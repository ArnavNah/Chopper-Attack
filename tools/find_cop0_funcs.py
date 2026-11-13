import re

# Read chopper_symbols.toml
funcs = []
with open('chopper_symbols.toml', 'r') as f:
    for line in f:
        m = re.search(r'name = "([^"]+)", vram = 0x([0-9A-Fa-f]+), size = 0x([0-9A-Fa-f]+)', line)
        if m:
            name = m.group(1)
            vram = int(m.group(2), 16)
            size = int(m.group(3), 16)
            funcs.append((name, vram, size))

with open('rom/chopper_attack.z64', 'rb') as f:
    rom = f.read()

VRAM_BASE = 0x80000400
ROM_BASE = 0x1000

cop0_funcs = {}
for offset in range(ROM_BASE, ROM_BASE + 0x66100, 4):
    vram = offset - ROM_BASE + VRAM_BASE
    word = int.from_bytes(rom[offset:offset+4], 'big')
    op = (word >> 26) & 0x3F
    if op == 0x10: # COP0
        rs = (word >> 21) & 0x1F
        rt = (word >> 16) & 0x1F
        rd = (word >> 11) & 0x1F
        # Find owning function
        for name, f_vram, size in funcs:
            if f_vram <= vram < f_vram + size:
                if name not in cop0_funcs:
                    cop0_funcs[name] = []
                cop0_funcs[name].append((vram, rs, rd))
                break

print(f"Total functions containing COP0 instructions: {len(cop0_funcs)}")
for name, list_insns in cop0_funcs.items():
    print(f"  {name}: {len(list_insns)} COP0 insns, e.g. {[f'0x{v:08X}: reg={rd}' for v, rs, rd in list_insns[:3]]}")
