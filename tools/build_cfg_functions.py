import capstone

with open('rom/chopper_attack.z64', 'rb') as f:
    rom = f.read()

VRAM_BASE = 0x80000400
ROM_BASE = 0x1000
CODE_SIZE = 0x66100 # up to 0x80066500
VRAM_END = VRAM_BASE + CODE_SIZE

def v2r(v): return v - VRAM_BASE + ROM_BASE
def r2v(r): return r - ROM_BASE + VRAM_BASE

# Pass 1: find all JAL targets, branches, returns, and jumps
jal_targets = set()
jal_targets.add(VRAM_BASE)

branches = {} # vram -> target
j_targets = {} # vram -> target
returns = set() # vram of jr $ra

for offset in range(ROM_BASE, ROM_BASE + CODE_SIZE, 4):
    vram = r2v(offset)
    word = int.from_bytes(rom[offset:offset+4], 'big')
    op = (word >> 26) & 0x3F
    rs = (word >> 21) & 0x1F
    rt = (word >> 16) & 0x1F
    imm = word & 0xFFFF
    if imm >= 0x8000:
        imm -= 0x10000

    if op in (4, 5, 6, 7, 20, 21, 22, 23): # BEQ, BNE, BLEZ, BGTZ, BEQL, BNEL, BLEZL, BGTZL
        target = vram + 4 + (imm << 2)
        branches[vram] = target
    elif op == 1: # REGIMM
        if rt in (0, 1, 2, 3): # BLTZ, BGEZ, BLTZL, BGEZL
            target = vram + 4 + (imm << 2)
            branches[vram] = target
    elif op == 17: # COP1
        if rs == 8: # BC1
            target = vram + 4 + (imm << 2)
            branches[vram] = target
    elif op == 3: # JAL
        target = ((vram & 0xF0000000) | ((word & 0x03FFFFFF) << 2))
        if VRAM_BASE <= target < VRAM_END:
            jal_targets.add(target)
    elif op == 2: # J
        target = ((vram & 0xF0000000) | ((word & 0x03FFFFFF) << 2))
        if VRAM_BASE <= target < VRAM_END:
            j_targets[vram] = target
    elif op == 0 and (word & 0x3F) == 8 and rs == 31: # JR $ra
        returns.add(vram)

# Also check data pointers into code
data_ptrs = set()
for offset in range(0, len(rom) - 3, 4):
    word = int.from_bytes(rom[offset:offset+4], 'big')
    if VRAM_BASE <= word < VRAM_END and word % 4 == 0:
        data_ptrs.add(word)

print(f"JAL targets: {len(jal_targets)}")
print(f"Data pointers in code range: {len(data_ptrs)}")

# Any address with branch crossing over it CANNOT be a function boundary!
# Specifically, for every branch at vram -> target:
# The open interval (min(vram, target), max(vram, target)] is "bonded" together!
# No function can begin or end inside (min, max]!
cannot_split = [False] * (CODE_SIZE // 4 + 1)

for vram, target in branches.items():
    if VRAM_BASE <= target < VRAM_END:
        start_idx = (min(vram, target) - VRAM_BASE) // 4
        end_idx = (max(vram, target) - VRAM_BASE) // 4
        for i in range(start_idx + 1, end_idx + 1):
            cannot_split[i] = True

print(f"Total instructions protected by branch bonding: {sum(cannot_split)}")

# Now find function boundaries:
# A function starts at:
# 1. VRAM_BASE
# 2. Or: the instruction following the end of the previous function.
# An instruction at vram is the end of a function if:
# - It is the delay slot of a return (vram - 4 is in returns) OR the delay slot of an unconditional tail jump (vram - 4 in j_targets)
# - AND cannot_split[idx + 1] is False!
# - If the next words are 0 (nop padding), skip past all nops until the next non-nop instruction!

functions = [] # (start_vram, end_vram)
cur_start = VRAM_BASE

offset = ROM_BASE
while offset < ROM_BASE + CODE_SIZE:
    vram = r2v(offset)
    idx = (vram - VRAM_BASE) // 4
    word = int.from_bytes(rom[offset:offset+4], 'big')

    # Check if this instruction could end a function
    # Must be delay slot of JR RA or J tail call
    prev_vram = vram - 4
    is_exit_delay_slot = False
    if prev_vram in returns:
        is_exit_delay_slot = True
    elif prev_vram in j_targets:
        # If J targets something outside [cur_start, vram], it's a tail call exit!
        tgt = j_targets[prev_vram]
        if tgt < cur_start or tgt > vram:
            # But only if no branch connects backward
            is_exit_delay_slot = True

    if is_exit_delay_slot:
        # Check if we can split here
        next_vram = vram + 4
        next_idx = (next_vram - VRAM_BASE) // 4
        if next_idx < len(cannot_split) and not cannot_split[next_idx]:
            # This is a valid function end!
            func_end = vram + 4
            functions.append((cur_start, func_end))

            # Skip any NOP padding
            next_offset = v2r(func_end)
            while next_offset < ROM_BASE + CODE_SIZE:
                next_word = int.from_bytes(rom[next_offset:next_offset+4], 'big')
                if next_word == 0:
                    next_offset += 4
                else:
                    break
            cur_start = r2v(next_offset)
            offset = next_offset
            continue

    offset += 4

if cur_start < VRAM_END:
    functions.append((cur_start, VRAM_END))

print(f"Discovered {len(functions)} functions with CFG branch bonding!")

# Sanity check: do any branches cross outside of these functions?
violations = 0
for start, end in functions:
    for v in range(start, end, 4):
        if v in branches:
            tgt = branches[v]
            if tgt < start or tgt >= end:
                violations += 1
                if violations <= 10:
                    print(f"Branch violation: 0x{v:08X} -> 0x{tgt:08X} outside [0x{start:08X}, 0x{end:08X})")

print(f"Total branch violations across all functions: {violations}")
