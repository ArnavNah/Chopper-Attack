#include "recomp.h"
#include "trace.h"
#include "funcs.h"

RECOMP_FUNC void func_8006132C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8006132C: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x80061330: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x80061334: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80061338: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8006133C: bgez        $a2, L_80061350
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80061340: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80061350;
    }
    // 0x80061340: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80061344: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80061348: nop

    // 0x8006134C: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_80061350:
    // 0x80061350: lh          $t6, 0x18($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X18);
    // 0x80061354: mul.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80061358: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8006135C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80061360: ldc1        $f10, -0x6818($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X6818);
    // 0x80061364: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80061368: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8006136C: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x80061370: mul.d       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x80061374: div.d       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f18.d);
    // 0x80061378: jr          $ra
    // 0x8006137C: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    TRACE_RETURN()
    return;
    // 0x8006137C: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
;}
RECOMP_FUNC void func_80061380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80061380: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80061384: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80061388: lw          $t7, 0x10($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X10);
    // 0x8006138C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80061390: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x80061394: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80061398: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8006139C: sltu        $at, $v0, $t8
    ctx->r1 = ctx->r2 < ctx->r24 ? 1 : 0;
    // 0x800613A0: bne         $at, $zero, L_800613B0
    if (ctx->r1 != 0) {
        // 0x800613A4: or          $t0, $a1, $zero
        ctx->r8 = ctx->r5 | 0;
            goto L_800613B0;
    }
    // 0x800613A4: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x800613A8: b           L_800613C8
    // 0x800613AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800613C8;
    // 0x800613AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800613B0:
    // 0x800613B0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800613B4: jal         0x80060F58
    // 0x800613B8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80060F58(rdram, ctx);
        goto after_0;
    // 0x800613B8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x800613BC: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x800613C0: sw          $a3, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r7;
    // 0x800613C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800613C8:
    // 0x800613C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800613CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800613D0: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800613D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800613D8: lw          $a1, 0x8($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X8);
    // 0x800613DC: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800613E0: addiu       $t7, $a1, 0x1
    ctx->r15 = ADD32(ctx->r5, 0X1);
    // 0x800613E4: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x800613E8: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800613EC: sll         $t6, $v1, 24
    ctx->r14 = S32(ctx->r3 << 24);
    // 0x800613F0: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800613F4: or          $v1, $t6, $t9
    ctx->r3 = ctx->r14 | ctx->r25;
    // 0x800613F8: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x800613FC: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x80061400: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80061404: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x80061408: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x8006140C: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x80061410: lbu         $t6, 0x0($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X0);
    // 0x80061414: or          $v1, $v1, $t8
    ctx->r3 = ctx->r3 | ctx->r24;
    // 0x80061418: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x8006141C: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x80061420: jr          $ra
    // 0x80061424: or          $v0, $v1, $t6
    ctx->r2 = ctx->r3 | ctx->r14;
    TRACE_RETURN()
    return;
    // 0x80061424: or          $v0, $v1, $t6
    ctx->r2 = ctx->r3 | ctx->r14;
;}
RECOMP_FUNC void func_80061428(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80061428: lw          $a1, 0x8($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X8);
    // 0x8006142C: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x80061430: addiu       $t9, $a1, 0x1
    ctx->r25 = ADD32(ctx->r5, 0X1);
    // 0x80061434: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x80061438: lbu         $t6, 0x0($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X0);
    // 0x8006143C: sll         $t8, $v1, 8
    ctx->r24 = S32(ctx->r3 << 8);
    // 0x80061440: addiu       $t9, $t9, 0x1
    ctx->r25 = ADD32(ctx->r25, 0X1);
    // 0x80061444: or          $v1, $t8, $t6
    ctx->r3 = ctx->r24 | ctx->r14;
    // 0x80061448: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x8006144C: sra         $v0, $t7, 16
    ctx->r2 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80061450: jr          $ra
    // 0x80061454: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    TRACE_RETURN()
    return;
    // 0x80061454: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void func_80061458(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80061458: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006145C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80061460: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80061464: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x80061468: sw          $a2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r6;
    // 0x8006146C: sh          $zero, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = 0;
    // 0x80061470: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x80061474: jal         0x800613D8
    // 0x80061478: sw          $a1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r5;
    func_800613D8(rdram, ctx);
        goto after_0;
    // 0x80061478: sw          $a1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r5;
    after_0:
    // 0x8006147C: lui         $at, 0x4D54
    ctx->r1 = S32(0X4D54 << 16);
    // 0x80061480: ori         $at, $at, 0x6864
    ctx->r1 = ctx->r1 | 0X6864;
    // 0x80061484: bnel        $v0, $at, L_80061524
    if (ctx->r2 != ctx->r1) {
        // 0x80061488: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80061524;
    }
    goto skip_0;
    // 0x80061488: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8006148C: jal         0x800613D8
    // 0x80061490: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800613D8(rdram, ctx);
        goto after_1;
    // 0x80061490: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x80061494: jal         0x80061428
    // 0x80061498: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80061428(rdram, ctx);
        goto after_2;
    // 0x80061498: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x8006149C: bnel        $v0, $zero, L_80061524
    if (ctx->r2 != 0) {
        // 0x800614A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80061524;
    }
    goto skip_1;
    // 0x800614A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800614A4: jal         0x80061428
    // 0x800614A8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80061428(rdram, ctx);
        goto after_3;
    // 0x800614A8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_3:
    // 0x800614AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800614B0: bnel        $v0, $at, L_80061524
    if (ctx->r2 != ctx->r1) {
        // 0x800614B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80061524;
    }
    goto skip_2;
    // 0x800614B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800614B8: jal         0x80061428
    // 0x800614BC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80061428(rdram, ctx);
        goto after_4;
    // 0x800614BC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_4:
    // 0x800614C0: sh          $v0, 0x18($a3)
    MEM_H(0X18, ctx->r7) = ctx->r2;
    // 0x800614C4: lh          $v1, 0x18($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X18);
    // 0x800614C8: andi        $t6, $v1, 0x8000
    ctx->r14 = ctx->r3 & 0X8000;
    // 0x800614CC: bnel        $t6, $zero, L_80061524
    if (ctx->r14 != 0) {
        // 0x800614D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80061524;
    }
    goto skip_3;
    // 0x800614D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x800614D4: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x800614D8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800614DC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800614E0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800614E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800614E8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800614EC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800614F0: div.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f10.d);
    // 0x800614F4: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800614F8: jal         0x800613D8
    // 0x800614FC: swc1        $f8, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f8.u32l;
    func_800613D8(rdram, ctx);
        goto after_5;
    // 0x800614FC: swc1        $f8, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f8.u32l;
    after_5:
    // 0x80061500: lui         $at, 0x4D54
    ctx->r1 = S32(0X4D54 << 16);
    // 0x80061504: ori         $at, $at, 0x726B
    ctx->r1 = ctx->r1 | 0X726B;
    // 0x80061508: bnel        $v0, $at, L_80061524
    if (ctx->r2 != ctx->r1) {
        // 0x8006150C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80061524;
    }
    goto skip_4;
    // 0x8006150C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x80061510: jal         0x800613D8
    // 0x80061514: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800613D8(rdram, ctx);
        goto after_6;
    // 0x80061514: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_6:
    // 0x80061518: lw          $t7, 0x8($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X8);
    // 0x8006151C: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x80061520: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80061524:
    // 0x80061524: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80061528: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80061530(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80061530: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80061534: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80061538: jr          $ra
    // 0x8006153C: sh          $a2, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r6;
    TRACE_RETURN()
    return;
    // 0x8006153C: sh          $a2, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r6;
;}
RECOMP_FUNC void func_80061540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80061540: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x80061544: jr          $ra
    // 0x80061548: lw          $v0, 0x4470($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4470);
    TRACE_RETURN()
    return;
    // 0x80061548: lw          $v0, 0x4470($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4470);
;}
RECOMP_FUNC void func_80061550(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80061550: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80061554: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80061558: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006155C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80061560: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80061564: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80061568: lui         $s1, 0x8007
    ctx->r17 = S32(0X8007 << 16);
    // 0x8006156C: lui         $t6, 0xA440
    ctx->r14 = S32(0XA440 << 16);
    // 0x80061570: lw          $s1, 0x4474($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X4474);
    // 0x80061574: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80061578: lw          $s0, 0x8($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X8);
    // 0x8006157C: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80061580: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80061584: jal         0x80053750
    // 0x80061588: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x80061588: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    after_0:
    // 0x8006158C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80061590: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80061594: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80061598: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8006159C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800615A0: addu        $t1, $s0, $t0
    ctx->r9 = ADD32(ctx->r16, ctx->r8);
    // 0x800615A4: lw          $t2, 0x28($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X28);
    // 0x800615A8: addu        $t3, $t2, $s2
    ctx->r11 = ADD32(ctx->r10, ctx->r18);
    // 0x800615AC: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x800615B0: lhu         $t4, 0x0($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X0);
    // 0x800615B4: andi        $t5, $t4, 0x2
    ctx->r13 = ctx->r12 & 0X2;
    // 0x800615B8: beq         $t5, $zero, L_800615DC
    if (ctx->r13 == 0) {
        // 0x800615BC: nop
    
            goto L_800615DC;
    }
    // 0x800615BC: nop

    // 0x800615C0: lw          $t7, 0x20($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X20);
    // 0x800615C4: lw          $t6, 0x20($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X20);
    // 0x800615C8: addiu       $at, $zero, -0x1000
    ctx->r1 = ADD32(0, -0X1000);
    // 0x800615CC: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800615D0: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800615D4: b           L_800615E4
    // 0x800615D8: sw          $t9, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r25;
        goto L_800615E4;
    // 0x800615D8: sw          $t9, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r25;
L_800615DC:
    // 0x800615DC: lw          $t0, 0x20($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X20);
    // 0x800615E0: sw          $t0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r8;
L_800615E4:
    // 0x800615E4: lhu         $t1, 0x0($s1)
    ctx->r9 = MEM_HU(ctx->r17, 0X0);
    // 0x800615E8: andi        $t2, $t1, 0x4
    ctx->r10 = ctx->r9 & 0X4;
    // 0x800615EC: beq         $t2, $zero, L_800616F4
    if (ctx->r10 == 0) {
        // 0x800615F0: nop
    
            goto L_800616F4;
    }
    // 0x800615F0: nop

    // 0x800615F4: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800615F8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800615FC: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80061600: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80061604: addu        $t5, $s0, $t4
    ctx->r13 = ADD32(ctx->r16, ctx->r12);
    // 0x80061608: lw          $t7, 0x2C($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X2C);
    // 0x8006160C: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x80061610: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80061614: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80061618: lwc1        $f4, 0x24($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8006161C: bgez        $t6, L_80061634
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80061620: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80061634;
    }
    // 0x80061620: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80061624: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80061628: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006162C: nop

    // 0x80061630: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_80061634:
    // 0x80061634: mul.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80061638: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8006163C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80061640: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80061644: nop

    // 0x80061648: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8006164C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80061650: nop

    // 0x80061654: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x80061658: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8006165C: beq         $t9, $zero, L_800616AC
    if (ctx->r25 == 0) {
        // 0x80061660: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_800616AC;
    }
    // 0x80061660: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80061664: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80061668: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8006166C: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80061670: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80061674: nop

    // 0x80061678: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8006167C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80061680: nop

    // 0x80061684: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x80061688: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8006168C: bne         $t9, $zero, L_800616A4
    if (ctx->r25 != 0) {
        // 0x80061690: nop
    
            goto L_800616A4;
    }
    // 0x80061690: nop

    // 0x80061694: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80061698: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8006169C: b           L_800616BC
    // 0x800616A0: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_800616BC;
    // 0x800616A0: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_800616A4:
    // 0x800616A4: b           L_800616BC
    // 0x800616A8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_800616BC;
    // 0x800616A8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_800616AC:
    // 0x800616AC: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x800616B0: nop

    // 0x800616B4: bltz        $t9, L_800616A4
    if (SIGNED(ctx->r25) < 0) {
        // 0x800616B8: nop
    
            goto L_800616A4;
    }
    // 0x800616B8: nop

