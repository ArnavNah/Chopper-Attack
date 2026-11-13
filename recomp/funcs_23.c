#include "recomp.h"
#include "trace.h"
#include "funcs.h"

RECOMP_FUNC void func_80050E6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80050E6C: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x80050E70: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80050E74: lbu         $s6, 0x8($t0)
    ctx->r22 = MEM_BU(ctx->r8, 0X8);
    // 0x80050E78: lbu         $s4, 0x9($t0)
    ctx->r20 = MEM_BU(ctx->r8, 0X9);
    // 0x80050E7C: lbu         $s1, 0xA($t0)
    ctx->r17 = MEM_BU(ctx->r8, 0XA);
    // 0x80050E80: andi        $v1, $s6, 0xF0
    ctx->r3 = ctx->r22 & 0XF0;
    // 0x80050E84: addiu       $t7, $v1, -0x80
    ctx->r15 = ADD32(ctx->r3, -0X80);
    // 0x80050E88: sltiu       $at, $t7, 0x61
    ctx->r1 = ctx->r15 < 0X61 ? 1 : 0;
    // 0x80050E8C: andi        $t6, $s6, 0xF
    ctx->r14 = ctx->r22 & 0XF;
    // 0x80050E90: beq         $at, $zero, L_80051684
    if (ctx->r1 == 0) {
        // 0x80050E94: or          $s6, $t6, $zero
        ctx->r22 = ctx->r14 | 0;
            goto L_80051684;
    }
    // 0x80050E94: or          $s6, $t6, $zero
    ctx->r22 = ctx->r14 | 0;
    // 0x80050E98: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80050E9C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80050EA0: addu        $at, $at, $t7
    gpr jr_addend_80050EA8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80050EA4: lw          $t7, -0x6EF0($at)
    ctx->r15 = ADD32(ctx->r1, -0X6EF0);
    // 0x80050EA8: jr          $t7
    // 0x80050EAC: nop

    switch (jr_addend_80050EA8 >> 2) {
        case 0: goto L_80051250; break;
        case 1: goto L_80051684; break;
        case 2: goto L_80051684; break;
        case 3: goto L_80051684; break;
        case 4: goto L_80051684; break;
        case 5: goto L_80051684; break;
        case 6: goto L_80051684; break;
        case 7: goto L_80051684; break;
        case 8: goto L_80051684; break;
        case 9: goto L_80051684; break;
        case 10: goto L_80051684; break;
        case 11: goto L_80051684; break;
        case 12: goto L_80051684; break;
        case 13: goto L_80051684; break;
        case 14: goto L_80051684; break;
        case 15: goto L_80051684; break;
        case 16: goto L_80050EB0; break;
        case 17: goto L_80051684; break;
        case 18: goto L_80051684; break;
        case 19: goto L_80051684; break;
        case 20: goto L_80051684; break;
        case 21: goto L_80051684; break;
        case 22: goto L_80051684; break;
        case 23: goto L_80051684; break;
        case 24: goto L_80051684; break;
        case 25: goto L_80051684; break;
        case 26: goto L_80051684; break;
        case 27: goto L_80051684; break;
        case 28: goto L_80051684; break;
        case 29: goto L_80051684; break;
        case 30: goto L_80051684; break;
        case 31: goto L_80051684; break;
        case 32: goto L_800512A8; break;
        case 33: goto L_80051684; break;
        case 34: goto L_80051684; break;
        case 35: goto L_80051684; break;
        case 36: goto L_80051684; break;
        case 37: goto L_80051684; break;
        case 38: goto L_80051684; break;
        case 39: goto L_80051684; break;
        case 40: goto L_80051684; break;
        case 41: goto L_80051684; break;
        case 42: goto L_80051684; break;
        case 43: goto L_80051684; break;
        case 44: goto L_80051684; break;
        case 45: goto L_80051684; break;
        case 46: goto L_80051684; break;
        case 47: goto L_80051684; break;
        case 48: goto L_80051380; break;
        case 49: goto L_80051684; break;
        case 50: goto L_80051684; break;
        case 51: goto L_80051684; break;
        case 52: goto L_80051684; break;
        case 53: goto L_80051684; break;
        case 54: goto L_80051684; break;
        case 55: goto L_80051684; break;
        case 56: goto L_80051684; break;
        case 57: goto L_80051684; break;
        case 58: goto L_80051684; break;
        case 59: goto L_80051684; break;
        case 60: goto L_80051684; break;
        case 61: goto L_80051684; break;
        case 62: goto L_80051684; break;
        case 63: goto L_80051684; break;
        case 64: goto L_800515B8; break;
        case 65: goto L_80051684; break;
        case 66: goto L_80051684; break;
        case 67: goto L_80051684; break;
        case 68: goto L_80051684; break;
        case 69: goto L_80051684; break;
        case 70: goto L_80051684; break;
        case 71: goto L_80051684; break;
        case 72: goto L_80051684; break;
        case 73: goto L_80051684; break;
        case 74: goto L_80051684; break;
        case 75: goto L_80051684; break;
        case 76: goto L_80051684; break;
        case 77: goto L_80051684; break;
        case 78: goto L_80051684; break;
        case 79: goto L_80051684; break;
        case 80: goto L_8005130C; break;
        case 81: goto L_80051684; break;
        case 82: goto L_80051684; break;
        case 83: goto L_80051684; break;
        case 84: goto L_80051684; break;
        case 85: goto L_80051684; break;
        case 86: goto L_80051684; break;
        case 87: goto L_80051684; break;
        case 88: goto L_80051684; break;
        case 89: goto L_80051684; break;
        case 90: goto L_80051684; break;
        case 91: goto L_80051684; break;
        case 92: goto L_80051684; break;
        case 93: goto L_80051684; break;
        case 94: goto L_80051684; break;
        case 95: goto L_80051684; break;
        case 96: goto L_800515EC; break;
        default: switch_error(__func__, 0x80050EA8, 0x80079110);
    }
    // 0x80050EAC: nop

L_80050EB0:
    // 0x80050EB0: beql        $s1, $zero, L_80051254
    if (ctx->r17 == 0) {
        // 0x80050EB4: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80051254;
    }
    goto skip_0;
    // 0x80050EB4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x80050EB8: lw          $t8, 0x2C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X2C);
    // 0x80050EBC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80050EC0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80050EC4: bne         $t8, $at, L_80051684
    if (ctx->r24 != ctx->r1) {
        // 0x80050EC8: andi        $a1, $s4, 0xFF
        ctx->r5 = ctx->r20 & 0XFF;
            goto L_80051684;
    }
    // 0x80050EC8: andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    // 0x80050ECC: andi        $a2, $s1, 0xFF
    ctx->r6 = ctx->r17 & 0XFF;
    // 0x80050ED0: andi        $a3, $s6, 0xFF
    ctx->r7 = ctx->r22 & 0XFF;
    // 0x80050ED4: jal         0x80057950
    // 0x80050ED8: sw          $t0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r8;
    func_80057950(rdram, ctx);
        goto after_0;
    // 0x80050ED8: sw          $t0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r8;
    after_0:
    // 0x80050EDC: beq         $v0, $zero, L_80051684
    if (ctx->r2 == 0) {
        // 0x80050EE0: or          $s7, $v0, $zero
        ctx->r23 = ctx->r2 | 0;
            goto L_80051684;
    }
    // 0x80050EE0: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x80050EE4: lw          $t9, 0x60($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X60);
    // 0x80050EE8: sll         $fp, $s6, 4
    ctx->r30 = S32(ctx->r22 << 4);
    // 0x80050EEC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80050EF0: addu        $t6, $t9, $fp
    ctx->r14 = ADD32(ctx->r25, ctx->r30);
    // 0x80050EF4: lbu         $t7, 0x8($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X8);
    // 0x80050EF8: sh          $zero, 0x76($sp)
    MEM_H(0X76, ctx->r29) = 0;
    // 0x80050EFC: sb          $zero, 0x78($sp)
    MEM_B(0X78, ctx->r29) = 0;
    // 0x80050F00: andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    // 0x80050F04: andi        $a2, $s1, 0xFF
    ctx->r6 = ctx->r17 & 0XFF;
    // 0x80050F08: andi        $a3, $s6, 0xFF
    ctx->r7 = ctx->r22 & 0XFF;
    // 0x80050F0C: jal         0x800578E0
    // 0x80050F10: sh          $t7, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r15;
    func_800578E0(rdram, ctx);
        goto after_1;
    // 0x80050F10: sh          $t7, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r15;
    after_1:
    // 0x80050F14: beq         $v0, $zero, L_80051684
    if (ctx->r2 == 0) {
        // 0x80050F18: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80051684;
    }
    // 0x80050F18: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80050F1C: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80050F20: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x80050F24: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // 0x80050F28: jal         0x80058F28
    // 0x80050F2C: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    func_80058F28(rdram, ctx);
        goto after_2;
    // 0x80050F2C: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    after_2:
    // 0x80050F30: sw          $s7, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r23;
    // 0x80050F34: sb          $zero, 0x34($s0)
    MEM_B(0X34, ctx->r16) = 0;
    // 0x80050F38: lw          $t8, 0x60($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X60);
    // 0x80050F3C: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x80050F40: addu        $t9, $t8, $fp
    ctx->r25 = ADD32(ctx->r24, ctx->r30);
    // 0x80050F44: lbu         $t6, 0xB($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0XB);
    // 0x80050F48: slti        $at, $t6, 0x40
    ctx->r1 = SIGNED(ctx->r14) < 0X40 ? 1 : 0;
    // 0x80050F4C: bnel        $at, $zero, L_80050F60
    if (ctx->r1 != 0) {
        // 0x80050F50: sb          $zero, 0x35($s0)
        MEM_B(0X35, ctx->r16) = 0;
            goto L_80050F60;
    }
    goto skip_1;
    // 0x80050F50: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
    skip_1:
    // 0x80050F54: b           L_80050F60
    // 0x80050F58: sb          $s5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r21;
        goto L_80050F60;
    // 0x80050F58: sb          $s5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r21;
    // 0x80050F5C: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
L_80050F60:
    // 0x80050F60: lw          $v0, 0x4($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X4);
    // 0x80050F64: lbu         $t7, 0x4($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4);
    // 0x80050F68: lb          $t6, 0x5($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X5);
    // 0x80050F6C: subu        $t8, $s4, $t7
    ctx->r24 = SUB32(ctx->r20, ctx->r15);
    // 0x80050F70: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80050F74: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80050F78: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80050F7C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80050F80: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80050F84: addu        $a0, $t9, $t6
    ctx->r4 = ADD32(ctx->r25, ctx->r14);
    // 0x80050F88: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x80050F8C: jal         0x80053FD0
    // 0x80050F90: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    func_80053FD0(rdram, ctx);
        goto after_3;
    // 0x80050F90: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    after_3:
    // 0x80050F94: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x80050F98: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x80050F9C: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80050FA0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80050FA4: lbu         $t6, 0xC($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0XC);
    // 0x80050FA8: sb          $t6, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r14;
    // 0x80050FAC: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x80050FB0: lw          $t7, 0x1C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X1C);
    // 0x80050FB4: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80050FB8: sb          $zero, 0x37($s0)
    MEM_B(0X37, ctx->r16) = 0;
    // 0x80050FBC: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x80050FC0: sw          $t6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r14;
    // 0x80050FC4: lw          $t8, 0x60($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X60);
    // 0x80050FC8: addu        $t7, $t8, $fp
    ctx->r15 = ADD32(ctx->r24, ctx->r30);
    // 0x80050FCC: lw          $s1, 0x0($t7)
    ctx->r17 = MEM_W(ctx->r15, 0X0);
    // 0x80050FD0: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    // 0x80050FD4: lbu         $a2, 0x4($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X4);
    // 0x80050FD8: beql        $a2, $zero, L_80051044
    if (ctx->r6 == 0) {
        // 0x80050FDC: cfc1        $t8, $FpcCsr
        ctx->r24 = get_cop1_cs();
            goto L_80051044;
    }
    goto skip_2;
    // 0x80050FDC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    skip_2:
    // 0x80050FE0: lw          $v0, 0x70($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X70);
    // 0x80050FE4: beql        $v0, $zero, L_80051044
    if (ctx->r2 == 0) {
        // 0x80050FE8: cfc1        $t8, $FpcCsr
        ctx->r24 = get_cop1_cs();
            goto L_80051044;
    }
    goto skip_3;
    // 0x80050FE8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    skip_3:
    // 0x80050FEC: lbu         $t9, 0x6($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X6);
    // 0x80050FF0: lbu         $a3, 0x5($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X5);
    // 0x80050FF4: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x80050FF8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80050FFC: lbu         $t6, 0x7($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X7);
    // 0x80051000: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x80051004: jalr        $v0
    // 0x80051008: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_4;
    // 0x80051008: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_4:
    // 0x8005100C: beq         $v0, $zero, L_80051040
    if (ctx->r2 == 0) {
        // 0x80051010: addiu       $t8, $zero, 0x16
        ctx->r24 = ADD32(0, 0X16);
            goto L_80051040;
    }
    // 0x80051010: addiu       $t8, $zero, 0x16
    ctx->r24 = ADD32(0, 0X16);
    // 0x80051014: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x80051018: sh          $t8, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r24;
    // 0x8005101C: sw          $s0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r16;
    // 0x80051020: addiu       $a0, $s2, 0x48
    ctx->r4 = ADD32(ctx->r18, 0X48);
    // 0x80051024: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x80051028: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8005102C: jal         0x8005702C
    // 0x80051030: sw          $t7, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r15;
    func_8005702C(rdram, ctx);
        goto after_5;
    // 0x80051030: sw          $t7, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r15;
    after_5:
    // 0x80051034: lbu         $t9, 0x37($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X37);
    // 0x80051038: ori         $t6, $t9, 0x1
    ctx->r14 = ctx->r25 | 0X1;
    // 0x8005103C: sb          $t6, 0x37($s0)
    MEM_B(0X37, ctx->r16) = ctx->r14;
L_80051040:
    // 0x80051040: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
L_80051044:
    // 0x80051044: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80051048: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8005104C: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80051050: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80051054: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80051058: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8005105C: nop

    // 0x80051060: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80051064: beql        $t7, $zero, L_800510B4
    if (ctx->r15 == 0) {
        // 0x80051068: mfc1        $t7, $f8
        ctx->r15 = (int32_t)ctx->f8.u32l;
            goto L_800510B4;
    }
    goto skip_4;
    // 0x80051068: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    skip_4:
    // 0x8005106C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80051070: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80051074: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80051078: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8005107C: nop

    // 0x80051080: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80051084: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80051088: nop

    // 0x8005108C: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80051090: bne         $t7, $zero, L_800510A8
    if (ctx->r15 != 0) {
        // 0x80051094: nop
    
            goto L_800510A8;
    }
    // 0x80051094: nop

    // 0x80051098: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x8005109C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800510A0: b           L_800510C0
    // 0x800510A4: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_800510C0;
    // 0x800510A4: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_800510A8:
    // 0x800510A8: b           L_800510C0
    // 0x800510AC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_800510C0;
    // 0x800510AC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800510B0: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
L_800510B4:
    // 0x800510B4: nop

    // 0x800510B8: bltz        $t7, L_800510A8
    if (SIGNED(ctx->r15) < 0) {
        // 0x800510BC: nop
    
            goto L_800510A8;
    }
    // 0x800510BC: nop

L_800510C0:
    // 0x800510C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800510C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800510C8: sb          $t7, 0x36($s0)
    MEM_B(0X36, ctx->r16) = ctx->r15;
    // 0x800510CC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800510D0: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    // 0x800510D4: lbu         $a2, 0x8($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X8);
    // 0x800510D8: addiu       $s5, $s2, 0x48
    ctx->r21 = ADD32(ctx->r18, 0X48);
    // 0x800510DC: beql        $a2, $zero, L_8005114C
    if (ctx->r6 == 0) {
        // 0x800510E0: lwc1        $f4, 0x64($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
            goto L_8005114C;
    }
    goto skip_5;
    // 0x800510E0: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    skip_5:
    // 0x800510E4: lw          $v0, 0x70($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X70);
    // 0x800510E8: beql        $v0, $zero, L_8005114C
    if (ctx->r2 == 0) {
        // 0x800510EC: lwc1        $f4, 0x64($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
            goto L_8005114C;
    }
    goto skip_6;
    // 0x800510EC: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    skip_6:
    // 0x800510F0: lbu         $t9, 0xA($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0XA);
    // 0x800510F4: lbu         $a3, 0x9($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X9);
    // 0x800510F8: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x800510FC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80051100: lbu         $t6, 0xB($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0XB);
    // 0x80051104: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x80051108: jalr        $v0
    // 0x8005110C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_6;
    // 0x8005110C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_6:
    // 0x80051110: beq         $v0, $zero, L_80051148
    if (ctx->r2 == 0) {
        // 0x80051114: addiu       $t8, $zero, 0x17
        ctx->r24 = ADD32(0, 0X17);
            goto L_80051148;
    }
    // 0x80051114: addiu       $t8, $zero, 0x17
    ctx->r24 = ADD32(0, 0X17);
    // 0x80051118: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x8005111C: sh          $t8, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r24;
    // 0x80051120: sw          $s0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r16;
    // 0x80051124: sb          $s6, 0x98($sp)
    MEM_B(0X98, ctx->r29) = ctx->r22;
    // 0x80051128: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8005112C: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x80051130: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80051134: jal         0x8005702C
    // 0x80051138: sw          $t7, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r15;
    func_8005702C(rdram, ctx);
        goto after_7;
    // 0x80051138: sw          $t7, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r15;
    after_7:
    // 0x8005113C: lbu         $t9, 0x37($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X37);
    // 0x80051140: ori         $t6, $t9, 0x2
    ctx->r14 = ctx->r25 | 0X2;
    // 0x80051144: sb          $t6, 0x37($s0)
    MEM_B(0X37, ctx->r16) = ctx->r14;
L_80051148:
    // 0x80051148: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
