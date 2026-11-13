#include "recomp.h"
#include "trace.h"
#include "funcs.h"

RECOMP_FUNC void func_80035904(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80035904: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80035908: lh          $t6, -0x6B80($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X6B80);
    // 0x8003590C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80035910: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80035914: bne         $t6, $zero, L_800359F4
    if (ctx->r14 != 0) {
        // 0x80035918: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800359F4;
    }
    // 0x80035918: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003591C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80035920: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80035924: lh          $t8, -0x661C($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X661C);
    // 0x80035928: lh          $t7, -0x661E($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X661E);
    // 0x8003592C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80035930: addiu       $v1, $v1, -0x6BE0
    ctx->r3 = ADD32(ctx->r3, -0X6BE0);
    // 0x80035934: bne         $t7, $t8, L_80035940
    if (ctx->r15 != ctx->r24) {
        // 0x80035938: lui         $a3, 0x8013
        ctx->r7 = S32(0X8013 << 16);
            goto L_80035940;
    }
    // 0x80035938: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x8003593C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80035940:
    // 0x80035940: beq         $v0, $zero, L_80035984
    if (ctx->r2 == 0) {
        // 0x80035944: addiu       $a3, $a3, -0x6B84
        ctx->r7 = ADD32(ctx->r7, -0X6B84);
            goto L_80035984;
    }
    // 0x80035944: addiu       $a3, $a3, -0x6B84
    ctx->r7 = ADD32(ctx->r7, -0X6B84);
    // 0x80035948: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8003594C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80035950: lh          $t1, 0x0($a3)
    ctx->r9 = MEM_H(ctx->r7, 0X0);
    // 0x80035954: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x80035958: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8003595C: lh          $v0, -0x662C($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X662C);
    // 0x80035960: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80035964: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80035968: slt         $at, $t1, $v0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003596C: beq         $at, $zero, L_800359F4
    if (ctx->r1 == 0) {
        // 0x80035970: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800359F4;
    }
    // 0x80035970: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80035974: jal         0x8001A37C
    // 0x80035978: sh          $v0, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r2;
    func_8001A37C(rdram, ctx);
        goto after_0;
    // 0x80035978: sh          $v0, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r2;
    after_0:
    // 0x8003597C: b           L_800359F8
    // 0x80035980: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800359F8;
    // 0x80035980: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80035984:
    // 0x80035984: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80035988: lh          $v0, -0x662C($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X662C);
    // 0x8003598C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80035990: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80035994: bne         $v0, $at, L_800359BC
    if (ctx->r2 != ctx->r1) {
        // 0x80035998: nop
    
            goto L_800359BC;
    }
    // 0x80035998: nop

    // 0x8003599C: lh          $t2, -0x6620($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X6620);
    // 0x800359A0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800359A4: addiu       $v1, $v1, -0x6BE0
    ctx->r3 = ADD32(ctx->r3, -0X6BE0);
    // 0x800359A8: beq         $t2, $zero, L_800359BC
    if (ctx->r10 == 0) {
        // 0x800359AC: nop
    
            goto L_800359BC;
    }
    // 0x800359AC: nop

    // 0x800359B0: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800359B4: ori         $t4, $t3, 0x180
    ctx->r12 = ctx->r11 | 0X180;
    // 0x800359B8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
L_800359BC:
    // 0x800359BC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800359C0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800359C4: bne         $v0, $at, L_800359F4
    if (ctx->r2 != ctx->r1) {
        // 0x800359C8: addiu       $v1, $v1, -0x6BE0
        ctx->r3 = ADD32(ctx->r3, -0X6BE0);
            goto L_800359F4;
    }
    // 0x800359C8: addiu       $v1, $v1, -0x6BE0
    ctx->r3 = ADD32(ctx->r3, -0X6BE0);
    // 0x800359CC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800359D0: lw          $v0, -0x65F4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X65F4);
    // 0x800359D4: beql        $v0, $zero, L_800359F8
    if (ctx->r2 == 0) {
        // 0x800359D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800359F8;
    }
    goto skip_0;
    // 0x800359D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800359DC: lh          $t5, 0x2E($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X2E);
    // 0x800359E0: bgtzl       $t5, L_800359F8
    if (SIGNED(ctx->r13) > 0) {
        // 0x800359E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800359F8;
    }
    goto skip_1;
    // 0x800359E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800359E8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800359EC: ori         $t7, $t6, 0x180
    ctx->r15 = ctx->r14 | 0X180;
    // 0x800359F0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_800359F4:
    // 0x800359F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800359F8:
    // 0x800359F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800359FC: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80035A04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80035A04: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80035A08: addiu       $v0, $v0, -0x662C
    ctx->r2 = ADD32(ctx->r2, -0X662C);
    // 0x80035A0C: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x80035A10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80035A14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80035A18: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x80035A1C: beq         $at, $zero, L_80035A2C
    if (ctx->r1 == 0) {
        // 0x80035A20: addiu       $t6, $a0, 0x1
        ctx->r14 = ADD32(ctx->r4, 0X1);
            goto L_80035A2C;
    }
    // 0x80035A20: addiu       $t6, $a0, 0x1
    ctx->r14 = ADD32(ctx->r4, 0X1);
    // 0x80035A24: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
    // 0x80035A28: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
L_80035A2C:
    // 0x80035A2C: jal         0x80035D1C
    // 0x80035A30: nop

    func_80035D1C(rdram, ctx);
        goto after_0;
    // 0x80035A30: nop

    after_0:
    // 0x80035A34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80035A38: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80035A3C: sw          $v0, -0x6630($at)
    MEM_W(-0X6630, ctx->r1) = ctx->r2;
    // 0x80035A40: jr          $ra
    // 0x80035A44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    TRACE_RETURN()
    return;
    // 0x80035A44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80035A48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80035A48: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80035A4C: addiu       $v0, $v0, -0x6628
    ctx->r2 = ADD32(ctx->r2, -0X6628);
    // 0x80035A50: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x80035A54: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80035A58: addu        $t9, $t8, $a0
    ctx->r25 = ADD32(ctx->r24, ctx->r4);
    // 0x80035A5C: jr          $ra
    // 0x80035A60: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    TRACE_RETURN()
    return;
    // 0x80035A60: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void func_80035A64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80035A64: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80035A68: addiu       $v0, $v0, -0x6628
    ctx->r2 = ADD32(ctx->r2, -0X6628);
    // 0x80035A6C: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x80035A70: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80035A74: jr          $ra
    // 0x80035A78: sh          $t7, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r15;
    TRACE_RETURN()
    return;
    // 0x80035A78: sh          $t7, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void func_80035A7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80035A7C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80035A80: lw          $t8, -0x6BE0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6BE0);
    // 0x80035A84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80035A88: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80035A8C: andi        $t9, $t8, 0x200
    ctx->r25 = ctx->r24 & 0X200;
    // 0x80035A90: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80035A94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80035A98: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80035A9C: bne         $t9, $zero, L_80035C64
    if (ctx->r25 != 0) {
        // 0x80035AA0: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80035C64;
    }
    // 0x80035AA0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80035AA4: beq         $t7, $zero, L_80035B50
    if (ctx->r15 == 0) {
        // 0x80035AA8: lui         $t1, 0x8013
        ctx->r9 = S32(0X8013 << 16);
            goto L_80035B50;
    }
    // 0x80035AA8: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80035AAC: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80035AB0: lh          $t0, -0x662C($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X662C);
    // 0x80035AB4: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80035AB8: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80035ABC: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x80035AC0: lw          $a0, -0x5D18($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5D18);
    // 0x80035AC4: beql        $a0, $zero, L_80035B34
    if (ctx->r4 == 0) {
        // 0x80035AC8: lh          $t9, 0x92($a3)
        ctx->r25 = MEM_H(ctx->r7, 0X92);
            goto L_80035B34;
    }
    goto skip_0;
    // 0x80035AC8: lh          $t9, 0x92($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X92);
    skip_0:
    // 0x80035ACC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80035AD0: addiu       $a1, $a3, 0x84
    ctx->r5 = ADD32(ctx->r7, 0X84);
    // 0x80035AD4: beql        $v0, $zero, L_80035B34
    if (ctx->r2 == 0) {
        // 0x80035AD8: lh          $t9, 0x92($a3)
        ctx->r25 = MEM_H(ctx->r7, 0X92);
            goto L_80035B34;
    }
    goto skip_1;
    // 0x80035AD8: lh          $t9, 0x92($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X92);
    skip_1:
    // 0x80035ADC: lw          $a2, 0x0($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X0);
    // 0x80035AE0: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
L_80035AE4:
    // 0x80035AE4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80035AE8: bnel        $a2, $t2, L_80035B28
    if (ctx->r6 != ctx->r10) {
        // 0x80035AEC: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_80035B28;
    }
    goto skip_2;
    // 0x80035AEC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    skip_2:
    // 0x80035AF0: lw          $t3, 0x4($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X4);
    // 0x80035AF4: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x80035AF8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80035AFC: addiu       $v0, $v0, -0x661E
    ctx->r2 = ADD32(ctx->r2, -0X661E);
    // 0x80035B00: bnel        $t3, $t4, L_80035B28
    if (ctx->r11 != ctx->r12) {
        // 0x80035B04: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_80035B28;
    }
    goto skip_3;
    // 0x80035B04: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    skip_3:
    // 0x80035B08: lh          $t5, 0x0($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X0);
    // 0x80035B0C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80035B10: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
    // 0x80035B14: lh          $t7, 0x92($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X92);
    // 0x80035B18: ori         $t8, $t7, 0x22
    ctx->r24 = ctx->r15 | 0X22;
    // 0x80035B1C: b           L_80035B30
    // 0x80035B20: sh          $t8, 0x92($a3)
    MEM_H(0X92, ctx->r7) = ctx->r24;
        goto L_80035B30;
    // 0x80035B20: sh          $t8, 0x92($a3)
    MEM_H(0X92, ctx->r7) = ctx->r24;
    // 0x80035B24: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_80035B28:
    // 0x80035B28: bnel        $v0, $zero, L_80035AE4
    if (ctx->r2 != 0) {
        // 0x80035B2C: lw          $t2, 0x0($v0)
        ctx->r10 = MEM_W(ctx->r2, 0X0);
            goto L_80035AE4;
    }
    goto skip_4;
    // 0x80035B2C: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    skip_4:
L_80035B30:
    // 0x80035B30: lh          $t9, 0x92($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X92);
L_80035B34:
    // 0x80035B34: andi        $t0, $t9, 0x10
    ctx->r8 = ctx->r25 & 0X10;
    // 0x80035B38: beql        $t0, $zero, L_80035C68
    if (ctx->r8 == 0) {
        // 0x80035B3C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80035C68;
    }
    goto skip_5;
    // 0x80035B3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x80035B40: jal         0x80035A48
    // 0x80035B44: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80035A48(rdram, ctx);
        goto after_0;
    // 0x80035B44: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80035B48: b           L_80035C68
    // 0x80035B4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80035C68;
    // 0x80035B4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80035B50:
    // 0x80035B50: lh          $t1, -0x662C($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X662C);
    // 0x80035B54: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80035B58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80035B5C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80035B60: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    // 0x80035B64: lw          $a0, -0x5CD4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5CD4);
    // 0x80035B68: beql        $a0, $zero, L_80035C2C
    if (ctx->r4 == 0) {
        // 0x80035B6C: lh          $a1, 0x94($a3)
        ctx->r5 = MEM_H(ctx->r7, 0X94);
            goto L_80035C2C;
    }
    goto skip_6;
    // 0x80035B6C: lh          $a1, 0x94($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X94);
    skip_6:
    // 0x80035B70: bnel        $a0, $at, L_80035B94
    if (ctx->r4 != ctx->r1) {
        // 0x80035B74: lh          $t4, 0x0($a0)
        ctx->r12 = MEM_H(ctx->r4, 0X0);
            goto L_80035B94;
    }
    goto skip_7;
    // 0x80035B74: lh          $t4, 0x0($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X0);
    skip_7:
    // 0x80035B78: lh          $t3, 0x94($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X94);
    // 0x80035B7C: addiu       $at, $zero, 0x501
    ctx->r1 = ADD32(0, 0X501);
    // 0x80035B80: beql        $t3, $at, L_80035C68
    if (ctx->r11 == ctx->r1) {
        // 0x80035B84: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80035C68;
    }
    goto skip_8;
    // 0x80035B84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_8:
    // 0x80035B88: b           L_80035BB4
    // 0x80035B8C: lh          $t5, 0x96($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X96);
        goto L_80035BB4;
    // 0x80035B8C: lh          $t5, 0x96($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X96);
    // 0x80035B90: lh          $t4, 0x0($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X0);
L_80035B94:
    // 0x80035B94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80035B98: beq         $t4, $zero, L_80035C20
    if (ctx->r12 == 0) {
        // 0x80035B9C: nop
    
            goto L_80035C20;
    }
    // 0x80035B9C: nop

    // 0x80035BA0: lh          $v1, 0x0($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X0);
    // 0x80035BA4: lh          $a1, 0x94($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X94);
L_80035BA8:
    // 0x80035BA8: bne         $a1, $v1, L_80035C04
    if (ctx->r5 != ctx->r3) {
        // 0x80035BAC: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80035C04;
    }
    // 0x80035BAC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80035BB0: lh          $t5, 0x96($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X96);
L_80035BB4:
    // 0x80035BB4: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80035BB8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80035BBC: bne         $t5, $at, L_80035BE8
    if (ctx->r13 != ctx->r1) {
        // 0x80035BC0: addiu       $v0, $v0, -0x661E
        ctx->r2 = ADD32(ctx->r2, -0X661E);
            goto L_80035BE8;
    }
    // 0x80035BC0: addiu       $v0, $v0, -0x661E
    ctx->r2 = ADD32(ctx->r2, -0X661E);
    // 0x80035BC4: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x80035BC8: lh          $t7, 0x98($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X98);
    // 0x80035BCC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80035BD0: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80035BD4: sh          $t8, -0x661E($at)
    MEM_H(-0X661E, ctx->r1) = ctx->r24;
    // 0x80035BD8: jal         0x80035A48
    // 0x80035BDC: lh          $a0, 0x98($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X98);
    func_80035A48(rdram, ctx);
        goto after_1;
    // 0x80035BDC: lh          $a0, 0x98($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X98);
    after_1:
    // 0x80035BE0: b           L_80035C68
    // 0x80035BE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80035C68;
    // 0x80035BE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80035BE8:
    // 0x80035BE8: lh          $t9, 0x98($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X98);
    // 0x80035BEC: ori         $t0, $t9, 0x400
    ctx->r8 = ctx->r25 | 0X400;
    // 0x80035BF0: sh          $t0, 0x98($a3)
    MEM_H(0X98, ctx->r7) = ctx->r8;
    // 0x80035BF4: lh          $t1, 0x98($a3)
    ctx->r9 = MEM_H(ctx->r7, 0X98);
    // 0x80035BF8: ori         $t2, $t1, 0x800
    ctx->r10 = ctx->r9 | 0X800;
    // 0x80035BFC: b           L_80035C64
    // 0x80035C00: sh          $t2, 0x98($a3)
    MEM_H(0X98, ctx->r7) = ctx->r10;
        goto L_80035C64;
    // 0x80035C00: sh          $t2, 0x98($a3)
    MEM_H(0X98, ctx->r7) = ctx->r10;
L_80035C04:
    // 0x80035C04: sll         $t3, $v0, 16
    ctx->r11 = S32(ctx->r2 << 16);
    // 0x80035C08: sra         $v0, $t3, 16
    ctx->r2 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80035C0C: sll         $t5, $v0, 1
    ctx->r13 = S32(ctx->r2 << 1);
    // 0x80035C10: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x80035C14: lh          $v1, 0x0($t6)
    ctx->r3 = MEM_H(ctx->r14, 0X0);
    // 0x80035C18: bne         $v1, $zero, L_80035BA8
    if (ctx->r3 != 0) {
        // 0x80035C1C: nop
    
            goto L_80035BA8;
    }
    // 0x80035C1C: nop

L_80035C20:
    // 0x80035C20: b           L_80035C2C
    // 0x80035C24: lh          $a1, 0x94($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X94);
        goto L_80035C2C;
    // 0x80035C24: lh          $a1, 0x94($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X94);
    // 0x80035C28: lh          $a1, 0x94($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X94);
L_80035C2C:
    // 0x80035C2C: addiu       $at, $zero, 0x501
    ctx->r1 = ADD32(0, 0X501);
    // 0x80035C30: beql        $a1, $at, L_80035C68
    if (ctx->r5 == ctx->r1) {
        // 0x80035C34: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80035C68;
    }
    goto skip_9;
    // 0x80035C34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_9:
    // 0x80035C38: lh          $t7, 0x96($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X96);
    // 0x80035C3C: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80035C40: bnel        $t7, $at, L_80035C5C
    if (ctx->r15 != ctx->r1) {
        // 0x80035C44: lh          $t8, 0x98($a3)
        ctx->r24 = MEM_H(ctx->r7, 0X98);
            goto L_80035C5C;
    }
    goto skip_10;
    // 0x80035C44: lh          $t8, 0x98($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X98);
    skip_10:
    // 0x80035C48: jal         0x80035A48
    // 0x80035C4C: lh          $a0, 0x98($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X98);
    func_80035A48(rdram, ctx);
        goto after_2;
    // 0x80035C4C: lh          $a0, 0x98($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X98);
    after_2:
    // 0x80035C50: b           L_80035C68
    // 0x80035C54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80035C68;
    // 0x80035C54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80035C58: lh          $t8, 0x98($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X98);
L_80035C5C:
    // 0x80035C5C: ori         $t9, $t8, 0x800
    ctx->r25 = ctx->r24 | 0X800;
    // 0x80035C60: sh          $t9, 0x98($a3)
    MEM_H(0X98, ctx->r7) = ctx->r25;
L_80035C64:
    // 0x80035C64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80035C68:
    // 0x80035C68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80035C6C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80035C74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80035C74: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80035C78: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80035C7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80035C80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80035C84: beq         $t7, $zero, L_80035CD0
    if (ctx->r15 == 0) {
        // 0x80035C88: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_80035CD0;
    }
    // 0x80035C88: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80035C8C: lh          $v0, 0x92($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X92);
    // 0x80035C90: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80035C94: addiu       $v1, $v1, -0x661C
    ctx->r3 = ADD32(ctx->r3, -0X661C);
    // 0x80035C98: andi        $t8, $v0, 0x2
    ctx->r24 = ctx->r2 & 0X2;
    // 0x80035C9C: beql        $t8, $zero, L_80035CB8
    if (ctx->r24 == 0) {
        // 0x80035CA0: andi        $t1, $v0, 0x10
        ctx->r9 = ctx->r2 & 0X10;
            goto L_80035CB8;
    }
    goto skip_0;
    // 0x80035CA0: andi        $t1, $v0, 0x10
    ctx->r9 = ctx->r2 & 0X10;
    skip_0:
    // 0x80035CA4: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x80035CA8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80035CAC: sh          $t0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r8;
    // 0x80035CB0: lh          $v0, 0x92($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X92);
    // 0x80035CB4: andi        $t1, $v0, 0x10
    ctx->r9 = ctx->r2 & 0X10;
L_80035CB8:
    // 0x80035CB8: beql        $t1, $zero, L_80035D10
    if (ctx->r9 == 0) {
        // 0x80035CBC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80035D10;
    }
    goto skip_1;
    // 0x80035CBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80035CC0: jal         0x80035A64
    // 0x80035CC4: nop

    func_80035A64(rdram, ctx);
        goto after_0;
    // 0x80035CC4: nop

    after_0:
    // 0x80035CC8: b           L_80035D10
    // 0x80035CCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80035D10;
    // 0x80035CCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80035CD0:
    // 0x80035CD0: lh          $v0, 0x98($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X98);
    // 0x80035CD4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80035CD8: addiu       $v1, $v1, -0x661C
    ctx->r3 = ADD32(ctx->r3, -0X661C);
    // 0x80035CDC: andi        $t2, $v0, 0x400
    ctx->r10 = ctx->r2 & 0X400;
    // 0x80035CE0: beql        $t2, $zero, L_80035CFC
    if (ctx->r10 == 0) {
        // 0x80035CE4: andi        $t5, $v0, 0x800
        ctx->r13 = ctx->r2 & 0X800;
            goto L_80035CFC;
    }
    goto skip_2;
    // 0x80035CE4: andi        $t5, $v0, 0x800
    ctx->r13 = ctx->r2 & 0X800;
    skip_2:
    // 0x80035CE8: lh          $t3, 0x0($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X0);
    // 0x80035CEC: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80035CF0: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
    // 0x80035CF4: lh          $v0, 0x98($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X98);
    // 0x80035CF8: andi        $t5, $v0, 0x800
    ctx->r13 = ctx->r2 & 0X800;
L_80035CFC:
    // 0x80035CFC: beql        $t5, $zero, L_80035D10
    if (ctx->r13 == 0) {
        // 0x80035D00: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80035D10;
    }
    goto skip_3;
    // 0x80035D00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80035D04: jal         0x80035A64
    // 0x80035D08: nop

    func_80035A64(rdram, ctx);
        goto after_1;
    // 0x80035D08: nop

    after_1:
    // 0x80035D0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80035D10:
    // 0x80035D10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80035D14: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80035D1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80035D1C: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80035D20: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80035D24: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x80035D28: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80035D2C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80035D30: jr          $ra
    // 0x80035D34: lbu         $v0, -0x5CAC($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5CAC);
    TRACE_RETURN()
    return;
    // 0x80035D34: lbu         $v0, -0x5CAC($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5CAC);
;}
static void func_80035D38_entry(uint8_t* rdram, recomp_context* ctx, unsigned entry) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    if (entry == 1) goto indirect_80035D60;

    // 0x80035D38: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80035D3C: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80035D40: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80035D44: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x80035D48: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x80035D4C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80035D50: jr          $ra
    // 0x80035D54: lh          $v0, -0x5CA0($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X5CA0);
    TRACE_RETURN()
    return;
    // 0x80035D54: lh          $v0, -0x5CA0($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X5CA0);
    // 0x80035D58: nop

    // 0x80035D5C: nop

indirect_80035D60:
    // 0x80035D60: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80035D64: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80035D68: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80035D6C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80035D70: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80035D74: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80035D78: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80035D7C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80035D80: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80035D84: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80035D88: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80035D8C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80035D90: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80035D94: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x80035D98: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
    // 0x80035D9C: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80035DA0: jal         0x80004364
    // 0x80035DA4: addiu       $a1, $zero, 0xFC
    ctx->r5 = ADD32(0, 0XFC);
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x80035DA4: addiu       $a1, $zero, 0xFC
    ctx->r5 = ADD32(0, 0XFC);
    after_0:
    // 0x80035DA8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80035DAC: addiu       $v1, $v1, -0x6610
    ctx->r3 = ADD32(ctx->r3, -0X6610);
    // 0x80035DB0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80035DB4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80035DB8: jal         0x8000C7C0
    // 0x80035DBC: addiu       $a1, $zero, 0xFC
    ctx->r5 = ADD32(0, 0XFC);
    func_8000C7C0(rdram, ctx);
        goto after_1;
    // 0x80035DBC: addiu       $a1, $zero, 0xFC
    ctx->r5 = ADD32(0, 0XFC);
    after_1:
    // 0x80035DC0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80035DC4: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80035DC8: jal         0x80004364
    // 0x80035DCC: addiu       $a1, $zero, 0xFC
    ctx->r5 = ADD32(0, 0XFC);
    func_80004364(rdram, ctx);
        goto after_2;
    // 0x80035DCC: addiu       $a1, $zero, 0xFC
    ctx->r5 = ADD32(0, 0XFC);
    after_2:
    // 0x80035DD0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80035DD4: addiu       $v1, $v1, -0x660C
    ctx->r3 = ADD32(ctx->r3, -0X660C);
    // 0x80035DD8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80035DDC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80035DE0: jal         0x8000C7C0
    // 0x80035DE4: addiu       $a1, $zero, 0xFC
    ctx->r5 = ADD32(0, 0XFC);
    func_8000C7C0(rdram, ctx);
        goto after_3;
    // 0x80035DE4: addiu       $a1, $zero, 0xFC
    ctx->r5 = ADD32(0, 0XFC);
    after_3:
    // 0x80035DE8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80035DEC: addiu       $v0, $v0, -0x6610
    ctx->r2 = ADD32(ctx->r2, -0X6610);
    // 0x80035DF0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80035DF4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80035DF8: addiu       $v1, $v1, -0x660C
    ctx->r3 = ADD32(ctx->r3, -0X660C);
    // 0x80035DFC: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x80035E00: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80035E04: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x80035E08: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80035E0C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80035E10: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80035E14: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x80035E18: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80035E1C: jal         0x80036C34
    // 0x80035E20: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    func_80036C34(rdram, ctx);
        goto after_4;
    // 0x80035E20: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    after_4:
    // 0x80035E24: jal         0x800361D0
    // 0x80035E28: nop

    func_800361D0(rdram, ctx);
        goto after_5;
    // 0x80035E28: nop

    after_5:
    // 0x80035E2C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80035E30: sh          $zero, -0x6624($at)
    MEM_H(-0X6624, ctx->r1) = 0;
    // 0x80035E34: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80035E38: sh          $zero, -0x65BC($at)
    MEM_H(-0X65BC, ctx->r1) = 0;
    // 0x80035E3C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80035E40: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x80035E44: sh          $zero, -0x65F6($at)
    MEM_H(-0X65F6, ctx->r1) = 0;
    // 0x80035E48: addiu       $fp, $fp, -0x65AC
    ctx->r30 = ADD32(ctx->r30, -0X65AC);
    // 0x80035E4C: sh          $zero, 0x0($fp)
    MEM_H(0X0, ctx->r30) = 0;
    // 0x80035E50: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80035E54: sh          $zero, -0x65AA($at)
    MEM_H(-0X65AA, ctx->r1) = 0;
    // 0x80035E58: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80035E5C: sw          $zero, -0x65F0($at)
    MEM_W(-0X65F0, ctx->r1) = 0;
    // 0x80035E60: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80035E64: lh          $t2, -0x662C($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X662C);
    // 0x80035E68: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80035E6C: sh          $zero, -0x65E0($at)
    MEM_H(-0X65E0, ctx->r1) = 0;
    // 0x80035E70: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80035E74: bnel        $t2, $at, L_80035EA8
    if (ctx->r10 != ctx->r1) {
        // 0x80035E78: lui         $at, 0x447A
        ctx->r1 = S32(0X447A << 16);
            goto L_80035EA8;
    }
    goto skip_0;
    // 0x80035E78: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    skip_0:
    // 0x80035E7C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80035E80: addiu       $s1, $sp, 0x60
    ctx->r17 = ADD32(ctx->r29, 0X60);
    // 0x80035E84: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80035E88: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    // 0x80035E8C: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x80035E90: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x80035E94: jal         0x80039724
    // 0x80035E98: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    func_80039724(rdram, ctx);
        goto after_6;
    // 0x80035E98: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x80035E9C: b           L_80035ED0
    // 0x80035EA0: nop

        goto L_80035ED0;
    // 0x80035EA0: nop

    // 0x80035EA4: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
L_80035EA8:
    // 0x80035EA8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80035EAC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80035EB0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80035EB4: addiu       $s1, $sp, 0x60
    ctx->r17 = ADD32(ctx->r29, 0X60);
    // 0x80035EB8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80035EBC: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    // 0x80035EC0: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    // 0x80035EC4: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
    // 0x80035EC8: jal         0x80039724
    // 0x80035ECC: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    func_80039724(rdram, ctx);
        goto after_7;
    // 0x80035ECC: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    after_7:
L_80035ED0:
    // 0x80035ED0: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80035ED4: lh          $t3, -0x6B80($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X6B80);
    // 0x80035ED8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80035EDC: sh          $zero, -0x65A8($at)
    MEM_H(-0X65A8, ctx->r1) = 0;
    // 0x80035EE0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80035EE4: bne         $t3, $at, L_80035F4C
    if (ctx->r11 != ctx->r1) {
        // 0x80035EE8: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80035F4C;
    }
    // 0x80035EE8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80035EEC:
    // 0x80035EEC: jal         0x8000E35C
    // 0x80035EF0: nop

    func_8000E35C(rdram, ctx);
        goto after_8;
    // 0x80035EF0: nop

    after_8:
    // 0x80035EF4: andi        $t4, $v0, 0x3FF
    ctx->r12 = ctx->r2 & 0X3FF;
    // 0x80035EF8: addiu       $t5, $t4, -0x458
    ctx->r13 = ADD32(ctx->r12, -0X458);
    // 0x80035EFC: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x80035F00: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80035F04: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80035F08: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
    // 0x80035F0C: jal         0x8000E35C
    // 0x80035F10: swc1        $f16, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f16.u32l;
    func_8000E35C(rdram, ctx);
        goto after_9;
    // 0x80035F10: swc1        $f16, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f16.u32l;
    after_9:
    // 0x80035F14: andi        $t6, $v0, 0x3FF
    ctx->r14 = ctx->r2 & 0X3FF;
    // 0x80035F18: addiu       $t7, $t6, -0x458
    ctx->r15 = ADD32(ctx->r14, -0X458);
    // 0x80035F1C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80035F20: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    // 0x80035F24: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80035F28: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80035F2C: jal         0x80039724
    // 0x80035F30: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    func_80039724(rdram, ctx);
        goto after_10;
    // 0x80035F30: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    after_10:
    // 0x80035F34: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80035F38: sll         $t8, $s0, 16
    ctx->r24 = S32(ctx->r16 << 16);
    // 0x80035F3C: sra         $s0, $t8, 16
    ctx->r16 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80035F40: slti        $at, $s0, 0xF
    ctx->r1 = SIGNED(ctx->r16) < 0XF ? 1 : 0;
    // 0x80035F44: bne         $at, $zero, L_80035EEC
    if (ctx->r1 != 0) {
        // 0x80035F48: nop
    
            goto L_80035EEC;
    }
    // 0x80035F48: nop

L_80035F4C:
    // 0x80035F4C: jal         0x8000798C
    // 0x80035F50: nop

    func_8000798C(rdram, ctx);
        goto after_11;
    // 0x80035F50: nop

    after_11:
    // 0x80035F54: addiu       $s5, $zero, 0x300
    ctx->r21 = ADD32(0, 0X300);
    // 0x80035F58: addiu       $s4, $zero, 0x200
    ctx->r20 = ADD32(0, 0X200);
    // 0x80035F5C: addiu       $s3, $zero, 0x100
    ctx->r19 = ADD32(0, 0X100);
    // 0x80035F60: addiu       $s1, $zero, -0x2
    ctx->r17 = ADD32(0, -0X2);
    // 0x80035F64: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
L_80035F68:
    // 0x80035F68: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80035F6C: bne         $v0, $at, L_80036034
    if (ctx->r2 != ctx->r1) {
        // 0x80035F70: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_80036034;
    }
    // 0x80035F70: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80035F74: addiu       $a0, $a0, -0x65F8
    ctx->r4 = ADD32(ctx->r4, -0X65F8);
    // 0x80035F78: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x80035F7C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80035F80: addiu       $v1, $v1, -0x6622
    ctx->r3 = ADD32(ctx->r3, -0X6622);
    // 0x80035F84: beq         $v0, $zero, L_80035F9C
    if (ctx->r2 == 0) {
        // 0x80035F88: nop
    
            goto L_80035F9C;
    }
    // 0x80035F88: nop

    // 0x80035F8C: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
    // 0x80035F90: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x80035F94: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x80035F98: sh          $t1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r9;
L_80035F9C:
    // 0x80035F9C: jal         0x80036D64
    // 0x80035FA0: nop

    func_80036D64(rdram, ctx);
        goto after_12;
    // 0x80035FA0: nop

    after_12:
    // 0x80035FA4: jal         0x80036BB4
    // 0x80035FA8: nop

    func_80036BB4(rdram, ctx);
        goto after_13;
    // 0x80035FA8: nop

    after_13:
    // 0x80035FAC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80035FB0: lw          $a1, -0x6610($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6610);
    // 0x80035FB4: lw          $s0, 0x0($a1)
    ctx->r16 = MEM_W(ctx->r5, 0X0);
    // 0x80035FB8: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80035FBC: beq         $t2, $zero, L_80035FEC
    if (ctx->r10 == 0) {
        // 0x80035FC0: nop
    
            goto L_80035FEC;
    }
    // 0x80035FC0: nop

    // 0x80035FC4: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
L_80035FC8:
    // 0x80035FC8: jal         0x80036E0C
    // 0x80035FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80036E0C(rdram, ctx);
        goto after_14;
    // 0x80035FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80035FD0: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80035FD4: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80035FD8: bnel        $t3, $zero, L_80035FC8
    if (ctx->r11 != 0) {
        // 0x80035FDC: lw          $s1, 0x0($s0)
        ctx->r17 = MEM_W(ctx->r16, 0X0);
            goto L_80035FC8;
    }
    goto skip_1;
    // 0x80035FDC: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x80035FE0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80035FE4: lw          $a1, -0x6610($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6610);
    // 0x80035FE8: sw          $s1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r17;
L_80035FEC:
    // 0x80035FEC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80035FF0: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x80035FF4: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80035FF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80035FFC: jal         0x800042A8
    // 0x80036000: addiu       $s7, $zero, 0xFF
    ctx->r23 = ADD32(0, 0XFF);
    func_800042A8(rdram, ctx);
        goto after_15;
    // 0x80036000: addiu       $s7, $zero, 0xFF
    ctx->r23 = ADD32(0, 0XFF);
    after_15:
    // 0x80036004: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80036008: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8003600C: lw          $a1, -0x660C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X660C);
    // 0x80036010: jal         0x800042A8
    // 0x80036014: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    func_800042A8(rdram, ctx);
        goto after_16;
    // 0x80036014: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    after_16:
    // 0x80036018: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8003601C: sw          $zero, -0x65F4($at)
    MEM_W(-0X65F4, ctx->r1) = 0;
    // 0x80036020: sw          $zero, 0x0($s6)
    MEM_W(0X0, ctx->r22) = 0;
L_80036024:
    // 0x80036024: jal         0x8000798C
    // 0x80036028: nop

    func_8000798C(rdram, ctx);
        goto after_17;
    // 0x80036028: nop

    after_17:
    // 0x8003602C: b           L_80036024
    // 0x80036030: nop

        goto L_80036024;
    // 0x80036030: nop

L_80036034:
    // 0x80036034: bne         $s1, $v0, L_80036058
    if (ctx->r17 != ctx->r2) {
        // 0x80036038: nop
    
            goto L_80036058;
    }
    // 0x80036038: nop

    // 0x8003603C: bne         $s1, $v0, L_80036058
    if (ctx->r17 != ctx->r2) {
        // 0x80036040: nop
    
            goto L_80036058;
    }
    // 0x80036040: nop

L_80036044:
    // 0x80036044: jal         0x8000798C
    // 0x80036048: nop

    func_8000798C(rdram, ctx);
        goto after_18;
    // 0x80036048: nop

    after_18:
    // 0x8003604C: lw          $t4, 0x0($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X0);
    // 0x80036050: beq         $s1, $t4, L_80036044
    if (ctx->r17 == ctx->r12) {
        // 0x80036054: nop
    
            goto L_80036044;
    }
    // 0x80036054: nop

L_80036058:
    // 0x80036058: jal         0x80036378
    // 0x8003605C: nop

    func_80036378(rdram, ctx);
        goto after_19;
    // 0x8003605C: nop

    after_19:
    // 0x80036060: lh          $v0, 0x0($fp)
    ctx->r2 = MEM_H(ctx->r30, 0X0);
    // 0x80036064: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80036068: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x8003606C: beq         $v0, $zero, L_80036080
    if (ctx->r2 == 0) {
        // 0x80036070: addiu       $t5, $v0, -0x1
        ctx->r13 = ADD32(ctx->r2, -0X1);
            goto L_80036080;
    }
    // 0x80036070: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x80036074: addiu       $s7, $zero, 0xFF
    ctx->r23 = ADD32(0, 0XFF);
    // 0x80036078: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x8003607C: sh          $zero, 0x0($fp)
    MEM_H(0X0, ctx->r30) = 0;
