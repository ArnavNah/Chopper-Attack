#include "recomp.h"
#include "trace.h"
#include "funcs.h"

RECOMP_FUNC void func_8000665C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000665C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80006660: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80006664: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80006668: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x8000666C: sra         $v1, $v0, 21
    ctx->r3 = S32(SIGNED(ctx->r2) >> 21);
    // 0x80006670: sra         $a1, $v0, 16
    ctx->r5 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80006674: andi        $t7, $v1, 0x1F
    ctx->r15 = ctx->r3 & 0X1F;
    // 0x80006678: andi        $t8, $a1, 0x1F
    ctx->r24 = ctx->r5 & 0X1F;
    // 0x8000667C: beq         $t7, $zero, L_800066B8
    if (ctx->r15 == 0) {
        // 0x80006680: or          $a1, $t8, $zero
        ctx->r5 = ctx->r24 | 0;
            goto L_800066B8;
    }
    // 0x80006680: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80006684: beq         $t8, $zero, L_800066A4
    if (ctx->r24 == 0) {
        // 0x80006688: addiu       $a0, $sp, 0x20
        ctx->r4 = ADD32(ctx->r29, 0X20);
            goto L_800066A4;
    }
    // 0x80006688: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8000668C: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x80006690: addiu       $a1, $a1, 0x4A50
    ctx->r5 = ADD32(ctx->r5, 0X4A50);
    // 0x80006694: jal         0x80007098
    // 0x80006698: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    func_80007098(rdram, ctx);
        goto after_0;
    // 0x80006698: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x8000669C: b           L_800066E8
    // 0x800066A0: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
        goto L_800066E8;
    // 0x800066A0: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
L_800066A4:
    // 0x800066A4: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x800066A8: jal         0x80007098
    // 0x800066AC: addiu       $a1, $a1, 0x4A64
    ctx->r5 = ADD32(ctx->r5, 0X4A64);
    func_80007098(rdram, ctx);
        goto after_1;
    // 0x800066AC: addiu       $a1, $a1, 0x4A64
    ctx->r5 = ADD32(ctx->r5, 0X4A64);
    after_1:
    // 0x800066B0: b           L_800066E8
    // 0x800066B4: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
        goto L_800066E8;
    // 0x800066B4: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
L_800066B8:
    // 0x800066B8: beq         $a1, $zero, L_800066D8
    if (ctx->r5 == 0) {
        // 0x800066BC: addiu       $a0, $sp, 0x20
        ctx->r4 = ADD32(ctx->r29, 0X20);
            goto L_800066D8;
    }
    // 0x800066BC: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x800066C0: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x800066C4: addiu       $a1, $a1, 0x4A70
    ctx->r5 = ADD32(ctx->r5, 0X4A70);
    // 0x800066C8: jal         0x80007098
    // 0x800066CC: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    func_80007098(rdram, ctx);
        goto after_2;
    // 0x800066CC: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_2:
    // 0x800066D0: b           L_800066E8
    // 0x800066D4: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
        goto L_800066E8;
    // 0x800066D4: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
L_800066D8:
    // 0x800066D8: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x800066DC: jal         0x80007098
    // 0x800066E0: addiu       $a1, $a1, 0x4A7C
    ctx->r5 = ADD32(ctx->r5, 0X4A7C);
    func_80007098(rdram, ctx);
        goto after_3;
    // 0x800066E0: addiu       $a1, $a1, 0x4A7C
    ctx->r5 = ADD32(ctx->r5, 0X4A7C);
    after_3:
    // 0x800066E4: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
L_800066E8:
    // 0x800066E8: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x800066EC: jal         0x80006110
    // 0x800066F0: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    func_80006110(rdram, ctx);
        goto after_4;
    // 0x800066F0: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    after_4:
    // 0x800066F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800066F8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x800066FC: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80006704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80006704: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80006708: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000670C: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x80006710: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x80006714: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80006718: sra         $t6, $v0, 16
    ctx->r14 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8000671C: andi        $t7, $t6, 0x1F
    ctx->r15 = ctx->r14 & 0X1F;
    // 0x80006720: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80006724: addu        $a2, $a2, $t8
    ctx->r6 = ADD32(ctx->r6, ctx->r24);
    // 0x80006728: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x8000672C: addiu       $a1, $a1, 0x4BE8
    ctx->r5 = ADD32(ctx->r5, 0X4BE8);
    // 0x80006730: lw          $a2, 0x7290($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7290);
    // 0x80006734: sw          $a3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r7;
    // 0x80006738: jal         0x80007098
    // 0x8000673C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_80007098(rdram, ctx);
        goto after_0;
    // 0x8000673C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80006740: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x80006744: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x80006748: jal         0x80006110
    // 0x8000674C: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    func_80006110(rdram, ctx);
        goto after_1;
    // 0x8000674C: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    after_1:
    // 0x80006750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006754: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80006758: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80006760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80006760: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80006764: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80006768: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x8000676C: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x80006770: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x80006774: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80006778: beq         $v0, $zero, L_800067F0
    if (ctx->r2 == 0) {
        // 0x8000677C: addiu       $a1, $a1, 0x4C18
        ctx->r5 = ADD32(ctx->r5, 0X4C18);
            goto L_800067F0;
    }
    // 0x8000677C: addiu       $a1, $a1, 0x4C18
    ctx->r5 = ADD32(ctx->r5, 0X4C18);
    // 0x80006780: sra         $v1, $v0, 16
    ctx->r3 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80006784: sra         $a0, $v0, 11
    ctx->r4 = S32(SIGNED(ctx->r2) >> 11);
    // 0x80006788: andi        $t6, $v1, 0x1F
    ctx->r14 = ctx->r3 & 0X1F;
    // 0x8000678C: andi        $t7, $a0, 0x1F
    ctx->r15 = ctx->r4 & 0X1F;
    // 0x80006790: beq         $t7, $t6, L_800067BC
    if (ctx->r15 == ctx->r14) {
        // 0x80006794: addiu       $a0, $sp, 0x20
        ctx->r4 = ADD32(ctx->r29, 0X20);
            goto L_800067BC;
    }
    // 0x80006794: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80006798: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x8000679C: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x800067A0: addiu       $a1, $a1, 0x4BF4
    ctx->r5 = ADD32(ctx->r5, 0X4BF4);
    // 0x800067A4: lw          $a2, 0x8($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X8);
    // 0x800067A8: sw          $a3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r7;
    // 0x800067AC: jal         0x80007098
    // 0x800067B0: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    func_80007098(rdram, ctx);
        goto after_0;
    // 0x800067B0: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x800067B4: b           L_800067D8
    // 0x800067B8: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
        goto L_800067D8;
    // 0x800067B8: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
L_800067BC:
    // 0x800067BC: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x800067C0: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x800067C4: addiu       $a1, $a1, 0x4C08
    ctx->r5 = ADD32(ctx->r5, 0X4C08);
    // 0x800067C8: lw          $a2, 0x8($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X8);
    // 0x800067CC: jal         0x80007098
    // 0x800067D0: sw          $a3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r7;
    func_80007098(rdram, ctx);
        goto after_1;
    // 0x800067D0: sw          $a3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r7;
    after_1:
    // 0x800067D4: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
L_800067D8:
    // 0x800067D8: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x800067DC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800067E0: jal         0x80006110
    // 0x800067E4: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_80006110(rdram, ctx);
        goto after_2;
    // 0x800067E4: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_2:
    // 0x800067E8: b           L_800067FC
    // 0x800067EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800067FC;
    // 0x800067EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800067F0:
    // 0x800067F0: jal         0x80007098
    // 0x800067F4: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    func_80007098(rdram, ctx);
        goto after_3;
    // 0x800067F4: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    after_3:
    // 0x800067F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800067FC:
    // 0x800067FC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80006800: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80006808(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80006808: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8000680C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80006810: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80006814: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x80006818: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8000681C: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80006820: sra         $v1, $v0, 16
    ctx->r3 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80006824: sra         $a2, $v0, 11
    ctx->r6 = S32(SIGNED(ctx->r2) >> 11);
    // 0x80006828: andi        $t6, $v1, 0x1F
    ctx->r14 = ctx->r3 & 0X1F;
    // 0x8000682C: andi        $t7, $a2, 0x1F
    ctx->r15 = ctx->r6 & 0X1F;
    // 0x80006830: beq         $t7, $t6, L_8000685C
    if (ctx->r15 == ctx->r14) {
        // 0x80006834: lw          $t9, 0x6C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X6C);
            goto L_8000685C;
    }
    // 0x80006834: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x80006838: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x8000683C: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x80006840: addiu       $a1, $a1, 0x4C1C
    ctx->r5 = ADD32(ctx->r5, 0X4C1C);
    // 0x80006844: lw          $a2, 0x8($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X8);
    // 0x80006848: sw          $a3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r7;
    // 0x8000684C: jal         0x80007098
    // 0x80006850: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    func_80007098(rdram, ctx);
        goto after_0;
    // 0x80006850: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x80006854: b           L_80006874
    // 0x80006858: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
        goto L_80006874;
    // 0x80006858: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
