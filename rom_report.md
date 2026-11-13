# ROM Report: Chopper Attack (N64)

## 1. File & Header Identification
- **File Name**: `Chopper Attack (USA).z64`
- **File Size**: `8,388,608` bytes (8.00 MB / 64 Mbit)
- **Byte Order**: Native Big-Endian (`.z64`), Magic: `0x80371240`
- **Internal Title**: `CHOPPER_ATTACK`
- **Game Code**: `NCHE` (Cartridge ID: `CH`, Region: `E` / North America)
- **Media Format**: Cartridge (` ` / 0x20)
- **Version**: `1.0` (Byte: `0x00`)
- **Clock Rate**: `0x0000000F`
- **Entry Point**: `0x80000400`
- **Release Address**: `0x00001448`
- **CRC1**: `0x214CAD94`
- **CRC2**: `0xBE1A3B24`

## 2. Cryptographic Hashes & Verification
- **CRC32**: `AA5D76A9` (Matches official No-Intro database: *Chopper Attack (USA)*)
- **MD5**: `c37e8afb4f3ecc86d01ce7388ca59347`
- **SHA1**: `1e3f1c94c806b2699c4e0e941190d468435b9f60`
- **Bootcode / CIC**: Compatible with **CIC-NUS-6102** (Bootcode CRC32: `0x90BB6CB5`)

## 3. Binary Structure & Memory Layout
- **Code Architecture**: **Single static code segment** (No dynamic overlays, no relocatable modules).
- **Code Compression**: **None** (100% raw uncompressed MIPS32 assembly).
- **Entry Routine (`0x80000400`, ROM `0x001000`)**:
  - Clears BSS from VRAM `0x8008B5B0` for length `0x000B3C50` (to `0x8013F200`).
  - Sets stack pointer `sp` to `0x800DE360`.
  - Jumps directly to main entry point at `0x8001BF90` (ROM `0x01CB90`).
- **Segment Breakdown**:
  - **Header**: ROM `0x000000` - `0x000040`
  - **IPL3 Bootcode**: ROM `0x000040` - `0x001000`
  - **Main Code (.text)**: ROM `0x001000` - `0x067100` (VRAM `0x80000400` - `0x80066500`, ~408 KB)
  - **Embedded Audio Microcode**: ROM `0x067100` - `0x067D00` (VRAM `0x80066500` - `0x80067100`, ~3 KB)
  - **Main Data & Rodata**: ROM `0x067D00` - `0x07A690` (VRAM `0x80067100` - `0x80079A90`)
  - **RSP Graphics Microcode 1**: ROM `0x07A690` - `0x07B960`
  - **RSP Graphics Microcode 2**: ROM `0x07B960` - `0x08C1B0`
  - **Initialized Data End**: ROM `0x08C1B0` (VRAM `0x8008B5B0`)
  - **Streaming Asset Data**: ROM `0x08C1B0` - `0x7A30E1` (~7.09 MB streamed into RAM via PI DMA)
  - **Unused Padding**: ROM `0x7A30E2` - `0x800000` (`0xFF` fill)

## 4. Compiler & Toolchain Fingerprint
- **Compiler**: **SGI IDO** (CC 5.3 / 7.1) with `-O2` optimization:
  - High density of Branch Likely instructions: **1,609** out of 8,179 branches (**19.7%**), characteristic of SGI IDO loop unrolling and branch scheduling.
  - Classic SGI register allocation patterns (frequent `$at` temporary usage in displacement addressing, standard caller/callee register preservation).

## 5. Microcode Analysis
- **Graphics Microcode (RSP)**:
  - Header Tag at `0x07A690`:
    `RSP SW Version: 2.0H, 02-12-97 SGI U64 GFX SW TEAM: S Anderson, S Carr, H Cheng, K Luster, R Moore, N Pooley, A Srinivasan`
  - Microcode Family: **F3DEX / Fast3D 2.0H** (Standard N64 FIFO geometry microcode, 32-vertex cache).
  - Renderer Compatibility: Natively supported by **RT64** HLE/command parser.
- **Audio Microcode (RSP)**:
  - Located at ROM `0x067100`, referenced as `unknown.dl` at `0x067F10`.
  - Standard SGI / Libultra audio synthesis driver (`aspMain`), compatible with `N64ModernRuntime` / `RSPRecomp`.

## 6. Libultra Subsystems & Key Functions Identified
- **Interrupt & Cache Control**:
  - `0x80056580` (ROM `0x057180`): `__osDisableInt`
  - `0x800565A0` (ROM `0x0571A0`): `__osRestoreInt`
  - `0x80056440` (ROM `0x057040`): `osInvalDCache`
  - `0x800564C8` (ROM `0x0570C8`): `osInvalICache`
- **Threading & Messages**:
  - `0x800565C0` (ROM `0x0571C0`): `__osEnqueueThread` / `__osPopThread`
  - `0x8004F990` (ROM `0x050590`): `osRecvMesg`
  - `0x8004F7C0` (ROM `0x0503C0`): `osSendMesg`
- **I/O & DMA**:
  - `0x8000C5FC` (ROM `0x00D1FC`): Game PI DMA Chunk Manager (transfers ROM assets in 0x400-byte increments)
  - `0x80053EC0` (ROM `0x054AC0`): `osPiStartDma`
  - `0x8005F590` (ROM `0x060190`): `osPiRawReadIo` / `osEPiReadIo`

## 7. Save Type & Peripherals
- **Save Type**: **Controller Pak** (N64 Memory Card plugged into controller).
  - Uses libultra `osPfs*` API.
  - No cartridge EEPROM, FlashRAM, or SRAM on board.
- **Rumble Support**: Standard N64 Rumble Pak support via `osMotor*` / PFS interface.
