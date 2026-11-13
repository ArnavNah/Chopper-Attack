#include "recomp.h"
#include "trace.h"
#include "funcs.h"

RECOMP_FUNC void func_8000D834(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000D834: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x8000D838: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8000D83C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8000D840: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8000D844: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8000D848: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8000D84C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8000D850: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8000D854: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8000D858: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8000D85C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8000D860: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8000D864: sw          $a0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r4;
    // 0x8000D868: sw          $a1, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r5;
    // 0x8000D86C: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8000D870: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8000D874: addiu       $a1, $sp, 0xF4
    ctx->r5 = ADD32(ctx->r29, 0XF4);
    // 0x8000D878: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8000D87C: addiu       $a0, $sp, 0xF8
    ctx->r4 = ADD32(ctx->r29, 0XF8);
    // 0x8000D880: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8000D884: nop

    // 0x8000D888: sw          $t7, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r15;
    // 0x8000D88C: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8000D890: sw          $zero, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = 0;
    // 0x8000D894: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8000D898: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8000D89C: jal         0x8004EE7C
    // 0x8000D8A0: sw          $t9, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r25;
    func_8004EE7C(rdram, ctx);
        goto after_0;
    // 0x8000D8A0: sw          $t9, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r25;
    after_0:
    // 0x8000D8A4: lw          $v1, 0xFC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XFC);
    // 0x8000D8A8: beq         $v0, $zero, L_8000DA90
    if (ctx->r2 == 0) {
        // 0x8000D8AC: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8000DA90;
    }
    // 0x8000D8AC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8000D8B0: lw          $t1, 0xF8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XF8);
    // 0x8000D8B4: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8000D8B8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8000D8BC: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x8000D8C0: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x8000D8C4: addiu       $s7, $sp, 0x9C
    ctx->r23 = ADD32(ctx->r29, 0X9C);
    // 0x8000D8C8: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8000D8CC: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x8000D8D0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8000D8D4: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    // 0x8000D8D8: addiu       $a2, $sp, 0x84
    ctx->r6 = ADD32(ctx->r29, 0X84);
    // 0x8000D8DC: cvt.s.w     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000D8E0: swc1        $f0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f0.u32l;
    // 0x8000D8E4: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    // 0x8000D8E8: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8000D8EC: add.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f12.fl;
    // 0x8000D8F0: swc1        $f4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f4.u32l;
    // 0x8000D8F4: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8000D8F8: swc1        $f2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f2.u32l;
    // 0x8000D8FC: swc1        $f2, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f2.u32l;
    // 0x8000D900: sub.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x8000D904: sw          $v1, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r3;
    // 0x8000D908: jal         0x800034FC
    // 0x8000D90C: swc1        $f8, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f8.u32l;
    func_800034FC(rdram, ctx);
        goto after_1;
    // 0x8000D90C: swc1        $f8, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x8000D910: lh          $s6, 0x2($s1)
    ctx->r22 = MEM_H(ctx->r17, 0X2);
    // 0x8000D914: lw          $v1, 0xFC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XFC);
    // 0x8000D918: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x8000D91C: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x8000D920: blez        $s6, L_8000DA90
    if (SIGNED(ctx->r22) <= 0) {
        // 0x8000D924: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8000DA90;
    }
    // 0x8000D924: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8000D928: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000D92C: lwc1        $f20, 0x5EE0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X5EE0);
    // 0x8000D930: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8000D934: addiu       $fp, $sp, 0x78
    ctx->r30 = ADD32(ctx->r29, 0X78);
    // 0x8000D938: addiu       $s5, $sp, 0xB4
    ctx->r21 = ADD32(ctx->r29, 0XB4);
    // 0x8000D93C: addiu       $s2, $sp, 0xD8
    ctx->r18 = ADD32(ctx->r29, 0XD8);
    // 0x8000D940: addiu       $s1, $zero, 0x6
    ctx->r17 = ADD32(0, 0X6);
L_8000D944:
    // 0x8000D944: addiu       $a2, $sp, 0xB4
    ctx->r6 = ADD32(ctx->r29, 0XB4);
    // 0x8000D948: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8000D94C: lw          $a3, 0x104($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X104);
L_8000D950:
    // 0x8000D950: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x8000D954: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000D958: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8000D95C: addiu       $s1, $s1, -0x2
    ctx->r17 = ADD32(ctx->r17, -0X2);
    // 0x8000D960: beq         $v0, $s1, L_8000D9C0
    if (ctx->r2 == ctx->r17) {
        // 0x8000D964: lbu         $t3, 0x0($a1)
        ctx->r11 = MEM_BU(ctx->r5, 0X0);
            goto L_8000D9C0;
    }
    // 0x8000D964: lbu         $t3, 0x0($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X0);
L_8000D968:
    // 0x8000D968: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x8000D96C: addu        $t5, $s0, $t4
    ctx->r13 = ADD32(ctx->r16, ctx->r12);
    // 0x8000D970: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8000D974: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x8000D978: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000D97C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8000D980: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8000D984: nop

    // 0x8000D988: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000D98C: swc1        $f18, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
    // 0x8000D990: lbu         $t8, 0x0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X0);
    // 0x8000D994: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x8000D998: addu        $t1, $s0, $t9
    ctx->r9 = ADD32(ctx->r16, ctx->r25);
    // 0x8000D99C: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x8000D9A0: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x8000D9A4: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8000D9A8: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x8000D9AC: nop

    // 0x8000D9B0: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000D9B4: swc1        $f18, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f18.u32l;
    // 0x8000D9B8: bne         $v0, $s1, L_8000D968
    if (ctx->r2 != ctx->r17) {
        // 0x8000D9BC: lbu         $t3, 0x0($a1)
        ctx->r11 = MEM_BU(ctx->r5, 0X0);
            goto L_8000D968;
    }
    // 0x8000D9BC: lbu         $t3, 0x0($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X0);
L_8000D9C0:
    // 0x8000D9C0: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x8000D9C4: addu        $t5, $s0, $t4
    ctx->r13 = ADD32(ctx->r16, ctx->r12);
    // 0x8000D9C8: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8000D9CC: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x8000D9D0: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8000D9D4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000D9D8: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8000D9DC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8000D9E0: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000D9E4: swc1        $f18, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
    // 0x8000D9E8: lbu         $t8, 0x0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X0);
    // 0x8000D9EC: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x8000D9F0: addu        $t1, $s0, $t9
    ctx->r9 = ADD32(ctx->r16, ctx->r25);
    // 0x8000D9F4: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x8000D9F8: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x8000D9FC: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8000DA00: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x8000DA04: nop

    // 0x8000DA08: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000DA0C: swc1        $f18, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f18.u32l;
    // 0x8000DA10: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x8000DA14: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8000DA18: bne         $a2, $s2, L_8000D950
    if (ctx->r6 != ctx->r18) {
        // 0x8000DA1C: addiu       $a3, $a3, 0xC
        ctx->r7 = ADD32(ctx->r7, 0XC);
            goto L_8000D950;
    }
    // 0x8000DA1C: addiu       $a3, $a3, 0xC
    ctx->r7 = ADD32(ctx->r7, 0XC);
    // 0x8000DA20: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8000DA24: jal         0x8000D110
    // 0x8000DA28: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_8000D110(rdram, ctx);
        goto after_2;
    // 0x8000DA28: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_2:
    // 0x8000DA2C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8000DA30: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x8000DA34: jal         0x8000D1FC
    // 0x8000DA38: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_8000D1FC(rdram, ctx);
        goto after_3;
    // 0x8000DA38: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_3:
    // 0x8000DA3C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000DA40: bne         $v0, $at, L_8000DA84
    if (ctx->r2 != ctx->r1) {
        // 0x8000DA44: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8000DA84;
    }
    // 0x8000DA44: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000DA48: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x8000DA4C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8000DA50: addiu       $a2, $sp, 0xC0
    ctx->r6 = ADD32(ctx->r29, 0XC0);
    // 0x8000DA54: addiu       $a3, $sp, 0xCC
    ctx->r7 = ADD32(ctx->r29, 0XCC);
    // 0x8000DA58: jal         0x800037FC
    // 0x8000DA5C: sw          $v0, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r2;
    func_800037FC(rdram, ctx);
        goto after_4;
    // 0x8000DA5C: sw          $v0, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r2;
    after_4:
    // 0x8000DA60: lw          $a0, 0x100($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X100);
    // 0x8000DA64: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8000DA68: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8000DA6C: lw          $v1, 0xFC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XFC);
    // 0x8000DA70: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x8000DA74: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x8000DA78: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8000DA7C: b           L_8000DA90
    // 0x8000DA80: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
        goto L_8000DA90;
    // 0x8000DA80: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
L_8000DA84:
    // 0x8000DA84: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8000DA88: bne         $s3, $s6, L_8000D944
    if (ctx->r19 != ctx->r22) {
        // 0x8000DA8C: addiu       $s4, $s4, 0x3
        ctx->r20 = ADD32(ctx->r20, 0X3);
            goto L_8000D944;
    }
    // 0x8000DA8C: addiu       $s4, $s4, 0x3
    ctx->r20 = ADD32(ctx->r20, 0X3);
L_8000DA90:
    // 0x8000DA90: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8000DA94: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8000DA98: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8000DA9C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8000DAA0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8000DAA4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8000DAA8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8000DAAC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8000DAB0: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8000DAB4: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8000DAB8: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8000DABC: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    // 0x8000DAC0: jr          $ra
    // 0x8000DAC4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    TRACE_RETURN()
    return;
    // 0x8000DAC4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8000DAC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000DAC8: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x8000DACC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8000DAD0: lw          $s0, 0xE8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XE8);
    // 0x8000DAD4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8000DAD8: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8000DADC: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8000DAE0: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8000DAE4: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8000DAE8: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8000DAEC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8000DAF0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8000DAF4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8000DAF8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8000DAFC: sw          $a0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r4;
    // 0x8000DB00: sw          $a1, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r5;
    // 0x8000DB04: sw          $a2, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r6;
    // 0x8000DB08: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8000DB0C: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x8000DB10: addiu       $a1, $sp, 0xCC
    ctx->r5 = ADD32(ctx->r29, 0XCC);
    // 0x8000DB14: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8000DB18: addiu       $a0, $sp, 0xD0
    ctx->r4 = ADD32(ctx->r29, 0XD0);
    // 0x8000DB1C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8000DB20: nop

    // 0x8000DB24: sw          $t7, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r15;
    // 0x8000DB28: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8000DB2C: sw          $zero, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = 0;
    // 0x8000DB30: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8000DB34: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8000DB38: jal         0x8004EE7C
    // 0x8000DB3C: sw          $t9, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r25;
    func_8004EE7C(rdram, ctx);
        goto after_0;
    // 0x8000DB3C: sw          $t9, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r25;
    after_0:
    // 0x8000DB40: lw          $t0, 0xD4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XD4);
    // 0x8000DB44: beq         $v0, $zero, L_8000DD0C
    if (ctx->r2 == 0) {
        // 0x8000DB48: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8000DD0C;
    }
    // 0x8000DB48: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8000DB4C: addiu       $v0, $sp, 0x68
    ctx->r2 = ADD32(ctx->r29, 0X68);
    // 0x8000DB50: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x8000DB54: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
L_8000DB58:
    // 0x8000DB58: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8000DB5C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8000DB60: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000DB64: bne         $v0, $a0, L_8000DB58
    if (ctx->r2 != ctx->r4) {
        // 0x8000DB68: swc1        $f16, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
            goto L_8000DB58;
    }
    // 0x8000DB68: swc1        $f16, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
    // 0x8000DB6C: lw          $t1, 0xD0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XD0);
    // 0x8000DB70: lw          $t2, 0xCC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XCC);
    // 0x8000DB74: addiu       $s7, $sp, 0x74
    ctx->r23 = ADD32(ctx->r29, 0X74);
    // 0x8000DB78: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x8000DB7C: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8000DB80: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8000DB84: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000DB88: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x8000DB8C: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    // 0x8000DB90: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000DB94: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    // 0x8000DB98: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8000DB9C: sw          $t0, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r8;
    // 0x8000DBA0: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
    // 0x8000DBA4: jal         0x800034FC
    // 0x8000DBA8: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    func_800034FC(rdram, ctx);
        goto after_1;
    // 0x8000DBA8: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x8000DBAC: lh          $s6, 0x2($s1)
    ctx->r22 = MEM_H(ctx->r17, 0X2);
    // 0x8000DBB0: lw          $t0, 0xD4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XD4);
    // 0x8000DBB4: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x8000DBB8: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x8000DBBC: blez        $s6, L_8000DD0C
    if (SIGNED(ctx->r22) <= 0) {
        // 0x8000DBC0: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8000DD0C;
    }
    // 0x8000DBC0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8000DBC4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000DBC8: lwc1        $f20, 0x5EE4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X5EE4);
    // 0x8000DBCC: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8000DBD0: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x8000DBD4: addiu       $s5, $sp, 0x8C
    ctx->r21 = ADD32(ctx->r29, 0X8C);
    // 0x8000DBD8: addiu       $s2, $sp, 0xB0
    ctx->r18 = ADD32(ctx->r29, 0XB0);
    // 0x8000DBDC: addiu       $s1, $zero, 0x6
    ctx->r17 = ADD32(0, 0X6);
L_8000DBE0:
    // 0x8000DBE0: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x8000DBE4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_8000DBE8:
    // 0x8000DBE8: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x8000DBEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000DBF0: addiu       $s1, $s1, -0x2
    ctx->r17 = ADD32(ctx->r17, -0X2);
    // 0x8000DBF4: beq         $v0, $s1, L_8000DC2C
    if (ctx->r2 == ctx->r17) {
        // 0x8000DBF8: lbu         $t3, 0x0($a0)
        ctx->r11 = MEM_BU(ctx->r4, 0X0);
            goto L_8000DC2C;
    }
    // 0x8000DBF8: lbu         $t3, 0x0($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X0);
L_8000DBFC:
    // 0x8000DBFC: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x8000DC00: addu        $t5, $s0, $t4
    ctx->r13 = ADD32(ctx->r16, ctx->r12);
    // 0x8000DC04: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8000DC08: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x8000DC0C: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8000DC10: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000DC14: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8000DC18: nop

    // 0x8000DC1C: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000DC20: swc1        $f18, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
    // 0x8000DC24: bne         $v0, $s1, L_8000DBFC
    if (ctx->r2 != ctx->r17) {
        // 0x8000DC28: lbu         $t3, 0x0($a0)
        ctx->r11 = MEM_BU(ctx->r4, 0X0);
            goto L_8000DBFC;
    }
    // 0x8000DC28: lbu         $t3, 0x0($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X0);
L_8000DC2C:
    // 0x8000DC2C: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x8000DC30: addu        $t5, $s0, $t4
    ctx->r13 = ADD32(ctx->r16, ctx->r12);
    // 0x8000DC34: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8000DC38: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x8000DC3C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8000DC40: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8000DC44: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8000DC48: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000DC4C: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000DC50: swc1        $f18, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
    // 0x8000DC54: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    // 0x8000DC58: bne         $a1, $s2, L_8000DBE8
    if (ctx->r5 != ctx->r18) {
        // 0x8000DC5C: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8000DBE8;
    }
    // 0x8000DC5C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8000DC60: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8000DC64: jal         0x8000D110
    // 0x8000DC68: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_8000D110(rdram, ctx);
        goto after_2;
    // 0x8000DC68: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_2:
    // 0x8000DC6C: lw          $a0, 0xD8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XD8);
    // 0x8000DC70: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x8000DC74: jal         0x8000D1FC
    // 0x8000DC78: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_8000D1FC(rdram, ctx);
        goto after_3;
    // 0x8000DC78: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_3:
    // 0x8000DC7C: bne         $v0, $fp, L_8000DD00
    if (ctx->r2 != ctx->r30) {
        // 0x8000DC80: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_8000DD00;
    }
    // 0x8000DC80: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8000DC84: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x8000DC88: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8000DC8C: addiu       $a2, $sp, 0x98
    ctx->r6 = ADD32(ctx->r29, 0X98);
    // 0x8000DC90: addiu       $a3, $sp, 0xA4
    ctx->r7 = ADD32(ctx->r29, 0XA4);
    // 0x8000DC94: jal         0x800037FC
    // 0x8000DC98: sw          $v0, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r2;
    func_800037FC(rdram, ctx);
        goto after_4;
    // 0x8000DC98: sw          $v0, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r2;
    after_4:
    // 0x8000DC9C: lw          $t8, 0xE0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE0);
    // 0x8000DCA0: jal         0x8000E978
    // 0x8000DCA4: lwc1        $f12, 0x8($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X8);
    func_8000E978(rdram, ctx);
        goto after_5;
    // 0x8000DCA4: lwc1        $f12, 0x8($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X8);
    after_5:
    // 0x8000DCA8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000DCAC: lwc1        $f20, 0x5EE8($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X5EE8);
    // 0x8000DCB0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000DCB4: lwc1        $f6, 0x5EEC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5EEC);
    // 0x8000DCB8: sub.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x8000DCBC: lw          $v0, 0xDC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XDC);
    // 0x8000DCC0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8000DCC4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8000DCC8: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    // 0x8000DCCC: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8000DCD0: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x8000DCD4: lw          $t9, 0xE0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE0);
    // 0x8000DCD8: jal         0x8000E978
    // 0x8000DCDC: lwc1        $f12, 0x0($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X0);
    func_8000E978(rdram, ctx);
        goto after_6;
    // 0x8000DCDC: lwc1        $f12, 0x0($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X0);
    after_6:
    // 0x8000DCE0: sub.s       $f18, $f0, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x8000DCE4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000DCE8: lwc1        $f4, 0x5EF0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5EF0);
    // 0x8000DCEC: lw          $t1, 0xDC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XDC);
    // 0x8000DCF0: lw          $t0, 0xD4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XD4);
    // 0x8000DCF4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8000DCF8: b           L_8000DD0C
    // 0x8000DCFC: swc1        $f6, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f6.u32l;
        goto L_8000DD0C;
    // 0x8000DCFC: swc1        $f6, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f6.u32l;
L_8000DD00:
    // 0x8000DD00: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8000DD04: bne         $s3, $s6, L_8000DBE0
    if (ctx->r19 != ctx->r22) {
        // 0x8000DD08: addiu       $s4, $s4, 0x3
        ctx->r20 = ADD32(ctx->r20, 0X3);
            goto L_8000DBE0;
    }
    // 0x8000DD08: addiu       $s4, $s4, 0x3
    ctx->r20 = ADD32(ctx->r20, 0X3);
L_8000DD0C:
    // 0x8000DD0C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8000DD10: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8000DD14: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8000DD18: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8000DD1C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8000DD20: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8000DD24: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8000DD28: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8000DD2C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8000DD30: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8000DD34: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8000DD38: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    // 0x8000DD3C: jr          $ra
    // 0x8000DD40: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    TRACE_RETURN()
    return;
    // 0x8000DD40: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
;}
RECOMP_FUNC void func_8000DD44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000DD44: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x8000DD48: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8000DD4C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8000DD50: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8000DD54: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8000DD58: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8000DD5C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8000DD60: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8000DD64: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8000DD68: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8000DD6C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8000DD70: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8000DD74: sw          $a0, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r4;
    // 0x8000DD78: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8000DD7C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8000DD80: addiu       $a0, $sp, 0xE0
    ctx->r4 = ADD32(ctx->r29, 0XE0);
    // 0x8000DD84: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8000DD88: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8000DD8C: nop

    // 0x8000DD90: sw          $t7, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r15;
    // 0x8000DD94: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8000DD98: sw          $zero, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = 0;
    // 0x8000DD9C: addiu       $a1, $sp, 0xDC
    ctx->r5 = ADD32(ctx->r29, 0XDC);
    // 0x8000DDA0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8000DDA4: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8000DDA8: jal         0x8004EE7C
    // 0x8000DDAC: sw          $t9, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r25;
    func_8004EE7C(rdram, ctx);
        goto after_0;
    // 0x8000DDAC: sw          $t9, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r25;
    after_0:
    // 0x8000DDB0: lw          $v1, 0xE4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XE4);
    // 0x8000DDB4: beq         $v0, $zero, L_8000DF24
    if (ctx->r2 == 0) {
        // 0x8000DDB8: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8000DF24;
    }
    // 0x8000DDB8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8000DDBC: lw          $t0, 0xE0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XE0);
    // 0x8000DDC0: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8000DDC4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8000DDC8: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x8000DDCC: lw          $t1, 0xDC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XDC);
    // 0x8000DDD0: addiu       $s7, $sp, 0x84
    ctx->r23 = ADD32(ctx->r29, 0X84);
    // 0x8000DDD4: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8000DDD8: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x8000DDDC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8000DDE0: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x8000DDE4: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    // 0x8000DDE8: cvt.s.w     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000DDEC: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    // 0x8000DDF0: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    // 0x8000DDF4: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8000DDF8: add.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f12.fl;
    // 0x8000DDFC: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    // 0x8000DE00: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8000DE04: swc1        $f2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f2.u32l;
    // 0x8000DE08: swc1        $f2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f2.u32l;
    // 0x8000DE0C: sub.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x8000DE10: sw          $v1, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r3;
    // 0x8000DE14: jal         0x800034FC
    // 0x8000DE18: swc1        $f8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f8.u32l;
    func_800034FC(rdram, ctx);
        goto after_1;
    // 0x8000DE18: swc1        $f8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x8000DE1C: lh          $s6, 0x2($s1)
    ctx->r22 = MEM_H(ctx->r17, 0X2);
    // 0x8000DE20: lw          $v1, 0xE4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XE4);
    // 0x8000DE24: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x8000DE28: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x8000DE2C: blez        $s6, L_8000DF24
    if (SIGNED(ctx->r22) <= 0) {
        // 0x8000DE30: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8000DF24;
    }
    // 0x8000DE30: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8000DE34: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000DE38: lwc1        $f20, 0x5EF4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X5EF4);
    // 0x8000DE3C: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8000DE40: addiu       $fp, $sp, 0x60
    ctx->r30 = ADD32(ctx->r29, 0X60);
    // 0x8000DE44: addiu       $s5, $sp, 0x9C
    ctx->r21 = ADD32(ctx->r29, 0X9C);
    // 0x8000DE48: addiu       $s2, $sp, 0xC0
    ctx->r18 = ADD32(ctx->r29, 0XC0);
    // 0x8000DE4C: addiu       $s1, $zero, 0x6
    ctx->r17 = ADD32(0, 0X6);