L_8000685C:
    // 0x8000685C: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x80006860: lw          $a2, 0x8($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X8);
    // 0x80006864: sw          $a3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r7;
    // 0x80006868: jal         0x80007098
    // 0x8000686C: addiu       $a1, $a1, 0x4C30
    ctx->r5 = ADD32(ctx->r5, 0X4C30);
    func_80007098(rdram, ctx);
        goto after_1;
    // 0x8000686C: addiu       $a1, $a1, 0x4C30
    ctx->r5 = ADD32(ctx->r5, 0X4C30);
    after_1:
    // 0x80006870: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
L_80006874:
    // 0x80006874: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80006878: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8000687C: jal         0x80006110
    // 0x80006880: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_80006110(rdram, ctx);
        goto after_2;
    // 0x80006880: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_2:
    // 0x80006884: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006888: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8000688C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80006894(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80006894: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80006898: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000689C: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x800068A0: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x800068A4: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x800068A8: sra         $v1, $v0, 21
    ctx->r3 = S32(SIGNED(ctx->r2) >> 21);
    // 0x800068AC: sra         $a2, $v0, 16
    ctx->r6 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800068B0: sra         $a3, $v0, 11
    ctx->r7 = S32(SIGNED(ctx->r2) >> 11);
    // 0x800068B4: andi        $t7, $v1, 0x1F
    ctx->r15 = ctx->r3 & 0X1F;
    // 0x800068B8: andi        $t8, $a2, 0x1F
    ctx->r24 = ctx->r6 & 0X1F;
    // 0x800068BC: andi        $t9, $a3, 0x1F
    ctx->r25 = ctx->r7 & 0X1F;
    // 0x800068C0: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x800068C4: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800068C8: bne         $t7, $zero, L_80006904
    if (ctx->r15 != 0) {
        // 0x800068CC: or          $a3, $t9, $zero
        ctx->r7 = ctx->r25 | 0;
            goto L_80006904;
    }
    // 0x800068CC: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x800068D0: bne         $t8, $zero, L_800068F0
    if (ctx->r24 != 0) {
        // 0x800068D4: addiu       $a0, $sp, 0x1C
        ctx->r4 = ADD32(ctx->r29, 0X1C);
            goto L_800068F0;
    }
    // 0x800068D4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800068D8: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x800068DC: addiu       $a1, $a1, 0x4C40
    ctx->r5 = ADD32(ctx->r5, 0X4C40);
    // 0x800068E0: jal         0x80007098
    // 0x800068E4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_80007098(rdram, ctx);
        goto after_0;
    // 0x800068E4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x800068E8: b           L_80006958
    // 0x800068EC: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
        goto L_80006958;
    // 0x800068EC: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
L_800068F0:
    // 0x800068F0: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x800068F4: jal         0x80007098
    // 0x800068F8: addiu       $a1, $a1, 0x4C48
    ctx->r5 = ADD32(ctx->r5, 0X4C48);
    func_80007098(rdram, ctx);
        goto after_1;
    // 0x800068F8: addiu       $a1, $a1, 0x4C48
    ctx->r5 = ADD32(ctx->r5, 0X4C48);
    after_1:
    // 0x800068FC: b           L_80006958
    // 0x80006900: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
        goto L_80006958;
    // 0x80006900: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
L_80006904:
    // 0x80006904: bne         $a2, $zero, L_80006920
    if (ctx->r6 != 0) {
        // 0x80006908: addiu       $a0, $sp, 0x1C
        ctx->r4 = ADD32(ctx->r29, 0X1C);
            goto L_80006920;
    }
    // 0x80006908: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8000690C: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x80006910: jal         0x80007098
    // 0x80006914: addiu       $a1, $a1, 0x4C54
    ctx->r5 = ADD32(ctx->r5, 0X4C54);
    func_80007098(rdram, ctx);
        goto after_2;
    // 0x80006914: addiu       $a1, $a1, 0x4C54
    ctx->r5 = ADD32(ctx->r5, 0X4C54);
    after_2:
    // 0x80006918: b           L_80006958
    // 0x8000691C: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
        goto L_80006958;
    // 0x8000691C: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
L_80006920:
    // 0x80006920: beq         $a3, $v1, L_80006948
    if (ctx->r7 == ctx->r3) {
        // 0x80006924: addiu       $a0, $sp, 0x1C
        ctx->r4 = ADD32(ctx->r29, 0X1C);
            goto L_80006948;
    }
    // 0x80006924: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80006928: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x8000692C: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x80006930: addiu       $a1, $a1, 0x4C60
    ctx->r5 = ADD32(ctx->r5, 0X4C60);
    // 0x80006934: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80006938: jal         0x80007098
    // 0x8000693C: lw          $a2, 0x8($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X8);
    func_80007098(rdram, ctx);
        goto after_3;
    // 0x8000693C: lw          $a2, 0x8($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X8);
    after_3:
    // 0x80006940: b           L_80006958
    // 0x80006944: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
        goto L_80006958;
    // 0x80006944: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
L_80006948:
    // 0x80006948: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x8000694C: jal         0x80007098
    // 0x80006950: addiu       $a1, $a1, 0x4C74
    ctx->r5 = ADD32(ctx->r5, 0X4C74);
    func_80007098(rdram, ctx);
        goto after_4;
    // 0x80006950: addiu       $a1, $a1, 0x4C74
    ctx->r5 = ADD32(ctx->r5, 0X4C74);
    after_4:
    // 0x80006954: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
L_80006958:
    // 0x80006958: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x8000695C: jal         0x80006110
    // 0x80006960: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    func_80006110(rdram, ctx);
        goto after_5;
    // 0x80006960: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    after_5:
    // 0x80006964: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006968: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8000696C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80006974(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80006974: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80006978: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000697C: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x80006980: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80006984: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80006988: sra         $t6, $v0, 11
    ctx->r14 = S32(SIGNED(ctx->r2) >> 11);
    // 0x8000698C: andi        $t7, $t6, 0x1F
    ctx->r15 = ctx->r14 & 0X1F;
    // 0x80006990: bne         $t7, $at, L_800069B0
    if (ctx->r15 != ctx->r1) {
        // 0x80006994: lui         $a2, 0x8007
        ctx->r6 = S32(0X8007 << 16);
            goto L_800069B0;
    }
    // 0x80006994: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80006998: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x8000699C: addiu       $a2, $a2, 0x4C80
    ctx->r6 = ADD32(ctx->r6, 0X4C80);
    // 0x800069A0: jal         0x80006110
    // 0x800069A4: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_80006110(rdram, ctx);
        goto after_0;
    // 0x800069A4: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x800069A8: b           L_800069C0
    // 0x800069AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800069C0;
    // 0x800069AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800069B0:
    // 0x800069B0: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800069B4: jal         0x80006110
    // 0x800069B8: addiu       $a2, $a2, 0x4C8C
    ctx->r6 = ADD32(ctx->r6, 0X4C8C);
    func_80006110(rdram, ctx);
        goto after_1;
    // 0x800069B8: addiu       $a2, $a2, 0x4C8C
    ctx->r6 = ADD32(ctx->r6, 0X4C8C);
    after_1:
    // 0x800069BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800069C0:
    // 0x800069C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800069C4: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800069CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800069CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800069D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800069D4: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x800069D8: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x800069DC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800069E0: sra         $t6, $v0, 21
    ctx->r14 = S32(SIGNED(ctx->r2) >> 21);
    // 0x800069E4: andi        $t7, $t6, 0x1F
    ctx->r15 = ctx->r14 & 0X1F;
    // 0x800069E8: bne         $t7, $at, L_80006A08
    if (ctx->r15 != ctx->r1) {
        // 0x800069EC: lui         $a2, 0x8007
        ctx->r6 = S32(0X8007 << 16);
            goto L_80006A08;
    }
    // 0x800069EC: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x800069F0: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x800069F4: addiu       $a2, $a2, 0x4CA0
    ctx->r6 = ADD32(ctx->r6, 0X4CA0);
    // 0x800069F8: jal         0x80006110
    // 0x800069FC: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_80006110(rdram, ctx);
        goto after_0;
    // 0x800069FC: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x80006A00: b           L_80006A18
    // 0x80006A04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80006A18;
    // 0x80006A04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80006A08:
    // 0x80006A08: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x80006A0C: jal         0x80006110
    // 0x80006A10: addiu       $a2, $a2, 0x4CA4
    ctx->r6 = ADD32(ctx->r6, 0X4CA4);
    func_80006110(rdram, ctx);
        goto after_1;
    // 0x80006A10: addiu       $a2, $a2, 0x4CA4
    ctx->r6 = ADD32(ctx->r6, 0X4CA4);
    after_1:
    // 0x80006A14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80006A18:
    // 0x80006A18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80006A1C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80006A24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80006A24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80006A28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80006A2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80006A30: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80006A34: lw          $t1, 0x8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X8);
    // 0x80006A38: addiu       $a2, $a2, -0x7DE0
    ctx->r6 = ADD32(ctx->r6, -0X7DE0);
    // 0x80006A3C: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x80006A40: addiu       $a3, $zero, 0x3F
    ctx->r7 = ADD32(0, 0X3F);
    // 0x80006A44: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
