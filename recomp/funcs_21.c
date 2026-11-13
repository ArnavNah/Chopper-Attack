#include "recomp.h"
#include "trace.h"
#include "funcs.h"

RECOMP_FUNC void func_8004D134(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004D134: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x8004D138: sra         $v1, $t8, 16
    ctx->r3 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8004D13C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8004D140: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8004D144: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8004D148: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8004D14C: sll         $t0, $a2, 16
    ctx->r8 = S32(ctx->r6 << 16);
    // 0x8004D150: lui         $a3, 0x8007
    ctx->r7 = S32(0X8007 << 16);
    // 0x8004D154: sra         $a2, $t0, 16
    ctx->r6 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8004D158: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8004D15C: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8004D160: addiu       $a3, $a3, -0x4440
    ctx->r7 = ADD32(ctx->r7, -0X4440);
    // 0x8004D164: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004D168:
    // 0x8004D168: sll         $t2, $v0, 4
    ctx->r10 = S32(ctx->r2 << 4);
    // 0x8004D16C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004D170: sll         $t4, $v0, 16
    ctx->r12 = S32(ctx->r2 << 16);
    // 0x8004D174: sra         $v0, $t4, 16
    ctx->r2 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8004D178: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8004D17C: addu        $t3, $a3, $t2
    ctx->r11 = ADD32(ctx->r7, ctx->r10);
    // 0x8004D180: bne         $at, $zero, L_8004D168
    if (ctx->r1 != 0) {
        // 0x8004D184: sb          $v1, 0xF($t3)
        MEM_B(0XF, ctx->r11) = ctx->r3;
            goto L_8004D168;
    }
    // 0x8004D184: sb          $v1, 0xF($t3)
    MEM_B(0XF, ctx->r11) = ctx->r3;
    // 0x8004D188: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004D18C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004D190: sh          $a0, -0x4A1E($at)
    MEM_H(-0X4A1E, ctx->r1) = ctx->r4;
    // 0x8004D194: addiu       $v1, $v1, -0x4A1C
    ctx->r3 = ADD32(ctx->r3, -0X4A1C);
    // 0x8004D198: sh          $a1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r5;
    // 0x8004D19C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004D1A0: sh          $a2, -0x4A1A($at)
    MEM_H(-0X4A1A, ctx->r1) = ctx->r6;
    // 0x8004D1A4: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x8004D1A8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004D1AC: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x8004D1B0: sh          $t6, -0x4A18($at)
    MEM_H(-0X4A18, ctx->r1) = ctx->r14;
    // 0x8004D1B4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004D1B8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8004D1BC: addiu       $a3, $a3, -0x4A40
    ctx->r7 = ADD32(ctx->r7, -0X4A40);
    // 0x8004D1C0: sh          $t7, -0x4A20($at)
    MEM_H(-0X4A20, ctx->r1) = ctx->r15;
    // 0x8004D1C4: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x8004D1C8: lui         $t8, 0x8007
    ctx->r24 = S32(0X8007 << 16);
    // 0x8004D1CC: addiu       $t8, $t8, -0x4400
    ctx->r24 = ADD32(ctx->r24, -0X4400);
    // 0x8004D1D0: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x8004D1D4: sw          $t8, 0xD0($t0)
    MEM_W(0XD0, ctx->r8) = ctx->r24;
    // 0x8004D1D8: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x8004D1DC: lw          $v0, 0x8($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X8);
    // 0x8004D1E0: lw          $t2, 0xD8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XD8);
    // 0x8004D1E4: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x8004D1E8: jr          $ra
    // 0x8004D1EC: sw          $t3, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r11;
    TRACE_RETURN()
    return;
    // 0x8004D1EC: sw          $t3, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r11;
;}
RECOMP_FUNC void func_8004D1F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004D1F0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004D1F4: jr          $ra
    // 0x8004D1F8: lh          $v0, -0x4A20($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X4A20);
    TRACE_RETURN()
    return;
    // 0x8004D1F8: lh          $v0, -0x4A20($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X4A20);
    // 0x8004D1FC: nop

}
RECOMP_FUNC void func_8004D200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004D200: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8004D204: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8004D208: lui         $s6, 0x801A
    ctx->r22 = S32(0X801A << 16);
    // 0x8004D20C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8004D210: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8004D214: addiu       $s6, $s6, 0x2800
    ctx->r22 = ADD32(ctx->r22, 0X2800);
    // 0x8004D218: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8004D21C: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8004D220: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8004D224: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8004D228: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8004D22C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8004D230: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8004D234: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8004D238: jal         0x80004364
    // 0x8004D23C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x8004D23C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_0:
    // 0x8004D240: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x8004D244: addiu       $s5, $s5, -0x4A10
    ctx->r21 = ADD32(ctx->r21, -0X4A10);
    // 0x8004D248: sw          $v0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r2;
    // 0x8004D24C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8004D250: jal         0x8000C7C0
    // 0x8004D254: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_8000C7C0(rdram, ctx);
        goto after_1;
    // 0x8004D254: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_1:
    // 0x8004D258: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8004D25C: jal         0x80004364
    // 0x8004D260: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_80004364(rdram, ctx);
        goto after_2;
    // 0x8004D260: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_2:
    // 0x8004D264: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x8004D268: addiu       $s7, $s7, -0x4A0C
    ctx->r23 = ADD32(ctx->r23, -0X4A0C);
    // 0x8004D26C: sw          $v0, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r2;
    // 0x8004D270: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8004D274: jal         0x8000C7C0
    // 0x8004D278: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_8000C7C0(rdram, ctx);
        goto after_3;
    // 0x8004D278: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_3:
    // 0x8004D27C: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    // 0x8004D280: addiu       $s3, $zero, -0x5
    ctx->r19 = ADD32(0, -0X5);
    // 0x8004D284: addiu       $s2, $zero, -0x3
    ctx->r18 = ADD32(0, -0X3);
    // 0x8004D288: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x8004D28C: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x8004D290: addiu       $s1, $zero, 0xFF
    ctx->r17 = ADD32(0, 0XFF);
    // 0x8004D294: addiu       $s0, $zero, -0x2
    ctx->r16 = ADD32(0, -0X2);
    // 0x8004D298: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x8004D29C: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x8004D2A0: lw          $t9, 0x0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X0);
    // 0x8004D2A4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8004D2A8: lw          $t1, 0x0($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X0);
    // 0x8004D2AC: lw          $t0, 0x0($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X0);
    // 0x8004D2B0: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x8004D2B4: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
L_8004D2B8:
    // 0x8004D2B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004D2BC: bne         $v0, $at, L_8004D300
    if (ctx->r2 != ctx->r1) {
        // 0x8004D2C0: nop
    
            goto L_8004D300;
    }
    // 0x8004D2C0: nop

    // 0x8004D2C4: jal         0x8000798C
    // 0x8004D2C8: nop

    func_8000798C(rdram, ctx);
        goto after_4;
    // 0x8004D2C8: nop

    after_4:
    // 0x8004D2CC: jal         0x8000798C
    // 0x8004D2D0: nop

    func_8000798C(rdram, ctx);
        goto after_5;
    // 0x8004D2D0: nop

    after_5:
    // 0x8004D2D4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8004D2D8: jal         0x800042A8
    // 0x8004D2DC: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
    func_800042A8(rdram, ctx);
        goto after_6;
    // 0x8004D2DC: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
    after_6:
    // 0x8004D2E0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8004D2E4: jal         0x800042A8
    // 0x8004D2E8: lw          $a1, 0x0($s7)
    ctx->r5 = MEM_W(ctx->r23, 0X0);
    func_800042A8(rdram, ctx);
        goto after_7;
    // 0x8004D2E8: lw          $a1, 0x0($s7)
    ctx->r5 = MEM_W(ctx->r23, 0X0);
    after_7:
    // 0x8004D2EC: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
L_8004D2F0:
    // 0x8004D2F0: jal         0x8000798C
    // 0x8004D2F4: nop

    func_8000798C(rdram, ctx);
        goto after_8;
    // 0x8004D2F4: nop

    after_8:
    // 0x8004D2F8: b           L_8004D2F0
    // 0x8004D2FC: nop

        goto L_8004D2F0;
    // 0x8004D2FC: nop

L_8004D300:
    // 0x8004D300: bnel        $s0, $v0, L_8004D328
    if (ctx->r16 != ctx->r2) {
        // 0x8004D304: lw          $t3, 0x0($s5)
        ctx->r11 = MEM_W(ctx->r21, 0X0);
            goto L_8004D328;
    }
    goto skip_0;
    // 0x8004D304: lw          $t3, 0x0($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X0);
    skip_0:
    // 0x8004D308: bnel        $s0, $v0, L_8004D328
    if (ctx->r16 != ctx->r2) {
        // 0x8004D30C: lw          $t3, 0x0($s5)
        ctx->r11 = MEM_W(ctx->r21, 0X0);
            goto L_8004D328;
    }
    goto skip_1;
    // 0x8004D30C: lw          $t3, 0x0($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X0);
    skip_1:
L_8004D310:
    // 0x8004D310: jal         0x8000798C
    // 0x8004D314: nop

    func_8000798C(rdram, ctx);
        goto after_9;
    // 0x8004D314: nop

    after_9:
    // 0x8004D318: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x8004D31C: beq         $s0, $t2, L_8004D310
    if (ctx->r16 == ctx->r10) {
        // 0x8004D320: nop
    
            goto L_8004D310;
    }
    // 0x8004D320: nop

    // 0x8004D324: lw          $t3, 0x0($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X0);
L_8004D328:
    // 0x8004D328: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8004D32C: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8004D330: beq         $t4, $zero, L_8004D448
    if (ctx->r12 == 0) {
        // 0x8004D334: nop
    
            goto L_8004D448;
    }
    // 0x8004D334: nop

    // 0x8004D338: lbu         $v1, 0x10($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X10);
L_8004D33C:
    // 0x8004D33C: andi        $t5, $v1, 0x4
    ctx->r13 = ctx->r3 & 0X4;
    // 0x8004D340: beq         $t5, $zero, L_8004D360
    if (ctx->r13 == 0) {
        // 0x8004D344: andi        $t6, $v1, 0x2
        ctx->r14 = ctx->r3 & 0X2;
            goto L_8004D360;
    }
    // 0x8004D344: andi        $t6, $v1, 0x2
    ctx->r14 = ctx->r3 & 0X2;
    // 0x8004D348: bne         $t6, $zero, L_8004D360
    if (ctx->r14 != 0) {
        // 0x8004D34C: ori         $t7, $v1, 0x2
        ctx->r15 = ctx->r3 | 0X2;
            goto L_8004D360;
    }
    // 0x8004D34C: ori         $t7, $v1, 0x2
    ctx->r15 = ctx->r3 | 0X2;
    // 0x8004D350: sb          $t7, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r15;
    // 0x8004D354: sb          $s1, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r17;
    // 0x8004D358: sb          $zero, 0x15($v0)
    MEM_B(0X15, ctx->r2) = 0;
    // 0x8004D35C: andi        $v1, $t7, 0xFF
    ctx->r3 = ctx->r15 & 0XFF;
L_8004D360:
    // 0x8004D360: andi        $t8, $v1, 0x2
    ctx->r24 = ctx->r3 & 0X2;
    // 0x8004D364: beql        $t8, $zero, L_8004D43C
    if (ctx->r24 == 0) {
        // 0x8004D368: lw          $v0, 0x0($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X0);
            goto L_8004D43C;
    }
    goto skip_2;
    // 0x8004D368: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    skip_2:
    // 0x8004D36C: lbu         $v1, 0x15($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X15);
    // 0x8004D370: bnel        $v1, $zero, L_8004D434
    if (ctx->r3 != 0) {
        // 0x8004D374: addiu       $t4, $v1, -0x1
        ctx->r12 = ADD32(ctx->r3, -0X1);
            goto L_8004D434;
    }
    goto skip_3;
    // 0x8004D374: addiu       $t4, $v1, -0x1
    ctx->r12 = ADD32(ctx->r3, -0X1);
    skip_3:
    // 0x8004D378: lbu         $t9, 0x14($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X14);
    // 0x8004D37C: lbu         $t1, 0x11($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X11);
    // 0x8004D380: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8004D384: andi        $a0, $t0, 0xFF
    ctx->r4 = ctx->r8 & 0XFF;
    // 0x8004D388: bne         $t1, $a0, L_8004D3D0
    if (ctx->r9 != ctx->r4) {
        // 0x8004D38C: sb          $t0, 0x14($v0)
        MEM_B(0X14, ctx->r2) = ctx->r8;
            goto L_8004D3D0;
    }
    // 0x8004D38C: sb          $t0, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r8;
    // 0x8004D390: lbu         $a1, 0x13($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X13);
    // 0x8004D394: beq         $a1, $zero, L_8004D3A4
    if (ctx->r5 == 0) {
        // 0x8004D398: addu        $t2, $a0, $a1
        ctx->r10 = ADD32(ctx->r4, ctx->r5);
            goto L_8004D3A4;
    }
    // 0x8004D398: addu        $t2, $a0, $a1
    ctx->r10 = ADD32(ctx->r4, ctx->r5);
    // 0x8004D39C: b           L_8004D3D0
    // 0x8004D3A0: sb          $t2, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r10;
        goto L_8004D3D0;
    // 0x8004D3A0: sb          $t2, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r10;
L_8004D3A4:
    // 0x8004D3A4: lbu         $v1, 0x10($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X10);
    // 0x8004D3A8: addiu       $t4, $a0, -0x1
    ctx->r12 = ADD32(ctx->r4, -0X1);
    // 0x8004D3AC: andi        $t3, $v1, 0x8
    ctx->r11 = ctx->r3 & 0X8;
    // 0x8004D3B0: beq         $t3, $zero, L_8004D3C0
    if (ctx->r11 == 0) {
        // 0x8004D3B4: and         $t6, $v1, $s2
        ctx->r14 = ctx->r3 & ctx->r18;
            goto L_8004D3C0;
    }
    // 0x8004D3B4: and         $t6, $v1, $s2
    ctx->r14 = ctx->r3 & ctx->r18;
    // 0x8004D3B8: b           L_8004D3D0
    // 0x8004D3BC: sb          $zero, 0x14($v0)
    MEM_B(0X14, ctx->r2) = 0;
        goto L_8004D3D0;
    // 0x8004D3BC: sb          $zero, 0x14($v0)
    MEM_B(0X14, ctx->r2) = 0;
L_8004D3C0:
    // 0x8004D3C0: sb          $t6, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r14;
    // 0x8004D3C4: and         $t7, $t6, $s3
    ctx->r15 = ctx->r14 & ctx->r19;
    // 0x8004D3C8: sb          $t4, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r12;
    // 0x8004D3CC: sb          $t7, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r15;
L_8004D3D0:
    // 0x8004D3D0: lbu         $t9, 0x10($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X10);
    // 0x8004D3D4: lbu         $t8, 0x12($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X12);
    // 0x8004D3D8: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x8004D3DC: andi        $t0, $t9, 0x10
    ctx->r8 = ctx->r25 & 0X10;
    // 0x8004D3E0: beq         $t0, $zero, L_8004D414
    if (ctx->r8 == 0) {
        // 0x8004D3E4: sb          $t8, 0x15($v0)
        MEM_B(0X15, ctx->r2) = ctx->r24;
            goto L_8004D414;
    }
    // 0x8004D3E4: sb          $t8, 0x15($v0)
    MEM_B(0X15, ctx->r2) = ctx->r24;
    // 0x8004D3E8: lw          $t1, 0x1C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X1C);
    // 0x8004D3EC: lbu         $t2, 0x14($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X14);
    // 0x8004D3F0: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x8004D3F4: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8004D3F8: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x8004D3FC: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8004D400: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x8004D404: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8004D408: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8004D40C: b           L_8004D430
    // 0x8004D410: lbu         $v1, 0x15($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X15);
        goto L_8004D430;
    // 0x8004D410: lbu         $v1, 0x15($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X15);
L_8004D414:
    // 0x8004D414: lbu         $t9, 0x14($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X14);
    // 0x8004D418: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x8004D41C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8004D420: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x8004D424: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8004D428: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8004D42C: lbu         $v1, 0x15($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X15);
L_8004D430:
    // 0x8004D430: addiu       $t4, $v1, -0x1
    ctx->r12 = ADD32(ctx->r3, -0X1);
L_8004D434:
    // 0x8004D434: sb          $t4, 0x15($v0)
    MEM_B(0X15, ctx->r2) = ctx->r12;
    // 0x8004D438: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
L_8004D43C:
    // 0x8004D43C: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8004D440: bnel        $t5, $zero, L_8004D33C
    if (ctx->r13 != 0) {
        // 0x8004D444: lbu         $v1, 0x10($v0)
        ctx->r3 = MEM_BU(ctx->r2, 0X10);
            goto L_8004D33C;
    }
    goto skip_4;
    // 0x8004D444: lbu         $v1, 0x10($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X10);
    skip_4:
L_8004D448:
    // 0x8004D448: jal         0x8000798C
    // 0x8004D44C: nop

    func_8000798C(rdram, ctx);
        goto after_10;
    // 0x8004D44C: nop

    after_10:
    // 0x8004D450: b           L_8004D2B8
    // 0x8004D454: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
        goto L_8004D2B8;
    // 0x8004D454: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x8004D458: nop

    // 0x8004D45C: nop

    // 0x8004D460: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8004D464: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8004D468: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8004D46C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8004D470: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8004D474: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8004D478: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8004D47C: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8004D480: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8004D484: jr          $ra
    // 0x8004D488: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    TRACE_RETURN()
    return;
    // 0x8004D488: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8004D48C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004D48C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8004D490: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004D494: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8004D498: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8004D49C: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8004D4A0: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8004D4A4: sll         $t6, $a3, 16
    ctx->r14 = S32(ctx->r7 << 16);
    // 0x8004D4A8: lui         $t0, 0x8007
    ctx->r8 = S32(0X8007 << 16);
    // 0x8004D4AC: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x8004D4B0: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x8004D4B4: sra         $a3, $t6, 16
    ctx->r7 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8004D4B8: addiu       $t0, $t0, -0x3390
    ctx->r8 = ADD32(ctx->r8, -0X3390);
    // 0x8004D4BC: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8004D4C0: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
L_8004D4C4:
    // 0x8004D4C4: lbu         $v1, 0x8($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0X8);
    // 0x8004D4C8: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8004D4CC: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8004D4D0: beq         $a0, $v1, L_8004D4F8
    if (ctx->r4 == ctx->r3) {
        // 0x8004D4D4: nop
    
            goto L_8004D4F8;
    }
    // 0x8004D4D4: nop

    // 0x8004D4D8: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8004D4DC: bne         $t1, $t2, L_8004D4F0
    if (ctx->r9 != ctx->r10) {
        // 0x8004D4E0: nop
    
            goto L_8004D4F0;
    }
    // 0x8004D4E0: nop

    // 0x8004D4E4: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x8004D4E8: beq         $t3, $t4, L_8004D4F8
    if (ctx->r11 == ctx->r12) {
        // 0x8004D4EC: nop
    
            goto L_8004D4F8;
    }
    // 0x8004D4EC: nop

L_8004D4F0:
    // 0x8004D4F0: b           L_8004D4C4
    // 0x8004D4F4: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
        goto L_8004D4C4;
    // 0x8004D4F4: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
L_8004D4F8:
    // 0x8004D4F8: bne         $a0, $v1, L_8004D508
    if (ctx->r4 != ctx->r3) {
        // 0x8004D4FC: or          $v0, $a3, $zero
        ctx->r2 = ctx->r7 | 0;
            goto L_8004D508;
    }
    // 0x8004D4FC: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8004D500: b           L_8004D61C
    // 0x8004D504: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8004D61C;
    // 0x8004D504: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004D508:
    // 0x8004D508: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x8004D50C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004D510: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8004D514: sll         $a1, $a3, 2
    ctx->r5 = S32(ctx->r7 << 2);
    // 0x8004D518: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x8004D51C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8004D520: jal         0x80004364
    // 0x8004D524: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x8004D524: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8004D528: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x8004D52C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8004D530: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8004D534: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8004D538: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8004D53C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8004D540: beq         $t6, $zero, L_8004D564
    if (ctx->r14 == 0) {
        // 0x8004D544: addiu       $a1, $zero, 0x20
        ctx->r5 = ADD32(0, 0X20);
            goto L_8004D564;
    }
    // 0x8004D544: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8004D548: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
L_8004D54C:
    // 0x8004D54C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8004D550: sw          $t7, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->r15;
    // 0x8004D554: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8004D558: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8004D55C: bnel        $t8, $zero, L_8004D54C
    if (ctx->r24 != 0) {
        // 0x8004D560: lw          $t7, 0x8($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X8);
            goto L_8004D54C;
    }
    goto skip_0;
    // 0x8004D560: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    skip_0:
L_8004D564:
    // 0x8004D564: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004D568: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8004D56C: jal         0x80004364
    // 0x8004D570: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    func_80004364(rdram, ctx);
        goto after_1;
    // 0x8004D570: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_1:
    // 0x8004D574: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8004D578: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8004D57C: jal         0x8000C7C0
    // 0x8004D580: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    func_8000C7C0(rdram, ctx);
        goto after_2;
    // 0x8004D580: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_2:
    // 0x8004D584: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x8004D588: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8004D58C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8004D590: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8004D594: sw          $t9, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r25;
    // 0x8004D598: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8004D59C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004D5A0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8004D5A4: sw          $t1, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r9;
    // 0x8004D5A8: lbu         $t7, 0x8($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X8);
    // 0x8004D5AC: sb          $t7, 0x10($a2)
    MEM_B(0X10, ctx->r6) = ctx->r15;
    // 0x8004D5B0: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8004D5B4: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x8004D5B8: sb          $t3, 0x11($a2)
    MEM_B(0X11, ctx->r6) = ctx->r11;
    // 0x8004D5BC: lbu         $t4, 0x9($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X9);
    // 0x8004D5C0: sb          $zero, 0x13($a2)
    MEM_B(0X13, ctx->r6) = 0;
    // 0x8004D5C4: sb          $t4, 0x12($a2)
    MEM_B(0X12, ctx->r6) = ctx->r12;
    // 0x8004D5C8: lw          $t5, 0xC($t0)
    ctx->r13 = MEM_W(ctx->r8, 0XC);
    // 0x8004D5CC: sb          $t6, 0x14($a2)
    MEM_B(0X14, ctx->r6) = ctx->r14;
    // 0x8004D5D0: sb          $zero, 0x15($a2)
    MEM_B(0X15, ctx->r6) = 0;
    // 0x8004D5D4: beq         $t8, $zero, L_8004D5E8
    if (ctx->r24 == 0) {
        // 0x8004D5D8: sw          $t5, 0x18($a2)
        MEM_W(0X18, ctx->r6) = ctx->r13;
            goto L_8004D5E8;
    }
    // 0x8004D5D8: sw          $t5, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r13;
    // 0x8004D5DC: jal         0x8004D62C
    // 0x8004D5E0: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    func_8004D62C(rdram, ctx);
        goto after_3;
    // 0x8004D5E0: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    after_3:
    // 0x8004D5E4: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
L_8004D5E8:
    // 0x8004D5E8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004D5EC: addiu       $v1, $v1, -0x4A0C
    ctx->r3 = ADD32(ctx->r3, -0X4A0C);
    // 0x8004D5F0: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8004D5F4: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8004D5F8: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x8004D5FC: sw          $a2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r6;
    // 0x8004D600: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8004D604: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x8004D608: sw          $t3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r11;
    // 0x8004D60C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8004D610: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x8004D614: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8004D618: sw          $a2, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r6;