L_8005114C:
    // 0x8005114C: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80051150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80051154: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    // 0x80051158: lw          $t8, 0x60($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X60);
    // 0x8005115C: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80051160: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80051164: addu        $v0, $t8, $fp
    ctx->r2 = ADD32(ctx->r24, ctx->r30);
    // 0x80051168: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8005116C: lbu         $s1, 0xA($v0)
    ctx->r17 = MEM_BU(ctx->r2, 0XA);
    // 0x80051170: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80051174: nop

    // 0x80051178: mul.s       $f20, $f10, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8005117C: jal         0x80057824
    // 0x80051180: nop

    func_80057824(rdram, ctx);
        goto after_8;
    // 0x80051180: nop

    after_8:
    // 0x80051184: andi        $fp, $v0, 0xFF
    ctx->r30 = ctx->r2 & 0XFF;
    // 0x80051188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005118C: jal         0x80057404
    // 0x80051190: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80057404(rdram, ctx);
        goto after_9;
    // 0x80051190: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_9:
    // 0x80051194: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x80051198: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x8005119C: lw          $a2, 0x8($s7)
    ctx->r6 = MEM_W(ctx->r23, 0X8);
    // 0x800511A0: lw          $s3, 0x0($t7)
    ctx->r19 = MEM_W(ctx->r15, 0X0);
    // 0x800511A4: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800511A8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800511AC: sw          $fp, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r30;
    // 0x800511B0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800511B4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800511B8: jal         0x80059070
    // 0x800511BC: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    func_80059070(rdram, ctx);
        goto after_10;
    // 0x800511BC: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    after_10:
    // 0x800511C0: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800511C4: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x800511C8: sh          $t9, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r25;
    // 0x800511CC: sw          $t6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r14;
    // 0x800511D0: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x800511D4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800511D8: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x800511DC: lbu         $t7, 0xD($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0XD);
    // 0x800511E0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800511E4: sb          $t7, 0x98($sp)
    MEM_B(0X98, ctx->r29) = ctx->r15;
    // 0x800511E8: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x800511EC: lw          $t6, 0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X4);
    // 0x800511F0: jal         0x8005702C
    // 0x800511F4: sw          $t6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r14;
    func_8005702C(rdram, ctx);
        goto after_11;
    // 0x800511F4: sw          $t6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r14;
    after_11:
    // 0x800511F8: lw          $v0, 0xBC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XBC);
    // 0x800511FC: addiu       $t7, $zero, 0x15
    ctx->r15 = ADD32(0, 0X15);
    // 0x80051200: ori         $t9, $s6, 0x80
    ctx->r25 = ctx->r22 | 0X80;
    // 0x80051204: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x80051208: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8005120C: beql        $t8, $zero, L_80051688
    if (ctx->r24 == 0) {
        // 0x80051210: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80051688;
    }
    goto skip_7;
    // 0x80051210: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_7:
    // 0x80051214: sh          $t7, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r15;
    // 0x80051218: sb          $t9, 0x94($sp)
    MEM_B(0X94, ctx->r29) = ctx->r25;
    // 0x8005121C: sb          $s4, 0x95($sp)
    MEM_B(0X95, ctx->r29) = ctx->r20;
    // 0x80051220: sb          $zero, 0x96($sp)
    MEM_B(0X96, ctx->r29) = 0;
    // 0x80051224: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x80051228: lw          $t6, 0x24($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X24);
    // 0x8005122C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80051230: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x80051234: multu       $t6, $t8
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80051238: mflo        $s3
    ctx->r19 = lo;
    // 0x8005123C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80051240: jal         0x8005702C
    // 0x80051244: nop

    func_8005702C(rdram, ctx);
        goto after_12;
    // 0x80051244: nop

    after_12:
    // 0x80051248: b           L_80051688
    // 0x8005124C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80051688;
    // 0x8005124C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80051250:
    // 0x80051250: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80051254:
    // 0x80051254: andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    // 0x80051258: jal         0x8005786C
    // 0x8005125C: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    func_8005786C(rdram, ctx);
        goto after_13;
    // 0x8005125C: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    after_13:
    // 0x80051260: beq         $v0, $zero, L_80051684
    if (ctx->r2 == 0) {
        // 0x80051264: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80051684;
    }
    // 0x80051264: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80051268: lbu         $t7, 0x35($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X35);
    // 0x8005126C: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x80051270: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80051274: bne         $s6, $t7, L_80051284
    if (ctx->r22 != ctx->r15) {
        // 0x80051278: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80051284;
    }
    // 0x80051278: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8005127C: b           L_80051684
    // 0x80051280: sb          $t9, 0x35($v0)
    MEM_B(0X35, ctx->r2) = ctx->r25;
        goto L_80051684;
    // 0x80051280: sb          $t9, 0x35($v0)
    MEM_B(0X35, ctx->r2) = ctx->r25;
L_80051284:
    // 0x80051284: lw          $t6, 0x20($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20);
    // 0x80051288: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
    // 0x8005128C: sb          $fp, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r30;
    // 0x80051290: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80051294: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80051298: jal         0x8005748C
    // 0x8005129C: lw          $a2, 0x8($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X8);
    func_8005748C(rdram, ctx);
        goto after_14;
    // 0x8005129C: lw          $a2, 0x8($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X8);
    after_14:
    // 0x800512A0: b           L_80051688
    // 0x800512A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80051688;
    // 0x800512A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800512A8:
    // 0x800512A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800512AC: andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    // 0x800512B0: jal         0x8005786C
    // 0x800512B4: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    func_8005786C(rdram, ctx);
        goto after_15;
    // 0x800512B4: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    after_15:
    // 0x800512B8: beq         $v0, $zero, L_80051684
    if (ctx->r2 == 0) {
        // 0x800512BC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80051684;
    }
    // 0x800512BC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800512C0: sb          $s1, 0x33($v0)
    MEM_B(0X33, ctx->r2) = ctx->r17;
    // 0x800512C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800512C8: jal         0x80057404
    // 0x800512CC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80057404(rdram, ctx);
        goto after_16;
    // 0x800512CC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_16:
    // 0x800512D0: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x800512D4: sra         $t7, $s1, 16
    ctx->r15 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800512D8: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x800512DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800512E0: jal         0x800573E0
    // 0x800512E4: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    func_800573E0(rdram, ctx);
        goto after_17;
    // 0x800512E4: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    after_17:
    // 0x800512E8: sll         $a2, $s1, 16
    ctx->r6 = S32(ctx->r17 << 16);
    // 0x800512EC: sra         $t9, $a2, 16
    ctx->r25 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800512F0: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800512F4: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800512F8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800512FC: jal         0x80058D10
    // 0x80051300: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_80058D10(rdram, ctx);
        goto after_18;
    // 0x80051300: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_18:
    // 0x80051304: b           L_80051688
    // 0x80051308: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80051688;
    // 0x80051308: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005130C:
    // 0x8005130C: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x80051310: beql        $s0, $zero, L_80051688
    if (ctx->r16 == 0) {
        // 0x80051314: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80051688;
    }
    goto skip_8;
    // 0x80051314: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_8:
    // 0x80051318: or          $s3, $s6, $zero
    ctx->r19 = ctx->r22 | 0;
    // 0x8005131C: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
L_80051320:
    // 0x80051320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80051324: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80051328: bnel        $s3, $t6, L_80051370
    if (ctx->r19 != ctx->r14) {
        // 0x8005132C: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80051370;
    }
    goto skip_9;
    // 0x8005132C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_9:
    // 0x80051330: jal         0x80057404
    // 0x80051334: sb          $s4, 0x33($s0)
    MEM_B(0X33, ctx->r16) = ctx->r20;
    func_80057404(rdram, ctx);
        goto after_19;
    // 0x80051334: sb          $s4, 0x33($s0)
    MEM_B(0X33, ctx->r16) = ctx->r20;
    after_19:
    // 0x80051338: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x8005133C: sra         $t8, $s1, 16
    ctx->r24 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80051340: or          $s1, $t8, $zero
    ctx->r17 = ctx->r24 | 0;
    // 0x80051344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80051348: jal         0x800573E0
    // 0x8005134C: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    func_800573E0(rdram, ctx);
        goto after_20;
    // 0x8005134C: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    after_20:
    // 0x80051350: sll         $a2, $s1, 16
    ctx->r6 = S32(ctx->r17 << 16);
    // 0x80051354: sra         $t7, $a2, 16
    ctx->r15 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80051358: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x8005135C: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80051360: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80051364: jal         0x80058D10
    // 0x80051368: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_80058D10(rdram, ctx);
        goto after_21;
    // 0x80051368: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_21:
    // 0x8005136C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_80051370:
    // 0x80051370: bnel        $s0, $zero, L_80051320
    if (ctx->r16 != 0) {
        // 0x80051374: lbu         $t6, 0x31($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X31);
            goto L_80051320;
    }
    goto skip_10;
    // 0x80051374: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
    skip_10:
    // 0x80051378: b           L_80051688
    // 0x8005137C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80051688;
    // 0x8005137C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80051380:
    // 0x80051380: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80051384: beq         $s4, $at, L_80051414
    if (ctx->r20 == ctx->r1) {
        // 0x80051388: or          $v0, $s4, $zero
        ctx->r2 = ctx->r20 | 0;
            goto L_80051414;
    }
    // 0x80051388: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x8005138C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80051390: beq         $v0, $at, L_800513B8
    if (ctx->r2 == ctx->r1) {
        // 0x80051394: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_800513B8;
    }
    // 0x80051394: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80051398: beq         $v0, $at, L_800514A4
    if (ctx->r2 == ctx->r1) {
        // 0x8005139C: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_800514A4;
    }
    // 0x8005139C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800513A0: beq         $v0, $at, L_800514B8
    if (ctx->r2 == ctx->r1) {
        // 0x800513A4: addiu       $at, $zero, 0x5B
        ctx->r1 = ADD32(0, 0X5B);
            goto L_800514B8;
    }
    // 0x800513A4: addiu       $at, $zero, 0x5B
    ctx->r1 = ADD32(0, 0X5B);
    // 0x800513A8: beql        $v0, $at, L_8005156C
    if (ctx->r2 == ctx->r1) {
        // 0x800513AC: lw          $t9, 0x60($s2)
        ctx->r25 = MEM_W(ctx->r18, 0X60);
            goto L_8005156C;
    }
    goto skip_11;
    // 0x800513AC: lw          $t9, 0x60($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X60);
    skip_11:
    // 0x800513B0: b           L_80051688
    // 0x800513B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80051688;
    // 0x800513B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800513B8:
    // 0x800513B8: lw          $t9, 0x60($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X60);
    // 0x800513BC: sll         $t6, $s6, 4
    ctx->r14 = S32(ctx->r22 << 4);
    // 0x800513C0: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x800513C4: sb          $s1, 0x7($t8)
    MEM_B(0X7, ctx->r24) = ctx->r17;
    // 0x800513C8: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x800513CC: beql        $s0, $zero, L_80051688
    if (ctx->r16 == 0) {
        // 0x800513D0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80051688;
    }
    goto skip_12;
    // 0x800513D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_12:
    // 0x800513D4: or          $s3, $s6, $zero
    ctx->r19 = ctx->r22 | 0;
    // 0x800513D8: lbu         $t7, 0x31($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X31);
L_800513DC:
    // 0x800513DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800513E0: bnel        $s3, $t7, L_80051404
    if (ctx->r19 != ctx->r15) {
        // 0x800513E4: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80051404;
    }
    goto skip_13;
    // 0x800513E4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_13:
    // 0x800513E8: jal         0x80057824
    // 0x800513EC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80057824(rdram, ctx);
        goto after_22;
    // 0x800513EC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_22:
    // 0x800513F0: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800513F4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800513F8: jal         0x80059160
    // 0x800513FC: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    func_80059160(rdram, ctx);
        goto after_23;
    // 0x800513FC: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    after_23:
    // 0x80051400: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_80051404:
    // 0x80051404: bnel        $s0, $zero, L_800513DC
    if (ctx->r16 != 0) {
        // 0x80051408: lbu         $t7, 0x31($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X31);
            goto L_800513DC;
    }
    goto skip_14;
    // 0x80051408: lbu         $t7, 0x31($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X31);
    skip_14:
    // 0x8005140C: b           L_80051688
    // 0x80051410: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80051688;
    // 0x80051410: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80051414:
    // 0x80051414: lw          $t9, 0x60($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X60);
    // 0x80051418: sll         $t6, $s6, 4
    ctx->r14 = S32(ctx->r22 << 4);
    // 0x8005141C: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x80051420: sb          $s1, 0x9($t8)
    MEM_B(0X9, ctx->r24) = ctx->r17;
    // 0x80051424: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x80051428: beql        $s0, $zero, L_80051688
    if (ctx->r16 == 0) {
        // 0x8005142C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80051688;
    }
    goto skip_15;
    // 0x8005142C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_15:
    // 0x80051430: or          $s3, $s6, $zero
    ctx->r19 = ctx->r22 | 0;
    // 0x80051434: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x80051438: lbu         $t7, 0x31($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X31);
L_8005143C:
    // 0x8005143C: bnel        $s3, $t7, L_80051494
    if (ctx->r19 != ctx->r15) {
        // 0x80051440: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80051494;
    }
    goto skip_16;
    // 0x80051440: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_16:
    // 0x80051444: lbu         $t9, 0x34($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X34);
    // 0x80051448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005144C: beql        $s4, $t9, L_80051494
    if (ctx->r20 == ctx->r25) {
        // 0x80051450: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80051494;
    }
    goto skip_17;
    // 0x80051450: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_17:
    // 0x80051454: jal         0x80057404
    // 0x80051458: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80057404(rdram, ctx);
        goto after_24;
    // 0x80051458: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_24:
    // 0x8005145C: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x80051460: sra         $t6, $s1, 16
    ctx->r14 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80051464: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x80051468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005146C: jal         0x800573E0
    // 0x80051470: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    func_800573E0(rdram, ctx);
        goto after_25;
    // 0x80051470: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    after_25:
    // 0x80051474: sll         $a2, $s1, 16
    ctx->r6 = S32(ctx->r17 << 16);
    // 0x80051478: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8005147C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80051480: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80051484: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80051488: jal         0x80058D10
    // 0x8005148C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_80058D10(rdram, ctx);
        goto after_26;
    // 0x8005148C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_26:
    // 0x80051490: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_80051494:
    // 0x80051494: bnel        $s0, $zero, L_8005143C
    if (ctx->r16 != 0) {
        // 0x80051498: lbu         $t7, 0x31($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X31);
            goto L_8005143C;
    }
    goto skip_18;
    // 0x80051498: lbu         $t7, 0x31($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X31);
    skip_18:
    // 0x8005149C: b           L_80051688
    // 0x800514A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80051688;
    // 0x800514A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800514A4:
    // 0x800514A4: lw          $t7, 0x60($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X60);
    // 0x800514A8: sll         $t9, $s6, 4
    ctx->r25 = S32(ctx->r22 << 4);
    // 0x800514AC: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x800514B0: b           L_80051684
    // 0x800514B4: sb          $s1, 0x8($t6)
    MEM_B(0X8, ctx->r14) = ctx->r17;
        goto L_80051684;
    // 0x800514B4: sb          $s1, 0x8($t6)
    MEM_B(0X8, ctx->r14) = ctx->r17;
L_800514B8:
    // 0x800514B8: lw          $t8, 0x60($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X60);
    // 0x800514BC: sll         $t7, $s6, 4
    ctx->r15 = S32(ctx->r22 << 4);
    // 0x800514C0: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x800514C4: sb          $s1, 0xB($t9)
    MEM_B(0XB, ctx->r25) = ctx->r17;
    // 0x800514C8: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x800514CC: beql        $s0, $zero, L_80051688
    if (ctx->r16 == 0) {
        // 0x800514D0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80051688;
    }
    goto skip_19;
    // 0x800514D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_19:
    // 0x800514D4: or          $s3, $s6, $zero
    ctx->r19 = ctx->r22 | 0;
    // 0x800514D8: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x800514DC: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
    // 0x800514E0: addiu       $s7, $zero, 0x4
    ctx->r23 = ADD32(0, 0X4);
    // 0x800514E4: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x800514E8: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x800514EC: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
L_800514F0:
    // 0x800514F0: bnel        $s3, $t6, L_80051558
    if (ctx->r19 != ctx->r14) {
        // 0x800514F4: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80051558;
    }
    goto skip_20;
    // 0x800514F4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_20:
    // 0x800514F8: lbu         $v0, 0x35($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X35);
    // 0x800514FC: slti        $at, $s1, 0x40
    ctx->r1 = SIGNED(ctx->r17) < 0X40 ? 1 : 0;
    // 0x80051500: beql        $s4, $v0, L_80051558
    if (ctx->r20 == ctx->r2) {
        // 0x80051504: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80051558;
    }
    goto skip_21;
    // 0x80051504: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_21:
    // 0x80051508: bne         $at, $zero, L_80051520
    if (ctx->r1 != 0) {
        // 0x8005150C: nop
    
            goto L_80051520;
    }
    // 0x8005150C: nop

    // 0x80051510: bnel        $v0, $zero, L_80051558
    if (ctx->r2 != 0) {
        // 0x80051514: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80051558;
    }
    goto skip_22;
    // 0x80051514: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_22:
    // 0x80051518: b           L_80051554
    // 0x8005151C: sb          $s5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r21;
        goto L_80051554;
    // 0x8005151C: sb          $s5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r21;
L_80051520:
    // 0x80051520: bne         $s6, $v0, L_80051530
    if (ctx->r22 != ctx->r2) {
        // 0x80051524: nop
    
            goto L_80051530;
    }
    // 0x80051524: nop

    // 0x80051528: b           L_80051554
    // 0x8005152C: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
        goto L_80051554;
    // 0x8005152C: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
L_80051530:
    // 0x80051530: bnel        $s7, $v0, L_80051558
    if (ctx->r23 != ctx->r2) {
        // 0x80051534: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80051558;
    }
    goto skip_23;
    // 0x80051534: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_23:
    // 0x80051538: lw          $t8, 0x20($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X20);
    // 0x8005153C: sb          $fp, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r30;
    // 0x80051540: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80051544: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x80051548: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8005154C: jal         0x8005748C
    // 0x80051550: lw          $a2, 0x8($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X8);
    func_8005748C(rdram, ctx);
        goto after_27;
    // 0x80051550: lw          $a2, 0x8($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X8);
    after_27:
L_80051554:
    // 0x80051554: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_80051558:
    // 0x80051558: bnel        $s0, $zero, L_800514F0
    if (ctx->r16 != 0) {
        // 0x8005155C: lbu         $t6, 0x31($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X31);
            goto L_800514F0;
    }
    goto skip_24;
    // 0x8005155C: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
    skip_24:
    // 0x80051560: b           L_80051688
    // 0x80051564: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80051688;
    // 0x80051564: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80051568: lw          $t9, 0x60($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X60);
L_8005156C:
    // 0x8005156C: sll         $t6, $s6, 4
    ctx->r14 = S32(ctx->r22 << 4);
    // 0x80051570: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x80051574: sb          $s1, 0xA($t8)
    MEM_B(0XA, ctx->r24) = ctx->r17;
    // 0x80051578: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x8005157C: beql        $s0, $zero, L_80051688
    if (ctx->r16 == 0) {
        // 0x80051580: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80051688;
    }
    goto skip_25;
    // 0x80051580: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_25:
    // 0x80051584: or          $s3, $s6, $zero
    ctx->r19 = ctx->r22 | 0;
    // 0x80051588: lbu         $t7, 0x31($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X31);