L_80006A48:
    // 0x80006A48: srav        $t7, $t1, $a1
    ctx->r15 = S32(SIGNED(ctx->r9) >> (ctx->r5 & 31));
    // 0x80006A4C: and         $v0, $t7, $a3
    ctx->r2 = ctx->r15 & ctx->r7;
    // 0x80006A50: multu       $v0, $a0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80006A54: mflo        $t0
    ctx->r8 = lo;
    // 0x80006A58: addu        $v1, $a2, $t0
    ctx->r3 = ADD32(ctx->r6, ctx->r8);
    // 0x80006A5C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80006A60: bnel        $t8, $zero, L_80006A80
    if (ctx->r24 != 0) {
        // 0x80006A64: lw          $v0, 0x4($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X4);
            goto L_80006A80;
    }
    goto skip_0;
    // 0x80006A64: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    skip_0:
    // 0x80006A68: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x80006A6C: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    // 0x80006A70: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    // 0x80006A74: b           L_80006A48
    // 0x80006A78: lbu         $a3, 0x1($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X1);
        goto L_80006A48;
    // 0x80006A78: lbu         $a3, 0x1($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X1);
    // 0x80006A7C: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
L_80006A80:
    // 0x80006A80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80006A84: addu        $a1, $t0, $a2
    ctx->r5 = ADD32(ctx->r8, ctx->r6);
    // 0x80006A88: jalr        $v0
    // 0x80006A8C: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80006A8C: nop

    after_0:
    // 0x80006A90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006A94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80006A98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80006A9C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80006AB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80006AB0: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x80006AB4: bltz        $a1, L_80006ACC
    if (SIGNED(ctx->r5) < 0) {
        // 0x80006AB8: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80006ACC;
    }
    // 0x80006AB8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80006ABC:
    // 0x80006ABC: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x80006AC0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80006AC4: bgez        $a1, L_80006ABC
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80006AC8: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80006ABC;
    }
    // 0x80006AC8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80006ACC:
    // 0x80006ACC: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80006AD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80006AD4: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80006AD8: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
    // 0x80006ADC: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
L_80006AE0:
    // 0x80006AE0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80006AE4: beql        $v0, $v1, L_80006AE0
    if (ctx->r2 == ctx->r3) {
        // 0x80006AE8: lbu         $v0, 0x0($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X0);
            goto L_80006AE0;
    }
    goto skip_0;
    // 0x80006AE8: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    skip_0:
    // 0x80006AEC: beql        $v0, $a1, L_80006AE0
    if (ctx->r2 == ctx->r5) {
        // 0x80006AF0: lbu         $v0, 0x0($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X0);
            goto L_80006AE0;
    }
    goto skip_1;
    // 0x80006AF0: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x80006AF4: jr          $ra
    // 0x80006AF8: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    TRACE_RETURN()
    return;
    // 0x80006AF8: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
;}
RECOMP_FUNC void func_80006AFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80006AFC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80006B00: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80006B04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80006B08: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80006B0C: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80006B10: jal         0x80004364
    // 0x80006B14: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x80006B14: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x80006B18: beq         $v0, $zero, L_80006B30
    if (ctx->r2 == 0) {
        // 0x80006B1C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80006B30;
    }
    // 0x80006B1C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80006B20: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80006B24: jal         0x80006AB0
    // 0x80006B28: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80006AB0(rdram, ctx);
        goto after_1;
    // 0x80006B28: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80006B2C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_80006B30:
    // 0x80006B30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006B34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80006B38: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80006B3C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80006B44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80006B44: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80006B48: beq         $a0, $zero, L_80006B90
    if (ctx->r4 == 0) {
        // 0x80006B4C: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80006B90;
    }
    // 0x80006B4C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
L_80006B50:
    // 0x80006B50: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80006B54: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80006B58: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80006B5C: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80006B60: lbu         $a1, 0x0($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X0);
L_80006B64:
    // 0x80006B64: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80006B68: bne         $a1, $t0, L_80006B7C
    if (ctx->r5 != ctx->r8) {
        // 0x80006B6C: nop
    
            goto L_80006B7C;
    }
    // 0x80006B6C: nop

    // 0x80006B70: sb          $zero, 0x0($a3)
    MEM_B(0X0, ctx->r7) = 0;
    // 0x80006B74: jr          $ra
    // 0x80006B78: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    TRACE_RETURN()
    return;
    // 0x80006B78: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
L_80006B7C:
    // 0x80006B7C: bnel        $a1, $zero, L_80006B64
    if (ctx->r5 != 0) {
        // 0x80006B80: lbu         $a1, 0x0($a0)
        ctx->r5 = MEM_BU(ctx->r4, 0X0);
            goto L_80006B64;
    }
    goto skip_0;
    // 0x80006B80: lbu         $a1, 0x0($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X0);
    skip_0:
    // 0x80006B84: sb          $v0, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r2;
    // 0x80006B88: b           L_80006B50
    // 0x80006B8C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
        goto L_80006B50;
    // 0x80006B8C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_80006B90:
    // 0x80006B90: lbu         $t0, 0x0($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X0);
L_80006B94:
    // 0x80006B94: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80006B98: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80006B9C: lbu         $a1, 0x0($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X0);
L_80006BA0:
    // 0x80006BA0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80006BA4: bne         $a1, $t0, L_80006BB4
    if (ctx->r5 != ctx->r8) {
        // 0x80006BA8: nop
    
            goto L_80006BB4;
    }
    // 0x80006BA8: nop

    // 0x80006BAC: jr          $ra
    // 0x80006BB0: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    TRACE_RETURN()
    return;
    // 0x80006BB0: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
L_80006BB4:
    // 0x80006BB4: bnel        $a1, $zero, L_80006BA0
    if (ctx->r5 != 0) {
        // 0x80006BB8: lbu         $a1, 0x0($a0)
        ctx->r5 = MEM_BU(ctx->r4, 0X0);
            goto L_80006BA0;
    }
    goto skip_1;
    // 0x80006BB8: lbu         $a1, 0x0($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x80006BBC: b           L_80006B94
    // 0x80006BC0: lbu         $t0, 0x0($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X0);
        goto L_80006B94;
    // 0x80006BC0: lbu         $t0, 0x0($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X0);
    // 0x80006BC4: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80006BCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80006BCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80006BD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80006BD4: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80006BD8: jal         0x80006B44
    // 0x80006BDC: addiu       $a2, $a2, 0x5DB0
    ctx->r6 = ADD32(ctx->r6, 0X5DB0);
    func_80006B44(rdram, ctx);
        goto after_0;
    // 0x80006BDC: addiu       $a2, $a2, 0x5DB0
    ctx->r6 = ADD32(ctx->r6, 0X5DB0);
    after_0:
    // 0x80006BE0: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80006BE4: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80006BE8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80006BEC: bne         $t6, $at, L_80006BF8
    if (ctx->r14 != ctx->r1) {
        // 0x80006BF0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80006BF8;
    }
    // 0x80006BF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006BF4: addiu       $a1, $v0, 0x1
    ctx->r5 = ADD32(ctx->r2, 0X1);
L_80006BF8:
    // 0x80006BF8: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x80006BFC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80006C00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80006C04: bnel        $v0, $at, L_80006C18
    if (ctx->r2 != ctx->r1) {
        // 0x80006C08: addiu       $at, $zero, 0x1A
        ctx->r1 = ADD32(0, 0X1A);
            goto L_80006C18;
    }
    goto skip_0;
    // 0x80006C08: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    skip_0:
    // 0x80006C0C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80006C10: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x80006C14: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
