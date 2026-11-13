#include "recomp.h"
#include "trace.h"
#include "funcs.h"
extern void osSpTaskYielded_recomp(uint8_t*, recomp_context*);

RECOMP_FUNC void func_800576D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800576D0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800576D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800576D8: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x800576DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800576E0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800576E4: bne         $t6, $at, L_8005779C
    if (ctx->r14 != ctx->r1) {
        // 0x800576E8: lw          $a2, 0x18($a0)
        ctx->r6 = MEM_W(ctx->r4, 0X18);
            goto L_8005779C;
    }
    // 0x800576E8: lw          $a2, 0x18($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X18);
    // 0x800576EC: beq         $a2, $zero, L_8005779C
    if (ctx->r6 == 0) {
        // 0x800576F0: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8005779C;
    }
    // 0x800576F0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800576F4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x800576F8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800576FC: jal         0x80061380
    // 0x80057700: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    func_80061380(rdram, ctx);
        goto after_0;
    // 0x80057700: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_0:
    // 0x80057704: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80057708: beq         $v0, $zero, L_8005779C
    if (ctx->r2 == 0) {
        // 0x8005770C: lw          $a3, 0x38($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X38);
            goto L_8005779C;
    }
    // 0x8005770C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80057710: lw          $t7, 0x84($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X84);
    // 0x80057714: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80057718: beql        $t7, $zero, L_8005777C
    if (ctx->r15 == 0) {
        // 0x8005771C: sh          $zero, 0x28($sp)
        MEM_H(0X28, ctx->r29) = 0;
            goto L_8005777C;
    }
    goto skip_0;
    // 0x8005771C: sh          $zero, 0x28($sp)
    MEM_H(0X28, ctx->r29) = 0;
    skip_0:
    // 0x80057720: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80057724: jal         0x80060F48
    // 0x80057728: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    func_80060F48(rdram, ctx);
        goto after_1;
    // 0x80057728: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_1:
    // 0x8005772C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80057730: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80057734: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80057738: lw          $t0, 0x80($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X80);
    // 0x8005773C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80057740: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80057744: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x80057748: slt         $at, $t9, $t1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8005774C: bnel        $at, $zero, L_8005777C
    if (ctx->r1 != 0) {
        // 0x80057750: sh          $zero, 0x28($sp)
        MEM_H(0X28, ctx->r29) = 0;
            goto L_8005777C;
    }
    goto skip_1;
    // 0x80057750: sh          $zero, 0x28($sp)
    MEM_H(0X28, ctx->r29) = 0;
    skip_1:
    // 0x80057754: lw          $a1, 0x7C($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X7C);
    // 0x80057758: jal         0x80060F2C
    // 0x8005775C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    func_80060F2C(rdram, ctx);
        goto after_2;
    // 0x8005775C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_2:
    // 0x80057760: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80057764: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80057768: lw          $v0, 0x84($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X84);
    // 0x8005776C: beq         $v0, $at, L_80057778
    if (ctx->r2 == ctx->r1) {
        // 0x80057770: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_80057778;
    }
    // 0x80057770: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x80057774: sw          $t2, 0x84($a3)
    MEM_W(0X84, ctx->r7) = ctx->r10;
L_80057778:
    // 0x80057778: sh          $zero, 0x28($sp)
    MEM_H(0X28, ctx->r29) = 0;
L_8005777C:
    // 0x8005777C: lw          $t3, 0x24($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X24);
    // 0x80057780: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80057784: addiu       $a0, $a3, 0x48
    ctx->r4 = ADD32(ctx->r7, 0X48);
    // 0x80057788: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8005778C: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80057790: mflo        $a2
    ctx->r6 = lo;
    // 0x80057794: jal         0x8005702C
    // 0x80057798: nop

    func_8005702C(rdram, ctx);
        goto after_3;
    // 0x80057798: nop

    after_3:
L_8005779C:
    // 0x8005779C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800577A0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800577A4: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800577AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800577AC: lbu         $t6, 0x8($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X8);
    // 0x800577B0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800577B4: bne         $t6, $at, L_8005781C
    if (ctx->r14 != ctx->r1) {
        // 0x800577B8: nop
    
            goto L_8005781C;
    }
    // 0x800577B8: nop

    // 0x800577BC: lbu         $t7, 0x9($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X9);
    // 0x800577C0: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x800577C4: addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
    // 0x800577C8: bne         $t7, $at, L_8005781C
    if (ctx->r15 != ctx->r1) {
        // 0x800577CC: nop
    
            goto L_8005781C;
    }
    // 0x800577CC: nop

    // 0x800577D0: lbu         $t6, 0x8($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X8);
    // 0x800577D4: lbu         $t8, 0x7($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X7);
    // 0x800577D8: lw          $a2, 0x18($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X18);
    // 0x800577DC: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x800577E0: lbu         $t6, 0x9($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X9);
    // 0x800577E4: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800577E8: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x800577EC: or          $v1, $t8, $t6
    ctx->r3 = ctx->r24 | ctx->r14;
    // 0x800577F0: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800577F4: addiu       $t8, $zero, 0x1E8
    ctx->r24 = ADD32(0, 0X1E8);
    // 0x800577F8: beq         $a2, $zero, L_80057818
    if (ctx->r6 == 0) {
        // 0x800577FC: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80057818;
    }
    // 0x800577FC: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80057800: lwc1        $f6, 0x14($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80057804: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80057808: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8005780C: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80057810: jr          $ra
    // 0x80057814: sw          $t7, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r15;
    TRACE_RETURN()
    return;
    // 0x80057814: sw          $t7, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r15;
L_80057818:
    // 0x80057818: sw          $t8, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r24;
L_8005781C:
    // 0x8005781C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80057824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80057824: lbu         $t7, 0x31($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X31);
    // 0x80057828: lw          $t6, 0x60($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X60);
    // 0x8005782C: lw          $t1, 0x20($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X20);
    // 0x80057830: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80057834: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80057838: lbu         $t0, 0x7($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X7);
    // 0x8005783C: lbu         $t2, 0xC($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0XC);
    // 0x80057840: addu        $v1, $t0, $t2
    ctx->r3 = ADD32(ctx->r8, ctx->r10);
    // 0x80057844: addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
    // 0x80057848: bgtzl       $v1, L_80057858
    if (SIGNED(ctx->r3) > 0) {
        // 0x8005784C: slti        $at, $v1, 0x7F
        ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
            goto L_80057858;
    }
    goto skip_0;
    // 0x8005784C: slti        $at, $v1, 0x7F
    ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
    skip_0:
    // 0x80057850: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80057854: slti        $at, $v1, 0x7F
    ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
L_80057858:
    // 0x80057858: bne         $at, $zero, L_80057864
    if (ctx->r1 != 0) {
        // 0x8005785C: nop
    
            goto L_80057864;
    }
    // 0x8005785C: nop

    // 0x80057860: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
L_80057864:
    // 0x80057864: jr          $ra
    // 0x80057868: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    TRACE_RETURN()
    return;
    // 0x80057868: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
;}
RECOMP_FUNC void func_8005786C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005786C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80057870: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80057874: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x80057878: andi        $t7, $a2, 0xFF
    ctx->r15 = ctx->r6 & 0XFF;
    // 0x8005787C: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x80057880: beq         $v1, $zero, L_800578D4
    if (ctx->r3 == 0) {
        // 0x80057884: andi        $t6, $a1, 0xFF
        ctx->r14 = ctx->r5 & 0XFF;
            goto L_800578D4;
    }
    // 0x80057884: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80057888: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8005788C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80057890: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80057894: lbu         $t8, 0x32($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X32);
L_80057898:
    // 0x80057898: bnel        $v0, $t8, L_800578CC
    if (ctx->r2 != ctx->r24) {
        // 0x8005789C: lw          $v1, 0x0($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X0);
            goto L_800578CC;
    }
    goto skip_0;
    // 0x8005789C: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x800578A0: lbu         $t9, 0x31($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X31);
    // 0x800578A4: bnel        $a2, $t9, L_800578CC
    if (ctx->r6 != ctx->r25) {
        // 0x800578A8: lw          $v1, 0x0($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X0);
            goto L_800578CC;
    }
    goto skip_1;
    // 0x800578A8: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x800578AC: lbu         $a0, 0x35($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X35);
    // 0x800578B0: beql        $a1, $a0, L_800578CC
    if (ctx->r5 == ctx->r4) {
        // 0x800578B4: lw          $v1, 0x0($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X0);
            goto L_800578CC;
    }
    goto skip_2;
    // 0x800578B4: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    skip_2:
    // 0x800578B8: beql        $a3, $a0, L_800578CC
    if (ctx->r7 == ctx->r4) {
        // 0x800578BC: lw          $v1, 0x0($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X0);
            goto L_800578CC;
    }
    goto skip_3;
    // 0x800578BC: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    skip_3:
    // 0x800578C0: jr          $ra
    // 0x800578C4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    TRACE_RETURN()
    return;
    // 0x800578C4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800578C8: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
L_800578CC:
    // 0x800578CC: bnel        $v1, $zero, L_80057898
    if (ctx->r3 != 0) {
        // 0x800578D0: lbu         $t8, 0x32($v1)
        ctx->r24 = MEM_BU(ctx->r3, 0X32);
            goto L_80057898;
    }
    goto skip_4;
    // 0x800578D0: lbu         $t8, 0x32($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X32);
    skip_4:
L_800578D4:
    // 0x800578D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800578D8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800578E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800578E0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800578E4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800578E8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800578EC: lw          $v1, 0x6C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X6C);
    // 0x800578F0: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800578F4: andi        $t7, $a2, 0xFF
    ctx->r15 = ctx->r6 & 0XFF;
    // 0x800578F8: andi        $t8, $a3, 0xFF
    ctx->r24 = ctx->r7 & 0XFF;
    // 0x800578FC: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x80057900: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x80057904: beq         $v1, $zero, L_80057948
    if (ctx->r3 == 0) {
        // 0x80057908: or          $a1, $t6, $zero
        ctx->r5 = ctx->r14 | 0;
            goto L_80057948;
    }
    // 0x80057908: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8005790C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80057910: sw          $t9, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r25;
    // 0x80057914: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80057918: lw          $t0, 0x64($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X64);
    // 0x8005791C: bnel        $t0, $zero, L_80057930
    if (ctx->r8 != 0) {
        // 0x80057920: lw          $t1, 0x68($a0)
        ctx->r9 = MEM_W(ctx->r4, 0X68);
            goto L_80057930;
    }
    goto skip_0;
    // 0x80057920: lw          $t1, 0x68($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X68);
    skip_0:
    // 0x80057924: b           L_80057934
    // 0x80057928: sw          $v1, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r3;
        goto L_80057934;
    // 0x80057928: sw          $v1, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r3;
    // 0x8005792C: lw          $t1, 0x68($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X68);
L_80057930:
    // 0x80057930: sw          $v1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r3;
L_80057934:
    // 0x80057934: sw          $v1, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->r3;
    // 0x80057938: sb          $a3, 0x31($v1)
    MEM_B(0X31, ctx->r3) = ctx->r7;
    // 0x8005793C: sb          $a1, 0x32($v1)
    MEM_B(0X32, ctx->r3) = ctx->r5;
    // 0x80057940: sb          $a2, 0x33($v1)
    MEM_B(0X33, ctx->r3) = ctx->r6;
    // 0x80057944: sw          $v1, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r3;
L_80057948:
    // 0x80057948: jr          $ra
    // 0x8005794C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    TRACE_RETURN()
    return;
    // 0x8005794C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80057950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80057950: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80057954: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80057958: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8005795C: lw          $t8, 0x60($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X60);
    // 0x80057960: andi        $t7, $a3, 0xFF
    ctx->r15 = ctx->r7 & 0XFF;
    // 0x80057964: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x80057968: addu        $t4, $t8, $t9
    ctx->r12 = ADD32(ctx->r24, ctx->r25);
    // 0x8005796C: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x80057970: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80057974: andi        $t3, $a2, 0xFF
    ctx->r11 = ctx->r6 & 0XFF;
    // 0x80057978: lh          $t0, 0xE($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XE);
    // 0x8005797C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80057980: or          $t1, $t6, $zero
    ctx->r9 = ctx->r14 | 0;
    // 0x80057984: blez        $t0, L_80057A40
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80057988: addu        $a1, $v1, $t0
        ctx->r5 = ADD32(ctx->r3, ctx->r8);
            goto L_80057A40;
    }
    // 0x80057988: addu        $a1, $v1, $t0
    ctx->r5 = ADD32(ctx->r3, ctx->r8);
L_8005798C:
    // 0x8005798C: bgez        $a1, L_8005799C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80057990: sra         $t5, $a1, 1
        ctx->r13 = S32(SIGNED(ctx->r5) >> 1);
            goto L_8005799C;
    }
    // 0x80057990: sra         $t5, $a1, 1
    ctx->r13 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80057994: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
    // 0x80057998: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_8005799C:
    // 0x8005799C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800579A0: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800579A4: lw          $a3, 0xC($t7)
    ctx->r7 = MEM_W(ctx->r15, 0XC);
    // 0x800579A8: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x800579AC: lw          $a2, 0x4($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X4);
    // 0x800579B0: lbu         $t2, 0x2($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X2);
    // 0x800579B4: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800579B8: bnel        $at, $zero, L_80057A00
    if (ctx->r1 != 0) {
        // 0x800579BC: slt         $at, $t1, $t2
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_80057A00;
    }
    goto skip_0;
    // 0x800579BC: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    skip_0:
    // 0x800579C0: lbu         $t8, 0x3($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X3);
    // 0x800579C4: slt         $at, $t8, $t1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800579C8: bnel        $at, $zero, L_80057A00
    if (ctx->r1 != 0) {
        // 0x800579CC: slt         $at, $t1, $t2
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_80057A00;
    }
    goto skip_1;
    // 0x800579CC: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    skip_1:
    // 0x800579D0: lbu         $t9, 0x0($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X0);
    // 0x800579D4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x800579D8: slt         $at, $t3, $t9
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800579DC: bnel        $at, $zero, L_80057A00
    if (ctx->r1 != 0) {
        // 0x800579E0: slt         $at, $t1, $t2
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_80057A00;
    }
    goto skip_2;
    // 0x800579E0: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    skip_2:
    // 0x800579E4: lbu         $t4, 0x1($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X1);
    // 0x800579E8: slt         $at, $t4, $a1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800579EC: bnel        $at, $zero, L_80057A00
    if (ctx->r1 != 0) {
        // 0x800579F0: slt         $at, $t1, $t2
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_80057A00;
    }
    goto skip_3;
    // 0x800579F0: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    skip_3:
    // 0x800579F4: jr          $ra
    // 0x800579F8: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    TRACE_RETURN()
    return;
    // 0x800579F8: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x800579FC: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
L_80057A00:
    // 0x80057A00: bne         $at, $zero, L_80057A28
    if (ctx->r1 != 0) {
        // 0x80057A04: nop
    
            goto L_80057A28;
    }
    // 0x80057A04: nop

    // 0x80057A08: lbu         $t5, 0x0($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X0);
    // 0x80057A0C: slt         $at, $t3, $t5
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80057A10: beql        $at, $zero, L_80057A34
    if (ctx->r1 == 0) {
        // 0x80057A14: addiu       $v1, $a0, 0x1
        ctx->r3 = ADD32(ctx->r4, 0X1);
            goto L_80057A34;
    }
    goto skip_4;
    // 0x80057A14: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    skip_4:
    // 0x80057A18: lbu         $t6, 0x3($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X3);
    // 0x80057A1C: slt         $at, $t6, $t1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80057A20: bnel        $at, $zero, L_80057A34
    if (ctx->r1 != 0) {
        // 0x80057A24: addiu       $v1, $a0, 0x1
        ctx->r3 = ADD32(ctx->r4, 0X1);
            goto L_80057A34;
    }
    goto skip_5;
    // 0x80057A24: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    skip_5:
L_80057A28:
    // 0x80057A28: b           L_80057A34
    // 0x80057A2C: addiu       $t0, $a0, -0x1
    ctx->r8 = ADD32(ctx->r4, -0X1);
        goto L_80057A34;
    // 0x80057A2C: addiu       $t0, $a0, -0x1
    ctx->r8 = ADD32(ctx->r4, -0X1);
    // 0x80057A30: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
L_80057A34:
    // 0x80057A34: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80057A38: beql        $at, $zero, L_8005798C
    if (ctx->r1 == 0) {
        // 0x80057A3C: addu        $a1, $v1, $t0
        ctx->r5 = ADD32(ctx->r3, ctx->r8);
            goto L_8005798C;
    }
    goto skip_6;
    // 0x80057A3C: addu        $a1, $v1, $t0
    ctx->r5 = ADD32(ctx->r3, ctx->r8);
    skip_6:
L_80057A40:
    // 0x80057A40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80057A44: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80057A4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80057A4C: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x80057A50: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80057A54: lbu         $s6, 0x8($a0)
    ctx->r22 = MEM_BU(ctx->r4, 0X8);
    // 0x80057A58: lbu         $s3, 0x9($a0)
    ctx->r19 = MEM_BU(ctx->r4, 0X9);
    // 0x80057A5C: lbu         $s4, 0xA($a0)
    ctx->r20 = MEM_BU(ctx->r4, 0XA);
    // 0x80057A60: andi        $v1, $s6, 0xF0
    ctx->r3 = ctx->r22 & 0XF0;
    // 0x80057A64: addiu       $t7, $v1, -0x80
    ctx->r15 = ADD32(ctx->r3, -0X80);
    // 0x80057A68: sltiu       $at, $t7, 0x61
    ctx->r1 = ctx->r15 < 0X61 ? 1 : 0;
    // 0x80057A6C: andi        $t6, $s6, 0xF
    ctx->r14 = ctx->r22 & 0XF;
    // 0x80057A70: beq         $at, $zero, L_80058254
    if (ctx->r1 == 0) {
        // 0x80057A74: or          $s6, $t6, $zero
        ctx->r22 = ctx->r14 | 0;
            goto L_80058254;
    }
    // 0x80057A74: or          $s6, $t6, $zero
    ctx->r22 = ctx->r14 | 0;
    // 0x80057A78: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80057A7C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80057A80: addu        $at, $at, $t7
    gpr jr_addend_80057A88 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80057A84: lw          $t7, -0x6BC0($at)
    ctx->r15 = ADD32(ctx->r1, -0X6BC0);
    // 0x80057A88: jr          $t7
    // 0x80057A8C: nop

    switch (jr_addend_80057A88 >> 2) {
        case 0: goto L_80057DE4; break;
        case 1: goto L_80058254; break;
        case 2: goto L_80058254; break;
        case 3: goto L_80058254; break;
        case 4: goto L_80058254; break;
        case 5: goto L_80058254; break;
        case 6: goto L_80058254; break;
        case 7: goto L_80058254; break;
        case 8: goto L_80058254; break;
        case 9: goto L_80058254; break;
        case 10: goto L_80058254; break;
        case 11: goto L_80058254; break;
        case 12: goto L_80058254; break;
        case 13: goto L_80058254; break;
        case 14: goto L_80058254; break;
        case 15: goto L_80058254; break;
        case 16: goto L_80057A90; break;
        case 17: goto L_80058254; break;
        case 18: goto L_80058254; break;
        case 19: goto L_80058254; break;
        case 20: goto L_80058254; break;
        case 21: goto L_80058254; break;
        case 22: goto L_80058254; break;
        case 23: goto L_80058254; break;
        case 24: goto L_80058254; break;
        case 25: goto L_80058254; break;
        case 26: goto L_80058254; break;
        case 27: goto L_80058254; break;
        case 28: goto L_80058254; break;
        case 29: goto L_80058254; break;
        case 30: goto L_80058254; break;
        case 31: goto L_80058254; break;
        case 32: goto L_80057E3C; break;
        case 33: goto L_80058254; break;
        case 34: goto L_80058254; break;
        case 35: goto L_80058254; break;
        case 36: goto L_80058254; break;
        case 37: goto L_80058254; break;
        case 38: goto L_80058254; break;
        case 39: goto L_80058254; break;
        case 40: goto L_80058254; break;
        case 41: goto L_80058254; break;
        case 42: goto L_80058254; break;
        case 43: goto L_80058254; break;
        case 44: goto L_80058254; break;
        case 45: goto L_80058254; break;
        case 46: goto L_80058254; break;
        case 47: goto L_80058254; break;
        case 48: goto L_80057F1C; break;
        case 49: goto L_80058254; break;
        case 50: goto L_80058254; break;
        case 51: goto L_80058254; break;
        case 52: goto L_80058254; break;
        case 53: goto L_80058254; break;
        case 54: goto L_80058254; break;
        case 55: goto L_80058254; break;
        case 56: goto L_80058254; break;
        case 57: goto L_80058254; break;
        case 58: goto L_80058254; break;
        case 59: goto L_80058254; break;
        case 60: goto L_80058254; break;
        case 61: goto L_80058254; break;
        case 62: goto L_80058254; break;
        case 63: goto L_80058254; break;
        case 64: goto L_80058188; break;
        case 65: goto L_80058254; break;
        case 66: goto L_80058254; break;
        case 67: goto L_80058254; break;
        case 68: goto L_80058254; break;
        case 69: goto L_80058254; break;
        case 70: goto L_80058254; break;
        case 71: goto L_80058254; break;
        case 72: goto L_80058254; break;
        case 73: goto L_80058254; break;
        case 74: goto L_80058254; break;
        case 75: goto L_80058254; break;
        case 76: goto L_80058254; break;
        case 77: goto L_80058254; break;
        case 78: goto L_80058254; break;
        case 79: goto L_80058254; break;
        case 80: goto L_80057EA4; break;
        case 81: goto L_80058254; break;
        case 82: goto L_80058254; break;
        case 83: goto L_80058254; break;
        case 84: goto L_80058254; break;
        case 85: goto L_80058254; break;
        case 86: goto L_80058254; break;
        case 87: goto L_80058254; break;
        case 88: goto L_80058254; break;
        case 89: goto L_80058254; break;
        case 90: goto L_80058254; break;
        case 91: goto L_80058254; break;
        case 92: goto L_80058254; break;
        case 93: goto L_80058254; break;
        case 94: goto L_80058254; break;
        case 95: goto L_80058254; break;
        case 96: goto L_800581BC; break;
        default: switch_error(__func__, 0x80057A88, 0x80079440);
    }
    // 0x80057A8C: nop

L_80057A90:
    // 0x80057A90: beql        $s4, $zero, L_80057DE8
    if (ctx->r20 == 0) {
        // 0x80057A94: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80057DE8;
    }
    goto skip_0;
    // 0x80057A94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x80057A98: lw          $t8, 0x2C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X2C);
    // 0x80057A9C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80057AA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80057AA4: bne         $t8, $at, L_80058254
    if (ctx->r24 != ctx->r1) {
        // 0x80057AA8: andi        $a1, $s3, 0xFF
        ctx->r5 = ctx->r19 & 0XFF;
            goto L_80058254;
    }
    // 0x80057AA8: andi        $a1, $s3, 0xFF
    ctx->r5 = ctx->r19 & 0XFF;
    // 0x80057AAC: andi        $a2, $s4, 0xFF
    ctx->r6 = ctx->r20 & 0XFF;
    // 0x80057AB0: jal         0x80057950
    // 0x80057AB4: andi        $a3, $s6, 0xFF
    ctx->r7 = ctx->r22 & 0XFF;
    func_80057950(rdram, ctx);
        goto after_0;
    // 0x80057AB4: andi        $a3, $s6, 0xFF
    ctx->r7 = ctx->r22 & 0XFF;
    after_0:
    // 0x80057AB8: beq         $v0, $zero, L_80058254
    if (ctx->r2 == 0) {
        // 0x80057ABC: or          $s7, $v0, $zero
        ctx->r23 = ctx->r2 | 0;
            goto L_80058254;
    }
    // 0x80057ABC: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x80057AC0: lw          $t9, 0x60($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X60);
    // 0x80057AC4: sll         $fp, $s6, 4
    ctx->r30 = S32(ctx->r22 << 4);
    // 0x80057AC8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80057ACC: addu        $t6, $t9, $fp
    ctx->r14 = ADD32(ctx->r25, ctx->r30);
    // 0x80057AD0: lbu         $t7, 0x8($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X8);
    // 0x80057AD4: sh          $zero, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = 0;
    // 0x80057AD8: sb          $zero, 0xA0($sp)
    MEM_B(0XA0, ctx->r29) = 0;
    // 0x80057ADC: andi        $a1, $s3, 0xFF
    ctx->r5 = ctx->r19 & 0XFF;
    // 0x80057AE0: andi        $a2, $s4, 0xFF
    ctx->r6 = ctx->r20 & 0XFF;
    // 0x80057AE4: andi        $a3, $s6, 0xFF
    ctx->r7 = ctx->r22 & 0XFF;
    // 0x80057AE8: jal         0x800578E0
    // 0x80057AEC: sh          $t7, 0x9C($sp)
    MEM_H(0X9C, ctx->r29) = ctx->r15;
    func_800578E0(rdram, ctx);
        goto after_1;
    // 0x80057AEC: sh          $t7, 0x9C($sp)
    MEM_H(0X9C, ctx->r29) = ctx->r15;
    after_1:
    // 0x80057AF0: beq         $v0, $zero, L_80058254
    if (ctx->r2 == 0) {
        // 0x80057AF4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80058254;
    }
    // 0x80057AF4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80057AF8: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x80057AFC: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x80057B00: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80057B04: jal         0x80058F28
    // 0x80057B08: addiu       $a2, $sp, 0x9C
    ctx->r6 = ADD32(ctx->r29, 0X9C);
    func_80058F28(rdram, ctx);
        goto after_2;
    // 0x80057B08: addiu       $a2, $sp, 0x9C
    ctx->r6 = ADD32(ctx->r29, 0X9C);
    after_2:
    // 0x80057B0C: sw          $s7, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r23;
    // 0x80057B10: sb          $zero, 0x34($s0)
    MEM_B(0X34, ctx->r16) = 0;
    // 0x80057B14: lw          $t8, 0x60($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X60);
    // 0x80057B18: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x80057B1C: addu        $t9, $t8, $fp
    ctx->r25 = ADD32(ctx->r24, ctx->r30);
    // 0x80057B20: lbu         $t6, 0xB($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0XB);
    // 0x80057B24: slti        $at, $t6, 0x40
    ctx->r1 = SIGNED(ctx->r14) < 0X40 ? 1 : 0;
    // 0x80057B28: bnel        $at, $zero, L_80057B3C
    if (ctx->r1 != 0) {
        // 0x80057B2C: sb          $zero, 0x35($s0)
        MEM_B(0X35, ctx->r16) = 0;
            goto L_80057B3C;
    }
    goto skip_1;
    // 0x80057B2C: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
    skip_1:
    // 0x80057B30: b           L_80057B3C
    // 0x80057B34: sb          $s5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r21;
        goto L_80057B3C;
    // 0x80057B34: sb          $s5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r21;
    // 0x80057B38: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
L_80057B3C:
    // 0x80057B3C: lw          $v0, 0x4($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X4);
    // 0x80057B40: lbu         $t7, 0x4($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4);
    // 0x80057B44: lb          $t6, 0x5($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X5);
    // 0x80057B48: subu        $t8, $s3, $t7
    ctx->r24 = SUB32(ctx->r19, ctx->r15);
    // 0x80057B4C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80057B50: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80057B54: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80057B58: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80057B5C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80057B60: addu        $a0, $t9, $t6
    ctx->r4 = ADD32(ctx->r25, ctx->r14);
    // 0x80057B64: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x80057B68: jal         0x80053FD0
    // 0x80057B6C: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    func_80053FD0(rdram, ctx);
        goto after_3;
    // 0x80057B6C: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    after_3:
    // 0x80057B70: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x80057B74: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x80057B78: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80057B7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80057B80: lbu         $t6, 0xC($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0XC);
    // 0x80057B84: sb          $t6, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r14;
    // 0x80057B88: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x80057B8C: lw          $t7, 0x1C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X1C);
    // 0x80057B90: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80057B94: sb          $zero, 0x37($s0)
    MEM_B(0X37, ctx->r16) = 0;
    // 0x80057B98: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x80057B9C: sw          $t6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r14;
    // 0x80057BA0: lw          $t8, 0x60($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X60);
    // 0x80057BA4: addu        $t7, $t8, $fp
    ctx->r15 = ADD32(ctx->r24, ctx->r30);
    // 0x80057BA8: lw          $s2, 0x0($t7)
    ctx->r18 = MEM_W(ctx->r15, 0X0);
    // 0x80057BAC: swc1        $f4, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f4.u32l;
    // 0x80057BB0: lbu         $a2, 0x4($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X4);
    // 0x80057BB4: beql        $a2, $zero, L_80057C20
    if (ctx->r6 == 0) {
        // 0x80057BB8: cfc1        $t8, $FpcCsr
        ctx->r24 = get_cop1_cs();
            goto L_80057C20;
    }
    goto skip_2;
    // 0x80057BB8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    skip_2:
    // 0x80057BBC: lw          $v0, 0x70($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X70);
    // 0x80057BC0: beql        $v0, $zero, L_80057C20
    if (ctx->r2 == 0) {
        // 0x80057BC4: cfc1        $t8, $FpcCsr
        ctx->r24 = get_cop1_cs();
            goto L_80057C20;
    }
    goto skip_3;
    // 0x80057BC4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    skip_3:
    // 0x80057BC8: lbu         $t9, 0x6($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X6);
    // 0x80057BCC: lbu         $a3, 0x5($s2)
    ctx->r7 = MEM_BU(ctx->r18, 0X5);
    // 0x80057BD0: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x80057BD4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80057BD8: lbu         $t6, 0x7($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X7);
    // 0x80057BDC: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x80057BE0: jalr        $v0
    // 0x80057BE4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_4;
    // 0x80057BE4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_4:
    // 0x80057BE8: beq         $v0, $zero, L_80057C1C
    if (ctx->r2 == 0) {
        // 0x80057BEC: addiu       $t8, $zero, 0x16
        ctx->r24 = ADD32(0, 0X16);
            goto L_80057C1C;
    }
    // 0x80057BEC: addiu       $t8, $zero, 0x16
    ctx->r24 = ADD32(0, 0X16);
    // 0x80057BF0: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x80057BF4: sh          $t8, 0xB4($sp)
    MEM_H(0XB4, ctx->r29) = ctx->r24;
    // 0x80057BF8: sw          $s0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r16;
    // 0x80057BFC: addiu       $a0, $s1, 0x48
    ctx->r4 = ADD32(ctx->r17, 0X48);
    // 0x80057C00: addiu       $a1, $sp, 0xB4
    ctx->r5 = ADD32(ctx->r29, 0XB4);
    // 0x80057C04: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80057C08: jal         0x8005702C
    // 0x80057C0C: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    func_8005702C(rdram, ctx);
        goto after_5;
    // 0x80057C0C: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    after_5:
    // 0x80057C10: lbu         $t9, 0x37($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X37);
    // 0x80057C14: ori         $t6, $t9, 0x1
    ctx->r14 = ctx->r25 | 0X1;
    // 0x80057C18: sb          $t6, 0x37($s0)
    MEM_B(0X37, ctx->r16) = ctx->r14;
L_80057C1C:
    // 0x80057C1C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