L_800616BC:
    // 0x800616BC: sw          $t9, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r25;
    // 0x800616C0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800616C4: lw          $t0, 0x2C($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X2C);
    // 0x800616C8: addiu       $at, $zero, -0x1000
    ctx->r1 = ADD32(0, -0X1000);
    // 0x800616CC: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800616D0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800616D4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800616D8: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x800616DC: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x800616E0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800616E4: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x800616E8: or          $t7, $t0, $t5
    ctx->r15 = ctx->r8 | ctx->r13;
    // 0x800616EC: b           L_80061710
    // 0x800616F0: sw          $t7, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r15;
        goto L_80061710;
    // 0x800616F0: sw          $t7, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r15;
L_800616F4:
    // 0x800616F4: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800616F8: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800616FC: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x80061700: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80061704: addu        $t9, $s0, $t8
    ctx->r25 = ADD32(ctx->r16, ctx->r24);
    // 0x80061708: lw          $t1, 0x2C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X2C);
    // 0x8006170C: sw          $t1, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r9;
L_80061710:
    // 0x80061710: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80061714: lui         $t5, 0x8007
    ctx->r13 = S32(0X8007 << 16);
    // 0x80061718: lw          $t5, 0x328C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X328C);
    // 0x8006171C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80061720: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80061724: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80061728: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x8006172C: lw          $t0, 0x30($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X30);
    // 0x80061730: sll         $t7, $t5, 16
    ctx->r15 = S32(ctx->r13 << 16);
    // 0x80061734: subu        $t6, $t0, $t7
    ctx->r14 = SUB32(ctx->r8, ctx->r15);
    // 0x80061738: addu        $t8, $t6, $t5
    ctx->r24 = ADD32(ctx->r14, ctx->r13);
    // 0x8006173C: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x80061740: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x80061744: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x80061748: lhu         $t1, 0x0($s1)
    ctx->r9 = MEM_HU(ctx->r17, 0X0);
    // 0x8006174C: andi        $t2, $t1, 0x20
    ctx->r10 = ctx->r9 & 0X20;
    // 0x80061750: beq         $t2, $zero, L_8006175C
    if (ctx->r10 == 0) {
        // 0x80061754: nop
    
            goto L_8006175C;
    }
    // 0x80061754: nop

    // 0x80061758: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
L_8006175C:
    // 0x8006175C: lhu         $t3, 0x0($s1)
    ctx->r11 = MEM_HU(ctx->r17, 0X0);
    // 0x80061760: andi        $t4, $t3, 0x40
    ctx->r12 = ctx->r11 & 0X40;
    // 0x80061764: beq         $t4, $zero, L_8006177C
    if (ctx->r12 == 0) {
        // 0x80061768: nop
    
            goto L_8006177C;
    }
    // 0x80061768: nop

    // 0x8006176C: sw          $zero, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = 0;
    // 0x80061770: jal         0x80053750
    // 0x80061774: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x80061774: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    after_1:
    // 0x80061778: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
L_8006177C:
    // 0x8006177C: lhu         $t0, 0x0($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0X0);
    // 0x80061780: andi        $t7, $t0, 0x80
    ctx->r15 = ctx->r8 & 0X80;
    // 0x80061784: beq         $t7, $zero, L_800617AC
    if (ctx->r15 == 0) {
        // 0x80061788: nop
    
            goto L_800617AC;
    }
    // 0x80061788: nop

    // 0x8006178C: lhu         $t6, 0x28($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X28);
    // 0x80061790: lui         $at, 0x3FF
    ctx->r1 = S32(0X3FF << 16);
    // 0x80061794: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x80061798: sll         $t5, $t6, 16
    ctx->r13 = S32(ctx->r14 << 16);
    // 0x8006179C: and         $t8, $t5, $at
    ctx->r24 = ctx->r13 & ctx->r1;
    // 0x800617A0: jal         0x80053750
    // 0x800617A4: sw          $t8, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r24;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x800617A4: sw          $t8, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r24;
    after_2:
    // 0x800617A8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
L_800617AC:
    // 0x800617AC: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800617B0: lui         $t1, 0xA440
    ctx->r9 = S32(0XA440 << 16);
    // 0x800617B4: lui         $t3, 0xA440
    ctx->r11 = S32(0XA440 << 16);
    // 0x800617B8: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x800617BC: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x800617C0: lui         $t0, 0xA440
    ctx->r8 = S32(0XA440 << 16);
    // 0x800617C4: lui         $t6, 0xA440
    ctx->r14 = S32(0XA440 << 16);
    // 0x800617C8: sw          $t2, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r10;
    // 0x800617CC: lw          $t4, 0xC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XC);
    // 0x800617D0: lui         $t8, 0xA440
    ctx->r24 = S32(0XA440 << 16);
    // 0x800617D4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800617D8: sw          $t4, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r12;
    // 0x800617DC: lw          $t7, 0x10($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X10);
    // 0x800617E0: sw          $t7, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r15;
    // 0x800617E4: lw          $t5, 0x14($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X14);
    // 0x800617E8: sw          $t5, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->r13;
    // 0x800617EC: lw          $t9, 0x18($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X18);
    // 0x800617F0: sw          $t9, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->r25;
    // 0x800617F4: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800617F8: lui         $t9, 0xA440
    ctx->r25 = S32(0XA440 << 16);
    // 0x800617FC: sw          $t2, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->r10;
    // 0x80061800: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80061804: sw          $t4, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->r12;
    // 0x80061808: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8006180C: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80061810: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x80061814: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80061818: addu        $t5, $s0, $t6
    ctx->r13 = ADD32(ctx->r16, ctx->r14);
    // 0x8006181C: lw          $t8, 0x34($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X34);
    // 0x80061820: lui         $t6, 0xA440
    ctx->r14 = S32(0XA440 << 16);
    // 0x80061824: sw          $t8, 0x2C($t9)
    MEM_W(0X2C, ctx->r25) = ctx->r24;
    // 0x80061828: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8006182C: lui         $t8, 0xA440
    ctx->r24 = S32(0XA440 << 16);
    // 0x80061830: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80061834: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80061838: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8006183C: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x80061840: lw          $t4, 0x38($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X38);
    // 0x80061844: lui         $t1, 0xA440
    ctx->r9 = S32(0XA440 << 16);
    // 0x80061848: lui         $t2, 0x8007
    ctx->r10 = S32(0X8007 << 16);
    // 0x8006184C: sw          $t4, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r12;
    // 0x80061850: lw          $t7, 0x20($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X20);
    // 0x80061854: lui         $t4, 0x8007
    ctx->r12 = S32(0X8007 << 16);
    // 0x80061858: lui         $t3, 0x8007
    ctx->r11 = S32(0X8007 << 16);
    // 0x8006185C: sw          $t7, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r15;
    // 0x80061860: lw          $t5, 0x2C($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X2C);
    // 0x80061864: sw          $t5, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->r13;
    // 0x80061868: lw          $t9, 0xC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XC);
    // 0x8006186C: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80061870: lw          $t2, 0x4470($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X4470);
    // 0x80061874: sw          $t2, 0x4474($at)
    MEM_W(0X4474, ctx->r1) = ctx->r10;
    // 0x80061878: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8006187C: sw          $s1, 0x4470($at)
    MEM_W(0X4470, ctx->r1) = ctx->r17;
    // 0x80061880: lw          $t4, 0x4470($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X4470);
    // 0x80061884: lw          $t3, 0x4474($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X4474);
    // 0x80061888: addiu       $t6, $t4, 0x30
    ctx->r14 = ADD32(ctx->r12, 0X30);
L_8006188C:
    // 0x8006188C: lw          $at, 0x0($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X0);
    // 0x80061890: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x80061894: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x80061898: sw          $at, -0xC($t3)
    MEM_W(-0XC, ctx->r11) = ctx->r1;
    // 0x8006189C: lw          $at, -0x8($t4)
    ctx->r1 = MEM_W(ctx->r12, -0X8);
    // 0x800618A0: sw          $at, -0x8($t3)
    MEM_W(-0X8, ctx->r11) = ctx->r1;
    // 0x800618A4: lw          $at, -0x4($t4)
    ctx->r1 = MEM_W(ctx->r12, -0X4);
    // 0x800618A8: bne         $t4, $t6, L_8006188C
    if (ctx->r12 != ctx->r14) {
        // 0x800618AC: sw          $at, -0x4($t3)
        MEM_W(-0X4, ctx->r11) = ctx->r1;
            goto L_8006188C;
    }
    // 0x800618AC: sw          $at, -0x4($t3)
    MEM_W(-0X4, ctx->r11) = ctx->r1;
    // 0x800618B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800618B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800618B8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800618BC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800618C0: jr          $ra
    // 0x800618C4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    TRACE_RETURN()
    return;
    // 0x800618C4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_800618D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800618D0: lui         $t6, 0xA404
    ctx->r14 = S32(0XA404 << 16);
    // 0x800618D4: jr          $ra
    // 0x800618D8: lw          $v0, 0x10($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X10);
    TRACE_RETURN()
    return;
    // 0x800618D8: lw          $v0, 0x10($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X10);