L_8004D61C:
    // 0x8004D61C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004D620: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8004D624: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8004D62C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004D62C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8004D630: lw          $t8, 0x18($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X18);
    // 0x8004D634: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x8004D638: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8004D63C: lbu         $t1, 0x10($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X10);
    // 0x8004D640: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8004D644: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8004D648: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8004D64C: andi        $t3, $t1, 0xFFF6
    ctx->r11 = ctx->r9 & 0XFFF6;
    // 0x8004D650: sb          $t3, 0x10($a0)
    MEM_B(0X10, ctx->r4) = ctx->r11;
    // 0x8004D654: lbu         $t4, 0x0($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X0);
    // 0x8004D658: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8004D65C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8004D660: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x8004D664: sb          $t5, 0x10($a0)
    MEM_B(0X10, ctx->r4) = ctx->r13;
    // 0x8004D668: lbu         $t6, -0x3($v0)
    ctx->r14 = MEM_BU(ctx->r2, -0X3);
    // 0x8004D66C: sb          $t6, 0x12($a0)
    MEM_B(0X12, ctx->r4) = ctx->r14;
    // 0x8004D670: lbu         $t7, -0x2($v0)
    ctx->r15 = MEM_BU(ctx->r2, -0X2);
    // 0x8004D674: sb          $t7, 0x11($a0)
    MEM_B(0X11, ctx->r4) = ctx->r15;
    // 0x8004D678: lbu         $t8, -0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, -0X1);
    // 0x8004D67C: sw          $v0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r2;
    // 0x8004D680: sb          $t9, 0x14($a0)
    MEM_B(0X14, ctx->r4) = ctx->r25;
    // 0x8004D684: sb          $zero, 0x15($a0)
    MEM_B(0X15, ctx->r4) = 0;
    // 0x8004D688: jr          $ra
    // 0x8004D68C: sb          $t8, 0x13($a0)
    MEM_B(0X13, ctx->r4) = ctx->r24;
    TRACE_RETURN()
    return;
    // 0x8004D68C: sb          $t8, 0x13($a0)
    MEM_B(0X13, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_8004D690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004D690: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004D694: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004D698: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8004D69C: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x8004D6A0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8004D6A4: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8004D6A8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8004D6AC: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8004D6B0: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x8004D6B4: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004D6B8: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8004D6BC: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8004D6C0: lw          $a1, 0xC($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XC);
    // 0x8004D6C4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x8004D6C8: jal         0x8001026C
    // 0x8004D6CC: addiu       $a2, $a2, -0x6C60
    ctx->r6 = ADD32(ctx->r6, -0X6C60);
    func_8001026C(rdram, ctx);
        goto after_0;
    // 0x8004D6CC: addiu       $a2, $a2, -0x6C60
    ctx->r6 = ADD32(ctx->r6, -0X6C60);
    after_0:
    // 0x8004D6D0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004D6D4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8004D6D8: jal         0x800042A8
    // 0x8004D6DC: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    func_800042A8(rdram, ctx);
        goto after_1;
    // 0x8004D6DC: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    after_1:
    // 0x8004D6E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004D6E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004D6E8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8004D6F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004D6F0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8004D6F4: lw          $t6, -0x6630($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6630);
    // 0x8004D6F8: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x8004D6FC: lui         $t8, 0x8007
    ctx->r24 = S32(0X8007 << 16);
    // 0x8004D700: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8004D704: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8004D708: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8004D70C: addiu       $t8, $t8, -0x2F20
    ctx->r24 = ADD32(ctx->r24, -0X2F20);
    // 0x8004D710: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8004D714: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x8004D718: lw          $s1, -0x8($v0)
    ctx->r17 = MEM_W(ctx->r2, -0X8);
    // 0x8004D71C: lw          $v1, -0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X4);
    // 0x8004D720: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x8004D724: lw          $t0, -0xC($v0)
    ctx->r8 = MEM_W(ctx->r2, -0XC);
    // 0x8004D728: lui         $s4, 0x801A
    ctx->r20 = S32(0X801A << 16);
    // 0x8004D72C: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x8004D730: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x8004D734: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8004D738: addiu       $s4, $s4, 0x2800
    ctx->r20 = ADD32(ctx->r20, 0X2800);
    // 0x8004D73C: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8004D740: subu        $s2, $v1, $s1
    ctx->r18 = SUB32(ctx->r3, ctx->r17);
    // 0x8004D744: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x8004D748: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x8004D74C: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x8004D750: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8004D754: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8004D758: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8004D75C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8004D760: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8004D764: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8004D768: jal         0x80004364
    // 0x8004D76C: sw          $t0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r8;
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x8004D76C: sw          $t0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r8;
    after_0:
    // 0x8004D770: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8004D774: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004D778: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8004D77C: jal         0x8000C5FC
    // 0x8004D780: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    dma_read_rom(rdram, ctx);
        goto after_1;
    // 0x8004D780: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_1:
    // 0x8004D784: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004D788: lw          $v1, -0x6630($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6630);
    // 0x8004D78C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004D790: lw          $t0, 0x88($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X88);
    // 0x8004D794: bne         $v1, $at, L_8004D7B4
    if (ctx->r3 != ctx->r1) {
        // 0x8004D798: addiu       $t1, $v1, -0x1
        ctx->r9 = ADD32(ctx->r3, -0X1);
            goto L_8004D7B4;
    }
    // 0x8004D798: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
    // 0x8004D79C: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x8004D7A0: addiu       $s5, $s5, -0x49CC
    ctx->r21 = ADD32(ctx->r21, -0X49CC);
    // 0x8004D7A4: addiu       $t9, $zero, 0x4B
    ctx->r25 = ADD32(0, 0X4B);
    // 0x8004D7A8: sw          $t9, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r25;
    // 0x8004D7AC: b           L_8004D7C4
    // 0x8004D7B0: addiu       $v0, $zero, 0x96
    ctx->r2 = ADD32(0, 0X96);
        goto L_8004D7C4;
    // 0x8004D7B0: addiu       $v0, $zero, 0x96
    ctx->r2 = ADD32(0, 0X96);
L_8004D7B4:
    // 0x8004D7B4: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x8004D7B8: addiu       $s5, $s5, -0x49CC
    ctx->r21 = ADD32(ctx->r21, -0X49CC);
    // 0x8004D7BC: addiu       $v0, $zero, 0x96
    ctx->r2 = ADD32(0, 0X96);
    // 0x8004D7C0: sw          $v0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r2;
L_8004D7C4:
    // 0x8004D7C4: sltiu       $at, $t1, 0x7
    ctx->r1 = ctx->r9 < 0X7 ? 1 : 0;
    // 0x8004D7C8: beq         $at, $zero, L_8004D81C
    if (ctx->r1 == 0) {
        // 0x8004D7CC: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_8004D81C;
    }
    // 0x8004D7CC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8004D7D0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8004D7D4: addu        $at, $at, $t1
    gpr jr_addend_8004D7DC = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8004D7D8: lw          $t1, -0x7000($at)
    ctx->r9 = ADD32(ctx->r1, -0X7000);
    // 0x8004D7DC: jr          $t1
    // 0x8004D7E0: nop

    switch (jr_addend_8004D7DC >> 2) {
        case 0: goto L_8004D7E4; break;
        case 1: goto L_8004D7EC; break;
        case 2: goto L_8004D7F4; break;
        case 3: goto L_8004D800; break;
        case 4: goto L_8004D808; break;
        case 5: goto L_8004D810; break;
        case 6: goto L_8004D818; break;
        default: switch_error(__func__, 0x8004D7DC, 0x80079000);
    }
    // 0x8004D7E0: nop

L_8004D7E4:
    // 0x8004D7E4: b           L_8004D81C
    // 0x8004D7E8: sw          $v0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r2;
        goto L_8004D81C;
    // 0x8004D7E8: sw          $v0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r2;
L_8004D7EC:
    // 0x8004D7EC: b           L_8004D81C
    // 0x8004D7F0: sw          $v0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r2;
        goto L_8004D81C;
    // 0x8004D7F0: sw          $v0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r2;
L_8004D7F4:
    // 0x8004D7F4: addiu       $t2, $zero, 0x4B
    ctx->r10 = ADD32(0, 0X4B);
    // 0x8004D7F8: b           L_8004D81C
    // 0x8004D7FC: sw          $t2, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r10;
        goto L_8004D81C;
    // 0x8004D7FC: sw          $t2, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r10;
L_8004D800:
    // 0x8004D800: b           L_8004D81C
    // 0x8004D804: sw          $v0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r2;
        goto L_8004D81C;
    // 0x8004D804: sw          $v0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r2;
L_8004D808:
    // 0x8004D808: b           L_8004D81C
    // 0x8004D80C: sw          $v0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r2;
        goto L_8004D81C;
    // 0x8004D80C: sw          $v0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r2;
L_8004D810:
    // 0x8004D810: b           L_8004D81C
    // 0x8004D814: sw          $v0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r2;
        goto L_8004D81C;
    // 0x8004D814: sw          $v0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r2;
L_8004D818:
    // 0x8004D818: sw          $v0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r2;
L_8004D81C:
    // 0x8004D81C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8004D820: lw          $t2, 0x10($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X10);
    // 0x8004D824: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x8004D828: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x8004D82C: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x8004D830: subu        $t4, $t3, $t0
    ctx->r12 = SUB32(ctx->r11, ctx->r8);
    // 0x8004D834: addu        $a0, $t4, $s0
    ctx->r4 = ADD32(ctx->r12, ctx->r16);
    // 0x8004D838: subu        $t3, $t2, $t0
    ctx->r11 = SUB32(ctx->r10, ctx->r8);
    // 0x8004D83C: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x8004D840: subu        $t6, $t5, $t0
    ctx->r14 = SUB32(ctx->r13, ctx->r8);
    // 0x8004D844: subu        $t8, $t7, $t0
    ctx->r24 = SUB32(ctx->r15, ctx->r8);
    // 0x8004D848: subu        $t1, $t9, $t0
    ctx->r9 = SUB32(ctx->r25, ctx->r8);
    // 0x8004D84C: addu        $a3, $t1, $s0
    ctx->r7 = ADD32(ctx->r9, ctx->r16);
    // 0x8004D850: addu        $a2, $t8, $s0
    ctx->r6 = ADD32(ctx->r24, ctx->r16);
    // 0x8004D854: addu        $a1, $t6, $s0
    ctx->r5 = ADD32(ctx->r14, ctx->r16);
    // 0x8004D858: jal         0x8004DBC8
    // 0x8004D85C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    func_8004DBC8(rdram, ctx);
        goto after_2;
    // 0x8004D85C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_2:
    // 0x8004D860: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8004D864: jal         0x800042A8
    // 0x8004D868: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800042A8(rdram, ctx);
        goto after_3;
    // 0x8004D868: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x8004D86C: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x8004D870: lh          $t5, -0x662C($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X662C);
    // 0x8004D874: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x8004D878: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004D87C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8004D880: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x8004D884: lw          $a0, -0x64D4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X64D4);
    // 0x8004D888: sw          $zero, -0x49DC($at)
    MEM_W(-0X49DC, ctx->r1) = 0;
    // 0x8004D88C: beql        $a0, $zero, L_8004D940
    if (ctx->r4 == 0) {
        // 0x8004D890: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8004D940;
    }
    goto skip_0;
    // 0x8004D890: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x8004D894: jal         0x80049CFC
    // 0x8004D898: nop

    func_80049CFC(rdram, ctx);
        goto after_4;
    // 0x8004D898: nop

    after_4:
    // 0x8004D89C: jal         0x80049D80
    // 0x8004D8A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80049D80(rdram, ctx);
        goto after_5;
    // 0x8004D8A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x8004D8A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8004D8A8: jal         0x80049DFC
    // 0x8004D8AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80049DFC(rdram, ctx);
        goto after_6;
    // 0x8004D8AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8004D8B0: sw          $v0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r2;
    // 0x8004D8B4: jal         0x8004A148
    // 0x8004D8B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8004A148(rdram, ctx);
        goto after_7;
    // 0x8004D8B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x8004D8BC: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8004D8C0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004D8C4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8004D8C8: lw          $t7, -0x6630($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6630);
    // 0x8004D8CC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8004D8D0: addiu       $s0, $sp, 0x98
    ctx->r16 = ADD32(ctx->r29, 0X98);
    // 0x8004D8D4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8004D8D8: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8004D8DC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8004D8E0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8004D8E4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8004D8E8: lwc1        $f20, -0x648C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X648C);
    // 0x8004D8EC: jal         0x80001AB4
    // 0x8004D8F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80001AB4(rdram, ctx);
        goto after_8;
    // 0x8004D8F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8004D8F4: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    // 0x8004D8F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004D8FC: lw          $a0, 0x8($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X8);
    // 0x8004D900: jal         0x80002340
    // 0x8004D904: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80002340(rdram, ctx);
        goto after_9;
    // 0x8004D904: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_9:
    // 0x8004D908: lw          $t1, 0x90($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X90);
    // 0x8004D90C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004D910: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x8004D914: swc1        $f0, 0x40($t2)
    MEM_W(0X40, ctx->r10) = ctx->f0.u32l;
    // 0x8004D918: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x8004D91C: swc1        $f20, 0x44($t3)
    MEM_W(0X44, ctx->r11) = ctx->f20.u32l;
    // 0x8004D920: lw          $t4, 0x8($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X8);
    // 0x8004D924: swc1        $f0, 0x48($t4)
    MEM_W(0X48, ctx->r12) = ctx->f0.u32l;
    // 0x8004D928: lw          $v0, 0x8($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X8);
    // 0x8004D92C: lw          $t5, 0xD8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XD8);
    // 0x8004D930: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x8004D934: b           L_8004D944
    // 0x8004D938: sw          $t6, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r14;
        goto L_8004D944;
    // 0x8004D938: sw          $t6, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r14;
    // 0x8004D93C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_8004D940:
    // 0x8004D940: sw          $zero, 0x90($sp)
    MEM_W(0X90, ctx->r29) = 0;
L_8004D944:
    // 0x8004D944: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004D948: sw          $zero, -0x49D4($at)
    MEM_W(-0X49D4, ctx->r1) = 0;
    // 0x8004D94C: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x8004D950: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8004D954: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x8004D958: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8004D95C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8004D960: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8004D964: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8004D968: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x8004D96C: addiu       $s1, $s1, -0x49D0
    ctx->r17 = ADD32(ctx->r17, -0X49D0);
    // 0x8004D970: addiu       $s2, $s2, -0x6C20
    ctx->r18 = ADD32(ctx->r18, -0X6C20);
    // 0x8004D974: addiu       $s0, $zero, -0x2
    ctx->r16 = ADD32(0, -0X2);
    // 0x8004D978: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
L_8004D97C:
    // 0x8004D97C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004D980: bne         $v0, $at, L_8004DA64
    if (ctx->r2 != ctx->r1) {
        // 0x8004D984: lui         $t7, 0x8013
        ctx->r15 = S32(0X8013 << 16);
            goto L_8004DA64;
    }
    // 0x8004D984: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8004D988: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8004D98C: lw          $t8, -0x49E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X49E8);
    // 0x8004D990: lw          $t7, -0x49EC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X49EC);
    // 0x8004D994: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x8004D998: addiu       $s5, $s5, -0x49F4
    ctx->r21 = ADD32(ctx->r21, -0X49F4);
    // 0x8004D99C: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004D9A0: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8004D9A4: lw          $s0, 0x0($s5)
    ctx->r16 = MEM_W(ctx->r21, 0X0);
    // 0x8004D9A8: addiu       $s2, $s2, -0x6C60
    ctx->r18 = ADD32(ctx->r18, -0X6C60);
    // 0x8004D9AC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8004D9B0: mflo        $t9
    ctx->r25 = lo;
    // 0x8004D9B4: blez        $t9, L_8004DA0C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8004D9B8: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_8004DA0C;
    }
    // 0x8004D9B8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_8004D9BC:
    // 0x8004D9BC: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8004D9C0: jal         0x8001026C
    // 0x8004D9C4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_8001026C(rdram, ctx);
        goto after_10;
    // 0x8004D9C4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_10:
    // 0x8004D9C8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8004D9CC: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x8004D9D0: jal         0x8001026C
    // 0x8004D9D4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_8001026C(rdram, ctx);
        goto after_11;
    // 0x8004D9D4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_11:
    // 0x8004D9D8: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x8004D9DC: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8004D9E0: lw          $t1, -0x49E8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X49E8);
    // 0x8004D9E4: lw          $t4, -0x49EC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X49EC);
    // 0x8004D9E8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8004D9EC: sll         $t2, $s1, 16
    ctx->r10 = S32(ctx->r17 << 16);
    // 0x8004D9F0: multu       $t4, $t1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004D9F4: sra         $s1, $t2, 16
    ctx->r17 = S32(SIGNED(ctx->r10) >> 16);
    // 0x8004D9F8: addiu       $s0, $s0, 0x48
    ctx->r16 = ADD32(ctx->r16, 0X48);
    // 0x8004D9FC: mflo        $t5
    ctx->r13 = lo;
    // 0x8004DA00: slt         $at, $s1, $t5
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8004DA04: bnel        $at, $zero, L_8004D9BC
    if (ctx->r1 != 0) {
        // 0x8004DA08: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_8004D9BC;
    }
    goto skip_1;
    // 0x8004DA08: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_1:
L_8004DA0C:
    // 0x8004DA0C: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8004DA10: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8004DA14: addiu       $a2, $s2, -0x6C60
    ctx->r6 = ADD32(ctx->r18, -0X6C60);
    // 0x8004DA18: lw          $a1, -0x49F0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X49F0);
    // 0x8004DA1C: jal         0x8001026C
    // 0x8004DA20: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_8001026C(rdram, ctx);
        goto after_12;
    // 0x8004DA20: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_12:
    // 0x8004DA24: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8004DA28: jal         0x800042A8
    // 0x8004DA2C: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
    func_800042A8(rdram, ctx);
        goto after_13;
    // 0x8004DA2C: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
    after_13:
    // 0x8004DA30: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8004DA34: jal         0x8004A0C4
    // 0x8004DA38: lw          $a0, -0x49D8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X49D8);
    func_8004A0C4(rdram, ctx);
        goto after_14;
    // 0x8004DA38: lw          $a0, -0x49D8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X49D8);
    after_14:
    // 0x8004DA3C: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    // 0x8004DA40: beql        $t6, $zero, L_8004DA54
    if (ctx->r14 == 0) {
        // 0x8004DA44: sw          $zero, 0x0($s3)
        MEM_W(0X0, ctx->r19) = 0;
            goto L_8004DA54;
    }
    goto skip_2;
    // 0x8004DA44: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
    skip_2:
    // 0x8004DA48: jal         0x8004A0C4
    // 0x8004DA4C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_8004A0C4(rdram, ctx);
        goto after_15;
    // 0x8004DA4C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_15:
    // 0x8004DA50: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
L_8004DA54:
    // 0x8004DA54: jal         0x8000798C
    // 0x8004DA58: nop

    func_8000798C(rdram, ctx);
        goto after_16;
    // 0x8004DA58: nop

    after_16:
    // 0x8004DA5C: b           L_8004DA54
    // 0x8004DA60: nop

        goto L_8004DA54;
    // 0x8004DA60: nop

L_8004DA64:
    // 0x8004DA64: bne         $s0, $v0, L_8004DA88
    if (ctx->r16 != ctx->r2) {
        // 0x8004DA68: nop
    
            goto L_8004DA88;
    }
    // 0x8004DA68: nop

    // 0x8004DA6C: bne         $s0, $v0, L_8004DA88
    if (ctx->r16 != ctx->r2) {
        // 0x8004DA70: nop
    
            goto L_8004DA88;
    }
    // 0x8004DA70: nop

L_8004DA74:
    // 0x8004DA74: jal         0x8000798C
    // 0x8004DA78: nop

    func_8000798C(rdram, ctx);
        goto after_17;
    // 0x8004DA78: nop

    after_17:
    // 0x8004DA7C: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x8004DA80: beq         $s0, $t7, L_8004DA74
    if (ctx->r16 == ctx->r15) {
        // 0x8004DA84: nop
    
            goto L_8004DA74;
    }
    // 0x8004DA84: nop

L_8004DA88:
    // 0x8004DA88: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004DA8C: lw          $v1, -0x49D4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X49D4);
    // 0x8004DA90: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004DA94: beq         $v1, $zero, L_8004DB7C
    if (ctx->r3 == 0) {
        // 0x8004DA98: nop
    
            goto L_8004DB7C;
    }
    // 0x8004DA98: nop

    // 0x8004DA9C: beq         $v1, $at, L_8004DAB4
    if (ctx->r3 == ctx->r1) {
        // 0x8004DAA0: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_8004DAB4;
    }
    // 0x8004DAA0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004DAA4: beql        $v1, $at, L_8004DB64
    if (ctx->r3 == ctx->r1) {
        // 0x8004DAA8: lw          $v0, 0x0($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X0);
            goto L_8004DB64;
    }
    goto skip_3;
    // 0x8004DAA8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    skip_3:
    // 0x8004DAAC: b           L_8004DB70
    // 0x8004DAB0: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
        goto L_8004DB70;
    // 0x8004DAB0: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
L_8004DAB4:
    // 0x8004DAB4: lwc1        $f4, 0x0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8004DAB8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004DABC: lwc1        $f0, 0x4($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8004DAC0: sub.s       $f20, $f4, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f26.fl;
    // 0x8004DAC4: c.lt.s      $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f6.fl < ctx->f20.fl;
    // 0x8004DAC8: nop

    // 0x8004DACC: bc1fl       L_8004DB54
    if (!c1cs) {
        // 0x8004DAD0: lw          $v0, 0x0($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X0);
            goto L_8004DB54;
    }
    goto skip_4;
    // 0x8004DAD0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    skip_4:
    // 0x8004DAD4: c.lt.s      $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl < ctx->f26.fl;
    // 0x8004DAD8: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x8004DADC: bc1fl       L_8004DB54
    if (!c1cs) {
        // 0x8004DAE0: lw          $v0, 0x0($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X0);
            goto L_8004DB54;
    }
    goto skip_5;
    // 0x8004DAE0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    skip_5:
    // 0x8004DAE4: c.lt.s      $f28, $f20
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f28.fl < ctx->f20.fl;
    // 0x8004DAE8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004DAEC: bc1fl       L_8004DAFC
    if (!c1cs) {
        // 0x8004DAF0: lw          $t8, 0x0($s5)
        ctx->r24 = MEM_W(ctx->r21, 0X0);
            goto L_8004DAFC;
    }
    goto skip_6;
    // 0x8004DAF0: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    skip_6:
    // 0x8004DAF4: mov.s       $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    ctx->f20.fl = ctx->f28.fl;
    // 0x8004DAF8: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
L_8004DAFC:
    // 0x8004DAFC: mul.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x8004DB00: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8004DB04: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8004DB08: lwc1        $f18, -0x6FE4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X6FE4);
    // 0x8004DB0C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8004DB10: mul.s       $f20, $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f16.fl);
    // 0x8004DB14: nop

    // 0x8004DB18: mul.s       $f22, $f0, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8004DB1C: jal         0x8004F7C0
    // 0x8004DB20: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_8004F7C0(rdram, ctx);
        goto after_18;
    // 0x8004DB20: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_18:
    // 0x8004DB24: mul.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8004DB28: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8004DB2C: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x8004DB30: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8004DB34: jal         0x8004F650
    // 0x8004DB38: add.s       $f24, $f4, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f4.fl + ctx->f6.fl;
    func_8004F650(rdram, ctx);
        goto after_19;
    // 0x8004DB38: add.s       $f24, $f4, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f4.fl + ctx->f6.fl;
    after_19:
    // 0x8004DB3C: mul.s       $f8, $f0, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8004DB40: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x8004DB44: lwc1        $f10, 0x8($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X8);
    // 0x8004DB48: b           L_8004DB6C
    // 0x8004DB4C: add.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f8.fl + ctx->f10.fl;
        goto L_8004DB6C;
    // 0x8004DB4C: add.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8004DB50: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_8004DB54:
    // 0x8004DB54: lwc1        $f24, 0x0($v0)
    ctx->f24.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8004DB58: b           L_8004DB6C
    // 0x8004DB5C: lwc1        $f22, 0x8($v0)
    ctx->f22.u32l = MEM_W(ctx->r2, 0X8);
        goto L_8004DB6C;
    // 0x8004DB5C: lwc1        $f22, 0x8($v0)
    ctx->f22.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8004DB60: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_8004DB64:
    // 0x8004DB64: lwc1        $f24, 0x0($v0)
    ctx->f24.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8004DB68: lwc1        $f22, 0x8($v0)
    ctx->f22.u32l = MEM_W(ctx->r2, 0X8);
L_8004DB6C:
    // 0x8004DB6C: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
L_8004DB70:
    // 0x8004DB70: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x8004DB74: jal         0x8004E2A4
    // 0x8004DB78: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_8004E2A4(rdram, ctx);
        goto after_20;
    // 0x8004DB78: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_20:
L_8004DB7C:
    // 0x8004DB7C: jal         0x8000798C
    // 0x8004DB80: nop

    func_8000798C(rdram, ctx);
        goto after_21;
    // 0x8004DB80: nop

    after_21:
    // 0x8004DB84: b           L_8004D97C
    // 0x8004DB88: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
        goto L_8004D97C;
    // 0x8004DB88: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8004DB8C: nop

    // 0x8004DB90: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8004DB94: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8004DB98: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8004DB9C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8004DBA0: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8004DBA4: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x8004DBA8: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x8004DBAC: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x8004DBB0: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x8004DBB4: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x8004DBB8: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x8004DBBC: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x8004DBC0: jr          $ra
    // 0x8004DBC4: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    TRACE_RETURN()
    return;
    // 0x8004DBC4: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
;}
RECOMP_FUNC void func_8004DBC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004DBC8: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x8004DBCC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8004DBD0: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8004DBD4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8004DBD8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8004DBDC: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x8004DBE0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8004DBE4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8004DBE8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8004DBEC: subu        $s0, $a3, $a2
    ctx->r16 = SUB32(ctx->r7, ctx->r6);
    // 0x8004DBF0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004DBF4: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8004DBF8: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x8004DBFC: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8004DC00: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8004DC04: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8004DC08: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8004DC0C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8004DC10: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8004DC14: jal         0x80004364
    // 0x8004DC18: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x8004DC18: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x8004DC1C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x8004DC20: addiu       $t2, $t2, -0x49F0
    ctx->r10 = ADD32(ctx->r10, -0X49F0);
    // 0x8004DC24: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // 0x8004DC28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004DC2C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8004DC30: bgez        $s0, L_8004DC40
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8004DC34: sra         $a3, $s0, 2
        ctx->r7 = S32(SIGNED(ctx->r16) >> 2);
            goto L_8004DC40;
    }
    // 0x8004DC34: sra         $a3, $s0, 2
    ctx->r7 = S32(SIGNED(ctx->r16) >> 2);
    // 0x8004DC38: addiu       $at, $s0, 0x3
    ctx->r1 = ADD32(ctx->r16, 0X3);
    // 0x8004DC3C: sra         $a3, $at, 2
    ctx->r7 = S32(SIGNED(ctx->r1) >> 2);
L_8004DC40:
    // 0x8004DC40: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8004DC44: blez        $a3, L_8004DC68
    if (SIGNED(ctx->r7) <= 0) {
        // 0x8004DC48: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8004DC68;
    }
    // 0x8004DC48: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8004DC4C:
    // 0x8004DC4C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8004DC50: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8004DC54: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8004DC58: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8004DC5C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8004DC60: bne         $at, $zero, L_8004DC4C
    if (ctx->r1 != 0) {
        // 0x8004DC64: sw          $t6, -0x4($a2)
        MEM_W(-0X4, ctx->r6) = ctx->r14;
            goto L_8004DC4C;
    }
    // 0x8004DC64: sw          $t6, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->r14;
L_8004DC68:
    // 0x8004DC68: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004DC6C: lui         $t1, 0x6964
    ctx->r9 = S32(0X6964 << 16);
    // 0x8004DC70: lui         $t0, 0x626C
    ctx->r8 = S32(0X626C << 16);
    // 0x8004DC74: lui         $a3, 0x626C
    ctx->r7 = S32(0X626C << 16);
    // 0x8004DC78: lui         $a1, 0x426C
    ctx->r5 = S32(0X426C << 16);
    // 0x8004DC7C: sw          $zero, -0x49E0($at)
    MEM_W(-0X49E0, ctx->r1) = 0;
    // 0x8004DC80: addiu       $a0, $s2, 0x8
    ctx->r4 = ADD32(ctx->r18, 0X8);
    // 0x8004DC84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004DC88: ori         $a1, $a1, 0x6B20
    ctx->r5 = ctx->r5 | 0X6B20;
    // 0x8004DC8C: ori         $a3, $a3, 0x6B78
    ctx->r7 = ctx->r7 | 0X6B78;
    // 0x8004DC90: ori         $t0, $t0, 0x6B79
    ctx->r8 = ctx->r8 | 0X6B79;
    // 0x8004DC94: ori         $t1, $t1, 0x7820
    ctx->r9 = ctx->r9 | 0X7820;