L_80057C20:
    // 0x80057C20: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80057C24: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80057C28: lwc1        $f6, 0x8C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80057C2C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80057C30: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80057C34: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80057C38: nop

    // 0x80057C3C: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80057C40: beql        $t7, $zero, L_80057C90
    if (ctx->r15 == 0) {
        // 0x80057C44: mfc1        $t7, $f8
        ctx->r15 = (int32_t)ctx->f8.u32l;
            goto L_80057C90;
    }
    goto skip_4;
    // 0x80057C44: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    skip_4:
    // 0x80057C48: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80057C4C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80057C50: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80057C54: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80057C58: nop

    // 0x80057C5C: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80057C60: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80057C64: nop

    // 0x80057C68: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80057C6C: bne         $t7, $zero, L_80057C84
    if (ctx->r15 != 0) {
        // 0x80057C70: nop
    
            goto L_80057C84;
    }
    // 0x80057C70: nop

    // 0x80057C74: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x80057C78: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80057C7C: b           L_80057C9C
    // 0x80057C80: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80057C9C;
    // 0x80057C80: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80057C84:
    // 0x80057C84: b           L_80057C9C
    // 0x80057C88: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80057C9C;
    // 0x80057C88: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80057C8C: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
L_80057C90:
    // 0x80057C90: nop

    // 0x80057C94: bltz        $t7, L_80057C84
    if (SIGNED(ctx->r15) < 0) {
        // 0x80057C98: nop
    
            goto L_80057C84;
    }
    // 0x80057C98: nop

L_80057C9C:
    // 0x80057C9C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80057CA0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80057CA4: sb          $t7, 0x36($s0)
    MEM_B(0X36, ctx->r16) = ctx->r15;
    // 0x80057CA8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80057CAC: swc1        $f10, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f10.u32l;
    // 0x80057CB0: lbu         $a2, 0x8($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X8);
    // 0x80057CB4: addiu       $s5, $s1, 0x48
    ctx->r21 = ADD32(ctx->r17, 0X48);
    // 0x80057CB8: beql        $a2, $zero, L_80057D28
    if (ctx->r6 == 0) {
        // 0x80057CBC: lwc1        $f4, 0x8C($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
            goto L_80057D28;
    }
    goto skip_5;
    // 0x80057CBC: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
    skip_5:
    // 0x80057CC0: lw          $v0, 0x70($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X70);
    // 0x80057CC4: beql        $v0, $zero, L_80057D28
    if (ctx->r2 == 0) {
        // 0x80057CC8: lwc1        $f4, 0x8C($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
            goto L_80057D28;
    }
    goto skip_6;
    // 0x80057CC8: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
    skip_6:
    // 0x80057CCC: lbu         $t9, 0xA($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0XA);
    // 0x80057CD0: lbu         $a3, 0x9($s2)
    ctx->r7 = MEM_BU(ctx->r18, 0X9);
    // 0x80057CD4: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x80057CD8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80057CDC: lbu         $t6, 0xB($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0XB);
    // 0x80057CE0: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x80057CE4: jalr        $v0
    // 0x80057CE8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_6;
    // 0x80057CE8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_6:
    // 0x80057CEC: beq         $v0, $zero, L_80057D24
    if (ctx->r2 == 0) {
        // 0x80057CF0: addiu       $t8, $zero, 0x17
        ctx->r24 = ADD32(0, 0X17);
            goto L_80057D24;
    }
    // 0x80057CF0: addiu       $t8, $zero, 0x17
    ctx->r24 = ADD32(0, 0X17);
    // 0x80057CF4: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x80057CF8: sh          $t8, 0xB4($sp)
    MEM_H(0XB4, ctx->r29) = ctx->r24;
    // 0x80057CFC: sw          $s0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r16;
    // 0x80057D00: sb          $s6, 0xC0($sp)
    MEM_B(0XC0, ctx->r29) = ctx->r22;
    // 0x80057D04: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80057D08: addiu       $a1, $sp, 0xB4
    ctx->r5 = ADD32(ctx->r29, 0XB4);
    // 0x80057D0C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80057D10: jal         0x8005702C
    // 0x80057D14: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    func_8005702C(rdram, ctx);
        goto after_7;
    // 0x80057D14: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    after_7:
    // 0x80057D18: lbu         $t9, 0x37($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X37);
    // 0x80057D1C: ori         $t6, $t9, 0x2
    ctx->r14 = ctx->r25 | 0X2;
    // 0x80057D20: sb          $t6, 0x37($s0)
    MEM_B(0X37, ctx->r16) = ctx->r14;
L_80057D24:
    // 0x80057D24: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
L_80057D28:
    // 0x80057D28: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80057D2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80057D30: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    // 0x80057D34: lw          $t8, 0x60($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X60);
    // 0x80057D38: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80057D3C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80057D40: addu        $v0, $t8, $fp
    ctx->r2 = ADD32(ctx->r24, ctx->r30);
    // 0x80057D44: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80057D48: lbu         $s2, 0xA($v0)
    ctx->r18 = MEM_BU(ctx->r2, 0XA);
    // 0x80057D4C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80057D50: nop

    // 0x80057D54: mul.s       $f20, $f10, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80057D58: jal         0x80057824
    // 0x80057D5C: nop

    func_80057824(rdram, ctx);
        goto after_8;
    // 0x80057D5C: nop

    after_8:
    // 0x80057D60: andi        $s4, $v0, 0xFF
    ctx->r20 = ctx->r2 & 0XFF;
    // 0x80057D64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80057D68: jal         0x80057404
    // 0x80057D6C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80057404(rdram, ctx);
        goto after_9;
    // 0x80057D6C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_9:
    // 0x80057D70: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x80057D74: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x80057D78: lw          $a2, 0x8($s7)
    ctx->r6 = MEM_W(ctx->r23, 0X8);
    // 0x80057D7C: lw          $s3, 0x0($t7)
    ctx->r19 = MEM_W(ctx->r15, 0X0);
    // 0x80057D80: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80057D84: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80057D88: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x80057D8C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80057D90: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80057D94: jal         0x80059070
    // 0x80057D98: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    func_80059070(rdram, ctx);
        goto after_10;
    // 0x80057D98: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    after_10:
    // 0x80057D9C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80057DA0: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x80057DA4: sh          $t9, 0xB4($sp)
    MEM_H(0XB4, ctx->r29) = ctx->r25;
    // 0x80057DA8: sw          $t6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r14;
    // 0x80057DAC: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x80057DB0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80057DB4: addiu       $a1, $sp, 0xB4
    ctx->r5 = ADD32(ctx->r29, 0XB4);
    // 0x80057DB8: lbu         $t7, 0xD($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0XD);
    // 0x80057DBC: sb          $t7, 0xC0($sp)
    MEM_B(0XC0, ctx->r29) = ctx->r15;
    // 0x80057DC0: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x80057DC4: lw          $t6, 0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X4);
    // 0x80057DC8: sw          $t6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r14;
    // 0x80057DCC: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x80057DD0: lw          $s3, 0x0($t8)
    ctx->r19 = MEM_W(ctx->r24, 0X0);
    // 0x80057DD4: jal         0x8005702C
    // 0x80057DD8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_8005702C(rdram, ctx);
        goto after_11;
    // 0x80057DD8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_11:
    // 0x80057DDC: b           L_80058258
    // 0x80057DE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80058258;
    // 0x80057DE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80057DE4:
    // 0x80057DE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80057DE8:
    // 0x80057DE8: andi        $a1, $s3, 0xFF
    ctx->r5 = ctx->r19 & 0XFF;
    // 0x80057DEC: jal         0x8005786C
    // 0x80057DF0: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    func_8005786C(rdram, ctx);
        goto after_12;
    // 0x80057DF0: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    after_12:
    // 0x80057DF4: beq         $v0, $zero, L_80058254
    if (ctx->r2 == 0) {
        // 0x80057DF8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80058254;
    }
    // 0x80057DF8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80057DFC: lbu         $t7, 0x35($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X35);
    // 0x80057E00: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x80057E04: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80057E08: bne         $s6, $t7, L_80057E18
    if (ctx->r22 != ctx->r15) {
        // 0x80057E0C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80057E18;
    }
    // 0x80057E0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80057E10: b           L_80058254
    // 0x80057E14: sb          $t9, 0x35($v0)
    MEM_B(0X35, ctx->r2) = ctx->r25;
        goto L_80058254;
    // 0x80057E14: sb          $t9, 0x35($v0)
    MEM_B(0X35, ctx->r2) = ctx->r25;
L_80057E18:
    // 0x80057E18: lw          $t6, 0x20($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20);
    // 0x80057E1C: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
    // 0x80057E20: sb          $fp, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r30;
    // 0x80057E24: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80057E28: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80057E2C: jal         0x8005748C
    // 0x80057E30: lw          $a2, 0x8($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X8);
    func_8005748C(rdram, ctx);
        goto after_13;
    // 0x80057E30: lw          $a2, 0x8($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X8);
    after_13:
    // 0x80057E34: b           L_80058258
    // 0x80057E38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80058258;
    // 0x80057E38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80057E3C:
    // 0x80057E3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80057E40: andi        $a1, $s3, 0xFF
    ctx->r5 = ctx->r19 & 0XFF;
    // 0x80057E44: jal         0x8005786C
    // 0x80057E48: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    func_8005786C(rdram, ctx);
        goto after_14;
    // 0x80057E48: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    after_14:
    // 0x80057E4C: beq         $v0, $zero, L_80058254
    if (ctx->r2 == 0) {
        // 0x80057E50: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80058254;
    }
    // 0x80057E50: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80057E54: sb          $s4, 0x33($v0)
    MEM_B(0X33, ctx->r2) = ctx->r20;
    // 0x80057E58: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80057E5C: jal         0x80057404
    // 0x80057E60: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80057404(rdram, ctx);
        goto after_15;
    // 0x80057E60: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_15:
    // 0x80057E64: lw          $v1, 0x1C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X1C);
    // 0x80057E68: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x80057E6C: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x80057E70: sra         $t7, $a2, 16
    ctx->r15 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80057E74: subu        $a0, $t9, $v1
    ctx->r4 = SUB32(ctx->r25, ctx->r3);
    // 0x80057E78: bltz        $a0, L_80057E88
    if (SIGNED(ctx->r4) < 0) {
        // 0x80057E7C: or          $a2, $t7, $zero
        ctx->r6 = ctx->r15 | 0;
            goto L_80057E88;
    }
    // 0x80057E7C: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x80057E80: b           L_80057E8C
    // 0x80057E84: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_80057E8C;
    // 0x80057E84: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80057E88:
    // 0x80057E88: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
L_80057E8C:
    // 0x80057E8C: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x80057E90: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80057E94: jal         0x80058D10
    // 0x80057E98: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_80058D10(rdram, ctx);
        goto after_16;
    // 0x80057E98: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_16:
    // 0x80057E9C: b           L_80058258
    // 0x80057EA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80058258;
    // 0x80057EA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80057EA4:
    // 0x80057EA4: lw          $s0, 0x64($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X64);
    // 0x80057EA8: beql        $s0, $zero, L_80058258
    if (ctx->r16 == 0) {
        // 0x80057EAC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80058258;
    }
    goto skip_7;
    // 0x80057EAC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_7:
    // 0x80057EB0: or          $s2, $s6, $zero
    ctx->r18 = ctx->r22 | 0;
    // 0x80057EB4: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
L_80057EB8:
    // 0x80057EB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80057EBC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80057EC0: bnel        $s2, $t6, L_80057F0C
    if (ctx->r18 != ctx->r14) {
        // 0x80057EC4: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80057F0C;
    }
    goto skip_8;
    // 0x80057EC4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_8:
    // 0x80057EC8: jal         0x80057404
    // 0x80057ECC: sb          $s3, 0x33($s0)
    MEM_B(0X33, ctx->r16) = ctx->r19;
    func_80057404(rdram, ctx);
        goto after_17;
    // 0x80057ECC: sb          $s3, 0x33($s0)
    MEM_B(0X33, ctx->r16) = ctx->r19;
    after_17:
    // 0x80057ED0: lw          $v1, 0x1C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X1C);
    // 0x80057ED4: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x80057ED8: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x80057EDC: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80057EE0: subu        $a0, $t7, $v1
    ctx->r4 = SUB32(ctx->r15, ctx->r3);
    // 0x80057EE4: bltz        $a0, L_80057EF4
    if (SIGNED(ctx->r4) < 0) {
        // 0x80057EE8: or          $a2, $t8, $zero
        ctx->r6 = ctx->r24 | 0;
            goto L_80057EF4;
    }
    // 0x80057EE8: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80057EEC: b           L_80057EF8
    // 0x80057EF0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_80057EF8;
    // 0x80057EF0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80057EF4:
    // 0x80057EF4: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
L_80057EF8:
    // 0x80057EF8: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x80057EFC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80057F00: jal         0x80058D10
    // 0x80057F04: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_80058D10(rdram, ctx);
        goto after_18;
    // 0x80057F04: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_18:
    // 0x80057F08: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_80057F0C:
    // 0x80057F0C: bnel        $s0, $zero, L_80057EB8
    if (ctx->r16 != 0) {
        // 0x80057F10: lbu         $t6, 0x31($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X31);
            goto L_80057EB8;
    }
    goto skip_9;
    // 0x80057F10: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
    skip_9:
    // 0x80057F14: b           L_80058258
    // 0x80057F18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80058258;
    // 0x80057F18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80057F1C:
    // 0x80057F1C: slti        $at, $s3, 0x41
    ctx->r1 = SIGNED(ctx->r19) < 0X41 ? 1 : 0;
    // 0x80057F20: bne         $at, $zero, L_80057F44
    if (ctx->r1 != 0) {
        // 0x80057F24: or          $v0, $s3, $zero
        ctx->r2 = ctx->r19 | 0;
            goto L_80057F44;
    }
    // 0x80057F24: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x80057F28: addiu       $at, $zero, 0x5B
    ctx->r1 = ADD32(0, 0X5B);
    // 0x80057F2C: beq         $v0, $at, L_80058138
    if (ctx->r2 == ctx->r1) {
        // 0x80057F30: addiu       $at, $zero, 0x5D
        ctx->r1 = ADD32(0, 0X5D);
            goto L_80058138;
    }
    // 0x80057F30: addiu       $at, $zero, 0x5D
    ctx->r1 = ADD32(0, 0X5D);
    // 0x80057F34: beql        $v0, $at, L_80058258
    if (ctx->r2 == ctx->r1) {
        // 0x80057F38: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80058258;
    }
    goto skip_10;
    // 0x80057F38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_10:
    // 0x80057F3C: b           L_80058258
    // 0x80057F40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80058258;
    // 0x80057F40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80057F44:
    // 0x80057F44: slti        $at, $v0, 0x1C
    ctx->r1 = SIGNED(ctx->r2) < 0X1C ? 1 : 0;
    // 0x80057F48: bne         $at, $zero, L_80057F64
    if (ctx->r1 != 0) {
        // 0x80057F4C: addiu       $t9, $v0, -0x7
        ctx->r25 = ADD32(ctx->r2, -0X7);
            goto L_80057F64;
    }
    // 0x80057F4C: addiu       $t9, $v0, -0x7
    ctx->r25 = ADD32(ctx->r2, -0X7);
    // 0x80057F50: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80057F54: beql        $v0, $at, L_8005808C
    if (ctx->r2 == ctx->r1) {
        // 0x80057F58: lw          $t7, 0x60($s1)
        ctx->r15 = MEM_W(ctx->r17, 0X60);
            goto L_8005808C;
    }
    goto skip_11;
    // 0x80057F58: lw          $t7, 0x60($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X60);
    skip_11:
    // 0x80057F5C: b           L_80058258
    // 0x80057F60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80058258;
    // 0x80057F60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80057F64:
    // 0x80057F64: sltiu       $at, $t9, 0x15
    ctx->r1 = ctx->r25 < 0X15 ? 1 : 0;
    // 0x80057F68: beq         $at, $zero, L_80058254
    if (ctx->r1 == 0) {
        // 0x80057F6C: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80058254;
    }
    // 0x80057F6C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80057F70: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80057F74: addu        $at, $at, $t9
    gpr jr_addend_80057F7C = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80057F78: lw          $t9, -0x6A3C($at)
    ctx->r25 = ADD32(ctx->r1, -0X6A3C);
    // 0x80057F7C: jr          $t9
    // 0x80057F80: nop

    switch (jr_addend_80057F7C >> 2) {
        case 0: goto L_80057FE0; break;
        case 1: goto L_80058254; break;
        case 2: goto L_80058254; break;
        case 3: goto L_80057F84; break;
        case 4: goto L_80058254; break;
        case 5: goto L_80058254; break;
        case 6: goto L_80058254; break;
        case 7: goto L_80058254; break;
        case 8: goto L_80058254; break;
        case 9: goto L_80058074; break;
        case 10: goto L_80058254; break;
        case 11: goto L_80058254; break;
        case 12: goto L_80058254; break;
        case 13: goto L_80058254; break;
        case 14: goto L_80058254; break;
        case 15: goto L_80058254; break;
        case 16: goto L_80058254; break;
        case 17: goto L_80058254; break;
        case 18: goto L_80058254; break;
        case 19: goto L_80058254; break;
        case 20: goto L_80058254; break;
        default: switch_error(__func__, 0x80057F7C, 0x800795C4);
    }
    // 0x80057F80: nop

