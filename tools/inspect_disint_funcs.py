import rabbitizer

with open('rom/chopper_attack.z64', 'rb') as f:
    rom = f.read()

funcs_to_check = [
    0x800534a0,
    0x80053630,
    0x800547c0,
    0x80055760,
    0x800593d0,
    0x8005c590,
    0x80060314,
    0x80060388,
    0x800629d0,
]

for vram in funcs_to_check:
    off = 0x1000 + (vram - 0x80000400)
    data = rom[off:off+0x40]
    print(f"=== 0x{vram:08x} ===")
    for i in range(0, min(len(data), 0x30), 4):
        w = int.from_bytes(data[i:i+4], 'big')
        print(f"  {vram+i:08x}: {rabbitizer.Instruction(w, vram=vram+i)}")