L_8005158C:
    // 0x8005158C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80051590: andi        $a2, $s1, 0xFF
    ctx->r6 = ctx->r17 & 0XFF;
    // 0x80051594: bnel        $s3, $t7, L_800515A8
    if (ctx->r19 != ctx->r15) {
        // 0x80051598: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800515A8;
    }
    goto skip_26;
    // 0x80051598: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_26:
    // 0x8005159C: jal         0x800591F0
    // 0x800515A0: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    func_800591F0(rdram, ctx);
        goto after_28;
    // 0x800515A0: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    after_28:
    // 0x800515A4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800515A8:
    // 0x800515A8: bnel        $s0, $zero, L_8005158C
    if (ctx->r16 != 0) {
        // 0x800515AC: lbu         $t7, 0x31($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X31);
            goto L_8005158C;
    }
    goto skip_27;
    // 0x800515AC: lbu         $t7, 0x31($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X31);
    skip_27:
    // 0x800515B0: b           L_80051688
    // 0x800515B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80051688;
    // 0x800515B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800515B8:
    // 0x800515B8: lw          $v0, 0x20($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X20);
    // 0x800515BC: sll         $t6, $s4, 2
    ctx->r14 = S32(ctx->r20 << 2);
    // 0x800515C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800515C4: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x800515C8: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800515CC: addu        $t8, $v0, $t6
    ctx->r24 = ADD32(ctx->r2, ctx->r14);
    // 0x800515D0: slt         $at, $s4, $t9
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800515D4: beql        $at, $zero, L_80051688
    if (ctx->r1 == 0) {
        // 0x800515D8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80051688;
    }
    goto skip_28;
    // 0x800515D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_28:
    // 0x800515DC: jal         0x80057250
    // 0x800515E0: lw          $a1, 0xC($t8)
    ctx->r5 = MEM_W(ctx->r24, 0XC);
    func_80057250(rdram, ctx);
        goto after_29;
    // 0x800515E0: lw          $a1, 0xC($t8)
    ctx->r5 = MEM_W(ctx->r24, 0XC);
    after_29:
    // 0x800515E4: b           L_80051688
    // 0x800515E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80051688;
    // 0x800515E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800515EC:
    // 0x800515EC: lw          $t7, 0x60($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X60);
    // 0x800515F0: sll         $fp, $s6, 4
    ctx->r30 = S32(ctx->r22 << 4);
    // 0x800515F4: sll         $t8, $s1, 7
    ctx->r24 = S32(ctx->r17 << 7);
    // 0x800515F8: addu        $t9, $t7, $fp
    ctx->r25 = ADD32(ctx->r15, ctx->r30);
    // 0x800515FC: lh          $t6, 0x4($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X4);
    // 0x80051600: addu        $t7, $t8, $s4
    ctx->r15 = ADD32(ctx->r24, ctx->r20);
    // 0x80051604: addiu       $t9, $t7, -0x2000
    ctx->r25 = ADD32(ctx->r15, -0X2000);
    // 0x80051608: multu       $t6, $t9
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005160C: mflo        $a0
    ctx->r4 = lo;
    // 0x80051610: bgez        $a0, L_80051620
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80051614: sra         $t8, $a0, 13
        ctx->r24 = S32(SIGNED(ctx->r4) >> 13);
            goto L_80051620;
    }
    // 0x80051614: sra         $t8, $a0, 13
    ctx->r24 = S32(SIGNED(ctx->r4) >> 13);
    // 0x80051618: addiu       $at, $a0, 0x1FFF
    ctx->r1 = ADD32(ctx->r4, 0X1FFF);
    // 0x8005161C: sra         $t8, $at, 13
    ctx->r24 = S32(SIGNED(ctx->r1) >> 13);
L_80051620:
    // 0x80051620: jal         0x80053FD0
    // 0x80051624: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_80053FD0(rdram, ctx);
        goto after_30;
    // 0x80051624: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_30:
    // 0x80051628: lw          $t7, 0x60($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X60);
    // 0x8005162C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80051630: addu        $t6, $t7, $fp
    ctx->r14 = ADD32(ctx->r15, ctx->r30);
    // 0x80051634: swc1        $f0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f0.u32l;
    // 0x80051638: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x8005163C: beql        $s0, $zero, L_80051688
    if (ctx->r16 == 0) {
        // 0x80051640: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80051688;
    }
    goto skip_29;
    // 0x80051640: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_29:
    // 0x80051644: or          $s3, $s6, $zero
    ctx->r19 = ctx->r22 | 0;
    // 0x80051648: lbu         $t9, 0x31($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X31);
L_8005164C:
    // 0x8005164C: bnel        $s3, $t9, L_8005167C
    if (ctx->r19 != ctx->r25) {
        // 0x80051650: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_8005167C;
    }
    goto skip_30;
    // 0x80051650: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_30:
    // 0x80051654: lwc1        $f6, 0x28($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80051658: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005165C: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80051660: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80051664: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80051668: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8005166C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80051670: jal         0x80058DB0
    // 0x80051674: nop

    func_80058DB0(rdram, ctx);
        goto after_31;
    // 0x80051674: nop

    after_31:
    // 0x80051678: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_8005167C:
    // 0x8005167C: bnel        $s0, $zero, L_8005164C
    if (ctx->r16 != 0) {
        // 0x80051680: lbu         $t9, 0x31($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X31);
            goto L_8005164C;
    }
    goto skip_31;
    // 0x80051680: lbu         $t9, 0x31($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X31);
    skip_31:
L_80051684:
    // 0x80051684: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80051688:
    // 0x80051688: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    // 0x8005168C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80051694(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80051694: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005169C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005169C: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x800516A0: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800516A4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800516A8: addiu       $t6, $a0, 0x38
    ctx->r14 = ADD32(ctx->r4, 0X38);
    // 0x800516AC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800516B0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800516B4: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800516B8: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800516BC: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800516C0: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800516C4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800516C8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800516CC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800516D0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800516D4: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
    // 0x800516D8: addiu       $s5, $a0, 0x48
    ctx->r21 = ADD32(ctx->r4, 0X48);
L_800516DC:
    // 0x800516DC: lhu         $t7, 0x38($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0X38);
    // 0x800516E0: sltiu       $at, $t7, 0x18
    ctx->r1 = ctx->r15 < 0X18 ? 1 : 0;
    // 0x800516E4: beq         $at, $zero, L_80051C5C
    if (ctx->r1 == 0) {
        // 0x800516E8: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80051C5C;
    }
    // 0x800516E8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800516EC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800516F0: addu        $at, $at, $t7
    gpr jr_addend_800516F8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800516F4: lw          $t7, -0x6D6C($at)
    ctx->r15 = ADD32(ctx->r1, -0X6D6C);
    // 0x800516F8: jr          $t7
    // 0x800516FC: nop

    switch (jr_addend_800516F8 >> 2) {
        case 0: goto L_80051700; break;
        case 1: goto L_80051C5C; break;
        case 2: goto L_80051A30; break;
        case 3: goto L_80051C5C; break;
        case 4: goto L_80051C5C; break;
        case 5: goto L_800517EC; break;
        case 6: goto L_80051838; break;
        case 7: goto L_80051A4C; break;
        case 8: goto L_80051C5C; break;
        case 9: goto L_800517CC; break;
        case 10: goto L_80051A6C; break;
        case 11: goto L_80051C5C; break;
        case 12: goto L_80051BFC; break;
        case 13: goto L_80051C18; break;
        case 14: goto L_80051C4C; break;
        case 15: goto L_80051AD0; break;
        case 16: goto L_80051AF4; break;
        case 17: goto L_80051B60; break;
        case 18: goto L_80051C5C; break;
        case 19: goto L_80051C5C; break;
        case 20: goto L_80051C5C; break;
        case 21: goto L_80051A30; break;
        case 22: goto L_8005189C; break;
        case 23: goto L_800519A8; break;
        default: switch_error(__func__, 0x800516F8, 0x80079294);
    }
    // 0x800516FC: nop

L_80051700:
    // 0x80051700: lw          $a0, 0x18($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X18);
    // 0x80051704: beql        $a0, $zero, L_80051C60
    if (ctx->r4 == 0) {
        // 0x80051708: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80051C60;
    }
    goto skip_0;
    // 0x80051708: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_0:
    // 0x8005170C: jal         0x8004FD34
    // 0x80051710: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    func_8004FD34(rdram, ctx);
        goto after_0;
    // 0x80051710: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_0:
    // 0x80051714: lh          $t8, 0x58($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X58);
    // 0x80051718: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8005171C: sltiu       $at, $t9, 0x14
    ctx->r1 = ctx->r25 < 0X14 ? 1 : 0;
    // 0x80051720: beq         $at, $zero, L_80051C5C
    if (ctx->r1 == 0) {
        // 0x80051724: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80051C5C;
    }
    // 0x80051724: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80051728: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8005172C: addu        $at, $at, $t9
    gpr jr_addend_80051734 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80051730: lw          $t9, -0x6D0C($at)
    ctx->r25 = ADD32(ctx->r1, -0X6D0C);
    // 0x80051734: jr          $t9
    // 0x80051738: nop

    switch (jr_addend_80051734 >> 2) {
        case 0: goto L_8005173C; break;
        case 1: goto L_80051C5C; break;
        case 2: goto L_80051764; break;
        case 3: goto L_80051790; break;
        case 4: goto L_80051C5C; break;
        case 5: goto L_80051C5C; break;
        case 6: goto L_80051C5C; break;
        case 7: goto L_80051C5C; break;
        case 8: goto L_80051C5C; break;
        case 9: goto L_80051C5C; break;
        case 10: goto L_80051C5C; break;
        case 11: goto L_80051C5C; break;
        case 12: goto L_80051C5C; break;
        case 13: goto L_80051C5C; break;
        case 14: goto L_80051C5C; break;
        case 15: goto L_80051C5C; break;
        case 16: goto L_80051C5C; break;
        case 17: goto L_800517BC; break;
        case 18: goto L_800517BC; break;
        case 19: goto L_800517BC; break;
        default: switch_error(__func__, 0x80051734, 0x800792F4);
    }
    // 0x80051738: nop

L_8005173C:
    // 0x8005173C: addiu       $t0, $sp, 0x58
    ctx->r8 = ADD32(ctx->r29, 0X58);
    // 0x80051740: sw          $s2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r18;
    // 0x80051744: jal         0x80050E6C
    // 0x80051748: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    func_80050E6C(rdram, ctx);
        goto after_1;
    // 0x80051748: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    after_1:
    // 0x8005174C: lw          $s2, 0xA0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA0);
    // 0x80051750: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80051754: jal         0x80050BF0
    // 0x80051758: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80050BF0(rdram, ctx);
        goto after_2;
    // 0x80051758: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x8005175C: b           L_80051C60
    // 0x80051760: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80051C60;
    // 0x80051760: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80051764:
    // 0x80051764: or          $s7, $s2, $zero
    ctx->r23 = ctx->r18 | 0;
    // 0x80051768: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x8005176C: sw          $s2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r18;
    // 0x80051770: jal         0x80050C9C
    // 0x80051774: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    func_80050C9C(rdram, ctx);
        goto after_3;
    // 0x80051774: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    after_3:
    // 0x80051778: lw          $s2, 0xA0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA0);
    // 0x8005177C: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80051780: jal         0x80050BF0
    // 0x80051784: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80050BF0(rdram, ctx);
        goto after_4;
    // 0x80051784: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x80051788: b           L_80051C60
    // 0x8005178C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80051C60;
    // 0x8005178C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80051790:
    // 0x80051790: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80051794: sw          $t6, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r14;
    // 0x80051798: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x8005179C: lui         $a2, 0x7FFF
    ctx->r6 = S32(0X7FFF << 16);
    // 0x800517A0: sh          $t7, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r15;
    // 0x800517A4: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x800517A8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800517AC: jal         0x8005702C
    // 0x800517B0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    func_8005702C(rdram, ctx);
        goto after_5;
    // 0x800517B0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_5:
    // 0x800517B4: b           L_80051C60
    // 0x800517B8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80051C60;
    // 0x800517B8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800517BC:
    // 0x800517BC: jal         0x80050BF0
    // 0x800517C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80050BF0(rdram, ctx);
        goto after_6;
    // 0x800517C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x800517C4: b           L_80051C60
    // 0x800517C8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80051C60;
    // 0x800517C8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800517CC:
    // 0x800517CC: addiu       $t8, $zero, 0x9
    ctx->r24 = ADD32(0, 0X9);
    // 0x800517D0: sh          $t8, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r24;
    // 0x800517D4: lw          $a2, 0x5C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X5C);
    // 0x800517D8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800517DC: jal         0x8005702C
    // 0x800517E0: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    func_8005702C(rdram, ctx);
        goto after_7;
    // 0x800517E0: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    after_7:
    // 0x800517E4: b           L_80051C60
    // 0x800517E8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80051C60;
    // 0x800517E8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800517EC:
    // 0x800517EC: lw          $s0, 0x3C($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X3C);
    // 0x800517F0: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800517F4: jal         0x80058BE0
    // 0x800517F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80058BE0(rdram, ctx);
        goto after_8;
    // 0x800517F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x800517FC: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80051800: jal         0x80058C60
    // 0x80051804: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80058C60(rdram, ctx);
        goto after_9;
    // 0x80051804: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
    // 0x80051808: lw          $s1, 0x10($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X10);
    // 0x8005180C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80051810: lbu         $t9, 0x37($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X37);
    // 0x80051814: beql        $t9, $zero, L_80051828
    if (ctx->r25 == 0) {
        // 0x80051818: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80051828;
    }
    goto skip_1;
    // 0x80051818: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_1:
    // 0x8005181C: jal         0x80058890
    // 0x80051820: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80058890(rdram, ctx);
        goto after_10;
    // 0x80051820: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_10:
    // 0x80051824: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80051828:
    // 0x80051828: jal         0x80057660
    // 0x8005182C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80057660(rdram, ctx);
        goto after_11;
    // 0x8005182C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_11:
    // 0x80051830: b           L_80051C60
    // 0x80051834: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80051C60;
    // 0x80051834: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80051838:
    // 0x80051838: lw          $s0, 0x3C($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X3C);
    // 0x8005183C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80051840: lw          $s1, 0x10($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X10);
    // 0x80051844: lbu         $t6, 0x34($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X34);
    // 0x80051848: bnel        $t6, $zero, L_80051858
    if (ctx->r14 != 0) {
        // 0x8005184C: lw          $s3, 0x40($s2)
        ctx->r19 = MEM_W(ctx->r18, 0X40);
            goto L_80051858;
    }
    goto skip_2;
    // 0x8005184C: lw          $s3, 0x40($s2)
    ctx->r19 = MEM_W(ctx->r18, 0X40);
    skip_2:
    // 0x80051850: sb          $t7, 0x34($s1)
    MEM_B(0X34, ctx->r17) = ctx->r15;
    // 0x80051854: lw          $s3, 0x40($s2)
    ctx->r19 = MEM_W(ctx->r18, 0X40);
L_80051858:
    // 0x80051858: lw          $t8, 0x1C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X1C);
    // 0x8005185C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80051860: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80051864: addu        $t9, $t8, $s3
    ctx->r25 = ADD32(ctx->r24, ctx->r19);
    // 0x80051868: sw          $t9, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r25;
    // 0x8005186C: lbu         $t6, 0x44($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X44);
    // 0x80051870: jal         0x80057404
    // 0x80051874: sb          $t6, 0x30($s1)
    MEM_B(0X30, ctx->r17) = ctx->r14;
    func_80057404(rdram, ctx);
        goto after_12;
    // 0x80051874: sb          $t6, 0x30($s1)
    MEM_B(0X30, ctx->r17) = ctx->r14;
    after_12:
    // 0x80051878: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x8005187C: sra         $t7, $a2, 16
    ctx->r15 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80051880: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x80051884: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80051888: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8005188C: jal         0x80058D10
    // 0x80051890: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    func_80058D10(rdram, ctx);
        goto after_13;
    // 0x80051890: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_13:
    // 0x80051894: b           L_80051C60
    // 0x80051898: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80051C60;
    // 0x80051898: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_8005189C:
    // 0x8005189C: lw          $t9, 0x74($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X74);
    // 0x800518A0: lw          $s4, 0x40($s2)
    ctx->r20 = MEM_W(ctx->r18, 0X40);
    // 0x800518A4: lw          $s1, 0x3C($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X3C);
    // 0x800518A8: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x800518AC: jalr        $t9
    // 0x800518B0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_14;
    // 0x800518B0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_14:
    // 0x800518B4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800518B8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800518BC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800518C0: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800518C4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800518C8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800518CC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800518D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800518D4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800518D8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800518DC: nop

    // 0x800518E0: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x800518E4: beql        $t6, $zero, L_80051934
    if (ctx->r14 == 0) {
        // 0x800518E8: mfc1        $t6, $f6
        ctx->r14 = (int32_t)ctx->f6.u32l;
            goto L_80051934;
    }
    goto skip_3;
    // 0x800518E8: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    skip_3:
    // 0x800518EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800518F0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800518F4: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800518F8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800518FC: nop

    // 0x80051900: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80051904: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80051908: nop

    // 0x8005190C: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80051910: bne         $t6, $zero, L_80051928
    if (ctx->r14 != 0) {
        // 0x80051914: nop
    
            goto L_80051928;
    }
    // 0x80051914: nop

    // 0x80051918: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8005191C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80051920: b           L_80051940
    // 0x80051924: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_80051940;
    // 0x80051924: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_80051928:
    // 0x80051928: b           L_80051940
    // 0x8005192C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_80051940;
    // 0x8005192C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80051930: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
L_80051934:
    // 0x80051934: nop

    // 0x80051938: bltz        $t6, L_80051928
    if (SIGNED(ctx->r14) < 0) {
        // 0x8005193C: nop
    
            goto L_80051928;
    }
    // 0x8005193C: nop

