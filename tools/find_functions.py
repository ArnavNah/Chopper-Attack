import capstone

with open('rom/chopper_attack.z64', 'rb') as f:
    rom = f.read()

VRAM_BASE = 0x80000400
ROM_BASE = 0x1000
CODE_SIZE = 0x66100
VRAM_END = VRAM_BASE + CODE_SIZE

def v2r(v): return v - VRAM_BASE + ROM_BASE

# Collect all JAL targets
jal_targets = set()
jal_targets.add(VRAM_BASE)

branches = {} # vram -> target
j_targets = {} # vram -> target
jr_ras = set()
other_jrs = set()

for offset in range(ROM_BASE, ROM_BASE + CODE_SIZE, 4):
    vram = offset - ROM_BASE + VRAM_BASE
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
    elif op == 0: # SPECIAL
        funct = word & 0x3F
        if funct == 8: # JR
            if rs == 31:
                jr_ras.add(vram)
            else:
                other_jrs.add(vram)

# Code pointers in data
data_ptrs = set()
for offset in range(0, len(rom) - 3, 4):
    word = int.from_bytes(rom[offset:offset+4], 'big')
    if VRAM_BASE <= word < VRAM_END and word % 4 == 0:
        data_ptrs.add(word)

print(f"JAL targets: {len(jal_targets)}")
print(f"Data pointers into code: {len(data_ptrs)}")
print(f"Branches: {len(branches)}")
print(f"JR RAs: {len(jr_ras)}")

# Union-Find for address connectivity
# If there is a branch from A to B, all addresses between min(A, B) and max(A, B) are in the same function span!
# Also, normal fallthrough connects addr to addr + 4 UNLESS addr is an unconditional transfer (JR RA, J, unconditional B)
# AND no branch reaches past addr + 4!

# For each address, what is the maximum forward branch that crosses over it?
# Or more simply: an interval graph of [min(v, target), max(v, target)] for all branches!
intervals = []
for v, target in branches.items():
    if VRAM_BASE <= target < VRAM_END:
        intervals.append((min(v, target), max(v, target)))

print(f"Total branch intervals: {len(intervals)}")

# Merge overlapping intervals
intervals.sort()
merged_intervals = []
for start, end in intervals:
    if not merged_intervals:
        merged_intervals.append([start, end])
    else:
        last = merged_intervals[-1]
        if start <= last[1]:
            last[1] = max(last[1], end)
        else:
            merged_intervals.append([start, end])

print(f"Merged connected branch intervals: {len(merged_intervals)}")

# Check: Does any merged interval contain an internal JR RA?
intervals_with_jr_ra = 0
for start, end in merged_intervals:
    jrs = [jr for jr in jr_ras if start <= jr <= end]
    if len(jrs) > 1 or (len(jrs) == 1 and jrs[0] < end):
        intervals_with_jr_ra += 1

print(f"Intervals spanning across early returns (JR RA): {intervals_with_jr_ra}")
