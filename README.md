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

### PlayStation Vita development

The experimental Vita application uses the recompiled game and RSP audio code
with Vita-native audio and input, plus a Fast3D renderer on vitaGL. The renderer
renders the widescreen game buffers at 848×480, then scales them to the Vita's
960×544 display. Menus and the HUD keep their original 4:3 proportions.
The port uses the GPL-3.0 renderer and Vita runtime adaptations from
[The New Tetris: Recompiled](https://github.com/SeveerJ/tnt64-recomp).
The Fast3D and widescreen changes are in `vita/fast3d-renderer.patch`.
See [the GPL-3.0 license text](vita/COPYING) for the code adapted from that project.

Set `VITASDK`, install the `vitaGL`, `vitaShaRK`, `SceShaccCgExt`,
`libmathneon`, and `taihen` VitaSDK packages, and prepare the pinned game
dependencies as described below. Then build the Vita application separately
from the Windows build.

```sh
python vita/prepare.py
cmake -S vita -B build/vita -G Ninja -DCMAKE_BUILD_TYPE=Release -DCHOPPER_VITA_APP=ON
cmake --build build/vita
```

To cross-compile just the game core, configure with `-DCHOPPER_VITA_APP=OFF`.

If your N64Recomp checkout predates Vita support, apply the ARM32 header patch
once from the project root.

```sh
git -C tools/N64ModernRuntime/N64Recomp apply ../../../patches/N64Recomp-arm32.patch
```

On a modded Vita, install `build/vita/ChopperAttack.vpk` with VitaShell. vitaGL needs
`libshacccg.suprx` in `ur0:data/` or `ur0:data/external/`. Supply your own
USA ROM at `ux0:data/ChopperAttack/chopper_attack.z64`. The app writes its
startup log and saves under `ux0:data/ChopperAttack/`. Game assets are loaded
from the ROM at runtime.

| Vita input | Action |
| --- | --- |
| Left stick up/down | Fly forward/reverse and pitch |
| Right stick left/right | Turn left/right |
| L / R | Fire cannon / fire equipped weapon |
| Cross / Circle | Confirm or previous weapon / back or next weapon |
| D-pad or left stick | Navigate menus |
| Right stick | N64 C-buttons in menus |
| Triangle | N64 C-Up |
| Select + Triangle | Switch between twin-stick and original N64 flight |
| Start | Pause |
| Hold Start + Select for 2 seconds | Quit |

On Windows, press F2 to switch flight layouts. The original layout sends the
left stick, D-pad, and C-buttons through the game's stock movement code. The
right stick supplies the C-buttons on both platforms. The game’s handedness
setting determines whether the D-pad or C-buttons handle movement.

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
- **Left Stick Up / Down**: Fly forward / backward with automatic tilt
- **Right Stick Left / Right**: Turn the chopper left / right
- **Left Stick / D-Pad**: Navigate menus
- **A Button (Cross)**: Confirm / previous weapon
- **B Button (Circle)**: Next weapon
- **Left Trigger / L1**: Fire the Vulcan cannon
- **Right Trigger / R1**: Launch the selected weapon
- **Start**: Pause / In-Game Menu

### Remap controls on Windows

Press **F1** at the title screen or while paused. Choose an N64 action, then
select its primary and alternate keyboard or gamepad inputs. Choose **None**
to clear a binding or **Restore Defaults** to reset all bindings. **Save**
applies the changes and keeps them for future launches.

### Keyboard
- **W / S**: Fly forward / reverse
- **A / D**: Turn left / right and advance with one key
- **Arrow keys**: Navigate menus or aim manually
- **Space / J**: Confirm / previous weapon
- **X / K**: Next weapon
- **Z / Left Shift**: Fire the Vulcan cannon
- **E / Right Shift**: Launch the selected weapon
- **Enter**: Start / Pause
- **Esc**: Exit

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