L_80036080:
    // 0x80036080: beq         $s7, $zero, L_80036118
    if (ctx->r23 == 0) {
        // 0x80036084: or          $s2, $s7, $zero
        ctx->r18 = ctx->r23 | 0;
            goto L_80036118;
    }
    // 0x80036084: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x80036088: lhu         $a3, 0x54($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X54);
    // 0x8003608C: or          $s0, $s7, $zero
    ctx->r16 = ctx->r23 | 0;
    // 0x80036090: sll         $t6, $s0, 24
    ctx->r14 = S32(ctx->r16 << 24);
    // 0x80036094: sra         $s0, $t6, 16
    ctx->r16 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80036098: sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16 << 16);
    // 0x8003609C: addiu       $a3, $a3, 0x4D
    ctx->r7 = ADD32(ctx->r7, 0X4D);
    // 0x800360A0: sll         $t9, $a3, 16
    ctx->r25 = S32(ctx->r7 << 16);
    // 0x800360A4: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800360A8: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800360AC: sra         $a3, $t9, 16
    ctx->r7 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800360B0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800360B4: jal         0x8004C580
    // 0x800360B8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_20;
    // 0x800360B8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_20:
    // 0x800360BC: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800360C0: lh          $t1, -0x65AA($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X65AA);
    // 0x800360C4: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    // 0x800360C8: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x800360CC: slti        $at, $t1, 0x2
    ctx->r1 = SIGNED(ctx->r9) < 0X2 ? 1 : 0;
    // 0x800360D0: bnel        $at, $zero, L_80036108
    if (ctx->r1 != 0) {
        // 0x800360D4: addiu       $s7, $s2, -0x5
        ctx->r23 = ADD32(ctx->r18, -0X5);
            goto L_80036108;
    }
    goto skip_2;
    // 0x800360D4: addiu       $s7, $s2, -0x5
    ctx->r23 = ADD32(ctx->r18, -0X5);
    skip_2:
    // 0x800360D8: jal         0x8004C388
    // 0x800360DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004C388(rdram, ctx);
        goto after_21;
    // 0x800360DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_21:
    // 0x800360E0: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x800360E4: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800360E8: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x800360EC: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800360F0: lh          $a3, -0x65AA($a3)
    ctx->r7 = MEM_H(ctx->r7, -0X65AA);
    // 0x800360F4: addiu       $a2, $a2, 0x7210
    ctx->r6 = ADD32(ctx->r6, 0X7210);
    // 0x800360F8: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800360FC: jal         0x8004C340
    // 0x80036100: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004C340(rdram, ctx);
        goto after_22;
    // 0x80036100: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_22:
    // 0x80036104: addiu       $s7, $s2, -0x5
    ctx->r23 = ADD32(ctx->r18, -0X5);
L_80036108:
    // 0x80036108: andi        $t3, $s7, 0xFFFF
    ctx->r11 = ctx->r23 & 0XFFFF;
    // 0x8003610C: bgtz        $t3, L_80036118
    if (SIGNED(ctx->r11) > 0) {
        // 0x80036110: or          $s7, $t3, $zero
        ctx->r23 = ctx->r11 | 0;
            goto L_80036118;
    }
    // 0x80036110: or          $s7, $t3, $zero
    ctx->r23 = ctx->r11 | 0;
    // 0x80036114: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
L_80036118:
    // 0x80036118: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x8003611C: lw          $t4, -0x6610($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X6610);
    // 0x80036120: lw          $s0, 0x0($t4)
    ctx->r16 = MEM_W(ctx->r12, 0X0);
    // 0x80036124: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80036128: beq         $v1, $zero, L_80036190
    if (ctx->r3 == 0) {
        // 0x8003612C: nop
    
            goto L_80036190;
    }
    // 0x8003612C: nop

    // 0x80036130: lh          $v0, 0x8C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X8C);
L_80036134:
    // 0x80036134: beq         $v0, $s3, L_80036154
    if (ctx->r2 == ctx->r19) {
        // 0x80036138: nop
    
            goto L_80036154;
    }
    // 0x80036138: nop

    // 0x8003613C: beq         $v0, $s4, L_80036164
    if (ctx->r2 == ctx->r20) {
        // 0x80036140: nop
    
            goto L_80036164;
    }
    // 0x80036140: nop

    // 0x80036144: beq         $v0, $s5, L_80036174
    if (ctx->r2 == ctx->r21) {
        // 0x80036148: nop
    
            goto L_80036174;
    }
    // 0x80036148: nop

    // 0x8003614C: b           L_80036184
    // 0x80036150: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
        goto L_80036184;
    // 0x80036150: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
L_80036154:
    // 0x80036154: jal         0x80037020
    // 0x80036158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80037020(rdram, ctx);
        goto after_23;
    // 0x80036158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x8003615C: b           L_80036180
    // 0x80036160: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_80036180;
    // 0x80036160: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80036164:
    // 0x80036164: jal         0x80037BB4
    // 0x80036168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80037BB4(rdram, ctx);
        goto after_24;
    // 0x80036168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x8003616C: b           L_80036180
    // 0x80036170: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_80036180;
    // 0x80036170: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80036174:
    // 0x80036174: jal         0x800389EC
    // 0x80036178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800389EC(rdram, ctx);
        goto after_25;
    // 0x80036178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x8003617C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80036180:
    // 0x80036180: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
L_80036184:
    // 0x80036184: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80036188: bnel        $v1, $zero, L_80036134
    if (ctx->r3 != 0) {
        // 0x8003618C: lh          $v0, 0x8C($s0)
        ctx->r2 = MEM_H(ctx->r16, 0X8C);
            goto L_80036134;
    }
    goto skip_3;
    // 0x8003618C: lh          $v0, 0x8C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X8C);
    skip_3:
L_80036190:
    // 0x80036190: jal         0x8000798C
    // 0x80036194: nop

    func_8000798C(rdram, ctx);
        goto after_26;
    // 0x80036194: nop

    after_26:
    // 0x80036198: b           L_80035F68
    // 0x8003619C: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
        goto L_80035F68;
    // 0x8003619C: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x800361A0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800361A4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800361A8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800361AC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800361B0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800361B4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800361B8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800361BC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800361C0: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800361C4: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800361C8: jr          $ra
    // 0x800361CC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    TRACE_RETURN()
    return;
    // 0x800361CC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_80035D38(uint8_t* rdram, recomp_context* ctx) { func_80035D38_entry(rdram, ctx, 0); }
RECOMP_FUNC void func_80035D60(uint8_t* rdram, recomp_context* ctx) { func_80035D38_entry(rdram, ctx, 1); }

RECOMP_FUNC void func_800361D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800361D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800361D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800361D8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800361DC: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x800361E0: jal         0x80004364
    // 0x800361E4: addiu       $a1, $zero, 0x90
    ctx->r5 = ADD32(0, 0X90);
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x800361E4: addiu       $a1, $zero, 0x90
    ctx->r5 = ADD32(0, 0X90);
    after_0:
    // 0x800361E8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800361EC: addiu       $v1, $v1, -0x6600
    ctx->r3 = ADD32(ctx->r3, -0X6600);
    // 0x800361F0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800361F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800361F8: jal         0x8000C7C0
    // 0x800361FC: addiu       $a1, $zero, 0x90
    ctx->r5 = ADD32(0, 0X90);
    func_8000C7C0(rdram, ctx);
        goto after_1;
    // 0x800361FC: addiu       $a1, $zero, 0x90
    ctx->r5 = ADD32(0, 0X90);
    after_1:
    // 0x80036200: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80036204: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80036208: jal         0x80004364
    // 0x8003620C: addiu       $a1, $zero, 0x90
    ctx->r5 = ADD32(0, 0X90);
    func_80004364(rdram, ctx);
        goto after_2;
    // 0x8003620C: addiu       $a1, $zero, 0x90
    ctx->r5 = ADD32(0, 0X90);
    after_2:
    // 0x80036210: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80036214: addiu       $v1, $v1, -0x65FC
    ctx->r3 = ADD32(ctx->r3, -0X65FC);
    // 0x80036218: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8003621C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80036220: jal         0x8000C7C0
    // 0x80036224: addiu       $a1, $zero, 0x90
    ctx->r5 = ADD32(0, 0X90);
    func_8000C7C0(rdram, ctx);
        goto after_3;
    // 0x80036224: addiu       $a1, $zero, 0x90
    ctx->r5 = ADD32(0, 0X90);
    after_3:
    // 0x80036228: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003622C: addiu       $v0, $v0, -0x6600
    ctx->r2 = ADD32(ctx->r2, -0X6600);
    // 0x80036230: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80036234: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80036238: addiu       $v1, $v1, -0x65FC
    ctx->r3 = ADD32(ctx->r3, -0X65FC);
    // 0x8003623C: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x80036240: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80036244: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x80036248: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8003624C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80036250: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80036254: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x80036258: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8003625C: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x80036260: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80036264: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80036268: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80036270(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80036270: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80036274: lh          $t6, -0x6B94($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X6B94);
    // 0x80036278: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003627C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036280: bne         $t6, $zero, L_80036290
    if (ctx->r14 != 0) {
        // 0x80036284: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_80036290;
    }
    // 0x80036284: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80036288: b           L_80036310
    // 0x8003628C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80036310;
    // 0x8003628C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80036290:
    // 0x80036290: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80036294: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80036298: jal         0x80004364
    // 0x8003629C: addiu       $a1, $zero, 0x90
    ctx->r5 = ADD32(0, 0X90);
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x8003629C: addiu       $a1, $zero, 0x90
    ctx->r5 = ADD32(0, 0X90);
    after_0:
    // 0x800362A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800362A4: addiu       $a1, $zero, 0x90
    ctx->r5 = ADD32(0, 0X90);
    // 0x800362A8: jal         0x8000C7C0
    // 0x800362AC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8000C7C0(rdram, ctx);
        goto after_1;
    // 0x800362AC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800362B0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800362B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800362B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800362BC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800362C0: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
L_800362C4:
    // 0x800362C4: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800362C8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800362CC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800362D0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800362D4: bne         $v0, $a1, L_800362C4
    if (ctx->r2 != ctx->r5) {
        // 0x800362D8: swc1        $f4, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
            goto L_800362C4;
    }
    // 0x800362D8: swc1        $f4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
    // 0x800362DC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800362E0: addiu       $v1, $v1, -0x65FC
    ctx->r3 = ADD32(ctx->r3, -0X65FC);
    // 0x800362E4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800362E8: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x800362EC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x800362F0: sw          $a2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r6;
    // 0x800362F4: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800362F8: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x800362FC: sw          $t0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r8;
    // 0x80036300: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x80036304: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x80036308: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8003630C: sw          $a2, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r6;
L_80036310:
    // 0x80036310: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80036314: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80036318: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80036320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80036320: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80036324: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036328: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8003632C: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x80036330: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80036334: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80036338: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8003633C: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x80036340: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x80036344: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80036348: beq         $a2, $zero, L_8003635C
    if (ctx->r6 == 0) {
        // 0x8003634C: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8003635C;
    }
    // 0x8003634C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80036350: jal         0x8004A0C4
    // 0x80036354: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_8004A0C4(rdram, ctx);
        goto after_0;
    // 0x80036354: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80036358: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
L_8003635C:
    // 0x8003635C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80036360: jal         0x800042A8
    // 0x80036364: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    func_800042A8(rdram, ctx);
        goto after_1;
    // 0x80036364: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    after_1:
    // 0x80036368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003636C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80036370: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80036378(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80036378: addiu       $sp, $sp, -0xF8
    ctx->r29 = ADD32(ctx->r29, -0XF8);
    // 0x8003637C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80036380: lw          $t6, -0x6600($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6600);
    // 0x80036384: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80036388: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8003638C: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x80036390: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80036394: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80036398: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8003639C: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x800363A0: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800363A4: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800363A8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800363AC: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800363B0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800363B4: lw          $s2, 0x0($t6)
    ctx->r18 = MEM_W(ctx->r14, 0X0);
    // 0x800363B8: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x800363BC: addiu       $fp, $fp, -0x65AA
    ctx->r30 = ADD32(ctx->r30, -0X65AA);
    // 0x800363C0: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800363C4: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x800363C8: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    // 0x800363CC: beq         $t7, $zero, L_80036B7C
    if (ctx->r15 == 0) {
        // 0x800363D0: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80036B7C;
    }
    // 0x800363D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800363D4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800363D8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800363DC: ldc1        $f20, 0x7250($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, 0X7250);
    // 0x800363E0: addiu       $s5, $zero, 0xC
    ctx->r21 = ADD32(0, 0XC);
    // 0x800363E4: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x800363E8: lh          $v1, 0x82($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X82);
L_800363EC:
    // 0x800363EC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800363F0: beq         $v1, $zero, L_80036418
    if (ctx->r3 == 0) {
        // 0x800363F4: nop
    
            goto L_80036418;
    }
    // 0x800363F4: nop

    // 0x800363F8: beql        $v1, $s6, L_80036680
    if (ctx->r3 == ctx->r22) {
        // 0x800363FC: lh          $v0, 0x8A($s2)
        ctx->r2 = MEM_H(ctx->r18, 0X8A);
            goto L_80036680;
    }
    goto skip_0;
    // 0x800363FC: lh          $v0, 0x8A($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X8A);
    skip_0:
    // 0x80036400: beql        $v1, $s7, L_800366B4
    if (ctx->r3 == ctx->r23) {
        // 0x80036404: lwc1        $f0, 0x40($s2)
        ctx->f0.u32l = MEM_W(ctx->r18, 0X40);
            goto L_800366B4;
    }
    goto skip_1;
    // 0x80036404: lwc1        $f0, 0x40($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X40);
    skip_1:
    // 0x80036408: beql        $v1, $s4, L_80036818
    if (ctx->r3 == ctx->r20) {
        // 0x8003640C: lh          $v0, 0x84($s2)
        ctx->r2 = MEM_H(ctx->r18, 0X84);
            goto L_80036818;
    }
    goto skip_2;
    // 0x8003640C: lh          $v0, 0x84($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X84);
    skip_2:
    // 0x80036410: b           L_80036818
    // 0x80036414: lh          $v0, 0x84($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X84);
        goto L_80036818;
    // 0x80036414: lh          $v0, 0x84($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X84);
L_80036418:
    // 0x80036418: lh          $t8, -0x662C($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X662C);
    // 0x8003641C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80036420: bne         $t8, $at, L_800364A8
    if (ctx->r24 != ctx->r1) {
        // 0x80036424: nop
    
            goto L_800364A8;
    }
    // 0x80036424: nop

    // 0x80036428: jal         0x8000E35C
    // 0x8003642C: nop

    func_8000E35C(rdram, ctx);
        goto after_0;
    // 0x8003642C: nop

    after_0:
    // 0x80036430: andi        $t9, $v0, 0xF
    ctx->r25 = ctx->r2 & 0XF;
    // 0x80036434: lui         $t0, 0x8007
    ctx->r8 = S32(0X8007 << 16);
    // 0x80036438: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8003643C: lbu         $t0, -0x5C6C($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X5C6C);
    // 0x80036440: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80036444: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80036448: sh          $t0, 0x80($s2)
    MEM_H(0X80, ctx->r18) = ctx->r8;
    // 0x8003644C: lh          $v1, 0x80($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X80);
    // 0x80036450: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80036454: bne         $s4, $v1, L_80036474
    if (ctx->r20 != ctx->r3) {
        // 0x80036458: nop
    
            goto L_80036474;
    }
    // 0x80036458: nop

    // 0x8003645C: lh          $v0, -0x68DE($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X68DE);
    // 0x80036460: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80036464: bne         $v0, $at, L_80036474
    if (ctx->r2 != ctx->r1) {
        // 0x80036468: nop
    
            goto L_80036474;
    }
    // 0x80036468: nop

    // 0x8003646C: sh          $s7, 0x80($s2)
    MEM_H(0X80, ctx->r18) = ctx->r23;
    // 0x80036470: lh          $v1, 0x80($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X80);
L_80036474:
    // 0x80036474: beq         $s7, $v1, L_80036484
    if (ctx->r23 == ctx->r3) {
        // 0x80036478: nop
    
            goto L_80036484;
    }
    // 0x80036478: nop

    // 0x8003647C: bnel        $s6, $v1, L_800365CC
    if (ctx->r22 != ctx->r3) {
        // 0x80036480: lh          $t4, 0x80($s2)
        ctx->r12 = MEM_H(ctx->r18, 0X80);
            goto L_800365CC;
    }
    goto skip_3;
    // 0x80036480: lh          $t4, 0x80($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X80);
    skip_3:
L_80036484:
    // 0x80036484: lh          $t1, -0x68D2($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X68D2);
    // 0x80036488: lh          $t2, -0x6932($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X6932);
    // 0x8003648C: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80036490: beq         $at, $zero, L_800364A0
    if (ctx->r1 == 0) {
        // 0x80036494: nop
    
            goto L_800364A0;
    }
    // 0x80036494: nop

    // 0x80036498: b           L_800365C8
    // 0x8003649C: sh          $s7, 0x80($s2)
    MEM_H(0X80, ctx->r18) = ctx->r23;
        goto L_800365C8;
    // 0x8003649C: sh          $s7, 0x80($s2)
    MEM_H(0X80, ctx->r18) = ctx->r23;
L_800364A0:
    // 0x800364A0: b           L_800365C8
    // 0x800364A4: sh          $s6, 0x80($s2)
    MEM_H(0X80, ctx->r18) = ctx->r22;
        goto L_800365C8;
    // 0x800364A4: sh          $s6, 0x80($s2)
    MEM_H(0X80, ctx->r18) = ctx->r22;
L_800364A8:
    // 0x800364A8: jal         0x8000E35C
    // 0x800364AC: nop

    func_8000E35C(rdram, ctx);
        goto after_1;
    // 0x800364AC: nop

    after_1:
    // 0x800364B0: andi        $t3, $v0, 0xF
    ctx->r11 = ctx->r2 & 0XF;
    // 0x800364B4: lui         $t4, 0x8007
    ctx->r12 = S32(0X8007 << 16);
    // 0x800364B8: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800364BC: lbu         $t4, -0x5C7C($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X5C7C);
    // 0x800364C0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800364C4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800364C8: sh          $t4, 0x80($s2)
    MEM_H(0X80, ctx->r18) = ctx->r12;
    // 0x800364CC: lh          $v1, 0x80($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X80);
    // 0x800364D0: beq         $v1, $s6, L_80036500
    if (ctx->r3 == ctx->r22) {
        // 0x800364D4: nop
    
            goto L_80036500;
    }
    // 0x800364D4: nop

    // 0x800364D8: beq         $v1, $s7, L_80036530
    if (ctx->r3 == ctx->r23) {
        // 0x800364DC: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80036530;
    }
    // 0x800364DC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800364E0: bne         $v1, $s4, L_8003655C
    if (ctx->r3 != ctx->r20) {
        // 0x800364E4: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8003655C;
    }
    // 0x800364E4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800364E8: lh          $v0, -0x68DE($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X68DE);
    // 0x800364EC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800364F0: bne         $v0, $at, L_8003655C
    if (ctx->r2 != ctx->r1) {
        // 0x800364F4: nop
    
            goto L_8003655C;
    }
    // 0x800364F4: nop

    // 0x800364F8: b           L_8003655C
    // 0x800364FC: sh          $zero, 0x80($s2)
    MEM_H(0X80, ctx->r18) = 0;
        goto L_8003655C;
    // 0x800364FC: sh          $zero, 0x80($s2)
    MEM_H(0X80, ctx->r18) = 0;
L_80036500:
    // 0x80036500: lh          $v0, -0x6934($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X6934);
    // 0x80036504: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80036508: lh          $t6, -0x6938($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X6938);
    // 0x8003650C: bgez        $v0, L_8003651C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80036510: sra         $t5, $v0, 1
        ctx->r13 = S32(SIGNED(ctx->r2) >> 1);
            goto L_8003651C;
    }
    // 0x80036510: sra         $t5, $v0, 1
    ctx->r13 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80036514: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x80036518: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_8003651C:
    // 0x8003651C: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80036520: beq         $at, $zero, L_8003655C
    if (ctx->r1 == 0) {
        // 0x80036524: nop
    
            goto L_8003655C;
    }
    // 0x80036524: nop

    // 0x80036528: b           L_8003655C
    // 0x8003652C: sh          $zero, 0x80($s2)
    MEM_H(0X80, ctx->r18) = 0;
        goto L_8003655C;
    // 0x8003652C: sh          $zero, 0x80($s2)
    MEM_H(0X80, ctx->r18) = 0;
L_80036530:
    // 0x80036530: lw          $v0, -0x68D8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68D8);
    // 0x80036534: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80036538: lw          $v1, -0x68DC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X68DC);
    // 0x8003653C: bgez        $v0, L_8003654C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80036540: sra         $t7, $v0, 1
        ctx->r15 = S32(SIGNED(ctx->r2) >> 1);
            goto L_8003654C;
    }
    // 0x80036540: sra         $t7, $v0, 1
    ctx->r15 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80036544: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x80036548: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_8003654C:
    // 0x8003654C: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80036550: beq         $at, $zero, L_8003655C
    if (ctx->r1 == 0) {
        // 0x80036554: nop
    
            goto L_8003655C;
    }
    // 0x80036554: nop

    // 0x80036558: sh          $zero, 0x80($s2)
    MEM_H(0X80, ctx->r18) = 0;
L_8003655C:
    // 0x8003655C: lh          $t8, -0x6938($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X6938);
    // 0x80036560: slti        $at, $t8, 0xC8
    ctx->r1 = SIGNED(ctx->r24) < 0XC8 ? 1 : 0;
    // 0x80036564: beq         $at, $zero, L_80036590
    if (ctx->r1 == 0) {
        // 0x80036568: nop
    
            goto L_80036590;
    }
    // 0x80036568: nop

    // 0x8003656C: lh          $t9, 0x80($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X80);
    // 0x80036570: beq         $s6, $t9, L_80036590
    if (ctx->r22 == ctx->r25) {
        // 0x80036574: nop
    
            goto L_80036590;
    }
    // 0x80036574: nop

    // 0x80036578: jal         0x8000E35C
    // 0x8003657C: nop

    func_8000E35C(rdram, ctx);
        goto after_2;
    // 0x8003657C: nop

    after_2:
    // 0x80036580: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x80036584: beq         $t0, $zero, L_80036590
    if (ctx->r8 == 0) {
        // 0x80036588: nop
    
            goto L_80036590;
    }
    // 0x80036588: nop

    // 0x8003658C: sh          $s6, 0x80($s2)
    MEM_H(0X80, ctx->r18) = ctx->r22;
L_80036590:
    // 0x80036590: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80036594: lh          $t1, -0x68D2($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X68D2);
    // 0x80036598: slti        $at, $t1, 0x14
    ctx->r1 = SIGNED(ctx->r9) < 0X14 ? 1 : 0;
    // 0x8003659C: beql        $at, $zero, L_800365CC
    if (ctx->r1 == 0) {
        // 0x800365A0: lh          $t4, 0x80($s2)
        ctx->r12 = MEM_H(ctx->r18, 0X80);
            goto L_800365CC;
    }
    goto skip_4;
    // 0x800365A0: lh          $t4, 0x80($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X80);
    skip_4:
    // 0x800365A4: lh          $t2, 0x80($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X80);
    // 0x800365A8: beql        $s7, $t2, L_800365CC
    if (ctx->r23 == ctx->r10) {
        // 0x800365AC: lh          $t4, 0x80($s2)
        ctx->r12 = MEM_H(ctx->r18, 0X80);
            goto L_800365CC;
    }
    goto skip_5;
    // 0x800365AC: lh          $t4, 0x80($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X80);
    skip_5:
    // 0x800365B0: jal         0x8000E35C
    // 0x800365B4: nop

    func_8000E35C(rdram, ctx);
        goto after_3;
    // 0x800365B4: nop

    after_3:
    // 0x800365B8: andi        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 & 0X1;
    // 0x800365BC: beql        $t3, $zero, L_800365CC
    if (ctx->r11 == 0) {
        // 0x800365C0: lh          $t4, 0x80($s2)
        ctx->r12 = MEM_H(ctx->r18, 0X80);
            goto L_800365CC;
    }
    goto skip_6;
    // 0x800365C0: lh          $t4, 0x80($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X80);
    skip_6:
    // 0x800365C4: sh          $s7, 0x80($s2)
    MEM_H(0X80, ctx->r18) = ctx->r23;
L_800365C8:
    // 0x800365C8: lh          $t4, 0x80($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X80);
L_800365CC:
    // 0x800365CC: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x800365D0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800365D4: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x800365D8: jal         0x80049CFC
    // 0x800365DC: lw          $a0, -0x5C90($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5C90);
    func_80049CFC(rdram, ctx);
        goto after_4;
    // 0x800365DC: lw          $a0, -0x5C90($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5C90);
    after_4:
    // 0x800365E0: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x800365E4: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800365E8: jal         0x80049D80
    // 0x800365EC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_80049D80(rdram, ctx);
        goto after_5;
    // 0x800365EC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_5:
    // 0x800365F0: sw          $v0, 0x74($s2)
    MEM_W(0X74, ctx->r18) = ctx->r2;
    // 0x800365F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800365F8: jal         0x80049DFC
    // 0x800365FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80049DFC(rdram, ctx);
        goto after_6;
    // 0x800365FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80036600: sw          $v0, 0x78($s2)
    MEM_W(0X78, ctx->r18) = ctx->r2;
    // 0x80036604: jal         0x8004A148
    // 0x80036608: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8004A148(rdram, ctx);
        goto after_7;
    // 0x80036608: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x8003660C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80036610: lwc1        $f4, 0x7258($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7258);
    // 0x80036614: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80036618: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003661C: lwc1        $f6, 0xC($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80036620: lh          $t9, 0x80($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X80);
    // 0x80036624: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80036628: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8003662C: addiu       $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
    // 0x80036630: swc1        $f4, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f4.u32l;
    // 0x80036634: swc1        $f10, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f10.u32l;
    // 0x80036638: lwc1        $f16, 0xC($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8003663C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80036640: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x80036644: bne         $t9, $at, L_80036654
    if (ctx->r25 != ctx->r1) {
        // 0x80036648: sh          $t8, 0x8C($s2)
        MEM_H(0X8C, ctx->r18) = ctx->r24;
            goto L_80036654;
    }
    // 0x80036648: sh          $t8, 0x8C($s2)
    MEM_H(0X8C, ctx->r18) = ctx->r24;
    // 0x8003664C: b           L_80036668
    // 0x80036650: sh          $t0, 0x8A($s2)
    MEM_H(0X8A, ctx->r18) = ctx->r8;
        goto L_80036668;
    // 0x80036650: sh          $t0, 0x8A($s2)
    MEM_H(0X8A, ctx->r18) = ctx->r8;
L_80036654:
    // 0x80036654: jal         0x8000E35C
    // 0x80036658: nop

    func_8000E35C(rdram, ctx);
        goto after_8;
    // 0x80036658: nop

    after_8:
    // 0x8003665C: andi        $t1, $v0, 0x3F
    ctx->r9 = ctx->r2 & 0X3F;
    // 0x80036660: addiu       $t2, $t1, 0x14
    ctx->r10 = ADD32(ctx->r9, 0X14);
    // 0x80036664: sh          $t2, 0x8A($s2)
    MEM_H(0X8A, ctx->r18) = ctx->r10;
L_80036668:
    // 0x80036668: addiu       $t3, $zero, 0x32
    ctx->r11 = ADD32(0, 0X32);
    // 0x8003666C: sh          $zero, 0x88($s2)
    MEM_H(0X88, ctx->r18) = 0;
    // 0x80036670: sh          $s7, 0x86($s2)
    MEM_H(0X86, ctx->r18) = ctx->r23;
    // 0x80036674: sh          $t3, 0x2E($s2)
    MEM_H(0X2E, ctx->r18) = ctx->r11;
    // 0x80036678: sh          $s6, 0x82($s2)
    MEM_H(0X82, ctx->r18) = ctx->r22;
    // 0x8003667C: lh          $v0, 0x8A($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X8A);
L_80036680:
    // 0x80036680: addiu       $a0, $s2, 0x8
    ctx->r4 = ADD32(ctx->r18, 0X8);
    // 0x80036684: beq         $v0, $zero, L_80036694
    if (ctx->r2 == 0) {
        // 0x80036688: addiu       $t4, $v0, -0x1
        ctx->r12 = ADD32(ctx->r2, -0X1);
            goto L_80036694;
    }
    // 0x80036688: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x8003668C: b           L_80036814
    // 0x80036690: sh          $t4, 0x8A($s2)
    MEM_H(0X8A, ctx->r18) = ctx->r12;
        goto L_80036814;
    // 0x80036690: sh          $t4, 0x8A($s2)
    MEM_H(0X8A, ctx->r18) = ctx->r12;
L_80036694:
    // 0x80036694: jal         0x80043EF0
    // 0x80036698: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80043EF0(rdram, ctx);
        goto after_9;
    // 0x80036698: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x8003669C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800366A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800366A4: sh          $s7, 0x82($s2)
    MEM_H(0X82, ctx->r18) = ctx->r23;
    // 0x800366A8: b           L_80036814
    // 0x800366AC: swc1        $f4, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->f4.u32l;
        goto L_80036814;
    // 0x800366AC: swc1        $f4, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->f4.u32l;
    // 0x800366B0: lwc1        $f0, 0x40($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X40);
L_800366B4:
    // 0x800366B4: lwc1        $f6, 0xC($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0XC);
    // 0x800366B8: lh          $t5, 0x8C($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X8C);
    // 0x800366BC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800366C0: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800366C4: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x800366C8: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x800366CC: swc1        $f8, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f8.u32l;
    // 0x800366D0: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800366D4: ldc1        $f16, 0x7260($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, 0X7260);
    // 0x800366D8: lwc1        $f8, 0xC($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0XC);
    // 0x800366DC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800366E0: sub.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d - ctx->f16.d;
    // 0x800366E4: c.le.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl <= ctx->f2.fl;
    // 0x800366E8: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x800366EC: bc1f        L_80036758
    if (!c1cs) {
        // 0x800366F0: swc1        $f4, 0x40($s2)
        MEM_W(0X40, ctx->r18) = ctx->f4.u32l;
            goto L_80036758;
    }
    // 0x800366F0: swc1        $f4, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->f4.u32l;
    // 0x800366F4: lwc1        $f10, 0x40($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X40);
    // 0x800366F8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800366FC: swc1        $f2, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f2.u32l;
    // 0x80036700: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80036704: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x80036708: swc1        $f4, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->f4.u32l;
    // 0x8003670C: lwc1        $f6, 0x40($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X40);
    // 0x80036710: c.lt.s      $f6, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f6.fl < ctx->f22.fl;
    // 0x80036714: nop

    // 0x80036718: bc1fl       L_8003675C
    if (!c1cs) {
        // 0x8003671C: lh          $t0, 0x80($s2)
        ctx->r8 = MEM_H(ctx->r18, 0X80);
            goto L_8003675C;
    }
    goto skip_7;
    // 0x8003671C: lh          $t0, 0x80($s2)
    ctx->r8 = MEM_H(ctx->r18, 0X80);
    skip_7:
    // 0x80036720: lh          $v0, 0x86($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X86);
    // 0x80036724: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x80036728: beq         $v0, $zero, L_80036740
    if (ctx->r2 == 0) {
        // 0x8003672C: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80036740;
    }
    // 0x8003672C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80036730: sh          $t6, 0x86($s2)
    MEM_H(0X86, ctx->r18) = ctx->r14;
    // 0x80036734: sh          $t7, 0x8A($s2)
    MEM_H(0X8A, ctx->r18) = ctx->r15;
    // 0x80036738: b           L_80036758
    // 0x8003673C: sh          $s6, 0x82($s2)
    MEM_H(0X82, ctx->r18) = ctx->r22;
        goto L_80036758;
    // 0x8003673C: sh          $s6, 0x82($s2)
    MEM_H(0X82, ctx->r18) = ctx->r22;
L_80036740:
    // 0x80036740: lh          $t8, 0x84($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X84);
    // 0x80036744: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80036748: bnel        $t8, $zero, L_80036758
    if (ctx->r24 != 0) {
        // 0x8003674C: sh          $s4, 0x82($s2)
        MEM_H(0X82, ctx->r18) = ctx->r20;
            goto L_80036758;
    }
    goto skip_8;
    // 0x8003674C: sh          $s4, 0x82($s2)
    MEM_H(0X82, ctx->r18) = ctx->r20;
    skip_8:
    // 0x80036750: sh          $t9, 0x84($s2)
    MEM_H(0X84, ctx->r18) = ctx->r25;
    // 0x80036754: sh          $s4, 0x82($s2)
    MEM_H(0X82, ctx->r18) = ctx->r20;
L_80036758:
    // 0x80036758: lh          $t0, 0x80($s2)
    ctx->r8 = MEM_H(ctx->r18, 0X80);
L_8003675C:
    // 0x8003675C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80036760: bne         $t0, $at, L_80036814
    if (ctx->r8 != ctx->r1) {
        // 0x80036764: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80036814;
    }
    // 0x80036764: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80036768: lwc1        $f8, -0x6A14($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6A14);
    // 0x8003676C: lwc1        $f10, 0xC($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80036770: addiu       $s3, $s2, 0x8
    ctx->r19 = ADD32(ctx->r18, 0X8);
    // 0x80036774: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80036778: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8003677C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80036780: bc1fl       L_80036818
    if (!c1cs) {
        // 0x80036784: lh          $v0, 0x84($s2)
        ctx->r2 = MEM_H(ctx->r18, 0X84);
            goto L_80036818;
    }
    goto skip_9;
    // 0x80036784: lh          $v0, 0x84($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X84);
    skip_9:
    // 0x80036788: jal         0x80042F80
    // 0x8003678C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80042F80(rdram, ctx);
        goto after_10;
    // 0x8003678C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x80036790: jal         0x80044480
    // 0x80036794: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80044480(rdram, ctx);
        goto after_11;
    // 0x80036794: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_11:
    // 0x80036798: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8003679C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800367A0: addiu       $a2, $a2, -0x6A18
    ctx->r6 = ADD32(ctx->r6, -0X6A18);
    // 0x800367A4: jal         0x8000CAA4
    // 0x800367A8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_8000CAA4(rdram, ctx);
        goto after_12;
    // 0x800367A8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_12:
    // 0x800367AC: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x800367B0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800367B4: sub.d       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f20.d); 
    ctx->f18.d = ctx->f16.d - ctx->f20.d;
    // 0x800367B8: addiu       $s1, $s2, 0x14
    ctx->r17 = ADD32(ctx->r18, 0X14);
    // 0x800367BC: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x800367C0: swc1        $f4, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f4.u32l;