L_80051940:
    // 0x80051940: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80051944: jal         0x80057404
    // 0x80051948: sb          $t6, 0x36($s1)
    MEM_B(0X36, ctx->r17) = ctx->r14;
    func_80057404(rdram, ctx);
        goto after_15;
    // 0x80051948: sb          $t6, 0x36($s1)
    MEM_B(0X36, ctx->r17) = ctx->r14;
    after_15:
    // 0x8005194C: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x80051950: sra         $t7, $s0, 16
    ctx->r15 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80051954: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x80051958: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005195C: jal         0x800573E0
    // 0x80051960: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    func_800573E0(rdram, ctx);
        goto after_16;
    // 0x80051960: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    after_16:
    // 0x80051964: sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16 << 16);
    // 0x80051968: sra         $t9, $a2, 16
    ctx->r25 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8005196C: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x80051970: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80051974: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x80051978: jal         0x80058D10
    // 0x8005197C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_80058D10(rdram, ctx);
        goto after_17;
    // 0x8005197C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_17:
    // 0x80051980: addiu       $t8, $zero, 0x16
    ctx->r24 = ADD32(0, 0X16);
    // 0x80051984: sh          $t8, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r24;
    // 0x80051988: sw          $s1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r17;
    // 0x8005198C: sw          $s4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r20;
    // 0x80051990: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80051994: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x80051998: jal         0x8005702C
    // 0x8005199C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_8005702C(rdram, ctx);
        goto after_18;
    // 0x8005199C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_18:
    // 0x800519A0: b           L_80051C60
    // 0x800519A4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80051C60;
    // 0x800519A4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800519A8:
    // 0x800519A8: lw          $t9, 0x74($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X74);
    // 0x800519AC: lw          $s4, 0x40($s2)
    ctx->r20 = MEM_W(ctx->r18, 0X40);
    // 0x800519B0: lw          $s1, 0x3C($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X3C);
    // 0x800519B4: lbu         $s0, 0x44($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0X44);
    // 0x800519B8: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x800519BC: jalr        $t9
    // 0x800519C0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_19;
    // 0x800519C0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_19:
    // 0x800519C4: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800519C8: lwc1        $f4, 0x28($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X28);
    // 0x800519CC: sll         $t7, $s0, 4
    ctx->r15 = S32(ctx->r16 << 4);
    // 0x800519D0: swc1        $f8, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f8.u32l;
    // 0x800519D4: lwc1        $f6, 0x2C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x800519D8: lw          $t6, 0x60($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X60);
    // 0x800519DC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800519E0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800519E4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800519E8: lwc1        $f10, 0xC($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0XC);
    // 0x800519EC: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800519F0: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x800519F4: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800519F8: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800519FC: jal         0x80058DB0
    // 0x80051A00: nop

    func_80058DB0(rdram, ctx);
        goto after_20;
    // 0x80051A00: nop

    after_20:
    // 0x80051A04: addiu       $t9, $zero, 0x17
    ctx->r25 = ADD32(0, 0X17);
    // 0x80051A08: sh          $t9, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r25;
    // 0x80051A0C: sw          $s1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r17;
    // 0x80051A10: sw          $s4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r20;
    // 0x80051A14: sb          $s0, 0x98($sp)
    MEM_B(0X98, ctx->r29) = ctx->r16;
    // 0x80051A18: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80051A1C: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x80051A20: jal         0x8005702C
    // 0x80051A24: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_8005702C(rdram, ctx);
        goto after_21;
    // 0x80051A24: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_21:
    // 0x80051A28: b           L_80051C60
    // 0x80051A2C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80051C60;
    // 0x80051A2C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80051A30:
    // 0x80051A30: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80051A34: sw          $s2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r18;
    // 0x80051A38: jal         0x80050E6C
    // 0x80051A3C: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    func_80050E6C(rdram, ctx);
        goto after_22;
    // 0x80051A3C: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    after_22:
    // 0x80051A40: lw          $s2, 0xA0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA0);
    // 0x80051A44: b           L_80051C5C
    // 0x80051A48: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
        goto L_80051C5C;
    // 0x80051A48: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
L_80051A4C:
    // 0x80051A4C: or          $s7, $s2, $zero
    ctx->r23 = ctx->r18 | 0;
    // 0x80051A50: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80051A54: sw          $s2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r18;
    // 0x80051A58: jal         0x80050C9C
    // 0x80051A5C: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    func_80050C9C(rdram, ctx);
        goto after_23;
    // 0x80051A5C: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    after_23:
    // 0x80051A60: lw          $s2, 0xA0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA0);
    // 0x80051A64: b           L_80051C5C
    // 0x80051A68: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
        goto L_80051C5C;
    // 0x80051A68: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
L_80051A6C:
    // 0x80051A6C: lw          $s1, 0x64($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X64);
    // 0x80051A70: lh          $t6, 0x3C($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X3C);
    // 0x80051A74: beq         $s1, $zero, L_80051C5C
    if (ctx->r17 == 0) {
        // 0x80051A78: sh          $t6, 0x32($s2)
        MEM_H(0X32, ctx->r18) = ctx->r14;
            goto L_80051C5C;
    }
    // 0x80051A78: sh          $t6, 0x32($s2)
    MEM_H(0X32, ctx->r18) = ctx->r14;
    // 0x80051A7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80051A80:
    // 0x80051A80: jal         0x80057404
    // 0x80051A84: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80057404(rdram, ctx);
        goto after_24;
    // 0x80051A84: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_24:
    // 0x80051A88: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x80051A8C: sra         $t7, $s0, 16
    ctx->r15 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80051A90: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x80051A94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80051A98: jal         0x800573E0
    // 0x80051A9C: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    func_800573E0(rdram, ctx);
        goto after_25;
    // 0x80051A9C: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    after_25:
    // 0x80051AA0: sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16 << 16);
    // 0x80051AA4: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80051AA8: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80051AAC: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80051AB0: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x80051AB4: jal         0x80058D10
    // 0x80051AB8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_80058D10(rdram, ctx);
        goto after_26;
    // 0x80051AB8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_26:
    // 0x80051ABC: lw          $s1, 0x0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X0);
    // 0x80051AC0: bnel        $s1, $zero, L_80051A80
    if (ctx->r17 != 0) {
        // 0x80051AC4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80051A80;
    }
    goto skip_4;
    // 0x80051AC4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_4:
    // 0x80051AC8: b           L_80051C60
    // 0x80051ACC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80051C60;
    // 0x80051ACC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80051AD0:
    // 0x80051AD0: lw          $t9, 0x2C($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X2C);
    // 0x80051AD4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80051AD8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80051ADC: beq         $t9, $at, L_80051C5C
    if (ctx->r25 == ctx->r1) {
        // 0x80051AE0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80051C5C;
    }
    // 0x80051AE0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80051AE4: jal         0x80050BF0
    // 0x80051AE8: sw          $t6, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r14;
    func_80050BF0(rdram, ctx);
        goto after_27;
    // 0x80051AE8: sw          $t6, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r14;
    after_27:
    // 0x80051AEC: b           L_80051C60
    // 0x80051AF0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80051C60;
    // 0x80051AF0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80051AF4:
    // 0x80051AF4: lw          $t7, 0x2C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X2C);
    // 0x80051AF8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80051AFC: bnel        $t7, $at, L_80051C60
    if (ctx->r15 != ctx->r1) {
        // 0x80051B00: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80051C60;
    }
    goto skip_5;
    // 0x80051B00: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_5:
    // 0x80051B04: lw          $s1, 0x64($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X64);
    // 0x80051B08: beq         $s1, $zero, L_80051B58
    if (ctx->r17 == 0) {
        // 0x80051B0C: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_80051B58;
    }
    // 0x80051B0C: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
L_80051B10:
    // 0x80051B10: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80051B14: jal         0x80058BE0
    // 0x80051B18: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    func_80058BE0(rdram, ctx);
        goto after_28;
    // 0x80051B18: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    after_28:
    // 0x80051B1C: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80051B20: jal         0x80058C60
    // 0x80051B24: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80058C60(rdram, ctx);
        goto after_29;
    // 0x80051B24: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_29:
    // 0x80051B28: lbu         $t8, 0x37($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X37);
    // 0x80051B2C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80051B30: beql        $t8, $zero, L_80051B44
    if (ctx->r24 == 0) {
        // 0x80051B34: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80051B44;
    }
    goto skip_6;
    // 0x80051B34: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_6:
    // 0x80051B38: jal         0x80058890
    // 0x80051B3C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80058890(rdram, ctx);
        goto after_30;
    // 0x80051B3C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_30:
    // 0x80051B40: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80051B44:
    // 0x80051B44: jal         0x80057660
    // 0x80051B48: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80057660(rdram, ctx);
        goto after_31;
    // 0x80051B48: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_31:
    // 0x80051B4C: lw          $s1, 0x64($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X64);
    // 0x80051B50: bnel        $s1, $zero, L_80051B10
    if (ctx->r17 != 0) {
        // 0x80051B54: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_80051B10;
    }
    goto skip_7;
    // 0x80051B54: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    skip_7:
L_80051B58:
    // 0x80051B58: b           L_80051C5C
    // 0x80051B5C: sw          $zero, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = 0;
        goto L_80051C5C;
    // 0x80051B5C: sw          $zero, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = 0;
L_80051B60:
    // 0x80051B60: lw          $t9, 0x2C($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X2C);
    // 0x80051B64: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80051B68: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80051B6C: bnel        $t9, $at, L_80051C60
    if (ctx->r25 != ctx->r1) {
        // 0x80051B70: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80051C60;
    }
    goto skip_8;
    // 0x80051B70: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_8:
    // 0x80051B74: jal         0x80056F10
    // 0x80051B78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056F10(rdram, ctx);
        goto after_32;
    // 0x80051B78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_32:
    // 0x80051B7C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80051B80: jal         0x80056F10
    // 0x80051B84: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    func_80056F10(rdram, ctx);
        goto after_33;
    // 0x80051B84: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_33:
    // 0x80051B88: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80051B8C: jal         0x80056F10
    // 0x80051B90: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80056F10(rdram, ctx);
        goto after_34;
    // 0x80051B90: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_34:
    // 0x80051B94: lw          $s1, 0x64($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X64);
    // 0x80051B98: beq         $s1, $zero, L_80051BD0
    if (ctx->r17 == 0) {
        // 0x80051B9C: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_80051BD0;
    }
    // 0x80051B9C: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
L_80051BA0:
    // 0x80051BA0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80051BA4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80051BA8: jal         0x800575B8
    // 0x80051BAC: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    func_800575B8(rdram, ctx);
        goto after_35;
    // 0x80051BAC: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    after_35:
    // 0x80051BB0: beq         $v0, $zero, L_80051BC4
    if (ctx->r2 == 0) {
        // 0x80051BB4: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80051BC4;
    }
    // 0x80051BB4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80051BB8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80051BBC: jal         0x8005748C
    // 0x80051BC0: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    func_8005748C(rdram, ctx);
        goto after_36;
    // 0x80051BC0: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    after_36:
L_80051BC4:
    // 0x80051BC4: lw          $s1, 0x0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X0);
    // 0x80051BC8: bnel        $s1, $zero, L_80051BA0
    if (ctx->r17 != 0) {
        // 0x80051BCC: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_80051BA0;
    }
    goto skip_9;
    // 0x80051BCC: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    skip_9:
L_80051BD0:
    // 0x80051BD0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80051BD4: sw          $t6, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r14;
    // 0x80051BD8: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x80051BDC: lui         $a2, 0x7FFF
    ctx->r6 = S32(0X7FFF << 16);
    // 0x80051BE0: sh          $t7, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r15;
    // 0x80051BE4: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x80051BE8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80051BEC: jal         0x8005702C
    // 0x80051BF0: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    func_8005702C(rdram, ctx);
        goto after_37;
    // 0x80051BF0: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    after_37:
    // 0x80051BF4: b           L_80051C60
    // 0x80051BF8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80051C60;
    // 0x80051BF8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80051BFC:
    // 0x80051BFC: lbu         $s0, 0x3C($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0X3C);
    // 0x80051C00: lw          $t9, 0x60($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X60);
    // 0x80051C04: lbu         $t8, 0x3D($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X3D);
    // 0x80051C08: sll         $t6, $s0, 4
    ctx->r14 = S32(ctx->r16 << 4);
    // 0x80051C0C: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x80051C10: b           L_80051C5C
    // 0x80051C14: sb          $t8, 0x8($t7)
    MEM_B(0X8, ctx->r15) = ctx->r24;
        goto L_80051C5C;
    // 0x80051C14: sb          $t8, 0x8($t7)
    MEM_B(0X8, ctx->r15) = ctx->r24;
L_80051C18:
    // 0x80051C18: lw          $t9, 0x3C($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X3C);
    // 0x80051C1C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80051C20: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80051C24: sw          $t9, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r25;
    // 0x80051C28: jal         0x80050C60
    // 0x80051C2C: lwc1        $f12, -0x6CBC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X6CBC);
    func_80050C60(rdram, ctx);
        goto after_38;
    // 0x80051C2C: lwc1        $f12, -0x6CBC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X6CBC);
    after_38:
    // 0x80051C30: lw          $a1, 0x20($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X20);
    // 0x80051C34: beql        $a1, $zero, L_80051C60
    if (ctx->r5 == 0) {
        // 0x80051C38: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80051C60;
    }
    goto skip_10;
    // 0x80051C38: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_10:
    // 0x80051C3C: jal         0x80057324
    // 0x80051C40: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80057324(rdram, ctx);
        goto after_39;
    // 0x80051C40: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_39:
    // 0x80051C44: b           L_80051C60
    // 0x80051C48: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80051C60;
    // 0x80051C48: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80051C4C:
    // 0x80051C4C: lw          $a1, 0x3C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X3C);
    // 0x80051C50: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80051C54: jal         0x80057324
    // 0x80051C58: sw          $a1, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r5;
    func_80057324(rdram, ctx);
        goto after_40;
    // 0x80051C58: sw          $a1, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r5;
    after_40:
L_80051C5C:
    // 0x80051C5C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80051C60:
    // 0x80051C60: jal         0x80057150
    // 0x80051C64: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    func_80057150(rdram, ctx);
        goto after_41;
    // 0x80051C64: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    after_41:
    // 0x80051C68: beq         $v0, $zero, L_800516DC
    if (ctx->r2 == 0) {
        // 0x80051C6C: sw          $v0, 0x28($s2)
        MEM_W(0X28, ctx->r18) = ctx->r2;
            goto L_800516DC;
    }
    // 0x80051C6C: sw          $v0, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r2;
    // 0x80051C70: lw          $t6, 0x1C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X1C);
    // 0x80051C74: addu        $t8, $t6, $v0
    ctx->r24 = ADD32(ctx->r14, ctx->r2);
    // 0x80051C78: sw          $t8, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r24;
    // 0x80051C7C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80051C80: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80051C84: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80051C88: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80051C8C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80051C90: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80051C94: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80051C98: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80051C9C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80051CA0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80051CA4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80051CA8: jr          $ra
    // 0x80051CAC: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    TRACE_RETURN()
    return;
    // 0x80051CAC: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_80051CB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80051CB0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80051CB4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80051CB8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80051CBC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80051CC0: lw          $a2, 0xC($a1)
    ctx->r6 = MEM_W(ctx->r5, 0XC);
    // 0x80051CC4: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    // 0x80051CC8: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x80051CCC: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x80051CD0: lw          $t6, 0x3190($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3190);
    // 0x80051CD4: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80051CD8: addiu       $t8, $zero, 0x1E8
    ctx->r24 = ADD32(0, 0X1E8);
    // 0x80051CDC: addiu       $t9, $zero, 0x7FFF
    ctx->r25 = ADD32(0, 0X7FFF);
    // 0x80051CE0: addiu       $t0, $zero, 0x3E80
    ctx->r8 = ADD32(0, 0X3E80);
    // 0x80051CE4: sh          $t7, 0x30($a0)
    MEM_H(0X30, ctx->r4) = ctx->r15;
    // 0x80051CE8: sw          $t8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r24;
    // 0x80051CEC: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
    // 0x80051CF0: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x80051CF4: sh          $t9, 0x32($a0)
    MEM_H(0X32, ctx->r4) = ctx->r25;
    // 0x80051CF8: sw          $t0, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->r8;
    // 0x80051CFC: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x80051D00: sw          $t6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r14;
    // 0x80051D04: lw          $t1, 0x10($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X10);
    // 0x80051D08: addiu       $t4, $zero, 0x9
    ctx->r12 = ADD32(0, 0X9);
    // 0x80051D0C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80051D10: sw          $t1, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->r9;
    // 0x80051D14: lw          $t2, 0x14($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X14);
    // 0x80051D18: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80051D1C: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x80051D20: sw          $t2, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->r10;
    // 0x80051D24: lw          $t3, 0x18($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X18);
    // 0x80051D28: sh          $t4, 0x38($a0)
    MEM_H(0X38, ctx->r4) = ctx->r12;
    // 0x80051D2C: sw          $t3, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r11;
    // 0x80051D30: lbu         $t5, 0x8($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X8);
    // 0x80051D34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80051D38: sb          $t5, 0x34($a0)
    MEM_B(0X34, ctx->r4) = ctx->r13;
    // 0x80051D3C: lbu         $a3, 0x8($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X8);
    // 0x80051D40: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80051D44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80051D48: jal         0x800507E0
    // 0x80051D4C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_800507E0(rdram, ctx);
        goto after_0;
    // 0x80051D4C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80051D50: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    // 0x80051D54: jal         0x80058994
    // 0x80051D58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80058994(rdram, ctx);
        goto after_1;
    // 0x80051D58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80051D5C: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80051D60: addiu       $t7, $zero, 0x38
    ctx->r15 = ADD32(0, 0X38);
    // 0x80051D64: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80051D68: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80051D6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80051D70: jal         0x800507E0
    // 0x80051D74: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_800507E0(rdram, ctx);
        goto after_2;
    // 0x80051D74: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80051D78: sw          $zero, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = 0;
    // 0x80051D7C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80051D80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80051D84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80051D88: blez        $t8, L_80051DB8
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80051D8C: addiu       $t1, $zero, 0x1C
        ctx->r9 = ADD32(0, 0X1C);
            goto L_80051DB8;
    }
    // 0x80051D8C: addiu       $t1, $zero, 0x1C
    ctx->r9 = ADD32(0, 0X1C);
    // 0x80051D90: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80051D94: lw          $t9, 0x6C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X6C);
L_80051D98:
    // 0x80051D98: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80051D9C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80051DA0: sw          $v1, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->r3;
    // 0x80051DA4: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80051DA8: addiu       $v1, $v1, 0x38
    ctx->r3 = ADD32(ctx->r3, 0X38);
    // 0x80051DAC: slt         $at, $a0, $t0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80051DB0: bnel        $at, $zero, L_80051D98
    if (ctx->r1 != 0) {
        // 0x80051DB4: lw          $t9, 0x6C($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X6C);
            goto L_80051D98;
    }
    goto skip_0;
    // 0x80051DB4: lw          $t9, 0x6C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X6C);
    skip_0:
L_80051DB8:
    // 0x80051DB8: sw          $zero, 0x64($s0)
    MEM_W(0X64, ctx->r16) = 0;
    // 0x80051DBC: sw          $zero, 0x68($s0)
    MEM_W(0X68, ctx->r16) = 0;
    // 0x80051DC0: lw          $a3, 0x4($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X4);
    // 0x80051DC4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80051DC8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80051DCC: jal         0x800507E0
    // 0x80051DD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800507E0(rdram, ctx);
        goto after_3;
    // 0x80051DD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80051DD4: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x80051DD8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80051DDC: jal         0x800571DC
    // 0x80051DE0: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    func_800571DC(rdram, ctx);
        goto after_4;
    // 0x80051DE0: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    after_4:
    // 0x80051DE4: lui         $t2, 0x8005
    ctx->r10 = S32(0X8005 << 16);
    // 0x80051DE8: addiu       $t2, $t2, 0x169C
    ctx->r10 = ADD32(ctx->r10, 0X169C);
    // 0x80051DEC: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80051DF0: sw          $t2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r10;
    // 0x80051DF4: sw          $s0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r16;
    // 0x80051DF8: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80051DFC: lw          $a0, 0x3190($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3190);
    // 0x80051E00: jal         0x80058B90
    // 0x80051E04: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80058B90(rdram, ctx);
        goto after_5;
    // 0x80051E04: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80051E08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80051E0C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80051E10: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80051E14: jr          $ra
    // 0x80051E18: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    TRACE_RETURN()
    return;
    // 0x80051E18: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80051E20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80051E20: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80051E24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80051E28: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x80051E2C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80051E30: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x80051E34: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80051E38: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x80051E3C: jal         0x8005702C
    // 0x80051E40: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8005702C(rdram, ctx);
        goto after_0;
    // 0x80051E40: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80051E44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80051E48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80051E4C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80051E60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80051E60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80051E64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80051E68: jal         0x80059290
    // 0x80051E6C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80051E6C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80051E70: lw          $s0, 0x8($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X8);
    // 0x80051E74: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80051E78: beq         $s0, $zero, L_80051EC4
    if (ctx->r16 == 0) {
        // 0x80051E7C: nop
    
            goto L_80051EC4;
    }
    // 0x80051E7C: nop

L_80051E80:
    // 0x80051E80: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
    // 0x80051E84: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x80051E88: bne         $s3, $t6, L_80051EBC
    if (ctx->r19 != ctx->r14) {
        // 0x80051E8C: nop
    
            goto L_80051EBC;
    }
    // 0x80051E8C: nop

    // 0x80051E90: beq         $s1, $zero, L_80051EA8
    if (ctx->r17 == 0) {
        // 0x80051E94: nop
    
            goto L_80051EA8;
    }
    // 0x80051E94: nop

    // 0x80051E98: lw          $t7, 0x8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8);
    // 0x80051E9C: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80051EA0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80051EA4: sw          $t9, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r25;
L_80051EA8:
    // 0x80051EA8: jal         0x800526C0
    // 0x80051EAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800526C0(rdram, ctx);
        goto after_1;
    // 0x80051EAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80051EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80051EB4: jal         0x800526F0
    // 0x80051EB8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800526F0(rdram, ctx);
        goto after_2;
    // 0x80051EB8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
L_80051EBC:
    // 0x80051EBC: bne         $s1, $zero, L_80051E80
    if (ctx->r17 != 0) {
        // 0x80051EC0: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80051E80;
    }
    // 0x80051EC0: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_80051EC4:
    // 0x80051EC4: jal         0x80059290
    // 0x80051EC8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x80051EC8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_3:
    // 0x80051ECC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80051ED0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80051ED4: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80051EDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80051EDC: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80051EE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80051EE4: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80051EEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80051EEC: addiu       $sp, $sp, -0x108
    ctx->r29 = ADD32(ctx->r29, -0X108);
    // 0x80051EF0: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80051EF4: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80051EF8: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80051EFC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80051F00: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80051F04: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80051F08: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80051F0C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80051F10: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80051F14: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80051F18: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80051F1C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80051F20: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80051F24: ldc1        $f20, -0x6CB0($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, -0X6CB0);
    // 0x80051F28: addiu       $s4, $a0, 0x28
    ctx->r20 = ADD32(ctx->r4, 0X28);
    // 0x80051F2C: addiu       $s7, $a0, 0x14
    ctx->r23 = ADD32(ctx->r4, 0X14);
    // 0x80051F30: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
L_80051F34:
    // 0x80051F34: lh          $v0, 0x28($s6)
    ctx->r2 = MEM_H(ctx->r22, 0X28);
    // 0x80051F38: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80051F3C: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80051F40: bne         $v0, $at, L_80051F60
    if (ctx->r2 != ctx->r1) {
        // 0x80051F44: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_80051F60;
    }
    // 0x80051F44: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80051F48: sh          $t6, 0xF4($sp)
    MEM_H(0XF4, ctx->r29) = ctx->r14;
    // 0x80051F4C: lw          $a2, 0x48($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X48);
    // 0x80051F50: jal         0x8005702C
    // 0x80051F54: addiu       $a1, $sp, 0xF4
    ctx->r5 = ADD32(ctx->r29, 0XF4);
    func_8005702C(rdram, ctx);
        goto after_0;
    // 0x80051F54: addiu       $a1, $sp, 0xF4
    ctx->r5 = ADD32(ctx->r29, 0XF4);
    after_0:
    // 0x80051F58: b           L_800523E4
    // 0x80051F5C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_800523E4;
    // 0x80051F5C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_80051F60:
    // 0x80051F60: lw          $s5, 0x2C($s6)
    ctx->r21 = MEM_W(ctx->r22, 0X2C);
    // 0x80051F64: sltiu       $at, $v0, 0x9
    ctx->r1 = ctx->r2 < 0X9 ? 1 : 0;
    // 0x80051F68: beq         $at, $zero, L_800523E0
    if (ctx->r1 == 0) {
        // 0x80051F6C: lw          $s1, 0x1C($s5)
        ctx->r17 = MEM_W(ctx->r21, 0X1C);
            goto L_800523E0;
    }
    // 0x80051F6C: lw          $s1, 0x1C($s5)
    ctx->r17 = MEM_W(ctx->r21, 0X1C);
    // 0x80051F70: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80051F74: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80051F78: addu        $at, $at, $t7
    gpr jr_addend_80051F80 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80051F7C: lw          $t7, -0x6CA8($at)
    ctx->r15 = ADD32(ctx->r1, -0X6CA8);
    // 0x80051F80: jr          $t7
    // 0x80051F84: nop

    switch (jr_addend_80051F80 >> 2) {
        case 0: goto L_80051F88; break;
        case 1: goto L_800520F0; break;
        case 2: goto L_800521BC; break;
        case 3: goto L_800522A0; break;
        case 4: goto L_80052224; break;
        case 5: goto L_800523E0; break;
        case 6: goto L_80052304; break;
        case 7: goto L_800523B0; break;
        case 8: goto L_80052278; break;
        default: switch_error(__func__, 0x80051F80, 0x80079358);
    }
    // 0x80051F84: nop

L_80051F88:
    // 0x80051F88: lw          $t8, 0x28($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X28);
    // 0x80051F8C: bnel        $t8, $zero, L_800523E4
    if (ctx->r24 != 0) {
        // 0x80051F90: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_800523E4;
    }
    goto skip_0;
    // 0x80051F90: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    skip_0:
    // 0x80051F94: beq         $s1, $zero, L_800523E0
    if (ctx->r17 == 0) {
        // 0x80051F98: or          $a1, $s5, $zero
        ctx->r5 = ctx->r21 | 0;
            goto L_800523E0;
    }
    // 0x80051F98: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80051F9C: sh          $zero, 0xE2($sp)
    MEM_H(0XE2, ctx->r29) = 0;
    // 0x80051FA0: lh          $t9, 0x20($s5)
    ctx->r25 = MEM_H(ctx->r21, 0X20);
    // 0x80051FA4: sb          $zero, 0xE4($sp)
    MEM_B(0XE4, ctx->r29) = 0;
    // 0x80051FA8: addiu       $a2, $sp, 0xE0
    ctx->r6 = ADD32(ctx->r29, 0XE0);
    // 0x80051FAC: sh          $t9, 0xE0($sp)
    MEM_H(0XE0, ctx->r29) = ctx->r25;
    // 0x80051FB0: jal         0x80058F28
    // 0x80051FB4: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    func_80058F28(rdram, ctx);
        goto after_1;
    // 0x80051FB4: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    after_1:
    // 0x80051FB8: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80051FBC: lh          $t7, 0x2C($s5)
    ctx->r15 = MEM_H(ctx->r21, 0X2C);
    // 0x80051FC0: addiu       $at, $zero, 0x7F
    ctx->r1 = ADD32(0, 0X7F);
    // 0x80051FC4: lbu         $t6, 0xC($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0XC);
    // 0x80051FC8: addiu       $t0, $zero, 0x7F
    ctx->r8 = ADD32(0, 0X7F);
    // 0x80051FCC: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80051FD0: mflo        $t8
    ctx->r24 = lo;
    // 0x80051FD4: nop

    // 0x80051FD8: nop

    // 0x80051FDC: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x80051FE0: mflo        $t9
    ctx->r25 = lo;
    // 0x80051FE4: sh          $t9, 0xBA($sp)
    MEM_H(0XBA, ctx->r29) = ctx->r25;
    // 0x80051FE8: lbu         $t7, 0xC($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0XC);
    // 0x80051FEC: lbu         $t6, 0x2E($s5)
    ctx->r14 = MEM_BU(ctx->r21, 0X2E);
    // 0x80051FF0: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80051FF4: addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
    // 0x80051FF8: sll         $t8, $v1, 16
    ctx->r24 = S32(ctx->r3 << 16);
    // 0x80051FFC: sra         $v1, $t8, 16
    ctx->r3 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80052000: bgtzl       $v1, L_80052010
    if (SIGNED(ctx->r3) > 0) {
        // 0x80052004: slti        $at, $v1, 0x7F
        ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
            goto L_80052010;
    }
    goto skip_1;
    // 0x80052004: slti        $at, $v1, 0x7F
    ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
    skip_1:
    // 0x80052008: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8005200C: slti        $at, $v1, 0x7F
    ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
L_80052010:
    // 0x80052010: beq         $at, $zero, L_80052020
    if (ctx->r1 == 0) {
        // 0x80052014: nop
    
            goto L_80052020;
    }
    // 0x80052014: nop

    // 0x80052018: b           L_80052020
    // 0x8005201C: andi        $t0, $v1, 0xFF
    ctx->r8 = ctx->r3 & 0XFF;
        goto L_80052020;
    // 0x8005201C: andi        $t0, $v1, 0xFF
    ctx->r8 = ctx->r3 & 0XFF;
L_80052020:
    // 0x80052020: lwc1        $f4, 0x24($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X24);
    // 0x80052024: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80052028: swc1        $f4, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f4.u32l;
    // 0x8005202C: lw          $s0, 0x0($a3)
    ctx->r16 = MEM_W(ctx->r7, 0X0);
    // 0x80052030: lw          $a2, 0x8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X8);
    // 0x80052034: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    // 0x80052038: jal         0x80059330
    // 0x8005203C: sb          $t0, 0xD7($sp)
    MEM_B(0XD7, ctx->r29) = ctx->r8;
    func_80059330(rdram, ctx);
        goto after_2;
    // 0x8005203C: sb          $t0, 0xD7($sp)
    MEM_B(0XD7, ctx->r29) = ctx->r8;
    after_2:
    // 0x80052040: lbu         $a2, 0xD7($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0XD7);
    // 0x80052044: sw          $fp, 0x28($s5)
    MEM_W(0X28, ctx->r21) = ctx->r30;
    // 0x80052048: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    // 0x8005204C: jal         0x80059160
    // 0x80052050: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_80059160(rdram, ctx);
        goto after_3;
    // 0x80052050: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_3:
    // 0x80052054: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    // 0x80052058: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8005205C: lh          $a2, 0xBA($sp)
    ctx->r6 = MEM_H(ctx->r29, 0XBA);
    // 0x80052060: jal         0x80058D10
    // 0x80052064: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_80058D10(rdram, ctx);
        goto after_4;
    // 0x80052064: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_4:
    // 0x80052068: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    // 0x8005206C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80052070: jal         0x80058DB0
    // 0x80052074: lw          $a2, 0xD0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XD0);
    func_80058DB0(rdram, ctx);
        goto after_5;
    // 0x80052074: lw          $a2, 0xD0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XD0);
    after_5:
    // 0x80052078: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    // 0x8005207C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80052080: jal         0x800591F0
    // 0x80052084: lbu         $a2, 0x2F($s5)
    ctx->r6 = MEM_BU(ctx->r21, 0X2F);
    func_800591F0(rdram, ctx);
        goto after_6;
    // 0x80052084: lbu         $a2, 0x2F($s5)
    ctx->r6 = MEM_BU(ctx->r21, 0X2F);
    after_6:
    // 0x80052088: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x8005208C: sh          $t6, 0xC0($sp)
    MEM_H(0XC0, ctx->r29) = ctx->r14;
    // 0x80052090: sw          $s5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r21;
    // 0x80052094: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80052098: lwc1        $f2, 0x24($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X24);
    // 0x8005209C: lui         $a2, 0x7FFF
    ctx->r6 = S32(0X7FFF << 16);
    // 0x800520A0: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x800520A4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800520A8: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800520AC: nop

    // 0x800520B0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800520B4: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800520B8: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x800520BC: c.lt.d      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.d < ctx->f0.d;
    // 0x800520C0: nop

    // 0x800520C4: bc1fl       L_800520D8
    if (!c1cs) {
        // 0x800520C8: trunc.w.d   $f4, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_D(ctx->f0.d);
            goto L_800520D8;
    }
    goto skip_2;
    // 0x800520C8: trunc.w.d   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_D(ctx->f0.d);
    skip_2:
    // 0x800520CC: b           L_800520E0
    // 0x800520D0: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
        goto L_800520E0;
    // 0x800520D0: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x800520D4: trunc.w.d   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_D(ctx->f0.d);
L_800520D8:
    // 0x800520D8: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800520DC: nop

L_800520E0:
    // 0x800520E0: jal         0x8005702C
    // 0x800520E4: addiu       $a1, $sp, 0xC0
    ctx->r5 = ADD32(ctx->r29, 0XC0);
    func_8005702C(rdram, ctx);
        goto after_7;
    // 0x800520E4: addiu       $a1, $sp, 0xC0
    ctx->r5 = ADD32(ctx->r29, 0XC0);
    after_7:
    // 0x800520E8: b           L_800523E4
    // 0x800520EC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_800523E4;
    // 0x800520EC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_800520F0:
    // 0x800520F0: lw          $t9, 0x28($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X28);
    // 0x800520F4: bnel        $fp, $t9, L_800523E4
    if (ctx->r30 != ctx->r25) {
        // 0x800520F8: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_800523E4;
    }
    goto skip_3;
    // 0x800520F8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    skip_3:
    // 0x800520FC: beq         $s1, $zero, L_800523E0
    if (ctx->r17 == 0) {
        // 0x80052100: or          $a1, $s5, $zero
        ctx->r5 = ctx->r21 | 0;
            goto L_800523E0;
    }
    // 0x80052100: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80052104: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80052108: lwc1        $f2, 0x24($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X24);
    // 0x8005210C: lui         $a3, 0x7FFF
    ctx->r7 = S32(0X7FFF << 16);
    // 0x80052110: lw          $v0, 0x8($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X8);
    // 0x80052114: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80052118: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8005211C: nop

    // 0x80052120: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80052124: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80052128: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x8005212C: c.lt.d      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.d < ctx->f0.d;
    // 0x80052130: nop

    // 0x80052134: bc1fl       L_80052148
    if (!c1cs) {
        // 0x80052138: trunc.w.d   $f4, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_D(ctx->f0.d);
            goto L_80052148;
    }
    goto skip_4;
    // 0x80052138: trunc.w.d   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_D(ctx->f0.d);
    skip_4:
    // 0x8005213C: b           L_80052150
    // 0x80052140: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
        goto L_80052150;
    // 0x80052140: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
    // 0x80052144: trunc.w.d   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_D(ctx->f0.d);
L_80052148:
    // 0x80052148: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8005214C: nop

L_80052150:
    // 0x80052150: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80052154: jal         0x80058D10
    // 0x80052158: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    func_80058D10(rdram, ctx);
        goto after_8;
    // 0x80052158: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    after_8:
    // 0x8005215C: beq         $s0, $zero, L_8005218C
    if (ctx->r16 == 0) {
        // 0x80052160: or          $a1, $s5, $zero
        ctx->r5 = ctx->r21 | 0;
            goto L_8005218C;
    }
    // 0x80052160: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80052164: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x80052168: sh          $t8, 0xC0($sp)
    MEM_H(0XC0, ctx->r29) = ctx->r24;
    // 0x8005216C: sw          $s5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r21;
    // 0x80052170: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80052174: addiu       $a1, $sp, 0xC0
    ctx->r5 = ADD32(ctx->r29, 0XC0);
    // 0x80052178: jal         0x8005702C
    // 0x8005217C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_8005702C(rdram, ctx);
        goto after_9;
    // 0x8005217C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_9:
    // 0x80052180: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80052184: b           L_800523E0
    // 0x80052188: sw          $t9, 0x28($s5)
    MEM_W(0X28, ctx->r21) = ctx->r25;
        goto L_800523E0;
    // 0x80052188: sw          $t9, 0x28($s5)
    MEM_W(0X28, ctx->r21) = ctx->r25;
L_8005218C:
    // 0x8005218C: jal         0x80058BE0
    // 0x80052190: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    func_80058BE0(rdram, ctx);
        goto after_10;
    // 0x80052190: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    after_10:
    // 0x80052194: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    // 0x80052198: jal         0x80058C60
    // 0x8005219C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_80058C60(rdram, ctx);
        goto after_11;
    // 0x8005219C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_11:
    // 0x800521A0: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x800521A4: or          $s3, $s5, $zero
    ctx->r19 = ctx->r21 | 0;
    // 0x800521A8: jal         0x80051E60
    // 0x800521AC: sw          $s4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r20;
    func_80051E60(rdram, ctx);
        goto after_12;
    // 0x800521AC: sw          $s4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r20;
    after_12:
    // 0x800521B0: lw          $s4, 0x4C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X4C);
    // 0x800521B4: b           L_800523E0
    // 0x800521B8: sw          $zero, 0x28($s5)
    MEM_W(0X28, ctx->r21) = 0;
        goto L_800523E0;
    // 0x800521B8: sw          $zero, 0x28($s5)
    MEM_W(0X28, ctx->r21) = 0;