L_8000DE50:
    // 0x8000DE50: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    // 0x8000DE54: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_8000DE58:
    // 0x8000DE58: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x8000DE5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000DE60: addiu       $s1, $s1, -0x2
    ctx->r17 = ADD32(ctx->r17, -0X2);
    // 0x8000DE64: beq         $v0, $s1, L_8000DE9C
    if (ctx->r2 == ctx->r17) {
        // 0x8000DE68: lbu         $t2, 0x0($a0)
        ctx->r10 = MEM_BU(ctx->r4, 0X0);
            goto L_8000DE9C;
    }
    // 0x8000DE68: lbu         $t2, 0x0($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X0);
L_8000DE6C:
    // 0x8000DE6C: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x8000DE70: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x8000DE74: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x8000DE78: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x8000DE7C: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8000DE80: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000DE84: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8000DE88: nop

    // 0x8000DE8C: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000DE90: swc1        $f18, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
    // 0x8000DE94: bne         $v0, $s1, L_8000DE6C
    if (ctx->r2 != ctx->r17) {
        // 0x8000DE98: lbu         $t2, 0x0($a0)
        ctx->r10 = MEM_BU(ctx->r4, 0X0);
            goto L_8000DE6C;
    }
    // 0x8000DE98: lbu         $t2, 0x0($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X0);
