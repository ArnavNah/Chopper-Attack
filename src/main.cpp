#include <cstdio>
#include <csignal>
#include <cstdint>
#include <vector>
#include <string>
#include <filesystem>
#include <algorithm>
#include <array>
#include <mutex>
#include <atomic>
#include <thread>
#include <chrono>

#define SDL_MAIN_HANDLED
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <commdlg.h>
#include <timeapi.h>
#include <DbgHelp.h>
#pragma comment(lib, "dbghelp.lib")
#include "SDL.h"
#include "SDL_syswm.h"

static LONG WINAPI CrashHandler(EXCEPTION_POINTERS* ep) {
    fprintf(stderr, "\n================ CRASH CAUGHT ================\n");
    fprintf(stderr, "Exception Code: 0x%08X at Address: %p\n", 
            ep->ExceptionRecord->ExceptionCode, 
            ep->ExceptionRecord->ExceptionAddress);

    HANDLE process = GetCurrentProcess();
    HANDLE thread = GetCurrentThread();
    SymInitialize(process, NULL, TRUE);

    CONTEXT context = *ep->ContextRecord;
    STACKFRAME64 stackFrame{};
    stackFrame.AddrPC.Offset = context.Rip;
    stackFrame.AddrPC.Mode = AddrModeFlat;
    stackFrame.AddrFrame.Offset = context.Rsp;
    stackFrame.AddrFrame.Mode = AddrModeFlat;
    stackFrame.AddrStack.Offset = context.Rsp;
    stackFrame.AddrStack.Mode = AddrModeFlat;

    fprintf(stderr, "Call stack:\n");
    for (int frame = 0; frame < 32; ++frame) {
        if (!StackWalk64(IMAGE_FILE_MACHINE_AMD64, process, thread, &stackFrame, &context,
                         NULL, SymFunctionTableAccess64, SymGetModuleBase64, NULL)) {
            break;
        }

        DWORD64 address = stackFrame.AddrPC.Offset;
        if (address == 0) break;

        char buffer[sizeof(SYMBOL_INFO) + MAX_SYM_NAME * sizeof(TCHAR)];
        PSYMBOL_INFO symbol = (PSYMBOL_INFO)buffer;
        symbol->SizeOfStruct = sizeof(SYMBOL_INFO);
        symbol->MaxNameLen = MAX_SYM_NAME;

        DWORD64 displacement = 0;
        if (SymFromAddr(process, address, &displacement, symbol)) {
            IMAGEHLP_LINE64 line{};
            line.SizeOfStruct = sizeof(IMAGEHLP_LINE64);
            DWORD lineDisplacement = 0;
            if (SymGetLineFromAddr64(process, address, &lineDisplacement, &line)) {
                fprintf(stderr, "  [%d] %s (%s:%d)\n", frame, symbol->Name, line.FileName, line.LineNumber);
            } else {
                fprintf(stderr, "  [%d] %s + 0x%llX\n", frame, symbol->Name, displacement);
            }
        } else {
            fprintf(stderr, "  [%d] 0x%llX\n", frame, address);
        }
    }
    fflush(stderr);
    return EXCEPTION_CONTINUE_SEARCH;
}
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_syswm.h>
#endif

#include "ultramodern/ultra64.h"
#include "ultramodern/ultramodern.hpp"
#include "ultramodern/config.hpp"
#include "ultramodern/renderer_context.hpp"
#include "librecomp/game.hpp"
#include "librecomp/helpers.hpp"
#include "librecomp/rsp.hpp"
#include "rt64_render_context.h"
#include "controls.h"

// Forward declaration of recompiled entrypoint
extern "C" void recomp_entrypoint(uint8_t* rdram, recomp_context* ctx);

