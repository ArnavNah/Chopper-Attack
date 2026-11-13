#include "recomp.h"
#include "trace.h"
#include "funcs.h"

RECOMP_FUNC void func_8001F704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8001F704: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x8001F708: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8001F70C: lw          $t6, -0x65A0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X65A0);
    // 0x8001F710: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8001F714: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8001F718: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8001F71C: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8001F720: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8001F724: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8001F728: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8001F72C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8001F730: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8001F734: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8001F738: lw          $s1, 0x0($t6)
    ctx->r17 = MEM_W(ctx->r14, 0X0);
    // 0x8001F73C: addiu       $s3, $sp, 0xAC
    ctx->r19 = ADD32(ctx->r29, 0XAC);
    // 0x8001F740: addiu       $s5, $sp, 0xA0
    ctx->r21 = ADD32(ctx->r29, 0XA0);
    // 0x8001F744: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8001F748: addiu       $s6, $sp, 0x60
    ctx->r22 = ADD32(ctx->r29, 0X60);
    // 0x8001F74C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001F750: beql        $v1, $zero, L_8001F984
    if (ctx->r3 == 0) {
        // 0x8001F754: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_8001F984;
    }
    goto skip_0;
    // 0x8001F754: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_0:
    // 0x8001F758: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8001F75C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8001F760: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x8001F764: lh          $t7, 0x36($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X36);
L_8001F768:
    // 0x8001F768: blezl       $t7, L_8001F974
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8001F76C: or          $s1, $v1, $zero
        ctx->r17 = ctx->r3 | 0;
            goto L_8001F974;
    }
    goto skip_1;
    // 0x8001F76C: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    skip_1:
    // 0x8001F770: lh          $v0, 0x34($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X34);
    // 0x8001F774: beql        $v0, $zero, L_8001F974
    if (ctx->r2 == 0) {
        // 0x8001F778: or          $s1, $v1, $zero
        ctx->r17 = ctx->r3 | 0;
            goto L_8001F974;
    }
    goto skip_2;
    // 0x8001F778: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    skip_2:
    // 0x8001F77C: blez        $v0, L_8001F970
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001F780: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8001F970;
    }
    // 0x8001F780: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001F784: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8001F788: lw          $t8, 0x30($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X30);
L_8001F78C:
    // 0x8001F78C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001F790: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x8001F794: addu        $t9, $t8, $s4
    ctx->r25 = ADD32(ctx->r24, ctx->r20);
    // 0x8001F798: lh          $a2, 0x0($t9)
    ctx->r6 = MEM_H(ctx->r25, 0X0);
L_8001F79C:
    // 0x8001F79C: lw          $t0, 0x30($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X30);
    // 0x8001F7A0: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    // 0x8001F7A4: subu        $t1, $t1, $s0
    ctx->r9 = SUB32(ctx->r9, ctx->r16);
    // 0x8001F7A8: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8001F7AC: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8001F7B0: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x8001F7B4: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8001F7B8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001F7BC: slti        $at, $v0, 0xC
    ctx->r1 = SIGNED(ctx->r2) < 0XC ? 1 : 0;
    // 0x8001F7C0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8001F7C4: bne         $at, $zero, L_8001F79C
    if (ctx->r1 != 0) {
        // 0x8001F7C8: swc1        $f4, 0x8($t3)
        MEM_W(0X8, ctx->r11) = ctx->f4.u32l;
            goto L_8001F79C;
    }
    // 0x8001F7C8: swc1        $f4, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f4.u32l;
    // 0x8001F7CC: andi        $t4, $a2, 0x20
    ctx->r12 = ctx->r6 & 0X20;
    // 0x8001F7D0: beq         $t4, $zero, L_8001F848
    if (ctx->r12 == 0) {
        // 0x8001F7D4: andi        $t6, $a2, 0x40
        ctx->r14 = ctx->r6 & 0X40;
            goto L_8001F848;
    }
    // 0x8001F7D4: andi        $t6, $a2, 0x40
    ctx->r14 = ctx->r6 & 0X40;
    // 0x8001F7D8: sll         $a0, $a2, 16
    ctx->r4 = S32(ctx->r6 << 16);
    // 0x8001F7DC: sra         $t5, $a0, 16
    ctx->r13 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001F7E0: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x8001F7E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8001F7E8:
    // 0x8001F7E8: andi        $t6, $a0, 0x4
    ctx->r14 = ctx->r4 & 0X4;
    // 0x8001F7EC: beq         $t6, $zero, L_8001F830
    if (ctx->r14 == 0) {
        // 0x8001F7F0: or          $t3, $a0, $zero
        ctx->r11 = ctx->r4 | 0;
            goto L_8001F830;
    }
    // 0x8001F7F0: or          $t3, $a0, $zero
    ctx->r11 = ctx->r4 | 0;
    // 0x8001F7F4: lw          $t7, 0x30($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X30);
    // 0x8001F7F8: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x8001F7FC: subu        $t8, $t8, $s0
    ctx->r24 = SUB32(ctx->r24, ctx->r16);
    // 0x8001F800: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8001F804: sll         $t0, $a1, 1
    ctx->r8 = S32(ctx->r5 << 1);
    // 0x8001F808: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8001F80C: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x8001F810: lh          $t2, 0x2($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X2);
    // 0x8001F814: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8001F818: addu        $v1, $v0, $t9
    ctx->r3 = ADD32(ctx->r2, ctx->r25);
    // 0x8001F81C: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8001F820: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8001F824: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001F828: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8001F82C: swc1        $f16, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f16.u32l;
L_8001F830:
    // 0x8001F830: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001F834: sll         $t4, $t3, 17
    ctx->r12 = S32(ctx->r11 << 17);
    // 0x8001F838: bne         $a1, $s2, L_8001F7E8
    if (ctx->r5 != ctx->r18) {
        // 0x8001F83C: sra         $a0, $t4, 16
        ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
            goto L_8001F7E8;
    }
    // 0x8001F83C: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8001F840: b           L_8001F958
    // 0x8001F844: lh          $t4, 0x34($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X34);
        goto L_8001F958;
    // 0x8001F844: lh          $t4, 0x34($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X34);
L_8001F848:
    // 0x8001F848: beql        $t6, $zero, L_8001F958
    if (ctx->r14 == 0) {
        // 0x8001F84C: lh          $t4, 0x34($s1)
        ctx->r12 = MEM_H(ctx->r17, 0X34);
            goto L_8001F958;
    }
    goto skip_3;
    // 0x8001F84C: lh          $t4, 0x34($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X34);
    skip_3:
    // 0x8001F850: lw          $t7, 0x30($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X30);
    // 0x8001F854: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8001F858: addu        $v0, $t7, $s4
    ctx->r2 = ADD32(ctx->r15, ctx->r20);
    // 0x8001F85C: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x8001F860: lh          $t9, 0x4($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X4);
    // 0x8001F864: lh          $t0, 0x6($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X6);
    // 0x8001F868: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8001F86C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8001F870: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8001F874: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001F878: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001F87C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8001F880: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001F884: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8001F888: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8001F88C: jal         0x80001A6C
    // 0x8001F890: nop

    func_80001A6C(rdram, ctx);
        goto after_0;
    // 0x8001F890: nop

    after_0:
    // 0x8001F894: lw          $a1, 0x1C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1C);
    // 0x8001F898: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8001F89C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8001F8A0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8001F8A4: jal         0x80049840
    // 0x8001F8A8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_80049840(rdram, ctx);
        goto after_1;
    // 0x8001F8A8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_1:
    // 0x8001F8AC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8001F8B0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8001F8B4: jal         0x80000BD8
    // 0x8001F8B8: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_80000BD8(rdram, ctx);
        goto after_2;
    // 0x8001F8B8: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_2:
    // 0x8001F8BC: lw          $a1, 0x20($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X20);
    // 0x8001F8C0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8001F8C4: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8001F8C8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8001F8CC: jal         0x80049840
    // 0x8001F8D0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_80049840(rdram, ctx);
        goto after_3;
    // 0x8001F8D0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_3:
    // 0x8001F8D4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8001F8D8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8001F8DC: jal         0x80000BD8
    // 0x8001F8E0: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_80000BD8(rdram, ctx);
        goto after_4;
    // 0x8001F8E0: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_4:
    // 0x8001F8E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001F8E8: addiu       $a0, $sp, 0xA0
    ctx->r4 = ADD32(ctx->r29, 0XA0);
    // 0x8001F8EC: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x8001F8F0: subu        $t2, $t2, $s0
    ctx->r10 = SUB32(ctx->r10, ctx->r16);
    // 0x8001F8F4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8001F8F8: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8001F8FC: beq         $a0, $s3, L_8001F938
    if (ctx->r4 == ctx->r19) {
        // 0x8001F900: lw          $t1, 0x30($s1)
        ctx->r9 = MEM_W(ctx->r17, 0X30);
            goto L_8001F938;
    }
    // 0x8001F900: lw          $t1, 0x30($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X30);
L_8001F904:
    // 0x8001F904: lwc1        $f18, 0x2C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x8001F908: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8001F90C: addu        $v1, $t3, $v0
    ctx->r3 = ADD32(ctx->r11, ctx->r2);
    // 0x8001F910: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8001F914: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x8001F918: subu        $t2, $t2, $s0
    ctx->r10 = SUB32(ctx->r10, ctx->r16);
    // 0x8001F91C: add.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8001F920: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8001F924: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001F928: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8001F92C: swc1        $f18, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f18.u32l;
    // 0x8001F930: bne         $a0, $s3, L_8001F904
    if (ctx->r4 != ctx->r19) {
        // 0x8001F934: lw          $t1, 0x30($s1)
        ctx->r9 = MEM_W(ctx->r17, 0X30);
            goto L_8001F904;
    }
    // 0x8001F934: lw          $t1, 0x30($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X30);
L_8001F938:
    // 0x8001F938: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8001F93C: addu        $v1, $t3, $v0
    ctx->r3 = ADD32(ctx->r11, ctx->r2);
    // 0x8001F940: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8001F944: lwc1        $f18, 0x2C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x8001F948: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001F94C: add.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8001F950: swc1        $f18, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f18.u32l;
    // 0x8001F954: lh          $t4, 0x34($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X34);
L_8001F958:
    // 0x8001F958: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001F95C: addiu       $s4, $s4, 0x18
    ctx->r20 = ADD32(ctx->r20, 0X18);
    // 0x8001F960: slt         $at, $s0, $t4
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8001F964: bnel        $at, $zero, L_8001F78C
    if (ctx->r1 != 0) {
        // 0x8001F968: lw          $t8, 0x30($s1)
        ctx->r24 = MEM_W(ctx->r17, 0X30);
            goto L_8001F78C;
    }
    goto skip_4;
    // 0x8001F968: lw          $t8, 0x30($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X30);
    skip_4:
    // 0x8001F96C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
L_8001F970:
    // 0x8001F970: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
L_8001F974:
    // 0x8001F974: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8001F978: bnel        $v1, $zero, L_8001F768
    if (ctx->r3 != 0) {
        // 0x8001F97C: lh          $t7, 0x36($s1)
        ctx->r15 = MEM_H(ctx->r17, 0X36);
            goto L_8001F768;
    }
    goto skip_5;
    // 0x8001F97C: lh          $t7, 0x36($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X36);
    skip_5:
    // 0x8001F980: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_8001F984:
    // 0x8001F984: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8001F988: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8001F98C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8001F990: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8001F994: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8001F998: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8001F99C: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8001F9A0: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8001F9A4: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8001F9A8: jr          $ra
    // 0x8001F9AC: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    TRACE_RETURN()
    return;
    // 0x8001F9AC: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
;}
RECOMP_FUNC void func_8001F9B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8001F9B0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001F9B4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8001F9B8: lw          $t6, -0x65A0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X65A0);
    // 0x8001F9BC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8001F9C0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001F9C4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001F9C8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001F9CC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001F9D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001F9D4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8001F9D8: lw          $s3, 0x0($t6)
    ctx->r19 = MEM_W(ctx->r14, 0X0);
    // 0x8001F9DC: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8001F9E0: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x8001F9E4: beql        $v1, $zero, L_8001FA94
    if (ctx->r3 == 0) {
        // 0x8001F9E8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8001FA94;
    }
    goto skip_0;
    // 0x8001F9E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8001F9EC: lh          $t7, 0x36($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X36);
L_8001F9F0:
    // 0x8001F9F0: blezl       $t7, L_8001FA84
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8001F9F4: or          $s3, $v1, $zero
        ctx->r19 = ctx->r3 | 0;
            goto L_8001FA84;
    }
    goto skip_1;
    // 0x8001F9F4: or          $s3, $v1, $zero
    ctx->r19 = ctx->r3 | 0;
    skip_1:
    // 0x8001F9F8: lh          $v0, 0x34($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X34);
    // 0x8001F9FC: beql        $v0, $zero, L_8001FA84
    if (ctx->r2 == 0) {
        // 0x8001FA00: or          $s3, $v1, $zero
        ctx->r19 = ctx->r3 | 0;
            goto L_8001FA84;
    }
    goto skip_2;
    // 0x8001FA00: or          $s3, $v1, $zero
    ctx->r19 = ctx->r3 | 0;
    skip_2:
    // 0x8001FA04: blez        $v0, L_8001FA80
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001FA08: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8001FA80;
    }
    // 0x8001FA08: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001FA0C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8001FA10: lw          $s0, 0x30($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X30);
L_8001FA14:
    // 0x8001FA14: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8001FA18: jal         0x80003668
    // 0x8001FA1C: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    func_80003668(rdram, ctx);
        goto after_0;
    // 0x8001FA1C: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    after_0:
    // 0x8001FA20: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001FA24: lw          $t8, 0x30($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X30);
    // 0x8001FA28: addu        $s0, $t8, $s2
    ctx->r16 = ADD32(ctx->r24, ctx->r18);
    // 0x8001FA2C: lh          $t1, 0x14($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X14);
    // 0x8001FA30: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x8001FA34: nop

    // 0x8001FA38: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8001FA3C: beql        $at, $zero, L_8001FA68
    if (ctx->r1 == 0) {
        // 0x8001FA40: lh          $t4, 0x34($s3)
        ctx->r12 = MEM_H(ctx->r19, 0X34);
            goto L_8001FA68;
    }
    goto skip_3;
    // 0x8001FA40: lh          $t4, 0x34($s3)
    ctx->r12 = MEM_H(ctx->r19, 0X34);
    skip_3:
    // 0x8001FA44: lh          $v0, 0x36($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X36);
    // 0x8001FA48: lh          $t2, 0x36($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X36);
    // 0x8001FA4C: addiu       $at, $zero, 0x7530
    ctx->r1 = ADD32(0, 0X7530);
    // 0x8001FA50: beq         $v0, $at, L_8001FA5C
    if (ctx->r2 == ctx->r1) {
        // 0x8001FA54: subu        $t3, $v0, $t2
        ctx->r11 = SUB32(ctx->r2, ctx->r10);
            goto L_8001FA5C;
    }
    // 0x8001FA54: subu        $t3, $v0, $t2
    ctx->r11 = SUB32(ctx->r2, ctx->r10);
    // 0x8001FA58: sh          $t3, 0x36($s3)
    MEM_H(0X36, ctx->r19) = ctx->r11;
L_8001FA5C:
    // 0x8001FA5C: b           L_8001FA94
    // 0x8001FA60: lh          $v0, 0x3C($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X3C);
        goto L_8001FA94;
    // 0x8001FA60: lh          $v0, 0x3C($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X3C);
    // 0x8001FA64: lh          $t4, 0x34($s3)
    ctx->r12 = MEM_H(ctx->r19, 0X34);
L_8001FA68:
    // 0x8001FA68: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8001FA6C: addiu       $s2, $s2, 0x18
    ctx->r18 = ADD32(ctx->r18, 0X18);
    // 0x8001FA70: slt         $at, $s1, $t4
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8001FA74: bne         $at, $zero, L_8001FA14
    if (ctx->r1 != 0) {
        // 0x8001FA78: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_8001FA14;
    }
    // 0x8001FA78: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x8001FA7C: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
L_8001FA80:
    // 0x8001FA80: or          $s3, $v1, $zero
    ctx->r19 = ctx->r3 | 0;
L_8001FA84:
    // 0x8001FA84: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8001FA88: bnel        $v1, $zero, L_8001F9F0
    if (ctx->r3 != 0) {
        // 0x8001FA8C: lh          $t7, 0x36($s3)
        ctx->r15 = MEM_H(ctx->r19, 0X36);
            goto L_8001F9F0;
    }
    goto skip_4;
    // 0x8001FA8C: lh          $t7, 0x36($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X36);
    skip_4:
    // 0x8001FA90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001FA94:
    // 0x8001FA94: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8001FA98: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001FA9C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001FAA0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001FAA4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001FAA8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001FAAC: jr          $ra
    // 0x8001FAB0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    TRACE_RETURN()
    return;
    // 0x8001FAB0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8001FAB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8001FAB4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001FAB8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8001FABC: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8001FAC0: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8001FAC4: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8001FAC8: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x8001FACC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8001FAD0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8001FAD4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8001FAD8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001FADC: jal         0x8001F704
    // 0x8001FAE0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    func_8001F704(rdram, ctx);
        goto after_0;
    // 0x8001FAE0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x8001FAE4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8001FAE8: lw          $t6, -0x65A0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X65A0);
    // 0x8001FAEC: lw          $s3, 0x0($t6)
    ctx->r19 = MEM_W(ctx->r14, 0X0);
    // 0x8001FAF0: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x8001FAF4: beql        $v1, $zero, L_8001FBEC
    if (ctx->r3 == 0) {
        // 0x8001FAF8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8001FBEC;
    }
    goto skip_0;
    // 0x8001FAF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8001FAFC: lh          $t7, 0x36($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X36);
L_8001FB00:
    // 0x8001FB00: blezl       $t7, L_8001FBDC
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8001FB04: or          $s3, $v1, $zero
        ctx->r19 = ctx->r3 | 0;
            goto L_8001FBDC;
    }
    goto skip_1;
    // 0x8001FB04: or          $s3, $v1, $zero
    ctx->r19 = ctx->r3 | 0;
    skip_1:
    // 0x8001FB08: lh          $t8, 0x92($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X92);
    // 0x8001FB0C: andi        $t9, $t8, 0x8
    ctx->r25 = ctx->r24 & 0X8;
    // 0x8001FB10: beql        $t9, $zero, L_8001FBDC
    if (ctx->r25 == 0) {
        // 0x8001FB14: or          $s3, $v1, $zero
        ctx->r19 = ctx->r3 | 0;
            goto L_8001FBDC;
    }
    goto skip_2;
    // 0x8001FB14: or          $s3, $v1, $zero
    ctx->r19 = ctx->r3 | 0;
    skip_2:
    // 0x8001FB18: lh          $v0, 0x34($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X34);
    // 0x8001FB1C: beql        $v0, $zero, L_8001FBDC
    if (ctx->r2 == 0) {
        // 0x8001FB20: or          $s3, $v1, $zero
        ctx->r19 = ctx->r3 | 0;
            goto L_8001FBDC;
    }
    goto skip_3;
    // 0x8001FB20: or          $s3, $v1, $zero
    ctx->r19 = ctx->r3 | 0;
    skip_3:
    // 0x8001FB24: blez        $v0, L_8001FBD8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001FB28: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8001FBD8;
    }
    // 0x8001FB28: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001FB2C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8001FB30: lw          $s0, 0x30($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X30);
L_8001FB34:
    // 0x8001FB34: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8001FB38: jal         0x80003668
    // 0x8001FB3C: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    func_80003668(rdram, ctx);
        goto after_1;
    // 0x8001FB3C: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    after_1:
    // 0x8001FB40: lw          $t0, 0x30($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X30);
    // 0x8001FB44: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001FB48: lh          $t2, 0xE0($s5)
    ctx->r10 = MEM_H(ctx->r21, 0XE0);
    // 0x8001FB4C: addu        $s0, $t0, $s2
    ctx->r16 = ADD32(ctx->r8, ctx->r18);
    // 0x8001FB50: lh          $t1, 0x14($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X14);
    // 0x8001FB54: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x8001FB58: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8001FB5C: slt         $at, $t3, $t5
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8001FB60: bnel        $at, $zero, L_8001FBC0
    if (ctx->r1 != 0) {
        // 0x8001FB64: lh          $t1, 0x34($s3)
        ctx->r9 = MEM_H(ctx->r19, 0X34);
            goto L_8001FBC0;
    }
    goto skip_4;
    // 0x8001FB64: lh          $t1, 0x34($s3)
    ctx->r9 = MEM_H(ctx->r19, 0X34);
    skip_4:
    // 0x8001FB68: lh          $t6, 0x8E($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X8E);
    // 0x8001FB6C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8001FB70: bne         $t6, $at, L_8001FBB4
    if (ctx->r14 != ctx->r1) {
        // 0x8001FB74: nop
    
            goto L_8001FBB4;
    }
    // 0x8001FB74: nop

    // 0x8001FB78: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8001FB7C: lwc1        $f8, 0x48($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X48);
    // 0x8001FB80: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8001FB84: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x8001FB88: nop

    // 0x8001FB8C: bc1t        L_8001FBB4
    if (c1cs) {
        // 0x8001FB90: nop
    
            goto L_8001FBB4;
    }
    // 0x8001FB90: nop

    // 0x8001FB94: lw          $t7, -0x6BE0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6BE0);
    // 0x8001FB98: andi        $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 & 0X8000;
    // 0x8001FB9C: bnel        $t8, $zero, L_8001FBB4
    if (ctx->r24 != 0) {
        // 0x8001FBA0: sh          $zero, 0x36($s3)
        MEM_H(0X36, ctx->r19) = 0;
            goto L_8001FBB4;
    }
    goto skip_5;
    // 0x8001FBA0: sh          $zero, 0x36($s3)
    MEM_H(0X36, ctx->r19) = 0;
    skip_5:
    // 0x8001FBA4: lh          $t9, 0xE8($s5)
    ctx->r25 = MEM_H(ctx->r21, 0XE8);
    // 0x8001FBA8: addiu       $t0, $t9, -0x64
    ctx->r8 = ADD32(ctx->r25, -0X64);
    // 0x8001FBAC: sh          $t0, 0xE8($s5)
    MEM_H(0XE8, ctx->r21) = ctx->r8;
    // 0x8001FBB0: sh          $zero, 0x36($s3)
    MEM_H(0X36, ctx->r19) = 0;
L_8001FBB4:
    // 0x8001FBB4: b           L_8001FBEC
    // 0x8001FBB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8001FBEC;
    // 0x8001FBB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001FBBC: lh          $t1, 0x34($s3)
    ctx->r9 = MEM_H(ctx->r19, 0X34);
L_8001FBC0:
    // 0x8001FBC0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8001FBC4: addiu       $s2, $s2, 0x18
    ctx->r18 = ADD32(ctx->r18, 0X18);
    // 0x8001FBC8: slt         $at, $s1, $t1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8001FBCC: bne         $at, $zero, L_8001FB34
    if (ctx->r1 != 0) {
        // 0x8001FBD0: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_8001FB34;
    }
    // 0x8001FBD0: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x8001FBD4: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
L_8001FBD8:
    // 0x8001FBD8: or          $s3, $v1, $zero
    ctx->r19 = ctx->r3 | 0;
L_8001FBDC:
    // 0x8001FBDC: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8001FBE0: bnel        $v1, $zero, L_8001FB00
    if (ctx->r3 != 0) {
        // 0x8001FBE4: lh          $t7, 0x36($s3)
        ctx->r15 = MEM_H(ctx->r19, 0X36);
            goto L_8001FB00;
    }
    goto skip_6;
    // 0x8001FBE4: lh          $t7, 0x36($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X36);
    skip_6:
    // 0x8001FBE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001FBEC:
    // 0x8001FBEC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8001FBF0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001FBF4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8001FBF8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8001FBFC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8001FC00: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8001FC04: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8001FC08: jr          $ra
    // 0x8001FC0C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    TRACE_RETURN()
    return;
    // 0x8001FC0C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8001FC10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8001FC10: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8001FC14: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8001FC18: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x8001FC1C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8001FC20: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8001FC24: addiu       $s4, $s4, -0x6A20
    ctx->r20 = ADD32(ctx->r20, -0X6A20);
    // 0x8001FC28: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8001FC2C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8001FC30: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8001FC34: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8001FC38: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8001FC3C: jal         0x80020328
    // 0x8001FC40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80020328(rdram, ctx);
        goto after_0;
    // 0x8001FC40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8001FC44: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001FC48: lh          $v0, -0x6B80($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X6B80);
    // 0x8001FC4C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001FC50: beq         $v0, $at, L_8001FC68
    if (ctx->r2 == ctx->r1) {
        // 0x8001FC54: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8001FC68;
    }
    // 0x8001FC54: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001FC58: beq         $v0, $at, L_8001FC80
    if (ctx->r2 == ctx->r1) {
        // 0x8001FC5C: addiu       $a0, $zero, 0x5
        ctx->r4 = ADD32(0, 0X5);
            goto L_8001FC80;
    }
    // 0x8001FC5C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8001FC60: b           L_8001FC94
    // 0x8001FC64: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_8001FC94;
    // 0x8001FC64: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8001FC68:
    // 0x8001FC68: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8001FC6C: addiu       $a1, $a1, -0x6A18
    ctx->r5 = ADD32(ctx->r5, -0X6A18);
    // 0x8001FC70: jal         0x80011520
    // 0x8001FC74: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_80011520(rdram, ctx);
        goto after_1;
    // 0x8001FC74: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_1:
    // 0x8001FC78: b           L_8001FCA0
    // 0x8001FC7C: nop

        goto L_8001FCA0;
    // 0x8001FC7C: nop

L_8001FC80:
    // 0x8001FC80: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8001FC84: jal         0x80011520
    // 0x8001FC88: addiu       $a1, $a1, -0x6A18
    ctx->r5 = ADD32(ctx->r5, -0X6A18);
    func_80011520(rdram, ctx);
        goto after_2;
    // 0x8001FC88: addiu       $a1, $a1, -0x6A18
    ctx->r5 = ADD32(ctx->r5, -0X6A18);
    after_2:
    // 0x8001FC8C: b           L_8001FCA0
    // 0x8001FC90: nop

        goto L_8001FCA0;
    // 0x8001FC90: nop

L_8001FC94:
    // 0x8001FC94: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8001FC98: jal         0x80011520
    // 0x8001FC9C: addiu       $a1, $a1, -0x6A18
    ctx->r5 = ADD32(ctx->r5, -0X6A18);
    func_80011520(rdram, ctx);
        goto after_3;
    // 0x8001FC9C: addiu       $a1, $a1, -0x6A18
    ctx->r5 = ADD32(ctx->r5, -0X6A18);
    after_3:
L_8001FCA0:
    // 0x8001FCA0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001FCA4: addiu       $v1, $v1, -0x68C2
    ctx->r3 = ADD32(ctx->r3, -0X68C2);
    // 0x8001FCA8: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x8001FCAC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001FCB0: lh          $v0, -0x662C($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X662C);
    // 0x8001FCB4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8001FCB8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8001FCBC: beq         $v0, $at, L_8001FCC8
    if (ctx->r2 == ctx->r1) {
        // 0x8001FCC0: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_8001FCC8;
    }
    // 0x8001FCC0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8001FCC4: bne         $v0, $at, L_8001FCD0
    if (ctx->r2 != ctx->r1) {
        // 0x8001FCC8: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8001FCD0;
    }
L_8001FCC8:
    // 0x8001FCC8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001FCCC: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
L_8001FCD0:
    // 0x8001FCD0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8001FCD4: bne         $v0, $at, L_8001FD00
    if (ctx->r2 != ctx->r1) {
        // 0x8001FCD8: lui         $at, 0x4234
        ctx->r1 = S32(0X4234 << 16);
            goto L_8001FD00;
    }
    // 0x8001FCD8: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8001FCDC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001FCE0: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8001FCE4: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
    // 0x8001FCE8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001FCEC: swc1        $f4, -0x68C0($at)
    MEM_W(-0X68C0, ctx->r1) = ctx->f4.u32l;
    // 0x8001FCF0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8001FCF4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001FCF8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001FCFC: swc1        $f6, -0x68BC($at)
    MEM_W(-0X68BC, ctx->r1) = ctx->f6.u32l;
L_8001FD00:
    // 0x8001FD00: lw          $t8, -0x6630($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6630);
    // 0x8001FD04: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001FD08: bne         $t8, $at, L_8001FD20
    if (ctx->r24 != ctx->r1) {
        // 0x8001FD0C: lui         $at, 0x43C8
        ctx->r1 = S32(0X43C8 << 16);
            goto L_8001FD20;
    }
    // 0x8001FD0C: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x8001FD10: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001FD14: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001FD18: b           L_8001FD30
    // 0x8001FD1C: swc1        $f8, -0x68B4($at)
    MEM_W(-0X68B4, ctx->r1) = ctx->f8.u32l;
        goto L_8001FD30;
    // 0x8001FD1C: swc1        $f8, -0x68B4($at)
    MEM_W(-0X68B4, ctx->r1) = ctx->f8.u32l;
L_8001FD20:
    // 0x8001FD20: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8001FD24: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001FD28: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001FD2C: swc1        $f10, -0x68B4($at)
    MEM_W(-0X68B4, ctx->r1) = ctx->f10.u32l;
L_8001FD30:
    // 0x8001FD30: jal         0x8000798C
    // 0x8001FD34: nop

    func_8000798C(rdram, ctx);
        goto after_4;
    // 0x8001FD34: nop

    after_4:
    // 0x8001FD38: jal         0x8000798C
    // 0x8001FD3C: nop

    func_8000798C(rdram, ctx);
        goto after_5;
    // 0x8001FD3C: nop

    after_5:
    // 0x8001FD40: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001FD44: jal         0x80044728
    // 0x8001FD48: lh          $a0, -0x6910($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X6910);
    func_80044728(rdram, ctx);
        goto after_6;
    // 0x8001FD48: lh          $a0, -0x6910($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X6910);
    after_6:
    // 0x8001FD4C: jal         0x8000798C
    // 0x8001FD50: nop

    func_8000798C(rdram, ctx);
        goto after_7;
    // 0x8001FD50: nop

    after_7:
    // 0x8001FD54: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8001FD58: lh          $t9, -0x6B80($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X6B80);
    // 0x8001FD5C: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x8001FD60: bne         $t9, $zero, L_8001FDC0
    if (ctx->r25 != 0) {
        // 0x8001FD64: nop
    
            goto L_8001FDC0;
    }
    // 0x8001FD64: nop

    // 0x8001FD68: jal         0x800443A8
    // 0x8001FD6C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800443A8(rdram, ctx);
        goto after_8;
    // 0x8001FD6C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x8001FD70: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8001FD74: lh          $t0, -0x6910($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X6910);
    // 0x8001FD78: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x8001FD7C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8001FD80: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8001FD84: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x8001FD88: jal         0x800443A8
    // 0x8001FD8C: lh          $a0, -0x62DE($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X62DE);
    func_800443A8(rdram, ctx);
        goto after_9;
    // 0x8001FD8C: lh          $a0, -0x62DE($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X62DE);
    after_9:
    // 0x8001FD90: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001FD94: sw          $v0, -0x6974($at)
    MEM_W(-0X6974, ctx->r1) = ctx->r2;
    // 0x8001FD98: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8001FD9C: jal         0x80044614
    // 0x8001FDA0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80044614(rdram, ctx);
        goto after_10;
    // 0x8001FDA0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_10:
    // 0x8001FDA4: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x8001FDA8: lw          $t2, -0x6BDC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X6BDC);
    // 0x8001FDAC: addiu       $at, $zero, 0x2710
    ctx->r1 = ADD32(0, 0X2710);
    // 0x8001FDB0: div         $zero, $t2, $at
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r1)));
    // 0x8001FDB4: mflo        $t3
    ctx->r11 = lo;
    // 0x8001FDB8: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x8001FDBC: nop

L_8001FDC0:
    // 0x8001FDC0: lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // 0x8001FDC4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8001FDC8: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8001FDCC: addiu       $s1, $s1, -0x6888
    ctx->r17 = ADD32(ctx->r17, -0X6888);
    // 0x8001FDD0: addiu       $s0, $s0, -0x68B0
    ctx->r16 = ADD32(ctx->r16, -0X68B0);
    // 0x8001FDD4: addiu       $v1, $v1, -0x62B8
    ctx->r3 = ADD32(ctx->r3, -0X62B8);
L_8001FDD8:
    // 0x8001FDD8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001FDDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001FDE0: lh          $a2, 0x2($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X2);
    // 0x8001FDE4: lh          $a3, 0x0($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X0);
    // 0x8001FDE8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001FDEC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8001FDF0: jal         0x8004C580
    // 0x8001FDF4: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    func_8004C580(rdram, ctx);
        goto after_11;
    // 0x8001FDF4: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_11:
    // 0x8001FDF8: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x8001FDFC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8001FE00: sw          $v0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r2;
    // 0x8001FE04: bne         $s0, $s1, L_8001FDD8
    if (ctx->r16 != ctx->r17) {
        // 0x8001FE08: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8001FDD8;
    }
    // 0x8001FE08: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8001FE0C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001FE10: lh          $v0, -0x6B80($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X6B80);
    // 0x8001FE14: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001FE18: sh          $zero, -0x6888($at)
    MEM_H(-0X6888, ctx->r1) = 0;
    // 0x8001FE1C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001FE20: bne         $v0, $at, L_8001FE38
    if (ctx->r2 != ctx->r1) {
        // 0x8001FE24: lui         $s3, 0x8013
        ctx->r19 = S32(0X8013 << 16);
            goto L_8001FE38;
    }
    // 0x8001FE24: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x8001FE28: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8001FE2C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001FE30: b           L_8001FE4C
    // 0x8001FE34: sh          $t4, -0x68E4($at)
    MEM_H(-0X68E4, ctx->r1) = ctx->r12;
        goto L_8001FE4C;
    // 0x8001FE34: sh          $t4, -0x68E4($at)
    MEM_H(-0X68E4, ctx->r1) = ctx->r12;
L_8001FE38:
    // 0x8001FE38: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001FE3C: bne         $v0, $at, L_8001FE4C
    if (ctx->r2 != ctx->r1) {
        // 0x8001FE40: addiu       $t5, $zero, 0x6
        ctx->r13 = ADD32(0, 0X6);
            goto L_8001FE4C;
    }
    // 0x8001FE40: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x8001FE44: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001FE48: sh          $t5, -0x68E4($at)
    MEM_H(-0X68E4, ctx->r1) = ctx->r13;
