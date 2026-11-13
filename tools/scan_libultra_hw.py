import capstone

md = capstone.Cs(capstone.CS_ARCH_MIPS, capstone.CS_MODE_MIPS32 + capstone.CS_MODE_BIG_ENDIAN)

with open('rom/chopper_attack.z64', 'rb') as f:
    rom = f.read()

VRAM_BASE = 0x80000400
ROM_BASE = 0x1000

def v2r(v): return v - VRAM_BASE + ROM_BASE

# Let's inspect string references in libultra code:
# Often __assert or debug strings or hardware addresses reveal function identities
hw_map = {
    0x04000000: "SP_MEM_ADDR",
    0x04000004: "SP_DRAM_ADDR",
    0x04000008: "SP_RD_LEN",
    0x0400000C: "SP_WR_LEN",
    0x04000010: "SP_STATUS",
    0x04000014: "SP_DMA_FULL",
    0x04000018: "SP_DMA_BUSY",
    0x0400001C: "SP_SEMAPHORE",
    0x04040010: "SP_PC",
    0x04100000: "DPC_START",
    0x04100004: "DPC_END",
    0x0410000C: "DPC_STATUS",
    0x04300000: "MI_INIT_MODE",
    0x04300004: "MI_VERSION",
    0x04300008: "MI_INTR",
    0x0430000C: "MI_INTR_MASK",
    0x04400000: "VI_STATUS",
    0x04400004: "VI_ORIGIN",
    0x04400008: "VI_WIDTH",
    0x0440000C: "VI_INTR",
    0x04400010: "VI_V_CURRENT_LINE",
    0x04500000: "AI_DRAM_ADDR",
    0x04500004: "AI_LEN",
    0x04500008: "AI_CONTROL",
    0x0450000C: "AI_STATUS",
    0x04500010: "AI_DACRATE",
    0x04500014: "AI_BITRATE",
    0x04600000: "PI_DRAM_ADDR",
    0x04600004: "PI_CART_ADDR",
    0x04600008: "PI_RD_LEN",
    0x0460000C: "PI_WR_LEN",
    0x04600010: "PI_STATUS",
    0x04800000: "SI_DRAM_ADDR",
    0x04800004: "SI_PIF_ADDR_RD64B",
    0x04800010: "SI_PIF_ADDR_WR64B",
    0x04800018: "SI_STATUS"
}

print("Libultra hardware references:")
for offset in range(v2r(0x8004E000), v2r(0x80066500), 4):
    vram = offset - ROM_BASE + VRAM_BASE
    word = int.from_bytes(rom[offset:offset+4], 'big')
    # look for lui $reg, 0x04xx or 0xA4xx
    op = (word >> 26) & 0x3F
    imm = word & 0xFFFF
    if op == 0x0F: # LUI
        hw_base = (imm << 16) & 0xFFFFFFFF
        if (hw_base & 0x1FFFFFFF) in (0x04000000, 0x04100000, 0x04300000, 0x04400000, 0x04500000, 0x04600000, 0x04700000, 0x04800000):
            print(f"0x{vram:08X}: LUI 0x{hw_base:08X}")