// Low-level thread queue routines stubbed for modern host threading
extern "C" {
    void __osEnqueueThread_recomp(uint8_t* rdram, recomp_context* ctx) {}
    void __osDequeueThread_recomp(uint8_t* rdram, recomp_context* ctx) {}
    void __osPopThread_recomp(uint8_t* rdram, recomp_context* ctx) {}
    void __osDispatchThread_recomp(uint8_t* rdram, recomp_context* ctx) {}
    void osPfsIsPlug_recomp(uint8_t* rdram, recomp_context* ctx) {
        runtime_log("[osPfsIsPlug] thread=%d, pfs=0x%08X", ultramodern_get_thread_id(), (uint32_t)ctx->r4);
        ctx->r2 = 0; // return 0 (no Controller Pak plugged)
    }
}

// ============================================================================
// FUNCTION ENTRY TRACING (200-entry ring buffer per thread) & WATCHDOG
// ============================================================================

constexpr size_t TRACE_RING_BUFFER_SIZE = 200;

struct TraceEntry {
    const char* name;
    uint64_t timestamp_us;
};

struct ThreadTraceBuffer {
    TraceEntry entries[TRACE_RING_BUFFER_SIZE];
    std::atomic<uint64_t> total_entries{0};
    std::atomic<uint64_t> last_active_us{0};
};

static ThreadTraceBuffer g_thread_traces[32];

extern "C" void recomp_trace_func_entry_str(const char* name) {
    int tid = ultramodern_get_thread_id();
    if (tid != 3 && tid != 6 && tid != 7) return;

    ThreadTraceBuffer& buf = g_thread_traces[tid];
    uint64_t idx = buf.total_entries.fetch_add(1, std::memory_order_relaxed);
    buf.entries[idx % TRACE_RING_BUFFER_SIZE] = { name, 0 };
    buf.last_active_us.store(GetTickCount64() * 1000, std::memory_order_release);
}

static void dump_thread_trace(int tid, size_t count) {
    if (tid < 0 || tid >= 32) return;
    ThreadTraceBuffer& buf = g_thread_traces[tid];
    uint64_t total = buf.total_entries.load();
    printf("\n========================================================================================\n");
    printf("   FUNCTION ENTRY TRACE: THREAD %d (Total recorded: %llu, Showing last %zu)\n",
           tid, (unsigned long long)total, count);
    printf("========================================================================================\n");
    runtime_log("[Watchdog] Dumping Thread %d trace (total=%llu, last %zu entries)",
                tid, (unsigned long long)total, count);

    if (total == 0) {
        printf("  [Thread %d has not recorded any function entries]\n", tid);
        runtime_log("  Thread %d: NO ENTRIES RECORDED", tid);
        printf("========================================================================================\n\n");
        return;
    }

    size_t to_show = std::min((size_t)total, count);
    size_t start_idx = (total >= to_show) ? (total - to_show) : 0;

    for (size_t i = start_idx; i < total; ++i) {
        const auto& entry = buf.entries[i % TRACE_RING_BUFFER_SIZE];
        printf("  [%3zu] %s\n", i - start_idx + 1, entry.name ? entry.name : "unknown");
        runtime_log("  [Trace T%d #%llu] %s", tid, (unsigned long long)i, entry.name ? entry.name : "unknown");
    }
    printf("========================================================================================\n\n");
}

static std::thread g_watchdog_thread;
static std::atomic<bool> g_watchdog_stop{false};

