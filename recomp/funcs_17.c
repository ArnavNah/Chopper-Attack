#include "recomp.h"
#include "trace.h"
#include "funcs.h"

RECOMP_FUNC void func_8003DE20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8003DE20: addiu       $sp, $sp, -0x108
    ctx->r29 = ADD32(ctx->r29, -0X108);
    // 0x8003DE24: sw          $a1, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r5;
    // 0x8003DE28: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x8003DE2C: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8003DE30: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8003DE34: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8003DE38: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8003DE3C: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8003DE40: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8003DE44: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8003DE48: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8003DE4C: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8003DE50: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8003DE54: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8003DE58: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8003DE5C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8003DE60: sw          $a2, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r6;
    // 0x8003DE64: beq         $a1, $zero, L_8003DECC
    if (ctx->r5 == 0) {
        // 0x8003DE68: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8003DECC;
    }
    // 0x8003DE68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003DE6C: lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // 0x8003DE70: addiu       $v1, $v1, 0x64C
    ctx->r3 = ADD32(ctx->r3, 0X64C);
    // 0x8003DE74: lh          $t8, 0x8($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X8);
    // 0x8003DE78: sll         $t2, $a1, 2
    ctx->r10 = S32(ctx->r5 << 2);
    // 0x8003DE7C: or          $s2, $v1, $zero
    ctx->r18 = ctx->r3 | 0;
    // 0x8003DE80: beq         $t8, $zero, L_8003DEA0
    if (ctx->r24 == 0) {
        // 0x8003DE84: subu        $t2, $t2, $a1
        ctx->r10 = SUB32(ctx->r10, ctx->r5);
            goto L_8003DEA0;
    }
    // 0x8003DE84: subu        $t2, $t2, $a1
    ctx->r10 = SUB32(ctx->r10, ctx->r5);
L_8003DE88:
    // 0x8003DE88: lh          $t1, 0x34($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X34);
    // 0x8003DE8C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8003DE90: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x8003DE94: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8003DE98: bne         $t1, $zero, L_8003DE88
    if (ctx->r9 != 0) {
        // 0x8003DE9C: addiu       $s2, $s2, 0x2C
        ctx->r18 = ADD32(ctx->r18, 0X2C);
            goto L_8003DE88;
    }
    // 0x8003DE9C: addiu       $s2, $s2, 0x2C
    ctx->r18 = ADD32(ctx->r18, 0X2C);
L_8003DEA0:
    // 0x8003DEA0: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8003DEA4: beq         $at, $zero, L_8003DEB4
    if (ctx->r1 == 0) {
        // 0x8003DEA8: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_8003DEB4;
    }
    // 0x8003DEA8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8003DEAC: b           L_8003E1C4
    // 0x8003DEB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003E1C4;
    // 0x8003DEB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003DEB4:
    // 0x8003DEB4: subu        $t2, $t2, $a1
    ctx->r10 = SUB32(ctx->r10, ctx->r5);
    // 0x8003DEB8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8003DEBC: addu        $v0, $v1, $t2
    ctx->r2 = ADD32(ctx->r3, ctx->r10);
    // 0x8003DEC0: addiu       $s3, $v0, -0x2C
    ctx->r19 = ADD32(ctx->r2, -0X2C);
    // 0x8003DEC4: b           L_8003DF00
    // 0x8003DEC8: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
        goto L_8003DF00;
    // 0x8003DEC8: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
L_8003DECC:
    // 0x8003DECC: lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // 0x8003DED0: addiu       $s2, $v1, 0x64C
    ctx->r18 = ADD32(ctx->r3, 0X64C);
    // 0x8003DED4: lh          $t3, 0x8($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X8);
    // 0x8003DED8: beql        $t3, $zero, L_8003E1C4
    if (ctx->r11 == 0) {
        // 0x8003DEDC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8003E1C4;
    }
    goto skip_0;
    // 0x8003DEDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8003DEE0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8003DEE4: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
L_8003DEE8:
    // 0x8003DEE8: or          $s3, $s2, $zero
    ctx->r19 = ctx->r18 | 0;
    // 0x8003DEEC: bnel        $v0, $t4, L_8003E1B4
    if (ctx->r2 != ctx->r12) {
        // 0x8003DEF0: lh          $t4, 0x34($s2)
        ctx->r12 = MEM_H(ctx->r18, 0X34);
            goto L_8003E1B4;
    }
    goto skip_1;
    // 0x8003DEF0: lh          $t4, 0x34($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X34);
    skip_1:
    // 0x8003DEF4: lw          $t5, 0x4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4);
    // 0x8003DEF8: lw          $t6, 0x4($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X4);
    // 0x8003DEFC: bne         $t5, $t6, L_8003E1B0
    if (ctx->r13 != ctx->r14) {
        // 0x8003DF00: lui         $s4, 0x801A
        ctx->r20 = S32(0X801A << 16);
            goto L_8003E1B0;
    }
L_8003DF00:
    // 0x8003DF00: lui         $s4, 0x801A
    ctx->r20 = S32(0X801A << 16);
    // 0x8003DF04: addiu       $s4, $s4, 0x2800
    ctx->r20 = ADD32(ctx->r20, 0X2800);
    // 0x8003DF08: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8003DF0C: jal         0x80004364
    // 0x8003DF10: addiu       $a1, $zero, 0xCC
    ctx->r5 = ADD32(0, 0XCC);
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x8003DF10: addiu       $a1, $zero, 0xCC
    ctx->r5 = ADD32(0, 0XCC);
    after_0:
    // 0x8003DF14: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8003DF18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8003DF1C: jal         0x8000C7C0
    // 0x8003DF20: addiu       $a1, $zero, 0xCC
    ctx->r5 = ADD32(0, 0XCC);
    func_8000C7C0(rdram, ctx);
        goto after_1;
    // 0x8003DF20: addiu       $a1, $zero, 0xCC
    ctx->r5 = ADD32(0, 0XCC);
    after_1:
    // 0x8003DF24: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8003DF28: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x8003DF2C: addiu       $v1, $s1, 0x84
    ctx->r3 = ADD32(ctx->r17, 0X84);
L_8003DF30:
    // 0x8003DF30: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8003DF34: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8003DF38: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x8003DF3C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003DF40: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003DF44: bne         $at, $zero, L_8003DF30
    if (ctx->r1 != 0) {
        // 0x8003DF48: sw          $t7, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r15;
            goto L_8003DF30;
    }
    // 0x8003DF48: sw          $t7, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r15;
    // 0x8003DF4C: lh          $t8, 0x8($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X8);
    // 0x8003DF50: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8003DF54: sh          $t8, 0x8E($s1)
    MEM_H(0X8E, ctx->r17) = ctx->r24;
    // 0x8003DF58: lwc1        $f4, 0xC($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8003DF5C: swc1        $f4, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f4.u32l;
    // 0x8003DF60: lh          $t9, 0x14($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X14);
    // 0x8003DF64: sh          $t9, 0x34($s1)
    MEM_H(0X34, ctx->r17) = ctx->r25;
    // 0x8003DF68: lh          $v0, 0x34($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X34);
    // 0x8003DF6C: beq         $v0, $zero, L_8003E168
    if (ctx->r2 == 0) {
        // 0x8003DF70: sll         $a1, $v0, 2
        ctx->r5 = S32(ctx->r2 << 2);
            goto L_8003E168;
    }
    // 0x8003DF70: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x8003DF74: subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // 0x8003DF78: jal         0x80004364
    // 0x8003DF7C: sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5 << 3);
    func_80004364(rdram, ctx);
        goto after_2;
    // 0x8003DF7C: sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5 << 3);
    after_2:
    // 0x8003DF80: lh          $t0, 0x34($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X34);
    // 0x8003DF84: sw          $v0, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r2;
    // 0x8003DF88: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8003DF8C: blez        $t0, L_8003E168
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8003DF90: or          $s7, $zero, $zero
        ctx->r23 = 0 | 0;
            goto L_8003E168;
    }
    // 0x8003DF90: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x8003DF94: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003DF98: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8003DF9C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8003DFA0: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x8003DFA4: addiu       $s6, $sp, 0x6C
    ctx->r22 = ADD32(ctx->r29, 0X6C);
    // 0x8003DFA8: addiu       $s5, $sp, 0xAC
    ctx->r21 = ADD32(ctx->r29, 0XAC);
    // 0x8003DFAC: addiu       $s4, $sp, 0xB8
    ctx->r20 = ADD32(ctx->r29, 0XB8);
    // 0x8003DFB0: addiu       $s3, $zero, 0x6
    ctx->r19 = ADD32(0, 0X6);
    // 0x8003DFB4: lw          $t1, 0x10($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X10);
L_8003DFB8:
    // 0x8003DFB8: lw          $t4, 0x30($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X30);
    // 0x8003DFBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003DFC0: addu        $t2, $t1, $fp
    ctx->r10 = ADD32(ctx->r9, ctx->r30);
    // 0x8003DFC4: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x8003DFC8: addu        $t5, $t4, $s7
    ctx->r13 = ADD32(ctx->r12, ctx->r23);
    // 0x8003DFCC: sh          $t3, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r11;
    // 0x8003DFD0: lw          $t6, 0x30($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X30);
    // 0x8003DFD4: addu        $t7, $t6, $s7
    ctx->r15 = ADD32(ctx->r14, ctx->r23);
    // 0x8003DFD8: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8003DFDC: andi        $t9, $t8, 0x40
    ctx->r25 = ctx->r24 & 0X40;
    // 0x8003DFE0: beql        $t9, $zero, L_8003E034
    if (ctx->r25 == 0) {
        // 0x8003DFE4: lw          $t9, 0x10($s2)
        ctx->r25 = MEM_W(ctx->r18, 0X10);
            goto L_8003E034;
    }
    goto skip_2;
    // 0x8003DFE4: lw          $t9, 0x10($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X10);
    skip_2:
L_8003DFE8:
    // 0x8003DFE8: lw          $t0, 0x10($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X10);
    // 0x8003DFEC: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    // 0x8003DFF0: lw          $t5, 0x30($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X30);
    // 0x8003DFF4: addu        $t1, $t1, $s0
    ctx->r9 = ADD32(ctx->r9, ctx->r16);
    // 0x8003DFF8: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x8003DFFC: subu        $t6, $t6, $s0
    ctx->r14 = SUB32(ctx->r14, ctx->r16);
    // 0x8003E000: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8003E004: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8003E008: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8003E00C: addu        $t4, $t2, $v0
    ctx->r12 = ADD32(ctx->r10, ctx->r2);
    // 0x8003E010: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8003E014: lh          $t3, 0x2($t4)
    ctx->r11 = MEM_H(ctx->r12, 0X2);
    // 0x8003E018: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8003E01C: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8003E020: bne         $v0, $s3, L_8003DFE8
    if (ctx->r2 != ctx->r19) {
        // 0x8003E024: sh          $t3, 0x2($t8)
        MEM_H(0X2, ctx->r24) = ctx->r11;
            goto L_8003DFE8;
    }
    // 0x8003E024: sh          $t3, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r11;
    // 0x8003E028: b           L_8003E138
    // 0x8003E02C: lw          $t2, 0x10($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X10);
        goto L_8003E138;
    // 0x8003E02C: lw          $t2, 0x10($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X10);
    // 0x8003E030: lw          $t9, 0x10($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X10);
L_8003E034:
    // 0x8003E034: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8003E038: addu        $v0, $t9, $fp
    ctx->r2 = ADD32(ctx->r25, ctx->r30);
    // 0x8003E03C: lh          $t0, 0x2($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X2);
    // 0x8003E040: lh          $t1, 0x4($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X4);
    // 0x8003E044: lh          $t2, 0x6($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X6);
    // 0x8003E048: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8003E04C: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8003E050: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x8003E054: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8003E058: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8003E05C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8003E060: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8003E064: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8003E068: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8003E06C: jal         0x80001A6C
    // 0x8003E070: nop

    func_80001A6C(rdram, ctx);
        goto after_3;
    // 0x8003E070: nop

    after_3:
    // 0x8003E074: lw          $t4, 0x110($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X110);
    // 0x8003E078: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8003E07C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8003E080: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    // 0x8003E084: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8003E088: jal         0x80049840
    // 0x8003E08C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_80049840(rdram, ctx);
        goto after_4;
    // 0x8003E08C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_4:
    // 0x8003E090: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8003E094: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8003E098: jal         0x80000BD8
    // 0x8003E09C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_80000BD8(rdram, ctx);
        goto after_5;
    // 0x8003E09C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_5:
    // 0x8003E0A0: lw          $t5, 0x110($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X110);
    // 0x8003E0A4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8003E0A8: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8003E0AC: lw          $a1, 0x8($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X8);
    // 0x8003E0B0: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x8003E0B4: jal         0x80049840
    // 0x8003E0B8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_80049840(rdram, ctx);
        goto after_6;
    // 0x8003E0B8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_6:
    // 0x8003E0BC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8003E0C0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8003E0C4: jal         0x80000BD8
    // 0x8003E0C8: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_80000BD8(rdram, ctx);
        goto after_7;
    // 0x8003E0C8: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_7:
    // 0x8003E0CC: lw          $t6, 0x110($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X110);
    // 0x8003E0D0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8003E0D4: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8003E0D8: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    // 0x8003E0DC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8003E0E0: jal         0x80049840
    // 0x8003E0E4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_80049840(rdram, ctx);
        goto after_8;
    // 0x8003E0E4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_8:
    // 0x8003E0E8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8003E0EC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8003E0F0: jal         0x80000BD8
    // 0x8003E0F4: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_80000BD8(rdram, ctx);
        goto after_9;
    // 0x8003E0F4: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_9:
    // 0x8003E0F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003E0FC: addiu       $v1, $sp, 0xAC
    ctx->r3 = ADD32(ctx->r29, 0XAC);
L_8003E100:
    // 0x8003E100: lwc1        $f16, 0x30($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X30);
    // 0x8003E104: lw          $t8, 0x30($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X30);
    // 0x8003E108: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x8003E10C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8003E110: subu        $t9, $t9, $s0
    ctx->r25 = SUB32(ctx->r25, ctx->r16);
    // 0x8003E114: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8003E118: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8003E11C: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x8003E120: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x8003E124: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003E128: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8003E12C: bne         $v1, $s4, L_8003E100
    if (ctx->r3 != ctx->r20) {
        // 0x8003E130: sh          $t3, 0x2($t1)
        MEM_H(0X2, ctx->r9) = ctx->r11;
            goto L_8003E100;
    }
    // 0x8003E130: sh          $t3, 0x2($t1)
    MEM_H(0X2, ctx->r9) = ctx->r11;
    // 0x8003E134: lw          $t2, 0x10($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X10);
L_8003E138:
    // 0x8003E138: lw          $t6, 0x30($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X30);
    // 0x8003E13C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8003E140: addu        $t4, $t2, $fp
    ctx->r12 = ADD32(ctx->r10, ctx->r30);
    // 0x8003E144: lh          $t5, 0x8($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X8);
    // 0x8003E148: addu        $t7, $t6, $s7
    ctx->r15 = ADD32(ctx->r14, ctx->r23);
    // 0x8003E14C: addiu       $s7, $s7, 0x18
    ctx->r23 = ADD32(ctx->r23, 0X18);
    // 0x8003E150: sh          $t5, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r13;
    // 0x8003E154: lh          $t8, 0x34($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X34);
    // 0x8003E158: addiu       $fp, $fp, 0xA
    ctx->r30 = ADD32(ctx->r30, 0XA);
    // 0x8003E15C: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8003E160: bnel        $at, $zero, L_8003DFB8
    if (ctx->r1 != 0) {
        // 0x8003E164: lw          $t1, 0x10($s2)
        ctx->r9 = MEM_W(ctx->r18, 0X10);
            goto L_8003DFB8;
    }
    goto skip_3;
    // 0x8003E164: lw          $t1, 0x10($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X10);
    skip_3:
L_8003E168:
    // 0x8003E168: lh          $v0, 0x16($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X16);
    // 0x8003E16C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8003E170: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003E174: sh          $v0, 0x38($s1)
    MEM_H(0X38, ctx->r17) = ctx->r2;
    // 0x8003E178: sh          $v0, 0x36($s1)
    MEM_H(0X36, ctx->r17) = ctx->r2;
    // 0x8003E17C: lh          $t9, 0x1A($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X1A);
    // 0x8003E180: sh          $t9, 0x3A($s1)
    MEM_H(0X3A, ctx->r17) = ctx->r25;
    // 0x8003E184: lh          $t0, 0x1C($s2)
    ctx->r8 = MEM_H(ctx->r18, 0X1C);
    // 0x8003E188: sh          $t0, 0x3C($s1)
    MEM_H(0X3C, ctx->r17) = ctx->r8;
    // 0x8003E18C: lw          $t3, 0x20($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X20);
    // 0x8003E190: sw          $t3, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->r11;
    // 0x8003E194: lh          $t1, 0x24($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X24);
    // 0x8003E198: sh          $t1, 0x92($s1)
    MEM_H(0X92, ctx->r17) = ctx->r9;
    // 0x8003E19C: lw          $t2, 0x28($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X28);
    // 0x8003E1A0: jal         0x80035A7C
    // 0x8003E1A4: sw          $t2, 0x80($s1)
    MEM_W(0X80, ctx->r17) = ctx->r10;
    func_80035A7C(rdram, ctx);
        goto after_10;
    // 0x8003E1A4: sw          $t2, 0x80($s1)
    MEM_W(0X80, ctx->r17) = ctx->r10;
    after_10:
    // 0x8003E1A8: b           L_8003E1C4
    // 0x8003E1AC: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
        goto L_8003E1C4;
    // 0x8003E1AC: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_8003E1B0:
    // 0x8003E1B0: lh          $t4, 0x34($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X34);
L_8003E1B4:
    // 0x8003E1B4: addiu       $s2, $s2, 0x2C
    ctx->r18 = ADD32(ctx->r18, 0X2C);
    // 0x8003E1B8: bnel        $t4, $zero, L_8003DEE8
    if (ctx->r12 != 0) {
        // 0x8003E1BC: lw          $t4, 0x0($s2)
        ctx->r12 = MEM_W(ctx->r18, 0X0);
            goto L_8003DEE8;
    }
    goto skip_4;
    // 0x8003E1BC: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    skip_4:
    // 0x8003E1C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003E1C4:
    // 0x8003E1C4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8003E1C8: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8003E1CC: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8003E1D0: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8003E1D4: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8003E1D8: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8003E1DC: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8003E1E0: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8003E1E4: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8003E1E8: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8003E1EC: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8003E1F0: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8003E1F4: jr          $ra
    // 0x8003E1F8: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
    TRACE_RETURN()
    return;
    // 0x8003E1F8: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
;}
RECOMP_FUNC void func_8003E1FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8003E1FC: lh          $t6, 0x8E($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X8E);
    // 0x8003E200: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8003E204: sltiu       $at, $t7, 0x14
    ctx->r1 = ctx->r15 < 0X14 ? 1 : 0;
    // 0x8003E208: beq         $at, $zero, L_8003E3AC
    if (ctx->r1 == 0) {
        // 0x8003E20C: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8003E3AC;
    }
    // 0x8003E20C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8003E210: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003E214: addu        $at, $at, $t7
    gpr jr_addend_8003E21C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8003E218: lw          $t7, 0x7568($at)
    ctx->r15 = ADD32(ctx->r1, 0X7568);
    // 0x8003E21C: jr          $t7
    // 0x8003E220: nop

    switch (jr_addend_8003E21C >> 2) {
        case 0: goto L_8003E224; break;
        case 1: goto L_8003E23C; break;
        case 2: goto L_8003E250; break;
        case 3: goto L_8003E264; break;
        case 4: goto L_8003E278; break;
        case 5: goto L_8003E3AC; break;
        case 6: goto L_8003E2A4; break;
        case 7: goto L_8003E2B8; break;
        case 8: goto L_8003E2CC; break;
        case 9: goto L_8003E2E4; break;
        case 10: goto L_8003E2F8; break;
        case 11: goto L_8003E30C; break;
        case 12: goto L_8003E348; break;
        case 13: goto L_8003E334; break;
        case 14: goto L_8003E370; break;
        case 15: goto L_8003E35C; break;
        case 16: goto L_8003E320; break;
        case 17: goto L_8003E290; break;
        case 18: goto L_8003E384; break;
        case 19: goto L_8003E398; break;
        default: switch_error(__func__, 0x8003E21C, 0x80077568);
    }
    // 0x8003E220: nop

L_8003E224:
    // 0x8003E224: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8003E228: addiu       $t8, $t8, -0x5AE0
    ctx->r24 = ADD32(ctx->r24, -0X5AE0);
    // 0x8003E22C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8003E230: sh          $t9, 0xB4($a0)
    MEM_H(0XB4, ctx->r4) = ctx->r25;
    // 0x8003E234: jr          $ra
    // 0x8003E238: sw          $t8, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->r24;
    TRACE_RETURN()
    return;
    // 0x8003E238: sw          $t8, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->r24;
L_8003E23C:
    // 0x8003E23C: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x8003E240: addiu       $t0, $t0, -0x5AE0
    ctx->r8 = ADD32(ctx->r8, -0X5AE0);
    // 0x8003E244: sw          $t0, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->r8;
    // 0x8003E248: jr          $ra
    // 0x8003E24C: sh          $zero, 0xB4($a0)
    MEM_H(0XB4, ctx->r4) = 0;
    TRACE_RETURN()
    return;
    // 0x8003E24C: sh          $zero, 0xB4($a0)
    MEM_H(0XB4, ctx->r4) = 0;
L_8003E250:
    // 0x8003E250: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x8003E254: addiu       $t1, $t1, -0x5694
    ctx->r9 = ADD32(ctx->r9, -0X5694);
    // 0x8003E258: sw          $t1, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->r9;
    // 0x8003E25C: jr          $ra
    // 0x8003E260: sh          $zero, 0xB4($a0)
    MEM_H(0XB4, ctx->r4) = 0;
    TRACE_RETURN()
    return;
    // 0x8003E260: sh          $zero, 0xB4($a0)
    MEM_H(0XB4, ctx->r4) = 0;
L_8003E264:
    // 0x8003E264: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x8003E268: addiu       $t2, $t2, -0x3998
    ctx->r10 = ADD32(ctx->r10, -0X3998);
    // 0x8003E26C: sw          $t2, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->r10;
    // 0x8003E270: jr          $ra
    // 0x8003E274: sh          $zero, 0xB4($a0)
    MEM_H(0XB4, ctx->r4) = 0;
    TRACE_RETURN()
    return;
    // 0x8003E274: sh          $zero, 0xB4($a0)
    MEM_H(0XB4, ctx->r4) = 0;
L_8003E278:
    // 0x8003E278: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x8003E27C: addiu       $t3, $t3, -0x3998
    ctx->r11 = ADD32(ctx->r11, -0X3998);
    // 0x8003E280: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8003E284: sh          $t4, 0xB4($a0)
    MEM_H(0XB4, ctx->r4) = ctx->r12;
    // 0x8003E288: jr          $ra
    // 0x8003E28C: sw          $t3, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->r11;
    TRACE_RETURN()
    return;
    // 0x8003E28C: sw          $t3, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->r11;
L_8003E290:
    // 0x8003E290: lui         $t5, 0x8004
    ctx->r13 = S32(0X8004 << 16);
    // 0x8003E294: addiu       $t5, $t5, -0x35F4
    ctx->r13 = ADD32(ctx->r13, -0X35F4);
    // 0x8003E298: sw          $t5, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->r13;
    // 0x8003E29C: jr          $ra
    // 0x8003E2A0: sh          $zero, 0xB4($a0)
    MEM_H(0XB4, ctx->r4) = 0;
    TRACE_RETURN()
    return;
    // 0x8003E2A0: sh          $zero, 0xB4($a0)
    MEM_H(0XB4, ctx->r4) = 0;
L_8003E2A4:
    // 0x8003E2A4: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8003E2A8: addiu       $t6, $t6, -0x3BB4
    ctx->r14 = ADD32(ctx->r14, -0X3BB4);
    // 0x8003E2AC: sw          $t6, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->r14;
    // 0x8003E2B0: jr          $ra
    // 0x8003E2B4: sh          $zero, 0xB4($a0)
    MEM_H(0XB4, ctx->r4) = 0;
    TRACE_RETURN()
    return;
    // 0x8003E2B4: sh          $zero, 0xB4($a0)
    MEM_H(0XB4, ctx->r4) = 0;
L_8003E2B8:
    // 0x8003E2B8: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8003E2BC: addiu       $t7, $t7, -0x2478
    ctx->r15 = ADD32(ctx->r15, -0X2478);
    // 0x8003E2C0: sw          $t7, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->r15;
    // 0x8003E2C4: jr          $ra
    // 0x8003E2C8: sh          $zero, 0xB4($a0)
    MEM_H(0XB4, ctx->r4) = 0;
    TRACE_RETURN()
    return;
    // 0x8003E2C8: sh          $zero, 0xB4($a0)
    MEM_H(0XB4, ctx->r4) = 0;
L_8003E2CC:
    // 0x8003E2CC: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8003E2D0: addiu       $t8, $t8, -0x2478
    ctx->r24 = ADD32(ctx->r24, -0X2478);
    // 0x8003E2D4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8003E2D8: sh          $t9, 0xB4($a0)
    MEM_H(0XB4, ctx->r4) = ctx->r25;
    // 0x8003E2DC: jr          $ra
    // 0x8003E2E0: sw          $t8, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->r24;
    TRACE_RETURN()
    return;
    // 0x8003E2E0: sw          $t8, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->r24;
L_8003E2E4:
    // 0x8003E2E4: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x8003E2E8: addiu       $t0, $t0, -0x31FC
    ctx->r8 = ADD32(ctx->r8, -0X31FC);
    // 0x8003E2EC: sw          $t0, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->r8;
    // 0x8003E2F0: jr          $ra
    // 0x8003E2F4: sh          $zero, 0xB4($a0)
    MEM_H(0XB4, ctx->r4) = 0;
    TRACE_RETURN()
    return;
    // 0x8003E2F4: sh          $zero, 0xB4($a0)
    MEM_H(0XB4, ctx->r4) = 0;
L_8003E2F8:
    // 0x8003E2F8: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x8003E2FC: addiu       $t1, $t1, -0x282C
    ctx->r9 = ADD32(ctx->r9, -0X282C);
    // 0x8003E300: sw          $t1, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->r9;
    // 0x8003E304: jr          $ra
    // 0x8003E308: sh          $zero, 0xB4($a0)
    MEM_H(0XB4, ctx->r4) = 0;
    TRACE_RETURN()
    return;
    // 0x8003E308: sh          $zero, 0xB4($a0)
    MEM_H(0XB4, ctx->r4) = 0;
L_8003E30C:
    // 0x8003E30C: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x8003E310: addiu       $t2, $t2, -0x4AF8
    ctx->r10 = ADD32(ctx->r10, -0X4AF8);
    // 0x8003E314: sw          $t2, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->r10;
    // 0x8003E318: jr          $ra
    // 0x8003E31C: sh          $zero, 0xB4($a0)
    MEM_H(0XB4, ctx->r4) = 0;
    TRACE_RETURN()
    return;
    // 0x8003E31C: sh          $zero, 0xB4($a0)
    MEM_H(0XB4, ctx->r4) = 0;
L_8003E320:
    // 0x8003E320: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x8003E324: addiu       $t3, $t3, -0x444C
    ctx->r11 = ADD32(ctx->r11, -0X444C);
    // 0x8003E328: sw          $t3, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->r11;
    // 0x8003E32C: jr          $ra
    // 0x8003E330: sh          $zero, 0xB4($a0)
    MEM_H(0XB4, ctx->r4) = 0;
    TRACE_RETURN()
    return;
    // 0x8003E330: sh          $zero, 0xB4($a0)
    MEM_H(0XB4, ctx->r4) = 0;
L_8003E334:
    // 0x8003E334: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x8003E338: addiu       $t4, $t4, -0x3F2C
    ctx->r12 = ADD32(ctx->r12, -0X3F2C);
    // 0x8003E33C: sw          $t4, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->r12;
    // 0x8003E340: jr          $ra
    // 0x8003E344: sh          $zero, 0xB4($a0)
    MEM_H(0XB4, ctx->r4) = 0;
    TRACE_RETURN()
    return;
    // 0x8003E344: sh          $zero, 0xB4($a0)
    MEM_H(0XB4, ctx->r4) = 0;
L_8003E348:
    // 0x8003E348: lui         $t5, 0x8004
    ctx->r13 = S32(0X8004 << 16);
    // 0x8003E34C: addiu       $t5, $t5, -0x5270
    ctx->r13 = ADD32(ctx->r13, -0X5270);
    // 0x8003E350: sw          $t5, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->r13;
    // 0x8003E354: jr          $ra
    // 0x8003E358: sh          $zero, 0xB4($a0)
    MEM_H(0XB4, ctx->r4) = 0;
    TRACE_RETURN()
    return;
    // 0x8003E358: sh          $zero, 0xB4($a0)
    MEM_H(0XB4, ctx->r4) = 0;
L_8003E35C:
    // 0x8003E35C: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8003E360: addiu       $t6, $t6, -0x4E7C
    ctx->r14 = ADD32(ctx->r14, -0X4E7C);
    // 0x8003E364: sw          $t6, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->r14;
    // 0x8003E368: jr          $ra
    // 0x8003E36C: sh          $zero, 0xB4($a0)
    MEM_H(0XB4, ctx->r4) = 0;
    TRACE_RETURN()
    return;
    // 0x8003E36C: sh          $zero, 0xB4($a0)
    MEM_H(0XB4, ctx->r4) = 0;
L_8003E370:
    // 0x8003E370: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8003E374: addiu       $t7, $t7, -0x2F10
    ctx->r15 = ADD32(ctx->r15, -0X2F10);
    // 0x8003E378: sw          $t7, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->r15;
    // 0x8003E37C: jr          $ra
    // 0x8003E380: sh          $zero, 0xB4($a0)
    MEM_H(0XB4, ctx->r4) = 0;
    TRACE_RETURN()
    return;
    // 0x8003E380: sh          $zero, 0xB4($a0)
    MEM_H(0XB4, ctx->r4) = 0;
L_8003E384:
    // 0x8003E384: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8003E388: addiu       $t8, $t8, -0x2204
    ctx->r24 = ADD32(ctx->r24, -0X2204);
    // 0x8003E38C: sw          $t8, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->r24;
    // 0x8003E390: jr          $ra
    // 0x8003E394: sh          $zero, 0xB4($a0)
    MEM_H(0XB4, ctx->r4) = 0;
    TRACE_RETURN()
    return;
    // 0x8003E394: sh          $zero, 0xB4($a0)
    MEM_H(0XB4, ctx->r4) = 0;
L_8003E398:
    // 0x8003E398: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x8003E39C: addiu       $t9, $t9, -0x4680
    ctx->r25 = ADD32(ctx->r25, -0X4680);
    // 0x8003E3A0: sw          $t9, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->r25;
    // 0x8003E3A4: jr          $ra
    // 0x8003E3A8: sh          $zero, 0xB4($a0)
    MEM_H(0XB4, ctx->r4) = 0;
    TRACE_RETURN()
    return;
    // 0x8003E3A8: sh          $zero, 0xB4($a0)
    MEM_H(0XB4, ctx->r4) = 0;
L_8003E3AC:
    // 0x8003E3AC: sw          $zero, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = 0;
    // 0x8003E3B0: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8003E3B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8003E3B8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8003E3BC: lw          $t6, 0x6AC8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6AC8);
    // 0x8003E3C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003E3C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003E3C8: andi        $t7, $t6, 0x8
    ctx->r15 = ctx->r14 & 0X8;
    // 0x8003E3CC: bnel        $t7, $zero, L_8003E3EC
    if (ctx->r15 != 0) {
        // 0x8003E3D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8003E3EC;
    }
    goto skip_0;
    // 0x8003E3D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8003E3D4: lw          $v0, 0xB0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB0);
    // 0x8003E3D8: beql        $v0, $zero, L_8003E3EC
    if (ctx->r2 == 0) {
        // 0x8003E3DC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8003E3EC;
    }
    goto skip_1;
    // 0x8003E3DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8003E3E0: jalr        $v0
    // 0x8003E3E4: lh          $a1, 0xB4($a0)
    ctx->r5 = MEM_H(ctx->r4, 0XB4);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8003E3E4: lh          $a1, 0xB4($a0)
    ctx->r5 = MEM_H(ctx->r4, 0XB4);
    after_0:
    // 0x8003E3E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003E3EC:
    // 0x8003E3EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003E3F0: jr          $ra
    TRACE_RETURN()
    return;
;}
static void func_8003E3F8_entry(uint8_t* rdram, recomp_context* ctx, unsigned entry) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    if (entry == 1) goto indirect_8003E4B0;

    // 0x8003E3F8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8003E3FC: lh          $t6, -0x6B9C($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X6B9C);
    // 0x8003E400: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8003E404: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003E408: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8003E40C: beq         $t6, $zero, L_8003E494
    if (ctx->r14 == 0) {
        // 0x8003E410: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_8003E494;
    }
    // 0x8003E410: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8003E414: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8003E418: lw          $t7, -0x6630($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6630);
    // 0x8003E41C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003E420: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8003E424: bne         $t7, $at, L_8003E448
    if (ctx->r15 != ctx->r1) {
        // 0x8003E428: nop
    
            goto L_8003E448;
    }
    // 0x8003E428: nop

    // 0x8003E42C: jal         0x8003DAFC
    // 0x8003E430: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    func_8003DAFC(rdram, ctx);
        goto after_0;
    // 0x8003E430: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_0:
    // 0x8003E434: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x8003E438: sra         $t8, $v1, 16
    ctx->r24 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8003E43C: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x8003E440: b           L_8003E448
    // 0x8003E444: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
        goto L_8003E448;
    // 0x8003E444: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
L_8003E448:
    // 0x8003E448: beq         $v1, $zero, L_8003E494
    if (ctx->r3 == 0) {
        // 0x8003E44C: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_8003E494;
    }
    // 0x8003E44C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8003E450: lwc1        $f0, -0x6B98($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6B98);
    // 0x8003E454: lwc1        $f4, 0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8003E458: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8003E45C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8003E460: nop

    // 0x8003E464: bc1fl       L_8003E498
    if (!c1cs) {
        // 0x8003E468: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8003E498;
    }
    goto skip_0;
    // 0x8003E468: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8003E46C: lwc1        $f6, 0x0($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8003E470: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8003E474: lh          $a1, 0x36($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X36);
    // 0x8003E478: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x8003E47C: lwc1        $f8, 0x8($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8003E480: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003E484: jal         0x80042F80
    // 0x8003E488: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    func_80042F80(rdram, ctx);
        goto after_1;
    // 0x8003E488: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x8003E48C: b           L_8003E498
    // 0x8003E490: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8003E498;
    // 0x8003E490: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003E494:
    // 0x8003E494: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003E498:
    // 0x8003E498: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003E49C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8003E4A0: jr          $ra
    // 0x8003E4A4: nop

    TRACE_RETURN()
    return;
    // 0x8003E4A4: nop

    // 0x8003E4A8: nop

    // 0x8003E4AC: nop

indirect_8003E4B0:
    // 0x8003E4B0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8003E4B4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8003E4B8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8003E4BC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8003E4C0: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8003E4C4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8003E4C8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8003E4CC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8003E4D0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8003E4D4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8003E4D8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8003E4DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003E4E0: jal         0x8003F258
    // 0x8003E4E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8003F258(rdram, ctx);
        goto after_2;
    // 0x8003E4E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x8003E4E8: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8003E4EC: addiu       $s2, $s2, -0x658C
    ctx->r18 = ADD32(ctx->r18, -0X658C);
    // 0x8003E4F0: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x8003E4F4: jal         0x80040068
    // 0x8003E4F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80040068(rdram, ctx);
        goto after_3;
    // 0x8003E4F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x8003E4FC: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x8003E500: addiu       $s3, $s3, -0x6588
    ctx->r19 = ADD32(ctx->r19, -0X6588);
    // 0x8003E504: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x8003E508: jal         0x8003E6A0
    // 0x8003E50C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8003E6A0(rdram, ctx);
        goto after_4;
    // 0x8003E50C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x8003E510: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x8003E514: addiu       $s4, $s4, -0x6584
    ctx->r20 = ADD32(ctx->r20, -0X6584);
    // 0x8003E518: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    // 0x8003E51C: jal         0x80041994
    // 0x8003E520: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80041994(rdram, ctx);
        goto after_5;
    // 0x8003E520: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x8003E524: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x8003E528: addiu       $s5, $s5, -0x6580
    ctx->r21 = ADD32(ctx->r21, -0X6580);
    // 0x8003E52C: sw          $v0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r2;
    // 0x8003E530: jal         0x8003F258
    // 0x8003E534: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8003F258(rdram, ctx);
        goto after_6;
    // 0x8003E534: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x8003E538: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x8003E53C: addiu       $s6, $s6, -0x657C
    ctx->r22 = ADD32(ctx->r22, -0X657C);
    // 0x8003E540: sw          $v0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r2;
    // 0x8003E544: jal         0x80040068
    // 0x8003E548: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80040068(rdram, ctx);
        goto after_7;
    // 0x8003E548: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x8003E54C: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x8003E550: addiu       $s7, $s7, -0x6590
    ctx->r23 = ADD32(ctx->r23, -0X6590);
    // 0x8003E554: sw          $v0, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r2;
    // 0x8003E558: jal         0x8003E6A0
    // 0x8003E55C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8003E6A0(rdram, ctx);
        goto after_8;
    // 0x8003E55C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
    // 0x8003E560: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x8003E564: addiu       $fp, $fp, -0x6578
    ctx->r30 = ADD32(ctx->r30, -0X6578);
    // 0x8003E568: sw          $v0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r2;
    // 0x8003E56C: jal         0x80041994
    // 0x8003E570: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80041994(rdram, ctx);
        goto after_9;
    // 0x8003E570: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_9:
    // 0x8003E574: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8003E578: sw          $v0, -0x6574($at)
    MEM_W(-0X6574, ctx->r1) = ctx->r2;
    // 0x8003E57C: addiu       $s0, $zero, -0x2
    ctx->r16 = ADD32(0, -0X2);
    // 0x8003E580: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_8003E584:
    // 0x8003E584: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003E588: bne         $v0, $at, L_8003E5E8
    if (ctx->r2 != ctx->r1) {
        // 0x8003E58C: nop
    
            goto L_8003E5E8;
    }
    // 0x8003E58C: nop

    // 0x8003E590: jal         0x8003FF94
    // 0x8003E594: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    func_8003FF94(rdram, ctx);
        goto after_10;
    // 0x8003E594: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_10:
    // 0x8003E598: jal         0x800417F4
    // 0x8003E59C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    func_800417F4(rdram, ctx);
        goto after_11;
    // 0x8003E59C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    after_11:
    // 0x8003E5A0: jal         0x8003F184
    // 0x8003E5A4: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    func_8003F184(rdram, ctx);
        goto after_12;
    // 0x8003E5A4: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    after_12:
    // 0x8003E5A8: jal         0x800422EC
    // 0x8003E5AC: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    func_800422EC(rdram, ctx);
        goto after_13;
    // 0x8003E5AC: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    after_13:
    // 0x8003E5B0: jal         0x8003FF94
    // 0x8003E5B4: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    func_8003FF94(rdram, ctx);
        goto after_14;
    // 0x8003E5B4: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    after_14:
    // 0x8003E5B8: jal         0x800417F4
    // 0x8003E5BC: lw          $a0, 0x0($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X0);
    func_800417F4(rdram, ctx);
        goto after_15;
    // 0x8003E5BC: lw          $a0, 0x0($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X0);
    after_15:
    // 0x8003E5C0: jal         0x8003F184
    // 0x8003E5C4: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    func_8003F184(rdram, ctx);
        goto after_16;
    // 0x8003E5C4: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    after_16:
    // 0x8003E5C8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8003E5CC: jal         0x800422EC
    // 0x8003E5D0: lw          $a0, -0x6574($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6574);
    func_800422EC(rdram, ctx);
        goto after_17;
    // 0x8003E5D0: lw          $a0, -0x6574($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6574);
    after_17:
    // 0x8003E5D4: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_8003E5D8:
    // 0x8003E5D8: jal         0x8000798C
    // 0x8003E5DC: nop

    func_8000798C(rdram, ctx);
        goto after_18;
    // 0x8003E5DC: nop

    after_18:
    // 0x8003E5E0: b           L_8003E5D8
    // 0x8003E5E4: nop

        goto L_8003E5D8;
    // 0x8003E5E4: nop

L_8003E5E8:
    // 0x8003E5E8: bne         $s0, $v0, L_8003E60C
    if (ctx->r16 != ctx->r2) {
        // 0x8003E5EC: nop
    
            goto L_8003E60C;
    }
    // 0x8003E5EC: nop

    // 0x8003E5F0: bne         $s0, $v0, L_8003E60C
    if (ctx->r16 != ctx->r2) {
        // 0x8003E5F4: nop
    
            goto L_8003E60C;
    }
    // 0x8003E5F4: nop

L_8003E5F8:
    // 0x8003E5F8: jal         0x8000798C
    // 0x8003E5FC: nop

    func_8000798C(rdram, ctx);
        goto after_19;
    // 0x8003E5FC: nop

    after_19:
    // 0x8003E600: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8003E604: beq         $s0, $t6, L_8003E5F8
    if (ctx->r16 == ctx->r14) {
        // 0x8003E608: nop
    
            goto L_8003E5F8;
    }
    // 0x8003E608: nop

L_8003E60C:
    // 0x8003E60C: jal         0x8003F974
    // 0x8003E610: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    func_8003F974(rdram, ctx);
        goto after_20;
    // 0x8003E610: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_20:
    // 0x8003E614: jal         0x80040880
    // 0x8003E618: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    func_80040880(rdram, ctx);
        goto after_21;
    // 0x8003E618: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    after_21:
    // 0x8003E61C: jal         0x8003EC24
    // 0x8003E620: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    func_8003EC24(rdram, ctx);
        goto after_22;
    // 0x8003E620: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    after_22:
    // 0x8003E624: jal         0x80041EF4
    // 0x8003E628: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    func_80041EF4(rdram, ctx);
        goto after_23;
    // 0x8003E628: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    after_23:
    // 0x8003E62C: jal         0x8003F974
    // 0x8003E630: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    func_8003F974(rdram, ctx);
        goto after_24;
    // 0x8003E630: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    after_24:
    // 0x8003E634: jal         0x80040880
    // 0x8003E638: lw          $a0, 0x0($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X0);
    func_80040880(rdram, ctx);
        goto after_25;
    // 0x8003E638: lw          $a0, 0x0($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X0);
    after_25:
    // 0x8003E63C: jal         0x8003EC24
    // 0x8003E640: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    func_8003EC24(rdram, ctx);
        goto after_26;
    // 0x8003E640: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    after_26:
    // 0x8003E644: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8003E648: jal         0x80041EF4
    // 0x8003E64C: lw          $a0, -0x6574($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6574);
    func_80041EF4(rdram, ctx);
        goto after_27;
    // 0x8003E64C: lw          $a0, -0x6574($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6574);
    after_27:
    // 0x8003E650: jal         0x8000798C
    // 0x8003E654: nop

    func_8000798C(rdram, ctx);
        goto after_28;
    // 0x8003E654: nop

    after_28:
    // 0x8003E658: b           L_8003E584
    // 0x8003E65C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
        goto L_8003E584;
    // 0x8003E65C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8003E660: nop

    // 0x8003E664: nop

    // 0x8003E668: nop

    // 0x8003E66C: nop

    // 0x8003E670: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8003E674: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003E678: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8003E67C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8003E680: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8003E684: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8003E688: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8003E68C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8003E690: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8003E694: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8003E698: jr          $ra
    // 0x8003E69C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    TRACE_RETURN()
    return;
    // 0x8003E69C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8003E3F8(uint8_t* rdram, recomp_context* ctx) { func_8003E3F8_entry(rdram, ctx, 0); }
RECOMP_FUNC void func_8003E4B0(uint8_t* rdram, recomp_context* ctx) { func_8003E3F8_entry(rdram, ctx, 1); }

RECOMP_FUNC void func_8003E6A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8003E6A0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8003E6A4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8003E6A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003E6AC: sll         $s0, $a0, 16
    ctx->r16 = S32(ctx->r4 << 16);
    // 0x8003E6B0: lui         $s4, 0x801A
    ctx->r20 = S32(0X801A << 16);
    // 0x8003E6B4: addiu       $s4, $s4, 0x2800
    ctx->r20 = ADD32(ctx->r20, 0X2800);
    // 0x8003E6B8: sra         $t6, $s0, 16
    ctx->r14 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8003E6BC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8003E6C0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8003E6C4: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x8003E6C8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8003E6CC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8003E6D0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8003E6D4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8003E6D8: jal         0x80004364
    // 0x8003E6DC: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x8003E6DC: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x8003E6E0: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8003E6E4: sh          $s0, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r16;
    // 0x8003E6E8: beq         $s0, $zero, L_8003E704
    if (ctx->r16 == 0) {
        // 0x8003E6EC: sh          $zero, 0x4($v0)
        MEM_H(0X4, ctx->r2) = 0;
            goto L_8003E704;
    }
    // 0x8003E6EC: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x8003E6F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003E6F4: beq         $s0, $at, L_8003E718
    if (ctx->r16 == ctx->r1) {
        // 0x8003E6F8: addiu       $t9, $zero, 0xA
        ctx->r25 = ADD32(0, 0XA);
            goto L_8003E718;
    }
    // 0x8003E6F8: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x8003E6FC: b           L_8003E728
    // 0x8003E700: lh          $a1, 0x6($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X6);
        goto L_8003E728;
    // 0x8003E700: lh          $a1, 0x6($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X6);
L_8003E704:
    // 0x8003E704: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x8003E708: addiu       $t8, $zero, 0x50
    ctx->r24 = ADD32(0, 0X50);
    // 0x8003E70C: sh          $t7, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r15;
    // 0x8003E710: b           L_8003E724
    // 0x8003E714: sh          $t8, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r24;
        goto L_8003E724;
    // 0x8003E714: sh          $t8, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r24;
L_8003E718:
    // 0x8003E718: addiu       $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
    // 0x8003E71C: sh          $t9, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r25;
    // 0x8003E720: sh          $t0, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r8;
L_8003E724:
    // 0x8003E724: lh          $a1, 0x6($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X6);
L_8003E728:
    // 0x8003E728: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8003E72C: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x8003E730: jal         0x80004364
    // 0x8003E734: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    func_80004364(rdram, ctx);
        goto after_1;
    // 0x8003E734: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    after_1:
    // 0x8003E738: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8003E73C: lh          $t2, 0x6($s3)
    ctx->r10 = MEM_H(ctx->r19, 0X6);
    // 0x8003E740: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8003E744: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8003E748: blez        $t2, L_8003E784
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8003E74C: addiu       $s2, $zero, -0x1
        ctx->r18 = ADD32(0, -0X1);
            goto L_8003E784;
    }
    // 0x8003E74C: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x8003E750: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_8003E754:
    // 0x8003E754: jal         0x80004364
    // 0x8003E758: addiu       $a1, $zero, 0x84
    ctx->r5 = ADD32(0, 0X84);
    func_80004364(rdram, ctx);
        goto after_2;
    // 0x8003E758: addiu       $a1, $zero, 0x84
    ctx->r5 = ADD32(0, 0X84);
    after_2:
    // 0x8003E75C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8003E760: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x8003E764: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8003E768: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8003E76C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8003E770: sh          $s2, 0xA($t3)
    MEM_H(0XA, ctx->r11) = ctx->r18;
    // 0x8003E774: lh          $t4, 0x6($s3)
    ctx->r12 = MEM_H(ctx->r19, 0X6);
    // 0x8003E778: slt         $at, $s1, $t4
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8003E77C: bnel        $at, $zero, L_8003E754
    if (ctx->r1 != 0) {
        // 0x8003E780: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_8003E754;
    }
    goto skip_0;
    // 0x8003E780: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_0:
L_8003E784:
    // 0x8003E784: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8003E788: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x8003E78C: sw          $t5, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r13;
    // 0x8003E790: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8003E794: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8003E798: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8003E79C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8003E7A0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8003E7A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003E7A8: jr          $ra
    // 0x8003E7AC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    TRACE_RETURN()
    return;
    // 0x8003E7AC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8003E7B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8003E7B0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8003E7B4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8003E7B8: lh          $t8, -0x6B94($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X6B94);
    // 0x8003E7BC: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8003E7C0: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8003E7C4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8003E7C8: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8003E7CC: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8003E7D0: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8003E7D4: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8003E7D8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8003E7DC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8003E7E0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8003E7E4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8003E7E8: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8003E7EC: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8003E7F0: beq         $t8, $zero, L_8003EBF8
    if (ctx->r24 == 0) {
        // 0x8003E7F4: sw          $a2, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r6;
            goto L_8003EBF8;
    }
    // 0x8003E7F4: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8003E7F8: beq         $t7, $zero, L_8003E818
    if (ctx->r15 == 0) {
        // 0x8003E7FC: lui         $s1, 0x8013
        ctx->r17 = S32(0X8013 << 16);
            goto L_8003E818;
    }
    // 0x8003E7FC: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8003E800: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003E804: beq         $t7, $at, L_8003E838
    if (ctx->r15 == ctx->r1) {
        // 0x8003E808: lui         $s1, 0x8013
        ctx->r17 = S32(0X8013 << 16);
            goto L_8003E838;
    }
    // 0x8003E808: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8003E80C: lh          $s2, 0x3E($sp)
    ctx->r18 = MEM_H(ctx->r29, 0X3E);
    // 0x8003E810: b           L_8003E854
    // 0x8003E814: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
        goto L_8003E854;
    // 0x8003E814: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
L_8003E818:
    // 0x8003E818: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x8003E81C: lw          $s1, -0x6584($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X6584);
    // 0x8003E820: jal         0x80049CFC
    // 0x8003E824: addiu       $a0, $a0, 0x75C0
    ctx->r4 = ADD32(ctx->r4, 0X75C0);
    func_80049CFC(rdram, ctx);
        goto after_0;
    // 0x8003E824: addiu       $a0, $a0, 0x75C0
    ctx->r4 = ADD32(ctx->r4, 0X75C0);
    after_0:
    // 0x8003E828: sll         $s2, $v0, 16
    ctx->r18 = S32(ctx->r2 << 16);
    // 0x8003E82C: sra         $t9, $s2, 16
    ctx->r25 = S32(SIGNED(ctx->r18) >> 16);
    // 0x8003E830: b           L_8003E854
    // 0x8003E834: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
        goto L_8003E854;
    // 0x8003E834: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
L_8003E838:
    // 0x8003E838: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x8003E83C: lw          $s1, -0x6578($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X6578);
    // 0x8003E840: jal         0x80049CFC
    // 0x8003E844: addiu       $a0, $a0, 0x75C8
    ctx->r4 = ADD32(ctx->r4, 0X75C8);
    func_80049CFC(rdram, ctx);
        goto after_1;
    // 0x8003E844: addiu       $a0, $a0, 0x75C8
    ctx->r4 = ADD32(ctx->r4, 0X75C8);
    after_1:
    // 0x8003E848: sll         $s2, $v0, 16
    ctx->r18 = S32(ctx->r2 << 16);
    // 0x8003E84C: sra         $t0, $s2, 16
    ctx->r8 = S32(SIGNED(ctx->r18) >> 16);
    // 0x8003E850: or          $s2, $t0, $zero
    ctx->r18 = ctx->r8 | 0;
L_8003E854:
    // 0x8003E854: lh          $t1, 0x52($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X52);
    // 0x8003E858: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x8003E85C: addiu       $s6, $zero, 0x64
    ctx->r22 = ADD32(0, 0X64);
    // 0x8003E860: blez        $t1, L_8003EBF8
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8003E864: addiu       $s5, $zero, 0xC
        ctx->r21 = ADD32(0, 0XC);
            goto L_8003EBF8;
    }
    // 0x8003E864: addiu       $s5, $zero, 0xC
    ctx->r21 = ADD32(0, 0XC);
    // 0x8003E868: lh          $s4, 0x3C($sp)
    ctx->r20 = MEM_H(ctx->r29, 0X3C);
    // 0x8003E86C: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x8003E870: lh          $a2, 0x6($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X6);
L_8003E874:
    // 0x8003E874: lh          $t2, 0x4($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X4);
    // 0x8003E878: slt         $at, $t2, $a2
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8003E87C: beql        $at, $zero, L_8003EBFC
    if (ctx->r1 == 0) {
        // 0x8003E880: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8003EBFC;
    }
    goto skip_0;
    // 0x8003E880: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x8003E884: blez        $a2, L_8003E8D4
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8003E888: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8003E8D4;
    }
    // 0x8003E888: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003E88C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_8003E890:
    // 0x8003E890: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8003E894: lh          $t3, 0x8($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X8);
    // 0x8003E898: bnel        $t3, $zero, L_8003E8C8
    if (ctx->r11 != 0) {
        // 0x8003E89C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8003E8C8;
    }
    goto skip_1;
    // 0x8003E89C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_1:
    // 0x8003E8A0: lh          $a0, 0xA($v1)
    ctx->r4 = MEM_H(ctx->r3, 0XA);
    // 0x8003E8A4: sll         $s4, $a1, 16
    ctx->r20 = S32(ctx->r5 << 16);
    // 0x8003E8A8: sra         $t4, $s4, 16
    ctx->r12 = S32(SIGNED(ctx->r20) >> 16);
    // 0x8003E8AC: beq         $s2, $a0, L_8003E8BC
    if (ctx->r18 == ctx->r4) {
        // 0x8003E8B0: or          $s4, $t4, $zero
        ctx->r20 = ctx->r12 | 0;
            goto L_8003E8BC;
    }
    // 0x8003E8B0: or          $s4, $t4, $zero
    ctx->r20 = ctx->r12 | 0;
    // 0x8003E8B4: bnel        $s3, $a0, L_8003E8C8
    if (ctx->r19 != ctx->r4) {
        // 0x8003E8B8: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8003E8C8;
    }
    goto skip_2;
    // 0x8003E8B8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_2:
L_8003E8BC:
    // 0x8003E8BC: b           L_8003E8D8
    // 0x8003E8C0: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
        goto L_8003E8D8;
    // 0x8003E8C0: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x8003E8C4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8003E8C8:
    // 0x8003E8C8: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8003E8CC: bne         $at, $zero, L_8003E890
    if (ctx->r1 != 0) {
        // 0x8003E8D0: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8003E890;
    }
    // 0x8003E8D0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8003E8D4:
    // 0x8003E8D4: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
L_8003E8D8:
    // 0x8003E8D8: sll         $s0, $s4, 2
    ctx->r16 = S32(ctx->r20 << 2);
    // 0x8003E8DC: addu        $t6, $t5, $s0
    ctx->r14 = ADD32(ctx->r13, ctx->r16);
    // 0x8003E8E0: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x8003E8E4: lh          $v0, 0xA($a1)
    ctx->r2 = MEM_H(ctx->r5, 0XA);
    // 0x8003E8E8: beql        $s2, $v0, L_8003E974
    if (ctx->r18 == ctx->r2) {
        // 0x8003E8EC: sh          $zero, 0xC($a1)
        MEM_H(0XC, ctx->r5) = 0;
            goto L_8003E974;
    }
    goto skip_3;
    // 0x8003E8EC: sh          $zero, 0xC($a1)
    MEM_H(0XC, ctx->r5) = 0;
    skip_3:
    // 0x8003E8F0: beq         $s3, $v0, L_8003E900
    if (ctx->r19 == ctx->r2) {
        // 0x8003E8F4: nop
    
            goto L_8003E900;
    }
    // 0x8003E8F4: nop

    // 0x8003E8F8: jal         0x8004A0C4
    // 0x8003E8FC: lw          $a0, 0x4($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X4);
    func_8004A0C4(rdram, ctx);
        goto after_2;
    // 0x8003E8FC: lw          $a0, 0x4($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X4);
    after_2:
L_8003E900:
    // 0x8003E900: jal         0x80049D80
    // 0x8003E904: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80049D80(rdram, ctx);
        goto after_3;
    // 0x8003E904: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x8003E908: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8003E90C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003E910: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8003E914: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8003E918: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x8003E91C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8003E920: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x8003E924: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8003E928: jal         0x80049DFC
    // 0x8003E92C: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    func_80049DFC(rdram, ctx);
        goto after_4;
    // 0x8003E92C: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    after_4:
    // 0x8003E930: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x8003E934: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x8003E938: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8003E93C: sw          $v0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r2;
    // 0x8003E940: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8003E944: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x8003E948: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8003E94C: jal         0x8004A148
    // 0x8003E950: lw          $a0, 0x4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X4);
    func_8004A148(rdram, ctx);
        goto after_5;
    // 0x8003E950: lw          $a0, 0x4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X4);
    after_5:
    // 0x8003E954: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8003E958: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x8003E95C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8003E960: sh          $s2, 0xA($t1)
    MEM_H(0XA, ctx->r9) = ctx->r18;
    // 0x8003E964: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x8003E968: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x8003E96C: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    // 0x8003E970: sh          $zero, 0xC($a1)
    MEM_H(0XC, ctx->r5) = 0;
L_8003E974:
    // 0x8003E974: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8003E978: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003E97C: lwc1        $f4, 0x7688($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7688);
    // 0x8003E980: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x8003E984: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8003E988: addiu       $t0, $zero, 0x4B
    ctx->r8 = ADD32(0, 0X4B);
    // 0x8003E98C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003E990: swc1        $f4, 0x74($t6)
    MEM_W(0X74, ctx->r14) = ctx->f4.u32l;
    // 0x8003E994: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8003E998: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8003E99C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8003E9A0: sh          $s6, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r22;
    // 0x8003E9A4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x8003E9A8: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x8003E9AC: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8003E9B0: sh          $t0, 0x80($t3)
    MEM_H(0X80, ctx->r11) = ctx->r8;
    // 0x8003E9B4: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8003E9B8: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x8003E9BC: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8003E9C0: sh          $zero, 0x82($t6)
    MEM_H(0X82, ctx->r14) = 0;
    // 0x8003E9C4: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
L_8003E9C8:
    // 0x8003E9C8: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8003E9CC: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8003E9D0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003E9D4: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8003E9D8: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8003E9DC: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x8003E9E0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003E9E4: bne         $v0, $s5, L_8003E9C8
    if (ctx->r2 != ctx->r21) {
        // 0x8003E9E8: swc1        $f6, 0x50($t1)
        MEM_W(0X50, ctx->r9) = ctx->f6.u32l;
            goto L_8003E9C8;
    }
    // 0x8003E9E8: swc1        $f6, 0x50($t1)
    MEM_W(0X50, ctx->r9) = ctx->f6.u32l;
    // 0x8003E9EC: jal         0x8000E35C
    // 0x8003E9F0: nop

    func_8000E35C(rdram, ctx);
        goto after_6;
    // 0x8003E9F0: nop

    after_6:
    // 0x8003E9F4: andi        $t2, $v0, 0xFF
    ctx->r10 = ctx->r2 & 0XFF;
    // 0x8003E9F8: addiu       $t0, $t2, 0xA
    ctx->r8 = ADD32(ctx->r10, 0XA);
    // 0x8003E9FC: div         $zero, $t0, $s6
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r22))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r22)));
    // 0x8003EA00: mflo        $t3
    ctx->r11 = lo;
    // 0x8003EA04: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8003EA08: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8003EA0C: bne         $s6, $zero, L_8003EA18
    if (ctx->r22 != 0) {
        // 0x8003EA10: nop
    
            goto L_8003EA18;
    }
    // 0x8003EA10: nop

    // 0x8003EA14: break       7
    do_break(2147740180);
L_8003EA18:
    // 0x8003EA18: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003EA1C: bne         $s6, $at, L_8003EA30
    if (ctx->r22 != ctx->r1) {
        // 0x8003EA20: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8003EA30;
    }
    // 0x8003EA20: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8003EA24: bne         $t0, $at, L_8003EA30
    if (ctx->r8 != ctx->r1) {
        // 0x8003EA28: nop
    
            goto L_8003EA30;
    }
    // 0x8003EA28: nop

    // 0x8003EA2C: break       6
    do_break(2147740204);
L_8003EA30:
    // 0x8003EA30: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8003EA34: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x8003EA38: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8003EA3C: jal         0x8000E35C
    // 0x8003EA40: swc1        $f10, 0x68($t6)
    MEM_W(0X68, ctx->r14) = ctx->f10.u32l;
    func_8000E35C(rdram, ctx);
        goto after_7;
    // 0x8003EA40: swc1        $f10, 0x68($t6)
    MEM_W(0X68, ctx->r14) = ctx->f10.u32l;
    after_7:
    // 0x8003EA44: andi        $t7, $v0, 0x1FF
    ctx->r15 = ctx->r2 & 0X1FF;
    // 0x8003EA48: addiu       $t8, $t7, 0xA
    ctx->r24 = ADD32(ctx->r15, 0XA);
    // 0x8003EA4C: div         $zero, $t8, $s6
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r22))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r22)));
    // 0x8003EA50: mflo        $t9
    ctx->r25 = lo;
    // 0x8003EA54: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8003EA58: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x8003EA5C: bne         $s6, $zero, L_8003EA68
    if (ctx->r22 != 0) {
        // 0x8003EA60: nop
    
            goto L_8003EA68;
    }
    // 0x8003EA60: nop

    // 0x8003EA64: break       7
    do_break(2147740260);
L_8003EA68:
    // 0x8003EA68: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003EA6C: bne         $s6, $at, L_8003EA80
    if (ctx->r22 != ctx->r1) {
        // 0x8003EA70: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8003EA80;
    }
    // 0x8003EA70: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8003EA74: bne         $t8, $at, L_8003EA80
    if (ctx->r24 != ctx->r1) {
        // 0x8003EA78: nop
    
            goto L_8003EA80;
    }
    // 0x8003EA78: nop

    // 0x8003EA7C: break       6
    do_break(2147740284);
L_8003EA80:
    // 0x8003EA80: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003EA84: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x8003EA88: lw          $t0, 0x0($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X0);
    // 0x8003EA8C: jal         0x8000E35C
    // 0x8003EA90: swc1        $f18, 0x6C($t0)
    MEM_W(0X6C, ctx->r8) = ctx->f18.u32l;
    func_8000E35C(rdram, ctx);
        goto after_8;
    // 0x8003EA90: swc1        $f18, 0x6C($t0)
    MEM_W(0X6C, ctx->r8) = ctx->f18.u32l;
    after_8:
    // 0x8003EA94: andi        $t3, $v0, 0xFF
    ctx->r11 = ctx->r2 & 0XFF;
    // 0x8003EA98: addiu       $t4, $t3, 0xA
    ctx->r12 = ADD32(ctx->r11, 0XA);
    // 0x8003EA9C: div         $zero, $t4, $s6
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r22))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r22)));
    // 0x8003EAA0: mflo        $t5
    ctx->r13 = lo;
    // 0x8003EAA4: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x8003EAA8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8003EAAC: bne         $s6, $zero, L_8003EAB8
    if (ctx->r22 != 0) {
        // 0x8003EAB0: nop
    
            goto L_8003EAB8;
    }
    // 0x8003EAB0: nop

    // 0x8003EAB4: break       7
    do_break(2147740340);
L_8003EAB8:
    // 0x8003EAB8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003EABC: bne         $s6, $at, L_8003EAD0
    if (ctx->r22 != ctx->r1) {
        // 0x8003EAC0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8003EAD0;
    }
    // 0x8003EAC0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8003EAC4: bne         $t4, $at, L_8003EAD0
    if (ctx->r12 != ctx->r1) {
        // 0x8003EAC8: nop
    
            goto L_8003EAD0;
    }
    // 0x8003EAC8: nop

    // 0x8003EACC: break       6
    do_break(2147740364);
L_8003EAD0:
    // 0x8003EAD0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003EAD4: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x8003EAD8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8003EADC: jal         0x8000E35C
    // 0x8003EAE0: swc1        $f6, 0x70($t8)
    MEM_W(0X70, ctx->r24) = ctx->f6.u32l;
    func_8000E35C(rdram, ctx);
        goto after_9;
    // 0x8003EAE0: swc1        $f6, 0x70($t8)
    MEM_W(0X70, ctx->r24) = ctx->f6.u32l;
    after_9:
    // 0x8003EAE4: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x8003EAE8: beq         $t9, $zero, L_8003EB08
    if (ctx->r25 == 0) {
        // 0x8003EAEC: nop
    
            goto L_8003EB08;
    }
    // 0x8003EAEC: nop

    // 0x8003EAF0: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x8003EAF4: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x8003EAF8: lw          $a1, 0x0($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X0);
    // 0x8003EAFC: lwc1        $f8, 0x68($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X68);
    // 0x8003EB00: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8003EB04: swc1        $f10, 0x68($a1)
    MEM_W(0X68, ctx->r5) = ctx->f10.u32l;
L_8003EB08:
    // 0x8003EB08: jal         0x8000E35C
    // 0x8003EB0C: nop

    func_8000E35C(rdram, ctx);
        goto after_10;
    // 0x8003EB0C: nop

    after_10:
    // 0x8003EB10: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x8003EB14: beq         $t0, $zero, L_8003EB34
    if (ctx->r8 == 0) {
        // 0x8003EB18: nop
    
            goto L_8003EB34;
    }
    // 0x8003EB18: nop

    // 0x8003EB1C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x8003EB20: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x8003EB24: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    // 0x8003EB28: lwc1        $f16, 0x70($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X70);
    // 0x8003EB2C: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x8003EB30: swc1        $f18, 0x70($a1)
    MEM_W(0X70, ctx->r5) = ctx->f18.u32l;
L_8003EB34:
    // 0x8003EB34: jal         0x8000E35C
    // 0x8003EB38: nop

    func_8000E35C(rdram, ctx);
        goto after_11;
    // 0x8003EB38: nop

    after_11:
    // 0x8003EB3C: addiu       $at, $zero, 0x63
    ctx->r1 = ADD32(0, 0X63);
    // 0x8003EB40: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x8003EB44: mfhi        $t5
    ctx->r13 = hi;
    // 0x8003EB48: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8003EB4C: nop

    // 0x8003EB50: div         $zero, $t5, $s6
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r22))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r22)));
    // 0x8003EB54: mflo        $t6
    ctx->r14 = lo;
    // 0x8003EB58: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8003EB5C: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8003EB60: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8003EB64: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003EB68: bne         $s6, $zero, L_8003EB74
    if (ctx->r22 != 0) {
        // 0x8003EB6C: nop
    
            goto L_8003EB74;
    }
    // 0x8003EB6C: nop

    // 0x8003EB70: break       7
    do_break(2147740528);
L_8003EB74:
    // 0x8003EB74: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003EB78: bne         $s6, $at, L_8003EB8C
    if (ctx->r22 != ctx->r1) {
        // 0x8003EB7C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8003EB8C;
    }
    // 0x8003EB7C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8003EB80: bne         $t5, $at, L_8003EB8C
    if (ctx->r13 != ctx->r1) {
        // 0x8003EB84: nop
    
            goto L_8003EB8C;
    }
    // 0x8003EB84: nop

    // 0x8003EB88: break       6
    do_break(2147740552);
L_8003EB8C:
    // 0x8003EB8C: swc1        $f6, 0x78($t9)
    MEM_W(0X78, ctx->r25) = ctx->f6.u32l;
    // 0x8003EB90: jal         0x8000E35C
    // 0x8003EB94: nop

    func_8000E35C(rdram, ctx);
        goto after_12;
    // 0x8003EB94: nop

    after_12:
    // 0x8003EB98: andi        $t1, $v0, 0xF
    ctx->r9 = ctx->r2 & 0XF;
    // 0x8003EB9C: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8003EBA0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003EBA4: lwc1        $f16, 0x768C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X768C);
    // 0x8003EBA8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8003EBAC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003EBB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003EBB4: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x8003EBB8: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8003EBBC: sll         $t6, $s7, 16
    ctx->r14 = S32(ctx->r23 << 16);
    // 0x8003EBC0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8003EBC4: addu        $t0, $t2, $s0
    ctx->r8 = ADD32(ctx->r10, ctx->r16);
    // 0x8003EBC8: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x8003EBCC: sra         $s7, $t6, 16
    ctx->r23 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8003EBD0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8003EBD4: swc1        $f6, 0x7C($t3)
    MEM_W(0X7C, ctx->r11) = ctx->f6.u32l;
    // 0x8003EBD8: lh          $t4, 0x4($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X4);
    // 0x8003EBDC: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8003EBE0: sh          $t5, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r13;
    // 0x8003EBE4: lh          $t8, 0x52($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X52);
    // 0x8003EBE8: slt         $at, $s7, $t8
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8003EBEC: bnel        $at, $zero, L_8003E874
    if (ctx->r1 != 0) {
        // 0x8003EBF0: lh          $a2, 0x6($s1)
        ctx->r6 = MEM_H(ctx->r17, 0X6);
            goto L_8003E874;
    }
    goto skip_4;
    // 0x8003EBF0: lh          $a2, 0x6($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X6);
    skip_4:
    // 0x8003EBF4: sh          $s4, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r20;
L_8003EBF8:
    // 0x8003EBF8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8003EBFC:
    // 0x8003EBFC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8003EC00: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8003EC04: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8003EC08: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8003EC0C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8003EC10: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8003EC14: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8003EC18: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8003EC1C: jr          $ra
    // 0x8003EC20: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    TRACE_RETURN()
    return;
    // 0x8003EC20: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8003EC24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8003EC24: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x8003EC28: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8003EC2C: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8003EC30: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8003EC34: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8003EC38: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8003EC3C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8003EC40: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8003EC44: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8003EC48: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8003EC4C: lh          $t6, 0x4($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X4);
    // 0x8003EC50: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8003EC54: blezl       $t6, L_8003F15C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8003EC58: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_8003F15C;
    }
    goto skip_0;
    // 0x8003EC58: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x8003EC5C: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x8003EC60: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8003EC64: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8003EC68: blez        $t7, L_8003F158
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8003EC6C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8003F158;
    }
    // 0x8003EC6C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003EC70: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8003EC74: addiu       $s6, $sp, 0xA0
    ctx->r22 = ADD32(ctx->r29, 0XA0);
    // 0x8003EC78: addiu       $s5, $zero, -0x2
    ctx->r21 = ADD32(0, -0X2);
    // 0x8003EC7C: addiu       $s4, $sp, 0x58
    ctx->r20 = ADD32(ctx->r29, 0X58);
    // 0x8003EC80: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
    // 0x8003EC84: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
L_8003EC88:
    // 0x8003EC88: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003EC8C: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x8003EC90: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8003EC94: lh          $t1, 0x8($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X8);
    // 0x8003EC98: beql        $t1, $zero, L_8003F144
    if (ctx->r9 == 0) {
        // 0x8003EC9C: lh          $t1, 0x6($s1)
        ctx->r9 = MEM_H(ctx->r17, 0X6);
            goto L_8003F144;
    }
    goto skip_1;
    // 0x8003EC9C: lh          $t1, 0x6($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X6);
    skip_1:
    // 0x8003ECA0: lwc1        $f4, 0x6C($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X6C);
    // 0x8003ECA4: lwc1        $f6, 0x7690($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7690);
    // 0x8003ECA8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003ECAC: swc1        $f8, 0x6C($t0)
    MEM_W(0X6C, ctx->r8) = ctx->f8.u32l;
    // 0x8003ECB0: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x8003ECB4: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x8003ECB8: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x8003ECBC: lwc1        $f10, 0x78($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X78);
    // 0x8003ECC0: lwc1        $f16, 0x7C($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X7C);
    // 0x8003ECC4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8003ECC8: swc1        $f18, 0x78($t0)
    MEM_W(0X78, ctx->r8) = ctx->f18.u32l;
    // 0x8003ECCC: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8003ECD0: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x8003ECD4: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x8003ECD8: jal         0x8000E074
    // 0x8003ECDC: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    func_8000E074(rdram, ctx);
        goto after_0;
    // 0x8003ECDC: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    after_0:
    // 0x8003ECE0: beql        $v0, $zero, L_8003ED88
    if (ctx->r2 == 0) {
        // 0x8003ECE4: lw          $t4, 0x0($s1)
        ctx->r12 = MEM_W(ctx->r17, 0X0);
            goto L_8003ED88;
    }
    goto skip_2;
    // 0x8003ECE4: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    skip_2:
    // 0x8003ECE8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8003ECEC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8003ECF0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8003ECF4: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x8003ECF8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8003ECFC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8003ED00: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8003ED04: lw          $v0, 0x8($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X8);
    // 0x8003ED08: lw          $t1, 0xD8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XD8);
    // 0x8003ED0C: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x8003ED10: sw          $t2, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r10;
    // 0x8003ED14: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x8003ED18: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x8003ED1C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8003ED20: lw          $a1, 0x78($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X78);
    // 0x8003ED24: jal         0x80049840
    // 0x8003ED28: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    func_80049840(rdram, ctx);
        goto after_1;
    // 0x8003ED28: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_1:
    // 0x8003ED2C: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8003ED30: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x8003ED34: lw          $t0, 0x0($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X0);
    // 0x8003ED38: lwc1        $f0, 0x74($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X74);
    // 0x8003ED3C: lw          $t8, 0x4($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X4);
    // 0x8003ED40: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003ED44: lw          $a0, 0x8($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X8);
    // 0x8003ED48: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003ED4C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003ED50: jal         0x80001AB4
    // 0x8003ED54: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80001AB4(rdram, ctx);
        goto after_2;
    // 0x8003ED54: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_2:
    // 0x8003ED58: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8003ED5C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x8003ED60: addu        $t1, $t9, $s0
    ctx->r9 = ADD32(ctx->r25, ctx->r16);
    // 0x8003ED64: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8003ED68: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x8003ED6C: lw          $a0, 0x8($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X8);
    // 0x8003ED70: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8003ED74: jal         0x80000BD8
    // 0x8003ED78: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_80000BD8(rdram, ctx);
        goto after_3;
    // 0x8003ED78: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_3:
    // 0x8003ED7C: b           L_8003EDA8
    // 0x8003ED80: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_8003EDA8;
    // 0x8003ED80: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8003ED84: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
L_8003ED88:
    // 0x8003ED88: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x8003ED8C: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8003ED90: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8003ED94: lw          $v0, 0x8($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X8);
    // 0x8003ED98: lw          $t8, 0xD8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XD8);
    // 0x8003ED9C: and         $t9, $t8, $s5
    ctx->r25 = ctx->r24 & ctx->r21;
    // 0x8003EDA0: sw          $t9, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r25;
    // 0x8003EDA4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8003EDA8:
    // 0x8003EDA8: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x8003EDAC: addiu       $s2, $s2, -0x4
    ctx->r18 = ADD32(ctx->r18, -0X4);
    // 0x8003EDB0: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x8003EDB4: beq         $v1, $s2, L_8003EE08
    if (ctx->r3 == ctx->r18) {
        // 0x8003EDB8: lw          $t3, 0x0($t2)
        ctx->r11 = MEM_W(ctx->r10, 0X0);
            goto L_8003EE08;
    }
    // 0x8003EDB8: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
L_8003EDBC:
    // 0x8003EDBC: addu        $v0, $t3, $v1
    ctx->r2 = ADD32(ctx->r11, ctx->r3);
    // 0x8003EDC0: lwc1        $f18, 0x50($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X50);
    // 0x8003EDC4: lwc1        $f16, 0x68($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X68);
    // 0x8003EDC8: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8003EDCC: swc1        $f16, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f16.u32l;
    // 0x8003EDD0: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8003EDD4: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x8003EDD8: lw          $t0, 0x0($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X0);
    // 0x8003EDDC: lw          $t7, 0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4);
    // 0x8003EDE0: addu        $t6, $t0, $v1
    ctx->r14 = ADD32(ctx->r8, ctx->r3);
    // 0x8003EDE4: lwc1        $f16, 0x50($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X50);
    // 0x8003EDE8: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x8003EDEC: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x8003EDF0: swc1        $f16, 0x40($t9)
    MEM_W(0X40, ctx->r25) = ctx->f16.u32l;
    // 0x8003EDF4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x8003EDF8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003EDFC: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x8003EE00: bne         $v1, $s2, L_8003EDBC
    if (ctx->r3 != ctx->r18) {
        // 0x8003EE04: lw          $t3, 0x0($t2)
        ctx->r11 = MEM_W(ctx->r10, 0X0);
            goto L_8003EDBC;
    }
    // 0x8003EE04: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
L_8003EE08:
    // 0x8003EE08: addu        $v0, $t3, $v1
    ctx->r2 = ADD32(ctx->r11, ctx->r3);
    // 0x8003EE0C: lwc1        $f18, 0x50($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X50);
    // 0x8003EE10: lwc1        $f16, 0x68($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X68);
    // 0x8003EE14: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8003EE18: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8003EE1C: swc1        $f16, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f16.u32l;
    // 0x8003EE20: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8003EE24: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x8003EE28: lw          $t0, 0x0($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X0);
    // 0x8003EE2C: lw          $t7, 0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4);
    // 0x8003EE30: addu        $t6, $t0, $v1
    ctx->r14 = ADD32(ctx->r8, ctx->r3);
    // 0x8003EE34: lwc1        $f16, 0x50($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X50);
    // 0x8003EE38: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x8003EE3C: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x8003EE40: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003EE44: swc1        $f16, 0x40($t9)
    MEM_W(0X40, ctx->r25) = ctx->f16.u32l;
    // 0x8003EE48: lh          $t1, 0x8($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X8);
    // 0x8003EE4C: bnel        $t1, $zero, L_8003EECC
    if (ctx->r9 != 0) {
        // 0x8003EE50: lw          $t2, 0x0($s1)
        ctx->r10 = MEM_W(ctx->r17, 0X0);
            goto L_8003EECC;
    }
    goto skip_3;
    // 0x8003EE50: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    skip_3:
    // 0x8003EE54: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x8003EE58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003EE5C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8003EE60: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x8003EE64: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x8003EE68: addiu       $a0, $t0, 0x50
    ctx->r4 = ADD32(ctx->r8, 0X50);
    // 0x8003EE6C: jal         0x8001F2CC
    // 0x8003EE70: lh          $a1, 0x80($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X80);
    func_8001F2CC(rdram, ctx);
        goto after_4;
    // 0x8003EE70: lh          $a1, 0x80($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X80);
    after_4:
    // 0x8003EE74: beql        $v0, $zero, L_8003EF28
    if (ctx->r2 == 0) {
        // 0x8003EE78: lw          $t2, 0x0($s1)
        ctx->r10 = MEM_W(ctx->r17, 0X0);
            goto L_8003EF28;
    }
    goto skip_4;
    // 0x8003EE78: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    skip_4:
    // 0x8003EE7C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8003EE80: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8003EE84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003EE88: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x8003EE8C: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x8003EE90: jal         0x80042F80
    // 0x8003EE94: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    func_80042F80(rdram, ctx);
        goto after_5;
    // 0x8003EE94: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    after_5:
    // 0x8003EE98: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8003EE9C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8003EEA0: addiu       $a0, $a0, -0x6A20
    ctx->r4 = ADD32(ctx->r4, -0X6A20);
    // 0x8003EEA4: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x8003EEA8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8003EEAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003EEB0: jal         0x80044614
    // 0x8003EEB4: sh          $zero, 0x8($t8)
    MEM_H(0X8, ctx->r24) = 0;
    func_80044614(rdram, ctx);
        goto after_6;
    // 0x8003EEB4: sh          $zero, 0x8($t8)
    MEM_H(0X8, ctx->r24) = 0;
    after_6:
    // 0x8003EEB8: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8003EEBC: addu        $t1, $t9, $s0
    ctx->r9 = ADD32(ctx->r25, ctx->r16);
    // 0x8003EEC0: b           L_8003F120
    // 0x8003EEC4: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
        goto L_8003F120;
    // 0x8003EEC4: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
    // 0x8003EEC8: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
L_8003EECC:
    // 0x8003EECC: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x8003EED0: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x8003EED4: addiu       $a0, $t0, 0x50
    ctx->r4 = ADD32(ctx->r8, 0X50);
    // 0x8003EED8: jal         0x8004267C
    // 0x8003EEDC: lh          $a1, 0x80($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X80);
    func_8004267C(rdram, ctx);
        goto after_7;
    // 0x8003EEDC: lh          $a1, 0x80($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X80);
    after_7:
    // 0x8003EEE0: beql        $v0, $zero, L_8003EF28
    if (ctx->r2 == 0) {
        // 0x8003EEE4: lw          $t2, 0x0($s1)
        ctx->r10 = MEM_W(ctx->r17, 0X0);
            goto L_8003EF28;
    }
    goto skip_5;
    // 0x8003EEE4: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    skip_5:
    // 0x8003EEE8: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8003EEEC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8003EEF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003EEF4: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x8003EEF8: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x8003EEFC: jal         0x80042F80
    // 0x8003EF00: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    func_80042F80(rdram, ctx);
        goto after_8;
    // 0x8003EF00: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    after_8:
    // 0x8003EF04: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8003EF08: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x8003EF0C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8003EF10: sh          $zero, 0x8($t8)
    MEM_H(0X8, ctx->r24) = 0;
    // 0x8003EF14: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8003EF18: addu        $t1, $t9, $s0
    ctx->r9 = ADD32(ctx->r25, ctx->r16);
    // 0x8003EF1C: b           L_8003F120
    // 0x8003EF20: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
        goto L_8003F120;
    // 0x8003EF20: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
    // 0x8003EF24: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
L_8003EF28:
    // 0x8003EF28: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x8003EF2C: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x8003EF30: addiu       $a0, $t0, 0x50
    ctx->r4 = ADD32(ctx->r8, 0X50);
    // 0x8003EF34: jal         0x8001F9B0
    // 0x8003EF38: lh          $a1, 0x80($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X80);
    func_8001F9B0(rdram, ctx);
        goto after_9;
    // 0x8003EF38: lh          $a1, 0x80($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X80);
    after_9:
    // 0x8003EF3C: beql        $v0, $zero, L_8003EF84
    if (ctx->r2 == 0) {
        // 0x8003EF40: lw          $t2, 0x0($s1)
        ctx->r10 = MEM_W(ctx->r17, 0X0);
            goto L_8003EF84;
    }
    goto skip_6;
    // 0x8003EF40: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    skip_6:
    // 0x8003EF44: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8003EF48: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8003EF4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003EF50: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x8003EF54: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x8003EF58: jal         0x80042F80
    // 0x8003EF5C: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    func_80042F80(rdram, ctx);
        goto after_10;
    // 0x8003EF5C: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    after_10:
    // 0x8003EF60: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8003EF64: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x8003EF68: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8003EF6C: sh          $zero, 0x8($t8)
    MEM_H(0X8, ctx->r24) = 0;
    // 0x8003EF70: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8003EF74: addu        $t1, $t9, $s0
    ctx->r9 = ADD32(ctx->r25, ctx->r16);
    // 0x8003EF78: b           L_8003F120
    // 0x8003EF7C: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
        goto L_8003F120;
    // 0x8003EF7C: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
    // 0x8003EF80: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
L_8003EF84:
    // 0x8003EF84: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x8003EF88: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x8003EF8C: addiu       $a0, $t0, 0x50
    ctx->r4 = ADD32(ctx->r8, 0X50);
    // 0x8003EF90: jal         0x800423C0
    // 0x8003EF94: lh          $a1, 0x80($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X80);
    func_800423C0(rdram, ctx);
        goto after_11;
    // 0x8003EF94: lh          $a1, 0x80($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X80);
    after_11:
    // 0x8003EF98: beql        $v0, $zero, L_8003EFE0
    if (ctx->r2 == 0) {
        // 0x8003EF9C: lw          $t2, 0x0($s1)
        ctx->r10 = MEM_W(ctx->r17, 0X0);
            goto L_8003EFE0;
    }
    goto skip_7;
    // 0x8003EF9C: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    skip_7:
    // 0x8003EFA0: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8003EFA4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8003EFA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003EFAC: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x8003EFB0: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x8003EFB4: jal         0x80042F80
    // 0x8003EFB8: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    func_80042F80(rdram, ctx);
        goto after_12;
    // 0x8003EFB8: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    after_12:
    // 0x8003EFBC: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8003EFC0: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x8003EFC4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8003EFC8: sh          $zero, 0x8($t8)
    MEM_H(0X8, ctx->r24) = 0;
    // 0x8003EFCC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8003EFD0: addu        $t1, $t9, $s0
    ctx->r9 = ADD32(ctx->r25, ctx->r16);
    // 0x8003EFD4: b           L_8003F120
    // 0x8003EFD8: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
        goto L_8003F120;
    // 0x8003EFD8: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
    // 0x8003EFDC: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
L_8003EFE0:
    // 0x8003EFE0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8003EFE4: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x8003EFE8: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    // 0x8003EFEC: jal         0x8000D3A4
    // 0x8003EFF0: addiu       $a1, $a1, 0x50
    ctx->r5 = ADD32(ctx->r5, 0X50);
    func_8000D3A4(rdram, ctx);
        goto after_13;
    // 0x8003EFF0: addiu       $a1, $a1, 0x50
    ctx->r5 = ADD32(ctx->r5, 0X50);
    after_13:
    // 0x8003EFF4: beql        $v0, $zero, L_8003F0A8
    if (ctx->r2 == 0) {
        // 0x8003EFF8: lw          $t1, 0x0($s1)
        ctx->r9 = MEM_W(ctx->r17, 0X0);
            goto L_8003F0A8;
    }
    goto skip_8;
    // 0x8003EFF8: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    skip_8:
    // 0x8003EFFC: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8003F000: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8003F004: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x8003F008: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x8003F00C: jal         0x80003668
    // 0x8003F010: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    func_80003668(rdram, ctx);
        goto after_14;
    // 0x8003F010: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    after_14:
    // 0x8003F014: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8003F018: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x8003F01C: nop

    // 0x8003F020: slti        $at, $t7, 0xC
    ctx->r1 = SIGNED(ctx->r15) < 0XC ? 1 : 0;
    // 0x8003F024: beql        $at, $zero, L_8003F0A8
    if (ctx->r1 == 0) {
        // 0x8003F028: lw          $t1, 0x0($s1)
        ctx->r9 = MEM_W(ctx->r17, 0X0);
            goto L_8003F0A8;
    }
    goto skip_9;
    // 0x8003F028: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    skip_9:
    // 0x8003F02C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8003F030: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x8003F034: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003F038: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x8003F03C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x8003F040: jal         0x80042F80
    // 0x8003F044: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    func_80042F80(rdram, ctx);
        goto after_15;
    // 0x8003F044: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    after_15:
    // 0x8003F048: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x8003F04C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x8003F050: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    // 0x8003F054: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x8003F058: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x8003F05C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8003F060: jal         0x8001F2CC
    // 0x8003F064: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    func_8001F2CC(rdram, ctx);
        goto after_16;
    // 0x8003F064: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    after_16:
    // 0x8003F068: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x8003F06C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x8003F070: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    // 0x8003F074: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x8003F078: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x8003F07C: jal         0x800425B4
    // 0x8003F080: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    func_800425B4(rdram, ctx);
        goto after_17;
    // 0x8003F080: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    after_17:
    // 0x8003F084: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x8003F088: addu        $t6, $t5, $s0
    ctx->r14 = ADD32(ctx->r13, ctx->r16);
    // 0x8003F08C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8003F090: sh          $zero, 0x8($t7)
    MEM_H(0X8, ctx->r15) = 0;
    // 0x8003F094: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8003F098: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x8003F09C: b           L_8003F120
    // 0x8003F0A0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
        goto L_8003F120;
    // 0x8003F0A0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8003F0A4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
L_8003F0A8:
    // 0x8003F0A8: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x8003F0AC: lw          $t0, 0x0($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X0);
    // 0x8003F0B0: lh          $t3, 0x82($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X82);
    // 0x8003F0B4: addiu       $a0, $t0, 0x50
    ctx->r4 = ADD32(ctx->r8, 0X50);
    // 0x8003F0B8: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x8003F0BC: bnel        $t4, $zero, L_8003F0F0
    if (ctx->r12 != 0) {
        // 0x8003F0C0: lw          $t9, 0x0($s1)
        ctx->r25 = MEM_W(ctx->r17, 0X0);
            goto L_8003F0F0;
    }
    goto skip_10;
    // 0x8003F0C0: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    skip_10:
    // 0x8003F0C4: jal         0x8003E3F8
    // 0x8003F0C8: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    func_8003E3F8(rdram, ctx);
        goto after_18;
    // 0x8003F0C8: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_18:
    // 0x8003F0CC: beql        $v0, $zero, L_8003F0F0
    if (ctx->r2 == 0) {
        // 0x8003F0D0: lw          $t9, 0x0($s1)
        ctx->r25 = MEM_W(ctx->r17, 0X0);
            goto L_8003F0F0;
    }
    goto skip_11;
    // 0x8003F0D0: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    skip_11:
    // 0x8003F0D4: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x8003F0D8: addu        $t6, $t5, $s0
    ctx->r14 = ADD32(ctx->r13, ctx->r16);
    // 0x8003F0DC: lw          $t0, 0x0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X0);
    // 0x8003F0E0: lh          $t7, 0x82($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X82);
    // 0x8003F0E4: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x8003F0E8: sh          $t8, 0x82($t0)
    MEM_H(0X82, ctx->r8) = ctx->r24;
    // 0x8003F0EC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
L_8003F0F0:
    // 0x8003F0F0: addu        $t1, $t9, $s0
    ctx->r9 = ADD32(ctx->r25, ctx->r16);
    // 0x8003F0F4: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
    // 0x8003F0F8: lh          $v0, 0x8($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X8);
    // 0x8003F0FC: beq         $v0, $zero, L_8003F118
    if (ctx->r2 == 0) {
        // 0x8003F100: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_8003F118;
    }
    // 0x8003F100: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x8003F104: sh          $t2, 0x8($t0)
    MEM_H(0X8, ctx->r8) = ctx->r10;
    // 0x8003F108: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x8003F10C: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x8003F110: lw          $t0, 0x0($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X0);
    // 0x8003F114: lh          $v0, 0x8($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X8);
L_8003F118:
    // 0x8003F118: bnel        $v0, $zero, L_8003F144
    if (ctx->r2 != 0) {
        // 0x8003F11C: lh          $t1, 0x6($s1)
        ctx->r9 = MEM_H(ctx->r17, 0X6);
            goto L_8003F144;
    }
    goto skip_12;
    // 0x8003F11C: lh          $t1, 0x6($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X6);
    skip_12:
L_8003F120:
    // 0x8003F120: lw          $t5, 0x4($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X4);
    // 0x8003F124: lw          $v0, 0x8($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X8);
    // 0x8003F128: lw          $t6, 0xD8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XD8);
    // 0x8003F12C: and         $t7, $t6, $s5
    ctx->r15 = ctx->r14 & ctx->r21;
    // 0x8003F130: sw          $t7, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r15;
    // 0x8003F134: lh          $t8, 0x4($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X4);
    // 0x8003F138: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8003F13C: sh          $t9, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r25;
    // 0x8003F140: lh          $t1, 0x6($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X6);
L_8003F144:
    // 0x8003F144: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8003F148: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8003F14C: slt         $at, $s3, $t1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8003F150: bnel        $at, $zero, L_8003EC88
    if (ctx->r1 != 0) {
        // 0x8003F154: lw          $t8, 0x0($s1)
        ctx->r24 = MEM_W(ctx->r17, 0X0);
            goto L_8003EC88;
    }
    goto skip_13;
    // 0x8003F154: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    skip_13:
L_8003F158:
    // 0x8003F158: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8003F15C:
    // 0x8003F15C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8003F160: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8003F164: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8003F168: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8003F16C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8003F170: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8003F174: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8003F178: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8003F17C: jr          $ra
    // 0x8003F180: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    TRACE_RETURN()
    return;
    // 0x8003F180: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void func_8003F184(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8003F184: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8003F188: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8003F18C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8003F190: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8003F194: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8003F198: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8003F19C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8003F1A0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8003F1A4: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x8003F1A8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8003F1AC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8003F1B0: blez        $t6, L_8003F214
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8003F1B4: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8003F214;
    }
    // 0x8003F1B4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8003F1B8: lui         $s5, 0x801A
    ctx->r21 = S32(0X801A << 16);
    // 0x8003F1BC: addiu       $s5, $s5, 0x2800
    ctx->r21 = ADD32(ctx->r21, 0X2800);
    // 0x8003F1C0: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // 0x8003F1C4: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
L_8003F1C8:
    // 0x8003F1C8: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x8003F1CC: lw          $s0, 0x0($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X0);
    // 0x8003F1D0: lh          $t9, 0xA($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XA);
    // 0x8003F1D4: beql        $s4, $t9, L_8003F1F4
    if (ctx->r20 == ctx->r25) {
        // 0x8003F1D8: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_8003F1F4;
    }
    goto skip_0;
    // 0x8003F1D8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_0:
    // 0x8003F1DC: jal         0x8004A0C4
    // 0x8003F1E0: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    func_8004A0C4(rdram, ctx);
        goto after_0;
    // 0x8003F1E0: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_0:
    // 0x8003F1E4: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x8003F1E8: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x8003F1EC: lw          $s0, 0x0($t1)
    ctx->r16 = MEM_W(ctx->r9, 0X0);
    // 0x8003F1F0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_8003F1F4:
    // 0x8003F1F4: jal         0x800042A8
    // 0x8003F1F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800042A8(rdram, ctx);
        goto after_1;
    // 0x8003F1F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x8003F1FC: lh          $t2, 0x6($s3)
    ctx->r10 = MEM_H(ctx->r19, 0X6);
    // 0x8003F200: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8003F204: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8003F208: slt         $at, $s2, $t2
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8003F20C: bnel        $at, $zero, L_8003F1C8
    if (ctx->r1 != 0) {
        // 0x8003F210: lw          $t7, 0x0($s3)
        ctx->r15 = MEM_W(ctx->r19, 0X0);
            goto L_8003F1C8;
    }
    goto skip_1;
    // 0x8003F210: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    skip_1:
L_8003F214:
    // 0x8003F214: lui         $s5, 0x801A
    ctx->r21 = S32(0X801A << 16);
    // 0x8003F218: addiu       $s5, $s5, 0x2800
    ctx->r21 = ADD32(ctx->r21, 0X2800);
    // 0x8003F21C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8003F220: jal         0x800042A8
    // 0x8003F224: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    func_800042A8(rdram, ctx);
        goto after_2;
    // 0x8003F224: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    after_2:
    // 0x8003F228: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8003F22C: jal         0x800042A8
    // 0x8003F230: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800042A8(rdram, ctx);
        goto after_3;
    // 0x8003F230: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_3:
    // 0x8003F234: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8003F238: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8003F23C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8003F240: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8003F244: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8003F248: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8003F24C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8003F250: jr          $ra
    // 0x8003F254: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    TRACE_RETURN()
    return;
    // 0x8003F254: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8003F258(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8003F258: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8003F25C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8003F260: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003F264: sll         $s0, $a0, 16
    ctx->r16 = S32(ctx->r4 << 16);
    // 0x8003F268: lui         $s4, 0x801A
    ctx->r20 = S32(0X801A << 16);
    // 0x8003F26C: addiu       $s4, $s4, 0x2800
    ctx->r20 = ADD32(ctx->r20, 0X2800);
    // 0x8003F270: sra         $t6, $s0, 16
    ctx->r14 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8003F274: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8003F278: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8003F27C: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x8003F280: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8003F284: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8003F288: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8003F28C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8003F290: jal         0x80004364
    // 0x8003F294: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x8003F294: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_0:
    // 0x8003F298: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8003F29C: sh          $s0, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r16;
    // 0x8003F2A0: beq         $s0, $zero, L_8003F2BC
    if (ctx->r16 == 0) {
        // 0x8003F2A4: sh          $zero, 0x4($v0)
        MEM_H(0X4, ctx->r2) = 0;
            goto L_8003F2BC;
    }
    // 0x8003F2A4: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x8003F2A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003F2AC: beq         $s0, $at, L_8003F2DC
    if (ctx->r16 == ctx->r1) {
        // 0x8003F2B0: addiu       $t9, $zero, 0xA
        ctx->r25 = ADD32(0, 0XA);
            goto L_8003F2DC;
    }
    // 0x8003F2B0: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x8003F2B4: b           L_8003F31C
    // 0x8003F2B8: lh          $a1, 0x6($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X6);
        goto L_8003F31C;
    // 0x8003F2B8: lh          $a1, 0x6($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X6);
L_8003F2BC:
    // 0x8003F2BC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8003F2C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003F2C4: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8003F2C8: addiu       $t8, $zero, 0x28
    ctx->r24 = ADD32(0, 0X28);
    // 0x8003F2CC: sh          $t7, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r15;
    // 0x8003F2D0: sh          $t8, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r24;
    // 0x8003F2D4: b           L_8003F318
    // 0x8003F2D8: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
        goto L_8003F318;
    // 0x8003F2D8: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
L_8003F2DC:
    // 0x8003F2DC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8003F2E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003F2E4: addiu       $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
    // 0x8003F2E8: sh          $t9, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r25;
    // 0x8003F2EC: sh          $t0, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r8;
    // 0x8003F2F0: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8003F2F4: swc1        $f6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f6.u32l;
    // 0x8003F2F8: lw          $t1, -0x6630($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X6630);
    // 0x8003F2FC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003F300: bne         $t1, $at, L_8003F318
    if (ctx->r9 != ctx->r1) {
        // 0x8003F304: lui         $at, 0x4100
        ctx->r1 = S32(0X4100 << 16);
            goto L_8003F318;
    }
    // 0x8003F304: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8003F308: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003F30C: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8003F310: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8003F314: swc1        $f16, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f16.u32l;
L_8003F318:
    // 0x8003F318: lh          $a1, 0x6($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X6);
L_8003F31C:
    // 0x8003F31C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8003F320: sll         $t2, $a1, 2
    ctx->r10 = S32(ctx->r5 << 2);
    // 0x8003F324: jal         0x80004364
    // 0x8003F328: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    func_80004364(rdram, ctx);
        goto after_1;
    // 0x8003F328: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    after_1:
    // 0x8003F32C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8003F330: lh          $t3, 0x6($s3)
    ctx->r11 = MEM_H(ctx->r19, 0X6);
    // 0x8003F334: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8003F338: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8003F33C: blez        $t3, L_8003F378
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8003F340: addiu       $s2, $zero, -0x1
        ctx->r18 = ADD32(0, -0X1);
            goto L_8003F378;
    }
    // 0x8003F340: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x8003F344: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_8003F348:
    // 0x8003F348: jal         0x80004364
    // 0x8003F34C: addiu       $a1, $zero, 0x7C
    ctx->r5 = ADD32(0, 0X7C);
    func_80004364(rdram, ctx);
        goto after_2;
    // 0x8003F34C: addiu       $a1, $zero, 0x7C
    ctx->r5 = ADD32(0, 0X7C);
    after_2:
    // 0x8003F350: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8003F354: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x8003F358: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8003F35C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8003F360: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8003F364: sh          $s2, 0xA($t4)
    MEM_H(0XA, ctx->r12) = ctx->r18;
    // 0x8003F368: lh          $t5, 0x6($s3)
    ctx->r13 = MEM_H(ctx->r19, 0X6);
    // 0x8003F36C: slt         $at, $s1, $t5
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8003F370: bnel        $at, $zero, L_8003F348
    if (ctx->r1 != 0) {
        // 0x8003F374: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_8003F348;
    }
    goto skip_0;
    // 0x8003F374: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_0:
L_8003F378:
    // 0x8003F378: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8003F37C: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x8003F380: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x8003F384: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8003F388: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8003F38C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8003F390: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8003F394: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8003F398: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003F39C: jr          $ra
    // 0x8003F3A0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    TRACE_RETURN()
    return;
    // 0x8003F3A0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8003F3A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8003F3A4: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x8003F3A8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8003F3AC: lh          $t7, -0x6B94($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X6B94);
    // 0x8003F3B0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8003F3B4: sll         $s0, $a0, 16
    ctx->r16 = S32(ctx->r4 << 16);
    // 0x8003F3B8: sra         $t6, $s0, 16
    ctx->r14 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8003F3BC: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x8003F3C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003F3C4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8003F3C8: sw          $a0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r4;
    // 0x8003F3CC: sw          $a1, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r5;
    // 0x8003F3D0: sw          $a2, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r6;
    // 0x8003F3D4: sw          $a3, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r7;
    // 0x8003F3D8: bne         $t7, $zero, L_8003F3E8
    if (ctx->r15 != 0) {
        // 0x8003F3DC: sh          $zero, 0x40($sp)
        MEM_H(0X40, ctx->r29) = 0;
            goto L_8003F3E8;
    }
    // 0x8003F3DC: sh          $zero, 0x40($sp)
    MEM_H(0X40, ctx->r29) = 0;
    // 0x8003F3E0: b           L_8003F960
    // 0x8003F3E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003F960;
    // 0x8003F3E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003F3E8:
    // 0x8003F3E8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8003F3EC: bne         $s0, $v1, L_8003F424
    if (ctx->r16 != ctx->r3) {
        // 0x8003F3F0: nop
    
            goto L_8003F424;
    }
    // 0x8003F3F0: nop

    // 0x8003F3F4: jal         0x8000E114
    // 0x8003F3F8: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    func_8000E114(rdram, ctx);
        goto after_0;
    // 0x8003F3F8: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    after_0:
    // 0x8003F3FC: bne         $v0, $zero, L_8003F40C
    if (ctx->r2 != 0) {
        // 0x8003F400: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8003F40C;
    }
    // 0x8003F400: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8003F404: b           L_8003F960
    // 0x8003F408: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003F960;
    // 0x8003F408: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003F40C:
    // 0x8003F40C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8003F410: lh          $t8, -0x6B7A($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X6B7A);
    // 0x8003F414: beq         $t8, $zero, L_8003F424
    if (ctx->r24 == 0) {
        // 0x8003F418: nop
    
            goto L_8003F424;
    }
    // 0x8003F418: nop

    // 0x8003F41C: b           L_8003F960
    // 0x8003F420: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003F960;
    // 0x8003F420: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003F424:
    // 0x8003F424: beq         $s0, $zero, L_8003F43C
    if (ctx->r16 == 0) {
        // 0x8003F428: lh          $t9, 0xE6($sp)
        ctx->r25 = MEM_H(ctx->r29, 0XE6);
            goto L_8003F43C;
    }
    // 0x8003F428: lh          $t9, 0xE6($sp)
    ctx->r25 = MEM_H(ctx->r29, 0XE6);
    // 0x8003F42C: beq         $s0, $v1, L_8003F498
    if (ctx->r16 == ctx->r3) {
        // 0x8003F430: lh          $t2, 0xE6($sp)
        ctx->r10 = MEM_H(ctx->r29, 0XE6);
            goto L_8003F498;
    }
    // 0x8003F430: lh          $t2, 0xE6($sp)
    ctx->r10 = MEM_H(ctx->r29, 0XE6);
    // 0x8003F434: b           L_8003F544
    // 0x8003F438: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
        goto L_8003F544;
    // 0x8003F438: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
L_8003F43C:
    // 0x8003F43C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8003F440: bne         $t9, $zero, L_8003F470
    if (ctx->r25 != 0) {
        // 0x8003F444: lw          $s1, -0x658C($s1)
        ctx->r17 = MEM_W(ctx->r17, -0X658C);
            goto L_8003F470;
    }
    // 0x8003F444: lw          $s1, -0x658C($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X658C);
    // 0x8003F448: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x8003F44C: jal         0x80049CFC
    // 0x8003F450: addiu       $a0, $a0, 0x75D0
    ctx->r4 = ADD32(ctx->r4, 0X75D0);
    func_80049CFC(rdram, ctx);
        goto after_1;
    // 0x8003F450: addiu       $a0, $a0, 0x75D0
    ctx->r4 = ADD32(ctx->r4, 0X75D0);
    after_1:
    // 0x8003F454: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003F458: lwc1        $f4, 0x7694($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7694);
    // 0x8003F45C: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x8003F460: sh          $v0, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r2;
    // 0x8003F464: sh          $t0, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r8;
    // 0x8003F468: b           L_8003F544
    // 0x8003F46C: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
        goto L_8003F544;
    // 0x8003F46C: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
L_8003F470:
    // 0x8003F470: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x8003F474: jal         0x80049CFC
    // 0x8003F478: addiu       $a0, $a0, 0x75D8
    ctx->r4 = ADD32(ctx->r4, 0X75D8);
    func_80049CFC(rdram, ctx);
        goto after_2;
    // 0x8003F478: addiu       $a0, $a0, 0x75D8
    ctx->r4 = ADD32(ctx->r4, 0X75D8);
    after_2:
    // 0x8003F47C: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x8003F480: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003F484: addiu       $t1, $zero, 0x32
    ctx->r9 = ADD32(0, 0X32);
    // 0x8003F488: sh          $v0, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r2;
    // 0x8003F48C: sh          $t1, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r9;
    // 0x8003F490: b           L_8003F544
    // 0x8003F494: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
        goto L_8003F544;
    // 0x8003F494: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
L_8003F498:
    // 0x8003F498: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8003F49C: beq         $t2, $zero, L_8003F4C0
    if (ctx->r10 == 0) {
        // 0x8003F4A0: lw          $s1, -0x657C($s1)
        ctx->r17 = MEM_W(ctx->r17, -0X657C);
            goto L_8003F4C0;
    }
    // 0x8003F4A0: lw          $s1, -0x657C($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X657C);
    // 0x8003F4A4: beq         $t2, $v1, L_8003F4F0
    if (ctx->r10 == ctx->r3) {
        // 0x8003F4A8: lui         $a0, 0x8007
        ctx->r4 = S32(0X8007 << 16);
            goto L_8003F4F0;
    }
    // 0x8003F4A8: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x8003F4AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003F4B0: beq         $t2, $at, L_8003F51C
    if (ctx->r10 == ctx->r1) {
        // 0x8003F4B4: lui         $a0, 0x8007
        ctx->r4 = S32(0X8007 << 16);
            goto L_8003F51C;
    }
    // 0x8003F4B4: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x8003F4B8: b           L_8003F548
    // 0x8003F4BC: lh          $a2, 0x6($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X6);
        goto L_8003F548;
    // 0x8003F4BC: lh          $a2, 0x6($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X6);
L_8003F4C0:
    // 0x8003F4C0: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x8003F4C4: jal         0x80049CFC
    // 0x8003F4C8: addiu       $a0, $a0, 0x75E0
    ctx->r4 = ADD32(ctx->r4, 0X75E0);
    func_80049CFC(rdram, ctx);
        goto after_3;
    // 0x8003F4C8: addiu       $a0, $a0, 0x75E0
    ctx->r4 = ADD32(ctx->r4, 0X75E0);
    after_3:
    // 0x8003F4CC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003F4D0: lwc1        $f8, 0x7698($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7698);
    // 0x8003F4D4: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x8003F4D8: addiu       $t4, $zero, 0xB
    ctx->r12 = ADD32(0, 0XB);
    // 0x8003F4DC: sh          $v0, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r2;
    // 0x8003F4E0: sh          $t3, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r11;
    // 0x8003F4E4: sh          $t4, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r12;
    // 0x8003F4E8: b           L_8003F544
    // 0x8003F4EC: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
        goto L_8003F544;
    // 0x8003F4EC: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
L_8003F4F0:
    // 0x8003F4F0: jal         0x80049CFC
    // 0x8003F4F4: addiu       $a0, $a0, 0x75E8
    ctx->r4 = ADD32(ctx->r4, 0X75E8);
    func_80049CFC(rdram, ctx);
        goto after_4;
    // 0x8003F4F4: addiu       $a0, $a0, 0x75E8
    ctx->r4 = ADD32(ctx->r4, 0X75E8);
    after_4:
    // 0x8003F4F8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003F4FC: lwc1        $f10, 0x769C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X769C);
    // 0x8003F500: addiu       $t5, $zero, 0x64
    ctx->r13 = ADD32(0, 0X64);
    // 0x8003F504: addiu       $t6, $zero, 0x1F
    ctx->r14 = ADD32(0, 0X1F);
    // 0x8003F508: sh          $v0, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r2;
    // 0x8003F50C: sh          $t5, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r13;
    // 0x8003F510: sh          $t6, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r14;
    // 0x8003F514: b           L_8003F544
    // 0x8003F518: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
        goto L_8003F544;
    // 0x8003F518: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
L_8003F51C:
    // 0x8003F51C: jal         0x80049CFC
    // 0x8003F520: addiu       $a0, $a0, 0x75F0
    ctx->r4 = ADD32(ctx->r4, 0X75F0);
    func_80049CFC(rdram, ctx);
        goto after_5;
    // 0x8003F520: addiu       $a0, $a0, 0x75F0
    ctx->r4 = ADD32(ctx->r4, 0X75F0);
    after_5:
    // 0x8003F524: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003F528: lwc1        $f16, 0x76A0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X76A0);
    // 0x8003F52C: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8003F530: addiu       $t8, $zero, 0x2C
    ctx->r24 = ADD32(0, 0X2C);
    // 0x8003F534: sh          $v0, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r2;
    // 0x8003F538: sh          $t7, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r15;
    // 0x8003F53C: sh          $t8, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r24;
    // 0x8003F540: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
L_8003F544:
    // 0x8003F544: lh          $a2, 0x6($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X6);
L_8003F548:
    // 0x8003F548: lh          $t9, 0x4($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X4);
    // 0x8003F54C: slt         $at, $t9, $a2
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8003F550: bne         $at, $zero, L_8003F560
    if (ctx->r1 != 0) {
        // 0x8003F554: nop
    
            goto L_8003F560;
    }
    // 0x8003F554: nop

    // 0x8003F558: b           L_8003F960
    // 0x8003F55C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003F960;
    // 0x8003F55C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003F560:
    // 0x8003F560: blez        $a2, L_8003F5B4
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8003F564: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8003F5B4;
    }
    // 0x8003F564: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003F568: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8003F56C: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_8003F570:
    // 0x8003F570: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8003F574: lh          $t0, 0x8($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X8);
    // 0x8003F578: bnel        $t0, $zero, L_8003F5A8
    if (ctx->r8 != 0) {
        // 0x8003F57C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8003F5A8;
    }
    goto skip_0;
    // 0x8003F57C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_0:
    // 0x8003F580: sh          $a1, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r5;
    // 0x8003F584: lh          $a0, 0xA($v1)
    ctx->r4 = MEM_H(ctx->r3, 0XA);
    // 0x8003F588: lh          $t1, 0x4A($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X4A);
    // 0x8003F58C: beq         $t1, $a0, L_8003F59C
    if (ctx->r9 == ctx->r4) {
        // 0x8003F590: nop
    
            goto L_8003F59C;
    }
    // 0x8003F590: nop

    // 0x8003F594: bnel        $a3, $a0, L_8003F5A8
    if (ctx->r7 != ctx->r4) {
        // 0x8003F598: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8003F5A8;
    }
    goto skip_1;
    // 0x8003F598: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_1:
L_8003F59C:
    // 0x8003F59C: b           L_8003F5B8
    // 0x8003F5A0: lh          $s0, 0x48($sp)
    ctx->r16 = MEM_H(ctx->r29, 0X48);
        goto L_8003F5B8;
    // 0x8003F5A0: lh          $s0, 0x48($sp)
    ctx->r16 = MEM_H(ctx->r29, 0X48);
    // 0x8003F5A4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8003F5A8:
    // 0x8003F5A8: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8003F5AC: bne         $at, $zero, L_8003F570
    if (ctx->r1 != 0) {
        // 0x8003F5B0: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8003F570;
    }
    // 0x8003F5B0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8003F5B4:
    // 0x8003F5B4: lh          $s0, 0x48($sp)
    ctx->r16 = MEM_H(ctx->r29, 0X48);
L_8003F5B8:
    // 0x8003F5B8: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x8003F5BC: lh          $t5, 0x4A($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X4A);
    // 0x8003F5C0: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x8003F5C4: addu        $t4, $t3, $t2
    ctx->r12 = ADD32(ctx->r11, ctx->r10);
    // 0x8003F5C8: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x8003F5CC: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8003F5D0: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x8003F5D4: lh          $v1, 0xA($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XA);
    // 0x8003F5D8: beql        $t5, $v1, L_8003F668
    if (ctx->r13 == ctx->r3) {
        // 0x8003F5DC: lw          $t4, 0x4($v0)
        ctx->r12 = MEM_W(ctx->r2, 0X4);
            goto L_8003F668;
    }
    goto skip_2;
    // 0x8003F5DC: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    skip_2:
    // 0x8003F5E0: beq         $a3, $v1, L_8003F5F0
    if (ctx->r7 == ctx->r3) {
        // 0x8003F5E4: nop
    
            goto L_8003F5F0;
    }
    // 0x8003F5E4: nop

    // 0x8003F5E8: jal         0x8004A0C4
    // 0x8003F5EC: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    func_8004A0C4(rdram, ctx);
        goto after_6;
    // 0x8003F5EC: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    after_6:
L_8003F5F0:
    // 0x8003F5F0: jal         0x80049D80
    // 0x8003F5F4: lh          $a0, 0x4A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X4A);
    func_80049D80(rdram, ctx);
        goto after_7;
    // 0x8003F5F4: lh          $a0, 0x4A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X4A);
    after_7:
    // 0x8003F5F8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8003F5FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003F600: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x8003F604: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8003F608: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x8003F60C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8003F610: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x8003F614: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8003F618: jal         0x80049DFC
    // 0x8003F61C: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    func_80049DFC(rdram, ctx);
        goto after_8;
    // 0x8003F61C: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    after_8:
    // 0x8003F620: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x8003F624: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x8003F628: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8003F62C: sw          $v0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r2;
    // 0x8003F630: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x8003F634: addu        $t6, $t5, $s0
    ctx->r14 = ADD32(ctx->r13, ctx->r16);
    // 0x8003F638: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8003F63C: jal         0x8004A148
    // 0x8003F640: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    func_8004A148(rdram, ctx);
        goto after_9;
    // 0x8003F640: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    after_9:
    // 0x8003F644: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8003F648: lh          $t8, 0x4A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X4A);
    // 0x8003F64C: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x8003F650: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8003F654: sh          $t8, 0xA($t1)
    MEM_H(0XA, ctx->r9) = ctx->r24;
    // 0x8003F658: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x8003F65C: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x8003F660: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8003F664: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
L_8003F668:
    // 0x8003F668: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x8003F66C: lw          $v1, 0xE0($t5)
    ctx->r3 = MEM_W(ctx->r13, 0XE0);
    // 0x8003F670: beql        $v1, $zero, L_8003F694
    if (ctx->r3 == 0) {
        // 0x8003F674: lh          $t8, 0xE6($sp)
        ctx->r24 = MEM_H(ctx->r29, 0XE6);
            goto L_8003F694;
    }
    goto skip_3;
    // 0x8003F674: lh          $t8, 0xE6($sp)
    ctx->r24 = MEM_H(ctx->r29, 0XE6);
    skip_3:
    // 0x8003F678: lbu         $t6, 0x10($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X10);
    // 0x8003F67C: ori         $t7, $t6, 0x4
    ctx->r15 = ctx->r14 | 0X4;
    // 0x8003F680: sb          $t7, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r15;
    // 0x8003F684: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8003F688: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x8003F68C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8003F690: lh          $t8, 0xE6($sp)
    ctx->r24 = MEM_H(ctx->r29, 0XE6);
L_8003F694:
    // 0x8003F694: sh          $t8, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r24;
    // 0x8003F698: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x8003F69C: lh          $t1, 0xA($s1)
    ctx->r9 = MEM_H(ctx->r17, 0XA);
    // 0x8003F6A0: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x8003F6A4: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8003F6A8: sh          $t1, 0x8($t4)
    MEM_H(0X8, ctx->r12) = ctx->r9;
    // 0x8003F6AC: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x8003F6B0: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8003F6B4: addu        $t6, $t5, $s0
    ctx->r14 = ADD32(ctx->r13, ctx->r16);
    // 0x8003F6B8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8003F6BC: swc1        $f18, 0x74($t7)
    MEM_W(0X74, ctx->r15) = ctx->f18.u32l;
    // 0x8003F6C0: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8003F6C4: lh          $t9, 0x42($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X42);
    // 0x8003F6C8: addu        $t8, $t0, $s0
    ctx->r24 = ADD32(ctx->r8, ctx->r16);
    // 0x8003F6CC: lw          $t2, 0x0($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X0);
    // 0x8003F6D0: sh          $t9, 0x78($t2)
    MEM_H(0X78, ctx->r10) = ctx->r25;
    // 0x8003F6D4: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x8003F6D8: addu        $t1, $t3, $s0
    ctx->r9 = ADD32(ctx->r11, ctx->r16);
    // 0x8003F6DC: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x8003F6E0: jal         0x8000E35C
    // 0x8003F6E4: sh          $zero, 0x7A($t4)
    MEM_H(0X7A, ctx->r12) = 0;
    func_8000E35C(rdram, ctx);
        goto after_10;
    // 0x8003F6E4: sh          $zero, 0x7A($t4)
    MEM_H(0X7A, ctx->r12) = 0;
    after_10:
    // 0x8003F6E8: andi        $t5, $v0, 0x3
    ctx->r13 = ctx->r2 & 0X3;
    // 0x8003F6EC: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x8003F6F0: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8003F6F4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8003F6F8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003F6FC: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    // 0x8003F700: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8003F704: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
L_8003F708:
    // 0x8003F708: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8003F70C: lwc1        $f16, 0x0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8003F710: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8003F714: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x8003F718: lw          $t0, 0x0($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X0);
    // 0x8003F71C: addu        $t8, $t0, $v1
    ctx->r24 = ADD32(ctx->r8, ctx->r3);
    // 0x8003F720: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003F724: slti        $at, $v1, 0xC
    ctx->r1 = SIGNED(ctx->r3) < 0XC ? 1 : 0;
    // 0x8003F728: bne         $at, $zero, L_8003F708
    if (ctx->r1 != 0) {
        // 0x8003F72C: swc1        $f16, 0x50($t8)
        MEM_W(0X50, ctx->r24) = ctx->f16.u32l;
            goto L_8003F708;
    }
    // 0x8003F72C: swc1        $f16, 0x50($t8)
    MEM_W(0X50, ctx->r24) = ctx->f16.u32l;
    // 0x8003F730: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8003F734: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
L_8003F738:
    // 0x8003F738: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x8003F73C: jal         0x8000E35C
    // 0x8003F740: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_8000E35C(rdram, ctx);
        goto after_11;
    // 0x8003F740: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_11:
    // 0x8003F744: andi        $t9, $v0, 0x7
    ctx->r25 = ctx->r2 & 0X7;
    // 0x8003F748: addiu       $t2, $t9, -0x4
    ctx->r10 = ADD32(ctx->r25, -0X4);
    // 0x8003F74C: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8003F750: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003F754: lwc1        $f6, 0x76A4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X76A4);
    // 0x8003F758: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8003F75C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x8003F760: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8003F764: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x8003F768: addu        $t1, $t3, $s0
    ctx->r9 = ADD32(ctx->r11, ctx->r16);
    // 0x8003F76C: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x8003F770: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8003F774: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8003F778: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x8003F77C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003F780: slti        $at, $v1, 0xC
    ctx->r1 = SIGNED(ctx->r3) < 0XC ? 1 : 0;
    // 0x8003F784: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8003F788: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8003F78C: bne         $at, $zero, L_8003F738
    if (ctx->r1 != 0) {
        // 0x8003F790: swc1        $f16, 0x5C($t5)
        MEM_W(0X5C, ctx->r13) = ctx->f16.u32l;
            goto L_8003F738;
    }
    // 0x8003F790: swc1        $f16, 0x5C($t5)
    MEM_W(0X5C, ctx->r13) = ctx->f16.u32l;
    // 0x8003F794: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8003F798: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003F79C: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x8003F7A0: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x8003F7A4: lw          $t0, 0x0($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X0);
    // 0x8003F7A8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003F7AC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8003F7B0: lw          $a1, 0x5C($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X5C);
    // 0x8003F7B4: jal         0x80049840
    // 0x8003F7B8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80049840(rdram, ctx);
        goto after_12;
    // 0x8003F7B8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_12:
    // 0x8003F7BC: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8003F7C0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8003F7C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003F7C8: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x8003F7CC: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x8003F7D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003F7D4: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x8003F7D8: lwc1        $f18, 0x60($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X60);
    // 0x8003F7DC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003F7E0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8003F7E4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8003F7E8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8003F7EC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8003F7F0: jal         0x80049840
    // 0x8003F7F4: nop

    func_80049840(rdram, ctx);
        goto after_13;
    // 0x8003F7F4: nop

    after_13:
    // 0x8003F7F8: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x8003F7FC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8003F800: jal         0x80000BD8
    // 0x8003F804: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    func_80000BD8(rdram, ctx);
        goto after_14;
    // 0x8003F804: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    after_14:
    // 0x8003F808: lwc1        $f8, 0xB4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x8003F80C: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8003F810: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x8003F814: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003F818: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8003F81C: addu        $t1, $t3, $s0
    ctx->r9 = ADD32(ctx->r11, ctx->r16);
    // 0x8003F820: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x8003F824: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003F828: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x8003F82C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8003F830: swc1        $f16, 0x68($t4)
    MEM_W(0X68, ctx->r12) = ctx->f16.u32l;
    // 0x8003F834: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8003F838: lwc1        $f18, 0xB8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x8003F83C: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x8003F840: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8003F844: addu        $t6, $t5, $s0
    ctx->r14 = ADD32(ctx->r13, ctx->r16);
    // 0x8003F848: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8003F84C: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8003F850: swc1        $f8, 0x6C($t7)
    MEM_W(0X6C, ctx->r15) = ctx->f8.u32l;
    // 0x8003F854: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8003F858: lwc1        $f10, 0xBC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8003F85C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8003F860: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8003F864: addu        $t8, $t0, $s0
    ctx->r24 = ADD32(ctx->r8, ctx->r16);
    // 0x8003F868: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8003F86C: swc1        $f18, 0x70($t9)
    MEM_W(0X70, ctx->r25) = ctx->f18.u32l;
    // 0x8003F870: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x8003F874: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x8003F878: lw          $t1, 0x0($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X0);
    // 0x8003F87C: lw          $a1, 0x5C($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X5C);
    // 0x8003F880: jal         0x80049840
    // 0x8003F884: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80049840(rdram, ctx);
        goto after_15;
    // 0x8003F884: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_15:
    // 0x8003F888: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8003F88C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003F890: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x8003F894: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x8003F898: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8003F89C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8003F8A0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8003F8A4: lw          $a1, 0x60($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X60);
    // 0x8003F8A8: jal         0x80049840
    // 0x8003F8AC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80049840(rdram, ctx);
        goto after_16;
    // 0x8003F8AC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_16:
    // 0x8003F8B0: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x8003F8B4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8003F8B8: jal         0x80000BD8
    // 0x8003F8BC: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    func_80000BD8(rdram, ctx);
        goto after_17;
    // 0x8003F8BC: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    after_17:
    // 0x8003F8C0: lui         $a1, 0x3D88
    ctx->r5 = S32(0X3D88 << 16);
    // 0x8003F8C4: ori         $a1, $a1, 0x8889
    ctx->r5 = ctx->r5 | 0X8889;
    // 0x8003F8C8: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x8003F8CC: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x8003F8D0: jal         0x80001AB4
    // 0x8003F8D4: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    func_80001AB4(rdram, ctx);
        goto after_18;
    // 0x8003F8D4: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    after_18:
    // 0x8003F8D8: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x8003F8DC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8003F8E0: jal         0x80000BD8
    // 0x8003F8E4: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    func_80000BD8(rdram, ctx);
        goto after_19;
    // 0x8003F8E4: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    after_19:
    // 0x8003F8E8: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8003F8EC: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x8003F8F0: addu        $t8, $t0, $s0
    ctx->r24 = ADD32(ctx->r8, ctx->r16);
    // 0x8003F8F4: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8003F8F8: lw          $t2, 0x4($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X4);
    // 0x8003F8FC: lw          $a0, 0x8($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X8);
    // 0x8003F900: jal         0x80002340
    // 0x8003F904: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80002340(rdram, ctx);
        goto after_20;
    // 0x8003F904: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_20:
    // 0x8003F908: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8003F90C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
L_8003F910:
    // 0x8003F910: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x8003F914: addu        $t1, $t3, $s0
    ctx->r9 = ADD32(ctx->r11, ctx->r16);
    // 0x8003F918: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x8003F91C: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x8003F920: addu        $t4, $v0, $v1
    ctx->r12 = ADD32(ctx->r2, ctx->r3);
    // 0x8003F924: lwc1        $f6, 0x50($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X50);
    // 0x8003F928: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x8003F92C: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x8003F930: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003F934: bne         $v1, $a0, L_8003F910
    if (ctx->r3 != ctx->r4) {
        // 0x8003F938: swc1        $f6, 0x40($t7)
        MEM_W(0X40, ctx->r15) = ctx->f6.u32l;
            goto L_8003F910;
    }
    // 0x8003F938: swc1        $f6, 0x40($t7)
    MEM_W(0X40, ctx->r15) = ctx->f6.u32l;
    // 0x8003F93C: lh          $t0, 0x40($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X40);
    // 0x8003F940: beql        $t0, $zero, L_8003F954
    if (ctx->r8 == 0) {
        // 0x8003F944: lh          $t8, 0x4($s1)
        ctx->r24 = MEM_H(ctx->r17, 0X4);
            goto L_8003F954;
    }
    goto skip_4;
    // 0x8003F944: lh          $t8, 0x4($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X4);
    skip_4:
    // 0x8003F948: jal         0x80044480
    // 0x8003F94C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_80044480(rdram, ctx);
        goto after_21;
    // 0x8003F94C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_21:
    // 0x8003F950: lh          $t8, 0x4($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X4);
L_8003F954:
    // 0x8003F954: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003F958: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8003F95C: sh          $t9, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r25;
L_8003F960:
    // 0x8003F960: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003F964: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8003F968: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8003F96C: jr          $ra
    // 0x8003F970: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    TRACE_RETURN()
    return;
    // 0x8003F970: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
;}
RECOMP_FUNC void func_8003F974(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8003F974: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8003F978: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8003F97C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8003F980: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8003F984: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8003F988: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8003F98C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8003F990: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8003F994: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8003F998: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8003F99C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003F9A0: lh          $t6, 0x4($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X4);
    // 0x8003F9A4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8003F9A8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8003F9AC: beql        $t6, $zero, L_8003FF68
    if (ctx->r14 == 0) {
        // 0x8003F9B0: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8003FF68;
    }
    goto skip_0;
    // 0x8003F9B0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x8003F9B4: lw          $t7, -0x6630($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6630);
    // 0x8003F9B8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003F9BC: addiu       $t8, $zero, 0x11
    ctx->r24 = ADD32(0, 0X11);
    // 0x8003F9C0: bne         $t7, $at, L_8003F9D0
    if (ctx->r15 != ctx->r1) {
        // 0x8003F9C4: addiu       $t9, $zero, 0xC
        ctx->r25 = ADD32(0, 0XC);
            goto L_8003F9D0;
    }
    // 0x8003F9C4: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x8003F9C8: b           L_8003F9D4
    // 0x8003F9CC: sw          $t8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r24;
        goto L_8003F9D4;
    // 0x8003F9CC: sw          $t8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r24;
L_8003F9D0:
    // 0x8003F9D0: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
L_8003F9D4:
    // 0x8003F9D4: lh          $v1, 0x6($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X6);
    // 0x8003F9D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8003F9DC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8003F9E0: blez        $v1, L_8003FF64
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8003F9E4: lh          $s7, 0x5E($sp)
        ctx->r23 = MEM_H(ctx->r29, 0X5E);
            goto L_8003FF64;
    }
    // 0x8003F9E4: lh          $s7, 0x5E($sp)
    ctx->r23 = MEM_H(ctx->r29, 0X5E);
    // 0x8003F9E8: lh          $s6, 0x5C($sp)
    ctx->r22 = MEM_H(ctx->r29, 0X5C);
    // 0x8003F9EC: addiu       $s5, $zero, 0xC
    ctx->r21 = ADD32(0, 0XC);
L_8003F9F0:
    // 0x8003F9F0: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8003F9F4: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x8003F9F8: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8003F9FC: addu        $t1, $t0, $s2
    ctx->r9 = ADD32(ctx->r8, ctx->r18);
    // 0x8003FA00: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8003FA04: lh          $t3, 0x8($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X8);
    // 0x8003FA08: blezl       $t3, L_8003FF50
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8003FA0C: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8003FF50;
    }
    goto skip_1;
    // 0x8003FA0C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_1:
    // 0x8003FA10: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8003FA14: sw          $a0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r4;
    // 0x8003FA18: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8003FA1C: addiu       $s5, $s5, -0x4
    ctx->r21 = ADD32(ctx->r21, -0X4);
    // 0x8003FA20: addu        $t5, $t4, $s2
    ctx->r13 = ADD32(ctx->r12, ctx->r18);
    // 0x8003FA24: beq         $v1, $s5, L_8003FA78
    if (ctx->r3 == ctx->r21) {
        // 0x8003FA28: lw          $t6, 0x0($t5)
        ctx->r14 = MEM_W(ctx->r13, 0X0);
            goto L_8003FA78;
    }
    // 0x8003FA28: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
L_8003FA2C:
    // 0x8003FA2C: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
    // 0x8003FA30: lwc1        $f18, 0x50($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X50);
    // 0x8003FA34: lwc1        $f16, 0x68($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X68);
    // 0x8003FA38: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8003FA3C: swc1        $f16, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f16.u32l;
    // 0x8003FA40: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8003FA44: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x8003FA48: lw          $s0, 0x0($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X0);
    // 0x8003FA4C: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x8003FA50: addu        $t9, $s0, $v1
    ctx->r25 = ADD32(ctx->r16, ctx->r3);
    // 0x8003FA54: lwc1        $f16, 0x50($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X50);
    // 0x8003FA58: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x8003FA5C: addu        $t2, $t1, $v1
    ctx->r10 = ADD32(ctx->r9, ctx->r3);
    // 0x8003FA60: swc1        $f16, 0x40($t2)
    MEM_W(0X40, ctx->r10) = ctx->f16.u32l;
    // 0x8003FA64: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8003FA68: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003FA6C: addu        $t5, $t4, $s2
    ctx->r13 = ADD32(ctx->r12, ctx->r18);
    // 0x8003FA70: bne         $v1, $s5, L_8003FA2C
    if (ctx->r3 != ctx->r21) {
        // 0x8003FA74: lw          $t6, 0x0($t5)
        ctx->r14 = MEM_W(ctx->r13, 0X0);
            goto L_8003FA2C;
    }
    // 0x8003FA74: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
L_8003FA78:
    // 0x8003FA78: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
    // 0x8003FA7C: lwc1        $f18, 0x50($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X50);
    // 0x8003FA80: lwc1        $f16, 0x68($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X68);
    // 0x8003FA84: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x8003FA88: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8003FA8C: swc1        $f16, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f16.u32l;
    // 0x8003FA90: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8003FA94: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x8003FA98: lw          $s0, 0x0($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X0);
    // 0x8003FA9C: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x8003FAA0: addu        $t9, $s0, $v1
    ctx->r25 = ADD32(ctx->r16, ctx->r3);
    // 0x8003FAA4: lwc1        $f16, 0x50($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X50);
    // 0x8003FAA8: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x8003FAAC: addu        $t2, $t1, $v1
    ctx->r10 = ADD32(ctx->r9, ctx->r3);
    // 0x8003FAB0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003FAB4: swc1        $f16, 0x40($t2)
    MEM_W(0X40, ctx->r10) = ctx->f16.u32l;
    // 0x8003FAB8: lh          $t3, 0x8($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X8);
    // 0x8003FABC: bnel        $t3, $zero, L_8003FB30
    if (ctx->r11 != 0) {
        // 0x8003FAC0: lw          $t3, 0x0($s1)
        ctx->r11 = MEM_W(ctx->r17, 0X0);
            goto L_8003FB30;
    }
    goto skip_2;
    // 0x8003FAC0: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    skip_2:
    // 0x8003FAC4: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8003FAC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003FACC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8003FAD0: addu        $t5, $t4, $s2
    ctx->r13 = ADD32(ctx->r12, ctx->r18);
    // 0x8003FAD4: lw          $s0, 0x0($t5)
    ctx->r16 = MEM_W(ctx->r13, 0X0);
    // 0x8003FAD8: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // 0x8003FADC: jal         0x8001F2CC
    // 0x8003FAE0: lh          $a1, 0x78($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X78);
    func_8001F2CC(rdram, ctx);
        goto after_0;
    // 0x8003FAE0: lh          $a1, 0x78($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X78);
    after_0:
    // 0x8003FAE4: beq         $v0, $zero, L_8003FB90
    if (ctx->r2 == 0) {
        // 0x8003FAE8: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8003FB90;
    }
    // 0x8003FAE8: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8003FAEC: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8003FAF0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003FAF4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8003FAF8: addu        $t7, $t6, $s2
    ctx->r15 = ADD32(ctx->r14, ctx->r18);
    // 0x8003FAFC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8003FB00: sh          $zero, 0x8($t8)
    MEM_H(0X8, ctx->r24) = 0;
    // 0x8003FB04: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8003FB08: addu        $t0, $t9, $s2
    ctx->r8 = ADD32(ctx->r25, ctx->r18);
    // 0x8003FB0C: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8003FB10: jal         0x80043714
    // 0x8003FB14: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    func_80043714(rdram, ctx);
        goto after_1;
    // 0x8003FB14: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    after_1:
    // 0x8003FB18: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x8003FB1C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8003FB20: addu        $t2, $t1, $s2
    ctx->r10 = ADD32(ctx->r9, ctx->r18);
    // 0x8003FB24: b           L_8003FD9C
    // 0x8003FB28: lw          $s0, 0x0($t2)
    ctx->r16 = MEM_W(ctx->r10, 0X0);
        goto L_8003FD9C;
    // 0x8003FB28: lw          $s0, 0x0($t2)
    ctx->r16 = MEM_W(ctx->r10, 0X0);
    // 0x8003FB2C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
L_8003FB30:
    // 0x8003FB30: addu        $t4, $t3, $s2
    ctx->r12 = ADD32(ctx->r11, ctx->r18);
    // 0x8003FB34: lw          $s0, 0x0($t4)
    ctx->r16 = MEM_W(ctx->r12, 0X0);
    // 0x8003FB38: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // 0x8003FB3C: jal         0x8004267C
    // 0x8003FB40: lh          $a1, 0x78($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X78);
    func_8004267C(rdram, ctx);
        goto after_2;
    // 0x8003FB40: lh          $a1, 0x78($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X78);
    after_2:
    // 0x8003FB44: beq         $v0, $zero, L_8003FB90
    if (ctx->r2 == 0) {
        // 0x8003FB48: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8003FB90;
    }
    // 0x8003FB48: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8003FB4C: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x8003FB50: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8003FB54: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8003FB58: addu        $t6, $t5, $s2
    ctx->r14 = ADD32(ctx->r13, ctx->r18);
    // 0x8003FB5C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8003FB60: sh          $zero, 0x8($t7)
    MEM_H(0X8, ctx->r15) = 0;
    // 0x8003FB64: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8003FB68: addu        $t9, $t8, $s2
    ctx->r25 = ADD32(ctx->r24, ctx->r18);
    // 0x8003FB6C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x8003FB70: jal         0x80043714
    // 0x8003FB74: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    func_80043714(rdram, ctx);
        goto after_3;
    // 0x8003FB74: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    after_3:
    // 0x8003FB78: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8003FB7C: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x8003FB80: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8003FB84: addu        $t1, $t0, $s2
    ctx->r9 = ADD32(ctx->r8, ctx->r18);
    // 0x8003FB88: b           L_8003FD9C
    // 0x8003FB8C: lw          $s0, 0x0($t1)
    ctx->r16 = MEM_W(ctx->r9, 0X0);
        goto L_8003FD9C;
    // 0x8003FB8C: lw          $s0, 0x0($t1)
    ctx->r16 = MEM_W(ctx->r9, 0X0);
L_8003FB90:
    // 0x8003FB90: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x8003FB94: addu        $t3, $t2, $s2
    ctx->r11 = ADD32(ctx->r10, ctx->r18);
    // 0x8003FB98: lw          $s0, 0x0($t3)
    ctx->r16 = MEM_W(ctx->r11, 0X0);
    // 0x8003FB9C: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // 0x8003FBA0: jal         0x8001F9B0
    // 0x8003FBA4: lh          $a1, 0x78($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X78);
    func_8001F9B0(rdram, ctx);
        goto after_4;
    // 0x8003FBA4: lh          $a1, 0x78($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X78);
    after_4:
    // 0x8003FBA8: beq         $v0, $zero, L_8003FBFC
    if (ctx->r2 == 0) {
        // 0x8003FBAC: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8003FBFC;
    }
    // 0x8003FBAC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8003FBB0: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8003FBB4: addu        $t5, $t4, $s2
    ctx->r13 = ADD32(ctx->r12, ctx->r18);
    // 0x8003FBB8: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8003FBBC: sh          $zero, 0x8($t6)
    MEM_H(0X8, ctx->r14) = 0;
    // 0x8003FBC0: lh          $t7, 0x8($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X8);
    // 0x8003FBC4: bnel        $t7, $zero, L_8003FBF0
    if (ctx->r15 != 0) {
        // 0x8003FBC8: lw          $t0, 0x0($s1)
        ctx->r8 = MEM_W(ctx->r17, 0X0);
            goto L_8003FBF0;
    }
    goto skip_3;
    // 0x8003FBC8: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    skip_3:
    // 0x8003FBCC: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8003FBD0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003FBD4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8003FBD8: addu        $t9, $t8, $s2
    ctx->r25 = ADD32(ctx->r24, ctx->r18);
    // 0x8003FBDC: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x8003FBE0: jal         0x80043714
    // 0x8003FBE4: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    func_80043714(rdram, ctx);
        goto after_5;
    // 0x8003FBE4: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    after_5:
    // 0x8003FBE8: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8003FBEC: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
L_8003FBF0:
    // 0x8003FBF0: addu        $t1, $t0, $s2
    ctx->r9 = ADD32(ctx->r8, ctx->r18);
    // 0x8003FBF4: b           L_8003FD9C
    // 0x8003FBF8: lw          $s0, 0x0($t1)
    ctx->r16 = MEM_W(ctx->r9, 0X0);
        goto L_8003FD9C;
    // 0x8003FBF8: lw          $s0, 0x0($t1)
    ctx->r16 = MEM_W(ctx->r9, 0X0);
L_8003FBFC:
    // 0x8003FBFC: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x8003FC00: addu        $t3, $t2, $s2
    ctx->r11 = ADD32(ctx->r10, ctx->r18);
    // 0x8003FC04: lw          $s0, 0x0($t3)
    ctx->r16 = MEM_W(ctx->r11, 0X0);
    // 0x8003FC08: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // 0x8003FC0C: jal         0x800423C0
    // 0x8003FC10: lh          $a1, 0x78($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X78);
    func_800423C0(rdram, ctx);
        goto after_6;
    // 0x8003FC10: lh          $a1, 0x78($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X78);
    after_6:
    // 0x8003FC14: beq         $v0, $zero, L_8003FC4C
    if (ctx->r2 == 0) {
        // 0x8003FC18: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8003FC4C;
    }
    // 0x8003FC18: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8003FC1C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8003FC20: addu        $t5, $t4, $s2
    ctx->r13 = ADD32(ctx->r12, ctx->r18);
    // 0x8003FC24: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8003FC28: sh          $zero, 0x8($t6)
    MEM_H(0X8, ctx->r14) = 0;
    // 0x8003FC2C: lh          $t7, 0x8($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X8);
    // 0x8003FC30: bnel        $t7, $zero, L_8003FC40
    if (ctx->r15 != 0) {
        // 0x8003FC34: lw          $t8, 0x0($s1)
        ctx->r24 = MEM_W(ctx->r17, 0X0);
            goto L_8003FC40;
    }
    goto skip_4;
    // 0x8003FC34: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    skip_4:
    // 0x8003FC38: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8003FC3C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
L_8003FC40:
    // 0x8003FC40: addu        $t9, $t8, $s2
    ctx->r25 = ADD32(ctx->r24, ctx->r18);
    // 0x8003FC44: b           L_8003FD9C
    // 0x8003FC48: lw          $s0, 0x0($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X0);
        goto L_8003FD9C;
    // 0x8003FC48: lw          $s0, 0x0($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X0);
L_8003FC4C:
    // 0x8003FC4C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8003FC50: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x8003FC54: addu        $t1, $t0, $s2
    ctx->r9 = ADD32(ctx->r8, ctx->r18);
    // 0x8003FC58: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x8003FC5C: jal         0x8000D3A4
    // 0x8003FC60: addiu       $a1, $a1, 0x50
    ctx->r5 = ADD32(ctx->r5, 0X50);
    func_8000D3A4(rdram, ctx);
        goto after_7;
    // 0x8003FC60: addiu       $a1, $a1, 0x50
    ctx->r5 = ADD32(ctx->r5, 0X50);
    after_7:
    // 0x8003FC64: beql        $v0, $zero, L_8003FCD8
    if (ctx->r2 == 0) {
        // 0x8003FC68: lh          $t3, 0x8($s1)
        ctx->r11 = MEM_H(ctx->r17, 0X8);
            goto L_8003FCD8;
    }
    goto skip_5;
    // 0x8003FC68: lh          $t3, 0x8($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X8);
    skip_5:
    // 0x8003FC6C: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x8003FC70: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x8003FC74: addu        $t3, $t2, $s2
    ctx->r11 = ADD32(ctx->r10, ctx->r18);
    // 0x8003FC78: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x8003FC7C: jal         0x80003668
    // 0x8003FC80: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    func_80003668(rdram, ctx);
        goto after_8;
    // 0x8003FC80: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    after_8:
    // 0x8003FC84: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8003FC88: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x8003FC8C: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x8003FC90: nop

    // 0x8003FC94: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8003FC98: beql        $at, $zero, L_8003FCD8
    if (ctx->r1 == 0) {
        // 0x8003FC9C: lh          $t3, 0x8($s1)
        ctx->r11 = MEM_H(ctx->r17, 0X8);
            goto L_8003FCD8;
    }
    goto skip_6;
    // 0x8003FC9C: lh          $t3, 0x8($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X8);
    skip_6:
    // 0x8003FCA0: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8003FCA4: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8003FCA8: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x8003FCAC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8003FCB0: sh          $zero, 0x8($t9)
    MEM_H(0X8, ctx->r25) = 0;
    // 0x8003FCB4: lh          $t0, 0x8($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X8);
    // 0x8003FCB8: bnel        $t0, $zero, L_8003FCC8
    if (ctx->r8 != 0) {
        // 0x8003FCBC: lw          $t1, 0x0($s1)
        ctx->r9 = MEM_W(ctx->r17, 0X0);
            goto L_8003FCC8;
    }
    goto skip_7;
    // 0x8003FCBC: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    skip_7:
    // 0x8003FCC0: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8003FCC4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
L_8003FCC8:
    // 0x8003FCC8: addu        $t2, $t1, $s2
    ctx->r10 = ADD32(ctx->r9, ctx->r18);
    // 0x8003FCCC: b           L_8003FD9C
    // 0x8003FCD0: lw          $s0, 0x0($t2)
    ctx->r16 = MEM_W(ctx->r10, 0X0);
        goto L_8003FD9C;
    // 0x8003FCD0: lw          $s0, 0x0($t2)
    ctx->r16 = MEM_W(ctx->r10, 0X0);
    // 0x8003FCD4: lh          $t3, 0x8($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X8);
L_8003FCD8:
    // 0x8003FCD8: bnel        $t3, $zero, L_8003FD24
    if (ctx->r11 != 0) {
        // 0x8003FCDC: lw          $t1, 0x0($s1)
        ctx->r9 = MEM_W(ctx->r17, 0X0);
            goto L_8003FD24;
    }
    goto skip_8;
    // 0x8003FCDC: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    skip_8:
    // 0x8003FCE0: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8003FCE4: addu        $t5, $t4, $s2
    ctx->r13 = ADD32(ctx->r12, ctx->r18);
    // 0x8003FCE8: lw          $s0, 0x0($t5)
    ctx->r16 = MEM_W(ctx->r13, 0X0);
    // 0x8003FCEC: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // 0x8003FCF0: jal         0x800427D0
    // 0x8003FCF4: lh          $a1, 0x78($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X78);
    func_800427D0(rdram, ctx);
        goto after_9;
    // 0x8003FCF4: lh          $a1, 0x78($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X78);
    after_9:
    // 0x8003FCF8: beq         $v0, $zero, L_8003FD20
    if (ctx->r2 == 0) {
        // 0x8003FCFC: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8003FD20;
    }
    // 0x8003FCFC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8003FD00: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8003FD04: addu        $t7, $t6, $s2
    ctx->r15 = ADD32(ctx->r14, ctx->r18);
    // 0x8003FD08: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8003FD0C: sh          $zero, 0x8($t8)
    MEM_H(0X8, ctx->r24) = 0;
    // 0x8003FD10: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8003FD14: addu        $t0, $t9, $s2
    ctx->r8 = ADD32(ctx->r25, ctx->r18);
    // 0x8003FD18: b           L_8003FD9C
    // 0x8003FD1C: lw          $s0, 0x0($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X0);
        goto L_8003FD9C;
    // 0x8003FD1C: lw          $s0, 0x0($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X0);
L_8003FD20:
    // 0x8003FD20: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
L_8003FD24:
    // 0x8003FD24: addu        $t2, $t1, $s2
    ctx->r10 = ADD32(ctx->r9, ctx->r18);
    // 0x8003FD28: lw          $s0, 0x0($t2)
    ctx->r16 = MEM_W(ctx->r10, 0X0);
    // 0x8003FD2C: lh          $t3, 0x7A($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X7A);
    // 0x8003FD30: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // 0x8003FD34: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x8003FD38: bnel        $t4, $zero, L_8003FD6C
    if (ctx->r12 != 0) {
        // 0x8003FD3C: lw          $t9, 0x0($s1)
        ctx->r25 = MEM_W(ctx->r17, 0X0);
            goto L_8003FD6C;
    }
    goto skip_9;
    // 0x8003FD3C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    skip_9:
    // 0x8003FD40: jal         0x8003E3F8
    // 0x8003FD44: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_8003E3F8(rdram, ctx);
        goto after_10;
    // 0x8003FD44: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_10:
    // 0x8003FD48: beql        $v0, $zero, L_8003FD6C
    if (ctx->r2 == 0) {
        // 0x8003FD4C: lw          $t9, 0x0($s1)
        ctx->r25 = MEM_W(ctx->r17, 0X0);
            goto L_8003FD6C;
    }
    goto skip_10;
    // 0x8003FD4C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    skip_10:
    // 0x8003FD50: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x8003FD54: addu        $t6, $t5, $s2
    ctx->r14 = ADD32(ctx->r13, ctx->r18);
    // 0x8003FD58: lw          $s0, 0x0($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X0);
    // 0x8003FD5C: lh          $t7, 0x7A($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X7A);
    // 0x8003FD60: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x8003FD64: sh          $t8, 0x7A($s0)
    MEM_H(0X7A, ctx->r16) = ctx->r24;
    // 0x8003FD68: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
L_8003FD6C:
    // 0x8003FD6C: addu        $t0, $t9, $s2
    ctx->r8 = ADD32(ctx->r25, ctx->r18);
    // 0x8003FD70: lw          $s0, 0x0($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X0);
    // 0x8003FD74: lh          $v0, 0x8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X8);
    // 0x8003FD78: beq         $v0, $zero, L_8003FD94
    if (ctx->r2 == 0) {
        // 0x8003FD7C: addiu       $t1, $v0, -0x1
        ctx->r9 = ADD32(ctx->r2, -0X1);
            goto L_8003FD94;
    }
    // 0x8003FD7C: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x8003FD80: sh          $t1, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r9;
    // 0x8003FD84: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x8003FD88: addu        $t3, $t2, $s2
    ctx->r11 = ADD32(ctx->r10, ctx->r18);
    // 0x8003FD8C: lw          $s0, 0x0($t3)
    ctx->r16 = MEM_W(ctx->r11, 0X0);
    // 0x8003FD90: lh          $v0, 0x8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X8);
L_8003FD94:
    // 0x8003FD94: bnel        $v0, $zero, L_8003FF34
    if (ctx->r2 != 0) {
        // 0x8003FD98: lw          $t8, 0x4($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X4);
            goto L_8003FF34;
    }
    goto skip_11;
    // 0x8003FD98: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    skip_11:
L_8003FD9C:
    // 0x8003FD9C: beql        $s3, $zero, L_8003FED8
    if (ctx->r19 == 0) {
        // 0x8003FDA0: lw          $t7, 0x4($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X4);
            goto L_8003FED8;
    }
    goto skip_12;
    // 0x8003FDA0: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    skip_12:
    // 0x8003FDA4: lh          $t4, 0xC($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XC);
    // 0x8003FDA8: bnel        $t4, $zero, L_8003FE8C
    if (ctx->r12 != 0) {
        // 0x8003FDAC: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_8003FE8C;
    }
    goto skip_13;
    // 0x8003FDAC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    skip_13:
    // 0x8003FDB0: jal         0x8000E35C
    // 0x8003FDB4: nop

    func_8000E35C(rdram, ctx);
        goto after_11;
    // 0x8003FDB4: nop

    after_11:
    // 0x8003FDB8: addiu       $t5, $s3, -0x1
    ctx->r13 = ADD32(ctx->r19, -0X1);
    // 0x8003FDBC: sltiu       $at, $t5, 0x5
    ctx->r1 = ctx->r13 < 0X5 ? 1 : 0;
    // 0x8003FDC0: beq         $at, $zero, L_8003FE90
    if (ctx->r1 == 0) {
        // 0x8003FDC4: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_8003FE90;
    }
    // 0x8003FDC4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8003FDC8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003FDCC: addu        $at, $at, $t5
    gpr jr_addend_8003FDD4 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8003FDD0: lw          $t5, 0x76A8($at)
    ctx->r13 = ADD32(ctx->r1, 0X76A8);
    // 0x8003FDD4: jr          $t5
    // 0x8003FDD8: nop

    switch (jr_addend_8003FDD4 >> 2) {
        case 0: goto L_8003FDDC; break;
        case 1: goto L_8003FDF8; break;
        case 2: goto L_8003FE1C; break;
        case 3: goto L_8003FE40; break;
        case 4: goto L_8003FE64; break;
        default: switch_error(__func__, 0x8003FDD4, 0x800776A8);
    }
    // 0x8003FDD8: nop

L_8003FDDC:
    // 0x8003FDDC: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x8003FDE0: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8003FDE4: lui         $s6, 0x8007
    ctx->r22 = S32(0X8007 << 16);
    // 0x8003FDE8: addu        $s6, $s6, $t7
    ctx->r22 = ADD32(ctx->r22, ctx->r15);
    // 0x8003FDEC: addiu       $s7, $zero, 0xB
    ctx->r23 = ADD32(0, 0XB);
    // 0x8003FDF0: b           L_8003FE90
    // 0x8003FDF4: lh          $s6, -0x5978($s6)
    ctx->r22 = MEM_H(ctx->r22, -0X5978);
        goto L_8003FE90;
    // 0x8003FDF4: lh          $s6, -0x5978($s6)
    ctx->r22 = MEM_H(ctx->r22, -0X5978);
L_8003FDF8:
    // 0x8003FDF8: andi        $v1, $v0, 0x3
    ctx->r3 = ctx->r2 & 0X3;
    // 0x8003FDFC: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    // 0x8003FE00: lui         $s7, 0x8007
    ctx->r23 = S32(0X8007 << 16);
    // 0x8003FE04: lui         $s6, 0x8007
    ctx->r22 = S32(0X8007 << 16);
    // 0x8003FE08: addu        $s7, $s7, $t8
    ctx->r23 = ADD32(ctx->r23, ctx->r24);
    // 0x8003FE0C: addu        $s6, $s6, $t8
    ctx->r22 = ADD32(ctx->r22, ctx->r24);
    // 0x8003FE10: lh          $s7, -0x5998($s7)
    ctx->r23 = MEM_H(ctx->r23, -0X5998);
    // 0x8003FE14: b           L_8003FE90
    // 0x8003FE18: lh          $s6, -0x5970($s6)
    ctx->r22 = MEM_H(ctx->r22, -0X5970);
        goto L_8003FE90;
    // 0x8003FE18: lh          $s6, -0x5970($s6)
    ctx->r22 = MEM_H(ctx->r22, -0X5970);
L_8003FE1C:
    // 0x8003FE1C: andi        $v1, $v0, 0x3
    ctx->r3 = ctx->r2 & 0X3;
    // 0x8003FE20: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x8003FE24: lui         $s7, 0x8007
    ctx->r23 = S32(0X8007 << 16);
    // 0x8003FE28: lui         $s6, 0x8007
    ctx->r22 = S32(0X8007 << 16);
    // 0x8003FE2C: addu        $s7, $s7, $t9
    ctx->r23 = ADD32(ctx->r23, ctx->r25);
    // 0x8003FE30: addu        $s6, $s6, $t9
    ctx->r22 = ADD32(ctx->r22, ctx->r25);
    // 0x8003FE34: lh          $s7, -0x5990($s7)
    ctx->r23 = MEM_H(ctx->r23, -0X5990);
    // 0x8003FE38: b           L_8003FE90
    // 0x8003FE3C: lh          $s6, -0x5968($s6)
    ctx->r22 = MEM_H(ctx->r22, -0X5968);
        goto L_8003FE90;
    // 0x8003FE3C: lh          $s6, -0x5968($s6)
    ctx->r22 = MEM_H(ctx->r22, -0X5968);
L_8003FE40:
    // 0x8003FE40: andi        $v1, $v0, 0x3
    ctx->r3 = ctx->r2 & 0X3;
    // 0x8003FE44: sll         $t0, $v1, 1
    ctx->r8 = S32(ctx->r3 << 1);
    // 0x8003FE48: lui         $s7, 0x8007
    ctx->r23 = S32(0X8007 << 16);
    // 0x8003FE4C: lui         $s6, 0x8007
    ctx->r22 = S32(0X8007 << 16);
    // 0x8003FE50: addu        $s7, $s7, $t0
    ctx->r23 = ADD32(ctx->r23, ctx->r8);
    // 0x8003FE54: addu        $s6, $s6, $t0
    ctx->r22 = ADD32(ctx->r22, ctx->r8);
    // 0x8003FE58: lh          $s7, -0x5988($s7)
    ctx->r23 = MEM_H(ctx->r23, -0X5988);
    // 0x8003FE5C: b           L_8003FE90
    // 0x8003FE60: lh          $s6, -0x5960($s6)
    ctx->r22 = MEM_H(ctx->r22, -0X5960);
        goto L_8003FE90;
    // 0x8003FE60: lh          $s6, -0x5960($s6)
    ctx->r22 = MEM_H(ctx->r22, -0X5960);
L_8003FE64:
    // 0x8003FE64: andi        $v1, $v0, 0x3
    ctx->r3 = ctx->r2 & 0X3;
    // 0x8003FE68: sll         $t1, $v1, 1
    ctx->r9 = S32(ctx->r3 << 1);
    // 0x8003FE6C: lui         $s7, 0x8007
    ctx->r23 = S32(0X8007 << 16);
    // 0x8003FE70: lui         $s6, 0x8007
    ctx->r22 = S32(0X8007 << 16);
    // 0x8003FE74: addu        $s7, $s7, $t1
    ctx->r23 = ADD32(ctx->r23, ctx->r9);
    // 0x8003FE78: addu        $s6, $s6, $t1
    ctx->r22 = ADD32(ctx->r22, ctx->r9);
    // 0x8003FE7C: lh          $s7, -0x5980($s7)
    ctx->r23 = MEM_H(ctx->r23, -0X5980);
    // 0x8003FE80: b           L_8003FE90
    // 0x8003FE84: lh          $s6, -0x5958($s6)
    ctx->r22 = MEM_H(ctx->r22, -0X5958);
        goto L_8003FE90;
    // 0x8003FE84: lh          $s6, -0x5958($s6)
    ctx->r22 = MEM_H(ctx->r22, -0X5958);
    // 0x8003FE88: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_8003FE8C:
    // 0x8003FE8C: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
L_8003FE90:
    // 0x8003FE90: beq         $s4, $zero, L_8003FEA4
    if (ctx->r20 == 0) {
        // 0x8003FE94: sll         $a0, $s7, 16
        ctx->r4 = S32(ctx->r23 << 16);
            goto L_8003FEA4;
    }
    // 0x8003FE94: sll         $a0, $s7, 16
    ctx->r4 = S32(ctx->r23 << 16);
    // 0x8003FE98: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8003FE9C: jal         0x80044480
    // 0x8003FEA0: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    func_80044480(rdram, ctx);
        goto after_12;
    // 0x8003FEA0: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_12:
L_8003FEA4:
    // 0x8003FEA4: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x8003FEA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003FEAC: addu        $t4, $t3, $s2
    ctx->r12 = ADD32(ctx->r11, ctx->r18);
    // 0x8003FEB0: beq         $fp, $zero, L_8003FEBC
    if (ctx->r30 == 0) {
        // 0x8003FEB4: lw          $s0, 0x0($t4)
        ctx->r16 = MEM_W(ctx->r12, 0X0);
            goto L_8003FEBC;
    }
    // 0x8003FEB4: lw          $s0, 0x0($t4)
    ctx->r16 = MEM_W(ctx->r12, 0X0);
    // 0x8003FEB8: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
L_8003FEBC:
    // 0x8003FEBC: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // 0x8003FEC0: jal         0x80042F80
    // 0x8003FEC4: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_80042F80(rdram, ctx);
        goto after_13;
    // 0x8003FEC4: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_13:
    // 0x8003FEC8: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x8003FECC: addu        $t6, $t5, $s2
    ctx->r14 = ADD32(ctx->r13, ctx->r18);
    // 0x8003FED0: lw          $s0, 0x0($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X0);
    // 0x8003FED4: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
L_8003FED8:
    // 0x8003FED8: lw          $v0, 0x8($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X8);
    // 0x8003FEDC: lw          $v1, 0xE0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XE0);
    // 0x8003FEE0: beql        $v1, $zero, L_8003FF0C
    if (ctx->r3 == 0) {
        // 0x8003FEE4: lw          $t4, 0xD8($v0)
        ctx->r12 = MEM_W(ctx->r2, 0XD8);
            goto L_8003FF0C;
    }
    goto skip_14;
    // 0x8003FEE4: lw          $t4, 0xD8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XD8);
    skip_14:
    // 0x8003FEE8: lbu         $t8, 0x10($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X10);
    // 0x8003FEEC: andi        $t9, $t8, 0xFFFB
    ctx->r25 = ctx->r24 & 0XFFFB;
    // 0x8003FEF0: sb          $t9, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r25;
    // 0x8003FEF4: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8003FEF8: addu        $t1, $t0, $s2
    ctx->r9 = ADD32(ctx->r8, ctx->r18);
    // 0x8003FEFC: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8003FF00: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x8003FF04: lw          $v0, 0x8($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X8);
    // 0x8003FF08: lw          $t4, 0xD8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XD8);
L_8003FF0C:
    // 0x8003FF0C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8003FF10: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x8003FF14: sw          $t5, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r13;
    // 0x8003FF18: lh          $t6, 0x4($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X4);
    // 0x8003FF1C: lh          $v1, 0x6($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X6);
    // 0x8003FF20: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8003FF24: sh          $t7, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r15;
    // 0x8003FF28: b           L_8003FF4C
    // 0x8003FF2C: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
        goto L_8003FF4C;
    // 0x8003FF2C: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x8003FF30: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
L_8003FF34:
    // 0x8003FF34: lw          $v0, 0x8($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X8);
    // 0x8003FF38: lw          $t9, 0xD8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XD8);
    // 0x8003FF3C: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x8003FF40: sw          $t0, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r8;
    // 0x8003FF44: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x8003FF48: lh          $v1, 0x6($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X6);
L_8003FF4C:
    // 0x8003FF4C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8003FF50:
    // 0x8003FF50: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003FF54: bne         $at, $zero, L_8003F9F0
    if (ctx->r1 != 0) {
        // 0x8003FF58: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8003F9F0;
    }
    // 0x8003FF58: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8003FF5C: sh          $s7, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r23;
    // 0x8003FF60: sh          $s6, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r22;
L_8003FF64:
    // 0x8003FF64: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8003FF68:
    // 0x8003FF68: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003FF6C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8003FF70: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8003FF74: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8003FF78: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8003FF7C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8003FF80: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8003FF84: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8003FF88: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8003FF8C: jr          $ra
    // 0x8003FF90: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    TRACE_RETURN()
    return;
    // 0x8003FF90: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_8003FF94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8003FF94: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8003FF98: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8003FF9C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8003FFA0: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8003FFA4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8003FFA8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8003FFAC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8003FFB0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8003FFB4: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x8003FFB8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8003FFBC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8003FFC0: blez        $t6, L_80040024
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8003FFC4: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80040024;
    }
    // 0x8003FFC4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8003FFC8: lui         $s5, 0x801A
    ctx->r21 = S32(0X801A << 16);
    // 0x8003FFCC: addiu       $s5, $s5, 0x2800
    ctx->r21 = ADD32(ctx->r21, 0X2800);
    // 0x8003FFD0: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // 0x8003FFD4: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
L_8003FFD8:
    // 0x8003FFD8: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x8003FFDC: lw          $s0, 0x0($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X0);
    // 0x8003FFE0: lh          $t9, 0xA($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XA);
    // 0x8003FFE4: beql        $s4, $t9, L_80040004
    if (ctx->r20 == ctx->r25) {
        // 0x8003FFE8: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80040004;
    }
    goto skip_0;
    // 0x8003FFE8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_0:
    // 0x8003FFEC: jal         0x8004A0C4
    // 0x8003FFF0: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    func_8004A0C4(rdram, ctx);
        goto after_0;
    // 0x8003FFF0: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_0:
    // 0x8003FFF4: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x8003FFF8: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x8003FFFC: lw          $s0, 0x0($t1)
    ctx->r16 = MEM_W(ctx->r9, 0X0);
    // 0x80040000: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80040004:
    // 0x80040004: jal         0x800042A8
    // 0x80040008: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800042A8(rdram, ctx);
        goto after_1;
    // 0x80040008: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x8004000C: lh          $t2, 0x6($s3)
    ctx->r10 = MEM_H(ctx->r19, 0X6);
    // 0x80040010: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80040014: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80040018: slt         $at, $s2, $t2
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8004001C: bnel        $at, $zero, L_8003FFD8
    if (ctx->r1 != 0) {
        // 0x80040020: lw          $t7, 0x0($s3)
        ctx->r15 = MEM_W(ctx->r19, 0X0);
            goto L_8003FFD8;
    }
    goto skip_1;
    // 0x80040020: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    skip_1:
L_80040024:
    // 0x80040024: lui         $s5, 0x801A
    ctx->r21 = S32(0X801A << 16);
    // 0x80040028: addiu       $s5, $s5, 0x2800
    ctx->r21 = ADD32(ctx->r21, 0X2800);
    // 0x8004002C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80040030: jal         0x800042A8
    // 0x80040034: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    func_800042A8(rdram, ctx);
        goto after_2;
    // 0x80040034: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    after_2:
    // 0x80040038: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8004003C: jal         0x800042A8
    // 0x80040040: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800042A8(rdram, ctx);
        goto after_3;
    // 0x80040040: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_3:
    // 0x80040044: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80040048: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8004004C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80040050: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80040054: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80040058: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8004005C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80040060: jr          $ra
    // 0x80040064: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    TRACE_RETURN()
    return;
    // 0x80040064: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80040068(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80040068: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8004006C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80040070: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80040074: sll         $s0, $a0, 16
    ctx->r16 = S32(ctx->r4 << 16);
    // 0x80040078: lui         $s4, 0x801A
    ctx->r20 = S32(0X801A << 16);
    // 0x8004007C: addiu       $s4, $s4, 0x2800
    ctx->r20 = ADD32(ctx->r20, 0X2800);
    // 0x80040080: sra         $t6, $s0, 16
    ctx->r14 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80040084: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80040088: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8004008C: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x80040090: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80040094: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80040098: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8004009C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800400A0: jal         0x80004364
    // 0x800400A4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x800400A4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x800400A8: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800400AC: sh          $s0, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r16;
    // 0x800400B0: beq         $s0, $zero, L_800400CC
    if (ctx->r16 == 0) {
        // 0x800400B4: sh          $zero, 0x4($v0)
        MEM_H(0X4, ctx->r2) = 0;
            goto L_800400CC;
    }
    // 0x800400B4: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x800400B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800400BC: beq         $s0, $at, L_800400D8
    if (ctx->r16 == ctx->r1) {
        // 0x800400C0: addiu       $t8, $zero, 0x4
        ctx->r24 = ADD32(0, 0X4);
            goto L_800400D8;
    }
    // 0x800400C0: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x800400C4: b           L_800400E0
    // 0x800400C8: lh          $a1, 0x6($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X6);
        goto L_800400E0;
    // 0x800400C8: lh          $a1, 0x6($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X6);
L_800400CC:
    // 0x800400CC: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800400D0: b           L_800400DC
    // 0x800400D4: sh          $t7, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r15;
        goto L_800400DC;
    // 0x800400D4: sh          $t7, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r15;
L_800400D8:
    // 0x800400D8: sh          $t8, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r24;
L_800400DC:
    // 0x800400DC: lh          $a1, 0x6($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X6);
L_800400E0:
    // 0x800400E0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800400E4: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x800400E8: jal         0x80004364
    // 0x800400EC: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    func_80004364(rdram, ctx);
        goto after_1;
    // 0x800400EC: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_1:
    // 0x800400F0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x800400F4: lh          $t0, 0x6($s3)
    ctx->r8 = MEM_H(ctx->r19, 0X6);
    // 0x800400F8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800400FC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80040100: blez        $t0, L_8004013C
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80040104: addiu       $s2, $zero, -0x1
        ctx->r18 = ADD32(0, -0X1);
            goto L_8004013C;
    }
    // 0x80040104: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x80040108: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_8004010C:
    // 0x8004010C: jal         0x80004364
    // 0x80040110: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    func_80004364(rdram, ctx);
        goto after_2;
    // 0x80040110: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_2:
    // 0x80040114: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80040118: sh          $s2, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r18;
    // 0x8004011C: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80040120: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80040124: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80040128: sh          $zero, 0x7A($t1)
    MEM_H(0X7A, ctx->r9) = 0;
    // 0x8004012C: lh          $t2, 0x6($s3)
    ctx->r10 = MEM_H(ctx->r19, 0X6);
    // 0x80040130: slt         $at, $s1, $t2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80040134: bnel        $at, $zero, L_8004010C
    if (ctx->r1 != 0) {
        // 0x80040138: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_8004010C;
    }
    goto skip_0;
    // 0x80040138: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_0:
L_8004013C:
    // 0x8004013C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80040140: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x80040144: sw          $t3, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r11;
    // 0x80040148: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8004014C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80040150: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80040154: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80040158: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8004015C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80040160: jr          $ra
    // 0x80040164: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    TRACE_RETURN()
    return;
    // 0x80040164: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80040168(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80040168: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004016C: lw          $v0, -0x6588($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6588);
    // 0x80040170: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80040174: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x80040178: lh          $t7, 0x6($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X6);
    // 0x8004017C: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80040180: bne         $at, $zero, L_8004018C
    if (ctx->r1 != 0) {
        // 0x80040184: nop
    
            goto L_8004018C;
    }
    // 0x80040184: nop

    // 0x80040188: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8004018C:
    // 0x8004018C: jr          $ra
    // 0x80040190: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    TRACE_RETURN()
    return;
    // 0x80040190: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80040194(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80040194: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80040198: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8004019C: lh          $t6, -0x6B94($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X6B94);
    // 0x800401A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800401A4: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800401A8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800401AC: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x800401B0: bne         $t6, $zero, L_800401C0
    if (ctx->r14 != 0) {
        // 0x800401B4: sw          $a3, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r7;
            goto L_800401C0;
    }
    // 0x800401B4: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x800401B8: b           L_80040754
    // 0x800401BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80040754;
    // 0x800401BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800401C0:
    // 0x800401C0: lh          $t7, 0x4A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X4A);
    // 0x800401C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800401C8: bnel        $t7, $at, L_80040200
    if (ctx->r15 != ctx->r1) {
        // 0x800401CC: lh          $t9, 0x4A($sp)
        ctx->r25 = MEM_H(ctx->r29, 0X4A);
            goto L_80040200;
    }
    goto skip_0;
    // 0x800401CC: lh          $t9, 0x4A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X4A);
    skip_0:
    // 0x800401D0: jal         0x8000E114
    // 0x800401D4: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    func_8000E114(rdram, ctx);
        goto after_0;
    // 0x800401D4: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_0:
    // 0x800401D8: bne         $v0, $zero, L_800401E8
    if (ctx->r2 != 0) {
        // 0x800401DC: lui         $t8, 0x8013
        ctx->r24 = S32(0X8013 << 16);
            goto L_800401E8;
    }
    // 0x800401DC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800401E0: b           L_80040754
    // 0x800401E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80040754;
    // 0x800401E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800401E8:
    // 0x800401E8: lh          $t8, -0x6B7A($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X6B7A);
    // 0x800401EC: beql        $t8, $zero, L_80040200
    if (ctx->r24 == 0) {
        // 0x800401F0: lh          $t9, 0x4A($sp)
        ctx->r25 = MEM_H(ctx->r29, 0X4A);
            goto L_80040200;
    }
    goto skip_1;
    // 0x800401F0: lh          $t9, 0x4A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X4A);
    skip_1:
    // 0x800401F4: b           L_80040754
    // 0x800401F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80040754;
    // 0x800401F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800401FC: lh          $t9, 0x4A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X4A);
L_80040200:
    // 0x80040200: lh          $v1, 0x5A($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X5A);
    // 0x80040204: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x80040208: beq         $t9, $zero, L_80040224
    if (ctx->r25 == 0) {
        // 0x8004020C: sh          $v1, 0x30($sp)
        MEM_H(0X30, ctx->r29) = ctx->r3;
            goto L_80040224;
    }
    // 0x8004020C: sh          $v1, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r3;
    // 0x80040210: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80040214: beq         $t9, $at, L_800402B8
    if (ctx->r25 == ctx->r1) {
        // 0x80040218: lui         $v0, 0x8007
        ctx->r2 = S32(0X8007 << 16);
            goto L_800402B8;
    }
    // 0x80040218: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x8004021C: b           L_800402EC
    // 0x80040220: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
        goto L_800402EC;
    // 0x80040220: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
L_80040224:
    // 0x80040224: addiu       $v0, $v0, -0x5950
    ctx->r2 = ADD32(ctx->r2, -0X5950);
    // 0x80040228: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8004022C: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x80040230: lw          $t0, -0x6588($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X6588);
    // 0x80040234: bne         $at, $zero, L_80040290
    if (ctx->r1 != 0) {
        // 0x80040238: sw          $v0, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r2;
            goto L_80040290;
    }
    // 0x80040238: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8004023C: sra         $t3, $v1, 4
    ctx->r11 = S32(SIGNED(ctx->r3) >> 4);
    // 0x80040240: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80040244: bne         $t3, $at, L_8004026C
    if (ctx->r11 != ctx->r1) {
        // 0x80040248: lui         $a0, 0x8007
        ctx->r4 = S32(0X8007 << 16);
            goto L_8004026C;
    }
    // 0x80040248: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x8004024C: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80040250: addiu       $a0, $a0, 0x7668
    ctx->r4 = ADD32(ctx->r4, 0X7668);
    // 0x80040254: jal         0x80049CFC
    // 0x80040258: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    func_80049CFC(rdram, ctx);
        goto after_1;
    // 0x80040258: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    after_1:
    // 0x8004025C: lh          $v1, 0x5A($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X5A);
    // 0x80040260: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80040264: b           L_80040284
    // 0x80040268: sh          $v0, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r2;
        goto L_80040284;
    // 0x80040268: sh          $v0, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r2;
L_8004026C:
    // 0x8004026C: addiu       $a0, $a0, 0x7670
    ctx->r4 = ADD32(ctx->r4, 0X7670);
    // 0x80040270: jal         0x80049CFC
    // 0x80040274: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    func_80049CFC(rdram, ctx);
        goto after_2;
    // 0x80040274: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    after_2:
    // 0x80040278: lh          $v1, 0x5A($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X5A);
    // 0x8004027C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80040280: sh          $v0, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r2;
L_80040284:
    // 0x80040284: andi        $t4, $v1, 0xF
    ctx->r12 = ctx->r3 & 0XF;
    // 0x80040288: b           L_800402EC
    // 0x8004028C: sh          $t4, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r12;
        goto L_800402EC;
    // 0x8004028C: sh          $t4, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r12;
L_80040290:
    // 0x80040290: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x80040294: addu        $t5, $t5, $v1
    ctx->r13 = ADD32(ctx->r13, ctx->r3);
    // 0x80040298: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8004029C: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x800402A0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x800402A4: jal         0x80049CFC
    // 0x800402A8: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    func_80049CFC(rdram, ctx);
        goto after_3;
    // 0x800402A8: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    after_3:
    // 0x800402AC: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800402B0: b           L_800402EC
    // 0x800402B4: sh          $v0, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r2;
        goto L_800402EC;
    // 0x800402B4: sh          $v0, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r2;
L_800402B8:
    // 0x800402B8: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800402BC: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x800402C0: addiu       $v0, $v0, -0x58C4
    ctx->r2 = ADD32(ctx->r2, -0X58C4);
    // 0x800402C4: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800402C8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800402CC: lw          $t0, -0x6590($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X6590);
    // 0x800402D0: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800402D4: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x800402D8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x800402DC: jal         0x80049CFC
    // 0x800402E0: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    func_80049CFC(rdram, ctx);
        goto after_4;
    // 0x800402E0: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    after_4:
    // 0x800402E4: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800402E8: sh          $v0, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r2;
L_800402EC:
    // 0x800402EC: lh          $a2, 0x6($t0)
    ctx->r6 = MEM_H(ctx->r8, 0X6);
    // 0x800402F0: lh          $t9, 0x4($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X4);
    // 0x800402F4: slt         $at, $t9, $a2
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800402F8: bne         $at, $zero, L_80040308
    if (ctx->r1 != 0) {
        // 0x800402FC: nop
    
            goto L_80040308;
    }
    // 0x800402FC: nop

    // 0x80040300: b           L_80040754
    // 0x80040304: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80040754;
    // 0x80040304: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80040308:
    // 0x80040308: blez        $a2, L_80040360
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8004030C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80040360;
    }
    // 0x8004030C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80040310: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80040314: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_80040318:
    // 0x80040318: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8004031C: lh          $t3, 0x7A($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X7A);
    // 0x80040320: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x80040324: bnel        $t4, $zero, L_80040354
    if (ctx->r12 != 0) {
        // 0x80040328: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80040354;
    }
    goto skip_2;
    // 0x80040328: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_2:
    // 0x8004032C: sh          $a1, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r5;
    // 0x80040330: lh          $a0, 0x10($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X10);
    // 0x80040334: lh          $t5, 0x3E($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X3E);
    // 0x80040338: beq         $t5, $a0, L_80040348
    if (ctx->r13 == ctx->r4) {
        // 0x8004033C: nop
    
            goto L_80040348;
    }
    // 0x8004033C: nop

    // 0x80040340: bnel        $a3, $a0, L_80040354
    if (ctx->r7 != ctx->r4) {
        // 0x80040344: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80040354;
    }
    goto skip_3;
    // 0x80040344: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_3:
L_80040348:
    // 0x80040348: b           L_80040364
    // 0x8004034C: lh          $a2, 0x3C($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X3C);
        goto L_80040364;
    // 0x8004034C: lh          $a2, 0x3C($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X3C);
    // 0x80040350: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80040354:
    // 0x80040354: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80040358: bne         $at, $zero, L_80040318
    if (ctx->r1 != 0) {
        // 0x8004035C: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80040318;
    }
    // 0x8004035C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80040360:
    // 0x80040360: lh          $a2, 0x3C($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X3C);
L_80040364:
    // 0x80040364: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x80040368: lh          $t9, 0x3E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X3E);
    // 0x8004036C: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80040370: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x80040374: lw          $v1, 0x0($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X0);
    // 0x80040378: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8004037C: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80040380: lh          $v0, 0x10($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X10);
    // 0x80040384: beql        $t9, $v0, L_80040438
    if (ctx->r25 == ctx->r2) {
        // 0x80040388: lh          $t5, 0x30($sp)
        ctx->r13 = MEM_H(ctx->r29, 0X30);
            goto L_80040438;
    }
    goto skip_4;
    // 0x80040388: lh          $t5, 0x30($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X30);
    skip_4:
    // 0x8004038C: beql        $a3, $v0, L_800403B0
    if (ctx->r7 == ctx->r2) {
        // 0x80040390: lh          $a0, 0x3E($sp)
        ctx->r4 = MEM_H(ctx->r29, 0X3E);
            goto L_800403B0;
    }
    goto skip_5;
    // 0x80040390: lh          $a0, 0x3E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X3E);
    skip_5:
    // 0x80040394: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x80040398: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x8004039C: jal         0x8004A0C4
    // 0x800403A0: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    func_8004A0C4(rdram, ctx);
        goto after_5;
    // 0x800403A0: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_5:
    // 0x800403A4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800403A8: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800403AC: lh          $a0, 0x3E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X3E);
L_800403B0:
    // 0x800403B0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800403B4: jal         0x80049D80
    // 0x800403B8: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    func_80049D80(rdram, ctx);
        goto after_6;
    // 0x800403B8: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    after_6:
    // 0x800403BC: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800403C0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800403C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800403C8: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800403CC: addu        $t4, $t3, $a2
    ctx->r12 = ADD32(ctx->r11, ctx->r6);
    // 0x800403D0: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800403D4: sw          $v0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r2;
    // 0x800403D8: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800403DC: addu        $t7, $t6, $a2
    ctx->r15 = ADD32(ctx->r14, ctx->r6);
    // 0x800403E0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800403E4: jal         0x80049DFC
    // 0x800403E8: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    func_80049DFC(rdram, ctx);
        goto after_7;
    // 0x800403E8: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_7:
    // 0x800403EC: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800403F0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800403F4: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800403F8: addu        $t3, $t9, $a2
    ctx->r11 = ADD32(ctx->r25, ctx->r6);
    // 0x800403FC: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80040400: sw          $v0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r2;
    // 0x80040404: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x80040408: addu        $t6, $t5, $a2
    ctx->r14 = ADD32(ctx->r13, ctx->r6);
    // 0x8004040C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80040410: jal         0x8004A148
    // 0x80040414: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    func_8004A148(rdram, ctx);
        goto after_8;
    // 0x80040414: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    after_8:
    // 0x80040418: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8004041C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80040420: lh          $t8, 0x3E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X3E);
    // 0x80040424: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80040428: addu        $t3, $t9, $a2
    ctx->r11 = ADD32(ctx->r25, ctx->r6);
    // 0x8004042C: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80040430: sh          $t8, 0x10($t4)
    MEM_H(0X10, ctx->r12) = ctx->r24;
    // 0x80040434: lh          $t5, 0x30($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X30);
L_80040438:
    // 0x80040438: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004043C: beq         $t5, $at, L_80040454
    if (ctx->r13 == ctx->r1) {
        // 0x80040440: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80040454;
    }
    // 0x80040440: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80040444: beq         $t5, $at, L_8004045C
    if (ctx->r13 == ctx->r1) {
        // 0x80040448: addiu       $a0, $zero, 0x2E
        ctx->r4 = ADD32(0, 0X2E);
            goto L_8004045C;
    }
    // 0x80040448: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    // 0x8004044C: b           L_8004045C
    // 0x80040450: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
        goto L_8004045C;
    // 0x80040450: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
L_80040454:
    // 0x80040454: b           L_8004045C
    // 0x80040458: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
        goto L_8004045C;
    // 0x80040458: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
L_8004045C:
    // 0x8004045C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80040460: jal         0x80044480
    // 0x80040464: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    func_80044480(rdram, ctx);
        goto after_9;
    // 0x80040464: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    after_9:
    // 0x80040468: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8004046C: lh          $t1, 0x30($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X30);
    // 0x80040470: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80040474: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80040478: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x8004047C: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x80040480: addu        $t6, $t6, $t1
    ctx->r14 = ADD32(ctx->r14, ctx->r9);
    // 0x80040484: sll         $t1, $t6, 2
    ctx->r9 = S32(ctx->r14 << 2);
    // 0x80040488: addu        $a3, $t7, $t1
    ctx->r7 = ADD32(ctx->r15, ctx->r9);
    // 0x8004048C: addu        $t8, $t3, $a2
    ctx->r24 = ADD32(ctx->r11, ctx->r6);
    // 0x80040490: lw          $t4, 0x0($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X0);
    // 0x80040494: lh          $t9, 0xC($a3)
    ctx->r25 = MEM_H(ctx->r7, 0XC);
    // 0x80040498: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x8004049C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800404A0: sh          $t9, 0x7A($t4)
    MEM_H(0X7A, ctx->r12) = ctx->r25;
    // 0x800404A4: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800404A8: lh          $t5, 0x30($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X30);
    // 0x800404AC: addu        $t7, $t6, $a2
    ctx->r15 = ADD32(ctx->r14, ctx->r6);
    // 0x800404B0: lw          $t3, 0x0($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X0);
    // 0x800404B4: sh          $t5, 0xE($t3)
    MEM_H(0XE, ctx->r11) = ctx->r13;
    // 0x800404B8: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800404BC: addu        $t9, $t8, $a2
    ctx->r25 = ADD32(ctx->r24, ctx->r6);
    // 0x800404C0: lw          $t4, 0x0($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X0);
    // 0x800404C4: sw          $t2, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r10;
    // 0x800404C8: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800404CC: lwc1        $f4, 0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X4);
    // 0x800404D0: addu        $t7, $t6, $a2
    ctx->r15 = ADD32(ctx->r14, ctx->r6);
    // 0x800404D4: lw          $t5, 0x0($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X0);
    // 0x800404D8: swc1        $f4, 0x70($t5)
    MEM_W(0X70, ctx->r13) = ctx->f4.u32l;
    // 0x800404DC: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800404E0: lh          $t3, 0xE($a3)
    ctx->r11 = MEM_H(ctx->r7, 0XE);
    // 0x800404E4: addu        $t9, $t8, $a2
    ctx->r25 = ADD32(ctx->r24, ctx->r6);
    // 0x800404E8: lw          $t4, 0x0($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X0);
    // 0x800404EC: sh          $t3, 0x8($t4)
    MEM_H(0X8, ctx->r12) = ctx->r11;
    // 0x800404F0: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800404F4: lh          $t6, 0x10($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X10);
    // 0x800404F8: addu        $t5, $t7, $a2
    ctx->r13 = ADD32(ctx->r15, ctx->r6);
    // 0x800404FC: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x80040500: sh          $t6, 0xA($t8)
    MEM_H(0XA, ctx->r24) = ctx->r14;
    // 0x80040504: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80040508: addu        $t3, $t9, $a2
    ctx->r11 = ADD32(ctx->r25, ctx->r6);
    // 0x8004050C: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80040510: sh          $zero, 0xC($t4)
    MEM_H(0XC, ctx->r12) = 0;
    // 0x80040514: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x80040518: addu        $t5, $t7, $a2
    ctx->r13 = ADD32(ctx->r15, ctx->r6);
    // 0x8004051C: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80040520: sh          $zero, 0x78($t6)
    MEM_H(0X78, ctx->r14) = 0;
    // 0x80040524: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80040528: lh          $t8, 0x12($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X12);
    // 0x8004052C: addu        $t3, $t9, $a2
    ctx->r11 = ADD32(ctx->r25, ctx->r6);
    // 0x80040530: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80040534: sh          $t8, 0x7C($t4)
    MEM_H(0X7C, ctx->r12) = ctx->r24;
    // 0x80040538: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x8004053C: addu        $t5, $t7, $a2
    ctx->r13 = ADD32(ctx->r15, ctx->r6);
    // 0x80040540: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80040544: sh          $zero, 0x7E($t6)
    MEM_H(0X7E, ctx->r14) = 0;
    // 0x80040548: lh          $t9, 0x30($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X30);
    // 0x8004054C: beql        $t9, $at, L_80040578
    if (ctx->r25 == ctx->r1) {
        // 0x80040550: lw          $t9, 0x0($t0)
        ctx->r25 = MEM_W(ctx->r8, 0X0);
            goto L_80040578;
    }
    goto skip_6;
    // 0x80040550: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    skip_6:
    // 0x80040554: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80040558: addu        $t8, $t3, $a2
    ctx->r24 = ADD32(ctx->r11, ctx->r6);
    // 0x8004055C: lw          $t4, 0x0($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X0);
    // 0x80040560: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x80040564: lw          $v0, 0x8($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X8);
    // 0x80040568: lw          $t5, 0xD8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XD8);
    // 0x8004056C: ori         $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 | 0X8000;
    // 0x80040570: sw          $t6, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r14;
    // 0x80040574: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
L_80040578:
    // 0x80040578: addu        $t3, $t9, $a2
    ctx->r11 = ADD32(ctx->r25, ctx->r6);
    // 0x8004057C: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80040580: lh          $v0, 0x7A($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X7A);
    // 0x80040584: andi        $t8, $v0, 0x2
    ctx->r24 = ctx->r2 & 0X2;
    // 0x80040588: beql        $t8, $zero, L_80040608
    if (ctx->r24 == 0) {
        // 0x8004058C: addiu       $at, $zero, 0x3C
        ctx->r1 = ADD32(0, 0X3C);
            goto L_80040608;
    }
    goto skip_7;
    // 0x8004058C: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    skip_7:
    // 0x80040590: bne         $t2, $zero, L_800405A4
    if (ctx->r10 != 0) {
        // 0x80040594: lh          $t7, 0x4A($sp)
        ctx->r15 = MEM_H(ctx->r29, 0X4A);
            goto L_800405A4;
    }
    // 0x80040594: lh          $t7, 0x4A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X4A);
    // 0x80040598: andi        $t4, $v0, 0xFFFD
    ctx->r12 = ctx->r2 & 0XFFFD;
    // 0x8004059C: b           L_80040604
    // 0x800405A0: sh          $t4, 0x7A($v1)
    MEM_H(0X7A, ctx->r3) = ctx->r12;
        goto L_80040604;
    // 0x800405A0: sh          $t4, 0x7A($v1)
    MEM_H(0X7A, ctx->r3) = ctx->r12;
L_800405A4:
    // 0x800405A4: bne         $t7, $zero, L_80040604
    if (ctx->r15 != 0) {
        // 0x800405A8: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_80040604;
    }
    // 0x800405A8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800405AC: addiu       $a0, $a0, -0x6A20
    ctx->r4 = ADD32(ctx->r4, -0X6A20);
    // 0x800405B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800405B4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800405B8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x800405BC: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x800405C0: jal         0x80044614
    // 0x800405C4: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    func_80044614(rdram, ctx);
        goto after_10;
    // 0x800405C4: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    after_10:
    // 0x800405C8: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x800405CC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800405D0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800405D4: lh          $t5, 0x98($t2)
    ctx->r13 = MEM_H(ctx->r10, 0X98);
    // 0x800405D8: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800405DC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800405E0: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x800405E4: beql        $t6, $zero, L_80040608
    if (ctx->r14 == 0) {
        // 0x800405E8: addiu       $at, $zero, 0x3C
        ctx->r1 = ADD32(0, 0X3C);
            goto L_80040608;
    }
    goto skip_8;
    // 0x800405E8: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    skip_8:
    // 0x800405EC: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800405F0: addu        $t3, $t9, $a2
    ctx->r11 = ADD32(ctx->r25, ctx->r6);
    // 0x800405F4: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x800405F8: lh          $t8, 0x7A($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X7A);
    // 0x800405FC: ori         $t4, $t8, 0x20
    ctx->r12 = ctx->r24 | 0X20;
    // 0x80040600: sh          $t4, 0x7A($v1)
    MEM_H(0X7A, ctx->r3) = ctx->r12;
L_80040604:
    // 0x80040604: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
L_80040608:
    // 0x80040608: bne         $t1, $at, L_80040640
    if (ctx->r9 != ctx->r1) {
        // 0x8004060C: lh          $t7, 0x4A($sp)
        ctx->r15 = MEM_H(ctx->r29, 0X4A);
            goto L_80040640;
    }
    // 0x8004060C: lh          $t7, 0x4A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X4A);
    // 0x80040610: bne         $t7, $zero, L_80040640
    if (ctx->r15 != 0) {
        // 0x80040614: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_80040640;
    }
    // 0x80040614: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80040618: addiu       $a0, $a0, -0x6A20
    ctx->r4 = ADD32(ctx->r4, -0X6A20);
    // 0x8004061C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80040620: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80040624: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80040628: jal         0x80044614
    // 0x8004062C: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    func_80044614(rdram, ctx);
        goto after_11;
    // 0x8004062C: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    after_11:
    // 0x80040630: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80040634: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80040638: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8004063C: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
L_80040640:
    // 0x80040640: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x80040644: lwc1        $f6, 0x8($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80040648: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004064C: addu        $t6, $t5, $a2
    ctx->r14 = ADD32(ctx->r13, ctx->r6);
    // 0x80040650: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x80040654: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80040658: swc1        $f6, 0x74($t9)
    MEM_W(0X74, ctx->r25) = ctx->f6.u32l;
    // 0x8004065C: lh          $t3, 0x4A($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X4A);
    // 0x80040660: bnel        $t3, $at, L_800406EC
    if (ctx->r11 != ctx->r1) {
        // 0x80040664: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800406EC;
    }
    goto skip_9;
    // 0x80040664: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_9:
    // 0x80040668: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x8004066C: addu        $t4, $t8, $a2
    ctx->r12 = ADD32(ctx->r24, ctx->r6);
    // 0x80040670: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x80040674: lh          $v0, 0x7A($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X7A);
    // 0x80040678: andi        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 & 0X2;
    // 0x8004067C: beq         $t7, $zero, L_800406E8
    if (ctx->r15 == 0) {
        // 0x80040680: andi        $t5, $v0, 0x40
        ctx->r13 = ctx->r2 & 0X40;
            goto L_800406E8;
    }
    // 0x80040680: andi        $t5, $v0, 0x40
    ctx->r13 = ctx->r2 & 0X40;
    // 0x80040684: bne         $t5, $zero, L_800406E8
    if (ctx->r13 != 0) {
        // 0x80040688: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_800406E8;
    }
    // 0x80040688: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8004068C: addiu       $t6, $t6, -0x6A20
    ctx->r14 = ADD32(ctx->r14, -0X6A20);
    // 0x80040690: bne         $t2, $t6, L_800406DC
    if (ctx->r10 != ctx->r14) {
        // 0x80040694: lui         $at, 0x40C0
        ctx->r1 = S32(0X40C0 << 16);
            goto L_800406DC;
    }
    // 0x80040694: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80040698: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8004069C: lh          $t9, -0x6B90($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X6B90);
    // 0x800406A0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800406A4: beql        $t9, $zero, L_800406C0
    if (ctx->r25 == 0) {
        // 0x800406A8: lwc1        $f10, 0x28($t2)
        ctx->f10.u32l = MEM_W(ctx->r10, 0X28);
            goto L_800406C0;
    }
    goto skip_10;
    // 0x800406A8: lwc1        $f10, 0x28($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X28);
    skip_10:
    // 0x800406AC: lui         $at, 0x40B0
    ctx->r1 = S32(0X40B0 << 16);
    // 0x800406B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800406B4: b           L_800406E8
    // 0x800406B8: swc1        $f8, 0x74($v1)
    MEM_W(0X74, ctx->r3) = ctx->f8.u32l;
        goto L_800406E8;
    // 0x800406B8: swc1        $f8, 0x74($v1)
    MEM_W(0X74, ctx->r3) = ctx->f8.u32l;
    // 0x800406BC: lwc1        $f10, 0x28($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X28);
L_800406C0:
    // 0x800406C0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800406C4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800406C8: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800406CC: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x800406D0: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800406D4: b           L_800406E8
    // 0x800406D8: swc1        $f6, 0x74($v1)
    MEM_W(0X74, ctx->r3) = ctx->f6.u32l;
        goto L_800406E8;
    // 0x800406D8: swc1        $f6, 0x74($v1)
    MEM_W(0X74, ctx->r3) = ctx->f6.u32l;
L_800406DC:
    // 0x800406DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800406E0: nop

    // 0x800406E4: swc1        $f8, 0x74($v1)
    MEM_W(0X74, ctx->r3) = ctx->f8.u32l;
L_800406E8:
    // 0x800406E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800406EC:
    // 0x800406EC: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
L_800406F0:
    // 0x800406F0: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800406F4: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800406F8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800406FC: addu        $t8, $t3, $a2
    ctx->r24 = ADD32(ctx->r11, ctx->r6);
    // 0x80040700: lw          $t4, 0x0($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X0);
    // 0x80040704: addu        $t7, $t4, $v0
    ctx->r15 = ADD32(ctx->r12, ctx->r2);
    // 0x80040708: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8004070C: slti        $at, $v0, 0xC
    ctx->r1 = SIGNED(ctx->r2) < 0XC ? 1 : 0;
    // 0x80040710: bne         $at, $zero, L_800406F0
    if (ctx->r1 != 0) {
        // 0x80040714: swc1        $f10, 0x58($t7)
        MEM_W(0X58, ctx->r15) = ctx->f10.u32l;
            goto L_800406F0;
    }
    // 0x80040714: swc1        $f10, 0x58($t7)
    MEM_W(0X58, ctx->r15) = ctx->f10.u32l;
    // 0x80040718: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8004071C: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
L_80040720:
    // 0x80040720: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x80040724: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80040728: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8004072C: addu        $t6, $t5, $a2
    ctx->r14 = ADD32(ctx->r13, ctx->r6);
    // 0x80040730: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x80040734: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x80040738: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8004073C: bne         $v0, $a0, L_80040720
    if (ctx->r2 != ctx->r4) {
        // 0x80040740: swc1        $f16, 0x64($t3)
        MEM_W(0X64, ctx->r11) = ctx->f16.u32l;
            goto L_80040720;
    }
    // 0x80040740: swc1        $f16, 0x64($t3)
    MEM_W(0X64, ctx->r11) = ctx->f16.u32l;
    // 0x80040744: lh          $t8, 0x4($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X4);
    // 0x80040748: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004074C: addiu       $t4, $t8, 0x1
    ctx->r12 = ADD32(ctx->r24, 0X1);
    // 0x80040750: sh          $t4, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r12;
L_80040754:
    // 0x80040754: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80040758: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8004075C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80040764(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80040764: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80040768: lw          $v0, -0x6588($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6588);
    // 0x8004076C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80040770: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x80040774: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x80040778: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x8004077C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80040780: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80040784: bnel        $t6, $zero, L_80040798
    if (ctx->r14 != 0) {
        // 0x80040788: lh          $a0, 0x6($v0)
        ctx->r4 = MEM_H(ctx->r2, 0X6);
            goto L_80040798;
    }
    goto skip_0;
    // 0x80040788: lh          $a0, 0x6($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X6);
    skip_0:
    // 0x8004078C: b           L_80040870
    // 0x80040790: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80040870;
    // 0x80040790: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80040794: lh          $a0, 0x6($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X6);
L_80040798:
    // 0x80040798: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8004079C: blezl       $a0, L_80040870
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800407A0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80040870;
    }
    goto skip_1;
    // 0x800407A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x800407A4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x800407A8: sll         $a2, $v1, 2
    ctx->r6 = S32(ctx->r3 << 2);
L_800407AC:
    // 0x800407AC: addu        $t7, $a1, $a2
    ctx->r15 = ADD32(ctx->r5, ctx->r6);
    // 0x800407B0: lw          $a3, 0x0($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X0);
    // 0x800407B4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800407B8: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x800407BC: lh          $t0, 0x7A($a3)
    ctx->r8 = MEM_H(ctx->r7, 0X7A);
    // 0x800407C0: sra         $v1, $t7, 16
    ctx->r3 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800407C4: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800407C8: andi        $t8, $t0, 0x1
    ctx->r24 = ctx->r8 & 0X1;
    // 0x800407CC: beq         $t8, $zero, L_80040864
    if (ctx->r24 == 0) {
        // 0x800407D0: nop
    
            goto L_80040864;
    }
    // 0x800407D0: nop

    // 0x800407D4: lh          $t9, 0x8($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X8);
    // 0x800407D8: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x800407DC: blez        $t9, L_80040864
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800407E0: nop
    
            goto L_80040864;
    }
    // 0x800407E0: nop

    // 0x800407E4: beq         $t1, $zero, L_80040864
    if (ctx->r9 == 0) {
        // 0x800407E8: nop
    
            goto L_80040864;
    }
    // 0x800407E8: nop

    // 0x800407EC: lh          $t2, 0x8($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X8);
    // 0x800407F0: bne         $t2, $zero, L_80040864
    if (ctx->r10 != 0) {
        // 0x800407F4: nop
    
            goto L_80040864;
    }
    // 0x800407F4: nop

    // 0x800407F8: lw          $t0, 0x14($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X14);
    // 0x800407FC: lh          $t3, 0x2E($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X2E);
    // 0x80040800: blez        $t3, L_80040864
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80040804: nop
    
            goto L_80040864;
    }
    // 0x80040804: nop

    // 0x80040808: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8004080C:
    // 0x8004080C: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80040810: sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3 << 2);
    // 0x80040814: addu        $t8, $s0, $a0
    ctx->r24 = ADD32(ctx->r16, ctx->r4);
    // 0x80040818: addu        $t5, $t4, $a2
    ctx->r13 = ADD32(ctx->r12, ctx->r6);
    // 0x8004081C: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80040820: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80040824: sll         $t5, $v1, 16
    ctx->r13 = S32(ctx->r3 << 16);
    // 0x80040828: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x8004082C: lwc1        $f4, 0x58($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X58);
    // 0x80040830: sra         $v1, $t5, 16
    ctx->r3 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80040834: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x80040838: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    // 0x8004083C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80040840: addu        $t4, $s1, $a0
    ctx->r12 = ADD32(ctx->r17, ctx->r4);
    // 0x80040844: addu        $t1, $t9, $a2
    ctx->r9 = ADD32(ctx->r25, ctx->r6);
    // 0x80040848: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8004084C: addu        $t3, $t2, $a0
    ctx->r11 = ADD32(ctx->r10, ctx->r4);
    // 0x80040850: lwc1        $f6, 0x64($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X64);
    // 0x80040854: bne         $at, $zero, L_8004080C
    if (ctx->r1 != 0) {
        // 0x80040858: swc1        $f6, 0x0($t4)
        MEM_W(0X0, ctx->r12) = ctx->f6.u32l;
            goto L_8004080C;
    }
    // 0x80040858: swc1        $f6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f6.u32l;
    // 0x8004085C: b           L_80040870
    // 0x80040860: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80040870;
    // 0x80040860: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80040864:
    // 0x80040864: bnel        $at, $zero, L_800407AC
    if (ctx->r1 != 0) {
        // 0x80040868: sll         $a2, $v1, 2
        ctx->r6 = S32(ctx->r3 << 2);
            goto L_800407AC;
    }
    goto skip_2;
    // 0x80040868: sll         $a2, $v1, 2
    ctx->r6 = S32(ctx->r3 << 2);
    skip_2:
    // 0x8004086C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80040870:
    // 0x80040870: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x80040874: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x80040878: jr          $ra
    // 0x8004087C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    TRACE_RETURN()
    return;
    // 0x8004087C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80040880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80040880: addiu       $sp, $sp, -0x170
    ctx->r29 = ADD32(ctx->r29, -0X170);
    // 0x80040884: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80040888: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x8004088C: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x80040890: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80040894: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x80040898: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8004089C: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x800408A0: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x800408A4: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x800408A8: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x800408AC: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x800408B0: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800408B4: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800408B8: lh          $t6, 0x4($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X4);
    // 0x800408BC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800408C0: beql        $t6, $zero, L_800417BC
    if (ctx->r14 == 0) {
        // 0x800408C4: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_800417BC;
    }
    goto skip_0;
    // 0x800408C4: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    skip_0:
    // 0x800408C8: sw          $zero, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = 0;
    // 0x800408CC: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x800408D0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800408D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800408D8: blez        $t7, L_800417B8
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800408DC: addiu       $fp, $zero, 0xC
        ctx->r30 = ADD32(0, 0XC);
            goto L_800417B8;
    }
    // 0x800408DC: addiu       $fp, $zero, 0xC
    ctx->r30 = ADD32(0, 0XC);
    // 0x800408E0: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x800408E4: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x800408E8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800408EC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800408F0: addiu       $s7, $sp, 0x108
    ctx->r23 = ADD32(ctx->r29, 0X108);
    // 0x800408F4: addiu       $s6, $sp, 0xBC
    ctx->r22 = ADD32(ctx->r29, 0XBC);
    // 0x800408F8: addiu       $s5, $sp, 0xA4
    ctx->r21 = ADD32(ctx->r29, 0XA4);
    // 0x800408FC: addiu       $s4, $sp, 0x148
    ctx->r20 = ADD32(ctx->r29, 0X148);
    // 0x80040900: addiu       $s3, $sp, 0xFC
    ctx->r19 = ADD32(ctx->r29, 0XFC);
    // 0x80040904: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
L_80040908:
    // 0x80040908: addu        $t9, $t8, $s2
    ctx->r25 = ADD32(ctx->r24, ctx->r18);
    // 0x8004090C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80040910: lh          $v0, 0x7A($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X7A);
    // 0x80040914: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x80040918: beql        $t1, $zero, L_8004179C
    if (ctx->r9 == 0) {
        // 0x8004091C: lw          $t9, 0x16C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X16C);
            goto L_8004179C;
    }
    goto skip_1;
    // 0x8004091C: lw          $t9, 0x16C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X16C);
    skip_1:
    // 0x80040920: lh          $t2, 0x8($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X8);
    // 0x80040924: blezl       $t2, L_80041690
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80040928: lw          $t5, 0x0($s1)
        ctx->r13 = MEM_W(ctx->r17, 0X0);
            goto L_80041690;
    }
    goto skip_2;
    // 0x80040928: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    skip_2:
    // 0x8004092C: lh          $t3, 0x8($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X8);
    // 0x80040930: andi        $t4, $v0, 0x40
    ctx->r12 = ctx->r2 & 0X40;
    // 0x80040934: bnel        $t3, $zero, L_80040950
    if (ctx->r11 != 0) {
        // 0x80040938: sh          $zero, 0x7A($sp)
        MEM_H(0X7A, ctx->r29) = 0;
            goto L_80040950;
    }
    goto skip_3;
    // 0x80040938: sh          $zero, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = 0;
    skip_3:
    // 0x8004093C: beq         $t4, $zero, L_8004094C
    if (ctx->r12 == 0) {
        // 0x80040940: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8004094C;
    }
    // 0x80040940: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80040944: b           L_80040950
    // 0x80040948: sh          $t5, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = ctx->r13;
        goto L_80040950;
    // 0x80040948: sh          $t5, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = ctx->r13;
L_8004094C:
    // 0x8004094C: sh          $zero, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = 0;
L_80040950:
    // 0x80040950: lh          $t6, 0xE($t0)
    ctx->r14 = MEM_H(ctx->r8, 0XE);
    // 0x80040954: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80040958: bne         $t6, $at, L_80040998
    if (ctx->r14 != ctx->r1) {
        // 0x8004095C: lui         $at, 0xBE80
        ctx->r1 = S32(0XBE80 << 16);
            goto L_80040998;
    }
    // 0x8004095C: lui         $at, 0xBE80
    ctx->r1 = S32(0XBE80 << 16);
    // 0x80040960: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80040964: lwc1        $f0, 0x64($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X64);
    // 0x80040968: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8004096C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80040970: nop

    // 0x80040974: bc1fl       L_8004099C
    if (!c1cs) {
        // 0x80040978: andi        $t9, $v0, 0x8
        ctx->r25 = ctx->r2 & 0X8;
            goto L_8004099C;
    }
    goto skip_4;
    // 0x80040978: andi        $t9, $v0, 0x8
    ctx->r25 = ctx->r2 & 0X8;
    skip_4:
    // 0x8004097C: lwc1        $f6, 0x76BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X76BC);
    // 0x80040980: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80040984: swc1        $f8, 0x64($t0)
    MEM_W(0X64, ctx->r8) = ctx->f8.u32l;
    // 0x80040988: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8004098C: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x80040990: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80040994: lh          $v0, 0x7A($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X7A);
L_80040998:
    // 0x80040998: andi        $t9, $v0, 0x8
    ctx->r25 = ctx->r2 & 0X8;
L_8004099C:
    // 0x8004099C: beql        $t9, $zero, L_80040A1C
    if (ctx->r25 == 0) {
        // 0x800409A0: lh          $v0, 0x7A($t0)
        ctx->r2 = MEM_H(ctx->r8, 0X7A);
            goto L_80040A1C;
    }
    goto skip_5;
    // 0x800409A0: lh          $v0, 0x7A($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X7A);
    skip_5:
    // 0x800409A4: lh          $t1, 0x8($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X8);
    // 0x800409A8: andi        $t2, $v0, 0xFFFD
    ctx->r10 = ctx->r2 & 0XFFFD;
    // 0x800409AC: slti        $at, $t1, 0x32
    ctx->r1 = SIGNED(ctx->r9) < 0X32 ? 1 : 0;
    // 0x800409B0: beql        $at, $zero, L_80040A1C
    if (ctx->r1 == 0) {
        // 0x800409B4: lh          $v0, 0x7A($t0)
        ctx->r2 = MEM_H(ctx->r8, 0X7A);
            goto L_80040A1C;
    }
    goto skip_6;
    // 0x800409B4: lh          $v0, 0x7A($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X7A);
    skip_6:
    // 0x800409B8: sh          $t2, 0x7A($t0)
    MEM_H(0X7A, ctx->r8) = ctx->r10;
    // 0x800409BC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x800409C0: lui         $at, 0xBE80
    ctx->r1 = S32(0XBE80 << 16);
    // 0x800409C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800409C8: addu        $t4, $t3, $s2
    ctx->r12 = ADD32(ctx->r11, ctx->r18);
    // 0x800409CC: lw          $t0, 0x0($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X0);
    // 0x800409D0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800409D4: lh          $t5, 0x7A($t0)
    ctx->r13 = MEM_H(ctx->r8, 0X7A);
    // 0x800409D8: ori         $t6, $t5, 0x4
    ctx->r14 = ctx->r13 | 0X4;
    // 0x800409DC: sh          $t6, 0x7A($t0)
    MEM_H(0X7A, ctx->r8) = ctx->r14;
    // 0x800409E0: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800409E4: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x800409E8: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x800409EC: lwc1        $f0, 0x64($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X64);
    // 0x800409F0: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x800409F4: nop

    // 0x800409F8: bc1fl       L_80040A1C
    if (!c1cs) {
        // 0x800409FC: lh          $v0, 0x7A($t0)
        ctx->r2 = MEM_H(ctx->r8, 0X7A);
            goto L_80040A1C;
    }
    goto skip_7;
    // 0x800409FC: lh          $v0, 0x7A($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X7A);
    skip_7:
    // 0x80040A00: lwc1        $f16, 0x76C0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X76C0);
    // 0x80040A04: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80040A08: swc1        $f18, 0x64($t0)
    MEM_W(0X64, ctx->r8) = ctx->f18.u32l;
    // 0x80040A0C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80040A10: addu        $t1, $t9, $s2
    ctx->r9 = ADD32(ctx->r25, ctx->r18);
    // 0x80040A14: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
    // 0x80040A18: lh          $v0, 0x7A($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X7A);
L_80040A1C:
    // 0x80040A1C: andi        $t2, $v0, 0x2
    ctx->r10 = ctx->r2 & 0X2;
    // 0x80040A20: beq         $t2, $zero, L_80040F98
    if (ctx->r10 == 0) {
        // 0x80040A24: andi        $t3, $v0, 0x10
        ctx->r11 = ctx->r2 & 0X10;
            goto L_80040F98;
    }
    // 0x80040A24: andi        $t3, $v0, 0x10
    ctx->r11 = ctx->r2 & 0X10;
    // 0x80040A28: beql        $t3, $zero, L_80040A68
    if (ctx->r11 == 0) {
        // 0x80040A2C: lh          $v1, 0x8($s1)
        ctx->r3 = MEM_H(ctx->r17, 0X8);
            goto L_80040A68;
    }
    goto skip_8;
    // 0x80040A2C: lh          $v1, 0x8($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X8);
    skip_8:
    // 0x80040A30: lw          $a0, 0x14($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X14);
    // 0x80040A34: lh          $v0, 0x8E($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X8E);
    // 0x80040A38: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80040A3C: blez        $v0, L_80040D8C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80040A40: sh          $v0, 0x82($sp)
        MEM_H(0X82, ctx->r29) = ctx->r2;
            goto L_80040D8C;
    }
    // 0x80040A40: sh          $v0, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r2;
    // 0x80040A44: addiu       $v0, $sp, 0x13C
    ctx->r2 = ADD32(ctx->r29, 0X13C);
L_80040A48:
    // 0x80040A48: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80040A4C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80040A50: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80040A54: bne         $v0, $s4, L_80040A48
    if (ctx->r2 != ctx->r20) {
        // 0x80040A58: swc1        $f4, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
            goto L_80040A48;
    }
    // 0x80040A58: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80040A5C: b           L_80040D90
    // 0x80040A60: lh          $t6, 0x82($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X82);
        goto L_80040D90;
    // 0x80040A60: lh          $t6, 0x82($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X82);
    // 0x80040A64: lh          $v1, 0x8($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X8);
L_80040A68:
    // 0x80040A68: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80040A6C: beql        $v1, $zero, L_80040A88
    if (ctx->r3 == 0) {
        // 0x80040A70: lw          $a1, 0x14($t0)
        ctx->r5 = MEM_W(ctx->r8, 0X14);
            goto L_80040A88;
    }
    goto skip_9;
    // 0x80040A70: lw          $a1, 0x14($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X14);
    skip_9:
    // 0x80040A74: beql        $v1, $at, L_80040D10
    if (ctx->r3 == ctx->r1) {
        // 0x80040A78: lw          $v0, 0x14($t0)
        ctx->r2 = MEM_W(ctx->r8, 0X14);
            goto L_80040D10;
    }
    goto skip_10;
    // 0x80040A78: lw          $v0, 0x14($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X14);
    skip_10:
    // 0x80040A7C: b           L_80040D90
    // 0x80040A80: lh          $t6, 0x82($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X82);
        goto L_80040D90;
    // 0x80040A80: lh          $t6, 0x82($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X82);
    // 0x80040A84: lw          $a1, 0x14($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X14);
L_80040A88:
    // 0x80040A88: andi        $t6, $v0, 0x20
    ctx->r14 = ctx->r2 & 0X20;
    // 0x80040A8C: lh          $t4, 0x2E($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X2E);
    // 0x80040A90: sh          $t4, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r12;
    // 0x80040A94: lh          $t5, 0x82($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X82);
    // 0x80040A98: blezl       $t5, L_80040D90
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80040A9C: lh          $t6, 0x82($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X82);
            goto L_80040D90;
    }
    goto skip_11;
    // 0x80040A9C: lh          $t6, 0x82($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X82);
    skip_11:
    // 0x80040AA0: beq         $t6, $zero, L_80040B84
    if (ctx->r14 == 0) {
        // 0x80040AA4: addiu       $v0, $sp, 0x13C
        ctx->r2 = ADD32(ctx->r29, 0X13C);
            goto L_80040B84;
    }
    // 0x80040AA4: addiu       $v0, $sp, 0x13C
    ctx->r2 = ADD32(ctx->r29, 0X13C);
    // 0x80040AA8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80040AAC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80040AB0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80040AB4: lw          $t7, 0x28($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X28);
    // 0x80040AB8: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x80040ABC: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80040AC0: beq         $v1, $a2, L_80040AF8
    if (ctx->r3 == ctx->r6) {
        // 0x80040AC4: lh          $t9, 0x2($t8)
        ctx->r25 = MEM_H(ctx->r24, 0X2);
            goto L_80040AF8;
    }
    // 0x80040AC4: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
L_80040AC8:
    // 0x80040AC8: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80040ACC: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80040AD0: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80040AD4: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80040AD8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80040ADC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80040AE0: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80040AE4: swc1        $f16, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
    // 0x80040AE8: lw          $t7, 0x28($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X28);
    // 0x80040AEC: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80040AF0: bne         $v1, $a2, L_80040AC8
    if (ctx->r3 != ctx->r6) {
        // 0x80040AF4: lh          $t9, 0x2($t8)
        ctx->r25 = MEM_H(ctx->r24, 0X2);
            goto L_80040AC8;
    }
    // 0x80040AF4: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
L_80040AF8:
    // 0x80040AF8: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80040AFC: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80040B00: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x80040B04: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80040B08: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80040B0C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80040B10: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80040B14: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80040B18: swc1        $f16, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
    // 0x80040B1C: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80040B20: addiu       $a1, $sp, 0x13C
    ctx->r5 = ADD32(ctx->r29, 0X13C);
    // 0x80040B24: addu        $t2, $t1, $s2
    ctx->r10 = ADD32(ctx->r9, ctx->r18);
    // 0x80040B28: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x80040B2C: jal         0x80003668
    // 0x80040B30: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_80003668(rdram, ctx);
        goto after_0;
    // 0x80040B30: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_0:
    // 0x80040B34: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80040B38: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80040B3C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80040B40: lwc1        $f4, 0x140($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X140);
    // 0x80040B44: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80040B48: nop

    // 0x80040B4C: bc1fl       L_80040B6C
    if (!c1cs) {
        // 0x80040B50: lw          $t3, 0x0($s1)
        ctx->r11 = MEM_W(ctx->r17, 0X0);
            goto L_80040B6C;
    }
    goto skip_12;
    // 0x80040B50: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    skip_12:
    // 0x80040B54: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80040B58: nop

    // 0x80040B5C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80040B60: b           L_80040D8C
    // 0x80040B64: swc1        $f8, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->f8.u32l;
        goto L_80040D8C;
    // 0x80040B64: swc1        $f8, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->f8.u32l;
    // 0x80040B68: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
L_80040B6C:
    // 0x80040B6C: addu        $t4, $t3, $s2
    ctx->r12 = ADD32(ctx->r11, ctx->r18);
    // 0x80040B70: lw          $t0, 0x0($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X0);
    // 0x80040B74: lh          $t5, 0x7A($t0)
    ctx->r13 = MEM_H(ctx->r8, 0X7A);
    // 0x80040B78: andi        $t6, $t5, 0xFFDF
    ctx->r14 = ctx->r13 & 0XFFDF;
    // 0x80040B7C: b           L_80040D8C
    // 0x80040B80: sh          $t6, 0x7A($t0)
    MEM_H(0X7A, ctx->r8) = ctx->r14;
        goto L_80040D8C;
    // 0x80040B80: sh          $t6, 0x7A($t0)
    MEM_H(0X7A, ctx->r8) = ctx->r14;
L_80040B84:
    // 0x80040B84: lw          $t7, 0x28($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X28);
    // 0x80040B88: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80040B8C: addiu       $v0, $sp, 0x13C
    ctx->r2 = ADD32(ctx->r29, 0X13C);
    // 0x80040B90: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x80040B94: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80040B98: addiu       $v1, $sp, 0x148
    ctx->r3 = ADD32(ctx->r29, 0X148);
    // 0x80040B9C: bne         $t8, $zero, L_80040C20
    if (ctx->r24 != 0) {
        // 0x80040BA0: nop
    
            goto L_80040C20;
    }
    // 0x80040BA0: nop

    // 0x80040BA4: addiu       $v0, $sp, 0x13C
    ctx->r2 = ADD32(ctx->r29, 0X13C);
    // 0x80040BA8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80040BAC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80040BB0: lw          $t9, 0x28($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X28);
    // 0x80040BB4: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x80040BB8: addu        $t1, $t9, $v1
    ctx->r9 = ADD32(ctx->r25, ctx->r3);
    // 0x80040BBC: beq         $v1, $a2, L_80040BF4
    if (ctx->r3 == ctx->r6) {
        // 0x80040BC0: lh          $t2, 0x2($t1)
        ctx->r10 = MEM_H(ctx->r9, 0X2);
            goto L_80040BF4;
    }
    // 0x80040BC0: lh          $t2, 0x2($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X2);
L_80040BC4:
    // 0x80040BC4: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80040BC8: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80040BCC: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80040BD0: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80040BD4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80040BD8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80040BDC: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80040BE0: swc1        $f16, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
    // 0x80040BE4: lw          $t9, 0x28($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X28);
    // 0x80040BE8: addu        $t1, $t9, $v1
    ctx->r9 = ADD32(ctx->r25, ctx->r3);
    // 0x80040BEC: bne         $v1, $a2, L_80040BC4
    if (ctx->r3 != ctx->r6) {
        // 0x80040BF0: lh          $t2, 0x2($t1)
        ctx->r10 = MEM_H(ctx->r9, 0X2);
            goto L_80040BC4;
    }
    // 0x80040BF0: lh          $t2, 0x2($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X2);
L_80040BF4:
    // 0x80040BF4: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80040BF8: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80040BFC: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x80040C00: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80040C04: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80040C08: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80040C0C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80040C10: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80040C14: swc1        $f16, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
    // 0x80040C18: b           L_80040C34
    // 0x80040C1C: nop

        goto L_80040C34;
    // 0x80040C1C: nop

L_80040C20:
    // 0x80040C20: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80040C24: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80040C28: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80040C2C: bne         $v0, $v1, L_80040C20
    if (ctx->r2 != ctx->r3) {
        // 0x80040C30: swc1        $f6, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
            goto L_80040C20;
    }
    // 0x80040C30: swc1        $f6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
L_80040C34:
    // 0x80040C34: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80040C38: lh          $t3, -0x662C($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X662C);
    // 0x80040C3C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80040C40: bnel        $t3, $at, L_80040D90
    if (ctx->r11 != ctx->r1) {
        // 0x80040C44: lh          $t6, 0x82($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X82);
            goto L_80040D90;
    }
    goto skip_13;
    // 0x80040C44: lh          $t6, 0x82($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X82);
    skip_13:
    // 0x80040C48: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80040C4C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80040C50: addu        $t5, $t4, $s2
    ctx->r13 = ADD32(ctx->r12, ctx->r18);
    // 0x80040C54: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80040C58: lh          $t7, 0xE($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XE);
    // 0x80040C5C: beql        $t7, $at, L_80040D90
    if (ctx->r15 == ctx->r1) {
        // 0x80040C60: lh          $t6, 0x82($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X82);
            goto L_80040D90;
    }
    goto skip_14;
    // 0x80040C60: lh          $t6, 0x82($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X82);
    skip_14:
    // 0x80040C64: jal         0x8000E35C
    // 0x80040C68: nop

    func_8000E35C(rdram, ctx);
        goto after_1;
    // 0x80040C68: nop

    after_1:
    // 0x80040C6C: andi        $t8, $v0, 0x3
    ctx->r24 = ctx->r2 & 0X3;
    // 0x80040C70: bnel        $t8, $zero, L_80040D90
    if (ctx->r24 != 0) {
        // 0x80040C74: lh          $t6, 0x82($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X82);
            goto L_80040D90;
    }
    goto skip_15;
    // 0x80040C74: lh          $t6, 0x82($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X82);
    skip_15:
    // 0x80040C78: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80040C7C: addiu       $a1, $sp, 0x13C
    ctx->r5 = ADD32(ctx->r29, 0X13C);
    // 0x80040C80: addu        $t1, $t9, $s2
    ctx->r9 = ADD32(ctx->r25, ctx->r18);
    // 0x80040C84: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80040C88: jal         0x80003668
    // 0x80040C8C: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_80003668(rdram, ctx);
        goto after_2;
    // 0x80040C8C: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_2:
    // 0x80040C90: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80040C94: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80040C98: nop

    // 0x80040C9C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80040CA0: nop

    // 0x80040CA4: bc1fl       L_80040D90
    if (!c1cs) {
        // 0x80040CA8: lh          $t6, 0x82($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X82);
            goto L_80040D90;
    }
    goto skip_16;
    // 0x80040CA8: lh          $t6, 0x82($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X82);
    skip_16:
    // 0x80040CAC: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80040CB0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80040CB4: addu        $t3, $t2, $s2
    ctx->r11 = ADD32(ctx->r10, ctx->r18);
    // 0x80040CB8: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x80040CBC: lh          $t4, 0x7A($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X7A);
    // 0x80040CC0: andi        $t5, $t4, 0xFFFD
    ctx->r13 = ctx->r12 & 0XFFFD;
    // 0x80040CC4: sh          $t5, 0x7A($t0)
    MEM_H(0X7A, ctx->r8) = ctx->r13;
L_80040CC8:
    // 0x80040CC8: jal         0x8000E35C
    // 0x80040CCC: nop

    func_8000E35C(rdram, ctx);
        goto after_3;
    // 0x80040CCC: nop

    after_3:
    // 0x80040CD0: andi        $t6, $v0, 0x7
    ctx->r14 = ctx->r2 & 0X7;
    // 0x80040CD4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80040CD8: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80040CDC: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80040CE0: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80040CE4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80040CE8: addu        $t9, $t8, $s2
    ctx->r25 = ADD32(ctx->r24, ctx->r18);
    // 0x80040CEC: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80040CF0: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x80040CF4: mul.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x80040CF8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80040CFC: bne         $s0, $at, L_80040CC8
    if (ctx->r16 != ctx->r1) {
        // 0x80040D00: swc1        $f18, 0x64($t2)
        MEM_W(0X64, ctx->r10) = ctx->f18.u32l;
            goto L_80040CC8;
    }
    // 0x80040D00: swc1        $f18, 0x64($t2)
    MEM_W(0X64, ctx->r10) = ctx->f18.u32l;
    // 0x80040D04: b           L_80040D90
    // 0x80040D08: lh          $t6, 0x82($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X82);
        goto L_80040D90;
    // 0x80040D08: lh          $t6, 0x82($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X82);
    // 0x80040D0C: lw          $v0, 0x14($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X14);
L_80040D10:
    // 0x80040D10: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80040D14: addiu       $t3, $t3, -0x6A20
    ctx->r11 = ADD32(ctx->r11, -0X6A20);
    // 0x80040D18: bne         $v0, $t3, L_80040D54
    if (ctx->r2 != ctx->r11) {
        // 0x80040D1C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80040D54;
    }
    // 0x80040D1C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80040D20: lh          $v0, 0xE8($a0)
    ctx->r2 = MEM_H(ctx->r4, 0XE8);
    // 0x80040D24: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80040D28: addiu       $a0, $sp, 0x148
    ctx->r4 = ADD32(ctx->r29, 0X148);
    // 0x80040D2C: blez        $v0, L_80040D8C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80040D30: sh          $v0, 0x82($sp)
        MEM_H(0X82, ctx->r29) = ctx->r2;
            goto L_80040D8C;
    }
    // 0x80040D30: sh          $v0, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r2;
    // 0x80040D34: addiu       $v0, $sp, 0x13C
    ctx->r2 = ADD32(ctx->r29, 0X13C);
L_80040D38:
    // 0x80040D38: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80040D3C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80040D40: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80040D44: bne         $v0, $a0, L_80040D38
    if (ctx->r2 != ctx->r4) {
        // 0x80040D48: swc1        $f4, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
            goto L_80040D38;
    }
    // 0x80040D48: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80040D4C: b           L_80040D90
    // 0x80040D50: lh          $t6, 0x82($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X82);
        goto L_80040D90;
    // 0x80040D50: lh          $t6, 0x82($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X82);
L_80040D54:
    // 0x80040D54: lh          $t4, 0x2E($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X2E);
    // 0x80040D58: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80040D5C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80040D60: sh          $t4, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r12;
    // 0x80040D64: lh          $t5, 0x82($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X82);
    // 0x80040D68: addiu       $a0, $sp, 0x148
    ctx->r4 = ADD32(ctx->r29, 0X148);
    // 0x80040D6C: addiu       $v0, $sp, 0x13C
    ctx->r2 = ADD32(ctx->r29, 0X13C);
    // 0x80040D70: blezl       $t5, L_80040D90
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80040D74: lh          $t6, 0x82($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X82);
            goto L_80040D90;
    }
    goto skip_17;
    // 0x80040D74: lh          $t6, 0x82($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X82);
    skip_17:
L_80040D78:
    // 0x80040D78: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80040D7C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80040D80: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80040D84: bne         $v0, $a0, L_80040D78
    if (ctx->r2 != ctx->r4) {
        // 0x80040D88: swc1        $f6, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
            goto L_80040D78;
    }
    // 0x80040D88: swc1        $f6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
L_80040D8C:
    // 0x80040D8C: lh          $t6, 0x82($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X82);
L_80040D90:
    // 0x80040D90: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80040D94: addiu       $v0, $sp, 0x98
    ctx->r2 = ADD32(ctx->r29, 0X98);
    // 0x80040D98: blezl       $t6, L_80040F74
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80040D9C: lw          $t7, 0x0($s1)
        ctx->r15 = MEM_W(ctx->r17, 0X0);
            goto L_80040F74;
    }
    goto skip_18;
    // 0x80040D9C: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    skip_18:
L_80040DA0:
    // 0x80040DA0: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80040DA4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80040DA8: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x80040DAC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80040DB0: addu        $t1, $t9, $s0
    ctx->r9 = ADD32(ctx->r25, ctx->r16);
    // 0x80040DB4: lwc1        $f8, 0x64($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X64);
    // 0x80040DB8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80040DBC: bne         $v0, $s5, L_80040DA0
    if (ctx->r2 != ctx->r21) {
        // 0x80040DC0: swc1        $f8, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
            goto L_80040DA0;
    }
    // 0x80040DC0: swc1        $f8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80040DC4: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80040DC8: addiu       $a0, $sp, 0x148
    ctx->r4 = ADD32(ctx->r29, 0X148);
    // 0x80040DCC: addiu       $a1, $sp, 0x98
    ctx->r5 = ADD32(ctx->r29, 0X98);
    // 0x80040DD0: addu        $t3, $t2, $s2
    ctx->r11 = ADD32(ctx->r10, ctx->r18);
    // 0x80040DD4: lw          $a2, 0x0($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X0);
    // 0x80040DD8: addiu       $a3, $sp, 0x13C
    ctx->r7 = ADD32(ctx->r29, 0X13C);
    // 0x80040DDC: jal         0x8000CD08
    // 0x80040DE0: addiu       $a2, $a2, 0x58
    ctx->r6 = ADD32(ctx->r6, 0X58);
    func_8000CD08(rdram, ctx);
        goto after_4;
    // 0x80040DE0: addiu       $a2, $a2, 0x58
    ctx->r6 = ADD32(ctx->r6, 0X58);
    after_4:
    // 0x80040DE4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80040DE8: lwc1        $f0, 0x14C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x80040DEC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80040DF0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80040DF4: addiu       $a1, $sp, 0x13C
    ctx->r5 = ADD32(ctx->r29, 0X13C);
    // 0x80040DF8: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80040DFC: nop

    // 0x80040E00: bc1fl       L_80040E1C
    if (!c1cs) {
        // 0x80040E04: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_80040E1C;
    }
    goto skip_19;
    // 0x80040E04: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    skip_19:
    // 0x80040E08: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80040E0C: nop

    // 0x80040E10: sub.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80040E14: swc1        $f0, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->f0.u32l;
    // 0x80040E18: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
L_80040E1C:
    // 0x80040E1C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80040E20: lwc1        $f18, 0x14C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x80040E24: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80040E28: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80040E2C: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80040E30: addu        $t5, $t4, $s2
    ctx->r13 = ADD32(ctx->r12, ctx->r18);
    // 0x80040E34: lw          $t0, 0x0($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X0);
    // 0x80040E38: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80040E3C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80040E40: lwc1        $f8, 0x68($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X68);
    // 0x80040E44: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80040E48: swc1        $f10, 0x68($t0)
    MEM_W(0X68, ctx->r8) = ctx->f10.u32l;
    // 0x80040E4C: lwc1        $f18, 0x148($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X148);
    // 0x80040E50: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80040E54: nop

    // 0x80040E58: bc1fl       L_80040E74
    if (!c1cs) {
        // 0x80040E5C: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_80040E74;
    }
    goto skip_20;
    // 0x80040E5C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    skip_20:
    // 0x80040E60: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80040E64: nop

    // 0x80040E68: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80040E6C: swc1        $f8, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->f8.u32l;
    // 0x80040E70: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
L_80040E74:
    // 0x80040E74: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80040E78: lwc1        $f6, 0x148($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X148);
    // 0x80040E7C: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80040E80: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80040E84: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80040E88: addu        $t7, $t6, $s2
    ctx->r15 = ADD32(ctx->r14, ctx->r18);
    // 0x80040E8C: lw          $t0, 0x0($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X0);
    // 0x80040E90: lwc1        $f18, 0x64($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X64);
    // 0x80040E94: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80040E98: swc1        $f4, 0x64($t0)
    MEM_W(0X64, ctx->r8) = ctx->f4.u32l;
    // 0x80040E9C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80040EA0: addu        $t9, $t8, $s2
    ctx->r25 = ADD32(ctx->r24, ctx->r18);
    // 0x80040EA4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80040EA8: lh          $t1, 0xE($t0)
    ctx->r9 = MEM_H(ctx->r8, 0XE);
    // 0x80040EAC: bnel        $t1, $at, L_80040EF4
    if (ctx->r9 != ctx->r1) {
        // 0x80040EB0: lh          $t6, 0x8($s1)
        ctx->r14 = MEM_H(ctx->r17, 0X8);
            goto L_80040EF4;
    }
    goto skip_21;
    // 0x80040EB0: lh          $t6, 0x8($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X8);
    skip_21:
    // 0x80040EB4: jal         0x80003668
    // 0x80040EB8: addiu       $a0, $t0, 0x58
    ctx->r4 = ADD32(ctx->r8, 0X58);
    func_80003668(rdram, ctx);
        goto after_5;
    // 0x80040EB8: addiu       $a0, $t0, 0x58
    ctx->r4 = ADD32(ctx->r8, 0X58);
    after_5:
    // 0x80040EBC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80040EC0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80040EC4: nop

    // 0x80040EC8: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80040ECC: nop

    // 0x80040ED0: bc1fl       L_80040EF4
    if (!c1cs) {
        // 0x80040ED4: lh          $t6, 0x8($s1)
        ctx->r14 = MEM_H(ctx->r17, 0X8);
            goto L_80040EF4;
    }
    goto skip_22;
    // 0x80040ED4: lh          $t6, 0x8($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X8);
    skip_22:
    // 0x80040ED8: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80040EDC: addu        $t3, $t2, $s2
    ctx->r11 = ADD32(ctx->r10, ctx->r18);
    // 0x80040EE0: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x80040EE4: lh          $t4, 0x7A($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X7A);
    // 0x80040EE8: andi        $t5, $t4, 0xFFFD
    ctx->r13 = ctx->r12 & 0XFFFD;
    // 0x80040EEC: sh          $t5, 0x7A($t0)
    MEM_H(0X7A, ctx->r8) = ctx->r13;
    // 0x80040EF0: lh          $t6, 0x8($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X8);
L_80040EF4:
    // 0x80040EF4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80040EF8: bnel        $t6, $at, L_80040F60
    if (ctx->r14 != ctx->r1) {
        // 0x80040EFC: lw          $t5, 0x0($s1)
        ctx->r13 = MEM_W(ctx->r17, 0X0);
            goto L_80040F60;
    }
    goto skip_23;
    // 0x80040EFC: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    skip_23:
    // 0x80040F00: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80040F04: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80040F08: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x80040F0C: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80040F10: lh          $t9, 0xE($t0)
    ctx->r25 = MEM_H(ctx->r8, 0XE);
    // 0x80040F14: addiu       $a0, $t0, 0x58
    ctx->r4 = ADD32(ctx->r8, 0X58);
    // 0x80040F18: bnel        $t9, $at, L_80040F60
    if (ctx->r25 != ctx->r1) {
        // 0x80040F1C: lw          $t5, 0x0($s1)
        ctx->r13 = MEM_W(ctx->r17, 0X0);
            goto L_80040F60;
    }
    goto skip_24;
    // 0x80040F1C: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    skip_24:
    // 0x80040F20: jal         0x80003668
    // 0x80040F24: addiu       $a1, $sp, 0x13C
    ctx->r5 = ADD32(ctx->r29, 0X13C);
    func_80003668(rdram, ctx);
        goto after_6;
    // 0x80040F24: addiu       $a1, $sp, 0x13C
    ctx->r5 = ADD32(ctx->r29, 0X13C);
    after_6:
    // 0x80040F28: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80040F2C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80040F30: nop

    // 0x80040F34: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80040F38: nop

    // 0x80040F3C: bc1fl       L_80040F60
    if (!c1cs) {
        // 0x80040F40: lw          $t5, 0x0($s1)
        ctx->r13 = MEM_W(ctx->r17, 0X0);
            goto L_80040F60;
    }
    goto skip_25;
    // 0x80040F40: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    skip_25:
    // 0x80040F44: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80040F48: addu        $t2, $t1, $s2
    ctx->r10 = ADD32(ctx->r9, ctx->r18);
    // 0x80040F4C: lw          $t0, 0x0($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X0);
    // 0x80040F50: lh          $t3, 0x7A($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X7A);
    // 0x80040F54: andi        $t4, $t3, 0xFFFD
    ctx->r12 = ctx->r11 & 0XFFFD;
    // 0x80040F58: sh          $t4, 0x7A($t0)
    MEM_H(0X7A, ctx->r8) = ctx->r12;
    // 0x80040F5C: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
L_80040F60:
    // 0x80040F60: addu        $t6, $t5, $s2
    ctx->r14 = ADD32(ctx->r13, ctx->r18);
    // 0x80040F64: lw          $t0, 0x0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X0);
    // 0x80040F68: b           L_80040F98
    // 0x80040F6C: lh          $v0, 0x7A($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X7A);
        goto L_80040F98;
    // 0x80040F6C: lh          $v0, 0x7A($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X7A);
    // 0x80040F70: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
L_80040F74:
    // 0x80040F74: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x80040F78: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80040F7C: lh          $t9, 0x7A($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X7A);
    // 0x80040F80: andi        $t1, $t9, 0xFFFD
    ctx->r9 = ctx->r25 & 0XFFFD;
    // 0x80040F84: sh          $t1, 0x7A($t0)
    MEM_H(0X7A, ctx->r8) = ctx->r9;
    // 0x80040F88: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80040F8C: addu        $t3, $t2, $s2
    ctx->r11 = ADD32(ctx->r10, ctx->r18);
    // 0x80040F90: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x80040F94: lh          $v0, 0x7A($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X7A);
L_80040F98:
    // 0x80040F98: andi        $t4, $v0, 0x40
    ctx->r12 = ctx->r2 & 0X40;
    // 0x80040F9C: beq         $t4, $zero, L_80041034
    if (ctx->r12 == 0) {
        // 0x80040FA0: lwc1        $f0, 0x64($t0)
        ctx->f0.u32l = MEM_W(ctx->r8, 0X64);
            goto L_80041034;
    }
    // 0x80040FA0: lwc1        $f0, 0x64($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X64);
    // 0x80040FA4: andi        $t5, $v0, 0x80
    ctx->r13 = ctx->r2 & 0X80;
    // 0x80040FA8: beq         $t5, $zero, L_80041034
    if (ctx->r13 == 0) {
        // 0x80040FAC: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80041034;
    }
    // 0x80040FAC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80040FB0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80040FB4: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80040FB8: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80040FBC: jal         0x80049840
    // 0x80040FC0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    func_80049840(rdram, ctx);
        goto after_7;
    // 0x80040FC0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_7:
    // 0x80040FC4: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80040FC8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80040FCC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80040FD0: addu        $t7, $t6, $s2
    ctx->r15 = ADD32(ctx->r14, ctx->r18);
    // 0x80040FD4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80040FD8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80040FDC: lw          $a1, 0x6C($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X6C);
    // 0x80040FE0: jal         0x80049840
    // 0x80040FE4: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    func_80049840(rdram, ctx);
        goto after_8;
    // 0x80040FE4: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_8:
    // 0x80040FE8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80040FEC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80040FF0: jal         0x80000BD8
    // 0x80040FF4: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_80000BD8(rdram, ctx);
        goto after_9;
    // 0x80040FF4: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_9:
    // 0x80040FF8: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80040FFC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80041000: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80041004: addu        $t1, $t9, $s2
    ctx->r9 = ADD32(ctx->r25, ctx->r18);
    // 0x80041008: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8004100C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80041010: lw          $a1, 0x68($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X68);
    // 0x80041014: jal         0x80049840
    // 0x80041018: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    func_80049840(rdram, ctx);
        goto after_10;
    // 0x80041018: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_10:
    // 0x8004101C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80041020: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80041024: jal         0x80000BD8
    // 0x80041028: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_80000BD8(rdram, ctx);
        goto after_11;
    // 0x80041028: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_11:
    // 0x8004102C: b           L_80041084
    // 0x80041030: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_80041084;
    // 0x80041030: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80041034:
    // 0x80041034: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80041038: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x8004103C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80041040: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80041044: jal         0x80049840
    // 0x80041048: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    func_80049840(rdram, ctx);
        goto after_12;
    // 0x80041048: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_12:
    // 0x8004104C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80041050: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80041054: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80041058: addu        $t4, $t3, $s2
    ctx->r12 = ADD32(ctx->r11, ctx->r18);
    // 0x8004105C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80041060: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80041064: lw          $a1, 0x68($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X68);
    // 0x80041068: jal         0x80049840
    // 0x8004106C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    func_80049840(rdram, ctx);
        goto after_13;
    // 0x8004106C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_13:
    // 0x80041070: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80041074: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80041078: jal         0x80000BD8
    // 0x8004107C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_80000BD8(rdram, ctx);
        goto after_14;
    // 0x8004107C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_14:
    // 0x80041080: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80041084:
    // 0x80041084: addiu       $v1, $sp, 0xFC
    ctx->r3 = ADD32(ctx->r29, 0XFC);
    // 0x80041088: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8004108C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80041090: sltu        $at, $v1, $s7
    ctx->r1 = ctx->r3 < ctx->r23 ? 1 : 0;
    // 0x80041094: addu        $t7, $t6, $s2
    ctx->r15 = ADD32(ctx->r14, ctx->r18);
    // 0x80041098: lw          $t0, 0x0($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X0);
    // 0x8004109C: beq         $at, $zero, L_800410E0
    if (ctx->r1 == 0) {
        // 0x800410A0: lwc1        $f18, 0x1C($v1)
        ctx->f18.u32l = MEM_W(ctx->r3, 0X1C);
            goto L_800410E0;
    }
    // 0x800410A0: lwc1        $f18, 0x1C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X1C);
L_800410A4:
    // 0x800410A4: lwc1        $f16, 0x74($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X74);
    // 0x800410A8: neg.s       $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = -ctx->f18.fl;
    // 0x800410AC: addu        $v0, $t0, $s0
    ctx->r2 = ADD32(ctx->r8, ctx->r16);
    // 0x800410B0: mul.s       $f16, $f14, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x800410B4: lwc1        $f14, 0x58($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X58);
    // 0x800410B8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800410BC: sltu        $at, $v1, $s7
    ctx->r1 = ctx->r3 < ctx->r23 ? 1 : 0;
    // 0x800410C0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800410C4: add.s       $f16, $f14, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x800410C8: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x800410CC: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800410D0: lwc1        $f18, 0x1C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x800410D4: addu        $t7, $t6, $s2
    ctx->r15 = ADD32(ctx->r14, ctx->r18);
    // 0x800410D8: bne         $at, $zero, L_800410A4
    if (ctx->r1 != 0) {
        // 0x800410DC: lw          $t0, 0x0($t7)
        ctx->r8 = MEM_W(ctx->r15, 0X0);
            goto L_800410A4;
    }
    // 0x800410DC: lw          $t0, 0x0($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X0);
L_800410E0:
    // 0x800410E0: lwc1        $f16, 0x74($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X74);
    // 0x800410E4: neg.s       $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = -ctx->f18.fl;
    // 0x800410E8: addu        $v0, $t0, $s0
    ctx->r2 = ADD32(ctx->r8, ctx->r16);
    // 0x800410EC: mul.s       $f16, $f14, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x800410F0: lwc1        $f14, 0x58($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X58);
    // 0x800410F4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800410F8: add.s       $f16, $f14, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x800410FC: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x80041100: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80041104: addu        $t9, $t8, $s2
    ctx->r25 = ADD32(ctx->r24, ctx->r18);
    // 0x80041108: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x8004110C: jal         0x8000E074
    // 0x80041110: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_8000E074(rdram, ctx);
        goto after_15;
    // 0x80041110: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_15:
    // 0x80041114: beql        $v0, $zero, L_8004130C
    if (ctx->r2 == 0) {
        // 0x80041118: lw          $t3, 0x0($s1)
        ctx->r11 = MEM_W(ctx->r17, 0X0);
            goto L_8004130C;
    }
    goto skip_26;
    // 0x80041118: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    skip_26:
    // 0x8004111C: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80041120: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80041124: addu        $t2, $t1, $s2
    ctx->r10 = ADD32(ctx->r9, ctx->r18);
    // 0x80041128: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8004112C: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x80041130: lw          $v0, 0x8($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X8);
    // 0x80041134: lw          $t5, 0xD8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XD8);
    // 0x80041138: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x8004113C: sw          $t6, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r14;
L_80041140:
    // 0x80041140: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80041144: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x80041148: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8004114C: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x80041150: addu        $t9, $t0, $s0
    ctx->r25 = ADD32(ctx->r8, ctx->r16);
    // 0x80041154: lwc1        $f10, 0x58($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X58);
    // 0x80041158: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x8004115C: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x80041160: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80041164: slti        $at, $s0, 0xC
    ctx->r1 = SIGNED(ctx->r16) < 0XC ? 1 : 0;
    // 0x80041168: bne         $at, $zero, L_80041140
    if (ctx->r1 != 0) {
        // 0x8004116C: swc1        $f10, 0x40($t3)
        MEM_W(0X40, ctx->r11) = ctx->f10.u32l;
            goto L_80041140;
    }
    // 0x8004116C: swc1        $f10, 0x40($t3)
    MEM_W(0X40, ctx->r11) = ctx->f10.u32l;
    // 0x80041170: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80041174: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80041178: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8004117C: addu        $t5, $t4, $s2
    ctx->r13 = ADD32(ctx->r12, ctx->r18);
    // 0x80041180: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80041184: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80041188: lw          $a1, 0x64($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X64);
    // 0x8004118C: jal         0x80049840
    // 0x80041190: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    func_80049840(rdram, ctx);
        goto after_16;
    // 0x80041190: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_16:
    // 0x80041194: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80041198: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8004119C: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x800411A0: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x800411A4: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800411A8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800411AC: lw          $a1, 0x68($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X68);
    // 0x800411B0: jal         0x80049840
    // 0x800411B4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    func_80049840(rdram, ctx);
        goto after_17;
    // 0x800411B4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_17:
    // 0x800411B8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800411BC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800411C0: jal         0x80000BD8
    // 0x800411C4: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_80000BD8(rdram, ctx);
        goto after_18;
    // 0x800411C4: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_18:
    // 0x800411C8: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x800411CC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800411D0: addu        $t2, $t1, $s2
    ctx->r10 = ADD32(ctx->r9, ctx->r18);
    // 0x800411D4: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800411D8: lwc1        $f0, 0x70($t3)
    ctx->f0.u32l = MEM_W(ctx->r11, 0X70);
    // 0x800411DC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800411E0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800411E4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800411E8: jal         0x80001AB4
    // 0x800411EC: nop

    func_80001AB4(rdram, ctx);
        goto after_19;
    // 0x800411EC: nop

    after_19:
    // 0x800411F0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800411F4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800411F8: jal         0x80000BD8
    // 0x800411FC: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_80000BD8(rdram, ctx);
        goto after_20;
    // 0x800411FC: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_20:
    // 0x80041200: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80041204: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80041208: addu        $t5, $t4, $s2
    ctx->r13 = ADD32(ctx->r12, ctx->r18);
    // 0x8004120C: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80041210: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80041214: lw          $a0, 0x8($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X8);
    // 0x80041218: jal         0x80002340
    // 0x8004121C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80002340(rdram, ctx);
        goto after_21;
    // 0x8004121C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_21:
    // 0x80041220: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80041224:
    // 0x80041224: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80041228: addu        $t9, $t8, $s2
    ctx->r25 = ADD32(ctx->r24, ctx->r18);
    // 0x8004122C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80041230: lw          $t2, 0x4($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X4);
    // 0x80041234: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x80041238: lwc1        $f18, 0x58($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X58);
    // 0x8004123C: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x80041240: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x80041244: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80041248: bne         $s0, $fp, L_80041224
    if (ctx->r16 != ctx->r30) {
        // 0x8004124C: swc1        $f18, 0x40($t4)
        MEM_W(0X40, ctx->r12) = ctx->f18.u32l;
            goto L_80041224;
    }
    // 0x8004124C: swc1        $f18, 0x40($t4)
    MEM_W(0X40, ctx->r12) = ctx->f18.u32l;
    // 0x80041250: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80041254: addu        $t6, $t5, $s2
    ctx->r14 = ADD32(ctx->r13, ctx->r18);
    // 0x80041258: lw          $t0, 0x0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X0);
    // 0x8004125C: lh          $v1, 0xA($t0)
    ctx->r3 = MEM_H(ctx->r8, 0XA);
    // 0x80041260: beql        $v1, $zero, L_8004133C
    if (ctx->r3 == 0) {
        // 0x80041264: lh          $t2, 0x8($s1)
        ctx->r10 = MEM_H(ctx->r17, 0X8);
            goto L_8004133C;
    }
    goto skip_27;
    // 0x80041264: lh          $t2, 0x8($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X8);
    skip_27:
    // 0x80041268: lh          $v0, 0xC($t0)
    ctx->r2 = MEM_H(ctx->r8, 0XC);
    // 0x8004126C: beq         $v0, $zero, L_80041288
    if (ctx->r2 == 0) {
        // 0x80041270: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_80041288;
    }
    // 0x80041270: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80041274: sh          $t7, 0xC($t0)
    MEM_H(0XC, ctx->r8) = ctx->r15;
    // 0x80041278: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8004127C: addu        $t9, $t8, $s2
    ctx->r25 = ADD32(ctx->r24, ctx->r18);
    // 0x80041280: b           L_80041338
    // 0x80041284: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
        goto L_80041338;
    // 0x80041284: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
L_80041288:
    // 0x80041288: sh          $v1, 0xC($t0)
    MEM_H(0XC, ctx->r8) = ctx->r3;
    // 0x8004128C: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80041290: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80041294: addu        $t2, $t1, $s2
    ctx->r10 = ADD32(ctx->r9, ctx->r18);
    // 0x80041298: lw          $t0, 0x0($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X0);
    // 0x8004129C: lh          $v0, 0x7A($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X7A);
    // 0x800412A0: andi        $t3, $v0, 0x4
    ctx->r11 = ctx->r2 & 0X4;
    // 0x800412A4: beql        $t3, $zero, L_800412CC
    if (ctx->r11 == 0) {
        // 0x800412A8: andi        $t8, $v0, 0x40
        ctx->r24 = ctx->r2 & 0X40;
            goto L_800412CC;
    }
    goto skip_28;
    // 0x800412A8: andi        $t8, $v0, 0x40
    ctx->r24 = ctx->r2 & 0X40;
    skip_28:
    // 0x800412AC: lh          $t4, 0xC($t0)
    ctx->r12 = MEM_H(ctx->r8, 0XC);
    // 0x800412B0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800412B4: sh          $t5, 0xC($t0)
    MEM_H(0XC, ctx->r8) = ctx->r13;
    // 0x800412B8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800412BC: addu        $t7, $t6, $s2
    ctx->r15 = ADD32(ctx->r14, ctx->r18);
    // 0x800412C0: lw          $t0, 0x0($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X0);
    // 0x800412C4: lh          $v0, 0x7A($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X7A);
    // 0x800412C8: andi        $t8, $v0, 0x40
    ctx->r24 = ctx->r2 & 0X40;
L_800412CC:
    // 0x800412CC: beq         $t8, $zero, L_800412F0
    if (ctx->r24 == 0) {
        // 0x800412D0: addiu       $a0, $t0, 0x58
        ctx->r4 = ADD32(ctx->r8, 0X58);
            goto L_800412F0;
    }
    // 0x800412D0: addiu       $a0, $t0, 0x58
    ctx->r4 = ADD32(ctx->r8, 0X58);
    // 0x800412D4: lh          $t9, 0x8($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X8);
    // 0x800412D8: bne         $t9, $zero, L_800412E8
    if (ctx->r25 != 0) {
        // 0x800412DC: nop
    
            goto L_800412E8;
    }
    // 0x800412DC: nop

    // 0x800412E0: b           L_800412F0
    // 0x800412E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_800412F0;
    // 0x800412E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800412E8:
    // 0x800412E8: b           L_800412F0
    // 0x800412EC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
        goto L_800412F0;
    // 0x800412EC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
L_800412F0:
    // 0x800412F0: jal         0x80042A14
    // 0x800412F4: addiu       $a1, $t0, 0x64
    ctx->r5 = ADD32(ctx->r8, 0X64);
    func_80042A14(rdram, ctx);
        goto after_22;
    // 0x800412F4: addiu       $a1, $t0, 0x64
    ctx->r5 = ADD32(ctx->r8, 0X64);
    after_22:
    // 0x800412F8: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x800412FC: addu        $t2, $t1, $s2
    ctx->r10 = ADD32(ctx->r9, ctx->r18);
    // 0x80041300: b           L_80041338
    // 0x80041304: lw          $t0, 0x0($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X0);
        goto L_80041338;
    // 0x80041304: lw          $t0, 0x0($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X0);
    // 0x80041308: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
L_8004130C:
    // 0x8004130C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80041310: addu        $t4, $t3, $s2
    ctx->r12 = ADD32(ctx->r11, ctx->r18);
    // 0x80041314: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80041318: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x8004131C: lw          $v0, 0x8($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X8);
    // 0x80041320: lw          $t7, 0xD8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XD8);
    // 0x80041324: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80041328: sw          $t8, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r24;
    // 0x8004132C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80041330: addu        $t1, $t9, $s2
    ctx->r9 = ADD32(ctx->r25, ctx->r18);
    // 0x80041334: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
L_80041338:
    // 0x80041338: lh          $t2, 0x8($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X8);
L_8004133C:
    // 0x8004133C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80041340: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80041344: bne         $t2, $zero, L_800413AC
    if (ctx->r10 != 0) {
        // 0x80041348: addiu       $a0, $t0, 0x58
        ctx->r4 = ADD32(ctx->r8, 0X58);
            goto L_800413AC;
    }
    // 0x80041348: addiu       $a0, $t0, 0x58
    ctx->r4 = ADD32(ctx->r8, 0X58);
    // 0x8004134C: addiu       $a0, $t0, 0x58
    ctx->r4 = ADD32(ctx->r8, 0X58);
    // 0x80041350: jal         0x8001F2CC
    // 0x80041354: lh          $a1, 0x7C($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X7C);
    func_8001F2CC(rdram, ctx);
        goto after_23;
    // 0x80041354: lh          $a1, 0x7C($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X7C);
    after_23:
    // 0x80041358: beql        $v0, $zero, L_800413FC
    if (ctx->r2 == 0) {
        // 0x8004135C: lw          $t8, 0x0($s1)
        ctx->r24 = MEM_W(ctx->r17, 0X0);
            goto L_800413FC;
    }
    goto skip_29;
    // 0x8004135C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    skip_29:
    // 0x80041360: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80041364: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80041368: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004136C: addu        $t4, $t3, $s2
    ctx->r12 = ADD32(ctx->r11, ctx->r18);
    // 0x80041370: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80041374: jal         0x80042F80
    // 0x80041378: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_80042F80(rdram, ctx);
        goto after_24;
    // 0x80041378: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_24:
    // 0x8004137C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80041380: addiu       $a0, $a0, -0x6A20
    ctx->r4 = ADD32(ctx->r4, -0X6A20);
    // 0x80041384: jal         0x80044614
    // 0x80041388: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80044614(rdram, ctx);
        goto after_25;
    // 0x80041388: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_25:
    // 0x8004138C: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80041390: addu        $t6, $t5, $s2
    ctx->r14 = ADD32(ctx->r13, ctx->r18);
    // 0x80041394: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80041398: sh          $zero, 0x8($t7)
    MEM_H(0X8, ctx->r15) = 0;
    // 0x8004139C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800413A0: addu        $t9, $t8, $s2
    ctx->r25 = ADD32(ctx->r24, ctx->r18);
    // 0x800413A4: b           L_80041704
    // 0x800413A8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
        goto L_80041704;
    // 0x800413A8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
L_800413AC:
    // 0x800413AC: jal         0x8004267C
    // 0x800413B0: lh          $a1, 0x7C($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X7C);
    func_8004267C(rdram, ctx);
        goto after_26;
    // 0x800413B0: lh          $a1, 0x7C($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X7C);
    after_26:
    // 0x800413B4: beql        $v0, $zero, L_800413FC
    if (ctx->r2 == 0) {
        // 0x800413B8: lw          $t8, 0x0($s1)
        ctx->r24 = MEM_W(ctx->r17, 0X0);
            goto L_800413FC;
    }
    goto skip_30;
    // 0x800413B8: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    skip_30:
    // 0x800413BC: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x800413C0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800413C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800413C8: addu        $t2, $t1, $s2
    ctx->r10 = ADD32(ctx->r9, ctx->r18);
    // 0x800413CC: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x800413D0: jal         0x80042F80
    // 0x800413D4: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_80042F80(rdram, ctx);
        goto after_27;
    // 0x800413D4: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_27:
    // 0x800413D8: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x800413DC: addu        $t4, $t3, $s2
    ctx->r12 = ADD32(ctx->r11, ctx->r18);
    // 0x800413E0: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800413E4: sh          $zero, 0x8($t5)
    MEM_H(0X8, ctx->r13) = 0;
    // 0x800413E8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800413EC: addu        $t7, $t6, $s2
    ctx->r15 = ADD32(ctx->r14, ctx->r18);
    // 0x800413F0: b           L_80041704
    // 0x800413F4: lw          $t0, 0x0($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X0);
        goto L_80041704;
    // 0x800413F4: lw          $t0, 0x0($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X0);
    // 0x800413F8: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
L_800413FC:
    // 0x800413FC: addu        $t9, $t8, $s2
    ctx->r25 = ADD32(ctx->r24, ctx->r18);
    // 0x80041400: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80041404: addiu       $a0, $t0, 0x58
    ctx->r4 = ADD32(ctx->r8, 0X58);
    // 0x80041408: jal         0x8001F9B0
    // 0x8004140C: lh          $a1, 0x7C($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X7C);
    func_8001F9B0(rdram, ctx);
        goto after_28;
    // 0x8004140C: lh          $a1, 0x7C($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X7C);
    after_28:
    // 0x80041410: beql        $v0, $zero, L_80041480
    if (ctx->r2 == 0) {
        // 0x80041414: lw          $t2, 0x0($s1)
        ctx->r10 = MEM_W(ctx->r17, 0X0);
            goto L_80041480;
    }
    goto skip_31;
    // 0x80041414: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    skip_31:
    // 0x80041418: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x8004141C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80041420: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80041424: addu        $t2, $t1, $s2
    ctx->r10 = ADD32(ctx->r9, ctx->r18);
    // 0x80041428: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x8004142C: jal         0x80042F80
    // 0x80041430: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_80042F80(rdram, ctx);
        goto after_29;
    // 0x80041430: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_29:
    // 0x80041434: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80041438: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8004143C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80041440: addu        $t4, $t3, $s2
    ctx->r12 = ADD32(ctx->r11, ctx->r18);
    // 0x80041444: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80041448: jal         0x80043714
    // 0x8004144C: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_80043714(rdram, ctx);
        goto after_30;
    // 0x8004144C: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_30:
    // 0x80041450: lh          $t5, 0x7A($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X7A);
    // 0x80041454: bnel        $t5, $zero, L_80041480
    if (ctx->r13 != 0) {
        // 0x80041458: lw          $t2, 0x0($s1)
        ctx->r10 = MEM_W(ctx->r17, 0X0);
            goto L_80041480;
    }
    goto skip_32;
    // 0x80041458: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    skip_32:
    // 0x8004145C: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80041460: addu        $t7, $t6, $s2
    ctx->r15 = ADD32(ctx->r14, ctx->r18);
    // 0x80041464: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80041468: sh          $zero, 0x8($t8)
    MEM_H(0X8, ctx->r24) = 0;
    // 0x8004146C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80041470: addu        $t1, $t9, $s2
    ctx->r9 = ADD32(ctx->r25, ctx->r18);
    // 0x80041474: b           L_80041704
    // 0x80041478: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
        goto L_80041704;
    // 0x80041478: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
    // 0x8004147C: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
L_80041480:
    // 0x80041480: addu        $t3, $t2, $s2
    ctx->r11 = ADD32(ctx->r10, ctx->r18);
    // 0x80041484: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x80041488: addiu       $a0, $t0, 0x58
    ctx->r4 = ADD32(ctx->r8, 0X58);
    // 0x8004148C: jal         0x800423C0
    // 0x80041490: lh          $a1, 0x7C($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X7C);
    func_800423C0(rdram, ctx);
        goto after_31;
    // 0x80041490: lh          $a1, 0x7C($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X7C);
    after_31:
    // 0x80041494: beql        $v0, $zero, L_800414F8
    if (ctx->r2 == 0) {
        // 0x80041498: lw          $t4, 0x0($s1)
        ctx->r12 = MEM_W(ctx->r17, 0X0);
            goto L_800414F8;
    }
    goto skip_33;
    // 0x80041498: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    skip_33:
    // 0x8004149C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x800414A0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800414A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800414A8: addu        $t5, $t4, $s2
    ctx->r13 = ADD32(ctx->r12, ctx->r18);
    // 0x800414AC: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x800414B0: jal         0x80042F80
    // 0x800414B4: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_80042F80(rdram, ctx);
        goto after_32;
    // 0x800414B4: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_32:
    // 0x800414B8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800414BC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800414C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800414C4: addu        $t7, $t6, $s2
    ctx->r15 = ADD32(ctx->r14, ctx->r18);
    // 0x800414C8: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x800414CC: jal         0x80043714
    // 0x800414D0: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_80043714(rdram, ctx);
        goto after_33;
    // 0x800414D0: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_33:
    // 0x800414D4: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800414D8: addu        $t9, $t8, $s2
    ctx->r25 = ADD32(ctx->r24, ctx->r18);
    // 0x800414DC: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x800414E0: sh          $zero, 0x8($t1)
    MEM_H(0X8, ctx->r9) = 0;
    // 0x800414E4: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x800414E8: addu        $t3, $t2, $s2
    ctx->r11 = ADD32(ctx->r10, ctx->r18);
    // 0x800414EC: b           L_80041704
    // 0x800414F0: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
        goto L_80041704;
    // 0x800414F0: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x800414F4: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
L_800414F8:
    // 0x800414F8: addiu       $a0, $sp, 0x158
    ctx->r4 = ADD32(ctx->r29, 0X158);
    // 0x800414FC: addiu       $a1, $sp, 0xB0
    ctx->r5 = ADD32(ctx->r29, 0XB0);
    // 0x80041500: addu        $t5, $t4, $s2
    ctx->r13 = ADD32(ctx->r12, ctx->r18);
    // 0x80041504: lw          $a3, 0x0($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X0);
    // 0x80041508: addiu       $a2, $sp, 0xA4
    ctx->r6 = ADD32(ctx->r29, 0XA4);
    // 0x8004150C: jal         0x8000D59C
    // 0x80041510: addiu       $a3, $a3, 0x58
    ctx->r7 = ADD32(ctx->r7, 0X58);
    func_8000D59C(rdram, ctx);
        goto after_34;
    // 0x80041510: addiu       $a3, $a3, 0x58
    ctx->r7 = ADD32(ctx->r7, 0X58);
    after_34:
    // 0x80041514: beql        $v0, $zero, L_80041648
    if (ctx->r2 == 0) {
        // 0x80041518: lw          $t6, 0x0($s1)
        ctx->r14 = MEM_W(ctx->r17, 0X0);
            goto L_80041648;
    }
    goto skip_34;
    // 0x80041518: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    skip_34:
    // 0x8004151C: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80041520: addiu       $a1, $sp, 0x158
    ctx->r5 = ADD32(ctx->r29, 0X158);
    // 0x80041524: addu        $t7, $t6, $s2
    ctx->r15 = ADD32(ctx->r14, ctx->r18);
    // 0x80041528: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x8004152C: jal         0x80003668
    // 0x80041530: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_80003668(rdram, ctx);
        goto after_35;
    // 0x80041530: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_35:
    // 0x80041534: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80041538: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x8004153C: nop

    // 0x80041540: slti        $at, $t9, 0xC
    ctx->r1 = SIGNED(ctx->r25) < 0XC ? 1 : 0;
    // 0x80041544: beql        $at, $zero, L_80041648
    if (ctx->r1 == 0) {
        // 0x80041548: lw          $t6, 0x0($s1)
        ctx->r14 = MEM_W(ctx->r17, 0X0);
            goto L_80041648;
    }
    goto skip_35;
    // 0x80041548: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    skip_35:
    // 0x8004154C: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80041550: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x80041554: addu        $t2, $t1, $s2
    ctx->r10 = ADD32(ctx->r9, ctx->r18);
    // 0x80041558: lw          $t0, 0x0($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X0);
    // 0x8004155C: lh          $v0, 0x7A($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X7A);
    // 0x80041560: addiu       $a0, $t0, 0x58
    ctx->r4 = ADD32(ctx->r8, 0X58);
    // 0x80041564: andi        $t3, $v0, 0x40
    ctx->r11 = ctx->r2 & 0X40;
    // 0x80041568: beq         $t3, $zero, L_800415C4
    if (ctx->r11 == 0) {
        // 0x8004156C: ori         $t4, $v0, 0x80
        ctx->r12 = ctx->r2 | 0X80;
            goto L_800415C4;
    }
    // 0x8004156C: ori         $t4, $v0, 0x80
    ctx->r12 = ctx->r2 | 0X80;
    // 0x80041570: sh          $t4, 0x7A($t0)
    MEM_H(0X7A, ctx->r8) = ctx->r12;
    // 0x80041574: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80041578: lwc1        $f8, 0x15C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X15C);
    // 0x8004157C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80041580: addu        $t6, $t5, $s2
    ctx->r14 = ADD32(ctx->r13, ctx->r18);
    // 0x80041584: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80041588: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8004158C: swc1        $f6, 0x5C($t7)
    MEM_W(0X5C, ctx->r15) = ctx->f6.u32l;
    // 0x80041590: jal         0x8000E16C
    // 0x80041594: lwc1        $f12, 0xB0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XB0);
    func_8000E16C(rdram, ctx);
        goto after_36;
    // 0x80041594: lwc1        $f12, 0xB0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XB0);
    after_36:
    // 0x80041598: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8004159C: addu        $t9, $t8, $s2
    ctx->r25 = ADD32(ctx->r24, ctx->r18);
    // 0x800415A0: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x800415A4: swc1        $f0, 0x64($t1)
    MEM_W(0X64, ctx->r9) = ctx->f0.u32l;
    // 0x800415A8: jal         0x8000E16C
    // 0x800415AC: lwc1        $f12, 0xB8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XB8);
    func_8000E16C(rdram, ctx);
        goto after_37;
    // 0x800415AC: lwc1        $f12, 0xB8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XB8);
    after_37:
    // 0x800415B0: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x800415B4: addu        $t3, $t2, $s2
    ctx->r11 = ADD32(ctx->r10, ctx->r18);
    // 0x800415B8: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800415BC: b           L_80041644
    // 0x800415C0: swc1        $f0, 0x6C($t4)
    MEM_W(0X6C, ctx->r12) = ctx->f0.u32l;
        goto L_80041644;
    // 0x800415C0: swc1        $f0, 0x6C($t4)
    MEM_W(0X6C, ctx->r12) = ctx->f0.u32l;
L_800415C4:
    // 0x800415C4: lh          $t5, 0xE($t0)
    ctx->r13 = MEM_H(ctx->r8, 0XE);
    // 0x800415C8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800415CC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800415D0: bne         $t5, $at, L_800415E0
    if (ctx->r13 != ctx->r1) {
        // 0x800415D4: nop
    
            goto L_800415E0;
    }
    // 0x800415D4: nop

    // 0x800415D8: b           L_800415E0
    // 0x800415DC: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
        goto L_800415E0;
    // 0x800415DC: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
L_800415E0:
    // 0x800415E0: jal         0x80042F80
    // 0x800415E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80042F80(rdram, ctx);
        goto after_38;
    // 0x800415E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_38:
    // 0x800415E8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800415EC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x800415F0: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x800415F4: addu        $t7, $t6, $s2
    ctx->r15 = ADD32(ctx->r14, ctx->r18);
    // 0x800415F8: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x800415FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80041600: jal         0x8001F2CC
    // 0x80041604: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_8001F2CC(rdram, ctx);
        goto after_39;
    // 0x80041604: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_39:
    // 0x80041608: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8004160C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80041610: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x80041614: addu        $t9, $t8, $s2
    ctx->r25 = ADD32(ctx->r24, ctx->r18);
    // 0x80041618: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x8004161C: jal         0x800425B4
    // 0x80041620: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_800425B4(rdram, ctx);
        goto after_40;
    // 0x80041620: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_40:
    // 0x80041624: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80041628: addu        $t2, $t1, $s2
    ctx->r10 = ADD32(ctx->r9, ctx->r18);
    // 0x8004162C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80041630: sh          $zero, 0x8($t3)
    MEM_H(0X8, ctx->r11) = 0;
    // 0x80041634: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80041638: addu        $t5, $t4, $s2
    ctx->r13 = ADD32(ctx->r12, ctx->r18);
    // 0x8004163C: b           L_80041704
    // 0x80041640: lw          $t0, 0x0($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X0);
        goto L_80041704;
    // 0x80041640: lw          $t0, 0x0($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X0);
L_80041644:
    // 0x80041644: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
L_80041648:
    // 0x80041648: addu        $t7, $t6, $s2
    ctx->r15 = ADD32(ctx->r14, ctx->r18);
    // 0x8004164C: lw          $t0, 0x0($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X0);
    // 0x80041650: lh          $t8, 0x7E($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X7E);
    // 0x80041654: addiu       $a0, $t0, 0x58
    ctx->r4 = ADD32(ctx->r8, 0X58);
    // 0x80041658: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8004165C: bnel        $t9, $zero, L_80041690
    if (ctx->r25 != 0) {
        // 0x80041660: lw          $t5, 0x0($s1)
        ctx->r13 = MEM_W(ctx->r17, 0X0);
            goto L_80041690;
    }
    goto skip_36;
    // 0x80041660: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    skip_36:
    // 0x80041664: jal         0x8003E3F8
    // 0x80041668: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    func_8003E3F8(rdram, ctx);
        goto after_41;
    // 0x80041668: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_41:
    // 0x8004166C: beql        $v0, $zero, L_80041690
    if (ctx->r2 == 0) {
        // 0x80041670: lw          $t5, 0x0($s1)
        ctx->r13 = MEM_W(ctx->r17, 0X0);
            goto L_80041690;
    }
    goto skip_37;
    // 0x80041670: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    skip_37:
    // 0x80041674: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80041678: addu        $t2, $t1, $s2
    ctx->r10 = ADD32(ctx->r9, ctx->r18);
    // 0x8004167C: lw          $t0, 0x0($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X0);
    // 0x80041680: lh          $t3, 0x7E($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X7E);
    // 0x80041684: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x80041688: sh          $t4, 0x7E($t0)
    MEM_H(0X7E, ctx->r8) = ctx->r12;
    // 0x8004168C: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
L_80041690:
    // 0x80041690: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80041694: addu        $t6, $t5, $s2
    ctx->r14 = ADD32(ctx->r13, ctx->r18);
    // 0x80041698: lw          $t0, 0x0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X0);
    // 0x8004169C: lh          $v0, 0x8($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X8);
    // 0x800416A0: addiu       $a0, $t0, 0x58
    ctx->r4 = ADD32(ctx->r8, 0X58);
    // 0x800416A4: bgez        $v0, L_800416E0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800416A8: nop
    
            goto L_800416E0;
    }
    // 0x800416A8: nop

    // 0x800416AC: jal         0x80042F80
    // 0x800416B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80042F80(rdram, ctx);
        goto after_42;
    // 0x800416B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_42:
    // 0x800416B4: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800416B8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800416BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800416C0: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x800416C4: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x800416C8: jal         0x80043714
    // 0x800416CC: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_80043714(rdram, ctx);
        goto after_43;
    // 0x800416CC: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_43:
    // 0x800416D0: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800416D4: addu        $t1, $t9, $s2
    ctx->r9 = ADD32(ctx->r25, ctx->r18);
    // 0x800416D8: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
    // 0x800416DC: lh          $v0, 0x8($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X8);
L_800416E0:
    // 0x800416E0: blez        $v0, L_800416FC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800416E4: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_800416FC;
    }
    // 0x800416E4: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x800416E8: sh          $t2, 0x8($t0)
    MEM_H(0X8, ctx->r8) = ctx->r10;
    // 0x800416EC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x800416F0: addu        $t4, $t3, $s2
    ctx->r12 = ADD32(ctx->r11, ctx->r18);
    // 0x800416F4: lw          $t0, 0x0($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X0);
    // 0x800416F8: lh          $v0, 0x8($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X8);
L_800416FC:
    // 0x800416FC: bgtzl       $v0, L_8004179C
    if (SIGNED(ctx->r2) > 0) {
        // 0x80041700: lw          $t9, 0x16C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X16C);
            goto L_8004179C;
    }
    goto skip_38;
    // 0x80041700: lw          $t9, 0x16C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X16C);
    skip_38:
L_80041704:
    // 0x80041704: lw          $t5, 0x4($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X4);
    // 0x80041708: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004170C: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    // 0x80041710: lw          $v0, 0x8($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X8);
    // 0x80041714: lw          $t6, 0xD8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XD8);
    // 0x80041718: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8004171C: sw          $t7, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r15;
    // 0x80041720: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80041724: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80041728: addu        $t9, $t8, $s2
    ctx->r25 = ADD32(ctx->r24, ctx->r18);
    // 0x8004172C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80041730: lh          $v1, 0xE($t0)
    ctx->r3 = MEM_H(ctx->r8, 0XE);
    // 0x80041734: addiu       $a0, $t0, 0x58
    ctx->r4 = ADD32(ctx->r8, 0X58);
    // 0x80041738: beq         $v1, $at, L_80041748
    if (ctx->r3 == ctx->r1) {
        // 0x8004173C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80041748;
    }
    // 0x8004173C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80041740: bnel        $v1, $at, L_80041784
    if (ctx->r3 != ctx->r1) {
        // 0x80041744: lh          $t5, 0x7A($t0)
        ctx->r13 = MEM_H(ctx->r8, 0X7A);
            goto L_80041784;
    }
    goto skip_39;
    // 0x80041744: lh          $t5, 0x7A($t0)
    ctx->r13 = MEM_H(ctx->r8, 0X7A);
    skip_39:
L_80041748:
    // 0x80041748: jal         0x80042F80
    // 0x8004174C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80042F80(rdram, ctx);
        goto after_44;
    // 0x8004174C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_44:
    // 0x80041750: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80041754: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80041758: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x8004175C: addu        $t2, $t1, $s2
    ctx->r10 = ADD32(ctx->r9, ctx->r18);
    // 0x80041760: lw          $a1, 0x0($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X0);
    // 0x80041764: jal         0x8003E7B0
    // 0x80041768: addiu       $a1, $a1, 0x58
    ctx->r5 = ADD32(ctx->r5, 0X58);
    func_8003E7B0(rdram, ctx);
        goto after_45;
    // 0x80041768: addiu       $a1, $a1, 0x58
    ctx->r5 = ADD32(ctx->r5, 0X58);
    after_45:
    // 0x8004176C: jal         0x80044480
    // 0x80041770: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    func_80044480(rdram, ctx);
        goto after_46;
    // 0x80041770: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    after_46:
    // 0x80041774: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80041778: addu        $t4, $t3, $s2
    ctx->r12 = ADD32(ctx->r11, ctx->r18);
    // 0x8004177C: lw          $t0, 0x0($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X0);
    // 0x80041780: lh          $t5, 0x7A($t0)
    ctx->r13 = MEM_H(ctx->r8, 0X7A);
L_80041784:
    // 0x80041784: andi        $t6, $t5, 0xFFFE
    ctx->r14 = ctx->r13 & 0XFFFE;
    // 0x80041788: sh          $t6, 0x7A($t0)
    MEM_H(0X7A, ctx->r8) = ctx->r14;
    // 0x8004178C: lh          $t7, 0x4($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X4);
    // 0x80041790: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80041794: sh          $t8, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r24;
    // 0x80041798: lw          $t9, 0x16C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X16C);
L_8004179C:
    // 0x8004179C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800417A0: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x800417A4: sw          $t1, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r9;
    // 0x800417A8: lh          $t2, 0x6($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X6);
    // 0x800417AC: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800417B0: bnel        $at, $zero, L_80040908
    if (ctx->r1 != 0) {
        // 0x800417B4: lw          $t8, 0x0($s1)
        ctx->r24 = MEM_W(ctx->r17, 0X0);
            goto L_80040908;
    }
    goto skip_40;
    // 0x800417B4: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    skip_40:
L_800417B8:
    // 0x800417B8: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_800417BC:
    // 0x800417BC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800417C0: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800417C4: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x800417C8: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800417CC: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x800417D0: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800417D4: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x800417D8: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x800417DC: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x800417E0: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x800417E4: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x800417E8: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x800417EC: jr          $ra
    // 0x800417F0: addiu       $sp, $sp, 0x170
    ctx->r29 = ADD32(ctx->r29, 0X170);
    TRACE_RETURN()
    return;
    // 0x800417F0: addiu       $sp, $sp, 0x170
    ctx->r29 = ADD32(ctx->r29, 0X170);
;}
RECOMP_FUNC void func_800417F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800417F4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800417F8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800417FC: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80041800: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80041804: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80041808: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8004180C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80041810: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80041814: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x80041818: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8004181C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80041820: blez        $t6, L_80041884
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80041824: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80041884;
    }
    // 0x80041824: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80041828: lui         $s5, 0x801A
    ctx->r21 = S32(0X801A << 16);
    // 0x8004182C: addiu       $s5, $s5, 0x2800
    ctx->r21 = ADD32(ctx->r21, 0X2800);
    // 0x80041830: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // 0x80041834: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
L_80041838:
    // 0x80041838: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x8004183C: lw          $s0, 0x0($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X0);
    // 0x80041840: lh          $t9, 0x10($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X10);
    // 0x80041844: beql        $s4, $t9, L_80041864
    if (ctx->r20 == ctx->r25) {
        // 0x80041848: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80041864;
    }
    goto skip_0;
    // 0x80041848: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_0:
    // 0x8004184C: jal         0x8004A0C4
    // 0x80041850: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    func_8004A0C4(rdram, ctx);
        goto after_0;
    // 0x80041850: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_0:
    // 0x80041854: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x80041858: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x8004185C: lw          $s0, 0x0($t1)
    ctx->r16 = MEM_W(ctx->r9, 0X0);
    // 0x80041860: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80041864:
    // 0x80041864: jal         0x800042A8
    // 0x80041868: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800042A8(rdram, ctx);
        goto after_1;
    // 0x80041868: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x8004186C: lh          $t2, 0x6($s3)
    ctx->r10 = MEM_H(ctx->r19, 0X6);
    // 0x80041870: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80041874: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80041878: slt         $at, $s2, $t2
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8004187C: bnel        $at, $zero, L_80041838
    if (ctx->r1 != 0) {
        // 0x80041880: lw          $t7, 0x0($s3)
        ctx->r15 = MEM_W(ctx->r19, 0X0);
            goto L_80041838;
    }
    goto skip_1;
    // 0x80041880: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    skip_1:
L_80041884:
    // 0x80041884: lui         $s5, 0x801A
    ctx->r21 = S32(0X801A << 16);
    // 0x80041888: addiu       $s5, $s5, 0x2800
    ctx->r21 = ADD32(ctx->r21, 0X2800);
    // 0x8004188C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80041890: jal         0x800042A8
    // 0x80041894: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    func_800042A8(rdram, ctx);
        goto after_2;
    // 0x80041894: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    after_2:
    // 0x80041898: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8004189C: jal         0x800042A8
    // 0x800418A0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800042A8(rdram, ctx);
        goto after_3;
    // 0x800418A0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_3:
    // 0x800418A4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800418A8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800418AC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800418B0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800418B4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800418B8: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800418BC: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800418C0: jr          $ra
    // 0x800418C4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    TRACE_RETURN()
    return;
    // 0x800418C4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800418C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800418C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800418CC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800418D0: lw          $v0, -0x6588($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6588);
    // 0x800418D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800418D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800418DC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800418E0: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x800418E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800418E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800418EC: blezl       $t6, L_80041980
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800418F0: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_80041980;
    }
    goto skip_0;
    // 0x800418F0: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    skip_0:
    // 0x800418F4: lh          $a3, 0x6($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X6);
    // 0x800418F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800418FC: blezl       $a3, L_80041980
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80041900: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_80041980;
    }
    goto skip_1;
    // 0x80041900: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    skip_1:
    // 0x80041904: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80041908: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
L_8004190C:
    // 0x8004190C: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x80041910: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x80041914: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80041918: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x8004191C: lh          $t9, 0x8($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X8);
    // 0x80041920: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80041924: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80041928: blez        $t9, L_80041974
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8004192C: nop
    
            goto L_80041974;
    }
    // 0x8004192C: nop

    // 0x80041930: lh          $t0, 0x7A($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X7A);
    // 0x80041934: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x80041938: beq         $t1, $zero, L_80041974
    if (ctx->r9 == 0) {
        // 0x8004193C: nop
    
            goto L_80041974;
    }
    // 0x8004193C: nop

    // 0x80041940: lw          $v1, 0x14($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X14);
    // 0x80041944: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80041948: bne         $v1, $s0, L_80041974
    if (ctx->r3 != ctx->r16) {
        // 0x8004194C: nop
    
            goto L_80041974;
    }
    // 0x8004194C: nop

    // 0x80041950: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80041954: jal         0x80003668
    // 0x80041958: addiu       $a1, $v0, 0x58
    ctx->r5 = ADD32(ctx->r2, 0X58);
    func_80003668(rdram, ctx);
        goto after_0;
    // 0x80041958: addiu       $a1, $v0, 0x58
    ctx->r5 = ADD32(ctx->r2, 0X58);
    after_0:
    // 0x8004195C: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80041960: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80041964: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80041968: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x8004196C: b           L_80041980
    // 0x80041970: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
        goto L_80041980;
    // 0x80041970: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
L_80041974:
    // 0x80041974: bnel        $at, $zero, L_8004190C
    if (ctx->r1 != 0) {
        // 0x80041978: sll         $t7, $a0, 2
        ctx->r15 = S32(ctx->r4 << 2);
            goto L_8004190C;
    }
    goto skip_2;
    // 0x80041978: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    skip_2:
    // 0x8004197C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_80041980:
    // 0x80041980: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80041984: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80041988: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004198C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80041994(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80041994: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80041998: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8004199C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800419A0: sll         $s0, $a0, 16
    ctx->r16 = S32(ctx->r4 << 16);
    // 0x800419A4: lui         $s4, 0x801A
    ctx->r20 = S32(0X801A << 16);
    // 0x800419A8: addiu       $s4, $s4, 0x2800
    ctx->r20 = ADD32(ctx->r20, 0X2800);
    // 0x800419AC: sra         $t6, $s0, 16
    ctx->r14 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800419B0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800419B4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800419B8: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x800419BC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800419C0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800419C4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800419C8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800419CC: jal         0x80004364
    // 0x800419D0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x800419D0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x800419D4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800419D8: sh          $s0, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r16;
    // 0x800419DC: beq         $s0, $zero, L_800419F8
    if (ctx->r16 == 0) {
        // 0x800419E0: sh          $zero, 0x4($v0)
        MEM_H(0X4, ctx->r2) = 0;
            goto L_800419F8;
    }
    // 0x800419E0: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x800419E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800419E8: beq         $s0, $at, L_80041A04
    if (ctx->r16 == ctx->r1) {
        // 0x800419EC: addiu       $t8, $zero, 0x4
        ctx->r24 = ADD32(0, 0X4);
            goto L_80041A04;
    }
    // 0x800419EC: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x800419F0: b           L_80041A0C
    // 0x800419F4: lh          $a1, 0x6($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X6);
        goto L_80041A0C;
    // 0x800419F4: lh          $a1, 0x6($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X6);
L_800419F8:
    // 0x800419F8: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800419FC: b           L_80041A08
    // 0x80041A00: sh          $t7, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r15;
        goto L_80041A08;
    // 0x80041A00: sh          $t7, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r15;
L_80041A04:
    // 0x80041A04: sh          $t8, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r24;
L_80041A08:
    // 0x80041A08: lh          $a1, 0x6($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X6);
L_80041A0C:
    // 0x80041A0C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80041A10: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80041A14: jal         0x80004364
    // 0x80041A18: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    func_80004364(rdram, ctx);
        goto after_1;
    // 0x80041A18: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_1:
    // 0x80041A1C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80041A20: lh          $t0, 0x6($s3)
    ctx->r8 = MEM_H(ctx->r19, 0X6);
    // 0x80041A24: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80041A28: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80041A2C: blez        $t0, L_80041A68
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80041A30: addiu       $s2, $zero, -0x1
        ctx->r18 = ADD32(0, -0X1);
            goto L_80041A68;
    }
    // 0x80041A30: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x80041A34: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_80041A38:
    // 0x80041A38: jal         0x80004364
    // 0x80041A3C: addiu       $a1, $zero, 0x9C
    ctx->r5 = ADD32(0, 0X9C);
    func_80004364(rdram, ctx);
        goto after_2;
    // 0x80041A3C: addiu       $a1, $zero, 0x9C
    ctx->r5 = ADD32(0, 0X9C);
    after_2:
    // 0x80041A40: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80041A44: sh          $zero, 0x84($v0)
    MEM_H(0X84, ctx->r2) = 0;
    // 0x80041A48: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80041A4C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80041A50: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80041A54: sh          $s2, 0x76($t1)
    MEM_H(0X76, ctx->r9) = ctx->r18;
    // 0x80041A58: lh          $t2, 0x6($s3)
    ctx->r10 = MEM_H(ctx->r19, 0X6);
    // 0x80041A5C: slt         $at, $s1, $t2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80041A60: bnel        $at, $zero, L_80041A38
    if (ctx->r1 != 0) {
        // 0x80041A64: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80041A38;
    }
    goto skip_0;
    // 0x80041A64: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_0:
L_80041A68:
    // 0x80041A68: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80041A6C: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x80041A70: sw          $t3, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r11;
    // 0x80041A74: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80041A78: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80041A7C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80041A80: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80041A84: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80041A88: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80041A8C: jr          $ra
    // 0x80041A90: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    TRACE_RETURN()
    return;
    // 0x80041A90: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80041A94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80041A94: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x80041A98: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80041A9C: lh          $t8, -0x6B94($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X6B94);
    // 0x80041AA0: sw          $a0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r4;
    // 0x80041AA4: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80041AA8: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80041AAC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80041AB0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80041AB4: sw          $a1, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r5;
    // 0x80041AB8: sw          $a2, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r6;
    // 0x80041ABC: bne         $t8, $zero, L_80041ACC
    if (ctx->r24 != 0) {
        // 0x80041AC0: sw          $a3, 0xE4($sp)
        MEM_W(0XE4, ctx->r29) = ctx->r7;
            goto L_80041ACC;
    }
    // 0x80041AC0: sw          $a3, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r7;
    // 0x80041AC4: b           L_80041EE0
    // 0x80041AC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80041EE0;
    // 0x80041AC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80041ACC:
    // 0x80041ACC: beq         $a0, $zero, L_80041AE8
    if (ctx->r4 == 0) {
        // 0x80041AD0: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_80041AE8;
    }
    // 0x80041AD0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80041AD4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80041AD8: beq         $a0, $at, L_80041B08
    if (ctx->r4 == ctx->r1) {
        // 0x80041ADC: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_80041B08;
    }
    // 0x80041ADC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80041AE0: b           L_80041B24
    // 0x80041AE4: lw          $s0, 0xD0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XD0);
        goto L_80041B24;
    // 0x80041AE4: lw          $s0, 0xD0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XD0);
L_80041AE8:
    // 0x80041AE8: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80041AEC: lw          $t2, -0x6590($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X6590);
    // 0x80041AF0: lui         $t9, 0x8007
    ctx->r25 = S32(0X8007 << 16);
    // 0x80041AF4: addiu       $t9, $t9, -0x5838
    ctx->r25 = ADD32(ctx->r25, -0X5838);
    // 0x80041AF8: lw          $s0, -0x6580($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X6580);
    // 0x80041AFC: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x80041B00: b           L_80041B24
    // 0x80041B04: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
        goto L_80041B24;
    // 0x80041B04: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
L_80041B08:
    // 0x80041B08: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80041B0C: lw          $t2, -0x6588($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X6588);
    // 0x80041B10: lui         $t4, 0x8007
    ctx->r12 = S32(0X8007 << 16);
    // 0x80041B14: addiu       $t4, $t4, -0x5828
    ctx->r12 = ADD32(ctx->r12, -0X5828);
    // 0x80041B18: lw          $s0, -0x6574($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X6574);
    // 0x80041B1C: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
    // 0x80041B20: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
L_80041B24:
    // 0x80041B24: lh          $t6, 0xE6($sp)
    ctx->r14 = MEM_H(ctx->r29, 0XE6);
    // 0x80041B28: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80041B2C: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80041B30: addu        $t3, $t5, $t7
    ctx->r11 = ADD32(ctx->r13, ctx->r15);
    // 0x80041B34: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x80041B38: jal         0x80049CFC
    // 0x80041B3C: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    func_80049CFC(rdram, ctx);
        goto after_0;
    // 0x80041B3C: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    after_0:
    // 0x80041B40: sh          $v0, 0xCE($sp)
    MEM_H(0XCE, ctx->r29) = ctx->r2;
    // 0x80041B44: lh          $t8, 0x4($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X4);
    // 0x80041B48: lh          $a3, 0x6($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X6);
    // 0x80041B4C: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80041B50: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80041B54: slt         $at, $t8, $a3
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80041B58: bne         $at, $zero, L_80041B68
    if (ctx->r1 != 0) {
        // 0x80041B5C: nop
    
            goto L_80041B68;
    }
    // 0x80041B5C: nop

    // 0x80041B60: b           L_80041EE0
    // 0x80041B64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80041EE0;
    // 0x80041B64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80041B68:
    // 0x80041B68: blez        $a3, L_80041BC4
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80041B6C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80041BC4;
    }
    // 0x80041B6C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80041B70: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80041B74: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_80041B78:
    // 0x80041B78: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x80041B7C: lh          $t9, 0x84($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X84);
    // 0x80041B80: andi        $t4, $t9, 0x1
    ctx->r12 = ctx->r25 & 0X1;
    // 0x80041B84: bnel        $t4, $zero, L_80041BB8
    if (ctx->r12 != 0) {
        // 0x80041B88: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80041BB8;
    }
    goto skip_0;
    // 0x80041B88: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_0:
    // 0x80041B8C: sh          $a0, 0xCC($sp)
    MEM_H(0XCC, ctx->r29) = ctx->r4;
    // 0x80041B90: lh          $a2, 0x76($a1)
    ctx->r6 = MEM_H(ctx->r5, 0X76);
    // 0x80041B94: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x80041B98: sra         $t5, $t6, 16
    ctx->r13 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80041B9C: beq         $t5, $a2, L_80041BAC
    if (ctx->r13 == ctx->r6) {
        // 0x80041BA0: nop
    
            goto L_80041BAC;
    }
    // 0x80041BA0: nop

    // 0x80041BA4: bnel        $t1, $a2, L_80041BB8
    if (ctx->r9 != ctx->r6) {
        // 0x80041BA8: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80041BB8;
    }
    goto skip_1;
    // 0x80041BA8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_1:
L_80041BAC:
    // 0x80041BAC: b           L_80041BC8
    // 0x80041BB0: lh          $t0, 0xCC($sp)
    ctx->r8 = MEM_H(ctx->r29, 0XCC);
        goto L_80041BC8;
    // 0x80041BB0: lh          $t0, 0xCC($sp)
    ctx->r8 = MEM_H(ctx->r29, 0XCC);
    // 0x80041BB4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80041BB8:
    // 0x80041BB8: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80041BBC: bne         $at, $zero, L_80041B78
    if (ctx->r1 != 0) {
        // 0x80041BC0: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80041B78;
    }
    // 0x80041BC0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80041BC4:
    // 0x80041BC4: lh          $t0, 0xCC($sp)
    ctx->r8 = MEM_H(ctx->r29, 0XCC);
L_80041BC8:
    // 0x80041BC8: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80041BCC: sll         $t4, $v0, 16
    ctx->r12 = S32(ctx->r2 << 16);
    // 0x80041BD0: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x80041BD4: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x80041BD8: lw          $v1, 0x0($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X0);
    // 0x80041BDC: sra         $t6, $t4, 16
    ctx->r14 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80041BE0: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80041BE4: lh          $a0, 0x76($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X76);
    // 0x80041BE8: or          $t0, $t7, $zero
    ctx->r8 = ctx->r15 | 0;
    // 0x80041BEC: beql        $t6, $a0, L_80041CA8
    if (ctx->r14 == ctx->r4) {
        // 0x80041BF0: addiu       $a0, $zero, 0xF
        ctx->r4 = ADD32(0, 0XF);
            goto L_80041CA8;
    }
    goto skip_2;
    // 0x80041BF0: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    skip_2:
    // 0x80041BF4: beql        $t1, $a0, L_80041C20
    if (ctx->r9 == ctx->r4) {
        // 0x80041BF8: lh          $a0, 0xCE($sp)
        ctx->r4 = MEM_H(ctx->r29, 0XCE);
            goto L_80041C20;
    }
    goto skip_3;
    // 0x80041BF8: lh          $a0, 0xCE($sp)
    ctx->r4 = MEM_H(ctx->r29, 0XCE);
    skip_3:
    // 0x80041BFC: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x80041C00: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x80041C04: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x80041C08: jal         0x8004A0C4
    // 0x80041C0C: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    func_8004A0C4(rdram, ctx);
        goto after_1;
    // 0x80041C0C: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    after_1:
    // 0x80041C10: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80041C14: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80041C18: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80041C1C: lh          $a0, 0xCE($sp)
    ctx->r4 = MEM_H(ctx->r29, 0XCE);
L_80041C20:
    // 0x80041C20: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x80041C24: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x80041C28: jal         0x80049D80
    // 0x80041C2C: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    func_80049D80(rdram, ctx);
        goto after_2;
    // 0x80041C2C: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    after_2:
    // 0x80041C30: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80041C34: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80041C38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80041C3C: addu        $t7, $t5, $t0
    ctx->r15 = ADD32(ctx->r13, ctx->r8);
    // 0x80041C40: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80041C44: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x80041C48: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80041C4C: addu        $t4, $t9, $t0
    ctx->r12 = ADD32(ctx->r25, ctx->r8);
    // 0x80041C50: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80041C54: jal         0x80049DFC
    // 0x80041C58: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_80049DFC(rdram, ctx);
        goto after_3;
    // 0x80041C58: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_3:
    // 0x80041C5C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80041C60: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80041C64: addu        $t7, $t5, $t0
    ctx->r15 = ADD32(ctx->r13, ctx->r8);
    // 0x80041C68: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80041C6C: sw          $v0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r2;
    // 0x80041C70: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80041C74: addu        $t4, $t9, $t0
    ctx->r12 = ADD32(ctx->r25, ctx->r8);
    // 0x80041C78: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80041C7C: jal         0x8004A148
    // 0x80041C80: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    func_8004A148(rdram, ctx);
        goto after_4;
    // 0x80041C80: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    after_4:
    // 0x80041C84: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80041C88: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80041C8C: lh          $t5, 0xCE($sp)
    ctx->r13 = MEM_H(ctx->r29, 0XCE);
    // 0x80041C90: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80041C94: addu        $t8, $t7, $t0
    ctx->r24 = ADD32(ctx->r15, ctx->r8);
    // 0x80041C98: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80041C9C: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80041CA0: sh          $t5, 0x76($t9)
    MEM_H(0X76, ctx->r25) = ctx->r13;
    // 0x80041CA4: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
L_80041CA8:
    // 0x80041CA8: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x80041CAC: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x80041CB0: jal         0x80044480
    // 0x80041CB4: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    func_80044480(rdram, ctx);
        goto after_5;
    // 0x80041CB4: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    after_5:
    // 0x80041CB8: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80041CBC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80041CC0: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80041CC4: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80041CC8: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x80041CCC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80041CD0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80041CD4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80041CD8: sh          $t4, 0x84($t8)
    MEM_H(0X84, ctx->r24) = ctx->r12;
    // 0x80041CDC: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80041CE0: lh          $t5, 0xE6($sp)
    ctx->r13 = MEM_H(ctx->r29, 0XE6);
    // 0x80041CE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80041CE8: addu        $t6, $t9, $t0
    ctx->r14 = ADD32(ctx->r25, ctx->r8);
    // 0x80041CEC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80041CF0: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    // 0x80041CF4: sh          $t5, 0x74($t7)
    MEM_H(0X74, ctx->r15) = ctx->r13;
    // 0x80041CF8: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80041CFC: lwc1        $f4, 0x4($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X4);
    // 0x80041D00: addu        $t8, $t4, $t0
    ctx->r24 = ADD32(ctx->r12, ctx->r8);
    // 0x80041D04: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80041D08: swc1        $f4, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->f4.u32l;
    // 0x80041D0C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80041D10: lh          $t6, 0xC($t3)
    ctx->r14 = MEM_H(ctx->r11, 0XC);
    // 0x80041D14: addu        $t7, $t5, $t0
    ctx->r15 = ADD32(ctx->r13, ctx->r8);
    // 0x80041D18: lw          $t4, 0x0($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X0);
    // 0x80041D1C: sh          $t6, 0x78($t4)
    MEM_H(0X78, ctx->r12) = ctx->r14;
    // 0x80041D20: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80041D24: lh          $t8, 0xE($t3)
    ctx->r24 = MEM_H(ctx->r11, 0XE);
    // 0x80041D28: addu        $t5, $t9, $t0
    ctx->r13 = ADD32(ctx->r25, ctx->r8);
    // 0x80041D2C: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x80041D30: sh          $t8, 0x7A($t7)
    MEM_H(0X7A, ctx->r15) = ctx->r24;
    // 0x80041D34: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80041D38: addu        $t4, $t6, $t0
    ctx->r12 = ADD32(ctx->r14, ctx->r8);
    // 0x80041D3C: lw          $t9, 0x0($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X0);
    // 0x80041D40: addiu       $t6, $zero, 0x3E8
    ctx->r14 = ADD32(0, 0X3E8);
    // 0x80041D44: sh          $zero, 0x7C($t9)
    MEM_H(0X7C, ctx->r25) = 0;
    // 0x80041D48: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80041D4C: addu        $t8, $t5, $t0
    ctx->r24 = ADD32(ctx->r13, ctx->r8);
    // 0x80041D50: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x80041D54: swc1        $f0, 0x80($t7)
    MEM_W(0X80, ctx->r15) = ctx->f0.u32l;
    // 0x80041D58: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80041D5C: addu        $t9, $t4, $t0
    ctx->r25 = ADD32(ctx->r12, ctx->r8);
    // 0x80041D60: lw          $t5, 0x0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X0);
    // 0x80041D64: sh          $t6, 0x8E($t5)
    MEM_H(0X8E, ctx->r13) = ctx->r14;
    // 0x80041D68: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80041D6C: addu        $t7, $t8, $t0
    ctx->r15 = ADD32(ctx->r24, ctx->r8);
    // 0x80041D70: lw          $t4, 0x0($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X0);
    // 0x80041D74: sh          $zero, 0x9A($t4)
    MEM_H(0X9A, ctx->r12) = 0;
    // 0x80041D78: lw          $v1, 0xDC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XDC);
L_80041D7C:
    // 0x80041D7C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80041D80: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80041D84: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80041D88: addu        $t6, $t9, $t0
    ctx->r14 = ADD32(ctx->r25, ctx->r8);
    // 0x80041D8C: lw          $t5, 0x0($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X0);
    // 0x80041D90: addu        $t8, $t5, $v0
    ctx->r24 = ADD32(ctx->r13, ctx->r2);
    // 0x80041D94: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80041D98: slti        $at, $v0, 0xC
    ctx->r1 = SIGNED(ctx->r2) < 0XC ? 1 : 0;
    // 0x80041D9C: bne         $at, $zero, L_80041D7C
    if (ctx->r1 != 0) {
        // 0x80041DA0: swc1        $f6, 0x8($t8)
        MEM_W(0X8, ctx->r24) = ctx->f6.u32l;
            goto L_80041D7C;
    }
    // 0x80041DA0: swc1        $f6, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f6.u32l;
    // 0x80041DA4: lw          $t7, 0xE0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE0);
    // 0x80041DA8: lui         $at, 0x3D80
    ctx->r1 = S32(0X3D80 << 16);
    // 0x80041DAC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80041DB0: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80041DB4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80041DB8: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x80041DBC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80041DC0: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x80041DC4: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x80041DC8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80041DCC: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80041DD0: jal         0x80049840
    // 0x80041DD4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_80049840(rdram, ctx);
        goto after_6;
    // 0x80041DD4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_6:
    // 0x80041DD8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80041DDC: lw          $t4, 0xE0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE0);
    // 0x80041DE0: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80041DE4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80041DE8: lw          $a1, 0x4($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X4);
    // 0x80041DEC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80041DF0: jal         0x80049840
    // 0x80041DF4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80049840(rdram, ctx);
        goto after_7;
    // 0x80041DF4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x80041DF8: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    // 0x80041DFC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80041E00: jal         0x80000BD8
    // 0x80041E04: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    func_80000BD8(rdram, ctx);
        goto after_8;
    // 0x80041E04: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    after_8:
    // 0x80041E08: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80041E0C: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80041E10: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80041E14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80041E18: addiu       $v1, $sp, 0x8C
    ctx->r3 = ADD32(ctx->r29, 0X8C);
    // 0x80041E1C: addiu       $a0, $sp, 0x98
    ctx->r4 = ADD32(ctx->r29, 0X98);
L_80041E20:
    // 0x80041E20: lwc1        $f18, 0x8($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X8);
    // 0x80041E24: lwc1        $f4, 0x20($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X20);
    // 0x80041E28: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80041E2C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80041E30: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80041E34: addu        $t6, $t9, $t0
    ctx->r14 = ADD32(ctx->r25, ctx->r8);
    // 0x80041E38: lw          $t5, 0x0($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X0);
    // 0x80041E3C: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x80041E40: addu        $t8, $t5, $v0
    ctx->r24 = ADD32(ctx->r13, ctx->r2);
    // 0x80041E44: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80041E48: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80041E4C: bne         $at, $zero, L_80041E20
    if (ctx->r1 != 0) {
        // 0x80041E50: swc1        $f8, 0x68($t8)
        MEM_W(0X68, ctx->r24) = ctx->f8.u32l;
            goto L_80041E20;
    }
    // 0x80041E50: swc1        $f8, 0x68($t8)
    MEM_W(0X68, ctx->r24) = ctx->f8.u32l;
    // 0x80041E54: lh          $t7, 0x4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X4);
    // 0x80041E58: addiu       $t4, $t7, 0x1
    ctx->r12 = ADD32(ctx->r15, 0X1);
    // 0x80041E5C: sh          $t4, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r12;
    // 0x80041E60: lh          $t9, 0x4($t2)
    ctx->r25 = MEM_H(ctx->r10, 0X4);
    // 0x80041E64: blezl       $t9, L_80041EE0
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80041E68: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80041EE0;
    }
    goto skip_4;
    // 0x80041E68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_4:
    // 0x80041E6C: lh          $a2, 0x6($t2)
    ctx->r6 = MEM_H(ctx->r10, 0X6);
    // 0x80041E70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80041E74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80041E78: blezl       $a2, L_80041EE0
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80041E7C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80041EE0;
    }
    goto skip_5;
    // 0x80041E7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_5:
L_80041E80:
    // 0x80041E80: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x80041E84: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80041E88: addu        $t5, $t6, $v0
    ctx->r13 = ADD32(ctx->r14, ctx->r2);
    // 0x80041E8C: lw          $v1, 0x0($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X0);
    // 0x80041E90: lh          $t8, 0x8($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X8);
    // 0x80041E94: blezl       $t8, L_80041ED4
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80041E98: slt         $at, $a0, $a2
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_80041ED4;
    }
    goto skip_6;
    // 0x80041E98: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    skip_6:
    // 0x80041E9C: lh          $a1, 0x7A($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X7A);
    // 0x80041EA0: andi        $t7, $a1, 0x2
    ctx->r15 = ctx->r5 & 0X2;
    // 0x80041EA4: beq         $t7, $zero, L_80041ED0
    if (ctx->r15 == 0) {
        // 0x80041EA8: ori         $t4, $a1, 0x10
        ctx->r12 = ctx->r5 | 0X10;
            goto L_80041ED0;
    }
    // 0x80041EA8: ori         $t4, $a1, 0x10
    ctx->r12 = ctx->r5 | 0X10;
    // 0x80041EAC: sh          $t4, 0x7A($v1)
    MEM_H(0X7A, ctx->r3) = ctx->r12;
    // 0x80041EB0: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x80041EB4: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80041EB8: addu        $t7, $t8, $v0
    ctx->r15 = ADD32(ctx->r24, ctx->r2);
    // 0x80041EBC: addu        $t6, $t9, $t0
    ctx->r14 = ADD32(ctx->r25, ctx->r8);
    // 0x80041EC0: lw          $t5, 0x0($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X0);
    // 0x80041EC4: lw          $t4, 0x0($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X0);
    // 0x80041EC8: sw          $t5, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r13;
    // 0x80041ECC: lh          $a2, 0x6($t2)
    ctx->r6 = MEM_H(ctx->r10, 0X6);
L_80041ED0:
    // 0x80041ED0: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
L_80041ED4:
    // 0x80041ED4: bne         $at, $zero, L_80041E80
    if (ctx->r1 != 0) {
        // 0x80041ED8: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80041E80;
    }
    // 0x80041ED8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80041EDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80041EE0:
    // 0x80041EE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80041EE4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80041EE8: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    // 0x80041EEC: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80041EF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80041EF4: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x80041EF8: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80041EFC: sw          $s7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r23;
    // 0x80041F00: sw          $s6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r22;
    // 0x80041F04: sw          $s5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r21;
    // 0x80041F08: sw          $s4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r20;
    // 0x80041F0C: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x80041F10: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x80041F14: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x80041F18: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x80041F1C: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80041F20: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80041F24: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80041F28: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80041F2C: lh          $t6, 0x4($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X4);
    // 0x80041F30: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80041F34: beql        $t6, $zero, L_800422B4
    if (ctx->r14 == 0) {
        // 0x80041F38: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_800422B4;
    }
    goto skip_0;
    // 0x80041F38: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    skip_0:
    // 0x80041F3C: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x80041F40: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80041F44: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80041F48: blez        $t7, L_800422B0
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80041F4C: lui         $at, 0x8007
        ctx->r1 = S32(0X8007 << 16);
            goto L_800422B0;
    }
    // 0x80041F4C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80041F50: lwc1        $f26, 0x76C4($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X76C4);
    // 0x80041F54: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80041F58: lwc1        $f24, 0x76C8($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X76C8);
    // 0x80041F5C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80041F60: lwc1        $f22, 0x76CC($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X76CC);
    // 0x80041F64: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80041F68: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80041F6C: addiu       $s7, $sp, 0xB0
    ctx->r23 = ADD32(ctx->r29, 0XB0);
    // 0x80041F70: addiu       $s6, $sp, 0x6C
    ctx->r22 = ADD32(ctx->r29, 0X6C);
    // 0x80041F74: addiu       $s4, $zero, -0x2
    ctx->r20 = ADD32(0, -0X2);
    // 0x80041F78: addiu       $s3, $zero, 0xC
    ctx->r19 = ADD32(0, 0XC);
    // 0x80041F7C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
L_80041F80:
    // 0x80041F80: addu        $t9, $t8, $s2
    ctx->r25 = ADD32(ctx->r24, ctx->r18);
    // 0x80041F84: lw          $s0, 0x0($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X0);
    // 0x80041F88: lh          $t0, 0x84($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X84);
    // 0x80041F8C: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x80041F90: beql        $t1, $zero, L_8004229C
    if (ctx->r9 == 0) {
        // 0x80041F94: lh          $t3, 0x6($s1)
        ctx->r11 = MEM_H(ctx->r17, 0X6);
            goto L_8004229C;
    }
    goto skip_1;
    // 0x80041F94: lh          $t3, 0x6($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X6);
    skip_1:
    // 0x80041F98: lwc1        $f4, 0x6C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80041F9C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80041FA0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80041FA4: sub.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f22.fl;
    // 0x80041FA8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80041FAC: swc1        $f6, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f6.u32l;
    // 0x80041FB0: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80041FB4: addu        $t3, $t2, $s2
    ctx->r11 = ADD32(ctx->r10, ctx->r18);
    // 0x80041FB8: lw          $s0, 0x0($t3)
    ctx->r16 = MEM_W(ctx->r11, 0X0);
    // 0x80041FBC: lwc1        $f8, 0x80($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X80);
    // 0x80041FC0: add.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f24.fl;
    // 0x80041FC4: swc1        $f10, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f10.u32l;
    // 0x80041FC8: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80041FCC: addu        $t5, $t4, $s2
    ctx->r13 = ADD32(ctx->r12, ctx->r18);
    // 0x80041FD0: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80041FD4: lw          $a1, 0x80($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X80);
    // 0x80041FD8: jal         0x80049840
    // 0x80041FDC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    func_80049840(rdram, ctx);
        goto after_0;
    // 0x80041FDC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_0:
    // 0x80041FE0: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80041FE4: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x80041FE8: lw          $s0, 0x0($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X0);
    // 0x80041FEC: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80041FF0: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x80041FF4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80041FF8: lw          $a0, 0x8($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X8);
    // 0x80041FFC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80042000: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80042004: jal         0x80001AB4
    // 0x80042008: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80001AB4(rdram, ctx);
        goto after_1;
    // 0x80042008: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_1:
    // 0x8004200C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80042010: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80042014: addu        $t1, $t0, $s2
    ctx->r9 = ADD32(ctx->r8, ctx->r18);
    // 0x80042018: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8004201C: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x80042020: lw          $a0, 0x8($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X8);
    // 0x80042024: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80042028: jal         0x80000BD8
    // 0x8004202C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_80000BD8(rdram, ctx);
        goto after_2;
    // 0x8004202C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_2:
    // 0x80042030: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80042034: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80042038: addiu       $s3, $s3, -0x4
    ctx->r19 = ADD32(ctx->r19, -0X4);
    // 0x8004203C: addu        $t5, $t4, $s2
    ctx->r13 = ADD32(ctx->r12, ctx->r18);
    // 0x80042040: beq         $v1, $s3, L_80042094
    if (ctx->r3 == ctx->r19) {
        // 0x80042044: lw          $t6, 0x0($t5)
        ctx->r14 = MEM_W(ctx->r13, 0X0);
            goto L_80042094;
    }
    // 0x80042044: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
L_80042048:
    // 0x80042048: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
    // 0x8004204C: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80042050: lwc1        $f16, 0x68($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X68);
    // 0x80042054: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80042058: swc1        $f16, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f16.u32l;
    // 0x8004205C: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80042060: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x80042064: lw          $s0, 0x0($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X0);
    // 0x80042068: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x8004206C: addu        $t9, $s0, $v1
    ctx->r25 = ADD32(ctx->r16, ctx->r3);
    // 0x80042070: lwc1        $f16, 0x8($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X8);
    // 0x80042074: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x80042078: addu        $t2, $t1, $v1
    ctx->r10 = ADD32(ctx->r9, ctx->r3);
    // 0x8004207C: swc1        $f16, 0x40($t2)
    MEM_W(0X40, ctx->r10) = ctx->f16.u32l;
    // 0x80042080: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80042084: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80042088: addu        $t5, $t4, $s2
    ctx->r13 = ADD32(ctx->r12, ctx->r18);
    // 0x8004208C: bne         $v1, $s3, L_80042048
    if (ctx->r3 != ctx->r19) {
        // 0x80042090: lw          $t6, 0x0($t5)
        ctx->r14 = MEM_W(ctx->r13, 0X0);
            goto L_80042048;
    }
    // 0x80042090: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
L_80042094:
    // 0x80042094: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
    // 0x80042098: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8004209C: lwc1        $f16, 0x68($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X68);
    // 0x800420A0: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x800420A4: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800420A8: swc1        $f16, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f16.u32l;
    // 0x800420AC: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800420B0: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x800420B4: lw          $s0, 0x0($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X0);
    // 0x800420B8: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x800420BC: addu        $t9, $s0, $v1
    ctx->r25 = ADD32(ctx->r16, ctx->r3);
    // 0x800420C0: lwc1        $f16, 0x8($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X8);
    // 0x800420C4: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x800420C8: addu        $t2, $t1, $v1
    ctx->r10 = ADD32(ctx->r9, ctx->r3);
    // 0x800420CC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800420D0: swc1        $f16, 0x40($t2)
    MEM_W(0X40, ctx->r10) = ctx->f16.u32l;
    // 0x800420D4: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x800420D8: addu        $t4, $t3, $s2
    ctx->r12 = ADD32(ctx->r11, ctx->r18);
    // 0x800420DC: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x800420E0: jal         0x8000E074
    // 0x800420E4: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_8000E074(rdram, ctx);
        goto after_3;
    // 0x800420E4: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_3:
    // 0x800420E8: beql        $v0, $zero, L_8004215C
    if (ctx->r2 == 0) {
        // 0x800420EC: lw          $t7, 0x0($s1)
        ctx->r15 = MEM_W(ctx->r17, 0X0);
            goto L_8004215C;
    }
    goto skip_2;
    // 0x800420EC: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    skip_2:
    // 0x800420F0: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x800420F4: addu        $t6, $t5, $s2
    ctx->r14 = ADD32(ctx->r13, ctx->r18);
    // 0x800420F8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800420FC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80042100: lw          $v0, 0x8($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X8);
    // 0x80042104: lw          $t9, 0xD8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XD8);
    // 0x80042108: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x8004210C: sw          $t0, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r8;
    // 0x80042110: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80042114: addu        $t2, $t1, $s2
    ctx->r10 = ADD32(ctx->r9, ctx->r18);
    // 0x80042118: lw          $s0, 0x0($t2)
    ctx->r16 = MEM_W(ctx->r10, 0X0);
    // 0x8004211C: lh          $v1, 0x7C($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X7C);
    // 0x80042120: beq         $v1, $zero, L_80042130
    if (ctx->r3 == 0) {
        // 0x80042124: addiu       $t3, $v1, -0x1
        ctx->r11 = ADD32(ctx->r3, -0X1);
            goto L_80042130;
    }
    // 0x80042124: addiu       $t3, $v1, -0x1
    ctx->r11 = ADD32(ctx->r3, -0X1);
    // 0x80042128: b           L_80042178
    // 0x8004212C: sh          $t3, 0x7C($s0)
    MEM_H(0X7C, ctx->r16) = ctx->r11;
        goto L_80042178;
    // 0x8004212C: sh          $t3, 0x7C($s0)
    MEM_H(0X7C, ctx->r16) = ctx->r11;
L_80042130:
    // 0x80042130: lh          $t4, 0x7A($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X7A);
    // 0x80042134: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80042138: sh          $t4, 0x7C($s0)
    MEM_H(0X7C, ctx->r16) = ctx->r12;
    // 0x8004213C: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80042140: addu        $t6, $t5, $s2
    ctx->r14 = ADD32(ctx->r13, ctx->r18);
    // 0x80042144: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80042148: jal         0x80043EF0
    // 0x8004214C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_80043EF0(rdram, ctx);
        goto after_4;
    // 0x8004214C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_4:
    // 0x80042150: b           L_8004217C
    // 0x80042154: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
        goto L_8004217C;
    // 0x80042154: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80042158: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
L_8004215C:
    // 0x8004215C: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x80042160: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80042164: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80042168: lw          $v0, 0x8($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X8);
    // 0x8004216C: lw          $t1, 0xD8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XD8);
    // 0x80042170: and         $t2, $t1, $s4
    ctx->r10 = ctx->r9 & ctx->r20;
    // 0x80042174: sw          $t2, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r10;
L_80042178:
    // 0x80042178: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
L_8004217C:
    // 0x8004217C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80042180: addu        $t4, $t3, $s2
    ctx->r12 = ADD32(ctx->r11, ctx->r18);
    // 0x80042184: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    // 0x80042188: jal         0x8000D3A4
    // 0x8004218C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    func_8000D3A4(rdram, ctx);
        goto after_5;
    // 0x8004218C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_5:
    // 0x80042190: beql        $v0, $zero, L_800421E8
    if (ctx->r2 == 0) {
        // 0x80042194: lw          $t1, 0x0($s1)
        ctx->r9 = MEM_W(ctx->r17, 0X0);
            goto L_800421E8;
    }
    goto skip_3;
    // 0x80042194: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    skip_3:
    // 0x80042198: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x8004219C: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800421A0: addu        $t6, $t5, $s2
    ctx->r14 = ADD32(ctx->r13, ctx->r18);
    // 0x800421A4: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x800421A8: jal         0x80003668
    // 0x800421AC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_80003668(rdram, ctx);
        goto after_6;
    // 0x800421AC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_6:
    // 0x800421B0: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800421B4: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800421B8: nop

    // 0x800421BC: slti        $at, $t8, 0xC
    ctx->r1 = SIGNED(ctx->r24) < 0XC ? 1 : 0;
    // 0x800421C0: beql        $at, $zero, L_800421E8
    if (ctx->r1 == 0) {
        // 0x800421C4: lw          $t1, 0x0($s1)
        ctx->r9 = MEM_W(ctx->r17, 0X0);
            goto L_800421E8;
    }
    goto skip_4;
    // 0x800421C4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    skip_4:
    // 0x800421C8: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800421CC: addu        $t0, $t9, $s2
    ctx->r8 = ADD32(ctx->r25, ctx->r18);
    // 0x800421D0: lw          $s0, 0x0($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X0);
    // 0x800421D4: lwc1        $f10, 0x6C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x800421D8: div.s       $f16, $f10, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f26.fl);
    // 0x800421DC: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x800421E0: swc1        $f18, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f18.u32l;
    // 0x800421E4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
L_800421E8:
    // 0x800421E8: addu        $t2, $t1, $s2
    ctx->r10 = ADD32(ctx->r9, ctx->r18);
    // 0x800421EC: lw          $s0, 0x0($t2)
    ctx->r16 = MEM_W(ctx->r10, 0X0);
    // 0x800421F0: lh          $t3, 0x9A($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X9A);
    // 0x800421F4: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x800421F8: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x800421FC: bnel        $t4, $zero, L_80042230
    if (ctx->r12 != 0) {
        // 0x80042200: lw          $t9, 0x0($s1)
        ctx->r25 = MEM_W(ctx->r17, 0X0);
            goto L_80042230;
    }
    goto skip_5;
    // 0x80042200: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    skip_5:
    // 0x80042204: jal         0x8003E3F8
    // 0x80042208: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    func_8003E3F8(rdram, ctx);
        goto after_7;
    // 0x80042208: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_7:
    // 0x8004220C: beql        $v0, $zero, L_80042230
    if (ctx->r2 == 0) {
        // 0x80042210: lw          $t9, 0x0($s1)
        ctx->r25 = MEM_W(ctx->r17, 0X0);
            goto L_80042230;
    }
    goto skip_6;
    // 0x80042210: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    skip_6:
    // 0x80042214: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80042218: addu        $t6, $t5, $s2
    ctx->r14 = ADD32(ctx->r13, ctx->r18);
    // 0x8004221C: lw          $s0, 0x0($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X0);
    // 0x80042220: lh          $t7, 0x9A($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X9A);
    // 0x80042224: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80042228: sh          $t8, 0x9A($s0)
    MEM_H(0X9A, ctx->r16) = ctx->r24;
    // 0x8004222C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
L_80042230:
    // 0x80042230: addu        $t0, $t9, $s2
    ctx->r8 = ADD32(ctx->r25, ctx->r18);
    // 0x80042234: lw          $s0, 0x0($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X0);
    // 0x80042238: lh          $v0, 0x78($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X78);
    // 0x8004223C: blez        $v0, L_80042258
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80042240: addiu       $t1, $v0, -0x1
        ctx->r9 = ADD32(ctx->r2, -0X1);
            goto L_80042258;
    }
    // 0x80042240: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x80042244: sh          $t1, 0x78($s0)
    MEM_H(0X78, ctx->r16) = ctx->r9;
    // 0x80042248: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x8004224C: addu        $t3, $t2, $s2
    ctx->r11 = ADD32(ctx->r10, ctx->r18);
    // 0x80042250: lw          $s0, 0x0($t3)
    ctx->r16 = MEM_W(ctx->r11, 0X0);
    // 0x80042254: lh          $v0, 0x78($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X78);
L_80042258:
    // 0x80042258: bgtzl       $v0, L_8004229C
    if (SIGNED(ctx->r2) > 0) {
        // 0x8004225C: lh          $t3, 0x6($s1)
        ctx->r11 = MEM_H(ctx->r17, 0X6);
            goto L_8004229C;
    }
    goto skip_7;
    // 0x8004225C: lh          $t3, 0x6($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X6);
    skip_7:
    // 0x80042260: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x80042264: lw          $v0, 0x8($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X8);
    // 0x80042268: lw          $t5, 0xD8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XD8);
    // 0x8004226C: and         $t6, $t5, $s4
    ctx->r14 = ctx->r13 & ctx->r20;
    // 0x80042270: sw          $t6, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r14;
    // 0x80042274: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80042278: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x8004227C: lw          $s0, 0x0($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X0);
    // 0x80042280: lh          $t9, 0x84($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X84);
    // 0x80042284: and         $t0, $t9, $s4
    ctx->r8 = ctx->r25 & ctx->r20;
    // 0x80042288: sh          $t0, 0x84($s0)
    MEM_H(0X84, ctx->r16) = ctx->r8;
    // 0x8004228C: lh          $t1, 0x4($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X4);
    // 0x80042290: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80042294: sh          $t2, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r10;
    // 0x80042298: lh          $t3, 0x6($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X6);
L_8004229C:
    // 0x8004229C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800422A0: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800422A4: slt         $at, $s5, $t3
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800422A8: bnel        $at, $zero, L_80041F80
    if (ctx->r1 != 0) {
        // 0x800422AC: lw          $t8, 0x0($s1)
        ctx->r24 = MEM_W(ctx->r17, 0X0);
            goto L_80041F80;
    }
    goto skip_8;
    // 0x800422AC: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    skip_8:
L_800422B0:
    // 0x800422B0: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_800422B4:
    // 0x800422B4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800422B8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800422BC: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x800422C0: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x800422C4: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x800422C8: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x800422CC: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x800422D0: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x800422D4: lw          $s4, 0x4C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X4C);
    // 0x800422D8: lw          $s5, 0x50($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X50);
    // 0x800422DC: lw          $s6, 0x54($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X54);
    // 0x800422E0: lw          $s7, 0x58($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X58);
    // 0x800422E4: jr          $ra
    // 0x800422E8: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    TRACE_RETURN()
    return;
    // 0x800422E8: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void func_800422EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800422EC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800422F0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800422F4: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800422F8: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800422FC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80042300: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80042304: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80042308: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8004230C: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x80042310: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80042314: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80042318: blez        $t6, L_8004237C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8004231C: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8004237C;
    }
    // 0x8004231C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80042320: lui         $s5, 0x801A
    ctx->r21 = S32(0X801A << 16);
    // 0x80042324: addiu       $s5, $s5, 0x2800
    ctx->r21 = ADD32(ctx->r21, 0X2800);
    // 0x80042328: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // 0x8004232C: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
L_80042330:
    // 0x80042330: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x80042334: lw          $s0, 0x0($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X0);
    // 0x80042338: lh          $t9, 0x76($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X76);
    // 0x8004233C: beql        $s4, $t9, L_8004235C
    if (ctx->r20 == ctx->r25) {
        // 0x80042340: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_8004235C;
    }
    goto skip_0;
    // 0x80042340: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_0:
    // 0x80042344: jal         0x8004A0C4
    // 0x80042348: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    func_8004A0C4(rdram, ctx);
        goto after_0;
    // 0x80042348: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_0:
    // 0x8004234C: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x80042350: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x80042354: lw          $s0, 0x0($t1)
    ctx->r16 = MEM_W(ctx->r9, 0X0);
    // 0x80042358: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_8004235C:
    // 0x8004235C: jal         0x800042A8
    // 0x80042360: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800042A8(rdram, ctx);
        goto after_1;
    // 0x80042360: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80042364: lh          $t2, 0x6($s3)
    ctx->r10 = MEM_H(ctx->r19, 0X6);
    // 0x80042368: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8004236C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80042370: slt         $at, $s2, $t2
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80042374: bnel        $at, $zero, L_80042330
    if (ctx->r1 != 0) {
        // 0x80042378: lw          $t7, 0x0($s3)
        ctx->r15 = MEM_W(ctx->r19, 0X0);
            goto L_80042330;
    }
    goto skip_1;
    // 0x80042378: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    skip_1:
L_8004237C:
    // 0x8004237C: lui         $s5, 0x801A
    ctx->r21 = S32(0X801A << 16);
    // 0x80042380: addiu       $s5, $s5, 0x2800
    ctx->r21 = ADD32(ctx->r21, 0X2800);
    // 0x80042384: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80042388: jal         0x800042A8
    // 0x8004238C: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    func_800042A8(rdram, ctx);
        goto after_2;
    // 0x8004238C: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    after_2:
    // 0x80042390: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80042394: jal         0x800042A8
    // 0x80042398: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800042A8(rdram, ctx);
        goto after_3;
    // 0x80042398: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_3:
    // 0x8004239C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800423A0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800423A4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800423A8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800423AC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800423B0: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800423B4: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800423B8: jr          $ra
    // 0x800423BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    TRACE_RETURN()
    return;
    // 0x800423BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800423C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800423C0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800423C4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800423C8: lw          $t6, -0x6610($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6610);
    // 0x800423CC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800423D0: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800423D4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800423D8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800423DC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800423E0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800423E4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800423E8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800423EC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800423F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800423F4: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x800423F8: lw          $s1, 0x0($t6)
    ctx->r17 = MEM_W(ctx->r14, 0X0);
    // 0x800423FC: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80042400: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x80042404: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80042408: addiu       $s3, $sp, 0x64
    ctx->r19 = ADD32(ctx->r29, 0X64);
    // 0x8004240C: addiu       $s5, $sp, 0x58
    ctx->r21 = ADD32(ctx->r29, 0X58);
    // 0x80042410: beq         $v0, $zero, L_80042580
    if (ctx->r2 == 0) {
        // 0x80042414: addiu       $fp, $zero, 0x7FFF
        ctx->r30 = ADD32(0, 0X7FFF);
            goto L_80042580;
    }
    // 0x80042414: addiu       $fp, $zero, 0x7FFF
    ctx->r30 = ADD32(0, 0X7FFF);
    // 0x80042418: addiu       $s2, $zero, 0x6
    ctx->r18 = ADD32(0, 0X6);
    // 0x8004241C: lh          $t7, 0x2E($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X2E);
L_80042420:
    // 0x80042420: blezl       $t7, L_80042574
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80042424: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80042574;
    }
    goto skip_0;
    // 0x80042424: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    skip_0:
    // 0x80042428: lh          $v1, 0x2C($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X2C);
    // 0x8004242C: beql        $v1, $zero, L_80042574
    if (ctx->r3 == 0) {
        // 0x80042430: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80042574;
    }
    goto skip_1;
    // 0x80042430: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    skip_1:
    // 0x80042434: blez        $v1, L_80042570
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80042438: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80042570;
    }
    // 0x80042438: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8004243C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80042440: lw          $v0, 0x28($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X28);
L_80042444:
    // 0x80042444: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x80042448: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8004244C: addiu       $v0, $sp, 0x58
    ctx->r2 = ADD32(ctx->r29, 0X58);
    // 0x80042450: bne         $t8, $zero, L_800424F0
    if (ctx->r24 != 0) {
        // 0x80042454: or          $v1, $s1, $zero
        ctx->r3 = ctx->r17 | 0;
            goto L_800424F0;
    }
    // 0x80042454: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x80042458: addiu       $v0, $sp, 0x58
    ctx->r2 = ADD32(ctx->r29, 0X58);
    // 0x8004245C: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x80042460: lw          $t9, 0x28($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X28);
    // 0x80042464: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x80042468: subu        $t0, $t0, $s0
    ctx->r8 = SUB32(ctx->r8, ctx->r16);
    // 0x8004246C: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80042470: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80042474: addiu       $s2, $s2, -0x2
    ctx->r18 = ADD32(ctx->r18, -0X2);
    // 0x80042478: addu        $t2, $t1, $a0
    ctx->r10 = ADD32(ctx->r9, ctx->r4);
    // 0x8004247C: beq         $a0, $s2, L_800424C4
    if (ctx->r4 == ctx->r18) {
        // 0x80042480: lh          $t3, 0x2($t2)
        ctx->r11 = MEM_H(ctx->r10, 0X2);
            goto L_800424C4;
    }
    // 0x80042480: lh          $t3, 0x2($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X2);
L_80042484:
    // 0x80042484: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80042488: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8004248C: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x80042490: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80042494: subu        $t0, $t0, $s0
    ctx->r8 = SUB32(ctx->r8, ctx->r16);
    // 0x80042498: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8004249C: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800424A0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800424A4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800424A8: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800424AC: swc1        $f16, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
    // 0x800424B0: lw          $t9, 0x28($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X28);
    // 0x800424B4: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800424B8: addu        $t2, $t1, $a0
    ctx->r10 = ADD32(ctx->r9, ctx->r4);
    // 0x800424BC: bne         $a0, $s2, L_80042484
    if (ctx->r4 != ctx->r18) {
        // 0x800424C0: lh          $t3, 0x2($t2)
        ctx->r11 = MEM_H(ctx->r10, 0X2);
            goto L_80042484;
    }
    // 0x800424C0: lh          $t3, 0x2($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X2);
L_800424C4:
    // 0x800424C4: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x800424C8: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800424CC: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x800424D0: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800424D4: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800424D8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800424DC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800424E0: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800424E4: swc1        $f16, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
    // 0x800424E8: b           L_80042508
    // 0x800424EC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80042508;
    // 0x800424EC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800424F0:
    // 0x800424F0: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800424F4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800424F8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800424FC: bne         $v0, $s3, L_800424F0
    if (ctx->r2 != ctx->r19) {
        // 0x80042500: swc1        $f16, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
            goto L_800424F0;
    }
    // 0x80042500: swc1        $f16, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
    // 0x80042504: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80042508:
    // 0x80042508: jal         0x80003668
    // 0x8004250C: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_80003668(rdram, ctx);
        goto after_0;
    // 0x8004250C: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_0:
    // 0x80042510: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80042514: lw          $t4, 0x28($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X28);
    // 0x80042518: addu        $v0, $t4, $s4
    ctx->r2 = ADD32(ctx->r12, ctx->r20);
    // 0x8004251C: lh          $t7, 0x14($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X14);
    // 0x80042520: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x80042524: nop

    // 0x80042528: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8004252C: beql        $at, $zero, L_80042558
    if (ctx->r1 == 0) {
        // 0x80042530: lh          $t0, 0x2C($s1)
        ctx->r8 = MEM_H(ctx->r17, 0X2C);
            goto L_80042558;
    }
    goto skip_2;
    // 0x80042530: lh          $t0, 0x2C($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X2C);
    skip_2:
    // 0x80042534: lh          $v0, 0x2E($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X2E);
    // 0x80042538: lh          $t8, 0x76($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X76);
    // 0x8004253C: beq         $fp, $v0, L_80042548
    if (ctx->r30 == ctx->r2) {
        // 0x80042540: subu        $t9, $v0, $t8
        ctx->r25 = SUB32(ctx->r2, ctx->r24);
            goto L_80042548;
    }
    // 0x80042540: subu        $t9, $v0, $t8
    ctx->r25 = SUB32(ctx->r2, ctx->r24);
    // 0x80042544: sh          $t9, 0x2E($s1)
    MEM_H(0X2E, ctx->r17) = ctx->r25;
L_80042548:
    // 0x80042548: lh          $s7, 0x34($s1)
    ctx->r23 = MEM_H(ctx->r17, 0X34);
    // 0x8004254C: b           L_80042570
    // 0x80042550: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
        goto L_80042570;
    // 0x80042550: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80042554: lh          $t0, 0x2C($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X2C);
L_80042558:
    // 0x80042558: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8004255C: addiu       $s4, $s4, 0x18
    ctx->r20 = ADD32(ctx->r20, 0X18);
    // 0x80042560: slt         $at, $s0, $t0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80042564: bne         $at, $zero, L_80042444
    if (ctx->r1 != 0) {
        // 0x80042568: addiu       $v0, $v0, 0x18
        ctx->r2 = ADD32(ctx->r2, 0X18);
            goto L_80042444;
    }
    // 0x80042568: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x8004256C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_80042570:
    // 0x80042570: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_80042574:
    // 0x80042574: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80042578: bnel        $v0, $zero, L_80042420
    if (ctx->r2 != 0) {
        // 0x8004257C: lh          $t7, 0x2E($s1)
        ctx->r15 = MEM_H(ctx->r17, 0X2E);
            goto L_80042420;
    }
    goto skip_3;
    // 0x8004257C: lh          $t7, 0x2E($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X2E);
    skip_3:
L_80042580:
    // 0x80042580: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80042584: or          $v0, $s7, $zero
    ctx->r2 = ctx->r23 | 0;
    // 0x80042588: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8004258C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80042590: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80042594: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80042598: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8004259C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800425A0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800425A4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800425A8: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800425AC: jr          $ra
    // 0x800425B0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    TRACE_RETURN()
    return;
    // 0x800425B0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_800425B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800425B4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800425B8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800425BC: lw          $t7, -0x6610($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6610);
    // 0x800425C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800425C4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800425C8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800425CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800425D0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800425D4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800425D8: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800425DC: lw          $s0, 0x0($t7)
    ctx->r16 = MEM_W(ctx->r15, 0X0);
    // 0x800425E0: sll         $s2, $a1, 16
    ctx->r18 = S32(ctx->r5 << 16);
    // 0x800425E4: sra         $t6, $s2, 16
    ctx->r14 = S32(SIGNED(ctx->r18) >> 16);
    // 0x800425E8: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800425EC: or          $s2, $t6, $zero
    ctx->r18 = ctx->r14 | 0;
    // 0x800425F0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800425F4: beql        $t8, $zero, L_80042664
    if (ctx->r24 == 0) {
        // 0x800425F8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80042664;
    }
    goto skip_0;
    // 0x800425F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800425FC: lh          $t9, 0x2E($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X2E);
L_80042600:
    // 0x80042600: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80042604: blezl       $t9, L_80042654
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80042608: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80042654;
    }
    goto skip_1;
    // 0x80042608: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x8004260C: jal         0x80003668
    // 0x80042610: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80003668(rdram, ctx);
        goto after_0;
    // 0x80042610: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x80042614: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80042618: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x8004261C: nop

    // 0x80042620: slt         $at, $t1, $s2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80042624: beql        $at, $zero, L_80042654
    if (ctx->r1 == 0) {
        // 0x80042628: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80042654;
    }
    goto skip_2;
    // 0x80042628: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x8004262C: lh          $v0, 0x2E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2E);
    // 0x80042630: lh          $t2, 0x3A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X3A);
    // 0x80042634: addiu       $at, $zero, 0x7FFF
    ctx->r1 = ADD32(0, 0X7FFF);
    // 0x80042638: beq         $v0, $at, L_80042644
    if (ctx->r2 == ctx->r1) {
        // 0x8004263C: subu        $t3, $v0, $t2
        ctx->r11 = SUB32(ctx->r2, ctx->r10);
            goto L_80042644;
    }
    // 0x8004263C: subu        $t3, $v0, $t2
    ctx->r11 = SUB32(ctx->r2, ctx->r10);
    // 0x80042640: sh          $t3, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r11;
L_80042644:
    // 0x80042644: lh          $t4, 0x34($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X34);
    // 0x80042648: b           L_80042660
    // 0x8004264C: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
        goto L_80042660;
    // 0x8004264C: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x80042650: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_80042654:
    // 0x80042654: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80042658: bnel        $t5, $zero, L_80042600
    if (ctx->r13 != 0) {
        // 0x8004265C: lh          $t9, 0x2E($s0)
        ctx->r25 = MEM_H(ctx->r16, 0X2E);
            goto L_80042600;
    }
    goto skip_3;
    // 0x8004265C: lh          $t9, 0x2E($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X2E);
    skip_3:
L_80042660:
    // 0x80042660: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80042664:
    // 0x80042664: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80042668: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004266C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80042670: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80042674: jr          $ra
    // 0x80042678: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    TRACE_RETURN()
    return;
    // 0x80042678: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
