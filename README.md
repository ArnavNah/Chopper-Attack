# Chopper Attack - Native PC Recompilation (N64)

A clean-room native PC port of the Nintendo 64 game **Chopper Attack** (SETA / Midway, 1997-1998) running directly on modern Windows (x64) and Linux, powered by static binary recompilation.

---

## 🏗️ Architecture

```
                                  +-----------------------+
                                  | Chopper Attack ROM    |
                                  | (BYOR: .z64/.n64/.v64)|
                                  +-----------+-----------+
                                              |
                                              v
+-------------------------+       +-----------+-----------+       +----------------------+
| CFG Branch-Bonding Tool | ----> |   chopper_symbols.toml| ----> |      N64Recomp       |
| (tools/generate_valid)  |       +-----------------------+       |   (Static Binary     |
+-------------------------+                                       |     Recompiler)      |
                                                                  +-----------+----------+
                                                                              |
                                                                              v
                                                                  +-----------+----------+
                                                                  |  35 Recompiled C     |
                                                                  |  Source Files        |
                                                                  +-----------+----------+
                                                                              |
                                                                              v
    +-----------------------+     +-----------------------+       +-----------+----------+
    |        RT64           |     |    N64ModernRuntime   |       |                      |
    | (DirectX 12 / Vulkan) | <-> | (ultra64 / librecomp) | <---> |  ChopperAttack.exe   |
    +-----------------------+     +-----------------------+       |  (Native PC Game)    |
                |                             |                   |                      |
                v                             v                   +----------------------+
        [Modern GPU 3D]               [SDL2 Audio / Input]
```

---

## 🚀 Quick Start (Running the Game)

1. Navigate to the `package/` folder.
2. Place your legally owned copy of the N64 game ROM inside `package/rom/chopper_attack.z64` (or double-click the executable to use the Windows file picker).
3. Run `ChopperAttack.exe` or `run.bat`.

---

## 🛠️ Building From Source

### Prerequisites (Windows 11)
- **Visual Studio 2022 Build Tools** (MSVC `cl.exe` 19.40+, C++20 support)
- **CMake** 3.25+
- **Ninja** build system
- **Windows SDK 10 / 11**
- **Python 3.10+** (with `capstone`, `pyyaml`)

### Build Steps

For a fresh clone, open a Visual Studio developer shell and run `powershell -ExecutionPolicy Bypass -File tools/setup_dependencies.ps1 -BuildRecompiler`. This checks out the pinned dependencies and applies the project-specific runtime patches. Put your ROM at `rom/chopper_attack.z64` before continuing. The ROM and generated build artifacts are not included in this repository.

1. **Regenerate CPU and audio code and reapply runtime patches**:
   ```cmd
   python tools\regenerate.py
   ```

2. **Configure & Build PC Executable with CMake + Ninja**:
   ```cmd
   call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat"
   cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
   ninja -C build
   ```

3. **Assemble Release Package**:
   ```cmd
   powershell -ExecutionPolicy Bypass -File tools\package_release.ps1
   ```

---

## 🎮 Controls

### Gamepad (Xbox / PlayStation / Switch Pro / DirectInput)
- **Left Stick / D-Pad**: Pitch & Roll (Fly & Aim)
- **A Button (Cross)**: Primary Weapon (Vulcan Cannon)
- **B Button (Circle)**: Secondary Weapon (Missiles / Bombs)
- **Left Trigger / L1**: Strafe Left / Air Brake
- **Right Trigger / R1**: Strafe Right
- **Start**: Pause / In-Game Menu

### Keyboard
- **W / S / Up / Down**: Pitch Nose Down / Up
- **A / D / Left / Right**: Turn Left / Right
- **Space / J**: N64 A button
- **X / K**: N64 B button
- **Z / Left Shift**: N64 Z trigger
- **Q / E**: Strafe Left / Right
- **Enter**: Start / Pause
- **Esc**: Exit

---

## 📋 Reverse Engineering & Toolchain Highlights

1. **Splat & CFG Branch-Bonding**:
   - The game code segment spans VRAM `0x80000400` to `0x80066500` (~408 KB).
   - Custom CFG branch-bonding algorithm mapped 860 valid functions with zero intra-procedural branch violations across all 9,480 MIPS branch instructions.
2. **Libultra Modern OS Replacement**:
   - Replaced raw N64 Serial Interface (SI), Peripheral Interface (PI), and Display Processor (DP) polling loops with modern OS message queues and host multithreading.
   - Accurately mapped and intercepted `osContInit`, `osContStartReadData`, `osContGetReadData`, `osMotorInit`, `osMotorStart`, `osMotorStop`, and `osPfsInitPak`.
3. **Hardware-Accelerated Rendering (RT64)**:
   - F3DEX 2.0H RSP display lists are intercepted via `osSpTaskLoad` and `osSpTaskStartGo` and passed directly into RT64's DirectX 12 graphics pipeline.

---

## ⚖️ Legal Disclaimer

This software does not include any Nintendo 64 game assets, copyrighted ROMs, audio files, textures, or proprietary code. Users must supply their own legally obtained ROM cartridge dump.

*Chopper Attack* is a trademark of SETA Corporation / Midway Games Inc.