L_8001FE4C:
    // 0x8001FE4C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001FE50: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8001FE54: sh          $zero, -0x68C4($at)
    MEM_H(-0X68C4, ctx->r1) = 0;
    // 0x8001FE58: addiu       $s1, $s1, -0x6A18
    ctx->r17 = ADD32(ctx->r17, -0X6A18);
    // 0x8001FE5C: addiu       $s3, $s3, -0x6C14
    ctx->r19 = ADD32(ctx->r19, -0X6C14);
    // 0x8001FE60: addiu       $s0, $zero, -0x2
    ctx->r16 = ADD32(0, -0X2);
    // 0x8001FE64: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
L_8001FE68:
    // 0x8001FE68: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001FE6C: bne         $v0, $at, L_8001FEB4
    if (ctx->r2 != ctx->r1) {
        // 0x8001FE70: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_8001FEB4;
    }
    // 0x8001FE70: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001FE74: jal         0x8004A0C4
    // 0x8001FE78: lw          $a0, -0x6A1C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6A1C);
    func_8004A0C4(rdram, ctx);
        goto after_12;
    // 0x8001FE78: lw          $a0, -0x6A1C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6A1C);
    after_12:
    // 0x8001FE7C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8001FE80: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8001FE84: addiu       $s1, $s1, -0x6888
    ctx->r17 = ADD32(ctx->r17, -0X6888);
    // 0x8001FE88: addiu       $s0, $s0, -0x68B0
    ctx->r16 = ADD32(ctx->r16, -0X68B0);
L_8001FE8C:
    // 0x8001FE8C: jal         0x8004C444
    // 0x8001FE90: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_8004C444(rdram, ctx);
        goto after_13;
    // 0x8001FE90: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_13:
    // 0x8001FE94: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8001FE98: bne         $s0, $s1, L_8001FE8C
    if (ctx->r16 != ctx->r17) {
        // 0x8001FE9C: nop
    
            goto L_8001FE8C;
    }
    // 0x8001FE9C: nop

    // 0x8001FEA0: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
L_8001FEA4:
    // 0x8001FEA4: jal         0x8000798C
    // 0x8001FEA8: nop

    func_8000798C(rdram, ctx);
        goto after_14;
    // 0x8001FEA8: nop

    after_14:
    // 0x8001FEAC: b           L_8001FEA4
    // 0x8001FEB0: nop

        goto L_8001FEA4;
    // 0x8001FEB0: nop

L_8001FEB4:
    // 0x8001FEB4: bne         $s0, $v0, L_8001FED8
    if (ctx->r16 != ctx->r2) {
        // 0x8001FEB8: nop
    
            goto L_8001FED8;
    }
    // 0x8001FEB8: nop

    // 0x8001FEBC: bne         $s0, $v0, L_8001FED8
    if (ctx->r16 != ctx->r2) {
        // 0x8001FEC0: nop
    
            goto L_8001FED8;
    }
    // 0x8001FEC0: nop

L_8001FEC4:
    // 0x8001FEC4: jal         0x8000798C
    // 0x8001FEC8: nop

    func_8000798C(rdram, ctx);
        goto after_15;
    // 0x8001FEC8: nop

    after_15:
    // 0x8001FECC: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8001FED0: beq         $s0, $t6, L_8001FEC4
    if (ctx->r16 == ctx->r14) {
        // 0x8001FED4: nop
    
            goto L_8001FEC4;
    }
    // 0x8001FED4: nop

L_8001FED8:
    // 0x8001FED8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8001FEDC: lh          $t7, -0x6B80($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X6B80);
    // 0x8001FEE0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001FEE4: beq         $t7, $zero, L_8001FF04
    if (ctx->r15 == 0) {
        // 0x8001FEE8: nop
    
            goto L_8001FF04;
    }
    // 0x8001FEE8: nop

    // 0x8001FEEC: jal         0x800216D8
    // 0x8001FEF0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800216D8(rdram, ctx);
        goto after_16;
    // 0x8001FEF0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_16:
    // 0x8001FEF4: jal         0x80022440
    // 0x8001FEF8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_80022440(rdram, ctx);
        goto after_17;
    // 0x8001FEF8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_17:
    // 0x8001FEFC: b           L_80020020
    // 0x8001FF00: nop

        goto L_80020020;
    // 0x8001FF00: nop

L_8001FF04:
    // 0x8001FF04: lw          $v0, -0x6BDC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6BDC);
    // 0x8001FF08: addiu       $at, $zero, 0x2710
    ctx->r1 = ADD32(0, 0X2710);
    // 0x8001FF0C: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8001FF10: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x8001FF14: mflo        $t8
    ctx->r24 = lo;
    // 0x8001FF18: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8001FF1C: beq         $t9, $t8, L_8001FF2C
    if (ctx->r25 == ctx->r24) {
        // 0x8001FF20: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8001FF2C;
    }
    // 0x8001FF20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8001FF24: jal         0x80044614
    // 0x8001FF28: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    func_80044614(rdram, ctx);
        goto after_18;
    // 0x8001FF28: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    after_18:
L_8001FF2C:
    // 0x8001FF2C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8001FF30: lh          $t0, -0x6938($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X6938);
    // 0x8001FF34: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8001FF38: blez        $t0, L_8001FF58
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8001FF3C: nop
    
            goto L_8001FF58;
    }
    // 0x8001FF3C: nop

    // 0x8001FF40: lw          $t1, -0x68DC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X68DC);
    // 0x8001FF44: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8001FF48: blez        $t1, L_8001FF58
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8001FF4C: nop
    
            goto L_8001FF58;
    }
    // 0x8001FF4C: nop

    // 0x8001FF50: jal         0x80020A90
    // 0x8001FF54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80020A90(rdram, ctx);
        goto after_19;
    // 0x8001FF54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_19:
L_8001FF58:
    // 0x8001FF58: jal         0x800216D8
    // 0x8001FF5C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800216D8(rdram, ctx);
        goto after_20;
    // 0x8001FF5C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_20:
    // 0x8001FF60: jal         0x80022440
    // 0x8001FF64: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_80022440(rdram, ctx);
        goto after_21;
    // 0x8001FF64: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_21:
    // 0x8001FF68: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x8001FF6C: lh          $t2, -0x6938($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X6938);
    // 0x8001FF70: blez        $t2, L_8001FF80
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8001FF74: nop
    
            goto L_8001FF80;
    }
    // 0x8001FF74: nop

    // 0x8001FF78: jal         0x80022770
    // 0x8001FF7C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_80022770(rdram, ctx);
        goto after_22;
    // 0x8001FF7C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_22:
L_8001FF80:
    // 0x8001FF80: jal         0x800233C4
    // 0x8001FF84: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800233C4(rdram, ctx);
        goto after_23;
    // 0x8001FF84: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_23:
    // 0x8001FF88: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x8001FF8C: lh          $t3, -0x6938($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X6938);
    // 0x8001FF90: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8001FF94: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8001FF98: blez        $t3, L_80020020
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8001FF9C: nop
    
            goto L_80020020;
    }
    // 0x8001FF9C: nop

    // 0x8001FFA0: lh          $t4, 0x6ACC($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X6ACC);
    // 0x8001FFA4: lhu         $v1, -0x2E44($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2E44);
    // 0x8001FFA8: beq         $t4, $zero, L_8001FFC8
    if (ctx->r12 == 0) {
        // 0x8001FFAC: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8001FFC8;
    }
    // 0x8001FFAC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8001FFB0: sra         $t7, $v1, 8
    ctx->r15 = S32(SIGNED(ctx->r3) >> 8);
    // 0x8001FFB4: andi        $t6, $v0, 0xFFF0
    ctx->r14 = ctx->r2 & 0XFFF0;
    // 0x8001FFB8: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x8001FFBC: or          $v0, $t6, $t8
    ctx->r2 = ctx->r14 | ctx->r24;
    // 0x8001FFC0: andi        $t9, $v0, 0xFFFF
    ctx->r25 = ctx->r2 & 0XFFFF;
    // 0x8001FFC4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8001FFC8:
    // 0x8001FFC8: andi        $t0, $v0, 0xB
    ctx->r8 = ctx->r2 & 0XB;
    // 0x8001FFCC: beq         $t0, $zero, L_80020020
    if (ctx->r8 == 0) {
        // 0x8001FFD0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80020020;
    }
    // 0x8001FFD0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8001FFD4: lh          $t1, 0x0($s3)
    ctx->r9 = MEM_H(ctx->r19, 0X0);
    // 0x8001FFD8: andi        $t2, $v1, 0x8
    ctx->r10 = ctx->r3 & 0X8;
    // 0x8001FFDC: beq         $t1, $zero, L_8001FFEC
    if (ctx->r9 == 0) {
        // 0x8001FFE0: nop
    
            goto L_8001FFEC;
    }
    // 0x8001FFE0: nop

    // 0x8001FFE4: b           L_80020020
    // 0x8001FFE8: sh          $zero, 0x0($s3)
    MEM_H(0X0, ctx->r19) = 0;
        goto L_80020020;
    // 0x8001FFE8: sh          $zero, 0x0($s3)
    MEM_H(0X0, ctx->r19) = 0;
L_8001FFEC:
    // 0x8001FFEC: beq         $t2, $zero, L_80020000
    if (ctx->r10 == 0) {
        // 0x8001FFF0: andi        $t4, $v1, 0x2
        ctx->r12 = ctx->r3 & 0X2;
            goto L_80020000;
    }
    // 0x8001FFF0: andi        $t4, $v1, 0x2
    ctx->r12 = ctx->r3 & 0X2;
    // 0x8001FFF4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8001FFF8: b           L_80020020
    // 0x8001FFFC: sh          $t3, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r11;
        goto L_80020020;
    // 0x8001FFFC: sh          $t3, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r11;
L_80020000:
    // 0x80020000: beq         $t4, $zero, L_80020014
    if (ctx->r12 == 0) {
        // 0x80020004: andi        $t6, $v1, 0x1
        ctx->r14 = ctx->r3 & 0X1;
            goto L_80020014;
    }
    // 0x80020004: andi        $t6, $v1, 0x1
    ctx->r14 = ctx->r3 & 0X1;
    // 0x80020008: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8002000C: b           L_80020020
    // 0x80020010: sh          $t5, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r13;
        goto L_80020020;
    // 0x80020010: sh          $t5, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r13;
L_80020014:
    // 0x80020014: beq         $t6, $zero, L_80020020
    if (ctx->r14 == 0) {
        // 0x80020018: addiu       $t7, $zero, 0x3
        ctx->r15 = ADD32(0, 0X3);
            goto L_80020020;
    }
    // 0x80020018: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8002001C: sh          $t7, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r15;
L_80020020:
    // 0x80020020: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80020024: jal         0x8000E074
    // 0x80020028: addiu       $a0, $a0, -0x6A18
    ctx->r4 = ADD32(ctx->r4, -0X6A18);
    func_8000E074(rdram, ctx);
        goto after_24;
    // 0x80020028: addiu       $a0, $a0, -0x6A18
    ctx->r4 = ADD32(ctx->r4, -0X6A18);
    after_24:
    // 0x8002002C: beq         $v0, $zero, L_8002004C
    if (ctx->r2 == 0) {
        // 0x80020030: lui         $t3, 0x8013
        ctx->r11 = S32(0X8013 << 16);
            goto L_8002004C;
    }
    // 0x80020030: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80020034: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80020038: lw          $t8, -0x692C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X692C);
    // 0x8002003C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80020040: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80020044: b           L_80020060
    // 0x80020048: sw          $t9, -0x692C($at)
    MEM_W(-0X692C, ctx->r1) = ctx->r25;
        goto L_80020060;
    // 0x80020048: sw          $t9, -0x692C($at)
    MEM_W(-0X692C, ctx->r1) = ctx->r25;
L_8002004C:
    // 0x8002004C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80020050: lw          $t0, -0x692C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X692C);
    // 0x80020054: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80020058: and         $t1, $t0, $s0
    ctx->r9 = ctx->r8 & ctx->r16;
    // 0x8002005C: sw          $t1, -0x692C($at)
    MEM_W(-0X692C, ctx->r1) = ctx->r9;
L_80020060:
    // 0x80020060: lw          $t3, -0x6A1C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X6A1C);
    // 0x80020064: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80020068: lw          $t2, -0x692C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X692C);
    // 0x8002006C: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x80020070: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80020074: addiu       $v0, $v0, -0x6A20
    ctx->r2 = ADD32(ctx->r2, -0X6A20);
    // 0x80020078: sw          $t2, 0xD8($t4)
    MEM_W(0XD8, ctx->r12) = ctx->r10;
    // 0x8002007C: lh          $v1, 0x134($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X134);
L_80020080:
    // 0x80020080: beq         $v1, $zero, L_8002008C
    if (ctx->r3 == 0) {
        // 0x80020084: addiu       $t5, $v1, -0x1
        ctx->r13 = ADD32(ctx->r3, -0X1);
            goto L_8002008C;
    }
    // 0x80020084: addiu       $t5, $v1, -0x1
    ctx->r13 = ADD32(ctx->r3, -0X1);
    // 0x80020088: sh          $t5, 0x134($v0)
    MEM_H(0X134, ctx->r2) = ctx->r13;
L_8002008C:
    // 0x8002008C: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80020090: bnel        $v0, $s1, L_80020080
    if (ctx->r2 != ctx->r17) {
        // 0x80020094: lh          $v1, 0x134($v0)
        ctx->r3 = MEM_H(ctx->r2, 0X134);
            goto L_80020080;
    }
    goto skip_0;
    // 0x80020094: lh          $v1, 0x134($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X134);
    skip_0:
    // 0x80020098: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8002009C: lh          $v0, -0x696C($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X696C);
    // 0x800200A0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800200A4: beq         $v0, $zero, L_800200B0
    if (ctx->r2 == 0) {
        // 0x800200A8: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_800200B0;
    }
    // 0x800200A8: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x800200AC: sh          $t7, -0x696C($at)
    MEM_H(-0X696C, ctx->r1) = ctx->r15;
L_800200B0:
    // 0x800200B0: jal         0x8000798C
    // 0x800200B4: nop

    func_8000798C(rdram, ctx);
        goto after_25;
    // 0x800200B4: nop

    after_25:
    // 0x800200B8: b           L_8001FE68
    // 0x800200BC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
        goto L_8001FE68;
    // 0x800200BC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800200C0: nop

    // 0x800200C4: nop

    // 0x800200C8: nop

    // 0x800200CC: nop

    // 0x800200D0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800200D4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800200D8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800200DC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800200E0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800200E4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800200E8: jr          $ra
    // 0x800200EC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    TRACE_RETURN()
    return;
    // 0x800200EC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_800200F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800200F0: jr          $ra
    // 0x800200F4: sh          $zero, 0xDC($a0)
    MEM_H(0XDC, ctx->r4) = 0;
    TRACE_RETURN()
    return;
    // 0x800200F4: sh          $zero, 0xDC($a0)
    MEM_H(0XDC, ctx->r4) = 0;
;}
RECOMP_FUNC void func_800200F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800200F8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800200FC: addiu       $v0, $v0, -0x6BA6
    ctx->r2 = ADD32(ctx->r2, -0X6BA6);
    // 0x80020100: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x80020104: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80020108: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x8002010C: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x80020110: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80020114: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80020118: bne         $at, $zero, L_8002017C
    if (ctx->r1 != 0) {
        // 0x8002011C: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_8002017C;
    }
    // 0x8002011C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80020120: andi        $t9, $t7, 0x8000
    ctx->r25 = ctx->r15 & 0X8000;
    // 0x80020124: beq         $t9, $zero, L_80020150
    if (ctx->r25 == 0) {
        // 0x80020128: sh          $zero, 0x11C($a0)
        MEM_H(0X11C, ctx->r4) = 0;
            goto L_80020150;
    }
    // 0x80020128: sh          $zero, 0x11C($a0)
    MEM_H(0X11C, ctx->r4) = 0;
    // 0x8002012C: lh          $t0, 0xDC($a0)
    ctx->r8 = MEM_H(ctx->r4, 0XDC);
    // 0x80020130: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80020134: sh          $t1, 0xDC($a0)
    MEM_H(0XDC, ctx->r4) = ctx->r9;
    // 0x80020138: lh          $t3, 0xDC($a0)
    ctx->r11 = MEM_H(ctx->r4, 0XDC);
    // 0x8002013C: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    // 0x80020140: bne         $t2, $t3, L_80020174
    if (ctx->r10 != ctx->r11) {
        // 0x80020144: nop
    
            goto L_80020174;
    }
    // 0x80020144: nop

    // 0x80020148: b           L_80020174
    // 0x8002014C: sh          $zero, 0xDC($a0)
    MEM_H(0XDC, ctx->r4) = 0;
        goto L_80020174;
    // 0x8002014C: sh          $zero, 0xDC($a0)
    MEM_H(0XDC, ctx->r4) = 0;
L_80020150:
    // 0x80020150: lh          $t4, 0xDC($a0)
    ctx->r12 = MEM_H(ctx->r4, 0XDC);
    // 0x80020154: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80020158: sh          $t5, 0xDC($a0)
    MEM_H(0XDC, ctx->r4) = ctx->r13;
    // 0x8002015C: lh          $t6, 0xDC($a0)
    ctx->r14 = MEM_H(ctx->r4, 0XDC);
    // 0x80020160: bgez        $t6, L_80020174
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80020164: nop
    
            goto L_80020174;
    }
    // 0x80020164: nop

    // 0x80020168: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x8002016C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80020170: sh          $t8, 0xDC($a0)
    MEM_H(0XDC, ctx->r4) = ctx->r24;
L_80020174:
    // 0x80020174: jal         0x80044480
    // 0x80020178: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    func_80044480(rdram, ctx);
        goto after_0;
    // 0x80020178: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_0:
L_8002017C:
    // 0x8002017C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80020180: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80020184: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8002018C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8002018C: lh          $t6, 0x110($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X110);
    // 0x80020190: lh          $t9, 0x112($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X112);
    // 0x80020194: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x80020198: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8002019C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800201A0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800201A4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800201A8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800201AC: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x800201B0: jr          $ra
    // 0x800201B4: lw          $v0, -0x6290($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6290);
    TRACE_RETURN()
    return;
    // 0x800201B4: lw          $v0, -0x6290($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6290);
;}
RECOMP_FUNC void func_800201B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800201B8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800201BC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800201C0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800201C4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800201C8: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800201CC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800201D0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800201D4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800201D8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800201DC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800201E0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800201E4: jal         0x8002018C
    // 0x800201E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_8002018C(rdram, ctx);
        goto after_0;
    // 0x800201E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800201EC: jal         0x80049CFC
    // 0x800201F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80049CFC(rdram, ctx);
        goto after_1;
    // 0x800201F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800201F4: jal         0x80049D80
    // 0x800201F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80049D80(rdram, ctx);
        goto after_2;
    // 0x800201F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x800201FC: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x80020200: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80020204: jal         0x80049DFC
    // 0x80020208: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80049DFC(rdram, ctx);
        goto after_3;
    // 0x80020208: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8002020C: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x80020210: sw          $v0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r2;
    // 0x80020214: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80020218: lh          $v1, 0xC($t7)
    ctx->r3 = MEM_H(ctx->r15, 0XC);
    // 0x8002021C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80020220: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80020224: blez        $v1, L_800202F0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80020228: lw          $s1, 0x0($t6)
        ctx->r17 = MEM_W(ctx->r14, 0X0);
            goto L_800202F0;
    }
    // 0x80020228: lw          $s1, 0x0($t6)
    ctx->r17 = MEM_W(ctx->r14, 0X0);
    // 0x8002022C: lui         $fp, 0x2020
    ctx->r30 = S32(0X2020 << 16);
    // 0x80020230: lui         $s7, 0x2020
    ctx->r23 = S32(0X2020 << 16);
    // 0x80020234: lui         $s6, 0x2020
    ctx->r22 = S32(0X2020 << 16);
    // 0x80020238: ori         $s6, $s6, 0x2079
    ctx->r22 = ctx->r22 | 0X2079;
    // 0x8002023C: ori         $s7, $s7, 0x2000
    ctx->r23 = ctx->r23 | 0X2000;
    // 0x80020240: ori         $fp, $fp, 0x2078
    ctx->r30 = ctx->r30 | 0X2078;
L_80020244:
    // 0x80020244: lw          $t8, 0x10($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X10);
    // 0x80020248: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8002024C: sll         $t0, $s4, 2
    ctx->r8 = S32(ctx->r20 << 2);
    // 0x80020250: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80020254: addu        $v0, $t9, $s7
    ctx->r2 = ADD32(ctx->r25, ctx->r23);
    // 0x80020258: beq         $s6, $v0, L_80020268
    if (ctx->r22 == ctx->r2) {
        // 0x8002025C: nop
    
            goto L_80020268;
    }
    // 0x8002025C: nop

    // 0x80020260: bnel        $fp, $v0, L_800202E4
    if (ctx->r30 != ctx->r2) {
        // 0x80020264: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_800202E4;
    }
    goto skip_0;
    // 0x80020264: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    skip_0:
L_80020268:
    // 0x80020268: jal         0x8000F764
    // 0x8002026C: addu        $s0, $s3, $t0
    ctx->r16 = ADD32(ctx->r19, ctx->r8);
    func_8000F764(rdram, ctx);
        goto after_4;
    // 0x8002026C: addu        $s0, $s3, $t0
    ctx->r16 = ADD32(ctx->r19, ctx->r8);
    after_4:
    // 0x80020270: lw          $t1, 0x4($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X4);
    // 0x80020274: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80020278: addiu       $a0, $v0, 0x10
    ctx->r4 = ADD32(ctx->r2, 0X10);
    // 0x8002027C: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x80020280: lw          $t3, 0xD4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XD4);
    // 0x80020284: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x80020288: sw          $v0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r2;
    // 0x8002028C: lw          $t5, 0x4($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X4);
    // 0x80020290: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x80020294: lw          $t7, 0xD4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XD4);
    // 0x80020298: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8002029C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800202A0: lw          $t9, 0x4($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X4);
    // 0x800202A4: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x800202A8: lw          $t1, 0xD4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XD4);
    // 0x800202AC: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x800202B0: lw          $t2, 0x4($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X4);
    // 0x800202B4: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x800202B8: lw          $t4, 0xD4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XD4);
    // 0x800202BC: sw          $v0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r2;
    // 0x800202C0: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x800202C4: jal         0x80002340
    // 0x800202C8: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    func_80002340(rdram, ctx);
        goto after_5;
    // 0x800202C8: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_5:
    // 0x800202CC: sw          $s2, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r18;
    // 0x800202D0: sw          $s2, 0x100($s0)
    MEM_W(0X100, ctx->r16) = ctx->r18;
    // 0x800202D4: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x800202D8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800202DC: lh          $v1, 0xC($t5)
    ctx->r3 = MEM_H(ctx->r13, 0XC);
    // 0x800202E0: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
L_800202E4:
    // 0x800202E4: slt         $at, $s5, $v1
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800202E8: bne         $at, $zero, L_80020244
    if (ctx->r1 != 0) {
        // 0x800202EC: lw          $s1, 0x0($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X0);
            goto L_80020244;
    }
    // 0x800202EC: lw          $s1, 0x0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X0);
L_800202F0:
    // 0x800202F0: jal         0x8004A148
    // 0x800202F4: lw          $a0, 0x4($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X4);
    func_8004A148(rdram, ctx);
        goto after_6;
    // 0x800202F4: lw          $a0, 0x4($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X4);
    after_6:
    // 0x800202F8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800202FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80020300: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80020304: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80020308: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8002030C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80020310: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80020314: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80020318: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8002031C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80020320: jr          $ra
    // 0x80020324: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    TRACE_RETURN()
    return;
    // 0x80020324: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80020328(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80020328: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002032C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80020330: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80020334: addiu       $a1, $zero, 0x158
    ctx->r5 = ADD32(0, 0X158);
    // 0x80020338: jal         0x8000C7C0
    // 0x8002033C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8000C7C0(rdram, ctx);
        goto after_0;
    // 0x8002033C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80020340: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80020344: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80020348: lw          $t6, -0x68C8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X68C8);
    // 0x8002034C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80020350: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80020354: sh          $zero, 0x112($a3)
    MEM_H(0X112, ctx->r7) = 0;
    // 0x80020358: sh          $t6, 0x110($a3)
    MEM_H(0X110, ctx->r7) = ctx->r14;
    // 0x8002035C: lh          $t7, -0x6B80($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X6B80);
    // 0x80020360: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80020364: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80020368: beq         $t7, $zero, L_80020394
    if (ctx->r15 == 0) {
        // 0x8002036C: or          $v1, $a3, $zero
        ctx->r3 = ctx->r7 | 0;
            goto L_80020394;
    }
    // 0x8002036C: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x80020370: lh          $t8, -0x6B7E($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X6B7E);
    // 0x80020374: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80020378: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8002037C: sh          $t8, 0x112($a3)
    MEM_H(0X112, ctx->r7) = ctx->r24;
    // 0x80020380: lh          $t9, 0x112($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X112);
    // 0x80020384: bne         $t0, $t9, L_800203A4
    if (ctx->r8 != ctx->r25) {
        // 0x80020388: nop
    
            goto L_800203A4;
    }
    // 0x80020388: nop

    // 0x8002038C: b           L_800203A4
    // 0x80020390: sh          $t2, 0x112($a3)
    MEM_H(0X112, ctx->r7) = ctx->r10;
        goto L_800203A4;
    // 0x80020390: sh          $t2, 0x112($a3)
    MEM_H(0X112, ctx->r7) = ctx->r10;
L_80020394:
    // 0x80020394: lh          $t3, 0x112($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X112);
    // 0x80020398: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8002039C: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800203A0: sh          $t3, -0x6B7E($at)
    MEM_H(-0X6B7E, ctx->r1) = ctx->r11;
L_800203A4:
    // 0x800203A4: bne         $t1, $t0, L_800203C0
    if (ctx->r9 != ctx->r8) {
        // 0x800203A8: lui         $t4, 0x8013
        ctx->r12 = S32(0X8013 << 16);
            goto L_800203C0;
    }
    // 0x800203A8: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800203AC: lw          $t4, -0x6BE0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X6BE0);
    // 0x800203B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800203B4: beql        $t4, $at, L_800203C4
    if (ctx->r12 == ctx->r1) {
        // 0x800203B8: lh          $t5, 0x110($a3)
        ctx->r13 = MEM_H(ctx->r7, 0X110);
            goto L_800203C4;
    }
    goto skip_0;
    // 0x800203B8: lh          $t5, 0x110($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X110);
    skip_0:
    // 0x800203BC: sh          $t0, 0x112($a3)
    MEM_H(0X112, ctx->r7) = ctx->r8;
L_800203C0:
    // 0x800203C0: lh          $t5, 0x110($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X110);
L_800203C4:
    // 0x800203C4: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x800203C8: addiu       $t7, $t7, -0x6218
    ctx->r15 = ADD32(ctx->r15, -0X6218);
    // 0x800203CC: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800203D0: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x800203D4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800203D8: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x800203DC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800203E0: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
L_800203E4:
    // 0x800203E4: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800203E8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800203EC: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800203F0: swc1        $f4, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f4.u32l;
    // 0x800203F4: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800203F8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800203FC: swc1        $f6, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f6.u32l;
    // 0x80020400: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80020404: swc1        $f8, 0x70($v1)
    MEM_W(0X70, ctx->r3) = ctx->f8.u32l;
    // 0x80020408: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8002040C: bne         $at, $zero, L_800203E4
    if (ctx->r1 != 0) {
        // 0x80020410: swc1        $f10, 0x64($v1)
        MEM_W(0X64, ctx->r3) = ctx->f10.u32l;
            goto L_800203E4;
    }
    // 0x80020410: swc1        $f10, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->f10.u32l;
    // 0x80020414: lwc1        $f16, 0x10($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80020418: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002041C: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x80020420: swc1        $f16, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->f16.u32l;
    // 0x80020424: lwc1        $f18, 0x14($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80020428: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8002042C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80020430: swc1        $f18, 0x80($a3)
    MEM_W(0X80, ctx->r7) = ctx->f18.u32l;
    // 0x80020434: lwc1        $f4, 0x18($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80020438: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8002043C: swc1        $f4, 0x88($a3)
    MEM_W(0X88, ctx->r7) = ctx->f4.u32l;
    // 0x80020440: lwc1        $f6, 0x1C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80020444: swc1        $f6, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->f6.u32l;
L_80020448:
    // 0x80020448: lh          $t8, 0x20($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X20);
    // 0x8002044C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80020450: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80020454: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80020458: bne         $v0, $a2, L_80020448
    if (ctx->r2 != ctx->r6) {
        // 0x8002045C: sh          $t8, 0xE0($v1)
        MEM_H(0XE0, ctx->r3) = ctx->r24;
            goto L_80020448;
    }
    // 0x8002045C: sh          $t8, 0xE0($v1)
    MEM_H(0XE0, ctx->r3) = ctx->r24;
    // 0x80020460: lh          $t9, 0x26($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X26);
    // 0x80020464: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80020468: sh          $t9, 0xE0($a3)
    MEM_H(0XE0, ctx->r7) = ctx->r25;
    // 0x8002046C: lh          $t2, 0x28($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X28);
    // 0x80020470: sh          $t0, 0xF2($a3)
    MEM_H(0XF2, ctx->r7) = ctx->r8;
    // 0x80020474: sh          $zero, 0x13C($a3)
    MEM_H(0X13C, ctx->r7) = 0;
    // 0x80020478: sh          $t2, 0xEC($a3)
    MEM_H(0XEC, ctx->r7) = ctx->r10;
    // 0x8002047C: lh          $t3, 0xEC($a3)
    ctx->r11 = MEM_H(ctx->r7, 0XEC);
    // 0x80020480: sh          $zero, 0x13E($a3)
    MEM_H(0X13E, ctx->r7) = 0;
    // 0x80020484: addiu       $t4, $t3, 0xC8
    ctx->r12 = ADD32(ctx->r11, 0XC8);
    // 0x80020488: sh          $t4, 0xEC($a3)
    MEM_H(0XEC, ctx->r7) = ctx->r12;
    // 0x8002048C: lh          $t5, 0x2A($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X2A);
    // 0x80020490: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80020494: sh          $t5, 0x142($a3)
    MEM_H(0X142, ctx->r7) = ctx->r13;
    // 0x80020498: lh          $t6, -0x6B8E($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X6B8E);
    // 0x8002049C: beql        $t6, $zero, L_800204AC
    if (ctx->r14 == 0) {
        // 0x800204A0: lh          $v0, 0xEC($a3)
        ctx->r2 = MEM_H(ctx->r7, 0XEC);
            goto L_800204AC;
    }
    goto skip_1;
    // 0x800204A0: lh          $v0, 0xEC($a3)
    ctx->r2 = MEM_H(ctx->r7, 0XEC);
    skip_1:
    // 0x800204A4: sh          $t7, 0x142($a3)
    MEM_H(0X142, ctx->r7) = ctx->r15;
    // 0x800204A8: lh          $v0, 0xEC($a3)
    ctx->r2 = MEM_H(ctx->r7, 0XEC);
L_800204AC:
    // 0x800204AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800204B0: sh          $v0, 0xEA($a3)
    MEM_H(0XEA, ctx->r7) = ctx->r2;
    // 0x800204B4: bne         $t1, $at, L_8002067C
    if (ctx->r9 != ctx->r1) {
        // 0x800204B8: sh          $v0, 0xE8($a3)
        MEM_H(0XE8, ctx->r7) = ctx->r2;
            goto L_8002067C;
    }
    // 0x800204B8: sh          $v0, 0xE8($a3)
    MEM_H(0XE8, ctx->r7) = ctx->r2;
    // 0x800204BC: jal         0x800200F0
    // 0x800204C0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800200F0(rdram, ctx);
        goto after_1;
    // 0x800204C0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x800204C4: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800204C8: lui         $v0, 0x15
    ctx->r2 = S32(0X15 << 16);
    // 0x800204CC: ori         $v0, $v0, 0xF900
    ctx->r2 = ctx->r2 | 0XF900;
    // 0x800204D0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800204D4: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x800204D8: addiu       $v1, $v1, -0x6630
    ctx->r3 = ADD32(ctx->r3, -0X6630);
    // 0x800204DC: sw          $v0, 0x144($a3)
    MEM_W(0X144, ctx->r7) = ctx->r2;
    // 0x800204E0: sw          $v0, 0x148($a3)
    MEM_W(0X148, ctx->r7) = ctx->r2;
    // 0x800204E4: sh          $t8, 0x14C($a3)
    MEM_H(0X14C, ctx->r7) = ctx->r24;
    // 0x800204E8: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800204EC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800204F0: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x800204F4: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800204F8: lwc1        $f8, -0x64AC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X64AC);
    // 0x800204FC: swc1        $f8, 0xA8($a3)
    MEM_W(0XA8, ctx->r7) = ctx->f8.u32l;
    // 0x80020500: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x80020504: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80020508: sltiu       $at, $t4, 0x7
    ctx->r1 = ctx->r12 < 0X7 ? 1 : 0;
    // 0x8002050C: beq         $at, $zero, L_80020634
    if (ctx->r1 == 0) {
        // 0x80020510: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_80020634;
    }
    // 0x80020510: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80020514: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80020518: addu        $at, $at, $t4
    gpr jr_addend_80020520 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8002051C: lw          $t4, 0x66C8($at)
    ctx->r12 = ADD32(ctx->r1, 0X66C8);
    // 0x80020520: jr          $t4
    // 0x80020524: nop

    switch (jr_addend_80020520 >> 2) {
        case 0: goto L_80020528; break;
        case 1: goto L_80020550; break;
        case 2: goto L_80020578; break;
        case 3: goto L_800205A0; break;
        case 4: goto L_800205C8; break;
        case 5: goto L_800205F0; break;
        case 6: goto L_80020610; break;
        default: switch_error(__func__, 0x80020520, 0x800766C8);
    }
    // 0x80020524: nop

L_80020528:
    // 0x80020528: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8002052C: lwc1        $f10, 0x66E4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X66E4);
    // 0x80020530: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80020534: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80020538: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8002053C: swc1        $f10, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f10.u32l;
    // 0x80020540: swc1        $f16, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f16.u32l;
    // 0x80020544: lwc1        $f18, 0x66E8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X66E8);
    // 0x80020548: b           L_80020634
    // 0x8002054C: swc1        $f18, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f18.u32l;
        goto L_80020634;
    // 0x8002054C: swc1        $f18, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f18.u32l;