L_80006C18:
    // 0x80006C18: bne         $v0, $at, L_80006C24
    if (ctx->r2 != ctx->r1) {
        // 0x80006C1C: nop
    
            goto L_80006C24;
    }
    // 0x80006C1C: nop

    // 0x80006C20: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80006C24:
    // 0x80006C24: jr          $ra
    // 0x80006C28: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    TRACE_RETURN()
    return;
    // 0x80006C28: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
;}
RECOMP_FUNC void func_80006C2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80006C2C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80006C30: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80006C34: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80006C38: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80006C3C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80006C40: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
L_80006C44:
    // 0x80006C44: srlv        $a2, $a1, $v0
    ctx->r6 = S32(U32(ctx->r5) >> (ctx->r2 & 31));
    // 0x80006C48: andi        $a0, $a2, 0xF
    ctx->r4 = ctx->r6 & 0XF;
    // 0x80006C4C: beq         $a0, $zero, L_80006C58
    if (ctx->r4 == 0) {
        // 0x80006C50: addu        $t7, $s0, $a0
        ctx->r15 = ADD32(ctx->r16, ctx->r4);
            goto L_80006C58;
    }
    // 0x80006C50: addu        $t7, $s0, $a0
    ctx->r15 = ADD32(ctx->r16, ctx->r4);
    // 0x80006C54: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_80006C58:
    // 0x80006C58: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80006C5C: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80006C60: sb          $t8, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r24;
    // 0x80006C64: bgez        $v0, L_80006C44
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80006C68: subu        $a3, $a3, $v1
        ctx->r7 = SUB32(ctx->r7, ctx->r3);
            goto L_80006C44;
    }
    // 0x80006C68: subu        $a3, $a3, $v1
    ctx->r7 = SUB32(ctx->r7, ctx->r3);
    // 0x80006C6C: addu        $a0, $a3, $v1
    ctx->r4 = ADD32(ctx->r7, ctx->r3);
    // 0x80006C70: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    // 0x80006C74: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x80006C78: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80006C7C: jr          $ra
    // 0x80006C80: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    TRACE_RETURN()
    return;
    // 0x80006C80: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
;}
RECOMP_FUNC void func_80006C84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80006C84: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x80006C88: lw          $v0, -0x7AB8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7AB8);
    // 0x80006C8C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80006C90: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80006C94: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80006C98: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80006C9C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80006CA0: beq         $v0, $zero, L_80006CF4
    if (ctx->r2 == 0) {
        // 0x80006CA4: addiu       $a2, $a2, -0x7AB4
        ctx->r6 = ADD32(ctx->r6, -0X7AB4);
            goto L_80006CF4;
    }
    // 0x80006CA4: addiu       $a2, $a2, -0x7AB4
    ctx->r6 = ADD32(ctx->r6, -0X7AB4);
L_80006CA8:
    // 0x80006CA8: divu        $zero, $a1, $v0
    lo = S32(U32(ctx->r5) / U32(ctx->r2)); hi = S32(U32(ctx->r5) % U32(ctx->r2));
    // 0x80006CAC: mflo        $a3
    ctx->r7 = lo;
    // 0x80006CB0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80006CB4: bne         $v0, $zero, L_80006CC0
    if (ctx->r2 != 0) {
        // 0x80006CB8: nop
    
            goto L_80006CC0;
    }
    // 0x80006CB8: nop

    // 0x80006CBC: break       7
    do_break(2147511484);
L_80006CC0:
    // 0x80006CC0: beq         $a3, $zero, L_80006CCC
    if (ctx->r7 == 0) {
        // 0x80006CC4: nop
    
            goto L_80006CCC;
    }
    // 0x80006CC4: nop

    // 0x80006CC8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_80006CCC:
    // 0x80006CCC: multu       $a0, $v0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80006CD0: addiu       $t6, $a0, 0x30
    ctx->r14 = ADD32(ctx->r4, 0X30);
    // 0x80006CD4: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x80006CD8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80006CDC: subu        $s0, $s0, $v1
    ctx->r16 = SUB32(ctx->r16, ctx->r3);
    // 0x80006CE0: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80006CE4: mflo        $t7
    ctx->r15 = lo;
    // 0x80006CE8: subu        $a1, $a1, $t7
    ctx->r5 = SUB32(ctx->r5, ctx->r15);
    // 0x80006CEC: bne         $v0, $zero, L_80006CA8
    if (ctx->r2 != 0) {
        // 0x80006CF0: nop
    
            goto L_80006CA8;
    }
    // 0x80006CF0: nop

L_80006CF4:
    // 0x80006CF4: addu        $a0, $s0, $v1
    ctx->r4 = ADD32(ctx->r16, ctx->r3);
    // 0x80006CF8: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    // 0x80006CFC: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x80006D00: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80006D04: jr          $ra
    // 0x80006D08: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    TRACE_RETURN()
    return;
    // 0x80006D08: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
;}
RECOMP_FUNC void func_80006D0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80006D0C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80006D10: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80006D14: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
L_80006D18:
    // 0x80006D18: srlv        $a0, $a1, $v0
    ctx->r4 = S32(U32(ctx->r5) >> (ctx->r2 & 31));
    // 0x80006D1C: andi        $t6, $a0, 0x1
    ctx->r14 = ctx->r4 & 0X1;
    // 0x80006D20: addiu       $t7, $t6, 0x30
    ctx->r15 = ADD32(ctx->r14, 0X30);
    // 0x80006D24: or          $v1, $v1, $t6
    ctx->r3 = ctx->r3 | ctx->r14;
    // 0x80006D28: sb          $t7, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r15;
    // 0x80006D2C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80006D30: bgez        $v0, L_80006D18
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80006D34: addu        $a2, $a2, $v1
        ctx->r6 = ADD32(ctx->r6, ctx->r3);
            goto L_80006D18;
    }
    // 0x80006D34: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x80006D38: subu        $a0, $a2, $v1
    ctx->r4 = SUB32(ctx->r6, ctx->r3);
    // 0x80006D3C: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80006D40: jr          $ra
    // 0x80006D44: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    TRACE_RETURN()
    return;
    // 0x80006D44: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
;}
RECOMP_FUNC void func_80006D48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80006D48: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80006D4C: beq         $a1, $zero, L_80006D68
    if (ctx->r5 == 0) {
        // 0x80006D50: addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
            goto L_80006D68;
    }
    // 0x80006D50: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
L_80006D54:
    // 0x80006D54: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80006D58: sb          $a2, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r6;
    // 0x80006D5C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80006D60: bne         $a1, $zero, L_80006D54
    if (ctx->r5 != 0) {
        // 0x80006D64: addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
            goto L_80006D54;
    }
    // 0x80006D64: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
L_80006D68:
    // 0x80006D68: jr          $ra
    // 0x80006D6C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    TRACE_RETURN()
    return;
    // 0x80006D6C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void func_80006D70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80006D70: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x80006D74: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80006D78: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80006D7C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80006D80: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80006D84: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80006D88: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80006D8C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80006D90: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80006D94: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80006D98: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80006D9C: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x80006DA0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80006DA4: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x80006DA8: beq         $v0, $zero, L_80007060
    if (ctx->r2 == 0) {
        // 0x80006DAC: addiu       $s0, $a1, 0x1
        ctx->r16 = ADD32(ctx->r5, 0X1);
            goto L_80007060;
    }
    // 0x80006DAC: addiu       $s0, $a1, 0x1
    ctx->r16 = ADD32(ctx->r5, 0X1);
    // 0x80006DB0: addiu       $fp, $zero, 0x30
    ctx->r30 = ADD32(0, 0X30);
    // 0x80006DB4: addiu       $s7, $zero, 0x2D
    ctx->r23 = ADD32(0, 0X2D);
    // 0x80006DB8: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x80006DBC: addiu       $at, $zero, 0x5C
    ctx->r1 = ADD32(0, 0X5C);
L_80006DC0:
    // 0x80006DC0: bnel        $v0, $at, L_80006DEC
    if (ctx->r2 != ctx->r1) {
        // 0x80006DC4: addiu       $at, $zero, 0x25
        ctx->r1 = ADD32(0, 0X25);
            goto L_80006DEC;
    }
    goto skip_0;
    // 0x80006DC4: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    skip_0:
    // 0x80006DC8: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x80006DCC: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x80006DD0: bnel        $v1, $at, L_80006DEC
    if (ctx->r3 != ctx->r1) {
        // 0x80006DD4: addiu       $at, $zero, 0x25
        ctx->r1 = ADD32(0, 0X25);
            goto L_80006DEC;
    }
    goto skip_1;
    // 0x80006DD4: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    skip_1:
    // 0x80006DD8: sb          $v1, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r3;
    // 0x80006DDC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80006DE0: b           L_80007050
    // 0x80006DE4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_80007050;
    // 0x80006DE4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80006DE8: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