;}
RECOMP_FUNC void func_800618E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800618E0: beq         $a2, $zero, L_8006194C
    if (ctx->r6 == 0) {
        // 0x800618E4: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_8006194C;
    }
    // 0x800618E4: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800618E8: beq         $a0, $a1, L_8006194C
    if (ctx->r4 == ctx->r5) {
        // 0x800618EC: slt         $at, $a1, $a0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8006194C;
    }
    // 0x800618EC: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800618F0: bnel        $at, $zero, L_80061914
    if (ctx->r1 != 0) {
        // 0x800618F4: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_80061914;
    }
    goto skip_0;
    // 0x800618F4: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_0:
    // 0x800618F8: add         $v0, $a0, $a2
    ctx->r2 = ADD32(ctx->r4, ctx->r6);
    // 0x800618FC: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80061900: beql        $at, $zero, L_80061914
    if (ctx->r1 == 0) {
        // 0x80061904: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_80061914;
    }
    goto skip_1;
    // 0x80061904: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_1:
    // 0x80061908: b           L_80061A78
    // 0x8006190C: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
        goto L_80061A78;
    // 0x8006190C: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x80061910: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_80061914:
    // 0x80061914: bne         $at, $zero, L_8006192C
    if (ctx->r1 != 0) {
        // 0x80061918: nop
    
            goto L_8006192C;
    }
    // 0x80061918: nop

    // 0x8006191C: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
    // 0x80061920: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x80061924: beq         $v0, $v1, L_80061954
    if (ctx->r2 == ctx->r3) {
        // 0x80061928: nop
    
            goto L_80061954;
    }
    // 0x80061928: nop

L_8006192C:
    // 0x8006192C: beq         $a2, $zero, L_8006194C
    if (ctx->r6 == 0) {
        // 0x80061930: nop
    
            goto L_8006194C;
    }
    // 0x80061930: nop

    // 0x80061934: addu        $v1, $a0, $a2
    ctx->r3 = ADD32(ctx->r4, ctx->r6);
L_80061938:
    // 0x80061938: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x8006193C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80061940: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80061944: bne         $a0, $v1, L_80061938
    if (ctx->r4 != ctx->r3) {
        // 0x80061948: sb          $v0, -0x1($a1)
        MEM_B(-0X1, ctx->r5) = ctx->r2;
            goto L_80061938;
    }
    // 0x80061948: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
L_8006194C:
    // 0x8006194C: jr          $ra
    // 0x80061950: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    TRACE_RETURN()
    return;
    // 0x80061950: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_80061954:
    // 0x80061954: beq         $v0, $zero, L_800619B8
    if (ctx->r2 == 0) {
        // 0x80061958: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800619B8;
    }
    // 0x80061958: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006195C: beq         $v0, $at, L_8006199C
    if (ctx->r2 == ctx->r1) {
        // 0x80061960: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8006199C;
    }
    // 0x80061960: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80061964: beql        $v0, $at, L_80061988
    if (ctx->r2 == ctx->r1) {
        // 0x80061968: lh          $v0, 0x0($a0)
        ctx->r2 = MEM_H(ctx->r4, 0X0);
            goto L_80061988;
    }
    goto skip_2;
    // 0x80061968: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    skip_2:
    // 0x8006196C: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x80061970: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80061974: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80061978: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8006197C: b           L_800619B8
    // 0x80061980: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
        goto L_800619B8;
    // 0x80061980: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
    // 0x80061984: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
L_80061988:
    // 0x80061988: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8006198C: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80061990: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x80061994: b           L_800619B8
    // 0x80061998: sh          $v0, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r2;
        goto L_800619B8;
    // 0x80061998: sh          $v0, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r2;
L_8006199C:
    // 0x8006199C: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800619A0: lh          $v1, 0x1($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X1);
    // 0x800619A4: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x800619A8: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    // 0x800619AC: addiu       $a2, $a2, -0x3
    ctx->r6 = ADD32(ctx->r6, -0X3);
    // 0x800619B0: sb          $v0, -0x3($a1)
    MEM_B(-0X3, ctx->r5) = ctx->r2;
    // 0x800619B4: sh          $v1, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r3;
L_800619B8:
    // 0x800619B8: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x800619BC: bnel        $at, $zero, L_80061A18
    if (ctx->r1 != 0) {
        // 0x800619C0: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_80061A18;
    }
    goto skip_3;
    // 0x800619C0: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_3:
    // 0x800619C4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800619C8: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x800619CC: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x800619D0: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x800619D4: lw          $t2, 0x10($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X10);
    // 0x800619D8: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x800619DC: lw          $t4, 0x18($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X18);
    // 0x800619E0: lw          $t5, 0x1C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X1C);
    // 0x800619E4: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x800619E8: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x800619EC: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
    // 0x800619F0: sw          $v0, -0x20($a1)
    MEM_W(-0X20, ctx->r5) = ctx->r2;
    // 0x800619F4: sw          $v1, -0x1C($a1)
    MEM_W(-0X1C, ctx->r5) = ctx->r3;
    // 0x800619F8: sw          $t0, -0x18($a1)
    MEM_W(-0X18, ctx->r5) = ctx->r8;
    // 0x800619FC: sw          $t1, -0x14($a1)
    MEM_W(-0X14, ctx->r5) = ctx->r9;
    // 0x80061A00: sw          $t2, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->r10;
    // 0x80061A04: sw          $t3, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->r11;
    // 0x80061A08: sw          $t4, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->r12;
    // 0x80061A0C: b           L_800619B8
    // 0x80061A10: sw          $t5, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r13;
        goto L_800619B8;
    // 0x80061A10: sw          $t5, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r13;
L_80061A14:
    // 0x80061A14: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_80061A18:
    // 0x80061A18: bnel        $at, $zero, L_80061A54
    if (ctx->r1 != 0) {
        // 0x80061A1C: slti        $at, $a2, 0x4
        ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
            goto L_80061A54;
    }
    goto skip_4;
    // 0x80061A1C: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    skip_4:
    // 0x80061A20: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80061A24: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x80061A28: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x80061A2C: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x80061A30: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80061A34: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80061A38: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
    // 0x80061A3C: sw          $v0, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->r2;
    // 0x80061A40: sw          $v1, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->r3;
    // 0x80061A44: sw          $t0, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->r8;
    // 0x80061A48: b           L_80061A14
    // 0x80061A4C: sw          $t1, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r9;
        goto L_80061A14;
    // 0x80061A4C: sw          $t1, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r9;
L_80061A50:
    // 0x80061A50: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
L_80061A54:
    // 0x80061A54: bne         $at, $zero, L_8006192C
    if (ctx->r1 != 0) {
        // 0x80061A58: nop
    
            goto L_8006192C;
    }
    // 0x80061A58: nop

    // 0x80061A5C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80061A60: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80061A64: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80061A68: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x80061A6C: b           L_80061A50
    // 0x80061A70: sw          $v0, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r2;
        goto L_80061A50;
    // 0x80061A70: sw          $v0, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r2;
    // 0x80061A74: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_80061A78:
    // 0x80061A78: add         $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x80061A7C: bne         $at, $zero, L_80061A94
    if (ctx->r1 != 0) {
        // 0x80061A80: add         $a1, $a1, $a2
        ctx->r5 = ADD32(ctx->r5, ctx->r6);
            goto L_80061A94;
    }
    // 0x80061A80: add         $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    // 0x80061A84: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
    // 0x80061A88: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x80061A8C: beq         $v0, $v1, L_80061AC4
    if (ctx->r2 == ctx->r3) {
        // 0x80061A90: nop
    
            goto L_80061AC4;
    }
    // 0x80061A90: nop

L_80061A94:
    // 0x80061A94: beq         $a2, $zero, L_8006194C
    if (ctx->r6 == 0) {
        // 0x80061A98: nop
    
            goto L_8006194C;
    }
    // 0x80061A98: nop

    // 0x80061A9C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80061AA0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80061AA4: subu        $v1, $a0, $a2
    ctx->r3 = SUB32(ctx->r4, ctx->r6);
L_80061AA8:
    // 0x80061AA8: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x80061AAC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80061AB0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80061AB4: bne         $a0, $v1, L_80061AA8
    if (ctx->r4 != ctx->r3) {
        // 0x80061AB8: sb          $v0, 0x1($a1)
        MEM_B(0X1, ctx->r5) = ctx->r2;
            goto L_80061AA8;
    }
    // 0x80061AB8: sb          $v0, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r2;
    // 0x80061ABC: jr          $ra
    // 0x80061AC0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    TRACE_RETURN()
    return;
    // 0x80061AC0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_80061AC4:
    // 0x80061AC4: beq         $v0, $zero, L_80061B28
    if (ctx->r2 == 0) {
        // 0x80061AC8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80061B28;
    }
    // 0x80061AC8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80061ACC: beq         $v0, $at, L_80061B0C
    if (ctx->r2 == ctx->r1) {
        // 0x80061AD0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80061B0C;
    }
    // 0x80061AD0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80061AD4: beql        $v0, $at, L_80061AF8
    if (ctx->r2 == ctx->r1) {
        // 0x80061AD8: lh          $v0, -0x2($a0)
        ctx->r2 = MEM_H(ctx->r4, -0X2);
            goto L_80061AF8;
    }
    goto skip_5;
    // 0x80061AD8: lh          $v0, -0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, -0X2);
    skip_5:
    // 0x80061ADC: lb          $v0, -0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, -0X1);
    // 0x80061AE0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80061AE4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80061AE8: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80061AEC: b           L_80061B28
    // 0x80061AF0: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
        goto L_80061B28;
    // 0x80061AF0: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x80061AF4: lh          $v0, -0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, -0X2);
L_80061AF8:
    // 0x80061AF8: addiu       $a0, $a0, -0x2
    ctx->r4 = ADD32(ctx->r4, -0X2);
    // 0x80061AFC: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
    // 0x80061B00: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x80061B04: b           L_80061B28
    // 0x80061B08: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
        goto L_80061B28;
    // 0x80061B08: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
L_80061B0C:
    // 0x80061B0C: lb          $v0, -0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, -0X1);
    // 0x80061B10: lh          $v1, -0x3($a0)
    ctx->r3 = MEM_H(ctx->r4, -0X3);
    // 0x80061B14: addiu       $a0, $a0, -0x3
    ctx->r4 = ADD32(ctx->r4, -0X3);
    // 0x80061B18: addiu       $a1, $a1, -0x3
    ctx->r5 = ADD32(ctx->r5, -0X3);
    // 0x80061B1C: addiu       $a2, $a2, -0x3
    ctx->r6 = ADD32(ctx->r6, -0X3);
    // 0x80061B20: sb          $v0, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r2;
    // 0x80061B24: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