L_800367C4:
    // 0x800367C4: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800367C8: sra         $t1, $a0, 16
    ctx->r9 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800367CC: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800367D0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800367D4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800367D8: jal         0x8003F3A4
    // 0x800367DC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8003F3A4(rdram, ctx);
        goto after_13;
    // 0x800367DC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_13:
    // 0x800367E0: lwc1        $f6, 0x18($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X18);
    // 0x800367E4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800367E8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800367EC: add.d       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = ctx->f8.d + ctx->f20.d;
    // 0x800367F0: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x800367F4: bne         $s0, $s4, L_800367C4
    if (ctx->r16 != ctx->r20) {
        // 0x800367F8: swc1        $f16, 0x18($s2)
        MEM_W(0X18, ctx->r18) = ctx->f16.u32l;
            goto L_800367C4;
    }
    // 0x800367F8: swc1        $f16, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f16.u32l;
    // 0x800367FC: lh          $t2, 0x84($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X84);
    // 0x80036800: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80036804: bnel        $t2, $zero, L_80036814
    if (ctx->r10 != 0) {
        // 0x80036808: sh          $s4, 0x82($s2)
        MEM_H(0X82, ctx->r18) = ctx->r20;
            goto L_80036814;
    }
    goto skip_10;
    // 0x80036808: sh          $s4, 0x82($s2)
    MEM_H(0X82, ctx->r18) = ctx->r20;
    skip_10:
    // 0x8003680C: sh          $t3, 0x84($s2)
    MEM_H(0X84, ctx->r18) = ctx->r11;
    // 0x80036810: sh          $s4, 0x82($s2)
    MEM_H(0X82, ctx->r18) = ctx->r20;
L_80036814:
    // 0x80036814: lh          $v0, 0x84($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X84);
L_80036818:
    // 0x80036818: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8003681C: bnel        $v0, $at, L_8003687C
    if (ctx->r2 != ctx->r1) {
        // 0x80036820: lh          $t7, 0x2E($s2)
        ctx->r15 = MEM_H(ctx->r18, 0X2E);
            goto L_8003687C;
    }
    goto skip_11;
    // 0x80036820: lh          $t7, 0x2E($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X2E);
    skip_11:
    // 0x80036824: lh          $t4, 0x88($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X88);
    // 0x80036828: addiu       $s3, $s2, 0x8
    ctx->r19 = ADD32(ctx->r18, 0X8);
    // 0x8003682C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80036830: bne         $t4, $zero, L_80036868
    if (ctx->r12 != 0) {
        // 0x80036834: addiu       $a1, $zero, 0x8
        ctx->r5 = ADD32(0, 0X8);
            goto L_80036868;
    }
    // 0x80036834: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80036838: jal         0x80042F80
    // 0x8003683C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80042F80(rdram, ctx);
        goto after_14;
    // 0x8003683C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_14:
    // 0x80036840: sll         $a1, $s4, 16
    ctx->r5 = S32(ctx->r20 << 16);
    // 0x80036844: sra         $t5, $a1, 16
    ctx->r13 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80036848: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x8003684C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80036850: jal         0x80043714
    // 0x80036854: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80043714(rdram, ctx);
        goto after_15;
    // 0x80036854: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_15:
    // 0x80036858: lh          $t6, 0x80($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X80);
    // 0x8003685C: bne         $t6, $zero, L_80036868
    if (ctx->r14 != 0) {
        // 0x80036860: nop
    
            goto L_80036868;
    }
    // 0x80036860: nop

    // 0x80036864: sh          $zero, 0x0($fp)
    MEM_H(0X0, ctx->r30) = 0;
L_80036868:
    // 0x80036868: jal         0x80036320
    // 0x8003686C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80036320(rdram, ctx);
        goto after_16;
    // 0x8003686C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_16:
    // 0x80036870: b           L_80036B6C
    // 0x80036874: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
        goto L_80036B6C;
    // 0x80036874: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80036878: lh          $t7, 0x2E($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X2E);
L_8003687C:
    // 0x8003687C: addiu       $a0, $sp, 0xB0
    ctx->r4 = ADD32(ctx->r29, 0XB0);
    // 0x80036880: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80036884: blez        $t7, L_80036B50
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80036888: addiu       $s3, $s2, 0x8
        ctx->r19 = ADD32(ctx->r18, 0X8);
            goto L_80036B50;
    }
    // 0x80036888: addiu       $s3, $s2, 0x8
    ctx->r19 = ADD32(ctx->r18, 0X8);
    // 0x8003688C: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80036890: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80036894: jal         0x80049840
    // 0x80036898: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    func_80049840(rdram, ctx);
        goto after_17;
    // 0x80036898: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_17:
    // 0x8003689C: lwc1        $f0, 0x24($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X24);
    // 0x800368A0: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x800368A4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800368A8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800368AC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800368B0: jal         0x80001AB4
    // 0x800368B4: nop

    func_80001AB4(rdram, ctx);
        goto after_18;
    // 0x800368B4: nop

    after_18:
    // 0x800368B8: lw          $t8, 0x78($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X78);
    // 0x800368BC: addiu       $a1, $sp, 0xB0
    ctx->r5 = ADD32(ctx->r29, 0XB0);
    // 0x800368C0: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    // 0x800368C4: lw          $a0, 0x8($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X8);
    // 0x800368C8: jal         0x80000BD8
    // 0x800368CC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80000BD8(rdram, ctx);
        goto after_19;
    // 0x800368CC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_19:
    // 0x800368D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800368D4: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
L_800368D8:
    // 0x800368D8: lw          $t9, 0x78($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X78);
    // 0x800368DC: lwc1        $f18, 0x8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800368E0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800368E4: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x800368E8: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x800368EC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800368F0: bne         $v0, $s5, L_800368D8
    if (ctx->r2 != ctx->r21) {
        // 0x800368F4: swc1        $f18, 0x40($t1)
        MEM_W(0X40, ctx->r9) = ctx->f18.u32l;
            goto L_800368D8;
    }
    // 0x800368F4: swc1        $f18, 0x40($t1)
    MEM_W(0X40, ctx->r9) = ctx->f18.u32l;
    // 0x800368F8: jal         0x8000E074
    // 0x800368FC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_8000E074(rdram, ctx);
        goto after_20;
    // 0x800368FC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_20:
    // 0x80036900: beq         $v0, $zero, L_80036920
    if (ctx->r2 == 0) {
        // 0x80036904: lui         $t8, 0x8013
        ctx->r24 = S32(0X8013 << 16);
            goto L_80036920;
    }
    // 0x80036904: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80036908: lw          $t2, 0x78($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X78);
    // 0x8003690C: lw          $v0, 0x8($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X8);
    // 0x80036910: lw          $t3, 0xD8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XD8);
    // 0x80036914: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x80036918: b           L_80036938
    // 0x8003691C: sw          $t4, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r12;
        goto L_80036938;
    // 0x8003691C: sw          $t4, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r12;
L_80036920:
    // 0x80036920: lw          $t5, 0x78($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X78);
    // 0x80036924: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80036928: lw          $v0, 0x8($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X8);
    // 0x8003692C: lw          $t6, 0xD8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XD8);
    // 0x80036930: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80036934: sw          $t7, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r15;
L_80036938:
    // 0x80036938: lh          $t8, -0x68E4($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X68E4);
    // 0x8003693C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80036940: addiu       $a0, $a0, -0x6A18
    ctx->r4 = ADD32(ctx->r4, -0X6A18);
    // 0x80036944: bnel        $t8, $zero, L_80036B6C
    if (ctx->r24 != 0) {
        // 0x80036948: lw          $v0, 0x0($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X0);
            goto L_80036B6C;
    }
    goto skip_12;
    // 0x80036948: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    skip_12:
    // 0x8003694C: jal         0x80003668
    // 0x80036950: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_80003668(rdram, ctx);
        goto after_21;
    // 0x80036950: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_21:
    // 0x80036954: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80036958: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003695C: nop

    // 0x80036960: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80036964: nop

    // 0x80036968: bc1fl       L_80036B6C
    if (!c1cs) {
        // 0x8003696C: lw          $v0, 0x0($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X0);
            goto L_80036B6C;
    }
    goto skip_13;
    // 0x8003696C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    skip_13:
    // 0x80036970: lh          $t9, 0x84($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X84);
    // 0x80036974: sh          $s6, 0x88($s2)
    MEM_H(0X88, ctx->r18) = ctx->r22;
    // 0x80036978: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8003697C: bnel        $t9, $zero, L_8003698C
    if (ctx->r25 != 0) {
        // 0x80036980: lh          $v1, 0x80($s2)
        ctx->r3 = MEM_H(ctx->r18, 0X80);
            goto L_8003698C;
    }
    goto skip_14;
    // 0x80036980: lh          $v1, 0x80($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X80);
    skip_14:
    // 0x80036984: sh          $t0, 0x84($s2)
    MEM_H(0X84, ctx->r18) = ctx->r8;
    // 0x80036988: lh          $v1, 0x80($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X80);
L_8003698C:
    // 0x8003698C: sh          $s4, 0x82($s2)
    MEM_H(0X82, ctx->r18) = ctx->r20;
    // 0x80036990: sltiu       $at, $v1, 0x5
    ctx->r1 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x80036994: beq         $at, $zero, L_80036AD0
    if (ctx->r1 == 0) {
        // 0x80036998: sll         $t1, $v1, 2
        ctx->r9 = S32(ctx->r3 << 2);
            goto L_80036AD0;
    }
    // 0x80036998: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x8003699C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800369A0: addu        $at, $at, $t1
    gpr jr_addend_800369A8 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800369A4: lw          $t1, 0x7268($at)
    ctx->r9 = ADD32(ctx->r1, 0X7268);
    // 0x800369A8: jr          $t1
    // 0x800369AC: nop

    switch (jr_addend_800369A8 >> 2) {
        case 0: goto L_800369B0; break;
        case 1: goto L_800369E8; break;
        case 2: goto L_80036A24; break;
        case 3: goto L_80036A60; break;
        case 4: goto L_80036A98; break;
        default: switch_error(__func__, 0x800369A8, 0x80077268);
    }
    // 0x800369AC: nop

L_800369B0:
    // 0x800369B0: lh          $t3, 0x0($fp)
    ctx->r11 = MEM_H(ctx->r30, 0X0);
    // 0x800369B4: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800369B8: lw          $t2, -0x6BDC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X6BDC);
    // 0x800369BC: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x800369C0: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x800369C4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800369C8: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800369CC: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x800369D0: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800369D4: addiu       $t6, $t5, 0x3E8
    ctx->r14 = ADD32(ctx->r13, 0X3E8);
    // 0x800369D8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800369DC: sw          $t6, -0x6BDC($at)
    MEM_W(-0X6BDC, ctx->r1) = ctx->r14;
    // 0x800369E0: b           L_80036AD0
    // 0x800369E4: lh          $v1, 0x80($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X80);
        goto L_80036AD0;
    // 0x800369E4: lh          $v1, 0x80($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X80);
L_800369E8:
    // 0x800369E8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800369EC: lh          $t7, -0x6938($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X6938);
    // 0x800369F0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800369F4: lh          $v0, -0x6934($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X6934);
    // 0x800369F8: addiu       $t8, $t7, 0x64
    ctx->r24 = ADD32(ctx->r15, 0X64);
    // 0x800369FC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80036A00: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80036A04: sh          $t8, -0x6938($at)
    MEM_H(-0X6938, ctx->r1) = ctx->r24;
    // 0x80036A08: sra         $t0, $t9, 16
    ctx->r8 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80036A0C: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80036A10: beq         $at, $zero, L_80036A1C
    if (ctx->r1 == 0) {
        // 0x80036A14: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80036A1C;
    }
    // 0x80036A14: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80036A18: sh          $v0, -0x6938($at)
    MEM_H(-0X6938, ctx->r1) = ctx->r2;
L_80036A1C:
    // 0x80036A1C: b           L_80036AD0
    // 0x80036A20: lh          $v1, 0x80($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X80);
        goto L_80036AD0;
    // 0x80036A20: lh          $v1, 0x80($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X80);
L_80036A24:
    // 0x80036A24: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80036A28: lw          $v1, -0x68DC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X68DC);
    // 0x80036A2C: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x80036A30: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80036A34: ori         $at, $at, 0xBF20
    ctx->r1 = ctx->r1 | 0XBF20;
    // 0x80036A38: lw          $v0, -0x68D8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68D8);
    // 0x80036A3C: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x80036A40: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80036A44: sw          $v1, -0x68DC($at)
    MEM_W(-0X68DC, ctx->r1) = ctx->r3;
    // 0x80036A48: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80036A4C: beq         $at, $zero, L_80036A58
    if (ctx->r1 == 0) {
        // 0x80036A50: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80036A58;
    }
    // 0x80036A50: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80036A54: sw          $v0, -0x68DC($at)
    MEM_W(-0X68DC, ctx->r1) = ctx->r2;
L_80036A58:
    // 0x80036A58: b           L_80036AD0
    // 0x80036A5C: lh          $v1, 0x80($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X80);
        goto L_80036AD0;
    // 0x80036A5C: lh          $v1, 0x80($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X80);
L_80036A60:
    // 0x80036A60: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80036A64: lh          $v0, -0x68DE($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X68DE);
    // 0x80036A68: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80036A6C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80036A70: sll         $t1, $v0, 16
    ctx->r9 = S32(ctx->r2 << 16);
    // 0x80036A74: sra         $t3, $t1, 16
    ctx->r11 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80036A78: sh          $t3, -0x68DE($at)
    MEM_H(-0X68DE, ctx->r1) = ctx->r11;
    // 0x80036A7C: slti        $at, $t3, 0x5
    ctx->r1 = SIGNED(ctx->r11) < 0X5 ? 1 : 0;
    // 0x80036A80: bne         $at, $zero, L_80036A90
    if (ctx->r1 != 0) {
        // 0x80036A84: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_80036A90;
    }
    // 0x80036A84: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80036A88: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80036A8C: sh          $v0, -0x68DE($at)
    MEM_H(-0X68DE, ctx->r1) = ctx->r2;
L_80036A90:
    // 0x80036A90: b           L_80036AD0
    // 0x80036A94: lh          $v1, 0x80($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X80);
        goto L_80036AD0;
    // 0x80036A94: lh          $v1, 0x80($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X80);
L_80036A98:
    // 0x80036A98: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80036A9C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80036AA0: jal         0x80042F80
    // 0x80036AA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80042F80(rdram, ctx);
        goto after_22;
    // 0x80036AA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_22:
    // 0x80036AA8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80036AAC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80036AB0: jal         0x80043714
    // 0x80036AB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80043714(rdram, ctx);
        goto after_23;
    // 0x80036AB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_23:
    // 0x80036AB8: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80036ABC: lh          $t2, -0x6938($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X6938);
    // 0x80036AC0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80036AC4: addiu       $t4, $t2, -0x64
    ctx->r12 = ADD32(ctx->r10, -0X64);
    // 0x80036AC8: sh          $t4, -0x6938($at)
    MEM_H(-0X6938, ctx->r1) = ctx->r12;
    // 0x80036ACC: lh          $v1, 0x80($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X80);
L_80036AD0:
    // 0x80036AD0: bne         $v1, $zero, L_80036AE8
    if (ctx->r3 != 0) {
        // 0x80036AD4: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80036AE8;
    }
    // 0x80036AD4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80036AD8: lh          $t5, 0x0($fp)
    ctx->r13 = MEM_H(ctx->r30, 0X0);
    // 0x80036ADC: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80036AE0: b           L_80036AEC
    // 0x80036AE4: sh          $t6, 0x0($fp)
    MEM_H(0X0, ctx->r30) = ctx->r14;
        goto L_80036AEC;
    // 0x80036AE4: sh          $t6, 0x0($fp)
    MEM_H(0X0, ctx->r30) = ctx->r14;
L_80036AE8:
    // 0x80036AE8: sh          $zero, 0x0($fp)
    MEM_H(0X0, ctx->r30) = 0;
L_80036AEC:
    // 0x80036AEC: lh          $t7, 0x80($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X80);
    // 0x80036AF0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80036AF4: beql        $t7, $at, L_80036B6C
    if (ctx->r15 == ctx->r1) {
        // 0x80036AF8: lw          $v0, 0x0($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X0);
            goto L_80036B6C;
    }
    goto skip_15;
    // 0x80036AF8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    skip_15:
    // 0x80036AFC: jal         0x80043EF0
    // 0x80036B00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80043EF0(rdram, ctx);
        goto after_24;
    // 0x80036B00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_24:
    // 0x80036B04: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80036B08: addiu       $a0, $a0, -0x6A20
    ctx->r4 = ADD32(ctx->r4, -0X6A20);
    // 0x80036B0C: jal         0x80044614
    // 0x80036B10: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80044614(rdram, ctx);
        goto after_25;
    // 0x80036B10: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_25:
    // 0x80036B14: jal         0x80044480
    // 0x80036B18: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    func_80044480(rdram, ctx);
        goto after_26;
    // 0x80036B18: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    after_26:
    // 0x80036B1C: sll         $a2, $s6, 16
    ctx->r6 = S32(ctx->r22 << 16);
    // 0x80036B20: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80036B24: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80036B28: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80036B2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80036B30: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80036B34: jal         0x8000ACEC
    // 0x80036B38: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8000ACEC(rdram, ctx);
        goto after_27;
    // 0x80036B38: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_27:
    // 0x80036B3C: lh          $t9, 0x80($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X80);
    // 0x80036B40: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80036B44: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80036B48: b           L_80036B68
    // 0x80036B4C: sh          $t0, -0x65AC($at)
    MEM_H(-0X65AC, ctx->r1) = ctx->r8;
        goto L_80036B68;
    // 0x80036B4C: sh          $t0, -0x65AC($at)
    MEM_H(-0X65AC, ctx->r1) = ctx->r8;
L_80036B50:
    // 0x80036B50: bnel        $v0, $zero, L_80036B6C
    if (ctx->r2 != 0) {
        // 0x80036B54: lw          $v0, 0x0($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X0);
            goto L_80036B6C;
    }
    goto skip_16;
    // 0x80036B54: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    skip_16:
    // 0x80036B58: bne         $v0, $zero, L_80036B64
    if (ctx->r2 != 0) {
        // 0x80036B5C: addiu       $t1, $zero, -0x1
        ctx->r9 = ADD32(0, -0X1);
            goto L_80036B64;
    }
    // 0x80036B5C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80036B60: sh          $t1, 0x84($s2)
    MEM_H(0X84, ctx->r18) = ctx->r9;
L_80036B64:
    // 0x80036B64: sh          $s4, 0x82($s2)
    MEM_H(0X82, ctx->r18) = ctx->r20;
L_80036B68:
    // 0x80036B68: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
L_80036B6C:
    // 0x80036B6C: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80036B70: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80036B74: bnel        $t3, $zero, L_800363EC
    if (ctx->r11 != 0) {
        // 0x80036B78: lh          $v1, 0x82($s2)
        ctx->r3 = MEM_H(ctx->r18, 0X82);
            goto L_800363EC;
    }
    goto skip_17;
    // 0x80036B78: lh          $v1, 0x82($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X82);
    skip_17:
L_80036B7C:
    // 0x80036B7C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80036B80: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80036B84: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80036B88: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80036B8C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80036B90: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80036B94: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80036B98: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80036B9C: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80036BA0: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80036BA4: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x80036BA8: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x80036BAC: jr          $ra
    // 0x80036BB0: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
    TRACE_RETURN()
    return;
    // 0x80036BB0: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
;}
RECOMP_FUNC void func_80036BB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80036BB4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80036BB8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80036BBC: lw          $a1, -0x6600($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6600);
    // 0x80036BC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80036BC4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80036BC8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80036BCC: lw          $s0, 0x0($a1)
    ctx->r16 = MEM_W(ctx->r5, 0X0);
    // 0x80036BD0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80036BD4: beq         $t6, $zero, L_80036C00
    if (ctx->r14 == 0) {
        // 0x80036BD8: nop
    
            goto L_80036C00;
    }
    // 0x80036BD8: nop

    // 0x80036BDC: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
L_80036BE0:
    // 0x80036BE0: jal         0x80036320
    // 0x80036BE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80036320(rdram, ctx);
        goto after_0;
    // 0x80036BE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80036BE8: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80036BEC: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80036BF0: bnel        $t7, $zero, L_80036BE0
    if (ctx->r15 != 0) {
        // 0x80036BF4: lw          $s1, 0x0($s0)
        ctx->r17 = MEM_W(ctx->r16, 0X0);
            goto L_80036BE0;
    }
    goto skip_0;
    // 0x80036BF4: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x80036BF8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80036BFC: lw          $a1, -0x6600($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6600);
L_80036C00:
    // 0x80036C00: lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // 0x80036C04: addiu       $s0, $s0, 0x2800
    ctx->r16 = ADD32(ctx->r16, 0X2800);
    // 0x80036C08: jal         0x800042A8
    // 0x80036C0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800042A8(rdram, ctx);
        goto after_1;
    // 0x80036C0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80036C10: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80036C14: lw          $a1, -0x65FC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X65FC);
    // 0x80036C18: jal         0x800042A8
    // 0x80036C1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800042A8(rdram, ctx);
        goto after_2;
    // 0x80036C1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80036C20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80036C24: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80036C28: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80036C2C: jr          $ra
    // 0x80036C30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    TRACE_RETURN()
    return;
    // 0x80036C30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80036C34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80036C34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80036C38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036C3C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80036C40: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80036C44: jal         0x80004364
    // 0x80036C48: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x80036C48: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_0:
    // 0x80036C4C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80036C50: addiu       $v1, $v1, -0x6608
    ctx->r3 = ADD32(ctx->r3, -0X6608);
    // 0x80036C54: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80036C58: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80036C5C: jal         0x8000C7C0
    // 0x80036C60: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    func_8000C7C0(rdram, ctx);
        goto after_1;
    // 0x80036C60: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_1:
    // 0x80036C64: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80036C68: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80036C6C: jal         0x80004364
    // 0x80036C70: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    func_80004364(rdram, ctx);
        goto after_2;
    // 0x80036C70: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_2:
    // 0x80036C74: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80036C78: addiu       $v1, $v1, -0x6604
    ctx->r3 = ADD32(ctx->r3, -0X6604);
    // 0x80036C7C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80036C80: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80036C84: jal         0x8000C7C0
    // 0x80036C88: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    func_8000C7C0(rdram, ctx);
        goto after_3;
    // 0x80036C88: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_3:
    // 0x80036C8C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80036C90: addiu       $v0, $v0, -0x6608
    ctx->r2 = ADD32(ctx->r2, -0X6608);
    // 0x80036C94: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80036C98: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80036C9C: addiu       $v1, $v1, -0x6604
    ctx->r3 = ADD32(ctx->r3, -0X6604);
    // 0x80036CA0: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x80036CA4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80036CA8: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x80036CAC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80036CB0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80036CB4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80036CB8: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x80036CBC: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80036CC0: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x80036CC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80036CC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80036CCC: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80036CD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80036CD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80036CD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80036CDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036CE0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80036CE4: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80036CE8: jal         0x80004364
    // 0x80036CEC: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x80036CEC: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_0:
    // 0x80036CF0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80036CF4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80036CF8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80036CFC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80036D00: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
L_80036D04:
    // 0x80036D04: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80036D08: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80036D0C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80036D10: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80036D14: bne         $v1, $a2, L_80036D04
    if (ctx->r3 != ctx->r6) {
        // 0x80036D18: swc1        $f4, 0x4($a1)
        MEM_W(0X4, ctx->r5) = ctx->f4.u32l;
            goto L_80036D04;
    }
    // 0x80036D18: swc1        $f4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f4.u32l;
    // 0x80036D1C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80036D20: addiu       $v1, $v1, -0x6604
    ctx->r3 = ADD32(ctx->r3, -0X6604);
    // 0x80036D24: sh          $zero, 0x14($a3)
    MEM_H(0X14, ctx->r7) = 0;
    // 0x80036D28: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80036D2C: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x80036D30: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80036D34: sw          $a3, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r7;
    // 0x80036D38: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80036D3C: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80036D40: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x80036D44: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80036D48: sw          $t0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r8;
    // 0x80036D4C: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x80036D50: sw          $a3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r7;
    // 0x80036D54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80036D58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80036D5C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80036D64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80036D64: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80036D68: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80036D6C: lw          $a1, -0x6608($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6608);
    // 0x80036D70: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80036D74: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80036D78: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80036D7C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80036D80: lw          $s0, 0x0($a1)
    ctx->r16 = MEM_W(ctx->r5, 0X0);
    // 0x80036D84: lui         $s2, 0x801A
    ctx->r18 = S32(0X801A << 16);
    // 0x80036D88: addiu       $s2, $s2, 0x2800
    ctx->r18 = ADD32(ctx->r18, 0X2800);
    // 0x80036D8C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80036D90: beq         $t6, $zero, L_80036DD4
    if (ctx->r14 == 0) {
        // 0x80036D94: nop
    
            goto L_80036DD4;
    }
    // 0x80036D94: nop

    // 0x80036D98: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
L_80036D9C:
    // 0x80036D9C: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x80036DA0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80036DA4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80036DA8: sw          $s1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r17;
    // 0x80036DAC: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80036DB0: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x80036DB4: jal         0x800042A8
    // 0x80036DB8: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    func_800042A8(rdram, ctx);
        goto after_0;
    // 0x80036DB8: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    after_0:
    // 0x80036DBC: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80036DC0: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80036DC4: bnel        $t0, $zero, L_80036D9C
    if (ctx->r8 != 0) {
        // 0x80036DC8: lw          $s1, 0x0($s0)
        ctx->r17 = MEM_W(ctx->r16, 0X0);
            goto L_80036D9C;
    }
    goto skip_0;
    // 0x80036DC8: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x80036DCC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80036DD0: lw          $a1, -0x6608($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6608);
L_80036DD4:
    // 0x80036DD4: lui         $s2, 0x801A
    ctx->r18 = S32(0X801A << 16);
    // 0x80036DD8: addiu       $s2, $s2, 0x2800
    ctx->r18 = ADD32(ctx->r18, 0X2800);
    // 0x80036DDC: jal         0x800042A8
    // 0x80036DE0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800042A8(rdram, ctx);
        goto after_1;
    // 0x80036DE0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x80036DE4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80036DE8: lw          $a1, -0x6604($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6604);
    // 0x80036DEC: jal         0x800042A8
    // 0x80036DF0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800042A8(rdram, ctx);
        goto after_2;
    // 0x80036DF0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x80036DF4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80036DF8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80036DFC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80036E00: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80036E04: jr          $ra
    // 0x80036E08: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    TRACE_RETURN()
    return;
    // 0x80036E08: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80036E0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80036E0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80036E10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036E14: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80036E18: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x80036E1C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80036E20: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80036E24: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80036E28: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x80036E2C: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x80036E30: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80036E34: jal         0x8004A0C4
    // 0x80036E38: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_8004A0C4(rdram, ctx);
        goto after_0;
    // 0x80036E38: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80036E3C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80036E40: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80036E44: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80036E48: lh          $t0, 0x2C($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X2C);
    // 0x80036E4C: beq         $t0, $zero, L_80036E64
    if (ctx->r8 == 0) {
        // 0x80036E50: nop
    
            goto L_80036E64;
    }
    // 0x80036E50: nop

    // 0x80036E54: lw          $a1, 0x28($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X28);
    // 0x80036E58: jal         0x800042A8
    // 0x80036E5C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800042A8(rdram, ctx);
        goto after_1;
    // 0x80036E5C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x80036E60: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_80036E64:
    // 0x80036E64: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80036E68: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80036E6C: jal         0x800042A8
    // 0x80036E70: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800042A8(rdram, ctx);
        goto after_2;
    // 0x80036E70: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_2:
    // 0x80036E74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80036E78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80036E7C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80036E84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80036E84: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80036E88: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80036E8C: lw          $t6, -0x6608($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6608);
    // 0x80036E90: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80036E94: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80036E98: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80036E9C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80036EA0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80036EA4: lw          $s0, 0x0($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X0);
    // 0x80036EA8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80036EAC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80036EB0: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80036EB4: lwc1        $f20, 0x30($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80036EB8: beq         $t7, $zero, L_80036F08
    if (ctx->r15 == 0) {
        // 0x80036EBC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80036F08;
    }
    // 0x80036EBC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80036EC0:
    // 0x80036EC0: jal         0x8000C8E8
    // 0x80036EC4: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    func_8000C8E8(rdram, ctx);
        goto after_0;
    // 0x80036EC4: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    after_0:
    // 0x80036EC8: bnel        $s1, $zero, L_80036EE0
    if (ctx->r17 != 0) {
        // 0x80036ECC: c.lt.s      $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
            goto L_80036EE0;
    }
    goto skip_0;
    // 0x80036ECC: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    skip_0:
    // 0x80036ED0: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x80036ED4: b           L_80036EF4
    // 0x80036ED8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
        goto L_80036EF4;
    // 0x80036ED8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80036EDC: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
L_80036EE0:
    // 0x80036EE0: nop

    // 0x80036EE4: bc1fl       L_80036EF8
    if (!c1cs) {
        // 0x80036EE8: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80036EF8;
    }
    goto skip_1;
    // 0x80036EE8: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x80036EEC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80036EF0: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
L_80036EF4:
    // 0x80036EF4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_80036EF8:
    // 0x80036EF8: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80036EFC: bnel        $t8, $zero, L_80036EC0
    if (ctx->r24 != 0) {
        // 0x80036F00: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80036EC0;
    }
    goto skip_2;
    // 0x80036F00: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_2:
    // 0x80036F04: swc1        $f20, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f20.u32l;
L_80036F08:
    // 0x80036F08: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80036F0C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80036F10: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80036F14: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80036F18: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80036F1C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80036F20: jr          $ra
    // 0x80036F24: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    TRACE_RETURN()
    return;
    // 0x80036F24: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80036F28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80036F28: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80036F2C: lw          $t6, -0x6610($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6610);
    // 0x80036F30: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80036F34: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    // 0x80036F38: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x80036F3C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80036F40: beql        $v1, $zero, L_80036F7C
    if (ctx->r3 == 0) {
        // 0x80036F44: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80036F7C;
    }
    goto skip_0;
    // 0x80036F44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80036F48: lh          $t7, 0x8C($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X8C);
L_80036F4C:
    // 0x80036F4C: bnel        $a0, $t7, L_80036F6C
    if (ctx->r4 != ctx->r15) {
        // 0x80036F50: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80036F6C;
    }
    goto skip_1;
    // 0x80036F50: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_1:
    // 0x80036F54: lh          $t8, 0xB4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XB4);
    // 0x80036F58: bnel        $a1, $t8, L_80036F6C
    if (ctx->r5 != ctx->r24) {
        // 0x80036F5C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80036F6C;
    }
    goto skip_2;
    // 0x80036F5C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_2:
    // 0x80036F60: jr          $ra
    // 0x80036F64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    TRACE_RETURN()
    return;
    // 0x80036F64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80036F68: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80036F6C:
    // 0x80036F6C: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80036F70: bnel        $v1, $zero, L_80036F4C
    if (ctx->r3 != 0) {
        // 0x80036F74: lh          $t7, 0x8C($v0)
        ctx->r15 = MEM_H(ctx->r2, 0X8C);
            goto L_80036F4C;
    }
    goto skip_3;
    // 0x80036F74: lh          $t7, 0x8C($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X8C);
    skip_3:
    // 0x80036F78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80036F7C:
    // 0x80036F7C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80036F84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80036F84: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80036F88: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80036F8C: lw          $t6, -0x6610($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6610);
    // 0x80036F90: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80036F94: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80036F98: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80036F9C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80036FA0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80036FA4: lw          $s0, 0x0($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X0);
    // 0x80036FA8: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x80036FAC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80036FB0: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80036FB4: addiu       $s1, $zero, 0x100
    ctx->r17 = ADD32(0, 0X100);
    // 0x80036FB8: beql        $t7, $zero, L_80037004
    if (ctx->r15 == 0) {
        // 0x80036FBC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80037004;
    }
    goto skip_0;
    // 0x80036FBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80036FC0: lh          $t8, 0x8C($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X8C);
L_80036FC4:
    // 0x80036FC4: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80036FC8: bnel        $s1, $t8, L_80036FF4
    if (ctx->r17 != ctx->r24) {
        // 0x80036FCC: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80036FF4;
    }
    goto skip_1;
    // 0x80036FCC: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x80036FD0: jal         0x8000C8E8
    // 0x80036FD4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_8000C8E8(rdram, ctx);
        goto after_0;
    // 0x80036FD4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x80036FD8: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80036FDC: nop

    // 0x80036FE0: bc1fl       L_80036FF4
    if (!c1cs) {
        // 0x80036FE4: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80036FF4;
    }
    goto skip_2;
    // 0x80036FE4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x80036FE8: b           L_80037004
    // 0x80036FEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80037004;
    // 0x80036FEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80036FF0: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_80036FF4:
    // 0x80036FF4: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80036FF8: bnel        $t9, $zero, L_80036FC4
    if (ctx->r25 != 0) {
        // 0x80036FFC: lh          $t8, 0x8C($s0)
        ctx->r24 = MEM_H(ctx->r16, 0X8C);
            goto L_80036FC4;
    }
    goto skip_3;
    // 0x80036FFC: lh          $t8, 0x8C($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X8C);
    skip_3:
    // 0x80037000: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80037004:
    // 0x80037004: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80037008: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8003700C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80037010: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80037014: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80037018: jr          $ra
    // 0x8003701C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    TRACE_RETURN()
    return;
    // 0x8003701C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80037020(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80037020: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80037024: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80037028: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003702C: lhu         $t6, 0x90($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X90);
    // 0x80037030: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80037034: sltiu       $at, $t6, 0x17
    ctx->r1 = ctx->r14 < 0X17 ? 1 : 0;
    // 0x80037038: beq         $at, $zero, L_80037918
    if (ctx->r1 == 0) {
        // 0x8003703C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80037918;
    }
    // 0x8003703C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80037040: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80037044: addu        $at, $at, $t6
    gpr jr_addend_8003704C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80037048: lw          $t6, 0x727C($at)
    ctx->r14 = ADD32(ctx->r1, 0X727C);
    // 0x8003704C: jr          $t6
    // 0x80037050: nop

    switch (jr_addend_8003704C >> 2) {
        case 0: goto L_80037054; break;
        case 1: goto L_80037178; break;
        case 2: goto L_800371B0; break;
        case 3: goto L_8003720C; break;
        case 4: goto L_80037280; break;
        case 5: goto L_8003733C; break;
        case 6: goto L_8003736C; break;
        case 7: goto L_80037484; break;
        case 8: goto L_800374AC; break;
        case 9: goto L_800374C4; break;
        case 10: goto L_800374EC; break;
        case 11: goto L_80037530; break;
        case 12: goto L_80037588; break;
        case 13: goto L_80037918; break;
        case 14: goto L_80037918; break;
        case 15: goto L_80037918; break;
        case 16: goto L_80037918; break;
        case 17: goto L_80037918; break;
        case 18: goto L_80037918; break;
        case 19: goto L_80037918; break;
        case 20: goto L_800376B8; break;
        case 21: goto L_80037814; break;
        case 22: goto L_800378A0; break;
        default: switch_error(__func__, 0x8003704C, 0x8007727C);
    }
    // 0x80037050: nop

L_80037054:
    // 0x80037054: jal         0x8000E35C
    // 0x80037058: nop

    func_8000E35C(rdram, ctx);
        goto after_0;
    // 0x80037058: nop

    after_0:
    // 0x8003705C: andi        $v1, $v0, 0x3
    ctx->r3 = ctx->r2 & 0X3;
    // 0x80037060: beq         $v1, $zero, L_80037094
    if (ctx->r3 == 0) {
        // 0x80037064: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80037094;
    }
    // 0x80037064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80037068: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003706C: beq         $v1, $at, L_800370A0
    if (ctx->r3 == ctx->r1) {
        // 0x80037070: addiu       $t8, $zero, 0x101
        ctx->r24 = ADD32(0, 0X101);
            goto L_800370A0;
    }
    // 0x80037070: addiu       $t8, $zero, 0x101
    ctx->r24 = ADD32(0, 0X101);
    // 0x80037074: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80037078: beq         $v1, $at, L_800370A8
    if (ctx->r3 == ctx->r1) {
        // 0x8003707C: addiu       $t9, $zero, 0x101
        ctx->r25 = ADD32(0, 0X101);
            goto L_800370A8;
    }
    // 0x8003707C: addiu       $t9, $zero, 0x101
    ctx->r25 = ADD32(0, 0X101);
    // 0x80037080: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80037084: beq         $v1, $a2, L_800370B0
    if (ctx->r3 == ctx->r6) {
        // 0x80037088: addiu       $t0, $zero, 0x102
        ctx->r8 = ADD32(0, 0X102);
            goto L_800370B0;
    }
    // 0x80037088: addiu       $t0, $zero, 0x102
    ctx->r8 = ADD32(0, 0X102);
    // 0x8003708C: b           L_800370B4
    // 0x80037090: nop

        goto L_800370B4;
    // 0x80037090: nop

