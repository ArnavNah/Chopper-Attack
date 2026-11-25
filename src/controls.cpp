#include "controls.h"
#include "chopper_recomp_hooks.h"

#define SDL_MAIN_HANDLED
#include <SDL.h>

#include <algorithm>
#include <array>
#include <atomic>
#include <filesystem>
#include <fstream>
#include <mutex>
#include <sstream>
#include <string>

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <SDL_syswm.h>
#include "controls_resource.h"
#endif

namespace chopper::controls {
namespace {
constexpr int unbound = -1;
constexpr int first_axis = SDL_CONTROLLER_BUTTON_MAX;
constexpr int axis_binding(SDL_GameControllerAxis axis, bool positive) {
    return first_axis + axis * 2 + positive;
}

struct Bindings {
    int key;
    int alternate_key;
    int pad;
    int alternate_pad;
};

enum class FlightAxis { none, forward, reverse, left, right };

struct Action {
    const char* id;
    const wchar_t* label;
    uint16_t button;
    Bindings defaults;
    int legacy_key = unbound;
    int legacy_alternate_key = unbound;
    FlightAxis flight = FlightAxis::none;
};

// The first four rows map the original N64 stick, used to aim in flight.
constexpr Action actions[] = {
    {"stick_up",    L"Tilt Down / Menu Up",     0, {SDL_SCANCODE_UP, unbound, axis_binding(SDL_CONTROLLER_AXIS_LEFTY, false), unbound}, SDL_SCANCODE_W, SDL_SCANCODE_UP},
    {"stick_down",  L"Tilt Up / Menu Down",     0, {SDL_SCANCODE_DOWN, unbound, axis_binding(SDL_CONTROLLER_AXIS_LEFTY, true), unbound}, SDL_SCANCODE_S, SDL_SCANCODE_DOWN},
    {"stick_left",  L"Turn Left / Menu Left",  0, {SDL_SCANCODE_LEFT, unbound, axis_binding(SDL_CONTROLLER_AXIS_LEFTX, false), unbound}, SDL_SCANCODE_A, SDL_SCANCODE_LEFT},
    {"stick_right", L"Turn Right / Menu Right",0, {SDL_SCANCODE_RIGHT, unbound, axis_binding(SDL_CONTROLLER_AXIS_LEFTX, true), unbound}, SDL_SCANCODE_D, SDL_SCANCODE_RIGHT},
    {"a",      L"Confirm / Previous Weapon (A)", 0x8000, {SDL_SCANCODE_SPACE, SDL_SCANCODE_J, SDL_CONTROLLER_BUTTON_A, unbound}},
    {"b",      L"Back / Next Weapon (B)", 0x4000, {SDL_SCANCODE_K, SDL_SCANCODE_X, SDL_CONTROLLER_BUTTON_B, SDL_CONTROLLER_BUTTON_X}},
    {"z",      L"Fire Cannon (Z)", 0x2000, {SDL_SCANCODE_LSHIFT, SDL_SCANCODE_Z, axis_binding(SDL_CONTROLLER_AXIS_TRIGGERLEFT, true), SDL_CONTROLLER_BUTTON_LEFTSHOULDER}},
    {"start",  L"Start / Pause",0x1000, {SDL_SCANCODE_RETURN, unbound, SDL_CONTROLLER_BUTTON_START, unbound}},
    {"l",      L"L Button",    0x0020, {SDL_SCANCODE_Q, unbound, unbound, unbound}},
    {"r",      L"Launch Selected Weapon (R)", 0x0010, {SDL_SCANCODE_E, SDL_SCANCODE_RSHIFT, axis_binding(SDL_CONTROLLER_AXIS_TRIGGERRIGHT, true), SDL_CONTROLLER_BUTTON_RIGHTSHOULDER}},
    {"d_up",   L"D-pad Up",    0x0800, {unbound, unbound, SDL_CONTROLLER_BUTTON_DPAD_UP, unbound}},
    {"d_down", L"D-pad Down",  0x0400, {unbound, unbound, SDL_CONTROLLER_BUTTON_DPAD_DOWN, unbound}},
    {"d_left", L"D-pad Left",  0x0200, {unbound, unbound, SDL_CONTROLLER_BUTTON_DPAD_LEFT, unbound}},
    {"d_right",L"D-pad Right", 0x0100, {unbound, unbound, SDL_CONTROLLER_BUTTON_DPAD_RIGHT, unbound}},
    {"c_up",   L"Fly Forward (C-Up)", 0x0008, {SDL_SCANCODE_W, SDL_SCANCODE_KP_8, axis_binding(SDL_CONTROLLER_AXIS_RIGHTY, false), SDL_CONTROLLER_BUTTON_Y}, SDL_SCANCODE_I, SDL_SCANCODE_KP_8},
    {"c_down", L"Reverse (C-Down)",   0x0004, {SDL_SCANCODE_S, SDL_SCANCODE_KP_2, axis_binding(SDL_CONTROLLER_AXIS_RIGHTY, true), unbound}, SDL_SCANCODE_M, SDL_SCANCODE_KP_2},
    {"c_left", L"Turn Left and Advance",  0x0002, {SDL_SCANCODE_A, SDL_SCANCODE_KP_4, axis_binding(SDL_CONTROLLER_AXIS_RIGHTX, false), unbound}, SDL_SCANCODE_U, SDL_SCANCODE_KP_4},
    {"c_right",L"Turn Right and Advance", 0x0001, {SDL_SCANCODE_D, SDL_SCANCODE_KP_6, axis_binding(SDL_CONTROLLER_AXIS_RIGHTX, true), unbound}, SDL_SCANCODE_O, SDL_SCANCODE_KP_6},
    {"flight_forward", L"Gamepad Fly Forward", 0, {unbound, unbound, axis_binding(SDL_CONTROLLER_AXIS_LEFTY, false), unbound}, unbound, unbound, FlightAxis::forward},
    {"flight_reverse", L"Gamepad Fly Backward", 0, {unbound, unbound, axis_binding(SDL_CONTROLLER_AXIS_LEFTY, true), unbound}, unbound, unbound, FlightAxis::reverse},
    {"flight_left", L"Gamepad Turn Left", 0, {unbound, unbound, axis_binding(SDL_CONTROLLER_AXIS_RIGHTX, false), unbound}, unbound, unbound, FlightAxis::left},
    {"flight_right", L"Gamepad Turn Right", 0, {unbound, unbound, axis_binding(SDL_CONTROLLER_AXIS_RIGHTX, true), unbound}, unbound, unbound, FlightAxis::right},
};
constexpr char settings_header[] = "# Chopper Attack controls v2";
using Mapping = std::array<Bindings, std::size(actions)>;

constexpr Mapping defaults() {
    Mapping result{};
    for (size_t i = 0; i < result.size(); ++i) result[i] = actions[i].defaults;
    return result;
}

Mapping mapping = defaults();
std::filesystem::path settings_path;
std::mutex input_mutex;
Input latest_input;
std::atomic<bool> original_flight{false};

void publish(Input input) {
    std::lock_guard lock(input_mutex);
    latest_input = input;
}

bool valid_key(int key) {
    if (key == unbound) return true;
    if (key <= SDL_SCANCODE_UNKNOWN || key >= SDL_NUM_SCANCODES ||
        key == SDL_SCANCODE_F1 || key == SDL_SCANCODE_F2 || key == SDL_SCANCODE_F11) return false;
    return *SDL_GetScancodeName(static_cast<SDL_Scancode>(key)) != '\0';
}

bool valid_pad(int code) {
    if (code == unbound) return true;
    if (code < 0 || code >= first_axis + SDL_CONTROLLER_AXIS_MAX * 2) return false;
    // Both SDL trigger axes report positive values only.
    return code < axis_binding(SDL_CONTROLLER_AXIS_TRIGGERLEFT, false) || (code - first_axis) % 2 == 1;
}

float pad_strength(SDL_GameController* pad, int code, bool analog) {
    if (!pad || code == unbound) return 0;
    if (code < first_axis) {
        return SDL_GameControllerGetButton(pad, static_cast<SDL_GameControllerButton>(code)) ? 1.0f : 0.0f;
    }
    const auto axis = static_cast<SDL_GameControllerAxis>((code - first_axis) / 2);
    const bool positive = (code - first_axis) % 2 == 1;
    const int signed_value = SDL_GameControllerGetAxis(pad, axis) * (positive ? 1 : -1);
    if (!analog) return signed_value > (axis >= SDL_CONTROLLER_AXIS_TRIGGERLEFT ? 8000 : 16000) ? 1.0f : 0.0f;
    return signed_value > 4915 ? std::min(signed_value / 32767.0f, 1.0f) : 0.0f;
}

#ifdef _WIN32
bool save(const Mapping& edited) {
    if (settings_path.empty()) return false;
    auto temp = settings_path;
    temp += L"." + std::to_wstring(GetCurrentProcessId()) + L".tmp";
    std::ofstream output(temp, std::ios::trunc);
    if (!output) return false;
    output << settings_header << '\n';
    for (size_t i = 0; i < edited.size(); ++i) {
        const auto& value = edited[i];
        output << actions[i].id << ' ' << value.key << ' ' << value.alternate_key << ' '
               << value.pad << ' ' << value.alternate_pad << '\n';
    }
    output.close();
    if (output && MoveFileExW(temp.c_str(), settings_path.c_str(), MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH)) {
        return true;
    }
    DeleteFileW(temp.c_str());
    return false;
}

constexpr int binding_controls[] = {IDC_KEY_1, IDC_KEY_2, IDC_PAD_1, IDC_PAD_2};
struct Editor {
    Mapping draft;
    size_t action = 0;
};

void add_choice(HWND combo, const wchar_t* label, int value) {
    const LRESULT row = SendMessageW(combo, CB_ADDSTRING, 0, reinterpret_cast<LPARAM>(label));
    if (row >= 0) SendMessageW(combo, CB_SETITEMDATA, row, value);
}

void add_sdl_choice(HWND combo, const char* label, int value) {
    wchar_t wide[128];
    if (MultiByteToWideChar(CP_UTF8, 0, label, -1, wide, static_cast<int>(std::size(wide))) > 0) {
        add_choice(combo, wide, value);
    }
}

void select_binding(HWND combo, int value) {
    const LRESULT count = SendMessageW(combo, CB_GETCOUNT, 0, 0);
    for (LRESULT index = 0; index < count; ++index) {
        if (SendMessageW(combo, CB_GETITEMDATA, index, 0) == value) {
            SendMessageW(combo, CB_SETCURSEL, index, 0);
            return;
        }
    }
    SendMessageW(combo, CB_SETCURSEL, 0, 0);
}

int read_binding(HWND dialog, int id) {
    HWND combo = GetDlgItem(dialog, id);
    const LRESULT row = SendMessageW(combo, CB_GETCURSEL, 0, 0);
    return row < 0 ? unbound : static_cast<int>(SendMessageW(combo, CB_GETITEMDATA, row, 0));
}

void sync_controls(HWND dialog, const Editor& editor) {
    const auto& [key, alt_key, pad, alt_pad] = editor.draft[editor.action];
    const int values[] = {key, alt_key, pad, alt_pad};
    for (size_t i = 0; i < std::size(values); ++i) {
        select_binding(GetDlgItem(dialog, binding_controls[i]), values[i]);
    }
    const bool keyboard_enabled = actions[editor.action].flight == FlightAxis::none;
    EnableWindow(GetDlgItem(dialog, IDC_KEY_1), keyboard_enabled);
    EnableWindow(GetDlgItem(dialog, IDC_KEY_2), keyboard_enabled);
}

void store_controls(HWND dialog, Editor& editor) {
    editor.draft[editor.action] = {read_binding(dialog, IDC_KEY_1), read_binding(dialog, IDC_KEY_2),
                                   read_binding(dialog, IDC_PAD_1), read_binding(dialog, IDC_PAD_2)};
}

INT_PTR CALLBACK dialog_proc(HWND dialog, UINT message, WPARAM command, LPARAM parameter) {
    if (message == WM_INITDIALOG) {
        auto& editor = *reinterpret_cast<Editor*>(parameter);
        SetWindowLongPtrW(dialog, DWLP_USER, parameter);
        HWND action = GetDlgItem(dialog, IDC_ACTION);
        for (size_t i = 0; i < std::size(actions); ++i) add_choice(action, actions[i].label, static_cast<int>(i));
        SendMessageW(action, CB_SETCURSEL, 0, 0);
        for (int id : {IDC_KEY_1, IDC_KEY_2}) {
            HWND combo = GetDlgItem(dialog, id);
            add_choice(combo, L"None", unbound);
            for (int key = 1; key < SDL_NUM_SCANCODES; ++key) {
                if (valid_key(key)) add_sdl_choice(combo, SDL_GetScancodeName(static_cast<SDL_Scancode>(key)), key);
            }
        }
        constexpr const wchar_t* button_labels[] = {
            L"A / Cross", L"B / Circle", L"X / Square", L"Y / Triangle",
            L"Back / Share", L"Guide", L"Start / Options", L"Left Stick Click", L"Right Stick Click",
            L"Left Bumper", L"Right Bumper", L"D-pad Up", L"D-pad Down", L"D-pad Left", L"D-pad Right",
            L"Misc Button", L"Paddle 1", L"Paddle 2", L"Paddle 3", L"Paddle 4", L"Touchpad Click"
        };
        static_assert(std::size(button_labels) == first_axis);
        constexpr const wchar_t* axis_labels[] = {
            L"Left Stick Left", L"Left Stick Right", L"Left Stick Up", L"Left Stick Down",
            L"Right Stick Left", L"Right Stick Right", L"Right Stick Up", L"Right Stick Down",
            L"", L"Left Trigger", L"", L"Right Trigger"
        };
        for (int id : {IDC_PAD_1, IDC_PAD_2}) {
            HWND combo = GetDlgItem(dialog, id);
            add_choice(combo, L"None", unbound);
            for (int button = 0; button < first_axis; ++button) add_choice(combo, button_labels[button], button);
            for (size_t i = 0; i < std::size(axis_labels); ++i) {
                if (*axis_labels[i]) add_choice(combo, axis_labels[i], first_axis + static_cast<int>(i));
            }
        }
        sync_controls(dialog, editor);
        return TRUE;
    }
    if (message == WM_CLOSE) {
        EndDialog(dialog, IDCANCEL);
        return TRUE;
    }
    if (message != WM_COMMAND) return FALSE;
    auto* editor = reinterpret_cast<Editor*>(GetWindowLongPtrW(dialog, DWLP_USER));
    if (!editor) return FALSE;

    switch (LOWORD(command)) {
        case IDC_ACTION:
            if (HIWORD(command) == CBN_SELCHANGE) {
                store_controls(dialog, *editor);
                editor->action = static_cast<size_t>(read_binding(dialog, IDC_ACTION));
                sync_controls(dialog, *editor);
            }
            return TRUE;
        case IDC_DEFAULTS:
            editor->draft = defaults();
            sync_controls(dialog, *editor);
            return TRUE;
        case IDOK:
            store_controls(dialog, *editor);
            if (!save(editor->draft)) {
                MessageBoxW(dialog, L"Could not save your controls. Check that the settings folder is writable.",
                            L"Chopper Attack Controls", MB_OK | MB_ICONERROR);
                return TRUE;
            }
            EndDialog(dialog, IDOK);
            return TRUE;
        case IDCANCEL:
            EndDialog(dialog, IDCANCEL);
            return TRUE;
    }
    return FALSE;
}
#endif
Mapping read_mapping(std::istream& input) {
    Mapping loaded = defaults();
    bool legacy = true;
    for (std::string line; std::getline(input, line);) {
        if (line == settings_header) {
            legacy = false;
            continue;
        }
        std::istringstream record(line);
        std::string id;
        Bindings value{};
        if (!(record >> id >> value.key >> value.alternate_key >> value.pad >> value.alternate_pad)) continue;
        if (!valid_key(value.key) || !valid_key(value.alternate_key) ||
            !valid_pad(value.pad) || !valid_pad(value.alternate_pad)) continue;
        for (size_t i = 0; i < loaded.size(); ++i) {
            const auto& action = actions[i];
            if (id == action.id) {
                if (legacy && action.legacy_key != unbound &&
                    value.key == action.legacy_key && value.alternate_key == action.legacy_alternate_key) {
                    value.key = action.defaults.key;
                    value.alternate_key = action.defaults.alternate_key;
                }
                loaded[i] = value;
                break;
            }
        }
    }
    return loaded;
}

Input map_input(const Uint8* keys, SDL_GameController* pad) {
    Input input{};
    input.pad_connected = pad != nullptr;
    for (size_t i = 0; i < mapping.size(); ++i) {
        const auto& [key, alternate_key, binding, alternate_pad] = mapping[i];
        const bool keyboard = keys && ((key != unbound && keys[key]) || (alternate_key != unbound && keys[alternate_key]));
        const auto button = actions[i].button;
        const bool keyboard_flight = keyboard && button > 0 && button <= 0x0008;
        if (keyboard_flight) input.keyboard_flight |= button;
        const bool analog = button == 0;
        const float pad_value = std::max(pad_strength(pad, binding, analog),
                                         pad_strength(pad, alternate_pad, analog));
        switch (actions[i].flight) {
            case FlightAxis::forward: input.pad_thrust += pad_value; continue;
            case FlightAxis::reverse: input.pad_thrust -= pad_value; continue;
            case FlightAxis::left: input.pad_yaw -= pad_value; continue;
            case FlightAxis::right: input.pad_yaw += pad_value; continue;
            case FlightAxis::none: break;
        }
        const float key_value = keyboard ? 1.0f : 0.0f;
        const float value = std::max(key_value, pad_value);
        switch (i) {
            case 0: input.y += value; input.keyboard_pitch += key_value; break;
            case 1: input.y -= value; input.keyboard_pitch -= key_value; break;
            case 2: input.x -= value; input.keyboard_yaw -= key_value; break;
            case 3: input.x += value; input.keyboard_yaw += key_value; break;
            default:
                if (value > 0) input.buttons |= button;
                break;
        }
    }
    return input;
}

}

void load() {
    if (char* directory = SDL_GetPrefPath("ChopperAttack", "Recompiled")) {
        settings_path = std::filesystem::u8path(directory) / "controls.cfg";
        SDL_free(directory);
    }
    if (settings_path.empty()) return;
    std::ifstream input(settings_path);
    mapping = read_mapping(input);
}

void poll(SDL_GameController* pad) {
    publish(map_input(SDL_GetKeyboardState(nullptr), pad));
}

Input read() {
    std::lock_guard lock(input_mutex);
    return latest_input;
}

bool toggle_original_flight() {
    const bool enabled = !original_flight.load();
    original_flight.store(enabled);
    return enabled;
}

#ifdef _WIN32
void edit(SDL_Window* owner) {
    SDL_SysWMinfo wm{};
    SDL_VERSION(&wm.version);
    if (!SDL_GetWindowWMInfo(owner, &wm)) return;
    publish({});
    Editor editor{mapping};
    const INT_PTR result = DialogBoxParamW(GetModuleHandleW(nullptr), MAKEINTRESOURCEW(IDD_CONTROLS),
                                          wm.info.win.window, dialog_proc, reinterpret_cast<LPARAM>(&editor));
    if (result == IDOK) mapping = editor.draft;
    if (result == -1) SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Chopper Attack", "Could not open the controls menu.", owner);
}
#endif
}