L_8000DE9C:
    // 0x8000DE9C: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x8000DEA0: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x8000DEA4: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x8000DEA8: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x8000DEAC: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8000DEB0: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8000DEB4: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8000DEB8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000DEBC: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000DEC0: swc1        $f18, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
    // 0x8000DEC4: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    // 0x8000DEC8: bne         $a1, $s2, L_8000DE58
    if (ctx->r5 != ctx->r18) {
        // 0x8000DECC: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8000DE58;
    }
    // 0x8000DECC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8000DED0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8000DED4: jal         0x8000D110
    // 0x8000DED8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_8000D110(rdram, ctx);
        goto after_2;
    // 0x8000DED8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_2:
    // 0x8000DEDC: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8000DEE0: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x8000DEE4: jal         0x8000D1FC
    // 0x8000DEE8: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_8000D1FC(rdram, ctx);
        goto after_3;
    // 0x8000DEE8: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_3:
    // 0x8000DEEC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000DEF0: bne         $v0, $at, L_8000DF18
    if (ctx->r2 != ctx->r1) {
        // 0x8000DEF4: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8000DF18;
    }
    // 0x8000DEF4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000DEF8: lw          $a0, 0xE8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE8);
    // 0x8000DEFC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8000DF00: addiu       $a2, $sp, 0xA8
    ctx->r6 = ADD32(ctx->r29, 0XA8);
    // 0x8000DF04: addiu       $a3, $sp, 0xB4
    ctx->r7 = ADD32(ctx->r29, 0XB4);
    // 0x8000DF08: jal         0x800037FC
    // 0x8000DF0C: sw          $v0, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r2;
    func_800037FC(rdram, ctx);
        goto after_4;
    // 0x8000DF0C: sw          $v0, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r2;
    after_4:
    // 0x8000DF10: b           L_8000DF24
    // 0x8000DF14: lw          $v1, 0xE4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XE4);
        goto L_8000DF24;
    // 0x8000DF14: lw          $v1, 0xE4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XE4);
L_8000DF18:
    // 0x8000DF18: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8000DF1C: bne         $s3, $s6, L_8000DE50
    if (ctx->r19 != ctx->r22) {
        // 0x8000DF20: addiu       $s4, $s4, 0x3
        ctx->r20 = ADD32(ctx->r20, 0X3);
            goto L_8000DE50;
    }
    // 0x8000DF20: addiu       $s4, $s4, 0x3
    ctx->r20 = ADD32(ctx->r20, 0X3);
L_8000DF24:
    // 0x8000DF24: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8000DF28: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8000DF2C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8000DF30: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8000DF34: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8000DF38: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8000DF3C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8000DF40: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8000DF44: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8000DF48: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8000DF4C: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8000DF50: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    // 0x8000DF54: jr          $ra
    // 0x8000DF58: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    TRACE_RETURN()
    return;
    // 0x8000DF58: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8000DF5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000DF5C: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8000DF60: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x8000DF64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000DF68: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x8000DF6C: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    // 0x8000DF70: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    // 0x8000DF74: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8000DF78: addiu       $v0, $sp, 0x2C
    ctx->r2 = ADD32(ctx->r29, 0X2C);
    // 0x8000DF7C: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8000DF80: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
L_8000DF84:
    // 0x8000DF84: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8000DF88: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8000DF8C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8000DF90: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x8000DF94: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8000DF98: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000DF9C: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8000DFA0: bne         $at, $zero, L_8000DF84
    if (ctx->r1 != 0) {
        // 0x8000DFA4: swc1        $f8, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
            goto L_8000DF84;
    }
    // 0x8000DFA4: swc1        $f8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
    // 0x8000DFA8: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x8000DFAC: lw          $a3, 0x84($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X84);
    // 0x8000DFB0: addiu       $t0, $sp, 0x74
    ctx->r8 = ADD32(ctx->r29, 0X74);
    // 0x8000DFB4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_8000DFB8:
    // 0x8000DFB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000DFBC: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x8000DFC0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_8000DFC4:
    // 0x8000DFC4: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000DFC8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000DFCC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000DFD0: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8000DFD4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8000DFD8: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x8000DFDC: nop

    // 0x8000DFE0: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8000DFE4: nop

    // 0x8000DFE8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000DFEC: bne         $v0, $a1, L_8000DFC4
    if (ctx->r2 != ctx->r5) {
        // 0x8000DFF0: swc1        $f4, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
            goto L_8000DFC4;
    }
    // 0x8000DFF0: swc1        $f4, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
    // 0x8000DFF4: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x8000DFF8: bne         $a2, $t0, L_8000DFB8
    if (ctx->r6 != ctx->r8) {
        // 0x8000DFFC: addiu       $a3, $a3, 0xC
        ctx->r7 = ADD32(ctx->r7, 0XC);
            goto L_8000DFB8;
    }
    // 0x8000DFFC: addiu       $a3, $a3, 0xC
    ctx->r7 = ADD32(ctx->r7, 0XC);
    // 0x8000E000: lui         $a1, 0x3F86
    ctx->r5 = S32(0X3F86 << 16);
    // 0x8000E004: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x8000E008: jal         0x8000D110
    // 0x8000E00C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    func_8000D110(rdram, ctx);
        goto after_0;
    // 0x8000E00C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_0:
    // 0x8000E010: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8000E014: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
    // 0x8000E018: jal         0x800034FC
    // 0x8000E01C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_800034FC(rdram, ctx);
        goto after_1;
    // 0x8000E01C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_1:
    // 0x8000E020: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x8000E024: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8000E028: jal         0x8000D1FC
    // 0x8000E02C: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    func_8000D1FC(rdram, ctx);
        goto after_2;
    // 0x8000E02C: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    after_2:
    // 0x8000E030: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000E034: bne         $v0, $at, L_8000E058
    if (ctx->r2 != ctx->r1) {
        // 0x8000E038: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8000E058;
    }
    // 0x8000E038: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000E03C: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x8000E040: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    // 0x8000E044: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x8000E048: addiu       $a2, $a1, 0xC
    ctx->r6 = ADD32(ctx->r5, 0XC);
    // 0x8000E04C: jal         0x800037FC
    // 0x8000E050: addiu       $a3, $a1, 0x18
    ctx->r7 = ADD32(ctx->r5, 0X18);
    func_800037FC(rdram, ctx);
        goto after_3;
    // 0x8000E050: addiu       $a3, $a1, 0x18
    ctx->r7 = ADD32(ctx->r5, 0X18);
    after_3:
    // 0x8000E054: lw          $v1, 0x7C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X7C);
L_8000E058:
    // 0x8000E058: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000E05C: beq         $v1, $at, L_8000E068
    if (ctx->r3 == ctx->r1) {
        // 0x8000E060: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8000E068;
    }
    // 0x8000E060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000E064: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8000E068:
    // 0x8000E068: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8000E06C: jr          $ra
    // 0x8000E070: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    TRACE_RETURN()
    return;
    // 0x8000E070: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_8000E074(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000E074: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8000E078: lw          $t6, -0x6630($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6630);
    // 0x8000E07C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000E080: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8000E084: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000E088: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000E08C: bne         $t6, $at, L_8000E0A4
    if (ctx->r14 != ctx->r1) {
        // 0x8000E090: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8000E0A4;
    }
    // 0x8000E090: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000E094: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x8000E098: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8000E09C: b           L_8000E0B0
    // 0x8000E0A0: nop

        goto L_8000E0B0;
    // 0x8000E0A0: nop

L_8000E0A4:
    // 0x8000E0A4: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x8000E0A8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8000E0AC: nop

L_8000E0B0:
    // 0x8000E0B0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8000E0B4: addiu       $a1, $a1, -0x6C50
    ctx->r5 = ADD32(ctx->r5, -0X6C50);
    // 0x8000E0B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000E0BC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8000E0C0: jal         0x80003668
    // 0x8000E0C4: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    func_80003668(rdram, ctx);
        goto after_0;
    // 0x8000E0C4: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x8000E0C8: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8000E0CC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000E0D0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8000E0D4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8000E0D8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E0DC: addiu       $a2, $a2, 0x6A80
    ctx->r6 = ADD32(ctx->r6, 0X6A80);
    // 0x8000E0E0: addiu       $a1, $a1, 0x6A40
    ctx->r5 = ADD32(ctx->r5, 0X6A40);
    // 0x8000E0E4: bc1f        L_8000E100
    if (!c1cs) {
        // 0x8000E0E8: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8000E100;
    }
    // 0x8000E0E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000E0EC: jal         0x8000E198
    // 0x8000E0F0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8000E198(rdram, ctx);
        goto after_1;
    // 0x8000E0F0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x8000E0F4: bne         $v0, $zero, L_8000E100
    if (ctx->r2 != 0) {
        // 0x8000E0F8: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_8000E100;
    }
    // 0x8000E0F8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E0FC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8000E100:
    // 0x8000E100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000E104: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000E108: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8000E10C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000E114(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000E114: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000E118: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000E11C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000E120: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8000E124: addiu       $a2, $a2, 0x6980
    ctx->r6 = ADD32(ctx->r6, 0X6980);
    // 0x8000E128: addiu       $a1, $a1, 0x6940
    ctx->r5 = ADD32(ctx->r5, 0X6940);
    // 0x8000E12C: jal         0x8000E198
    // 0x8000E130: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    func_8000E198(rdram, ctx);
        goto after_0;
    // 0x8000E130: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x8000E134: bne         $v0, $zero, L_8000E140
    if (ctx->r2 != 0) {
        // 0x8000E138: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_8000E140;
    }
    // 0x8000E138: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E13C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8000E140:
    // 0x8000E140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000E144: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000E148: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8000E14C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000E154(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000E154: bltz        $a0, L_8000E164
    if (SIGNED(ctx->r4) < 0) {
        // 0x8000E158: negu        $v0, $a0
        ctx->r2 = SUB32(0, ctx->r4);
            goto L_8000E164;
    }
    // 0x8000E158: negu        $v0, $a0
    ctx->r2 = SUB32(0, ctx->r4);
    // 0x8000E15C: jr          $ra
    // 0x8000E160: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    TRACE_RETURN()
    return;
    // 0x8000E160: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8000E164:
    // 0x8000E164: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000E16C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000E16C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000E170: nop

    // 0x8000E174: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x8000E178: nop

    // 0x8000E17C: bc1fl       L_8000E190
    if (!c1cs) {
        // 0x8000E180: neg.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
            goto L_8000E190;
    }
    goto skip_0;
    // 0x8000E180: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
    skip_0:
    // 0x8000E184: jr          $ra
    // 0x8000E188: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    TRACE_RETURN()
    return;
    // 0x8000E188: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x8000E18C: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