L_80037094:
    // 0x80037094: addiu       $t7, $zero, 0x101
    ctx->r15 = ADD32(0, 0X101);
    // 0x80037098: b           L_800370B4
    // 0x8003709C: sh          $t7, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r15;
        goto L_800370B4;
    // 0x8003709C: sh          $t7, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r15;
L_800370A0:
    // 0x800370A0: b           L_800370B4
    // 0x800370A4: sh          $t8, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r24;
        goto L_800370B4;
    // 0x800370A4: sh          $t8, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r24;
L_800370A8:
    // 0x800370A8: b           L_800370B4
    // 0x800370AC: sh          $t9, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r25;
        goto L_800370B4;
    // 0x800370AC: sh          $t9, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r25;
L_800370B0:
    // 0x800370B0: sh          $t0, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r8;
L_800370B4:
    // 0x800370B4: jal         0x80039158
    // 0x800370B8: lh          $a1, 0x3E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X3E);
    func_80039158(rdram, ctx);
        goto after_1;
    // 0x800370B8: lh          $a1, 0x3E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X3E);
    after_1:
    // 0x800370BC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800370C0: lh          $v1, -0x662C($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X662C);
    // 0x800370C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800370C8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x800370CC: beq         $v1, $at, L_800370DC
    if (ctx->r3 == ctx->r1) {
        // 0x800370D0: addiu       $t1, $zero, 0x3E8
        ctx->r9 = ADD32(0, 0X3E8);
            goto L_800370DC;
    }
    // 0x800370D0: addiu       $t1, $zero, 0x3E8
    ctx->r9 = ADD32(0, 0X3E8);
    // 0x800370D4: bnel        $a2, $v1, L_800370E4
    if (ctx->r6 != ctx->r3) {
        // 0x800370D8: lw          $t2, 0x84($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X84);
            goto L_800370E4;
    }
    goto skip_0;
    // 0x800370D8: lw          $t2, 0x84($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X84);
    skip_0:
L_800370DC:
    // 0x800370DC: sh          $t1, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r9;
    // 0x800370E0: lw          $t2, 0x84($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X84);
L_800370E4:
    // 0x800370E4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800370E8: addiu       $v1, $v1, -0x6624
    ctx->r3 = ADD32(ctx->r3, -0X6624);
    // 0x800370EC: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x800370F0: addiu       $a0, $zero, 0x103
    ctx->r4 = ADD32(0, 0X103);
    // 0x800370F4: lw          $v0, 0xE0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0XE0);
    // 0x800370F8: lbu         $t4, 0x10($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X10);
    // 0x800370FC: ori         $t5, $t4, 0x4
    ctx->r13 = ctx->r12 | 0X4;
    // 0x80037100: sb          $t5, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r13;
    // 0x80037104: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x80037108: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8003710C: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
    // 0x80037110: lh          $t8, 0x8E($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X8E);
    // 0x80037114: bne         $a0, $t8, L_80037128
    if (ctx->r4 != ctx->r24) {
        // 0x80037118: nop
    
            goto L_80037128;
    }
    // 0x80037118: nop

    // 0x8003711C: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x80037120: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80037124: sh          $t0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r8;
L_80037128:
    // 0x80037128: jal         0x80036E84
    // 0x8003712C: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    func_80036E84(rdram, ctx);
        goto after_2;
    // 0x8003712C: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    after_2:
    // 0x80037130: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80037134: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80037138: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8003713C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80037140:
    // 0x80037140: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80037144: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80037148: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003714C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80037150: bne         $a0, $a2, L_80037140
    if (ctx->r4 != ctx->r6) {
        // 0x80037154: swc1        $f4, 0xB4($v1)
        MEM_W(0XB4, ctx->r3) = ctx->f4.u32l;
            goto L_80037140;
    }
    // 0x80037154: swc1        $f4, 0xB4($v1)
    MEM_W(0XB4, ctx->r3) = ctx->f4.u32l;
    // 0x80037158: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8003715C: lh          $t1, -0x6B80($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X6B80);
    // 0x80037160: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80037164: bne         $t1, $at, L_80037178
    if (ctx->r9 != ctx->r1) {
        // 0x80037168: lui         $at, 0x8007
        ctx->r1 = S32(0X8007 << 16);
            goto L_80037178;
    }
    // 0x80037168: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003716C: lwc1        $f6, 0x72D8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X72D8);
    // 0x80037170: b           L_80037304
    // 0x80037174: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
        goto L_80037304;
    // 0x80037174: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
L_80037178:
    // 0x80037178: lw          $t2, 0x84($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X84);
    // 0x8003717C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80037180: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x80037184: jal         0x8004D62C
    // 0x80037188: lw          $a0, 0xE0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XE0);
    func_8004D62C(rdram, ctx);
        goto after_3;
    // 0x80037188: lw          $a0, 0xE0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XE0);
    after_3:
    // 0x8003718C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80037190: jal         0x8000E35C
    // 0x80037194: sh          $t4, 0x6C($s0)
    MEM_H(0X6C, ctx->r16) = ctx->r12;
    func_8000E35C(rdram, ctx);
        goto after_4;
    // 0x80037194: sh          $t4, 0x6C($s0)
    MEM_H(0X6C, ctx->r16) = ctx->r12;
    after_4:
    // 0x80037198: andi        $t5, $v0, 0x3F
    ctx->r13 = ctx->r2 & 0X3F;
    // 0x8003719C: addiu       $t6, $t5, 0xA
    ctx->r14 = ADD32(ctx->r13, 0XA);
    // 0x800371A0: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800371A4: sh          $t6, 0xAC($s0)
    MEM_H(0XAC, ctx->r16) = ctx->r14;
    // 0x800371A8: sh          $zero, 0xAE($s0)
    MEM_H(0XAE, ctx->r16) = 0;
    // 0x800371AC: sh          $t7, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r15;
L_800371B0:
    // 0x800371B0: lh          $t8, 0xAE($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XAE);
    // 0x800371B4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x800371B8: bnel        $t8, $zero, L_80037200
    if (ctx->r24 != 0) {
        // 0x800371BC: lh          $t3, 0xAC($s0)
        ctx->r11 = MEM_H(ctx->r16, 0XAC);
            goto L_80037200;
    }
    goto skip_1;
    // 0x800371BC: lh          $t3, 0xAC($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XAC);
    skip_1:
    // 0x800371C0: jal         0x8000E35C
    // 0x800371C4: nop

    func_8000E35C(rdram, ctx);
        goto after_5;
    // 0x800371C4: nop

    after_5:
    // 0x800371C8: andi        $t9, $v0, 0x3F
    ctx->r25 = ctx->r2 & 0X3F;
    // 0x800371CC: addiu       $t0, $t9, 0x28
    ctx->r8 = ADD32(ctx->r25, 0X28);
    // 0x800371D0: jal         0x8000E35C
    // 0x800371D4: sh          $t0, 0xAE($s0)
    MEM_H(0XAE, ctx->r16) = ctx->r8;
    func_8000E35C(rdram, ctx);
        goto after_6;
    // 0x800371D4: sh          $t0, 0xAE($s0)
    MEM_H(0XAE, ctx->r16) = ctx->r8;
    after_6:
    // 0x800371D8: andi        $t1, $v0, 0x3
    ctx->r9 = ctx->r2 & 0X3;
    // 0x800371DC: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800371E0: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x800371E4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800371E8: lwc1        $f8, 0x72DC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X72DC);
    // 0x800371EC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800371F0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x800371F4: div.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800371F8: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    // 0x800371FC: lh          $t3, 0xAC($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XAC);
L_80037200:
    // 0x80037200: bnel        $t3, $zero, L_8003791C
    if (ctx->r11 != 0) {
        // 0x80037204: addiu       $t4, $s0, 0x8
        ctx->r12 = ADD32(ctx->r16, 0X8);
            goto L_8003791C;
    }
    goto skip_2;
    // 0x80037204: addiu       $t4, $s0, 0x8
    ctx->r12 = ADD32(ctx->r16, 0X8);
    skip_2:
    // 0x80037208: sh          $a2, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r6;
L_8003720C:
    // 0x8003720C: lw          $t4, 0x84($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X84);
    // 0x80037210: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80037214: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x80037218: jal         0x8004D62C
    // 0x8003721C: lw          $a0, 0xE0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0XE0);
    func_8004D62C(rdram, ctx);
        goto after_7;
    // 0x8003721C: lw          $a0, 0xE0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0XE0);
    after_7:
    // 0x80037220: jal         0x8000E35C
    // 0x80037224: sh          $zero, 0x6C($s0)
    MEM_H(0X6C, ctx->r16) = 0;
    func_8000E35C(rdram, ctx);
        goto after_8;
    // 0x80037224: sh          $zero, 0x6C($s0)
    MEM_H(0X6C, ctx->r16) = 0;
    after_8:
    // 0x80037228: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x8003722C: addiu       $t7, $t6, 0x50
    ctx->r15 = ADD32(ctx->r14, 0X50);
    // 0x80037230: sh          $t7, 0xAC($s0)
    MEM_H(0XAC, ctx->r16) = ctx->r15;
    // 0x80037234: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80037238: lh          $t8, -0x6B80($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X6B80);
    // 0x8003723C: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80037240: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80037244: bnel        $t8, $zero, L_8003727C
    if (ctx->r24 != 0) {
        // 0x80037248: addiu       $t9, $zero, 0x4
        ctx->r25 = ADD32(0, 0X4);
            goto L_8003727C;
    }
    goto skip_3;
    // 0x80037248: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    skip_3:
    // 0x8003724C: jal         0x8000C8E8
    // 0x80037250: addiu       $a1, $a1, -0x6A18
    ctx->r5 = ADD32(ctx->r5, -0X6A18);
    func_8000C8E8(rdram, ctx);
        goto after_9;
    // 0x80037250: addiu       $a1, $a1, -0x6A18
    ctx->r5 = ADD32(ctx->r5, -0X6A18);
    after_9:
    // 0x80037254: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80037258: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003725C: nop

    // 0x80037260: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80037264: nop

    // 0x80037268: bc1fl       L_8003727C
    if (!c1cs) {
        // 0x8003726C: addiu       $t9, $zero, 0x4
        ctx->r25 = ADD32(0, 0X4);
            goto L_8003727C;
    }
    goto skip_4;
    // 0x8003726C: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    skip_4:
    // 0x80037270: jal         0x80044480
    // 0x80037274: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    func_80044480(rdram, ctx);
        goto after_10;
    // 0x80037274: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_10:
    // 0x80037278: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
L_8003727C:
    // 0x8003727C: sh          $t9, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r25;
L_80037280:
    // 0x80037280: lh          $t0, 0xAC($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XAC);
    // 0x80037284: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    // 0x80037288: addiu       $a1, $s0, 0x14
    ctx->r5 = ADD32(ctx->r16, 0X14);
    // 0x8003728C: beq         $t0, $zero, L_800372E8
    if (ctx->r8 == 0) {
        // 0x80037290: lui         $t1, 0x8013
        ctx->r9 = S32(0X8013 << 16);
            goto L_800372E8;
    }
    // 0x80037290: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80037294: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80037298: addiu       $a3, $a3, -0x6A18
    ctx->r7 = ADD32(ctx->r7, -0X6A18);
    // 0x8003729C: jal         0x8000CD08
    // 0x800372A0: addiu       $a2, $s0, 0x8
    ctx->r6 = ADD32(ctx->r16, 0X8);
    func_8000CD08(rdram, ctx);
        goto after_11;
    // 0x800372A0: addiu       $a2, $s0, 0x8
    ctx->r6 = ADD32(ctx->r16, 0X8);
    after_11:
    // 0x800372A4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800372A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800372AC: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800372B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800372B4: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800372B8: nop

    // 0x800372BC: bc1fl       L_800372DC
    if (!c1cs) {
        // 0x800372C0: lwc1        $f16, 0x18($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X18);
            goto L_800372DC;
    }
    goto skip_5;
    // 0x800372C0: lwc1        $f16, 0x18($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X18);
    skip_5:
    // 0x800372C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800372C8: nop

    // 0x800372CC: sub.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800372D0: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    // 0x800372D4: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800372D8: lwc1        $f16, 0x18($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X18);
L_800372DC:
    // 0x800372DC: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x800372E0: b           L_80037918
    // 0x800372E4: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
        goto L_80037918;
    // 0x800372E4: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
L_800372E8:
    // 0x800372E8: lh          $t1, -0x6B80($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X6B80);
    // 0x800372EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800372F0: addiu       $t2, $zero, 0x3E8
    ctx->r10 = ADD32(0, 0X3E8);
    // 0x800372F4: bnel        $t1, $at, L_80037308
    if (ctx->r9 != ctx->r1) {
        // 0x800372F8: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80037308;
    }
    goto skip_6;
    // 0x800372F8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    skip_6:
    // 0x800372FC: b           L_80037918
    // 0x80037300: sh          $t2, 0xAC($s0)
    MEM_H(0XAC, ctx->r16) = ctx->r10;
        goto L_80037918;
    // 0x80037300: sh          $t2, 0xAC($s0)
    MEM_H(0XAC, ctx->r16) = ctx->r10;
L_80037304:
    // 0x80037304: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_80037308:
    // 0x80037308: jal         0x8000E35C
    // 0x8003730C: sh          $t3, 0xB4($s0)
    MEM_H(0XB4, ctx->r16) = ctx->r11;
    func_8000E35C(rdram, ctx);
        goto after_12;
    // 0x8003730C: sh          $t3, 0xB4($s0)
    MEM_H(0XB4, ctx->r16) = ctx->r11;
    after_12:
    // 0x80037310: andi        $t4, $v0, 0x7
    ctx->r12 = ctx->r2 & 0X7;
    // 0x80037314: addiu       $t5, $t4, 0x1E
    ctx->r13 = ADD32(ctx->r12, 0X1E);
    // 0x80037318: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x8003731C: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x80037320: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x80037324: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80037328: sh          $t6, 0xC8($s0)
    MEM_H(0XC8, ctx->r16) = ctx->r14;
    // 0x8003732C: sh          $zero, 0xAC($s0)
    MEM_H(0XAC, ctx->r16) = 0;
    // 0x80037330: sh          $t7, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r15;
    // 0x80037334: b           L_80037918
    // 0x80037338: swc1        $f6, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f6.u32l;
        goto L_80037918;
    // 0x80037338: swc1        $f6, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f6.u32l;
L_8003733C:
    // 0x8003733C: lw          $t8, 0x84($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X84);
    // 0x80037340: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80037344: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x80037348: jal         0x8004D62C
    // 0x8003734C: lw          $a0, 0xE0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0XE0);
    func_8004D62C(rdram, ctx);
        goto after_13;
    // 0x8003734C: lw          $a0, 0xE0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0XE0);
    after_13:
    // 0x80037350: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80037354: addiu       $t1, $zero, 0x190
    ctx->r9 = ADD32(0, 0X190);
    // 0x80037358: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x8003735C: sh          $t0, 0x6C($s0)
    MEM_H(0X6C, ctx->r16) = ctx->r8;
    // 0x80037360: sh          $zero, 0xAC($s0)
    MEM_H(0XAC, ctx->r16) = 0;
    // 0x80037364: sh          $t1, 0xAE($s0)
    MEM_H(0XAE, ctx->r16) = ctx->r9;
    // 0x80037368: sh          $t2, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r10;
L_8003736C:
    // 0x8003736C: lh          $t3, 0xAC($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XAC);
    // 0x80037370: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80037374: bne         $t3, $zero, L_80037414
    if (ctx->r11 != 0) {
        // 0x80037378: nop
    
            goto L_80037414;
    }
    // 0x80037378: nop

    // 0x8003737C: jal         0x8000E35C
    // 0x80037380: nop

    func_8000E35C(rdram, ctx);
        goto after_14;
    // 0x80037380: nop

    after_14:
    // 0x80037384: andi        $t4, $v0, 0x3F
    ctx->r12 = ctx->r2 & 0X3F;
    // 0x80037388: addiu       $t5, $t4, 0x14
    ctx->r13 = ADD32(ctx->r12, 0X14);
    // 0x8003738C: sh          $t5, 0xAC($s0)
    MEM_H(0XAC, ctx->r16) = ctx->r13;
    // 0x80037390: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    // 0x80037394: addiu       $a1, $s0, 0x14
    ctx->r5 = ADD32(ctx->r16, 0X14);
    // 0x80037398: addiu       $a2, $s0, 0x8
    ctx->r6 = ADD32(ctx->r16, 0X8);
    // 0x8003739C: jal         0x8000CD08
    // 0x800373A0: addiu       $a3, $s0, 0xB8
    ctx->r7 = ADD32(ctx->r16, 0XB8);
    func_8000CD08(rdram, ctx);
        goto after_15;
    // 0x800373A0: addiu       $a3, $s0, 0xB8
    ctx->r7 = ADD32(ctx->r16, 0XB8);
    after_15:
    // 0x800373A4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800373A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800373AC: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800373B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800373B4: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x800373B8: nop

    // 0x800373BC: bc1fl       L_800373DC
    if (!c1cs) {
        // 0x800373C0: lwc1        $f18, 0x18($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X18);
            goto L_800373DC;
    }
    goto skip_7;
    // 0x800373C0: lwc1        $f18, 0x18($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X18);
    skip_7:
    // 0x800373C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800373C8: nop

    // 0x800373CC: sub.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x800373D0: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    // 0x800373D4: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800373D8: lwc1        $f18, 0x18($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X18);
L_800373DC:
    // 0x800373DC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800373E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800373E4: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x800373E8: jal         0x8000E3A0
    // 0x800373EC: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    func_8000E3A0(rdram, ctx);
        goto after_16;
    // 0x800373EC: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    after_16:
    // 0x800373F0: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800373F4: lui         $at, 0x3D80
    ctx->r1 = S32(0X3D80 << 16);
    // 0x800373F8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800373FC: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80037400: lwc1        $f18, 0x58($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80037404: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80037408: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8003740C: b           L_80037918
    // 0x80037410: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_80037918;
    // 0x80037410: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_80037414:
    // 0x80037414: jal         0x8000C8E8
    // 0x80037418: addiu       $a1, $s0, 0xB8
    ctx->r5 = ADD32(ctx->r16, 0XB8);
    func_8000C8E8(rdram, ctx);
        goto after_17;
    // 0x80037418: addiu       $a1, $s0, 0xB8
    ctx->r5 = ADD32(ctx->r16, 0XB8);
    after_17:
    // 0x8003741C: lwc1        $f6, 0xC4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80037420: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80037424: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80037428: nop

    // 0x8003742C: bc1fl       L_80037460
    if (!c1cs) {
        // 0x80037430: lh          $t8, 0x8E($s0)
        ctx->r24 = MEM_H(ctx->r16, 0X8E);
            goto L_80037460;
    }
    goto skip_8;
    // 0x80037430: lh          $t8, 0x8E($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X8E);
    skip_8:
    // 0x80037434: lh          $t6, -0x6B80($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X6B80);
    // 0x80037438: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003743C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80037440: bnel        $t6, $at, L_80037454
    if (ctx->r14 != ctx->r1) {
        // 0x80037444: lh          $t7, 0xC8($s0)
        ctx->r15 = MEM_H(ctx->r16, 0XC8);
            goto L_80037454;
    }
    goto skip_9;
    // 0x80037444: lh          $t7, 0xC8($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XC8);
    skip_9:
    // 0x80037448: b           L_80037918
    // 0x8003744C: sh          $a2, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r6;
        goto L_80037918;
    // 0x8003744C: sh          $a2, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r6;
    // 0x80037450: lh          $t7, 0xC8($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XC8);
L_80037454:
    // 0x80037454: b           L_80037918
    // 0x80037458: sh          $t7, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r15;
        goto L_80037918;
    // 0x80037458: sh          $t7, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r15;
    // 0x8003745C: lh          $t8, 0x8E($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X8E);
L_80037460:
    // 0x80037460: addiu       $at, $zero, 0x102
    ctx->r1 = ADD32(0, 0X102);
    // 0x80037464: bnel        $t8, $at, L_8003791C
    if (ctx->r24 != ctx->r1) {
        // 0x80037468: addiu       $t4, $s0, 0x8
        ctx->r12 = ADD32(ctx->r16, 0X8);
            goto L_8003791C;
    }
    goto skip_10;
    // 0x80037468: addiu       $t4, $s0, 0x8
    ctx->r12 = ADD32(ctx->r16, 0X8);
    skip_10:
    // 0x8003746C: lh          $t9, 0xAE($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XAE);
    // 0x80037470: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x80037474: bnel        $t9, $zero, L_8003791C
    if (ctx->r25 != 0) {
        // 0x80037478: addiu       $t4, $s0, 0x8
        ctx->r12 = ADD32(ctx->r16, 0X8);
            goto L_8003791C;
    }
    goto skip_11;
    // 0x80037478: addiu       $t4, $s0, 0x8
    ctx->r12 = ADD32(ctx->r16, 0X8);
    skip_11:
    // 0x8003747C: b           L_80037918
    // 0x80037480: sh          $t0, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r8;
        goto L_80037918;
    // 0x80037480: sh          $t0, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r8;
L_80037484:
    // 0x80037484: lw          $t1, 0x84($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X84);
    // 0x80037488: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8003748C: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x80037490: jal         0x8004D62C
    // 0x80037494: lw          $a0, 0xE0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0XE0);
    func_8004D62C(rdram, ctx);
        goto after_18;
    // 0x80037494: lw          $a0, 0xE0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0XE0);
    after_18:
    // 0x80037498: addiu       $t3, $zero, 0x64
    ctx->r11 = ADD32(0, 0X64);
    // 0x8003749C: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x800374A0: sh          $zero, 0x6C($s0)
    MEM_H(0X6C, ctx->r16) = 0;
    // 0x800374A4: sh          $t3, 0xAC($s0)
    MEM_H(0XAC, ctx->r16) = ctx->r11;
    // 0x800374A8: sh          $t4, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r12;
L_800374AC:
    // 0x800374AC: lh          $t5, 0xAC($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XAC);
    // 0x800374B0: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x800374B4: bnel        $t5, $zero, L_8003791C
    if (ctx->r13 != 0) {
        // 0x800374B8: addiu       $t4, $s0, 0x8
        ctx->r12 = ADD32(ctx->r16, 0X8);
            goto L_8003791C;
    }
    goto skip_12;
    // 0x800374B8: addiu       $t4, $s0, 0x8
    ctx->r12 = ADD32(ctx->r16, 0X8);
    skip_12:
    // 0x800374BC: b           L_80037918
    // 0x800374C0: sh          $t6, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r14;
        goto L_80037918;
    // 0x800374C0: sh          $t6, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r14;
L_800374C4:
    // 0x800374C4: lw          $t8, 0x84($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X84);
    // 0x800374C8: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800374CC: sh          $t7, 0xB4($s0)
    MEM_H(0XB4, ctx->r16) = ctx->r15;
    // 0x800374D0: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x800374D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800374D8: jal         0x8004D62C
    // 0x800374DC: lw          $a0, 0xE0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0XE0);
    func_8004D62C(rdram, ctx);
        goto after_19;
    // 0x800374DC: lw          $a0, 0xE0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0XE0);
    after_19:
    // 0x800374E0: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x800374E4: sh          $zero, 0x6C($s0)
    MEM_H(0X6C, ctx->r16) = 0;
    // 0x800374E8: sh          $t0, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r8;
L_800374EC:
    // 0x800374EC: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800374F0: lh          $t1, -0x65BC($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X65BC);
    // 0x800374F4: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x800374F8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800374FC: beql        $t1, $zero, L_8003791C
    if (ctx->r9 == 0) {
        // 0x80037500: addiu       $t4, $s0, 0x8
        ctx->r12 = ADD32(ctx->r16, 0X8);
            goto L_8003791C;
    }
    goto skip_13;
    // 0x80037500: addiu       $t4, $s0, 0x8
    ctx->r12 = ADD32(ctx->r16, 0X8);
    skip_13:
    // 0x80037504: jal         0x8000C8E8
    // 0x80037508: addiu       $a1, $a1, -0x65C8
    ctx->r5 = ADD32(ctx->r5, -0X65C8);
    func_8000C8E8(rdram, ctx);
        goto after_20;
    // 0x80037508: addiu       $a1, $a1, -0x65C8
    ctx->r5 = ADD32(ctx->r5, -0X65C8);
    after_20:
    // 0x8003750C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80037510: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80037514: addiu       $t2, $zero, 0xB
    ctx->r10 = ADD32(0, 0XB);
    // 0x80037518: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8003751C: nop

    // 0x80037520: bc1fl       L_8003791C
    if (!c1cs) {
        // 0x80037524: addiu       $t4, $s0, 0x8
        ctx->r12 = ADD32(ctx->r16, 0X8);
            goto L_8003791C;
    }
    goto skip_14;
    // 0x80037524: addiu       $t4, $s0, 0x8
    ctx->r12 = ADD32(ctx->r16, 0X8);
    skip_14:
    // 0x80037528: b           L_80037918
    // 0x8003752C: sh          $t2, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r10;
        goto L_80037918;
    // 0x8003752C: sh          $t2, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r10;
L_80037530:
    // 0x80037530: lw          $t3, 0x84($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X84);
    // 0x80037534: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80037538: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x8003753C: jal         0x8004D62C
    // 0x80037540: lw          $a0, 0xE0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0XE0);
    func_8004D62C(rdram, ctx);
        goto after_21;
    // 0x80037540: lw          $a0, 0xE0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0XE0);
    after_21:
    // 0x80037544: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80037548: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003754C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80037550: sh          $t5, 0x6C($s0)
    MEM_H(0X6C, ctx->r16) = ctx->r13;
    // 0x80037554: addiu       $a0, $a0, -0x65BC
    ctx->r4 = ADD32(ctx->r4, -0X65BC);
    // 0x80037558: addiu       $v0, $v0, -0x65C8
    ctx->r2 = ADD32(ctx->r2, -0X65C8);
    // 0x8003755C: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
L_80037560:
    // 0x80037560: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80037564: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80037568: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003756C: bne         $v0, $a0, L_80037560
    if (ctx->r2 != ctx->r4) {
        // 0x80037570: swc1        $f8, 0xB4($v1)
        MEM_W(0XB4, ctx->r3) = ctx->f8.u32l;
            goto L_80037560;
    }
    // 0x80037570: swc1        $f8, 0xB4($v1)
    MEM_W(0XB4, ctx->r3) = ctx->f8.u32l;
    // 0x80037574: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80037578: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003757C: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80037580: sh          $t6, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r14;
    // 0x80037584: swc1        $f18, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f18.u32l;
L_80037588:
    // 0x80037588: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8003758C: lh          $t7, -0x65BC($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X65BC);
    // 0x80037590: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    // 0x80037594: addiu       $a1, $s0, 0x14
    ctx->r5 = ADD32(ctx->r16, 0X14);
    // 0x80037598: beq         $t7, $zero, L_800376B0
    if (ctx->r15 == 0) {
        // 0x8003759C: addiu       $a2, $zero, 0x3
        ctx->r6 = ADD32(0, 0X3);
            goto L_800376B0;
    }
    // 0x8003759C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x800375A0: addiu       $a2, $s0, 0x8
    ctx->r6 = ADD32(ctx->r16, 0X8);
    // 0x800375A4: addiu       $a3, $s0, 0xB8
    ctx->r7 = ADD32(ctx->r16, 0XB8);
    // 0x800375A8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800375AC: jal         0x8000CD08
    // 0x800375B0: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_8000CD08(rdram, ctx);
        goto after_22;
    // 0x800375B0: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_22:
    // 0x800375B4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800375B8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800375BC: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800375C0: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x800375C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800375C8: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x800375CC: nop

    // 0x800375D0: bc1fl       L_800375F0
    if (!c1cs) {
        // 0x800375D4: lwc1        $f10, 0x18($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
            goto L_800375F0;
    }
    goto skip_15;
    // 0x800375D4: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    skip_15:
    // 0x800375D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800375DC: nop

    // 0x800375E0: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800375E4: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    // 0x800375E8: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800375EC: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
L_800375F0:
    // 0x800375F0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800375F4: add.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x800375F8: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    // 0x800375FC: jal         0x8000C8E8
    // 0x80037600: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_8000C8E8(rdram, ctx);
        goto after_23;
    // 0x80037600: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_23:
    // 0x80037604: lwc1        $f18, 0xC4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80037608: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8003760C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80037610: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80037614: addiu       $v1, $v1, -0x6624
    ctx->r3 = ADD32(ctx->r3, -0X6624);
    // 0x80037618: addiu       $v0, $v0, -0x65F8
    ctx->r2 = ADD32(ctx->r2, -0X65F8);
    // 0x8003761C: bc1fl       L_8003791C
    if (!c1cs) {
        // 0x80037620: addiu       $t4, $s0, 0x8
        ctx->r12 = ADD32(ctx->r16, 0X8);
            goto L_8003791C;
    }
    goto skip_16;
    // 0x80037620: addiu       $t4, $s0, 0x8
    ctx->r12 = ADD32(ctx->r16, 0X8);
    skip_16:
    // 0x80037624: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x80037628: addiu       $a0, $zero, 0x103
    ctx->r4 = ADD32(0, 0X103);
    // 0x8003762C: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80037630: sh          $t0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r8;
    // 0x80037634: lh          $t1, 0x8E($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X8E);
    // 0x80037638: bnel        $a0, $t1, L_80037650
    if (ctx->r4 != ctx->r9) {
        // 0x8003763C: lh          $t4, 0x0($v0)
        ctx->r12 = MEM_H(ctx->r2, 0X0);
            goto L_80037650;
    }
    goto skip_17;
    // 0x8003763C: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    skip_17:
    // 0x80037640: lh          $t2, 0x0($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X0);
    // 0x80037644: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80037648: sh          $t3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r11;
    // 0x8003764C: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
L_80037650:
    // 0x80037650: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80037654: sh          $t5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r13;
    // 0x80037658: lh          $t6, 0x8E($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X8E);
    // 0x8003765C: bne         $a0, $t6, L_80037670
    if (ctx->r4 != ctx->r14) {
        // 0x80037660: nop
    
            goto L_80037670;
    }
    // 0x80037660: nop

    // 0x80037664: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x80037668: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8003766C: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
L_80037670:
    // 0x80037670: jal         0x80036E0C
    // 0x80037674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80036E0C(rdram, ctx);
        goto after_24;
    // 0x80037674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80037678: jal         0x80044480
    // 0x8003767C: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    func_80044480(rdram, ctx);
        goto after_25;
    // 0x8003767C: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    after_25:
    // 0x80037680: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80037684: lh          $v1, -0x662C($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X662C);
    // 0x80037688: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003768C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80037690: beq         $v1, $at, L_8003769C
    if (ctx->r3 == ctx->r1) {
        // 0x80037694: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8003769C;
    }
    // 0x80037694: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80037698: bne         $a2, $v1, L_80037BA0
    if (ctx->r6 != ctx->r3) {
        // 0x8003769C: addiu       $v0, $v0, -0x661C
        ctx->r2 = ADD32(ctx->r2, -0X661C);
            goto L_80037BA0;
    }
L_8003769C:
    // 0x8003769C: addiu       $v0, $v0, -0x661C
    ctx->r2 = ADD32(ctx->r2, -0X661C);
    // 0x800376A0: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x800376A4: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800376A8: b           L_80037BA0
    // 0x800376AC: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
        goto L_80037BA0;
    // 0x800376AC: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
L_800376B0:
    // 0x800376B0: b           L_80037918
    // 0x800376B4: sh          $a2, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r6;
        goto L_80037918;
    // 0x800376B4: sh          $a2, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r6;
L_800376B8:
    // 0x800376B8: lw          $t1, 0x84($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X84);
    // 0x800376BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800376C0: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x800376C4: jal         0x8004D62C
    // 0x800376C8: lw          $a0, 0xE0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0XE0);
    func_8004D62C(rdram, ctx);
        goto after_26;
    // 0x800376C8: lw          $a0, 0xE0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0XE0);
    after_26:
    // 0x800376CC: lh          $t3, 0x2E($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X2E);
    // 0x800376D0: sh          $zero, 0x6C($s0)
    MEM_H(0X6C, ctx->r16) = 0;
    // 0x800376D4: bgez        $t3, L_80037750
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800376D8: nop
    
            goto L_80037750;
    }
    // 0x800376D8: nop

    // 0x800376DC: jal         0x8000E35C
    // 0x800376E0: nop

    func_8000E35C(rdram, ctx);
        goto after_27;
    // 0x800376E0: nop

    after_27:
    // 0x800376E4: andi        $t4, $v0, 0x7F
    ctx->r12 = ctx->r2 & 0X7F;
    // 0x800376E8: addiu       $t5, $t4, 0xA
    ctx->r13 = ADD32(ctx->r12, 0XA);
    // 0x800376EC: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x800376F0: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x800376F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800376F8: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800376FC: div.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80037700: jal         0x8000E35C
    // 0x80037704: swc1        $f10, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f10.u32l;
    func_8000E35C(rdram, ctx);
        goto after_28;
    // 0x80037704: swc1        $f10, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f10.u32l;
    after_28:
    // 0x80037708: andi        $t6, $v0, 0x1FF
    ctx->r14 = ctx->r2 & 0X1FF;
    // 0x8003770C: addiu       $t7, $t6, 0x190
    ctx->r15 = ADD32(ctx->r14, 0X190);
    // 0x80037710: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80037714: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80037718: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003771C: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80037720: div.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80037724: jal         0x8000E35C
    // 0x80037728: swc1        $f4, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f4.u32l;
    func_8000E35C(rdram, ctx);
        goto after_29;
    // 0x80037728: swc1        $f4, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f4.u32l;
    after_29:
    // 0x8003772C: andi        $t8, $v0, 0x7F
    ctx->r24 = ctx->r2 & 0X7F;
    // 0x80037730: addiu       $t9, $t8, 0xA
    ctx->r25 = ADD32(ctx->r24, 0XA);
    // 0x80037734: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80037738: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8003773C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80037740: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80037744: div.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80037748: b           L_800377C0
    // 0x8003774C: swc1        $f18, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f18.u32l;
        goto L_800377C0;
    // 0x8003774C: swc1        $f18, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f18.u32l;
L_80037750:
    // 0x80037750: jal         0x8000E35C
    // 0x80037754: nop

    func_8000E35C(rdram, ctx);
        goto after_30;
    // 0x80037754: nop

    after_30:
    // 0x80037758: andi        $t0, $v0, 0x7F
    ctx->r8 = ctx->r2 & 0X7F;
    // 0x8003775C: addiu       $t1, $t0, 0x5
    ctx->r9 = ADD32(ctx->r8, 0X5);
    // 0x80037760: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x80037764: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80037768: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003776C: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80037770: div.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80037774: jal         0x8000E35C
    // 0x80037778: swc1        $f10, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f10.u32l;
    func_8000E35C(rdram, ctx);
        goto after_31;
    // 0x80037778: swc1        $f10, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f10.u32l;
    after_31:
    // 0x8003777C: andi        $t2, $v0, 0xFF
    ctx->r10 = ctx->r2 & 0XFF;
    // 0x80037780: addiu       $t3, $t2, 0x190
    ctx->r11 = ADD32(ctx->r10, 0X190);
    // 0x80037784: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80037788: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8003778C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80037790: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80037794: div.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80037798: jal         0x8000E35C
    // 0x8003779C: swc1        $f4, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f4.u32l;
    func_8000E35C(rdram, ctx);
        goto after_32;
    // 0x8003779C: swc1        $f4, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f4.u32l;
    after_32:
    // 0x800377A0: andi        $t4, $v0, 0x7F
    ctx->r12 = ctx->r2 & 0X7F;
    // 0x800377A4: addiu       $t5, $t4, 0x5
    ctx->r13 = ADD32(ctx->r12, 0X5);
    // 0x800377A8: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x800377AC: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x800377B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800377B4: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800377B8: div.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800377BC: swc1        $f18, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f18.u32l;
