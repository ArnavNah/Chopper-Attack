import struct

with open('rom/chopper_attack.z64', 'rb') as f:
    rom = f.read()

def vram_to_rom(vram):
    return 0x1000 + (vram - 0x80000400)

funcs = [
    ("osRecvMesg", 0x8004F990, 0x1DC),
    ("osCreateMesgQueue", 0x80052780, 0x2C),
    ("osCreateThread", 0x800527B0, 0x140),
    ("osStartThread", 0x80052570, 0x150),
    ("osSendMesg", 0x800534A0, 0x14C),
    ("osJamMesg", 0x8005C590, 0x150),
    ("osViBlack", 0x80053630, 0x6C),
    ("osViSetMode", 0x80059730, 0x64),
    ("osViSetEvent", 0x800597A0, 0x68),
    ("osViSwapBuffer", 0x80059910, 0x4C),
    ("osSpTaskLoad", 0x80059AAC, 0x18C),
    ("osSpTaskStartGo", 0x80059C3C, 0x3C),
    ("osPiStartDma", 0x80053EC0, 0x10C),
    ("osAiSetFrequency", 0x80050840, 0x160),
    ("osAiGetLength", 0x800537D0, 0x14)
]

for name, vram, sz in funcs:
    rom_off = vram_to_rom(vram)
    bytes_sample = rom[rom_off:rom_off+16]
    hex_str = ' '.join(f'{b:02X}' for b in bytes_sample)
    print(f"{name:20s} @ {hex(vram)} (ROM {hex(rom_off)}): {hex_str}")
