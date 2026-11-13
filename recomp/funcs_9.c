#include "recomp.h"
#include "trace.h"
#include "funcs.h"

RECOMP_FUNC void func_8000EF2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000EF2C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000EF30: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000EF34: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8000EF38: c.le.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl <= ctx->f4.fl;
    // 0x8000EF3C: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x8000EF40: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000EF44: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8000EF48: bc1f        L_8000EF60
    if (!c1cs) {
        // 0x8000EF4C: lui         $at, 0x8007
        ctx->r1 = S32(0X8007 << 16);
            goto L_8000EF60;
    }
    // 0x8000EF4C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000EF50: lui         $at, 0xC380
    ctx->r1 = S32(0XC380 << 16);
    // 0x8000EF54: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8000EF58: b           L_8000F084
    // 0x8000EF5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8000F084;
    // 0x8000EF5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8000EF60:
    // 0x8000EF60: lwc1        $f6, 0x5FC0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5FC0);
    // 0x8000EF64: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8000EF68: jal         0x8000F200
    // 0x8000EF6C: div.s       $f12, $f20, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f20.fl, ctx->f6.fl);
    func_8000F200(rdram, ctx);
        goto after_0;
    // 0x8000EF6C: div.s       $f12, $f20, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f20.fl, ctx->f6.fl);
    after_0:
    // 0x8000EF70: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000EF74: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8000EF78: jal         0x8000F378
    // 0x8000EF7C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_8000F378(rdram, ctx);
        goto after_1;
    // 0x8000EF7C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x8000EF80: div.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8000EF84: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8000EF88: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8000EF8C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000EF90: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000EF94: addiu       $t7, $zero, 0x9
    ctx->r15 = ADD32(0, 0X9);
    // 0x8000EF98: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000EF9C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8000EFA0: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8000EFA4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8000EFA8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8000EFAC: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8000EFB0: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x8000EFB4: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8000EFB8: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x8000EFBC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8000EFC0: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8000EFC4: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8000EFC8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000EFCC: sub.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f8.fl;
    // 0x8000EFD0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000EFD4: mul.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8000EFD8: add.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x8000EFDC: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8000EFE0: div.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8000EFE4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000EFE8: mul.s       $f12, $f10, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8000EFEC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8000EFF0: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8000EFF4: div.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8000EFF8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000EFFC: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8000F000: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8000F004: div.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f12.fl, ctx->f8.fl);
    // 0x8000F008: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000F00C: mul.s       $f14, $f8, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8000F010: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8000F014: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x8000F018: div.s       $f2, $f12, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f12.fl, ctx->f4.fl);
    // 0x8000F01C: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000F020: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8000F024: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8000F028: div.s       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f14.fl, ctx->f6.fl);
    // 0x8000F02C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000F030: mul.s       $f16, $f6, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8000F034: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8000F038: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8000F03C: div.s       $f2, $f14, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f14.fl, ctx->f10.fl);
    // 0x8000F040: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000F044: add.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8000F048: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8000F04C: div.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8000F050: cvt.d.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.d = CVT_D_W(ctx->f10.u32l);
    // 0x8000F054: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8000F058: ldc1        $f6, 0x5FC8($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X5FC8);
    // 0x8000F05C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000F060: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000F064: div.s       $f2, $f16, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f16.fl, ctx->f8.fl);
    // 0x8000F068: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8000F06C: add.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8000F070: div.s       $f6, $f20, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f20.fl, ctx->f4.fl);
    // 0x8000F074: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8000F078: add.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d + ctx->f10.d;
    // 0x8000F07C: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    // 0x8000F080: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8000F084:
    // 0x8000F084: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8000F088: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8000F08C: jr          $ra
    // 0x8000F090: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    TRACE_RETURN()
    return;
    // 0x8000F090: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8000F094(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000F094: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8000F098: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000F09C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8000F0A0: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
    // 0x8000F0A4: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x8000F0A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000F0AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000F0B0: bc1fl       L_8000F0C8
    if (!c1cs) {
        // 0x8000F0B4: c.le.s      $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
            goto L_8000F0C8;
    }
    goto skip_0;
    // 0x8000F0B4: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    skip_0:
    // 0x8000F0B8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8000F0BC: b           L_8000F1B4
    // 0x8000F0C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8000F1B4;
    // 0x8000F0C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F0C4: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
L_8000F0C8:
    // 0x8000F0C8: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x8000F0CC: bc1fl       L_8000F0E8
    if (!c1cs) {
        // 0x8000F0D0: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_8000F0E8;
    }
    goto skip_1;
    // 0x8000F0D0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_1:
    // 0x8000F0D4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8000F0D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8000F0DC: b           L_8000F0EC
    // 0x8000F0E0: nop

        goto L_8000F0EC;
    // 0x8000F0E0: nop

    // 0x8000F0E4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_8000F0E8:
    // 0x8000F0E8: nop

L_8000F0EC:
    // 0x8000F0EC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000F0F0: ldc1        $f16, 0x5FD0($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, 0X5FD0);
    // 0x8000F0F4: cvt.d.s     $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f12.d = CVT_D_S(ctx->f20.fl);
    // 0x8000F0F8: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8000F0FC: div.d       $f6, $f12, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = DIV_D(ctx->f12.d, ctx->f16.d);
    // 0x8000F100: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x8000F104: addiu       $t7, $zero, 0x12
    ctx->r15 = ADD32(0, 0X12);
    // 0x8000F108: addiu       $t8, $zero, 0xE
    ctx->r24 = ADD32(0, 0XE);
    // 0x8000F10C: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x8000F110: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x8000F114: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x8000F118: trunc.w.d   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_D(ctx->f8.d);
    // 0x8000F11C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8000F120: nop

    // 0x8000F124: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8000F128: nop

    // 0x8000F12C: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8000F130: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000F134: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8000F138: mul.d       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x8000F13C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8000F140: sub.d       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f12.d - ctx->f8.d;
    // 0x8000F144: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000F148: cvt.s.d     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f20.fl = CVT_S_D(ctx->f10.d);
    // 0x8000F14C: mul.s       $f2, $f20, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8000F150: div.s       $f14, $f2, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8000F154: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8000F158: nop

    // 0x8000F15C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000F160: add.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x8000F164: div.s       $f0, $f2, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8000F168: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8000F16C: nop

    // 0x8000F170: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000F174: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8000F178: div.s       $f0, $f2, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f8.fl);
    // 0x8000F17C: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8000F180: nop

    // 0x8000F184: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000F188: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8000F18C: div.s       $f0, $f2, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8000F190: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8000F194: add.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x8000F198: div.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8000F19C: add.s       $f2, $f6, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8000F1A0: add.s       $f8, $f2, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f20.fl;
    // 0x8000F1A4: sub.s       $f10, $f2, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f20.fl;
    // 0x8000F1A8: jal         0x8000F378
    // 0x8000F1AC: div.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    func_8000F378(rdram, ctx);
        goto after_0;
    // 0x8000F1AC: div.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    after_0:
    // 0x8000F1B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000F1B4:
    // 0x8000F1B4: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8000F1B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000F1BC: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000F1C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000F1C4: sdc1        $f12, 0x0($sp)
    CHECK_FR(ctx, 12);
    SD(ctx->f12.u64, 0X0, ctx->r29);
    // 0x8000F1C8: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8000F1CC: ldc1        $f4, 0x0($sp)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r29, 0X0);
    // 0x8000F1D0: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8000F1D4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8000F1D8: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x8000F1DC: c.eq.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d == ctx->f6.d;
    // 0x8000F1E0: sra         $t7, $t6, 20
    ctx->r15 = S32(SIGNED(ctx->r14) >> 20);
    // 0x8000F1E4: andi        $t8, $t7, 0x7FF
    ctx->r24 = ctx->r15 & 0X7FF;
    // 0x8000F1E8: addiu       $t9, $t8, -0x3FE
    ctx->r25 = ADD32(ctx->r24, -0X3FE);
    // 0x8000F1EC: bc1t        L_8000F1F8
    if (c1cs) {
        // 0x8000F1F0: nop
    
            goto L_8000F1F8;
    }
    // 0x8000F1F0: nop

    // 0x8000F1F4: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
L_8000F1F8:
    // 0x8000F1F8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000F200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000F200: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000F204: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8000F208: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x8000F20C: c.eq.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl == ctx->f4.fl;
    // 0x8000F210: addiu       $a0, $sp, 0x4
    ctx->r4 = ADD32(ctx->r29, 0X4);
    // 0x8000F214: bc1fl       L_8000F22C
    if (!c1cs) {
        // 0x8000F218: swc1        $f12, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->f12.u32l;
            goto L_8000F22C;
    }
    goto skip_0;
    // 0x8000F218: swc1        $f12, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f12.u32l;
    skip_0:
    // 0x8000F21C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8000F220: b           L_8000F370
    // 0x8000F224: nop

        goto L_8000F370;
    // 0x8000F224: nop

    // 0x8000F228: swc1        $f12, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f12.u32l;
L_8000F22C:
    // 0x8000F22C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8000F230: lui         $at, 0x7FFF
    ctx->r1 = S32(0X7FFF << 16);
    // 0x8000F234: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8000F238: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x8000F23C: lui         $at, 0x8080
    ctx->r1 = S32(0X8080 << 16);
    // 0x8000F240: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
    // 0x8000F244: blez        $v0, L_8000F254
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000F248: nop
    
            goto L_8000F254;
    }
    // 0x8000F248: nop

    // 0x8000F24C: b           L_8000F370
    // 0x8000F250: lwc1        $f0, 0x4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4);
        goto L_8000F370;
    // 0x8000F250: lwc1        $f0, 0x4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4);
L_8000F254:
    // 0x8000F254: bne         $v0, $zero, L_8000F27C
    if (ctx->r2 != 0) {
        // 0x8000F258: lui         $a2, 0x8000
        ctx->r6 = S32(0X8000 << 16);
            goto L_8000F27C;
    }
    // 0x8000F258: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x8000F25C: addiu       $t6, $zero, 0x401
    ctx->r14 = ADD32(0, 0X401);
    // 0x8000F260: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8000F264: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8000F268: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x8000F26C: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8000F270: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8000F274: b           L_8000F370
    // 0x8000F278: lwc1        $f0, 0x4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4);
        goto L_8000F370;
    // 0x8000F278: lwc1        $f0, 0x4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4);