L_80020550:
    // 0x80020550: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80020554: lwc1        $f4, 0x66EC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X66EC);
    // 0x80020558: lui         $at, 0x42EE
    ctx->r1 = S32(0X42EE << 16);
    // 0x8002055C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80020560: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80020564: swc1        $f4, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f4.u32l;
    // 0x80020568: swc1        $f6, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f6.u32l;
    // 0x8002056C: lwc1        $f8, 0x66F0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X66F0);
    // 0x80020570: b           L_80020634
    // 0x80020574: swc1        $f8, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f8.u32l;
        goto L_80020634;
    // 0x80020574: swc1        $f8, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f8.u32l;
L_80020578:
    // 0x80020578: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8002057C: lwc1        $f10, 0x66F4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X66F4);
    // 0x80020580: lui         $at, 0x4388
    ctx->r1 = S32(0X4388 << 16);
    // 0x80020584: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80020588: lui         $at, 0x443E
    ctx->r1 = S32(0X443E << 16);
    // 0x8002058C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80020590: swc1        $f10, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f10.u32l;
    // 0x80020594: swc1        $f16, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f16.u32l;
    // 0x80020598: b           L_80020634
    // 0x8002059C: swc1        $f18, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f18.u32l;
        goto L_80020634;
    // 0x8002059C: swc1        $f18, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f18.u32l;
L_800205A0:
    // 0x800205A0: lui         $at, 0xC416
    ctx->r1 = S32(0XC416 << 16);
    // 0x800205A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800205A8: lui         $at, 0x4274
    ctx->r1 = S32(0X4274 << 16);
    // 0x800205AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800205B0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800205B4: swc1        $f4, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f4.u32l;
    // 0x800205B8: swc1        $f6, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f6.u32l;
    // 0x800205BC: lwc1        $f8, 0x66F8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X66F8);
    // 0x800205C0: b           L_80020634
    // 0x800205C4: swc1        $f8, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f8.u32l;
        goto L_80020634;
    // 0x800205C4: swc1        $f8, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f8.u32l;
L_800205C8:
    // 0x800205C8: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x800205CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800205D0: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800205D4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800205D8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800205DC: swc1        $f10, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f10.u32l;
    // 0x800205E0: swc1        $f16, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f16.u32l;
    // 0x800205E4: lwc1        $f18, 0x66FC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X66FC);
    // 0x800205E8: b           L_80020634
    // 0x800205EC: swc1        $f18, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f18.u32l;
        goto L_80020634;
    // 0x800205EC: swc1        $f18, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f18.u32l;
L_800205F0:
    // 0x800205F0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800205F4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800205F8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800205FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80020600: swc1        $f0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f0.u32l;
    // 0x80020604: swc1        $f0, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f0.u32l;
    // 0x80020608: b           L_80020634
    // 0x8002060C: swc1        $f4, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f4.u32l;
        goto L_80020634;
    // 0x8002060C: swc1        $f4, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f4.u32l;
L_80020610:
    // 0x80020610: lui         $at, 0xC3EC
    ctx->r1 = S32(0XC3EC << 16);
    // 0x80020614: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80020618: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8002061C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80020620: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80020624: swc1        $f6, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f6.u32l;
    // 0x80020628: swc1        $f8, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f8.u32l;
    // 0x8002062C: lwc1        $f10, 0x6700($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6700);
    // 0x80020630: swc1        $f10, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f10.u32l;
L_80020634:
    // 0x80020634: lwc1        $f16, 0x14($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80020638: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8002063C: lwc1        $f0, 0x6704($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6704);
    // 0x80020640: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80020644: swc1        $f16, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f16.u32l;
    // 0x80020648: lwc1        $f18, 0x6708($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6708);
    // 0x8002064C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80020650: swc1        $f0, 0xD4($a3)
    MEM_W(0XD4, ctx->r7) = ctx->f0.u32l;
    // 0x80020654: swc1        $f18, 0xD0($a3)
    MEM_W(0XD0, ctx->r7) = ctx->f18.u32l;
    // 0x80020658: lwc1        $f4, 0x670C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X670C);
    // 0x8002065C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80020660: swc1        $f4, 0xD8($a3)
    MEM_W(0XD8, ctx->r7) = ctx->f4.u32l;
    // 0x80020664: lwc1        $f6, 0x6710($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6710);
    // 0x80020668: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8002066C: swc1        $f0, 0xC8($a3)
    MEM_W(0XC8, ctx->r7) = ctx->f0.u32l;
    // 0x80020670: swc1        $f6, 0xC4($a3)
    MEM_W(0XC4, ctx->r7) = ctx->f6.u32l;
    // 0x80020674: lwc1        $f8, 0x6714($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6714);
    // 0x80020678: swc1        $f8, 0xCC($a3)
    MEM_W(0XCC, ctx->r7) = ctx->f8.u32l;
L_8002067C:
    // 0x8002067C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80020680: jal         0x800201B8
    // 0x80020684: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800201B8(rdram, ctx);
        goto after_2;
    // 0x80020684: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_2:
    // 0x80020688: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8002068C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80020690: lwc1        $f0, 0x6718($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6718);
    // 0x80020694: lw          $t5, 0xF4($a3)
    ctx->r13 = MEM_W(ctx->r7, 0XF4);
    // 0x80020698: lw          $t7, 0x4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4);
    // 0x8002069C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800206A0: ori         $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 | 0X8000;
    // 0x800206A4: sw          $t6, 0xF4($a3)
    MEM_W(0XF4, ctx->r7) = ctx->r14;
    // 0x800206A8: lw          $v0, 0x8($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X8);
    // 0x800206AC: lw          $t8, 0xD8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XD8);
    // 0x800206B0: ori         $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 | 0X8000;
    // 0x800206B4: sw          $t9, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r25;
    // 0x800206B8: lh          $t2, 0x110($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X110);
    // 0x800206BC: swc1        $f0, 0x108($a3)
    MEM_W(0X108, ctx->r7) = ctx->f0.u32l;
    // 0x800206C0: swc1        $f0, 0x10C($a3)
    MEM_W(0X10C, ctx->r7) = ctx->f0.u32l;
    // 0x800206C4: bne         $t2, $at, L_800206D4
    if (ctx->r10 != ctx->r1) {
        // 0x800206C8: lui         $at, 0x8007
        ctx->r1 = S32(0X8007 << 16);
            goto L_800206D4;
    }
    // 0x800206C8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800206CC: lwc1        $f10, 0x671C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X671C);
    // 0x800206D0: swc1        $f10, 0x10C($a3)
    MEM_W(0X10C, ctx->r7) = ctx->f10.u32l;
L_800206D4:
    // 0x800206D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800206D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800206DC: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800206E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800206E4: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800206E8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800206EC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800206F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800206F4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800206F8: nop

    // 0x800206FC: bc1fl       L_80020710
    if (!c1cs) {
        // 0x80020700: c.lt.s      $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
            goto L_80020710;
    }
    goto skip_0;
    // 0x80020700: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    skip_0:
    // 0x80020704: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80020708: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002070C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
L_80020710:
    // 0x80020710: nop

    // 0x80020714: bc1f        L_8002072C
    if (!c1cs) {
        // 0x80020718: nop
    
            goto L_8002072C;
    }
    // 0x80020718: nop

    // 0x8002071C: beq         $v0, $zero, L_80020728
    if (ctx->r2 == 0) {
        // 0x80020720: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_80020728;
    }
    // 0x80020720: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x80020724: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
L_80020728:
    // 0x80020728: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
L_8002072C:
    // 0x8002072C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80020734(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80020734: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80020738: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002073C: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80020740: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80020744: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x80020748: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8002074C: bc1f        L_80020770
    if (!c1cs) {
        // 0x80020750: swc1        $f6, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
            goto L_80020770;
    }
    // 0x80020750: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x80020754: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80020758: c.lt.s      $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f10.fl < ctx->f14.fl;
    // 0x8002075C: nop

    // 0x80020760: bc1f        L_80020788
    if (!c1cs) {
        // 0x80020764: nop
    
            goto L_80020788;
    }
    // 0x80020764: nop

    // 0x80020768: jr          $ra
    // 0x8002076C: swc1        $f14, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f14.u32l;
    TRACE_RETURN()
    return;
    // 0x8002076C: swc1        $f14, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f14.u32l;
L_80020770:
    // 0x80020770: lwc1        $f16, 0x0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80020774: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
    // 0x80020778: nop

    // 0x8002077C: bc1f        L_80020788
    if (!c1cs) {
        // 0x80020780: nop
    
            goto L_80020788;
    }
    // 0x80020780: nop

    // 0x80020784: swc1        $f14, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f14.u32l;
L_80020788:
    // 0x80020788: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80020790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80020790: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80020794: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x80020798: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x8002079C: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x800207A0: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x800207A4: addiu       $s0, $sp, 0x50
    ctx->r16 = ADD32(ctx->r29, 0X50);
    // 0x800207A8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800207AC: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x800207B0: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x800207B4: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x800207B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800207BC:
    // 0x800207BC: addiu       $a0, $v0, 0x1
    ctx->r4 = ADD32(ctx->r2, 0X1);
    // 0x800207C0: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x800207C4: beq         $at, $zero, L_8002088C
    if (ctx->r1 == 0) {
        // 0x800207C8: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_8002088C;
    }
    // 0x800207C8: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800207CC: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800207D0: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x800207D4: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x800207D8: subu        $t7, $t7, $v1
    ctx->r15 = SUB32(ctx->r15, ctx->r3);
    // 0x800207DC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800207E0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800207E4: addu        $a3, $a1, $t8
    ctx->r7 = ADD32(ctx->r5, ctx->r24);
    // 0x800207E8: addu        $a2, $a1, $t7
    ctx->r6 = ADD32(ctx->r5, ctx->r15);
L_800207EC:
    // 0x800207EC: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800207F0: lwc1        $f6, 0x4($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X4);
    // 0x800207F4: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800207F8: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x800207FC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80020800: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80020804: addu        $t2, $a1, $t9
    ctx->r10 = ADD32(ctx->r5, ctx->r25);
    // 0x80020808: or          $t3, $t2, $zero
    ctx->r11 = ctx->r10 | 0;
    // 0x8002080C: bc1f        L_80020880
    if (!c1cs) {
        // 0x80020810: addiu       $t1, $sp, 0x44
        ctx->r9 = ADD32(ctx->r29, 0X44);
            goto L_80020880;
    }
    // 0x80020810: addiu       $t1, $sp, 0x44
    ctx->r9 = ADD32(ctx->r29, 0X44);
    // 0x80020814: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80020818: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x8002081C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80020820: addu        $t4, $a1, $t6
    ctx->r12 = ADD32(ctx->r5, ctx->r14);
L_80020824:
    // 0x80020824: lwc1        $f8, 0x0($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80020828: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x8002082C: sltu        $at, $t1, $s0
    ctx->r1 = ctx->r9 < ctx->r16 ? 1 : 0;
    // 0x80020830: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x80020834: bne         $at, $zero, L_80020824
    if (ctx->r1 != 0) {
        // 0x80020838: swc1        $f8, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->f8.u32l;
            goto L_80020824;
    }
    // 0x80020838: swc1        $f8, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->f8.u32l;
    // 0x8002083C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80020840: or          $t3, $t2, $zero
    ctx->r11 = ctx->r10 | 0;
    // 0x80020844: or          $t5, $t4, $zero
    ctx->r13 = ctx->r12 | 0;
L_80020848:
    // 0x80020848: lwc1        $f10, 0x0($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8002084C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80020850: slti        $at, $t0, 0x3
    ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // 0x80020854: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x80020858: addiu       $t5, $t5, 0x4
    ctx->r13 = ADD32(ctx->r13, 0X4);
    // 0x8002085C: bne         $at, $zero, L_80020848
    if (ctx->r1 != 0) {
        // 0x80020860: swc1        $f10, -0x4($t3)
        MEM_W(-0X4, ctx->r11) = ctx->f10.u32l;
            goto L_80020848;
    }
    // 0x80020860: swc1        $f10, -0x4($t3)
    MEM_W(-0X4, ctx->r11) = ctx->f10.u32l;
    // 0x80020864: addiu       $t1, $sp, 0x44
    ctx->r9 = ADD32(ctx->r29, 0X44);
    // 0x80020868: or          $t5, $t4, $zero
    ctx->r13 = ctx->r12 | 0;
L_8002086C:
    // 0x8002086C: lwc1        $f16, 0x0($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80020870: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x80020874: addiu       $t5, $t5, 0x4
    ctx->r13 = ADD32(ctx->r13, 0X4);
    // 0x80020878: bne         $t1, $s1, L_8002086C
    if (ctx->r9 != ctx->r17) {
        // 0x8002087C: swc1        $f16, -0x4($t5)
        MEM_W(-0X4, ctx->r13) = ctx->f16.u32l;
            goto L_8002086C;
    }
    // 0x8002087C: swc1        $f16, -0x4($t5)
    MEM_W(-0X4, ctx->r13) = ctx->f16.u32l;
L_80020880:
    // 0x80020880: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80020884: bne         $v1, $s2, L_800207EC
    if (ctx->r3 != ctx->r18) {
        // 0x80020888: addiu       $a2, $a2, 0xC
        ctx->r6 = ADD32(ctx->r6, 0XC);
            goto L_800207EC;
    }
    // 0x80020888: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
L_8002088C:
    // 0x8002088C: bne         $a0, $s3, L_800207BC
    if (ctx->r4 != ctx->r19) {
        // 0x80020890: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_800207BC;
    }
    // 0x80020890: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80020894: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x80020898: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8002089C: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x800208A0: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x800208A4: jr          $ra
    // 0x800208A8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    TRACE_RETURN()
    return;
    // 0x800208A8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_800208AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800208AC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800208B0: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x800208B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800208B8: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800208BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800208C0: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    // 0x800208C4: swc1        $f14, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f14.u32l;
    // 0x800208C8: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x800208CC: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x800208D0: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x800208D4: jal         0x8003DAFC
    // 0x800208D8: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    func_8003DAFC(rdram, ctx);
        goto after_0;
    // 0x800208D8: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x800208DC: beq         $v0, $zero, L_800208F0
    if (ctx->r2 == 0) {
        // 0x800208E0: lw          $a3, 0x54($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X54);
            goto L_800208F0;
    }
    // 0x800208E0: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x800208E4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800208E8: b           L_8002093C
    // 0x800208EC: lwc1        $f2, -0x6B98($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6B98);
        goto L_8002093C;
    // 0x800208EC: lwc1        $f2, -0x6B98($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6B98);
L_800208F0:
    // 0x800208F0: beq         $a3, $zero, L_80020928
    if (ctx->r7 == 0) {
        // 0x800208F4: addiu       $a0, $sp, 0x30
        ctx->r4 = ADD32(ctx->r29, 0X30);
            goto L_80020928;
    }
    // 0x800208F4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800208F8: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x800208FC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80020900: lwc1        $f10, 0x0($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80020904: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80020908: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8002090C: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80020910: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80020914: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x80020918: lwc1        $f6, 0x8($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8002091C: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80020920: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80020924: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
L_80020928:
    // 0x80020928: jal         0x8000D3A4
    // 0x8002092C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_8000D3A4(rdram, ctx);
        goto after_1;
    // 0x8002092C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_1:
    // 0x80020930: beql        $v0, $zero, L_80020A80
    if (ctx->r2 == 0) {
        // 0x80020934: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80020A80;
    }
    goto skip_0;
    // 0x80020934: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80020938: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
L_8002093C:
    // 0x8002093C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80020940: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80020944: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80020948: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8002094C: addiu       $v1, $v1, -0x68B8
    ctx->r3 = ADD32(ctx->r3, -0X68B8);
    // 0x80020950: bc1fl       L_80020960
    if (!c1cs) {
        // 0x80020954: add.s       $f0, $f2, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f16.fl;
            goto L_80020960;
    }
    goto skip_1;
    // 0x80020954: add.s       $f0, $f2, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f16.fl;
    skip_1:
    // 0x80020958: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8002095C: add.s       $f0, $f2, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f16.fl;
L_80020960:
    // 0x80020960: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80020964: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80020968: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8002096C: sub.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x80020970: lh          $v0, -0x68C2($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X68C2);
    // 0x80020974: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80020978: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8002097C: bne         $v0, $at, L_800209CC
    if (ctx->r2 != ctx->r1) {
        // 0x80020980: swc1        $f10, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
            goto L_800209CC;
    }
    // 0x80020980: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x80020984: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80020988: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8002098C: lui         $at, 0x4479
    ctx->r1 = S32(0X4479 << 16);
    // 0x80020990: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80020994: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x80020998: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8002099C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800209A0: bc1f        L_800209AC
    if (!c1cs) {
        // 0x800209A4: nop
    
            goto L_800209AC;
    }
    // 0x800209A4: nop

    // 0x800209A8: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
L_800209AC:
    // 0x800209AC: lwc1        $f16, 0x6720($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6720);
    // 0x800209B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800209B4: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800209B8: sub.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x800209BC: trunc.w.s   $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800209C0: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x800209C4: nop

    // 0x800209C8: sw          $t7, -0x2CF4($at)
    MEM_W(-0X2CF4, ctx->r1) = ctx->r15;
L_800209CC:
    // 0x800209CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800209D0: bnel        $v0, $at, L_80020A80
    if (ctx->r2 != ctx->r1) {
        // 0x800209D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80020A80;
    }
    goto skip_2;
    // 0x800209D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800209D8: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x800209DC: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x800209E0: beq         $v0, $zero, L_800209F0
    if (ctx->r2 == 0) {
        // 0x800209E4: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_800209F0;
    }
    // 0x800209E4: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x800209E8: b           L_80020A7C
    // 0x800209EC: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
        goto L_80020A7C;
    // 0x800209EC: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
L_800209F0:
    // 0x800209F0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800209F4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800209F8: addiu       $v0, $v0, -0x68C0
    ctx->r2 = ADD32(ctx->r2, -0X68C0);
    // 0x800209FC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80020A00: lwc1        $f10, 0x6724($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6724);
    // 0x80020A04: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80020A08: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80020A0C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80020A10: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80020A14: addiu       $a0, $a0, -0x68BC
    ctx->r4 = ADD32(ctx->r4, -0X68BC);
    // 0x80020A18: addiu       $t1, $zero, 0xC8
    ctx->r9 = ADD32(0, 0XC8);
    // 0x80020A1C: trunc.w.s   $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80020A20: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x80020A24: nop

    // 0x80020A28: sw          $t0, -0x2CF4($at)
    MEM_W(-0X2CF4, ctx->r1) = ctx->r8;
    // 0x80020A2C: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80020A30: add.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80020A34: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x80020A38: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80020A3C: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x80020A40: nop

    // 0x80020A44: bc1fl       L_80020A64
    if (!c1cs) {
        // 0x80020A48: c.lt.s      $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
            goto L_80020A64;
    }
    goto skip_3;
    // 0x80020A48: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    skip_3:
    // 0x80020A4C: neg.s       $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = -ctx->f2.fl;
    // 0x80020A50: swc1        $f14, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f14.u32l;
    // 0x80020A54: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x80020A58: b           L_80020A7C
    // 0x80020A5C: sh          $t1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r9;
        goto L_80020A7C;
    // 0x80020A5C: sh          $t1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r9;
    // 0x80020A60: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
L_80020A64:
    // 0x80020A64: nop

    // 0x80020A68: bc1fl       L_80020A80
    if (!c1cs) {
        // 0x80020A6C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80020A80;
    }
    goto skip_4;
    // 0x80020A6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x80020A70: neg.s       $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = -ctx->f2.fl;
    // 0x80020A74: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
    // 0x80020A78: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
L_80020A7C:
    // 0x80020A7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80020A80:
    // 0x80020A80: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80020A84: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80020A88: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80020A90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80020A90: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80020A94: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80020A98: lb          $t6, -0x2E48($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X2E48);
    // 0x80020A9C: lb          $t7, -0x2E47($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X2E47);
    // 0x80020AA0: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x80020AA4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80020AA8: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80020AAC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80020AB0: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80020AB4: lh          $t8, 0x6ACC($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X6ACC);
    // 0x80020AB8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80020ABC: lhu         $v0, -0x2E46($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2E46);
    // 0x80020AC0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80020AC4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80020AC8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80020ACC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80020AD0: sw          $a1, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r5;
    // 0x80020AD4: swc1        $f0, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f0.u32l;
    // 0x80020AD8: sh          $v0, 0xE2($sp)
    MEM_H(0XE2, ctx->r29) = ctx->r2;
    // 0x80020ADC: beq         $t8, $zero, L_80020B04
    if (ctx->r24 == 0) {
        // 0x80020AE0: swc1        $f8, 0xEC($sp)
        MEM_W(0XEC, ctx->r29) = ctx->f8.u32l;
            goto L_80020B04;
    }
    // 0x80020AE0: swc1        $f8, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f8.u32l;
    // 0x80020AE4: lh          $t9, 0xE2($sp)
    ctx->r25 = MEM_H(ctx->r29, 0XE2);
    // 0x80020AE8: sll         $t1, $v0, 8
    ctx->r9 = S32(ctx->r2 << 8);
    // 0x80020AEC: andi        $t2, $t1, 0xF00
    ctx->r10 = ctx->r9 & 0XF00;
    // 0x80020AF0: andi        $t4, $t9, 0xF0FF
    ctx->r12 = ctx->r25 & 0XF0FF;
    // 0x80020AF4: sh          $t4, 0xE2($sp)
    MEM_H(0XE2, ctx->r29) = ctx->r12;
    // 0x80020AF8: or          $t5, $t4, $t2
    ctx->r13 = ctx->r12 | ctx->r10;
    // 0x80020AFC: sh          $t5, 0xE2($sp)
    MEM_H(0XE2, ctx->r29) = ctx->r13;
    // 0x80020B00: swc1        $f0, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f0.u32l;
L_80020B04:
    // 0x80020B04: lh          $t6, 0x154($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X154);
    // 0x80020B08: beq         $t6, $zero, L_80020B78
    if (ctx->r14 == 0) {
        // 0x80020B0C: nop
    
            goto L_80020B78;
    }
    // 0x80020B0C: nop

    // 0x80020B10: jal         0x8000E35C
    // 0x80020B14: nop

    func_8000E35C(rdram, ctx);
        goto after_0;
    // 0x80020B14: nop

    after_0:
    // 0x80020B18: andi        $t7, $v0, 0x7
    ctx->r15 = ctx->r2 & 0X7;
    // 0x80020B1C: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80020B20: nop

    // 0x80020B24: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80020B28: jal         0x8000E35C
    // 0x80020B2C: swc1        $f0, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f0.u32l;
    func_8000E35C(rdram, ctx);
        goto after_1;
    // 0x80020B2C: swc1        $f0, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80020B30: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x80020B34: beq         $t8, $zero, L_80020B44
    if (ctx->r24 == 0) {
        // 0x80020B38: lwc1        $f0, 0xE8($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0XE8);
            goto L_80020B44;
    }
    // 0x80020B38: lwc1        $f0, 0xE8($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80020B3C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80020B40: swc1        $f0, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f0.u32l;
L_80020B44:
    // 0x80020B44: jal         0x8000E35C
    // 0x80020B48: nop

    func_8000E35C(rdram, ctx);
        goto after_2;
    // 0x80020B48: nop

    after_2:
    // 0x80020B4C: andi        $t9, $v0, 0x7
    ctx->r25 = ctx->r2 & 0X7;
    // 0x80020B50: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80020B54: nop

    // 0x80020B58: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80020B5C: jal         0x8000E35C
    // 0x80020B60: swc1        $f18, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f18.u32l;
    func_8000E35C(rdram, ctx);
        goto after_3;
    // 0x80020B60: swc1        $f18, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x80020B64: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x80020B68: beq         $t1, $zero, L_80020B78
    if (ctx->r9 == 0) {
        // 0x80020B6C: lwc1        $f4, 0xEC($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0XEC);
            goto L_80020B78;
    }
    // 0x80020B6C: lwc1        $f4, 0xEC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x80020B70: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80020B74: swc1        $f6, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f6.u32l;
L_80020B78:
    // 0x80020B78: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80020B7C: lw          $v0, -0x6BE0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6BE0);
    // 0x80020B80: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80020B84: lwc1        $f0, 0xE8($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80020B88: andi        $t0, $v0, 0x4
    ctx->r8 = ctx->r2 & 0X4;
    // 0x80020B8C: bne         $t0, $zero, L_80020BE8
    if (ctx->r8 != 0) {
        // 0x80020B90: andi        $t3, $v0, 0x80
        ctx->r11 = ctx->r2 & 0X80;
            goto L_80020BE8;
    }
    // 0x80020B90: andi        $t3, $v0, 0x80
    ctx->r11 = ctx->r2 & 0X80;
    // 0x80020B94: bne         $t3, $zero, L_80020BE8
    if (ctx->r11 != 0) {
        // 0x80020B98: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80020BE8;
    }
    // 0x80020B98: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80020B9C: lh          $v0, -0x6B92($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X6B92);
    // 0x80020BA0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80020BA4: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80020BA8: beq         $v0, $at, L_80020BC8
    if (ctx->r2 == ctx->r1) {
        // 0x80020BAC: lwc1        $f8, 0xEC($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0XEC);
            goto L_80020BC8;
    }
    // 0x80020BAC: lwc1        $f8, 0xEC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x80020BB0: beq         $v0, $v1, L_80020BD4
    if (ctx->r2 == ctx->r3) {
        // 0x80020BB4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80020BD4;
    }
    // 0x80020BB4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80020BB8: beq         $v0, $at, L_80020BDC
    if (ctx->r2 == ctx->r1) {
        // 0x80020BBC: lwc1        $f16, 0xEC($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0XEC);
            goto L_80020BDC;
    }
    // 0x80020BBC: lwc1        $f16, 0xEC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x80020BC0: b           L_80020BEC
    // 0x80020BC4: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
        goto L_80020BEC;
    // 0x80020BC4: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
L_80020BC8:
    // 0x80020BC8: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80020BCC: b           L_80020BE8
    // 0x80020BD0: swc1        $f10, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f10.u32l;
        goto L_80020BE8;
    // 0x80020BD0: swc1        $f10, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f10.u32l;
L_80020BD4:
    // 0x80020BD4: b           L_80020BE8
    // 0x80020BD8: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
        goto L_80020BE8;
    // 0x80020BD8: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_80020BDC:
    // 0x80020BDC: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x80020BE0: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80020BE4: swc1        $f18, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f18.u32l;
L_80020BE8:
    // 0x80020BE8: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
L_80020BEC:
    // 0x80020BEC: swc1        $f0, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f0.u32l;
    // 0x80020BF0: lwc1        $f6, 0xE8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80020BF4: bc1tl       L_80020C2C
    if (c1cs) {
        // 0x80020BF8: lwc1        $f0, 0x60($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X60);
            goto L_80020C2C;
    }
    goto skip_0;
    // 0x80020BF8: lwc1        $f0, 0x60($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X60);
    skip_0:
    // 0x80020BFC: lwc1        $f4, 0x6C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80020C00: lwc1        $f10, 0x60($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X60);
    // 0x80020C04: addiu       $a0, $s0, 0x60
    ctx->r4 = ADD32(ctx->r16, 0X60);
    // 0x80020C08: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80020C0C: lw          $a1, 0x78($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X78);
    // 0x80020C10: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80020C14: jal         0x800206E4
    // 0x80020C18: swc1        $f16, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f16.u32l;
    func_800206E4(rdram, ctx);
        goto after_4;
    // 0x80020C18: swc1        $f16, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f16.u32l;
    after_4:
    // 0x80020C1C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80020C20: b           L_80020C58
    // 0x80020C24: lwc1        $f0, 0x60($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X60);
        goto L_80020C58;
    // 0x80020C24: lwc1        $f0, 0x60($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X60);
    // 0x80020C28: lwc1        $f0, 0x60($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X60);
L_80020C2C:
    // 0x80020C2C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80020C30: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x80020C34: nop

    // 0x80020C38: bc1tl       L_80020C5C
    if (c1cs) {
        // 0x80020C3C: lwc1        $f10, 0x9C($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X9C);
            goto L_80020C5C;
    }
    goto skip_1;
    // 0x80020C3C: lwc1        $f10, 0x9C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X9C);
    skip_1:
    // 0x80020C40: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80020C44: nop

    // 0x80020C48: div.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80020C4C: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80020C50: swc1        $f6, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f6.u32l;
    // 0x80020C54: lwc1        $f0, 0x60($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X60);
L_80020C58:
    // 0x80020C58: lwc1        $f10, 0x9C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X9C);
L_80020C5C:
    // 0x80020C5C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80020C60: sub.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80020C64: swc1        $f8, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = ctx->f8.u32l;
    // 0x80020C68: lwc1        $f16, 0xEC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x80020C6C: c.eq.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl == ctx->f16.fl;
    // 0x80020C70: nop

    // 0x80020C74: bc1tl       L_80020CC4
    if (c1cs) {
        // 0x80020C78: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_80020CC4;
    }
    goto skip_2;
    // 0x80020C78: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_2:
    // 0x80020C7C: lwc1        $f18, 0x6728($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6728);
    // 0x80020C80: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x80020C84: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80020C88: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80020C8C: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x80020C90: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80020C94: swc1        $f6, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f6.u32l;
    // 0x80020C98: lwc1        $f0, 0x8C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x80020C9C: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80020CA0: swc1        $f0, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->f0.u32l;
    // 0x80020CA4: bc1fl       L_80020CD8
    if (!c1cs) {
        // 0x80020CA8: lwc1        $f6, 0x98($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0X98);
            goto L_80020CD8;
    }
    goto skip_3;
    // 0x80020CA8: lwc1        $f6, 0x98($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X98);
    skip_3:
    // 0x80020CAC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80020CB0: nop

    // 0x80020CB4: swc1        $f8, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f8.u32l;
    // 0x80020CB8: b           L_80020CD4
    // 0x80020CBC: lwc1        $f0, 0x8C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8C);
        goto L_80020CD4;
    // 0x80020CBC: lwc1        $f0, 0x8C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x80020CC0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_80020CC4:
    // 0x80020CC4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80020CC8: swc1        $f16, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f16.u32l;
    // 0x80020CCC: lwc1        $f0, 0x8C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x80020CD0: swc1        $f18, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->f18.u32l;
L_80020CD4:
    // 0x80020CD4: lwc1        $f6, 0x98($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X98);
L_80020CD8:
    // 0x80020CD8: lwc1        $f4, 0x80($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X80);
    // 0x80020CDC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80020CE0: sub.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80020CE4: addiu       $a0, $s0, 0x98
    ctx->r4 = ADD32(ctx->r16, 0X98);
    // 0x80020CE8: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80020CEC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80020CF0: jal         0x80020734
    // 0x80020CF4: nop

    func_80020734(rdram, ctx);
        goto after_5;
    // 0x80020CF4: nop

    after_5:
    // 0x80020CF8: lwc1        $f0, 0x90($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X90);
    // 0x80020CFC: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80020D00: lwc1        $f16, 0x80($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X80);
    // 0x80020D04: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80020D08: sub.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x80020D0C: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    // 0x80020D10: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80020D14: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80020D18: jal         0x80020734
    // 0x80020D1C: nop

    func_80020734(rdram, ctx);
        goto after_6;
    // 0x80020D1C: nop

    after_6:
    // 0x80020D20: lh          $t4, 0xF6($sp)
    ctx->r12 = MEM_H(ctx->r29, 0XF6);
    // 0x80020D24: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80020D28: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80020D2C: bne         $t4, $at, L_80020D58
    if (ctx->r12 != ctx->r1) {
        // 0x80020D30: lh          $a3, 0xE2($sp)
        ctx->r7 = MEM_H(ctx->r29, 0XE2);
            goto L_80020D58;
    }
    // 0x80020D30: lh          $a3, 0xE2($sp)
    ctx->r7 = MEM_H(ctx->r29, 0XE2);
    // 0x80020D34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80020D38: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80020D3C:
    // 0x80020D3C: lwc1        $f10, 0x98($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X98);
    // 0x80020D40: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80020D44: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80020D48: bne         $a1, $v1, L_80020D3C
    if (ctx->r5 != ctx->r3) {
        // 0x80020D4C: swc1        $f10, 0x10($v0)
        MEM_W(0X10, ctx->r2) = ctx->f10.u32l;
            goto L_80020D3C;
    }
    // 0x80020D4C: swc1        $f10, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f10.u32l;
    // 0x80020D50: b           L_800216C8
    // 0x80020D54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800216C8;
    // 0x80020D54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80020D58:
    // 0x80020D58: lh          $t7, 0x154($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X154);
    // 0x80020D5C: andi        $t2, $a3, 0xF00
    ctx->r10 = ctx->r7 & 0XF00;
    // 0x80020D60: sll         $t5, $t2, 16
    ctx->r13 = S32(ctx->r10 << 16);
    // 0x80020D64: beq         $t7, $zero, L_80020D70
    if (ctx->r15 == 0) {
        // 0x80020D68: sra         $a3, $t5, 16
        ctx->r7 = S32(SIGNED(ctx->r13) >> 16);
            goto L_80020D70;
    }
    // 0x80020D68: sra         $a3, $t5, 16
    ctx->r7 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80020D6C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80020D70:
    // 0x80020D70: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80020D74: andi        $v0, $a3, 0x300
    ctx->r2 = ctx->r7 & 0X300;
    // 0x80020D78: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x80020D7C: swc1        $f8, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f8.u32l;
    // 0x80020D80: lwc1        $f18, 0x30($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80020D84: beq         $v0, $at, L_80020DA0
    if (ctx->r2 == ctx->r1) {
        // 0x80020D88: swc1        $f18, 0xC0($sp)
        MEM_W(0XC0, ctx->r29) = ctx->f18.u32l;
            goto L_80020DA0;
    }
    // 0x80020D88: swc1        $f18, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f18.u32l;
    // 0x80020D8C: addiu       $at, $zero, 0x200
    ctx->r1 = ADD32(0, 0X200);
    // 0x80020D90: beql        $v0, $at, L_80020DCC
    if (ctx->r2 == ctx->r1) {
        // 0x80020D94: lwc1        $f10, 0x34($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X34);
            goto L_80020DCC;
    }
    goto skip_4;
    // 0x80020D94: lwc1        $f10, 0x34($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X34);
    skip_4:
    // 0x80020D98: b           L_80020DF0
    // 0x80020D9C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
        goto L_80020DF0;
    // 0x80020D9C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_80020DA0:
    // 0x80020DA0: lwc1        $f16, 0x34($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80020DA4: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80020DA8: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x80020DAC: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80020DB0: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    // 0x80020DB4: sh          $a3, 0xE0($sp)
    MEM_H(0XE0, ctx->r29) = ctx->r7;
    // 0x80020DB8: jal         0x800206E4
    // 0x80020DBC: lw          $a1, 0xBC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XBC);
    func_800206E4(rdram, ctx);
        goto after_7;
    // 0x80020DBC: lw          $a1, 0xBC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XBC);
    after_7:
    // 0x80020DC0: b           L_80020E2C
    // 0x80020DC4: lh          $a3, 0xE0($sp)
    ctx->r7 = MEM_H(ctx->r29, 0XE0);
        goto L_80020E2C;
    // 0x80020DC4: lh          $a3, 0xE0($sp)
    ctx->r7 = MEM_H(ctx->r29, 0XE0);
    // 0x80020DC8: lwc1        $f10, 0x34($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X34);