L_8000E190:
    // 0x8000E190: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000E198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000E198: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000E19C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8000E1A0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8000E1A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000E1A8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8000E1AC: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8000E1B0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8000E1B4: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x8000E1B8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8000E1BC: jal         0x80000FE4
    // 0x8000E1C0: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_80000FE4(rdram, ctx);
        goto after_0;
    // 0x8000E1C0: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x8000E1C4: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8000E1C8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8000E1CC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8000E1D0: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8000E1D4: jal         0x80000FE4
    // 0x8000E1D8: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    func_80000FE4(rdram, ctx);
        goto after_1;
    // 0x8000E1D8: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8000E1DC: jal         0x8000E16C
    // 0x8000E1E0: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    func_8000E16C(rdram, ctx);
        goto after_2;
    // 0x8000E1E0: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8000E1E4: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8000E1E8: jal         0x8000E16C
    // 0x8000E1EC: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    func_8000E16C(rdram, ctx);
        goto after_3;
    // 0x8000E1EC: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x8000E1F0: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8000E1F4: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8000E1F8: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8000E1FC: nop

    // 0x8000E200: bc1fl       L_8000E25C
    if (!c1cs) {
        // 0x8000E204: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8000E25C;
    }
    goto skip_0;
    // 0x8000E204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8000E208: jal         0x8000E16C
    // 0x8000E20C: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    func_8000E16C(rdram, ctx);
        goto after_4;
    // 0x8000E20C: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    after_4:
    // 0x8000E210: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8000E214: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8000E218: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8000E21C: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8000E220: bc1fl       L_8000E25C
    if (!c1cs) {
        // 0x8000E224: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8000E25C;
    }
    goto skip_1;
    // 0x8000E224: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8000E228: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x8000E22C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000E230: bc1fl       L_8000E25C
    if (!c1cs) {
        // 0x8000E234: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8000E25C;
    }
    goto skip_2;
    // 0x8000E234: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8000E238: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8000E23C: nop

    // 0x8000E240: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x8000E244: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x8000E248: nop

    // 0x8000E24C: bc1fl       L_8000E25C
    if (!c1cs) {
        // 0x8000E250: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8000E25C;
    }
    goto skip_3;
    // 0x8000E250: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8000E254: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8000E258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000E25C:
    // 0x8000E25C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E260: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8000E264: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000E26C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000E26C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000E270: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8000E274: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8000E278: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000E27C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8000E280: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8000E284: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8000E288: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x8000E28C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8000E290: jal         0x80000FE4
    // 0x8000E294: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_80000FE4(rdram, ctx);
        goto after_0;
    // 0x8000E294: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x8000E298: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8000E29C: jal         0x8000E16C
    // 0x8000E2A0: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    func_8000E16C(rdram, ctx);
        goto after_1;
    // 0x8000E2A0: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x8000E2A4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8000E2A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000E2AC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8000E2B0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8000E2B4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8000E2B8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8000E2BC: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8000E2C0: bc1f        L_8000E2D0
    if (!c1cs) {
        // 0x8000E2C4: nop
    
            goto L_8000E2D0;
    }
    // 0x8000E2C4: nop

    // 0x8000E2C8: b           L_8000E34C
    // 0x8000E2CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000E34C;
    // 0x8000E2CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000E2D0:
    // 0x8000E2D0: jal         0x80000FE4
    // 0x8000E2D4: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    func_80000FE4(rdram, ctx);
        goto after_2;
    // 0x8000E2D4: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x8000E2D8: jal         0x8000E16C
    // 0x8000E2DC: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    func_8000E16C(rdram, ctx);
        goto after_3;
    // 0x8000E2DC: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x8000E2E0: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8000E2E4: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8000E2E8: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8000E2EC: nop

    // 0x8000E2F0: bc1fl       L_8000E34C
    if (!c1cs) {
        // 0x8000E2F4: lw          $v0, 0x1C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X1C);
            goto L_8000E34C;
    }
    goto skip_0;
    // 0x8000E2F4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8000E2F8: jal         0x8000E16C
    // 0x8000E2FC: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    func_8000E16C(rdram, ctx);
        goto after_4;
    // 0x8000E2FC: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    after_4:
    // 0x8000E300: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8000E304: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8000E308: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8000E30C: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8000E310: bc1fl       L_8000E34C
    if (!c1cs) {
        // 0x8000E314: lw          $v0, 0x1C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X1C);
            goto L_8000E34C;
    }
    goto skip_1;
    // 0x8000E314: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8000E318: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x8000E31C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000E320: bc1fl       L_8000E34C
    if (!c1cs) {
        // 0x8000E324: lw          $v0, 0x1C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X1C);
            goto L_8000E34C;
    }
    goto skip_2;
    // 0x8000E324: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8000E328: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000E32C: nop

    // 0x8000E330: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x8000E334: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x8000E338: nop

    // 0x8000E33C: bc1fl       L_8000E34C
    if (!c1cs) {
        // 0x8000E340: lw          $v0, 0x1C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X1C);
            goto L_8000E34C;
    }
    goto skip_3;
    // 0x8000E340: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8000E344: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8000E348: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_8000E34C:
    // 0x8000E34C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000E350: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8000E354: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000E35C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000E35C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8000E360: addiu       $v1, $v1, 0x6AC4
    ctx->r3 = ADD32(ctx->r3, 0X6AC4);
    // 0x8000E364: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8000E368: lui         $at, 0x41C6
    ctx->r1 = S32(0X41C6 << 16);
    // 0x8000E36C: ori         $at, $at, 0x4E6D
    ctx->r1 = ctx->r1 | 0X4E6D;
    // 0x8000E370: multu       $t6, $at
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r1)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000E374: mflo        $t7
    ctx->r15 = lo;
    // 0x8000E378: addiu       $t8, $t7, 0x3039
    ctx->r24 = ADD32(ctx->r15, 0X3039);
    // 0x8000E37C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8000E380: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000E384: bgez        $v0, L_8000E398
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000E388: sra         $t9, $v0, 16
        ctx->r25 = S32(SIGNED(ctx->r2) >> 16);
            goto L_8000E398;
    }
    // 0x8000E388: sra         $t9, $v0, 16
    ctx->r25 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8000E38C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8000E390: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8000E394: sra         $t9, $at, 16
    ctx->r25 = S32(SIGNED(ctx->r1) >> 16);
L_8000E398:
    // 0x8000E398: jr          $ra
    // 0x8000E39C: andi        $v0, $t9, 0x7FFF
    ctx->r2 = ctx->r25 & 0X7FFF;
    TRACE_RETURN()
    return;
    // 0x8000E39C: andi        $v0, $t9, 0x7FFF
    ctx->r2 = ctx->r25 & 0X7FFF;
;}
RECOMP_FUNC void func_8000E3A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000E3A0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8000E3A4: addiu       $a2, $a2, 0x6AC4
    ctx->r6 = ADD32(ctx->r6, 0X6AC4);
    // 0x8000E3A8: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8000E3AC: lui         $at, 0x41C6
    ctx->r1 = S32(0X41C6 << 16);
    // 0x8000E3B0: ori         $at, $at, 0x4E6D
    ctx->r1 = ctx->r1 | 0X4E6D;
    // 0x8000E3B4: multu       $t6, $at
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r1)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000E3B8: mflo        $t7
    ctx->r15 = lo;
    // 0x8000E3BC: addiu       $t8, $t7, 0x3039
    ctx->r24 = ADD32(ctx->r15, 0X3039);
    // 0x8000E3C0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8000E3C4: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8000E3C8: bgez        $v0, L_8000E3DC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000E3CC: sra         $v1, $v0, 16
        ctx->r3 = S32(SIGNED(ctx->r2) >> 16);
            goto L_8000E3DC;
    }
    // 0x8000E3CC: sra         $v1, $v0, 16
    ctx->r3 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8000E3D0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8000E3D4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8000E3D8: sra         $v1, $at, 16
    ctx->r3 = S32(SIGNED(ctx->r1) >> 16);
L_8000E3DC:
    // 0x8000E3DC: andi        $t9, $v1, 0x7FFF
    ctx->r25 = ctx->r3 & 0X7FFF;
    // 0x8000E3E0: beq         $a1, $zero, L_8000E3F8
    if (ctx->r5 == 0) {
        // 0x8000E3E4: and         $v1, $t9, $a0
        ctx->r3 = ctx->r25 & ctx->r4;
            goto L_8000E3F8;
    }
    // 0x8000E3E4: and         $v1, $t9, $a0
    ctx->r3 = ctx->r25 & ctx->r4;
    // 0x8000E3E8: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x8000E3EC: beq         $t0, $zero, L_8000E3F8
    if (ctx->r8 == 0) {
        // 0x8000E3F0: nop
    
            goto L_8000E3F8;
    }
    // 0x8000E3F0: nop

    // 0x8000E3F4: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
L_8000E3F8:
    // 0x8000E3F8: jr          $ra
    // 0x8000E3FC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    TRACE_RETURN()
    return;
    // 0x8000E3FC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8000E400(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000E400: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8000E404: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x8000E408: c.le.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl <= ctx->f12.fl;
    // 0x8000E40C: nop

    // 0x8000E410: bc1fl       L_8000E42C
    if (!c1cs) {
        // 0x8000E414: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_8000E42C;
    }
    goto skip_0;
    // 0x8000E414: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x8000E418: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8000E41C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8000E420: b           L_8000E430
    // 0x8000E424: nop

        goto L_8000E430;
    // 0x8000E424: nop

    // 0x8000E428: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_8000E42C:
    // 0x8000E42C: nop

L_8000E430:
    // 0x8000E430: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000E434: lwc1        $f4, 0x5F00($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5F00);
    // 0x8000E438: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000E43C: addiu       $t7, $zero, 0x13
    ctx->r15 = ADD32(0, 0X13);
    // 0x8000E440: div.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f12.fl, ctx->f4.fl);
    // 0x8000E444: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8000E448: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8000E44C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8000E450: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x8000E454: nop

    // 0x8000E458: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x8000E45C: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8000E460: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8000E464: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x8000E468: ldc1        $f4, 0x5F08($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X5F08);
    // 0x8000E46C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000E470: lwc1        $f8, 0x5F10($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5F10);
    // 0x8000E474: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000E478: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8000E47C: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    // 0x8000E480: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000E484: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8000E488: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8000E48C: sub.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x8000E490: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8000E494: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8000E498: sub.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f14.fl;
    // 0x8000E49C: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x8000E4A0: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x8000E4A4: mul.s       $f0, $f12, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8000E4A8: div.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
L_8000E4AC:
    // 0x8000E4AC: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8000E4B0: addiu       $t8, $v0, -0x2
    ctx->r24 = ADD32(ctx->r2, -0X2);
    // 0x8000E4B4: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8000E4B8: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000E4BC: addiu       $t9, $v0, -0x4
    ctx->r25 = ADD32(ctx->r2, -0X4);
    // 0x8000E4C0: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8000E4C4: addiu       $t0, $v0, -0x6
    ctx->r8 = ADD32(ctx->r2, -0X6);
    // 0x8000E4C8: addiu       $v0, $v0, -0x8
    ctx->r2 = ADD32(ctx->r2, -0X8);
    // 0x8000E4CC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8000E4D0: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x8000E4D4: sub.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x8000E4D8: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000E4DC: div.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8000E4E0: sub.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x8000E4E4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8000E4E8: div.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8000E4EC: sub.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x8000E4F0: div.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8000E4F4: sub.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x8000E4F8: bne         $v0, $v1, L_8000E4AC
    if (ctx->r2 != ctx->r3) {
        // 0x8000E4FC: div.s       $f2, $f0, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
            goto L_8000E4AC;
    }
    // 0x8000E4FC: div.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8000E500: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8000E504: nop

    // 0x8000E508: sub.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x8000E50C: jr          $ra
    // 0x8000E510: div.s       $f0, $f12, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f10.fl);
    TRACE_RETURN()
    return;
    // 0x8000E510: div.s       $f0, $f12, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f10.fl);
;}
RECOMP_FUNC void func_8000E514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000E514: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000E518: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000E51C: jal         0x8000E400
    // 0x8000E520: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8000E400(rdram, ctx);
        goto after_0;
    // 0x8000E520: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8000E524: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E528: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8000E52C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000E530: bgez        $t6, L_8000E544
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8000E534: andi        $t7, $t6, 0x1
        ctx->r15 = ctx->r14 & 0X1;
            goto L_8000E544;
    }
    // 0x8000E534: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8000E538: beq         $t7, $zero, L_8000E544
    if (ctx->r15 == 0) {
        // 0x8000E53C: nop
    
            goto L_8000E544;
    }
    // 0x8000E53C: nop

    // 0x8000E540: addiu       $t7, $t7, -0x2
    ctx->r15 = ADD32(ctx->r15, -0X2);
