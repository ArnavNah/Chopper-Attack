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
- **Keyboard Fallback**: Fully playable with arrow keys/WASD and keyboard buttons
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
| **Left Analog Stick** | Steer Helicopter (Pitch & Roll) |
| **D-Pad** | Directional control |
| **A Button** (Cross) | Primary Weapon (Vulcan Cannon / Machine Gun) |
| **B Button** (Circle) | Secondary Weapon (Homing Missiles / Cluster Bombs) |
| **Right Bumper / RT** | Strafe Right |
| **Left Bumper / LT** | Strafe Left / Air Brake |
| **Start** | Pause / Mission Menu |

### Keyboard
| Key | Action |
| :--- | :--- |
| **W / Up Arrow** | Pitch Nose Down (Fly Forward) |
| **S / Down Arrow** | Pitch Nose Up (Fly Backward) |
| **A / Left Arrow** | Turn Left |
| **D / Right Arrow** | Turn Right |
| **Space / J** | N64 A button |
| **X / K** | N64 B button |
| **Z / Left Shift** | N64 Z trigger |
| **Q / E** | N64 L / R buttons |
| **Enter** | Start / Pause |
| **Esc** | Quit Game |

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