L_800377C0:
    // 0x800377C0: jal         0x8000E35C
    // 0x800377C4: nop

    func_8000E35C(rdram, ctx);
        goto after_33;
    // 0x800377C4: nop

    after_33:
    // 0x800377C8: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x800377CC: beq         $t6, $zero, L_800377E0
    if (ctx->r14 == 0) {
        // 0x800377D0: nop
    
            goto L_800377E0;
    }
    // 0x800377D0: nop

    // 0x800377D4: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x800377D8: neg.s       $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = -ctx->f16.fl;
    // 0x800377DC: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
L_800377E0:
    // 0x800377E0: jal         0x8000E35C
    // 0x800377E4: nop

    func_8000E35C(rdram, ctx);
        goto after_34;
    // 0x800377E4: nop

    after_34:
    // 0x800377E8: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x800377EC: beq         $t7, $zero, L_80037800
    if (ctx->r15 == 0) {
        // 0x800377F0: addiu       $t8, $zero, 0x64
        ctx->r24 = ADD32(0, 0X64);
            goto L_80037800;
    }
    // 0x800377F0: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x800377F4: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
    // 0x800377F8: neg.s       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = -ctx->f6.fl;
    // 0x800377FC: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
L_80037800:
    // 0x80037800: addiu       $t9, $zero, 0x15
    ctx->r25 = ADD32(0, 0X15);
    // 0x80037804: sh          $t8, 0xAC($s0)
    MEM_H(0XAC, ctx->r16) = ctx->r24;
    // 0x80037808: sh          $t9, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r25;
    // 0x8003780C: jal         0x80044480
    // 0x80037810: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    func_80044480(rdram, ctx);
        goto after_35;
    // 0x80037810: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    after_35:
L_80037814:
    // 0x80037814: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80037818: lwc1        $f0, 0x72E0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X72E0);
    // 0x8003781C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80037820: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80037824: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80037828: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8003782C: lwc1        $f18, 0x8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80037830: beq         $a0, $a2, L_80037860
    if (ctx->r4 == ctx->r6) {
        // 0x80037834: lwc1        $f16, 0x3C($v1)
        ctx->f16.u32l = MEM_W(ctx->r3, 0X3C);
            goto L_80037860;
    }
    // 0x80037834: lwc1        $f16, 0x3C($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X3C);
L_80037838:
    // 0x80037838: add.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8003783C: lwc1        $f12, 0x14($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80037840: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80037844: lwc1        $f16, 0x40($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X40);
    // 0x80037848: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x8003784C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80037850: swc1        $f14, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f14.u32l;
    // 0x80037854: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80037858: bne         $a0, $a2, L_80037838
    if (ctx->r4 != ctx->r6) {
        // 0x8003785C: swc1        $f12, 0x10($v1)
        MEM_W(0X10, ctx->r3) = ctx->f12.u32l;
            goto L_80037838;
    }
    // 0x8003785C: swc1        $f12, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f12.u32l;
L_80037860:
    // 0x80037860: lwc1        $f12, 0x14($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80037864: add.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80037868: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003786C: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x80037870: swc1        $f14, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f14.u32l;
    // 0x80037874: swc1        $f12, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f12.u32l;
    // 0x80037878: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003787C: lwc1        $f8, 0x72E4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X72E4);
    // 0x80037880: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80037884: lh          $t0, 0xAC($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XAC);
    // 0x80037888: addiu       $t1, $zero, 0x16
    ctx->r9 = ADD32(0, 0X16);
    // 0x8003788C: sub.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80037890: bne         $t0, $zero, L_80037918
    if (ctx->r8 != 0) {
        // 0x80037894: swc1        $f18, 0x40($s0)
        MEM_W(0X40, ctx->r16) = ctx->f18.u32l;
            goto L_80037918;
    }
    // 0x80037894: swc1        $f18, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f18.u32l;
    // 0x80037898: b           L_80037918
    // 0x8003789C: sh          $t1, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r9;
        goto L_80037918;
    // 0x8003789C: sh          $t1, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r9;
L_800378A0:
    // 0x800378A0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800378A4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800378A8: addiu       $v1, $v1, -0x6624
    ctx->r3 = ADD32(ctx->r3, -0X6624);
    // 0x800378AC: addiu       $v0, $v0, -0x6620
    ctx->r2 = ADD32(ctx->r2, -0X6620);
    // 0x800378B0: lh          $t2, 0x0($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X0);
    // 0x800378B4: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x800378B8: addiu       $a0, $zero, 0x103
    ctx->r4 = ADD32(0, 0X103);
    // 0x800378BC: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x800378C0: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800378C4: sh          $t3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r11;
    // 0x800378C8: sh          $t5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r13;
    // 0x800378CC: lh          $t6, 0x8E($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X8E);
    // 0x800378D0: bne         $a0, $t6, L_800378F0
    if (ctx->r4 != ctx->r14) {
        // 0x800378D4: nop
    
            goto L_800378F0;
    }
    // 0x800378D4: nop

    // 0x800378D8: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x800378DC: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x800378E0: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800378E4: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800378E8: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x800378EC: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
L_800378F0:
    // 0x800378F0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800378F4: addiu       $v0, $v0, -0x6BDC
    ctx->r2 = ADD32(ctx->r2, -0X6BDC);
    // 0x800378F8: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800378FC: lw          $t2, 0x38($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X38);
    // 0x80037900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80037904: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80037908: jal         0x80036E0C
    // 0x8003790C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    func_80036E0C(rdram, ctx);
        goto after_36;
    // 0x8003790C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    after_36:
    // 0x80037910: b           L_80037BA4
    // 0x80037914: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80037BA4;
    // 0x80037914: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80037918:
    // 0x80037918: addiu       $t4, $s0, 0x8
    ctx->r12 = ADD32(ctx->r16, 0X8);
L_8003791C:
    // 0x8003791C: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x80037920: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80037924: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80037928:
    // 0x80037928: lh          $a0, 0xAC($v0)
    ctx->r4 = MEM_H(ctx->r2, 0XAC);
    // 0x8003792C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80037930: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x80037934: beq         $a0, $zero, L_80037940
    if (ctx->r4 == 0) {
        // 0x80037938: addiu       $t5, $a0, -0x1
        ctx->r13 = ADD32(ctx->r4, -0X1);
            goto L_80037940;
    }
    // 0x80037938: addiu       $t5, $a0, -0x1
    ctx->r13 = ADD32(ctx->r4, -0X1);
    // 0x8003793C: sh          $t5, 0xAC($v0)
    MEM_H(0XAC, ctx->r2) = ctx->r13;
L_80037940:
    // 0x80037940: bne         $at, $zero, L_80037928
    if (ctx->r1 != 0) {
        // 0x80037944: addiu       $v0, $v0, 0x2
        ctx->r2 = ADD32(ctx->r2, 0X2);
            goto L_80037928;
    }
    // 0x80037944: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80037948: lh          $t6, 0x2E($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2E);
    // 0x8003794C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80037950: blezl       $t6, L_80037B24
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80037954: lh          $v0, 0x92($s0)
        ctx->r2 = MEM_H(ctx->r16, 0X92);
            goto L_80037B24;
    }
    goto skip_18;
    // 0x80037954: lh          $v0, 0x92($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X92);
    skip_18:
    // 0x80037958: lh          $t7, -0x6B80($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X6B80);
    // 0x8003795C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80037960: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80037964: beql        $t7, $at, L_800379CC
    if (ctx->r15 == ctx->r1) {
        // 0x80037968: lh          $t0, 0x6C($s0)
        ctx->r8 = MEM_H(ctx->r16, 0X6C);
            goto L_800379CC;
    }
    goto skip_19;
    // 0x80037968: lh          $t0, 0x6C($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6C);
    skip_19:
    // 0x8003796C: lh          $t8, -0x65F6($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X65F6);
    // 0x80037970: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80037974: bnel        $t8, $zero, L_800379CC
    if (ctx->r24 != 0) {
        // 0x80037978: lh          $t0, 0x6C($s0)
        ctx->r8 = MEM_H(ctx->r16, 0X6C);
            goto L_800379CC;
    }
    goto skip_20;
    // 0x80037978: lh          $t0, 0x6C($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6C);
    skip_20:
    // 0x8003797C: jal         0x8000C8E8
    // 0x80037980: addiu       $a1, $s0, 0xB8
    ctx->r5 = ADD32(ctx->r16, 0XB8);
    func_8000C8E8(rdram, ctx);
        goto after_37;
    // 0x80037980: addiu       $a1, $s0, 0xB8
    ctx->r5 = ADD32(ctx->r16, 0XB8);
    after_37:
    // 0x80037984: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80037988: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003798C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80037990: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80037994: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80037998: addiu       $a0, $a0, -0x65AC
    ctx->r4 = ADD32(ctx->r4, -0X65AC);
    // 0x8003799C: addiu       $v0, $v0, -0x65B8
    ctx->r2 = ADD32(ctx->r2, -0X65B8);
    // 0x800379A0: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800379A4: bc1f        L_800379C8
    if (!c1cs) {
        // 0x800379A8: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_800379C8;
    }
    // 0x800379A8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_800379AC:
    // 0x800379AC: lwc1        $f4, 0xB8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XB8);
    // 0x800379B0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800379B4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800379B8: bne         $v0, $a0, L_800379AC
    if (ctx->r2 != ctx->r4) {
        // 0x800379BC: swc1        $f4, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
            goto L_800379AC;
    }
    // 0x800379BC: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x800379C0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800379C4: sh          $t9, -0x65F6($at)
    MEM_H(-0X65F6, ctx->r1) = ctx->r25;
L_800379C8:
    // 0x800379C8: lh          $t0, 0x6C($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6C);
L_800379CC:
    // 0x800379CC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800379D0: beql        $t0, $zero, L_80037A10
    if (ctx->r8 == 0) {
        // 0x800379D4: lwc1        $f18, 0x3C($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X3C);
            goto L_80037A10;
    }
    goto skip_21;
    // 0x800379D4: lwc1        $f18, 0x3C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X3C);
    skip_21:
    // 0x800379D8: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x800379DC: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x800379E0: lwc1        $f2, 0x48($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X48);
    // 0x800379E4: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800379E8: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
    // 0x800379EC: lwc1        $f0, 0x3C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x800379F0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800379F4: nop

    // 0x800379F8: bc1fl       L_80037A40
    if (!c1cs) {
        // 0x800379FC: lh          $t1, 0x6C($s0)
        ctx->r9 = MEM_H(ctx->r16, 0X6C);
            goto L_80037A40;
    }
    goto skip_22;
    // 0x800379FC: lh          $t1, 0x6C($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X6C);
    skip_22:
    // 0x80037A00: swc1        $f2, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f2.u32l;
    // 0x80037A04: b           L_80037A3C
    // 0x80037A08: lwc1        $f0, 0x3C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
        goto L_80037A3C;
    // 0x80037A08: lwc1        $f0, 0x3C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80037A0C: lwc1        $f18, 0x3C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X3C);
L_80037A10:
    // 0x80037A10: lwc1        $f16, 0x4C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80037A14: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80037A18: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80037A1C: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    // 0x80037A20: lwc1        $f0, 0x3C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80037A24: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80037A28: nop

    // 0x80037A2C: bc1fl       L_80037A40
    if (!c1cs) {
        // 0x80037A30: lh          $t1, 0x6C($s0)
        ctx->r9 = MEM_H(ctx->r16, 0X6C);
            goto L_80037A40;
    }
    goto skip_23;
    // 0x80037A30: lh          $t1, 0x6C($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X6C);
    skip_23:
    // 0x80037A34: swc1        $f2, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f2.u32l;
    // 0x80037A38: lwc1        $f0, 0x3C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
L_80037A3C:
    // 0x80037A3C: lh          $t1, 0x6C($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X6C);
L_80037A40:
    // 0x80037A40: lwc1        $f2, 0x18($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80037A44: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80037A48: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x80037A4C: beq         $t1, $zero, L_80037A68
    if (ctx->r9 == 0) {
        // 0x80037A50: sub.s       $f12, $f6, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f2.fl;
            goto L_80037A68;
    }
    // 0x80037A50: sub.s       $f12, $f6, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x80037A54: lwc1        $f10, 0x50($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80037A58: mul.s       $f8, $f12, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x80037A5C: add.s       $f18, $f2, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x80037A60: b           L_80037A7C
    // 0x80037A64: swc1        $f18, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f18.u32l;
        goto L_80037A7C;
    // 0x80037A64: swc1        $f18, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f18.u32l;
L_80037A68:
    // 0x80037A68: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80037A6C: add.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80037A70: mul.s       $f4, $f12, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x80037A74: add.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x80037A78: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
L_80037A7C:
    // 0x80037A7C: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80037A80: lwc1        $f8, 0x72E8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X72E8);
    // 0x80037A84: mul.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80037A88: jal         0x8004F7C0
    // 0x80037A8C: nop

    func_8004F7C0(rdram, ctx);
        goto after_38;
    // 0x80037A8C: nop

    after_38:
    // 0x80037A90: lwc1        $f18, 0x3C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80037A94: neg.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = -ctx->f0.fl;
    // 0x80037A98: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80037A9C: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80037AA0: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80037AA4: swc1        $f4, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f4.u32l;
    // 0x80037AA8: lwc1        $f10, 0x72EC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X72EC);
    // 0x80037AAC: mul.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80037AB0: jal         0x8004F650
    // 0x80037AB4: nop

    func_8004F650(rdram, ctx);
        goto after_39;
    // 0x80037AB4: nop

    after_39:
    // 0x80037AB8: lwc1        $f8, 0x44($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80037ABC: neg.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = -ctx->f0.fl;
    // 0x80037AC0: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80037AC4: mul.s       $f2, $f8, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80037AC8: lwc1        $f4, 0x60($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X60);
    // 0x80037ACC: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80037AD0: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80037AD4: addiu       $v0, $sp, 0x4C
    ctx->r2 = ADD32(ctx->r29, 0X4C);
    // 0x80037AD8: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80037ADC: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x80037AE0: swc1        $f2, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f2.u32l;
    // 0x80037AE4: add.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x80037AE8: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x80037AEC: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80037AF0: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
L_80037AF4:
    // 0x80037AF4: lwc1        $f18, 0x8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80037AF8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80037AFC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80037B00: bne         $v0, $a0, L_80037AF4
    if (ctx->r2 != ctx->r4) {
        // 0x80037B04: swc1        $f18, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f18.u32l;
            goto L_80037AF4;
    }
    // 0x80037B04: swc1        $f18, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f18.u32l;
    // 0x80037B08: jal         0x8000D3A4
    // 0x80037B0C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    func_8000D3A4(rdram, ctx);
        goto after_40;
    // 0x80037B0C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_40:
    // 0x80037B10: beq         $v0, $zero, L_80037B3C
    if (ctx->r2 == 0) {
        // 0x80037B14: lwc1        $f16, 0x44($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
            goto L_80037B3C;
    }
    // 0x80037B14: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80037B18: b           L_80037B3C
    // 0x80037B1C: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
        goto L_80037B3C;
    // 0x80037B1C: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x80037B20: lh          $v0, 0x92($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X92);
L_80037B24:
    // 0x80037B24: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x80037B28: andi        $t2, $v0, 0x2000
    ctx->r10 = ctx->r2 & 0X2000;
    // 0x80037B2C: bne         $t2, $zero, L_80037B3C
    if (ctx->r10 != 0) {
        // 0x80037B30: ori         $t3, $v0, 0x2000
        ctx->r11 = ctx->r2 | 0X2000;
            goto L_80037B3C;
    }
    // 0x80037B30: ori         $t3, $v0, 0x2000
    ctx->r11 = ctx->r2 | 0X2000;
    // 0x80037B34: sh          $t3, 0x92($s0)
    MEM_H(0X92, ctx->r16) = ctx->r11;
    // 0x80037B38: sh          $t4, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r12;
L_80037B3C:
    // 0x80037B3C: jal         0x8000E074
    // 0x80037B40: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_8000E074(rdram, ctx);
        goto after_41;
    // 0x80037B40: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_41:
    // 0x80037B44: beql        $v0, $zero, L_80037B80
    if (ctx->r2 == 0) {
        // 0x80037B48: lh          $t0, 0x92($s0)
        ctx->r8 = MEM_H(ctx->r16, 0X92);
            goto L_80037B80;
    }
    goto skip_24;
    // 0x80037B48: lh          $t0, 0x92($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X92);
    skip_24:
    // 0x80037B4C: lh          $t5, 0x92($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X92);
    // 0x80037B50: lw          $t7, 0x84($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X84);
    // 0x80037B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80037B58: ori         $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 | 0X8000;
    // 0x80037B5C: sh          $t6, 0x92($s0)
    MEM_H(0X92, ctx->r16) = ctx->r14;
    // 0x80037B60: lw          $v0, 0x8($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X8);
    // 0x80037B64: lw          $t8, 0xD8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XD8);
    // 0x80037B68: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80037B6C: jal         0x8003947C
    // 0x80037B70: sw          $t9, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r25;
    func_8003947C(rdram, ctx);
        goto after_42;
    // 0x80037B70: sw          $t9, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r25;
    after_42:
    // 0x80037B74: b           L_80037BA4
    // 0x80037B78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80037BA4;
    // 0x80037B78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80037B7C: lh          $t0, 0x92($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X92);
L_80037B80:
    // 0x80037B80: lw          $t2, 0x84($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X84);
    // 0x80037B84: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80037B88: andi        $t1, $t0, 0x7FFF
    ctx->r9 = ctx->r8 & 0X7FFF;
    // 0x80037B8C: sh          $t1, 0x92($s0)
    MEM_H(0X92, ctx->r16) = ctx->r9;
    // 0x80037B90: lw          $v0, 0x8($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X8);
    // 0x80037B94: lw          $t3, 0xD8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XD8);
    // 0x80037B98: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x80037B9C: sw          $t4, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r12;
L_80037BA0:
    // 0x80037BA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80037BA4:
    // 0x80037BA4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80037BA8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80037BAC: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80037BB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80037BB4: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80037BB8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80037BBC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80037BC0: lhu         $t6, 0x90($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X90);
    // 0x80037BC4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80037BC8: sltiu       $at, $t6, 0x17
    ctx->r1 = ctx->r14 < 0X17 ? 1 : 0;
    // 0x80037BCC: beq         $at, $zero, L_8003824C
    if (ctx->r1 == 0) {
        // 0x80037BD0: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8003824C;
    }
    // 0x80037BD0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80037BD4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80037BD8: addu        $at, $at, $t6
    gpr jr_addend_80037BE0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80037BDC: lw          $t6, 0x72F0($at)
    ctx->r14 = ADD32(ctx->r1, 0X72F0);
    // 0x80037BE0: jr          $t6
    // 0x80037BE4: nop

    switch (jr_addend_80037BE0 >> 2) {
        case 0: goto L_80037BE8; break;
        case 1: goto L_80037C98; break;
        case 2: goto L_80037D2C; break;
        case 3: goto L_80037D48; break;
        case 4: goto L_80037E40; break;
        case 5: goto L_80037E58; break;
        case 6: goto L_80037EC4; break;
        case 7: goto L_80037EF4; break;
        case 8: goto L_80037F44; break;
        case 9: goto L_80037F90; break;
        case 10: goto L_8003824C; break;
        case 11: goto L_8003824C; break;
        case 12: goto L_8003824C; break;
        case 13: goto L_8003824C; break;
        case 14: goto L_8003824C; break;
        case 15: goto L_8003824C; break;
        case 16: goto L_8003824C; break;
        case 17: goto L_8003824C; break;
        case 18: goto L_8003824C; break;
        case 19: goto L_8003824C; break;
        case 20: goto L_80038078; break;
        case 21: goto L_800380E8; break;
        case 22: goto L_800381B8; break;
        default: switch_error(__func__, 0x80037BE0, 0x800772F0);
    }
    // 0x80037BE4: nop

L_80037BE8:
    // 0x80037BE8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80037BEC: sh          $zero, -0x65E0($at)
    MEM_H(-0X65E0, ctx->r1) = 0;
    // 0x80037BF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80037BF4: jal         0x80039158
    // 0x80037BF8: addiu       $a1, $zero, 0x201
    ctx->r5 = ADD32(0, 0X201);
    func_80039158(rdram, ctx);
        goto after_0;
    // 0x80037BF8: addiu       $a1, $zero, 0x201
    ctx->r5 = ADD32(0, 0X201);
    after_0:
    // 0x80037BFC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80037C00: lw          $t7, -0x6630($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6630);
    // 0x80037C04: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80037C08: lwc1        $f0, 0x734C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X734C);
    // 0x80037C0C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80037C10: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80037C14: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80037C18: lwc1        $f4, -0x64AC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X64AC);
    // 0x80037C1C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80037C20: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80037C24: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80037C28: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80037C2C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80037C30: swc1        $f8, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f8.u32l;
    // 0x80037C34: lwc1        $f10, 0x7350($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7350);
    // 0x80037C38: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80037C3C: swc1        $f10, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f10.u32l;
    // 0x80037C40: lwc1        $f16, 0x7354($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7354);
    // 0x80037C44: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80037C48: swc1        $f0, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->f0.u32l;
    // 0x80037C4C: swc1        $f16, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f16.u32l;
    // 0x80037C50: lwc1        $f18, 0x7358($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7358);
    // 0x80037C54: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80037C58: swc1        $f18, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f18.u32l;
    // 0x80037C5C: lwc1        $f4, 0x735C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X735C);
    // 0x80037C60: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80037C64: swc1        $f0, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->f0.u32l;
    // 0x80037C68: swc1        $f4, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->f4.u32l;
    // 0x80037C6C: lwc1        $f6, 0x7360($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7360);
    // 0x80037C70: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80037C74: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80037C78: sh          $zero, 0xB4($s0)
    MEM_H(0XB4, ctx->r16) = 0;
    // 0x80037C7C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80037C80: swc1        $f6, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f6.u32l;
    // 0x80037C84: swc1        $f8, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f8.u32l;
    // 0x80037C88: sh          $zero, -0x65F8($at)
    MEM_H(-0X65F8, ctx->r1) = 0;
    // 0x80037C8C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80037C90: sw          $s0, -0x65F0($at)
    MEM_W(-0X65F0, ctx->r1) = ctx->r16;
    // 0x80037C94: sh          $t9, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r25;
L_80037C98:
    // 0x80037C98: lh          $t2, 0xB4($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XB4);
    // 0x80037C9C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80037CA0: lh          $t1, 0x30($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X30);
    // 0x80037CA4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80037CA8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80037CAC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80037CB0: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80037CB4: sh          $t3, 0xB4($s0)
    MEM_H(0XB4, ctx->r16) = ctx->r11;
    // 0x80037CB8: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80037CBC: sh          $t1, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r9;
    // 0x80037CC0: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x80037CC4: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x80037CC8: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    // 0x80037CCC: lh          $t4, -0x65F6($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X65F6);
    // 0x80037CD0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80037CD4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80037CD8: beql        $t4, $zero, L_80038250
    if (ctx->r12 == 0) {
        // 0x80037CDC: addiu       $t3, $s0, 0x8
        ctx->r11 = ADD32(ctx->r16, 0X8);
            goto L_80038250;
    }
    goto skip_0;
    // 0x80037CDC: addiu       $t3, $s0, 0x8
    ctx->r11 = ADD32(ctx->r16, 0X8);
    skip_0:
    // 0x80037CE0: lh          $t5, 0xB4($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XB4);
    // 0x80037CE4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80037CE8: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80037CEC: andi        $t6, $t5, 0xFFFE
    ctx->r14 = ctx->r13 & 0XFFFE;
    // 0x80037CF0: sh          $t6, 0xB4($s0)
    MEM_H(0XB4, ctx->r16) = ctx->r14;
    // 0x80037CF4: lh          $t7, 0xB4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XB4);
    // 0x80037CF8: addiu       $t0, $t0, -0x65AC
    ctx->r8 = ADD32(ctx->r8, -0X65AC);
    // 0x80037CFC: addiu       $v1, $v1, -0x65B8
    ctx->r3 = ADD32(ctx->r3, -0X65B8);
    // 0x80037D00: ori         $t8, $t7, 0x4
    ctx->r24 = ctx->r15 | 0X4;
    // 0x80037D04: sh          $t8, 0xB4($s0)
    MEM_H(0XB4, ctx->r16) = ctx->r24;
L_80037D08:
    // 0x80037D08: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80037D0C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80037D10: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80037D14: bne         $v1, $t0, L_80037D08
    if (ctx->r3 != ctx->r8) {
        // 0x80037D18: swc1        $f4, 0xB4($v0)
        MEM_W(0XB4, ctx->r2) = ctx->f4.u32l;
            goto L_80037D08;
    }
    // 0x80037D18: swc1        $f4, 0xB4($v0)
    MEM_W(0XB4, ctx->r2) = ctx->f4.u32l;
    // 0x80037D1C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80037D20: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80037D24: sh          $t9, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r25;
    // 0x80037D28: swc1        $f6, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f6.u32l;
L_80037D2C:
    // 0x80037D2C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80037D30: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80037D34: sh          $t1, 0x6C($s0)
    MEM_H(0X6C, ctx->r16) = ctx->r9;
    // 0x80037D38: sh          $t2, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r10;
    // 0x80037D3C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80037D40: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80037D44: sh          $t3, -0x65E0($at)
    MEM_H(-0X65E0, ctx->r1) = ctx->r11;
L_80037D48:
    // 0x80037D48: addiu       $a2, $s0, 0x8
    ctx->r6 = ADD32(ctx->r16, 0X8);
    // 0x80037D4C: addiu       $a3, $s0, 0xB8
    ctx->r7 = ADD32(ctx->r16, 0XB8);
    // 0x80037D50: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80037D54: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80037D58: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    // 0x80037D5C: jal         0x8000CD08
    // 0x80037D60: addiu       $a1, $s0, 0x14
    ctx->r5 = ADD32(ctx->r16, 0X14);
    func_8000CD08(rdram, ctx);
        goto after_1;
    // 0x80037D60: addiu       $a1, $s0, 0x14
    ctx->r5 = ADD32(ctx->r16, 0X14);
    after_1:
    // 0x80037D64: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80037D68: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80037D6C: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80037D70: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80037D74: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80037D78: nop

    // 0x80037D7C: bc1fl       L_80037D9C
    if (!c1cs) {
        // 0x80037D80: lwc1        $f18, 0x18($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X18);
            goto L_80037D9C;
    }
    goto skip_1;
    // 0x80037D80: lwc1        $f18, 0x18($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X18);
    skip_1:
    // 0x80037D84: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80037D88: nop

    // 0x80037D8C: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80037D90: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    // 0x80037D94: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80037D98: lwc1        $f18, 0x18($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X18);
L_80037D9C:
    // 0x80037D9C: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80037DA0: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x80037DA4: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    // 0x80037DA8: lh          $t4, -0x6624($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X6624);
    // 0x80037DAC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80037DB0: bne         $t4, $zero, L_80037DD4
    if (ctx->r12 != 0) {
        // 0x80037DB4: nop
    
            goto L_80037DD4;
    }
    // 0x80037DB4: nop

L_80037DB8:
    // 0x80037DB8: lh          $t5, 0xB4($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XB4);
    // 0x80037DBC: andi        $t6, $t5, 0xFFFB
    ctx->r14 = ctx->r13 & 0XFFFB;
    // 0x80037DC0: sh          $t6, 0xB4($s0)
    MEM_H(0XB4, ctx->r16) = ctx->r14;
    // 0x80037DC4: lh          $t7, 0xB4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XB4);
    // 0x80037DC8: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x80037DCC: b           L_80037F6C
    // 0x80037DD0: sh          $t8, 0xB4($s0)
    MEM_H(0XB4, ctx->r16) = ctx->r24;
        goto L_80037F6C;
    // 0x80037DD0: sh          $t8, 0xB4($s0)
    MEM_H(0XB4, ctx->r16) = ctx->r24;
L_80037DD4:
    // 0x80037DD4: jal         0x8000C8E8
    // 0x80037DD8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8000C8E8(rdram, ctx);
        goto after_2;
    // 0x80037DD8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80037DDC: lwc1        $f6, 0xC4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80037DE0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80037DE4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80037DE8: nop

    // 0x80037DEC: bc1fl       L_80038250
    if (!c1cs) {
        // 0x80037DF0: addiu       $t3, $s0, 0x8
        ctx->r11 = ADD32(ctx->r16, 0X8);
            goto L_80038250;
    }
    goto skip_2;
    // 0x80037DF0: addiu       $t3, $s0, 0x8
    ctx->r11 = ADD32(ctx->r16, 0X8);
    skip_2:
    // 0x80037DF4: jal         0x80036F84
    // 0x80037DF8: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    func_80036F84(rdram, ctx);
        goto after_3;
    // 0x80037DF8: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    after_3:
    // 0x80037DFC: beq         $v0, $zero, L_80037DB8
    if (ctx->r2 == 0) {
        // 0x80037E00: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80037DB8;
    }
    // 0x80037E00: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80037E04: jal         0x80036F84
    // 0x80037E08: lui         $a1, 0x42F0
    ctx->r5 = S32(0X42F0 << 16);
    func_80036F84(rdram, ctx);
        goto after_4;
    // 0x80037E08: lui         $a1, 0x42F0
    ctx->r5 = S32(0X42F0 << 16);
    after_4:
    // 0x80037E0C: beql        $v0, $zero, L_80038250
    if (ctx->r2 == 0) {
        // 0x80037E10: addiu       $t3, $s0, 0x8
        ctx->r11 = ADD32(ctx->r16, 0X8);
            goto L_80038250;
    }
    goto skip_3;
    // 0x80037E10: addiu       $t3, $s0, 0x8
    ctx->r11 = ADD32(ctx->r16, 0X8);
    skip_3:
    // 0x80037E14: jal         0x80036E84
    // 0x80037E18: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_80036E84(rdram, ctx);
        goto after_5;
    // 0x80037E18: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x80037E1C: lh          $t9, 0x14($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X14);
    // 0x80037E20: beql        $t9, $zero, L_80038250
    if (ctx->r25 == 0) {
        // 0x80037E24: addiu       $t3, $s0, 0x8
        ctx->r11 = ADD32(ctx->r16, 0X8);
            goto L_80038250;
    }
    goto skip_4;
    // 0x80037E24: addiu       $t3, $s0, 0x8
    ctx->r11 = ADD32(ctx->r16, 0X8);
    skip_4:
    // 0x80037E28: lh          $t1, 0xB4($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XB4);
    // 0x80037E2C: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80037E30: sh          $t3, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r11;
    // 0x80037E34: andi        $t2, $t1, 0xFFFB
    ctx->r10 = ctx->r9 & 0XFFFB;
    // 0x80037E38: b           L_8003824C
    // 0x80037E3C: sh          $t2, 0xB4($s0)
    MEM_H(0XB4, ctx->r16) = ctx->r10;
        goto L_8003824C;
    // 0x80037E3C: sh          $t2, 0xB4($s0)
    MEM_H(0XB4, ctx->r16) = ctx->r10;
L_80037E40:
    // 0x80037E40: lh          $t4, 0xB4($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XB4);
    // 0x80037E44: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80037E48: sh          $zero, 0x6C($s0)
    MEM_H(0X6C, ctx->r16) = 0;
    // 0x80037E4C: ori         $t5, $t4, 0x10
    ctx->r13 = ctx->r12 | 0X10;
    // 0x80037E50: sh          $t5, 0xB4($s0)
    MEM_H(0XB4, ctx->r16) = ctx->r13;
    // 0x80037E54: sh          $t6, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r14;
L_80037E58:
    // 0x80037E58: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    // 0x80037E5C: addiu       $a1, $s0, 0x14
    ctx->r5 = ADD32(ctx->r16, 0X14);
    // 0x80037E60: addiu       $a2, $s0, 0x8
    ctx->r6 = ADD32(ctx->r16, 0X8);
    // 0x80037E64: jal         0x8000CD08
    // 0x80037E68: addiu       $a3, $s0, 0xB8
    ctx->r7 = ADD32(ctx->r16, 0XB8);
    func_8000CD08(rdram, ctx);
        goto after_6;
    // 0x80037E68: addiu       $a3, $s0, 0xB8
    ctx->r7 = ADD32(ctx->r16, 0XB8);
    after_6:
    // 0x80037E6C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80037E70: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80037E74: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80037E78: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80037E7C: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x80037E80: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80037E84: nop

    // 0x80037E88: bc1fl       L_80037EA8
    if (!c1cs) {
        // 0x80037E8C: lwc1        $f18, 0x18($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X18);
            goto L_80037EA8;
    }
    goto skip_5;
    // 0x80037E8C: lwc1        $f18, 0x18($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X18);
    skip_5:
    // 0x80037E90: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80037E94: nop

    // 0x80037E98: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80037E9C: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    // 0x80037EA0: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80037EA4: lwc1        $f18, 0x18($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X18);
L_80037EA8:
    // 0x80037EA8: lh          $t7, 0xB4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XB4);
    // 0x80037EAC: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x80037EB0: andi        $t8, $t7, 0x20
    ctx->r24 = ctx->r15 & 0X20;
    // 0x80037EB4: beq         $t8, $zero, L_8003824C
    if (ctx->r24 == 0) {
        // 0x80037EB8: swc1        $f4, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
            goto L_8003824C;
    }
    // 0x80037EB8: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    // 0x80037EBC: b           L_8003824C
    // 0x80037EC0: sh          $t9, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r25;
        goto L_8003824C;
    // 0x80037EC0: sh          $t9, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r25;
L_80037EC4:
    // 0x80037EC4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80037EC8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80037ECC: addiu       $a0, $a0, -0x65BC
    ctx->r4 = ADD32(ctx->r4, -0X65BC);
    // 0x80037ED0: addiu       $v1, $v1, -0x65C8
    ctx->r3 = ADD32(ctx->r3, -0X65C8);
    // 0x80037ED4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80037ED8:
    // 0x80037ED8: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80037EDC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80037EE0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80037EE4: bne         $v1, $a0, L_80037ED8
    if (ctx->r3 != ctx->r4) {
        // 0x80037EE8: swc1        $f6, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f6.u32l;
            goto L_80037ED8;
    }
    // 0x80037EE8: swc1        $f6, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f6.u32l;
    // 0x80037EEC: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x80037EF0: sh          $t1, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r9;
L_80037EF4:
    // 0x80037EF4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80037EF8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80037EFC: sh          $t2, -0x65BC($at)
    MEM_H(-0X65BC, ctx->r1) = ctx->r10;
    // 0x80037F00: lh          $t3, 0x2E($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X2E);
    // 0x80037F04: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
    // 0x80037F08: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80037F0C: beq         $v0, $t3, L_80037F28
    if (ctx->r2 == ctx->r11) {
        // 0x80037F10: addiu       $a0, $a0, -0x65C8
        ctx->r4 = ADD32(ctx->r4, -0X65C8);
            goto L_80037F28;
    }
    // 0x80037F10: addiu       $a0, $a0, -0x65C8
    ctx->r4 = ADD32(ctx->r4, -0X65C8);
    // 0x80037F14: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80037F18: lh          $t4, -0x65F8($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X65F8);
    // 0x80037F1C: beq         $t4, $zero, L_80037F28
    if (ctx->r12 == 0) {
        // 0x80037F20: nop
    
            goto L_80037F28;
    }
    // 0x80037F20: nop

    // 0x80037F24: sh          $v0, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r2;