L_8000F27C:
    // 0x8000F27C: srl         $t9, $v1, 23
    ctx->r25 = S32(U32(ctx->r3) >> 23);
    // 0x8000F280: andi        $t1, $t9, 0xFF
    ctx->r9 = ctx->r25 & 0XFF;
    // 0x8000F284: addiu       $t2, $t1, -0x7E
    ctx->r10 = ADD32(ctx->r9, -0X7E);
    // 0x8000F288: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x8000F28C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8000F290: lui         $a3, 0x7F
    ctx->r7 = S32(0X7F << 16);
    // 0x8000F294: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
    // 0x8000F298: and         $t4, $v1, $a3
    ctx->r12 = ctx->r3 & ctx->r7;
    // 0x8000F29C: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8000F2A0: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x8000F2A4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8000F2A8: and         $v0, $v1, $a2
    ctx->r2 = ctx->r3 & ctx->r6;
    // 0x8000F2AC: or          $t3, $v0, $at
    ctx->r11 = ctx->r2 | ctx->r1;
    // 0x8000F2B0: addiu       $at, $zero, -0x7E
    ctx->r1 = ADD32(0, -0X7E);
    // 0x8000F2B4: bne         $t5, $at, L_8000F360
    if (ctx->r13 != ctx->r1) {
        // 0x8000F2B8: or          $v0, $t3, $zero
        ctx->r2 = ctx->r11 | 0;
            goto L_8000F360;
    }
    // 0x8000F2B8: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8000F2BC: lui         $t0, 0x100
    ctx->r8 = S32(0X100 << 16);
    // 0x8000F2C0: sll         $v1, $t4, 9
    ctx->r3 = S32(ctx->r12 << 9);
    // 0x8000F2C4: sltu        $at, $v1, $t0
    ctx->r1 = ctx->r3 < ctx->r8 ? 1 : 0;
    // 0x8000F2C8: beq         $at, $zero, L_8000F2F4
    if (ctx->r1 == 0) {
        // 0x8000F2CC: sw          $v1, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r3;
            goto L_8000F2F4;
    }
    // 0x8000F2CC: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x8000F2D0: sll         $t8, $v1, 8
    ctx->r24 = S32(ctx->r3 << 8);
L_8000F2D4:
    // 0x8000F2D4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8000F2D8: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8000F2DC: addiu       $t1, $t9, -0x8
    ctx->r9 = ADD32(ctx->r25, -0X8);
    // 0x8000F2E0: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x8000F2E4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8000F2E8: sltu        $at, $v1, $t0
    ctx->r1 = ctx->r3 < ctx->r8 ? 1 : 0;
    // 0x8000F2EC: bnel        $at, $zero, L_8000F2D4
    if (ctx->r1 != 0) {
        // 0x8000F2F0: sll         $t8, $v1, 8
        ctx->r24 = S32(ctx->r3 << 8);
            goto L_8000F2D4;
    }
    goto skip_1;
    // 0x8000F2F0: sll         $t8, $v1, 8
    ctx->r24 = S32(ctx->r3 << 8);
    skip_1:
L_8000F2F4:
    // 0x8000F2F4: lui         $t0, 0x4000
    ctx->r8 = S32(0X4000 << 16);
    // 0x8000F2F8: sltu        $at, $v1, $t0
    ctx->r1 = ctx->r3 < ctx->r8 ? 1 : 0;
    // 0x8000F2FC: beq         $at, $zero, L_8000F324
    if (ctx->r1 == 0) {
        // 0x8000F300: sll         $t2, $v1, 2
        ctx->r10 = S32(ctx->r3 << 2);
            goto L_8000F324;
    }
    // 0x8000F300: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
L_8000F304:
    // 0x8000F304: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8000F308: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x8000F30C: addiu       $t4, $t3, -0x2
    ctx->r12 = ADD32(ctx->r11, -0X2);
    // 0x8000F310: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x8000F314: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8000F318: sltu        $at, $v1, $t0
    ctx->r1 = ctx->r3 < ctx->r8 ? 1 : 0;
    // 0x8000F31C: bnel        $at, $zero, L_8000F304
    if (ctx->r1 != 0) {
        // 0x8000F320: sll         $t2, $v1, 2
        ctx->r10 = S32(ctx->r3 << 2);
            goto L_8000F304;
    }
    goto skip_2;
    // 0x8000F320: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    skip_2:
L_8000F324:
    // 0x8000F324: sltu        $at, $v1, $a2
    ctx->r1 = ctx->r3 < ctx->r6 ? 1 : 0;
    // 0x8000F328: beq         $at, $zero, L_8000F350
    if (ctx->r1 == 0) {
        // 0x8000F32C: sll         $t5, $v1, 1
        ctx->r13 = S32(ctx->r3 << 1);
            goto L_8000F350;
    }
    // 0x8000F32C: sll         $t5, $v1, 1
    ctx->r13 = S32(ctx->r3 << 1);
L_8000F330:
    // 0x8000F330: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8000F334: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8000F338: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8000F33C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8000F340: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8000F344: sltu        $at, $v1, $a2
    ctx->r1 = ctx->r3 < ctx->r6 ? 1 : 0;
    // 0x8000F348: bnel        $at, $zero, L_8000F330
    if (ctx->r1 != 0) {
        // 0x8000F34C: sll         $t5, $v1, 1
        ctx->r13 = S32(ctx->r3 << 1);
            goto L_8000F330;
    }
    goto skip_3;
    // 0x8000F34C: sll         $t5, $v1, 1
    ctx->r13 = S32(ctx->r3 << 1);
    skip_3:
L_8000F350:
    // 0x8000F350: srl         $t8, $v1, 8
    ctx->r24 = S32(U32(ctx->r3) >> 8);
    // 0x8000F354: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8000F358: and         $t1, $t8, $a3
    ctx->r9 = ctx->r24 & ctx->r7;
    // 0x8000F35C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
L_8000F360:
    // 0x8000F360: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8000F364: or          $t3, $t2, $v0
    ctx->r11 = ctx->r10 | ctx->r2;
    // 0x8000F368: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8000F36C: lwc1        $f0, 0x4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4);
L_8000F370:
    // 0x8000F370: jr          $ra
    // 0x8000F374: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    TRACE_RETURN()
    return;
    // 0x8000F374: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8000F378(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000F378: bltz        $a1, L_8000F390
    if (SIGNED(ctx->r5) < 0) {
        // 0x8000F37C: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_8000F390;
    }
    // 0x8000F37C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8000F380: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8000F384: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8000F388: b           L_8000F398
    // 0x8000F38C: nop

        goto L_8000F398;
    // 0x8000F38C: nop

L_8000F390:
    // 0x8000F390: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8000F394: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
L_8000F398:
    // 0x8000F398: beq         $a1, $zero, L_8000F3BC
    if (ctx->r5 == 0) {
        // 0x8000F39C: andi        $t6, $a1, 0x1
        ctx->r14 = ctx->r5 & 0X1;
            goto L_8000F3BC;
    }
L_8000F39C:
    // 0x8000F39C: andi        $t6, $a1, 0x1
    ctx->r14 = ctx->r5 & 0X1;
    // 0x8000F3A0: beq         $t6, $zero, L_8000F3B0
    if (ctx->r14 == 0) {
        // 0x8000F3A4: sra         $t7, $a1, 1
        ctx->r15 = S32(SIGNED(ctx->r5) >> 1);
            goto L_8000F3B0;
    }
    // 0x8000F3A4: sra         $t7, $a1, 1
    ctx->r15 = S32(SIGNED(ctx->r5) >> 1);
    // 0x8000F3A8: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8000F3AC: nop

L_8000F3B0:
    // 0x8000F3B0: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8000F3B4: bne         $t7, $zero, L_8000F39C
    if (ctx->r15 != 0) {
        // 0x8000F3B8: or          $a1, $t7, $zero
        ctx->r5 = ctx->r15 | 0;
            goto L_8000F39C;
    }
    // 0x8000F3B8: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
L_8000F3BC:
    // 0x8000F3BC: jr          $ra
    // 0x8000F3C0: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    TRACE_RETURN()
    return;
    // 0x8000F3C0: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
;}
RECOMP_FUNC void func_8000F3C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000F3C4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000F3C8: lwc1        $f0, 0x5FD8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5FD8);
    // 0x8000F3CC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000F3D0: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8000F3D4: nop

    // 0x8000F3D8: bc1f        L_8000F400
    if (!c1cs) {
        // 0x8000F3DC: nop
    
            goto L_8000F400;
    }
    // 0x8000F3DC: nop

    // 0x8000F3E0: ldc1        $f2, 0x5FE0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, 0X5FE0);
    // 0x8000F3E4: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
L_8000F3E8:
    // 0x8000F3E8: add.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f4.d + ctx->f2.d;
    // 0x8000F3EC: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x8000F3F0: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8000F3F4: nop

    // 0x8000F3F8: bc1tl       L_8000F3E8
    if (c1cs) {
        // 0x8000F3FC: cvt.d.s     $f4, $f12
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
            goto L_8000F3E8;
    }
    goto skip_0;
    // 0x8000F3FC: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    skip_0:
L_8000F400:
    // 0x8000F400: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000F404: lwc1        $f0, 0x5FE8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5FE8);
    // 0x8000F408: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000F40C: ldc1        $f2, 0x5FF0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, 0X5FF0);
    // 0x8000F410: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x8000F414: nop

    // 0x8000F418: bc1f        L_8000F43C
    if (!c1cs) {
        // 0x8000F41C: nop
    
            goto L_8000F43C;
    }
    // 0x8000F41C: nop

    // 0x8000F420: cvt.d.s     $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.d = CVT_D_S(ctx->f12.fl);
L_8000F424:
    // 0x8000F424: sub.d       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f8.d - ctx->f2.d;
    // 0x8000F428: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    // 0x8000F42C: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x8000F430: nop

    // 0x8000F434: bc1tl       L_8000F424
    if (c1cs) {
        // 0x8000F438: cvt.d.s     $f8, $f12
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.d = CVT_D_S(ctx->f12.fl);
            goto L_8000F424;
    }
    goto skip_1;
    // 0x8000F438: cvt.d.s     $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.d = CVT_D_S(ctx->f12.fl);
    skip_1:
L_8000F43C:
    // 0x8000F43C: jr          $ra
    // 0x8000F440: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    TRACE_RETURN()
    return;
    // 0x8000F440: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