L_8004DC98:
    // 0x8004DC98: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8004DC9C: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x8004DCA0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8004DCA4: beq         $v0, $a1, L_8004DCF4
    if (ctx->r2 == ctx->r5) {
        // 0x8004DCA8: addu        $t3, $a0, $v1
        ctx->r11 = ADD32(ctx->r4, ctx->r3);
            goto L_8004DCF4;
    }
    // 0x8004DCA8: addu        $t3, $a0, $v1
    ctx->r11 = ADD32(ctx->r4, ctx->r3);
    // 0x8004DCAC: beql        $v0, $a3, L_8004DCD0
    if (ctx->r2 == ctx->r7) {
        // 0x8004DCB0: lw          $t7, 0x0($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X0);
            goto L_8004DCD0;
    }
    goto skip_0;
    // 0x8004DCB0: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x8004DCB4: beql        $v0, $t0, L_8004DCE0
    if (ctx->r2 == ctx->r8) {
        // 0x8004DCB8: lw          $t8, 0x0($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X0);
            goto L_8004DCE0;
    }
    goto skip_1;
    // 0x8004DCB8: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    skip_1:
    // 0x8004DCBC: beq         $v0, $t1, L_8004DCEC
    if (ctx->r2 == ctx->r9) {
        // 0x8004DCC0: nop
    
            goto L_8004DCEC;
    }
    // 0x8004DCC0: nop

    // 0x8004DCC4: b           L_8004DCF8
    // 0x8004DCC8: nop

        goto L_8004DCF8;
    // 0x8004DCC8: nop

    // 0x8004DCCC: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
L_8004DCD0:
    // 0x8004DCD0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004DCD4: b           L_8004DCF8
    // 0x8004DCD8: sw          $t7, -0x49EC($at)
    MEM_W(-0X49EC, ctx->r1) = ctx->r15;
        goto L_8004DCF8;
    // 0x8004DCD8: sw          $t7, -0x49EC($at)
    MEM_W(-0X49EC, ctx->r1) = ctx->r15;
    // 0x8004DCDC: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
L_8004DCE0:
    // 0x8004DCE0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004DCE4: b           L_8004DCF8
    // 0x8004DCE8: sw          $t8, -0x49E8($at)
    MEM_W(-0X49E8, ctx->r1) = ctx->r24;
        goto L_8004DCF8;
    // 0x8004DCE8: sw          $t8, -0x49E8($at)
    MEM_W(-0X49E8, ctx->r1) = ctx->r24;
L_8004DCEC:
    // 0x8004DCEC: b           L_8004DCF8
    // 0x8004DCF0: sw          $a0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r4;
        goto L_8004DCF8;
    // 0x8004DCF0: sw          $a0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r4;
L_8004DCF4:
    // 0x8004DCF4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
L_8004DCF8:
    // 0x8004DCF8: beq         $a2, $zero, L_8004DC98
    if (ctx->r6 == 0) {
        // 0x8004DCFC: or          $a0, $t3, $zero
        ctx->r4 = ctx->r11 | 0;
            goto L_8004DC98;
    }
    // 0x8004DCFC: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x8004DD00: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8004DD04: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x8004DD08: lw          $t4, -0x49E8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X49E8);
    // 0x8004DD0C: lw          $t9, -0x49EC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X49EC);
    // 0x8004DD10: lw          $t6, 0xE0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE0);
    // 0x8004DD14: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004DD18: multu       $t9, $t4
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004DD1C: addiu       $v0, $v0, -0x49E4
    ctx->r2 = ADD32(ctx->r2, -0X49E4);
    // 0x8004DD20: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004DD24: sw          $s3, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r19;
    // 0x8004DD28: sw          $s4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r20;
    // 0x8004DD2C: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8004DD30: sw          $a2, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r6;
    // 0x8004DD34: sw          $t6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r14;
    // 0x8004DD38: mflo        $t5
    ctx->r13 = lo;
    // 0x8004DD3C: sll         $t7, $t5, 3
    ctx->r15 = S32(ctx->r13 << 3);
    // 0x8004DD40: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x8004DD44: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8004DD48: jal         0x80004364
    // 0x8004DD4C: sll         $a1, $t7, 3
    ctx->r5 = S32(ctx->r15 << 3);
    func_80004364(rdram, ctx);
        goto after_1;
    // 0x8004DD4C: sll         $a1, $t7, 3
    ctx->r5 = S32(ctx->r15 << 3);
    after_1:
    // 0x8004DD50: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8004DD54: lw          $a0, -0x49E8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X49E8);
    // 0x8004DD58: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004DD5C: sw          $v0, -0x49F4($at)
    MEM_W(-0X49F4, ctx->r1) = ctx->r2;
    // 0x8004DD60: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8004DD64: blez        $a0, L_8004E150
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8004DD68: sw          $zero, 0xA0($sp)
        MEM_W(0XA0, ctx->r29) = 0;
            goto L_8004E150;
    }
    // 0x8004DD68: sw          $zero, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = 0;
    // 0x8004DD6C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8004DD70: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004DD74: addiu       $s1, $sp, 0x7C
    ctx->r17 = ADD32(ctx->r29, 0X7C);
    // 0x8004DD78: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8004DD7C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8004DD80: addiu       $s2, $s2, -0x49CC
    ctx->r18 = ADD32(ctx->r18, -0X49CC);
    // 0x8004DD84: or          $s3, $s1, $zero
    ctx->r19 = ctx->r17 | 0;
    // 0x8004DD88: lw          $v1, -0x49EC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X49EC);
    // 0x8004DD8C: addiu       $s7, $zero, 0xFF
    ctx->r23 = ADD32(0, 0XFF);
    // 0x8004DD90: lh          $s6, 0x8A($sp)
    ctx->r22 = MEM_H(ctx->r29, 0X8A);
    // 0x8004DD94: lh          $s5, 0x8C($sp)
    ctx->r21 = MEM_H(ctx->r29, 0X8C);
    // 0x8004DD98: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
L_8004DD9C:
    // 0x8004DD9C: blez        $v1, L_8004E134
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8004DDA0: sw          $zero, 0xA4($sp)
        MEM_W(0XA4, ctx->r29) = 0;
            goto L_8004E134;
    }
    // 0x8004DDA0: sw          $zero, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = 0;
L_8004DDA4:
    // 0x8004DDA4: lw          $t9, 0x94($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X94);
    // 0x8004DDA8: lw          $a1, 0x90($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X90);
    // 0x8004DDAC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004DDB0: lbu         $t4, 0x0($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X0);
    // 0x8004DDB4: addiu       $v1, $v1, -0x49E0
    ctx->r3 = ADD32(ctx->r3, -0X49E0);
    // 0x8004DDB8: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x8004DDBC: sh          $t4, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r12;
    // 0x8004DDC0: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x8004DDC4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8004DDC8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8004DDCC: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8004DDD0: sw          $t6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r14;
    // 0x8004DDD4: lbu         $t7, -0x1($a1)
    ctx->r15 = MEM_BU(ctx->r5, -0X1);
    // 0x8004DDD8: lh          $v0, 0x3C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X3C);
    // 0x8004DDDC: sb          $t7, 0x44($s0)
    MEM_B(0X44, ctx->r16) = ctx->r15;
    // 0x8004DDE0: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8004DDE4: slt         $at, $t8, $v0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8004DDE8: beq         $at, $zero, L_8004DDF8
    if (ctx->r1 == 0) {
        // 0x8004DDEC: nop
    
            goto L_8004DDF8;
    }
    // 0x8004DDEC: nop

    // 0x8004DDF0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8004DDF4: lh          $v0, 0x3C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X3C);
L_8004DDF8:
    // 0x8004DDF8: lw          $t9, -0x49F0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X49F0);
    // 0x8004DDFC: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x8004DE00: subu        $t4, $t4, $v0
    ctx->r12 = SUB32(ctx->r12, ctx->r2);
    // 0x8004DE04: lw          $a0, 0x98($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X98);
    // 0x8004DE08: sll         $t4, $t4, 9
    ctx->r12 = S32(ctx->r12 << 9);
    // 0x8004DE0C: addu        $t5, $t9, $t4
    ctx->r13 = ADD32(ctx->r25, ctx->r12);
    // 0x8004DE10: sw          $t5, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r13;
    // 0x8004DE14: lh          $v1, 0x0($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X0);
    // 0x8004DE18: lw          $t6, 0xB4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB4);
    // 0x8004DE1C: lw          $t4, 0xB8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB8);
    // 0x8004DE20: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8004DE24: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8004DE28: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8004DE2C: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8004DE30: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    // 0x8004DE34: sw          $a1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r5;
    // 0x8004DE38: addu        $a2, $t4, $t9
    ctx->r6 = ADD32(ctx->r12, ctx->r25);
L_8004DE3C:
    // 0x8004DE3C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8004DE40: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x8004DE44: lui         $at, 0x7472
    ctx->r1 = S32(0X7472 << 16);
    // 0x8004DE48: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8004DE4C: ori         $at, $at, 0x6920
    ctx->r1 = ctx->r1 | 0X6920;
    // 0x8004DE50: beq         $v0, $at, L_8004E0B0
    if (ctx->r2 == ctx->r1) {
        // 0x8004DE54: addu        $t3, $a2, $v1
        ctx->r11 = ADD32(ctx->r6, ctx->r3);
            goto L_8004E0B0;
    }
    // 0x8004DE54: addu        $t3, $a2, $v1
    ctx->r11 = ADD32(ctx->r6, ctx->r3);
    // 0x8004DE58: lui         $at, 0x7472
    ctx->r1 = S32(0X7472 << 16);
    // 0x8004DE5C: ori         $at, $at, 0x696E
    ctx->r1 = ctx->r1 | 0X696E;
    // 0x8004DE60: beq         $v0, $at, L_8004DEAC
    if (ctx->r2 == ctx->r1) {
        // 0x8004DE64: lui         $at, 0x7674
        ctx->r1 = S32(0X7674 << 16);
            goto L_8004DEAC;
    }
    // 0x8004DE64: lui         $at, 0x7674
    ctx->r1 = S32(0X7674 << 16);
    // 0x8004DE68: ori         $at, $at, 0x7832
    ctx->r1 = ctx->r1 | 0X7832;
    // 0x8004DE6C: beq         $v0, $at, L_8004DED8
    if (ctx->r2 == ctx->r1) {
        // 0x8004DE70: lw          $t5, 0xA4($sp)
        ctx->r13 = MEM_W(ctx->r29, 0XA4);
            goto L_8004DED8;
    }
    // 0x8004DE70: lw          $t5, 0xA4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA4);
    // 0x8004DE74: lui         $at, 0x7674
    ctx->r1 = S32(0X7674 << 16);
    // 0x8004DE78: ori         $at, $at, 0x786E
    ctx->r1 = ctx->r1 | 0X786E;
    // 0x8004DE7C: bne         $v0, $at, L_8004E104
    if (ctx->r2 != ctx->r1) {
        // 0x8004DE80: nop
    
            goto L_8004E104;
    }
    // 0x8004DE80: nop

    // 0x8004DE84: lh          $s5, 0x2($a2)
    ctx->r21 = MEM_H(ctx->r6, 0X2);
    // 0x8004DE88: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004DE8C: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8004DE90: sh          $s5, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r21;
    // 0x8004DE94: sw          $t3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r11;
    // 0x8004DE98: jal         0x80004364
    // 0x8004DE9C: sll         $a1, $s5, 4
    ctx->r5 = S32(ctx->r21 << 4);
    func_80004364(rdram, ctx);
        goto after_2;
    // 0x8004DE9C: sll         $a1, $s5, 4
    ctx->r5 = S32(ctx->r21 << 4);
    after_2:
    // 0x8004DEA0: lw          $t3, 0xBC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XBC);
    // 0x8004DEA4: b           L_8004E104
    // 0x8004DEA8: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
        goto L_8004E104;
    // 0x8004DEA8: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
L_8004DEAC:
    // 0x8004DEAC: lh          $s6, 0x2($a2)
    ctx->r22 = MEM_H(ctx->r6, 0X2);
    // 0x8004DEB0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004DEB4: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8004DEB8: sh          $s6, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r22;
    // 0x8004DEBC: sll         $a1, $s6, 2
    ctx->r5 = S32(ctx->r22 << 2);
    // 0x8004DEC0: sw          $t3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r11;
    // 0x8004DEC4: jal         0x80004364
    // 0x8004DEC8: subu        $a1, $a1, $s6
    ctx->r5 = SUB32(ctx->r5, ctx->r22);
    func_80004364(rdram, ctx);
        goto after_3;
    // 0x8004DEC8: subu        $a1, $a1, $s6
    ctx->r5 = SUB32(ctx->r5, ctx->r22);
    after_3:
    // 0x8004DECC: lw          $t3, 0xBC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XBC);
    // 0x8004DED0: b           L_8004E104
    // 0x8004DED4: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
        goto L_8004E104;
    // 0x8004DED4: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
L_8004DED8:
    // 0x8004DED8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8004DEDC: lw          $t6, -0x49EC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X49EC);
    // 0x8004DEE0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8004DEE4: lw          $t9, -0x49E8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X49E8);
    // 0x8004DEE8: bgez        $t6, L_8004DEF8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8004DEEC: sra         $t7, $t6, 1
        ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
            goto L_8004DEF8;
    }
    // 0x8004DEEC: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8004DEF0: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x8004DEF4: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_8004DEF8:
    // 0x8004DEF8: lw          $t4, 0xA0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA0);
    // 0x8004DEFC: subu        $t8, $t5, $t7
    ctx->r24 = SUB32(ctx->r13, ctx->r15);
    // 0x8004DF00: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8004DF04: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8004DF08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004DF0C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8004DF10: bgez        $t9, L_8004DF20
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8004DF14: sra         $t6, $t9, 1
        ctx->r14 = S32(SIGNED(ctx->r25) >> 1);
            goto L_8004DF20;
    }
    // 0x8004DF14: sra         $t6, $t9, 1
    ctx->r14 = S32(SIGNED(ctx->r25) >> 1);
    // 0x8004DF18: addiu       $at, $t9, 0x1
    ctx->r1 = ADD32(ctx->r25, 0X1);
    // 0x8004DF1C: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_8004DF20:
    // 0x8004DF20: subu        $t5, $t4, $t6
    ctx->r13 = SUB32(ctx->r12, ctx->r14);
    // 0x8004DF24: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x8004DF28: blez        $s5, L_8004E104
    if (SIGNED(ctx->r21) <= 0) {
        // 0x8004DF2C: cvt.s.w     $f2, $f6
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8004E104;
    }
    // 0x8004DF2C: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8004DF30: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_8004DF34:
    // 0x8004DF34: addiu       $v0, $sp, 0x70
    ctx->r2 = ADD32(ctx->r29, 0X70);
    // 0x8004DF38: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8004DF3C: sltu        $at, $v0, $s1
    ctx->r1 = ctx->r2 < ctx->r17 ? 1 : 0;
    // 0x8004DF40: beq         $at, $zero, L_8004DF6C
    if (ctx->r1 == 0) {
        // 0x8004DF44: lh          $t7, 0x0($a2)
        ctx->r15 = MEM_H(ctx->r6, 0X0);
            goto L_8004DF6C;
    }
    // 0x8004DF44: lh          $t7, 0x0($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X0);
L_8004DF48:
    // 0x8004DF48: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8004DF4C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8004DF50: sltu        $at, $v0, $s1
    ctx->r1 = ctx->r2 < ctx->r17 ? 1 : 0;
    // 0x8004DF54: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8004DF58: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x8004DF5C: div.s       $f18, $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = DIV_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8004DF60: swc1        $f18, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f18.u32l;
    // 0x8004DF64: bne         $at, $zero, L_8004DF48
    if (ctx->r1 != 0) {
        // 0x8004DF68: lh          $t7, 0x0($a2)
        ctx->r15 = MEM_H(ctx->r6, 0X0);
            goto L_8004DF48;
    }
    // 0x8004DF68: lh          $t7, 0x0($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X0);
L_8004DF6C:
    // 0x8004DF6C: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8004DF70: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x8004DF74: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8004DF78: div.s       $f18, $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = DIV_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8004DF7C: swc1        $f18, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f18.u32l;
    // 0x8004DF80: lwc1        $f18, 0x70($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8004DF84: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8004DF88: addiu       $v0, $sp, 0x70
    ctx->r2 = ADD32(ctx->r29, 0X70);
    // 0x8004DF8C: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x8004DF90: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8004DF94: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8004DF98: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8004DF9C: swc1        $f4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f4.u32l;
    // 0x8004DFA0: swc1        $f8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f8.u32l;
L_8004DFA4:
    // 0x8004DFA4: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x8004DFA8: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8004DFAC: sll         $t5, $a1, 4
    ctx->r13 = S32(ctx->r5 << 4);
    // 0x8004DFB0: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8004DFB4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8004DFB8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8004DFBC: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8004DFC0: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x8004DFC4: lwc1        $f6, -0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0X4);
    // 0x8004DFC8: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x8004DFCC: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8004DFD0: addu        $t7, $t6, $t5
    ctx->r15 = ADD32(ctx->r14, ctx->r13);
    // 0x8004DFD4: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8004DFD8: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8004DFDC: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x8004DFE0: slti        $at, $v1, 0x6
    ctx->r1 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // 0x8004DFE4: bne         $at, $zero, L_8004DFA4
    if (ctx->r1 != 0) {
        // 0x8004DFE8: sh          $t4, 0x0($t8)
        MEM_H(0X0, ctx->r24) = ctx->r12;
            goto L_8004DFA4;
    }
    // 0x8004DFE8: sh          $t4, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r12;
    // 0x8004DFEC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8004DFF0:
    // 0x8004DFF0: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x8004DFF4: sll         $t5, $a1, 4
    ctx->r13 = S32(ctx->r5 << 4);
    // 0x8004DFF8: lh          $t9, 0x0($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X0);
    // 0x8004DFFC: addu        $t7, $t6, $t5
    ctx->r15 = ADD32(ctx->r14, ctx->r13);
    // 0x8004E000: addu        $t4, $t7, $v1
    ctx->r12 = ADD32(ctx->r15, ctx->r3);
    // 0x8004E004: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8004E008: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x8004E00C: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x8004E010: bne         $at, $zero, L_8004DFF0
    if (ctx->r1 != 0) {
        // 0x8004E014: sh          $t9, 0x8($t4)
        MEM_H(0X8, ctx->r12) = ctx->r25;
            goto L_8004DFF0;
    }
    // 0x8004E014: sh          $t9, 0x8($t4)
    MEM_H(0X8, ctx->r12) = ctx->r25;
L_8004E018:
    // 0x8004E018: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x8004E01C: sll         $t5, $a1, 4
    ctx->r13 = S32(ctx->r5 << 4);
    // 0x8004E020: lbu         $t8, 0x0($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X0);
    // 0x8004E024: addu        $t7, $t6, $t5
    ctx->r15 = ADD32(ctx->r14, ctx->r13);
    // 0x8004E028: addu        $t9, $t7, $a0
    ctx->r25 = ADD32(ctx->r15, ctx->r4);
    // 0x8004E02C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8004E030: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x8004E034: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8004E038: bne         $at, $zero, L_8004E018
    if (ctx->r1 != 0) {
        // 0x8004E03C: sb          $t8, 0xC($t9)
        MEM_B(0XC, ctx->r25) = ctx->r24;
            goto L_8004E018;
    }
    // 0x8004E03C: sb          $t8, 0xC($t9)
    MEM_B(0XC, ctx->r25) = ctx->r24;
    // 0x8004E040: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x8004E044: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8004E048: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8004E04C: addu        $t6, $t4, $t1
    ctx->r14 = ADD32(ctx->r12, ctx->r9);
    // 0x8004E050: sb          $s7, 0xF($t6)
    MEM_B(0XF, ctx->r14) = ctx->r23;
    // 0x8004E054: lbu         $t0, -0x1($a2)
    ctx->r8 = MEM_BU(ctx->r6, -0X1);
    // 0x8004E058: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8004E05C: addiu       $v0, $sp, 0x70
    ctx->r2 = ADD32(ctx->r29, 0X70);
    // 0x8004E060: andi        $t5, $t0, 0x80
    ctx->r13 = ctx->r8 & 0X80;
    // 0x8004E064: beq         $t5, $zero, L_8004E0A0
    if (ctx->r13 == 0) {
        // 0x8004E068: andi        $t7, $t0, 0x3
        ctx->r15 = ctx->r8 & 0X3;
            goto L_8004E0A0;
    }
    // 0x8004E068: andi        $t7, $t0, 0x3
    ctx->r15 = ctx->r8 & 0X3;
    // 0x8004E06C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8004E070: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8004E074: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8004E078: addu        $a3, $s0, $t8
    ctx->r7 = ADD32(ctx->r16, ctx->r24);
L_8004E07C:
    // 0x8004E07C: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8004E080: addu        $t9, $a3, $v1
    ctx->r25 = ADD32(ctx->r7, ctx->r3);
    // 0x8004E084: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8004E088: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8004E08C: bne         $v0, $s3, L_8004E07C
    if (ctx->r2 != ctx->r19) {
        // 0x8004E090: swc1        $f16, 0xC($t9)
        MEM_W(0XC, ctx->r25) = ctx->f16.u32l;
            goto L_8004E07C;
    }
    // 0x8004E090: swc1        $f16, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f16.u32l;
    // 0x8004E094: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8004E098: sll         $t4, $t2, 16
    ctx->r12 = S32(ctx->r10 << 16);
    // 0x8004E09C: sra         $t2, $t4, 16
    ctx->r10 = S32(SIGNED(ctx->r12) >> 16);
L_8004E0A0:
    // 0x8004E0A0: bne         $a1, $s5, L_8004DF34
    if (ctx->r5 != ctx->r21) {
        // 0x8004E0A4: addiu       $t1, $t1, 0x10
        ctx->r9 = ADD32(ctx->r9, 0X10);
            goto L_8004DF34;
    }
    // 0x8004E0A4: addiu       $t1, $t1, 0x10
    ctx->r9 = ADD32(ctx->r9, 0X10);
    // 0x8004E0A8: b           L_8004E104
    // 0x8004E0AC: nop

        goto L_8004E104;
    // 0x8004E0AC: nop

L_8004E0B0:
    // 0x8004E0B0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8004E0B4: blez        $s6, L_8004E104
    if (SIGNED(ctx->r22) <= 0) {
        // 0x8004E0B8: or          $fp, $zero, $zero
        ctx->r30 = 0 | 0;
            goto L_8004E104;
    }
    // 0x8004E0B8: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x8004E0BC: lh          $v0, 0x0($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X0);
L_8004E0C0:
    // 0x8004E0C0: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x8004E0C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8004E0C8:
    // 0x8004E0C8: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x8004E0CC: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x8004E0D0: subu        $t8, $t8, $v1
    ctx->r24 = SUB32(ctx->r24, ctx->r3);
    // 0x8004E0D4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8004E0D8: addu        $t4, $t9, $a1
    ctx->r12 = ADD32(ctx->r25, ctx->r5);
    // 0x8004E0DC: sra         $t6, $v0, 4
    ctx->r14 = S32(SIGNED(ctx->r2) >> 4);
    // 0x8004E0E0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8004E0E4: andi        $t5, $v0, 0xF
    ctx->r13 = ctx->r2 & 0XF;
    // 0x8004E0E8: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8004E0EC: sb          $t5, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r13;
    // 0x8004E0F0: bne         $a1, $s4, L_8004E0C8
    if (ctx->r5 != ctx->r20) {
        // 0x8004E0F4: sra         $v0, $t7, 16
        ctx->r2 = S32(SIGNED(ctx->r15) >> 16);
            goto L_8004E0C8;
    }
    // 0x8004E0F4: sra         $v0, $t7, 16
    ctx->r2 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8004E0F8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8004E0FC: bnel        $v1, $s6, L_8004E0C0
    if (ctx->r3 != ctx->r22) {
        // 0x8004E100: lh          $v0, 0x0($a2)
        ctx->r2 = MEM_H(ctx->r6, 0X0);
            goto L_8004E0C0;
    }
    goto skip_2;
    // 0x8004E100: lh          $v0, 0x0($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X0);
    skip_2:
L_8004E104:
    // 0x8004E104: bne         $fp, $zero, L_8004DE3C
    if (ctx->r30 != 0) {
        // 0x8004E108: or          $a2, $t3, $zero
        ctx->r6 = ctx->r11 | 0;
            goto L_8004DE3C;
    }
    // 0x8004E108: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x8004E10C: lw          $v0, 0xA4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA4);
    // 0x8004E110: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004E114: lw          $v1, -0x49EC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X49EC);
    // 0x8004E118: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004E11C: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x8004E120: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8004E124: bne         $at, $zero, L_8004DDA4
    if (ctx->r1 != 0) {
        // 0x8004E128: addiu       $s0, $s0, 0x48
        ctx->r16 = ADD32(ctx->r16, 0X48);
            goto L_8004DDA4;
    }
    // 0x8004E128: addiu       $s0, $s0, 0x48
    ctx->r16 = ADD32(ctx->r16, 0X48);
    // 0x8004E12C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8004E130: lw          $a0, -0x49E8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X49E8);
L_8004E134:
    // 0x8004E134: lw          $t9, 0xA0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA0);
    // 0x8004E138: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x8004E13C: slt         $at, $t5, $a0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8004E140: bne         $at, $zero, L_8004DD9C
    if (ctx->r1 != 0) {
        // 0x8004E144: sw          $t5, 0xA0($sp)
        MEM_W(0XA0, ctx->r29) = ctx->r13;
            goto L_8004DD9C;
    }
    // 0x8004E144: sw          $t5, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r13;
    // 0x8004E148: sh          $s6, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = ctx->r22;
    // 0x8004E14C: sh          $s5, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r21;
