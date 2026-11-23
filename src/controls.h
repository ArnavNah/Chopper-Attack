#pragma once

#include <cstdint>

struct SDL_Window;
struct _SDL_GameController;

namespace chopper::controls {
struct Input {
    uint16_t buttons = 0;
    float x = 0;
    float y = 0;
    uint16_t keyboard_flight = 0;
    float keyboard_yaw = 0;
    float keyboard_pitch = 0;
    float pad_thrust = 0;
    float pad_yaw = 0;
    bool pad_connected = false;
};

void load();
void poll(_SDL_GameController* pad);
Input read();
#ifdef _WIN32
void edit(SDL_Window* owner);
#endif
}
