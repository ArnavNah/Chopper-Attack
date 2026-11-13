import os
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

def get_code(vram, size):
    off = 0x1000 + (vram - 0x80000400)
    return rom[off:off+size]

def get_instrs(vram, size):
    data = get_code(vram, size)
    res = []
    for i in range(0, len(data), 4):
        w = int.from_bytes(data[i:i+4], 'big')
        res.append((w, rabbitizer.Instruction(w, vram=vram+i)))
    return res

# Let's inspect callers of osSendMesg (0x8004F7C0) and osRecvMesg (0x8004F990)
# and let's find osCreateMesgQueue, osSetEventMesg, osViSetEvent, osSetTimer, osStopTimer
# In libultra, osCreateMesgQueue initializes:
# mq->mtQueue = NULL
# mq->fullQueue = NULL
# mq->validCount = 0
# mq->first = 0
# mq->msgCount = msgCount
# mq->msg = msg

# Let's scan all symbols in the libultra range (>= 0x8004E000)
results = {}

for s in symbols:
    vram = s['vram']
    size = s['size']
    instrs = get_instrs(vram, size)
    words = [w for w, _ in instrs]
    
    # 1. osCreateMesgQueue
    # Typical IDO compiled:
    # sw $zero, 0x0($a0)
    # sw $zero, 0x4($a0)
    # sw $zero, 0x8($a0)
    # sw $zero, 0xC($a0)
    # sw $a2, 0x10($a0)
    # sw $a1, 0x14($a0)
    # jr $ra
    if any(w == 0xAC860010 for w in words) and any(w == 0xAC850014 for w in words):
        results[vram] = "osCreateMesgQueue"

    # 2. osJamMesg
    # Similar to osSendMesg (0x8004F7C0) but inserts at head instead of tail
    if size == 0x1BC and vram != 0x8004F7C0:
        results[vram] = "osJamMesg"

    # 3. osSetEventMesg(OSEvent event, OSMesgQueue *mq, OSMesg msg)
    # writes to __osEventStateTab[event]
    # In IDO:
    # lui $t6, %hi(__osEventStateTab)
    # sll $t7, $a0, 3 (or sll $t7, $a0, 4)
    # ...
    # sw $a1, %lo(__osEventStateTab)($t6)
    # sw $a2, ...
    if size in (0x48, 0x50, 0x54, 0x58, 0x60, 0x70) and any(w == 0x0C015960 for w in words): # jal __osDisableInt
        # check if it takes 3 args and stores them
        if any((w >> 26) == 0x2B and ((w >> 16) & 0x1F) == 5 for w in words): # sw $a1, ...
            if any((w >> 26) == 0x2B and ((w >> 16) & 0x1F) == 6 for w in words): # sw $a2, ...
                results[vram] = "osSetEventMesg"

    # 4. osViSetEvent(OSMesgQueue *mq, OSMesg msg, u32 retraceCount)
    # writes to __osViContext
    if any("0x8007" in str(ins) for _, ins in instrs if "lui" in str(ins)):
        if size in (0x30, 0x38, 0x40, 0x48, 0x50) and any(w == 0x0C015960 for w in words): # jal __osDisableInt
            # check if it stores $a0, $a1, $a2 into vi context
            pass

    # 5. osSetTimer(OSTimer *t, OSTime countdown, OSTime interval, OSMesgQueue *mq, OSMesg msg)
    # calls __osInsertTimer
    if size in (0x50, 0x60, 0x64, 0x70, 0x80, 0x90):
        # check if it takes 64-bit args in $a2/$a3 and stack
        if any(w == 0x8FA40018 for w in words): # lw $a0, 0x18($sp)
            results[vram] = "osSetTimer"

    # 6. osStopTimer(OSTimer *t)
    if size in (0x30, 0x38, 0x3C, 0x40, 0x44) and any(w == 0x0C015960 for w in words):
        # checks if t->next != NULL
        results[vram] = "osStopTimer"

for vram, name in sorted(results.items()):
    print(f"0x{vram:08x}: {name}")