L_8000E544:
    // 0x8000E544: bnel        $t7, $zero, L_8000E558
    if (ctx->r15 != 0) {
        // 0x8000E548: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_8000E558;
    }
    goto skip_0;
    // 0x8000E548: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_0:
    // 0x8000E54C: b           L_8000E580
    // 0x8000E550: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8000E580;
    // 0x8000E550: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8000E554: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_8000E558:
    // 0x8000E558: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000E55C: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x8000E560: nop

    // 0x8000E564: bc1t        L_8000E57C
    if (c1cs) {
        // 0x8000E568: nop
    
            goto L_8000E57C;
    }
    // 0x8000E568: nop

    // 0x8000E56C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8000E570: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8000E574: b           L_8000E580
    // 0x8000E578: div.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
        goto L_8000E580;
    // 0x8000E578: div.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
L_8000E57C:
    // 0x8000E57C: lwc1        $f0, 0x5F14($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5F14);
L_8000E580:
    // 0x8000E580: jr          $ra
    // 0x8000E584: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    TRACE_RETURN()
    return;
    // 0x8000E584: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8000E588(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000E588: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    // 0x8000E58C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8000E590: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8000E594: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
    // 0x8000E598: nop

    // 0x8000E59C: bc1fl       L_8000E5FC
    if (!c1cs) {
        // 0x8000E5A0: mov.d       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
            goto L_8000E5FC;
    }
    goto skip_0;
    // 0x8000E5A0: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
    skip_0:
    // 0x8000E5A4: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8000E5A8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8000E5AC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8000E5B0: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8000E5B4: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
    // 0x8000E5B8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8000E5BC: bc1fl       L_8000E5D0
    if (!c1cs) {
        // 0x8000E5C0: mov.d       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
            goto L_8000E5D0;
    }
    goto skip_1;
    // 0x8000E5C0: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
    skip_1:
    // 0x8000E5C4: b           L_8000E5D0
    // 0x8000E5C8: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
        goto L_8000E5D0;
    // 0x8000E5C8: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    // 0x8000E5CC: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
L_8000E5D0:
    // 0x8000E5D0: div.d       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f12.d, ctx->f0.d);
L_8000E5D4:
    // 0x8000E5D4: mov.d       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.d = ctx->f0.d;
    // 0x8000E5D8: add.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f4.d + ctx->f0.d;
    // 0x8000E5DC: div.d       $f0, $f6, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f0.d = DIV_D(ctx->f6.d, ctx->f14.d);
    // 0x8000E5E0: c.lt.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d < ctx->f2.d;
    // 0x8000E5E4: nop

    // 0x8000E5E8: bc1tl       L_8000E5D4
    if (c1cs) {
        // 0x8000E5EC: div.d       $f4, $f12, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f12.d, ctx->f0.d);
            goto L_8000E5D4;
    }
    goto skip_2;
    // 0x8000E5EC: div.d       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f12.d, ctx->f0.d);
    skip_2:
    // 0x8000E5F0: jr          $ra
    // 0x8000E5F4: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
    TRACE_RETURN()
    return;
    // 0x8000E5F4: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
    // 0x8000E5F8: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
L_8000E5FC:
    // 0x8000E5FC: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000E604(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000E604: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000E608: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8000E60C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8000E610: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000E614: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x8000E618: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8000E61C: bc1fl       L_8000E630
    if (!c1cs) {
        // 0x8000E620: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_8000E630;
    }
    goto skip_0;
    // 0x8000E620: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_0:
    // 0x8000E624: b           L_8000E650
    // 0x8000E628: div.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f14.fl, ctx->f12.fl);
        goto L_8000E650;
    // 0x8000E628: div.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8000E62C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_8000E630:
    // 0x8000E630: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000E634: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x8000E638: nop

    // 0x8000E63C: bc1f        L_8000E650
    if (!c1cs) {
        // 0x8000E640: nop
    
            goto L_8000E650;
    }
    // 0x8000E640: nop

    // 0x8000E644: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8000E648: b           L_8000E650
    // 0x8000E64C: div.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f14.fl, ctx->f12.fl);
        goto L_8000E650;
    // 0x8000E64C: div.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f14.fl, ctx->f12.fl);
L_8000E650:
    // 0x8000E650: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x8000E654: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000E658: bc1fl       L_8000E66C
    if (!c1cs) {
        // 0x8000E65C: neg.s       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
            goto L_8000E66C;
    }
    goto skip_1;
    // 0x8000E65C: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
    skip_1:
    // 0x8000E660: b           L_8000E66C
    // 0x8000E664: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
        goto L_8000E66C;
    // 0x8000E664: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8000E668: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
L_8000E66C:
    // 0x8000E66C: lwc1        $f6, 0x5F18($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5F18);
    // 0x8000E670: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000E674: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x8000E678: nop

    // 0x8000E67C: bc1f        L_8000E68C
    if (!c1cs) {
        // 0x8000E680: nop
    
            goto L_8000E68C;
    }
    // 0x8000E680: nop

    // 0x8000E684: b           L_8000E70C
    // 0x8000E688: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
        goto L_8000E70C;
    // 0x8000E688: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
L_8000E68C:
    // 0x8000E68C: lwc1        $f8, 0x5F1C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5F1C);
    // 0x8000E690: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000E694: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x8000E698: nop

    // 0x8000E69C: bc1f        L_8000E6AC
    if (!c1cs) {
        // 0x8000E6A0: nop
    
            goto L_8000E6AC;
    }
    // 0x8000E6A0: nop

    // 0x8000E6A4: b           L_8000E70C
    // 0x8000E6A8: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
        goto L_8000E70C;
    // 0x8000E6A8: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
L_8000E6AC:
    // 0x8000E6AC: lwc1        $f10, 0x5F20($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5F20);
    // 0x8000E6B0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000E6B4: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x8000E6B8: nop

    // 0x8000E6BC: bc1f        L_8000E6CC
    if (!c1cs) {
        // 0x8000E6C0: nop
    
            goto L_8000E6CC;
    }
    // 0x8000E6C0: nop

    // 0x8000E6C4: b           L_8000E70C
    // 0x8000E6C8: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
        goto L_8000E70C;
    // 0x8000E6C8: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
L_8000E6CC:
    // 0x8000E6CC: lwc1        $f16, 0x5F24($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5F24);
    // 0x8000E6D0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000E6D4: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x8000E6D8: nop

    // 0x8000E6DC: bc1f        L_8000E6EC
    if (!c1cs) {
        // 0x8000E6E0: nop
    
            goto L_8000E6EC;
    }
    // 0x8000E6E0: nop

    // 0x8000E6E4: b           L_8000E70C
    // 0x8000E6E8: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
        goto L_8000E70C;
    // 0x8000E6E8: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_8000E6EC:
    // 0x8000E6EC: lwc1        $f18, 0x5F28($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5F28);
    // 0x8000E6F0: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8000E6F4: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x8000E6F8: nop

    // 0x8000E6FC: bc1f        L_8000E70C
    if (!c1cs) {
        // 0x8000E700: nop
    
            goto L_8000E70C;
    }
    // 0x8000E700: nop

    // 0x8000E704: b           L_8000E70C
    // 0x8000E708: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
        goto L_8000E70C;
    // 0x8000E708: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_8000E70C:
    // 0x8000E70C: blez        $v1, L_8000E758
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8000E710: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_8000E758;
    }
    // 0x8000E710: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8000E714: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
    // 0x8000E718: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8000E71C:
    // 0x8000E71C: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000E720: mtc1        $a0, $f16
    ctx->f16.u32l = ctx->r4;
    // 0x8000E724: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8000E728: addiu       $a0, $a0, -0x2
    ctx->r4 = ADD32(ctx->r4, -0X2);
    // 0x8000E72C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8000E730: mflo        $t6
    ctx->r14 = lo;
    // 0x8000E734: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8000E738: nop

    // 0x8000E73C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000E740: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x8000E744: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8000E748: nop

    // 0x8000E74C: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8000E750: bgtz        $v1, L_8000E71C
    if (SIGNED(ctx->r3) > 0) {
        // 0x8000E754: div.s       $f2, $f10, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
            goto L_8000E71C;
    }
    // 0x8000E754: div.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
L_8000E758:
    // 0x8000E758: blez        $v0, L_8000E778
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000E75C: nop
    
            goto L_8000E778;
    }
    // 0x8000E75C: nop

    // 0x8000E760: add.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x8000E764: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000E768: lwc1        $f6, 0x5F2C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5F2C);
    // 0x8000E76C: div.s       $f16, $f12, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = DIV_S(ctx->f12.fl, ctx->f8.fl);
    // 0x8000E770: jr          $ra
    // 0x8000E774: sub.s       $f0, $f6, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f16.fl;
    TRACE_RETURN()
    return;
    // 0x8000E774: sub.s       $f0, $f6, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f16.fl;
L_8000E778:
    // 0x8000E778: bgezl       $v0, L_8000E79C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000E77C: add.s       $f8, $f14, $f2
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f2.fl;
            goto L_8000E79C;
    }
    goto skip_2;
    // 0x8000E77C: add.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f2.fl;
    skip_2:
    // 0x8000E780: add.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x8000E784: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000E788: lwc1        $f18, 0x5F30($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5F30);
    // 0x8000E78C: div.s       $f4, $f12, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = DIV_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8000E790: jr          $ra
    // 0x8000E794: sub.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f4.fl;
    TRACE_RETURN()
    return;
    // 0x8000E794: sub.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8000E798: add.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f2.fl;
L_8000E79C:
    // 0x8000E79C: div.s       $f0, $f12, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f8.fl);
    // 0x8000E7A0: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000E7A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000E7A8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8000E7AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000E7B0: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8000E7B4: c.eq.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl == ctx->f0.fl;
    // 0x8000E7B8: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x8000E7BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000E7C0: bc1fl       L_8000E7E8
    if (!c1cs) {
        // 0x8000E7C4: c.eq.s      $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl == ctx->f0.fl;
            goto L_8000E7E8;
    }
    goto skip_0;
    // 0x8000E7C4: c.eq.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl == ctx->f0.fl;
    skip_0:
    // 0x8000E7C8: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
    // 0x8000E7CC: nop

    // 0x8000E7D0: bc1fl       L_8000E7E8
    if (!c1cs) {
        // 0x8000E7D4: c.eq.s      $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl == ctx->f0.fl;
            goto L_8000E7E8;
    }
    goto skip_1;
    // 0x8000E7D4: c.eq.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl == ctx->f0.fl;
    skip_1:
    // 0x8000E7D8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8000E7DC: b           L_8000E8C4
    // 0x8000E7E0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8000E8C4;
    // 0x8000E7E0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8000E7E4: c.eq.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl == ctx->f0.fl;
L_8000E7E8:
    // 0x8000E7E8: nop

    // 0x8000E7EC: bc1tl       L_8000E8A0
    if (c1cs) {
        // 0x8000E7F0: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_8000E8A0;
    }
    goto skip_2;
    // 0x8000E7F0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_2:
    // 0x8000E7F4: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    // 0x8000E7F8: nop

    // 0x8000E7FC: bc1tl       L_8000E878
    if (c1cs) {
        // 0x8000E800: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_8000E878;
    }
    goto skip_3;
    // 0x8000E800: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_3:
    // 0x8000E804: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8000E808: nop

    // 0x8000E80C: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x8000E810: nop

    // 0x8000E814: bc1fl       L_8000E830
    if (!c1cs) {
        // 0x8000E818: c.lt.s      $f2, $f20
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
            goto L_8000E830;
    }
    goto skip_4;
    // 0x8000E818: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    skip_4:
    // 0x8000E81C: jal         0x8000E604
    // 0x8000E820: div.s       $f12, $f20, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = DIV_S(ctx->f20.fl, ctx->f14.fl);
    func_8000E604(rdram, ctx);
        goto after_0;
    // 0x8000E820: div.s       $f12, $f20, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = DIV_S(ctx->f20.fl, ctx->f14.fl);
    after_0:
    // 0x8000E824: b           L_8000E8C8
    // 0x8000E828: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8000E8C8;
    // 0x8000E828: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E82C: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