L_80061B28:
    // 0x80061B28: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x80061B2C: bnel        $at, $zero, L_80061B88
    if (ctx->r1 != 0) {
        // 0x80061B30: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_80061B88;
    }
    goto skip_6;
    // 0x80061B30: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_6:
    // 0x80061B34: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x80061B38: lw          $v1, -0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X8);
    // 0x80061B3C: lw          $t0, -0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, -0XC);
    // 0x80061B40: lw          $t1, -0x10($a0)
    ctx->r9 = MEM_W(ctx->r4, -0X10);
    // 0x80061B44: lw          $t2, -0x14($a0)
    ctx->r10 = MEM_W(ctx->r4, -0X14);
    // 0x80061B48: lw          $t3, -0x18($a0)
    ctx->r11 = MEM_W(ctx->r4, -0X18);
    // 0x80061B4C: lw          $t4, -0x1C($a0)
    ctx->r12 = MEM_W(ctx->r4, -0X1C);
    // 0x80061B50: lw          $t5, -0x20($a0)
    ctx->r13 = MEM_W(ctx->r4, -0X20);
    // 0x80061B54: addiu       $a0, $a0, -0x20
    ctx->r4 = ADD32(ctx->r4, -0X20);
    // 0x80061B58: addiu       $a1, $a1, -0x20
    ctx->r5 = ADD32(ctx->r5, -0X20);
    // 0x80061B5C: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
    // 0x80061B60: sw          $v0, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r2;
    // 0x80061B64: sw          $v1, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r3;
    // 0x80061B68: sw          $t0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r8;
    // 0x80061B6C: sw          $t1, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r9;
    // 0x80061B70: sw          $t2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r10;
    // 0x80061B74: sw          $t3, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r11;
    // 0x80061B78: sw          $t4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r12;
    // 0x80061B7C: b           L_80061B28
    // 0x80061B80: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
        goto L_80061B28;
    // 0x80061B80: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
L_80061B84:
    // 0x80061B84: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_80061B88:
    // 0x80061B88: bnel        $at, $zero, L_80061BC4
    if (ctx->r1 != 0) {
        // 0x80061B8C: slti        $at, $a2, 0x4
        ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
            goto L_80061BC4;
    }
    goto skip_7;
    // 0x80061B8C: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    skip_7:
    // 0x80061B90: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x80061B94: lw          $v1, -0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X8);
    // 0x80061B98: lw          $t0, -0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, -0XC);
    // 0x80061B9C: lw          $t1, -0x10($a0)
    ctx->r9 = MEM_W(ctx->r4, -0X10);
    // 0x80061BA0: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
    // 0x80061BA4: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
    // 0x80061BA8: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
    // 0x80061BAC: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    // 0x80061BB0: sw          $v1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r3;
    // 0x80061BB4: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x80061BB8: b           L_80061B84
    // 0x80061BBC: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
        goto L_80061B84;
    // 0x80061BBC: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
L_80061BC0:
    // 0x80061BC0: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
L_80061BC4:
    // 0x80061BC4: bne         $at, $zero, L_80061A94
    if (ctx->r1 != 0) {
        // 0x80061BC8: nop
    
            goto L_80061A94;
    }
    // 0x80061BC8: nop

    // 0x80061BCC: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x80061BD0: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x80061BD4: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x80061BD8: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x80061BDC: b           L_80061BC0
    // 0x80061BE0: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
        goto L_80061BC0;
    // 0x80061BE0: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
;}
RECOMP_FUNC void func_80061BF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
;}
RECOMP_FUNC void func_80061C40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
;}
RECOMP_FUNC void func_80061CD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80061CD0: lui         $t6, 0xA404
    ctx->r14 = S32(0XA404 << 16);
    // 0x80061CD4: lw          $a0, 0x10($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X10);
    // 0x80061CD8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80061CDC: andi        $t7, $a0, 0x1C
    ctx->r15 = ctx->r4 & 0X1C;
    // 0x80061CE0: beq         $t7, $zero, L_80061CF0
    if (ctx->r15 == 0) {
        // 0x80061CE4: nop
    
            goto L_80061CF0;
    }
    // 0x80061CE4: nop

    // 0x80061CE8: b           L_80061CF4
    // 0x80061CEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80061CF4;
    // 0x80061CEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80061CF0:
    // 0x80061CF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80061CF4:
    // 0x80061CF4: jr          $ra
    // 0x80061CF8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    TRACE_RETURN()
    return;
    // 0x80061CF8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80061D00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80061D00: lui         $t6, 0xA410
    ctx->r14 = S32(0XA410 << 16);
    // 0x80061D04: lw          $a0, 0xC($t6)
    ctx->r4 = MEM_W(ctx->r14, 0XC);
    // 0x80061D08: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80061D0C: andi        $t7, $a0, 0x100
    ctx->r15 = ctx->r4 & 0X100;
    // 0x80061D10: beq         $t7, $zero, L_80061D20
    if (ctx->r15 == 0) {
        // 0x80061D14: nop
    
            goto L_80061D20;
    }
    // 0x80061D14: nop

    // 0x80061D18: b           L_80061D24
    // 0x80061D1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80061D24;
    // 0x80061D1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80061D20:
    // 0x80061D20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80061D24:
    // 0x80061D24: jr          $ra
    // 0x80061D28: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    TRACE_RETURN()
    return;
    // 0x80061D28: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80061D30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80061D30: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80061D34: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x80061D38: sw          $a2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r6;
    // 0x80061D3C: sh          $zero, 0xC($a0)
    MEM_H(0XC, ctx->r4) = 0;
    // 0x80061D40: sh          $zero, 0xE($a0)
    MEM_H(0XE, ctx->r4) = 0;
    // 0x80061D44: jr          $ra
    // 0x80061D48: sw          $a3, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r7;
    TRACE_RETURN()
    return;
    // 0x80061D48: sw          $a3, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r7;
;}
RECOMP_FUNC void func_80061D50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80061D50: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x80061D54: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80061D58: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80061D5C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80061D60: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80061D64: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80061D68: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x80061D6C: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80061D70: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80061D74: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80061D78: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
    // 0x80061D7C: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80061D80: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x80061D84: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80061D88: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x80061D8C: nop

    // 0x80061D90: bc1fl       L_80061DB8
    if (!c1cs) {
        // 0x80061D94: cvt.s.d     $f18, $f0
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f18.fl = CVT_S_D(ctx->f0.d);
            goto L_80061DB8;
    }
    goto skip_0;
    // 0x80061D94: cvt.s.d     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f18.fl = CVT_S_D(ctx->f0.d);
    skip_0:
    // 0x80061D98: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80061D9C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80061DA0: nop

    // 0x80061DA4: sub.d       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f0.d - ctx->f8.d;
    // 0x80061DA8: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x80061DAC: b           L_80061DBC
    // 0x80061DB0: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
        goto L_80061DBC;
    // 0x80061DB0: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
    // 0x80061DB4: cvt.s.d     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f18.fl = CVT_S_D(ctx->f0.d);
L_80061DB8:
    // 0x80061DB8: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
L_80061DBC:
    // 0x80061DBC: lwc1        $f2, 0x14($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80061DC0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80061DC4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80061DC8: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x80061DCC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80061DD0: bc1fl       L_80061DE0
    if (!c1cs) {
        // 0x80061DD4: cvt.d.s     $f4, $f2
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
            goto L_80061DE0;
    }
    goto skip_1;
    // 0x80061DD4: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    skip_1:
    // 0x80061DD8: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80061DDC: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
L_80061DE0:
    // 0x80061DE0: lwc1        $f10, 0x1C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80061DE4: sub.d       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f4.d - ctx->f8.d;
    // 0x80061DE8: cvt.s.d     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f2.fl = CVT_S_D(ctx->f16.d);
    // 0x80061DEC: mul.s       $f0, $f10, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80061DF0: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80061DF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80061DF8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80061DFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80061E00: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // 0x80061E04: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x80061E08: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80061E0C: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x80061E10: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x80061E14: lui         $t2, 0xB00
    ctx->r10 = S32(0XB00 << 16);
    // 0x80061E18: or          $t6, $v0, $at
    ctx->r14 = ctx->r2 | ctx->r1;
    // 0x80061E1C: or          $t1, $t7, $t9
    ctx->r9 = ctx->r15 | ctx->r25;
    // 0x80061E20: ori         $t2, $t2, 0x20
    ctx->r10 = ctx->r10 | 0X20;
    // 0x80061E24: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x80061E28: sw          $t1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r9;
    // 0x80061E2C: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x80061E30: sw          $t2, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r10;
    // 0x80061E34: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80061E38: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80061E3C: jal         0x80053750
    // 0x80061E40: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x80061E40: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_0:
    // 0x80061E44: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80061E48: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80061E4C: lui         $at, 0xE00
    ctx->r1 = S32(0XE00 << 16);
    // 0x80061E50: addiu       $v1, $a3, 0x10
    ctx->r3 = ADD32(ctx->r7, 0X10);
    // 0x80061E54: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x80061E58: sw          $v0, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r2;
    // 0x80061E5C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80061E60: lw          $t4, 0x2C($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X2C);
    // 0x80061E64: lh          $t7, 0x2($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X2);
    // 0x80061E68: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x80061E6C: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x80061E70: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x80061E74: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x80061E78: or          $t1, $t8, $t9
    ctx->r9 = ctx->r24 | ctx->r25;
    // 0x80061E7C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80061E80: lw          $a0, 0x28($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X28);
    // 0x80061E84: jal         0x80053750
    // 0x80061E88: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x80061E88: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_1:
    // 0x80061E8C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80061E90: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80061E94: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x80061E98: sw          $zero, 0x2C($t0)
    MEM_W(0X2C, ctx->r8) = 0;
    // 0x80061E9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80061EA0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80061EA4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80061EA8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80061EB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80061EB0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80061EB4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80061EB8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80061EBC: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x80061EC0: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x80061EC4: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x80061EC8: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x80061ECC: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x80061ED0: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x80061ED4: or          $t5, $a2, $zero
    ctx->r13 = ctx->r6 | 0;
    // 0x80061ED8: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x80061EDC: beq         $at, $zero, L_80061EE8
    if (ctx->r1 == 0) {
        // 0x80061EE0: addu        $t1, $v0, $t6
        ctx->r9 = ADD32(ctx->r2, ctx->r14);
            goto L_80061EE8;
    }
    // 0x80061EE0: addu        $t1, $v0, $t6
    ctx->r9 = ADD32(ctx->r2, ctx->r14);
    // 0x80061EE4: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