L_80006DEC:
    // 0x80006DEC: beq         $v0, $at, L_80006E00
    if (ctx->r2 == ctx->r1) {
        // 0x80006DF0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80006E00;
    }
    // 0x80006DF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80006DF4: sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
    // 0x80006DF8: b           L_80007050
    // 0x80006DFC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_80007050;
    // 0x80006DFC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80006E00:
    // 0x80006E00: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
    // 0x80006E04: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80006E08: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80006E0C: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x80006E10: addiu       $s3, $sp, 0x4C
    ctx->r19 = ADD32(ctx->r29, 0X4C);
L_80006E14:
    // 0x80006E14: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80006E18: bne         $v1, $fp, L_80006E2C
    if (ctx->r3 != ctx->r30) {
        // 0x80006E1C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80006E2C;
    }
    // 0x80006E1C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80006E20: ori         $t6, $s1, 0x1
    ctx->r14 = ctx->r17 | 0X1;
    // 0x80006E24: b           L_80006E38
    // 0x80006E28: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
        goto L_80006E38;
    // 0x80006E28: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
L_80006E2C:
    // 0x80006E2C: bne         $v0, $s7, L_80006E40
    if (ctx->r2 != ctx->r23) {
        // 0x80006E30: ori         $t7, $s1, 0x2
        ctx->r15 = ctx->r17 | 0X2;
            goto L_80006E40;
    }
    // 0x80006E30: ori         $t7, $s1, 0x2
    ctx->r15 = ctx->r17 | 0X2;
    // 0x80006E34: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
L_80006E38:
    // 0x80006E38: b           L_80006E14
    // 0x80006E3C: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
        goto L_80006E14;
    // 0x80006E3C: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
L_80006E40:
    // 0x80006E40: lbu         $v0, -0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, -0X1);
    // 0x80006E44: addiu       $s0, $s0, 0x0
    ctx->r16 = ADD32(ctx->r16, 0X0);
    // 0x80006E48: addiu       $v0, $v0, -0x30
    ctx->r2 = ADD32(ctx->r2, -0X30);
    // 0x80006E4C: sltiu       $at, $v0, 0xA
    ctx->r1 = ctx->r2 < 0XA ? 1 : 0;
    // 0x80006E50: beql        $at, $zero, L_80006E80
    if (ctx->r1 == 0) {
        // 0x80006E54: addiu       $t9, $v0, -0x28
        ctx->r25 = ADD32(ctx->r2, -0X28);
            goto L_80006E80;
    }
    goto skip_2;
    // 0x80006E54: addiu       $t9, $v0, -0x28
    ctx->r25 = ADD32(ctx->r2, -0X28);
    skip_2:
L_80006E58:
    // 0x80006E58: multu       $s4, $t0
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80006E5C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80006E60: mflo        $t8
    ctx->r24 = lo;
    // 0x80006E64: addu        $s4, $t8, $v0
    ctx->r20 = ADD32(ctx->r24, ctx->r2);
    // 0x80006E68: lbu         $v0, -0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, -0X1);
    // 0x80006E6C: addiu       $v0, $v0, -0x30
    ctx->r2 = ADD32(ctx->r2, -0X30);
    // 0x80006E70: sltiu       $at, $v0, 0xA
    ctx->r1 = ctx->r2 < 0XA ? 1 : 0;
    // 0x80006E74: bne         $at, $zero, L_80006E58
    if (ctx->r1 != 0) {
        // 0x80006E78: nop
    
            goto L_80006E58;
    }
    // 0x80006E78: nop

    // 0x80006E7C: addiu       $t9, $v0, -0x28
    ctx->r25 = ADD32(ctx->r2, -0X28);
L_80006E80:
    // 0x80006E80: sltiu       $at, $t9, 0x21
    ctx->r1 = ctx->r25 < 0X21 ? 1 : 0;
    // 0x80006E84: beq         $at, $zero, L_80006F80
    if (ctx->r1 == 0) {
        // 0x80006E88: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80006F80;
    }
    // 0x80006E88: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80006E8C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80006E90: addu        $at, $at, $t9
    gpr jr_addend_80006E98 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80006E94: lw          $t9, 0x5DB4($at)
    ctx->r25 = ADD32(ctx->r1, 0X5DB4);
    // 0x80006E98: jr          $t9
    // 0x80006E9C: nop

    switch (jr_addend_80006E98 >> 2) {
        case 0: goto L_80006EF8; break;
        case 1: goto L_80006F80; break;
        case 2: goto L_80006F80; break;
        case 3: goto L_80006F80; break;
        case 4: goto L_80006F80; break;
        case 5: goto L_80006F80; break;
        case 6: goto L_80006F80; break;
        case 7: goto L_80006F80; break;
        case 8: goto L_80006F80; break;
        case 9: goto L_80006F80; break;
        case 10: goto L_80006F4C; break;
        case 11: goto L_80006F68; break;
        case 12: goto L_80006F1C; break;
        case 13: goto L_80006F80; break;
        case 14: goto L_80006F80; break;
        case 15: goto L_80006F80; break;
        case 16: goto L_80006F80; break;
        case 17: goto L_80006F80; break;
        case 18: goto L_80006F80; break;
        case 19: goto L_80006F80; break;
        case 20: goto L_80006F80; break;
        case 21: goto L_80006F80; break;
        case 22: goto L_80006F80; break;
        case 23: goto L_80006F80; break;
        case 24: goto L_80006F80; break;
        case 25: goto L_80006F80; break;
        case 26: goto L_80006F80; break;
        case 27: goto L_80006EA0; break;
        case 28: goto L_80006F80; break;
        case 29: goto L_80006F80; break;
        case 30: goto L_80006F80; break;
        case 31: goto L_80006F80; break;
        case 32: goto L_80006ED4; break;
        default: switch_error(__func__, 0x80006E98, 0x80075DB4);
    }
    // 0x80006E9C: nop

L_80006EA0:
    // 0x80006EA0: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x80006EA4: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x80006EA8: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80006EAC: or          $s3, $v1, $zero
    ctx->r19 = ctx->r3 | 0;
    // 0x80006EB0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80006EB4: beq         $v0, $zero, L_80006ECC
    if (ctx->r2 == 0) {
        // 0x80006EB8: nop
    
            goto L_80006ECC;
    }
    // 0x80006EB8: nop

    // 0x80006EBC: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
L_80006EC0:
    // 0x80006EC0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80006EC4: bnel        $v0, $zero, L_80006EC0
    if (ctx->r2 != 0) {
        // 0x80006EC8: lbu         $v0, 0x0($v1)
        ctx->r2 = MEM_BU(ctx->r3, 0X0);
            goto L_80006EC0;
    }
    goto skip_3;
    // 0x80006EC8: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    skip_3:
L_80006ECC:
    // 0x80006ECC: b           L_80006F94
    // 0x80006ED0: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
        goto L_80006F94;
    // 0x80006ED0: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
L_80006ED4:
    // 0x80006ED4: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80006ED8: addiu       $a2, $a2, -0x7AE0
    ctx->r6 = ADD32(ctx->r6, -0X7AE0);
    // 0x80006EDC: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80006EE0: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
    // 0x80006EE4: jal         0x80006C2C
    // 0x80006EE8: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    func_80006C2C(rdram, ctx);
        goto after_0;
    // 0x80006EE8: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    after_0:
    // 0x80006EEC: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x80006EF0: b           L_80006F94
    // 0x80006EF4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80006F94;
    // 0x80006EF4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80006EF8:
    // 0x80006EF8: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80006EFC: addiu       $a2, $a2, -0x7ACC
    ctx->r6 = ADD32(ctx->r6, -0X7ACC);
    // 0x80006F00: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80006F04: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
    // 0x80006F08: jal         0x80006C2C
    // 0x80006F0C: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    func_80006C2C(rdram, ctx);
        goto after_1;
    // 0x80006F0C: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    after_1:
    // 0x80006F10: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x80006F14: b           L_80006F94
    // 0x80006F18: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80006F94;
    // 0x80006F18: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80006F1C:
    // 0x80006F1C: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
    // 0x80006F20: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x80006F24: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80006F28: bgez        $a1, L_80006F38
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80006F2C: nop
    
            goto L_80006F38;
    }
    // 0x80006F2C: nop

    // 0x80006F30: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x80006F34: sw          $t1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r9;
