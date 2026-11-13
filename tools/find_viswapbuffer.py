import rabbitizer

with open('rom/chopper_attack.z64', 'rb') as f:
    rom = f.read()

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

for s in symbols:
    if s['size'] in (0x28, 0x30, 0x34, 0x38, 0x40, 0x48, 0x50):
        off = 0x1000 + (s['vram'] - 0x80000400)
        data = rom[off:off+s['size']]
        words = [int.from_bytes(data[i:i+4], 'big') for i in range(0, len(data), 4)]
        # Check if calls __osDisableInt (0x80056580 -> JAL 0x0C015960) and __osRestoreInt (0x800565A0 -> JAL 0x0C015968)
        if 0x0C015960 in words and 0x0C015968 in words:
            print(f'Candidate: 0x{s["vram"]:08x} ({s["name"]}) size 0x{s["size"]:x}')
            for i in range(0, len(data), 4):
                w = words[i//4]
                print(f'   {s["vram"]+i:08x}: {rabbitizer.Instruction(w, vram=s["vram"]+i)}')