L_80037F28:
    // 0x80037F28: jal         0x80036F84
    // 0x80037F2C: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    func_80036F84(rdram, ctx);
        goto after_7;
    // 0x80037F2C: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    after_7:
    // 0x80037F30: bne         $v0, $zero, L_8003824C
    if (ctx->r2 != 0) {
        // 0x80037F34: addiu       $t5, $zero, 0x8
        ctx->r13 = ADD32(0, 0X8);
            goto L_8003824C;
    }
    // 0x80037F34: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x80037F38: sh          $t5, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r13;
    // 0x80037F3C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80037F40: sh          $zero, -0x65E0($at)
    MEM_H(-0X65E0, ctx->r1) = 0;
L_80037F44:
    // 0x80037F44: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80037F48: sh          $zero, -0x65BC($at)
    MEM_H(-0X65BC, ctx->r1) = 0;
    // 0x80037F4C: lh          $t6, 0xB4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XB4);
    // 0x80037F50: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80037F54: sh          $t1, 0x6C($s0)
    MEM_H(0X6C, ctx->r16) = ctx->r9;
    // 0x80037F58: andi        $t7, $t6, 0xFFDF
    ctx->r15 = ctx->r14 & 0XFFDF;
    // 0x80037F5C: sh          $t7, 0xB4($s0)
    MEM_H(0XB4, ctx->r16) = ctx->r15;
    // 0x80037F60: lh          $t8, 0xB4($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XB4);
    // 0x80037F64: ori         $t9, $t8, 0x40
    ctx->r25 = ctx->r24 | 0X40;
    // 0x80037F68: sh          $t9, 0xB4($s0)
    MEM_H(0XB4, ctx->r16) = ctx->r25;
L_80037F6C:
    // 0x80037F6C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80037F70: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80037F74: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80037F78: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80037F7C: addiu       $t2, $zero, 0x9
    ctx->r10 = ADD32(0, 0X9);
    // 0x80037F80: sh          $t2, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r10;
    // 0x80037F84: swc1        $f8, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->f8.u32l;
    // 0x80037F88: swc1        $f10, 0xBC($s0)
    MEM_W(0XBC, ctx->r16) = ctx->f10.u32l;
    // 0x80037F8C: swc1        $f16, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f16.u32l;
L_80037F90:
    // 0x80037F90: addiu       $a2, $s0, 0x8
    ctx->r6 = ADD32(ctx->r16, 0X8);
    // 0x80037F94: addiu       $a3, $s0, 0xB8
    ctx->r7 = ADD32(ctx->r16, 0XB8);
    // 0x80037F98: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80037F9C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80037FA0: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    // 0x80037FA4: jal         0x8000CD08
    // 0x80037FA8: addiu       $a1, $s0, 0x14
    ctx->r5 = ADD32(ctx->r16, 0X14);
    func_8000CD08(rdram, ctx);
        goto after_8;
    // 0x80037FA8: addiu       $a1, $s0, 0x14
    ctx->r5 = ADD32(ctx->r16, 0X14);
    after_8:
    // 0x80037FAC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80037FB0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80037FB4: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80037FB8: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80037FBC: nop

    // 0x80037FC0: bc1f        L_80037FDC
    if (!c1cs) {
        // 0x80037FC4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80037FDC;
    }
    // 0x80037FC4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80037FC8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80037FCC: nop

    // 0x80037FD0: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80037FD4: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    // 0x80037FD8: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
L_80037FDC:
    // 0x80037FDC: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80037FE0: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80037FE4: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    // 0x80037FE8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80037FEC: jal         0x80003668
    // 0x80037FF0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80003668(rdram, ctx);
        goto after_9;
    // 0x80037FF0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_9:
    // 0x80037FF4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80037FF8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80037FFC: nop

    // 0x80038000: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80038004: nop

    // 0x80038008: bc1f        L_8003824C
    if (!c1cs) {
        // 0x8003800C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8003824C;
    }
    // 0x8003800C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80038010: lh          $v0, -0x65F8($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X65F8);
    // 0x80038014: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80038018: lw          $t3, -0x6BDC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X6BDC);
    // 0x8003801C: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x80038020: addu        $t4, $t4, $v0
    ctx->r12 = ADD32(ctx->r12, ctx->r2);
    // 0x80038024: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80038028: subu        $t4, $t4, $v0
    ctx->r12 = SUB32(ctx->r12, ctx->r2);
    // 0x8003802C: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x80038030: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80038034: addu        $t4, $t4, $v0
    ctx->r12 = ADD32(ctx->r12, ctx->r2);
    // 0x80038038: lh          $t6, -0x6622($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X6622);
    // 0x8003803C: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x80038040: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80038044: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80038048: sw          $t5, -0x6BDC($at)
    MEM_W(-0X6BDC, ctx->r1) = ctx->r13;
    // 0x8003804C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80038050: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80038054: sh          $t7, -0x6622($at)
    MEM_H(-0X6622, ctx->r1) = ctx->r15;
    // 0x80038058: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8003805C: sh          $zero, -0x65F8($at)
    MEM_H(-0X65F8, ctx->r1) = 0;
    // 0x80038060: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80038064: sh          $zero, -0x65F6($at)
    MEM_H(-0X65F6, ctx->r1) = 0;
    // 0x80038068: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8003806C: sh          $zero, 0xB4($s0)
    MEM_H(0XB4, ctx->r16) = 0;
    // 0x80038070: b           L_80037C98
    // 0x80038074: sh          $t8, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r24;
        goto L_80037C98;
    // 0x80038074: sh          $t8, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r24;
L_80038078:
    // 0x80038078: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003807C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80038080: sh          $zero, -0x65E0($at)
    MEM_H(-0X65E0, ctx->r1) = 0;
    // 0x80038084: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80038088: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x8003808C: lwc1        $f18, 0x7364($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7364);
    // 0x80038090: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80038094: swc1        $f0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f0.u32l;
    // 0x80038098: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
L_8003809C:
    // 0x8003809C: jal         0x8000E35C
    // 0x800380A0: sw          $v1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r3;
    func_8000E35C(rdram, ctx);
        goto after_10;
    // 0x800380A0: sw          $v1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r3;
    after_10:
    // 0x800380A4: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x800380A8: beq         $t9, $zero, L_800380C4
    if (ctx->r25 == 0) {
        // 0x800380AC: lw          $v1, 0x8C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X8C);
            goto L_800380C4;
    }
    // 0x800380AC: lw          $v1, 0x8C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X8C);
    // 0x800380B0: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x800380B4: addu        $v0, $s0, $t1
    ctx->r2 = ADD32(ctx->r16, ctx->r9);
    // 0x800380B8: lwc1        $f4, 0x54($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X54);
    // 0x800380BC: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800380C0: swc1        $f6, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f6.u32l;
L_800380C4:
    // 0x800380C4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800380C8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800380CC: bne         $v1, $at, L_8003809C
    if (ctx->r3 != ctx->r1) {
        // 0x800380D0: nop
    
            goto L_8003809C;
    }
    // 0x800380D0: nop

    // 0x800380D4: addiu       $t2, $zero, 0xC8
    ctx->r10 = ADD32(0, 0XC8);
    // 0x800380D8: addiu       $t3, $zero, 0x15
    ctx->r11 = ADD32(0, 0X15);
    // 0x800380DC: sh          $t2, 0xAC($s0)
    MEM_H(0XAC, ctx->r16) = ctx->r10;
    // 0x800380E0: sh          $zero, 0xAE($s0)
    MEM_H(0XAE, ctx->r16) = 0;
    // 0x800380E4: sh          $t3, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r11;
L_800380E8:
    // 0x800380E8: lh          $t4, 0xAE($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XAE);
    // 0x800380EC: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x800380F0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800380F4: bne         $t4, $zero, L_80038128
    if (ctx->r12 != 0) {
        // 0x800380F8: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80038128;
    }
    // 0x800380F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800380FC: jal         0x80042F80
    // 0x80038100: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_80042F80(rdram, ctx);
        goto after_11;
    // 0x80038100: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_11:
    // 0x80038104: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80038108: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8003810C: jal         0x80043714
    // 0x80038110: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80043714(rdram, ctx);
        goto after_12;
    // 0x80038110: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
    // 0x80038114: jal         0x8000E35C
    // 0x80038118: nop

    func_8000E35C(rdram, ctx);
        goto after_13;
    // 0x80038118: nop

    after_13:
    // 0x8003811C: andi        $t5, $v0, 0x3F
    ctx->r13 = ctx->r2 & 0X3F;
    // 0x80038120: addiu       $t6, $t5, 0x14
    ctx->r14 = ADD32(ctx->r13, 0X14);
    // 0x80038124: sh          $t6, 0xAE($s0)
    MEM_H(0XAE, ctx->r16) = ctx->r14;
L_80038128:
    // 0x80038128: lh          $t7, 0x6C($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X6C);
    // 0x8003812C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80038130: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80038134: bne         $t7, $at, L_80038168
    if (ctx->r15 != ctx->r1) {
        // 0x80038138: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_80038168;
    }
    // 0x80038138: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8003813C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80038140: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80038144: lwc1        $f0, 0x3C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80038148: lwc1        $f8, 0x1C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8003814C: lwc1        $f10, 0x5C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x80038150: div.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80038154: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80038158: swc1        $f16, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f16.u32l;
    // 0x8003815C: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80038160: b           L_800381A4
    // 0x80038164: swc1        $f6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f6.u32l;
        goto L_800381A4;
    // 0x80038164: swc1        $f6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f6.u32l;
L_80038168:
    // 0x80038168: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8003816C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80038170: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80038174: beq         $v1, $a1, L_80038198
    if (ctx->r3 == ctx->r5) {
        // 0x80038178: lwc1        $f16, 0x54($v0)
        ctx->f16.u32l = MEM_W(ctx->r2, 0X54);
            goto L_80038198;
    }
    // 0x80038178: lwc1        $f16, 0x54($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X54);
L_8003817C:
    // 0x8003817C: add.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80038180: lwc1        $f18, 0x18($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80038184: lwc1        $f16, 0x58($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80038188: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8003818C: swc1        $f14, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f14.u32l;
    // 0x80038190: bne         $v1, $a1, L_8003817C
    if (ctx->r3 != ctx->r5) {
        // 0x80038194: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8003817C;
    }
    // 0x80038194: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80038198:
    // 0x80038198: add.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8003819C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800381A0: swc1        $f14, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f14.u32l;
L_800381A4:
    // 0x800381A4: lh          $t8, 0xAC($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XAC);
    // 0x800381A8: bnel        $t8, $zero, L_80038250
    if (ctx->r24 != 0) {
        // 0x800381AC: addiu       $t3, $s0, 0x8
        ctx->r11 = ADD32(ctx->r16, 0X8);
            goto L_80038250;
    }
    goto skip_6;
    // 0x800381AC: addiu       $t3, $s0, 0x8
    ctx->r11 = ADD32(ctx->r16, 0X8);
    skip_6:
    // 0x800381B0: b           L_8003824C
    // 0x800381B4: sh          $zero, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = 0;
        goto L_8003824C;
    // 0x800381B4: sh          $zero, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = 0;
L_800381B8:
    // 0x800381B8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800381BC: sh          $zero, -0x65BC($at)
    MEM_H(-0X65BC, ctx->r1) = 0;
    // 0x800381C0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800381C4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800381C8: addiu       $v0, $v0, -0x6620
    ctx->r2 = ADD32(ctx->r2, -0X6620);
    // 0x800381CC: sh          $zero, -0x65F6($at)
    MEM_H(-0X65F6, ctx->r1) = 0;
    // 0x800381D0: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800381D4: lh          $t1, -0x65F8($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X65F8);
    // 0x800381D8: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x800381DC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800381E0: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x800381E4: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x800381E8: sh          $t2, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r10;
    // 0x800381EC: sh          $zero, -0x65F8($at)
    MEM_H(-0X65F8, ctx->r1) = 0;
    // 0x800381F0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800381F4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x800381F8: jal         0x80042F80
    // 0x800381FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80042F80(rdram, ctx);
        goto after_14;
    // 0x800381FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_14:
    // 0x80038200: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80038204: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80038208: jal         0x80043714
    // 0x8003820C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80043714(rdram, ctx);
        goto after_15;
    // 0x8003820C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_15:
    // 0x80038210: jal         0x80036E0C
    // 0x80038214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80036E0C(rdram, ctx);
        goto after_16;
    // 0x80038214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80038218: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003821C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80038220: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80038224: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    // 0x80038228: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x8003822C: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x80038230: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x80038234: jal         0x80039724
    // 0x80038238: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    func_80039724(rdram, ctx);
        goto after_17;
    // 0x80038238: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    after_17:
    // 0x8003823C: jal         0x80044480
    // 0x80038240: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    func_80044480(rdram, ctx);
        goto after_18;
    // 0x80038240: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    after_18:
    // 0x80038244: b           L_800389DC
    // 0x80038248: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800389DC;
    // 0x80038248: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8003824C:
    // 0x8003824C: addiu       $t3, $s0, 0x8
    ctx->r11 = ADD32(ctx->r16, 0X8);
L_80038250:
    // 0x80038250: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x80038254: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80038258: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8003825C:
    // 0x8003825C: lh          $v1, 0xAC($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XAC);
    // 0x80038260: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80038264: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x80038268: beq         $v1, $zero, L_80038274
    if (ctx->r3 == 0) {
        // 0x8003826C: addiu       $t4, $v1, -0x1
        ctx->r12 = ADD32(ctx->r3, -0X1);
            goto L_80038274;
    }
    // 0x8003826C: addiu       $t4, $v1, -0x1
    ctx->r12 = ADD32(ctx->r3, -0X1);
    // 0x80038270: sh          $t4, 0xAC($v0)
    MEM_H(0XAC, ctx->r2) = ctx->r12;
L_80038274:
    // 0x80038274: bne         $at, $zero, L_8003825C
    if (ctx->r1 != 0) {
        // 0x80038278: addiu       $v0, $v0, 0x2
        ctx->r2 = ADD32(ctx->r2, 0X2);
            goto L_8003825C;
    }
    // 0x80038278: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8003827C: lh          $v0, 0x2E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2E);
    // 0x80038280: bgtz        $v0, L_80038290
    if (SIGNED(ctx->r2) > 0) {
        // 0x80038284: addiu       $t5, $zero, 0x16
        ctx->r13 = ADD32(0, 0X16);
            goto L_80038290;
    }
    // 0x80038284: addiu       $t5, $zero, 0x16
    ctx->r13 = ADD32(0, 0X16);
    // 0x80038288: b           L_800382D4
    // 0x8003828C: sh          $t5, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r13;
        goto L_800382D4;
    // 0x8003828C: sh          $t5, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r13;
L_80038290:
    // 0x80038290: lh          $v1, 0x92($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X92);
    // 0x80038294: slti        $at, $v0, 0x33
    ctx->r1 = SIGNED(ctx->r2) < 0X33 ? 1 : 0;
    // 0x80038298: andi        $t6, $v1, 0x2000
    ctx->r14 = ctx->r3 & 0X2000;
    // 0x8003829C: bnel        $t6, $zero, L_800382D8
    if (ctx->r14 != 0) {
        // 0x800382A0: lh          $v0, 0x6C($s0)
        ctx->r2 = MEM_H(ctx->r16, 0X6C);
            goto L_800382D8;
    }
    goto skip_7;
    // 0x800382A0: lh          $v0, 0x6C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6C);
    skip_7:
    // 0x800382A4: beq         $at, $zero, L_800382C0
    if (ctx->r1 == 0) {
        // 0x800382A8: andi        $t9, $v1, 0x1000
        ctx->r25 = ctx->r3 & 0X1000;
            goto L_800382C0;
    }
    // 0x800382A8: andi        $t9, $v1, 0x1000
    ctx->r25 = ctx->r3 & 0X1000;
    // 0x800382AC: ori         $t7, $v1, 0x2000
    ctx->r15 = ctx->r3 | 0X2000;
    // 0x800382B0: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x800382B4: sh          $t7, 0x92($s0)
    MEM_H(0X92, ctx->r16) = ctx->r15;
    // 0x800382B8: b           L_800382D4
    // 0x800382BC: sh          $t8, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r24;
        goto L_800382D4;
    // 0x800382BC: sh          $t8, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r24;
L_800382C0:
    // 0x800382C0: bne         $t9, $zero, L_800382D4
    if (ctx->r25 != 0) {
        // 0x800382C4: slti        $at, $v0, 0x51
        ctx->r1 = SIGNED(ctx->r2) < 0X51 ? 1 : 0;
            goto L_800382D4;
    }
    // 0x800382C4: slti        $at, $v0, 0x51
    ctx->r1 = SIGNED(ctx->r2) < 0X51 ? 1 : 0;
    // 0x800382C8: beq         $at, $zero, L_800382D4
    if (ctx->r1 == 0) {
        // 0x800382CC: ori         $t1, $v1, 0x1000
        ctx->r9 = ctx->r3 | 0X1000;
            goto L_800382D4;
    }
    // 0x800382CC: ori         $t1, $v1, 0x1000
    ctx->r9 = ctx->r3 | 0X1000;
    // 0x800382D0: sh          $t1, 0x92($s0)
    MEM_H(0X92, ctx->r16) = ctx->r9;
L_800382D4:
    // 0x800382D4: lh          $v0, 0x6C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6C);
L_800382D8:
    // 0x800382D8: beq         $v0, $zero, L_800382F4
    if (ctx->r2 == 0) {
        // 0x800382DC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800382F4;
    }
    // 0x800382DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800382E0: beql        $v0, $at, L_8003833C
    if (ctx->r2 == ctx->r1) {
        // 0x800382E4: lwc1        $f18, 0x3C($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X3C);
            goto L_8003833C;
    }
    goto skip_8;
    // 0x800382E4: lwc1        $f18, 0x3C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X3C);
    skip_8:
    // 0x800382E8: lwc1        $f14, 0x18($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800382EC: b           L_80038370
    // 0x800382F0: lwc1        $f0, 0x3C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
        goto L_80038370;
    // 0x800382F0: lwc1        $f0, 0x3C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
L_800382F4:
    // 0x800382F4: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x800382F8: lwc1        $f6, 0x4C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x800382FC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80038300: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80038304: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
    // 0x80038308: lwc1        $f0, 0x3C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8003830C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80038310: nop

    // 0x80038314: bc1fl       L_80038330
    if (!c1cs) {
        // 0x80038318: lwc1        $f14, 0x18($s0)
        ctx->f14.u32l = MEM_W(ctx->r16, 0X18);
            goto L_80038330;
    }
    goto skip_9;
    // 0x80038318: lwc1        $f14, 0x18($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X18);
    skip_9:
    // 0x8003831C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80038320: nop

    // 0x80038324: swc1        $f16, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f16.u32l;
    // 0x80038328: lwc1        $f0, 0x3C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8003832C: lwc1        $f14, 0x18($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X18);
L_80038330:
    // 0x80038330: b           L_80038370
    // 0x80038334: lh          $v0, 0x6C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6C);
        goto L_80038370;
    // 0x80038334: lh          $v0, 0x6C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6C);
    // 0x80038338: lwc1        $f18, 0x3C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X3C);
L_8003833C:
    // 0x8003833C: lwc1        $f4, 0x4C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80038340: lwc1        $f2, 0x48($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80038344: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80038348: swc1        $f6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f6.u32l;
    // 0x8003834C: lwc1        $f0, 0x3C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80038350: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80038354: nop

    // 0x80038358: bc1fl       L_8003836C
    if (!c1cs) {
        // 0x8003835C: lwc1        $f14, 0x18($s0)
        ctx->f14.u32l = MEM_W(ctx->r16, 0X18);
            goto L_8003836C;
    }
    goto skip_10;
    // 0x8003835C: lwc1        $f14, 0x18($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X18);
    skip_10:
    // 0x80038360: swc1        $f2, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f2.u32l;
    // 0x80038364: lwc1        $f0, 0x3C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80038368: lwc1        $f14, 0x18($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X18);
L_8003836C:
    // 0x8003836C: lh          $v0, 0x6C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6C);
L_80038370:
    // 0x80038370: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80038374: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x80038378: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003837C: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x80038380: beq         $v0, $zero, L_80038398
    if (ctx->r2 == 0) {
        // 0x80038384: swc1        $f10, 0x74($sp)
        MEM_W(0X74, ctx->r29) = ctx->f10.u32l;
            goto L_80038398;
    }
    // 0x80038384: swc1        $f10, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f10.u32l;
    // 0x80038388: beq         $v0, $at, L_800383C8
    if (ctx->r2 == ctx->r1) {
        // 0x8003838C: nop
    
            goto L_800383C8;
    }
    // 0x8003838C: nop

    // 0x80038390: b           L_80038424
    // 0x80038394: nop

        goto L_80038424;
    // 0x80038394: nop

L_80038398:
    // 0x80038398: lh          $t2, 0x92($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X92);
    // 0x8003839C: andi        $t3, $t2, 0x2000
    ctx->r11 = ctx->r10 & 0X2000;
    // 0x800383A0: bne         $t3, $zero, L_80038424
    if (ctx->r11 != 0) {
        // 0x800383A4: nop
    
            goto L_80038424;
    }
    // 0x800383A4: nop

    // 0x800383A8: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800383AC: lwc1        $f16, 0x74($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800383B0: add.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800383B4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800383B8: add.s       $f6, $f14, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f4.fl;
    // 0x800383BC: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
    // 0x800383C0: b           L_80038424
    // 0x800383C4: lwc1        $f14, 0x18($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X18);
        goto L_80038424;
    // 0x800383C4: lwc1        $f14, 0x18($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X18);
L_800383C8:
    // 0x800383C8: jal         0x8000E16C
    // 0x800383CC: lwc1        $f12, 0x74($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X74);
    func_8000E16C(rdram, ctx);
        goto after_19;
    // 0x800383CC: lwc1        $f12, 0x74($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X74);
    after_19:
    // 0x800383D0: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x800383D4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800383D8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800383DC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800383E0: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x800383E4: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800383E8: bc1fl       L_800383F8
    if (!c1cs) {
        // 0x800383EC: c.lt.s      $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
            goto L_800383F8;
    }
    goto skip_11;
    // 0x800383EC: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    skip_11:
    // 0x800383F0: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x800383F4: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
L_800383F8:
    // 0x800383F8: nop

    // 0x800383FC: bc1fl       L_8003840C
    if (!c1cs) {
        // 0x80038400: swc1        $f2, 0x74($sp)
        MEM_W(0X74, ctx->r29) = ctx->f2.u32l;
            goto L_8003840C;
    }
    goto skip_12;
    // 0x80038400: swc1        $f2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f2.u32l;
    skip_12:
    // 0x80038404: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80038408: swc1        $f2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f2.u32l;
L_8003840C:
    // 0x8003840C: lwc1        $f18, 0x50($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80038410: lwc1        $f16, 0x18($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80038414: mul.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x80038418: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8003841C: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
    // 0x80038420: lwc1        $f14, 0x18($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X18);
L_80038424:
    // 0x80038424: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80038428: lwc1        $f8, 0x7368($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7368);
    // 0x8003842C: mul.s       $f12, $f14, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x80038430: jal         0x8004F7C0
    // 0x80038434: nop

    func_8004F7C0(rdram, ctx);
        goto after_20;
    // 0x80038434: nop

    after_20:
    // 0x80038438: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8003843C: neg.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = -ctx->f0.fl;
    // 0x80038440: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80038444: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80038448: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8003844C: swc1        $f16, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f16.u32l;
    // 0x80038450: lwc1        $f6, 0x736C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X736C);
    // 0x80038454: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80038458: jal         0x8004F650
    // 0x8003845C: nop

    func_8004F650(rdram, ctx);
        goto after_21;
    // 0x8003845C: nop

    after_21:
    // 0x80038460: lwc1        $f8, 0x44($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80038464: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x80038468: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8003846C: mul.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80038470: lwc1        $f16, 0x60($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X60);
    // 0x80038474: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80038478: lh          $t4, 0xB4($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XB4);
    // 0x8003847C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80038480: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80038484: andi        $t5, $t4, 0x10
    ctx->r13 = ctx->r12 & 0X10;
    // 0x80038488: swc1        $f2, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f2.u32l;
    // 0x8003848C: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x80038490: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x80038494: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x80038498: beq         $t5, $zero, L_800384D4
    if (ctx->r13 == 0) {
        // 0x8003849C: swc1        $f8, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
            goto L_800384D4;
    }
    // 0x8003849C: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
    // 0x800384A0: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800384A4: lwc1        $f10, 0xB8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x800384A8: lwc1        $f2, 0x10($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800384AC: lwc1        $f6, 0xC0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x800384B0: sub.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x800384B4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800384B8: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x800384BC: div.s       $f16, $f18, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = DIV_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800384C0: div.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800384C4: add.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x800384C8: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x800384CC: add.s       $f18, $f2, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x800384D0: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
L_800384D4:
    // 0x800384D4: lh          $t6, 0x92($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X92);
    // 0x800384D8: andi        $t7, $t6, 0x2000
    ctx->r15 = ctx->r14 & 0X2000;
    // 0x800384DC: beql        $t7, $zero, L_80038578
    if (ctx->r15 == 0) {
        // 0x800384E0: lh          $t9, 0x6C($s0)
        ctx->r25 = MEM_H(ctx->r16, 0X6C);
            goto L_80038578;
    }
    goto skip_13;
    // 0x800384E0: lh          $t9, 0x6C($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X6C);
    skip_13:
    // 0x800384E4: lh          $t8, 0x6C($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X6C);
    // 0x800384E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800384EC: bne         $t8, $at, L_80038508
    if (ctx->r24 != ctx->r1) {
        // 0x800384F0: lui         $at, 0x8007
        ctx->r1 = S32(0X8007 << 16);
            goto L_80038508;
    }
    // 0x800384F0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800384F4: lwc1        $f4, 0x7370($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7370);
    // 0x800384F8: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800384FC: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80038500: b           L_80038538
    // 0x80038504: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
        goto L_80038538;
    // 0x80038504: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
L_80038508:
    // 0x80038508: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8003850C: lwc1        $f0, 0x40($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80038510: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80038514: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80038518: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003851C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80038520: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80038524: bc1f        L_80038538
    if (!c1cs) {
        // 0x80038528: swc1        $f10, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
            goto L_80038538;
    }
    // 0x80038528: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x8003852C: lwc1        $f16, 0x7374($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7374);
    // 0x80038530: add.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80038534: swc1        $f4, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f4.u32l;
L_80038538:
    // 0x80038538: jal         0x8000D3A4
    // 0x8003853C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_8000D3A4(rdram, ctx);
        goto after_22;
    // 0x8003853C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_22:
    // 0x80038540: beq         $v0, $zero, L_800388E8
    if (ctx->r2 == 0) {
        // 0x80038544: addiu       $a0, $sp, 0x54
        ctx->r4 = ADD32(ctx->r29, 0X54);
            goto L_800388E8;
    }
    // 0x80038544: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x80038548: jal         0x80003668
    // 0x8003854C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80003668(rdram, ctx);
        goto after_23;
    // 0x8003854C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_23:
    // 0x80038550: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80038554: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80038558: nop

    // 0x8003855C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80038560: nop

    // 0x80038564: bc1fl       L_800388EC
    if (!c1cs) {
        // 0x80038568: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800388EC;
    }
    goto skip_14;
    // 0x80038568: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    skip_14:
    // 0x8003856C: b           L_800388E8
    // 0x80038570: sh          $zero, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = 0;
        goto L_800388E8;
    // 0x80038570: sh          $zero, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = 0;
    // 0x80038574: lh          $t9, 0x6C($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X6C);
L_80038578:
    // 0x80038578: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003857C: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80038580: bnel        $t9, $at, L_80038594
    if (ctx->r25 != ctx->r1) {
        // 0x80038584: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_80038594;
    }
    goto skip_15;
    // 0x80038584: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_15:
    // 0x80038588: b           L_8003859C
    // 0x8003858C: swc1        $f8, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f8.u32l;
        goto L_8003859C;
    // 0x8003858C: swc1        $f8, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f8.u32l;
    // 0x80038590: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_80038594:
    // 0x80038594: nop

    // 0x80038598: swc1        $f10, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f10.u32l;
L_8003859C:
    // 0x8003859C: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800385A0: lwc1        $f18, 0x5C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x800385A4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800385A8: lwc1        $f4, 0x7378($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7378);
    // 0x800385AC: sub.s       $f16, $f18, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x800385B0: lh          $v0, 0xB4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB4);
    // 0x800385B4: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800385B8: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x800385BC: andi        $t2, $v0, 0x20
    ctx->r10 = ctx->r2 & 0X20;
    // 0x800385C0: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x800385C4: bne         $t1, $zero, L_800388E8
    if (ctx->r9 != 0) {
        // 0x800385C8: swc1        $f8, 0x1C($s0)
        MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
            goto L_800388E8;
    }
    // 0x800385C8: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
    // 0x800385CC: beq         $t2, $zero, L_80038618
    if (ctx->r10 == 0) {
        // 0x800385D0: lui         $at, 0x4008
        ctx->r1 = S32(0X4008 << 16);
            goto L_80038618;
    }
    // 0x800385D0: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x800385D4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800385D8: lwc1        $f0, 0xEC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x800385DC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800385E0: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x800385E4: nop

    // 0x800385E8: bc1tl       L_800388EC
    if (c1cs) {
        // 0x800385EC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800388EC;
    }
    goto skip_16;
    // 0x800385EC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    skip_16:
    // 0x800385F0: lwc1        $f10, 0x737C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X737C);
    // 0x800385F4: sub.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800385F8: swc1        $f18, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f18.u32l;
    // 0x800385FC: lwc1        $f16, 0xEC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x80038600: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x80038604: nop

    // 0x80038608: bc1fl       L_800388EC
    if (!c1cs) {
        // 0x8003860C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800388EC;
    }
    goto skip_17;
    // 0x8003860C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    skip_17:
    // 0x80038610: b           L_800388E8
    // 0x80038614: swc1        $f2, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f2.u32l;
        goto L_800388E8;
    // 0x80038614: swc1        $f2, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f2.u32l;
L_80038618:
    // 0x80038618: lwc1        $f0, 0xEC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8003861C: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x80038620: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80038624: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80038628: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003862C: c.lt.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d < ctx->f2.d;
    // 0x80038630: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80038634: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80038638: addiu       $v1, $sp, 0x6C
    ctx->r3 = ADD32(ctx->r29, 0X6C);
    // 0x8003863C: bc1fl       L_8003867C
    if (!c1cs) {
        // 0x80038640: lh          $t3, 0xB4($s0)
        ctx->r11 = MEM_H(ctx->r16, 0XB4);
            goto L_8003867C;
    }
    goto skip_18;
    // 0x80038640: lh          $t3, 0xB4($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XB4);
    skip_18:
    // 0x80038644: lwc1        $f6, 0x7380($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7380);
    // 0x80038648: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8003864C: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80038650: swc1        $f8, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f8.u32l;
    // 0x80038654: lwc1        $f10, 0xEC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x80038658: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8003865C: c.lt.d      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.d < ctx->f18.d;
    // 0x80038660: nop

    // 0x80038664: bc1fl       L_8003867C
    if (!c1cs) {
        // 0x80038668: lh          $t3, 0xB4($s0)
        ctx->r11 = MEM_H(ctx->r16, 0XB4);
            goto L_8003867C;
    }
    goto skip_19;
    // 0x80038668: lh          $t3, 0xB4($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XB4);
    skip_19:
    // 0x8003866C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80038670: nop

    // 0x80038674: swc1        $f16, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f16.u32l;
    // 0x80038678: lh          $t3, 0xB4($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XB4);
L_8003867C:
    // 0x8003867C: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80038680: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x80038684: bnel        $t4, $zero, L_800388EC
    if (ctx->r12 != 0) {
        // 0x80038688: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800388EC;
    }
    goto skip_20;
    // 0x80038688: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    skip_20:
L_8003868C:
    // 0x8003868C: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80038690: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80038694: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80038698: bne         $a0, $v1, L_8003868C
    if (ctx->r4 != ctx->r3) {
        // 0x8003869C: swc1        $f4, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = ctx->f4.u32l;
            goto L_8003868C;
    }
    // 0x8003869C: swc1        $f4, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f4.u32l;
    // 0x800386A0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800386A4: lwc1        $f8, 0x60($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X60);
    // 0x800386A8: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800386AC: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800386B0: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800386B4: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800386B8: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x800386BC: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800386C0: swc1        $f18, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f18.u32l;
    // 0x800386C4: lwc1        $f4, 0x68($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X68);
    // 0x800386C8: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800386CC: add.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800386D0: jal         0x8000D3A4
    // 0x800386D4: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    func_8000D3A4(rdram, ctx);
        goto after_24;
    // 0x800386D4: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    after_24:
    // 0x800386D8: beql        $v0, $zero, L_800388EC
    if (ctx->r2 == 0) {
        // 0x800386DC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800388EC;
    }
    goto skip_21;
    // 0x800386DC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    skip_21:
    // 0x800386E0: lh          $v0, 0xB4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB4);
    // 0x800386E4: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800386E8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800386EC: andi        $t5, $v0, 0x10
    ctx->r13 = ctx->r2 & 0X10;
    // 0x800386F0: beq         $t5, $zero, L_8003876C
    if (ctx->r13 == 0) {
        // 0x800386F4: lwc1        $f18, 0x58($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
            goto L_8003876C;
    }
    // 0x800386F4: lwc1        $f18, 0x58($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800386F8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800386FC: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80038700: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80038704: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80038708: andi        $t6, $v0, 0xFFEF
    ctx->r14 = ctx->r2 & 0XFFEF;
    // 0x8003870C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80038710: nop

    // 0x80038714: bc1fl       L_80038758
    if (!c1cs) {
        // 0x80038718: sh          $t6, 0xB4($s0)
        MEM_H(0XB4, ctx->r16) = ctx->r14;
            goto L_80038758;
    }
    goto skip_22;
    // 0x80038718: sh          $t6, 0xB4($s0)
    MEM_H(0XB4, ctx->r16) = ctx->r14;
    skip_22:
    // 0x8003871C: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80038720: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80038724: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80038728: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003872C: div.s       $f12, $f16, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80038730: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80038734: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x80038738: nop

    // 0x8003873C: bc1f        L_8003874C
    if (!c1cs) {
        // 0x80038740: nop
    
            goto L_8003874C;
    }
    // 0x80038740: nop

    // 0x80038744: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80038748: nop

L_8003874C:
    // 0x8003874C: b           L_80038864
    // 0x80038750: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
        goto L_80038864;
    // 0x80038750: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x80038754: sh          $t6, 0xB4($s0)
    MEM_H(0XB4, ctx->r16) = ctx->r14;
L_80038758:
    // 0x80038758: lh          $t7, 0xB4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XB4);
    // 0x8003875C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80038760: ori         $t8, $t7, 0x20
    ctx->r24 = ctx->r15 | 0X20;
    // 0x80038764: b           L_80038864
    // 0x80038768: sh          $t8, 0xB4($s0)
    MEM_H(0XB4, ctx->r16) = ctx->r24;
        goto L_80038864;
    // 0x80038768: sh          $t8, 0xB4($s0)
    MEM_H(0XB4, ctx->r16) = ctx->r24;
L_8003876C:
    // 0x8003876C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80038770: nop

    // 0x80038774: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80038778: nop

    // 0x8003877C: bc1fl       L_80038798
    if (!c1cs) {
        // 0x80038780: lwc1        $f16, 0x58($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
            goto L_80038798;
    }
    goto skip_23;
    // 0x80038780: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    skip_23:
    // 0x80038784: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80038788: nop

    // 0x8003878C: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x80038790: lh          $v0, 0xB4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB4);
    // 0x80038794: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