L_80020DCC:
    // 0x80020DCC: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80020DD0: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x80020DD4: sub.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80020DD8: swc1        $f18, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f18.u32l;
    // 0x80020DDC: sh          $a3, 0xE0($sp)
    MEM_H(0XE0, ctx->r29) = ctx->r7;
    // 0x80020DE0: jal         0x800206E4
    // 0x80020DE4: lw          $a1, 0xBC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XBC);
    func_800206E4(rdram, ctx);
        goto after_8;
    // 0x80020DE4: lw          $a1, 0xBC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XBC);
    after_8:
    // 0x80020DE8: b           L_80020E2C
    // 0x80020DEC: lh          $a3, 0xE0($sp)
    ctx->r7 = MEM_H(ctx->r29, 0XE0);
        goto L_80020E2C;
    // 0x80020DEC: lh          $a3, 0xE0($sp)
    ctx->r7 = MEM_H(ctx->r29, 0XE0);
L_80020DF0:
    // 0x80020DF0: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80020DF4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80020DF8: nop

    // 0x80020DFC: c.eq.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl == ctx->f0.fl;
    // 0x80020E00: nop

    // 0x80020E04: bc1tl       L_80020E30
    if (c1cs) {
        // 0x80020E08: andi        $v0, $a3, 0xC00
        ctx->r2 = ctx->r7 & 0XC00;
            goto L_80020E30;
    }
    goto skip_5;
    // 0x80020E08: andi        $v0, $a3, 0xC00
    ctx->r2 = ctx->r7 & 0XC00;
    skip_5:
    // 0x80020E0C: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80020E10: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80020E14: nop

    // 0x80020E18: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80020E1C: nop

    // 0x80020E20: mul.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80020E24: sub.s       $f18, $f0, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80020E28: swc1        $f18, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f18.u32l;
L_80020E2C:
    // 0x80020E2C: andi        $v0, $a3, 0xC00
    ctx->r2 = ctx->r7 & 0XC00;
L_80020E30:
    // 0x80020E30: addiu       $at, $zero, 0x400
    ctx->r1 = ADD32(0, 0X400);
    // 0x80020E34: beq         $v0, $at, L_80020E6C
    if (ctx->r2 == ctx->r1) {
        // 0x80020E38: addiu       $at, $zero, 0x800
        ctx->r1 = ADD32(0, 0X800);
            goto L_80020E6C;
    }
    // 0x80020E38: addiu       $at, $zero, 0x800
    ctx->r1 = ADD32(0, 0X800);
    // 0x80020E3C: bnel        $v0, $at, L_80020E98
    if (ctx->r2 != ctx->r1) {
        // 0x80020E40: lwc1        $f0, 0x3C($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
            goto L_80020E98;
    }
    goto skip_6;
    // 0x80020E40: lwc1        $f0, 0x3C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
    skip_6:
    // 0x80020E44: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80020E48: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80020E4C: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x80020E50: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x80020E54: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    // 0x80020E58: sh          $a3, 0xE0($sp)
    MEM_H(0XE0, ctx->r29) = ctx->r7;
    // 0x80020E5C: jal         0x800206E4
    // 0x80020E60: lw          $a1, 0xC0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC0);
    func_800206E4(rdram, ctx);
        goto after_9;
    // 0x80020E60: lw          $a1, 0xC0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC0);
    after_9:
    // 0x80020E64: b           L_80020ED0
    // 0x80020E68: lh          $a3, 0xE0($sp)
    ctx->r7 = MEM_H(ctx->r29, 0XE0);
        goto L_80020ED0;
    // 0x80020E68: lh          $a3, 0xE0($sp)
    ctx->r7 = MEM_H(ctx->r29, 0XE0);
L_80020E6C:
    // 0x80020E6C: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80020E70: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80020E74: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x80020E78: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80020E7C: swc1        $f18, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f18.u32l;
    // 0x80020E80: sh          $a3, 0xE0($sp)
    MEM_H(0XE0, ctx->r29) = ctx->r7;
    // 0x80020E84: jal         0x800206E4
    // 0x80020E88: lw          $a1, 0xC0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC0);
    func_800206E4(rdram, ctx);
        goto after_10;
    // 0x80020E88: lw          $a1, 0xC0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC0);
    after_10:
    // 0x80020E8C: b           L_80020ED0
    // 0x80020E90: lh          $a3, 0xE0($sp)
    ctx->r7 = MEM_H(ctx->r29, 0XE0);
        goto L_80020ED0;
    // 0x80020E90: lh          $a3, 0xE0($sp)
    ctx->r7 = MEM_H(ctx->r29, 0XE0);
    // 0x80020E94: lwc1        $f0, 0x3C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
L_80020E98:
    // 0x80020E98: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80020E9C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80020EA0: c.eq.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl == ctx->f0.fl;
    // 0x80020EA4: nop

    // 0x80020EA8: bc1t        L_80020ED0
    if (c1cs) {
        // 0x80020EAC: nop
    
            goto L_80020ED0;
    }
    // 0x80020EAC: nop

    // 0x80020EB0: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80020EB4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80020EB8: nop

    // 0x80020EBC: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80020EC0: nop

    // 0x80020EC4: mul.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80020EC8: sub.s       $f18, $f0, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80020ECC: swc1        $f18, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f18.u32l;
L_80020ED0:
    // 0x80020ED0: beql        $a3, $zero, L_80020F10
    if (ctx->r7 == 0) {
        // 0x80020ED4: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_80020F10;
    }
    goto skip_7;
    // 0x80020ED4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_7:
    // 0x80020ED8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80020EDC: addiu       $a2, $s0, 0x34
    ctx->r6 = ADD32(ctx->r16, 0X34);
    // 0x80020EE0: addiu       $v0, $sp, 0xC8
    ctx->r2 = ADD32(ctx->r29, 0XC8);
    // 0x80020EE4: addiu       $v1, $sp, 0xD4
    ctx->r3 = ADD32(ctx->r29, 0XD4);
L_80020EE8:
    // 0x80020EE8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80020EEC: bne         $v0, $v1, L_80020EE8
    if (ctx->r2 != ctx->r3) {
        // 0x80020EF0: swc1        $f0, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f0.u32l;
            goto L_80020EE8;
    }
    // 0x80020EF0: swc1        $f0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80020EF4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80020EF8: addiu       $a1, $sp, 0xC8
    ctx->r5 = ADD32(ctx->r29, 0XC8);
    // 0x80020EFC: jal         0x8000CAA4
    // 0x80020F00: sh          $a3, 0xE0($sp)
    MEM_H(0XE0, ctx->r29) = ctx->r7;
    func_8000CAA4(rdram, ctx);
        goto after_11;
    // 0x80020F00: sh          $a3, 0xE0($sp)
    MEM_H(0XE0, ctx->r29) = ctx->r7;
    after_11:
    // 0x80020F04: lh          $a3, 0xE0($sp)
    ctx->r7 = MEM_H(ctx->r29, 0XE0);
    // 0x80020F08: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    // 0x80020F0C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_80020F10:
    // 0x80020F10: andi        $t8, $a3, 0x200
    ctx->r24 = ctx->r7 & 0X200;
    // 0x80020F14: beq         $t8, $zero, L_80020F2C
    if (ctx->r24 == 0) {
        // 0x80020F18: swc1        $f16, 0x94($s0)
        MEM_W(0X94, ctx->r16) = ctx->f16.u32l;
            goto L_80020F2C;
    }
    // 0x80020F18: swc1        $f16, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f16.u32l;
    // 0x80020F1C: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x80020F20: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80020F24: b           L_80020F44
    // 0x80020F28: swc1        $f6, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f6.u32l;
        goto L_80020F44;
    // 0x80020F28: swc1        $f6, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f6.u32l;
L_80020F2C:
    // 0x80020F2C: andi        $t9, $a3, 0x100
    ctx->r25 = ctx->r7 & 0X100;
    // 0x80020F30: beq         $t9, $zero, L_80020F44
    if (ctx->r25 == 0) {
        // 0x80020F34: lui         $at, 0xBE00
        ctx->r1 = S32(0XBE00 << 16);
            goto L_80020F44;
    }
    // 0x80020F34: lui         $at, 0xBE00
    ctx->r1 = S32(0XBE00 << 16);
    // 0x80020F38: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80020F3C: nop

    // 0x80020F40: swc1        $f4, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f4.u32l;
L_80020F44:
    // 0x80020F44: lwc1        $f0, 0xA0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XA0);
    // 0x80020F48: lwc1        $f10, 0x94($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80020F4C: lwc1        $f18, 0x88($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X88);
    // 0x80020F50: lwc1        $f4, 0x34($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80020F54: sub.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80020F58: addiu       $v0, $sp, 0xD8
    ctx->r2 = ADD32(ctx->r29, 0XD8);
    // 0x80020F5C: mul.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80020F60: add.s       $f6, $f0, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80020F64: swc1        $f6, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->f6.u32l;
    // 0x80020F68: swc1        $f4, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f4.u32l;
    // 0x80020F6C: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80020F70: swc1        $f10, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f10.u32l;
L_80020F74:
    // 0x80020F74: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80020F78: jal         0x8000E16C
    // 0x80020F7C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_8000E16C(rdram, ctx);
        goto after_12;
    // 0x80020F7C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_12:
    // 0x80020F80: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80020F84: addiu       $t1, $sp, 0xE0
    ctx->r9 = ADD32(ctx->r29, 0XE0);
    // 0x80020F88: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80020F8C: sltu        $at, $v0, $t1
    ctx->r1 = ctx->r2 < ctx->r9 ? 1 : 0;
    // 0x80020F90: bne         $at, $zero, L_80020F74
    if (ctx->r1 != 0) {
        // 0x80020F94: swc1        $f0, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f0.u32l;
            goto L_80020F74;
    }
    // 0x80020F94: swc1        $f0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80020F98: lwc1        $f0, 0xDC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x80020F9C: lwc1        $f12, 0xD8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x80020FA0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80020FA4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80020FA8: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80020FAC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80020FB0: addiu       $v1, $sp, 0x74
    ctx->r3 = ADD32(ctx->r29, 0X74);
    // 0x80020FB4: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x80020FB8: bc1f        L_80020FC4
    if (!c1cs) {
        // 0x80020FBC: addiu       $a1, $sp, 0x74
        ctx->r5 = ADD32(ctx->r29, 0X74);
            goto L_80020FC4;
    }
    // 0x80020FBC: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x80020FC0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_80020FC4:
    // 0x80020FC4: lwc1        $f8, 0x672C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X672C);
    // 0x80020FC8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80020FCC: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x80020FD0: nop

    // 0x80020FD4: bc1fl       L_80020FE8
    if (!c1cs) {
        // 0x80020FD8: swc1        $f12, 0xD8($sp)
        MEM_W(0XD8, ctx->r29) = ctx->f12.u32l;
            goto L_80020FE8;
    }
    goto skip_8;
    // 0x80020FD8: swc1        $f12, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f12.u32l;
    skip_8:
    // 0x80020FDC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80020FE0: nop

    // 0x80020FE4: swc1        $f12, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f12.u32l;
L_80020FE8:
    // 0x80020FE8: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80020FEC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80020FF0: sltu        $at, $a0, $a1
    ctx->r1 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x80020FF4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80020FF8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80020FFC: swc1        $f0, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f0.u32l;
    // 0x80021000: bne         $at, $zero, L_80020FE8
    if (ctx->r1 != 0) {
        // 0x80021004: swc1        $f0, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = ctx->f0.u32l;
            goto L_80020FE8;
    }
    // 0x80021004: swc1        $f0, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f0.u32l;
    // 0x80021008: lwc1        $f12, 0xD8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x8002100C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021010: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80021014: c.eq.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl == ctx->f12.fl;
    // 0x80021018: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x8002101C: swc1        $f12, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f12.u32l;
    // 0x80021020: bc1t        L_800210E0
    if (c1cs) {
        // 0x80021024: nop
    
            goto L_800210E0;
    }
    // 0x80021024: nop

    // 0x80021028: lwc1        $f16, 0x9C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x8002102C: lwc1        $f6, 0x4C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80021030: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80021034: lwc1        $f4, 0x6730($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6730);
    // 0x80021038: add.s       $f0, $f16, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8002103C: mul.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80021040: swc1        $f0, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f0.u32l;
    // 0x80021044: jal         0x8004F7C0
    // 0x80021048: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    func_8004F7C0(rdram, ctx);
        goto after_13;
    // 0x80021048: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    after_13:
    // 0x8002104C: lwc1        $f10, 0xD8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x80021050: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x80021054: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80021058: swc1        $f18, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f18.u32l;
    // 0x8002105C: jal         0x8004F650
    // 0x80021060: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    func_8004F650(rdram, ctx);
        goto after_14;
    // 0x80021060: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    after_14:
    // 0x80021064: lwc1        $f16, 0xD8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x80021068: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x8002106C: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80021070: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80021074: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    // 0x80021078: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8002107C: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80021080: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80021084: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80021088: swc1        $f18, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f18.u32l;
    // 0x8002108C: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80021090: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80021094: jal         0x8004F7C0
    // 0x80021098: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    func_8004F7C0(rdram, ctx);
        goto after_15;
    // 0x80021098: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    after_15:
    // 0x8002109C: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x800210A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800210A4: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x800210A8: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800210AC: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800210B0: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800210B4: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800210B8: jal         0x8004F650
    // 0x800210BC: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    func_8004F650(rdram, ctx);
        goto after_16;
    // 0x800210BC: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    after_16:
    // 0x800210C0: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x800210C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800210C8: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x800210CC: lwc1        $f16, 0x70($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800210D0: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800210D4: add.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800210D8: b           L_800210F0
    // 0x800210DC: swc1        $f18, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f18.u32l;
        goto L_800210F0;
    // 0x800210DC: swc1        $f18, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f18.u32l;
L_800210E0:
    // 0x800210E0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800210E4: swc1        $f2, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f2.u32l;
    // 0x800210E8: bne         $a1, $v1, L_800210E0
    if (ctx->r5 != ctx->r3) {
        // 0x800210EC: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800210E0;
    }
    // 0x800210EC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800210F0:
    // 0x800210F0: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800210F4: lw          $t0, -0x6630($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X6630);
    // 0x800210F8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800210FC: lwc1        $f14, 0x78($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80021100: bne         $t0, $at, L_80021138
    if (ctx->r8 != ctx->r1) {
        // 0x80021104: lwc1        $f12, 0x74($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X74);
            goto L_80021138;
    }
    // 0x80021104: lwc1        $f12, 0x74($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80021108: lwc1        $f6, 0xA8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8002110C: lwc1        $f12, 0x74($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80021110: lw          $a2, 0x7C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X7C);
    // 0x80021114: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80021118: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8002111C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80021120: jal         0x800208AC
    // 0x80021124: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_800208AC(rdram, ctx);
        goto after_17;
    // 0x80021124: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_17:
    // 0x80021128: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8002112C: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80021130: b           L_80021164
    // 0x80021134: swc1        $f16, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f16.u32l;
        goto L_80021164;
    // 0x80021134: swc1        $f16, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f16.u32l;
L_80021138:
    // 0x80021138: lwc1        $f8, 0xA8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8002113C: lwc1        $f14, 0xC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80021140: lw          $a2, 0x7C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X7C);
    // 0x80021144: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80021148: lwc1        $f18, 0x38($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8002114C: addiu       $a3, $s0, 0x50
    ctx->r7 = ADD32(ctx->r16, 0X50);
    // 0x80021150: jal         0x800208AC
    // 0x80021154: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_800208AC(rdram, ctx);
        goto after_18;
    // 0x80021154: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_18:
    // 0x80021158: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8002115C: add.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80021160: swc1        $f4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f4.u32l;
L_80021164:
    // 0x80021164: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x80021168: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8002116C: jal         0x8001FAB4
    // 0x80021170: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    func_8001FAB4(rdram, ctx);
        goto after_19;
    // 0x80021170: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    after_19:
    // 0x80021174: beq         $v0, $zero, L_8002123C
    if (ctx->r2 == 0) {
        // 0x80021178: addiu       $v1, $sp, 0x50
        ctx->r3 = ADD32(ctx->r29, 0X50);
            goto L_8002123C;
    }
    // 0x80021178: addiu       $v1, $sp, 0x50
    ctx->r3 = ADD32(ctx->r29, 0X50);
    // 0x8002117C: addiu       $v1, $sp, 0x74
    ctx->r3 = ADD32(ctx->r29, 0X74);
L_80021180:
    // 0x80021180: addiu       $v0, $sp, 0x5C
    ctx->r2 = ADD32(ctx->r29, 0X5C);
    // 0x80021184: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
L_80021188:
    // 0x80021188: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8002118C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80021190: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x80021194: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80021198: bne         $at, $zero, L_80021188
    if (ctx->r1 != 0) {
        // 0x8002119C: swc1        $f10, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
            goto L_80021188;
    }
    // 0x8002119C: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x800211A0: lwc1        $f12, 0xD8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800211A4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800211A8: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    // 0x800211AC: addiu       $a1, $s0, 0x50
    ctx->r5 = ADD32(ctx->r16, 0X50);
    // 0x800211B0: c.eq.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl == ctx->f12.fl;
    // 0x800211B4: addiu       $v1, $sp, 0xA8
    ctx->r3 = ADD32(ctx->r29, 0XA8);
    // 0x800211B8: addiu       $v0, $sp, 0xB4
    ctx->r2 = ADD32(ctx->r29, 0XB4);
    // 0x800211BC: bc1t        L_80021224
    if (c1cs) {
        // 0x800211C0: nop
    
            goto L_80021224;
    }
    // 0x800211C0: nop

    // 0x800211C4: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800211C8: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800211CC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800211D0: neg.s       $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = -ctx->f8.fl;
    // 0x800211D4: neg.s       $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = -ctx->f4.fl;
    // 0x800211D8: swc1        $f18, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f18.u32l;
    // 0x800211DC: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    // 0x800211E0: jal         0x8000399C
    // 0x800211E4: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    func_8000399C(rdram, ctx);
        goto after_20;
    // 0x800211E4: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    after_20:
    // 0x800211E8: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x800211EC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800211F0: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800211F4: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800211F8: lwc1        $f10, 0xB0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800211FC: mul.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80021200: add.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80021204: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80021208: swc1        $f6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f6.u32l;
    // 0x8002120C: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80021210: swc1        $f4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f4.u32l;
    // 0x80021214: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80021218: add.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x8002121C: b           L_80021430
    // 0x80021220: swc1        $f18, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f18.u32l;
        goto L_80021430;
    // 0x80021220: swc1        $f18, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f18.u32l;
L_80021224:
    // 0x80021224: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80021228: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8002122C: bne         $v1, $v0, L_80021224
    if (ctx->r3 != ctx->r2) {
        // 0x80021230: swc1        $f6, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f6.u32l;
            goto L_80021224;
    }
    // 0x80021230: swc1        $f6, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f6.u32l;
    // 0x80021234: b           L_80021434
    // 0x80021238: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
        goto L_80021434;
    // 0x80021238: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_8002123C:
    // 0x8002123C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80021240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80021244: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x80021248: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8002124C: beq         $v1, $a1, L_8002127C
    if (ctx->r3 == ctx->r5) {
        // 0x80021250: lh          $t3, 0xE2($a0)
        ctx->r11 = MEM_H(ctx->r4, 0XE2);
            goto L_8002127C;
    }
    // 0x80021250: lh          $t3, 0xE2($a0)
    ctx->r11 = MEM_H(ctx->r4, 0XE2);
L_80021254:
    // 0x80021254: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80021258: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002125C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80021260: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80021264: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80021268: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8002126C: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80021270: swc1        $f16, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f16.u32l;
    // 0x80021274: bne         $v1, $a1, L_80021254
    if (ctx->r3 != ctx->r5) {
        // 0x80021278: lh          $t3, 0xE2($a0)
        ctx->r11 = MEM_H(ctx->r4, 0XE2);
            goto L_80021254;
    }
    // 0x80021278: lh          $t3, 0xE2($a0)
    ctx->r11 = MEM_H(ctx->r4, 0XE2);
L_8002127C:
    // 0x8002127C: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80021280: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80021284: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80021288: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8002128C: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80021290: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80021294: swc1        $f16, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f16.u32l;
    // 0x80021298: lh          $t4, 0x110($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X110);
    // 0x8002129C: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x800212A0: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800212A4: sll         $t2, $t4, 1
    ctx->r10 = S32(ctx->r12 << 1);
    // 0x800212A8: addu        $a1, $a1, $t2
    ctx->r5 = ADD32(ctx->r5, ctx->r10);
    // 0x800212AC: lh          $a1, -0x6060($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X6060);
    // 0x800212B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800212B4: jal         0x8001F2CC
    // 0x800212B8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8001F2CC(rdram, ctx);
        goto after_21;
    // 0x800212B8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_21:
    // 0x800212BC: beq         $v0, $zero, L_800212F8
    if (ctx->r2 == 0) {
        // 0x800212C0: lui         $t5, 0x8013
        ctx->r13 = S32(0X8013 << 16);
            goto L_800212F8;
    }
    // 0x800212C0: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800212C4: lw          $t5, -0x6BE0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X6BE0);
    // 0x800212C8: andi        $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 & 0X8000;
    // 0x800212CC: bnel        $t6, $zero, L_800212F0
    if (ctx->r14 != 0) {
        // 0x800212D0: lh          $t1, 0xE8($s0)
        ctx->r9 = MEM_H(ctx->r16, 0XE8);
            goto L_800212F0;
    }
    goto skip_9;
    // 0x800212D0: lh          $t1, 0xE8($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XE8);
    skip_9:
    // 0x800212D4: lh          $t7, 0x156($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X156);
    // 0x800212D8: bnel        $t7, $zero, L_800212F0
    if (ctx->r15 != 0) {
        // 0x800212DC: lh          $t1, 0xE8($s0)
        ctx->r9 = MEM_H(ctx->r16, 0XE8);
            goto L_800212F0;
    }
    goto skip_10;
    // 0x800212DC: lh          $t1, 0xE8($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XE8);
    skip_10:
    // 0x800212E0: lh          $t8, 0xE8($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XE8);
    // 0x800212E4: addiu       $t9, $t8, -0x5
    ctx->r25 = ADD32(ctx->r24, -0X5);
    // 0x800212E8: sh          $t9, 0xE8($s0)
    MEM_H(0XE8, ctx->r16) = ctx->r25;
    // 0x800212EC: lh          $t1, 0xE8($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XE8);
L_800212F0:
    // 0x800212F0: bgtzl       $t1, L_80021180
    if (SIGNED(ctx->r9) > 0) {
        // 0x800212F4: addiu       $v1, $sp, 0x74
        ctx->r3 = ADD32(ctx->r29, 0X74);
            goto L_80021180;
    }
    goto skip_11;
    // 0x800212F4: addiu       $v1, $sp, 0x74
    ctx->r3 = ADD32(ctx->r29, 0X74);
    skip_11:
L_800212F8:
    // 0x800212F8: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800212FC: lw          $t0, -0x6630($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X6630);
    // 0x80021300: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80021304: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    // 0x80021308: bne         $t0, $at, L_80021548
    if (ctx->r8 != ctx->r1) {
        // 0x8002130C: addiu       $a1, $sp, 0x84
        ctx->r5 = ADD32(ctx->r29, 0X84);
            goto L_80021548;
    }
    // 0x8002130C: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    // 0x80021310: jal         0x8000D834
    // 0x80021314: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    func_8000D834(rdram, ctx);
        goto after_22;
    // 0x80021314: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    after_22:
    // 0x80021318: beq         $v0, $zero, L_80021548
    if (ctx->r2 == 0) {
        // 0x8002131C: nop
    
            goto L_80021548;
    }
    // 0x8002131C: nop

    // 0x80021320: jal         0x8000E16C
    // 0x80021324: lwc1        $f12, 0xA8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XA8);
    func_8000E16C(rdram, ctx);
        goto after_23;
    // 0x80021324: lwc1        $f12, 0xA8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XA8);
    after_23:
    // 0x80021328: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8002132C: lwc1        $f18, 0x6734($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6734);
    // 0x80021330: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80021334: nop

    // 0x80021338: bc1tl       L_80021364
    if (c1cs) {
        // 0x8002133C: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_80021364;
    }
    goto skip_12;
    // 0x8002133C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_12:
    // 0x80021340: jal         0x8000E16C
    // 0x80021344: lwc1        $f12, 0xB0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XB0);
    func_8000E16C(rdram, ctx);
        goto after_24;
    // 0x80021344: lwc1        $f12, 0xB0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XB0);
    after_24:
    // 0x80021348: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8002134C: lwc1        $f6, 0x6738($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6738);
    // 0x80021350: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80021354: nop

    // 0x80021358: bc1f        L_80021548
    if (!c1cs) {
        // 0x8002135C: nop
    
            goto L_80021548;
    }
    // 0x8002135C: nop

    // 0x80021360: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_80021364:
    // 0x80021364: lwc1        $f16, 0xD8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x80021368: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8002136C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80021370: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x80021374: lwc1        $f8, 0xD4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80021378: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8002137C: swc1        $f4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f4.u32l;
    // 0x80021380: bc1f        L_80021390
    if (!c1cs) {
        // 0x80021384: nop
    
            goto L_80021390;
    }
    // 0x80021384: nop

    // 0x80021388: b           L_80021550
    // 0x8002138C: lw          $v1, -0x6630($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6630);
        goto L_80021550;
    // 0x8002138C: lw          $v1, -0x6630($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6630);
L_80021390:
    // 0x80021390: lwc1        $f18, 0x673C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X673C);
    // 0x80021394: mul.s       $f12, $f8, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80021398: jal         0x8004F7C0
    // 0x8002139C: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    func_8004F7C0(rdram, ctx);
        goto after_25;
    // 0x8002139C: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    after_25:
    // 0x800213A0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800213A4: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x800213A8: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800213AC: swc1        $f6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f6.u32l;
    // 0x800213B0: jal         0x8004F650
    // 0x800213B4: swc1        $f4, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f4.u32l;
    func_8004F650(rdram, ctx);
        goto after_26;
    // 0x800213B4: swc1        $f4, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f4.u32l;
    after_26:
    // 0x800213B8: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x800213BC: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x800213C0: swc1        $f10, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f10.u32l;
    // 0x800213C4: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    // 0x800213C8: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    // 0x800213CC: jal         0x8000DF5C
    // 0x800213D0: addiu       $a3, $sp, 0xA8
    ctx->r7 = ADD32(ctx->r29, 0XA8);
    func_8000DF5C(rdram, ctx);
        goto after_27;
    // 0x800213D0: addiu       $a3, $sp, 0xA8
    ctx->r7 = ADD32(ctx->r29, 0XA8);
    after_27:
    // 0x800213D4: beq         $v0, $zero, L_80021548
    if (ctx->r2 == 0) {
        // 0x800213D8: addiu       $a0, $sp, 0x5C
        ctx->r4 = ADD32(ctx->r29, 0X5C);
            goto L_80021548;
    }
    // 0x800213D8: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x800213DC: jal         0x80003668
    // 0x800213E0: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    func_80003668(rdram, ctx);
        goto after_28;
    // 0x800213E0: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    after_28:
    // 0x800213E4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800213E8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800213EC: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x800213F0: lwc1        $f8, 0xA8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800213F4: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800213F8: nop

    // 0x800213FC: bc1f        L_80021548
    if (!c1cs) {
        // 0x80021400: nop
    
            goto L_80021548;
    }
    // 0x80021400: nop

    // 0x80021404: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80021408: lwc1        $f10, 0xB0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x8002140C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80021410: mul.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80021414: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80021418: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8002141C: mul.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80021420: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80021424: add.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80021428: swc1        $f12, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f12.u32l;
    // 0x8002142C: swc1        $f6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f6.u32l;
L_80021430:
    // 0x80021430: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_80021434:
    // 0x80021434: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80021438: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002143C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80021440: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    // 0x80021444: swc1        $f10, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f10.u32l;
L_80021448:
    // 0x80021448: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002144C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80021450: slti        $at, $a1, 0x3
    ctx->r1 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // 0x80021454: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80021458: bne         $at, $zero, L_80021448
    if (ctx->r1 != 0) {
        // 0x8002145C: swc1        $f16, 0x58($v0)
        MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
            goto L_80021448;
    }
    // 0x8002145C: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x80021460: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80021464: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80021468: addiu       $v0, $sp, 0x5C
    ctx->r2 = ADD32(ctx->r29, 0X5C);
    // 0x8002146C: addiu       $v1, $sp, 0xA8
    ctx->r3 = ADD32(ctx->r29, 0XA8);
    // 0x80021470: addiu       $a0, $sp, 0xB4
    ctx->r4 = ADD32(ctx->r29, 0XB4);
    // 0x80021474: lwc1        $f14, 0x0($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80021478: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8002147C: mul.s       $f18, $f14, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80021480: beql        $v1, $a0, L_800214AC
    if (ctx->r3 == ctx->r4) {
        // 0x80021484: lwc1        $f16, 0x0($v0)
        ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
            goto L_800214AC;
    }
    goto skip_13;
    // 0x80021484: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    skip_13:
L_80021488:
    // 0x80021488: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002148C: lwc1        $f14, 0x0($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80021490: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80021494: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80021498: mul.s       $f18, $f14, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8002149C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800214A0: bne         $v1, $a0, L_80021488
    if (ctx->r3 != ctx->r4) {
        // 0x800214A4: swc1        $f16, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
            goto L_80021488;
    }
    // 0x800214A4: swc1        $f16, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
    // 0x800214A8: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
L_800214AC:
    // 0x800214AC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800214B0: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800214B4: swc1        $f16, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
    // 0x800214B8: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x800214BC: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    // 0x800214C0: jal         0x80042F80
    // 0x800214C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80042F80(rdram, ctx);
        goto after_29;
    // 0x800214C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_29:
    // 0x800214C8: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x800214CC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800214D0: jal         0x80043714
    // 0x800214D4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80043714(rdram, ctx);
        goto after_30;
    // 0x800214D4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_30:
    // 0x800214D8: jal         0x8000E35C
    // 0x800214DC: nop

    func_8000E35C(rdram, ctx);
        goto after_31;
    // 0x800214DC: nop

    after_31:
    // 0x800214E0: andi        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 & 0X1;
    // 0x800214E4: beq         $t3, $zero, L_800214FC
    if (ctx->r11 == 0) {
        // 0x800214E8: nop
    
            goto L_800214FC;
    }
    // 0x800214E8: nop

    // 0x800214EC: jal         0x80044480
    // 0x800214F0: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    func_80044480(rdram, ctx);
        goto after_32;
    // 0x800214F0: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_32:
    // 0x800214F4: b           L_80021508
    // 0x800214F8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
        goto L_80021508;
    // 0x800214F8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
L_800214FC:
    // 0x800214FC: jal         0x80044480
    // 0x80021500: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    func_80044480(rdram, ctx);
        goto after_33;
    // 0x80021500: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    after_33:
    // 0x80021504: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
L_80021508:
    // 0x80021508: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002150C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80021510: swc1        $f10, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f10.u32l;
    // 0x80021514: lwc1        $f12, 0x6740($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X6740);
    // 0x80021518: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8002151C: jal         0x80011534
    // 0x80021520: lwc1        $f14, 0x6744($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X6744);
    func_80011534(rdram, ctx);
        goto after_34;
    // 0x80021520: lwc1        $f14, 0x6744($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X6744);
    after_34:
    // 0x80021524: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80021528: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002152C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80021530: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80021534: jal         0x8000ACEC
    // 0x80021538: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8000ACEC(rdram, ctx);
        goto after_35;
    // 0x80021538: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_35:
    // 0x8002153C: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x80021540: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80021544: sh          $t4, -0x68C4($at)
    MEM_H(-0X68C4, ctx->r1) = ctx->r12;
L_80021548:
    // 0x80021548: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8002154C: lw          $v1, -0x6630($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6630);
L_80021550:
    // 0x80021550: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80021554: lw          $v0, -0x6B58($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6B58);
    // 0x80021558: lwc1        $f12, 0x74($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8002155C: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80021560: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x80021564: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80021568: negu        $t2, $v0
    ctx->r10 = SUB32(0, ctx->r2);
    // 0x8002156C: cvt.s.w     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80021570: negu        $t5, $v0
    ctx->r13 = SUB32(0, ctx->r2);
    // 0x80021574: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80021578: nop

    // 0x8002157C: bc1fl       L_80021590
    if (!c1cs) {
        // 0x80021580: mtc1        $t2, $f18
        ctx->f18.u32l = ctx->r10;
            goto L_80021590;
    }
    goto skip_14;
    // 0x80021580: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    skip_14:
    // 0x80021584: b           L_800215AC
    // 0x80021588: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
        goto L_800215AC;
    // 0x80021588: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x8002158C: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
L_80021590:
    // 0x80021590: nop

    // 0x80021594: cvt.s.w     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80021598: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8002159C: nop

    // 0x800215A0: bc1fl       L_800215B0
    if (!c1cs) {
        // 0x800215A4: c.lt.s      $f2, $f8
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
            goto L_800215B0;
    }
    goto skip_15;
    // 0x800215A4: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    skip_15:
    // 0x800215A8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_800215AC:
    // 0x800215AC: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
L_800215B0:
    // 0x800215B0: nop

    // 0x800215B4: bc1fl       L_800215C8
    if (!c1cs) {
        // 0x800215B8: mtc1        $t5, $f6
        ctx->f6.u32l = ctx->r13;
            goto L_800215C8;
    }
    goto skip_16;
    // 0x800215B8: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    skip_16:
    // 0x800215BC: b           L_800215E4
    // 0x800215C0: swc1        $f2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f2.u32l;
        goto L_800215E4;
    // 0x800215C0: swc1        $f2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f2.u32l;
    // 0x800215C4: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