static void watchdog_thread_func() {
    auto start_time = std::chrono::steady_clock::now();
    bool dumped_inactivity = false;
    bool dumped_10s = false;

    while (!g_watchdog_stop.load()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        auto now = std::chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(now - start_time).count();
        uint64_t now_us = GetTickCount64() * 1000;

        uint64_t t3_total = g_thread_traces[3].total_entries.load();
        uint64_t t7_total = g_thread_traces[7].total_entries.load();
        uint64_t t3_last = g_thread_traces[3].last_active_us.load();
        uint64_t t7_last = g_thread_traces[7].last_active_us.load();

        // Check if both threads 3 and 7 have had no activity for >= 2000 ms (and at least one has started)
        if (!dumped_inactivity && (t3_total > 0 || t7_total > 0)) {
            bool t3_inactive = (t3_total == 0) || (now_us - t3_last >= 2000000ULL);
            bool t7_inactive = (t7_total == 0) || (now_us - t7_last >= 2000000ULL);

            if (t3_inactive && t7_inactive) {
                dumped_inactivity = true;
                printf("\n>>> [WATCHDOG] Inactivity detected for Threads 3 and 7 (>= 2.0s without activity) at %lld ms <<<\n", (long long)elapsed_ms);
                runtime_log("[Watchdog] Inactivity detected for Threads 3 and 7 at %lld ms", (long long)elapsed_ms);
                dump_thread_trace(7, 50);
                dump_thread_trace(3, 50);
                dump_thread_trace(6, 50);
                ultramodern_dump_thread_states();
                fflush(stdout);
            }
        }

        // At 10 seconds:
        if (!dumped_10s && elapsed_ms >= 10000) {
            dumped_10s = true;
            printf("\n>>> [WATCHDOG] 10-Second Mark Reached (%lld ms) <<<\n", (long long)elapsed_ms);
            runtime_log("[Watchdog] 10-Second Mark Reached (%lld ms)", (long long)elapsed_ms);
            dump_thread_trace(7, 50);
            dump_thread_trace(3, 50);
            dump_thread_trace(6, 50);
            ultramodern_dump_thread_states();
            fflush(stdout);
        }
    }
}

// RSP audio microcode
RspExitReason aspMain(uint8_t* rdram, uint32_t ucode_addr);

static SDL_Window* g_window = nullptr;
static std::vector<SDL_GameController*> g_controllers;
static std::mutex g_controller_mutex;

// ============================================================================
// AUDIO SUBSYSTEM (SDL2 Audio Queue)
// ============================================================================

static SDL_AudioCVT audio_convert;
static SDL_AudioDeviceID audio_device = 0;
static uint32_t sample_rate = 32000;
static uint32_t output_sample_rate = 48000;
constexpr uint32_t input_channels = 2;
static uint32_t output_channels = 2;
constexpr uint32_t bytes_per_frame = input_channels * sizeof(float);

static void update_audio_converter() {
    int ret = SDL_BuildAudioCVT(&audio_convert, AUDIO_F32, input_channels, sample_rate, AUDIO_F32, output_channels, output_sample_rate);
    if (ret < 0) {
        fprintf(stderr, "[Audio] Error creating SDL audio converter: %s\n", SDL_GetError());
    }
}

static void set_frequency(uint32_t freq) {
    if (freq != 0) {
        sample_rate = freq;
        update_audio_converter();
    }
}

static void reset_audio(uint32_t output_freq) {
    if (audio_device != 0) {
        SDL_CloseAudioDevice(audio_device);
        audio_device = 0;
    }

    SDL_AudioSpec desired{
        .freq = (int)output_freq,
        .format = AUDIO_F32,
        .channels = (Uint8)output_channels,
        .silence = 0,
        .samples = 512,
        .padding = 0,
        .size = 0,
        .callback = nullptr,
        .userdata = nullptr
    };

    audio_device = SDL_OpenAudioDevice(nullptr, false, &desired, nullptr, 0);
    if (audio_device == 0) {
        fprintf(stderr, "[Audio] SDL error opening audio device: %s\n", SDL_GetError());
        return;
    }

    SDL_PauseAudioDevice(audio_device, 0);
    output_sample_rate = output_freq;
    update_audio_converter();
    printf("[Audio] Audio device opened at %u Hz\n", output_freq);
}