L_8004E150:
    // 0x8004E150: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x8004E154: lw          $t4, -0x49E0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X49E0);
    // 0x8004E158: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004E15C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004E160: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x8004E164: sw          $t6, -0x49E0($at)
    MEM_W(-0X49E0, ctx->r1) = ctx->r14;
    // 0x8004E168: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8004E16C: jal         0x80004364
    // 0x8004E170: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80004364(rdram, ctx);
        goto after_4;
    // 0x8004E170: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_4:
    // 0x8004E174: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8004E178: addiu       $s0, $s0, -0x49D8
    ctx->r16 = ADD32(ctx->r16, -0X49D8);
    // 0x8004E17C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8004E180: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8004E184: jal         0x8000C7C0
    // 0x8004E188: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_8000C7C0(rdram, ctx);
        goto after_5;
    // 0x8004E188: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_5:
    // 0x8004E18C: jal         0x8000F764
    // 0x8004E190: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_8000F764(rdram, ctx);
        goto after_6;
    // 0x8004E190: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_6:
    // 0x8004E194: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8004E198: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004E19C: addiu       $v1, $v1, -0x6C88
    ctx->r3 = ADD32(ctx->r3, -0X6C88);
    // 0x8004E1A0: sw          $v0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r2;
    // 0x8004E1A4: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8004E1A8: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8004E1AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8004E1B0: lw          $t4, 0xD4($t5)
    ctx->r12 = MEM_W(ctx->r13, 0XD4);
    // 0x8004E1B4: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x8004E1B8: lw          $t6, 0x4($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X4);
    // 0x8004E1BC: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8004E1C0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8004E1C4: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8004E1C8: lw          $t8, 0xD4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XD4);
    // 0x8004E1CC: lw          $t9, 0x8($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X8);
    // 0x8004E1D0: lw          $t5, 0x4($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X4);
    // 0x8004E1D4: sw          $t5, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r13;
    // 0x8004E1D8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8004E1DC: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8004E1E0: lw          $t7, 0xD4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XD4);
    // 0x8004E1E4: lw          $t4, 0x8($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X8);
    // 0x8004E1E8: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x8004E1EC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8004E1F0: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8004E1F4: lw          $t8, 0xD4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XD4);
    // 0x8004E1F8: lw          $t9, 0x8($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X8);
    // 0x8004E1FC: jal         0x8000F764
    // 0x8004E200: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    func_8000F764(rdram, ctx);
        goto after_7;
    // 0x8004E200: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    after_7:
    // 0x8004E204: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8004E208: sw          $v0, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r2;
    // 0x8004E20C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8004E210: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    // 0x8004E214: lw          $t4, 0xC($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XC);
    // 0x8004E218: lw          $t6, 0xD4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XD4);
    // 0x8004E21C: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8004E220: sw          $t4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r12;
    // 0x8004E224: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8004E228: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x8004E22C: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
    // 0x8004E230: lw          $t7, 0xD4($t8)
    ctx->r15 = MEM_W(ctx->r24, 0XD4);
    // 0x8004E234: lw          $t5, 0x4($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X4);
    // 0x8004E238: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x8004E23C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8004E240: lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X8);
    // 0x8004E244: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
    // 0x8004E248: lw          $t9, 0xD4($t4)
    ctx->r25 = MEM_W(ctx->r12, 0XD4);
    // 0x8004E24C: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x8004E250: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8004E254: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    // 0x8004E258: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x8004E25C: lw          $t6, 0xD4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XD4);
    // 0x8004E260: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x8004E264: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8004E268: lw          $t9, 0x8($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X8);
    // 0x8004E26C: sw          $zero, 0xDC($t9)
    MEM_W(0XDC, ctx->r25) = 0;
    // 0x8004E270: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8004E274: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8004E278: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8004E27C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8004E280: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8004E284: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8004E288: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8004E28C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8004E290: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8004E294: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8004E298: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8004E29C: jr          $ra
    // 0x8004E2A0: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    TRACE_RETURN()
    return;
    // 0x8004E2A0: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void func_8004E2A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004E2A4: addiu       $sp, $sp, -0x148
    ctx->r29 = ADD32(ctx->r29, -0X148);
    // 0x8004E2A8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8004E2AC: lw          $a1, -0x49DC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X49DC);
    // 0x8004E2B0: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8004E2B4: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8004E2B8: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8004E2BC: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8004E2C0: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8004E2C4: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8004E2C8: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8004E2CC: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8004E2D0: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8004E2D4: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8004E2D8: beq         $a1, $zero, L_8004E314
    if (ctx->r5 == 0) {
        // 0x8004E2DC: sw          $s0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r16;
            goto L_8004E314;
    }
    // 0x8004E2DC: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8004E2E0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004E2E4: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8004E2E8: addiu       $a2, $a2, -0x6C60
    ctx->r6 = ADD32(ctx->r6, -0X6C60);
    // 0x8004E2EC: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8004E2F0: sw          $s1, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r17;
    // 0x8004E2F4: swc1        $f12, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->f12.u32l;
    // 0x8004E2F8: jal         0x8001026C
    // 0x8004E2FC: swc1        $f14, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->f14.u32l;
    func_8001026C(rdram, ctx);
        goto after_0;
    // 0x8004E2FC: swc1        $f14, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x8004E300: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004E304: lwc1        $f12, 0x148($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X148);
    // 0x8004E308: lwc1        $f14, 0x14C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x8004E30C: sw          $zero, -0x49DC($at)
    MEM_W(-0X49DC, ctx->r1) = 0;
    // 0x8004E310: lw          $s1, 0x150($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X150);
L_8004E314:
    // 0x8004E314: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8004E318: lw          $t6, -0x49CC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X49CC);
    // 0x8004E31C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8004E320: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8004E324: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8004E328: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x8004E32C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x8004E330: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8004E334: addiu       $t2, $t2, -0x6C40
    ctx->r10 = ADD32(ctx->r10, -0X6C40);
    // 0x8004E338: addiu       $t1, $t1, -0x6C50
    ctx->r9 = ADD32(ctx->r9, -0X6C50);
    // 0x8004E33C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8004E340: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8004E344: div.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8004E348: div.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8004E34C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8004E350: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x8004E354: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8004E358: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x8004E35C: bc1fl       L_8004E36C
    if (!c1cs) {
        // 0x8004E360: c.lt.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
            goto L_8004E36C;
    }
    goto skip_0;
    // 0x8004E360: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    skip_0:
    // 0x8004E364: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8004E368: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
L_8004E36C:
    // 0x8004E36C: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x8004E370: bc1f        L_8004E37C
    if (!c1cs) {
        // 0x8004E374: nop
    
            goto L_8004E37C;
    }
    // 0x8004E374: nop

    // 0x8004E378: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_8004E37C:
    // 0x8004E37C: lw          $t9, -0x49EC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X49EC);
    // 0x8004E380: lw          $t8, -0x49E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X49E8);
    // 0x8004E384: multu       $s1, $s1
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004E388: subu        $t6, $t9, $s1
    ctx->r14 = SUB32(ctx->r25, ctx->r17);
    // 0x8004E38C: subu        $t9, $t8, $s1
    ctx->r25 = SUB32(ctx->r24, ctx->r17);
    // 0x8004E390: addiu       $t4, $t4, -0x6C30
    ctx->r12 = ADD32(ctx->r12, -0X6C30);
    // 0x8004E394: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x8004E398: addiu       $fp, $fp, 0x69C0
    ctx->r30 = ADD32(ctx->r30, 0X69C0);
    // 0x8004E39C: sw          $s1, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r17;
    // 0x8004E3A0: sw          $s1, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r17;
    // 0x8004E3A4: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8004E3A8: sw          $s1, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r17;
    // 0x8004E3AC: mflo        $t5
    ctx->r13 = lo;
    // 0x8004E3B0: sw          $t5, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r13;
    // 0x8004E3B4: bgez        $t6, L_8004E3C4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8004E3B8: sra         $t7, $t6, 1
        ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
            goto L_8004E3C4;
    }
    // 0x8004E3B8: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8004E3BC: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x8004E3C0: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_8004E3C4:
    // 0x8004E3C4: addu        $t3, $t7, $v1
    ctx->r11 = ADD32(ctx->r15, ctx->r3);
    // 0x8004E3C8: bgez        $t9, L_8004E3D8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8004E3CC: sra         $t6, $t9, 1
        ctx->r14 = S32(SIGNED(ctx->r25) >> 1);
            goto L_8004E3D8;
    }
    // 0x8004E3CC: sra         $t6, $t9, 1
    ctx->r14 = S32(SIGNED(ctx->r25) >> 1);
    // 0x8004E3D0: addiu       $at, $t9, 0x1
    ctx->r1 = ADD32(ctx->r25, 0X1);
    // 0x8004E3D4: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_8004E3D8:
    // 0x8004E3D8: addu        $s0, $t6, $t0
    ctx->r16 = ADD32(ctx->r14, ctx->r8);
    // 0x8004E3DC: bgez        $s1, L_8004E3EC
    if (SIGNED(ctx->r17) >= 0) {
        // 0x8004E3E0: sra         $v0, $s1, 1
        ctx->r2 = S32(SIGNED(ctx->r17) >> 1);
            goto L_8004E3EC;
    }
    // 0x8004E3E0: sra         $v0, $s1, 1
    ctx->r2 = S32(SIGNED(ctx->r17) >> 1);
    // 0x8004E3E4: addiu       $at, $s1, 0x1
    ctx->r1 = ADD32(ctx->r17, 0X1);
    // 0x8004E3E8: sra         $v0, $at, 1
    ctx->r2 = S32(SIGNED(ctx->r1) >> 1);
L_8004E3EC:
    // 0x8004E3EC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004E3F0: addu        $t7, $v0, $t3
    ctx->r15 = ADD32(ctx->r2, ctx->r11);
    // 0x8004E3F4: sw          $t7, -0x49FC($at)
    MEM_W(-0X49FC, ctx->r1) = ctx->r15;
    // 0x8004E3F8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004E3FC: addu        $t8, $v0, $s0
    ctx->r24 = ADD32(ctx->r2, ctx->r16);
    // 0x8004E400: sw          $t8, -0x49F8($at)
    MEM_W(-0X49F8, ctx->r1) = ctx->r24;
    // 0x8004E404: lwc1        $f0, 0x0($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8004E408: lwc1        $f8, 0x4($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X4);
    // 0x8004E40C: lwc1        $f6, 0x8($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X8);
    // 0x8004E410: lwc1        $f4, 0x4($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X4);
    // 0x8004E414: lwc1        $f18, 0x0($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8004E418: lw          $a3, 0x8($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X8);
    // 0x8004E41C: lw          $a2, 0x4($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X4);
    // 0x8004E420: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x8004E424: sw          $t3, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r11;
    // 0x8004E428: sw          $t5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r13;
    // 0x8004E42C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8004E430: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8004E434: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8004E438: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8004E43C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8004E440: jal         0x80055BB0
    // 0x8004E444: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_80055BB0(rdram, ctx);
        goto after_1;
    // 0x8004E444: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x8004E448: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x8004E44C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004E450: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8004E454: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8004E458: jal         0x80004364
    // 0x8004E45C: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    func_80004364(rdram, ctx);
        goto after_2;
    // 0x8004E45C: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_2:
    // 0x8004E460: lw          $t6, 0x150($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X150);
    // 0x8004E464: sw          $v0, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r2;
    // 0x8004E468: sw          $zero, 0x114($sp)
    MEM_W(0X114, ctx->r29) = 0;
    // 0x8004E46C: sw          $zero, 0x110($sp)
    MEM_W(0X110, ctx->r29) = 0;
    // 0x8004E470: sw          $zero, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = 0;
    // 0x8004E474: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8004E478: sw          $s0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r16;
    // 0x8004E47C: blez        $t6, L_8004E618
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8004E480: sw          $zero, 0x120($sp)
        MEM_W(0X120, ctx->r29) = 0;
            goto L_8004E618;
    }
    // 0x8004E480: sw          $zero, 0x120($sp)
    MEM_W(0X120, ctx->r29) = 0;
    // 0x8004E484: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x8004E488: addiu       $s4, $s4, 0x6A00
    ctx->r20 = ADD32(ctx->r20, 0X6A00);
    // 0x8004E48C: addiu       $s5, $zero, 0x30
    ctx->r21 = ADD32(0, 0X30);
    // 0x8004E490: lw          $v1, 0x138($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X138);
L_8004E494:
    // 0x8004E494: lw          $t7, 0xEC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XEC);
    // 0x8004E498: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8004E49C: bltzl       $t7, L_8004E5B0
    if (SIGNED(ctx->r15) < 0) {
        // 0x8004E4A0: lw          $t7, 0x150($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X150);
            goto L_8004E5B0;
    }
    goto skip_1;
    // 0x8004E4A0: lw          $t7, 0x150($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X150);
    skip_1:
    // 0x8004E4A4: lw          $t8, -0x49E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X49E8);
    // 0x8004E4A8: lw          $t9, 0x150($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X150);
    // 0x8004E4AC: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8004E4B0: beql        $at, $zero, L_8004E5B0
    if (ctx->r1 == 0) {
        // 0x8004E4B4: lw          $t7, 0x150($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X150);
            goto L_8004E5B0;
    }
    goto skip_2;
    // 0x8004E4B4: lw          $t7, 0x150($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X150);
    skip_2:
    // 0x8004E4B8: lw          $s6, 0x12C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X12C);
    // 0x8004E4BC: blez        $t9, L_8004E5F8
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8004E4C0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8004E5F8;
    }
    // 0x8004E4C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8004E4C4:
    // 0x8004E4C4: bltz        $s6, L_8004E590
    if (SIGNED(ctx->r22) < 0) {
        // 0x8004E4C8: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8004E590;
    }
    // 0x8004E4C8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004E4CC: lw          $v0, -0x49EC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X49EC);
    // 0x8004E4D0: slt         $at, $s6, $v0
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8004E4D4: beql        $at, $zero, L_8004E594
    if (ctx->r1 == 0) {
        // 0x8004E4D8: sw          $zero, 0x0($s2)
        MEM_W(0X0, ctx->r18) = 0;
            goto L_8004E594;
    }
    goto skip_3;
    // 0x8004E4D8: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    skip_3:
    // 0x8004E4DC: lw          $t6, 0xEC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XEC);
    // 0x8004E4E0: sw          $a0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r4;
    // 0x8004E4E4: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x8004E4E8: multu       $t6, $v0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004E4EC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8004E4F0: lw          $t6, -0x49F4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X49F4);
    // 0x8004E4F4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8004E4F8: mflo        $t7
    ctx->r15 = lo;
    // 0x8004E4FC: addu        $t8, $t7, $s6
    ctx->r24 = ADD32(ctx->r15, ctx->r22);
    // 0x8004E500: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8004E504: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8004E508: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8004E50C: addu        $s3, $t9, $t6
    ctx->r19 = ADD32(ctx->r25, ctx->r14);
    // 0x8004E510: addiu       $s1, $s3, 0xC
    ctx->r17 = ADD32(ctx->r19, 0XC);
L_8004E514:
    // 0x8004E514: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004E518: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x8004E51C: jal         0x8000E26C
    // 0x8004E520: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_8000E26C(rdram, ctx);
        goto after_3;
    // 0x8004E520: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_3:
    // 0x8004E524: bne         $v0, $zero, L_8004E534
    if (ctx->r2 != 0) {
        // 0x8004E528: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_8004E534;
    }
    // 0x8004E528: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8004E52C: b           L_8004E53C
    // 0x8004E530: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
        goto L_8004E53C;
    // 0x8004E530: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
L_8004E534:
    // 0x8004E534: bne         $s0, $s5, L_8004E514
    if (ctx->r16 != ctx->r21) {
        // 0x8004E538: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_8004E514;
    }
    // 0x8004E538: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_8004E53C:
    // 0x8004E53C: beql        $s7, $zero, L_8004E580
    if (ctx->r23 == 0) {
        // 0x8004E540: sw          $zero, 0x0($s2)
        MEM_W(0X0, ctx->r18) = 0;
            goto L_8004E580;
    }
    goto skip_4;
    // 0x8004E540: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    skip_4:
    // 0x8004E544: sw          $s3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r19;
    // 0x8004E548: lw          $t7, 0x114($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X114);
    // 0x8004E54C: lw          $t9, 0x110($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X110);
    // 0x8004E550: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8004E554: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8004E558: sw          $t8, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r24;
    // 0x8004E55C: lh          $t6, 0x2($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X2);
    // 0x8004E560: lw          $t8, 0x10C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10C);
    // 0x8004E564: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x8004E568: sw          $t7, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r15;
    // 0x8004E56C: lh          $t9, 0x0($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X0);
    // 0x8004E570: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x8004E574: b           L_8004E584
    // 0x8004E578: sw          $t6, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r14;
        goto L_8004E584;
    // 0x8004E578: sw          $t6, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r14;
    // 0x8004E57C: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
L_8004E580:
    // 0x8004E580: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_8004E584:
    // 0x8004E584: lw          $a0, 0x124($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X124);
    // 0x8004E588: b           L_8004E598
    // 0x8004E58C: lw          $v1, 0x138($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X138);
        goto L_8004E598;
    // 0x8004E58C: lw          $v1, 0x138($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X138);
L_8004E590:
    // 0x8004E590: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
L_8004E594:
    // 0x8004E594: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_8004E598:
    // 0x8004E598: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8004E59C: bne         $a0, $v1, L_8004E4C4
    if (ctx->r4 != ctx->r3) {
        // 0x8004E5A0: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_8004E4C4;
    }
    // 0x8004E5A0: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x8004E5A4: b           L_8004E5FC
    // 0x8004E5A8: lw          $t9, 0xEC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XEC);
        goto L_8004E5FC;
    // 0x8004E5A8: lw          $t9, 0xEC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XEC);
    // 0x8004E5AC: lw          $t7, 0x150($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X150);
L_8004E5B0:
    // 0x8004E5B0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8004E5B4: blez        $t7, L_8004E5F8
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8004E5B8: andi        $a0, $t7, 0x3
        ctx->r4 = ctx->r15 & 0X3;
            goto L_8004E5F8;
    }
    // 0x8004E5B8: andi        $a0, $t7, 0x3
    ctx->r4 = ctx->r15 & 0X3;
    // 0x8004E5BC: beq         $a0, $zero, L_8004E5DC
    if (ctx->r4 == 0) {
        // 0x8004E5C0: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8004E5DC;
    }
    // 0x8004E5C0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8004E5C4:
    // 0x8004E5C4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8004E5C8: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    // 0x8004E5CC: bne         $v0, $t0, L_8004E5C4
    if (ctx->r2 != ctx->r8) {
        // 0x8004E5D0: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8004E5C4;
    }
    // 0x8004E5D0: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8004E5D4: lw          $t8, 0x150($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X150);
    // 0x8004E5D8: beq         $t0, $t8, L_8004E5F8
    if (ctx->r8 == ctx->r24) {
        // 0x8004E5DC: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_8004E5F8;
    }
L_8004E5DC:
    // 0x8004E5DC: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8004E5E0: sw          $zero, 0x4($s2)
    MEM_W(0X4, ctx->r18) = 0;
    // 0x8004E5E4: sw          $zero, 0x8($s2)
    MEM_W(0X8, ctx->r18) = 0;
    // 0x8004E5E8: sw          $zero, 0xC($s2)
    MEM_W(0XC, ctx->r18) = 0;
    // 0x8004E5EC: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x8004E5F0: bne         $t0, $v1, L_8004E5DC
    if (ctx->r8 != ctx->r3) {
        // 0x8004E5F4: sw          $zero, -0x10($s2)
        MEM_W(-0X10, ctx->r18) = 0;
            goto L_8004E5DC;
    }
    // 0x8004E5F4: sw          $zero, -0x10($s2)
    MEM_W(-0X10, ctx->r18) = 0;
L_8004E5F8:
    // 0x8004E5F8: lw          $t9, 0xEC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XEC);
L_8004E5FC:
    // 0x8004E5FC: lw          $t7, 0x120($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X120);
    // 0x8004E600: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x8004E604: lw          $t9, 0x134($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X134);
    // 0x8004E608: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8004E60C: sw          $t8, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r24;
    // 0x8004E610: bne         $t8, $t9, L_8004E494
    if (ctx->r24 != ctx->r25) {
        // 0x8004E614: sw          $t6, 0xEC($sp)
        MEM_W(0XEC, ctx->r29) = ctx->r14;
            goto L_8004E494;
    }
    // 0x8004E614: sw          $t6, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r14;
L_8004E618:
    // 0x8004E618: lw          $t6, 0x114($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X114);
    // 0x8004E61C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004E620: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004E624: sll         $s7, $t6, 2
    ctx->r23 = S32(ctx->r14 << 2);
    // 0x8004E628: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x8004E62C: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8004E630: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8004E634: sw          $zero, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = 0;
    // 0x8004E638: jal         0x80004364
    // 0x8004E63C: sw          $t6, -0x4A00($at)
    MEM_W(-0X4A00, ctx->r1) = ctx->r14;
    func_80004364(rdram, ctx);
        goto after_4;
    // 0x8004E63C: sw          $t6, -0x4A00($at)
    MEM_W(-0X4A00, ctx->r1) = ctx->r14;
    after_4:
    // 0x8004E640: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x8004E644: lw          $t0, 0x11C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X11C);
    // 0x8004E648: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x8004E64C: blez        $a2, L_8004E708
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8004E650: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8004E708;
    }
    // 0x8004E650: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8004E654: andi        $v0, $a2, 0x3
    ctx->r2 = ctx->r6 & 0X3;
    // 0x8004E658: beq         $v0, $zero, L_8004E694
    if (ctx->r2 == 0) {
        // 0x8004E65C: lw          $t7, 0x144($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X144);
            goto L_8004E694;
    }
    // 0x8004E65C: lw          $t7, 0x144($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X144);
    // 0x8004E660: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x8004E664: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x8004E668: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8004E66C:
    // 0x8004E66C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8004E670: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8004E674: beq         $v0, $zero, L_8004E684
    if (ctx->r2 == 0) {
        // 0x8004E678: nop
    
            goto L_8004E684;
    }
    // 0x8004E678: nop

    // 0x8004E67C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8004E680: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_8004E684:
    // 0x8004E684: bne         $a1, $t0, L_8004E66C
    if (ctx->r5 != ctx->r8) {
        // 0x8004E688: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_8004E66C;
    }
    // 0x8004E688: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8004E68C: beql        $t0, $a2, L_8004E708
    if (ctx->r8 == ctx->r6) {
        // 0x8004E690: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_8004E708;
    }
    goto skip_5;
    // 0x8004E690: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    skip_5:
L_8004E694:
    // 0x8004E694: lw          $a2, 0x130($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X130);
    // 0x8004E698: lw          $t9, 0x144($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X144);
    // 0x8004E69C: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x8004E6A0: sll         $a1, $a2, 2
    ctx->r5 = S32(ctx->r6 << 2);
    // 0x8004E6A4: addu        $a0, $t9, $t5
    ctx->r4 = ADD32(ctx->r25, ctx->r13);
L_8004E6A8:
    // 0x8004E6A8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8004E6AC: addiu       $t5, $t5, 0x10
    ctx->r13 = ADD32(ctx->r13, 0X10);
    // 0x8004E6B0: beql        $v0, $zero, L_8004E6C4
    if (ctx->r2 == 0) {
        // 0x8004E6B4: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_8004E6C4;
    }
    goto skip_6;
    // 0x8004E6B4: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_6:
    // 0x8004E6B8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8004E6BC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8004E6C0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_8004E6C4:
    // 0x8004E6C4: beql        $v0, $zero, L_8004E6D8
    if (ctx->r2 == 0) {
        // 0x8004E6C8: lw          $v0, 0x8($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X8);
            goto L_8004E6D8;
    }
    goto skip_7;
    // 0x8004E6C8: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    skip_7:
    // 0x8004E6CC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8004E6D0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8004E6D4: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
L_8004E6D8:
    // 0x8004E6D8: beql        $v0, $zero, L_8004E6EC
    if (ctx->r2 == 0) {
        // 0x8004E6DC: lw          $v0, 0xC($a0)
        ctx->r2 = MEM_W(ctx->r4, 0XC);
            goto L_8004E6EC;
    }
    goto skip_8;
    // 0x8004E6DC: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    skip_8:
    // 0x8004E6E0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8004E6E4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8004E6E8: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
L_8004E6EC:
    // 0x8004E6EC: beq         $v0, $zero, L_8004E6FC
    if (ctx->r2 == 0) {
        // 0x8004E6F0: nop
    
            goto L_8004E6FC;
    }
    // 0x8004E6F0: nop

    // 0x8004E6F4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8004E6F8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_8004E6FC:
    // 0x8004E6FC: bne         $t5, $a1, L_8004E6A8
    if (ctx->r13 != ctx->r5) {
        // 0x8004E700: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_8004E6A8;
    }
    // 0x8004E700: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8004E704: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8004E708:
    // 0x8004E708: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8004E70C: addiu       $s2, $s2, -0x49E0
    ctx->r18 = ADD32(ctx->r18, -0X49E0);
    // 0x8004E710: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x8004E714: lui         $s5, 0x801A
    ctx->r21 = S32(0X801A << 16);
    // 0x8004E718: addiu       $s5, $s5, 0x2800
    ctx->r21 = ADD32(ctx->r21, 0X2800);
    // 0x8004E71C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8004E720: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8004E724: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8004E728: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8004E72C: jal         0x80004364
    // 0x8004E730: sw          $t0, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r8;
    func_80004364(rdram, ctx);
        goto after_5;
    // 0x8004E730: sw          $t0, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r8;
    after_5:
    // 0x8004E734: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x8004E738: lw          $t0, 0x11C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X11C);
    // 0x8004E73C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8004E740: blez        $t7, L_8004E768
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8004E744: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8004E768;
    }
    // 0x8004E744: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8004E748: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
L_8004E74C:
    // 0x8004E74C: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x8004E750: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8004E754: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8004E758: slt         $at, $t0, $t8
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8004E75C: bnel        $at, $zero, L_8004E74C
    if (ctx->r1 != 0) {
        // 0x8004E760: sh          $zero, 0x0($v1)
        MEM_H(0X0, ctx->r3) = 0;
            goto L_8004E74C;
    }
    goto skip_9;
    // 0x8004E760: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    skip_9:
    // 0x8004E764: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8004E768:
    // 0x8004E768: lw          $s3, 0x114($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X114);
    // 0x8004E76C: blez        $s3, L_8004E864
    if (SIGNED(ctx->r19) <= 0) {
        // 0x8004E770: andi        $v1, $s3, 0x3
        ctx->r3 = ctx->r19 & 0X3;
            goto L_8004E864;
    }
    // 0x8004E770: andi        $v1, $s3, 0x3
    ctx->r3 = ctx->r19 & 0X3;
    // 0x8004E774: beq         $v1, $zero, L_8004E7B8
    if (ctx->r3 == 0) {
        // 0x8004E778: or          $a3, $v1, $zero
        ctx->r7 = ctx->r3 | 0;
            goto L_8004E7B8;
    }
    // 0x8004E778: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x8004E77C: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x8004E780: addu        $a2, $s6, $t9
    ctx->r6 = ADD32(ctx->r22, ctx->r25);
L_8004E784:
    // 0x8004E784: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8004E788: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8004E78C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8004E790: lh          $t6, 0x3C($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X3C);
    // 0x8004E794: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8004E798: addu        $a0, $t7, $v0
    ctx->r4 = ADD32(ctx->r15, ctx->r2);
    // 0x8004E79C: lh          $a1, 0x0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X0);
    // 0x8004E7A0: bne         $a1, $zero, L_8004E7AC
    if (ctx->r5 != 0) {
        // 0x8004E7A4: addiu       $t8, $a1, 0x1
        ctx->r24 = ADD32(ctx->r5, 0X1);
            goto L_8004E7AC;
    }
    // 0x8004E7A4: addiu       $t8, $a1, 0x1
    ctx->r24 = ADD32(ctx->r5, 0X1);
    // 0x8004E7A8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8004E7AC:
    // 0x8004E7AC: bne         $a3, $t0, L_8004E784
    if (ctx->r7 != ctx->r8) {
        // 0x8004E7B0: sh          $t8, 0x0($a0)
        MEM_H(0X0, ctx->r4) = ctx->r24;
            goto L_8004E784;
    }
    // 0x8004E7B0: sh          $t8, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r24;
    // 0x8004E7B4: beq         $t0, $s3, L_8004E860
    if (ctx->r8 == ctx->r19) {
        // 0x8004E7B8: sll         $t5, $t0, 2
        ctx->r13 = S32(ctx->r8 << 2);
            goto L_8004E860;
    }
