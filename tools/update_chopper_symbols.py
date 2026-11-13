import os
import re

# Map of VRAM -> proper libultra symbol name
REPLACEMENTS = {
    0x80055EE0: "osInitialize",
    0x800527B0: "osCreateThread",
    0x80052570: "osStartThread",
    0x80056300: "osSetThreadPri",
    0x80060D90: "osDestroyThread",
    0x80052780: "osCreateMesgQueue",
    0x80056170: "osCreatePiManager",
    0x800564F0: "osGetTime",
    0x80050840: "osAiSetFrequency",
    0x800536A0: "osAiSetNextBuffer",
    0x800537D0: "osAiGetLength",
    0x800565C0: "__osDequeueThread",
    0x80056D2C: "__osEnqueueThread",
    0x80056D74: "__osPopThread",
    0x80056D84: "__osDispatchThread",
    0x80059730: "osViSetMode",
    0x800597A0: "osViSetEvent",
    0x80059890: "osViGetCurrentFramebuffer",
    0x800598D0: "osViGetNextFramebuffer",
    0x80059910: "osViSwapBuffer",
    0x80053630: "osViBlack",
    0x80055760: "osViSetSpecialFeatures",
    0x800547C0: "osSetEventMesg",
    0x8005C590: "osJamMesg",
    0x80060388: "osSetTimer",
}

with open("chopper_symbols.toml", "r") as f:
    lines = f.readlines()

new_lines = []
modified = 0

for line in lines:
    line_clean = line.strip()
    if line_clean.startswith("{") and "vram =" in line_clean:
        # e.g.: { name = "func_80055EE0", vram = 0x80055EE0, size = 0x288 },
        m = re.search(r'vram\s*=\s*(0x[0-9a-fA-F]+)', line_clean)
        if m:
            vram = int(m.group(1), 16)
            if vram in REPLACEMENTS:
                new_name = REPLACEMENTS[vram]
                line = re.sub(r'name\s*=\s*"[^"]+"', f'name = "{new_name}"', line)
                modified += 1
                print(f"Updated 0x{vram:08x} -> {new_name}")
    new_lines.append(line)

with open("chopper_symbols.toml", "w") as f:
    f.writelines(new_lines)

print(f"\nSuccessfully updated {modified} symbols in chopper_symbols.toml!")
