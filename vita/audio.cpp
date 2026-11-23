#include "audio.hpp"

#include <algorithm>
#include <array>
#include <atomic>
#include <mutex>
#include <thread>

#include <psp2/audioout.h>

namespace {

constexpr unsigned output_rate = 48000;
constexpr size_t block_frames = 512;
constexpr size_t buffer_frames = 4096;

using Frame = std::array<int16_t, 2>;
std::array<Frame, buffer_frames> queued{};
size_t first = 0;
size_t count = 0;
uint32_t source_rate = output_rate;
uint32_t phase = 0;
std::mutex audio_mutex;
std::atomic<bool> running{false};
std::thread output_thread;
int port = -1;

void play() {
    std::array<Frame, block_frames> block{};
    while (running.load(std::memory_order_relaxed)) {
        {
            const std::lock_guard lock(audio_mutex);
            for (Frame& frame : block) {
                if (count < 2) {
                    frame = {};
                    continue;
                }
                const Frame& a = queued[first];
                const Frame& b = queued[(first + 1) % buffer_frames];
                for (size_t channel = 0; channel < frame.size(); ++channel) {
                    const int weighted = a[channel] * int(output_rate - phase) + b[channel] * int(phase);
                    frame[channel] = static_cast<int16_t>(weighted / int(output_rate));
                }
                phase += source_rate;
                const size_t consumed = std::min(count, size_t(phase / output_rate));
                phase %= output_rate;
                first = (first + consumed) % buffer_frames;
                count -= consumed;
            }
        }
        if (sceAudioOutOutput(port, block.data()) < 0) break;
    }
    running.store(false, std::memory_order_relaxed);
}

void queue_samples(int16_t* data, size_t sample_count) {
    if (!running.load(std::memory_order_relaxed)) return;
    const std::lock_guard lock(audio_mutex);
    const size_t available = std::min(sample_count / 2, buffer_frames - count);
    for (size_t i = 0; i < available; ++i) {
        // Guest audio is word-swapped, so the right sample comes first.
        queued[(first + count + i) % buffer_frames] = {data[i * 2 + 1], data[i * 2]};
    }
    count += available;
}

size_t get_frames_remaining() {
    if (!running.load(std::memory_order_relaxed)) return 0;
    const std::lock_guard lock(audio_mutex);
    return count;
}

void set_frequency(uint32_t frequency) {
    if (frequency == 0) return;
    const std::lock_guard lock(audio_mutex);
    source_rate = frequency;
    phase = 0;
}

}

ultramodern::audio_callbacks_t chopper::vita::initialize_audio() {
    port = sceAudioOutOpenPort(SCE_AUDIO_OUT_PORT_TYPE_MAIN, block_frames, output_rate,
                              SCE_AUDIO_OUT_MODE_STEREO);
    if (port >= 0) {
        running.store(true, std::memory_order_relaxed);
        output_thread = std::thread(play);
    }
    return {queue_samples, get_frames_remaining, set_frequency};
}

void chopper::vita::shutdown_audio() {
    running.store(false, std::memory_order_relaxed);
    if (output_thread.joinable()) output_thread.join();
    if (port >= 0) sceAudioOutReleasePort(port);
}