L_8000E830:
    // 0x8000E830: nop

    // 0x8000E834: bc1fl       L_8000E85C
    if (!c1cs) {
        // 0x8000E838: neg.s       $f8, $f14
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = -ctx->f14.fl;
            goto L_8000E85C;
    }
    goto skip_5;
    // 0x8000E838: neg.s       $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = -ctx->f14.fl;
    skip_5:
    // 0x8000E83C: neg.s       $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = -ctx->f14.fl;
    // 0x8000E840: jal         0x8000E604
    // 0x8000E844: div.s       $f12, $f20, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = DIV_S(ctx->f20.fl, ctx->f4.fl);
    func_8000E604(rdram, ctx);
        goto after_1;
    // 0x8000E844: div.s       $f12, $f20, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = DIV_S(ctx->f20.fl, ctx->f4.fl);
    after_1:
    // 0x8000E848: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000E84C: lwc1        $f6, 0x5F34($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5F34);
    // 0x8000E850: b           L_8000E8C4
    // 0x8000E854: sub.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f0.fl;
        goto L_8000E8C4;
    // 0x8000E854: sub.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8000E858: neg.s       $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = -ctx->f14.fl;
L_8000E85C:
    // 0x8000E85C: jal         0x8000E604
    // 0x8000E860: div.s       $f12, $f20, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f20.fl, ctx->f8.fl);
    func_8000E604(rdram, ctx);
        goto after_2;
    // 0x8000E860: div.s       $f12, $f20, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f20.fl, ctx->f8.fl);
    after_2:
    // 0x8000E864: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000E868: lwc1        $f10, 0x5F38($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5F38);
    // 0x8000E86C: b           L_8000E8C4
    // 0x8000E870: sub.s       $f0, $f10, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f0.fl;
        goto L_8000E8C4;
    // 0x8000E870: sub.s       $f0, $f10, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8000E874: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_8000E878:
    // 0x8000E878: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000E87C: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x8000E880: nop

    // 0x8000E884: bc1f        L_8000E894
    if (!c1cs) {
        // 0x8000E888: nop
    
            goto L_8000E894;
    }
    // 0x8000E888: nop

    // 0x8000E88C: b           L_8000E8C4
    // 0x8000E890: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8000E8C4;
    // 0x8000E890: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8000E894:
    // 0x8000E894: b           L_8000E8C4
    // 0x8000E898: lwc1        $f0, 0x5F3C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5F3C);
        goto L_8000E8C4;
    // 0x8000E898: lwc1        $f0, 0x5F3C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5F3C);
    // 0x8000E89C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_8000E8A0:
    // 0x8000E8A0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000E8A4: c.le.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl <= ctx->f20.fl;
    // 0x8000E8A8: nop

    // 0x8000E8AC: bc1f        L_8000E8C0
    if (!c1cs) {
        // 0x8000E8B0: nop
    
            goto L_8000E8C0;
    }
    // 0x8000E8B0: nop

    // 0x8000E8B4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000E8B8: b           L_8000E8C4
    // 0x8000E8BC: lwc1        $f0, 0x5F40($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5F40);
        goto L_8000E8C4;
    // 0x8000E8BC: lwc1        $f0, 0x5F40($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5F40);
L_8000E8C0:
    // 0x8000E8C0: lwc1        $f0, 0x5F44($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5F44);
L_8000E8C4:
    // 0x8000E8C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000E8C8:
    // 0x8000E8C8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8000E8CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000E8D0: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000E8D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000E8D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000E8DC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8000E8E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000E8E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000E8E8: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x8000E8EC: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    // 0x8000E8F0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8000E8F4: bc1fl       L_8000E90C
    if (!c1cs) {
        // 0x8000E8F8: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_8000E90C;
    }
    goto skip_0;
    // 0x8000E8F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_0:
    // 0x8000E8FC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000E900: b           L_8000E968
    // 0x8000E904: lwc1        $f0, 0x5F48($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5F48);
        goto L_8000E968;
    // 0x8000E904: lwc1        $f0, 0x5F48($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5F48);
    // 0x8000E908: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_8000E90C:
    // 0x8000E90C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000E910: c.le.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl <= ctx->f4.fl;
    // 0x8000E914: nop

    // 0x8000E918: bc1fl       L_8000E92C
    if (!c1cs) {
        // 0x8000E91C: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_8000E92C;
    }
    goto skip_1;
    // 0x8000E91C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_1:
    // 0x8000E920: b           L_8000E968
    // 0x8000E924: lwc1        $f0, 0x5F4C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5F4C);
        goto L_8000E968;
    // 0x8000E924: lwc1        $f0, 0x5F4C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5F4C);
    // 0x8000E928: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_8000E92C:
    // 0x8000E92C: nop

    // 0x8000E930: c.eq.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl == ctx->f6.fl;
    // 0x8000E934: nop

    // 0x8000E938: bc1f        L_8000E94C
    if (!c1cs) {
        // 0x8000E93C: nop
    
            goto L_8000E94C;
    }
    // 0x8000E93C: nop

    // 0x8000E940: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8000E944: b           L_8000E96C
    // 0x8000E948: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000E96C;
    // 0x8000E948: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000E94C:
    // 0x8000E94C: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8000E950: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    // 0x8000E954: jal         0x8004F640
    // 0x8000E958: sub.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f8.fl;
    func_8004F640(rdram, ctx);
        goto after_0;
    // 0x8000E958: sub.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f8.fl;
    after_0:
    // 0x8000E95C: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8000E960: jal         0x8000E604
    // 0x8000E964: div.s       $f12, $f14, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    func_8000E604(rdram, ctx);
        goto after_1;
    // 0x8000E964: div.s       $f12, $f14, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    after_1:
L_8000E968:
    // 0x8000E968: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000E96C:
    // 0x8000E96C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000E970: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000E978(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000E978: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000E97C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000E980: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000E984: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000E988: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x8000E98C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8000E990: bc1fl       L_8000E9A8
    if (!c1cs) {
        // 0x8000E994: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_8000E9A8;
    }
    goto skip_0;
    // 0x8000E994: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_0:
    // 0x8000E998: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8000E99C: b           L_8000E9FC
    // 0x8000E9A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000E9FC;
    // 0x8000E9A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000E9A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_8000E9A8:
    // 0x8000E9A8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000E9AC: c.le.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl <= ctx->f6.fl;
    // 0x8000E9B0: nop

    // 0x8000E9B4: bc1fl       L_8000E9C8
    if (!c1cs) {
        // 0x8000E9B8: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_8000E9C8;
    }
    goto skip_1;
    // 0x8000E9B8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_1:
    // 0x8000E9BC: b           L_8000E9F8
    // 0x8000E9C0: lwc1        $f0, 0x5F50($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5F50);
        goto L_8000E9F8;
    // 0x8000E9C0: lwc1        $f0, 0x5F50($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5F50);
    // 0x8000E9C4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_8000E9C8:
    // 0x8000E9C8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000E9CC: c.eq.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl == ctx->f8.fl;
    // 0x8000E9D0: nop

    // 0x8000E9D4: bc1f        L_8000E9E4
    if (!c1cs) {
        // 0x8000E9D8: nop
    
            goto L_8000E9E4;
    }
    // 0x8000E9D8: nop

    // 0x8000E9DC: b           L_8000E9F8
    // 0x8000E9E0: lwc1        $f0, 0x5F54($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5F54);
        goto L_8000E9F8;
    // 0x8000E9E0: lwc1        $f0, 0x5F54($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5F54);
L_8000E9E4:
    // 0x8000E9E4: jal         0x8000E8D8
    // 0x8000E9E8: nop

    func_8000E8D8(rdram, ctx);
        goto after_0;
    // 0x8000E9E8: nop

    after_0:
    // 0x8000E9EC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000E9F0: lwc1        $f10, 0x5F58($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5F58);
    // 0x8000E9F4: sub.s       $f0, $f10, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f0.fl;
L_8000E9F8:
    // 0x8000E9F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000E9FC:
    // 0x8000E9FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000EA00: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000EA08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000EA08: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8000EA0C: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8000EA10: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8000EA14: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    // 0x8000EA18: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8000EA1C: c.lt.d      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.d < ctx->f12.d;
    // 0x8000EA20: addiu       $v1, $zero, 0x14
    ctx->r3 = ADD32(0, 0X14);
    // 0x8000EA24: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    // 0x8000EA28: addiu       $a2, $zero, 0x27
    ctx->r6 = ADD32(0, 0X27);
    // 0x8000EA2C: bc1f        L_8000EA40
    if (!c1cs) {
        // 0x8000EA30: addiu       $t0, $zero, 0x25
        ctx->r8 = ADD32(0, 0X25);
            goto L_8000EA40;
    }
    // 0x8000EA30: addiu       $t0, $zero, 0x25
    ctx->r8 = ADD32(0, 0X25);
    // 0x8000EA34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000EA38: b           L_8000EA6C
    // 0x8000EA3C: div.d       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f12.d); 
    ctx->f12.d = DIV_D(ctx->f14.d, ctx->f12.d);
        goto L_8000EA6C;
    // 0x8000EA3C: div.d       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f12.d); 
    ctx->f12.d = DIV_D(ctx->f14.d, ctx->f12.d);
L_8000EA40:
    // 0x8000EA40: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x8000EA44: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8000EA48: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000EA4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000EA50: c.lt.d      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.d < ctx->f4.d;
    // 0x8000EA54: nop

    // 0x8000EA58: bc1f        L_8000EA6C
    if (!c1cs) {
        // 0x8000EA5C: nop
    
            goto L_8000EA6C;
    }
    // 0x8000EA5C: nop

    // 0x8000EA60: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8000EA64: b           L_8000EA6C
    // 0x8000EA68: div.d       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f12.d); 
    ctx->f12.d = DIV_D(ctx->f14.d, ctx->f12.d);
        goto L_8000EA6C;
    // 0x8000EA68: div.d       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f12.d); 
    ctx->f12.d = DIV_D(ctx->f14.d, ctx->f12.d);
L_8000EA6C:
    // 0x8000EA6C: addiu       $t2, $zero, 0x23
    ctx->r10 = ADD32(0, 0X23);
