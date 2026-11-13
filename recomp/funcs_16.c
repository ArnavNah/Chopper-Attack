#include "recomp.h"
#include "trace.h"
#include "funcs.h"

RECOMP_FUNC void func_800396E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800396E8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800396EC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800396F0: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_800396F4:
    // 0x800396F4: lw          $t6, 0x9C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X9C);
    // 0x800396F8: beq         $t6, $zero, L_8003971C
    if (ctx->r14 == 0) {
        // 0x800396FC: nop
    
            goto L_8003971C;
    }
    // 0x800396FC: nop

    // 0x80039700: lwc1        $f4, 0x94($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X94);
    // 0x80039704: lwc1        $f6, 0xA4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XA4);
    // 0x80039708: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003970C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80039710: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80039714: bne         $v1, $v0, L_800396F4
    if (ctx->r3 != ctx->r2) {
        // 0x80039718: swc1        $f8, 0x90($a1)
        MEM_W(0X90, ctx->r5) = ctx->f8.u32l;
            goto L_800396F4;
    }
    // 0x80039718: swc1        $f8, 0x90($a1)
    MEM_W(0X90, ctx->r5) = ctx->f8.u32l;
L_8003971C:
    // 0x8003971C: jr          $ra
    TRACE_RETURN()
    return;
;}
static void func_80039724_entry(uint8_t* rdram, recomp_context* ctx, unsigned entry) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    if (entry == 1) goto indirect_800397D0;

    // 0x80039724: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80039728: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8003972C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80039730: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80039734: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80039738: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8003973C: jal         0x80004364
    // 0x80039740: addiu       $a1, $zero, 0xFC
    ctx->r5 = ADD32(0, 0XFC);
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x80039740: addiu       $a1, $zero, 0xFC
    ctx->r5 = ADD32(0, 0XFC);
    after_0:
    // 0x80039744: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80039748: addiu       $a1, $zero, 0xFC
    ctx->r5 = ADD32(0, 0XFC);
    // 0x8003974C: jal         0x8000C7C0
    // 0x80039750: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8000C7C0(rdram, ctx);
        goto after_1;
    // 0x80039750: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80039754: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80039758: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8003975C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80039760: addiu       $a1, $a1, -0x660C
    ctx->r5 = ADD32(ctx->r5, -0X660C);
    // 0x80039764: sh          $t6, 0x8C($v1)
    MEM_H(0X8C, ctx->r3) = ctx->r14;
    // 0x80039768: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8003976C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80039770: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80039774: sw          $v1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r3;
    // 0x80039778: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8003977C: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80039780: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x80039784: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x80039788: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8003978C: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x80039790: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80039794: sw          $v1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r3;
    // 0x80039798: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
L_8003979C:
    // 0x8003979C: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800397A0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800397A4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800397A8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800397AC: bne         $v0, $a1, L_8003979C
    if (ctx->r2 != ctx->r5) {
        // 0x800397B0: swc1        $f4, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
            goto L_8003979C;
    }
    // 0x800397B0: swc1        $f4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
    // 0x800397B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800397B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800397BC: jr          $ra
    // 0x800397C0: nop

    TRACE_RETURN()
    return;
    // 0x800397C0: nop

    // 0x800397C4: nop

    // 0x800397C8: nop

    // 0x800397CC: nop

indirect_800397D0:
    // 0x800397D0: addiu       $sp, $sp, -0x110
    ctx->r29 = ADD32(ctx->r29, -0X110);
    // 0x800397D4: sw          $a0, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r4;
    // 0x800397D8: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x800397DC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800397E0: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x800397E4: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x800397E8: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x800397EC: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x800397F0: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x800397F4: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x800397F8: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800397FC: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80039800: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80039804: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80039808: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8003980C: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80039810: jal         0x80004364
    // 0x80039814: addiu       $a1, $zero, 0xCC
    ctx->r5 = ADD32(0, 0XCC);
    func_80004364(rdram, ctx);
        goto after_2;
    // 0x80039814: addiu       $a1, $zero, 0xCC
    ctx->r5 = ADD32(0, 0XCC);
    after_2:
    // 0x80039818: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8003981C: addiu       $v1, $v1, -0x65A0
    ctx->r3 = ADD32(ctx->r3, -0X65A0);
    // 0x80039820: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80039824: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80039828: jal         0x8000C7C0
    // 0x8003982C: addiu       $a1, $zero, 0xCC
    ctx->r5 = ADD32(0, 0XCC);
    func_8000C7C0(rdram, ctx);
        goto after_3;
    // 0x8003982C: addiu       $a1, $zero, 0xCC
    ctx->r5 = ADD32(0, 0XCC);
    after_3:
    // 0x80039830: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80039834: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80039838: jal         0x80004364
    // 0x8003983C: addiu       $a1, $zero, 0xCC
    ctx->r5 = ADD32(0, 0XCC);
    func_80004364(rdram, ctx);
        goto after_4;
    // 0x8003983C: addiu       $a1, $zero, 0xCC
    ctx->r5 = ADD32(0, 0XCC);
    after_4:
    // 0x80039840: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80039844: addiu       $v1, $v1, -0x659C
    ctx->r3 = ADD32(ctx->r3, -0X659C);
    // 0x80039848: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8003984C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80039850: jal         0x8000C7C0
    // 0x80039854: addiu       $a1, $zero, 0xCC
    ctx->r5 = ADD32(0, 0XCC);
    func_8000C7C0(rdram, ctx);
        goto after_5;
    // 0x80039854: addiu       $a1, $zero, 0xCC
    ctx->r5 = ADD32(0, 0XCC);
    after_5:
    // 0x80039858: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8003985C: lw          $t6, -0x65A0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X65A0);
    // 0x80039860: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80039864: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80039868: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x8003986C: lw          $t7, -0x659C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X659C);
    // 0x80039870: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80039874: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80039878: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x8003987C: lw          $t9, -0x65A0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X65A0);
    // 0x80039880: lw          $t8, -0x659C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X659C);
    // 0x80039884: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80039888: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003988C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80039890: lw          $t1, -0x659C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X659C);
    // 0x80039894: lw          $t0, -0x65A0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X65A0);
    // 0x80039898: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x8003989C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800398A0: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x800398A4: lh          $v0, -0x6B80($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X6B80);
    // 0x800398A8: bne         $fp, $v0, L_800398BC
    if (ctx->r30 != ctx->r2) {
        // 0x800398AC: nop
    
            goto L_800398BC;
    }
    // 0x800398AC: nop

    // 0x800398B0: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800398B4: b           L_80039CF4
    // 0x800398B8: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
        goto L_80039CF4;
    // 0x800398B8: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
L_800398BC:
    // 0x800398BC: bne         $v0, $at, L_80039908
    if (ctx->r2 != ctx->r1) {
        // 0x800398C0: lui         $t4, 0x8013
        ctx->r12 = S32(0X8013 << 16);
            goto L_80039908;
    }
    // 0x800398C0: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800398C4: lui         $s1, 0x8007
    ctx->r17 = S32(0X8007 << 16);
    // 0x800398C8: addiu       $s1, $s1, 0x1F0
    ctx->r17 = ADD32(ctx->r17, 0X1F0);
    // 0x800398CC: lw          $t2, 0x74($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X74);
    // 0x800398D0: lw          $t3, 0x70($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X70);
    // 0x800398D4: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800398D8: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x800398DC: subu        $s0, $t2, $t3
    ctx->r16 = SUB32(ctx->r10, ctx->r11);
    // 0x800398E0: jal         0x80004364
    // 0x800398E4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80004364(rdram, ctx);
        goto after_6;
    // 0x800398E4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x800398E8: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    // 0x800398EC: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x800398F0: lw          $a0, 0x70($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X70);
    // 0x800398F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800398F8: jal         0x8000C5FC
    // 0x800398FC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    dma_read_rom(rdram, ctx);
        goto after_7;
    // 0x800398FC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_7:
    // 0x80039900: b           L_80039970
    // 0x80039904: lbu         $t1, 0x0($s5)
    ctx->r9 = MEM_BU(ctx->r21, 0X0);
        goto L_80039970;
    // 0x80039904: lbu         $t1, 0x0($s5)
    ctx->r9 = MEM_BU(ctx->r21, 0X0);
L_80039908:
    // 0x80039908: lh          $t4, -0x662C($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X662C);
    // 0x8003990C: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
    // 0x80039910: lui         $s1, 0x8007
    ctx->r17 = S32(0X8007 << 16);
    // 0x80039914: multu       $t4, $s2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80039918: addiu       $s1, $s1, 0x1F0
    ctx->r17 = ADD32(ctx->r17, 0X1F0);
    // 0x8003991C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80039920: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80039924: mflo        $t5
    ctx->r13 = lo;
    // 0x80039928: addu        $v0, $s1, $t5
    ctx->r2 = ADD32(ctx->r17, ctx->r13);
    // 0x8003992C: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x80039930: lw          $t7, -0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X8);
    // 0x80039934: subu        $s0, $t6, $t7
    ctx->r16 = SUB32(ctx->r14, ctx->r15);
    // 0x80039938: jal         0x80004364
    // 0x8003993C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80004364(rdram, ctx);
        goto after_8;
    // 0x8003993C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x80039940: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80039944: lh          $t8, -0x662C($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X662C);
    // 0x80039948: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    // 0x8003994C: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80039950: multu       $t8, $s2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80039954: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80039958: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8003995C: mflo        $t9
    ctx->r25 = lo;
    // 0x80039960: addu        $t0, $s1, $t9
    ctx->r8 = ADD32(ctx->r17, ctx->r25);
    // 0x80039964: jal         0x8000C5FC
    // 0x80039968: lw          $a0, -0x8($t0)
    ctx->r4 = MEM_W(ctx->r8, -0X8);
    dma_read_rom(rdram, ctx);
        goto after_9;
    // 0x80039968: lw          $a0, -0x8($t0)
    ctx->r4 = MEM_W(ctx->r8, -0X8);
    after_9:
    // 0x8003996C: lbu         $t1, 0x0($s5)
    ctx->r9 = MEM_BU(ctx->r21, 0X0);
L_80039970:
    // 0x80039970: addiu       $s7, $zero, 0x20
    ctx->r23 = ADD32(0, 0X20);
    // 0x80039974: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x80039978: beq         $s7, $t1, L_80039CDC
    if (ctx->r23 == ctx->r9) {
        // 0x8003997C: addiu       $s6, $s6, 0x6AC8
        ctx->r22 = ADD32(ctx->r22, 0X6AC8);
            goto L_80039CDC;
    }
    // 0x8003997C: addiu       $s6, $s6, 0x6AC8
    ctx->r22 = ADD32(ctx->r22, 0X6AC8);
    // 0x80039980: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80039984: addiu       $s4, $zero, 0x8
    ctx->r20 = ADD32(0, 0X8);
    // 0x80039988: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
    // 0x8003998C: lw          $t2, 0x0($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X0);
L_80039990:
    // 0x80039990: lui         $at, 0x6172
    ctx->r1 = S32(0X6172 << 16);
    // 0x80039994: ori         $at, $at, 0x6D30
    ctx->r1 = ctx->r1 | 0X6D30;
    // 0x80039998: bnel        $t2, $at, L_800399D0
    if (ctx->r10 != ctx->r1) {
        // 0x8003999C: lw          $v0, 0x24($s5)
        ctx->r2 = MEM_W(ctx->r21, 0X24);
            goto L_800399D0;
    }
    goto skip_0;
    // 0x8003999C: lw          $v0, 0x24($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X24);
    skip_0:
    // 0x800399A0: lw          $t3, 0x0($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X0);
    // 0x800399A4: addiu       $s0, $s5, 0xC
    ctx->r16 = ADD32(ctx->r21, 0XC);
    // 0x800399A8: andi        $t4, $t3, 0x8
    ctx->r12 = ctx->r11 & 0X8;
    // 0x800399AC: bnel        $t4, $zero, L_800399D0
    if (ctx->r12 != 0) {
        // 0x800399B0: lw          $v0, 0x24($s5)
        ctx->r2 = MEM_W(ctx->r21, 0X24);
            goto L_800399D0;
    }
    goto skip_1;
    // 0x800399B0: lw          $v0, 0x24($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X24);
    skip_1:
    // 0x800399B4: jal         0x80024F1C
    // 0x800399B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80024F1C(rdram, ctx);
        goto after_10;
    // 0x800399B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x800399BC: jal         0x80024F1C
    // 0x800399C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80024F1C(rdram, ctx);
        goto after_11;
    // 0x800399C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x800399C4: b           L_80039CD0
    // 0x800399C8: lbu         $t0, 0x28($s5)
    ctx->r8 = MEM_BU(ctx->r21, 0X28);
        goto L_80039CD0;
    // 0x800399C8: lbu         $t0, 0x28($s5)
    ctx->r8 = MEM_BU(ctx->r21, 0X28);
    // 0x800399CC: lw          $v0, 0x24($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X24);
L_800399D0:
    // 0x800399D0: lui         $at, 0x3F
    ctx->r1 = S32(0X3F << 16);
    // 0x800399D4: andi        $t5, $v0, 0x8
    ctx->r13 = ctx->r2 & 0X8;
    // 0x800399D8: beq         $t5, $zero, L_80039A68
    if (ctx->r13 == 0) {
        // 0x800399DC: and         $t2, $v0, $at
        ctx->r10 = ctx->r2 & ctx->r1;
            goto L_80039A68;
    }
    // 0x800399DC: and         $t2, $v0, $at
    ctx->r10 = ctx->r2 & ctx->r1;
    // 0x800399E0: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
    // 0x800399E4: addiu       $a1, $zero, 0xCC
    ctx->r5 = ADD32(0, 0XCC);
    // 0x800399E8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800399EC: andi        $t7, $t6, 0x8
    ctx->r15 = ctx->r14 & 0X8;
    // 0x800399F0: beq         $t7, $zero, L_80039A58
    if (ctx->r15 == 0) {
        // 0x800399F4: nop
    
            goto L_80039A58;
    }
    // 0x800399F4: nop

    // 0x800399F8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800399FC: jal         0x80004364
    // 0x80039A00: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    func_80004364(rdram, ctx);
        goto after_12;
    // 0x80039A00: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    after_12:
    // 0x80039A04: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80039A08: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80039A0C: jal         0x8000C7C0
    // 0x80039A10: addiu       $a1, $zero, 0xCC
    ctx->r5 = ADD32(0, 0XCC);
    func_8000C7C0(rdram, ctx);
        goto after_13;
    // 0x80039A10: addiu       $a1, $zero, 0xCC
    ctx->r5 = ADD32(0, 0XCC);
    after_13:
    // 0x80039A14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80039A18: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80039A1C: or          $v1, $s5, $zero
    ctx->r3 = ctx->r21 | 0;
L_80039A20:
    // 0x80039A20: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x80039A24: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80039A28: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80039A2C: sb          $t8, 0x80($v0)
    MEM_B(0X80, ctx->r2) = ctx->r24;
    // 0x80039A30: lbu         $t9, 0x1($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1);
    // 0x80039A34: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80039A38: sb          $t9, 0x81($v0)
    MEM_B(0X81, ctx->r2) = ctx->r25;
    // 0x80039A3C: lbu         $t0, -0x2($v1)
    ctx->r8 = MEM_BU(ctx->r3, -0X2);
    // 0x80039A40: sb          $t0, 0x82($v0)
    MEM_B(0X82, ctx->r2) = ctx->r8;
    // 0x80039A44: lbu         $t1, -0x1($v1)
    ctx->r9 = MEM_BU(ctx->r3, -0X1);
    // 0x80039A48: bne         $a0, $s4, L_80039A20
    if (ctx->r4 != ctx->r20) {
        // 0x80039A4C: sb          $t1, 0x83($v0)
        MEM_B(0X83, ctx->r2) = ctx->r9;
            goto L_80039A20;
    }
    // 0x80039A4C: sb          $t1, 0x83($v0)
    MEM_B(0X83, ctx->r2) = ctx->r9;
    // 0x80039A50: b           L_80039C44
    // 0x80039A54: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
        goto L_80039C44;
    // 0x80039A54: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
L_80039A58:
    // 0x80039A58: jal         0x80024C4C
    // 0x80039A5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80024C4C(rdram, ctx);
        goto after_14;
    // 0x80039A5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x80039A60: b           L_80039CD0
    // 0x80039A64: lbu         $t0, 0x28($s5)
    ctx->r8 = MEM_BU(ctx->r21, 0X28);
        goto L_80039CD0;
    // 0x80039A64: lbu         $t0, 0x28($s5)
    ctx->r8 = MEM_BU(ctx->r21, 0X28);
L_80039A68:
    // 0x80039A68: beq         $t2, $zero, L_80039BFC
    if (ctx->r10 == 0) {
        // 0x80039A6C: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80039BFC;
    }
    // 0x80039A6C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80039A70: lw          $t3, 0x0($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X0);
    // 0x80039A74: srl         $s2, $v0, 16
    ctx->r18 = S32(U32(ctx->r2) >> 16);
    // 0x80039A78: andi        $t9, $s2, 0x3F
    ctx->r25 = ctx->r18 & 0X3F;
    // 0x80039A7C: andi        $t4, $t3, 0x8
    ctx->r12 = ctx->r11 & 0X8;
    // 0x80039A80: beq         $t4, $zero, L_80039AEC
    if (ctx->r12 == 0) {
        // 0x80039A84: sll         $t0, $t9, 16
        ctx->r8 = S32(ctx->r25 << 16);
            goto L_80039AEC;
    }
    // 0x80039A84: sll         $t0, $t9, 16
    ctx->r8 = S32(ctx->r25 << 16);
    // 0x80039A88: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80039A8C: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80039A90: jal         0x80004364
    // 0x80039A94: addiu       $a1, $zero, 0xCC
    ctx->r5 = ADD32(0, 0XCC);
    func_80004364(rdram, ctx);
        goto after_15;
    // 0x80039A94: addiu       $a1, $zero, 0xCC
    ctx->r5 = ADD32(0, 0XCC);
    after_15:
    // 0x80039A98: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80039A9C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80039AA0: jal         0x8000C7C0
    // 0x80039AA4: addiu       $a1, $zero, 0xCC
    ctx->r5 = ADD32(0, 0XCC);
    func_8000C7C0(rdram, ctx);
        goto after_16;
    // 0x80039AA4: addiu       $a1, $zero, 0xCC
    ctx->r5 = ADD32(0, 0XCC);
    after_16:
    // 0x80039AA8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80039AAC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80039AB0: or          $v1, $s5, $zero
    ctx->r3 = ctx->r21 | 0;
L_80039AB4:
    // 0x80039AB4: lbu         $t5, 0x0($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X0);
    // 0x80039AB8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80039ABC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80039AC0: sb          $t5, 0x80($v0)
    MEM_B(0X80, ctx->r2) = ctx->r13;
    // 0x80039AC4: lbu         $t6, 0x1($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1);
    // 0x80039AC8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80039ACC: sb          $t6, 0x81($v0)
    MEM_B(0X81, ctx->r2) = ctx->r14;
    // 0x80039AD0: lbu         $t7, -0x2($v1)
    ctx->r15 = MEM_BU(ctx->r3, -0X2);
    // 0x80039AD4: sb          $t7, 0x82($v0)
    MEM_B(0X82, ctx->r2) = ctx->r15;
    // 0x80039AD8: lbu         $t8, -0x1($v1)
    ctx->r24 = MEM_BU(ctx->r3, -0X1);
    // 0x80039ADC: bne         $a0, $s4, L_80039AB4
    if (ctx->r4 != ctx->r20) {
        // 0x80039AE0: sb          $t8, 0x83($v0)
        MEM_B(0X83, ctx->r2) = ctx->r24;
            goto L_80039AB4;
    }
    // 0x80039AE0: sb          $t8, 0x83($v0)
    MEM_B(0X83, ctx->r2) = ctx->r24;
    // 0x80039AE4: b           L_80039C44
    // 0x80039AE8: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
        goto L_80039C44;
    // 0x80039AE8: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
L_80039AEC:
    // 0x80039AEC: sra         $s2, $t0, 16
    ctx->r18 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80039AF0: slti        $at, $s2, 0x21
    ctx->r1 = SIGNED(ctx->r18) < 0X21 ? 1 : 0;
    // 0x80039AF4: bne         $at, $zero, L_80039BB8
    if (ctx->r1 != 0) {
        // 0x80039AF8: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80039BB8;
    }
    // 0x80039AF8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80039AFC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80039B00: lh          $v0, -0x662C($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X662C);
    // 0x80039B04: sll         $a0, $fp, 16
    ctx->r4 = S32(ctx->r30 << 16);
    // 0x80039B08: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80039B0C: beq         $v0, $fp, L_80039B28
    if (ctx->r2 == ctx->r30) {
        // 0x80039B10: or          $a0, $t2, $zero
        ctx->r4 = ctx->r10 | 0;
            goto L_80039B28;
    }
    // 0x80039B10: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x80039B14: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80039B18: beq         $v0, $at, L_80039B68
    if (ctx->r2 == ctx->r1) {
        // 0x80039B1C: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_80039B68;
    }
    // 0x80039B1C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80039B20: b           L_80039BB0
    // 0x80039B24: sll         $s1, $fp, 16
    ctx->r17 = S32(ctx->r30 << 16);
        goto L_80039BB0;
    // 0x80039B24: sll         $s1, $fp, 16
    ctx->r17 = S32(ctx->r30 << 16);
L_80039B28:
    // 0x80039B28: andi        $s0, $s2, 0xF
    ctx->r16 = ctx->r18 & 0XF;
    // 0x80039B2C: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    // 0x80039B30: sra         $t3, $a1, 16
    ctx->r11 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80039B34: jal         0x8003A114
    // 0x80039B38: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    func_8003A114(rdram, ctx);
        goto after_17;
    // 0x80039B38: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_17:
    // 0x80039B3C: beq         $v0, $zero, L_80039BAC
    if (ctx->r2 == 0) {
        // 0x80039B40: lui         $t4, 0x8013
        ctx->r12 = S32(0X8013 << 16);
            goto L_80039BAC;
    }
    // 0x80039B40: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80039B44: lh          $t4, -0x6B78($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X6B78);
    // 0x80039B48: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80039B4C: beql        $t4, $s0, L_80039BB0
    if (ctx->r12 == ctx->r16) {
        // 0x80039B50: sll         $s1, $fp, 16
        ctx->r17 = S32(ctx->r30 << 16);
            goto L_80039BB0;
    }
    goto skip_2;
    // 0x80039B50: sll         $s1, $fp, 16
    ctx->r17 = S32(ctx->r30 << 16);
    skip_2:
    // 0x80039B54: lh          $t5, -0x6B76($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X6B76);
    // 0x80039B58: beql        $t5, $s0, L_80039BB0
    if (ctx->r13 == ctx->r16) {
        // 0x80039B5C: sll         $s1, $fp, 16
        ctx->r17 = S32(ctx->r30 << 16);
            goto L_80039BB0;
    }
    goto skip_3;
    // 0x80039B5C: sll         $s1, $fp, 16
    ctx->r17 = S32(ctx->r30 << 16);
    skip_3:
    // 0x80039B60: b           L_80039CD0
    // 0x80039B64: lbu         $t0, 0x28($s5)
    ctx->r8 = MEM_BU(ctx->r21, 0X28);
        goto L_80039CD0;
    // 0x80039B64: lbu         $t0, 0x28($s5)
    ctx->r8 = MEM_BU(ctx->r21, 0X28);
L_80039B68:
    // 0x80039B68: andi        $s0, $s2, 0xF
    ctx->r16 = ctx->r18 & 0XF;
    // 0x80039B6C: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    // 0x80039B70: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80039B74: jal         0x8003A114
    // 0x80039B78: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    func_8003A114(rdram, ctx);
        goto after_18;
    // 0x80039B78: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_18:
    // 0x80039B7C: beq         $v0, $zero, L_80039BAC
    if (ctx->r2 == 0) {
        // 0x80039B80: lui         $t7, 0x8013
        ctx->r15 = S32(0X8013 << 16);
            goto L_80039BAC;
    }
    // 0x80039B80: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80039B84: lh          $t7, -0x6B74($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X6B74);
    // 0x80039B88: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80039B8C: beql        $t7, $s0, L_80039BB0
    if (ctx->r15 == ctx->r16) {
        // 0x80039B90: sll         $s1, $fp, 16
        ctx->r17 = S32(ctx->r30 << 16);
            goto L_80039BB0;
    }
    goto skip_4;
    // 0x80039B90: sll         $s1, $fp, 16
    ctx->r17 = S32(ctx->r30 << 16);
    skip_4:
    // 0x80039B94: lh          $t8, -0x6B72($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X6B72);
    // 0x80039B98: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80039B9C: beql        $t8, $s0, L_80039BB0
    if (ctx->r24 == ctx->r16) {
        // 0x80039BA0: sll         $s1, $fp, 16
        ctx->r17 = S32(ctx->r30 << 16);
            goto L_80039BB0;
    }
    goto skip_5;
    // 0x80039BA0: sll         $s1, $fp, 16
    ctx->r17 = S32(ctx->r30 << 16);
    skip_5:
    // 0x80039BA4: lh          $t9, -0x6B70($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X6B70);
    // 0x80039BA8: bne         $t9, $s0, L_80039CCC
    if (ctx->r25 != ctx->r16) {
        // 0x80039BAC: sll         $s1, $fp, 16
        ctx->r17 = S32(ctx->r30 << 16);
            goto L_80039CCC;
    }
L_80039BAC:
    // 0x80039BAC: sll         $s1, $fp, 16
    ctx->r17 = S32(ctx->r30 << 16);
L_80039BB0:
    // 0x80039BB0: sra         $t0, $s1, 16
    ctx->r8 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80039BB4: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
L_80039BB8:
    // 0x80039BB8: andi        $t1, $s2, 0x1F
    ctx->r9 = ctx->r18 & 0X1F;
    // 0x80039BBC: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x80039BC0: sra         $s2, $t2, 16
    ctx->r18 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80039BC4: addiu       $a0, $s2, -0x1
    ctx->r4 = ADD32(ctx->r18, -0X1);
    // 0x80039BC8: sll         $t4, $a0, 16
    ctx->r12 = S32(ctx->r4 << 16);
    // 0x80039BCC: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80039BD0: addiu       $a1, $s5, 0xC
    ctx->r5 = ADD32(ctx->r21, 0XC);
    // 0x80039BD4: jal         0x80035764
    // 0x80039BD8: addiu       $a2, $s5, 0x18
    ctx->r6 = ADD32(ctx->r21, 0X18);
    func_80035764(rdram, ctx);
        goto after_19;
    // 0x80039BD8: addiu       $a2, $s5, 0x18
    ctx->r6 = ADD32(ctx->r21, 0X18);
    after_19:
    // 0x80039BDC: beq         $s1, $zero, L_80039CCC
    if (ctx->r17 == 0) {
        // 0x80039BE0: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80039CCC;
    }
    // 0x80039BE0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80039BE4: andi        $a1, $s2, 0xF
    ctx->r5 = ctx->r18 & 0XF;
    // 0x80039BE8: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80039BEC: jal         0x80024C4C
    // 0x80039BF0: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    func_80024C4C(rdram, ctx);
        goto after_20;
    // 0x80039BF0: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    after_20:
    // 0x80039BF4: b           L_80039CD0
    // 0x80039BF8: lbu         $t0, 0x28($s5)
    ctx->r8 = MEM_BU(ctx->r21, 0X28);
        goto L_80039CD0;
    // 0x80039BF8: lbu         $t0, 0x28($s5)
    ctx->r8 = MEM_BU(ctx->r21, 0X28);
L_80039BFC:
    // 0x80039BFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80039C00: jal         0x8003DE20
    // 0x80039C04: addiu       $a2, $s5, 0x18
    ctx->r6 = ADD32(ctx->r21, 0X18);
    func_8003DE20(rdram, ctx);
        goto after_21;
    // 0x80039C04: addiu       $a2, $s5, 0x18
    ctx->r6 = ADD32(ctx->r21, 0X18);
    after_21:
    // 0x80039C08: beq         $v0, $zero, L_80039CCC
    if (ctx->r2 == 0) {
        // 0x80039C0C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80039CCC;
    }
    // 0x80039C0C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80039C10: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    // 0x80039C14: lui         $at, 0x6865
    ctx->r1 = S32(0X6865 << 16);
    // 0x80039C18: ori         $at, $at, 0x7269
    ctx->r1 = ctx->r1 | 0X7269;
    // 0x80039C1C: bnel        $t8, $at, L_80039C44
    if (ctx->r24 != ctx->r1) {
        // 0x80039C20: lwc1        $f4, 0x2C($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
            goto L_80039C44;
    }
    goto skip_6;
    // 0x80039C20: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    skip_6:
    // 0x80039C24: lw          $t9, 0x0($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X0);
    // 0x80039C28: andi        $t0, $t9, 0x8
    ctx->r8 = ctx->r25 & 0X8;
    // 0x80039C2C: bnel        $t0, $zero, L_80039C44
    if (ctx->r8 != 0) {
        // 0x80039C30: lwc1        $f4, 0x2C($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
            goto L_80039C44;
    }
    goto skip_7;
    // 0x80039C30: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    skip_7:
    // 0x80039C34: jal         0x80036CD4
    // 0x80039C38: addiu       $a0, $s5, 0xC
    ctx->r4 = ADD32(ctx->r21, 0XC);
    func_80036CD4(rdram, ctx);
        goto after_22;
    // 0x80039C38: addiu       $a0, $s5, 0xC
    ctx->r4 = ADD32(ctx->r21, 0XC);
    after_22:
    // 0x80039C3C: sw          $v0, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->r2;
    // 0x80039C40: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
L_80039C44:
    // 0x80039C44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80039C48: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80039C4C: c.eq.s      $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f22.fl == ctx->f4.fl;
    // 0x80039C50: or          $v1, $s5, $zero
    ctx->r3 = ctx->r21 | 0;
    // 0x80039C54: bc1f        L_80039C64
    if (!c1cs) {
        // 0x80039C58: nop
    
            goto L_80039C64;
    }
    // 0x80039C58: nop

    // 0x80039C5C: lwc1        $f6, 0x8($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0X8);
    // 0x80039C60: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
L_80039C64:
    // 0x80039C64: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80039C68: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80039C6C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80039C70: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x80039C74: lwc1        $f10, 0x18($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80039C78: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80039C7C: bne         $a0, $s3, L_80039C64
    if (ctx->r4 != ctx->r19) {
        // 0x80039C80: swc1        $f10, 0x18($v0)
        MEM_W(0X18, ctx->r2) = ctx->f10.u32l;
            goto L_80039C64;
    }
    // 0x80039C80: swc1        $f10, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f10.u32l;
    // 0x80039C84: lw          $t1, 0x80($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X80);
    // 0x80039C88: lw          $t2, 0x24($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X24);
    // 0x80039C8C: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80039C90: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80039C94: or          $t3, $t1, $t2
    ctx->r11 = ctx->r9 | ctx->r10;
    // 0x80039C98: sw          $t3, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->r11;
    // 0x80039C9C: lw          $t4, -0x659C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X659C);
    // 0x80039CA0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80039CA4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80039CA8: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x80039CAC: sw          $s0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r16;
    // 0x80039CB0: lw          $t6, -0x659C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X659C);
    // 0x80039CB4: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80039CB8: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x80039CBC: lw          $t8, -0x659C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X659C);
    // 0x80039CC0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80039CC4: lw          $t9, -0x659C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X659C);
    // 0x80039CC8: sw          $s0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r16;
L_80039CCC:
    // 0x80039CCC: lbu         $t0, 0x28($s5)
    ctx->r8 = MEM_BU(ctx->r21, 0X28);
L_80039CD0:
    // 0x80039CD0: addiu       $s5, $s5, 0x28
    ctx->r21 = ADD32(ctx->r21, 0X28);
    // 0x80039CD4: bnel        $s7, $t0, L_80039990
    if (ctx->r23 != ctx->r8) {
        // 0x80039CD8: lw          $t2, 0x0($s5)
        ctx->r10 = MEM_W(ctx->r21, 0X0);
            goto L_80039990;
    }
    goto skip_8;
    // 0x80039CD8: lw          $t2, 0x0($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X0);
    skip_8:
L_80039CDC:
    // 0x80039CDC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80039CE0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80039CE4: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
    // 0x80039CE8: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80039CEC: jal         0x800042A8
    // 0x80039CF0: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    func_800042A8(rdram, ctx);
        goto after_23;
    // 0x80039CF0: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    after_23:
L_80039CF4:
    // 0x80039CF4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80039CF8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80039CFC: addiu       $s7, $zero, -0x2
    ctx->r23 = ADD32(0, -0X2);
    // 0x80039D00: lui         $s6, 0x8000
    ctx->r22 = S32(0X8000 << 16);
    // 0x80039D04: addiu       $s5, $zero, -0x2
    ctx->r21 = ADD32(0, -0X2);
    // 0x80039D08: lw          $s4, 0x100($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X100);
    // 0x80039D0C: addiu       $s2, $sp, 0x80
    ctx->r18 = ADD32(ctx->r29, 0X80);
    // 0x80039D10: addiu       $s1, $sp, 0xC0
    ctx->r17 = ADD32(ctx->r29, 0XC0);
    // 0x80039D14: lw          $t1, 0x110($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X110);
L_80039D18:
    // 0x80039D18: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80039D1C: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x80039D20: bne         $v0, $at, L_80039DA4
    if (ctx->r2 != ctx->r1) {
        // 0x80039D24: lui         $a1, 0x8013
        ctx->r5 = S32(0X8013 << 16);
            goto L_80039DA4;
    }
    // 0x80039D24: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80039D28: lw          $a1, -0x65A0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X65A0);
    // 0x80039D2C: lw          $s0, 0x0($a1)
    ctx->r16 = MEM_W(ctx->r5, 0X0);
    // 0x80039D30: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80039D34: beq         $t2, $zero, L_80039D60
    if (ctx->r10 == 0) {
        // 0x80039D38: nop
    
            goto L_80039D60;
    }
    // 0x80039D38: nop

    // 0x80039D3C: lw          $s4, 0x0($s0)
    ctx->r20 = MEM_W(ctx->r16, 0X0);
L_80039D40:
    // 0x80039D40: jal         0x8003A008
    // 0x80039D44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003A008(rdram, ctx);
        goto after_24;
    // 0x80039D44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80039D48: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x80039D4C: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x80039D50: bnel        $t3, $zero, L_80039D40
    if (ctx->r11 != 0) {
        // 0x80039D54: lw          $s4, 0x0($s0)
        ctx->r20 = MEM_W(ctx->r16, 0X0);
            goto L_80039D40;
    }
    goto skip_9;
    // 0x80039D54: lw          $s4, 0x0($s0)
    ctx->r20 = MEM_W(ctx->r16, 0X0);
    skip_9:
    // 0x80039D58: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80039D5C: lw          $a1, -0x65A0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X65A0);
L_80039D60:
    // 0x80039D60: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80039D64: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80039D68: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80039D6C: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x80039D70: jal         0x800042A8
    // 0x80039D74: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800042A8(rdram, ctx);
        goto after_25;
    // 0x80039D74: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_25:
    // 0x80039D78: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80039D7C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80039D80: lw          $a1, -0x659C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X659C);
    // 0x80039D84: jal         0x800042A8
    // 0x80039D88: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    func_800042A8(rdram, ctx);
        goto after_26;
    // 0x80039D88: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    after_26:
    // 0x80039D8C: lw          $t4, 0x110($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X110);
    // 0x80039D90: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
L_80039D94:
    // 0x80039D94: jal         0x8000798C
    // 0x80039D98: nop

    func_8000798C(rdram, ctx);
        goto after_27;
    // 0x80039D98: nop

    after_27:
    // 0x80039D9C: b           L_80039D94
    // 0x80039DA0: nop

        goto L_80039D94;
    // 0x80039DA0: nop

L_80039DA4:
    // 0x80039DA4: bne         $s5, $v0, L_80039DCC
    if (ctx->r21 != ctx->r2) {
        // 0x80039DA8: nop
    
            goto L_80039DCC;
    }
    // 0x80039DA8: nop

    // 0x80039DAC: bne         $s5, $v0, L_80039DCC
    if (ctx->r21 != ctx->r2) {
        // 0x80039DB0: nop
    
            goto L_80039DCC;
    }
    // 0x80039DB0: nop

L_80039DB4:
    // 0x80039DB4: jal         0x8000798C
    // 0x80039DB8: nop

    func_8000798C(rdram, ctx);
        goto after_28;
    // 0x80039DB8: nop

    after_28:
    // 0x80039DBC: lw          $t5, 0x110($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X110);
    // 0x80039DC0: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80039DC4: beq         $s5, $t6, L_80039DB4
    if (ctx->r21 == ctx->r14) {
        // 0x80039DC8: nop
    
            goto L_80039DB4;
    }
    // 0x80039DC8: nop

L_80039DCC:
    // 0x80039DCC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80039DD0: lw          $t7, -0x65A0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X65A0);
    // 0x80039DD4: lw          $s0, 0x0($t7)
    ctx->r16 = MEM_W(ctx->r15, 0X0);
L_80039DD8:
    // 0x80039DD8: lw          $s4, 0x0($s0)
    ctx->r20 = MEM_W(ctx->r16, 0X0);
    // 0x80039DDC: beq         $s4, $zero, L_80039FB8
    if (ctx->r20 == 0) {
        // 0x80039DE0: nop
    
            goto L_80039FB8;
    }
    // 0x80039DE0: nop

    // 0x80039DE4: lh          $v0, 0x7C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X7C);
    // 0x80039DE8: beq         $v0, $zero, L_80039E08
    if (ctx->r2 == 0) {
        // 0x80039DEC: nop
    
            goto L_80039E08;
    }
    // 0x80039DEC: nop

    // 0x80039DF0: beq         $v0, $fp, L_80039F40
    if (ctx->r2 == ctx->r30) {
        // 0x80039DF4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80039F40;
    }
    // 0x80039DF4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80039DF8: beq         $v0, $at, L_80039FA4
    if (ctx->r2 == ctx->r1) {
        // 0x80039DFC: nop
    
            goto L_80039FA4;
    }
    // 0x80039DFC: nop

    // 0x80039E00: b           L_80039DD8
    // 0x80039E04: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
        goto L_80039DD8;
    // 0x80039E04: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
L_80039E08:
    // 0x80039E08: jal         0x80049CFC
    // 0x80039E0C: addiu       $a0, $s0, 0x84
    ctx->r4 = ADD32(ctx->r16, 0X84);
    func_80049CFC(rdram, ctx);
        goto after_29;
    // 0x80039E0C: addiu       $a0, $s0, 0x84
    ctx->r4 = ADD32(ctx->r16, 0X84);
    after_29:
    // 0x80039E10: sh          $v0, 0x8C($s0)
    MEM_H(0X8C, ctx->r16) = ctx->r2;
    // 0x80039E14: jal         0x80049D80
    // 0x80039E18: lh          $a0, 0x8C($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X8C);
    func_80049D80(rdram, ctx);
        goto after_30;
    // 0x80039E18: lh          $a0, 0x8C($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X8C);
    after_30:
    // 0x80039E1C: lw          $t8, 0x80($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X80);
    // 0x80039E20: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x80039E24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80039E28: andi        $t9, $t8, 0x4
    ctx->r25 = ctx->r24 & 0X4;
    // 0x80039E2C: beq         $t9, $zero, L_80039E3C
    if (ctx->r25 == 0) {
        // 0x80039E30: nop
    
            goto L_80039E3C;
    }
    // 0x80039E30: nop

    // 0x80039E34: b           L_80039E3C
    // 0x80039E38: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
        goto L_80039E3C;
    // 0x80039E38: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
L_80039E3C:
    // 0x80039E3C: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80039E40: jal         0x80049DFC
    // 0x80039E44: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80049DFC(rdram, ctx);
        goto after_31;
    // 0x80039E44: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_31:
    // 0x80039E48: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x80039E4C: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x80039E50: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80039E54: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80039E58: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x80039E5C: jal         0x80049840
    // 0x80039E60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80049840(rdram, ctx);
        goto after_32;
    // 0x80039E60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_32:
    // 0x80039E64: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    // 0x80039E68: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80039E6C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80039E70: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x80039E74: jal         0x80049840
    // 0x80039E78: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80049840(rdram, ctx);
        goto after_33;
    // 0x80039E78: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_33:
    // 0x80039E7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80039E80: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80039E84: jal         0x80000BD8
    // 0x80039E88: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_80000BD8(rdram, ctx);
        goto after_34;
    // 0x80039E88: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_34:
    // 0x80039E8C: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    // 0x80039E90: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80039E94: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80039E98: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80039E9C: jal         0x80049840
    // 0x80039EA0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80049840(rdram, ctx);
        goto after_35;
    // 0x80039EA0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_35:
    // 0x80039EA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80039EA8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80039EAC: jal         0x80000BD8
    // 0x80039EB0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_80000BD8(rdram, ctx);
        goto after_36;
    // 0x80039EB0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_36:
    // 0x80039EB4: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80039EB8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80039EBC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80039EC0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80039EC4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80039EC8: jal         0x80001AB4
    // 0x80039ECC: nop

    func_80001AB4(rdram, ctx);
        goto after_37;
    // 0x80039ECC: nop

    after_37:
    // 0x80039ED0: lw          $t0, 0xC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XC);
    // 0x80039ED4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80039ED8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80039EDC: lw          $a0, 0x8($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X8);
    // 0x80039EE0: jal         0x80000BD8
    // 0x80039EE4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80000BD8(rdram, ctx);
        goto after_38;
    // 0x80039EE4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_38:
    // 0x80039EE8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80039EEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80039EF0: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
L_80039EF4:
    // 0x80039EF4: lw          $t1, 0xC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XC);
    // 0x80039EF8: lwc1        $f16, 0x10($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80039EFC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80039F00: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x80039F04: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80039F08: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x80039F0C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80039F10: bne         $a0, $s3, L_80039EF4
    if (ctx->r4 != ctx->r19) {
        // 0x80039F14: swc1        $f16, 0x40($t3)
        MEM_W(0X40, ctx->r11) = ctx->f16.u32l;
            goto L_80039EF4;
    }
    // 0x80039F14: swc1        $f16, 0x40($t3)
    MEM_W(0X40, ctx->r11) = ctx->f16.u32l;
    // 0x80039F18: sh          $zero, 0x90($s0)
    MEM_H(0X90, ctx->r16) = 0;
    // 0x80039F1C: jal         0x8003E1FC
    // 0x80039F20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003E1FC(rdram, ctx);
        goto after_39;
    // 0x80039F20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_39:
    // 0x80039F24: jal         0x8003E3B8
    // 0x80039F28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003E3B8(rdram, ctx);
        goto after_40;
    // 0x80039F28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_40:
    // 0x80039F2C: jal         0x8004A148
    // 0x80039F30: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    func_8004A148(rdram, ctx);
        goto after_41;
    // 0x80039F30: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    after_41:
    // 0x80039F34: sh          $fp, 0x7C($s0)
    MEM_H(0X7C, ctx->r16) = ctx->r30;
    // 0x80039F38: b           L_80039DD8
    // 0x80039F3C: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
        goto L_80039DD8;
    // 0x80039F3C: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
L_80039F40:
    // 0x80039F40: lw          $v0, 0x80($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X80);
    // 0x80039F44: and         $t4, $v0, $s6
    ctx->r12 = ctx->r2 & ctx->r22;
    // 0x80039F48: beq         $t4, $zero, L_80039F58
    if (ctx->r12 == 0) {
        // 0x80039F4C: ori         $t5, $v0, 0x1
        ctx->r13 = ctx->r2 | 0X1;
            goto L_80039F58;
    }
    // 0x80039F4C: ori         $t5, $v0, 0x1
    ctx->r13 = ctx->r2 | 0X1;
    // 0x80039F50: b           L_80039F84
    // 0x80039F54: sw          $t5, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->r13;
        goto L_80039F84;
    // 0x80039F54: sw          $t5, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->r13;
L_80039F58:
    // 0x80039F58: jal         0x8000E074
    // 0x80039F5C: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    func_8000E074(rdram, ctx);
        goto after_42;
    // 0x80039F5C: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    after_42:
    // 0x80039F60: beql        $v0, $zero, L_80039F7C
    if (ctx->r2 == 0) {
        // 0x80039F64: lw          $t8, 0x80($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X80);
            goto L_80039F7C;
    }
    goto skip_10;
    // 0x80039F64: lw          $t8, 0x80($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X80);
    skip_10:
    // 0x80039F68: lw          $t6, 0x80($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X80);
    // 0x80039F6C: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x80039F70: b           L_80039F84
    // 0x80039F74: sw          $t7, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->r15;
        goto L_80039F84;
    // 0x80039F74: sw          $t7, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->r15;
    // 0x80039F78: lw          $t8, 0x80($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X80);
L_80039F7C:
    // 0x80039F7C: and         $t9, $t8, $s7
    ctx->r25 = ctx->r24 & ctx->r23;
    // 0x80039F80: sw          $t9, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->r25;
L_80039F84:
    // 0x80039F84: lw          $t1, 0xC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XC);
    // 0x80039F88: lw          $t0, 0x80($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X80);
    // 0x80039F8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80039F90: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x80039F94: jal         0x8003E3B8
    // 0x80039F98: sw          $t0, 0xD8($t2)
    MEM_W(0XD8, ctx->r10) = ctx->r8;
    func_8003E3B8(rdram, ctx);
        goto after_43;
    // 0x80039F98: sw          $t0, 0xD8($t2)
    MEM_W(0XD8, ctx->r10) = ctx->r8;
    after_43:
    // 0x80039F9C: b           L_80039DD8
    // 0x80039FA0: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
        goto L_80039DD8;
    // 0x80039FA0: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
L_80039FA4:
    // 0x80039FA4: jal         0x8004A0C4
    // 0x80039FA8: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    func_8004A0C4(rdram, ctx);
        goto after_44;
    // 0x80039FA8: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    after_44:
    // 0x80039FAC: sh          $s3, 0x7C($s0)
    MEM_H(0X7C, ctx->r16) = ctx->r19;
    // 0x80039FB0: b           L_80039DD8
    // 0x80039FB4: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
        goto L_80039DD8;
    // 0x80039FB4: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
L_80039FB8:
    // 0x80039FB8: jal         0x8001F704
    // 0x80039FBC: nop

    func_8001F704(rdram, ctx);
        goto after_45;
    // 0x80039FBC: nop

    after_45:
    // 0x80039FC0: jal         0x8000798C
    // 0x80039FC4: nop

    func_8000798C(rdram, ctx);
        goto after_46;
    // 0x80039FC4: nop

    after_46:
    // 0x80039FC8: b           L_80039D18
    // 0x80039FCC: lw          $t1, 0x110($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X110);
        goto L_80039D18;
    // 0x80039FCC: lw          $t1, 0x110($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X110);
    // 0x80039FD0: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80039FD4: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80039FD8: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80039FDC: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80039FE0: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80039FE4: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80039FE8: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80039FEC: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80039FF0: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80039FF4: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80039FF8: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x80039FFC: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8003A000: jr          $ra
    // 0x8003A004: addiu       $sp, $sp, 0x110
    ctx->r29 = ADD32(ctx->r29, 0X110);
    TRACE_RETURN()
    return;
    // 0x8003A004: addiu       $sp, $sp, 0x110
    ctx->r29 = ADD32(ctx->r29, 0X110);
;}
RECOMP_FUNC void func_80039724(uint8_t* rdram, recomp_context* ctx) { func_80039724_entry(rdram, ctx, 0); }
RECOMP_FUNC void func_800397D0(uint8_t* rdram, recomp_context* ctx) { func_80039724_entry(rdram, ctx, 1); }

RECOMP_FUNC void func_8003A008(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8003A008: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003A00C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003A010: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8003A014: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x8003A018: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8003A01C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8003A020: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8003A024: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x8003A028: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8003A02C: lw          $a0, 0xC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC);
    // 0x8003A030: jal         0x8004A0C4
    // 0x8003A034: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_8004A0C4(rdram, ctx);
        goto after_0;
    // 0x8003A034: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8003A038: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8003A03C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8003A040: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8003A044: lh          $t0, 0x34($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X34);
    // 0x8003A048: beq         $t0, $zero, L_8003A060
    if (ctx->r8 == 0) {
        // 0x8003A04C: nop
    
            goto L_8003A060;
    }
    // 0x8003A04C: nop

    // 0x8003A050: lw          $a1, 0x30($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X30);
    // 0x8003A054: jal         0x800042A8
    // 0x8003A058: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800042A8(rdram, ctx);
        goto after_1;
    // 0x8003A058: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x8003A05C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_8003A060:
    // 0x8003A060: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8003A064: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8003A068: jal         0x800042A8
    // 0x8003A06C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800042A8(rdram, ctx);
        goto after_2;
    // 0x8003A06C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_2:
    // 0x8003A070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003A074: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003A078: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8003A080(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8003A080: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8003A084: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8003A088: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8003A08C: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x8003A090: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8003A094: lh          $t8, 0x8C($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X8C);
    // 0x8003A098: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x8003A09C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8003A0A0: bne         $at, $zero, L_8003A108
    if (ctx->r1 != 0) {
        // 0x8003A0A4: sh          $t8, 0x0($a2)
        MEM_H(0X0, ctx->r6) = ctx->r24;
            goto L_8003A108;
    }
    // 0x8003A0A4: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
    // 0x8003A0A8: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8003A0AC: addu        $t1, $t9, $a0
    ctx->r9 = ADD32(ctx->r25, ctx->r4);
    // 0x8003A0B0: addiu       $a3, $a0, 0x4
    ctx->r7 = ADD32(ctx->r4, 0X4);
    // 0x8003A0B4: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
L_8003A0B8:
    // 0x8003A0B8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8003A0BC: blez        $v1, L_8003A0E0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8003A0C0: lh          $a0, 0x8C($v0)
        ctx->r4 = MEM_H(ctx->r2, 0X8C);
            goto L_8003A0E0;
    }
    // 0x8003A0C0: lh          $a0, 0x8C($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X8C);
    // 0x8003A0C4: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_8003A0C8:
    // 0x8003A0C8: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    // 0x8003A0CC: beq         $a0, $t2, L_8003A0E0
    if (ctx->r4 == ctx->r10) {
        // 0x8003A0D0: nop
    
            goto L_8003A0E0;
    }
    // 0x8003A0D0: nop

    // 0x8003A0D4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8003A0D8: bne         $t0, $v1, L_8003A0C8
    if (ctx->r8 != ctx->r3) {
        // 0x8003A0DC: addiu       $v0, $v0, 0x2
        ctx->r2 = ADD32(ctx->r2, 0X2);
            goto L_8003A0C8;
    }
    // 0x8003A0DC: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
L_8003A0E0:
    // 0x8003A0E0: bne         $v1, $t0, L_8003A100
    if (ctx->r3 != ctx->r8) {
        // 0x8003A0E4: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_8003A100;
    }
    // 0x8003A0E4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8003A0E8: sll         $t3, $v1, 1
    ctx->r11 = S32(ctx->r3 << 1);
    // 0x8003A0EC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8003A0F0: addu        $t4, $a2, $t3
    ctx->r12 = ADD32(ctx->r6, ctx->r11);
    // 0x8003A0F4: sll         $t5, $v1, 16
    ctx->r13 = S32(ctx->r3 << 16);
    // 0x8003A0F8: sh          $a0, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r4;
    // 0x8003A0FC: sra         $v1, $t5, 16
    ctx->r3 = S32(SIGNED(ctx->r13) >> 16);
L_8003A100:
    // 0x8003A100: bnel        $a3, $t1, L_8003A0B8
    if (ctx->r7 != ctx->r9) {
        // 0x8003A104: lw          $v0, 0x0($a3)
        ctx->r2 = MEM_W(ctx->r7, 0X0);
            goto L_8003A0B8;
    }
    goto skip_0;
    // 0x8003A104: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    skip_0:
L_8003A108:
    // 0x8003A108: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x8003A10C: jr          $ra
    // 0x8003A110: sh          $v1, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r3;
    TRACE_RETURN()
    return;
    // 0x8003A110: sh          $v1, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r3;
;}
RECOMP_FUNC void func_8003A114(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8003A114: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8003A118: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8003A11C: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8003A120: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8003A124: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x8003A128: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003A12C: bne         $a0, $at, L_8003A178
    if (ctx->r4 != ctx->r1) {
        // 0x8003A130: sra         $a1, $t8, 16
        ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
            goto L_8003A178;
    }
    // 0x8003A130: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8003A134: lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // 0x8003A138: addiu       $v1, $v1, -0x5C50
    ctx->r3 = ADD32(ctx->r3, -0X5C50);
    // 0x8003A13C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003A140: sll         $t0, $v0, 1
    ctx->r8 = S32(ctx->r2 << 1);
L_8003A144:
    // 0x8003A144: addu        $t1, $v1, $t0
    ctx->r9 = ADD32(ctx->r3, ctx->r8);
    // 0x8003A148: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x8003A14C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8003A150: sll         $t3, $v0, 16
    ctx->r11 = S32(ctx->r2 << 16);
    // 0x8003A154: bne         $a1, $t2, L_8003A164
    if (ctx->r5 != ctx->r10) {
        // 0x8003A158: sra         $v0, $t3, 16
        ctx->r2 = S32(SIGNED(ctx->r11) >> 16);
            goto L_8003A164;
    }
    // 0x8003A158: sra         $v0, $t3, 16
    ctx->r2 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8003A15C: jr          $ra
    // 0x8003A160: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    TRACE_RETURN()
    return;
    // 0x8003A160: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003A164:
    // 0x8003A164: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x8003A168: bnel        $at, $zero, L_8003A144
    if (ctx->r1 != 0) {
        // 0x8003A16C: sll         $t0, $v0, 1
        ctx->r8 = S32(ctx->r2 << 1);
            goto L_8003A144;
    }
    goto skip_0;
    // 0x8003A16C: sll         $t0, $v0, 1
    ctx->r8 = S32(ctx->r2 << 1);
    skip_0:
    // 0x8003A170: b           L_8003A1C0
    // 0x8003A174: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003A1C0;
    // 0x8003A174: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003A178:
    // 0x8003A178: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003A17C: bne         $a0, $at, L_8003A1BC
    if (ctx->r4 != ctx->r1) {
        // 0x8003A180: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8003A1BC;
    }
    // 0x8003A180: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003A184: lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // 0x8003A188: addiu       $v1, $v1, -0x5C44
    ctx->r3 = ADD32(ctx->r3, -0X5C44);
    // 0x8003A18C: sll         $t5, $v0, 1
    ctx->r13 = S32(ctx->r2 << 1);
L_8003A190:
    // 0x8003A190: addu        $t6, $v1, $t5
    ctx->r14 = ADD32(ctx->r3, ctx->r13);
    // 0x8003A194: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x8003A198: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8003A19C: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x8003A1A0: bne         $a1, $t7, L_8003A1B0
    if (ctx->r5 != ctx->r15) {
        // 0x8003A1A4: sra         $v0, $t8, 16
        ctx->r2 = S32(SIGNED(ctx->r24) >> 16);
            goto L_8003A1B0;
    }
    // 0x8003A1A4: sra         $v0, $t8, 16
    ctx->r2 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8003A1A8: jr          $ra
    // 0x8003A1AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    TRACE_RETURN()
    return;
    // 0x8003A1AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003A1B0:
    // 0x8003A1B0: slti        $at, $v0, 0x9
    ctx->r1 = SIGNED(ctx->r2) < 0X9 ? 1 : 0;
    // 0x8003A1B4: bnel        $at, $zero, L_8003A190
    if (ctx->r1 != 0) {
        // 0x8003A1B8: sll         $t5, $v0, 1
        ctx->r13 = S32(ctx->r2 << 1);
            goto L_8003A190;
    }
    goto skip_1;
    // 0x8003A1B8: sll         $t5, $v0, 1
    ctx->r13 = S32(ctx->r2 << 1);
    skip_1:
L_8003A1BC:
    // 0x8003A1BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003A1C0:
    // 0x8003A1C0: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8003A1C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8003A1C8: addiu       $sp, $sp, -0x678
    ctx->r29 = ADD32(ctx->r29, -0X678);
    // 0x8003A1CC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8003A1D0: lw          $t6, -0x65A0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X65A0);
    // 0x8003A1D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003A1D8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8003A1DC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8003A1E0: sb          $zero, 0x660($sp)
    MEM_B(0X660, ctx->r29) = 0;
    // 0x8003A1E4: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x8003A1E8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8003A1EC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8003A1F0: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8003A1F4: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8003A1F8: addiu       $t4, $sp, 0x2FC
    ctx->r12 = ADD32(ctx->r29, 0X2FC);
    // 0x8003A1FC: beq         $t7, $zero, L_8003A284
    if (ctx->r15 == 0) {
        // 0x8003A200: addiu       $a2, $sp, 0x3FC
        ctx->r6 = ADD32(ctx->r29, 0X3FC);
            goto L_8003A284;
    }
    // 0x8003A200: addiu       $a2, $sp, 0x3FC
    ctx->r6 = ADD32(ctx->r29, 0X3FC);
    // 0x8003A204: addiu       $a1, $sp, 0x16C
    ctx->r5 = ADD32(ctx->r29, 0X16C);
    // 0x8003A208: lui         $v1, 0x3F
    ctx->r3 = S32(0X3F << 16);
    // 0x8003A20C: lw          $v0, 0x80($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X80);
L_8003A210:
    // 0x8003A210: sll         $t9, $t2, 2
    ctx->r25 = S32(ctx->r10 << 2);
    // 0x8003A214: addu        $t5, $a1, $t9
    ctx->r13 = ADD32(ctx->r5, ctx->r25);
    // 0x8003A218: and         $t8, $v0, $v1
    ctx->r24 = ctx->r2 & ctx->r3;
    // 0x8003A21C: beql        $t8, $zero, L_8003A23C
    if (ctx->r24 == 0) {
        // 0x8003A220: andi        $t8, $v0, 0x8
        ctx->r24 = ctx->r2 & 0X8;
            goto L_8003A23C;
    }
    goto skip_0;
    // 0x8003A220: andi        $t8, $v0, 0x8
    ctx->r24 = ctx->r2 & 0X8;
    skip_0:
    // 0x8003A224: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8003A228: sll         $t6, $t2, 16
    ctx->r14 = S32(ctx->r10 << 16);
    // 0x8003A22C: sra         $t2, $t6, 16
    ctx->r10 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8003A230: b           L_8003A274
    // 0x8003A234: sw          $a0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r4;
        goto L_8003A274;
    // 0x8003A234: sw          $a0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r4;
    // 0x8003A238: andi        $t8, $v0, 0x8
    ctx->r24 = ctx->r2 & 0X8;
L_8003A23C:
    // 0x8003A23C: beq         $t8, $zero, L_8003A25C
    if (ctx->r24 == 0) {
        // 0x8003A240: sll         $t9, $s1, 2
        ctx->r25 = S32(ctx->r17 << 2);
            goto L_8003A25C;
    }
    // 0x8003A240: sll         $t9, $s1, 2
    ctx->r25 = S32(ctx->r17 << 2);
    // 0x8003A244: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8003A248: sll         $t6, $s1, 16
    ctx->r14 = S32(ctx->r17 << 16);
    // 0x8003A24C: addu        $t5, $t4, $t9
    ctx->r13 = ADD32(ctx->r12, ctx->r25);
    // 0x8003A250: sw          $a0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r4;
    // 0x8003A254: b           L_8003A274
    // 0x8003A258: sra         $s1, $t6, 16
    ctx->r17 = S32(SIGNED(ctx->r14) >> 16);
        goto L_8003A274;
    // 0x8003A258: sra         $s1, $t6, 16
    ctx->r17 = S32(SIGNED(ctx->r14) >> 16);
L_8003A25C:
    // 0x8003A25C: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x8003A260: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8003A264: sll         $t5, $s0, 16
    ctx->r13 = S32(ctx->r16 << 16);
    // 0x8003A268: addu        $t9, $a2, $t8
    ctx->r25 = ADD32(ctx->r6, ctx->r24);
    // 0x8003A26C: sw          $a0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r4;
    // 0x8003A270: sra         $s0, $t5, 16
    ctx->r16 = S32(SIGNED(ctx->r13) >> 16);
L_8003A274:
    // 0x8003A274: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x8003A278: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8003A27C: bnel        $t7, $zero, L_8003A210
    if (ctx->r15 != 0) {
        // 0x8003A280: lw          $v0, 0x80($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X80);
            goto L_8003A210;
    }
    goto skip_1;
    // 0x8003A280: lw          $v0, 0x80($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X80);
    skip_1:
L_8003A284:
    // 0x8003A284: beq         $s0, $zero, L_8003A354
    if (ctx->r16 == 0) {
        // 0x8003A288: addiu       $a0, $sp, 0x3FC
        ctx->r4 = ADD32(ctx->r29, 0X3FC);
            goto L_8003A354;
    }
    // 0x8003A288: addiu       $a0, $sp, 0x3FC
    ctx->r4 = ADD32(ctx->r29, 0X3FC);
    // 0x8003A28C: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    // 0x8003A290: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8003A294: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x8003A298: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x8003A29C: addiu       $a3, $sp, 0x36
    ctx->r7 = ADD32(ctx->r29, 0X36);
    // 0x8003A2A0: jal         0x8003A080
    // 0x8003A2A4: sh          $t2, 0x166($sp)
    MEM_H(0X166, ctx->r29) = ctx->r10;
    func_8003A080(rdram, ctx);
        goto after_0;
    // 0x8003A2A4: sh          $t2, 0x166($sp)
    MEM_H(0X166, ctx->r29) = ctx->r10;
    after_0:
    // 0x8003A2A8: lh          $t9, 0x36($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X36);
    // 0x8003A2AC: lh          $t2, 0x166($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X166);
    // 0x8003A2B0: addiu       $t1, $sp, 0x38
    ctx->r9 = ADD32(ctx->r29, 0X38);
    // 0x8003A2B4: blez        $t9, L_8003A354
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8003A2B8: sll         $t6, $t9, 1
        ctx->r14 = S32(ctx->r25 << 1);
            goto L_8003A354;
    }
    // 0x8003A2B8: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x8003A2BC: addu        $t3, $t6, $t1
    ctx->r11 = ADD32(ctx->r14, ctx->r9);
    // 0x8003A2C0: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
L_8003A2C4:
    // 0x8003A2C4: blez        $s0, L_8003A348
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8003A2C8: lh          $a2, 0x0($t1)
        ctx->r6 = MEM_H(ctx->r9, 0X0);
            goto L_8003A348;
    }
    // 0x8003A2C8: lh          $a2, 0x0($t1)
    ctx->r6 = MEM_H(ctx->r9, 0X0);
    // 0x8003A2CC: addiu       $a1, $sp, 0x3FC
    ctx->r5 = ADD32(ctx->r29, 0X3FC);
    // 0x8003A2D0: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x8003A2D4: addu        $a3, $t8, $a1
    ctx->r7 = ADD32(ctx->r24, ctx->r5);
    // 0x8003A2D8: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
L_8003A2DC:
    // 0x8003A2DC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8003A2E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003A2E4: lh          $t9, 0x8C($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X8C);
    // 0x8003A2E8: addiu       $v1, $sp, 0x658
    ctx->r3 = ADD32(ctx->r29, 0X658);
    // 0x8003A2EC: bne         $a2, $t9, L_8003A340
    if (ctx->r6 != ctx->r25) {
        // 0x8003A2F0: nop
    
            goto L_8003A340;
    }
    // 0x8003A2F0: nop

L_8003A2F4:
    // 0x8003A2F4: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x8003A2F8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003A2FC: addu        $t5, $t6, $v0
    ctx->r13 = ADD32(ctx->r14, ctx->r2);
    // 0x8003A300: lbu         $t8, 0x10($t5)
    ctx->r24 = MEM_BU(ctx->r13, 0X10);
    // 0x8003A304: sb          $t8, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r24;
    // 0x8003A308: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8003A30C: addu        $t9, $t7, $v0
    ctx->r25 = ADD32(ctx->r15, ctx->r2);
    // 0x8003A310: lbu         $t6, 0x11($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X11);
    // 0x8003A314: sb          $t6, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r14;
    // 0x8003A318: lw          $t5, 0x8($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X8);
    // 0x8003A31C: addu        $t8, $t5, $v0
    ctx->r24 = ADD32(ctx->r13, ctx->r2);
    // 0x8003A320: lbu         $t7, 0x12($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X12);
    // 0x8003A324: sb          $t7, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r15;
    // 0x8003A328: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x8003A32C: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x8003A330: lbu         $t5, 0x13($t6)
    ctx->r13 = MEM_BU(ctx->r14, 0X13);
    // 0x8003A334: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003A338: bne         $v0, $t0, L_8003A2F4
    if (ctx->r2 != ctx->r8) {
        // 0x8003A33C: sb          $t5, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r13;
            goto L_8003A2F4;
    }
    // 0x8003A33C: sb          $t5, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r13;
L_8003A340:
    // 0x8003A340: bnel        $a1, $a3, L_8003A2DC
    if (ctx->r5 != ctx->r7) {
        // 0x8003A344: lw          $a0, 0x0($a1)
        ctx->r4 = MEM_W(ctx->r5, 0X0);
            goto L_8003A2DC;
    }
    goto skip_2;
    // 0x8003A344: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    skip_2:
L_8003A348:
    // 0x8003A348: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x8003A34C: bne         $t1, $t3, L_8003A2C4
    if (ctx->r9 != ctx->r11) {
        // 0x8003A350: nop
    
            goto L_8003A2C4;
    }
    // 0x8003A350: nop

L_8003A354:
    // 0x8003A354: beq         $s1, $zero, L_8003A42C
    if (ctx->r17 == 0) {
        // 0x8003A358: addiu       $t0, $zero, 0x8
        ctx->r8 = ADD32(0, 0X8);
            goto L_8003A42C;
    }
    // 0x8003A358: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x8003A35C: sll         $a1, $s1, 16
    ctx->r5 = S32(ctx->r17 << 16);
    // 0x8003A360: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8003A364: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x8003A368: addiu       $a0, $sp, 0x2FC
    ctx->r4 = ADD32(ctx->r29, 0X2FC);
    // 0x8003A36C: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x8003A370: addiu       $a3, $sp, 0x36
    ctx->r7 = ADD32(ctx->r29, 0X36);
    // 0x8003A374: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003A378: jal         0x8003A080
    // 0x8003A37C: sh          $t2, 0x166($sp)
    MEM_H(0X166, ctx->r29) = ctx->r10;
    func_8003A080(rdram, ctx);
        goto after_1;
    // 0x8003A37C: sh          $t2, 0x166($sp)
    MEM_H(0X166, ctx->r29) = ctx->r10;
    after_1:
    // 0x8003A380: lh          $t7, 0x36($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X36);
    // 0x8003A384: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x8003A388: lh          $t2, 0x166($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X166);
    // 0x8003A38C: blez        $t7, L_8003A42C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8003A390: addiu       $t1, $sp, 0x38
        ctx->r9 = ADD32(ctx->r29, 0X38);
            goto L_8003A42C;
    }
    // 0x8003A390: addiu       $t1, $sp, 0x38
    ctx->r9 = ADD32(ctx->r29, 0X38);
    // 0x8003A394: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x8003A398: addu        $t3, $t6, $t1
    ctx->r11 = ADD32(ctx->r14, ctx->r9);
L_8003A39C:
    // 0x8003A39C: blez        $s1, L_8003A420
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8003A3A0: lh          $a2, 0x0($t1)
        ctx->r6 = MEM_H(ctx->r9, 0X0);
            goto L_8003A420;
    }
    // 0x8003A3A0: lh          $a2, 0x0($t1)
    ctx->r6 = MEM_H(ctx->r9, 0X0);
    // 0x8003A3A4: addiu       $a1, $sp, 0x2FC
    ctx->r5 = ADD32(ctx->r29, 0X2FC);
    // 0x8003A3A8: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x8003A3AC: addu        $a3, $t8, $a1
    ctx->r7 = ADD32(ctx->r24, ctx->r5);
    // 0x8003A3B0: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
L_8003A3B4:
    // 0x8003A3B4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8003A3B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003A3BC: lh          $t7, 0x8C($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X8C);
    // 0x8003A3C0: addiu       $v1, $sp, 0x658
    ctx->r3 = ADD32(ctx->r29, 0X658);
    // 0x8003A3C4: bne         $a2, $t7, L_8003A418
    if (ctx->r6 != ctx->r15) {
        // 0x8003A3C8: nop
    
            goto L_8003A418;
    }
    // 0x8003A3C8: nop

L_8003A3CC:
    // 0x8003A3CC: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x8003A3D0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003A3D4: addu        $t9, $t6, $v0
    ctx->r25 = ADD32(ctx->r14, ctx->r2);
    // 0x8003A3D8: lbu         $t8, 0x10($t9)
    ctx->r24 = MEM_BU(ctx->r25, 0X10);
    // 0x8003A3DC: sb          $t8, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r24;
    // 0x8003A3E0: lw          $t5, 0x8($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X8);
    // 0x8003A3E4: addu        $t7, $t5, $v0
    ctx->r15 = ADD32(ctx->r13, ctx->r2);
    // 0x8003A3E8: lbu         $t6, 0x11($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0X11);
    // 0x8003A3EC: sb          $t6, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r14;
    // 0x8003A3F0: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x8003A3F4: addu        $t8, $t9, $v0
    ctx->r24 = ADD32(ctx->r25, ctx->r2);
    // 0x8003A3F8: lbu         $t5, 0x12($t8)
    ctx->r13 = MEM_BU(ctx->r24, 0X12);
    // 0x8003A3FC: sb          $t5, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r13;
    // 0x8003A400: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8003A404: addu        $t6, $t7, $v0
    ctx->r14 = ADD32(ctx->r15, ctx->r2);
    // 0x8003A408: lbu         $t9, 0x13($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X13);
    // 0x8003A40C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003A410: bne         $v0, $t0, L_8003A3CC
    if (ctx->r2 != ctx->r8) {
        // 0x8003A414: sb          $t9, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r25;
            goto L_8003A3CC;
    }
    // 0x8003A414: sb          $t9, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r25;
L_8003A418:
    // 0x8003A418: bnel        $a1, $a3, L_8003A3B4
    if (ctx->r5 != ctx->r7) {
        // 0x8003A41C: lw          $a0, 0x0($a1)
        ctx->r4 = MEM_W(ctx->r5, 0X0);
            goto L_8003A3B4;
    }
    goto skip_3;
    // 0x8003A41C: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    skip_3:
L_8003A420:
    // 0x8003A420: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x8003A424: bne         $t1, $t3, L_8003A39C
    if (ctx->r9 != ctx->r11) {
        // 0x8003A428: nop
    
            goto L_8003A39C;
    }
    // 0x8003A428: nop

L_8003A42C:
    // 0x8003A42C: beql        $t2, $zero, L_8003A4D8
    if (ctx->r10 == 0) {
        // 0x8003A430: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8003A4D8;
    }
    goto skip_4;
    // 0x8003A430: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x8003A434: blez        $t2, L_8003A4D4
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8003A438: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8003A4D4;
    }
    // 0x8003A438: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003A43C: addiu       $a1, $sp, 0x16C
    ctx->r5 = ADD32(ctx->r29, 0X16C);
    // 0x8003A440: sll         $t5, $t2, 2
    ctx->r13 = S32(ctx->r10 << 2);
    // 0x8003A444: addu        $a3, $t5, $a1
    ctx->r7 = ADD32(ctx->r13, ctx->r5);
    // 0x8003A448: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
L_8003A44C:
    // 0x8003A44C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003A450: addiu       $v1, $sp, 0x658
    ctx->r3 = ADD32(ctx->r29, 0X658);
L_8003A454:
    // 0x8003A454: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8003A458: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003A45C: addu        $t6, $t7, $v0
    ctx->r14 = ADD32(ctx->r15, ctx->r2);
    // 0x8003A460: lbu         $t9, 0x10($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X10);
    // 0x8003A464: sb          $t9, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r25;
    // 0x8003A468: lw          $t5, 0x8($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X8);
    // 0x8003A46C: addu        $t8, $t5, $v0
    ctx->r24 = ADD32(ctx->r13, ctx->r2);
    // 0x8003A470: lbu         $t7, 0x11($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X11);
    // 0x8003A474: sb          $t7, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r15;
    // 0x8003A478: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x8003A47C: addu        $t9, $t6, $v0
    ctx->r25 = ADD32(ctx->r14, ctx->r2);
    // 0x8003A480: lbu         $t5, 0x12($t9)
    ctx->r13 = MEM_BU(ctx->r25, 0X12);
    // 0x8003A484: sb          $t5, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r13;
    // 0x8003A488: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x8003A48C: addu        $t7, $t8, $v0
    ctx->r15 = ADD32(ctx->r24, ctx->r2);
    // 0x8003A490: lbu         $t6, 0x13($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0X13);
    // 0x8003A494: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003A498: bne         $v0, $t0, L_8003A454
    if (ctx->r2 != ctx->r8) {
        // 0x8003A49C: sb          $t6, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r14;
            goto L_8003A454;
    }
    // 0x8003A49C: sb          $t6, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r14;
    // 0x8003A4A0: lw          $v0, 0x80($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X80);
    // 0x8003A4A4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8003A4A8: srl         $t9, $v0, 16
    ctx->r25 = S32(U32(ctx->r2) >> 16);
    // 0x8003A4AC: andi        $t5, $t9, 0x3F
    ctx->r13 = ctx->r25 & 0X3F;
    // 0x8003A4B0: sll         $t8, $t5, 16
    ctx->r24 = S32(ctx->r13 << 16);
    // 0x8003A4B4: sra         $t7, $t8, 16
    ctx->r15 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8003A4B8: beq         $t7, $a2, L_8003A4CC
    if (ctx->r15 == ctx->r6) {
        // 0x8003A4BC: nop
    
            goto L_8003A4CC;
    }
    // 0x8003A4BC: nop

    // 0x8003A4C0: sll         $a2, $t7, 16
    ctx->r6 = S32(ctx->r15 << 16);
    // 0x8003A4C4: sra         $t6, $a2, 16
    ctx->r14 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8003A4C8: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
L_8003A4CC:
    // 0x8003A4CC: bnel        $a1, $a3, L_8003A44C
    if (ctx->r5 != ctx->r7) {
        // 0x8003A4D0: lw          $a0, 0x0($a1)
        ctx->r4 = MEM_W(ctx->r5, 0X0);
            goto L_8003A44C;
    }
    goto skip_5;
    // 0x8003A4D0: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    skip_5:
L_8003A4D4:
    // 0x8003A4D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8003A4D8:
    // 0x8003A4D8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8003A4DC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8003A4E0: jr          $ra
    // 0x8003A4E4: addiu       $sp, $sp, 0x678
    ctx->r29 = ADD32(ctx->r29, 0X678);
    TRACE_RETURN()
    return;
    // 0x8003A4E4: addiu       $sp, $sp, 0x678
    ctx->r29 = ADD32(ctx->r29, 0X678);
;}
RECOMP_FUNC void func_8003A4E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8003A4E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003A4EC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003A4F0: addiu       $v0, $v0, -0x6BDC
    ctx->r2 = ADD32(ctx->r2, -0X6BDC);
    // 0x8003A4F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003A4F8: lw          $t7, 0x40($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X40);
    // 0x8003A4FC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8003A500: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003A504: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8003A508: jal         0x80035C74
    // 0x8003A50C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    func_80035C74(rdram, ctx);
        goto after_0;
    // 0x8003A50C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    after_0:
    // 0x8003A510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003A514: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003A518: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8003A520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8003A520: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x8003A524: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8003A528: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8003A52C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8003A530: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003A534: sw          $a1, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r5;
    // 0x8003A538: lh          $v0, 0x90($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X90);
    // 0x8003A53C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8003A540: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003A544: beq         $v0, $zero, L_8003A56C
    if (ctx->r2 == 0) {
        // 0x8003A548: lh          $t6, 0xE6($sp)
        ctx->r14 = MEM_H(ctx->r29, 0XE6);
            goto L_8003A56C;
    }
    // 0x8003A548: lh          $t6, 0xE6($sp)
    ctx->r14 = MEM_H(ctx->r29, 0XE6);
    // 0x8003A54C: beq         $v0, $at, L_8003A648
    if (ctx->r2 == ctx->r1) {
        // 0x8003A550: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8003A648;
    }
    // 0x8003A550: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003A554: beq         $v0, $at, L_8003A7A0
    if (ctx->r2 == ctx->r1) {
        // 0x8003A558: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8003A7A0;
    }
    // 0x8003A558: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003A55C: beql        $v0, $at, L_8003A914
    if (ctx->r2 == ctx->r1) {
        // 0x8003A560: lh          $v1, 0x94($s1)
        ctx->r3 = MEM_H(ctx->r17, 0X94);
            goto L_8003A914;
    }
    goto skip_0;
    // 0x8003A560: lh          $v1, 0x94($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X94);
    skip_0:
    // 0x8003A564: b           L_8003A914
    // 0x8003A568: lh          $v1, 0x94($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X94);
        goto L_8003A914;
    // 0x8003A568: lh          $v1, 0x94($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X94);
L_8003A56C:
    // 0x8003A56C: beql        $t6, $zero, L_8003A644
    if (ctx->r14 == 0) {
        // 0x8003A570: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_8003A644;
    }
    goto skip_1;
    // 0x8003A570: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    skip_1:
    // 0x8003A574: lw          $t7, 0xC($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XC);
    // 0x8003A578: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8003A57C: jal         0x8000F764
    // 0x8003A580: lw          $s0, 0x0($t7)
    ctx->r16 = MEM_W(ctx->r15, 0X0);
    func_8000F764(rdram, ctx);
        goto after_0;
    // 0x8003A580: lw          $s0, 0x0($t7)
    ctx->r16 = MEM_W(ctx->r15, 0X0);
    after_0:
    // 0x8003A584: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
    // 0x8003A588: sw          $v0, 0xBC($s1)
    MEM_W(0XBC, ctx->r17) = ctx->r2;
    // 0x8003A58C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8003A590: lh          $v1, 0xC($t8)
    ctx->r3 = MEM_H(ctx->r24, 0XC);
    // 0x8003A594: blezl       $v1, L_8003A644
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8003A598: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_8003A644;
    }
    goto skip_2;
    // 0x8003A598: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    skip_2:
    // 0x8003A59C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_8003A5A0:
    // 0x8003A5A0: addiu       $at, $zero, 0x79
    ctx->r1 = ADD32(0, 0X79);
    // 0x8003A5A4: lw          $t9, 0x10($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X10);
    // 0x8003A5A8: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x8003A5AC: bnel        $t0, $at, L_8003A634
    if (ctx->r8 != ctx->r1) {
        // 0x8003A5B0: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8003A634;
    }
    goto skip_3;
    // 0x8003A5B0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_3:
    // 0x8003A5B4: lw          $t2, 0xC($s1)
    ctx->r10 = MEM_W(ctx->r17, 0XC);
    // 0x8003A5B8: lw          $t1, 0xBC($s1)
    ctx->r9 = MEM_W(ctx->r17, 0XBC);
    // 0x8003A5BC: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x8003A5C0: lw          $t4, 0xD4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XD4);
    // 0x8003A5C4: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x8003A5C8: sw          $t1, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r9;
    // 0x8003A5CC: lw          $t6, 0xC($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XC);
    // 0x8003A5D0: lw          $t0, 0xBC($s1)
    ctx->r8 = MEM_W(ctx->r17, 0XBC);
    // 0x8003A5D4: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x8003A5D8: lw          $t8, 0xD4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XD4);
    // 0x8003A5DC: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8003A5E0: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8003A5E4: lw          $t2, 0xC($s1)
    ctx->r10 = MEM_W(ctx->r17, 0XC);
    // 0x8003A5E8: lw          $t1, 0xBC($s1)
    ctx->r9 = MEM_W(ctx->r17, 0XBC);
    // 0x8003A5EC: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x8003A5F0: lw          $t4, 0xD4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XD4);
    // 0x8003A5F4: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x8003A5F8: lw          $t6, 0xC($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XC);
    // 0x8003A5FC: lw          $t5, 0xBC($s1)
    ctx->r13 = MEM_W(ctx->r17, 0XBC);
    // 0x8003A600: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x8003A604: lw          $t8, 0xD4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XD4);
    // 0x8003A608: sw          $t5, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r13;
    // 0x8003A60C: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8003A610: lw          $a0, 0xBC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XBC);
    // 0x8003A614: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x8003A618: jal         0x80002340
    // 0x8003A61C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80002340(rdram, ctx);
        goto after_1;
    // 0x8003A61C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_1:
    // 0x8003A620: lw          $t9, 0xBC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XBC);
    // 0x8003A624: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
    // 0x8003A628: lw          $t0, 0x8($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X8);
    // 0x8003A62C: lh          $v1, 0xC($t0)
    ctx->r3 = MEM_H(ctx->r8, 0XC);
    // 0x8003A630: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8003A634:
    // 0x8003A634: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003A638: bnel        $at, $zero, L_8003A5A0
    if (ctx->r1 != 0) {
        // 0x8003A63C: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_8003A5A0;
    }
    goto skip_4;
    // 0x8003A63C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_4:
    // 0x8003A640: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8003A644:
    // 0x8003A644: sh          $t2, 0x90($s1)
    MEM_H(0X90, ctx->r17) = ctx->r10;
L_8003A648:
    // 0x8003A648: lh          $t3, 0xE6($sp)
    ctx->r11 = MEM_H(ctx->r29, 0XE6);
    // 0x8003A64C: beql        $t3, $zero, L_8003A6C8
    if (ctx->r11 == 0) {
        // 0x8003A650: lh          $t1, 0x36($s1)
        ctx->r9 = MEM_H(ctx->r17, 0X36);
            goto L_8003A6C8;
    }
    goto skip_5;
    // 0x8003A650: lh          $t1, 0x36($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X36);
    skip_5:
    // 0x8003A654: lw          $v0, 0xBC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XBC);
    // 0x8003A658: beql        $v0, $zero, L_8003A6C8
    if (ctx->r2 == 0) {
        // 0x8003A65C: lh          $t1, 0x36($s1)
        ctx->r9 = MEM_H(ctx->r17, 0X36);
            goto L_8003A6C8;
    }
    goto skip_6;
    // 0x8003A65C: lh          $t1, 0x36($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X36);
    skip_6:
    // 0x8003A660: lwc1        $f4, 0xB8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XB8);
    // 0x8003A664: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003A668: ldc1        $f8, 0x7430($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X7430);
    // 0x8003A66C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8003A670: lw          $t4, 0xC($s1)
    ctx->r12 = MEM_W(ctx->r17, 0XC);
    // 0x8003A674: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x8003A678: addiu       $a0, $v0, 0x10
    ctx->r4 = ADD32(ctx->r2, 0X10);
    // 0x8003A67C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8003A680: swc1        $f16, 0xB8($s1)
    MEM_W(0XB8, ctx->r17) = ctx->f16.u32l;
    // 0x8003A684: lw          $a1, 0xC($t4)
    ctx->r5 = MEM_W(ctx->r12, 0XC);
    // 0x8003A688: jal         0x80002340
    // 0x8003A68C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    func_80002340(rdram, ctx);
        goto after_2;
    // 0x8003A68C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_2:
    // 0x8003A690: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003A694: addiu       $s0, $sp, 0x9C
    ctx->r16 = ADD32(ctx->r29, 0X9C);
    // 0x8003A698: lw          $a1, 0xB8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XB8);
    // 0x8003A69C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003A6A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003A6A4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8003A6A8: jal         0x80049840
    // 0x8003A6AC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80049840(rdram, ctx);
        goto after_3;
    // 0x8003A6AC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x8003A6B0: lw          $a0, 0xBC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XBC);
    // 0x8003A6B4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8003A6B8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8003A6BC: jal         0x80000BD8
    // 0x8003A6C0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_80000BD8(rdram, ctx);
        goto after_4;
    // 0x8003A6C0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_4:
    // 0x8003A6C4: lh          $t1, 0x36($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X36);
L_8003A6C8:
    // 0x8003A6C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8003A6CC: bgtzl       $t1, L_8003A914
    if (SIGNED(ctx->r9) > 0) {
        // 0x8003A6D0: lh          $v1, 0x94($s1)
        ctx->r3 = MEM_H(ctx->r17, 0X94);
            goto L_8003A914;
    }
    goto skip_7;
    // 0x8003A6D0: lh          $v1, 0x94($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X94);
    skip_7:
    // 0x8003A6D4: jal         0x8003A4E8
    // 0x8003A6D8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    func_8003A4E8(rdram, ctx);
        goto after_5;
    // 0x8003A6D8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    after_5:
    // 0x8003A6DC: lh          $t6, 0x34($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X34);
    // 0x8003A6E0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8003A6E4: blezl       $t6, L_8003A750
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8003A6E8: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8003A750;
    }
    goto skip_8;
    // 0x8003A6E8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_8:
    // 0x8003A6EC: lw          $t7, 0x30($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X30);
L_8003A6F0:
    // 0x8003A6F0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8003A6F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003A6F8: addu        $a0, $t7, $s0
    ctx->r4 = ADD32(ctx->r15, ctx->r16);
    // 0x8003A6FC: jal         0x80042F80
    // 0x8003A700: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_80042F80(rdram, ctx);
        goto after_6;
    // 0x8003A700: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_6:
    // 0x8003A704: lw          $t5, 0x30($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X30);
    // 0x8003A708: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x8003A70C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003A710: addu        $a0, $t5, $s0
    ctx->r4 = ADD32(ctx->r13, ctx->r16);
    // 0x8003A714: jal         0x80042F80
    // 0x8003A718: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_80042F80(rdram, ctx);
        goto after_7;
    // 0x8003A718: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_7:
    // 0x8003A71C: lw          $t8, 0x30($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X30);
    // 0x8003A720: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8003A724: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003A728: addu        $a0, $t8, $s0
    ctx->r4 = ADD32(ctx->r24, ctx->r16);
    // 0x8003A72C: jal         0x80043714
    // 0x8003A730: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_80043714(rdram, ctx);
        goto after_8;
    // 0x8003A730: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_8:
    // 0x8003A734: lh          $t9, 0x34($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X34);
    // 0x8003A738: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8003A73C: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x8003A740: slt         $at, $s2, $t9
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8003A744: bnel        $at, $zero, L_8003A6F0
    if (ctx->r1 != 0) {
        // 0x8003A748: lw          $t7, 0x30($s1)
        ctx->r15 = MEM_W(ctx->r17, 0X30);
            goto L_8003A6F0;
    }
    goto skip_9;
    // 0x8003A748: lw          $t7, 0x30($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X30);
    skip_9:
    // 0x8003A74C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_8003A750:
    // 0x8003A750: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003A754: swc1        $f0, 0xB8($s1)
    MEM_W(0XB8, ctx->r17) = ctx->f0.u32l;
    // 0x8003A758: swc1        $f0, 0xA4($s1)
    MEM_W(0XA4, ctx->r17) = ctx->f0.u32l;
    // 0x8003A75C: lwc1        $f18, 0x7438($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7438);
    // 0x8003A760: jal         0x8000E35C
    // 0x8003A764: swc1        $f18, 0xA8($s1)
    MEM_W(0XA8, ctx->r17) = ctx->f18.u32l;
    func_8000E35C(rdram, ctx);
        goto after_9;
    // 0x8003A764: swc1        $f18, 0xA8($s1)
    MEM_W(0XA8, ctx->r17) = ctx->f18.u32l;
    after_9:
    // 0x8003A768: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x8003A76C: beq         $t0, $zero, L_8003A780
    if (ctx->r8 == 0) {
        // 0x8003A770: addiu       $t2, $zero, 0x4
        ctx->r10 = ADD32(0, 0X4);
            goto L_8003A780;
    }
    // 0x8003A770: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8003A774: lwc1        $f4, 0xA8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XA8);
    // 0x8003A778: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8003A77C: swc1        $f6, 0xA8($s1)
    MEM_W(0XA8, ctx->r17) = ctx->f6.u32l;
L_8003A780:
    // 0x8003A780: sh          $zero, 0x96($s1)
    MEM_H(0X96, ctx->r17) = 0;
    // 0x8003A784: sh          $t2, 0x9C($s1)
    MEM_H(0X9C, ctx->r17) = ctx->r10;
    // 0x8003A788: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x8003A78C: jal         0x800443A8
    // 0x8003A790: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    func_800443A8(rdram, ctx);
        goto after_10;
    // 0x8003A790: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    after_10:
    // 0x8003A794: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8003A798: b           L_8003A910
    // 0x8003A79C: sh          $t3, 0x90($s1)
    MEM_H(0X90, ctx->r17) = ctx->r11;
        goto L_8003A910;
    // 0x8003A79C: sh          $t3, 0x90($s1)
    MEM_H(0X90, ctx->r17) = ctx->r11;
L_8003A7A0:
    // 0x8003A7A0: lwc1        $f0, 0xA4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XA4);
    // 0x8003A7A4: lwc1        $f8, 0xB8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XB8);
    // 0x8003A7A8: lwc1        $f16, 0xA8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XA8);
    // 0x8003A7AC: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8003A7B0: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x8003A7B4: swc1        $f10, 0xB8($s1)
    MEM_W(0XB8, ctx->r17) = ctx->f10.u32l;
    // 0x8003A7B8: lwc1        $f12, 0xB8($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0XB8);
    // 0x8003A7BC: jal         0x8000E16C
    // 0x8003A7C0: swc1        $f18, 0xA4($s1)
    MEM_W(0XA4, ctx->r17) = ctx->f18.u32l;
    func_8000E16C(rdram, ctx);
        goto after_11;
    // 0x8003A7C0: swc1        $f18, 0xA4($s1)
    MEM_W(0XA4, ctx->r17) = ctx->f18.u32l;
    after_11:
    // 0x8003A7C4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003A7C8: lwc1        $f4, 0x743C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X743C);
    // 0x8003A7CC: addiu       $s0, $sp, 0x9C
    ctx->r16 = ADD32(ctx->r29, 0X9C);
    // 0x8003A7D0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003A7D4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8003A7D8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003A7DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003A7E0: bc1fl       L_8003A81C
    if (!c1cs) {
        // 0x8003A7E4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8003A81C;
    }
    goto skip_10;
    // 0x8003A7E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_10:
    // 0x8003A7E8: lwc1        $f6, 0xA4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XA4);
    // 0x8003A7EC: lwc1        $f8, 0x7440($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7440);
    // 0x8003A7F0: lh          $t4, 0x9C($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X9C);
    // 0x8003A7F4: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8003A7F8: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8003A7FC: addiu       $t1, $t4, -0x1
    ctx->r9 = ADD32(ctx->r12, -0X1);
    // 0x8003A800: sh          $t1, 0x9C($s1)
    MEM_H(0X9C, ctx->r17) = ctx->r9;
    // 0x8003A804: lh          $t6, 0x9C($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X9C);
    // 0x8003A808: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x8003A80C: bne         $t6, $zero, L_8003A818
    if (ctx->r14 != 0) {
        // 0x8003A810: swc1        $f16, 0xA4($s1)
        MEM_W(0XA4, ctx->r17) = ctx->f16.u32l;
            goto L_8003A818;
    }
    // 0x8003A810: swc1        $f16, 0xA4($s1)
    MEM_W(0XA4, ctx->r17) = ctx->f16.u32l;
    // 0x8003A814: sh          $t7, 0x90($s1)
    MEM_H(0X90, ctx->r17) = ctx->r15;
L_8003A818:
    // 0x8003A818: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8003A81C:
    // 0x8003A81C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003A820: lw          $a1, 0xB8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XB8);
    // 0x8003A824: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003A828: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8003A82C: jal         0x80049840
    // 0x8003A830: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    func_80049840(rdram, ctx);
        goto after_12;
    // 0x8003A830: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_12:
    // 0x8003A834: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003A838: addiu       $s2, $sp, 0x5C
    ctx->r18 = ADD32(ctx->r29, 0X5C);
    // 0x8003A83C: lw          $a1, 0x20($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X20);
    // 0x8003A840: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003A844: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8003A848: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8003A84C: jal         0x80049840
    // 0x8003A850: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80049840(rdram, ctx);
        goto after_13;
    // 0x8003A850: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_13:
    // 0x8003A854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003A858: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8003A85C: jal         0x80000BD8
    // 0x8003A860: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_80000BD8(rdram, ctx);
        goto after_14;
    // 0x8003A860: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_14:
    // 0x8003A864: lwc1        $f0, 0x2C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x8003A868: lw          $t5, 0xC($s1)
    ctx->r13 = MEM_W(ctx->r17, 0XC);
    // 0x8003A86C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003A870: lw          $a0, 0x8($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X8);
    // 0x8003A874: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003A878: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003A87C: jal         0x80001AB4
    // 0x8003A880: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80001AB4(rdram, ctx);
        goto after_15;
    // 0x8003A880: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_15:
    // 0x8003A884: lw          $t8, 0xC($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XC);
    // 0x8003A888: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8003A88C: lw          $a0, 0x8($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X8);
    // 0x8003A890: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8003A894: jal         0x80000BD8
    // 0x8003A898: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_80000BD8(rdram, ctx);
        goto after_16;
    // 0x8003A898: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_16:
    // 0x8003A89C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003A8A0: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x8003A8A4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
L_8003A8A8:
    // 0x8003A8A8: lw          $t9, 0xC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XC);
    // 0x8003A8AC: lwc1        $f18, 0x10($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8003A8B0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003A8B4: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x8003A8B8: addu        $t2, $t0, $v0
    ctx->r10 = ADD32(ctx->r8, ctx->r2);
    // 0x8003A8BC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003A8C0: bne         $v0, $a0, L_8003A8A8
    if (ctx->r2 != ctx->r4) {
        // 0x8003A8C4: swc1        $f18, 0x40($t2)
        MEM_W(0X40, ctx->r10) = ctx->f18.u32l;
            goto L_8003A8A8;
    }
    // 0x8003A8C4: swc1        $f18, 0x40($t2)
    MEM_W(0X40, ctx->r10) = ctx->f18.u32l;
    // 0x8003A8C8: lh          $t3, 0x96($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X96);
    // 0x8003A8CC: addiu       $t4, $zero, 0x1F
    ctx->r12 = ADD32(0, 0X1F);
    // 0x8003A8D0: addiu       $t1, $zero, 0xF
    ctx->r9 = ADD32(0, 0XF);
    // 0x8003A8D4: bne         $t3, $zero, L_8003A910
    if (ctx->r11 != 0) {
        // 0x8003A8D8: addiu       $t6, $zero, 0x1F
        ctx->r14 = ADD32(0, 0X1F);
            goto L_8003A910;
    }
    // 0x8003A8D8: addiu       $t6, $zero, 0x1F
    ctx->r14 = ADD32(0, 0X1F);
    // 0x8003A8DC: sh          $t4, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r12;
    // 0x8003A8E0: sh          $t1, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r9;
    // 0x8003A8E4: sh          $t6, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r14;
    // 0x8003A8E8: sh          $zero, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = 0;
    // 0x8003A8EC: sh          $zero, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = 0;
    // 0x8003A8F0: sh          $zero, 0x40($sp)
    MEM_H(0X40, ctx->r29) = 0;
    // 0x8003A8F4: addiu       $a0, $s1, 0x10
    ctx->r4 = ADD32(ctx->r17, 0X10);
    // 0x8003A8F8: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x8003A8FC: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x8003A900: jal         0x80043DE8
    // 0x8003A904: addiu       $a3, $zero, 0x1A
    ctx->r7 = ADD32(0, 0X1A);
    func_80043DE8(rdram, ctx);
        goto after_17;
    // 0x8003A904: addiu       $a3, $zero, 0x1A
    ctx->r7 = ADD32(0, 0X1A);
    after_17:
    // 0x8003A908: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x8003A90C: sh          $t7, 0x96($s1)
    MEM_H(0X96, ctx->r17) = ctx->r15;
L_8003A910:
    // 0x8003A910: lh          $v1, 0x94($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X94);
L_8003A914:
    // 0x8003A914: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8003A918: beq         $v1, $zero, L_8003A924
    if (ctx->r3 == 0) {
        // 0x8003A91C: addiu       $t5, $v1, -0x1
        ctx->r13 = ADD32(ctx->r3, -0X1);
            goto L_8003A924;
    }
    // 0x8003A91C: addiu       $t5, $v1, -0x1
    ctx->r13 = ADD32(ctx->r3, -0X1);
    // 0x8003A920: sh          $t5, 0x94($s1)
    MEM_H(0X94, ctx->r17) = ctx->r13;
L_8003A924:
    // 0x8003A924: lh          $v1, 0x96($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X96);
    // 0x8003A928: beq         $v1, $zero, L_8003A934
    if (ctx->r3 == 0) {
        // 0x8003A92C: addiu       $t8, $v1, -0x1
        ctx->r24 = ADD32(ctx->r3, -0X1);
            goto L_8003A934;
    }
    // 0x8003A92C: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x8003A930: sh          $t8, 0x96($v0)
    MEM_H(0X96, ctx->r2) = ctx->r24;
L_8003A934:
    // 0x8003A934: lh          $v1, 0x98($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X98);
    // 0x8003A938: beq         $v1, $zero, L_8003A944
    if (ctx->r3 == 0) {
        // 0x8003A93C: addiu       $t9, $v1, -0x1
        ctx->r25 = ADD32(ctx->r3, -0X1);
            goto L_8003A944;
    }
    // 0x8003A93C: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
    // 0x8003A940: sh          $t9, 0x98($v0)
    MEM_H(0X98, ctx->r2) = ctx->r25;
L_8003A944:
    // 0x8003A944: lh          $v1, 0x9A($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X9A);
    // 0x8003A948: beq         $v1, $zero, L_8003A954
    if (ctx->r3 == 0) {
        // 0x8003A94C: addiu       $t0, $v1, -0x1
        ctx->r8 = ADD32(ctx->r3, -0X1);
            goto L_8003A954;
    }
    // 0x8003A94C: addiu       $t0, $v1, -0x1
    ctx->r8 = ADD32(ctx->r3, -0X1);
    // 0x8003A950: sh          $t0, 0x9A($v0)
    MEM_H(0X9A, ctx->r2) = ctx->r8;
L_8003A954:
    // 0x8003A954: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8003A958: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003A95C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8003A960: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8003A964: jr          $ra
    // 0x8003A968: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    TRACE_RETURN()
    return;
    // 0x8003A968: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
;}
RECOMP_FUNC void func_8003A96C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8003A96C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8003A970: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003A974: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003A978: lhu         $t6, 0x90($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X90);
    // 0x8003A97C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003A980: sltiu       $at, $t6, 0x8
    ctx->r1 = ctx->r14 < 0X8 ? 1 : 0;
    // 0x8003A984: beq         $at, $zero, L_8003AD38
    if (ctx->r1 == 0) {
        // 0x8003A988: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8003AD38;
    }
    // 0x8003A988: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8003A98C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003A990: addu        $at, $at, $t6
    gpr jr_addend_8003A998 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8003A994: lw          $t6, 0x7444($at)
    ctx->r14 = ADD32(ctx->r1, 0X7444);
    // 0x8003A998: jr          $t6
    // 0x8003A99C: nop

    switch (jr_addend_8003A998 >> 2) {
        case 0: goto L_8003A9A0; break;
        case 1: goto L_8003AA04; break;
        case 2: goto L_8003AAF4; break;
        case 3: goto L_8003AD38; break;
        case 4: goto L_8003AB94; break;
        case 5: goto L_8003ABA8; break;
        case 6: goto L_8003AC58; break;
        case 7: goto L_8003AC8C; break;
        default: switch_error(__func__, 0x8003A998, 0x80077444);
    }
    // 0x8003A99C: nop

L_8003A9A0:
    // 0x8003A9A0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8003A9A4: lh          $t7, -0x662C($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X662C);
    // 0x8003A9A8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8003A9AC: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x8003A9B0: bnel        $t7, $at, L_8003AA00
    if (ctx->r15 != ctx->r1) {
        // 0x8003A9B4: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_8003AA00;
    }
    goto skip_0;
    // 0x8003A9B4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    skip_0:
    // 0x8003A9B8: jal         0x80049CFC
    // 0x8003A9BC: addiu       $a0, $a0, 0x7410
    ctx->r4 = ADD32(ctx->r4, 0X7410);
    func_80049CFC(rdram, ctx);
        goto after_0;
    // 0x8003A9BC: addiu       $a0, $a0, 0x7410
    ctx->r4 = ADD32(ctx->r4, 0X7410);
    after_0:
    // 0x8003A9C0: lh          $t8, 0x8C($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X8C);
    // 0x8003A9C4: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8003A9C8: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x8003A9CC: bne         $v0, $t8, L_8003A9DC
    if (ctx->r2 != ctx->r24) {
        // 0x8003A9D0: nop
    
            goto L_8003A9DC;
    }
    // 0x8003A9D0: nop

    // 0x8003A9D4: b           L_8003AB94
    // 0x8003A9D8: sh          $t9, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r25;
        goto L_8003AB94;
    // 0x8003A9D8: sh          $t9, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r25;
L_8003A9DC:
    // 0x8003A9DC: jal         0x80049CFC
    // 0x8003A9E0: addiu       $a0, $a0, 0x7418
    ctx->r4 = ADD32(ctx->r4, 0X7418);
    func_80049CFC(rdram, ctx);
        goto after_1;
    // 0x8003A9E0: addiu       $a0, $a0, 0x7418
    ctx->r4 = ADD32(ctx->r4, 0X7418);
    after_1:
    // 0x8003A9E4: lh          $t0, 0x8C($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X8C);
    // 0x8003A9E8: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x8003A9EC: bnel        $v0, $t0, L_8003AA00
    if (ctx->r2 != ctx->r8) {
        // 0x8003A9F0: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_8003AA00;
    }
    goto skip_1;
    // 0x8003A9F0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    skip_1:
    // 0x8003A9F4: b           L_8003AC58
    // 0x8003A9F8: sh          $t1, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r9;
        goto L_8003AC58;
    // 0x8003A9F8: sh          $t1, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r9;
    // 0x8003A9FC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8003AA00:
    // 0x8003AA00: sh          $t2, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r10;
L_8003AA04:
    // 0x8003AA04: lh          $t3, 0x36($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X36);
    // 0x8003AA08: bgtzl       $t3, L_8003AD3C
    if (SIGNED(ctx->r11) > 0) {
        // 0x8003AA0C: lh          $v1, 0x94($s0)
        ctx->r3 = MEM_H(ctx->r16, 0X94);
            goto L_8003AD3C;
    }
    goto skip_2;
    // 0x8003AA0C: lh          $v1, 0x94($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X94);
    skip_2:
    // 0x8003AA10: jal         0x8003A4E8
    // 0x8003AA14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003A4E8(rdram, ctx);
        goto after_2;
    // 0x8003AA14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8003AA18: lw          $t4, 0xC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XC);
    // 0x8003AA1C: addiu       $v1, $sp, 0x44
    ctx->r3 = ADD32(ctx->r29, 0X44);
    // 0x8003AA20: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8003AA24: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x8003AA28: lw          $a0, 0xE0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0XE0);
    // 0x8003AA2C: lbu         $t6, 0x10($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X10);
    // 0x8003AA30: ori         $t7, $t6, 0x4
    ctx->r15 = ctx->r14 | 0X4;
    // 0x8003AA34: sb          $t7, 0x10($a0)
    MEM_B(0X10, ctx->r4) = ctx->r15;
    // 0x8003AA38: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
L_8003AA3C:
    // 0x8003AA3C: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8003AA40: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003AA44: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003AA48: bne         $v1, $a0, L_8003AA3C
    if (ctx->r3 != ctx->r4) {
        // 0x8003AA4C: swc1        $f4, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
            goto L_8003AA3C;
    }
    // 0x8003AA4C: swc1        $f4, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
    // 0x8003AA50: lw          $t8, 0x30($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X30);
    // 0x8003AA54: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8003AA58: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8003AA5C: lh          $t9, 0x4($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X4);
    // 0x8003AA60: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8003AA64: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003AA68: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8003AA6C: nop

    // 0x8003AA70: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8003AA74: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8003AA78: jal         0x80042F80
    // 0x8003AA7C: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    func_80042F80(rdram, ctx);
        goto after_3;
    // 0x8003AA7C: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x8003AA80: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8003AA84: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x8003AA88: jal         0x80042F80
    // 0x8003AA8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80042F80(rdram, ctx);
        goto after_4;
    // 0x8003AA8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x8003AA90: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8003AA94: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8003AA98: jal         0x80043714
    // 0x8003AA9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80043714(rdram, ctx);
        goto after_5;
    // 0x8003AA9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8003AAA0: lh          $t1, 0x92($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X92);
    // 0x8003AAA4: addiu       $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
    // 0x8003AAA8: sh          $t0, 0x94($s0)
    MEM_H(0X94, ctx->r16) = ctx->r8;
    // 0x8003AAAC: andi        $t2, $t1, 0x4
    ctx->r10 = ctx->r9 & 0X4;
    // 0x8003AAB0: beq         $t2, $zero, L_8003AACC
    if (ctx->r10 == 0) {
        // 0x8003AAB4: nop
    
            goto L_8003AACC;
    }
    // 0x8003AAB4: nop

    // 0x8003AAB8: lw          $v0, 0xB8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB8);
    // 0x8003AABC: lh          $t3, 0xA2($v0)
    ctx->r11 = MEM_H(ctx->r2, 0XA2);
    // 0x8003AAC0: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8003AAC4: b           L_8003AAE8
    // 0x8003AAC8: sh          $t4, 0xA2($v0)
    MEM_H(0XA2, ctx->r2) = ctx->r12;
        goto L_8003AAE8;
    // 0x8003AAC8: sh          $t4, 0xA2($v0)
    MEM_H(0XA2, ctx->r2) = ctx->r12;
L_8003AACC:
    // 0x8003AACC: jal         0x8000E35C
    // 0x8003AAD0: nop

    func_8000E35C(rdram, ctx);
        goto after_6;
    // 0x8003AAD0: nop

    after_6:
    // 0x8003AAD4: andi        $t5, $v0, 0x3
    ctx->r13 = ctx->r2 & 0X3;
    // 0x8003AAD8: beq         $t5, $zero, L_8003AAE8
    if (ctx->r13 == 0) {
        // 0x8003AADC: addiu       $a0, $s0, 0x10
        ctx->r4 = ADD32(ctx->r16, 0X10);
            goto L_8003AAE8;
    }
    // 0x8003AADC: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    // 0x8003AAE0: jal         0x80024DC4
    // 0x8003AAE4: addiu       $a1, $s0, 0x1C
    ctx->r5 = ADD32(ctx->r16, 0X1C);
    func_80024DC4(rdram, ctx);
        goto after_7;
    // 0x8003AAE4: addiu       $a1, $s0, 0x1C
    ctx->r5 = ADD32(ctx->r16, 0X1C);
    after_7:
L_8003AAE8:
    // 0x8003AAE8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8003AAEC: b           L_8003AD38
    // 0x8003AAF0: sh          $t6, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r14;
        goto L_8003AD38;
    // 0x8003AAF0: sh          $t6, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r14;
L_8003AAF4:
    // 0x8003AAF4: lh          $t7, 0x94($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X94);
    // 0x8003AAF8: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8003AAFC: beq         $t7, $zero, L_8003AB8C
    if (ctx->r15 == 0) {
        // 0x8003AB00: nop
    
            goto L_8003AB8C;
    }
    // 0x8003AB00: nop

    // 0x8003AB04: lh          $t8, 0x96($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X96);
    // 0x8003AB08: addiu       $v1, $sp, 0x44
    ctx->r3 = ADD32(ctx->r29, 0X44);
    // 0x8003AB0C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8003AB10: bne         $t8, $zero, L_8003AD38
    if (ctx->r24 != 0) {
        // 0x8003AB14: addiu       $a0, $sp, 0x50
        ctx->r4 = ADD32(ctx->r29, 0X50);
            goto L_8003AD38;
    }
    // 0x8003AB14: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
L_8003AB18:
    // 0x8003AB18: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8003AB1C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003AB20: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003AB24: bne         $v1, $a0, L_8003AB18
    if (ctx->r3 != ctx->r4) {
        // 0x8003AB28: swc1        $f18, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
            goto L_8003AB18;
    }
    // 0x8003AB28: swc1        $f18, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
    // 0x8003AB2C: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x8003AB30: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8003AB34: addiu       $t1, $zero, 0x1F
    ctx->r9 = ADD32(0, 0X1F);
    // 0x8003AB38: lh          $t0, 0x4($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X4);
    // 0x8003AB3C: addiu       $t2, $zero, 0xF
    ctx->r10 = ADD32(0, 0XF);
    // 0x8003AB40: addiu       $t3, $zero, 0x1F
    ctx->r11 = ADD32(0, 0X1F);
    // 0x8003AB44: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8003AB48: sh          $t3, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r11;
    // 0x8003AB4C: sh          $t2, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r10;
    // 0x8003AB50: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8003AB54: sh          $t1, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r9;
    // 0x8003AB58: sh          $zero, 0x34($sp)
    MEM_H(0X34, ctx->r29) = 0;
    // 0x8003AB5C: sh          $zero, 0x32($sp)
    MEM_H(0X32, ctx->r29) = 0;
    // 0x8003AB60: sh          $zero, 0x30($sp)
    MEM_H(0X30, ctx->r29) = 0;
    // 0x8003AB64: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    // 0x8003AB68: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003AB6C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8003AB70: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x8003AB74: addiu       $a3, $zero, 0x1A
    ctx->r7 = ADD32(0, 0X1A);
    // 0x8003AB78: jal         0x80043DE8
    // 0x8003AB7C: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    func_80043DE8(rdram, ctx);
        goto after_8;
    // 0x8003AB7C: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    after_8:
    // 0x8003AB80: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8003AB84: b           L_8003AD38
    // 0x8003AB88: sh          $t4, 0x96($s0)
    MEM_H(0X96, ctx->r16) = ctx->r12;
        goto L_8003AD38;
    // 0x8003AB88: sh          $t4, 0x96($s0)
    MEM_H(0X96, ctx->r16) = ctx->r12;
L_8003AB8C:
    // 0x8003AB8C: b           L_8003AD38
    // 0x8003AB90: sh          $t5, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r13;
        goto L_8003AD38;
    // 0x8003AB90: sh          $t5, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r13;
L_8003AB94:
    // 0x8003AB94: lh          $t6, 0x36($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X36);
    // 0x8003AB98: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8003AB9C: sh          $zero, 0xA2($s0)
    MEM_H(0XA2, ctx->r16) = 0;
    // 0x8003ABA0: sh          $t7, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r15;
    // 0x8003ABA4: sh          $t6, 0x9C($s0)
    MEM_H(0X9C, ctx->r16) = ctx->r14;
L_8003ABA8:
    // 0x8003ABA8: lh          $t8, 0x36($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X36);
    // 0x8003ABAC: lh          $t9, 0x9C($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X9C);
    // 0x8003ABB0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003ABB4: addiu       $v0, $v0, -0x6BDC
    ctx->r2 = ADD32(ctx->r2, -0X6BDC);
    // 0x8003ABB8: beql        $t8, $t9, L_8003AD3C
    if (ctx->r24 == ctx->r25) {
        // 0x8003ABBC: lh          $v1, 0x94($s0)
        ctx->r3 = MEM_H(ctx->r16, 0X94);
            goto L_8003AD3C;
    }
    goto skip_3;
    // 0x8003ABBC: lh          $v1, 0x94($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X94);
    skip_3:
    // 0x8003ABC0: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8003ABC4: addiu       $t2, $zero, 0x2710
    ctx->r10 = ADD32(0, 0X2710);
    // 0x8003ABC8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8003ABCC: addiu       $t1, $t0, 0x4D
    ctx->r9 = ADD32(ctx->r8, 0X4D);
    // 0x8003ABD0: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8003ABD4: lh          $t4, 0xA2($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XA2);
    // 0x8003ABD8: sh          $t2, 0x36($s0)
    MEM_H(0X36, ctx->r16) = ctx->r10;
    // 0x8003ABDC: lh          $t3, 0x36($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X36);
    // 0x8003ABE0: bne         $t4, $zero, L_8003AD38
    if (ctx->r12 != 0) {
        // 0x8003ABE4: sh          $t3, 0x9C($s0)
        MEM_H(0X9C, ctx->r16) = ctx->r11;
            goto L_8003AD38;
    }
    // 0x8003ABE4: sh          $t3, 0x9C($s0)
    MEM_H(0X9C, ctx->r16) = ctx->r11;
    // 0x8003ABE8: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003ABEC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003ABF0: lui         $at, 0x41A8
    ctx->r1 = S32(0X41A8 << 16);
    // 0x8003ABF4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003ABF8: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8003ABFC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003AC00: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x8003AC04: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x8003AC08: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003AC0C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8003AC10: nop

    // 0x8003AC14: bc1fl       L_8003AC28
    if (!c1cs) {
        // 0x8003AC18: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8003AC28;
    }
    goto skip_4;
    // 0x8003AC18: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    skip_4:
    // 0x8003AC1C: jal         0x80044480
    // 0x8003AC20: sh          $t5, 0xA2($s0)
    MEM_H(0XA2, ctx->r16) = ctx->r13;
    func_80044480(rdram, ctx);
        goto after_9;
    // 0x8003AC20: sh          $t5, 0xA2($s0)
    MEM_H(0XA2, ctx->r16) = ctx->r13;
    after_9:
    // 0x8003AC24: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8003AC28:
    // 0x8003AC28: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8003AC2C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
L_8003AC30:
    // 0x8003AC30: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x8003AC34: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8003AC38: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003AC3C: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x8003AC40: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8003AC44: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003AC48: bne         $v1, $a0, L_8003AC30
    if (ctx->r3 != ctx->r4) {
        // 0x8003AC4C: swc1        $f10, 0x40($t8)
        MEM_W(0X40, ctx->r24) = ctx->f10.u32l;
            goto L_8003AC30;
    }
    // 0x8003AC4C: swc1        $f10, 0x40($t8)
    MEM_W(0X40, ctx->r24) = ctx->f10.u32l;
    // 0x8003AC50: b           L_8003AD3C
    // 0x8003AC54: lh          $v1, 0x94($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X94);
        goto L_8003AD3C;
    // 0x8003AC54: lh          $v1, 0x94($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X94);
L_8003AC58:
    // 0x8003AC58: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x8003AC5C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003AC60: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003AC64: lh          $t9, 0x36($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X36);
    // 0x8003AC68: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x8003AC6C: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8003AC70: sh          $zero, 0xA2($s0)
    MEM_H(0XA2, ctx->r16) = 0;
    // 0x8003AC74: sh          $t2, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r10;
    // 0x8003AC78: sh          $t9, 0x9C($s0)
    MEM_H(0X9C, ctx->r16) = ctx->r25;
    // 0x8003AC7C: trunc.w.s   $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8003AC80: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x8003AC84: nop

    // 0x8003AC88: sh          $t1, 0x9E($s0)
    MEM_H(0X9E, ctx->r16) = ctx->r9;
L_8003AC8C:
    // 0x8003AC8C: lh          $t3, 0x36($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X36);
    // 0x8003AC90: lh          $t4, 0x9C($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X9C);
    // 0x8003AC94: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003AC98: addiu       $v0, $v0, -0x6BDC
    ctx->r2 = ADD32(ctx->r2, -0X6BDC);
    // 0x8003AC9C: beql        $t3, $t4, L_8003AD3C
    if (ctx->r11 == ctx->r12) {
        // 0x8003ACA0: lh          $v1, 0x94($s0)
        ctx->r3 = MEM_H(ctx->r16, 0X94);
            goto L_8003AD3C;
    }
    goto skip_5;
    // 0x8003ACA0: lh          $v1, 0x94($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X94);
    skip_5:
    // 0x8003ACA4: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8003ACA8: addiu       $t7, $zero, 0x2710
    ctx->r15 = ADD32(0, 0X2710);
    // 0x8003ACAC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8003ACB0: addiu       $t6, $t5, 0x3
    ctx->r14 = ADD32(ctx->r13, 0X3);
    // 0x8003ACB4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8003ACB8: lh          $t9, 0xA2($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XA2);
    // 0x8003ACBC: sh          $t7, 0x36($s0)
    MEM_H(0X36, ctx->r16) = ctx->r15;
    // 0x8003ACC0: lh          $t8, 0x36($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X36);
    // 0x8003ACC4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8003ACC8: bne         $t9, $zero, L_8003AD38
    if (ctx->r25 != 0) {
        // 0x8003ACCC: sh          $t8, 0x9C($s0)
        MEM_H(0X9C, ctx->r16) = ctx->r24;
            goto L_8003AD38;
    }
    // 0x8003ACCC: sh          $t8, 0x9C($s0)
    MEM_H(0X9C, ctx->r16) = ctx->r24;
    // 0x8003ACD0: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003ACD4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003ACD8: lh          $t0, 0x9E($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X9E);
    // 0x8003ACDC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003ACE0: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8003ACE4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8003ACE8: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x8003ACEC: swc1        $f16, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f16.u32l;
    // 0x8003ACF0: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003ACF4: trunc.w.s   $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8003ACF8: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x8003ACFC: nop

    // 0x8003AD00: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x8003AD04: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8003AD08: slt         $at, $t0, $t4
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8003AD0C: beq         $at, $zero, L_8003AD18
    if (ctx->r1 == 0) {
        // 0x8003AD10: nop
    
            goto L_8003AD18;
    }
    // 0x8003AD10: nop

    // 0x8003AD14: sh          $t5, 0xA2($s0)
    MEM_H(0XA2, ctx->r16) = ctx->r13;
L_8003AD18:
    // 0x8003AD18: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x8003AD1C: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8003AD20: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003AD24: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x8003AD28: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8003AD2C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003AD30: bne         $v1, $a0, L_8003AD18
    if (ctx->r3 != ctx->r4) {
        // 0x8003AD34: swc1        $f4, 0x40($t8)
        MEM_W(0X40, ctx->r24) = ctx->f4.u32l;
            goto L_8003AD18;
    }
    // 0x8003AD34: swc1        $f4, 0x40($t8)
    MEM_W(0X40, ctx->r24) = ctx->f4.u32l;
L_8003AD38:
    // 0x8003AD38: lh          $v1, 0x94($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X94);
L_8003AD3C:
    // 0x8003AD3C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8003AD40: beq         $v1, $zero, L_8003AD4C
    if (ctx->r3 == 0) {
        // 0x8003AD44: addiu       $t9, $v1, -0x1
        ctx->r25 = ADD32(ctx->r3, -0X1);
            goto L_8003AD4C;
    }
    // 0x8003AD44: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
    // 0x8003AD48: sh          $t9, 0x94($s0)
    MEM_H(0X94, ctx->r16) = ctx->r25;
L_8003AD4C:
    // 0x8003AD4C: lh          $v1, 0x96($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X96);
    // 0x8003AD50: beq         $v1, $zero, L_8003AD5C
    if (ctx->r3 == 0) {
        // 0x8003AD54: addiu       $t1, $v1, -0x1
        ctx->r9 = ADD32(ctx->r3, -0X1);
            goto L_8003AD5C;
    }
    // 0x8003AD54: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
    // 0x8003AD58: sh          $t1, 0x96($v0)
    MEM_H(0X96, ctx->r2) = ctx->r9;
L_8003AD5C:
    // 0x8003AD5C: lh          $v1, 0x98($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X98);
    // 0x8003AD60: beq         $v1, $zero, L_8003AD6C
    if (ctx->r3 == 0) {
        // 0x8003AD64: addiu       $t2, $v1, -0x1
        ctx->r10 = ADD32(ctx->r3, -0X1);
            goto L_8003AD6C;
    }
    // 0x8003AD64: addiu       $t2, $v1, -0x1
    ctx->r10 = ADD32(ctx->r3, -0X1);
    // 0x8003AD68: sh          $t2, 0x98($v0)
    MEM_H(0X98, ctx->r2) = ctx->r10;
L_8003AD6C:
    // 0x8003AD6C: lh          $v1, 0x9A($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X9A);
    // 0x8003AD70: beq         $v1, $zero, L_8003AD7C
    if (ctx->r3 == 0) {
        // 0x8003AD74: addiu       $t3, $v1, -0x1
        ctx->r11 = ADD32(ctx->r3, -0X1);
            goto L_8003AD7C;
    }
    // 0x8003AD74: addiu       $t3, $v1, -0x1
    ctx->r11 = ADD32(ctx->r3, -0X1);
    // 0x8003AD78: sh          $t3, 0x9A($v0)
    MEM_H(0X9A, ctx->r2) = ctx->r11;
L_8003AD7C:
    // 0x8003AD7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003AD80: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003AD84: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8003AD88: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8003AD90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8003AD90: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x8003AD94: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8003AD98: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8003AD9C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8003ADA0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003ADA4: lh          $v0, 0x90($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X90);
    // 0x8003ADA8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8003ADAC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003ADB0: beql        $v0, $zero, L_8003ADCC
    if (ctx->r2 == 0) {
        // 0x8003ADB4: lh          $t6, 0x36($s2)
        ctx->r14 = MEM_H(ctx->r18, 0X36);
            goto L_8003ADCC;
    }
    goto skip_0;
    // 0x8003ADB4: lh          $t6, 0x36($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X36);
    skip_0:
    // 0x8003ADB8: beql        $v0, $at, L_8003AF08
    if (ctx->r2 == ctx->r1) {
        // 0x8003ADBC: lh          $t9, 0x94($s2)
        ctx->r25 = MEM_H(ctx->r18, 0X94);
            goto L_8003AF08;
    }
    goto skip_1;
    // 0x8003ADBC: lh          $t9, 0x94($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X94);
    skip_1:
    // 0x8003ADC0: b           L_8003B12C
    // 0x8003ADC4: lh          $v1, 0x94($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X94);
        goto L_8003B12C;
    // 0x8003ADC4: lh          $v1, 0x94($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X94);
    // 0x8003ADC8: lh          $t6, 0x36($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X36);
L_8003ADCC:
    // 0x8003ADCC: bgtzl       $t6, L_8003B12C
    if (SIGNED(ctx->r14) > 0) {
        // 0x8003ADD0: lh          $v1, 0x94($s2)
        ctx->r3 = MEM_H(ctx->r18, 0X94);
            goto L_8003B12C;
    }
    goto skip_2;
    // 0x8003ADD0: lh          $v1, 0x94($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X94);
    skip_2:
    // 0x8003ADD4: jal         0x8003A4E8
    // 0x8003ADD8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8003A4E8(rdram, ctx);
        goto after_0;
    // 0x8003ADD8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x8003ADDC: addiu       $v0, $sp, 0xD4
    ctx->r2 = ADD32(ctx->r29, 0XD4);
    // 0x8003ADE0: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x8003ADE4: addiu       $v1, $sp, 0xE0
    ctx->r3 = ADD32(ctx->r29, 0XE0);
L_8003ADE8:
    // 0x8003ADE8: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003ADEC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003ADF0: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8003ADF4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8003ADF8: bne         $at, $zero, L_8003ADE8
    if (ctx->r1 != 0) {
        // 0x8003ADFC: swc1        $f4, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
            goto L_8003ADE8;
    }
    // 0x8003ADFC: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x8003AE00: lw          $t7, 0x30($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X30);
    // 0x8003AE04: lwc1        $f6, 0xD8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x8003AE08: addiu       $s0, $sp, 0xD4
    ctx->r16 = ADD32(ctx->r29, 0XD4);
    // 0x8003AE0C: lh          $t8, 0x4($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X4);
    // 0x8003AE10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003AE14: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8003AE18: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8003AE1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003AE20: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8003AE24: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8003AE28: jal         0x80042F80
    // 0x8003AE2C: swc1        $f16, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f16.u32l;
    func_80042F80(rdram, ctx);
        goto after_1;
    // 0x8003AE2C: swc1        $f16, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x8003AE30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003AE34: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8003AE38: jal         0x80043714
    // 0x8003AE3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80043714(rdram, ctx);
        goto after_2;
    // 0x8003AE3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8003AE40: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x8003AE44: sh          $t9, 0x94($s2)
    MEM_H(0X94, ctx->r18) = ctx->r25;
    // 0x8003AE48: addiu       $a0, $s2, 0x44
    ctx->r4 = ADD32(ctx->r18, 0X44);
    // 0x8003AE4C: jal         0x8000DD44
    // 0x8003AE50: addiu       $a1, $s2, 0x10
    ctx->r5 = ADD32(ctx->r18, 0X10);
    func_8000DD44(rdram, ctx);
        goto after_3;
    // 0x8003AE50: addiu       $a1, $s2, 0x10
    ctx->r5 = ADD32(ctx->r18, 0X10);
    after_3:
    // 0x8003AE54: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8003AE58: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
L_8003AE5C:
    // 0x8003AE5C: jal         0x8000E35C
    // 0x8003AE60: nop

    func_8000E35C(rdram, ctx);
        goto after_4;
    // 0x8003AE60: nop

    after_4:
    // 0x8003AE64: andi        $t0, $v0, 0x3
    ctx->r8 = ctx->r2 & 0X3;
    // 0x8003AE68: addiu       $t1, $t0, 0x4
    ctx->r9 = ADD32(ctx->r8, 0X4);
    // 0x8003AE6C: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x8003AE70: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8003AE74: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003AE78: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8003AE7C: lwc1        $f10, 0x44($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8003AE80: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8003AE84: nop

    // 0x8003AE88: mul.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8003AE8C: jal         0x8000E35C
    // 0x8003AE90: swc1        $f16, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f16.u32l;
    func_8000E35C(rdram, ctx);
        goto after_5;
    // 0x8003AE90: swc1        $f16, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f16.u32l;
    after_5:
    // 0x8003AE94: andi        $t2, $v0, 0x7
    ctx->r10 = ctx->r2 & 0X7;
    // 0x8003AE98: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8003AE9C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003AEA0: lwc1        $f8, 0x7464($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7464);
    // 0x8003AEA4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8003AEA8: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8003AEAC: jal         0x8000E35C
    // 0x8003AEB0: swc1        $f10, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f10.u32l;
    func_8000E35C(rdram, ctx);
        goto after_6;
    // 0x8003AEB0: swc1        $f10, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f10.u32l;
    after_6:
    // 0x8003AEB4: andi        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 & 0X1;
    // 0x8003AEB8: beq         $t3, $zero, L_8003AECC
    if (ctx->r11 == 0) {
        // 0x8003AEBC: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8003AECC;
    }
    // 0x8003AEBC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8003AEC0: lwc1        $f6, 0x5C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x8003AEC4: neg.s       $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = -ctx->f6.fl;
    // 0x8003AEC8: swc1        $f16, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f16.u32l;
L_8003AECC:
    // 0x8003AECC: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8003AED0: bne         $s1, $at, L_8003AE5C
    if (ctx->r17 != ctx->r1) {
        // 0x8003AED4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8003AE5C;
    }
    // 0x8003AED4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8003AED8: lh          $t4, 0x92($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X92);
    // 0x8003AEDC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8003AEE0: andi        $t5, $t4, 0x4
    ctx->r13 = ctx->r12 & 0X4;
    // 0x8003AEE4: beq         $t5, $zero, L_8003AEFC
    if (ctx->r13 == 0) {
        // 0x8003AEE8: nop
    
            goto L_8003AEFC;
    }
    // 0x8003AEE8: nop

    // 0x8003AEEC: lw          $v0, 0xB8($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XB8);
    // 0x8003AEF0: lh          $t6, 0xA2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XA2);
    // 0x8003AEF4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8003AEF8: sh          $t7, 0xA2($v0)
    MEM_H(0XA2, ctx->r2) = ctx->r15;
L_8003AEFC:
    // 0x8003AEFC: b           L_8003B128
    // 0x8003AF00: sh          $t8, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r24;
        goto L_8003B128;
    // 0x8003AF00: sh          $t8, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r24;
    // 0x8003AF04: lh          $t9, 0x94($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X94);
L_8003AF08:
    // 0x8003AF08: beql        $t9, $zero, L_8003AF98
    if (ctx->r25 == 0) {
        // 0x8003AF0C: addiu       $t7, $s2, 0x10
        ctx->r15 = ADD32(ctx->r18, 0X10);
            goto L_8003AF98;
    }
    goto skip_3;
    // 0x8003AF0C: addiu       $t7, $s2, 0x10
    ctx->r15 = ADD32(ctx->r18, 0X10);
    skip_3:
    // 0x8003AF10: lh          $t0, 0x96($s2)
    ctx->r8 = MEM_H(ctx->r18, 0X96);
    // 0x8003AF14: addiu       $v0, $sp, 0xD4
    ctx->r2 = ADD32(ctx->r29, 0XD4);
    // 0x8003AF18: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x8003AF1C: bne         $t0, $zero, L_8003AF94
    if (ctx->r8 != 0) {
        // 0x8003AF20: addiu       $v1, $sp, 0xE0
        ctx->r3 = ADD32(ctx->r29, 0XE0);
            goto L_8003AF94;
    }
    // 0x8003AF20: addiu       $v1, $sp, 0xE0
    ctx->r3 = ADD32(ctx->r29, 0XE0);
L_8003AF24:
    // 0x8003AF24: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003AF28: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003AF2C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8003AF30: bne         $v0, $v1, L_8003AF24
    if (ctx->r2 != ctx->r3) {
        // 0x8003AF34: swc1        $f18, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f18.u32l;
            goto L_8003AF24;
    }
    // 0x8003AF34: swc1        $f18, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f18.u32l;
    // 0x8003AF38: lw          $t1, 0x30($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X30);
    // 0x8003AF3C: lwc1        $f4, 0xD8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x8003AF40: addiu       $t3, $zero, 0x1F
    ctx->r11 = ADD32(0, 0X1F);
    // 0x8003AF44: lh          $t2, 0x4($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X4);
    // 0x8003AF48: addiu       $t4, $zero, 0xF
    ctx->r12 = ADD32(0, 0XF);
    // 0x8003AF4C: addiu       $t5, $zero, 0x1F
    ctx->r13 = ADD32(0, 0X1F);
    // 0x8003AF50: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8003AF54: sh          $t5, 0xCC($sp)
    MEM_H(0XCC, ctx->r29) = ctx->r13;
    // 0x8003AF58: sh          $t4, 0xCA($sp)
    MEM_H(0XCA, ctx->r29) = ctx->r12;
    // 0x8003AF5C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8003AF60: sh          $t3, 0xC8($sp)
    MEM_H(0XC8, ctx->r29) = ctx->r11;
    // 0x8003AF64: sh          $zero, 0xC4($sp)
    MEM_H(0XC4, ctx->r29) = 0;
    // 0x8003AF68: sh          $zero, 0xC2($sp)
    MEM_H(0XC2, ctx->r29) = 0;
    // 0x8003AF6C: sh          $zero, 0xC0($sp)
    MEM_H(0XC0, ctx->r29) = 0;
    // 0x8003AF70: addiu       $a0, $s2, 0x10
    ctx->r4 = ADD32(ctx->r18, 0X10);
    // 0x8003AF74: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8003AF78: addiu       $a1, $sp, 0xC8
    ctx->r5 = ADD32(ctx->r29, 0XC8);
    // 0x8003AF7C: addiu       $a2, $sp, 0xC0
    ctx->r6 = ADD32(ctx->r29, 0XC0);
    // 0x8003AF80: addiu       $a3, $zero, 0x19
    ctx->r7 = ADD32(0, 0X19);
    // 0x8003AF84: jal         0x80043DE8
    // 0x8003AF88: swc1        $f6, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f6.u32l;
    func_80043DE8(rdram, ctx);
        goto after_7;
    // 0x8003AF88: swc1        $f6, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f6.u32l;
    after_7:
    // 0x8003AF8C: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8003AF90: sh          $t6, 0x96($s2)
    MEM_H(0X96, ctx->r18) = ctx->r14;
L_8003AF94:
    // 0x8003AF94: addiu       $t7, $s2, 0x10
    ctx->r15 = ADD32(ctx->r18, 0X10);
L_8003AF98:
    // 0x8003AF98: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x8003AF9C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8003AFA0: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
L_8003AFA4:
    // 0x8003AFA4: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003AFA8: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8003AFAC: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8003AFB0: lwc1        $f10, 0x5C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x8003AFB4: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8003AFB8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8003AFBC: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x8003AFC0: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8003AFC4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8003AFC8: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8003AFCC: bne         $at, $zero, L_8003AFA4
    if (ctx->r1 != 0) {
        // 0x8003AFD0: swc1        $f6, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
            goto L_8003AFA4;
    }
    // 0x8003AFD0: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
    // 0x8003AFD4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003AFD8: lwc1        $f18, 0x7468($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7468);
    // 0x8003AFDC: lwc1        $f16, 0x48($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X48);
    // 0x8003AFE0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003AFE4: addiu       $s0, $sp, 0x80
    ctx->r16 = ADD32(ctx->r29, 0X80);
    // 0x8003AFE8: sub.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8003AFEC: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    // 0x8003AFF0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003AFF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003AFF8: swc1        $f8, 0x48($s2)
    MEM_W(0X48, ctx->r18) = ctx->f8.u32l;
    // 0x8003AFFC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8003B000: jal         0x80049840
    // 0x8003B004: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80049840(rdram, ctx);
        goto after_8;
    // 0x8003B004: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x8003B008: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003B00C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003B010: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003B014: addiu       $s1, $sp, 0x40
    ctx->r17 = ADD32(ctx->r29, 0X40);
    // 0x8003B018: lw          $a1, 0x24($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X24);
    // 0x8003B01C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003B020: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003B024: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8003B028: jal         0x80049840
    // 0x8003B02C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80049840(rdram, ctx);
        goto after_9;
    // 0x8003B02C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_9:
    // 0x8003B030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003B034: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8003B038: jal         0x80000BD8
    // 0x8003B03C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_80000BD8(rdram, ctx);
        goto after_10;
    // 0x8003B03C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_10:
    // 0x8003B040: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003B044: lw          $a1, 0x20($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X20);
    // 0x8003B048: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8003B04C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003B050: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8003B054: jal         0x80049840
    // 0x8003B058: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80049840(rdram, ctx);
        goto after_11;
    // 0x8003B058: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_11:
    // 0x8003B05C: lw          $t8, 0xC($s2)
    ctx->r24 = MEM_W(ctx->r18, 0XC);
    // 0x8003B060: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8003B064: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8003B068: lw          $a0, 0x8($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X8);
    // 0x8003B06C: jal         0x80000BD8
    // 0x8003B070: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80000BD8(rdram, ctx);
        goto after_12;
    // 0x8003B070: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_12:
    // 0x8003B074: lwc1        $f0, 0x2C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X2C);
    // 0x8003B078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003B07C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003B080: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003B084: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003B088: jal         0x80001AB4
    // 0x8003B08C: nop

    func_80001AB4(rdram, ctx);
        goto after_13;
    // 0x8003B08C: nop

    after_13:
    // 0x8003B090: lw          $t9, 0xC($s2)
    ctx->r25 = MEM_W(ctx->r18, 0XC);
    // 0x8003B094: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8003B098: lw          $a0, 0x8($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X8);
    // 0x8003B09C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8003B0A0: jal         0x80000BD8
    // 0x8003B0A4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_80000BD8(rdram, ctx);
        goto after_14;
    // 0x8003B0A4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_14:
    // 0x8003B0A8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8003B0AC: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x8003B0B0: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_8003B0B4:
    // 0x8003B0B4: lw          $t0, 0xC($s2)
    ctx->r8 = MEM_W(ctx->r18, 0XC);
    // 0x8003B0B8: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003B0BC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8003B0C0: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x8003B0C4: addu        $t2, $t1, $s1
    ctx->r10 = ADD32(ctx->r9, ctx->r17);
    // 0x8003B0C8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8003B0CC: bne         $s1, $v0, L_8003B0B4
    if (ctx->r17 != ctx->r2) {
        // 0x8003B0D0: swc1        $f10, 0x40($t2)
        MEM_W(0X40, ctx->r10) = ctx->f10.u32l;
            goto L_8003B0B4;
    }
    // 0x8003B0D0: swc1        $f10, 0x40($t2)
    MEM_W(0X40, ctx->r10) = ctx->f10.u32l;
    // 0x8003B0D4: addiu       $s0, $sp, 0xD4
    ctx->r16 = ADD32(ctx->r29, 0XD4);
    // 0x8003B0D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003B0DC: jal         0x8000D3A4
    // 0x8003B0E0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_8000D3A4(rdram, ctx);
        goto after_15;
    // 0x8003B0E0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_15:
    // 0x8003B0E4: beq         $v0, $zero, L_8003B128
    if (ctx->r2 == 0) {
        // 0x8003B0E8: lwc1        $f6, 0xD8($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0XD8);
            goto L_8003B128;
    }
    // 0x8003B0E8: lwc1        $f6, 0xD8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x8003B0EC: lwc1        $f16, 0x14($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8003B0F0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8003B0F4: c.le.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl <= ctx->f6.fl;
    // 0x8003B0F8: nop

    // 0x8003B0FC: bc1fl       L_8003B12C
    if (!c1cs) {
        // 0x8003B100: lh          $v1, 0x94($s2)
        ctx->r3 = MEM_H(ctx->r18, 0X94);
            goto L_8003B12C;
    }
    goto skip_4;
    // 0x8003B100: lh          $v1, 0x94($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X94);
    skip_4:
    // 0x8003B104: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003B108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003B10C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8003B110: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8003B114: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003B118: jal         0x80042F80
    // 0x8003B11C: swc1        $f8, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f8.u32l;
    func_80042F80(rdram, ctx);
        goto after_16;
    // 0x8003B11C: swc1        $f8, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f8.u32l;
    after_16:
    // 0x8003B120: jal         0x8003A008
    // 0x8003B124: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8003A008(rdram, ctx);
        goto after_17;
    // 0x8003B124: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_17:
L_8003B128:
    // 0x8003B128: lh          $v1, 0x94($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X94);
L_8003B12C:
    // 0x8003B12C: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x8003B130: beq         $v1, $zero, L_8003B13C
    if (ctx->r3 == 0) {
        // 0x8003B134: addiu       $t3, $v1, -0x1
        ctx->r11 = ADD32(ctx->r3, -0X1);
            goto L_8003B13C;
    }
    // 0x8003B134: addiu       $t3, $v1, -0x1
    ctx->r11 = ADD32(ctx->r3, -0X1);
    // 0x8003B138: sh          $t3, 0x94($s2)
    MEM_H(0X94, ctx->r18) = ctx->r11;
L_8003B13C:
    // 0x8003B13C: lh          $v1, 0x96($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X96);
    // 0x8003B140: beq         $v1, $zero, L_8003B14C
    if (ctx->r3 == 0) {
        // 0x8003B144: addiu       $t4, $v1, -0x1
        ctx->r12 = ADD32(ctx->r3, -0X1);
            goto L_8003B14C;
    }
    // 0x8003B144: addiu       $t4, $v1, -0x1
    ctx->r12 = ADD32(ctx->r3, -0X1);
    // 0x8003B148: sh          $t4, 0x96($v0)
    MEM_H(0X96, ctx->r2) = ctx->r12;
L_8003B14C:
    // 0x8003B14C: lh          $v1, 0x98($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X98);
    // 0x8003B150: beq         $v1, $zero, L_8003B15C
    if (ctx->r3 == 0) {
        // 0x8003B154: addiu       $t5, $v1, -0x1
        ctx->r13 = ADD32(ctx->r3, -0X1);
            goto L_8003B15C;
    }
    // 0x8003B154: addiu       $t5, $v1, -0x1
    ctx->r13 = ADD32(ctx->r3, -0X1);
    // 0x8003B158: sh          $t5, 0x98($v0)
    MEM_H(0X98, ctx->r2) = ctx->r13;
L_8003B15C:
    // 0x8003B15C: lh          $v1, 0x9A($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X9A);
    // 0x8003B160: beq         $v1, $zero, L_8003B16C
    if (ctx->r3 == 0) {
        // 0x8003B164: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_8003B16C;
    }
    // 0x8003B164: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8003B168: sh          $t6, 0x9A($v0)
    MEM_H(0X9A, ctx->r2) = ctx->r14;
L_8003B16C:
    // 0x8003B16C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8003B170: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003B174: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8003B178: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8003B17C: jr          $ra
    // 0x8003B180: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    TRACE_RETURN()
    return;
    // 0x8003B180: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
;}
RECOMP_FUNC void func_8003B184(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8003B184: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x8003B188: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003B18C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003B190: lh          $v0, 0x90($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X90);
    // 0x8003B194: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003B198: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003B19C: beql        $v0, $zero, L_8003B1C0
    if (ctx->r2 == 0) {
        // 0x8003B1A0: lh          $t6, 0x36($s0)
        ctx->r14 = MEM_H(ctx->r16, 0X36);
            goto L_8003B1C0;
    }
    goto skip_0;
    // 0x8003B1A0: lh          $t6, 0x36($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X36);
    skip_0:
    // 0x8003B1A4: beq         $v0, $at, L_8003B294
    if (ctx->r2 == ctx->r1) {
        // 0x8003B1A8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8003B294;
    }
    // 0x8003B1A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003B1AC: beql        $v0, $at, L_8003B4B4
    if (ctx->r2 == ctx->r1) {
        // 0x8003B1B0: lh          $v1, 0x94($s0)
        ctx->r3 = MEM_H(ctx->r16, 0X94);
            goto L_8003B4B4;
    }
    goto skip_1;
    // 0x8003B1B0: lh          $v1, 0x94($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X94);
    skip_1:
    // 0x8003B1B4: b           L_8003B4B4
    // 0x8003B1B8: lh          $v1, 0x94($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X94);
        goto L_8003B4B4;
    // 0x8003B1B8: lh          $v1, 0x94($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X94);
    // 0x8003B1BC: lh          $t6, 0x36($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X36);
L_8003B1C0:
    // 0x8003B1C0: bgtzl       $t6, L_8003B4B4
    if (SIGNED(ctx->r14) > 0) {
        // 0x8003B1C4: lh          $v1, 0x94($s0)
        ctx->r3 = MEM_H(ctx->r16, 0X94);
            goto L_8003B4B4;
    }
    goto skip_2;
    // 0x8003B1C4: lh          $v1, 0x94($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X94);
    skip_2:
    // 0x8003B1C8: jal         0x8003A4E8
    // 0x8003B1CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003A4E8(rdram, ctx);
        goto after_0;
    // 0x8003B1CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8003B1D0: addiu       $v0, $sp, 0xCC
    ctx->r2 = ADD32(ctx->r29, 0XCC);
    // 0x8003B1D4: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8003B1D8: addiu       $a0, $sp, 0xD8
    ctx->r4 = ADD32(ctx->r29, 0XD8);
L_8003B1DC:
    // 0x8003B1DC: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8003B1E0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003B1E4: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x8003B1E8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003B1EC: bne         $at, $zero, L_8003B1DC
    if (ctx->r1 != 0) {
        // 0x8003B1F0: swc1        $f4, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
            goto L_8003B1DC;
    }
    // 0x8003B1F0: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x8003B1F4: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
    // 0x8003B1F8: lwc1        $f6, 0xD0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x8003B1FC: addiu       $a0, $sp, 0xCC
    ctx->r4 = ADD32(ctx->r29, 0XCC);
    // 0x8003B200: lh          $t8, 0x4($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X4);
    // 0x8003B204: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8003B208: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003B20C: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8003B210: nop

    // 0x8003B214: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8003B218: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8003B21C: jal         0x80042F80
    // 0x8003B220: swc1        $f16, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f16.u32l;
    func_80042F80(rdram, ctx);
        goto after_1;
    // 0x8003B220: swc1        $f16, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x8003B224: addiu       $a0, $sp, 0xCC
    ctx->r4 = ADD32(ctx->r29, 0XCC);
    // 0x8003B228: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8003B22C: jal         0x80043714
    // 0x8003B230: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80043714(rdram, ctx);
        goto after_2;
    // 0x8003B230: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8003B234: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x8003B238: sh          $t9, 0x94($s0)
    MEM_H(0X94, ctx->r16) = ctx->r25;
    // 0x8003B23C: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x8003B240: jal         0x8000DD44
    // 0x8003B244: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    func_8000DD44(rdram, ctx);
        goto after_3;
    // 0x8003B244: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    after_3:
    // 0x8003B248: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8003B24C: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8003B250: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8003B254:
    // 0x8003B254: lwc1        $f18, 0x44($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X44);
    // 0x8003B258: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8003B25C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003B260: bne         $a0, $v0, L_8003B254
    if (ctx->r4 != ctx->r2) {
        // 0x8003B264: swc1        $f18, 0x40($v1)
        MEM_W(0X40, ctx->r3) = ctx->f18.u32l;
            goto L_8003B254;
    }
    // 0x8003B264: swc1        $f18, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f18.u32l;
    // 0x8003B268: lh          $t0, 0x92($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X92);
    // 0x8003B26C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8003B270: andi        $t1, $t0, 0x4
    ctx->r9 = ctx->r8 & 0X4;
    // 0x8003B274: beq         $t1, $zero, L_8003B28C
    if (ctx->r9 == 0) {
        // 0x8003B278: nop
    
            goto L_8003B28C;
    }
    // 0x8003B278: nop

    // 0x8003B27C: lw          $v0, 0xB8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB8);
    // 0x8003B280: lh          $t2, 0xA2($v0)
    ctx->r10 = MEM_H(ctx->r2, 0XA2);
    // 0x8003B284: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8003B288: sh          $t3, 0xA2($v0)
    MEM_H(0XA2, ctx->r2) = ctx->r11;
L_8003B28C:
    // 0x8003B28C: b           L_8003B4B0
    // 0x8003B290: sh          $t4, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r12;
        goto L_8003B4B0;
    // 0x8003B290: sh          $t4, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r12;
L_8003B294:
    // 0x8003B294: lh          $t5, 0x94($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X94);
    // 0x8003B298: beql        $t5, $zero, L_8003B328
    if (ctx->r13 == 0) {
        // 0x8003B29C: addiu       $t3, $s0, 0x10
        ctx->r11 = ADD32(ctx->r16, 0X10);
            goto L_8003B328;
    }
    goto skip_3;
    // 0x8003B29C: addiu       $t3, $s0, 0x10
    ctx->r11 = ADD32(ctx->r16, 0X10);
    skip_3:
    // 0x8003B2A0: lh          $t6, 0x96($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X96);
    // 0x8003B2A4: addiu       $v0, $sp, 0xCC
    ctx->r2 = ADD32(ctx->r29, 0XCC);
    // 0x8003B2A8: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8003B2AC: bne         $t6, $zero, L_8003B324
    if (ctx->r14 != 0) {
        // 0x8003B2B0: addiu       $a0, $sp, 0xD8
        ctx->r4 = ADD32(ctx->r29, 0XD8);
            goto L_8003B324;
    }
    // 0x8003B2B0: addiu       $a0, $sp, 0xD8
    ctx->r4 = ADD32(ctx->r29, 0XD8);
L_8003B2B4:
    // 0x8003B2B4: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8003B2B8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003B2BC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003B2C0: bne         $v0, $a0, L_8003B2B4
    if (ctx->r2 != ctx->r4) {
        // 0x8003B2C4: swc1        $f4, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
            goto L_8003B2B4;
    }
    // 0x8003B2C4: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x8003B2C8: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
    // 0x8003B2CC: lwc1        $f8, 0xD0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x8003B2D0: addiu       $t9, $zero, 0x1F
    ctx->r25 = ADD32(0, 0X1F);
    // 0x8003B2D4: lh          $t8, 0x4($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X4);
    // 0x8003B2D8: addiu       $t0, $zero, 0xF
    ctx->r8 = ADD32(0, 0XF);
    // 0x8003B2DC: addiu       $t1, $zero, 0x1F
    ctx->r9 = ADD32(0, 0X1F);
    // 0x8003B2E0: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8003B2E4: sh          $t1, 0xC4($sp)
    MEM_H(0XC4, ctx->r29) = ctx->r9;
    // 0x8003B2E8: sh          $t0, 0xC2($sp)
    MEM_H(0XC2, ctx->r29) = ctx->r8;
    // 0x8003B2EC: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8003B2F0: sh          $t9, 0xC0($sp)
    MEM_H(0XC0, ctx->r29) = ctx->r25;
    // 0x8003B2F4: sh          $zero, 0xBC($sp)
    MEM_H(0XBC, ctx->r29) = 0;
    // 0x8003B2F8: sh          $zero, 0xBA($sp)
    MEM_H(0XBA, ctx->r29) = 0;
    // 0x8003B2FC: sh          $zero, 0xB8($sp)
    MEM_H(0XB8, ctx->r29) = 0;
    // 0x8003B300: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    // 0x8003B304: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8003B308: addiu       $a1, $sp, 0xC0
    ctx->r5 = ADD32(ctx->r29, 0XC0);
    // 0x8003B30C: addiu       $a2, $sp, 0xB8
    ctx->r6 = ADD32(ctx->r29, 0XB8);
    // 0x8003B310: addiu       $a3, $zero, 0x19
    ctx->r7 = ADD32(0, 0X19);
    // 0x8003B314: jal         0x80043DE8
    // 0x8003B318: swc1        $f16, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f16.u32l;
    func_80043DE8(rdram, ctx);
        goto after_4;
    // 0x8003B318: swc1        $f16, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f16.u32l;
    after_4:
    // 0x8003B31C: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8003B320: sh          $t2, 0x96($s0)
    MEM_H(0X96, ctx->r16) = ctx->r10;
L_8003B324:
    // 0x8003B324: addiu       $t3, $s0, 0x10
    ctx->r11 = ADD32(ctx->r16, 0X10);
L_8003B328:
    // 0x8003B328: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003B32C: lwc1        $f0, 0x746C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X746C);
    // 0x8003B330: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x8003B334: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8003B338: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
L_8003B33C:
    // 0x8003B33C: lwc1        $f18, 0x10($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8003B340: lwc1        $f4, 0x44($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X44);
    // 0x8003B344: lwc1        $f8, 0x1C($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x8003B348: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8003B34C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8003B350: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x8003B354: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003B358: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8003B35C: swc1        $f6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f6.u32l;
    // 0x8003B360: bne         $at, $zero, L_8003B33C
    if (ctx->r1 != 0) {
        // 0x8003B364: swc1        $f10, 0x18($v1)
        MEM_W(0X18, ctx->r3) = ctx->f10.u32l;
            goto L_8003B33C;
    }
    // 0x8003B364: swc1        $f10, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f10.u32l;
    // 0x8003B368: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003B36C: lwc1        $f18, 0x7470($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7470);
    // 0x8003B370: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8003B374: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003B378: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x8003B37C: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8003B380: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003B384: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x8003B388: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8003B38C: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    // 0x8003B390: jal         0x80049840
    // 0x8003B394: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80049840(rdram, ctx);
        goto after_5;
    // 0x8003B394: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x8003B398: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003B39C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003B3A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003B3A4: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    // 0x8003B3A8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003B3AC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003B3B0: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8003B3B4: jal         0x80049840
    // 0x8003B3B8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_80049840(rdram, ctx);
        goto after_6;
    // 0x8003B3B8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_6:
    // 0x8003B3BC: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x8003B3C0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8003B3C4: jal         0x80000BD8
    // 0x8003B3C8: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    func_80000BD8(rdram, ctx);
        goto after_7;
    // 0x8003B3C8: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_7:
    // 0x8003B3CC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003B3D0: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    // 0x8003B3D4: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8003B3D8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003B3DC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8003B3E0: jal         0x80049840
    // 0x8003B3E4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80049840(rdram, ctx);
        goto after_8;
    // 0x8003B3E4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x8003B3E8: lw          $t4, 0xC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XC);
    // 0x8003B3EC: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8003B3F0: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    // 0x8003B3F4: lw          $a0, 0x8($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X8);
    // 0x8003B3F8: jal         0x80000BD8
    // 0x8003B3FC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80000BD8(rdram, ctx);
        goto after_9;
    // 0x8003B3FC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_9:
    // 0x8003B400: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8003B404: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x8003B408: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003B40C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003B410: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003B414: jal         0x80001AB4
    // 0x8003B418: nop

    func_80001AB4(rdram, ctx);
        goto after_10;
    // 0x8003B418: nop

    after_10:
    // 0x8003B41C: lw          $t5, 0xC($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XC);
    // 0x8003B420: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    // 0x8003B424: lw          $a0, 0x8($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X8);
    // 0x8003B428: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8003B42C: jal         0x80000BD8
    // 0x8003B430: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_80000BD8(rdram, ctx);
        goto after_11;
    // 0x8003B430: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_11:
    // 0x8003B434: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003B438: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8003B43C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
L_8003B440:
    // 0x8003B440: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x8003B444: lwc1        $f8, 0x10($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8003B448: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003B44C: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x8003B450: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8003B454: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003B458: bne         $v0, $a0, L_8003B440
    if (ctx->r2 != ctx->r4) {
        // 0x8003B45C: swc1        $f8, 0x40($t8)
        MEM_W(0X40, ctx->r24) = ctx->f8.u32l;
            goto L_8003B440;
    }
    // 0x8003B45C: swc1        $f8, 0x40($t8)
    MEM_W(0X40, ctx->r24) = ctx->f8.u32l;
    // 0x8003B460: addiu       $a0, $sp, 0xCC
    ctx->r4 = ADD32(ctx->r29, 0XCC);
    // 0x8003B464: jal         0x8000D3A4
    // 0x8003B468: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_8000D3A4(rdram, ctx);
        goto after_12;
    // 0x8003B468: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_12:
    // 0x8003B46C: beq         $v0, $zero, L_8003B4B0
    if (ctx->r2 == 0) {
        // 0x8003B470: lwc1        $f10, 0xD0($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0XD0);
            goto L_8003B4B0;
    }
    // 0x8003B470: lwc1        $f10, 0xD0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x8003B474: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003B478: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8003B47C: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x8003B480: nop

    // 0x8003B484: bc1fl       L_8003B4B4
    if (!c1cs) {
        // 0x8003B488: lh          $v1, 0x94($s0)
        ctx->r3 = MEM_H(ctx->r16, 0X94);
            goto L_8003B4B4;
    }
    goto skip_4;
    // 0x8003B488: lh          $v1, 0x94($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X94);
    skip_4:
    // 0x8003B48C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003B490: addiu       $a0, $sp, 0xCC
    ctx->r4 = ADD32(ctx->r29, 0XCC);
    // 0x8003B494: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8003B498: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8003B49C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003B4A0: jal         0x80042F80
    // 0x8003B4A4: swc1        $f4, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f4.u32l;
    func_80042F80(rdram, ctx);
        goto after_13;
    // 0x8003B4A4: swc1        $f4, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f4.u32l;
    after_13:
    // 0x8003B4A8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8003B4AC: sh          $t9, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r25;
L_8003B4B0:
    // 0x8003B4B0: lh          $v1, 0x94($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X94);
L_8003B4B4:
    // 0x8003B4B4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8003B4B8: beq         $v1, $zero, L_8003B4C4
    if (ctx->r3 == 0) {
        // 0x8003B4BC: addiu       $t0, $v1, -0x1
        ctx->r8 = ADD32(ctx->r3, -0X1);
            goto L_8003B4C4;
    }
    // 0x8003B4BC: addiu       $t0, $v1, -0x1
    ctx->r8 = ADD32(ctx->r3, -0X1);
    // 0x8003B4C0: sh          $t0, 0x94($s0)
    MEM_H(0X94, ctx->r16) = ctx->r8;
L_8003B4C4:
    // 0x8003B4C4: lh          $v1, 0x96($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X96);
    // 0x8003B4C8: beq         $v1, $zero, L_8003B4D4
    if (ctx->r3 == 0) {
        // 0x8003B4CC: addiu       $t1, $v1, -0x1
        ctx->r9 = ADD32(ctx->r3, -0X1);
            goto L_8003B4D4;
    }
    // 0x8003B4CC: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
    // 0x8003B4D0: sh          $t1, 0x96($v0)
    MEM_H(0X96, ctx->r2) = ctx->r9;
L_8003B4D4:
    // 0x8003B4D4: lh          $v1, 0x98($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X98);
    // 0x8003B4D8: beq         $v1, $zero, L_8003B4E4
    if (ctx->r3 == 0) {
        // 0x8003B4DC: addiu       $t2, $v1, -0x1
        ctx->r10 = ADD32(ctx->r3, -0X1);
            goto L_8003B4E4;
    }
    // 0x8003B4DC: addiu       $t2, $v1, -0x1
    ctx->r10 = ADD32(ctx->r3, -0X1);
    // 0x8003B4E0: sh          $t2, 0x98($v0)
    MEM_H(0X98, ctx->r2) = ctx->r10;
L_8003B4E4:
    // 0x8003B4E4: lh          $v1, 0x9A($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X9A);
    // 0x8003B4E8: beq         $v1, $zero, L_8003B4F4
    if (ctx->r3 == 0) {
        // 0x8003B4EC: addiu       $t3, $v1, -0x1
        ctx->r11 = ADD32(ctx->r3, -0X1);
            goto L_8003B4F4;
    }
    // 0x8003B4EC: addiu       $t3, $v1, -0x1
    ctx->r11 = ADD32(ctx->r3, -0X1);
    // 0x8003B4F0: sh          $t3, 0x9A($v0)
    MEM_H(0X9A, ctx->r2) = ctx->r11;
L_8003B4F4:
    // 0x8003B4F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003B4F8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003B4FC: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    // 0x8003B500: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8003B508(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8003B508: addiu       $sp, $sp, -0x120
    ctx->r29 = ADD32(ctx->r29, -0X120);
    // 0x8003B50C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8003B510: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8003B514: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8003B518: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8003B51C: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8003B520: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8003B524: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8003B528: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8003B52C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8003B530: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8003B534: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8003B538: lh          $v0, 0x90($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X90);
    // 0x8003B53C: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x8003B540: lui         $s3, 0x8007
    ctx->r19 = S32(0X8007 << 16);
    // 0x8003B544: beq         $v0, $zero, L_8003B574
    if (ctx->r2 == 0) {
        // 0x8003B548: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_8003B574;
    }
    // 0x8003B548: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8003B54C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003B550: beq         $v0, $at, L_8003B6C8
    if (ctx->r2 == ctx->r1) {
        // 0x8003B554: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8003B6C8;
    }
    // 0x8003B554: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003B558: beq         $v0, $at, L_8003B7DC
    if (ctx->r2 == ctx->r1) {
        // 0x8003B55C: addiu       $a0, $zero, 0xC
        ctx->r4 = ADD32(0, 0XC);
            goto L_8003B7DC;
    }
    // 0x8003B55C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x8003B560: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003B564: beql        $v0, $at, L_8003B90C
    if (ctx->r2 == ctx->r1) {
        // 0x8003B568: lh          $v1, 0x94($s7)
        ctx->r3 = MEM_H(ctx->r23, 0X94);
            goto L_8003B90C;
    }
    goto skip_0;
    // 0x8003B568: lh          $v1, 0x94($s7)
    ctx->r3 = MEM_H(ctx->r23, 0X94);
    skip_0:
    // 0x8003B56C: b           L_8003B90C
    // 0x8003B570: lh          $v1, 0x94($s7)
    ctx->r3 = MEM_H(ctx->r23, 0X94);
        goto L_8003B90C;
    // 0x8003B570: lh          $v1, 0x94($s7)
    ctx->r3 = MEM_H(ctx->r23, 0X94);
L_8003B574:
    // 0x8003B574: lui         $fp, 0x8007
    ctx->r30 = S32(0X8007 << 16);
    // 0x8003B578: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x8003B57C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8003B580: addiu       $s6, $s6, -0x659C
    ctx->r22 = ADD32(ctx->r22, -0X659C);
    // 0x8003B584: addiu       $fp, $fp, -0x5C20
    ctx->r30 = ADD32(ctx->r30, -0X5C20);
    // 0x8003B588: addiu       $s3, $s3, -0x5C30
    ctx->r19 = ADD32(ctx->r19, -0X5C30);
    // 0x8003B58C: addiu       $s2, $sp, 0xC4
    ctx->r18 = ADD32(ctx->r29, 0XC4);
L_8003B590:
    // 0x8003B590: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8003B594: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003B598: jal         0x8003DE20
    // 0x8003B59C: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    func_8003DE20(rdram, ctx);
        goto after_0;
    // 0x8003B59C: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    after_0:
    // 0x8003B5A0: beq         $v0, $zero, L_8003B6A8
    if (ctx->r2 == 0) {
        // 0x8003B5A4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8003B6A8;
    }
    // 0x8003B5A4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8003B5A8: lh          $t6, 0x8($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X8);
    // 0x8003B5AC: lh          $t7, 0xA($s3)
    ctx->r15 = MEM_H(ctx->r19, 0XA);
    // 0x8003B5B0: lh          $t8, 0xC($s3)
    ctx->r24 = MEM_H(ctx->r19, 0XC);
    // 0x8003B5B4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8003B5B8: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8003B5BC: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8003B5C0: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003B5C4: sll         $t9, $s4, 3
    ctx->r25 = S32(ctx->r20 << 3);
    // 0x8003B5C8: subu        $t9, $t9, $s4
    ctx->r25 = SUB32(ctx->r25, ctx->r20);
    // 0x8003B5CC: lui         $t0, 0x8007
    ctx->r8 = S32(0X8007 << 16);
    // 0x8003B5D0: addiu       $t0, $t0, -0x5C30
    ctx->r8 = ADD32(ctx->r8, -0X5C30);
    // 0x8003B5D4: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8003B5D8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8003B5DC: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8003B5E0: sll         $t1, $s4, 2
    ctx->r9 = S32(ctx->r20 << 2);
    // 0x8003B5E4: addu        $s1, $s7, $t1
    ctx->r17 = ADD32(ctx->r23, ctx->r9);
    // 0x8003B5E8: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8003B5EC: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8003B5F0: addu        $s5, $t9, $t0
    ctx->r21 = ADD32(ctx->r25, ctx->r8);
    // 0x8003B5F4: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    // 0x8003B5F8: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8003B5FC: jal         0x80001A6C
    // 0x8003B600: nop

    func_80001A6C(rdram, ctx);
        goto after_1;
    // 0x8003B600: nop

    after_1:
    // 0x8003B604: lw          $a1, 0x20($s7)
    ctx->r5 = MEM_W(ctx->r23, 0X20);
    // 0x8003B608: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8003B60C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8003B610: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x8003B614: jal         0x80049840
    // 0x8003B618: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_80049840(rdram, ctx);
        goto after_2;
    // 0x8003B618: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x8003B61C: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    // 0x8003B620: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8003B624: jal         0x80000BD8
    // 0x8003B628: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    func_80000BD8(rdram, ctx);
        goto after_3;
    // 0x8003B628: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    after_3:
    // 0x8003B62C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8003B630: addiu       $v1, $sp, 0xB8
    ctx->r3 = ADD32(ctx->r29, 0XB8);
    // 0x8003B634: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8003B638: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
L_8003B63C:
    // 0x8003B63C: lwc1        $f10, 0x30($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X30);
    // 0x8003B640: lwc1        $f16, 0x10($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8003B644: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003B648: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003B64C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8003B650: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8003B654: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8003B658: swc1        $f18, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f18.u32l;
    // 0x8003B65C: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8003B660: lwc1        $f4, 0xC($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8003B664: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003B668: bne         $v1, $s2, L_8003B63C
    if (ctx->r3 != ctx->r18) {
        // 0x8003B66C: swc1        $f8, 0x18($v0)
        MEM_W(0X18, ctx->r2) = ctx->f8.u32l;
            goto L_8003B63C;
    }
    // 0x8003B66C: swc1        $f8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f8.u32l;
    // 0x8003B670: lw          $t2, 0x80($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X80);
    // 0x8003B674: sw          $t2, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->r10;
    // 0x8003B678: lw          $t3, 0x0($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X0);
    // 0x8003B67C: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x8003B680: sw          $s0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r16;
    // 0x8003B684: lw          $t5, 0x0($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X0);
    // 0x8003B688: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x8003B68C: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x8003B690: lw          $t7, 0x0($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X0);
    // 0x8003B694: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8003B698: lw          $t8, 0x0($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X0);
    // 0x8003B69C: sw          $s0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r16;
    // 0x8003B6A0: sw          $s7, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->r23;
    // 0x8003B6A4: sw          $s0, 0xB8($s1)
    MEM_W(0XB8, ctx->r17) = ctx->r16;
L_8003B6A8:
    // 0x8003B6A8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8003B6AC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8003B6B0: addiu       $s3, $s3, 0x1C
    ctx->r19 = ADD32(ctx->r19, 0X1C);
    // 0x8003B6B4: bne         $s4, $v0, L_8003B590
    if (ctx->r20 != ctx->r2) {
        // 0x8003B6B8: addiu       $fp, $fp, 0x1C
        ctx->r30 = ADD32(ctx->r30, 0X1C);
            goto L_8003B590;
    }
    // 0x8003B6B8: addiu       $fp, $fp, 0x1C
    ctx->r30 = ADD32(ctx->r30, 0X1C);
    // 0x8003B6BC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8003B6C0: sh          $v0, 0xA2($s7)
    MEM_H(0XA2, ctx->r23) = ctx->r2;
    // 0x8003B6C4: sh          $t9, 0x90($s7)
    MEM_H(0X90, ctx->r23) = ctx->r25;
L_8003B6C8:
    // 0x8003B6C8: lh          $t0, 0xA2($s7)
    ctx->r8 = MEM_H(ctx->r23, 0XA2);
    // 0x8003B6CC: bnel        $t0, $zero, L_8003B90C
    if (ctx->r8 != 0) {
        // 0x8003B6D0: lh          $v1, 0x94($s7)
        ctx->r3 = MEM_H(ctx->r23, 0X94);
            goto L_8003B90C;
    }
    goto skip_1;
    // 0x8003B6D0: lh          $v1, 0x94($s7)
    ctx->r3 = MEM_H(ctx->r23, 0X94);
    skip_1:
    // 0x8003B6D4: lw          $t1, 0xC($s7)
    ctx->r9 = MEM_W(ctx->r23, 0XC);
    // 0x8003B6D8: sh          $zero, 0x36($s7)
    MEM_H(0X36, ctx->r23) = 0;
    // 0x8003B6DC: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    // 0x8003B6E0: lw          $a1, 0x8($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X8);
    // 0x8003B6E4: jal         0x80002340
    // 0x8003B6E8: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    func_80002340(rdram, ctx);
        goto after_4;
    // 0x8003B6E8: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_4:
    // 0x8003B6EC: jal         0x8004A0C4
    // 0x8003B6F0: lw          $a0, 0xC($s7)
    ctx->r4 = MEM_W(ctx->r23, 0XC);
    func_8004A0C4(rdram, ctx);
        goto after_5;
    // 0x8003B6F0: lw          $a0, 0xC($s7)
    ctx->r4 = MEM_W(ctx->r23, 0XC);
    after_5:
    // 0x8003B6F4: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x8003B6F8: jal         0x80049CFC
    // 0x8003B6FC: addiu       $a0, $a0, 0x7424
    ctx->r4 = ADD32(ctx->r4, 0X7424);
    func_80049CFC(rdram, ctx);
        goto after_6;
    // 0x8003B6FC: addiu       $a0, $a0, 0x7424
    ctx->r4 = ADD32(ctx->r4, 0X7424);
    after_6:
    // 0x8003B700: jal         0x80049D80
    // 0x8003B704: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80049D80(rdram, ctx);
        goto after_7;
    // 0x8003B704: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x8003B708: sw          $v0, 0x8($s7)
    MEM_W(0X8, ctx->r23) = ctx->r2;
    // 0x8003B70C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8003B710: jal         0x80049DFC
    // 0x8003B714: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80049DFC(rdram, ctx);
        goto after_8;
    // 0x8003B714: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x8003B718: sw          $v0, 0xC($s7)
    MEM_W(0XC, ctx->r23) = ctx->r2;
    // 0x8003B71C: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    // 0x8003B720: addiu       $a1, $sp, 0xB8
    ctx->r5 = ADD32(ctx->r29, 0XB8);
    // 0x8003B724: jal         0x80002340
    // 0x8003B728: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80002340(rdram, ctx);
        goto after_9;
    // 0x8003B728: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_9:
    // 0x8003B72C: jal         0x8004A148
    // 0x8003B730: lw          $a0, 0xC($s7)
    ctx->r4 = MEM_W(ctx->r23, 0XC);
    func_8004A148(rdram, ctx);
        goto after_10;
    // 0x8003B730: lw          $a0, 0xC($s7)
    ctx->r4 = MEM_W(ctx->r23, 0XC);
    after_10:
    // 0x8003B734: lw          $t3, 0xC($s7)
    ctx->r11 = MEM_W(ctx->r23, 0XC);
    // 0x8003B738: lw          $t2, 0x80($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X80);
    // 0x8003B73C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8003B740: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x8003B744: jal         0x8003A4E8
    // 0x8003B748: sw          $t2, 0xD8($t4)
    MEM_W(0XD8, ctx->r12) = ctx->r10;
    func_8003A4E8(rdram, ctx);
        goto after_11;
    // 0x8003B748: sw          $t2, 0xD8($t4)
    MEM_W(0XD8, ctx->r12) = ctx->r10;
    after_11:
    // 0x8003B74C: or          $s1, $s7, $zero
    ctx->r17 = ctx->r23 | 0;
    // 0x8003B750: addiu       $v0, $sp, 0x114
    ctx->r2 = ADD32(ctx->r29, 0X114);
    // 0x8003B754: addiu       $v1, $sp, 0x120
    ctx->r3 = ADD32(ctx->r29, 0X120);
L_8003B758:
    // 0x8003B758: lwc1        $f10, 0x10($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8003B75C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003B760: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8003B764: bne         $v0, $v1, L_8003B758
    if (ctx->r2 != ctx->r3) {
        // 0x8003B768: swc1        $f10, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
            goto L_8003B758;
    }
    // 0x8003B768: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x8003B76C: lw          $t5, 0x30($s7)
    ctx->r13 = MEM_W(ctx->r23, 0X30);
    // 0x8003B770: lwc1        $f16, 0x118($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X118);
    // 0x8003B774: addiu       $s0, $sp, 0x114
    ctx->r16 = ADD32(ctx->r29, 0X114);
    // 0x8003B778: lh          $t6, 0x4($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X4);
    // 0x8003B77C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003B780: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8003B784: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8003B788: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003B78C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8003B790: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8003B794: jal         0x80042F80
    // 0x8003B798: swc1        $f6, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->f6.u32l;
    func_80042F80(rdram, ctx);
        goto after_12;
    // 0x8003B798: swc1        $f6, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->f6.u32l;
    after_12:
    // 0x8003B79C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003B7A0: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x8003B7A4: jal         0x80042F80
    // 0x8003B7A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80042F80(rdram, ctx);
        goto after_13;
    // 0x8003B7A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
    // 0x8003B7AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003B7B0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8003B7B4: jal         0x80043714
    // 0x8003B7B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80043714(rdram, ctx);
        goto after_14;
    // 0x8003B7B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_14:
    // 0x8003B7BC: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x8003B7C0: sh          $t7, 0x94($s7)
    MEM_H(0X94, ctx->r23) = ctx->r15;
    // 0x8003B7C4: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x8003B7C8: jal         0x800443A8
    // 0x8003B7CC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    func_800443A8(rdram, ctx);
        goto after_15;
    // 0x8003B7CC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_15:
    // 0x8003B7D0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8003B7D4: b           L_8003B908
    // 0x8003B7D8: sh          $t8, 0x90($s7)
    MEM_H(0X90, ctx->r23) = ctx->r24;
        goto L_8003B908;
    // 0x8003B7D8: sh          $t8, 0x90($s7)
    MEM_H(0X90, ctx->r23) = ctx->r24;
L_8003B7DC:
    // 0x8003B7DC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003B7E0: lwc1        $f0, 0x7474($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7474);
    // 0x8003B7E4: lwc1        $f8, 0x14($s7)
    ctx->f8.u32l = MEM_W(ctx->r23, 0X14);
    // 0x8003B7E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003B7EC: or          $s1, $s7, $zero
    ctx->r17 = ctx->r23 | 0;
    // 0x8003B7F0: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8003B7F4: swc1        $f10, 0x14($s7)
    MEM_W(0X14, ctx->r23) = ctx->f10.u32l;
L_8003B7F8:
    // 0x8003B7F8: lw          $t9, 0xC($s7)
    ctx->r25 = MEM_W(ctx->r23, 0XC);
    // 0x8003B7FC: lwc1        $f18, 0x10($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8003B800: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8003B804: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x8003B808: addu        $t1, $t0, $a1
    ctx->r9 = ADD32(ctx->r8, ctx->r5);
    // 0x8003B80C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8003B810: slti        $at, $a1, 0xC
    ctx->r1 = SIGNED(ctx->r5) < 0XC ? 1 : 0;
    // 0x8003B814: bne         $at, $zero, L_8003B7F8
    if (ctx->r1 != 0) {
        // 0x8003B818: swc1        $f18, 0x40($t1)
        MEM_W(0X40, ctx->r9) = ctx->f18.u32l;
            goto L_8003B7F8;
    }
    // 0x8003B818: swc1        $f18, 0x40($t1)
    MEM_W(0X40, ctx->r9) = ctx->f18.u32l;
    // 0x8003B81C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003B820: or          $s1, $s7, $zero
    ctx->r17 = ctx->r23 | 0;
L_8003B824:
    // 0x8003B824: lw          $s0, 0xB8($s1)
    ctx->r16 = MEM_W(ctx->r17, 0XB8);
    // 0x8003B828: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8003B82C: slti        $at, $a1, 0x10
    ctx->r1 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x8003B830: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003B834: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8003B838: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8003B83C: sub.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x8003B840: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
L_8003B844:
    // 0x8003B844: lw          $t3, 0xC($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XC);
    // 0x8003B848: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8003B84C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003B850: lw          $t2, 0x8($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X8);
    // 0x8003B854: addu        $t4, $t2, $v1
    ctx->r12 = ADD32(ctx->r10, ctx->r3);
    // 0x8003B858: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003B85C: bne         $v1, $a0, L_8003B844
    if (ctx->r3 != ctx->r4) {
        // 0x8003B860: swc1        $f6, 0x40($t4)
        MEM_W(0X40, ctx->r12) = ctx->f6.u32l;
            goto L_8003B844;
    }
    // 0x8003B860: swc1        $f6, 0x40($t4)
    MEM_W(0X40, ctx->r12) = ctx->f6.u32l;
    // 0x8003B864: bne         $at, $zero, L_8003B824
    if (ctx->r1 != 0) {
        // 0x8003B868: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8003B824;
    }
    // 0x8003B868: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8003B86C: lh          $t5, 0x94($s7)
    ctx->r13 = MEM_H(ctx->r23, 0X94);
    // 0x8003B870: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8003B874: beql        $t5, $zero, L_8003B908
    if (ctx->r13 == 0) {
        // 0x8003B878: sh          $t2, 0x90($s7)
        MEM_H(0X90, ctx->r23) = ctx->r10;
            goto L_8003B908;
    }
    goto skip_2;
    // 0x8003B878: sh          $t2, 0x90($s7)
    MEM_H(0X90, ctx->r23) = ctx->r10;
    skip_2:
    // 0x8003B87C: lh          $t6, 0x96($s7)
    ctx->r14 = MEM_H(ctx->r23, 0X96);
    // 0x8003B880: or          $s1, $s7, $zero
    ctx->r17 = ctx->r23 | 0;
    // 0x8003B884: addiu       $v0, $sp, 0x114
    ctx->r2 = ADD32(ctx->r29, 0X114);
    // 0x8003B888: bne         $t6, $zero, L_8003B908
    if (ctx->r14 != 0) {
        // 0x8003B88C: addiu       $v1, $sp, 0x120
        ctx->r3 = ADD32(ctx->r29, 0X120);
            goto L_8003B908;
    }
    // 0x8003B88C: addiu       $v1, $sp, 0x120
    ctx->r3 = ADD32(ctx->r29, 0X120);
L_8003B890:
    // 0x8003B890: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8003B894: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003B898: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8003B89C: bne         $v0, $v1, L_8003B890
    if (ctx->r2 != ctx->r3) {
        // 0x8003B8A0: swc1        $f8, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
            goto L_8003B890;
    }
    // 0x8003B8A0: swc1        $f8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
    // 0x8003B8A4: lw          $t7, 0x30($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X30);
    // 0x8003B8A8: lwc1        $f10, 0x118($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X118);
    // 0x8003B8AC: addiu       $t9, $zero, 0x3F
    ctx->r25 = ADD32(0, 0X3F);
    // 0x8003B8B0: lh          $t8, 0x4($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X4);
    // 0x8003B8B4: addiu       $t0, $zero, 0xF
    ctx->r8 = ADD32(0, 0XF);
    // 0x8003B8B8: addiu       $t1, $zero, 0x3F
    ctx->r9 = ADD32(0, 0X3F);
    // 0x8003B8BC: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8003B8C0: sh          $t1, 0x108($sp)
    MEM_H(0X108, ctx->r29) = ctx->r9;
    // 0x8003B8C4: sh          $t0, 0x106($sp)
    MEM_H(0X106, ctx->r29) = ctx->r8;
    // 0x8003B8C8: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8003B8CC: sh          $t9, 0x104($sp)
    MEM_H(0X104, ctx->r29) = ctx->r25;
    // 0x8003B8D0: sh          $zero, 0x100($sp)
    MEM_H(0X100, ctx->r29) = 0;
    // 0x8003B8D4: sh          $zero, 0xFE($sp)
    MEM_H(0XFE, ctx->r29) = 0;
    // 0x8003B8D8: sh          $zero, 0xFC($sp)
    MEM_H(0XFC, ctx->r29) = 0;
    // 0x8003B8DC: addiu       $a0, $s7, 0x10
    ctx->r4 = ADD32(ctx->r23, 0X10);
    // 0x8003B8E0: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8003B8E4: addiu       $a1, $sp, 0x104
    ctx->r5 = ADD32(ctx->r29, 0X104);
    // 0x8003B8E8: addiu       $a2, $sp, 0xFC
    ctx->r6 = ADD32(ctx->r29, 0XFC);
    // 0x8003B8EC: addiu       $a3, $zero, 0x1A
    ctx->r7 = ADD32(0, 0X1A);
    // 0x8003B8F0: jal         0x80043DE8
    // 0x8003B8F4: swc1        $f4, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->f4.u32l;
    func_80043DE8(rdram, ctx);
        goto after_16;
    // 0x8003B8F4: swc1        $f4, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->f4.u32l;
    after_16:
    // 0x8003B8F8: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8003B8FC: b           L_8003B908
    // 0x8003B900: sh          $t3, 0x96($s7)
    MEM_H(0X96, ctx->r23) = ctx->r11;
        goto L_8003B908;
    // 0x8003B900: sh          $t3, 0x96($s7)
    MEM_H(0X96, ctx->r23) = ctx->r11;
    // 0x8003B904: sh          $t2, 0x90($s7)
    MEM_H(0X90, ctx->r23) = ctx->r10;
L_8003B908:
    // 0x8003B908: lh          $v1, 0x94($s7)
    ctx->r3 = MEM_H(ctx->r23, 0X94);
L_8003B90C:
    // 0x8003B90C: or          $v0, $s7, $zero
    ctx->r2 = ctx->r23 | 0;
    // 0x8003B910: beq         $v1, $zero, L_8003B91C
    if (ctx->r3 == 0) {
        // 0x8003B914: addiu       $t4, $v1, -0x1
        ctx->r12 = ADD32(ctx->r3, -0X1);
            goto L_8003B91C;
    }
    // 0x8003B914: addiu       $t4, $v1, -0x1
    ctx->r12 = ADD32(ctx->r3, -0X1);
    // 0x8003B918: sh          $t4, 0x94($s7)
    MEM_H(0X94, ctx->r23) = ctx->r12;
L_8003B91C:
    // 0x8003B91C: lh          $v1, 0x96($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X96);
    // 0x8003B920: beq         $v1, $zero, L_8003B92C
    if (ctx->r3 == 0) {
        // 0x8003B924: addiu       $t5, $v1, -0x1
        ctx->r13 = ADD32(ctx->r3, -0X1);
            goto L_8003B92C;
    }
    // 0x8003B924: addiu       $t5, $v1, -0x1
    ctx->r13 = ADD32(ctx->r3, -0X1);
    // 0x8003B928: sh          $t5, 0x96($v0)
    MEM_H(0X96, ctx->r2) = ctx->r13;
L_8003B92C:
    // 0x8003B92C: lh          $v1, 0x98($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X98);
    // 0x8003B930: beq         $v1, $zero, L_8003B93C
    if (ctx->r3 == 0) {
        // 0x8003B934: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_8003B93C;
    }
    // 0x8003B934: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8003B938: sh          $t6, 0x98($v0)
    MEM_H(0X98, ctx->r2) = ctx->r14;
L_8003B93C:
    // 0x8003B93C: lh          $v1, 0x9A($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X9A);
    // 0x8003B940: beq         $v1, $zero, L_8003B94C
    if (ctx->r3 == 0) {
        // 0x8003B944: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_8003B94C;
    }
    // 0x8003B944: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x8003B948: sh          $t7, 0x9A($v0)
    MEM_H(0X9A, ctx->r2) = ctx->r15;
L_8003B94C:
    // 0x8003B94C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8003B950: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8003B954: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8003B958: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8003B95C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8003B960: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8003B964: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8003B968: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8003B96C: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8003B970: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8003B974: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8003B978: jr          $ra
    // 0x8003B97C: addiu       $sp, $sp, 0x120
    ctx->r29 = ADD32(ctx->r29, 0X120);
    TRACE_RETURN()
    return;
    // 0x8003B97C: addiu       $sp, $sp, 0x120
    ctx->r29 = ADD32(ctx->r29, 0X120);
;}
RECOMP_FUNC void func_8003B980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8003B980: addiu       $sp, $sp, -0x128
    ctx->r29 = ADD32(ctx->r29, -0X128);
    // 0x8003B984: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8003B988: lh          $t6, -0x6B80($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X6B80);
    // 0x8003B98C: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8003B990: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8003B994: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x8003B998: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8003B99C: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8003B9A0: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8003B9A4: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8003B9A8: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8003B9AC: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8003B9B0: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8003B9B4: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8003B9B8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8003B9BC: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8003B9C0: bne         $v1, $t6, L_8003B9CC
    if (ctx->r3 != ctx->r14) {
        // 0x8003B9C4: sdc1        $f20, 0x20($sp)
        CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
            goto L_8003B9CC;
    }
    // 0x8003B9C4: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8003B9C8: sh          $v1, 0x90($a0)
    MEM_H(0X90, ctx->r4) = ctx->r3;
L_8003B9CC:
    // 0x8003B9CC: lh          $v0, 0x90($s6)
    ctx->r2 = MEM_H(ctx->r22, 0X90);
    // 0x8003B9D0: lui         $s2, 0x8007
    ctx->r18 = S32(0X8007 << 16);
    // 0x8003B9D4: addiu       $s2, $s2, -0x5BC0
    ctx->r18 = ADD32(ctx->r18, -0X5BC0);
    // 0x8003B9D8: beq         $v0, $zero, L_8003B9FC
    if (ctx->r2 == 0) {
        // 0x8003B9DC: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8003B9FC;
    }
    // 0x8003B9DC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8003B9E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8003B9E4: beql        $v0, $a0, L_8003BB68
    if (ctx->r2 == ctx->r4) {
        // 0x8003B9E8: lh          $t2, 0xA2($s6)
        ctx->r10 = MEM_H(ctx->r22, 0XA2);
            goto L_8003BB68;
    }
    goto skip_0;
    // 0x8003B9E8: lh          $t2, 0xA2($s6)
    ctx->r10 = MEM_H(ctx->r22, 0XA2);
    skip_0:
    // 0x8003B9EC: beql        $v0, $v1, L_8003BB80
    if (ctx->r2 == ctx->r3) {
        // 0x8003B9F0: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8003BB80;
    }
    goto skip_1;
    // 0x8003B9F0: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_1:
    // 0x8003B9F4: b           L_8003BB80
    // 0x8003B9F8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_8003BB80;
    // 0x8003B9F8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8003B9FC:
    // 0x8003B9FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003BA00: lui         $s7, 0x8007
    ctx->r23 = S32(0X8007 << 16);
    // 0x8003BA04: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x8003BA08: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8003BA0C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8003BA10: addiu       $s5, $s5, -0x659C
    ctx->r21 = ADD32(ctx->r21, -0X659C);
    // 0x8003BA14: addiu       $s7, $s7, -0x5BB0
    ctx->r23 = ADD32(ctx->r23, -0X5BB0);
    // 0x8003BA18: addiu       $fp, $sp, 0xC0
    ctx->r30 = ADD32(ctx->r29, 0XC0);
    // 0x8003BA1C: addiu       $s1, $sp, 0xCC
    ctx->r17 = ADD32(ctx->r29, 0XCC);
L_8003BA20:
    // 0x8003BA20: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8003BA24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003BA28: jal         0x8003DE20
    // 0x8003BA2C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    func_8003DE20(rdram, ctx);
        goto after_0;
    // 0x8003BA2C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_0:
    // 0x8003BA30: beq         $v0, $zero, L_8003BB40
    if (ctx->r2 == 0) {
        // 0x8003BA34: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8003BB40;
    }
    // 0x8003BA34: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8003BA38: lh          $t7, 0x8($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X8);
    // 0x8003BA3C: lh          $t8, 0xA($s2)
    ctx->r24 = MEM_H(ctx->r18, 0XA);
    // 0x8003BA40: lh          $t9, 0xC($s2)
    ctx->r25 = MEM_H(ctx->r18, 0XC);
    // 0x8003BA44: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8003BA48: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8003BA4C: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8003BA50: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003BA54: sll         $t0, $s3, 3
    ctx->r8 = S32(ctx->r19 << 3);
    // 0x8003BA58: subu        $t0, $t0, $s3
    ctx->r8 = SUB32(ctx->r8, ctx->r19);
    // 0x8003BA5C: lui         $t1, 0x8007
    ctx->r9 = S32(0X8007 << 16);
    // 0x8003BA60: sll         $t2, $s3, 2
    ctx->r10 = S32(ctx->r19 << 2);
    // 0x8003BA64: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8003BA68: addu        $t3, $s6, $t2
    ctx->r11 = ADD32(ctx->r22, ctx->r10);
    // 0x8003BA6C: addiu       $t1, $t1, -0x5BC0
    ctx->r9 = ADD32(ctx->r9, -0X5BC0);
    // 0x8003BA70: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8003BA74: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8003BA78: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8003BA7C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8003BA80: addu        $s4, $t0, $t1
    ctx->r20 = ADD32(ctx->r8, ctx->r9);
    // 0x8003BA84: sw          $t3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r11;
    // 0x8003BA88: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8003BA8C: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8003BA90: jal         0x80001A6C
    // 0x8003BA94: nop

    func_80001A6C(rdram, ctx);
        goto after_1;
    // 0x8003BA94: nop

    after_1:
    // 0x8003BA98: lw          $a1, 0x20($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X20);
    // 0x8003BA9C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8003BAA0: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8003BAA4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8003BAA8: jal         0x80049840
    // 0x8003BAAC: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    func_80049840(rdram, ctx);
        goto after_2;
    // 0x8003BAAC: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    after_2:
    // 0x8003BAB0: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8003BAB4: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x8003BAB8: jal         0x80000BD8
    // 0x8003BABC: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
    func_80000BD8(rdram, ctx);
        goto after_3;
    // 0x8003BABC: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
    after_3:
    // 0x8003BAC0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8003BAC4: addiu       $v1, $sp, 0xC0
    ctx->r3 = ADD32(ctx->r29, 0XC0);
    // 0x8003BAC8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8003BACC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
L_8003BAD0:
    // 0x8003BAD0: lwc1        $f10, 0x30($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X30);
    // 0x8003BAD4: lwc1        $f16, 0x10($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8003BAD8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003BADC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003BAE0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8003BAE4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8003BAE8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8003BAEC: swc1        $f18, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f18.u32l;
    // 0x8003BAF0: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8003BAF4: lwc1        $f4, 0xC($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8003BAF8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003BAFC: bne         $v1, $s1, L_8003BAD0
    if (ctx->r3 != ctx->r17) {
        // 0x8003BB00: swc1        $f8, 0x18($v0)
        MEM_W(0X18, ctx->r2) = ctx->f8.u32l;
            goto L_8003BAD0;
    }
    // 0x8003BB00: swc1        $f8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f8.u32l;
    // 0x8003BB04: lw          $t4, 0x80($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X80);
    // 0x8003BB08: sw          $t4, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->r12;
    // 0x8003BB0C: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x8003BB10: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x8003BB14: sw          $s0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r16;
    // 0x8003BB18: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x8003BB1C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8003BB20: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x8003BB24: lw          $t9, 0x0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X0);
    // 0x8003BB28: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8003BB2C: lw          $t0, 0x0($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X0);
    // 0x8003BB30: sw          $s0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r16;
    // 0x8003BB34: sw          $s6, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->r22;
    // 0x8003BB38: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8003BB3C: sw          $s0, 0xBC($t1)
    MEM_W(0XBC, ctx->r9) = ctx->r16;
L_8003BB40:
    // 0x8003BB40: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8003BB44: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8003BB48: addiu       $s2, $s2, 0x1C
    ctx->r18 = ADD32(ctx->r18, 0X1C);
    // 0x8003BB4C: bne         $s3, $v0, L_8003BA20
    if (ctx->r19 != ctx->r2) {
        // 0x8003BB50: addiu       $s7, $s7, 0x1C
        ctx->r23 = ADD32(ctx->r23, 0X1C);
            goto L_8003BA20;
    }
    // 0x8003BB50: addiu       $s7, $s7, 0x1C
    ctx->r23 = ADD32(ctx->r23, 0X1C);
    // 0x8003BB54: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8003BB58: sh          $v0, 0xA2($s6)
    MEM_H(0XA2, ctx->r22) = ctx->r2;
    // 0x8003BB5C: sh          $a0, 0x90($s6)
    MEM_H(0X90, ctx->r22) = ctx->r4;
    // 0x8003BB60: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8003BB64: lh          $t2, 0xA2($s6)
    ctx->r10 = MEM_H(ctx->r22, 0XA2);
L_8003BB68:
    // 0x8003BB68: bnel        $t2, $zero, L_8003BB80
    if (ctx->r10 != 0) {
        // 0x8003BB6C: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8003BB80;
    }
    goto skip_2;
    // 0x8003BB6C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_2:
    // 0x8003BB70: lw          $t3, 0xB8($s6)
    ctx->r11 = MEM_W(ctx->r22, 0XB8);
    // 0x8003BB74: sh          $a0, 0x14($t3)
    MEM_H(0X14, ctx->r11) = ctx->r4;
    // 0x8003BB78: sh          $v1, 0x90($s6)
    MEM_H(0X90, ctx->r22) = ctx->r3;
    // 0x8003BB7C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8003BB80:
    // 0x8003BB80: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8003BB84: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8003BB88: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8003BB8C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8003BB90: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8003BB94: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8003BB98: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8003BB9C: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8003BBA0: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8003BBA4: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8003BBA8: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8003BBAC: jr          $ra
    // 0x8003BBB0: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
    TRACE_RETURN()
    return;
    // 0x8003BBB0: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
;}
RECOMP_FUNC void func_8003BBB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8003BBB4: addiu       $sp, $sp, -0x118
    ctx->r29 = ADD32(ctx->r29, -0X118);
    // 0x8003BBB8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8003BBBC: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8003BBC0: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8003BBC4: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8003BBC8: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8003BBCC: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8003BBD0: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8003BBD4: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8003BBD8: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8003BBDC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8003BBE0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8003BBE4: lhu         $t6, 0x90($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X90);
    // 0x8003BBE8: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x8003BBEC: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x8003BBF0: beq         $at, $zero, L_8003C05C
    if (ctx->r1 == 0) {
        // 0x8003BBF4: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8003C05C;
    }
    // 0x8003BBF4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8003BBF8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003BBFC: addu        $at, $at, $t6
    gpr jr_addend_8003BC04 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8003BC00: lw          $t6, 0x7478($at)
    ctx->r14 = ADD32(ctx->r1, 0X7478);
    // 0x8003BC04: jr          $t6
    // 0x8003BC08: nop

    switch (jr_addend_8003BC04 >> 2) {
        case 0: goto L_8003BC0C; break;
        case 1: goto L_8003BD60; break;
        case 2: goto L_8003BD80; break;
        case 3: goto L_8003BE44; break;
        case 4: goto L_8003C05C; break;
        default: switch_error(__func__, 0x8003BC04, 0x80077478);
    }
    // 0x8003BC08: nop

L_8003BC0C:
    // 0x8003BC0C: lui         $s3, 0x8007
    ctx->r19 = S32(0X8007 << 16);
    // 0x8003BC10: lui         $s6, 0x8007
    ctx->r22 = S32(0X8007 << 16);
    // 0x8003BC14: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x8003BC18: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8003BC1C: addiu       $s5, $s5, -0x659C
    ctx->r21 = ADD32(ctx->r21, -0X659C);
    // 0x8003BC20: addiu       $s6, $s6, -0x5B40
    ctx->r22 = ADD32(ctx->r22, -0X5B40);
    // 0x8003BC24: addiu       $s3, $s3, -0x5B50
    ctx->r19 = ADD32(ctx->r19, -0X5B50);
    // 0x8003BC28: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8003BC2C: addiu       $s7, $sp, 0xB0
    ctx->r23 = ADD32(ctx->r29, 0XB0);
    // 0x8003BC30: addiu       $s1, $sp, 0xBC
    ctx->r17 = ADD32(ctx->r29, 0XBC);
L_8003BC34:
    // 0x8003BC34: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8003BC38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003BC3C: jal         0x8003DE20
    // 0x8003BC40: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_8003DE20(rdram, ctx);
        goto after_0;
    // 0x8003BC40: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_0:
    // 0x8003BC44: beq         $v0, $zero, L_8003BD40
    if (ctx->r2 == 0) {
        // 0x8003BC48: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8003BD40;
    }
    // 0x8003BC48: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8003BC4C: lh          $t7, 0x8($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X8);
    // 0x8003BC50: lh          $t8, 0xA($s3)
    ctx->r24 = MEM_H(ctx->r19, 0XA);
    // 0x8003BC54: lh          $t9, 0xC($s3)
    ctx->r25 = MEM_H(ctx->r19, 0XC);
    // 0x8003BC58: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8003BC5C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8003BC60: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8003BC64: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003BC68: sll         $t0, $s2, 3
    ctx->r8 = S32(ctx->r18 << 3);
    // 0x8003BC6C: subu        $t0, $t0, $s2
    ctx->r8 = SUB32(ctx->r8, ctx->r18);
    // 0x8003BC70: lui         $t1, 0x8007
    ctx->r9 = S32(0X8007 << 16);
    // 0x8003BC74: addiu       $t1, $t1, -0x5B50
    ctx->r9 = ADD32(ctx->r9, -0X5B50);
    // 0x8003BC78: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8003BC7C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8003BC80: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8003BC84: addu        $s4, $t0, $t1
    ctx->r20 = ADD32(ctx->r8, ctx->r9);
    // 0x8003BC88: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8003BC8C: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8003BC90: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8003BC94: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8003BC98: jal         0x80001A6C
    // 0x8003BC9C: nop

    func_80001A6C(rdram, ctx);
        goto after_1;
    // 0x8003BC9C: nop

    after_1:
    // 0x8003BCA0: lw          $a1, 0x20($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X20);
    // 0x8003BCA4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8003BCA8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8003BCAC: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x8003BCB0: jal         0x80049840
    // 0x8003BCB4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_80049840(rdram, ctx);
        goto after_2;
    // 0x8003BCB4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x8003BCB8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8003BCBC: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x8003BCC0: jal         0x80000BD8
    // 0x8003BCC4: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    func_80000BD8(rdram, ctx);
        goto after_3;
    // 0x8003BCC4: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    after_3:
    // 0x8003BCC8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8003BCCC: addiu       $v1, $sp, 0xB0
    ctx->r3 = ADD32(ctx->r29, 0XB0);
    // 0x8003BCD0: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8003BCD4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
L_8003BCD8:
    // 0x8003BCD8: lwc1        $f10, 0x30($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X30);
    // 0x8003BCDC: lwc1        $f16, 0x10($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8003BCE0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003BCE4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003BCE8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8003BCEC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8003BCF0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8003BCF4: swc1        $f18, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f18.u32l;
    // 0x8003BCF8: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8003BCFC: lwc1        $f4, 0xC($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8003BD00: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003BD04: bne         $v1, $s1, L_8003BCD8
    if (ctx->r3 != ctx->r17) {
        // 0x8003BD08: swc1        $f8, 0x18($v0)
        MEM_W(0X18, ctx->r2) = ctx->f8.u32l;
            goto L_8003BCD8;
    }
    // 0x8003BD08: swc1        $f8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f8.u32l;
    // 0x8003BD0C: lw          $t2, 0x80($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X80);
    // 0x8003BD10: sw          $t2, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->r10;
    // 0x8003BD14: lw          $t3, 0x0($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X0);
    // 0x8003BD18: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x8003BD1C: sw          $s0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r16;
    // 0x8003BD20: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x8003BD24: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x8003BD28: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x8003BD2C: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x8003BD30: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8003BD34: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    // 0x8003BD38: sw          $s0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r16;
    // 0x8003BD3C: sw          $fp, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->r30;
L_8003BD40:
    // 0x8003BD40: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8003BD44: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8003BD48: addiu       $s3, $s3, 0x1C
    ctx->r19 = ADD32(ctx->r19, 0X1C);
    // 0x8003BD4C: bne         $s2, $v0, L_8003BC34
    if (ctx->r18 != ctx->r2) {
        // 0x8003BD50: addiu       $s6, $s6, 0x1C
        ctx->r22 = ADD32(ctx->r22, 0X1C);
            goto L_8003BC34;
    }
    // 0x8003BD50: addiu       $s6, $s6, 0x1C
    ctx->r22 = ADD32(ctx->r22, 0X1C);
    // 0x8003BD54: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8003BD58: sh          $v0, 0xA2($fp)
    MEM_H(0XA2, ctx->r30) = ctx->r2;
    // 0x8003BD5C: sh          $t9, 0x90($fp)
    MEM_H(0X90, ctx->r30) = ctx->r25;
L_8003BD60:
    // 0x8003BD60: lh          $t0, 0xA2($fp)
    ctx->r8 = MEM_H(ctx->r30, 0XA2);
    // 0x8003BD64: addiu       $t1, $zero, 0x12C
    ctx->r9 = ADD32(0, 0X12C);
    // 0x8003BD68: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8003BD6C: bnel        $t0, $zero, L_8003C060
    if (ctx->r8 != 0) {
        // 0x8003BD70: lh          $v1, 0x94($fp)
        ctx->r3 = MEM_H(ctx->r30, 0X94);
            goto L_8003C060;
    }
    goto skip_0;
    // 0x8003BD70: lh          $v1, 0x94($fp)
    ctx->r3 = MEM_H(ctx->r30, 0X94);
    skip_0:
    // 0x8003BD74: sh          $t1, 0x36($fp)
    MEM_H(0X36, ctx->r30) = ctx->r9;
    // 0x8003BD78: b           L_8003C05C
    // 0x8003BD7C: sh          $t2, 0x90($fp)
    MEM_H(0X90, ctx->r30) = ctx->r10;
        goto L_8003C05C;
    // 0x8003BD7C: sh          $t2, 0x90($fp)
    MEM_H(0X90, ctx->r30) = ctx->r10;
L_8003BD80:
    // 0x8003BD80: lh          $t3, 0x36($fp)
    ctx->r11 = MEM_H(ctx->r30, 0X36);
    // 0x8003BD84: bgtzl       $t3, L_8003C060
    if (SIGNED(ctx->r11) > 0) {
        // 0x8003BD88: lh          $v1, 0x94($fp)
        ctx->r3 = MEM_H(ctx->r30, 0X94);
            goto L_8003C060;
    }
    goto skip_1;
    // 0x8003BD88: lh          $v1, 0x94($fp)
    ctx->r3 = MEM_H(ctx->r30, 0X94);
    skip_1:
    // 0x8003BD8C: jal         0x8003A4E8
    // 0x8003BD90: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    func_8003A4E8(rdram, ctx);
        goto after_4;
    // 0x8003BD90: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_4:
    // 0x8003BD94: addiu       $v0, $sp, 0x10C
    ctx->r2 = ADD32(ctx->r29, 0X10C);
    // 0x8003BD98: or          $v1, $fp, $zero
    ctx->r3 = ctx->r30 | 0;
    // 0x8003BD9C: addiu       $a0, $sp, 0x118
    ctx->r4 = ADD32(ctx->r29, 0X118);
L_8003BDA0:
    // 0x8003BDA0: lwc1        $f10, 0x10($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8003BDA4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003BDA8: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x8003BDAC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003BDB0: bne         $at, $zero, L_8003BDA0
    if (ctx->r1 != 0) {
        // 0x8003BDB4: swc1        $f10, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
            goto L_8003BDA0;
    }
    // 0x8003BDB4: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x8003BDB8: lw          $t4, 0x30($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X30);
    // 0x8003BDBC: lwc1        $f16, 0x110($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X110);
    // 0x8003BDC0: addiu       $s0, $sp, 0x10C
    ctx->r16 = ADD32(ctx->r29, 0X10C);
    // 0x8003BDC4: lh          $t5, 0x4($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X4);
    // 0x8003BDC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003BDCC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8003BDD0: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x8003BDD4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003BDD8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8003BDDC: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8003BDE0: jal         0x80042F80
    // 0x8003BDE4: swc1        $f6, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->f6.u32l;
    func_80042F80(rdram, ctx);
        goto after_5;
    // 0x8003BDE4: swc1        $f6, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x8003BDE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003BDEC: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x8003BDF0: jal         0x80042F80
    // 0x8003BDF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80042F80(rdram, ctx);
        goto after_6;
    // 0x8003BDF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x8003BDF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003BDFC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8003BE00: jal         0x80043714
    // 0x8003BE04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80043714(rdram, ctx);
        goto after_7;
    // 0x8003BE04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x8003BE08: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x8003BE0C: sh          $t6, 0x94($fp)
    MEM_H(0X94, ctx->r30) = ctx->r14;
    // 0x8003BE10: addiu       $a0, $fp, 0x44
    ctx->r4 = ADD32(ctx->r30, 0X44);
    // 0x8003BE14: jal         0x8000DD44
    // 0x8003BE18: addiu       $a1, $fp, 0x10
    ctx->r5 = ADD32(ctx->r30, 0X10);
    func_8000DD44(rdram, ctx);
        goto after_8;
    // 0x8003BE18: addiu       $a1, $fp, 0x10
    ctx->r5 = ADD32(ctx->r30, 0X10);
    after_8:
    // 0x8003BE1C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8003BE20: or          $v1, $fp, $zero
    ctx->r3 = ctx->r30 | 0;
    // 0x8003BE24: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8003BE28:
    // 0x8003BE28: lwc1        $f8, 0x44($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X44);
    // 0x8003BE2C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8003BE30: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003BE34: bne         $s2, $v0, L_8003BE28
    if (ctx->r18 != ctx->r2) {
        // 0x8003BE38: swc1        $f8, 0x40($v1)
        MEM_W(0X40, ctx->r3) = ctx->f8.u32l;
            goto L_8003BE28;
    }
    // 0x8003BE38: swc1        $f8, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f8.u32l;
    // 0x8003BE3C: b           L_8003C05C
    // 0x8003BE40: sh          $v0, 0x90($fp)
    MEM_H(0X90, ctx->r30) = ctx->r2;
        goto L_8003C05C;
    // 0x8003BE40: sh          $v0, 0x90($fp)
    MEM_H(0X90, ctx->r30) = ctx->r2;
L_8003BE44:
    // 0x8003BE44: lh          $t7, 0x94($fp)
    ctx->r15 = MEM_H(ctx->r30, 0X94);
    // 0x8003BE48: beq         $t7, $zero, L_8003BED4
    if (ctx->r15 == 0) {
        // 0x8003BE4C: nop
    
            goto L_8003BED4;
    }
    // 0x8003BE4C: nop

    // 0x8003BE50: lh          $t8, 0x96($fp)
    ctx->r24 = MEM_H(ctx->r30, 0X96);
    // 0x8003BE54: addiu       $v0, $sp, 0x10C
    ctx->r2 = ADD32(ctx->r29, 0X10C);
    // 0x8003BE58: or          $v1, $fp, $zero
    ctx->r3 = ctx->r30 | 0;
    // 0x8003BE5C: bne         $t8, $zero, L_8003BED4
    if (ctx->r24 != 0) {
        // 0x8003BE60: addiu       $a0, $sp, 0x118
        ctx->r4 = ADD32(ctx->r29, 0X118);
            goto L_8003BED4;
    }
    // 0x8003BE60: addiu       $a0, $sp, 0x118
    ctx->r4 = ADD32(ctx->r29, 0X118);
L_8003BE64:
    // 0x8003BE64: lwc1        $f10, 0x10($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8003BE68: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003BE6C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003BE70: bne         $v0, $a0, L_8003BE64
    if (ctx->r2 != ctx->r4) {
        // 0x8003BE74: swc1        $f10, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
            goto L_8003BE64;
    }
    // 0x8003BE74: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x8003BE78: lw          $t9, 0x30($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X30);
    // 0x8003BE7C: lwc1        $f18, 0x110($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X110);
    // 0x8003BE80: addiu       $t1, $zero, 0x3F
    ctx->r9 = ADD32(0, 0X3F);
    // 0x8003BE84: lh          $t0, 0x4($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X4);
    // 0x8003BE88: addiu       $t2, $zero, 0xF
    ctx->r10 = ADD32(0, 0XF);
    // 0x8003BE8C: addiu       $t3, $zero, 0x3F
    ctx->r11 = ADD32(0, 0X3F);
    // 0x8003BE90: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x8003BE94: sh          $t3, 0x100($sp)
    MEM_H(0X100, ctx->r29) = ctx->r11;
    // 0x8003BE98: sh          $t2, 0xFE($sp)
    MEM_H(0XFE, ctx->r29) = ctx->r10;
    // 0x8003BE9C: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003BEA0: sh          $t1, 0xFC($sp)
    MEM_H(0XFC, ctx->r29) = ctx->r9;
    // 0x8003BEA4: sh          $zero, 0xF8($sp)
    MEM_H(0XF8, ctx->r29) = 0;
    // 0x8003BEA8: sh          $zero, 0xF6($sp)
    MEM_H(0XF6, ctx->r29) = 0;
    // 0x8003BEAC: sh          $zero, 0xF4($sp)
    MEM_H(0XF4, ctx->r29) = 0;
    // 0x8003BEB0: addiu       $a0, $fp, 0x10
    ctx->r4 = ADD32(ctx->r30, 0X10);
    // 0x8003BEB4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8003BEB8: addiu       $a1, $sp, 0xFC
    ctx->r5 = ADD32(ctx->r29, 0XFC);
    // 0x8003BEBC: addiu       $a2, $sp, 0xF4
    ctx->r6 = ADD32(ctx->r29, 0XF4);
    // 0x8003BEC0: addiu       $a3, $zero, 0x1A
    ctx->r7 = ADD32(0, 0X1A);
    // 0x8003BEC4: jal         0x80043DE8
    // 0x8003BEC8: swc1        $f6, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->f6.u32l;
    func_80043DE8(rdram, ctx);
        goto after_9;
    // 0x8003BEC8: swc1        $f6, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->f6.u32l;
    after_9:
    // 0x8003BECC: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8003BED0: sh          $t4, 0x96($fp)
    MEM_H(0X96, ctx->r30) = ctx->r12;
L_8003BED4:
    // 0x8003BED4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003BED8: lwc1        $f0, 0x748C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X748C);
    // 0x8003BEDC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8003BEE0: or          $v1, $fp, $zero
    ctx->r3 = ctx->r30 | 0;
    // 0x8003BEE4: addiu       $s1, $fp, 0x10
    ctx->r17 = ADD32(ctx->r30, 0X10);
L_8003BEE8:
    // 0x8003BEE8: lwc1        $f8, 0x10($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8003BEEC: lwc1        $f10, 0x44($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X44);
    // 0x8003BEF0: lwc1        $f18, 0x1C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x8003BEF4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8003BEF8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8003BEFC: slti        $at, $s2, 0x3
    ctx->r1 = SIGNED(ctx->r18) < 0X3 ? 1 : 0;
    // 0x8003BF00: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003BF04: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x8003BF08: swc1        $f16, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f16.u32l;
    // 0x8003BF0C: bne         $at, $zero, L_8003BEE8
    if (ctx->r1 != 0) {
        // 0x8003BF10: swc1        $f4, 0x18($v1)
        MEM_W(0X18, ctx->r3) = ctx->f4.u32l;
            goto L_8003BEE8;
    }
    // 0x8003BF10: swc1        $f4, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f4.u32l;
    // 0x8003BF14: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003BF18: lwc1        $f8, 0x7490($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7490);
    // 0x8003BF1C: lwc1        $f6, 0x48($fp)
    ctx->f6.u32l = MEM_W(ctx->r30, 0X48);
    // 0x8003BF20: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8003BF24: addiu       $s7, $sp, 0xB0
    ctx->r23 = ADD32(ctx->r29, 0XB0);
    // 0x8003BF28: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8003BF2C: lw          $a1, 0x1C($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X1C);
    // 0x8003BF30: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8003BF34: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8003BF38: swc1        $f10, 0x48($fp)
    MEM_W(0X48, ctx->r30) = ctx->f10.u32l;
    // 0x8003BF3C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8003BF40: jal         0x80049840
    // 0x8003BF44: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    func_80049840(rdram, ctx);
        goto after_10;
    // 0x8003BF44: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_10:
    // 0x8003BF48: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003BF4C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003BF50: lw          $a1, 0x24($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X24);
    // 0x8003BF54: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8003BF58: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8003BF5C: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x8003BF60: jal         0x80049840
    // 0x8003BF64: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_80049840(rdram, ctx);
        goto after_11;
    // 0x8003BF64: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_11:
    // 0x8003BF68: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8003BF6C: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x8003BF70: jal         0x80000BD8
    // 0x8003BF74: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    func_80000BD8(rdram, ctx);
        goto after_12;
    // 0x8003BF74: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    after_12:
    // 0x8003BF78: lw          $a1, 0x20($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X20);
    // 0x8003BF7C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8003BF80: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8003BF84: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x8003BF88: jal         0x80049840
    // 0x8003BF8C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_80049840(rdram, ctx);
        goto after_13;
    // 0x8003BF8C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_13:
    // 0x8003BF90: lw          $t5, 0xC($fp)
    ctx->r13 = MEM_W(ctx->r30, 0XC);
    // 0x8003BF94: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x8003BF98: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x8003BF9C: lw          $a0, 0x8($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X8);
    // 0x8003BFA0: jal         0x80000BD8
    // 0x8003BFA4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80000BD8(rdram, ctx);
        goto after_14;
    // 0x8003BFA4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_14:
    // 0x8003BFA8: lwc1        $f0, 0x2C($fp)
    ctx->f0.u32l = MEM_W(ctx->r30, 0X2C);
    // 0x8003BFAC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8003BFB0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003BFB4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003BFB8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003BFBC: jal         0x80001AB4
    // 0x8003BFC0: nop

    func_80001AB4(rdram, ctx);
        goto after_15;
    // 0x8003BFC0: nop

    after_15:
    // 0x8003BFC4: lw          $t6, 0xC($fp)
    ctx->r14 = MEM_W(ctx->r30, 0XC);
    // 0x8003BFC8: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x8003BFCC: lw          $a0, 0x8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X8);
    // 0x8003BFD0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8003BFD4: jal         0x80000BD8
    // 0x8003BFD8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_80000BD8(rdram, ctx);
        goto after_16;
    // 0x8003BFD8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_16:
    // 0x8003BFDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003BFE0: or          $v1, $fp, $zero
    ctx->r3 = ctx->r30 | 0;
    // 0x8003BFE4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
L_8003BFE8:
    // 0x8003BFE8: lw          $t7, 0xC($fp)
    ctx->r15 = MEM_W(ctx->r30, 0XC);
    // 0x8003BFEC: lwc1        $f18, 0x10($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8003BFF0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003BFF4: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x8003BFF8: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8003BFFC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003C000: bne         $v0, $a0, L_8003BFE8
    if (ctx->r2 != ctx->r4) {
        // 0x8003C004: swc1        $f18, 0x40($t9)
        MEM_W(0X40, ctx->r25) = ctx->f18.u32l;
            goto L_8003BFE8;
    }
    // 0x8003C004: swc1        $f18, 0x40($t9)
    MEM_W(0X40, ctx->r25) = ctx->f18.u32l;
    // 0x8003C008: addiu       $s0, $sp, 0x10C
    ctx->r16 = ADD32(ctx->r29, 0X10C);
    // 0x8003C00C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003C010: jal         0x8000D3A4
    // 0x8003C014: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8000D3A4(rdram, ctx);
        goto after_17;
    // 0x8003C014: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_17:
    // 0x8003C018: beq         $v0, $zero, L_8003C05C
    if (ctx->r2 == 0) {
        // 0x8003C01C: lwc1        $f4, 0x110($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X110);
            goto L_8003C05C;
    }
    // 0x8003C01C: lwc1        $f4, 0x110($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X110);
    // 0x8003C020: lwc1        $f6, 0x14($fp)
    ctx->f6.u32l = MEM_W(ctx->r30, 0X14);
    // 0x8003C024: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8003C028: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8003C02C: nop

    // 0x8003C030: bc1fl       L_8003C060
    if (!c1cs) {
        // 0x8003C034: lh          $v1, 0x94($fp)
        ctx->r3 = MEM_H(ctx->r30, 0X94);
            goto L_8003C060;
    }
    goto skip_2;
    // 0x8003C034: lh          $v1, 0x94($fp)
    ctx->r3 = MEM_H(ctx->r30, 0X94);
    skip_2:
    // 0x8003C038: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003C03C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003C040: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8003C044: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8003C048: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003C04C: jal         0x80042F80
    // 0x8003C050: swc1        $f10, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->f10.u32l;
    func_80042F80(rdram, ctx);
        goto after_18;
    // 0x8003C050: swc1        $f10, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->f10.u32l;
    after_18:
    // 0x8003C054: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8003C058: sh          $t0, 0x90($fp)
    MEM_H(0X90, ctx->r30) = ctx->r8;
L_8003C05C:
    // 0x8003C05C: lh          $v1, 0x94($fp)
    ctx->r3 = MEM_H(ctx->r30, 0X94);
L_8003C060:
    // 0x8003C060: or          $v0, $fp, $zero
    ctx->r2 = ctx->r30 | 0;
    // 0x8003C064: beq         $v1, $zero, L_8003C070
    if (ctx->r3 == 0) {
        // 0x8003C068: addiu       $t1, $v1, -0x1
        ctx->r9 = ADD32(ctx->r3, -0X1);
            goto L_8003C070;
    }
    // 0x8003C068: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
    // 0x8003C06C: sh          $t1, 0x94($fp)
    MEM_H(0X94, ctx->r30) = ctx->r9;
L_8003C070:
    // 0x8003C070: lh          $v1, 0x96($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X96);
    // 0x8003C074: beq         $v1, $zero, L_8003C080
    if (ctx->r3 == 0) {
        // 0x8003C078: addiu       $t2, $v1, -0x1
        ctx->r10 = ADD32(ctx->r3, -0X1);
            goto L_8003C080;
    }
    // 0x8003C078: addiu       $t2, $v1, -0x1
    ctx->r10 = ADD32(ctx->r3, -0X1);
    // 0x8003C07C: sh          $t2, 0x96($v0)
    MEM_H(0X96, ctx->r2) = ctx->r10;
L_8003C080:
    // 0x8003C080: lh          $v1, 0x98($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X98);
    // 0x8003C084: beq         $v1, $zero, L_8003C090
    if (ctx->r3 == 0) {
        // 0x8003C088: addiu       $t3, $v1, -0x1
        ctx->r11 = ADD32(ctx->r3, -0X1);
            goto L_8003C090;
    }
    // 0x8003C088: addiu       $t3, $v1, -0x1
    ctx->r11 = ADD32(ctx->r3, -0X1);
    // 0x8003C08C: sh          $t3, 0x98($v0)
    MEM_H(0X98, ctx->r2) = ctx->r11;
L_8003C090:
    // 0x8003C090: lh          $v1, 0x9A($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X9A);
    // 0x8003C094: beq         $v1, $zero, L_8003C0A0
    if (ctx->r3 == 0) {
        // 0x8003C098: addiu       $t4, $v1, -0x1
        ctx->r12 = ADD32(ctx->r3, -0X1);
            goto L_8003C0A0;
    }
    // 0x8003C098: addiu       $t4, $v1, -0x1
    ctx->r12 = ADD32(ctx->r3, -0X1);
    // 0x8003C09C: sh          $t4, 0x9A($v0)
    MEM_H(0X9A, ctx->r2) = ctx->r12;
L_8003C0A0:
    // 0x8003C0A0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8003C0A4: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8003C0A8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8003C0AC: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8003C0B0: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8003C0B4: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8003C0B8: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8003C0BC: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8003C0C0: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8003C0C4: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8003C0C8: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8003C0CC: jr          $ra
    // 0x8003C0D0: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
    TRACE_RETURN()
    return;
    // 0x8003C0D0: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
;}
RECOMP_FUNC void func_8003C0D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8003C0D4: addiu       $sp, $sp, -0x118
    ctx->r29 = ADD32(ctx->r29, -0X118);
    // 0x8003C0D8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8003C0DC: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8003C0E0: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8003C0E4: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8003C0E8: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8003C0EC: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8003C0F0: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8003C0F4: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8003C0F8: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8003C0FC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8003C100: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8003C104: lh          $v0, 0x90($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X90);
    // 0x8003C108: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x8003C10C: lui         $s2, 0x8007
    ctx->r18 = S32(0X8007 << 16);
    // 0x8003C110: beq         $v0, $zero, L_8003C13C
    if (ctx->r2 == 0) {
        // 0x8003C114: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8003C13C;
    }
    // 0x8003C114: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8003C118: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003C11C: beq         $v0, $at, L_8003C288
    if (ctx->r2 == ctx->r1) {
        // 0x8003C120: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8003C288;
    }
    // 0x8003C120: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003C124: beq         $v0, $at, L_8003C338
    if (ctx->r2 == ctx->r1) {
        // 0x8003C128: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8003C338;
    }
    // 0x8003C128: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003C12C: beql        $v0, $at, L_8003C3D8
    if (ctx->r2 == ctx->r1) {
        // 0x8003C130: lh          $v1, 0x94($fp)
        ctx->r3 = MEM_H(ctx->r30, 0X94);
            goto L_8003C3D8;
    }
    goto skip_0;
    // 0x8003C130: lh          $v1, 0x94($fp)
    ctx->r3 = MEM_H(ctx->r30, 0X94);
    skip_0:
    // 0x8003C134: b           L_8003C3D8
    // 0x8003C138: lh          $v1, 0x94($fp)
    ctx->r3 = MEM_H(ctx->r30, 0X94);
        goto L_8003C3D8;
    // 0x8003C138: lh          $v1, 0x94($fp)
    ctx->r3 = MEM_H(ctx->r30, 0X94);
L_8003C13C:
    // 0x8003C13C: lui         $s6, 0x8007
    ctx->r22 = S32(0X8007 << 16);
    // 0x8003C140: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x8003C144: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8003C148: addiu       $s5, $s5, -0x659C
    ctx->r21 = ADD32(ctx->r21, -0X659C);
    // 0x8003C14C: addiu       $s6, $s6, -0x5AEC
    ctx->r22 = ADD32(ctx->r22, -0X5AEC);
    // 0x8003C150: addiu       $s2, $s2, -0x5AFC
    ctx->r18 = ADD32(ctx->r18, -0X5AFC);
    // 0x8003C154: addiu       $s7, $sp, 0xB0
    ctx->r23 = ADD32(ctx->r29, 0XB0);
    // 0x8003C158: addiu       $s1, $sp, 0xBC
    ctx->r17 = ADD32(ctx->r29, 0XBC);
L_8003C15C:
    // 0x8003C15C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8003C160: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003C164: jal         0x8003DE20
    // 0x8003C168: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_8003DE20(rdram, ctx);
        goto after_0;
    // 0x8003C168: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_0:
    // 0x8003C16C: beq         $v0, $zero, L_8003C268
    if (ctx->r2 == 0) {
        // 0x8003C170: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8003C268;
    }
    // 0x8003C170: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8003C174: lh          $t6, 0x8($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X8);
    // 0x8003C178: lh          $t7, 0xA($s2)
    ctx->r15 = MEM_H(ctx->r18, 0XA);
    // 0x8003C17C: lh          $t8, 0xC($s2)
    ctx->r24 = MEM_H(ctx->r18, 0XC);
    // 0x8003C180: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8003C184: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8003C188: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8003C18C: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003C190: sll         $t9, $s3, 3
    ctx->r25 = S32(ctx->r19 << 3);
    // 0x8003C194: subu        $t9, $t9, $s3
    ctx->r25 = SUB32(ctx->r25, ctx->r19);
    // 0x8003C198: lui         $t0, 0x8007
    ctx->r8 = S32(0X8007 << 16);
    // 0x8003C19C: addiu       $t0, $t0, -0x5AFC
    ctx->r8 = ADD32(ctx->r8, -0X5AFC);
    // 0x8003C1A0: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8003C1A4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8003C1A8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8003C1AC: addu        $s4, $t9, $t0
    ctx->r20 = ADD32(ctx->r25, ctx->r8);
    // 0x8003C1B0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8003C1B4: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8003C1B8: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8003C1BC: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8003C1C0: jal         0x80001A6C
    // 0x8003C1C4: nop

    func_80001A6C(rdram, ctx);
        goto after_1;
    // 0x8003C1C4: nop

    after_1:
    // 0x8003C1C8: lw          $a1, 0x20($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X20);
    // 0x8003C1CC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8003C1D0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8003C1D4: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x8003C1D8: jal         0x80049840
    // 0x8003C1DC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_80049840(rdram, ctx);
        goto after_2;
    // 0x8003C1DC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x8003C1E0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8003C1E4: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x8003C1E8: jal         0x80000BD8
    // 0x8003C1EC: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    func_80000BD8(rdram, ctx);
        goto after_3;
    // 0x8003C1EC: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    after_3:
    // 0x8003C1F0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8003C1F4: addiu       $v1, $sp, 0xB0
    ctx->r3 = ADD32(ctx->r29, 0XB0);
    // 0x8003C1F8: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8003C1FC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
L_8003C200:
    // 0x8003C200: lwc1        $f10, 0x30($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X30);
    // 0x8003C204: lwc1        $f16, 0x10($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8003C208: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003C20C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003C210: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8003C214: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8003C218: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8003C21C: swc1        $f18, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f18.u32l;
    // 0x8003C220: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8003C224: lwc1        $f4, 0xC($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8003C228: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003C22C: bne         $v1, $s1, L_8003C200
    if (ctx->r3 != ctx->r17) {
        // 0x8003C230: swc1        $f8, 0x18($v0)
        MEM_W(0X18, ctx->r2) = ctx->f8.u32l;
            goto L_8003C200;
    }
    // 0x8003C230: swc1        $f8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f8.u32l;
    // 0x8003C234: lw          $t1, 0x80($fp)
    ctx->r9 = MEM_W(ctx->r30, 0X80);
    // 0x8003C238: sw          $t1, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->r9;
    // 0x8003C23C: lw          $t2, 0x0($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X0);
    // 0x8003C240: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x8003C244: sw          $s0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r16;
    // 0x8003C248: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
    // 0x8003C24C: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x8003C250: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
    // 0x8003C254: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    // 0x8003C258: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8003C25C: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x8003C260: sw          $s0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r16;
    // 0x8003C264: sw          $fp, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->r30;
L_8003C268:
    // 0x8003C268: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8003C26C: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x8003C270: addiu       $s2, $s2, 0x1C
    ctx->r18 = ADD32(ctx->r18, 0X1C);
    // 0x8003C274: bne         $s3, $v0, L_8003C15C
    if (ctx->r19 != ctx->r2) {
        // 0x8003C278: addiu       $s6, $s6, 0x1C
        ctx->r22 = ADD32(ctx->r22, 0X1C);
            goto L_8003C15C;
    }
    // 0x8003C278: addiu       $s6, $s6, 0x1C
    ctx->r22 = ADD32(ctx->r22, 0X1C);
    // 0x8003C27C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8003C280: sh          $v0, 0xA2($fp)
    MEM_H(0XA2, ctx->r30) = ctx->r2;
    // 0x8003C284: sh          $t8, 0x90($fp)
    MEM_H(0X90, ctx->r30) = ctx->r24;
L_8003C288:
    // 0x8003C288: lh          $t9, 0x36($fp)
    ctx->r25 = MEM_H(ctx->r30, 0X36);
    // 0x8003C28C: bgtzl       $t9, L_8003C3D8
    if (SIGNED(ctx->r25) > 0) {
        // 0x8003C290: lh          $v1, 0x94($fp)
        ctx->r3 = MEM_H(ctx->r30, 0X94);
            goto L_8003C3D8;
    }
    goto skip_1;
    // 0x8003C290: lh          $v1, 0x94($fp)
    ctx->r3 = MEM_H(ctx->r30, 0X94);
    skip_1:
    // 0x8003C294: lw          $t0, 0xC($fp)
    ctx->r8 = MEM_W(ctx->r30, 0XC);
    // 0x8003C298: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8003C29C: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x8003C2A0: lw          $v0, 0xE0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0XE0);
    // 0x8003C2A4: lbu         $t2, 0x10($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X10);
    // 0x8003C2A8: ori         $t3, $t2, 0x4
    ctx->r11 = ctx->r10 | 0X4;
    // 0x8003C2AC: jal         0x8003A4E8
    // 0x8003C2B0: sb          $t3, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r11;
    func_8003A4E8(rdram, ctx);
        goto after_4;
    // 0x8003C2B0: sb          $t3, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r11;
    after_4:
    // 0x8003C2B4: addiu       $v0, $sp, 0x10C
    ctx->r2 = ADD32(ctx->r29, 0X10C);
    // 0x8003C2B8: or          $v1, $fp, $zero
    ctx->r3 = ctx->r30 | 0;
    // 0x8003C2BC: addiu       $a0, $sp, 0x118
    ctx->r4 = ADD32(ctx->r29, 0X118);
L_8003C2C0:
    // 0x8003C2C0: lwc1        $f10, 0x10($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8003C2C4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003C2C8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003C2CC: bne         $v0, $a0, L_8003C2C0
    if (ctx->r2 != ctx->r4) {
        // 0x8003C2D0: swc1        $f10, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
            goto L_8003C2C0;
    }
    // 0x8003C2D0: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x8003C2D4: lw          $t4, 0x30($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X30);
    // 0x8003C2D8: lwc1        $f16, 0x110($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X110);
    // 0x8003C2DC: addiu       $s0, $sp, 0x10C
    ctx->r16 = ADD32(ctx->r29, 0X10C);
    // 0x8003C2E0: lh          $t5, 0x4($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X4);
    // 0x8003C2E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003C2E8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8003C2EC: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x8003C2F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003C2F4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8003C2F8: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8003C2FC: jal         0x80042F80
    // 0x8003C300: swc1        $f6, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->f6.u32l;
    func_80042F80(rdram, ctx);
        goto after_5;
    // 0x8003C300: swc1        $f6, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x8003C304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003C308: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x8003C30C: jal         0x80042F80
    // 0x8003C310: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80042F80(rdram, ctx);
        goto after_6;
    // 0x8003C310: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x8003C314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003C318: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8003C31C: jal         0x80043714
    // 0x8003C320: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80043714(rdram, ctx);
        goto after_7;
    // 0x8003C320: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x8003C324: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x8003C328: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8003C32C: sh          $t6, 0x94($fp)
    MEM_H(0X94, ctx->r30) = ctx->r14;
    // 0x8003C330: b           L_8003C3D4
    // 0x8003C334: sh          $t7, 0x90($fp)
    MEM_H(0X90, ctx->r30) = ctx->r15;
        goto L_8003C3D4;
    // 0x8003C334: sh          $t7, 0x90($fp)
    MEM_H(0X90, ctx->r30) = ctx->r15;
L_8003C338:
    // 0x8003C338: lh          $t8, 0x94($fp)
    ctx->r24 = MEM_H(ctx->r30, 0X94);
    // 0x8003C33C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8003C340: beql        $t8, $zero, L_8003C3D4
    if (ctx->r24 == 0) {
        // 0x8003C344: sh          $t6, 0x90($fp)
        MEM_H(0X90, ctx->r30) = ctx->r14;
            goto L_8003C3D4;
    }
    goto skip_2;
    // 0x8003C344: sh          $t6, 0x90($fp)
    MEM_H(0X90, ctx->r30) = ctx->r14;
    skip_2:
    // 0x8003C348: lh          $t9, 0x96($fp)
    ctx->r25 = MEM_H(ctx->r30, 0X96);
    // 0x8003C34C: addiu       $v0, $sp, 0x10C
    ctx->r2 = ADD32(ctx->r29, 0X10C);
    // 0x8003C350: or          $v1, $fp, $zero
    ctx->r3 = ctx->r30 | 0;
    // 0x8003C354: bne         $t9, $zero, L_8003C3D4
    if (ctx->r25 != 0) {
        // 0x8003C358: addiu       $a0, $sp, 0x118
        ctx->r4 = ADD32(ctx->r29, 0X118);
            goto L_8003C3D4;
    }
    // 0x8003C358: addiu       $a0, $sp, 0x118
    ctx->r4 = ADD32(ctx->r29, 0X118);
L_8003C35C:
    // 0x8003C35C: lwc1        $f8, 0x10($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8003C360: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003C364: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003C368: bne         $v0, $a0, L_8003C35C
    if (ctx->r2 != ctx->r4) {
        // 0x8003C36C: swc1        $f8, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
            goto L_8003C35C;
    }
    // 0x8003C36C: swc1        $f8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
    // 0x8003C370: lw          $t0, 0x30($fp)
    ctx->r8 = MEM_W(ctx->r30, 0X30);
    // 0x8003C374: lwc1        $f10, 0x110($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X110);
    // 0x8003C378: addiu       $t2, $zero, 0x3F
    ctx->r10 = ADD32(0, 0X3F);
    // 0x8003C37C: lh          $t1, 0x4($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X4);
    // 0x8003C380: addiu       $t3, $zero, 0xF
    ctx->r11 = ADD32(0, 0XF);
    // 0x8003C384: addiu       $t4, $zero, 0x3F
    ctx->r12 = ADD32(0, 0X3F);
    // 0x8003C388: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x8003C38C: sh          $t4, 0x100($sp)
    MEM_H(0X100, ctx->r29) = ctx->r12;
    // 0x8003C390: sh          $t3, 0xFE($sp)
    MEM_H(0XFE, ctx->r29) = ctx->r11;
    // 0x8003C394: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8003C398: sh          $t2, 0xFC($sp)
    MEM_H(0XFC, ctx->r29) = ctx->r10;
    // 0x8003C39C: sh          $zero, 0xF8($sp)
    MEM_H(0XF8, ctx->r29) = 0;
    // 0x8003C3A0: sh          $zero, 0xF6($sp)
    MEM_H(0XF6, ctx->r29) = 0;
    // 0x8003C3A4: sh          $zero, 0xF4($sp)
    MEM_H(0XF4, ctx->r29) = 0;
    // 0x8003C3A8: addiu       $a0, $fp, 0x10
    ctx->r4 = ADD32(ctx->r30, 0X10);
    // 0x8003C3AC: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8003C3B0: addiu       $a1, $sp, 0xFC
    ctx->r5 = ADD32(ctx->r29, 0XFC);
    // 0x8003C3B4: addiu       $a2, $sp, 0xF4
    ctx->r6 = ADD32(ctx->r29, 0XF4);
    // 0x8003C3B8: addiu       $a3, $zero, 0x1A
    ctx->r7 = ADD32(0, 0X1A);
    // 0x8003C3BC: jal         0x80043DE8
    // 0x8003C3C0: swc1        $f4, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->f4.u32l;
    func_80043DE8(rdram, ctx);
        goto after_8;
    // 0x8003C3C0: swc1        $f4, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->f4.u32l;
    after_8:
    // 0x8003C3C4: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8003C3C8: b           L_8003C3D4
    // 0x8003C3CC: sh          $t5, 0x96($fp)
    MEM_H(0X96, ctx->r30) = ctx->r13;
        goto L_8003C3D4;
    // 0x8003C3CC: sh          $t5, 0x96($fp)
    MEM_H(0X96, ctx->r30) = ctx->r13;
    // 0x8003C3D0: sh          $t6, 0x90($fp)
    MEM_H(0X90, ctx->r30) = ctx->r14;
L_8003C3D4:
    // 0x8003C3D4: lh          $v1, 0x94($fp)
    ctx->r3 = MEM_H(ctx->r30, 0X94);
L_8003C3D8:
    // 0x8003C3D8: or          $v0, $fp, $zero
    ctx->r2 = ctx->r30 | 0;
    // 0x8003C3DC: beq         $v1, $zero, L_8003C3E8
    if (ctx->r3 == 0) {
        // 0x8003C3E0: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_8003C3E8;
    }
    // 0x8003C3E0: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x8003C3E4: sh          $t7, 0x94($fp)
    MEM_H(0X94, ctx->r30) = ctx->r15;
L_8003C3E8:
    // 0x8003C3E8: lh          $v1, 0x96($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X96);
    // 0x8003C3EC: beq         $v1, $zero, L_8003C3F8
    if (ctx->r3 == 0) {
        // 0x8003C3F0: addiu       $t8, $v1, -0x1
        ctx->r24 = ADD32(ctx->r3, -0X1);
            goto L_8003C3F8;
    }
    // 0x8003C3F0: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x8003C3F4: sh          $t8, 0x96($v0)
    MEM_H(0X96, ctx->r2) = ctx->r24;
L_8003C3F8:
    // 0x8003C3F8: lh          $v1, 0x98($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X98);
    // 0x8003C3FC: beq         $v1, $zero, L_8003C408
    if (ctx->r3 == 0) {
        // 0x8003C400: addiu       $t9, $v1, -0x1
        ctx->r25 = ADD32(ctx->r3, -0X1);
            goto L_8003C408;
    }
    // 0x8003C400: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
    // 0x8003C404: sh          $t9, 0x98($v0)
    MEM_H(0X98, ctx->r2) = ctx->r25;
L_8003C408:
    // 0x8003C408: lh          $v1, 0x9A($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X9A);
    // 0x8003C40C: beq         $v1, $zero, L_8003C418
    if (ctx->r3 == 0) {
        // 0x8003C410: addiu       $t0, $v1, -0x1
        ctx->r8 = ADD32(ctx->r3, -0X1);
            goto L_8003C418;
    }
    // 0x8003C410: addiu       $t0, $v1, -0x1
    ctx->r8 = ADD32(ctx->r3, -0X1);
    // 0x8003C414: sh          $t0, 0x9A($v0)
    MEM_H(0X9A, ctx->r2) = ctx->r8;
L_8003C418:
    // 0x8003C418: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8003C41C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8003C420: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8003C424: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8003C428: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8003C42C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8003C430: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8003C434: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8003C438: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8003C43C: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8003C440: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8003C444: jr          $ra
    // 0x8003C448: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
    TRACE_RETURN()
    return;
    // 0x8003C448: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
;}
RECOMP_FUNC void func_8003C44C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8003C44C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8003C450: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003C454: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003C458: lh          $v0, 0x90($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X90);
    // 0x8003C45C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003C460: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003C464: beql        $v0, $zero, L_8003C488
    if (ctx->r2 == 0) {
        // 0x8003C468: lh          $t6, 0x36($s0)
        ctx->r14 = MEM_H(ctx->r16, 0X36);
            goto L_8003C488;
    }
    goto skip_0;
    // 0x8003C468: lh          $t6, 0x36($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X36);
    skip_0:
    // 0x8003C46C: beq         $v0, $at, L_8003C574
    if (ctx->r2 == ctx->r1) {
        // 0x8003C470: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8003C574;
    }
    // 0x8003C470: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003C474: beql        $v0, $at, L_8003C614
    if (ctx->r2 == ctx->r1) {
        // 0x8003C478: lh          $v1, 0x94($s0)
        ctx->r3 = MEM_H(ctx->r16, 0X94);
            goto L_8003C614;
    }
    goto skip_1;
    // 0x8003C478: lh          $v1, 0x94($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X94);
    skip_1:
    // 0x8003C47C: b           L_8003C614
    // 0x8003C480: lh          $v1, 0x94($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X94);
        goto L_8003C614;
    // 0x8003C480: lh          $v1, 0x94($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X94);
    // 0x8003C484: lh          $t6, 0x36($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X36);
L_8003C488:
    // 0x8003C488: bgtzl       $t6, L_8003C614
    if (SIGNED(ctx->r14) > 0) {
        // 0x8003C48C: lh          $v1, 0x94($s0)
        ctx->r3 = MEM_H(ctx->r16, 0X94);
            goto L_8003C614;
    }
    goto skip_2;
    // 0x8003C48C: lh          $v1, 0x94($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X94);
    skip_2:
    // 0x8003C490: jal         0x8003A4E8
    // 0x8003C494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003A4E8(rdram, ctx);
        goto after_0;
    // 0x8003C494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8003C498: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x8003C49C: addiu       $v0, $sp, 0x44
    ctx->r2 = ADD32(ctx->r29, 0X44);
    // 0x8003C4A0: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8003C4A4: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x8003C4A8: lw          $a0, 0xE0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0XE0);
    // 0x8003C4AC: lbu         $t9, 0x10($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X10);
    // 0x8003C4B0: ori         $t0, $t9, 0x4
    ctx->r8 = ctx->r25 | 0X4;
    // 0x8003C4B4: sb          $t0, 0x10($a0)
    MEM_B(0X10, ctx->r4) = ctx->r8;
    // 0x8003C4B8: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
L_8003C4BC:
    // 0x8003C4BC: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8003C4C0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003C4C4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003C4C8: bne         $v0, $a0, L_8003C4BC
    if (ctx->r2 != ctx->r4) {
        // 0x8003C4CC: swc1        $f4, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
            goto L_8003C4BC;
    }
    // 0x8003C4CC: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x8003C4D0: lw          $t1, 0x30($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X30);
    // 0x8003C4D4: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8003C4D8: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8003C4DC: lh          $t2, 0x4($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X4);
    // 0x8003C4E0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8003C4E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003C4E8: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8003C4EC: nop

    // 0x8003C4F0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8003C4F4: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8003C4F8: jal         0x80042F80
    // 0x8003C4FC: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    func_80042F80(rdram, ctx);
        goto after_1;
    // 0x8003C4FC: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x8003C500: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8003C504: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x8003C508: jal         0x80042F80
    // 0x8003C50C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80042F80(rdram, ctx);
        goto after_2;
    // 0x8003C50C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8003C510: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8003C514: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8003C518: jal         0x80043714
    // 0x8003C51C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80043714(rdram, ctx);
        goto after_3;
    // 0x8003C51C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8003C520: addiu       $t3, $zero, 0x64
    ctx->r11 = ADD32(0, 0X64);
    // 0x8003C524: sh          $t3, 0x94($s0)
    MEM_H(0X94, ctx->r16) = ctx->r11;
    // 0x8003C528: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003C52C: lh          $v0, -0x662C($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X662C);
    // 0x8003C530: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    // 0x8003C534: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    // 0x8003C538: blez        $v0, L_8003C548
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003C53C: slti        $at, $v0, 0x3
        ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
            goto L_8003C548;
    }
    // 0x8003C53C: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8003C540: bnel        $at, $zero, L_8003C56C
    if (ctx->r1 != 0) {
        // 0x8003C544: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8003C56C;
    }
    goto skip_3;
    // 0x8003C544: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    skip_3:
L_8003C548:
    // 0x8003C548: jal         0x80039724
    // 0x8003C54C: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_80039724(rdram, ctx);
        goto after_4;
    // 0x8003C54C: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_4:
    // 0x8003C550: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    // 0x8003C554: jal         0x80039724
    // 0x8003C558: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80039724(rdram, ctx);
        goto after_5;
    // 0x8003C558: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x8003C55C: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    // 0x8003C560: jal         0x80039724
    // 0x8003C564: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80039724(rdram, ctx);
        goto after_6;
    // 0x8003C564: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_6:
    // 0x8003C568: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
L_8003C56C:
    // 0x8003C56C: b           L_8003C610
    // 0x8003C570: sh          $t4, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r12;
        goto L_8003C610;
    // 0x8003C570: sh          $t4, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r12;
L_8003C574:
    // 0x8003C574: lh          $t5, 0x94($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X94);
    // 0x8003C578: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8003C57C: beql        $t5, $zero, L_8003C610
    if (ctx->r13 == 0) {
        // 0x8003C580: sh          $t3, 0x90($s0)
        MEM_H(0X90, ctx->r16) = ctx->r11;
            goto L_8003C610;
    }
    goto skip_4;
    // 0x8003C580: sh          $t3, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r11;
    skip_4:
    // 0x8003C584: lh          $t6, 0x96($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X96);
    // 0x8003C588: addiu       $v0, $sp, 0x44
    ctx->r2 = ADD32(ctx->r29, 0X44);
    // 0x8003C58C: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8003C590: bne         $t6, $zero, L_8003C610
    if (ctx->r14 != 0) {
        // 0x8003C594: addiu       $a0, $sp, 0x50
        ctx->r4 = ADD32(ctx->r29, 0X50);
            goto L_8003C610;
    }
    // 0x8003C594: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
L_8003C598:
    // 0x8003C598: lwc1        $f18, 0x10($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8003C59C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003C5A0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003C5A4: bne         $v0, $a0, L_8003C598
    if (ctx->r2 != ctx->r4) {
        // 0x8003C5A8: swc1        $f18, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f18.u32l;
            goto L_8003C598;
    }
    // 0x8003C5A8: swc1        $f18, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f18.u32l;
    // 0x8003C5AC: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
    // 0x8003C5B0: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8003C5B4: addiu       $t9, $zero, 0x1F
    ctx->r25 = ADD32(0, 0X1F);
    // 0x8003C5B8: lh          $t8, 0x4($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X4);
    // 0x8003C5BC: addiu       $t0, $zero, 0xF
    ctx->r8 = ADD32(0, 0XF);
    // 0x8003C5C0: addiu       $t1, $zero, 0x1F
    ctx->r9 = ADD32(0, 0X1F);
    // 0x8003C5C4: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8003C5C8: sh          $t1, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r9;
    // 0x8003C5CC: sh          $t0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r8;
    // 0x8003C5D0: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8003C5D4: sh          $t9, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r25;
    // 0x8003C5D8: sh          $zero, 0x34($sp)
    MEM_H(0X34, ctx->r29) = 0;
    // 0x8003C5DC: sh          $zero, 0x32($sp)
    MEM_H(0X32, ctx->r29) = 0;
    // 0x8003C5E0: sh          $zero, 0x30($sp)
    MEM_H(0X30, ctx->r29) = 0;
    // 0x8003C5E4: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    // 0x8003C5E8: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003C5EC: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8003C5F0: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x8003C5F4: addiu       $a3, $zero, 0x1A
    ctx->r7 = ADD32(0, 0X1A);
    // 0x8003C5F8: jal         0x80043DE8
    // 0x8003C5FC: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    func_80043DE8(rdram, ctx);
        goto after_7;
    // 0x8003C5FC: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    after_7:
    // 0x8003C600: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8003C604: b           L_8003C610
    // 0x8003C608: sh          $t2, 0x96($s0)
    MEM_H(0X96, ctx->r16) = ctx->r10;
        goto L_8003C610;
    // 0x8003C608: sh          $t2, 0x96($s0)
    MEM_H(0X96, ctx->r16) = ctx->r10;
    // 0x8003C60C: sh          $t3, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r11;
L_8003C610:
    // 0x8003C610: lh          $v1, 0x94($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X94);
L_8003C614:
    // 0x8003C614: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8003C618: beq         $v1, $zero, L_8003C624
    if (ctx->r3 == 0) {
        // 0x8003C61C: addiu       $t4, $v1, -0x1
        ctx->r12 = ADD32(ctx->r3, -0X1);
            goto L_8003C624;
    }
    // 0x8003C61C: addiu       $t4, $v1, -0x1
    ctx->r12 = ADD32(ctx->r3, -0X1);
    // 0x8003C620: sh          $t4, 0x94($s0)
    MEM_H(0X94, ctx->r16) = ctx->r12;
L_8003C624:
    // 0x8003C624: lh          $v1, 0x96($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X96);
    // 0x8003C628: beq         $v1, $zero, L_8003C634
    if (ctx->r3 == 0) {
        // 0x8003C62C: addiu       $t5, $v1, -0x1
        ctx->r13 = ADD32(ctx->r3, -0X1);
            goto L_8003C634;
    }
    // 0x8003C62C: addiu       $t5, $v1, -0x1
    ctx->r13 = ADD32(ctx->r3, -0X1);
    // 0x8003C630: sh          $t5, 0x96($v0)
    MEM_H(0X96, ctx->r2) = ctx->r13;
L_8003C634:
    // 0x8003C634: lh          $v1, 0x98($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X98);
    // 0x8003C638: beq         $v1, $zero, L_8003C644
    if (ctx->r3 == 0) {
        // 0x8003C63C: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_8003C644;
    }
    // 0x8003C63C: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8003C640: sh          $t6, 0x98($v0)
    MEM_H(0X98, ctx->r2) = ctx->r14;
L_8003C644:
    // 0x8003C644: lh          $v1, 0x9A($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X9A);
    // 0x8003C648: beq         $v1, $zero, L_8003C654
    if (ctx->r3 == 0) {
        // 0x8003C64C: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_8003C654;
    }
    // 0x8003C64C: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x8003C650: sh          $t7, 0x9A($v0)
    MEM_H(0X9A, ctx->r2) = ctx->r15;
L_8003C654:
    // 0x8003C654: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003C658: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003C65C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8003C660: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8003C668(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8003C668: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x8003C66C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003C670: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003C674: sw          $a1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r5;
    // 0x8003C678: lh          $v0, 0x90($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X90);
    // 0x8003C67C: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x8003C680: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8003C684: beq         $v0, $zero, L_8003C6B0
    if (ctx->r2 == 0) {
        // 0x8003C688: or          $s0, $a0, $zero
        ctx->r16 = ctx->r4 | 0;
            goto L_8003C6B0;
    }
    // 0x8003C688: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003C68C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8003C690: beq         $v0, $v1, L_8003C6D0
    if (ctx->r2 == ctx->r3) {
        // 0x8003C694: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8003C6D0;
    }
    // 0x8003C694: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003C698: beq         $v0, $at, L_8003C8D8
    if (ctx->r2 == ctx->r1) {
        // 0x8003C69C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8003C8D8;
    }
    // 0x8003C69C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003C6A0: beql        $v0, $at, L_8003C9FC
    if (ctx->r2 == ctx->r1) {
        // 0x8003C6A4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8003C9FC;
    }
    goto skip_0;
    // 0x8003C6A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8003C6A8: b           L_8003C9FC
    // 0x8003C6AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8003C9FC;
    // 0x8003C6AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003C6B0:
    // 0x8003C6B0: lh          $t8, 0x36($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X36);
    // 0x8003C6B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003C6B8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8003C6BC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8003C6C0: sh          $v1, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r3;
    // 0x8003C6C4: sh          $t8, 0x9C($s0)
    MEM_H(0X9C, ctx->r16) = ctx->r24;
    // 0x8003C6C8: swc1        $f4, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f4.u32l;
    // 0x8003C6CC: swc1        $f6, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f6.u32l;
L_8003C6D0:
    // 0x8003C6D0: lh          $v0, 0x36($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X36);
    // 0x8003C6D4: lh          $t9, 0x9C($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X9C);
    // 0x8003C6D8: addiu       $t1, $zero, 0x64
    ctx->r9 = ADD32(0, 0X64);
    // 0x8003C6DC: beql        $v0, $t9, L_8003C700
    if (ctx->r2 == ctx->r25) {
        // 0x8003C6E0: lh          $t2, 0x9E($s0)
        ctx->r10 = MEM_H(ctx->r16, 0X9E);
            goto L_8003C700;
    }
    goto skip_1;
    // 0x8003C6E0: lh          $t2, 0x9E($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9E);
    skip_1:
    // 0x8003C6E4: bne         $a1, $v1, L_8003C6F4
    if (ctx->r5 != ctx->r3) {
        // 0x8003C6E8: addiu       $t0, $zero, 0x2710
        ctx->r8 = ADD32(0, 0X2710);
            goto L_8003C6F4;
    }
    // 0x8003C6E8: addiu       $t0, $zero, 0x2710
    ctx->r8 = ADD32(0, 0X2710);
    // 0x8003C6EC: sh          $t0, 0x36($s0)
    MEM_H(0X36, ctx->r16) = ctx->r8;
    // 0x8003C6F0: lh          $v0, 0x36($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X36);
L_8003C6F4:
    // 0x8003C6F4: sh          $v0, 0x9C($s0)
    MEM_H(0X9C, ctx->r16) = ctx->r2;
    // 0x8003C6F8: sh          $t1, 0x9E($s0)
    MEM_H(0X9E, ctx->r16) = ctx->r9;
    // 0x8003C6FC: lh          $t2, 0x9E($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9E);
L_8003C700:
    // 0x8003C700: beq         $t2, $zero, L_8003C874
    if (ctx->r10 == 0) {
        // 0x8003C704: nop
    
            goto L_8003C874;
    }
    // 0x8003C704: nop

    // 0x8003C708: jal         0x8004F7C0
    // 0x8003C70C: lwc1        $f12, 0xA4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XA4);
    func_8004F7C0(rdram, ctx);
        goto after_0;
    // 0x8003C70C: lwc1        $f12, 0xA4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XA4);
    after_0:
    // 0x8003C710: lh          $t3, 0x9E($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X9E);
    // 0x8003C714: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003C718: lwc1        $f16, 0x7494($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7494);
    // 0x8003C71C: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8003C720: lwc1        $f12, 0xA8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8003C724: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8003C728: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8003C72C: nop

    // 0x8003C730: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8003C734: jal         0x8004F7C0
    // 0x8003C738: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    func_8004F7C0(rdram, ctx);
        goto after_1;
    // 0x8003C738: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x8003C73C: lh          $t4, 0x9E($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X9E);
    // 0x8003C740: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003C744: lwc1        $f10, 0x7498($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7498);
    // 0x8003C748: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x8003C74C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003C750: lwc1        $f4, 0xA4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x8003C754: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8003C758: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8003C75C: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x8003C760: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x8003C764: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8003C768: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8003C76C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8003C770: lwc1        $f10, 0xA8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8003C774: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8003C778: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    // 0x8003C77C: lwc1        $f6, 0x749C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X749C);
    // 0x8003C780: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003C784: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003C788: swc1        $f8, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f8.u32l;
    // 0x8003C78C: lwc1        $f16, 0x74A0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X74A0);
    // 0x8003C790: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8003C794: swc1        $f18, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f18.u32l;
    // 0x8003C798: jal         0x80049840
    // 0x8003C79C: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    func_80049840(rdram, ctx);
        goto after_2;
    // 0x8003C79C: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x8003C7A0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003C7A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003C7A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003C7AC: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    // 0x8003C7B0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003C7B4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003C7B8: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x8003C7BC: jal         0x80049840
    // 0x8003C7C0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80049840(rdram, ctx);
        goto after_3;
    // 0x8003C7C0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x8003C7C4: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x8003C7C8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8003C7CC: jal         0x80000BD8
    // 0x8003C7D0: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    func_80000BD8(rdram, ctx);
        goto after_4;
    // 0x8003C7D0: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_4:
    // 0x8003C7D4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003C7D8: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    // 0x8003C7DC: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x8003C7E0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003C7E4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8003C7E8: jal         0x80049840
    // 0x8003C7EC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80049840(rdram, ctx);
        goto after_5;
    // 0x8003C7EC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x8003C7F0: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    // 0x8003C7F4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8003C7F8: jal         0x80000BD8
    // 0x8003C7FC: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    func_80000BD8(rdram, ctx);
        goto after_6;
    // 0x8003C7FC: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_6:
    // 0x8003C800: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8003C804: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x8003C808: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003C80C: lw          $a0, 0x8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X8);
    // 0x8003C810: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003C814: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003C818: jal         0x80001AB4
    // 0x8003C81C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80001AB4(rdram, ctx);
        goto after_7;
    // 0x8003C81C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_7:
    // 0x8003C820: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x8003C824: addiu       $a2, $sp, 0x7C
    ctx->r6 = ADD32(ctx->r29, 0X7C);
    // 0x8003C828: lw          $a0, 0x8($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X8);
    // 0x8003C82C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8003C830: jal         0x80000BD8
    // 0x8003C834: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_80000BD8(rdram, ctx);
        goto after_8;
    // 0x8003C834: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_8:
    // 0x8003C838: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003C83C: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8003C840: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
L_8003C844:
    // 0x8003C844: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x8003C848: lwc1        $f6, 0x10($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8003C84C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003C850: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x8003C854: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x8003C858: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003C85C: bne         $v0, $a0, L_8003C844
    if (ctx->r2 != ctx->r4) {
        // 0x8003C860: swc1        $f6, 0x40($t0)
        MEM_W(0X40, ctx->r8) = ctx->f6.u32l;
            goto L_8003C844;
    }
    // 0x8003C860: swc1        $f6, 0x40($t0)
    MEM_W(0X40, ctx->r8) = ctx->f6.u32l;
    // 0x8003C864: lh          $t1, 0x9E($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X9E);
    // 0x8003C868: lh          $v0, 0x36($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X36);
    // 0x8003C86C: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x8003C870: sh          $t2, 0x9E($s0)
    MEM_H(0X9E, ctx->r16) = ctx->r10;
L_8003C874:
    // 0x8003C874: bgtzl       $v0, L_8003C9FC
    if (SIGNED(ctx->r2) > 0) {
        // 0x8003C878: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8003C9FC;
    }
    goto skip_2;
    // 0x8003C878: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x8003C87C: jal         0x8003A4E8
    // 0x8003C880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003A4E8(rdram, ctx);
        goto after_9;
    // 0x8003C880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8003C884: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003C888: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003C88C: swc1        $f0, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->f0.u32l;
    // 0x8003C890: swc1        $f0, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f0.u32l;
    // 0x8003C894: lwc1        $f8, 0x74A4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X74A4);
    // 0x8003C898: jal         0x8000E35C
    // 0x8003C89C: swc1        $f8, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f8.u32l;
    func_8000E35C(rdram, ctx);
        goto after_10;
    // 0x8003C89C: swc1        $f8, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f8.u32l;
    after_10:
    // 0x8003C8A0: andi        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 & 0X1;
    // 0x8003C8A4: beq         $t3, $zero, L_8003C8B8
    if (ctx->r11 == 0) {
        // 0x8003C8A8: addiu       $t4, $zero, 0x4
        ctx->r12 = ADD32(0, 0X4);
            goto L_8003C8B8;
    }
    // 0x8003C8A8: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8003C8AC: lwc1        $f10, 0xA8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8003C8B0: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x8003C8B4: swc1        $f16, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f16.u32l;
L_8003C8B8:
    // 0x8003C8B8: sh          $zero, 0x96($s0)
    MEM_H(0X96, ctx->r16) = 0;
    // 0x8003C8BC: sh          $t4, 0x9C($s0)
    MEM_H(0X9C, ctx->r16) = ctx->r12;
    // 0x8003C8C0: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x8003C8C4: jal         0x800443A8
    // 0x8003C8C8: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    func_800443A8(rdram, ctx);
        goto after_11;
    // 0x8003C8C8: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_11:
    // 0x8003C8CC: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8003C8D0: b           L_8003C9F8
    // 0x8003C8D4: sh          $t5, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r13;
        goto L_8003C9F8;
    // 0x8003C8D4: sh          $t5, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r13;
L_8003C8D8:
    // 0x8003C8D8: lwc1        $f0, 0xA4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x8003C8DC: lwc1        $f18, 0xB8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x8003C8E0: lwc1        $f6, 0xA8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8003C8E4: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x8003C8E8: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8003C8EC: swc1        $f4, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->f4.u32l;
    // 0x8003C8F0: lwc1        $f12, 0xB8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x8003C8F4: jal         0x8000E16C
    // 0x8003C8F8: swc1        $f8, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f8.u32l;
    func_8000E16C(rdram, ctx);
        goto after_12;
    // 0x8003C8F8: swc1        $f8, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f8.u32l;
    after_12:
    // 0x8003C8FC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003C900: lwc1        $f10, 0x74A8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X74A8);
    // 0x8003C904: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003C908: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x8003C90C: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8003C910: nop

    // 0x8003C914: bc1fl       L_8003C950
    if (!c1cs) {
        // 0x8003C918: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8003C950;
    }
    goto skip_3;
    // 0x8003C918: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_3:
    // 0x8003C91C: lwc1        $f16, 0xA4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x8003C920: lwc1        $f18, 0x74AC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X74AC);
    // 0x8003C924: lh          $t6, 0x9C($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X9C);
    // 0x8003C928: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8003C92C: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8003C930: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8003C934: sh          $t7, 0x9C($s0)
    MEM_H(0X9C, ctx->r16) = ctx->r15;
    // 0x8003C938: lh          $t8, 0x9C($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X9C);
    // 0x8003C93C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8003C940: bne         $t8, $zero, L_8003C94C
    if (ctx->r24 != 0) {
        // 0x8003C944: swc1        $f6, 0xA4($s0)
        MEM_W(0XA4, ctx->r16) = ctx->f6.u32l;
            goto L_8003C94C;
    }
    // 0x8003C944: swc1        $f6, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f6.u32l;
    // 0x8003C948: sh          $t9, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r25;
L_8003C94C:
    // 0x8003C94C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8003C950:
    // 0x8003C950: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8003C954: lw          $a1, 0xB8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XB8);
    // 0x8003C958: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8003C95C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003C960: jal         0x80049840
    // 0x8003C964: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80049840(rdram, ctx);
        goto after_13;
    // 0x8003C964: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_13:
    // 0x8003C968: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003C96C: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    // 0x8003C970: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x8003C974: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003C978: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8003C97C: jal         0x80049840
    // 0x8003C980: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80049840(rdram, ctx);
        goto after_14;
    // 0x8003C980: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_14:
    // 0x8003C984: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x8003C988: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8003C98C: jal         0x80000BD8
    // 0x8003C990: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    func_80000BD8(rdram, ctx);
        goto after_15;
    // 0x8003C990: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_15:
    // 0x8003C994: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8003C998: lw          $t0, 0xC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XC);
    // 0x8003C99C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003C9A0: lw          $a0, 0x8($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X8);
    // 0x8003C9A4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003C9A8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003C9AC: jal         0x80001AB4
    // 0x8003C9B0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80001AB4(rdram, ctx);
        goto after_16;
    // 0x8003C9B0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_16:
    // 0x8003C9B4: lw          $t1, 0xC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XC);
    // 0x8003C9B8: addiu       $a2, $sp, 0x7C
    ctx->r6 = ADD32(ctx->r29, 0X7C);
    // 0x8003C9BC: lw          $a0, 0x8($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X8);
    // 0x8003C9C0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8003C9C4: jal         0x80000BD8
    // 0x8003C9C8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_80000BD8(rdram, ctx);
        goto after_17;
    // 0x8003C9C8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_17:
    // 0x8003C9CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003C9D0: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8003C9D4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
L_8003C9D8:
    // 0x8003C9D8: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
    // 0x8003C9DC: lwc1        $f8, 0x10($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8003C9E0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003C9E4: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x8003C9E8: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x8003C9EC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003C9F0: bne         $v0, $a0, L_8003C9D8
    if (ctx->r2 != ctx->r4) {
        // 0x8003C9F4: swc1        $f8, 0x40($t4)
        MEM_W(0X40, ctx->r12) = ctx->f8.u32l;
            goto L_8003C9D8;
    }
    // 0x8003C9F4: swc1        $f8, 0x40($t4)
    MEM_W(0X40, ctx->r12) = ctx->f8.u32l;
L_8003C9F8:
    // 0x8003C9F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003C9FC:
    // 0x8003C9FC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003CA00: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    // 0x8003CA04: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8003CA0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8003CA0C: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x8003CA10: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003CA14: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003CA18: lh          $v0, 0x90($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X90);
    // 0x8003CA1C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003CA20: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003CA24: beq         $v0, $zero, L_8003CA4C
    if (ctx->r2 == 0) {
        // 0x8003CA28: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8003CA4C;
    }
    // 0x8003CA28: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8003CA2C: beq         $v0, $at, L_8003CA68
    if (ctx->r2 == ctx->r1) {
        // 0x8003CA30: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8003CA68;
    }
    // 0x8003CA30: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003CA34: beq         $v0, $at, L_8003CCD0
    if (ctx->r2 == ctx->r1) {
        // 0x8003CA38: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8003CCD0;
    }
    // 0x8003CA38: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003CA3C: beql        $v0, $at, L_8003CDF4
    if (ctx->r2 == ctx->r1) {
        // 0x8003CA40: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8003CDF4;
    }
    goto skip_0;
    // 0x8003CA40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8003CA44: b           L_8003CDF4
    // 0x8003CA48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8003CDF4;
    // 0x8003CA48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003CA4C:
    // 0x8003CA4C: lh          $t6, 0x36($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X36);
    // 0x8003CA50: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003CA54: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8003CA58: sh          $t7, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r15;
    // 0x8003CA5C: sh          $t6, 0x9C($s0)
    MEM_H(0X9C, ctx->r16) = ctx->r14;
    // 0x8003CA60: swc1        $f4, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f4.u32l;
    // 0x8003CA64: swc1        $f6, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f6.u32l;
L_8003CA68:
    // 0x8003CA68: lh          $v0, 0x36($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X36);
    // 0x8003CA6C: lh          $t8, 0x9C($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X9C);
    // 0x8003CA70: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x8003CA74: beql        $v0, $t8, L_8003CA88
    if (ctx->r2 == ctx->r24) {
        // 0x8003CA78: lh          $t0, 0x9E($s0)
        ctx->r8 = MEM_H(ctx->r16, 0X9E);
            goto L_8003CA88;
    }
    goto skip_1;
    // 0x8003CA78: lh          $t0, 0x9E($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X9E);
    skip_1:
    // 0x8003CA7C: sh          $v0, 0x9C($s0)
    MEM_H(0X9C, ctx->r16) = ctx->r2;
    // 0x8003CA80: sh          $t9, 0x9E($s0)
    MEM_H(0X9E, ctx->r16) = ctx->r25;
    // 0x8003CA84: lh          $t0, 0x9E($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X9E);
L_8003CA88:
    // 0x8003CA88: beq         $t0, $zero, L_8003CBFC
    if (ctx->r8 == 0) {
        // 0x8003CA8C: nop
    
            goto L_8003CBFC;
    }
    // 0x8003CA8C: nop

    // 0x8003CA90: jal         0x8004F7C0
    // 0x8003CA94: lwc1        $f12, 0xA4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XA4);
    func_8004F7C0(rdram, ctx);
        goto after_0;
    // 0x8003CA94: lwc1        $f12, 0xA4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XA4);
    after_0:
    // 0x8003CA98: lh          $t1, 0x9E($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X9E);
    // 0x8003CA9C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003CAA0: lwc1        $f16, 0x74B0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X74B0);
    // 0x8003CAA4: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8003CAA8: lwc1        $f12, 0xA8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8003CAAC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8003CAB0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8003CAB4: nop

    // 0x8003CAB8: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8003CABC: jal         0x8004F7C0
    // 0x8003CAC0: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    func_8004F7C0(rdram, ctx);
        goto after_1;
    // 0x8003CAC0: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x8003CAC4: lh          $t2, 0x9E($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9E);
    // 0x8003CAC8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003CACC: lwc1        $f10, 0x74B4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X74B4);
    // 0x8003CAD0: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x8003CAD4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003CAD8: lwc1        $f4, 0xA4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x8003CADC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8003CAE0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8003CAE4: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x8003CAE8: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x8003CAEC: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8003CAF0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8003CAF4: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8003CAF8: lwc1        $f10, 0xA8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8003CAFC: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8003CB00: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    // 0x8003CB04: lwc1        $f6, 0x74B8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X74B8);
    // 0x8003CB08: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003CB0C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003CB10: swc1        $f8, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f8.u32l;
    // 0x8003CB14: lwc1        $f16, 0x74BC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X74BC);
    // 0x8003CB18: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8003CB1C: swc1        $f18, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f18.u32l;
    // 0x8003CB20: jal         0x80049840
    // 0x8003CB24: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    func_80049840(rdram, ctx);
        goto after_2;
    // 0x8003CB24: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x8003CB28: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8003CB2C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003CB30: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003CB34: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    // 0x8003CB38: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8003CB3C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8003CB40: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8003CB44: jal         0x80049840
    // 0x8003CB48: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80049840(rdram, ctx);
        goto after_3;
    // 0x8003CB48: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x8003CB4C: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x8003CB50: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8003CB54: jal         0x80000BD8
    // 0x8003CB58: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    func_80000BD8(rdram, ctx);
        goto after_4;
    // 0x8003CB58: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_4:
    // 0x8003CB5C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8003CB60: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    // 0x8003CB64: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8003CB68: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8003CB6C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8003CB70: jal         0x80049840
    // 0x8003CB74: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    func_80049840(rdram, ctx);
        goto after_5;
    // 0x8003CB74: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_5:
    // 0x8003CB78: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    // 0x8003CB7C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8003CB80: jal         0x80000BD8
    // 0x8003CB84: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    func_80000BD8(rdram, ctx);
        goto after_6;
    // 0x8003CB84: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_6:
    // 0x8003CB88: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8003CB8C: lw          $t4, 0xC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XC);
    // 0x8003CB90: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003CB94: lw          $a0, 0x8($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X8);
    // 0x8003CB98: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003CB9C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003CBA0: jal         0x80001AB4
    // 0x8003CBA4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80001AB4(rdram, ctx);
        goto after_7;
    // 0x8003CBA4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_7:
    // 0x8003CBA8: lw          $t5, 0xC($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XC);
    // 0x8003CBAC: addiu       $a2, $sp, 0x84
    ctx->r6 = ADD32(ctx->r29, 0X84);
    // 0x8003CBB0: lw          $a0, 0x8($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X8);
    // 0x8003CBB4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8003CBB8: jal         0x80000BD8
    // 0x8003CBBC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_80000BD8(rdram, ctx);
        goto after_8;
    // 0x8003CBBC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_8:
    // 0x8003CBC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003CBC4: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8003CBC8: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
L_8003CBCC:
    // 0x8003CBCC: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x8003CBD0: lwc1        $f6, 0x10($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8003CBD4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003CBD8: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x8003CBDC: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8003CBE0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003CBE4: bne         $v0, $a0, L_8003CBCC
    if (ctx->r2 != ctx->r4) {
        // 0x8003CBE8: swc1        $f6, 0x40($t8)
        MEM_W(0X40, ctx->r24) = ctx->f6.u32l;
            goto L_8003CBCC;
    }
    // 0x8003CBE8: swc1        $f6, 0x40($t8)
    MEM_W(0X40, ctx->r24) = ctx->f6.u32l;
    // 0x8003CBEC: lh          $t9, 0x9E($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X9E);
    // 0x8003CBF0: lh          $v0, 0x36($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X36);
    // 0x8003CBF4: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8003CBF8: sh          $t0, 0x9E($s0)
    MEM_H(0X9E, ctx->r16) = ctx->r8;
L_8003CBFC:
    // 0x8003CBFC: bgtzl       $v0, L_8003CDF4
    if (SIGNED(ctx->r2) > 0) {
        // 0x8003CC00: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8003CDF4;
    }
    goto skip_2;
    // 0x8003CC00: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x8003CC04: jal         0x8003A4E8
    // 0x8003CC08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003A4E8(rdram, ctx);
        goto after_9;
    // 0x8003CC08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8003CC0C: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8003CC10: addiu       $v0, $sp, 0x38
    ctx->r2 = ADD32(ctx->r29, 0X38);
    // 0x8003CC14: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
L_8003CC18:
    // 0x8003CC18: lwc1        $f8, 0x10($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8003CC1C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003CC20: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003CC24: bne         $v0, $a0, L_8003CC18
    if (ctx->r2 != ctx->r4) {
        // 0x8003CC28: swc1        $f8, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
            goto L_8003CC18;
    }
    // 0x8003CC28: swc1        $f8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
    // 0x8003CC2C: lw          $t1, 0x30($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X30);
    // 0x8003CC30: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8003CC34: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8003CC38: lh          $t2, 0x4($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X4);
    // 0x8003CC3C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8003CC40: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003CC44: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8003CC48: nop

    // 0x8003CC4C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003CC50: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8003CC54: jal         0x80042F80
    // 0x8003CC58: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    func_80042F80(rdram, ctx);
        goto after_10;
    // 0x8003CC58: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    after_10:
    // 0x8003CC5C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8003CC60: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x8003CC64: jal         0x80042F80
    // 0x8003CC68: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80042F80(rdram, ctx);
        goto after_11;
    // 0x8003CC68: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x8003CC6C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8003CC70: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8003CC74: jal         0x80043714
    // 0x8003CC78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80043714(rdram, ctx);
        goto after_12;
    // 0x8003CC78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
    // 0x8003CC7C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003CC80: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003CC84: swc1        $f0, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->f0.u32l;
    // 0x8003CC88: swc1        $f0, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f0.u32l;
    // 0x8003CC8C: lwc1        $f6, 0x74C0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X74C0);
    // 0x8003CC90: jal         0x8000E35C
    // 0x8003CC94: swc1        $f6, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f6.u32l;
    func_8000E35C(rdram, ctx);
        goto after_13;
    // 0x8003CC94: swc1        $f6, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f6.u32l;
    after_13:
    // 0x8003CC98: andi        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 & 0X1;
    // 0x8003CC9C: beq         $t3, $zero, L_8003CCB0
    if (ctx->r11 == 0) {
        // 0x8003CCA0: addiu       $t4, $zero, 0x4
        ctx->r12 = ADD32(0, 0X4);
            goto L_8003CCB0;
    }
    // 0x8003CCA0: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8003CCA4: lwc1        $f8, 0xA8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8003CCA8: neg.s       $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = -ctx->f8.fl;
    // 0x8003CCAC: swc1        $f16, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f16.u32l;
L_8003CCB0:
    // 0x8003CCB0: sh          $zero, 0x96($s0)
    MEM_H(0X96, ctx->r16) = 0;
    // 0x8003CCB4: sh          $t4, 0x9C($s0)
    MEM_H(0X9C, ctx->r16) = ctx->r12;
    // 0x8003CCB8: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x8003CCBC: jal         0x800443A8
    // 0x8003CCC0: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    func_800443A8(rdram, ctx);
        goto after_14;
    // 0x8003CCC0: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_14:
    // 0x8003CCC4: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8003CCC8: b           L_8003CDF0
    // 0x8003CCCC: sh          $t5, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r13;
        goto L_8003CDF0;
    // 0x8003CCCC: sh          $t5, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r13;
L_8003CCD0:
    // 0x8003CCD0: lwc1        $f0, 0xA4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x8003CCD4: lwc1        $f10, 0xB8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x8003CCD8: lwc1        $f4, 0xA8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8003CCDC: add.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x8003CCE0: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8003CCE4: swc1        $f18, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->f18.u32l;
    // 0x8003CCE8: lwc1        $f12, 0xB8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x8003CCEC: jal         0x8000E16C
    // 0x8003CCF0: swc1        $f6, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f6.u32l;
    func_8000E16C(rdram, ctx);
        goto after_15;
    // 0x8003CCF0: swc1        $f6, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f6.u32l;
    after_15:
    // 0x8003CCF4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003CCF8: lwc1        $f8, 0x74C4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X74C4);
    // 0x8003CCFC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003CD00: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x8003CD04: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8003CD08: nop

    // 0x8003CD0C: bc1fl       L_8003CD48
    if (!c1cs) {
        // 0x8003CD10: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8003CD48;
    }
    goto skip_3;
    // 0x8003CD10: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_3:
    // 0x8003CD14: lwc1        $f16, 0xA4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x8003CD18: lwc1        $f10, 0x74C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X74C8);
    // 0x8003CD1C: lh          $t6, 0x9C($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X9C);
    // 0x8003CD20: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8003CD24: div.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8003CD28: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8003CD2C: sh          $t7, 0x9C($s0)
    MEM_H(0X9C, ctx->r16) = ctx->r15;
    // 0x8003CD30: lh          $t8, 0x9C($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X9C);
    // 0x8003CD34: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x8003CD38: bne         $t8, $zero, L_8003CD44
    if (ctx->r24 != 0) {
        // 0x8003CD3C: swc1        $f4, 0xA4($s0)
        MEM_W(0XA4, ctx->r16) = ctx->f4.u32l;
            goto L_8003CD44;
    }
    // 0x8003CD3C: swc1        $f4, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f4.u32l;
    // 0x8003CD40: sh          $t9, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r25;
L_8003CD44:
    // 0x8003CD44: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8003CD48:
    // 0x8003CD48: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8003CD4C: lw          $a1, 0xB8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XB8);
    // 0x8003CD50: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8003CD54: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003CD58: jal         0x80049840
    // 0x8003CD5C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80049840(rdram, ctx);
        goto after_16;
    // 0x8003CD5C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_16:
    // 0x8003CD60: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8003CD64: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    // 0x8003CD68: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8003CD6C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8003CD70: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8003CD74: jal         0x80049840
    // 0x8003CD78: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    func_80049840(rdram, ctx);
        goto after_17;
    // 0x8003CD78: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_17:
    // 0x8003CD7C: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x8003CD80: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8003CD84: jal         0x80000BD8
    // 0x8003CD88: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    func_80000BD8(rdram, ctx);
        goto after_18;
    // 0x8003CD88: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_18:
    // 0x8003CD8C: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8003CD90: lw          $t0, 0xC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XC);
    // 0x8003CD94: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003CD98: lw          $a0, 0x8($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X8);
    // 0x8003CD9C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003CDA0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003CDA4: jal         0x80001AB4
    // 0x8003CDA8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80001AB4(rdram, ctx);
        goto after_19;
    // 0x8003CDA8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_19:
    // 0x8003CDAC: lw          $t1, 0xC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XC);
    // 0x8003CDB0: addiu       $a2, $sp, 0x84
    ctx->r6 = ADD32(ctx->r29, 0X84);
    // 0x8003CDB4: lw          $a0, 0x8($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X8);
    // 0x8003CDB8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8003CDBC: jal         0x80000BD8
    // 0x8003CDC0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_80000BD8(rdram, ctx);
        goto after_20;
    // 0x8003CDC0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_20:
    // 0x8003CDC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003CDC8: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8003CDCC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
L_8003CDD0:
    // 0x8003CDD0: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
    // 0x8003CDD4: lwc1        $f6, 0x10($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8003CDD8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003CDDC: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x8003CDE0: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x8003CDE4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003CDE8: bne         $v0, $a0, L_8003CDD0
    if (ctx->r2 != ctx->r4) {
        // 0x8003CDEC: swc1        $f6, 0x40($t4)
        MEM_W(0X40, ctx->r12) = ctx->f6.u32l;
            goto L_8003CDD0;
    }
    // 0x8003CDEC: swc1        $f6, 0x40($t4)
    MEM_W(0X40, ctx->r12) = ctx->f6.u32l;
L_8003CDF0:
    // 0x8003CDF0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003CDF4:
    // 0x8003CDF4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003CDF8: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    // 0x8003CDFC: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8003CE04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8003CE04: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x8003CE08: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8003CE0C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8003CE10: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8003CE14: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003CE18: lh          $v0, 0x90($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X90);
    // 0x8003CE1C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8003CE20: sh          $zero, 0xA0($a0)
    MEM_H(0XA0, ctx->r4) = 0;
    // 0x8003CE24: sltiu       $at, $v0, 0x6
    ctx->r1 = ctx->r2 < 0X6 ? 1 : 0;
    // 0x8003CE28: beq         $at, $zero, L_8003CFC4
    if (ctx->r1 == 0) {
        // 0x8003CE2C: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_8003CFC4;
    }
    // 0x8003CE2C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8003CE30: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003CE34: addu        $at, $at, $t6
    gpr jr_addend_8003CE3C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8003CE38: lw          $t6, 0x74CC($at)
    ctx->r14 = ADD32(ctx->r1, 0X74CC);
    // 0x8003CE3C: jr          $t6
    // 0x8003CE40: nop

    switch (jr_addend_8003CE3C >> 2) {
        case 0: goto L_8003CE44; break;
        case 1: goto L_8003CE6C; break;
        case 2: goto L_8003CFC4; break;
        case 3: goto L_8003CE94; break;
        case 4: goto L_8003CF0C; break;
        case 5: goto L_8003D0D8; break;
        default: switch_error(__func__, 0x8003CE3C, 0x800774CC);
    }
    // 0x8003CE40: nop

L_8003CE44:
    // 0x8003CE44: lwc1        $f4, 0x14($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8003CE48: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003CE4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003CE50: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8003CE54: sh          $v0, 0x9E($s2)
    MEM_H(0X9E, ctx->r18) = ctx->r2;
    // 0x8003CE58: sh          $zero, 0xA2($s2)
    MEM_H(0XA2, ctx->r18) = 0;
    // 0x8003CE5C: sh          $v0, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r2;
    // 0x8003CE60: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8003CE64: swc1        $f8, 0xA4($s2)
    MEM_W(0XA4, ctx->r18) = ctx->f8.u32l;
    // 0x8003CE68: sh          $t8, 0x9C($s2)
    MEM_H(0X9C, ctx->r18) = ctx->r24;
L_8003CE6C:
    // 0x8003CE6C: lh          $t9, 0xA2($s2)
    ctx->r25 = MEM_H(ctx->r18, 0XA2);
    // 0x8003CE70: bne         $t9, $zero, L_8003CE8C
    if (ctx->r25 != 0) {
        // 0x8003CE74: nop
    
            goto L_8003CE8C;
    }
    // 0x8003CE74: nop

    // 0x8003CE78: lh          $t0, 0x9E($s2)
    ctx->r8 = MEM_H(ctx->r18, 0X9E);
    // 0x8003CE7C: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8003CE80: sh          $t2, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r10;
    // 0x8003CE84: xori        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 ^ 0X1;
    // 0x8003CE88: sh          $t1, 0x9E($s2)
    MEM_H(0X9E, ctx->r18) = ctx->r9;
L_8003CE8C:
    // 0x8003CE8C: b           L_8003CFC4
    // 0x8003CE90: lh          $v0, 0x90($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X90);
        goto L_8003CFC4;
    // 0x8003CE90: lh          $v0, 0x90($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X90);
L_8003CE94:
    // 0x8003CE94: lh          $t3, 0x34($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X34);
    // 0x8003CE98: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8003CE9C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8003CEA0: blezl       $t3, L_8003CEF4
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8003CEA4: addiu       $a0, $zero, 0x20
        ctx->r4 = ADD32(0, 0X20);
            goto L_8003CEF4;
    }
    goto skip_0;
    // 0x8003CEA4: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    skip_0:
    // 0x8003CEA8: lw          $t4, 0x30($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X30);
L_8003CEAC:
    // 0x8003CEAC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8003CEB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003CEB4: addu        $a0, $t4, $s0
    ctx->r4 = ADD32(ctx->r12, ctx->r16);
    // 0x8003CEB8: jal         0x80042F80
    // 0x8003CEBC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_80042F80(rdram, ctx);
        goto after_0;
    // 0x8003CEBC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_0:
    // 0x8003CEC0: lw          $t5, 0x30($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X30);
    // 0x8003CEC4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8003CEC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003CECC: addu        $a0, $t5, $s0
    ctx->r4 = ADD32(ctx->r13, ctx->r16);
    // 0x8003CED0: jal         0x80043714
    // 0x8003CED4: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_80043714(rdram, ctx);
        goto after_1;
    // 0x8003CED4: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_1:
    // 0x8003CED8: lh          $t6, 0x34($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X34);
    // 0x8003CEDC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8003CEE0: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x8003CEE4: slt         $at, $s1, $t6
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8003CEE8: bnel        $at, $zero, L_8003CEAC
    if (ctx->r1 != 0) {
        // 0x8003CEEC: lw          $t4, 0x30($s2)
        ctx->r12 = MEM_W(ctx->r18, 0X30);
            goto L_8003CEAC;
    }
    goto skip_1;
    // 0x8003CEEC: lw          $t4, 0x30($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X30);
    skip_1:
    // 0x8003CEF0: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
L_8003CEF4:
    // 0x8003CEF4: jal         0x800443A8
    // 0x8003CEF8: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    func_800443A8(rdram, ctx);
        goto after_2;
    // 0x8003CEF8: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_2:
    // 0x8003CEFC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8003CF00: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8003CF04: sh          $t7, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r15;
    // 0x8003CF08: swc1        $f10, 0x48($s2)
    MEM_W(0X48, ctx->r18) = ctx->f10.u32l;
L_8003CF0C:
    // 0x8003CF0C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003CF10: lwc1        $f18, 0x74E4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X74E4);
    // 0x8003CF14: lwc1        $f16, 0x48($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X48);
    // 0x8003CF18: lwc1        $f6, 0x14($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8003CF1C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003CF20: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8003CF24: lwc1        $f16, 0x1C($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X1C);
    // 0x8003CF28: addiu       $s1, $sp, 0x38
    ctx->r17 = ADD32(ctx->r29, 0X38);
    // 0x8003CF2C: addiu       $s0, $s2, 0x10
    ctx->r16 = ADD32(ctx->r18, 0X10);
    // 0x8003CF30: swc1        $f4, 0x48($s2)
    MEM_W(0X48, ctx->r18) = ctx->f4.u32l;
    // 0x8003CF34: lwc1        $f8, 0x48($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X48);
    // 0x8003CF38: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8003CF3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8003CF40: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8003CF44: lwc1        $f6, 0x24($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X24);
    // 0x8003CF48: swc1        $f10, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f10.u32l;
    // 0x8003CF4C: lwc1        $f18, 0x74E8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X74E8);
    // 0x8003CF50: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003CF54: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8003CF58: swc1        $f4, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f4.u32l;
    // 0x8003CF5C: lwc1        $f8, 0x74EC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X74EC);
    // 0x8003CF60: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8003CF64: jal         0x8000D3A4
    // 0x8003CF68: swc1        $f10, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f10.u32l;
    func_8000D3A4(rdram, ctx);
        goto after_3;
    // 0x8003CF68: swc1        $f10, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f10.u32l;
    after_3:
    // 0x8003CF6C: beq         $v0, $zero, L_8003CFC0
    if (ctx->r2 == 0) {
        // 0x8003CF70: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8003CFC0;
    }
    // 0x8003CF70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8003CF74: jal         0x80003668
    // 0x8003CF78: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80003668(rdram, ctx);
        goto after_4;
    // 0x8003CF78: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x8003CF7C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8003CF80: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003CF84: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003CF88: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x8003CF8C: nop

    // 0x8003CF90: bc1fl       L_8003CFC4
    if (!c1cs) {
        // 0x8003CF94: lh          $v0, 0x90($s2)
        ctx->r2 = MEM_H(ctx->r18, 0X90);
            goto L_8003CFC4;
    }
    goto skip_2;
    // 0x8003CF94: lh          $v0, 0x90($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X90);
    skip_2:
    // 0x8003CF98: lwc1        $f12, 0x74F0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X74F0);
    // 0x8003CF9C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003CFA0: jal         0x80011534
    // 0x8003CFA4: lwc1        $f14, 0x74F4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X74F4);
    func_80011534(rdram, ctx);
        goto after_5;
    // 0x8003CFA4: lwc1        $f14, 0x74F4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X74F4);
    after_5:
    // 0x8003CFA8: jal         0x80044480
    // 0x8003CFAC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80044480(rdram, ctx);
        goto after_6;
    // 0x8003CFAC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x8003CFB0: jal         0x8003A4E8
    // 0x8003CFB4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8003A4E8(rdram, ctx);
        goto after_7;
    // 0x8003CFB4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_7:
    // 0x8003CFB8: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x8003CFBC: sh          $t8, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r24;
L_8003CFC0:
    // 0x8003CFC0: lh          $v0, 0x90($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X90);
L_8003CFC4:
    // 0x8003CFC4: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8003CFC8: beq         $at, $zero, L_8003CFE4
    if (ctx->r1 == 0) {
        // 0x8003CFCC: addiu       $s0, $sp, 0x84
        ctx->r16 = ADD32(ctx->r29, 0X84);
            goto L_8003CFE4;
    }
    // 0x8003CFCC: addiu       $s0, $sp, 0x84
    ctx->r16 = ADD32(ctx->r29, 0X84);
    // 0x8003CFD0: lh          $t9, 0x36($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X36);
    // 0x8003CFD4: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8003CFD8: bgtzl       $t9, L_8003CFE8
    if (SIGNED(ctx->r25) > 0) {
        // 0x8003CFDC: lh          $v0, 0xA2($s2)
        ctx->r2 = MEM_H(ctx->r18, 0XA2);
            goto L_8003CFE8;
    }
    goto skip_3;
    // 0x8003CFDC: lh          $v0, 0xA2($s2)
    ctx->r2 = MEM_H(ctx->r18, 0XA2);
    skip_3:
    // 0x8003CFE0: sh          $t0, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r8;
L_8003CFE4:
    // 0x8003CFE4: lh          $v0, 0xA2($s2)
    ctx->r2 = MEM_H(ctx->r18, 0XA2);
L_8003CFE8:
    // 0x8003CFE8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003CFEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003CFF0: beq         $v0, $zero, L_8003D000
    if (ctx->r2 == 0) {
        // 0x8003CFF4: lui         $a2, 0x3F80
        ctx->r6 = S32(0X3F80 << 16);
            goto L_8003D000;
    }
    // 0x8003CFF4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8003CFF8: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x8003CFFC: sh          $t1, 0xA2($s2)
    MEM_H(0XA2, ctx->r18) = ctx->r9;
L_8003D000:
    // 0x8003D000: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    // 0x8003D004: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003D008: jal         0x80049840
    // 0x8003D00C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80049840(rdram, ctx);
        goto after_8;
    // 0x8003D00C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x8003D010: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003D014: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003D018: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003D01C: addiu       $s1, $sp, 0x44
    ctx->r17 = ADD32(ctx->r29, 0X44);
    // 0x8003D020: lw          $a1, 0x24($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X24);
    // 0x8003D024: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003D028: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003D02C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8003D030: jal         0x80049840
    // 0x8003D034: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_80049840(rdram, ctx);
        goto after_9;
    // 0x8003D034: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_9:
    // 0x8003D038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003D03C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8003D040: jal         0x80000BD8
    // 0x8003D044: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_80000BD8(rdram, ctx);
        goto after_10;
    // 0x8003D044: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_10:
    // 0x8003D048: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003D04C: lw          $a1, 0x20($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X20);
    // 0x8003D050: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8003D054: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003D058: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8003D05C: jal         0x80049840
    // 0x8003D060: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80049840(rdram, ctx);
        goto after_11;
    // 0x8003D060: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_11:
    // 0x8003D064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003D068: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8003D06C: jal         0x80000BD8
    // 0x8003D070: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_80000BD8(rdram, ctx);
        goto after_12;
    // 0x8003D070: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_12:
    // 0x8003D074: lwc1        $f0, 0x2C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X2C);
    // 0x8003D078: lw          $t2, 0xC($s2)
    ctx->r10 = MEM_W(ctx->r18, 0XC);
    // 0x8003D07C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003D080: lw          $a0, 0x8($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X8);
    // 0x8003D084: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003D088: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003D08C: jal         0x80001AB4
    // 0x8003D090: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80001AB4(rdram, ctx);
        goto after_13;
    // 0x8003D090: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_13:
    // 0x8003D094: lw          $t3, 0xC($s2)
    ctx->r11 = MEM_W(ctx->r18, 0XC);
    // 0x8003D098: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8003D09C: lw          $a0, 0x8($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X8);
    // 0x8003D0A0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8003D0A4: jal         0x80000BD8
    // 0x8003D0A8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_80000BD8(rdram, ctx);
        goto after_14;
    // 0x8003D0A8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_14:
    // 0x8003D0AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003D0B0: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x8003D0B4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
L_8003D0B8:
    // 0x8003D0B8: lw          $t4, 0xC($s2)
    ctx->r12 = MEM_W(ctx->r18, 0XC);
    // 0x8003D0BC: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8003D0C0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003D0C4: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x8003D0C8: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8003D0CC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003D0D0: bne         $v0, $a0, L_8003D0B8
    if (ctx->r2 != ctx->r4) {
        // 0x8003D0D4: swc1        $f4, 0x40($t6)
        MEM_W(0X40, ctx->r14) = ctx->f4.u32l;
            goto L_8003D0B8;
    }
    // 0x8003D0D4: swc1        $f4, 0x40($t6)
    MEM_W(0X40, ctx->r14) = ctx->f4.u32l;
L_8003D0D8:
    // 0x8003D0D8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8003D0DC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003D0E0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8003D0E4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8003D0E8: jr          $ra
    // 0x8003D0EC: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    TRACE_RETURN()
    return;
    // 0x8003D0EC: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void func_8003D0F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8003D0F0: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x8003D0F4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8003D0F8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8003D0FC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8003D100: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003D104: lhu         $t6, 0x90($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X90);
    // 0x8003D108: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8003D10C: sltiu       $at, $t6, 0xA
    ctx->r1 = ctx->r14 < 0XA ? 1 : 0;
    // 0x8003D110: beq         $at, $zero, L_8003D5D4
    if (ctx->r1 == 0) {
        // 0x8003D114: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8003D5D4;
    }
    // 0x8003D114: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8003D118: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003D11C: addu        $at, $at, $t6
    gpr jr_addend_8003D124 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8003D120: lw          $t6, 0x74F8($at)
    ctx->r14 = ADD32(ctx->r1, 0X74F8);
    // 0x8003D124: jr          $t6
    // 0x8003D128: nop

    switch (jr_addend_8003D124 >> 2) {
        case 0: goto L_8003D12C; break;
        case 1: goto L_8003D2B0; break;
        case 2: goto L_8003D2D0; break;
        case 3: goto L_8003D324; break;
        case 4: goto L_8003D374; break;
        case 5: goto L_8003D434; break;
        case 6: goto L_8003D4B4; break;
        case 7: goto L_8003D504; break;
        case 8: goto L_8003D58C; break;
        case 9: goto L_8003D6B8; break;
        default: switch_error(__func__, 0x8003D124, 0x800774F8);
    }
    // 0x8003D128: nop

L_8003D12C:
    // 0x8003D12C: lbu         $t7, 0x8A($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X8A);
    // 0x8003D130: addiu       $at, $zero, 0x61
    ctx->r1 = ADD32(0, 0X61);
    // 0x8003D134: lui         $t1, 0x8007
    ctx->r9 = S32(0X8007 << 16);
    // 0x8003D138: bne         $t7, $at, L_8003D294
    if (ctx->r15 != ctx->r1) {
        // 0x8003D13C: addiu       $t8, $zero, 0x2
        ctx->r24 = ADD32(0, 0X2);
            goto L_8003D294;
    }
    // 0x8003D13C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8003D140: lbu         $v0, 0x89($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X89);
    // 0x8003D144: addiu       $t1, $t1, -0x5A00
    ctx->r9 = ADD32(ctx->r9, -0X5A00);
    // 0x8003D148: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003D14C: addiu       $v0, $v0, -0x31
    ctx->r2 = ADD32(ctx->r2, -0X31);
    // 0x8003D150: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x8003D154: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8003D158: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8003D15C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8003D160: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8003D164: addu        $s0, $t0, $t1
    ctx->r16 = ADD32(ctx->r8, ctx->r9);
    // 0x8003D168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003D16C: addiu       $a2, $s0, 0x10
    ctx->r6 = ADD32(ctx->r16, 0X10);
    // 0x8003D170: jal         0x8003DE20
    // 0x8003D174: sh          $t9, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r25;
    func_8003DE20(rdram, ctx);
        goto after_0;
    // 0x8003D174: sh          $t9, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r25;
    after_0:
    // 0x8003D178: beq         $v0, $zero, L_8003D288
    if (ctx->r2 == 0) {
        // 0x8003D17C: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8003D288;
    }
    // 0x8003D17C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8003D180: lh          $t2, 0x8($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X8);
    // 0x8003D184: lh          $t3, 0xA($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XA);
    // 0x8003D188: lh          $t4, 0xC($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XC);
    // 0x8003D18C: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8003D190: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8003D194: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x8003D198: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003D19C: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    // 0x8003D1A0: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8003D1A4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8003D1A8: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8003D1AC: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8003D1B0: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8003D1B4: jal         0x80001A6C
    // 0x8003D1B8: nop

    func_80001A6C(rdram, ctx);
        goto after_1;
    // 0x8003D1B8: nop

    after_1:
    // 0x8003D1BC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8003D1C0: addiu       $s0, $sp, 0x50
    ctx->r16 = ADD32(ctx->r29, 0X50);
    // 0x8003D1C4: lw          $a1, 0x20($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X20);
    // 0x8003D1C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003D1CC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8003D1D0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8003D1D4: jal         0x80049840
    // 0x8003D1D8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_80049840(rdram, ctx);
        goto after_2;
    // 0x8003D1D8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x8003D1DC: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    // 0x8003D1E0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8003D1E4: jal         0x80000BD8
    // 0x8003D1E8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80000BD8(rdram, ctx);
        goto after_3;
    // 0x8003D1E8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_3:
    // 0x8003D1EC: lh          $t6, 0x4A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X4A);
    // 0x8003D1F0: lui         $t8, 0x8007
    ctx->r24 = S32(0X8007 << 16);
    // 0x8003D1F4: addiu       $t8, $t8, -0x5A00
    ctx->r24 = ADD32(ctx->r24, -0X5A00);
    // 0x8003D1F8: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8003D1FC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8003D200: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8003D204: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x8003D208: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8003D20C: addiu       $v1, $sp, 0x90
    ctx->r3 = ADD32(ctx->r29, 0X90);
    // 0x8003D210: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8003D214: addiu       $a2, $sp, 0x9C
    ctx->r6 = ADD32(ctx->r29, 0X9C);
L_8003D218:
    // 0x8003D218: lwc1        $f16, 0x30($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X30);
    // 0x8003D21C: lwc1        $f18, 0x10($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8003D220: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003D224: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003D228: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8003D22C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8003D230: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8003D234: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x8003D238: lwc1        $f8, 0x18($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8003D23C: lwc1        $f6, 0xC($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8003D240: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8003D244: bne         $v1, $a2, L_8003D218
    if (ctx->r3 != ctx->r6) {
        // 0x8003D248: swc1        $f10, 0x18($v0)
        MEM_W(0X18, ctx->r2) = ctx->f10.u32l;
            goto L_8003D218;
    }
    // 0x8003D248: swc1        $f10, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f10.u32l;
    // 0x8003D24C: lw          $t9, 0x80($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X80);
    // 0x8003D250: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003D254: addiu       $v0, $v0, -0x659C
    ctx->r2 = ADD32(ctx->r2, -0X659C);
    // 0x8003D258: sw          $t9, 0x80($s1)
    MEM_W(0X80, ctx->r17) = ctx->r25;
    // 0x8003D25C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8003D260: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8003D264: sw          $s1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r17;
    // 0x8003D268: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8003D26C: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x8003D270: sw          $t3, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r11;
    // 0x8003D274: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8003D278: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x8003D27C: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8003D280: sw          $s1, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r17;
    // 0x8003D284: sw          $s2, 0xC0($s1)
    MEM_W(0XC0, ctx->r17) = ctx->r18;
L_8003D288:
    // 0x8003D288: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003D28C: b           L_8003D5D4
    // 0x8003D290: sh          $t6, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r14;
        goto L_8003D5D4;
    // 0x8003D290: sh          $t6, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r14;
L_8003D294:
    // 0x8003D294: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003D298: lh          $t7, 0x36($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X36);
    // 0x8003D29C: sh          $t8, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r24;
    // 0x8003D2A0: swc1        $f0, 0xA4($s2)
    MEM_W(0XA4, ctx->r18) = ctx->f0.u32l;
    // 0x8003D2A4: sh          $t7, 0x9C($s2)
    MEM_H(0X9C, ctx->r18) = ctx->r15;
    // 0x8003D2A8: b           L_8003D5D4
    // 0x8003D2AC: swc1        $f0, 0xA8($s2)
    MEM_W(0XA8, ctx->r18) = ctx->f0.u32l;
        goto L_8003D5D4;
    // 0x8003D2AC: swc1        $f0, 0xA8($s2)
    MEM_W(0XA8, ctx->r18) = ctx->f0.u32l;
L_8003D2B0:
    // 0x8003D2B0: lh          $v1, 0x36($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X36);
    // 0x8003D2B4: addiu       $at, $zero, 0x7530
    ctx->r1 = ADD32(0, 0X7530);
    // 0x8003D2B8: beql        $v1, $at, L_8003D5D8
    if (ctx->r3 == ctx->r1) {
        // 0x8003D2BC: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8003D5D8;
    }
    goto skip_0;
    // 0x8003D2BC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x8003D2C0: bgtz        $v1, L_8003D5D4
    if (SIGNED(ctx->r3) > 0) {
        // 0x8003D2C4: addiu       $t9, $zero, 0x8
        ctx->r25 = ADD32(0, 0X8);
            goto L_8003D5D4;
    }
    // 0x8003D2C4: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x8003D2C8: b           L_8003D5D4
    // 0x8003D2CC: sh          $t9, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r25;
        goto L_8003D5D4;
    // 0x8003D2CC: sh          $t9, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r25;
L_8003D2D0:
    // 0x8003D2D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003D2D4: lwc1        $f16, 0x1C($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X1C);
    // 0x8003D2D8: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8003D2DC: addiu       $a0, $s2, 0x10
    ctx->r4 = ADD32(ctx->r18, 0X10);
    // 0x8003D2E0: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x8003D2E4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8003D2E8: bc1f        L_8003D2F8
    if (!c1cs) {
        // 0x8003D2EC: nop
    
            goto L_8003D2F8;
    }
    // 0x8003D2EC: nop

    // 0x8003D2F0: b           L_8003D5D4
    // 0x8003D2F4: sh          $t0, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r8;
        goto L_8003D5D4;
    // 0x8003D2F4: sh          $t0, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r8;
L_8003D2F8:
    // 0x8003D2F8: jal         0x80003668
    // 0x8003D2FC: addiu       $a1, $a1, -0x6A18
    ctx->r5 = ADD32(ctx->r5, -0X6A18);
    func_80003668(rdram, ctx);
        goto after_4;
    // 0x8003D2FC: addiu       $a1, $a1, -0x6A18
    ctx->r5 = ADD32(ctx->r5, -0X6A18);
    after_4:
    // 0x8003D300: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8003D304: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003D308: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8003D30C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8003D310: nop

    // 0x8003D314: bc1fl       L_8003D5D8
    if (!c1cs) {
        // 0x8003D318: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8003D5D8;
    }
    goto skip_1;
    // 0x8003D318: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_1:
    // 0x8003D31C: b           L_8003D5D4
    // 0x8003D320: sh          $t1, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r9;
        goto L_8003D5D4;
    // 0x8003D320: sh          $t1, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r9;
L_8003D324:
    // 0x8003D324: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003D328: lwc1        $f6, 0x7520($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7520);
    // 0x8003D32C: lwc1        $f4, 0x1C($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X1C);
    // 0x8003D330: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003D334: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8003D338: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003D33C: addiu       $t4, $zero, 0x7
    ctx->r12 = ADD32(0, 0X7);
    // 0x8003D340: swc1        $f8, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f8.u32l;
    // 0x8003D344: lwc1        $f10, 0x1C($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X1C);
    // 0x8003D348: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x8003D34C: nop

    // 0x8003D350: bc1fl       L_8003D364
    if (!c1cs) {
        // 0x8003D354: lh          $t3, 0x36($s2)
        ctx->r11 = MEM_H(ctx->r18, 0X36);
            goto L_8003D364;
    }
    goto skip_2;
    // 0x8003D354: lh          $t3, 0x36($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X36);
    skip_2:
    // 0x8003D358: swc1        $f0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f0.u32l;
    // 0x8003D35C: sh          $t2, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r10;
    // 0x8003D360: lh          $t3, 0x36($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X36);
L_8003D364:
    // 0x8003D364: bgtzl       $t3, L_8003D5D8
    if (SIGNED(ctx->r11) > 0) {
        // 0x8003D368: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8003D5D8;
    }
    goto skip_3;
    // 0x8003D368: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_3:
    // 0x8003D36C: b           L_8003D5D4
    // 0x8003D370: sh          $t4, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r12;
        goto L_8003D5D4;
    // 0x8003D370: sh          $t4, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r12;
L_8003D374:
    // 0x8003D374: lh          $v1, 0x36($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X36);
    // 0x8003D378: lh          $t5, 0x9C($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X9C);
    // 0x8003D37C: addiu       $t6, $zero, 0x32
    ctx->r14 = ADD32(0, 0X32);
    // 0x8003D380: beql        $v1, $t5, L_8003D394
    if (ctx->r3 == ctx->r13) {
        // 0x8003D384: lh          $t7, 0x9E($s2)
        ctx->r15 = MEM_H(ctx->r18, 0X9E);
            goto L_8003D394;
    }
    goto skip_4;
    // 0x8003D384: lh          $t7, 0x9E($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X9E);
    skip_4:
    // 0x8003D388: sh          $v1, 0x9C($s2)
    MEM_H(0X9C, ctx->r18) = ctx->r3;
    // 0x8003D38C: sh          $t6, 0x9E($s2)
    MEM_H(0X9E, ctx->r18) = ctx->r14;
    // 0x8003D390: lh          $t7, 0x9E($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X9E);
L_8003D394:
    // 0x8003D394: beq         $t7, $zero, L_8003D424
    if (ctx->r15 == 0) {
        // 0x8003D398: nop
    
            goto L_8003D424;
    }
    // 0x8003D398: nop

    // 0x8003D39C: jal         0x8004F7C0
    // 0x8003D3A0: lwc1        $f12, 0xA4($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0XA4);
    func_8004F7C0(rdram, ctx);
        goto after_5;
    // 0x8003D3A0: lwc1        $f12, 0xA4($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0XA4);
    after_5:
    // 0x8003D3A4: lh          $t8, 0x9E($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X9E);
    // 0x8003D3A8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003D3AC: lwc1        $f4, 0x7524($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7524);
    // 0x8003D3B0: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8003D3B4: lwc1        $f12, 0xA8($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0XA8);
    // 0x8003D3B8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003D3BC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8003D3C0: nop

    // 0x8003D3C4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8003D3C8: jal         0x8004F7C0
    // 0x8003D3CC: swc1        $f8, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f8.u32l;
    func_8004F7C0(rdram, ctx);
        goto after_6;
    // 0x8003D3CC: swc1        $f8, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f8.u32l;
    after_6:
    // 0x8003D3D0: lh          $v0, 0x9E($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X9E);
    // 0x8003D3D4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003D3D8: lwc1        $f18, 0x7528($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7528);
    // 0x8003D3DC: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8003D3E0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003D3E4: lwc1        $f8, 0xA4($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0XA4);
    // 0x8003D3E8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8003D3EC: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x8003D3F0: lh          $v1, 0x36($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X36);
    // 0x8003D3F4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8003D3F8: lwc1        $f18, 0xA8($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0XA8);
    // 0x8003D3FC: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8003D400: swc1        $f6, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f6.u32l;
    // 0x8003D404: lwc1        $f10, 0x752C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X752C);
    // 0x8003D408: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003D40C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8003D410: swc1        $f16, 0xA4($s2)
    MEM_W(0XA4, ctx->r18) = ctx->f16.u32l;
    // 0x8003D414: lwc1        $f4, 0x7530($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7530);
    // 0x8003D418: sh          $t9, 0x9E($s2)
    MEM_H(0X9E, ctx->r18) = ctx->r25;
    // 0x8003D41C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8003D420: swc1        $f6, 0xA8($s2)
    MEM_W(0XA8, ctx->r18) = ctx->f6.u32l;
L_8003D424:
    // 0x8003D424: bgtz        $v1, L_8003D5D4
    if (SIGNED(ctx->r3) > 0) {
        // 0x8003D428: addiu       $t0, $zero, 0x5
        ctx->r8 = ADD32(0, 0X5);
            goto L_8003D5D4;
    }
    // 0x8003D428: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x8003D42C: b           L_8003D5D4
    // 0x8003D430: sh          $t0, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r8;
        goto L_8003D5D4;
    // 0x8003D430: sh          $t0, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r8;
L_8003D434:
    // 0x8003D434: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003D438: lwc1        $f8, 0x1C($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X1C);
    // 0x8003D43C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003D440: swc1        $f0, 0xA4($s2)
    MEM_W(0XA4, ctx->r18) = ctx->f0.u32l;
    // 0x8003D444: swc1        $f8, 0xB8($s2)
    MEM_W(0XB8, ctx->r18) = ctx->f8.u32l;
    // 0x8003D448: lwc1        $f10, 0x7534($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7534);
    // 0x8003D44C: jal         0x8000E35C
    // 0x8003D450: swc1        $f10, 0xA8($s2)
    MEM_W(0XA8, ctx->r18) = ctx->f10.u32l;
    func_8000E35C(rdram, ctx);
        goto after_7;
    // 0x8003D450: swc1        $f10, 0xA8($s2)
    MEM_W(0XA8, ctx->r18) = ctx->f10.u32l;
    after_7:
    // 0x8003D454: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x8003D458: beq         $t1, $zero, L_8003D46C
    if (ctx->r9 == 0) {
        // 0x8003D45C: addiu       $a0, $zero, 0x20
        ctx->r4 = ADD32(0, 0X20);
            goto L_8003D46C;
    }
    // 0x8003D45C: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x8003D460: lwc1        $f16, 0xA8($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0XA8);
    // 0x8003D464: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x8003D468: swc1        $f18, 0xA8($s2)
    MEM_W(0XA8, ctx->r18) = ctx->f18.u32l;
L_8003D46C:
    // 0x8003D46C: jal         0x800443A8
    // 0x8003D470: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    func_800443A8(rdram, ctx);
        goto after_8;
    // 0x8003D470: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_8:
    // 0x8003D474: addiu       $s0, $s2, 0x10
    ctx->r16 = ADD32(ctx->r18, 0X10);
    // 0x8003D478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003D47C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8003D480: jal         0x80042F80
    // 0x8003D484: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80042F80(rdram, ctx);
        goto after_9;
    // 0x8003D484: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x8003D488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003D48C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x8003D490: jal         0x80042F80
    // 0x8003D494: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80042F80(rdram, ctx);
        goto after_10;
    // 0x8003D494: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x8003D498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003D49C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8003D4A0: jal         0x80043714
    // 0x8003D4A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80043714(rdram, ctx);
        goto after_11;
    // 0x8003D4A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x8003D4A8: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x8003D4AC: b           L_8003D5D4
    // 0x8003D4B0: sh          $t2, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r10;
        goto L_8003D5D4;
    // 0x8003D4B0: sh          $t2, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r10;
L_8003D4B4:
    // 0x8003D4B4: lwc1        $f0, 0xA4($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XA4);
    // 0x8003D4B8: lwc1        $f4, 0xB8($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XB8);
    // 0x8003D4BC: lwc1        $f8, 0xA8($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0XA8);
    // 0x8003D4C0: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8003D4C4: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x8003D4C8: swc1        $f6, 0xB8($s2)
    MEM_W(0XB8, ctx->r18) = ctx->f6.u32l;
    // 0x8003D4CC: lwc1        $f12, 0xB8($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0XB8);
    // 0x8003D4D0: jal         0x8000E16C
    // 0x8003D4D4: swc1        $f10, 0xA4($s2)
    MEM_W(0XA4, ctx->r18) = ctx->f10.u32l;
    func_8000E16C(rdram, ctx);
        goto after_12;
    // 0x8003D4D4: swc1        $f10, 0xA4($s2)
    MEM_W(0XA4, ctx->r18) = ctx->f10.u32l;
    after_12:
    // 0x8003D4D8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003D4DC: lwc1        $f16, 0x7538($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7538);
    // 0x8003D4E0: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x8003D4E4: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8003D4E8: nop

    // 0x8003D4EC: bc1fl       L_8003D4FC
    if (!c1cs) {
        // 0x8003D4F0: lwc1        $f18, 0xB8($s2)
        ctx->f18.u32l = MEM_W(ctx->r18, 0XB8);
            goto L_8003D4FC;
    }
    goto skip_5;
    // 0x8003D4F0: lwc1        $f18, 0xB8($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0XB8);
    skip_5:
    // 0x8003D4F4: sh          $t3, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r11;
    // 0x8003D4F8: lwc1        $f18, 0xB8($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0XB8);
L_8003D4FC:
    // 0x8003D4FC: b           L_8003D5D4
    // 0x8003D500: swc1        $f18, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f18.u32l;
        goto L_8003D5D4;
    // 0x8003D500: swc1        $f18, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f18.u32l;
L_8003D504:
    // 0x8003D504: lw          $t5, 0xC0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0XC0);
    // 0x8003D508: addiu       $t4, $zero, 0x64
    ctx->r12 = ADD32(0, 0X64);
    // 0x8003D50C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8003D510: jal         0x8003A4E8
    // 0x8003D514: sh          $t4, 0x36($t5)
    MEM_H(0X36, ctx->r13) = ctx->r12;
    func_8003A4E8(rdram, ctx);
        goto after_13;
    // 0x8003D514: sh          $t4, 0x36($t5)
    MEM_H(0X36, ctx->r13) = ctx->r12;
    after_13:
    // 0x8003D518: jal         0x8001F494
    // 0x8003D51C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8001F494(rdram, ctx);
        goto after_14;
    // 0x8003D51C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_14:
    // 0x8003D520: lh          $t6, 0x34($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X34);
    // 0x8003D524: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8003D528: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8003D52C: blez        $t6, L_8003D57C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8003D530: nop
    
            goto L_8003D57C;
    }
    // 0x8003D530: nop

    // 0x8003D534: lw          $t7, 0x30($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X30);
L_8003D538:
    // 0x8003D538: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8003D53C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003D540: addu        $a0, $t7, $s0
    ctx->r4 = ADD32(ctx->r15, ctx->r16);
    // 0x8003D544: jal         0x80042F80
    // 0x8003D548: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_80042F80(rdram, ctx);
        goto after_15;
    // 0x8003D548: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_15:
    // 0x8003D54C: lw          $t8, 0x30($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X30);
    // 0x8003D550: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8003D554: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003D558: addu        $a0, $t8, $s0
    ctx->r4 = ADD32(ctx->r24, ctx->r16);
    // 0x8003D55C: jal         0x80043714
    // 0x8003D560: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_80043714(rdram, ctx);
        goto after_16;
    // 0x8003D560: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_16:
    // 0x8003D564: lh          $t9, 0x34($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X34);
    // 0x8003D568: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8003D56C: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x8003D570: slt         $at, $s1, $t9
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8003D574: bnel        $at, $zero, L_8003D538
    if (ctx->r1 != 0) {
        // 0x8003D578: lw          $t7, 0x30($s2)
        ctx->r15 = MEM_W(ctx->r18, 0X30);
            goto L_8003D538;
    }
    goto skip_6;
    // 0x8003D578: lw          $t7, 0x30($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X30);
    skip_6:
L_8003D57C:
    // 0x8003D57C: jal         0x8003A008
    // 0x8003D580: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8003A008(rdram, ctx);
        goto after_17;
    // 0x8003D580: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_17:
    // 0x8003D584: b           L_8003D6BC
    // 0x8003D588: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8003D6BC;
    // 0x8003D588: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8003D58C:
    // 0x8003D58C: jal         0x8003A4E8
    // 0x8003D590: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8003A4E8(rdram, ctx);
        goto after_18;
    // 0x8003D590: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_18:
    // 0x8003D594: addiu       $s0, $s2, 0x10
    ctx->r16 = ADD32(ctx->r18, 0X10);
    // 0x8003D598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003D59C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8003D5A0: jal         0x80042F80
    // 0x8003D5A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80042F80(rdram, ctx);
        goto after_19;
    // 0x8003D5A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_19:
    // 0x8003D5A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003D5AC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8003D5B0: jal         0x80043714
    // 0x8003D5B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80043714(rdram, ctx);
        goto after_20;
    // 0x8003D5B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_20:
    // 0x8003D5B8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8003D5BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003D5C0: lwc1        $f4, 0x14($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8003D5C4: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x8003D5C8: sh          $t0, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r8;
    // 0x8003D5CC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003D5D0: swc1        $f8, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f8.u32l;
L_8003D5D4:
    // 0x8003D5D4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_8003D5D8:
    // 0x8003D5D8: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    // 0x8003D5DC: addiu       $s0, $sp, 0x50
    ctx->r16 = ADD32(ctx->r29, 0X50);
    // 0x8003D5E0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003D5E4: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    // 0x8003D5E8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8003D5EC: jal         0x80049840
    // 0x8003D5F0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80049840(rdram, ctx);
        goto after_21;
    // 0x8003D5F0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_21:
    // 0x8003D5F4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003D5F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003D5FC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003D600: lw          $a1, 0x24($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X24);
    // 0x8003D604: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003D608: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003D60C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003D610: jal         0x80049840
    // 0x8003D614: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_80049840(rdram, ctx);
        goto after_22;
    // 0x8003D614: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_22:
    // 0x8003D618: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    // 0x8003D61C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8003D620: jal         0x80000BD8
    // 0x8003D624: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80000BD8(rdram, ctx);
        goto after_23;
    // 0x8003D624: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_23:
    // 0x8003D628: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003D62C: lw          $a1, 0x20($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X20);
    // 0x8003D630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003D634: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8003D638: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8003D63C: jal         0x80049840
    // 0x8003D640: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_80049840(rdram, ctx);
        goto after_24;
    // 0x8003D640: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_24:
    // 0x8003D644: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    // 0x8003D648: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8003D64C: jal         0x80000BD8
    // 0x8003D650: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80000BD8(rdram, ctx);
        goto after_25;
    // 0x8003D650: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_25:
    // 0x8003D654: lwc1        $f0, 0x2C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X2C);
    // 0x8003D658: lw          $t1, 0xC($s2)
    ctx->r9 = MEM_W(ctx->r18, 0XC);
    // 0x8003D65C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003D660: lw          $a0, 0x8($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X8);
    // 0x8003D664: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003D668: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003D66C: jal         0x80001AB4
    // 0x8003D670: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80001AB4(rdram, ctx);
        goto after_26;
    // 0x8003D670: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_26:
    // 0x8003D674: lw          $t2, 0xC($s2)
    ctx->r10 = MEM_W(ctx->r18, 0XC);
    // 0x8003D678: addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    // 0x8003D67C: lw          $a0, 0x8($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X8);
    // 0x8003D680: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8003D684: jal         0x80000BD8
    // 0x8003D688: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_80000BD8(rdram, ctx);
        goto after_27;
    // 0x8003D688: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_27:
    // 0x8003D68C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003D690: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x8003D694: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
L_8003D698:
    // 0x8003D698: lw          $t3, 0xC($s2)
    ctx->r11 = MEM_W(ctx->r18, 0XC);
    // 0x8003D69C: lwc1        $f18, 0x10($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8003D6A0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003D6A4: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x8003D6A8: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x8003D6AC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003D6B0: bne         $v0, $a0, L_8003D698
    if (ctx->r2 != ctx->r4) {
        // 0x8003D6B4: swc1        $f18, 0x40($t5)
        MEM_W(0X40, ctx->r13) = ctx->f18.u32l;
            goto L_8003D698;
    }
    // 0x8003D6B4: swc1        $f18, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f18.u32l;
L_8003D6B8:
    // 0x8003D6B8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8003D6BC:
    // 0x8003D6BC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003D6C0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8003D6C4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8003D6C8: jr          $ra
    // 0x8003D6CC: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    TRACE_RETURN()
    return;
    // 0x8003D6CC: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
;}
RECOMP_FUNC void func_8003D6D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8003D6D0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8003D6D4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8003D6D8: lw          $t6, -0x65A0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X65A0);
    // 0x8003D6DC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8003D6E0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8003D6E4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8003D6E8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003D6EC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8003D6F0: lw          $s0, 0x0($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X0);
    // 0x8003D6F4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8003D6F8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8003D6FC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8003D700: beql        $t7, $zero, L_8003D7B8
    if (ctx->r15 == 0) {
        // 0x8003D704: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8003D7B8;
    }
    goto skip_0;
    // 0x8003D704: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8003D708: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8003D70C: addiu       $s2, $zero, 0xB
    ctx->r18 = ADD32(0, 0XB);
    // 0x8003D710: lh          $t8, 0x8E($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X8E);
L_8003D714:
    // 0x8003D714: bnel        $s2, $t8, L_8003D7A8
    if (ctx->r18 != ctx->r24) {
        // 0x8003D718: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_8003D7A8;
    }
    goto skip_1;
    // 0x8003D718: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x8003D71C: beql        $s0, $s1, L_8003D7A8
    if (ctx->r16 == ctx->r17) {
        // 0x8003D720: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_8003D7A8;
    }
    goto skip_2;
    // 0x8003D720: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x8003D724: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003D728: lwc1        $f6, 0x14($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8003D72C: addiu       $a0, $s1, 0x10
    ctx->r4 = ADD32(ctx->r17, 0X10);
    // 0x8003D730: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8003D734: nop

    // 0x8003D738: bc1fl       L_8003D7A8
    if (!c1cs) {
        // 0x8003D73C: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_8003D7A8;
    }
    goto skip_3;
    // 0x8003D73C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_3:
    // 0x8003D740: jal         0x80003668
    // 0x8003D744: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    func_80003668(rdram, ctx);
        goto after_0;
    // 0x8003D744: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    after_0:
    // 0x8003D748: lw          $t9, 0x30($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X30);
    // 0x8003D74C: lw          $t1, 0x30($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X30);
    // 0x8003D750: add.s       $f16, $f0, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x8003D754: lh          $t0, 0x14($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X14);
    // 0x8003D758: lh          $t2, 0x14($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X14);
    // 0x8003D75C: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x8003D760: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8003D764: nop

    // 0x8003D768: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8003D76C: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x8003D770: nop

    // 0x8003D774: bc1fl       L_8003D7A8
    if (!c1cs) {
        // 0x8003D778: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_8003D7A8;
    }
    goto skip_4;
    // 0x8003D778: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_4:
    // 0x8003D77C: lh          $v0, 0x9E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X9E);
    // 0x8003D780: beq         $v0, $zero, L_8003D79C
    if (ctx->r2 == 0) {
        // 0x8003D784: nop
    
            goto L_8003D79C;
    }
    // 0x8003D784: nop

    // 0x8003D788: bgez        $v0, L_8003D798
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8003D78C: sra         $t4, $v0, 1
        ctx->r12 = S32(SIGNED(ctx->r2) >> 1);
            goto L_8003D798;
    }
    // 0x8003D78C: sra         $t4, $v0, 1
    ctx->r12 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8003D790: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x8003D794: sra         $t4, $at, 1
    ctx->r12 = S32(SIGNED(ctx->r1) >> 1);
L_8003D798:
    // 0x8003D798: sh          $t4, 0x9E($s1)
    MEM_H(0X9E, ctx->r17) = ctx->r12;
L_8003D79C:
    // 0x8003D79C: b           L_8003D7B8
    // 0x8003D7A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8003D7B8;
    // 0x8003D7A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003D7A4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_8003D7A8:
    // 0x8003D7A8: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8003D7AC: bnel        $t5, $zero, L_8003D714
    if (ctx->r13 != 0) {
        // 0x8003D7B0: lh          $t8, 0x8E($s0)
        ctx->r24 = MEM_H(ctx->r16, 0X8E);
            goto L_8003D714;
    }
    goto skip_5;
    // 0x8003D7B0: lh          $t8, 0x8E($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X8E);
    skip_5:
    // 0x8003D7B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003D7B8:
    // 0x8003D7B8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8003D7BC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8003D7C0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003D7C4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8003D7C8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8003D7CC: jr          $ra
    // 0x8003D7D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    TRACE_RETURN()
    return;
    // 0x8003D7D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8003D7D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8003D7D4: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x8003D7D8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003D7DC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003D7E0: lh          $v1, 0x36($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X36);
    // 0x8003D7E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003D7E8: bgtzl       $v1, L_8003D824
    if (SIGNED(ctx->r3) > 0) {
        // 0x8003D7EC: lh          $v0, 0x90($s0)
        ctx->r2 = MEM_H(ctx->r16, 0X90);
            goto L_8003D824;
    }
    goto skip_0;
    // 0x8003D7EC: lh          $v0, 0x90($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X90);
    skip_0:
    // 0x8003D7F0: jal         0x8003A4E8
    // 0x8003D7F4: nop

    func_8003A4E8(rdram, ctx);
        goto after_0;
    // 0x8003D7F4: nop

    after_0:
    // 0x8003D7F8: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    // 0x8003D7FC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8003D800: jal         0x80043714
    // 0x8003D804: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80043714(rdram, ctx);
        goto after_1;
    // 0x8003D804: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8003D808: jal         0x8003A008
    // 0x8003D80C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003A008(rdram, ctx);
        goto after_2;
    // 0x8003D80C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8003D810: jal         0x80044480
    // 0x8003D814: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80044480(rdram, ctx);
        goto after_3;
    // 0x8003D814: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x8003D818: b           L_8003DAEC
    // 0x8003D81C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8003DAEC;
    // 0x8003D81C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003D820: lh          $v0, 0x90($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X90);
L_8003D824:
    // 0x8003D824: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003D828: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003D82C: beq         $v0, $zero, L_8003D844
    if (ctx->r2 == 0) {
        // 0x8003D830: addiu       $a0, $sp, 0x40
        ctx->r4 = ADD32(ctx->r29, 0X40);
            goto L_8003D844;
    }
    // 0x8003D830: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8003D834: beql        $v0, $at, L_8003D850
    if (ctx->r2 == ctx->r1) {
        // 0x8003D838: lw          $t7, 0x80($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X80);
            goto L_8003D850;
    }
    goto skip_1;
    // 0x8003D838: lw          $t7, 0x80($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X80);
    skip_1:
    // 0x8003D83C: b           L_8003D850
    // 0x8003D840: lw          $t7, 0x80($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X80);
        goto L_8003D850;
    // 0x8003D840: lw          $t7, 0x80($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X80);
L_8003D844:
    // 0x8003D844: sh          $v1, 0x9C($s0)
    MEM_H(0X9C, ctx->r16) = ctx->r3;
    // 0x8003D848: sh          $t6, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r14;
    // 0x8003D84C: lw          $t7, 0x80($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X80);
L_8003D850:
    // 0x8003D850: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    // 0x8003D854: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8003D858: beql        $t8, $zero, L_8003D948
    if (ctx->r24 == 0) {
        // 0x8003D85C: lh          $a1, 0x9C($s0)
        ctx->r5 = MEM_H(ctx->r16, 0X9C);
            goto L_8003D948;
    }
    goto skip_2;
    // 0x8003D85C: lh          $a1, 0x9C($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X9C);
    skip_2:
    // 0x8003D860: sh          $zero, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = 0;
    // 0x8003D864: jal         0x8000D3A4
    // 0x8003D868: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    func_8000D3A4(rdram, ctx);
        goto after_4;
    // 0x8003D868: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_4:
    // 0x8003D86C: lh          $v1, 0x3E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X3E);
    // 0x8003D870: beq         $v0, $zero, L_8003D8B0
    if (ctx->r2 == 0) {
        // 0x8003D874: lw          $a1, 0x30($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X30);
            goto L_8003D8B0;
    }
    // 0x8003D874: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8003D878: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8003D87C: jal         0x80003668
    // 0x8003D880: sh          $v1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r3;
    func_80003668(rdram, ctx);
        goto after_5;
    // 0x8003D880: sh          $v1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r3;
    after_5:
    // 0x8003D884: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x8003D888: lh          $v1, 0x3E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X3E);
    // 0x8003D88C: lh          $t0, 0x14($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X14);
    // 0x8003D890: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8003D894: nop

    // 0x8003D898: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003D89C: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x8003D8A0: nop

    // 0x8003D8A4: bc1f        L_8003D8B0
    if (!c1cs) {
        // 0x8003D8A8: nop
    
            goto L_8003D8B0;
    }
    // 0x8003D8A8: nop

    // 0x8003D8AC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8003D8B0:
    // 0x8003D8B0: bne         $v1, $zero, L_8003D8CC
    if (ctx->r3 != 0) {
        // 0x8003D8B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8003D8CC;
    }
    // 0x8003D8B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003D8B8: jal         0x8003D6D0
    // 0x8003D8BC: sh          $v1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r3;
    func_8003D6D0(rdram, ctx);
        goto after_6;
    // 0x8003D8BC: sh          $v1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r3;
    after_6:
    // 0x8003D8C0: beq         $v0, $zero, L_8003D8CC
    if (ctx->r2 == 0) {
        // 0x8003D8C4: lh          $v1, 0x3E($sp)
        ctx->r3 = MEM_H(ctx->r29, 0X3E);
            goto L_8003D8CC;
    }
    // 0x8003D8C4: lh          $v1, 0x3E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X3E);
    // 0x8003D8C8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8003D8CC:
    // 0x8003D8CC: beq         $v1, $zero, L_8003D920
    if (ctx->r3 == 0) {
        // 0x8003D8D0: lui         $at, 0x3E80
        ctx->r1 = S32(0X3E80 << 16);
            goto L_8003D920;
    }
    // 0x8003D8D0: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8003D8D4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003D8D8: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8003D8DC: addiu       $t1, $zero, 0x32
    ctx->r9 = ADD32(0, 0X32);
    // 0x8003D8E0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003D8E4: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x8003D8E8: nop

    // 0x8003D8EC: bc1tl       L_8003D914
    if (c1cs) {
        // 0x8003D8F0: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_8003D914;
    }
    goto skip_3;
    // 0x8003D8F0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_3:
    // 0x8003D8F4: sh          $t1, 0x9E($s0)
    MEM_H(0X9E, ctx->r16) = ctx->r9;
    // 0x8003D8F8: lwc1        $f12, 0x753C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X753C);
    // 0x8003D8FC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003D900: jal         0x80011534
    // 0x8003D904: lwc1        $f14, 0x7540($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X7540);
    func_80011534(rdram, ctx);
        goto after_7;
    // 0x8003D904: lwc1        $f14, 0x7540($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X7540);
    after_7:
    // 0x8003D908: jal         0x80044480
    // 0x8003D90C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80044480(rdram, ctx);
        goto after_8;
    // 0x8003D90C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
    // 0x8003D910: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_8003D914:
    // 0x8003D914: lh          $v1, 0x36($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X36);
    // 0x8003D918: b           L_8003D944
    // 0x8003D91C: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
        goto L_8003D944;
    // 0x8003D91C: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
L_8003D920:
    // 0x8003D920: lwc1        $f18, 0x48($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8003D924: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003D928: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003D92C: lh          $v1, 0x36($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X36);
    // 0x8003D930: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8003D934: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
    // 0x8003D938: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8003D93C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8003D940: swc1        $f16, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f16.u32l;
L_8003D944:
    // 0x8003D944: lh          $a1, 0x9C($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X9C);
L_8003D948:
    // 0x8003D948: beq         $v1, $a1, L_8003D974
    if (ctx->r3 == ctx->r5) {
        // 0x8003D94C: subu        $t3, $a1, $v1
        ctx->r11 = SUB32(ctx->r5, ctx->r3);
            goto L_8003D974;
    }
    // 0x8003D94C: subu        $t3, $a1, $v1
    ctx->r11 = SUB32(ctx->r5, ctx->r3);
    // 0x8003D950: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8003D954: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8003D958: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x8003D95C: sra         $v0, $t5, 16
    ctx->r2 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8003D960: slti        $a0, $v0, 0xC9
    ctx->r4 = SIGNED(ctx->r2) < 0XC9 ? 1 : 0;
    // 0x8003D964: bne         $a0, $zero, L_8003D970
    if (ctx->r4 != 0) {
        // 0x8003D968: sh          $v1, 0x9C($s0)
        MEM_H(0X9C, ctx->r16) = ctx->r3;
            goto L_8003D970;
    }
    // 0x8003D968: sh          $v1, 0x9C($s0)
    MEM_H(0X9C, ctx->r16) = ctx->r3;
    // 0x8003D96C: addiu       $v0, $zero, 0xC8
    ctx->r2 = ADD32(0, 0XC8);
L_8003D970:
    // 0x8003D970: sh          $v0, 0x9E($s0)
    MEM_H(0X9E, ctx->r16) = ctx->r2;
L_8003D974:
    // 0x8003D974: lh          $t7, 0x9E($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X9E);
    // 0x8003D978: beql        $t7, $zero, L_8003DAC0
    if (ctx->r15 == 0) {
        // 0x8003D97C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8003DAC0;
    }
    goto skip_4;
    // 0x8003D97C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_4:
    // 0x8003D980: jal         0x8004F7C0
    // 0x8003D984: lwc1        $f12, 0xA4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XA4);
    func_8004F7C0(rdram, ctx);
        goto after_9;
    // 0x8003D984: lwc1        $f12, 0xA4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XA4);
    after_9:
    // 0x8003D988: lh          $t8, 0x9E($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X9E);
    // 0x8003D98C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003D990: lwc1        $f6, 0x7544($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7544);
    // 0x8003D994: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8003D998: lwc1        $f12, 0xA8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8003D99C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8003D9A0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8003D9A4: nop

    // 0x8003D9A8: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8003D9AC: jal         0x8004F7C0
    // 0x8003D9B0: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    func_8004F7C0(rdram, ctx);
        goto after_10;
    // 0x8003D9B0: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    after_10:
    // 0x8003D9B4: lh          $t9, 0x9E($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X9E);
    // 0x8003D9B8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003D9BC: lwc1        $f4, 0x7548($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7548);
    // 0x8003D9C0: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8003D9C4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003D9C8: lwc1        $f10, 0xA4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x8003D9CC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003D9D0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8003D9D4: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x8003D9D8: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    // 0x8003D9DC: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8003D9E0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8003D9E4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8003D9E8: lwc1        $f4, 0xA8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8003D9EC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8003D9F0: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    // 0x8003D9F4: lwc1        $f16, 0x754C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X754C);
    // 0x8003D9F8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003D9FC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8003DA00: swc1        $f18, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f18.u32l;
    // 0x8003DA04: lwc1        $f6, 0x7550($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7550);
    // 0x8003DA08: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003DA0C: swc1        $f8, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f8.u32l;
    // 0x8003DA10: jal         0x80049840
    // 0x8003DA14: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    func_80049840(rdram, ctx);
        goto after_11;
    // 0x8003DA14: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_11:
    // 0x8003DA18: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003DA1C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003DA20: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003DA24: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    // 0x8003DA28: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003DA2C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003DA30: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x8003DA34: jal         0x80049840
    // 0x8003DA38: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_80049840(rdram, ctx);
        goto after_12;
    // 0x8003DA38: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_12:
    // 0x8003DA3C: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    // 0x8003DA40: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8003DA44: jal         0x80000BD8
    // 0x8003DA48: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    func_80000BD8(rdram, ctx);
        goto after_13;
    // 0x8003DA48: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    after_13:
    // 0x8003DA4C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003DA50: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    // 0x8003DA54: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x8003DA58: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8003DA5C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8003DA60: jal         0x80049840
    // 0x8003DA64: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_80049840(rdram, ctx);
        goto after_14;
    // 0x8003DA64: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_14:
    // 0x8003DA68: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    // 0x8003DA6C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8003DA70: jal         0x80000BD8
    // 0x8003DA74: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    func_80000BD8(rdram, ctx);
        goto after_15;
    // 0x8003DA74: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    after_15:
    // 0x8003DA78: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8003DA7C: lw          $t0, 0xC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XC);
    // 0x8003DA80: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003DA84: lw          $a0, 0x8($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X8);
    // 0x8003DA88: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003DA8C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003DA90: jal         0x80001AB4
    // 0x8003DA94: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80001AB4(rdram, ctx);
        goto after_16;
    // 0x8003DA94: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_16:
    // 0x8003DA98: lw          $t1, 0xC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XC);
    // 0x8003DA9C: addiu       $a2, $sp, 0x8C
    ctx->r6 = ADD32(ctx->r29, 0X8C);
    // 0x8003DAA0: lw          $a0, 0x8($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X8);
    // 0x8003DAA4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8003DAA8: jal         0x80000BD8
    // 0x8003DAAC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_80000BD8(rdram, ctx);
        goto after_17;
    // 0x8003DAAC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_17:
    // 0x8003DAB0: lh          $t2, 0x9E($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9E);
    // 0x8003DAB4: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8003DAB8: sh          $t3, 0x9E($s0)
    MEM_H(0X9E, ctx->r16) = ctx->r11;
    // 0x8003DABC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003DAC0:
    // 0x8003DAC0: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8003DAC4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
L_8003DAC8:
    // 0x8003DAC8: lw          $t4, 0xC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XC);
    // 0x8003DACC: lwc1        $f18, 0x10($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8003DAD0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003DAD4: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x8003DAD8: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8003DADC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003DAE0: bne         $v0, $a0, L_8003DAC8
    if (ctx->r2 != ctx->r4) {
        // 0x8003DAE4: swc1        $f18, 0x40($t6)
        MEM_W(0X40, ctx->r14) = ctx->f18.u32l;
            goto L_8003DAC8;
    }
    // 0x8003DAE4: swc1        $f18, 0x40($t6)
    MEM_W(0X40, ctx->r14) = ctx->f18.u32l;
    // 0x8003DAE8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003DAEC:
    // 0x8003DAEC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003DAF0: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    // 0x8003DAF4: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8003DAFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8003DAFC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8003DB00: lw          $t6, -0x6630($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6630);
    // 0x8003DB04: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003DB08: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8003DB0C: bne         $t6, $at, L_8003DB80
    if (ctx->r14 != ctx->r1) {
        // 0x8003DB10: lui         $at, 0x43BE
        ctx->r1 = S32(0X43BE << 16);
            goto L_8003DB80;
    }
    // 0x8003DB10: lui         $at, 0x43BE
    ctx->r1 = S32(0X43BE << 16);
    // 0x8003DB14: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003DB18: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8003DB1C: lui         $at, 0x445C
    ctx->r1 = S32(0X445C << 16);
    // 0x8003DB20: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8003DB24: nop

    // 0x8003DB28: bc1f        L_8003DB80
    if (!c1cs) {
        // 0x8003DB2C: nop
    
            goto L_8003DB80;
    }
    // 0x8003DB2C: nop

    // 0x8003DB30: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003DB34: lui         $at, 0xC457
    ctx->r1 = S32(0XC457 << 16);
    // 0x8003DB38: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8003DB3C: nop

    // 0x8003DB40: bc1f        L_8003DB80
    if (!c1cs) {
        // 0x8003DB44: nop
    
            goto L_8003DB80;
    }
    // 0x8003DB44: nop

    // 0x8003DB48: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8003DB4C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003DB50: lui         $at, 0xC3C8
    ctx->r1 = S32(0XC3C8 << 16);
    // 0x8003DB54: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8003DB58: nop

    // 0x8003DB5C: bc1f        L_8003DB80
    if (!c1cs) {
        // 0x8003DB60: nop
    
            goto L_8003DB80;
    }
    // 0x8003DB60: nop

    // 0x8003DB64: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003DB68: nop

    // 0x8003DB6C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8003DB70: nop

    // 0x8003DB74: bc1f        L_8003DB80
    if (!c1cs) {
        // 0x8003DB78: nop
    
            goto L_8003DB80;
    }
    // 0x8003DB78: nop

    // 0x8003DB7C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8003DB80:
    // 0x8003DB80: jr          $ra
    // 0x8003DB84: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    TRACE_RETURN()
    return;
    // 0x8003DB84: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8003DB88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8003DB88: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x8003DB8C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003DB90: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003DB94: sw          $a1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r5;
    // 0x8003DB98: lh          $v0, 0x90($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X90);
    // 0x8003DB9C: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x8003DBA0: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8003DBA4: beq         $v0, $zero, L_8003DBC8
    if (ctx->r2 == 0) {
        // 0x8003DBA8: or          $s0, $a0, $zero
        ctx->r16 = ctx->r4 | 0;
            goto L_8003DBC8;
    }
    // 0x8003DBA8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003DBAC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8003DBB0: beq         $v0, $v1, L_8003DC40
    if (ctx->r2 == ctx->r3) {
        // 0x8003DBB4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8003DC40;
    }
    // 0x8003DBB4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003DBB8: beq         $v0, $at, L_8003DC2C
    if (ctx->r2 == ctx->r1) {
        // 0x8003DBBC: nop
    
            goto L_8003DC2C;
    }
    // 0x8003DBBC: nop

    // 0x8003DBC0: b           L_8003DC44
    // 0x8003DBC4: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
        goto L_8003DC44;
    // 0x8003DBC4: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
L_8003DBC8:
    // 0x8003DBC8: beq         $a1, $zero, L_8003DBE4
    if (ctx->r5 == 0) {
        // 0x8003DBCC: addiu       $v0, $zero, 0x14
        ctx->r2 = ADD32(0, 0X14);
            goto L_8003DBE4;
    }
    // 0x8003DBCC: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x8003DBD0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8003DBD4: beq         $a1, $v1, L_8003DBFC
    if (ctx->r5 == ctx->r3) {
        // 0x8003DBD8: addiu       $t9, $zero, 0x64
        ctx->r25 = ADD32(0, 0X64);
            goto L_8003DBFC;
    }
    // 0x8003DBD8: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x8003DBDC: b           L_8003DC0C
    // 0x8003DBE0: nop

        goto L_8003DC0C;
    // 0x8003DBE0: nop

L_8003DBE4:
    // 0x8003DBE4: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8003DBE8: sh          $t8, 0x9C($s0)
    MEM_H(0X9C, ctx->r16) = ctx->r24;
    // 0x8003DBEC: sh          $v0, 0x9E($s0)
    MEM_H(0X9E, ctx->r16) = ctx->r2;
    // 0x8003DBF0: sh          $v0, 0xA0($s0)
    MEM_H(0XA0, ctx->r16) = ctx->r2;
    // 0x8003DBF4: b           L_8003DC0C
    // 0x8003DBF8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8003DC0C;
    // 0x8003DBF8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8003DBFC:
    // 0x8003DBFC: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8003DC00: sh          $v1, 0x9C($s0)
    MEM_H(0X9C, ctx->r16) = ctx->r3;
    // 0x8003DC04: sh          $t9, 0x9E($s0)
    MEM_H(0X9E, ctx->r16) = ctx->r25;
    // 0x8003DC08: sh          $t0, 0xA0($s0)
    MEM_H(0XA0, ctx->r16) = ctx->r8;
L_8003DC0C:
    // 0x8003DC0C: bne         $a1, $zero, L_8003DC40
    if (ctx->r5 != 0) {
        // 0x8003DC10: sh          $v1, 0x90($s0)
        MEM_H(0X90, ctx->r16) = ctx->r3;
            goto L_8003DC40;
    }
    // 0x8003DC10: sh          $v1, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r3;
    // 0x8003DC14: jal         0x8003DAFC
    // 0x8003DC18: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    func_8003DAFC(rdram, ctx);
        goto after_0;
    // 0x8003DC18: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    after_0:
    // 0x8003DC1C: beq         $v0, $zero, L_8003DC40
    if (ctx->r2 == 0) {
        // 0x8003DC20: addiu       $t1, $zero, 0x2
        ctx->r9 = ADD32(0, 0X2);
            goto L_8003DC40;
    }
    // 0x8003DC20: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8003DC24: b           L_8003DC40
    // 0x8003DC28: sh          $t1, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r9;
        goto L_8003DC40;
    // 0x8003DC28: sh          $t1, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r9;
L_8003DC2C:
    // 0x8003DC2C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8003DC30: sh          $v1, -0x6B9C($at)
    MEM_H(-0X6B9C, ctx->r1) = ctx->r3;
    // 0x8003DC34: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003DC38: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8003DC3C: swc1        $f4, -0x6B98($at)
    MEM_W(-0X6B98, ctx->r1) = ctx->f4.u32l;
L_8003DC40:
    // 0x8003DC40: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
L_8003DC44:
    // 0x8003DC44: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003DC48: lwc1        $f2, 0x7554($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7554);
    // 0x8003DC4C: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x8003DC50: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003DC54: lwc1        $f10, 0x7558($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7558);
    // 0x8003DC58: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8003DC5C: lwc1        $f8, 0xA4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x8003DC60: lh          $t3, 0xA0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XA0);
    // 0x8003DC64: lwc1        $f4, 0xAC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XAC);
    // 0x8003DC68: div.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8003DC6C: div.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8003DC70: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8003DC74: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8003DC78: lwc1        $f8, 0xA8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8003DC7C: swc1        $f18, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f18.u32l;
    // 0x8003DC80: lwc1        $f12, 0xA4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x8003DC84: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003DC88: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003DC8C: div.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8003DC90: swc1        $f10, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->f10.u32l;
    // 0x8003DC94: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8003DC98: jal         0x8004F7C0
    // 0x8003DC9C: swc1        $f6, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f6.u32l;
    func_8004F7C0(rdram, ctx);
        goto after_1;
    // 0x8003DC9C: swc1        $f6, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f6.u32l;
    after_1:
    // 0x8003DCA0: lh          $t4, 0x9E($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X9E);
    // 0x8003DCA4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003DCA8: lwc1        $f18, 0x755C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X755C);
    // 0x8003DCAC: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8003DCB0: lwc1        $f12, 0xA8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8003DCB4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8003DCB8: mul.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8003DCBC: nop

    // 0x8003DCC0: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8003DCC4: jal         0x8004F7C0
    // 0x8003DCC8: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    func_8004F7C0(rdram, ctx);
        goto after_2;
    // 0x8003DCC8: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x8003DCCC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003DCD0: lwc1        $f6, 0x7560($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7560);
    // 0x8003DCD4: lwc1        $f12, 0xAC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XAC);
    // 0x8003DCD8: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8003DCDC: jal         0x8004F7C0
    // 0x8003DCE0: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
    func_8004F7C0(rdram, ctx);
        goto after_3;
    // 0x8003DCE0: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
    after_3:
    // 0x8003DCE4: lh          $t5, 0x9E($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X9E);
    // 0x8003DCE8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003DCEC: lwc1        $f8, 0x7564($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7564);
    // 0x8003DCF0: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x8003DCF4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8003DCF8: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x8003DCFC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003DD00: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8003DD04: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x8003DD08: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8003DD0C: mul.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8003DD10: nop

    // 0x8003DD14: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8003DD18: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x8003DD1C: jal         0x80049840
    // 0x8003DD20: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    func_80049840(rdram, ctx);
        goto after_4;
    // 0x8003DD20: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_4:
    // 0x8003DD24: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003DD28: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003DD2C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003DD30: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    // 0x8003DD34: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003DD38: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003DD3C: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x8003DD40: jal         0x80049840
    // 0x8003DD44: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_80049840(rdram, ctx);
        goto after_5;
    // 0x8003DD44: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x8003DD48: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x8003DD4C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8003DD50: jal         0x80000BD8
    // 0x8003DD54: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    func_80000BD8(rdram, ctx);
        goto after_6;
    // 0x8003DD54: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_6:
    // 0x8003DD58: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003DD5C: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    // 0x8003DD60: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x8003DD64: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003DD68: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8003DD6C: jal         0x80049840
    // 0x8003DD70: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80049840(rdram, ctx);
        goto after_7;
    // 0x8003DD70: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x8003DD74: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x8003DD78: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8003DD7C: jal         0x80000BD8
    // 0x8003DD80: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    func_80000BD8(rdram, ctx);
        goto after_8;
    // 0x8003DD80: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_8:
    // 0x8003DD84: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8003DD88: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x8003DD8C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003DD90: lw          $a0, 0x8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X8);
    // 0x8003DD94: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003DD98: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003DD9C: jal         0x80001AB4
    // 0x8003DDA0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80001AB4(rdram, ctx);
        goto after_9;
    // 0x8003DDA0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_9:
    // 0x8003DDA4: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x8003DDA8: addiu       $a2, $sp, 0x7C
    ctx->r6 = ADD32(ctx->r29, 0X7C);
    // 0x8003DDAC: lw          $a0, 0x8($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X8);
    // 0x8003DDB0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8003DDB4: jal         0x80000BD8
    // 0x8003DDB8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_80000BD8(rdram, ctx);
        goto after_10;
    // 0x8003DDB8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_10:
    // 0x8003DDBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003DDC0: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8003DDC4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
L_8003DDC8:
    // 0x8003DDC8: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x8003DDCC: lwc1        $f16, 0x10($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8003DDD0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003DDD4: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x8003DDD8: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x8003DDDC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003DDE0: bne         $v0, $a0, L_8003DDC8
    if (ctx->r2 != ctx->r4) {
        // 0x8003DDE4: swc1        $f16, 0x40($t0)
        MEM_W(0X40, ctx->r8) = ctx->f16.u32l;
            goto L_8003DDC8;
    }
    // 0x8003DDE4: swc1        $f16, 0x40($t0)
    MEM_W(0X40, ctx->r8) = ctx->f16.u32l;
    // 0x8003DDE8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003DDEC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003DDF0: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    // 0x8003DDF4: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8003DDFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8003DDFC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003DE00: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8003DE04: sh          $t6, -0x6B9C($at)
    MEM_H(-0X6B9C, ctx->r1) = ctx->r14;
    // 0x8003DE08: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8003DE0C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8003DE10: addiu       $t7, $zero, 0x63
    ctx->r15 = ADD32(0, 0X63);
    // 0x8003DE14: swc1        $f4, -0x6B98($at)
    MEM_W(-0X6B98, ctx->r1) = ctx->f4.u32l;
    // 0x8003DE18: jr          $ra
    // 0x8003DE1C: sh          $t7, 0x8E($a0)
    MEM_H(0X8E, ctx->r4) = ctx->r15;
    TRACE_RETURN()
    return;
    // 0x8003DE1C: sh          $t7, 0x8E($a0)
    MEM_H(0X8E, ctx->r4) = ctx->r15;
;}
