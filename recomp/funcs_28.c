#include "recomp.h"
#include "trace.h"
#include "funcs.h"

RECOMP_FUNC void func_8005BB24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005BB24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005BB28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005BB2C: lw          $t6, 0x48($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X48);
    // 0x8005BB30: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005BB34: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8005BB38: bne         $t6, $at, L_8005BB48
    if (ctx->r14 != ctx->r1) {
        // 0x8005BB3C: nop
    
            goto L_8005BB48;
    }
    // 0x8005BB3C: nop

    // 0x8005BB40: bnel        $s5, $zero, L_8005BB54
    if (ctx->r21 != 0) {
        // 0x8005BB44: sw          $t0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r8;
            goto L_8005BB54;
    }
    goto skip_0;
    // 0x8005BB44: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    skip_0:
L_8005BB48:
    // 0x8005BB48: b           L_8005BDAC
    // 0x8005BB4C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_8005BDAC;
    // 0x8005BB4C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8005BB50: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
L_8005BB54:
    // 0x8005BB54: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x8005BB58: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8005BB5C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x8005BB60: jalr        $t9
    // 0x8005BB64: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8005BB64: nop

    after_0:
    // 0x8005BB68: lh          $t7, 0x0($s6)
    ctx->r15 = MEM_H(ctx->r22, 0X0);
    // 0x8005BB6C: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8005BB70: sll         $s7, $s5, 1
    ctx->r23 = S32(ctx->r21 << 1);
    // 0x8005BB74: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8005BB78: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x8005BB7C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8005BB80: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x8005BB84: lui         $at, 0x808
    ctx->r1 = S32(0X808 << 16);
    // 0x8005BB88: addiu       $s4, $v0, 0x10
    ctx->r20 = ADD32(ctx->r2, 0X10);
    // 0x8005BB8C: addiu       $t8, $t9, 0x440
    ctx->r24 = ADD32(ctx->r25, 0X440);
    // 0x8005BB90: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x8005BB94: andi        $t9, $s7, 0xFFFF
    ctx->r25 = ctx->r23 & 0XFFFF;
    // 0x8005BB98: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x8005BB9C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8005BBA0: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x8005BBA4: addiu       $t6, $t8, 0x580
    ctx->r14 = ADD32(ctx->r24, 0X580);
    // 0x8005BBA8: andi        $t9, $t6, 0xFFFF
    ctx->r25 = ctx->r14 & 0XFFFF;
    // 0x8005BBAC: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x8005BBB0: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x8005BBB4: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
    // 0x8005BBB8: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x8005BBBC: addiu       $t8, $v1, 0x800
    ctx->r24 = ADD32(ctx->r3, 0X800);
    // 0x8005BBC0: andi        $t6, $t8, 0xFFFF
    ctx->r14 = ctx->r24 & 0XFFFF;
    // 0x8005BBC4: addiu       $t7, $v1, 0x6C0
    ctx->r15 = ADD32(ctx->r3, 0X6C0);
    // 0x8005BBC8: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8005BBCC: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8005BBD0: sw          $t9, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r25;
    // 0x8005BBD4: lw          $t7, 0x38($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X38);
    // 0x8005BBD8: lui         $t9, 0x8007
    ctx->r25 = S32(0X8007 << 16);
    // 0x8005BBDC: beql        $t7, $zero, L_8005BD7C
    if (ctx->r15 == 0) {
        // 0x8005BBE0: lui         $t7, 0x308
        ctx->r15 = S32(0X308 << 16);
            goto L_8005BD7C;
    }
    goto skip_1;
    // 0x8005BBE0: lui         $t7, 0x308
    ctx->r15 = S32(0X308 << 16);
    skip_1:
    // 0x8005BBE4: lh          $t6, 0x18($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X18);
    // 0x8005BBE8: sw          $zero, 0x38($s3)
    MEM_W(0X38, ctx->r19) = 0;
    // 0x8005BBEC: lh          $t7, 0x1A($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X1A);
    // 0x8005BBF0: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x8005BBF4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8005BBF8: lh          $t9, 0x4610($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X4610);
    // 0x8005BBFC: lw          $a0, 0x34($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X34);
    // 0x8005BC00: addiu       $s1, $s3, 0x24
    ctx->r17 = ADD32(ctx->r19, 0X24);
    // 0x8005BC04: multu       $t9, $t7
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005BC08: lh          $t9, 0x1C($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X1C);
    // 0x8005BC0C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8005BC10: nop

    // 0x8005BC14: cvt.d.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.d = CVT_D_W(ctx->f4.u32l);
    // 0x8005BC18: mflo        $t6
    ctx->r14 = lo;
    // 0x8005BC1C: sra         $t8, $t6, 15
    ctx->r24 = S32(SIGNED(ctx->r14) >> 15);
    // 0x8005BC20: sh          $t8, 0x28($s3)
    MEM_H(0X28, ctx->r19) = ctx->r24;
    // 0x8005BC24: lh          $t7, 0x28($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X28);
    // 0x8005BC28: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8005BC2C: jal         0x8005B954
    // 0x8005BC30: cvt.d.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.d = CVT_D_W(ctx->f6.u32l);
    func_8005B954(rdram, ctx);
        goto after_1;
    // 0x8005BC30: cvt.d.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.d = CVT_D_W(ctx->f6.u32l);
    after_1:
    // 0x8005BC34: lh          $t6, 0x18($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X18);
    // 0x8005BC38: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x8005BC3C: sh          $v0, 0x26($s3)
    MEM_H(0X26, ctx->r19) = ctx->r2;
    // 0x8005BC40: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x8005BC44: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x8005BC48: addu        $t7, $t7, $t9
    ctx->r15 = ADD32(ctx->r15, ctx->r25);
    // 0x8005BC4C: lh          $t7, 0x470E($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X470E);
    // 0x8005BC50: lh          $t6, 0x1A($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X1A);
    // 0x8005BC54: lw          $a0, 0x34($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X34);
    // 0x8005BC58: addiu       $s1, $s3, 0x2A
    ctx->r17 = ADD32(ctx->r19, 0X2A);
    // 0x8005BC5C: multu       $t7, $t6
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005BC60: lh          $t7, 0x1E($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X1E);
    // 0x8005BC64: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8005BC68: nop

    // 0x8005BC6C: cvt.d.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.d = CVT_D_W(ctx->f8.u32l);
    // 0x8005BC70: mflo        $t8
    ctx->r24 = lo;
    // 0x8005BC74: sra         $t9, $t8, 15
    ctx->r25 = S32(SIGNED(ctx->r24) >> 15);
    // 0x8005BC78: sh          $t9, 0x2E($s3)
    MEM_H(0X2E, ctx->r19) = ctx->r25;
    // 0x8005BC7C: lh          $t6, 0x2E($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X2E);
    // 0x8005BC80: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8005BC84: jal         0x8005B954
    // 0x8005BC88: cvt.d.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.d = CVT_D_W(ctx->f10.u32l);
    func_8005B954(rdram, ctx);
        goto after_2;
    // 0x8005BC88: cvt.d.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.d = CVT_D_W(ctx->f10.u32l);
    after_2:
    // 0x8005BC8C: lh          $t8, 0x1C($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X1C);
    // 0x8005BC90: sh          $v0, 0x2C($s3)
    MEM_H(0X2C, ctx->r19) = ctx->r2;
    // 0x8005BC94: or          $v1, $s4, $zero
    ctx->r3 = ctx->r20 | 0;
    // 0x8005BC98: lui         $at, 0x906
    ctx->r1 = S32(0X906 << 16);
    // 0x8005BC9C: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x8005BCA0: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x8005BCA4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8005BCA8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005BCAC: lh          $t6, 0x1E($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X1E);
    // 0x8005BCB0: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x8005BCB4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8005BCB8: lui         $at, 0x904
    ctx->r1 = S32(0X904 << 16);
    // 0x8005BCBC: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x8005BCC0: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8005BCC4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8005BCC8: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8005BCCC: lh          $t7, 0x28($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X28);
    // 0x8005BCD0: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x8005BCD4: lui         $at, 0x902
    ctx->r1 = S32(0X902 << 16);
    // 0x8005BCD8: andi        $t6, $t7, 0xFFFF
    ctx->r14 = ctx->r15 & 0XFFFF;
    // 0x8005BCDC: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x8005BCE0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8005BCE4: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8005BCE8: lh          $t7, 0x26($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X26);
    // 0x8005BCEC: lhu         $t9, 0x24($s3)
    ctx->r25 = MEM_HU(ctx->r19, 0X24);
    // 0x8005BCF0: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x8005BCF4: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x8005BCF8: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x8005BCFC: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8005BD00: lh          $t8, 0x2E($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X2E);
    // 0x8005BD04: lui         $at, 0x900
    ctx->r1 = S32(0X900 << 16);
    // 0x8005BD08: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x8005BD0C: andi        $t6, $t8, 0xFFFF
    ctx->r14 = ctx->r24 & 0XFFFF;
    // 0x8005BD10: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x8005BD14: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8005BD18: lh          $t8, 0x2C($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X2C);
    // 0x8005BD1C: lhu         $t7, 0x2A($s3)
    ctx->r15 = MEM_HU(ctx->r19, 0X2A);
    // 0x8005BD20: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x8005BD24: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x8005BD28: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8005BD2C: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x8005BD30: lh          $t9, 0x20($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X20);
    // 0x8005BD34: lui         $at, 0x908
    ctx->r1 = S32(0X908 << 16);
    // 0x8005BD38: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x8005BD3C: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x8005BD40: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8005BD44: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005BD48: lh          $t8, 0x22($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X22);
    // 0x8005BD4C: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x8005BD50: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x8005BD54: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x8005BD58: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8005BD5C: lui         $t6, 0x309
    ctx->r14 = S32(0X309 << 16);
    // 0x8005BD60: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8005BD64: lw          $a0, 0x14($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X14);
    // 0x8005BD68: jal         0x80053750
    // 0x8005BD6C: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_3;
    // 0x8005BD6C: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    after_3:
    // 0x8005BD70: b           L_8005BD90
    // 0x8005BD74: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
        goto L_8005BD90;
    // 0x8005BD74: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x8005BD78: lui         $t7, 0x308
    ctx->r15 = S32(0X308 << 16);
L_8005BD7C:
    // 0x8005BD7C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8005BD80: lw          $a0, 0x14($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X14);
    // 0x8005BD84: jal         0x80053750
    // 0x8005BD88: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_4;
    // 0x8005BD88: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    after_4:
    // 0x8005BD8C: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
L_8005BD90:
    // 0x8005BD90: lh          $t8, 0x0($s6)
    ctx->r24 = MEM_H(ctx->r22, 0X0);
    // 0x8005BD94: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x8005BD98: addu        $t9, $t8, $s7
    ctx->r25 = ADD32(ctx->r24, ctx->r23);
    // 0x8005BD9C: sh          $t9, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r25;
    // 0x8005BDA0: lw          $t6, 0x30($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X30);
    // 0x8005BDA4: addu        $t7, $t6, $s5
    ctx->r15 = ADD32(ctx->r14, ctx->r21);
    // 0x8005BDA8: sw          $t7, 0x30($s3)
    MEM_W(0X30, ctx->r19) = ctx->r15;
L_8005BDAC:
    // 0x8005BDAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005BDB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005BDB4: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005BDBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005BDBC: sw          $a1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r5;
    // 0x8005BDC0: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x8005BDC4: sw          $a2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r6;
    // 0x8005BDC8: andi        $t8, $a2, 0xFFFF
    ctx->r24 = ctx->r6 & 0XFFFF;
    // 0x8005BDCC: sra         $t9, $a0, 3
    ctx->r25 = S32(SIGNED(ctx->r4) >> 3);
    // 0x8005BDD0: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x8005BDD4: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8005BDD8: bne         $t9, $zero, L_8005BDE8
    if (ctx->r25 != 0) {
        // 0x8005BDDC: or          $a0, $t9, $zero
        ctx->r4 = ctx->r25 | 0;
            goto L_8005BDE8;
    }
    // 0x8005BDDC: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x8005BDE0: jr          $ra
    // 0x8005BDE4: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    TRACE_RETURN()
    return;
    // 0x8005BDE4: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8005BDE8:
    // 0x8005BDE8: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x8005BDEC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8005BDF0: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x8005BDF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005BDF8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005BDFC: bgez        $a2, L_8005BE14
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8005BE00: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8005BE14;
    }
    // 0x8005BE00: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005BE04: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8005BE08: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005BE0C: nop

    // 0x8005BE10: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_8005BE14:
    // 0x8005BE14: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x8005BE18: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8005BE1C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005BE20: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005BE24: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8005BE28: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
    // 0x8005BE2C: div.s       $f0, $f8, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8005BE30: andi        $t7, $a0, 0x1
    ctx->r15 = ctx->r4 & 0X1;
L_8005BE34:
    // 0x8005BE34: beq         $t7, $zero, L_8005BE44
    if (ctx->r15 == 0) {
        // 0x8005BE38: sra         $t8, $a0, 1
        ctx->r24 = S32(SIGNED(ctx->r4) >> 1);
            goto L_8005BE44;
    }
    // 0x8005BE38: sra         $t8, $a0, 1
    ctx->r24 = S32(SIGNED(ctx->r4) >> 1);
    // 0x8005BE3C: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8005BE40: nop

L_8005BE44:
    // 0x8005BE44: beq         $t8, $zero, L_8005BE5C
    if (ctx->r24 == 0) {
        // 0x8005BE48: or          $a0, $t8, $zero
        ctx->r4 = ctx->r24 | 0;
            goto L_8005BE5C;
    }
    // 0x8005BE48: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8005BE4C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005BE50: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005BE54: bnel        $v0, $v1, L_8005BE34
    if (ctx->r2 != ctx->r3) {
        // 0x8005BE58: andi        $t7, $a0, 0x1
        ctx->r15 = ctx->r4 & 0X1;
            goto L_8005BE34;
    }
    goto skip_0;
    // 0x8005BE58: andi        $t7, $a0, 0x1
    ctx->r15 = ctx->r4 & 0X1;
    skip_0:
L_8005BE5C:
    // 0x8005BE5C: mul.s       $f0, $f12, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x8005BE60: nop

    // 0x8005BE64: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005BE6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005BE6C: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x8005BE70: lw          $t6, 0xB8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB8);
    // 0x8005BE74: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8005BE78: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8005BE7C: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8005BE80: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8005BE84: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8005BE88: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8005BE8C: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8005BE90: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8005BE94: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8005BE98: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8005BE9C: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8005BEA0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8005BEA4: sw          $a1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r5;
    // 0x8005BEA8: sw          $a2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r6;
    // 0x8005BEAC: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    // 0x8005BEB0: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x8005BEB4: sw          $a3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r7;
    // 0x8005BEB8: sh          $zero, 0x8E($sp)
    MEM_H(0X8E, ctx->r29) = 0;
    // 0x8005BEBC: sh          $zero, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = 0;
    // 0x8005BEC0: sw          $t6, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r14;
    // 0x8005BEC4: lw          $t8, 0x3C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X3C);
    // 0x8005BEC8: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x8005BECC: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8005BED0: beql        $t8, $zero, L_8005C344
    if (ctx->r24 == 0) {
        // 0x8005BED4: or          $s3, $fp, $zero
        ctx->r19 = ctx->r30 | 0;
            goto L_8005C344;
    }
    goto skip_0;
    // 0x8005BED4: or          $s3, $fp, $zero
    ctx->r19 = ctx->r30 | 0;
    skip_0:
    // 0x8005BED8: lw          $v1, 0x3C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X3C);
L_8005BEDC:
    // 0x8005BEDC: lw          $v0, 0x94($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X94);
    // 0x8005BEE0: lw          $t8, 0xB0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB0);
    // 0x8005BEE4: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x8005BEE8: subu        $t7, $t9, $v0
    ctx->r15 = SUB32(ctx->r25, ctx->r2);
    // 0x8005BEEC: slt         $at, $t8, $t7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8005BEF0: sw          $t7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r15;
    // 0x8005BEF4: bne         $at, $zero, L_8005C340
    if (ctx->r1 != 0) {
        // 0x8005BEF8: sw          $t9, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->r25;
            goto L_8005C340;
    }
    // 0x8005BEF8: sw          $t9, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r25;
    // 0x8005BEFC: lhu         $t9, 0x8($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X8);
    // 0x8005BF00: sltiu       $at, $t9, 0x11
    ctx->r1 = ctx->r25 < 0X11 ? 1 : 0;
    // 0x8005BF04: beq         $at, $zero, L_8005C2B8
    if (ctx->r1 == 0) {
        // 0x8005BF08: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_8005C2B8;
    }
    // 0x8005BF08: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8005BF0C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8005BF10: addu        $at, $at, $t9
    gpr jr_addend_8005BF18 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8005BF14: lw          $t9, -0x6890($at)
    ctx->r25 = ADD32(ctx->r1, -0X6890);
    // 0x8005BF18: jr          $t9
    // 0x8005BF1C: nop

    switch (jr_addend_8005BF18 >> 2) {
        case 0: goto L_8005C298; break;
        case 1: goto L_8005C2B8; break;
        case 2: goto L_8005C2B8; break;
        case 3: goto L_8005C2B8; break;
        case 4: goto L_8005C2B8; break;
        case 5: goto L_8005C2B8; break;
        case 6: goto L_8005C2B8; break;
        case 7: goto L_8005C2B8; break;
        case 8: goto L_8005C2B8; break;
        case 9: goto L_8005C2B8; break;
        case 10: goto L_8005C2B8; break;
        case 11: goto L_8005C060; break;
        case 12: goto L_8005C060; break;
        case 13: goto L_8005BF20; break;
        case 14: goto L_8005C204; break;
        case 15: goto L_8005C258; break;
        case 16: goto L_8005C060; break;
        default: switch_error(__func__, 0x8005BF18, 0x80079770);
    }
    // 0x8005BF1C: nop

L_8005BF20:
    // 0x8005BF20: lh          $t6, 0xA($v1)
    ctx->r14 = MEM_H(ctx->r3, 0XA);
    // 0x8005BF24: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x8005BF28: beql        $t6, $zero, L_8005BF48
    if (ctx->r14 == 0) {
        // 0x8005BF2C: lw          $t9, 0x8($fp)
        ctx->r25 = MEM_W(ctx->r30, 0X8);
            goto L_8005BF48;
    }
    goto skip_1;
    // 0x8005BF2C: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    skip_1:
    // 0x8005BF30: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    // 0x8005BF34: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8005BF38: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8005BF3C: jalr        $t9
    // 0x8005BF40: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8005BF40: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8005BF44: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
L_8005BF48:
    // 0x8005BF48: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8005BF4C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8005BF50: jalr        $t9
    // 0x8005BF54: lw          $a2, 0x18($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X18);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8005BF54: lw          $a2, 0x18($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X18);
    after_1:
    // 0x8005BF58: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    // 0x8005BF5C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8005BF60: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x8005BF64: jalr        $t9
    // 0x8005BF68: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8005BF68: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8005BF6C: sw          $s1, 0x38($fp)
    MEM_W(0X38, ctx->r30) = ctx->r17;
    // 0x8005BF70: sw          $zero, 0x30($fp)
    MEM_W(0X30, ctx->r30) = 0;
    // 0x8005BF74: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x8005BF78: sw          $t8, 0x34($fp)
    MEM_W(0X34, ctx->r30) = ctx->r24;
    // 0x8005BF7C: lh          $v1, 0x10($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X10);
    // 0x8005BF80: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005BF84: mflo        $a0
    ctx->r4 = lo;
    // 0x8005BF88: sra         $t7, $a0, 15
    ctx->r15 = S32(SIGNED(ctx->r4) >> 15);
    // 0x8005BF8C: sh          $t7, 0x1A($fp)
    MEM_H(0X1A, ctx->r30) = ctx->r15;
    // 0x8005BF90: lbu         $t6, 0x12($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X12);
    // 0x8005BF94: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x8005BF98: sh          $t6, 0x18($fp)
    MEM_H(0X18, ctx->r30) = ctx->r14;
    // 0x8005BF9C: lbu         $t9, 0x13($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X13);
    // 0x8005BFA0: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x8005BFA4: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x8005BFA8: lh          $t7, 0x4610($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X4610);
    // 0x8005BFAC: sh          $t7, 0x20($fp)
    MEM_H(0X20, ctx->r30) = ctx->r15;
    // 0x8005BFB0: lbu         $t6, 0x13($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X13);
    // 0x8005BFB4: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x8005BFB8: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x8005BFBC: negu        $t8, $t9
    ctx->r24 = SUB32(0, ctx->r25);
    // 0x8005BFC0: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x8005BFC4: lh          $t7, 0x470E($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X470E);
    // 0x8005BFC8: sh          $t7, 0x22($fp)
    MEM_H(0X22, ctx->r30) = ctx->r15;
    // 0x8005BFCC: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x8005BFD0: beql        $t6, $zero, L_8005BFE8
    if (ctx->r14 == 0) {
        // 0x8005BFD4: lh          $v0, 0x18($fp)
        ctx->r2 = MEM_H(ctx->r30, 0X18);
            goto L_8005BFE8;
    }
    goto skip_2;
    // 0x8005BFD4: lh          $v0, 0x18($fp)
    ctx->r2 = MEM_H(ctx->r30, 0X18);
    skip_2:
    // 0x8005BFD8: sh          $s1, 0x1C($fp)
    MEM_H(0X1C, ctx->r30) = ctx->r17;
    // 0x8005BFDC: b           L_8005C02C
    // 0x8005BFE0: sh          $s1, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r17;
        goto L_8005C02C;
    // 0x8005BFE0: sh          $s1, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r17;
    // 0x8005BFE4: lh          $v0, 0x18($fp)
    ctx->r2 = MEM_H(ctx->r30, 0X18);
L_8005BFE8:
    // 0x8005BFE8: lui         $t8, 0x8007
    ctx->r24 = S32(0X8007 << 16);
    // 0x8005BFEC: lh          $v1, 0x1A($fp)
    ctx->r3 = MEM_H(ctx->r30, 0X1A);
    // 0x8005BFF0: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x8005BFF4: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x8005BFF8: lh          $t8, 0x4610($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X4610);
    // 0x8005BFFC: negu        $t9, $t9
    ctx->r25 = SUB32(0, ctx->r25);
    // 0x8005C000: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005C004: lui         $t8, 0x8007
    ctx->r24 = S32(0X8007 << 16);
    // 0x8005C008: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x8005C00C: mflo        $t7
    ctx->r15 = lo;
    // 0x8005C010: sra         $t6, $t7, 15
    ctx->r14 = S32(SIGNED(ctx->r15) >> 15);
    // 0x8005C014: sh          $t6, 0x1C($fp)
    MEM_H(0X1C, ctx->r30) = ctx->r14;
    // 0x8005C018: lh          $t8, 0x470E($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X470E);
    // 0x8005C01C: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005C020: mflo        $t7
    ctx->r15 = lo;
    // 0x8005C024: sra         $t6, $t7, 15
    ctx->r14 = S32(SIGNED(ctx->r15) >> 15);
    // 0x8005C028: sh          $t6, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r14;
L_8005C02C:
    // 0x8005C02C: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x8005C030: beql        $t9, $zero, L_8005C2F8
    if (ctx->r25 == 0) {
        // 0x8005C034: lw          $t8, 0x60($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X60);
            goto L_8005C2F8;
    }
    goto skip_3;
    // 0x8005C034: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    skip_3:
    // 0x8005C038: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005C03C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8005C040: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x8005C044: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    // 0x8005C048: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    // 0x8005C04C: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x8005C050: jalr        $t9
    // 0x8005C054: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x8005C054: nop

    after_3:
    // 0x8005C058: b           L_8005C2F8
    // 0x8005C05C: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
        goto L_8005C2F8;
    // 0x8005C05C: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
L_8005C060:
    // 0x8005C060: or          $s3, $fp, $zero
    ctx->r19 = ctx->r30 | 0;
    // 0x8005C064: addiu       $s6, $sp, 0x9E
    ctx->r22 = ADD32(ctx->r29, 0X9E);
    // 0x8005C068: addiu       $s0, $sp, 0x8E
    ctx->r16 = ADD32(ctx->r29, 0X8E);
    // 0x8005C06C: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x8005C070: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x8005C074: jal         0x8005BB24
    // 0x8005C078: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    func_8005BB24(rdram, ctx);
        goto after_4;
    // 0x8005C078: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    after_4:
    // 0x8005C07C: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x8005C080: lw          $a0, 0x34($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X34);
    // 0x8005C084: lw          $a3, 0x30($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X30);
    // 0x8005C088: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8005C08C: slt         $at, $a3, $a0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8005C090: bnel        $at, $zero, L_8005C0FC
    if (ctx->r1 != 0) {
        // 0x8005C094: lh          $t6, 0x1C($fp)
        ctx->r14 = MEM_H(ctx->r30, 0X1C);
            goto L_8005C0FC;
    }
    goto skip_4;
    // 0x8005C094: lh          $t6, 0x1C($fp)
    ctx->r14 = MEM_H(ctx->r30, 0X1C);
    skip_4:
    // 0x8005C098: lh          $v0, 0x18($fp)
    ctx->r2 = MEM_H(ctx->r30, 0X18);
    // 0x8005C09C: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x8005C0A0: lh          $v1, 0x1A($fp)
    ctx->r3 = MEM_H(ctx->r30, 0X1A);
    // 0x8005C0A4: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x8005C0A8: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x8005C0AC: lh          $t7, 0x4610($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X4610);
    // 0x8005C0B0: negu        $t8, $t8
    ctx->r24 = SUB32(0, ctx->r24);
    // 0x8005C0B4: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005C0B8: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x8005C0BC: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x8005C0C0: mflo        $t6
    ctx->r14 = lo;
    // 0x8005C0C4: sra         $t9, $t6, 15
    ctx->r25 = S32(SIGNED(ctx->r14) >> 15);
    // 0x8005C0C8: sh          $t9, 0x28($fp)
    MEM_H(0X28, ctx->r30) = ctx->r25;
    // 0x8005C0CC: lh          $t7, 0x470E($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X470E);
    // 0x8005C0D0: lh          $t8, 0x28($fp)
    ctx->r24 = MEM_H(ctx->r30, 0X28);
    // 0x8005C0D4: sw          $a0, 0x30($fp)
    MEM_W(0X30, ctx->r30) = ctx->r4;
    // 0x8005C0D8: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005C0DC: sh          $t8, 0x1C($fp)
    MEM_H(0X1C, ctx->r30) = ctx->r24;
    // 0x8005C0E0: mflo        $t6
    ctx->r14 = lo;
    // 0x8005C0E4: sra         $t9, $t6, 15
    ctx->r25 = S32(SIGNED(ctx->r14) >> 15);
    // 0x8005C0E8: sh          $t9, 0x2E($fp)
    MEM_H(0X2E, ctx->r30) = ctx->r25;
    // 0x8005C0EC: lh          $t7, 0x2E($fp)
    ctx->r15 = MEM_H(ctx->r30, 0X2E);
    // 0x8005C0F0: b           L_8005C14C
    // 0x8005C0F4: sh          $t7, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r15;
        goto L_8005C14C;
    // 0x8005C0F4: sh          $t7, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r15;
    // 0x8005C0F8: lh          $t6, 0x1C($fp)
    ctx->r14 = MEM_H(ctx->r30, 0X1C);
L_8005C0FC:
    // 0x8005C0FC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8005C100: lh          $a1, 0x26($fp)
    ctx->r5 = MEM_H(ctx->r30, 0X26);
    // 0x8005C104: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8005C108: lhu         $a2, 0x24($fp)
    ctx->r6 = MEM_HU(ctx->r30, 0X24);
    // 0x8005C10C: jal         0x8005BDBC
    // 0x8005C110: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    func_8005BDBC(rdram, ctx);
        goto after_5;
    // 0x8005C110: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    after_5:
    // 0x8005C114: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005C118: lh          $t7, 0x1E($fp)
    ctx->r15 = MEM_H(ctx->r30, 0X1E);
    // 0x8005C11C: lw          $a0, 0x30($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X30);
    // 0x8005C120: lh          $a1, 0x2C($fp)
    ctx->r5 = MEM_H(ctx->r30, 0X2C);
    // 0x8005C124: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x8005C128: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8005C12C: lhu         $a2, 0x2A($fp)
    ctx->r6 = MEM_HU(ctx->r30, 0X2A);
    // 0x8005C130: sh          $t8, 0x1C($fp)
    MEM_H(0X1C, ctx->r30) = ctx->r24;
    // 0x8005C134: jal         0x8005BDBC
    // 0x8005C138: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    func_8005BDBC(rdram, ctx);
        goto after_6;
    // 0x8005C138: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    after_6:
    // 0x8005C13C: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005C140: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x8005C144: nop

    // 0x8005C148: sh          $t9, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r25;