L_8000EA70:
    // 0x8000EA70: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000EA74: mtc1        $a0, $f18
    ctx->f18.u32l = ctx->r4;
    // 0x8000EA78: addiu       $a1, $v1, -0x1
    ctx->r5 = ADD32(ctx->r3, -0X1);
    // 0x8000EA7C: addiu       $a3, $v1, -0x2
    ctx->r7 = ADD32(ctx->r3, -0X2);
    // 0x8000EA80: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x8000EA84: addiu       $t1, $v1, -0x3
    ctx->r9 = ADD32(ctx->r3, -0X3);
    // 0x8000EA88: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8000EA8C: addiu       $a0, $a0, -0x8
    ctx->r4 = ADD32(ctx->r4, -0X8);
    // 0x8000EA90: mflo        $t6
    ctx->r14 = lo;
    // 0x8000EA94: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8000EA98: nop

    // 0x8000EA9C: multu       $a1, $a1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000EAA0: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x8000EAA4: add.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f4.d + ctx->f2.d;
    // 0x8000EAA8: mul.d       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x8000EAAC: mflo        $t7
    ctx->r15 = lo;
    // 0x8000EAB0: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8000EAB4: nop

    // 0x8000EAB8: multu       $a3, $a3
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000EABC: mul.d       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f12.d);
    // 0x8000EAC0: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x8000EAC4: mflo        $t8
    ctx->r24 = lo;
    // 0x8000EAC8: div.d       $f2, $f16, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f2.d = DIV_D(ctx->f16.d, ctx->f6.d);
    // 0x8000EACC: mul.d       $f18, $f10, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f12.d);
    // 0x8000EAD0: mtc1        $a2, $f16
    ctx->f16.u32l = ctx->r6;
    // 0x8000EAD4: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8000EAD8: multu       $t1, $t1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000EADC: addiu       $a2, $a2, -0x8
    ctx->r6 = ADD32(ctx->r6, -0X8);
    // 0x8000EAE0: cvt.d.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.d = CVT_D_W(ctx->f16.u32l);
    // 0x8000EAE4: mul.d       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f12.d);
    // 0x8000EAE8: mflo        $t9
    ctx->r25 = lo;
    // 0x8000EAEC: cvt.d.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
    // 0x8000EAF0: mul.d       $f16, $f18, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f18.d, ctx->f12.d);
    // 0x8000EAF4: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8000EAF8: add.d       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f6.d + ctx->f2.d;
    // 0x8000EAFC: mul.d       $f6, $f16, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f12.d);
    // 0x8000EB00: div.d       $f2, $f4, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f2.d = DIV_D(ctx->f4.d, ctx->f8.d);
    // 0x8000EB04: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8000EB08: addiu       $t0, $t0, -0x8
    ctx->r8 = ADD32(ctx->r8, -0X8);
    // 0x8000EB0C: cvt.d.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.d = CVT_D_W(ctx->f4.u32l);
    // 0x8000EB10: cvt.d.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.d = CVT_D_W(ctx->f18.u32l);
    // 0x8000EB14: mul.d       $f4, $f16, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f12.d);
    // 0x8000EB18: add.d       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f8.d + ctx->f2.d;
    // 0x8000EB1C: mul.d       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f12.d);
    // 0x8000EB20: div.d       $f2, $f6, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f2.d = DIV_D(ctx->f6.d, ctx->f10.d);
    // 0x8000EB24: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x8000EB28: addiu       $t2, $t2, -0x8
    ctx->r10 = ADD32(ctx->r10, -0X8);
    // 0x8000EB2C: cvt.d.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
    // 0x8000EB30: add.d       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f18.d = ctx->f10.d + ctx->f2.d;
    // 0x8000EB34: bne         $v1, $zero, L_8000EA70
    if (ctx->r3 != 0) {
        // 0x8000EB38: div.d       $f2, $f8, $f18
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f2.d = DIV_D(ctx->f8.d, ctx->f18.d);
            goto L_8000EA70;
    }
    // 0x8000EB38: div.d       $f2, $f8, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f2.d = DIV_D(ctx->f8.d, ctx->f18.d);
    // 0x8000EB3C: blez        $v0, L_8000EB5C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000EB40: nop
    
            goto L_8000EB5C;
    }
    // 0x8000EB40: nop

    // 0x8000EB44: add.d       $f4, $f14, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f14.d + ctx->f2.d;
    // 0x8000EB48: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000EB4C: ldc1        $f16, 0x5F60($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, 0X5F60);
    // 0x8000EB50: div.d       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f12.d, ctx->f4.d);
    // 0x8000EB54: jr          $ra
    // 0x8000EB58: sub.d       $f0, $f16, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f0.d = ctx->f16.d - ctx->f6.d;
    TRACE_RETURN()
    return;
    // 0x8000EB58: sub.d       $f0, $f16, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f0.d = ctx->f16.d - ctx->f6.d;
L_8000EB5C:
    // 0x8000EB5C: bgezl       $v0, L_8000EB80
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000EB60: add.d       $f4, $f14, $f2
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f14.d + ctx->f2.d;
            goto L_8000EB80;
    }
    goto skip_0;
    // 0x8000EB60: add.d       $f4, $f14, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f14.d + ctx->f2.d;
    skip_0:
    // 0x8000EB64: add.d       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f14.d + ctx->f2.d;
    // 0x8000EB68: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000EB6C: ldc1        $f10, 0x5F68($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X5F68);
    // 0x8000EB70: div.d       $f18, $f12, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = DIV_D(ctx->f12.d, ctx->f8.d);
    // 0x8000EB74: jr          $ra
    // 0x8000EB78: sub.d       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = ctx->f10.d - ctx->f18.d;
    TRACE_RETURN()
    return;
    // 0x8000EB78: sub.d       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = ctx->f10.d - ctx->f18.d;
    // 0x8000EB7C: add.d       $f4, $f14, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f14.d + ctx->f2.d;
L_8000EB80:
    // 0x8000EB80: div.d       $f0, $f12, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = DIV_D(ctx->f12.d, ctx->f4.d);
    // 0x8000EB84: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000EB8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000EB8C: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    // 0x8000EB90: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8000EB94: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000EB98: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8000EB9C: c.eq.d      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.d == ctx->f2.d;
    // 0x8000EBA0: mov.d       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.d = ctx->f12.d;
    // 0x8000EBA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000EBA8: bc1fl       L_8000EBCC
    if (!c1cs) {
        // 0x8000EBAC: c.eq.d      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.d == ctx->f2.d;
            goto L_8000EBCC;
    }
    goto skip_0;
    // 0x8000EBAC: c.eq.d      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.d == ctx->f2.d;
    skip_0:
    // 0x8000EBB0: c.eq.d      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.d == ctx->f2.d;
    // 0x8000EBB4: nop

    // 0x8000EBB8: bc1fl       L_8000EBCC
    if (!c1cs) {
        // 0x8000EBBC: c.eq.d      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.d == ctx->f2.d;
            goto L_8000EBCC;
    }
    goto skip_1;
    // 0x8000EBBC: c.eq.d      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.d == ctx->f2.d;
    skip_1:
    // 0x8000EBC0: b           L_8000EC90
    // 0x8000EBC4: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
        goto L_8000EC90;
    // 0x8000EBC4: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
    // 0x8000EBC8: c.eq.d      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.d == ctx->f2.d;
L_8000EBCC:
    // 0x8000EBCC: nop

    // 0x8000EBD0: bc1tl       L_8000EC74
    if (c1cs) {
        // 0x8000EBD4: c.le.d      $f2, $f20
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.d <= ctx->f20.d;
            goto L_8000EC74;
    }
    goto skip_2;
    // 0x8000EBD4: c.le.d      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.d <= ctx->f20.d;
    skip_2:
    // 0x8000EBD8: c.eq.d      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.d == ctx->f2.d;
    // 0x8000EBDC: nop

    // 0x8000EBE0: bc1tl       L_8000EC54
    if (c1cs) {
        // 0x8000EBE4: c.lt.d      $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.d < ctx->f14.d;
            goto L_8000EC54;
    }
    goto skip_3;
    // 0x8000EBE4: c.lt.d      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.d < ctx->f14.d;
    skip_3:
    // 0x8000EBE8: c.lt.d      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.d < ctx->f14.d;
    // 0x8000EBEC: nop

    // 0x8000EBF0: bc1fl       L_8000EC0C
    if (!c1cs) {
        // 0x8000EBF4: c.lt.d      $f2, $f20
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.d < ctx->f20.d;
            goto L_8000EC0C;
    }
    goto skip_4;
    // 0x8000EBF4: c.lt.d      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.d < ctx->f20.d;
    skip_4:
    // 0x8000EBF8: jal         0x8000EA08
    // 0x8000EBFC: div.d       $f12, $f20, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f14.d); 
    ctx->f12.d = DIV_D(ctx->f20.d, ctx->f14.d);
    func_8000EA08(rdram, ctx);
        goto after_0;
    // 0x8000EBFC: div.d       $f12, $f20, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f14.d); 
    ctx->f12.d = DIV_D(ctx->f20.d, ctx->f14.d);
    after_0:
    // 0x8000EC00: b           L_8000EC94
    // 0x8000EC04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8000EC94;
    // 0x8000EC04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000EC08: c.lt.d      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.d < ctx->f20.d;
L_8000EC0C:
    // 0x8000EC0C: nop

    // 0x8000EC10: bc1fl       L_8000EC38
    if (!c1cs) {
        // 0x8000EC14: neg.d       $f8, $f14
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = -ctx->f14.d;
            goto L_8000EC38;
    }
    goto skip_5;
    // 0x8000EC14: neg.d       $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = -ctx->f14.d;
    skip_5:
    // 0x8000EC18: neg.d       $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = -ctx->f14.d;
    // 0x8000EC1C: jal         0x8000EA08
    // 0x8000EC20: div.d       $f12, $f20, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f4.d); 
    ctx->f12.d = DIV_D(ctx->f20.d, ctx->f4.d);
    func_8000EA08(rdram, ctx);
        goto after_1;
    // 0x8000EC20: div.d       $f12, $f20, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f4.d); 
    ctx->f12.d = DIV_D(ctx->f20.d, ctx->f4.d);
    after_1:
    // 0x8000EC24: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000EC28: ldc1        $f6, 0x5F70($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X5F70);
    // 0x8000EC2C: b           L_8000EC90
    // 0x8000EC30: sub.d       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f6.d - ctx->f0.d;
        goto L_8000EC90;
    // 0x8000EC30: sub.d       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f6.d - ctx->f0.d;
    // 0x8000EC34: neg.d       $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = -ctx->f14.d;
L_8000EC38:
    // 0x8000EC38: jal         0x8000EA08
    // 0x8000EC3C: div.d       $f12, $f20, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f8.d); 
    ctx->f12.d = DIV_D(ctx->f20.d, ctx->f8.d);
    func_8000EA08(rdram, ctx);
        goto after_2;
    // 0x8000EC3C: div.d       $f12, $f20, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f8.d); 
    ctx->f12.d = DIV_D(ctx->f20.d, ctx->f8.d);
    after_2:
    // 0x8000EC40: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000EC44: ldc1        $f10, 0x5F78($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X5F78);
    // 0x8000EC48: b           L_8000EC90
    // 0x8000EC4C: sub.d       $f0, $f10, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f10.d - ctx->f0.d;
        goto L_8000EC90;
    // 0x8000EC4C: sub.d       $f0, $f10, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f10.d - ctx->f0.d;
    // 0x8000EC50: c.lt.d      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.d < ctx->f14.d;
L_8000EC54:
    // 0x8000EC54: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000EC58: bc1f        L_8000EC68
    if (!c1cs) {
        // 0x8000EC5C: nop
    
            goto L_8000EC68;
    }
    // 0x8000EC5C: nop

    // 0x8000EC60: b           L_8000EC90
    // 0x8000EC64: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
        goto L_8000EC90;
    // 0x8000EC64: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
L_8000EC68:
    // 0x8000EC68: b           L_8000EC90
    // 0x8000EC6C: ldc1        $f0, 0x5F80($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X5F80);
        goto L_8000EC90;
    // 0x8000EC6C: ldc1        $f0, 0x5F80($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X5F80);
    // 0x8000EC70: c.le.d      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.d <= ctx->f20.d;
L_8000EC74:
    // 0x8000EC74: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000EC78: bc1f        L_8000EC8C
    if (!c1cs) {
        // 0x8000EC7C: nop
    
            goto L_8000EC8C;
    }
    // 0x8000EC7C: nop

    // 0x8000EC80: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000EC84: b           L_8000EC90
    // 0x8000EC88: ldc1        $f0, 0x5F88($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X5F88);
        goto L_8000EC90;
    // 0x8000EC88: ldc1        $f0, 0x5F88($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X5F88);
L_8000EC8C:
    // 0x8000EC8C: ldc1        $f0, 0x5F90($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X5F90);
L_8000EC90:
    // 0x8000EC90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000EC94:
    // 0x8000EC94: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8000EC98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000EC9C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000ECA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000ECA4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8000ECA8: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8000ECAC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8000ECB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000ECB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000ECB8: c.le.d      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.d <= ctx->f12.d;
    // 0x8000ECBC: mov.d       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.d = ctx->f12.d;
    // 0x8000ECC0: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x8000ECC4: bc1fl       L_8000ECDC
    if (!c1cs) {
        // 0x8000ECC8: mtc1        $at, $f5
        ctx->f_odd[(5 - 1) * 2] = ctx->r1;
            goto L_8000ECDC;
    }
    goto skip_0;
    // 0x8000ECC8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    skip_0:
    // 0x8000ECCC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000ECD0: b           L_8000ED3C
    // 0x8000ECD4: ldc1        $f0, 0x5F98($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X5F98);
        goto L_8000ED3C;
    // 0x8000ECD4: ldc1        $f0, 0x5F98($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X5F98);
    // 0x8000ECD8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