L_80038798:
    // 0x80038798: lwc1        $f8, 0x70($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8003879C: andi        $t9, $v0, 0x40
    ctx->r25 = ctx->r2 & 0X40;
    // 0x800387A0: beq         $t9, $zero, L_80038814
    if (ctx->r25 == 0) {
        // 0x800387A4: add.s       $f2, $f16, $f8
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f16.fl + ctx->f8.fl;
            goto L_80038814;
    }
    // 0x800387A4: add.s       $f2, $f16, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800387A8: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800387AC: andi        $t1, $v0, 0xFFBF
    ctx->r9 = ctx->r2 & 0XFFBF;
    // 0x800387B0: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800387B4: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800387B8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800387BC: bc1fl       L_800387E4
    if (!c1cs) {
        // 0x800387C0: sub.s       $f18, $f0, $f6
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f6.fl;
            goto L_800387E4;
    }
    goto skip_24;
    // 0x800387C0: sub.s       $f18, $f0, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f6.fl;
    skip_24:
    // 0x800387C4: sh          $t1, 0xB4($s0)
    MEM_H(0XB4, ctx->r16) = ctx->r9;
    // 0x800387C8: lh          $t2, 0xB4($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XB4);
    // 0x800387CC: ori         $t3, $t2, 0x80
    ctx->r11 = ctx->r10 | 0X80;
    // 0x800387D0: sh          $t3, 0xB4($s0)
    MEM_H(0XB4, ctx->r16) = ctx->r11;
    // 0x800387D4: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800387D8: b           L_80038828
    // 0x800387DC: lh          $v0, 0xB4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB4);
        goto L_80038828;
    // 0x800387DC: lh          $v0, 0xB4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB4);
    // 0x800387E0: sub.s       $f18, $f0, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f6.fl;
L_800387E4:
    // 0x800387E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800387E8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800387EC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800387F0: div.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800387F4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800387F8: c.lt.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl < ctx->f12.fl;
    // 0x800387FC: nop

    // 0x80038800: bc1fl       L_80038868
    if (!c1cs) {
        // 0x80038804: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_80038868;
    }
    goto skip_25;
    // 0x80038804: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_25:
    // 0x80038808: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8003880C: b           L_80038868
    // 0x80038810: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
        goto L_80038868;
    // 0x80038810: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_80038814:
    // 0x80038814: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80038818: lwc1        $f16, 0x40($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8003881C: sub.s       $f6, $f2, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x80038820: mul.s       $f12, $f16, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80038824: nop

L_80038828:
    // 0x80038828: andi        $t4, $v0, 0x80
    ctx->r12 = ctx->r2 & 0X80;
    // 0x8003882C: beql        $t4, $zero, L_80038868
    if (ctx->r12 == 0) {
        // 0x80038830: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_80038868;
    }
    goto skip_26;
    // 0x80038830: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_26:
    // 0x80038834: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80038838: lwc1        $f4, 0xBC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XBC);
    // 0x8003883C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80038840: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80038844: nop

    // 0x80038848: bc1fl       L_80038860
    if (!c1cs) {
        // 0x8003884C: mtc1        $zero, $f12
        ctx->f12.u32l = 0;
            goto L_80038860;
    }
    goto skip_27;
    // 0x8003884C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    skip_27:
    // 0x80038850: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80038854: b           L_80038868
    // 0x80038858: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
        goto L_80038868;
    // 0x80038858: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8003885C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
L_80038860:
    // 0x80038860: nop

L_80038864:
    // 0x80038864: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_80038868:
    // 0x80038868: nop

    // 0x8003886C: c.eq.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl == ctx->f10.fl;
    // 0x80038870: nop

    // 0x80038874: bc1tl       L_800388E0
    if (c1cs) {
        // 0x80038878: lwc1        $f4, 0xC($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
            goto L_800388E0;
    }
    goto skip_28;
    // 0x80038878: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    skip_28:
    // 0x8003887C: jal         0x8000E16C
    // 0x80038880: swc1        $f12, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f12.u32l;
    func_8000E16C(rdram, ctx);
        goto after_25;
    // 0x80038880: swc1        $f12, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f12.u32l;
    after_25:
    // 0x80038884: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80038888: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003888C: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80038890: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80038894: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80038898: nop

    // 0x8003889C: bc1fl       L_800388E0
    if (!c1cs) {
        // 0x800388A0: lwc1        $f4, 0xC($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
            goto L_800388E0;
    }
    goto skip_29;
    // 0x800388A0: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    skip_29:
    // 0x800388A4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800388A8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800388AC: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x800388B0: add.s       $f6, $f12, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x800388B4: c.lt.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl < ctx->f18.fl;
    // 0x800388B8: nop

    // 0x800388BC: bc1fl       L_800388D8
    if (!c1cs) {
        // 0x800388C0: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_800388D8;
    }
    goto skip_30;
    // 0x800388C0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_30:
    // 0x800388C4: lui         $at, 0xC020
    ctx->r1 = S32(0XC020 << 16);
    // 0x800388C8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800388CC: b           L_800388E0
    // 0x800388D0: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
        goto L_800388E0;
    // 0x800388D0: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800388D4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_800388D8:
    // 0x800388D8: nop

    // 0x800388DC: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
L_800388E0:
    // 0x800388E0: add.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x800388E4: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
L_800388E8:
    // 0x800388E8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800388EC:
    // 0x800388EC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_800388F0:
    // 0x800388F0: lwc1        $f12, 0xC8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC8);
    // 0x800388F4: sw          $v1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r3;
    // 0x800388F8: jal         0x8004F7C0
    // 0x800388FC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_8004F7C0(rdram, ctx);
        goto after_26;
    // 0x800388FC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_26:
    // 0x80038900: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80038904: lwc1        $f16, 0xEC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x80038908: lw          $v1, 0x8C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X8C);
    // 0x8003890C: lwc1        $f8, 0xD4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XD4);
    // 0x80038910: lwc1        $f4, 0xC8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC8);
    // 0x80038914: lwc1        $f10, 0xE0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XE0);
    // 0x80038918: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8003891C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80038920: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80038924: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80038928: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003892C: swc1        $f8, 0xC4($v0)
    MEM_W(0XC4, ctx->r2) = ctx->f8.u32l;
    // 0x80038930: mul.s       $f18, $f6, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80038934: bne         $v1, $at, L_800388F0
    if (ctx->r3 != ctx->r1) {
        // 0x80038938: swc1        $f18, 0xEC($v0)
        MEM_W(0XEC, ctx->r2) = ctx->f18.u32l;
            goto L_800388F0;
    }
    // 0x80038938: swc1        $f18, 0xEC($v0)
    MEM_W(0XEC, ctx->r2) = ctx->f18.u32l;
    // 0x8003893C: jal         0x800396E8
    // 0x80038940: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800396E8(rdram, ctx);
        goto after_27;
    // 0x80038940: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x80038944: jal         0x8000E074
    // 0x80038948: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8000E074(rdram, ctx);
        goto after_28;
    // 0x80038948: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_28:
    // 0x8003894C: beql        $v0, $zero, L_800389B8
    if (ctx->r2 == 0) {
        // 0x80038950: lh          $t4, 0x92($s0)
        ctx->r12 = MEM_H(ctx->r16, 0X92);
            goto L_800389B8;
    }
    goto skip_31;
    // 0x80038950: lh          $t4, 0x92($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X92);
    skip_31:
    // 0x80038954: lh          $t5, 0x92($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X92);
    // 0x80038958: lw          $t7, 0x84($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X84);
    // 0x8003895C: ori         $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 | 0X8000;
    // 0x80038960: sh          $t6, 0x92($s0)
    MEM_H(0X92, ctx->r16) = ctx->r14;
    // 0x80038964: lw          $v0, 0x8($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X8);
    // 0x80038968: lw          $t8, 0xD8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XD8);
    // 0x8003896C: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80038970: sw          $t9, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r25;
    // 0x80038974: lh          $t1, 0x2E($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X2E);
    // 0x80038978: slti        $at, $t1, 0xC8
    ctx->r1 = SIGNED(ctx->r9) < 0XC8 ? 1 : 0;
    // 0x8003897C: beq         $at, $zero, L_800389A4
    if (ctx->r1 == 0) {
        // 0x80038980: nop
    
            goto L_800389A4;
    }
    // 0x80038980: nop

    // 0x80038984: lh          $t2, 0xB0($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XB0);
    // 0x80038988: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8003898C: bne         $t2, $zero, L_800389A4
    if (ctx->r10 != 0) {
        // 0x80038990: nop
    
            goto L_800389A4;
    }
    // 0x80038990: nop

    // 0x80038994: jal         0x80043EF0
    // 0x80038998: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80043EF0(rdram, ctx);
        goto after_29;
    // 0x80038998: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_29:
    // 0x8003899C: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x800389A0: sh          $t3, 0xB0($s0)
    MEM_H(0XB0, ctx->r16) = ctx->r11;
L_800389A4:
    // 0x800389A4: jal         0x8003947C
    // 0x800389A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003947C(rdram, ctx);
        goto after_30;
    // 0x800389A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x800389AC: b           L_800389DC
    // 0x800389B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800389DC;
    // 0x800389B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800389B4: lh          $t4, 0x92($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X92);
L_800389B8:
    // 0x800389B8: lw          $t6, 0x84($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X84);
    // 0x800389BC: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800389C0: andi        $t5, $t4, 0x7FFF
    ctx->r13 = ctx->r12 & 0X7FFF;
    // 0x800389C4: sh          $t5, 0x92($s0)
    MEM_H(0X92, ctx->r16) = ctx->r13;
    // 0x800389C8: lw          $v0, 0x8($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X8);
    // 0x800389CC: lw          $t7, 0xD8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XD8);
    // 0x800389D0: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800389D4: sw          $t8, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r24;
    // 0x800389D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800389DC:
    // 0x800389DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800389E0: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // 0x800389E4: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800389EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800389EC: addiu       $sp, $sp, -0x108
    ctx->r29 = ADD32(ctx->r29, -0X108);
    // 0x800389F0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800389F4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800389F8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800389FC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80038A00: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80038A04: sw          $a0, -0x65F4($at)
    MEM_W(-0X65F4, ctx->r1) = ctx->r4;
    // 0x80038A08: lhu         $t6, 0x90($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X90);
    // 0x80038A0C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80038A10: sltiu       $at, $t6, 0x18
    ctx->r1 = ctx->r14 < 0X18 ? 1 : 0;
    // 0x80038A14: beq         $at, $zero, L_80038D14
    if (ctx->r1 == 0) {
        // 0x80038A18: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80038D14;
    }
    // 0x80038A18: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80038A1C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80038A20: addu        $at, $at, $t6
    gpr jr_addend_80038A28 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80038A24: lw          $t6, 0x7384($at)
    ctx->r14 = ADD32(ctx->r1, 0X7384);
    // 0x80038A28: jr          $t6
    // 0x80038A2C: nop

    switch (jr_addend_80038A28 >> 2) {
        case 0: goto L_80038A30; break;
        case 1: goto L_80038D14; break;
        case 2: goto L_80038AB4; break;
        case 3: goto L_80038D14; break;
        case 4: goto L_80038D14; break;
        case 5: goto L_80038D14; break;
        case 6: goto L_80038D14; break;
        case 7: goto L_80038D14; break;
        case 8: goto L_80038D14; break;
        case 9: goto L_80038D14; break;
        case 10: goto L_80038D14; break;
        case 11: goto L_80038D14; break;
        case 12: goto L_80038D14; break;
        case 13: goto L_80038D14; break;
        case 14: goto L_80038D14; break;
        case 15: goto L_80038D14; break;
        case 16: goto L_80038D14; break;
        case 17: goto L_80038D14; break;
        case 18: goto L_80038D14; break;
        case 19: goto L_80038D14; break;
        case 20: goto L_80038ACC; break;
        case 21: goto L_80038B68; break;
        case 22: goto L_80038C54; break;
        case 23: goto L_80038CC4; break;
        default: switch_error(__func__, 0x80038A28, 0x80077384);
    }
    // 0x80038A2C: nop

L_80038A30:
    // 0x80038A30: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80038A34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80038A38: jal         0x80024654
    // 0x80038A3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80024654(rdram, ctx);
        goto after_0;
    // 0x80038A3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80038A40: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80038A44: jal         0x80039158
    // 0x80038A48: addiu       $a1, $zero, 0x301
    ctx->r5 = ADD32(0, 0X301);
    func_80039158(rdram, ctx);
        goto after_1;
    // 0x80038A48: addiu       $a1, $zero, 0x301
    ctx->r5 = ADD32(0, 0X301);
    after_1:
    // 0x80038A4C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80038A50: lwc1        $f0, 0x73E4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X73E4);
    // 0x80038A54: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80038A58: lwc1        $f4, 0x73E8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X73E8);
    // 0x80038A5C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80038A60: swc1        $f0, 0xE4($s2)
    MEM_W(0XE4, ctx->r18) = ctx->f0.u32l;
    // 0x80038A64: swc1        $f4, 0xE0($s2)
    MEM_W(0XE0, ctx->r18) = ctx->f4.u32l;
    // 0x80038A68: lwc1        $f6, 0x73EC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X73EC);
    // 0x80038A6C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80038A70: addiu       $a0, $zero, -0x27
    ctx->r4 = ADD32(0, -0X27);
    // 0x80038A74: swc1        $f6, 0xE8($s2)
    MEM_W(0XE8, ctx->r18) = ctx->f6.u32l;
    // 0x80038A78: lwc1        $f8, 0x73F0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X73F0);
    // 0x80038A7C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80038A80: swc1        $f0, 0xD8($s2)
    MEM_W(0XD8, ctx->r18) = ctx->f0.u32l;
    // 0x80038A84: swc1        $f8, 0xD4($s2)
    MEM_W(0XD4, ctx->r18) = ctx->f8.u32l;
    // 0x80038A88: lwc1        $f10, 0x73F4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X73F4);
    // 0x80038A8C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80038A90: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80038A94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80038A98: swc1        $f10, 0xDC($s2)
    MEM_W(0XDC, ctx->r18) = ctx->f10.u32l;
    // 0x80038A9C: jal         0x800443A8
    // 0x80038AA0: swc1        $f16, 0xEC($s2)
    MEM_W(0XEC, ctx->r18) = ctx->f16.u32l;
    func_800443A8(rdram, ctx);
        goto after_2;
    // 0x80038AA0: swc1        $f16, 0xEC($s2)
    MEM_W(0XEC, ctx->r18) = ctx->f16.u32l;
    after_2:
    // 0x80038AA4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80038AA8: sw          $v0, -0x65A4($at)
    MEM_W(-0X65A4, ctx->r1) = ctx->r2;
    // 0x80038AAC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80038AB0: sh          $t7, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r15;
L_80038AB4:
    // 0x80038AB4: lh          $t8, 0x2E($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X2E);
    // 0x80038AB8: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x80038ABC: bgtzl       $t8, L_80038D18
    if (SIGNED(ctx->r24) > 0) {
        // 0x80038AC0: addiu       $t9, $s2, 0x8
        ctx->r25 = ADD32(ctx->r18, 0X8);
            goto L_80038D18;
    }
    goto skip_0;
    // 0x80038AC0: addiu       $t9, $s2, 0x8
    ctx->r25 = ADD32(ctx->r18, 0X8);
    skip_0:
    // 0x80038AC4: b           L_80038D14
    // 0x80038AC8: sh          $t9, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r25;
        goto L_80038D14;
    // 0x80038AC8: sh          $t9, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r25;
L_80038ACC:
    // 0x80038ACC: lwc1        $f18, 0x58($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X58);
    // 0x80038AD0: lwc1        $f4, 0x18($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X18);
    // 0x80038AD4: lh          $t0, 0x92($s2)
    ctx->r8 = MEM_H(ctx->r18, 0X92);
    // 0x80038AD8: sub.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80038ADC: ori         $t1, $t0, 0x2000
    ctx->r9 = ctx->r8 | 0X2000;
    // 0x80038AE0: sh          $t1, 0x92($s2)
    MEM_H(0X92, ctx->r18) = ctx->r9;
    // 0x80038AE4: jal         0x8000E16C
    // 0x80038AE8: swc1        $f12, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f12.u32l;
    func_8000E16C(rdram, ctx);
        goto after_3;
    // 0x80038AE8: swc1        $f12, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f12.u32l;
    after_3:
    // 0x80038AEC: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80038AF0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80038AF4: lwc1        $f12, 0xF8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80038AF8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80038AFC: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x80038B00: nop

    // 0x80038B04: bc1fl       L_80038B38
    if (!c1cs) {
        // 0x80038B08: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_80038B38;
    }
    goto skip_1;
    // 0x80038B08: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    skip_1:
    // 0x80038B0C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80038B10: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80038B14: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x80038B18: add.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x80038B1C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80038B20: nop

    // 0x80038B24: bc1fl       L_80038B34
    if (!c1cs) {
        // 0x80038B28: mov.s       $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
            goto L_80038B34;
    }
    goto skip_2;
    // 0x80038B28: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    skip_2:
    // 0x80038B2C: neg.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = -ctx->f14.fl;
    // 0x80038B30: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
L_80038B34:
    // 0x80038B34: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
L_80038B38:
    // 0x80038B38: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80038B3C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80038B40: div.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f12.fl, ctx->f16.fl);
    // 0x80038B44: swc1        $f18, 0x5C($s2)
    MEM_W(0X5C, ctx->r18) = ctx->f18.u32l;
    // 0x80038B48: lw          $a0, -0x65A4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X65A4);
    // 0x80038B4C: beql        $a0, $zero, L_80038B60
    if (ctx->r4 == 0) {
        // 0x80038B50: addiu       $t2, $zero, 0x15
        ctx->r10 = ADD32(0, 0X15);
            goto L_80038B60;
    }
    goto skip_3;
    // 0x80038B50: addiu       $t2, $zero, 0x15
    ctx->r10 = ADD32(0, 0X15);
    skip_3:
    // 0x80038B54: jal         0x800444F8
    // 0x80038B58: nop

    func_800444F8(rdram, ctx);
        goto after_4;
    // 0x80038B58: nop

    after_4:
    // 0x80038B5C: addiu       $t2, $zero, 0x15
    ctx->r10 = ADD32(0, 0X15);
L_80038B60:
    // 0x80038B60: sh          $zero, 0xAE($s2)
    MEM_H(0XAE, ctx->r18) = 0;
    // 0x80038B64: sh          $t2, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r10;
L_80038B68:
    // 0x80038B68: lui         $at, 0xBD80
    ctx->r1 = S32(0XBD80 << 16);
    // 0x80038B6C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80038B70: lwc1        $f0, 0x14($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X14);
    // 0x80038B74: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80038B78: addiu       $a0, $s2, 0x8
    ctx->r4 = ADD32(ctx->r18, 0X8);
    // 0x80038B7C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80038B80: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80038B84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80038B88: bc1fl       L_80038BA0
    if (!c1cs) {
        // 0x80038B8C: lh          $t3, 0xAE($s2)
        ctx->r11 = MEM_H(ctx->r18, 0XAE);
            goto L_80038BA0;
    }
    goto skip_4;
    // 0x80038B8C: lh          $t3, 0xAE($s2)
    ctx->r11 = MEM_H(ctx->r18, 0XAE);
    skip_4:
    // 0x80038B90: lwc1        $f6, 0x73F8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X73F8);
    // 0x80038B94: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80038B98: swc1        $f8, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f8.u32l;
    // 0x80038B9C: lh          $t3, 0xAE($s2)
    ctx->r11 = MEM_H(ctx->r18, 0XAE);
L_80038BA0:
    // 0x80038BA0: bnel        $t3, $zero, L_80038BD8
    if (ctx->r11 != 0) {
        // 0x80038BA4: lwc1        $f10, 0x1C($s2)
        ctx->f10.u32l = MEM_W(ctx->r18, 0X1C);
            goto L_80038BD8;
    }
    goto skip_5;
    // 0x80038BA4: lwc1        $f10, 0x1C($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X1C);
    skip_5:
    // 0x80038BA8: jal         0x80042F80
    // 0x80038BAC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_80042F80(rdram, ctx);
        goto after_5;
    // 0x80038BAC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_5:
    // 0x80038BB0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80038BB4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80038BB8: jal         0x80043714
    // 0x80038BBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80043714(rdram, ctx);
        goto after_6;
    // 0x80038BBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80038BC0: jal         0x8000E35C
    // 0x80038BC4: nop

    func_8000E35C(rdram, ctx);
        goto after_7;
    // 0x80038BC4: nop

    after_7:
    // 0x80038BC8: andi        $t4, $v0, 0x3F
    ctx->r12 = ctx->r2 & 0X3F;
    // 0x80038BCC: addiu       $t5, $t4, 0x14
    ctx->r13 = ADD32(ctx->r12, 0X14);
    // 0x80038BD0: sh          $t5, 0xAE($s2)
    MEM_H(0XAE, ctx->r18) = ctx->r13;
    // 0x80038BD4: lwc1        $f10, 0x1C($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X1C);
L_80038BD8:
    // 0x80038BD8: lwc1        $f16, 0x5C($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X5C);
    // 0x80038BDC: lw          $a1, 0x28($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X28);
    // 0x80038BE0: addiu       $s0, $sp, 0xE4
    ctx->r16 = ADD32(ctx->r29, 0XE4);
    // 0x80038BE4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80038BE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80038BEC: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80038BF0: jal         0x8000D3A4
    // 0x80038BF4: swc1        $f18, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f18.u32l;
    func_8000D3A4(rdram, ctx);
        goto after_8;
    // 0x80038BF4: swc1        $f18, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f18.u32l;
    after_8:
    // 0x80038BF8: beql        $v0, $zero, L_80038D18
    if (ctx->r2 == 0) {
        // 0x80038BFC: addiu       $t9, $s2, 0x8
        ctx->r25 = ADD32(ctx->r18, 0X8);
            goto L_80038D18;
    }
    goto skip_6;
    // 0x80038BFC: addiu       $t9, $s2, 0x8
    ctx->r25 = ADD32(ctx->r18, 0X8);
    skip_6:
    // 0x80038C00: lw          $a1, 0x28($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X28);
    // 0x80038C04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80038C08: jal         0x80003668
    // 0x80038C0C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    func_80003668(rdram, ctx);
        goto after_9;
    // 0x80038C0C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_9:
    // 0x80038C10: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80038C14: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80038C18: addiu       $a0, $s2, 0x8
    ctx->r4 = ADD32(ctx->r18, 0X8);
    // 0x80038C1C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80038C20: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80038C24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80038C28: bc1fl       L_80038D18
    if (!c1cs) {
        // 0x80038C2C: addiu       $t9, $s2, 0x8
        ctx->r25 = ADD32(ctx->r18, 0X8);
            goto L_80038D18;
    }
    goto skip_7;
    // 0x80038C2C: addiu       $t9, $s2, 0x8
    ctx->r25 = ADD32(ctx->r18, 0X8);
    skip_7:
    // 0x80038C30: jal         0x80042F80
    // 0x80038C34: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_80042F80(rdram, ctx);
        goto after_10;
    // 0x80038C34: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_10:
    // 0x80038C38: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80038C3C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80038C40: jal         0x80043714
    // 0x80038C44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80043714(rdram, ctx);
        goto after_11;
    // 0x80038C44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x80038C48: addiu       $t6, $zero, 0x16
    ctx->r14 = ADD32(0, 0X16);
    // 0x80038C4C: b           L_80038D14
    // 0x80038C50: sh          $t6, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r14;
        goto L_80038D14;
    // 0x80038C50: sh          $t6, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r14;
L_80038C54:
    // 0x80038C54: jal         0x8001EAC8
    // 0x80038C58: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8001EAC8(rdram, ctx);
        goto after_12;
    // 0x80038C58: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_12:
    // 0x80038C5C: lh          $t7, 0x2C($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X2C);
    // 0x80038C60: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80038C64: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80038C68: blezl       $t7, L_80038CBC
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80038C6C: addiu       $t1, $zero, 0x17
        ctx->r9 = ADD32(0, 0X17);
            goto L_80038CBC;
    }
    goto skip_8;
    // 0x80038C6C: addiu       $t1, $zero, 0x17
    ctx->r9 = ADD32(0, 0X17);
    skip_8:
    // 0x80038C70: lw          $t8, 0x28($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X28);
L_80038C74:
    // 0x80038C74: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80038C78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80038C7C: addu        $a0, $t8, $s0
    ctx->r4 = ADD32(ctx->r24, ctx->r16);
    // 0x80038C80: jal         0x80042F80
    // 0x80038C84: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_80042F80(rdram, ctx);
        goto after_13;
    // 0x80038C84: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_13:
    // 0x80038C88: lw          $t9, 0x28($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X28);
    // 0x80038C8C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80038C90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80038C94: addu        $a0, $t9, $s0
    ctx->r4 = ADD32(ctx->r25, ctx->r16);
    // 0x80038C98: jal         0x80043714
    // 0x80038C9C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_80043714(rdram, ctx);
        goto after_14;
    // 0x80038C9C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_14:
    // 0x80038CA0: lh          $t0, 0x2C($s2)
    ctx->r8 = MEM_H(ctx->r18, 0X2C);
    // 0x80038CA4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80038CA8: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x80038CAC: slt         $at, $s1, $t0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80038CB0: bnel        $at, $zero, L_80038C74
    if (ctx->r1 != 0) {
        // 0x80038CB4: lw          $t8, 0x28($s2)
        ctx->r24 = MEM_W(ctx->r18, 0X28);
            goto L_80038C74;
    }
    goto skip_9;
    // 0x80038CB4: lw          $t8, 0x28($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X28);
    skip_9:
    // 0x80038CB8: addiu       $t1, $zero, 0x17
    ctx->r9 = ADD32(0, 0X17);
L_80038CBC:
    // 0x80038CBC: sh          $zero, 0xAC($s2)
    MEM_H(0XAC, ctx->r18) = 0;
    // 0x80038CC0: sh          $t1, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r9;
L_80038CC4:
    // 0x80038CC4: lh          $t2, 0xAC($s2)
    ctx->r10 = MEM_H(ctx->r18, 0XAC);
    // 0x80038CC8: addiu       $a0, $s2, 0x8
    ctx->r4 = ADD32(ctx->r18, 0X8);
    // 0x80038CCC: bnel        $t2, $zero, L_80038CE8
    if (ctx->r10 != 0) {
        // 0x80038CD0: lh          $t4, 0x92($s2)
        ctx->r12 = MEM_H(ctx->r18, 0X92);
            goto L_80038CE8;
    }
    goto skip_10;
    // 0x80038CD0: lh          $t4, 0x92($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X92);
    skip_10:
    // 0x80038CD4: jal         0x80043EF0
    // 0x80038CD8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80043EF0(rdram, ctx);
        goto after_15;
    // 0x80038CD8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_15:
    // 0x80038CDC: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x80038CE0: sh          $t3, 0xAC($s2)
    MEM_H(0XAC, ctx->r18) = ctx->r11;
    // 0x80038CE4: lh          $t4, 0x92($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X92);
L_80038CE8:
    // 0x80038CE8: lw          $t6, 0x84($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X84);
    // 0x80038CEC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80038CF0: ori         $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 | 0X8000;
    // 0x80038CF4: sh          $t5, 0x92($s2)
    MEM_H(0X92, ctx->r18) = ctx->r13;
    // 0x80038CF8: lw          $v0, 0x8($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X8);
    // 0x80038CFC: lw          $t7, 0xD8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XD8);
    // 0x80038D00: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80038D04: jal         0x8003947C
    // 0x80038D08: sw          $t8, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r24;
    func_8003947C(rdram, ctx);
        goto after_16;
    // 0x80038D08: sw          $t8, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r24;
    after_16:
    // 0x80038D0C: b           L_80039144
    // 0x80038D10: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80039144;
    // 0x80038D10: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80038D14:
    // 0x80038D14: addiu       $t9, $s2, 0x8
    ctx->r25 = ADD32(ctx->r18, 0X8);
L_80038D18:
    // 0x80038D18: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x80038D1C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80038D20: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_80038D24:
    // 0x80038D24: lh          $a0, 0xAC($v0)
    ctx->r4 = MEM_H(ctx->r2, 0XAC);
    // 0x80038D28: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80038D2C: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x80038D30: beq         $a0, $zero, L_80038D3C
    if (ctx->r4 == 0) {
        // 0x80038D34: addiu       $t0, $a0, -0x1
        ctx->r8 = ADD32(ctx->r4, -0X1);
            goto L_80038D3C;
    }
    // 0x80038D34: addiu       $t0, $a0, -0x1
    ctx->r8 = ADD32(ctx->r4, -0X1);
    // 0x80038D38: sh          $t0, 0xAC($v0)
    MEM_H(0XAC, ctx->r2) = ctx->r8;
L_80038D3C:
    // 0x80038D3C: bne         $at, $zero, L_80038D24
    if (ctx->r1 != 0) {
        // 0x80038D40: addiu       $v0, $v0, 0x2
        ctx->r2 = ADD32(ctx->r2, 0X2);
            goto L_80038D24;
    }
    // 0x80038D40: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80038D44: lh          $v0, 0x2E($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X2E);
    // 0x80038D48: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80038D4C: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x80038D50: bgtzl       $v0, L_80038D78
    if (SIGNED(ctx->r2) > 0) {
        // 0x80038D54: lh          $t4, 0x92($s2)
        ctx->r12 = MEM_H(ctx->r18, 0X92);
            goto L_80038D78;
    }
    goto skip_11;
    // 0x80038D54: lh          $t4, 0x92($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X92);
    skip_11:
    // 0x80038D58: lh          $v0, 0x92($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X92);
    // 0x80038D5C: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x80038D60: andi        $t1, $v0, 0x2000
    ctx->r9 = ctx->r2 & 0X2000;
    // 0x80038D64: bne         $t1, $zero, L_80038D74
    if (ctx->r9 != 0) {
        // 0x80038D68: ori         $t2, $v0, 0x2000
        ctx->r10 = ctx->r2 | 0X2000;
            goto L_80038D74;
    }
    // 0x80038D68: ori         $t2, $v0, 0x2000
    ctx->r10 = ctx->r2 | 0X2000;
    // 0x80038D6C: sh          $t2, 0x92($s2)
    MEM_H(0X92, ctx->r18) = ctx->r10;
    // 0x80038D70: sh          $t3, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r11;
L_80038D74:
    // 0x80038D74: lh          $t4, 0x92($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X92);
L_80038D78:
    // 0x80038D78: addiu       $v0, $sp, 0x4C
    ctx->r2 = ADD32(ctx->r29, 0X4C);
    // 0x80038D7C: addiu       $a1, $s2, 0x14
    ctx->r5 = ADD32(ctx->r18, 0X14);
    // 0x80038D80: andi        $t5, $t4, 0x2000
    ctx->r13 = ctx->r12 & 0X2000;
    // 0x80038D84: bne         $t5, $zero, L_80038F20
    if (ctx->r13 != 0) {
        // 0x80038D88: addiu       $a3, $sp, 0x4C
        ctx->r7 = ADD32(ctx->r29, 0X4C);
            goto L_80038F20;
    }
    // 0x80038D88: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
L_80038D8C:
    // 0x80038D8C: lh          $t7, 0x7A($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X7A);
    // 0x80038D90: lw          $t6, 0x74($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X74);
    // 0x80038D94: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80038D98: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80038D9C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80038DA0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80038DA4: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80038DA8: addu        $t0, $t9, $v1
    ctx->r8 = ADD32(ctx->r25, ctx->r3);
    // 0x80038DAC: lwc1        $f6, 0x4($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80038DB0: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x80038DB4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80038DB8: bne         $at, $zero, L_80038D8C
    if (ctx->r1 != 0) {
        // 0x80038DBC: swc1        $f6, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
            goto L_80038D8C;
    }
    // 0x80038DBC: swc1        $f6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80038DC0: addiu       $a0, $s2, 0x54
    ctx->r4 = ADD32(ctx->r18, 0X54);
    // 0x80038DC4: jal         0x8000CD08
    // 0x80038DC8: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    func_8000CD08(rdram, ctx);
        goto after_17;
    // 0x80038DC8: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    after_17:
    // 0x80038DCC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80038DD0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80038DD4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80038DD8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80038DDC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80038DE0: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
L_80038DE4:
    // 0x80038DE4: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80038DE8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80038DEC: nop

    // 0x80038DF0: bc1fl       L_80038E08
    if (!c1cs) {
        // 0x80038DF4: lwc1        $f10, 0x14($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
            goto L_80038E08;
    }
    goto skip_12;
    // 0x80038DF4: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    skip_12:
    // 0x80038DF8: sub.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x80038DFC: swc1        $f8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
    // 0x80038E00: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80038E04: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
L_80038E08:
    // 0x80038E08: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80038E0C: slti        $at, $s1, 0x2
    ctx->r1 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
    // 0x80038E10: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80038E14: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80038E18: bne         $at, $zero, L_80038DE4
    if (ctx->r1 != 0) {
        // 0x80038E1C: swc1        $f16, 0x50($s0)
        MEM_W(0X50, ctx->r16) = ctx->f16.u32l;
            goto L_80038DE4;
    }
    // 0x80038E1C: swc1        $f16, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f16.u32l;
    // 0x80038E20: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80038E24: jal         0x80003668
    // 0x80038E28: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_80003668(rdram, ctx);
        goto after_18;
    // 0x80038E28: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_18:
    // 0x80038E2C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80038E30: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80038E34: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80038E38: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x80038E3C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80038E40: nop

    // 0x80038E44: bc1f        L_80038E7C
    if (!c1cs) {
        // 0x80038E48: nop
    
            goto L_80038E7C;
    }
    // 0x80038E48: nop

    // 0x80038E4C: lh          $t1, 0x7A($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X7A);
    // 0x80038E50: lh          $t4, 0x78($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X78);
    // 0x80038E54: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80038E58: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80038E5C: sh          $t2, 0x7A($s2)
    MEM_H(0X7A, ctx->r18) = ctx->r10;
    // 0x80038E60: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80038E64: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x80038E68: lh          $t7, -0x6770($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X6770);
    // 0x80038E6C: lh          $t3, 0x7A($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X7A);
    // 0x80038E70: bne         $t3, $t7, L_80038E7C
    if (ctx->r11 != ctx->r15) {
        // 0x80038E74: nop
    
            goto L_80038E7C;
    }
    // 0x80038E74: nop

    // 0x80038E78: sh          $zero, 0x7A($s2)
    MEM_H(0X7A, ctx->r18) = 0;
L_80038E7C:
    // 0x80038E7C: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80038E80: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80038E84: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80038E88: jal         0x8000E16C
    // 0x80038E8C: swc1        $f12, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f12.u32l;
    func_8000E16C(rdram, ctx);
        goto after_19;
    // 0x80038E8C: swc1        $f12, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f12.u32l;
    after_19:
    // 0x80038E90: lui         $at, 0x3D00
    ctx->r1 = S32(0X3D00 << 16);
    // 0x80038E94: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80038E98: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80038E9C: lwc1        $f12, 0xF8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80038EA0: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80038EA4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80038EA8: lui         $at, 0x3D00
    ctx->r1 = S32(0X3D00 << 16);
    // 0x80038EAC: bc1fl       L_80038EC0
    if (!c1cs) {
        // 0x80038EB0: c.lt.s      $f12, $f10
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
            goto L_80038EC0;
    }
    goto skip_13;
    // 0x80038EB0: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    skip_13:
    // 0x80038EB4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80038EB8: nop

    // 0x80038EBC: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