L_8004E7B8:
    // 0x8004E7B8: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x8004E7BC: addu        $a2, $s6, $t5
    ctx->r6 = ADD32(ctx->r22, ctx->r13);
    // 0x8004E7C0: sll         $a3, $s3, 2
    ctx->r7 = S32(ctx->r19 << 2);
L_8004E7C4:
    // 0x8004E7C4: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8004E7C8: addiu       $t5, $t5, 0x10
    ctx->r13 = ADD32(ctx->r13, 0X10);
    // 0x8004E7CC: lh          $t9, 0x3C($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X3C);
    // 0x8004E7D0: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8004E7D4: addu        $a0, $t6, $v0
    ctx->r4 = ADD32(ctx->r14, ctx->r2);
    // 0x8004E7D8: lh          $a1, 0x0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X0);
    // 0x8004E7DC: bne         $a1, $zero, L_8004E7E8
    if (ctx->r5 != 0) {
        // 0x8004E7E0: addiu       $t7, $a1, 0x1
        ctx->r15 = ADD32(ctx->r5, 0X1);
            goto L_8004E7E8;
    }
    // 0x8004E7E0: addiu       $t7, $a1, 0x1
    ctx->r15 = ADD32(ctx->r5, 0X1);
    // 0x8004E7E4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8004E7E8:
    // 0x8004E7E8: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x8004E7EC: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x8004E7F0: lh          $t8, 0x3C($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X3C);
    // 0x8004E7F4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8004E7F8: addu        $a0, $t9, $v0
    ctx->r4 = ADD32(ctx->r25, ctx->r2);
    // 0x8004E7FC: lh          $a1, 0x0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X0);
    // 0x8004E800: bne         $a1, $zero, L_8004E80C
    if (ctx->r5 != 0) {
        // 0x8004E804: addiu       $t6, $a1, 0x1
        ctx->r14 = ADD32(ctx->r5, 0X1);
            goto L_8004E80C;
    }
    // 0x8004E804: addiu       $t6, $a1, 0x1
    ctx->r14 = ADD32(ctx->r5, 0X1);
    // 0x8004E808: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8004E80C:
    // 0x8004E80C: sh          $t6, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r14;
    // 0x8004E810: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x8004E814: lh          $t7, 0x3C($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X3C);
    // 0x8004E818: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8004E81C: addu        $a0, $t8, $v0
    ctx->r4 = ADD32(ctx->r24, ctx->r2);
    // 0x8004E820: lh          $a1, 0x0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X0);
    // 0x8004E824: bne         $a1, $zero, L_8004E830
    if (ctx->r5 != 0) {
        // 0x8004E828: addiu       $t9, $a1, 0x1
        ctx->r25 = ADD32(ctx->r5, 0X1);
            goto L_8004E830;
    }
    // 0x8004E828: addiu       $t9, $a1, 0x1
    ctx->r25 = ADD32(ctx->r5, 0X1);
    // 0x8004E82C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8004E830:
    // 0x8004E830: sh          $t9, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r25;
    // 0x8004E834: lw          $v1, 0xC($a2)
    ctx->r3 = MEM_W(ctx->r6, 0XC);
    // 0x8004E838: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8004E83C: lh          $t6, 0x3C($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X3C);
    // 0x8004E840: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8004E844: addu        $a0, $t7, $v0
    ctx->r4 = ADD32(ctx->r15, ctx->r2);
    // 0x8004E848: lh          $a1, 0x0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X0);
    // 0x8004E84C: bne         $a1, $zero, L_8004E858
    if (ctx->r5 != 0) {
        // 0x8004E850: addiu       $t8, $a1, 0x1
        ctx->r24 = ADD32(ctx->r5, 0X1);
            goto L_8004E858;
    }
    // 0x8004E850: addiu       $t8, $a1, 0x1
    ctx->r24 = ADD32(ctx->r5, 0X1);
    // 0x8004E854: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8004E858:
    // 0x8004E858: bne         $t5, $a3, L_8004E7C4
    if (ctx->r13 != ctx->r7) {
        // 0x8004E85C: sh          $t8, 0x0($a0)
        MEM_H(0X0, ctx->r4) = ctx->r24;
            goto L_8004E7C4;
    }
    // 0x8004E85C: sh          $t8, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r24;
L_8004E860:
    // 0x8004E860: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8004E864:
    // 0x8004E864: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8004E868: sll         $a1, $s1, 2
    ctx->r5 = S32(ctx->r17 << 2);
    // 0x8004E86C: jal         0x80004364
    // 0x8004E870: sw          $t0, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r8;
    func_80004364(rdram, ctx);
        goto after_6;
    // 0x8004E870: sw          $t0, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r8;
    after_6:
    // 0x8004E874: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x8004E878: lw          $t0, 0x11C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X11C);
    // 0x8004E87C: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8004E880: blez        $a1, L_8004E8C0
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8004E884: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8004E8C0;
    }
    // 0x8004E884: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8004E888: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8004E88C:
    // 0x8004E88C: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x8004E890: blezl       $a0, L_8004E8B0
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8004E894: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_8004E8B0;
    }
    goto skip_10;
    // 0x8004E894: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    skip_10:
    // 0x8004E898: sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
    // 0x8004E89C: sh          $t0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r8;
    // 0x8004E8A0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8004E8A4: lw          $a1, -0x49E0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X49E0);
    // 0x8004E8A8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8004E8AC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_8004E8B0:
    // 0x8004E8B0: slt         $at, $t0, $a1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8004E8B4: bne         $at, $zero, L_8004E88C
    if (ctx->r1 != 0) {
        // 0x8004E8B8: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8004E88C;
    }
    // 0x8004E8B8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8004E8BC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8004E8C0:
    // 0x8004E8C0: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8004E8C4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8004E8C8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8004E8CC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8004E8D0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8004E8D4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8004E8D8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8004E8DC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8004E8E0: jal         0x800008CC
    // 0x8004E8E4: sw          $t0, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r8;
    func_800008CC(rdram, ctx);
        goto after_7;
    // 0x8004E8E4: sw          $t0, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r8;
    after_7:
    // 0x8004E8E8: lw          $t0, 0x11C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X11C);
    // 0x8004E8EC: blez        $s1, L_8004E9B4
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8004E8F0: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8004E9B4;
    }
    // 0x8004E8F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004E8F4: andi        $a0, $s1, 0x3
    ctx->r4 = ctx->r17 & 0X3;
    // 0x8004E8F8: beq         $a0, $zero, L_8004E934
    if (ctx->r4 == 0) {
        // 0x8004E8FC: lui         $s5, 0x801A
        ctx->r21 = S32(0X801A << 16);
            goto L_8004E934;
    }
    // 0x8004E8FC: lui         $s5, 0x801A
    ctx->r21 = S32(0X801A << 16);
    // 0x8004E900: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x8004E904: addu        $v0, $s4, $t7
    ctx->r2 = ADD32(ctx->r20, ctx->r15);
    // 0x8004E908: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_8004E90C:
    // 0x8004E90C: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x8004E910: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8004E914: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8004E918: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8004E91C: addu        $t6, $s0, $t9
    ctx->r14 = ADD32(ctx->r16, ctx->r25);
    // 0x8004E920: sh          $a1, 0x2($t6)
    MEM_H(0X2, ctx->r14) = ctx->r5;
    // 0x8004E924: lh          $t7, -0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, -0X4);
    // 0x8004E928: bne         $v1, $t0, L_8004E90C
    if (ctx->r3 != ctx->r8) {
        // 0x8004E92C: addu        $a1, $a1, $t7
        ctx->r5 = ADD32(ctx->r5, ctx->r15);
            goto L_8004E90C;
    }
    // 0x8004E92C: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x8004E930: beq         $t0, $s1, L_8004E9A8
    if (ctx->r8 == ctx->r17) {
        // 0x8004E934: sll         $t8, $t0, 2
        ctx->r24 = S32(ctx->r8 << 2);
            goto L_8004E9A8;
    }
L_8004E934:
    // 0x8004E934: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x8004E938: addu        $v0, $s4, $t8
    ctx->r2 = ADD32(ctx->r20, ctx->r24);
L_8004E93C:
    // 0x8004E93C: lh          $t9, 0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2);
    // 0x8004E940: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8004E944: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8004E948: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8004E94C: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x8004E950: sh          $a1, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r5;
    // 0x8004E954: lh          $t9, -0xA($v0)
    ctx->r25 = MEM_H(ctx->r2, -0XA);
    // 0x8004E958: lh          $t8, -0x10($v0)
    ctx->r24 = MEM_H(ctx->r2, -0X10);
    // 0x8004E95C: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8004E960: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x8004E964: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x8004E968: sh          $a1, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r5;
    // 0x8004E96C: lh          $t9, -0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, -0X6);
    // 0x8004E970: lh          $t8, -0xC($v0)
    ctx->r24 = MEM_H(ctx->r2, -0XC);
    // 0x8004E974: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8004E978: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x8004E97C: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x8004E980: sh          $a1, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r5;
    // 0x8004E984: lh          $t9, -0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, -0X2);
    // 0x8004E988: lh          $t8, -0x8($v0)
    ctx->r24 = MEM_H(ctx->r2, -0X8);
    // 0x8004E98C: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8004E990: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x8004E994: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x8004E998: sh          $a1, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r5;
    // 0x8004E99C: lh          $t8, -0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, -0X4);
    // 0x8004E9A0: bne         $t0, $s1, L_8004E93C
    if (ctx->r8 != ctx->r17) {
        // 0x8004E9A4: addu        $a1, $a1, $t8
        ctx->r5 = ADD32(ctx->r5, ctx->r24);
            goto L_8004E93C;
    }
    // 0x8004E9A4: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
L_8004E9A8:
    // 0x8004E9A8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8004E9AC: addiu       $s5, $s5, 0x2800
    ctx->r21 = ADD32(ctx->r21, 0X2800);
    // 0x8004E9B0: lw          $s3, 0x114($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X114);
L_8004E9B4:
    // 0x8004E9B4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8004E9B8: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x8004E9BC: jal         0x80004364
    // 0x8004E9C0: sw          $t0, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r8;
    func_80004364(rdram, ctx);
        goto after_8;
    // 0x8004E9C0: sw          $t0, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r8;
    after_8:
    // 0x8004E9C4: lw          $t0, 0x11C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X11C);
    // 0x8004E9C8: blez        $s3, L_8004EB34
    if (SIGNED(ctx->r19) <= 0) {
        // 0x8004E9CC: sw          $v0, 0xFC($sp)
        MEM_W(0XFC, ctx->r29) = ctx->r2;
            goto L_8004EB34;
    }
    // 0x8004E9CC: sw          $v0, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r2;
    // 0x8004E9D0: andi        $v1, $s3, 0x3
    ctx->r3 = ctx->r19 & 0X3;
    // 0x8004E9D4: beq         $v1, $zero, L_8004EA34
    if (ctx->r3 == 0) {
        // 0x8004E9D8: lui         $s5, 0x801A
        ctx->r21 = S32(0X801A << 16);
            goto L_8004EA34;
    }
    // 0x8004E9D8: lui         $s5, 0x801A
    ctx->r21 = S32(0X801A << 16);
    // 0x8004E9DC: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x8004E9E0: addu        $a2, $s6, $t9
    ctx->r6 = ADD32(ctx->r22, ctx->r25);
    // 0x8004E9E4: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
L_8004E9E8:
    // 0x8004E9E8: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8004E9EC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8004E9F0: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8004E9F4: lh          $t6, 0x3C($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X3C);
    // 0x8004E9F8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8004E9FC: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8004EA00: lh          $a1, 0x2($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X2);
    // 0x8004EA04: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8004EA08: addu        $t6, $v0, $t9
    ctx->r14 = ADD32(ctx->r2, ctx->r25);
    // 0x8004EA0C: sw          $v1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r3;
    // 0x8004EA10: lh          $t7, 0x3C($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X3C);
    // 0x8004EA14: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8004EA18: addu        $a0, $s0, $t8
    ctx->r4 = ADD32(ctx->r16, ctx->r24);
    // 0x8004EA1C: lh          $t9, 0x2($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X2);
    // 0x8004EA20: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x8004EA24: bne         $a3, $t0, L_8004E9E8
    if (ctx->r7 != ctx->r8) {
        // 0x8004EA28: sh          $t6, 0x2($a0)
        MEM_H(0X2, ctx->r4) = ctx->r14;
            goto L_8004E9E8;
    }
    // 0x8004EA28: sh          $t6, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r14;
    // 0x8004EA2C: lw          $a3, 0x114($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X114);
    // 0x8004EA30: beq         $t0, $a3, L_8004EB2C
    if (ctx->r8 == ctx->r7) {
        // 0x8004EA34: sll         $t7, $t0, 2
        ctx->r15 = S32(ctx->r8 << 2);
            goto L_8004EB2C;
    }
L_8004EA34:
    // 0x8004EA34: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x8004EA38: addu        $a2, $s6, $t7
    ctx->r6 = ADD32(ctx->r22, ctx->r15);
    // 0x8004EA3C: lw          $a3, 0x114($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X114);
L_8004EA40:
    // 0x8004EA40: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8004EA44: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8004EA48: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8004EA4C: lh          $t8, 0x3C($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X3C);
    // 0x8004EA50: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8004EA54: addu        $t6, $t9, $s0
    ctx->r14 = ADD32(ctx->r25, ctx->r16);
    // 0x8004EA58: lh          $a1, 0x2($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X2);
    // 0x8004EA5C: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8004EA60: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8004EA64: sw          $v1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r3;
    // 0x8004EA68: lh          $t9, 0x3C($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X3C);
    // 0x8004EA6C: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8004EA70: addu        $a0, $s0, $t6
    ctx->r4 = ADD32(ctx->r16, ctx->r14);
    // 0x8004EA74: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    // 0x8004EA78: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8004EA7C: sh          $t8, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r24;
    // 0x8004EA80: lw          $v1, -0xC($a2)
    ctx->r3 = MEM_W(ctx->r6, -0XC);
    // 0x8004EA84: lh          $t9, 0x3C($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X3C);
    // 0x8004EA88: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8004EA8C: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x8004EA90: lh          $a1, 0x2($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X2);
    // 0x8004EA94: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8004EA98: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8004EA9C: sw          $v1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r3;
    // 0x8004EAA0: lh          $t6, 0x3C($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X3C);
    // 0x8004EAA4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8004EAA8: addu        $a0, $s0, $t7
    ctx->r4 = ADD32(ctx->r16, ctx->r15);
    // 0x8004EAAC: lh          $t8, 0x2($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X2);
    // 0x8004EAB0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8004EAB4: sh          $t9, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r25;
    // 0x8004EAB8: lw          $v1, -0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, -0X8);
    // 0x8004EABC: lh          $t6, 0x3C($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X3C);
    // 0x8004EAC0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8004EAC4: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8004EAC8: lh          $a1, 0x2($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X2);
    // 0x8004EACC: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8004EAD0: addu        $t6, $v0, $t9
    ctx->r14 = ADD32(ctx->r2, ctx->r25);
    // 0x8004EAD4: sw          $v1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r3;
    // 0x8004EAD8: lh          $t7, 0x3C($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X3C);
    // 0x8004EADC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8004EAE0: addu        $a0, $s0, $t8
    ctx->r4 = ADD32(ctx->r16, ctx->r24);
    // 0x8004EAE4: lh          $t9, 0x2($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X2);
    // 0x8004EAE8: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x8004EAEC: sh          $t6, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r14;
    // 0x8004EAF0: lw          $v1, -0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, -0X4);
    // 0x8004EAF4: lh          $t7, 0x3C($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X3C);
    // 0x8004EAF8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8004EAFC: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x8004EB00: lh          $a1, 0x2($t9)
    ctx->r5 = MEM_H(ctx->r25, 0X2);
    // 0x8004EB04: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8004EB08: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8004EB0C: sw          $v1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r3;
    // 0x8004EB10: lh          $t8, 0x3C($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X3C);
    // 0x8004EB14: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8004EB18: addu        $a0, $s0, $t9
    ctx->r4 = ADD32(ctx->r16, ctx->r25);
    // 0x8004EB1C: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x8004EB20: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8004EB24: bne         $t0, $a3, L_8004EA40
    if (ctx->r8 != ctx->r7) {
        // 0x8004EB28: sh          $t7, 0x2($a0)
        MEM_H(0X2, ctx->r4) = ctx->r15;
            goto L_8004EA40;
    }
    // 0x8004EB28: sh          $t7, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r15;
L_8004EB2C:
    // 0x8004EB2C: addiu       $s5, $s5, 0x2800
    ctx->r21 = ADD32(ctx->r21, 0X2800);
    // 0x8004EB30: lw          $s3, 0x114($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X114);
L_8004EB34:
    // 0x8004EB34: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8004EB38: jal         0x800042A8
    // 0x8004EB3C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800042A8(rdram, ctx);
        goto after_9;
    // 0x8004EB3C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_9:
    // 0x8004EB40: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8004EB44: jal         0x800042A8
    // 0x8004EB48: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800042A8(rdram, ctx);
        goto after_10;
    // 0x8004EB48: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_10:
    // 0x8004EB4C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8004EB50: jal         0x800042A8
    // 0x8004EB54: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_800042A8(rdram, ctx);
        goto after_11;
    // 0x8004EB54: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_11:
    // 0x8004EB58: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8004EB5C: jal         0x800042A8
    // 0x8004EB60: lw          $a1, 0x144($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X144);
    func_800042A8(rdram, ctx);
        goto after_12;
    // 0x8004EB60: lw          $a1, 0x144($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X144);
    after_12:
    // 0x8004EB64: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x8004EB68: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x8004EB6C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8004EB70: lw          $t7, 0x110($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X110);
    // 0x8004EB74: addu        $t8, $t8, $s1
    ctx->r24 = ADD32(ctx->r24, ctx->r17);
    // 0x8004EB78: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8004EB7C: sll         $t9, $s3, 3
    ctx->r25 = S32(ctx->r19 << 3);
    // 0x8004EB80: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x8004EB84: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8004EB88: addu        $a1, $t6, $t8
    ctx->r5 = ADD32(ctx->r14, ctx->r24);
    // 0x8004EB8C: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    // 0x8004EB90: jal         0x80004364
    // 0x8004EB94: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_80004364(rdram, ctx);
        goto after_13;
    // 0x8004EB94: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_13:
    // 0x8004EB98: lw          $v1, 0x114($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X114);
    // 0x8004EB9C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004EBA0: sw          $v0, -0x49DC($at)
    MEM_W(-0X49DC, ctx->r1) = ctx->r2;
    // 0x8004EBA4: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8004EBA8: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8004EBAC: blez        $v1, L_8004EDF0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8004EBB0: lw          $a2, -0x49DC($a2)
        ctx->r6 = MEM_W(ctx->r6, -0X49DC);
            goto L_8004EDF0;
    }
    // 0x8004EBB0: lw          $a2, -0x49DC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X49DC);
    // 0x8004EBB4: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x8004EBB8: lui         $s7, 0x73F
    ctx->r23 = S32(0X73F << 16);
    // 0x8004EBBC: lui         $s4, 0xF500
    ctx->r20 = S32(0XF500 << 16);
    // 0x8004EBC0: ori         $s4, $s4, 0x100
    ctx->r20 = ctx->r20 | 0X100;
    // 0x8004EBC4: ori         $s7, $s7, 0xC000
    ctx->r23 = ctx->r23 | 0XC000;
    // 0x8004EBC8: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
    // 0x8004EBCC: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x8004EBD0: lw          $ra, 0xFC($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XFC);
    // 0x8004EBD4: lui         $fp, 0xFD50
    ctx->r30 = S32(0XFD50 << 16);
    // 0x8004EBD8: lui         $s6, 0xF000
    ctx->r22 = S32(0XF000 << 16);
    // 0x8004EBDC: lui         $s5, 0x700
    ctx->r21 = S32(0X700 << 16);
    // 0x8004EBE0: lui         $s3, 0xE800
    ctx->r19 = S32(0XE800 << 16);
    // 0x8004EBE4: lui         $s2, 0xFD10
    ctx->r18 = S32(0XFD10 << 16);
    // 0x8004EBE8: lui         $s1, 0xE700
    ctx->r17 = S32(0XE700 << 16);
    // 0x8004EBEC: lui         $s0, 0xE600
    ctx->r16 = S32(0XE600 << 16);
    // 0x8004EBF0: lui         $t1, 0xBF00
    ctx->r9 = S32(0XBF00 << 16);
    // 0x8004EBF4: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x8004EBF8: lw          $t0, 0x0($ra)
    ctx->r8 = MEM_W(ctx->r31, 0X0);
L_8004EBFC:
    // 0x8004EBFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004EC00: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8004EC04: lh          $t7, 0x3C($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X3C);
    // 0x8004EC08: beql        $t2, $t7, L_8004ED24
    if (ctx->r10 == ctx->r15) {
        // 0x8004EC0C: lh          $v1, 0x0($t0)
        ctx->r3 = MEM_H(ctx->r8, 0X0);
            goto L_8004ED24;
    }
    goto skip_11;
    // 0x8004EC0C: lh          $v1, 0x0($t0)
    ctx->r3 = MEM_H(ctx->r8, 0X0);
    skip_11:
    // 0x8004EC10: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x8004EC14: lw          $t6, 0x40($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X40);
    // 0x8004EC18: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8004EC1C: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x8004EC20: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8004EC24: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8004EC28: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8004EC2C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8004EC30: sw          $s3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r19;
    // 0x8004EC34: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8004EC38: or          $t2, $a2, $zero
    ctx->r10 = ctx->r6 | 0;
    // 0x8004EC3C: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8004EC40: sw          $s5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r21;
    // 0x8004EC44: sw          $s4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r20;
    // 0x8004EC48: or          $t3, $a2, $zero
    ctx->r11 = ctx->r6 | 0;
    // 0x8004EC4C: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8004EC50: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8004EC54: sw          $s0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r16;
    // 0x8004EC58: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8004EC5C: sw          $s7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r23;
    // 0x8004EC60: sw          $s6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r22;
    // 0x8004EC64: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8004EC68: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8004EC6C: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x8004EC70: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x8004EC74: sw          $fp, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r30;
    // 0x8004EC78: lw          $t8, 0x40($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X40);
    // 0x8004EC7C: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8004EC80: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8004EC84: addiu       $t9, $t8, 0x200
    ctx->r25 = ADD32(ctx->r24, 0X200);
    // 0x8004EC88: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8004EC8C: lui         $t6, 0x708
    ctx->r14 = S32(0X708 << 16);
    // 0x8004EC90: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x8004EC94: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8004EC98: lui         $t7, 0xF550
    ctx->r15 = S32(0XF550 << 16);
    // 0x8004EC9C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8004ECA0: or          $t2, $a2, $zero
    ctx->r10 = ctx->r6 | 0;
    // 0x8004ECA4: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8004ECA8: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8004ECAC: or          $t4, $a2, $zero
    ctx->r12 = ctx->r6 | 0;
    // 0x8004ECB0: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8004ECB4: sw          $s0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r16;
    // 0x8004ECB8: lui         $t9, 0x71F
    ctx->r25 = S32(0X71F << 16);
    // 0x8004ECBC: ori         $t9, $t9, 0xF200
    ctx->r25 = ctx->r25 | 0XF200;
    // 0x8004ECC0: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8004ECC4: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x8004ECC8: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x8004ECCC: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8004ECD0: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x8004ECD4: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8004ECD8: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x8004ECDC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8004ECE0: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x8004ECE4: lui         $t6, 0x8
    ctx->r14 = S32(0X8 << 16);
    // 0x8004ECE8: lui         $t7, 0xF548
    ctx->r15 = S32(0XF548 << 16);
    // 0x8004ECEC: ori         $t7, $t7, 0x800
    ctx->r15 = ctx->r15 | 0X800;
    // 0x8004ECF0: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x8004ECF4: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8004ECF8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8004ECFC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8004ED00: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8004ED04: lui         $t9, 0x7
    ctx->r25 = S32(0X7 << 16);
    // 0x8004ED08: ori         $t9, $t9, 0xC07C
    ctx->r25 = ctx->r25 | 0XC07C;
    // 0x8004ED0C: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8004ED10: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8004ED14: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8004ED18: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8004ED1C: lh          $t2, 0x3C($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X3C);
    // 0x8004ED20: lh          $v1, 0x0($t0)
    ctx->r3 = MEM_H(ctx->r8, 0X0);
L_8004ED24:
    // 0x8004ED24: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8004ED28: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8004ED2C: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x8004ED30: sll         $t6, $t7, 4
    ctx->r14 = S32(ctx->r15 << 4);
    // 0x8004ED34: andi        $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 & 0XFF;
    // 0x8004ED38: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8004ED3C: sll         $t6, $v1, 4
    ctx->r14 = S32(ctx->r3 << 4);
    // 0x8004ED40: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x8004ED44: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x8004ED48: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x8004ED4C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8004ED50: lw          $t6, 0x4($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X4);
    // 0x8004ED54: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8004ED58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8004ED5C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8004ED60: lh          $t7, 0x2($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X2);
    // 0x8004ED64: blez        $t7, L_8004EDDC
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8004ED68: or          $v1, $a2, $zero
        ctx->r3 = ctx->r6 | 0;
            goto L_8004EDDC;
    }
    // 0x8004ED68: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
L_8004ED6C:
    // 0x8004ED6C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8004ED70: lw          $t8, 0x8($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X8);
    // 0x8004ED74: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8004ED78: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8004ED7C: addu        $v0, $t8, $a0
    ctx->r2 = ADD32(ctx->r24, ctx->r4);
    // 0x8004ED80: lbu         $t9, 0x2($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X2);
    // 0x8004ED84: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x8004ED88: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x8004ED8C: multu       $t9, $a3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004ED90: mflo        $t6
    ctx->r14 = lo;
    // 0x8004ED94: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8004ED98: nop

    // 0x8004ED9C: multu       $t8, $a3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004EDA0: mflo        $t9
    ctx->r25 = lo;
    // 0x8004EDA4: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x8004EDA8: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x8004EDAC: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x8004EDB0: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x8004EDB4: multu       $t6, $a3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004EDB8: mflo        $t7
    ctx->r15 = lo;
    // 0x8004EDBC: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8004EDC0: sll         $t6, $t8, 8
    ctx->r14 = S32(ctx->r24 << 8);
    // 0x8004EDC4: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x8004EDC8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8004EDCC: lh          $t8, 0x2($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X2);
    // 0x8004EDD0: slt         $at, $a1, $t8
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8004EDD4: bnel        $at, $zero, L_8004ED6C
    if (ctx->r1 != 0) {
        // 0x8004EDD8: or          $v1, $a2, $zero
        ctx->r3 = ctx->r6 | 0;
            goto L_8004ED6C;
    }
    goto skip_12;
    // 0x8004EDD8: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    skip_12:
L_8004EDDC:
    // 0x8004EDDC: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x8004EDE0: addiu       $t5, $t5, 0x4
    ctx->r13 = ADD32(ctx->r13, 0X4);
    // 0x8004EDE4: addiu       $ra, $ra, 0x4
    ctx->r31 = ADD32(ctx->r31, 0X4);
    // 0x8004EDE8: bnel        $t5, $t9, L_8004EBFC
    if (ctx->r13 != ctx->r25) {
        // 0x8004EDEC: lw          $t0, 0x0($ra)
        ctx->r8 = MEM_W(ctx->r31, 0X0);
            goto L_8004EBFC;
    }
    goto skip_13;
    // 0x8004EDEC: lw          $t0, 0x0($ra)
    ctx->r8 = MEM_W(ctx->r31, 0X0);
    skip_13:
L_8004EDF0:
    // 0x8004EDF0: lui         $t6, 0xB800
    ctx->r14 = S32(0XB800 << 16);
    // 0x8004EDF4: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8004EDF8: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x8004EDFC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004EE00: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8004EE04: jal         0x800042A8
    // 0x8004EE08: lw          $a1, 0xFC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XFC);
    func_800042A8(rdram, ctx);
        goto after_14;
    // 0x8004EE08: lw          $a1, 0xFC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XFC);
    after_14:
    // 0x8004EE0C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004EE10: addiu       $v1, $v1, -0x49D8
    ctx->r3 = ADD32(ctx->r3, -0X49D8);
    // 0x8004EE14: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8004EE18: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8004EE1C: lw          $t7, -0x49DC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X49DC);
    // 0x8004EE20: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x8004EE24: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8004EE28: sw          $t7, 0xD0($t9)
    MEM_W(0XD0, ctx->r25) = ctx->r15;
    // 0x8004EE2C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8004EE30: lw          $t7, 0x8($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X8);
    // 0x8004EE34: sw          $t6, 0xD8($t7)
    MEM_W(0XD8, ctx->r15) = ctx->r14;
    // 0x8004EE38: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8004EE3C: lw          $v0, 0x8($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X8);
    // 0x8004EE40: lw          $t8, 0xD8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XD8);
    // 0x8004EE44: ori         $t6, $t8, 0x8000
    ctx->r14 = ctx->r24 | 0X8000;
    // 0x8004EE48: sw          $t6, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r14;
    // 0x8004EE4C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8004EE50: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8004EE54: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8004EE58: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8004EE5C: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8004EE60: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8004EE64: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8004EE68: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8004EE6C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8004EE70: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8004EE74: jr          $ra
    // 0x8004EE78: addiu       $sp, $sp, 0x148
    ctx->r29 = ADD32(ctx->r29, 0X148);
    TRACE_RETURN()
    return;
    // 0x8004EE78: addiu       $sp, $sp, 0x148
    ctx->r29 = ADD32(ctx->r29, 0X148);
;}
RECOMP_FUNC void func_8004EE7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004EE7C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8004EE80: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8004EE84: bnel        $t6, $zero, L_8004EE98
    if (ctx->r14 != 0) {
        // 0x8004EE88: lw          $v1, 0x0($a1)
        ctx->r3 = MEM_W(ctx->r5, 0X0);
            goto L_8004EE98;
    }
    goto skip_0;
    // 0x8004EE88: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    skip_0:
    // 0x8004EE8C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8004EE90: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8004EE94: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
L_8004EE98:
    // 0x8004EE98: bne         $v1, $zero, L_8004EEAC
    if (ctx->r3 != 0) {
        // 0x8004EE9C: nop
    
            goto L_8004EEAC;
    }
    // 0x8004EE9C: nop

    // 0x8004EEA0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8004EEA4: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8004EEA8: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_8004EEAC:
    // 0x8004EEAC: lw          $a2, -0x49CC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X49CC);
    // 0x8004EEB0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8004EEB4: div         $zero, $v0, $a2
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r6)));
    // 0x8004EEB8: mflo        $a1
    ctx->r5 = lo;
    // 0x8004EEBC: bne         $a2, $zero, L_8004EEC8
    if (ctx->r6 != 0) {
        // 0x8004EEC0: nop
    
            goto L_8004EEC8;
    }
    // 0x8004EEC0: nop

    // 0x8004EEC4: break       7
    do_break(2147806916);
L_8004EEC8:
    // 0x8004EEC8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004EECC: bne         $a2, $at, L_8004EEE0
    if (ctx->r6 != ctx->r1) {
        // 0x8004EED0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8004EEE0;
    }
    // 0x8004EED0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8004EED4: bne         $v0, $at, L_8004EEE0
    if (ctx->r2 != ctx->r1) {
        // 0x8004EED8: nop
    
            goto L_8004EEE0;
    }
    // 0x8004EED8: nop

    // 0x8004EEDC: break       6
    do_break(2147806940);
L_8004EEE0:
    // 0x8004EEE0: div         $zero, $v1, $a2
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r6)));
    // 0x8004EEE4: mflo        $a3
    ctx->r7 = lo;
    // 0x8004EEE8: bne         $a2, $zero, L_8004EEF4
    if (ctx->r6 != 0) {
        // 0x8004EEEC: nop
    
            goto L_8004EEF4;
    }
    // 0x8004EEEC: nop

    // 0x8004EEF0: break       7
    do_break(2147806960);
L_8004EEF4:
    // 0x8004EEF4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004EEF8: bne         $a2, $at, L_8004EF0C
    if (ctx->r6 != ctx->r1) {
        // 0x8004EEFC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8004EF0C;
    }
    // 0x8004EEFC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8004EF00: bne         $v1, $at, L_8004EF0C
    if (ctx->r3 != ctx->r1) {
        // 0x8004EF04: nop
    
            goto L_8004EF0C;
    }
    // 0x8004EF04: nop

    // 0x8004EF08: break       6
    do_break(2147806984);
L_8004EF0C:
    // 0x8004EF0C: bgez        $v0, L_8004EF18
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8004EF10: nop
    
            goto L_8004EF18;
    }
    // 0x8004EF10: nop

    // 0x8004EF14: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
L_8004EF18:
    // 0x8004EF18: bgez        $v1, L_8004EF24
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8004EF1C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8004EF24;
    }
    // 0x8004EF1C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004EF20: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
L_8004EF24:
    // 0x8004EF24: lw          $v0, -0x49EC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X49EC);
    // 0x8004EF28: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004EF2C: lw          $v1, -0x49E8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X49E8);
    // 0x8004EF30: bgez        $v0, L_8004EF40
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8004EF34: sra         $t9, $v0, 1
        ctx->r25 = S32(SIGNED(ctx->r2) >> 1);
            goto L_8004EF40;
    }
    // 0x8004EF34: sra         $t9, $v0, 1
    ctx->r25 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8004EF38: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x8004EF3C: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_8004EF40:
    // 0x8004EF40: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x8004EF44: bgez        $v1, L_8004EF54
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8004EF48: sra         $t0, $v1, 1
        ctx->r8 = S32(SIGNED(ctx->r3) >> 1);
            goto L_8004EF54;
    }
    // 0x8004EF48: sra         $t0, $v1, 1
    ctx->r8 = S32(SIGNED(ctx->r3) >> 1);
    // 0x8004EF4C: addiu       $at, $v1, 0x1
    ctx->r1 = ADD32(ctx->r3, 0X1);
    // 0x8004EF50: sra         $t0, $at, 1
    ctx->r8 = S32(SIGNED(ctx->r1) >> 1);
L_8004EF54:
    // 0x8004EF54: bltz        $a1, L_8004EF68
    if (SIGNED(ctx->r5) < 0) {
        // 0x8004EF58: addu        $a3, $a3, $t0
        ctx->r7 = ADD32(ctx->r7, ctx->r8);
            goto L_8004EF68;
    }
    // 0x8004EF58: addu        $a3, $a3, $t0
    ctx->r7 = ADD32(ctx->r7, ctx->r8);
    // 0x8004EF5C: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8004EF60: bne         $at, $zero, L_8004EF70
    if (ctx->r1 != 0) {
        // 0x8004EF64: nop
    
            goto L_8004EF70;
    }
    // 0x8004EF64: nop

L_8004EF68:
    // 0x8004EF68: jr          $ra
    // 0x8004EF6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    TRACE_RETURN()
    return;
    // 0x8004EF6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004EF70:
    // 0x8004EF70: bltz        $a3, L_8004EF80
    if (SIGNED(ctx->r7) < 0) {
        // 0x8004EF74: slt         $at, $a3, $v1
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8004EF80;
    }
    // 0x8004EF74: slt         $at, $a3, $v1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8004EF78: bne         $at, $zero, L_8004EF88
    if (ctx->r1 != 0) {
        // 0x8004EF7C: nop
    
            goto L_8004EF88;
    }
    // 0x8004EF7C: nop

L_8004EF80:
    // 0x8004EF80: jr          $ra
    // 0x8004EF84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    TRACE_RETURN()
    return;
    // 0x8004EF84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004EF88:
    // 0x8004EF88: multu       $a3, $v1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004EF8C: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x8004EF90: lw          $t4, -0x49F4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X49F4);
    // 0x8004EF94: mflo        $t1
    ctx->r9 = lo;
    // 0x8004EF98: addu        $t2, $t1, $a1
    ctx->r10 = ADD32(ctx->r9, ctx->r5);
    // 0x8004EF9C: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8004EFA0: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8004EFA4: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8004EFA8: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x8004EFAC: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8004EFB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004EFB4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004EFB8: sw          $a0, -0x49D4($at)
    MEM_W(-0X49D4, ctx->r1) = ctx->r4;
    // 0x8004EFBC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004EFC0: jr          $ra
    // 0x8004EFC4: sw          $a1, -0x49D0($at)
    MEM_W(-0X49D0, ctx->r1) = ctx->r5;
    TRACE_RETURN()
    return;
    // 0x8004EFC4: sw          $a1, -0x49D0($at)
    MEM_W(-0X49D0, ctx->r1) = ctx->r5;
;}
RECOMP_FUNC void func_8004EFD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004EFD0: addiu       $sp, $sp, -0x180
    ctx->r29 = ADD32(ctx->r29, -0X180);
    // 0x8004EFD4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8004EFD8: addiu       $s3, $sp, 0x58
    ctx->r19 = ADD32(ctx->r29, 0X58);
    // 0x8004EFDC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8004EFE0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8004EFE4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8004EFE8: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8004EFEC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8004EFF0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8004EFF4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8004EFF8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8004EFFC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8004F000: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004F004: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8004F008: jal         0x8000C5FC
    // 0x8004F00C: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    dma_read_rom(rdram, ctx);
        goto after_0;
    // 0x8004F00C: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    after_0:
    // 0x8004F010: lbu         $t6, 0x5B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X5B);
    // 0x8004F014: lbu         $t8, 0x58($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X58);
    // 0x8004F018: lbu         $t0, 0x59($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X59);
    // 0x8004F01C: lbu         $t3, 0x5A($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X5A);
    // 0x8004F020: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x8004F024: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8004F028: sll         $t1, $t0, 8
    ctx->r9 = S32(ctx->r8 << 8);
    // 0x8004F02C: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8004F030: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x8004F034: addu        $a1, $t2, $t4
    ctx->r5 = ADD32(ctx->r10, ctx->r12);
    // 0x8004F038: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004F03C: addiu       $s2, $s2, 0x100
    ctx->r18 = ADD32(ctx->r18, 0X100);
    // 0x8004F040: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8004F044: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8004F048: jal         0x80004364
    // 0x8004F04C: sw          $a1, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r5;
    func_80004364(rdram, ctx);
        goto after_1;
    // 0x8004F04C: sw          $a1, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r5;
    after_1:
    // 0x8004F050: lw          $t5, 0x16C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X16C);
    // 0x8004F054: sw          $v0, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r2;
    // 0x8004F058: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
    // 0x8004F05C: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x8004F060: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x8004F064: blez        $t5, L_8004F1A8
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8004F068: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_8004F1A8;
    }
    // 0x8004F068: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
L_8004F06C:
    // 0x8004F06C: bne         $s5, $zero, L_8004F0A0
    if (ctx->r21 != 0) {
        // 0x8004F070: addu        $t6, $s1, $s3
        ctx->r14 = ADD32(ctx->r17, ctx->r19);
            goto L_8004F0A0;
    }
    // 0x8004F070: addu        $t6, $s1, $s3
    ctx->r14 = ADD32(ctx->r17, ctx->r19);
    // 0x8004F074: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8004F078: andi        $t7, $s1, 0xFF
    ctx->r15 = ctx->r17 & 0XFF;
    // 0x8004F07C: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x8004F080: bne         $t7, $zero, L_8004F09C
    if (ctx->r15 != 0) {
        // 0x8004F084: lbu         $s7, 0x0($t6)
        ctx->r23 = MEM_BU(ctx->r14, 0X0);
            goto L_8004F09C;
    }
    // 0x8004F084: lbu         $s7, 0x0($t6)
    ctx->r23 = MEM_BU(ctx->r14, 0X0);
    // 0x8004F088: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8004F08C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8004F090: jal         0x8000C5FC
    // 0x8004F094: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    dma_read_rom(rdram, ctx);
        goto after_2;
    // 0x8004F094: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    after_2:
    // 0x8004F098: addiu       $s2, $s2, 0x100
    ctx->r18 = ADD32(ctx->r18, 0X100);
L_8004F09C:
    // 0x8004F09C: addiu       $s5, $zero, 0x8
    ctx->r21 = ADD32(0, 0X8);
L_8004F0A0:
    // 0x8004F0A0: sll         $t8, $s7, 1
    ctx->r24 = S32(ctx->r23 << 1);
    // 0x8004F0A4: andi        $t0, $t8, 0x100
    ctx->r8 = ctx->r24 & 0X100;
    // 0x8004F0A8: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x8004F0AC: beq         $t0, $zero, L_8004F160
    if (ctx->r8 == 0) {
        // 0x8004F0B0: or          $s7, $t8, $zero
        ctx->r23 = ctx->r24 | 0;
            goto L_8004F160;
    }
    // 0x8004F0B0: or          $s7, $t8, $zero
    ctx->r23 = ctx->r24 | 0;
    // 0x8004F0B4: addu        $t9, $s1, $s3
    ctx->r25 = ADD32(ctx->r17, ctx->r19);
    // 0x8004F0B8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8004F0BC: andi        $t1, $s1, 0xFF
    ctx->r9 = ctx->r17 & 0XFF;
    // 0x8004F0C0: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x8004F0C4: bne         $t1, $zero, L_8004F0E0
    if (ctx->r9 != 0) {
        // 0x8004F0C8: lbu         $s6, 0x0($t9)
        ctx->r22 = MEM_BU(ctx->r25, 0X0);
            goto L_8004F0E0;
    }
    // 0x8004F0C8: lbu         $s6, 0x0($t9)
    ctx->r22 = MEM_BU(ctx->r25, 0X0);
    // 0x8004F0CC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8004F0D0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8004F0D4: jal         0x8000C5FC
    // 0x8004F0D8: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    dma_read_rom(rdram, ctx);
        goto after_3;
    // 0x8004F0D8: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    after_3:
    // 0x8004F0DC: addiu       $s2, $s2, 0x100
    ctx->r18 = ADD32(ctx->r18, 0X100);
L_8004F0E0:
    // 0x8004F0E0: addu        $t3, $s1, $s3
    ctx->r11 = ADD32(ctx->r17, ctx->r19);
    // 0x8004F0E4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8004F0E8: andi        $t2, $s1, 0xFF
    ctx->r10 = ctx->r17 & 0XFF;
    // 0x8004F0EC: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
    // 0x8004F0F0: bne         $t2, $zero, L_8004F10C
    if (ctx->r10 != 0) {
        // 0x8004F0F4: lbu         $s4, 0x0($t3)
        ctx->r20 = MEM_BU(ctx->r11, 0X0);
            goto L_8004F10C;
    }
    // 0x8004F0F4: lbu         $s4, 0x0($t3)
    ctx->r20 = MEM_BU(ctx->r11, 0X0);
    // 0x8004F0F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8004F0FC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8004F100: jal         0x8000C5FC
    // 0x8004F104: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    dma_read_rom(rdram, ctx);
        goto after_4;
    // 0x8004F104: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    after_4:
    // 0x8004F108: addiu       $s2, $s2, 0x100
    ctx->r18 = ADD32(ctx->r18, 0X100);
L_8004F10C:
    // 0x8004F10C: andi        $t4, $s6, 0xF
    ctx->r12 = ctx->r22 & 0XF;
    // 0x8004F110: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x8004F114: addu        $t6, $s4, $t5
    ctx->r14 = ADD32(ctx->r20, ctx->r13);
    // 0x8004F118: sra         $a0, $s6, 4
    ctx->r4 = S32(SIGNED(ctx->r22) >> 4);
    // 0x8004F11C: subu        $a2, $s0, $t6
    ctx->r6 = SUB32(ctx->r16, ctx->r14);
    // 0x8004F120: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x8004F124: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8004F128: beq         $a0, $zero, L_8004F198
    if (ctx->r4 == 0) {
        // 0x8004F12C: addiu       $v1, $a0, -0x1
        ctx->r3 = ADD32(ctx->r4, -0X1);
            goto L_8004F198;
    }
    // 0x8004F12C: addiu       $v1, $a0, -0x1
    ctx->r3 = ADD32(ctx->r4, -0X1);
    // 0x8004F130: addu        $a0, $fp, $s0
    ctx->r4 = ADD32(ctx->r30, ctx->r16);
    // 0x8004F134: addu        $a1, $a2, $fp
    ctx->r5 = ADD32(ctx->r6, ctx->r30);
L_8004F138:
    // 0x8004F138: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x8004F13C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8004F140: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8004F144: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8004F148: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8004F14C: sb          $t7, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r15;
    // 0x8004F150: bne         $v1, $zero, L_8004F138
    if (ctx->r3 != 0) {
        // 0x8004F154: addiu       $v1, $v1, -0x1
        ctx->r3 = ADD32(ctx->r3, -0X1);
            goto L_8004F138;
    }
    // 0x8004F154: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8004F158: b           L_8004F19C
    // 0x8004F15C: lw          $t3, 0x16C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X16C);
        goto L_8004F19C;
    // 0x8004F15C: lw          $t3, 0x16C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X16C);
L_8004F160:
    // 0x8004F160: addu        $t8, $s1, $s3
    ctx->r24 = ADD32(ctx->r17, ctx->r19);
    // 0x8004F164: lbu         $t0, 0x0($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X0);
    // 0x8004F168: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8004F16C: andi        $t1, $s1, 0xFF
    ctx->r9 = ctx->r17 & 0XFF;
    // 0x8004F170: addu        $t9, $fp, $s0
    ctx->r25 = ADD32(ctx->r30, ctx->r16);
    // 0x8004F174: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8004F178: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x8004F17C: bne         $t1, $zero, L_8004F198
    if (ctx->r9 != 0) {
        // 0x8004F180: sb          $t0, 0x0($t9)
        MEM_B(0X0, ctx->r25) = ctx->r8;
            goto L_8004F198;
    }
    // 0x8004F180: sb          $t0, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r8;
    // 0x8004F184: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8004F188: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8004F18C: jal         0x8000C5FC
    // 0x8004F190: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    dma_read_rom(rdram, ctx);
        goto after_5;
    // 0x8004F190: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    after_5:
    // 0x8004F194: addiu       $s2, $s2, 0x100
    ctx->r18 = ADD32(ctx->r18, 0X100);
L_8004F198:
    // 0x8004F198: lw          $t3, 0x16C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X16C);
L_8004F19C:
    // 0x8004F19C: slt         $at, $s0, $t3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8004F1A0: bne         $at, $zero, L_8004F06C
    if (ctx->r1 != 0) {
        // 0x8004F1A4: nop
    
            goto L_8004F06C;
    }
    // 0x8004F1A4: nop

L_8004F1A8:
    // 0x8004F1A8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8004F1AC: lw          $v0, 0x178($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X178);
    // 0x8004F1B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004F1B4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8004F1B8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8004F1BC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8004F1C0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8004F1C4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8004F1C8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8004F1CC: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8004F1D0: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8004F1D4: jr          $ra
    // 0x8004F1D8: addiu       $sp, $sp, 0x180
    ctx->r29 = ADD32(ctx->r29, 0X180);
    TRACE_RETURN()
    return;
    // 0x8004F1D8: addiu       $sp, $sp, 0x180
    ctx->r29 = ADD32(ctx->r29, 0X180);
;}
RECOMP_FUNC void func_8004F1DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004F1DC: addiu       $sp, $sp, -0x178
    ctx->r29 = ADD32(ctx->r29, -0X178);
    // 0x8004F1E0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8004F1E4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8004F1E8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8004F1EC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8004F1F0: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x8004F1F4: addiu       $s4, $sp, 0x58
    ctx->r20 = ADD32(ctx->r29, 0X58);
    // 0x8004F1F8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8004F1FC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8004F200: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8004F204: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8004F208: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8004F20C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8004F210: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8004F214: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004F218: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8004F21C: jal         0x8000C5FC
    // 0x8004F220: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    dma_read_rom(rdram, ctx);
        goto after_0;
    // 0x8004F220: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    after_0:
    // 0x8004F224: lbu         $t6, 0x5B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X5B);
    // 0x8004F228: lbu         $t8, 0x58($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X58);
    // 0x8004F22C: lbu         $t0, 0x59($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X59);
    // 0x8004F230: lbu         $t3, 0x5A($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X5A);
    // 0x8004F234: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x8004F238: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8004F23C: sll         $t1, $t0, 8
    ctx->r9 = S32(ctx->r8 << 8);
    // 0x8004F240: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8004F244: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x8004F248: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8004F24C: addiu       $s3, $s3, 0x100
    ctx->r19 = ADD32(ctx->r19, 0X100);
    // 0x8004F250: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8004F254: sw          $t5, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->r13;
    // 0x8004F258: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
    // 0x8004F25C: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x8004F260: blez        $t5, L_8004F3A4
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8004F264: or          $s6, $zero, $zero
        ctx->r22 = 0 | 0;
            goto L_8004F3A4;
    }
    // 0x8004F264: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
L_8004F268:
    // 0x8004F268: bne         $s6, $zero, L_8004F29C
    if (ctx->r22 != 0) {
        // 0x8004F26C: addu        $t6, $s2, $s4
        ctx->r14 = ADD32(ctx->r18, ctx->r20);
            goto L_8004F29C;
    }
    // 0x8004F26C: addu        $t6, $s2, $s4
    ctx->r14 = ADD32(ctx->r18, ctx->r20);
    // 0x8004F270: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8004F274: andi        $t7, $s2, 0xFF
    ctx->r15 = ctx->r18 & 0XFF;
    // 0x8004F278: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x8004F27C: bne         $t7, $zero, L_8004F298
    if (ctx->r15 != 0) {
        // 0x8004F280: lbu         $fp, 0x0($t6)
        ctx->r30 = MEM_BU(ctx->r14, 0X0);
            goto L_8004F298;
    }
    // 0x8004F280: lbu         $fp, 0x0($t6)
    ctx->r30 = MEM_BU(ctx->r14, 0X0);
    // 0x8004F284: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8004F288: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8004F28C: jal         0x8000C5FC
    // 0x8004F290: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    dma_read_rom(rdram, ctx);
        goto after_1;
    // 0x8004F290: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    after_1:
    // 0x8004F294: addiu       $s3, $s3, 0x100
    ctx->r19 = ADD32(ctx->r19, 0X100);
L_8004F298:
    // 0x8004F298: addiu       $s6, $zero, 0x8
    ctx->r22 = ADD32(0, 0X8);
L_8004F29C:
    // 0x8004F29C: sll         $t8, $fp, 1
    ctx->r24 = S32(ctx->r30 << 1);
    // 0x8004F2A0: andi        $t0, $t8, 0x100
    ctx->r8 = ctx->r24 & 0X100;
    // 0x8004F2A4: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    // 0x8004F2A8: beq         $t0, $zero, L_8004F35C
    if (ctx->r8 == 0) {
        // 0x8004F2AC: or          $fp, $t8, $zero
        ctx->r30 = ctx->r24 | 0;
            goto L_8004F35C;
    }
    // 0x8004F2AC: or          $fp, $t8, $zero
    ctx->r30 = ctx->r24 | 0;
    // 0x8004F2B0: addu        $t9, $s2, $s4
    ctx->r25 = ADD32(ctx->r18, ctx->r20);
    // 0x8004F2B4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8004F2B8: andi        $t1, $s2, 0xFF
    ctx->r9 = ctx->r18 & 0XFF;
    // 0x8004F2BC: or          $s2, $t1, $zero
    ctx->r18 = ctx->r9 | 0;
    // 0x8004F2C0: bne         $t1, $zero, L_8004F2DC
    if (ctx->r9 != 0) {
        // 0x8004F2C4: lbu         $s7, 0x0($t9)
        ctx->r23 = MEM_BU(ctx->r25, 0X0);
            goto L_8004F2DC;
    }
    // 0x8004F2C4: lbu         $s7, 0x0($t9)
    ctx->r23 = MEM_BU(ctx->r25, 0X0);
    // 0x8004F2C8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8004F2CC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8004F2D0: jal         0x8000C5FC
    // 0x8004F2D4: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    dma_read_rom(rdram, ctx);
        goto after_2;
    // 0x8004F2D4: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    after_2:
    // 0x8004F2D8: addiu       $s3, $s3, 0x100
    ctx->r19 = ADD32(ctx->r19, 0X100);
L_8004F2DC:
    // 0x8004F2DC: addu        $t3, $s2, $s4
    ctx->r11 = ADD32(ctx->r18, ctx->r20);
    // 0x8004F2E0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8004F2E4: andi        $t2, $s2, 0xFF
    ctx->r10 = ctx->r18 & 0XFF;
    // 0x8004F2E8: or          $s2, $t2, $zero
    ctx->r18 = ctx->r10 | 0;
    // 0x8004F2EC: bne         $t2, $zero, L_8004F308
    if (ctx->r10 != 0) {
        // 0x8004F2F0: lbu         $s5, 0x0($t3)
        ctx->r21 = MEM_BU(ctx->r11, 0X0);
            goto L_8004F308;
    }
    // 0x8004F2F0: lbu         $s5, 0x0($t3)
    ctx->r21 = MEM_BU(ctx->r11, 0X0);
    // 0x8004F2F4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8004F2F8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8004F2FC: jal         0x8000C5FC
    // 0x8004F300: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    dma_read_rom(rdram, ctx);
        goto after_3;
    // 0x8004F300: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    after_3:
    // 0x8004F304: addiu       $s3, $s3, 0x100
    ctx->r19 = ADD32(ctx->r19, 0X100);