L_800215C8:
    // 0x800215C8: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800215CC: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800215D0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800215D4: nop

    // 0x800215D8: bc1f        L_800215E4
    if (!c1cs) {
        // 0x800215DC: nop
    
            goto L_800215E4;
    }
    // 0x800215DC: nop

    // 0x800215E0: swc1        $f0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f0.u32l;
L_800215E4:
    // 0x800215E4: beq         $v1, $at, L_800216A4
    if (ctx->r3 == ctx->r1) {
        // 0x800215E8: swc1        $f12, 0x74($sp)
        MEM_W(0X74, ctx->r29) = ctx->f12.u32l;
            goto L_800216A4;
    }
    // 0x800215E8: swc1        $f12, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f12.u32l;
    // 0x800215EC: jal         0x8000E16C
    // 0x800215F0: swc1        $f12, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f12.u32l;
    func_8000E16C(rdram, ctx);
        goto after_36;
    // 0x800215F0: swc1        $f12, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f12.u32l;
    after_36:
    // 0x800215F4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800215F8: lw          $t6, -0x6B58($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6B58);
    // 0x800215FC: lwc1        $f12, 0x7C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80021600: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80021604: nop

    // 0x80021608: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8002160C: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x80021610: trunc.w.s   $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80021614: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x80021618: jal         0x8000E16C
    // 0x8002161C: sh          $t9, 0xB4($sp)
    MEM_H(0XB4, ctx->r29) = ctx->r25;
    func_8000E16C(rdram, ctx);
        goto after_37;
    // 0x8002161C: sh          $t9, 0xB4($sp)
    MEM_H(0XB4, ctx->r29) = ctx->r25;
    after_37:
    // 0x80021620: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80021624: lw          $t1, -0x6B58($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X6B58);
    // 0x80021628: lh          $v0, 0xB4($sp)
    ctx->r2 = MEM_H(ctx->r29, 0XB4);
    // 0x8002162C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80021630: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80021634: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x80021638: addiu       $a3, $zero, 0x19
    ctx->r7 = ADD32(0, 0X19);
    // 0x8002163C: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80021640: sub.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80021644: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80021648: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x8002164C: nop

    // 0x80021650: sll         $t3, $v1, 16
    ctx->r11 = S32(ctx->r3 << 16);
    // 0x80021654: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80021658: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002165C: beq         $at, $zero, L_80021674
    if (ctx->r1 == 0) {
        // 0x80021660: sh          $t4, 0xB6($sp)
        MEM_H(0XB6, ctx->r29) = ctx->r12;
            goto L_80021674;
    }
    // 0x80021660: sh          $t4, 0xB6($sp)
    MEM_H(0XB6, ctx->r29) = ctx->r12;
    // 0x80021664: sll         $v0, $t4, 16
    ctx->r2 = S32(ctx->r12 << 16);
    // 0x80021668: sra         $t2, $v0, 16
    ctx->r10 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002166C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80021670: sh          $t4, 0xB6($sp)
    MEM_H(0XB6, ctx->r29) = ctx->r12;
L_80021674:
    // 0x80021674: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x80021678: beq         $at, $zero, L_800216A4
    if (ctx->r1 == 0) {
        // 0x8002167C: sh          $v0, 0xB4($sp)
        MEM_H(0XB4, ctx->r29) = ctx->r2;
            goto L_800216A4;
    }
    // 0x8002167C: sh          $v0, 0xB4($sp)
    MEM_H(0XB4, ctx->r29) = ctx->r2;
    // 0x80021680: negu        $a2, $v0
    ctx->r6 = SUB32(0, ctx->r2);
    // 0x80021684: sll         $t5, $a2, 1
    ctx->r13 = S32(ctx->r6 << 1);
    // 0x80021688: addiu       $t6, $t5, 0xFE
    ctx->r14 = ADD32(ctx->r13, 0XFE);
    // 0x8002168C: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x80021690: sra         $a2, $t7, 16
    ctx->r6 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80021694: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80021698: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8002169C: jal         0x8004C580
    // 0x800216A0: sh          $v0, 0xB4($sp)
    MEM_H(0XB4, ctx->r29) = ctx->r2;
    func_8004C580(rdram, ctx);
        goto after_38;
    // 0x800216A0: sh          $v0, 0xB4($sp)
    MEM_H(0XB4, ctx->r29) = ctx->r2;
    after_38:
L_800216A4:
    // 0x800216A4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800216A8: addiu       $v1, $sp, 0x74
    ctx->r3 = ADD32(ctx->r29, 0X74);
    // 0x800216AC: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
L_800216B0:
    // 0x800216B0: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800216B4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800216B8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800216BC: bne         $v1, $a0, L_800216B0
    if (ctx->r3 != ctx->r4) {
        // 0x800216C0: swc1        $f18, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
            goto L_800216B0;
    }
    // 0x800216C0: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
    // 0x800216C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800216C8:
    // 0x800216C8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800216CC: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    // 0x800216D0: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800216D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800216D8: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800216DC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800216E0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800216E4: sh          $zero, 0x38($sp)
    MEM_H(0X38, ctx->r29) = 0;
    // 0x800216E8: lh          $v0, 0x156($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X156);
    // 0x800216EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800216F0: beq         $v0, $zero, L_800216FC
    if (ctx->r2 == 0) {
        // 0x800216F4: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_800216FC;
    }
    // 0x800216F4: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x800216F8: sh          $t6, 0x156($a0)
    MEM_H(0X156, ctx->r4) = ctx->r14;
L_800216FC:
    // 0x800216FC: lhu         $t7, 0x13C($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X13C);
    // 0x80021700: sltiu       $at, $t7, 0x9
    ctx->r1 = ctx->r15 < 0X9 ? 1 : 0;
    // 0x80021704: beq         $at, $zero, L_80022030
    if (ctx->r1 == 0) {
        // 0x80021708: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80022030;
    }
    // 0x80021708: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8002170C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80021710: addu        $at, $at, $t7
    gpr jr_addend_80021718 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80021714: lw          $t7, 0x6748($at)
    ctx->r15 = ADD32(ctx->r1, 0X6748);
    // 0x80021718: jr          $t7
    // 0x8002171C: nop

    switch (jr_addend_80021718 >> 2) {
        case 0: goto L_80021720; break;
        case 1: goto L_800219C8; break;
        case 2: goto L_80021AEC; break;
        case 3: goto L_80021D30; break;
        case 4: goto L_80021E34; break;
        case 5: goto L_80021EFC; break;
        case 6: goto L_80021F5C; break;
        case 7: goto L_80021F80; break;
        case 8: goto L_80021FFC; break;
        default: switch_error(__func__, 0x80021718, 0x80076748);
    }
    // 0x8002171C: nop

L_80021720:
    // 0x80021720: lh          $t8, 0xE8($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XE8);
    // 0x80021724: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80021728: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8002172C: bgtz        $t8, L_8002173C
    if (SIGNED(ctx->r24) > 0) {
        // 0x80021730: nop
    
            goto L_8002173C;
    }
    // 0x80021730: nop

    // 0x80021734: b           L_800219C8
    // 0x80021738: sh          $t9, 0x13C($s0)
    MEM_H(0X13C, ctx->r16) = ctx->r25;
        goto L_800219C8;
    // 0x80021738: sh          $t9, 0x13C($s0)
    MEM_H(0X13C, ctx->r16) = ctx->r25;
L_8002173C:
    // 0x8002173C: lw          $t0, -0x6BE0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X6BE0);
    // 0x80021740: andi        $t1, $t0, 0x8000
    ctx->r9 = ctx->r8 & 0X8000;
    // 0x80021744: bne         $t1, $zero, L_80021774
    if (ctx->r9 != 0) {
        // 0x80021748: lui         $t0, 0x8013
        ctx->r8 = S32(0X8013 << 16);
            goto L_80021774;
    }
    // 0x80021748: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8002174C: lw          $v0, 0x144($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X144);
    // 0x80021750: beql        $v0, $zero, L_80021778
    if (ctx->r2 == 0) {
        // 0x80021754: lw          $v0, 0x144($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X144);
            goto L_80021778;
    }
    goto skip_0;
    // 0x80021754: lw          $v0, 0x144($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X144);
    skip_0:
    // 0x80021758: lh          $t2, 0x14C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X14C);
    // 0x8002175C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80021760: subu        $t3, $v0, $t2
    ctx->r11 = SUB32(ctx->r2, ctx->r10);
    // 0x80021764: bgtz        $t3, L_80021774
    if (SIGNED(ctx->r11) > 0) {
        // 0x80021768: sw          $t3, 0x144($s0)
        MEM_W(0X144, ctx->r16) = ctx->r11;
            goto L_80021774;
    }
    // 0x80021768: sw          $t3, 0x144($s0)
    MEM_W(0X144, ctx->r16) = ctx->r11;
    // 0x8002176C: sw          $zero, 0x144($s0)
    MEM_W(0X144, ctx->r16) = 0;
    // 0x80021770: sh          $t5, 0x13C($s0)
    MEM_H(0X13C, ctx->r16) = ctx->r13;
L_80021774:
    // 0x80021774: lw          $v0, 0x144($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X144);
L_80021778:
    // 0x80021778: lh          $t6, 0x14E($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X14E);
    // 0x8002177C: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80021780: beq         $v0, $zero, L_800217C8
    if (ctx->r2 == 0) {
        // 0x80021784: sh          $t6, 0x150($s0)
        MEM_H(0X150, ctx->r16) = ctx->r14;
            goto L_800217C8;
    }
    // 0x80021784: sh          $t6, 0x150($s0)
    MEM_H(0X150, ctx->r16) = ctx->r14;
    // 0x80021788: lw          $t7, 0x148($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X148);
    // 0x8002178C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80021790: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x80021794: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80021798: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002179C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800217A0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800217A4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800217A8: div.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800217AC: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x800217B0: mul.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x800217B4: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    // 0x800217B8: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800217BC: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800217C0: b           L_800217CC
    // 0x800217C4: sh          $t9, 0x14E($s0)
    MEM_H(0X14E, ctx->r16) = ctx->r25;
        goto L_800217CC;
    // 0x800217C4: sh          $t9, 0x14E($s0)
    MEM_H(0X14E, ctx->r16) = ctx->r25;
L_800217C8:
    // 0x800217C8: sh          $zero, 0x14E($s0)
    MEM_H(0X14E, ctx->r16) = 0;
L_800217CC:
    // 0x800217CC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800217D0: lwc1        $f10, 0x108($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X108);
    // 0x800217D4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800217D8: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x800217DC: nop

    // 0x800217E0: bc1tl       L_80021820
    if (c1cs) {
        // 0x800217E4: lwc1        $f18, 0xA8($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0XA8);
            goto L_80021820;
    }
    goto skip_1;
    // 0x800217E4: lwc1        $f18, 0xA8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XA8);
    skip_1:
    // 0x800217E8: lw          $t0, -0x6630($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X6630);
    // 0x800217EC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800217F0: lwc1        $f0, 0xA8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x800217F4: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800217F8: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800217FC: lwc1        $f18, -0x64AC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X64AC);
    // 0x80021800: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80021804: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80021808: sub.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x8002180C: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80021810: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80021814: b           L_80021830
    // 0x80021818: swc1        $f10, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f10.u32l;
        goto L_80021830;
    // 0x80021818: swc1        $f10, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f10.u32l;
    // 0x8002181C: lwc1        $f18, 0xA8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XA8);
L_80021820:
    // 0x80021820: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80021824: nop

    // 0x80021828: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8002182C: swc1        $f6, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f6.u32l;
L_80021830:
    // 0x80021830: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80021834: lwc1        $f8, 0x676C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X676C);
    // 0x80021838: lh          $t2, 0x110($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X110);
    // 0x8002183C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80021840: swc1        $f8, 0x108($s0)
    MEM_W(0X108, ctx->r16) = ctx->f8.u32l;
    // 0x80021844: bne         $t2, $at, L_80022030
    if (ctx->r10 != ctx->r1) {
        // 0x80021848: nop
    
            goto L_80022030;
    }
    // 0x80021848: nop

    // 0x8002184C: lw          $t3, -0x6630($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X6630);
    // 0x80021850: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80021854: beq         $v1, $t3, L_80022030
    if (ctx->r3 == ctx->r11) {
        // 0x80021858: nop
    
            goto L_80022030;
    }
    // 0x80021858: nop

    // 0x8002185C: lh          $v1, 0x14E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X14E);
    // 0x80021860: slti        $at, $v1, 0x5A
    ctx->r1 = SIGNED(ctx->r3) < 0X5A ? 1 : 0;
    // 0x80021864: beq         $at, $zero, L_80022030
    if (ctx->r1 == 0) {
        // 0x80021868: nop
    
            goto L_80022030;
    }
    // 0x80021868: nop

    // 0x8002186C: lh          $v0, 0x152($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X152);
    // 0x80021870: beql        $v0, $zero, L_8002197C
    if (ctx->r2 == 0) {
        // 0x80021874: lh          $t6, 0x150($s0)
        ctx->r14 = MEM_H(ctx->r16, 0X150);
            goto L_8002197C;
    }
    goto skip_2;
    // 0x80021874: lh          $t6, 0x150($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X150);
    skip_2:
    // 0x80021878: lh          $v1, 0x154($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X154);
    // 0x8002187C: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x80021880: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80021884: beq         $v1, $zero, L_800218A0
    if (ctx->r3 == 0) {
        // 0x80021888: addiu       $t4, $v1, -0x1
        ctx->r12 = ADD32(ctx->r3, -0X1);
            goto L_800218A0;
    }
    // 0x80021888: addiu       $t4, $v1, -0x1
    ctx->r12 = ADD32(ctx->r3, -0X1);
    // 0x8002188C: bne         $t5, $zero, L_80022030
    if (ctx->r13 != 0) {
        // 0x80021890: sh          $t4, 0x154($s0)
        MEM_H(0X154, ctx->r16) = ctx->r12;
            goto L_80022030;
    }
    // 0x80021890: sh          $t4, 0x154($s0)
    MEM_H(0X154, ctx->r16) = ctx->r12;
    // 0x80021894: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80021898: b           L_80022030
    // 0x8002189C: swc1        $f10, 0x108($s0)
    MEM_W(0X108, ctx->r16) = ctx->f10.u32l;
        goto L_80022030;
    // 0x8002189C: swc1        $f10, 0x108($s0)
    MEM_W(0X108, ctx->r16) = ctx->f10.u32l;
L_800218A0:
    // 0x800218A0: sh          $t6, 0x152($s0)
    MEM_H(0X152, ctx->r16) = ctx->r14;
    // 0x800218A4: lh          $t7, 0x152($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X152);
    // 0x800218A8: beql        $t7, $zero, L_80021958
    if (ctx->r15 == 0) {
        // 0x800218AC: lh          $t4, 0x110($s0)
        ctx->r12 = MEM_H(ctx->r16, 0X110);
            goto L_80021958;
    }
    goto skip_3;
    // 0x800218AC: lh          $t4, 0x110($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X110);
    skip_3:
    // 0x800218B0: jal         0x8000E35C
    // 0x800218B4: nop

    func_8000E35C(rdram, ctx);
        goto after_0;
    // 0x800218B4: nop

    after_0:
    // 0x800218B8: lh          $t0, 0x152($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X152);
    // 0x800218BC: andi        $t8, $v0, 0xF
    ctx->r24 = ctx->r2 & 0XF;
    // 0x800218C0: addiu       $t9, $t8, 0x3
    ctx->r25 = ADD32(ctx->r24, 0X3);
    // 0x800218C4: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x800218C8: bne         $t1, $zero, L_80021930
    if (ctx->r9 != 0) {
        // 0x800218CC: sh          $t9, 0x154($s0)
        MEM_H(0X154, ctx->r16) = ctx->r25;
            goto L_80021930;
    }
    // 0x800218CC: sh          $t9, 0x154($s0)
    MEM_H(0X154, ctx->r16) = ctx->r25;
    // 0x800218D0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x800218D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800218D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800218DC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800218E0: jal         0x8000ACEC
    // 0x800218E4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8000ACEC(rdram, ctx);
        goto after_1;
    // 0x800218E4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x800218E8: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x800218EC: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x800218F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800218F4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
L_800218F8:
    // 0x800218F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800218FC: jal         0x80043EF0
    // 0x80021900: sw          $a2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r6;
    func_80043EF0(rdram, ctx);
        goto after_2;
    // 0x80021900: sw          $a2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r6;
    after_2:
    // 0x80021904: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x80021908: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8002190C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80021910: bnel        $a2, $at, L_800218F8
    if (ctx->r6 != ctx->r1) {
        // 0x80021914: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_800218F8;
    }
    goto skip_4;
    // 0x80021914: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    skip_4:
    // 0x80021918: jal         0x80044480
    // 0x8002191C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80044480(rdram, ctx);
        goto after_3;
    // 0x8002191C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80021920: jal         0x800444F8
    // 0x80021924: lw          $a0, 0xAC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XAC);
    func_800444F8(rdram, ctx);
        goto after_4;
    // 0x80021924: lw          $a0, 0xAC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XAC);
    after_4:
    // 0x80021928: b           L_80022030
    // 0x8002192C: nop

        goto L_80022030;
    // 0x8002192C: nop

L_80021930:
    // 0x80021930: lh          $t2, 0x110($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X110);
    // 0x80021934: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80021938: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8002193C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80021940: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x80021944: jal         0x800443A8
    // 0x80021948: lh          $a0, -0x62DE($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X62DE);
    func_800443A8(rdram, ctx);
        goto after_5;
    // 0x80021948: lh          $a0, -0x62DE($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X62DE);
    after_5:
    // 0x8002194C: b           L_80022030
    // 0x80021950: sw          $v0, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->r2;
        goto L_80022030;
    // 0x80021950: sw          $v0, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->r2;
    // 0x80021954: lh          $t4, 0x110($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X110);
L_80021958:
    // 0x80021958: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x8002195C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80021960: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80021964: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x80021968: jal         0x800443A8
    // 0x8002196C: lh          $a0, -0x62DE($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X62DE);
    func_800443A8(rdram, ctx);
        goto after_6;
    // 0x8002196C: lh          $a0, -0x62DE($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X62DE);
    after_6:
    // 0x80021970: b           L_80022030
    // 0x80021974: sw          $v0, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->r2;
        goto L_80022030;
    // 0x80021974: sw          $v0, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->r2;
    // 0x80021978: lh          $t6, 0x150($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X150);
L_8002197C:
    // 0x8002197C: slt         $at, $v1, $t6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80021980: beq         $at, $zero, L_80022030
    if (ctx->r1 == 0) {
        // 0x80021984: nop
    
            goto L_80022030;
    }
    // 0x80021984: nop

    // 0x80021988: jal         0x8000E35C
    // 0x8002198C: nop

    func_8000E35C(rdram, ctx);
        goto after_7;
    // 0x8002198C: nop

    after_7:
    // 0x80021990: andi        $t7, $v0, 0xF
    ctx->r15 = ctx->r2 & 0XF;
    // 0x80021994: bne         $t7, $zero, L_80022030
    if (ctx->r15 != 0) {
        // 0x80021998: nop
    
            goto L_80022030;
    }
    // 0x80021998: nop

    // 0x8002199C: jal         0x8000E35C
    // 0x800219A0: nop

    func_8000E35C(rdram, ctx);
        goto after_8;
    // 0x800219A0: nop

    after_8:
    // 0x800219A4: andi        $t8, $v0, 0x7
    ctx->r24 = ctx->r2 & 0X7;
    // 0x800219A8: addiu       $t9, $t8, 0x5
    ctx->r25 = ADD32(ctx->r24, 0X5);
    // 0x800219AC: sh          $t9, 0x152($s0)
    MEM_H(0X152, ctx->r16) = ctx->r25;
    // 0x800219B0: sh          $zero, 0x154($s0)
    MEM_H(0X154, ctx->r16) = 0;
    // 0x800219B4: addiu       $a0, $zero, 0x58
    ctx->r4 = ADD32(0, 0X58);
    // 0x800219B8: jal         0x800443A8
    // 0x800219BC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    func_800443A8(rdram, ctx);
        goto after_9;
    // 0x800219BC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_9:
    // 0x800219C0: b           L_80022030
    // 0x800219C4: nop

        goto L_80022030;
    // 0x800219C4: nop

L_800219C8:
    // 0x800219C8: lw          $a0, 0xB0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XB0);
    // 0x800219CC: beql        $a0, $zero, L_800219E0
    if (ctx->r4 == 0) {
        // 0x800219D0: lw          $t1, 0x144($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X144);
            goto L_800219E0;
    }
    goto skip_5;
    // 0x800219D0: lw          $t1, 0x144($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X144);
    skip_5:
    // 0x800219D4: jal         0x800444F8
    // 0x800219D8: nop

    func_800444F8(rdram, ctx);
        goto after_10;
    // 0x800219D8: nop

    after_10:
    // 0x800219DC: lw          $t1, 0x144($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X144);
L_800219E0:
    // 0x800219E0: addiu       $t0, $zero, 0x190
    ctx->r8 = ADD32(0, 0X190);
    // 0x800219E4: sh          $t0, 0x13A($s0)
    MEM_H(0X13A, ctx->r16) = ctx->r8;
    // 0x800219E8: beq         $t1, $zero, L_80021A8C
    if (ctx->r9 == 0) {
        // 0x800219EC: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80021A8C;
    }
    // 0x800219EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800219F0: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x800219F4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800219F8: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x800219FC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80021A00: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x80021A04: jal         0x8000ACEC
    // 0x80021A08: addiu       $a3, $zero, -0x2
    ctx->r7 = ADD32(0, -0X2);
    func_8000ACEC(rdram, ctx);
        goto after_11;
    // 0x80021A08: addiu       $a3, $zero, -0x2
    ctx->r7 = ADD32(0, -0X2);
    after_11:
    // 0x80021A0C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80021A10: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80021A14: sh          $t3, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r11;
    // 0x80021A18: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80021A1C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80021A20: jal         0x80042F80
    // 0x80021A24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80042F80(rdram, ctx);
        goto after_12;
    // 0x80021A24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
    // 0x80021A28: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80021A2C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80021A30: jal         0x80043714
    // 0x80021A34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80043714(rdram, ctx);
        goto after_13;
    // 0x80021A34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
    // 0x80021A38: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80021A3C: jal         0x8000E35C
    // 0x80021A40: sh          $v1, 0x136($s0)
    MEM_H(0X136, ctx->r16) = ctx->r3;
    func_8000E35C(rdram, ctx);
        goto after_14;
    // 0x80021A40: sh          $v1, 0x136($s0)
    MEM_H(0X136, ctx->r16) = ctx->r3;
    after_14:
    // 0x80021A44: andi        $t4, $v0, 0x7
    ctx->r12 = ctx->r2 & 0X7;
    // 0x80021A48: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80021A4C: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x80021A50: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80021A54: lwc1        $f6, 0x6770($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6770);
    // 0x80021A58: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80021A5C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80021A60: jal         0x8000E35C
    // 0x80021A64: swc1        $f8, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->f8.u32l;
    func_8000E35C(rdram, ctx);
        goto after_15;
    // 0x80021A64: swc1        $f8, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->f8.u32l;
    after_15:
    // 0x80021A68: andi        $t6, $v0, 0x7
    ctx->r14 = ctx->r2 & 0X7;
    // 0x80021A6C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80021A70: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80021A74: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80021A78: lwc1        $f4, 0x6774($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6774);
    // 0x80021A7C: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80021A80: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80021A84: b           L_80021AD8
    // 0x80021A88: swc1        $f6, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f6.u32l;
        goto L_80021AD8;
    // 0x80021A88: swc1        $f6, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f6.u32l;
L_80021A8C:
    // 0x80021A8C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80021A90: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80021A94: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_80021A98:
    // 0x80021A98: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80021A9C: swc1        $f0, 0x8C($v0)
    MEM_W(0X8C, ctx->r2) = ctx->f0.u32l;
    // 0x80021AA0: bne         $a2, $v1, L_80021A98
    if (ctx->r6 != ctx->r3) {
        // 0x80021AA4: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80021A98;
    }
    // 0x80021AA4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80021AA8: jal         0x8000E35C
    // 0x80021AAC: nop

    func_8000E35C(rdram, ctx);
        goto after_16;
    // 0x80021AAC: nop

    after_16:
    // 0x80021AB0: andi        $t8, $v0, 0x7
    ctx->r24 = ctx->r2 & 0X7;
    // 0x80021AB4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80021AB8: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80021ABC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80021AC0: lwc1        $f8, 0x6778($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6778);
    // 0x80021AC4: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80021AC8: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x80021ACC: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80021AD0: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80021AD4: swc1        $f10, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->f10.u32l;
L_80021AD8:
    // 0x80021AD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80021ADC: jal         0x80044614
    // 0x80021AE0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80044614(rdram, ctx);
        goto after_17;
    // 0x80021AE0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_17:
    // 0x80021AE4: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80021AE8: sh          $t0, 0x13C($s0)
    MEM_H(0X13C, ctx->r16) = ctx->r8;
L_80021AEC:
    // 0x80021AEC: addiu       $t1, $s0, 0x8
    ctx->r9 = ADD32(ctx->r16, 0X8);
    // 0x80021AF0: jal         0x8000E35C
    // 0x80021AF4: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    func_8000E35C(rdram, ctx);
        goto after_18;
    // 0x80021AF4: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    after_18:
    // 0x80021AF8: andi        $t2, $v0, 0x7
    ctx->r10 = ctx->r2 & 0X7;
    // 0x80021AFC: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80021B00: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80021B04: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80021B08: lwc1        $f6, 0x677C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X677C);
    // 0x80021B0C: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80021B10: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80021B14: lwc1        $f10, 0x50($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80021B18: lw          $t4, 0x144($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X144);
    // 0x80021B1C: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80021B20: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80021B24: mul.s       $f0, $f18, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80021B28: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80021B2C: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80021B30: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x80021B34: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80021B38: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80021B3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80021B40: swc1        $f0, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f0.u32l;
    // 0x80021B44: swc1        $f0, 0x108($s0)
    MEM_W(0X108, ctx->r16) = ctx->f0.u32l;
    // 0x80021B48: beq         $t4, $zero, L_80021B68
    if (ctx->r12 == 0) {
        // 0x80021B4C: swc1        $f4, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
            goto L_80021B68;
    }
    // 0x80021B4C: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    // 0x80021B50: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80021B54: lwc1        $f8, 0x6780($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6780);
    // 0x80021B58: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80021B5C: sub.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80021B60: b           L_80021B7C
    // 0x80021B64: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
        goto L_80021B7C;
    // 0x80021B64: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
L_80021B68:
    // 0x80021B68: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80021B6C: lwc1        $f4, 0x6784($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6784);
    // 0x80021B70: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80021B74: sub.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80021B78: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
L_80021B7C:
    // 0x80021B7C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80021B80: lwc1        $f18, 0x98($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X98);
    // 0x80021B84: beq         $a2, $v1, L_80021BA8
    if (ctx->r6 == ctx->r3) {
        // 0x80021B88: lwc1        $f16, 0x8C($v0)
        ctx->f16.u32l = MEM_W(ctx->r2, 0X8C);
            goto L_80021BA8;
    }
    // 0x80021B88: lwc1        $f16, 0x8C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8C);
L_80021B8C:
    // 0x80021B8C: add.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80021B90: lwc1        $f18, 0x9C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X9C);
    // 0x80021B94: lwc1        $f16, 0x90($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X90);
    // 0x80021B98: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80021B9C: swc1        $f14, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->f14.u32l;
    // 0x80021BA0: bne         $a2, $v1, L_80021B8C
    if (ctx->r6 != ctx->r3) {
        // 0x80021BA4: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80021B8C;
    }
    // 0x80021BA4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80021BA8:
    // 0x80021BA8: add.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80021BAC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80021BB0: swc1        $f14, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->f14.u32l;
    // 0x80021BB4: lw          $t5, 0x144($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X144);
    // 0x80021BB8: beql        $t5, $zero, L_80021C04
    if (ctx->r13 == 0) {
        // 0x80021BBC: lui         $at, 0xC396
        ctx->r1 = S32(0XC396 << 16);
            goto L_80021C04;
    }
    goto skip_6;
    // 0x80021BBC: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    skip_6:
    // 0x80021BC0: lh          $t6, 0x136($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X136);
    // 0x80021BC4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80021BC8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80021BCC: bnel        $t6, $zero, L_80021C04
    if (ctx->r14 != 0) {
        // 0x80021BD0: lui         $at, 0xC396
        ctx->r1 = S32(0XC396 << 16);
            goto L_80021C04;
    }
    goto skip_7;
    // 0x80021BD0: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    skip_7:
    // 0x80021BD4: jal         0x80042F80
    // 0x80021BD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80042F80(rdram, ctx);
        goto after_19;
    // 0x80021BD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_19:
    // 0x80021BDC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80021BE0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80021BE4: jal         0x80043714
    // 0x80021BE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80043714(rdram, ctx);
        goto after_20;
    // 0x80021BE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_20:
    // 0x80021BEC: jal         0x8000E35C
    // 0x80021BF0: nop

    func_8000E35C(rdram, ctx);
        goto after_21;
    // 0x80021BF0: nop

    after_21:
    // 0x80021BF4: andi        $t7, $v0, 0x3F
    ctx->r15 = ctx->r2 & 0X3F;
    // 0x80021BF8: addiu       $t8, $t7, 0x5
    ctx->r24 = ADD32(ctx->r15, 0X5);
    // 0x80021BFC: sh          $t8, 0x136($s0)
    MEM_H(0X136, ctx->r16) = ctx->r24;
    // 0x80021C00: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
L_80021C04:
    // 0x80021C04: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80021C08: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80021C0C: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80021C10: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x80021C14: nop

    // 0x80021C18: bc1f        L_80021C28
    if (!c1cs) {
        // 0x80021C1C: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80021C28;
    }
    // 0x80021C1C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80021C20: b           L_80021C60
    // 0x80021C24: sh          $t9, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r25;
        goto L_80021C60;
    // 0x80021C24: sh          $t9, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r25;
L_80021C28:
    // 0x80021C28: jal         0x8000D3A4
    // 0x80021C2C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8000D3A4(rdram, ctx);
        goto after_22;
    // 0x80021C2C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_22:
    // 0x80021C30: beq         $v0, $zero, L_80022030
    if (ctx->r2 == 0) {
        // 0x80021C34: addiu       $a0, $sp, 0x60
        ctx->r4 = ADD32(ctx->r29, 0X60);
            goto L_80022030;
    }
    // 0x80021C34: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80021C38: jal         0x80003668
    // 0x80021C3C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80003668(rdram, ctx);
        goto after_23;
    // 0x80021C3C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_23:
    // 0x80021C40: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80021C44: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80021C48: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80021C4C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80021C50: nop

    // 0x80021C54: bc1f        L_80022030
    if (!c1cs) {
        // 0x80021C58: nop
    
            goto L_80022030;
    }
    // 0x80021C58: nop

    // 0x80021C5C: sh          $t0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r8;
L_80021C60:
    // 0x80021C60: lh          $v0, 0x140($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X140);
    // 0x80021C64: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x80021C68: beq         $t1, $zero, L_80021C74
    if (ctx->r9 == 0) {
        // 0x80021C6C: andi        $t2, $v0, 0xFFFE
        ctx->r10 = ctx->r2 & 0XFFFE;
            goto L_80021C74;
    }
    // 0x80021C6C: andi        $t2, $v0, 0xFFFE
    ctx->r10 = ctx->r2 & 0XFFFE;
    // 0x80021C70: sh          $t2, 0x140($s0)
    MEM_H(0X140, ctx->r16) = ctx->r10;
L_80021C74:
    // 0x80021C74: sh          $zero, 0xE8($s0)
    MEM_H(0XE8, ctx->r16) = 0;
    // 0x80021C78: jal         0x8004A0C4
    // 0x80021C7C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    func_8004A0C4(rdram, ctx);
        goto after_24;
    // 0x80021C7C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_24:
    // 0x80021C80: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80021C84: sh          $t3, 0x112($s0)
    MEM_H(0X112, ctx->r16) = ctx->r11;
    // 0x80021C88: lh          $t4, 0x112($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X112);
    // 0x80021C8C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80021C90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80021C94: jal         0x800201B8
    // 0x80021C98: sh          $t4, -0x6B7E($at)
    MEM_H(-0X6B7E, ctx->r1) = ctx->r12;
    func_800201B8(rdram, ctx);
        goto after_25;
    // 0x80021C98: sh          $t4, -0x6B7E($at)
    MEM_H(-0X6B7E, ctx->r1) = ctx->r12;
    after_25:
    // 0x80021C9C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80021CA0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80021CA4: jal         0x80042F80
    // 0x80021CA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80042F80(rdram, ctx);
        goto after_26;
    // 0x80021CA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_26:
    // 0x80021CAC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80021CB0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80021CB4: jal         0x80043714
    // 0x80021CB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80043714(rdram, ctx);
        goto after_27;
    // 0x80021CB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_27:
    // 0x80021CBC: lw          $a0, 0xAC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XAC);
    // 0x80021CC0: beq         $a0, $zero, L_80021CD0
    if (ctx->r4 == 0) {
        // 0x80021CC4: nop
    
            goto L_80021CD0;
    }
    // 0x80021CC4: nop

    // 0x80021CC8: jal         0x800444F8
    // 0x80021CCC: nop

    func_800444F8(rdram, ctx);
        goto after_28;
    // 0x80021CCC: nop

    after_28:
L_80021CD0:
    // 0x80021CD0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80021CD4: addiu       $v0, $v0, -0x6BE0
    ctx->r2 = ADD32(ctx->r2, -0X6BE0);
    // 0x80021CD8: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80021CDC: addiu       $t7, $zero, 0x5A
    ctx->r15 = ADD32(0, 0X5A);
    // 0x80021CE0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80021CE4: ori         $t6, $t5, 0x10
    ctx->r14 = ctx->r13 | 0X10;
    // 0x80021CE8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80021CEC: sh          $t7, 0x134($s0)
    MEM_H(0X134, ctx->r16) = ctx->r15;
    // 0x80021CF0: sh          $zero, 0x136($s0)
    MEM_H(0X136, ctx->r16) = 0;
    // 0x80021CF4: sh          $zero, 0x138($s0)
    MEM_H(0X138, ctx->r16) = 0;
    // 0x80021CF8: lwc1        $f12, 0x6788($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X6788);
    // 0x80021CFC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80021D00: jal         0x80011534
    // 0x80021D04: lwc1        $f14, 0x678C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X678C);
    func_80011534(rdram, ctx);
        goto after_29;
    // 0x80021D04: lwc1        $f14, 0x678C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X678C);
    after_29:
    // 0x80021D08: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80021D0C: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x80021D10: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80021D14: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80021D18: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80021D1C: jal         0x8000ACEC
    // 0x80021D20: addiu       $a3, $zero, -0x5
    ctx->r7 = ADD32(0, -0X5);
    func_8000ACEC(rdram, ctx);
        goto after_30;
    // 0x80021D20: addiu       $a3, $zero, -0x5
    ctx->r7 = ADD32(0, -0X5);
    after_30:
    // 0x80021D24: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80021D28: b           L_80022030
    // 0x80021D2C: sh          $v1, 0x13C($s0)
    MEM_H(0X13C, ctx->r16) = ctx->r3;
        goto L_80022030;
    // 0x80021D2C: sh          $v1, 0x13C($s0)
    MEM_H(0X13C, ctx->r16) = ctx->r3;