L_8005C14C:
    // 0x8005C14C: lh          $t8, 0x1C($fp)
    ctx->r24 = MEM_H(ctx->r30, 0X1C);
    // 0x8005C150: bnel        $t8, $zero, L_8005C160
    if (ctx->r24 != 0) {
        // 0x8005C154: lh          $t7, 0x1E($fp)
        ctx->r15 = MEM_H(ctx->r30, 0X1E);
            goto L_8005C160;
    }
    goto skip_5;
    // 0x8005C154: lh          $t7, 0x1E($fp)
    ctx->r15 = MEM_H(ctx->r30, 0X1E);
    skip_5:
    // 0x8005C158: sh          $s1, 0x1C($fp)
    MEM_H(0X1C, ctx->r30) = ctx->r17;
    // 0x8005C15C: lh          $t7, 0x1E($fp)
    ctx->r15 = MEM_H(ctx->r30, 0X1E);
L_8005C160:
    // 0x8005C160: bnel        $t7, $zero, L_8005C170
    if (ctx->r15 != 0) {
        // 0x8005C164: lw          $v1, 0x3C($fp)
        ctx->r3 = MEM_W(ctx->r30, 0X3C);
            goto L_8005C170;
    }
    goto skip_6;
    // 0x8005C164: lw          $v1, 0x3C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X3C);
    skip_6:
    // 0x8005C168: sh          $s1, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r17;
    // 0x8005C16C: lw          $v1, 0x3C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X3C);
L_8005C170:
    // 0x8005C170: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8005C174: lh          $a0, 0x8($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X8);
    // 0x8005C178: bnel        $a0, $at, L_8005C190
    if (ctx->r4 != ctx->r1) {
        // 0x8005C17C: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_8005C190;
    }
    goto skip_7;
    // 0x8005C17C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    skip_7:
    // 0x8005C180: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
    // 0x8005C184: sh          $t6, 0x18($fp)
    MEM_H(0X18, ctx->r30) = ctx->r14;
    // 0x8005C188: lh          $a0, 0x8($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X8);
    // 0x8005C18C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
L_8005C190:
    // 0x8005C190: bnel        $a0, $at, L_8005C1C0
    if (ctx->r4 != ctx->r1) {
        // 0x8005C194: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_8005C1C0;
    }
    goto skip_8;
    // 0x8005C194: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    skip_8:
    // 0x8005C198: sw          $zero, 0x30($fp)
    MEM_W(0X30, ctx->r30) = 0;
    // 0x8005C19C: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x8005C1A0: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005C1A4: mflo        $v0
    ctx->r2 = lo;
    // 0x8005C1A8: sra         $t9, $v0, 15
    ctx->r25 = S32(SIGNED(ctx->r2) >> 15);
    // 0x8005C1AC: sh          $t9, 0x1A($fp)
    MEM_H(0X1A, ctx->r30) = ctx->r25;
    // 0x8005C1B0: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
    // 0x8005C1B4: sw          $t8, 0x34($fp)
    MEM_W(0X34, ctx->r30) = ctx->r24;
    // 0x8005C1B8: lh          $a0, 0x8($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X8);
    // 0x8005C1BC: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
L_8005C1C0:
    // 0x8005C1C0: bne         $a0, $at, L_8005C1FC
    if (ctx->r4 != ctx->r1) {
        // 0x8005C1C4: nop
    
            goto L_8005C1FC;
    }
    // 0x8005C1C4: nop

    // 0x8005C1C8: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x8005C1CC: lui         $t9, 0x8007
    ctx->r25 = S32(0X8007 << 16);
    // 0x8005C1D0: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x8005C1D4: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x8005C1D8: lh          $t9, 0x4610($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X4610);
    // 0x8005C1DC: sh          $t9, 0x20($fp)
    MEM_H(0X20, ctx->r30) = ctx->r25;
    // 0x8005C1E0: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
    // 0x8005C1E4: lui         $t9, 0x8007
    ctx->r25 = S32(0X8007 << 16);
    // 0x8005C1E8: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x8005C1EC: negu        $t6, $t7
    ctx->r14 = SUB32(0, ctx->r15);
    // 0x8005C1F0: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x8005C1F4: lh          $t9, 0x470E($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X470E);
    // 0x8005C1F8: sh          $t9, 0x22($fp)
    MEM_H(0X22, ctx->r30) = ctx->r25;
L_8005C1FC:
    // 0x8005C1FC: b           L_8005C2F4
    // 0x8005C200: sw          $s1, 0x38($fp)
    MEM_W(0X38, ctx->r30) = ctx->r17;
        goto L_8005C2F4;
    // 0x8005C200: sw          $s1, 0x38($fp)
    MEM_W(0X38, ctx->r30) = ctx->r17;
L_8005C204:
    // 0x8005C204: lh          $t8, 0xA($v1)
    ctx->r24 = MEM_H(ctx->r3, 0XA);
    // 0x8005C208: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x8005C20C: beql        $t8, $zero, L_8005C22C
    if (ctx->r24 == 0) {
        // 0x8005C210: lw          $t9, 0x8($fp)
        ctx->r25 = MEM_W(ctx->r30, 0X8);
            goto L_8005C22C;
    }
    goto skip_9;
    // 0x8005C210: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    skip_9:
    // 0x8005C214: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    // 0x8005C218: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8005C21C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8005C220: jalr        $t9
    // 0x8005C224: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_7;
    // 0x8005C224: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x8005C228: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
L_8005C22C:
    // 0x8005C22C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8005C230: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8005C234: jalr        $t9
    // 0x8005C238: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x8005C238: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    after_8:
    // 0x8005C23C: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    // 0x8005C240: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8005C244: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x8005C248: jalr        $t9
    // 0x8005C24C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_9;
    // 0x8005C24C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x8005C250: b           L_8005C2F8
    // 0x8005C254: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
        goto L_8005C2F8;
    // 0x8005C254: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
L_8005C258:
    // 0x8005C258: or          $s3, $fp, $zero
    ctx->r19 = ctx->r30 | 0;
    // 0x8005C25C: addiu       $s6, $sp, 0x9E
    ctx->r22 = ADD32(ctx->r29, 0X9E);
    // 0x8005C260: addiu       $s0, $sp, 0x8E
    ctx->r16 = ADD32(ctx->r29, 0X8E);
    // 0x8005C264: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x8005C268: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x8005C26C: jal         0x8005BB24
    // 0x8005C270: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    func_8005BB24(rdram, ctx);
        goto after_10;
    // 0x8005C270: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    after_10:
    // 0x8005C274: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x8005C278: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    // 0x8005C27C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8005C280: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8005C284: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8005C288: jalr        $t9
    // 0x8005C28C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_11;
    // 0x8005C28C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x8005C290: b           L_8005C2F8
    // 0x8005C294: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
        goto L_8005C2F8;
    // 0x8005C294: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
L_8005C298:
    // 0x8005C298: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x8005C29C: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x8005C2A0: lw          $a0, 0x3190($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3190);
    // 0x8005C2A4: sw          $zero, 0xD8($t7)
    MEM_W(0XD8, ctx->r15) = 0;
    // 0x8005C2A8: jal         0x80053840
    // 0x8005C2AC: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    func_80053840(rdram, ctx);
        goto after_12;
    // 0x8005C2AC: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    after_12:
    // 0x8005C2B0: b           L_8005C2F8
    // 0x8005C2B4: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
        goto L_8005C2F8;
    // 0x8005C2B4: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
L_8005C2B8:
    // 0x8005C2B8: or          $s3, $fp, $zero
    ctx->r19 = ctx->r30 | 0;
    // 0x8005C2BC: addiu       $s6, $sp, 0x9E
    ctx->r22 = ADD32(ctx->r29, 0X9E);
    // 0x8005C2C0: addiu       $s0, $sp, 0x8E
    ctx->r16 = ADD32(ctx->r29, 0X8E);
    // 0x8005C2C4: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x8005C2C8: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x8005C2CC: jal         0x8005BB24
    // 0x8005C2D0: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    func_8005BB24(rdram, ctx);
        goto after_13;
    // 0x8005C2D0: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    after_13:
    // 0x8005C2D4: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x8005C2D8: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    // 0x8005C2DC: lw          $v1, 0x3C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X3C);
    // 0x8005C2E0: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8005C2E4: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8005C2E8: lh          $a1, 0x8($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X8);
    // 0x8005C2EC: jalr        $t9
    // 0x8005C2F0: lw          $a2, 0xC($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XC);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_14;
    // 0x8005C2F0: lw          $a2, 0xC($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XC);
    after_14:
L_8005C2F4:
    // 0x8005C2F4: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
L_8005C2F8:
    // 0x8005C2F8: lh          $t6, 0x8E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X8E);
    // 0x8005C2FC: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x8005C300: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x8005C304: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x8005C308: sh          $t9, 0x8E($sp)
    MEM_H(0X8E, ctx->r29) = ctx->r25;
    // 0x8005C30C: subu        $t7, $t6, $t8
    ctx->r15 = SUB32(ctx->r14, ctx->r24);
    // 0x8005C310: sw          $t7, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r15;
    // 0x8005C314: lw          $a0, 0x3C($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X3C);
    // 0x8005C318: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005C31C: bne         $t9, $zero, L_8005C328
    if (ctx->r25 != 0) {
        // 0x8005C320: sw          $t9, 0x3C($fp)
        MEM_W(0X3C, ctx->r30) = ctx->r25;
            goto L_8005C328;
    }
    // 0x8005C320: sw          $t9, 0x3C($fp)
    MEM_W(0X3C, ctx->r30) = ctx->r25;
    // 0x8005C324: sw          $zero, 0x40($fp)
    MEM_W(0X40, ctx->r30) = 0;
L_8005C328:
    // 0x8005C328: jal         0x800538D8
    // 0x8005C32C: nop

    func_800538D8(rdram, ctx);
        goto after_15;
    // 0x8005C32C: nop

    after_15:
    // 0x8005C330: lw          $t8, 0xA0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA0);
    // 0x8005C334: lw          $t7, 0x3C($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X3C);
    // 0x8005C338: bnel        $t7, $zero, L_8005BEDC
    if (ctx->r15 != 0) {
        // 0x8005C33C: lw          $v1, 0x3C($fp)
        ctx->r3 = MEM_W(ctx->r30, 0X3C);
            goto L_8005BEDC;
    }
    goto skip_10;
    // 0x8005C33C: lw          $v1, 0x3C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X3C);
    skip_10:
L_8005C340:
    // 0x8005C340: or          $s3, $fp, $zero
    ctx->r19 = ctx->r30 | 0;
L_8005C344:
    // 0x8005C344: addiu       $s6, $sp, 0x9E
    ctx->r22 = ADD32(ctx->r29, 0X9E);
    // 0x8005C348: addiu       $s0, $sp, 0x8E
    ctx->r16 = ADD32(ctx->r29, 0X8E);
    // 0x8005C34C: lw          $s5, 0xB0($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XB0);
    // 0x8005C350: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x8005C354: jal         0x8005BB24
    // 0x8005C358: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    func_8005BB24(rdram, ctx);
        goto after_16;
    // 0x8005C358: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    after_16:
    // 0x8005C35C: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x8005C360: lw          $t9, 0x30($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X30);
    // 0x8005C364: lw          $a0, 0x34($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X34);
    // 0x8005C368: slt         $at, $a0, $t9
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8005C36C: beql        $at, $zero, L_8005C37C
    if (ctx->r1 == 0) {
        // 0x8005C370: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8005C37C;
    }
    goto skip_11;
    // 0x8005C370: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_11:
    // 0x8005C374: sw          $a0, 0x30($fp)
    MEM_W(0X30, ctx->r30) = ctx->r4;
    // 0x8005C378: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8005C37C:
    // 0x8005C37C: lw          $v0, 0xA4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA4);
    // 0x8005C380: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8005C384: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8005C388: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8005C38C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8005C390: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8005C394: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8005C398: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8005C39C: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8005C3A0: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8005C3A4: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8005C3A8: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8005C3AC: jr          $ra
    // 0x8005C3B0: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    TRACE_RETURN()
    return;
    // 0x8005C3B0: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_8005C3C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005C3C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005C3C4: bne         $a1, $at, L_8005C3E8
    if (ctx->r5 != ctx->r1) {
        // 0x8005C3C8: lw          $v0, 0x1C($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1C);
            goto L_8005C3E8;
    }
    // 0x8005C3C8: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x8005C3CC: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x8005C3D0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8005C3D4: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8005C3D8: sw          $a2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r6;
    // 0x8005C3DC: lw          $t9, 0x14($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14);
    // 0x8005C3E0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8005C3E4: sw          $t0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r8;
L_8005C3E8:
    // 0x8005C3E8: jr          $ra
    // 0x8005C3EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    TRACE_RETURN()
    return;
    // 0x8005C3EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_8005C3F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005C3F0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8005C3F4: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8005C3F8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8005C3FC: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8005C400: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8005C404: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8005C408: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8005C40C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8005C410: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8005C414: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005C418: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x8005C41C: lui         $t6, 0x200
    ctx->r14 = S32(0X200 << 16);
    // 0x8005C420: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x8005C424: lui         $t7, 0x200
    ctx->r15 = S32(0X200 << 16);
    // 0x8005C428: ori         $t6, $t6, 0x6C0
    ctx->r14 = ctx->r14 | 0X6C0;
    // 0x8005C42C: ori         $t7, $t7, 0x800
    ctx->r15 = ctx->r15 | 0X800;
    // 0x8005C430: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x8005C434: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    // 0x8005C438: sw          $t7, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r15;
    // 0x8005C43C: sw          $v0, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r2;
    // 0x8005C440: lw          $t8, 0x14($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14);
    // 0x8005C444: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x8005C448: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x8005C44C: or          $s6, $a3, $zero
    ctx->r22 = ctx->r7 | 0;
    // 0x8005C450: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8005C454: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8005C458: blez        $t8, L_8005C49C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8005C45C: addiu       $s2, $t0, 0x10
        ctx->r18 = ADD32(ctx->r8, 0X10);
            goto L_8005C49C;
    }
    // 0x8005C45C: addiu       $s2, $t0, 0x10
    ctx->r18 = ADD32(ctx->r8, 0X10);
    // 0x8005C460: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
