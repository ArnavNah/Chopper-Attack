#include "recomp.h"
#include "trace.h"
#include "funcs.h"

RECOMP_FUNC void func_8004267C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004267C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80042680: lw          $v0, -0x6BE0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6BE0);
    // 0x80042684: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80042688: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004268C: andi        $t6, $v0, 0x8000
    ctx->r14 = ctx->r2 & 0X8000;
    // 0x80042690: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80042694: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80042698: beq         $t6, $zero, L_800426A8
    if (ctx->r14 == 0) {
        // 0x8004269C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800426A8;
    }
    // 0x8004269C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800426A0: b           L_800427C0
    // 0x800426A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800427C0;
    // 0x800426A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800426A8:
    // 0x800426A8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800426AC: lh          $t7, -0x68CA($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X68CA);
    // 0x800426B0: andi        $t8, $v0, 0x80
    ctx->r24 = ctx->r2 & 0X80;
    // 0x800426B4: beq         $t7, $zero, L_800426C4
    if (ctx->r15 == 0) {
        // 0x800426B8: nop
    
            goto L_800426C4;
    }
    // 0x800426B8: nop

    // 0x800426BC: b           L_800427C0
    // 0x800426C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800427C0;
    // 0x800426C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800426C4:
    // 0x800426C4: beq         $t8, $zero, L_800426D4
    if (ctx->r24 == 0) {
        // 0x800426C8: lui         $t9, 0x8013
        ctx->r25 = S32(0X8013 << 16);
            goto L_800426D4;
    }
    // 0x800426C8: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800426CC: b           L_800427C0
    // 0x800426D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800427C0;
    // 0x800426D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800426D4:
    // 0x800426D4: lh          $t9, -0x6938($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X6938);
    // 0x800426D8: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800426DC: addiu       $v0, $t0, -0x6A20
    ctx->r2 = ADD32(ctx->r8, -0X6A20);
    // 0x800426E0: blez        $t9, L_800427BC
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800426E4: addiu       $v1, $sp, 0x24
        ctx->r3 = ADD32(ctx->r29, 0X24);
            goto L_800427BC;
    }
    // 0x800426E4: addiu       $v1, $sp, 0x24
    ctx->r3 = ADD32(ctx->r29, 0X24);
    // 0x800426E8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800426EC: addiu       $a1, $a1, -0x6A14
    ctx->r5 = ADD32(ctx->r5, -0X6A14);
    // 0x800426F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800426F4: lh          $t1, 0xE2($a0)
    ctx->r9 = MEM_H(ctx->r4, 0XE2);
    // 0x800426F8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800426FC: mtc1        $t1, $f14
    ctx->f14.u32l = ctx->r9;
    // 0x80042700: beq         $v0, $a1, L_80042730
    if (ctx->r2 == ctx->r5) {
        // 0x80042704: cvt.s.w     $f18, $f14
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    ctx->f18.fl = CVT_S_W(ctx->f14.u32l);
            goto L_80042730;
    }
    // 0x80042704: cvt.s.w     $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    ctx->f18.fl = CVT_S_W(ctx->f14.u32l);
L_80042708:
    // 0x80042708: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8004270C: lh          $t1, 0xE4($a0)
    ctx->r9 = MEM_H(ctx->r4, 0XE4);
    // 0x80042710: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80042714: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80042718: mtc1        $t1, $f14
    ctx->f14.u32l = ctx->r9;
    // 0x8004271C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80042720: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80042724: cvt.s.w     $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    ctx->f18.fl = CVT_S_W(ctx->f14.u32l);
    // 0x80042728: bne         $v0, $a1, L_80042708
    if (ctx->r2 != ctx->r5) {
        // 0x8004272C: swc1        $f16, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f16.u32l;
            goto L_80042708;
    }
    // 0x8004272C: swc1        $f16, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f16.u32l;
L_80042730:
    // 0x80042730: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80042734: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80042738: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8004273C: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80042740: swc1        $f16, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f16.u32l;
    // 0x80042744: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80042748: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8004274C: jal         0x80003668
    // 0x80042750: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    func_80003668(rdram, ctx);
        goto after_0;
    // 0x80042750: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x80042754: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80042758: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x8004275C: lh          $t4, -0x6940($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X6940);
    // 0x80042760: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80042764: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x80042768: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x8004276C: lh          $t6, 0x46($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X46);
    // 0x80042770: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80042774: beql        $at, $zero, L_800427C0
    if (ctx->r1 == 0) {
        // 0x80042778: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_800427C0;
    }
    goto skip_0;
    // 0x80042778: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    skip_0:
    // 0x8004277C: lh          $t5, -0x6938($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X6938);
    // 0x80042780: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80042784: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80042788: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x8004278C: sh          $t7, -0x6938($at)
    MEM_H(-0X6938, ctx->r1) = ctx->r15;
    // 0x80042790: lh          $t8, -0x68E2($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X68E2);
    // 0x80042794: sll         $t0, $t7, 16
    ctx->r8 = S32(ctx->r15 << 16);
    // 0x80042798: sra         $t1, $t0, 16
    ctx->r9 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8004279C: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800427A0: beq         $t9, $zero, L_800427B8
    if (ctx->r25 == 0) {
        // 0x800427A4: lui         $a2, 0x8013
        ctx->r6 = S32(0X8013 << 16);
            goto L_800427B8;
    }
    // 0x800427A4: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800427A8: bgtz        $t1, L_800427B8
    if (SIGNED(ctx->r9) > 0) {
        // 0x800427AC: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_800427B8;
    }
    // 0x800427AC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800427B0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800427B4: sh          $t2, -0x6938($at)
    MEM_H(-0X6938, ctx->r1) = ctx->r10;
L_800427B8:
    // 0x800427B8: lh          $a2, -0x692E($a2)
    ctx->r6 = MEM_H(ctx->r6, -0X692E);
L_800427BC:
    // 0x800427BC: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_800427C0:
    // 0x800427C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800427C4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800427C8: jr          $ra
    TRACE_RETURN()
    return;
;}
static void func_800427D0_entry(uint8_t* rdram, recomp_context* ctx, unsigned entry) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    if (entry == 1) goto indirect_800428C0;

    // 0x800427D0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800427D4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800427D8: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800427DC: lw          $s2, -0x6590($s2)
    ctx->r18 = MEM_W(ctx->r18, -0X6590);
    // 0x800427E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800427E4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800427E8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800427EC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800427F0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800427F4: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800427F8: lh          $t6, 0x4($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X4);
    // 0x800427FC: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80042800: blezl       $t6, L_80042898
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80042804: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80042898;
    }
    goto skip_0;
    // 0x80042804: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80042808: lh          $t7, 0x6($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X6);
    // 0x8004280C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80042810: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80042814: blezl       $t7, L_80042898
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80042818: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80042898;
    }
    goto skip_1;
    // 0x80042818: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8004281C: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
L_80042820:
    // 0x80042820: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x80042824: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x80042828: lh          $t0, 0x7A($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X7A);
    // 0x8004282C: addiu       $a0, $v0, 0x58
    ctx->r4 = ADD32(ctx->r2, 0X58);
    // 0x80042830: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x80042834: beql        $t1, $zero, L_80042880
    if (ctx->r9 == 0) {
        // 0x80042838: lh          $t9, 0x6($s2)
        ctx->r25 = MEM_H(ctx->r18, 0X6);
            goto L_80042880;
    }
    goto skip_2;
    // 0x80042838: lh          $t9, 0x6($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X6);
    skip_2:
    // 0x8004283C: jal         0x80003668
    // 0x80042840: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_80003668(rdram, ctx);
        goto after_0;
    // 0x80042840: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_0:
    // 0x80042844: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80042848: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x8004284C: nop

    // 0x80042850: slti        $at, $t3, 0x7
    ctx->r1 = SIGNED(ctx->r11) < 0X7 ? 1 : 0;
    // 0x80042854: beql        $at, $zero, L_80042880
    if (ctx->r1 == 0) {
        // 0x80042858: lh          $t9, 0x6($s2)
        ctx->r25 = MEM_H(ctx->r18, 0X6);
            goto L_80042880;
    }
    goto skip_3;
    // 0x80042858: lh          $t9, 0x6($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X6);
    skip_3:
    // 0x8004285C: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80042860: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80042864: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80042868: addu        $t6, $t5, $s0
    ctx->r14 = ADD32(ctx->r13, ctx->r16);
    // 0x8004286C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80042870: sh          $t4, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r12;
    // 0x80042874: b           L_80042894
    // 0x80042878: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
        goto L_80042894;
    // 0x80042878: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x8004287C: lh          $t9, 0x6($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X6);
L_80042880:
    // 0x80042880: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80042884: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80042888: slt         $at, $s1, $t9
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8004288C: bnel        $at, $zero, L_80042820
    if (ctx->r1 != 0) {
        // 0x80042890: lw          $t8, 0x0($s2)
        ctx->r24 = MEM_W(ctx->r18, 0X0);
            goto L_80042820;
    }
    goto skip_4;
    // 0x80042890: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    skip_4:
L_80042894:
    // 0x80042894: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80042898:
    // 0x80042898: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8004289C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800428A0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800428A4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800428A8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800428AC: jr          $ra
    // 0x800428B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    TRACE_RETURN()
    return;
    // 0x800428B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800428B4: nop

    // 0x800428B8: nop

    // 0x800428BC: nop

indirect_800428C0:
    // 0x800428C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800428C4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800428C8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800428CC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800428D0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800428D4: jal         0x80042998
    // 0x800428D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_80042998(rdram, ctx);
        goto after_1;
    // 0x800428D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_1:
    // 0x800428DC: jal         0x80042F04
    // 0x800428E0: nop

    func_80042F04(rdram, ctx);
        goto after_2;
    // 0x800428E0: nop

    after_2:
    // 0x800428E4: jal         0x80043698
    // 0x800428E8: nop

    func_80043698(rdram, ctx);
        goto after_3;
    // 0x800428E8: nop

    after_3:
    // 0x800428EC: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x800428F0: addiu       $s0, $zero, -0x2
    ctx->r16 = ADD32(0, -0X2);
    // 0x800428F4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_800428F8:
    // 0x800428F8: bne         $s2, $v0, L_8004292C
    if (ctx->r18 != ctx->r2) {
        // 0x800428FC: nop
    
            goto L_8004292C;
    }
    // 0x800428FC: nop

    // 0x80042900: jal         0x80042E78
    // 0x80042904: nop

    func_80042E78(rdram, ctx);
        goto after_4;
    // 0x80042904: nop

    after_4:
    // 0x80042908: jal         0x8004360C
    // 0x8004290C: nop

    func_8004360C(rdram, ctx);
        goto after_5;
    // 0x8004290C: nop

    after_5:
    // 0x80042910: jal         0x80043D5C
    // 0x80042914: nop

    func_80043D5C(rdram, ctx);
        goto after_6;
    // 0x80042914: nop

    after_6:
    // 0x80042918: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_8004291C:
    // 0x8004291C: jal         0x8000798C
    // 0x80042920: nop

    func_8000798C(rdram, ctx);
        goto after_7;
    // 0x80042920: nop

    after_7:
    // 0x80042924: b           L_8004291C
    // 0x80042928: nop

        goto L_8004291C;
    // 0x80042928: nop

L_8004292C:
    // 0x8004292C: bne         $s0, $v0, L_80042950
    if (ctx->r16 != ctx->r2) {
        // 0x80042930: nop
    
            goto L_80042950;
    }
    // 0x80042930: nop

    // 0x80042934: bne         $s0, $v0, L_80042950
    if (ctx->r16 != ctx->r2) {
        // 0x80042938: nop
    
            goto L_80042950;
    }
    // 0x80042938: nop

L_8004293C:
    // 0x8004293C: jal         0x8000798C
    // 0x80042940: nop

    func_8000798C(rdram, ctx);
        goto after_8;
    // 0x80042940: nop

    after_8:
    // 0x80042944: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80042948: beq         $s0, $t6, L_8004293C
    if (ctx->r16 == ctx->r14) {
        // 0x8004294C: nop
    
            goto L_8004293C;
    }
    // 0x8004294C: nop

L_80042950:
    // 0x80042950: jal         0x80042DC4
    // 0x80042954: nop

    func_80042DC4(rdram, ctx);
        goto after_9;
    // 0x80042954: nop

    after_9:
    // 0x80042958: jal         0x800433CC
    // 0x8004295C: nop

    func_800433CC(rdram, ctx);
        goto after_10;
    // 0x8004295C: nop

    after_10:
    // 0x80042960: jal         0x80043B44
    // 0x80042964: nop

    func_80043B44(rdram, ctx);
        goto after_11;
    // 0x80042964: nop

    after_11:
    // 0x80042968: jal         0x8000798C
    // 0x8004296C: nop

    func_8000798C(rdram, ctx);
        goto after_12;
    // 0x8004296C: nop

    after_12:
    // 0x80042970: b           L_800428F8
    // 0x80042974: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
        goto L_800428F8;
    // 0x80042974: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80042978: nop

    // 0x8004297C: nop

    // 0x80042980: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80042984: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80042988: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8004298C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80042990: jr          $ra
    // 0x80042994: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    TRACE_RETURN()
    return;
    // 0x80042994: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800427D0(uint8_t* rdram, recomp_context* ctx) { func_800427D0_entry(rdram, ctx, 0); }
RECOMP_FUNC void func_800428C0(uint8_t* rdram, recomp_context* ctx) { func_800427D0_entry(rdram, ctx, 1); }