L_8004F308:
    // 0x8004F308: andi        $t4, $s7, 0xF
    ctx->r12 = ctx->r23 & 0XF;
    // 0x8004F30C: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x8004F310: addu        $t6, $s5, $t5
    ctx->r14 = ADD32(ctx->r21, ctx->r13);
    // 0x8004F314: sra         $a0, $s7, 4
    ctx->r4 = S32(SIGNED(ctx->r23) >> 4);
    // 0x8004F318: subu        $a2, $s0, $t6
    ctx->r6 = SUB32(ctx->r16, ctx->r14);
    // 0x8004F31C: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x8004F320: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8004F324: beq         $a0, $zero, L_8004F394
    if (ctx->r4 == 0) {
        // 0x8004F328: addiu       $v1, $a0, -0x1
        ctx->r3 = ADD32(ctx->r4, -0X1);
            goto L_8004F394;
    }
    // 0x8004F328: addiu       $v1, $a0, -0x1
    ctx->r3 = ADD32(ctx->r4, -0X1);
    // 0x8004F32C: addu        $a0, $s1, $s0
    ctx->r4 = ADD32(ctx->r17, ctx->r16);
    // 0x8004F330: addu        $a1, $a2, $s1
    ctx->r5 = ADD32(ctx->r6, ctx->r17);
L_8004F334:
    // 0x8004F334: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x8004F338: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8004F33C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8004F340: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8004F344: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8004F348: sb          $t7, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r15;
    // 0x8004F34C: bne         $v1, $zero, L_8004F334
    if (ctx->r3 != 0) {
        // 0x8004F350: addiu       $v1, $v1, -0x1
        ctx->r3 = ADD32(ctx->r3, -0X1);
            goto L_8004F334;
    }
    // 0x8004F350: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8004F354: b           L_8004F398
    // 0x8004F358: lw          $t3, 0x168($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X168);
        goto L_8004F398;
    // 0x8004F358: lw          $t3, 0x168($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X168);
L_8004F35C:
    // 0x8004F35C: addu        $t8, $s2, $s4
    ctx->r24 = ADD32(ctx->r18, ctx->r20);
    // 0x8004F360: lbu         $t0, 0x0($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X0);
    // 0x8004F364: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8004F368: andi        $t1, $s2, 0xFF
    ctx->r9 = ctx->r18 & 0XFF;
    // 0x8004F36C: addu        $t9, $s1, $s0
    ctx->r25 = ADD32(ctx->r17, ctx->r16);
    // 0x8004F370: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8004F374: or          $s2, $t1, $zero
    ctx->r18 = ctx->r9 | 0;
    // 0x8004F378: bne         $t1, $zero, L_8004F394
    if (ctx->r9 != 0) {
        // 0x8004F37C: sb          $t0, 0x0($t9)
        MEM_B(0X0, ctx->r25) = ctx->r8;
            goto L_8004F394;
    }
    // 0x8004F37C: sb          $t0, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r8;
    // 0x8004F380: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8004F384: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8004F388: jal         0x8000C5FC
    // 0x8004F38C: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    dma_read_rom(rdram, ctx);
        goto after_4;
    // 0x8004F38C: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    after_4:
    // 0x8004F390: addiu       $s3, $s3, 0x100
    ctx->r19 = ADD32(ctx->r19, 0X100);
L_8004F394:
    // 0x8004F394: lw          $t3, 0x168($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X168);
L_8004F398:
    // 0x8004F398: slt         $at, $s0, $t3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8004F39C: bne         $at, $zero, L_8004F268
    if (ctx->r1 != 0) {
        // 0x8004F3A0: nop
    
            goto L_8004F268;
    }
    // 0x8004F3A0: nop

L_8004F3A4:
    // 0x8004F3A4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8004F3A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004F3AC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8004F3B0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8004F3B4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8004F3B8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8004F3BC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8004F3C0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8004F3C4: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8004F3C8: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8004F3CC: jr          $ra
    // 0x8004F3D0: addiu       $sp, $sp, 0x178
    ctx->r29 = ADD32(ctx->r29, 0X178);
    TRACE_RETURN()
    return;
    // 0x8004F3D0: addiu       $sp, $sp, 0x178
    ctx->r29 = ADD32(ctx->r29, 0X178);
;}
RECOMP_FUNC void func_8004F3D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004F3D4: addiu       $sp, $sp, -0x128
    ctx->r29 = ADD32(ctx->r29, -0X128);
    // 0x8004F3D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004F3DC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8004F3E0: jal         0x8000C5FC
    // 0x8004F3E4: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    dma_read_rom(rdram, ctx);
        goto after_0;
    // 0x8004F3E4: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    after_0:
    // 0x8004F3E8: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x8004F3EC: lbu         $t8, 0x20($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X20);
    // 0x8004F3F0: lbu         $t0, 0x21($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X21);
    // 0x8004F3F4: lbu         $t3, 0x22($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X22);
    // 0x8004F3F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004F3FC: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x8004F400: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8004F404: sll         $t1, $t0, 8
    ctx->r9 = S32(ctx->r8 << 8);
    // 0x8004F408: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8004F40C: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x8004F410: addu        $v0, $t2, $t4
    ctx->r2 = ADD32(ctx->r10, ctx->r12);
    // 0x8004F414: jr          $ra
    // 0x8004F418: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
    TRACE_RETURN()
    return;
    // 0x8004F418: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
    // 0x8004F41C: nop

    // 0x8004F420: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004F424: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x8004F428: addiu       $t7, $zero, 0x0
    ctx->r15 = ADD32(0, 0X0);
    // 0x8004F42C: sw          $t7, -0x49B4($at)
    MEM_W(-0X49B4, ctx->r1) = ctx->r15;
    // 0x8004F430: sw          $t6, -0x49B8($at)
    MEM_W(-0X49B8, ctx->r1) = ctx->r14;
    // 0x8004F434: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004F438: sw          $zero, -0x49B0($at)
    MEM_W(-0X49B0, ctx->r1) = 0;
    // 0x8004F43C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004F440: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8004F444: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x8004F448: sw          $t9, -0x49A4($at)
    MEM_W(-0X49A4, ctx->r1) = ctx->r25;
    // 0x8004F44C: sw          $t8, -0x49A8($at)
    MEM_W(-0X49A8, ctx->r1) = ctx->r24;
    // 0x8004F450: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004F454: sw          $zero, -0x49A0($at)
    MEM_W(-0X49A0, ctx->r1) = 0;
    // 0x8004F458: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004F45C: addiu       $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
    // 0x8004F460: addiu       $t1, $zero, 0x0
    ctx->r9 = ADD32(0, 0X0);
    // 0x8004F464: sw          $t1, -0x4994($at)
    MEM_W(-0X4994, ctx->r1) = ctx->r9;
    // 0x8004F468: sw          $t0, -0x4998($at)
    MEM_W(-0X4998, ctx->r1) = ctx->r8;
    // 0x8004F46C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8004F470: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x8004F474: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004F478: addiu       $t3, $t3, -0x49B8
    ctx->r11 = ADD32(ctx->r11, -0X49B8);
    // 0x8004F47C: sll         $t2, $v0, 4
    ctx->r10 = S32(ctx->r2 << 4);
    // 0x8004F480: sw          $zero, -0x4990($at)
    MEM_W(-0X4990, ctx->r1) = 0;
    // 0x8004F484: addu        $v1, $t2, $t3
    ctx->r3 = ADD32(ctx->r10, ctx->r11);
    // 0x8004F488: addiu       $t4, $zero, 0x0
    ctx->r12 = ADD32(0, 0X0);
    // 0x8004F48C: addiu       $t5, $zero, 0x0
    ctx->r13 = ADD32(0, 0X0);
    // 0x8004F490: sw          $t6, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r14;
    // 0x8004F494: sw          $t7, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r15;
    // 0x8004F498: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
    // 0x8004F49C: sw          $t8, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r24;
    // 0x8004F4A0: sw          $t9, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r25;
    // 0x8004F4A4: sw          $zero, 0x28($v1)
    MEM_W(0X28, ctx->r3) = 0;
    // 0x8004F4A8: sw          $t0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r8;
    // 0x8004F4AC: sw          $t1, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r9;
    // 0x8004F4B0: sw          $zero, 0x38($v1)
    MEM_W(0X38, ctx->r3) = 0;
    // 0x8004F4B4: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8004F4B8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8004F4BC: jr          $ra
    // 0x8004F4C0: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    TRACE_RETURN()
    return;
    // 0x8004F4C0: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
;}
RECOMP_FUNC void func_8004F4C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004F4C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004F4C8: andi        $t6, $a0, 0x1
    ctx->r14 = ctx->r4 & 0X1;
    // 0x8004F4CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004F4D0: beq         $t6, $zero, L_8004F508
    if (ctx->r14 == 0) {
        // 0x8004F4D4: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_8004F508;
    }
    // 0x8004F4D4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8004F4D8: jal         0x800564F0
    // 0x8004F4DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    osGetTime_recomp(rdram, ctx);
        goto after_0;
    // 0x8004F4DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8004F4E0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8004F4E4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8004F4E8: addiu       $t9, $t9, -0x49B8
    ctx->r25 = ADD32(ctx->r25, -0X49B8);
    // 0x8004F4EC: sra         $t7, $a1, 1
    ctx->r15 = S32(SIGNED(ctx->r5) >> 1);
    // 0x8004F4F0: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8004F4F4: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x8004F4F8: lw          $t1, 0x4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4);
    // 0x8004F4FC: subu        $t3, $v1, $t1
    ctx->r11 = SUB32(ctx->r3, ctx->r9);
    // 0x8004F500: b           L_8004F52C
    // 0x8004F504: sw          $t3, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r11;
        goto L_8004F52C;
    // 0x8004F504: sw          $t3, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r11;
L_8004F508:
    // 0x8004F508: jal         0x800564F0
    // 0x8004F50C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    osGetTime_recomp(rdram, ctx);
        goto after_1;
    // 0x8004F50C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x8004F510: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8004F514: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004F518: sra         $t5, $a1, 1
    ctx->r13 = S32(SIGNED(ctx->r5) >> 1);
    // 0x8004F51C: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x8004F520: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8004F524: sw          $v0, -0x49B8($at)
    MEM_W(-0X49B8, ctx->r1) = ctx->r2;
    // 0x8004F528: sw          $v1, -0x49B4($at)
    MEM_W(-0X49B4, ctx->r1) = ctx->r3;
L_8004F52C:
    // 0x8004F52C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004F530: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004F534: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8004F540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004F540: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8004F544: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8004F548: lh          $t0, 0x0($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X0);
    // 0x8004F54C: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x8004F550: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x8004F554: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8004F558: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8004F55C: beq         $t0, $zero, L_8004F588
    if (ctx->r8 == 0) {
        // 0x8004F560: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8004F588;
    }
    // 0x8004F560: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8004F564: lh          $v1, 0x0($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X0);
L_8004F568:
    // 0x8004F568: bnel        $a1, $v1, L_8004F57C
    if (ctx->r5 != ctx->r3) {
        // 0x8004F56C: lh          $v1, 0xA($v0)
        ctx->r3 = MEM_H(ctx->r2, 0XA);
            goto L_8004F57C;
    }
    goto skip_0;
    // 0x8004F56C: lh          $v1, 0xA($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XA);
    skip_0:
    // 0x8004F570: jr          $ra
    // 0x8004F574: sh          $a2, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r6;
    TRACE_RETURN()
    return;
    // 0x8004F574: sh          $a2, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r6;
    // 0x8004F578: lh          $v1, 0xA($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XA);
L_8004F57C:
    // 0x8004F57C: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x8004F580: bne         $v1, $zero, L_8004F568
    if (ctx->r3 != 0) {
        // 0x8004F584: nop
    
            goto L_8004F568;
    }
    // 0x8004F584: nop

L_8004F588:
    // 0x8004F588: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8004F590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004F590: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8004F594: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8004F598: lui         $s3, 0x8007
    ctx->r19 = S32(0X8007 << 16);
    // 0x8004F59C: addiu       $s3, $s3, 0x2EF0
    ctx->r19 = ADD32(ctx->r19, 0X2EF0);
    // 0x8004F5A0: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x8004F5A4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8004F5A8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8004F5AC: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8004F5B0: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8004F5B4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8004F5B8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8004F5BC: beq         $t6, $zero, L_8004F61C
    if (ctx->r14 == 0) {
        // 0x8004F5C0: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8004F61C;
    }
    // 0x8004F5C0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8004F5C4: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x8004F5C8: addiu       $s0, $t7, 0x2EF0
    ctx->r16 = ADD32(ctx->r15, 0X2EF0);
    // 0x8004F5CC: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x8004F5D0: addiu       $s4, $s4, -0x6B90
    ctx->r20 = ADD32(ctx->r20, -0X6B90);
    // 0x8004F5D4: lw          $s2, 0x0($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X0);
    // 0x8004F5D8: addiu       $s5, $zero, 0xC
    ctx->r21 = ADD32(0, 0XC);
    // 0x8004F5DC: lh          $t8, 0x0($s4)
    ctx->r24 = MEM_H(ctx->r20, 0X0);
L_8004F5E0:
    // 0x8004F5E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8004F5E4: lh          $a1, 0x4($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4);
    // 0x8004F5E8: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8004F5EC: addu        $t0, $s0, $t9
    ctx->r8 = ADD32(ctx->r16, ctx->r25);
    // 0x8004F5F0: jal         0x8004F540
    // 0x8004F5F4: lh          $a2, 0x6($t0)
    ctx->r6 = MEM_H(ctx->r8, 0X6);
    func_8004F540(rdram, ctx);
        goto after_0;
    // 0x8004F5F4: lh          $a2, 0x6($t0)
    ctx->r6 = MEM_H(ctx->r8, 0X6);
    after_0:
    // 0x8004F5F8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8004F5FC: sll         $t1, $s1, 16
    ctx->r9 = S32(ctx->r17 << 16);
    // 0x8004F600: sra         $s1, $t1, 16
    ctx->r17 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8004F604: multu       $s1, $s5
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004F608: mflo        $t3
    ctx->r11 = lo;
    // 0x8004F60C: addu        $s0, $s3, $t3
    ctx->r16 = ADD32(ctx->r19, ctx->r11);
    // 0x8004F610: lw          $s2, 0x0($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X0);
    // 0x8004F614: bnel        $s2, $zero, L_8004F5E0
    if (ctx->r18 != 0) {
        // 0x8004F618: lh          $t8, 0x0($s4)
        ctx->r24 = MEM_H(ctx->r20, 0X0);
            goto L_8004F5E0;
    }
    goto skip_0;
    // 0x8004F618: lh          $t8, 0x0($s4)
    ctx->r24 = MEM_H(ctx->r20, 0X0);
    skip_0:
L_8004F61C:
    // 0x8004F61C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8004F620: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8004F624: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8004F628: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8004F62C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8004F630: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8004F634: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8004F638: jr          $ra
    // 0x8004F63C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    TRACE_RETURN()
    return;
    // 0x8004F63C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8004F640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004F640: jr          $ra
    // 0x8004F644: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
    TRACE_RETURN()
    return;
    // 0x8004F644: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
;}
RECOMP_FUNC void func_8004F650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004F650: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x8004F654: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x8004F658: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8004F65C: lwc1        $f10, 0x0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8004F660: sra         $t6, $v0, 22
    ctx->r14 = S32(SIGNED(ctx->r2) >> 22);
    // 0x8004F664: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x8004F668: slti        $at, $t7, 0x136
    ctx->r1 = SIGNED(ctx->r15) < 0X136 ? 1 : 0;
    // 0x8004F66C: beql        $at, $zero, L_8004F794
    if (ctx->r1 == 0) {
        // 0x8004F670: c.eq.s      $f10, $f10
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f10.fl == ctx->f10.fl;
            goto L_8004F794;
    }
    goto skip_0;
    // 0x8004F670: c.eq.s      $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f10.fl == ctx->f10.fl;
    skip_0:
    // 0x8004F674: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004F678: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8004F67C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8004F680: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8004F684: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8004F688: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8004F68C: bc1fl       L_8004F6A0
    if (!c1cs) {
        // 0x8004F690: neg.s       $f0, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
            goto L_8004F6A0;
    }
    goto skip_1;
    // 0x8004F690: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    skip_1:
    // 0x8004F694: b           L_8004F6A0
    // 0x8004F698: mov.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
        goto L_8004F6A0;
    // 0x8004F698: mov.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
    // 0x8004F69C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_8004F6A0:
    // 0x8004F6A0: ldc1        $f8, -0x6F78($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X6F78);
    // 0x8004F6A4: cvt.d.s     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.d = CVT_D_S(ctx->f0.fl);
    // 0x8004F6A8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004F6AC: mul.d       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f12.d, ctx->f8.d);
    // 0x8004F6B0: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8004F6B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004F6B8: add.d       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f14.d = ctx->f10.d + ctx->f18.d;
    // 0x8004F6BC: c.le.d      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.d <= ctx->f14.d;
    // 0x8004F6C0: nop

    // 0x8004F6C4: bc1fl       L_8004F6E4
    if (!c1cs) {
        // 0x8004F6C8: sub.d       $f10, $f14, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f14.d - ctx->f18.d;
            goto L_8004F6E4;
    }
    goto skip_2;
    // 0x8004F6C8: sub.d       $f10, $f14, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f14.d - ctx->f18.d;
    skip_2:
    // 0x8004F6CC: add.d       $f6, $f14, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f14.d + ctx->f18.d;
    // 0x8004F6D0: trunc.w.d   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x8004F6D4: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8004F6D8: b           L_8004F6F4
    // 0x8004F6DC: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
        goto L_8004F6F4;
    // 0x8004F6DC: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8004F6E0: sub.d       $f10, $f14, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f14.d - ctx->f18.d;
L_8004F6E4:
    // 0x8004F6E4: trunc.w.d   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x8004F6E8: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8004F6EC: nop

    // 0x8004F6F0: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
L_8004F6F4:
    // 0x8004F6F4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8004F6F8: ldc1        $f10, -0x6F70($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X6F70);
    // 0x8004F6FC: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x8004F700: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8004F704: ldc1        $f6, -0x6F68($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X6F68);
    // 0x8004F708: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8004F70C: addiu       $v1, $v1, -0x6FA0
    ctx->r3 = ADD32(ctx->r3, -0X6FA0);
    // 0x8004F710: sub.d       $f0, $f8, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = ctx->f8.d - ctx->f18.d;
    // 0x8004F714: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x8004F718: mul.d       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f10.d);
    // 0x8004F71C: ldc1        $f10, 0x20($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X20);
    // 0x8004F720: mul.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x8004F724: ldc1        $f6, 0x18($v1)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r3, 0X18);
    // 0x8004F728: sub.d       $f2, $f12, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f12.d - ctx->f4.d;
    // 0x8004F72C: sub.d       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f2.d = ctx->f2.d - ctx->f8.d;
    // 0x8004F730: mul.d       $f14, $f2, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f14.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x8004F734: nop

    // 0x8004F738: mul.d       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f14.d);
    // 0x8004F73C: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x8004F740: ldc1        $f4, 0x10($v1)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r3, 0X10);
    // 0x8004F744: mul.d       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x8004F748: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x8004F74C: ldc1        $f10, 0x8($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X8);
    // 0x8004F750: mul.d       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f14.d);
    // 0x8004F754: bne         $t0, $zero, L_8004F774
    if (ctx->r8 != 0) {
        // 0x8004F758: add.d       $f16, $f10, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d + ctx->f8.d;
            goto L_8004F774;
    }
    // 0x8004F758: add.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d + ctx->f8.d;
    // 0x8004F75C: mul.d       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f14.d);
    // 0x8004F760: nop

    // 0x8004F764: mul.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x8004F768: add.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f6.d + ctx->f2.d;
    // 0x8004F76C: jr          $ra
    // 0x8004F770: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    TRACE_RETURN()
    return;
    // 0x8004F770: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_8004F774:
    // 0x8004F774: mul.d       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f14.d);
    // 0x8004F778: nop

    // 0x8004F77C: mul.d       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x8004F780: add.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f4.d + ctx->f2.d;
    // 0x8004F784: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x8004F788: jr          $ra
    // 0x8004F78C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    TRACE_RETURN()
    return;
    // 0x8004F78C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8004F790: c.eq.s      $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f10.fl == ctx->f10.fl;
L_8004F794:
    // 0x8004F794: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8004F798: bc1t        L_8004F7AC
    if (c1cs) {
        // 0x8004F79C: nop
    
            goto L_8004F7AC;
    }
    // 0x8004F79C: nop

    // 0x8004F7A0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8004F7A4: jr          $ra
    // 0x8004F7A8: lwc1        $f0, -0x6C20($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6C20);
    TRACE_RETURN()
    return;
    // 0x8004F7A8: lwc1        $f0, -0x6C20($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6C20);
L_8004F7AC:
    // 0x8004F7AC: lwc1        $f0, -0x6F60($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6F60);
    // 0x8004F7B0: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8004F7C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004F7C0: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x8004F7C4: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x8004F7C8: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8004F7CC: sra         $v1, $v0, 22
    ctx->r3 = S32(SIGNED(ctx->r2) >> 22);
    // 0x8004F7D0: andi        $t6, $v1, 0x1FF
    ctx->r14 = ctx->r3 & 0X1FF;
    // 0x8004F7D4: slti        $at, $t6, 0xFF
    ctx->r1 = SIGNED(ctx->r14) < 0XFF ? 1 : 0;
    // 0x8004F7D8: beq         $at, $zero, L_8004F840
    if (ctx->r1 == 0) {
        // 0x8004F7DC: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_8004F840;
    }
    // 0x8004F7DC: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x8004F7E0: slti        $at, $t6, 0xE6
    ctx->r1 = SIGNED(ctx->r14) < 0XE6 ? 1 : 0;
    // 0x8004F7E4: bne         $at, $zero, L_8004F838
    if (ctx->r1 != 0) {
        // 0x8004F7E8: cvt.d.s     $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
            goto L_8004F838;
    }
    // 0x8004F7E8: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x8004F7EC: mul.d       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x8004F7F0: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8004F7F4: addiu       $v1, $v1, -0x6F50
    ctx->r3 = ADD32(ctx->r3, -0X6F50);
    // 0x8004F7F8: ldc1        $f6, 0x20($v1)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r3, 0X20);
    // 0x8004F7FC: ldc1        $f10, 0x18($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X18);
    // 0x8004F800: ldc1        $f4, 0x10($v1)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r3, 0X10);
    // 0x8004F804: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x8004F808: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x8004F80C: ldc1        $f10, 0x8($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X8);
    // 0x8004F810: mul.d       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f12.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f12.d);
    // 0x8004F814: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x8004F818: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x8004F81C: add.d       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f14.d = ctx->f10.d + ctx->f8.d;
    // 0x8004F820: mul.d       $f16, $f2, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x8004F824: nop

    // 0x8004F828: mul.d       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f14.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f14.d);
    // 0x8004F82C: add.d       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f18.d + ctx->f2.d;
    // 0x8004F830: jr          $ra
    // 0x8004F834: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    TRACE_RETURN()
    return;
    // 0x8004F834: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
L_8004F838:
    // 0x8004F838: jr          $ra
    // 0x8004F83C: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
    TRACE_RETURN()
    return;
    // 0x8004F83C: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
L_8004F840:
    // 0x8004F840: slti        $at, $v1, 0x136
    ctx->r1 = SIGNED(ctx->r3) < 0X136 ? 1 : 0;
    // 0x8004F844: beq         $at, $zero, L_8004F958
    if (ctx->r1 == 0) {
        // 0x8004F848: lwc1        $f4, 0x0($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
            goto L_8004F958;
    }
    // 0x8004F848: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8004F84C: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8004F850: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8004F854: ldc1        $f10, -0x6F28($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X6F28);
    // 0x8004F858: cvt.d.s     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f2.d = CVT_D_S(ctx->f6.fl);
    // 0x8004F85C: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8004F860: mul.d       $f0, $f2, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f0.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x8004F864: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004F868: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8004F86C: c.le.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d <= ctx->f0.d;
    // 0x8004F870: nop

    // 0x8004F874: bc1fl       L_8004F8A4
    if (!c1cs) {
        // 0x8004F878: mtc1        $at, $f7
        ctx->f_odd[(7 - 1) * 2] = ctx->r1;
            goto L_8004F8A4;
    }
    goto skip_0;
    // 0x8004F878: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    skip_0:
    // 0x8004F87C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8004F880: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8004F884: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8004F888: nop

    // 0x8004F88C: add.d       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f0.d + ctx->f16.d;
    // 0x8004F890: trunc.w.d   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_D(ctx->f18.d);
    // 0x8004F894: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8004F898: b           L_8004F8C0
    // 0x8004F89C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
        goto L_8004F8C0;
    // 0x8004F89C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x8004F8A0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
L_8004F8A4:
    // 0x8004F8A4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004F8A8: nop

    // 0x8004F8AC: sub.d       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f0.d - ctx->f6.d;
    // 0x8004F8B0: trunc.w.d   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x8004F8B4: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8004F8B8: nop

    // 0x8004F8BC: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
