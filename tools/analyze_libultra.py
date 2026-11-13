import os
import struct
import rabbitizer

with open('rom/chopper_attack.z64', 'rb') as f:
    rom = f.read()

# Read symbols
symbols = []
with open('chopper_symbols.toml', 'r') as f:
    for line in f:
        line = line.strip()
        if line.startswith('{') and 'vram =' in line:
            # { name = "func_80000450", vram = 0x80000450, size = 0x60 }
            parts = line.split(',')
            name = parts[0].split('"')[1]
            vram = int(parts[1].split('=')[1].strip(), 16)
            size = int(parts[2].split('=')[1].replace('}', '').strip(), 16)
            symbols.append({'name': name, 'vram': vram, 'size': size})

print(f"Total symbols: {len(symbols)}")

# Let's inspect functions from 0x8004E000 to end
libultra_range = [s for s in symbols if s['vram'] >= 0x8004F000]
print(f"Functions in libultra range (>= 0x8004F000): {len(libultra_range)}")

for s in libultra_range:
    offset = 0x1000 + (s['vram'] - 0x80000400)
    data = rom[offset : offset + s['size']]
    
    # Check for hardware register accesses (0x0400 to 0x0480 in upper 16 bits or 0xA400 to 0xA480)
    hw_refs = []
    jals = []
    mfc0s = []
    for i in range(0, len(data), 4):
        w = int.from_bytes(data[i:i+4], 'big')
        instr = rabbitizer.Instruction(w, vram=s['vram']+i)
        
        # Check jal
        if instr.isJumpWithAddress():
            target = instr.getInstrIndexAsVram()
            jals.append(target)
            
        # Check lui / registers
        opcode = w >> 26
        if opcode == 0x0F: # lui
            imm = w & 0xFFFF
            if imm in (0x0400, 0x0410, 0x0420, 0x0430, 0x0440, 0x0450, 0x0460, 0x0470, 0x0480,
                       0xA400, 0xA410, 0xA420, 0xA430, 0xA440, 0xA450, 0xA460, 0xA470, 0xA480):
                hw_refs.append(f"HW:0x{imm:04x}")
        elif (w >> 21) == 0x200: # mfc0
            hw_refs.append("mfc0")
        elif (w >> 21) == 0x204: # mtc0
            hw_refs.append("mtc0")

    hw_summary = ", ".join(set(hw_refs))
    if hw_summary or s['name'].startswith('os') or s['name'].startswith('__os'):
        print(f"0x{s['vram']:08x} ({s['size']:04x}): {s['name']:25s} | {hw_summary}")