RECOMP_FUNC void func_80042998(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80042998: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004299C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800429A0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800429A4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800429A8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800429AC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800429B0: lui         $s1, 0x801A
    ctx->r17 = S32(0X801A << 16);
    // 0x800429B4: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800429B8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800429BC: addiu       $s3, $s3, -0x650C
    ctx->r19 = ADD32(ctx->r19, -0X650C);
    // 0x800429C0: addiu       $s1, $s1, 0x2800
    ctx->r17 = ADD32(ctx->r17, 0X2800);
    // 0x800429C4: addiu       $s0, $s0, -0x6570
    ctx->r16 = ADD32(ctx->r16, -0X6570);
    // 0x800429C8: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
L_800429CC:
    // 0x800429CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800429D0: jal         0x80004364
    // 0x800429D4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x800429D4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_0:
    // 0x800429D8: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800429DC: sh          $s2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r18;
    // 0x800429E0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800429E4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800429E8: bne         $s0, $s3, L_800429CC
    if (ctx->r16 != ctx->r19) {
        // 0x800429EC: sh          $zero, 0xA($t6)
        MEM_H(0XA, ctx->r14) = 0;
            goto L_800429CC;
    }
    // 0x800429EC: sh          $zero, 0xA($t6)
    MEM_H(0XA, ctx->r14) = 0;
    // 0x800429F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800429F4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800429F8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800429FC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80042A00: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80042A04: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80042A08: sh          $zero, -0x650C($at)
    MEM_H(-0X650C, ctx->r1) = 0;
    // 0x80042A0C: jr          $ra
    // 0x80042A10: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    TRACE_RETURN()
    return;
    // 0x80042A10: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80042A14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80042A14: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80042A18: lh          $t6, -0x6B94($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X6B94);
    // 0x80042A1C: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x80042A20: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80042A24: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80042A28: sw          $a0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r4;
    // 0x80042A2C: bne         $t6, $zero, L_80042A3C
    if (ctx->r14 != 0) {
        // 0x80042A30: sw          $a1, 0xCC($sp)
        MEM_W(0XCC, ctx->r29) = ctx->r5;
            goto L_80042A3C;
    }
    // 0x80042A30: sw          $a1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r5;
    // 0x80042A34: b           L_80042DB0
    // 0x80042A38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80042DB0;
    // 0x80042A38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80042A3C:
    // 0x80042A3C: beq         $a2, $zero, L_80042A64
    if (ctx->r6 == 0) {
        // 0x80042A40: lui         $a0, 0x8007
        ctx->r4 = S32(0X8007 << 16);
            goto L_80042A64;
    }
    // 0x80042A40: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80042A44: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80042A48: beq         $a2, $at, L_80042A80
    if (ctx->r6 == ctx->r1) {
        // 0x80042A4C: lui         $a0, 0x8007
        ctx->r4 = S32(0X8007 << 16);
            goto L_80042A80;
    }
    // 0x80042A4C: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80042A50: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80042A54: beq         $a2, $at, L_80042A9C
    if (ctx->r6 == ctx->r1) {
        // 0x80042A58: lui         $a0, 0x8007
        ctx->r4 = S32(0X8007 << 16);
            goto L_80042A9C;
    }
    // 0x80042A58: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80042A5C: b           L_80042AB4
    // 0x80042A60: nop

        goto L_80042AB4;
    // 0x80042A60: nop

L_80042A64:
    // 0x80042A64: jal         0x80049CFC
    // 0x80042A68: addiu       $a0, $a0, 0x76D0
    ctx->r4 = ADD32(ctx->r4, 0X76D0);
    func_80049CFC(rdram, ctx);
        goto after_0;
    // 0x80042A68: addiu       $a0, $a0, 0x76D0
    ctx->r4 = ADD32(ctx->r4, 0X76D0);
    after_0:
    // 0x80042A6C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80042A70: lwc1        $f4, 0x785C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X785C);
    // 0x80042A74: sh          $v0, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r2;
    // 0x80042A78: b           L_80042AB4
    // 0x80042A7C: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
        goto L_80042AB4;
    // 0x80042A7C: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
L_80042A80:
    // 0x80042A80: jal         0x80049CFC
    // 0x80042A84: addiu       $a0, $a0, 0x76D8
    ctx->r4 = ADD32(ctx->r4, 0X76D8);
    func_80049CFC(rdram, ctx);
        goto after_1;
    // 0x80042A84: addiu       $a0, $a0, 0x76D8
    ctx->r4 = ADD32(ctx->r4, 0X76D8);
    after_1:
    // 0x80042A88: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80042A8C: lwc1        $f6, 0x7860($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7860);
    // 0x80042A90: sh          $v0, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r2;
    // 0x80042A94: b           L_80042AB4
    // 0x80042A98: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
        goto L_80042AB4;
    // 0x80042A98: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
L_80042A9C:
    // 0x80042A9C: jal         0x80049CFC
    // 0x80042AA0: addiu       $a0, $a0, 0x76E0
    ctx->r4 = ADD32(ctx->r4, 0X76E0);
    func_80049CFC(rdram, ctx);
        goto after_2;
    // 0x80042AA0: addiu       $a0, $a0, 0x76E0
    ctx->r4 = ADD32(ctx->r4, 0X76E0);
    after_2:
    // 0x80042AA4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80042AA8: lwc1        $f8, 0x7864($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7864);
    // 0x80042AAC: sh          $v0, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r2;
    // 0x80042AB0: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
L_80042AB4:
    // 0x80042AB4: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80042AB8: lh          $t0, -0x650C($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X650C);
    // 0x80042ABC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80042AC0: addiu       $a0, $a0, -0x6570
    ctx->r4 = ADD32(ctx->r4, -0X6570);
    // 0x80042AC4: slti        $at, $t0, 0x19
    ctx->r1 = SIGNED(ctx->r8) < 0X19 ? 1 : 0;
    // 0x80042AC8: bne         $at, $zero, L_80042BC0
    if (ctx->r1 != 0) {
        // 0x80042ACC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80042BC0;
    }
    // 0x80042ACC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80042AD0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80042AD4: lw          $t7, -0x6570($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6570);
    // 0x80042AD8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80042ADC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80042AE0: addiu       $a0, $a0, -0x656C
    ctx->r4 = ADD32(ctx->r4, -0X656C);
    // 0x80042AE4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80042AE8: addiu       $a3, $zero, 0x19
    ctx->r7 = ADD32(0, 0X19);
    // 0x80042AEC: lh          $v0, 0xA($t7)
    ctx->r2 = MEM_H(ctx->r15, 0XA);
L_80042AF0:
    // 0x80042AF0: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80042AF4: lh          $a1, 0xA($t8)
    ctx->r5 = MEM_H(ctx->r24, 0XA);
    // 0x80042AF8: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80042AFC: beql        $at, $zero, L_80042B20
    if (ctx->r1 == 0) {
        // 0x80042B00: lw          $t2, 0x4($a0)
        ctx->r10 = MEM_W(ctx->r4, 0X4);
            goto L_80042B20;
    }
    goto skip_0;
    // 0x80042B00: lw          $t2, 0x4($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X4);
    skip_0:
    // 0x80042B04: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x80042B08: sll         $a2, $v1, 16
    ctx->r6 = S32(ctx->r3 << 16);
    // 0x80042B0C: sra         $t9, $v0, 16
    ctx->r25 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80042B10: sra         $t1, $a2, 16
    ctx->r9 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80042B14: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80042B18: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x80042B1C: lw          $t2, 0x4($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X4);
L_80042B20:
    // 0x80042B20: lh          $a1, 0xA($t2)
    ctx->r5 = MEM_H(ctx->r10, 0XA);
    // 0x80042B24: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80042B28: beql        $at, $zero, L_80042B4C
    if (ctx->r1 == 0) {
        // 0x80042B2C: lw          $t6, 0x8($a0)
        ctx->r14 = MEM_W(ctx->r4, 0X8);
            goto L_80042B4C;
    }
    goto skip_1;
    // 0x80042B2C: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    skip_1:
    // 0x80042B30: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x80042B34: addiu       $a2, $v1, 0x1
    ctx->r6 = ADD32(ctx->r3, 0X1);
    // 0x80042B38: sll         $t4, $a2, 16
    ctx->r12 = S32(ctx->r6 << 16);
    // 0x80042B3C: sra         $t3, $v0, 16
    ctx->r11 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80042B40: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x80042B44: sra         $a2, $t4, 16
    ctx->r6 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80042B48: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
L_80042B4C:
    // 0x80042B4C: lh          $a1, 0xA($t6)
    ctx->r5 = MEM_H(ctx->r14, 0XA);
    // 0x80042B50: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80042B54: beql        $at, $zero, L_80042B78
    if (ctx->r1 == 0) {
        // 0x80042B58: lw          $t1, 0xC($a0)
        ctx->r9 = MEM_W(ctx->r4, 0XC);
            goto L_80042B78;
    }
    goto skip_2;
    // 0x80042B58: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    skip_2:
    // 0x80042B5C: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x80042B60: addiu       $a2, $v1, 0x2
    ctx->r6 = ADD32(ctx->r3, 0X2);
    // 0x80042B64: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x80042B68: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80042B6C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80042B70: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80042B74: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
L_80042B78:
    // 0x80042B78: lh          $a1, 0xA($t1)
    ctx->r5 = MEM_H(ctx->r9, 0XA);
    // 0x80042B7C: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80042B80: beql        $at, $zero, L_80042BA4
    if (ctx->r1 == 0) {
        // 0x80042B84: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80042BA4;
    }
    goto skip_3;
    // 0x80042B84: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_3:
    // 0x80042B88: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x80042B8C: addiu       $a2, $v1, 0x3
    ctx->r6 = ADD32(ctx->r3, 0X3);
    // 0x80042B90: sll         $t3, $a2, 16
    ctx->r11 = S32(ctx->r6 << 16);
    // 0x80042B94: sra         $t2, $v0, 16
    ctx->r10 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80042B98: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80042B9C: sra         $a2, $t3, 16
    ctx->r6 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80042BA0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80042BA4:
    // 0x80042BA4: bne         $v1, $a3, L_80042AF0
    if (ctx->r3 != ctx->r7) {
        // 0x80042BA8: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_80042AF0;
    }
    // 0x80042BA8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80042BAC: addiu       $t5, $t0, -0x1
    ctx->r13 = ADD32(ctx->r8, -0X1);
    // 0x80042BB0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80042BB4: sh          $t5, -0x650C($at)
    MEM_H(-0X650C, ctx->r1) = ctx->r13;
    // 0x80042BB8: b           L_80042C10
    // 0x80042BBC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_80042C10;
    // 0x80042BBC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_80042BC0:
    // 0x80042BC0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80042BC4: addiu       $a3, $zero, 0x19
    ctx->r7 = ADD32(0, 0X19);
    // 0x80042BC8: lh          $a2, 0x38($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X38);
L_80042BCC:
    // 0x80042BCC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80042BD0: lh          $t8, 0x42($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X42);
    // 0x80042BD4: lh          $t6, 0xA($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XA);
    // 0x80042BD8: bnel        $t6, $zero, L_80042C08
    if (ctx->r14 != 0) {
        // 0x80042BDC: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80042C08;
    }
    goto skip_4;
    // 0x80042BDC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_4:
    // 0x80042BE0: lh          $a1, 0x8($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X8);
    // 0x80042BE4: sll         $a2, $v1, 16
    ctx->r6 = S32(ctx->r3 << 16);
    // 0x80042BE8: sra         $t7, $a2, 16
    ctx->r15 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80042BEC: beq         $t8, $a1, L_80042BFC
    if (ctx->r24 == ctx->r5) {
        // 0x80042BF0: or          $a2, $t7, $zero
        ctx->r6 = ctx->r15 | 0;
            goto L_80042BFC;
    }
    // 0x80042BF0: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x80042BF4: bnel        $t0, $a1, L_80042C08
    if (ctx->r8 != ctx->r5) {
        // 0x80042BF8: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80042C08;
    }
    goto skip_5;
    // 0x80042BF8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_5:
L_80042BFC:
    // 0x80042BFC: b           L_80042C10
    // 0x80042C00: nop

        goto L_80042C10;
    // 0x80042C00: nop

    // 0x80042C04: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80042C08:
    // 0x80042C08: bne         $v1, $a3, L_80042BCC
    if (ctx->r3 != ctx->r7) {
        // 0x80042C0C: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80042BCC;
    }
    // 0x80042C0C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_80042C10:
    // 0x80042C10: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80042C14: addiu       $t1, $t1, -0x6570
    ctx->r9 = ADD32(ctx->r9, -0X6570);
    // 0x80042C18: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x80042C1C: addu        $s0, $t9, $t1
    ctx->r16 = ADD32(ctx->r25, ctx->r9);
    // 0x80042C20: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80042C24: lh          $t2, 0x42($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X42);
    // 0x80042C28: lh          $v0, 0x8($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X8);
    // 0x80042C2C: beql        $t2, $v0, L_80042C8C
    if (ctx->r10 == ctx->r2) {
        // 0x80042C30: addiu       $t9, $zero, 0x28
        ctx->r25 = ADD32(0, 0X28);
            goto L_80042C8C;
    }
    goto skip_6;
    // 0x80042C30: addiu       $t9, $zero, 0x28
    ctx->r25 = ADD32(0, 0X28);
    skip_6:
    // 0x80042C34: beq         $t0, $v0, L_80042C44
    if (ctx->r8 == ctx->r2) {
        // 0x80042C38: nop
    
            goto L_80042C44;
    }
    // 0x80042C38: nop

    // 0x80042C3C: jal         0x8004A0C4
    // 0x80042C40: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    func_8004A0C4(rdram, ctx);
        goto after_3;
    // 0x80042C40: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    after_3:
L_80042C44:
    // 0x80042C44: jal         0x80049D80
    // 0x80042C48: lh          $a0, 0x42($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X42);
    func_80049D80(rdram, ctx);
        goto after_4;
    // 0x80042C48: lh          $a0, 0x42($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X42);
    after_4:
    // 0x80042C4C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80042C50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80042C54: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
    // 0x80042C58: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80042C5C: jal         0x80049DFC
    // 0x80042C60: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    func_80049DFC(rdram, ctx);
        goto after_5;
    // 0x80042C60: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    after_5:
    // 0x80042C64: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80042C68: sw          $v0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r2;
    // 0x80042C6C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80042C70: jal         0x8004A148
    // 0x80042C74: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    func_8004A148(rdram, ctx);
        goto after_6;
    // 0x80042C74: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    after_6:
    // 0x80042C78: lh          $t7, 0x42($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X42);
    // 0x80042C7C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80042C80: sh          $t7, 0x8($t8)
    MEM_H(0X8, ctx->r24) = ctx->r15;
    // 0x80042C84: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80042C88: addiu       $t9, $zero, 0x28
    ctx->r25 = ADD32(0, 0X28);
L_80042C8C:
    // 0x80042C8C: sh          $t9, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r25;
    // 0x80042C90: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80042C94: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80042C98: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80042C9C: sh          $t1, 0xC($t2)
    MEM_H(0XC, ctx->r10) = ctx->r9;
    // 0x80042CA0: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80042CA4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80042CA8: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x80042CAC: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x80042CB0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80042CB4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80042CB8: lw          $v0, 0x8($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X8);
    // 0x80042CBC: lw          $t5, 0xD8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XD8);
    // 0x80042CC0: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x80042CC4: sw          $t6, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r14;
    // 0x80042CC8: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80042CCC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80042CD0: lw          $v0, 0x8($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X8);
    // 0x80042CD4: lw          $t9, 0xD8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XD8);
    // 0x80042CD8: ori         $t1, $t9, 0x8000
    ctx->r9 = ctx->r25 | 0X8000;
    // 0x80042CDC: sw          $t1, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r9;
    // 0x80042CE0: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80042CE4: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80042CE8: swc1        $f10, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->f10.u32l;
    // 0x80042CEC: lw          $t3, 0xCC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XCC);
    // 0x80042CF0: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    // 0x80042CF4: jal         0x80049840
    // 0x80042CF8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80049840(rdram, ctx);
        goto after_7;
    // 0x80042CF8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x80042CFC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80042D00: lw          $t4, 0xCC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XCC);
    // 0x80042D04: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80042D08: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80042D0C: lw          $a1, 0x4($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X4);
    // 0x80042D10: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80042D14: jal         0x80049840
    // 0x80042D18: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80049840(rdram, ctx);
        goto after_8;
    // 0x80042D18: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x80042D1C: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x80042D20: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80042D24: jal         0x80000BD8
    // 0x80042D28: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    func_80000BD8(rdram, ctx);
        goto after_9;
    // 0x80042D28: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    after_9:
    // 0x80042D2C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80042D30: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80042D34: lwc1        $f0, 0x10($t5)
    ctx->f0.u32l = MEM_W(ctx->r13, 0X10);
    // 0x80042D38: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80042D3C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80042D40: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80042D44: jal         0x80001AB4
    // 0x80042D48: nop

    func_80001AB4(rdram, ctx);
        goto after_10;
    // 0x80042D48: nop

    after_10:
    // 0x80042D4C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80042D50: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    // 0x80042D54: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x80042D58: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80042D5C: lw          $a0, 0x8($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X8);
    // 0x80042D60: jal         0x80000BD8
    // 0x80042D64: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80000BD8(rdram, ctx);
        goto after_11;
    // 0x80042D64: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_11:
    // 0x80042D68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80042D6C: lw          $v1, 0xC8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XC8);
    // 0x80042D70: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
L_80042D74:
    // 0x80042D74: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80042D78: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80042D7C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80042D80: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80042D84: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x80042D88: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x80042D8C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80042D90: bne         $v0, $a0, L_80042D74
    if (ctx->r2 != ctx->r4) {
        // 0x80042D94: swc1        $f16, 0x40($t2)
        MEM_W(0X40, ctx->r10) = ctx->f16.u32l;
            goto L_80042D74;
    }
    // 0x80042D94: swc1        $f16, 0x40($t2)
    MEM_W(0X40, ctx->r10) = ctx->f16.u32l;
    // 0x80042D98: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80042D9C: lh          $t3, -0x650C($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X650C);
    // 0x80042DA0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80042DA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80042DA8: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80042DAC: sh          $t4, -0x650C($at)
    MEM_H(-0X650C, ctx->r1) = ctx->r12;
L_80042DB0:
    // 0x80042DB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80042DB4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80042DB8: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    // 0x80042DBC: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80042DC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80042DC4: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80042DC8: addiu       $a3, $a3, -0x650C
    ctx->r7 = ADD32(ctx->r7, -0X650C);
    // 0x80042DCC: lh          $v0, 0x0($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X0);
    // 0x80042DD0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80042DD4: addiu       $a1, $a1, -0x6570
    ctx->r5 = ADD32(ctx->r5, -0X6570);
    // 0x80042DD8: blez        $v0, L_80042E70
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80042DDC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80042E70;
    }
    // 0x80042DDC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80042DE0: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80042DE4: addiu       $t1, $t1, -0x650C
    ctx->r9 = ADD32(ctx->r9, -0X650C);
    // 0x80042DE8: addiu       $t0, $zero, -0x2
    ctx->r8 = ADD32(0, -0X2);
    // 0x80042DEC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