L_80057F84:
    // 0x80057F84: lw          $t6, 0x60($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X60);
    // 0x80057F88: sll         $t8, $s6, 4
    ctx->r24 = S32(ctx->r22 << 4);
    // 0x80057F8C: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x80057F90: sb          $s4, 0x7($t7)
    MEM_B(0X7, ctx->r15) = ctx->r20;
    // 0x80057F94: lw          $s0, 0x64($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X64);
    // 0x80057F98: beql        $s0, $zero, L_80058258
    if (ctx->r16 == 0) {
        // 0x80057F9C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80058258;
    }
    goto skip_12;
    // 0x80057F9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_12:
    // 0x80057FA0: or          $s2, $s6, $zero
    ctx->r18 = ctx->r22 | 0;
    // 0x80057FA4: lbu         $t9, 0x31($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X31);
L_80057FA8:
    // 0x80057FA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80057FAC: bnel        $s2, $t9, L_80057FD0
    if (ctx->r18 != ctx->r25) {
        // 0x80057FB0: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80057FD0;
    }
    goto skip_13;
    // 0x80057FB0: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_13:
    // 0x80057FB4: jal         0x80057824
    // 0x80057FB8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80057824(rdram, ctx);
        goto after_19;
    // 0x80057FB8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_19:
    // 0x80057FBC: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x80057FC0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80057FC4: jal         0x80059160
    // 0x80057FC8: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    func_80059160(rdram, ctx);
        goto after_20;
    // 0x80057FC8: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    after_20:
    // 0x80057FCC: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_80057FD0:
    // 0x80057FD0: bnel        $s0, $zero, L_80057FA8
    if (ctx->r16 != 0) {
        // 0x80057FD4: lbu         $t9, 0x31($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X31);
            goto L_80057FA8;
    }
    goto skip_14;
    // 0x80057FD4: lbu         $t9, 0x31($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X31);
    skip_14:
    // 0x80057FD8: b           L_80058258
    // 0x80057FDC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80058258;
    // 0x80057FDC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80057FE0:
    // 0x80057FE0: lw          $t6, 0x60($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X60);
    // 0x80057FE4: sll         $t8, $s6, 4
    ctx->r24 = S32(ctx->r22 << 4);
    // 0x80057FE8: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x80057FEC: sb          $s4, 0x9($t7)
    MEM_B(0X9, ctx->r15) = ctx->r20;
    // 0x80057FF0: lw          $s0, 0x64($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X64);
    // 0x80057FF4: beql        $s0, $zero, L_80058258
    if (ctx->r16 == 0) {
        // 0x80057FF8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80058258;
    }
    goto skip_15;
    // 0x80057FF8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_15:
    // 0x80057FFC: or          $s2, $s6, $zero
    ctx->r18 = ctx->r22 | 0;
    // 0x80058000: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
    // 0x80058004: lbu         $t9, 0x31($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X31);
L_80058008:
    // 0x80058008: bnel        $s2, $t9, L_80058064
    if (ctx->r18 != ctx->r25) {
        // 0x8005800C: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80058064;
    }
    goto skip_16;
    // 0x8005800C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_16:
    // 0x80058010: lbu         $t6, 0x34($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X34);
    // 0x80058014: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80058018: beql        $s3, $t6, L_80058064
    if (ctx->r19 == ctx->r14) {
        // 0x8005801C: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80058064;
    }
    goto skip_17;
    // 0x8005801C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_17:
    // 0x80058020: jal         0x80057404
    // 0x80058024: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80057404(rdram, ctx);
        goto after_21;
    // 0x80058024: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_21:
    // 0x80058028: lw          $v1, 0x1C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X1C);
    // 0x8005802C: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x80058030: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x80058034: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80058038: subu        $a0, $t7, $v1
    ctx->r4 = SUB32(ctx->r15, ctx->r3);
    // 0x8005803C: bltz        $a0, L_8005804C
    if (SIGNED(ctx->r4) < 0) {
        // 0x80058040: or          $a2, $t8, $zero
        ctx->r6 = ctx->r24 | 0;
            goto L_8005804C;
    }
    // 0x80058040: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80058044: b           L_80058050
    // 0x80058048: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_80058050;
    // 0x80058048: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8005804C:
    // 0x8005804C: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
L_80058050:
    // 0x80058050: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x80058054: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80058058: jal         0x80058D10
    // 0x8005805C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_80058D10(rdram, ctx);
        goto after_22;
    // 0x8005805C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_22:
    // 0x80058060: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_80058064:
    // 0x80058064: bnel        $s0, $zero, L_80058008
    if (ctx->r16 != 0) {
        // 0x80058068: lbu         $t9, 0x31($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X31);
            goto L_80058008;
    }
    goto skip_18;
    // 0x80058068: lbu         $t9, 0x31($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X31);
    skip_18:
    // 0x8005806C: b           L_80058258
    // 0x80058070: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80058258;
    // 0x80058070: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80058074:
    // 0x80058074: lw          $t9, 0x60($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X60);
    // 0x80058078: sll         $t6, $s6, 4
    ctx->r14 = S32(ctx->r22 << 4);
    // 0x8005807C: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x80058080: b           L_80058254
    // 0x80058084: sb          $s4, 0x8($t8)
    MEM_B(0X8, ctx->r24) = ctx->r20;
        goto L_80058254;
    // 0x80058084: sb          $s4, 0x8($t8)
    MEM_B(0X8, ctx->r24) = ctx->r20;
    // 0x80058088: lw          $t7, 0x60($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X60);
L_8005808C:
    // 0x8005808C: sll         $t9, $s6, 4
    ctx->r25 = S32(ctx->r22 << 4);
    // 0x80058090: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x80058094: sb          $s4, 0xB($t6)
    MEM_B(0XB, ctx->r14) = ctx->r20;
    // 0x80058098: lw          $s0, 0x64($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X64);
    // 0x8005809C: beql        $s0, $zero, L_80058258
    if (ctx->r16 == 0) {
        // 0x800580A0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80058258;
    }
    goto skip_19;
    // 0x800580A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_19:
    // 0x800580A4: or          $s2, $s6, $zero
    ctx->r18 = ctx->r22 | 0;
    // 0x800580A8: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x800580AC: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
    // 0x800580B0: addiu       $s7, $zero, 0x4
    ctx->r23 = ADD32(0, 0X4);
    // 0x800580B4: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x800580B8: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
    // 0x800580BC: lbu         $t8, 0x31($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X31);
L_800580C0:
    // 0x800580C0: bnel        $s2, $t8, L_80058128
    if (ctx->r18 != ctx->r24) {
        // 0x800580C4: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80058128;
    }
    goto skip_20;
    // 0x800580C4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_20:
    // 0x800580C8: lbu         $v0, 0x35($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X35);
    // 0x800580CC: slti        $at, $s4, 0x40
    ctx->r1 = SIGNED(ctx->r20) < 0X40 ? 1 : 0;
    // 0x800580D0: beql        $s3, $v0, L_80058128
    if (ctx->r19 == ctx->r2) {
        // 0x800580D4: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80058128;
    }
    goto skip_21;
    // 0x800580D4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_21:
    // 0x800580D8: bne         $at, $zero, L_800580F0
    if (ctx->r1 != 0) {
        // 0x800580DC: nop
    
            goto L_800580F0;
    }
    // 0x800580DC: nop

    // 0x800580E0: bnel        $v0, $zero, L_80058128
    if (ctx->r2 != 0) {
        // 0x800580E4: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80058128;
    }
    goto skip_22;
    // 0x800580E4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_22:
    // 0x800580E8: b           L_80058124
    // 0x800580EC: sb          $s5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r21;
        goto L_80058124;
    // 0x800580EC: sb          $s5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r21;
L_800580F0:
    // 0x800580F0: bne         $s6, $v0, L_80058100
    if (ctx->r22 != ctx->r2) {
        // 0x800580F4: nop
    
            goto L_80058100;
    }
    // 0x800580F4: nop

    // 0x800580F8: b           L_80058124
    // 0x800580FC: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
        goto L_80058124;
    // 0x800580FC: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
L_80058100:
    // 0x80058100: bnel        $s7, $v0, L_80058128
    if (ctx->r23 != ctx->r2) {
        // 0x80058104: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80058128;
    }
    goto skip_23;
    // 0x80058104: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_23:
    // 0x80058108: lw          $t7, 0x20($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X20);
    // 0x8005810C: sb          $fp, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r30;
    // 0x80058110: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80058114: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80058118: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8005811C: jal         0x8005748C
    // 0x80058120: lw          $a2, 0x8($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X8);
    func_8005748C(rdram, ctx);
        goto after_23;
    // 0x80058120: lw          $a2, 0x8($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X8);
    after_23:
L_80058124:
    // 0x80058124: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_80058128:
    // 0x80058128: bnel        $s0, $zero, L_800580C0
    if (ctx->r16 != 0) {
        // 0x8005812C: lbu         $t8, 0x31($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X31);
            goto L_800580C0;
    }
    goto skip_24;
    // 0x8005812C: lbu         $t8, 0x31($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X31);
    skip_24:
    // 0x80058130: b           L_80058258
    // 0x80058134: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80058258;
    // 0x80058134: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80058138:
    // 0x80058138: lw          $t6, 0x60($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X60);
    // 0x8005813C: sll         $t8, $s6, 4
    ctx->r24 = S32(ctx->r22 << 4);
    // 0x80058140: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x80058144: sb          $s4, 0xA($t7)
    MEM_B(0XA, ctx->r15) = ctx->r20;
    // 0x80058148: lw          $s0, 0x64($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X64);
    // 0x8005814C: beql        $s0, $zero, L_80058258
    if (ctx->r16 == 0) {
        // 0x80058150: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80058258;
    }
    goto skip_25;
    // 0x80058150: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_25:
    // 0x80058154: or          $s2, $s6, $zero
    ctx->r18 = ctx->r22 | 0;
    // 0x80058158: lbu         $t9, 0x31($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X31);
L_8005815C:
    // 0x8005815C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80058160: andi        $a2, $s4, 0xFF
    ctx->r6 = ctx->r20 & 0XFF;
    // 0x80058164: bnel        $s2, $t9, L_80058178
    if (ctx->r18 != ctx->r25) {
        // 0x80058168: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80058178;
    }
    goto skip_26;
    // 0x80058168: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_26:
    // 0x8005816C: jal         0x800591F0
    // 0x80058170: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    func_800591F0(rdram, ctx);
        goto after_24;
    // 0x80058170: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    after_24:
    // 0x80058174: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_80058178:
    // 0x80058178: bnel        $s0, $zero, L_8005815C
    if (ctx->r16 != 0) {
        // 0x8005817C: lbu         $t9, 0x31($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X31);
            goto L_8005815C;
    }
    goto skip_27;
    // 0x8005817C: lbu         $t9, 0x31($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X31);
    skip_27:
    // 0x80058180: b           L_80058258
    // 0x80058184: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80058258;
    // 0x80058184: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80058188:
    // 0x80058188: lw          $v0, 0x20($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X20);
    // 0x8005818C: sll         $t8, $s3, 2
    ctx->r24 = S32(ctx->r19 << 2);
    // 0x80058190: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80058194: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x80058198: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x8005819C: addu        $t7, $v0, $t8
    ctx->r15 = ADD32(ctx->r2, ctx->r24);
    // 0x800581A0: slt         $at, $s3, $t6
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800581A4: beql        $at, $zero, L_80058258
    if (ctx->r1 == 0) {
        // 0x800581A8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80058258;
    }
    goto skip_28;
    // 0x800581A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_28:
    // 0x800581AC: jal         0x80057250
    // 0x800581B0: lw          $a1, 0xC($t7)
    ctx->r5 = MEM_W(ctx->r15, 0XC);
    func_80057250(rdram, ctx);
        goto after_25;
    // 0x800581B0: lw          $a1, 0xC($t7)
    ctx->r5 = MEM_W(ctx->r15, 0XC);
    after_25:
    // 0x800581B4: b           L_80058258
    // 0x800581B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80058258;
    // 0x800581B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800581BC:
    // 0x800581BC: lw          $t9, 0x60($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X60);
    // 0x800581C0: sll         $fp, $s6, 4
    ctx->r30 = S32(ctx->r22 << 4);
    // 0x800581C4: sll         $t7, $s4, 7
    ctx->r15 = S32(ctx->r20 << 7);
    // 0x800581C8: addu        $t6, $t9, $fp
    ctx->r14 = ADD32(ctx->r25, ctx->r30);
    // 0x800581CC: lh          $t8, 0x4($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X4);
    // 0x800581D0: addu        $t9, $t7, $s3
    ctx->r25 = ADD32(ctx->r15, ctx->r19);
    // 0x800581D4: addiu       $t6, $t9, -0x2000
    ctx->r14 = ADD32(ctx->r25, -0X2000);
    // 0x800581D8: multu       $t8, $t6
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800581DC: mflo        $a0
    ctx->r4 = lo;
    // 0x800581E0: bgez        $a0, L_800581F0
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800581E4: sra         $t7, $a0, 13
        ctx->r15 = S32(SIGNED(ctx->r4) >> 13);
            goto L_800581F0;
    }
    // 0x800581E4: sra         $t7, $a0, 13
    ctx->r15 = S32(SIGNED(ctx->r4) >> 13);
    // 0x800581E8: addiu       $at, $a0, 0x1FFF
    ctx->r1 = ADD32(ctx->r4, 0X1FFF);
    // 0x800581EC: sra         $t7, $at, 13
    ctx->r15 = S32(SIGNED(ctx->r1) >> 13);
L_800581F0:
    // 0x800581F0: jal         0x80053FD0
    // 0x800581F4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_80053FD0(rdram, ctx);
        goto after_26;
    // 0x800581F4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_26:
    // 0x800581F8: lw          $t9, 0x60($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X60);
    // 0x800581FC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80058200: addu        $t8, $t9, $fp
    ctx->r24 = ADD32(ctx->r25, ctx->r30);
    // 0x80058204: swc1        $f0, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f0.u32l;
    // 0x80058208: lw          $s0, 0x64($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X64);
    // 0x8005820C: beql        $s0, $zero, L_80058258
    if (ctx->r16 == 0) {
        // 0x80058210: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80058258;
    }
    goto skip_29;
    // 0x80058210: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_29:
    // 0x80058214: or          $s2, $s6, $zero
    ctx->r18 = ctx->r22 | 0;
    // 0x80058218: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