static void queue_samples(int16_t* audio_data, size_t sample_count) {
    if (audio_device == 0 || sample_count == 0) {
        return;
    }

    if (sample_count > 131072 || (sample_count & 1) || audio_convert.len_mult < 0 || audio_convert.len_mult > 64) {
        static unsigned invalid_count = 0;
        if (invalid_count++ < 5) fprintf(stderr, "[Audio] Rejected invalid sample count %zu (converter multiplier %d)\n", sample_count, audio_convert.len_mult);
        return;
    }
    // Keep the host queue bounded if the emulated scheduler runs faster than audio playback.
    if (SDL_GetQueuedAudioSize(audio_device) > output_sample_rate * bytes_per_frame / 10) return;
    static std::vector<float> swap_buffer;
    size_t needed_size = std::max(sample_count, sample_count * (audio_convert.len_mult ? audio_convert.len_mult : 1));
    if (needed_size > swap_buffer.size()) {
        swap_buffer.resize(needed_size * 2);
    }

    // Convert 16-bit PCM to float and swap L/R channels for N64 endianness
    for (size_t i = 0; i < sample_count; i += 2) {
        swap_buffer[i + 0] = audio_data[i + 1] * (1.0f / 32768.0f);
        swap_buffer[i + 1] = audio_data[i + 0] * (1.0f / 32768.0f);
    }

    audio_convert.buf = reinterpret_cast<Uint8*>(swap_buffer.data());
    audio_convert.len = (int)(sample_count * sizeof(float));

    if (SDL_ConvertAudio(&audio_convert) == 0) {
        SDL_QueueAudio(audio_device, audio_convert.buf, audio_convert.len_cvt);
    }
}

static size_t get_frames_remaining() {
    if (audio_device == 0) {
        return 0;
    }
    uint32_t queued_bytes = SDL_GetQueuedAudioSize(audio_device);
    // SDL counts frames at the output rate; the emulated AI expects input-rate frames.
    return (uint64_t(queued_bytes / bytes_per_frame) * sample_rate) / output_sample_rate;
}

// ============================================================================
// GRAPHICS & WINDOW SUBSYSTEM
// ============================================================================

static ultramodern::gfx_callbacks_t::gfx_data_t create_gfx() {
    return {};
}

static ultramodern::renderer::WindowHandle create_window(ultramodern::gfx_callbacks_t::gfx_data_t) {
    uint32_t flags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN;

    g_window = SDL_CreateWindow(
        "Chopper Attack (Recompiled)",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1280, 720,
        flags
    );

    if (g_window == nullptr) {
        fprintf(stderr, "[SDL] Failed to create window: %s\n", SDL_GetError());
        return {};
    }

    SDL_ShowWindow(g_window);
    SDL_RaiseWindow(g_window);

    SDL_SysWMinfo wmInfo;
    SDL_VERSION(&wmInfo.version);
    SDL_GetWindowWMInfo(g_window, &wmInfo);

#if defined(_WIN32)
    printf("[Window] Created window %p at HWND %p\n", (void*)g_window, wmInfo.info.win.window);
    return ultramodern::renderer::WindowHandle{ wmInfo.info.win.window, GetCurrentThreadId() };
#elif defined(__linux__) || defined(__ANDROID__)
    return ultramodern::renderer::WindowHandle{ g_window };
#endif
}

static void update_gfx(void*) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                ultramodern::quit();
                break;

            case SDL_KEYDOWN:
#ifdef _WIN32
                if (event.key.keysym.scancode == SDL_SCANCODE_F2 && !event.key.repeat) {
                    const bool original = chopper::controls::toggle_original_flight();
                    SDL_SetWindowTitle(g_window, original ? "Chopper Attack (Recompiled) - Original N64 flight"
                                                         : "Chopper Attack (Recompiled) - Twin-stick flight");
                    break;
                }
                if (event.key.keysym.scancode == SDL_SCANCODE_F1 && !event.key.repeat) {
                    chopper::controls::edit(g_window);
                    break;
                }