L_80006F38:
    // 0x80006F38: jal         0x80006C84
    // 0x80006F3C: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    func_80006C84(rdram, ctx);
        goto after_2;
    // 0x80006F3C: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_2:
    // 0x80006F40: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x80006F44: b           L_80006F94
    // 0x80006F48: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80006F94;
    // 0x80006F48: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80006F4C:
    // 0x80006F4C: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80006F50: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
    // 0x80006F54: jal         0x80006D0C
    // 0x80006F58: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    func_80006D0C(rdram, ctx);
        goto after_3;
    // 0x80006F58: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    after_3:
    // 0x80006F5C: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x80006F60: b           L_80006F94
    // 0x80006F64: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80006F94;
    // 0x80006F64: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80006F68:
    // 0x80006F68: lw          $t2, 0x0($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X0);
    // 0x80006F6C: addiu       $v1, $sp, 0x4D
    ctx->r3 = ADD32(ctx->r29, 0X4D);
    // 0x80006F70: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x80006F74: sb          $zero, 0x4D($sp)
    MEM_B(0X4D, ctx->r29) = 0;
    // 0x80006F78: b           L_80006F94
    // 0x80006F7C: sb          $t2, 0x4C($sp)
    MEM_B(0X4C, ctx->r29) = ctx->r10;
        goto L_80006F94;
    // 0x80006F7C: sb          $t2, 0x4C($sp)
    MEM_B(0X4C, ctx->r29) = ctx->r10;
L_80006F80:
    // 0x80006F80: addiu       $t3, $zero, 0x25
    ctx->r11 = ADD32(0, 0X25);
    // 0x80006F84: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80006F88: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80006F8C: sb          $t3, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r11;
    // 0x80006F90: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80006F94:
    // 0x80006F94: beq         $v1, $zero, L_80007050
    if (ctx->r3 == 0) {
        // 0x80006F98: addiu       $s6, $zero, 0x20
        ctx->r22 = ADD32(0, 0X20);
            goto L_80007050;
    }
    // 0x80006F98: addiu       $s6, $zero, 0x20
    ctx->r22 = ADD32(0, 0X20);
    // 0x80006F9C: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x80006FA0: subu        $t4, $v1, $s3
    ctx->r12 = SUB32(ctx->r3, ctx->r19);
    // 0x80006FA4: subu        $t5, $s4, $t4
    ctx->r13 = SUB32(ctx->r20, ctx->r12);
    // 0x80006FA8: subu        $s4, $t5, $t6
    ctx->r20 = SUB32(ctx->r13, ctx->r14);
    // 0x80006FAC: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    // 0x80006FB0: blez        $s4, L_80006FF8
    if (SIGNED(ctx->r20) <= 0) {
        // 0x80006FB4: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80006FF8;
    }
    // 0x80006FB4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80006FB8: beq         $s1, $zero, L_80006FE0
    if (ctx->r17 == 0) {
        // 0x80006FBC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80006FE0;
    }
    // 0x80006FBC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80006FC0: andi        $t7, $s1, 0x2
    ctx->r15 = ctx->r17 & 0X2;
    // 0x80006FC4: beql        $t7, $zero, L_80006FD8
    if (ctx->r15 == 0) {
        // 0x80006FC8: or          $a3, $s4, $zero
        ctx->r7 = ctx->r20 | 0;
            goto L_80006FD8;
    }
    goto skip_4;
    // 0x80006FC8: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    skip_4:
    // 0x80006FCC: b           L_80006FF8
    // 0x80006FD0: sw          $s4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r20;
        goto L_80006FF8;
    // 0x80006FD0: sw          $s4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r20;
    // 0x80006FD4: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
L_80006FD8:
    // 0x80006FD8: b           L_80006FF8
    // 0x80006FDC: or          $s6, $fp, $zero
    ctx->r22 = ctx->r30 | 0;
        goto L_80006FF8;
    // 0x80006FDC: or          $s6, $fp, $zero
    ctx->r22 = ctx->r30 | 0;
L_80006FE0:
    // 0x80006FE0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80006FE4: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80006FE8: jal         0x80006D48
    // 0x80006FEC: sw          $a3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r7;
    func_80006D48(rdram, ctx);
        goto after_4;
    // 0x80006FEC: sw          $a3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r7;
    after_4:
    // 0x80006FF0: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    // 0x80006FF4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_80006FF8:
    // 0x80006FF8: sb          $s7, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r23;
    // 0x80006FFC: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x80007000: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80007004: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80007008: jal         0x80006D48
    // 0x8000700C: addu        $a0, $s2, $t8
    ctx->r4 = ADD32(ctx->r18, ctx->r24);
    func_80006D48(rdram, ctx);
        goto after_5;
    // 0x8000700C: addu        $a0, $s2, $t8
    ctx->r4 = ADD32(ctx->r18, ctx->r24);
    after_5:
    // 0x80007010: lbu         $v1, 0x0($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X0);
    // 0x80007014: addiu       $s2, $v0, 0x1
    ctx->r18 = ADD32(ctx->r2, 0X1);
    // 0x80007018: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8000701C: beq         $v1, $zero, L_80007038
    if (ctx->r3 == 0) {
        // 0x80007020: sb          $v1, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r3;
            goto L_80007038;
    }
    // 0x80007020: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
L_80007024:
    // 0x80007024: lbu         $v1, 0x0($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X0);
    // 0x80007028: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8000702C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80007030: bne         $v1, $zero, L_80007024
    if (ctx->r3 != 0) {
        // 0x80007034: sb          $v1, -0x1($s2)
        MEM_B(-0X1, ctx->r18) = ctx->r3;
            goto L_80007024;
    }
    // 0x80007034: sb          $v1, -0x1($s2)
    MEM_B(-0X1, ctx->r18) = ctx->r3;
L_80007038:
    // 0x80007038: addiu       $a0, $s2, -0x1
    ctx->r4 = ADD32(ctx->r18, -0X1);
    // 0x8000703C: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x80007040: jal         0x80006D48
    // 0x80007044: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_80006D48(rdram, ctx);
        goto after_6;
    // 0x80007044: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_6:
    // 0x80007048: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x8000704C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_80007050:
    // 0x80007050: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80007054: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80007058: bnel        $v0, $zero, L_80006DC0
    if (ctx->r2 != 0) {
        // 0x8000705C: addiu       $at, $zero, 0x5C
        ctx->r1 = ADD32(0, 0X5C);
            goto L_80006DC0;
    }
    goto skip_5;
    // 0x8000705C: addiu       $at, $zero, 0x5C
    ctx->r1 = ADD32(0, 0X5C);
    skip_5:
L_80007060:
    // 0x80007060: sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
    // 0x80007064: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80007068: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x8000706C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80007070: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80007074: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80007078: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8000707C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80007080: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80007084: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80007088: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000708C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80007090: jr          $ra
    // 0x80007094: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    TRACE_RETURN()
    return;
    // 0x80007094: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_80007098(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80007098: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000709C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800070A0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800070A4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800070A8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800070AC: jal         0x80006D70
    // 0x800070B0: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    func_80006D70(rdram, ctx);
        goto after_0;
    // 0x800070B0: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x800070B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800070B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800070BC: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800070D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800070D0: lui         $t0, 0x8007
    ctx->r8 = S32(0X8007 << 16);
    // 0x800070D4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800070D8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800070DC: addiu       $t0, $t0, -0x7A80
    ctx->r8 = ADD32(ctx->r8, -0X7A80);
    // 0x800070E0: addiu       $a3, $zero, 0x5F
    ctx->r7 = ADD32(0, 0X5F);
L_800070E4:
    // 0x800070E4: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
L_800070E8:
    // 0x800070E8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800070EC: beql        $v0, $a3, L_800070E8
    if (ctx->r2 == ctx->r7) {
        // 0x800070F0: lbu         $v0, 0x0($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X0);
            goto L_800070E8;
    }
    goto skip_0;
    // 0x800070F0: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    skip_0:
    // 0x800070F4: addu        $t6, $t0, $v0
    ctx->r14 = ADD32(ctx->r8, ctx->r2);
    // 0x800070F8: lb          $a1, 0x0($t6)
    ctx->r5 = MEM_B(ctx->r14, 0X0);
    // 0x800070FC: sll         $t7, $v1, 4
    ctx->r15 = S32(ctx->r3 << 4);
    // 0x80007100: bltz        $a1, L_80007110
    if (SIGNED(ctx->r5) < 0) {
        // 0x80007104: nop
    
            goto L_80007110;
    }
    // 0x80007104: nop

    // 0x80007108: b           L_800070E4
    // 0x8000710C: addu        $v1, $t7, $a1
    ctx->r3 = ADD32(ctx->r15, ctx->r5);
        goto L_800070E4;
    // 0x8000710C: addu        $v1, $t7, $a1
    ctx->r3 = ADD32(ctx->r15, ctx->r5);