L_80061EE8:
    // 0x80061EE8: sll         $a2, $t3, 1
    ctx->r6 = S32(ctx->r11 << 1);
    // 0x80061EEC: addu        $a3, $a2, $a1
    ctx->r7 = ADD32(ctx->r6, ctx->r5);
    // 0x80061EF0: sltu        $at, $t1, $a3
    ctx->r1 = ctx->r9 < ctx->r7 ? 1 : 0;
    // 0x80061EF4: beq         $at, $zero, L_80061FE8
    if (ctx->r1 == 0) {
        // 0x80061EF8: addiu       $s0, $t0, 0x8
        ctx->r16 = ADD32(ctx->r8, 0X8);
            goto L_80061FE8;
    }
    // 0x80061EF8: addiu       $s0, $t0, 0x8
    ctx->r16 = ADD32(ctx->r8, 0X8);
    // 0x80061EFC: subu        $t3, $t1, $a1
    ctx->r11 = SUB32(ctx->r9, ctx->r5);
    // 0x80061F00: sra         $t8, $t3, 1
    ctx->r24 = S32(SIGNED(ctx->r11) >> 1);
    // 0x80061F04: lui         $t7, 0x800
    ctx->r15 = S32(0X800 << 16);
    // 0x80061F08: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80061F0C: sll         $t3, $t8, 1
    ctx->r11 = S32(ctx->r24 << 1);
    // 0x80061F10: andi        $t8, $t3, 0xFFFF
    ctx->r24 = ctx->r11 & 0XFFFF;
    // 0x80061F14: sll         $t7, $t5, 16
    ctx->r15 = S32(ctx->r13 << 16);
    // 0x80061F18: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80061F1C: addiu       $s0, $t0, 0x8
    ctx->r16 = ADD32(ctx->r8, 0X8);
    // 0x80061F20: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x80061F24: or          $t4, $s0, $zero
    ctx->r12 = ctx->r16 | 0;
    // 0x80061F28: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x80061F2C: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80061F30: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    // 0x80061F34: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
    // 0x80061F38: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80061F3C: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x80061F40: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x80061F44: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x80061F48: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x80061F4C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80061F50: jal         0x80053750
    // 0x80061F54: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x80061F54: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80061F58: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x80061F5C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80061F60: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x80061F64: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80061F68: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x80061F6C: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80061F70: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80061F74: lui         $t7, 0x800
    ctx->r15 = S32(0X800 << 16);
    // 0x80061F78: sw          $v0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r2;
    // 0x80061F7C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80061F80: subu        $t7, $a3, $t1
    ctx->r15 = SUB32(ctx->r7, ctx->r9);
    // 0x80061F84: addu        $t9, $t3, $t5
    ctx->r25 = ADD32(ctx->r11, ctx->r13);
    // 0x80061F88: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x80061F8C: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x80061F90: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80061F94: andi        $t7, $t9, 0xFFFF
    ctx->r15 = ctx->r25 & 0XFFFF;
    // 0x80061F98: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80061F9C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80061FA0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80061FA4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80061FA8: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x80061FAC: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80061FB0: lw          $a0, 0x14($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X14);
    // 0x80061FB4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80061FB8: jal         0x80053750
    // 0x80061FBC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x80061FBC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    after_1:
    // 0x80061FC0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80061FC4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80061FC8: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80061FCC: lui         $t6, 0x800
    ctx->r14 = S32(0X800 << 16);
    // 0x80061FD0: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x80061FD4: andi        $t7, $a2, 0xFFFF
    ctx->r15 = ctx->r6 & 0XFFFF;
    // 0x80061FD8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80061FDC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80061FE0: b           L_80062024
    // 0x80061FE4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_80062024;
    // 0x80061FE4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_80061FE8:
    // 0x80061FE8: lui         $t8, 0x800
    ctx->r24 = S32(0X800 << 16);
    // 0x80061FEC: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80061FF0: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x80061FF4: andi        $t7, $a2, 0xFFFF
    ctx->r15 = ctx->r6 & 0XFFFF;
    // 0x80061FF8: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80061FFC: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x80062000: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80062004: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x80062008: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8006200C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x80062010: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80062014: jal         0x80053750
    // 0x80062018: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x80062018: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x8006201C: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80062020: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_80062024:
    // 0x80062024: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80062028: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8006202C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80062030: jr          $ra
    // 0x80062034: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    TRACE_RETURN()
    return;
    // 0x80062034: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80062038(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80062038: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8006203C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80062040: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80062044: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x80062048: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x8006204C: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x80062050: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x80062054: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x80062058: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x8006205C: or          $t5, $a2, $zero
    ctx->r13 = ctx->r6 | 0;
    // 0x80062060: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x80062064: beq         $at, $zero, L_80062070
    if (ctx->r1 == 0) {
        // 0x80062068: addu        $t1, $v0, $t6
        ctx->r9 = ADD32(ctx->r2, ctx->r14);
            goto L_80062070;
    }
    // 0x80062068: addu        $t1, $v0, $t6
    ctx->r9 = ADD32(ctx->r2, ctx->r14);
    // 0x8006206C: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
L_80062070:
    // 0x80062070: sll         $a2, $t3, 1
    ctx->r6 = S32(ctx->r11 << 1);
    // 0x80062074: addu        $a3, $a2, $a1
    ctx->r7 = ADD32(ctx->r6, ctx->r5);
    // 0x80062078: sltu        $at, $t1, $a3
    ctx->r1 = ctx->r9 < ctx->r7 ? 1 : 0;
    // 0x8006207C: beq         $at, $zero, L_8006215C
    if (ctx->r1 == 0) {
        // 0x80062080: addiu       $s0, $t0, 0x8
        ctx->r16 = ADD32(ctx->r8, 0X8);
            goto L_8006215C;
    }
    // 0x80062080: addiu       $s0, $t0, 0x8
    ctx->r16 = ADD32(ctx->r8, 0X8);
    // 0x80062084: andi        $t7, $t5, 0xFFFF
    ctx->r15 = ctx->r13 & 0XFFFF;
    // 0x80062088: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8006208C: subu        $t3, $t1, $a1
    ctx->r11 = SUB32(ctx->r9, ctx->r5);
    // 0x80062090: sra         $t9, $t3, 1
    ctx->r25 = S32(SIGNED(ctx->r11) >> 1);
    // 0x80062094: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80062098: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x8006209C: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800620A0: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x800620A4: addiu       $s0, $t0, 0x8
    ctx->r16 = ADD32(ctx->r8, 0X8);
    // 0x800620A8: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x800620AC: or          $t4, $s0, $zero
    ctx->r12 = ctx->r16 | 0;
    // 0x800620B0: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x800620B4: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x800620B8: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    // 0x800620BC: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
    // 0x800620C0: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x800620C4: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x800620C8: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x800620CC: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x800620D0: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x800620D4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800620D8: jal         0x80053750
    // 0x800620DC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x800620DC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800620E0: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800620E4: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x800620E8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800620EC: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800620F0: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x800620F4: addu        $t9, $t3, $t5
    ctx->r25 = ADD32(ctx->r11, ctx->r13);
    // 0x800620F8: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x800620FC: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x80062100: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80062104: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80062108: subu        $t8, $a3, $t1
    ctx->r24 = SUB32(ctx->r7, ctx->r9);
    // 0x8006210C: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80062110: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80062114: sw          $v0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r2;
    // 0x80062118: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8006211C: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x80062120: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x80062124: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80062128: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8006212C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80062130: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x80062134: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80062138: lw          $a0, 0x14($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X14);
    // 0x8006213C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80062140: jal         0x80053750
    // 0x80062144: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x80062144: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    after_1:
    // 0x80062148: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8006214C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80062150: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x80062154: b           L_800621A0
    // 0x80062158: andi        $a3, $a2, 0xFFFF
    ctx->r7 = ctx->r6 & 0XFFFF;
        goto L_800621A0;
    // 0x80062158: andi        $a3, $a2, 0xFFFF
    ctx->r7 = ctx->r6 & 0XFFFF;
