#include "recomp.h"
#include "trace.h"
#include "funcs.h"
#include "chopper_recomp_hooks.h"

RECOMP_FUNC void func_80018E10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80018E10: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80018E14: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80018E18: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80018E1C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80018E20: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x80018E24: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80018E28: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80018E2C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80018E30: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80018E34: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80018E38: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80018E3C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80018E40: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80018E44: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x80018E48: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80018E4C: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x80018E50: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
    // 0x80018E54: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80018E58: jal         0x8004D134
    // 0x80018E5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004D134(rdram, ctx);
        goto after_0;
    // 0x80018E5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80018E60: lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // 0x80018E64: addiu       $a0, $a0, -0x3900
    ctx->r4 = ADD32(ctx->r4, -0X3900);
    // 0x80018E68: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    // 0x80018E6C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80018E70: jal         0x80004CE0
    // 0x80018E74: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    func_80004CE0(rdram, ctx);
        goto after_1;
    // 0x80018E74: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    after_1:
    // 0x80018E78: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80018E7C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80018E80: jal         0x800499B0
    // 0x80018E84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800499B0(rdram, ctx);
        goto after_2;
    // 0x80018E84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80018E88: jal         0x8004B1E0
    // 0x80018E8C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_8004B1E0(rdram, ctx);
        goto after_3;
    // 0x80018E8C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_3:
    // 0x80018E90: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80018E94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80018E98: jal         0x8000BD4C
    // 0x80018E9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BD4C(rdram, ctx);
        goto after_4;
    // 0x80018E9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80018EA0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80018EA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80018EA8: jal         0x8000BDEC
    // 0x80018EAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BDEC(rdram, ctx);
        goto after_5;
    // 0x80018EAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x80018EB0: addiu       $t7, $zero, 0x3E8
    ctx->r15 = ADD32(0, 0X3E8);
    // 0x80018EB4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80018EB8: sw          $t7, -0x2CF8($at)
    MEM_W(-0X2CF8, ctx->r1) = ctx->r15;
    // 0x80018EBC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80018EC0: addiu       $t8, $zero, 0x3D0
    ctx->r24 = ADD32(0, 0X3D0);
    // 0x80018EC4: sw          $t8, -0x2CF4($at)
    MEM_W(-0X2CF4, ctx->r1) = ctx->r24;
    // 0x80018EC8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80018ECC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80018ED0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80018ED4: lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // 0x80018ED8: sh          $t9, -0x2CC4($at)
    MEM_H(-0X2CC4, ctx->r1) = ctx->r25;
    // 0x80018EDC: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    // 0x80018EE0: addiu       $a0, $a0, 0x3D4
    ctx->r4 = ADD32(ctx->r4, 0X3D4);
    // 0x80018EE4: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x80018EE8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80018EEC: jal         0x80004CE0
    // 0x80018EF0: addiu       $a3, $sp, 0x68
    ctx->r7 = ADD32(ctx->r29, 0X68);
    func_80004CE0(rdram, ctx);
        goto after_6;
    // 0x80018EF0: addiu       $a3, $sp, 0x68
    ctx->r7 = ADD32(ctx->r29, 0X68);
    after_6:
    // 0x80018EF4: jal         0x8000798C
    // 0x80018EF8: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    func_8000798C(rdram, ctx);
        goto after_7;
    // 0x80018EF8: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    after_7:
    // 0x80018EFC: jal         0x8000798C
    // 0x80018F00: nop

    func_8000798C(rdram, ctx);
        goto after_8;
    // 0x80018F00: nop

    after_8:
    // 0x80018F04: jal         0x8000798C
    // 0x80018F08: nop

    func_8000798C(rdram, ctx);
        goto after_9;
    // 0x80018F08: nop

    after_9:
    // 0x80018F0C: jal         0x8000798C
    // 0x80018F10: nop

    func_8000798C(rdram, ctx);
        goto after_10;
    // 0x80018F10: nop

    after_10:
    // 0x80018F14: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80018F18: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80018F1C: sw          $zero, -0x68C8($at)
    MEM_W(-0X68C8, ctx->r1) = 0;
    // 0x80018F20: addiu       $a0, $a0, -0x6A20
    ctx->r4 = ADD32(ctx->r4, -0X6A20);
    // 0x80018F24: jal         0x80020328
    // 0x80018F28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80020328(rdram, ctx);
        goto after_11;
    // 0x80018F28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80018F2C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80018F30: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80018F34: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80018F38: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80018F3C: addiu       $a1, $a1, -0x6A18
    ctx->r5 = ADD32(ctx->r5, -0X6A18);
    // 0x80018F40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80018F44: jal         0x80011520
    // 0x80018F48: swc1        $f4, -0x6A14($at)
    MEM_W(-0X6A14, ctx->r1) = ctx->f4.u32l;
    func_80011520(rdram, ctx);
        goto after_12;
    // 0x80018F48: swc1        $f4, -0x6A14($at)
    MEM_W(-0X6A14, ctx->r1) = ctx->f4.u32l;
    after_12:
    // 0x80018F4C: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80018F50: jal         0x80049CFC
    // 0x80018F54: addiu       $a0, $a0, 0x6440
    ctx->r4 = ADD32(ctx->r4, 0X6440);
    func_80049CFC(rdram, ctx);
        goto after_13;
    // 0x80018F54: addiu       $a0, $a0, 0x6440
    ctx->r4 = ADD32(ctx->r4, 0X6440);
    after_13:
    // 0x80018F58: jal         0x80049D80
    // 0x80018F5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80049D80(rdram, ctx);
        goto after_14;
    // 0x80018F5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_14:
    // 0x80018F60: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80018F64: jal         0x80049DFC
    // 0x80018F68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80049DFC(rdram, ctx);
        goto after_15;
    // 0x80018F68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x80018F6C: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x80018F70: jal         0x8004A148
    // 0x80018F74: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8004A148(rdram, ctx);
        goto after_16;
    // 0x80018F74: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_16:
    // 0x80018F78: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x80018F7C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80018F80: addiu       $a1, $zero, 0x58
    ctx->r5 = ADD32(0, 0X58);
    // 0x80018F84: lw          $v0, 0x8($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X8);
    // 0x80018F88: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x80018F8C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80018F90: lw          $t2, 0xD8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XD8);
    // 0x80018F94: ori         $t3, $t2, 0x8001
    ctx->r11 = ctx->r10 | 0X8001;
    // 0x80018F98: sw          $t3, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r11;
    // 0x80018F9C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80018FA0: jal         0x8004C580
    // 0x80018FA4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_17;
    // 0x80018FA4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_17:
    // 0x80018FA8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80018FAC: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    // 0x80018FB0: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x80018FB4: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x80018FB8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80018FBC: jal         0x8004C580
    // 0x80018FC0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_18;
    // 0x80018FC0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_18:
    // 0x80018FC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80018FC8: addiu       $a1, $zero, -0x5F
    ctx->r5 = ADD32(0, -0X5F);
    // 0x80018FCC: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x80018FD0: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x80018FD4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80018FD8: jal         0x8004C580
    // 0x80018FDC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_19;
    // 0x80018FDC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_19:
    // 0x80018FE0: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x80018FE4: addiu       $fp, $fp, -0x6B92
    ctx->r30 = ADD32(ctx->r30, -0X6B92);
    // 0x80018FE8: lh          $s7, 0x0($fp)
    ctx->r23 = MEM_H(ctx->r30, 0X0);
    // 0x80018FEC: sll         $s2, $s7, 16
    ctx->r18 = S32(ctx->r23 << 16);
    // 0x80018FF0: sra         $t4, $s2, 16
    ctx->r12 = S32(SIGNED(ctx->r18) >> 16);
    // 0x80018FF4: jal         0x8000798C
    // 0x80018FF8: or          $s2, $t4, $zero
    ctx->r18 = ctx->r12 | 0;
    func_8000798C(rdram, ctx);
        goto after_20;
    // 0x80018FF8: or          $s2, $t4, $zero
    ctx->r18 = ctx->r12 | 0;
    after_20:
    // 0x80018FFC: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x80019000: lui         $s3, 0x8007
    ctx->r19 = S32(0X8007 << 16);
    // 0x80019004: addiu       $s3, $s3, -0x6590
    ctx->r19 = ADD32(ctx->r19, -0X6590);
    // 0x80019008: addiu       $s4, $s4, -0x2E5A
    ctx->r20 = ADD32(ctx->r20, -0X2E5A);
    // 0x8001900C: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
L_80019010:
    // 0x80019010: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80019014: bnel        $t5, $at, L_80019068
    if (ctx->r13 != ctx->r1) {
        // 0x80019018: lw          $t9, 0x54($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X54);
            goto L_80019068;
    }
    goto skip_0;
    // 0x80019018: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x8001901C: lhu         $t6, 0x0($s4)
    ctx->r14 = MEM_HU(ctx->r20, 0X0);
    // 0x80019020: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x80019024: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x80019028: beql        $t7, $zero, L_80019068
    if (ctx->r15 == 0) {
        // 0x8001902C: lw          $t9, 0x54($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X54);
            goto L_80019068;
    }
    goto skip_1;
    // 0x8001902C: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    skip_1:
    // 0x80019030: jal         0x80044480
    // 0x80019034: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    func_80044480(rdram, ctx);
        goto after_21;
    // 0x80019034: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    after_21:
    // 0x80019038: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x8001903C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80019040: jal         0x8004D134
    // 0x80019044: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_8004D134(rdram, ctx);
        goto after_22;
    // 0x80019044: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_22:
    // 0x80019048: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8001904C: sw          $t8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r24;
    // 0x80019050: sh          $s2, 0x0($fp)
    MEM_H(0X0, ctx->r30) = ctx->r18;
    // 0x80019054: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80019058: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001905C: jal         0x8001A37C
    // 0x80019060: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8001A37C(rdram, ctx);
        goto after_23;
    // 0x80019060: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_23:
    // 0x80019064: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
L_80019068:
    // 0x80019068: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8001906C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80019070: bne         $t9, $at, L_800190F4
    if (ctx->r25 != ctx->r1) {
        // 0x80019074: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_800190F4;
    }
    // 0x80019074: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80019078: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001907C: jal         0x8004A0C4
    // 0x80019080: lw          $a0, -0x6A1C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6A1C);
    func_8004A0C4(rdram, ctx);
        goto after_24;
    // 0x80019080: lw          $a0, -0x6A1C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6A1C);
    after_24:
    // 0x80019084: jal         0x8004A0C4
    // 0x80019088: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    func_8004A0C4(rdram, ctx);
        goto after_25;
    // 0x80019088: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    after_25:
    // 0x8001908C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80019090: jal         0x8004C4D8
    // 0x80019094: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004C4D8(rdram, ctx);
        goto after_26;
    // 0x80019094: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_26:
    // 0x80019098: jal         0x80049C48
    // 0x8001909C: nop

    func_80049C48(rdram, ctx);
        goto after_27;
    // 0x8001909C: nop

    after_27:
    // 0x800190A0: jal         0x8004B21C
    // 0x800190A4: nop

    func_8004B21C(rdram, ctx);
        goto after_28;
    // 0x800190A4: nop

    after_28:
    // 0x800190A8: jal         0x80004E5C
    // 0x800190AC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80004E5C(rdram, ctx);
        goto after_29;
    // 0x800190AC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_29:
    // 0x800190B0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x800190B4: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
L_800190B8:
    // 0x800190B8: jal         0x8000798C
    // 0x800190BC: nop

    func_8000798C(rdram, ctx);
        goto after_30;
    // 0x800190BC: nop

    after_30:
    // 0x800190C0: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x800190C4: bne         $t1, $zero, L_800190B8
    if (ctx->r9 != 0) {
        // 0x800190C8: nop
    
            goto L_800190B8;
    }
    // 0x800190C8: nop

    // 0x800190CC: jal         0x80004E5C
    // 0x800190D0: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    func_80004E5C(rdram, ctx);
        goto after_31;
    // 0x800190D0: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    after_31:
    // 0x800190D4: jal         0x8000798C
    // 0x800190D8: nop

    func_8000798C(rdram, ctx);
        goto after_32;
    // 0x800190D8: nop

    after_32:
    // 0x800190DC: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
    // 0x800190E0: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
L_800190E4:
    // 0x800190E4: jal         0x8000798C
    // 0x800190E8: nop

    func_8000798C(rdram, ctx);
        goto after_33;
    // 0x800190E8: nop

    after_33:
    // 0x800190EC: b           L_800190E4
    // 0x800190F0: nop

        goto L_800190E4;
    // 0x800190F0: nop

L_800190F4:
    // 0x800190F4: bne         $s5, $zero, L_8001914C
    if (ctx->r21 != 0) {
        // 0x800190F8: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8001914C;
    }
    // 0x800190F8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800190FC: lh          $t5, -0x2E60($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X2E60);
    // 0x80019100: lh          $t7, -0x2E5E($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X2E5E);
    // 0x80019104: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80019108: bgez        $t5, L_80019118
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8001910C: sra         $t6, $t5, 3
        ctx->r14 = S32(SIGNED(ctx->r13) >> 3);
            goto L_80019118;
    }
    // 0x8001910C: sra         $t6, $t5, 3
    ctx->r14 = S32(SIGNED(ctx->r13) >> 3);
    // 0x80019110: addiu       $at, $t5, 0x7
    ctx->r1 = ADD32(ctx->r13, 0X7);
    // 0x80019114: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_80019118:
    // 0x80019118: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001911C: sb          $t6, -0x2E48($at)
    MEM_B(-0X2E48, ctx->r1) = ctx->r14;
    // 0x80019120: bgez        $t7, L_80019130
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80019124: sra         $t8, $t7, 3
        ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
            goto L_80019130;
    }
    // 0x80019124: sra         $t8, $t7, 3
    ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
    // 0x80019128: addiu       $at, $t7, 0x7
    ctx->r1 = ADD32(ctx->r15, 0X7);
    // 0x8001912C: sra         $t8, $at, 3
    ctx->r24 = S32(SIGNED(ctx->r1) >> 3);
L_80019130:
    // 0x80019130: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80019134: sb          $t8, -0x2E47($at)
    MEM_B(-0X2E47, ctx->r1) = ctx->r24;
    // 0x80019138: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001913C: sw          $t9, -0x6630($at)
    MEM_W(-0X6630, ctx->r1) = ctx->r25;
    // 0x80019140: addiu       $a0, $a0, -0x6A20
    ctx->r4 = ADD32(ctx->r4, -0X6A20);
    // 0x80019144: jal         0x80020A90
    // 0x80019148: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80020A90(rdram, ctx);
        goto after_34;
    // 0x80019148: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_34:
L_8001914C:
    // 0x8001914C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80019150: jal         0x80022440
    // 0x80019154: addiu       $a0, $a0, -0x6A20
    ctx->r4 = ADD32(ctx->r4, -0X6A20);
    func_80022440(rdram, ctx);
        goto after_35;
    // 0x80019154: addiu       $a0, $a0, -0x6A20
    ctx->r4 = ADD32(ctx->r4, -0X6A20);
    after_35:
    // 0x80019158: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8001915C: lw          $t0, -0x6A1C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X6A1C);
    // 0x80019160: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80019164: lw          $v0, 0x8($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X8);
    // 0x80019168: lw          $t1, 0xD8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XD8);
    // 0x8001916C: ori         $t2, $t1, 0x8001
    ctx->r10 = ctx->r9 | 0X8001;
    // 0x80019170: sw          $t2, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r10;
L_80019174:
    // 0x80019174: bne         $s0, $s2, L_80019184
    if (ctx->r16 != ctx->r18) {
        // 0x80019178: sll         $t3, $s0, 1
        ctx->r11 = S32(ctx->r16 << 1);
            goto L_80019184;
    }
    // 0x80019178: sll         $t3, $s0, 1
    ctx->r11 = S32(ctx->r16 << 1);
    // 0x8001917C: b           L_80019188
    // 0x80019180: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
        goto L_80019188;
    // 0x80019180: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80019184:
    // 0x80019184: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
L_80019188:
    // 0x80019188: addiu       $s1, $s0, 0x1
    ctx->r17 = ADD32(ctx->r16, 0X1);
    // 0x8001918C: sll         $a3, $s1, 16
    ctx->r7 = S32(ctx->r17 << 16);
    // 0x80019190: addu        $t4, $s3, $t3
    ctx->r12 = ADD32(ctx->r19, ctx->r11);
    // 0x80019194: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80019198: sll         $t5, $a2, 24
    ctx->r13 = S32(ctx->r6 << 24);
    // 0x8001919C: lh          $a0, 0x0($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X0);
    // 0x800191A0: sra         $t7, $a3, 16
    ctx->r15 = S32(SIGNED(ctx->r7) >> 16);
    // 0x800191A4: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x800191A8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800191AC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800191B0: sra         $a2, $t5, 16
    ctx->r6 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800191B4: jal         0x8004C580
    // 0x800191B8: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    func_8004C580(rdram, ctx);
        goto after_36;
    // 0x800191B8: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_36:
    // 0x800191BC: sll         $s0, $s1, 16
    ctx->r16 = S32(ctx->r17 << 16);
    // 0x800191C0: sra         $t8, $s0, 16
    ctx->r24 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800191C4: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x800191C8: bne         $at, $zero, L_80019174
    if (ctx->r1 != 0) {
        // 0x800191CC: or          $s0, $t8, $zero
        ctx->r16 = ctx->r24 | 0;
            goto L_80019174;
    }
    // 0x800191CC: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x800191D0: andi        $a2, $s6, 0x7F
    ctx->r6 = ctx->r22 & 0X7F;
    // 0x800191D4: sll         $t9, $s2, 1
    ctx->r25 = S32(ctx->r18 << 1);
    // 0x800191D8: addiu       $t0, $a2, 0x80
    ctx->r8 = ADD32(ctx->r6, 0X80);
    // 0x800191DC: addu        $v0, $s3, $t9
    ctx->r2 = ADD32(ctx->r19, ctx->r25);
    // 0x800191E0: sll         $t1, $t0, 24
    ctx->r9 = S32(ctx->r8 << 24);
    // 0x800191E4: sra         $a2, $t1, 16
    ctx->r6 = S32(SIGNED(ctx->r9) >> 16);
    // 0x800191E8: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x800191EC: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    // 0x800191F0: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x800191F4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800191F8: jal         0x8004C580
    // 0x800191FC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_37;
    // 0x800191FC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_37:
    // 0x80019200: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x80019204: sll         $t3, $s6, 16
    ctx->r11 = S32(ctx->r22 << 16);
    // 0x80019208: bne         $s5, $zero, L_80019274
    if (ctx->r21 != 0) {
        // 0x8001920C: sra         $s6, $t3, 16
        ctx->r22 = S32(SIGNED(ctx->r11) >> 16);
            goto L_80019274;
    }
    // 0x8001920C: sra         $s6, $t3, 16
    ctx->r22 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80019210: lhu         $v0, 0x0($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X0);
    // 0x80019214: sll         $s7, $s2, 16
    ctx->r23 = S32(ctx->r18 << 16);
    // 0x80019218: sra         $t5, $s7, 16
    ctx->r13 = S32(SIGNED(ctx->r23) >> 16);
    // 0x8001921C: andi        $t6, $v0, 0x100
    ctx->r14 = ctx->r2 & 0X100;
    // 0x80019220: beq         $t6, $zero, L_80019244
    if (ctx->r14 == 0) {
        // 0x80019224: or          $s7, $t5, $zero
        ctx->r23 = ctx->r13 | 0;
            goto L_80019244;
    }
    // 0x80019224: or          $s7, $t5, $zero
    ctx->r23 = ctx->r13 | 0;
    // 0x80019228: slti        $at, $s2, 0x3
    ctx->r1 = SIGNED(ctx->r18) < 0X3 ? 1 : 0;
    // 0x8001922C: beq         $at, $zero, L_80019264
    if (ctx->r1 == 0) {
        // 0x80019230: nop
    
            goto L_80019264;
    }
    // 0x80019230: nop

    // 0x80019234: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80019238: sll         $t7, $s2, 16
    ctx->r15 = S32(ctx->r18 << 16);
    // 0x8001923C: b           L_80019264
    // 0x80019240: sra         $s2, $t7, 16
    ctx->r18 = S32(SIGNED(ctx->r15) >> 16);
        goto L_80019264;
    // 0x80019240: sra         $s2, $t7, 16
    ctx->r18 = S32(SIGNED(ctx->r15) >> 16);
L_80019244:
    // 0x80019244: andi        $t9, $v0, 0x200
    ctx->r25 = ctx->r2 & 0X200;
    // 0x80019248: beq         $t9, $zero, L_80019264
    if (ctx->r25 == 0) {
        // 0x8001924C: nop
    
            goto L_80019264;
    }
    // 0x8001924C: nop

    // 0x80019250: blez        $s2, L_80019264
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80019254: nop
    
            goto L_80019264;
    }
    // 0x80019254: nop

    // 0x80019258: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x8001925C: sll         $t0, $s2, 16
    ctx->r8 = S32(ctx->r18 << 16);
    // 0x80019260: sra         $s2, $t0, 16
    ctx->r18 = S32(SIGNED(ctx->r8) >> 16);
L_80019264:
    // 0x80019264: beq         $s7, $s2, L_80019274
    if (ctx->r23 == ctx->r18) {
        // 0x80019268: addiu       $a0, $zero, 0x13
        ctx->r4 = ADD32(0, 0X13);
            goto L_80019274;
    }
    // 0x80019268: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    // 0x8001926C: jal         0x80044480
    // 0x80019270: sh          $s2, 0x0($fp)
    MEM_H(0X0, ctx->r30) = ctx->r18;
    func_80044480(rdram, ctx);
        goto after_38;
    // 0x80019270: sh          $s2, 0x0($fp)
    MEM_H(0X0, ctx->r30) = ctx->r18;
    after_38:
L_80019274:
    // 0x80019274: jal         0x8000798C
    // 0x80019278: nop

    func_8000798C(rdram, ctx);
        goto after_39;
    // 0x80019278: nop

    after_39:
    // 0x8001927C: b           L_80019010
    // 0x80019280: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
        goto L_80019010;
    // 0x80019280: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x80019284: nop

    // 0x80019288: nop

    // 0x8001928C: nop

    // 0x80019290: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80019294: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80019298: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8001929C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800192A0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800192A4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800192A8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800192AC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800192B0: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800192B4: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800192B8: jr          $ra
    // 0x800192BC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    TRACE_RETURN()
    return;
    // 0x800192BC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_800192C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800192C0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800192C4: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800192C8: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800192CC: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800192D0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800192D4: sll         $s7, $a1, 16
    ctx->r23 = S32(ctx->r5 << 16);
    // 0x800192D8: sll         $s3, $t7, 16
    ctx->r19 = S32(ctx->r15 << 16);
    // 0x800192DC: sra         $t8, $s7, 16
    ctx->r24 = S32(SIGNED(ctx->r23) >> 16);
    // 0x800192E0: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800192E4: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800192E8: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x800192EC: sra         $t9, $s3, 16
    ctx->r25 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800192F0: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800192F4: or          $s7, $t8, $zero
    ctx->r23 = ctx->r24 | 0;
    // 0x800192F8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800192FC: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80019300: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80019304: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80019308: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8001930C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80019310: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80019314: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x80019318: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x8001931C: sh          $zero, 0x48($sp)
    MEM_H(0X48, ctx->r29) = 0;
    // 0x80019320: or          $s3, $t9, $zero
    ctx->r19 = ctx->r25 | 0;
    // 0x80019324: bgez        $a2, L_80019338
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80019328: or          $s5, $a2, $zero
        ctx->r21 = ctx->r6 | 0;
            goto L_80019338;
    }
    // 0x80019328: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x8001932C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80019330: sh          $t0, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r8;
    // 0x80019334: negu        $s5, $a2
    ctx->r21 = SUB32(0, ctx->r6);
L_80019338:
    // 0x80019338: lh          $t1, 0x6E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X6E);
    // 0x8001933C: lui         $s2, 0x8007
    ctx->r18 = S32(0X8007 << 16);
    // 0x80019340: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80019344: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80019348: addu        $s2, $s2, $t2
    ctx->r18 = ADD32(ctx->r18, ctx->r10);
    // 0x8001934C: blez        $t1, L_800194D4
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80019350: lw          $s2, -0x6580($s2)
        ctx->r18 = MEM_W(ctx->r18, -0X6580);
            goto L_800194D4;
    }
    // 0x80019350: lw          $s2, -0x6580($s2)
    ctx->r18 = MEM_W(ctx->r18, -0X6580);
    // 0x80019354: lh          $fp, 0x76($sp)
    ctx->r30 = MEM_H(ctx->r29, 0X76);
L_80019358:
    // 0x80019358: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001935C: bne         $s2, $at, L_80019368
    if (ctx->r18 != ctx->r1) {
        // 0x80019360: nop
    
            goto L_80019368;
    }
    // 0x80019360: nop

    // 0x80019364: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_80019368:
    // 0x80019368: div         $zero, $s5, $s2
    lo = S32(S64(S32(ctx->r21)) / S64(S32(ctx->r18))); hi = S32(S64(S32(ctx->r21)) % S64(S32(ctx->r18)));
    // 0x8001936C: bne         $s2, $zero, L_80019378
    if (ctx->r18 != 0) {
        // 0x80019370: nop
    
            goto L_80019378;
    }
    // 0x80019370: nop

    // 0x80019374: break       7
    do_break(2147586932);
L_80019378:
    // 0x80019378: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001937C: bne         $s2, $at, L_80019390
    if (ctx->r18 != ctx->r1) {
        // 0x80019380: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80019390;
    }
    // 0x80019380: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80019384: bne         $s5, $at, L_80019390
    if (ctx->r21 != ctx->r1) {
        // 0x80019388: nop
    
            goto L_80019390;
    }
    // 0x80019388: nop

    // 0x8001938C: break       6
    do_break(2147586956);
L_80019390:
    // 0x80019390: mflo        $v0
    ctx->r2 = lo;
    // 0x80019394: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80019398: bne         $v0, $zero, L_800193B0
    if (ctx->r2 != 0) {
        // 0x8001939C: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_800193B0;
    }
    // 0x8001939C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800193A0: bne         $s6, $zero, L_800193B4
    if (ctx->r22 != 0) {
        // 0x800193A4: nop
    
            goto L_800193B4;
    }
    // 0x800193A4: nop

    // 0x800193A8: b           L_800193B4
    // 0x800193AC: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
        goto L_800193B4;
    // 0x800193AC: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
L_800193B0:
    // 0x800193B0: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_800193B4:
    // 0x800193B4: beql        $s1, $at, L_800194A8
    if (ctx->r17 == ctx->r1) {
        // 0x800193B8: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_800194A8;
    }
    goto skip_0;
    // 0x800193B8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    skip_0:
    // 0x800193BC: lh          $s0, 0x72($sp)
    ctx->r16 = MEM_H(ctx->r29, 0X72);
    // 0x800193C0: lh          $t5, 0x48($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X48);
    // 0x800193C4: ori         $at, $zero, 0xFF00
    ctx->r1 = 0 | 0XFF00;
    // 0x800193C8: addu        $s0, $s0, $at
    ctx->r16 = ADD32(ctx->r16, ctx->r1);
    // 0x800193CC: sll         $t3, $s0, 16
    ctx->r11 = S32(ctx->r16 << 16);
    // 0x800193D0: beq         $t5, $zero, L_8001941C
    if (ctx->r13 == 0) {
        // 0x800193D4: sra         $s0, $t3, 16
        ctx->r16 = S32(SIGNED(ctx->r11) >> 16);
            goto L_8001941C;
    }
    // 0x800193D4: sra         $s0, $t3, 16
    ctx->r16 = S32(SIGNED(ctx->r11) >> 16);
    // 0x800193D8: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800193DC: beq         $fp, $zero, L_800193E8
    if (ctx->r30 == 0) {
        // 0x800193E0: sh          $zero, 0x48($sp)
        MEM_H(0X48, ctx->r29) = 0;
            goto L_800193E8;
    }
    // 0x800193E0: sh          $zero, 0x48($sp)
    MEM_H(0X48, ctx->r29) = 0;
    // 0x800193E4: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_800193E8:
    // 0x800193E8: subu        $a0, $s3, $v0
    ctx->r4 = SUB32(ctx->r19, ctx->r2);
    // 0x800193EC: sll         $a1, $s7, 16
    ctx->r5 = S32(ctx->r23 << 16);
    // 0x800193F0: sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16 << 16);
    // 0x800193F4: sra         $t9, $a2, 16
    ctx->r25 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800193F8: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800193FC: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80019400: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80019404: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80019408: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x8001940C: addiu       $a3, $zero, 0x2A
    ctx->r7 = ADD32(0, 0X2A);
    // 0x80019410: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80019414: jal         0x8004C580
    // 0x80019418: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_0;
    // 0x80019418: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_0:
L_8001941C:
    // 0x8001941C: beq         $fp, $zero, L_80019458
    if (ctx->r30 == 0) {
        // 0x80019420: addiu       $a0, $s3, -0x8
        ctx->r4 = ADD32(ctx->r19, -0X8);
            goto L_80019458;
    }
    // 0x80019420: addiu       $a0, $s3, -0x8
    ctx->r4 = ADD32(ctx->r19, -0X8);
    // 0x80019424: sll         $a1, $s7, 16
    ctx->r5 = S32(ctx->r23 << 16);
    // 0x80019428: sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16 << 16);
    // 0x8001942C: sra         $t3, $a2, 16
    ctx->r11 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80019430: sra         $t1, $a1, 16
    ctx->r9 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80019434: sll         $t0, $a0, 16
    ctx->r8 = S32(ctx->r4 << 16);
    // 0x80019438: sra         $a0, $t0, 16
    ctx->r4 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8001943C: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x80019440: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x80019444: addiu       $a3, $zero, 0x2B
    ctx->r7 = ADD32(0, 0X2B);
    // 0x80019448: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001944C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80019450: jal         0x8004C580
    // 0x80019454: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    func_8004C580(rdram, ctx);
        goto after_1;
    // 0x80019454: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    after_1:
L_80019458:
    // 0x80019458: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x8001945C: sll         $a1, $s7, 16
    ctx->r5 = S32(ctx->r23 << 16);
    // 0x80019460: sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16 << 16);
    // 0x80019464: addiu       $a3, $s1, 0x20
    ctx->r7 = ADD32(ctx->r17, 0X20);
    // 0x80019468: sll         $t7, $a3, 16
    ctx->r15 = S32(ctx->r7 << 16);
    // 0x8001946C: sra         $t6, $a2, 16
    ctx->r14 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80019470: sra         $t5, $a1, 16
    ctx->r13 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80019474: sra         $t4, $a0, 16
    ctx->r12 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80019478: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8001947C: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x80019480: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80019484: sra         $a3, $t7, 16
    ctx->r7 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80019488: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001948C: jal         0x8004C580
    // 0x80019490: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_2;
    // 0x80019490: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_2:
    // 0x80019494: multu       $s1, $s2
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80019498: mflo        $t9
    ctx->r25 = lo;
    // 0x8001949C: subu        $s5, $s5, $t9
    ctx->r21 = SUB32(ctx->r21, ctx->r25);
    // 0x800194A0: nop

    // 0x800194A4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
L_800194A8:
    // 0x800194A8: div         $zero, $s2, $at
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r1)));
    // 0x800194AC: lh          $t3, 0x6E($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X6E);
    // 0x800194B0: addiu       $s3, $s3, 0x7
    ctx->r19 = ADD32(ctx->r19, 0X7);
    // 0x800194B4: sll         $t2, $s3, 16
    ctx->r10 = S32(ctx->r19 << 16);
    // 0x800194B8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800194BC: mflo        $t0
    ctx->r8 = lo;
    // 0x800194C0: sra         $t1, $t2, 16
    ctx->r9 = S32(SIGNED(ctx->r10) >> 16);
    // 0x800194C4: or          $s2, $t0, $zero
    ctx->r18 = ctx->r8 | 0;
    // 0x800194C8: bne         $s4, $t3, L_80019358
    if (ctx->r20 != ctx->r11) {
        // 0x800194CC: or          $s3, $t1, $zero
        ctx->r19 = ctx->r9 | 0;
            goto L_80019358;
    }
    // 0x800194CC: or          $s3, $t1, $zero
    ctx->r19 = ctx->r9 | 0;
    // 0x800194D0: sh          $fp, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r30;
L_800194D4:
    // 0x800194D4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800194D8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800194DC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800194E0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800194E4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800194E8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800194EC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800194F0: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800194F4: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800194F8: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800194FC: jr          $ra
    // 0x80019500: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    TRACE_RETURN()
    return;
    // 0x80019500: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80019504(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80019504: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80019508: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8001950C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80019510: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80019514: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80019518: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8001951C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80019520: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80019524: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80019528: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8001952C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80019530: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x80019534: sh          $zero, 0x74($sp)
    MEM_H(0X74, ctx->r29) = 0;
    // 0x80019538: sh          $zero, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = 0;
    // 0x8001953C: sh          $zero, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = 0;
    // 0x80019540: sh          $zero, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = 0;
    // 0x80019544: sh          $zero, 0x68($sp)
    MEM_H(0X68, ctx->r29) = 0;
    // 0x80019548: sh          $zero, 0x66($sp)
    MEM_H(0X66, ctx->r29) = 0;
    // 0x8001954C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80019550: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80019554: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80019558: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x8001955C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80019560: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x80019564: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
    // 0x80019568: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8001956C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80019570: jal         0x8004D134
    // 0x80019574: sh          $t7, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = ctx->r15;
    func_8004D134(rdram, ctx);
        goto after_0;
    // 0x80019574: sh          $t7, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = ctx->r15;
    after_0:
    // 0x80019578: lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // 0x8001957C: addiu       $a0, $a0, -0x3900
    ctx->r4 = ADD32(ctx->r4, -0X3900);
    // 0x80019580: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    // 0x80019584: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80019588: jal         0x80004CE0
    // 0x8001958C: addiu       $a3, $sp, 0x60
    ctx->r7 = ADD32(ctx->r29, 0X60);
    func_80004CE0(rdram, ctx);
        goto after_1;
    // 0x8001958C: addiu       $a3, $sp, 0x60
    ctx->r7 = ADD32(ctx->r29, 0X60);
    after_1:
    // 0x80019590: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80019594: jal         0x8004B1E0
    // 0x80019598: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    func_8004B1E0(rdram, ctx);
        goto after_2;
    // 0x80019598: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_2:
    // 0x8001959C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800195A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800195A4: jal         0x8000BD4C
    // 0x800195A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BD4C(rdram, ctx);
        goto after_3;
    // 0x800195A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x800195AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800195B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800195B4: jal         0x8000BDEC
    // 0x800195B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BDEC(rdram, ctx);
        goto after_4;
    // 0x800195B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x800195BC: addiu       $t9, $zero, 0x3E8
    ctx->r25 = ADD32(0, 0X3E8);
    // 0x800195C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800195C4: sw          $t9, -0x2CF8($at)
    MEM_W(-0X2CF8, ctx->r1) = ctx->r25;
    // 0x800195C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800195CC: addiu       $t1, $zero, 0x3D0
    ctx->r9 = ADD32(0, 0X3D0);
    // 0x800195D0: sw          $t1, -0x2CF4($at)
    MEM_W(-0X2CF4, ctx->r1) = ctx->r9;
    // 0x800195D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800195D8: sh          $zero, -0x2CC4($at)
    MEM_H(-0X2CC4, ctx->r1) = 0;
    // 0x800195DC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800195E0: lui         $at, 0x4238
    ctx->r1 = S32(0X4238 << 16);
    // 0x800195E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800195E8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800195EC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800195F0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800195F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800195F8: addiu       $v1, $v1, -0x6C40
    ctx->r3 = ADD32(ctx->r3, -0X6C40);
    // 0x800195FC: addiu       $v0, $v0, -0x6C50
    ctx->r2 = ADD32(ctx->r2, -0X6C50);
    // 0x80019600: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80019604: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x80019608: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x8001960C: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x80019610: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80019614: jal         0x8000798C
    // 0x80019618: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    func_8000798C(rdram, ctx);
        goto after_5;
    // 0x80019618: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    after_5:
    // 0x8001961C: jal         0x8000798C
    // 0x80019620: nop

    func_8000798C(rdram, ctx);
        goto after_6;
    // 0x80019620: nop

    after_6:
    // 0x80019624: jal         0x8000798C
    // 0x80019628: nop

    func_8000798C(rdram, ctx);
        goto after_7;
    // 0x80019628: nop

    after_7:
    // 0x8001962C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80019630: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80019634: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x80019638: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001963C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80019640: jal         0x8004C580
    // 0x80019644: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_8;
    // 0x80019644: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_8:
    // 0x80019648: lh          $t2, 0x8A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X8A);
    // 0x8001964C: lui         $a3, 0x8007
    ctx->r7 = S32(0X8007 << 16);
    // 0x80019650: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80019654: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80019658: addu        $a3, $a3, $t3
    ctx->r7 = ADD32(ctx->r7, ctx->r11);
    // 0x8001965C: lh          $a3, -0x652C($a3)
    ctx->r7 = MEM_H(ctx->r7, -0X652C);
    // 0x80019660: addiu       $a1, $zero, 0x58
    ctx->r5 = ADD32(0, 0X58);
    // 0x80019664: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x80019668: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001966C: jal         0x8004C580
    // 0x80019670: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_9;
    // 0x80019670: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_9:
    // 0x80019674: lui         $s7, 0x8007
    ctx->r23 = S32(0X8007 << 16);
    // 0x80019678: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8001967C: addiu       $s7, $s7, -0x655C
    ctx->r23 = ADD32(ctx->r23, -0X655C);
    // 0x80019680: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80019684: addiu       $s6, $zero, 0xC
    ctx->r22 = ADD32(0, 0XC);
L_80019688:
    // 0x80019688: multu       $s2, $s6
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001968C: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x80019690: sra         $t4, $a1, 16
    ctx->r12 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80019694: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x80019698: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8001969C: mflo        $t5
    ctx->r13 = lo;
    // 0x800196A0: addu        $a2, $t5, $s7
    ctx->r6 = ADD32(ctx->r13, ctx->r23);
    // 0x800196A4: jal         0x8001A37C
    // 0x800196A8: nop

    func_8001A37C(rdram, ctx);
        goto after_10;
    // 0x800196A8: nop

    after_10:
    // 0x800196AC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800196B0: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x800196B4: sra         $s2, $t6, 16
    ctx->r18 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800196B8: slti        $at, $s2, 0x4
    ctx->r1 = SIGNED(ctx->r18) < 0X4 ? 1 : 0;
    // 0x800196BC: bne         $at, $zero, L_80019688
    if (ctx->r1 != 0) {
        // 0x800196C0: nop
    
            goto L_80019688;
    }
    // 0x800196C0: nop

    // 0x800196C4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800196C8: lh          $a1, 0x6C($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X6C);
    // 0x800196CC: addiu       $a0, $zero, 0x4B31
    ctx->r4 = ADD32(0, 0X4B31);
L_800196D0:
    // 0x800196D0: multu       $s2, $s6
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800196D4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800196D8: sll         $t4, $s2, 16
    ctx->r12 = S32(ctx->r18 << 16);
    // 0x800196DC: sra         $s2, $t4, 16
    ctx->r18 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800196E0: slti        $at, $s2, 0x4
    ctx->r1 = SIGNED(ctx->r18) < 0X4 ? 1 : 0;
    // 0x800196E4: mflo        $t8
    ctx->r24 = lo;
    // 0x800196E8: addu        $t9, $s7, $t8
    ctx->r25 = ADD32(ctx->r23, ctx->r24);
    // 0x800196EC: lhu         $t1, 0x0($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X0);
    // 0x800196F0: bne         $a0, $t1, L_80019704
    if (ctx->r4 != ctx->r9) {
        // 0x800196F4: nop
    
            goto L_80019704;
    }
    // 0x800196F4: nop

    // 0x800196F8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800196FC: sll         $t2, $a1, 16
    ctx->r10 = S32(ctx->r5 << 16);
    // 0x80019700: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
L_80019704:
    // 0x80019704: bne         $at, $zero, L_800196D0
    if (ctx->r1 != 0) {
        // 0x80019708: nop
    
            goto L_800196D0;
    }
    // 0x80019708: nop

    // 0x8001970C: lh          $t6, 0x8A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X8A);
    // 0x80019710: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80019714: beql        $t6, $v0, L_80019744
    if (ctx->r14 == ctx->r2) {
        // 0x80019718: sh          $a1, 0x6C($sp)
        MEM_H(0X6C, ctx->r29) = ctx->r5;
            goto L_80019744;
    }
    goto skip_0;
    // 0x80019718: sh          $a1, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = ctx->r5;
    skip_0:
    // 0x8001971C: bne         $a1, $zero, L_80019740
    if (ctx->r5 != 0) {
        // 0x80019720: or          $v1, $s3, $zero
        ctx->r3 = ctx->r19 | 0;
            goto L_80019740;
    }
    // 0x80019720: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
    // 0x80019724: sh          $a1, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = ctx->r5;
    // 0x80019728: sh          $v0, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r2;
    // 0x8001972C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80019730: lh          $s0, 0x7E($sp)
    ctx->r16 = MEM_H(ctx->r29, 0X7E);
    // 0x80019734: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80019738: b           L_800198E0
    // 0x8001973C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
        goto L_800198E0;
    // 0x8001973C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
L_80019740:
    // 0x80019740: sh          $a1, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = ctx->r5;
L_80019744:
    // 0x80019744: lh          $t7, 0x66($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X66);
    // 0x80019748: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8001974C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80019750: beq         $t7, $zero, L_80019884
    if (ctx->r15 == 0) {
        // 0x80019754: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80019884;
    }
    // 0x80019754: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80019758: bne         $t8, $at, L_80019884
    if (ctx->r24 != ctx->r1) {
        // 0x8001975C: nop
    
            goto L_80019884;
    }
    // 0x8001975C: nop

    // 0x80019760: jal         0x8004C4D8
    // 0x80019764: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004C4D8(rdram, ctx);
        goto after_11;
    // 0x80019764: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80019768: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8001976C: jal         0x8004C4D8
    // 0x80019770: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004C4D8(rdram, ctx);
        goto after_12;
    // 0x80019770: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80019774: jal         0x8004B21C
    // 0x80019778: nop

    func_8004B21C(rdram, ctx);
        goto after_13;
    // 0x80019778: nop

    after_13:
    // 0x8001977C: jal         0x80004E5C
    // 0x80019780: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    func_80004E5C(rdram, ctx);
        goto after_14;
    // 0x80019780: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    after_14:
    // 0x80019784: jal         0x8000798C
    // 0x80019788: nop

    func_8000798C(rdram, ctx);
        goto after_15;
    // 0x80019788: nop

    after_15:
    // 0x8001978C: lh          $t9, 0x68($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X68);
    // 0x80019790: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80019794: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
    // 0x80019798: beq         $t9, $zero, L_80019810
    if (ctx->r25 == 0) {
        // 0x8001979C: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80019810;
    }
    // 0x8001979C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800197A0: lw          $t1, 0x90($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X90);
    // 0x800197A4: addiu       $t4, $zero, 0x9
    ctx->r12 = ADD32(0, 0X9);
    // 0x800197A8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800197AC: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x800197B0: sh          $t4, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r12;
    // 0x800197B4: sh          $t5, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r13;
    // 0x800197B8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800197BC: sh          $t6, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r14;
    // 0x800197C0: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x800197C4: sh          $t7, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r15;
    // 0x800197C8: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x800197CC: sh          $t8, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r24;
    // 0x800197D0: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x800197D4: sh          $t9, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r25;
    // 0x800197D8: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x800197DC: sh          $t1, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r9;
    // 0x800197E0: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x800197E4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800197E8: sh          $t3, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r11;
    // 0x800197EC: sh          $t4, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r12;
    // 0x800197F0: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x800197F4: sh          $zero, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = 0;
    // 0x800197F8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800197FC: sh          $t2, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r10;
    // 0x80019800: sh          $t5, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r13;
    // 0x80019804: sh          $zero, 0x76($sp)
    MEM_H(0X76, ctx->r29) = 0;
    // 0x80019808: b           L_80019874
    // 0x8001980C: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
        goto L_80019874;
    // 0x8001980C: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
L_80019810:
    // 0x80019810: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80019814: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x80019818: sh          $t1, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r9;
    // 0x8001981C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80019820: sh          $t2, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r10;
    // 0x80019824: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80019828: sh          $t3, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r11;
    // 0x8001982C: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80019830: sh          $t4, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r12;
    // 0x80019834: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x80019838: sh          $t5, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r13;
    // 0x8001983C: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80019840: sh          $t6, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r14;
    // 0x80019844: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80019848: sh          $t7, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r15;
    // 0x8001984C: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x80019850: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80019854: sh          $t9, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r25;
    // 0x80019858: sh          $t1, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r9;
    // 0x8001985C: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x80019860: sh          $zero, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = 0;
    // 0x80019864: sh          $t8, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r24;
    // 0x80019868: sh          $t2, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r10;
    // 0x8001986C: sh          $zero, 0x76($sp)
    MEM_H(0X76, ctx->r29) = 0;
    // 0x80019870: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
L_80019874:
    // 0x80019874: jal         0x8000798C
    // 0x80019878: nop

    func_8000798C(rdram, ctx);
        goto after_16;
    // 0x80019878: nop

    after_16:
    // 0x8001987C: b           L_80019874
    // 0x80019880: nop

        goto L_80019874;
    // 0x80019880: nop

L_80019884:
    // 0x80019884: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80019888: lhu         $s0, -0x2E5A($s0)
    ctx->r16 = MEM_HU(ctx->r16, -0X2E5A);
    // 0x8001988C: andi        $t3, $s0, 0x9000
    ctx->r11 = ctx->r16 & 0X9000;
    // 0x80019890: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x80019894: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80019898: beq         $s4, $zero, L_800198C0
    if (ctx->r20 == 0) {
        // 0x8001989C: or          $s0, $t5, $zero
        ctx->r16 = ctx->r13 | 0;
            goto L_800198C0;
    }
    // 0x8001989C: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
    // 0x800198A0: beq         $t5, $zero, L_800198C0
    if (ctx->r13 == 0) {
        // 0x800198A4: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_800198C0;
    }
    // 0x800198A4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800198A8: bnel        $fp, $at, L_800198C0
    if (ctx->r30 != ctx->r1) {
        // 0x800198AC: sh          $v0, 0x76($sp)
        MEM_H(0X76, ctx->r29) = ctx->r2;
            goto L_800198C0;
    }
    goto skip_1;
    // 0x800198AC: sh          $v0, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r2;
    skip_1:
    // 0x800198B0: jal         0x80044480
    // 0x800198B4: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_80044480(rdram, ctx);
        goto after_17;
    // 0x800198B4: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_17:
    // 0x800198B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800198BC: sh          $v0, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r2;
L_800198C0:
    // 0x800198C0: lh          $t6, 0x66($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X66);
    // 0x800198C4: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
    // 0x800198C8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800198CC: beq         $t6, $zero, L_800198DC
    if (ctx->r14 == 0) {
        // 0x800198D0: lh          $a1, 0x8A($sp)
        ctx->r5 = MEM_H(ctx->r29, 0X8A);
            goto L_800198DC;
    }
    // 0x800198D0: lh          $a1, 0x8A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X8A);
    // 0x800198D4: b           L_80019D50
    // 0x800198D8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
        goto L_80019D50;
    // 0x800198D8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_800198DC:
    // 0x800198DC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
L_800198E0:
    // 0x800198E0: sltiu       $at, $v1, 0xB
    ctx->r1 = ctx->r3 < 0XB ? 1 : 0;
L_800198E4:
    // 0x800198E4: beq         $at, $zero, L_80019D4C
    if (ctx->r1 == 0) {
        // 0x800198E8: sll         $t7, $v1, 2
        ctx->r15 = S32(ctx->r3 << 2);
            goto L_80019D4C;
    }
    // 0x800198E8: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800198EC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800198F0: addu        $at, $at, $t7
    gpr jr_addend_800198F8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800198F4: lw          $t7, 0x6450($at)
    ctx->r15 = ADD32(ctx->r1, 0X6450);
    // 0x800198F8: jr          $t7
    // 0x800198FC: nop

    switch (jr_addend_800198F8 >> 2) {
        case 0: goto L_80019900; break;
        case 1: goto L_800199C4; break;
        case 2: goto L_80019A54; break;
        case 3: goto L_80019AF0; break;
        case 4: goto L_80019B8C; break;
        case 5: goto L_80019C10; break;
        case 6: goto L_80019C40; break;
        case 7: goto L_80019CC4; break;
        case 8: goto L_80019D4C; break;
        case 9: goto L_80019D4C; break;
        case 10: goto L_80019D38; break;
        default: switch_error(__func__, 0x800198F8, 0x80076450);
    }
    // 0x800198FC: nop

L_80019900:
    // 0x80019900: lh          $t8, 0x6A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X6A);
    // 0x80019904: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x80019908: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8001990C: beq         $t8, $zero, L_80019930
    if (ctx->r24 == 0) {
        // 0x80019910: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80019930;
    }
    // 0x80019910: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80019914: sll         $s5, $a2, 16
    ctx->r21 = S32(ctx->r6 << 16);
    // 0x80019918: sra         $t1, $s5, 16
    ctx->r9 = S32(SIGNED(ctx->r21) >> 16);
    // 0x8001991C: sh          $t9, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r25;
    // 0x80019920: or          $s5, $t1, $zero
    ctx->r21 = ctx->r9 | 0;
    // 0x80019924: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80019928: b           L_80019938
    // 0x8001992C: sh          $zero, 0x76($sp)
    MEM_H(0X76, ctx->r29) = 0;
        goto L_80019938;
    // 0x8001992C: sh          $zero, 0x76($sp)
    MEM_H(0X76, ctx->r29) = 0;
L_80019930:
    // 0x80019930: sh          $v0, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r2;
    // 0x80019934: sh          $zero, 0x76($sp)
    MEM_H(0X76, ctx->r29) = 0;
L_80019938:
    // 0x80019938: beql        $s0, $zero, L_80019D50
    if (ctx->r16 == 0) {
        // 0x8001993C: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80019D50;
    }
    goto skip_2;
    // 0x8001993C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    skip_2:
    // 0x80019940: bne         $s5, $a2, L_80019970
    if (ctx->r21 != ctx->r6) {
        // 0x80019944: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_80019970;
    }
    // 0x80019944: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80019948: sh          $t2, 0x66($sp)
    MEM_H(0X66, ctx->r29) = ctx->r10;
    // 0x8001994C: jal         0x80044480
    // 0x80019950: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    func_80044480(rdram, ctx);
        goto after_18;
    // 0x80019950: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_18:
    // 0x80019954: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
L_80019958:
    // 0x80019958: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001995C: jal         0x8004D134
    // 0x80019960: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_8004D134(rdram, ctx);
        goto after_19;
    // 0x80019960: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_19:
    // 0x80019964: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80019968: b           L_80019D4C
    // 0x8001996C: sw          $t3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r11;
        goto L_80019D4C;
    // 0x8001996C: sw          $t3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r11;
L_80019970:
    // 0x80019970: beql        $a1, $v0, L_80019994
    if (ctx->r5 == ctx->r2) {
        // 0x80019974: sll         $s3, $v0, 16
        ctx->r19 = S32(ctx->r2 << 16);
            goto L_80019994;
    }
    goto skip_3;
    // 0x80019974: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    skip_3:
    // 0x80019978: beql        $a1, $at, L_800199A8
    if (ctx->r5 == ctx->r1) {
        // 0x8001997C: addiu       $s3, $zero, 0x2
        ctx->r19 = ADD32(0, 0X2);
            goto L_800199A8;
    }
    goto skip_4;
    // 0x8001997C: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    skip_4:
    // 0x80019980: beql        $a1, $a0, L_800199B4
    if (ctx->r5 == ctx->r4) {
        // 0x80019984: sll         $s3, $a0, 16
        ctx->r19 = S32(ctx->r4 << 16);
            goto L_800199B4;
    }
    goto skip_5;
    // 0x80019984: sll         $s3, $a0, 16
    ctx->r19 = S32(ctx->r4 << 16);
    skip_5:
    // 0x80019988: b           L_800198E4
    // 0x8001998C: sltiu       $at, $v1, 0xB
    ctx->r1 = ctx->r3 < 0XB ? 1 : 0;
        goto L_800198E4;
    // 0x8001998C: sltiu       $at, $v1, 0xB
    ctx->r1 = ctx->r3 < 0XB ? 1 : 0;
    // 0x80019990: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
L_80019994:
    // 0x80019994: sra         $t4, $s3, 16
    ctx->r12 = S32(SIGNED(ctx->r19) >> 16);
    // 0x80019998: or          $s3, $t4, $zero
    ctx->r19 = ctx->r12 | 0;
    // 0x8001999C: b           L_800198E0
    // 0x800199A0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800198E0;
    // 0x800199A0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800199A4: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
L_800199A8:
    // 0x800199A8: b           L_800198E0
    // 0x800199AC: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_800198E0;
    // 0x800199AC: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800199B0: sll         $s3, $a0, 16
    ctx->r19 = S32(ctx->r4 << 16);
L_800199B4:
    // 0x800199B4: sra         $t5, $s3, 16
    ctx->r13 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800199B8: or          $s3, $t5, $zero
    ctx->r19 = ctx->r13 | 0;
    // 0x800199BC: b           L_800198E0
    // 0x800199C0: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
        goto L_800198E0;
    // 0x800199C0: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_800199C4:
    // 0x800199C4: bne         $s4, $zero, L_80019A20
    if (ctx->r20 != 0) {
        // 0x800199C8: lh          $t1, 0x76($sp)
        ctx->r9 = MEM_H(ctx->r29, 0X76);
            goto L_80019A20;
    }
    // 0x800199C8: lh          $t1, 0x76($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X76);
    // 0x800199CC: multu       $s5, $s6
    result = U64(U32(ctx->r21)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800199D0: addiu       $at, $zero, 0x4B31
    ctx->r1 = ADD32(0, 0X4B31);
    // 0x800199D4: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800199D8: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x800199DC: addiu       $fp, $zero, -0x1
    ctx->r30 = ADD32(0, -0X1);
    // 0x800199E0: mflo        $t6
    ctx->r14 = lo;
    // 0x800199E4: addu        $t7, $s7, $t6
    ctx->r15 = ADD32(ctx->r23, ctx->r14);
    // 0x800199E8: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x800199EC: bnel        $t8, $at, L_80019A0C
    if (ctx->r24 != ctx->r1) {
        // 0x800199F0: sh          $a0, 0x88($sp)
        MEM_H(0X88, ctx->r29) = ctx->r4;
            goto L_80019A0C;
    }
    goto skip_6;
    // 0x800199F0: sh          $a0, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r4;
    skip_6:
    // 0x800199F4: sh          $t9, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r25;
    // 0x800199F8: sh          $zero, 0x76($sp)
    MEM_H(0X76, ctx->r29) = 0;
    // 0x800199FC: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80019A00: b           L_80019A10
    // 0x80019A04: addiu       $fp, $zero, -0x1
    ctx->r30 = ADD32(0, -0X1);
        goto L_80019A10;
    // 0x80019A04: addiu       $fp, $zero, -0x1
    ctx->r30 = ADD32(0, -0X1);
    // 0x80019A08: sh          $a0, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r4;
L_80019A0C:
    // 0x80019A0C: sh          $zero, 0x76($sp)
    MEM_H(0X76, ctx->r29) = 0;
L_80019A10:
    // 0x80019A10: jal         0x80044480
    // 0x80019A14: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    func_80044480(rdram, ctx);
        goto after_20;
    // 0x80019A14: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_20:
    // 0x80019A18: b           L_80019D50
    // 0x80019A1C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
        goto L_80019D50;
    // 0x80019A1C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80019A20:
    // 0x80019A20: beql        $t1, $zero, L_80019D50
    if (ctx->r9 == 0) {
        // 0x80019A24: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80019D50;
    }
    goto skip_7;
    // 0x80019A24: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    skip_7:
    // 0x80019A28: bne         $fp, $v0, L_80019A44
    if (ctx->r30 != ctx->r2) {
        // 0x80019A2C: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_80019A44;
    }
    // 0x80019A2C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80019A30: sll         $s3, $a2, 16
    ctx->r19 = S32(ctx->r6 << 16);
    // 0x80019A34: sra         $v1, $s3, 16
    ctx->r3 = S32(SIGNED(ctx->r19) >> 16);
    // 0x80019A38: or          $s3, $v1, $zero
    ctx->r19 = ctx->r3 | 0;
    // 0x80019A3C: b           L_800198E0
    // 0x80019A40: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
        goto L_800198E0;
    // 0x80019A40: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_80019A44:
    // 0x80019A44: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80019A48: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80019A4C: b           L_800198E0
    // 0x80019A50: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
        goto L_800198E0;
    // 0x80019A50: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
L_80019A54:
    // 0x80019A54: bne         $s4, $zero, L_80019AC0
    if (ctx->r20 != 0) {
        // 0x80019A58: lh          $t7, 0x76($sp)
        ctx->r15 = MEM_H(ctx->r29, 0X76);
            goto L_80019AC0;
    }
    // 0x80019A58: lh          $t7, 0x76($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X76);
    // 0x80019A5C: multu       $s5, $s6
    result = U64(U32(ctx->r21)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80019A60: addiu       $at, $zero, 0x4B31
    ctx->r1 = ADD32(0, 0X4B31);
    // 0x80019A64: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x80019A68: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80019A6C: mflo        $t3
    ctx->r11 = lo;
    // 0x80019A70: addu        $t4, $s7, $t3
    ctx->r12 = ADD32(ctx->r23, ctx->r11);
    // 0x80019A74: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x80019A78: bne         $t5, $at, L_80019AA0
    if (ctx->r13 != ctx->r1) {
        // 0x80019A7C: addiu       $t6, $zero, 0x6
        ctx->r14 = ADD32(0, 0X6);
            goto L_80019AA0;
    }
    // 0x80019A7C: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80019A80: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80019A84: addiu       $fp, $zero, -0x1
    ctx->r30 = ADD32(0, -0X1);
    // 0x80019A88: sh          $zero, 0x76($sp)
    MEM_H(0X76, ctx->r29) = 0;
    // 0x80019A8C: sh          $t6, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r14;
    // 0x80019A90: jal         0x80044480
    // 0x80019A94: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    func_80044480(rdram, ctx);
        goto after_21;
    // 0x80019A94: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_21:
    // 0x80019A98: b           L_80019D50
    // 0x80019A9C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
        goto L_80019D50;
    // 0x80019A9C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80019AA0:
    // 0x80019AA0: jal         0x80044480
    // 0x80019AA4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    func_80044480(rdram, ctx);
        goto after_22;
    // 0x80019AA4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    after_22:
    // 0x80019AA8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80019AAC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80019AB0: lh          $a1, 0x8A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X8A);
    // 0x80019AB4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80019AB8: b           L_800198E0
    // 0x80019ABC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800198E0;
    // 0x80019ABC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80019AC0:
    // 0x80019AC0: beql        $t7, $zero, L_80019D50
    if (ctx->r15 == 0) {
        // 0x80019AC4: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80019D50;
    }
    goto skip_8;
    // 0x80019AC4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    skip_8:
    // 0x80019AC8: bne         $fp, $v0, L_80019AE0
    if (ctx->r30 != ctx->r2) {
        // 0x80019ACC: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_80019AE0;
    }
    // 0x80019ACC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80019AD0: addiu       $s3, $zero, 0x6
    ctx->r19 = ADD32(0, 0X6);
    // 0x80019AD4: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80019AD8: b           L_800198E0
    // 0x80019ADC: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
        goto L_800198E0;
    // 0x80019ADC: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
L_80019AE0:
    // 0x80019AE0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80019AE4: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80019AE8: b           L_800198E0
    // 0x80019AEC: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
        goto L_800198E0;
    // 0x80019AEC: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
L_80019AF0:
    // 0x80019AF0: bne         $s4, $zero, L_80019B5C
    if (ctx->r20 != 0) {
        // 0x80019AF4: lh          $t3, 0x76($sp)
        ctx->r11 = MEM_H(ctx->r29, 0X76);
            goto L_80019B5C;
    }
    // 0x80019AF4: lh          $t3, 0x76($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X76);
    // 0x80019AF8: multu       $s5, $s6
    result = U64(U32(ctx->r21)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80019AFC: addiu       $at, $zero, 0x4B31
    ctx->r1 = ADD32(0, 0X4B31);
    // 0x80019B00: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x80019B04: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80019B08: mflo        $t8
    ctx->r24 = lo;
    // 0x80019B0C: addu        $t9, $s7, $t8
    ctx->r25 = ADD32(ctx->r23, ctx->r24);
    // 0x80019B10: lhu         $t1, 0x0($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X0);
    // 0x80019B14: bne         $t1, $at, L_80019B3C
    if (ctx->r9 != ctx->r1) {
        // 0x80019B18: addiu       $t2, $zero, 0x7
        ctx->r10 = ADD32(0, 0X7);
            goto L_80019B3C;
    }
    // 0x80019B18: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x80019B1C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80019B20: addiu       $fp, $zero, -0x1
    ctx->r30 = ADD32(0, -0X1);
    // 0x80019B24: sh          $zero, 0x76($sp)
    MEM_H(0X76, ctx->r29) = 0;
    // 0x80019B28: sh          $t2, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r10;
    // 0x80019B2C: jal         0x80044480
    // 0x80019B30: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    func_80044480(rdram, ctx);
        goto after_23;
    // 0x80019B30: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_23:
    // 0x80019B34: b           L_80019D50
    // 0x80019B38: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
        goto L_80019D50;
    // 0x80019B38: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80019B3C:
    // 0x80019B3C: jal         0x80044480
    // 0x80019B40: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    func_80044480(rdram, ctx);
        goto after_24;
    // 0x80019B40: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    after_24:
    // 0x80019B44: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80019B48: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80019B4C: lh          $a1, 0x8A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X8A);
    // 0x80019B50: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80019B54: b           L_800198E0
    // 0x80019B58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800198E0;
    // 0x80019B58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80019B5C:
    // 0x80019B5C: beql        $t3, $zero, L_80019D50
    if (ctx->r11 == 0) {
        // 0x80019B60: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80019D50;
    }
    goto skip_9;
    // 0x80019B60: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    skip_9:
    // 0x80019B64: bne         $fp, $v0, L_80019B7C
    if (ctx->r30 != ctx->r2) {
        // 0x80019B68: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_80019B7C;
    }
    // 0x80019B68: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80019B6C: addiu       $s3, $zero, 0x7
    ctx->r19 = ADD32(0, 0X7);
    // 0x80019B70: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80019B74: b           L_800198E0
    // 0x80019B78: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
        goto L_800198E0;
    // 0x80019B78: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
L_80019B7C:
    // 0x80019B7C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80019B80: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80019B84: b           L_800198E0
    // 0x80019B88: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
        goto L_800198E0;
    // 0x80019B88: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
L_80019B8C:
    // 0x80019B8C: sll         $v0, $s5, 2
    ctx->r2 = S32(ctx->r21 << 2);
    // 0x80019B90: subu        $v0, $v0, $s5
    ctx->r2 = SUB32(ctx->r2, ctx->r21);
    // 0x80019B94: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80019B98: addu        $s0, $s7, $v0
    ctx->r16 = ADD32(ctx->r23, ctx->r2);
    // 0x80019B9C: addu        $s1, $v0, $s7
    ctx->r17 = ADD32(ctx->r2, ctx->r23);
    // 0x80019BA0: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80019BA4: jal         0x80044480
    // 0x80019BA8: addiu       $s3, $zero, 0x5
    ctx->r19 = ADD32(0, 0X5);
    func_80044480(rdram, ctx);
        goto after_25;
    // 0x80019BA8: addiu       $s3, $zero, 0x5
    ctx->r19 = ADD32(0, 0X5);
    after_25:
    // 0x80019BAC: addiu       $t4, $zero, 0x4B31
    ctx->r12 = ADD32(0, 0X4B31);
    // 0x80019BB0: sh          $t4, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r12;
    // 0x80019BB4: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80019BB8: lw          $t5, -0x68C8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X68C8);
    // 0x80019BBC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80019BC0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80019BC4: sb          $t5, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r13;
    // 0x80019BC8: lh          $t6, -0x662C($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X662C);
    // 0x80019BCC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80019BD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80019BD4: sb          $t6, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r14;
    // 0x80019BD8: lh          $t7, -0x6B90($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X6B90);
    // 0x80019BDC: sb          $t7, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r15;
    // 0x80019BE0: lw          $t8, -0x6BD4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6BD4);
    // 0x80019BE4: jal         0x80024484
    // 0x80019BE8: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
    func_80024484(rdram, ctx);
        goto after_26;
    // 0x80019BE8: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
    after_26:
    // 0x80019BEC: sll         $a1, $s5, 16
    ctx->r5 = S32(ctx->r21 << 16);
    // 0x80019BF0: sra         $t9, $a1, 16
    ctx->r25 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80019BF4: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x80019BF8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80019BFC: jal         0x8001A37C
    // 0x80019C00: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_8001A37C(rdram, ctx);
        goto after_27;
    // 0x80019C00: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_27:
    // 0x80019C04: addiu       $t1, $zero, 0x1E
    ctx->r9 = ADD32(0, 0X1E);
    // 0x80019C08: sh          $t1, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r9;
    // 0x80019C0C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
L_80019C10:
    // 0x80019C10: lh          $t2, 0x74($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X74);
    // 0x80019C14: sh          $a2, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r6;
    // 0x80019C18: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80019C1C: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x80019C20: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80019C24: bne         $t5, $zero, L_80019D4C
    if (ctx->r13 != 0) {
        // 0x80019C28: sh          $t3, 0x74($sp)
        MEM_H(0X74, ctx->r29) = ctx->r11;
            goto L_80019D4C;
    }
    // 0x80019C28: sh          $t3, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r11;
    // 0x80019C2C: sll         $s5, $a2, 16
    ctx->r21 = S32(ctx->r6 << 16);
    // 0x80019C30: sra         $t6, $s5, 16
    ctx->r14 = S32(SIGNED(ctx->r21) >> 16);
    // 0x80019C34: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80019C38: b           L_80019D4C
    // 0x80019C3C: or          $s5, $t6, $zero
    ctx->r21 = ctx->r14 | 0;
        goto L_80019D4C;
    // 0x80019C3C: or          $s5, $t6, $zero
    ctx->r21 = ctx->r14 | 0;
L_80019C40:
    // 0x80019C40: sll         $v0, $s5, 2
    ctx->r2 = S32(ctx->r21 << 2);
    // 0x80019C44: subu        $v0, $v0, $s5
    ctx->r2 = SUB32(ctx->r2, ctx->r21);
    // 0x80019C48: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80019C4C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80019C50: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80019C54: sh          $t8, 0x68($sp)
    MEM_H(0X68, ctx->r29) = ctx->r24;
    // 0x80019C58: sh          $t7, 0x66($sp)
    MEM_H(0X66, ctx->r29) = ctx->r15;
    // 0x80019C5C: addu        $s0, $s7, $v0
    ctx->r16 = ADD32(ctx->r23, ctx->r2);
    // 0x80019C60: addu        $s1, $v0, $s7
    ctx->r17 = ADD32(ctx->r2, ctx->r23);
    // 0x80019C64: jal         0x80044480
    // 0x80019C68: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    func_80044480(rdram, ctx);
        goto after_28;
    // 0x80019C68: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_28:
    // 0x80019C6C: sll         $a1, $s5, 16
    ctx->r5 = S32(ctx->r21 << 16);
    // 0x80019C70: sra         $t9, $a1, 16
    ctx->r25 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80019C74: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x80019C78: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80019C7C: jal         0x8001A37C
    // 0x80019C80: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_8001A37C(rdram, ctx);
        goto after_29;
    // 0x80019C80: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_29:
    // 0x80019C84: lbu         $t1, 0x2($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X2);
    // 0x80019C88: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80019C8C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80019C90: sw          $t1, -0x68C8($at)
    MEM_W(-0X68C8, ctx->r1) = ctx->r9;
    // 0x80019C94: lbu         $t2, 0x3($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X3);
    // 0x80019C98: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80019C9C: sh          $t2, -0x662C($at)
    MEM_H(-0X662C, ctx->r1) = ctx->r10;
    // 0x80019CA0: lbu         $t3, 0x4($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X4);
    // 0x80019CA4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80019CA8: sh          $t3, -0x6B90($at)
    MEM_H(-0X6B90, ctx->r1) = ctx->r11;
    // 0x80019CAC: lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8);
    // 0x80019CB0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80019CB4: jal         0x80024484
    // 0x80019CB8: sw          $t4, -0x6BD4($at)
    MEM_W(-0X6BD4, ctx->r1) = ctx->r12;
    func_80024484(rdram, ctx);
        goto after_30;
    // 0x80019CB8: sw          $t4, -0x6BD4($at)
    MEM_W(-0X6BD4, ctx->r1) = ctx->r12;
    after_30:
    // 0x80019CBC: b           L_80019958
    // 0x80019CC0: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
        goto L_80019958;
    // 0x80019CC0: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
L_80019CC4:
    // 0x80019CC4: sll         $s1, $s5, 3
    ctx->r17 = S32(ctx->r21 << 3);
    // 0x80019CC8: sll         $t7, $s5, 2
    ctx->r15 = S32(ctx->r21 << 2);
    // 0x80019CCC: subu        $t7, $t7, $s5
    ctx->r15 = SUB32(ctx->r15, ctx->r21);
    // 0x80019CD0: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x80019CD4: sll         $t5, $s1, 16
    ctx->r13 = S32(ctx->r17 << 16);
    // 0x80019CD8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80019CDC: addu        $s0, $s7, $t7
    ctx->r16 = ADD32(ctx->r23, ctx->r15);
    // 0x80019CE0: sra         $s1, $t5, 16
    ctx->r17 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80019CE4: jal         0x80044480
    // 0x80019CE8: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    func_80044480(rdram, ctx);
        goto after_31;
    // 0x80019CE8: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_31:
    // 0x80019CEC: sll         $a1, $s1, 16
    ctx->r5 = S32(ctx->r17 << 16);
    // 0x80019CF0: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80019CF4: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80019CF8: addiu       $a2, $a2, -0x64F0
    ctx->r6 = ADD32(ctx->r6, -0X64F0);
    // 0x80019CFC: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80019D00: jal         0x8001A37C
    // 0x80019D04: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    func_8001A37C(rdram, ctx);
        goto after_32;
    // 0x80019D04: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_32:
    // 0x80019D08: lh          $t9, 0x6C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X6C);
    // 0x80019D0C: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x80019D10: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80019D14: addiu       $t1, $t9, -0x1
    ctx->r9 = ADD32(ctx->r25, -0X1);
    // 0x80019D18: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x80019D1C: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80019D20: bne         $t3, $zero, L_80019D30
    if (ctx->r11 != 0) {
        // 0x80019D24: sh          $t1, 0x6C($sp)
        MEM_H(0X6C, ctx->r29) = ctx->r9;
            goto L_80019D30;
    }
    // 0x80019D24: sh          $t1, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = ctx->r9;
    // 0x80019D28: sh          $t4, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r12;
    // 0x80019D2C: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
L_80019D30:
    // 0x80019D30: b           L_80019D4C
    // 0x80019D34: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
        goto L_80019D4C;
    // 0x80019D34: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80019D38:
    // 0x80019D38: sll         $s5, $a2, 16
    ctx->r21 = S32(ctx->r6 << 16);
    // 0x80019D3C: addiu       $t5, $zero, 0x9
    ctx->r13 = ADD32(0, 0X9);
    // 0x80019D40: sra         $t6, $s5, 16
    ctx->r14 = S32(SIGNED(ctx->r21) >> 16);
    // 0x80019D44: sh          $t5, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r13;
    // 0x80019D48: or          $s5, $t6, $zero
    ctx->r21 = ctx->r14 | 0;
L_80019D4C:
    // 0x80019D4C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80019D50:
    // 0x80019D50: multu       $s2, $s6
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80019D54: sll         $t6, $s2, 2
    ctx->r14 = S32(ctx->r18 << 2);
    // 0x80019D58: sll         $t9, $s2, 2
    ctx->r25 = S32(ctx->r18 << 2);
    // 0x80019D5C: subu        $t6, $t6, $s2
    ctx->r14 = SUB32(ctx->r14, ctx->r18);
    // 0x80019D60: addiu       $at, $zero, 0x4B31
    ctx->r1 = ADD32(0, 0X4B31);
    // 0x80019D64: subu        $t9, $t9, $s2
    ctx->r25 = SUB32(ctx->r25, ctx->r18);
    // 0x80019D68: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80019D6C: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80019D70: addiu       $a2, $zero, -0x100
    ctx->r6 = ADD32(0, -0X100);
    // 0x80019D74: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x80019D78: mflo        $t7
    ctx->r15 = lo;
    // 0x80019D7C: addu        $s1, $s7, $t7
    ctx->r17 = ADD32(ctx->r23, ctx->r15);
    // 0x80019D80: lhu         $t8, 0x0($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X0);
    // 0x80019D84: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x80019D88: addiu       $t7, $t7, -0x6524
    ctx->r15 = ADD32(ctx->r15, -0X6524);
    // 0x80019D8C: bne         $t8, $at, L_80019E64
    if (ctx->r24 != ctx->r1) {
        // 0x80019D90: addu        $s0, $t6, $t7
        ctx->r16 = ADD32(ctx->r14, ctx->r15);
            goto L_80019E64;
    }
    // 0x80019D90: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x80019D94: lui         $t1, 0x8007
    ctx->r9 = S32(0X8007 << 16);
    // 0x80019D98: addiu       $t1, $t1, -0x6524
    ctx->r9 = ADD32(ctx->r9, -0X6524);
    // 0x80019D9C: addu        $s0, $t9, $t1
    ctx->r16 = ADD32(ctx->r25, ctx->r9);
    // 0x80019DA0: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80019DA4: lbu         $a3, 0x2($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X2);
    // 0x80019DA8: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    // 0x80019DAC: addiu       $a0, $a0, -0x3C
    ctx->r4 = ADD32(ctx->r4, -0X3C);
    // 0x80019DB0: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80019DB4: sll         $t4, $a3, 16
    ctx->r12 = S32(ctx->r7 << 16);
    // 0x80019DB8: sll         $t2, $a0, 16
    ctx->r10 = S32(ctx->r4 << 16);
    // 0x80019DBC: sra         $a0, $t2, 16
    ctx->r4 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80019DC0: sra         $a3, $t4, 16
    ctx->r7 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80019DC4: addiu       $a2, $zero, -0x100
    ctx->r6 = ADD32(0, -0X100);
    // 0x80019DC8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80019DCC: jal         0x8004C580
    // 0x80019DD0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_33;
    // 0x80019DD0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_33:
    // 0x80019DD4: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80019DD8: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    // 0x80019DDC: lbu         $a2, 0x3($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X3);
    // 0x80019DE0: addiu       $a0, $a0, -0xB
    ctx->r4 = ADD32(ctx->r4, -0XB);
    // 0x80019DE4: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80019DE8: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80019DEC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80019DF0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80019DF4: jal         0x800192C0
    // 0x80019DF8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_800192C0(rdram, ctx);
        goto after_34;
    // 0x80019DF8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_34:
    // 0x80019DFC: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80019E00: lbu         $a3, 0x4($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X4);
    // 0x80019E04: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    // 0x80019E08: addiu       $a0, $a0, 0x25
    ctx->r4 = ADD32(ctx->r4, 0X25);
    // 0x80019E0C: addiu       $a3, $a3, 0xE
    ctx->r7 = ADD32(ctx->r7, 0XE);
    // 0x80019E10: sll         $t1, $a3, 16
    ctx->r9 = S32(ctx->r7 << 16);
    // 0x80019E14: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x80019E18: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80019E1C: sra         $a3, $t1, 16
    ctx->r7 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80019E20: addiu       $a2, $zero, -0x100
    ctx->r6 = ADD32(0, -0X100);
    // 0x80019E24: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80019E28: jal         0x8004C580
    // 0x80019E2C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_35;
    // 0x80019E2C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_35:
    // 0x80019E30: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80019E34: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80019E38: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80019E3C: addiu       $a0, $a0, 0x49
    ctx->r4 = ADD32(ctx->r4, 0X49);
    // 0x80019E40: sll         $t3, $a0, 16
    ctx->r11 = S32(ctx->r4 << 16);
    // 0x80019E44: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80019E48: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    // 0x80019E4C: lw          $a2, 0x8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X8);
    // 0x80019E50: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x80019E54: jal         0x800192C0
    // 0x80019E58: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800192C0(rdram, ctx);
        goto after_36;
    // 0x80019E58: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_36:
    // 0x80019E5C: b           L_80019E84
    // 0x80019E60: nop

        goto L_80019E84;
    // 0x80019E60: nop

L_80019E64:
    // 0x80019E64: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80019E68: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    // 0x80019E6C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80019E70: addiu       $a0, $a0, 0x1A
    ctx->r4 = ADD32(ctx->r4, 0X1A);
    // 0x80019E74: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x80019E78: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80019E7C: jal         0x8004C580
    // 0x80019E80: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_37;
    // 0x80019E80: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_37:
L_80019E84:
    // 0x80019E84: beq         $s2, $s5, L_80019EA4
    if (ctx->r18 == ctx->r21) {
        // 0x80019E88: addiu       $a2, $zero, -0x8000
        ctx->r6 = ADD32(0, -0X8000);
            goto L_80019EA4;
    }
    // 0x80019E88: addiu       $a2, $zero, -0x8000
    ctx->r6 = ADD32(0, -0X8000);
    // 0x80019E8C: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80019E90: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    // 0x80019E94: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    // 0x80019E98: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80019E9C: jal         0x8004C580
    // 0x80019EA0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_38;
    // 0x80019EA0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_38:
L_80019EA4:
    // 0x80019EA4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80019EA8: sll         $t1, $s2, 16
    ctx->r9 = S32(ctx->r18 << 16);
    // 0x80019EAC: sra         $s2, $t1, 16
    ctx->r18 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80019EB0: slti        $at, $s2, 0x4
    ctx->r1 = SIGNED(ctx->r18) < 0X4 ? 1 : 0;
    // 0x80019EB4: bne         $at, $zero, L_80019D50
    if (ctx->r1 != 0) {
        // 0x80019EB8: nop
    
            goto L_80019D50;
    }
    // 0x80019EB8: nop

    // 0x80019EBC: lh          $t3, 0x66($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X66);
    // 0x80019EC0: bnel        $t3, $zero, L_80019FE4
    if (ctx->r11 != 0) {
        // 0x80019EC4: lh          $a2, 0x6E($sp)
        ctx->r6 = MEM_H(ctx->r29, 0X6E);
            goto L_80019FE4;
    }
    goto skip_10;
    // 0x80019EC4: lh          $a2, 0x6E($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X6E);
    skip_10:
    // 0x80019EC8: bne         $s3, $zero, L_80019F5C
    if (ctx->r19 != 0) {
        // 0x80019ECC: lh          $t4, 0x6A($sp)
        ctx->r12 = MEM_H(ctx->r29, 0X6A);
            goto L_80019F5C;
    }
    // 0x80019ECC: lh          $t4, 0x6A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X6A);
    // 0x80019ED0: bne         $t4, $zero, L_80019F5C
    if (ctx->r12 != 0) {
        // 0x80019ED4: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_80019F5C;
    }
    // 0x80019ED4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80019ED8: lhu         $v0, -0x2E5A($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2E5A);
    // 0x80019EDC: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x80019EE0: sra         $t5, $a0, 16
    ctx->r13 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80019EE4: andi        $t6, $v0, 0x400
    ctx->r14 = ctx->r2 & 0X400;
    // 0x80019EE8: bne         $t6, $zero, L_80019F04
    if (ctx->r14 != 0) {
        // 0x80019EEC: or          $a0, $t5, $zero
        ctx->r4 = ctx->r13 | 0;
            goto L_80019F04;
    }
    // 0x80019EEC: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x80019EF0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80019EF4: lh          $v1, -0x2E4C($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X2E4C);
    // 0x80019EF8: andi        $t1, $v0, 0x800
    ctx->r9 = ctx->r2 & 0X800;
    // 0x80019EFC: andi        $t7, $v1, 0x400
    ctx->r15 = ctx->r3 & 0X400;
    // 0x80019F00: beq         $t7, $zero, L_80019F20
    if (ctx->r15 == 0) {
        // 0x80019F04: slti        $at, $s5, 0x4
        ctx->r1 = SIGNED(ctx->r21) < 0X4 ? 1 : 0;
            goto L_80019F20;
    }
L_80019F04:
    // 0x80019F04: slti        $at, $s5, 0x4
    ctx->r1 = SIGNED(ctx->r21) < 0X4 ? 1 : 0;
    // 0x80019F08: beq         $at, $zero, L_80019F44
    if (ctx->r1 == 0) {
        // 0x80019F0C: nop
    
            goto L_80019F44;
    }
    // 0x80019F0C: nop

    // 0x80019F10: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80019F14: sll         $t8, $s5, 16
    ctx->r24 = S32(ctx->r21 << 16);
    // 0x80019F18: b           L_80019F44
    // 0x80019F1C: sra         $s5, $t8, 16
    ctx->r21 = S32(SIGNED(ctx->r24) >> 16);
        goto L_80019F44;
    // 0x80019F1C: sra         $s5, $t8, 16
    ctx->r21 = S32(SIGNED(ctx->r24) >> 16);
L_80019F20:
    // 0x80019F20: bne         $t1, $zero, L_80019F30
    if (ctx->r9 != 0) {
        // 0x80019F24: andi        $t2, $v1, 0x800
        ctx->r10 = ctx->r3 & 0X800;
            goto L_80019F30;
    }
    // 0x80019F24: andi        $t2, $v1, 0x800
    ctx->r10 = ctx->r3 & 0X800;
    // 0x80019F28: beq         $t2, $zero, L_80019F44
    if (ctx->r10 == 0) {
        // 0x80019F2C: nop
    
            goto L_80019F44;
    }
    // 0x80019F2C: nop

L_80019F30:
    // 0x80019F30: blez        $s5, L_80019F44
    if (SIGNED(ctx->r21) <= 0) {
        // 0x80019F34: nop
    
            goto L_80019F44;
    }
    // 0x80019F34: nop

    // 0x80019F38: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x80019F3C: sll         $t3, $s5, 16
    ctx->r11 = S32(ctx->r21 << 16);
    // 0x80019F40: sra         $s5, $t3, 16
    ctx->r21 = S32(SIGNED(ctx->r11) >> 16);
L_80019F44:
    // 0x80019F44: beql        $a0, $s5, L_80019FE4
    if (ctx->r4 == ctx->r21) {
        // 0x80019F48: lh          $a2, 0x6E($sp)
        ctx->r6 = MEM_H(ctx->r29, 0X6E);
            goto L_80019FE4;
    }
    goto skip_11;
    // 0x80019F48: lh          $a2, 0x6E($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X6E);
    skip_11:
    // 0x80019F4C: jal         0x80044480
    // 0x80019F50: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    func_80044480(rdram, ctx);
        goto after_39;
    // 0x80019F50: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_39:
    // 0x80019F54: b           L_80019FE4
    // 0x80019F58: lh          $a2, 0x6E($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X6E);
        goto L_80019FE4;
    // 0x80019F58: lh          $a2, 0x6E($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X6E);
L_80019F5C:
    // 0x80019F5C: beq         $s4, $zero, L_80019FE0
    if (ctx->r20 == 0) {
        // 0x80019F60: sll         $v0, $fp, 16
        ctx->r2 = S32(ctx->r30 << 16);
            goto L_80019FE0;
    }
    // 0x80019F60: sll         $v0, $fp, 16
    ctx->r2 = S32(ctx->r30 << 16);
    // 0x80019F64: sra         $t5, $v0, 16
    ctx->r13 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80019F68: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80019F6C: bne         $fp, $at, L_80019FA4
    if (ctx->r30 != ctx->r1) {
        // 0x80019F70: or          $v0, $t5, $zero
        ctx->r2 = ctx->r13 | 0;
            goto L_80019FA4;
    }
    // 0x80019F70: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x80019F74: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80019F78: lhu         $t6, -0x2E5A($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X2E5A);
    // 0x80019F7C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80019F80: andi        $t7, $t6, 0x100
    ctx->r15 = ctx->r14 & 0X100;
    // 0x80019F84: bne         $t7, $zero, L_80019F9C
    if (ctx->r15 != 0) {
        // 0x80019F88: nop
    
            goto L_80019F9C;
    }
    // 0x80019F88: nop

    // 0x80019F8C: lh          $t8, -0x2E4C($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X2E4C);
    // 0x80019F90: andi        $t9, $t8, 0x100
    ctx->r25 = ctx->r24 & 0X100;
    // 0x80019F94: beq         $t9, $zero, L_80019FD0
    if (ctx->r25 == 0) {
        // 0x80019F98: nop
    
            goto L_80019FD0;
    }
    // 0x80019F98: nop

L_80019F9C:
    // 0x80019F9C: b           L_80019FD0
    // 0x80019FA0: addiu       $fp, $zero, -0x1
    ctx->r30 = ADD32(0, -0X1);
        goto L_80019FD0;
    // 0x80019FA0: addiu       $fp, $zero, -0x1
    ctx->r30 = ADD32(0, -0X1);
L_80019FA4:
    // 0x80019FA4: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80019FA8: lhu         $t1, -0x2E5A($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X2E5A);
    // 0x80019FAC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80019FB0: andi        $t2, $t1, 0x200
    ctx->r10 = ctx->r9 & 0X200;
    // 0x80019FB4: bnel        $t2, $zero, L_80019FD0
    if (ctx->r10 != 0) {
        // 0x80019FB8: addiu       $fp, $zero, 0x1
        ctx->r30 = ADD32(0, 0X1);
            goto L_80019FD0;
    }
    goto skip_12;
    // 0x80019FB8: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    skip_12:
    // 0x80019FBC: lh          $t3, -0x2E4C($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X2E4C);
    // 0x80019FC0: andi        $t4, $t3, 0x200
    ctx->r12 = ctx->r11 & 0X200;
    // 0x80019FC4: beq         $t4, $zero, L_80019FD0
    if (ctx->r12 == 0) {
        // 0x80019FC8: nop
    
            goto L_80019FD0;
    }
    // 0x80019FC8: nop

    // 0x80019FCC: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
L_80019FD0:
    // 0x80019FD0: beql        $v0, $fp, L_80019FE4
    if (ctx->r2 == ctx->r30) {
        // 0x80019FD4: lh          $a2, 0x6E($sp)
        ctx->r6 = MEM_H(ctx->r29, 0X6E);
            goto L_80019FE4;
    }
    goto skip_13;
    // 0x80019FD4: lh          $a2, 0x6E($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X6E);
    skip_13:
    // 0x80019FD8: jal         0x80044480
    // 0x80019FDC: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    func_80044480(rdram, ctx);
        goto after_40;
    // 0x80019FDC: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_40:
L_80019FE0:
    // 0x80019FE0: lh          $a2, 0x6E($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X6E);
L_80019FE4:
    // 0x80019FE4: sll         $t5, $s5, 2
    ctx->r13 = S32(ctx->r21 << 2);
    // 0x80019FE8: subu        $t5, $t5, $s5
    ctx->r13 = SUB32(ctx->r13, ctx->r21);
    // 0x80019FEC: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x80019FF0: andi        $t7, $a2, 0x7F
    ctx->r15 = ctx->r6 & 0X7F;
    // 0x80019FF4: addiu       $t8, $t7, 0x80
    ctx->r24 = ADD32(ctx->r15, 0X80);
    // 0x80019FF8: addiu       $t6, $t6, -0x6524
    ctx->r14 = ADD32(ctx->r14, -0X6524);
    // 0x80019FFC: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8001A000: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x8001A004: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x8001A008: sra         $a2, $t9, 16
    ctx->r6 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8001A00C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8001A010: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x8001A014: lh          $a1, 0x2($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X2);
    // 0x8001A018: lh          $a3, 0x4($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X4);
    // 0x8001A01C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001A020: jal         0x8004C580
    // 0x8001A024: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_41;
    // 0x8001A024: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_41:
    // 0x8001A028: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8001A02C: bne         $s5, $at, L_8001A060
    if (ctx->r21 != ctx->r1) {
        // 0x8001A030: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_8001A060;
    }
    // 0x8001A030: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8001A034: lh          $t2, 0x6A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X6A);
    // 0x8001A038: lh          $t3, 0x8A($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X8A);
    // 0x8001A03C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001A040: bnel        $t2, $zero, L_8001A064
    if (ctx->r10 != 0) {
        // 0x8001A044: lh          $t6, 0x88($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X88);
            goto L_8001A064;
    }
    goto skip_14;
    // 0x8001A044: lh          $t6, 0x88($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X88);
    skip_14:
    // 0x8001A048: bne         $t3, $at, L_8001A05C
    if (ctx->r11 != ctx->r1) {
        // 0x8001A04C: addiu       $t5, $zero, 0x8
        ctx->r13 = ADD32(0, 0X8);
            goto L_8001A05C;
    }
    // 0x8001A04C: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x8001A050: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x8001A054: b           L_8001A060
    // 0x8001A058: sh          $t4, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r12;
        goto L_8001A060;
    // 0x8001A058: sh          $t4, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r12;
L_8001A05C:
    // 0x8001A05C: sh          $t5, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r13;
L_8001A060:
    // 0x8001A060: lh          $t6, 0x88($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X88);
L_8001A064:
    // 0x8001A064: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x8001A068: addiu       $a2, $zero, -0x100
    ctx->r6 = ADD32(0, -0X100);
    // 0x8001A06C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8001A070: addiu       $a3, $t6, 0x14
    ctx->r7 = ADD32(ctx->r14, 0X14);
    // 0x8001A074: sll         $t8, $a3, 16
    ctx->r24 = S32(ctx->r7 << 16);
    // 0x8001A078: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x8001A07C: lh          $a1, -0x6504($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X6504);
    // 0x8001A080: sra         $a3, $t8, 16
    ctx->r7 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8001A084: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001A088: jal         0x8004C580
    // 0x8001A08C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_42;
    // 0x8001A08C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_42:
    // 0x8001A090: beq         $s4, $zero, L_8001A13C
    if (ctx->r20 == 0) {
        // 0x8001A094: lh          $t1, 0x88($sp)
        ctx->r9 = MEM_H(ctx->r29, 0X88);
            goto L_8001A13C;
    }
    // 0x8001A094: lh          $t1, 0x88($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X88);
    // 0x8001A098: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001A09C: bne         $t1, $at, L_8001A0AC
    if (ctx->r9 != ctx->r1) {
        // 0x8001A0A0: lui         $t3, 0x8007
        ctx->r11 = S32(0X8007 << 16);
            goto L_8001A0AC;
    }
    // 0x8001A0A0: lui         $t3, 0x8007
    ctx->r11 = S32(0X8007 << 16);
    // 0x8001A0A4: b           L_8001A0B0
    // 0x8001A0A8: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_8001A0B0;
    // 0x8001A0A8: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8001A0AC:
    // 0x8001A0AC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8001A0B0:
    // 0x8001A0B0: sll         $t2, $s1, 3
    ctx->r10 = S32(ctx->r17 << 3);
    // 0x8001A0B4: addiu       $t3, $t3, -0x64E8
    ctx->r11 = ADD32(ctx->r11, -0X64E8);
    // 0x8001A0B8: addu        $s0, $t2, $t3
    ctx->r16 = ADD32(ctx->r10, ctx->r11);
    // 0x8001A0BC: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8001A0C0: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    // 0x8001A0C4: addiu       $a2, $zero, -0x100
    ctx->r6 = ADD32(0, -0X100);
    // 0x8001A0C8: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    // 0x8001A0CC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001A0D0: jal         0x8004C580
    // 0x8001A0D4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_43;
    // 0x8001A0D4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_43:
    // 0x8001A0D8: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    // 0x8001A0DC: lh          $a1, 0x6($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X6);
    // 0x8001A0E0: addiu       $a2, $zero, -0x100
    ctx->r6 = ADD32(0, -0X100);
    // 0x8001A0E4: addiu       $a3, $zero, 0x1F
    ctx->r7 = ADD32(0, 0X1F);
    // 0x8001A0E8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001A0EC: jal         0x8004C580
    // 0x8001A0F0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_44;
    // 0x8001A0F0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_44:
    // 0x8001A0F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001A0F8: bne         $fp, $at, L_8001A108
    if (ctx->r30 != ctx->r1) {
        // 0x8001A0FC: sll         $t4, $s1, 3
        ctx->r12 = S32(ctx->r17 << 3);
            goto L_8001A108;
    }
    // 0x8001A0FC: sll         $t4, $s1, 3
    ctx->r12 = S32(ctx->r17 << 3);
    // 0x8001A100: b           L_8001A10C
    // 0x8001A104: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
        goto L_8001A10C;
    // 0x8001A104: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8001A108:
    // 0x8001A108: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
L_8001A10C:
    // 0x8001A10C: sll         $t5, $s2, 1
    ctx->r13 = S32(ctx->r18 << 1);
    // 0x8001A110: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x8001A114: addiu       $t6, $t6, -0x64E8
    ctx->r14 = ADD32(ctx->r14, -0X64E8);
    // 0x8001A118: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x8001A11C: addu        $v0, $t7, $t6
    ctx->r2 = ADD32(ctx->r15, ctx->r14);
    // 0x8001A120: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x8001A124: lh          $a1, 0x2($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X2);
    // 0x8001A128: lh          $a2, 0x52($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X52);
    // 0x8001A12C: addiu       $a3, $zero, 0x13
    ctx->r7 = ADD32(0, 0X13);
    // 0x8001A130: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001A134: jal         0x8004C580
    // 0x8001A138: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_45;
    // 0x8001A138: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_45:
L_8001A13C:
    // 0x8001A13C: lh          $t8, 0x6E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X6E);
    // 0x8001A140: addiu       $t9, $t8, 0x6
    ctx->r25 = ADD32(ctx->r24, 0X6);
    // 0x8001A144: jal         0x8000798C
    // 0x8001A148: sh          $t9, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r25;
    func_8000798C(rdram, ctx);
        goto after_46;
    // 0x8001A148: sh          $t9, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r25;
    after_46:
    // 0x8001A14C: b           L_80019744
    // 0x8001A150: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80019744;
    // 0x8001A150: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001A154: nop

    // 0x8001A158: nop

    // 0x8001A15C: nop

    // 0x8001A160: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8001A164: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8001A168: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8001A16C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8001A170: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8001A174: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8001A178: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8001A17C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8001A180: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8001A184: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8001A188: jr          $ra
    // 0x8001A18C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    TRACE_RETURN()
    return;
    // 0x8001A18C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_8001A190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8001A190: addiu       $sp, $sp, -0x230
    ctx->r29 = ADD32(ctx->r29, -0X230);
    // 0x8001A194: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8001A198: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001A19C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001A1A0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001A1A4: addiu       $s1, $sp, 0x30
    ctx->r17 = ADD32(ctx->r29, 0X30);
    // 0x8001A1A8: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
L_8001A1AC:
    // 0x8001A1AC: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001A1B0: sll         $t7, $s0, 3
    ctx->r15 = S32(ctx->r16 << 3);
    // 0x8001A1B4: addu        $a1, $s1, $t7
    ctx->r5 = ADD32(ctx->r17, ctx->r15);
    // 0x8001A1B8: jal         0x8000A3E8
    // 0x8001A1BC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_8000A3E8(rdram, ctx);
        goto after_0;
    // 0x8001A1BC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x8001A1C0: jal         0x8000A414
    // 0x8001A1C4: nop

    func_8000A414(rdram, ctx);
        goto after_1;
    // 0x8001A1C4: nop

    after_1:
    // 0x8001A1C8: beql        $v0, $zero, L_8001A1E4
    if (ctx->r2 == 0) {
        // 0x8001A1CC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8001A1E4;
    }
    goto skip_0;
    // 0x8001A1CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_8001A1D0:
    // 0x8001A1D0: jal         0x8000A414
    // 0x8001A1D4: nop

    func_8000A414(rdram, ctx);
        goto after_2;
    // 0x8001A1D4: nop

    after_2:
    // 0x8001A1D8: bne         $v0, $zero, L_8001A1D0
    if (ctx->r2 != 0) {
        // 0x8001A1DC: nop
    
            goto L_8001A1D0;
    }
    // 0x8001A1DC: nop

    // 0x8001A1E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001A1E4:
    // 0x8001A1E4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8001A1E8:
    // 0x8001A1E8: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x8001A1EC: sra         $v0, $t8, 16
    ctx->r2 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8001A1F0: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8001A1F4: bnel        $at, $zero, L_8001A1E8
    if (ctx->r1 != 0) {
        // 0x8001A1F8: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8001A1E8;
    }
    goto skip_1;
    // 0x8001A1F8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_1:
    // 0x8001A1FC: sll         $t0, $s0, 3
    ctx->r8 = S32(ctx->r16 << 3);
    // 0x8001A200: addu        $a0, $s1, $t0
    ctx->r4 = ADD32(ctx->r17, ctx->r8);
    // 0x8001A204: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001A208:
    // 0x8001A208: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001A20C: sll         $t2, $v0, 16
    ctx->r10 = S32(ctx->r2 << 16);
    // 0x8001A210: sra         $v0, $t2, 16
    ctx->r2 = S32(SIGNED(ctx->r10) >> 16);
    // 0x8001A214: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8001A218: bne         $at, $zero, L_8001A208
    if (ctx->r1 != 0) {
        // 0x8001A21C: nop
    
            goto L_8001A208;
    }
    // 0x8001A21C: nop

    // 0x8001A220: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001A224: sll         $t4, $s0, 16
    ctx->r12 = S32(ctx->r16 << 16);
    // 0x8001A228: sra         $s0, $t4, 16
    ctx->r16 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8001A22C: slti        $at, $s0, 0x40
    ctx->r1 = SIGNED(ctx->r16) < 0X40 ? 1 : 0;
    // 0x8001A230: bnel        $at, $zero, L_8001A1AC
    if (ctx->r1 != 0) {
        // 0x8001A234: sll         $a0, $s0, 16
        ctx->r4 = S32(ctx->r16 << 16);
            goto L_8001A1AC;
    }
    goto skip_2;
    // 0x8001A234: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    skip_2:
    // 0x8001A238: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001A23C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001A240: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8001A244: jr          $ra
    // 0x8001A248: addiu       $sp, $sp, 0x230
    ctx->r29 = ADD32(ctx->r29, 0X230);
    TRACE_RETURN()
    return;
    // 0x8001A248: addiu       $sp, $sp, 0x230
    ctx->r29 = ADD32(ctx->r29, 0X230);
;}
RECOMP_FUNC void func_8001A24C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8001A24C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001A250: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001A254: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8001A258:
    // 0x8001A258: addu        $t6, $a0, $a1
    ctx->r14 = ADD32(ctx->r4, ctx->r5);
    // 0x8001A25C: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8001A260: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001A264: sll         $t0, $a1, 16
    ctx->r8 = S32(ctx->r5 << 16);
    // 0x8001A268: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8001A26C: sra         $a1, $t0, 16
    ctx->r5 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8001A270: addiu       $v0, $t8, 0x6
    ctx->r2 = ADD32(ctx->r24, 0X6);
    // 0x8001A274: slti        $at, $a1, 0x7
    ctx->r1 = SIGNED(ctx->r5) < 0X7 ? 1 : 0;
    // 0x8001A278: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x8001A27C: bne         $at, $zero, L_8001A258
    if (ctx->r1 != 0) {
        // 0x8001A280: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_8001A258;
    }
    // 0x8001A280: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8001A284: lbu         $t2, 0x7($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X7);
    // 0x8001A288: bne         $t9, $t2, L_8001A294
    if (ctx->r25 != ctx->r10) {
        // 0x8001A28C: nop
    
            goto L_8001A294;
    }
    // 0x8001A28C: nop

    // 0x8001A290: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8001A294:
    // 0x8001A294: jr          $ra
    // 0x8001A298: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    TRACE_RETURN()
    return;
    // 0x8001A298: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8001A29C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8001A29C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8001A2A0: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x8001A2A4: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8001A2A8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001A2AC: blez        $a1, L_8001A2E0
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8001A2B0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8001A2E0;
    }
    // 0x8001A2B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001A2B4:
    // 0x8001A2B4: addu        $t8, $a0, $v0
    ctx->r24 = ADD32(ctx->r4, ctx->r2);
    // 0x8001A2B8: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8001A2BC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001A2C0: sll         $t2, $v0, 16
    ctx->r10 = S32(ctx->r2 << 16);
    // 0x8001A2C4: addu        $t0, $v1, $t9
    ctx->r8 = ADD32(ctx->r3, ctx->r25);
    // 0x8001A2C8: sra         $v0, $t2, 16
    ctx->r2 = S32(SIGNED(ctx->r10) >> 16);
    // 0x8001A2CC: addiu       $v1, $t0, 0x6
    ctx->r3 = ADD32(ctx->r8, 0X6);
    // 0x8001A2D0: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8001A2D4: andi        $t1, $v1, 0xFF
    ctx->r9 = ctx->r3 & 0XFF;
    // 0x8001A2D8: bne         $at, $zero, L_8001A2B4
    if (ctx->r1 != 0) {
        // 0x8001A2DC: or          $v1, $t1, $zero
        ctx->r3 = ctx->r9 | 0;
            goto L_8001A2B4;
    }
    // 0x8001A2DC: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
L_8001A2E0:
    // 0x8001A2E0: jr          $ra
    // 0x8001A2E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    TRACE_RETURN()
    return;
    // 0x8001A2E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8001A2E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8001A2E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001A2EC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8001A2F0:
    // 0x8001A2F0: addu        $t6, $a0, $v1
    ctx->r14 = ADD32(ctx->r4, ctx->r3);
    // 0x8001A2F4: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8001A2F8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001A2FC: sll         $t0, $v1, 16
    ctx->r8 = S32(ctx->r3 << 16);
    // 0x8001A300: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8001A304: sra         $v1, $t0, 16
    ctx->r3 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8001A308: addiu       $v0, $t8, 0x6
    ctx->r2 = ADD32(ctx->r24, 0X6);
    // 0x8001A30C: slti        $at, $v1, 0x7
    ctx->r1 = SIGNED(ctx->r3) < 0X7 ? 1 : 0;
    // 0x8001A310: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x8001A314: bne         $at, $zero, L_8001A2F0
    if (ctx->r1 != 0) {
        // 0x8001A318: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_8001A2F0;
    }
    // 0x8001A318: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8001A31C: jr          $ra
    // 0x8001A320: sb          $t9, 0x7($a0)
    MEM_B(0X7, ctx->r4) = ctx->r25;
    TRACE_RETURN()
    return;
    // 0x8001A320: sb          $t9, 0x7($a0)
    MEM_B(0X7, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void func_8001A324(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8001A324: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001A328: sh          $zero, -0x6B92($at)
    MEM_H(-0X6B92, ctx->r1) = 0;
    // 0x8001A32C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001A330: sh          $zero, -0x6B90($at)
    MEM_H(-0X6B90, ctx->r1) = 0;
    // 0x8001A334: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001A338: sh          $zero, -0x6B8E($at)
    MEM_H(-0X6B8E, ctx->r1) = 0;
    // 0x8001A33C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001A340: sh          $zero, -0x6B8A($at)
    MEM_H(-0X6B8A, ctx->r1) = 0;
    // 0x8001A344: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001A348: sh          $zero, -0x6B88($at)
    MEM_H(-0X6B88, ctx->r1) = 0;
    // 0x8001A34C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001A350: sh          $zero, -0x6B86($at)
    MEM_H(-0X6B86, ctx->r1) = 0;
    // 0x8001A354: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001A358: sh          $zero, -0x6B84($at)
    MEM_H(-0X6B84, ctx->r1) = 0;
    // 0x8001A35C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001A360: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001A364: sh          $v0, 0x6ACC($at)
    MEM_H(0X6ACC, ctx->r1) = ctx->r2;
    // 0x8001A368: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001A36C: sh          $v0, 0x6ACE($at)
    MEM_H(0X6ACE, ctx->r1) = ctx->r2;
    // 0x8001A370: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001A374: jr          $ra
    // 0x8001A378: sh          $v0, 0x6AD0($at)
    MEM_H(0X6AD0, ctx->r1) = ctx->r2;
    TRACE_RETURN()
    return;
    // 0x8001A378: sh          $v0, 0x6AD0($at)
    MEM_H(0X6AD0, ctx->r1) = ctx->r2;
;}
RECOMP_FUNC void func_8001A37C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8001A37C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8001A380: lw          $t9, -0x2E40($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2E40);
    // 0x8001A384: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8001A388: sll         $a3, $a1, 16
    ctx->r7 = S32(ctx->r5 << 16);
    // 0x8001A38C: sra         $t8, $a3, 16
    ctx->r24 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8001A390: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8001A394: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8001A398: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x8001A39C: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8001A3A0: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x8001A3A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001A3A8: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8001A3AC: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x8001A3B0: bne         $t0, $zero, L_8001A3C8
    if (ctx->r8 != 0) {
        // 0x8001A3B4: sw          $zero, 0x34($sp)
        MEM_W(0X34, ctx->r29) = 0;
            goto L_8001A3C8;
    }
    // 0x8001A3B4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8001A3B8: jal         0x8001A324
    // 0x8001A3BC: nop

    func_8001A324(rdram, ctx);
        goto after_0;
    // 0x8001A3BC: nop

    after_0:
    // 0x8001A3C0: b           L_8001AA80
    // 0x8001A3C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001AA80;
    // 0x8001A3C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001A3C8:
    // 0x8001A3C8: addiu       $t1, $a0, -0x1
    ctx->r9 = ADD32(ctx->r4, -0X1);
    // 0x8001A3CC: sltiu       $at, $t1, 0xA
    ctx->r1 = ctx->r9 < 0XA ? 1 : 0;
    // 0x8001A3D0: beq         $at, $zero, L_8001AA80
    if (ctx->r1 == 0) {
        // 0x8001A3D4: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_8001AA80;
    }
    // 0x8001A3D4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8001A3D8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001A3DC: addu        $at, $at, $t1
    gpr jr_addend_8001A3E4 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8001A3E0: lw          $t1, 0x647C($at)
    ctx->r9 = ADD32(ctx->r1, 0X647C);
    // 0x8001A3E4: jr          $t1
    // 0x8001A3E8: nop

    switch (jr_addend_8001A3E4 >> 2) {
        case 0: goto L_8001A3EC; break;
        case 1: goto L_8001A514; break;
        case 2: goto L_8001A62C; break;
        case 3: goto L_8001A874; break;
        case 4: goto L_8001AA80; break;
        case 5: goto L_8001AA80; break;
        case 6: goto L_8001AA80; break;
        case 7: goto L_8001AA80; break;
        case 8: goto L_8001AA5C; break;
        case 9: goto L_8001AA78; break;
        default: switch_error(__func__, 0x8001A3E4, 0x8007647C);
    }
    // 0x8001A3E8: nop

L_8001A3EC:
    // 0x8001A3EC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8001A3F0: jal         0x8000A3E8
    // 0x8001A3F4: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    func_8000A3E8(rdram, ctx);
        goto after_1;
    // 0x8001A3F4: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_1:
    // 0x8001A3F8: jal         0x8000A414
    // 0x8001A3FC: nop

    func_8000A414(rdram, ctx);
        goto after_2;
    // 0x8001A3FC: nop

    after_2:
    // 0x8001A400: beq         $v0, $zero, L_8001A418
    if (ctx->r2 == 0) {
        // 0x8001A404: nop
    
            goto L_8001A418;
    }
    // 0x8001A404: nop

L_8001A408:
    // 0x8001A408: jal         0x8000A414
    // 0x8001A40C: nop

    func_8000A414(rdram, ctx);
        goto after_3;
    // 0x8001A40C: nop

    after_3:
    // 0x8001A410: bne         $v0, $zero, L_8001A408
    if (ctx->r2 != 0) {
        // 0x8001A414: nop
    
            goto L_8001A408;
    }
    // 0x8001A414: nop

L_8001A418:
    // 0x8001A418: jal         0x8001A24C
    // 0x8001A41C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    func_8001A24C(rdram, ctx);
        goto after_4;
    // 0x8001A41C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_4:
    // 0x8001A420: beq         $v0, $zero, L_8001A4F8
    if (ctx->r2 == 0) {
        // 0x8001A424: addiu       $t1, $zero, -0x1
        ctx->r9 = ADD32(0, -0X1);
            goto L_8001A4F8;
    }
    // 0x8001A424: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8001A428: lhu         $t2, 0x50($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X50);
    // 0x8001A42C: addiu       $at, $zero, 0x5743
    ctx->r1 = ADD32(0, 0X5743);
    // 0x8001A430: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8001A434: bne         $t2, $at, L_8001A4F0
    if (ctx->r10 != ctx->r1) {
        // 0x8001A438: nop
    
            goto L_8001A4F0;
    }
    // 0x8001A438: nop

    // 0x8001A43C: lbu         $v0, 0x52($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X52);
    // 0x8001A440: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001A444: lbu         $v1, 0x53($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X53);
    // 0x8001A448: andi        $t3, $v0, 0x3
    ctx->r11 = ctx->r2 & 0X3;
    // 0x8001A44C: sh          $t3, -0x6B92($at)
    MEM_H(-0X6B92, ctx->r1) = ctx->r11;
    // 0x8001A450: sra         $t4, $v0, 2
    ctx->r12 = S32(SIGNED(ctx->r2) >> 2);
    // 0x8001A454: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x8001A458: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001A45C: sh          $t5, -0x6B90($at)
    MEM_H(-0X6B90, ctx->r1) = ctx->r13;
    // 0x8001A460: sra         $t6, $v0, 3
    ctx->r14 = S32(SIGNED(ctx->r2) >> 3);
    // 0x8001A464: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8001A468: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001A46C: sh          $t7, -0x6B8E($at)
    MEM_H(-0X6B8E, ctx->r1) = ctx->r15;
    // 0x8001A470: sra         $t8, $v0, 4
    ctx->r24 = S32(SIGNED(ctx->r2) >> 4);
    // 0x8001A474: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8001A478: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001A47C: sh          $t9, -0x6B8A($at)
    MEM_H(-0X6B8A, ctx->r1) = ctx->r25;
    // 0x8001A480: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001A484: sh          $zero, -0x6B88($at)
    MEM_H(-0X6B88, ctx->r1) = 0;
    // 0x8001A488: sra         $t0, $v0, 6
    ctx->r8 = S32(SIGNED(ctx->r2) >> 6);
    // 0x8001A48C: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x8001A490: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001A494: sh          $t1, -0x6B86($at)
    MEM_H(-0X6B86, ctx->r1) = ctx->r9;
    // 0x8001A498: sra         $t2, $v0, 7
    ctx->r10 = S32(SIGNED(ctx->r2) >> 7);
    // 0x8001A49C: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8001A4A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001A4A4: sh          $t3, 0x6ACC($at)
    MEM_H(0X6ACC, ctx->r1) = ctx->r11;
    // 0x8001A4A8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001A4AC: andi        $t4, $v1, 0xF
    ctx->r12 = ctx->r3 & 0XF;
    // 0x8001A4B0: sh          $t4, -0x6B84($at)
    MEM_H(-0X6B84, ctx->r1) = ctx->r12;
    // 0x8001A4B4: sra         $t5, $v1, 4
    ctx->r13 = S32(SIGNED(ctx->r3) >> 4);
    // 0x8001A4B8: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x8001A4BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001A4C0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8001A4C4: lh          $t9, -0x6B84($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X6B84);
    // 0x8001A4C8: sh          $t6, 0x6ACE($at)
    MEM_H(0X6ACE, ctx->r1) = ctx->r14;
    // 0x8001A4CC: sra         $t7, $v1, 5
    ctx->r15 = S32(SIGNED(ctx->r3) >> 5);
    // 0x8001A4D0: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8001A4D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001A4D8: sh          $t8, 0x6AD0($at)
    MEM_H(0X6AD0, ctx->r1) = ctx->r24;
    // 0x8001A4DC: slti        $at, $t9, 0x9
    ctx->r1 = SIGNED(ctx->r25) < 0X9 ? 1 : 0;
    // 0x8001A4E0: bne         $at, $zero, L_8001A4FC
    if (ctx->r1 != 0) {
        // 0x8001A4E4: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_8001A4FC;
    }
    // 0x8001A4E4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001A4E8: b           L_8001A514
    // 0x8001A4EC: sh          $zero, -0x6B84($at)
    MEM_H(-0X6B84, ctx->r1) = 0;
        goto L_8001A514;
    // 0x8001A4EC: sh          $zero, -0x6B84($at)
    MEM_H(-0X6B84, ctx->r1) = 0;
L_8001A4F0:
    // 0x8001A4F0: b           L_8001A4FC
    // 0x8001A4F4: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
        goto L_8001A4FC;
    // 0x8001A4F4: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
L_8001A4F8:
    // 0x8001A4F8: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
L_8001A4FC:
    // 0x8001A4FC: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8001A500: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001A504: bnel        $t2, $at, L_8001AA84
    if (ctx->r10 != ctx->r1) {
        // 0x8001A508: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8001AA84;
    }
    goto skip_0;
    // 0x8001A508: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8001A50C: jal         0x8001A324
    // 0x8001A510: nop

    func_8001A324(rdram, ctx);
        goto after_5;
    // 0x8001A510: nop

    after_5:
L_8001A514:
    // 0x8001A514: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001A518: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x8001A51C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_8001A520:
    // 0x8001A520: addu        $t3, $a0, $v0
    ctx->r11 = ADD32(ctx->r4, ctx->r2);
    // 0x8001A524: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001A528: sll         $t4, $v0, 16
    ctx->r12 = S32(ctx->r2 << 16);
    // 0x8001A52C: sra         $v0, $t4, 16
    ctx->r2 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8001A530: slti        $at, $v0, 0x7
    ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x8001A534: bne         $at, $zero, L_8001A520
    if (ctx->r1 != 0) {
        // 0x8001A538: sb          $v1, 0x0($t3)
        MEM_B(0X0, ctx->r11) = ctx->r3;
            goto L_8001A520;
    }
    // 0x8001A538: sb          $v1, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r3;
    // 0x8001A53C: addiu       $t6, $zero, 0x57
    ctx->r14 = ADD32(0, 0X57);
    // 0x8001A540: addiu       $t7, $zero, 0x43
    ctx->r15 = ADD32(0, 0X43);
    // 0x8001A544: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x8001A548: sb          $t7, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r15;
    // 0x8001A54C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8001A550: lh          $t0, -0x6B90($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X6B90);
    // 0x8001A554: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001A558: lh          $v0, -0x6B92($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X6B92);
    // 0x8001A55C: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x8001A560: lh          $t4, -0x6B8E($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X6B8E);
    // 0x8001A564: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x8001A568: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8001A56C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8001A570: andi        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 & 0X3;
    // 0x8001A574: lh          $t8, -0x6B8A($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X6B8A);
    // 0x8001A578: or          $t3, $t9, $t2
    ctx->r11 = ctx->r25 | ctx->r10;
    // 0x8001A57C: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x8001A580: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x8001A584: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x8001A588: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x8001A58C: lh          $t2, -0x6B86($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X6B86);
    // 0x8001A590: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8001A594: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x8001A598: or          $t1, $t7, $t0
    ctx->r9 = ctx->r15 | ctx->r8;
    // 0x8001A59C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8001A5A0: lh          $t7, 0x6ACC($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X6ACC);
    // 0x8001A5A4: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8001A5A8: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8001A5AC: lh          $t2, 0x6ACE($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X6ACE);
    // 0x8001A5B0: sll         $t4, $t3, 6
    ctx->r12 = S32(ctx->r11 << 6);
    // 0x8001A5B4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001A5B8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8001A5BC: lh          $v0, -0x6B84($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X6B84);
    // 0x8001A5C0: lh          $t6, 0x6AD0($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X6AD0);
    // 0x8001A5C4: or          $t5, $t1, $t4
    ctx->r13 = ctx->r9 | ctx->r12;
    // 0x8001A5C8: sll         $t8, $t7, 7
    ctx->r24 = S32(ctx->r15 << 7);
    // 0x8001A5CC: or          $t9, $t5, $t8
    ctx->r25 = ctx->r13 | ctx->r24;
    // 0x8001A5D0: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8001A5D4: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x8001A5D8: andi        $t1, $v0, 0xF
    ctx->r9 = ctx->r2 & 0XF;
    // 0x8001A5DC: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8001A5E0: sb          $t9, 0x52($sp)
    MEM_B(0X52, ctx->r29) = ctx->r25;
    // 0x8001A5E4: or          $t5, $t1, $t4
    ctx->r13 = ctx->r9 | ctx->r12;
    // 0x8001A5E8: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x8001A5EC: or          $t9, $t5, $t8
    ctx->r25 = ctx->r13 | ctx->r24;
    // 0x8001A5F0: jal         0x8001A2E8
    // 0x8001A5F4: sb          $t9, 0x53($sp)
    MEM_B(0X53, ctx->r29) = ctx->r25;
    func_8001A2E8(rdram, ctx);
        goto after_6;
    // 0x8001A5F4: sb          $t9, 0x53($sp)
    MEM_B(0X53, ctx->r29) = ctx->r25;
    after_6:
    // 0x8001A5F8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8001A5FC: jal         0x8000A3B8
    // 0x8001A600: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    func_8000A3B8(rdram, ctx);
        goto after_7;
    // 0x8001A600: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_7:
    // 0x8001A604: jal         0x8000A414
    // 0x8001A608: nop

    func_8000A414(rdram, ctx);
        goto after_8;
    // 0x8001A608: nop

    after_8:
    // 0x8001A60C: beql        $v0, $zero, L_8001AA84
    if (ctx->r2 == 0) {
        // 0x8001A610: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8001AA84;
    }
    goto skip_1;
    // 0x8001A610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
L_8001A614:
    // 0x8001A614: jal         0x8000A414
    // 0x8001A618: nop

    func_8000A414(rdram, ctx);
        goto after_9;
    // 0x8001A618: nop

    after_9:
    // 0x8001A61C: bne         $v0, $zero, L_8001A614
    if (ctx->r2 != 0) {
        // 0x8001A620: nop
    
            goto L_8001A614;
    }
    // 0x8001A620: nop

    // 0x8001A624: b           L_8001AA84
    // 0x8001A628: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8001AA84;
    // 0x8001A628: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001A62C:
    // 0x8001A62C: sll         $v0, $a3, 3
    ctx->r2 = S32(ctx->r7 << 3);
    // 0x8001A630: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x8001A634: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x8001A638: sra         $t1, $a0, 16
    ctx->r9 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001A63C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x8001A640: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8001A644: jal         0x8000A3E8
    // 0x8001A648: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    func_8000A3E8(rdram, ctx);
        goto after_10;
    // 0x8001A648: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_10:
    // 0x8001A64C: jal         0x8000A414
    // 0x8001A650: nop

    func_8000A414(rdram, ctx);
        goto after_11;
    // 0x8001A650: nop

    after_11:
    // 0x8001A654: beql        $v0, $zero, L_8001A670
    if (ctx->r2 == 0) {
        // 0x8001A658: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8001A670;
    }
    goto skip_2;
    // 0x8001A658: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_2:
L_8001A65C:
    // 0x8001A65C: jal         0x8000A414
    // 0x8001A660: nop

    func_8000A414(rdram, ctx);
        goto after_12;
    // 0x8001A660: nop

    after_12:
    // 0x8001A664: bne         $v0, $zero, L_8001A65C
    if (ctx->r2 != 0) {
        // 0x8001A668: nop
    
            goto L_8001A65C;
    }
    // 0x8001A668: nop

    // 0x8001A66C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_8001A670:
    // 0x8001A670: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x8001A674: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001A678: sll         $t2, $a0, 16
    ctx->r10 = S32(ctx->r4 << 16);
    // 0x8001A67C: sra         $a0, $t2, 16
    ctx->r4 = S32(SIGNED(ctx->r10) >> 16);
    // 0x8001A680: jal         0x8000A3E8
    // 0x8001A684: sh          $a0, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r4;
    func_8000A3E8(rdram, ctx);
        goto after_13;
    // 0x8001A684: sh          $a0, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r4;
    after_13:
    // 0x8001A688: jal         0x8000A414
    // 0x8001A68C: nop

    func_8000A414(rdram, ctx);
        goto after_14;
    // 0x8001A68C: nop

    after_14:
    // 0x8001A690: beql        $v0, $zero, L_8001A6AC
    if (ctx->r2 == 0) {
        // 0x8001A694: lh          $t4, 0x30($sp)
        ctx->r12 = MEM_H(ctx->r29, 0X30);
            goto L_8001A6AC;
    }
    goto skip_3;
    // 0x8001A694: lh          $t4, 0x30($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X30);
    skip_3:
L_8001A698:
    // 0x8001A698: jal         0x8000A414
    // 0x8001A69C: nop

    func_8000A414(rdram, ctx);
        goto after_15;
    // 0x8001A69C: nop

    after_15:
    // 0x8001A6A0: bne         $v0, $zero, L_8001A698
    if (ctx->r2 != 0) {
        // 0x8001A6A4: nop
    
            goto L_8001A698;
    }
    // 0x8001A6A4: nop

    // 0x8001A6A8: lh          $t4, 0x30($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X30);
L_8001A6AC:
    // 0x8001A6AC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8001A6B0: addiu       $a1, $a1, -0x6B68
    ctx->r5 = ADD32(ctx->r5, -0X6B68);
    // 0x8001A6B4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8001A6B8: sll         $a0, $t5, 16
    ctx->r4 = S32(ctx->r13 << 16);
    // 0x8001A6BC: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001A6C0: sh          $t5, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r13;
    // 0x8001A6C4: jal         0x8000A3E8
    // 0x8001A6C8: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_8000A3E8(rdram, ctx);
        goto after_16;
    // 0x8001A6C8: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_16:
    // 0x8001A6CC: jal         0x8000A414
    // 0x8001A6D0: nop

    func_8000A414(rdram, ctx);
        goto after_17;
    // 0x8001A6D0: nop

    after_17:
    // 0x8001A6D4: beql        $v0, $zero, L_8001A6F0
    if (ctx->r2 == 0) {
        // 0x8001A6D8: lh          $t7, 0x30($sp)
        ctx->r15 = MEM_H(ctx->r29, 0X30);
            goto L_8001A6F0;
    }
    goto skip_4;
    // 0x8001A6D8: lh          $t7, 0x30($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X30);
    skip_4:
L_8001A6DC:
    // 0x8001A6DC: jal         0x8000A414
    // 0x8001A6E0: nop

    func_8000A414(rdram, ctx);
        goto after_18;
    // 0x8001A6E0: nop

    after_18:
    // 0x8001A6E4: bne         $v0, $zero, L_8001A6DC
    if (ctx->r2 != 0) {
        // 0x8001A6E8: nop
    
            goto L_8001A6DC;
    }
    // 0x8001A6E8: nop

    // 0x8001A6EC: lh          $t7, 0x30($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X30);
L_8001A6F0:
    // 0x8001A6F0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8001A6F4: addiu       $a1, $a1, -0x6B60
    ctx->r5 = ADD32(ctx->r5, -0X6B60);
    // 0x8001A6F8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8001A6FC: sll         $a0, $t8, 16
    ctx->r4 = S32(ctx->r24 << 16);
    // 0x8001A700: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001A704: sh          $t8, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r24;
    // 0x8001A708: jal         0x8000A3E8
    // 0x8001A70C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_8000A3E8(rdram, ctx);
        goto after_19;
    // 0x8001A70C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_19:
    // 0x8001A710: jal         0x8000A414
    // 0x8001A714: nop

    func_8000A414(rdram, ctx);
        goto after_20;
    // 0x8001A714: nop

    after_20:
    // 0x8001A718: beql        $v0, $zero, L_8001A734
    if (ctx->r2 == 0) {
        // 0x8001A71C: lh          $t0, 0x30($sp)
        ctx->r8 = MEM_H(ctx->r29, 0X30);
            goto L_8001A734;
    }
    goto skip_5;
    // 0x8001A71C: lh          $t0, 0x30($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X30);
    skip_5:
L_8001A720:
    // 0x8001A720: jal         0x8000A414
    // 0x8001A724: nop

    func_8000A414(rdram, ctx);
        goto after_21;
    // 0x8001A724: nop

    after_21:
    // 0x8001A728: bne         $v0, $zero, L_8001A720
    if (ctx->r2 != 0) {
        // 0x8001A72C: nop
    
            goto L_8001A720;
    }
    // 0x8001A72C: nop

    // 0x8001A730: lh          $t0, 0x30($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X30);
L_8001A734:
    // 0x8001A734: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x8001A738: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8001A73C: sll         $a0, $t1, 16
    ctx->r4 = S32(ctx->r9 << 16);
    // 0x8001A740: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001A744: sh          $t1, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r9;
    // 0x8001A748: jal         0x8000A3E8
    // 0x8001A74C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    func_8000A3E8(rdram, ctx);
        goto after_22;
    // 0x8001A74C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_22:
    // 0x8001A750: jal         0x8000A414
    // 0x8001A754: nop

    func_8000A414(rdram, ctx);
        goto after_23;
    // 0x8001A754: nop

    after_23:
    // 0x8001A758: beq         $v0, $zero, L_8001A770
    if (ctx->r2 == 0) {
        // 0x8001A75C: nop
    
            goto L_8001A770;
    }
    // 0x8001A75C: nop

L_8001A760:
    // 0x8001A760: jal         0x8000A414
    // 0x8001A764: nop

    func_8000A414(rdram, ctx);
        goto after_24;
    // 0x8001A764: nop

    after_24:
    // 0x8001A768: bne         $v0, $zero, L_8001A760
    if (ctx->r2 != 0) {
        // 0x8001A76C: nop
    
            goto L_8001A760;
    }
    // 0x8001A76C: nop

L_8001A770:
    // 0x8001A770: jal         0x8001A24C
    // 0x8001A774: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    func_8001A24C(rdram, ctx);
        goto after_25;
    // 0x8001A774: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_25:
    // 0x8001A778: beq         $v0, $zero, L_8001A854
    if (ctx->r2 == 0) {
        // 0x8001A77C: addiu       $t1, $zero, -0x1
        ctx->r9 = ADD32(0, -0X1);
            goto L_8001A854;
    }
    // 0x8001A77C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8001A780: jal         0x8001A24C
    // 0x8001A784: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    func_8001A24C(rdram, ctx);
        goto after_26;
    // 0x8001A784: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_26:
    // 0x8001A788: beq         $v0, $zero, L_8001A848
    if (ctx->r2 == 0) {
        // 0x8001A78C: addiu       $t0, $zero, -0x1
        ctx->r8 = ADD32(0, -0X1);
            goto L_8001A848;
    }
    // 0x8001A78C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8001A790: lhu         $t3, 0x50($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X50);
    // 0x8001A794: addiu       $v0, $zero, 0x4B31
    ctx->r2 = ADD32(0, 0X4B31);
    // 0x8001A798: lhu         $t4, 0x48($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X48);
    // 0x8001A79C: bne         $v0, $t3, L_8001A840
    if (ctx->r2 != ctx->r11) {
        // 0x8001A7A0: addiu       $t9, $zero, -0x1
        ctx->r25 = ADD32(0, -0X1);
            goto L_8001A840;
    }
    // 0x8001A7A0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8001A7A4: bne         $v0, $t4, L_8001A838
    if (ctx->r2 != ctx->r12) {
        // 0x8001A7A8: addiu       $t8, $zero, -0x1
        ctx->r24 = ADD32(0, -0X1);
            goto L_8001A838;
    }
    // 0x8001A7A8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8001A7AC: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
    // 0x8001A7B0: addiu       $t5, $zero, 0x4B31
    ctx->r13 = ADD32(0, 0X4B31);
    // 0x8001A7B4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001A7B8: sh          $t5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r13;
    // 0x8001A7BC: lbu         $t6, 0x52($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X52);
    // 0x8001A7C0: addiu       $a0, $a0, -0x6B68
    ctx->r4 = ADD32(ctx->r4, -0X6B68);
    // 0x8001A7C4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8001A7C8: sra         $t7, $t6, 4
    ctx->r15 = S32(SIGNED(ctx->r14) >> 4);
    // 0x8001A7CC: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x8001A7D0: sb          $t8, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r24;
    // 0x8001A7D4: lbu         $t9, 0x52($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X52);
    // 0x8001A7D8: andi        $t0, $t9, 0xF
    ctx->r8 = ctx->r25 & 0XF;
    // 0x8001A7DC: sb          $t0, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r8;
    // 0x8001A7E0: lbu         $t1, 0x53($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X53);
    // 0x8001A7E4: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x8001A7E8: sb          $t2, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r10;
    // 0x8001A7EC: lwl         $t3, 0x4A($sp)
    ctx->r11 = do_lwl(rdram, ctx->r11, ctx->r29, 0X4A);
    // 0x8001A7F0: lwr         $t3, 0x4D($sp)
    ctx->r11 = do_lwr(rdram, ctx->r11, ctx->r29, 0X4D);
    // 0x8001A7F4: jal         0x8001A29C
    // 0x8001A7F8: sw          $t3, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r11;
    func_8001A29C(rdram, ctx);
        goto after_27;
    // 0x8001A7F8: sw          $t3, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r11;
    after_27:
    // 0x8001A7FC: lbu         $t4, 0x40($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X40);
    // 0x8001A800: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001A804: addiu       $v1, $v1, -0x6B68
    ctx->r3 = ADD32(ctx->r3, -0X6B68);
    // 0x8001A808: beql        $v0, $t4, L_8001A85C
    if (ctx->r2 == ctx->r12) {
        // 0x8001A80C: lw          $t2, 0x34($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X34);
            goto L_8001A85C;
    }
    goto skip_6;
    // 0x8001A80C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    skip_6:
    // 0x8001A810: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001A814:
    // 0x8001A814: addu        $t5, $v1, $v0
    ctx->r13 = ADD32(ctx->r3, ctx->r2);
    // 0x8001A818: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001A81C: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x8001A820: sra         $v0, $t6, 16
    ctx->r2 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8001A824: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x8001A828: bne         $at, $zero, L_8001A814
    if (ctx->r1 != 0) {
        // 0x8001A82C: sb          $zero, 0x0($t5)
        MEM_B(0X0, ctx->r13) = 0;
            goto L_8001A814;
    }
    // 0x8001A82C: sb          $zero, 0x0($t5)
    MEM_B(0X0, ctx->r13) = 0;
    // 0x8001A830: b           L_8001A85C
    // 0x8001A834: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
        goto L_8001A85C;
    // 0x8001A834: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
L_8001A838:
    // 0x8001A838: b           L_8001A858
    // 0x8001A83C: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
        goto L_8001A858;
    // 0x8001A83C: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_8001A840:
    // 0x8001A840: b           L_8001A858
    // 0x8001A844: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
        goto L_8001A858;
    // 0x8001A844: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_8001A848:
    // 0x8001A848: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8001A84C: b           L_8001A85C
    // 0x8001A850: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
        goto L_8001A85C;
    // 0x8001A850: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
L_8001A854:
    // 0x8001A854: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
L_8001A858:
    // 0x8001A858: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
L_8001A85C:
    // 0x8001A85C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001A860: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8001A864: bne         $t2, $at, L_8001AA80
    if (ctx->r10 != ctx->r1) {
        // 0x8001A868: addiu       $t3, $zero, 0x4E47
        ctx->r11 = ADD32(0, 0X4E47);
            goto L_8001AA80;
    }
    // 0x8001A868: addiu       $t3, $zero, 0x4E47
    ctx->r11 = ADD32(0, 0X4E47);
    // 0x8001A86C: b           L_8001AA80
    // 0x8001A870: sh          $t3, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r11;
        goto L_8001AA80;
    // 0x8001A870: sh          $t3, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r11;
L_8001A874:
    // 0x8001A874: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001A878: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x8001A87C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x8001A880: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_8001A884:
    // 0x8001A884: addu        $t5, $a0, $v0
    ctx->r13 = ADD32(ctx->r4, ctx->r2);
    // 0x8001A888: addu        $t6, $a1, $v0
    ctx->r14 = ADD32(ctx->r5, ctx->r2);
    // 0x8001A88C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001A890: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x8001A894: sra         $v0, $t7, 16
    ctx->r2 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8001A898: slti        $at, $v0, 0x7
    ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x8001A89C: sb          $v1, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r3;
    // 0x8001A8A0: bne         $at, $zero, L_8001A884
    if (ctx->r1 != 0) {
        // 0x8001A8A4: sb          $v1, 0x0($t6)
        MEM_B(0X0, ctx->r14) = ctx->r3;
            goto L_8001A884;
    }
    // 0x8001A8A4: sb          $v1, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r3;
    // 0x8001A8A8: addiu       $t9, $zero, 0x4B
    ctx->r25 = ADD32(0, 0X4B);
    // 0x8001A8AC: addiu       $t0, $zero, 0x31
    ctx->r8 = ADD32(0, 0X31);
    // 0x8001A8B0: sb          $t9, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r25;
    // 0x8001A8B4: sb          $t0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r8;
    // 0x8001A8B8: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8001A8BC: lw          $t1, -0x68C8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X68C8);
    // 0x8001A8C0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001A8C4: lbu         $v0, -0x662B($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X662B);
    // 0x8001A8C8: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x8001A8CC: sh          $a3, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r7;
    // 0x8001A8D0: or          $t3, $v0, $t2
    ctx->r11 = ctx->r2 | ctx->r10;
    // 0x8001A8D4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001A8D8: lbu         $v0, -0x6B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X6B8F);
    // 0x8001A8DC: sb          $t3, 0x52($sp)
    MEM_B(0X52, ctx->r29) = ctx->r11;
    // 0x8001A8E0: jal         0x8001A2E8
    // 0x8001A8E4: sb          $v0, 0x53($sp)
    MEM_B(0X53, ctx->r29) = ctx->r2;
    func_8001A2E8(rdram, ctx);
        goto after_28;
    // 0x8001A8E4: sb          $v0, 0x53($sp)
    MEM_B(0X53, ctx->r29) = ctx->r2;
    after_28:
    // 0x8001A8E8: lh          $a3, 0x5E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X5E);
    // 0x8001A8EC: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8001A8F0: sll         $a0, $a3, 3
    ctx->r4 = S32(ctx->r7 << 3);
    // 0x8001A8F4: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x8001A8F8: sll         $t4, $a0, 16
    ctx->r12 = S32(ctx->r4 << 16);
    // 0x8001A8FC: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8001A900: jal         0x8000A3B8
    // 0x8001A904: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8000A3B8(rdram, ctx);
        goto after_29;
    // 0x8001A904: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_29:
    // 0x8001A908: jal         0x8000A414
    // 0x8001A90C: nop

    func_8000A414(rdram, ctx);
        goto after_30;
    // 0x8001A90C: nop

    after_30:
    // 0x8001A910: beql        $v0, $zero, L_8001A92C
    if (ctx->r2 == 0) {
        // 0x8001A914: lw          $t6, 0x20($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X20);
            goto L_8001A92C;
    }
    goto skip_7;
    // 0x8001A914: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    skip_7:
L_8001A918:
    // 0x8001A918: jal         0x8000A414
    // 0x8001A91C: nop

    func_8000A414(rdram, ctx);
        goto after_31;
    // 0x8001A91C: nop

    after_31:
    // 0x8001A920: bne         $v0, $zero, L_8001A918
    if (ctx->r2 != 0) {
        // 0x8001A924: nop
    
            goto L_8001A918;
    }
    // 0x8001A924: nop

    // 0x8001A928: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
L_8001A92C:
    // 0x8001A92C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8001A930: addiu       $t8, $zero, 0x4B
    ctx->r24 = ADD32(0, 0X4B);
    // 0x8001A934: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8001A938: sh          $t7, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r15;
    // 0x8001A93C: addiu       $t9, $zero, 0x31
    ctx->r25 = ADD32(0, 0X31);
    // 0x8001A940: sb          $t8, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r24;
    // 0x8001A944: sb          $t9, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r25;
    // 0x8001A948: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8001A94C: lw          $t0, -0x6BD4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X6BD4);
    // 0x8001A950: swl         $t0, 0x4A($sp)
    do_swl(rdram, 0X4A, ctx->r29, ctx->r8);
    // 0x8001A954: jal         0x8001A2E8
    // 0x8001A958: swr         $t0, 0x4D($sp)
    do_swr(rdram, 0X4D, ctx->r29, ctx->r8);
    func_8001A2E8(rdram, ctx);
        goto after_32;
    // 0x8001A958: swr         $t0, 0x4D($sp)
    do_swr(rdram, 0X4D, ctx->r29, ctx->r8);
    after_32:
    // 0x8001A95C: lh          $a0, 0x30($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X30);
    // 0x8001A960: jal         0x8000A3B8
    // 0x8001A964: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_8000A3B8(rdram, ctx);
        goto after_33;
    // 0x8001A964: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_33:
    // 0x8001A968: jal         0x8000A414
    // 0x8001A96C: nop

    func_8000A414(rdram, ctx);
        goto after_34;
    // 0x8001A96C: nop

    after_34:
    // 0x8001A970: beql        $v0, $zero, L_8001A98C
    if (ctx->r2 == 0) {
        // 0x8001A974: lh          $a0, 0x30($sp)
        ctx->r4 = MEM_H(ctx->r29, 0X30);
            goto L_8001A98C;
    }
    goto skip_8;
    // 0x8001A974: lh          $a0, 0x30($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X30);
    skip_8:
L_8001A978:
    // 0x8001A978: jal         0x8000A414
    // 0x8001A97C: nop

    func_8000A414(rdram, ctx);
        goto after_35;
    // 0x8001A97C: nop

    after_35:
    // 0x8001A980: bne         $v0, $zero, L_8001A978
    if (ctx->r2 != 0) {
        // 0x8001A984: nop
    
            goto L_8001A978;
    }
    // 0x8001A984: nop

    // 0x8001A988: lh          $a0, 0x30($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X30);
L_8001A98C:
    // 0x8001A98C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8001A990: addiu       $a1, $a1, -0x6B68
    ctx->r5 = ADD32(ctx->r5, -0X6B68);
    // 0x8001A994: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001A998: sll         $t1, $a0, 16
    ctx->r9 = S32(ctx->r4 << 16);
    // 0x8001A99C: sra         $a0, $t1, 16
    ctx->r4 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8001A9A0: jal         0x8000A3B8
    // 0x8001A9A4: sh          $a0, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r4;
    func_8000A3B8(rdram, ctx);
        goto after_36;
    // 0x8001A9A4: sh          $a0, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r4;
    after_36:
    // 0x8001A9A8: jal         0x8000A414
    // 0x8001A9AC: nop

    func_8000A414(rdram, ctx);
        goto after_37;
    // 0x8001A9AC: nop

    after_37:
    // 0x8001A9B0: beql        $v0, $zero, L_8001A9CC
    if (ctx->r2 == 0) {
        // 0x8001A9B4: lh          $a0, 0x30($sp)
        ctx->r4 = MEM_H(ctx->r29, 0X30);
            goto L_8001A9CC;
    }
    goto skip_9;
    // 0x8001A9B4: lh          $a0, 0x30($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X30);
    skip_9:
L_8001A9B8:
    // 0x8001A9B8: jal         0x8000A414
    // 0x8001A9BC: nop

    func_8000A414(rdram, ctx);
        goto after_38;
    // 0x8001A9BC: nop

    after_38:
    // 0x8001A9C0: bne         $v0, $zero, L_8001A9B8
    if (ctx->r2 != 0) {
        // 0x8001A9C4: nop
    
            goto L_8001A9B8;
    }
    // 0x8001A9C4: nop

    // 0x8001A9C8: lh          $a0, 0x30($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X30);
L_8001A9CC:
    // 0x8001A9CC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8001A9D0: addiu       $a1, $a1, -0x6B60
    ctx->r5 = ADD32(ctx->r5, -0X6B60);
    // 0x8001A9D4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001A9D8: sll         $t3, $a0, 16
    ctx->r11 = S32(ctx->r4 << 16);
    // 0x8001A9DC: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8001A9E0: jal         0x8000A3B8
    // 0x8001A9E4: sh          $a0, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r4;
    func_8000A3B8(rdram, ctx);
        goto after_39;
    // 0x8001A9E4: sh          $a0, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r4;
    after_39:
    // 0x8001A9E8: jal         0x8000A414
    // 0x8001A9EC: nop

    func_8000A414(rdram, ctx);
        goto after_40;
    // 0x8001A9EC: nop

    after_40:
    // 0x8001A9F0: beq         $v0, $zero, L_8001AA08
    if (ctx->r2 == 0) {
        // 0x8001A9F4: nop
    
            goto L_8001AA08;
    }
    // 0x8001A9F4: nop

L_8001A9F8:
    // 0x8001A9F8: jal         0x8000A414
    // 0x8001A9FC: nop

    func_8000A414(rdram, ctx);
        goto after_41;
    // 0x8001A9FC: nop

    after_41:
    // 0x8001AA00: bne         $v0, $zero, L_8001A9F8
    if (ctx->r2 != 0) {
        // 0x8001AA04: nop
    
            goto L_8001A9F8;
    }
    // 0x8001AA04: nop

L_8001AA08:
    // 0x8001AA08: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001AA0C: addiu       $a0, $a0, -0x6B68
    ctx->r4 = ADD32(ctx->r4, -0X6B68);
    // 0x8001AA10: jal         0x8001A29C
    // 0x8001AA14: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_8001A29C(rdram, ctx);
        goto after_42;
    // 0x8001AA14: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_42:
    // 0x8001AA18: lh          $a0, 0x30($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X30);
    // 0x8001AA1C: sb          $v0, 0x40($sp)
    MEM_B(0X40, ctx->r29) = ctx->r2;
    // 0x8001AA20: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x8001AA24: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001AA28: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x8001AA2C: jal         0x8000A3B8
    // 0x8001AA30: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    func_8000A3B8(rdram, ctx);
        goto after_43;
    // 0x8001AA30: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    after_43:
    // 0x8001AA34: jal         0x8000A414
    // 0x8001AA38: nop

    func_8000A414(rdram, ctx);
        goto after_44;
    // 0x8001AA38: nop

    after_44:
    // 0x8001AA3C: beql        $v0, $zero, L_8001AA84
    if (ctx->r2 == 0) {
        // 0x8001AA40: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8001AA84;
    }
    goto skip_10;
    // 0x8001AA40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_10:
L_8001AA44:
    // 0x8001AA44: jal         0x8000A414
    // 0x8001AA48: nop

    func_8000A414(rdram, ctx);
        goto after_45;
    // 0x8001AA48: nop

    after_45:
    // 0x8001AA4C: bne         $v0, $zero, L_8001AA44
    if (ctx->r2 != 0) {
        // 0x8001AA50: nop
    
            goto L_8001AA44;
    }
    // 0x8001AA50: nop

    // 0x8001AA54: b           L_8001AA84
    // 0x8001AA58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8001AA84;
    // 0x8001AA58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001AA5C:
    // 0x8001AA5C: sll         $a0, $a3, 16
    ctx->r4 = S32(ctx->r7 << 16);
    // 0x8001AA60: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001AA64: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8001AA68: jal         0x8000A3B8
    // 0x8001AA6C: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    func_8000A3B8(rdram, ctx);
        goto after_46;
    // 0x8001AA6C: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    after_46:
    // 0x8001AA70: b           L_8001AA84
    // 0x8001AA74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8001AA84;
    // 0x8001AA74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001AA78:
    // 0x8001AA78: jal         0x8001A190
    // 0x8001AA7C: nop

    func_8001A190(rdram, ctx);
        goto after_47;
    // 0x8001AA7C: nop

    after_47:
L_8001AA80:
    // 0x8001AA80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001AA84:
    // 0x8001AA84: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8001AA88: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8001AA90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8001AA90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001AA94: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001AA98: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8001AA9C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8001AAA0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8001AAA4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001AAA8: jal         0x8004B1E0
    // 0x8001AAAC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8004B1E0(rdram, ctx);
        goto after_0;
    // 0x8001AAAC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8001AAB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001AAB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001AAB8: jal         0x8000BD4C
    // 0x8001AABC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BD4C(rdram, ctx);
        goto after_1;
    // 0x8001AABC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8001AAC0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001AAC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001AAC8: jal         0x8000BDEC
    // 0x8001AACC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BDEC(rdram, ctx);
        goto after_2;
    // 0x8001AACC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8001AAD0: addiu       $t6, $zero, 0x3E8
    ctx->r14 = ADD32(0, 0X3E8);
    // 0x8001AAD4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001AAD8: sw          $t6, -0x2CF8($at)
    MEM_W(-0X2CF8, ctx->r1) = ctx->r14;
    // 0x8001AADC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001AAE0: addiu       $t7, $zero, 0x3D0
    ctx->r15 = ADD32(0, 0X3D0);
    // 0x8001AAE4: sw          $t7, -0x2CF4($at)
    MEM_W(-0X2CF4, ctx->r1) = ctx->r15;
    // 0x8001AAE8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001AAEC: jal         0x8000798C
    // 0x8001AAF0: sh          $zero, -0x2CC4($at)
    MEM_H(-0X2CC4, ctx->r1) = 0;
    func_8000798C(rdram, ctx);
        goto after_3;
    // 0x8001AAF0: sh          $zero, -0x2CC4($at)
    MEM_H(-0X2CC4, ctx->r1) = 0;
    after_3:
    // 0x8001AAF4: jal         0x8000798C
    // 0x8001AAF8: nop

    func_8000798C(rdram, ctx);
        goto after_4;
    // 0x8001AAF8: nop

    after_4:
    // 0x8001AAFC: jal         0x8000798C
    // 0x8001AB00: nop

    func_8000798C(rdram, ctx);
        goto after_5;
    // 0x8001AB00: nop

    after_5:
    // 0x8001AB04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001AB08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001AB0C: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x8001AB10: addiu       $a3, $zero, 0x27
    ctx->r7 = ADD32(0, 0X27);
    // 0x8001AB14: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001AB18: jal         0x8004C580
    // 0x8001AB1C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_6;
    // 0x8001AB1C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_6:
    // 0x8001AB20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001AB24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001AB28: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x8001AB2C: addiu       $a3, $zero, 0x26
    ctx->r7 = ADD32(0, 0X26);
    // 0x8001AB30: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001AB34: jal         0x8004C580
    // 0x8001AB38: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_7;
    // 0x8001AB38: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_7:
    // 0x8001AB3C: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
    // 0x8001AB40: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8001AB44: jal         0x8004D134
    // 0x8001AB48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004D134(rdram, ctx);
        goto after_8;
    // 0x8001AB48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x8001AB4C: jal         0x8004D1F0
    // 0x8001AB50: nop

    func_8004D1F0(rdram, ctx);
        goto after_9;
    // 0x8001AB50: nop

    after_9:
    // 0x8001AB54: beq         $v0, $zero, L_8001AB74
    if (ctx->r2 == 0) {
        // 0x8001AB58: nop
    
            goto L_8001AB74;
    }
    // 0x8001AB58: nop

L_8001AB5C:
    // 0x8001AB5C: jal         0x8000798C
    // 0x8001AB60: nop

    func_8000798C(rdram, ctx);
        goto after_10;
    // 0x8001AB60: nop

    after_10:
    // 0x8001AB64: jal         0x8004D1F0
    // 0x8001AB68: nop

    func_8004D1F0(rdram, ctx);
        goto after_11;
    // 0x8001AB68: nop

    after_11:
    // 0x8001AB6C: bne         $v0, $zero, L_8001AB5C
    if (ctx->r2 != 0) {
        // 0x8001AB70: nop
    
            goto L_8001AB5C;
    }
    // 0x8001AB70: nop

L_8001AB74:
    // 0x8001AB74: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8001AB78: addiu       $s0, $s0, -0x2E5A
    ctx->r16 = ADD32(ctx->r16, -0X2E5A);
    // 0x8001AB7C: lhu         $t8, 0x0($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X0);
L_8001AB80:
    // 0x8001AB80: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8001AB84: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    // 0x8001AB88: andi        $t9, $t8, 0x1000
    ctx->r25 = ctx->r24 & 0X1000;
    // 0x8001AB8C: beq         $t9, $zero, L_8001AC0C
    if (ctx->r25 == 0) {
        // 0x8001AB90: nop
    
            goto L_8001AC0C;
    }
    // 0x8001AB90: nop

    // 0x8001AB94: jal         0x80044480
    // 0x8001AB98: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    func_80044480(rdram, ctx);
        goto after_12;
    // 0x8001AB98: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_12:
    // 0x8001AB9C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x8001ABA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001ABA4: jal         0x8004D134
    // 0x8001ABA8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_8004D134(rdram, ctx);
        goto after_13;
    // 0x8001ABA8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_13:
    // 0x8001ABAC: jal         0x8004D1F0
    // 0x8001ABB0: nop

    func_8004D1F0(rdram, ctx);
        goto after_14;
    // 0x8001ABB0: nop

    after_14:
    // 0x8001ABB4: beql        $v0, $zero, L_8001ABD8
    if (ctx->r2 == 0) {
        // 0x8001ABB8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8001ABD8;
    }
    goto skip_0;
    // 0x8001ABB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_0:
L_8001ABBC:
    // 0x8001ABBC: jal         0x8000798C
    // 0x8001ABC0: nop

    func_8000798C(rdram, ctx);
        goto after_15;
    // 0x8001ABC0: nop

    after_15:
    // 0x8001ABC4: jal         0x8004D1F0
    // 0x8001ABC8: nop

    func_8004D1F0(rdram, ctx);
        goto after_16;
    // 0x8001ABC8: nop

    after_16:
    // 0x8001ABCC: bne         $v0, $zero, L_8001ABBC
    if (ctx->r2 != 0) {
        // 0x8001ABD0: nop
    
            goto L_8001ABBC;
    }
    // 0x8001ABD0: nop

    // 0x8001ABD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8001ABD8:
    // 0x8001ABD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8001ABDC: jal         0x8004C4D8
    // 0x8001ABE0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    func_8004C4D8(rdram, ctx);
        goto after_17;
    // 0x8001ABE0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_17:
    // 0x8001ABE4: jal         0x8004B21C
    // 0x8001ABE8: nop

    func_8004B21C(rdram, ctx);
        goto after_18;
    // 0x8001ABE8: nop

    after_18:
    // 0x8001ABEC: jal         0x8000798C
    // 0x8001ABF0: nop

    func_8000798C(rdram, ctx);
        goto after_19;
    // 0x8001ABF0: nop

    after_19:
    // 0x8001ABF4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8001ABF8: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
L_8001ABFC:
    // 0x8001ABFC: jal         0x8000798C
    // 0x8001AC00: nop

    func_8000798C(rdram, ctx);
        goto after_20;
    // 0x8001AC00: nop

    after_20:
    // 0x8001AC04: b           L_8001ABFC
    // 0x8001AC08: nop

        goto L_8001ABFC;
    // 0x8001AC08: nop

L_8001AC0C:
    // 0x8001AC0C: jal         0x8004C388
    // 0x8001AC10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004C388(rdram, ctx);
        goto after_21;
    // 0x8001AC10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_21:
    // 0x8001AC14: sll         $t2, $s1, 24
    ctx->r10 = S32(ctx->r17 << 24);
    // 0x8001AC18: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x8001AC1C: addiu       $a2, $a2, 0x64B0
    ctx->r6 = ADD32(ctx->r6, 0X64B0);
    // 0x8001AC20: sra         $a0, $t2, 16
    ctx->r4 = S32(SIGNED(ctx->r10) >> 16);
    // 0x8001AC24: jal         0x8004BCF0
    // 0x8001AC28: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8004BCF0(rdram, ctx);
        goto after_22;
    // 0x8001AC28: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_22:
    // 0x8001AC2C: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8001AC30: sll         $t4, $s1, 16
    ctx->r12 = S32(ctx->r17 << 16);
    // 0x8001AC34: jal         0x8000798C
    // 0x8001AC38: sra         $s1, $t4, 16
    ctx->r17 = S32(SIGNED(ctx->r12) >> 16);
    func_8000798C(rdram, ctx);
        goto after_23;
    // 0x8001AC38: sra         $s1, $t4, 16
    ctx->r17 = S32(SIGNED(ctx->r12) >> 16);
    after_23:
    // 0x8001AC3C: b           L_8001AB80
    // 0x8001AC40: lhu         $t8, 0x0($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X0);
        goto L_8001AB80;
    // 0x8001AC40: lhu         $t8, 0x0($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X0);
    // 0x8001AC44: nop

    // 0x8001AC48: nop

    // 0x8001AC4C: nop

    // 0x8001AC50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001AC54: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AC58: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8001AC5C: jr          $ra
    // 0x8001AC60: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    TRACE_RETURN()
    return;
    // 0x8001AC60: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001AC64: nop

    // 0x8001AC68: nop

    // 0x8001AC6C: nop

    // 0x8001AC70: jr          $ra
    // 0x8001AC74: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    TRACE_RETURN()
    return;
    // 0x8001AC74: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void func_8001AC78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8001AC78: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8001AC7C: lh          $t6, -0x662C($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X662C);
    // 0x8001AC80: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001AC84: lui         $t8, 0x8007
    ctx->r24 = S32(0X8007 << 16);
    // 0x8001AC88: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001AC8C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8001AC90: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8001AC94: addiu       $t8, $t8, -0x644C
    ctx->r24 = ADD32(ctx->r24, -0X644C);
    // 0x8001AC98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001AC9C: addu        $a3, $t7, $t8
    ctx->r7 = ADD32(ctx->r15, ctx->r24);
    // 0x8001ACA0: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x8001ACA4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8001ACA8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8001ACAC:
    // 0x8001ACAC: addu        $v1, $a3, $a0
    ctx->r3 = ADD32(ctx->r7, ctx->r4);
    // 0x8001ACB0: lbu         $t9, -0x6($v1)
    ctx->r25 = MEM_BU(ctx->r3, -0X6);
    // 0x8001ACB4: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8001ACB8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001ACBC: addu        $t0, $a1, $v0
    ctx->r8 = ADD32(ctx->r5, ctx->r2);
    // 0x8001ACC0: sll         $t3, $a0, 16
    ctx->r11 = S32(ctx->r4 << 16);
    // 0x8001ACC4: sh          $t9, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r25;
    // 0x8001ACC8: lbu         $t1, -0x3($v1)
    ctx->r9 = MEM_BU(ctx->r3, -0X3);
    // 0x8001ACCC: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8001ACD0: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x8001ACD4: addu        $t2, $a2, $v0
    ctx->r10 = ADD32(ctx->r6, ctx->r2);
    // 0x8001ACD8: bne         $at, $zero, L_8001ACAC
    if (ctx->r1 != 0) {
        // 0x8001ACDC: sh          $t1, 0x0($t2)
        MEM_H(0X0, ctx->r10) = ctx->r9;
            goto L_8001ACAC;
    }
    // 0x8001ACDC: sh          $t1, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r9;
    // 0x8001ACE0: lh          $a0, 0x28($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X28);
    // 0x8001ACE4: lh          $a1, 0x2A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2A);
    // 0x8001ACE8: jal         0x8000BD4C
    // 0x8001ACEC: lh          $a2, 0x2C($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X2C);
    func_8000BD4C(rdram, ctx);
        goto after_0;
    // 0x8001ACEC: lh          $a2, 0x2C($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X2C);
    after_0:
    // 0x8001ACF0: lh          $a0, 0x20($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X20);
    // 0x8001ACF4: lh          $a1, 0x22($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X22);
    // 0x8001ACF8: jal         0x8000BDEC
    // 0x8001ACFC: lh          $a2, 0x24($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X24);
    func_8000BDEC(rdram, ctx);
        goto after_1;
    // 0x8001ACFC: lh          $a2, 0x24($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X24);
    after_1:
    // 0x8001AD00: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x8001AD04: lh          $t5, -0x662C($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X662C);
    // 0x8001AD08: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8001AD0C: addiu       $t6, $zero, 0x3E8
    ctx->r14 = ADD32(0, 0X3E8);
    // 0x8001AD10: bne         $t5, $at, L_8001AD28
    if (ctx->r13 != ctx->r1) {
        // 0x8001AD14: addiu       $t7, $zero, 0x3DA
        ctx->r15 = ADD32(0, 0X3DA);
            goto L_8001AD28;
    }
    // 0x8001AD14: addiu       $t7, $zero, 0x3DA
    ctx->r15 = ADD32(0, 0X3DA);
    // 0x8001AD18: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001AD1C: sw          $t6, -0x2CF8($at)
    MEM_W(-0X2CF8, ctx->r1) = ctx->r14;
    // 0x8001AD20: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001AD24: sw          $t7, -0x2CF4($at)
    MEM_W(-0X2CF4, ctx->r1) = ctx->r15;
L_8001AD28:
    // 0x8001AD28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001AD2C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001AD30: jr          $ra
    TRACE_RETURN()
    return;
;}
static void func_8001AD38_entry(uint8_t* rdram, recomp_context* ctx, unsigned entry) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    if (entry == 1) goto indirect_8001B250;

    // 0x8001AD38: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8001AD3C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8001AD40: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8001AD44: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8001AD48: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8001AD4C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8001AD50: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8001AD54: sh          $zero, 0x50($sp)
    MEM_H(0X50, ctx->r29) = 0;
    // 0x8001AD58: sh          $zero, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = 0;
    // 0x8001AD5C: sh          $zero, 0x48($sp)
    MEM_H(0X48, ctx->r29) = 0;
    // 0x8001AD60: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8001AD64: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001AD68: bne         $t7, $at, L_8001AD88
    if (ctx->r15 != ctx->r1) {
        // 0x8001AD6C: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_8001AD88;
    }
    // 0x8001AD6C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001AD70: jal         0x80035D1C
    // 0x8001AD74: lh          $a0, -0x6B84($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X6B84);
    func_80035D1C(rdram, ctx);
        goto after_0;
    // 0x8001AD74: lh          $a0, -0x6B84($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X6B84);
    after_0:
    // 0x8001AD78: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x8001AD7C: sra         $t8, $s3, 16
    ctx->r24 = S32(SIGNED(ctx->r19) >> 16);
    // 0x8001AD80: b           L_8001ADA4
    // 0x8001AD84: or          $s3, $t8, $zero
    ctx->r19 = ctx->r24 | 0;
        goto L_8001ADA4;
    // 0x8001AD84: or          $s3, $t8, $zero
    ctx->r19 = ctx->r24 | 0;
L_8001AD88:
    // 0x8001AD88: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8001AD8C: lh          $t9, -0x6B90($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X6B90);
    // 0x8001AD90: addiu       $s3, $zero, 0x6
    ctx->r19 = ADD32(0, 0X6);
    // 0x8001AD94: bne         $t9, $zero, L_8001ADA4
    if (ctx->r25 != 0) {
        // 0x8001AD98: nop
    
            goto L_8001ADA4;
    }
    // 0x8001AD98: nop

    // 0x8001AD9C: b           L_8001ADA4
    // 0x8001ADA0: addiu       $s3, $zero, 0x5
    ctx->r19 = ADD32(0, 0X5);
        goto L_8001ADA4;
    // 0x8001ADA0: addiu       $s3, $zero, 0x5
    ctx->r19 = ADD32(0, 0X5);
L_8001ADA4:
    // 0x8001ADA4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8001ADA8: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x8001ADAC: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
    // 0x8001ADB0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8001ADB4: jal         0x8004D134
    // 0x8001ADB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004D134(rdram, ctx);
        goto after_1;
    // 0x8001ADB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8001ADBC: lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // 0x8001ADC0: addiu       $a0, $a0, -0x3900
    ctx->r4 = ADD32(ctx->r4, -0X3900);
    // 0x8001ADC4: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    // 0x8001ADC8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8001ADCC: jal         0x80004CE0
    // 0x8001ADD0: addiu       $a3, $sp, 0x44
    ctx->r7 = ADD32(ctx->r29, 0X44);
    func_80004CE0(rdram, ctx);
        goto after_2;
    // 0x8001ADD0: addiu       $a3, $sp, 0x44
    ctx->r7 = ADD32(ctx->r29, 0X44);
    after_2:
    // 0x8001ADD4: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x8001ADD8: jal         0x8004B1E0
    // 0x8001ADDC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_8004B1E0(rdram, ctx);
        goto after_3;
    // 0x8001ADDC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_3:
    // 0x8001ADE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001ADE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001ADE8: jal         0x8000BD4C
    // 0x8001ADEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BD4C(rdram, ctx);
        goto after_4;
    // 0x8001ADEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x8001ADF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001ADF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001ADF8: jal         0x8000BDEC
    // 0x8001ADFC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BDEC(rdram, ctx);
        goto after_5;
    // 0x8001ADFC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8001AE00: addiu       $t2, $zero, 0x3E8
    ctx->r10 = ADD32(0, 0X3E8);
    // 0x8001AE04: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001AE08: sw          $t2, -0x2CF8($at)
    MEM_W(-0X2CF8, ctx->r1) = ctx->r10;
    // 0x8001AE0C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001AE10: addiu       $t3, $zero, 0x3D0
    ctx->r11 = ADD32(0, 0X3D0);
    // 0x8001AE14: sw          $t3, -0x2CF4($at)
    MEM_W(-0X2CF4, ctx->r1) = ctx->r11;
    // 0x8001AE18: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001AE1C: sh          $zero, -0x2CC4($at)
    MEM_H(-0X2CC4, ctx->r1) = 0;
    // 0x8001AE20: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001AE24: lui         $at, 0x4238
    ctx->r1 = S32(0X4238 << 16);
    // 0x8001AE28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001AE2C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001AE30: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001AE34: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8001AE38: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001AE3C: addiu       $v1, $v1, -0x6C40
    ctx->r3 = ADD32(ctx->r3, -0X6C40);
    // 0x8001AE40: addiu       $v0, $v0, -0x6C50
    ctx->r2 = ADD32(ctx->r2, -0X6C50);
    // 0x8001AE44: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8001AE48: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x8001AE4C: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x8001AE50: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x8001AE54: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x8001AE58: jal         0x8000798C
    // 0x8001AE5C: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    func_8000798C(rdram, ctx);
        goto after_6;
    // 0x8001AE5C: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    after_6:
    // 0x8001AE60: jal         0x8000798C
    // 0x8001AE64: nop

    func_8000798C(rdram, ctx);
        goto after_7;
    // 0x8001AE64: nop

    after_7:
    // 0x8001AE68: jal         0x8000798C
    // 0x8001AE6C: nop

    func_8000798C(rdram, ctx);
        goto after_8;
    // 0x8001AE6C: nop

    after_8:
    // 0x8001AE70: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8001AE74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001AE78: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x8001AE7C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001AE80: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001AE84: jal         0x8004C580
    // 0x8001AE88: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_9;
    // 0x8001AE88: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_9:
    // 0x8001AE8C: bne         $s3, $zero, L_8001AEE8
    if (ctx->r19 != 0) {
        // 0x8001AE90: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8001AEE8;
    }
    // 0x8001AE90: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001AE94: addiu       $s0, $zero, 0x3C
    ctx->r16 = ADD32(0, 0X3C);
L_8001AE98:
    // 0x8001AE98: jal         0x8000798C
    // 0x8001AE9C: nop

    func_8000798C(rdram, ctx);
        goto after_10;
    // 0x8001AE9C: nop

    after_10:
    // 0x8001AEA0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8001AEA4: lhu         $t6, -0x2E5A($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X2E5A);
    // 0x8001AEA8: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8001AEAC: sll         $t4, $s0, 16
    ctx->r12 = S32(ctx->r16 << 16);
    // 0x8001AEB0: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8001AEB4: andi        $t7, $t6, 0x9000
    ctx->r15 = ctx->r14 & 0X9000;
    // 0x8001AEB8: bne         $t7, $zero, L_8001AEC8
    if (ctx->r15 != 0) {
        // 0x8001AEBC: or          $s0, $t5, $zero
        ctx->r16 = ctx->r13 | 0;
            goto L_8001AEC8;
    }
    // 0x8001AEBC: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
    // 0x8001AEC0: bne         $t5, $zero, L_8001AE98
    if (ctx->r13 != 0) {
        // 0x8001AEC4: nop
    
            goto L_8001AE98;
    }
    // 0x8001AEC4: nop

L_8001AEC8:
    // 0x8001AEC8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001AECC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8001AED0: lui         $s1, 0x8007
    ctx->r17 = S32(0X8007 << 16);
    // 0x8001AED4: sw          $zero, -0x6630($at)
    MEM_W(-0X6630, ctx->r1) = 0;
    // 0x8001AED8: addiu       $s1, $s1, -0x6414
    ctx->r17 = ADD32(ctx->r17, -0X6414);
    // 0x8001AEDC: sh          $t8, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r24;
    // 0x8001AEE0: b           L_8001AFC0
    // 0x8001AEE4: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
        goto L_8001AFC0;
    // 0x8001AEE4: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
L_8001AEE8:
    // 0x8001AEE8: lui         $s1, 0x8007
    ctx->r17 = S32(0X8007 << 16);
    // 0x8001AEEC: addiu       $s1, $s1, -0x6414
    ctx->r17 = ADD32(ctx->r17, -0X6414);
    // 0x8001AEF0: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
L_8001AEF4:
    // 0x8001AEF4: slt         $at, $s0, $s3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8001AEF8: beq         $at, $zero, L_8001AF60
    if (ctx->r1 == 0) {
        // 0x8001AEFC: sll         $t9, $s0, 2
        ctx->r25 = S32(ctx->r16 << 2);
            goto L_8001AF60;
    }
    // 0x8001AEFC: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x8001AF00: lui         $t1, 0x8007
    ctx->r9 = S32(0X8007 << 16);
    // 0x8001AF04: addiu       $t1, $t1, -0x63D8
    ctx->r9 = ADD32(ctx->r9, -0X63D8);
    // 0x8001AF08: addu        $v0, $t9, $t1
    ctx->r2 = ADD32(ctx->r25, ctx->r9);
    // 0x8001AF0C: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x8001AF10: addiu       $v1, $s0, 0x1
    ctx->r3 = ADD32(ctx->r16, 0X1);
    // 0x8001AF14: sll         $a3, $v1, 16
    ctx->r7 = S32(ctx->r3 << 16);
    // 0x8001AF18: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8001AF1C: sll         $t2, $a0, 16
    ctx->r10 = S32(ctx->r4 << 16);
    // 0x8001AF20: sra         $t4, $a3, 16
    ctx->r12 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8001AF24: or          $a3, $t4, $zero
    ctx->r7 = ctx->r12 | 0;
    // 0x8001AF28: sra         $a0, $t2, 16
    ctx->r4 = S32(SIGNED(ctx->r10) >> 16);
    // 0x8001AF2C: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x8001AF30: lh          $a1, 0x2($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X2);
    // 0x8001AF34: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x8001AF38: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001AF3C: jal         0x8004C580
    // 0x8001AF40: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_11;
    // 0x8001AF40: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_11:
    // 0x8001AF44: multu       $s0, $s2
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001AF48: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8001AF4C: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x8001AF50: mflo        $t6
    ctx->r14 = lo;
    // 0x8001AF54: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x8001AF58: b           L_8001AF74
    // 0x8001AF5C: sh          $t5, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r13;
        goto L_8001AF74;
    // 0x8001AF5C: sh          $t5, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r13;
L_8001AF60:
    // 0x8001AF60: multu       $s0, $s2
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001AF64: addiu       $v1, $s0, 0x1
    ctx->r3 = ADD32(ctx->r16, 0X1);
    // 0x8001AF68: mflo        $t8
    ctx->r24 = lo;
    // 0x8001AF6C: addu        $t9, $s1, $t8
    ctx->r25 = ADD32(ctx->r17, ctx->r24);
    // 0x8001AF70: sh          $zero, 0x8($t9)
    MEM_H(0X8, ctx->r25) = 0;
L_8001AF74:
    // 0x8001AF74: sll         $s0, $v1, 16
    ctx->r16 = S32(ctx->r3 << 16);
    // 0x8001AF78: sra         $t1, $s0, 16
    ctx->r9 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8001AF7C: slti        $at, $t1, 0x6
    ctx->r1 = SIGNED(ctx->r9) < 0X6 ? 1 : 0;
    // 0x8001AF80: bne         $at, $zero, L_8001AEF4
    if (ctx->r1 != 0) {
        // 0x8001AF84: or          $s0, $t1, $zero
        ctx->r16 = ctx->r9 | 0;
            goto L_8001AEF4;
    }
    // 0x8001AF84: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
    // 0x8001AF88: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
L_8001AF8C:
    // 0x8001AF8C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001AF90: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8001AF94: bnel        $t2, $at, L_8001AFE4
    if (ctx->r10 != ctx->r1) {
        // 0x8001AF98: lw          $t9, 0x44($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X44);
            goto L_8001AFE4;
    }
    goto skip_0;
    // 0x8001AF98: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x8001AF9C: lhu         $t3, -0x2E5A($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X2E5A);
    // 0x8001AFA0: lh          $t6, 0x50($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X50);
    // 0x8001AFA4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001AFA8: andi        $t4, $t3, 0x9000
    ctx->r12 = ctx->r11 & 0X9000;
    // 0x8001AFAC: beq         $t4, $zero, L_8001AFE0
    if (ctx->r12 == 0) {
        // 0x8001AFB0: addiu       $t5, $t6, 0x1
        ctx->r13 = ADD32(ctx->r14, 0X1);
            goto L_8001AFE0;
    }
    // 0x8001AFB0: addiu       $t5, $t6, 0x1
    ctx->r13 = ADD32(ctx->r14, 0X1);
    // 0x8001AFB4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001AFB8: sw          $t5, -0x6630($at)
    MEM_W(-0X6630, ctx->r1) = ctx->r13;
    // 0x8001AFBC: sh          $t7, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r15;
L_8001AFC0:
    // 0x8001AFC0: jal         0x80044480
    // 0x8001AFC4: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    func_80044480(rdram, ctx);
        goto after_12;
    // 0x8001AFC4: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_12:
    // 0x8001AFC8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x8001AFCC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001AFD0: jal         0x8004D134
    // 0x8001AFD4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_8004D134(rdram, ctx);
        goto after_13;
    // 0x8001AFD4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_13:
    // 0x8001AFD8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8001AFDC: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
L_8001AFE0:
    // 0x8001AFE0: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
L_8001AFE4:
    // 0x8001AFE4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8001AFE8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001AFEC: bne         $t9, $at, L_8001B05C
    if (ctx->r25 != ctx->r1) {
        // 0x8001AFF0: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8001B05C;
    }
    // 0x8001AFF0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8001AFF4: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8001AFF8: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x8001AFFC: sra         $t2, $v0, 16
    ctx->r10 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8001B000: sh          $zero, 0x48($sp)
    MEM_H(0X48, ctx->r29) = 0;
    // 0x8001B004: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8001B008: sh          $t1, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r9;
    // 0x8001B00C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8001B010: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001B014: addiu       $s3, $zero, 0x6
    ctx->r19 = ADD32(0, 0X6);
    // 0x8001B018: jal         0x8004C4D8
    // 0x8001B01C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    func_8004C4D8(rdram, ctx);
        goto after_14;
    // 0x8001B01C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_14:
    // 0x8001B020: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8001B024: jal         0x8004C4D8
    // 0x8001B028: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004C4D8(rdram, ctx);
        goto after_15;
    // 0x8001B028: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x8001B02C: jal         0x8004B21C
    // 0x8001B030: nop

    func_8004B21C(rdram, ctx);
        goto after_16;
    // 0x8001B030: nop

    after_16:
    // 0x8001B034: jal         0x80004E5C
    // 0x8001B038: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_80004E5C(rdram, ctx);
        goto after_17;
    // 0x8001B038: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_17:
    // 0x8001B03C: jal         0x8000798C
    // 0x8001B040: nop

    func_8000798C(rdram, ctx);
        goto after_18;
    // 0x8001B040: nop

    after_18:
    // 0x8001B044: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x8001B048: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
L_8001B04C:
    // 0x8001B04C: jal         0x8000798C
    // 0x8001B050: nop

    func_8000798C(rdram, ctx);
        goto after_19;
    // 0x8001B050: nop

    after_19:
    // 0x8001B054: b           L_8001B04C
    // 0x8001B058: nop

        goto L_8001B04C;
    // 0x8001B058: nop

L_8001B05C:
    // 0x8001B05C: blez        $s3, L_8001B0C0
    if (SIGNED(ctx->r19) <= 0) {
        // 0x8001B060: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8001B0C0;
    }
    // 0x8001B060: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001B064: lh          $t0, 0x50($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X50);
L_8001B068:
    // 0x8001B068: beq         $t0, $s0, L_8001B0A8
    if (ctx->r8 == ctx->r16) {
        // 0x8001B06C: sll         $t4, $s0, 2
        ctx->r12 = S32(ctx->r16 << 2);
            goto L_8001B0A8;
    }
    // 0x8001B06C: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x8001B070: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x8001B074: addiu       $t6, $t6, -0x63D8
    ctx->r14 = ADD32(ctx->r14, -0X63D8);
    // 0x8001B078: addu        $v0, $t4, $t6
    ctx->r2 = ADD32(ctx->r12, ctx->r14);
    // 0x8001B07C: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x8001B080: lh          $a1, 0x2($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X2);
    // 0x8001B084: addiu       $a2, $zero, -0x8000
    ctx->r6 = ADD32(0, -0X8000);
    // 0x8001B088: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8001B08C: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x8001B090: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8001B094: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x8001B098: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001B09C: jal         0x8004C580
    // 0x8001B0A0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_20;
    // 0x8001B0A0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_20:
    // 0x8001B0A4: lh          $t0, 0x50($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X50);
L_8001B0A8:
    // 0x8001B0A8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001B0AC: sll         $t8, $s0, 16
    ctx->r24 = S32(ctx->r16 << 16);
    // 0x8001B0B0: sra         $s0, $t8, 16
    ctx->r16 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8001B0B4: slt         $at, $s0, $s3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8001B0B8: bne         $at, $zero, L_8001B068
    if (ctx->r1 != 0) {
        // 0x8001B0BC: nop
    
            goto L_8001B068;
    }
    // 0x8001B0BC: nop

L_8001B0C0:
    // 0x8001B0C0: lh          $t1, 0x48($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X48);
    // 0x8001B0C4: lh          $t0, 0x50($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X50);
    // 0x8001B0C8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8001B0CC: bne         $t1, $zero, L_8001B1B4
    if (ctx->r9 != 0) {
        // 0x8001B0D0: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_8001B1B4;
    }
    // 0x8001B0D0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001B0D4: lh          $a0, -0x2E4C($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X2E4C);
    // 0x8001B0D8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8001B0DC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8001B0E0: andi        $t2, $a0, 0x100
    ctx->r10 = ctx->r4 & 0X100;
    // 0x8001B0E4: bne         $t2, $zero, L_8001B100
    if (ctx->r10 != 0) {
        // 0x8001B0E8: andi        $t1, $a0, 0x400
        ctx->r9 = ctx->r4 & 0X400;
            goto L_8001B100;
    }
    // 0x8001B0E8: andi        $t1, $a0, 0x400
    ctx->r9 = ctx->r4 & 0X400;
    // 0x8001B0EC: lhu         $v0, -0x2E5A($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2E5A);
    // 0x8001B0F0: andi        $t5, $a0, 0x200
    ctx->r13 = ctx->r4 & 0X200;
    // 0x8001B0F4: andi        $t3, $v0, 0x100
    ctx->r11 = ctx->r2 & 0X100;
    // 0x8001B0F8: beq         $t3, $zero, L_8001B114
    if (ctx->r11 == 0) {
        // 0x8001B0FC: nop
    
            goto L_8001B114;
    }
    // 0x8001B0FC: nop

L_8001B100:
    // 0x8001B100: multu       $t0, $s2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B104: mflo        $t4
    ctx->r12 = lo;
    // 0x8001B108: addu        $t6, $s1, $t4
    ctx->r14 = ADD32(ctx->r17, ctx->r12);
    // 0x8001B10C: b           L_8001B134
    // 0x8001B110: lh          $v1, 0x0($t6)
    ctx->r3 = MEM_H(ctx->r14, 0X0);
        goto L_8001B134;
    // 0x8001B110: lh          $v1, 0x0($t6)
    ctx->r3 = MEM_H(ctx->r14, 0X0);
L_8001B114:
    // 0x8001B114: bne         $t5, $zero, L_8001B124
    if (ctx->r13 != 0) {
        // 0x8001B118: andi        $t7, $v0, 0x200
        ctx->r15 = ctx->r2 & 0X200;
            goto L_8001B124;
    }
    // 0x8001B118: andi        $t7, $v0, 0x200
    ctx->r15 = ctx->r2 & 0X200;
    // 0x8001B11C: beq         $t7, $zero, L_8001B134
    if (ctx->r15 == 0) {
        // 0x8001B120: nop
    
            goto L_8001B134;
    }
    // 0x8001B120: nop

L_8001B124:
    // 0x8001B124: multu       $t0, $s2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B128: mflo        $t8
    ctx->r24 = lo;
    // 0x8001B12C: addu        $t9, $s1, $t8
    ctx->r25 = ADD32(ctx->r17, ctx->r24);
    // 0x8001B130: lh          $v1, 0x2($t9)
    ctx->r3 = MEM_H(ctx->r25, 0X2);
L_8001B134:
    // 0x8001B134: bne         $t1, $zero, L_8001B150
    if (ctx->r9 != 0) {
        // 0x8001B138: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_8001B150;
    }
    // 0x8001B138: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8001B13C: lhu         $v0, -0x2E5A($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2E5A);
    // 0x8001B140: andi        $t6, $a0, 0x800
    ctx->r14 = ctx->r4 & 0X800;
    // 0x8001B144: andi        $t2, $v0, 0x400
    ctx->r10 = ctx->r2 & 0X400;
    // 0x8001B148: beq         $t2, $zero, L_8001B164
    if (ctx->r10 == 0) {
        // 0x8001B14C: nop
    
            goto L_8001B164;
    }
    // 0x8001B14C: nop

L_8001B150:
    // 0x8001B150: multu       $t0, $s2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B154: mflo        $t3
    ctx->r11 = lo;
    // 0x8001B158: addu        $t4, $s1, $t3
    ctx->r12 = ADD32(ctx->r17, ctx->r11);
    // 0x8001B15C: b           L_8001B184
    // 0x8001B160: lh          $v1, 0x4($t4)
    ctx->r3 = MEM_H(ctx->r12, 0X4);
        goto L_8001B184;
    // 0x8001B160: lh          $v1, 0x4($t4)
    ctx->r3 = MEM_H(ctx->r12, 0X4);
L_8001B164:
    // 0x8001B164: bne         $t6, $zero, L_8001B174
    if (ctx->r14 != 0) {
        // 0x8001B168: andi        $t5, $v0, 0x800
        ctx->r13 = ctx->r2 & 0X800;
            goto L_8001B174;
    }
    // 0x8001B168: andi        $t5, $v0, 0x800
    ctx->r13 = ctx->r2 & 0X800;
    // 0x8001B16C: beq         $t5, $zero, L_8001B184
    if (ctx->r13 == 0) {
        // 0x8001B170: nop
    
            goto L_8001B184;
    }
    // 0x8001B170: nop

L_8001B174:
    // 0x8001B174: multu       $t0, $s2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B178: mflo        $t7
    ctx->r15 = lo;
    // 0x8001B17C: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x8001B180: lh          $v1, 0x6($t8)
    ctx->r3 = MEM_H(ctx->r24, 0X6);
L_8001B184:
    // 0x8001B184: beq         $v1, $at, L_8001B1B4
    if (ctx->r3 == ctx->r1) {
        // 0x8001B188: nop
    
            goto L_8001B1B4;
    }
    // 0x8001B188: nop

    // 0x8001B18C: multu       $v1, $s2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B190: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    // 0x8001B194: mflo        $t9
    ctx->r25 = lo;
    // 0x8001B198: addu        $t1, $s1, $t9
    ctx->r9 = ADD32(ctx->r17, ctx->r25);
    // 0x8001B19C: lh          $t2, 0x8($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X8);
    // 0x8001B1A0: beq         $t2, $zero, L_8001B1B4
    if (ctx->r10 == 0) {
        // 0x8001B1A4: nop
    
            goto L_8001B1B4;
    }
    // 0x8001B1A4: nop

    // 0x8001B1A8: jal         0x80044480
    // 0x8001B1AC: sh          $v1, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r3;
    func_80044480(rdram, ctx);
        goto after_21;
    // 0x8001B1AC: sh          $v1, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r3;
    after_21:
    // 0x8001B1B0: lh          $t0, 0x50($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X50);
L_8001B1B4:
    // 0x8001B1B4: beq         $s3, $zero, L_8001B210
    if (ctx->r19 == 0) {
        // 0x8001B1B8: sll         $t3, $t0, 2
        ctx->r11 = S32(ctx->r8 << 2);
            goto L_8001B210;
    }
    // 0x8001B1B8: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x8001B1BC: lui         $t4, 0x8007
    ctx->r12 = S32(0X8007 << 16);
    // 0x8001B1C0: lh          $a2, 0x4C($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X4C);
    // 0x8001B1C4: addiu       $t4, $t4, -0x63D8
    ctx->r12 = ADD32(ctx->r12, -0X63D8);
    // 0x8001B1C8: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x8001B1CC: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x8001B1D0: nor         $a2, $a2, $zero
    ctx->r6 = ~(ctx->r6 | 0);
    // 0x8001B1D4: andi        $t7, $a2, 0x7F
    ctx->r15 = ctx->r6 & 0X7F;
    // 0x8001B1D8: addiu       $t8, $t7, 0x80
    ctx->r24 = ADD32(ctx->r15, 0X80);
    // 0x8001B1DC: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8001B1E0: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8001B1E4: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x8001B1E8: sra         $a2, $t9, 16
    ctx->r6 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8001B1EC: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8001B1F0: lh          $a1, 0x2($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X2);
    // 0x8001B1F4: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x8001B1F8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001B1FC: jal         0x8004C580
    // 0x8001B200: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_22;
    // 0x8001B200: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_22:
    // 0x8001B204: lh          $t2, 0x4C($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X4C);
    // 0x8001B208: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x8001B20C: sh          $t3, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r11;
L_8001B210:
    // 0x8001B210: jal         0x8000798C
    // 0x8001B214: nop

    func_8000798C(rdram, ctx);
        goto after_23;
    // 0x8001B214: nop

    after_23:
    // 0x8001B218: b           L_8001AF8C
    // 0x8001B21C: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
        goto L_8001AF8C;
    // 0x8001B21C: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8001B220: nop

    // 0x8001B224: nop

    // 0x8001B228: nop

    // 0x8001B22C: nop

    // 0x8001B230: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8001B234: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B238: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8001B23C: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8001B240: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8001B244: jr          $ra
    // 0x8001B248: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    TRACE_RETURN()
    return;
    // 0x8001B248: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8001B24C: nop

indirect_8001B250:
    // 0x8001B250: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8001B254: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001B258: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8001B25C: jal         0x80007EC8
    // 0x8001B260: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80007EC8(rdram, ctx);
        goto after_24;
    // 0x8001B260: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_24:
    // 0x8001B264: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8001B268: lh          $t6, -0x6B8E($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X6B8E);
    // 0x8001B26C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8001B270: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001B274: beq         $t6, $zero, L_8001B2B4
    if (ctx->r14 == 0) {
        // 0x8001B278: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8001B2B4;
    }
    // 0x8001B278: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001B27C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001B280: sh          $t7, -0x662C($at)
    MEM_H(-0X662C, ctx->r1) = ctx->r15;
    // 0x8001B284: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001B288: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8001B28C: sw          $t8, -0x6630($at)
    MEM_W(-0X6630, ctx->r1) = ctx->r24;
    // 0x8001B290: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001B294: sh          $zero, -0x6B90($at)
    MEM_H(-0X6B90, ctx->r1) = 0;
    // 0x8001B298: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001B29C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8001B2A0: addiu       $t2, $sp, 0x34
    ctx->r10 = ADD32(ctx->r29, 0X34);
    // 0x8001B2A4: sh          $zero, -0x6B92($at)
    MEM_H(-0X6B92, ctx->r1) = 0;
    // 0x8001B2A8: sh          $t9, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r25;
    // 0x8001B2AC: b           L_8001B4C8
    // 0x8001B2B0: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
        goto L_8001B4C8;
    // 0x8001B2B0: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
L_8001B2B4:
    // 0x8001B2B4: jal         0x8001A37C
    // 0x8001B2B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8001A37C(rdram, ctx);
        goto after_25;
    // 0x8001B2B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_25:
    // 0x8001B2BC: jal         0x8002421C
    // 0x8001B2C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8002421C(rdram, ctx);
        goto after_26;
    // 0x8001B2C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_26:
    // 0x8001B2C4: lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // 0x8001B2C8: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    // 0x8001B2CC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x8001B2D0: addiu       $a0, $a0, 0x79A0
    ctx->r4 = ADD32(ctx->r4, 0X79A0);
    // 0x8001B2D4: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x8001B2D8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8001B2DC: jal         0x80004CE0
    // 0x8001B2E0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    func_80004CE0(rdram, ctx);
        goto after_27;
    // 0x8001B2E0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_27:
    // 0x8001B2E4: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8001B2E8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8001B2EC: bne         $t0, $zero, L_8001B308
    if (ctx->r8 != 0) {
        // 0x8001B2F0: nop
    
            goto L_8001B308;
    }
    // 0x8001B2F0: nop

L_8001B2F4:
    // 0x8001B2F4: jal         0x8000798C
    // 0x8001B2F8: nop

    func_8000798C(rdram, ctx);
        goto after_28;
    // 0x8001B2F8: nop

    after_28:
    // 0x8001B2FC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8001B300: beq         $t0, $zero, L_8001B2F4
    if (ctx->r8 == 0) {
        // 0x8001B304: nop
    
            goto L_8001B2F4;
    }
    // 0x8001B304: nop

L_8001B308:
    // 0x8001B308: jal         0x80004E5C
    // 0x8001B30C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80004E5C(rdram, ctx);
        goto after_29;
    // 0x8001B30C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_29:
    // 0x8001B310: jal         0x8000798C
    // 0x8001B314: nop

    func_8000798C(rdram, ctx);
        goto after_30;
    // 0x8001B314: nop

    after_30:
    // 0x8001B318: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8001B31C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001B320: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001B324: addiu       $v1, $v1, -0x6B7A
    ctx->r3 = ADD32(ctx->r3, -0X6B7A);
    // 0x8001B328: addiu       $v0, $v0, -0x6B82
    ctx->r2 = ADD32(ctx->r2, -0X6B82);
    // 0x8001B32C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8001B330: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x8001B334: beq         $t0, $t1, L_8001B364
    if (ctx->r8 == ctx->r9) {
        // 0x8001B338: sh          $zero, 0x0($v1)
        MEM_H(0X0, ctx->r3) = 0;
            goto L_8001B364;
    }
    // 0x8001B338: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x8001B33C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001B340: beq         $t0, $at, L_8001B444
    if (ctx->r8 == ctx->r1) {
        // 0x8001B344: addiu       $t8, $zero, 0x7
        ctx->r24 = ADD32(0, 0X7);
            goto L_8001B444;
    }
    // 0x8001B344: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x8001B348: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001B34C: beq         $t0, $at, L_8001B468
    if (ctx->r8 == ctx->r1) {
        // 0x8001B350: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8001B468;
    }
    // 0x8001B350: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8001B354: beq         $t0, $at, L_8001B4AC
    if (ctx->r8 == ctx->r1) {
        // 0x8001B358: sw          $t0, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r8;
            goto L_8001B4AC;
    }
    // 0x8001B358: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8001B35C: b           L_8001B4C8
    // 0x8001B360: nop

        goto L_8001B4C8;
    // 0x8001B360: nop

L_8001B364:
    // 0x8001B364: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x8001B368: lh          $t4, -0x6B8A($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X6B8A);
    // 0x8001B36C: lui         $t3, 0x1
    ctx->r11 = S32(0X1 << 16);
    // 0x8001B370: ori         $t3, $t3, 0x86A0
    ctx->r11 = ctx->r11 | 0X86A0;
    // 0x8001B374: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001B378: sh          $zero, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = 0;
    // 0x8001B37C: beq         $t4, $zero, L_8001B430
    if (ctx->r12 == 0) {
        // 0x8001B380: sw          $t3, -0x6BD4($at)
        MEM_W(-0X6BD4, ctx->r1) = ctx->r11;
            goto L_8001B430;
    }
    // 0x8001B380: sw          $t3, -0x6BD4($at)
    MEM_W(-0X6BD4, ctx->r1) = ctx->r11;
    // 0x8001B384: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8001B388: lui         $a0, 0x8002
    ctx->r4 = S32(0X8002 << 16);
    // 0x8001B38C: addiu       $a0, $a0, -0x52C8
    ctx->r4 = ADD32(ctx->r4, -0X52C8);
    // 0x8001B390: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8001B394: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x8001B398: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8001B39C: jal         0x80004CE0
    // 0x8001B3A0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    func_80004CE0(rdram, ctx);
        goto after_31;
    // 0x8001B3A0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_31:
    // 0x8001B3A4: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8001B3A8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8001B3AC: beq         $t0, $zero, L_8001B3C8
    if (ctx->r8 == 0) {
        // 0x8001B3B0: nop
    
            goto L_8001B3C8;
    }
    // 0x8001B3B0: nop

L_8001B3B4:
    // 0x8001B3B4: jal         0x8000798C
    // 0x8001B3B8: nop

    func_8000798C(rdram, ctx);
        goto after_32;
    // 0x8001B3B8: nop

    after_32:
    // 0x8001B3BC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8001B3C0: bne         $t0, $zero, L_8001B3B4
    if (ctx->r8 != 0) {
        // 0x8001B3C4: nop
    
            goto L_8001B3B4;
    }
    // 0x8001B3C4: nop

L_8001B3C8:
    // 0x8001B3C8: jal         0x80004E5C
    // 0x8001B3CC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80004E5C(rdram, ctx);
        goto after_33;
    // 0x8001B3CC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_33:
    // 0x8001B3D0: jal         0x8000798C
    // 0x8001B3D4: nop

    func_8000798C(rdram, ctx);
        goto after_34;
    // 0x8001B3D4: nop

    after_34:
    // 0x8001B3D8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001B3DC: jal         0x80035D38
    // 0x8001B3E0: lh          $a0, -0x662E($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X662E);
    func_80035D38(rdram, ctx);
        goto after_35;
    // 0x8001B3E0: lh          $a0, -0x662E($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X662E);
    after_35:
    // 0x8001B3E4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001B3E8: sh          $v0, -0x662C($at)
    MEM_H(-0X662C, ctx->r1) = ctx->r2;
    // 0x8001B3EC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001B3F0: lh          $v1, -0x662C($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X662C);
    // 0x8001B3F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001B3F8: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8001B3FC: beq         $v1, $at, L_8001B40C
    if (ctx->r3 == ctx->r1) {
        // 0x8001B400: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8001B40C;
    }
    // 0x8001B400: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001B404: bne         $v1, $at, L_8001B428
    if (ctx->r3 != ctx->r1) {
        // 0x8001B408: nop
    
            goto L_8001B428;
    }
    // 0x8001B408: nop

L_8001B40C:
    // 0x8001B40C: lhu         $t5, -0x2E5C($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X2E5C);
    // 0x8001B410: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x8001B414: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001B418: andi        $t6, $t5, 0x2000
    ctx->r14 = ctx->r13 & 0X2000;
    // 0x8001B41C: beq         $t6, $zero, L_8001B428
    if (ctx->r14 == 0) {
        // 0x8001B420: nop
    
            goto L_8001B428;
    }
    // 0x8001B420: nop

    // 0x8001B424: sh          $t7, -0x662C($at)
    MEM_H(-0X662C, ctx->r1) = ctx->r15;
L_8001B428:
    // 0x8001B428: b           L_8001B4C8
    // 0x8001B42C: nop

        goto L_8001B4C8;
    // 0x8001B42C: nop

L_8001B430:
    // 0x8001B430: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001B434: sw          $t1, -0x6630($at)
    MEM_W(-0X6630, ctx->r1) = ctx->r9;
    // 0x8001B438: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001B43C: b           L_8001B4C8
    // 0x8001B440: sh          $t1, -0x662C($at)
    MEM_H(-0X662C, ctx->r1) = ctx->r9;
        goto L_8001B4C8;
    // 0x8001B440: sh          $t1, -0x662C($at)
    MEM_H(-0X662C, ctx->r1) = ctx->r9;
L_8001B444:
    // 0x8001B444: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001B448: sw          $t8, -0x6630($at)
    MEM_W(-0X6630, ctx->r1) = ctx->r24;
    // 0x8001B44C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001B450: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x8001B454: sh          $t9, -0x662C($at)
    MEM_H(-0X662C, ctx->r1) = ctx->r25;
    // 0x8001B458: sh          $t1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r9;
    // 0x8001B45C: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
    // 0x8001B460: b           L_8001B4C8
    // 0x8001B464: sh          $t1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r9;
        goto L_8001B4C8;
    // 0x8001B464: sh          $t1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r9;
L_8001B468:
    // 0x8001B468: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x8001B46C: lh          $t2, -0x6B90($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X6B90);
    // 0x8001B470: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8001B474: sh          $zero, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = 0;
    // 0x8001B478: bne         $t2, $zero, L_8001B488
    if (ctx->r10 != 0) {
        // 0x8001B47C: lui         $t3, 0x8013
        ctx->r11 = S32(0X8013 << 16);
            goto L_8001B488;
    }
    // 0x8001B47C: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x8001B480: b           L_8001B48C
    // 0x8001B484: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_8001B48C;
    // 0x8001B484: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_8001B488:
    // 0x8001B488: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_8001B48C:
    // 0x8001B48C: lh          $t3, -0x662C($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X662C);
    // 0x8001B490: slt         $at, $t3, $v0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001B494: beq         $at, $zero, L_8001B524
    if (ctx->r1 == 0) {
        // 0x8001B498: nop
    
            goto L_8001B524;
    }
    // 0x8001B498: nop

    // 0x8001B49C: jal         0x80035A04
    // 0x8001B4A0: nop

    func_80035A04(rdram, ctx);
        goto after_36;
    // 0x8001B4A0: nop

    after_36:
    // 0x8001B4A4: b           L_8001B524
    // 0x8001B4A8: nop

        goto L_8001B524;
    // 0x8001B4A8: nop

L_8001B4AC:
    // 0x8001B4AC: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
    // 0x8001B4B0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001B4B4: sh          $t1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r9;
    // 0x8001B4B8: jal         0x80035D38
    // 0x8001B4BC: lh          $a0, -0x662E($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X662E);
    func_80035D38(rdram, ctx);
        goto after_37;
    // 0x8001B4BC: lh          $a0, -0x662E($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X662E);
    after_37:
    // 0x8001B4C0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001B4C4: sh          $v0, -0x662C($at)
    MEM_H(-0X662C, ctx->r1) = ctx->r2;
L_8001B4C8:
    // 0x8001B4C8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001B4CC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8001B4D0: lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // 0x8001B4D4: sw          $zero, -0x6BE0($at)
    MEM_W(-0X6BE0, ctx->r1) = 0;
    // 0x8001B4D8: addiu       $a0, $a0, 0x2BC8
    ctx->r4 = ADD32(ctx->r4, 0X2BC8);
    // 0x8001B4DC: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8001B4E0: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x8001B4E4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8001B4E8: jal         0x80004CE0
    // 0x8001B4EC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    func_80004CE0(rdram, ctx);
        goto after_38;
    // 0x8001B4EC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_38:
    // 0x8001B4F0: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8001B4F4: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8001B4F8: beq         $t0, $zero, L_8001B514
    if (ctx->r8 == 0) {
        // 0x8001B4FC: nop
    
            goto L_8001B514;
    }
    // 0x8001B4FC: nop

L_8001B500:
    // 0x8001B500: jal         0x8000798C
    // 0x8001B504: nop

    func_8000798C(rdram, ctx);
        goto after_39;
    // 0x8001B504: nop

    after_39:
    // 0x8001B508: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8001B50C: bne         $t0, $zero, L_8001B500
    if (ctx->r8 != 0) {
        // 0x8001B510: nop
    
            goto L_8001B500;
    }
    // 0x8001B510: nop

L_8001B514:
    // 0x8001B514: jal         0x80004E5C
    // 0x8001B518: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80004E5C(rdram, ctx);
        goto after_40;
    // 0x8001B518: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_40:
    // 0x8001B51C: jal         0x8000798C
    // 0x8001B520: nop

    func_8000798C(rdram, ctx);
        goto after_41;
    // 0x8001B520: nop

    after_41:
L_8001B524:
    // 0x8001B524: jal         0x80013A94
    // 0x8001B528: nop

    func_80013A94(rdram, ctx);
        goto after_42;
    // 0x8001B528: nop

    after_42:
    // 0x8001B52C: jal         0x80007E20
    // 0x8001B530: nop

    func_80007E20(rdram, ctx);
        goto after_43;
    // 0x8001B530: nop

    after_43:
    // 0x8001B534: lh          $t4, 0x2E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2E);
    // 0x8001B538: beq         $t4, $zero, L_8001B54C
    if (ctx->r12 == 0) {
        // 0x8001B53C: lui         $t5, 0xF
        ctx->r13 = S32(0XF << 16);
            goto L_8001B54C;
    }
    // 0x8001B53C: lui         $t5, 0xF
    ctx->r13 = S32(0XF << 16);
    // 0x8001B540: ori         $t5, $t5, 0x4240
    ctx->r13 = ctx->r13 | 0X4240;
    // 0x8001B544: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001B548: sw          $t5, -0x6BD4($at)
    MEM_W(-0X6BD4, ctx->r1) = ctx->r13;
L_8001B54C:
    // 0x8001B54C: jal         0x8000E35C
    // 0x8001B550: nop

    func_8000E35C(rdram, ctx);
        goto after_44;
    // 0x8001B550: nop

    after_44:
    // 0x8001B554: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001B558: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x8001B55C: mfhi        $t6
    ctx->r14 = hi;
    // 0x8001B560: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8001B564: lui         $t8, 0x8007
    ctx->r24 = S32(0X8007 << 16);
    // 0x8001B568: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8001B56C: lh          $t8, -0x63C0($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X63C0);
    // 0x8001B570: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001B574: jal         0x8000E35C
    // 0x8001B578: sh          $t8, -0x6B78($at)
    MEM_H(-0X6B78, ctx->r1) = ctx->r24;
    func_8000E35C(rdram, ctx);
        goto after_45;
    // 0x8001B578: sh          $t8, -0x6B78($at)
    MEM_H(-0X6B78, ctx->r1) = ctx->r24;
    after_45:
    // 0x8001B57C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001B580: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x8001B584: mfhi        $t9
    ctx->r25 = hi;
    // 0x8001B588: sll         $t2, $t9, 1
    ctx->r10 = S32(ctx->r25 << 1);
    // 0x8001B58C: lui         $t3, 0x8007
    ctx->r11 = S32(0X8007 << 16);
    // 0x8001B590: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8001B594: lh          $t3, -0x63BA($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X63BA);
    // 0x8001B598: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001B59C: jal         0x8000E35C
    // 0x8001B5A0: sh          $t3, -0x6B76($at)
    MEM_H(-0X6B76, ctx->r1) = ctx->r11;
    func_8000E35C(rdram, ctx);
        goto after_46;
    // 0x8001B5A0: sh          $t3, -0x6B76($at)
    MEM_H(-0X6B76, ctx->r1) = ctx->r11;
    after_46:
    // 0x8001B5A4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001B5A8: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x8001B5AC: mfhi        $t4
    ctx->r12 = hi;
    // 0x8001B5B0: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x8001B5B4: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8001B5B8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001B5BC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8001B5C0: lui         $t8, 0x8007
    ctx->r24 = S32(0X8007 << 16);
    // 0x8001B5C4: addiu       $t8, $t8, -0x63B4
    ctx->r24 = ADD32(ctx->r24, -0X63B4);
    // 0x8001B5C8: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8001B5CC: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8001B5D0: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x8001B5D4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001B5D8: sh          $t9, -0x6B74($at)
    MEM_H(-0X6B74, ctx->r1) = ctx->r25;
    // 0x8001B5DC: lh          $t2, 0x2($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X2);
    // 0x8001B5E0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001B5E4: sh          $t2, -0x6B72($at)
    MEM_H(-0X6B72, ctx->r1) = ctx->r10;
    // 0x8001B5E8: lh          $t3, 0x4($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X4);
    // 0x8001B5EC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001B5F0: jal         0x8004F590
    // 0x8001B5F4: sh          $t3, -0x6B70($at)
    MEM_H(-0X6B70, ctx->r1) = ctx->r11;
    func_8004F590(rdram, ctx);
        goto after_47;
    // 0x8001B5F4: sh          $t3, -0x6B70($at)
    MEM_H(-0X6B70, ctx->r1) = ctx->r11;
    after_47:
    // 0x8001B5F8: lh          $t4, 0x2E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2E);
L_8001B5FC:
    // 0x8001B5FC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001B600: sw          $zero, -0x6BE0($at)
    MEM_W(-0X6BE0, ctx->r1) = 0;
    // 0x8001B604: beq         $t4, $zero, L_8001B618
    if (ctx->r12 == 0) {
        // 0x8001B608: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_8001B618;
    }
    // 0x8001B608: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8001B60C: addiu       $t5, $zero, 0x200
    ctx->r13 = ADD32(0, 0X200);
    // 0x8001B610: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001B614: sw          $t5, -0x6BE0($at)
    MEM_W(-0X6BE0, ctx->r1) = ctx->r13;
L_8001B618:
    // 0x8001B618: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8001B61C: lh          $t7, -0x6B8E($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X6B8E);
    // 0x8001B620: lw          $t6, -0x6BD4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6BD4);
    // 0x8001B624: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001B628: beq         $t7, $zero, L_8001B6B8
    if (ctx->r15 == 0) {
        // 0x8001B62C: sw          $t6, -0x6BD0($at)
        MEM_W(-0X6BD0, ctx->r1) = ctx->r14;
            goto L_8001B6B8;
    }
    // 0x8001B62C: sw          $t6, -0x6BD0($at)
    MEM_W(-0X6BD0, ctx->r1) = ctx->r14;
    // 0x8001B630: lui         $t8, 0x8002
    ctx->r24 = S32(0X8002 << 16);
    // 0x8001B634: addiu       $t8, $t8, -0x5570
    ctx->r24 = ADD32(ctx->r24, -0X5570);
    // 0x8001B638: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8001B63C: jal         0x80007EC8
    // 0x8001B640: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_80007EC8(rdram, ctx);
        goto after_48;
    // 0x8001B640: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_48:
    // 0x8001B644: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8001B648: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8001B64C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B650: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x8001B654: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8001B658: jal         0x80004CE0
    // 0x8001B65C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    func_80004CE0(rdram, ctx);
        goto after_49;
    // 0x8001B65C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_49:
    // 0x8001B660: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8001B664: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8001B668: beq         $t0, $zero, L_8001B684
    if (ctx->r8 == 0) {
        // 0x8001B66C: nop
    
            goto L_8001B684;
    }
    // 0x8001B66C: nop

L_8001B670:
    // 0x8001B670: jal         0x8000798C
    // 0x8001B674: nop

    func_8000798C(rdram, ctx);
        goto after_50;
    // 0x8001B674: nop

    after_50:
    // 0x8001B678: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8001B67C: bne         $t0, $zero, L_8001B670
    if (ctx->r8 != 0) {
        // 0x8001B680: nop
    
            goto L_8001B670;
    }
    // 0x8001B680: nop

L_8001B684:
    // 0x8001B684: lui         $t9, 0x8002
    ctx->r25 = S32(0X8002 << 16);
    // 0x8001B688: addiu       $t9, $t9, -0x423C
    ctx->r25 = ADD32(ctx->r25, -0X423C);
    // 0x8001B68C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8001B690: jal         0x80004E5C
    // 0x8001B694: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80004E5C(rdram, ctx);
        goto after_51;
    // 0x8001B694: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_51:
    // 0x8001B698: jal         0x8000798C
    // 0x8001B69C: nop

    func_8000798C(rdram, ctx);
        goto after_52;
    // 0x8001B69C: nop

    after_52:
    // 0x8001B6A0: jal         0x80007E20
    // 0x8001B6A4: nop

    func_80007E20(rdram, ctx);
        goto after_53;
    // 0x8001B6A4: nop

    after_53:
    // 0x8001B6A8: jal         0x8000798C
    // 0x8001B6AC: nop

    func_8000798C(rdram, ctx);
        goto after_54;
    // 0x8001B6AC: nop

    after_54:
    // 0x8001B6B0: b           L_8001B828
    // 0x8001B6B4: nop

        goto L_8001B828;
    // 0x8001B6B4: nop

L_8001B6B8:
    // 0x8001B6B8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001B6BC: lh          $v0, -0x6B88($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X6B88);
    // 0x8001B6C0: lh          $t2, 0x2E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X2E);
    // 0x8001B6C4: bne         $v0, $zero, L_8001B74C
    if (ctx->r2 != 0) {
        // 0x8001B6C8: nop
    
            goto L_8001B74C;
    }
    // 0x8001B6C8: nop

    // 0x8001B6CC: bne         $t2, $zero, L_8001B74C
    if (ctx->r10 != 0) {
        // 0x8001B6D0: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8001B74C;
    }
    // 0x8001B6D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8001B6D4: lui         $t3, 0x8001
    ctx->r11 = S32(0X8001 << 16);
    // 0x8001B6D8: addiu       $t3, $t3, 0x5E90
    ctx->r11 = ADD32(ctx->r11, 0X5E90);
    // 0x8001B6DC: jal         0x80007EC8
    // 0x8001B6E0: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    func_80007EC8(rdram, ctx);
        goto after_55;
    // 0x8001B6E0: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    after_55:
    // 0x8001B6E4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8001B6E8: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8001B6EC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B6F0: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x8001B6F4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8001B6F8: jal         0x80004CE0
    // 0x8001B6FC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    func_80004CE0(rdram, ctx);
        goto after_56;
    // 0x8001B6FC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_56:
    // 0x8001B700: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8001B704: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8001B708: beq         $t0, $zero, L_8001B724
    if (ctx->r8 == 0) {
        // 0x8001B70C: nop
    
            goto L_8001B724;
    }
    // 0x8001B70C: nop

L_8001B710:
    // 0x8001B710: jal         0x8000798C
    // 0x8001B714: nop

    func_8000798C(rdram, ctx);
        goto after_57;
    // 0x8001B714: nop

    after_57:
    // 0x8001B718: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8001B71C: bne         $t0, $zero, L_8001B710
    if (ctx->r8 != 0) {
        // 0x8001B720: nop
    
            goto L_8001B710;
    }
    // 0x8001B720: nop

L_8001B724:
    // 0x8001B724: jal         0x80004E5C
    // 0x8001B728: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80004E5C(rdram, ctx);
        goto after_58;
    // 0x8001B728: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_58:
    // 0x8001B72C: jal         0x8000798C
    // 0x8001B730: nop

    func_8000798C(rdram, ctx);
        goto after_59;
    // 0x8001B730: nop

    after_59:
    // 0x8001B734: jal         0x80007E20
    // 0x8001B738: nop

    func_80007E20(rdram, ctx);
        goto after_60;
    // 0x8001B738: nop

    after_60:
    // 0x8001B73C: jal         0x8000798C
    // 0x8001B740: nop

    func_8000798C(rdram, ctx);
        goto after_61;
    // 0x8001B740: nop

    after_61:
    // 0x8001B744: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001B748: lh          $v0, -0x6B88($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X6B88);
L_8001B74C:
    // 0x8001B74C: bne         $v0, $zero, L_8001B7B8
    if (ctx->r2 != 0) {
        // 0x8001B750: nop
    
            goto L_8001B7B8;
    }
    // 0x8001B750: nop

    // 0x8001B754: jal         0x80007EC8
    // 0x8001B758: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_80007EC8(rdram, ctx);
        goto after_62;
    // 0x8001B758: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_62:
    // 0x8001B75C: lh          $t4, 0x2E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2E);
    // 0x8001B760: lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // 0x8001B764: addiu       $a0, $a0, 0x6674
    ctx->r4 = ADD32(ctx->r4, 0X6674);
    // 0x8001B768: bne         $t4, $zero, L_8001B7B8
    if (ctx->r12 != 0) {
        // 0x8001B76C: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_8001B7B8;
    }
    // 0x8001B76C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8001B770: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x8001B774: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8001B778: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8001B77C: jal         0x80004CE0
    // 0x8001B780: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    func_80004CE0(rdram, ctx);
        goto after_63;
    // 0x8001B780: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    after_63:
    // 0x8001B784: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8001B788: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8001B78C: beq         $t0, $zero, L_8001B7A8
    if (ctx->r8 == 0) {
        // 0x8001B790: nop
    
            goto L_8001B7A8;
    }
    // 0x8001B790: nop

L_8001B794:
    // 0x8001B794: jal         0x8000798C
    // 0x8001B798: nop

    func_8000798C(rdram, ctx);
        goto after_64;
    // 0x8001B798: nop

    after_64:
    // 0x8001B79C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8001B7A0: bne         $t0, $zero, L_8001B794
    if (ctx->r8 != 0) {
        // 0x8001B7A4: nop
    
            goto L_8001B794;
    }
    // 0x8001B7A4: nop

L_8001B7A8:
    // 0x8001B7A8: jal         0x80004E5C
    // 0x8001B7AC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80004E5C(rdram, ctx);
        goto after_65;
    // 0x8001B7AC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_65:
    // 0x8001B7B0: jal         0x8000798C
    // 0x8001B7B4: nop

    func_8000798C(rdram, ctx);
        goto after_66;
    // 0x8001B7B4: nop

    after_66:
L_8001B7B8:
    // 0x8001B7B8: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x8001B7BC: lh          $t5, -0x6B88($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X6B88);
    // 0x8001B7C0: lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // 0x8001B7C4: addiu       $a0, $a0, 0x3D4C
    ctx->r4 = ADD32(ctx->r4, 0X3D4C);
    // 0x8001B7C8: bne         $t5, $zero, L_8001B818
    if (ctx->r13 != 0) {
        // 0x8001B7CC: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_8001B818;
    }
    // 0x8001B7CC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8001B7D0: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x8001B7D4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8001B7D8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8001B7DC: jal         0x80004CE0
    // 0x8001B7E0: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    func_80004CE0(rdram, ctx);
        goto after_67;
    // 0x8001B7E0: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    after_67:
    // 0x8001B7E4: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8001B7E8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8001B7EC: beq         $t0, $zero, L_8001B808
    if (ctx->r8 == 0) {
        // 0x8001B7F0: nop
    
            goto L_8001B808;
    }
    // 0x8001B7F0: nop

L_8001B7F4:
    // 0x8001B7F4: jal         0x8000798C
    // 0x8001B7F8: nop

    func_8000798C(rdram, ctx);
        goto after_68;
    // 0x8001B7F8: nop

    after_68:
    // 0x8001B7FC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8001B800: bne         $t0, $zero, L_8001B7F4
    if (ctx->r8 != 0) {
        // 0x8001B804: nop
    
            goto L_8001B7F4;
    }
    // 0x8001B804: nop

L_8001B808:
    // 0x8001B808: jal         0x80004E5C
    // 0x8001B80C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80004E5C(rdram, ctx);
        goto after_69;
    // 0x8001B80C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_69:
    // 0x8001B810: jal         0x8000798C
    // 0x8001B814: nop

    func_8000798C(rdram, ctx);
        goto after_70;
    // 0x8001B814: nop

    after_70:
L_8001B818:
    // 0x8001B818: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x8001B81C: addiu       $t6, $t6, -0x423C
    ctx->r14 = ADD32(ctx->r14, -0X423C);
    // 0x8001B820: jal         0x80007E20
    // 0x8001B824: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_80007E20(rdram, ctx);
        goto after_71;
    // 0x8001B824: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_71:
L_8001B828:
    // 0x8001B828: jal         0x8000798C
    // 0x8001B82C: nop

    func_8000798C(rdram, ctx);
        goto after_72;
    // 0x8001B82C: nop

    after_72:
    // 0x8001B830: jal         0x8000798C
    // 0x8001B834: nop

    func_8000798C(rdram, ctx);
        goto after_73;
    // 0x8001B834: nop

    after_73:
    // 0x8001B838: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8001B83C: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8001B840: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B844: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x8001B848: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8001B84C: jal         0x80004CE0
    // 0x8001B850: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    func_80004CE0(rdram, ctx);
        goto after_74;
    // 0x8001B850: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_74:
    // 0x8001B854: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8001B858: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8001B85C: beq         $t0, $zero, L_8001B878
    if (ctx->r8 == 0) {
        // 0x8001B860: nop
    
            goto L_8001B878;
    }
    // 0x8001B860: nop

L_8001B864:
    // 0x8001B864: jal         0x8000798C
    // 0x8001B868: nop

    func_8000798C(rdram, ctx);
        goto after_75;
    // 0x8001B868: nop

    after_75:
    // 0x8001B86C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8001B870: bne         $t0, $zero, L_8001B864
    if (ctx->r8 != 0) {
        // 0x8001B874: nop
    
            goto L_8001B864;
    }
    // 0x8001B874: nop

L_8001B878:
    // 0x8001B878: jal         0x80004E5C
    // 0x8001B87C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80004E5C(rdram, ctx);
        goto after_76;
    // 0x8001B87C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_76:
    // 0x8001B880: jal         0x8000798C
    // 0x8001B884: nop

    func_8000798C(rdram, ctx);
        goto after_77;
    // 0x8001B884: nop

    after_77:
    // 0x8001B888: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8001B88C: lh          $t7, -0x6B8E($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X6B8E);
    // 0x8001B890: lh          $t8, 0x2E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X2E);
    // 0x8001B894: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001B898: beq         $t7, $zero, L_8001B8A8
    if (ctx->r15 == 0) {
        // 0x8001B89C: lui         $a0, 0x8001
        ctx->r4 = S32(0X8001 << 16);
            goto L_8001B8A8;
    }
    // 0x8001B89C: lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // 0x8001B8A0: b           L_8001BB98
    // 0x8001B8A4: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
        goto L_8001BB98;
    // 0x8001B8A4: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
L_8001B8A8:
    // 0x8001B8A8: bne         $t8, $zero, L_8001BB1C
    if (ctx->r24 != 0) {
        // 0x8001B8AC: addiu       $a0, $a0, 0x7290
        ctx->r4 = ADD32(ctx->r4, 0X7290);
            goto L_8001BB1C;
    }
    // 0x8001B8AC: addiu       $a0, $a0, 0x7290
    ctx->r4 = ADD32(ctx->r4, 0X7290);
    // 0x8001B8B0: lw          $v0, -0x6BE0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6BE0);
    // 0x8001B8B4: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x8001B8B8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8001B8BC: andi        $t9, $v0, 0x80
    ctx->r25 = ctx->r2 & 0X80;
    // 0x8001B8C0: beq         $t9, $zero, L_8001BAA8
    if (ctx->r25 == 0) {
        // 0x8001B8C4: andi        $t2, $v0, 0x100
        ctx->r10 = ctx->r2 & 0X100;
            goto L_8001BAA8;
    }
    // 0x8001B8C4: andi        $t2, $v0, 0x100
    ctx->r10 = ctx->r2 & 0X100;
    // 0x8001B8C8: bne         $t2, $zero, L_8001BAA8
    if (ctx->r10 != 0) {
        // 0x8001B8CC: lui         $t3, 0x8001
        ctx->r11 = S32(0X8001 << 16);
            goto L_8001BAA8;
    }
    // 0x8001B8CC: lui         $t3, 0x8001
    ctx->r11 = S32(0X8001 << 16);
    // 0x8001B8D0: addiu       $t3, $t3, 0x5144
    ctx->r11 = ADD32(ctx->r11, 0X5144);
    // 0x8001B8D4: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x8001B8D8: jal         0x80007EC8
    // 0x8001B8DC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_80007EC8(rdram, ctx);
        goto after_78;
    // 0x8001B8DC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_78:
    // 0x8001B8E0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8001B8E4: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8001B8E8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B8EC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x8001B8F0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8001B8F4: jal         0x80004CE0
    // 0x8001B8F8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    func_80004CE0(rdram, ctx);
        goto after_79;
    // 0x8001B8F8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_79:
    // 0x8001B8FC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8001B900: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8001B904: beq         $t0, $zero, L_8001B920
    if (ctx->r8 == 0) {
        // 0x8001B908: nop
    
            goto L_8001B920;
    }
    // 0x8001B908: nop

L_8001B90C:
    // 0x8001B90C: jal         0x8000798C
    // 0x8001B910: nop

    func_8000798C(rdram, ctx);
        goto after_80;
    // 0x8001B910: nop

    after_80:
    // 0x8001B914: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8001B918: bne         $t0, $zero, L_8001B90C
    if (ctx->r8 != 0) {
        // 0x8001B91C: nop
    
            goto L_8001B90C;
    }
    // 0x8001B91C: nop

L_8001B920:
    // 0x8001B920: jal         0x80004E5C
    // 0x8001B924: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80004E5C(rdram, ctx);
        goto after_81;
    // 0x8001B924: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_81:
    // 0x8001B928: jal         0x8000798C
    // 0x8001B92C: nop

    func_8000798C(rdram, ctx);
        goto after_82;
    // 0x8001B92C: nop

    after_82:
    // 0x8001B930: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x8001B934: lh          $t4, -0x6B90($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X6B90);
    // 0x8001B938: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x8001B93C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8001B940: bne         $t4, $zero, L_8001B950
    if (ctx->r12 != 0) {
        // 0x8001B944: lui         $a0, 0x8002
        ctx->r4 = S32(0X8002 << 16);
            goto L_8001B950;
    }
    // 0x8001B944: lui         $a0, 0x8002
    ctx->r4 = S32(0X8002 << 16);
    // 0x8001B948: b           L_8001B954
    // 0x8001B94C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_8001B954;
    // 0x8001B94C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_8001B950:
    // 0x8001B950: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_8001B954:
    // 0x8001B954: lh          $t5, -0x662C($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X662C);
    // 0x8001B958: addiu       $a0, $a0, -0x6AFC
    ctx->r4 = ADD32(ctx->r4, -0X6AFC);
    // 0x8001B95C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x8001B960: bne         $v0, $t5, L_8001BA18
    if (ctx->r2 != ctx->r13) {
        // 0x8001B964: addiu       $a2, $zero, 0x8
        ctx->r6 = ADD32(0, 0X8);
            goto L_8001BA18;
    }
    // 0x8001B964: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8001B968: jal         0x80007E20
    // 0x8001B96C: nop

    func_80007E20(rdram, ctx);
        goto after_83;
    // 0x8001B96C: nop

    after_83:
    // 0x8001B970: jal         0x8000798C
    // 0x8001B974: nop

    func_8000798C(rdram, ctx);
        goto after_84;
    // 0x8001B974: nop

    after_84:
    // 0x8001B978: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001B97C: addiu       $v0, $v0, -0x6BE0
    ctx->r2 = ADD32(ctx->r2, -0X6BE0);
    // 0x8001B980: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8001B984: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x8001B988: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8001B98C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8001B990: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x8001B994: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x8001B998: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x8001B99C: and         $t3, $t9, $at
    ctx->r11 = ctx->r25 & ctx->r1;
    // 0x8001B9A0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8001B9A4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001B9A8: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x8001B9AC: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8001B9B0: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x8001B9B4: lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // 0x8001B9B8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8001B9BC: addiu       $a0, $a0, 0x7130
    ctx->r4 = ADD32(ctx->r4, 0X7130);
    // 0x8001B9C0: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8001B9C4: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x8001B9C8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8001B9CC: jal         0x80004CE0
    // 0x8001B9D0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    func_80004CE0(rdram, ctx);
        goto after_85;
    // 0x8001B9D0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_85:
    // 0x8001B9D4: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8001B9D8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8001B9DC: beq         $t0, $zero, L_8001B9F8
    if (ctx->r8 == 0) {
        // 0x8001B9E0: nop
    
            goto L_8001B9F8;
    }
    // 0x8001B9E0: nop

L_8001B9E4:
    // 0x8001B9E4: jal         0x8000798C
    // 0x8001B9E8: nop

    func_8000798C(rdram, ctx);
        goto after_86;
    // 0x8001B9E8: nop

    after_86:
    // 0x8001B9EC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8001B9F0: bne         $t0, $zero, L_8001B9E4
    if (ctx->r8 != 0) {
        // 0x8001B9F4: nop
    
            goto L_8001B9E4;
    }
    // 0x8001B9F4: nop

L_8001B9F8:
    // 0x8001B9F8: jal         0x80004E5C
    // 0x8001B9FC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80004E5C(rdram, ctx);
        goto after_87;
    // 0x8001B9FC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_87:
    // 0x8001BA00: jal         0x8000798C
    // 0x8001BA04: nop

    func_8000798C(rdram, ctx);
        goto after_88;
    // 0x8001BA04: nop

    after_88:
    // 0x8001BA08: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8001BA0C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001BA10: b           L_8001BB1C
    // 0x8001BA14: sw          $t6, -0x6BE0($at)
    MEM_W(-0X6BE0, ctx->r1) = ctx->r14;
        goto L_8001BB1C;
    // 0x8001BA14: sw          $t6, -0x6BE0($at)
    MEM_W(-0X6BE0, ctx->r1) = ctx->r14;
L_8001BA18:
    // 0x8001BA18: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8001BA1C: jal         0x80004CE0
    // 0x8001BA20: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    func_80004CE0(rdram, ctx);
        goto after_89;
    // 0x8001BA20: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    after_89:
    // 0x8001BA24: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8001BA28: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001BA2C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8001BA30: bne         $t0, $at, L_8001BA50
    if (ctx->r8 != ctx->r1) {
        // 0x8001BA34: nop
    
            goto L_8001BA50;
    }
    // 0x8001BA34: nop

L_8001BA38:
    // 0x8001BA38: jal         0x8000798C
    // 0x8001BA3C: nop

    func_8000798C(rdram, ctx);
        goto after_90;
    // 0x8001BA3C: nop

    after_90:
    // 0x8001BA40: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8001BA44: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001BA48: beq         $t0, $at, L_8001BA38
    if (ctx->r8 == ctx->r1) {
        // 0x8001BA4C: nop
    
            goto L_8001BA38;
    }
    // 0x8001BA4C: nop

L_8001BA50:
    // 0x8001BA50: jal         0x80004E5C
    // 0x8001BA54: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80004E5C(rdram, ctx);
        goto after_91;
    // 0x8001BA54: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_91:
    // 0x8001BA58: jal         0x8000798C
    // 0x8001BA5C: nop

    func_8000798C(rdram, ctx);
        goto after_92;
    // 0x8001BA5C: nop

    after_92:
    // 0x8001BA60: jal         0x80007E20
    // 0x8001BA64: nop

    func_80007E20(rdram, ctx);
        goto after_93;
    // 0x8001BA64: nop

    after_93:
    // 0x8001BA68: jal         0x8000798C
    // 0x8001BA6C: nop

    func_8000798C(rdram, ctx);
        goto after_94;
    // 0x8001BA6C: nop

    after_94:
    // 0x8001BA70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001BA74:
    // 0x8001BA74: jal         0x8000798C
    // 0x8001BA78: sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
    func_8000798C(rdram, ctx);
        goto after_95;
    // 0x8001BA78: sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
    after_95:
    // 0x8001BA7C: lh          $v0, 0x2C($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X2C);
    // 0x8001BA80: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001BA84: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x8001BA88: sra         $v0, $t7, 16
    ctx->r2 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8001BA8C: slti        $at, $v0, 0x3C
    ctx->r1 = SIGNED(ctx->r2) < 0X3C ? 1 : 0;
    // 0x8001BA90: bne         $at, $zero, L_8001BA74
    if (ctx->r1 != 0) {
        // 0x8001BA94: nop
    
            goto L_8001BA74;
    }
    // 0x8001BA94: nop

    // 0x8001BA98: jal         0x80035A04
    // 0x8001BA9C: nop

    func_80035A04(rdram, ctx);
        goto after_96;
    // 0x8001BA9C: nop

    after_96:
    // 0x8001BAA0: b           L_8001B5FC
    // 0x8001BAA4: lh          $t4, 0x2E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2E);
        goto L_8001B5FC;
    // 0x8001BAA4: lh          $t4, 0x2E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2E);
L_8001BAA8:
    // 0x8001BAA8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8001BAAC: jal         0x80004CE0
    // 0x8001BAB0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    func_80004CE0(rdram, ctx);
        goto after_97;
    // 0x8001BAB0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_97:
    // 0x8001BAB4: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8001BAB8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8001BABC: bne         $t0, $zero, L_8001BAD8
    if (ctx->r8 != 0) {
        // 0x8001BAC0: nop
    
            goto L_8001BAD8;
    }
    // 0x8001BAC0: nop

L_8001BAC4:
    // 0x8001BAC4: jal         0x8000798C
    // 0x8001BAC8: nop

    func_8000798C(rdram, ctx);
        goto after_98;
    // 0x8001BAC8: nop

    after_98:
    // 0x8001BACC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8001BAD0: beq         $t0, $zero, L_8001BAC4
    if (ctx->r8 == 0) {
        // 0x8001BAD4: nop
    
            goto L_8001BAC4;
    }
    // 0x8001BAD4: nop

L_8001BAD8:
    // 0x8001BAD8: jal         0x80004E5C
    // 0x8001BADC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80004E5C(rdram, ctx);
        goto after_99;
    // 0x8001BADC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_99:
    // 0x8001BAE0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001BAE4: jal         0x8000798C
    // 0x8001BAE8: sw          $zero, -0x6BE0($at)
    MEM_W(-0X6BE0, ctx->r1) = 0;
    func_8000798C(rdram, ctx);
        goto after_100;
    // 0x8001BAE8: sw          $zero, -0x6BE0($at)
    MEM_W(-0X6BE0, ctx->r1) = 0;
    after_100:
    // 0x8001BAEC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8001BAF0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001BAF4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8001BAF8: beql        $t0, $at, L_8001BB20
    if (ctx->r8 == ctx->r1) {
        // 0x8001BAFC: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_8001BB20;
    }
    goto skip_1;
    // 0x8001BAFC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    skip_1:
    // 0x8001BB00: lw          $t9, -0x6BD0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6BD0);
    // 0x8001BB04: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001BB08: jal         0x8000798C
    // 0x8001BB0C: sw          $t9, -0x6BD4($at)
    MEM_W(-0X6BD4, ctx->r1) = ctx->r25;
    func_8000798C(rdram, ctx);
        goto after_101;
    // 0x8001BB0C: sw          $t9, -0x6BD4($at)
    MEM_W(-0X6BD4, ctx->r1) = ctx->r25;
    after_101:
    // 0x8001BB10: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001BB14: b           L_8001B74C
    // 0x8001BB18: lh          $v0, -0x6B88($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X6B88);
        goto L_8001B74C;
    // 0x8001BB18: lh          $v0, -0x6B88($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X6B88);
L_8001BB1C:
    // 0x8001BB1C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8001BB20:
    // 0x8001BB20: lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // 0x8001BB24: addiu       $a0, $a0, 0x6BD0
    ctx->r4 = ADD32(ctx->r4, 0X6BD0);
    // 0x8001BB28: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8001BB2C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x8001BB30: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8001BB34: jal         0x80004CE0
    // 0x8001BB38: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    func_80004CE0(rdram, ctx);
        goto after_102;
    // 0x8001BB38: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_102:
    // 0x8001BB3C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8001BB40: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8001BB44: beq         $t0, $zero, L_8001BB60
    if (ctx->r8 == 0) {
        // 0x8001BB48: nop
    
            goto L_8001BB60;
    }
    // 0x8001BB48: nop

L_8001BB4C:
    // 0x8001BB4C: jal         0x8000798C
    // 0x8001BB50: nop

    func_8000798C(rdram, ctx);
        goto after_103;
    // 0x8001BB50: nop

    after_103:
    // 0x8001BB54: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8001BB58: bne         $t0, $zero, L_8001BB4C
    if (ctx->r8 != 0) {
        // 0x8001BB5C: nop
    
            goto L_8001BB4C;
    }
    // 0x8001BB5C: nop

L_8001BB60:
    // 0x8001BB60: jal         0x80004E5C
    // 0x8001BB64: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80004E5C(rdram, ctx);
        goto after_104;
    // 0x8001BB64: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_104:
    // 0x8001BB68: jal         0x8000798C
    // 0x8001BB6C: nop

    func_8000798C(rdram, ctx);
        goto after_105;
    // 0x8001BB6C: nop

    after_105:
    // 0x8001BB70: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001BB74: addiu       $v1, $v1, -0x6BE0
    ctx->r3 = ADD32(ctx->r3, -0X6BE0);
    // 0x8001BB78: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8001BB7C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001BB80: bnel        $t2, $at, L_8001BB94
    if (ctx->r10 != ctx->r1) {
        // 0x8001BB84: sw          $zero, 0x0($v1)
        MEM_W(0X0, ctx->r3) = 0;
            goto L_8001BB94;
    }
    goto skip_2;
    // 0x8001BB84: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    skip_2:
    // 0x8001BB88: b           L_8001BB98
    // 0x8001BB8C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
        goto L_8001BB98;
    // 0x8001BB8C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8001BB90: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8001BB94:
    // 0x8001BB94: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
L_8001BB98:
    // 0x8001BB98: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
L_8001BB9C:
    // 0x8001BB9C: jal         0x8000798C
    // 0x8001BBA0: nop

    func_8000798C(rdram, ctx);
        goto after_106;
    // 0x8001BBA0: nop

    after_106:
    // 0x8001BBA4: b           L_8001BB9C
    // 0x8001BBA8: nop

        goto L_8001BB9C;
    // 0x8001BBA8: nop

    // 0x8001BBAC: nop

    // 0x8001BBB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001BBB4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8001BBB8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8001AD38(uint8_t* rdram, recomp_context* ctx) { func_8001AD38_entry(rdram, ctx, 0); }
RECOMP_FUNC void func_8001B250(uint8_t* rdram, recomp_context* ctx) { func_8001AD38_entry(rdram, ctx, 1); }

RECOMP_FUNC void func_8001BBC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8001BBC0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8001BBC4: lh          $t6, -0x662C($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X662C);
    // 0x8001BBC8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8001BBCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001BBD0: bne         $t6, $at, L_8001BBDC
    if (ctx->r14 != ctx->r1) {
        // 0x8001BBD4: lui         $a1, 0x8013
        ctx->r5 = S32(0X8013 << 16);
            goto L_8001BBDC;
    }
    // 0x8001BBD4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8001BBD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001BBDC:
    // 0x8001BBDC: addiu       $a1, $a1, -0x6BA6
    ctx->r5 = ADD32(ctx->r5, -0X6BA6);
    // 0x8001BBE0: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8001BBE4: sh          $t7, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r15;
    // 0x8001BBE8: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    // 0x8001BBEC: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8001BBF0: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x8001BBF4: blez        $a0, L_8001BC48
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8001BBF8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8001BC48;
    }
    // 0x8001BBF8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001BBFC: lui         $t9, 0x8007
    ctx->r25 = S32(0X8007 << 16);
    // 0x8001BC00: addiu       $t9, $t9, -0x63A0
    ctx->r25 = ADD32(ctx->r25, -0X63A0);
    // 0x8001BC04: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8001BC08: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8001BC0C: addiu       $a2, $a2, -0x6BC8
    ctx->r6 = ADD32(ctx->r6, -0X6BC8);
    // 0x8001BC10: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x8001BC14: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
L_8001BC18:
    // 0x8001BC18: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x8001BC1C: sll         $t1, $v1, 1
    ctx->r9 = S32(ctx->r3 << 1);
    // 0x8001BC20: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001BC24: sll         $t4, $v1, 16
    ctx->r12 = S32(ctx->r3 << 16);
    // 0x8001BC28: addu        $t2, $a1, $t1
    ctx->r10 = ADD32(ctx->r5, ctx->r9);
    // 0x8001BC2C: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x8001BC30: sra         $v1, $t4, 16
    ctx->r3 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8001BC34: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001BC38: addu        $v0, $a2, $t0
    ctx->r2 = ADD32(ctx->r6, ctx->r8);
    // 0x8001BC3C: sh          $a3, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r7;
    // 0x8001BC40: bne         $at, $zero, L_8001BC18
    if (ctx->r1 != 0) {
        // 0x8001BC44: sh          $t3, 0x0($v0)
        MEM_H(0X0, ctx->r2) = ctx->r11;
            goto L_8001BC18;
    }
    // 0x8001BC44: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
L_8001BC48:
    // 0x8001BC48: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8001BC50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8001BC50: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8001BC54: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x8001BC58: lh          $t9, 0x56($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X56);
    // 0x8001BC5C: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8001BC60: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8001BC64: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8001BC68: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8001BC6C: sll         $s2, $t7, 16
    ctx->r18 = S32(ctx->r15 << 16);
    // 0x8001BC70: lui         $s1, 0x8007
    ctx->r17 = S32(0X8007 << 16);
    // 0x8001BC74: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8001BC78: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8001BC7C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8001BC80: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8001BC84: sra         $t8, $s2, 16
    ctx->r24 = S32(SIGNED(ctx->r18) >> 16);
    // 0x8001BC88: addu        $s1, $s1, $t0
    ctx->r17 = ADD32(ctx->r17, ctx->r8);
    // 0x8001BC8C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8001BC90: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8001BC94: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8001BC98: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8001BC9C: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8001BCA0: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8001BCA4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8001BCA8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8001BCAC: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
    // 0x8001BCB0: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x8001BCB4: lw          $s1, -0x638C($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X638C);
    // 0x8001BCB8: blez        $t9, L_8001BD94
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8001BCBC: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_8001BD94;
    }
    // 0x8001BCBC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8001BCC0: addiu       $fp, $zero, 0xA
    ctx->r30 = ADD32(0, 0XA);
    // 0x8001BCC4: ori         $s7, $zero, 0xFF00
    ctx->r23 = 0 | 0XFF00;
    // 0x8001BCC8: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
    // 0x8001BCCC: lh          $s5, 0x5A($sp)
    ctx->r21 = MEM_H(ctx->r29, 0X5A);
L_8001BCD0:
    // 0x8001BCD0: div         $zero, $s3, $s1
    lo = S32(S64(S32(ctx->r19)) / S64(S32(ctx->r17))); hi = S32(S64(S32(ctx->r19)) % S64(S32(ctx->r17)));
    // 0x8001BCD4: mflo        $v0
    ctx->r2 = lo;
    // 0x8001BCD8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8001BCDC: bne         $s1, $zero, L_8001BCE8
    if (ctx->r17 != 0) {
        // 0x8001BCE0: nop
    
            goto L_8001BCE8;
    }
    // 0x8001BCE0: nop

    // 0x8001BCE4: break       7
    do_break(2147597540);
L_8001BCE8:
    // 0x8001BCE8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001BCEC: bne         $s1, $at, L_8001BD00
    if (ctx->r17 != ctx->r1) {
        // 0x8001BCF0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001BD00;
    }
    // 0x8001BCF0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001BCF4: bne         $s3, $at, L_8001BD00
    if (ctx->r19 != ctx->r1) {
        // 0x8001BCF8: nop
    
            goto L_8001BD00;
    }
    // 0x8001BCF8: nop

    // 0x8001BCFC: break       6
    do_break(2147597564);
L_8001BD00:
    // 0x8001BD00: beq         $v0, $s6, L_8001BD4C
    if (ctx->r2 == ctx->r22) {
        // 0x8001BD04: nop
    
            goto L_8001BD4C;
    }
    // 0x8001BD04: nop

    // 0x8001BD08: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x8001BD0C: addu        $a2, $s5, $s7
    ctx->r6 = ADD32(ctx->r21, ctx->r23);
    // 0x8001BD10: addiu       $a3, $s0, 0x54
    ctx->r7 = ADD32(ctx->r16, 0X54);
    // 0x8001BD14: sll         $t4, $a3, 16
    ctx->r12 = S32(ctx->r7 << 16);
    // 0x8001BD18: sll         $t2, $a2, 16
    ctx->r10 = S32(ctx->r6 << 16);
    // 0x8001BD1C: sra         $t1, $a0, 16
    ctx->r9 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001BD20: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x8001BD24: sra         $a2, $t2, 16
    ctx->r6 = S32(SIGNED(ctx->r10) >> 16);
    // 0x8001BD28: sra         $a3, $t4, 16
    ctx->r7 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8001BD2C: lh          $a1, 0x4E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X4E);
    // 0x8001BD30: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001BD34: jal         0x8004C580
    // 0x8001BD38: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_0;
    // 0x8001BD38: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_0:
    // 0x8001BD3C: multu       $s0, $s1
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001BD40: mflo        $t6
    ctx->r14 = lo;
    // 0x8001BD44: subu        $s3, $s3, $t6
    ctx->r19 = SUB32(ctx->r19, ctx->r14);
    // 0x8001BD48: nop

L_8001BD4C:
    // 0x8001BD4C: div         $zero, $s1, $fp
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r30))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r30)));
    // 0x8001BD50: lh          $t0, 0x56($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X56);
    // 0x8001BD54: addiu       $s2, $s2, 0x20
    ctx->r18 = ADD32(ctx->r18, 0X20);
    // 0x8001BD58: bne         $fp, $zero, L_8001BD64
    if (ctx->r30 != 0) {
        // 0x8001BD5C: nop
    
            goto L_8001BD64;
    }
    // 0x8001BD5C: nop

    // 0x8001BD60: break       7
    do_break(2147597664);
L_8001BD64:
    // 0x8001BD64: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001BD68: bne         $fp, $at, L_8001BD7C
    if (ctx->r30 != ctx->r1) {
        // 0x8001BD6C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001BD7C;
    }
    // 0x8001BD6C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001BD70: bne         $s1, $at, L_8001BD7C
    if (ctx->r17 != ctx->r1) {
        // 0x8001BD74: nop
    
            goto L_8001BD7C;
    }
    // 0x8001BD74: nop

    // 0x8001BD78: break       6
    do_break(2147597688);
L_8001BD7C:
    // 0x8001BD7C: sll         $t7, $s2, 16
    ctx->r15 = S32(ctx->r18 << 16);
    // 0x8001BD80: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8001BD84: mflo        $s1
    ctx->r17 = lo;
    // 0x8001BD88: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8001BD8C: bne         $s4, $t0, L_8001BCD0
    if (ctx->r20 != ctx->r8) {
        // 0x8001BD90: or          $s2, $t8, $zero
        ctx->r18 = ctx->r24 | 0;
            goto L_8001BCD0;
    }
    // 0x8001BD90: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
L_8001BD94:
    // 0x8001BD94: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8001BD98: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8001BD9C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8001BDA0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8001BDA4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8001BDA8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8001BDAC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8001BDB0: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8001BDB4: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8001BDB8: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8001BDBC: jr          $ra
    // 0x8001BDC0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    TRACE_RETURN()
    return;
    // 0x8001BDC0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8001BDC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8001BDC4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001BDC8: sh          $zero, -0x6B94($at)
    MEM_H(-0X6B94, ctx->r1) = 0;
    // 0x8001BDCC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001BDD0: sw          $zero, -0x6BDC($at)
    MEM_W(-0X6BDC, ctx->r1) = 0;
    // 0x8001BDD4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001BDD8: sh          $zero, -0x6622($at)
    MEM_H(-0X6622, ctx->r1) = 0;
    // 0x8001BDDC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001BDE0: sh          $zero, -0x6620($at)
    MEM_H(-0X6620, ctx->r1) = 0;
    // 0x8001BDE4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001BDE8: sh          $zero, -0x6BA4($at)
    MEM_H(-0X6BA4, ctx->r1) = 0;
    // 0x8001BDEC: addiu       $sp, $sp, -0x1A8
    ctx->r29 = ADD32(ctx->r29, -0X1A8);
    // 0x8001BDF0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001BDF4: sh          $zero, -0x6BA2($at)
    MEM_H(-0X6BA2, ctx->r1) = 0;
    // 0x8001BDF8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001BDFC: sw          $zero, -0x6BA0($at)
    MEM_W(-0X6BA0, ctx->r1) = 0;
    // 0x8001BE00: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001BE04: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001BE08: sh          $zero, -0x6B9C($at)
    MEM_H(-0X6B9C, ctx->r1) = 0;
    // 0x8001BE0C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001BE10: swc1        $f4, -0x6B98($at)
    MEM_W(-0X6B98, ctx->r1) = ctx->f4.u32l;
    // 0x8001BE14: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001BE18: sw          $zero, -0x65F4($at)
    MEM_W(-0X65F4, ctx->r1) = 0;
    // 0x8001BE1C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001BE20: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001BE24: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8001BE28: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8001BE2C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8001BE30: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8001BE34: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8001BE38: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8001BE3C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8001BE40: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8001BE44: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8001BE48: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8001BE4C: sw          $a0, 0x1A8($sp)
    MEM_W(0X1A8, ctx->r29) = ctx->r4;
    // 0x8001BE50: sh          $t6, 0x6AD2($at)
    MEM_H(0X6AD2, ctx->r1) = ctx->r14;
    // 0x8001BE54: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001BE58: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x8001BE5C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8001BE60: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8001BE64: bne         $at, $zero, L_8001BE84
    if (ctx->r1 != 0) {
        // 0x8001BE68: addiu       $s5, $s5, -0x6BE0
        ctx->r21 = ADD32(ctx->r21, -0X6BE0);
            goto L_8001BE84;
    }
    // 0x8001BE68: addiu       $s5, $s5, -0x6BE0
    ctx->r21 = ADD32(ctx->r21, -0X6BE0);
    // 0x8001BE6C: addiu       $t2, $v0, -0xA
    ctx->r10 = ADD32(ctx->r2, -0XA);
    // 0x8001BE70: sll         $t8, $t2, 16
    ctx->r24 = S32(ctx->r10 << 16);
    // 0x8001BE74: sw          $zero, 0x0($s5)
    MEM_W(0X0, ctx->r21) = 0;
    // 0x8001BE78: ori         $t6, $zero, 0x4
    ctx->r14 = 0 | 0X4;
    // 0x8001BE7C: sra         $t2, $t8, 16
    ctx->r10 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8001BE80: sw          $t6, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r14;
L_8001BE84:
    // 0x8001BE84: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x8001BE88: addiu       $s5, $s5, -0x6BE0
    ctx->r21 = ADD32(ctx->r21, -0X6BE0);
    // 0x8001BE8C: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x8001BE90: andi        $t7, $v0, 0x4
    ctx->r15 = ctx->r2 & 0X4;
    // 0x8001BE94: beq         $t7, $zero, L_8001C020
    if (ctx->r15 == 0) {
        // 0x8001BE98: nop
    
            goto L_8001C020;
    }
    // 0x8001BE98: nop

    // 0x8001BE9C: beq         $t2, $zero, L_8001BED0
    if (ctx->r10 == 0) {
        // 0x8001BEA0: lui         $a0, 0x40
        ctx->r4 = S32(0X40 << 16);
            goto L_8001BED0;
    }
    // 0x8001BEA0: lui         $a0, 0x40
    ctx->r4 = S32(0X40 << 16);
    // 0x8001BEA4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001BEA8: beq         $t2, $at, L_8001BEE8
    if (ctx->r10 == ctx->r1) {
        // 0x8001BEAC: lui         $a0, 0x40
        ctx->r4 = S32(0X40 << 16);
            goto L_8001BEE8;
    }
    // 0x8001BEAC: lui         $a0, 0x40
    ctx->r4 = S32(0X40 << 16);
    // 0x8001BEB0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8001BEB4: beq         $t2, $a1, L_8001BF00
    if (ctx->r10 == ctx->r5) {
        // 0x8001BEB8: lui         $a0, 0x40
        ctx->r4 = S32(0X40 << 16);
            goto L_8001BF00;
    }
    // 0x8001BEB8: lui         $a0, 0x40
    ctx->r4 = S32(0X40 << 16);
    // 0x8001BEBC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001BEC0: beq         $t2, $at, L_8001BF18
    if (ctx->r10 == ctx->r1) {
        // 0x8001BEC4: lui         $a0, 0x40
        ctx->r4 = S32(0X40 << 16);
            goto L_8001BF18;
    }
    // 0x8001BEC4: lui         $a0, 0x40
    ctx->r4 = S32(0X40 << 16);
    // 0x8001BEC8: b           L_8001BF28
    // 0x8001BECC: lw          $v1, 0x1A0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1A0);
        goto L_8001BF28;
    // 0x8001BECC: lw          $v1, 0x1A0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1A0);
L_8001BED0:
    // 0x8001BED0: jal         0x8004EFD0
    // 0x8001BED4: addiu       $a0, $a0, -0x1DE0
    ctx->r4 = ADD32(ctx->r4, -0X1DE0);
    func_8004EFD0(rdram, ctx);
        goto after_0;
    // 0x8001BED4: addiu       $a0, $a0, -0x1DE0
    ctx->r4 = ADD32(ctx->r4, -0X1DE0);
    after_0:
    // 0x8001BED8: sw          $v0, 0x1A0($sp)
    MEM_W(0X1A0, ctx->r29) = ctx->r2;
    // 0x8001BEDC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8001BEE0: b           L_8001BF28
    // 0x8001BEE4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8001BF28;
    // 0x8001BEE4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8001BEE8:
    // 0x8001BEE8: jal         0x8004EFD0
    // 0x8001BEEC: addiu       $a0, $a0, -0x8D0
    ctx->r4 = ADD32(ctx->r4, -0X8D0);
    func_8004EFD0(rdram, ctx);
        goto after_1;
    // 0x8001BEEC: addiu       $a0, $a0, -0x8D0
    ctx->r4 = ADD32(ctx->r4, -0X8D0);
    after_1:
    // 0x8001BEF0: sw          $v0, 0x1A0($sp)
    MEM_W(0X1A0, ctx->r29) = ctx->r2;
    // 0x8001BEF4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8001BEF8: b           L_8001BF28
    // 0x8001BEFC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8001BF28;
    // 0x8001BEFC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8001BF00:
    // 0x8001BF00: jal         0x8004EFD0
    // 0x8001BF04: addiu       $a0, $a0, 0xA90
    ctx->r4 = ADD32(ctx->r4, 0XA90);
    func_8004EFD0(rdram, ctx);
        goto after_2;
    // 0x8001BF04: addiu       $a0, $a0, 0xA90
    ctx->r4 = ADD32(ctx->r4, 0XA90);
    after_2:
    // 0x8001BF08: sw          $v0, 0x1A0($sp)
    MEM_W(0X1A0, ctx->r29) = ctx->r2;
    // 0x8001BF0C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8001BF10: b           L_8001BF28
    // 0x8001BF14: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8001BF28;
    // 0x8001BF14: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8001BF18:
    // 0x8001BF18: jal         0x8004EFD0
    // 0x8001BF1C: addiu       $a0, $a0, 0x1EA0
    ctx->r4 = ADD32(ctx->r4, 0X1EA0);
    func_8004EFD0(rdram, ctx);
        goto after_3;
    // 0x8001BF1C: addiu       $a0, $a0, 0x1EA0
    ctx->r4 = ADD32(ctx->r4, 0X1EA0);
    after_3:
    // 0x8001BF20: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8001BF24: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_8001BF28:
    // 0x8001BF28: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x8001BF2C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001BF30: addiu       $a0, $a0, -0x6630
    ctx->r4 = ADD32(ctx->r4, -0X6630);
    // 0x8001BF34: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8001BF38: lbu         $t9, 0x1($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1);
    // 0x8001BF3C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001BF40: sw          $t9, -0x68C8($at)
    MEM_W(-0X68C8, ctx->r1) = ctx->r25;
    // 0x8001BF44: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001BF48: lhu         $t5, 0x2($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X2);
    // 0x8001BF4C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001BF50: beq         $v0, $at, L_8001BF80
    if (ctx->r2 == ctx->r1) {
        // 0x8001BF54: sw          $t5, 0x19C($sp)
        MEM_W(0X19C, ctx->r29) = ctx->r13;
            goto L_8001BF80;
    }
    // 0x8001BF54: sw          $t5, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r13;
    // 0x8001BF58: beq         $v0, $a1, L_8001BF8C
    if (ctx->r2 == ctx->r5) {
        // 0x8001BF5C: addiu       $t6, $zero, 0x3
        ctx->r14 = ADD32(0, 0X3);
            goto L_8001BF8C;
    }
    // 0x8001BF5C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8001BF60: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8001BF64: beq         $v0, $at, L_8001BF98
    if (ctx->r2 == ctx->r1) {
        // 0x8001BF68: addiu       $t7, $zero, 0x6
        ctx->r15 = ADD32(0, 0X6);
            goto L_8001BF98;
    }
    // 0x8001BF68: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x8001BF6C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8001BF70: beq         $v0, $at, L_8001BFA4
    if (ctx->r2 == ctx->r1) {
        // 0x8001BF74: addiu       $t8, $zero, 0x7
        ctx->r24 = ADD32(0, 0X7);
            goto L_8001BFA4;
    }
    // 0x8001BF74: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x8001BF78: b           L_8001BFAC
    // 0x8001BF7C: nop

        goto L_8001BFAC;
    // 0x8001BF7C: nop

L_8001BF80:
    // 0x8001BF80: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001BF84: b           L_8001BFAC
    // 0x8001BF88: sh          $a1, -0x662C($at)
    MEM_H(-0X662C, ctx->r1) = ctx->r5;
        goto L_8001BFAC;
    // 0x8001BF88: sh          $a1, -0x662C($at)
    MEM_H(-0X662C, ctx->r1) = ctx->r5;
L_8001BF8C:
    // 0x8001BF8C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001BF90: b           L_8001BFAC
    // 0x8001BF94: sh          $t6, -0x662C($at)
    MEM_H(-0X662C, ctx->r1) = ctx->r14;
        goto L_8001BFAC;
    // 0x8001BF94: sh          $t6, -0x662C($at)
    MEM_H(-0X662C, ctx->r1) = ctx->r14;
L_8001BF98:
    // 0x8001BF98: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001BF9C: b           L_8001BFAC
    // 0x8001BFA0: sh          $t7, -0x662C($at)
    MEM_H(-0X662C, ctx->r1) = ctx->r15;
        goto L_8001BFAC;
    // 0x8001BFA0: sh          $t7, -0x662C($at)
    MEM_H(-0X662C, ctx->r1) = ctx->r15;
L_8001BFA4:
    // 0x8001BFA4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001BFA8: sh          $t8, -0x662C($at)
    MEM_H(-0X662C, ctx->r1) = ctx->r24;
L_8001BFAC:
    // 0x8001BFAC: jal         0x8001BBC0
    // 0x8001BFB0: sw          $v1, 0x1A0($sp)
    MEM_W(0X1A0, ctx->r29) = ctx->r3;
    func_8001BBC0(rdram, ctx);
        goto after_4;
    // 0x8001BFB0: sw          $v1, 0x1A0($sp)
    MEM_W(0X1A0, ctx->r29) = ctx->r3;
    after_4:
    // 0x8001BFB4: jal         0x8002421C
    // 0x8001BFB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8002421C(rdram, ctx);
        goto after_5;
    // 0x8001BFB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x8001BFBC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001BFC0: sw          $zero, 0x6AC4($at)
    MEM_W(0X6AC4, ctx->r1) = 0;
    // 0x8001BFC4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001BFC8: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x8001BFCC: sh          $zero, -0x6B90($at)
    MEM_H(-0X6B90, ctx->r1) = 0;
    // 0x8001BFD0: addiu       $s4, $s4, 0x6ACC
    ctx->r20 = ADD32(ctx->r20, 0X6ACC);
    // 0x8001BFD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001BFD8: sh          $zero, 0x0($s4)
    MEM_H(0X0, ctx->r20) = 0;
    // 0x8001BFDC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001BFE0: sh          $v0, -0x6B78($at)
    MEM_H(-0X6B78, ctx->r1) = ctx->r2;
    // 0x8001BFE4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001BFE8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8001BFEC: sh          $t9, -0x6B76($at)
    MEM_H(-0X6B76, ctx->r1) = ctx->r25;
    // 0x8001BFF0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001BFF4: sh          $v0, -0x6B74($at)
    MEM_H(-0X6B74, ctx->r1) = ctx->r2;
    // 0x8001BFF8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001BFFC: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8001C000: sh          $t5, -0x6B72($at)
    MEM_H(-0X6B72, ctx->r1) = ctx->r13;
    // 0x8001C004: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001C008: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8001C00C: jal         0x8004F590
    // 0x8001C010: sh          $t6, -0x6B70($at)
    MEM_H(-0X6B70, ctx->r1) = ctx->r14;
    func_8004F590(rdram, ctx);
        goto after_6;
    // 0x8001C010: sh          $t6, -0x6B70($at)
    MEM_H(-0X6B70, ctx->r1) = ctx->r14;
    after_6:
    // 0x8001C014: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001C018: b           L_8001C0F0
    // 0x8001C01C: sw          $t7, 0x198($sp)
    MEM_W(0X198, ctx->r29) = ctx->r15;
        goto L_8001C0F0;
    // 0x8001C01C: sw          $t7, 0x198($sp)
    MEM_W(0X198, ctx->r29) = ctx->r15;
L_8001C020:
    // 0x8001C020: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8001C024: lhu         $t8, -0x2E5C($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X2E5C);
    // 0x8001C028: andi        $t9, $t8, 0x10
    ctx->r25 = ctx->r24 & 0X10;
    // 0x8001C02C: beq         $t9, $zero, L_8001C0DC
    if (ctx->r25 == 0) {
        // 0x8001C030: ori         $t5, $v0, 0x2
        ctx->r13 = ctx->r2 | 0X2;
            goto L_8001C0DC;
    }
    // 0x8001C030: ori         $t5, $v0, 0x2
    ctx->r13 = ctx->r2 | 0X2;
    // 0x8001C034: addiu       $t6, $zero, 0xE10
    ctx->r14 = ADD32(0, 0XE10);
    // 0x8001C038: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8001C03C: sw          $t5, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r13;
    // 0x8001C040: sw          $t6, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r14;
    // 0x8001C044: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8001C048: jal         0x80004364
    // 0x8001C04C: addiu       $a1, $zero, 0x5460
    ctx->r5 = ADD32(0, 0X5460);
    func_80004364(rdram, ctx);
        goto after_7;
    // 0x8001C04C: addiu       $a1, $zero, 0x5460
    ctx->r5 = ADD32(0, 0X5460);
    after_7:
    // 0x8001C050: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8001C054: lw          $t7, -0x6630($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6630);
    // 0x8001C058: sw          $v0, 0x1A0($sp)
    MEM_W(0X1A0, ctx->r29) = ctx->r2;
    // 0x8001C05C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8001C060: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x8001C064: lw          $t8, -0x68C8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X68C8);
    // 0x8001C068: addiu       $t9, $zero, 0xE10
    ctx->r25 = ADD32(0, 0XE10);
    // 0x8001C06C: sh          $t9, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r25;
    // 0x8001C070: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001C074: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001C078: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    // 0x8001C07C: sh          $t6, -0x6B78($at)
    MEM_H(-0X6B78, ctx->r1) = ctx->r14;
    // 0x8001C080: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001C084: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8001C088: sh          $t7, -0x6B76($at)
    MEM_H(-0X6B76, ctx->r1) = ctx->r15;
    // 0x8001C08C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001C090: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8001C094: sh          $t8, -0x6B74($at)
    MEM_H(-0X6B74, ctx->r1) = ctx->r24;
    // 0x8001C098: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8001C09C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001C0A0: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8001C0A4: sw          $t5, 0x198($sp)
    MEM_W(0X198, ctx->r29) = ctx->r13;
    // 0x8001C0A8: sh          $t9, -0x6B72($at)
    MEM_H(-0X6B72, ctx->r1) = ctx->r25;
    // 0x8001C0AC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001C0B0: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8001C0B4: sh          $t5, -0x6B70($at)
    MEM_H(-0X6B70, ctx->r1) = ctx->r13;
    // 0x8001C0B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001C0BC: sw          $zero, 0x6AC4($at)
    MEM_W(0X6AC4, ctx->r1) = 0;
    // 0x8001C0C0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001C0C4: jal         0x8004F590
    // 0x8001C0C8: sh          $zero, -0x6B90($at)
    MEM_H(-0X6B90, ctx->r1) = 0;
    func_8004F590(rdram, ctx);
        goto after_8;
    // 0x8001C0C8: sh          $zero, -0x6B90($at)
    MEM_H(-0X6B90, ctx->r1) = 0;
    after_8:
    // 0x8001C0CC: jal         0x8001BBC0
    // 0x8001C0D0: nop

    func_8001BBC0(rdram, ctx);
        goto after_9;
    // 0x8001C0D0: nop

    after_9:
    // 0x8001C0D4: jal         0x8002421C
    // 0x8001C0D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8002421C(rdram, ctx);
        goto after_10;
    // 0x8001C0D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
L_8001C0DC:
    // 0x8001C0DC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001C0E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001C0E4: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x8001C0E8: addiu       $s4, $s4, 0x6ACC
    ctx->r20 = ADD32(ctx->r20, 0X6ACC);
    // 0x8001C0EC: sh          $t6, -0x2D1E($at)
    MEM_H(-0X2D1E, ctx->r1) = ctx->r14;
L_8001C0F0:
    // 0x8001C0F0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8001C0F4: lh          $t7, -0x6B88($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X6B88);
    // 0x8001C0F8: beq         $t7, $zero, L_8001C108
    if (ctx->r15 == 0) {
        // 0x8001C0FC: nop
    
            goto L_8001C108;
    }
    // 0x8001C0FC: nop

    // 0x8001C100: jal         0x8001BBC0
    // 0x8001C104: nop

    func_8001BBC0(rdram, ctx);
        goto after_11;
    // 0x8001C104: nop

    after_11:
L_8001C108:
    // 0x8001C108: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8001C10C: lh          $t8, -0x6B8E($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X6B8E);
    // 0x8001C110: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8001C114: beq         $t8, $zero, L_8001C13C
    if (ctx->r24 == 0) {
        // 0x8001C118: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8001C13C;
    }
    // 0x8001C118: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001C11C: addiu       $v0, $v0, -0x6BC8
    ctx->r2 = ADD32(ctx->r2, -0X6BC8);
    // 0x8001C120: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8001C124: addiu       $t5, $zero, 0xC8
    ctx->r13 = ADD32(0, 0XC8);
    // 0x8001C128: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x8001C12C: sh          $t5, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r13;
    // 0x8001C130: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001C134: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001C138: sh          $t6, -0x6BA6($at)
    MEM_H(-0X6BA6, ctx->r1) = ctx->r14;
L_8001C13C:
    // 0x8001C13C: lh          $t7, -0x6B80($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X6B80);
    // 0x8001C140: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001C144: bne         $t7, $at, L_8001C15C
    if (ctx->r15 != ctx->r1) {
        // 0x8001C148: addiu       $a0, $zero, 0xF
        ctx->r4 = ADD32(0, 0XF);
            goto L_8001C15C;
    }
    // 0x8001C148: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x8001C14C: jal         0x800499B0
    // 0x8001C150: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800499B0(rdram, ctx);
        goto after_12;
    // 0x8001C150: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x8001C154: b           L_8001C180
    // 0x8001C158: nop

        goto L_8001C180;
    // 0x8001C158: nop

L_8001C15C:
    // 0x8001C15C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001C160: lh          $v0, -0x662C($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X662C);
    // 0x8001C164: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x8001C168: addiu       $a1, $v0, -0x1
    ctx->r5 = ADD32(ctx->r2, -0X1);
    // 0x8001C16C: sll         $t9, $a1, 16
    ctx->r25 = S32(ctx->r5 << 16);
    // 0x8001C170: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001C174: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8001C178: jal         0x800499B0
    // 0x8001C17C: sra         $a1, $t9, 16
    ctx->r5 = S32(SIGNED(ctx->r25) >> 16);
    func_800499B0(rdram, ctx);
        goto after_13;
    // 0x8001C17C: sra         $a1, $t9, 16
    ctx->r5 = S32(SIGNED(ctx->r25) >> 16);
    after_13:
L_8001C180:
    // 0x8001C180: jal         0x8000798C
    // 0x8001C184: nop

    func_8000798C(rdram, ctx);
        goto after_14;
    // 0x8001C184: nop

    after_14:
    // 0x8001C188: jal         0x8000798C
    // 0x8001C18C: nop

    func_8000798C(rdram, ctx);
        goto after_15;
    // 0x8001C18C: nop

    after_15:
    // 0x8001C190: jal         0x8000798C
    // 0x8001C194: nop

    func_8000798C(rdram, ctx);
        goto after_16;
    // 0x8001C194: nop

    after_16:
    // 0x8001C198: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8001C19C: lh          $t6, -0x662C($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X662C);
    // 0x8001C1A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001C1A4: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
    // 0x8001C1A8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8001C1AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001C1B0: jal         0x8004D134
    // 0x8001C1B4: sh          $t6, -0x2CC2($at)
    MEM_H(-0X2CC2, ctx->r1) = ctx->r14;
    func_8004D134(rdram, ctx);
        goto after_17;
    // 0x8001C1B4: sh          $t6, -0x2CC2($at)
    MEM_H(-0X2CC2, ctx->r1) = ctx->r14;
    after_17:
    // 0x8001C1B8: addiu       $t7, $zero, 0x3E8
    ctx->r15 = ADD32(0, 0X3E8);
    // 0x8001C1BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001C1C0: sw          $t7, -0x2CF8($at)
    MEM_W(-0X2CF8, ctx->r1) = ctx->r15;
    // 0x8001C1C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001C1C8: addiu       $t8, $zero, 0x3E4
    ctx->r24 = ADD32(0, 0X3E4);
    // 0x8001C1CC: sw          $t8, -0x2CF4($at)
    MEM_W(-0X2CF4, ctx->r1) = ctx->r24;
    // 0x8001C1D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001C1D4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8001C1D8: jal         0x8001AC78
    // 0x8001C1DC: sh          $t9, -0x2CC4($at)
    MEM_H(-0X2CC4, ctx->r1) = ctx->r25;
    func_8001AC78(rdram, ctx);
        goto after_18;
    // 0x8001C1DC: sh          $t9, -0x2CC4($at)
    MEM_H(-0X2CC4, ctx->r1) = ctx->r25;
    after_18:
    // 0x8001C1E0: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x8001C1E4: lw          $t5, -0x6630($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X6630);
    // 0x8001C1E8: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x8001C1EC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001C1F0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8001C1F4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8001C1F8: lw          $t7, -0x646C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X646C);
    // 0x8001C1FC: jal         0x800358B0
    // 0x8001C200: sw          $t7, -0x6B58($at)
    MEM_W(-0X6B58, ctx->r1) = ctx->r15;
    func_800358B0(rdram, ctx);
        goto after_19;
    // 0x8001C200: sw          $t7, -0x6B58($at)
    MEM_W(-0X6B58, ctx->r1) = ctx->r15;
    after_19:
    // 0x8001C204: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    // 0x8001C208: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x8001C20C: addiu       $a3, $sp, 0x114
    ctx->r7 = ADD32(ctx->r29, 0X114);
    // 0x8001C210: andi        $t9, $t8, 0x200
    ctx->r25 = ctx->r24 & 0X200;
    // 0x8001C214: beq         $t9, $zero, L_8001C224
    if (ctx->r25 == 0) {
        // 0x8001C218: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8001C224;
    }
    // 0x8001C218: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001C21C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001C220: sh          $zero, -0x661E($at)
    MEM_H(-0X661E, ctx->r1) = 0;
L_8001C224:
    // 0x8001C224: lh          $t5, -0x6B8E($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X6B8E);
    // 0x8001C228: lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // 0x8001C22C: addiu       $a0, $a0, 0x3D4
    ctx->r4 = ADD32(ctx->r4, 0X3D4);
    // 0x8001C230: beq         $t5, $zero, L_8001C244
    if (ctx->r13 == 0) {
        // 0x8001C234: addiu       $a1, $zero, 0x28
        ctx->r5 = ADD32(0, 0X28);
            goto L_8001C244;
    }
    // 0x8001C234: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x8001C238: addiu       $t6, $zero, 0xE10
    ctx->r14 = ADD32(0, 0XE10);
    // 0x8001C23C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001C240: sh          $t6, -0x6B8C($at)
    MEM_H(-0X6B8C, ctx->r1) = ctx->r14;
L_8001C244:
    // 0x8001C244: sw          $t7, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r15;
    // 0x8001C248: jal         0x80004CE0
    // 0x8001C24C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_80004CE0(rdram, ctx);
        goto after_20;
    // 0x8001C24C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_20:
    // 0x8001C250: sw          $v0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r2;
    // 0x8001C254: addiu       $s0, $sp, 0x118
    ctx->r16 = ADD32(ctx->r29, 0X118);
    // 0x8001C258: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8001C25C: addiu       $t0, $sp, 0x94
    ctx->r8 = ADD32(ctx->r29, 0X94);
    // 0x8001C260: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8001C264: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x8001C268: addiu       $a0, $a0, -0x2E00
    ctx->r4 = ADD32(ctx->r4, -0X2E00);
    // 0x8001C26C: sw          $t0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r8;
    // 0x8001C270: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8001C274: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    // 0x8001C278: jal         0x80004CE0
    // 0x8001C27C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_80004CE0(rdram, ctx);
        goto after_21;
    // 0x8001C27C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_21:
    // 0x8001C280: lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8C);
    // 0x8001C284: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8001C288: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8001C28C: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8001C290: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8001C294: lui         $a0, 0x8002
    ctx->r4 = S32(0X8002 << 16);
    // 0x8001C298: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8001C29C: sw          $t0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r8;
    // 0x8001C2A0: addiu       $a0, $a0, -0x3F0
    ctx->r4 = ADD32(ctx->r4, -0X3F0);
    // 0x8001C2A4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8001C2A8: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x8001C2AC: jal         0x80004CE0
    // 0x8001C2B0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_80004CE0(rdram, ctx);
        goto after_22;
    // 0x8001C2B0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_22:
    // 0x8001C2B4: lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8C);
    // 0x8001C2B8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8001C2BC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8001C2C0: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8001C2C4: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8001C2C8: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x8001C2CC: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8001C2D0: sw          $t0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r8;
    // 0x8001C2D4: addiu       $a0, $a0, -0x2910
    ctx->r4 = ADD32(ctx->r4, -0X2910);
    // 0x8001C2D8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8001C2DC: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    // 0x8001C2E0: jal         0x80004CE0
    // 0x8001C2E4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_80004CE0(rdram, ctx);
        goto after_23;
    // 0x8001C2E4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_23:
    // 0x8001C2E8: lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8C);
    // 0x8001C2EC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001C2F0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8001C2F4: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8001C2F8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8001C2FC: lui         $a0, 0x8002
    ctx->r4 = S32(0X8002 << 16);
    // 0x8001C300: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8001C304: sw          $t0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r8;
    // 0x8001C308: addiu       $a0, $a0, 0x37E0
    ctx->r4 = ADD32(ctx->r4, 0X37E0);
    // 0x8001C30C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8001C310: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x8001C314: jal         0x80004CE0
    // 0x8001C318: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_80004CE0(rdram, ctx);
        goto after_24;
    // 0x8001C318: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_24:
    // 0x8001C31C: lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8C);
    // 0x8001C320: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001C324: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8001C328: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8001C32C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8001C330: lui         $a0, 0x8003
    ctx->r4 = S32(0X8003 << 16);
    // 0x8001C334: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8001C338: sw          $t0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r8;
    // 0x8001C33C: addiu       $a0, $a0, 0x5D60
    ctx->r4 = ADD32(ctx->r4, 0X5D60);
    // 0x8001C340: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8001C344: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    // 0x8001C348: jal         0x80004CE0
    // 0x8001C34C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_80004CE0(rdram, ctx);
        goto after_25;
    // 0x8001C34C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_25:
    // 0x8001C350: lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8C);
    // 0x8001C354: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8001C358: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8001C35C: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8001C360: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8001C364: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8001C368: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8001C36C: sw          $t0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r8;
    // 0x8001C370: addiu       $a0, $a0, -0x6830
    ctx->r4 = ADD32(ctx->r4, -0X6830);
    // 0x8001C374: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8001C378: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    // 0x8001C37C: jal         0x80004CE0
    // 0x8001C380: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_80004CE0(rdram, ctx);
        goto after_26;
    // 0x8001C380: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_26:
    // 0x8001C384: lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8C);
    // 0x8001C388: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8001C38C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8001C390: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8001C394: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8001C398: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8001C39C: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8001C3A0: sw          $t0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r8;
    // 0x8001C3A4: addiu       $a0, $a0, 0x28C0
    ctx->r4 = ADD32(ctx->r4, 0X28C0);
    // 0x8001C3A8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8001C3AC: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x8001C3B0: jal         0x80004CE0
    // 0x8001C3B4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_80004CE0(rdram, ctx);
        goto after_27;
    // 0x8001C3B4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_27:
    // 0x8001C3B8: lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8C);
    // 0x8001C3BC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8001C3C0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8001C3C4: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8001C3C8: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8001C3CC: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8001C3D0: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8001C3D4: sw          $t0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r8;
    // 0x8001C3D8: addiu       $a0, $a0, -0x1B50
    ctx->r4 = ADD32(ctx->r4, -0X1B50);
    // 0x8001C3DC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8001C3E0: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x8001C3E4: jal         0x80004CE0
    // 0x8001C3E8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_80004CE0(rdram, ctx);
        goto after_28;
    // 0x8001C3E8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_28:
    // 0x8001C3EC: lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8C);
    // 0x8001C3F0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001C3F4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8001C3F8: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8001C3FC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8001C400: lui         $a0, 0x8002
    ctx->r4 = S32(0X8002 << 16);
    // 0x8001C404: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8001C408: sw          $t0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r8;
    // 0x8001C40C: addiu       $a0, $a0, -0x2368
    ctx->r4 = ADD32(ctx->r4, -0X2368);
    // 0x8001C410: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8001C414: addiu       $a1, $zero, 0x55
    ctx->r5 = ADD32(0, 0X55);
    // 0x8001C418: jal         0x80004CE0
    // 0x8001C41C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_80004CE0(rdram, ctx);
        goto after_29;
    // 0x8001C41C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_29:
    // 0x8001C420: lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8C);
    // 0x8001C424: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001C428: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8001C42C: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8001C430: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8001C434: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8001C438: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8001C43C: sw          $t0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r8;
    // 0x8001C440: addiu       $a0, $a0, 0x4020
    ctx->r4 = ADD32(ctx->r4, 0X4020);
    // 0x8001C444: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8001C448: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    // 0x8001C44C: jal         0x80004CE0
    // 0x8001C450: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_80004CE0(rdram, ctx);
        goto after_30;
    // 0x8001C450: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_30:
    // 0x8001C454: lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8C);
    // 0x8001C458: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8001C45C: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8001C460: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8001C464: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8001C468: jal         0x8000798C
    // 0x8001C46C: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    func_8000798C(rdram, ctx);
        goto after_31;
    // 0x8001C46C: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    after_31:
    // 0x8001C470: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x8001C474: addiu       $s2, $s2, 0x6ACE
    ctx->r18 = ADD32(ctx->r18, 0X6ACE);
    // 0x8001C478: lh          $t8, 0x0($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X0);
    // 0x8001C47C: beq         $t8, $zero, L_8001C4BC
    if (ctx->r24 == 0) {
        // 0x8001C480: lui         $t9, 0x8013
        ctx->r25 = S32(0X8013 << 16);
            goto L_8001C4BC;
    }
    // 0x8001C480: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8001C484: lh          $t9, -0x6B80($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X6B80);
    // 0x8001C488: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x8001C48C: bne         $t9, $zero, L_8001C4B4
    if (ctx->r25 != 0) {
        // 0x8001C490: nop
    
            goto L_8001C4B4;
    }
    // 0x8001C490: nop

    // 0x8001C494: lw          $t5, -0x6630($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X6630);
    // 0x8001C498: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x8001C49C: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x8001C4A0: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x8001C4A4: jal         0x80007EC8
    // 0x8001C4A8: lh          $a0, -0x6320($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X6320);
    func_80007EC8(rdram, ctx);
        goto after_32;
    // 0x8001C4A8: lh          $a0, -0x6320($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X6320);
    after_32:
    // 0x8001C4AC: b           L_8001C4BC
    // 0x8001C4B0: nop

        goto L_8001C4BC;
    // 0x8001C4B0: nop

L_8001C4B4:
    // 0x8001C4B4: jal         0x80007EC8
    // 0x8001C4B8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_80007EC8(rdram, ctx);
        goto after_33;
    // 0x8001C4B8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_33:
L_8001C4BC:
    // 0x8001C4BC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8001C4C0: addiu       $a1, $a1, -0x6A18
    ctx->r5 = ADD32(ctx->r5, -0X6A18);
    // 0x8001C4C4: jal         0x8004EFB4
    // 0x8001C4C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8004EFB4(rdram, ctx);
        goto after_34;
    // 0x8001C4C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_34:
    // 0x8001C4CC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001C4D0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001C4D4: jal         0x8004D1F0
    // 0x8001C4D8: sh          $t7, -0x6B94($at)
    MEM_H(-0X6B94, ctx->r1) = ctx->r15;
    func_8004D1F0(rdram, ctx);
        goto after_35;
    // 0x8001C4D8: sh          $t7, -0x6B94($at)
    MEM_H(-0X6B94, ctx->r1) = ctx->r15;
    after_35:
    // 0x8001C4DC: beq         $v0, $zero, L_8001C52C
    if (ctx->r2 == 0) {
        // 0x8001C4E0: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_8001C52C;
    }
L_8001C4E0:
    // 0x8001C4E0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8001C4E4: addiu       $v0, $v0, -0x2E47
    ctx->r2 = ADD32(ctx->r2, -0X2E47);
    // 0x8001C4E8: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8001C4EC: lb          $t8, 0x0($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X0);
    // 0x8001C4F0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001C4F4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8001C4F8: sb          $t8, -0x2E48($at)
    MEM_B(-0X2E48, ctx->r1) = ctx->r24;
    // 0x8001C4FC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8001C500: addiu       $a0, $a0, -0x2E42
    ctx->r4 = ADD32(ctx->r4, -0X2E42);
    // 0x8001C504: addiu       $v1, $v1, -0x2E44
    ctx->r3 = ADD32(ctx->r3, -0X2E44);
    // 0x8001C508: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x8001C50C: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x8001C510: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001C514: jal         0x8000798C
    // 0x8001C518: sh          $zero, -0x2E46($at)
    MEM_H(-0X2E46, ctx->r1) = 0;
    func_8000798C(rdram, ctx);
        goto after_36;
    // 0x8001C518: sh          $zero, -0x2E46($at)
    MEM_H(-0X2E46, ctx->r1) = 0;
    after_36:
    // 0x8001C51C: jal         0x8004D1F0
    // 0x8001C520: nop

    func_8004D1F0(rdram, ctx);
        goto after_37;
    // 0x8001C520: nop

    after_37:
    // 0x8001C524: bne         $v0, $zero, L_8001C4E0
    if (ctx->r2 != 0) {
        // 0x8001C528: nop
    
            goto L_8001C4E0;
    }
    // 0x8001C528: nop

L_8001C52C:
    // 0x8001C52C: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    // 0x8001C530: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8001C534: ori         $t7, $t6, 0x800
    ctx->r15 = ctx->r14 | 0X800;
    // 0x8001C538: sw          $t7, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r15;
    // 0x8001C53C: lh          $t8, -0x6B80($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X6B80);
    // 0x8001C540: bne         $t8, $zero, L_8001C550
    if (ctx->r24 != 0) {
        // 0x8001C544: nop
    
            goto L_8001C550;
    }
    // 0x8001C544: nop

    // 0x8001C548: jal         0x80044480
    // 0x8001C54C: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_80044480(rdram, ctx);
        goto after_38;
    // 0x8001C54C: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_38:
L_8001C550:
    // 0x8001C550: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x8001C554: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x8001C558: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x8001C55C: addiu       $s1, $s1, -0x2E4C
    ctx->r17 = ADD32(ctx->r17, -0X2E4C);
    // 0x8001C560: addiu       $s3, $s3, 0x6AD0
    ctx->r19 = ADD32(ctx->r19, 0X6AD0);
    // 0x8001C564: addiu       $s6, $s6, -0x2E5A
    ctx->r22 = ADD32(ctx->r22, -0X2E5A);
    // 0x8001C568: addiu       $fp, $zero, -0x2
    ctx->r30 = ADD32(0, -0X2);
    // 0x8001C56C: addiu       $s7, $sp, 0x68
    ctx->r23 = ADD32(ctx->r29, 0X68);
    // 0x8001C570: lhu         $t9, 0x0($s6)
    ctx->r25 = MEM_HU(ctx->r22, 0X0);
L_8001C574:
    // 0x8001C574: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8001C578: andi        $t5, $t9, 0x1000
    ctx->r13 = ctx->r25 & 0X1000;
    // 0x8001C57C: beql        $t5, $zero, L_8001C970
    if (ctx->r13 == 0) {
        // 0x8001C580: lw          $t7, 0x1A8($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1A8);
            goto L_8001C970;
    }
    goto skip_0;
    // 0x8001C580: lw          $t7, 0x1A8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1A8);
    skip_0:
    // 0x8001C584: lh          $t6, -0x6B8E($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X6B8E);
    // 0x8001C588: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8001C58C: bnel        $t6, $zero, L_8001C970
    if (ctx->r14 != 0) {
        // 0x8001C590: lw          $t7, 0x1A8($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1A8);
            goto L_8001C970;
    }
    goto skip_1;
    // 0x8001C590: lw          $t7, 0x1A8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1A8);
    skip_1:
    // 0x8001C594: lh          $t7, -0x6B80($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X6B80);
    // 0x8001C598: bnel        $t7, $zero, L_8001C970
    if (ctx->r15 != 0) {
        // 0x8001C59C: lw          $t7, 0x1A8($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1A8);
            goto L_8001C970;
    }
    goto skip_2;
    // 0x8001C59C: lw          $t7, 0x1A8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1A8);
    skip_2:
    // 0x8001C5A0: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x8001C5A4: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x8001C5A8: andi        $t8, $v0, 0x2
    ctx->r24 = ctx->r2 & 0X2;
    // 0x8001C5AC: bne         $t8, $zero, L_8001C97C
    if (ctx->r24 != 0) {
        // 0x8001C5B0: andi        $t9, $v0, 0x4
        ctx->r25 = ctx->r2 & 0X4;
            goto L_8001C97C;
    }
    // 0x8001C5B0: andi        $t9, $v0, 0x4
    ctx->r25 = ctx->r2 & 0X4;
    // 0x8001C5B4: bnel        $t9, $zero, L_8001C970
    if (ctx->r25 != 0) {
        // 0x8001C5B8: lw          $t7, 0x1A8($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1A8);
            goto L_8001C970;
    }
    goto skip_3;
    // 0x8001C5B8: lw          $t7, 0x1A8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1A8);
    skip_3:
    // 0x8001C5BC: jal         0x80044480
    // 0x8001C5C0: addiu       $s0, $sp, 0x114
    ctx->r16 = ADD32(ctx->r29, 0X114);
    func_80044480(rdram, ctx);
        goto after_39;
    // 0x8001C5C0: addiu       $s0, $sp, 0x114
    ctx->r16 = ADD32(ctx->r29, 0X114);
    after_39:
    // 0x8001C5C4: lw          $t5, 0x114($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X114);
    // 0x8001C5C8: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x8001C5CC: addiu       $a1, $a1, -0x6368
    ctx->r5 = ADD32(ctx->r5, -0X6368);
    // 0x8001C5D0: beq         $t5, $zero, L_8001C5EC
    if (ctx->r13 == 0) {
        // 0x8001C5D4: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_8001C5EC;
    }
    // 0x8001C5D4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8001C5D8: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
L_8001C5DC:
    // 0x8001C5DC: sw          $fp, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r30;
    // 0x8001C5E0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8001C5E4: bnel        $t6, $zero, L_8001C5DC
    if (ctx->r14 != 0) {
        // 0x8001C5E8: lw          $t6, 0x4($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X4);
            goto L_8001C5DC;
    }
    goto skip_4;
    // 0x8001C5E8: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    skip_4:
L_8001C5EC:
    // 0x8001C5EC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001C5F0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8001C5F4: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x8001C5F8: jal         0x80049660
    // 0x8001C5FC: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    func_80049660(rdram, ctx);
        goto after_40;
    // 0x8001C5FC: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    after_40:
    // 0x8001C600: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8001C604: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001C608: jal         0x8000798C
    // 0x8001C60C: sh          $t8, -0x2D1C($at)
    MEM_H(-0X2D1C, ctx->r1) = ctx->r24;
    func_8000798C(rdram, ctx);
        goto after_41;
    // 0x8001C60C: sh          $t8, -0x2D1C($at)
    MEM_H(-0X2D1C, ctx->r1) = ctx->r24;
    after_41:
    // 0x8001C610: jal         0x8000798C
    // 0x8001C614: nop

    func_8000798C(rdram, ctx);
        goto after_42;
    // 0x8001C614: nop

    after_42:
    // 0x8001C618: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8001C61C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001C620: jal         0x8000798C
    // 0x8001C624: sh          $t9, -0x2D1E($at)
    MEM_H(-0X2D1E, ctx->r1) = ctx->r25;
    func_8000798C(rdram, ctx);
        goto after_43;
    // 0x8001C624: sh          $t9, -0x2D1E($at)
    MEM_H(-0X2D1E, ctx->r1) = ctx->r25;
    after_43:
    // 0x8001C628: jal         0x8000798C
    // 0x8001C62C: nop

    func_8000798C(rdram, ctx);
        goto after_44;
    // 0x8001C62C: nop

    after_44:
    // 0x8001C630: jal         0x8000798C
    // 0x8001C634: nop

    func_8000798C(rdram, ctx);
        goto after_45;
    // 0x8001C634: nop

    after_45:
L_8001C638:
    // 0x8001C638: jal         0x800496B4
    // 0x8001C63C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_800496B4(rdram, ctx);
        goto after_46;
    // 0x8001C63C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_46:
    // 0x8001C640: lhu         $v0, 0x0($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X0);
    // 0x8001C644: lh          $v1, 0x74($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X74);
    // 0x8001C648: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001C64C: andi        $t5, $v0, 0x1000
    ctx->r13 = ctx->r2 & 0X1000;
    // 0x8001C650: beq         $t5, $zero, L_8001C660
    if (ctx->r13 == 0) {
        // 0x8001C654: andi        $t6, $v0, 0xA300
        ctx->r14 = ctx->r2 & 0XA300;
            goto L_8001C660;
    }
    // 0x8001C654: andi        $t6, $v0, 0xA300
    ctx->r14 = ctx->r2 & 0XA300;
    // 0x8001C658: b           L_8001C8F4
    // 0x8001C65C: addiu       $s0, $sp, 0x114
    ctx->r16 = ADD32(ctx->r29, 0X114);
        goto L_8001C8F4;
    // 0x8001C65C: addiu       $s0, $sp, 0x114
    ctx->r16 = ADD32(ctx->r29, 0X114);
L_8001C660:
    // 0x8001C660: beq         $v1, $at, L_8001C690
    if (ctx->r3 == ctx->r1) {
        // 0x8001C664: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8001C690;
    }
    // 0x8001C664: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001C668: beq         $v1, $at, L_8001C718
    if (ctx->r3 == ctx->r1) {
        // 0x8001C66C: andi        $t9, $v0, 0xA300
        ctx->r25 = ctx->r2 & 0XA300;
            goto L_8001C718;
    }
    // 0x8001C66C: andi        $t9, $v0, 0xA300
    ctx->r25 = ctx->r2 & 0XA300;
    // 0x8001C670: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8001C674: beq         $v1, $at, L_8001C7D8
    if (ctx->r3 == ctx->r1) {
        // 0x8001C678: andi        $t5, $v0, 0xA300
        ctx->r13 = ctx->r2 & 0XA300;
            goto L_8001C7D8;
    }
    // 0x8001C678: andi        $t5, $v0, 0xA300
    ctx->r13 = ctx->r2 & 0XA300;
    // 0x8001C67C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8001C680: beq         $v1, $at, L_8001C860
    if (ctx->r3 == ctx->r1) {
        // 0x8001C684: andi        $t8, $v0, 0xA300
        ctx->r24 = ctx->r2 & 0XA300;
            goto L_8001C860;
    }
    // 0x8001C684: andi        $t8, $v0, 0xA300
    ctx->r24 = ctx->r2 & 0XA300;
    // 0x8001C688: b           L_8001C8E4
    // 0x8001C68C: nop

        goto L_8001C8E4;
    // 0x8001C68C: nop

L_8001C690:
    // 0x8001C690: bne         $t6, $zero, L_8001C6A8
    if (ctx->r14 != 0) {
        // 0x8001C694: nop
    
            goto L_8001C6A8;
    }
    // 0x8001C694: nop

    // 0x8001C698: lh          $t7, 0x0($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X0);
    // 0x8001C69C: andi        $t8, $t7, 0x300
    ctx->r24 = ctx->r15 & 0X300;
    // 0x8001C6A0: beql        $t8, $zero, L_8001C6C4
    if (ctx->r24 == 0) {
        // 0x8001C6A4: addiu       $a1, $v1, 0xD
        ctx->r5 = ADD32(ctx->r3, 0XD);
            goto L_8001C6C4;
    }
    goto skip_5;
    // 0x8001C6A4: addiu       $a1, $v1, 0xD
    ctx->r5 = ADD32(ctx->r3, 0XD);
    skip_5:
L_8001C6A8:
    // 0x8001C6A8: jal         0x80044480
    // 0x8001C6AC: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    func_80044480(rdram, ctx);
        goto after_47;
    // 0x8001C6AC: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_47:
    // 0x8001C6B0: lh          $t9, 0x0($s4)
    ctx->r25 = MEM_H(ctx->r20, 0X0);
    // 0x8001C6B4: lh          $v1, 0x74($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X74);
    // 0x8001C6B8: xori        $t5, $t9, 0x1
    ctx->r13 = ctx->r25 ^ 0X1;
    // 0x8001C6BC: sh          $t5, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r13;
    // 0x8001C6C0: addiu       $a1, $v1, 0xD
    ctx->r5 = ADD32(ctx->r3, 0XD);
L_8001C6C4:
    // 0x8001C6C4: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x8001C6C8: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8001C6CC: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x8001C6D0: jal         0x8004C388
    // 0x8001C6D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004C388(rdram, ctx);
        goto after_48;
    // 0x8001C6D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_48:
    // 0x8001C6D8: lh          $t8, 0x0($s4)
    ctx->r24 = MEM_H(ctx->r20, 0X0);
    // 0x8001C6DC: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x8001C6E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8001C6E4: beq         $t8, $zero, L_8001C708
    if (ctx->r24 == 0) {
        // 0x8001C6E8: lui         $a2, 0x8007
        ctx->r6 = S32(0X8007 << 16);
            goto L_8001C708;
    }
    // 0x8001C6E8: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x8001C6EC: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x8001C6F0: addiu       $a2, $a2, 0x6570
    ctx->r6 = ADD32(ctx->r6, 0X6570);
    // 0x8001C6F4: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x8001C6F8: jal         0x8004BCF0
    // 0x8001C6FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004BCF0(rdram, ctx);
        goto after_49;
    // 0x8001C6FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_49:
    // 0x8001C700: b           L_8001C8E4
    // 0x8001C704: nop

        goto L_8001C8E4;
    // 0x8001C704: nop

L_8001C708:
    // 0x8001C708: jal         0x8004BCF0
    // 0x8001C70C: addiu       $a2, $a2, 0x6578
    ctx->r6 = ADD32(ctx->r6, 0X6578);
    func_8004BCF0(rdram, ctx);
        goto after_50;
    // 0x8001C70C: addiu       $a2, $a2, 0x6578
    ctx->r6 = ADD32(ctx->r6, 0X6578);
    after_50:
    // 0x8001C710: b           L_8001C8E4
    // 0x8001C714: nop

        goto L_8001C8E4;
    // 0x8001C714: nop

L_8001C718:
    // 0x8001C718: bnel        $t9, $zero, L_8001C734
    if (ctx->r25 != 0) {
        // 0x8001C71C: lh          $t7, 0x0($s2)
        ctx->r15 = MEM_H(ctx->r18, 0X0);
            goto L_8001C734;
    }
    goto skip_6;
    // 0x8001C71C: lh          $t7, 0x0($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X0);
    skip_6:
    // 0x8001C720: lh          $t5, 0x0($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X0);
    // 0x8001C724: andi        $t6, $t5, 0x300
    ctx->r14 = ctx->r13 & 0X300;
    // 0x8001C728: beql        $t6, $zero, L_8001C784
    if (ctx->r14 == 0) {
        // 0x8001C72C: addiu       $a1, $v1, 0xD
        ctx->r5 = ADD32(ctx->r3, 0XD);
            goto L_8001C784;
    }
    goto skip_7;
    // 0x8001C72C: addiu       $a1, $v1, 0xD
    ctx->r5 = ADD32(ctx->r3, 0XD);
    skip_7:
    // 0x8001C730: lh          $t7, 0x0($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X0);
L_8001C734:
    // 0x8001C734: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x8001C738: xori        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 ^ 0X1;
    // 0x8001C73C: jal         0x80044480
    // 0x8001C740: sh          $t8, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r24;
    func_80044480(rdram, ctx);
        goto after_51;
    // 0x8001C740: sh          $t8, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r24;
    after_51:
    // 0x8001C744: lh          $t9, 0x0($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X0);
    // 0x8001C748: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x8001C74C: beq         $t9, $zero, L_8001C774
    if (ctx->r25 == 0) {
        // 0x8001C750: nop
    
            goto L_8001C774;
    }
    // 0x8001C750: nop

    // 0x8001C754: lw          $t5, -0x6630($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X6630);
    // 0x8001C758: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x8001C75C: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x8001C760: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x8001C764: jal         0x80007EC8
    // 0x8001C768: lh          $a0, -0x6320($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X6320);
    func_80007EC8(rdram, ctx);
        goto after_52;
    // 0x8001C768: lh          $a0, -0x6320($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X6320);
    after_52:
    // 0x8001C76C: b           L_8001C780
    // 0x8001C770: lh          $v1, 0x74($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X74);
        goto L_8001C780;
    // 0x8001C770: lh          $v1, 0x74($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X74);
L_8001C774:
    // 0x8001C774: jal         0x80007E20
    // 0x8001C778: nop

    func_80007E20(rdram, ctx);
        goto after_53;
    // 0x8001C778: nop

    after_53:
    // 0x8001C77C: lh          $v1, 0x74($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X74);
L_8001C780:
    // 0x8001C780: addiu       $a1, $v1, 0xD
    ctx->r5 = ADD32(ctx->r3, 0XD);
L_8001C784:
    // 0x8001C784: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x8001C788: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8001C78C: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x8001C790: jal         0x8004C388
    // 0x8001C794: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004C388(rdram, ctx);
        goto after_54;
    // 0x8001C794: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_54:
    // 0x8001C798: lh          $t9, 0x0($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X0);
    // 0x8001C79C: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x8001C7A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8001C7A4: beq         $t9, $zero, L_8001C7C8
    if (ctx->r25 == 0) {
        // 0x8001C7A8: lui         $a2, 0x8007
        ctx->r6 = S32(0X8007 << 16);
            goto L_8001C7C8;
    }
    // 0x8001C7A8: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x8001C7AC: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x8001C7B0: addiu       $a2, $a2, 0x6580
    ctx->r6 = ADD32(ctx->r6, 0X6580);
    // 0x8001C7B4: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x8001C7B8: jal         0x8004BCF0
    // 0x8001C7BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004BCF0(rdram, ctx);
        goto after_55;
    // 0x8001C7BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_55:
    // 0x8001C7C0: b           L_8001C8E4
    // 0x8001C7C4: nop

        goto L_8001C8E4;
    // 0x8001C7C4: nop

L_8001C7C8:
    // 0x8001C7C8: jal         0x8004BCF0
    // 0x8001C7CC: addiu       $a2, $a2, 0x6584
    ctx->r6 = ADD32(ctx->r6, 0X6584);
    func_8004BCF0(rdram, ctx);
        goto after_56;
    // 0x8001C7CC: addiu       $a2, $a2, 0x6584
    ctx->r6 = ADD32(ctx->r6, 0X6584);
    after_56:
    // 0x8001C7D0: b           L_8001C8E4
    // 0x8001C7D4: nop

        goto L_8001C8E4;
    // 0x8001C7D4: nop

L_8001C7D8:
    // 0x8001C7D8: bnel        $t5, $zero, L_8001C7F4
    if (ctx->r13 != 0) {
        // 0x8001C7DC: lh          $t8, 0x0($s3)
        ctx->r24 = MEM_H(ctx->r19, 0X0);
            goto L_8001C7F4;
    }
    goto skip_8;
    // 0x8001C7DC: lh          $t8, 0x0($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X0);
    skip_8:
    // 0x8001C7E0: lh          $t6, 0x0($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X0);
    // 0x8001C7E4: andi        $t7, $t6, 0x300
    ctx->r15 = ctx->r14 & 0X300;
    // 0x8001C7E8: beql        $t7, $zero, L_8001C80C
    if (ctx->r15 == 0) {
        // 0x8001C7EC: addiu       $a1, $v1, 0xD
        ctx->r5 = ADD32(ctx->r3, 0XD);
            goto L_8001C80C;
    }
    goto skip_9;
    // 0x8001C7EC: addiu       $a1, $v1, 0xD
    ctx->r5 = ADD32(ctx->r3, 0XD);
    skip_9:
    // 0x8001C7F0: lh          $t8, 0x0($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X0);
L_8001C7F4:
    // 0x8001C7F4: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x8001C7F8: xori        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 ^ 0X1;
    // 0x8001C7FC: jal         0x80044480
    // 0x8001C800: sh          $t9, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r25;
    func_80044480(rdram, ctx);
        goto after_57;
    // 0x8001C800: sh          $t9, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r25;
    after_57:
    // 0x8001C804: lh          $v1, 0x74($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X74);
    // 0x8001C808: addiu       $a1, $v1, 0xD
    ctx->r5 = ADD32(ctx->r3, 0XD);
L_8001C80C:
    // 0x8001C80C: sll         $t5, $a1, 16
    ctx->r13 = S32(ctx->r5 << 16);
    // 0x8001C810: sra         $a1, $t5, 16
    ctx->r5 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8001C814: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x8001C818: jal         0x8004C388
    // 0x8001C81C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004C388(rdram, ctx);
        goto after_58;
    // 0x8001C81C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_58:
    // 0x8001C820: lh          $t7, 0x0($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X0);
    // 0x8001C824: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x8001C828: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8001C82C: beq         $t7, $zero, L_8001C850
    if (ctx->r15 == 0) {
        // 0x8001C830: lui         $a2, 0x8007
        ctx->r6 = S32(0X8007 << 16);
            goto L_8001C850;
    }
    // 0x8001C830: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x8001C834: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x8001C838: addiu       $a2, $a2, 0x6588
    ctx->r6 = ADD32(ctx->r6, 0X6588);
    // 0x8001C83C: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x8001C840: jal         0x8004BCF0
    // 0x8001C844: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004BCF0(rdram, ctx);
        goto after_59;
    // 0x8001C844: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_59:
    // 0x8001C848: b           L_8001C8E4
    // 0x8001C84C: nop

        goto L_8001C8E4;
    // 0x8001C84C: nop

L_8001C850:
    // 0x8001C850: jal         0x8004BCF0
    // 0x8001C854: addiu       $a2, $a2, 0x658C
    ctx->r6 = ADD32(ctx->r6, 0X658C);
    func_8004BCF0(rdram, ctx);
        goto after_60;
    // 0x8001C854: addiu       $a2, $a2, 0x658C
    ctx->r6 = ADD32(ctx->r6, 0X658C);
    after_60:
    // 0x8001C858: b           L_8001C8E4
    // 0x8001C85C: nop

        goto L_8001C8E4;
    // 0x8001C85C: nop

L_8001C860:
    // 0x8001C860: bnel        $t8, $zero, L_8001C87C
    if (ctx->r24 != 0) {
        // 0x8001C864: lw          $t6, 0x0($s5)
        ctx->r14 = MEM_W(ctx->r21, 0X0);
            goto L_8001C87C;
    }
    goto skip_10;
    // 0x8001C864: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    skip_10:
    // 0x8001C868: lh          $t9, 0x0($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X0);
    // 0x8001C86C: andi        $t5, $t9, 0x300
    ctx->r13 = ctx->r25 & 0X300;
    // 0x8001C870: beql        $t5, $zero, L_8001C894
    if (ctx->r13 == 0) {
        // 0x8001C874: addiu       $a1, $v1, 0xD
        ctx->r5 = ADD32(ctx->r3, 0XD);
            goto L_8001C894;
    }
    goto skip_11;
    // 0x8001C874: addiu       $a1, $v1, 0xD
    ctx->r5 = ADD32(ctx->r3, 0XD);
    skip_11:
    // 0x8001C878: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
L_8001C87C:
    // 0x8001C87C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x8001C880: xori        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 ^ 0X8000;
    // 0x8001C884: jal         0x80044480
    // 0x8001C888: sw          $t7, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r15;
    func_80044480(rdram, ctx);
        goto after_61;
    // 0x8001C888: sw          $t7, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r15;
    after_61:
    // 0x8001C88C: lh          $v1, 0x74($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X74);
    // 0x8001C890: addiu       $a1, $v1, 0xD
    ctx->r5 = ADD32(ctx->r3, 0XD);
L_8001C894:
    // 0x8001C894: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x8001C898: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8001C89C: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x8001C8A0: jal         0x8004C388
    // 0x8001C8A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004C388(rdram, ctx);
        goto after_62;
    // 0x8001C8A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_62:
    // 0x8001C8A8: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x8001C8AC: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x8001C8B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8001C8B4: andi        $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 & 0X8000;
    // 0x8001C8B8: beq         $t6, $zero, L_8001C8DC
    if (ctx->r14 == 0) {
        // 0x8001C8BC: lui         $a2, 0x8007
        ctx->r6 = S32(0X8007 << 16);
            goto L_8001C8DC;
    }
    // 0x8001C8BC: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x8001C8C0: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x8001C8C4: addiu       $a2, $a2, 0x6590
    ctx->r6 = ADD32(ctx->r6, 0X6590);
    // 0x8001C8C8: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x8001C8CC: jal         0x8004BCF0
    // 0x8001C8D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004BCF0(rdram, ctx);
        goto after_63;
    // 0x8001C8D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_63:
    // 0x8001C8D4: b           L_8001C8E4
    // 0x8001C8D8: nop

        goto L_8001C8E4;
    // 0x8001C8D8: nop

L_8001C8DC:
    // 0x8001C8DC: jal         0x8004BCF0
    // 0x8001C8E0: addiu       $a2, $a2, 0x6594
    ctx->r6 = ADD32(ctx->r6, 0X6594);
    func_8004BCF0(rdram, ctx);
        goto after_64;
    // 0x8001C8E0: addiu       $a2, $a2, 0x6594
    ctx->r6 = ADD32(ctx->r6, 0X6594);
    after_64:
L_8001C8E4:
    // 0x8001C8E4: jal         0x8000798C
    // 0x8001C8E8: nop

    func_8000798C(rdram, ctx);
        goto after_65;
    // 0x8001C8E8: nop

    after_65:
    // 0x8001C8EC: b           L_8001C638
    // 0x8001C8F0: nop

        goto L_8001C638;
    // 0x8001C8F0: nop

L_8001C8F4:
    // 0x8001C8F4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001C8F8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001C8FC: jal         0x8000798C
    // 0x8001C900: sh          $t7, -0x2D1E($at)
    MEM_H(-0X2D1E, ctx->r1) = ctx->r15;
    func_8000798C(rdram, ctx);
        goto after_66;
    // 0x8001C900: sh          $t7, -0x2D1E($at)
    MEM_H(-0X2D1E, ctx->r1) = ctx->r15;
    after_66:
    // 0x8001C904: jal         0x8000798C
    // 0x8001C908: nop

    func_8000798C(rdram, ctx);
        goto after_67;
    // 0x8001C908: nop

    after_67:
    // 0x8001C90C: jal         0x8000798C
    // 0x8001C910: nop

    func_8000798C(rdram, ctx);
        goto after_68;
    // 0x8001C910: nop

    after_68:
    // 0x8001C914: lw          $t8, 0x114($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X114);
    // 0x8001C918: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001C91C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8001C920: beq         $t8, $zero, L_8001C93C
    if (ctx->r24 == 0) {
        // 0x8001C924: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8001C93C;
    }
    // 0x8001C924: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001C928: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
L_8001C92C:
    // 0x8001C92C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8001C930: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8001C934: bnel        $t9, $zero, L_8001C92C
    if (ctx->r25 != 0) {
        // 0x8001C938: lw          $t9, 0x4($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X4);
            goto L_8001C92C;
    }
    goto skip_12;
    // 0x8001C938: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    skip_12:
L_8001C93C:
    // 0x8001C93C: jal         0x8001A37C
    // 0x8001C940: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8001A37C(rdram, ctx);
        goto after_69;
    // 0x8001C940: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_69:
    // 0x8001C944: lh          $v1, 0x74($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X74);
    // 0x8001C948: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8001C94C: bne         $v1, $at, L_8001C964
    if (ctx->r3 != ctx->r1) {
        // 0x8001C950: nop
    
            goto L_8001C964;
    }
    // 0x8001C950: nop

    // 0x8001C954: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x8001C958: ori         $t6, $t5, 0x20
    ctx->r14 = ctx->r13 | 0X20;
    // 0x8001C95C: b           L_8001C97C
    // 0x8001C960: sw          $t6, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r14;
        goto L_8001C97C;
    // 0x8001C960: sw          $t6, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r14;
L_8001C964:
    // 0x8001C964: jal         0x80044480
    // 0x8001C968: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    func_80044480(rdram, ctx);
        goto after_70;
    // 0x8001C968: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_70:
    // 0x8001C96C: lw          $t7, 0x1A8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1A8);
L_8001C970:
    // 0x8001C970: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001C974: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8001C978: bne         $t8, $at, L_8001CBDC
    if (ctx->r24 != ctx->r1) {
        // 0x8001C97C: addiu       $a0, $zero, 0xF
        ctx->r4 = ADD32(0, 0XF);
            goto L_8001CBDC;
    }
L_8001C97C:
    // 0x8001C97C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
L_8001C980:
    // 0x8001C980: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001C984: jal         0x8004D134
    // 0x8001C988: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_8004D134(rdram, ctx);
        goto after_71;
    // 0x8001C988: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_71:
L_8001C98C:
    // 0x8001C98C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001C990: jal         0x8004D1F0
    // 0x8001C994: sh          $zero, -0x6B94($at)
    MEM_H(-0X6B94, ctx->r1) = 0;
    func_8004D1F0(rdram, ctx);
        goto after_72;
    // 0x8001C994: sh          $zero, -0x6B94($at)
    MEM_H(-0X6B94, ctx->r1) = 0;
    after_72:
    // 0x8001C998: beql        $v0, $zero, L_8001C9BC
    if (ctx->r2 == 0) {
        // 0x8001C99C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8001C9BC;
    }
    goto skip_13;
    // 0x8001C99C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_13:
L_8001C9A0:
    // 0x8001C9A0: jal         0x8000798C
    // 0x8001C9A4: nop

    func_8000798C(rdram, ctx);
        goto after_73;
    // 0x8001C9A4: nop

    after_73:
    // 0x8001C9A8: jal         0x8004D1F0
    // 0x8001C9AC: nop

    func_8004D1F0(rdram, ctx);
        goto after_74;
    // 0x8001C9AC: nop

    after_74:
    // 0x8001C9B0: bne         $v0, $zero, L_8001C9A0
    if (ctx->r2 != 0) {
        // 0x8001C9B4: nop
    
            goto L_8001C9A0;
    }
    // 0x8001C9B4: nop

    // 0x8001C9B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8001C9BC:
    // 0x8001C9BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001C9C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001C9C4: jal         0x8000BD4C
    // 0x8001C9C8: addiu       $s0, $sp, 0x114
    ctx->r16 = ADD32(ctx->r29, 0X114);
    func_8000BD4C(rdram, ctx);
        goto after_75;
    // 0x8001C9C8: addiu       $s0, $sp, 0x114
    ctx->r16 = ADD32(ctx->r29, 0X114);
    after_75:
    // 0x8001C9CC: lw          $t9, 0x114($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X114);
    // 0x8001C9D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001C9D4: sh          $zero, -0x2CC4($at)
    MEM_H(-0X2CC4, ctx->r1) = 0;
    // 0x8001C9D8: beq         $t9, $zero, L_8001CA04
    if (ctx->r25 == 0) {
        // 0x8001C9DC: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8001CA04;
    }
    // 0x8001C9DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001C9E0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8001C9E4:
    // 0x8001C9E4: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x8001C9E8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001C9EC: sll         $t5, $a2, 16
    ctx->r13 = S32(ctx->r6 << 16);
    // 0x8001C9F0: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8001C9F4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8001C9F8: bne         $t7, $zero, L_8001C9E4
    if (ctx->r15 != 0) {
        // 0x8001C9FC: sra         $a2, $t5, 16
        ctx->r6 = S32(SIGNED(ctx->r13) >> 16);
            goto L_8001C9E4;
    }
    // 0x8001C9FC: sra         $a2, $t5, 16
    ctx->r6 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8001CA00: addiu       $s0, $sp, 0x114
    ctx->r16 = ADD32(ctx->r29, 0X114);
L_8001CA04:
    // 0x8001CA04: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001CA08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8001CA0C:
    // 0x8001CA0C: sw          $v1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r3;
    // 0x8001CA10: sw          $a1, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r5;
    // 0x8001CA14: jal         0x8000798C
    // 0x8001CA18: sh          $a2, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r6;
    func_8000798C(rdram, ctx);
        goto after_76;
    // 0x8001CA18: sh          $a2, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r6;
    after_76:
    // 0x8001CA1C: lh          $a2, 0x82($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X82);
    // 0x8001CA20: lw          $v1, 0x7C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X7C);
    // 0x8001CA24: lw          $a1, 0x1A4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1A4);
    // 0x8001CA28: blez        $a2, L_8001CA80
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8001CA2C: andi        $v0, $a2, 0x3
        ctx->r2 = ctx->r6 & 0X3;
            goto L_8001CA80;
    }
    // 0x8001CA2C: andi        $v0, $a2, 0x3
    ctx->r2 = ctx->r6 & 0X3;
    // 0x8001CA30: beq         $v0, $zero, L_8001CA54
    if (ctx->r2 == 0) {
        // 0x8001CA34: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8001CA54;
    }
    // 0x8001CA34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8001CA38:
    // 0x8001CA38: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8001CA3C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001CA40: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8001CA44: bne         $a0, $a1, L_8001CA38
    if (ctx->r4 != ctx->r5) {
        // 0x8001CA48: or          $v1, $v1, $v0
        ctx->r3 = ctx->r3 | ctx->r2;
            goto L_8001CA38;
    }
    // 0x8001CA48: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8001CA4C: beq         $a1, $a2, L_8001CA80
    if (ctx->r5 == ctx->r6) {
        // 0x8001CA50: nop
    
            goto L_8001CA80;
    }
    // 0x8001CA50: nop

L_8001CA54:
    // 0x8001CA54: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8001CA58: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8001CA5C: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8001CA60: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8001CA64: lw          $v0, -0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, -0XC);
    // 0x8001CA68: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8001CA6C: lw          $v0, -0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, -0X8);
    // 0x8001CA70: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8001CA74: lw          $v0, -0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, -0X4);
    // 0x8001CA78: bne         $a1, $a2, L_8001CA54
    if (ctx->r5 != ctx->r6) {
        // 0x8001CA7C: or          $v1, $v1, $v0
        ctx->r3 = ctx->r3 | ctx->r2;
            goto L_8001CA54;
    }
    // 0x8001CA7C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_8001CA80:
    // 0x8001CA80: bne         $v1, $zero, L_8001CA90
    if (ctx->r3 != 0) {
        // 0x8001CA84: addiu       $s0, $sp, 0x114
        ctx->r16 = ADD32(ctx->r29, 0X114);
            goto L_8001CA90;
    }
    // 0x8001CA84: addiu       $s0, $sp, 0x114
    ctx->r16 = ADD32(ctx->r29, 0X114);
    // 0x8001CA88: b           L_8001CA9C
    // 0x8001CA8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_8001CA9C;
    // 0x8001CA8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8001CA90:
    // 0x8001CA90: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001CA94: b           L_8001CA0C
    // 0x8001CA98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_8001CA0C;
    // 0x8001CA98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8001CA9C:
    // 0x8001CA9C: blez        $a2, L_8001CAD4
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8001CAA0: addiu       $t0, $sp, 0x90
        ctx->r8 = ADD32(ctx->r29, 0X90);
            goto L_8001CAD4;
    }
    // 0x8001CAA0: addiu       $t0, $sp, 0x90
    ctx->r8 = ADD32(ctx->r29, 0X90);
    // 0x8001CAA4: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
L_8001CAA8:
    // 0x8001CAA8: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8001CAAC: sw          $t0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r8;
    // 0x8001CAB0: sh          $a2, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r6;
    // 0x8001CAB4: jal         0x80004E5C
    // 0x8001CAB8: sw          $a1, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r5;
    func_80004E5C(rdram, ctx);
        goto after_77;
    // 0x8001CAB8: sw          $a1, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r5;
    after_77:
    // 0x8001CABC: lw          $a1, 0x1A4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1A4);
    // 0x8001CAC0: lh          $a2, 0x82($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X82);
    // 0x8001CAC4: lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8C);
    // 0x8001CAC8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001CACC: bnel        $a1, $a2, L_8001CAA8
    if (ctx->r5 != ctx->r6) {
        // 0x8001CAD0: lw          $a0, 0x0($t0)
        ctx->r4 = MEM_W(ctx->r8, 0X0);
            goto L_8001CAA8;
    }
    goto skip_14;
    // 0x8001CAD0: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    skip_14:
L_8001CAD4:
    // 0x8001CAD4: jal         0x8000798C
    // 0x8001CAD8: nop

    func_8000798C(rdram, ctx);
        goto after_78;
    // 0x8001CAD8: nop

    after_78:
    // 0x8001CADC: jal         0x80007E20
    // 0x8001CAE0: nop

    func_80007E20(rdram, ctx);
        goto after_79;
    // 0x8001CAE0: nop

    after_79:
    // 0x8001CAE4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001CAE8: sh          $zero, -0x2CC2($at)
    MEM_H(-0X2CC2, ctx->r1) = 0;
    // 0x8001CAEC: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x8001CAF0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8001CAF4: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8001CAF8: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
    // 0x8001CAFC: beq         $t8, $zero, L_8001CB20
    if (ctx->r24 == 0) {
        // 0x8001CB00: andi        $t6, $v0, 0x2
        ctx->r14 = ctx->r2 & 0X2;
            goto L_8001CB20;
    }
    // 0x8001CB00: andi        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 & 0X2;
    // 0x8001CB04: jal         0x800042A8
    // 0x8001CB08: lw          $a1, 0x1A0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1A0);
    func_800042A8(rdram, ctx);
        goto after_80;
    // 0x8001CB08: lw          $a1, 0x1A0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1A0);
    after_80:
    // 0x8001CB0C: lw          $t9, 0x0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X0);
    // 0x8001CB10: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x8001CB14: and         $t5, $t9, $at
    ctx->r13 = ctx->r25 & ctx->r1;
    // 0x8001CB18: b           L_8001CB80
    // 0x8001CB1C: sw          $t5, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r13;
        goto L_8001CB80;
    // 0x8001CB1C: sw          $t5, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r13;
L_8001CB20:
    // 0x8001CB20: beq         $t6, $zero, L_8001CB80
    if (ctx->r14 == 0) {
        // 0x8001CB24: andi        $t7, $v0, 0x8
        ctx->r15 = ctx->r2 & 0X8;
            goto L_8001CB80;
    }
    // 0x8001CB24: andi        $t7, $v0, 0x8
    ctx->r15 = ctx->r2 & 0X8;
    // 0x8001CB28: beq         $t7, $zero, L_8001CB64
    if (ctx->r15 == 0) {
        // 0x8001CB2C: lui         $a0, 0x801A
        ctx->r4 = S32(0X801A << 16);
            goto L_8001CB64;
    }
    // 0x8001CB2C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8001CB30: lw          $v0, 0x19C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X19C);
    // 0x8001CB34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001CB38: blez        $v0, L_8001CB64
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001CB3C: andi        $t1, $v0, 0x3
        ctx->r9 = ctx->r2 & 0X3;
            goto L_8001CB64;
    }
    // 0x8001CB3C: andi        $t1, $v0, 0x3
    ctx->r9 = ctx->r2 & 0X3;
    // 0x8001CB40: beq         $t1, $zero, L_8001CB58
    if (ctx->r9 == 0) {
        // 0x8001CB44: or          $a3, $t1, $zero
        ctx->r7 = ctx->r9 | 0;
            goto L_8001CB58;
    }
    // 0x8001CB44: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x8001CB48: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8001CB4C:
    // 0x8001CB4C: bnel        $a3, $a1, L_8001CB4C
    if (ctx->r7 != ctx->r5) {
        // 0x8001CB50: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8001CB4C;
    }
    goto skip_15;
    // 0x8001CB50: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_15:
    // 0x8001CB54: beq         $a1, $v0, L_8001CB64
    if (ctx->r5 == ctx->r2) {
        // 0x8001CB58: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8001CB64;
    }
L_8001CB58:
    // 0x8001CB58: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_8001CB5C:
    // 0x8001CB5C: bnel        $a1, $v0, L_8001CB5C
    if (ctx->r5 != ctx->r2) {
        // 0x8001CB60: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8001CB5C;
    }
    goto skip_16;
    // 0x8001CB60: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    skip_16:
L_8001CB64:
    // 0x8001CB64: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8001CB68: jal         0x800042A8
    // 0x8001CB6C: lw          $a1, 0x1A0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1A0);
    func_800042A8(rdram, ctx);
        goto after_81;
    // 0x8001CB6C: lw          $a1, 0x1A0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1A0);
    after_81:
    // 0x8001CB70: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    // 0x8001CB74: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8001CB78: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8001CB7C: sw          $t9, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r25;
L_8001CB80:
    // 0x8001CB80: addiu       $t4, $zero, 0xE10
    ctx->r12 = ADD32(0, 0XE10);
    // 0x8001CB84: andi        $t1, $t4, 0x3
    ctx->r9 = ctx->r12 & 0X3;
    // 0x8001CB88: andi        $v0, $zero, 0x3
    ctx->r2 = 0 & 0X3;
    // 0x8001CB8C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001CB90: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x8001CB94: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8001CB98: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8001CB9C: addiu       $s0, $sp, 0x114
    ctx->r16 = ADD32(ctx->r29, 0X114);
    // 0x8001CBA0: addiu       $t0, $sp, 0x90
    ctx->r8 = ADD32(ctx->r29, 0X90);
    // 0x8001CBA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001CBA8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001CBAC: jal         0x80049C48
    // 0x8001CBB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80049C48(rdram, ctx);
        goto after_82;
    // 0x8001CBB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_82:
    // 0x8001CBB4: jal         0x8000798C
    // 0x8001CBB8: nop

    func_8000798C(rdram, ctx);
        goto after_83;
    // 0x8001CBB8: nop

    after_83:
    // 0x8001CBBC: lw          $t5, 0x1A8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1A8);
    // 0x8001CBC0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001CBC4: sh          $zero, 0x6AD2($at)
    MEM_H(0X6AD2, ctx->r1) = 0;
    // 0x8001CBC8: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
L_8001CBCC:
    // 0x8001CBCC: jal         0x8000798C
    // 0x8001CBD0: nop

    func_8000798C(rdram, ctx);
        goto after_84;
    // 0x8001CBD0: nop

    after_84:
    // 0x8001CBD4: b           L_8001CBCC
    // 0x8001CBD8: nop

        goto L_8001CBCC;
    // 0x8001CBD8: nop

L_8001CBDC:
    // 0x8001CBDC: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x8001CBE0: andi        $t6, $v0, 0x20
    ctx->r14 = ctx->r2 & 0X20;
    // 0x8001CBE4: bne         $t6, $zero, L_8001C97C
    if (ctx->r14 != 0) {
        // 0x8001CBE8: andi        $t7, $v0, 0x200
        ctx->r15 = ctx->r2 & 0X200;
            goto L_8001C97C;
    }
    // 0x8001CBE8: andi        $t7, $v0, 0x200
    ctx->r15 = ctx->r2 & 0X200;
    // 0x8001CBEC: bne         $t7, $zero, L_8001CBFC
    if (ctx->r15 != 0) {
        // 0x8001CBF0: nop
    
            goto L_8001CBFC;
    }
    // 0x8001CBF0: nop

    // 0x8001CBF4: jal         0x80035904
    // 0x8001CBF8: nop

    func_80035904(rdram, ctx);
        goto after_85;
    // 0x8001CBF8: nop

    after_85:
L_8001CBFC:
    // 0x8001CBFC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8001CC00: lh          $t8, -0x6B8E($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X6B8E);
    // 0x8001CC04: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001CC08: addiu       $v0, $v0, -0x6B8C
    ctx->r2 = ADD32(ctx->r2, -0X6B8C);
    // 0x8001CC0C: beql        $t8, $zero, L_8001CC5C
    if (ctx->r24 == 0) {
        // 0x8001CC10: lw          $v0, 0x0($s5)
        ctx->r2 = MEM_W(ctx->r21, 0X0);
            goto L_8001CC5C;
    }
    goto skip_17;
    // 0x8001CC10: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    skip_17:
    // 0x8001CC14: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x8001CC18: addiu       $a0, $zero, -0x50
    ctx->r4 = ADD32(0, -0X50);
    // 0x8001CC1C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8001CC20: addiu       $t5, $t9, -0x1
    ctx->r13 = ADD32(ctx->r25, -0X1);
    // 0x8001CC24: sh          $t5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r13;
    // 0x8001CC28: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8001CC2C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8001CC30: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x8001CC34: bnel        $t6, $zero, L_8001CC5C
    if (ctx->r14 != 0) {
        // 0x8001CC38: lw          $v0, 0x0($s5)
        ctx->r2 = MEM_W(ctx->r21, 0X0);
            goto L_8001CC5C;
    }
    goto skip_18;
    // 0x8001CC38: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    skip_18:
    // 0x8001CC3C: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x8001CC40: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8001CC44: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8001CC48: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x8001CC4C: sw          $t8, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r24;
    // 0x8001CC50: jal         0x8001BC50
    // 0x8001CC54: lw          $a2, -0x6BDC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X6BDC);
    func_8001BC50(rdram, ctx);
        goto after_86;
    // 0x8001CC54: lw          $a2, -0x6BDC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X6BDC);
    after_86:
    // 0x8001CC58: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
L_8001CC5C:
    // 0x8001CC5C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8001CC60: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8001CC64: andi        $t5, $v0, 0x80
    ctx->r13 = ctx->r2 & 0X80;
    // 0x8001CC68: beq         $t5, $zero, L_8001CD94
    if (ctx->r13 == 0) {
        // 0x8001CC6C: andi        $t6, $v0, 0x4
        ctx->r14 = ctx->r2 & 0X4;
            goto L_8001CD94;
    }
    // 0x8001CC6C: andi        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 & 0X4;
    // 0x8001CC70: andi        $t6, $v0, 0x100
    ctx->r14 = ctx->r2 & 0X100;
    // 0x8001CC74: bnel        $t6, $zero, L_8001CC88
    if (ctx->r14 != 0) {
        // 0x8001CC78: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8001CC88;
    }
    goto skip_19;
    // 0x8001CC78: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    skip_19:
    // 0x8001CC7C: jal         0x8002421C
    // 0x8001CC80: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002421C(rdram, ctx);
        goto after_87;
    // 0x8001CC80: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_87:
    // 0x8001CC84: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_8001CC88:
    // 0x8001CC88: lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // 0x8001CC8C: addiu       $a0, $a0, 0x6950
    ctx->r4 = ADD32(ctx->r4, 0X6950);
    // 0x8001CC90: sw          $t7, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r15;
    // 0x8001CC94: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x8001CC98: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8001CC9C: jal         0x80004CE0
    // 0x8001CCA0: addiu       $a3, $sp, 0x88
    ctx->r7 = ADD32(ctx->r29, 0X88);
    func_80004CE0(rdram, ctx);
        goto after_88;
    // 0x8001CCA0: addiu       $a3, $sp, 0x88
    ctx->r7 = ADD32(ctx->r29, 0X88);
    after_88:
    // 0x8001CCA4: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    // 0x8001CCA8: lw          $t5, 0x88($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X88);
    // 0x8001CCAC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8001CCB0: ori         $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 | 0X8000;
    // 0x8001CCB4: beq         $t5, $zero, L_8001CD7C
    if (ctx->r13 == 0) {
        // 0x8001CCB8: sw          $t9, 0x0($s5)
        MEM_W(0X0, ctx->r21) = ctx->r25;
            goto L_8001CD7C;
    }
    // 0x8001CCB8: sw          $t9, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r25;
    // 0x8001CCBC: addiu       $s2, $zero, 0x900
    ctx->r18 = ADD32(0, 0X900);
    // 0x8001CCC0: addiu       $s1, $zero, 0x9
    ctx->r17 = ADD32(0, 0X9);
    // 0x8001CCC4: addiu       $s0, $zero, 0x3C
    ctx->r16 = ADD32(0, 0X3C);
    // 0x8001CCC8: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
L_8001CCCC:
    // 0x8001CCCC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001CCD0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8001CCD4: andi        $t7, $t6, 0x100
    ctx->r15 = ctx->r14 & 0X100;
    // 0x8001CCD8: beq         $t7, $zero, L_8001CD00
    if (ctx->r15 == 0) {
        // 0x8001CCDC: nop
    
            goto L_8001CD00;
    }
    // 0x8001CCDC: nop

    // 0x8001CCE0: sh          $zero, -0x2E44($at)
    MEM_H(-0X2E44, ctx->r1) = 0;
    // 0x8001CCE4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001CCE8: sh          $zero, -0x2E46($at)
    MEM_H(-0X2E46, ctx->r1) = 0;
    // 0x8001CCEC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001CCF0: sb          $zero, -0x2E47($at)
    MEM_B(-0X2E47, ctx->r1) = 0;
    // 0x8001CCF4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001CCF8: b           L_8001CD68
    // 0x8001CCFC: sb          $zero, -0x2E48($at)
    MEM_B(-0X2E48, ctx->r1) = 0;
        goto L_8001CD68;
    // 0x8001CCFC: sb          $zero, -0x2E48($at)
    MEM_B(-0X2E48, ctx->r1) = 0;
L_8001CD00:
    // 0x8001CD00: lw          $t8, -0x6630($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6630);
    // 0x8001CD04: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001CD08: bne         $t8, $at, L_8001CD30
    if (ctx->r24 != ctx->r1) {
        // 0x8001CD0C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8001CD30;
    }
    // 0x8001CD0C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001CD10: sb          $zero, -0x2E48($at)
    MEM_B(-0X2E48, ctx->r1) = 0;
    // 0x8001CD14: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001CD18: sb          $zero, -0x2E47($at)
    MEM_B(-0X2E47, ctx->r1) = 0;
    // 0x8001CD1C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001CD20: sh          $zero, -0x2E46($at)
    MEM_H(-0X2E46, ctx->r1) = 0;
    // 0x8001CD24: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001CD28: b           L_8001CD68
    // 0x8001CD2C: sh          $zero, -0x2E44($at)
    MEM_H(-0X2E44, ctx->r1) = 0;
        goto L_8001CD68;
    // 0x8001CD2C: sh          $zero, -0x2E44($at)
    MEM_H(-0X2E44, ctx->r1) = 0;
L_8001CD30:
    // 0x8001CD30: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001CD34: sb          $s0, -0x2E48($at)
    MEM_B(-0X2E48, ctx->r1) = ctx->r16;
    // 0x8001CD38: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001CD3C: sb          $zero, -0x2E47($at)
    MEM_B(-0X2E47, ctx->r1) = 0;
    // 0x8001CD40: lh          $t9, 0x0($s4)
    ctx->r25 = MEM_H(ctx->r20, 0X0);
    // 0x8001CD44: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001CD48: beq         $t9, $zero, L_8001CD5C
    if (ctx->r25 == 0) {
        // 0x8001CD4C: nop
    
            goto L_8001CD5C;
    }
    // 0x8001CD4C: nop

    // 0x8001CD50: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001CD54: b           L_8001CD60
    // 0x8001CD58: sh          $s1, -0x2E46($at)
    MEM_H(-0X2E46, ctx->r1) = ctx->r17;
        goto L_8001CD60;
    // 0x8001CD58: sh          $s1, -0x2E46($at)
    MEM_H(-0X2E46, ctx->r1) = ctx->r17;
L_8001CD5C:
    // 0x8001CD5C: sh          $s2, -0x2E46($at)
    MEM_H(-0X2E46, ctx->r1) = ctx->r18;
L_8001CD60:
    // 0x8001CD60: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001CD64: sh          $zero, -0x2E44($at)
    MEM_H(-0X2E44, ctx->r1) = 0;
L_8001CD68:
    // 0x8001CD68: jal         0x8000798C
    // 0x8001CD6C: nop

    func_8000798C(rdram, ctx);
        goto after_89;
    // 0x8001CD6C: nop

    after_89:
    // 0x8001CD70: lw          $t5, 0x88($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X88);
    // 0x8001CD74: bnel        $t5, $zero, L_8001CCCC
    if (ctx->r13 != 0) {
        // 0x8001CD78: lw          $t6, 0x0($s5)
        ctx->r14 = MEM_W(ctx->r21, 0X0);
            goto L_8001CCCC;
    }
    goto skip_20;
    // 0x8001CD78: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    skip_20:
L_8001CD7C:
    // 0x8001CD7C: jal         0x80004E5C
    // 0x8001CD80: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80004E5C(rdram, ctx);
        goto after_90;
    // 0x8001CD80: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_90:
    // 0x8001CD84: jal         0x8000798C
    // 0x8001CD88: nop

    func_8000798C(rdram, ctx);
        goto after_91;
    // 0x8001CD88: nop

    after_91:
    // 0x8001CD8C: b           L_8001C980
    // 0x8001CD90: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
        goto L_8001C980;
    // 0x8001CD90: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
L_8001CD94:
    // 0x8001CD94: beq         $t6, $zero, L_8001CE4C
    if (ctx->r14 == 0) {
        // 0x8001CD98: andi        $v1, $v0, 0x2
        ctx->r3 = ctx->r2 & 0X2;
            goto L_8001CE4C;
    }
    // 0x8001CD98: andi        $v1, $v0, 0x2
    ctx->r3 = ctx->r2 & 0X2;
    // 0x8001CD9C: lw          $v1, 0x198($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X198);
    // 0x8001CDA0: lw          $t8, 0x1A0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A0);
    // 0x8001CDA4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001CDA8: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8001CDAC: subu        $t7, $t7, $v1
    ctx->r15 = SUB32(ctx->r15, ctx->r3);
    // 0x8001CDB0: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8001CDB4: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8001CDB8: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x8001CDBC: lw          $t8, 0x19C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X19C);
    // 0x8001CDC0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001CDC4: sb          $t9, -0x2E48($at)
    MEM_B(-0X2E48, ctx->r1) = ctx->r25;
    // 0x8001CDC8: lbu         $t5, 0x1($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X1);
    // 0x8001CDCC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001CDD0: addiu       $t9, $v1, 0x64
    ctx->r25 = ADD32(ctx->r3, 0X64);
    // 0x8001CDD4: sb          $t5, -0x2E47($at)
    MEM_B(-0X2E47, ctx->r1) = ctx->r13;
    // 0x8001CDD8: lhu         $t6, 0x2($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X2);
    // 0x8001CDDC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001CDE0: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x8001CDE4: sh          $t6, -0x2E46($at)
    MEM_H(-0X2E46, ctx->r1) = ctx->r14;
    // 0x8001CDE8: lhu         $t7, 0x4($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X4);
    // 0x8001CDEC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001CDF0: sw          $v1, 0x198($sp)
    MEM_W(0X198, ctx->r29) = ctx->r3;
    // 0x8001CDF4: bne         $t8, $t9, L_8001CE08
    if (ctx->r24 != ctx->r25) {
        // 0x8001CDF8: sh          $t7, -0x2E44($at)
        MEM_H(-0X2E44, ctx->r1) = ctx->r15;
            goto L_8001CE08;
    }
    // 0x8001CDF8: sh          $t7, -0x2E44($at)
    MEM_H(-0X2E44, ctx->r1) = ctx->r15;
    // 0x8001CDFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001CE00: jal         0x8004D134
    // 0x8001CE04: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_8004D134(rdram, ctx);
        goto after_92;
    // 0x8001CE04: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_92:
L_8001CE08:
    // 0x8001CE08: lw          $t6, 0x19C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X19C);
    // 0x8001CE0C: lw          $t5, 0x198($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X198);
    // 0x8001CE10: addiu       $t7, $t6, -0x64
    ctx->r15 = ADD32(ctx->r14, -0X64);
    // 0x8001CE14: slt         $at, $t7, $t5
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8001CE18: beql        $at, $zero, L_8001CE44
    if (ctx->r1 == 0) {
        // 0x8001CE1C: lw          $v0, 0x0($s5)
        ctx->r2 = MEM_W(ctx->r21, 0X0);
            goto L_8001CE44;
    }
    goto skip_21;
    // 0x8001CE1C: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    skip_21:
    // 0x8001CE20: jal         0x8004D1F0
    // 0x8001CE24: nop

    func_8004D1F0(rdram, ctx);
        goto after_93;
    // 0x8001CE24: nop

    after_93:
    // 0x8001CE28: bnel        $v0, $zero, L_8001CE44
    if (ctx->r2 != 0) {
        // 0x8001CE2C: lw          $v0, 0x0($s5)
        ctx->r2 = MEM_W(ctx->r21, 0X0);
            goto L_8001CE44;
    }
    goto skip_22;
    // 0x8001CE2C: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    skip_22:
    // 0x8001CE30: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    // 0x8001CE34: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x8001CE38: b           L_8001C98C
    // 0x8001CE3C: sw          $t9, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r25;
        goto L_8001C98C;
    // 0x8001CE3C: sw          $t9, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r25;
    // 0x8001CE40: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
L_8001CE44:
    // 0x8001CE44: b           L_8001CEB0
    // 0x8001CE48: andi        $v1, $v0, 0x2
    ctx->r3 = ctx->r2 & 0X2;
        goto L_8001CEB0;
    // 0x8001CE48: andi        $v1, $v0, 0x2
    ctx->r3 = ctx->r2 & 0X2;
L_8001CE4C:
    // 0x8001CE4C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8001CE50: lh          $t6, -0x2E60($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X2E60);
    // 0x8001CE54: lh          $t7, -0x2E5E($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X2E5E);
    // 0x8001CE58: lhu         $t9, -0x2E5C($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X2E5C);
    // 0x8001CE5C: bgez        $t6, L_8001CE6C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8001CE60: sra         $t5, $t6, 3
        ctx->r13 = S32(SIGNED(ctx->r14) >> 3);
            goto L_8001CE6C;
    }
    // 0x8001CE60: sra         $t5, $t6, 3
    ctx->r13 = S32(SIGNED(ctx->r14) >> 3);
    // 0x8001CE64: addiu       $at, $t6, 0x7
    ctx->r1 = ADD32(ctx->r14, 0X7);
    // 0x8001CE68: sra         $t5, $at, 3
    ctx->r13 = S32(SIGNED(ctx->r1) >> 3);
L_8001CE6C:
    // 0x8001CE6C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001CE70: sb          $t5, -0x2E48($at)
    MEM_B(-0X2E48, ctx->r1) = ctx->r13;
    // 0x8001CE74: bgez        $t7, L_8001CE84
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8001CE78: sra         $t8, $t7, 3
        ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
            goto L_8001CE84;
    }
    // 0x8001CE78: sra         $t8, $t7, 3
    ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
    // 0x8001CE7C: addiu       $at, $t7, 0x7
    ctx->r1 = ADD32(ctx->r15, 0X7);
    // 0x8001CE80: sra         $t8, $at, 3
    ctx->r24 = S32(SIGNED(ctx->r1) >> 3);
L_8001CE84:
    // 0x8001CE84: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001CE88: sb          $t8, -0x2E47($at)
    MEM_B(-0X2E47, ctx->r1) = ctx->r24;
    // 0x8001CE8C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001CE90: sh          $t9, -0x2E46($at)
    MEM_H(-0X2E46, ctx->r1) = ctx->r25;
    // 0x8001CE94: lhu         $t6, 0x0($s6)
    ctx->r14 = MEM_HU(ctx->r22, 0X0);
    // 0x8001CE98: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8001CE9C: lhu         $t5, -0x2E58($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X2E58);
    // 0x8001CEA0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001CEA4: sh          $t6, -0x2E44($at)
    MEM_H(-0X2E44, ctx->r1) = ctx->r14;
    // 0x8001CEA8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001CEAC: sh          $t5, -0x2E42($at)
    MEM_H(-0X2E42, ctx->r1) = ctx->r13;
L_8001CEB0:
    // 0x8001CEB0: beq         $v1, $zero, L_8001CF9C
    if (ctx->r3 == 0) {
        // 0x8001CEB4: andi        $t7, $v0, 0x8
        ctx->r15 = ctx->r2 & 0X8;
            goto L_8001CF9C;
    }
    // 0x8001CEB4: andi        $t7, $v0, 0x8
    ctx->r15 = ctx->r2 & 0X8;
    // 0x8001CEB8: bne         $t7, $zero, L_8001CF9C
    if (ctx->r15 != 0) {
        // 0x8001CEBC: lw          $t8, 0x1A0($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X1A0);
            goto L_8001CF9C;
    }
    // 0x8001CEBC: lw          $t8, 0x1A0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A0);
    // 0x8001CEC0: lw          $t9, 0x198($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X198);
    // 0x8001CEC4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8001CEC8: lb          $t5, -0x2E48($t5)
    ctx->r13 = MEM_B(ctx->r13, -0X2E48);
    // 0x8001CECC: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8001CED0: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x8001CED4: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8001CED8: addu        $v0, $t8, $t6
    ctx->r2 = ADD32(ctx->r24, ctx->r14);
    // 0x8001CEDC: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8001CEE0: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
    // 0x8001CEE4: lb          $t7, -0x2E47($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X2E47);
    // 0x8001CEE8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8001CEEC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8001CEF0: sb          $t7, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r15;
    // 0x8001CEF4: lhu         $t9, -0x2E46($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X2E46);
    // 0x8001CEF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001CEFC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8001CF00: sh          $t9, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r25;
    // 0x8001CF04: lhu         $t8, -0x2E44($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X2E44);
    // 0x8001CF08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8001CF0C: sh          $t8, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r24;
    // 0x8001CF10: lw          $t5, 0x198($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X198);
    // 0x8001CF14: lw          $t6, 0x19C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X19C);
    // 0x8001CF18: jal         0x8004C388
    // 0x8001CF1C: subu        $s0, $t6, $t5
    ctx->r16 = SUB32(ctx->r14, ctx->r13);
    func_8004C388(rdram, ctx);
        goto after_94;
    // 0x8001CF1C: subu        $s0, $t6, $t5
    ctx->r16 = SUB32(ctx->r14, ctx->r13);
    after_94:
    // 0x8001CF20: addiu       $v0, $zero, 0x708
    ctx->r2 = ADD32(0, 0X708);
    // 0x8001CF24: div         $zero, $s0, $v0
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r2)));
    // 0x8001CF28: mfhi        $t7
    ctx->r15 = hi;
    // 0x8001CF2C: mflo        $a3
    ctx->r7 = lo;
    // 0x8001CF30: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x8001CF34: addiu       $a2, $a2, 0x6598
    ctx->r6 = ADD32(ctx->r6, 0X6598);
    // 0x8001CF38: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x8001CF3C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8001CF40: bne         $v0, $zero, L_8001CF4C
    if (ctx->r2 != 0) {
        // 0x8001CF44: nop
    
            goto L_8001CF4C;
    }
    // 0x8001CF44: nop

    // 0x8001CF48: break       7
    do_break(2147602248);
L_8001CF4C:
    // 0x8001CF4C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001CF50: bne         $v0, $at, L_8001CF64
    if (ctx->r2 != ctx->r1) {
        // 0x8001CF54: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001CF64;
    }
    // 0x8001CF54: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001CF58: bne         $s0, $at, L_8001CF64
    if (ctx->r16 != ctx->r1) {
        // 0x8001CF5C: nop
    
            goto L_8001CF64;
    }
    // 0x8001CF5C: nop

    // 0x8001CF60: break       6
    do_break(2147602272);
L_8001CF64:
    // 0x8001CF64: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x8001CF68: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x8001CF6C: mflo        $t9
    ctx->r25 = lo;
    // 0x8001CF70: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8001CF74: jal         0x8004C340
    // 0x8001CF78: nop

    func_8004C340(rdram, ctx);
        goto after_95;
    // 0x8001CF78: nop

    after_95:
    // 0x8001CF7C: lw          $t8, 0x198($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X198);
    // 0x8001CF80: lw          $t5, 0x19C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X19C);
    // 0x8001CF84: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x8001CF88: bne         $t6, $t5, L_8001CF9C
    if (ctx->r14 != ctx->r13) {
        // 0x8001CF8C: sw          $t6, 0x198($sp)
        MEM_W(0X198, ctx->r29) = ctx->r14;
            goto L_8001CF9C;
    }
    // 0x8001CF8C: sw          $t6, 0x198($sp)
    MEM_W(0X198, ctx->r29) = ctx->r14;
    // 0x8001CF90: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x8001CF94: ori         $t9, $t7, 0x8
    ctx->r25 = ctx->r15 | 0X8;
    // 0x8001CF98: sw          $t9, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r25;
L_8001CF9C:
    // 0x8001CF9C: jal         0x8000798C
    // 0x8001CFA0: nop

    func_8000798C(rdram, ctx);
        goto after_96;
    // 0x8001CFA0: nop

    after_96:
    // 0x8001CFA4: b           L_8001C574
    // 0x8001CFA8: lhu         $t9, 0x0($s6)
    ctx->r25 = MEM_HU(ctx->r22, 0X0);
        goto L_8001C574;
    // 0x8001CFA8: lhu         $t9, 0x0($s6)
    ctx->r25 = MEM_HU(ctx->r22, 0X0);
    // 0x8001CFAC: nop

    // 0x8001CFB0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8001CFB4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8001CFB8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8001CFBC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8001CFC0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8001CFC4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8001CFC8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8001CFCC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8001CFD0: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8001CFD4: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8001CFD8: jr          $ra
    // 0x8001CFDC: addiu       $sp, $sp, 0x1A8
    ctx->r29 = ADD32(ctx->r29, 0X1A8);
    TRACE_RETURN()
    return;
    // 0x8001CFDC: addiu       $sp, $sp, 0x1A8
    ctx->r29 = ADD32(ctx->r29, 0X1A8);
;}
RECOMP_FUNC void func_8001CFE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8001CFE0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001CFE4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001CFE8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8001CFEC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8001CFF0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001CFF4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8001CFF8: addiu       $a0, $zero, -0x69
    ctx->r4 = ADD32(0, -0X69);
    // 0x8001CFFC: addiu       $a1, $zero, -0x4B
    ctx->r5 = ADD32(0, -0X4B);
    // 0x8001D000: addiu       $a2, $zero, 0x4001
    ctx->r6 = ADD32(0, 0X4001);
    // 0x8001D004: jal         0x8004C580
    // 0x8001D008: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    func_8004C580(rdram, ctx);
        goto after_0;
    // 0x8001D008: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_0:
    // 0x8001D00C: addiu       $a0, $zero, -0x69
    ctx->r4 = ADD32(0, -0X69);
    // 0x8001D010: addiu       $a1, $zero, -0x4B
    ctx->r5 = ADD32(0, -0X4B);
    // 0x8001D014: addiu       $a2, $zero, -0x3FFF
    ctx->r6 = ADD32(0, -0X3FFF);
    // 0x8001D018: addiu       $a3, $zero, 0x31
    ctx->r7 = ADD32(0, 0X31);
    // 0x8001D01C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001D020: jal         0x8004C580
    // 0x8001D024: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_1;
    // 0x8001D024: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
    // 0x8001D028: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8001D02C: addiu       $s1, $s1, -0x6B50
    ctx->r17 = ADD32(ctx->r17, -0X6B50);
    // 0x8001D030: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8001D034:
    // 0x8001D034: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001D038: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001D03C: addiu       $a2, $zero, -0x3FEF
    ctx->r6 = ADD32(0, -0X3FEF);
    // 0x8001D040: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x8001D044: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001D048: jal         0x8004C580
    // 0x8001D04C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_2;
    // 0x8001D04C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_2:
    // 0x8001D050: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x8001D054: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x8001D058: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x8001D05C: lh          $t8, 0xE2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XE2);
    // 0x8001D060: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001D064: sll         $t0, $s0, 16
    ctx->r8 = S32(ctx->r16 << 16);
    // 0x8001D068: sra         $s0, $t0, 16
    ctx->r16 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8001D06C: slti        $at, $s0, 0xF
    ctx->r1 = SIGNED(ctx->r16) < 0XF ? 1 : 0;
    // 0x8001D070: ori         $t9, $t8, 0x20
    ctx->r25 = ctx->r24 | 0X20;
    // 0x8001D074: bne         $at, $zero, L_8001D034
    if (ctx->r1 != 0) {
        // 0x8001D078: sh          $t9, 0xE2($v0)
        MEM_H(0XE2, ctx->r2) = ctx->r25;
            goto L_8001D034;
    }
    // 0x8001D078: sh          $t9, 0xE2($v0)
    MEM_H(0XE2, ctx->r2) = ctx->r25;
    // 0x8001D07C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8001D080: addiu       $s1, $s1, -0x6B10
    ctx->r17 = ADD32(ctx->r17, -0X6B10);
    // 0x8001D084: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8001D088:
    // 0x8001D088: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001D08C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001D090: addiu       $a2, $zero, -0x3FEF
    ctx->r6 = ADD32(0, -0X3FEF);
    // 0x8001D094: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x8001D098: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001D09C: jal         0x8004C580
    // 0x8001D0A0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_3;
    // 0x8001D0A0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_3:
    // 0x8001D0A4: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x8001D0A8: addu        $t3, $s1, $t2
    ctx->r11 = ADD32(ctx->r17, ctx->r10);
    // 0x8001D0AC: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
    // 0x8001D0B0: lh          $t4, 0xE2($v0)
    ctx->r12 = MEM_H(ctx->r2, 0XE2);
    // 0x8001D0B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001D0B8: sll         $t6, $s0, 16
    ctx->r14 = S32(ctx->r16 << 16);
    // 0x8001D0BC: sra         $s0, $t6, 16
    ctx->r16 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8001D0C0: slti        $at, $s0, 0xF
    ctx->r1 = SIGNED(ctx->r16) < 0XF ? 1 : 0;
    // 0x8001D0C4: ori         $t5, $t4, 0x20
    ctx->r13 = ctx->r12 | 0X20;
    // 0x8001D0C8: bne         $at, $zero, L_8001D088
    if (ctx->r1 != 0) {
        // 0x8001D0CC: sh          $t5, 0xE2($v0)
        MEM_H(0XE2, ctx->r2) = ctx->r13;
            goto L_8001D088;
    }
    // 0x8001D0CC: sh          $t5, 0xE2($v0)
    MEM_H(0XE2, ctx->r2) = ctx->r13;
    // 0x8001D0D0: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8001D0D4: addiu       $s1, $s1, -0x6AD0
    ctx->r17 = ADD32(ctx->r17, -0X6AD0);
    // 0x8001D0D8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8001D0DC:
    // 0x8001D0DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001D0E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001D0E4: addiu       $a2, $zero, -0x3FEF
    ctx->r6 = ADD32(0, -0X3FEF);
    // 0x8001D0E8: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x8001D0EC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001D0F0: jal         0x8004C580
    // 0x8001D0F4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_4;
    // 0x8001D0F4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_4:
    // 0x8001D0F8: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x8001D0FC: addu        $t9, $s1, $t8
    ctx->r25 = ADD32(ctx->r17, ctx->r24);
    // 0x8001D100: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x8001D104: lh          $t0, 0xE2($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XE2);
    // 0x8001D108: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001D10C: sll         $t2, $s0, 16
    ctx->r10 = S32(ctx->r16 << 16);
    // 0x8001D110: sra         $s0, $t2, 16
    ctx->r16 = S32(SIGNED(ctx->r10) >> 16);
    // 0x8001D114: slti        $at, $s0, 0x5
    ctx->r1 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
    // 0x8001D118: ori         $t1, $t0, 0x20
    ctx->r9 = ctx->r8 | 0X20;
    // 0x8001D11C: bne         $at, $zero, L_8001D0DC
    if (ctx->r1 != 0) {
        // 0x8001D120: sh          $t1, 0xE2($v0)
        MEM_H(0XE2, ctx->r2) = ctx->r9;
            goto L_8001D0DC;
    }
    // 0x8001D120: sh          $t1, 0xE2($v0)
    MEM_H(0XE2, ctx->r2) = ctx->r9;
    // 0x8001D124: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001D128: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001D12C: addiu       $a2, $zero, -0x3FEF
    ctx->r6 = ADD32(0, -0X3FEF);
    // 0x8001D130: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x8001D134: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001D138: jal         0x8004C580
    // 0x8001D13C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_5;
    // 0x8001D13C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_5:
    // 0x8001D140: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001D144: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001D148: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D14C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8001D150: sw          $v0, -0x6ABC($at)
    MEM_W(-0X6ABC, ctx->r1) = ctx->r2;
    // 0x8001D154: jr          $ra
    // 0x8001D158: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    TRACE_RETURN()
    return;
    // 0x8001D158: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8001D15C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8001D15C: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8001D160: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8001D164: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001D168: lwc1        $f20, 0x65B4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X65B4);
    // 0x8001D16C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001D170: lwc1        $f4, -0x6A08($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6A08);
    // 0x8001D174: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8001D178: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x8001D17C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8001D180: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x8001D184: mul.s       $f12, $f6, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8001D188: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x8001D18C: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x8001D190: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x8001D194: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x8001D198: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x8001D19C: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x8001D1A0: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8001D1A4: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x8001D1A8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001D1AC: sh          $zero, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = 0;
    // 0x8001D1B0: jal         0x8004F7C0
    // 0x8001D1B4: sh          $zero, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = 0;
    func_8004F7C0(rdram, ctx);
        goto after_0;
    // 0x8001D1B4: sh          $zero, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = 0;
    after_0:
    // 0x8001D1B8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001D1BC: lwc1        $f8, -0x6A08($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6A08);
    // 0x8001D1C0: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8001D1C4: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8001D1C8: mul.s       $f12, $f10, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8001D1CC: jal         0x8004F650
    // 0x8001D1D0: nop

    func_8004F650(rdram, ctx);
        goto after_1;
    // 0x8001D1D0: nop

    after_1:
    // 0x8001D1D4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001D1D8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001D1DC: lh          $t0, 0x5E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X5E);
    // 0x8001D1E0: lh          $t1, 0x5C($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X5C);
    // 0x8001D1E4: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x8001D1E8: addiu       $a0, $a0, -0x6B14
    ctx->r4 = ADD32(ctx->r4, -0X6B14);
    // 0x8001D1EC: addiu       $v1, $v1, -0x6B50
    ctx->r3 = ADD32(ctx->r3, -0X6B50);
L_8001D1F0:
    // 0x8001D1F0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001D1F4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8001D1F8: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x8001D1FC: lh          $t6, 0xE2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XE2);
    // 0x8001D200: ori         $t7, $t6, 0x20
    ctx->r15 = ctx->r14 | 0X20;
    // 0x8001D204: bne         $at, $zero, L_8001D1F0
    if (ctx->r1 != 0) {
        // 0x8001D208: sh          $t7, 0xE2($v0)
        MEM_H(0XE2, ctx->r2) = ctx->r15;
            goto L_8001D1F0;
    }
    // 0x8001D208: sh          $t7, 0xE2($v0)
    MEM_H(0XE2, ctx->r2) = ctx->r15;
    // 0x8001D20C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001D210: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001D214: addiu       $a0, $a0, -0x6AD4
    ctx->r4 = ADD32(ctx->r4, -0X6AD4);
    // 0x8001D218: addiu       $v1, $v1, -0x6B10
    ctx->r3 = ADD32(ctx->r3, -0X6B10);
L_8001D21C:
    // 0x8001D21C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001D220: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8001D224: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x8001D228: lh          $t8, 0xE2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XE2);
    // 0x8001D22C: ori         $t9, $t8, 0x20
    ctx->r25 = ctx->r24 | 0X20;
    // 0x8001D230: bne         $at, $zero, L_8001D21C
    if (ctx->r1 != 0) {
        // 0x8001D234: sh          $t9, 0xE2($v0)
        MEM_H(0XE2, ctx->r2) = ctx->r25;
            goto L_8001D21C;
    }
    // 0x8001D234: sh          $t9, 0xE2($v0)
    MEM_H(0XE2, ctx->r2) = ctx->r25;
    // 0x8001D238: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x8001D23C: lw          $t2, -0x6AD0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X6AD0);
    // 0x8001D240: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8001D244: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8001D248: lh          $t3, 0xE2($t2)
    ctx->r11 = MEM_H(ctx->r10, 0XE2);
    // 0x8001D24C: addiu       $t6, $t6, -0x6AD0
    ctx->r14 = ADD32(ctx->r14, -0X6AD0);
    // 0x8001D250: sll         $t5, $a3, 2
    ctx->r13 = S32(ctx->r7 << 2);
    // 0x8001D254: ori         $t4, $t3, 0x20
    ctx->r12 = ctx->r11 | 0X20;
    // 0x8001D258: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x8001D25C: sh          $t4, 0xE2($t2)
    MEM_H(0XE2, ctx->r10) = ctx->r12;
    // 0x8001D260: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8001D264: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x8001D268: addiu       $s3, $s3, -0x6A18
    ctx->r19 = ADD32(ctx->r19, -0X6A18);
    // 0x8001D26C: lh          $t7, 0xE2($v1)
    ctx->r15 = MEM_H(ctx->r3, 0XE2);
    // 0x8001D270: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8001D274: addiu       $s2, $zero, -0x21
    ctx->r18 = ADD32(0, -0X21);
    // 0x8001D278: ori         $t8, $t7, 0x20
    ctx->r24 = ctx->r15 | 0X20;
    // 0x8001D27C: sh          $t8, 0xE2($v1)
    MEM_H(0XE2, ctx->r3) = ctx->r24;
    // 0x8001D280: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x8001D284: lh          $t9, 0xE2($a0)
    ctx->r25 = MEM_H(ctx->r4, 0XE2);
    // 0x8001D288: ori         $t3, $t9, 0x20
    ctx->r11 = ctx->r25 | 0X20;
    // 0x8001D28C: sh          $t3, 0xE2($a0)
    MEM_H(0XE2, ctx->r4) = ctx->r11;
    // 0x8001D290: lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8);
    // 0x8001D294: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8001D298: lh          $t4, 0xE2($a1)
    ctx->r12 = MEM_H(ctx->r5, 0XE2);
    // 0x8001D29C: ori         $t2, $t4, 0x20
    ctx->r10 = ctx->r12 | 0X20;
    // 0x8001D2A0: sh          $t2, 0xE2($a1)
    MEM_H(0XE2, ctx->r5) = ctx->r10;
    // 0x8001D2A4: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    // 0x8001D2A8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001D2AC: lh          $t5, 0xE2($a2)
    ctx->r13 = MEM_H(ctx->r6, 0XE2);
    // 0x8001D2B0: ori         $t6, $t5, 0x20
    ctx->r14 = ctx->r13 | 0X20;
    // 0x8001D2B4: sh          $t6, 0xE2($a2)
    MEM_H(0XE2, ctx->r6) = ctx->r14;
    // 0x8001D2B8: lw          $v0, -0x6ABC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6ABC);
    // 0x8001D2BC: lh          $t7, 0xE2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XE2);
    // 0x8001D2C0: ori         $t8, $t7, 0x20
    ctx->r24 = ctx->r15 | 0X20;
    // 0x8001D2C4: sh          $t8, 0xE2($v0)
    MEM_H(0XE2, ctx->r2) = ctx->r24;
    // 0x8001D2C8: lw          $t9, -0x6810($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6810);
    // 0x8001D2CC: lw          $s0, 0x0($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X0);
    // 0x8001D2D0: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8001D2D4: beq         $t3, $zero, L_8001D458
    if (ctx->r11 == 0) {
        // 0x8001D2D8: nop
    
            goto L_8001D458;
    }
    // 0x8001D2D8: nop

    // 0x8001D2DC: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x8001D2E0: lui         $at, 0xC296
    ctx->r1 = S32(0XC296 << 16);
    // 0x8001D2E4: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8001D2E8: lui         $at, 0xC2D2
    ctx->r1 = S32(0XC2D2 << 16);
    // 0x8001D2EC: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8001D2F0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001D2F4: lwc1        $f20, 0x65B8($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X65B8);
    // 0x8001D2F8: lh          $t4, 0x98($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X98);
L_8001D2FC:
    // 0x8001D2FC: andi        $t2, $t4, 0x100
    ctx->r10 = ctx->r12 & 0X100;
    // 0x8001D300: beql        $t2, $zero, L_8001D44C
    if (ctx->r10 == 0) {
        // 0x8001D304: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_8001D44C;
    }
    goto skip_0;
    // 0x8001D304: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x8001D308: lh          $t5, 0x2E($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X2E);
    // 0x8001D30C: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x8001D310: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8001D314: blezl       $t5, L_8001D44C
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8001D318: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_8001D44C;
    }
    goto skip_1;
    // 0x8001D318: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x8001D31C: sh          $t0, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r8;
    // 0x8001D320: jal         0x8000C8E8
    // 0x8001D324: sh          $t1, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r9;
    func_8000C8E8(rdram, ctx);
        goto after_2;
    // 0x8001D324: sh          $t1, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r9;
    after_2:
    // 0x8001D328: c.lt.s      $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f0.fl < ctx->f30.fl;
    // 0x8001D32C: lh          $t0, 0x5E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X5E);
    // 0x8001D330: lh          $t1, 0x5C($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X5C);
    // 0x8001D334: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001D338: bc1fl       L_8001D44C
    if (!c1cs) {
        // 0x8001D33C: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_8001D44C;
    }
    goto skip_2;
    // 0x8001D33C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x8001D340: lwc1        $f18, -0x6A18($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X6A18);
    // 0x8001D344: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8001D348: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001D34C: lwc1        $f6, -0x6A10($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X6A10);
    // 0x8001D350: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8001D354: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8001D358: slti        $at, $t1, 0xF
    ctx->r1 = SIGNED(ctx->r9) < 0XF ? 1 : 0;
    // 0x8001D35C: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8001D360: mul.s       $f8, $f0, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x8001D364: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x8001D368: mul.s       $f10, $f2, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x8001D36C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8001D370: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x8001D374: nop

    // 0x8001D378: mul.s       $f4, $f0, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8001D37C: nop

    // 0x8001D380: mul.s       $f6, $f2, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x8001D384: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
    // 0x8001D388: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001D38C: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8001D390: swc1        $f10, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
    // 0x8001D394: lh          $t6, 0x98($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X98);
    // 0x8001D398: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x8001D39C: beq         $t7, $zero, L_8001D3F8
    if (ctx->r15 == 0) {
        // 0x8001D3A0: nop
    
            goto L_8001D3F8;
    }
    // 0x8001D3A0: nop

    // 0x8001D3A4: slti        $at, $t0, 0xF
    ctx->r1 = SIGNED(ctx->r8) < 0XF ? 1 : 0;
    // 0x8001D3A8: beq         $at, $zero, L_8001D448
    if (ctx->r1 == 0) {
        // 0x8001D3AC: sll         $t8, $t0, 2
        ctx->r24 = S32(ctx->r8 << 2);
            goto L_8001D448;
    }
    // 0x8001D3AC: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x8001D3B0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8001D3B4: addiu       $t9, $t9, -0x6B50
    ctx->r25 = ADD32(ctx->r25, -0X6B50);
    // 0x8001D3B8: add.s       $f16, $f18, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f26.fl;
    // 0x8001D3BC: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x8001D3C0: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8001D3C4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001D3C8: sll         $t6, $t0, 16
    ctx->r14 = S32(ctx->r8 << 16);
    // 0x8001D3CC: swc1        $f16, 0x84($t3)
    MEM_W(0X84, ctx->r11) = ctx->f16.u32l;
    // 0x8001D3D0: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8001D3D4: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8001D3D8: sra         $t0, $t6, 16
    ctx->r8 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8001D3DC: add.s       $f6, $f4, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f28.fl;
    // 0x8001D3E0: swc1        $f6, 0x88($t4)
    MEM_W(0X88, ctx->r12) = ctx->f6.u32l;
    // 0x8001D3E4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8001D3E8: lh          $t2, 0xE2($v1)
    ctx->r10 = MEM_H(ctx->r3, 0XE2);
    // 0x8001D3EC: and         $t5, $t2, $s2
    ctx->r13 = ctx->r10 & ctx->r18;
    // 0x8001D3F0: b           L_8001D448
    // 0x8001D3F4: sh          $t5, 0xE2($v1)
    MEM_H(0XE2, ctx->r3) = ctx->r13;
        goto L_8001D448;
    // 0x8001D3F4: sh          $t5, 0xE2($v1)
    MEM_H(0XE2, ctx->r3) = ctx->r13;
L_8001D3F8:
    // 0x8001D3F8: beq         $at, $zero, L_8001D448
    if (ctx->r1 == 0) {
        // 0x8001D3FC: sll         $t8, $t1, 2
        ctx->r24 = S32(ctx->r9 << 2);
            goto L_8001D448;
    }
    // 0x8001D3FC: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x8001D400: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8001D404: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8001D408: addiu       $t9, $t9, -0x6B10
    ctx->r25 = ADD32(ctx->r25, -0X6B10);
    // 0x8001D40C: add.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f26.fl;
    // 0x8001D410: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x8001D414: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8001D418: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8001D41C: sll         $t6, $t1, 16
    ctx->r14 = S32(ctx->r9 << 16);
    // 0x8001D420: swc1        $f10, 0x84($t3)
    MEM_W(0X84, ctx->r11) = ctx->f10.u32l;
    // 0x8001D424: lwc1        $f18, 0x68($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8001D428: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8001D42C: sra         $t1, $t6, 16
    ctx->r9 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8001D430: add.s       $f16, $f18, $f28
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f28.fl;
    // 0x8001D434: swc1        $f16, 0x88($t4)
    MEM_W(0X88, ctx->r12) = ctx->f16.u32l;
    // 0x8001D438: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8001D43C: lh          $t2, 0xE2($v1)
    ctx->r10 = MEM_H(ctx->r3, 0XE2);
    // 0x8001D440: and         $t5, $t2, $s2
    ctx->r13 = ctx->r10 & ctx->r18;
    // 0x8001D444: sh          $t5, 0xE2($v1)
    MEM_H(0XE2, ctx->r3) = ctx->r13;
L_8001D448:
    // 0x8001D448: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_8001D44C:
    // 0x8001D44C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8001D450: bnel        $t8, $zero, L_8001D2FC
    if (ctx->r24 != 0) {
        // 0x8001D454: lh          $t4, 0x98($s0)
        ctx->r12 = MEM_H(ctx->r16, 0X98);
            goto L_8001D2FC;
    }
    goto skip_3;
    // 0x8001D454: lh          $t4, 0x98($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X98);
    skip_3:
L_8001D458:
    // 0x8001D458: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8001D45C: lw          $t9, -0x6610($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6610);
    // 0x8001D460: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001D464: lwc1        $f20, 0x65BC($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X65BC);
    // 0x8001D468: lw          $s0, 0x0($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X0);
    // 0x8001D46C: lui         $at, 0xC2D2
    ctx->r1 = S32(0XC2D2 << 16);
    // 0x8001D470: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8001D474: lui         $at, 0xC296
    ctx->r1 = S32(0XC296 << 16);
    // 0x8001D478: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8001D47C: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8001D480: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8001D484: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x8001D488: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x8001D48C: addiu       $s3, $s3, -0x6A18
    ctx->r19 = ADD32(ctx->r19, -0X6A18);
    // 0x8001D490: beq         $t3, $zero, L_8001D580
    if (ctx->r11 == 0) {
        // 0x8001D494: addiu       $s2, $zero, -0x21
        ctx->r18 = ADD32(0, -0X21);
            goto L_8001D580;
    }
    // 0x8001D494: addiu       $s2, $zero, -0x21
    ctx->r18 = ADD32(0, -0X21);
    // 0x8001D498: lh          $t4, 0x92($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X92);
L_8001D49C:
    // 0x8001D49C: andi        $t2, $t4, 0x100
    ctx->r10 = ctx->r12 & 0X100;
    // 0x8001D4A0: beql        $t2, $zero, L_8001D574
    if (ctx->r10 == 0) {
        // 0x8001D4A4: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_8001D574;
    }
    goto skip_4;
    // 0x8001D4A4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_4:
    // 0x8001D4A8: lh          $t5, 0x8E($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X8E);
    // 0x8001D4AC: addiu       $at, $zero, 0x201
    ctx->r1 = ADD32(0, 0X201);
    // 0x8001D4B0: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x8001D4B4: bne         $t5, $at, L_8001D4CC
    if (ctx->r13 != ctx->r1) {
        // 0x8001D4B8: nop
    
            goto L_8001D4CC;
    }
    // 0x8001D4B8: nop

    // 0x8001D4BC: lh          $t6, 0xB4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XB4);
    // 0x8001D4C0: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8001D4C4: bne         $t7, $zero, L_8001D580
    if (ctx->r15 != 0) {
        // 0x8001D4C8: nop
    
            goto L_8001D580;
    }
    // 0x8001D4C8: nop

L_8001D4CC:
    // 0x8001D4CC: jal         0x8000C8E8
    // 0x8001D4D0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_8000C8E8(rdram, ctx);
        goto after_3;
    // 0x8001D4D0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_3:
    // 0x8001D4D4: c.lt.s      $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f0.fl < ctx->f30.fl;
    // 0x8001D4D8: nop

    // 0x8001D4DC: bc1f        L_8001D570
    if (!c1cs) {
        // 0x8001D4E0: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_8001D570;
    }
    // 0x8001D4E0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001D4E4: lwc1        $f6, -0x6A18($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X6A18);
    // 0x8001D4E8: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8001D4EC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001D4F0: lwc1        $f10, -0x6A10($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X6A10);
    // 0x8001D4F4: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8001D4F8: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8001D4FC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8001D500: lw          $t8, -0x6ABC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6ABC);
    // 0x8001D504: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8001D508: mul.s       $f18, $f0, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x8001D50C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8001D510: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001D514: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x8001D518: mul.s       $f16, $f2, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x8001D51C: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x8001D520: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8001D524: nop

    // 0x8001D528: mul.s       $f8, $f0, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8001D52C: nop

    // 0x8001D530: mul.s       $f10, $f2, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x8001D534: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
    // 0x8001D538: add.s       $f4, $f6, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f26.fl;
    // 0x8001D53C: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8001D540: mul.s       $f16, $f18, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8001D544: swc1        $f16, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f16.u32l;
    // 0x8001D548: swc1        $f4, 0x84($t8)
    MEM_W(0X84, ctx->r24) = ctx->f4.u32l;
    // 0x8001D54C: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8001D550: lw          $t9, -0x6ABC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6ABC);
    // 0x8001D554: add.s       $f10, $f8, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f28.fl;
    // 0x8001D558: swc1        $f10, 0x88($t9)
    MEM_W(0X88, ctx->r25) = ctx->f10.u32l;
    // 0x8001D55C: lw          $v0, -0x6ABC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6ABC);
    // 0x8001D560: lh          $t3, 0xE2($v0)
    ctx->r11 = MEM_H(ctx->r2, 0XE2);
    // 0x8001D564: and         $t4, $t3, $s2
    ctx->r12 = ctx->r11 & ctx->r18;
    // 0x8001D568: b           L_8001D580
    // 0x8001D56C: sh          $t4, 0xE2($v0)
    MEM_H(0XE2, ctx->r2) = ctx->r12;
        goto L_8001D580;
    // 0x8001D56C: sh          $t4, 0xE2($v0)
    MEM_H(0XE2, ctx->r2) = ctx->r12;
L_8001D570:
    // 0x8001D570: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_8001D574:
    // 0x8001D574: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8001D578: bnel        $t2, $zero, L_8001D49C
    if (ctx->r10 != 0) {
        // 0x8001D57C: lh          $t4, 0x92($s0)
        ctx->r12 = MEM_H(ctx->r16, 0X92);
            goto L_8001D49C;
    }
    goto skip_5;
    // 0x8001D57C: lh          $t4, 0x92($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X92);
    skip_5:
L_8001D580:
    // 0x8001D580: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001D584: lw          $v0, -0x6590($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6590);
    // 0x8001D588: beql        $v0, $zero, L_8001D6F8
    if (ctx->r2 == 0) {
        // 0x8001D58C: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8001D6F8;
    }
    goto skip_6;
    // 0x8001D58C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_6:
    // 0x8001D590: lh          $t5, 0x4($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X4);
    // 0x8001D594: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8001D598: blezl       $t5, L_8001D6F8
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8001D59C: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8001D6F8;
    }
    goto skip_7;
    // 0x8001D59C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_7:
    // 0x8001D5A0: lh          $t6, 0x6($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X6);
    // 0x8001D5A4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001D5A8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001D5AC: blezl       $t6, L_8001D6F8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8001D5B0: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8001D6F8;
    }
    goto skip_8;
    // 0x8001D5B0: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_8:
    // 0x8001D5B4: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
L_8001D5B8:
    // 0x8001D5B8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8001D5BC: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8001D5C0: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x8001D5C4: lh          $v1, 0x7A($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X7A);
    // 0x8001D5C8: andi        $t9, $v1, 0x1
    ctx->r25 = ctx->r3 & 0X1;
    // 0x8001D5CC: beql        $t9, $zero, L_8001D6E0
    if (ctx->r25 == 0) {
        // 0x8001D5D0: lh          $t9, 0x6($a2)
        ctx->r25 = MEM_H(ctx->r6, 0X6);
            goto L_8001D6E0;
    }
    goto skip_9;
    // 0x8001D5D0: lh          $t9, 0x6($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X6);
    skip_9:
    // 0x8001D5D4: lw          $a0, 0x6AC0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6AC0);
    // 0x8001D5D8: andi        $t4, $v1, 0x2
    ctx->r12 = ctx->r3 & 0X2;
    // 0x8001D5DC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8001D5E0: andi        $t3, $a0, 0x10
    ctx->r11 = ctx->r4 & 0X10;
    // 0x8001D5E4: beq         $t4, $zero, L_8001D604
    if (ctx->r12 == 0) {
        // 0x8001D5E8: or          $a0, $t3, $zero
        ctx->r4 = ctx->r11 | 0;
            goto L_8001D604;
    }
    // 0x8001D5E8: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x8001D5EC: lw          $t5, 0x14($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X14);
    // 0x8001D5F0: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x8001D5F4: addiu       $t2, $t2, -0x6A20
    ctx->r10 = ADD32(ctx->r10, -0X6A20);
    // 0x8001D5F8: bne         $t2, $t5, L_8001D604
    if (ctx->r10 != ctx->r13) {
        // 0x8001D5FC: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8001D604;
    }
    // 0x8001D5FC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001D600: sw          $t6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r14;
L_8001D604:
    // 0x8001D604: beq         $a0, $zero, L_8001D6DC
    if (ctx->r4 == 0) {
        // 0x8001D608: addiu       $a0, $v0, 0x58
        ctx->r4 = ADD32(ctx->r2, 0X58);
            goto L_8001D6DC;
    }
    // 0x8001D608: addiu       $a0, $v0, 0x58
    ctx->r4 = ADD32(ctx->r2, 0X58);
    // 0x8001D60C: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x8001D610: jal         0x8000C8E8
    // 0x8001D614: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    func_8000C8E8(rdram, ctx);
        goto after_4;
    // 0x8001D614: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    after_4:
    // 0x8001D618: c.lt.s      $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f0.fl < ctx->f30.fl;
    // 0x8001D61C: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x8001D620: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    // 0x8001D624: bc1fl       L_8001D6E0
    if (!c1cs) {
        // 0x8001D628: lh          $t9, 0x6($a2)
        ctx->r25 = MEM_H(ctx->r6, 0X6);
            goto L_8001D6E0;
    }
    goto skip_10;
    // 0x8001D628: lh          $t9, 0x6($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X6);
    skip_10:
    // 0x8001D62C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x8001D630: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001D634: lwc1        $f16, -0x6A18($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X6A18);
    // 0x8001D638: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8001D63C: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x8001D640: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001D644: lwc1        $f4, -0x6A10($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6A10);
    // 0x8001D648: lwc1        $f18, 0x58($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X58);
    // 0x8001D64C: lwc1        $f6, 0x60($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X60);
    // 0x8001D650: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x8001D654: sub.s       $f0, $f18, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x8001D658: slti        $at, $s1, 0x5
    ctx->r1 = SIGNED(ctx->r17) < 0X5 ? 1 : 0;
    // 0x8001D65C: addiu       $t3, $t3, -0x6AD0
    ctx->r11 = ADD32(ctx->r11, -0X6AD0);
    // 0x8001D660: sub.s       $f2, $f6, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x8001D664: mul.s       $f8, $f0, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x8001D668: sll         $t9, $s1, 2
    ctx->r25 = S32(ctx->r17 << 2);
    // 0x8001D66C: addu        $v0, $t9, $t3
    ctx->r2 = ADD32(ctx->r25, ctx->r11);
    // 0x8001D670: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x8001D674: mul.s       $f10, $f2, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x8001D678: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8001D67C: mul.s       $f16, $f18, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8001D680: nop

    // 0x8001D684: mul.s       $f6, $f0, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8001D688: nop

    // 0x8001D68C: mul.s       $f4, $f2, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x8001D690: swc1        $f16, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f16.u32l;
    // 0x8001D694: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8001D698: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8001D69C: beq         $at, $zero, L_8001D6DC
    if (ctx->r1 == 0) {
        // 0x8001D6A0: swc1        $f10, 0x68($sp)
        MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
            goto L_8001D6DC;
    }
    // 0x8001D6A0: swc1        $f10, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
    // 0x8001D6A4: add.s       $f18, $f16, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f26.fl;
    // 0x8001D6A8: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8001D6AC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8001D6B0: sll         $t7, $s1, 16
    ctx->r15 = S32(ctx->r17 << 16);
    // 0x8001D6B4: swc1        $f18, 0x84($t4)
    MEM_W(0X84, ctx->r12) = ctx->f18.u32l;
    // 0x8001D6B8: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8001D6BC: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8001D6C0: sra         $s1, $t7, 16
    ctx->r17 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8001D6C4: add.s       $f4, $f6, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f28.fl;
    // 0x8001D6C8: swc1        $f4, 0x88($t2)
    MEM_W(0X88, ctx->r10) = ctx->f4.u32l;
    // 0x8001D6CC: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8001D6D0: lh          $t5, 0xE2($v1)
    ctx->r13 = MEM_H(ctx->r3, 0XE2);
    // 0x8001D6D4: and         $t6, $t5, $s2
    ctx->r14 = ctx->r13 & ctx->r18;
    // 0x8001D6D8: sh          $t6, 0xE2($v1)
    MEM_H(0XE2, ctx->r3) = ctx->r14;
L_8001D6DC:
    // 0x8001D6DC: lh          $t9, 0x6($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X6);
L_8001D6E0:
    // 0x8001D6E0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8001D6E4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8001D6E8: slt         $at, $a3, $t9
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8001D6EC: bnel        $at, $zero, L_8001D5B8
    if (ctx->r1 != 0) {
        // 0x8001D6F0: lw          $t7, 0x0($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X0);
            goto L_8001D5B8;
    }
    goto skip_11;
    // 0x8001D6F0: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    skip_11:
    // 0x8001D6F4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8001D6F8:
    // 0x8001D6F8: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
    // 0x8001D6FC: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8001D700: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8001D704: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x8001D708: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x8001D70C: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x8001D710: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x8001D714: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x8001D718: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x8001D71C: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x8001D720: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x8001D724: jr          $ra
    // 0x8001D728: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    TRACE_RETURN()
    return;
    // 0x8001D728: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_8001D72C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8001D72C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001D730: lw          $v0, -0x6630($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6630);
    // 0x8001D734: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001D738: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001D73C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8001D740: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8001D744: lwc1        $f4, -0x6314($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6314);
    // 0x8001D748: lui         $a3, 0x8007
    ctx->r7 = S32(0X8007 << 16);
    // 0x8001D74C: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x8001D750: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001D754: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001D758: addu        $a3, $a3, $t7
    ctx->r7 = ADD32(ctx->r7, ctx->r15);
    // 0x8001D75C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8001D760: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8001D764: lh          $a3, -0x62F6($a3)
    ctx->r7 = MEM_H(ctx->r7, -0X62F6);
    // 0x8001D768: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001D76C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8001D770: addiu       $a0, $zero, 0x65
    ctx->r4 = ADD32(0, 0X65);
    // 0x8001D774: addiu       $a1, $zero, -0x42
    ctx->r5 = ADD32(0, -0X42);
    // 0x8001D778: addiu       $a2, $zero, -0x7FFF
    ctx->r6 = ADD32(0, -0X7FFF);
    // 0x8001D77C: jal         0x8004C580
    // 0x8001D780: swc1        $f4, -0x6AB8($at)
    MEM_W(-0X6AB8, ctx->r1) = ctx->f4.u32l;
    func_8004C580(rdram, ctx);
        goto after_0;
    // 0x8001D780: swc1        $f4, -0x6AB8($at)
    MEM_W(-0X6AB8, ctx->r1) = ctx->f4.u32l;
    after_0:
    // 0x8001D784: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8001D788: addiu       $s1, $s1, -0x6AB0
    ctx->r17 = ADD32(ctx->r17, -0X6AB0);
    // 0x8001D78C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8001D790:
    // 0x8001D790: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001D794: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001D798: addiu       $a2, $zero, -0x3FEF
    ctx->r6 = ADD32(0, -0X3FEF);
    // 0x8001D79C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x8001D7A0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001D7A4: jal         0x8004C580
    // 0x8001D7A8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_1;
    // 0x8001D7A8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
    // 0x8001D7AC: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x8001D7B0: addu        $t9, $s1, $t8
    ctx->r25 = ADD32(ctx->r17, ctx->r24);
    // 0x8001D7B4: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x8001D7B8: lh          $t0, 0xE2($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XE2);
    // 0x8001D7BC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001D7C0: sll         $t2, $s0, 16
    ctx->r10 = S32(ctx->r16 << 16);
    // 0x8001D7C4: sra         $s0, $t2, 16
    ctx->r16 = S32(SIGNED(ctx->r10) >> 16);
    // 0x8001D7C8: slti        $at, $s0, 0x5
    ctx->r1 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
    // 0x8001D7CC: ori         $t1, $t0, 0x20
    ctx->r9 = ctx->r8 | 0X20;
    // 0x8001D7D0: bne         $at, $zero, L_8001D790
    if (ctx->r1 != 0) {
        // 0x8001D7D4: sh          $t1, 0xE2($v0)
        MEM_H(0XE2, ctx->r2) = ctx->r9;
            goto L_8001D790;
    }
    // 0x8001D7D4: sh          $t1, 0xE2($v0)
    MEM_H(0XE2, ctx->r2) = ctx->r9;
    // 0x8001D7D8: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8001D7DC: addiu       $s1, $s1, -0x6A98
    ctx->r17 = ADD32(ctx->r17, -0X6A98);
    // 0x8001D7E0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8001D7E4:
    // 0x8001D7E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001D7E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001D7EC: addiu       $a2, $zero, -0x3FEF
    ctx->r6 = ADD32(0, -0X3FEF);
    // 0x8001D7F0: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x8001D7F4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001D7F8: jal         0x8004C580
    // 0x8001D7FC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_2;
    // 0x8001D7FC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_2:
    // 0x8001D800: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x8001D804: addu        $t5, $s1, $t4
    ctx->r13 = ADD32(ctx->r17, ctx->r12);
    // 0x8001D808: sw          $v0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r2;
    // 0x8001D80C: lh          $t6, 0xE2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XE2);
    // 0x8001D810: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001D814: sll         $t8, $s0, 16
    ctx->r24 = S32(ctx->r16 << 16);
    // 0x8001D818: sra         $s0, $t8, 16
    ctx->r16 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8001D81C: slti        $at, $s0, 0x1E
    ctx->r1 = SIGNED(ctx->r16) < 0X1E ? 1 : 0;
    // 0x8001D820: ori         $t7, $t6, 0x20
    ctx->r15 = ctx->r14 | 0X20;
    // 0x8001D824: bne         $at, $zero, L_8001D7E4
    if (ctx->r1 != 0) {
        // 0x8001D828: sh          $t7, 0xE2($v0)
        MEM_H(0XE2, ctx->r2) = ctx->r15;
            goto L_8001D7E4;
    }
    // 0x8001D828: sh          $t7, 0xE2($v0)
    MEM_H(0XE2, ctx->r2) = ctx->r15;
    // 0x8001D82C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001D830: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001D834: addiu       $a2, $zero, -0x3FEF
    ctx->r6 = ADD32(0, -0X3FEF);
    // 0x8001D838: addiu       $a3, $zero, 0x31
    ctx->r7 = ADD32(0, 0X31);
    // 0x8001D83C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001D840: jal         0x8004C580
    // 0x8001D844: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_3;
    // 0x8001D844: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_3:
    // 0x8001D848: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001D84C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001D850: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D854: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8001D858: sw          $v0, -0x6AB4($at)
    MEM_W(-0X6AB4, ctx->r1) = ctx->r2;
    // 0x8001D85C: jr          $ra
    // 0x8001D860: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    TRACE_RETURN()
    return;
    // 0x8001D860: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8001D864(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8001D864: lui         $at, 0x42CA
    ctx->r1 = S32(0X42CA << 16);
    // 0x8001D868: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8001D86C: lui         $at, 0xC284
    ctx->r1 = S32(0XC284 << 16);
    // 0x8001D870: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001D874: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8001D878: addiu       $v0, $v0, -0x6A20
    ctx->r2 = ADD32(ctx->r2, -0X6A20);
    // 0x8001D87C: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8001D880: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001D884: lwc1        $f0, -0x6AB8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6AB8);
    // 0x8001D888: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8001D88C: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x8001D890: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8001D894: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8001D898: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8001D89C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8001D8A0: addiu       $t1, $t1, -0x6AB4
    ctx->r9 = ADD32(ctx->r9, -0X6AB4);
    // 0x8001D8A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001D8A8: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x8001D8AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001D8B0: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8001D8B4: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x8001D8B8: sh          $zero, 0x34($sp)
    MEM_H(0X34, ctx->r29) = 0;
    // 0x8001D8BC: sh          $zero, 0x36($sp)
    MEM_H(0X36, ctx->r29) = 0;
    // 0x8001D8C0: lw          $a1, 0x18($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X18);
    // 0x8001D8C4: addiu       $a0, $a0, 0x54
    ctx->r4 = ADD32(ctx->r4, 0X54);
    // 0x8001D8C8: div.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8001D8CC: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8001D8D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001D8D4: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x8001D8D8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8001D8DC: add.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f12.fl;
    // 0x8001D8E0: jal         0x80049840
    // 0x8001D8E4: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    func_80049840(rdram, ctx);
        goto after_0;
    // 0x8001D8E4: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8001D8E8: lui         $at, 0x42CA
    ctx->r1 = S32(0X42CA << 16);
    // 0x8001D8EC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8001D8F0: lui         $at, 0xC284
    ctx->r1 = S32(0XC284 << 16);
    // 0x8001D8F4: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8001D8F8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8001D8FC: addiu       $t1, $t1, -0x6AB4
    ctx->r9 = ADD32(ctx->r9, -0X6AB4);
    // 0x8001D900: lh          $t0, 0x34($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X34);
    // 0x8001D904: lh          $t2, 0x36($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X36);
    // 0x8001D908: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001D90C: addiu       $v0, $sp, 0x54
    ctx->r2 = ADD32(ctx->r29, 0X54);
    // 0x8001D910: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
L_8001D914:
    // 0x8001D914: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8001D918: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001D91C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001D920: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x8001D924: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x8001D928: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8001D92C: bne         $at, $zero, L_8001D914
    if (ctx->r1 != 0) {
        // 0x8001D930: swc1        $f8, 0x84($t7)
        MEM_W(0X84, ctx->r15) = ctx->f8.u32l;
            goto L_8001D914;
    }
    // 0x8001D930: swc1        $f8, 0x84($t7)
    MEM_W(0X84, ctx->r15) = ctx->f8.u32l;
    // 0x8001D934: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001D938: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001D93C: addiu       $a0, $a0, -0x6A9C
    ctx->r4 = ADD32(ctx->r4, -0X6A9C);
    // 0x8001D940: addiu       $v1, $v1, -0x6AB0
    ctx->r3 = ADD32(ctx->r3, -0X6AB0);
L_8001D944:
    // 0x8001D944: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001D948: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8001D94C: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x8001D950: lh          $t8, 0xE2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XE2);
    // 0x8001D954: ori         $t9, $t8, 0x20
    ctx->r25 = ctx->r24 | 0X20;
    // 0x8001D958: bne         $at, $zero, L_8001D944
    if (ctx->r1 != 0) {
        // 0x8001D95C: sh          $t9, 0xE2($v0)
        MEM_H(0XE2, ctx->r2) = ctx->r25;
            goto L_8001D944;
    }
    // 0x8001D95C: sh          $t9, 0xE2($v0)
    MEM_H(0XE2, ctx->r2) = ctx->r25;
    // 0x8001D960: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8001D964: lw          $t6, -0x6A98($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6A98);
    // 0x8001D968: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8001D96C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001D970: lh          $t7, 0xE2($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XE2);
    // 0x8001D974: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x8001D978: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x8001D97C: ori         $t8, $t7, 0x20
    ctx->r24 = ctx->r15 | 0X20;
    // 0x8001D980: sh          $t8, 0xE2($t6)
    MEM_H(0XE2, ctx->r14) = ctx->r24;
    // 0x8001D984: lw          $t9, -0x6A94($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6A94);
    // 0x8001D988: addiu       $a3, $a3, -0x6A20
    ctx->r7 = ADD32(ctx->r7, -0X6A20);
    // 0x8001D98C: addiu       $v0, $v0, -0x6A90
    ctx->r2 = ADD32(ctx->r2, -0X6A90);
    // 0x8001D990: lh          $t7, 0xE2($t9)
    ctx->r15 = MEM_H(ctx->r25, 0XE2);
    // 0x8001D994: addiu       $t5, $t5, -0x6AB0
    ctx->r13 = ADD32(ctx->r13, -0X6AB0);
    // 0x8001D998: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8001D99C: ori         $t8, $t7, 0x20
    ctx->r24 = ctx->r15 | 0X20;
    // 0x8001D9A0: sh          $t8, 0xE2($t9)
    MEM_H(0XE2, ctx->r25) = ctx->r24;
L_8001D9A4:
    // 0x8001D9A4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8001D9A8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8001D9AC: lh          $t6, 0xE2($v1)
    ctx->r14 = MEM_H(ctx->r3, 0XE2);
    // 0x8001D9B0: ori         $t7, $t6, 0x20
    ctx->r15 = ctx->r14 | 0X20;
    // 0x8001D9B4: sh          $t7, 0xE2($v1)
    MEM_H(0XE2, ctx->r3) = ctx->r15;
    // 0x8001D9B8: lw          $a0, -0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, -0XC);
    // 0x8001D9BC: lh          $t8, 0xE2($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE2);
    // 0x8001D9C0: ori         $t9, $t8, 0x20
    ctx->r25 = ctx->r24 | 0X20;
    // 0x8001D9C4: sh          $t9, 0xE2($a0)
    MEM_H(0XE2, ctx->r4) = ctx->r25;
    // 0x8001D9C8: lw          $a1, -0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, -0X8);
    // 0x8001D9CC: lh          $t6, 0xE2($a1)
    ctx->r14 = MEM_H(ctx->r5, 0XE2);
    // 0x8001D9D0: ori         $t7, $t6, 0x20
    ctx->r15 = ctx->r14 | 0X20;
    // 0x8001D9D4: sh          $t7, 0xE2($a1)
    MEM_H(0XE2, ctx->r5) = ctx->r15;
    // 0x8001D9D8: lw          $a2, -0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, -0X4);
    // 0x8001D9DC: lh          $t8, 0xE2($a2)
    ctx->r24 = MEM_H(ctx->r6, 0XE2);
    // 0x8001D9E0: ori         $t9, $t8, 0x20
    ctx->r25 = ctx->r24 | 0X20;
    // 0x8001D9E4: bne         $v0, $a3, L_8001D9A4
    if (ctx->r2 != ctx->r7) {
        // 0x8001D9E8: sh          $t9, 0xE2($a2)
        MEM_H(0XE2, ctx->r6) = ctx->r25;
            goto L_8001D9A4;
    }
    // 0x8001D9E8: sh          $t9, 0xE2($a2)
    MEM_H(0XE2, ctx->r6) = ctx->r25;
    // 0x8001D9EC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8001D9F0: lw          $t6, -0x65A0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X65A0);
    // 0x8001D9F4: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8001D9F8: addiu       $t1, $t1, -0x6A98
    ctx->r9 = ADD32(ctx->r9, -0X6A98);
    // 0x8001D9FC: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x8001DA00: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8001DA04: addiu       $a3, $zero, -0x21
    ctx->r7 = ADD32(0, -0X21);
    // 0x8001DA08: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x8001DA0C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x8001DA10: beq         $t7, $zero, L_8001DB74
    if (ctx->r15 == 0) {
        // 0x8001DA14: nop
    
            goto L_8001DB74;
    }
    // 0x8001DA14: nop

    // 0x8001DA18: lh          $t8, 0x36($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X36);
L_8001DA1C:
    // 0x8001DA1C: blezl       $t8, L_8001DB68
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8001DA20: lw          $a2, 0x0($a2)
        ctx->r6 = MEM_W(ctx->r6, 0X0);
            goto L_8001DB68;
    }
    goto skip_0;
    // 0x8001DA20: lw          $a2, 0x0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X0);
    skip_0:
    // 0x8001DA24: lh          $t9, 0x92($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X92);
    // 0x8001DA28: andi        $t6, $t9, 0x20
    ctx->r14 = ctx->r25 & 0X20;
    // 0x8001DA2C: beql        $t6, $zero, L_8001DB68
    if (ctx->r14 == 0) {
        // 0x8001DA30: lw          $a2, 0x0($a2)
        ctx->r6 = MEM_W(ctx->r6, 0X0);
            goto L_8001DB68;
    }
    goto skip_1;
    // 0x8001DA30: lw          $a2, 0x0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X0);
    skip_1:
    // 0x8001DA34: lwc1        $f10, 0x10($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X10);
    // 0x8001DA38: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001DA3C: lwc1        $f0, -0x6AB8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6AB8);
    // 0x8001DA40: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    // 0x8001DA44: lwc1        $f16, 0x18($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X18);
    // 0x8001DA48: addiu       $v1, $sp, 0x54
    ctx->r3 = ADD32(ctx->r29, 0X54);
    // 0x8001DA4C: addiu       $v0, $sp, 0x38
    ctx->r2 = ADD32(ctx->r29, 0X38);
    // 0x8001DA50: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x8001DA54: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
L_8001DA58:
    // 0x8001DA58: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8001DA5C: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8001DA60: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x8001DA64: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8001DA68: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8001DA6C: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x8001DA70: nop

    // 0x8001DA74: bgez        $a0, L_8001DA84
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8001DA78: sw          $a0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r4;
            goto L_8001DA84;
    }
    // 0x8001DA78: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8001DA7C: negu        $t9, $a0
    ctx->r25 = SUB32(0, ctx->r4);
    // 0x8001DA80: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_8001DA84:
    // 0x8001DA84: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001DA88: bne         $v0, $a1, L_8001DA58
    if (ctx->r2 != ctx->r5) {
        // 0x8001DA8C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8001DA58;
    }
    // 0x8001DA8C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8001DA90: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8001DA94: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8001DA98: slti        $at, $t6, 0x20
    ctx->r1 = SIGNED(ctx->r14) < 0X20 ? 1 : 0;
    // 0x8001DA9C: beq         $at, $zero, L_8001DB64
    if (ctx->r1 == 0) {
        // 0x8001DAA0: slti        $at, $t7, 0x20
        ctx->r1 = SIGNED(ctx->r15) < 0X20 ? 1 : 0;
            goto L_8001DB64;
    }
    // 0x8001DAA0: slti        $at, $t7, 0x20
    ctx->r1 = SIGNED(ctx->r15) < 0X20 ? 1 : 0;
    // 0x8001DAA4: beql        $at, $zero, L_8001DB68
    if (ctx->r1 == 0) {
        // 0x8001DAA8: lw          $a2, 0x0($a2)
        ctx->r6 = MEM_W(ctx->r6, 0X0);
            goto L_8001DB68;
    }
    goto skip_2;
    // 0x8001DAA8: lw          $a2, 0x0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X0);
    skip_2:
    // 0x8001DAAC: lh          $v0, 0x92($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X92);
    // 0x8001DAB0: slti        $at, $t2, 0x5
    ctx->r1 = SIGNED(ctx->r10) < 0X5 ? 1 : 0;
    // 0x8001DAB4: andi        $t8, $v0, 0x3
    ctx->r24 = ctx->r2 & 0X3;
    // 0x8001DAB8: beq         $t8, $t3, L_8001DAD0
    if (ctx->r24 == ctx->r11) {
        // 0x8001DABC: nop
    
            goto L_8001DAD0;
    }
    // 0x8001DABC: nop

    // 0x8001DAC0: beq         $t8, $t4, L_8001DB1C
    if (ctx->r24 == ctx->r12) {
        // 0x8001DAC4: slti        $at, $t0, 0x1E
        ctx->r1 = SIGNED(ctx->r8) < 0X1E ? 1 : 0;
            goto L_8001DB1C;
    }
    // 0x8001DAC4: slti        $at, $t0, 0x1E
    ctx->r1 = SIGNED(ctx->r8) < 0X1E ? 1 : 0;
    // 0x8001DAC8: b           L_8001DB68
    // 0x8001DACC: lw          $a2, 0x0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X0);
        goto L_8001DB68;
    // 0x8001DACC: lw          $a2, 0x0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X0);
L_8001DAD0:
    // 0x8001DAD0: beq         $at, $zero, L_8001DB64
    if (ctx->r1 == 0) {
        // 0x8001DAD4: lwc1        $f16, 0x54($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
            goto L_8001DB64;
    }
    // 0x8001DAD4: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8001DAD8: sll         $t9, $t2, 2
    ctx->r25 = S32(ctx->r10 << 2);
    // 0x8001DADC: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8001DAE0: addu        $v0, $t5, $t9
    ctx->r2 = ADD32(ctx->r13, ctx->r25);
    // 0x8001DAE4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8001DAE8: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8001DAEC: swc1        $f18, 0x84($t6)
    MEM_W(0X84, ctx->r14) = ctx->f18.u32l;
    // 0x8001DAF0: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8001DAF4: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8001DAF8: sll         $t6, $t2, 16
    ctx->r14 = S32(ctx->r10 << 16);
    // 0x8001DAFC: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8001DB00: sra         $t2, $t6, 16
    ctx->r10 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8001DB04: swc1        $f6, 0x88($t7)
    MEM_W(0X88, ctx->r15) = ctx->f6.u32l;
    // 0x8001DB08: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8001DB0C: lh          $t8, 0xE2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0XE2);
    // 0x8001DB10: and         $t9, $t8, $a3
    ctx->r25 = ctx->r24 & ctx->r7;
    // 0x8001DB14: b           L_8001DB64
    // 0x8001DB18: sh          $t9, 0xE2($v1)
    MEM_H(0XE2, ctx->r3) = ctx->r25;
        goto L_8001DB64;
    // 0x8001DB18: sh          $t9, 0xE2($v1)
    MEM_H(0XE2, ctx->r3) = ctx->r25;
L_8001DB1C:
    // 0x8001DB1C: beq         $at, $zero, L_8001DB64
    if (ctx->r1 == 0) {
        // 0x8001DB20: lwc1        $f8, 0x54($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
            goto L_8001DB64;
    }
    // 0x8001DB20: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8001DB24: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x8001DB28: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8001DB2C: addu        $v0, $t1, $t8
    ctx->r2 = ADD32(ctx->r9, ctx->r24);
    // 0x8001DB30: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8001DB34: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001DB38: swc1        $f10, 0x84($t9)
    MEM_W(0X84, ctx->r25) = ctx->f10.u32l;
    // 0x8001DB3C: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8001DB40: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8001DB44: sll         $t9, $t0, 16
    ctx->r25 = S32(ctx->r8 << 16);
    // 0x8001DB48: add.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x8001DB4C: sra         $t0, $t9, 16
    ctx->r8 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8001DB50: swc1        $f18, 0x88($t6)
    MEM_W(0X88, ctx->r14) = ctx->f18.u32l;
    // 0x8001DB54: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8001DB58: lh          $t7, 0xE2($v1)
    ctx->r15 = MEM_H(ctx->r3, 0XE2);
    // 0x8001DB5C: and         $t8, $t7, $a3
    ctx->r24 = ctx->r15 & ctx->r7;
    // 0x8001DB60: sh          $t8, 0xE2($v1)
    MEM_H(0XE2, ctx->r3) = ctx->r24;
L_8001DB64:
    // 0x8001DB64: lw          $a2, 0x0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X0);
L_8001DB68:
    // 0x8001DB68: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x8001DB6C: bnel        $t7, $zero, L_8001DA1C
    if (ctx->r15 != 0) {
        // 0x8001DB70: lh          $t8, 0x36($a2)
        ctx->r24 = MEM_H(ctx->r6, 0X36);
            goto L_8001DA1C;
    }
    goto skip_3;
    // 0x8001DB70: lh          $t8, 0x36($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X36);
    skip_3:
L_8001DB74:
    // 0x8001DB74: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8001DB78: lw          $t8, -0x6810($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6810);
    // 0x8001DB7C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8001DB80: addiu       $t1, $t1, -0x6A98
    ctx->r9 = ADD32(ctx->r9, -0X6A98);
    // 0x8001DB84: lw          $a2, 0x0($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X0);
    // 0x8001DB88: addiu       $a3, $zero, -0x21
    ctx->r7 = ADD32(0, -0X21);
    // 0x8001DB8C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x8001DB90: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x8001DB94: beql        $t9, $zero, L_8001DC8C
    if (ctx->r25 == 0) {
        // 0x8001DB98: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001DC8C;
    }
    goto skip_4;
    // 0x8001DB98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x8001DB9C: lh          $t6, 0x2E($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X2E);
L_8001DBA0:
    // 0x8001DBA0: blezl       $t6, L_8001DC7C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8001DBA4: lw          $a2, 0x0($a2)
        ctx->r6 = MEM_W(ctx->r6, 0X0);
            goto L_8001DC7C;
    }
    goto skip_5;
    // 0x8001DBA4: lw          $a2, 0x0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X0);
    skip_5:
    // 0x8001DBA8: lh          $t7, 0x98($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X98);
    // 0x8001DBAC: andi        $t8, $t7, 0x400
    ctx->r24 = ctx->r15 & 0X400;
    // 0x8001DBB0: beql        $t8, $zero, L_8001DC7C
    if (ctx->r24 == 0) {
        // 0x8001DBB4: lw          $a2, 0x0($a2)
        ctx->r6 = MEM_W(ctx->r6, 0X0);
            goto L_8001DC7C;
    }
    goto skip_6;
    // 0x8001DBB4: lw          $a2, 0x0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X0);
    skip_6:
    // 0x8001DBB8: lwc1        $f4, 0x8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8001DBBC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001DBC0: lwc1        $f0, -0x6AB8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6AB8);
    // 0x8001DBC4: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    // 0x8001DBC8: lwc1        $f6, 0x10($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X10);
    // 0x8001DBCC: addiu       $v1, $sp, 0x54
    ctx->r3 = ADD32(ctx->r29, 0X54);
    // 0x8001DBD0: addiu       $v0, $sp, 0x38
    ctx->r2 = ADD32(ctx->r29, 0X38);
    // 0x8001DBD4: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8001DBD8: swc1        $f8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f8.u32l;
L_8001DBDC:
    // 0x8001DBDC: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8001DBE0: div.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8001DBE4: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
    // 0x8001DBE8: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8001DBEC: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8001DBF0: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x8001DBF4: nop

    // 0x8001DBF8: bgez        $a0, L_8001DC08
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8001DBFC: sw          $a0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r4;
            goto L_8001DC08;
    }
    // 0x8001DBFC: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8001DC00: negu        $t7, $a0
    ctx->r15 = SUB32(0, ctx->r4);
    // 0x8001DC04: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_8001DC08:
    // 0x8001DC08: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001DC0C: bne         $v0, $a1, L_8001DBDC
    if (ctx->r2 != ctx->r5) {
        // 0x8001DC10: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8001DBDC;
    }
    // 0x8001DC10: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8001DC14: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8001DC18: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8001DC1C: slti        $at, $t8, 0x20
    ctx->r1 = SIGNED(ctx->r24) < 0X20 ? 1 : 0;
    // 0x8001DC20: beq         $at, $zero, L_8001DC78
    if (ctx->r1 == 0) {
        // 0x8001DC24: slti        $at, $t9, 0x20
        ctx->r1 = SIGNED(ctx->r25) < 0X20 ? 1 : 0;
            goto L_8001DC78;
    }
    // 0x8001DC24: slti        $at, $t9, 0x20
    ctx->r1 = SIGNED(ctx->r25) < 0X20 ? 1 : 0;
    // 0x8001DC28: beq         $at, $zero, L_8001DC78
    if (ctx->r1 == 0) {
        // 0x8001DC2C: slti        $at, $t0, 0x1E
        ctx->r1 = SIGNED(ctx->r8) < 0X1E ? 1 : 0;
            goto L_8001DC78;
    }
    // 0x8001DC2C: slti        $at, $t0, 0x1E
    ctx->r1 = SIGNED(ctx->r8) < 0X1E ? 1 : 0;
    // 0x8001DC30: beq         $at, $zero, L_8001DC78
    if (ctx->r1 == 0) {
        // 0x8001DC34: lwc1        $f6, 0x54($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
            goto L_8001DC78;
    }
    // 0x8001DC34: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8001DC38: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x8001DC3C: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8001DC40: addu        $v0, $t1, $t6
    ctx->r2 = ADD32(ctx->r9, ctx->r14);
    // 0x8001DC44: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8001DC48: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001DC4C: swc1        $f8, 0x84($t7)
    MEM_W(0X84, ctx->r15) = ctx->f8.u32l;
    // 0x8001DC50: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8001DC54: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8001DC58: sll         $t7, $t0, 16
    ctx->r15 = S32(ctx->r8 << 16);
    // 0x8001DC5C: add.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x8001DC60: sra         $t0, $t7, 16
    ctx->r8 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8001DC64: swc1        $f16, 0x88($t8)
    MEM_W(0X88, ctx->r24) = ctx->f16.u32l;
    // 0x8001DC68: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8001DC6C: lh          $t9, 0xE2($v1)
    ctx->r25 = MEM_H(ctx->r3, 0XE2);
    // 0x8001DC70: and         $t6, $t9, $a3
    ctx->r14 = ctx->r25 & ctx->r7;
    // 0x8001DC74: sh          $t6, 0xE2($v1)
    MEM_H(0XE2, ctx->r3) = ctx->r14;
L_8001DC78:
    // 0x8001DC78: lw          $a2, 0x0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X0);
L_8001DC7C:
    // 0x8001DC7C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x8001DC80: bnel        $t9, $zero, L_8001DBA0
    if (ctx->r25 != 0) {
        // 0x8001DC84: lh          $t6, 0x2E($a2)
        ctx->r14 = MEM_H(ctx->r6, 0X2E);
            goto L_8001DBA0;
    }
    goto skip_7;
    // 0x8001DC84: lh          $t6, 0x2E($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X2E);
    skip_7:
    // 0x8001DC88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001DC8C:
    // 0x8001DC8C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8001DC90: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8001DC98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8001DC98: addiu       $sp, $sp, -0x138
    ctx->r29 = ADD32(ctx->r29, -0X138);
    // 0x8001DC9C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8001DCA0: lh          $t7, -0x6B80($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X6B80);
    // 0x8001DCA4: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8001DCA8: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8001DCAC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8001DCB0: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8001DCB4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8001DCB8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8001DCBC: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8001DCC0: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8001DCC4: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8001DCC8: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8001DCCC: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8001DCD0: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8001DCD4: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8001DCD8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8001DCDC: sw          $zero, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = 0;
    // 0x8001DCE0: sw          $zero, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = 0;
    // 0x8001DCE4: sh          $zero, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = 0;
    // 0x8001DCE8: sh          $t6, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = ctx->r14;
    // 0x8001DCEC: beq         $t7, $zero, L_8001DD38
    if (ctx->r15 == 0) {
        // 0x8001DCF0: sh          $zero, 0x66($sp)
        MEM_H(0X66, ctx->r29) = 0;
            goto L_8001DD38;
    }
    // 0x8001DCF0: sh          $zero, 0x66($sp)
    MEM_H(0X66, ctx->r29) = 0;
    // 0x8001DCF4: jal         0x8004B1E0
    // 0x8001DCF8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8004B1E0(rdram, ctx);
        goto after_0;
    // 0x8001DCF8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x8001DCFC: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
L_8001DD00:
    // 0x8001DD00: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001DD04: bne         $t8, $at, L_8001DD28
    if (ctx->r24 != ctx->r1) {
        // 0x8001DD08: nop
    
            goto L_8001DD28;
    }
    // 0x8001DD08: nop

    // 0x8001DD0C: jal         0x8004B21C
    // 0x8001DD10: nop

    func_8004B21C(rdram, ctx);
        goto after_1;
    // 0x8001DD10: nop

    after_1:
    // 0x8001DD14: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
L_8001DD18:
    // 0x8001DD18: jal         0x8000798C
    // 0x8001DD1C: nop

    func_8000798C(rdram, ctx);
        goto after_2;
    // 0x8001DD1C: nop

    after_2:
    // 0x8001DD20: b           L_8001DD18
    // 0x8001DD24: nop

        goto L_8001DD18;
    // 0x8001DD24: nop

L_8001DD28:
    // 0x8001DD28: jal         0x8000798C
    // 0x8001DD2C: nop

    func_8000798C(rdram, ctx);
        goto after_3;
    // 0x8001DD2C: nop

    after_3:
    // 0x8001DD30: b           L_8001DD00
    // 0x8001DD34: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
        goto L_8001DD00;
    // 0x8001DD34: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
L_8001DD38:
    // 0x8001DD38: jal         0x8004B1E0
    // 0x8001DD3C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8004B1E0(rdram, ctx);
        goto after_4;
    // 0x8001DD3C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x8001DD40: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8001DD44: sw          $t9, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r25;
    // 0x8001DD48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001DD4C: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x8001DD50: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x8001DD54: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x8001DD58: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001DD5C: jal         0x8004C580
    // 0x8001DD60: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_5;
    // 0x8001DD60: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_5:
    // 0x8001DD64: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8001DD68: sh          $t6, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r14;
    // 0x8001DD6C: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
    // 0x8001DD70: addiu       $a0, $zero, 0x6A
    ctx->r4 = ADD32(0, 0X6A);
    // 0x8001DD74: addiu       $a1, $zero, 0x5F
    ctx->r5 = ADD32(0, 0X5F);
    // 0x8001DD78: addiu       $a2, $zero, -0x3FFF
    ctx->r6 = ADD32(0, -0X3FFF);
    // 0x8001DD7C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001DD80: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001DD84: jal         0x8004C580
    // 0x8001DD88: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_6;
    // 0x8001DD88: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_6:
    // 0x8001DD8C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8001DD90: lh          $t7, -0x6B8E($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X6B8E);
    // 0x8001DD94: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8001DD98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001DD9C: bne         $t7, $zero, L_8001DDC0
    if (ctx->r15 != 0) {
        // 0x8001DDA0: addiu       $a1, $zero, -0x64
        ctx->r5 = ADD32(0, -0X64);
            goto L_8001DDC0;
    }
    // 0x8001DDA0: addiu       $a1, $zero, -0x64
    ctx->r5 = ADD32(0, -0X64);
    // 0x8001DDA4: sh          $t8, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = ctx->r24;
    // 0x8001DDA8: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    // 0x8001DDAC: addiu       $a2, $zero, -0x7FFF
    ctx->r6 = ADD32(0, -0X7FFF);
    // 0x8001DDB0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8001DDB4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001DDB8: jal         0x8004C580
    // 0x8001DDBC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_7;
    // 0x8001DDBC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_7:
L_8001DDC0:
    // 0x8001DDC0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001DDC4: lh          $v0, -0x6BA6($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X6BA6);
    // 0x8001DDC8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8001DDCC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8001DDD0: sh          $t6, 0x12E($sp)
    MEM_H(0X12E, ctx->r29) = ctx->r14;
    // 0x8001DDD4: beq         $v0, $zero, L_8001DE70
    if (ctx->r2 == 0) {
        // 0x8001DDD8: sh          $t9, 0x92($sp)
        MEM_H(0X92, ctx->r29) = ctx->r25;
            goto L_8001DE70;
    }
    // 0x8001DDD8: sh          $t9, 0x92($sp)
    MEM_H(0X92, ctx->r29) = ctx->r25;
    // 0x8001DDDC: blez        $v0, L_8001DE8C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001DDE0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8001DE8C;
    }
    // 0x8001DDE0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001DDE4: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8001DDE8: addiu       $s1, $s1, -0x6BC8
    ctx->r17 = ADD32(ctx->r17, -0X6BC8);
    // 0x8001DDEC: addiu       $s0, $sp, 0xCC
    ctx->r16 = ADD32(ctx->r29, 0XCC);
    // 0x8001DDF0: addiu       $t0, $zero, -0x7C
    ctx->r8 = ADD32(0, -0X7C);
L_8001DDF4:
    // 0x8001DDF4: lh          $t7, 0x0($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X0);
    // 0x8001DDF8: addiu       $t8, $zero, 0x63
    ctx->r24 = ADD32(0, 0X63);
    // 0x8001DDFC: sh          $t0, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r8;
    // 0x8001DE00: sh          $t7, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r15;
    // 0x8001DE04: lh          $v0, 0x4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4);
    // 0x8001DE08: sh          $t8, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r24;
    // 0x8001DE0C: lh          $a1, 0x8($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X8);
    // 0x8001DE10: lh          $a0, 0x6($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X6);
    // 0x8001DE14: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x8001DE18: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x8001DE1C: sra         $t9, $a3, 16
    ctx->r25 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8001DE20: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x8001DE24: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    // 0x8001DE28: sw          $v1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r3;
    // 0x8001DE2C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8001DE30: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001DE34: jal         0x8004C580
    // 0x8001DE38: addiu       $a2, $zero, -0x7FFF
    ctx->r6 = ADD32(0, -0X7FFF);
    func_8004C580(rdram, ctx);
        goto after_8;
    // 0x8001DE38: addiu       $a2, $zero, -0x7FFF
    ctx->r6 = ADD32(0, -0X7FFF);
    after_8:
    // 0x8001DE3C: lw          $v1, 0x68($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X68);
    // 0x8001DE40: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x8001DE44: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8001DE48: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8001DE4C: lh          $t6, -0x6BA6($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X6BA6);
    // 0x8001DE50: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001DE54: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8001DE58: slt         $at, $v1, $t6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8001DE5C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8001DE60: bne         $at, $zero, L_8001DDF4
    if (ctx->r1 != 0) {
        // 0x8001DE64: addiu       $t0, $t0, 0x13
        ctx->r8 = ADD32(ctx->r8, 0X13);
            goto L_8001DDF4;
    }
    // 0x8001DE64: addiu       $t0, $t0, 0x13
    ctx->r8 = ADD32(ctx->r8, 0X13);
    // 0x8001DE68: b           L_8001DE90
    // 0x8001DE6C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_8001DE90;
    // 0x8001DE6C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_8001DE70:
    // 0x8001DE70: addiu       $a0, $zero, -0x6A
    ctx->r4 = ADD32(0, -0X6A);
    // 0x8001DE74: addiu       $a1, $zero, 0x5F
    ctx->r5 = ADD32(0, 0X5F);
    // 0x8001DE78: addiu       $a2, $zero, -0x3FFF
    ctx->r6 = ADD32(0, -0X3FFF);
    // 0x8001DE7C: addiu       $a3, $zero, 0x4A
    ctx->r7 = ADD32(0, 0X4A);
    // 0x8001DE80: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001DE84: jal         0x8004C580
    // 0x8001DE88: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_9;
    // 0x8001DE88: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_9:
L_8001DE8C:
    // 0x8001DE8C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_8001DE90:
    // 0x8001DE90: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8001DE94: sh          $t8, 0xBE($sp)
    MEM_H(0XBE, ctx->r29) = ctx->r24;
    // 0x8001DE98: sh          $t7, 0xB2($sp)
    MEM_H(0XB2, ctx->r29) = ctx->r15;
    // 0x8001DE9C: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x8001DEA0: addiu       $a1, $zero, 0x5F
    ctx->r5 = ADD32(0, 0X5F);
    // 0x8001DEA4: addiu       $a2, $zero, -0x3FFF
    ctx->r6 = ADD32(0, -0X3FFF);
    // 0x8001DEA8: addiu       $a3, $zero, 0x25
    ctx->r7 = ADD32(0, 0X25);
    // 0x8001DEAC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001DEB0: jal         0x8004C580
    // 0x8001DEB4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_10;
    // 0x8001DEB4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_10:
    // 0x8001DEB8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8001DEBC: sh          $t9, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r25;
    // 0x8001DEC0: addiu       $a0, $zero, 0x65
    ctx->r4 = ADD32(0, 0X65);
    // 0x8001DEC4: addiu       $a1, $zero, -0x67
    ctx->r5 = ADD32(0, -0X67);
    // 0x8001DEC8: addiu       $a2, $zero, -0x3FFF
    ctx->r6 = ADD32(0, -0X3FFF);
    // 0x8001DECC: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    // 0x8001DED0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001DED4: jal         0x8004C580
    // 0x8001DED8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_11;
    // 0x8001DED8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_11:
    // 0x8001DEDC: jal         0x8001CFE0
    // 0x8001DEE0: nop

    func_8001CFE0(rdram, ctx);
        goto after_12;
    // 0x8001DEE0: nop

    after_12:
    // 0x8001DEE4: jal         0x8001D72C
    // 0x8001DEE8: nop

    func_8001D72C(rdram, ctx);
        goto after_13;
    // 0x8001DEE8: nop

    after_13:
    // 0x8001DEEC: addiu       $fp, $sp, 0x9C
    ctx->r30 = ADD32(ctx->r29, 0X9C);
    // 0x8001DEF0: addiu       $s7, $sp, 0xB0
    ctx->r23 = ADD32(ctx->r29, 0XB0);
    // 0x8001DEF4: addiu       $s6, $sp, 0xBC
    ctx->r22 = ADD32(ctx->r29, 0XBC);
    // 0x8001DEF8: addiu       $s5, $zero, 0xA
    ctx->r21 = ADD32(0, 0XA);
    // 0x8001DEFC: addiu       $s4, $sp, 0x90
    ctx->r20 = ADD32(ctx->r29, 0X90);
    // 0x8001DF00: addiu       $s2, $zero, -0x2
    ctx->r18 = ADD32(0, -0X2);
    // 0x8001DF04: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
L_8001DF08:
    // 0x8001DF08: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001DF0C: bne         $v0, $at, L_8001DF94
    if (ctx->r2 != ctx->r1) {
        // 0x8001DF10: nop
    
            goto L_8001DF94;
    }
    // 0x8001DF10: nop

    // 0x8001DF14: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8001DF18: addiu       $ra, $zero, -0x1
    ctx->r31 = ADD32(0, -0X1);
    // 0x8001DF1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001DF20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8001DF24: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8001DF28: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8001DF2C: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x8001DF30: addiu       $s7, $zero, -0x1
    ctx->r23 = ADD32(0, -0X1);
    // 0x8001DF34: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8001DF38: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8001DF3C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8001DF40: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x8001DF44: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x8001DF48: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001DF4C: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x8001DF50: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x8001DF54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001DF58: lh          $t0, 0x90($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X90);
    // 0x8001DF5C: addiu       $a2, $zero, 0x63
    ctx->r6 = ADD32(0, 0X63);
    // 0x8001DF60: addiu       $t1, $zero, 0x1E
    ctx->r9 = ADD32(0, 0X1E);
    // 0x8001DF64: jal         0x8004C4D8
    // 0x8001DF68: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8004C4D8(rdram, ctx);
        goto after_14;
    // 0x8001DF68: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_14:
    // 0x8001DF6C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8001DF70: jal         0x8004C4D8
    // 0x8001DF74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004C4D8(rdram, ctx);
        goto after_15;
    // 0x8001DF74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x8001DF78: jal         0x8004B21C
    // 0x8001DF7C: nop

    func_8004B21C(rdram, ctx);
        goto after_16;
    // 0x8001DF7C: nop

    after_16:
    // 0x8001DF80: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
L_8001DF84:
    // 0x8001DF84: jal         0x8000798C
    // 0x8001DF88: nop

    func_8000798C(rdram, ctx);
        goto after_17;
    // 0x8001DF88: nop

    after_17:
    // 0x8001DF8C: b           L_8001DF84
    // 0x8001DF90: nop

        goto L_8001DF84;
    // 0x8001DF90: nop

L_8001DF94:
    // 0x8001DF94: bne         $s2, $v0, L_8001DFB8
    if (ctx->r18 != ctx->r2) {
        // 0x8001DF98: nop
    
            goto L_8001DFB8;
    }
    // 0x8001DF98: nop

    // 0x8001DF9C: bne         $s2, $v0, L_8001DFB8
    if (ctx->r18 != ctx->r2) {
        // 0x8001DFA0: nop
    
            goto L_8001DFB8;
    }
    // 0x8001DFA0: nop

L_8001DFA4:
    // 0x8001DFA4: jal         0x8000798C
    // 0x8001DFA8: nop

    func_8000798C(rdram, ctx);
        goto after_18;
    // 0x8001DFA8: nop

    after_18:
    // 0x8001DFAC: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x8001DFB0: beq         $s2, $t8, L_8001DFA4
    if (ctx->r18 == ctx->r24) {
        // 0x8001DFB4: nop
    
            goto L_8001DFA4;
    }
    // 0x8001DFB4: nop

L_8001DFB8:
    // 0x8001DFB8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001DFBC: lw          $v0, -0x6BDC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6BDC);
    // 0x8001DFC0: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
    // 0x8001DFC4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001DFC8: beq         $t9, $v0, L_8001E01C
    if (ctx->r25 == ctx->r2) {
        // 0x8001DFCC: nop
    
            goto L_8001E01C;
    }
    // 0x8001DFCC: nop

    // 0x8001DFD0: beql        $t9, $at, L_8001DFEC
    if (ctx->r25 == ctx->r1) {
        // 0x8001DFD4: sw          $v0, 0xC4($sp)
        MEM_W(0XC4, ctx->r29) = ctx->r2;
            goto L_8001DFEC;
    }
    goto skip_0;
    // 0x8001DFD4: sw          $v0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r2;
    skip_0:
    // 0x8001DFD8: jal         0x8004C444
    // 0x8001DFDC: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    func_8004C444(rdram, ctx);
        goto after_19;
    // 0x8001DFDC: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    after_19:
    // 0x8001DFE0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001DFE4: lw          $v0, -0x6BDC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6BDC);
    // 0x8001DFE8: sw          $v0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r2;
L_8001DFEC:
    // 0x8001DFEC: addiu       $a0, $zero, -0x1D
    ctx->r4 = ADD32(0, -0X1D);
    // 0x8001DFF0: addiu       $a1, $zero, 0x58
    ctx->r5 = ADD32(0, 0X58);
    // 0x8001DFF4: jal         0x8004C388
    // 0x8001DFF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004C388(rdram, ctx);
        goto after_20;
    // 0x8001DFF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_20:
    // 0x8001DFFC: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x8001E000: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x8001E004: lw          $a3, -0x6BDC($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X6BDC);
    // 0x8001E008: addiu       $a2, $a2, 0x65A4
    ctx->r6 = ADD32(ctx->r6, 0X65A4);
    // 0x8001E00C: addiu       $a0, $zero, -0xFF
    ctx->r4 = ADD32(0, -0XFF);
    // 0x8001E010: jal         0x8004C340
    // 0x8001E014: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004C340(rdram, ctx);
        goto after_21;
    // 0x8001E014: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x8001E018: sw          $v0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r2;
L_8001E01C:
    // 0x8001E01C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8001E020: lh          $t7, -0x6932($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X6932);
    // 0x8001E024: lh          $t6, 0x82($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X82);
    // 0x8001E028: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8001E02C: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x8001E030: bne         $t6, $t7, L_8001E044
    if (ctx->r14 != ctx->r15) {
        // 0x8001E034: nop
    
            goto L_8001E044;
    }
    // 0x8001E034: nop

    // 0x8001E038: lh          $t8, -0x6938($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X6938);
    // 0x8001E03C: bgtz        $t8, L_8001E09C
    if (SIGNED(ctx->r24) > 0) {
        // 0x8001E040: nop
    
            goto L_8001E09C;
    }
    // 0x8001E040: nop

L_8001E044:
    // 0x8001E044: beq         $t9, $zero, L_8001E054
    if (ctx->r25 == 0) {
        // 0x8001E048: or          $a0, $t9, $zero
        ctx->r4 = ctx->r25 | 0;
            goto L_8001E054;
    }
    // 0x8001E048: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x8001E04C: jal         0x8004C444
    // 0x8001E050: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
    func_8004C444(rdram, ctx);
        goto after_22;
    // 0x8001E050: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
    after_22:
L_8001E054:
    // 0x8001E054: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8001E058: lh          $t7, -0x6938($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X6938);
    // 0x8001E05C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8001E060: lh          $t6, -0x6932($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X6932);
    // 0x8001E064: addiu       $a0, $zero, 0x6A
    ctx->r4 = ADD32(0, 0X6A);
    // 0x8001E068: blez        $t7, L_8001E09C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8001E06C: sh          $t6, 0x82($sp)
        MEM_H(0X82, ctx->r29) = ctx->r14;
            goto L_8001E09C;
    }
    // 0x8001E06C: sh          $t6, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r14;
    // 0x8001E070: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x8001E074: beq         $at, $zero, L_8001E080
    if (ctx->r1 == 0) {
        // 0x8001E078: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8001E080;
    }
    // 0x8001E078: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8001E07C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_8001E080:
    // 0x8001E080: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    // 0x8001E084: addiu       $a2, $zero, -0x3FFF
    ctx->r6 = ADD32(0, -0X3FFF);
    // 0x8001E088: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8001E08C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8001E090: jal         0x8004C580
    // 0x8001E094: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_23;
    // 0x8001E094: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_23:
    // 0x8001E098: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
L_8001E09C:
    // 0x8001E09C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8001E0A0: lh          $t8, -0x6B8E($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X6B8E);
    // 0x8001E0A4: addiu       $a0, $zero, -0xA
    ctx->r4 = ADD32(0, -0XA);
    // 0x8001E0A8: lh          $t9, 0x7A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X7A);
    // 0x8001E0AC: beq         $t8, $zero, L_8001E154
    if (ctx->r24 == 0) {
        // 0x8001E0B0: lui         $t7, 0x8013
        ctx->r15 = S32(0X8013 << 16);
            goto L_8001E154;
    }
    // 0x8001E0B0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8001E0B4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8001E0B8: lh          $t9, -0x6B8C($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X6B8C);
    // 0x8001E0BC: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x8001E0C0: addiu       $a1, $zero, -0x64
    ctx->r5 = ADD32(0, -0X64);
    // 0x8001E0C4: slti        $at, $t9, 0x12C
    ctx->r1 = SIGNED(ctx->r25) < 0X12C ? 1 : 0;
    // 0x8001E0C8: beq         $at, $zero, L_8001E0D8
    if (ctx->r1 == 0) {
        // 0x8001E0CC: nop
    
            goto L_8001E0D8;
    }
    // 0x8001E0CC: nop

    // 0x8001E0D0: b           L_8001E0D8
    // 0x8001E0D4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_8001E0D8;
    // 0x8001E0D4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8001E0D8:
    // 0x8001E0D8: jal         0x8004C388
    // 0x8001E0DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004C388(rdram, ctx);
        goto after_24;
    // 0x8001E0DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_24:
    // 0x8001E0E0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001E0E4: lh          $v0, -0x6B8C($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X6B8C);
    // 0x8001E0E8: addiu       $v1, $zero, 0x708
    ctx->r3 = ADD32(0, 0X708);
    // 0x8001E0EC: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    // 0x8001E0F0: div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // 0x8001E0F4: mfhi        $t6
    ctx->r14 = hi;
    // 0x8001E0F8: mflo        $a3
    ctx->r7 = lo;
    // 0x8001E0FC: sra         $t7, $a1, 16
    ctx->r15 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8001E100: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x8001E104: addiu       $a2, $a2, 0x65AC
    ctx->r6 = ADD32(ctx->r6, 0X65AC);
    // 0x8001E108: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x8001E10C: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x8001E110: bne         $v1, $zero, L_8001E11C
    if (ctx->r3 != 0) {
        // 0x8001E114: nop
    
            goto L_8001E11C;
    }
    // 0x8001E114: nop

    // 0x8001E118: break       7
    do_break(2147606808);
L_8001E11C:
    // 0x8001E11C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001E120: bne         $v1, $at, L_8001E134
    if (ctx->r3 != ctx->r1) {
        // 0x8001E124: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001E134;
    }
    // 0x8001E124: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001E128: bne         $v0, $at, L_8001E134
    if (ctx->r2 != ctx->r1) {
        // 0x8001E12C: nop
    
            goto L_8001E134;
    }
    // 0x8001E12C: nop

    // 0x8001E130: break       6
    do_break(2147606832);
L_8001E134:
    // 0x8001E134: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x8001E138: div         $zero, $t6, $at
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r1)));
    // 0x8001E13C: mflo        $t8
    ctx->r24 = lo;
    // 0x8001E140: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8001E144: jal         0x8004C340
    // 0x8001E148: nop

    func_8004C340(rdram, ctx);
        goto after_25;
    // 0x8001E148: nop

    after_25:
    // 0x8001E14C: b           L_8001E20C
    // 0x8001E150: nop

        goto L_8001E20C;
    // 0x8001E150: nop

L_8001E154:
    // 0x8001E154: lh          $t7, -0x68D2($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X68D2);
    // 0x8001E158: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8001E15C: bnel        $t9, $t7, L_8001E174
    if (ctx->r25 != ctx->r15) {
        // 0x8001E160: lw          $t8, 0x74($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X74);
            goto L_8001E174;
    }
    goto skip_1;
    // 0x8001E160: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    skip_1:
    // 0x8001E164: lh          $t6, -0x6938($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X6938);
    // 0x8001E168: bgtz        $t6, L_8001E1C8
    if (SIGNED(ctx->r14) > 0) {
        // 0x8001E16C: nop
    
            goto L_8001E1C8;
    }
    // 0x8001E16C: nop

    // 0x8001E170: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
L_8001E174:
    // 0x8001E174: beq         $t8, $zero, L_8001E184
    if (ctx->r24 == 0) {
        // 0x8001E178: or          $a0, $t8, $zero
        ctx->r4 = ctx->r24 | 0;
            goto L_8001E184;
    }
    // 0x8001E178: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8001E17C: jal         0x8004C444
    // 0x8001E180: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    func_8004C444(rdram, ctx);
        goto after_26;
    // 0x8001E180: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    after_26:
L_8001E184:
    // 0x8001E184: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8001E188: lw          $t7, -0x68DC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X68DC);
    // 0x8001E18C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8001E190: lh          $t9, -0x68D2($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X68D2);
    // 0x8001E194: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001E198: beq         $t7, $zero, L_8001E1C8
    if (ctx->r15 == 0) {
        // 0x8001E19C: sh          $t9, 0x7A($sp)
        MEM_H(0X7A, ctx->r29) = ctx->r25;
            goto L_8001E1C8;
    }
    // 0x8001E19C: sh          $t9, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = ctx->r25;
    // 0x8001E1A0: bne         $t9, $zero, L_8001E1AC
    if (ctx->r25 != 0) {
        // 0x8001E1A4: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_8001E1AC;
    }
    // 0x8001E1A4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8001E1A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001E1AC:
    // 0x8001E1AC: addiu       $a1, $zero, -0x64
    ctx->r5 = ADD32(0, -0X64);
    // 0x8001E1B0: addiu       $a2, $zero, -0x7FFF
    ctx->r6 = ADD32(0, -0X7FFF);
    // 0x8001E1B4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8001E1B8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8001E1BC: jal         0x8004C580
    // 0x8001E1C0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_27;
    // 0x8001E1C0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_27:
    // 0x8001E1C4: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
L_8001E1C8:
    // 0x8001E1C8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8001E1CC: lh          $t6, -0x68D2($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X68D2);
    // 0x8001E1D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001E1D4: addiu       $a1, $zero, -0x50
    ctx->r5 = ADD32(0, -0X50);
    // 0x8001E1D8: slti        $at, $t6, 0x14
    ctx->r1 = SIGNED(ctx->r14) < 0X14 ? 1 : 0;
    // 0x8001E1DC: beq         $at, $zero, L_8001E20C
    if (ctx->r1 == 0) {
        // 0x8001E1E0: nop
    
            goto L_8001E20C;
    }
    // 0x8001E1E0: nop

    // 0x8001E1E4: lhu         $s0, 0x66($sp)
    ctx->r16 = MEM_HU(ctx->r29, 0X66);
    // 0x8001E1E8: addiu       $a3, $zero, 0x52
    ctx->r7 = ADD32(0, 0X52);
    // 0x8001E1EC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001E1F0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8001E1F4: sll         $t8, $a2, 24
    ctx->r24 = S32(ctx->r6 << 24);
    // 0x8001E1F8: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8001E1FC: jal         0x8004C580
    // 0x8001E200: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_28;
    // 0x8001E200: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_28:
    // 0x8001E204: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x8001E208: sh          $t9, 0x66($sp)
    MEM_H(0X66, ctx->r29) = ctx->r25;
L_8001E20C:
    // 0x8001E20C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8001E210: lh          $t6, -0x6BA6($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X6BA6);
    // 0x8001E214: beq         $t6, $zero, L_8001E538
    if (ctx->r14 == 0) {
        // 0x8001E218: nop
    
            goto L_8001E538;
    }
    // 0x8001E218: nop

    // 0x8001E21C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8001E220: lh          $t7, -0x6944($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X6944);
    // 0x8001E224: lh          $t8, 0x12E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X12E);
    // 0x8001E228: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001E22C: beq         $t8, $t7, L_8001E368
    if (ctx->r24 == ctx->r15) {
        // 0x8001E230: nop
    
            goto L_8001E368;
    }
    // 0x8001E230: nop

    // 0x8001E234: beq         $t8, $at, L_8001E28C
    if (ctx->r24 == ctx->r1) {
        // 0x8001E238: sll         $t9, $t8, 2
        ctx->r25 = S32(ctx->r24 << 2);
            goto L_8001E28C;
    }
    // 0x8001E238: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001E23C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8001E240: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8001E244: addiu       $t6, $sp, 0xCC
    ctx->r14 = ADD32(ctx->r29, 0XCC);
    // 0x8001E248: addu        $s0, $t9, $t6
    ctx->r16 = ADD32(ctx->r25, ctx->r14);
    // 0x8001E24C: jal         0x8004C444
    // 0x8001E250: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_8004C444(rdram, ctx);
        goto after_29;
    // 0x8001E250: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_29:
    // 0x8001E254: lh          $v0, 0x4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4);
    // 0x8001E258: lh          $a0, 0x6($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X6);
    // 0x8001E25C: lh          $a1, 0x8($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X8);
    // 0x8001E260: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x8001E264: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x8001E268: sra         $t7, $a3, 16
    ctx->r15 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8001E26C: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x8001E270: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8001E274: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001E278: jal         0x8004C580
    // 0x8001E27C: addiu       $a2, $zero, -0x7FFF
    ctx->r6 = ADD32(0, -0X7FFF);
    func_8004C580(rdram, ctx);
        goto after_30;
    // 0x8001E27C: addiu       $a2, $zero, -0x7FFF
    ctx->r6 = ADD32(0, -0X7FFF);
    after_30:
    // 0x8001E280: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8001E284: jal         0x8004C444
    // 0x8001E288: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    func_8004C444(rdram, ctx);
        goto after_31;
    // 0x8001E288: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    after_31:
L_8001E28C:
    // 0x8001E28C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8001E290: lh          $t8, -0x6944($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X6944);
    // 0x8001E294: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001E298: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8001E29C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8001E2A0: addu        $a0, $sp, $t9
    ctx->r4 = ADD32(ctx->r29, ctx->r25);
    // 0x8001E2A4: jal         0x8004C444
    // 0x8001E2A8: lw          $a0, 0xCC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XCC);
    func_8004C444(rdram, ctx);
        goto after_32;
    // 0x8001E2A8: lw          $a0, 0xCC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XCC);
    after_32:
    // 0x8001E2AC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8001E2B0: lh          $t6, -0x6944($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X6944);
    // 0x8001E2B4: addiu       $t8, $sp, 0xCC
    ctx->r24 = ADD32(ctx->r29, 0XCC);
    // 0x8001E2B8: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x8001E2BC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001E2C0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8001E2C4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8001E2C8: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
    // 0x8001E2CC: lh          $v0, 0x4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4);
    // 0x8001E2D0: lh          $a0, 0x6($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X6);
    // 0x8001E2D4: lh          $a1, 0x8($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X8);
    // 0x8001E2D8: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x8001E2DC: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x8001E2E0: sra         $t9, $a3, 16
    ctx->r25 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8001E2E4: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x8001E2E8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8001E2EC: jal         0x8004C580
    // 0x8001E2F0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_33;
    // 0x8001E2F0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_33:
    // 0x8001E2F4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001E2F8: lh          $v1, -0x6944($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X6944);
    // 0x8001E2FC: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x8001E300: addiu       $t0, $sp, 0xCC
    ctx->r8 = ADD32(ctx->r29, 0XCC);
    // 0x8001E304: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001E308: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x8001E30C: addiu       $a3, $zero, 0x49
    ctx->r7 = ADD32(0, 0X49);
    // 0x8001E310: mflo        $t6
    ctx->r14 = lo;
    // 0x8001E314: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x8001E318: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x8001E31C: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001E320: mflo        $t8
    ctx->r24 = lo;
    // 0x8001E324: addu        $s0, $t0, $t8
    ctx->r16 = ADD32(ctx->r8, ctx->r24);
    // 0x8001E328: lh          $a1, 0x8($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X8);
    // 0x8001E32C: lh          $a0, 0x6($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X6);
    // 0x8001E330: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8001E334: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x8001E338: sll         $t9, $a1, 16
    ctx->r25 = S32(ctx->r5 << 16);
    // 0x8001E33C: sra         $a1, $t9, 16
    ctx->r5 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8001E340: jal         0x8004C580
    // 0x8001E344: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_34;
    // 0x8001E344: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_34:
    // 0x8001E348: lh          $t8, 0x92($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X92);
    // 0x8001E34C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8001E350: lh          $t7, -0x6944($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X6944);
    // 0x8001E354: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001E358: sw          $v0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r2;
    // 0x8001E35C: beq         $t8, $at, L_8001E368
    if (ctx->r24 == ctx->r1) {
        // 0x8001E360: sh          $t7, 0x12E($sp)
        MEM_H(0X12E, ctx->r29) = ctx->r15;
            goto L_8001E368;
    }
    // 0x8001E360: sh          $t7, 0x12E($sp)
    MEM_H(0X12E, ctx->r29) = ctx->r15;
    // 0x8001E364: sh          $s2, 0x92($sp)
    MEM_H(0X92, ctx->r29) = ctx->r18;
L_8001E368:
    // 0x8001E368: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8001E36C: lh          $t9, -0x6944($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X6944);
    // 0x8001E370: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001E374: lh          $t7, 0x92($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X92);
    // 0x8001E378: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8001E37C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8001E380: lh          $v0, -0x6BC6($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X6BC6);
    // 0x8001E384: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001E388: beq         $v0, $t7, L_8001E538
    if (ctx->r2 == ctx->r15) {
        // 0x8001E38C: sh          $v0, 0x90($sp)
        MEM_H(0X90, ctx->r29) = ctx->r2;
            goto L_8001E538;
    }
    // 0x8001E38C: sh          $v0, 0x90($sp)
    MEM_H(0X90, ctx->r29) = ctx->r2;
    // 0x8001E390: beq         $t7, $at, L_8001E3AC
    if (ctx->r15 == ctx->r1) {
        // 0x8001E394: addiu       $s0, $sp, 0x84
        ctx->r16 = ADD32(ctx->r29, 0X84);
            goto L_8001E3AC;
    }
    // 0x8001E394: addiu       $s0, $sp, 0x84
    ctx->r16 = ADD32(ctx->r29, 0X84);
L_8001E398:
    // 0x8001E398: jal         0x8004C444
    // 0x8001E39C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_8004C444(rdram, ctx);
        goto after_35;
    // 0x8001E39C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_35:
    // 0x8001E3A0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8001E3A4: bne         $s0, $s4, L_8001E398
    if (ctx->r16 != ctx->r20) {
        // 0x8001E3A8: nop
    
            goto L_8001E398;
    }
    // 0x8001E3A8: nop

L_8001E3AC:
    // 0x8001E3AC: lh          $v1, 0x90($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X90);
    // 0x8001E3B0: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8001E3B4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8001E3B8: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x8001E3BC: lh          $t8, -0x6944($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X6944);
    // 0x8001E3C0: addiu       $t6, $sp, 0xCC
    ctx->r14 = ADD32(ctx->r29, 0XCC);
    // 0x8001E3C4: mflo        $a3
    ctx->r7 = lo;
    // 0x8001E3C8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001E3CC: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8001E3D0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8001E3D4: addu        $s0, $t9, $t6
    ctx->r16 = ADD32(ctx->r25, ctx->r14);
    // 0x8001E3D8: lh          $s1, 0x6($s0)
    ctx->r17 = MEM_H(ctx->r16, 0X6);
    // 0x8001E3DC: lh          $t6, 0x8($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X8);
    // 0x8001E3E0: addiu       $a3, $a3, 0x1A
    ctx->r7 = ADD32(ctx->r7, 0X1A);
    // 0x8001E3E4: addiu       $s1, $s1, -0x5
    ctx->r17 = ADD32(ctx->r17, -0X5);
    // 0x8001E3E8: sll         $t7, $s1, 16
    ctx->r15 = S32(ctx->r17 << 16);
    // 0x8001E3EC: addiu       $a1, $t6, -0x9
    ctx->r5 = ADD32(ctx->r14, -0X9);
    // 0x8001E3F0: sra         $s1, $t7, 16
    ctx->r17 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8001E3F4: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x8001E3F8: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x8001E3FC: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8001E400: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001E404: sll         $t6, $a3, 16
    ctx->r14 = S32(ctx->r7 << 16);
    // 0x8001E408: sra         $a3, $t6, 16
    ctx->r7 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8001E40C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8001E410: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8001E414: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8001E418: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001E41C: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x8001E420: jal         0x8004C580
    // 0x8001E424: sh          $v1, 0x92($sp)
    MEM_H(0X92, ctx->r29) = ctx->r3;
    func_8004C580(rdram, ctx);
        goto after_36;
    // 0x8001E424: sh          $v1, 0x92($sp)
    MEM_H(0X92, ctx->r29) = ctx->r3;
    after_36:
    // 0x8001E428: lh          $t7, 0x90($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X90);
    // 0x8001E42C: addiu       $a0, $s1, 0x5
    ctx->r4 = ADD32(ctx->r17, 0X5);
    // 0x8001E430: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x8001E434: div         $zero, $t7, $s5
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r21)));
    // 0x8001E438: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8001E43C: mflo        $t8
    ctx->r24 = lo;
    // 0x8001E440: lw          $s0, 0x5C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X5C);
    // 0x8001E444: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x8001E448: div         $zero, $t8, $s5
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r21)));
    // 0x8001E44C: mfhi        $a3
    ctx->r7 = hi;
    // 0x8001E450: addiu       $a3, $a3, 0x1A
    ctx->r7 = ADD32(ctx->r7, 0X1A);
    // 0x8001E454: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    // 0x8001E458: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8001E45C: sll         $t9, $a3, 16
    ctx->r25 = S32(ctx->r7 << 16);
    // 0x8001E460: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    // 0x8001E464: sra         $a3, $t9, 16
    ctx->r7 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8001E468: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8001E46C: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x8001E470: bne         $s5, $zero, L_8001E47C
    if (ctx->r21 != 0) {
        // 0x8001E474: nop
    
            goto L_8001E47C;
    }
    // 0x8001E474: nop

    // 0x8001E478: break       7
    do_break(2147607672);
L_8001E47C:
    // 0x8001E47C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001E480: bne         $s5, $at, L_8001E494
    if (ctx->r21 != ctx->r1) {
        // 0x8001E484: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001E494;
    }
    // 0x8001E484: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001E488: bne         $t7, $at, L_8001E494
    if (ctx->r15 != ctx->r1) {
        // 0x8001E48C: nop
    
            goto L_8001E494;
    }
    // 0x8001E48C: nop

    // 0x8001E490: break       6
    do_break(2147607696);
L_8001E494:
    // 0x8001E494: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001E498: bne         $s5, $zero, L_8001E4A4
    if (ctx->r21 != 0) {
        // 0x8001E49C: nop
    
            goto L_8001E4A4;
    }
    // 0x8001E49C: nop

    // 0x8001E4A0: break       7
    do_break(2147607712);
L_8001E4A4:
    // 0x8001E4A4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001E4A8: bne         $s5, $at, L_8001E4BC
    if (ctx->r21 != ctx->r1) {
        // 0x8001E4AC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001E4BC;
    }
    // 0x8001E4AC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001E4B0: bne         $t8, $at, L_8001E4BC
    if (ctx->r24 != ctx->r1) {
        // 0x8001E4B4: nop
    
            goto L_8001E4BC;
    }
    // 0x8001E4B4: nop

    // 0x8001E4B8: break       6
    do_break(2147607736);
L_8001E4BC:
    // 0x8001E4BC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8001E4C0: jal         0x8004C580
    // 0x8001E4C4: nop

    func_8004C580(rdram, ctx);
        goto after_37;
    // 0x8001E4C4: nop

    after_37:
    // 0x8001E4C8: lh          $t6, 0x90($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X90);
    // 0x8001E4CC: addiu       $a0, $s1, 0xA
    ctx->r4 = ADD32(ctx->r17, 0XA);
    // 0x8001E4D0: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x8001E4D4: div         $zero, $t6, $s5
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r21)));
    // 0x8001E4D8: mfhi        $a3
    ctx->r7 = hi;
    // 0x8001E4DC: addiu       $a3, $a3, 0x1A
    ctx->r7 = ADD32(ctx->r7, 0X1A);
    // 0x8001E4E0: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8001E4E4: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    // 0x8001E4E8: sra         $t9, $a1, 16
    ctx->r25 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8001E4EC: sll         $t7, $a3, 16
    ctx->r15 = S32(ctx->r7 << 16);
    // 0x8001E4F0: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    // 0x8001E4F4: sra         $a3, $t7, 16
    ctx->r7 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8001E4F8: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x8001E4FC: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8001E500: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x8001E504: bne         $s5, $zero, L_8001E510
    if (ctx->r21 != 0) {
        // 0x8001E508: nop
    
            goto L_8001E510;
    }
    // 0x8001E508: nop

    // 0x8001E50C: break       7
    do_break(2147607820);
L_8001E510:
    // 0x8001E510: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001E514: bne         $s5, $at, L_8001E528
    if (ctx->r21 != ctx->r1) {
        // 0x8001E518: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001E528;
    }
    // 0x8001E518: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001E51C: bne         $t6, $at, L_8001E528
    if (ctx->r14 != ctx->r1) {
        // 0x8001E520: nop
    
            goto L_8001E528;
    }
    // 0x8001E520: nop

    // 0x8001E524: break       6
    do_break(2147607844);
L_8001E528:
    // 0x8001E528: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001E52C: jal         0x8004C580
    // 0x8001E530: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_38;
    // 0x8001E530: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_38:
    // 0x8001E534: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
L_8001E538:
    // 0x8001E538: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001E53C: lh          $v0, -0x6624($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X6624);
    // 0x8001E540: lh          $t9, 0xBE($sp)
    ctx->r25 = MEM_H(ctx->r29, 0XBE);
    // 0x8001E544: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001E548: beq         $t9, $v0, L_8001E62C
    if (ctx->r25 == ctx->r2) {
        // 0x8001E54C: nop
    
            goto L_8001E62C;
    }
    // 0x8001E54C: nop

    // 0x8001E550: beq         $t9, $at, L_8001E578
    if (ctx->r25 == ctx->r1) {
        // 0x8001E554: nop
    
            goto L_8001E578;
    }
    // 0x8001E554: nop

    // 0x8001E558: addiu       $s0, $sp, 0xB4
    ctx->r16 = ADD32(ctx->r29, 0XB4);
L_8001E55C:
    // 0x8001E55C: jal         0x8004C444
    // 0x8001E560: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_8004C444(rdram, ctx);
        goto after_39;
    // 0x8001E560: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_39:
    // 0x8001E564: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8001E568: bne         $s0, $s6, L_8001E55C
    if (ctx->r16 != ctx->r22) {
        // 0x8001E56C: nop
    
            goto L_8001E55C;
    }
    // 0x8001E56C: nop

    // 0x8001E570: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001E574: lh          $v0, -0x6624($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X6624);
L_8001E578:
    // 0x8001E578: div         $zero, $v0, $s5
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r21)));
    // 0x8001E57C: mflo        $a3
    ctx->r7 = lo;
    // 0x8001E580: addiu       $a3, $a3, 0x1A
    ctx->r7 = ADD32(ctx->r7, 0X1A);
    // 0x8001E584: sll         $t6, $a3, 16
    ctx->r14 = S32(ctx->r7 << 16);
    // 0x8001E588: sh          $v0, 0xBE($sp)
    MEM_H(0XBE, ctx->r29) = ctx->r2;
    // 0x8001E58C: sra         $a3, $t6, 16
    ctx->r7 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8001E590: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    // 0x8001E594: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    // 0x8001E598: addiu       $a2, $zero, -0x3FFF
    ctx->r6 = ADD32(0, -0X3FFF);
    // 0x8001E59C: bne         $s5, $zero, L_8001E5A8
    if (ctx->r21 != 0) {
        // 0x8001E5A0: nop
    
            goto L_8001E5A8;
    }
    // 0x8001E5A0: nop

    // 0x8001E5A4: break       7
    do_break(2147607972);
L_8001E5A8:
    // 0x8001E5A8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001E5AC: bne         $s5, $at, L_8001E5C0
    if (ctx->r21 != ctx->r1) {
        // 0x8001E5B0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001E5C0;
    }
    // 0x8001E5B0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001E5B4: bne         $v0, $at, L_8001E5C0
    if (ctx->r2 != ctx->r1) {
        // 0x8001E5B8: nop
    
            goto L_8001E5C0;
    }
    // 0x8001E5B8: nop

    // 0x8001E5BC: break       6
    do_break(2147607996);
L_8001E5C0:
    // 0x8001E5C0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001E5C4: jal         0x8004C580
    // 0x8001E5C8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_40;
    // 0x8001E5C8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_40:
    // 0x8001E5CC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8001E5D0: lh          $t8, -0x6624($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X6624);
    // 0x8001E5D4: sw          $v0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r2;
    // 0x8001E5D8: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x8001E5DC: div         $zero, $t8, $s5
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r21)));
    // 0x8001E5E0: mfhi        $a3
    ctx->r7 = hi;
    // 0x8001E5E4: addiu       $a3, $a3, 0x1A
    ctx->r7 = ADD32(ctx->r7, 0X1A);
    // 0x8001E5E8: sll         $t9, $a3, 16
    ctx->r25 = S32(ctx->r7 << 16);
    // 0x8001E5EC: sra         $a3, $t9, 16
    ctx->r7 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8001E5F0: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    // 0x8001E5F4: addiu       $a2, $zero, -0x3FFF
    ctx->r6 = ADD32(0, -0X3FFF);
    // 0x8001E5F8: bne         $s5, $zero, L_8001E604
    if (ctx->r21 != 0) {
        // 0x8001E5FC: nop
    
            goto L_8001E604;
    }
    // 0x8001E5FC: nop

    // 0x8001E600: break       7
    do_break(2147608064);
L_8001E604:
    // 0x8001E604: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001E608: bne         $s5, $at, L_8001E61C
    if (ctx->r21 != ctx->r1) {
        // 0x8001E60C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001E61C;
    }
    // 0x8001E60C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001E610: bne         $t8, $at, L_8001E61C
    if (ctx->r24 != ctx->r1) {
        // 0x8001E614: nop
    
            goto L_8001E61C;
    }
    // 0x8001E614: nop

    // 0x8001E618: break       6
    do_break(2147608088);
L_8001E61C:
    // 0x8001E61C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001E620: jal         0x8004C580
    // 0x8001E624: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_41;
    // 0x8001E624: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_41:
    // 0x8001E628: sw          $v0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r2;
L_8001E62C:
    // 0x8001E62C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001E630: lh          $v0, -0x6622($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X6622);
    // 0x8001E634: lh          $t7, 0xB2($sp)
    ctx->r15 = MEM_H(ctx->r29, 0XB2);
    // 0x8001E638: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001E63C: beq         $t7, $v0, L_8001E720
    if (ctx->r15 == ctx->r2) {
        // 0x8001E640: nop
    
            goto L_8001E720;
    }
    // 0x8001E640: nop

    // 0x8001E644: beq         $t7, $at, L_8001E66C
    if (ctx->r15 == ctx->r1) {
        // 0x8001E648: nop
    
            goto L_8001E66C;
    }
    // 0x8001E648: nop

    // 0x8001E64C: addiu       $s0, $sp, 0xA8
    ctx->r16 = ADD32(ctx->r29, 0XA8);
L_8001E650:
    // 0x8001E650: jal         0x8004C444
    // 0x8001E654: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_8004C444(rdram, ctx);
        goto after_42;
    // 0x8001E654: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_42:
    // 0x8001E658: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8001E65C: bne         $s0, $s7, L_8001E650
    if (ctx->r16 != ctx->r23) {
        // 0x8001E660: nop
    
            goto L_8001E650;
    }
    // 0x8001E660: nop

    // 0x8001E664: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001E668: lh          $v0, -0x6622($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X6622);
L_8001E66C:
    // 0x8001E66C: div         $zero, $v0, $s5
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r21)));
    // 0x8001E670: mflo        $a3
    ctx->r7 = lo;
    // 0x8001E674: addiu       $a3, $a3, 0x1A
    ctx->r7 = ADD32(ctx->r7, 0X1A);
    // 0x8001E678: sll         $t8, $a3, 16
    ctx->r24 = S32(ctx->r7 << 16);
    // 0x8001E67C: sh          $v0, 0xB2($sp)
    MEM_H(0XB2, ctx->r29) = ctx->r2;
    // 0x8001E680: sra         $a3, $t8, 16
    ctx->r7 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8001E684: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    // 0x8001E688: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    // 0x8001E68C: addiu       $a2, $zero, -0x3FFF
    ctx->r6 = ADD32(0, -0X3FFF);
    // 0x8001E690: bne         $s5, $zero, L_8001E69C
    if (ctx->r21 != 0) {
        // 0x8001E694: nop
    
            goto L_8001E69C;
    }
    // 0x8001E694: nop

    // 0x8001E698: break       7
    do_break(2147608216);
L_8001E69C:
    // 0x8001E69C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001E6A0: bne         $s5, $at, L_8001E6B4
    if (ctx->r21 != ctx->r1) {
        // 0x8001E6A4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001E6B4;
    }
    // 0x8001E6A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001E6A8: bne         $v0, $at, L_8001E6B4
    if (ctx->r2 != ctx->r1) {
        // 0x8001E6AC: nop
    
            goto L_8001E6B4;
    }
    // 0x8001E6AC: nop

    // 0x8001E6B0: break       6
    do_break(2147608240);
L_8001E6B4:
    // 0x8001E6B4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001E6B8: jal         0x8004C580
    // 0x8001E6BC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_43;
    // 0x8001E6BC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_43:
    // 0x8001E6C0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8001E6C4: lh          $t6, -0x6622($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X6622);
    // 0x8001E6C8: sw          $v0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r2;
    // 0x8001E6CC: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    // 0x8001E6D0: div         $zero, $t6, $s5
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r21)));
    // 0x8001E6D4: mfhi        $a3
    ctx->r7 = hi;
    // 0x8001E6D8: addiu       $a3, $a3, 0x1A
    ctx->r7 = ADD32(ctx->r7, 0X1A);
    // 0x8001E6DC: sll         $t7, $a3, 16
    ctx->r15 = S32(ctx->r7 << 16);
    // 0x8001E6E0: sra         $a3, $t7, 16
    ctx->r7 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8001E6E4: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    // 0x8001E6E8: addiu       $a2, $zero, -0x3FFF
    ctx->r6 = ADD32(0, -0X3FFF);
    // 0x8001E6EC: bne         $s5, $zero, L_8001E6F8
    if (ctx->r21 != 0) {
        // 0x8001E6F0: nop
    
            goto L_8001E6F8;
    }
    // 0x8001E6F0: nop

    // 0x8001E6F4: break       7
    do_break(2147608308);
L_8001E6F8:
    // 0x8001E6F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001E6FC: bne         $s5, $at, L_8001E710
    if (ctx->r21 != ctx->r1) {
        // 0x8001E700: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001E710;
    }
    // 0x8001E700: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001E704: bne         $t6, $at, L_8001E710
    if (ctx->r14 != ctx->r1) {
        // 0x8001E708: nop
    
            goto L_8001E710;
    }
    // 0x8001E708: nop

    // 0x8001E70C: break       6
    do_break(2147608332);
L_8001E710:
    // 0x8001E710: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001E714: jal         0x8004C580
    // 0x8001E718: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_44;
    // 0x8001E718: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_44:
    // 0x8001E71C: sw          $v0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r2;
L_8001E720:
    // 0x8001E720: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8001E724: lh          $t9, -0x65F8($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X65F8);
    // 0x8001E728: beq         $t9, $zero, L_8001E800
    if (ctx->r25 == 0) {
        // 0x8001E72C: nop
    
            goto L_8001E800;
    }
    // 0x8001E72C: nop

    // 0x8001E730: jal         0x8004F7C0
    // 0x8001E734: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_8004F7C0(rdram, ctx);
        goto after_45;
    // 0x8001E734: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_45:
    // 0x8001E738: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8001E73C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001E740: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x8001E744: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001E748: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8001E74C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001E750: ldc1        $f4, 0x65C0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X65C0);
    // 0x8001E754: cvt.d.s     $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f18.d = CVT_D_S(ctx->f20.fl);
    // 0x8001E758: addiu       $a1, $zero, 0x66
    ctx->r5 = ADD32(0, 0X66);
    // 0x8001E75C: addiu       $a2, $zero, -0x100
    ctx->r6 = ADD32(0, -0X100);
    // 0x8001E760: addiu       $a3, $zero, 0x26
    ctx->r7 = ADD32(0, 0X26);
    // 0x8001E764: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8001E768: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001E76C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8001E770: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x8001E774: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8001E778: cvt.s.d     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f20.fl = CVT_S_D(ctx->f6.d);
    // 0x8001E77C: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x8001E780: nop

    // 0x8001E784: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x8001E788: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x8001E78C: sra         $t7, $s0, 16
    ctx->r15 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8001E790: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001E794: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x8001E798: jal         0x8004C580
    // 0x8001E79C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_8004C580(rdram, ctx);
        goto after_46;
    // 0x8001E79C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_46:
    // 0x8001E7A0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8001E7A4: lh          $t6, -0x65F8($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X65F8);
    // 0x8001E7A8: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x8001E7AC: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001E7B0: div         $zero, $t6, $s5
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r21)));
    // 0x8001E7B4: mfhi        $a3
    ctx->r7 = hi;
    // 0x8001E7B8: addiu       $a3, $a3, 0x1A
    ctx->r7 = ADD32(ctx->r7, 0X1A);
    // 0x8001E7BC: sll         $t7, $a3, 16
    ctx->r15 = S32(ctx->r7 << 16);
    // 0x8001E7C0: sra         $a3, $t7, 16
    ctx->r7 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8001E7C4: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x8001E7C8: addiu       $a1, $zero, 0x66
    ctx->r5 = ADD32(0, 0X66);
    // 0x8001E7CC: addiu       $a2, $zero, -0x100
    ctx->r6 = ADD32(0, -0X100);
    // 0x8001E7D0: bne         $s5, $zero, L_8001E7DC
    if (ctx->r21 != 0) {
        // 0x8001E7D4: nop
    
            goto L_8001E7DC;
    }
    // 0x8001E7D4: nop

    // 0x8001E7D8: break       7
    do_break(2147608536);
L_8001E7DC:
    // 0x8001E7DC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001E7E0: bne         $s5, $at, L_8001E7F4
    if (ctx->r21 != ctx->r1) {
        // 0x8001E7E4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001E7F4;
    }
    // 0x8001E7E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001E7E8: bne         $t6, $at, L_8001E7F4
    if (ctx->r14 != ctx->r1) {
        // 0x8001E7EC: nop
    
            goto L_8001E7F4;
    }
    // 0x8001E7EC: nop

    // 0x8001E7F0: break       6
    do_break(2147608560);
L_8001E7F4:
    // 0x8001E7F4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001E7F8: jal         0x8004C580
    // 0x8001E7FC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_47;
    // 0x8001E7FC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_47:
L_8001E800:
    // 0x8001E800: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8001E804: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8001E808: lh          $t6, -0x661C($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X661C);
    // 0x8001E80C: lh          $t9, -0x661E($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X661E);
    // 0x8001E810: lh          $t7, 0x9E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X9E);
    // 0x8001E814: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001E818: subu        $v0, $t9, $t6
    ctx->r2 = SUB32(ctx->r25, ctx->r14);
    // 0x8001E81C: beq         $t7, $v0, L_8001E938
    if (ctx->r15 == ctx->r2) {
        // 0x8001E820: nop
    
            goto L_8001E938;
    }
    // 0x8001E820: nop

    // 0x8001E824: beql        $t7, $at, L_8001E86C
    if (ctx->r15 == ctx->r1) {
        // 0x8001E828: sll         $v1, $v0, 16
        ctx->r3 = S32(ctx->r2 << 16);
            goto L_8001E86C;
    }
    goto skip_2;
    // 0x8001E828: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    skip_2:
    // 0x8001E82C: addiu       $s0, $sp, 0x94
    ctx->r16 = ADD32(ctx->r29, 0X94);
L_8001E830:
    // 0x8001E830: jal         0x8004C444
    // 0x8001E834: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_8004C444(rdram, ctx);
        goto after_48;
    // 0x8001E834: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_48:
    // 0x8001E838: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8001E83C: bne         $s0, $fp, L_8001E830
    if (ctx->r16 != ctx->r30) {
        // 0x8001E840: nop
    
            goto L_8001E830;
    }
    // 0x8001E840: nop

    // 0x8001E844: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8001E848: addiu       $a0, $a0, -0x6A20
    ctx->r4 = ADD32(ctx->r4, -0X6A20);
    // 0x8001E84C: jal         0x80044614
    // 0x8001E850: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80044614(rdram, ctx);
        goto after_49;
    // 0x8001E850: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_49:
    // 0x8001E854: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8001E858: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8001E85C: lh          $t9, -0x661C($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X661C);
    // 0x8001E860: lh          $t8, -0x661E($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X661E);
    // 0x8001E864: subu        $v0, $t8, $t9
    ctx->r2 = SUB32(ctx->r24, ctx->r25);
    // 0x8001E868: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
L_8001E86C:
    // 0x8001E86C: sra         $t6, $v1, 16
    ctx->r14 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8001E870: slti        $at, $t6, 0x64
    ctx->r1 = SIGNED(ctx->r14) < 0X64 ? 1 : 0;
    // 0x8001E874: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x8001E878: bne         $at, $zero, L_8001E888
    if (ctx->r1 != 0) {
        // 0x8001E87C: sh          $t6, 0x9E($sp)
        MEM_H(0X9E, ctx->r29) = ctx->r14;
            goto L_8001E888;
    }
    // 0x8001E87C: sh          $t6, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r14;
    // 0x8001E880: addiu       $t7, $zero, 0x63
    ctx->r15 = ADD32(0, 0X63);
    // 0x8001E884: sh          $t7, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r15;
L_8001E888:
    // 0x8001E888: lh          $t8, 0x9E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X9E);
    // 0x8001E88C: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x8001E890: addiu       $a1, $zero, -0x66
    ctx->r5 = ADD32(0, -0X66);
    // 0x8001E894: div         $zero, $t8, $s5
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r21)));
    // 0x8001E898: mflo        $a3
    ctx->r7 = lo;
    // 0x8001E89C: addiu       $a3, $a3, 0x1A
    ctx->r7 = ADD32(ctx->r7, 0X1A);
    // 0x8001E8A0: sll         $t9, $a3, 16
    ctx->r25 = S32(ctx->r7 << 16);
    // 0x8001E8A4: sra         $a3, $t9, 16
    ctx->r7 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8001E8A8: addiu       $a2, $zero, -0x3FFF
    ctx->r6 = ADD32(0, -0X3FFF);
    // 0x8001E8AC: bne         $s5, $zero, L_8001E8B8
    if (ctx->r21 != 0) {
        // 0x8001E8B0: nop
    
            goto L_8001E8B8;
    }
    // 0x8001E8B0: nop

    // 0x8001E8B4: break       7
    do_break(2147608756);
L_8001E8B8:
    // 0x8001E8B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001E8BC: bne         $s5, $at, L_8001E8D0
    if (ctx->r21 != ctx->r1) {
        // 0x8001E8C0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001E8D0;
    }
    // 0x8001E8C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001E8C4: bne         $t8, $at, L_8001E8D0
    if (ctx->r24 != ctx->r1) {
        // 0x8001E8C8: nop
    
            goto L_8001E8D0;
    }
    // 0x8001E8C8: nop

    // 0x8001E8CC: break       6
    do_break(2147608780);
L_8001E8D0:
    // 0x8001E8D0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001E8D4: jal         0x8004C580
    // 0x8001E8D8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_50;
    // 0x8001E8D8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_50:
    // 0x8001E8DC: lh          $t7, 0x9E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X9E);
    // 0x8001E8E0: sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
    // 0x8001E8E4: addiu       $a0, $zero, 0x7D
    ctx->r4 = ADD32(0, 0X7D);
    // 0x8001E8E8: div         $zero, $t7, $s5
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r21)));
    // 0x8001E8EC: mfhi        $a3
    ctx->r7 = hi;
    // 0x8001E8F0: addiu       $a3, $a3, 0x1A
    ctx->r7 = ADD32(ctx->r7, 0X1A);
    // 0x8001E8F4: sll         $t8, $a3, 16
    ctx->r24 = S32(ctx->r7 << 16);
    // 0x8001E8F8: sra         $a3, $t8, 16
    ctx->r7 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8001E8FC: addiu       $a1, $zero, -0x66
    ctx->r5 = ADD32(0, -0X66);
    // 0x8001E900: addiu       $a2, $zero, -0x3FFF
    ctx->r6 = ADD32(0, -0X3FFF);
    // 0x8001E904: bne         $s5, $zero, L_8001E910
    if (ctx->r21 != 0) {
        // 0x8001E908: nop
    
            goto L_8001E910;
    }
    // 0x8001E908: nop

    // 0x8001E90C: break       7
    do_break(2147608844);
L_8001E910:
    // 0x8001E910: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001E914: bne         $s5, $at, L_8001E928
    if (ctx->r21 != ctx->r1) {
        // 0x8001E918: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001E928;
    }
    // 0x8001E918: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001E91C: bne         $t7, $at, L_8001E928
    if (ctx->r15 != ctx->r1) {
        // 0x8001E920: nop
    
            goto L_8001E928;
    }
    // 0x8001E920: nop

    // 0x8001E924: break       6
    do_break(2147608868);
L_8001E928:
    // 0x8001E928: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001E92C: jal         0x8004C580
    // 0x8001E930: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_51;
    // 0x8001E930: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_51:
    // 0x8001E934: sw          $v0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r2;
L_8001E938:
    // 0x8001E938: jal         0x8001D15C
    // 0x8001E93C: nop

    func_8001D15C(rdram, ctx);
        goto after_52;
    // 0x8001E93C: nop

    after_52:
    // 0x8001E940: jal         0x8001D864
    // 0x8001E944: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_8001D864(rdram, ctx);
        goto after_53;
    // 0x8001E944: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_53:
    // 0x8001E948: beq         $s0, $zero, L_8001E9D0
    if (ctx->r16 == 0) {
        // 0x8001E94C: addiu       $t6, $zero, 0xFF
        ctx->r14 = ADD32(0, 0XFF);
            goto L_8001E9D0;
    }
    // 0x8001E94C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8001E950: lh          $t6, 0x6E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X6E);
    // 0x8001E954: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x8001E958: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8001E95C: bne         $t6, $zero, L_8001E97C
    if (ctx->r14 != 0) {
        // 0x8001E960: lh          $t9, 0x6E($sp)
        ctx->r25 = MEM_H(ctx->r29, 0X6E);
            goto L_8001E97C;
    }
    // 0x8001E960: lh          $t9, 0x6E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X6E);
    // 0x8001E964: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x8001E968: sh          $t8, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r24;
    // 0x8001E96C: jal         0x80044480
    // 0x8001E970: sh          $t7, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = ctx->r15;
    func_80044480(rdram, ctx);
        goto after_54;
    // 0x8001E970: sh          $t7, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = ctx->r15;
    after_54:
    // 0x8001E974: b           L_8001E9A8
    // 0x8001E978: lh          $t7, 0x6C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X6C);
        goto L_8001E9A8;
    // 0x8001E978: lh          $t7, 0x6C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X6C);
L_8001E97C:
    // 0x8001E97C: lh          $t7, 0x6C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X6C);
    // 0x8001E980: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x8001E984: sh          $t6, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r14;
    // 0x8001E988: beq         $t7, $zero, L_8001E9A4
    if (ctx->r15 == 0) {
        // 0x8001E98C: addiu       $t8, $t7, -0x4
        ctx->r24 = ADD32(ctx->r15, -0X4);
            goto L_8001E9A4;
    }
    // 0x8001E98C: addiu       $t8, $t7, -0x4
    ctx->r24 = ADD32(ctx->r15, -0X4);
    // 0x8001E990: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8001E994: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8001E998: bgez        $t6, L_8001E9A4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8001E99C: sh          $t8, 0x6C($sp)
        MEM_H(0X6C, ctx->r29) = ctx->r24;
            goto L_8001E9A4;
    }
    // 0x8001E99C: sh          $t8, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = ctx->r24;
    // 0x8001E9A0: sh          $zero, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = 0;
L_8001E9A4:
    // 0x8001E9A4: lh          $t7, 0x6C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X6C);
L_8001E9A8:
    // 0x8001E9A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001E9AC: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x8001E9B0: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x8001E9B4: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8001E9B8: addiu       $a3, $zero, 0x24
    ctx->r7 = ADD32(0, 0X24);
    // 0x8001E9BC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001E9C0: jal         0x8004C580
    // 0x8001E9C4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_55;
    // 0x8001E9C4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_55:
    // 0x8001E9C8: b           L_8001E9D8
    // 0x8001E9CC: nop

        goto L_8001E9D8;
    // 0x8001E9CC: nop

L_8001E9D0:
    // 0x8001E9D0: sh          $zero, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = 0;
    // 0x8001E9D4: sh          $t6, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = ctx->r14;
L_8001E9D8:
    // 0x8001E9D8: jal         0x8000798C
    // 0x8001E9DC: nop

    func_8000798C(rdram, ctx);
        goto after_56;
    // 0x8001E9DC: nop

    after_56:
    // 0x8001E9E0: b           L_8001DF08
    // 0x8001E9E4: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
        goto L_8001DF08;
    // 0x8001E9E4: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8001E9E8: nop

    // 0x8001E9EC: nop

    // 0x8001E9F0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8001E9F4: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8001E9F8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8001E9FC: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8001EA00: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8001EA04: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8001EA08: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8001EA0C: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8001EA10: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8001EA14: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8001EA18: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8001EA1C: jr          $ra
    // 0x8001EA20: addiu       $sp, $sp, 0x138
    ctx->r29 = ADD32(ctx->r29, 0X138);
    TRACE_RETURN()
    return;
    // 0x8001EA20: addiu       $sp, $sp, 0x138
    ctx->r29 = ADD32(ctx->r29, 0X138);
    // 0x8001EA24: nop

    // 0x8001EA28: nop

    // 0x8001EA2C: nop

    // 0x8001EA30: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001EA34: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001EA38: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001EA3C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001EA40: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8001EA44: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001EA48: addiu       $s0, $zero, -0x2
    ctx->r16 = ADD32(0, -0X2);
    // 0x8001EA4C: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x8001EA50: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_8001EA54:
    // 0x8001EA54: bne         $s2, $v0, L_8001EA70
    if (ctx->r18 != ctx->r2) {
        // 0x8001EA58: nop
    
            goto L_8001EA70;
    }
    // 0x8001EA58: nop

    // 0x8001EA5C: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_8001EA60:
    // 0x8001EA60: jal         0x8000798C
    // 0x8001EA64: nop

    func_8000798C(rdram, ctx);
        goto after_57;
    // 0x8001EA64: nop

    after_57:
    // 0x8001EA68: b           L_8001EA60
    // 0x8001EA6C: nop

        goto L_8001EA60;
    // 0x8001EA6C: nop

L_8001EA70:
    // 0x8001EA70: bne         $s0, $v0, L_8001EA94
    if (ctx->r16 != ctx->r2) {
        // 0x8001EA74: nop
    
            goto L_8001EA94;
    }
    // 0x8001EA74: nop

    // 0x8001EA78: bne         $s0, $v0, L_8001EA94
    if (ctx->r16 != ctx->r2) {
        // 0x8001EA7C: nop
    
            goto L_8001EA94;
    }
    // 0x8001EA7C: nop

L_8001EA80:
    // 0x8001EA80: jal         0x8000798C
    // 0x8001EA84: nop

    func_8000798C(rdram, ctx);
        goto after_58;
    // 0x8001EA84: nop

    after_58:
    // 0x8001EA88: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8001EA8C: beq         $s0, $t6, L_8001EA80
    if (ctx->r16 == ctx->r14) {
        // 0x8001EA90: nop
    
            goto L_8001EA80;
    }
    // 0x8001EA90: nop

L_8001EA94:
    // 0x8001EA94: jal         0x8000798C
    // 0x8001EA98: nop

    func_8000798C(rdram, ctx);
        goto after_59;
    // 0x8001EA98: nop

    after_59:
    // 0x8001EA9C: b           L_8001EA54
    // 0x8001EAA0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
        goto L_8001EA54;
    // 0x8001EAA0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8001EAA4: nop

    // 0x8001EAA8: nop

    // 0x8001EAAC: nop

    // 0x8001EAB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001EAB4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001EAB8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001EABC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001EAC0: jr          $ra
    // 0x8001EAC4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    TRACE_RETURN()
    return;
    // 0x8001EAC4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8001EAC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8001EAC8: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x8001EACC: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8001EAD0: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8001EAD4: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8001EAD8: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8001EADC: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8001EAE0: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8001EAE4: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8001EAE8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8001EAEC: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8001EAF0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8001EAF4: lh          $t6, 0x2C($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2C);
    // 0x8001EAF8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001EAFC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001EB00: blez        $t6, L_8001ED30
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8001EB04: or          $s6, $zero, $zero
        ctx->r22 = 0 | 0;
            goto L_8001ED30;
    }
    // 0x8001EB04: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x8001EB08: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001EB0C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8001EB10: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8001EB14: addiu       $s5, $sp, 0x64
    ctx->r21 = ADD32(ctx->r29, 0X64);
    // 0x8001EB18: addiu       $s4, $sp, 0xA4
    ctx->r20 = ADD32(ctx->r29, 0XA4);
    // 0x8001EB1C: addiu       $s3, $sp, 0xB0
    ctx->r19 = ADD32(ctx->r29, 0XB0);
    // 0x8001EB20: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x8001EB24: lw          $t7, 0x28($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X28);
L_8001EB28:
    // 0x8001EB28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001EB2C: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8001EB30: addu        $t8, $t7, $s6
    ctx->r24 = ADD32(ctx->r15, ctx->r22);
    // 0x8001EB34: lh          $a2, 0x0($t8)
    ctx->r6 = MEM_H(ctx->r24, 0X0);
L_8001EB38:
    // 0x8001EB38: lw          $t9, 0x28($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X28);
    // 0x8001EB3C: sll         $t0, $s1, 2
    ctx->r8 = S32(ctx->r17 << 2);
    // 0x8001EB40: subu        $t0, $t0, $s1
    ctx->r8 = SUB32(ctx->r8, ctx->r17);
    // 0x8001EB44: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8001EB48: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8001EB4C: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x8001EB50: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8001EB54: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001EB58: slti        $at, $v0, 0xC
    ctx->r1 = SIGNED(ctx->r2) < 0XC ? 1 : 0;
    // 0x8001EB5C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8001EB60: bne         $at, $zero, L_8001EB38
    if (ctx->r1 != 0) {
        // 0x8001EB64: swc1        $f4, 0x8($t2)
        MEM_W(0X8, ctx->r10) = ctx->f4.u32l;
            goto L_8001EB38;
    }
    // 0x8001EB64: swc1        $f4, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f4.u32l;
    // 0x8001EB68: andi        $t3, $a2, 0x20
    ctx->r11 = ctx->r6 & 0X20;
    // 0x8001EB6C: beq         $t3, $zero, L_8001EBE4
    if (ctx->r11 == 0) {
        // 0x8001EB70: andi        $t5, $a2, 0x40
        ctx->r13 = ctx->r6 & 0X40;
            goto L_8001EBE4;
    }
    // 0x8001EB70: andi        $t5, $a2, 0x40
    ctx->r13 = ctx->r6 & 0X40;
    // 0x8001EB74: sll         $a0, $a2, 16
    ctx->r4 = S32(ctx->r6 << 16);
    // 0x8001EB78: sra         $t4, $a0, 16
    ctx->r12 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001EB7C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8001EB80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8001EB84:
    // 0x8001EB84: andi        $t5, $a0, 0x4
    ctx->r13 = ctx->r4 & 0X4;
    // 0x8001EB88: beq         $t5, $zero, L_8001EBCC
    if (ctx->r13 == 0) {
        // 0x8001EB8C: or          $t2, $a0, $zero
        ctx->r10 = ctx->r4 | 0;
            goto L_8001EBCC;
    }
    // 0x8001EB8C: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x8001EB90: lw          $t6, 0x28($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X28);
    // 0x8001EB94: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x8001EB98: subu        $t7, $t7, $s1
    ctx->r15 = SUB32(ctx->r15, ctx->r17);
    // 0x8001EB9C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8001EBA0: sll         $t9, $a1, 1
    ctx->r25 = S32(ctx->r5 << 1);
    // 0x8001EBA4: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8001EBA8: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x8001EBAC: lh          $t1, 0x2($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X2);
    // 0x8001EBB0: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8001EBB4: addu        $v1, $v0, $t8
    ctx->r3 = ADD32(ctx->r2, ctx->r24);
    // 0x8001EBB8: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8001EBBC: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8001EBC0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001EBC4: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8001EBC8: swc1        $f16, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f16.u32l;
L_8001EBCC:
    // 0x8001EBCC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001EBD0: sll         $t3, $t2, 17
    ctx->r11 = S32(ctx->r10 << 17);
    // 0x8001EBD4: bne         $a1, $s2, L_8001EB84
    if (ctx->r5 != ctx->r18) {
        // 0x8001EBD8: sra         $a0, $t3, 16
        ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
            goto L_8001EB84;
    }
    // 0x8001EBD8: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8001EBDC: b           L_8001ED1C
    // 0x8001EBE0: lh          $t3, 0x2C($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X2C);
        goto L_8001ED1C;
    // 0x8001EBE0: lh          $t3, 0x2C($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X2C);
L_8001EBE4:
    // 0x8001EBE4: beql        $t5, $zero, L_8001ED1C
    if (ctx->r13 == 0) {
        // 0x8001EBE8: lh          $t3, 0x2C($s0)
        ctx->r11 = MEM_H(ctx->r16, 0X2C);
            goto L_8001ED1C;
    }
    goto skip_0;
    // 0x8001EBE8: lh          $t3, 0x2C($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X2C);
    skip_0:
    // 0x8001EBEC: lw          $t6, 0x28($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X28);
    // 0x8001EBF0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8001EBF4: addu        $v0, $t6, $s6
    ctx->r2 = ADD32(ctx->r14, ctx->r22);
    // 0x8001EBF8: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x8001EBFC: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x8001EC00: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x8001EC04: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8001EC08: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8001EC0C: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8001EC10: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001EC14: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001EC18: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8001EC1C: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001EC20: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8001EC24: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8001EC28: jal         0x80001A6C
    // 0x8001EC2C: nop

    func_80001A6C(rdram, ctx);
        goto after_0;
    // 0x8001EC2C: nop

    after_0:
    // 0x8001EC30: lw          $a1, 0x14($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14);
    // 0x8001EC34: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8001EC38: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8001EC3C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8001EC40: jal         0x80049840
    // 0x8001EC44: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_80049840(rdram, ctx);
        goto after_1;
    // 0x8001EC44: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_1:
    // 0x8001EC48: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8001EC4C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8001EC50: jal         0x80000BD8
    // 0x8001EC54: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_80000BD8(rdram, ctx);
        goto after_2;
    // 0x8001EC54: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_2:
    // 0x8001EC58: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x8001EC5C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8001EC60: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8001EC64: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x8001EC68: jal         0x80049840
    // 0x8001EC6C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_80049840(rdram, ctx);
        goto after_3;
    // 0x8001EC6C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_3:
    // 0x8001EC70: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8001EC74: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8001EC78: jal         0x80000BD8
    // 0x8001EC7C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_80000BD8(rdram, ctx);
        goto after_4;
    // 0x8001EC7C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_4:
    // 0x8001EC80: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    // 0x8001EC84: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8001EC88: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8001EC8C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8001EC90: jal         0x80049840
    // 0x8001EC94: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_80049840(rdram, ctx);
        goto after_5;
    // 0x8001EC94: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_5:
    // 0x8001EC98: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8001EC9C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8001ECA0: jal         0x80000BD8
    // 0x8001ECA4: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_80000BD8(rdram, ctx);
        goto after_6;
    // 0x8001ECA4: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_6:
    // 0x8001ECA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001ECAC: addiu       $a0, $sp, 0xA4
    ctx->r4 = ADD32(ctx->r29, 0XA4);
    // 0x8001ECB0: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x8001ECB4: subu        $t1, $t1, $s1
    ctx->r9 = SUB32(ctx->r9, ctx->r17);
    // 0x8001ECB8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8001ECBC: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8001ECC0: beq         $a0, $s3, L_8001ECFC
    if (ctx->r4 == ctx->r19) {
        // 0x8001ECC4: lw          $t0, 0x28($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X28);
            goto L_8001ECFC;
    }
    // 0x8001ECC4: lw          $t0, 0x28($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X28);
L_8001ECC8:
    // 0x8001ECC8: lwc1        $f18, 0x2C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x8001ECCC: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8001ECD0: addu        $v1, $t2, $v0
    ctx->r3 = ADD32(ctx->r10, ctx->r2);
    // 0x8001ECD4: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8001ECD8: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x8001ECDC: subu        $t1, $t1, $s1
    ctx->r9 = SUB32(ctx->r9, ctx->r17);
    // 0x8001ECE0: add.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8001ECE4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8001ECE8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001ECEC: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8001ECF0: swc1        $f18, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f18.u32l;
    // 0x8001ECF4: bne         $a0, $s3, L_8001ECC8
    if (ctx->r4 != ctx->r19) {
        // 0x8001ECF8: lw          $t0, 0x28($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X28);
            goto L_8001ECC8;
    }
    // 0x8001ECF8: lw          $t0, 0x28($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X28);
L_8001ECFC:
    // 0x8001ECFC: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8001ED00: addu        $v1, $t2, $v0
    ctx->r3 = ADD32(ctx->r10, ctx->r2);
    // 0x8001ED04: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8001ED08: lwc1        $f18, 0x2C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x8001ED0C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001ED10: add.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8001ED14: swc1        $f18, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f18.u32l;
    // 0x8001ED18: lh          $t3, 0x2C($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X2C);
L_8001ED1C:
    // 0x8001ED1C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8001ED20: addiu       $s6, $s6, 0x18
    ctx->r22 = ADD32(ctx->r22, 0X18);
    // 0x8001ED24: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8001ED28: bnel        $at, $zero, L_8001EB28
    if (ctx->r1 != 0) {
        // 0x8001ED2C: lw          $t7, 0x28($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X28);
            goto L_8001EB28;
    }
    goto skip_1;
    // 0x8001ED2C: lw          $t7, 0x28($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X28);
    skip_1:
L_8001ED30:
    // 0x8001ED30: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8001ED34: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8001ED38: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8001ED3C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8001ED40: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8001ED44: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8001ED48: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8001ED4C: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8001ED50: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8001ED54: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8001ED58: jr          $ra
    // 0x8001ED5C: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    TRACE_RETURN()
    return;
    // 0x8001ED5C: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
;}
RECOMP_FUNC void func_8001ED60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8001ED60: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x8001ED64: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8001ED68: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8001ED6C: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8001ED70: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8001ED74: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8001ED78: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8001ED7C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8001ED80: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8001ED84: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8001ED88: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8001ED8C: lh          $t6, 0x2C($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2C);
    // 0x8001ED90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001ED94: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001ED98: blez        $t6, L_8001EFC8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8001ED9C: or          $s6, $zero, $zero
        ctx->r22 = 0 | 0;
            goto L_8001EFC8;
    }
    // 0x8001ED9C: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x8001EDA0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001EDA4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8001EDA8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8001EDAC: addiu       $s5, $sp, 0x64
    ctx->r21 = ADD32(ctx->r29, 0X64);
    // 0x8001EDB0: addiu       $s4, $sp, 0xA4
    ctx->r20 = ADD32(ctx->r29, 0XA4);
    // 0x8001EDB4: addiu       $s3, $sp, 0xB0
    ctx->r19 = ADD32(ctx->r29, 0XB0);
    // 0x8001EDB8: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x8001EDBC: lw          $t7, 0x28($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X28);
L_8001EDC0:
    // 0x8001EDC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001EDC4: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8001EDC8: addu        $t8, $t7, $s6
    ctx->r24 = ADD32(ctx->r15, ctx->r22);
    // 0x8001EDCC: lh          $a2, 0x0($t8)
    ctx->r6 = MEM_H(ctx->r24, 0X0);
L_8001EDD0:
    // 0x8001EDD0: lw          $t9, 0x28($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X28);
    // 0x8001EDD4: sll         $t0, $s1, 2
    ctx->r8 = S32(ctx->r17 << 2);
    // 0x8001EDD8: subu        $t0, $t0, $s1
    ctx->r8 = SUB32(ctx->r8, ctx->r17);
    // 0x8001EDDC: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8001EDE0: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8001EDE4: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x8001EDE8: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8001EDEC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001EDF0: slti        $at, $v0, 0xC
    ctx->r1 = SIGNED(ctx->r2) < 0XC ? 1 : 0;
    // 0x8001EDF4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8001EDF8: bne         $at, $zero, L_8001EDD0
    if (ctx->r1 != 0) {
        // 0x8001EDFC: swc1        $f4, 0x8($t2)
        MEM_W(0X8, ctx->r10) = ctx->f4.u32l;
            goto L_8001EDD0;
    }
    // 0x8001EDFC: swc1        $f4, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f4.u32l;
    // 0x8001EE00: andi        $t3, $a2, 0x20
    ctx->r11 = ctx->r6 & 0X20;
    // 0x8001EE04: beq         $t3, $zero, L_8001EE7C
    if (ctx->r11 == 0) {
        // 0x8001EE08: andi        $t5, $a2, 0x40
        ctx->r13 = ctx->r6 & 0X40;
            goto L_8001EE7C;
    }
    // 0x8001EE08: andi        $t5, $a2, 0x40
    ctx->r13 = ctx->r6 & 0X40;
    // 0x8001EE0C: sll         $a0, $a2, 16
    ctx->r4 = S32(ctx->r6 << 16);
    // 0x8001EE10: sra         $t4, $a0, 16
    ctx->r12 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001EE14: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8001EE18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8001EE1C:
    // 0x8001EE1C: andi        $t5, $a0, 0x4
    ctx->r13 = ctx->r4 & 0X4;
    // 0x8001EE20: beq         $t5, $zero, L_8001EE64
    if (ctx->r13 == 0) {
        // 0x8001EE24: or          $t2, $a0, $zero
        ctx->r10 = ctx->r4 | 0;
            goto L_8001EE64;
    }
    // 0x8001EE24: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x8001EE28: lw          $t6, 0x28($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X28);
    // 0x8001EE2C: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x8001EE30: subu        $t7, $t7, $s1
    ctx->r15 = SUB32(ctx->r15, ctx->r17);
    // 0x8001EE34: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8001EE38: sll         $t9, $a1, 1
    ctx->r25 = S32(ctx->r5 << 1);
    // 0x8001EE3C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8001EE40: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x8001EE44: lh          $t1, 0x2($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X2);
    // 0x8001EE48: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8001EE4C: addu        $v1, $v0, $t8
    ctx->r3 = ADD32(ctx->r2, ctx->r24);
    // 0x8001EE50: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8001EE54: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8001EE58: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001EE5C: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8001EE60: swc1        $f16, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f16.u32l;
L_8001EE64:
    // 0x8001EE64: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001EE68: sll         $t3, $t2, 17
    ctx->r11 = S32(ctx->r10 << 17);
    // 0x8001EE6C: bne         $a1, $s2, L_8001EE1C
    if (ctx->r5 != ctx->r18) {
        // 0x8001EE70: sra         $a0, $t3, 16
        ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
            goto L_8001EE1C;
    }
    // 0x8001EE70: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8001EE74: b           L_8001EFB4
    // 0x8001EE78: lh          $t3, 0x2C($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X2C);
        goto L_8001EFB4;
    // 0x8001EE78: lh          $t3, 0x2C($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X2C);
L_8001EE7C:
    // 0x8001EE7C: beql        $t5, $zero, L_8001EFB4
    if (ctx->r13 == 0) {
        // 0x8001EE80: lh          $t3, 0x2C($s0)
        ctx->r11 = MEM_H(ctx->r16, 0X2C);
            goto L_8001EFB4;
    }
    goto skip_0;
    // 0x8001EE80: lh          $t3, 0x2C($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X2C);
    skip_0:
    // 0x8001EE84: lw          $t6, 0x28($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X28);
    // 0x8001EE88: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8001EE8C: addu        $v0, $t6, $s6
    ctx->r2 = ADD32(ctx->r14, ctx->r22);
    // 0x8001EE90: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x8001EE94: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x8001EE98: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x8001EE9C: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8001EEA0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8001EEA4: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8001EEA8: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001EEAC: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001EEB0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8001EEB4: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001EEB8: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8001EEBC: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8001EEC0: jal         0x80001A6C
    // 0x8001EEC4: nop

    func_80001A6C(rdram, ctx);
        goto after_0;
    // 0x8001EEC4: nop

    after_0:
    // 0x8001EEC8: lw          $a1, 0x14($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14);
    // 0x8001EECC: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8001EED0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8001EED4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8001EED8: jal         0x80049840
    // 0x8001EEDC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_80049840(rdram, ctx);
        goto after_1;
    // 0x8001EEDC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_1:
    // 0x8001EEE0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8001EEE4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8001EEE8: jal         0x80000BD8
    // 0x8001EEEC: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_80000BD8(rdram, ctx);
        goto after_2;
    // 0x8001EEEC: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_2:
    // 0x8001EEF0: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x8001EEF4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8001EEF8: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8001EEFC: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x8001EF00: jal         0x80049840
    // 0x8001EF04: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_80049840(rdram, ctx);
        goto after_3;
    // 0x8001EF04: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_3:
    // 0x8001EF08: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8001EF0C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8001EF10: jal         0x80000BD8
    // 0x8001EF14: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_80000BD8(rdram, ctx);
        goto after_4;
    // 0x8001EF14: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_4:
    // 0x8001EF18: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    // 0x8001EF1C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8001EF20: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8001EF24: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8001EF28: jal         0x80049840
    // 0x8001EF2C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_80049840(rdram, ctx);
        goto after_5;
    // 0x8001EF2C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_5:
    // 0x8001EF30: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8001EF34: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8001EF38: jal         0x80000BD8
    // 0x8001EF3C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_80000BD8(rdram, ctx);
        goto after_6;
    // 0x8001EF3C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_6:
    // 0x8001EF40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001EF44: addiu       $a0, $sp, 0xA4
    ctx->r4 = ADD32(ctx->r29, 0XA4);
    // 0x8001EF48: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x8001EF4C: subu        $t1, $t1, $s1
    ctx->r9 = SUB32(ctx->r9, ctx->r17);
    // 0x8001EF50: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8001EF54: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8001EF58: beq         $a0, $s3, L_8001EF94
    if (ctx->r4 == ctx->r19) {
        // 0x8001EF5C: lw          $t0, 0x28($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X28);
            goto L_8001EF94;
    }
    // 0x8001EF5C: lw          $t0, 0x28($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X28);
L_8001EF60:
    // 0x8001EF60: lwc1        $f18, 0x2C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x8001EF64: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8001EF68: addu        $v1, $t2, $v0
    ctx->r3 = ADD32(ctx->r10, ctx->r2);
    // 0x8001EF6C: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8001EF70: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x8001EF74: subu        $t1, $t1, $s1
    ctx->r9 = SUB32(ctx->r9, ctx->r17);
    // 0x8001EF78: add.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8001EF7C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8001EF80: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001EF84: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8001EF88: swc1        $f18, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f18.u32l;
    // 0x8001EF8C: bne         $a0, $s3, L_8001EF60
    if (ctx->r4 != ctx->r19) {
        // 0x8001EF90: lw          $t0, 0x28($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X28);
            goto L_8001EF60;
    }
    // 0x8001EF90: lw          $t0, 0x28($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X28);
L_8001EF94:
    // 0x8001EF94: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8001EF98: addu        $v1, $t2, $v0
    ctx->r3 = ADD32(ctx->r10, ctx->r2);
    // 0x8001EF9C: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8001EFA0: lwc1        $f18, 0x2C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x8001EFA4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001EFA8: add.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8001EFAC: swc1        $f18, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f18.u32l;
    // 0x8001EFB0: lh          $t3, 0x2C($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X2C);
L_8001EFB4:
    // 0x8001EFB4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8001EFB8: addiu       $s6, $s6, 0x18
    ctx->r22 = ADD32(ctx->r22, 0X18);
    // 0x8001EFBC: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8001EFC0: bnel        $at, $zero, L_8001EDC0
    if (ctx->r1 != 0) {
        // 0x8001EFC4: lw          $t7, 0x28($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X28);
            goto L_8001EDC0;
    }
    goto skip_1;
    // 0x8001EFC4: lw          $t7, 0x28($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X28);
    skip_1:
L_8001EFC8:
    // 0x8001EFC8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8001EFCC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8001EFD0: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8001EFD4: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8001EFD8: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8001EFDC: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8001EFE0: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8001EFE4: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8001EFE8: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8001EFEC: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8001EFF0: jr          $ra
    // 0x8001EFF4: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    TRACE_RETURN()
    return;
    // 0x8001EFF4: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
;}
RECOMP_FUNC void func_8001EFF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8001EFF8: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x8001EFFC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8001F000: lw          $t6, -0x6810($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6810);
    // 0x8001F004: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8001F008: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8001F00C: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8001F010: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8001F014: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8001F018: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8001F01C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8001F020: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8001F024: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8001F028: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8001F02C: lw          $s1, 0x0($t6)
    ctx->r17 = MEM_W(ctx->r14, 0X0);
    // 0x8001F030: addiu       $s3, $sp, 0xAC
    ctx->r19 = ADD32(ctx->r29, 0XAC);
    // 0x8001F034: addiu       $s4, $sp, 0xA0
    ctx->r20 = ADD32(ctx->r29, 0XA0);
    // 0x8001F038: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8001F03C: addiu       $s5, $sp, 0x60
    ctx->r21 = ADD32(ctx->r29, 0X60);
    // 0x8001F040: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001F044: beql        $v1, $zero, L_8001F2A0
    if (ctx->r3 == 0) {
        // 0x8001F048: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_8001F2A0;
    }
    goto skip_0;
    // 0x8001F048: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_0:
    // 0x8001F04C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8001F050: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8001F054: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x8001F058: lh          $t7, 0x2E($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X2E);
L_8001F05C:
    // 0x8001F05C: blezl       $t7, L_8001F290
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8001F060: or          $s1, $v1, $zero
        ctx->r17 = ctx->r3 | 0;
            goto L_8001F290;
    }
    goto skip_1;
    // 0x8001F060: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    skip_1:
    // 0x8001F064: lh          $v0, 0x2C($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X2C);
    // 0x8001F068: beql        $v0, $zero, L_8001F290
    if (ctx->r2 == 0) {
        // 0x8001F06C: or          $s1, $v1, $zero
        ctx->r17 = ctx->r3 | 0;
            goto L_8001F290;
    }
    goto skip_2;
    // 0x8001F06C: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    skip_2:
    // 0x8001F070: blez        $v0, L_8001F28C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001F074: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8001F28C;
    }
    // 0x8001F074: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001F078: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x8001F07C: lw          $t8, 0x28($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X28);
L_8001F080:
    // 0x8001F080: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001F084: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x8001F088: addu        $t9, $t8, $s6
    ctx->r25 = ADD32(ctx->r24, ctx->r22);
    // 0x8001F08C: lh          $a2, 0x0($t9)
    ctx->r6 = MEM_H(ctx->r25, 0X0);
L_8001F090:
    // 0x8001F090: lw          $t0, 0x28($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X28);
    // 0x8001F094: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    // 0x8001F098: subu        $t1, $t1, $s0
    ctx->r9 = SUB32(ctx->r9, ctx->r16);
    // 0x8001F09C: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8001F0A0: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8001F0A4: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x8001F0A8: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8001F0AC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001F0B0: slti        $at, $v0, 0xC
    ctx->r1 = SIGNED(ctx->r2) < 0XC ? 1 : 0;
    // 0x8001F0B4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8001F0B8: bne         $at, $zero, L_8001F090
    if (ctx->r1 != 0) {
        // 0x8001F0BC: swc1        $f4, 0x8($t3)
        MEM_W(0X8, ctx->r11) = ctx->f4.u32l;
            goto L_8001F090;
    }
    // 0x8001F0BC: swc1        $f4, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f4.u32l;
    // 0x8001F0C0: andi        $t4, $a2, 0x20
    ctx->r12 = ctx->r6 & 0X20;
    // 0x8001F0C4: beq         $t4, $zero, L_8001F13C
    if (ctx->r12 == 0) {
        // 0x8001F0C8: andi        $t6, $a2, 0x40
        ctx->r14 = ctx->r6 & 0X40;
            goto L_8001F13C;
    }
    // 0x8001F0C8: andi        $t6, $a2, 0x40
    ctx->r14 = ctx->r6 & 0X40;
    // 0x8001F0CC: sll         $a0, $a2, 16
    ctx->r4 = S32(ctx->r6 << 16);
    // 0x8001F0D0: sra         $t5, $a0, 16
    ctx->r13 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001F0D4: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x8001F0D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8001F0DC:
    // 0x8001F0DC: andi        $t6, $a0, 0x4
    ctx->r14 = ctx->r4 & 0X4;
    // 0x8001F0E0: beq         $t6, $zero, L_8001F124
    if (ctx->r14 == 0) {
        // 0x8001F0E4: or          $t3, $a0, $zero
        ctx->r11 = ctx->r4 | 0;
            goto L_8001F124;
    }
    // 0x8001F0E4: or          $t3, $a0, $zero
    ctx->r11 = ctx->r4 | 0;
    // 0x8001F0E8: lw          $t7, 0x28($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X28);
    // 0x8001F0EC: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x8001F0F0: subu        $t8, $t8, $s0
    ctx->r24 = SUB32(ctx->r24, ctx->r16);
    // 0x8001F0F4: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8001F0F8: sll         $t0, $a1, 1
    ctx->r8 = S32(ctx->r5 << 1);
    // 0x8001F0FC: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8001F100: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x8001F104: lh          $t2, 0x2($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X2);
    // 0x8001F108: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8001F10C: addu        $v1, $v0, $t9
    ctx->r3 = ADD32(ctx->r2, ctx->r25);
    // 0x8001F110: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8001F114: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8001F118: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001F11C: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8001F120: swc1        $f16, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f16.u32l;
L_8001F124:
    // 0x8001F124: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001F128: sll         $t4, $t3, 17
    ctx->r12 = S32(ctx->r11 << 17);
    // 0x8001F12C: bne         $a1, $s2, L_8001F0DC
    if (ctx->r5 != ctx->r18) {
        // 0x8001F130: sra         $a0, $t4, 16
        ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
            goto L_8001F0DC;
    }
    // 0x8001F130: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8001F134: b           L_8001F274
    // 0x8001F138: lh          $t4, 0x2C($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X2C);
        goto L_8001F274;
    // 0x8001F138: lh          $t4, 0x2C($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X2C);
L_8001F13C:
    // 0x8001F13C: beql        $t6, $zero, L_8001F274
    if (ctx->r14 == 0) {
        // 0x8001F140: lh          $t4, 0x2C($s1)
        ctx->r12 = MEM_H(ctx->r17, 0X2C);
            goto L_8001F274;
    }
    goto skip_3;
    // 0x8001F140: lh          $t4, 0x2C($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X2C);
    skip_3:
    // 0x8001F144: lw          $t7, 0x28($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X28);
    // 0x8001F148: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8001F14C: addu        $v0, $t7, $s6
    ctx->r2 = ADD32(ctx->r15, ctx->r22);
    // 0x8001F150: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x8001F154: lh          $t9, 0x4($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X4);
    // 0x8001F158: lh          $t0, 0x6($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X6);
    // 0x8001F15C: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8001F160: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8001F164: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8001F168: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001F16C: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001F170: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8001F174: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001F178: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8001F17C: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8001F180: jal         0x80001A6C
    // 0x8001F184: nop

    func_80001A6C(rdram, ctx);
        goto after_0;
    // 0x8001F184: nop

    after_0:
    // 0x8001F188: lw          $a1, 0x14($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X14);
    // 0x8001F18C: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8001F190: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8001F194: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8001F198: jal         0x80049840
    // 0x8001F19C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_80049840(rdram, ctx);
        goto after_1;
    // 0x8001F19C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_1:
    // 0x8001F1A0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8001F1A4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8001F1A8: jal         0x80000BD8
    // 0x8001F1AC: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_80000BD8(rdram, ctx);
        goto after_2;
    // 0x8001F1AC: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_2:
    // 0x8001F1B0: lw          $a1, 0x1C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1C);
    // 0x8001F1B4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8001F1B8: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8001F1BC: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x8001F1C0: jal         0x80049840
    // 0x8001F1C4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_80049840(rdram, ctx);
        goto after_3;
    // 0x8001F1C4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_3:
    // 0x8001F1C8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8001F1CC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8001F1D0: jal         0x80000BD8
    // 0x8001F1D4: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_80000BD8(rdram, ctx);
        goto after_4;
    // 0x8001F1D4: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_4:
    // 0x8001F1D8: lw          $a1, 0x18($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X18);
    // 0x8001F1DC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8001F1E0: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8001F1E4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8001F1E8: jal         0x80049840
    // 0x8001F1EC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_80049840(rdram, ctx);
        goto after_5;
    // 0x8001F1EC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_5:
    // 0x8001F1F0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8001F1F4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8001F1F8: jal         0x80000BD8
    // 0x8001F1FC: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_80000BD8(rdram, ctx);
        goto after_6;
    // 0x8001F1FC: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_6:
    // 0x8001F200: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001F204: addiu       $a0, $sp, 0xA0
    ctx->r4 = ADD32(ctx->r29, 0XA0);
    // 0x8001F208: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x8001F20C: subu        $t2, $t2, $s0
    ctx->r10 = SUB32(ctx->r10, ctx->r16);
    // 0x8001F210: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8001F214: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8001F218: beq         $a0, $s3, L_8001F254
    if (ctx->r4 == ctx->r19) {
        // 0x8001F21C: lw          $t1, 0x28($s1)
        ctx->r9 = MEM_W(ctx->r17, 0X28);
            goto L_8001F254;
    }
    // 0x8001F21C: lw          $t1, 0x28($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X28);
L_8001F220:
    // 0x8001F220: lwc1        $f18, 0x2C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x8001F224: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8001F228: addu        $v1, $t3, $v0
    ctx->r3 = ADD32(ctx->r11, ctx->r2);
    // 0x8001F22C: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8001F230: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x8001F234: subu        $t2, $t2, $s0
    ctx->r10 = SUB32(ctx->r10, ctx->r16);
    // 0x8001F238: add.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8001F23C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8001F240: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001F244: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8001F248: swc1        $f18, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f18.u32l;
    // 0x8001F24C: bne         $a0, $s3, L_8001F220
    if (ctx->r4 != ctx->r19) {
        // 0x8001F250: lw          $t1, 0x28($s1)
        ctx->r9 = MEM_W(ctx->r17, 0X28);
            goto L_8001F220;
    }
    // 0x8001F250: lw          $t1, 0x28($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X28);
L_8001F254:
    // 0x8001F254: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8001F258: addu        $v1, $t3, $v0
    ctx->r3 = ADD32(ctx->r11, ctx->r2);
    // 0x8001F25C: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8001F260: lwc1        $f18, 0x2C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x8001F264: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001F268: add.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8001F26C: swc1        $f18, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f18.u32l;
    // 0x8001F270: lh          $t4, 0x2C($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X2C);
L_8001F274:
    // 0x8001F274: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001F278: addiu       $s6, $s6, 0x18
    ctx->r22 = ADD32(ctx->r22, 0X18);
    // 0x8001F27C: slt         $at, $s0, $t4
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8001F280: bnel        $at, $zero, L_8001F080
    if (ctx->r1 != 0) {
        // 0x8001F284: lw          $t8, 0x28($s1)
        ctx->r24 = MEM_W(ctx->r17, 0X28);
            goto L_8001F080;
    }
    goto skip_4;
    // 0x8001F284: lw          $t8, 0x28($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X28);
    skip_4:
    // 0x8001F288: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
L_8001F28C:
    // 0x8001F28C: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
L_8001F290:
    // 0x8001F290: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8001F294: bnel        $v1, $zero, L_8001F05C
    if (ctx->r3 != 0) {
        // 0x8001F298: lh          $t7, 0x2E($s1)
        ctx->r15 = MEM_H(ctx->r17, 0X2E);
            goto L_8001F05C;
    }
    goto skip_5;
    // 0x8001F298: lh          $t7, 0x2E($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X2E);
    skip_5:
    // 0x8001F29C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_8001F2A0:
    // 0x8001F2A0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8001F2A4: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8001F2A8: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8001F2AC: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8001F2B0: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8001F2B4: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8001F2B8: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8001F2BC: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8001F2C0: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8001F2C4: jr          $ra
    // 0x8001F2C8: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    TRACE_RETURN()
    return;
    // 0x8001F2C8: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
;}
static void ground_collision(uint8_t* rdram, recomp_context* ctx, int sweep_cannon) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8001F2CC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8001F2D0: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8001F2D4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8001F2D8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001F2DC: sll         $s4, $a2, 16
    ctx->r20 = S32(ctx->r6 << 16);
    // 0x8001F2E0: sll         $s6, $a1, 16
    ctx->r22 = S32(ctx->r5 << 16);
    // 0x8001F2E4: sll         $fp, $a3, 16
    ctx->r30 = S32(ctx->r7 << 16);
    // 0x8001F2E8: sra         $t8, $fp, 16
    ctx->r24 = S32(SIGNED(ctx->r30) >> 16);
    // 0x8001F2EC: sra         $t6, $s6, 16
    ctx->r14 = S32(SIGNED(ctx->r22) >> 16);
    // 0x8001F2F0: sra         $t7, $s4, 16
    ctx->r15 = S32(SIGNED(ctx->r20) >> 16);
    // 0x8001F2F4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8001F2F8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8001F2FC: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8001F300: or          $s4, $t7, $zero
    ctx->r20 = ctx->r15 | 0;
    // 0x8001F304: or          $s6, $t6, $zero
    ctx->r22 = ctx->r14 | 0;
    // 0x8001F308: or          $fp, $t8, $zero
    ctx->r30 = ctx->r24 | 0;
    // 0x8001F30C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8001F310: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001F314: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001F318: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001F31C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001F320: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8001F324: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8001F328: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8001F32C: beq         $t8, $zero, L_8001F33C
    if (ctx->r24 == 0) {
        // 0x8001F330: or          $s7, $zero, $zero
        ctx->r23 = 0 | 0;
            goto L_8001F33C;
    }
    // 0x8001F330: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x8001F334: jal         0x8001EFF8
    // 0x8001F338: nop

    func_8001EFF8(rdram, ctx);
        goto after_0;
    // 0x8001F338: nop

    after_0:
L_8001F33C:
    // 0x8001F33C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8001F340: lw          $t9, -0x6810($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6810);
    // 0x8001F344: lw          $s1, 0x0($t9)
    ctx->r17 = MEM_W(ctx->r25, 0X0);
    // 0x8001F348: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8001F34C: beql        $v1, $zero, L_8001F464
    if (ctx->r3 == 0) {
        // 0x8001F350: or          $v0, $s7, $zero
        ctx->r2 = ctx->r23 | 0;
            goto L_8001F464;
    }
    goto skip_0;
    // 0x8001F350: or          $v0, $s7, $zero
    ctx->r2 = ctx->r23 | 0;
    skip_0:
    // 0x8001F354: lh          $t0, 0x2E($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X2E);
L_8001F358:
    // 0x8001F358: blezl       $t0, L_8001F454
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8001F35C: or          $s1, $v1, $zero
        ctx->r17 = ctx->r3 | 0;
            goto L_8001F454;
    }
    goto skip_1;
    // 0x8001F35C: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    skip_1:
    // 0x8001F360: lh          $t1, 0x96($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X96);
    // 0x8001F364: blezl       $t1, L_8001F454
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8001F368: or          $s1, $v1, $zero
        ctx->r17 = ctx->r3 | 0;
            goto L_8001F454;
    }
    goto skip_2;
    // 0x8001F368: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    skip_2:
    // 0x8001F36C: lh          $v0, 0x2C($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X2C);
    // 0x8001F370: beql        $v0, $zero, L_8001F454
    if (ctx->r2 == 0) {
        // 0x8001F374: or          $s1, $v1, $zero
        ctx->r17 = ctx->r3 | 0;
            goto L_8001F454;
    }
    goto skip_3;
    // 0x8001F374: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    skip_3:
    // 0x8001F378: beq         $fp, $zero, L_8001F390
    if (ctx->r30 == 0) {
        // 0x8001F37C: nop
    
            goto L_8001F390;
    }
    // 0x8001F37C: nop

    // 0x8001F380: lh          $t2, 0x98($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X98);
    // 0x8001F384: andi        $t3, $t2, 0x4
    ctx->r11 = ctx->r10 & 0X4;
    // 0x8001F388: bnel        $t3, $zero, L_8001F454
    if (ctx->r11 != 0) {
        // 0x8001F38C: or          $s1, $v1, $zero
        ctx->r17 = ctx->r3 | 0;
            goto L_8001F454;
    }
    goto skip_4;
    // 0x8001F38C: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    skip_4:
L_8001F390:
    // 0x8001F390: blez        $v0, L_8001F450
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001F394: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8001F450;
    }
    // 0x8001F394: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8001F398: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8001F39C: lw          $t4, 0x28($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X28);
L_8001F3A0:
    // 0x8001F3A0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8001F3A4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001F3A8: addu        $a1, $t4, $s2
    ctx->r5 = ADD32(ctx->r12, ctx->r18);
    // 0x8001F3AC: jal         0x80003668
    // 0x8001F3B0: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    if (sweep_cannon) chopper_cannon_ground_distance(rdram, ctx);
    else func_80003668(rdram, ctx);
        goto after_1;
    // 0x8001F3B0: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_1:
    // 0x8001F3B4: beql        $s4, $zero, L_8001F3E0
    if (ctx->r20 == 0) {
        // 0x8001F3B8: trunc.w.s   $f6, $f0
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
            goto L_8001F3E0;
    }
    goto skip_5;
    // 0x8001F3B8: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    skip_5:
    // 0x8001F3BC: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001F3C0: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x8001F3C4: nop

    // 0x8001F3C8: slt         $at, $t6, $s4
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8001F3CC: beq         $at, $zero, L_8001F404
    if (ctx->r1 == 0) {
        // 0x8001F3D0: nop
    
            goto L_8001F404;
    }
    // 0x8001F3D0: nop

    // 0x8001F3D4: b           L_8001F404
    // 0x8001F3D8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_8001F404;
    // 0x8001F3D8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8001F3DC: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
L_8001F3E0:
    // 0x8001F3E0: lw          $t9, 0x28($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X28);
    // 0x8001F3E4: addu        $t0, $t9, $s2
    ctx->r8 = ADD32(ctx->r25, ctx->r18);
    // 0x8001F3E8: lh          $t1, 0x14($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X14);
    // 0x8001F3EC: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8001F3F0: nop

    // 0x8001F3F4: slt         $at, $t8, $t1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8001F3F8: beq         $at, $zero, L_8001F404
    if (ctx->r1 == 0) {
        // 0x8001F3FC: nop
    
            goto L_8001F404;
    }
    // 0x8001F3FC: nop

    // 0x8001F400: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8001F404:
    // 0x8001F404: beql        $s0, $zero, L_8001F438
    if (ctx->r16 == 0) {
        // 0x8001F408: lh          $t5, 0x2C($s1)
        ctx->r13 = MEM_H(ctx->r17, 0X2C);
            goto L_8001F438;
    }
    goto skip_6;
    // 0x8001F408: lh          $t5, 0x2C($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X2C);
    skip_6:
    // 0x8001F40C: lh          $t2, 0x32($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X32);
    // 0x8001F410: bne         $t2, $zero, L_8001F424
    if (ctx->r10 != 0) {
        // 0x8001F414: nop
    
            goto L_8001F424;
    }
    // 0x8001F414: nop

    // 0x8001F418: lh          $t3, 0x2E($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X2E);
    // 0x8001F41C: subu        $t4, $t3, $s6
    ctx->r12 = SUB32(ctx->r11, ctx->r22);
    // 0x8001F420: sh          $t4, 0x2E($s1)
    MEM_H(0X2E, ctx->r17) = ctx->r12;
L_8001F424:
    // 0x8001F424: bne         $s4, $zero, L_8001F434
    if (ctx->r20 != 0) {
        // 0x8001F428: lh          $s7, 0x34($s1)
        ctx->r23 = MEM_H(ctx->r17, 0X34);
            goto L_8001F434;
    }
    // 0x8001F428: lh          $s7, 0x34($s1)
    ctx->r23 = MEM_H(ctx->r17, 0X34);
    // 0x8001F42C: b           L_8001F464
    // 0x8001F430: or          $v0, $s7, $zero
    ctx->r2 = ctx->r23 | 0;
        goto L_8001F464;
    // 0x8001F430: or          $v0, $s7, $zero
    ctx->r2 = ctx->r23 | 0;
L_8001F434:
    // 0x8001F434: lh          $t5, 0x2C($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X2C);
L_8001F438:
    // 0x8001F438: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8001F43C: addiu       $s2, $s2, 0x18
    ctx->r18 = ADD32(ctx->r18, 0X18);
    // 0x8001F440: slt         $at, $s3, $t5
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8001F444: bnel        $at, $zero, L_8001F3A0
    if (ctx->r1 != 0) {
        // 0x8001F448: lw          $t4, 0x28($s1)
        ctx->r12 = MEM_W(ctx->r17, 0X28);
            goto L_8001F3A0;
    }
    goto skip_7;
    // 0x8001F448: lw          $t4, 0x28($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X28);
    skip_7:
    // 0x8001F44C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
L_8001F450:
    // 0x8001F450: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
L_8001F454:
    // 0x8001F454: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8001F458: bnel        $v1, $zero, L_8001F358
    if (ctx->r3 != 0) {
        // 0x8001F45C: lh          $t0, 0x2E($s1)
        ctx->r8 = MEM_H(ctx->r17, 0X2E);
            goto L_8001F358;
    }
    goto skip_8;
    // 0x8001F45C: lh          $t0, 0x2E($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X2E);
    skip_8:
    // 0x8001F460: or          $v0, $s7, $zero
    ctx->r2 = ctx->r23 | 0;
L_8001F464:
    // 0x8001F464: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8001F468: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001F46C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001F470: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001F474: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001F478: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001F47C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8001F480: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8001F484: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8001F488: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8001F48C: jr          $ra
    // 0x8001F490: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    TRACE_RETURN()
    return;
    // 0x8001F490: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8001F2CC(uint8_t* rdram, recomp_context* ctx) {
    ground_collision(rdram, ctx, 0);
}
void chopper_cannon_ground_collision(uint8_t* rdram, recomp_context* ctx) {
    ground_collision(rdram, ctx, 1);
}
RECOMP_FUNC void func_8001F494(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8001F494: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x8001F498: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8001F49C: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8001F4A0: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8001F4A4: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8001F4A8: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8001F4AC: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8001F4B0: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8001F4B4: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8001F4B8: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8001F4BC: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8001F4C0: lh          $t6, 0x34($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X34);
    // 0x8001F4C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001F4C8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001F4CC: blez        $t6, L_8001F6D4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8001F4D0: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_8001F6D4;
    }
    // 0x8001F4D0: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8001F4D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001F4D8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8001F4DC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8001F4E0: addiu       $s6, $sp, 0x64
    ctx->r22 = ADD32(ctx->r29, 0X64);
    // 0x8001F4E4: addiu       $s4, $sp, 0xA4
    ctx->r20 = ADD32(ctx->r29, 0XA4);
    // 0x8001F4E8: addiu       $s3, $sp, 0xB0
    ctx->r19 = ADD32(ctx->r29, 0XB0);
    // 0x8001F4EC: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x8001F4F0: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
L_8001F4F4:
    // 0x8001F4F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001F4F8: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8001F4FC: addu        $t8, $t7, $s5
    ctx->r24 = ADD32(ctx->r15, ctx->r21);
    // 0x8001F500: lh          $a2, 0x0($t8)
    ctx->r6 = MEM_H(ctx->r24, 0X0);
L_8001F504:
    // 0x8001F504: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x8001F508: sll         $t0, $s1, 2
    ctx->r8 = S32(ctx->r17 << 2);
    // 0x8001F50C: subu        $t0, $t0, $s1
    ctx->r8 = SUB32(ctx->r8, ctx->r17);
    // 0x8001F510: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8001F514: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8001F518: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x8001F51C: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8001F520: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001F524: slti        $at, $v0, 0xC
    ctx->r1 = SIGNED(ctx->r2) < 0XC ? 1 : 0;
    // 0x8001F528: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8001F52C: bne         $at, $zero, L_8001F504
    if (ctx->r1 != 0) {
        // 0x8001F530: swc1        $f4, 0x8($t2)
        MEM_W(0X8, ctx->r10) = ctx->f4.u32l;
            goto L_8001F504;
    }
    // 0x8001F530: swc1        $f4, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f4.u32l;
    // 0x8001F534: andi        $t3, $a2, 0x20
    ctx->r11 = ctx->r6 & 0X20;
    // 0x8001F538: beq         $t3, $zero, L_8001F5B0
    if (ctx->r11 == 0) {
        // 0x8001F53C: andi        $t5, $a2, 0x40
        ctx->r13 = ctx->r6 & 0X40;
            goto L_8001F5B0;
    }
    // 0x8001F53C: andi        $t5, $a2, 0x40
    ctx->r13 = ctx->r6 & 0X40;
    // 0x8001F540: sll         $a0, $a2, 16
    ctx->r4 = S32(ctx->r6 << 16);
    // 0x8001F544: sra         $t4, $a0, 16
    ctx->r12 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001F548: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8001F54C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8001F550:
    // 0x8001F550: andi        $t5, $a0, 0x4
    ctx->r13 = ctx->r4 & 0X4;
    // 0x8001F554: beq         $t5, $zero, L_8001F598
    if (ctx->r13 == 0) {
        // 0x8001F558: or          $t2, $a0, $zero
        ctx->r10 = ctx->r4 | 0;
            goto L_8001F598;
    }
    // 0x8001F558: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x8001F55C: lw          $t6, 0x30($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X30);
    // 0x8001F560: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x8001F564: subu        $t7, $t7, $s1
    ctx->r15 = SUB32(ctx->r15, ctx->r17);
    // 0x8001F568: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8001F56C: sll         $t9, $a1, 1
    ctx->r25 = S32(ctx->r5 << 1);
    // 0x8001F570: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8001F574: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x8001F578: lh          $t1, 0x2($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X2);
    // 0x8001F57C: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8001F580: addu        $v1, $v0, $t8
    ctx->r3 = ADD32(ctx->r2, ctx->r24);
    // 0x8001F584: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8001F588: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8001F58C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001F590: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8001F594: swc1        $f16, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f16.u32l;
L_8001F598:
    // 0x8001F598: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001F59C: sll         $t3, $t2, 17
    ctx->r11 = S32(ctx->r10 << 17);
    // 0x8001F5A0: bne         $a1, $s2, L_8001F550
    if (ctx->r5 != ctx->r18) {
        // 0x8001F5A4: sra         $a0, $t3, 16
        ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
            goto L_8001F550;
    }
    // 0x8001F5A4: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8001F5A8: b           L_8001F6C0
    // 0x8001F5AC: lh          $t3, 0x34($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X34);
        goto L_8001F6C0;
    // 0x8001F5AC: lh          $t3, 0x34($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X34);
L_8001F5B0:
    // 0x8001F5B0: beql        $t5, $zero, L_8001F6C0
    if (ctx->r13 == 0) {
        // 0x8001F5B4: lh          $t3, 0x34($s0)
        ctx->r11 = MEM_H(ctx->r16, 0X34);
            goto L_8001F6C0;
    }
    goto skip_0;
    // 0x8001F5B4: lh          $t3, 0x34($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X34);
    skip_0:
    // 0x8001F5B8: lw          $t6, 0x30($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X30);
    // 0x8001F5BC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8001F5C0: addu        $v0, $t6, $s5
    ctx->r2 = ADD32(ctx->r14, ctx->r21);
    // 0x8001F5C4: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x8001F5C8: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x8001F5CC: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x8001F5D0: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8001F5D4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8001F5D8: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8001F5DC: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001F5E0: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001F5E4: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8001F5E8: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001F5EC: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8001F5F0: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8001F5F4: jal         0x80001A6C
    // 0x8001F5F8: nop

    func_80001A6C(rdram, ctx);
        goto after_0;
    // 0x8001F5F8: nop

    after_0:
    // 0x8001F5FC: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x8001F600: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8001F604: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8001F608: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8001F60C: jal         0x80049840
    // 0x8001F610: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_80049840(rdram, ctx);
        goto after_1;
    // 0x8001F610: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_1:
    // 0x8001F614: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8001F618: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8001F61C: jal         0x80000BD8
    // 0x8001F620: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_80000BD8(rdram, ctx);
        goto after_2;
    // 0x8001F620: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_2:
    // 0x8001F624: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    // 0x8001F628: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8001F62C: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8001F630: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8001F634: jal         0x80049840
    // 0x8001F638: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_80049840(rdram, ctx);
        goto after_3;
    // 0x8001F638: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_3:
    // 0x8001F63C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8001F640: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8001F644: jal         0x80000BD8
    // 0x8001F648: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_80000BD8(rdram, ctx);
        goto after_4;
    // 0x8001F648: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_4:
    // 0x8001F64C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001F650: addiu       $a0, $sp, 0xA4
    ctx->r4 = ADD32(ctx->r29, 0XA4);
    // 0x8001F654: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x8001F658: subu        $t1, $t1, $s1
    ctx->r9 = SUB32(ctx->r9, ctx->r17);
    // 0x8001F65C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8001F660: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8001F664: beq         $a0, $s3, L_8001F6A0
    if (ctx->r4 == ctx->r19) {
        // 0x8001F668: lw          $t0, 0x30($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X30);
            goto L_8001F6A0;
    }
    // 0x8001F668: lw          $t0, 0x30($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X30);
L_8001F66C:
    // 0x8001F66C: lwc1        $f18, 0x2C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x8001F670: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8001F674: addu        $v1, $t2, $v0
    ctx->r3 = ADD32(ctx->r10, ctx->r2);
    // 0x8001F678: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8001F67C: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x8001F680: subu        $t1, $t1, $s1
    ctx->r9 = SUB32(ctx->r9, ctx->r17);
    // 0x8001F684: add.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8001F688: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8001F68C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001F690: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8001F694: swc1        $f18, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f18.u32l;
    // 0x8001F698: bne         $a0, $s3, L_8001F66C
    if (ctx->r4 != ctx->r19) {
        // 0x8001F69C: lw          $t0, 0x30($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X30);
            goto L_8001F66C;
    }
    // 0x8001F69C: lw          $t0, 0x30($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X30);
L_8001F6A0:
    // 0x8001F6A0: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8001F6A4: addu        $v1, $t2, $v0
    ctx->r3 = ADD32(ctx->r10, ctx->r2);
    // 0x8001F6A8: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8001F6AC: lwc1        $f18, 0x2C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x8001F6B0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001F6B4: add.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8001F6B8: swc1        $f18, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f18.u32l;
    // 0x8001F6BC: lh          $t3, 0x34($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X34);
L_8001F6C0:
    // 0x8001F6C0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8001F6C4: addiu       $s5, $s5, 0x18
    ctx->r21 = ADD32(ctx->r21, 0X18);
    // 0x8001F6C8: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8001F6CC: bnel        $at, $zero, L_8001F4F4
    if (ctx->r1 != 0) {
        // 0x8001F6D0: lw          $t7, 0x30($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X30);
            goto L_8001F4F4;
    }
    goto skip_1;
    // 0x8001F6D0: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
    skip_1:
L_8001F6D4:
    // 0x8001F6D4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8001F6D8: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8001F6DC: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8001F6E0: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8001F6E4: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8001F6E8: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8001F6EC: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8001F6F0: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8001F6F4: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8001F6F8: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8001F6FC: jr          $ra
    // 0x8001F700: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    TRACE_RETURN()
    return;
    // 0x8001F700: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
;}