L_80042DF0:
    // 0x80042DF0: lh          $v1, 0xA($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XA);
    // 0x80042DF4: beq         $v1, $zero, L_80042E64
    if (ctx->r3 == 0) {
        // 0x80042DF8: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_80042E64;
    }
    // 0x80042DF8: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80042DFC: sh          $t6, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r14;
    // 0x80042E00: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80042E04: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80042E08: lh          $a2, 0xC($v0)
    ctx->r6 = MEM_H(ctx->r2, 0XC);
    // 0x80042E0C: beq         $a2, $zero, L_80042E1C
    if (ctx->r6 == 0) {
        // 0x80042E10: addiu       $t7, $a2, -0x1
        ctx->r15 = ADD32(ctx->r6, -0X1);
            goto L_80042E1C;
    }
    // 0x80042E10: addiu       $t7, $a2, -0x1
    ctx->r15 = ADD32(ctx->r6, -0X1);
    // 0x80042E14: b           L_80042E30
    // 0x80042E18: sh          $t7, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r15;
        goto L_80042E30;
    // 0x80042E18: sh          $t7, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r15;
L_80042E1C:
    // 0x80042E1C: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x80042E20: lw          $v1, 0x8($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X8);
    // 0x80042E24: lw          $t9, 0xD8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XD8);
    // 0x80042E28: ori         $t2, $t9, 0x1
    ctx->r10 = ctx->r25 | 0X1;
    // 0x80042E2C: sw          $t2, 0xD8($v1)
    MEM_W(0XD8, ctx->r3) = ctx->r10;
L_80042E30:
    // 0x80042E30: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80042E34: lh          $t3, 0xA($v0)
    ctx->r11 = MEM_H(ctx->r2, 0XA);
    // 0x80042E38: bne         $t3, $zero, L_80042E60
    if (ctx->r11 != 0) {
        // 0x80042E3C: nop
    
            goto L_80042E60;
    }
    // 0x80042E3C: nop

    // 0x80042E40: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x80042E44: lw          $v1, 0x8($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X8);
    // 0x80042E48: lw          $t5, 0xD8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XD8);
    // 0x80042E4C: and         $t6, $t5, $t0
    ctx->r14 = ctx->r13 & ctx->r8;
    // 0x80042E50: sw          $t6, 0xD8($v1)
    MEM_W(0XD8, ctx->r3) = ctx->r14;
    // 0x80042E54: lh          $t7, 0x0($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X0);
    // 0x80042E58: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80042E5C: sh          $t8, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r24;
L_80042E60:
    // 0x80042E60: beq         $a0, $zero, L_80042E70
    if (ctx->r4 == 0) {
        // 0x80042E64: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80042E70;
    }
L_80042E64:
    // 0x80042E64: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80042E68: bnel        $a1, $t1, L_80042DF0
    if (ctx->r5 != ctx->r9) {
        // 0x80042E6C: lw          $v0, 0x0($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X0);
            goto L_80042DF0;
    }
    goto skip_0;
    // 0x80042E6C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    skip_0:
L_80042E70:
    // 0x80042E70: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80042E78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80042E78: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80042E7C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80042E80: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80042E84: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80042E88: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80042E8C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80042E90: lui         $s3, 0x801A
    ctx->r19 = S32(0X801A << 16);
    // 0x80042E94: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x80042E98: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80042E9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80042EA0: addiu       $s4, $s4, -0x650C
    ctx->r20 = ADD32(ctx->r20, -0X650C);
    // 0x80042EA4: addiu       $s3, $s3, 0x2800
    ctx->r19 = ADD32(ctx->r19, 0X2800);
    // 0x80042EA8: addiu       $s1, $s1, -0x6570
    ctx->r17 = ADD32(ctx->r17, -0X6570);
    // 0x80042EAC: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x80042EB0: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
L_80042EB4:
    // 0x80042EB4: lh          $t6, 0x8($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X8);
    // 0x80042EB8: beql        $s2, $t6, L_80042ED0
    if (ctx->r18 == ctx->r14) {
        // 0x80042EBC: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80042ED0;
    }
    goto skip_0;
    // 0x80042EBC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_0:
    // 0x80042EC0: jal         0x8004A0C4
    // 0x80042EC4: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    func_8004A0C4(rdram, ctx);
        goto after_0;
    // 0x80042EC4: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_0:
    // 0x80042EC8: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80042ECC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80042ED0:
    // 0x80042ED0: jal         0x800042A8
    // 0x80042ED4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800042A8(rdram, ctx);
        goto after_1;
    // 0x80042ED4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80042ED8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80042EDC: bnel        $s1, $s4, L_80042EB4
    if (ctx->r17 != ctx->r20) {
        // 0x80042EE0: lw          $s0, 0x0($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X0);
            goto L_80042EB4;
    }
    goto skip_1;
    // 0x80042EE0: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    skip_1:
    // 0x80042EE4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80042EE8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80042EEC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80042EF0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80042EF4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80042EF8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80042EFC: jr          $ra
    // 0x80042F00: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    TRACE_RETURN()
    return;
    // 0x80042F00: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80042F04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80042F04: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80042F08: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80042F0C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80042F10: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80042F14: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80042F18: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80042F1C: lui         $s1, 0x801A
    ctx->r17 = S32(0X801A << 16);
    // 0x80042F20: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80042F24: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80042F28: addiu       $s3, $s3, -0x64A4
    ctx->r19 = ADD32(ctx->r19, -0X64A4);
    // 0x80042F2C: addiu       $s1, $s1, 0x2800
    ctx->r17 = ADD32(ctx->r17, 0X2800);
    // 0x80042F30: addiu       $s0, $s0, -0x6508
    ctx->r16 = ADD32(ctx->r16, -0X6508);
    // 0x80042F34: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
L_80042F38:
    // 0x80042F38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80042F3C: jal         0x80004364
    // 0x80042F40: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x80042F40: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    after_0:
    // 0x80042F44: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80042F48: sh          $zero, 0x1A($v0)
    MEM_H(0X1A, ctx->r2) = 0;
    // 0x80042F4C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80042F50: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80042F54: bne         $s0, $s3, L_80042F38
    if (ctx->r16 != ctx->r19) {
        // 0x80042F58: sh          $s2, 0x18($t6)
        MEM_H(0X18, ctx->r14) = ctx->r18;
            goto L_80042F38;
    }
    // 0x80042F58: sh          $s2, 0x18($t6)
    MEM_H(0X18, ctx->r14) = ctx->r18;
    // 0x80042F5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80042F60: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80042F64: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80042F68: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80042F6C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80042F70: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80042F74: sh          $zero, -0x64A4($at)
    MEM_H(-0X64A4, ctx->r1) = 0;
    // 0x80042F78: jr          $ra
    // 0x80042F7C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    TRACE_RETURN()
    return;
    // 0x80042F7C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80042F80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80042F80: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80042F84: lh          $t6, -0x6B94($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X6B94);
    // 0x80042F88: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80042F8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80042F90: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80042F94: bne         $t6, $zero, L_80042FA4
    if (ctx->r14 != 0) {
        // 0x80042F98: sw          $a2, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r6;
            goto L_80042FA4;
    }
    // 0x80042F98: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80042F9C: b           L_800433BC
    // 0x80042FA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800433BC;
    // 0x80042FA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80042FA4:
    // 0x80042FA4: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80042FA8: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x80042FAC: lui         $t8, 0x8007
    ctx->r24 = S32(0X8007 << 16);
    // 0x80042FB0: addiu       $t8, $t8, -0x5810
    ctx->r24 = ADD32(ctx->r24, -0X5810);
    // 0x80042FB4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80042FB8: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80042FBC: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80042FC0: jal         0x80049CFC
    // 0x80042FC4: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_80049CFC(rdram, ctx);
        goto after_0;
    // 0x80042FC4: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_0:
    // 0x80042FC8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80042FCC: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80042FD0: lh          $t3, -0x64A4($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X64A4);
    // 0x80042FD4: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80042FD8: lh          $t9, 0x8($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X8);
    // 0x80042FDC: lh          $t4, 0xA($v1)
    ctx->r12 = MEM_H(ctx->r3, 0XA);
    // 0x80042FE0: slti        $at, $t3, 0x19
    ctx->r1 = SIGNED(ctx->r11) < 0X19 ? 1 : 0;
    // 0x80042FE4: sh          $v0, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r2;
    // 0x80042FE8: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x80042FEC: sh          $t9, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r25;
    // 0x80042FF0: bne         $at, $zero, L_800431B4
    if (ctx->r1 != 0) {
        // 0x80042FF4: sh          $t4, 0x2A($sp)
        MEM_H(0X2A, ctx->r29) = ctx->r12;
            goto L_800431B4;
    }
    // 0x80042FF4: sh          $t4, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r12;
    // 0x80042FF8: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80042FFC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80043000: addiu       $a0, $a0, -0x64A4
    ctx->r4 = ADD32(ctx->r4, -0X64A4);
    // 0x80043004: addiu       $a2, $a2, -0x6508
    ctx->r6 = ADD32(ctx->r6, -0X6508);
    // 0x80043008: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
L_8004300C:
    // 0x8004300C: lw          $t5, 0x20($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X20);
    // 0x80043010: bnel        $t5, $zero, L_80043038
    if (ctx->r13 != 0) {
        // 0x80043014: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_80043038;
    }
    goto skip_0;
    // 0x80043014: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    skip_0:
    // 0x80043018: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x8004301C: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x80043020: lw          $t8, 0xE0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XE0);
    // 0x80043024: lbu         $t9, 0x10($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X10);
    // 0x80043028: andi        $t4, $t9, 0x8
    ctx->r12 = ctx->r25 & 0X8;
    // 0x8004302C: beq         $t4, $zero, L_80043044
    if (ctx->r12 == 0) {
        // 0x80043030: nop
    
            goto L_80043044;
    }
    // 0x80043030: nop

    // 0x80043034: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_80043038:
    // 0x80043038: sltu        $at, $a2, $a0
    ctx->r1 = ctx->r6 < ctx->r4 ? 1 : 0;
    // 0x8004303C: bnel        $at, $zero, L_8004300C
    if (ctx->r1 != 0) {
        // 0x80043040: lw          $v1, 0x0($a2)
        ctx->r3 = MEM_W(ctx->r6, 0X0);
            goto L_8004300C;
    }
    goto skip_1;
    // 0x80043040: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    skip_1:
L_80043044:
    // 0x80043044: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80043048: addiu       $t5, $t5, -0x64A4
    ctx->r13 = ADD32(ctx->r13, -0X64A4);
    // 0x8004304C: bne         $a2, $t5, L_8004305C
    if (ctx->r6 != ctx->r13) {
        // 0x80043050: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_8004305C;
    }
    // 0x80043050: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80043054: b           L_800433BC
    // 0x80043058: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800433BC;
    // 0x80043058: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004305C:
    // 0x8004305C: lw          $t6, -0x6508($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6508);
    // 0x80043060: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80043064: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80043068: lw          $t7, 0x20($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20);
    // 0x8004306C: addiu       $a2, $a2, -0x6504
    ctx->r6 = ADD32(ctx->r6, -0X6504);
    // 0x80043070: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80043074: bne         $t7, $zero, L_800430A4
    if (ctx->r15 != 0) {
        // 0x80043078: addiu       $t2, $zero, -0x1
        ctx->r10 = ADD32(0, -0X1);
            goto L_800430A4;
    }
    // 0x80043078: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8004307C: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x80043080: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x80043084: lw          $t4, 0xE0($t9)
    ctx->r12 = MEM_W(ctx->r25, 0XE0);
    // 0x80043088: lbu         $t5, 0x10($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X10);
    // 0x8004308C: andi        $t7, $t5, 0x8
    ctx->r15 = ctx->r13 & 0X8;
    // 0x80043090: bnel        $t7, $zero, L_800430A8
    if (ctx->r15 != 0) {
        // 0x80043094: lh          $a3, 0x3A($sp)
        ctx->r7 = MEM_H(ctx->r29, 0X3A);
            goto L_800430A8;
    }
    goto skip_2;
    // 0x80043094: lh          $a3, 0x3A($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X3A);
    skip_2:
    // 0x80043098: lh          $a3, 0x1A($t6)
    ctx->r7 = MEM_H(ctx->r14, 0X1A);
    // 0x8004309C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800430A0: sh          $a3, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r7;
L_800430A4:
    // 0x800430A4: lh          $a3, 0x3A($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X3A);
L_800430A8:
    // 0x800430A8: addiu       $t1, $zero, 0x19
    ctx->r9 = ADD32(0, 0X19);
L_800430AC:
    // 0x800430AC: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x800430B0: lw          $t8, 0x20($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X20);
    // 0x800430B4: bnel        $t8, $zero, L_80043120
    if (ctx->r24 != 0) {
        // 0x800430B8: lw          $v1, 0x4($a2)
        ctx->r3 = MEM_W(ctx->r6, 0X4);
            goto L_80043120;
    }
    goto skip_3;
    // 0x800430B8: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    skip_3:
    // 0x800430BC: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x800430C0: lw          $t4, 0x8($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X8);
    // 0x800430C4: lw          $t5, 0xE0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XE0);
    // 0x800430C8: lbu         $t7, 0x10($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X10);
    // 0x800430CC: andi        $t6, $t7, 0x8
    ctx->r14 = ctx->r15 & 0X8;
    // 0x800430D0: bnel        $t6, $zero, L_80043120
    if (ctx->r14 != 0) {
        // 0x800430D4: lw          $v1, 0x4($a2)
        ctx->r3 = MEM_W(ctx->r6, 0X4);
            goto L_80043120;
    }
    goto skip_4;
    // 0x800430D4: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    skip_4:
    // 0x800430D8: bnel        $t0, $t2, L_800430F8
    if (ctx->r8 != ctx->r10) {
        // 0x800430DC: lh          $a1, 0x1A($v1)
        ctx->r5 = MEM_H(ctx->r3, 0X1A);
            goto L_800430F8;
    }
    goto skip_5;
    // 0x800430DC: lh          $a1, 0x1A($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X1A);
    skip_5:
    // 0x800430E0: sll         $t0, $a0, 16
    ctx->r8 = S32(ctx->r4 << 16);
    // 0x800430E4: sra         $t8, $t0, 16
    ctx->r24 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800430E8: lh          $a3, 0x1A($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X1A);
    // 0x800430EC: b           L_8004311C
    // 0x800430F0: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
        goto L_8004311C;
    // 0x800430F0: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x800430F4: lh          $a1, 0x1A($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X1A);
L_800430F8:
    // 0x800430F8: slt         $at, $a3, $a1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800430FC: beql        $at, $zero, L_80043120
    if (ctx->r1 == 0) {
        // 0x80043100: lw          $v1, 0x4($a2)
        ctx->r3 = MEM_W(ctx->r6, 0X4);
            goto L_80043120;
    }
    goto skip_6;
    // 0x80043100: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    skip_6:
    // 0x80043104: sll         $a3, $a1, 16
    ctx->r7 = S32(ctx->r5 << 16);
    // 0x80043108: sll         $t0, $a0, 16
    ctx->r8 = S32(ctx->r4 << 16);
    // 0x8004310C: sra         $t9, $a3, 16
    ctx->r25 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80043110: sra         $t4, $t0, 16
    ctx->r12 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80043114: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x80043118: or          $t0, $t4, $zero
    ctx->r8 = ctx->r12 | 0;
L_8004311C:
    // 0x8004311C: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