extern "C" uint16_t chopper_flight_camera_mask(void) {
    if (chopper::controls::original_flight.load()) return 0;
    const auto input = chopper::controls::read();
    return input.keyboard_flight | (input.pad_connected ? 0x3 : 0);
}

extern "C" void chopper_apply_flight_controls(uint8_t* rdram, recomp_context* ctx) {
    if (chopper::controls::original_flight.load()) return;
    const auto input = chopper::controls::read();
    const uint16_t keys = input.keyboard_flight;
    if (!keys && !input.pad_connected) return;

    float thrust = input.pad_thrust;
    float turn = input.pad_yaw;
    if (keys) {
        turn = ((keys & 1) != 0) - ((keys & 2) != 0);
        thrust = (keys & 0xC) ? ((keys & 8) != 0) - ((keys & 4) != 0) : turn != 0;
    }
    uint16_t buttons = MEM_HU(0xE2, ctx->r29) & ~0xF00;
    if (thrust > 0) buttons |= 0x800;
    if (thrust < 0) buttons |= 0x400;
    MEM_H(0xE2, ctx->r29) = buttons;

    // The guest expects native stick units and applies its own pitch and yaw
    // smoothing. Keep manual keyboard aim available with a pad connected.
    // Stock flight consumes the N64 stick divided by eight (about +/-10).
    const fpr yaw{.fl = turn != 0.0f ? turn * 10.0f : input.keyboard_yaw * 7.0f};
    const fpr pitch{.fl = input.keyboard_pitch != 0.0f ? input.keyboard_pitch * 7.0f : thrust * 4.0f};
    MEM_W(0xE8, ctx->r29) = yaw.u32l;
    MEM_W(0xEC, ctx->r29) = pitch.u32l;
}