;}
RECOMP_FUNC void func_8000F444(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000F444: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x8000F448: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8000F44C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8000F450: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8000F454: nop

    // 0x8000F458: bc1fl       L_8000F480
    if (!c1cs) {
        // 0x8000F45C: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_8000F480;
    }
    goto skip_0;
    // 0x8000F45C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    skip_0:
    // 0x8000F460: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8000F464: nop

    // 0x8000F468: add.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f2.fl;
L_8000F46C:
    // 0x8000F46C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8000F470: nop

    // 0x8000F474: bc1tl       L_8000F46C
    if (c1cs) {
        // 0x8000F478: add.s       $f12, $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f2.fl;
            goto L_8000F46C;
    }
    goto skip_1;
    // 0x8000F478: add.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f2.fl;
    skip_1:
    // 0x8000F47C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_8000F480:
    // 0x8000F480: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8000F484: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8000F488: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8000F48C: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x8000F490: nop

    // 0x8000F494: bc1f        L_8000F4B0
    if (!c1cs) {
        // 0x8000F498: nop
    
            goto L_8000F4B0;
    }
    // 0x8000F498: nop

    // 0x8000F49C: sub.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f2.fl;
L_8000F4A0:
    // 0x8000F4A0: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x8000F4A4: nop

    // 0x8000F4A8: bc1tl       L_8000F4A0
    if (c1cs) {
        // 0x8000F4AC: sub.s       $f12, $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f2.fl;
            goto L_8000F4A0;
    }
    goto skip_2;
    // 0x8000F4AC: sub.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f2.fl;
    skip_2:
L_8000F4B0:
    // 0x8000F4B0: jr          $ra
    // 0x8000F4B4: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    TRACE_RETURN()
    return;
    // 0x8000F4B4: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
;}
RECOMP_FUNC void func_8000F4B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000F4B8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000F4BC: lwc1        $f2, 0x5FF8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5FF8);
    // 0x8000F4C0: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000F4C4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000F4C8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8000F4CC: nop

    // 0x8000F4D0: bc1f        L_8000F4F8
    if (!c1cs) {
        // 0x8000F4D4: nop
    
            goto L_8000F4F8;
    }
    // 0x8000F4D4: nop

    // 0x8000F4D8: lwc1        $f12, 0x5FFC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X5FFC);
    // 0x8000F4DC: add.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f12.fl;
L_8000F4E0:
    // 0x8000F4E0: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x8000F4E4: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000F4E8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8000F4EC: nop

    // 0x8000F4F0: bc1tl       L_8000F4E0
    if (c1cs) {
        // 0x8000F4F4: add.s       $f4, $f0, $f12
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f12.fl;
            goto L_8000F4E0;
    }
    goto skip_0;
    // 0x8000F4F4: add.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f12.fl;
    skip_0:
L_8000F4F8:
    // 0x8000F4F8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000F4FC: lwc1        $f2, 0x6000($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6000);
    // 0x8000F500: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000F504: lwc1        $f12, 0x6004($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X6004);
    // 0x8000F508: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8000F50C: nop

    // 0x8000F510: bc1f        L_8000F534
    if (!c1cs) {
        // 0x8000F514: nop
    
            goto L_8000F534;
    }
    // 0x8000F514: nop

    // 0x8000F518: sub.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f12.fl;
L_8000F51C:
    // 0x8000F51C: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x8000F520: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000F524: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8000F528: nop

    // 0x8000F52C: bc1tl       L_8000F51C
    if (c1cs) {
        // 0x8000F530: sub.s       $f6, $f0, $f12
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f12.fl;
            goto L_8000F51C;
    }
    goto skip_1;
    // 0x8000F530: sub.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f12.fl;
    skip_1:
L_8000F534:
    // 0x8000F534: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000F53C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000F53C: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x8000F540: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8000F544: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000F548: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8000F54C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8000F550: nop

    // 0x8000F554: bc1fl       L_8000F584
    if (!c1cs) {
        // 0x8000F558: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_8000F584;
    }
    goto skip_0;
    // 0x8000F558: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    skip_0:
    // 0x8000F55C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8000F560: nop

    // 0x8000F564: add.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f12.fl;
L_8000F568:
    // 0x8000F568: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x8000F56C: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000F570: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8000F574: nop

    // 0x8000F578: bc1tl       L_8000F568
    if (c1cs) {
        // 0x8000F57C: add.s       $f4, $f0, $f12
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f12.fl;
            goto L_8000F568;
    }
    goto skip_1;
    // 0x8000F57C: add.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f12.fl;
    skip_1:
    // 0x8000F580: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_8000F584:
    // 0x8000F584: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8000F588: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8000F58C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8000F590: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8000F594: nop

    // 0x8000F598: bc1f        L_8000F5BC
    if (!c1cs) {
        // 0x8000F59C: nop
    
            goto L_8000F5BC;
    }
    // 0x8000F59C: nop

    // 0x8000F5A0: sub.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f12.fl;
L_8000F5A4:
    // 0x8000F5A4: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x8000F5A8: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000F5AC: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8000F5B0: nop

    // 0x8000F5B4: bc1tl       L_8000F5A4
    if (c1cs) {
        // 0x8000F5B8: sub.s       $f6, $f0, $f12
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f12.fl;
            goto L_8000F5A4;
    }
    goto skip_2;
    // 0x8000F5B8: sub.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f12.fl;
    skip_2:
L_8000F5BC:
    // 0x8000F5BC: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000F5D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000F5D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000F5D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000F5D8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8000F5DC: addiu       $a0, $a0, -0x6CA0
    ctx->r4 = ADD32(ctx->r4, -0X6CA0);
    // 0x8000F5E0: lui         $a1, 0x4
    ctx->r5 = S32(0X4 << 16);
    // 0x8000F5E4: jal         0x80004430
    // 0x8000F5E8: addiu       $a2, $zero, 0xE8
    ctx->r6 = ADD32(0, 0XE8);
    func_80004430(rdram, ctx);
        goto after_0;
    // 0x8000F5E8: addiu       $a2, $zero, 0xE8
    ctx->r6 = ADD32(0, 0XE8);
    after_0:
    // 0x8000F5EC: jal         0x8000F764
    // 0x8000F5F0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_8000F764(rdram, ctx);
        goto after_1;
    // 0x8000F5F0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_1:
    // 0x8000F5F4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8000F5F8: addiu       $a1, $a1, -0x6CA0
    ctx->r5 = ADD32(ctx->r5, -0X6CA0);
    // 0x8000F5FC: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8000F600: lw          $t6, 0xD8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XD8);
    // 0x8000F604: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8000F608: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x8000F60C: jal         0x8000F764
    // 0x8000F610: sw          $t7, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r15;
    func_8000F764(rdram, ctx);
        goto after_2;
    // 0x8000F610: sw          $t7, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r15;
    after_2:
    // 0x8000F614: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8000F618: addiu       $a1, $a1, -0x6C9C
    ctx->r5 = ADD32(ctx->r5, -0X6C9C);
    // 0x8000F61C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8000F620: lw          $t8, 0xD8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XD8);
    // 0x8000F624: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8000F628: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x8000F62C: jal         0x8000F764
    // 0x8000F630: sw          $t9, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r25;
    func_8000F764(rdram, ctx);
        goto after_3;
    // 0x8000F630: sw          $t9, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r25;
    after_3:
    // 0x8000F634: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8000F638: addiu       $a1, $a1, -0x6C98
    ctx->r5 = ADD32(ctx->r5, -0X6C98);
    // 0x8000F63C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8000F640: lw          $t0, 0xD8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XD8);
    // 0x8000F644: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8000F648: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x8000F64C: jal         0x8000F764
    // 0x8000F650: sw          $t1, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r9;
    func_8000F764(rdram, ctx);
        goto after_4;
    // 0x8000F650: sw          $t1, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r9;
    after_4:
    // 0x8000F654: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8000F658: addiu       $a1, $a1, -0x6C94
    ctx->r5 = ADD32(ctx->r5, -0X6C94);
    // 0x8000F65C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8000F660: lw          $t2, 0xD8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XD8);
    // 0x8000F664: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8000F668: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x8000F66C: jal         0x8000F764
    // 0x8000F670: sw          $t3, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r11;
    func_8000F764(rdram, ctx);
        goto after_5;
    // 0x8000F670: sw          $t3, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r11;
    after_5:
    // 0x8000F674: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8000F678: addiu       $a1, $a1, -0x6C90
    ctx->r5 = ADD32(ctx->r5, -0X6C90);
    // 0x8000F67C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8000F680: lw          $t4, 0xD8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XD8);
    // 0x8000F684: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8000F688: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x8000F68C: jal         0x8000F764
    // 0x8000F690: sw          $t5, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r13;
    func_8000F764(rdram, ctx);
        goto after_6;
    // 0x8000F690: sw          $t5, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r13;
    after_6:
    // 0x8000F694: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8000F698: addiu       $a1, $a1, -0x6C8C
    ctx->r5 = ADD32(ctx->r5, -0X6C8C);
    // 0x8000F69C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8000F6A0: lw          $t6, 0xD8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XD8);
    // 0x8000F6A4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8000F6A8: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x8000F6AC: jal         0x8000F764
    // 0x8000F6B0: sw          $t7, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r15;
    func_8000F764(rdram, ctx);
        goto after_7;
    // 0x8000F6B0: sw          $t7, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r15;
    after_7:
    // 0x8000F6B4: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8000F6B8: addiu       $a2, $a2, -0x6C88
    ctx->r6 = ADD32(ctx->r6, -0X6C88);
    // 0x8000F6BC: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x8000F6C0: lw          $t8, 0xD8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XD8);
    // 0x8000F6C4: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8000F6C8: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8000F6CC: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x8000F6D0: sw          $t9, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r25;
    // 0x8000F6D4: jal         0x80004364
    // 0x8000F6D8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80004364(rdram, ctx);
        goto after_8;
    // 0x8000F6D8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_8:
    // 0x8000F6DC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8000F6E0: addiu       $v1, $v1, -0x6C84
    ctx->r3 = ADD32(ctx->r3, -0X6C84);
    // 0x8000F6E4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000F6E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000F6EC: jal         0x8000C7C0
    // 0x8000F6F0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_8000C7C0(rdram, ctx);
        goto after_9;
    // 0x8000F6F0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_9:
    // 0x8000F6F4: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8000F6F8: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8000F6FC: jal         0x80004364
    // 0x8000F700: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80004364(rdram, ctx);
        goto after_10;
    // 0x8000F700: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_10:
    // 0x8000F704: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8000F708: addiu       $v1, $v1, -0x6C80
    ctx->r3 = ADD32(ctx->r3, -0X6C80);
    // 0x8000F70C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000F710: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000F714: jal         0x8000C7C0
    // 0x8000F718: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_8000C7C0(rdram, ctx);
        goto after_11;
    // 0x8000F718: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_11:
    // 0x8000F71C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8000F720: addiu       $v0, $v0, -0x6C84
    ctx->r2 = ADD32(ctx->r2, -0X6C84);
    // 0x8000F724: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8000F728: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8000F72C: addiu       $v1, $v1, -0x6C80
    ctx->r3 = ADD32(ctx->r3, -0X6C80);
    // 0x8000F730: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8000F734: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8000F738: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8000F73C: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8000F740: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8000F744: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8000F748: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8000F74C: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8000F750: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x8000F754: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000F758: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000F75C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000F764(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000F764: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000F768: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000F76C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000F770: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8000F774: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000F778: jal         0x800044AC
    // 0x8000F77C: addiu       $a0, $a0, -0x6CA0
    ctx->r4 = ADD32(ctx->r4, -0X6CA0);
    func_800044AC(rdram, ctx);
        goto after_0;
    // 0x8000F77C: addiu       $a0, $a0, -0x6CA0
    ctx->r4 = ADD32(ctx->r4, -0X6CA0);
    after_0:
    // 0x8000F780: beq         $v0, $zero, L_8000F7F4
    if (ctx->r2 == 0) {
        // 0x8000F784: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8000F7F4;
    }
    // 0x8000F784: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000F788: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000F78C: jal         0x8000C7C0
    // 0x8000F790: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    func_8000C7C0(rdram, ctx);
        goto after_1;
    // 0x8000F790: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    after_1:
    // 0x8000F794: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8000F798: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8000F79C: bne         $v0, $at, L_8000F7EC
    if (ctx->r2 != ctx->r1) {
        // 0x8000F7A0: sw          $v0, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->r2;
            goto L_8000F7EC;
    }
    // 0x8000F7A0: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x8000F7A4: jal         0x8000F764
    // 0x8000F7A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8000F764(rdram, ctx);
        goto after_2;
    // 0x8000F7A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x8000F7AC: sw          $v0, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->r2;
    // 0x8000F7B0: sw          $s0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r16;
    // 0x8000F7B4: jal         0x8000F764
    // 0x8000F7B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8000F764(rdram, ctx);
        goto after_3;
    // 0x8000F7B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x8000F7BC: sw          $v0, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->r2;
    // 0x8000F7C0: sw          $s0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r16;
    // 0x8000F7C4: lw          $t6, 0xD0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XD0);
    // 0x8000F7C8: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x8000F7CC: lw          $t7, 0xD4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XD4);
    // 0x8000F7D0: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x8000F7D4: lw          $t8, 0xD4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XD4);
    // 0x8000F7D8: lw          $t9, 0xD0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XD0);
    // 0x8000F7DC: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8000F7E0: lw          $t1, 0xD4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XD4);
    // 0x8000F7E4: lw          $t0, 0xD0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XD0);
    // 0x8000F7E8: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
