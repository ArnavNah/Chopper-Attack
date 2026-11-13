import re

with open('chopper_symbols.toml', 'r') as f:
    for line in f:
        m = re.search(r'name = "(os\w+|__os\w+)",\s*vram = (0x[0-9A-Fa-f]+),\s*size = (0x[0-9A-Fa-f]+)', line)
        if m:
            name, vram, size = m.groups()
            print(f"{name:25s} | VRAM: {vram} | Size: {size}")