L_80043120:
    // 0x80043120: lw          $t5, 0x20($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X20);
    // 0x80043124: bnel        $t5, $zero, L_80043190
    if (ctx->r13 != 0) {
        // 0x80043128: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_80043190;
    }
    goto skip_7;
    // 0x80043128: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    skip_7:
    // 0x8004312C: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x80043130: lw          $t6, 0x8($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X8);
    // 0x80043134: lw          $t8, 0xE0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XE0);
    // 0x80043138: lbu         $t9, 0x10($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X10);
    // 0x8004313C: andi        $t4, $t9, 0x8
    ctx->r12 = ctx->r25 & 0X8;
    // 0x80043140: bnel        $t4, $zero, L_80043190
    if (ctx->r12 != 0) {
        // 0x80043144: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_80043190;
    }
    goto skip_8;
    // 0x80043144: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    skip_8:
    // 0x80043148: bnel        $t0, $t2, L_80043168
    if (ctx->r8 != ctx->r10) {
        // 0x8004314C: lh          $a1, 0x1A($v1)
        ctx->r5 = MEM_H(ctx->r3, 0X1A);
            goto L_80043168;
    }
    goto skip_9;
    // 0x8004314C: lh          $a1, 0x1A($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X1A);
    skip_9:
    // 0x80043150: addiu       $t0, $a0, 0x1
    ctx->r8 = ADD32(ctx->r4, 0X1);
    // 0x80043154: sll         $t5, $t0, 16
    ctx->r13 = S32(ctx->r8 << 16);
    // 0x80043158: sra         $t0, $t5, 16
    ctx->r8 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8004315C: b           L_8004318C
    // 0x80043160: lh          $a3, 0x1A($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X1A);
        goto L_8004318C;
    // 0x80043160: lh          $a3, 0x1A($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X1A);
    // 0x80043164: lh          $a1, 0x1A($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X1A);
L_80043168:
    // 0x80043168: slt         $at, $a3, $a1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8004316C: beql        $at, $zero, L_80043190
    if (ctx->r1 == 0) {
        // 0x80043170: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_80043190;
    }
    goto skip_10;
    // 0x80043170: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    skip_10:
    // 0x80043174: sll         $a3, $a1, 16
    ctx->r7 = S32(ctx->r5 << 16);
    // 0x80043178: addiu       $t0, $a0, 0x1
    ctx->r8 = ADD32(ctx->r4, 0X1);
    // 0x8004317C: sll         $t8, $t0, 16
    ctx->r24 = S32(ctx->r8 << 16);
    // 0x80043180: sra         $t6, $a3, 16
    ctx->r14 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80043184: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x80043188: sra         $t0, $t8, 16
    ctx->r8 = S32(SIGNED(ctx->r24) >> 16);
L_8004318C:
    // 0x8004318C: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
L_80043190:
    // 0x80043190: bne         $a0, $t1, L_800430AC
    if (ctx->r4 != ctx->r9) {
        // 0x80043194: addiu       $a2, $a2, 0x8
        ctx->r6 = ADD32(ctx->r6, 0X8);
            goto L_800430AC;
    }
    // 0x80043194: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80043198: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x8004319C: sra         $t5, $a1, 16
    ctx->r13 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800431A0: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x800431A4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800431A8: sh          $t4, -0x64A4($at)
    MEM_H(-0X64A4, ctx->r1) = ctx->r12;
    // 0x800431AC: b           L_80043218
    // 0x800431B0: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
        goto L_80043218;
    // 0x800431B0: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
L_800431B4:
    // 0x800431B4: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x800431B8: sra         $t7, $a1, 16
    ctx->r15 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800431BC: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800431C0: addiu       $a2, $a2, -0x6508
    ctx->r6 = ADD32(ctx->r6, -0X6508);
    // 0x800431C4: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x800431C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800431CC: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800431D0: addiu       $t1, $zero, 0x19
    ctx->r9 = ADD32(0, 0X19);
    // 0x800431D4: lh          $t0, 0x38($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X38);
L_800431D8:
    // 0x800431D8: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x800431DC: lh          $t6, 0x1A($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X1A);
    // 0x800431E0: bnel        $t6, $zero, L_80043210
    if (ctx->r14 != 0) {
        // 0x800431E4: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80043210;
    }
    goto skip_11;
    // 0x800431E4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_11:
    // 0x800431E8: lh          $v0, 0x18($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X18);
    // 0x800431EC: sll         $t0, $a0, 16
    ctx->r8 = S32(ctx->r4 << 16);
    // 0x800431F0: sra         $t8, $t0, 16
    ctx->r24 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800431F4: beq         $a1, $v0, L_80043204
    if (ctx->r5 == ctx->r2) {
        // 0x800431F8: or          $t0, $t8, $zero
        ctx->r8 = ctx->r24 | 0;
            goto L_80043204;
    }
    // 0x800431F8: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x800431FC: bnel        $t2, $v0, L_80043210
    if (ctx->r10 != ctx->r2) {
        // 0x80043200: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80043210;
    }
    goto skip_12;
    // 0x80043200: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_12:
L_80043204:
    // 0x80043204: b           L_80043218
    // 0x80043208: nop

        goto L_80043218;
    // 0x80043208: nop

    // 0x8004320C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80043210:
    // 0x80043210: bne         $a0, $t1, L_800431D8
    if (ctx->r4 != ctx->r9) {
        // 0x80043214: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_800431D8;
    }
    // 0x80043214: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_80043218:
    // 0x80043218: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x8004321C: addiu       $t4, $t4, -0x6508
    ctx->r12 = ADD32(ctx->r12, -0X6508);
    // 0x80043220: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x80043224: addu        $a2, $t9, $t4
    ctx->r6 = ADD32(ctx->r25, ctx->r12);
    // 0x80043228: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x8004322C: lh          $v0, 0x18($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X18);
    // 0x80043230: beql        $a1, $v0, L_800432AC
    if (ctx->r5 == ctx->r2) {
        // 0x80043234: lh          $t5, 0x2A($sp)
        ctx->r13 = MEM_H(ctx->r29, 0X2A);
            goto L_800432AC;
    }
    goto skip_13;
    // 0x80043234: lh          $t5, 0x2A($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X2A);
    skip_13:
    // 0x80043238: beql        $t2, $v0, L_80043254
    if (ctx->r10 == ctx->r2) {
        // 0x8004323C: lh          $a0, 0x32($sp)
        ctx->r4 = MEM_H(ctx->r29, 0X32);
            goto L_80043254;
    }
    goto skip_14;
    // 0x8004323C: lh          $a0, 0x32($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X32);
    skip_14:
    // 0x80043240: lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X4);
    // 0x80043244: jal         0x8004A0C4
    // 0x80043248: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_8004A0C4(rdram, ctx);
        goto after_1;
    // 0x80043248: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_1:
    // 0x8004324C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80043250: lh          $a0, 0x32($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X32);
L_80043254:
    // 0x80043254: jal         0x80049D80
    // 0x80043258: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80049D80(rdram, ctx);
        goto after_2;
    // 0x80043258: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_2:
    // 0x8004325C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80043260: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80043264: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80043268: sw          $v0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r2;
    // 0x8004326C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80043270: jal         0x80049DFC
    // 0x80043274: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    func_80049DFC(rdram, ctx);
        goto after_3;
    // 0x80043274: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_3:
    // 0x80043278: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8004327C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80043280: sw          $v0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r2;
    // 0x80043284: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80043288: jal         0x8004A148
    // 0x8004328C: lw          $a0, 0x4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X4);
    func_8004A148(rdram, ctx);
        goto after_4;
    // 0x8004328C: lw          $a0, 0x4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X4);
    after_4:
    // 0x80043290: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80043294: lh          $t9, 0x32($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X32);
    // 0x80043298: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8004329C: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x800432A0: sh          $t9, 0x18($t4)
    MEM_H(0X18, ctx->r12) = ctx->r25;
    // 0x800432A4: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x800432A8: lh          $t5, 0x2A($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X2A);
L_800432AC:
    // 0x800432AC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800432B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800432B4: sh          $t5, 0x1C($a3)
    MEM_H(0X1C, ctx->r7) = ctx->r13;
    // 0x800432B8: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800432BC: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800432C0: swc1        $f6, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->f6.u32l;
    // 0x800432C4: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800432C8: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800432CC: sw          $t6, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->r14;
    // 0x800432D0: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x800432D4: sh          $t9, 0x1A($t4)
    MEM_H(0X1A, ctx->r12) = ctx->r25;
    // 0x800432D8: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x800432DC: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x800432E0: lw          $a0, 0x8($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X8);
    // 0x800432E4: lw          $t6, 0xD8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XD8);
    // 0x800432E8: ori         $t8, $t6, 0x8000
    ctx->r24 = ctx->r14 | 0X8000;
    // 0x800432EC: sw          $t8, 0xD8($a0)
    MEM_W(0XD8, ctx->r4) = ctx->r24;
    // 0x800432F0: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x800432F4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
L_800432F8:
    // 0x800432F8: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800432FC: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80043300: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80043304: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x80043308: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8004330C: bne         $v0, $a0, L_800432F8
    if (ctx->r2 != ctx->r4) {
        // 0x80043310: swc1        $f8, 0x8($t4)
        MEM_W(0X8, ctx->r12) = ctx->f8.u32l;
            goto L_800432F8;
    }
    // 0x80043310: swc1        $f8, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f8.u32l;
    // 0x80043314: lh          $t5, 0x2A($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X2A);
    // 0x80043318: andi        $t7, $t5, 0x1
    ctx->r15 = ctx->r13 & 0X1;
    // 0x8004331C: bnel        $t7, $zero, L_80043340
    if (ctx->r15 != 0) {
        // 0x80043320: lw          $t6, 0x0($a2)
        ctx->r14 = MEM_W(ctx->r6, 0X0);
            goto L_80043340;
    }
    goto skip_15;
    // 0x80043320: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    skip_15:
    // 0x80043324: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80043328: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8004332C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80043330: lwc1        $f10, 0xC($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80043334: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80043338: swc1        $f18, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f18.u32l;
    // 0x8004333C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
L_80043340:
    // 0x80043340: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80043344: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x80043348: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x8004334C: lw          $v0, 0xE0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0XE0);
    // 0x80043350: lbu         $t4, 0x10($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X10);
    // 0x80043354: ori         $t5, $t4, 0x4
    ctx->r13 = ctx->r12 | 0X4;
    // 0x80043358: sb          $t5, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r13;
    // 0x8004335C: lh          $t7, 0x30($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X30);
    // 0x80043360: beq         $t7, $t2, L_800433A4
    if (ctx->r15 == ctx->r10) {
        // 0x80043364: nop
    
            goto L_800433A4;
    }
    // 0x80043364: nop

    // 0x80043368: bnel        $t7, $at, L_80043398
    if (ctx->r15 != ctx->r1) {
        // 0x8004336C: lh          $a0, 0x30($sp)
        ctx->r4 = MEM_H(ctx->r29, 0X30);
            goto L_80043398;
    }
    goto skip_16;
    // 0x8004336C: lh          $a0, 0x30($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X30);
    skip_16:
    // 0x80043370: jal         0x8000E35C
    // 0x80043374: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_8000E35C(rdram, ctx);
        goto after_5;
    // 0x80043374: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_5:
    // 0x80043378: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x8004337C: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x80043380: lui         $t9, 0x8007
    ctx->r25 = S32(0X8007 << 16);
    // 0x80043384: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80043388: lh          $t9, -0x56B4($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X56B4);
    // 0x8004338C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80043390: sh          $t9, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r25;
    // 0x80043394: lh          $a0, 0x30($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X30);
L_80043398:
    // 0x80043398: jal         0x80044480
    // 0x8004339C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80044480(rdram, ctx);
        goto after_6;
    // 0x8004339C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_6:
    // 0x800433A0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
L_800433A4:
    // 0x800433A4: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800433A8: lh          $t4, -0x64A4($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X64A4);
    // 0x800433AC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800433B0: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800433B4: sh          $t5, -0x64A4($at)
    MEM_H(-0X64A4, ctx->r1) = ctx->r13;
    // 0x800433B8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
L_800433BC:
    // 0x800433BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800433C0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800433C4: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800433CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800433CC: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x800433D0: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x800433D4: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800433D8: addiu       $s4, $s4, -0x64A4
    ctx->r20 = ADD32(ctx->r20, -0X64A4);
    // 0x800433DC: lh          $t6, 0x0($s4)
    ctx->r14 = MEM_H(ctx->r20, 0X0);
    // 0x800433E0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800433E4: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x800433E8: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x800433EC: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x800433F0: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800433F4: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800433F8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800433FC: blez        $t6, L_800435E0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80043400: sw          $s0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r16;
            goto L_800435E0;
    }
    // 0x80043400: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80043404: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80043408: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8004340C: addiu       $a0, $a0, -0x6C14
    ctx->r4 = ADD32(ctx->r4, -0X6C14);
    // 0x80043410: addiu       $v0, $v0, -0x6C20
    ctx->r2 = ADD32(ctx->r2, -0X6C20);
    // 0x80043414: addiu       $v1, $sp, 0xD0
    ctx->r3 = ADD32(ctx->r29, 0XD0);
L_80043418:
    // 0x80043418: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8004341C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80043420: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x80043424: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80043428: bne         $at, $zero, L_80043418
    if (ctx->r1 != 0) {
        // 0x8004342C: swc1        $f4, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
            goto L_80043418;
    }
    // 0x8004342C: swc1        $f4, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
    // 0x80043430: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80043434: addiu       $s5, $sp, 0x90
    ctx->r21 = ADD32(ctx->r29, 0X90);
    // 0x80043438: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8004343C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80043440: lw          $a1, 0xD0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XD0);
    // 0x80043444: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80043448: jal         0x80049840
    // 0x8004344C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80049840(rdram, ctx);
        goto after_0;
    // 0x8004344C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80043450: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80043454: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80043458: lwc1        $f6, 0xD4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x8004345C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80043460: addiu       $s0, $sp, 0x50
    ctx->r16 = ADD32(ctx->r29, 0X50);
    // 0x80043464: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80043468: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8004346C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80043470: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80043474: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80043478: jal         0x80049840
    // 0x8004347C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80049840(rdram, ctx);
        goto after_1;
    // 0x8004347C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80043480: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80043484: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80043488: jal         0x80000BD8
    // 0x8004348C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80000BD8(rdram, ctx);
        goto after_2;
    // 0x8004348C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_2:
    // 0x80043490: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80043494: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x80043498: addiu       $s7, $s7, -0x64A4
    ctx->r23 = ADD32(ctx->r23, -0X64A4);
    // 0x8004349C: addiu       $s1, $s1, -0x6508
    ctx->r17 = ADD32(ctx->r17, -0X6508);
    // 0x800434A0: lh          $s3, 0x0($s4)
    ctx->r19 = MEM_H(ctx->r20, 0X0);
    // 0x800434A4: addiu       $s6, $zero, -0x2
    ctx->r22 = ADD32(0, -0X2);
    // 0x800434A8: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
    // 0x800434AC: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
L_800434B0:
    // 0x800434B0: lh          $v0, 0x1A($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1A);
    // 0x800434B4: beq         $v0, $zero, L_800435D4
    if (ctx->r2 == 0) {
        // 0x800434B8: slti        $at, $v0, 0x7FFF
        ctx->r1 = SIGNED(ctx->r2) < 0X7FFF ? 1 : 0;
            goto L_800435D4;
    }
    // 0x800434B8: slti        $at, $v0, 0x7FFF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FFF ? 1 : 0;
    // 0x800434BC: beq         $at, $zero, L_800434CC
    if (ctx->r1 == 0) {
        // 0x800434C0: addiu       $t7, $v0, 0x1
        ctx->r15 = ADD32(ctx->r2, 0X1);
            goto L_800434CC;
    }
    // 0x800434C0: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x800434C4: sh          $t7, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r15;
    // 0x800434C8: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