L_8000F7EC:
    // 0x8000F7EC: jal         0x800022F0
    // 0x8000F7F0: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    func_800022F0(rdram, ctx);
        goto after_4;
    // 0x8000F7F0: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    after_4:
L_8000F7F4:
    // 0x8000F7F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F7F8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8000F7FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000F800: jr          $ra
    // 0x8000F804: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    TRACE_RETURN()
    return;
    // 0x8000F804: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8000F808(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000F808: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000F80C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000F810: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000F814: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8000F818: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8000F81C: jal         0x80004364
    // 0x8000F820: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x8000F820: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x8000F824: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8000F828: addiu       $v1, $v1, -0x6C80
    ctx->r3 = ADD32(ctx->r3, -0X6C80);
    // 0x8000F82C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8000F830: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8000F834: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8000F838: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8000F83C: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x8000F840: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8000F844: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8000F848: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8000F84C: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8000F850: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8000F854: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8000F858: sw          $v0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r2;
    // 0x8000F85C: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8000F860: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
    // 0x8000F864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000F868: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000F86C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000F874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000F874: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000F878: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000F87C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000F880: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x8000F884: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8000F888: bne         $t7, $at, L_8000F8A4
    if (ctx->r15 != ctx->r1) {
        // 0x8000F88C: nop
    
            goto L_8000F8A4;
    }
    // 0x8000F88C: nop

    // 0x8000F890: jal         0x8000F874
    // 0x8000F894: lw          $a0, 0xD0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD0);
    func_8000F874(rdram, ctx);
        goto after_0;
    // 0x8000F894: lw          $a0, 0xD0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD0);
    after_0:
    // 0x8000F898: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8000F89C: jal         0x8000F874
    // 0x8000F8A0: lw          $a0, 0xD4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0XD4);
    func_8000F874(rdram, ctx);
        goto after_1;
    // 0x8000F8A0: lw          $a0, 0xD4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0XD4);
    after_1:
L_8000F8A4:
    // 0x8000F8A4: jal         0x8000F808
    // 0x8000F8A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8000F808(rdram, ctx);
        goto after_2;
    // 0x8000F8A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8000F8AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000F8B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000F8B4: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000F8BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000F8BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000F8C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000F8C4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000F8C8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000F8CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000F8D0: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x8000F8D4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8000F8D8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8000F8DC: bnel        $t6, $at, L_8000F928
    if (ctx->r14 != ctx->r1) {
        // 0x8000F8E0: lw          $t7, 0x0($s2)
        ctx->r15 = MEM_W(ctx->r18, 0X0);
            goto L_8000F928;
    }
    goto skip_0;
    // 0x8000F8E0: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    skip_0:
    // 0x8000F8E4: lw          $a0, 0xD0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD0);
    // 0x8000F8E8: lw          $s1, 0x0($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X0);
    // 0x8000F8EC: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8000F8F0: beq         $s0, $zero, L_8000F914
    if (ctx->r16 == 0) {
        // 0x8000F8F4: nop
    
            goto L_8000F914;
    }
    // 0x8000F8F4: nop

L_8000F8F8:
    // 0x8000F8F8: jal         0x8000F8BC
    // 0x8000F8FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000F8BC(rdram, ctx);
        goto after_0;
    // 0x8000F8FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x8000F900: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x8000F904: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x8000F908: bne         $s0, $zero, L_8000F8F8
    if (ctx->r16 != 0) {
        // 0x8000F90C: nop
    
            goto L_8000F8F8;
    }
    // 0x8000F90C: nop

    // 0x8000F910: lw          $a0, 0xD0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0XD0);
L_8000F914:
    // 0x8000F914: jal         0x8000F808
    // 0x8000F918: nop

    func_8000F808(rdram, ctx);
        goto after_1;
    // 0x8000F918: nop

    after_1:
    // 0x8000F91C: jal         0x8000F808
    // 0x8000F920: lw          $a0, 0xD4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0XD4);
    func_8000F808(rdram, ctx);
        goto after_2;
    // 0x8000F920: lw          $a0, 0xD4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0XD4);
    after_2:
    // 0x8000F924: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
L_8000F928:
    // 0x8000F928: lw          $t8, 0x4($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X4);
    // 0x8000F92C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F930: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8000F934: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x8000F938: lw          $t9, 0x4($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X4);
    // 0x8000F93C: jal         0x8000F808
    // 0x8000F940: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    func_8000F808(rdram, ctx);
        goto after_3;
    // 0x8000F940: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    after_3:
    // 0x8000F944: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000F948: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000F94C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F950: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000F954: jr          $ra
    // 0x8000F958: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    TRACE_RETURN()
    return;
    // 0x8000F958: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8000F95C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000F95C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000F960: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8000F964: lw          $t6, -0x6C84($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6C84);
    // 0x8000F968: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000F96C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000F970: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000F974: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000F978: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000F97C: lw          $s1, 0x0($t6)
    ctx->r17 = MEM_W(ctx->r14, 0X0);
    // 0x8000F980: lui         $s2, 0x800F
    ctx->r18 = S32(0X800F << 16);
    // 0x8000F984: lui         $s3, 0x801A
    ctx->r19 = S32(0X801A << 16);
    // 0x8000F988: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8000F98C: addiu       $s3, $s3, 0x2800
    ctx->r19 = ADD32(ctx->r19, 0X2800);
    // 0x8000F990: addiu       $s2, $s2, -0x6CA0
    ctx->r18 = ADD32(ctx->r18, -0X6CA0);
    // 0x8000F994: beq         $v0, $zero, L_8000F9DC
    if (ctx->r2 == 0) {
        // 0x8000F998: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_8000F9DC;
    }
    // 0x8000F998: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_8000F99C:
    // 0x8000F99C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8000F9A0: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x8000F9A4: jal         0x800044F8
    // 0x8000F9A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800044F8(rdram, ctx);
        goto after_0;
    // 0x8000F9A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x8000F9AC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8000F9B0: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x8000F9B4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000F9B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8000F9BC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8000F9C0: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x8000F9C4: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x8000F9C8: jal         0x800042A8
    // 0x8000F9CC: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    func_800042A8(rdram, ctx);
        goto after_1;
    // 0x8000F9CC: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    after_1:
    // 0x8000F9D0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8000F9D4: bnel        $v0, $zero, L_8000F99C
    if (ctx->r2 != 0) {
        // 0x8000F9D8: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_8000F99C;
    }
    goto skip_0;
    // 0x8000F9D8: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    skip_0:
L_8000F9DC:
    // 0x8000F9DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000F9E0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000F9E4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000F9E8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F9EC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8000F9F0: jr          $ra
    // 0x8000F9F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    TRACE_RETURN()
    return;
    // 0x8000F9F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8000F9F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000F9F8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8000F9FC: jr          $ra
    // 0x8000FA00: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    TRACE_RETURN()
    return;
    // 0x8000FA00: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void func_8000FA04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000FA04: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000FA08: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000FA0C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8000FA10: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8000FA14: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000FA18: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000FA1C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000FA20: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000FA24: lw          $t6, 0xD0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XD0);
    // 0x8000FA28: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x8000FA2C: addiu       $s5, $zero, 0x5
    ctx->r21 = ADD32(0, 0X5);
    // 0x8000FA30: lw          $s1, 0x0($t6)
    ctx->r17 = MEM_W(ctx->r14, 0X0);
    // 0x8000FA34: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8000FA38: beql        $v0, $zero, L_8000FABC
    if (ctx->r2 == 0) {
        // 0x8000FA3C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8000FABC;
    }
    goto skip_0;
    // 0x8000FA3C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x8000FA40: lw          $t7, 0xC($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XC);
