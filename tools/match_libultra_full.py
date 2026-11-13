import os
import rabbitizer

with open('rom/chopper_attack.z64', 'rb') as f:
    rom = f.read()

# Load all boot_functions from mm-decomp
mm_funcs = []
with open('tools/Zelda64Recomp/lib/mm-decomp/tools/sizes/boot_functions.csv', 'r') as f:
    for line in f:
        line = line.strip()
        if not line:
            continue
        parts = line.split(',')
        path, name, vram_s, count_s = parts[0], parts[1], parts[2], parts[3]
        mm_funcs.append({
            'path': path,
            'name': name,
            'vram': int(vram_s, 16),
            'count': int(count_s, 16), # number of instructions
            'bytes': int(count_s, 16) * 4
        })

print(f"Loaded {len(mm_funcs)} mm-decomp libultra functions.")

# Load Chopper symbols
symbols = []
with open('chopper_symbols.toml', 'r') as f:
    for line in f:
        line = line.strip()
        if line.startswith('{') and 'vram =' in line:
            parts = line.split(',')
            name = parts[0].split('"')[1]
            vram = int(parts[1].split('=')[1].strip(), 16)
            size = int(parts[2].split('=')[1].replace('}', '').strip(), 16)
            symbols.append({'name': name, 'vram': vram, 'size': size})

# Check functions in Chopper Attack
chopper_libultra = [s for s in symbols if s['vram'] >= 0x8004F000]

# Build dictionary of mm_funcs by name
mm_by_name = {f['name']: f for f in mm_funcs}

# Let's inspect each function in chopper_libultra and see if any matches known mm function by size or signature
matches = {}
for s in chopper_libultra:
    offset = 0x1000 + (s['vram'] - 0x80000400)
    data = rom[offset : offset + s['size']]
    instr_count = s['size'] // 4
    
    # Potential candidates by instruction count (exact or +- 4 instructions due to compiler/version)
    candidates = [f for f in mm_funcs if abs(f['count'] - instr_count) <= 2]
    # If already named as an os function:
    if s['name'].startswith('os') or s['name'].startswith('__os'):
        matches[s['vram']] = s['name']
        print(f"Existing: 0x{s['vram']:08x} -> {s['name']} (size: 0x{s['size']:x})")
    elif candidates:
        names = [c['name'] for c in candidates]
        # print(f"0x{s['vram']:08x} size 0x{s['size']:x} ({instr_count} instrs) candidates: {', '.join(names[:5])}")

print(f"Total matched so far: {len(matches)}")