L_8005C464:
    // 0x8005C464: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8005C468: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8005C46C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8005C470: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x8005C474: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x8005C478: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x8005C47C: jalr        $t9
    // 0x8005C480: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8005C480: nop

    after_0:
    // 0x8005C484: lw          $t1, 0x14($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X14);
    // 0x8005C488: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8005C48C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8005C490: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8005C494: bne         $at, $zero, L_8005C464
    if (ctx->r1 != 0) {
        // 0x8005C498: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_8005C464;
    }
    // 0x8005C498: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_8005C49C:
    // 0x8005C49C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8005C4A0: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x8005C4A4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8005C4A8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005C4AC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8005C4B0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8005C4B4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8005C4B8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8005C4BC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8005C4C0: jr          $ra
    // 0x8005C4C4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    TRACE_RETURN()
    return;
    // 0x8005C4C4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8005C4D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005C4D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005C4D4: beq         $a1, $at, L_8005C4F0
    if (ctx->r5 == ctx->r1) {
        // 0x8005C4D8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8005C4F0;
    }
    // 0x8005C4D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005C4DC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8005C4E0: beql        $a1, $at, L_8005C4FC
    if (ctx->r5 == ctx->r1) {
        // 0x8005C4E4: sw          $a2, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->r6;
            goto L_8005C4FC;
    }
    goto skip_0;
    // 0x8005C4E4: sw          $a2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r6;
    skip_0:
    // 0x8005C4E8: jr          $ra
    // 0x8005C4EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    TRACE_RETURN()
    return;
    // 0x8005C4EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005C4F0:
    // 0x8005C4F0: jr          $ra
    // 0x8005C4F4: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    TRACE_RETURN()
    return;
    // 0x8005C4F4: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x8005C4F8: sw          $a2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r6;
L_8005C4FC:
    // 0x8005C4FC: jr          $ra
    // 0x8005C500: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    TRACE_RETURN()
    return;
    // 0x8005C500: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_8005C504(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005C504: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005C508: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005C50C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8005C510: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x8005C514: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8005C518: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8005C51C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8005C520: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x8005C524: jalr        $t9
    // 0x8005C528: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8005C528: nop

    after_0:
    // 0x8005C52C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8005C530: lui         $v1, 0x800
    ctx->r3 = S32(0X800 << 16);
    // 0x8005C534: lui         $t2, 0x440
    ctx->r10 = S32(0X440 << 16);
    // 0x8005C538: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x8005C53C: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    // 0x8005C540: andi        $t0, $t8, 0xFFFF
    ctx->r8 = ctx->r24 & 0XFFFF;
    // 0x8005C544: ori         $t2, $t2, 0x580
    ctx->r10 = ctx->r10 | 0X580;
    // 0x8005C548: lui         $t1, 0xD00
    ctx->r9 = S32(0XD00 << 16);
    // 0x8005C54C: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x8005C550: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x8005C554: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8005C558: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8005C55C: sw          $t1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r9;
    // 0x8005C560: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x8005C564: sw          $t4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r12;
    // 0x8005C568: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x8005C56C: sw          $t5, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r13;
    // 0x8005C570: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8005C574: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x8005C578: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x8005C57C: sw          $t7, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r15;
    // 0x8005C580: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005C584: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005C588: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005C6E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005C6E0: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x8005C6E4: lw          $t6, 0x3200($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3200);
    // 0x8005C6E8: bne         $t6, $zero, L_8005C6F8
    if (ctx->r14 != 0) {
        // 0x8005C6EC: nop
    
            goto L_8005C6F8;
    }
    // 0x8005C6EC: nop

    // 0x8005C6F0: jr          $ra
    // 0x8005C6F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    TRACE_RETURN()
    return;
    // 0x8005C6F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005C6F8:
    // 0x8005C6F8: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x8005C6FC: lw          $v0, 0x3208($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3208);
    // 0x8005C700: jr          $ra
    // 0x8005C704: nop

    TRACE_RETURN()
    return;
    // 0x8005C704: nop

    // 0x8005C708: nop

    // 0x8005C70C: nop

    // 0x8005C710: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8005C714: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005C718: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8005C71C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8005C720: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8005C724: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x8005C728: sb          $zero, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = 0;
    // 0x8005C72C: jal         0x8005CAD0
    // 0x8005C730: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_8005CAD0(rdram, ctx);
        goto after_0;
    // 0x8005C730: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
L_8005C734:
    // 0x8005C734: jal         0x8005C8B0
    // 0x8005C738: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8005C8B0(rdram, ctx);
        goto after_1;
    // 0x8005C738: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8005C73C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8005C740: addiu       $a1, $a1, -0x2170
    ctx->r5 = ADD32(ctx->r5, -0X2170);
    // 0x8005C744: jal         0x8005CB40
    // 0x8005C748: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8005CB40(rdram, ctx);
        goto after_2;
    // 0x8005C748: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x8005C74C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8005C750: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8005C754: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8005C758: jal         0x8004F990
    // 0x8005C75C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x8005C75C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x8005C760: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8005C764: addiu       $a1, $a1, -0x2170
    ctx->r5 = ADD32(ctx->r5, -0X2170);
    // 0x8005C768: jal         0x8005CB40
    // 0x8005C76C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8005CB40(rdram, ctx);
        goto after_4;
    // 0x8005C76C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x8005C770: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8005C774: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8005C778: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8005C77C: jal         0x8004F990
    // 0x8005C780: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x8005C780: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x8005C784: addiu       $a0, $sp, 0x37
    ctx->r4 = ADD32(ctx->r29, 0X37);
    // 0x8005C788: jal         0x8005C9AC
    // 0x8005C78C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8005C9AC(rdram, ctx);
        goto after_6;
    // 0x8005C78C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_6:
    // 0x8005C790: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8005C794: lbu         $t7, -0x463F($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X463F);
    // 0x8005C798: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8005C79C: blez        $t7, L_8005C7F0
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8005C7A0: nop
    
            goto L_8005C7F0;
    }
    // 0x8005C7A0: nop

L_8005C7A4:
    // 0x8005C7A4: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8005C7A8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8005C7AC: addu        $t0, $sp, $t9
    ctx->r8 = ADD32(ctx->r29, ctx->r25);
    // 0x8005C7B0: lbu         $t0, 0x26($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X26);
    // 0x8005C7B4: andi        $t1, $t0, 0x4
    ctx->r9 = ctx->r8 & 0X4;
    // 0x8005C7B8: bne         $t1, $zero, L_8005C7D0
    if (ctx->r9 != 0) {
        // 0x8005C7BC: nop
    
            goto L_8005C7D0;
    }
    // 0x8005C7BC: nop

    // 0x8005C7C0: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8005C7C4: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8005C7C8: b           L_8005C7F0
    // 0x8005C7CC: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
        goto L_8005C7F0;
    // 0x8005C7CC: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
L_8005C7D0:
    // 0x8005C7D0: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8005C7D4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8005C7D8: lbu         $t6, -0x463F($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X463F);
    // 0x8005C7DC: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8005C7E0: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x8005C7E4: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8005C7E8: bne         $at, $zero, L_8005C7A4
    if (ctx->r1 != 0) {
        // 0x8005C7EC: nop
    
            goto L_8005C7A4;
    }
    // 0x8005C7EC: nop

L_8005C7F0:
    // 0x8005C7F0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8005C7F4: lbu         $t7, -0x463F($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X463F);
    // 0x8005C7F8: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8005C7FC: bne         $t7, $t8, L_8005C808
    if (ctx->r15 != ctx->r24) {
        // 0x8005C800: nop
    
            goto L_8005C808;
    }
    // 0x8005C800: nop

    // 0x8005C804: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_8005C808:
    // 0x8005C808: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8005C80C: bgtz        $t9, L_8005C734
    if (SIGNED(ctx->r25) > 0) {
        // 0x8005C810: nop
    
            goto L_8005C734;
    }
    // 0x8005C810: nop

    // 0x8005C814: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8005C818: lbu         $t0, -0x463F($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X463F);
    // 0x8005C81C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8005C820: blez        $t0, L_8005C888
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8005C824: nop
    
            goto L_8005C888;
    }
    // 0x8005C824: nop

L_8005C828:
    // 0x8005C828: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8005C82C: addiu       $t3, $sp, 0x24
    ctx->r11 = ADD32(ctx->r29, 0X24);
    // 0x8005C830: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8005C834: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8005C838: lbu         $t5, 0x3($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X3);
    // 0x8005C83C: bne         $t5, $zero, L_8005C868
    if (ctx->r13 != 0) {
        // 0x8005C840: nop
    
            goto L_8005C868;
    }
    // 0x8005C840: nop

    // 0x8005C844: lbu         $t6, 0x2($t4)
    ctx->r14 = MEM_BU(ctx->r12, 0X2);
    // 0x8005C848: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8005C84C: beq         $t7, $zero, L_8005C868
    if (ctx->r15 == 0) {
        // 0x8005C850: nop
    
            goto L_8005C868;
    }
    // 0x8005C850: nop

    // 0x8005C854: lbu         $t8, 0x1F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X1F);
    // 0x8005C858: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8005C85C: sllv        $t0, $t9, $t1
    ctx->r8 = S32(ctx->r25 << (ctx->r9 & 31));
    // 0x8005C860: or          $t2, $t8, $t0
    ctx->r10 = ctx->r24 | ctx->r8;
    // 0x8005C864: sb          $t2, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r10;
L_8005C868:
    // 0x8005C868: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8005C86C: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x8005C870: lbu         $t4, -0x463F($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X463F);
    // 0x8005C874: addiu       $t5, $t3, 0x1
    ctx->r13 = ADD32(ctx->r11, 0X1);
    // 0x8005C878: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x8005C87C: slt         $at, $t5, $t4
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8005C880: bne         $at, $zero, L_8005C828
    if (ctx->r1 != 0) {
        // 0x8005C884: nop
    
            goto L_8005C828;
    }
    // 0x8005C884: nop

L_8005C888:
    // 0x8005C888: jal         0x8005CB14
    // 0x8005C88C: nop

    func_8005CB14(rdram, ctx);
        goto after_7;
    // 0x8005C88C: nop

    after_7:
    // 0x8005C890: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8005C894: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8005C898: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x8005C89C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005C8A0: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8005C8A4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8005C8A8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005C8B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005C8B0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8005C8B4: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8005C8B8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8005C8BC: sb          $a0, -0x4640($at)
    MEM_B(-0X4640, ctx->r1) = ctx->r4;
    // 0x8005C8C0: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_8005C8C4:
    // 0x8005C8C4: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x8005C8C8: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x8005C8CC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8005C8D0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8005C8D4: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8005C8D8: sw          $zero, -0x2170($at)
    MEM_W(-0X2170, ctx->r1) = 0;
    // 0x8005C8DC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8005C8E0: slti        $at, $t9, 0x10
    ctx->r1 = SIGNED(ctx->r25) < 0X10 ? 1 : 0;
    // 0x8005C8E4: bne         $at, $zero, L_8005C8C4
    if (ctx->r1 != 0) {
        // 0x8005C8E8: sw          $t9, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r25;
            goto L_8005C8C4;
    }
    // 0x8005C8E8: sw          $t9, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r25;
    // 0x8005C8EC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8005C8F0: lbu         $t9, -0x463F($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X463F);
    // 0x8005C8F4: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8005C8F8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8005C8FC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8005C900: addiu       $t1, $t1, -0x2170
    ctx->r9 = ADD32(ctx->r9, -0X2170);
    // 0x8005C904: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8005C908: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005C90C: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8005C910: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8005C914: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8005C918: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8005C91C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8005C920: sw          $t0, -0x2134($at)
    MEM_W(-0X2134, ctx->r1) = ctx->r8;
    // 0x8005C924: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x8005C928: sb          $t2, 0x4($sp)
    MEM_B(0X4, ctx->r29) = ctx->r10;
    // 0x8005C92C: sb          $t3, 0x5($sp)
    MEM_B(0X5, ctx->r29) = ctx->r11;
    // 0x8005C930: sb          $t4, 0x6($sp)
    MEM_B(0X6, ctx->r29) = ctx->r12;
    // 0x8005C934: sb          $a0, 0x7($sp)
    MEM_B(0X7, ctx->r29) = ctx->r4;
    // 0x8005C938: sb          $t5, 0x8($sp)
    MEM_B(0X8, ctx->r29) = ctx->r13;
    // 0x8005C93C: sb          $t6, 0x9($sp)
    MEM_B(0X9, ctx->r29) = ctx->r14;
    // 0x8005C940: sb          $t7, 0xA($sp)
    MEM_B(0XA, ctx->r29) = ctx->r15;
    // 0x8005C944: sb          $t8, 0xB($sp)
    MEM_B(0XB, ctx->r29) = ctx->r24;
    // 0x8005C948: blez        $t9, L_8005C998
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8005C94C: sw          $zero, 0x0($sp)
        MEM_W(0X0, ctx->r29) = 0;
            goto L_8005C998;
    }
    // 0x8005C94C: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_8005C950:
    // 0x8005C950: addiu       $t1, $sp, 0x4
    ctx->r9 = ADD32(ctx->r29, 0X4);
    // 0x8005C954: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x8005C958: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x8005C95C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8005C960: swl         $at, 0x0($t0)
    do_swl(rdram, 0X0, ctx->r8, ctx->r1);
    // 0x8005C964: swr         $at, 0x3($t0)
    do_swr(rdram, 0X3, ctx->r8, ctx->r1);
    // 0x8005C968: lw          $t3, 0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X4);
    // 0x8005C96C: swl         $t3, 0x4($t0)
    do_swl(rdram, 0X4, ctx->r8, ctx->r11);
    // 0x8005C970: swr         $t3, 0x7($t0)
    do_swr(rdram, 0X7, ctx->r8, ctx->r11);
    // 0x8005C974: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x8005C978: lbu         $t8, -0x463F($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X463F);
    // 0x8005C97C: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x8005C980: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8005C984: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8005C988: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8005C98C: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x8005C990: bne         $at, $zero, L_8005C950
    if (ctx->r1 != 0) {
        // 0x8005C994: sw          $t5, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r13;
            goto L_8005C950;
    }
    // 0x8005C994: sw          $t5, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r13;
L_8005C998:
    // 0x8005C998: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x8005C99C: addiu       $t9, $zero, 0xFE
    ctx->r25 = ADD32(0, 0XFE);
    // 0x8005C9A0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x8005C9A4: jr          $ra
    // 0x8005C9A8: sb          $t9, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r25;
    TRACE_RETURN()
    return;
    // 0x8005C9A8: sb          $t9, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r25;
;}
RECOMP_FUNC void func_8005C9AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005C9AC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8005C9B0: lbu         $t7, -0x463F($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X463F);
    // 0x8005C9B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005C9B8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8005C9BC: addiu       $t6, $t6, -0x2170
    ctx->r14 = ADD32(ctx->r14, -0X2170);
    // 0x8005C9C0: sb          $zero, 0x7($sp)
    MEM_B(0X7, ctx->r29) = 0;
    // 0x8005C9C4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8005C9C8: blez        $t7, L_8005CA6C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8005C9CC: sw          $zero, 0x8($sp)
        MEM_W(0X8, ctx->r29) = 0;
            goto L_8005CA6C;
    }
    // 0x8005C9CC: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