L_8000FA44:
    // 0x8000FA44: bnel        $s5, $t7, L_8000FAAC
    if (ctx->r21 != ctx->r15) {
        // 0x8000FA48: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8000FAAC;
    }
    goto skip_1;
    // 0x8000FA48: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    skip_1:
    // 0x8000FA4C: lw          $t8, 0xD8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XD8);
    // 0x8000FA50: addiu       $a0, $s1, 0x50
    ctx->r4 = ADD32(ctx->r17, 0X50);
    // 0x8000FA54: addiu       $a1, $s1, 0x10
    ctx->r5 = ADD32(ctx->r17, 0X10);
    // 0x8000FA58: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8000FA5C: beql        $t9, $zero, L_8000FAAC
    if (ctx->r25 == 0) {
        // 0x8000FA60: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8000FAAC;
    }
    goto skip_2;
    // 0x8000FA60: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    skip_2:
    // 0x8000FA64: jal         0x80000BD8
    // 0x8000FA68: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_80000BD8(rdram, ctx);
        goto after_0;
    // 0x8000FA68: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_0:
    // 0x8000FA6C: lw          $t0, 0xD0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0XD0);
    // 0x8000FA70: or          $s3, $s1, $zero
    ctx->r19 = ctx->r17 | 0;
    // 0x8000FA74: addiu       $s2, $s3, 0x50
    ctx->r18 = ADD32(ctx->r19, 0X50);
    // 0x8000FA78: lw          $s1, 0x0($t0)
    ctx->r17 = MEM_W(ctx->r8, 0X0);
    // 0x8000FA7C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8000FA80: beq         $s0, $zero, L_8000FAA4
    if (ctx->r16 == 0) {
        // 0x8000FA84: addiu       $a0, $s1, 0x50
        ctx->r4 = ADD32(ctx->r17, 0X50);
            goto L_8000FAA4;
    }
    // 0x8000FA84: addiu       $a0, $s1, 0x50
    ctx->r4 = ADD32(ctx->r17, 0X50);
L_8000FA88:
    // 0x8000FA88: addiu       $a1, $s1, 0x10
    ctx->r5 = ADD32(ctx->r17, 0X10);
    // 0x8000FA8C: jal         0x80000BD8
    // 0x8000FA90: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_80000BD8(rdram, ctx);
        goto after_1;
    // 0x8000FA90: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_1:
    // 0x8000FA94: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x8000FA98: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x8000FA9C: bnel        $s0, $zero, L_8000FA88
    if (ctx->r16 != 0) {
        // 0x8000FAA0: addiu       $a0, $s1, 0x50
        ctx->r4 = ADD32(ctx->r17, 0X50);
            goto L_8000FA88;
    }
    goto skip_3;
    // 0x8000FAA0: addiu       $a0, $s1, 0x50
    ctx->r4 = ADD32(ctx->r17, 0X50);
    skip_3:
L_8000FAA4:
    // 0x8000FAA4: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8000FAA8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_8000FAAC:
    // 0x8000FAAC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000FAB0: bnel        $v0, $zero, L_8000FA44
    if (ctx->r2 != 0) {
        // 0x8000FAB4: lw          $t7, 0xC($s1)
        ctx->r15 = MEM_W(ctx->r17, 0XC);
            goto L_8000FA44;
    }
    goto skip_4;
    // 0x8000FAB4: lw          $t7, 0xC($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XC);
    skip_4:
    // 0x8000FAB8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8000FABC:
    // 0x8000FABC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000FAC0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000FAC4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000FAC8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8000FACC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8000FAD0: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8000FAD4: jr          $ra
    // 0x8000FAD8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    TRACE_RETURN()
    return;
    // 0x8000FAD8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8000FADC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000FADC: jr          $ra
    // 0x8000FAE0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    TRACE_RETURN()
    return;
    // 0x8000FAE0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8000FAE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000FAE4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000FAE8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000FAEC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000FAF0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000FAF4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000FAF8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000FAFC: lw          $t6, 0xD0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XD0);
    // 0x8000FB00: addiu       $s3, $zero, 0x5
    ctx->r19 = ADD32(0, 0X5);
    // 0x8000FB04: lw          $s1, 0x0($t6)
    ctx->r17 = MEM_W(ctx->r14, 0X0);
    // 0x8000FB08: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8000FB0C: beql        $v0, $zero, L_8000FB78
    if (ctx->r2 == 0) {
        // 0x8000FB10: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8000FB78;
    }
    goto skip_0;
    // 0x8000FB10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8000FB14: lw          $t7, 0xC($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XC);
L_8000FB18:
    // 0x8000FB18: bnel        $s3, $t7, L_8000FB68
    if (ctx->r19 != ctx->r15) {
        // 0x8000FB1C: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8000FB68;
    }
    goto skip_1;
    // 0x8000FB1C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    skip_1:
    // 0x8000FB20: lw          $t8, 0xD8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XD8);
    // 0x8000FB24: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8000FB28: beql        $t9, $zero, L_8000FB68
    if (ctx->r25 == 0) {
        // 0x8000FB2C: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8000FB68;
    }
    goto skip_2;
    // 0x8000FB2C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    skip_2:
    // 0x8000FB30: lw          $t0, 0xD0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0XD0);
    // 0x8000FB34: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
    // 0x8000FB38: lw          $s1, 0x0($t0)
    ctx->r17 = MEM_W(ctx->r8, 0X0);
    // 0x8000FB3C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8000FB40: beq         $s0, $zero, L_8000FB60
    if (ctx->r16 == 0) {
        // 0x8000FB44: addiu       $a0, $s1, 0x90
        ctx->r4 = ADD32(ctx->r17, 0X90);
            goto L_8000FB60;
    }
    // 0x8000FB44: addiu       $a0, $s1, 0x90
    ctx->r4 = ADD32(ctx->r17, 0X90);
L_8000FB48:
    // 0x8000FB48: jal         0x80004EF0
    // 0x8000FB4C: addiu       $a1, $s1, 0x50
    ctx->r5 = ADD32(ctx->r17, 0X50);
    func_80004EF0(rdram, ctx);
        goto after_0;
    // 0x8000FB4C: addiu       $a1, $s1, 0x50
    ctx->r5 = ADD32(ctx->r17, 0X50);
    after_0:
    // 0x8000FB50: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x8000FB54: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x8000FB58: bnel        $s0, $zero, L_8000FB48
    if (ctx->r16 != 0) {
        // 0x8000FB5C: addiu       $a0, $s1, 0x90
        ctx->r4 = ADD32(ctx->r17, 0X90);
            goto L_8000FB48;
    }
    goto skip_3;
    // 0x8000FB5C: addiu       $a0, $s1, 0x90
    ctx->r4 = ADD32(ctx->r17, 0X90);
    skip_3:
L_8000FB60:
    // 0x8000FB60: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8000FB64: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_8000FB68:
    // 0x8000FB68: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000FB6C: bnel        $v0, $zero, L_8000FB18
    if (ctx->r2 != 0) {
        // 0x8000FB70: lw          $t7, 0xC($s1)
        ctx->r15 = MEM_W(ctx->r17, 0XC);
            goto L_8000FB18;
    }
    goto skip_4;
    // 0x8000FB70: lw          $t7, 0xC($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XC);
    skip_4:
    // 0x8000FB74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8000FB78:
    // 0x8000FB78: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000FB7C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000FB80: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000FB84: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8000FB88: jr          $ra
    // 0x8000FB8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    TRACE_RETURN()
    return;
    // 0x8000FB8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8000FB90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000FB90: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8000FB94: jr          $ra
    // 0x8000FB98: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    TRACE_RETURN()
    return;
    // 0x8000FB98: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void func_8000FB9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000FB9C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000FBA0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8000FBA4: lh          $t6, -0x6B7C($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X6B7C);
    // 0x8000FBA8: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8000FBAC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000FBB0: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x8000FBB4: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x8000FBB8: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x8000FBBC: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x8000FBC0: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x8000FBC4: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x8000FBC8: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8000FBCC: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8000FBD0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8000FBD4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8000FBD8: beq         $t6, $zero, L_8000FBF4
    if (ctx->r14 == 0) {
        // 0x8000FBDC: addiu       $s0, $zero, -0x1
        ctx->r16 = ADD32(0, -0X1);
            goto L_8000FBF4;
    }
    // 0x8000FBDC: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x8000FBE0: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x8000FBE4: ori         $t7, $t7, 0xC02
    ctx->r15 = ctx->r15 | 0XC02;
    // 0x8000FBE8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8000FBEC: addiu       $a3, $a0, 0x8
    ctx->r7 = ADD32(ctx->r4, 0X8);
    // 0x8000FBF0: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8000FBF4:
    // 0x8000FBF4: lh          $t8, 0x3A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X3A);
    // 0x8000FBF8: addiu       $s7, $zero, -0x1
    ctx->r23 = ADD32(0, -0X1);
    // 0x8000FBFC: addiu       $fp, $zero, -0x1
    ctx->r30 = ADD32(0, -0X1);
    // 0x8000FC00: beq         $t8, $zero, L_8000FC3C
    if (ctx->r24 == 0) {
        // 0x8000FC04: lui         $ra, 0x2
        ctx->r31 = S32(0X2 << 16);
            goto L_8000FC3C;
    }
    // 0x8000FC04: lui         $ra, 0x2
    ctx->r31 = S32(0X2 << 16);
    // 0x8000FC08: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8000FC0C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8000FC10: lui         $t9, 0xB700
    ctx->r25 = S32(0XB700 << 16);
    // 0x8000FC14: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8000FC18: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8000FC1C: sw          $ra, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r31;
    // 0x8000FC20: lui         $t6, 0xFC12
    ctx->r14 = S32(0XFC12 << 16);
    // 0x8000FC24: lui         $t7, 0xFF33
    ctx->r15 = S32(0XFF33 << 16);
    // 0x8000FC28: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x8000FC2C: ori         $t6, $t6, 0x1824
    ctx->r14 = ctx->r14 | 0X1824;
    // 0x8000FC30: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8000FC34: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8000FC38: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