#endif
                if ((event.key.keysym.scancode == SDL_SCANCODE_RETURN && (event.key.keysym.mod & KMOD_ALT)) ||
                    event.key.keysym.scancode == SDL_SCANCODE_F11) {
                    uint32_t current_flags = SDL_GetWindowFlags(g_window);
                    bool is_fullscreen = (current_flags & SDL_WINDOW_FULLSCREEN_DESKTOP) != 0;
                    SDL_SetWindowFullscreen(g_window, is_fullscreen ? 0 : SDL_WINDOW_FULLSCREEN_DESKTOP);
                }
                break;

            case SDL_CONTROLLERDEVICEADDED: {
                std::lock_guard<std::mutex> lock(g_controller_mutex);
                SDL_GameController* controller = SDL_GameControllerOpen(event.cdevice.which);
                if (controller != nullptr) {
                    printf("[Input] Game Controller Connected: %s\n", SDL_GameControllerName(controller));
                    g_controllers.push_back(controller);
                }
                break;
            }

            case SDL_CONTROLLERDEVICEREMOVED: {
                std::lock_guard<std::mutex> lock(g_controller_mutex);
                SDL_JoystickID jid = event.cdevice.which;
                for (auto it = g_controllers.begin(); it != g_controllers.end(); ) {
                    if (SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(*it)) == jid) {
                        SDL_GameControllerClose(*it);
                        it = g_controllers.erase(it);
                        printf("[Input] Game Controller Removed (ID %d)\n", jid);
                    } else {
                        ++it;
                    }
                }
                break;
            }

            default:
                break;
        }
    }
    std::lock_guard<std::mutex> lock(g_controller_mutex);
    chopper::controls::poll(g_controllers.empty() ? nullptr : g_controllers.front());
}

// ============================================================================
// INPUT SUBSYSTEM (N64 Controller Mapping)
// ============================================================================

static bool g_auto_start = false;

static void poll_input() {
    // SDL events are polled in update_gfx() on the main loop.
}

static bool get_input(int controller_num, uint16_t* buttons, float* x, float* y) {
    if (controller_num != 0) {
        return false;
    }

    auto input = chopper::controls::read();
    static const uint64_t input_start_time = GetTickCount64();
    const uint64_t elapsed_ms = GetTickCount64() - input_start_time;
    if (g_auto_start && elapsed_ms > 4000 && elapsed_ms % 2000 < 300) {
        input.buttons |= 0x1000;
    }

    *buttons = input.buttons;
    *x = input.x;
    *y = input.y;
    return true;
}

static void set_rumble(int controller_num, bool rumble) {
    std::lock_guard<std::mutex> lock(g_controller_mutex);
    if (controller_num == 0 && !g_controllers.empty() && g_controllers[0] != nullptr) {
        uint16_t freq = rumble ? 0xFFFF : 0x0000;
        SDL_GameControllerRumble(g_controllers[0], freq, freq, 100);
    }
}

static ultramodern::input::connected_device_info_t get_connected_device_info(int controller_num) {
    if (controller_num == 0) {
        return {
            .connected_device = ultramodern::input::Device::Controller,
            .connected_pak = ultramodern::input::Pak::RumblePak,
        };
    }
    return {
        .connected_device = ultramodern::input::Device::None,
        .connected_pak = ultramodern::input::Pak::None,
    };
}

// ============================================================================
// RSP AUDIO MICROCODE CALLBACK
// ============================================================================

static RspUcodeFunc* get_rsp_microcode(const OSTask* task) {
    if (task->t.type == M_AUDTASK) {
        return aspMain;
    }
    fprintf(stderr, "[RSP] Unknown task type: %u\n", task->t.type);
    return nullptr;
}

// ============================================================================
// ERROR HANDLING
// ============================================================================

static void show_message_box(const char* msg) {
    fprintf(stderr, "[ERROR] %s\n", msg);
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Chopper Attack", msg, nullptr);
}

// Forward declaration of overlays registration
namespace chopper {
    void register_overlays();
}

// ============================================================================
// MAIN ENTRY POINT
// ============================================================================