L_800521BC:
    // 0x800521BC: lw          $t7, 0x28($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X28);
    // 0x800521C0: lbu         $t6, 0x8($s4)
    ctx->r14 = MEM_BU(ctx->r20, 0X8);
    // 0x800521C4: bne         $fp, $t7, L_800523E0
    if (ctx->r30 != ctx->r15) {
        // 0x800521C8: sb          $t6, 0x2E($s5)
        MEM_B(0X2E, ctx->r21) = ctx->r14;
            goto L_800523E0;
    }
    // 0x800521C8: sb          $t6, 0x2E($s5)
    MEM_B(0X2E, ctx->r21) = ctx->r14;
    // 0x800521CC: beq         $s1, $zero, L_800523E0
    if (ctx->r17 == 0) {
        // 0x800521D0: or          $a1, $s5, $zero
        ctx->r5 = ctx->r21 | 0;
            goto L_800523E0;
    }
    // 0x800521D0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800521D4: lbu         $t9, 0xC($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0XC);
    // 0x800521D8: andi        $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 & 0XFF;
    // 0x800521DC: addiu       $t0, $zero, 0x7F
    ctx->r8 = ADD32(0, 0X7F);
    // 0x800521E0: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x800521E4: addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
    // 0x800521E8: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x800521EC: sra         $v1, $t6, 16
    ctx->r3 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800521F0: bgtzl       $v1, L_80052200
    if (SIGNED(ctx->r3) > 0) {
        // 0x800521F4: slti        $at, $v1, 0x7F
        ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
            goto L_80052200;
    }
    goto skip_5;
    // 0x800521F4: slti        $at, $v1, 0x7F
    ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
    skip_5:
    // 0x800521F8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800521FC: slti        $at, $v1, 0x7F
    ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
L_80052200:
    // 0x80052200: beq         $at, $zero, L_80052210
    if (ctx->r1 == 0) {
        // 0x80052204: nop
    
            goto L_80052210;
    }
    // 0x80052204: nop

    // 0x80052208: b           L_80052210
    // 0x8005220C: andi        $t0, $v1, 0xFF
    ctx->r8 = ctx->r3 & 0XFF;
        goto L_80052210;
    // 0x8005220C: andi        $t0, $v1, 0xFF
    ctx->r8 = ctx->r3 & 0XFF;
L_80052210:
    // 0x80052210: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    // 0x80052214: jal         0x80059160
    // 0x80052218: andi        $a2, $t0, 0xFF
    ctx->r6 = ctx->r8 & 0XFF;
    func_80059160(rdram, ctx);
        goto after_13;
    // 0x80052218: andi        $a2, $t0, 0xFF
    ctx->r6 = ctx->r8 & 0XFF;
    after_13:
    // 0x8005221C: b           L_800523E4
    // 0x80052220: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_800523E4;
    // 0x80052220: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_80052224:
    // 0x80052224: lwc1        $f0, 0x8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X8);
    // 0x80052228: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8005222C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80052230: swc1        $f0, 0x24($s5)
    MEM_W(0X24, ctx->r21) = ctx->f0.u32l;
    // 0x80052234: ldc1        $f8, -0x6C80($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X6C80);
    // 0x80052238: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8005223C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80052240: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x80052244: nop

    // 0x80052248: bc1fl       L_8005225C
    if (!c1cs) {
        // 0x8005224C: lw          $t8, 0x28($s5)
        ctx->r24 = MEM_W(ctx->r21, 0X28);
            goto L_8005225C;
    }
    goto skip_6;
    // 0x8005224C: lw          $t8, 0x28($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X28);
    skip_6:
    // 0x80052250: lwc1        $f10, -0x6C78($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X6C78);
    // 0x80052254: swc1        $f10, 0x24($s5)
    MEM_W(0X24, ctx->r21) = ctx->f10.u32l;
    // 0x80052258: lw          $t8, 0x28($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X28);
L_8005225C:
    // 0x8005225C: bnel        $fp, $t8, L_800523E4
    if (ctx->r30 != ctx->r24) {
        // 0x80052260: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_800523E4;
    }
    goto skip_7;
    // 0x80052260: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    skip_7:
    // 0x80052264: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    // 0x80052268: jal         0x80058DB0
    // 0x8005226C: lw          $a2, 0x24($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X24);
    func_80058DB0(rdram, ctx);
        goto after_14;
    // 0x8005226C: lw          $a2, 0x24($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X24);
    after_14:
    // 0x80052270: b           L_800523E4
    // 0x80052274: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_800523E4;
    // 0x80052274: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_80052278:
    // 0x80052278: lw          $t6, 0x28($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X28);
    // 0x8005227C: lbu         $t9, 0x8($s4)
    ctx->r25 = MEM_BU(ctx->r20, 0X8);
    // 0x80052280: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80052284: bne         $fp, $t6, L_800523E0
    if (ctx->r30 != ctx->r14) {
        // 0x80052288: sb          $t9, 0x2F($s5)
        MEM_B(0X2F, ctx->r21) = ctx->r25;
            goto L_800523E0;
    }
    // 0x80052288: sb          $t9, 0x2F($s5)
    MEM_B(0X2F, ctx->r21) = ctx->r25;
    // 0x8005228C: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    // 0x80052290: jal         0x800591F0
    // 0x80052294: andi        $a2, $t9, 0xFF
    ctx->r6 = ctx->r25 & 0XFF;
    func_800591F0(rdram, ctx);
        goto after_15;
    // 0x80052294: andi        $a2, $t9, 0xFF
    ctx->r6 = ctx->r25 & 0XFF;
    after_15:
    // 0x80052298: b           L_800523E4
    // 0x8005229C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_800523E4;
    // 0x8005229C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_800522A0:
    // 0x800522A0: lw          $t8, 0x28($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X28);
    // 0x800522A4: lh          $t7, 0x8($s4)
    ctx->r15 = MEM_H(ctx->r20, 0X8);
    // 0x800522A8: bne         $fp, $t8, L_800523E0
    if (ctx->r30 != ctx->r24) {
        // 0x800522AC: sh          $t7, 0x2C($s5)
        MEM_H(0X2C, ctx->r21) = ctx->r15;
            goto L_800523E0;
    }
    // 0x800522AC: sh          $t7, 0x2C($s5)
    MEM_H(0X2C, ctx->r21) = ctx->r15;
    // 0x800522B0: beql        $s1, $zero, L_800523E4
    if (ctx->r17 == 0) {
        // 0x800522B4: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_800523E4;
    }
    goto skip_8;
    // 0x800522B4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    skip_8:
    // 0x800522B8: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800522BC: lh          $t7, 0x2C($s5)
    ctx->r15 = MEM_H(ctx->r21, 0X2C);
    // 0x800522C0: addiu       $at, $zero, 0x7F
    ctx->r1 = ADD32(0, 0X7F);
    // 0x800522C4: lbu         $t6, 0xD($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0XD);
    // 0x800522C8: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    // 0x800522CC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800522D0: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800522D4: addiu       $a3, $zero, 0x3E8
    ctx->r7 = ADD32(0, 0X3E8);
    // 0x800522D8: mflo        $t0
    ctx->r8 = lo;
    // 0x800522DC: nop

    // 0x800522E0: nop

    // 0x800522E4: div         $zero, $t0, $at
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r1)));
    // 0x800522E8: mflo        $t8
    ctx->r24 = lo;
    // 0x800522EC: sll         $a2, $t8, 16
    ctx->r6 = S32(ctx->r24 << 16);
    // 0x800522F0: sra         $t9, $a2, 16
    ctx->r25 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800522F4: jal         0x80058D10
    // 0x800522F8: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    func_80058D10(rdram, ctx);
        goto after_16;
    // 0x800522F8: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_16:
    // 0x800522FC: b           L_800523E4
    // 0x80052300: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_800523E4;
    // 0x80052300: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_80052304:
    // 0x80052304: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80052308: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005230C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80052310: lw          $v1, 0x4($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X4);
    // 0x80052314: beql        $v1, $at, L_800523E4
    if (ctx->r3 == ctx->r1) {
        // 0x80052318: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_800523E4;
    }
    goto skip_9;
    // 0x80052318: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    skip_9:
    // 0x8005231C: lbu         $t6, 0xD($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0XD);
    // 0x80052320: lh          $t7, 0x2C($s5)
    ctx->r15 = MEM_H(ctx->r21, 0X2C);
    // 0x80052324: addiu       $at, $zero, 0x7F
    ctx->r1 = ADD32(0, 0X7F);
    // 0x80052328: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x8005232C: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80052330: lwc1        $f2, 0x24($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X24);
    // 0x80052334: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80052338: lui         $a3, 0x7FFF
    ctx->r7 = S32(0X7FFF << 16);
    // 0x8005233C: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80052340: mflo        $t0
    ctx->r8 = lo;
    // 0x80052344: nop

    // 0x80052348: nop

    // 0x8005234C: div         $zero, $t0, $at
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r1)));
    // 0x80052350: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x80052354: mflo        $t0
    ctx->r8 = lo;
    // 0x80052358: c.lt.d      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.d < ctx->f0.d;
    // 0x8005235C: sll         $a2, $t0, 16
    ctx->r6 = S32(ctx->r8 << 16);
    // 0x80052360: sra         $t6, $a2, 16
    ctx->r14 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80052364: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80052368: bc1fl       L_8005237C
    if (!c1cs) {
        // 0x8005236C: trunc.w.d   $f10, $f0
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_D(ctx->f0.d);
            goto L_8005237C;
    }
    goto skip_10;
    // 0x8005236C: trunc.w.d   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_D(ctx->f0.d);
    skip_10:
    // 0x80052370: b           L_80052384
    // 0x80052374: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
        goto L_80052384;
    // 0x80052374: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
    // 0x80052378: trunc.w.d   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_D(ctx->f0.d);
L_8005237C:
    // 0x8005237C: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80052380: nop

L_80052384:
    // 0x80052384: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80052388: jal         0x80058D10
    // 0x8005238C: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    func_80058D10(rdram, ctx);
        goto after_17;
    // 0x8005238C: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    after_17:
    // 0x80052390: sh          $fp, 0xC0($sp)
    MEM_H(0XC0, ctx->r29) = ctx->r30;
    // 0x80052394: sw          $s5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r21;
    // 0x80052398: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8005239C: addiu       $a1, $sp, 0xC0
    ctx->r5 = ADD32(ctx->r29, 0XC0);
    // 0x800523A0: jal         0x8005702C
    // 0x800523A4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_8005702C(rdram, ctx);
        goto after_18;
    // 0x800523A4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_18:
    // 0x800523A8: b           L_800523E4
    // 0x800523AC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_800523E4;
    // 0x800523AC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_800523B0:
    // 0x800523B0: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    // 0x800523B4: jal         0x80058BE0
    // 0x800523B8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_80058BE0(rdram, ctx);
        goto after_19;
    // 0x800523B8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_19:
    // 0x800523BC: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    // 0x800523C0: jal         0x80058C60
    // 0x800523C4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_80058C60(rdram, ctx);
        goto after_20;
    // 0x800523C4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_20:
    // 0x800523C8: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x800523CC: or          $s3, $s5, $zero
    ctx->r19 = ctx->r21 | 0;
    // 0x800523D0: jal         0x80051E60
    // 0x800523D4: sw          $s4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r20;
    func_80051E60(rdram, ctx);
        goto after_21;
    // 0x800523D4: sw          $s4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r20;
    after_21:
    // 0x800523D8: lw          $s4, 0x4C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X4C);
    // 0x800523DC: sw          $zero, 0x28($s5)
    MEM_W(0X28, ctx->r21) = 0;
L_800523E0:
    // 0x800523E0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_800523E4:
    // 0x800523E4: jal         0x80057150
    // 0x800523E8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_80057150(rdram, ctx);
        goto after_22;
    // 0x800523E8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_22:
    // 0x800523EC: beq         $v0, $zero, L_80051F34
    if (ctx->r2 == 0) {
        // 0x800523F0: sw          $v0, 0x4C($s6)
        MEM_W(0X4C, ctx->r22) = ctx->r2;
            goto L_80051F34;
    }
    // 0x800523F0: sw          $v0, 0x4C($s6)
    MEM_W(0X4C, ctx->r22) = ctx->r2;
    // 0x800523F4: lw          $t7, 0x50($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X50);
    // 0x800523F8: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800523FC: sw          $t8, 0x50($s6)
    MEM_W(0X50, ctx->r22) = ctx->r24;
    // 0x80052400: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80052404: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80052408: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8005240C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80052410: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80052414: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80052418: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8005241C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80052420: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80052424: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80052428: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8005242C: jr          $ra
    // 0x80052430: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
    TRACE_RETURN()
    return;
    // 0x80052430: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