L_8000FC3C:
    // 0x8000FC3C: lw          $t8, 0xD0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0XD0);
    // 0x8000FC40: lui         $ra, 0x2
    ctx->r31 = S32(0X2 << 16);
    // 0x8000FC44: lui         $s6, 0xE700
    ctx->r22 = S32(0XE700 << 16);
    // 0x8000FC48: lw          $a2, 0x0($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X0);
    // 0x8000FC4C: lui         $s5, 0xE600
    ctx->r21 = S32(0XE600 << 16);
    // 0x8000FC50: lui         $s4, 0x700
    ctx->r20 = S32(0X700 << 16);
    // 0x8000FC54: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8000FC58: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x8000FC5C: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x8000FC60: beq         $v0, $zero, L_800101E0
    if (ctx->r2 == 0) {
        // 0x8000FC64: addiu       $t3, $zero, 0x2
        ctx->r11 = ADD32(0, 0X2);
            goto L_800101E0;
    }
    // 0x8000FC64: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8000FC68: lui         $t1, 0x102
    ctx->r9 = S32(0X102 << 16);
    // 0x8000FC6C: ori         $t1, $t1, 0x40
    ctx->r9 = ctx->r9 | 0X40;
    // 0x8000FC70: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8000FC74: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x8000FC78: lw          $t9, 0xC($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XC);
L_8000FC7C:
    // 0x8000FC7C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8000FC80: bnel        $t9, $at, L_800101D4
    if (ctx->r25 != ctx->r1) {
        // 0x8000FC84: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800101D4;
    }
    goto skip_0;
    // 0x8000FC84: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    skip_0:
    // 0x8000FC88: lw          $v1, 0xD8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0XD8);
    // 0x8000FC8C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8000FC90: andi        $t6, $v1, 0x1
    ctx->r14 = ctx->r3 & 0X1;
    // 0x8000FC94: beql        $t6, $zero, L_800101D4
    if (ctx->r14 == 0) {
        // 0x8000FC98: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800101D4;
    }
    goto skip_1;
    // 0x8000FC98: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    skip_1:
    // 0x8000FC9C: lh          $t7, -0x6B7C($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X6B7C);
    // 0x8000FCA0: andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // 0x8000FCA4: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x8000FCA8: bne         $t7, $zero, L_8000FD00
    if (ctx->r15 != 0) {
        // 0x8000FCAC: sra         $t9, $t8, 16
        ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
            goto L_8000FD00;
    }
    // 0x8000FCAC: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8000FCB0: beql        $s7, $t9, L_8000FD04
    if (ctx->r23 == ctx->r25) {
        // 0x8000FCB4: lh          $t6, 0x3A($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X3A);
            goto L_8000FD04;
    }
    goto skip_2;
    // 0x8000FCB4: lh          $t6, 0x3A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X3A);
    skip_2:
    // 0x8000FCB8: sll         $s7, $t9, 16
    ctx->r23 = S32(ctx->r25 << 16);
    // 0x8000FCBC: sra         $t6, $s7, 16
    ctx->r14 = S32(SIGNED(ctx->r23) >> 16);
    // 0x8000FCC0: beq         $t9, $zero, L_8000FCE4
    if (ctx->r25 == 0) {
        // 0x8000FCC4: or          $s7, $t6, $zero
        ctx->r23 = ctx->r14 | 0;
            goto L_8000FCE4;
    }
    // 0x8000FCC4: or          $s7, $t6, $zero
    ctx->r23 = ctx->r14 | 0;
    // 0x8000FCC8: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8000FCCC: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x8000FCD0: ori         $t7, $t7, 0xC02
    ctx->r15 = ctx->r15 | 0XC02;
    // 0x8000FCD4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8000FCD8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8000FCDC: b           L_8000FD00
    // 0x8000FCE0: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
        goto L_8000FD00;
    // 0x8000FCE0: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
L_8000FCE4:
    // 0x8000FCE4: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8000FCE8: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x8000FCEC: ori         $t8, $t8, 0xC02
    ctx->r24 = ctx->r24 | 0XC02;
    // 0x8000FCF0: addiu       $t9, $zero, 0x2000
    ctx->r25 = ADD32(0, 0X2000);
    // 0x8000FCF4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8000FCF8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8000FCFC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
L_8000FD00:
    // 0x8000FD00: lh          $t6, 0x3A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X3A);
L_8000FD04:
    // 0x8000FD04: bnel        $t6, $zero, L_8000FDA0
    if (ctx->r14 != 0) {
        // 0x8000FD08: lw          $v0, 0xDC($a2)
        ctx->r2 = MEM_W(ctx->r6, 0XDC);
            goto L_8000FDA0;
    }
    goto skip_3;
    // 0x8000FD08: lw          $v0, 0xDC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XDC);
    skip_3:
    // 0x8000FD0C: lw          $v0, 0xD8($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XD8);
    // 0x8000FD10: andi        $t7, $v0, 0x8000
    ctx->r15 = ctx->r2 & 0X8000;
    // 0x8000FD14: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8000FD18: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8000FD1C: beql        $fp, $t9, L_8000FDA0
    if (ctx->r30 == ctx->r25) {
        // 0x8000FD20: lw          $v0, 0xDC($a2)
        ctx->r2 = MEM_W(ctx->r6, 0XDC);
            goto L_8000FDA0;
    }
    goto skip_4;
    // 0x8000FD20: lw          $v0, 0xDC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XDC);
    skip_4:
    // 0x8000FD24: sll         $fp, $t9, 16
    ctx->r30 = S32(ctx->r25 << 16);
    // 0x8000FD28: sra         $t6, $fp, 16
    ctx->r14 = S32(SIGNED(ctx->r30) >> 16);
    // 0x8000FD2C: beq         $t9, $zero, L_8000FD68
    if (ctx->r25 == 0) {
        // 0x8000FD30: or          $fp, $t6, $zero
        ctx->r30 = ctx->r14 | 0;
            goto L_8000FD68;
    }
    // 0x8000FD30: or          $fp, $t6, $zero
    ctx->r30 = ctx->r14 | 0;
    // 0x8000FD34: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8000FD38: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8000FD3C: lui         $t7, 0xB700
    ctx->r15 = S32(0XB700 << 16);
    // 0x8000FD40: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8000FD44: lui         $t8, 0xFC12
    ctx->r24 = S32(0XFC12 << 16);
    // 0x8000FD48: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8000FD4C: sw          $ra, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r31;
    // 0x8000FD50: ori         $t8, $t8, 0x7E24
    ctx->r24 = ctx->r24 | 0X7E24;
    // 0x8000FD54: addiu       $t9, $zero, -0xC07
    ctx->r25 = ADD32(0, -0XC07);
    // 0x8000FD58: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8000FD5C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000FD60: b           L_8000FD9C
    // 0x8000FD64: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
        goto L_8000FD9C;
    // 0x8000FD64: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
L_8000FD68:
    // 0x8000FD68: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8000FD6C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8000FD70: lui         $t6, 0xB600
    ctx->r14 = S32(0XB600 << 16);
    // 0x8000FD74: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8000FD78: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8000FD7C: sw          $ra, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r31;
    // 0x8000FD80: lui         $t7, 0xFCFF
    ctx->r15 = S32(0XFCFF << 16);
    // 0x8000FD84: lui         $t8, 0xFFFC
    ctx->r24 = S32(0XFFFC << 16);
    // 0x8000FD88: ori         $t8, $t8, 0xF279
    ctx->r24 = ctx->r24 | 0XF279;
    // 0x8000FD8C: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x8000FD90: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8000FD94: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8000FD98: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
L_8000FD9C:
    // 0x8000FD9C: lw          $v0, 0xDC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XDC);
L_8000FDA0:
    // 0x8000FDA0: beql        $v0, $zero, L_80010020
    if (ctx->r2 == 0) {
        // 0x8000FDA4: lw          $t6, 0xD0($a2)
        ctx->r14 = MEM_W(ctx->r6, 0XD0);
            goto L_80010020;
    }
    goto skip_5;
    // 0x8000FDA4: lw          $t6, 0xD0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XD0);
    skip_5:
    // 0x8000FDA8: lh          $t9, 0x1E($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X1E);
    // 0x8000FDAC: bne         $t2, $t9, L_8000FDC8
    if (ctx->r10 != ctx->r25) {
        // 0x8000FDB0: nop
    
            goto L_8000FDC8;
    }
    // 0x8000FDB0: nop

    // 0x8000FDB4: lh          $a0, 0x18($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X18);
    // 0x8000FDB8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000FDBC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8000FDC0: bne         $a0, $at, L_8000FDD0
    if (ctx->r4 != ctx->r1) {
        // 0x8000FDC4: sll         $t6, $a0, 3
        ctx->r14 = S32(ctx->r4 << 3);
            goto L_8000FDD0;
    }
    // 0x8000FDC4: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
L_8000FDC8:
    // 0x8000FDC8: b           L_8001001C
    // 0x8000FDCC: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
        goto L_8001001C;
    // 0x8000FDCC: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
