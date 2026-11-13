with open('rom/chopper_attack.z64', 'rb') as f:
    rom = f.read()

VRAM_BASE = 0x80000400
ROM_BASE = 0x1000
CODE_SIZE = 0x66100
VRAM_END = VRAM_BASE + CODE_SIZE

def v2r(v): return v - VRAM_BASE + ROM_BASE
def r2v(r): return r - ROM_BASE + VRAM_BASE

# Collect all JAL targets
jal_targets = set()
jal_targets.add(VRAM_BASE)

branches = {} # vram -> target
j_targets = {} # vram -> target
returns = set() # vram of jr, eret, etc.

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
    elif op == 0 and (word & 0x3F) == 8: # JR ($ra or any reg)
        returns.add(vram)
    elif word == 0x42000018: # ERET
        returns.add(vram)

# Compute cannot_split intervals based on all branches
cannot_split = [False] * (CODE_SIZE // 4 + 1)
for vram, target in branches.items():
    if VRAM_BASE <= target < VRAM_END:
        start_idx = (min(vram, target) - VRAM_BASE) // 4
        end_idx = (max(vram, target) - VRAM_BASE) // 4
        for i in range(start_idx + 1, end_idx + 1):
            cannot_split[i] = True

# Also: JAL targets MUST be split points (function starts)
# If a JAL target has cannot_split[idx] == True, that would mean a branch crosses over a JAL target!
conflicts = []
for jal in jal_targets:
    idx = (jal - VRAM_BASE) // 4
    if idx < len(cannot_split) and cannot_split[idx]:
        conflicts.append(jal)

print(f"JAL targets conflicting with branch boundaries: {len(conflicts)}")
for c in conflicts:
    print(f"  Conflict at 0x{c:08X}")