L_80007110:
    // 0x80007110: beq         $a2, $zero, L_8000711C
    if (ctx->r6 == 0) {
        // 0x80007114: addiu       $t8, $a0, -0x1
        ctx->r24 = ADD32(ctx->r4, -0X1);
            goto L_8000711C;
    }
    // 0x80007114: addiu       $t8, $a0, -0x1
    ctx->r24 = ADD32(ctx->r4, -0X1);
    // 0x80007118: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
L_8000711C:
    // 0x8000711C: jr          $ra
    // 0x80007120: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    TRACE_RETURN()
    return;
    // 0x80007120: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80007124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80007124: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80007128: addiu       $a2, $zero, 0x5F
    ctx->r6 = ADD32(0, 0X5F);
L_8000712C:
    // 0x8000712C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
L_80007130:
    // 0x80007130: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80007134: beql        $v0, $a2, L_80007130
    if (ctx->r2 == ctx->r6) {
        // 0x80007138: lbu         $v0, 0x0($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X0);
            goto L_80007130;
    }
    goto skip_0;
    // 0x80007138: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    skip_0:
    // 0x8000713C: addiu       $v0, $v0, -0x30
    ctx->r2 = ADD32(ctx->r2, -0X30);
    // 0x80007140: sltiu       $at, $v0, 0x2
    ctx->r1 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80007144: beq         $at, $zero, L_80007154
    if (ctx->r1 == 0) {
        // 0x80007148: sll         $t6, $v1, 1
        ctx->r14 = S32(ctx->r3 << 1);
            goto L_80007154;
    }
    // 0x80007148: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x8000714C: b           L_8000712C
    // 0x80007150: addu        $v1, $t6, $v0
    ctx->r3 = ADD32(ctx->r14, ctx->r2);
        goto L_8000712C;
    // 0x80007150: addu        $v1, $t6, $v0
    ctx->r3 = ADD32(ctx->r14, ctx->r2);
L_80007154:
    // 0x80007154: beq         $a1, $zero, L_80007160
    if (ctx->r5 == 0) {
        // 0x80007158: addiu       $t7, $a0, -0x1
        ctx->r15 = ADD32(ctx->r4, -0X1);
            goto L_80007160;
    }
    // 0x80007158: addiu       $t7, $a0, -0x1
    ctx->r15 = ADD32(ctx->r4, -0X1);
    // 0x8000715C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
L_80007160:
    // 0x80007160: jr          $ra
    // 0x80007164: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    TRACE_RETURN()
    return;
    // 0x80007164: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80007168(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80007168: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000716C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x80007170: addiu       $a2, $zero, 0x5F
    ctx->r6 = ADD32(0, 0X5F);
    // 0x80007174: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
L_80007178:
    // 0x80007178: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8000717C: beql        $v0, $a2, L_80007178
    if (ctx->r2 == ctx->r6) {
        // 0x80007180: lbu         $v0, 0x0($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X0);
            goto L_80007178;
    }
    goto skip_0;
    // 0x80007180: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    skip_0:
    // 0x80007184: addiu       $v0, $v0, -0x30
    ctx->r2 = ADD32(ctx->r2, -0X30);
    // 0x80007188: sltiu       $at, $v0, 0xA
    ctx->r1 = ctx->r2 < 0XA ? 1 : 0;
    // 0x8000718C: beq         $at, $zero, L_800071A8
    if (ctx->r1 == 0) {
        // 0x80007190: nop
    
            goto L_800071A8;
    }
    // 0x80007190: nop

    // 0x80007194: multu       $v1, $a3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80007198: mflo        $t6
    ctx->r14 = lo;
    // 0x8000719C: addu        $v1, $t6, $v0
    ctx->r3 = ADD32(ctx->r14, ctx->r2);
    // 0x800071A0: b           L_80007178
    // 0x800071A4: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
        goto L_80007178;
    // 0x800071A4: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
L_800071A8:
    // 0x800071A8: beq         $a1, $zero, L_800071B4
    if (ctx->r5 == 0) {
        // 0x800071AC: addiu       $t7, $a0, -0x1
        ctx->r15 = ADD32(ctx->r4, -0X1);
            goto L_800071B4;
    }
    // 0x800071AC: addiu       $t7, $a0, -0x1
    ctx->r15 = ADD32(ctx->r4, -0X1);
    // 0x800071B0: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
L_800071B4:
    // 0x800071B4: jr          $ra
    // 0x800071B8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    TRACE_RETURN()
    return;
    // 0x800071B8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_800071BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800071BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800071C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800071C4: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x800071C8: addiu       $at, $zero, 0x24
    ctx->r1 = ADD32(0, 0X24);
    // 0x800071CC: addiu       $a2, $a0, 0x1
    ctx->r6 = ADD32(ctx->r4, 0X1);
    // 0x800071D0: bnel        $v1, $at, L_800071EC
    if (ctx->r3 != ctx->r1) {
        // 0x800071D4: addiu       $at, $zero, 0x30
        ctx->r1 = ADD32(0, 0X30);
            goto L_800071EC;
    }
    goto skip_0;
    // 0x800071D4: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    skip_0:
    // 0x800071D8: jal         0x800070D0
    // 0x800071DC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800070D0(rdram, ctx);
        goto after_0;
    // 0x800071DC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x800071E0: b           L_8000723C
    // 0x800071E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000723C;
    // 0x800071E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800071E8: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
L_800071EC:
    // 0x800071EC: bnel        $v1, $at, L_80007218
    if (ctx->r3 != ctx->r1) {
        // 0x800071F0: addiu       $at, $zero, 0x25
        ctx->r1 = ADD32(0, 0X25);
            goto L_80007218;
    }
    goto skip_1;
    // 0x800071F0: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    skip_1:
    // 0x800071F4: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    // 0x800071F8: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x800071FC: bnel        $t6, $at, L_80007218
    if (ctx->r14 != ctx->r1) {
        // 0x80007200: addiu       $at, $zero, 0x25
        ctx->r1 = ADD32(0, 0X25);
            goto L_80007218;
    }
    goto skip_2;
    // 0x80007200: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    skip_2:
    // 0x80007204: jal         0x800070D0
    // 0x80007208: addiu       $a0, $a2, 0x1
    ctx->r4 = ADD32(ctx->r6, 0X1);
    func_800070D0(rdram, ctx);
        goto after_1;
    // 0x80007208: addiu       $a0, $a2, 0x1
    ctx->r4 = ADD32(ctx->r6, 0X1);
    after_1:
    // 0x8000720C: b           L_8000723C
    // 0x80007210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000723C;
    // 0x80007210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80007214: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
L_80007218:
    // 0x80007218: bne         $v1, $at, L_80007230
    if (ctx->r3 != ctx->r1) {
        // 0x8000721C: nop
    
            goto L_80007230;
    }
    // 0x8000721C: nop

    // 0x80007220: jal         0x80007124
    // 0x80007224: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80007124(rdram, ctx);
        goto after_2;
    // 0x80007224: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x80007228: b           L_8000723C
    // 0x8000722C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000723C;
    // 0x8000722C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80007230:
    // 0x80007230: jal         0x80007168
    // 0x80007234: addiu       $a0, $a2, -0x1
    ctx->r4 = ADD32(ctx->r6, -0X1);
    func_80007168(rdram, ctx);
        goto after_3;
    // 0x80007234: addiu       $a0, $a2, -0x1
    ctx->r4 = ADD32(ctx->r6, -0X1);
    after_3:
    // 0x80007238: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000723C:
    // 0x8000723C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80007240: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80007248(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80007248: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000724C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80007250: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80007254: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80007258: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8000725C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80007260: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80007264: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80007268: jal         0x800071BC
    // 0x8000726C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_800071BC(rdram, ctx);
        goto after_0;
    // 0x8000726C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_0:
    // 0x80007270: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80007274: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80007278: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8000727C: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80007280: beql        $t6, $t7, L_80007294
    if (ctx->r14 == ctx->r15) {
        // 0x80007284: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80007294;
    }
    goto skip_0;
    // 0x80007284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80007288: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x8000728C: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80007290: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80007294:
    // 0x80007294: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80007298: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8000729C: jr          $ra
    // 0x800072A0: nop

    TRACE_RETURN()
    return;
    // 0x800072A0: nop

    // 0x800072A4: nop

    // 0x800072A8: nop

    // 0x800072AC: nop

    // 0x800072B0: addiu       $t6, $a1, -0x18
    ctx->r14 = ADD32(ctx->r5, -0X18);
    // 0x800072B4: divu        $zero, $t6, $a2
    lo = S32(U32(ctx->r14) / U32(ctx->r6)); hi = S32(U32(ctx->r14) % U32(ctx->r6));
    // 0x800072B8: mflo        $t7
    ctx->r15 = lo;
    // 0x800072BC: addiu       $v1, $a0, 0x18
    ctx->r3 = ADD32(ctx->r4, 0X18);
    // 0x800072C0: sw          $a2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r6;
    // 0x800072C4: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800072C8: sw          $v1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r3;
    // 0x800072CC: bne         $a2, $zero, L_800072D8
    if (ctx->r6 != 0) {
        // 0x800072D0: nop
    
            goto L_800072D8;
    }
    // 0x800072D0: nop

    // 0x800072D4: break       7
    do_break(2147513044);