L_800434CC:
    // 0x800434CC: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x800434D0: lw          $v0, 0x8($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X8);
    // 0x800434D4: lw          $t9, 0xE0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XE0);
    // 0x800434D8: lbu         $t0, 0x10($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X10);
    // 0x800434DC: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x800434E0: beql        $t1, $zero, L_80043504
    if (ctx->r9 == 0) {
        // 0x800434E4: lwc1        $f0, 0x14($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
            goto L_80043504;
    }
    goto skip_0;
    // 0x800434E4: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    skip_0:
    // 0x800434E8: lw          $t2, 0xD8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XD8);
    // 0x800434EC: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x800434F0: sw          $t3, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r11;
    // 0x800434F4: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800434F8: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x800434FC: lw          $v0, 0x8($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X8);
    // 0x80043500: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
L_80043504:
    // 0x80043504: addiu       $a0, $v0, 0x10
    ctx->r4 = ADD32(ctx->r2, 0X10);
    // 0x80043508: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8004350C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80043510: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80043514: jal         0x80001AB4
    // 0x80043518: nop

    func_80001AB4(rdram, ctx);
        goto after_3;
    // 0x80043518: nop

    after_3:
    // 0x8004351C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80043520: lh          $t5, 0x1C($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X1C);
    // 0x80043524: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x80043528: beql        $t6, $zero, L_8004354C
    if (ctx->r14 == 0) {
        // 0x8004352C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8004354C;
    }
    goto skip_1;
    // 0x8004352C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80043530: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x80043534: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80043538: lw          $a0, 0x8($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X8);
    // 0x8004353C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80043540: jal         0x80000BD8
    // 0x80043544: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_80000BD8(rdram, ctx);
        goto after_4;
    // 0x80043544: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_4:
    // 0x80043548: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004354C:
    // 0x8004354C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80043550: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x80043554: addu        $t8, $s0, $v0
    ctx->r24 = ADD32(ctx->r16, ctx->r2);
    // 0x80043558: lwc1        $f16, 0x8($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8004355C: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x80043560: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x80043564: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80043568: bne         $v0, $s2, L_8004354C
    if (ctx->r2 != ctx->r18) {
        // 0x8004356C: swc1        $f16, 0x40($t1)
        MEM_W(0X40, ctx->r9) = ctx->f16.u32l;
            goto L_8004354C;
    }
    // 0x8004356C: swc1        $f16, 0x40($t1)
    MEM_W(0X40, ctx->r9) = ctx->f16.u32l;
    // 0x80043570: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80043574: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x80043578: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x8004357C: lw          $v0, 0x8($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X8);
    // 0x80043580: lw          $t3, 0xE0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XE0);
    // 0x80043584: lbu         $t4, 0x10($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X10);
    // 0x80043588: andi        $t5, $t4, 0x4
    ctx->r13 = ctx->r12 & 0X4;
    // 0x8004358C: bne         $t5, $zero, L_800435D0
    if (ctx->r13 != 0) {
        // 0x80043590: nop
    
            goto L_800435D0;
    }
    // 0x80043590: nop

    // 0x80043594: lw          $v1, 0x20($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X20);
    // 0x80043598: beql        $v1, $zero, L_800435B4
    if (ctx->r3 == 0) {
        // 0x8004359C: lw          $t8, 0xD8($v0)
        ctx->r24 = MEM_W(ctx->r2, 0XD8);
            goto L_800435B4;
    }
    goto skip_2;
    // 0x8004359C: lw          $t8, 0xD8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XD8);
    skip_2:
    // 0x800435A0: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x800435A4: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800435A8: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800435AC: lw          $v0, 0x8($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X8);
    // 0x800435B0: lw          $t8, 0xD8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XD8);
L_800435B4:
    // 0x800435B4: and         $t9, $t8, $s6
    ctx->r25 = ctx->r24 & ctx->r22;
    // 0x800435B8: sw          $t9, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r25;
    // 0x800435BC: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x800435C0: sh          $zero, 0x1A($t0)
    MEM_H(0X1A, ctx->r8) = 0;
    // 0x800435C4: lh          $t1, 0x0($s4)
    ctx->r9 = MEM_H(ctx->r20, 0X0);
    // 0x800435C8: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x800435CC: sh          $t2, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r10;
L_800435D0:
    // 0x800435D0: beq         $s3, $zero, L_800435E0
    if (ctx->r19 == 0) {
        // 0x800435D4: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800435E0;
    }
L_800435D4:
    // 0x800435D4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800435D8: bnel        $s1, $s7, L_800434B0
    if (ctx->r17 != ctx->r23) {
        // 0x800435DC: lw          $s0, 0x0($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X0);
            goto L_800434B0;
    }
    goto skip_3;
    // 0x800435DC: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    skip_3:
L_800435E0:
    // 0x800435E0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800435E4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800435E8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800435EC: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800435F0: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800435F4: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x800435F8: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x800435FC: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x80043600: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x80043604: jr          $ra
    // 0x80043608: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    TRACE_RETURN()
    return;
    // 0x80043608: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
;}
RECOMP_FUNC void func_8004360C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004360C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80043610: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80043614: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80043618: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8004361C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80043620: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80043624: lui         $s3, 0x801A
    ctx->r19 = S32(0X801A << 16);
    // 0x80043628: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x8004362C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80043630: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80043634: addiu       $s4, $s4, -0x64A4
    ctx->r20 = ADD32(ctx->r20, -0X64A4);
    // 0x80043638: addiu       $s3, $s3, 0x2800
    ctx->r19 = ADD32(ctx->r19, 0X2800);
    // 0x8004363C: addiu       $s1, $s1, -0x6508
    ctx->r17 = ADD32(ctx->r17, -0X6508);
    // 0x80043640: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x80043644: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
L_80043648:
    // 0x80043648: lh          $t6, 0x18($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X18);
    // 0x8004364C: beql        $s2, $t6, L_80043664
    if (ctx->r18 == ctx->r14) {
        // 0x80043650: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80043664;
    }
    goto skip_0;
    // 0x80043650: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_0:
    // 0x80043654: jal         0x8004A0C4
    // 0x80043658: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    func_8004A0C4(rdram, ctx);
        goto after_0;
    // 0x80043658: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_0:
    // 0x8004365C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80043660: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80043664:
    // 0x80043664: jal         0x800042A8
    // 0x80043668: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800042A8(rdram, ctx);
        goto after_1;
    // 0x80043668: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x8004366C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80043670: bnel        $s1, $s4, L_80043648
    if (ctx->r17 != ctx->r20) {
        // 0x80043674: lw          $s0, 0x0($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X0);
            goto L_80043648;
    }
    goto skip_1;
    // 0x80043674: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    skip_1:
    // 0x80043678: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8004367C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80043680: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80043684: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80043688: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8004368C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80043690: jr          $ra
    // 0x80043694: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    TRACE_RETURN()
    return;
    // 0x80043694: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80043698(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80043698: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004369C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800436A0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800436A4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800436A8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800436AC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800436B0: lui         $s1, 0x801A
    ctx->r17 = S32(0X801A << 16);
    // 0x800436B4: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800436B8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800436BC: addiu       $s3, $s3, -0x6464
    ctx->r19 = ADD32(ctx->r19, -0X6464);
    // 0x800436C0: addiu       $s1, $s1, 0x2800
    ctx->r17 = ADD32(ctx->r17, 0X2800);
    // 0x800436C4: addiu       $s0, $s0, -0x64A0
    ctx->r16 = ADD32(ctx->r16, -0X64A0);
    // 0x800436C8: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
L_800436CC:
    // 0x800436CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800436D0: jal         0x80004364
    // 0x800436D4: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x800436D4: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    after_0:
    // 0x800436D8: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800436DC: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x800436E0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800436E4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800436E8: bne         $s0, $s3, L_800436CC
    if (ctx->r16 != ctx->r19) {
        // 0x800436EC: sh          $s2, 0xA($t6)
        MEM_H(0XA, ctx->r14) = ctx->r18;
            goto L_800436CC;
    }
    // 0x800436EC: sh          $s2, 0xA($t6)
    MEM_H(0XA, ctx->r14) = ctx->r18;
    // 0x800436F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800436F4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800436F8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800436FC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80043700: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80043704: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80043708: sh          $zero, -0x6464($at)
    MEM_H(-0X6464, ctx->r1) = 0;
    // 0x8004370C: jr          $ra
    // 0x80043710: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    TRACE_RETURN()
    return;
    // 0x80043710: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80043714(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80043714: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80043718: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8004371C: lh          $t8, -0x6B94($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X6B94);
    // 0x80043720: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x80043724: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80043728: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8004372C: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x80043730: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80043734: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80043738: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8004373C: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80043740: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80043744: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80043748: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8004374C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80043750: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80043754: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80043758: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8004375C: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80043760: beq         $t8, $zero, L_80043B0C
    if (ctx->r24 == 0) {
        // 0x80043764: sw          $a2, 0x68($sp)
        MEM_W(0X68, ctx->r29) = ctx->r6;
            goto L_80043B0C;
    }
    // 0x80043764: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x80043768: lh          $t9, 0x66($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X66);
    // 0x8004376C: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x80043770: sll         $t0, $t7, 3
    ctx->r8 = S32(ctx->r15 << 3);
    // 0x80043774: blez        $t9, L_80043B0C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80043778: lui         $t1, 0x8007
        ctx->r9 = S32(0X8007 << 16);
            goto L_80043B0C;
    }
    // 0x80043778: lui         $t1, 0x8007
    ctx->r9 = S32(0X8007 << 16);
    // 0x8004377C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80043780: addiu       $t1, $t1, -0x565C
    ctx->r9 = ADD32(ctx->r9, -0X565C);
    // 0x80043784: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x80043788: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8004378C: addiu       $s5, $s5, -0x6464
    ctx->r21 = ADD32(ctx->r21, -0X6464);
    // 0x80043790: addu        $fp, $t0, $t1
    ctx->r30 = ADD32(ctx->r8, ctx->r9);
    // 0x80043794: addiu       $s4, $zero, 0xC
    ctx->r20 = ADD32(0, 0XC);
    // 0x80043798: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x8004379C: addiu       $s2, $zero, 0xF
    ctx->r18 = ADD32(0, 0XF);
    // 0x800437A0: lh          $s0, 0x54($sp)
    ctx->r16 = MEM_H(ctx->r29, 0X54);
L_800437A4:
    // 0x800437A4: lw          $t2, 0x0($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X0);
    // 0x800437A8: andi        $t3, $s7, 0x3
    ctx->r11 = ctx->r23 & 0X3;
    // 0x800437AC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800437B0: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800437B4: jal         0x80049CFC
    // 0x800437B8: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    func_80049CFC(rdram, ctx);
        goto after_0;
    // 0x800437B8: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    after_0:
    // 0x800437BC: lh          $a3, 0x0($s5)
    ctx->r7 = MEM_H(ctx->r21, 0X0);
    // 0x800437C0: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x800437C4: lwc1        $f22, 0x4($fp)
    ctx->f22.u32l = MEM_W(ctx->r30, 0X4);
    // 0x800437C8: slti        $at, $a3, 0xF
    ctx->r1 = SIGNED(ctx->r7) < 0XF ? 1 : 0;
    // 0x800437CC: bne         $at, $zero, L_80043914
    if (ctx->r1 != 0) {
        // 0x800437D0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80043914;
    }
    // 0x800437D0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800437D4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800437D8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800437DC: lw          $t6, -0x64A0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X64A0);
    // 0x800437E0: lw          $t7, -0x649C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X649C);
    // 0x800437E4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800437E8: lh          $a1, 0x8($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X8);
    // 0x800437EC: lh          $v1, 0x8($t7)
    ctx->r3 = MEM_H(ctx->r15, 0X8);
    // 0x800437F0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800437F4: addiu       $a0, $a0, -0x6494
    ctx->r4 = ADD32(ctx->r4, -0X6494);
    // 0x800437F8: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800437FC: beq         $at, $zero, L_80043814
    if (ctx->r1 == 0) {
        // 0x80043800: lui         $t9, 0x8013
        ctx->r25 = S32(0X8013 << 16);
            goto L_80043814;
    }
    // 0x80043800: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80043804: sll         $a1, $v1, 16
    ctx->r5 = S32(ctx->r3 << 16);
    // 0x80043808: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8004380C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80043810: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80043814:
    // 0x80043814: lw          $t9, -0x6498($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6498);
    // 0x80043818: lh          $v1, 0x8($t9)
    ctx->r3 = MEM_H(ctx->r25, 0X8);
    // 0x8004381C: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80043820: beql        $at, $zero, L_8004383C
    if (ctx->r1 == 0) {
        // 0x80043824: addiu       $v1, $zero, 0x3
        ctx->r3 = ADD32(0, 0X3);
            goto L_8004383C;
    }
    goto skip_0;
    // 0x80043824: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    skip_0:
    // 0x80043828: sll         $a1, $v1, 16
    ctx->r5 = S32(ctx->r3 << 16);
    // 0x8004382C: sra         $t0, $a1, 16
    ctx->r8 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80043830: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x80043834: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x80043838: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_8004383C:
    // 0x8004383C: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80043840: lh          $a2, 0x8($t1)
    ctx->r6 = MEM_H(ctx->r9, 0X8);
    // 0x80043844: slt         $at, $a2, $a1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80043848: beql        $at, $zero, L_8004386C
    if (ctx->r1 == 0) {
        // 0x8004384C: lw          $t4, 0x4($a0)
        ctx->r12 = MEM_W(ctx->r4, 0X4);
            goto L_8004386C;
    }
    goto skip_1;
    // 0x8004384C: lw          $t4, 0x4($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X4);
    skip_1:
    // 0x80043850: sll         $a1, $a2, 16
    ctx->r5 = S32(ctx->r6 << 16);
    // 0x80043854: sll         $s0, $v1, 16
    ctx->r16 = S32(ctx->r3 << 16);
    // 0x80043858: sra         $t3, $a1, 16
    ctx->r11 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8004385C: sra         $t2, $s0, 16
    ctx->r10 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80043860: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x80043864: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x80043868: lw          $t4, 0x4($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X4);
L_8004386C:
    // 0x8004386C: lh          $a2, 0x8($t4)
    ctx->r6 = MEM_H(ctx->r12, 0X8);
    // 0x80043870: slt         $at, $a2, $a1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80043874: beql        $at, $zero, L_80043898
    if (ctx->r1 == 0) {
        // 0x80043878: lw          $t8, 0x8($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X8);
            goto L_80043898;
    }
    goto skip_2;
    // 0x80043878: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    skip_2:
    // 0x8004387C: sll         $a1, $a2, 16
    ctx->r5 = S32(ctx->r6 << 16);
    // 0x80043880: addiu       $s0, $v1, 0x1
    ctx->r16 = ADD32(ctx->r3, 0X1);
    // 0x80043884: sll         $t6, $s0, 16
    ctx->r14 = S32(ctx->r16 << 16);
    // 0x80043888: sra         $t5, $a1, 16
    ctx->r13 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8004388C: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x80043890: sra         $s0, $t6, 16
    ctx->r16 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80043894: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
L_80043898:
    // 0x80043898: lh          $a2, 0x8($t8)
    ctx->r6 = MEM_H(ctx->r24, 0X8);
    // 0x8004389C: slt         $at, $a2, $a1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800438A0: beql        $at, $zero, L_800438C4
    if (ctx->r1 == 0) {
        // 0x800438A4: lw          $t3, 0xC($a0)
        ctx->r11 = MEM_W(ctx->r4, 0XC);
            goto L_800438C4;
    }
    goto skip_3;
    // 0x800438A4: lw          $t3, 0xC($a0)
    ctx->r11 = MEM_W(ctx->r4, 0XC);
    skip_3:
    // 0x800438A8: sll         $a1, $a2, 16
    ctx->r5 = S32(ctx->r6 << 16);
    // 0x800438AC: addiu       $s0, $v1, 0x2
    ctx->r16 = ADD32(ctx->r3, 0X2);
    // 0x800438B0: sll         $t0, $s0, 16
    ctx->r8 = S32(ctx->r16 << 16);
    // 0x800438B4: sra         $t9, $a1, 16
    ctx->r25 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800438B8: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x800438BC: sra         $s0, $t0, 16
    ctx->r16 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800438C0: lw          $t3, 0xC($a0)
    ctx->r11 = MEM_W(ctx->r4, 0XC);