L_8005821C:
    // 0x8005821C: bnel        $s2, $t6, L_8005824C
    if (ctx->r18 != ctx->r14) {
        // 0x80058220: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_8005824C;
    }
    goto skip_30;
    // 0x80058220: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_30:
    // 0x80058224: lwc1        $f6, 0x28($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80058228: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005822C: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x80058230: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80058234: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80058238: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8005823C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80058240: jal         0x80058DB0
    // 0x80058244: nop

    func_80058DB0(rdram, ctx);
        goto after_27;
    // 0x80058244: nop

    after_27:
    // 0x80058248: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_8005824C:
    // 0x8005824C: bnel        $s0, $zero, L_8005821C
    if (ctx->r16 != 0) {
        // 0x80058250: lbu         $t6, 0x31($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X31);
            goto L_8005821C;
    }
    goto skip_31;
    // 0x80058250: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
    skip_31:
L_80058254:
    // 0x80058254: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80058258:
    // 0x80058258: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    // 0x8005825C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80058264(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80058264: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005826C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005826C: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x80058270: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80058274: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80058278: addiu       $t6, $a0, 0x38
    ctx->r14 = ADD32(ctx->r4, 0X38);
    // 0x8005827C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80058280: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80058284: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80058288: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8005828C: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80058290: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80058294: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80058298: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8005829C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800582A0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800582A4: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
    // 0x800582A8: addiu       $s5, $a0, 0x48
    ctx->r21 = ADD32(ctx->r4, 0X48);
L_800582AC:
    // 0x800582AC: lhu         $t7, 0x38($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0X38);
    // 0x800582B0: sltiu       $at, $t7, 0x18
    ctx->r1 = ctx->r15 < 0X18 ? 1 : 0;
    // 0x800582B4: beq         $at, $zero, L_8005883C
    if (ctx->r1 == 0) {
        // 0x800582B8: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8005883C;
    }
    // 0x800582B8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800582BC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800582C0: addu        $at, $at, $t7
    gpr jr_addend_800582C8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800582C4: lw          $t7, -0x69E8($at)
    ctx->r15 = ADD32(ctx->r1, -0X69E8);
    // 0x800582C8: jr          $t7
    // 0x800582CC: nop

    switch (jr_addend_800582C8 >> 2) {
        case 0: goto L_800582D0; break;
        case 1: goto L_8005883C; break;
        case 2: goto L_800585E4; break;
        case 3: goto L_8005883C; break;
        case 4: goto L_8005883C; break;
        case 5: goto L_8005839C; break;
        case 6: goto L_800583E8; break;
        case 7: goto L_80058604; break;
        case 8: goto L_8005883C; break;
        case 9: goto L_8005837C; break;
        case 10: goto L_8005873C; break;
        case 11: goto L_800587A4; break;
        case 12: goto L_800587C0; break;
        case 13: goto L_800587DC; break;
        case 14: goto L_8005882C; break;
        case 15: goto L_80058618; break;
        case 16: goto L_8005863C; break;
        case 17: goto L_800586AC; break;
        case 18: goto L_8005883C; break;
        case 19: goto L_8005883C; break;
        case 20: goto L_8005883C; break;
        case 21: goto L_8005883C; break;
        case 22: goto L_8005844C; break;
        case 23: goto L_8005855C; break;
        default: switch_error(__func__, 0x800582C8, 0x80079618);
    }
    // 0x800582CC: nop

L_800582D0:
    // 0x800582D0: lw          $a0, 0x18($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X18);
    // 0x800582D4: beql        $a0, $zero, L_80058840
    if (ctx->r4 == 0) {
        // 0x800582D8: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80058840;
    }
    goto skip_0;
    // 0x800582D8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_0:
    // 0x800582DC: jal         0x80060FA4
    // 0x800582E0: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    func_80060FA4(rdram, ctx);
        goto after_0;
    // 0x800582E0: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    after_0:
    // 0x800582E4: lh          $v0, 0x88($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X88);
    // 0x800582E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800582EC: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    // 0x800582F0: beq         $v0, $at, L_80058318
    if (ctx->r2 == ctx->r1) {
        // 0x800582F4: addiu       $a0, $sp, 0x88
        ctx->r4 = ADD32(ctx->r29, 0X88);
            goto L_80058318;
    }
    // 0x800582F4: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x800582F8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800582FC: beq         $v0, $at, L_8005833C
    if (ctx->r2 == ctx->r1) {
        // 0x80058300: or          $a1, $s2, $zero
        ctx->r5 = ctx->r18 | 0;
            goto L_8005833C;
    }
    // 0x80058300: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80058304: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80058308: beq         $v0, $at, L_80058354
    if (ctx->r2 == ctx->r1) {
        // 0x8005830C: addiu       $t8, $zero, 0x2
        ctx->r24 = ADD32(0, 0X2);
            goto L_80058354;
    }
    // 0x8005830C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80058310: b           L_80058840
    // 0x80058314: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80058840;
    // 0x80058314: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80058318:
    // 0x80058318: sw          $s2, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r18;
    // 0x8005831C: jal         0x80057A4C
    // 0x80058320: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    func_80057A4C(rdram, ctx);
        goto after_1;
    // 0x80058320: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    after_1:
    // 0x80058324: lw          $s2, 0xD0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XD0);
    // 0x80058328: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x8005832C: jal         0x800576D0
    // 0x80058330: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800576D0(rdram, ctx);
        goto after_2;
    // 0x80058330: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x80058334: b           L_80058840
    // 0x80058338: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80058840;
    // 0x80058338: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_8005833C:
    // 0x8005833C: jal         0x800577AC
    // 0x80058340: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    func_800577AC(rdram, ctx);
        goto after_3;
    // 0x80058340: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    after_3:
    // 0x80058344: jal         0x800576D0
    // 0x80058348: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800576D0(rdram, ctx);
        goto after_4;
    // 0x80058348: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x8005834C: b           L_80058840
    // 0x80058350: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80058840;
    // 0x80058350: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80058354:
    // 0x80058354: sw          $t8, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r24;
    // 0x80058358: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x8005835C: lui         $a2, 0x7FFF
    ctx->r6 = S32(0X7FFF << 16);
    // 0x80058360: sh          $t9, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r25;
    // 0x80058364: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x80058368: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8005836C: jal         0x8005702C
    // 0x80058370: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    func_8005702C(rdram, ctx);
        goto after_5;
    // 0x80058370: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    after_5:
    // 0x80058374: b           L_80058840
    // 0x80058378: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80058840;
    // 0x80058378: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_8005837C:
    // 0x8005837C: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x80058380: sh          $t6, 0xBC($sp)
    MEM_H(0XBC, ctx->r29) = ctx->r14;
    // 0x80058384: lw          $a2, 0x5C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X5C);
    // 0x80058388: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8005838C: jal         0x8005702C
    // 0x80058390: addiu       $a1, $sp, 0xBC
    ctx->r5 = ADD32(ctx->r29, 0XBC);
    func_8005702C(rdram, ctx);
        goto after_6;
    // 0x80058390: addiu       $a1, $sp, 0xBC
    ctx->r5 = ADD32(ctx->r29, 0XBC);
    after_6:
    // 0x80058394: b           L_80058840
    // 0x80058398: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80058840;
    // 0x80058398: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_8005839C:
    // 0x8005839C: lw          $s0, 0x3C($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X3C);
    // 0x800583A0: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800583A4: jal         0x80058BE0
    // 0x800583A8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80058BE0(rdram, ctx);
        goto after_7;
    // 0x800583A8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x800583AC: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800583B0: jal         0x80058C60
    // 0x800583B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80058C60(rdram, ctx);
        goto after_8;
    // 0x800583B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x800583B8: lw          $s1, 0x10($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X10);
    // 0x800583BC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800583C0: lbu         $t7, 0x37($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X37);
    // 0x800583C4: beql        $t7, $zero, L_800583D8
    if (ctx->r15 == 0) {
        // 0x800583C8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800583D8;
    }
    goto skip_1;
    // 0x800583C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_1:
    // 0x800583CC: jal         0x80058890
    // 0x800583D0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80058890(rdram, ctx);
        goto after_9;
    // 0x800583D0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_9:
    // 0x800583D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800583D8:
    // 0x800583D8: jal         0x80057660
    // 0x800583DC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80057660(rdram, ctx);
        goto after_10;
    // 0x800583DC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_10:
    // 0x800583E0: b           L_80058840
    // 0x800583E4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80058840;
    // 0x800583E4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800583E8:
    // 0x800583E8: lw          $s0, 0x3C($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X3C);
    // 0x800583EC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800583F0: lw          $s1, 0x10($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X10);
    // 0x800583F4: lbu         $t8, 0x34($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X34);
    // 0x800583F8: bnel        $t8, $zero, L_80058408
    if (ctx->r24 != 0) {
        // 0x800583FC: lbu         $t6, 0x44($s2)
        ctx->r14 = MEM_BU(ctx->r18, 0X44);
            goto L_80058408;
    }
    goto skip_2;
    // 0x800583FC: lbu         $t6, 0x44($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X44);
    skip_2:
    // 0x80058400: sb          $t9, 0x34($s1)
    MEM_B(0X34, ctx->r17) = ctx->r25;
    // 0x80058404: lbu         $t6, 0x44($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X44);
L_80058408:
    // 0x80058408: lw          $s3, 0x40($s2)
    ctx->r19 = MEM_W(ctx->r18, 0X40);
    // 0x8005840C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80058410: sb          $t6, 0x30($s1)
    MEM_B(0X30, ctx->r17) = ctx->r14;
    // 0x80058414: lw          $t7, 0x1C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X1C);
    // 0x80058418: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8005841C: addu        $t8, $t7, $s3
    ctx->r24 = ADD32(ctx->r15, ctx->r19);
    // 0x80058420: jal         0x80057404
    // 0x80058424: sw          $t8, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r24;
    func_80057404(rdram, ctx);
        goto after_11;
    // 0x80058424: sw          $t8, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r24;
    after_11:
    // 0x80058428: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x8005842C: sra         $t9, $a2, 16
    ctx->r25 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80058430: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x80058434: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80058438: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8005843C: jal         0x80058D10
    // 0x80058440: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    func_80058D10(rdram, ctx);
        goto after_12;
    // 0x80058440: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_12:
    // 0x80058444: b           L_80058840
    // 0x80058448: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80058840;
    // 0x80058448: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_8005844C:
    // 0x8005844C: lw          $t9, 0x74($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X74);
    // 0x80058450: lw          $s4, 0x40($s2)
    ctx->r20 = MEM_W(ctx->r18, 0X40);
    // 0x80058454: lw          $s1, 0x3C($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X3C);
    // 0x80058458: addiu       $a1, $sp, 0xA8
    ctx->r5 = ADD32(ctx->r29, 0XA8);
    // 0x8005845C: jalr        $t9
    // 0x80058460: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_13;
    // 0x80058460: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_13:
    // 0x80058464: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80058468: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005846C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80058470: lwc1        $f4, 0xA8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80058474: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80058478: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8005847C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80058480: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80058484: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80058488: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8005848C: nop

    // 0x80058490: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80058494: beql        $t7, $zero, L_800584E4
    if (ctx->r15 == 0) {
        // 0x80058498: mfc1        $t7, $f6
        ctx->r15 = (int32_t)ctx->f6.u32l;
            goto L_800584E4;
    }
    goto skip_3;
    // 0x80058498: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    skip_3:
    // 0x8005849C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800584A0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800584A4: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800584A8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800584AC: nop

    // 0x800584B0: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800584B4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800584B8: nop

    // 0x800584BC: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800584C0: bne         $t7, $zero, L_800584D8
    if (ctx->r15 != 0) {
        // 0x800584C4: nop
    
            goto L_800584D8;
    }
    // 0x800584C4: nop

    // 0x800584C8: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800584CC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800584D0: b           L_800584F0
    // 0x800584D4: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_800584F0;
    // 0x800584D4: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_800584D8:
    // 0x800584D8: b           L_800584F0
    // 0x800584DC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_800584F0;
    // 0x800584DC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800584E0: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
L_800584E4:
    // 0x800584E4: nop

    // 0x800584E8: bltz        $t7, L_800584D8
    if (SIGNED(ctx->r15) < 0) {
        // 0x800584EC: nop
    
            goto L_800584D8;
    }
    // 0x800584EC: nop

L_800584F0:
    // 0x800584F0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800584F4: jal         0x80057404
    // 0x800584F8: sb          $t7, 0x36($s1)
    MEM_B(0X36, ctx->r17) = ctx->r15;
    func_80057404(rdram, ctx);
        goto after_14;
    // 0x800584F8: sb          $t7, 0x36($s1)
    MEM_B(0X36, ctx->r17) = ctx->r15;
    after_14:
    // 0x800584FC: lw          $v1, 0x1C($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X1C);
    // 0x80058500: lw          $t9, 0x24($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X24);
    // 0x80058504: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x80058508: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8005850C: subu        $a0, $t9, $v1
    ctx->r4 = SUB32(ctx->r25, ctx->r3);
    // 0x80058510: bltz        $a0, L_80058520
    if (SIGNED(ctx->r4) < 0) {
        // 0x80058514: or          $a2, $t8, $zero
        ctx->r6 = ctx->r24 | 0;
            goto L_80058520;
    }
    // 0x80058514: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80058518: b           L_80058524
    // 0x8005851C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_80058524;
    // 0x8005851C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80058520:
    // 0x80058520: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
L_80058524:
    // 0x80058524: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80058528: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x8005852C: jal         0x80058D10
    // 0x80058530: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_80058D10(rdram, ctx);
        goto after_15;
    // 0x80058530: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_15:
    // 0x80058534: addiu       $t6, $zero, 0x16
    ctx->r14 = ADD32(0, 0X16);
    // 0x80058538: sh          $t6, 0xBC($sp)
    MEM_H(0XBC, ctx->r29) = ctx->r14;
    // 0x8005853C: sw          $s1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r17;
    // 0x80058540: sw          $s4, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r20;
    // 0x80058544: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80058548: addiu       $a1, $sp, 0xBC
    ctx->r5 = ADD32(ctx->r29, 0XBC);
    // 0x8005854C: jal         0x8005702C
    // 0x80058550: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_8005702C(rdram, ctx);
        goto after_16;
    // 0x80058550: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_16:
    // 0x80058554: b           L_80058840
    // 0x80058558: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80058840;
    // 0x80058558: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_8005855C:
    // 0x8005855C: lw          $t9, 0x74($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X74);
    // 0x80058560: lw          $s4, 0x40($s2)
    ctx->r20 = MEM_W(ctx->r18, 0X40);
    // 0x80058564: lw          $s1, 0x3C($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X3C);
    // 0x80058568: lbu         $s0, 0x44($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0X44);
    // 0x8005856C: addiu       $a1, $sp, 0xA8
    ctx->r5 = ADD32(ctx->r29, 0XA8);
    // 0x80058570: jalr        $t9
    // 0x80058574: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_17;
    // 0x80058574: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_17:
    // 0x80058578: lwc1        $f8, 0xA8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8005857C: lwc1        $f4, 0x28($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80058580: sll         $t8, $s0, 4
    ctx->r24 = S32(ctx->r16 << 4);
    // 0x80058584: swc1        $f8, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f8.u32l;
    // 0x80058588: lwc1        $f6, 0x2C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x8005858C: lw          $t7, 0x60($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X60);
    // 0x80058590: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80058594: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80058598: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x8005859C: lwc1        $f10, 0xC($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0XC);
    // 0x800585A0: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800585A4: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x800585A8: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800585AC: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800585B0: jal         0x80058DB0
    // 0x800585B4: nop

    func_80058DB0(rdram, ctx);
        goto after_18;
    // 0x800585B4: nop

    after_18:
    // 0x800585B8: addiu       $t9, $zero, 0x17
    ctx->r25 = ADD32(0, 0X17);
    // 0x800585BC: sh          $t9, 0xBC($sp)
    MEM_H(0XBC, ctx->r29) = ctx->r25;
    // 0x800585C0: sw          $s1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r17;
    // 0x800585C4: sw          $s4, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r20;
    // 0x800585C8: sb          $s0, 0xC8($sp)
    MEM_B(0XC8, ctx->r29) = ctx->r16;
    // 0x800585CC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800585D0: addiu       $a1, $sp, 0xBC
    ctx->r5 = ADD32(ctx->r29, 0XBC);
    // 0x800585D4: jal         0x8005702C
    // 0x800585D8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_8005702C(rdram, ctx);
        goto after_19;
    // 0x800585D8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_19:
    // 0x800585DC: b           L_80058840
    // 0x800585E0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80058840;
    // 0x800585E0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800585E4:
    // 0x800585E4: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    // 0x800585E8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800585EC: sw          $s2, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r18;
    // 0x800585F0: jal         0x80057A4C
    // 0x800585F4: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    func_80057A4C(rdram, ctx);
        goto after_20;
    // 0x800585F4: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    after_20:
    // 0x800585F8: lw          $s2, 0xD0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XD0);
    // 0x800585FC: b           L_8005883C
    // 0x80058600: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
        goto L_8005883C;
    // 0x80058600: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