L_8005C9D0:
    // 0x8005C9D0: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x8005C9D4: addiu       $t8, $sp, 0xC
    ctx->r24 = ADD32(ctx->r29, 0XC);
    // 0x8005C9D8: lwl         $at, 0x0($t9)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r25, 0X0);
    // 0x8005C9DC: lwr         $at, 0x3($t9)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r25, 0X3);
    // 0x8005C9E0: sw          $at, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r1;
    // 0x8005C9E4: lwl         $t1, 0x4($t9)
    ctx->r9 = do_lwl(rdram, ctx->r9, ctx->r25, 0X4);
    // 0x8005C9E8: lwr         $t1, 0x7($t9)
    ctx->r9 = do_lwr(rdram, ctx->r9, ctx->r25, 0X7);
    // 0x8005C9EC: sw          $t1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r9;
    // 0x8005C9F0: lbu         $t2, 0xE($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0XE);
    // 0x8005C9F4: andi        $t3, $t2, 0xC0
    ctx->r11 = ctx->r10 & 0XC0;
    // 0x8005C9F8: sra         $t4, $t3, 4
    ctx->r12 = S32(SIGNED(ctx->r11) >> 4);
    // 0x8005C9FC: sb          $t4, 0x3($a1)
    MEM_B(0X3, ctx->r5) = ctx->r12;
    // 0x8005CA00: lbu         $t5, 0x3($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X3);
    // 0x8005CA04: bne         $t5, $zero, L_8005CA40
    if (ctx->r13 != 0) {
        // 0x8005CA08: nop
    
            goto L_8005CA40;
    }
    // 0x8005CA08: nop

    // 0x8005CA0C: lbu         $t6, 0x11($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X11);
    // 0x8005CA10: lbu         $t0, 0x10($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X10);
    // 0x8005CA14: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005CA18: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x8005CA1C: or          $t8, $t7, $t0
    ctx->r24 = ctx->r15 | ctx->r8;
    // 0x8005CA20: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x8005CA24: lbu         $t9, 0x12($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X12);
    // 0x8005CA28: sb          $t9, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r25;
    // 0x8005CA2C: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x8005CA30: lbu         $t1, 0x7($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X7);
    // 0x8005CA34: sllv        $t4, $t3, $t2
    ctx->r12 = S32(ctx->r11 << (ctx->r10 & 31));
    // 0x8005CA38: or          $t5, $t1, $t4
    ctx->r13 = ctx->r9 | ctx->r12;
    // 0x8005CA3C: sb          $t5, 0x7($sp)
    MEM_B(0X7, ctx->r29) = ctx->r13;
L_8005CA40:
    // 0x8005CA40: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x8005CA44: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8005CA48: lbu         $t9, -0x463F($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X463F);
    // 0x8005CA4C: lw          $t0, 0x14($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14);
    // 0x8005CA50: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8005CA54: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8005CA58: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x8005CA5C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8005CA60: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x8005CA64: bne         $at, $zero, L_8005C9D0
    if (ctx->r1 != 0) {
        // 0x8005CA68: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8005C9D0;
    }
    // 0x8005CA68: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_8005CA6C:
    // 0x8005CA6C: lbu         $t3, 0x7($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X7);
    // 0x8005CA70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005CA74: jr          $ra
    // 0x8005CA78: sb          $t3, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r11;
    TRACE_RETURN()
    return;
    // 0x8005CA78: sb          $t3, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r11;
;}
RECOMP_FUNC void func_8005CA80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005CA80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005CA84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005CA88: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005CA8C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8005CA90: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005CA94: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8005CA98: sw          $t6, 0x4750($at)
    MEM_W(0X4750, ctx->r1) = ctx->r14;
    // 0x8005CA9C: addiu       $a1, $a1, -0x2130
    ctx->r5 = ADD32(ctx->r5, -0X2130);
    // 0x8005CAA0: addiu       $a0, $a0, -0x2128
    ctx->r4 = ADD32(ctx->r4, -0X2128);
    // 0x8005CAA4: jal         0x80052780
    // 0x8005CAA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x8005CAA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8005CAAC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005CAB0: addiu       $a0, $a0, -0x2128
    ctx->r4 = ADD32(ctx->r4, -0X2128);
    // 0x8005CAB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CAB8: jal         0x800534A0
    // 0x8005CABC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8005CABC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8005CAC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005CAC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005CAC8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005CAD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005CAD0: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x8005CAD4: lw          $t6, 0x4750($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4750);
    // 0x8005CAD8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005CADC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005CAE0: bne         $t6, $zero, L_8005CAF0
    if (ctx->r14 != 0) {
        // 0x8005CAE4: nop
    
            goto L_8005CAF0;
    }
    // 0x8005CAE4: nop

    // 0x8005CAE8: jal         0x8005CA80
    // 0x8005CAEC: nop

    func_8005CA80(rdram, ctx);
        goto after_0;
    // 0x8005CAEC: nop

    after_0:
L_8005CAF0:
    // 0x8005CAF0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005CAF4: addiu       $a0, $a0, -0x2128
    ctx->r4 = ADD32(ctx->r4, -0X2128);
    // 0x8005CAF8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8005CAFC: jal         0x8004F990
    // 0x8005CB00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8005CB00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8005CB04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005CB08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005CB0C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005CB14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005CB14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005CB18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005CB1C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005CB20: addiu       $a0, $a0, -0x2128
    ctx->r4 = ADD32(ctx->r4, -0X2128);
    // 0x8005CB24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CB28: jal         0x800534A0
    // 0x8005CB2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8005CB2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8005CB30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005CB34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005CB38: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005CB40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005CB40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005CB44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005CB48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8005CB4C: jal         0x800629A0
    // 0x8005CB50: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800629A0(rdram, ctx);
        goto after_0;
    // 0x8005CB50: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8005CB54: beq         $v0, $zero, L_8005CB64
    if (ctx->r2 == 0) {
        // 0x8005CB58: nop
    
            goto L_8005CB64;
    }
    // 0x8005CB58: nop

    // 0x8005CB5C: b           L_8005CBDC
    // 0x8005CB60: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8005CBDC;
    // 0x8005CB60: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8005CB64:
    // 0x8005CB64: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8005CB68: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005CB6C: bne         $t6, $at, L_8005CB80
    if (ctx->r14 != ctx->r1) {
        // 0x8005CB70: nop
    
            goto L_8005CB80;
    }
    // 0x8005CB70: nop

    // 0x8005CB74: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8005CB78: jal         0x8005F430
    // 0x8005CB7C: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_8005F430(rdram, ctx);
        goto after_1;
    // 0x8005CB7C: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_1:
L_8005CB80:
    // 0x8005CB80: jal         0x80053750
    // 0x8005CB84: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x8005CB84: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x8005CB88: lui         $t7, 0xA480
    ctx->r15 = S32(0XA480 << 16);
    // 0x8005CB8C: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x8005CB90: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8005CB94: bne         $t8, $zero, L_8005CBB0
    if (ctx->r24 != 0) {
        // 0x8005CB98: nop
    
            goto L_8005CBB0;
    }
    // 0x8005CB98: nop

    // 0x8005CB9C: lui         $t9, 0x1FC0
    ctx->r25 = S32(0X1FC0 << 16);
    // 0x8005CBA0: ori         $t9, $t9, 0x7C0
    ctx->r25 = ctx->r25 | 0X7C0;
    // 0x8005CBA4: lui         $t0, 0xA480
    ctx->r8 = S32(0XA480 << 16);
    // 0x8005CBA8: b           L_8005CBC0
    // 0x8005CBAC: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
        goto L_8005CBC0;
    // 0x8005CBAC: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
L_8005CBB0:
    // 0x8005CBB0: lui         $t1, 0x1FC0
    ctx->r9 = S32(0X1FC0 << 16);
    // 0x8005CBB4: ori         $t1, $t1, 0x7C0
    ctx->r9 = ctx->r9 | 0X7C0;
    // 0x8005CBB8: lui         $t2, 0xA480
    ctx->r10 = S32(0XA480 << 16);
    // 0x8005CBBC: sw          $t1, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->r9;
L_8005CBC0:
    // 0x8005CBC0: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8005CBC4: bne         $t3, $zero, L_8005CBD8
    if (ctx->r11 != 0) {
        // 0x8005CBC8: nop
    
            goto L_8005CBD8;
    }
    // 0x8005CBC8: nop

    // 0x8005CBCC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8005CBD0: jal         0x80056440
    // 0x8005CBD4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    osInvalDCache_recomp(rdram, ctx);
        goto after_3;
    // 0x8005CBD4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_3:
L_8005CBD8:
    // 0x8005CBD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005CBDC:
    // 0x8005CBDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005CBE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005CBE4: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005CBF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005CBF0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8005CBF4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8005CBF8: sb          $zero, 0xF($sp)
    MEM_B(0XF, ctx->r29) = 0;
    // 0x8005CBFC: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
L_8005CC00:
    // 0x8005CC00: lbu         $t6, 0xF($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XF);
    // 0x8005CC04: andi        $t7, $t6, 0x10
    ctx->r15 = ctx->r14 & 0X10;
    // 0x8005CC08: beq         $t7, $zero, L_8005CC1C
    if (ctx->r15 == 0) {
        // 0x8005CC0C: nop
    
            goto L_8005CC1C;
    }
    // 0x8005CC0C: nop

    // 0x8005CC10: addiu       $t8, $zero, 0x15
    ctx->r24 = ADD32(0, 0X15);
    // 0x8005CC14: b           L_8005CC20
    // 0x8005CC18: sb          $t8, 0xE($sp)
    MEM_B(0XE, ctx->r29) = ctx->r24;
        goto L_8005CC20;
    // 0x8005CC18: sb          $t8, 0xE($sp)
    MEM_B(0XE, ctx->r29) = ctx->r24;
L_8005CC1C:
    // 0x8005CC1C: sb          $zero, 0xE($sp)
    MEM_B(0XE, ctx->r29) = 0;
L_8005CC20:
    // 0x8005CC20: lbu         $t9, 0xF($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0XF);
    // 0x8005CC24: andi        $t1, $a0, 0x400
    ctx->r9 = ctx->r4 & 0X400;
    // 0x8005CC28: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8005CC2C: beq         $t1, $zero, L_8005CC3C
    if (ctx->r9 == 0) {
        // 0x8005CC30: sb          $t0, 0xF($sp)
        MEM_B(0XF, ctx->r29) = ctx->r8;
            goto L_8005CC3C;
    }
    // 0x8005CC30: sb          $t0, 0xF($sp)
    MEM_B(0XF, ctx->r29) = ctx->r8;
    // 0x8005CC34: b           L_8005CC40
    // 0x8005CC38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8005CC40;
    // 0x8005CC38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8005CC3C:
    // 0x8005CC3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8005CC40:
    // 0x8005CC40: lbu         $t2, 0xF($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0XF);
    // 0x8005CC44: lw          $t0, 0x8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8);
    // 0x8005CC48: lbu         $t7, 0xE($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XE);
    // 0x8005CC4C: andi        $t3, $a1, 0xFF
    ctx->r11 = ctx->r5 & 0XFF;
    // 0x8005CC50: sll         $t5, $a0, 1
    ctx->r13 = S32(ctx->r4 << 1);
    // 0x8005CC54: or          $t4, $t2, $t3
    ctx->r12 = ctx->r10 | ctx->r11;
    // 0x8005CC58: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x8005CC5C: andi        $t8, $t4, 0xFF
    ctx->r24 = ctx->r12 & 0XFF;
    // 0x8005CC60: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8005CC64: slti        $at, $t1, 0x10
    ctx->r1 = SIGNED(ctx->r9) < 0X10 ? 1 : 0;
    // 0x8005CC68: sb          $t4, 0xF($sp)
    MEM_B(0XF, ctx->r29) = ctx->r12;
    // 0x8005CC6C: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x8005CC70: xor         $t9, $t8, $t7
    ctx->r25 = ctx->r24 ^ ctx->r15;
    // 0x8005CC74: sw          $t1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r9;
    // 0x8005CC78: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8005CC7C: bne         $at, $zero, L_8005CC00
    if (ctx->r1 != 0) {
        // 0x8005CC80: sb          $t9, 0xF($sp)
        MEM_B(0XF, ctx->r29) = ctx->r25;
            goto L_8005CC00;
    }
    // 0x8005CC80: sb          $t9, 0xF($sp)
    MEM_B(0XF, ctx->r29) = ctx->r25;
    // 0x8005CC84: lbu         $v0, 0xF($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0XF);
    // 0x8005CC88: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x8005CC8C: andi        $t2, $v0, 0x1F
    ctx->r10 = ctx->r2 & 0X1F;
    // 0x8005CC90: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8005CC94: andi        $t3, $v0, 0xFF
    ctx->r11 = ctx->r2 & 0XFF;
    // 0x8005CC98: jr          $ra
    // 0x8005CC9C: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    TRACE_RETURN()
    return;
    // 0x8005CC9C: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
;}
RECOMP_FUNC void func_8005CCA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005CCA0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8005CCA4: sb          $zero, 0xF($sp)
    MEM_B(0XF, ctx->r29) = 0;
    // 0x8005CCA8: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
L_8005CCAC:
    // 0x8005CCAC: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x8005CCB0: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
L_8005CCB4:
    // 0x8005CCB4: lbu         $t7, 0xF($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XF);
    // 0x8005CCB8: andi        $t8, $t7, 0x80
    ctx->r24 = ctx->r15 & 0X80;
    // 0x8005CCBC: beq         $t8, $zero, L_8005CCD0
    if (ctx->r24 == 0) {
        // 0x8005CCC0: nop
    
            goto L_8005CCD0;
    }
    // 0x8005CCC0: nop

    // 0x8005CCC4: addiu       $t9, $zero, 0x85
    ctx->r25 = ADD32(0, 0X85);
    // 0x8005CCC8: b           L_8005CCD4
    // 0x8005CCCC: sb          $t9, 0xE($sp)
    MEM_B(0XE, ctx->r29) = ctx->r25;
        goto L_8005CCD4;
    // 0x8005CCCC: sb          $t9, 0xE($sp)
    MEM_B(0XE, ctx->r29) = ctx->r25;
L_8005CCD0:
    // 0x8005CCD0: sb          $zero, 0xE($sp)
    MEM_B(0XE, ctx->r29) = 0;