L_80021D30:
    // 0x80021D30: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80021D34: lw          $v0, -0x6BE0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6BE0);
    // 0x80021D38: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80021D3C: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80021D40: andi        $t8, $v0, 0x20
    ctx->r24 = ctx->r2 & 0X20;
    // 0x80021D44: bne         $t8, $zero, L_80021DA4
    if (ctx->r24 != 0) {
        // 0x80021D48: addiu       $a1, $zero, 0x8
        ctx->r5 = ADD32(0, 0X8);
            goto L_80021DA4;
    }
    // 0x80021D48: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80021D4C: lh          $t9, -0x6B8E($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X6B8E);
    // 0x80021D50: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80021D54: beql        $t9, $zero, L_80021D88
    if (ctx->r25 == 0) {
        // 0x80021D58: lh          $t3, 0x134($s0)
        ctx->r11 = MEM_H(ctx->r16, 0X134);
            goto L_80021D88;
    }
    goto skip_8;
    // 0x80021D58: lh          $t3, 0x134($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X134);
    skip_8:
    // 0x80021D5C: lhu         $t0, -0x2E5A($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X2E5A);
    // 0x80021D60: ori         $t2, $v0, 0x20
    ctx->r10 = ctx->r2 | 0X20;
    // 0x80021D64: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80021D68: andi        $t1, $t0, 0x1000
    ctx->r9 = ctx->r8 & 0X1000;
    // 0x80021D6C: beql        $t1, $zero, L_80021DA8
    if (ctx->r9 == 0) {
        // 0x80021D70: lh          $t5, 0x136($s0)
        ctx->r13 = MEM_H(ctx->r16, 0X136);
            goto L_80021DA8;
    }
    goto skip_9;
    // 0x80021D70: lh          $t5, 0x136($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X136);
    skip_9:
    // 0x80021D74: sw          $t2, -0x6BE0($at)
    MEM_W(-0X6BE0, ctx->r1) = ctx->r10;
    // 0x80021D78: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80021D7C: b           L_80021DA4
    // 0x80021D80: sh          $zero, -0x6B94($at)
    MEM_H(-0X6B94, ctx->r1) = 0;
        goto L_80021DA4;
    // 0x80021D80: sh          $zero, -0x6B94($at)
    MEM_H(-0X6B94, ctx->r1) = 0;
    // 0x80021D84: lh          $t3, 0x134($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X134);
L_80021D88:
    // 0x80021D88: ori         $t4, $v0, 0x20
    ctx->r12 = ctx->r2 | 0X20;
    // 0x80021D8C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80021D90: bnel        $t3, $zero, L_80021DA8
    if (ctx->r11 != 0) {
        // 0x80021D94: lh          $t5, 0x136($s0)
        ctx->r13 = MEM_H(ctx->r16, 0X136);
            goto L_80021DA8;
    }
    goto skip_10;
    // 0x80021D94: lh          $t5, 0x136($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X136);
    skip_10:
    // 0x80021D98: sw          $t4, -0x6BE0($at)
    MEM_W(-0X6BE0, ctx->r1) = ctx->r12;
    // 0x80021D9C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80021DA0: sh          $zero, -0x6B94($at)
    MEM_H(-0X6B94, ctx->r1) = 0;
L_80021DA4:
    // 0x80021DA4: lh          $t5, 0x136($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X136);
L_80021DA8:
    // 0x80021DA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80021DAC: bnel        $t5, $zero, L_80021DE4
    if (ctx->r13 != 0) {
        // 0x80021DB0: lh          $t9, 0x138($s0)
        ctx->r25 = MEM_H(ctx->r16, 0X138);
            goto L_80021DE4;
    }
    goto skip_11;
    // 0x80021DB0: lh          $t9, 0x138($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X138);
    skip_11:
    // 0x80021DB4: jal         0x80042F80
    // 0x80021DB8: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    func_80042F80(rdram, ctx);
        goto after_31;
    // 0x80021DB8: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_31:
    // 0x80021DBC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80021DC0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80021DC4: jal         0x80043714
    // 0x80021DC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80043714(rdram, ctx);
        goto after_32;
    // 0x80021DC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_32:
    // 0x80021DCC: jal         0x8000E35C
    // 0x80021DD0: nop

    func_8000E35C(rdram, ctx);
        goto after_33;
    // 0x80021DD0: nop

    after_33:
    // 0x80021DD4: andi        $t7, $v0, 0x7F
    ctx->r15 = ctx->r2 & 0X7F;
    // 0x80021DD8: addiu       $t8, $t7, 0x28
    ctx->r24 = ADD32(ctx->r15, 0X28);
    // 0x80021DDC: sh          $t8, 0x136($s0)
    MEM_H(0X136, ctx->r16) = ctx->r24;
    // 0x80021DE0: lh          $t9, 0x138($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X138);
L_80021DE4:
    // 0x80021DE4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80021DE8: addiu       $v1, $sp, 0x50
    ctx->r3 = ADD32(ctx->r29, 0X50);
    // 0x80021DEC: bne         $t9, $zero, L_80022030
    if (ctx->r25 != 0) {
        // 0x80021DF0: addiu       $a0, $sp, 0x5C
        ctx->r4 = ADD32(ctx->r29, 0X5C);
            goto L_80022030;
    }
    // 0x80021DF0: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
L_80021DF4:
    // 0x80021DF4: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80021DF8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80021DFC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80021E00: bne         $v1, $a0, L_80021DF4
    if (ctx->r3 != ctx->r4) {
        // 0x80021E04: swc1        $f18, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
            goto L_80021DF4;
    }
    // 0x80021E04: swc1        $f18, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
    // 0x80021E08: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80021E0C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80021E10: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80021E14: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80021E18: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80021E1C: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80021E20: jal         0x80043EF0
    // 0x80021E24: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    func_80043EF0(rdram, ctx);
        goto after_34;
    // 0x80021E24: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    after_34:
    // 0x80021E28: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x80021E2C: b           L_80022030
    // 0x80021E30: sh          $t0, 0x138($s0)
    MEM_H(0X138, ctx->r16) = ctx->r8;
        goto L_80022030;
    // 0x80021E30: sh          $t0, 0x138($s0)
    MEM_H(0X138, ctx->r16) = ctx->r8;
L_80021E34:
    // 0x80021E34: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80021E38: lwc1        $f8, 0x6790($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6790);
    // 0x80021E3C: lui         $at, 0x43F2
    ctx->r1 = S32(0X43F2 << 16);
    // 0x80021E40: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80021E44: lui         $at, 0xC3DE
    ctx->r1 = S32(0XC3DE << 16);
    // 0x80021E48: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80021E4C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80021E50: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x80021E54: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x80021E58: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x80021E5C: lwc1        $f4, 0x6794($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6794);
    // 0x80021E60: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80021E64: lwc1        $f10, 0x6798($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6798);
    // 0x80021E68: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80021E6C: lwc1        $f8, 0x679C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X679C);
    // 0x80021E70: addiu       $a0, $s0, 0x8C
    ctx->r4 = ADD32(ctx->r16, 0X8C);
    // 0x80021E74: addiu       $a1, $s0, 0x14
    ctx->r5 = ADD32(ctx->r16, 0X14);
    // 0x80021E78: addiu       $a2, $s0, 0x8
    ctx->r6 = ADD32(ctx->r16, 0X8);
    // 0x80021E7C: addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    // 0x80021E80: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    // 0x80021E84: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    // 0x80021E88: jal         0x8000CD08
    // 0x80021E8C: swc1        $f8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f8.u32l;
    func_8000CD08(rdram, ctx);
        goto after_35;
    // 0x80021E8C: swc1        $f8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f8.u32l;
    after_35:
    // 0x80021E90: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80021E94: lwc1        $f0, 0x90($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X90);
    // 0x80021E98: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80021E9C: swc1        $f18, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->f18.u32l;
    // 0x80021EA0: swc1        $f0, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = ctx->f0.u32l;
    // 0x80021EA4: lwc1        $f6, 0x67A0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X67A0);
    // 0x80021EA8: mul.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80021EAC: jal         0x8004F7C0
    // 0x80021EB0: nop

    func_8004F7C0(rdram, ctx);
        goto after_36;
    // 0x80021EB0: nop

    after_36:
    // 0x80021EB4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80021EB8: lwc1        $f10, 0x67A4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X67A4);
    // 0x80021EBC: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x80021EC0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80021EC4: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80021EC8: lwc1        $f18, 0x9C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x80021ECC: swc1        $f8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f8.u32l;
    // 0x80021ED0: lwc1        $f6, 0x67A8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X67A8);
    // 0x80021ED4: mul.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80021ED8: jal         0x8004F650
    // 0x80021EDC: nop

    func_8004F650(rdram, ctx);
        goto after_37;
    // 0x80021EDC: nop

    after_37:
    // 0x80021EE0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80021EE4: lwc1        $f10, 0x67AC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X67AC);
    // 0x80021EE8: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x80021EEC: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x80021EF0: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80021EF4: sh          $t1, 0x13C($s0)
    MEM_H(0X13C, ctx->r16) = ctx->r9;
    // 0x80021EF8: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
L_80021EFC:
    // 0x80021EFC: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80021F00: lwc1        $f6, 0x34($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80021F04: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80021F08: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80021F0C: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80021F10: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80021F14: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80021F18: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80021F1C: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x80021F20: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    // 0x80021F24: lw          $v0, -0x6BE0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6BE0);
    // 0x80021F28: andi        $t2, $v0, 0x20
    ctx->r10 = ctx->r2 & 0X20;
    // 0x80021F2C: bne         $t2, $zero, L_80022030
    if (ctx->r10 != 0) {
        // 0x80021F30: nop
    
            goto L_80022030;
    }
    // 0x80021F30: nop

    // 0x80021F34: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80021F38: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80021F3C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80021F40: ori         $t3, $v0, 0x20
    ctx->r11 = ctx->r2 | 0X20;
    // 0x80021F44: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x80021F48: nop

    // 0x80021F4C: bc1f        L_80022030
    if (!c1cs) {
        // 0x80021F50: nop
    
            goto L_80022030;
    }
    // 0x80021F50: nop

    // 0x80021F54: b           L_80022030
    // 0x80021F58: sw          $t3, -0x6BE0($at)
    MEM_W(-0X6BE0, ctx->r1) = ctx->r11;
        goto L_80022030;
    // 0x80021F58: sw          $t3, -0x6BE0($at)
    MEM_W(-0X6BE0, ctx->r1) = ctx->r11;
L_80021F5C:
    // 0x80021F5C: lui         $at, 0xC416
    ctx->r1 = S32(0XC416 << 16);
    // 0x80021F60: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80021F64: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x80021F68: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80021F6C: addiu       $t4, $zero, 0x7
    ctx->r12 = ADD32(0, 0X7);
    // 0x80021F70: sh          $t4, 0x13C($s0)
    MEM_H(0X13C, ctx->r16) = ctx->r12;
    // 0x80021F74: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x80021F78: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x80021F7C: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
L_80021F80:
    // 0x80021F80: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80021F84: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80021F88: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80021F8C: lh          $t5, 0x110($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X110);
    // 0x80021F90: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80021F94: div.s       $f18, $f0, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80021F98: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80021F9C: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80021FA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80021FA4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80021FA8: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80021FAC: addiu       $t7, $zero, 0xE10
    ctx->r15 = ADD32(0, 0XE10);
    // 0x80021FB0: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x80021FB4: sub.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x80021FB8: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x80021FBC: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80021FC0: lwc1        $f2, -0x6024($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6024);
    // 0x80021FC4: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x80021FC8: nop

    // 0x80021FCC: bc1f        L_80021FF4
    if (!c1cs) {
        // 0x80021FD0: nop
    
            goto L_80021FF4;
    }
    // 0x80021FD0: nop

    // 0x80021FD4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80021FD8: swc1        $f2, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f2.u32l;
L_80021FDC:
    // 0x80021FDC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80021FE0: swc1        $f16, 0xC4($v0)
    MEM_W(0XC4, ctx->r2) = ctx->f16.u32l;
    // 0x80021FE4: bne         $a2, $v1, L_80021FDC
    if (ctx->r6 != ctx->r3) {
        // 0x80021FE8: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80021FDC;
    }
    // 0x80021FE8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80021FEC: sh          $t7, 0x13A($s0)
    MEM_H(0X13A, ctx->r16) = ctx->r15;
    // 0x80021FF0: sh          $t8, 0x13C($s0)
    MEM_H(0X13C, ctx->r16) = ctx->r24;
L_80021FF4:
    // 0x80021FF4: b           L_80022030
    // 0x80021FF8: nop

        goto L_80022030;
    // 0x80021FF8: nop

L_80021FFC:
    // 0x80021FFC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80022000: lhu         $t9, -0x2E5A($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X2E5A);
    // 0x80022004: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80022008: andi        $t0, $t9, 0x1000
    ctx->r8 = ctx->r25 & 0X1000;
    // 0x8002200C: bne         $t0, $zero, L_80022020
    if (ctx->r8 != 0) {
        // 0x80022010: nop
    
            goto L_80022020;
    }
    // 0x80022010: nop

    // 0x80022014: lh          $t1, 0x13A($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X13A);
    // 0x80022018: bne         $t1, $zero, L_80022030
    if (ctx->r9 != 0) {
        // 0x8002201C: nop
    
            goto L_80022030;
    }
    // 0x8002201C: nop

L_80022020:
    // 0x80022020: lw          $t2, -0x6BE0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X6BE0);
    // 0x80022024: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80022028: ori         $t3, $t2, 0x20
    ctx->r11 = ctx->r10 | 0X20;
    // 0x8002202C: sw          $t3, -0x6BE0($at)
    MEM_W(-0X6BE0, ctx->r1) = ctx->r11;
L_80022030:
    // 0x80022030: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80022034: lw          $t4, -0x6BE0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X6BE0);
    // 0x80022038: andi        $t5, $t4, 0x10
    ctx->r13 = ctx->r12 & 0X10;
    // 0x8002203C: bnel        $t5, $zero, L_80022430
    if (ctx->r13 != 0) {
        // 0x80022040: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80022430;
    }
    goto skip_12;
    // 0x80022040: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_12:
    // 0x80022044: lh          $v0, 0xE8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XE8);
    // 0x80022048: lh          $t6, 0xEC($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XEC);
    // 0x8002204C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80022050: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80022054: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80022058: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002205C: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80022060: lh          $t9, 0xEA($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XEA);
    // 0x80022064: subu        $v1, $t9, $v0
    ctx->r3 = SUB32(ctx->r25, ctx->r2);
    // 0x80022068: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002206C: sll         $t0, $v1, 16
    ctx->r8 = S32(ctx->r3 << 16);
    // 0x80022070: sra         $t1, $t0, 16
    ctx->r9 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80022074: slti        $at, $t1, 0x33
    ctx->r1 = SIGNED(ctx->r9) < 0X33 ? 1 : 0;
    // 0x80022078: div.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8002207C: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80022080: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80022084: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x80022088: blez        $t1, L_80022208
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8002208C: sh          $t8, 0xEE($s0)
        MEM_H(0XEE, ctx->r16) = ctx->r24;
            goto L_80022208;
    }
    // 0x8002208C: sh          $t8, 0xEE($s0)
    MEM_H(0XEE, ctx->r16) = ctx->r24;
    // 0x80022090: bne         $at, $zero, L_80022198
    if (ctx->r1 != 0) {
        // 0x80022094: sh          $v0, 0xEA($s0)
        MEM_H(0XEA, ctx->r16) = ctx->r2;
            goto L_80022198;
    }
    // 0x80022094: sh          $v0, 0xEA($s0)
    MEM_H(0XEA, ctx->r16) = ctx->r2;
    // 0x80022098: lh          $t2, 0x38($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X38);
    // 0x8002209C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x800220A0: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x800220A4: bne         $t2, $zero, L_800220BC
    if (ctx->r10 != 0) {
        // 0x800220A8: addiu       $a2, $zero, 0x4
        ctx->r6 = ADD32(0, 0X4);
            goto L_800220BC;
    }
    // 0x800220A8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800220AC: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x800220B0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800220B4: jal         0x8000ACEC
    // 0x800220B8: addiu       $a3, $zero, -0x4
    ctx->r7 = ADD32(0, -0X4);
    func_8000ACEC(rdram, ctx);
        goto after_38;
    // 0x800220B8: addiu       $a3, $zero, -0x4
    ctx->r7 = ADD32(0, -0X4);
    after_38:
L_800220BC:
    // 0x800220BC: lw          $t5, 0x12C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X12C);
    // 0x800220C0: addiu       $t4, $zero, 0x78
    ctx->r12 = ADD32(0, 0X78);
    // 0x800220C4: sh          $t4, 0x156($s0)
    MEM_H(0X156, ctx->r16) = ctx->r12;
    // 0x800220C8: bne         $t5, $zero, L_80022184
    if (ctx->r13 != 0) {
        // 0x800220CC: addiu       $a0, $s0, 0x8
        ctx->r4 = ADD32(ctx->r16, 0X8);
            goto L_80022184;
    }
    // 0x800220CC: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x800220D0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800220D4: addiu       $a2, $s0, 0x128
    ctx->r6 = ADD32(ctx->r16, 0X128);
    // 0x800220D8: jal         0x80042F80
    // 0x800220DC: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    func_80042F80(rdram, ctx);
        goto after_39;
    // 0x800220DC: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_39:
    // 0x800220E0: beq         $v0, $zero, L_800220F0
    if (ctx->r2 == 0) {
        // 0x800220E4: sw          $v0, 0x12C($s0)
        MEM_W(0X12C, ctx->r16) = ctx->r2;
            goto L_800220F0;
    }
    // 0x800220E4: sw          $v0, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->r2;
    // 0x800220E8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800220EC: sh          $t6, 0x128($s0)
    MEM_H(0X128, ctx->r16) = ctx->r14;
L_800220F0:
    // 0x800220F0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800220F4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800220F8: jal         0x80043714
    // 0x800220FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80043714(rdram, ctx);
        goto after_40;
    // 0x800220FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_40:
    // 0x80022100: lh          $t7, 0x110($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X110);
    // 0x80022104: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80022108: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8002210C: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80022110: lwc1        $f10, -0x604C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X604C);
    // 0x80022114: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80022118: swc1        $f10, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f10.u32l;
    // 0x8002211C: lwc1        $f12, 0x67B0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X67B0);
    // 0x80022120: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80022124: jal         0x80011534
    // 0x80022128: lwc1        $f14, 0x67B4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X67B4);
    func_80011534(rdram, ctx);
        goto after_41;
    // 0x80022128: lwc1        $f14, 0x67B4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X67B4);
    after_41:
    // 0x8002212C: lh          $v0, 0x140($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X140);
    // 0x80022130: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x80022134: beq         $t9, $zero, L_80022140
    if (ctx->r25 == 0) {
        // 0x80022138: andi        $t0, $v0, 0xFFFE
        ctx->r8 = ctx->r2 & 0XFFFE;
            goto L_80022140;
    }
    // 0x80022138: andi        $t0, $v0, 0xFFFE
    ctx->r8 = ctx->r2 & 0XFFFE;
    // 0x8002213C: sh          $t0, 0x140($s0)
    MEM_H(0X140, ctx->r16) = ctx->r8;
L_80022140:
    // 0x80022140: lh          $t1, 0x112($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X112);
    // 0x80022144: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80022148: beql        $t1, $at, L_80022188
    if (ctx->r9 == ctx->r1) {
        // 0x8002214C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80022188;
    }
    goto skip_13;
    // 0x8002214C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_13:
    // 0x80022150: lh          $t2, 0xEE($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XEE);
    // 0x80022154: slti        $at, $t2, 0x15
    ctx->r1 = SIGNED(ctx->r10) < 0X15 ? 1 : 0;
    // 0x80022158: beql        $at, $zero, L_80022188
    if (ctx->r1 == 0) {
        // 0x8002215C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80022188;
    }
    goto skip_14;
    // 0x8002215C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_14:
    // 0x80022160: jal         0x8004A0C4
    // 0x80022164: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    func_8004A0C4(rdram, ctx);
        goto after_42;
    // 0x80022164: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_42:
    // 0x80022168: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8002216C: sh          $t3, 0x112($s0)
    MEM_H(0X112, ctx->r16) = ctx->r11;
    // 0x80022170: lh          $t4, 0x112($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X112);
    // 0x80022174: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80022178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002217C: jal         0x800201B8
    // 0x80022180: sh          $t4, -0x6B7E($at)
    MEM_H(-0X6B7E, ctx->r1) = ctx->r12;
    func_800201B8(rdram, ctx);
        goto after_43;
    // 0x80022180: sh          $t4, -0x6B7E($at)
    MEM_H(-0X6B7E, ctx->r1) = ctx->r12;
    after_43:
L_80022184:
    // 0x80022184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80022188:
    // 0x80022188: jal         0x80044614
    // 0x8002218C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80044614(rdram, ctx);
        goto after_44;
    // 0x8002218C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_44:
    // 0x80022190: b           L_800221EC
    // 0x80022194: lh          $t7, 0x13E($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X13E);
        goto L_800221EC;
    // 0x80022194: lh          $t7, 0x13E($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X13E);
L_80022198:
    // 0x80022198: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8002219C: lwc1        $f12, 0x67B8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X67B8);
    // 0x800221A0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800221A4: jal         0x80011534
    // 0x800221A8: lwc1        $f14, 0x67BC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X67BC);
    func_80011534(rdram, ctx);
        goto after_45;
    // 0x800221A8: lwc1        $f14, 0x67BC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X67BC);
    after_45:
    // 0x800221AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800221B0: jal         0x80044614
    // 0x800221B4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80044614(rdram, ctx);
        goto after_46;
    // 0x800221B4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_46:
    // 0x800221B8: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800221BC: lh          $t5, -0x68C4($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X68C4);
    // 0x800221C0: lh          $t6, 0x38($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X38);
    // 0x800221C4: bnel        $t5, $zero, L_800221EC
    if (ctx->r13 != 0) {
        // 0x800221C8: lh          $t7, 0x13E($s0)
        ctx->r15 = MEM_H(ctx->r16, 0X13E);
            goto L_800221EC;
    }
    goto skip_15;
    // 0x800221C8: lh          $t7, 0x13E($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X13E);
    skip_15:
    // 0x800221CC: bne         $t6, $zero, L_800221E8
    if (ctx->r14 != 0) {
        // 0x800221D0: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_800221E8;
    }
    // 0x800221D0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800221D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800221D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800221DC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800221E0: jal         0x8000ACEC
    // 0x800221E4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8000ACEC(rdram, ctx);
        goto after_47;
    // 0x800221E4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_47:
L_800221E8:
    // 0x800221E8: lh          $t7, 0x13E($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X13E);
L_800221EC:
    // 0x800221EC: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800221F0: beq         $t8, $zero, L_80022200
    if (ctx->r24 == 0) {
        // 0x800221F4: nop
    
            goto L_80022200;
    }
    // 0x800221F4: nop

    // 0x800221F8: lh          $t9, 0xEC($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XEC);
    // 0x800221FC: sh          $t9, 0xE8($s0)
    MEM_H(0XE8, ctx->r16) = ctx->r25;
L_80022200:
    // 0x80022200: b           L_80022250
    // 0x80022204: nop

        goto L_80022250;
    // 0x80022204: nop

L_80022208:
    // 0x80022208: lw          $t0, 0x12C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X12C);
    // 0x8002220C: beq         $t0, $zero, L_80022250
    if (ctx->r8 == 0) {
        // 0x80022210: nop
    
            goto L_80022250;
    }
    // 0x80022210: nop

    // 0x80022214: lh          $t1, 0x128($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X128);
    // 0x80022218: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002221C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80022220: beq         $t1, $zero, L_8002224C
    if (ctx->r9 == 0) {
        // 0x80022224: addiu       $a0, $zero, 0xC
        ctx->r4 = ADD32(0, 0XC);
            goto L_8002224C;
    }
    // 0x80022224: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
L_80022228:
    // 0x80022228: lw          $t2, 0x12C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X12C);
    // 0x8002222C: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80022230: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80022234: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x80022238: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8002223C: bne         $v1, $a0, L_80022228
    if (ctx->r3 != ctx->r4) {
        // 0x80022240: swc1        $f8, 0x8($t3)
        MEM_W(0X8, ctx->r11) = ctx->f8.u32l;
            goto L_80022228;
    }
    // 0x80022240: swc1        $f8, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f8.u32l;
    // 0x80022244: b           L_80022250
    // 0x80022248: nop

        goto L_80022250;
    // 0x80022248: nop

L_8002224C:
    // 0x8002224C: sw          $zero, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = 0;
L_80022250:
    // 0x80022250: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80022254: lh          $v0, -0x68C4($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X68C4);
    // 0x80022258: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8002225C: beq         $v0, $zero, L_80022268
    if (ctx->r2 == 0) {
        // 0x80022260: addiu       $t4, $v0, -0x1
        ctx->r12 = ADD32(ctx->r2, -0X1);
            goto L_80022268;
    }
    // 0x80022260: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x80022264: sh          $t4, -0x68C4($at)
    MEM_H(-0X68C4, ctx->r1) = ctx->r12;
L_80022268:
    // 0x80022268: lh          $t5, 0xEE($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XEE);
    // 0x8002226C: slti        $at, $t5, 0x15
    ctx->r1 = SIGNED(ctx->r13) < 0X15 ? 1 : 0;
    // 0x80022270: beql        $at, $zero, L_80022298
    if (ctx->r1 == 0) {
        // 0x80022274: lw          $t8, 0x144($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X144);
            goto L_80022298;
    }
    goto skip_16;
    // 0x80022274: lw          $t8, 0x144($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X144);
    skip_16:
    // 0x80022278: lh          $t6, 0x134($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X134);
    // 0x8002227C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80022280: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80022284: bne         $t6, $zero, L_80022294
    if (ctx->r14 != 0) {
        // 0x80022288: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80022294;
    }
    // 0x80022288: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002228C: jal         0x80043EF0
    // 0x80022290: sh          $t7, 0x134($s0)
    MEM_H(0X134, ctx->r16) = ctx->r15;
    func_80043EF0(rdram, ctx);
        goto after_48;
    // 0x80022290: sh          $t7, 0x134($s0)
    MEM_H(0X134, ctx->r16) = ctx->r15;
    after_48:
L_80022294:
    // 0x80022294: lw          $t8, 0x144($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X144);
L_80022298:
    // 0x80022298: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002229C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800222A0: bnel        $t8, $zero, L_800222C8
    if (ctx->r24 != 0) {
        // 0x800222A4: lh          $v0, 0xEE($s0)
        ctx->r2 = MEM_H(ctx->r16, 0XEE);
            goto L_800222C8;
    }
    goto skip_17;
    // 0x800222A4: lh          $v0, 0xEE($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XEE);
    skip_17:
    // 0x800222A8: lwc1        $f18, 0x130($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X130);
    // 0x800222AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800222B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800222B4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800222B8: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800222BC: b           L_80022314
    // 0x800222C0: swc1        $f4, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f4.u32l;
        goto L_80022314;
    // 0x800222C0: swc1        $f4, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f4.u32l;
    // 0x800222C4: lh          $v0, 0xEE($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XEE);
L_800222C8:
    // 0x800222C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800222CC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800222D0: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x800222D4: beq         $at, $zero, L_800222E4
    if (ctx->r1 == 0) {
        // 0x800222D8: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_800222E4;
    }
    // 0x800222D8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800222DC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800222E0: nop

L_800222E4:
    // 0x800222E4: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x800222E8: beq         $at, $zero, L_800222F8
    if (ctx->r1 == 0) {
        // 0x800222EC: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_800222F8;
    }
    // 0x800222EC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800222F0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800222F4: nop

L_800222F8:
    // 0x800222F8: lh          $t9, 0x140($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X140);
    // 0x800222FC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80022300: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x80022304: beql        $t0, $zero, L_80022318
    if (ctx->r8 == 0) {
        // 0x80022308: lwc1        $f0, 0x130($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X130);
            goto L_80022318;
    }
    goto skip_18;
    // 0x80022308: lwc1        $f0, 0x130($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X130);
    skip_18:
    // 0x8002230C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80022310: nop

L_80022314:
    // 0x80022314: lwc1        $f0, 0x130($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X130);
L_80022318:
    // 0x80022318: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8002231C: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80022320: nop

    // 0x80022324: bc1fl       L_8002238C
    if (!c1cs) {
        // 0x80022328: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_8002238C;
    }
    goto skip_19;
    // 0x80022328: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    skip_19:
    // 0x8002232C: lwc1        $f8, 0x67C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X67C0);
    // 0x80022330: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80022334: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80022338: sub.s       $f18, $f0, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8002233C: swc1        $f18, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f18.u32l;
    // 0x80022340: lwc1        $f6, 0x130($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X130);
    // 0x80022344: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x80022348: nop

    // 0x8002234C: bc1fl       L_8002235C
    if (!c1cs) {
        // 0x80022350: lw          $t1, 0x144($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X144);
            goto L_8002235C;
    }
    goto skip_20;
    // 0x80022350: lw          $t1, 0x144($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X144);
    skip_20:
    // 0x80022354: swc1        $f12, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f12.u32l;
    // 0x80022358: lw          $t1, 0x144($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X144);
L_8002235C:
    // 0x8002235C: beql        $t1, $zero, L_8002238C
    if (ctx->r9 == 0) {
        // 0x80022360: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_8002238C;
    }
    goto skip_21;
    // 0x80022360: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    skip_21:
    // 0x80022364: lh          $t2, 0xEE($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XEE);
    // 0x80022368: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x8002236C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80022370: slti        $at, $t2, 0x15
    ctx->r1 = SIGNED(ctx->r10) < 0X15 ? 1 : 0;
    // 0x80022374: bnel        $at, $zero, L_8002238C
    if (ctx->r1 != 0) {
        // 0x80022378: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_8002238C;
    }
    goto skip_22;
    // 0x80022378: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    skip_22:
    // 0x8002237C: jal         0x80043EF0
    // 0x80022380: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    func_80043EF0(rdram, ctx);
        goto after_49;
    // 0x80022380: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    after_49:
    // 0x80022384: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80022388: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8002238C:
    // 0x8002238C: addiu       $v1, $sp, 0x44
    ctx->r3 = ADD32(ctx->r29, 0X44);
L_80022390:
    // 0x80022390: lwc1        $f12, 0xB8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XB8);
    // 0x80022394: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    // 0x80022398: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x8002239C: jal         0x8004F7C0
    // 0x800223A0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_8004F7C0(rdram, ctx);
        goto after_50;
    // 0x800223A0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_50:
    // 0x800223A4: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x800223A8: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800223AC: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800223B0: lwc1        $f4, 0xC4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC4);
    // 0x800223B4: addiu       $t3, $sp, 0x50
    ctx->r11 = ADD32(ctx->r29, 0X50);
    // 0x800223B8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800223BC: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800223C0: sltu        $at, $v1, $t3
    ctx->r1 = ctx->r3 < ctx->r11 ? 1 : 0;
    // 0x800223C4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800223C8: mul.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800223CC: swc1        $f8, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f8.u32l;
    // 0x800223D0: lwc1        $f18, 0xB4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XB4);
    // 0x800223D4: lwc1        $f6, 0xCC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XCC);
    // 0x800223D8: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800223DC: bne         $at, $zero, L_80022390
    if (ctx->r1 != 0) {
        // 0x800223E0: swc1        $f4, 0xB4($v0)
        MEM_W(0XB4, ctx->r2) = ctx->f4.u32l;
            goto L_80022390;
    }
    // 0x800223E0: swc1        $f4, 0xB4($v0)
    MEM_W(0XB4, ctx->r2) = ctx->f4.u32l;
    // 0x800223E4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800223E8: addiu       $v1, $sp, 0x44
    ctx->r3 = ADD32(ctx->r29, 0X44);
    // 0x800223EC: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800223F0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800223F4: lwc1        $f18, 0x98($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X98);
    // 0x800223F8: beq         $v1, $a0, L_80022420
    if (ctx->r3 == ctx->r4) {
        // 0x800223FC: lwc1        $f16, -0x4($v1)
        ctx->f16.u32l = MEM_W(ctx->r3, -0X4);
            goto L_80022420;
    }
    // 0x800223FC: lwc1        $f16, -0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, -0X4);
    // 0x80022400: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
L_80022404:
    // 0x80022404: lwc1        $f18, 0x9C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X9C);
    // 0x80022408: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8002240C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80022410: swc1        $f14, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f14.u32l;
    // 0x80022414: lwc1        $f16, -0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, -0X4);
    // 0x80022418: bnel        $v1, $a0, L_80022404
    if (ctx->r3 != ctx->r4) {
        // 0x8002241C: add.s       $f14, $f16, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
            goto L_80022404;
    }
    goto skip_23;
    // 0x8002241C: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    skip_23:
L_80022420:
    // 0x80022420: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80022424: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80022428: swc1        $f14, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f14.u32l;
    // 0x8002242C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80022430:
    // 0x80022430: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80022434: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80022438: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80022440(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80022440: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x80022444: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80022448: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002244C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80022450: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80022454: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80022458: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8002245C: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80022460: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80022464: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80022468: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8002246C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80022470: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80022474: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80022478: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8002247C: ldc1        $f22, 0x67C8($at)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r1, 0X67C8);
    // 0x80022480: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80022484: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80022488: addiu       $s3, $sp, 0xB0
    ctx->r19 = ADD32(ctx->r29, 0XB0);