L_80058604:
    // 0x80058604: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80058608: jal         0x800577AC
    // 0x8005860C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_800577AC(rdram, ctx);
        goto after_21;
    // 0x8005860C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_21:
    // 0x80058610: b           L_80058840
    // 0x80058614: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80058840;
    // 0x80058614: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80058618:
    // 0x80058618: lw          $t7, 0x2C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X2C);
    // 0x8005861C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80058620: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80058624: beq         $t7, $at, L_8005883C
    if (ctx->r15 == ctx->r1) {
        // 0x80058628: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8005883C;
    }
    // 0x80058628: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8005862C: jal         0x800576D0
    // 0x80058630: sw          $t8, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r24;
    func_800576D0(rdram, ctx);
        goto after_22;
    // 0x80058630: sw          $t8, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r24;
    after_22:
    // 0x80058634: b           L_80058840
    // 0x80058638: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80058840;
    // 0x80058638: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_8005863C:
    // 0x8005863C: lw          $t6, 0x2C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X2C);
    // 0x80058640: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80058644: bnel        $t6, $at, L_80058840
    if (ctx->r14 != ctx->r1) {
        // 0x80058648: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80058840;
    }
    goto skip_4;
    // 0x80058648: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_4:
    // 0x8005864C: lw          $s1, 0x64($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X64);
    // 0x80058650: beq         $s1, $zero, L_800586A0
    if (ctx->r17 == 0) {
        // 0x80058654: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_800586A0;
    }
    // 0x80058654: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
L_80058658:
    // 0x80058658: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8005865C: jal         0x80058BE0
    // 0x80058660: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    func_80058BE0(rdram, ctx);
        goto after_23;
    // 0x80058660: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    after_23:
    // 0x80058664: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80058668: jal         0x80058C60
    // 0x8005866C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80058C60(rdram, ctx);
        goto after_24;
    // 0x8005866C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_24:
    // 0x80058670: lbu         $t9, 0x37($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X37);
    // 0x80058674: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80058678: beql        $t9, $zero, L_8005868C
    if (ctx->r25 == 0) {
        // 0x8005867C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8005868C;
    }
    goto skip_5;
    // 0x8005867C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_5:
    // 0x80058680: jal         0x80058890
    // 0x80058684: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80058890(rdram, ctx);
        goto after_25;
    // 0x80058684: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_25:
    // 0x80058688: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8005868C:
    // 0x8005868C: jal         0x80057660
    // 0x80058690: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80057660(rdram, ctx);
        goto after_26;
    // 0x80058690: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_26:
    // 0x80058694: lw          $s1, 0x64($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X64);
    // 0x80058698: bnel        $s1, $zero, L_80058658
    if (ctx->r17 != 0) {
        // 0x8005869C: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_80058658;
    }
    goto skip_6;
    // 0x8005869C: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    skip_6:
L_800586A0:
    // 0x800586A0: sw          $zero, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = 0;
    // 0x800586A4: b           L_8005883C
    // 0x800586A8: sw          $zero, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = 0;
        goto L_8005883C;
    // 0x800586A8: sw          $zero, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = 0;
L_800586AC:
    // 0x800586AC: lw          $t7, 0x2C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X2C);
    // 0x800586B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800586B4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800586B8: bnel        $t7, $at, L_80058840
    if (ctx->r15 != ctx->r1) {
        // 0x800586BC: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80058840;
    }
    goto skip_7;
    // 0x800586BC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_7:
    // 0x800586C0: jal         0x80056F10
    // 0x800586C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056F10(rdram, ctx);
        goto after_27;
    // 0x800586C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_27:
    // 0x800586C8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800586CC: jal         0x80056F10
    // 0x800586D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80056F10(rdram, ctx);
        goto after_28;
    // 0x800586D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_28:
    // 0x800586D4: lw          $s1, 0x64($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X64);
    // 0x800586D8: beq         $s1, $zero, L_80058710
    if (ctx->r17 == 0) {
        // 0x800586DC: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_80058710;
    }
    // 0x800586DC: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
L_800586E0:
    // 0x800586E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800586E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800586E8: jal         0x800575B8
    // 0x800586EC: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    func_800575B8(rdram, ctx);
        goto after_29;
    // 0x800586EC: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    after_29:
    // 0x800586F0: beq         $v0, $zero, L_80058704
    if (ctx->r2 == 0) {
        // 0x800586F4: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80058704;
    }
    // 0x800586F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800586F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800586FC: jal         0x8005748C
    // 0x80058700: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    func_8005748C(rdram, ctx);
        goto after_30;
    // 0x80058700: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    after_30:
L_80058704:
    // 0x80058704: lw          $s1, 0x0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X0);
    // 0x80058708: bnel        $s1, $zero, L_800586E0
    if (ctx->r17 != 0) {
        // 0x8005870C: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_800586E0;
    }
    goto skip_8;
    // 0x8005870C: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    skip_8:
L_80058710:
    // 0x80058710: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80058714: sw          $t8, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r24;
    // 0x80058718: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x8005871C: lui         $a2, 0x7FFF
    ctx->r6 = S32(0X7FFF << 16);
    // 0x80058720: sh          $t6, 0xBC($sp)
    MEM_H(0XBC, ctx->r29) = ctx->r14;
    // 0x80058724: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x80058728: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8005872C: jal         0x8005702C
    // 0x80058730: addiu       $a1, $sp, 0xBC
    ctx->r5 = ADD32(ctx->r29, 0XBC);
    func_8005702C(rdram, ctx);
        goto after_31;
    // 0x80058730: addiu       $a1, $sp, 0xBC
    ctx->r5 = ADD32(ctx->r29, 0XBC);
    after_31:
    // 0x80058734: b           L_80058840
    // 0x80058738: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80058840;
    // 0x80058738: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_8005873C:
    // 0x8005873C: lw          $s1, 0x64($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X64);
    // 0x80058740: lh          $t9, 0x3C($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X3C);
    // 0x80058744: beq         $s1, $zero, L_8005883C
    if (ctx->r17 == 0) {
        // 0x80058748: sh          $t9, 0x32($s2)
        MEM_H(0X32, ctx->r18) = ctx->r25;
            goto L_8005883C;
    }
    // 0x80058748: sh          $t9, 0x32($s2)
    MEM_H(0X32, ctx->r18) = ctx->r25;
    // 0x8005874C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80058750:
    // 0x80058750: jal         0x80057404
    // 0x80058754: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80057404(rdram, ctx);
        goto after_32;
    // 0x80058754: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_32:
    // 0x80058758: lw          $v1, 0x1C($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X1C);
    // 0x8005875C: lw          $t8, 0x24($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X24);
    // 0x80058760: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x80058764: sra         $t7, $a2, 16
    ctx->r15 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80058768: subu        $a0, $t8, $v1
    ctx->r4 = SUB32(ctx->r24, ctx->r3);
    // 0x8005876C: bltz        $a0, L_8005877C
    if (SIGNED(ctx->r4) < 0) {
        // 0x80058770: or          $a2, $t7, $zero
        ctx->r6 = ctx->r15 | 0;
            goto L_8005877C;
    }
    // 0x80058770: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x80058774: b           L_80058780
    // 0x80058778: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_80058780;
    // 0x80058778: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8005877C:
    // 0x8005877C: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
L_80058780:
    // 0x80058780: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80058784: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x80058788: jal         0x80058D10
    // 0x8005878C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_80058D10(rdram, ctx);
        goto after_33;
    // 0x8005878C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_33:
    // 0x80058790: lw          $s1, 0x0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X0);
    // 0x80058794: bnel        $s1, $zero, L_80058750
    if (ctx->r17 != 0) {
        // 0x80058798: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80058750;
    }
    goto skip_9;
    // 0x80058798: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_9:
    // 0x8005879C: b           L_80058840
    // 0x800587A0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80058840;
    // 0x800587A0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800587A4:
    // 0x800587A4: lw          $t6, 0x3C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X3C);
    // 0x800587A8: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
    // 0x800587AC: lw          $t7, 0x44($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X44);
    // 0x800587B0: sw          $t6, 0x7C($s2)
    MEM_W(0X7C, ctx->r18) = ctx->r14;
    // 0x800587B4: sw          $t9, 0x80($s2)
    MEM_W(0X80, ctx->r18) = ctx->r25;
    // 0x800587B8: b           L_8005883C
    // 0x800587BC: sw          $t7, 0x84($s2)
    MEM_W(0X84, ctx->r18) = ctx->r15;
        goto L_8005883C;
    // 0x800587BC: sw          $t7, 0x84($s2)
    MEM_W(0X84, ctx->r18) = ctx->r15;
L_800587C0:
    // 0x800587C0: lbu         $s0, 0x3C($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0X3C);
    // 0x800587C4: lw          $t6, 0x60($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X60);
    // 0x800587C8: lbu         $t8, 0x3D($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X3D);
    // 0x800587CC: sll         $t9, $s0, 4
    ctx->r25 = S32(ctx->r16 << 4);
    // 0x800587D0: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x800587D4: b           L_8005883C
    // 0x800587D8: sb          $t8, 0x8($t7)
    MEM_B(0X8, ctx->r15) = ctx->r24;
        goto L_8005883C;
    // 0x800587D8: sb          $t8, 0x8($t7)
    MEM_B(0X8, ctx->r15) = ctx->r24;
L_800587DC:
    // 0x800587DC: lw          $a1, 0x3C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X3C);
    // 0x800587E0: addiu       $t7, $zero, 0x1E8
    ctx->r15 = ADD32(0, 0X1E8);
    // 0x800587E4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800587E8: beq         $a1, $zero, L_8005880C
    if (ctx->r5 == 0) {
        // 0x800587EC: sw          $a1, 0x18($s2)
        MEM_W(0X18, ctx->r18) = ctx->r5;
            goto L_8005880C;
    }
    // 0x800587EC: sw          $a1, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r5;
    // 0x800587F0: lwc1        $f6, -0x6988($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X6988);
    // 0x800587F4: lwc1        $f10, 0x14($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800587F8: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800587FC: trunc.w.s   $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80058800: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x80058804: b           L_80058810
    // 0x80058808: sw          $t8, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r24;
        goto L_80058810;
    // 0x80058808: sw          $t8, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r24;
L_8005880C:
    // 0x8005880C: sw          $t7, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r15;
L_80058810:
    // 0x80058810: lw          $a1, 0x20($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X20);
    // 0x80058814: beql        $a1, $zero, L_80058840
    if (ctx->r5 == 0) {
        // 0x80058818: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80058840;
    }
    goto skip_10;
    // 0x80058818: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_10:
    // 0x8005881C: jal         0x80057324
    // 0x80058820: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80057324(rdram, ctx);
        goto after_34;
    // 0x80058820: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_34:
    // 0x80058824: b           L_80058840
    // 0x80058828: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80058840;
    // 0x80058828: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_8005882C:
    // 0x8005882C: lw          $a1, 0x3C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X3C);
    // 0x80058830: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80058834: jal         0x80057324
    // 0x80058838: sw          $a1, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r5;
    func_80057324(rdram, ctx);
        goto after_35;
    // 0x80058838: sw          $a1, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r5;
    after_35:
L_8005883C:
    // 0x8005883C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80058840:
    // 0x80058840: jal         0x80057150
    // 0x80058844: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    func_80057150(rdram, ctx);
        goto after_36;
    // 0x80058844: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    after_36:
    // 0x80058848: beq         $v0, $zero, L_800582AC
    if (ctx->r2 == 0) {
        // 0x8005884C: sw          $v0, 0x28($s2)
        MEM_W(0X28, ctx->r18) = ctx->r2;
            goto L_800582AC;
    }
    // 0x8005884C: sw          $v0, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r2;
    // 0x80058850: lw          $t6, 0x1C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X1C);
    // 0x80058854: addu        $t9, $t6, $v0
    ctx->r25 = ADD32(ctx->r14, ctx->r2);
    // 0x80058858: sw          $t9, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r25;
    // 0x8005885C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80058860: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80058864: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80058868: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8005886C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80058870: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80058874: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80058878: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8005887C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80058880: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80058884: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80058888: jr          $ra
    // 0x8005888C: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    TRACE_RETURN()
    return;
    // 0x8005888C: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void func_80058890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80058890: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80058894: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80058898: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8005889C: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x800588A0: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800588A4: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800588A8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800588AC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800588B0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800588B4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800588B8: lw          $s0, 0x50($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X50);
    // 0x800588BC: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800588C0: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x800588C4: beq         $s0, $zero, L_80058968
    if (ctx->r16 == 0) {
        // 0x800588C8: addiu       $s7, $zero, 0x17
        ctx->r23 = ADD32(0, 0X17);
            goto L_80058968;
    }
    // 0x800588C8: addiu       $s7, $zero, 0x17
    ctx->r23 = ADD32(0, 0X17);
    // 0x800588CC: addiu       $s6, $zero, 0x16
    ctx->r22 = ADD32(0, 0X16);
L_800588D0:
    // 0x800588D0: lh          $s3, 0xC($s0)
    ctx->r19 = MEM_H(ctx->r16, 0XC);
    // 0x800588D4: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800588D8: beql        $s3, $s6, L_800588EC
    if (ctx->r19 == ctx->r22) {
        // 0x800588DC: lw          $t6, 0x10($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X10);
            goto L_800588EC;
    }
    goto skip_0;
    // 0x800588DC: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
    skip_0:
    // 0x800588E0: bne         $s3, $s7, L_80058960
    if (ctx->r19 != ctx->r23) {
        // 0x800588E4: nop
    
            goto L_80058960;
    }
    // 0x800588E4: nop

    // 0x800588E8: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
L_800588EC:
    // 0x800588EC: bne         $s2, $t6, L_80058960
    if (ctx->r18 != ctx->r14) {
        // 0x800588F0: nop
    
            goto L_80058960;
    }
    // 0x800588F0: nop

    // 0x800588F4: lw          $t9, 0x78($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X78);
    // 0x800588F8: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    // 0x800588FC: addiu       $s4, $s5, 0x48
    ctx->r20 = ADD32(ctx->r21, 0X48);
    // 0x80058900: jalr        $t9
    // 0x80058904: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80058904: nop

    after_0:
    // 0x80058908: jal         0x800526C0
    // 0x8005890C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800526C0(rdram, ctx);
        goto after_1;
    // 0x8005890C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80058910: beq         $s1, $zero, L_80058928
    if (ctx->r17 == 0) {
        // 0x80058914: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80058928;
    }
    // 0x80058914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80058918: lw          $t7, 0x8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8);
    // 0x8005891C: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80058920: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x80058924: sw          $t0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r8;
