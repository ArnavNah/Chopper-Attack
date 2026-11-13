import capstone

with open('rom/chopper_attack.z64', 'rb') as f:
    rom = f.read()

VRAM_BASE = 0x80000400
ROM_BASE = 0x1000
CODE_SIZE = 0x66100
VRAM_END = VRAM_BASE + CODE_SIZE

def v2r(v): return v - VRAM_BASE + ROM_BASE
def r2v(r): return r - ROM_BASE + VRAM_BASE

# Pass 1: JAL targets, branches, returns
jal_targets = set()
jal_targets.add(VRAM_BASE)

branches = {} # vram -> target
j_targets = {} # vram -> target
returns = set() # vram of exit instructions

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

# Data pointers
data_ptrs = set()
for offset in range(0, len(rom) - 3, 4):
    word = int.from_bytes(rom[offset:offset+4], 'big')
    if VRAM_BASE <= word < VRAM_END and word % 4 == 0:
        data_ptrs.add(word)

# We define function split candidates:
# Any JAL target (except if inside a bonded branch interval)
# Any instruction right after an exit delay slot (JR / J / ERET) where cannot_split is False
# Any non-zero instruction preceded by NOP padding where cannot_split is False
split_points = set()
split_points.add(VRAM_BASE)

for jal in jal_targets:
    idx = (jal - VRAM_BASE) // 4
    if idx < len(cannot_split) and not cannot_split[idx]:
        split_points.add(jal)

for offset in range(ROM_BASE, ROM_BASE + CODE_SIZE, 4):
    vram = r2v(offset)
    idx = (vram - VRAM_BASE) // 4
    
    # Check if preceding instruction was an exit delay slot
    prev_vram = vram - 4
    prev_idx = idx - 1
    if prev_vram - 4 in returns or prev_vram - 4 in j_targets:
        if idx < len(cannot_split) and not cannot_split[idx]:
            # Also check that current instruction is not NOP padding
            word = int.from_bytes(rom[offset:offset+4], 'big')
            if word != 0:
                split_points.add(vram)
    
    # Check if this non-zero instruction follows a run of NOPs
    word = int.from_bytes(rom[offset:offset+4], 'big')
    if word != 0 and offset >= ROM_BASE + 4:
        prev_word = int.from_bytes(rom[offset-4:offset], 'big')
        if prev_word == 0: # preceded by NOP
            if idx < len(cannot_split) and not cannot_split[idx]:
                # If it's a known data pointer or JAL target or preceded by exit, split here
                if vram in data_ptrs or vram in jal_targets:
                    split_points.add(vram)

sorted_splits = sorted(list(split_points))
print(f"Total split points (function starts): {len(sorted_splits)}")

# Now construct functions list: (start, end)
funcs = []
for i in range(len(sorted_splits)):
    start = sorted_splits[i]
    if i + 1 < len(sorted_splits):
        # The function ends at sorted_splits[i+1], minus any trailing NOP padding
        raw_end = sorted_splits[i+1]
        # Trim trailing NOPs from the end of the function
        end = raw_end
        end_offset = v2r(end) - 4
        while end_offset >= v2r(start):
            w = int.from_bytes(rom[end_offset:end_offset+4], 'big')
            if w == 0:
                end -= 4
                end_offset -= 4
            else:
                break
        if end <= start:
            end = raw_end # keep raw if entirely nops somehow
        funcs.append((start, end))
    else:
        # Last function
        end = VRAM_END
        end_offset = v2r(end) - 4
        while end_offset >= v2r(start):
            w = int.from_bytes(rom[end_offset:end_offset+4], 'big')
            if w == 0:
                end -= 4
                end_offset -= 4
            else:
                break
        funcs.append((start, end))

print(f"Constructed {len(funcs)} functions.")

# Verify no branch violations
violations = 0
for s, e in funcs:
    for v in range(s, e, 4):
        if v in branches:
            tgt = branches[v]
            if tgt < s or tgt >= e:
                violations += 1

print(f"Branch violations: {violations}")

# Known libultra names mapping
known_names = {
    0x80000400: "recomp_entrypoint",
    0x8000C5FC: "dma_read_rom",
    0x8001BF90: "bootProc",
    0x8004F7C0: "osSendMesg",
    0x8004F990: "osRecvMesg",
    0x80050860: "osAiSetFrequency",
    0x80050930: "osAiSetNextBuffer",
    0x800509F0: "osAiGetLength",
    0x80053EC0: "osPiStartDma",
    0x80054040: "osEPiStartDma",
    0x80056440: "osInvalDCache",
    0x800564C8: "osInvalICache",
    0x80056500: "osWritebackDCache",
    0x80056580: "__osDisableInt",
    0x800565A0: "__osRestoreInt",
    0x800565C0: "__osEnqueueThread",
    0x80059290: "osSetIntMask",
    0x80060100: "osGetCount",
    0x80056600: "__osDispatchThread",
    0x80056D80: "__osPopThread",
    0x80059B40: "osSpTaskLoad",
    0x80061520: "osViSwapBuffer",
    0x80061730: "osViBlack",
    0x80061C40: "osSpTaskStartGo",
    0x80061BF0: "__osSpSetPc",
}

# Write chopper_symbols.toml
with open('chopper_symbols.toml', 'w') as f:
    f.write('[[section]]\n')
    f.write('name = "code"\n')
    f.write(f'rom = 0x{ROM_BASE:X}\n')
    f.write(f'vram = 0x{VRAM_BASE:X}\n')
    f.write(f'size = 0x{CODE_SIZE:X}\n\n')
    f.write('functions = [\n')
    for s, e in funcs:
        size = e - s
        name = known_names.get(s, f"func_{s:08X}")
        f.write(f'    {{ name = "{name}", vram = 0x{s:08X}, size = 0x{size:X} }},\n')
    f.write(']\n')

print("Wrote chopper_symbols.toml successfully!")