L_8005CCD4:
    // 0x8005CCD4: lbu         $t0, 0xF($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0XF);
    // 0x8005CCD8: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x8005CCDC: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x8005CCE0: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8005CCE4: bne         $t2, $at, L_8005CCF8
    if (ctx->r10 != ctx->r1) {
        // 0x8005CCE8: sb          $t1, 0xF($sp)
        MEM_B(0XF, ctx->r29) = ctx->r9;
            goto L_8005CCF8;
    }
    // 0x8005CCE8: sb          $t1, 0xF($sp)
    MEM_B(0XF, ctx->r29) = ctx->r9;
    // 0x8005CCEC: andi        $t3, $t1, 0xFF
    ctx->r11 = ctx->r9 & 0XFF;
    // 0x8005CCF0: b           L_8005CD2C
    // 0x8005CCF4: sb          $t3, 0xF($sp)
    MEM_B(0XF, ctx->r29) = ctx->r11;
        goto L_8005CD2C;
    // 0x8005CCF4: sb          $t3, 0xF($sp)
    MEM_B(0XF, ctx->r29) = ctx->r11;
L_8005CCF8:
    // 0x8005CCF8: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8005CCFC: lbu         $t4, 0x0($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X0);
    // 0x8005CD00: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005CD04: sllv        $t7, $t6, $t5
    ctx->r15 = S32(ctx->r14 << (ctx->r13 & 31));
    // 0x8005CD08: and         $t8, $t4, $t7
    ctx->r24 = ctx->r12 & ctx->r15;
    // 0x8005CD0C: beq         $t8, $zero, L_8005CD1C
    if (ctx->r24 == 0) {
        // 0x8005CD10: nop
    
            goto L_8005CD1C;
    }
    // 0x8005CD10: nop

    // 0x8005CD14: b           L_8005CD20
    // 0x8005CD18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8005CD20;
    // 0x8005CD18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8005CD1C:
    // 0x8005CD1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8005CD20:
    // 0x8005CD20: lbu         $t9, 0xF($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0XF);
    // 0x8005CD24: or          $t0, $t9, $a1
    ctx->r8 = ctx->r25 | ctx->r5;
    // 0x8005CD28: sb          $t0, 0xF($sp)
    MEM_B(0XF, ctx->r29) = ctx->r8;
L_8005CD2C:
    // 0x8005CD2C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8005CD30: lbu         $t2, 0xF($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0XF);
    // 0x8005CD34: lbu         $t1, 0xE($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0XE);
    // 0x8005CD38: addiu       $t5, $t6, -0x1
    ctx->r13 = ADD32(ctx->r14, -0X1);
    // 0x8005CD3C: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x8005CD40: xor         $t3, $t2, $t1
    ctx->r11 = ctx->r10 ^ ctx->r9;
    // 0x8005CD44: bgez        $t5, L_8005CCB4
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8005CD48: sb          $t3, 0xF($sp)
        MEM_B(0XF, ctx->r29) = ctx->r11;
            goto L_8005CCB4;
    }
    // 0x8005CD48: sb          $t3, 0xF($sp)
    MEM_B(0XF, ctx->r29) = ctx->r11;
    // 0x8005CD4C: lw          $t4, 0x8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8);
    // 0x8005CD50: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8005CD54: addiu       $t7, $t4, 0x1
    ctx->r15 = ADD32(ctx->r12, 0X1);
    // 0x8005CD58: slti        $at, $t7, 0x21
    ctx->r1 = SIGNED(ctx->r15) < 0X21 ? 1 : 0;
    // 0x8005CD5C: bne         $at, $zero, L_8005CCAC
    if (ctx->r1 != 0) {
        // 0x8005CD60: sw          $t7, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r15;
            goto L_8005CCAC;
    }
    // 0x8005CD60: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x8005CD64: lbu         $v0, 0xF($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0XF);
    // 0x8005CD68: jr          $ra
    // 0x8005CD6C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    TRACE_RETURN()
    return;
    // 0x8005CD6C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8005CD70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005CD70: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8005CD74: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x8005CD78: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8005CD7C: addiu       $t6, $t6, -0x2170
    ctx->r14 = ADD32(ctx->r14, -0X2170);
    // 0x8005CD80: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8005CD84: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005CD88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005CD8C: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8005CD90: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8005CD94: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x8005CD98: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x8005CD9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005CDA0: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    // 0x8005CDA4: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x8005CDA8: beq         $t8, $at, L_8005CDD0
    if (ctx->r24 == ctx->r1) {
        // 0x8005CDAC: sw          $t7, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r15;
            goto L_8005CDD0;
    }
    // 0x8005CDAC: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8005CDB0: lhu         $t9, 0x6A($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X6A);
    // 0x8005CDB4: slti        $at, $t9, 0x7
    ctx->r1 = SIGNED(ctx->r25) < 0X7 ? 1 : 0;
    // 0x8005CDB8: beq         $at, $zero, L_8005CDD0
    if (ctx->r1 == 0) {
        // 0x8005CDBC: nop
    
            goto L_8005CDD0;
    }
    // 0x8005CDBC: nop

    // 0x8005CDC0: beq         $t9, $zero, L_8005CDD0
    if (ctx->r25 == 0) {
        // 0x8005CDC4: nop
    
            goto L_8005CDD0;
    }
    // 0x8005CDC4: nop

    // 0x8005CDC8: b           L_8005CF60
    // 0x8005CDCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005CF60;
    // 0x8005CDCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005CDD0:
    // 0x8005CDD0: jal         0x8005CAD0
    // 0x8005CDD4: nop

    func_8005CAD0(rdram, ctx);
        goto after_0;
    // 0x8005CDD4: nop

    after_0:
    // 0x8005CDD8: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8005CDDC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8005CDE0: sb          $t0, -0x4640($at)
    MEM_B(-0X4640, ctx->r1) = ctx->r8;
    // 0x8005CDE4: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8005CDE8: lhu         $a1, 0x6A($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X6A);
    // 0x8005CDEC: jal         0x8005CF74
    // 0x8005CDF0: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    func_8005CF74(rdram, ctx);
        goto after_1;
    // 0x8005CDF0: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    after_1:
    // 0x8005CDF4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8005CDF8: addiu       $a1, $a1, -0x2170
    ctx->r5 = ADD32(ctx->r5, -0X2170);
    // 0x8005CDFC: jal         0x8005CB40
    // 0x8005CE00: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8005CB40(rdram, ctx);
        goto after_2;
    // 0x8005CE00: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x8005CE04: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x8005CE08: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8005CE0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CE10: jal         0x8004F990
    // 0x8005CE14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x8005CE14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
L_8005CE18:
    // 0x8005CE18: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8005CE1C: addiu       $a1, $a1, -0x2170
    ctx->r5 = ADD32(ctx->r5, -0X2170);
    // 0x8005CE20: jal         0x8005CB40
    // 0x8005CE24: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8005CB40(rdram, ctx);
        goto after_4;
    // 0x8005CE24: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x8005CE28: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x8005CE2C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8005CE30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CE34: jal         0x8004F990
    // 0x8005CE38: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x8005CE38: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x8005CE3C: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x8005CE40: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8005CE44: addiu       $t1, $t1, -0x2170
    ctx->r9 = ADD32(ctx->r9, -0X2170);
    // 0x8005CE48: beq         $t2, $zero, L_8005CE7C
    if (ctx->r10 == 0) {
        // 0x8005CE4C: sw          $t1, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r9;
            goto L_8005CE7C;
    }
    // 0x8005CE4C: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    // 0x8005CE50: blez        $t2, L_8005CE7C
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8005CE54: sw          $zero, 0x58($sp)
        MEM_W(0X58, ctx->r29) = 0;
            goto L_8005CE7C;
    }
    // 0x8005CE54: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
L_8005CE58:
    // 0x8005CE58: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x8005CE5C: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x8005CE60: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x8005CE64: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8005CE68: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8005CE6C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005CE70: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
    // 0x8005CE74: bne         $at, $zero, L_8005CE58
    if (ctx->r1 != 0) {
        // 0x8005CE78: sw          $t4, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r12;
            goto L_8005CE58;
    }
    // 0x8005CE78: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
L_8005CE7C:
    // 0x8005CE7C: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8005CE80: addiu       $t8, $sp, 0x2C
    ctx->r24 = ADD32(ctx->r29, 0X2C);
    // 0x8005CE84: addiu       $t1, $t9, 0x24
    ctx->r9 = ADD32(ctx->r25, 0X24);
L_8005CE88:
    // 0x8005CE88: lwl         $at, 0x0($t9)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r25, 0X0);
    // 0x8005CE8C: lwr         $at, 0x3($t9)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r25, 0X3);
    // 0x8005CE90: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8005CE94: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x8005CE98: sw          $at, -0xC($t8)
    MEM_W(-0XC, ctx->r24) = ctx->r1;
    // 0x8005CE9C: lwl         $at, -0x8($t9)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r25, -0X8);
    // 0x8005CEA0: lwr         $at, -0x5($t9)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r25, -0X5);
    // 0x8005CEA4: sw          $at, -0x8($t8)
    MEM_W(-0X8, ctx->r24) = ctx->r1;
    // 0x8005CEA8: lwl         $at, -0x4($t9)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r25, -0X4);
    // 0x8005CEAC: lwr         $at, -0x1($t9)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r25, -0X1);
    // 0x8005CEB0: bne         $t9, $t1, L_8005CE88
    if (ctx->r25 != ctx->r9) {
        // 0x8005CEB4: sw          $at, -0x4($t8)
        MEM_W(-0X4, ctx->r24) = ctx->r1;
            goto L_8005CE88;
    }
    // 0x8005CEB4: sw          $at, -0x4($t8)
    MEM_W(-0X4, ctx->r24) = ctx->r1;
    // 0x8005CEB8: lwl         $at, 0x0($t9)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r25, 0X0);
    // 0x8005CEBC: lwr         $at, 0x3($t9)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r25, 0X3);
    // 0x8005CEC0: sw          $at, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r1;
    // 0x8005CEC4: lbu         $t2, 0x2E($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X2E);
    // 0x8005CEC8: andi        $t3, $t2, 0xC0
    ctx->r11 = ctx->r10 & 0XC0;
    // 0x8005CECC: sra         $t4, $t3, 4
    ctx->r12 = S32(SIGNED(ctx->r11) >> 4);
    // 0x8005CED0: bne         $t4, $zero, L_8005CF24
    if (ctx->r12 != 0) {
        // 0x8005CED4: sw          $t4, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r12;
            goto L_8005CF24;
    }
    // 0x8005CED4: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
    // 0x8005CED8: jal         0x8005CCA0
    // 0x8005CEDC: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    func_8005CCA0(rdram, ctx);
        goto after_6;
    // 0x8005CEDC: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    after_6:
    // 0x8005CEE0: lbu         $t5, 0x52($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X52);
    // 0x8005CEE4: beq         $v0, $t5, L_8005CF2C
    if (ctx->r2 == ctx->r13) {
        // 0x8005CEE8: nop
    
            goto L_8005CF2C;
    }
    // 0x8005CEE8: nop

    // 0x8005CEEC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8005CEF0: jal         0x8005D820
    // 0x8005CEF4: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    func_8005D820(rdram, ctx);
        goto after_7;
    // 0x8005CEF4: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    after_7:
    // 0x8005CEF8: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x8005CEFC: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x8005CF00: beq         $t6, $zero, L_8005CF18
    if (ctx->r14 == 0) {
        // 0x8005CF04: nop
    
            goto L_8005CF18;
    }
    // 0x8005CF04: nop

    // 0x8005CF08: jal         0x8005CB14
    // 0x8005CF0C: nop

    func_8005CB14(rdram, ctx);
        goto after_8;
    // 0x8005CF0C: nop

    after_8:
    // 0x8005CF10: b           L_8005CF60
    // 0x8005CF14: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
        goto L_8005CF60;
    // 0x8005CF14: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
L_8005CF18:
    // 0x8005CF18: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8005CF1C: b           L_8005CF2C
    // 0x8005CF20: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
        goto L_8005CF2C;
    // 0x8005CF20: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
L_8005CF24:
    // 0x8005CF24: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8005CF28: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
L_8005CF2C:
    // 0x8005CF2C: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8005CF30: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005CF34: bne         $t1, $at, L_8005CF54
    if (ctx->r9 != ctx->r1) {
        // 0x8005CF38: nop
    
            goto L_8005CF54;
    }
    // 0x8005CF38: nop

    // 0x8005CF3C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8005CF40: slti        $s0, $t9, 0x0
    ctx->r16 = SIGNED(ctx->r25) < 0X0 ? 1 : 0;
    // 0x8005CF44: xori        $s0, $s0, 0x1
    ctx->r16 = ctx->r16 ^ 0X1;
    // 0x8005CF48: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x8005CF4C: bne         $s0, $zero, L_8005CE18
    if (ctx->r16 != 0) {
        // 0x8005CF50: sw          $t8, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r24;
            goto L_8005CE18;
    }
    // 0x8005CF50: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
L_8005CF54:
    // 0x8005CF54: jal         0x8005CB14
    // 0x8005CF58: nop

    func_8005CB14(rdram, ctx);
        goto after_9;
    // 0x8005CF58: nop

    after_9:
    // 0x8005CF5C: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
