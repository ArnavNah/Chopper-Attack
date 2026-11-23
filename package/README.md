# Chopper Attack - Native PC Recompilation

A native Windows 64-bit port of the Nintendo 64 game **Chopper Attack** (known in Japan as *Wild Choppers*), built using static binary recompilation via **N64Recomp**, **N64ModernRuntime**, **RT64** (DirectX 12 / Vulkan), and **SDL2**.

---

## 🚁 Overview

Unlike traditional emulation, this is a **fully native PC executable** (`ChopperAttack.exe`). The MIPS machine code from the original N64 game ROM has been statically recompiled into native C instructions and compiled with Microsoft Visual C++ with full hardware acceleration.

### Features
- **DirectX 12 Hardware Accelerated 3D Graphics** via RT64
- **Authentic 4:3 Aspect Ratio** with crisp modern scaling
- **Low-Latency Audio** output via SDL2 and WASAPI
- **Automatic Controller Support**: Native XInput (Xbox), PlayStation DualShock/DualSense, Switch Pro, and generic DirectInput gamepads
- **Keyboard Controls**: Fly and turn with WASD. Weapons aim at enemies in view.
- **Bring Your Own ROM (BYOR)**: Automatically detects `.z64`, `.n64`, and `.v64` ROMs with in-memory byte-order handling and a native Windows file selection dialog

---

## 🕹️ System Requirements

- **OS**: Windows 10 or Windows 11 (64-bit)
- **GPU**: DirectX 12 compatible graphics card (Intel Iris Xe, NVIDIA GeForce GTX 900+, AMD Radeon RX 400+)
- **Runtime**: Microsoft Visual C++ 2022 Redistributable (x64)
- **Original Game ROM**: *Chopper Attack* (USA NTSC)

---

## 🎮 How to Play

### 1. Place Your Game ROM
Place your legally dumped Chopper Attack ROM into the `rom/` folder:
- `rom/chopper_attack.z64` (recommended)
- Or `rom/Chopper Attack (USA).z64`

*Note: If no ROM is found in `rom/`, launching the game will automatically open a Windows Open File dialog asking you to browse and select your ROM.*

### 2. Launch the Game
- Double-click **`ChopperAttack.exe`** (or run `run.bat`).

---

## 🕹️ Default Controls

### Gamepad (Xbox / PlayStation / Generic)
| Button | Action |
| :--- | :--- |
| **Left Stick Up / Down** | Fly forward / backward with automatic tilt |
| **Right Stick Left / Right** | Turn the chopper left / right |
| **Left Stick / D-Pad** | Navigate menus |
| **A Button** (Cross) | Confirm / previous weapon |
| **B Button** (Circle) | Next weapon |
| **Right Bumper / RT** | Launch the selected weapon |
| **Left Bumper / LT** | Fire the Vulcan cannon |
| **Start** | Pause / Mission Menu |

### Remap controls on Windows

Press **F1** at the title screen or while paused. Choose an N64 action, then
select its primary and alternate keyboard or gamepad inputs. Choose **None**
to clear a binding or **Restore Defaults** to reset all bindings. **Save**
applies the changes and keeps them for future launches.

### Keyboard
| Key | Action |
| :--- | :--- |
| **W / S** | Fly forward / reverse |
| **A / D** | Turn left / right and advance with one key |
| **Arrow keys** | Navigate menus or aim manually |
| **Space / J** | Confirm / previous weapon |
| **X / K** | Next weapon |
| **Z / Left Shift** | Fire the Vulcan cannon |
| **E / Right Shift** | Launch the selected weapon |
| **Enter** | Start / Pause |
| **Esc** | Quit Game |

The keyboard and gamepad flight controls work with either setting under
**Control** in the game's Options screen. To rebind twin-stick movement,
use the **Gamepad Fly** and **Gamepad Turn** entries in the F1 menu.

The chopper tilts automatically as you fly forward, turn, or reverse.
Lock brackets mark the enemy the aim assist has picked, including when the
Vulcan cannon is your only weapon.

When you fire the Vulcan cannon, rockets, or missiles, aim assist favors live
enemies that are close to the chopper and near the center of the screen. Cluster bombs
get a downward launch angle when a ground target is within their drop range.
The dummy countermeasure keeps its normal defensive behavior.

---

## 📦 Package Contents

| File | Purpose |
| :--- | :--- |
| `ChopperAttack.exe` | Native PC Game Executable |
| `SDL2.dll` | SDL2 runtime for audio, windowing, and input |
| `dxcompiler.dll` | DirectX Shader Compiler for RT64 |
| `dxil.dll` | DirectX Intermediate Language validator |
| `rom/` | Directory for user's game ROM |
| `run.bat` | Convenient launcher script |
| `README.md` | User documentation |

---

## ⚖️ Legal & Disclaimer

This project is a clean-room static recompiler wrapper and runtime. **No copyrighted game ROMs, 3D models, textures, audio samples, or proprietary Nintendo 64 assets are distributed with this software.** Users must provide their own legally acquired copy of the original Nintendo 64 game cartridge ROM.

*Chopper Attack* is © 1997-1998 SETA Corporation / Midway Games Inc. All trademarks and copyrights belong to their respective owners.