L_800438C4:
    // 0x800438C4: lh          $a2, 0x8($t3)
    ctx->r6 = MEM_H(ctx->r11, 0X8);
    // 0x800438C8: slt         $at, $a2, $a1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800438CC: beql        $at, $zero, L_800438F0
    if (ctx->r1 == 0) {
        // 0x800438D0: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800438F0;
    }
    goto skip_4;
    // 0x800438D0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_4:
    // 0x800438D4: sll         $a1, $a2, 16
    ctx->r5 = S32(ctx->r6 << 16);
    // 0x800438D8: addiu       $s0, $v1, 0x3
    ctx->r16 = ADD32(ctx->r3, 0X3);
    // 0x800438DC: sll         $t4, $s0, 16
    ctx->r12 = S32(ctx->r16 << 16);
    // 0x800438E0: sra         $t2, $a1, 16
    ctx->r10 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800438E4: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x800438E8: sra         $s0, $t4, 16
    ctx->r16 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800438EC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_800438F0:
    // 0x800438F0: bne         $v1, $s2, L_8004383C
    if (ctx->r3 != ctx->r18) {
        // 0x800438F4: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_8004383C;
    }
    // 0x800438F4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800438F8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800438FC: addiu       $t8, $t8, -0x64A0
    ctx->r24 = ADD32(ctx->r24, -0X64A0);
    // 0x80043900: addiu       $t6, $a3, -0x1
    ctx->r14 = ADD32(ctx->r7, -0X1);
    // 0x80043904: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x80043908: addu        $s1, $t7, $t8
    ctx->r17 = ADD32(ctx->r15, ctx->r24);
    // 0x8004390C: b           L_80043974
    // 0x80043910: sh          $t6, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r14;
        goto L_80043974;
    // 0x80043910: sh          $t6, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r14;
L_80043914:
    // 0x80043914: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80043918: addiu       $a0, $a0, -0x64A0
    ctx->r4 = ADD32(ctx->r4, -0X64A0);
L_8004391C:
    // 0x8004391C: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x80043920: lh          $t9, 0x8($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X8);
    // 0x80043924: bnel        $t9, $zero, L_8004395C
    if (ctx->r25 != 0) {
        // 0x80043928: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8004395C;
    }
    goto skip_5;
    // 0x80043928: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_5:
    // 0x8004392C: lh          $a2, 0xA($a1)
    ctx->r6 = MEM_H(ctx->r5, 0XA);
    // 0x80043930: sll         $s0, $v1, 16
    ctx->r16 = S32(ctx->r3 << 16);
    // 0x80043934: sra         $t0, $s0, 16
    ctx->r8 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80043938: beq         $v0, $a2, L_80043944
    if (ctx->r2 == ctx->r6) {
        // 0x8004393C: or          $s0, $t0, $zero
        ctx->r16 = ctx->r8 | 0;
            goto L_80043944;
    }
    // 0x8004393C: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
    // 0x80043940: bne         $s3, $a2, L_80043958
    if (ctx->r19 != ctx->r6) {
        // 0x80043944: lui         $t3, 0x8013
        ctx->r11 = S32(0X8013 << 16);
            goto L_80043958;
    }
L_80043944:
    // 0x80043944: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80043948: addiu       $t3, $t3, -0x64A0
    ctx->r11 = ADD32(ctx->r11, -0X64A0);
    // 0x8004394C: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    // 0x80043950: b           L_80043974
    // 0x80043954: addu        $s1, $t1, $t3
    ctx->r17 = ADD32(ctx->r9, ctx->r11);
        goto L_80043974;
    // 0x80043954: addu        $s1, $t1, $t3
    ctx->r17 = ADD32(ctx->r9, ctx->r11);
L_80043958:
    // 0x80043958: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8004395C:
    // 0x8004395C: bne         $v1, $s2, L_8004391C
    if (ctx->r3 != ctx->r18) {
        // 0x80043960: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_8004391C;
    }
    // 0x80043960: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80043964: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80043968: addiu       $t4, $t4, -0x64A0
    ctx->r12 = ADD32(ctx->r12, -0X64A0);
    // 0x8004396C: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x80043970: addu        $s1, $t2, $t4
    ctx->r17 = ADD32(ctx->r10, ctx->r12);
L_80043974:
    // 0x80043974: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80043978: lh          $v1, 0xA($a1)
    ctx->r3 = MEM_H(ctx->r5, 0XA);
    // 0x8004397C: beql        $v0, $v1, L_800439D8
    if (ctx->r2 == ctx->r3) {
        // 0x80043980: addiu       $t0, $zero, 0x50
        ctx->r8 = ADD32(0, 0X50);
            goto L_800439D8;
    }
    goto skip_6;
    // 0x80043980: addiu       $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
    skip_6:
    // 0x80043984: beq         $s3, $v1, L_80043994
    if (ctx->r19 == ctx->r3) {
        // 0x80043988: nop
    
            goto L_80043994;
    }
    // 0x80043988: nop

    // 0x8004398C: jal         0x8004A0C4
    // 0x80043990: lw          $a0, 0x4($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X4);
    func_8004A0C4(rdram, ctx);
        goto after_1;
    // 0x80043990: lw          $a0, 0x4($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X4);
    after_1:
L_80043994:
    // 0x80043994: jal         0x80049D80
    // 0x80043998: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_80049D80(rdram, ctx);
        goto after_2;
    // 0x80043998: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_2:
    // 0x8004399C: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x800439A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800439A4: sw          $v0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r2;
    // 0x800439A8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800439AC: jal         0x80049DFC
    // 0x800439B0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_80049DFC(rdram, ctx);
        goto after_3;
    // 0x800439B0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_3:
    // 0x800439B4: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800439B8: sw          $v0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r2;
    // 0x800439BC: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800439C0: jal         0x8004A148
    // 0x800439C4: lw          $a0, 0x4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X4);
    func_8004A148(rdram, ctx);
        goto after_4;
    // 0x800439C4: lw          $a0, 0x4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X4);
    after_4:
    // 0x800439C8: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800439CC: sh          $s6, 0xA($t9)
    MEM_H(0XA, ctx->r25) = ctx->r22;
    // 0x800439D0: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x800439D4: addiu       $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
L_800439D8:
    // 0x800439D8: sh          $t0, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r8;
    // 0x800439DC: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x800439E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800439E4: swc1        $f22, 0x2C($t1)
    MEM_W(0X2C, ctx->r9) = ctx->f22.u32l;
    // 0x800439E8: lw          $v1, 0x60($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X60);
L_800439EC:
    // 0x800439EC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x800439F0: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800439F4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800439F8: addu        $t2, $t3, $v0
    ctx->r10 = ADD32(ctx->r11, ctx->r2);
    // 0x800439FC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80043A00: bne         $v0, $s4, L_800439EC
    if (ctx->r2 != ctx->r20) {
        // 0x80043A04: swc1        $f4, 0xC($t2)
        MEM_W(0XC, ctx->r10) = ctx->f4.u32l;
            goto L_800439EC;
    }
    // 0x80043A04: swc1        $f4, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f4.u32l;
    // 0x80043A08: jal         0x8000E35C
    // 0x80043A0C: nop

    func_8000E35C(rdram, ctx);
        goto after_5;
    // 0x80043A0C: nop

    after_5:
    // 0x80043A10: andi        $t4, $v0, 0xFF
    ctx->r12 = ctx->r2 & 0XFF;
    // 0x80043A14: addiu       $t5, $t4, 0xA
    ctx->r13 = ADD32(ctx->r12, 0XA);
    // 0x80043A18: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80043A1C: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80043A20: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80043A24: div.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80043A28: jal         0x8000E35C
    // 0x80043A2C: swc1        $f10, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f10.u32l;
    func_8000E35C(rdram, ctx);
        goto after_6;
    // 0x80043A2C: swc1        $f10, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f10.u32l;
    after_6:
    // 0x80043A30: andi        $t7, $v0, 0x1FF
    ctx->r15 = ctx->r2 & 0X1FF;
    // 0x80043A34: addiu       $t8, $t7, 0xA
    ctx->r24 = ADD32(ctx->r15, 0XA);
    // 0x80043A38: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80043A3C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80043A40: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80043A44: div.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80043A48: jal         0x8000E35C
    // 0x80043A4C: swc1        $f4, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f4.u32l;
    func_8000E35C(rdram, ctx);
        goto after_7;
    // 0x80043A4C: swc1        $f4, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f4.u32l;
    after_7:
    // 0x80043A50: andi        $t0, $v0, 0xFF
    ctx->r8 = ctx->r2 & 0XFF;
    // 0x80043A54: addiu       $t1, $t0, 0xA
    ctx->r9 = ADD32(ctx->r8, 0XA);
    // 0x80043A58: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80043A5C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80043A60: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80043A64: div.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80043A68: jal         0x8000E35C
    // 0x80043A6C: swc1        $f10, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f10.u32l;
    func_8000E35C(rdram, ctx);
        goto after_8;
    // 0x80043A6C: swc1        $f10, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f10.u32l;
    after_8:
    // 0x80043A70: andi        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 & 0X1;
    // 0x80043A74: beq         $t2, $zero, L_80043A8C
    if (ctx->r10 == 0) {
        // 0x80043A78: nop
    
            goto L_80043A8C;
    }
    // 0x80043A78: nop

    // 0x80043A7C: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80043A80: lwc1        $f16, 0x18($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X18);
    // 0x80043A84: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x80043A88: swc1        $f18, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->f18.u32l;
L_80043A8C:
    // 0x80043A8C: jal         0x8000E35C
    // 0x80043A90: nop

    func_8000E35C(rdram, ctx);
        goto after_9;
    // 0x80043A90: nop

    after_9:
    // 0x80043A94: andi        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 & 0X1;
    // 0x80043A98: beq         $t4, $zero, L_80043AB0
    if (ctx->r12 == 0) {
        // 0x80043A9C: nop
    
            goto L_80043AB0;
    }
    // 0x80043A9C: nop

    // 0x80043AA0: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80043AA4: lwc1        $f4, 0x20($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X20);
    // 0x80043AA8: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80043AAC: swc1        $f6, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f6.u32l;
L_80043AB0:
    // 0x80043AB0: jal         0x8000E35C
    // 0x80043AB4: nop

    func_8000E35C(rdram, ctx);
        goto after_10;
    // 0x80043AB4: nop

    after_10:
    // 0x80043AB8: addiu       $at, $zero, 0x63
    ctx->r1 = ADD32(0, 0X63);
    // 0x80043ABC: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80043AC0: mfhi        $t5
    ctx->r13 = hi;
    // 0x80043AC4: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80043AC8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80043ACC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80043AD0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80043AD4: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80043AD8: div.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80043ADC: swc1        $f16, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->f16.u32l;
    // 0x80043AE0: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80043AE4: lwc1        $f18, 0x7868($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7868);
    // 0x80043AE8: swc1        $f18, 0x28($t7)
    MEM_W(0X28, ctx->r15) = ctx->f18.u32l;
    // 0x80043AEC: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80043AF0: sh          $zero, 0x30($t8)
    MEM_H(0X30, ctx->r24) = 0;
    // 0x80043AF4: lh          $t9, 0x0($s5)
    ctx->r25 = MEM_H(ctx->r21, 0X0);
    // 0x80043AF8: lh          $t1, 0x66($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X66);
    // 0x80043AFC: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80043B00: bne         $s7, $t1, L_800437A4
    if (ctx->r23 != ctx->r9) {
        // 0x80043B04: sh          $t0, 0x0($s5)
        MEM_H(0X0, ctx->r21) = ctx->r8;
            goto L_800437A4;
    }
    // 0x80043B04: sh          $t0, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r8;
    // 0x80043B08: sh          $s0, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r16;
L_80043B0C:
    // 0x80043B0C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80043B10: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80043B14: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80043B18: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80043B1C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80043B20: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80043B24: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80043B28: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80043B2C: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80043B30: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80043B34: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80043B38: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80043B3C: jr          $ra
    // 0x80043B40: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    TRACE_RETURN()
    return;
    // 0x80043B40: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80043B44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80043B44: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x80043B48: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x80043B4C: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x80043B50: addiu       $s4, $s4, -0x6464
    ctx->r20 = ADD32(ctx->r20, -0X6464);
    // 0x80043B54: lh          $v0, 0x0($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X0);
    // 0x80043B58: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80043B5C: sw          $s7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r23;
    // 0x80043B60: sw          $s6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r22;
    // 0x80043B64: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x80043B68: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x80043B6C: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x80043B70: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80043B74: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80043B78: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80043B7C: blez        $v0, L_80043D28
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80043B80: sdc1        $f20, 0x18($sp)
        CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
            goto L_80043D28;
    }
    // 0x80043B80: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80043B84: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80043B88: lwc1        $f22, 0x786C($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X786C);
    // 0x80043B8C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80043B90: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80043B94: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x80043B98: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80043B9C: addiu       $s7, $s7, -0x6464
    ctx->r23 = ADD32(ctx->r23, -0X6464);
    // 0x80043BA0: addiu       $s1, $s1, -0x64A0
    ctx->r17 = ADD32(ctx->r17, -0X64A0);
    // 0x80043BA4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80043BA8: addiu       $s6, $zero, -0x2
    ctx->r22 = ADD32(0, -0X2);
    // 0x80043BAC: addiu       $s5, $sp, 0x68
    ctx->r21 = ADD32(ctx->r29, 0X68);
    // 0x80043BB0: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
    // 0x80043BB4: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
L_80043BB8:
    // 0x80043BB8: lh          $v0, 0x8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X8);
    // 0x80043BBC: beq         $v0, $zero, L_80043D1C
    if (ctx->r2 == 0) {
        // 0x80043BC0: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80043D1C;
    }
    // 0x80043BC0: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80043BC4: sh          $t6, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r14;
    // 0x80043BC8: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80043BCC: lh          $t7, 0x8($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X8);
    // 0x80043BD0: bnel        $t7, $zero, L_80043C00
    if (ctx->r15 != 0) {
        // 0x80043BD4: lwc1        $f4, 0x1C($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
            goto L_80043C00;
    }
    goto skip_0;
    // 0x80043BD4: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    skip_0:
    // 0x80043BD8: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x80043BDC: lw          $v0, 0x8($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X8);
    // 0x80043BE0: lw          $t9, 0xD8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XD8);
    // 0x80043BE4: and         $t0, $t9, $s6
    ctx->r8 = ctx->r25 & ctx->r22;
    // 0x80043BE8: sw          $t0, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r8;
    // 0x80043BEC: lh          $t1, 0x0($s4)
    ctx->r9 = MEM_H(ctx->r20, 0X0);
    // 0x80043BF0: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80043BF4: b           L_80043D1C
    // 0x80043BF8: sh          $t2, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r10;
        goto L_80043D1C;
    // 0x80043BF8: sh          $t2, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r10;
    // 0x80043BFC: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
L_80043C00:
    // 0x80043C00: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80043C04: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80043C08: sub.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f22.fl;
    // 0x80043C0C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80043C10: swc1        $f6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f6.u32l;
    // 0x80043C14: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80043C18: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80043C1C: lwc1        $f10, 0x28($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80043C20: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80043C24: swc1        $f16, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f16.u32l;
    // 0x80043C28: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80043C2C: lw          $a1, 0x24($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X24);
    // 0x80043C30: jal         0x80049840
    // 0x80043C34: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    func_80049840(rdram, ctx);
        goto after_0;
    // 0x80043C34: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_0:
    // 0x80043C38: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80043C3C: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80043C40: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x80043C44: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80043C48: lw          $a0, 0x8($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X8);
    // 0x80043C4C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80043C50: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80043C54: jal         0x80001AB4
    // 0x80043C58: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80001AB4(rdram, ctx);
        goto after_1;
    // 0x80043C58: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_1:
    // 0x80043C5C: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80043C60: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80043C64: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x80043C68: lw          $a0, 0x8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X8);
    // 0x80043C6C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80043C70: jal         0x80000BD8
    // 0x80043C74: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_80000BD8(rdram, ctx);
        goto after_2;
    // 0x80043C74: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_2:
    // 0x80043C78: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80043C7C: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80043C80: addiu       $s2, $s2, -0x4
    ctx->r18 = ADD32(ctx->r18, -0X4);
    // 0x80043C84: addu        $v0, $t7, $v1
    ctx->r2 = ADD32(ctx->r15, ctx->r3);
    // 0x80043C88: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80043C8C: lwc1        $f16, 0x18($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80043C90: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80043C94: swc1        $f16, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f16.u32l;
    // 0x80043C98: beq         $v1, $s2, L_80043CDC
    if (ctx->r3 == ctx->r18) {
        // 0x80043C9C: lw          $s0, 0x0($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X0);
            goto L_80043CDC;
    }
    // 0x80043C9C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
