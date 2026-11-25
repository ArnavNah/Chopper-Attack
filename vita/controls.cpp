#include "controls.hpp"

#include <algorithm>
#include <atomic>
#include <cmath>
#include <cstdint>
#include <psp2/ctrl.h>
#include <psp2/kernel/clib.h>

#include "chopper_recomp_hooks.h"

namespace {

constexpr uint16_t c_right = 0x0001;
constexpr uint16_t c_left = 0x0002;
constexpr uint16_t c_down = 0x0004;
constexpr uint16_t c_up = 0x0008;
constexpr uint16_t d_right = 0x0100;
constexpr uint16_t d_left = 0x0200;
constexpr uint16_t d_down = 0x0400;
constexpr uint16_t d_up = 0x0800;

struct Pad {
    uint8_t lx = 128;
    uint8_t ly = 128;
    uint8_t rx = 128;
    uint8_t ry = 128;
};

std::atomic<uint32_t> sticks{0x80808080};
std::atomic<bool> original_flight{false};

float axis(uint8_t value) {
    constexpr float deadzone = 0.2f;
    const float normalized = std::clamp((static_cast<int>(value) - 128) / 127.0f, -1.0f, 1.0f);
    const float magnitude = std::max(0.0f, (std::abs(normalized) - deadzone) / (1.0f - deadzone));
    return std::copysign(magnitude, normalized);
}

bool get_input(int controller, uint16_t* buttons, float* x, float* y) {
    if (controller != 0) return false;

    SceCtrlData data{};
    const bool sampled = sceCtrlPeekBufferPositive(0, &data, 1) > 0;
    const Pad pad = sampled ? Pad{data.lx, data.ly, data.rx, data.ry} : Pad{};
    sticks.store(uint32_t{pad.lx} | (uint32_t{pad.ly} << 8) |
                 (uint32_t{pad.rx} << 16) | (uint32_t{pad.ry} << 24),
                 std::memory_order_relaxed);
    if (!sampled) data.buttons = 0;

    constexpr uint32_t layout_chord = SCE_CTRL_SELECT | SCE_CTRL_TRIANGLE;
    static bool chord_held = false;
    const bool toggle_pressed = (data.buttons & layout_chord) == layout_chord;
    if (toggle_pressed && !chord_held) {
        const bool original = !original_flight.load();
        original_flight.store(original);
        sceClibPrintf("[Chopper Attack] Flight layout: %s\n", original ? "Original N64" : "Twin-stick");
    }
    chord_held = toggle_pressed;
    if (toggle_pressed) data.buttons &= ~layout_chord;

    *buttons = 0;
    const auto map = [&](uint32_t vita_button, uint16_t n64_button) {
        if (data.buttons & vita_button) *buttons |= n64_button;
    };
    map(SCE_CTRL_CROSS, 0x8000);
    map(SCE_CTRL_CIRCLE, 0x4000);
    map(SCE_CTRL_LTRIGGER, 0x2000); // Cannon (Z).
    map(SCE_CTRL_START, 0x1000);
    map(SCE_CTRL_RTRIGGER, 0x0010); // Equipped weapon (R).
    map(SCE_CTRL_UP, d_up);
    map(SCE_CTRL_DOWN, d_down);
    map(SCE_CTRL_LEFT, d_left);
    map(SCE_CTRL_RIGHT, d_right);

    // Keep the stock C-buttons available in menus. Horizontal C inputs are
    // masked at the camera hook because the same stick turns the helicopter.
    const float rx = axis(pad.rx);
    const float ry = -axis(pad.ry);
    if (rx < -0.5f) *buttons |= c_left;
    if (rx > 0.5f) *buttons |= c_right;
    if (ry < -0.5f) *buttons |= c_down;
    if (ry > 0.5f) *buttons |= c_up;
    map(SCE_CTRL_TRIANGLE, c_up);

    *x = axis(pad.lx);
    *y = -axis(pad.ly);
    return true;
}

ultramodern::input::connected_device_info_t get_connected_device_info(int controller) {
    using namespace ultramodern::input;
    return {controller == 0 ? Device::Controller : Device::None, Pak::None};
}

}

ultramodern::input::callbacks_t chopper::vita::initialize_controls() {
    sceCtrlSetSamplingMode(SCE_CTRL_MODE_ANALOG_WIDE);
    return {
        .poll_input = [] {},
        .get_input = get_input,
        .set_rumble = [](int, bool) {},
        .get_connected_device_info = get_connected_device_info,
    };
}

extern "C" uint16_t chopper_flight_camera_mask() {
    return original_flight.load() ? 0 : c_left | c_right;
}

extern "C" void chopper_apply_flight_controls(uint8_t* rdram, recomp_context* ctx) {
    if (original_flight.load()) return;
    const uint32_t pad = sticks.load(std::memory_order_relaxed);
    const float thrust = -axis(static_cast<uint8_t>(pad >> 8));
    const float turn = axis(static_cast<uint8_t>(pad >> 16));

    uint16_t buttons = MEM_HU(0xE2, ctx->r29) & ~(d_up | d_down | d_left | d_right);
    if (thrust > 0.0f) buttons |= d_up;
    if (thrust < 0.0f) buttons |= d_down;
    MEM_H(0xE2, ctx->r29) = buttons;

    const fpr yaw{.fl = turn * 10.0f};
    const fpr pitch{.fl = thrust * 4.0f};
    MEM_W(0xE8, ctx->r29) = yaw.u32l;
    MEM_W(0xEC, ctx->r29) = pitch.u32l;
}