int main(int argc, char** argv) {

    setvbuf(stdout, nullptr, _IONBF, 0);
    setvbuf(stderr, nullptr, _IONBF, 0);

#ifdef _WIN32
    SetUnhandledExceptionFilter(CrashHandler);
    std::signal(SIGABRT, [](int) {
        CONTEXT ctx{}; RtlCaptureContext(&ctx);
        EXCEPTION_RECORD record{}; record.ExceptionCode = 0xE0000001;
        EXCEPTION_POINTERS info{ &record, &ctx }; CrashHandler(&info);
    });
    timeBeginPeriod(1);
    SetConsoleOutputCP(CP_UTF8);
    SDL_setenv("SDL_AUDIODRIVER", "wasapi", 1);
#endif

    SDL_SetHint(SDL_HINT_WINDOWS_DPI_AWARENESS, "permonitorv2");
    SDL_SetHint(SDL_HINT_GAMECONTROLLER_USE_BUTTON_LABELS, "0");
    SDL_SetHint(SDL_HINT_JOYSTICK_HIDAPI_PS4_RUMBLE, "1");
    SDL_SetHint(SDL_HINT_JOYSTICK_HIDAPI_PS5_RUMBLE, "1");
    SDL_SetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS, "1");

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER | SDL_INIT_AUDIO) != 0) {
        fprintf(stderr, "[SDL] Failed to initialize SDL2: %s\n", SDL_GetError());
    } else {
        printf("[SDL] Initialized successfully. Video Driver: %s\n", SDL_GetCurrentVideoDriver());
    }

    printf("====================================================\n");
    printf("   CHOPPER ATTACK - NATIVE PC RECOMPILATION        \n");
    printf("====================================================\n");

    std::filesystem::path current_dir = std::filesystem::current_path();
    recomp::register_config_path(current_dir);
    chopper::controls::load();

    // Register Chopper Attack game entry
    recomp::GameEntry chopper_game = {
        .rom_hash = 0x567f7275cea88092ULL,
        .internal_name = "CHOPPER_ATTACK",
        .display_name = "Chopper Attack",
        .game_id = u8"chopper_attack",
        .mod_game_id = "chopper_attack",
        .save_type = recomp::SaveType::AllowAll,
        .is_enabled = true,
        .has_compressed_code = false,
        .entrypoint_address = (gpr)(int32_t)0x80000400u,
        .entrypoint = recomp_entrypoint,
    };

    recomp::register_game(chopper_game);

    // Find and validate the ROM
    std::filesystem::path exe_dir;
#ifdef _WIN32
    wchar_t exe_path_buf[MAX_PATH] = { 0 };
    if (GetModuleFileNameW(nullptr, exe_path_buf, MAX_PATH)) {
        exe_dir = std::filesystem::path(exe_path_buf).parent_path();
    }
#endif
    if (exe_dir.empty()) {
        exe_dir = current_dir;
    }

    std::vector<std::filesystem::path> search_paths = {
        "rom/chopper_attack.z64",
        "Chopper Attack (USA).z64",
        "chopper_attack.z64",
        exe_dir / "rom" / "chopper_attack.z64",
        exe_dir / "chopper_attack.z64",
        exe_dir / "Chopper Attack (USA).z64",
        current_dir / "rom" / "chopper_attack.z64",
        current_dir / "Chopper Attack (USA).z64"
    };

    if (argc > 1) {
        search_paths.insert(search_paths.begin(), argv[1]);
    }

    std::filesystem::path resolved_rom;
    for (const auto& path : search_paths) {
        if (std::filesystem::exists(path)) {
            resolved_rom = path;
            break;
        }
    }