L_80043CA0:
    // 0x80043CA0: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x80043CA4: addu        $t8, $s0, $v1
    ctx->r24 = ADD32(ctx->r16, ctx->r3);
    // 0x80043CA8: lwc1        $f18, 0xC($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0XC);
    // 0x80043CAC: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x80043CB0: addu        $t1, $t0, $v1
    ctx->r9 = ADD32(ctx->r8, ctx->r3);
    // 0x80043CB4: swc1        $f18, 0x40($t1)
    MEM_W(0X40, ctx->r9) = ctx->f18.u32l;
    // 0x80043CB8: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80043CBC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80043CC0: addu        $v0, $t7, $v1
    ctx->r2 = ADD32(ctx->r15, ctx->r3);
    // 0x80043CC4: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80043CC8: lwc1        $f16, 0x18($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80043CCC: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80043CD0: swc1        $f16, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f16.u32l;
    // 0x80043CD4: bne         $v1, $s2, L_80043CA0
    if (ctx->r3 != ctx->r18) {
        // 0x80043CD8: lw          $s0, 0x0($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X0);
            goto L_80043CA0;
    }
    // 0x80043CD8: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
L_80043CDC:
    // 0x80043CDC: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x80043CE0: addu        $t8, $s0, $v1
    ctx->r24 = ADD32(ctx->r16, ctx->r3);
    // 0x80043CE4: lwc1        $f18, 0xC($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0XC);
    // 0x80043CE8: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x80043CEC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80043CF0: addu        $t1, $t0, $v1
    ctx->r9 = ADD32(ctx->r8, ctx->r3);
    // 0x80043CF4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80043CF8: swc1        $f18, 0x40($t1)
    MEM_W(0X40, ctx->r9) = ctx->f18.u32l;
    // 0x80043CFC: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80043D00: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x80043D04: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x80043D08: lw          $v0, 0x8($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X8);
    // 0x80043D0C: lw          $t4, 0xD8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XD8);
    // 0x80043D10: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x80043D14: beq         $s3, $zero, L_80043D28
    if (ctx->r19 == 0) {
        // 0x80043D18: sw          $t5, 0xD8($v0)
        MEM_W(0XD8, ctx->r2) = ctx->r13;
            goto L_80043D28;
    }
    // 0x80043D18: sw          $t5, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r13;
L_80043D1C:
    // 0x80043D1C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80043D20: bnel        $s1, $s7, L_80043BB8
    if (ctx->r17 != ctx->r23) {
        // 0x80043D24: lw          $s0, 0x0($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X0);
            goto L_80043BB8;
    }
    goto skip_1;
    // 0x80043D24: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    skip_1:
L_80043D28:
    // 0x80043D28: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80043D2C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80043D30: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80043D34: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80043D38: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80043D3C: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x80043D40: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x80043D44: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x80043D48: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x80043D4C: lw          $s6, 0x44($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X44);
    // 0x80043D50: lw          $s7, 0x48($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X48);
    // 0x80043D54: jr          $ra
    // 0x80043D58: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    TRACE_RETURN()
    return;
    // 0x80043D58: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_80043D5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80043D5C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80043D60: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80043D64: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80043D68: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80043D6C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80043D70: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80043D74: lui         $s3, 0x801A
    ctx->r19 = S32(0X801A << 16);
    // 0x80043D78: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x80043D7C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80043D80: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80043D84: addiu       $s4, $s4, -0x6464
    ctx->r20 = ADD32(ctx->r20, -0X6464);
    // 0x80043D88: addiu       $s3, $s3, 0x2800
    ctx->r19 = ADD32(ctx->r19, 0X2800);
    // 0x80043D8C: addiu       $s1, $s1, -0x64A0
    ctx->r17 = ADD32(ctx->r17, -0X64A0);
    // 0x80043D90: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x80043D94: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
L_80043D98:
    // 0x80043D98: lh          $t6, 0xA($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XA);
    // 0x80043D9C: beql        $s2, $t6, L_80043DB4
    if (ctx->r18 == ctx->r14) {
        // 0x80043DA0: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80043DB4;
    }
    goto skip_0;
    // 0x80043DA0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_0:
    // 0x80043DA4: jal         0x8004A0C4
    // 0x80043DA8: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    func_8004A0C4(rdram, ctx);
        goto after_0;
    // 0x80043DA8: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_0:
    // 0x80043DAC: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80043DB0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80043DB4:
    // 0x80043DB4: jal         0x800042A8
    // 0x80043DB8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800042A8(rdram, ctx);
        goto after_1;
    // 0x80043DB8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80043DBC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80043DC0: bnel        $s1, $s4, L_80043D98
    if (ctx->r17 != ctx->r20) {
        // 0x80043DC4: lw          $s0, 0x0($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X0);
            goto L_80043D98;
    }
    goto skip_1;
    // 0x80043DC4: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    skip_1:
    // 0x80043DC8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80043DCC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80043DD0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80043DD4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80043DD8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80043DDC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80043DE0: jr          $ra
    // 0x80043DE4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    TRACE_RETURN()
    return;
    // 0x80043DE4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80043DE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80043DE8: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80043DEC: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80043DF0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80043DF4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80043DF8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80043DFC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80043E00: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80043E04: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80043E08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80043E0C: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x80043E10: addiu       $s1, $sp, 0x5C
    ctx->r17 = ADD32(ctx->r29, 0X5C);
    // 0x80043E14: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80043E18: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x80043E1C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80043E20: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80043E24: addiu       $s6, $zero, 0x6
    ctx->r22 = ADD32(0, 0X6);
L_80043E28:
    // 0x80043E28: lwc1        $f4, 0x0($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80043E2C: swc1        $f4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f4.u32l;
    // 0x80043E30: lh          $t6, 0x0($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X0);
    // 0x80043E34: beql        $t6, $zero, L_80043E84
    if (ctx->r14 == 0) {
        // 0x80043E38: lh          $v0, 0x0($s3)
        ctx->r2 = MEM_H(ctx->r19, 0X0);
            goto L_80043E84;
    }
    goto skip_0;
    // 0x80043E38: lh          $v0, 0x0($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X0);
    skip_0:
    // 0x80043E3C: jal         0x8000E35C
    // 0x80043E40: nop

    func_8000E35C(rdram, ctx);
        goto after_0;
    // 0x80043E40: nop

    after_0:
    // 0x80043E44: lh          $t8, 0x0($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X0);
    // 0x80043E48: lh          $t7, 0x0($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X0);
    // 0x80043E4C: and         $t9, $v0, $t8
    ctx->r25 = ctx->r2 & ctx->r24;
    // 0x80043E50: jal         0x8000E35C
    // 0x80043E54: addu        $s0, $t7, $t9
    ctx->r16 = ADD32(ctx->r15, ctx->r25);
    func_8000E35C(rdram, ctx);
        goto after_1;
    // 0x80043E54: addu        $s0, $t7, $t9
    ctx->r16 = ADD32(ctx->r15, ctx->r25);
    after_1:
    // 0x80043E58: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x80043E5C: beql        $t0, $zero, L_80043E6C
    if (ctx->r8 == 0) {
        // 0x80043E60: mtc1        $s0, $f8
        ctx->f8.u32l = ctx->r16;
            goto L_80043E6C;
    }
    goto skip_1;
    // 0x80043E60: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    skip_1:
    // 0x80043E64: negu        $s0, $s0
    ctx->r16 = SUB32(0, ctx->r16);
    // 0x80043E68: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
L_80043E6C:
    // 0x80043E6C: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80043E70: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80043E74: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80043E78: b           L_80043EA0
    // 0x80043E7C: swc1        $f16, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
        goto L_80043EA0;
    // 0x80043E7C: swc1        $f16, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
    // 0x80043E80: lh          $v0, 0x0($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X0);
L_80043E84:
    // 0x80043E84: beql        $v0, $zero, L_80043EA4
    if (ctx->r2 == 0) {
        // 0x80043E88: addiu       $s5, $s5, 0x2
        ctx->r21 = ADD32(ctx->r21, 0X2);
            goto L_80043EA4;
    }
    goto skip_2;
    // 0x80043E88: addiu       $s5, $s5, 0x2
    ctx->r21 = ADD32(ctx->r21, 0X2);
    skip_2:
    // 0x80043E8C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80043E90: lwc1        $f18, 0x0($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80043E94: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80043E98: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80043E9C: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
L_80043EA0:
    // 0x80043EA0: addiu       $s5, $s5, 0x2
    ctx->r21 = ADD32(ctx->r21, 0X2);
L_80043EA4:
    // 0x80043EA4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80043EA8: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80043EAC: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x80043EB0: bne         $s5, $s6, L_80043E28
    if (ctx->r21 != ctx->r22) {
        // 0x80043EB4: addiu       $s3, $s3, 0x2
        ctx->r19 = ADD32(ctx->r19, 0X2);
            goto L_80043E28;
    }
    // 0x80043EB4: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x80043EB8: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x80043EBC: lh          $a1, 0x76($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X76);
    // 0x80043EC0: jal         0x80042F80
    // 0x80043EC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80042F80(rdram, ctx);
        goto after_2;
    // 0x80043EC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80043EC8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80043ECC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80043ED0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80043ED4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80043ED8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80043EDC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80043EE0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80043EE4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80043EE8: jr          $ra
    // 0x80043EEC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    TRACE_RETURN()
    return;
    // 0x80043EEC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
static void func_80043EF0_entry(uint8_t* rdram, recomp_context* ctx, unsigned entry) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    if (entry == 1) goto indirect_80044020;

    // 0x80043EF0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80043EF4: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80043EF8: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80043EFC: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x80043F00: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80043F04: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80043F08: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80043F0C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80043F10: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80043F14: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80043F18: beq         $at, $zero, L_80043F90
    if (ctx->r1 == 0) {
        // 0x80043F1C: sw          $a1, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r5;
            goto L_80043F90;
    }
    // 0x80043F1C: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80043F20: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80043F24: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80043F28: addu        $at, $at, $t8
    gpr jr_addend_80043F30 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80043F2C: lw          $t8, 0x7870($at)
    ctx->r24 = ADD32(ctx->r1, 0X7870);
    // 0x80043F30: jr          $t8
    // 0x80043F34: nop

    switch (jr_addend_80043F30 >> 2) {
        case 0: goto L_80043F38; break;
        case 1: goto L_80043F48; break;
        case 2: goto L_80043F5C; break;
        case 3: goto L_80043F70; break;
        case 4: goto L_80043F84; break;
        default: switch_error(__func__, 0x80043F30, 0x80077870);
    }
    // 0x80043F34: nop

L_80043F38:
    // 0x80043F38: addiu       $t9, $zero, 0x19
    ctx->r25 = ADD32(0, 0X19);
    // 0x80043F3C: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x80043F40: b           L_80043F90
    // 0x80043F44: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
        goto L_80043F90;
    // 0x80043F44: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
L_80043F48:
    // 0x80043F48: addiu       $s3, $zero, 0x7
    ctx->r19 = ADD32(0, 0X7);
    // 0x80043F4C: addiu       $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
    // 0x80043F50: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x80043F54: b           L_80043F90
    // 0x80043F58: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
        goto L_80043F90;
    // 0x80043F58: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
L_80043F5C:
    // 0x80043F5C: addiu       $s3, $zero, 0xF
    ctx->r19 = ADD32(0, 0XF);
    // 0x80043F60: addiu       $t1, $zero, 0x19
    ctx->r9 = ADD32(0, 0X19);
    // 0x80043F64: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x80043F68: b           L_80043F90
    // 0x80043F6C: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
        goto L_80043F90;
    // 0x80043F6C: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
L_80043F70:
    // 0x80043F70: addiu       $s3, $zero, 0xF
    ctx->r19 = ADD32(0, 0XF);
    // 0x80043F74: addiu       $t2, $zero, 0x1A
    ctx->r10 = ADD32(0, 0X1A);
    // 0x80043F78: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x80043F7C: b           L_80043F90
    // 0x80043F80: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
        goto L_80043F90;
    // 0x80043F80: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
L_80043F84:
    // 0x80043F84: addiu       $t3, $zero, 0x1A
    ctx->r11 = ADD32(0, 0X1A);
    // 0x80043F88: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x80043F8C: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
L_80043F90:
    // 0x80043F90: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80043F94: addiu       $s0, $sp, 0x4C
    ctx->r16 = ADD32(ctx->r29, 0X4C);
    // 0x80043F98: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80043F9C: addiu       $s4, $sp, 0x58
    ctx->r20 = ADD32(ctx->r29, 0X58);
L_80043FA0:
    // 0x80043FA0: lwc1        $f4, 0x0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80043FA4: beq         $s3, $zero, L_80043FE0
    if (ctx->r19 == 0) {
        // 0x80043FA8: swc1        $f4, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
            goto L_80043FE0;
    }
    // 0x80043FA8: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x80043FAC: jal         0x8000E35C
    // 0x80043FB0: nop

    func_8000E35C(rdram, ctx);
        goto after_0;
    // 0x80043FB0: nop

    after_0:
    // 0x80043FB4: jal         0x8000E35C
    // 0x80043FB8: and         $s1, $v0, $s3
    ctx->r17 = ctx->r2 & ctx->r19;
    func_8000E35C(rdram, ctx);
        goto after_1;
    // 0x80043FB8: and         $s1, $v0, $s3
    ctx->r17 = ctx->r2 & ctx->r19;
    after_1:
    // 0x80043FBC: andi        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 & 0X1;
    // 0x80043FC0: beql        $t4, $zero, L_80043FD0
    if (ctx->r12 == 0) {
        // 0x80043FC4: mtc1        $s1, $f8
        ctx->f8.u32l = ctx->r17;
            goto L_80043FD0;
    }
    goto skip_0;
    // 0x80043FC4: mtc1        $s1, $f8
    ctx->f8.u32l = ctx->r17;
    skip_0:
    // 0x80043FC8: negu        $s1, $s1
    ctx->r17 = SUB32(0, ctx->r17);
    // 0x80043FCC: mtc1        $s1, $f8
    ctx->f8.u32l = ctx->r17;
L_80043FD0:
    // 0x80043FD0: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80043FD4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80043FD8: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80043FDC: swc1        $f16, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f16.u32l;
L_80043FE0:
    // 0x80043FE0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80043FE4: bne         $s0, $s4, L_80043FA0
    if (ctx->r16 != ctx->r20) {
        // 0x80043FE8: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80043FA0;
    }
    // 0x80043FE8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80043FEC: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80043FF0: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80043FF4: jal         0x80042F80
    // 0x80043FF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80042F80(rdram, ctx);
        goto after_2;
    // 0x80043FF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80043FFC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80044000: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80044004: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80044008: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8004400C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80044010: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80044014: jr          $ra
    // 0x80044018: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    TRACE_RETURN()
    return;
    // 0x80044018: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8004401C: nop

