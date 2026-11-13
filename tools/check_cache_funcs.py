import re

funcs = []
with open('chopper_symbols.toml', 'r') as f:
    for line in f:
        m = re.search(r'name = "([^"]+)", vram = 0x([0-9A-Fa-f]+), size = 0x([0-9A-Fa-f]+)', line)
        if m:
            funcs.append((m.group(1), int(m.group(2), 16), int(m.group(3), 16)))

cache_addrs = [0x8005647C, 0x800564A0, 0x800564B0, 0x800564D4, 0x80059970, 0x8005F468, 0x8005F48C, 0x8005F4E8, 0x8005F50C]
found_funcs = set()
for ca in cache_addrs:
    for name, vram, size in funcs:
        if vram <= ca < vram + size:
            print(f'Cache at 0x{ca:08X} in {name} (0x{vram:08X}, size 0x{size:X})')
            found_funcs.add(name)
            break

print("All cache functions:", found_funcs)