L_80038EC0:
    // 0x80038EC0: nop

    // 0x80038EC4: bc1fl       L_80038ED4
    if (!c1cs) {
        // 0x80038EC8: lwc1        $f18, 0x50($s2)
        ctx->f18.u32l = MEM_W(ctx->r18, 0X50);
            goto L_80038ED4;
    }
    goto skip_14;
    // 0x80038EC8: lwc1        $f18, 0x50($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X50);
    skip_14:
    // 0x80038ECC: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80038ED0: lwc1        $f18, 0x50($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X50);
L_80038ED4:
    // 0x80038ED4: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80038ED8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80038EDC: mul.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x80038EE0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80038EE4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80038EE8: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80038EEC: bne         $s1, $at, L_80038E7C
    if (ctx->r17 != ctx->r1) {
        // 0x80038EF0: swc1        $f6, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
            goto L_80038E7C;
    }
    // 0x80038EF0: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x80038EF4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80038EF8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80038EFC: lwc1        $f0, 0x1C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X1C);
    // 0x80038F00: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80038F04: mul.s       $f12, $f2, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80038F08: sub.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80038F0C: swc1        $f12, 0x5C($s2)
    MEM_W(0X5C, ctx->r18) = ctx->f12.u32l;
    // 0x80038F10: lwc1        $f18, 0x73FC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X73FC);
    // 0x80038F14: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80038F18: add.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80038F1C: swc1        $f4, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f4.u32l;
L_80038F20:
    // 0x80038F20: lwc1        $f0, 0xEC($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XEC);
    // 0x80038F24: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x80038F28: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x80038F2C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80038F30: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80038F34: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80038F38: c.lt.d      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.d < ctx->f2.d;
    // 0x80038F3C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80038F40: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x80038F44: bc1f        L_80038F80
    if (!c1cs) {
        // 0x80038F48: nop
    
            goto L_80038F80;
    }
    // 0x80038F48: nop

    // 0x80038F4C: lwc1        $f8, 0x7400($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7400);
    // 0x80038F50: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80038F54: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80038F58: swc1        $f10, 0xEC($s2)
    MEM_W(0XEC, ctx->r18) = ctx->f10.u32l;
    // 0x80038F5C: lwc1        $f18, 0xEC($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0XEC);
    // 0x80038F60: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x80038F64: c.lt.d      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.d < ctx->f16.d;
    // 0x80038F68: nop

    // 0x80038F6C: bc1f        L_80038F80
    if (!c1cs) {
        // 0x80038F70: nop
    
            goto L_80038F80;
    }
    // 0x80038F70: nop

    // 0x80038F74: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80038F78: nop

    // 0x80038F7C: swc1        $f4, 0xEC($s2)
    MEM_W(0XEC, ctx->r18) = ctx->f4.u32l;
L_80038F80:
    // 0x80038F80: jal         0x8004F7C0
    // 0x80038F84: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
    func_8004F7C0(rdram, ctx);
        goto after_20;
    // 0x80038F84: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
    after_20:
    // 0x80038F88: lwc1        $f6, 0xD4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XD4);
    // 0x80038F8C: lwc1        $f8, 0xEC($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0XEC);
    // 0x80038F90: lwc1        $f16, 0xC8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x80038F94: lwc1        $f4, 0xE0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE0);
    // 0x80038F98: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80038F9C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80038FA0: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80038FA4: slti        $at, $s1, 0x3
    ctx->r1 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // 0x80038FA8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80038FAC: swc1        $f6, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f6.u32l;
    // 0x80038FB0: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80038FB4: bne         $at, $zero, L_80038F80
    if (ctx->r1 != 0) {
        // 0x80038FB8: swc1        $f18, 0xEC($s0)
        MEM_W(0XEC, ctx->r16) = ctx->f18.u32l;
            goto L_80038F80;
    }
    // 0x80038FB8: swc1        $f18, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f18.u32l;
    // 0x80038FBC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80038FC0: addiu       $s0, $sp, 0x98
    ctx->r16 = ADD32(ctx->r29, 0X98);
    // 0x80038FC4: lw          $a1, 0x14($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X14);
    // 0x80038FC8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80038FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80038FD0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80038FD4: jal         0x80049840
    // 0x80038FD8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80049840(rdram, ctx);
        goto after_21;
    // 0x80038FD8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_21:
    // 0x80038FDC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80038FE0: addiu       $s1, $sp, 0x58
    ctx->r17 = ADD32(ctx->r29, 0X58);
    // 0x80038FE4: lw          $a1, 0x18($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X18);
    // 0x80038FE8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80038FEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80038FF0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80038FF4: jal         0x80049840
    // 0x80038FF8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80049840(rdram, ctx);
        goto after_22;
    // 0x80038FF8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_22:
    // 0x80038FFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80039000: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80039004: jal         0x80000BD8
    // 0x80039008: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_80000BD8(rdram, ctx);
        goto after_23;
    // 0x80039008: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_23:
    // 0x8003900C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80039010: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80039014: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x80039018: addiu       $v0, $sp, 0x98
    ctx->r2 = ADD32(ctx->r29, 0X98);
    // 0x8003901C: addiu       $v1, $sp, 0xA4
    ctx->r3 = ADD32(ctx->r29, 0XA4);
    // 0x80039020: lwc1        $f14, 0x20($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80039024: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80039028: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8003902C: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x80039030: mul.s       $f16, $f14, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80039034: beql        $v0, $v1, L_80039068
    if (ctx->r2 == ctx->r3) {
        // 0x80039038: add.s       $f14, $f18, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
            goto L_80039068;
    }
    goto skip_15;
    // 0x80039038: add.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
    skip_15:
    // 0x8003903C: add.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
L_80039040:
    // 0x80039040: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80039044: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80039048: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8003904C: swc1        $f14, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f14.u32l;
    // 0x80039050: lwc1        $f14, 0x1C($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80039054: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x80039058: mul.s       $f16, $f14, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8003905C: bnel        $v0, $v1, L_80039040
    if (ctx->r2 != ctx->r3) {
        // 0x80039060: add.s       $f14, $f18, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
            goto L_80039040;
    }
    goto skip_16;
    // 0x80039060: add.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
    skip_16:
    // 0x80039064: add.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
L_80039068:
    // 0x80039068: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8003906C: swc1        $f14, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f14.u32l;
    // 0x80039070: jal         0x8000E074
    // 0x80039074: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_8000E074(rdram, ctx);
        goto after_24;
    // 0x80039074: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_24:
    // 0x80039078: beql        $v0, $zero, L_80039120
    if (ctx->r2 == 0) {
        // 0x8003907C: lh          $t6, 0x92($s2)
        ctx->r14 = MEM_H(ctx->r18, 0X92);
            goto L_80039120;
    }
    goto skip_17;
    // 0x8003907C: lh          $t6, 0x92($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X92);
    skip_17:
    // 0x80039080: lh          $t6, 0x92($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X92);
    // 0x80039084: lw          $t9, 0x84($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X84);
    // 0x80039088: ori         $t8, $t6, 0x8000
    ctx->r24 = ctx->r14 | 0X8000;
    // 0x8003908C: sh          $t8, 0x92($s2)
    MEM_H(0X92, ctx->r18) = ctx->r24;
    // 0x80039090: lw          $v0, 0x8($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X8);
    // 0x80039094: lw          $t0, 0xD8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XD8);
    // 0x80039098: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x8003909C: sw          $t1, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r9;
    // 0x800390A0: lh          $t2, 0xB0($s2)
    ctx->r10 = MEM_H(ctx->r18, 0XB0);
    // 0x800390A4: bne         $t2, $zero, L_8003910C
    if (ctx->r10 != 0) {
        // 0x800390A8: nop
    
            goto L_8003910C;
    }
    // 0x800390A8: nop

    // 0x800390AC: lh          $t4, 0x2E($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X2E);
    // 0x800390B0: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
    // 0x800390B4: slti        $at, $t4, 0x191
    ctx->r1 = SIGNED(ctx->r12) < 0X191 ? 1 : 0;
    // 0x800390B8: bne         $at, $zero, L_800390C8
    if (ctx->r1 != 0) {
        // 0x800390BC: nop
    
            goto L_800390C8;
    }
    // 0x800390BC: nop

    // 0x800390C0: b           L_800390C8
    // 0x800390C4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_800390C8;
    // 0x800390C4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800390C8:
    // 0x800390C8: jal         0x8001EAC8
    // 0x800390CC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8001EAC8(rdram, ctx);
        goto after_25;
    // 0x800390CC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_25:
    // 0x800390D0: lw          $a0, 0x28($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X28);
    // 0x800390D4: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    // 0x800390D8: sra         $t5, $a1, 16
    ctx->r13 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800390DC: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x800390E0: jal         0x80043EF0
    // 0x800390E4: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    func_80043EF0(rdram, ctx);
        goto after_26;
    // 0x800390E4: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_26:
    // 0x800390E8: beq         $s0, $zero, L_80039104
    if (ctx->r16 == 0) {
        // 0x800390EC: sll         $a1, $s0, 16
        ctx->r5 = S32(ctx->r16 << 16);
            goto L_80039104;
    }
    // 0x800390EC: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    // 0x800390F0: lw          $a0, 0x28($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X28);
    // 0x800390F4: sra         $t3, $a1, 16
    ctx->r11 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800390F8: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x800390FC: jal         0x80043EF0
    // 0x80039100: addiu       $a0, $a0, 0x38
    ctx->r4 = ADD32(ctx->r4, 0X38);
    func_80043EF0(rdram, ctx);
        goto after_27;
    // 0x80039100: addiu       $a0, $a0, 0x38
    ctx->r4 = ADD32(ctx->r4, 0X38);
    after_27:
L_80039104:
    // 0x80039104: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x80039108: sh          $t7, 0xB0($s2)
    MEM_H(0XB0, ctx->r18) = ctx->r15;
L_8003910C:
    // 0x8003910C: jal         0x8003947C
    // 0x80039110: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8003947C(rdram, ctx);
        goto after_28;
    // 0x80039110: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_28:
    // 0x80039114: b           L_80039144
    // 0x80039118: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80039144;
    // 0x80039118: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8003911C: lh          $t6, 0x92($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X92);
L_80039120:
    // 0x80039120: lw          $t9, 0x84($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X84);
    // 0x80039124: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80039128: andi        $t8, $t6, 0x7FFF
    ctx->r24 = ctx->r14 & 0X7FFF;
    // 0x8003912C: sh          $t8, 0x92($s2)
    MEM_H(0X92, ctx->r18) = ctx->r24;
    // 0x80039130: lw          $v0, 0x8($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X8);
    // 0x80039134: lw          $t0, 0xD8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XD8);
    // 0x80039138: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x8003913C: sw          $t1, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r9;
    // 0x80039140: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80039144:
    // 0x80039144: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80039148: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8003914C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80039150: jr          $ra
    // 0x80039154: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
    TRACE_RETURN()
    return;
    // 0x80039154: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
;}
RECOMP_FUNC void func_80039158(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80039158: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8003915C: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80039160: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80039164: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80039168: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8003916C: andi        $v0, $a1, 0xFF00
    ctx->r2 = ctx->r5 & 0XFF00;
    // 0x80039170: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x80039174: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80039178: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8003917C: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x80039180: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x80039184: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80039188: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x8003918C: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80039190: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80039194: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80039198: beq         $v0, $at, L_800391C0
    if (ctx->r2 == ctx->r1) {
        // 0x8003919C: sdc1        $f20, 0x10($sp)
        CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
            goto L_800391C0;
    }
    // 0x8003919C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800391A0: addiu       $at, $zero, 0x200
    ctx->r1 = ADD32(0, 0X200);
    // 0x800391A4: beq         $v0, $at, L_800391CC
    if (ctx->r2 == ctx->r1) {
        // 0x800391A8: lui         $s1, 0x8007
        ctx->r17 = S32(0X8007 << 16);
            goto L_800391CC;
    }
    // 0x800391A8: lui         $s1, 0x8007
    ctx->r17 = S32(0X8007 << 16);
    // 0x800391AC: addiu       $at, $zero, 0x300
    ctx->r1 = ADD32(0, 0X300);
    // 0x800391B0: beq         $v0, $at, L_800391D4
    if (ctx->r2 == ctx->r1) {
        // 0x800391B4: lui         $s1, 0x8007
        ctx->r17 = S32(0X8007 << 16);
            goto L_800391D4;
    }
    // 0x800391B4: lui         $s1, 0x8007
    ctx->r17 = S32(0X8007 << 16);
    // 0x800391B8: b           L_800391D8
    // 0x800391BC: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
        goto L_800391D8;
    // 0x800391BC: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
L_800391C0:
    // 0x800391C0: lui         $s1, 0x8007
    ctx->r17 = S32(0X8007 << 16);
    // 0x800391C4: b           L_800391D8
    // 0x800391C8: addiu       $s1, $s1, 0x2FF0
    ctx->r17 = ADD32(ctx->r17, 0X2FF0);
        goto L_800391D8;
    // 0x800391C8: addiu       $s1, $s1, 0x2FF0
    ctx->r17 = ADD32(ctx->r17, 0X2FF0);
L_800391CC:
    // 0x800391CC: b           L_800391D8
    // 0x800391D0: addiu       $s1, $s1, 0x2F88
    ctx->r17 = ADD32(ctx->r17, 0X2F88);
        goto L_800391D8;
    // 0x800391D0: addiu       $s1, $s1, 0x2F88
    ctx->r17 = ADD32(ctx->r17, 0X2F88);
L_800391D4:
    // 0x800391D4: addiu       $s1, $s1, 0x3128
    ctx->r17 = ADD32(ctx->r17, 0X3128);
L_800391D8:
    // 0x800391D8: lh          $v0, 0x0($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X0);
    // 0x800391DC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800391E0: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x800391E4: beql        $v0, $zero, L_80039208
    if (ctx->r2 == 0) {
        // 0x800391E8: sh          $a1, 0x8E($s2)
        MEM_H(0X8E, ctx->r18) = ctx->r5;
            goto L_80039208;
    }
    goto skip_0;
    // 0x800391E8: sh          $a1, 0x8E($s2)
    MEM_H(0X8E, ctx->r18) = ctx->r5;
    skip_0:
L_800391EC:
    // 0x800391EC: beql        $a1, $v0, L_80039208
    if (ctx->r5 == ctx->r2) {
        // 0x800391F0: sh          $a1, 0x8E($s2)
        MEM_H(0X8E, ctx->r18) = ctx->r5;
            goto L_80039208;
    }
    goto skip_1;
    // 0x800391F0: sh          $a1, 0x8E($s2)
    MEM_H(0X8E, ctx->r18) = ctx->r5;
    skip_1:
    // 0x800391F4: lh          $v0, 0x34($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X34);
    // 0x800391F8: addiu       $s1, $s1, 0x34
    ctx->r17 = ADD32(ctx->r17, 0X34);
    // 0x800391FC: bne         $v0, $zero, L_800391EC
    if (ctx->r2 != 0) {
        // 0x80039200: nop
    
            goto L_800391EC;
    }
    // 0x80039200: nop

    // 0x80039204: sh          $a1, 0x8E($s2)
    MEM_H(0X8E, ctx->r18) = ctx->r5;
L_80039208:
    // 0x80039208: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8003920C: swc1        $f4, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f4.u32l;
    // 0x80039210: lh          $t8, 0xC($s1)
    ctx->r24 = MEM_H(ctx->r17, 0XC);
    // 0x80039214: sh          $t8, 0x92($s2)
    MEM_H(0X92, ctx->r18) = ctx->r24;
    // 0x80039218: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8003921C: swc1        $f6, 0x48($s2)
    MEM_W(0X48, ctx->r18) = ctx->f6.u32l;
    // 0x80039220: lwc1        $f8, 0x14($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80039224: swc1        $f8, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->f8.u32l;
    // 0x80039228: lwc1        $f10, 0x18($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8003922C: swc1        $f10, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f10.u32l;
    // 0x80039230: lh          $t9, 0x20($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X20);
    // 0x80039234: sh          $t9, 0x2C($s2)
    MEM_H(0X2C, ctx->r18) = ctx->r25;
    // 0x80039238: lh          $v0, 0x2C($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X2C);
    // 0x8003923C: beq         $v0, $zero, L_800392FC
    if (ctx->r2 == 0) {
        // 0x80039240: sll         $a1, $v0, 2
        ctx->r5 = S32(ctx->r2 << 2);
            goto L_800392FC;
    }
    // 0x80039240: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x80039244: subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // 0x80039248: jal         0x80004364
    // 0x8003924C: sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5 << 3);
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x8003924C: sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5 << 3);
    after_0:
    // 0x80039250: lh          $t0, 0x2C($s2)
    ctx->r8 = MEM_H(ctx->r18, 0X2C);
    // 0x80039254: sw          $v0, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r2;
    // 0x80039258: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8003925C: blez        $t0, L_800392FC
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80039260: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800392FC;
    }
    // 0x80039260: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80039264: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80039268: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // 0x8003926C: lw          $t1, 0x1C($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X1C);
L_80039270:
    // 0x80039270: lw          $t4, 0x28($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X28);
    // 0x80039274: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80039278: addu        $t2, $t1, $a1
    ctx->r10 = ADD32(ctx->r9, ctx->r5);
    // 0x8003927C: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x80039280: addu        $t5, $t4, $a0
    ctx->r13 = ADD32(ctx->r12, ctx->r4);
    // 0x80039284: sh          $t3, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r11;
L_80039288:
    // 0x80039288: lw          $t6, 0x1C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X1C);
    // 0x8003928C: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x80039290: lw          $t1, 0x28($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X28);
    // 0x80039294: addu        $t7, $t7, $s0
    ctx->r15 = ADD32(ctx->r15, ctx->r16);
    // 0x80039298: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x8003929C: subu        $t2, $t2, $s0
    ctx->r10 = SUB32(ctx->r10, ctx->r16);
    // 0x800392A0: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800392A4: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x800392A8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800392AC: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800392B0: addu        $t4, $t1, $t2
    ctx->r12 = ADD32(ctx->r9, ctx->r10);
    // 0x800392B4: lh          $t0, 0x2($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X2);
    // 0x800392B8: addu        $t3, $t4, $v0
    ctx->r11 = ADD32(ctx->r12, ctx->r2);
    // 0x800392BC: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800392C0: bne         $v0, $v1, L_80039288
    if (ctx->r2 != ctx->r3) {
        // 0x800392C4: sh          $t0, 0x2($t3)
        MEM_H(0X2, ctx->r11) = ctx->r8;
            goto L_80039288;
    }
    // 0x800392C4: sh          $t0, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r8;
    // 0x800392C8: lw          $t5, 0x1C($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X1C);
    // 0x800392CC: lw          $t8, 0x28($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X28);
    // 0x800392D0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800392D4: addu        $t6, $t5, $a1
    ctx->r14 = ADD32(ctx->r13, ctx->r5);
    // 0x800392D8: lh          $t7, 0x8($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X8);
    // 0x800392DC: addu        $t9, $t8, $a0
    ctx->r25 = ADD32(ctx->r24, ctx->r4);
    // 0x800392E0: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    // 0x800392E4: sh          $t7, 0x14($t9)
    MEM_H(0X14, ctx->r25) = ctx->r15;
    // 0x800392E8: lh          $t1, 0x2C($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X2C);
    // 0x800392EC: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
    // 0x800392F0: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800392F4: bnel        $at, $zero, L_80039270
    if (ctx->r1 != 0) {
        // 0x800392F8: lw          $t1, 0x1C($s1)
        ctx->r9 = MEM_W(ctx->r17, 0X1C);
            goto L_80039270;
    }
    goto skip_2;
    // 0x800392F8: lw          $t1, 0x1C($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X1C);
    skip_2:
L_800392FC:
    // 0x800392FC: lh          $v0, 0x22($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X22);
    // 0x80039300: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80039304: sh          $v0, 0x30($s2)
    MEM_H(0X30, ctx->r18) = ctx->r2;
    // 0x80039308: sh          $v0, 0x2E($s2)
    MEM_H(0X2E, ctx->r18) = ctx->r2;
    // 0x8003930C: lh          $t2, 0x26($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X26);
    // 0x80039310: sh          $t2, 0x32($s2)
    MEM_H(0X32, ctx->r18) = ctx->r10;
    // 0x80039314: lh          $t4, 0x28($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X28);
    // 0x80039318: sh          $t4, 0x34($s2)
    MEM_H(0X34, ctx->r18) = ctx->r12;
    // 0x8003931C: lw          $t0, 0x2C($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X2C);
    // 0x80039320: sw          $t0, 0x38($s2)
    MEM_W(0X38, ctx->r18) = ctx->r8;
    // 0x80039324: jal         0x80049CFC
    // 0x80039328: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    func_80049CFC(rdram, ctx);
        goto after_1;
    // 0x80039328: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    after_1:
    // 0x8003932C: jal         0x80049D80
    // 0x80039330: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80049D80(rdram, ctx);
        goto after_2;
    // 0x80039330: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80039334: sw          $v0, 0x80($s2)
    MEM_W(0X80, ctx->r18) = ctx->r2;
    // 0x80039338: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8003933C: jal         0x80049DFC
    // 0x80039340: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80049DFC(rdram, ctx);
        goto after_3;
    // 0x80039340: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80039344: sw          $v0, 0x84($s2)
    MEM_W(0X84, ctx->r18) = ctx->r2;
    // 0x80039348: lw          $t5, 0x8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X8);
    // 0x8003934C: lh          $t3, 0x30($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X30);
    // 0x80039350: lui         $s7, 0x2020
    ctx->r23 = S32(0X2020 << 16);
    // 0x80039354: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80039358: sw          $t3, 0xD8($t5)
    MEM_W(0XD8, ctx->r13) = ctx->r11;
    // 0x8003935C: lw          $t8, 0x80($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X80);
    // 0x80039360: lw          $a0, 0x84($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X84);
    // 0x80039364: ori         $s7, $s7, 0x2000
    ctx->r23 = ctx->r23 | 0X2000;
    // 0x80039368: lh          $v1, 0xC($t8)
    ctx->r3 = MEM_H(ctx->r24, 0XC);
    // 0x8003936C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80039370: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80039374: blez        $v1, L_80039444
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80039378: lw          $s3, 0x0($t6)
        ctx->r19 = MEM_W(ctx->r14, 0X0);
            goto L_80039444;
    }
    // 0x80039378: lw          $s3, 0x0($t6)
    ctx->r19 = MEM_W(ctx->r14, 0X0);
    // 0x8003937C: lui         $s6, 0x2020
    ctx->r22 = S32(0X2020 << 16);
    // 0x80039380: ori         $s6, $s6, 0x2079
    ctx->r22 = ctx->r22 | 0X2079;
    // 0x80039384: lwc1        $f20, 0x7404($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X7404);
L_80039388:
    // 0x80039388: lw          $t7, 0x10($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X10);
    // 0x8003938C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80039390: sll         $t2, $s5, 2
    ctx->r10 = S32(ctx->r21 << 2);
    // 0x80039394: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x80039398: addu        $t1, $t9, $s7
    ctx->r9 = ADD32(ctx->r25, ctx->r23);
    // 0x8003939C: bnel        $s6, $t1, L_80039434
    if (ctx->r22 != ctx->r9) {
        // 0x800393A0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80039434;
    }
    goto skip_3;
    // 0x800393A0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_3:
    // 0x800393A4: jal         0x8000F764
    // 0x800393A8: addu        $s1, $s2, $t2
    ctx->r17 = ADD32(ctx->r18, ctx->r10);
    func_8000F764(rdram, ctx);
        goto after_4;
    // 0x800393A8: addu        $s1, $s2, $t2
    ctx->r17 = ADD32(ctx->r18, ctx->r10);
    after_4:
    // 0x800393AC: lw          $t4, 0x84($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X84);
    // 0x800393B0: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x800393B4: addiu       $a0, $v0, 0x10
    ctx->r4 = ADD32(ctx->r2, 0X10);
    // 0x800393B8: lw          $t0, 0x8($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X8);
    // 0x800393BC: lw          $t3, 0xD4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0XD4);
    // 0x800393C0: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x800393C4: sw          $v0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r2;
    // 0x800393C8: lw          $t6, 0x84($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X84);
    // 0x800393CC: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x800393D0: lw          $t7, 0xD4($t8)
    ctx->r15 = MEM_W(ctx->r24, 0XD4);
    // 0x800393D4: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x800393D8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800393DC: lw          $t1, 0x84($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X84);
    // 0x800393E0: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x800393E4: lw          $t4, 0xD4($t2)
    ctx->r12 = MEM_W(ctx->r10, 0XD4);
    // 0x800393E8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800393EC: lw          $t0, 0x84($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X84);
    // 0x800393F0: lw          $t3, 0x8($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X8);
    // 0x800393F4: lw          $t5, 0xD4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0XD4);
    // 0x800393F8: sw          $v0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r2;
    // 0x800393FC: lw          $a1, 0xC($s3)
    ctx->r5 = MEM_W(ctx->r19, 0XC);
    // 0x80039400: jal         0x80002340
    // 0x80039404: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    func_80002340(rdram, ctx);
        goto after_5;
    // 0x80039404: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_5:
    // 0x80039408: sw          $s4, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->r20;
    // 0x8003940C: sw          $s4, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = ctx->r20;
    // 0x80039410: beq         $s5, $zero, L_80039424
    if (ctx->r21 == 0) {
        // 0x80039414: swc1        $f20, 0xA4($s1)
        MEM_W(0XA4, ctx->r17) = ctx->f20.u32l;
            goto L_80039424;
    }
    // 0x80039414: swc1        $f20, 0xA4($s1)
    MEM_W(0XA4, ctx->r17) = ctx->f20.u32l;
    // 0x80039418: lwc1        $f16, 0xA4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XA4);
    // 0x8003941C: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x80039420: swc1        $f18, 0xA4($s1)
    MEM_W(0XA4, ctx->r17) = ctx->f18.u32l;
L_80039424:
    // 0x80039424: lw          $t6, 0x80($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X80);
    // 0x80039428: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8003942C: lh          $v1, 0xC($t6)
    ctx->r3 = MEM_H(ctx->r14, 0XC);
    // 0x80039430: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80039434:
    // 0x80039434: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80039438: bne         $at, $zero, L_80039388
    if (ctx->r1 != 0) {
        // 0x8003943C: lw          $s3, 0x0($s3)
        ctx->r19 = MEM_W(ctx->r19, 0X0);
            goto L_80039388;
    }
    // 0x8003943C: lw          $s3, 0x0($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X0);
    // 0x80039440: lw          $a0, 0x84($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X84);
L_80039444:
    // 0x80039444: jal         0x8004A148
    // 0x80039448: nop

    func_8004A148(rdram, ctx);
        goto after_6;
    // 0x80039448: nop

    after_6:
    // 0x8003944C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80039450: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80039454: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80039458: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8003945C: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80039460: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80039464: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80039468: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x8003946C: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x80039470: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x80039474: jr          $ra
    // 0x80039478: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    TRACE_RETURN()
    return;
    // 0x80039478: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8003947C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8003947C: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x80039480: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80039484: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80039488: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003948C: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80039490: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80039494: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80039498: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8003949C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800394A0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800394A4: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800394A8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800394AC: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800394B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800394B4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800394B8: addiu       $s3, $sp, 0xB0
    ctx->r19 = ADD32(ctx->r29, 0XB0);
L_800394BC:
    // 0x800394BC: lw          $v0, 0x9C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X9C);
    // 0x800394C0: beq         $v0, $zero, L_80039510
    if (ctx->r2 == 0) {
        // 0x800394C4: nop
    
            goto L_80039510;
    }
    // 0x800394C4: nop

    // 0x800394C8: lw          $t6, 0x84($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X84);
    // 0x800394CC: addiu       $s2, $v0, 0x10
    ctx->r18 = ADD32(ctx->r2, 0X10);
    // 0x800394D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800394D4: lw          $a1, 0xC($t6)
    ctx->r5 = MEM_W(ctx->r14, 0XC);
    // 0x800394D8: jal         0x80002340
    // 0x800394DC: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    func_80002340(rdram, ctx);
        goto after_0;
    // 0x800394DC: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_0:
    // 0x800394E0: lw          $a1, 0x94($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X94);
    // 0x800394E4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800394E8: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x800394EC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x800394F0: jal         0x80049840
    // 0x800394F4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80049840(rdram, ctx);
        goto after_1;
    // 0x800394F4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_1:
    // 0x800394F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800394FC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80039500: jal         0x80000BD8
    // 0x80039504: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_80000BD8(rdram, ctx);
        goto after_2;
    // 0x80039504: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_2:
    // 0x80039508: b           L_80039518
    // 0x8003950C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
        goto L_80039518;
    // 0x8003950C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80039510:
    // 0x80039510: b           L_80039528
    // 0x80039514: lh          $v0, 0x8E($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X8E);
        goto L_80039528;
    // 0x80039514: lh          $v0, 0x8E($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X8E);
L_80039518:
    // 0x80039518: slti        $at, $s1, 0x8
    ctx->r1 = SIGNED(ctx->r17) < 0X8 ? 1 : 0;
    // 0x8003951C: bne         $at, $zero, L_800394BC
    if (ctx->r1 != 0) {
        // 0x80039520: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800394BC;
    }
    // 0x80039520: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80039524: lh          $v0, 0x8E($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X8E);
L_80039528:
    // 0x80039528: addiu       $s0, $zero, 0x201
    ctx->r16 = ADD32(0, 0X201);
    // 0x8003952C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80039530: bne         $s0, $v0, L_80039590
    if (ctx->r16 != ctx->r2) {
        // 0x80039534: nop
    
            goto L_80039590;
    }
    // 0x80039534: nop

    // 0x80039538: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8003953C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80039540: jal         0x80001A6C
    // 0x80039544: lui         $a3, 0xC316
    ctx->r7 = S32(0XC316 << 16);
    func_80001A6C(rdram, ctx);
        goto after_3;
    // 0x80039544: lui         $a3, 0xC316
    ctx->r7 = S32(0XC316 << 16);
    after_3:
    // 0x80039548: lw          $v1, 0x9C($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X9C);
    // 0x8003954C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80039550: addiu       $s2, $v1, 0x10
    ctx->r18 = ADD32(ctx->r3, 0X10);
    // 0x80039554: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80039558: jal         0x80000BD8
    // 0x8003955C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80000BD8(rdram, ctx);
        goto after_4;
    // 0x8003955C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_4:
    // 0x80039560: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80039564: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80039568: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8003956C: jal         0x80001A6C
    // 0x80039570: lui         $a3, 0x4316
    ctx->r7 = S32(0X4316 << 16);
    func_80001A6C(rdram, ctx);
        goto after_5;
    // 0x80039570: lui         $a3, 0x4316
    ctx->r7 = S32(0X4316 << 16);
    after_5:
    // 0x80039574: lw          $v1, 0xA0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0XA0);
    // 0x80039578: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x8003957C: addiu       $s2, $v1, 0x10
    ctx->r18 = ADD32(ctx->r3, 0X10);
    // 0x80039580: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80039584: jal         0x80000BD8
    // 0x80039588: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80000BD8(rdram, ctx);
        goto after_6;
    // 0x80039588: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_6:
    // 0x8003958C: lh          $v0, 0x8E($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X8E);
L_80039590:
    // 0x80039590: beq         $s0, $v0, L_800395A4
    if (ctx->r16 == ctx->r2) {
        // 0x80039594: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800395A4;
    }
    // 0x80039594: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80039598: addiu       $at, $zero, 0x301
    ctx->r1 = ADD32(0, 0X301);
    // 0x8003959C: bne         $v0, $at, L_800395D4
    if (ctx->r2 != ctx->r1) {
        // 0x800395A0: or          $s0, $s4, $zero
        ctx->r16 = ctx->r20 | 0;
            goto L_800395D4;
    }
    // 0x800395A0: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
L_800395A4:
    // 0x800395A4: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x800395A8: addiu       $v0, $sp, 0x5C
    ctx->r2 = ADD32(ctx->r29, 0X5C);
    // 0x800395AC: addiu       $v1, $sp, 0x68
    ctx->r3 = ADD32(ctx->r29, 0X68);
L_800395B0:
    // 0x800395B0: lwc1        $f4, 0xF0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x800395B4: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800395B8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800395BC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800395C0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800395C4: bne         $v0, $v1, L_800395B0
    if (ctx->r2 != ctx->r3) {
        // 0x800395C8: swc1        $f8, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
            goto L_800395B0;
    }
    // 0x800395C8: swc1        $f8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
    // 0x800395CC: b           L_800395F4
    // 0x800395D0: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
        goto L_800395F4;
    // 0x800395D0: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
L_800395D4:
    // 0x800395D4: addiu       $v0, $sp, 0x5C
    ctx->r2 = ADD32(ctx->r29, 0X5C);
    // 0x800395D8: addiu       $v1, $sp, 0x68
    ctx->r3 = ADD32(ctx->r29, 0X68);
L_800395DC:
    // 0x800395DC: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800395E0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800395E4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800395E8: bne         $v0, $v1, L_800395DC
    if (ctx->r2 != ctx->r3) {
        // 0x800395EC: swc1        $f10, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
            goto L_800395DC;
    }
    // 0x800395EC: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x800395F0: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
L_800395F4:
    // 0x800395F4: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800395F8: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x800395FC: jal         0x80049840
    // 0x80039600: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    func_80049840(rdram, ctx);
        goto after_7;
    // 0x80039600: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_7:
    // 0x80039604: addiu       $s0, $sp, 0x70
    ctx->r16 = ADD32(ctx->r29, 0X70);
    // 0x80039608: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8003960C: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80039610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80039614: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x80039618: jal         0x80049840
    // 0x8003961C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    func_80049840(rdram, ctx);
        goto after_8;
    // 0x8003961C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_8:
    // 0x80039620: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80039624: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80039628: jal         0x80000BD8
    // 0x8003962C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80000BD8(rdram, ctx);
        goto after_9;
    // 0x8003962C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_9:
    // 0x80039630: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80039634: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80039638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003963C: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80039640: jal         0x80049840
    // 0x80039644: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    func_80049840(rdram, ctx);
        goto after_10;
    // 0x80039644: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_10:
    // 0x80039648: lw          $t7, 0x84($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X84);
    // 0x8003964C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80039650: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80039654: lw          $a0, 0x8($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X8);
    // 0x80039658: jal         0x80000BD8
    // 0x8003965C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80000BD8(rdram, ctx);
        goto after_11;
    // 0x8003965C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_11:
    // 0x80039660: lwc1        $f0, 0x24($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X24);
    // 0x80039664: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80039668: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003966C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80039670: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80039674: jal         0x80001AB4
    // 0x80039678: nop

    func_80001AB4(rdram, ctx);
        goto after_12;
    // 0x80039678: nop

    after_12:
    // 0x8003967C: lw          $t8, 0x84($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X84);
    // 0x80039680: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80039684: lw          $a0, 0x8($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X8);
    // 0x80039688: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8003968C: jal         0x80000BD8
    // 0x80039690: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_80000BD8(rdram, ctx);
        goto after_13;
    // 0x80039690: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_13:
    // 0x80039694: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80039698: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x8003969C: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_800396A0:
    // 0x800396A0: lw          $t9, 0x84($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X84);
    // 0x800396A4: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800396A8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800396AC: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x800396B0: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x800396B4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800396B8: bne         $s1, $v0, L_800396A0
    if (ctx->r17 != ctx->r2) {
        // 0x800396BC: swc1        $f16, 0x40($t1)
        MEM_W(0X40, ctx->r9) = ctx->f16.u32l;
            goto L_800396A0;
    }
    // 0x800396BC: swc1        $f16, 0x40($t1)
    MEM_W(0X40, ctx->r9) = ctx->f16.u32l;
    // 0x800396C0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800396C4: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800396C8: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800396CC: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800396D0: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800396D4: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800396D8: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x800396DC: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x800396E0: jr          $ra
    // 0x800396E4: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    TRACE_RETURN()
    return;
    // 0x800396E4: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
;}
