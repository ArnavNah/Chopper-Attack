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

identified = {}

# 1. We know:
# osCreateThread: 0x800527B0
# osStartThread: 0x80052570
# osSetThreadPri: 0x80056300
# osDestroyThread: 0x80060D90
# osGetTime: 0x800564F0
# osCreatePiManager: 0x80056170
# osInitialize: 0x80055EE0
# __osDequeueThread: 0x800565C0
# __osEnqueueThread: 0x80056D2C
# __osPopThread: 0x80056D74
# __osDispatchThread: 0x80056D84
# __osDisableInt: 0x80056580
# __osRestoreInt: 0x800565A0
# osInvalDCache: 0x80056440
# osSetIntMask: 0x80059290
# osGetCount: 0x80060100
# __osSpSetPc: 0x80061BF0
# osSpTaskStartGo: 0x80061C40
# osSendMesg: 0x8004F7C0
# osRecvMesg: 0x8004F990
# osPiStartDma: 0x80053EC0

identified[0x800527B0] = "osCreateThread"
identified[0x80052570] = "osStartThread"
identified[0x80056300] = "osSetThreadPri"
identified[0x80060D90] = "osDestroyThread"
identified[0x800564F0] = "osGetTime"
identified[0x80056170] = "osCreatePiManager"
identified[0x80055EE0] = "osInitialize"
identified[0x800565C0] = "__osDequeueThread"
identified[0x80056D2C] = "__osEnqueueThread"
identified[0x80056D74] = "__osPopThread"
identified[0x80056D84] = "__osDispatchThread"
identified[0x80056580] = "__osDisableInt"
identified[0x800565A0] = "__osRestoreInt"
identified[0x80056440] = "osInvalDCache"
identified[0x80059290] = "osSetIntMask"
identified[0x80060100] = "osGetCount"
identified[0x80061BF0] = "__osSpSetPc"
identified[0x80061C40] = "osSpTaskStartGo"
identified[0x8004F7C0] = "osSendMesg"
identified[0x8004F990] = "osRecvMesg"
identified[0x80053EC0] = "osPiStartDma"

# Now let's search for others:
for s in symbols:
    vram = s['vram']
    size = s['size']
    if vram in identified:
        continue
    
    instrs = get_instrs(vram, size)
    words = [w for w, _ in instrs]
    
    # Check osCreateMesgQueue:
    # void osCreateMesgQueue(OSMesgQueue *mq, OSMesg *msgBuf, s32 count)
    # mq->mtQueue = NULL; mq->fullQueue = NULL; mq->validCount = 0; mq->first = 0; mq->msgCount = count; mq->msg = msgBuf;
    if size in (0x28, 0x30, 0x34) and len(words) >= 8:
        # Check sw $zero, 0($a0); sw $zero, 4($a0); sw $zero, 8($a0); sw $zero, 0xC($a0); sw $a2, 0x10($a0); sw $a1, 0x14($a0)
        has_sw_a2 = any(w == 0xAC860010 for w in words) # sw $a2, 0x10($a0)
        has_sw_a1 = any(w == 0xAC850014 for w in words) # sw $a1, 0x14($a0)
        if has_sw_a2 and has_sw_a1:
            identified[vram] = "osCreateMesgQueue"
            continue

    # Check osSetEventMesg(OSEvent event, OSMesgQueue *mq, OSMesg msg)
    # writes to __osEventStateTab[event]
    # table is 3 * 4 = 12 bytes per event, or 8 bytes per event
    if size in (0x50, 0x54, 0x58, 0x60, 0x64, 0x70) and any(w == 0x00041080 for w in words): # sll $v0, $a0, 2 or similar
        # Let's check if it calls __osDisableInt / __osRestoreInt
        calls_dis = any(w == 0x0C015960 for w in words) # jal 0x80056580
        if calls_dis and any("0x8007" in str(ins) for _, ins in instrs):
            # Could be osSetEventMesg
            pass

    # Check AI functions: access 0xA4500000
    ai_access = [ins for _, ins in instrs if "0xA450" in str(ins) or "0x0450" in str(ins)]
    if ai_access:
        # Let's check osAiSetFrequency
        # calculates dacrate: (2 * sys_clock) / freq - 1, writes to 0xA4500010
        if any(w == 0xAC400010 or "0x10" in str(ins) for w, ins in instrs if "sw" in str(ins)):
            if size > 0x80:
                identified[vram] = "osAiSetFrequency"
            elif size <= 0x30:
                identified[vram] = "osAiGetLength"
        # osAiSetNextBuffer writes to 0xA4500000 (dram addr) and 0xA4500004 (len)
        elif any("0x0($2)" in str(ins) or "0x4($2)" in str(ins) for _, ins in instrs if "sw" in str(ins)):
            if size >= 0x80:
                identified[vram] = "osAiSetNextBuffer"

    # Check VI functions: access 0xA4400000 or 0x04400000
    vi_access = [ins for _, ins in instrs if "0xA440" in str(ins) or "0x0440" in str(ins)]
    if vi_access:
        # osViSwapBuffer writes to origin (0x04400004) or context
        if size == 0x88: # 0x8005C504 is size 0x88
            identified[vram] = "osViSwapBuffer"
        elif size == 0x378: # 0x80061550
            identified[vram] = "osViSetMode"

    # Check SI / Controller functions
    si_access = [ins for _, ins in instrs if "0xA480" in str(ins) or "0x0480" in str(ins)]
    if si_access:
        if size == 0xA8:
            identified[vram] = "osContInit"

    # Check osSpTaskLoad
    if size in (0x3A0, 0x3AC, 0x3B0, 0x180, 0x18C) and any("0x0400" in str(ins) for _, ins in instrs):
        if size == 0x3AC:
            identified[vram] = "osSpTaskLoad"

    # Check osWritebackDCache / osWritebackDCacheAll / osInvalICache
    # cache instructions have opcode 0x2F (47)
    cache_instrs = [ins for w, ins in instrs if (w >> 26) == 0x2F]
    if cache_instrs:
        # cache op 0x10 is Hit_Writeback_Inv_D, 0x19 is Hit_Invalidate_I, 0x14 is Index_Writeback_Inv_D
        ops = set((w >> 16) & 0x1F for w, _ in instrs if (w >> 26) == 0x2F)
        if 0x10 in ops: # Hit_Writeback_Inv_D
            identified[vram] = "osWritebackDCache"
        elif 0x19 in ops or 0x00 in ops:
            identified[vram] = "osInvalICache"
        elif 0x14 in ops:
            identified[vram] = "osWritebackDCacheAll"

    # Check osVirtualToPhysical
    # addresses < 0x80000000 or > 0xC0000000 return -1, else addr & 0x1FFFFFFF
    if size in (0x1C, 0x20, 0x24):
        # sltu or andi with 0x1FFF
        if any((w & 0xFFFF) == 0x1FFF for w in words):
            identified[vram] = "osVirtualToPhysical"

for vram, name in sorted(identified.items()):
    print(f"0x{vram:08x}: {name}")

print(f"\nTotal identified: {len(identified)}")