L_8002248C:
    // 0x8002248C: lw          $v0, 0x100($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X100);
    // 0x80022490: beq         $v0, $zero, L_8002257C
    if (ctx->r2 == 0) {
        // 0x80022494: nop
    
            goto L_8002257C;
    }
    // 0x80022494: nop

    // 0x80022498: lw          $t6, 0x4($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X4);
    // 0x8002249C: addiu       $s2, $v0, 0x10
    ctx->r18 = ADD32(ctx->r2, 0X10);
    // 0x800224A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800224A4: lw          $a1, 0xC($t6)
    ctx->r5 = MEM_W(ctx->r14, 0XC);
    // 0x800224A8: jal         0x80002340
    // 0x800224AC: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    func_80002340(rdram, ctx);
        goto after_0;
    // 0x800224AC: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_0:
    // 0x800224B0: bne         $s1, $zero, L_800224D4
    if (ctx->r17 != 0) {
        // 0x800224B4: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800224D4;
    }
    // 0x800224B4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800224B8: lw          $a1, 0xF8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XF8);
    // 0x800224BC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800224C0: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x800224C4: jal         0x80049840
    // 0x800224C8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    func_80049840(rdram, ctx);
        goto after_1;
    // 0x800224C8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_1:
    // 0x800224CC: b           L_80022540
    // 0x800224D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
        goto L_80022540;
    // 0x800224D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800224D4:
    // 0x800224D4: lh          $t7, 0x110($s4)
    ctx->r15 = MEM_H(ctx->r20, 0X110);
    // 0x800224D8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800224DC: bnel        $t7, $at, L_80022510
    if (ctx->r15 != ctx->r1) {
        // 0x800224E0: lwc1        $f8, 0xF8($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0XF8);
            goto L_80022510;
    }
    goto skip_0;
    // 0x800224E0: lwc1        $f8, 0xF8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XF8);
    skip_0:
    // 0x800224E4: lwc1        $f4, 0xF8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x800224E8: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x800224EC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800224F0: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800224F4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x800224F8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800224FC: jal         0x80049840
    // 0x80022500: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80049840(rdram, ctx);
        goto after_2;
    // 0x80022500: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_2:
    // 0x80022504: b           L_80022540
    // 0x80022508: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
        goto L_80022540;
    // 0x80022508: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8002250C: lwc1        $f8, 0xF8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XF8);
L_80022510:
    // 0x80022510: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80022514: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80022518: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8002251C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80022520: sub.d       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f22.d); 
    ctx->f16.d = ctx->f10.d - ctx->f22.d;
    // 0x80022524: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80022528: neg.d       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = -ctx->f16.d;
    // 0x8002252C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80022530: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80022534: jal         0x80049840
    // 0x80022538: nop

    func_80049840(rdram, ctx);
        goto after_3;
    // 0x80022538: nop

    after_3:
    // 0x8002253C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80022540:
    // 0x80022540: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80022544: jal         0x80000BD8
    // 0x80022548: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_80000BD8(rdram, ctx);
        goto after_4;
    // 0x80022548: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_4:
    // 0x8002254C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80022550: lw          $t8, -0x6BE0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6BE0);
    // 0x80022554: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80022558: slti        $at, $s1, 0x8
    ctx->r1 = SIGNED(ctx->r17) < 0X8 ? 1 : 0;
    // 0x8002255C: andi        $t9, $t8, 0x10
    ctx->r25 = ctx->r24 & 0X10;
    // 0x80022560: bne         $t9, $zero, L_80022584
    if (ctx->r25 != 0) {
        // 0x80022564: nop
    
            goto L_80022584;
    }
    // 0x80022564: nop

    // 0x80022568: lwc1        $f6, 0xF8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x8002256C: lwc1        $f8, 0x108($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X108);
    // 0x80022570: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80022574: b           L_80022584
    // 0x80022578: swc1        $f10, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f10.u32l;
        goto L_80022584;
    // 0x80022578: swc1        $f10, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f10.u32l;
L_8002257C:
    // 0x8002257C: b           L_80022590
    // 0x80022580: lh          $v0, 0x110($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X110);
        goto L_80022590;
    // 0x80022580: lh          $v0, 0x110($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X110);
L_80022584:
    // 0x80022584: bne         $at, $zero, L_8002248C
    if (ctx->r1 != 0) {
        // 0x80022588: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8002248C;
    }
    // 0x80022588: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8002258C: lh          $v0, 0x110($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X110);
L_80022590:
    // 0x80022590: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80022594: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80022598: beq         $v0, $at, L_800225BC
    if (ctx->r2 == ctx->r1) {
        // 0x8002259C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800225BC;
    }
    // 0x8002259C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800225A0: beq         $v0, $at, L_80022618
    if (ctx->r2 == ctx->r1) {
        // 0x800225A4: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80022618;
    }
    // 0x800225A4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800225A8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800225AC: beq         $v0, $at, L_80022648
    if (ctx->r2 == ctx->r1) {
        // 0x800225B0: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80022648;
    }
    // 0x800225B0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800225B4: b           L_80022674
    // 0x800225B8: lw          $a1, 0x14($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X14);
        goto L_80022674;
    // 0x800225B8: lw          $a1, 0x14($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X14);
L_800225BC:
    // 0x800225BC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800225C0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800225C4: jal         0x80001A6C
    // 0x800225C8: lui         $a1, 0x430C
    ctx->r5 = S32(0X430C << 16);
    func_80001A6C(rdram, ctx);
        goto after_5;
    // 0x800225C8: lui         $a1, 0x430C
    ctx->r5 = S32(0X430C << 16);
    after_5:
    // 0x800225CC: lw          $v1, 0x100($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X100);
    // 0x800225D0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800225D4: addiu       $s2, $v1, 0x10
    ctx->r18 = ADD32(ctx->r3, 0X10);
    // 0x800225D8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800225DC: jal         0x80000BD8
    // 0x800225E0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80000BD8(rdram, ctx);
        goto after_6;
    // 0x800225E0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_6:
    // 0x800225E4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800225E8: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800225EC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800225F0: jal         0x80001A6C
    // 0x800225F4: lui         $a1, 0xC30C
    ctx->r5 = S32(0XC30C << 16);
    func_80001A6C(rdram, ctx);
        goto after_7;
    // 0x800225F4: lui         $a1, 0xC30C
    ctx->r5 = S32(0XC30C << 16);
    after_7:
    // 0x800225F8: lw          $v1, 0x104($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X104);
    // 0x800225FC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80022600: addiu       $s2, $v1, 0x10
    ctx->r18 = ADD32(ctx->r3, 0X10);
    // 0x80022604: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80022608: jal         0x80000BD8
    // 0x8002260C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80000BD8(rdram, ctx);
        goto after_8;
    // 0x8002260C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_8:
    // 0x80022610: b           L_80022674
    // 0x80022614: lw          $a1, 0x14($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X14);
        goto L_80022674;
    // 0x80022614: lw          $a1, 0x14($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X14);
L_80022618:
    // 0x80022618: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8002261C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80022620: jal         0x80001A6C
    // 0x80022624: lui         $a3, 0x433E
    ctx->r7 = S32(0X433E << 16);
    func_80001A6C(rdram, ctx);
        goto after_9;
    // 0x80022624: lui         $a3, 0x433E
    ctx->r7 = S32(0X433E << 16);
    after_9:
    // 0x80022628: lw          $v1, 0x104($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X104);
    // 0x8002262C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80022630: addiu       $s2, $v1, 0x10
    ctx->r18 = ADD32(ctx->r3, 0X10);
    // 0x80022634: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80022638: jal         0x80000BD8
    // 0x8002263C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80000BD8(rdram, ctx);
        goto after_10;
    // 0x8002263C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_10:
    // 0x80022640: b           L_80022674
    // 0x80022644: lw          $a1, 0x14($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X14);
        goto L_80022674;
    // 0x80022644: lw          $a1, 0x14($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X14);
L_80022648:
    // 0x80022648: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8002264C: lui         $a2, 0x42A2
    ctx->r6 = S32(0X42A2 << 16);
    // 0x80022650: jal         0x80001A6C
    // 0x80022654: lui         $a3, 0xC278
    ctx->r7 = S32(0XC278 << 16);
    func_80001A6C(rdram, ctx);
        goto after_11;
    // 0x80022654: lui         $a3, 0xC278
    ctx->r7 = S32(0XC278 << 16);
    after_11:
    // 0x80022658: lw          $v1, 0x104($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X104);
    // 0x8002265C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80022660: addiu       $s2, $v1, 0x10
    ctx->r18 = ADD32(ctx->r3, 0X10);
    // 0x80022664: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80022668: jal         0x80000BD8
    // 0x8002266C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80000BD8(rdram, ctx);
        goto after_12;
    // 0x8002266C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_12:
    // 0x80022670: lw          $a1, 0x14($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X14);
L_80022674:
    // 0x80022674: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80022678: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8002267C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80022680: jal         0x80049840
    // 0x80022684: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80049840(rdram, ctx);
        goto after_13;
    // 0x80022684: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_13:
    // 0x80022688: addiu       $s0, $sp, 0x70
    ctx->r16 = ADD32(ctx->r29, 0X70);
    // 0x8002268C: lw          $a1, 0x18($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X18);
    // 0x80022690: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80022694: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80022698: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8002269C: jal         0x80049840
    // 0x800226A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80049840(rdram, ctx);
        goto after_14;
    // 0x800226A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x800226A4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800226A8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800226AC: jal         0x80000BD8
    // 0x800226B0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80000BD8(rdram, ctx);
        goto after_15;
    // 0x800226B0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_15:
    // 0x800226B4: lw          $a1, 0x1C($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X1C);
    // 0x800226B8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800226BC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800226C0: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x800226C4: jal         0x80049840
    // 0x800226C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80049840(rdram, ctx);
        goto after_16;
    // 0x800226C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x800226CC: lw          $t0, 0x4($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X4);
    // 0x800226D0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800226D4: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800226D8: lw          $a0, 0x8($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X8);
    // 0x800226DC: jal         0x80000BD8
    // 0x800226E0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80000BD8(rdram, ctx);
        goto after_17;
    // 0x800226E0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_17:
    // 0x800226E4: lwc1        $f0, 0x24($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X24);
    // 0x800226E8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800226EC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800226F0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800226F4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800226F8: jal         0x80001AB4
    // 0x800226FC: nop

    func_80001AB4(rdram, ctx);
        goto after_18;
    // 0x800226FC: nop

    after_18:
    // 0x80022700: lw          $t1, 0x4($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X4);
    // 0x80022704: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80022708: lw          $a0, 0x8($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X8);
    // 0x8002270C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80022710: jal         0x80000BD8
    // 0x80022714: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_80000BD8(rdram, ctx);
        goto after_19;
    // 0x80022714: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_19:
    // 0x80022718: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8002271C: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x80022720: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_80022724:
    // 0x80022724: lw          $t2, 0x4($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X4);
    // 0x80022728: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8002272C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80022730: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x80022734: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x80022738: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8002273C: bne         $s1, $v0, L_80022724
    if (ctx->r17 != ctx->r2) {
        // 0x80022740: swc1        $f16, 0x40($t4)
        MEM_W(0X40, ctx->r12) = ctx->f16.u32l;
            goto L_80022724;
    }
    // 0x80022740: swc1        $f16, 0x40($t4)
    MEM_W(0X40, ctx->r12) = ctx->f16.u32l;
    // 0x80022744: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80022748: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8002274C: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80022750: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80022754: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80022758: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8002275C: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80022760: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80022764: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80022768: jr          $ra
    // 0x8002276C: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    TRACE_RETURN()
    return;
    // 0x8002276C: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
;}
RECOMP_FUNC void func_80022770(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80022770: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80022774: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80022778: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8002277C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80022780: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80022784: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80022788: lh          $v0, 0x114($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X114);
    // 0x8002278C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80022790: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80022794: blez        $v0, L_800227A0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80022798: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_800227A0;
    }
    // 0x80022798: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8002279C: sh          $t6, 0x114($a0)
    MEM_H(0X114, ctx->r4) = ctx->r14;
L_800227A0:
    // 0x800227A0: lhu         $t7, -0x2E46($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X2E46);
    // 0x800227A4: andi        $t8, $t7, 0x2000
    ctx->r24 = ctx->r15 & 0X2000;
    // 0x800227A8: beql        $t8, $zero, L_80022920
    if (ctx->r24 == 0) {
        // 0x800227AC: lw          $a0, 0xB0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0XB0);
            goto L_80022920;
    }
    goto skip_0;
    // 0x800227AC: lw          $a0, 0xB0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XB0);
    skip_0:
    // 0x800227B0: lh          $t9, 0x114($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X114);
    // 0x800227B4: bnel        $t9, $zero, L_800228D4
    if (ctx->r25 != 0) {
        // 0x800227B8: lw          $t9, 0x124($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X124);
            goto L_800228D4;
    }
    goto skip_1;
    // 0x800227B8: lw          $t9, 0x124($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X124);
    skip_1:
    // 0x800227BC: lh          $t1, 0x110($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X110);
    // 0x800227C0: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x800227C4: lui         $t0, 0x8007
    ctx->r8 = S32(0X8007 << 16);
    // 0x800227C8: multu       $t1, $v1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800227CC: addiu       $t0, $t0, -0x5FFC
    ctx->r8 = ADD32(ctx->r8, -0X5FFC);
    // 0x800227D0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800227D4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800227D8: addiu       $t7, $s0, 0x14
    ctx->r15 = ADD32(ctx->r16, 0X14);
    // 0x800227DC: addiu       $s3, $sp, 0x54
    ctx->r19 = ADD32(ctx->r29, 0X54);
    // 0x800227E0: mflo        $t2
    ctx->r10 = lo;
    // 0x800227E4: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x800227E8: lwc1        $f4, 0x4($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X4);
    // 0x800227EC: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x800227F0: lh          $t4, 0x110($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X110);
    // 0x800227F4: multu       $t4, $v1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800227F8: mflo        $t5
    ctx->r13 = lo;
    // 0x800227FC: addu        $t6, $t0, $t5
    ctx->r14 = ADD32(ctx->r8, ctx->r13);
    // 0x80022800: lwc1        $f6, 0x8($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X8);
    // 0x80022804: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    // 0x80022808: lh          $v0, 0x142($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X142);
    // 0x8002280C: blezl       $v0, L_800228D4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80022810: lw          $t9, 0x124($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X124);
            goto L_800228D4;
    }
    goto skip_2;
    // 0x80022810: lw          $t9, 0x124($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X124);
    skip_2:
    // 0x80022814: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80022818: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
L_8002281C:
    // 0x8002281C: addu        $t9, $t8, $s2
    ctx->r25 = ADD32(ctx->r24, ctx->r18);
    // 0x80022820: lui         $t1, 0x8007
    ctx->r9 = S32(0X8007 << 16);
    // 0x80022824: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x80022828: lh          $t1, -0x5F8C($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X5F8C);
    // 0x8002282C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80022830: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80022834: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80022838: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x8002283C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80022840: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    // 0x80022844: jal         0x80001A6C
    // 0x80022848: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    func_80001A6C(rdram, ctx);
        goto after_0;
    // 0x80022848: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_0:
    // 0x8002284C: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x80022850: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80022854: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80022858: lw          $a2, 0x8($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X8);
    // 0x8002285C: jal         0x80000BD8
    // 0x80022860: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    func_80000BD8(rdram, ctx);
        goto after_1;
    // 0x80022860: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    after_1:
    // 0x80022864: lh          $t3, 0x110($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X110);
    // 0x80022868: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8002286C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80022870: bne         $t3, $at, L_80022880
    if (ctx->r11 != ctx->r1) {
        // 0x80022874: addiu       $a1, $sp, 0x84
        ctx->r5 = ADD32(ctx->r29, 0X84);
            goto L_80022880;
    }
    // 0x80022874: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    // 0x80022878: b           L_80022884
    // 0x8002287C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_80022884;
    // 0x8002287C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80022880:
    // 0x80022880: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80022884:
    // 0x80022884: jal         0x8003F3A4
    // 0x80022888: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_8003F3A4(rdram, ctx);
        goto after_2;
    // 0x80022888: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x8002288C: beql        $v0, $zero, L_800228BC
    if (ctx->r2 == 0) {
        // 0x80022890: lh          $v0, 0x142($s0)
        ctx->r2 = MEM_H(ctx->r16, 0X142);
            goto L_800228BC;
    }
    goto skip_3;
    // 0x80022890: lh          $v0, 0x142($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X142);
    skip_3:
    // 0x80022894: lh          $t4, 0x110($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X110);
    // 0x80022898: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x8002289C: lh          $t7, 0x11A($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X11A);
    // 0x800228A0: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x800228A4: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800228A8: lh          $t6, -0x5F64($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X5F64);
    // 0x800228AC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800228B0: sh          $t8, 0x11A($s0)
    MEM_H(0X11A, ctx->r16) = ctx->r24;
    // 0x800228B4: sh          $t6, 0x114($s0)
    MEM_H(0X114, ctx->r16) = ctx->r14;
    // 0x800228B8: lh          $v0, 0x142($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X142);
L_800228BC:
    // 0x800228BC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800228C0: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x800228C4: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800228C8: bnel        $at, $zero, L_8002281C
    if (ctx->r1 != 0) {
        // 0x800228CC: sll         $t8, $v0, 3
        ctx->r24 = S32(ctx->r2 << 3);
            goto L_8002281C;
    }
    goto skip_4;
    // 0x800228CC: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    skip_4:
    // 0x800228D0: lw          $t9, 0x124($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X124);
L_800228D4:
    // 0x800228D4: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x800228D8: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    // 0x800228DC: bnel        $t9, $zero, L_80022900
    if (ctx->r25 != 0) {
        // 0x800228E0: lw          $t2, 0xB0($s0)
        ctx->r10 = MEM_W(ctx->r16, 0XB0);
            goto L_80022900;
    }
    goto skip_5;
    // 0x800228E0: lw          $t2, 0xB0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XB0);
    skip_5:
    // 0x800228E4: jal         0x80042F80
    // 0x800228E8: addiu       $a2, $s0, 0x120
    ctx->r6 = ADD32(ctx->r16, 0X120);
    func_80042F80(rdram, ctx);
        goto after_3;
    // 0x800228E8: addiu       $a2, $s0, 0x120
    ctx->r6 = ADD32(ctx->r16, 0X120);
    after_3:
    // 0x800228EC: beq         $v0, $zero, L_800228FC
    if (ctx->r2 == 0) {
        // 0x800228F0: sw          $v0, 0x124($s0)
        MEM_W(0X124, ctx->r16) = ctx->r2;
            goto L_800228FC;
    }
    // 0x800228F0: sw          $v0, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->r2;
    // 0x800228F4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800228F8: sh          $t1, 0x120($s0)
    MEM_H(0X120, ctx->r16) = ctx->r9;
L_800228FC:
    // 0x800228FC: lw          $t2, 0xB0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XB0);
L_80022900:
    // 0x80022900: addiu       $a0, $zero, -0x2
    ctx->r4 = ADD32(0, -0X2);
    // 0x80022904: bnel        $t2, $zero, L_80022938
    if (ctx->r10 != 0) {
        // 0x80022908: lw          $t4, 0x124($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X124);
            goto L_80022938;
    }
    goto skip_6;
    // 0x80022908: lw          $t4, 0x124($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X124);
    skip_6:
    // 0x8002290C: jal         0x800443A8
    // 0x80022910: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800443A8(rdram, ctx);
        goto after_4;
    // 0x80022910: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80022914: b           L_80022934
    // 0x80022918: sw          $v0, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r2;
        goto L_80022934;
    // 0x80022918: sw          $v0, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r2;
    // 0x8002291C: lw          $a0, 0xB0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XB0);
L_80022920:
    // 0x80022920: beql        $a0, $zero, L_80022938
    if (ctx->r4 == 0) {
        // 0x80022924: lw          $t4, 0x124($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X124);
            goto L_80022938;
    }
    goto skip_7;
    // 0x80022924: lw          $t4, 0x124($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X124);
    skip_7:
    // 0x80022928: jal         0x800444F8
    // 0x8002292C: nop

    func_800444F8(rdram, ctx);
        goto after_5;
    // 0x8002292C: nop

    after_5:
    // 0x80022930: sw          $zero, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = 0;
L_80022934:
    // 0x80022934: lw          $t4, 0x124($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X124);
L_80022938:
    // 0x80022938: lui         $t0, 0x8007
    ctx->r8 = S32(0X8007 << 16);
    // 0x8002293C: addiu       $t3, $sp, 0x54
    ctx->r11 = ADD32(ctx->r29, 0X54);
    // 0x80022940: or          $s3, $t3, $zero
    ctx->r19 = ctx->r11 | 0;
    // 0x80022944: beq         $t4, $zero, L_800229F0
    if (ctx->r12 == 0) {
        // 0x80022948: addiu       $t0, $t0, -0x5FFC
        ctx->r8 = ADD32(ctx->r8, -0X5FFC);
            goto L_800229F0;
    }
    // 0x80022948: addiu       $t0, $t0, -0x5FFC
    ctx->r8 = ADD32(ctx->r8, -0X5FFC);
    // 0x8002294C: lh          $t5, 0x120($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X120);
    // 0x80022950: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80022954: addiu       $v1, $sp, 0x48
    ctx->r3 = ADD32(ctx->r29, 0X48);
    // 0x80022958: beq         $t5, $zero, L_800229EC
    if (ctx->r13 == 0) {
        // 0x8002295C: or          $a0, $t3, $zero
        ctx->r4 = ctx->r11 | 0;
            goto L_800229EC;
    }
    // 0x8002295C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
L_80022960:
    // 0x80022960: lh          $t6, 0x110($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X110);
    // 0x80022964: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80022968: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x8002296C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80022970: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80022974: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80022978: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x8002297C: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x80022980: lwc1        $f16, 0x0($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80022984: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80022988: bne         $at, $zero, L_80022960
    if (ctx->r1 != 0) {
        // 0x8002298C: swc1        $f16, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f16.u32l;
            goto L_80022960;
    }
    // 0x8002298C: swc1        $f16, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f16.u32l;
    // 0x80022990: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80022994: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80022998: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x8002299C: jal         0x80001A6C
    // 0x800229A0: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    func_80001A6C(rdram, ctx);
        goto after_6;
    // 0x800229A0: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    after_6:
    // 0x800229A4: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x800229A8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800229AC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800229B0: lw          $a2, 0x8($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X8);
    // 0x800229B4: jal         0x80000BD8
    // 0x800229B8: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    func_80000BD8(rdram, ctx);
        goto after_7;
    // 0x800229B8: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    after_7:
    // 0x800229BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800229C0: addiu       $v1, $sp, 0x54
    ctx->r3 = ADD32(ctx->r29, 0X54);
    // 0x800229C4: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
L_800229C8:
    // 0x800229C8: lw          $t2, 0x124($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X124);
    // 0x800229CC: lwc1        $f18, 0x30($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X30);
    // 0x800229D0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800229D4: addu        $t4, $t2, $v0
    ctx->r12 = ADD32(ctx->r10, ctx->r2);
    // 0x800229D8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800229DC: bne         $v1, $a0, L_800229C8
    if (ctx->r3 != ctx->r4) {
        // 0x800229E0: swc1        $f18, 0x8($t4)
        MEM_W(0X8, ctx->r12) = ctx->f18.u32l;
            goto L_800229C8;
    }
    // 0x800229E0: swc1        $f18, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f18.u32l;
    // 0x800229E4: b           L_800229F4
    // 0x800229E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800229F4;
    // 0x800229E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800229EC:
    // 0x800229EC: sw          $zero, 0x124($s0)
    MEM_W(0X124, ctx->r16) = 0;
L_800229F0:
    // 0x800229F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800229F4:
    // 0x800229F4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800229F8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800229FC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80022A00: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80022A04: jr          $ra
    // 0x80022A08: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    TRACE_RETURN()
    return;
    // 0x80022A08: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_80022A0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80022A0C: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80022A10: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x80022A14: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80022A18: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x80022A1C: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80022A20: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80022A24: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80022A28: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80022A2C: addiu       $a0, $a0, -0x5F50
    ctx->r4 = ADD32(ctx->r4, -0X5F50);
    // 0x80022A30: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80022A34: addiu       $v0, $sp, 0x38
    ctx->r2 = ADD32(ctx->r29, 0X38);
    // 0x80022A38: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80022A3C:
    // 0x80022A3C: lh          $t6, 0x110($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X110);
    // 0x80022A40: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80022A44: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80022A48: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80022A4C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80022A50: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x80022A54: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x80022A58: lwc1        $f4, 0x0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80022A5C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80022A60: bne         $v0, $a1, L_80022A3C
    if (ctx->r2 != ctx->r5) {
        // 0x80022A64: swc1        $f4, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
            goto L_80022A3C;
    }
    // 0x80022A64: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80022A68: lh          $t1, 0x8A($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X8A);
    // 0x80022A6C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80022A70: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80022A74: beq         $t1, $at, L_80022A8C
    if (ctx->r9 == ctx->r1) {
        // 0x80022A78: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80022A8C;
    }
    // 0x80022A78: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80022A7C: beq         $t1, $at, L_80022A8C
    if (ctx->r9 == ctx->r1) {
        // 0x80022A80: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80022A8C;
    }
    // 0x80022A80: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80022A84: bne         $t1, $at, L_80022A90
    if (ctx->r9 != ctx->r1) {
        // 0x80022A88: nop
    
            goto L_80022A90;
    }
    // 0x80022A88: nop

L_80022A8C:
    // 0x80022A8C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80022A90:
    // 0x80022A90: beql        $t0, $zero, L_80022AB8
    if (ctx->r8 == 0) {
        // 0x80022A94: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_80022AB8;
    }
    goto skip_0;
    // 0x80022A94: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_0:
    // 0x80022A98: lh          $t2, 0x11E($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X11E);
    // 0x80022A9C: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80022AA0: beql        $t2, $zero, L_80022AC4
    if (ctx->r10 == 0) {
        // 0x80022AA4: lw          $a1, 0x38($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X38);
            goto L_80022AC4;
    }
    goto skip_1;
    // 0x80022AA4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    skip_1:
    // 0x80022AA8: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80022AAC: b           L_80022AC0
    // 0x80022AB0: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
        goto L_80022AC0;
    // 0x80022AB0: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x80022AB4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_80022AB8:
    // 0x80022AB8: nop

    // 0x80022ABC: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
L_80022AC0:
    // 0x80022AC0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
L_80022AC4:
    // 0x80022AC4: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80022AC8: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80022ACC: jal         0x80001A6C
    // 0x80022AD0: sh          $t0, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r8;
    func_80001A6C(rdram, ctx);
        goto after_0;
    // 0x80022AD0: sh          $t0, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r8;
    after_0:
    // 0x80022AD4: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x80022AD8: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80022ADC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80022AE0: lw          $a2, 0x8($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X8);
    // 0x80022AE4: jal         0x80000BD8
    // 0x80022AE8: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    func_80000BD8(rdram, ctx);
        goto after_1;
    // 0x80022AE8: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    after_1:
    // 0x80022AEC: lh          $v0, 0x8A($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X8A);
    // 0x80022AF0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80022AF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80022AF8: bne         $v0, $at, L_80022B1C
    if (ctx->r2 != ctx->r1) {
        // 0x80022AFC: addiu       $a1, $sp, 0x74
        ctx->r5 = ADD32(ctx->r29, 0X74);
            goto L_80022B1C;
    }
    // 0x80022AFC: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x80022B00: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80022B04: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x80022B08: addiu       $a2, $s0, 0x14
    ctx->r6 = ADD32(ctx->r16, 0X14);
    // 0x80022B0C: jal         0x80041A94
    // 0x80022B10: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80041A94(rdram, ctx);
        goto after_2;
    // 0x80022B10: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80022B14: b           L_80022B38
    // 0x80022B18: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80022B38;
    // 0x80022B18: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80022B1C:
    // 0x80022B1C: lw          $t4, 0x8C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8C);
    // 0x80022B20: addiu       $a2, $s0, 0x14
    ctx->r6 = ADD32(ctx->r16, 0X14);
    // 0x80022B24: addiu       $a3, $s0, 0x50
    ctx->r7 = ADD32(ctx->r16, 0X50);
    // 0x80022B28: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80022B2C: jal         0x80040194
    // 0x80022B30: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    func_80040194(rdram, ctx);
        goto after_3;
    // 0x80022B30: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_3:
    // 0x80022B34: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80022B38:
    // 0x80022B38: beql        $v0, $zero, L_80022BD4
    if (ctx->r2 == 0) {
        // 0x80022B3C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80022BD4;
    }
    goto skip_2;
    // 0x80022B3C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80022B40: lh          $t5, 0xDC($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XDC);
    // 0x80022B44: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80022B48: addiu       $t7, $t7, -0x6BC8
    ctx->r15 = ADD32(ctx->r15, -0X6BC8);
    // 0x80022B4C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80022B50: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80022B54: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x80022B58: lh          $t1, 0x32($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X32);
    // 0x80022B5C: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80022B60: beq         $t1, $zero, L_80022B88
    if (ctx->r9 == 0) {
        // 0x80022B64: sh          $t9, 0x2($v0)
        MEM_H(0X2, ctx->r2) = ctx->r25;
            goto L_80022B88;
    }
    // 0x80022B64: sh          $t9, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r25;
    // 0x80022B68: lh          $t2, 0x11E($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X11E);
    // 0x80022B6C: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x80022B70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80022B74: xori        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 ^ 0X1;
    // 0x80022B78: sh          $t3, 0x11E($s0)
    MEM_H(0X11E, ctx->r16) = ctx->r11;
    // 0x80022B7C: jal         0x80043EF0
    // 0x80022B80: sw          $v1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r3;
    func_80043EF0(rdram, ctx);
        goto after_4;
    // 0x80022B80: sw          $v1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r3;
    after_4:
    // 0x80022B84: lw          $v1, 0x84($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X84);
L_80022B88:
    // 0x80022B88: lh          $t4, 0xDC($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XDC);
    // 0x80022B8C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80022B90: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80022B94: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80022B98: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80022B9C: lh          $t6, -0x6BC8($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X6BC8);
    // 0x80022BA0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80022BA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80022BA8: bne         $t6, $at, L_80022BBC
    if (ctx->r14 != ctx->r1) {
        // 0x80022BAC: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_80022BBC;
    }
    // 0x80022BAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80022BB0: lh          $t7, 0x11C($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X11C);
    // 0x80022BB4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80022BB8: bne         $t7, $at, L_80022BD0
    if (ctx->r15 != ctx->r1) {
        // 0x80022BBC: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80022BD0;
    }
L_80022BBC:
    // 0x80022BBC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80022BC0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80022BC4: jal         0x8000ACEC
    // 0x80022BC8: sw          $v1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r3;
    func_8000ACEC(rdram, ctx);
        goto after_5;
    // 0x80022BC8: sw          $v1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r3;
    after_5:
    // 0x80022BCC: lw          $v1, 0x84($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X84);
L_80022BD0:
    // 0x80022BD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80022BD4:
    // 0x80022BD4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80022BD8: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x80022BDC: jr          $ra
    // 0x80022BE0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    TRACE_RETURN()
    return;
    // 0x80022BE0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80022BE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80022BE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80022BE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80022BEC: lh          $t6, 0xDC($a0)
    ctx->r14 = MEM_H(ctx->r4, 0XDC);
    // 0x80022BF0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80022BF4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80022BF8: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x80022BFC: lh          $v1, -0x6BC6($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X6BC6);
    // 0x80022C00: beq         $v1, $zero, L_80022C10
    if (ctx->r3 == 0) {
        // 0x80022C04: nop
    
            goto L_80022C10;
    }
    // 0x80022C04: nop

    // 0x80022C08: b           L_80022C1C
    // 0x80022C0C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80022C1C;
    // 0x80022C0C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80022C10:
    // 0x80022C10: jal         0x80044480
    // 0x80022C14: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_80044480(rdram, ctx);
        goto after_0;
    // 0x80022C14: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_0:
    // 0x80022C18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80022C1C:
    // 0x80022C1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80022C20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80022C24: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80022C2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80022C2C: lh          $v0, 0x116($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X116);
    // 0x80022C30: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80022C34: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80022C38: blez        $v0, L_80022C44
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80022C3C: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80022C44;
    }
    // 0x80022C3C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80022C40: sh          $t6, 0x116($a0)
    MEM_H(0X116, ctx->r4) = ctx->r14;
L_80022C44:
    // 0x80022C44: lh          $t7, 0x6ACC($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X6ACC);
    // 0x80022C48: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x80022C4C: beq         $t7, $zero, L_80022C5C
    if (ctx->r15 == 0) {
        // 0x80022C50: nop
    
            goto L_80022C5C;
    }
    // 0x80022C50: nop

    // 0x80022C54: b           L_80022C5C
    // 0x80022C58: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
        goto L_80022C5C;
    // 0x80022C58: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_80022C5C:
    // 0x80022C5C: lhu         $t8, -0x2E44($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X2E44);
    // 0x80022C60: and         $t9, $t8, $v0
    ctx->r25 = ctx->r24 & ctx->r2;
    // 0x80022C64: beq         $t9, $zero, L_80022C80
    if (ctx->r25 == 0) {
        // 0x80022C68: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80022C80;
    }
    // 0x80022C68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80022C6C: lh          $t0, 0x116($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X116);
    // 0x80022C70: bne         $t0, $zero, L_80022C80
    if (ctx->r8 != 0) {
        // 0x80022C74: nop
    
            goto L_80022C80;
    }
    // 0x80022C74: nop

    // 0x80022C78: jr          $ra
    // 0x80022C7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    TRACE_RETURN()
    return;
    // 0x80022C7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80022C80:
    // 0x80022C80: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80022C88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80022C88: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80022C8C: sw          $a2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r6;
    // 0x80022C90: lh          $t6, 0xAA($sp)
    ctx->r14 = MEM_H(ctx->r29, 0XAA);
    // 0x80022C94: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80022C98: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x80022C9C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80022CA0: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x80022CA4: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x80022CA8: sltiu       $at, $t7, 0x8
    ctx->r1 = ctx->r15 < 0X8 ? 1 : 0;
    // 0x80022CAC: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x80022CB0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80022CB4: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x80022CB8: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80022CBC: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80022CC0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80022CC4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80022CC8: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x80022CCC: sw          $a3, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r7;
    // 0x80022CD0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80022CD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80022CD8: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80022CDC: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    // 0x80022CE0: beq         $at, $zero, L_80022D68
    if (ctx->r1 == 0) {
        // 0x80022CE4: swc1        $f0, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
            goto L_80022D68;
    }
    // 0x80022CE4: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    // 0x80022CE8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80022CEC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80022CF0: addu        $at, $at, $t7
    gpr jr_addend_80022CF8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80022CF4: lw          $t7, 0x67D0($at)
    ctx->r15 = ADD32(ctx->r1, 0X67D0);
    // 0x80022CF8: jr          $t7
    // 0x80022CFC: nop

    switch (jr_addend_80022CF8 >> 2) {
        case 0: goto L_80022D00; break;
        case 1: goto L_80022D18; break;
        case 2: goto L_80022D2C; break;
        case 3: goto L_80022D68; break;
        case 4: goto L_80022D68; break;
        case 5: goto L_80022D68; break;
        case 6: goto L_80022D44; break;
        case 7: goto L_80022D58; break;
        default: switch_error(__func__, 0x80022CF8, 0x800767D0);
    }
    // 0x80022CFC: nop