L_8005CF60:
    // 0x8005CF60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005CF64: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005CF68: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8005CF6C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005CF74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005CF74: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8005CF78: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8005CF7C: addiu       $t6, $t6, -0x2170
    ctx->r14 = ADD32(ctx->r14, -0X2170);
    // 0x8005CF80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005CF84: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8005CF88: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8005CF8C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8005CF90: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x8005CF94: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_8005CF98:
    // 0x8005CF98: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8005CF9C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8005CFA0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8005CFA4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8005CFA8: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8005CFAC: sw          $zero, -0x2170($at)
    MEM_W(-0X2170, ctx->r1) = 0;
    // 0x8005CFB0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8005CFB4: slti        $at, $t0, 0x10
    ctx->r1 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // 0x8005CFB8: bne         $at, $zero, L_8005CF98
    if (ctx->r1 != 0) {
        // 0x8005CFBC: sw          $t0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r8;
            goto L_8005CF98;
    }
    // 0x8005CFBC: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8005CFC0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8005CFC4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8005CFC8: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8005CFCC: addiu       $t3, $zero, 0x23
    ctx->r11 = ADD32(0, 0X23);
    // 0x8005CFD0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8005CFD4: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8005CFD8: sw          $t1, -0x2134($at)
    MEM_W(-0X2134, ctx->r1) = ctx->r9;
    // 0x8005CFDC: sb          $t2, 0x1C($sp)
    MEM_B(0X1C, ctx->r29) = ctx->r10;
    // 0x8005CFE0: sb          $t3, 0x1D($sp)
    MEM_B(0X1D, ctx->r29) = ctx->r11;
    // 0x8005CFE4: sb          $t4, 0x1E($sp)
    MEM_B(0X1E, ctx->r29) = ctx->r12;
    // 0x8005CFE8: sb          $t5, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r13;
    // 0x8005CFEC: jal         0x8005CBF0
    // 0x8005CFF0: lhu         $a0, 0x4E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X4E);
    func_8005CBF0(rdram, ctx);
        goto after_0;
    // 0x8005CFF0: lhu         $a0, 0x4E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X4E);
    after_0:
    // 0x8005CFF4: lhu         $t6, 0x4E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X4E);
    // 0x8005CFF8: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8005CFFC: sb          $t9, 0x42($sp)
    MEM_B(0X42, ctx->r29) = ctx->r25;
    // 0x8005D000: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x8005D004: or          $t8, $v0, $t7
    ctx->r24 = ctx->r2 | ctx->r15;
    // 0x8005D008: sh          $t8, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r24;
    // 0x8005D00C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_8005D010:
    // 0x8005D010: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8005D014: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8005D018: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x8005D01C: addu        $t3, $sp, $t2
    ctx->r11 = ADD32(ctx->r29, ctx->r10);
    // 0x8005D020: sb          $t1, 0x22($t3)
    MEM_B(0X22, ctx->r11) = ctx->r9;
    // 0x8005D024: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8005D028: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8005D02C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8005D030: slti        $at, $t7, 0x20
    ctx->r1 = SIGNED(ctx->r15) < 0X20 ? 1 : 0;
    // 0x8005D034: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8005D038: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8005D03C: bne         $at, $zero, L_8005D010
    if (ctx->r1 != 0) {
        // 0x8005D040: sw          $t5, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r13;
            goto L_8005D010;
    }
    // 0x8005D040: sw          $t5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r13;
    // 0x8005D044: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8005D048: beq         $t8, $zero, L_8005D084
    if (ctx->r24 == 0) {
        // 0x8005D04C: nop
    
            goto L_8005D084;
    }
    // 0x8005D04C: nop

    // 0x8005D050: blez        $t8, L_8005D084
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8005D054: sw          $zero, 0x18($sp)
        MEM_W(0X18, ctx->r29) = 0;
            goto L_8005D084;
    }
    // 0x8005D054: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_8005D058:
    // 0x8005D058: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8005D05C: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
    // 0x8005D060: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8005D064: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x8005D068: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8005D06C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8005D070: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8005D074: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8005D078: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8005D07C: bne         $at, $zero, L_8005D058
    if (ctx->r1 != 0) {
        // 0x8005D080: sw          $t1, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r9;
            goto L_8005D058;
    }
    // 0x8005D080: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
L_8005D084:
    // 0x8005D084: addiu       $t6, $sp, 0x1C
    ctx->r14 = ADD32(ctx->r29, 0X1C);
    // 0x8005D088: addiu       $t8, $t6, 0x24
    ctx->r24 = ADD32(ctx->r14, 0X24);
    // 0x8005D08C: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
L_8005D090:
    // 0x8005D090: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8005D094: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8005D098: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x8005D09C: swl         $at, -0xC($t5)
    do_swl(rdram, -0XC, ctx->r13, ctx->r1);
    // 0x8005D0A0: swr         $at, -0x9($t5)
    do_swr(rdram, -0X9, ctx->r13, ctx->r1);
    // 0x8005D0A4: lw          $at, -0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X8);
    // 0x8005D0A8: swl         $at, -0x8($t5)
    do_swl(rdram, -0X8, ctx->r13, ctx->r1);
    // 0x8005D0AC: swr         $at, -0x5($t5)
    do_swr(rdram, -0X5, ctx->r13, ctx->r1);
    // 0x8005D0B0: lw          $at, -0x4($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X4);
    // 0x8005D0B4: swl         $at, -0x4($t5)
    do_swl(rdram, -0X4, ctx->r13, ctx->r1);
    // 0x8005D0B8: bne         $t6, $t8, L_8005D090
    if (ctx->r14 != ctx->r24) {
        // 0x8005D0BC: swr         $at, -0x1($t5)
        do_swr(rdram, -0X1, ctx->r13, ctx->r1);
            goto L_8005D090;
    }
    // 0x8005D0BC: swr         $at, -0x1($t5)
    do_swr(rdram, -0X1, ctx->r13, ctx->r1);
    // 0x8005D0C0: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8005D0C4: addiu       $t1, $zero, 0xFE
    ctx->r9 = ADD32(0, 0XFE);
    // 0x8005D0C8: swl         $at, 0x0($t5)
    do_swl(rdram, 0X0, ctx->r13, ctx->r1);
    // 0x8005D0CC: swr         $at, 0x3($t5)
    do_swr(rdram, 0X3, ctx->r13, ctx->r1);
    // 0x8005D0D0: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8005D0D4: addiu       $t0, $t9, 0x28
    ctx->r8 = ADD32(ctx->r25, 0X28);
    // 0x8005D0D8: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x8005D0DC: sb          $t1, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r9;
    // 0x8005D0E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005D0E4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8005D0E8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005D0F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005D0F0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8005D0F4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8005D0F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005D0FC: addiu       $t6, $t6, -0x2170
    ctx->r14 = ADD32(ctx->r14, -0X2170);
    // 0x8005D100: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8005D104: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8005D108: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8005D10C: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x8005D110: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x8005D114: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005D118: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    // 0x8005D11C: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x8005D120: jal         0x8005CAD0
    // 0x8005D124: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    func_8005CAD0(rdram, ctx);
        goto after_0;
    // 0x8005D124: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    after_0:
    // 0x8005D128: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8005D12C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8005D130: sb          $t8, -0x4640($at)
    MEM_B(-0X4640, ctx->r1) = ctx->r24;
    // 0x8005D134: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8005D138: jal         0x8005D30C
    // 0x8005D13C: lhu         $a1, 0x6A($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X6A);
    func_8005D30C(rdram, ctx);
        goto after_1;
    // 0x8005D13C: lhu         $a1, 0x6A($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X6A);
    after_1:
    // 0x8005D140: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8005D144: addiu       $a1, $a1, -0x2170
    ctx->r5 = ADD32(ctx->r5, -0X2170);
    // 0x8005D148: jal         0x8005CB40
    // 0x8005D14C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8005CB40(rdram, ctx);
        goto after_2;
    // 0x8005D14C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x8005D150: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x8005D154: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8005D158: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005D15C: jal         0x8004F990
    // 0x8005D160: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x8005D160: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
L_8005D164:
    // 0x8005D164: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8005D168: addiu       $a1, $a1, -0x2170
    ctx->r5 = ADD32(ctx->r5, -0X2170);
    // 0x8005D16C: jal         0x8005CB40
    // 0x8005D170: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8005CB40(rdram, ctx);
        goto after_4;
    // 0x8005D170: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x8005D174: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x8005D178: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8005D17C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005D180: jal         0x8004F990
    // 0x8005D184: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x8005D184: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x8005D188: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x8005D18C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8005D190: addiu       $t9, $t9, -0x2170
    ctx->r25 = ADD32(ctx->r25, -0X2170);
    // 0x8005D194: beq         $t0, $zero, L_8005D1C8
    if (ctx->r8 == 0) {
        // 0x8005D198: sw          $t9, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r25;
            goto L_8005D1C8;
    }
    // 0x8005D198: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
    // 0x8005D19C: blez        $t0, L_8005D1C8
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8005D1A0: sw          $zero, 0x58($sp)
        MEM_W(0X58, ctx->r29) = 0;
            goto L_8005D1C8;
    }
    // 0x8005D1A0: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
L_8005D1A4:
    // 0x8005D1A4: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x8005D1A8: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x8005D1AC: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x8005D1B0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005D1B4: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8005D1B8: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8005D1BC: sw          $t4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r12;
    // 0x8005D1C0: bne         $at, $zero, L_8005D1A4
    if (ctx->r1 != 0) {
        // 0x8005D1C4: sw          $t2, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r10;
            goto L_8005D1A4;
    }
    // 0x8005D1C4: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
L_8005D1C8:
    // 0x8005D1C8: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8005D1CC: addiu       $t6, $sp, 0x2C
    ctx->r14 = ADD32(ctx->r29, 0X2C);
    // 0x8005D1D0: addiu       $t9, $t7, 0x24
    ctx->r25 = ADD32(ctx->r15, 0X24);
L_8005D1D4:
    // 0x8005D1D4: lwl         $at, 0x0($t7)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r15, 0X0);
    // 0x8005D1D8: lwr         $at, 0x3($t7)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r15, 0X3);
    // 0x8005D1DC: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x8005D1E0: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8005D1E4: sw          $at, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r1;
    // 0x8005D1E8: lwl         $at, -0x8($t7)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r15, -0X8);
    // 0x8005D1EC: lwr         $at, -0x5($t7)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r15, -0X5);
    // 0x8005D1F0: sw          $at, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r1;
    // 0x8005D1F4: lwl         $at, -0x4($t7)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r15, -0X4);
    // 0x8005D1F8: lwr         $at, -0x1($t7)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r15, -0X1);
    // 0x8005D1FC: bne         $t7, $t9, L_8005D1D4
    if (ctx->r15 != ctx->r25) {
        // 0x8005D200: sw          $at, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r1;
            goto L_8005D1D4;
    }
    // 0x8005D200: sw          $at, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r1;
    // 0x8005D204: lwl         $at, 0x0($t7)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r15, 0X0);
    // 0x8005D208: lwr         $at, 0x3($t7)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r15, 0X3);
    // 0x8005D20C: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8005D210: lbu         $t0, 0x2E($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X2E);
    // 0x8005D214: andi        $t1, $t0, 0xC0
    ctx->r9 = ctx->r8 & 0XC0;
    // 0x8005D218: sra         $t2, $t1, 4
    ctx->r10 = S32(SIGNED(ctx->r9) >> 4);
    // 0x8005D21C: bne         $t2, $zero, L_8005D2BC
    if (ctx->r10 != 0) {
        // 0x8005D220: sw          $t2, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r10;
            goto L_8005D2BC;
    }
    // 0x8005D220: sw          $t2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r10;
    // 0x8005D224: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8005D228: jal         0x8005CCA0
    // 0x8005D22C: addiu       $a0, $a0, 0x6
    ctx->r4 = ADD32(ctx->r4, 0X6);
    func_8005CCA0(rdram, ctx);
        goto after_6;
    // 0x8005D22C: addiu       $a0, $a0, 0x6
    ctx->r4 = ADD32(ctx->r4, 0X6);
    after_6:
    // 0x8005D230: sb          $v0, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r2;
    // 0x8005D234: lbu         $t3, 0x27($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X27);
    // 0x8005D238: lbu         $t4, 0x52($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X52);
    // 0x8005D23C: beq         $t3, $t4, L_8005D27C
    if (ctx->r11 == ctx->r12) {
        // 0x8005D240: nop
    
            goto L_8005D27C;
    }
    // 0x8005D240: nop

    // 0x8005D244: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8005D248: jal         0x8005D820
    // 0x8005D24C: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    func_8005D820(rdram, ctx);
        goto after_7;
    // 0x8005D24C: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    after_7:
    // 0x8005D250: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x8005D254: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x8005D258: beq         $t5, $zero, L_8005D270
    if (ctx->r13 == 0) {
        // 0x8005D25C: nop
    
            goto L_8005D270;
    }
    // 0x8005D25C: nop

    // 0x8005D260: jal         0x8005CB14
    // 0x8005D264: nop

    func_8005CB14(rdram, ctx);
        goto after_8;
    // 0x8005D264: nop

    after_8:
    // 0x8005D268: b           L_8005D2F8
    // 0x8005D26C: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
        goto L_8005D2F8;
    // 0x8005D26C: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
L_8005D270:
    // 0x8005D270: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8005D274: b           L_8005D2C4
    // 0x8005D278: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
        goto L_8005D2C4;
    // 0x8005D278: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
L_8005D27C:
    // 0x8005D27C: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
L_8005D280:
    // 0x8005D280: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x8005D284: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x8005D288: addu        $t7, $sp, $t9
    ctx->r15 = ADD32(ctx->r29, ctx->r25);
    // 0x8005D28C: lbu         $t7, 0x32($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X32);
    // 0x8005D290: sb          $t7, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r15;
    // 0x8005D294: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x8005D298: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x8005D29C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8005D2A0: slti        $at, $t3, 0x20
    ctx->r1 = SIGNED(ctx->r11) < 0X20 ? 1 : 0;
    // 0x8005D2A4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8005D2A8: sw          $t3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r11;
    // 0x8005D2AC: bne         $at, $zero, L_8005D280
    if (ctx->r1 != 0) {
        // 0x8005D2B0: sw          $t1, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r9;
            goto L_8005D280;
    }
    // 0x8005D2B0: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
    // 0x8005D2B4: b           L_8005D2C4
    // 0x8005D2B8: nop

        goto L_8005D2C4;
    // 0x8005D2B8: nop

L_8005D2BC:
    // 0x8005D2BC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8005D2C0: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
L_8005D2C4:
    // 0x8005D2C4: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x8005D2C8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005D2CC: bne         $t5, $at, L_8005D2EC
    if (ctx->r13 != ctx->r1) {
        // 0x8005D2D0: nop
    
            goto L_8005D2EC;
    }
    // 0x8005D2D0: nop

    // 0x8005D2D4: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8005D2D8: slti        $s0, $t8, 0x0
    ctx->r16 = SIGNED(ctx->r24) < 0X0 ? 1 : 0;
    // 0x8005D2DC: xori        $s0, $s0, 0x1
    ctx->r16 = ctx->r16 ^ 0X1;
    // 0x8005D2E0: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8005D2E4: bne         $s0, $zero, L_8005D164
    if (ctx->r16 != 0) {
        // 0x8005D2E8: sw          $t9, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r25;
            goto L_8005D164;
    }
    // 0x8005D2E8: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
L_8005D2EC:
    // 0x8005D2EC: jal         0x8005CB14
    // 0x8005D2F0: nop

    func_8005CB14(rdram, ctx);
        goto after_9;
    // 0x8005D2F0: nop

    after_9:
    // 0x8005D2F4: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