indirect_80044020:
    // 0x80044020: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80044024: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80044028: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8004402C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80044030: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80044034: jal         0x800440F8
    // 0x80044038: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_800440F8(rdram, ctx);
        goto after_3;
    // 0x80044038: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_3:
    // 0x8004403C: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x80044040: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80044044: sh          $s2, -0x6458($at)
    MEM_H(-0X6458, ctx->r1) = ctx->r18;
    // 0x80044048: jal         0x80044514
    // 0x8004404C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80044514(rdram, ctx);
        goto after_4;
    // 0x8004404C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x80044050: addiu       $s0, $zero, -0x2
    ctx->r16 = ADD32(0, -0X2);
    // 0x80044054: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_80044058:
    // 0x80044058: bne         $s2, $v0, L_8004407C
    if (ctx->r18 != ctx->r2) {
        // 0x8004405C: nop
    
            goto L_8004407C;
    }
    // 0x8004405C: nop

    // 0x80044060: jal         0x80044198
    // 0x80044064: nop

    func_80044198(rdram, ctx);
        goto after_5;
    // 0x80044064: nop

    after_5:
    // 0x80044068: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_8004406C:
    // 0x8004406C: jal         0x8000798C
    // 0x80044070: nop

    func_8000798C(rdram, ctx);
        goto after_6;
    // 0x80044070: nop

    after_6:
    // 0x80044074: b           L_8004406C
    // 0x80044078: nop

        goto L_8004406C;
    // 0x80044078: nop

L_8004407C:
    // 0x8004407C: bne         $s0, $v0, L_800440B4
    if (ctx->r16 != ctx->r2) {
        // 0x80044080: nop
    
            goto L_800440B4;
    }
    // 0x80044080: nop

    // 0x80044084: jal         0x80044218
    // 0x80044088: nop

    func_80044218(rdram, ctx);
        goto after_7;
    // 0x80044088: nop

    after_7:
    // 0x8004408C: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80044090: bne         $s0, $t6, L_800440AC
    if (ctx->r16 != ctx->r14) {
        // 0x80044094: nop
    
            goto L_800440AC;
    }
    // 0x80044094: nop

L_80044098:
    // 0x80044098: jal         0x8000798C
    // 0x8004409C: nop

    func_8000798C(rdram, ctx);
        goto after_8;
    // 0x8004409C: nop

    after_8:
    // 0x800440A0: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800440A4: beq         $s0, $t7, L_80044098
    if (ctx->r16 == ctx->r15) {
        // 0x800440A8: nop
    
            goto L_80044098;
    }
    // 0x800440A8: nop

L_800440AC:
    // 0x800440AC: jal         0x800442E0
    // 0x800440B0: nop

    func_800442E0(rdram, ctx);
        goto after_9;
    // 0x800440B0: nop

    after_9:
L_800440B4:
    // 0x800440B4: jal         0x8004455C
    // 0x800440B8: nop

    func_8004455C(rdram, ctx);
        goto after_10;
    // 0x800440B8: nop

    after_10:
    // 0x800440BC: jal         0x8000798C
    // 0x800440C0: nop

    func_8000798C(rdram, ctx);
        goto after_11;
    // 0x800440C0: nop

    after_11:
    // 0x800440C4: b           L_80044058
    // 0x800440C8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
        goto L_80044058;
    // 0x800440C8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800440CC: nop

    // 0x800440D0: nop

    // 0x800440D4: nop

    // 0x800440D8: nop

    // 0x800440DC: nop

    // 0x800440E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800440E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800440E8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800440EC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800440F0: jr          $ra
    // 0x800440F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    TRACE_RETURN()
    return;
    // 0x800440F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80043EF0(uint8_t* rdram, recomp_context* ctx) { func_80043EF0_entry(rdram, ctx, 0); }
RECOMP_FUNC void func_80044020(uint8_t* rdram, recomp_context* ctx) { func_80043EF0_entry(rdram, ctx, 1); }

RECOMP_FUNC void func_800440F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800440F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800440FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80044100: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80044104: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80044108: jal         0x80004364
    // 0x8004410C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x8004410C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_0:
    // 0x80044110: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80044114: addiu       $v1, $v1, -0x6460
    ctx->r3 = ADD32(ctx->r3, -0X6460);
    // 0x80044118: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8004411C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80044120: jal         0x8000C7C0
    // 0x80044124: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_8000C7C0(rdram, ctx);
        goto after_1;
    // 0x80044124: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_1:
    // 0x80044128: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004412C: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80044130: jal         0x80004364
    // 0x80044134: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_80004364(rdram, ctx);
        goto after_2;
    // 0x80044134: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_2:
    // 0x80044138: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004413C: addiu       $v1, $v1, -0x645C
    ctx->r3 = ADD32(ctx->r3, -0X645C);
    // 0x80044140: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80044144: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80044148: jal         0x8000C7C0
    // 0x8004414C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_8000C7C0(rdram, ctx);
        goto after_3;
    // 0x8004414C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_3:
    // 0x80044150: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80044154: addiu       $v0, $v0, -0x6460
    ctx->r2 = ADD32(ctx->r2, -0X6460);
    // 0x80044158: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8004415C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80044160: addiu       $v1, $v1, -0x645C
    ctx->r3 = ADD32(ctx->r3, -0X645C);
    // 0x80044164: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x80044168: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8004416C: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x80044170: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80044174: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80044178: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8004417C: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x80044180: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80044184: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x80044188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004418C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80044190: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80044198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80044198: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004419C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800441A0: lw          $a1, -0x6460($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6460);
    // 0x800441A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800441A8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800441AC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800441B0: lw          $s0, 0x0($a1)
    ctx->r16 = MEM_W(ctx->r5, 0X0);
    // 0x800441B4: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800441B8: beq         $t6, $zero, L_800441E4
    if (ctx->r14 == 0) {
        // 0x800441BC: nop
    
            goto L_800441E4;
    }
    // 0x800441BC: nop

    // 0x800441C0: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
L_800441C4:
    // 0x800441C4: jal         0x80044348
    // 0x800441C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80044348(rdram, ctx);
        goto after_0;
    // 0x800441C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800441CC: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800441D0: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800441D4: bnel        $t7, $zero, L_800441C4
    if (ctx->r15 != 0) {
        // 0x800441D8: lw          $s1, 0x0($s0)
        ctx->r17 = MEM_W(ctx->r16, 0X0);
            goto L_800441C4;
    }
    goto skip_0;
    // 0x800441D8: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x800441DC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800441E0: lw          $a1, -0x6460($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6460);
L_800441E4:
    // 0x800441E4: lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // 0x800441E8: addiu       $s0, $s0, 0x2800
    ctx->r16 = ADD32(ctx->r16, 0X2800);
    // 0x800441EC: jal         0x800042A8
    // 0x800441F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800042A8(rdram, ctx);
        goto after_1;
    // 0x800441F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800441F4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800441F8: lw          $a1, -0x645C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X645C);
    // 0x800441FC: jal         0x800042A8
    // 0x80044200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800042A8(rdram, ctx);
        goto after_2;
    // 0x80044200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80044204: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80044208: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8004420C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80044210: jr          $ra
    // 0x80044214: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    TRACE_RETURN()
    return;
    // 0x80044214: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80044218(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80044218: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8004421C: lw          $t6, -0x6460($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6460);
    // 0x80044220: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80044224: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80044228: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004422C: lw          $s0, 0x0($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X0);
    // 0x80044230: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80044234: beql        $v0, $zero, L_8004426C
    if (ctx->r2 == 0) {
        // 0x80044238: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8004426C;
    }
    goto skip_0;
    // 0x80044238: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8004423C: lh          $t7, 0x8($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X8);
L_80044240:
    // 0x80044240: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x80044244: beql        $t8, $zero, L_8004425C
    if (ctx->r24 == 0) {
        // 0x80044248: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8004425C;
    }
    goto skip_1;
    // 0x80044248: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    skip_1:
    // 0x8004424C: jal         0x800444D0
    // 0x80044250: lh          $a0, 0x10($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X10);
    func_800444D0(rdram, ctx);
        goto after_0;
    // 0x80044250: lh          $a0, 0x10($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X10);
    after_0:
    // 0x80044254: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80044258: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8004425C:
    // 0x8004425C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80044260: bnel        $v0, $zero, L_80044240
    if (ctx->r2 != 0) {
        // 0x80044264: lh          $t7, 0x8($s0)
        ctx->r15 = MEM_H(ctx->r16, 0X8);
            goto L_80044240;
    }
    goto skip_2;
    // 0x80044264: lh          $t7, 0x8($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X8);
    skip_2:
    // 0x80044268: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004426C:
    // 0x8004426C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80044270: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80044274: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8004427C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004427C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80044280: lh          $t7, 0x6AD0($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X6AD0);
    // 0x80044284: sll         $a1, $a0, 16
    ctx->r5 = S32(ctx->r4 << 16);
    // 0x80044288: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8004428C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80044290: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80044294: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80044298: beq         $t7, $zero, L_800442B8
    if (ctx->r15 == 0) {
        // 0x8004429C: or          $a1, $t6, $zero
        ctx->r5 = ctx->r14 | 0;
            goto L_800442B8;
    }
    // 0x8004429C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
L_800442A0:
    // 0x800442A0: jal         0x8000804C
    // 0x800442A4: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
    func_8000804C(rdram, ctx);
        goto after_0;
    // 0x800442A4: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
    after_0:
    // 0x800442A8: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x800442AC: sra         $t8, $v1, 16
    ctx->r24 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800442B0: b           L_800442CC
    // 0x800442B4: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
        goto L_800442CC;
    // 0x800442B4: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_800442B8:
    // 0x800442B8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800442BC: lh          $t9, 0x6AD2($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X6AD2);
    // 0x800442C0: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800442C4: beq         $t9, $zero, L_800442A0
    if (ctx->r25 == 0) {
        // 0x800442C8: nop
    
            goto L_800442A0;
    }
    // 0x800442C8: nop

L_800442CC:
    // 0x800442CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800442D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800442D4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800442D8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800442E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800442E0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800442E4: lw          $t6, -0x6460($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6460);
    // 0x800442E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800442EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800442F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800442F4: lw          $s0, 0x0($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X0);
    // 0x800442F8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800442FC: beql        $v1, $zero, L_80044338
    if (ctx->r3 == 0) {
        // 0x80044300: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80044338;
    }
    goto skip_0;
    // 0x80044300: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80044304: lh          $t7, 0x8($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X8);
L_80044308:
    // 0x80044308: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x8004430C: beql        $t8, $zero, L_80044328
    if (ctx->r24 == 0) {
        // 0x80044310: or          $s0, $v1, $zero
        ctx->r16 = ctx->r3 | 0;
            goto L_80044328;
    }
    goto skip_1;
    // 0x80044310: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    skip_1:
    // 0x80044314: jal         0x8004427C
    // 0x80044318: lh          $a0, 0xA($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XA);
    func_8004427C(rdram, ctx);
        goto after_0;
    // 0x80044318: lh          $a0, 0xA($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XA);
    after_0:
    // 0x8004431C: sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
    // 0x80044320: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80044324: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
L_80044328:
    // 0x80044328: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8004432C: bnel        $v1, $zero, L_80044308
    if (ctx->r3 != 0) {
        // 0x80044330: lh          $t7, 0x8($s0)
        ctx->r15 = MEM_H(ctx->r16, 0X8);
            goto L_80044308;
    }
    goto skip_2;
    // 0x80044330: lh          $t7, 0x8($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X8);
    skip_2:
    // 0x80044334: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80044338:
    // 0x80044338: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004433C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80044340: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80044348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80044348: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004434C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80044350: lh          $t6, 0x8($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X8);
    // 0x80044354: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80044358: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x8004435C: beql        $t7, $zero, L_80044378
    if (ctx->r15 == 0) {
        // 0x80044360: lw          $t8, 0x0($a1)
        ctx->r24 = MEM_W(ctx->r5, 0X0);
            goto L_80044378;
    }
    goto skip_0;
    // 0x80044360: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    skip_0:
    // 0x80044364: lhu         $a0, 0x10($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X10);
    // 0x80044368: jal         0x80008320
    // 0x8004436C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_80008320(rdram, ctx);
        goto after_0;
    // 0x8004436C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80044370: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80044374: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
L_80044378:
    // 0x80044378: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x8004437C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80044380: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80044384: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80044388: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x8004438C: lw          $t0, 0x4($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X4);
    // 0x80044390: jal         0x800042A8
    // 0x80044394: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    func_800042A8(rdram, ctx);
        goto after_1;
    // 0x80044394: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    after_1:
    // 0x80044398: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004439C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800443A0: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800443A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800443A8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800443AC: lh          $t7, -0x6B94($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X6B94);
    // 0x800443B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800443B4: sll         $a2, $a0, 16
    ctx->r6 = S32(ctx->r4 << 16);
    // 0x800443B8: sra         $t6, $a2, 16
    ctx->r14 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800443BC: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x800443C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800443C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800443C8: bne         $t7, $zero, L_800443D8
    if (ctx->r15 != 0) {
        // 0x800443CC: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_800443D8;
    }
    // 0x800443CC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800443D0: b           L_80044470
    // 0x800443D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80044470;
    // 0x800443D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800443D8:
    // 0x800443D8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800443DC: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x800443E0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x800443E4: jal         0x80004364
    // 0x800443E8: sh          $a2, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r6;
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x800443E8: sh          $a2, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r6;
    after_0:
    // 0x800443EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800443F0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x800443F4: jal         0x8000C7C0
    // 0x800443F8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8000C7C0(rdram, ctx);
        goto after_1;
    // 0x800443F8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800443FC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80044400: addiu       $v0, $v0, -0x645C
    ctx->r2 = ADD32(ctx->r2, -0X645C);
    // 0x80044404: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80044408: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8004440C: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    // 0x80044410: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80044414: sll         $a0, $a2, 16
    ctx->r4 = S32(ctx->r6 << 16);
    // 0x80044418: sw          $v1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r3;
    // 0x8004441C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80044420: sra         $t4, $a0, 16
    ctx->r12 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80044424: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x80044428: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8004442C: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80044430: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80044434: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80044438: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8004443C: bgez        $a2, L_8004445C
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80044440: sw          $v1, 0x4($t3)
        MEM_W(0X4, ctx->r11) = ctx->r3;
            goto L_8004445C;
    }
    // 0x80044440: sw          $v1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r3;
    // 0x80044444: lh          $t7, 0x8($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X8);
    // 0x80044448: negu        $a0, $a2
    ctx->r4 = SUB32(0, ctx->r6);
    // 0x8004444C: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x80044450: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80044454: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80044458: sh          $t8, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r24;
L_8004445C:
    // 0x8004445C: andi        $t9, $a0, 0xFF
    ctx->r25 = ctx->r4 & 0XFF;
    // 0x80044460: sh          $t9, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r25;
    // 0x80044464: lh          $t0, 0x26($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X26);
    // 0x80044468: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8004446C: sh          $t0, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r8;
L_80044470:
    // 0x80044470: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80044474: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80044478: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80044480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80044480: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80044484: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80044488: sll         $v0, $t7, 16
    ctx->r2 = S32(ctx->r15 << 16);
    // 0x8004448C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80044490: sra         $t8, $v0, 16
    ctx->r24 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80044494: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80044498: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8004449C: bgez        $t7, L_800444B0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800444A0: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_800444B0;
    }
    // 0x800444A0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800444A4: negu        $v0, $t7
    ctx->r2 = SUB32(0, ctx->r15);
    // 0x800444A8: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x800444AC: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
L_800444B0:
    // 0x800444B0: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x800444B4: sll         $t1, $a0, 16
    ctx->r9 = S32(ctx->r4 << 16);
    // 0x800444B8: jal         0x8004427C
    // 0x800444BC: sra         $a0, $t1, 16
    ctx->r4 = S32(SIGNED(ctx->r9) >> 16);
    func_8004427C(rdram, ctx);
        goto after_0;
    // 0x800444BC: sra         $a0, $t1, 16
    ctx->r4 = S32(SIGNED(ctx->r9) >> 16);
    after_0:
    // 0x800444C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800444C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800444C8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800444D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800444D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800444D4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800444D8: beq         $a0, $at, L_800444E8
    if (ctx->r4 == ctx->r1) {
        // 0x800444DC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800444E8;
    }
    // 0x800444DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800444E0: jal         0x80008320
    // 0x800444E4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    func_80008320(rdram, ctx);
        goto after_0;
    // 0x800444E4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
L_800444E8:
    // 0x800444E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800444EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800444F0: jr          $ra
    TRACE_RETURN()
    return;
;}