L_80022D00:
    // 0x80022D00: addiu       $t8, $zero, 0x17
    ctx->r24 = ADD32(0, 0X17);
    // 0x80022D04: addiu       $t9, $zero, 0x4B
    ctx->r25 = ADD32(0, 0X4B);
    // 0x80022D08: sh          $t9, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r25;
    // 0x80022D0C: sh          $t8, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r24;
    // 0x80022D10: b           L_80022D68
    // 0x80022D14: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
        goto L_80022D68;
    // 0x80022D14: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_80022D18:
    // 0x80022D18: addiu       $t0, $zero, 0x17
    ctx->r8 = ADD32(0, 0X17);
    // 0x80022D1C: addiu       $t1, $zero, 0x4C
    ctx->r9 = ADD32(0, 0X4C);
    // 0x80022D20: sh          $t1, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r9;
    // 0x80022D24: b           L_80022D68
    // 0x80022D28: sh          $t0, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r8;
        goto L_80022D68;
    // 0x80022D28: sh          $t0, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r8;
L_80022D2C:
    // 0x80022D2C: addiu       $t2, $zero, 0x12
    ctx->r10 = ADD32(0, 0X12);
    // 0x80022D30: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x80022D34: sh          $t3, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r11;
    // 0x80022D38: sh          $t2, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r10;
    // 0x80022D3C: b           L_80022D68
    // 0x80022D40: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
        goto L_80022D68;
    // 0x80022D40: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
L_80022D44:
    // 0x80022D44: addiu       $t4, $zero, 0x12
    ctx->r12 = ADD32(0, 0X12);
    // 0x80022D48: addiu       $t5, $zero, 0x14
    ctx->r13 = ADD32(0, 0X14);
    // 0x80022D4C: sh          $t5, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r13;
    // 0x80022D50: b           L_80022D68
    // 0x80022D54: sh          $t4, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r12;
        goto L_80022D68;
    // 0x80022D54: sh          $t4, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r12;
L_80022D58:
    // 0x80022D58: addiu       $t6, $zero, 0x12
    ctx->r14 = ADD32(0, 0X12);
    // 0x80022D5C: addiu       $t7, $zero, 0x18
    ctx->r15 = ADD32(0, 0X18);
    // 0x80022D60: sh          $t7, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r15;
    // 0x80022D64: sh          $t6, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r14;
L_80022D68:
    // 0x80022D68: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80022D6C: jal         0x80022BE4
    // 0x80022D70: sh          $v0, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r2;
    func_80022BE4(rdram, ctx);
        goto after_0;
    // 0x80022D70: sh          $v0, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r2;
    after_0:
    // 0x80022D74: bne         $v0, $zero, L_80022D80
    if (ctx->r2 != 0) {
        // 0x80022D78: nop
    
            goto L_80022D80;
    }
    // 0x80022D78: nop

    // 0x80022D7C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_80022D80:
    // 0x80022D80: bne         $s4, $zero, L_80022D9C
    if (ctx->r20 != 0) {
        // 0x80022D84: nop
    
            goto L_80022D9C;
    }
    // 0x80022D84: nop

    // 0x80022D88: jal         0x80040168
    // 0x80022D8C: nop

    func_80040168(rdram, ctx);
        goto after_1;
    // 0x80022D8C: nop

    after_1:
    // 0x80022D90: sll         $s4, $v0, 16
    ctx->r20 = S32(ctx->r2 << 16);
    // 0x80022D94: sra         $t8, $s4, 16
    ctx->r24 = S32(SIGNED(ctx->r20) >> 16);
    // 0x80022D98: or          $s4, $t8, $zero
    ctx->r20 = ctx->r24 | 0;
L_80022D9C:
    // 0x80022D9C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80022DA0: lw          $t9, -0x6810($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6810);
    // 0x80022DA4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80022DA8: addiu       $s2, $sp, 0x98
    ctx->r18 = ADD32(ctx->r29, 0X98);
    // 0x80022DAC: lw          $s0, 0x0($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X0);
    // 0x80022DB0: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80022DB4: beq         $t0, $zero, L_80022F74
    if (ctx->r8 == 0) {
        // 0x80022DB8: nop
    
            goto L_80022F74;
    }
    // 0x80022DB8: nop

    // 0x80022DBC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80022DC0: addiu       $s1, $sp, 0x5C
    ctx->r17 = ADD32(ctx->r29, 0X5C);
    // 0x80022DC4: lh          $t1, 0x2E($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X2E);
L_80022DC8:
    // 0x80022DC8: blezl       $t1, L_80022F68
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80022DCC: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80022F68;
    }
    goto skip_0;
    // 0x80022DCC: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x80022DD0: lh          $v0, 0x98($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X98);
    // 0x80022DD4: lh          $t3, 0xAE($sp)
    ctx->r11 = MEM_H(ctx->r29, 0XAE);
    // 0x80022DD8: andi        $t2, $v0, 0x200
    ctx->r10 = ctx->r2 & 0X200;
    // 0x80022DDC: beq         $t2, $zero, L_80022F64
    if (ctx->r10 == 0) {
        // 0x80022DE0: and         $t4, $v0, $t3
        ctx->r12 = ctx->r2 & ctx->r11;
            goto L_80022F64;
    }
    // 0x80022DE0: and         $t4, $v0, $t3
    ctx->r12 = ctx->r2 & ctx->r11;
    // 0x80022DE4: beql        $t4, $zero, L_80022F68
    if (ctx->r12 == 0) {
        // 0x80022DE8: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80022F68;
    }
    goto skip_1;
    // 0x80022DE8: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x80022DEC: lw          $t5, 0x28($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X28);
    // 0x80022DF0: addiu       $a1, $s5, 0x8
    ctx->r5 = ADD32(ctx->r21, 0X8);
    // 0x80022DF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80022DF8: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x80022DFC: bne         $t6, $zero, L_80022E54
    if (ctx->r14 != 0) {
        // 0x80022E00: nop
    
            goto L_80022E54;
    }
    // 0x80022E00: nop

    // 0x80022E04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80022E08:
    // 0x80022E08: lw          $t7, 0x28($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X28);
    // 0x80022E0C: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x80022E10: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80022E14: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80022E18: lh          $t0, 0x2($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X2);
    // 0x80022E1C: addu        $t1, $s0, $v1
    ctx->r9 = ADD32(ctx->r16, ctx->r3);
    // 0x80022E20: lwc1        $f8, 0x8($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X8);
    // 0x80022E24: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80022E28: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80022E2C: sll         $t3, $v0, 16
    ctx->r11 = S32(ctx->r2 << 16);
    // 0x80022E30: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80022E34: sra         $v0, $t3, 16
    ctx->r2 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80022E38: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80022E3C: addu        $t2, $s1, $v1
    ctx->r10 = ADD32(ctx->r17, ctx->r3);
    // 0x80022E40: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80022E44: bne         $at, $zero, L_80022E08
    if (ctx->r1 != 0) {
        // 0x80022E48: swc1        $f10, 0x0($t2)
        MEM_W(0X0, ctx->r10) = ctx->f10.u32l;
            goto L_80022E08;
    }
    // 0x80022E48: swc1        $f10, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f10.u32l;
    // 0x80022E4C: b           L_80022E7C
    // 0x80022E50: nop

        goto L_80022E7C;
    // 0x80022E50: nop

L_80022E54:
    // 0x80022E54: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80022E58: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80022E5C: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x80022E60: addu        $t5, $s0, $v1
    ctx->r13 = ADD32(ctx->r16, ctx->r3);
    // 0x80022E64: lwc1        $f16, 0x8($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X8);
    // 0x80022E68: sra         $v0, $t7, 16
    ctx->r2 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80022E6C: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80022E70: addu        $t6, $s1, $v1
    ctx->r14 = ADD32(ctx->r17, ctx->r3);
    // 0x80022E74: bne         $at, $zero, L_80022E54
    if (ctx->r1 != 0) {
        // 0x80022E78: swc1        $f16, 0x0($t6)
        MEM_W(0X0, ctx->r14) = ctx->f16.u32l;
            goto L_80022E54;
    }
    // 0x80022E78: swc1        $f16, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f16.u32l;
L_80022E7C:
    // 0x80022E7C: jal         0x8000C8A4
    // 0x80022E80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000C8A4(rdram, ctx);
        goto after_2;
    // 0x80022E80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80022E84: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80022E88: lwc1        $f18, -0x68B4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X68B4);
    // 0x80022E8C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80022E90: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80022E94: nop

    // 0x80022E98: bc1fl       L_80022F68
    if (!c1cs) {
        // 0x80022E9C: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80022F68;
    }
    goto skip_2;
    // 0x80022E9C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x80022EA0: jal         0x8000C94C
    // 0x80022EA4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8000C94C(rdram, ctx);
        goto after_3;
    // 0x80022EA4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80022EA8: beq         $v0, $zero, L_80022F64
    if (ctx->r2 == 0) {
        // 0x80022EAC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80022F64;
    }
    // 0x80022EAC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80022EB0: jal         0x8000C8A4
    // 0x80022EB4: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    func_8000C8A4(rdram, ctx);
        goto after_4;
    // 0x80022EB4: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    after_4:
    // 0x80022EB8: c.le.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl <= ctx->f22.fl;
    // 0x80022EBC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80022EC0: bc1fl       L_80022F68
    if (!c1cs) {
        // 0x80022EC4: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80022F68;
    }
    goto skip_3;
    // 0x80022EC4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_3:
    // 0x80022EC8: sub.s       $f2, $f22, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f22.fl - ctx->f0.fl;
    // 0x80022ECC: lwc1        $f4, 0x67F0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X67F0);
    // 0x80022ED0: lwc1        $f6, 0x98($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80022ED4: lwc1        $f10, 0x9C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80022ED8: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80022EDC: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80022EE0: lh          $a3, 0x5A($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X5A);
    // 0x80022EE4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80022EE8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80022EEC: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80022EF0: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80022EF4: sll         $t0, $a0, 16
    ctx->r8 = S32(ctx->r4 << 16);
    // 0x80022EF8: trunc.w.s   $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80022EFC: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80022F00: sra         $a0, $t0, 16
    ctx->r4 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80022F04: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x80022F08: sll         $t3, $a1, 16
    ctx->r11 = S32(ctx->r5 << 16);
    // 0x80022F0C: sra         $a1, $t3, 16
    ctx->r5 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80022F10: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x80022F14: jal         0x8004C580
    // 0x80022F18: sra         $a2, $t7, 16
    ctx->r6 = S32(SIGNED(ctx->r15) >> 16);
    func_8004C580(rdram, ctx);
        goto after_5;
    // 0x80022F18: sra         $a2, $t7, 16
    ctx->r6 = S32(SIGNED(ctx->r15) >> 16);
    after_5:
    // 0x80022F1C: bne         $s4, $zero, L_80022F64
    if (ctx->r20 != 0) {
        // 0x80022F20: lh          $t9, 0x58($sp)
        ctx->r25 = MEM_H(ctx->r29, 0X58);
            goto L_80022F64;
    }
    // 0x80022F20: lh          $t9, 0x58($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X58);
    // 0x80022F24: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80022F28: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80022F2C: lw          $a1, 0xA0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA0);
    // 0x80022F30: jal         0x8000C8A4
    // 0x80022F34: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    func_8000C8A4(rdram, ctx);
        goto after_6;
    // 0x80022F34: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    after_6:
    // 0x80022F38: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80022F3C: sll         $t0, $s3, 2
    ctx->r8 = S32(ctx->r19 << 2);
    // 0x80022F40: addu        $t1, $sp, $t0
    ctx->r9 = ADD32(ctx->r29, ctx->r8);
    // 0x80022F44: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80022F48: bc1fl       L_80022F68
    if (!c1cs) {
        // 0x80022F4C: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80022F68;
    }
    goto skip_4;
    // 0x80022F4C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_4:
    // 0x80022F50: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80022F54: sll         $t2, $s3, 16
    ctx->r10 = S32(ctx->r19 << 16);
    // 0x80022F58: sra         $s3, $t2, 16
    ctx->r19 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80022F5C: beq         $s3, $at, L_8002314C
    if (ctx->r19 == ctx->r1) {
        // 0x80022F60: sw          $s0, 0x78($t1)
        MEM_W(0X78, ctx->r9) = ctx->r16;
            goto L_8002314C;
    }
    // 0x80022F60: sw          $s0, 0x78($t1)
    MEM_W(0X78, ctx->r9) = ctx->r16;
L_80022F64:
    // 0x80022F64: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_80022F68:
    // 0x80022F68: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80022F6C: bnel        $t4, $zero, L_80022DC8
    if (ctx->r12 != 0) {
        // 0x80022F70: lh          $t1, 0x2E($s0)
        ctx->r9 = MEM_H(ctx->r16, 0X2E);
            goto L_80022DC8;
    }
    goto skip_5;
    // 0x80022F70: lh          $t1, 0x2E($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X2E);
    skip_5:
L_80022F74:
    // 0x80022F74: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80022F78: lw          $t5, -0x6610($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X6610);
    // 0x80022F7C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80022F80: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80022F84: lw          $s0, 0x0($t5)
    ctx->r16 = MEM_W(ctx->r13, 0X0);
    // 0x80022F88: addiu       $s1, $sp, 0x5C
    ctx->r17 = ADD32(ctx->r29, 0X5C);
    // 0x80022F8C: addiu       $s2, $sp, 0x98
    ctx->r18 = ADD32(ctx->r29, 0X98);
    // 0x80022F90: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80022F94: beq         $t6, $zero, L_8002314C
    if (ctx->r14 == 0) {
        // 0x80022F98: nop
    
            goto L_8002314C;
    }
    // 0x80022F98: nop

    // 0x80022F9C: lh          $t7, 0x2E($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X2E);
L_80022FA0:
    // 0x80022FA0: blezl       $t7, L_80023140
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80022FA4: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80023140;
    }
    goto skip_6;
    // 0x80022FA4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_6:
    // 0x80022FA8: lh          $t8, 0x92($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X92);
    // 0x80022FAC: addiu       $a2, $s0, 0x8
    ctx->r6 = ADD32(ctx->r16, 0X8);
    // 0x80022FB0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80022FB4: andi        $t9, $t8, 0x200
    ctx->r25 = ctx->r24 & 0X200;
    // 0x80022FB8: beql        $t9, $zero, L_80023140
    if (ctx->r25 == 0) {
        // 0x80022FBC: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80023140;
    }
    goto skip_7;
    // 0x80022FBC: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_7:
    // 0x80022FC0: lw          $t0, 0x28($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X28);
    // 0x80022FC4: addiu       $a1, $s5, 0x8
    ctx->r5 = ADD32(ctx->r21, 0X8);
    // 0x80022FC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80022FCC: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x80022FD0: bne         $t1, $zero, L_80023028
    if (ctx->r9 != 0) {
        // 0x80022FD4: nop
    
            goto L_80023028;
    }
    // 0x80022FD4: nop

    // 0x80022FD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80022FDC:
    // 0x80022FDC: lw          $t2, 0x28($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X28);
    // 0x80022FE0: sll         $t3, $v0, 1
    ctx->r11 = S32(ctx->r2 << 1);
    // 0x80022FE4: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80022FE8: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80022FEC: lh          $t5, 0x2($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X2);
    // 0x80022FF0: addu        $t6, $s0, $v1
    ctx->r14 = ADD32(ctx->r16, ctx->r3);
    // 0x80022FF4: lwc1        $f10, 0x8($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X8);
    // 0x80022FF8: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80022FFC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80023000: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x80023004: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80023008: sra         $v0, $t8, 16
    ctx->r2 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002300C: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80023010: addu        $t7, $s1, $v1
    ctx->r15 = ADD32(ctx->r17, ctx->r3);
    // 0x80023014: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80023018: bne         $at, $zero, L_80022FDC
    if (ctx->r1 != 0) {
        // 0x8002301C: swc1        $f16, 0x0($t7)
        MEM_W(0X0, ctx->r15) = ctx->f16.u32l;
            goto L_80022FDC;
    }
    // 0x8002301C: swc1        $f16, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f16.u32l;
    // 0x80023020: b           L_80023050
    // 0x80023024: nop

        goto L_80023050;
    // 0x80023024: nop

L_80023028:
    // 0x80023028: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8002302C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80023030: sll         $t2, $v0, 16
    ctx->r10 = S32(ctx->r2 << 16);
    // 0x80023034: addu        $t0, $s0, $v1
    ctx->r8 = ADD32(ctx->r16, ctx->r3);
    // 0x80023038: lwc1        $f18, 0x8($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8002303C: sra         $v0, $t2, 16
    ctx->r2 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80023040: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80023044: addu        $t1, $s1, $v1
    ctx->r9 = ADD32(ctx->r17, ctx->r3);
    // 0x80023048: bne         $at, $zero, L_80023028
    if (ctx->r1 != 0) {
        // 0x8002304C: swc1        $f18, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->f18.u32l;
            goto L_80023028;
    }
    // 0x8002304C: swc1        $f18, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f18.u32l;
L_80023050:
    // 0x80023050: jal         0x8000C8A4
    // 0x80023054: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    func_8000C8A4(rdram, ctx);
        goto after_7;
    // 0x80023054: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_7:
    // 0x80023058: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8002305C: lwc1        $f4, -0x68B4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X68B4);
    // 0x80023060: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x80023064: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80023068: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8002306C: nop

    // 0x80023070: bc1fl       L_80023140
    if (!c1cs) {
        // 0x80023074: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80023140;
    }
    goto skip_8;
    // 0x80023074: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_8:
    // 0x80023078: jal         0x8000C94C
    // 0x8002307C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_8000C94C(rdram, ctx);
        goto after_8;
    // 0x8002307C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_8:
    // 0x80023080: beq         $v0, $zero, L_8002313C
    if (ctx->r2 == 0) {
        // 0x80023084: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8002313C;
    }
    // 0x80023084: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80023088: jal         0x8000C8A4
    // 0x8002308C: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    func_8000C8A4(rdram, ctx);
        goto after_9;
    // 0x8002308C: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    after_9:
    // 0x80023090: c.le.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl <= ctx->f22.fl;
    // 0x80023094: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80023098: bc1fl       L_80023140
    if (!c1cs) {
        // 0x8002309C: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80023140;
    }
    goto skip_9;
    // 0x8002309C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_9:
    // 0x800230A0: sub.s       $f2, $f22, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f22.fl - ctx->f0.fl;
    // 0x800230A4: lwc1        $f6, 0x67F4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X67F4);
    // 0x800230A8: lwc1        $f8, 0x98($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800230AC: lwc1        $f16, 0x9C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800230B0: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800230B4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800230B8: addiu       $a3, $zero, 0x17
    ctx->r7 = ADD32(0, 0X17);
    // 0x800230BC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800230C0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800230C4: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x800230C8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800230CC: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x800230D0: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x800230D4: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800230D8: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800230DC: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x800230E0: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x800230E4: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800230E8: sll         $t2, $t1, 24
    ctx->r10 = S32(ctx->r9 << 24);
    // 0x800230EC: jal         0x8004C580
    // 0x800230F0: sra         $a2, $t2, 16
    ctx->r6 = S32(SIGNED(ctx->r10) >> 16);
    func_8004C580(rdram, ctx);
        goto after_10;
    // 0x800230F0: sra         $a2, $t2, 16
    ctx->r6 = S32(SIGNED(ctx->r10) >> 16);
    after_10:
    // 0x800230F4: bne         $s4, $zero, L_8002313C
    if (ctx->r20 != 0) {
        // 0x800230F8: lh          $t4, 0x58($sp)
        ctx->r12 = MEM_H(ctx->r29, 0X58);
            goto L_8002313C;
    }
    // 0x800230F8: lh          $t4, 0x58($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X58);
    // 0x800230FC: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80023100: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80023104: lw          $a1, 0xA0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA0);
    // 0x80023108: jal         0x8000C8A4
    // 0x8002310C: cvt.s.w     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = CVT_S_W(ctx->f6.u32l);
    func_8000C8A4(rdram, ctx);
        goto after_11;
    // 0x8002310C: cvt.s.w     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = CVT_S_W(ctx->f6.u32l);
    after_11:
    // 0x80023110: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80023114: sll         $t5, $s3, 2
    ctx->r13 = S32(ctx->r19 << 2);
    // 0x80023118: addu        $t6, $sp, $t5
    ctx->r14 = ADD32(ctx->r29, ctx->r13);
    // 0x8002311C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80023120: bc1fl       L_80023140
    if (!c1cs) {
        // 0x80023124: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80023140;
    }
    goto skip_10;
    // 0x80023124: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_10:
    // 0x80023128: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8002312C: sll         $t7, $s3, 16
    ctx->r15 = S32(ctx->r19 << 16);
    // 0x80023130: sra         $s3, $t7, 16
    ctx->r19 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80023134: beq         $s3, $at, L_8002314C
    if (ctx->r19 == ctx->r1) {
        // 0x80023138: sw          $s0, 0x78($t6)
        MEM_W(0X78, ctx->r14) = ctx->r16;
            goto L_8002314C;
    }
    // 0x80023138: sw          $s0, 0x78($t6)
    MEM_W(0X78, ctx->r14) = ctx->r16;
L_8002313C:
    // 0x8002313C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_80023140:
    // 0x80023140: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80023144: bnel        $t9, $zero, L_80022FA0
    if (ctx->r25 != 0) {
        // 0x80023148: lh          $t7, 0x2E($s0)
        ctx->r15 = MEM_H(ctx->r16, 0X2E);
            goto L_80022FA0;
    }
    goto skip_11;
    // 0x80023148: lh          $t7, 0x2E($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X2E);
    skip_11:
L_8002314C:
    // 0x8002314C: jal         0x80022C2C
    // 0x80023150: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_80022C2C(rdram, ctx);
        goto after_12;
    // 0x80023150: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_12:
    // 0x80023154: beql        $v0, $zero, L_800231E4
    if (ctx->r2 == 0) {
        // 0x80023158: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_800231E4;
    }
    goto skip_12;
    // 0x80023158: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_12:
    // 0x8002315C: bne         $s4, $zero, L_800231E0
    if (ctx->r20 != 0) {
        // 0x80023160: lh          $v0, 0xAA($sp)
        ctx->r2 = MEM_H(ctx->r29, 0XAA);
            goto L_800231E0;
    }
    // 0x80023160: lh          $v0, 0xAA($sp)
    ctx->r2 = MEM_H(ctx->r29, 0XAA);
    // 0x80023164: beq         $s3, $zero, L_80023174
    if (ctx->r19 == 0) {
        // 0x80023168: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80023174;
    }
    // 0x80023168: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8002316C: b           L_80023178
    // 0x80023170: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
        goto L_80023178;
    // 0x80023170: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
L_80023174:
    // 0x80023174: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80023178:
    // 0x80023178: beq         $v0, $at, L_800231B4
    if (ctx->r2 == ctx->r1) {
        // 0x8002317C: addiu       $a0, $zero, 0x5
        ctx->r4 = ADD32(0, 0X5);
            goto L_800231B4;
    }
    // 0x8002317C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80023180: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80023184: beq         $v0, $at, L_800231CC
    if (ctx->r2 == ctx->r1) {
        // 0x80023188: addiu       $a0, $zero, 0x6
        ctx->r4 = ADD32(0, 0X6);
            goto L_800231CC;
    }
    // 0x80023188: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8002318C: lh          $a0, 0x56($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X56);
    // 0x80023190: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80023194: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80023198: sll         $t0, $a0, 16
    ctx->r8 = S32(ctx->r4 << 16);
    // 0x8002319C: jal         0x80022A0C
    // 0x800231A0: sra         $a0, $t0, 16
    ctx->r4 = S32(SIGNED(ctx->r8) >> 16);
    func_80022A0C(rdram, ctx);
        goto after_13;
    // 0x800231A0: sra         $a0, $t0, 16
    ctx->r4 = S32(SIGNED(ctx->r8) >> 16);
    after_13:
    // 0x800231A4: beq         $v0, $zero, L_800231E0
    if (ctx->r2 == 0) {
        // 0x800231A8: addiu       $t2, $zero, 0xF
        ctx->r10 = ADD32(0, 0XF);
            goto L_800231E0;
    }
    // 0x800231A8: addiu       $t2, $zero, 0xF
    ctx->r10 = ADD32(0, 0XF);
    // 0x800231AC: b           L_800231E0
    // 0x800231B0: sh          $t2, 0x116($s5)
    MEM_H(0X116, ctx->r21) = ctx->r10;
        goto L_800231E0;
    // 0x800231B0: sh          $t2, 0x116($s5)
    MEM_H(0X116, ctx->r21) = ctx->r10;
L_800231B4:
    // 0x800231B4: jal         0x80022A0C
    // 0x800231B8: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_80022A0C(rdram, ctx);
        goto after_14;
    // 0x800231B8: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_14:
    // 0x800231BC: beq         $v0, $zero, L_800231E0
    if (ctx->r2 == 0) {
        // 0x800231C0: addiu       $t3, $zero, 0x1E
        ctx->r11 = ADD32(0, 0X1E);
            goto L_800231E0;
    }
    // 0x800231C0: addiu       $t3, $zero, 0x1E
    ctx->r11 = ADD32(0, 0X1E);
    // 0x800231C4: b           L_800231E0
    // 0x800231C8: sh          $t3, 0x116($s5)
    MEM_H(0X116, ctx->r21) = ctx->r11;
        goto L_800231E0;
    // 0x800231C8: sh          $t3, 0x116($s5)
    MEM_H(0X116, ctx->r21) = ctx->r11;
L_800231CC:
    // 0x800231CC: jal         0x80022A0C
    // 0x800231D0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_80022A0C(rdram, ctx);
        goto after_15;
    // 0x800231D0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_15:
    // 0x800231D4: beq         $v0, $zero, L_800231E0
    if (ctx->r2 == 0) {
        // 0x800231D8: addiu       $t4, $zero, 0xF
        ctx->r12 = ADD32(0, 0XF);
            goto L_800231E0;
    }
    // 0x800231D8: addiu       $t4, $zero, 0xF
    ctx->r12 = ADD32(0, 0XF);
    // 0x800231DC: sh          $t4, 0x116($s5)
    MEM_H(0X116, ctx->r21) = ctx->r12;
L_800231E0:
    // 0x800231E0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_800231E4:
    // 0x800231E4: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x800231E8: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x800231EC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800231F0: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800231F4: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800231F8: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x800231FC: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x80023200: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x80023204: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x80023208: jr          $ra
    // 0x8002320C: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    TRACE_RETURN()
    return;
    // 0x8002320C: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_80023210(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80023210: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80023214: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80023218: jal         0x80022C2C
    // 0x8002321C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80022C2C(rdram, ctx);
        goto after_0;
    // 0x8002321C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80023220: beql        $v0, $zero, L_80023258
    if (ctx->r2 == 0) {
        // 0x80023224: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80023258;
    }
    goto skip_0;
    // 0x80023224: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80023228: jal         0x80022BE4
    // 0x8002322C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80022BE4(rdram, ctx);
        goto after_1;
    // 0x8002322C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80023230: beq         $v0, $zero, L_80023254
    if (ctx->r2 == 0) {
        // 0x80023234: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80023254;
    }
    // 0x80023234: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80023238: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002323C: jal         0x80022A0C
    // 0x80023240: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    func_80022A0C(rdram, ctx);
        goto after_2;
    // 0x80023240: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80023244: beq         $v0, $zero, L_80023254
    if (ctx->r2 == 0) {
        // 0x80023248: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_80023254;
    }
    // 0x80023248: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8002324C: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x80023250: sh          $t6, 0x116($t7)
    MEM_H(0X116, ctx->r15) = ctx->r14;
L_80023254:
    // 0x80023254: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023258:
    // 0x80023258: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002325C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80023264(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80023264: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80023268: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002326C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80023270: lh          $t6, 0x11C($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X11C);
    // 0x80023274: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80023278: beq         $t6, $zero, L_800232DC
    if (ctx->r14 == 0) {
        // 0x8002327C: nop
    
            goto L_800232DC;
    }
    // 0x8002327C: nop

    // 0x80023280: jal         0x80022C2C
    // 0x80023284: nop

    func_80022C2C(rdram, ctx);
        goto after_0;
    // 0x80023284: nop

    after_0:
    // 0x80023288: lh          $t7, 0x116($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X116);
    // 0x8002328C: bne         $t7, $zero, L_80023308
    if (ctx->r15 != 0) {
        // 0x80023290: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_80023308;
    }
L_80023290:
    // 0x80023290: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80023294: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80023298: jal         0x80022A0C
    // 0x8002329C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80022A0C(rdram, ctx);
        goto after_1;
    // 0x8002329C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_1:
    // 0x800232A0: beql        $v0, $zero, L_8002330C
    if (ctx->r2 == 0) {
        // 0x800232A4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8002330C;
    }
    goto skip_0;
    // 0x800232A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800232A8: jal         0x80022BE4
    // 0x800232AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80022BE4(rdram, ctx);
        goto after_2;
    // 0x800232AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800232B0: beql        $v0, $zero, L_800232D4
    if (ctx->r2 == 0) {
        // 0x800232B4: sh          $zero, 0x116($s0)
        MEM_H(0X116, ctx->r16) = 0;
            goto L_800232D4;
    }
    goto skip_1;
    // 0x800232B4: sh          $zero, 0x116($s0)
    MEM_H(0X116, ctx->r16) = 0;
    skip_1:
    // 0x800232B8: lh          $t9, 0x11C($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X11C);
    // 0x800232BC: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x800232C0: sh          $t8, 0x116($s0)
    MEM_H(0X116, ctx->r16) = ctx->r24;
    // 0x800232C4: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x800232C8: b           L_80023308
    // 0x800232CC: sh          $t0, 0x11C($s0)
    MEM_H(0X11C, ctx->r16) = ctx->r8;
        goto L_80023308;
    // 0x800232CC: sh          $t0, 0x11C($s0)
    MEM_H(0X11C, ctx->r16) = ctx->r8;
    // 0x800232D0: sh          $zero, 0x116($s0)
    MEM_H(0X116, ctx->r16) = 0;
L_800232D4:
    // 0x800232D4: b           L_80023308
    // 0x800232D8: sh          $zero, 0x11C($s0)
    MEM_H(0X11C, ctx->r16) = 0;
        goto L_80023308;
    // 0x800232D8: sh          $zero, 0x11C($s0)
    MEM_H(0X11C, ctx->r16) = 0;
L_800232DC:
    // 0x800232DC: jal         0x80022C2C
    // 0x800232E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80022C2C(rdram, ctx);
        goto after_3;
    // 0x800232E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800232E4: beql        $v0, $zero, L_8002330C
    if (ctx->r2 == 0) {
        // 0x800232E8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8002330C;
    }
    goto skip_2;
    // 0x800232E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x800232EC: jal         0x80022BE4
    // 0x800232F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80022BE4(rdram, ctx);
        goto after_4;
    // 0x800232F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800232F4: beq         $v0, $zero, L_80023308
    if (ctx->r2 == 0) {
        // 0x800232F8: addiu       $t1, $zero, 0xA
        ctx->r9 = ADD32(0, 0XA);
            goto L_80023308;
    }
    // 0x800232F8: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x800232FC: sh          $t1, 0x11C($s0)
    MEM_H(0X11C, ctx->r16) = ctx->r9;
    // 0x80023300: b           L_80023290
    // 0x80023304: sh          $zero, 0x116($s0)
    MEM_H(0X116, ctx->r16) = 0;
        goto L_80023290;
    // 0x80023304: sh          $zero, 0x116($s0)
    MEM_H(0X116, ctx->r16) = 0;
L_80023308:
    // 0x80023308: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8002330C:
    // 0x8002330C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80023310: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80023314: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8002331C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8002331C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80023320: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80023324: jal         0x80022C2C
    // 0x80023328: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80022C2C(rdram, ctx);
        goto after_0;
    // 0x80023328: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002332C: beql        $v0, $zero, L_80023364
    if (ctx->r2 == 0) {
        // 0x80023330: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80023364;
    }
    goto skip_0;
    // 0x80023330: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80023334: jal         0x80022BE4
    // 0x80023338: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80022BE4(rdram, ctx);
        goto after_1;
    // 0x80023338: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8002333C: beq         $v0, $zero, L_80023360
    if (ctx->r2 == 0) {
        // 0x80023340: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_80023360;
    }
    // 0x80023340: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80023344: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80023348: jal         0x80022A0C
    // 0x8002334C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    func_80022A0C(rdram, ctx);
        goto after_2;
    // 0x8002334C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80023350: beq         $v0, $zero, L_80023360
    if (ctx->r2 == 0) {
        // 0x80023354: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_80023360;
    }
    // 0x80023354: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80023358: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x8002335C: sh          $t6, 0x116($t7)
    MEM_H(0X116, ctx->r15) = ctx->r14;
L_80023360:
    // 0x80023360: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023364:
    // 0x80023364: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80023368: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80023370(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80023370: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80023374: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80023378: jal         0x80022C2C
    // 0x8002337C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80022C2C(rdram, ctx);
        goto after_0;
    // 0x8002337C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80023380: beql        $v0, $zero, L_800233B8
    if (ctx->r2 == 0) {
        // 0x80023384: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800233B8;
    }
    goto skip_0;
    // 0x80023384: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80023388: jal         0x80022BE4
    // 0x8002338C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80022BE4(rdram, ctx);
        goto after_1;
    // 0x8002338C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80023390: beq         $v0, $zero, L_800233B4
    if (ctx->r2 == 0) {
        // 0x80023394: addiu       $a0, $zero, 0x8
        ctx->r4 = ADD32(0, 0X8);
            goto L_800233B4;
    }
    // 0x80023394: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80023398: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002339C: jal         0x80022A0C
    // 0x800233A0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    func_80022A0C(rdram, ctx);
        goto after_2;
    // 0x800233A0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800233A4: beq         $v0, $zero, L_800233B4
    if (ctx->r2 == 0) {
        // 0x800233A8: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_800233B4;
    }
    // 0x800233A8: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800233AC: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x800233B0: sh          $t6, 0x116($t7)
    MEM_H(0X116, ctx->r15) = ctx->r14;
L_800233B4:
    // 0x800233B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800233B8:
    // 0x800233B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800233BC: jr          $ra
    TRACE_RETURN()
    return;
;}