L_8000FDD0:
    // 0x8000FDD0: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8000FDD4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8000FDD8: addiu       $t7, $t7, -0x6048
    ctx->r15 = ADD32(ctx->r15, -0X6048);
    // 0x8000FDDC: beq         $s0, $a0, L_8001001C
    if (ctx->r16 == ctx->r4) {
        // 0x8000FDE0: addu        $v1, $t6, $t7
        ctx->r3 = ADD32(ctx->r14, ctx->r15);
            goto L_8001001C;
    }
    // 0x8000FDE0: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x8000FDE4: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8000FDE8: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x8000FDEC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8000FDF0: lw          $t9, 0x18($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X18);
    // 0x8000FDF4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8000FDF8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8000FDFC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8000FE00: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x8000FE04: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8000FE08: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8000FE0C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8000FE10: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8000FE14: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8000FE18: lui         $t7, 0xF500
    ctx->r15 = S32(0XF500 << 16);
    // 0x8000FE1C: ori         $t7, $t7, 0x100
    ctx->r15 = ctx->r15 | 0X100;
    // 0x8000FE20: or          $t4, $a3, $zero
    ctx->r12 = ctx->r7 | 0;
    // 0x8000FE24: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8000FE28: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8000FE2C: sw          $s4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r20;
    // 0x8000FE30: or          $t5, $a3, $zero
    ctx->r13 = ctx->r7 | 0;
    // 0x8000FE34: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8000FE38: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x8000FE3C: sw          $s5, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r21;
    // 0x8000FE40: lui         $t9, 0x73F
    ctx->r25 = S32(0X73F << 16);
    // 0x8000FE44: ori         $t9, $t9, 0xC000
    ctx->r25 = ctx->r25 | 0XC000;
    // 0x8000FE48: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8000FE4C: lui         $t8, 0xF000
    ctx->r24 = S32(0XF000 << 16);
    // 0x8000FE50: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
    // 0x8000FE54: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    // 0x8000FE58: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8000FE5C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8000FE60: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x8000FE64: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8000FE68: lui         $t6, 0xFD50
    ctx->r14 = S32(0XFD50 << 16);
    // 0x8000FE6C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8000FE70: lw          $t7, 0x18($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X18);
    // 0x8000FE74: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8000FE78: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8000FE7C: addiu       $t8, $t7, 0x200
    ctx->r24 = ADD32(ctx->r15, 0X200);
    // 0x8000FE80: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8000FE84: lui         $t9, 0xF550
    ctx->r25 = S32(0XF550 << 16);
    // 0x8000FE88: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8000FE8C: lh          $t6, 0x6($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X6);
    // 0x8000FE90: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8000FE94: or          $t4, $a3, $zero
    ctx->r12 = ctx->r7 | 0;
    // 0x8000FE98: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x8000FE9C: lh          $t6, 0x4($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X4);
    // 0x8000FEA0: sll         $t8, $t7, 14
    ctx->r24 = S32(ctx->r15 << 14);
    // 0x8000FEA4: or          $t9, $t8, $s4
    ctx->r25 = ctx->r24 | ctx->r20;
    // 0x8000FEA8: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x8000FEAC: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8000FEB0: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x8000FEB4: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x8000FEB8: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8000FEBC: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x8000FEC0: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x8000FEC4: sw          $s5, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r21;
    // 0x8000FEC8: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x8000FECC: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8000FED0: lh          $t9, 0x2($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X2);
    // 0x8000FED4: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x8000FED8: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8000FEDC: addiu       $t5, $zero, 0x7FF
    ctx->r13 = ADD32(0, 0X7FF);
    // 0x8000FEE0: multu       $v0, $t9
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000FEE4: mflo        $a0
    ctx->r4 = lo;
    // 0x8000FEE8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8000FEEC: sra         $t8, $a0, 1
    ctx->r24 = S32(SIGNED(ctx->r4) >> 1);
    // 0x8000FEF0: addiu       $a0, $t8, -0x1
    ctx->r4 = ADD32(ctx->r24, -0X1);
    // 0x8000FEF4: slti        $at, $a0, 0x7FF
    ctx->r1 = SIGNED(ctx->r4) < 0X7FF ? 1 : 0;
    // 0x8000FEF8: beq         $at, $zero, L_8000FF08
    if (ctx->r1 == 0) {
        // 0x8000FEFC: nop
    
            goto L_8000FF08;
    }
    // 0x8000FEFC: nop

    // 0x8000FF00: b           L_8000FF08
    // 0x8000FF04: or          $t5, $a0, $zero
    ctx->r13 = ctx->r4 | 0;
        goto L_8000FF08;
    // 0x8000FF04: or          $t5, $a0, $zero
    ctx->r13 = ctx->r4 | 0;
L_8000FF08:
    // 0x8000FF08: bgez        $v0, L_8000FF18
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000FF0C: sra         $a0, $v0, 3
        ctx->r4 = S32(SIGNED(ctx->r2) >> 3);
            goto L_8000FF18;
    }
    // 0x8000FF0C: sra         $a0, $v0, 3
    ctx->r4 = S32(SIGNED(ctx->r2) >> 3);
    // 0x8000FF10: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x8000FF14: sra         $a0, $at, 3
    ctx->r4 = S32(SIGNED(ctx->r1) >> 3);
L_8000FF18:
    // 0x8000FF18: bgtz        $a0, L_8000FF28
    if (SIGNED(ctx->r4) > 0) {
        // 0x8000FF1C: or          $s0, $a0, $zero
        ctx->r16 = ctx->r4 | 0;
            goto L_8000FF28;
    }
    // 0x8000FF1C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000FF20: b           L_8000FF28
    // 0x8000FF24: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
        goto L_8000FF28;
    // 0x8000FF24: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
L_8000FF28:
    // 0x8000FF28: bgtz        $a0, L_8000FF38
    if (SIGNED(ctx->r4) > 0) {
        // 0x8000FF2C: addiu       $t6, $s0, 0x7FF
        ctx->r14 = ADD32(ctx->r16, 0X7FF);
            goto L_8000FF38;
    }
    // 0x8000FF2C: addiu       $t6, $s0, 0x7FF
    ctx->r14 = ADD32(ctx->r16, 0X7FF);
    // 0x8000FF30: b           L_8000FF3C
    // 0x8000FF34: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
        goto L_8000FF3C;
    // 0x8000FF34: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_8000FF38:
    // 0x8000FF38: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8000FF3C:
    // 0x8000FF3C: div         $zero, $t6, $v0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r2)));
    // 0x8000FF40: mflo        $t7
    ctx->r15 = lo;
    // 0x8000FF44: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x8000FF48: bne         $v0, $zero, L_8000FF54
    if (ctx->r2 != 0) {
        // 0x8000FF4C: nop
    
            goto L_8000FF54;
    }
    // 0x8000FF4C: nop

    // 0x8000FF50: break       7
    do_break(2147549008);
L_8000FF54:
    // 0x8000FF54: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000FF58: bne         $v0, $at, L_8000FF6C
    if (ctx->r2 != ctx->r1) {
        // 0x8000FF5C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8000FF6C;
    }
    // 0x8000FF5C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000FF60: bne         $t6, $at, L_8000FF6C
    if (ctx->r14 != ctx->r1) {
        // 0x8000FF64: nop
    
            goto L_8000FF6C;
    }
    // 0x8000FF64: nop

    // 0x8000FF68: break       6
    do_break(2147549032);
L_8000FF6C:
    // 0x8000FF6C: andi        $t6, $t5, 0xFFF
    ctx->r14 = ctx->r13 & 0XFFF;
    // 0x8000FF70: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x8000FF74: or          $t8, $t9, $s4
    ctx->r24 = ctx->r25 | ctx->r20;
    // 0x8000FF78: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x8000FF7C: sw          $t9, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r25;
    // 0x8000FF80: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8000FF84: sw          $s6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r22;
    // 0x8000FF88: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8000FF8C: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x8000FF90: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8000FF94: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8000FF98: addiu       $t8, $t6, 0x7
    ctx->r24 = ADD32(ctx->r14, 0X7);
    // 0x8000FF9C: sra         $t7, $t8, 3
    ctx->r15 = S32(SIGNED(ctx->r24) >> 3);
    // 0x8000FFA0: andi        $t9, $t7, 0x1FF
    ctx->r25 = ctx->r15 & 0X1FF;
    // 0x8000FFA4: sll         $t6, $t9, 9
    ctx->r14 = S32(ctx->r25 << 9);
    // 0x8000FFA8: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x8000FFAC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8000FFB0: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8000FFB4: lh          $t7, 0x6($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X6);
    // 0x8000FFB8: lh          $t8, 0x4($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X4);
    // 0x8000FFBC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8000FFC0: andi        $t9, $t7, 0xF
    ctx->r25 = ctx->r15 & 0XF;
    // 0x8000FFC4: sll         $t6, $t9, 14
    ctx->r14 = S32(ctx->r25 << 14);
    // 0x8000FFC8: andi        $t7, $t8, 0xF
    ctx->r15 = ctx->r24 & 0XF;
    // 0x8000FFCC: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x8000FFD0: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x8000FFD4: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x8000FFD8: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x8000FFDC: or          $t4, $a3, $zero
    ctx->r12 = ctx->r7 | 0;
    // 0x8000FFE0: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x8000FFE4: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x8000FFE8: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8000FFEC: addiu       $t9, $t6, -0x1
    ctx->r25 = ADD32(ctx->r14, -0X1);
    // 0x8000FFF0: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8000FFF4: lh          $t9, 0x2($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X2);
    // 0x8000FFF8: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8000FFFC: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x80010000: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x80010004: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x80010008: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x8001000C: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x80010010: sw          $t8, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r24;
    // 0x80010014: lw          $t7, 0xDC($a2)
    ctx->r15 = MEM_W(ctx->r6, 0XDC);
    // 0x80010018: lh          $s0, 0x18($t7)
    ctx->r16 = MEM_H(ctx->r15, 0X18);
L_8001001C:
    // 0x8001001C: lw          $t6, 0xD0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XD0);
L_80010020:
    // 0x80010020: or          $t5, $a2, $zero
    ctx->r13 = ctx->r6 | 0;
    // 0x80010024: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x80010028: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x8001002C: beql        $t4, $zero, L_800101D0
    if (ctx->r12 == 0) {
        // 0x80010030: lw          $v0, 0x0($t5)
        ctx->r2 = MEM_W(ctx->r13, 0X0);
            goto L_800101D0;
    }
    goto skip_6;
    // 0x80010030: lw          $v0, 0x0($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X0);
    skip_6:
    // 0x80010034: lw          $v0, 0xC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XC);
L_80010038:
    // 0x80010038: beql        $v0, $t2, L_80010064
    if (ctx->r2 == ctx->r10) {
        // 0x8001003C: lw          $t9, 0xD0($a2)
        ctx->r25 = MEM_W(ctx->r6, 0XD0);
            goto L_80010064;
    }
    goto skip_7;
    // 0x8001003C: lw          $t9, 0xD0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XD0);
    skip_7:
    // 0x80010040: beq         $v0, $t3, L_80010098
    if (ctx->r2 == ctx->r11) {
        // 0x80010044: or          $v1, $a3, $zero
        ctx->r3 = ctx->r7 | 0;
            goto L_80010098;
    }
    // 0x80010044: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x80010048: beql        $v0, $s2, L_800100F4
    if (ctx->r2 == ctx->r18) {
        // 0x8001004C: lw          $t6, 0xD4($a2)
        ctx->r14 = MEM_W(ctx->r6, 0XD4);
            goto L_800100F4;
    }
    goto skip_8;
    // 0x8001004C: lw          $t6, 0xD4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XD4);
    skip_8:
    // 0x80010050: beql        $v0, $s3, L_8001014C
    if (ctx->r2 == ctx->r19) {
        // 0x80010054: lw          $a0, 0xD4($a2)
        ctx->r4 = MEM_W(ctx->r6, 0XD4);
            goto L_8001014C;
    }
    goto skip_9;
    // 0x80010054: lw          $a0, 0xD4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XD4);
    skip_9:
    // 0x80010058: b           L_800101C0
    // 0x8001005C: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
        goto L_800101C0;
    // 0x8001005C: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x80010060: lw          $t9, 0xD0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XD0);