;}
RECOMP_FUNC void func_80052434(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80052434: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80052438: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005243C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80052440: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80052444: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80052448: addiu       $t8, $zero, 0x3E80
    ctx->r24 = ADD32(0, 0X3E80);
    // 0x8005244C: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x80052450: sw          $t7, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r15;
    // 0x80052454: sw          $t8, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r24;
    // 0x80052458: sw          $t6, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r14;
    // 0x8005245C: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80052460: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80052464: lw          $a2, 0x8($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X8);
    // 0x80052468: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8005246C: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
    // 0x80052470: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x80052474: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80052478: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x8005247C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80052480: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80052484: jal         0x800507E0
    // 0x80052488: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800507E0(rdram, ctx);
        goto after_0;
    // 0x80052488: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x8005248C: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80052490: sw          $v0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r2;
    // 0x80052494: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80052498: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8005249C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800524A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800524A4: beq         $t2, $zero, L_800524C8
    if (ctx->r10 == 0) {
        // 0x800524A8: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_800524C8;
    }
    // 0x800524A8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800524AC: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
L_800524B0:
    // 0x800524B0: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800524B4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800524B8: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // 0x800524BC: sltu        $at, $v1, $t3
    ctx->r1 = ctx->r3 < ctx->r11 ? 1 : 0;
    // 0x800524C0: bnel        $at, $zero, L_800524B0
    if (ctx->r1 != 0) {
        // 0x800524C4: sw          $zero, 0x1C($a0)
        MEM_W(0X1C, ctx->r4) = 0;
            goto L_800524B0;
    }
    goto skip_0;
    // 0x800524C4: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    skip_0:
L_800524C8:
    // 0x800524C8: lw          $t4, 0x4($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X4);
    // 0x800524CC: lw          $a2, 0x8($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X8);
    // 0x800524D0: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x800524D4: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x800524D8: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800524DC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800524E0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800524E4: jal         0x800507E0
    // 0x800524E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800507E0(rdram, ctx);
        goto after_1;
    // 0x800524E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x800524EC: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x800524F0: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    // 0x800524F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800524F8: lw          $a2, 0x4($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X4);
    // 0x800524FC: jal         0x800571DC
    // 0x80052500: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800571DC(rdram, ctx);
        goto after_2;
    // 0x80052500: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_2:
    // 0x80052504: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x80052508: lw          $a0, 0x3190($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X3190);
    // 0x8005250C: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x80052510: addiu       $t7, $t7, 0x1EEC
    ctx->r15 = ADD32(ctx->r15, 0X1EEC);
    // 0x80052514: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80052518: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    // 0x8005251C: sw          $s0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r16;
    // 0x80052520: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80052524: jal         0x80058B90
    // 0x80052528: sw          $a0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r4;
    func_80058B90(rdram, ctx);
        goto after_3;
    // 0x80052528: sw          $a0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r4;
    after_3:
    // 0x8005252C: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x80052530: sh          $t8, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r24;
    // 0x80052534: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x80052538: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8005253C: jal         0x8005702C
    // 0x80052540: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_8005702C(rdram, ctx);
        goto after_4;
    // 0x80052540: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_4:
    // 0x80052544: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80052548: jal         0x80057150
    // 0x8005254C: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    func_80057150(rdram, ctx);
        goto after_5;
    // 0x8005254C: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    after_5:
    // 0x80052550: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
    // 0x80052554: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80052558: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005255C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80052560: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800526C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800526C0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800526C4: beql        $v0, $zero, L_800526D8
    if (ctx->r2 == 0) {
        // 0x800526C8: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_800526D8;
    }
    goto skip_0;
    // 0x800526C8: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_0:
    // 0x800526CC: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800526D0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800526D4: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_800526D8:
    // 0x800526D8: beq         $v0, $zero, L_800526E8
    if (ctx->r2 == 0) {
        // 0x800526DC: nop
    
            goto L_800526E8;
    }
    // 0x800526DC: nop

    // 0x800526E0: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800526E4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_800526E8:
    // 0x800526E8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800526F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800526F0: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800526F4: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x800526F8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800526FC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80052700: beq         $v0, $zero, L_8005270C
    if (ctx->r2 == 0) {
        // 0x80052704: nop
    
            goto L_8005270C;
    }
    // 0x80052704: nop

    // 0x80052708: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
L_8005270C:
    // 0x8005270C: jr          $ra
    // 0x80052710: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    TRACE_RETURN()
    return;
    // 0x80052710: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
;}
RECOMP_FUNC void func_80052714(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80052714: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x80052718: lw          $t6, 0x3190($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3190);
    // 0x8005271C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80052720: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80052724: beql        $t6, $zero, L_80052740
    if (ctx->r14 == 0) {
        // 0x80052728: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80052740;
    }
    goto skip_0;
    // 0x80052728: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8005272C: jal         0x800593C0
    // 0x80052730: nop

    func_800593C0(rdram, ctx);
        goto after_0;
    // 0x80052730: nop

    after_0:
    // 0x80052734: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80052738: sw          $zero, 0x3190($at)
    MEM_W(0X3190, ctx->r1) = 0;
    // 0x8005273C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80052740:
    // 0x80052740: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80052744: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005274C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005274C: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x80052750: addiu       $v0, $v0, 0x3190
    ctx->r2 = ADD32(ctx->r2, 0X3190);
    // 0x80052754: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80052758: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005275C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80052760: bnel        $t6, $zero, L_80052774
    if (ctx->r14 != 0) {
        // 0x80052764: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80052774;
    }
    goto skip_0;
    // 0x80052764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80052768: jal         0x80053BC0
    // 0x8005276C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    func_80053BC0(rdram, ctx);
        goto after_0;
    // 0x8005276C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    after_0:
    // 0x80052770: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80052774:
    // 0x80052774: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80052778: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80052900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80052900: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80052904: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80052908: beq         $a0, $zero, L_8005293C
    if (ctx->r4 == 0) {
        // 0x8005290C: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_8005293C;
    }
    // 0x8005290C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80052910: jal         0x80059890
    // 0x80052914: nop

    osViGetCurrentFramebuffer_recomp(rdram, ctx);
        goto after_0;
    // 0x80052914: nop

    after_0:
    // 0x80052918: jal         0x800598D0
    // 0x8005291C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    osViGetNextFramebuffer_recomp(rdram, ctx);
        goto after_1;
    // 0x8005291C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x80052920: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80052924: beq         $v0, $t7, L_80052934
    if (ctx->r2 == ctx->r15) {
        // 0x80052928: nop
    
            goto L_80052934;
    }
    // 0x80052928: nop

    // 0x8005292C: b           L_80052940
    // 0x80052930: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80052940;
    // 0x80052930: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80052934:
    // 0x80052934: b           L_80052940
    // 0x80052938: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
        goto L_80052940;
    // 0x80052938: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_8005293C:
    // 0x8005293C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80052940:
    // 0x80052940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80052944: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80052948: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80052950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80052950: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80052954: beq         $s0, $zero, L_800529A4
    if (ctx->r16 == 0) {
        // 0x80052958: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800529A4;
    }
    // 0x80052958: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005295C: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
    // 0x80052960: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80052964: bnel        $t6, $at, L_80052978
    if (ctx->r14 != ctx->r1) {
        // 0x80052968: lw          $t7, 0x4($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X4);
            goto L_80052978;
    }
    goto skip_0;
    // 0x80052968: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    skip_0:
    // 0x8005296C: jal         0x80059960
    // 0x80052970: nop

    func_80059960(rdram, ctx);
        goto after_0;
    // 0x80052970: nop

    after_0:
    // 0x80052974: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
L_80052978:
    // 0x80052978: addiu       $at, $zero, -0x31
    ctx->r1 = ADD32(0, -0X31);
    // 0x8005297C: addiu       $s2, $s0, 0x10
    ctx->r18 = ADD32(ctx->r16, 0X10);
    // 0x80052980: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80052984: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x80052988: jal         0x80059AAC
    // 0x8005298C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    osSpTaskLoad_recomp(rdram, ctx);
        goto after_1;
    // 0x8005298C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x80052990: jal         0x80059C3C
    // 0x80052994: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    osSpTaskStartGo_recomp(rdram, ctx);
        goto after_2;
    // 0x80052994: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x80052998: bne         $s0, $s1, L_800529A4
    if (ctx->r16 != ctx->r17) {
        // 0x8005299C: sw          $s0, 0x274($s3)
        MEM_W(0X274, ctx->r19) = ctx->r16;
            goto L_800529A4;
    }
    // 0x8005299C: sw          $s0, 0x274($s3)
    MEM_W(0X274, ctx->r19) = ctx->r16;
    // 0x800529A0: sw          $s1, 0x278($s3)
    MEM_W(0X278, ctx->r19) = ctx->r17;
L_800529A4:
    // 0x800529A4: beql        $s1, $zero, L_800529E4
    if (ctx->r17 == 0) {
        // 0x800529A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800529E4;
    }
    goto skip_1;
    // 0x800529A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800529AC: beql        $s1, $s0, L_800529E4
    if (ctx->r17 == ctx->r16) {
        // 0x800529B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800529E4;
    }
    goto skip_2;
    // 0x800529B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800529B4: lw          $t9, 0x3C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X3C);
    // 0x800529B8: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800529BC: lw          $a2, 0x0($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X0);
    // 0x800529C0: jal         0x80059C80
    // 0x800529C4: lw          $a3, 0x4($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X4);
    func_80059C80(rdram, ctx);
        goto after_3;
    // 0x800529C4: lw          $a3, 0x4($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X4);
    after_3:
    // 0x800529C8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800529CC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800529D0: sw          $t6, 0x31A0($at)
    MEM_W(0X31A0, ctx->r1) = ctx->r14;
    // 0x800529D4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800529D8: sw          $zero, 0x31A4($at)
    MEM_W(0X31A4, ctx->r1) = 0;
    // 0x800529DC: sw          $s1, 0x278($s3)
    MEM_W(0X278, ctx->r19) = ctx->r17;
    // 0x800529E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800529E4:
    // 0x800529E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800529E8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800529F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800529F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800529F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800529F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800529FC: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x80052A00: addiu       $t1, $zero, -0x3
    ctx->r9 = ADD32(0, -0X3);
L_80052A04:
    // 0x80052A04: lw          $t6, 0x280($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X280);
    // 0x80052A08: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x80052A0C: lw          $s0, 0x268($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X268);
    // 0x80052A10: beq         $t6, $zero, L_80052A6C
    if (ctx->r14 == 0) {
        // 0x80052A14: lw          $v0, 0x264($t0)
        ctx->r2 = MEM_W(ctx->r8, 0X264);
            goto L_80052A6C;
    }
    // 0x80052A14: lw          $v0, 0x264($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X264);
    // 0x80052A18: andi        $t7, $a3, 0x2
    ctx->r15 = ctx->r7 & 0X2;
    // 0x80052A1C: beql        $t7, $zero, L_80052A70
    if (ctx->r15 == 0) {
        // 0x80052A20: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80052A70;
    }
    goto skip_0;
    // 0x80052A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80052A24: beql        $s0, $zero, L_80052A4C
    if (ctx->r16 == 0) {
        // 0x80052A28: sw          $v0, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r2;
            goto L_80052A4C;
    }
    goto skip_1;
    // 0x80052A28: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    skip_1:
    // 0x80052A2C: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80052A30: and         $v1, $a3, $t1
    ctx->r3 = ctx->r7 & ctx->r9;
    // 0x80052A34: andi        $t9, $t8, 0x10
    ctx->r25 = ctx->r24 & 0X10;
    // 0x80052A38: beql        $t9, $zero, L_80052A4C
    if (ctx->r25 == 0) {
        // 0x80052A3C: sw          $v0, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r2;
            goto L_80052A4C;
    }
    goto skip_2;
    // 0x80052A3C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    skip_2:
    // 0x80052A40: b           L_80052BB0
    // 0x80052A44: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
        goto L_80052BB0;
    // 0x80052A44: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
    // 0x80052A48: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
L_80052A4C:
    // 0x80052A4C: lw          $t3, 0x264($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X264);
    // 0x80052A50: sw          $zero, 0x280($t0)
    MEM_W(0X280, ctx->r8) = 0;
    // 0x80052A54: and         $v1, $a3, $t1
    ctx->r3 = ctx->r7 & ctx->r9;
    // 0x80052A58: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80052A5C: bne         $t4, $zero, L_80052BB0
    if (ctx->r12 != 0) {
        // 0x80052A60: sw          $t4, 0x264($t0)
        MEM_W(0X264, ctx->r8) = ctx->r12;
            goto L_80052BB0;
    }
    // 0x80052A60: sw          $t4, 0x264($t0)
    MEM_W(0X264, ctx->r8) = ctx->r12;
    // 0x80052A64: b           L_80052BB0
    // 0x80052A68: sw          $zero, 0x26C($t0)
    MEM_W(0X26C, ctx->r8) = 0;
        goto L_80052BB0;
    // 0x80052A68: sw          $zero, 0x26C($t0)
    MEM_W(0X26C, ctx->r8) = 0;
L_80052A6C:
    // 0x80052A6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80052A70:
    // 0x80052A70: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80052A74: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80052A78: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80052A7C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80052A80: jal         0x80052900
    // 0x80052A84: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    func_80052900(rdram, ctx);
        goto after_0;
    // 0x80052A84: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    after_0:
    // 0x80052A88: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80052A8C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80052A90: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80052A94: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80052A98: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80052A9C: addiu       $t1, $zero, -0x3
    ctx->r9 = ADD32(0, -0X3);
    // 0x80052AA0: beq         $v0, $zero, L_80052BB0
    if (ctx->r2 == 0) {
        // 0x80052AA4: addiu       $t2, $zero, -0x2
        ctx->r10 = ADD32(0, -0X2);
            goto L_80052BB0;
    }
    // 0x80052AA4: addiu       $t2, $zero, -0x2
    ctx->r10 = ADD32(0, -0X2);
    // 0x80052AA8: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80052AAC: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x80052AB0: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80052AB4: sltiu       $at, $t8, 0x7
    ctx->r1 = ctx->r24 < 0X7 ? 1 : 0;
    // 0x80052AB8: beq         $at, $zero, L_80052BB0
    if (ctx->r1 == 0) {
        // 0x80052ABC: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80052BB0;
    }
    // 0x80052ABC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80052AC0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80052AC4: addu        $at, $at, $t8
    gpr jr_addend_80052ACC = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80052AC8: lw          $t8, -0x6C70($at)
    ctx->r24 = ADD32(ctx->r1, -0X6C70);
    // 0x80052ACC: jr          $t8
    // 0x80052AD0: nop

    switch (jr_addend_80052ACC >> 2) {
        case 0: goto L_80052BB0; break;
        case 1: goto L_80052B5C; break;
        case 2: goto L_80052AD4; break;
        case 3: goto L_80052BB0; break;
        case 4: goto L_80052BB0; break;
        case 5: goto L_80052B5C; break;
        case 6: goto L_80052B5C; break;
        default: switch_error(__func__, 0x80052ACC, 0x80079390);
    }
    // 0x80052AD0: nop

L_80052AD4:
    // 0x80052AD4: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x80052AD8: andi        $t4, $a3, 0x2
    ctx->r12 = ctx->r7 & 0X2;
    // 0x80052ADC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80052AE0: andi        $t3, $t9, 0x20
    ctx->r11 = ctx->r25 & 0X20;
    // 0x80052AE4: beq         $t3, $zero, L_80052B2C
    if (ctx->r11 == 0) {
        // 0x80052AE8: nop
    
            goto L_80052B2C;
    }
    // 0x80052AE8: nop

    // 0x80052AEC: beq         $t4, $zero, L_80052BB0
    if (ctx->r12 == 0) {
        // 0x80052AF0: nop
    
            goto L_80052BB0;
    }
    // 0x80052AF0: nop

    // 0x80052AF4: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
    // 0x80052AF8: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x80052AFC: and         $v1, $a3, $t1
    ctx->r3 = ctx->r7 & ctx->r9;
    // 0x80052B00: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x80052B04: beql        $t6, $zero, L_80052B18
    if (ctx->r14 == 0) {
        // 0x80052B08: lw          $t7, 0x268($t0)
        ctx->r15 = MEM_W(ctx->r8, 0X268);
            goto L_80052B18;
    }
    goto skip_3;
    // 0x80052B08: lw          $t7, 0x268($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X268);
    skip_3:
    // 0x80052B0C: sw          $s0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r16;
    // 0x80052B10: and         $v1, $v1, $t2
    ctx->r3 = ctx->r3 & ctx->r10;
    // 0x80052B14: lw          $t7, 0x268($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X268);
L_80052B18:
    // 0x80052B18: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80052B1C: bne         $t8, $zero, L_80052BB0
    if (ctx->r24 != 0) {
        // 0x80052B20: sw          $t8, 0x268($t0)
        MEM_W(0X268, ctx->r8) = ctx->r24;
            goto L_80052BB0;
    }
    // 0x80052B20: sw          $t8, 0x268($t0)
    MEM_W(0X268, ctx->r8) = ctx->r24;
    // 0x80052B24: b           L_80052BB0
    // 0x80052B28: sw          $zero, 0x270($t0)
    MEM_W(0X270, ctx->r8) = 0;
        goto L_80052BB0;
    // 0x80052B28: sw          $zero, 0x270($t0)
    MEM_W(0X270, ctx->r8) = 0;
L_80052B2C:
    // 0x80052B2C: bne         $a3, $at, L_80052BB0
    if (ctx->r7 != ctx->r1) {
        // 0x80052B30: nop
    
            goto L_80052BB0;
    }
    // 0x80052B30: nop

    // 0x80052B34: sw          $s0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r16;
    // 0x80052B38: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
    // 0x80052B3C: lw          $t3, 0x268($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X268);
    // 0x80052B40: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80052B44: and         $v1, $a3, $at
    ctx->r3 = ctx->r7 & ctx->r1;
    // 0x80052B48: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80052B4C: bne         $t4, $zero, L_80052BB0
    if (ctx->r12 != 0) {
        // 0x80052B50: sw          $t4, 0x268($t0)
        MEM_W(0X268, ctx->r8) = ctx->r12;
            goto L_80052BB0;
    }
    // 0x80052B50: sw          $t4, 0x268($t0)
    MEM_W(0X268, ctx->r8) = ctx->r12;
    // 0x80052B54: b           L_80052BB0
    // 0x80052B58: sw          $zero, 0x270($t0)
    MEM_W(0X270, ctx->r8) = 0;
        goto L_80052BB0;
    // 0x80052B58: sw          $zero, 0x270($t0)
    MEM_W(0X270, ctx->r8) = 0;
L_80052B5C:
    // 0x80052B5C: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80052B60: andi        $t7, $a3, 0x2
    ctx->r15 = ctx->r7 & 0X2;
    // 0x80052B64: andi        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 & 0X2;
    // 0x80052B68: beq         $t6, $zero, L_80052B84
    if (ctx->r14 == 0) {
        // 0x80052B6C: andi        $t8, $v0, 0x1
        ctx->r24 = ctx->r2 & 0X1;
            goto L_80052B84;
    }
    // 0x80052B6C: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x80052B70: beq         $t7, $zero, L_80052BB0
    if (ctx->r15 == 0) {
        // 0x80052B74: nop
    
            goto L_80052BB0;
    }
    // 0x80052B74: nop

    // 0x80052B78: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
    // 0x80052B7C: b           L_80052BB0
    // 0x80052B80: and         $v1, $a3, $t1
    ctx->r3 = ctx->r7 & ctx->r9;
        goto L_80052BB0;
    // 0x80052B80: and         $v1, $a3, $t1
    ctx->r3 = ctx->r7 & ctx->r9;
L_80052B84:
    // 0x80052B84: beq         $t8, $zero, L_80052BB0
    if (ctx->r24 == 0) {
        // 0x80052B88: andi        $t9, $a3, 0x1
        ctx->r25 = ctx->r7 & 0X1;
            goto L_80052BB0;
    }
    // 0x80052B88: andi        $t9, $a3, 0x1
    ctx->r25 = ctx->r7 & 0X1;
    // 0x80052B8C: beq         $t9, $zero, L_80052BB0
    if (ctx->r25 == 0) {
        // 0x80052B90: nop
    
            goto L_80052BB0;
    }
    // 0x80052B90: nop

    // 0x80052B94: sw          $s0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r16;
    // 0x80052B98: lw          $t3, 0x268($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X268);
    // 0x80052B9C: and         $v1, $a3, $t2
    ctx->r3 = ctx->r7 & ctx->r10;
    // 0x80052BA0: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80052BA4: bne         $t4, $zero, L_80052BB0
    if (ctx->r12 != 0) {
        // 0x80052BA8: sw          $t4, 0x268($t0)
        MEM_W(0X268, ctx->r8) = ctx->r12;
            goto L_80052BB0;
    }
    // 0x80052BA8: sw          $t4, 0x268($t0)
    MEM_W(0X268, ctx->r8) = ctx->r12;
    // 0x80052BAC: sw          $zero, 0x270($t0)
    MEM_W(0X270, ctx->r8) = 0;
L_80052BB0:
    // 0x80052BB0: beql        $v1, $a3, L_80052BC4
    if (ctx->r3 == ctx->r7) {
        // 0x80052BB4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80052BC4;
    }
    goto skip_4;
    // 0x80052BB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80052BB8: b           L_80052A04
    // 0x80052BBC: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
        goto L_80052A04;
    // 0x80052BBC: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x80052BC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80052BC4:
    // 0x80052BC4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80052BC8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80052BCC: jr          $ra
    // 0x80052BD0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    TRACE_RETURN()
    return;
    // 0x80052BD0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80052BD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80052BD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80052BD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80052BDC: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x80052BE0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80052BE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80052BE8: andi        $t7, $t6, 0x3
    ctx->r15 = ctx->r14 & 0X3;
    // 0x80052BEC: bne         $t7, $zero, L_80052C54
    if (ctx->r15 != 0) {
        // 0x80052BF0: nop
    
            goto L_80052C54;
    }
    // 0x80052BF0: nop

    // 0x80052BF4: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x80052BF8: jal         0x800534A0
    // 0x80052BFC: lw          $a1, 0x54($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X54);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80052BFC: lw          $a1, 0x54($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X54);
    after_0:
    // 0x80052C00: lw          $t8, 0x10($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X10);
    // 0x80052C04: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80052C08: bne         $t8, $at, L_80052C4C
    if (ctx->r24 != ctx->r1) {
        // 0x80052C0C: nop
    
            goto L_80052C4C;
    }
    // 0x80052C0C: nop

    // 0x80052C10: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80052C14: andi        $t9, $v0, 0x40
    ctx->r25 = ctx->r2 & 0X40;
    // 0x80052C18: beq         $t9, $zero, L_80052C4C
    if (ctx->r25 == 0) {
        // 0x80052C1C: andi        $t6, $v0, 0x20
        ctx->r14 = ctx->r2 & 0X20;
            goto L_80052C4C;
    }
    // 0x80052C1C: andi        $t6, $v0, 0x20
    ctx->r14 = ctx->r2 & 0X20;
    // 0x80052C20: beq         $t6, $zero, L_80052C4C
    if (ctx->r14 == 0) {
        // 0x80052C24: lui         $t7, 0x8007
        ctx->r15 = S32(0X8007 << 16);
            goto L_80052C4C;
    }
    // 0x80052C24: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x80052C28: lw          $t7, 0x31A8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X31A8);
    // 0x80052C2C: beq         $t7, $zero, L_80052C44
    if (ctx->r15 == 0) {
        // 0x80052C30: nop
    
            goto L_80052C44;
    }
    // 0x80052C30: nop

    // 0x80052C34: jal         0x80053630
    // 0x80052C38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    osViBlack_recomp(rdram, ctx);
        goto after_1;
    // 0x80052C38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80052C3C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80052C40: sw          $zero, 0x31A8($at)
    MEM_W(0X31A8, ctx->r1) = 0;
L_80052C44:
    // 0x80052C44: jal         0x80059910
    // 0x80052C48: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    osViSwapBuffer_recomp(rdram, ctx);
        goto after_2;
    // 0x80052C48: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    after_2:
L_80052C4C:
    // 0x80052C4C: b           L_80052C54
    // 0x80052C50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80052C54;
    // 0x80052C50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80052C54:
    // 0x80052C54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80052C58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80052C5C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80052C64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80052C64: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80052C6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80052C6C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80052C74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80052C74: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80052C7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80052C7C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80052C84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80052C84: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80052C88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80052C8C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80052C90: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80052C94: lw          $t6, 0x27C($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X27C);
    // 0x80052C98: addiu       $s5, $sp, 0x44
    ctx->r21 = ADD32(ctx->r29, 0X44);
    // 0x80052C9C: addiu       $s3, $s4, 0x78
    ctx->r19 = ADD32(ctx->r20, 0X78);
    // 0x80052CA0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80052CA4: sw          $t7, 0x27C($s4)
    MEM_W(0X27C, ctx->r20) = ctx->r15;
    // 0x80052CA8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80052CAC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80052CB0: jal         0x8004F990
    // 0x80052CB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80052CB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80052CB8: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x80052CBC: beql        $v0, $s0, L_80052D4C
    if (ctx->r2 == ctx->r16) {
        // 0x80052CC0: lw          $t7, 0x280($s4)
        ctx->r15 = MEM_W(ctx->r20, 0X280);
            goto L_80052D4C;
    }
    goto skip_0;
    // 0x80052CC0: lw          $t7, 0x280($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X280);
    skip_0:
    // 0x80052CC4: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80052CC8: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x80052CCC: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
L_80052CD0:
    // 0x80052CD0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80052CD4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80052CD8: lw          $v1, 0x10($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X10);
    // 0x80052CDC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80052CE0: bnel        $v1, $s1, L_80052D10
    if (ctx->r3 != ctx->r17) {
        // 0x80052CE4: lw          $v1, 0x270($s4)
        ctx->r3 = MEM_W(ctx->r20, 0X270);
            goto L_80052D10;
    }
    goto skip_1;
    // 0x80052CE4: lw          $v1, 0x270($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X270);
    skip_1:
    // 0x80052CE8: lw          $v1, 0x26C($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X26C);
    // 0x80052CEC: beql        $v1, $zero, L_80052D00
    if (ctx->r3 == 0) {
        // 0x80052CF0: sw          $v0, 0x264($s4)
        MEM_W(0X264, ctx->r20) = ctx->r2;
            goto L_80052D00;
    }
    goto skip_2;
    // 0x80052CF0: sw          $v0, 0x264($s4)
    MEM_W(0X264, ctx->r20) = ctx->r2;
    skip_2:
    // 0x80052CF4: b           L_80052D00
    // 0x80052CF8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
        goto L_80052D00;
    // 0x80052CF8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80052CFC: sw          $v0, 0x264($s4)
    MEM_W(0X264, ctx->r20) = ctx->r2;
L_80052D00:
    // 0x80052D00: sw          $v0, 0x26C($s4)
    MEM_W(0X26C, ctx->r20) = ctx->r2;
    // 0x80052D04: b           L_80052D28
    // 0x80052D08: sw          $s2, 0x280($s4)
    MEM_W(0X280, ctx->r20) = ctx->r18;
        goto L_80052D28;
    // 0x80052D08: sw          $s2, 0x280($s4)
    MEM_W(0X280, ctx->r20) = ctx->r18;
    // 0x80052D0C: lw          $v1, 0x270($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X270);
L_80052D10:
    // 0x80052D10: beql        $v1, $zero, L_80052D24
    if (ctx->r3 == 0) {
        // 0x80052D14: sw          $v0, 0x268($s4)
        MEM_W(0X268, ctx->r20) = ctx->r2;
            goto L_80052D24;
    }
    goto skip_3;
    // 0x80052D14: sw          $v0, 0x268($s4)
    MEM_W(0X268, ctx->r20) = ctx->r2;
    skip_3:
    // 0x80052D18: b           L_80052D24
    // 0x80052D1C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_80052D24;
    // 0x80052D1C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80052D20: sw          $v0, 0x268($s4)
    MEM_W(0X268, ctx->r20) = ctx->r2;
L_80052D24:
    // 0x80052D24: sw          $v0, 0x270($s4)
    MEM_W(0X270, ctx->r20) = ctx->r2;
L_80052D28:
    // 0x80052D28: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x80052D2C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80052D30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80052D34: andi        $t6, $t9, 0x3
    ctx->r14 = ctx->r25 & 0X3;
    // 0x80052D38: jal         0x8004F990
    // 0x80052D3C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80052D3C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    after_1:
    // 0x80052D40: bnel        $v0, $s0, L_80052CD0
    if (ctx->r2 != ctx->r16) {
        // 0x80052D44: lw          $t8, 0x44($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X44);
            goto L_80052CD0;
    }
    goto skip_4;
    // 0x80052D44: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    skip_4:
    // 0x80052D48: lw          $t7, 0x280($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X280);
L_80052D4C:
    // 0x80052D4C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80052D50: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80052D54: beql        $t7, $zero, L_80052D94
    if (ctx->r15 == 0) {
        // 0x80052D58: lw          $t7, 0x274($s4)
        ctx->r15 = MEM_W(ctx->r20, 0X274);
            goto L_80052D94;
    }
    goto skip_5;
    // 0x80052D58: lw          $t7, 0x274($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X274);
    skip_5:
    // 0x80052D5C: lw          $v0, 0x274($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X274);
    // 0x80052D60: beql        $v0, $zero, L_80052D94
    if (ctx->r2 == 0) {
        // 0x80052D64: lw          $t7, 0x274($s4)
        ctx->r15 = MEM_W(ctx->r20, 0X274);
            goto L_80052D94;
    }
    goto skip_6;
    // 0x80052D64: lw          $t7, 0x274($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X274);
    skip_6:
    // 0x80052D68: lw          $t8, 0x10($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X10);
    // 0x80052D6C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80052D70: bnel        $t8, $at, L_80052DD0
    if (ctx->r24 != ctx->r1) {
        // 0x80052D74: lw          $s0, 0x260($s4)
        ctx->r16 = MEM_W(ctx->r20, 0X260);
            goto L_80052DD0;
    }
    goto skip_7;
    // 0x80052D74: lw          $s0, 0x260($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X260);
    skip_7:
    // 0x80052D78: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x80052D7C: ori         $t6, $t9, 0x10
    ctx->r14 = ctx->r25 | 0X10;
    // 0x80052D80: jal         0x80059D30
    // 0x80052D84: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    func_80059D30(rdram, ctx);
        goto after_2;
    // 0x80052D84: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    after_2:
    // 0x80052D88: b           L_80052DD0
    // 0x80052D8C: lw          $s0, 0x260($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X260);
        goto L_80052DD0;
    // 0x80052D8C: lw          $s0, 0x260($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X260);
    // 0x80052D90: lw          $t7, 0x274($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X274);
L_80052D94:
    // 0x80052D94: lw          $t6, 0x278($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X278);
    // 0x80052D98: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x80052D9C: sltiu       $t8, $t7, 0x1
    ctx->r24 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80052DA0: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80052DA4: sltiu       $t7, $t6, 0x1
    ctx->r15 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80052DA8: or          $s0, $t9, $t7
    ctx->r16 = ctx->r25 | ctx->r15;
    // 0x80052DAC: jal         0x800529F0
    // 0x80052DB0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_800529F0(rdram, ctx);
        goto after_3;
    // 0x80052DB0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_3:
    // 0x80052DB4: beql        $v0, $s0, L_80052DD0
    if (ctx->r2 == ctx->r16) {
        // 0x80052DB8: lw          $s0, 0x260($s4)
        ctx->r16 = MEM_W(ctx->r20, 0X260);
            goto L_80052DD0;
    }
    goto skip_8;
    // 0x80052DB8: lw          $s0, 0x260($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X260);
    skip_8:
    // 0x80052DBC: or          $s3, $s4, $zero
    ctx->r19 = ctx->r20 | 0;
    // 0x80052DC0: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x80052DC4: jal         0x80052950
    // 0x80052DC8: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    func_80052950(rdram, ctx);
        goto after_4;
    // 0x80052DC8: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    after_4:
    // 0x80052DCC: lw          $s0, 0x260($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X260);
L_80052DD0:
    // 0x80052DD0: beql        $s0, $zero, L_80052DF8
    if (ctx->r16 == 0) {
        // 0x80052DD4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80052DF8;
    }
    goto skip_9;
    // 0x80052DD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_9:
    // 0x80052DD8: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
L_80052DDC:
    // 0x80052DDC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80052DE0: jal         0x800534A0
    // 0x80052DE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x80052DE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x80052DE8: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x80052DEC: bnel        $s0, $zero, L_80052DDC
    if (ctx->r16 != 0) {
        // 0x80052DF0: lw          $a0, 0x4($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X4);
            goto L_80052DDC;
    }
    goto skip_10;
    // 0x80052DF0: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    skip_10:
    // 0x80052DF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80052DF8:
    // 0x80052DF8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80052DFC: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80052E04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80052E04: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80052E08: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80052E0C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80052E10: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80052E14: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80052E18: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80052E1C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80052E20: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80052E24: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80052E28: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80052E2C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80052E30: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80052E34: addiu       $s7, $a0, 0x40
    ctx->r23 = ADD32(ctx->r4, 0X40);
    // 0x80052E38: addiu       $fp, $zero, 0x29A
    ctx->r30 = ADD32(0, 0X29A);
L_80052E3C:
    // 0x80052E3C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_80052E40:
    // 0x80052E40: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    // 0x80052E44: jal         0x8004F990
    // 0x80052E48: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80052E48: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80052E4C: lw          $v1, 0x84($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X84);
    // 0x80052E50: addiu       $at, $zero, 0x29B
    ctx->r1 = ADD32(0, 0X29B);
    // 0x80052E54: beq         $v1, $fp, L_80052E7C
    if (ctx->r3 == ctx->r30) {
        // 0x80052E58: nop
    
            goto L_80052E7C;
    }
    // 0x80052E58: nop

    // 0x80052E5C: beq         $v1, $at, L_80052E8C
    if (ctx->r3 == ctx->r1) {
        // 0x80052E60: addiu       $at, $zero, 0x29C
        ctx->r1 = ADD32(0, 0X29C);
            goto L_80052E8C;
    }
    // 0x80052E60: addiu       $at, $zero, 0x29C
    ctx->r1 = ADD32(0, 0X29C);
    // 0x80052E64: beq         $v1, $at, L_80052F58
    if (ctx->r3 == ctx->r1) {
        // 0x80052E68: addiu       $at, $zero, 0x29D
        ctx->r1 = ADD32(0, 0X29D);
            goto L_80052F58;
    }
    // 0x80052E68: addiu       $at, $zero, 0x29D
    ctx->r1 = ADD32(0, 0X29D);
    // 0x80052E6C: beql        $v1, $at, L_80052FCC
    if (ctx->r3 == ctx->r1) {
        // 0x80052E70: lw          $s0, 0x260($s6)
        ctx->r16 = MEM_W(ctx->r22, 0X260);
            goto L_80052FCC;
    }
    goto skip_0;
    // 0x80052E70: lw          $s0, 0x260($s6)
    ctx->r16 = MEM_W(ctx->r22, 0X260);
    skip_0:
    // 0x80052E74: b           L_80052E40
    // 0x80052E78: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_80052E40;
    // 0x80052E78: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_80052E7C:
    // 0x80052E7C: jal         0x80052C84
    // 0x80052E80: or          $s4, $s6, $zero
    ctx->r20 = ctx->r22 | 0;
    func_80052C84(rdram, ctx);
        goto after_1;
    // 0x80052E80: or          $s4, $s6, $zero
    ctx->r20 = ctx->r22 | 0;
    after_1:
    // 0x80052E84: b           L_80052E40
    // 0x80052E88: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_80052E40;
    // 0x80052E88: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_80052E8C:
    // 0x80052E8C: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    // 0x80052E90: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
    // 0x80052E94: lw          $s0, 0x274($s6)
    ctx->r16 = MEM_W(ctx->r22, 0X274);
    // 0x80052E98: sw          $zero, 0x274($s6)
    MEM_W(0X274, ctx->r22) = 0;
    // 0x80052E9C: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x80052EA0: andi        $t7, $t6, 0x10
    ctx->r15 = ctx->r14 & 0X10;
    // 0x80052EA4: beql        $t7, $zero, L_80052EFC
    if (ctx->r15 == 0) {
        // 0x80052EA8: lw          $t6, 0x4($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X4);
            goto L_80052EFC;
    }
    goto skip_1;
    // 0x80052EA8: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    skip_1:
    // 0x80052EAC: jal         0x80059810
    // 0x80052EB0: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    func_80059810(rdram, ctx);
        goto after_2;
    // 0x80052EB0: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    after_2:
    // 0x80052EB4: beql        $v0, $zero, L_80052EFC
    if (ctx->r2 == 0) {
        // 0x80052EB8: lw          $t6, 0x4($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X4);
            goto L_80052EFC;
    }
    goto skip_2;
    // 0x80052EB8: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    skip_2:
    // 0x80052EBC: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x80052EC0: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80052EC4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80052EC8: ori         $t9, $t8, 0x20
    ctx->r25 = ctx->r24 | 0X20;
    // 0x80052ECC: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x80052ED0: bne         $t7, $at, L_80052F10
    if (ctx->r15 != ctx->r1) {
        // 0x80052ED4: sw          $t9, 0x4($s0)
        MEM_W(0X4, ctx->r16) = ctx->r25;
            goto L_80052F10;
    }
    // 0x80052ED4: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x80052ED8: lw          $t8, 0x268($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X268);
    // 0x80052EDC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80052EE0: lw          $t9, 0x270($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X270);
    // 0x80052EE4: sw          $s0, 0x268($s6)
    MEM_W(0X268, ctx->r22) = ctx->r16;
    // 0x80052EE8: bnel        $t9, $zero, L_80052F14
    if (ctx->r25 != 0) {
        // 0x80052EEC: lw          $t8, 0x274($s6)
        ctx->r24 = MEM_W(ctx->r22, 0X274);
            goto L_80052F14;
    }
    goto skip_3;
    // 0x80052EEC: lw          $t8, 0x274($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X274);
    skip_3:
    // 0x80052EF0: b           L_80052F10
    // 0x80052EF4: sw          $s0, 0x270($s6)
    MEM_W(0X270, ctx->r22) = ctx->r16;
        goto L_80052F10;
    // 0x80052EF4: sw          $s0, 0x270($s6)
    MEM_W(0X270, ctx->r22) = ctx->r16;
    // 0x80052EF8: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
L_80052EFC:
    // 0x80052EFC: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80052F00: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80052F04: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x80052F08: jal         0x80052BD4
    // 0x80052F0C: sw          $s6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r22;
    func_80052BD4(rdram, ctx);
        goto after_3;
    // 0x80052F0C: sw          $s6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r22;
    after_3:
L_80052F10:
    // 0x80052F10: lw          $t8, 0x274($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X274);
L_80052F14:
    // 0x80052F14: lw          $t7, 0x278($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X278);
    // 0x80052F18: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80052F1C: sltiu       $t9, $t8, 0x1
    ctx->r25 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80052F20: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x80052F24: sltiu       $t8, $t7, 0x1
    ctx->r24 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80052F28: or          $s0, $t6, $t8
    ctx->r16 = ctx->r14 | ctx->r24;
    // 0x80052F2C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80052F30: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x80052F34: jal         0x800529F0
    // 0x80052F38: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    func_800529F0(rdram, ctx);
        goto after_4;
    // 0x80052F38: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    after_4:
    // 0x80052F3C: beq         $v0, $s0, L_80052E3C
    if (ctx->r2 == ctx->r16) {
        // 0x80052F40: or          $s3, $s6, $zero
        ctx->r19 = ctx->r22 | 0;
            goto L_80052E3C;
    }
    // 0x80052F40: or          $s3, $s6, $zero
    ctx->r19 = ctx->r22 | 0;
    // 0x80052F44: lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X68);
    // 0x80052F48: jal         0x80052950
    // 0x80052F4C: lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X64);
    func_80052950(rdram, ctx);
        goto after_5;
    // 0x80052F4C: lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X64);
    after_5:
    // 0x80052F50: b           L_80052E40
    // 0x80052F54: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_80052E40;
    // 0x80052F54: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_80052F58:
    // 0x80052F58: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    // 0x80052F5C: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80052F60: lw          $s0, 0x278($s6)
    ctx->r16 = MEM_W(ctx->r22, 0X278);
    // 0x80052F64: sw          $zero, 0x278($s6)
    MEM_W(0X278, ctx->r22) = 0;
    // 0x80052F68: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80052F6C: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x80052F70: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x80052F74: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x80052F78: jal         0x80052BD4
    // 0x80052F7C: sw          $s6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r22;
    func_80052BD4(rdram, ctx);
        goto after_6;
    // 0x80052F7C: sw          $s6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r22;
    after_6:
    // 0x80052F80: lw          $t6, 0x274($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X274);
    // 0x80052F84: lw          $t7, 0x278($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X278);
    // 0x80052F88: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80052F8C: sltiu       $t8, $t6, 0x1
    ctx->r24 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80052F90: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80052F94: sltiu       $t6, $t7, 0x1
    ctx->r14 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80052F98: or          $s0, $t9, $t6
    ctx->r16 = ctx->r25 | ctx->r14;
    // 0x80052F9C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80052FA0: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x80052FA4: jal         0x800529F0
    // 0x80052FA8: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    func_800529F0(rdram, ctx);
        goto after_7;
    // 0x80052FA8: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    after_7:
    // 0x80052FAC: beq         $v0, $s0, L_80052E3C
    if (ctx->r2 == ctx->r16) {
        // 0x80052FB0: or          $s3, $s6, $zero
        ctx->r19 = ctx->r22 | 0;
            goto L_80052E3C;
    }
    // 0x80052FB0: or          $s3, $s6, $zero
    ctx->r19 = ctx->r22 | 0;
    // 0x80052FB4: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80052FB8: jal         0x80052950
    // 0x80052FBC: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    func_80052950(rdram, ctx);
        goto after_8;
    // 0x80052FBC: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    after_8:
    // 0x80052FC0: b           L_80052E40
    // 0x80052FC4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_80052E40;
    // 0x80052FC4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80052FC8: lw          $s0, 0x260($s6)
    ctx->r16 = MEM_W(ctx->r22, 0X260);
L_80052FCC:
    // 0x80052FCC: addiu       $s1, $s6, 0x20
    ctx->r17 = ADD32(ctx->r22, 0X20);
    // 0x80052FD0: beql        $s0, $zero, L_80052E40
    if (ctx->r16 == 0) {
        // 0x80052FD4: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_80052E40;
    }
    goto skip_4;
    // 0x80052FD4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    skip_4:
    // 0x80052FD8: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
L_80052FDC:
    // 0x80052FDC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80052FE0: jal         0x800534A0
    // 0x80052FE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_9;
    // 0x80052FE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x80052FE8: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x80052FEC: bnel        $s0, $zero, L_80052FDC
    if (ctx->r16 != 0) {
        // 0x80052FF0: lw          $a0, 0x4($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X4);
            goto L_80052FDC;
    }
    goto skip_5;
    // 0x80052FF0: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    skip_5:
    // 0x80052FF4: b           L_80052E40
    // 0x80052FF8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_80052E40;
    // 0x80052FF8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80052FFC: nop

    // 0x80053000: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80053004: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80053008: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8005300C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80053010: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80053014: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80053018: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8005301C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80053020: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80053024: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80053028: jr          $ra
    // 0x8005302C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    TRACE_RETURN()
    return;
    // 0x8005302C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_80053030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80053030: jr          $ra
    // 0x80053034: addiu       $v0, $a0, 0x78
    ctx->r2 = ADD32(ctx->r4, 0X78);
    TRACE_RETURN()
    return;
    // 0x80053034: addiu       $v0, $a0, 0x78
    ctx->r2 = ADD32(ctx->r4, 0X78);
;}