L_8005D2F8:
    // 0x8005D2F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D2FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005D300: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8005D304: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005D30C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005D30C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8005D310: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8005D314: addiu       $t6, $t6, -0x2170
    ctx->r14 = ADD32(ctx->r14, -0X2170);
    // 0x8005D318: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005D31C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8005D320: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8005D324: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x8005D328: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_8005D32C:
    // 0x8005D32C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8005D330: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8005D334: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8005D338: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8005D33C: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8005D340: sw          $zero, -0x2170($at)
    MEM_W(-0X2170, ctx->r1) = 0;
    // 0x8005D344: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8005D348: slti        $at, $t0, 0x10
    ctx->r1 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // 0x8005D34C: bne         $at, $zero, L_8005D32C
    if (ctx->r1 != 0) {
        // 0x8005D350: sw          $t0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r8;
            goto L_8005D32C;
    }
    // 0x8005D350: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8005D354: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8005D358: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8005D35C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8005D360: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8005D364: addiu       $t4, $zero, 0x21
    ctx->r12 = ADD32(0, 0X21);
    // 0x8005D368: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8005D36C: sw          $t1, -0x2134($at)
    MEM_W(-0X2134, ctx->r1) = ctx->r9;
    // 0x8005D370: sb          $t2, 0x1C($sp)
    MEM_B(0X1C, ctx->r29) = ctx->r10;
    // 0x8005D374: sb          $t3, 0x1D($sp)
    MEM_B(0X1D, ctx->r29) = ctx->r11;
    // 0x8005D378: sb          $t4, 0x1E($sp)
    MEM_B(0X1E, ctx->r29) = ctx->r12;
    // 0x8005D37C: sb          $t5, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r13;
    // 0x8005D380: jal         0x8005CBF0
    // 0x8005D384: lhu         $a0, 0x4E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X4E);
    func_8005CBF0(rdram, ctx);
        goto after_0;
    // 0x8005D384: lhu         $a0, 0x4E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X4E);
    after_0:
    // 0x8005D388: lhu         $t6, 0x4E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X4E);
    // 0x8005D38C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8005D390: sb          $t9, 0x42($sp)
    MEM_B(0X42, ctx->r29) = ctx->r25;
    // 0x8005D394: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x8005D398: or          $t8, $v0, $t7
    ctx->r24 = ctx->r2 | ctx->r15;
    // 0x8005D39C: sh          $t8, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r24;
    // 0x8005D3A0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_8005D3A4:
    // 0x8005D3A4: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8005D3A8: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8005D3AC: addu        $t2, $sp, $t1
    ctx->r10 = ADD32(ctx->r29, ctx->r9);
    // 0x8005D3B0: sb          $t0, 0x22($t2)
    MEM_B(0X22, ctx->r10) = ctx->r8;
    // 0x8005D3B4: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8005D3B8: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005D3BC: slti        $at, $t4, 0x20
    ctx->r1 = SIGNED(ctx->r12) < 0X20 ? 1 : 0;
    // 0x8005D3C0: bne         $at, $zero, L_8005D3A4
    if (ctx->r1 != 0) {
        // 0x8005D3C4: sw          $t4, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r12;
            goto L_8005D3A4;
    }
    // 0x8005D3C4: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8005D3C8: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x8005D3CC: beq         $t5, $zero, L_8005D408
    if (ctx->r13 == 0) {
        // 0x8005D3D0: nop
    
            goto L_8005D408;
    }
    // 0x8005D3D0: nop

    // 0x8005D3D4: blez        $t5, L_8005D408
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8005D3D8: sw          $zero, 0x18($sp)
        MEM_W(0X18, ctx->r29) = 0;
            goto L_8005D408;
    }
    // 0x8005D3D8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_8005D3DC:
    // 0x8005D3DC: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8005D3E0: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x8005D3E4: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8005D3E8: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8005D3EC: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8005D3F0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8005D3F4: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8005D3F8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8005D3FC: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8005D400: bne         $at, $zero, L_8005D3DC
    if (ctx->r1 != 0) {
        // 0x8005D404: sw          $t8, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r24;
            goto L_8005D3DC;
    }
    // 0x8005D404: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
L_8005D408:
    // 0x8005D408: addiu       $t3, $sp, 0x1C
    ctx->r11 = ADD32(ctx->r29, 0X1C);
    // 0x8005D40C: addiu       $t5, $t3, 0x24
    ctx->r13 = ADD32(ctx->r11, 0X24);
    // 0x8005D410: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
L_8005D414:
    // 0x8005D414: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x8005D418: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x8005D41C: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x8005D420: swl         $at, -0xC($t2)
    do_swl(rdram, -0XC, ctx->r10, ctx->r1);
    // 0x8005D424: swr         $at, -0x9($t2)
    do_swr(rdram, -0X9, ctx->r10, ctx->r1);
    // 0x8005D428: lw          $at, -0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, -0X8);
    // 0x8005D42C: swl         $at, -0x8($t2)
    do_swl(rdram, -0X8, ctx->r10, ctx->r1);
    // 0x8005D430: swr         $at, -0x5($t2)
    do_swr(rdram, -0X5, ctx->r10, ctx->r1);
    // 0x8005D434: lw          $at, -0x4($t3)
    ctx->r1 = MEM_W(ctx->r11, -0X4);
    // 0x8005D438: swl         $at, -0x4($t2)
    do_swl(rdram, -0X4, ctx->r10, ctx->r1);
    // 0x8005D43C: bne         $t3, $t5, L_8005D414
    if (ctx->r11 != ctx->r13) {
        // 0x8005D440: swr         $at, -0x1($t2)
        do_swr(rdram, -0X1, ctx->r10, ctx->r1);
            goto L_8005D414;
    }
    // 0x8005D440: swr         $at, -0x1($t2)
    do_swr(rdram, -0X1, ctx->r10, ctx->r1);
    // 0x8005D444: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x8005D448: addiu       $t8, $zero, 0xFE
    ctx->r24 = ADD32(0, 0XFE);
    // 0x8005D44C: swl         $at, 0x0($t2)
    do_swl(rdram, 0X0, ctx->r10, ctx->r1);
    // 0x8005D450: swr         $at, 0x3($t2)
    do_swr(rdram, 0X3, ctx->r10, ctx->r1);
    // 0x8005D454: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8005D458: addiu       $t7, $t6, 0x28
    ctx->r15 = ADD32(ctx->r14, 0X28);
    // 0x8005D45C: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x8005D460: sb          $t8, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r24;
    // 0x8005D464: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005D468: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8005D46C: jr          $ra
    // 0x8005D470: nop

    TRACE_RETURN()
    return;
    // 0x8005D470: nop

    // 0x8005D474: nop

    // 0x8005D478: nop

    // 0x8005D47C: nop

    // 0x8005D480: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8005D484: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8005D488: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8005D48C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8005D490: ld          $t7, 0x8($sp)
    ctx->r15 = LD(ctx->r29, 0X8);
    // 0x8005D494: ld          $t6, 0x0($sp)
    ctx->r14 = LD(ctx->r29, 0X0);
    // 0x8005D498: dsrlv       $v0, $t6, $t7
    ctx->r2 = ctx->r14 >> (ctx->r15 & 63);
    // 0x8005D49C: dsll32      $v1, $v0, 0
    ctx->r3 = ctx->r2 << (0 + 32);
    // 0x8005D4A0: dsra32      $v1, $v1, 0
    ctx->r3 = SIGNED(ctx->r3) >> (0 + 32);
    // 0x8005D4A4: jr          $ra
    // 0x8005D4A8: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    TRACE_RETURN()
    return;
    // 0x8005D4A8: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
;}
RECOMP_FUNC void func_8005D4AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005D4AC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8005D4B0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8005D4B4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8005D4B8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8005D4BC: ld          $t7, 0x8($sp)
    ctx->r15 = LD(ctx->r29, 0X8);
    // 0x8005D4C0: ld          $t6, 0x0($sp)
    ctx->r14 = LD(ctx->r29, 0X0);
    // 0x8005D4C4: ddivu       $zero, $t6, $t7
    DDIVU(U64(ctx->r14), U64(ctx->r15), &lo, &hi);
    // 0x8005D4C8: bne         $t7, $zero, L_8005D4D4
    if (ctx->r15 != 0) {
        // 0x8005D4CC: nop
    
            goto L_8005D4D4;
    }
    // 0x8005D4CC: nop

    // 0x8005D4D0: break       7
    do_break(2147865808);
L_8005D4D4:
    // 0x8005D4D4: mfhi        $v0
    ctx->r2 = hi;
    // 0x8005D4D8: dsll32      $v1, $v0, 0
    ctx->r3 = ctx->r2 << (0 + 32);
    // 0x8005D4DC: dsra32      $v1, $v1, 0
    ctx->r3 = SIGNED(ctx->r3) >> (0 + 32);
    // 0x8005D4E0: jr          $ra
    // 0x8005D4E4: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    TRACE_RETURN()
    return;
    // 0x8005D4E4: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
;}
RECOMP_FUNC void func_8005D4E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005D4E8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8005D4EC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8005D4F0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8005D4F4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8005D4F8: ld          $t7, 0x8($sp)
    ctx->r15 = LD(ctx->r29, 0X8);
    // 0x8005D4FC: ld          $t6, 0x0($sp)
    ctx->r14 = LD(ctx->r29, 0X0);
    // 0x8005D500: ddivu       $zero, $t6, $t7
    DDIVU(U64(ctx->r14), U64(ctx->r15), &lo, &hi);
    // 0x8005D504: bne         $t7, $zero, L_8005D510
    if (ctx->r15 != 0) {
        // 0x8005D508: nop
    
            goto L_8005D510;
    }
    // 0x8005D508: nop

    // 0x8005D50C: break       7
    do_break(2147865868);
L_8005D510:
    // 0x8005D510: mflo        $v0
    ctx->r2 = lo;
    // 0x8005D514: dsll32      $v1, $v0, 0
    ctx->r3 = ctx->r2 << (0 + 32);
    // 0x8005D518: dsra32      $v1, $v1, 0
    ctx->r3 = SIGNED(ctx->r3) >> (0 + 32);
    // 0x8005D51C: jr          $ra
    // 0x8005D520: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    TRACE_RETURN()
    return;
    // 0x8005D520: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
;}
RECOMP_FUNC void func_8005D524(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005D524: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8005D528: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8005D52C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8005D530: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8005D534: ld          $t7, 0x8($sp)
    ctx->r15 = LD(ctx->r29, 0X8);
    // 0x8005D538: ld          $t6, 0x0($sp)
    ctx->r14 = LD(ctx->r29, 0X0);
    // 0x8005D53C: dsllv       $v0, $t6, $t7
    ctx->r2 = ctx->r14 << (ctx->r15 & 63);
    // 0x8005D540: dsll32      $v1, $v0, 0
    ctx->r3 = ctx->r2 << (0 + 32);
    // 0x8005D544: dsra32      $v1, $v1, 0
    ctx->r3 = SIGNED(ctx->r3) >> (0 + 32);
    // 0x8005D548: jr          $ra
    // 0x8005D54C: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    TRACE_RETURN()
    return;
    // 0x8005D54C: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
;}
RECOMP_FUNC void func_8005D550(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005D550: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8005D554: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8005D558: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8005D55C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8005D560: ld          $t7, 0x8($sp)
    ctx->r15 = LD(ctx->r29, 0X8);
    // 0x8005D564: ld          $t6, 0x0($sp)
    ctx->r14 = LD(ctx->r29, 0X0);
    // 0x8005D568: ddivu       $zero, $t6, $t7
    DDIVU(U64(ctx->r14), U64(ctx->r15), &lo, &hi);
    // 0x8005D56C: bne         $t7, $zero, L_8005D578
    if (ctx->r15 != 0) {
        // 0x8005D570: nop
    
            goto L_8005D578;
    }
    // 0x8005D570: nop

    // 0x8005D574: break       7
    do_break(2147865972);
L_8005D578:
    // 0x8005D578: mfhi        $v0
    ctx->r2 = hi;
    // 0x8005D57C: dsll32      $v1, $v0, 0
    ctx->r3 = ctx->r2 << (0 + 32);
    // 0x8005D580: dsra32      $v1, $v1, 0
    ctx->r3 = SIGNED(ctx->r3) >> (0 + 32);
    // 0x8005D584: jr          $ra
    // 0x8005D588: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    TRACE_RETURN()
    return;
    // 0x8005D588: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
;}
RECOMP_FUNC void func_8005D58C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005D58C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8005D590: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8005D594: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8005D598: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8005D59C: ld          $t7, 0x8($sp)
    ctx->r15 = LD(ctx->r29, 0X8);
    // 0x8005D5A0: ld          $t6, 0x0($sp)
    ctx->r14 = LD(ctx->r29, 0X0);
    // 0x8005D5A4: ddiv        $zero, $t6, $t7
    DDIV(S64(ctx->r14), S64(ctx->r15), &lo, &hi);
    // 0x8005D5A8: nop

    // 0x8005D5AC: bne         $t7, $zero, L_8005D5B8
    if (ctx->r15 != 0) {
        // 0x8005D5B0: nop
    
            goto L_8005D5B8;
    }
    // 0x8005D5B0: nop

    // 0x8005D5B4: break       7
    do_break(2147866036);
L_8005D5B8:
    // 0x8005D5B8: daddiu      $at, $zero, -0x1
    ctx->r1 = 0 + -0X1;
    // 0x8005D5BC: bne         $t7, $at, L_8005D5D4
    if (ctx->r15 != ctx->r1) {
        // 0x8005D5C0: daddiu      $at, $zero, 0x1
        ctx->r1 = 0 + 0X1;
            goto L_8005D5D4;
    }
    // 0x8005D5C0: daddiu      $at, $zero, 0x1
    ctx->r1 = 0 + 0X1;
    // 0x8005D5C4: dsll32      $at, $at, 31
    ctx->r1 = ctx->r1 << (31 + 32);
    // 0x8005D5C8: bne         $t6, $at, L_8005D5D4
    if (ctx->r14 != ctx->r1) {
        // 0x8005D5CC: nop
    
            goto L_8005D5D4;
    }
    // 0x8005D5CC: nop

    // 0x8005D5D0: break       6
    do_break(2147866064);
L_8005D5D4:
    // 0x8005D5D4: mflo        $v0
    ctx->r2 = lo;
    // 0x8005D5D8: dsll32      $v1, $v0, 0
    ctx->r3 = ctx->r2 << (0 + 32);
    // 0x8005D5DC: dsra32      $v1, $v1, 0
    ctx->r3 = SIGNED(ctx->r3) >> (0 + 32);
    // 0x8005D5E0: jr          $ra
    // 0x8005D5E4: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    TRACE_RETURN()
    return;
    // 0x8005D5E4: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
;}