L_80010064:
    // 0x80010064: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x80010068: addiu       $t8, $a2, 0x90
    ctx->r24 = ADD32(ctx->r6, 0X90);
    // 0x8001006C: beql        $t9, $zero, L_800101C0
    if (ctx->r25 == 0) {
        // 0x80010070: or          $a2, $t4, $zero
        ctx->r6 = ctx->r12 | 0;
            goto L_800101C0;
    }
    goto skip_10;
    // 0x80010070: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    skip_10:
    // 0x80010074: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80010078: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8001007C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80010080: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x80010084: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80010088: lw          $t7, 0xD0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0XD0);
    // 0x8001008C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80010090: b           L_800101BC
    // 0x80010094: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
        goto L_800101BC;
    // 0x80010094: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
L_80010098:
    // 0x80010098: addiu       $t6, $a2, 0x90
    ctx->r14 = ADD32(ctx->r6, 0X90);
    // 0x8001009C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800100A0: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800100A4: lw          $t9, 0xD4($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XD4);
    // 0x800100A8: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x800100AC: lw          $v0, 0xD0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XD0);
    // 0x800100B0: blez        $t9, L_800101BC
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800100B4: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800101BC;
    }
    // 0x800100B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800100B8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800100BC: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800100C0:
    // 0x800100C0: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x800100C4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800100C8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800100CC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800100D0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800100D4: lw          $t7, 0xD4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0XD4);
    // 0x800100D8: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x800100DC: slt         $at, $a1, $t7
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800100E0: bnel        $at, $zero, L_800100C0
    if (ctx->r1 != 0) {
        // 0x800100E4: or          $v0, $a3, $zero
        ctx->r2 = ctx->r7 | 0;
            goto L_800100C0;
    }
    goto skip_11;
    // 0x800100E4: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    skip_11:
    // 0x800100E8: b           L_800101C0
    // 0x800100EC: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
        goto L_800101C0;
    // 0x800100EC: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x800100F0: lw          $t6, 0xD4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XD4);
L_800100F4:
    // 0x800100F4: lw          $v0, 0xD0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XD0);
    // 0x800100F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800100FC: blez        $t6, L_800101BC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80010100: or          $v1, $a3, $zero
        ctx->r3 = ctx->r7 | 0;
            goto L_800101BC;
    }
    // 0x80010100: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
L_80010104:
    // 0x80010104: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80010108: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8001010C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80010110: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80010114: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80010118: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x8001011C: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x80010120: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80010124: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80010128: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8001012C: lw          $t7, 0xD4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0XD4);
    // 0x80010130: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80010134: slt         $at, $a1, $t7
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80010138: bnel        $at, $zero, L_80010104
    if (ctx->r1 != 0) {
        // 0x8001013C: or          $v1, $a3, $zero
        ctx->r3 = ctx->r7 | 0;
            goto L_80010104;
    }
    goto skip_12;
    // 0x8001013C: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    skip_12:
    // 0x80010140: b           L_800101C0
    // 0x80010144: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
        goto L_800101C0;
    // 0x80010144: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x80010148: lw          $a0, 0xD4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XD4);
L_8001014C:
    // 0x8001014C: lw          $v1, 0xD0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0XD0);
    // 0x80010150: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80010154: blezl       $a0, L_800101C0
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80010158: or          $a2, $t4, $zero
        ctx->r6 = ctx->r12 | 0;
            goto L_800101C0;
    }
    goto skip_13;
    // 0x80010158: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    skip_13:
L_8001015C:
    // 0x8001015C: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x80010160: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80010164: beql        $v0, $t2, L_80010180
    if (ctx->r2 == ctx->r10) {
        // 0x80010168: or          $v0, $a3, $zero
        ctx->r2 = ctx->r7 | 0;
            goto L_80010180;
    }
    goto skip_14;
    // 0x80010168: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    skip_14:
    // 0x8001016C: beql        $v0, $t3, L_8001019C
    if (ctx->r2 == ctx->r11) {
        // 0x80010170: or          $v0, $a3, $zero
        ctx->r2 = ctx->r7 | 0;
            goto L_8001019C;
    }
    goto skip_15;
    // 0x80010170: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    skip_15:
    // 0x80010174: b           L_800101B4
    // 0x80010178: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
        goto L_800101B4;
    // 0x80010178: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001017C: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_80010180:
    // 0x80010180: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80010184: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x80010188: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8001018C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80010190: b           L_800101B0
    // 0x80010194: lw          $a0, 0xD4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XD4);
        goto L_800101B0;
    // 0x80010194: lw          $a0, 0xD4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XD4);
    // 0x80010198: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_8001019C:
    // 0x8001019C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x800101A0: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x800101A4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x800101A8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800101AC: lw          $a0, 0xD4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XD4);
L_800101B0:
    // 0x800101B0: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
L_800101B4:
    // 0x800101B4: bne         $at, $zero, L_8001015C
    if (ctx->r1 != 0) {
        // 0x800101B8: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_8001015C;
    }
    // 0x800101B8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_800101BC:
    // 0x800101BC: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
L_800101C0:
    // 0x800101C0: lw          $t4, 0x0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X0);
    // 0x800101C4: bnel        $t4, $zero, L_80010038
    if (ctx->r12 != 0) {
        // 0x800101C8: lw          $v0, 0xC($a2)
        ctx->r2 = MEM_W(ctx->r6, 0XC);
            goto L_80010038;
    }
    goto skip_16;
    // 0x800101C8: lw          $v0, 0xC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XC);
    skip_16:
    // 0x800101CC: lw          $v0, 0x0($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X0);
L_800101D0:
    // 0x800101D0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_800101D4:
    // 0x800101D4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800101D8: bnel        $v0, $zero, L_8000FC7C
    if (ctx->r2 != 0) {
        // 0x800101DC: lw          $t9, 0xC($a2)
        ctx->r25 = MEM_W(ctx->r6, 0XC);
            goto L_8000FC7C;
    }
    goto skip_17;
    // 0x800101DC: lw          $t9, 0xC($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XC);
    skip_17:
L_800101E0:
    // 0x800101E0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800101E4: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x800101E8: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x800101EC: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x800101F0: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x800101F4: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x800101F8: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x800101FC: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x80010200: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x80010204: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x80010208: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001020C: jr          $ra
    // 0x80010210: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    TRACE_RETURN()
    return;
    // 0x80010210: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
;}
RECOMP_FUNC void func_80010220(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80010220: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80010224: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80010228: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001022C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80010230: jal         0x8000C7C0
    // 0x80010234: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8000C7C0(rdram, ctx);
        goto after_0;
    // 0x80010234: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80010238: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8001023C: jal         0x8000C7C0
    // 0x80010240: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_8000C7C0(rdram, ctx);
        goto after_1;
    // 0x80010240: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_1:
    // 0x80010244: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80010248: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8001024C: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x80010250: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80010254: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
    // 0x80010258: sw          $a2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r6;
    // 0x8001025C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80010260: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80010264: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8001026C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8001026C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80010270: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80010274: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80010278: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001027C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80010280: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80010284: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80010288: jal         0x80004364
    // 0x8001028C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x8001028C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80010290: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80010294: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80010298: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001029C: lw          $t6, 0x4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X4);
    // 0x800102A0: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x800102A4: lw          $t7, 0x4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4);
    // 0x800102A8: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x800102AC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800102B0: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x800102B4: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800102B8: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x800102BC: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800102C0: sw          $t9, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r25;
    // 0x800102C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800102C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800102CC: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800102D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800102D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800102D8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800102DC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800102E0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800102E4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800102E8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800102EC: lw          $s1, 0x0($a1)
    ctx->r17 = MEM_W(ctx->r5, 0X0);
    // 0x800102F0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800102F4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800102F8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800102FC: beq         $v0, $zero, L_8001034C
    if (ctx->r2 == 0) {
        // 0x80010300: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_8001034C;
    }
L_80010300:
    // 0x80010300: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80010304: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80010308: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x8001030C: jal         0x800042A8
    // 0x80010310: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    func_800042A8(rdram, ctx);
        goto after_0;
    // 0x80010310: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    after_0:
    // 0x80010314: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80010318: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x8001031C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80010320: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80010324: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80010328: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8001032C: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x80010330: jal         0x800042A8
    // 0x80010334: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    func_800042A8(rdram, ctx);
        goto after_1;
    // 0x80010334: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    after_1:
    // 0x80010338: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8001033C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80010340: sll         $t0, $s2, 16
    ctx->r8 = S32(ctx->r18 << 16);
    // 0x80010344: bne         $v0, $zero, L_80010300
    if (ctx->r2 != 0) {
        // 0x80010348: sra         $s2, $t0, 16
        ctx->r18 = S32(SIGNED(ctx->r8) >> 16);
            goto L_80010300;
    }
    // 0x80010348: sra         $s2, $t0, 16
    ctx->r18 = S32(SIGNED(ctx->r8) >> 16);
L_8001034C:
    // 0x8001034C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80010350: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80010354: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80010358: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8001035C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80010360: jr          $ra
    // 0x80010364: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    TRACE_RETURN()
    return;
    // 0x80010364: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80010370(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80010370: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80010374: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80010378: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001037C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80010380: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80010384: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80010388: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001038C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80010390: addiu       $a0, $a0, -0x6C30
    ctx->r4 = ADD32(ctx->r4, -0X6C30);
    // 0x80010394: addiu       $v1, $v1, -0x6C40
    ctx->r3 = ADD32(ctx->r3, -0X6C40);
    // 0x80010398: addiu       $v0, $v0, -0x6C50
    ctx->r2 = ADD32(ctx->r2, -0X6C50);
    // 0x8001039C: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x800103A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800103A4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800103A8: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x800103AC: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x800103B0: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x800103B4: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x800103B8: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x800103BC: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x800103C0: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x800103C4: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x800103C8: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x800103CC: jr          $ra
    // 0x800103D0: swc1        $f8, -0x6C24($at)
    MEM_W(-0X6C24, ctx->r1) = ctx->f8.u32l;
    TRACE_RETURN()
    return;
    // 0x800103D0: swc1        $f8, -0x6C24($at)
    MEM_W(-0X6C24, ctx->r1) = ctx->f8.u32l;
;}