#ifdef _WIN32
    if (resolved_rom.empty()) {
        wchar_t file_buf[MAX_PATH] = { 0 };
        OPENFILENAMEW ofn = { 0 };
        ofn.lStructSize = sizeof(ofn);
        ofn.lpstrFilter = L"N64 ROM Files (*.z64;*.n64;*.v64)\0*.z64;*.n64;*.v64\0All Files (*.*)\0*.*\0";
        ofn.lpstrFile = file_buf;
        ofn.nMaxFile = MAX_PATH;
        ofn.lpstrTitle = L"Select Chopper Attack ROM (.z64, .n64, .v64)";
        ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
        if (GetOpenFileNameW(&ofn)) {
            resolved_rom = file_buf;
        }
    }
#endif

    if (resolved_rom.empty()) {
        show_message_box("Could not find Chopper Attack ROM!\nPlease place 'chopper_attack.z64' in the ./rom/ directory or select it when prompted.");
        return EXIT_FAILURE;
    }

    printf("[ROM] Loading ROM from: %ls\n", resolved_rom.c_str());
    recomp::RomValidationError err = recomp::select_rom(resolved_rom, chopper_game.game_id);
    if (err != recomp::RomValidationError::Good) {
        char err_msg[256];
        snprintf(err_msg, sizeof(err_msg), "Invalid ROM file! Error code: %d", (int)err);
        show_message_box(err_msg);
        return EXIT_FAILURE;
    }

    printf("[ROM] ROM verified successfully! Starting game...\n");

    // Initialize SDL audio
    reset_audio(48000);

    bool test_pattern = false;
    bool use_vulkan = false;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--test-pattern") == 0) test_pattern = true;
        if (strcmp(argv[i], "--vulkan") == 0) use_vulkan = true;
        if (strcmp(argv[i], "--d3d12") == 0) use_vulkan = false;
        if (strcmp(argv[i], "--auto-start") == 0) g_auto_start = true;
    }

    // Set initial graphics configuration
    ultramodern::renderer::GraphicsConfig gfx_cfg{};
    gfx_cfg.developer_mode = false;
    gfx_cfg.res_option = ultramodern::renderer::Resolution::Auto;
    gfx_cfg.wm_option = ultramodern::renderer::WindowMode::Windowed;
    gfx_cfg.hr_option = ultramodern::renderer::HUDRatioMode::Original;
    gfx_cfg.api_option = use_vulkan ? ultramodern::renderer::GraphicsApi::Vulkan : ultramodern::renderer::GraphicsApi::D3D12;
    gfx_cfg.ar_option = ultramodern::renderer::AspectRatio::Original; // 4:3 authentic N64
    gfx_cfg.msaa_option = ultramodern::renderer::Antialiasing::None;
    gfx_cfg.rr_option = ultramodern::renderer::RefreshRate::Display;
    gfx_cfg.hpfb_option = ultramodern::renderer::HighPrecisionFramebuffer::Auto;
    gfx_cfg.rr_manual_value = 60;
    gfx_cfg.ds_option = 1;
    ultramodern::renderer::set_graphics_config(gfx_cfg);
    printf("[Graphics] Selected Graphics API: %s\n", use_vulkan ? "Vulkan" : "D3D12");

    if (test_pattern) {
        printf("[Test] Running standalone renderer test pattern (%s)...\n", use_vulkan ? "Vulkan" : "D3D12");
        auto win_handle = create_window({});
        std::vector<uint8_t> dummy_rdram(8 * 1024 * 1024, 0);
        uint32_t fb_origin = 0x003B5000;
        uint16_t colors[8] = {
            0xFFFF, // White
            0xFFE1, // Yellow
            0x07FF, // Cyan
            0x07E1, // Green
            0xF81F, // Magenta
            0xF801, // Red
            0x003F, // Blue
            0x0001  // Black
        };
        for (int y = 0; y < 240; y++) {
            for (int x = 0; x < 320; x++) {
                int bar = x / 40;
                uint16_t col = colors[bar];
                uint32_t addr = fb_origin + (y * 320 + x) * 2;
                *(uint16_t*)&dummy_rdram[addr ^ 2] = col;
            }
        }
        auto vi_regs = ultramodern::renderer::get_vi_regs();
        vi_regs->VI_STATUS_REG = 0x00013006;
        vi_regs->VI_ORIGIN_REG = fb_origin;
        vi_regs->VI_WIDTH_REG = 320;
        vi_regs->VI_H_START_REG = (108 << 16) | (108 + 320);
        vi_regs->VI_V_START_REG = (35 << 16) | (35 + 240);
        vi_regs->VI_X_SCALE_REG = 0x0200;
        vi_regs->VI_Y_SCALE_REG = 0x0400;

        auto render_ctx = chopper::renderer::create_render_context(dummy_rdram.data(), win_handle, false);
        if (!render_ctx || !render_ctx->valid()) {
            fprintf(stderr, "[Test] Failed to create render context!\n");
            return 1;
        }

        for (int f = 0; f < 60; f++) {
            SDL_Event ev;
            while (SDL_PollEvent(&ev)) {
                if (ev.type == SDL_QUIT) break;
            }
            render_ctx->update_screen();
            SDL_Delay(16);
        }
        printf("[Test] Test pattern presentation completed successfully (%s)!\n", use_vulkan ? "Vulkan" : "D3D12");
        render_ctx->shutdown();
        render_ctx.reset();
        SDL_DestroyWindow(g_window);
        SDL_Quit();
        return 0;
    }

    // Callbacks setup
    recomp::rsp::callbacks_t rsp_callbacks{
        .get_rsp_microcode = get_rsp_microcode,
    };

    ultramodern::renderer::callbacks_t renderer_callbacks{
        .create_render_context = chopper::renderer::create_render_context,
    };

    ultramodern::gfx_callbacks_t gfx_callbacks{
        .create_gfx = create_gfx,
        .create_window = create_window,
        .update_gfx = update_gfx,
    };

    ultramodern::audio_callbacks_t audio_callbacks{
        .queue_samples = queue_samples,
        .get_frames_remaining = get_frames_remaining,
        .set_frequency = set_frequency,
    };

    ultramodern::input::callbacks_t input_callbacks{
        .poll_input = poll_input,
        .get_input = get_input,
        .set_rumble = set_rumble,
        .get_connected_device_info = get_connected_device_info,
    };

    ultramodern::events::callbacks_t events_callbacks{
        .vi_callback = nullptr,
        .gfx_init_callback = nullptr,
    };

    ultramodern::error_handling::callbacks_t error_handling_callbacks{
        .message_box = show_message_box,
    };

    ultramodern::threads::callbacks_t threads_callbacks{
        .get_game_thread_name = nullptr,
    };

    recomp::Configuration recomp_config{
        .argc = argc,
        .argv = argv,
        .project_version = recomp::Version(1, 0, 0),
        .window_handle = {},
        .rsp_callbacks = rsp_callbacks,
        .renderer_callbacks = renderer_callbacks,
        .audio_callbacks = audio_callbacks,
        .input_callbacks = input_callbacks,
        .gfx_callbacks = gfx_callbacks,
        .events_callbacks = events_callbacks,
        .error_handling_callbacks = error_handling_callbacks,
        .threads_callbacks = threads_callbacks,
        .message_queue_control = {}
    };

    // Register overlays table
    chopper::register_overlays();

    // Start watchdog thread for inactivity and state monitoring
    if (std::getenv("CHOPPER_DEBUG")) {
        g_watchdog_thread = std::thread(watchdog_thread_func);
    }

    // Auto-launch Chopper Attack
    recomp::start_game(chopper_game.game_id, "");

    // Start runtime
    recomp::start(recomp_config);

    g_watchdog_stop.store(true);
    if (g_watchdog_thread.joinable()) {
        g_watchdog_thread.detach();
    }

#ifdef _WIN32
    timeEndPeriod(1);
#endif

    return EXIT_SUCCESS;
}