L_80058928:
    // 0x80058928: jal         0x800526F0
    // 0x8005892C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800526F0(rdram, ctx);
        goto after_2;
    // 0x8005892C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_2:
    // 0x80058930: bnel        $s3, $s6, L_8005894C
    if (ctx->r19 != ctx->r22) {
        // 0x80058934: lbu         $t3, 0x37($s2)
        ctx->r11 = MEM_BU(ctx->r18, 0X37);
            goto L_8005894C;
    }
    goto skip_1;
    // 0x80058934: lbu         $t3, 0x37($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X37);
    skip_1:
    // 0x80058938: lbu         $t1, 0x37($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X37);
    // 0x8005893C: andi        $t2, $t1, 0xFE
    ctx->r10 = ctx->r9 & 0XFE;
    // 0x80058940: b           L_80058954
    // 0x80058944: sb          $t2, 0x37($s2)
    MEM_B(0X37, ctx->r18) = ctx->r10;
        goto L_80058954;
    // 0x80058944: sb          $t2, 0x37($s2)
    MEM_B(0X37, ctx->r18) = ctx->r10;
    // 0x80058948: lbu         $t3, 0x37($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X37);
L_8005894C:
    // 0x8005894C: andi        $t4, $t3, 0xFD
    ctx->r12 = ctx->r11 & 0XFD;
    // 0x80058950: sb          $t4, 0x37($s2)
    MEM_B(0X37, ctx->r18) = ctx->r12;
L_80058954:
    // 0x80058954: lbu         $t5, 0x37($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X37);
    // 0x80058958: beql        $t5, $zero, L_8005896C
    if (ctx->r13 == 0) {
        // 0x8005895C: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8005896C;
    }
    goto skip_2;
    // 0x8005895C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_2:
L_80058960:
    // 0x80058960: bne         $s1, $zero, L_800588D0
    if (ctx->r17 != 0) {
        // 0x80058964: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800588D0;
    }
    // 0x80058964: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_80058968:
    // 0x80058968: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8005896C:
    // 0x8005896C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80058970: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80058974: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80058978: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8005897C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80058980: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80058984: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80058988: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8005898C: jr          $ra
    // 0x80058990: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    TRACE_RETURN()
    return;
    // 0x80058990: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80058994(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80058994: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80058998: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005899C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800589A0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800589A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800589A8: lbu         $t6, 0x34($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X34);
    // 0x800589AC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800589B0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800589B4: blez        $t6, L_800589EC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800589B8: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_800589EC;
    }
    // 0x800589B8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800589BC: lw          $t7, 0x60($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X60);
L_800589C0:
    // 0x800589C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800589C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800589C8: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x800589CC: jal         0x800572A4
    // 0x800589D0: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    func_800572A4(rdram, ctx);
        goto after_0;
    // 0x800589D0: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    after_0:
    // 0x800589D4: lbu         $t9, 0x34($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X34);
    // 0x800589D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800589DC: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x800589E0: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800589E4: bnel        $at, $zero, L_800589C0
    if (ctx->r1 != 0) {
        // 0x800589E8: lw          $t7, 0x60($s1)
        ctx->r15 = MEM_W(ctx->r17, 0X60);
            goto L_800589C0;
    }
    goto skip_0;
    // 0x800589E8: lw          $t7, 0x60($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X60);
    skip_0:
L_800589EC:
    // 0x800589EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800589F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800589F4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800589F8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800589FC: jr          $ra
    // 0x80058A00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    TRACE_RETURN()
    return;
    // 0x80058A00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80058A04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80058A04: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80058A08: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80058A0C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80058A10: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80058A14: lw          $a2, 0xC($a1)
    ctx->r6 = MEM_W(ctx->r5, 0XC);
    // 0x80058A18: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    // 0x80058A1C: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x80058A20: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x80058A24: lw          $t6, 0x3190($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3190);
    // 0x80058A28: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80058A2C: addiu       $t8, $zero, 0x1E8
    ctx->r24 = ADD32(0, 0X1E8);
    // 0x80058A30: addiu       $t9, $zero, 0x7FFF
    ctx->r25 = ADD32(0, 0X7FFF);
    // 0x80058A34: sh          $t7, 0x30($a0)
    MEM_H(0X30, ctx->r4) = ctx->r15;
    // 0x80058A38: sw          $t8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r24;
    // 0x80058A3C: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
    // 0x80058A40: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x80058A44: sh          $t9, 0x32($a0)
    MEM_H(0X32, ctx->r4) = ctx->r25;
    // 0x80058A48: sw          $t6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r14;
    // 0x80058A4C: lbu         $t0, 0x9($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X9);
    // 0x80058A50: addiu       $t1, $zero, 0x3E80
    ctx->r9 = ADD32(0, 0X3E80);
    // 0x80058A54: sw          $t1, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->r9;
    // 0x80058A58: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x80058A5C: sb          $t0, 0x35($a0)
    MEM_B(0X35, ctx->r4) = ctx->r8;
    // 0x80058A60: lw          $t2, 0x10($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X10);
    // 0x80058A64: addiu       $t5, $zero, 0x9
    ctx->r13 = ADD32(0, 0X9);
    // 0x80058A68: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80058A6C: sw          $t2, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->r10;
    // 0x80058A70: lw          $t3, 0x14($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X14);
    // 0x80058A74: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80058A78: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x80058A7C: sw          $t3, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->r11;
    // 0x80058A80: lw          $t4, 0x18($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X18);
    // 0x80058A84: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
    // 0x80058A88: sw          $zero, 0x80($a0)
    MEM_W(0X80, ctx->r4) = 0;
    // 0x80058A8C: sw          $zero, 0x84($a0)
    MEM_W(0X84, ctx->r4) = 0;
    // 0x80058A90: sh          $t5, 0x38($a0)
    MEM_H(0X38, ctx->r4) = ctx->r13;
    // 0x80058A94: sw          $t4, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r12;
    // 0x80058A98: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x80058A9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80058AA0: sb          $t6, 0x34($a0)
    MEM_B(0X34, ctx->r4) = ctx->r14;
    // 0x80058AA4: lbu         $a3, 0x8($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X8);
    // 0x80058AA8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80058AAC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80058AB0: jal         0x800507E0
    // 0x80058AB4: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_800507E0(rdram, ctx);
        goto after_0;
    // 0x80058AB4: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80058AB8: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    // 0x80058ABC: jal         0x80058994
    // 0x80058AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80058994(rdram, ctx);
        goto after_1;
    // 0x80058AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80058AC4: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80058AC8: addiu       $t8, $zero, 0x38
    ctx->r24 = ADD32(0, 0X38);
    // 0x80058ACC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80058AD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80058AD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80058AD8: jal         0x800507E0
    // 0x80058ADC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_800507E0(rdram, ctx);
        goto after_2;
    // 0x80058ADC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80058AE0: sw          $zero, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = 0;
    // 0x80058AE4: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80058AE8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80058AEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80058AF0: blez        $t9, L_80058B20
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80058AF4: addiu       $t2, $zero, 0x1C
        ctx->r10 = ADD32(0, 0X1C);
            goto L_80058B20;
    }
    // 0x80058AF4: addiu       $t2, $zero, 0x1C
    ctx->r10 = ADD32(0, 0X1C);
    // 0x80058AF8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80058AFC: lw          $t0, 0x6C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X6C);
L_80058B00:
    // 0x80058B00: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80058B04: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80058B08: sw          $v1, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->r3;
    // 0x80058B0C: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80058B10: addiu       $v1, $v1, 0x38
    ctx->r3 = ADD32(ctx->r3, 0X38);
    // 0x80058B14: slt         $at, $a0, $t1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80058B18: bnel        $at, $zero, L_80058B00
    if (ctx->r1 != 0) {
        // 0x80058B1C: lw          $t0, 0x6C($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X6C);
            goto L_80058B00;
    }
    goto skip_0;
    // 0x80058B1C: lw          $t0, 0x6C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X6C);
    skip_0:
L_80058B20:
    // 0x80058B20: sw          $zero, 0x64($s0)
    MEM_W(0X64, ctx->r16) = 0;
    // 0x80058B24: sw          $zero, 0x68($s0)
    MEM_W(0X68, ctx->r16) = 0;
    // 0x80058B28: lw          $a3, 0x4($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X4);
    // 0x80058B2C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80058B30: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80058B34: jal         0x800507E0
    // 0x80058B38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800507E0(rdram, ctx);
        goto after_3;
    // 0x80058B38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80058B3C: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x80058B40: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80058B44: jal         0x800571DC
    // 0x80058B48: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    func_800571DC(rdram, ctx);
        goto after_4;
    // 0x80058B48: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    after_4:
    // 0x80058B4C: lui         $t3, 0x8006
    ctx->r11 = S32(0X8006 << 16);
    // 0x80058B50: addiu       $t3, $t3, -0x7D94
    ctx->r11 = ADD32(ctx->r11, -0X7D94);
    // 0x80058B54: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80058B58: sw          $t3, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r11;
    // 0x80058B5C: sw          $s0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r16;
    // 0x80058B60: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80058B64: lw          $a0, 0x3190($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3190);
    // 0x80058B68: jal         0x80058B90
    // 0x80058B6C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80058B90(rdram, ctx);
        goto after_5;
    // 0x80058B6C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80058B70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80058B74: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80058B78: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80058B7C: jr          $ra
    // 0x80058B80: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    TRACE_RETURN()
    return;
    // 0x80058B80: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80058B90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80058B90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80058B94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80058B98: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80058B9C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80058BA0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80058BA4: jal         0x80059290
    // 0x80058BA8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80058BA8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80058BAC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80058BB0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80058BB4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80058BB8: lw          $t6, 0x20($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X20);
    // 0x80058BBC: sw          $t6, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r14;
    // 0x80058BC0: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80058BC4: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80058BC8: jal         0x80059290
    // 0x80058BCC: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x80058BCC: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
    after_1:
    // 0x80058BD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80058BD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80058BD8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80058BE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80058BE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80058BE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80058BE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80058BEC: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x80058BF0: beql        $t6, $zero, L_80058C4C
    if (ctx->r14 == 0) {
        // 0x80058BF4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80058C4C;
    }
    goto skip_0;
    // 0x80058BF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80058BF8: jal         0x800538F0
    // 0x80058BFC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800538F0(rdram, ctx);
        goto after_0;
    // 0x80058BFC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80058C00: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80058C04: beq         $v0, $zero, L_80058C48
    if (ctx->r2 == 0) {
        // 0x80058C08: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80058C48;
    }
    // 0x80058C08: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80058C0C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80058C10: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x80058C14: addiu       $t2, $zero, 0xF
    ctx->r10 = ADD32(0, 0XF);
    // 0x80058C18: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x80058C1C: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x80058C20: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x80058C24: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80058C28: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80058C2C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80058C30: lw          $t3, 0x8($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X8);
    // 0x80058C34: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80058C38: lw          $a0, 0xC($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC);
    // 0x80058C3C: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x80058C40: jalr        $t9
    // 0x80058C44: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80058C44: nop

    after_1:
L_80058C48:
    // 0x80058C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80058C4C:
    // 0x80058C4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80058C50: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80058C60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80058C60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80058C64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80058C68: lw          $a2, 0x8($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X8);
    // 0x80058C6C: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x80058C70: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80058C74: beql        $a2, $zero, L_80058D04
    if (ctx->r6 == 0) {
        // 0x80058C78: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80058D04;
    }
    goto skip_0;
    // 0x80058C78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80058C7C: lw          $t6, 0xD8($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XD8);
    // 0x80058C80: beql        $t6, $zero, L_80058CEC
    if (ctx->r14 == 0) {
        // 0x80058C84: or          $a0, $t0, $zero
        ctx->r4 = ctx->r8 | 0;
            goto L_80058CEC;
    }
    goto skip_1;
    // 0x80058C84: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    skip_1:
    // 0x80058C88: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80058C8C: jal         0x800538F0
    // 0x80058C90: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800538F0(rdram, ctx);
        goto after_0;
    // 0x80058C90: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80058C94: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80058C98: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80058C9C: beq         $v0, $zero, L_80058D00
    if (ctx->r2 == 0) {
        // 0x80058CA0: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80058D00;
    }
    // 0x80058CA0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80058CA4: lw          $t8, 0x8($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X8);
    // 0x80058CA8: lw          $t7, 0x1C($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X1C);
    // 0x80058CAC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80058CB0: lw          $t9, 0xD8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XD8);
    // 0x80058CB4: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x80058CB8: addu        $t1, $t7, $t9
    ctx->r9 = ADD32(ctx->r15, ctx->r25);
    // 0x80058CBC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80058CC0: lw          $t2, 0x8($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X8);
    // 0x80058CC4: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x80058CC8: lw          $t3, 0x8($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X8);
    // 0x80058CCC: lw          $a0, 0xC($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC);
    // 0x80058CD0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x80058CD4: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x80058CD8: jalr        $t9
    // 0x80058CDC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80058CDC: nop

    after_1:
    // 0x80058CE0: b           L_80058CFC
    // 0x80058CE4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
        goto L_80058CFC;
    // 0x80058CE4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80058CE8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_80058CEC:
    // 0x80058CEC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80058CF0: jal         0x80053840
    // 0x80058CF4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_80053840(rdram, ctx);
        goto after_2;
    // 0x80058CF4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_2:
    // 0x80058CF8: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_80058CFC:
    // 0x80058CFC: sw          $zero, 0x8($a3)
    MEM_W(0X8, ctx->r7) = 0;
L_80058D00:
    // 0x80058D00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80058D04:
    // 0x80058D04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80058D08: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80058D10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80058D10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80058D14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80058D18: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80058D1C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80058D20: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80058D24: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x80058D28: beql        $t7, $zero, L_80058DA0
    if (ctx->r15 == 0) {
        // 0x80058D2C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80058DA0;
    }
    goto skip_0;
    // 0x80058D2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80058D30: jal         0x800538F0
    // 0x80058D34: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800538F0(rdram, ctx);
        goto after_0;
    // 0x80058D34: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80058D38: beq         $v0, $zero, L_80058D9C
    if (ctx->r2 == 0) {
        // 0x80058D3C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80058D9C;
    }
    // 0x80058D3C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80058D40: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80058D44: lw          $t8, 0x1C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1C);
    // 0x80058D48: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
    // 0x80058D4C: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x80058D50: lw          $t1, 0xD8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XD8);
    // 0x80058D54: sh          $t3, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r11;
    // 0x80058D58: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x80058D5C: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80058D60: lh          $t4, 0x2A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2A);
    // 0x80058D64: sw          $t4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r12;
    // 0x80058D68: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80058D6C: jal         0x800537E8
    // 0x80058D70: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800537E8(rdram, ctx);
        goto after_1;
    // 0x80058D70: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80058D74: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80058D78: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80058D7C: sw          $v0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r2;
    // 0x80058D80: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80058D84: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80058D88: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x80058D8C: lw          $a0, 0xC($t6)
    ctx->r4 = MEM_W(ctx->r14, 0XC);
    // 0x80058D90: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x80058D94: jalr        $t9
    // 0x80058D98: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80058D98: nop

    after_2:
L_80058D9C:
    // 0x80058D9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80058DA0:
    // 0x80058DA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80058DA4: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80058DB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80058DB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80058DB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80058DB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80058DBC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80058DC0: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x80058DC4: beql        $t6, $zero, L_80058E28
    if (ctx->r14 == 0) {
        // 0x80058DC8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80058E28;
    }
    goto skip_0;
    // 0x80058DC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80058DCC: jal         0x800538F0
    // 0x80058DD0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800538F0(rdram, ctx);
        goto after_0;
    // 0x80058DD0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80058DD4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80058DD8: beq         $v0, $zero, L_80058E24
    if (ctx->r2 == 0) {
        // 0x80058DDC: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80058E24;
    }
    // 0x80058DDC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80058DE0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80058DE4: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x80058DE8: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x80058DEC: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x80058DF0: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x80058DF4: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x80058DF8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80058DFC: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80058E00: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80058E04: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80058E08: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80058E0C: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x80058E10: lw          $t3, 0x8($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X8);
    // 0x80058E14: lw          $a0, 0xC($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC);
    // 0x80058E18: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x80058E1C: jalr        $t9
    // 0x80058E20: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80058E20: nop

    after_1:
L_80058E24:
    // 0x80058E24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80058E28:
    // 0x80058E28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80058E2C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80058E40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80058E40: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80058E44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80058E48: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80058E4C: lw          $a3, 0x14($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X14);
    // 0x80058E50: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x80058E54: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80058E58: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x80058E5C: beq         $a3, $zero, L_80058E94
    if (ctx->r7 == 0) {
        // 0x80058E60: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80058E94;
    }
    // 0x80058E60: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80058E64: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x80058E68: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80058E6C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80058E70: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80058E74: jal         0x800526C0
    // 0x80058E78: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800526C0(rdram, ctx);
        goto after_0;
    // 0x80058E78: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x80058E7C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80058E80: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80058E84: jal         0x800526F0
    // 0x80058E88: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    func_800526F0(rdram, ctx);
        goto after_1;
    // 0x80058E88: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    after_1:
    // 0x80058E8C: b           L_80058F14
    // 0x80058E90: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
        goto L_80058F14;
    // 0x80058E90: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_80058E94:
    // 0x80058E94: lw          $a3, 0x4($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X4);
    // 0x80058E98: beq         $a3, $zero, L_80058ECC
    if (ctx->r7 == 0) {
        // 0x80058E9C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80058ECC;
    }
    // 0x80058E9C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80058EA0: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x80058EA4: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80058EA8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80058EAC: jal         0x800526C0
    // 0x80058EB0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_800526C0(rdram, ctx);
        goto after_2;
    // 0x80058EB0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80058EB4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80058EB8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80058EBC: jal         0x800526F0
    // 0x80058EC0: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    func_800526F0(rdram, ctx);
        goto after_3;
    // 0x80058EC0: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    after_3:
    // 0x80058EC4: b           L_80058F14
    // 0x80058EC8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
        goto L_80058F14;
    // 0x80058EC8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_80058ECC:
    // 0x80058ECC: lw          $a3, 0xC($t0)
    ctx->r7 = MEM_W(ctx->r8, 0XC);
    // 0x80058ED0: beql        $a3, $zero, L_80058F18
    if (ctx->r7 == 0) {
        // 0x80058ED4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80058F18;
    }
    goto skip_0;
    // 0x80058ED4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80058ED8: lw          $t8, 0x8($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X8);
L_80058EDC:
    // 0x80058EDC: lh          $t9, 0x16($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X16);
    // 0x80058EE0: slt         $at, $a2, $t9
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80058EE4: bnel        $at, $zero, L_80058F0C
    if (ctx->r1 != 0) {
        // 0x80058EE8: lw          $a3, 0x0($a3)
        ctx->r7 = MEM_W(ctx->r7, 0X0);
            goto L_80058F0C;
    }
    goto skip_1;
    // 0x80058EE8: lw          $a3, 0x0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X0);
    skip_1:
    // 0x80058EEC: lw          $t1, 0xD8($a3)
    ctx->r9 = MEM_W(ctx->r7, 0XD8);
    // 0x80058EF0: bnel        $t1, $zero, L_80058F0C
    if (ctx->r9 != 0) {
        // 0x80058EF4: lw          $a3, 0x0($a3)
        ctx->r7 = MEM_W(ctx->r7, 0X0);
            goto L_80058F0C;
    }
    goto skip_2;
    // 0x80058EF4: lw          $a3, 0x0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X0);
    skip_2:
    // 0x80058EF8: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x80058EFC: lw          $t2, 0x8($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X8);
    // 0x80058F00: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80058F04: lh          $a2, 0x16($t2)
    ctx->r6 = MEM_H(ctx->r10, 0X16);
    // 0x80058F08: lw          $a3, 0x0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X0);
L_80058F0C:
    // 0x80058F0C: bnel        $a3, $zero, L_80058EDC
    if (ctx->r7 != 0) {
        // 0x80058F10: lw          $t8, 0x8($a3)
        ctx->r24 = MEM_W(ctx->r7, 0X8);
            goto L_80058EDC;
    }
    goto skip_3;
    // 0x80058F10: lw          $t8, 0x8($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X8);
    skip_3:
L_80058F14:
    // 0x80058F14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80058F18:
    // 0x80058F18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80058F1C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80058F20: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80058F28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80058F28: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80058F2C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80058F30: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80058F34: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80058F38: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80058F3C: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x80058F40: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80058F44: sh          $t6, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r14;
    // 0x80058F48: lbu         $t7, 0x4($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X4);
    // 0x80058F4C: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
    // 0x80058F50: sh          $t7, 0x1A($a1)
    MEM_H(0X1A, ctx->r5) = ctx->r15;
    // 0x80058F54: lh          $t8, 0x2($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X2);
    // 0x80058F58: sh          $zero, 0x14($a1)
    MEM_H(0X14, ctx->r5) = 0;
    // 0x80058F5C: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    // 0x80058F60: sh          $t8, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r24;
    // 0x80058F64: lh          $a2, 0x0($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X0);
    // 0x80058F68: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80058F6C: jal         0x80058E40
    // 0x80058F70: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_80058E40(rdram, ctx);
        goto after_0;
    // 0x80058F70: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80058F74: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80058F78: beql        $t9, $zero, L_80059050
    if (ctx->r25 == 0) {
        // 0x80058F7C: lw          $v0, 0x2C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X2C);
            goto L_80059050;
    }
    goto skip_0;
    // 0x80058F7C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80058F80: beq         $v0, $zero, L_80059034
    if (ctx->r2 == 0) {
        // 0x80058F84: lw          $a0, 0xC($t9)
        ctx->r4 = MEM_W(ctx->r25, 0XC);
            goto L_80059034;
    }
    // 0x80058F84: lw          $a0, 0xC($t9)
    ctx->r4 = MEM_W(ctx->r25, 0XC);
    // 0x80058F88: addiu       $t0, $zero, 0x200
    ctx->r8 = ADD32(0, 0X200);
    // 0x80058F8C: sw          $t0, 0xD8($t9)
    MEM_W(0XD8, ctx->r25) = ctx->r8;
    // 0x80058F90: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80058F94: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x80058F98: sw          $zero, 0x8($t2)
    MEM_W(0X8, ctx->r10) = 0;
    // 0x80058F9C: jal         0x800538F0
    // 0x80058FA0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800538F0(rdram, ctx);
        goto after_1;
    // 0x80058FA0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_1:
    // 0x80058FA4: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80058FA8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80058FAC: addiu       $t5, $zero, 0xB
    ctx->r13 = ADD32(0, 0XB);
    // 0x80058FB0: lw          $t4, 0x1C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1C);
    // 0x80058FB4: sh          $t5, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r13;
    // 0x80058FB8: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x80058FBC: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80058FC0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80058FC4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80058FC8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80058FCC: lw          $t7, 0xD8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XD8);
    // 0x80058FD0: addiu       $t8, $t7, -0x40
    ctx->r24 = ADD32(ctx->r15, -0X40);
    // 0x80058FD4: sw          $t8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r24;
    // 0x80058FD8: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x80058FDC: jalr        $t9
    // 0x80058FE0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80058FE0: nop

    after_2:
    // 0x80058FE4: jal         0x800538F0
    // 0x80058FE8: nop

    func_800538F0(rdram, ctx);
        goto after_3;
    // 0x80058FE8: nop

    after_3:
    // 0x80058FEC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80058FF0: beq         $v0, $zero, L_8005903C
    if (ctx->r2 == 0) {
        // 0x80058FF4: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8005903C;
    }
    // 0x80058FF4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80058FF8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80058FFC: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80059000: addiu       $t5, $zero, 0xF
    ctx->r13 = ADD32(0, 0XF);
    // 0x80059004: lw          $t1, 0x1C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1C);
    // 0x80059008: lw          $t3, 0xD8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XD8);
    // 0x8005900C: sh          $t5, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r13;
    // 0x80059010: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80059014: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80059018: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8005901C: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x80059020: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80059024: jalr        $t9
    // 0x80059028: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x80059028: nop

    after_4:
    // 0x8005902C: b           L_80059040
    // 0x80059030: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
        goto L_80059040;
    // 0x80059030: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_80059034:
    // 0x80059034: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80059038: sw          $zero, 0xD8($t6)
    MEM_W(0XD8, ctx->r14) = 0;
L_8005903C:
    // 0x8005903C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_80059040:
    // 0x80059040: sw          $s0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r16;
    // 0x80059044: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80059048: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
    // 0x8005904C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
L_80059050:
    // 0x80059050: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80059054: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80059058: sltu        $t0, $zero, $v0
    ctx->r8 = 0 < ctx->r2 ? 1 : 0;
    // 0x8005905C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80059060: jr          $ra
    // 0x80059064: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    TRACE_RETURN()
    return;
    // 0x80059064: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80059070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80059070: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80059074: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80059078: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8005907C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80059080: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80059084: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x80059088: beql        $t6, $zero, L_80059148
    if (ctx->r14 == 0) {
        // 0x8005908C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80059148;
    }
    goto skip_0;
    // 0x8005908C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80059090: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80059094: jal         0x800538F0
    // 0x80059098: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800538F0(rdram, ctx);
        goto after_0;
    // 0x80059098: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8005909C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800590A0: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x800590A4: beq         $v0, $zero, L_80059144
    if (ctx->r2 == 0) {
        // 0x800590A8: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80059144;
    }
    // 0x800590A8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800590AC: lbu         $v1, 0x3B($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X3B);
    // 0x800590B0: bgez        $v1, L_800590C4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800590B4: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800590C4;
    }
    // 0x800590B4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800590B8: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
    // 0x800590BC: andi        $t7, $v1, 0xFF
    ctx->r15 = ctx->r3 & 0XFF;
    // 0x800590C0: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
L_800590C4:
    // 0x800590C4: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x800590C8: lw          $t8, 0x1C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1C);
    // 0x800590CC: addiu       $t2, $zero, 0xD
    ctx->r10 = ADD32(0, 0XD);
    // 0x800590D0: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x800590D4: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800590D8: sh          $t2, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r10;
    // 0x800590DC: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800590E0: sw          $t1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r9;
    // 0x800590E4: lh          $t3, 0x1A($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X1A);
    // 0x800590E8: sh          $t3, 0xA($a2)
    MEM_H(0XA, ctx->r6) = ctx->r11;
    // 0x800590EC: lbu         $t4, 0x37($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X37);
    // 0x800590F0: sb          $t4, 0x12($a2)
    MEM_B(0X12, ctx->r6) = ctx->r12;
    // 0x800590F4: lh          $t5, 0x32($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X32);
    // 0x800590F8: sb          $v1, 0x13($a2)
    MEM_B(0X13, ctx->r6) = ctx->r3;
    // 0x800590FC: sh          $t5, 0x10($a2)
    MEM_H(0X10, ctx->r6) = ctx->r13;
    // 0x80059100: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80059104: swc1        $f4, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f4.u32l;
    // 0x80059108: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8005910C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x80059110: jal         0x800537E8
    // 0x80059114: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_800537E8(rdram, ctx);
        goto after_1;
    // 0x80059114: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_1:
    // 0x80059118: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8005911C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80059120: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80059124: sw          $v0, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r2;
    // 0x80059128: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8005912C: sw          $t6, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r14;
    // 0x80059130: lw          $t7, 0x8($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X8);
    // 0x80059134: lw          $a0, 0xC($t7)
    ctx->r4 = MEM_W(ctx->r15, 0XC);
    // 0x80059138: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x8005913C: jalr        $t9
    // 0x80059140: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80059140: nop

    after_2:
L_80059144:
    // 0x80059144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80059148:
    // 0x80059148: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005914C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80059160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80059160: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80059164: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80059168: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8005916C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80059170: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x80059174: beql        $t6, $zero, L_800591D8
    if (ctx->r14 == 0) {
        // 0x80059178: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800591D8;
    }
    goto skip_0;
    // 0x80059178: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8005917C: jal         0x800538F0
    // 0x80059180: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800538F0(rdram, ctx);
        goto after_0;
    // 0x80059180: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80059184: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80059188: beq         $v0, $zero, L_800591D4
    if (ctx->r2 == 0) {
        // 0x8005918C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800591D4;
    }
    // 0x8005918C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80059190: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80059194: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x80059198: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x8005919C: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x800591A0: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x800591A4: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x800591A8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800591AC: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800591B0: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800591B4: lbu         $t3, 0x23($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X23);
    // 0x800591B8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800591BC: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x800591C0: lw          $t4, 0x8($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X8);
    // 0x800591C4: lw          $a0, 0xC($t4)
    ctx->r4 = MEM_W(ctx->r12, 0XC);
    // 0x800591C8: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800591CC: jalr        $t9
    // 0x800591D0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800591D0: nop

    after_1:
L_800591D4:
    // 0x800591D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800591D8:
    // 0x800591D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800591DC: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800591F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800591F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800591F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800591F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800591FC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80059200: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x80059204: beql        $t6, $zero, L_80059278
    if (ctx->r14 == 0) {
        // 0x80059208: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80059278;
    }
    goto skip_0;
    // 0x80059208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8005920C: jal         0x800538F0
    // 0x80059210: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800538F0(rdram, ctx);
        goto after_0;
    // 0x80059210: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80059214: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80059218: beq         $v0, $zero, L_80059274
    if (ctx->r2 == 0) {
        // 0x8005921C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80059274;
    }
    // 0x8005921C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80059220: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80059224: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x80059228: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x8005922C: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x80059230: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x80059234: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x80059238: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8005923C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80059240: lbu         $v1, 0x23($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X23);
    // 0x80059244: bgez        $v1, L_80059254
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80059248: negu        $t3, $v1
        ctx->r11 = SUB32(0, ctx->r3);
            goto L_80059254;
    }
    // 0x80059248: negu        $t3, $v1
    ctx->r11 = SUB32(0, ctx->r3);
    // 0x8005924C: b           L_80059258
    // 0x80059250: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
        goto L_80059258;
    // 0x80059250: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
L_80059254:
    // 0x80059254: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
L_80059258:
    // 0x80059258: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8005925C: lw          $t4, 0x8($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X8);
    // 0x80059260: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80059264: lw          $a0, 0xC($t4)
    ctx->r4 = MEM_W(ctx->r12, 0XC);
    // 0x80059268: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x8005926C: jalr        $t9
    // 0x80059270: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80059270: nop

    after_1:
L_80059274:
    // 0x80059274: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80059278:
    // 0x80059278: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005927C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80059330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80059330: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80059334: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80059338: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8005933C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80059340: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x80059344: beql        $t6, $zero, L_800593B0
    if (ctx->r14 == 0) {
        // 0x80059348: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800593B0;
    }
    goto skip_0;
    // 0x80059348: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8005934C: jal         0x800538F0
    // 0x80059350: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800538F0(rdram, ctx);
        goto after_0;
    // 0x80059350: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80059354: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80059358: beq         $v0, $zero, L_800593AC
    if (ctx->r2 == 0) {
        // 0x8005935C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800593AC;
    }
    // 0x8005935C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80059360: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80059364: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x80059368: addiu       $t2, $zero, 0xE
    ctx->r10 = ADD32(0, 0XE);
    // 0x8005936C: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x80059370: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x80059374: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x80059378: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8005937C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80059380: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80059384: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80059388: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8005938C: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x80059390: lh          $t4, 0x1A($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X1A);
    // 0x80059394: sh          $t4, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r12;
    // 0x80059398: lw          $t5, 0x8($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X8);
    // 0x8005939C: lw          $a0, 0xC($t5)
    ctx->r4 = MEM_W(ctx->r13, 0XC);
    // 0x800593A0: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800593A4: jalr        $t9
    // 0x800593A8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800593A8: nop

    after_1:
L_800593AC:
    // 0x800593AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800593B0:
    // 0x800593B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800593B4: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800593C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800593C0: jr          $ra
    // 0x800593C4: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    TRACE_RETURN()
    return;
    // 0x800593C4: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
;}
RECOMP_FUNC void func_80059810(uint8_t* rdram, recomp_context* ctx) {
    osSpTaskYielded_recomp(rdram, ctx);
}