L_8000ECDC:
    // 0x8000ECDC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000ECE0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000ECE4: c.le.d      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.d <= ctx->f4.d;
    // 0x8000ECE8: nop

    // 0x8000ECEC: bc1fl       L_8000ED00
    if (!c1cs) {
        // 0x8000ECF0: mtc1        $zero, $f3
        ctx->f_odd[(3 - 1) * 2] = 0;
            goto L_8000ED00;
    }
    goto skip_1;
    // 0x8000ECF0: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    skip_1:
    // 0x8000ECF4: b           L_8000ED3C
    // 0x8000ECF8: ldc1        $f0, 0x5FA0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X5FA0);
        goto L_8000ED3C;
    // 0x8000ECF8: ldc1        $f0, 0x5FA0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X5FA0);
    // 0x8000ECFC: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
L_8000ED00:
    // 0x8000ED00: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8000ED04: nop

    // 0x8000ED08: c.eq.d      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.d == ctx->f2.d;
    // 0x8000ED0C: nop

    // 0x8000ED10: bc1f        L_8000ED20
    if (!c1cs) {
        // 0x8000ED14: nop
    
            goto L_8000ED20;
    }
    // 0x8000ED14: nop

    // 0x8000ED18: b           L_8000ED3C
    // 0x8000ED1C: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
        goto L_8000ED3C;
    // 0x8000ED1C: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
L_8000ED20:
    // 0x8000ED20: mul.d       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = MUL_D(ctx->f14.d, ctx->f14.d);
    // 0x8000ED24: sdc1        $f14, 0x18($sp)
    CHECK_FR(ctx, 14);
    SD(ctx->f14.u64, 0X18, ctx->r29);
    // 0x8000ED28: jal         0x8000E588
    // 0x8000ED2C: sub.d       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f12.d = ctx->f0.d - ctx->f6.d;
    func_8000E588(rdram, ctx);
        goto after_0;
    // 0x8000ED2C: sub.d       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f12.d = ctx->f0.d - ctx->f6.d;
    after_0:
    // 0x8000ED30: ldc1        $f14, 0x18($sp)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r29, 0X18);
    // 0x8000ED34: jal         0x8000EA08
    // 0x8000ED38: div.d       $f12, $f14, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f0.d); 
    ctx->f12.d = DIV_D(ctx->f14.d, ctx->f0.d);
    func_8000EA08(rdram, ctx);
        goto after_1;
    // 0x8000ED38: div.d       $f12, $f14, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f0.d); 
    ctx->f12.d = DIV_D(ctx->f14.d, ctx->f0.d);
    after_1:
L_8000ED3C:
    // 0x8000ED3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000ED40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000ED44: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000ED4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000ED4C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8000ED50: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8000ED54: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000ED58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000ED5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000ED60: c.le.d      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.d <= ctx->f12.d;
    // 0x8000ED64: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x8000ED68: bc1fl       L_8000ED84
    if (!c1cs) {
        // 0x8000ED6C: mtc1        $at, $f7
        ctx->f_odd[(7 - 1) * 2] = ctx->r1;
            goto L_8000ED84;
    }
    goto skip_0;
    // 0x8000ED6C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    skip_0:
    // 0x8000ED70: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x8000ED74: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8000ED78: b           L_8000EDE0
    // 0x8000ED7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000EDE0;
    // 0x8000ED7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000ED80: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
L_8000ED84:
    // 0x8000ED84: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8000ED88: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000ED8C: c.le.d      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.d <= ctx->f6.d;
    // 0x8000ED90: nop

    // 0x8000ED94: bc1fl       L_8000EDA8
    if (!c1cs) {
        // 0x8000ED98: mtc1        $zero, $f9
        ctx->f_odd[(9 - 1) * 2] = 0;
            goto L_8000EDA8;
    }
    goto skip_1;
    // 0x8000ED98: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    skip_1:
    // 0x8000ED9C: b           L_8000EDDC
    // 0x8000EDA0: ldc1        $f0, 0x5FA8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X5FA8);
        goto L_8000EDDC;
    // 0x8000EDA0: ldc1        $f0, 0x5FA8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X5FA8);
    // 0x8000EDA4: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
L_8000EDA8:
    // 0x8000EDA8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8000EDAC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000EDB0: c.eq.d      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.d == ctx->f8.d;
    // 0x8000EDB4: nop

    // 0x8000EDB8: bc1f        L_8000EDC8
    if (!c1cs) {
        // 0x8000EDBC: nop
    
            goto L_8000EDC8;
    }
    // 0x8000EDBC: nop

    // 0x8000EDC0: b           L_8000EDDC
    // 0x8000EDC4: ldc1        $f0, 0x5FB0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X5FB0);
        goto L_8000EDDC;
    // 0x8000EDC4: ldc1        $f0, 0x5FB0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X5FB0);
L_8000EDC8:
    // 0x8000EDC8: jal         0x8000ECA4
    // 0x8000EDCC: nop

    func_8000ECA4(rdram, ctx);
        goto after_0;
    // 0x8000EDCC: nop

    after_0:
    // 0x8000EDD0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000EDD4: ldc1        $f10, 0x5FB8($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X5FB8);
    // 0x8000EDD8: sub.d       $f0, $f10, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f10.d - ctx->f0.d;
L_8000EDDC:
    // 0x8000EDDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000EDE0:
    // 0x8000EDE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000EDE4: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000EDEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000EDEC: bltz        $a1, L_8000EDFC
    if (SIGNED(ctx->r5) < 0) {
        // 0x8000EDF0: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8000EDFC;
    }
    // 0x8000EDF0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000EDF4: b           L_8000EE00
    // 0x8000EDF8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_8000EE00;
    // 0x8000EDF8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8000EDFC:
    // 0x8000EDFC: negu        $v0, $a1
    ctx->r2 = SUB32(0, ctx->r5);
L_8000EE00:
    // 0x8000EE00: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8000EE04: beq         $v0, $zero, L_8000EE2C
    if (ctx->r2 == 0) {
        // 0x8000EE08: mov.s       $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
            goto L_8000EE2C;
    }
    // 0x8000EE08: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
L_8000EE0C:
    // 0x8000EE0C: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8000EE10: beq         $t6, $zero, L_8000EE20
    if (ctx->r14 == 0) {
        // 0x8000EE14: srl         $t7, $v0, 1
        ctx->r15 = S32(U32(ctx->r2) >> 1);
            goto L_8000EE20;
    }
    // 0x8000EE14: srl         $t7, $v0, 1
    ctx->r15 = S32(U32(ctx->r2) >> 1);
    // 0x8000EE18: mul.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x8000EE1C: nop

L_8000EE20:
    // 0x8000EE20: mul.s       $f12, $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8000EE24: bne         $t7, $zero, L_8000EE0C
    if (ctx->r15 != 0) {
        // 0x8000EE28: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_8000EE0C;
    }
    // 0x8000EE28: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8000EE2C:
    // 0x8000EE2C: bltzl       $a1, L_8000EE40
    if (SIGNED(ctx->r5) < 0) {
        // 0x8000EE30: div.s       $f0, $f14, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f14.fl, ctx->f2.fl);
            goto L_8000EE40;
    }
    goto skip_0;
    // 0x8000EE30: div.s       $f0, $f14, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f14.fl, ctx->f2.fl);
    skip_0:
    // 0x8000EE34: jr          $ra
    // 0x8000EE38: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    TRACE_RETURN()
    return;
    // 0x8000EE38: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8000EE3C: div.s       $f0, $f14, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f14.fl, ctx->f2.fl);
L_8000EE40:
    // 0x8000EE40: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000EE48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000EE48: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8000EE4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000EE50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000EE54: c.eq.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl == ctx->f0.fl;
    // 0x8000EE58: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000EE5C: bc1fl       L_8000EE74
    if (!c1cs) {
        // 0x8000EE60: c.eq.s      $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
            goto L_8000EE74;
    }
    goto skip_0;
    // 0x8000EE60: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
    skip_0:
    // 0x8000EE64: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8000EE68: b           L_8000EF20
    // 0x8000EE6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000EF20;
    // 0x8000EE6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000EE70: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
L_8000EE74:
    // 0x8000EE74: nop

    // 0x8000EE78: bc1fl       L_8000EE90
    if (!c1cs) {
        // 0x8000EE7C: trunc.w.s   $f4, $f14
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    ctx->f4.u32l = TRUNC_W_S(ctx->f14.fl);
            goto L_8000EE90;
    }
    goto skip_1;
    // 0x8000EE7C: trunc.w.s   $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    ctx->f4.u32l = TRUNC_W_S(ctx->f14.fl);
    skip_1:
    // 0x8000EE80: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8000EE84: b           L_8000EF20
    // 0x8000EE88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000EF20;
    // 0x8000EE88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000EE8C: trunc.w.s   $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    ctx->f4.u32l = TRUNC_W_S(ctx->f14.fl);
L_8000EE90:
    // 0x8000EE90: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x8000EE94: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8000EE98: nop

    // 0x8000EE9C: slt         $at, $a1, $at
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8000EEA0: beq         $at, $zero, L_8000EEE4
    if (ctx->r1 == 0) {
        // 0x8000EEA4: lui         $at, 0xFF00
        ctx->r1 = S32(0XFF00 << 16);
            goto L_8000EEE4;
    }
    // 0x8000EEA4: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x8000EEA8: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8000EEAC: slt         $at, $a1, $at
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8000EEB0: bnel        $at, $zero, L_8000EEE8
    if (ctx->r1 != 0) {
        // 0x8000EEB4: c.lt.s      $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
            goto L_8000EEE8;
    }
    goto skip_2;
    // 0x8000EEB4: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    skip_2:
    // 0x8000EEB8: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x8000EEBC: nop

    // 0x8000EEC0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000EEC4: c.eq.s      $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f14.fl == ctx->f8.fl;
    // 0x8000EEC8: nop

    // 0x8000EECC: bc1fl       L_8000EEE8
    if (!c1cs) {
        // 0x8000EED0: c.lt.s      $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
            goto L_8000EEE8;
    }
    goto skip_3;
    // 0x8000EED0: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    skip_3:
    // 0x8000EED4: jal         0x8000EDEC
    // 0x8000EED8: nop

    func_8000EDEC(rdram, ctx);
        goto after_0;
    // 0x8000EED8: nop

    after_0:
    // 0x8000EEDC: b           L_8000EF20
    // 0x8000EEE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000EF20;
    // 0x8000EEE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000EEE4:
    // 0x8000EEE4: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
L_8000EEE8:
    // 0x8000EEE8: nop

    // 0x8000EEEC: bc1fl       L_8000EF18
    if (!c1cs) {
        // 0x8000EEF0: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8000EF18;
    }
    goto skip_4;
    // 0x8000EEF0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_4:
    // 0x8000EEF4: jal         0x8000EF2C
    // 0x8000EEF8: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    func_8000EF2C(rdram, ctx);
        goto after_1;
    // 0x8000EEF8: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x8000EEFC: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8000EF00: mul.s       $f12, $f0, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x8000EF04: jal         0x8000F094
    // 0x8000EF08: nop

    func_8000F094(rdram, ctx);
        goto after_2;
    // 0x8000EF08: nop

    after_2:
    // 0x8000EF0C: b           L_8000EF20
    // 0x8000EF10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000EF20;
    // 0x8000EF10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000EF14: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_8000EF18:
    // 0x8000EF18: nop

    // 0x8000EF1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000EF20:
    // 0x8000EF20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000EF24: jr          $ra
    TRACE_RETURN()
    return;
;}