L_8006215C:
    // 0x8006215C: andi        $t9, $t5, 0xFFFF
    ctx->r25 = ctx->r13 & 0XFFFF;
    // 0x80062160: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x80062164: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x80062168: andi        $a3, $a2, 0xFFFF
    ctx->r7 = ctx->r6 & 0XFFFF;
    // 0x8006216C: sw          $a3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r7;
    // 0x80062170: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80062174: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80062178: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x8006217C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80062180: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x80062184: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x80062188: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8006218C: jal         0x80053750
    // 0x80062190: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x80062190: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x80062194: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80062198: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8006219C: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_800621A0:
    // 0x800621A0: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800621A4: lui         $t8, 0x800
    ctx->r24 = S32(0X800 << 16);
    // 0x800621A8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800621AC: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x800621B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800621B4: addiu       $v0, $s0, 0x8
    ctx->r2 = ADD32(ctx->r16, 0X8);
    // 0x800621B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800621BC: jr          $ra
    // 0x800621C0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    TRACE_RETURN()
    return;
    // 0x800621C0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_800621C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800621C4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800621C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800621CC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800621D0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800621D4: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x800621D8: lw          $t6, 0x24($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X24);
    // 0x800621DC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800621E0: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x800621E4: beq         $t6, $zero, L_800623A0
    if (ctx->r14 == 0) {
        // 0x800621E8: or          $t2, $a0, $zero
        ctx->r10 = ctx->r4 | 0;
            goto L_800623A0;
    }
    // 0x800621E8: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x800621EC: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x800621F0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800621F4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800621F8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800621FC: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x80062200: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x80062204: jal         0x80061D50
    // 0x80062208: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    func_80061D50(rdram, ctx);
        goto after_0;
    // 0x80062208: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    after_0:
    // 0x8006220C: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80062210: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x80062214: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80062218: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x8006221C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80062220: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80062224: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80062228: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8006222C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80062230: addiu       $a2, $zero, 0x280
    ctx->r6 = ADD32(0, 0X280);
    // 0x80062234: div.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80062238: mul.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8006223C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80062240: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x80062244: nop

    // 0x80062248: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8006224C: nop

    // 0x80062250: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80062254: div.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80062258: mtc1        $s1, $f8
    ctx->f8.u32l = ctx->r17;
    // 0x8006225C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80062260: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80062264: sub.d       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f4.d - ctx->f16.d;
    // 0x80062268: cvt.s.d     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f2.fl = CVT_S_D(ctx->f18.d);
    // 0x8006226C: mul.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80062270: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x80062274: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80062278: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8006227C: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80062280: trunc.w.s   $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x80062284: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x80062288: nop

    // 0x8006228C: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x80062290: nop

    // 0x80062294: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80062298: sub.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x8006229C: swc1        $f10, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f10.u32l;
    // 0x800622A0: lw          $t9, 0x18($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X18);
    // 0x800622A4: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x800622A8: lw          $t7, 0x18($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X18);
    // 0x800622AC: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x800622B0: subu        $t4, $t8, $t9
    ctx->r12 = SUB32(ctx->r24, ctx->r25);
    // 0x800622B4: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x800622B8: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800622BC: addu        $t0, $t7, $t6
    ctx->r8 = ADD32(ctx->r15, ctx->r14);
    // 0x800622C0: andi        $v1, $t0, 0x7
    ctx->r3 = ctx->r8 & 0X7;
    // 0x800622C4: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x800622C8: sra         $t8, $v1, 1
    ctx->r24 = S32(SIGNED(ctx->r3) >> 1);
    // 0x800622CC: sll         $t3, $t8, 1
    ctx->r11 = S32(ctx->r24 << 1);
    // 0x800622D0: subu        $a1, $t0, $t3
    ctx->r5 = SUB32(ctx->r8, ctx->r11);
    // 0x800622D4: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x800622D8: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800622DC: addu        $a3, $t1, $t8
    ctx->r7 = ADD32(ctx->r9, ctx->r24);
    // 0x800622E0: jal         0x80062038
    // 0x800622E4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_80062038(rdram, ctx);
        goto after_1;
    // 0x800622E4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_1:
    // 0x800622E8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800622EC: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800622F0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800622F4: addiu       $t4, $t3, 0x280
    ctx->r12 = ADD32(ctx->r11, 0X280);
    // 0x800622F8: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x800622FC: or          $t7, $t5, $at
    ctx->r15 = ctx->r13 | ctx->r1;
    // 0x80062300: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80062304: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x80062308: sll         $t4, $s1, 1
    ctx->r12 = S32(ctx->r17 << 1);
    // 0x8006230C: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x80062310: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80062314: or          $t7, $t9, $t5
    ctx->r15 = ctx->r25 | ctx->r13;
    // 0x80062318: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8006231C: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x80062320: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80062324: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80062328: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x8006232C: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x80062330: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80062334: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x80062338: lw          $t7, 0x24($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X24);
    // 0x8006233C: addiu       $v1, $v0, 0x10
    ctx->r3 = ADD32(ctx->r2, 0X10);
    // 0x80062340: andi        $t6, $t7, 0xFF
    ctx->r14 = ctx->r15 & 0XFF;
    // 0x80062344: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x80062348: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8006234C: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x80062350: nop

    // 0x80062354: andi        $t9, $t4, 0xFFFF
    ctx->r25 = ctx->r12 & 0XFFFF;
    // 0x80062358: or          $t4, $t8, $at
    ctx->r12 = ctx->r24 | ctx->r1;
    // 0x8006235C: or          $t5, $t4, $t9
    ctx->r13 = ctx->r12 | ctx->r25;
    // 0x80062360: sw          $t5, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r13;
    // 0x80062364: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x80062368: lw          $a0, 0x14($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X14);
    // 0x8006236C: jal         0x80053750
    // 0x80062370: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x80062370: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80062374: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80062378: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8006237C: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x80062380: sw          $v0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r2;
    // 0x80062384: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x80062388: sw          $zero, 0x24($t8)
    MEM_W(0X24, ctx->r24) = 0;
    // 0x8006238C: lw          $t4, 0x18($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X18);
    // 0x80062390: addu        $t9, $t4, $t1
    ctx->r25 = ADD32(ctx->r12, ctx->r9);
    // 0x80062394: subu        $t5, $t9, $s1
    ctx->r13 = SUB32(ctx->r25, ctx->r17);
    // 0x80062398: b           L_800623D0
    // 0x8006239C: sw          $t5, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r13;
        goto L_800623D0;
    // 0x8006239C: sw          $t5, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r13;
L_800623A0:
    // 0x800623A0: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x800623A4: lw          $t7, 0x18($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X18);
    // 0x800623A8: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x800623AC: negu        $t8, $t6
    ctx->r24 = SUB32(0, ctx->r14);
    // 0x800623B0: sll         $t4, $t8, 1
    ctx->r12 = S32(ctx->r24 << 1);
    // 0x800623B4: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800623B8: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x800623BC: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x800623C0: addu        $a1, $t7, $t4
    ctx->r5 = ADD32(ctx->r15, ctx->r12);
    // 0x800623C4: jal         0x80062038
    // 0x800623C8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_80062038(rdram, ctx);
        goto after_3;
    // 0x800623C8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_3:
    // 0x800623CC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800623D0:
    // 0x800623D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800623D4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800623D8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800623DC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x800623E0: jr          $ra
    // 0x800623E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    TRACE_RETURN()
    return;
    // 0x800623E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_800623E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800623E8: addiu       $v1, $a1, -0x2
    ctx->r3 = ADD32(ctx->r5, -0X2);
    // 0x800623EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800623F0: andi        $t6, $v1, 0x7
    ctx->r14 = ctx->r3 & 0X7;
    // 0x800623F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800623F8: sltiu       $at, $t6, 0x8
    ctx->r1 = ctx->r14 < 0X8 ? 1 : 0;
    // 0x800623FC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80062400: beq         $at, $zero, L_80062630
    if (ctx->r1 == 0) {
        // 0x80062404: lw          $t0, 0x0($a2)
        ctx->r8 = MEM_W(ctx->r6, 0X0);
            goto L_80062630;
    }
    // 0x80062404: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x80062408: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8006240C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80062410: addu        $at, $at, $t6
    gpr jr_addend_80062418 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80062414: lw          $t6, -0x6810($at)
    ctx->r14 = ADD32(ctx->r1, -0X6810);
    // 0x80062418: jr          $t6
    // 0x8006241C: nop

    switch (jr_addend_80062418 >> 2) {
        case 0: goto L_80062420; break;
        case 1: goto L_80062454; break;
        case 2: goto L_800624B4; break;
        case 3: goto L_80062488; break;
        case 4: goto L_800624E0; break;
        case 5: goto L_8006250C; break;
        case 6: goto L_80062574; break;
        case 7: goto L_800625EC; break;
        default: switch_error(__func__, 0x80062418, 0x800797F0);
    }
    // 0x8006241C: nop

L_80062420:
    // 0x80062420: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x80062424: and         $t7, $t0, $at
    ctx->r15 = ctx->r8 & ctx->r1;
    // 0x80062428: lw          $t8, 0x20($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X20);
    // 0x8006242C: bgez        $v1, L_8006243C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80062430: sra         $t9, $v1, 3
        ctx->r25 = S32(SIGNED(ctx->r3) >> 3);
            goto L_8006243C;
    }
    // 0x80062430: sra         $t9, $v1, 3
    ctx->r25 = S32(SIGNED(ctx->r3) >> 3);
    // 0x80062434: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x80062438: sra         $t9, $at, 3
    ctx->r25 = S32(SIGNED(ctx->r1) >> 3);
L_8006243C:
    // 0x8006243C: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80062440: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x80062444: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80062448: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x8006244C: b           L_80062630
    // 0x80062450: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
        goto L_80062630;
    // 0x80062450: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
L_80062454:
    // 0x80062454: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x80062458: and         $t3, $t0, $at
    ctx->r11 = ctx->r8 & ctx->r1;
    // 0x8006245C: lw          $t4, 0x20($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X20);
    // 0x80062460: bgez        $v1, L_80062470
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80062464: sra         $t5, $v1, 3
        ctx->r13 = S32(SIGNED(ctx->r3) >> 3);
            goto L_80062470;
    }
    // 0x80062464: sra         $t5, $v1, 3
    ctx->r13 = S32(SIGNED(ctx->r3) >> 3);
    // 0x80062468: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x8006246C: sra         $t5, $at, 3
    ctx->r13 = S32(SIGNED(ctx->r1) >> 3);
L_80062470:
    // 0x80062470: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80062474: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80062478: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8006247C: addu        $t9, $t4, $t6
    ctx->r25 = ADD32(ctx->r12, ctx->r14);
    // 0x80062480: b           L_80062630
    // 0x80062484: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
        goto L_80062630;
    // 0x80062484: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
L_80062488:
    // 0x80062488: lw          $t8, 0x20($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X20);
    // 0x8006248C: bgez        $v1, L_8006249C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80062490: sra         $t1, $v1, 3
        ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
            goto L_8006249C;
    }
    // 0x80062490: sra         $t1, $v1, 3
    ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
    // 0x80062494: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x80062498: sra         $t1, $at, 3
    ctx->r9 = S32(SIGNED(ctx->r1) >> 3);
L_8006249C:
    // 0x8006249C: sll         $t7, $t1, 2
    ctx->r15 = S32(ctx->r9 << 2);
    // 0x800624A0: addu        $t7, $t7, $t1
    ctx->r15 = ADD32(ctx->r15, ctx->r9);
    // 0x800624A4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800624A8: addu        $t2, $t8, $t7
    ctx->r10 = ADD32(ctx->r24, ctx->r15);
    // 0x800624AC: b           L_80062630
    // 0x800624B0: sh          $t0, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r8;
        goto L_80062630;
    // 0x800624B0: sh          $t0, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r8;
L_800624B4:
    // 0x800624B4: lw          $t5, 0x20($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X20);
    // 0x800624B8: bgez        $v1, L_800624C8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800624BC: sra         $t4, $v1, 3
        ctx->r12 = S32(SIGNED(ctx->r3) >> 3);
            goto L_800624C8;
    }
    // 0x800624BC: sra         $t4, $v1, 3
    ctx->r12 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800624C0: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x800624C4: sra         $t4, $at, 3
    ctx->r12 = S32(SIGNED(ctx->r1) >> 3);
L_800624C8:
    // 0x800624C8: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x800624CC: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x800624D0: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800624D4: addu        $t3, $t5, $t6
    ctx->r11 = ADD32(ctx->r13, ctx->r14);
    // 0x800624D8: b           L_80062630
    // 0x800624DC: sh          $t0, 0xA($t3)
    MEM_H(0XA, ctx->r11) = ctx->r8;
        goto L_80062630;
    // 0x800624DC: sh          $t0, 0xA($t3)
    MEM_H(0XA, ctx->r11) = ctx->r8;
L_800624E0:
    // 0x800624E0: lw          $t9, 0x20($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X20);
    // 0x800624E4: bgez        $v1, L_800624F4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800624E8: sra         $t1, $v1, 3
        ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
            goto L_800624F4;
    }
    // 0x800624E8: sra         $t1, $v1, 3
    ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800624EC: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x800624F0: sra         $t1, $at, 3
    ctx->r9 = S32(SIGNED(ctx->r1) >> 3);
L_800624F4:
    // 0x800624F4: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x800624F8: addu        $t8, $t8, $t1
    ctx->r24 = ADD32(ctx->r24, ctx->r9);
    // 0x800624FC: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80062500: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x80062504: b           L_80062630
    // 0x80062508: sh          $t0, 0xC($t7)
    MEM_H(0XC, ctx->r15) = ctx->r8;
        goto L_80062630;
    // 0x80062508: sh          $t0, 0xC($t7)
    MEM_H(0XC, ctx->r15) = ctx->r8;