L_800072D8:
    // 0x800072D8: sw          $v1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r3;
    // 0x800072DC: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x800072E0: mflo        $v0
    ctx->r2 = lo;
    // 0x800072E4: addu        $a3, $v1, $v0
    ctx->r7 = ADD32(ctx->r3, ctx->r2);
    // 0x800072E8: sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
    // 0x800072EC: jr          $ra
    // 0x800072F0: sw          $a3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r7;
    TRACE_RETURN()
    return;
    // 0x800072F0: sw          $a3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r7;
;}
RECOMP_FUNC void func_800072F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800072F4: lw          $v1, 0xC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XC);
    // 0x800072F8: lw          $a2, 0x14($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X14);
    // 0x800072FC: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80007300: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x80007304: addu        $v0, $v1, $a2
    ctx->r2 = ADD32(ctx->r3, ctx->r6);
    // 0x80007308: sltu        $at, $v0, $t6
    ctx->r1 = ctx->r2 < ctx->r14 ? 1 : 0;
    // 0x8000730C: bne         $at, $zero, L_80007318
    if (ctx->r1 != 0) {
        // 0x80007310: or          $t0, $a2, $zero
        ctx->r8 = ctx->r6 | 0;
            goto L_80007318;
    }
    // 0x80007310: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x80007314: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_80007318:
    // 0x80007318: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8000731C: andi        $t8, $a2, 0x3
    ctx->r24 = ctx->r6 & 0X3;
    // 0x80007320: bne         $v0, $t7, L_80007330
    if (ctx->r2 != ctx->r15) {
        // 0x80007324: nop
    
            goto L_80007330;
    }
    // 0x80007324: nop

    // 0x80007328: jr          $ra
    // 0x8000732C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    TRACE_RETURN()
    return;
    // 0x8000732C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80007330:
    // 0x80007330: beq         $t8, $zero, L_800073A0
    if (ctx->r24 == 0) {
        // 0x80007334: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_800073A0;
    }
    // 0x80007334: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80007338: andi        $a1, $a2, 0x3
    ctx->r5 = ctx->r6 & 0X3;
    // 0x8000733C: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x80007340: beq         $a1, $zero, L_80007368
    if (ctx->r5 == 0) {
        // 0x80007344: addu        $v1, $a1, $a2
        ctx->r3 = ADD32(ctx->r5, ctx->r6);
            goto L_80007368;
    }
    // 0x80007344: addu        $v1, $a1, $a2
    ctx->r3 = ADD32(ctx->r5, ctx->r6);
L_80007348:
    // 0x80007348: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x8000734C: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x80007350: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80007354: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80007358: bne         $v1, $t0, L_80007348
    if (ctx->r3 != ctx->r8) {
        // 0x8000735C: sb          $t9, -0x1($a3)
        MEM_B(-0X1, ctx->r7) = ctx->r25;
            goto L_80007348;
    }
    // 0x8000735C: sb          $t9, -0x1($a3)
    MEM_B(-0X1, ctx->r7) = ctx->r25;
    // 0x80007360: beql        $t0, $zero, L_80007404
    if (ctx->r8 == 0) {
        // 0x80007364: lw          $t1, 0x4($a0)
        ctx->r9 = MEM_W(ctx->r4, 0X4);
            goto L_80007404;
    }
    goto skip_0;
    // 0x80007364: lw          $t1, 0x4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4);
    skip_0:
L_80007368:
    // 0x80007368: lbu         $t1, 0x0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X0);
    // 0x8000736C: addiu       $t0, $t0, -0x4
    ctx->r8 = ADD32(ctx->r8, -0X4);
    // 0x80007370: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80007374: sb          $t1, -0x4($a3)
    MEM_B(-0X4, ctx->r7) = ctx->r9;
    // 0x80007378: lbu         $t2, 0x1($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X1);
    // 0x8000737C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80007380: sb          $t2, -0x3($a3)
    MEM_B(-0X3, ctx->r7) = ctx->r10;
    // 0x80007384: lbu         $t3, -0x2($v0)
    ctx->r11 = MEM_BU(ctx->r2, -0X2);
    // 0x80007388: sb          $t3, -0x2($a3)
    MEM_B(-0X2, ctx->r7) = ctx->r11;
    // 0x8000738C: lbu         $t4, -0x1($v0)
    ctx->r12 = MEM_BU(ctx->r2, -0X1);
    // 0x80007390: bne         $t0, $zero, L_80007368
    if (ctx->r8 != 0) {
        // 0x80007394: sb          $t4, -0x1($a3)
        MEM_B(-0X1, ctx->r7) = ctx->r12;
            goto L_80007368;
    }
    // 0x80007394: sb          $t4, -0x1($a3)
    MEM_B(-0X1, ctx->r7) = ctx->r12;
    // 0x80007398: b           L_80007404
    // 0x8000739C: lw          $t1, 0x4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4);
        goto L_80007404;
    // 0x8000739C: lw          $t1, 0x4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4);
L_800073A0:
    // 0x800073A0: andi        $a1, $t0, 0xF
    ctx->r5 = ctx->r8 & 0XF;
    // 0x800073A4: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x800073A8: beq         $a1, $zero, L_800073D0
    if (ctx->r5 == 0) {
        // 0x800073AC: addu        $v1, $a1, $t0
        ctx->r3 = ADD32(ctx->r5, ctx->r8);
            goto L_800073D0;
    }
    // 0x800073AC: addu        $v1, $a1, $t0
    ctx->r3 = ADD32(ctx->r5, ctx->r8);
L_800073B0:
    // 0x800073B0: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x800073B4: addiu       $t0, $t0, -0x4
    ctx->r8 = ADD32(ctx->r8, -0X4);
    // 0x800073B8: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800073BC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800073C0: bne         $v1, $t0, L_800073B0
    if (ctx->r3 != ctx->r8) {
        // 0x800073C4: sw          $t5, -0x4($a3)
        MEM_W(-0X4, ctx->r7) = ctx->r13;
            goto L_800073B0;
    }
    // 0x800073C4: sw          $t5, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->r13;
    // 0x800073C8: beql        $t0, $zero, L_80007404
    if (ctx->r8 == 0) {
        // 0x800073CC: lw          $t1, 0x4($a0)
        ctx->r9 = MEM_W(ctx->r4, 0X4);
            goto L_80007404;
    }
    goto skip_1;
    // 0x800073CC: lw          $t1, 0x4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4);
    skip_1:
L_800073D0:
    // 0x800073D0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800073D4: addiu       $t0, $t0, -0x10
    ctx->r8 = ADD32(ctx->r8, -0X10);
    // 0x800073D8: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x800073DC: sw          $t6, -0x10($a3)
    MEM_W(-0X10, ctx->r7) = ctx->r14;
    // 0x800073E0: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x800073E4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800073E8: sw          $t7, -0xC($a3)
    MEM_W(-0XC, ctx->r7) = ctx->r15;
    // 0x800073EC: lw          $t8, -0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X8);
    // 0x800073F0: sw          $t8, -0x8($a3)
    MEM_W(-0X8, ctx->r7) = ctx->r24;
    // 0x800073F4: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x800073F8: bne         $t0, $zero, L_800073D0
    if (ctx->r8 != 0) {
        // 0x800073FC: sw          $t9, -0x4($a3)
        MEM_W(-0X4, ctx->r7) = ctx->r25;
            goto L_800073D0;
    }
    // 0x800073FC: sw          $t9, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->r25;
    // 0x80007400: lw          $t1, 0x4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4);
L_80007404:
    // 0x80007404: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80007408: sltu        $at, $a3, $t1
    ctx->r1 = ctx->r7 < ctx->r9 ? 1 : 0;
    // 0x8000740C: bnel        $at, $zero, L_8000741C
    if (ctx->r1 != 0) {
        // 0x80007410: sw          $a3, 0xC($a0)
        MEM_W(0XC, ctx->r4) = ctx->r7;
            goto L_8000741C;
    }
    goto skip_2;
    // 0x80007410: sw          $a3, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r7;
    skip_2:
    // 0x80007414: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80007418: sw          $a3, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r7;
L_8000741C:
    // 0x8000741C: jr          $ra
    TRACE_RETURN()
    return;
;}