L_8004F8C0:
    // 0x8004F8C0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8004F8C4: ldc1        $f18, -0x6F20($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X6F20);
    // 0x8004F8C8: cvt.d.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.d = CVT_D_W(ctx->f16.u32l);
    // 0x8004F8CC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8004F8D0: ldc1        $f6, -0x6F18($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X6F18);
    // 0x8004F8D4: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8004F8D8: addiu       $v1, $v1, -0x6F50
    ctx->r3 = ADD32(ctx->r3, -0X6F50);
    // 0x8004F8DC: mul.d       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f18.d);
    // 0x8004F8E0: ldc1        $f8, 0x20($v1)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r3, 0X20);
    // 0x8004F8E4: ldc1        $f18, 0x18($v1)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r3, 0X18);
    // 0x8004F8E8: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x8004F8EC: mul.d       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x8004F8F0: sub.d       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f2.d - ctx->f4.d;
    // 0x8004F8F4: sub.d       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f2.d = ctx->f2.d - ctx->f10.d;
    // 0x8004F8F8: ldc1        $f10, 0x10($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X10);
    // 0x8004F8FC: mul.d       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x8004F900: nop

    // 0x8004F904: mul.d       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x8004F908: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x8004F90C: ldc1        $f18, 0x8($v1)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r3, 0X8);
    // 0x8004F910: mul.d       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f12.d);
    // 0x8004F914: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x8004F918: mul.d       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x8004F91C: bne         $t9, $zero, L_8004F93C
    if (ctx->r25 != 0) {
        // 0x8004F920: add.d       $f14, $f18, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f14.d = ctx->f18.d + ctx->f16.d;
            goto L_8004F93C;
    }
    // 0x8004F920: add.d       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f14.d = ctx->f18.d + ctx->f16.d;
    // 0x8004F924: mul.d       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x8004F928: nop

    // 0x8004F92C: mul.d       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f14.d);
    // 0x8004F930: add.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f6.d + ctx->f2.d;
    // 0x8004F934: jr          $ra
    // 0x8004F938: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    TRACE_RETURN()
    return;
    // 0x8004F938: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_8004F93C:
    // 0x8004F93C: mul.d       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x8004F940: nop

    // 0x8004F944: mul.d       $f18, $f8, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x8004F948: add.d       $f16, $f18, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = ctx->f18.d + ctx->f2.d;
    // 0x8004F94C: cvt.s.d     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f0.fl = CVT_S_D(ctx->f16.d);
    // 0x8004F950: jr          $ra
    // 0x8004F954: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    TRACE_RETURN()
    return;
    // 0x8004F954: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_8004F958:
    // 0x8004F958: c.eq.s      $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f4.fl == ctx->f4.fl;
    // 0x8004F95C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8004F960: bc1t        L_8004F974
    if (c1cs) {
        // 0x8004F964: nop
    
            goto L_8004F974;
    }
    // 0x8004F964: nop

    // 0x8004F968: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8004F96C: jr          $ra
    // 0x8004F970: lwc1        $f0, -0x6C20($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6C20);
    TRACE_RETURN()
    return;
    // 0x8004F970: lwc1        $f0, -0x6C20($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6C20);
L_8004F974:
    // 0x8004F974: lwc1        $f0, -0x6F10($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6F10);
    // 0x8004F978: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8004F980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004F980: jr          $ra
    // 0x8004F984: lh          $v0, 0x32($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X32);
    TRACE_RETURN()
    return;
    // 0x8004F984: lh          $v0, 0x32($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X32);
;}
RECOMP_FUNC void func_8004FB70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004FB70: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8004FB74: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8004FB78: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8004FB7C: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8004FB80: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x8004FB84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8004FB88: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8004FB8C: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x8004FB90: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x8004FB94: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x8004FB98: sw          $t8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r24;
    // 0x8004FB9C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
L_8004FBA0:
    // 0x8004FBA0: lw          $t9, 0xC($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XC);
    // 0x8004FBA4: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8004FBA8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8004FBAC: sw          $t9, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r25;
    // 0x8004FBB0: lw          $t1, 0x4C($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X4C);
    // 0x8004FBB4: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8004FBB8: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x8004FBBC: sw          $t1, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r9;
    // 0x8004FBC0: lbu         $t2, 0x8C($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X8C);
    // 0x8004FBC4: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x8004FBC8: sb          $t2, 0x96($a3)
    MEM_B(0X96, ctx->r7) = ctx->r10;
    // 0x8004FBCC: lbu         $t3, 0x9A($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X9A);
    // 0x8004FBD0: sb          $t3, 0xA6($a3)
    MEM_B(0XA6, ctx->r7) = ctx->r11;
    // 0x8004FBD4: lw          $t4, 0xA4($a2)
    ctx->r12 = MEM_W(ctx->r6, 0XA4);
    // 0x8004FBD8: sw          $t4, 0xB0($v1)
    MEM_W(0XB0, ctx->r3) = ctx->r12;
    // 0x8004FBDC: lw          $t5, 0x8($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X8);
    // 0x8004FBE0: sw          $t5, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r13;
    // 0x8004FBE4: lw          $t6, 0x48($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X48);
    // 0x8004FBE8: sw          $t6, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r14;
    // 0x8004FBEC: lbu         $t7, 0x8B($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X8B);
    // 0x8004FBF0: sb          $t7, 0x97($a3)
    MEM_B(0X97, ctx->r7) = ctx->r15;
    // 0x8004FBF4: lbu         $t8, 0x9B($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X9B);
    // 0x8004FBF8: sb          $t8, 0xA7($a3)
    MEM_B(0XA7, ctx->r7) = ctx->r24;
    // 0x8004FBFC: lw          $t9, 0xA8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XA8);
    // 0x8004FC00: bne         $v0, $a0, L_8004FBA0
    if (ctx->r2 != ctx->r4) {
        // 0x8004FC04: sw          $t9, 0xB4($v1)
        MEM_W(0XB4, ctx->r3) = ctx->r25;
            goto L_8004FBA0;
    }
    // 0x8004FC04: sw          $t9, 0xB4($v1)
    MEM_W(0XB4, ctx->r3) = ctx->r25;
    // 0x8004FC08: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8004FC10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004FC10: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x8004FC14: lbu         $t6, 0x98($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X98);
    // 0x8004FC18: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8004FC1C: addu        $a2, $a0, $t7
    ctx->r6 = ADD32(ctx->r4, ctx->r15);
    // 0x8004FC20: beql        $t6, $zero, L_8004FC58
    if (ctx->r14 == 0) {
        // 0x8004FC24: lw          $a3, 0x18($a2)
        ctx->r7 = MEM_W(ctx->r6, 0X18);
            goto L_8004FC58;
    }
    goto skip_0;
    // 0x8004FC24: lw          $a3, 0x18($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X18);
    skip_0:
    // 0x8004FC28: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8004FC2C: addu        $a2, $a0, $t7
    ctx->r6 = ADD32(ctx->r4, ctx->r15);
    // 0x8004FC30: lw          $a3, 0x58($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X58);
    // 0x8004FC34: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x8004FC38: addiu       $t8, $a3, 0x1
    ctx->r24 = ADD32(ctx->r7, 0X1);
    // 0x8004FC3C: sw          $t8, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->r24;
    // 0x8004FC40: lbu         $t9, 0x98($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X98);
    // 0x8004FC44: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x8004FC48: sb          $t6, 0x98($v0)
    MEM_B(0X98, ctx->r2) = ctx->r14;
    // 0x8004FC4C: jr          $ra
    // 0x8004FC50: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    TRACE_RETURN()
    return;
    // 0x8004FC50: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8004FC54: lw          $a3, 0x18($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X18);
L_8004FC58:
    // 0x8004FC58: addiu       $t0, $zero, 0xFE
    ctx->r8 = ADD32(0, 0XFE);
    // 0x8004FC5C: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x8004FC60: addiu       $t8, $a3, 0x1
    ctx->r24 = ADD32(ctx->r7, 0X1);
    // 0x8004FC64: sw          $t8, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r24;
    // 0x8004FC68: bne         $t0, $v1, L_8004FCCC
    if (ctx->r8 != ctx->r3) {
        // 0x8004FC6C: nop
    
            goto L_8004FCCC;
    }
    // 0x8004FC6C: nop

    // 0x8004FC70: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    // 0x8004FC74: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8004FC78: sw          $t9, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r25;
    // 0x8004FC7C: beq         $t0, $a0, L_8004FCCC
    if (ctx->r8 == ctx->r4) {
        // 0x8004FC80: addiu       $t6, $t9, 0x1
        ctx->r14 = ADD32(ctx->r25, 0X1);
            goto L_8004FCCC;
    }
    // 0x8004FC80: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x8004FC84: lbu         $v1, 0x0($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X0);
    // 0x8004FC88: sw          $t6, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r14;
    // 0x8004FC8C: lbu         $a1, 0x0($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X0);
    // 0x8004FC90: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8004FC94: sll         $t9, $a0, 8
    ctx->r25 = S32(ctx->r4 << 8);
    // 0x8004FC98: sw          $t7, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r15;
    // 0x8004FC9C: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x8004FCA0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8004FCA4: addiu       $t9, $t7, -0x4
    ctx->r25 = ADD32(ctx->r15, -0X4);
    // 0x8004FCA8: sw          $t9, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->r25;
    // 0x8004FCAC: sb          $a1, 0x98($v0)
    MEM_B(0X98, ctx->r2) = ctx->r5;
    // 0x8004FCB0: lw          $a3, 0x58($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X58);
    // 0x8004FCB4: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x8004FCB8: addiu       $t8, $a3, 0x1
    ctx->r24 = ADD32(ctx->r7, 0X1);
    // 0x8004FCBC: sw          $t8, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->r24;
    // 0x8004FCC0: lbu         $t6, 0x98($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X98);
    // 0x8004FCC4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8004FCC8: sb          $t7, 0x98($v0)
    MEM_B(0X98, ctx->r2) = ctx->r15;
L_8004FCCC:
    // 0x8004FCCC: jr          $ra
    // 0x8004FCD0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    TRACE_RETURN()
    return;
    // 0x8004FCD0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8004FCD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004FCD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004FCD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004FCDC: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x8004FCE0: jal         0x8004FC10
    // 0x8004FCE4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    func_8004FC10(rdram, ctx);
        goto after_0;
    // 0x8004FCE4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_0:
    // 0x8004FCE8: andi        $t6, $v0, 0x80
    ctx->r14 = ctx->r2 & 0X80;
    // 0x8004FCEC: beq         $t6, $zero, L_8004FD18
    if (ctx->r14 == 0) {
        // 0x8004FCF0: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_8004FD18;
    }
    // 0x8004FCF0: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x8004FCF4: andi        $t1, $v0, 0x7F
    ctx->r9 = ctx->r2 & 0X7F;
L_8004FCF8:
    // 0x8004FCF8: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x8004FCFC: jal         0x8004FC10
    // 0x8004FD00: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    func_8004FC10(rdram, ctx);
        goto after_1;
    // 0x8004FD00: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_1:
    // 0x8004FD04: sll         $t7, $t1, 7
    ctx->r15 = S32(ctx->r9 << 7);
    // 0x8004FD08: andi        $t8, $v0, 0x7F
    ctx->r24 = ctx->r2 & 0X7F;
    // 0x8004FD0C: andi        $t9, $v0, 0x80
    ctx->r25 = ctx->r2 & 0X80;
    // 0x8004FD10: bne         $t9, $zero, L_8004FCF8
    if (ctx->r25 != 0) {
        // 0x8004FD14: addu        $t1, $t7, $t8
        ctx->r9 = ADD32(ctx->r15, ctx->r24);
            goto L_8004FCF8;
    }
    // 0x8004FD14: addu        $t1, $t7, $t8
    ctx->r9 = ADD32(ctx->r15, ctx->r24);
L_8004FD18:
    // 0x8004FD18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004FD1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004FD20: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8004FD24: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8004FD2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004FD2C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8004FD34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004FD34: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8004FD38: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004FD3C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8004FD40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004FD44: or          $t4, $a0, $zero
    ctx->r12 = ctx->r4 | 0;
    // 0x8004FD48: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8004FD4C: lw          $a2, 0x10($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X10);
    // 0x8004FD50: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8004FD54: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8004FD58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8004FD5C: lw          $t6, 0x4($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X4);
L_8004FD60:
    // 0x8004FD60: srlv        $t7, $t6, $v0
    ctx->r15 = S32(U32(ctx->r14) >> (ctx->r2 & 31));
    // 0x8004FD64: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8004FD68: beql        $t8, $zero, L_8004FDAC
    if (ctx->r24 == 0) {
        // 0x8004FD6C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8004FDAC;
    }
    goto skip_0;
    // 0x8004FD6C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x8004FD70: lw          $t6, 0x14($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X14);
    // 0x8004FD74: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8004FD78: addu        $v1, $t4, $t9
    ctx->r3 = ADD32(ctx->r12, ctx->r25);
    // 0x8004FD7C: beql        $t6, $zero, L_8004FD94
    if (ctx->r14 == 0) {
        // 0x8004FD80: lw          $a0, 0xB8($v1)
        ctx->r4 = MEM_W(ctx->r3, 0XB8);
            goto L_8004FD94;
    }
    goto skip_1;
    // 0x8004FD80: lw          $a0, 0xB8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XB8);
    skip_1:
    // 0x8004FD84: lw          $t7, 0xB8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XB8);
    // 0x8004FD88: subu        $t8, $t7, $a2
    ctx->r24 = SUB32(ctx->r15, ctx->r6);
    // 0x8004FD8C: sw          $t8, 0xB8($v1)
    MEM_W(0XB8, ctx->r3) = ctx->r24;
    // 0x8004FD90: lw          $a0, 0xB8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XB8);
L_8004FD94:
    // 0x8004FD94: sltu        $at, $a0, $t1
    ctx->r1 = ctx->r4 < ctx->r9 ? 1 : 0;
    // 0x8004FD98: beql        $at, $zero, L_8004FDAC
    if (ctx->r1 == 0) {
        // 0x8004FD9C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8004FDAC;
    }
    goto skip_2;
    // 0x8004FD9C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_2:
    // 0x8004FDA0: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
    // 0x8004FDA4: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x8004FDA8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8004FDAC:
    // 0x8004FDAC: bnel        $v0, $a1, L_8004FD60
    if (ctx->r2 != ctx->r5) {
        // 0x8004FDB0: lw          $t6, 0x4($t4)
        ctx->r14 = MEM_W(ctx->r12, 0X4);
            goto L_8004FD60;
    }
    goto skip_3;
    // 0x8004FDB0: lw          $t6, 0x4($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X4);
    skip_3:
    // 0x8004FDB4: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8004FDB8: jal         0x8004FC10
    // 0x8004FDBC: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    func_8004FC10(rdram, ctx);
        goto after_0;
    // 0x8004FDBC: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_0:
    // 0x8004FDC0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8004FDC4: andi        $t2, $v0, 0xFF
    ctx->r10 = ctx->r2 & 0XFF;
    // 0x8004FDC8: bne         $v0, $at, L_8004FF34
    if (ctx->r2 != ctx->r1) {
        // 0x8004FDCC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8004FF34;
    }
    // 0x8004FDCC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8004FDD0: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8004FDD4: jal         0x8004FC10
    // 0x8004FDD8: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    func_8004FC10(rdram, ctx);
        goto after_1;
    // 0x8004FDD8: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_1:
    // 0x8004FDDC: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x8004FDE0: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    // 0x8004FDE4: bne         $v0, $at, L_8004FE38
    if (ctx->r2 != ctx->r1) {
        // 0x8004FDE8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8004FE38;
    }
    // 0x8004FDE8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8004FDEC: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8004FDF0: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x8004FDF4: sb          $t2, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r10;
    // 0x8004FDF8: sb          $a2, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r6;
    // 0x8004FDFC: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8004FE00: jal         0x8004FC10
    // 0x8004FE04: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    func_8004FC10(rdram, ctx);
        goto after_2;
    // 0x8004FE04: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_2:
    // 0x8004FE08: sb          $v0, 0xB($s0)
    MEM_B(0XB, ctx->r16) = ctx->r2;
    // 0x8004FE0C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8004FE10: jal         0x8004FC10
    // 0x8004FE14: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    func_8004FC10(rdram, ctx);
        goto after_3;
    // 0x8004FE14: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_3:
    // 0x8004FE18: sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // 0x8004FE1C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8004FE20: jal         0x8004FC10
    // 0x8004FE24: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    func_8004FC10(rdram, ctx);
        goto after_4;
    // 0x8004FE24: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_4:
    // 0x8004FE28: sb          $v0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r2;
    // 0x8004FE2C: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x8004FE30: b           L_8004FFD0
    // 0x8004FE34: sb          $zero, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = 0;
        goto L_8004FFD0;
    // 0x8004FE34: sb          $zero, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = 0;
L_8004FE38:
    // 0x8004FE38: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x8004FE3C: bnel        $v1, $at, L_8004FE78
    if (ctx->r3 != ctx->r1) {
        // 0x8004FE40: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_8004FE78;
    }
    goto skip_4;
    // 0x8004FE40: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    skip_4:
    // 0x8004FE44: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x8004FE48: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8004FE4C: sllv        $t9, $t8, $t3
    ctx->r25 = S32(ctx->r24 << (ctx->r11 & 31));
    // 0x8004FE50: xor         $t6, $t7, $t9
    ctx->r14 = ctx->r15 ^ ctx->r25;
    // 0x8004FE54: beq         $t6, $zero, L_8004FE68
    if (ctx->r14 == 0) {
        // 0x8004FE58: sw          $t6, 0x4($t4)
        MEM_W(0X4, ctx->r12) = ctx->r14;
            goto L_8004FE68;
    }
    // 0x8004FE58: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x8004FE5C: addiu       $t7, $zero, 0x12
    ctx->r15 = ADD32(0, 0X12);
    // 0x8004FE60: b           L_8004FFD0
    // 0x8004FE64: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
        goto L_8004FFD0;
    // 0x8004FE64: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
L_8004FE68:
    // 0x8004FE68: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8004FE6C: b           L_8004FFD0
    // 0x8004FE70: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
        goto L_8004FFD0;
    // 0x8004FE70: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x8004FE74: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
L_8004FE78:
    // 0x8004FE78: bne         $v1, $at, L_8004FEA8
    if (ctx->r3 != ctx->r1) {
        // 0x8004FE7C: or          $a0, $t4, $zero
        ctx->r4 = ctx->r12 | 0;
            goto L_8004FEA8;
    }
    // 0x8004FE7C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8004FE80: jal         0x8004FC10
    // 0x8004FE84: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    func_8004FC10(rdram, ctx);
        goto after_5;
    // 0x8004FE84: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_5:
    // 0x8004FE88: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8004FE8C: jal         0x8004FC10
    // 0x8004FE90: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    func_8004FC10(rdram, ctx);
        goto after_6;
    // 0x8004FE90: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_6:
    // 0x8004FE94: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x8004FE98: sb          $zero, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = 0;
    // 0x8004FE9C: addiu       $t8, $zero, 0x13
    ctx->r24 = ADD32(0, 0X13);
    // 0x8004FEA0: b           L_8004FFD0
    // 0x8004FEA4: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
        goto L_8004FFD0;
    // 0x8004FEA4: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
L_8004FEA8:
    // 0x8004FEA8: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x8004FEAC: bne         $v1, $at, L_8004FFD0
    if (ctx->r3 != ctx->r1) {
        // 0x8004FEB0: sll         $t7, $t3, 2
        ctx->r15 = S32(ctx->r11 << 2);
            goto L_8004FFD0;
    }
    // 0x8004FEB0: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x8004FEB4: addu        $t5, $t4, $t7
    ctx->r13 = ADD32(ctx->r12, ctx->r15);
    // 0x8004FEB8: lw          $v0, 0x18($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X18);
    // 0x8004FEBC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8004FEC0: lbu         $a0, 0x1($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X1);
    // 0x8004FEC4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004FEC8: addiu       $t9, $v0, 0x5
    ctx->r25 = ADD32(ctx->r2, 0X5);
    // 0x8004FECC: bne         $a0, $zero, L_8004FEE0
    if (ctx->r4 != 0) {
        // 0x8004FED0: lbu         $a1, -0x1($v0)
        ctx->r5 = MEM_BU(ctx->r2, -0X1);
            goto L_8004FEE0;
    }
    // 0x8004FED0: lbu         $a1, -0x1($v0)
    ctx->r5 = MEM_BU(ctx->r2, -0X1);
    // 0x8004FED4: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
    // 0x8004FED8: b           L_8004FF20
    // 0x8004FEDC: sw          $t9, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r25;
        goto L_8004FF20;
    // 0x8004FEDC: sw          $t9, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r25;
L_8004FEE0:
    // 0x8004FEE0: beq         $a0, $at, L_8004FEEC
    if (ctx->r4 == ctx->r1) {
        // 0x8004FEE4: addiu       $t6, $a0, -0x1
        ctx->r14 = ADD32(ctx->r4, -0X1);
            goto L_8004FEEC;
    }
    // 0x8004FEE4: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x8004FEE8: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
L_8004FEEC:
    // 0x8004FEEC: lbu         $t7, 0x2($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2);
    // 0x8004FEF0: lbu         $v1, 0x1($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X1);
    // 0x8004FEF4: lbu         $t6, 0x3($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X3);
    // 0x8004FEF8: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x8004FEFC: sll         $t8, $v1, 24
    ctx->r24 = S32(ctx->r3 << 24);
    // 0x8004FF00: lbu         $t7, 0x4($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4);
    // 0x8004FF04: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x8004FF08: sll         $t8, $t6, 8
    ctx->r24 = S32(ctx->r14 << 8);
    // 0x8004FF0C: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x8004FF10: addiu       $v0, $v0, 0x5
    ctx->r2 = ADD32(ctx->r2, 0X5);
    // 0x8004FF14: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x8004FF18: subu        $t9, $v0, $v1
    ctx->r25 = SUB32(ctx->r2, ctx->r3);
    // 0x8004FF1C: sw          $t9, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r25;
L_8004FF20:
    // 0x8004FF20: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x8004FF24: sb          $zero, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = 0;
    // 0x8004FF28: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x8004FF2C: b           L_8004FFD0
    // 0x8004FF30: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
        goto L_8004FFD0;
    // 0x8004FF30: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
L_8004FF34:
    // 0x8004FF34: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8004FF38: andi        $t9, $v1, 0x80
    ctx->r25 = ctx->r3 & 0X80;
    // 0x8004FF3C: beq         $t9, $zero, L_8004FF64
    if (ctx->r25 == 0) {
        // 0x8004FF40: sh          $t7, 0x0($s0)
        MEM_H(0X0, ctx->r16) = ctx->r15;
            goto L_8004FF64;
    }
    // 0x8004FF40: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
    // 0x8004FF44: sb          $t2, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r10;
    // 0x8004FF48: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8004FF4C: jal         0x8004FC10
    // 0x8004FF50: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    func_8004FC10(rdram, ctx);
        goto after_7;
    // 0x8004FF50: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_7:
    // 0x8004FF54: sb          $v0, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r2;
    // 0x8004FF58: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x8004FF5C: b           L_8004FF74
    // 0x8004FF60: sb          $t2, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = ctx->r10;
        goto L_8004FF74;
    // 0x8004FF60: sb          $t2, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = ctx->r10;
L_8004FF64:
    // 0x8004FF64: addu        $t8, $t4, $t3
    ctx->r24 = ADD32(ctx->r12, ctx->r11);
    // 0x8004FF68: lbu         $t7, 0xA8($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0XA8);
    // 0x8004FF6C: sb          $v0, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r2;
    // 0x8004FF70: sb          $t7, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r15;
L_8004FF74:
    // 0x8004FF74: lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X8);
    // 0x8004FF78: addiu       $at, $zero, 0xC0
    ctx->r1 = ADD32(0, 0XC0);
    // 0x8004FF7C: andi        $t9, $v0, 0xF0
    ctx->r25 = ctx->r2 & 0XF0;
    // 0x8004FF80: beq         $t9, $at, L_8004FFCC
    if (ctx->r25 == ctx->r1) {
        // 0x8004FF84: addiu       $at, $zero, 0xD0
        ctx->r1 = ADD32(0, 0XD0);
            goto L_8004FFCC;
    }
    // 0x8004FF84: addiu       $at, $zero, 0xD0
    ctx->r1 = ADD32(0, 0XD0);
    // 0x8004FF88: beq         $t9, $at, L_8004FFCC
    if (ctx->r25 == ctx->r1) {
        // 0x8004FF8C: or          $a0, $t4, $zero
        ctx->r4 = ctx->r12 | 0;
            goto L_8004FFCC;
    }
    // 0x8004FF8C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8004FF90: jal         0x8004FC10
    // 0x8004FF94: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    func_8004FC10(rdram, ctx);
        goto after_8;
    // 0x8004FF94: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_8:
    // 0x8004FF98: lbu         $t6, 0x8($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X8);
    // 0x8004FF9C: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x8004FFA0: sb          $v0, 0xA($s0)
    MEM_B(0XA, ctx->r16) = ctx->r2;
    // 0x8004FFA4: andi        $t8, $t6, 0xF0
    ctx->r24 = ctx->r14 & 0XF0;
    // 0x8004FFA8: bne         $t8, $at, L_8004FFD0
    if (ctx->r24 != ctx->r1) {
        // 0x8004FFAC: or          $t2, $t4, $zero
        ctx->r10 = ctx->r12 | 0;
            goto L_8004FFD0;
    }
    // 0x8004FFAC: or          $t2, $t4, $zero
    ctx->r10 = ctx->r12 | 0;
    // 0x8004FFB0: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8004FFB4: jal         0x8004FCD4
    // 0x8004FFB8: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    func_8004FCD4(rdram, ctx);
        goto after_9;
    // 0x8004FFB8: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    after_9:
    // 0x8004FFBC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8004FFC0: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8004FFC4: b           L_8004FFD0
    // 0x8004FFC8: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
        goto L_8004FFD0;
    // 0x8004FFC8: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
L_8004FFCC:
    // 0x8004FFCC: sb          $zero, 0xA($s0)
    MEM_B(0XA, ctx->r16) = 0;
L_8004FFD0:
    // 0x8004FFD0: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
    // 0x8004FFD4: lw          $t7, 0xC($t4)
    ctx->r15 = MEM_W(ctx->r12, 0XC);
    // 0x8004FFD8: sw          $t1, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r9;
    // 0x8004FFDC: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x8004FFE0: addu        $t9, $t7, $t1
    ctx->r25 = ADD32(ctx->r15, ctx->r9);
    // 0x8004FFE4: sw          $t9, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r25;
    // 0x8004FFE8: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x8004FFEC: or          $t2, $t4, $zero
    ctx->r10 = ctx->r12 | 0;
    // 0x8004FFF0: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x8004FFF4: beql        $t6, $at, L_80050014
    if (ctx->r14 == ctx->r1) {
        // 0x8004FFF8: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80050014;
    }
    goto skip_5;
    // 0x8004FFF8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    skip_5:
    // 0x8004FFFC: jal         0x8004FCD4
    // 0x80050000: addu        $t5, $t4, $t8
    ctx->r13 = ADD32(ctx->r12, ctx->r24);
    func_8004FCD4(rdram, ctx);
        goto after_10;
    // 0x80050000: addu        $t5, $t4, $t8
    ctx->r13 = ADD32(ctx->r12, ctx->r24);
    after_10:
    // 0x80050004: lw          $t7, 0xB8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0XB8);
    // 0x80050008: addu        $t9, $t7, $v0
    ctx->r25 = ADD32(ctx->r15, ctx->r2);
    // 0x8005000C: sw          $t9, 0xB8($t5)
    MEM_W(0XB8, ctx->r13) = ctx->r25;
    // 0x80050010: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_80050014:
    // 0x80050014: sw          $t6, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r14;
    // 0x80050018: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005001C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80050020: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80050024: jr          $ra
    TRACE_RETURN()
    return;
;}