L_8006250C:
    // 0x8006250C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80062510: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80062514: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80062518: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8006251C: lui         $t2, 0x8007
    ctx->r10 = S32(0X8007 << 16);
    // 0x80062520: lw          $t2, 0x3190($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3190);
    // 0x80062524: lw          $t5, 0x20($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X20);
    // 0x80062528: lw          $t4, 0x44($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X44);
    // 0x8006252C: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80062530: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80062534: nop

    // 0x80062538: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x8006253C: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x80062540: add.d       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = ctx->f0.d + ctx->f0.d;
    // 0x80062544: div.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f16.d, ctx->f4.d);
    // 0x80062548: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8006254C: bgez        $v1, L_8006255C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80062550: sra         $t6, $v1, 3
        ctx->r14 = S32(SIGNED(ctx->r3) >> 3);
            goto L_8006255C;
    }
    // 0x80062550: sra         $t6, $v1, 3
    ctx->r14 = S32(SIGNED(ctx->r3) >> 3);
    // 0x80062554: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x80062558: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_8006255C:
    // 0x8006255C: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x80062560: addu        $t3, $t3, $t6
    ctx->r11 = ADD32(ctx->r11, ctx->r14);
    // 0x80062564: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80062568: addu        $t1, $t5, $t3
    ctx->r9 = ADD32(ctx->r13, ctx->r11);
    // 0x8006256C: b           L_80062630
    // 0x80062570: swc1        $f8, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f8.u32l;
        goto L_80062630;
    // 0x80062570: swc1        $f8, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f8.u32l;
L_80062574:
    // 0x80062574: lw          $t9, 0x20($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X20);
    // 0x80062578: bgez        $v1, L_80062588
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8006257C: sra         $t8, $v1, 3
        ctx->r24 = S32(SIGNED(ctx->r3) >> 3);
            goto L_80062588;
    }
    // 0x8006257C: sra         $t8, $v1, 3
    ctx->r24 = S32(SIGNED(ctx->r3) >> 3);
    // 0x80062580: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x80062584: sra         $t8, $at, 3
    ctx->r24 = S32(SIGNED(ctx->r1) >> 3);
L_80062588:
    // 0x80062588: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8006258C: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x80062590: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80062594: addu        $v0, $t9, $t7
    ctx->r2 = ADD32(ctx->r25, ctx->r15);
    // 0x80062598: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x8006259C: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x800625A0: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800625A4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800625A8: subu        $t6, $t2, $t4
    ctx->r14 = SUB32(ctx->r10, ctx->r12);
    // 0x800625AC: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800625B0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800625B4: bgez        $t6, L_800625CC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800625B8: cvt.d.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
            goto L_800625CC;
    }
    // 0x800625B8: cvt.d.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
    // 0x800625BC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800625C0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800625C4: nop

    // 0x800625C8: add.d       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f18.d + ctx->f16.d;
L_800625CC:
    // 0x800625CC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800625D0: ldc1        $f10, -0x67F0($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X67F0);
    // 0x800625D4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800625D8: div.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x800625DC: mul.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f16.d);
    // 0x800625E0: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800625E4: b           L_80062630
    // 0x800625E8: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
        goto L_80062630;
    // 0x800625E8: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
L_800625EC:
    // 0x800625EC: bgez        $v1, L_800625FC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800625F0: sra         $v0, $v1, 3
        ctx->r2 = S32(SIGNED(ctx->r3) >> 3);
            goto L_800625FC;
    }
    // 0x800625F0: sra         $v0, $v1, 3
    ctx->r2 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800625F4: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x800625F8: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_800625FC:
    // 0x800625FC: lw          $t3, 0x20($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X20);
    // 0x80062600: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x80062604: addu        $t5, $t5, $v0
    ctx->r13 = ADD32(ctx->r13, ctx->r2);
    // 0x80062608: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8006260C: addu        $t1, $t3, $t5
    ctx->r9 = ADD32(ctx->r11, ctx->r13);
    // 0x80062610: lw          $a1, 0x20($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X20);
    // 0x80062614: beql        $a1, $zero, L_80062634
    if (ctx->r5 == 0) {
        // 0x80062618: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80062634;
    }
    goto skip_0;
    // 0x80062618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8006261C: sh          $t0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r8;
    // 0x80062620: lw          $t8, 0x20($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X20);
    // 0x80062624: addu        $t9, $t8, $t5
    ctx->r25 = ADD32(ctx->r24, ctx->r13);
    // 0x80062628: jal         0x8005A240
    // 0x8006262C: lw          $a0, 0x20($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X20);
    func_8005A240(rdram, ctx);
        goto after_0;
    // 0x8006262C: lw          $a0, 0x20($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X20);
    after_0:
L_80062630:
    // 0x80062630: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80062634:
    // 0x80062634: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062638: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006263C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80062644(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80062644: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80062648: bne         $a1, $at, L_80062654
    if (ctx->r5 != ctx->r1) {
        // 0x8006264C: nop
    
            goto L_80062654;
    }
    // 0x8006264C: nop

    // 0x80062650: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
L_80062654:
    // 0x80062654: jr          $ra
    // 0x80062658: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    TRACE_RETURN()
    return;
    // 0x80062658: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_8006265C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8006265C: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x80062660: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80062664: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80062668: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8006266C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80062670: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80062674: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80062678: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8006267C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80062680: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80062684: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80062688: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8006268C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80062690: lw          $t6, 0xB8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB8);
    // 0x80062694: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
    // 0x80062698: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x8006269C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800626A0: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x800626A4: jalr        $t9
    // 0x800626A8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800626A8: nop

    after_0:
    // 0x800626AC: sll         $s1, $s6, 1
    ctx->r17 = S32(ctx->r22 << 1);
    // 0x800626B0: lui         $t8, 0xC00
    ctx->r24 = S32(0XC00 << 16);
    // 0x800626B4: lui         $t2, 0x6C0
    ctx->r10 = S32(0X6C0 << 16);
    // 0x800626B8: lui         $t3, 0xC00
    ctx->r11 = S32(0XC00 << 16);
    // 0x800626BC: lui         $t4, 0x800
    ctx->r12 = S32(0X800 << 16);
    // 0x800626C0: andi        $t1, $s1, 0xFFFF
    ctx->r9 = ctx->r17 & 0XFFFF;
    // 0x800626C4: lui         $t7, 0x800
    ctx->r15 = S32(0X800 << 16);
    // 0x800626C8: ori         $t2, $t2, 0x6C0
    ctx->r10 = ctx->r10 | 0X6C0;
    // 0x800626CC: ori         $t8, $t8, 0xDA83
    ctx->r24 = ctx->r24 | 0XDA83;
    // 0x800626D0: ori         $t4, $t4, 0x6C0
    ctx->r12 = ctx->r12 | 0X6C0;
    // 0x800626D4: ori         $t3, $t3, 0x5A82
    ctx->r11 = ctx->r11 | 0X5A82;
    // 0x800626D8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800626DC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800626E0: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x800626E4: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x800626E8: sw          $t3, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r11;
    // 0x800626EC: sw          $t4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r12;
    // 0x800626F0: lw          $a1, 0x18($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X18);
    // 0x800626F4: addiu       $t5, $v0, 0x18
    ctx->r13 = ADD32(ctx->r2, 0X18);
    // 0x800626F8: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800626FC: addiu       $s2, $zero, 0x140
    ctx->r18 = ADD32(0, 0X140);
    // 0x80062700: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80062704: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
    // 0x80062708: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x8006270C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80062710: addiu       $a2, $zero, 0x6C0
    ctx->r6 = ADD32(0, 0X6C0);
    // 0x80062714: jal         0x80061EB0
    // 0x80062718: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    func_80061EB0(rdram, ctx);
        goto after_1;
    // 0x80062718: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_1:
    // 0x8006271C: lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X80);
    // 0x80062720: lui         $t6, 0x200
    ctx->r14 = S32(0X200 << 16);
    // 0x80062724: ori         $t6, $t6, 0x800
    ctx->r14 = ctx->r14 | 0X800;
    // 0x80062728: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8006272C: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x80062730: lbu         $t9, 0x24($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X24);
    // 0x80062734: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x80062738: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x8006273C: blezl       $t9, L_8006291C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80062740: lw          $v1, 0x1C($s3)
        ctx->r3 = MEM_W(ctx->r19, 0X1C);
            goto L_8006291C;
    }
    goto skip_0;
    // 0x80062740: lw          $v1, 0x1C($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X1C);
    skip_0:
    // 0x80062744: lw          $v0, 0x18($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X18);
L_80062748:
    // 0x80062748: lw          $t7, 0x20($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X20);
    // 0x8006274C: sll         $t8, $s7, 2
    ctx->r24 = S32(ctx->r23 << 2);
    // 0x80062750: addu        $t8, $t8, $s7
    ctx->r24 = ADD32(ctx->r24, ctx->r23);
    // 0x80062754: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80062758: addu        $s1, $t7, $t8
    ctx->r17 = ADD32(ctx->r15, ctx->r24);
    // 0x8006275C: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80062760: lw          $t5, 0x4($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X4);
    // 0x80062764: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80062768: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x8006276C: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80062770: negu        $t6, $t5
    ctx->r14 = SUB32(0, ctx->r13);
    // 0x80062774: addu        $s4, $v0, $t4
    ctx->r20 = ADD32(ctx->r2, ctx->r12);
    // 0x80062778: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x8006277C: bne         $s4, $v1, L_800627A4
    if (ctx->r20 != ctx->r3) {
        // 0x80062780: addu        $fp, $v0, $t9
        ctx->r30 = ADD32(ctx->r2, ctx->r25);
            goto L_800627A4;
    }
    // 0x80062780: addu        $fp, $v0, $t9
    ctx->r30 = ADD32(ctx->r2, ctx->r25);
    // 0x80062784: or          $t7, $s2, $zero
    ctx->r15 = ctx->r18 | 0;
    // 0x80062788: sll         $s2, $s5, 16
    ctx->r18 = S32(ctx->r21 << 16);
    // 0x8006278C: sll         $s5, $t7, 16
    ctx->r21 = S32(ctx->r15 << 16);
    // 0x80062790: sra         $t2, $s5, 16
    ctx->r10 = S32(SIGNED(ctx->r21) >> 16);
    // 0x80062794: sra         $t8, $s2, 16
    ctx->r24 = S32(SIGNED(ctx->r18) >> 16);
    // 0x80062798: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
    // 0x8006279C: b           L_800627BC
    // 0x800627A0: or          $s5, $t2, $zero
    ctx->r21 = ctx->r10 | 0;
        goto L_800627BC;
    // 0x800627A0: or          $s5, $t2, $zero
    ctx->r21 = ctx->r10 | 0;
L_800627A4:
    // 0x800627A4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800627A8: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800627AC: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x800627B0: jal         0x80062038
    // 0x800627B4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_80062038(rdram, ctx);
        goto after_2;
    // 0x800627B4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_2:
    // 0x800627B8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800627BC:
    // 0x800627BC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800627C0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800627C4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800627C8: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x800627CC: jal         0x800621C4
    // 0x800627D0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_800621C4(rdram, ctx);
        goto after_3;
    // 0x800627D0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_3:
    // 0x800627D4: lh          $a0, 0x8($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X8);
    // 0x800627D8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800627DC: lui         $at, 0xC00
    ctx->r1 = S32(0XC00 << 16);
    // 0x800627E0: beq         $a0, $zero, L_80062834
    if (ctx->r4 == 0) {
        // 0x800627E4: andi        $t4, $a0, 0xFFFF
        ctx->r12 = ctx->r4 & 0XFFFF;
            goto L_80062834;
    }
    // 0x800627E4: andi        $t4, $a0, 0xFFFF
    ctx->r12 = ctx->r4 & 0XFFFF;
    // 0x800627E8: sll         $t9, $s5, 16
    ctx->r25 = S32(ctx->r21 << 16);
    // 0x800627EC: andi        $t7, $s2, 0xFFFF
    ctx->r15 = ctx->r18 & 0XFFFF;
    // 0x800627F0: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x800627F4: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x800627F8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800627FC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80062800: lw          $t2, 0x24($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X24);
    // 0x80062804: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x80062808: bnel        $t2, $zero, L_80062838
    if (ctx->r10 != 0) {
        // 0x8006280C: lh          $v1, 0xA($s1)
        ctx->r3 = MEM_H(ctx->r17, 0XA);
            goto L_80062838;
    }
    goto skip_1;
    // 0x8006280C: lh          $v1, 0xA($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XA);
    skip_1:
    // 0x80062810: lw          $t3, 0x20($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X20);
    // 0x80062814: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80062818: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x8006281C: bne         $t3, $zero, L_80062834
    if (ctx->r11 != 0) {
        // 0x80062820: or          $a2, $s2, $zero
        ctx->r6 = ctx->r18 | 0;
            goto L_80062834;
    }
    // 0x80062820: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80062824: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x80062828: jal         0x80061EB0
    // 0x8006282C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_80061EB0(rdram, ctx);
        goto after_4;
    // 0x8006282C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_4:
    // 0x80062830: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80062834:
    // 0x80062834: lh          $v1, 0xA($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XA);
L_80062838:
    // 0x80062838: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8006283C: lui         $at, 0xC00
    ctx->r1 = S32(0XC00 << 16);
    // 0x80062840: beq         $v1, $zero, L_80062880
    if (ctx->r3 == 0) {
        // 0x80062844: andi        $t5, $v1, 0xFFFF
        ctx->r13 = ctx->r3 & 0XFFFF;
            goto L_80062880;
    }
    // 0x80062844: andi        $t5, $v1, 0xFFFF
    ctx->r13 = ctx->r3 & 0XFFFF;
    // 0x80062848: sll         $t7, $s2, 16
    ctx->r15 = S32(ctx->r18 << 16);
    // 0x8006284C: andi        $t8, $s5, 0xFFFF
    ctx->r24 = ctx->r21 & 0XFFFF;
    // 0x80062850: or          $t2, $t7, $t8
    ctx->r10 = ctx->r15 | ctx->r24;
    // 0x80062854: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x80062858: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8006285C: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80062860: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80062864: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80062868: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8006286C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80062870: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80062874: jal         0x80061EB0
    // 0x80062878: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    func_80061EB0(rdram, ctx);
        goto after_5;
    // 0x80062878: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_5:
    // 0x8006287C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80062880:
    // 0x80062880: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x80062884: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80062888: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x8006288C: beql        $a0, $zero, L_800628A4
    if (ctx->r4 == 0) {
        // 0x80062890: lw          $t3, 0x24($s1)
        ctx->r11 = MEM_W(ctx->r17, 0X24);
            goto L_800628A4;
    }
    goto skip_2;
    // 0x80062890: lw          $t3, 0x24($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X24);
    skip_2:
    // 0x80062894: jal         0x80061DF8
    // 0x80062898: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_80061DF8(rdram, ctx);
        goto after_6;
    // 0x80062898: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_6:
    // 0x8006289C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800628A0: lw          $t3, 0x24($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X24);
L_800628A4:
    // 0x800628A4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800628A8: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x800628AC: bne         $t3, $zero, L_800628C4
    if (ctx->r11 != 0) {
        // 0x800628B0: or          $a2, $s2, $zero
        ctx->r6 = ctx->r18 | 0;
            goto L_800628C4;
    }
    // 0x800628B0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800628B4: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x800628B8: jal         0x80061EB0
    // 0x800628BC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_80061EB0(rdram, ctx);
        goto after_7;
    // 0x800628BC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_7:
    // 0x800628C0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800628C4:
    // 0x800628C4: lh          $v1, 0xC($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XC);
    // 0x800628C8: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800628CC: sll         $t4, $s7, 16
    ctx->r12 = S32(ctx->r23 << 16);
    // 0x800628D0: beq         $v1, $zero, L_800628FC
    if (ctx->r3 == 0) {
        // 0x800628D4: sra         $s7, $t4, 16
        ctx->r23 = S32(SIGNED(ctx->r12) >> 16);
            goto L_800628FC;
    }
    // 0x800628D4: sra         $s7, $t4, 16
    ctx->r23 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800628D8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800628DC: andi        $t5, $v1, 0xFFFF
    ctx->r13 = ctx->r3 & 0XFFFF;
    // 0x800628E0: lui         $at, 0xC00
    ctx->r1 = S32(0XC00 << 16);
    // 0x800628E4: sll         $t7, $s2, 16
    ctx->r15 = S32(ctx->r18 << 16);
    // 0x800628E8: ori         $t8, $t7, 0x800
    ctx->r24 = ctx->r15 | 0X800;
    // 0x800628EC: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x800628F0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800628F4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800628F8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_800628FC:
    // 0x800628FC: lbu         $t6, 0x24($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X24);
    // 0x80062900: lw          $t2, 0x4($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4);
    // 0x80062904: lw          $v0, 0x18($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X18);
    // 0x80062908: slt         $at, $s7, $t6
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8006290C: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80062910: bne         $at, $zero, L_80062748
    if (ctx->r1 != 0) {
        // 0x80062914: addu        $v1, $v0, $t3
        ctx->r3 = ADD32(ctx->r2, ctx->r11);
            goto L_80062748;
    }
    // 0x80062914: addu        $v1, $v0, $t3
    ctx->r3 = ADD32(ctx->r2, ctx->r11);
    // 0x80062918: lw          $v1, 0x1C($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X1C);
L_8006291C:
    // 0x8006291C: lw          $t9, 0x18($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X18);
    // 0x80062920: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80062924: lw          $t3, 0x14($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X14);
    // 0x80062928: sll         $t2, $v1, 1
    ctx->r10 = S32(ctx->r3 << 1);
    // 0x8006292C: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x80062930: addu        $t4, $t3, $t2
    ctx->r12 = ADD32(ctx->r11, ctx->r10);
    // 0x80062934: sltu        $at, $t4, $t8
    ctx->r1 = ctx->r12 < ctx->r24 ? 1 : 0;
    // 0x80062938: beq         $at, $zero, L_80062948
    if (ctx->r1 == 0) {
        // 0x8006293C: sw          $t8, 0x18($s3)
        MEM_W(0X18, ctx->r19) = ctx->r24;
            goto L_80062948;
    }
    // 0x8006293C: sw          $t8, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r24;
    // 0x80062940: subu        $t5, $t8, $t2
    ctx->r13 = SUB32(ctx->r24, ctx->r10);
    // 0x80062944: sw          $t5, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r13;
L_80062948:
    // 0x80062948: lui         $t6, 0xA00
    ctx->r14 = S32(0XA00 << 16);
    // 0x8006294C: ori         $t6, $t6, 0x800
    ctx->r14 = ctx->r14 | 0X800;
    // 0x80062950: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80062954: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80062958: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x8006295C: lui         $at, 0x6C0
    ctx->r1 = S32(0X6C0 << 16);
    // 0x80062960: addiu       $v0, $s0, 0x8
    ctx->r2 = ADD32(ctx->r16, 0X8);
    // 0x80062964: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x80062968: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8006296C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80062970: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80062974: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80062978: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8006297C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80062980: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80062984: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80062988: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8006298C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80062990: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80062994: jr          $ra
    // 0x80062998: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    TRACE_RETURN()
    return;
    // 0x80062998: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_800629A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800629A0: lui         $t6, 0xA480
    ctx->r14 = S32(0XA480 << 16);
    // 0x800629A4: lw          $a0, 0x18($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X18);
    // 0x800629A8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800629AC: andi        $t7, $a0, 0x3
    ctx->r15 = ctx->r4 & 0X3;
    // 0x800629B0: beq         $t7, $zero, L_800629C0
    if (ctx->r15 == 0) {
        // 0x800629B4: nop
    
            goto L_800629C0;
    }
    // 0x800629B4: nop

    // 0x800629B8: b           L_800629C4
    // 0x800629BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800629C4;
    // 0x800629BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800629C0:
    // 0x800629C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800629C4:
    // 0x800629C4: jr          $ra
    // 0x800629C8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    TRACE_RETURN()
    return;
    // 0x800629C8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800629D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800629D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800629D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800629D8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800629DC: jal         0x80056580
    // 0x800629E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    __osDisableInt_recomp(rdram, ctx);
        goto after_0;
    // 0x800629E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800629E4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800629E8: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x800629EC: lw          $t6, 0x31F0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X31F0);
    // 0x800629F0: addiu       $at, $zero, -0x402
    ctx->r1 = ADD32(0, -0X402);
    // 0x800629F4: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800629F8: nor         $t9, $t8, $zero
    ctx->r25 = ~(ctx->r24 | 0);
    // 0x800629FC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80062A00: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80062A04: and         $t0, $t6, $t9
    ctx->r8 = ctx->r14 & ctx->r25;
    // 0x80062A08: sw          $t0, 0x31F0($at)
    MEM_W(0X31F0, ctx->r1) = ctx->r8;
    // 0x80062A0C: jal         0x800565A0
    // 0x80062A10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    __osRestoreInt_recomp(rdram, ctx);
        goto after_1;
    // 0x80062A10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80062A14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80062A18: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80062A1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80062A20: jr          $ra
    TRACE_RETURN()
    return;
;}
