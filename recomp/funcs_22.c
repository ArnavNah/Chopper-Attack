#include "recomp.h"
#include "trace.h"
#include "funcs.h"

RECOMP_FUNC void func_8005002C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005002C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80050030: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80050034: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80050038: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8005003C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80050040: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80050044: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80050048: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005004C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80050050: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80050054: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x80050058: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8005005C: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x80050060: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x80050064: sw          $t6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r14;
    // 0x80050068: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8005006C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80050070: addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
    // 0x80050074: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80050078: or          $t4, $a0, $zero
    ctx->r12 = ctx->r4 | 0;
L_8005007C:
    // 0x8005007C: sb          $zero, 0xA8($s1)
    MEM_B(0XA8, ctx->r17) = 0;
    // 0x80050080: sw          $zero, 0x58($t4)
    MEM_W(0X58, ctx->r12) = 0;
    // 0x80050084: sb          $zero, 0x98($s1)
    MEM_B(0X98, ctx->r17) = 0;
    // 0x80050088: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8005008C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80050090: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x80050094: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x80050098: sllv        $t7, $t6, $t5
    ctx->r15 = S32(ctx->r14 << (ctx->r13 & 31));
    // 0x8005009C: beq         $v0, $zero, L_800500C8
    if (ctx->r2 == 0) {
        // 0x800500A0: addu        $t6, $s4, $v0
        ctx->r14 = ADD32(ctx->r20, ctx->r2);
            goto L_800500C8;
    }
    // 0x800500A0: addu        $t6, $s4, $v0
    ctx->r14 = ADD32(ctx->r20, ctx->r2);
    // 0x800500A4: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x800500A8: or          $t2, $s0, $zero
    ctx->r10 = ctx->r16 | 0;
    // 0x800500AC: or          $t3, $t5, $zero
    ctx->r11 = ctx->r13 | 0;
    // 0x800500B0: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x800500B4: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x800500B8: jal         0x8004FCD4
    // 0x800500BC: sw          $t6, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r14;
    func_8004FCD4(rdram, ctx);
        goto after_0;
    // 0x800500BC: sw          $t6, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r14;
    after_0:
    // 0x800500C0: b           L_800500CC
    // 0x800500C4: sw          $v0, 0xB8($t4)
    MEM_W(0XB8, ctx->r12) = ctx->r2;
        goto L_800500CC;
    // 0x800500C4: sw          $v0, 0xB8($t4)
    MEM_W(0XB8, ctx->r12) = ctx->r2;
L_800500C8:
    // 0x800500C8: sw          $zero, 0x18($t4)
    MEM_W(0X18, ctx->r12) = 0;
L_800500CC:
    // 0x800500CC: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x800500D0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800500D4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800500D8: bne         $t5, $s3, L_8005007C
    if (ctx->r13 != ctx->r19) {
        // 0x800500DC: addiu       $t4, $t4, 0x4
        ctx->r12 = ADD32(ctx->r12, 0X4);
            goto L_8005007C;
    }
    // 0x800500DC: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x800500E0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800500E4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800500E8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800500EC: lw          $t7, 0x40($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X40);
    // 0x800500F0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800500F4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800500F8: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800500FC: bgez        $t7, L_80050110
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80050100: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80050110;
    }
    // 0x80050100: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80050104: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80050108: nop

    // 0x8005010C: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_80050110:
    // 0x80050110: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80050114: div.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x80050118: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x8005011C: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x80050120: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80050124: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80050128: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8005012C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80050130: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80050134: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80050138: jr          $ra
    // 0x8005013C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    TRACE_RETURN()
    return;
    // 0x8005013C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80050140(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80050140: addiu       $sp, $sp, -0x150
    ctx->r29 = ADD32(ctx->r29, -0X150);
    // 0x80050144: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80050148: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8005014C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80050150: addiu       $s3, $sp, 0x48
    ctx->r19 = ADD32(ctx->r29, 0X48);
    // 0x80050154: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80050158: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8005015C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80050160: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80050164: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80050168: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8005016C: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x80050170: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x80050174: jal         0x8005002C
    // 0x80050178: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_8005002C(rdram, ctx);
        goto after_0;
    // 0x80050178: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x8005017C: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
    // 0x80050180: addiu       $s4, $sp, 0x140
    ctx->r20 = ADD32(ctx->r29, 0X140);
    // 0x80050184: addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
    // 0x80050188: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
L_8005018C:
    // 0x8005018C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80050190: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80050194: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x80050198: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8005019C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x800501A0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800501A4: sw          $t7, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r15;
    // 0x800501A8: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800501AC: sw          $t8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r24;
L_800501B0:
    // 0x800501B0: lw          $t0, 0x18($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X18);
    // 0x800501B4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800501B8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800501BC: sw          $t0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r8;
    // 0x800501C0: lw          $t1, 0x58($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X58);
    // 0x800501C4: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800501C8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800501CC: sw          $t1, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r9;
    // 0x800501D0: lbu         $t2, 0x94($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X94);
    // 0x800501D4: sb          $t2, 0x88($a1)
    MEM_B(0X88, ctx->r5) = ctx->r10;
    // 0x800501D8: lbu         $t3, 0xA4($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0XA4);
    // 0x800501DC: sb          $t3, 0x98($a1)
    MEM_B(0X98, ctx->r5) = ctx->r11;
    // 0x800501E0: lw          $t4, 0xA8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XA8);
    // 0x800501E4: sw          $t4, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = ctx->r12;
    // 0x800501E8: lw          $t5, 0xC($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XC);
    // 0x800501EC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800501F0: lw          $t6, 0x4C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4C);
    // 0x800501F4: sw          $t6, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r14;
    // 0x800501F8: lbu         $t7, 0x95($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X95);
    // 0x800501FC: sb          $t7, 0x89($a1)
    MEM_B(0X89, ctx->r5) = ctx->r15;
    // 0x80050200: lbu         $t8, 0xA5($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XA5);
    // 0x80050204: sb          $t8, 0x99($a1)
    MEM_B(0X99, ctx->r5) = ctx->r24;
    // 0x80050208: lw          $t9, 0xAC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XAC);
    // 0x8005020C: sw          $t9, 0xA0($v0)
    MEM_W(0XA0, ctx->r2) = ctx->r25;
    // 0x80050210: lw          $t0, 0x10($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X10);
    // 0x80050214: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80050218: lw          $t1, 0x50($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X50);
    // 0x8005021C: sw          $t1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r9;
    // 0x80050220: lbu         $t2, 0x96($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X96);
    // 0x80050224: sb          $t2, 0x8A($a1)
    MEM_B(0X8A, ctx->r5) = ctx->r10;
    // 0x80050228: lbu         $t3, 0xA6($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0XA6);
    // 0x8005022C: sb          $t3, 0x9A($a1)
    MEM_B(0X9A, ctx->r5) = ctx->r11;
    // 0x80050230: lw          $t4, 0xB0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XB0);
    // 0x80050234: sw          $t4, 0xA4($v0)
    MEM_W(0XA4, ctx->r2) = ctx->r12;
    // 0x80050238: lw          $t5, 0x14($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X14);
    // 0x8005023C: sw          $t5, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r13;
    // 0x80050240: lw          $t6, 0x54($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X54);
    // 0x80050244: sw          $t6, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r14;
    // 0x80050248: lbu         $t7, 0x97($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X97);
    // 0x8005024C: sb          $t7, 0x8B($a1)
    MEM_B(0X8B, ctx->r5) = ctx->r15;
    // 0x80050250: lbu         $t8, 0xA7($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XA7);
    // 0x80050254: sb          $t8, 0x9B($a1)
    MEM_B(0X9B, ctx->r5) = ctx->r24;
    // 0x80050258: lw          $t9, 0xB4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XB4);
    // 0x8005025C: bne         $a0, $s0, L_800501B0
    if (ctx->r4 != ctx->r16) {
        // 0x80050260: sw          $t9, 0xA8($v0)
        MEM_W(0XA8, ctx->r2) = ctx->r25;
            goto L_800501B0;
    }
    // 0x80050260: sw          $t9, 0xA8($v0)
    MEM_W(0XA8, ctx->r2) = ctx->r25;
    // 0x80050264: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80050268: jal         0x8004FD34
    // 0x8005026C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_8004FD34(rdram, ctx);
        goto after_1;
    // 0x8005026C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_1:
    // 0x80050270: lh          $t0, 0x140($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X140);
    // 0x80050274: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x80050278: beq         $t0, $s5, L_80050288
    if (ctx->r8 == ctx->r21) {
        // 0x8005027C: sltu        $at, $t1, $s2
        ctx->r1 = ctx->r9 < ctx->r18 ? 1 : 0;
            goto L_80050288;
    }
    // 0x8005027C: sltu        $at, $t1, $s2
    ctx->r1 = ctx->r9 < ctx->r18 ? 1 : 0;
    // 0x80050280: bnel        $at, $zero, L_8005018C
    if (ctx->r1 != 0) {
        // 0x80050284: lw          $t6, 0x4C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X4C);
            goto L_8005018C;
    }
    goto skip_0;
    // 0x80050284: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    skip_0:
L_80050288:
    // 0x80050288: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8005028C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80050290: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80050294: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80050298: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8005029C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800502A0: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800502A4: jr          $ra
    // 0x800502A8: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
    TRACE_RETURN()
    return;
    // 0x800502A8: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
;}
RECOMP_FUNC void func_800502AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800502AC: jr          $ra
    // 0x800502B0: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    TRACE_RETURN()
    return;
    // 0x800502B0: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
;}
RECOMP_FUNC void func_800502B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800502B4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800502B8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800502BC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800502C0: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x800502C4: ldc1        $f6, -0x6F00($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X6F00);
    // 0x800502C8: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x800502CC: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800502D0: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800502D4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800502D8: bgez        $t7, L_800502F0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800502DC: cvt.d.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
            goto L_800502F0;
    }
    // 0x800502DC: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x800502E0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800502E4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800502E8: nop

    // 0x800502EC: add.d       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f16.d + ctx->f18.d;
L_800502F0:
    // 0x800502F0: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x800502F4: mul.d       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x800502F8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800502FC: bgez        $a2, L_80050314
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80050300: cvt.d.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
            goto L_80050314;
    }
    // 0x80050300: cvt.d.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
    // 0x80050304: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80050308: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005030C: nop

    // 0x80050310: add.d       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f10.d + ctx->f18.d;
L_80050314:
    // 0x80050314: div.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f10.d);
    // 0x80050318: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005031C: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80050320: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80050324: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80050328: nop

    // 0x8005032C: cvt.w.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_D(ctx->f8.d);
    // 0x80050330: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80050334: nop

    // 0x80050338: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x8005033C: beql        $v0, $zero, L_80050398
    if (ctx->r2 == 0) {
        // 0x80050340: mfc1        $v0, $f16
        ctx->r2 = (int32_t)ctx->f16.u32l;
            goto L_80050398;
    }
    goto skip_0;
    // 0x80050340: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x80050344: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80050348: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005034C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80050350: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80050354: sub.d       $f16, $f8, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f16.d = ctx->f8.d - ctx->f16.d;
    // 0x80050358: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x8005035C: nop

    // 0x80050360: cvt.w.d     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_D(ctx->f16.d);
    // 0x80050364: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80050368: nop

    // 0x8005036C: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80050370: bnel        $v0, $zero, L_8005038C
    if (ctx->r2 != 0) {
        // 0x80050374: ctc1        $t8, $FpcCsr
        set_cop1_cs(ctx->r24);
            goto L_8005038C;
    }
    goto skip_1;
    // 0x80050374: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    skip_1:
    // 0x80050378: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x8005037C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80050380: jr          $ra
    // 0x80050384: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    TRACE_RETURN()
    return;
    // 0x80050384: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    // 0x80050388: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
L_8005038C:
    // 0x8005038C: jr          $ra
    // 0x80050390: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    TRACE_RETURN()
    return;
    // 0x80050390: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80050394: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
L_80050398:
    // 0x80050398: nop

    // 0x8005039C: bltzl       $v0, L_8005038C
    if (SIGNED(ctx->r2) < 0) {
        // 0x800503A0: ctc1        $t8, $FpcCsr
        set_cop1_cs(ctx->r24);
            goto L_8005038C;
    }
    goto skip_2;
    // 0x800503A0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    skip_2:
    // 0x800503A4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800503A8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800503B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800503B0: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x800503B4: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x800503B8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800503BC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800503C0: bgez        $a2, L_800503D4
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800503C4: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800503D4;
    }
    // 0x800503C4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800503C8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800503CC: nop

    // 0x800503D0: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_800503D4:
    // 0x800503D4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800503D8: mul.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800503DC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800503E0: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x800503E4: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800503E8: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800503EC: bgez        $t7, L_80050400
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800503F0: cvt.s.w     $f16, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80050400;
    }
    // 0x800503F0: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800503F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800503F8: nop

    // 0x800503FC: add.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f6.fl;
L_80050400:
    // 0x80050400: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80050404: ldc1        $f18, -0x6EF8($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X6EF8);
    // 0x80050408: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8005040C: mul.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x80050410: div.d       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f8.d);
    // 0x80050414: jr          $ra
    // 0x80050418: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    TRACE_RETURN()
    return;
    // 0x80050418: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
;}
RECOMP_FUNC void func_8005041C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005041C: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80050420: or          $t1, $a1, $zero
    ctx->r9 = ctx->r5 | 0;
    // 0x80050424: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80050428: bne         $t6, $zero, L_80050438
    if (ctx->r14 != 0) {
        // 0x8005042C: lw          $v0, 0x10($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X10);
            goto L_80050438;
    }
    // 0x8005042C: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x80050430: jr          $ra
    // 0x80050434: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    TRACE_RETURN()
    return;
    // 0x80050434: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80050438:
    // 0x80050438: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005043C: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x80050440: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
L_80050444:
    // 0x80050444: addiu       $t6, $a2, 0x1
    ctx->r14 = ADD32(ctx->r6, 0X1);
    // 0x80050448: srlv        $t7, $a1, $a2
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r6 & 31));
    // 0x8005044C: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80050450: beql        $t8, $zero, L_80050494
    if (ctx->r24 == 0) {
        // 0x80050454: srlv        $t7, $a1, $t6
        ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
            goto L_80050494;
    }
    goto skip_0;
    // 0x80050454: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
    skip_0:
    // 0x80050458: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x8005045C: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x80050460: addu        $a3, $a0, $t9
    ctx->r7 = ADD32(ctx->r4, ctx->r25);
    // 0x80050464: beql        $t3, $zero, L_80050480
    if (ctx->r11 == 0) {
        // 0x80050468: lw          $t0, 0xB8($a3)
        ctx->r8 = MEM_W(ctx->r7, 0XB8);
            goto L_80050480;
    }
    goto skip_1;
    // 0x80050468: lw          $t0, 0xB8($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XB8);
    skip_1:
    // 0x8005046C: lw          $t4, 0xB8($a3)
    ctx->r12 = MEM_W(ctx->r7, 0XB8);
    // 0x80050470: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x80050474: sw          $t5, 0xB8($a3)
    MEM_W(0XB8, ctx->r7) = ctx->r13;
    // 0x80050478: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    // 0x8005047C: lw          $t0, 0xB8($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XB8);
L_80050480:
    // 0x80050480: sltu        $at, $t0, $v1
    ctx->r1 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x80050484: beql        $at, $zero, L_80050494
    if (ctx->r1 == 0) {
        // 0x80050488: srlv        $t7, $a1, $t6
        ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
            goto L_80050494;
    }
    goto skip_2;
    // 0x80050488: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
    skip_2:
    // 0x8005048C: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80050490: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
L_80050494:
    // 0x80050494: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80050498: beq         $t8, $zero, L_800504D8
    if (ctx->r24 == 0) {
        // 0x8005049C: addiu       $t6, $a2, 0x2
        ctx->r14 = ADD32(ctx->r6, 0X2);
            goto L_800504D8;
    }
    // 0x8005049C: addiu       $t6, $a2, 0x2
    ctx->r14 = ADD32(ctx->r6, 0X2);
    // 0x800504A0: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x800504A4: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800504A8: addu        $a3, $a0, $t9
    ctx->r7 = ADD32(ctx->r4, ctx->r25);
    // 0x800504AC: beql        $t3, $zero, L_800504C8
    if (ctx->r11 == 0) {
        // 0x800504B0: lw          $t0, 0xBC($a3)
        ctx->r8 = MEM_W(ctx->r7, 0XBC);
            goto L_800504C8;
    }
    goto skip_3;
    // 0x800504B0: lw          $t0, 0xBC($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XBC);
    skip_3:
    // 0x800504B4: lw          $t4, 0xBC($a3)
    ctx->r12 = MEM_W(ctx->r7, 0XBC);
    // 0x800504B8: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x800504BC: sw          $t5, 0xBC($a3)
    MEM_W(0XBC, ctx->r7) = ctx->r13;
    // 0x800504C0: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    // 0x800504C4: lw          $t0, 0xBC($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XBC);
L_800504C8:
    // 0x800504C8: sltu        $at, $t0, $v1
    ctx->r1 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x800504CC: beql        $at, $zero, L_800504DC
    if (ctx->r1 == 0) {
        // 0x800504D0: srlv        $t7, $a1, $t6
        ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
            goto L_800504DC;
    }
    goto skip_4;
    // 0x800504D0: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
    skip_4:
    // 0x800504D4: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_800504D8:
    // 0x800504D8: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
L_800504DC:
    // 0x800504DC: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800504E0: beq         $t8, $zero, L_80050520
    if (ctx->r24 == 0) {
        // 0x800504E4: addiu       $t6, $a2, 0x3
        ctx->r14 = ADD32(ctx->r6, 0X3);
            goto L_80050520;
    }
    // 0x800504E4: addiu       $t6, $a2, 0x3
    ctx->r14 = ADD32(ctx->r6, 0X3);
    // 0x800504E8: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x800504EC: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800504F0: addu        $a3, $a0, $t9
    ctx->r7 = ADD32(ctx->r4, ctx->r25);
    // 0x800504F4: beql        $t3, $zero, L_80050510
    if (ctx->r11 == 0) {
        // 0x800504F8: lw          $t0, 0xC0($a3)
        ctx->r8 = MEM_W(ctx->r7, 0XC0);
            goto L_80050510;
    }
    goto skip_5;
    // 0x800504F8: lw          $t0, 0xC0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XC0);
    skip_5:
    // 0x800504FC: lw          $t4, 0xC0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0XC0);
    // 0x80050500: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x80050504: sw          $t5, 0xC0($a3)
    MEM_W(0XC0, ctx->r7) = ctx->r13;
    // 0x80050508: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    // 0x8005050C: lw          $t0, 0xC0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XC0);
L_80050510:
    // 0x80050510: sltu        $at, $t0, $v1
    ctx->r1 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x80050514: beql        $at, $zero, L_80050524
    if (ctx->r1 == 0) {
        // 0x80050518: srlv        $t7, $a1, $t6
        ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
            goto L_80050524;
    }
    goto skip_6;
    // 0x80050518: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
    skip_6:
    // 0x8005051C: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_80050520:
    // 0x80050520: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
L_80050524:
    // 0x80050524: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80050528: beql        $t8, $zero, L_80050568
    if (ctx->r24 == 0) {
        // 0x8005052C: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_80050568;
    }
    goto skip_7;
    // 0x8005052C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    skip_7:
    // 0x80050530: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x80050534: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x80050538: addu        $a3, $a0, $t9
    ctx->r7 = ADD32(ctx->r4, ctx->r25);
    // 0x8005053C: beql        $t3, $zero, L_80050554
    if (ctx->r11 == 0) {
        // 0x80050540: lw          $a1, 0xC4($a3)
        ctx->r5 = MEM_W(ctx->r7, 0XC4);
            goto L_80050554;
    }
    goto skip_8;
    // 0x80050540: lw          $a1, 0xC4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XC4);
    skip_8:
    // 0x80050544: lw          $t4, 0xC4($a3)
    ctx->r12 = MEM_W(ctx->r7, 0XC4);
    // 0x80050548: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x8005054C: sw          $t5, 0xC4($a3)
    MEM_W(0XC4, ctx->r7) = ctx->r13;
    // 0x80050550: lw          $a1, 0xC4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XC4);
L_80050554:
    // 0x80050554: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x80050558: beql        $at, $zero, L_80050568
    if (ctx->r1 == 0) {
        // 0x8005055C: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_80050568;
    }
    goto skip_9;
    // 0x8005055C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    skip_9:
    // 0x80050560: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80050564: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_80050568:
    // 0x80050568: bnel        $a2, $t2, L_80050444
    if (ctx->r6 != ctx->r10) {
        // 0x8005056C: lw          $a1, 0x4($a0)
        ctx->r5 = MEM_W(ctx->r4, 0X4);
            goto L_80050444;
    }
    goto skip_10;
    // 0x8005056C: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    skip_10:
    // 0x80050570: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x80050574: sw          $v1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r3;
    // 0x80050578: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005057C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80050590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80050590: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80050594: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80050598: addiu       $t6, $zero, 0xD
    ctx->r14 = ADD32(0, 0XD);
    // 0x8005059C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800505A0: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x800505A4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800505A8: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x800505AC: jal         0x8005702C
    // 0x800505B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8005702C(rdram, ctx);
        goto after_0;
    // 0x800505B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800505B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800505B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800505BC: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800505D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800505D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800505D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800505D8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800505DC: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x800505E0: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x800505E4: sh          $t7, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r15;
    // 0x800505E8: sh          $t6, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r14;
    // 0x800505EC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800505F0: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x800505F4: jal         0x8005702C
    // 0x800505F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8005702C(rdram, ctx);
        goto after_0;
    // 0x800505F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800505FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80050600: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80050604: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80050610(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80050610: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80050614: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80050618: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x8005061C: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x80050620: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80050624: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x80050628: jal         0x8005702C
    // 0x8005062C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8005702C(rdram, ctx);
        goto after_0;
    // 0x8005062C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80050630: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80050634: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80050638: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80050640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80050640: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80050644: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80050648: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8005064C: jr          $ra
    // 0x80050650: sw          $t7, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r15;
    TRACE_RETURN()
    return;
    // 0x80050650: sw          $t7, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_80050660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80050660: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80050664: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80050668: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x8005066C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80050670: sh          $t6, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r14;
    // 0x80050674: lw          $t7, 0x3C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X3C);
    // 0x80050678: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8005067C: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x80050680: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80050684: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80050688: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x8005068C: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x80050690: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80050694: jal         0x8005702C
    // 0x80050698: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8005702C(rdram, ctx);
        goto after_0;
    // 0x80050698: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8005069C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800506A0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800506A4: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800506B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800506B0: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x800506B4: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800506B8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800506BC: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x800506C0: sll         $v1, $t7, 2
    ctx->r3 = S32(ctx->r15 << 2);
    // 0x800506C4: subu        $v1, $v1, $t7
    ctx->r3 = SUB32(ctx->r3, ctx->r15);
    // 0x800506C8: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800506CC: addu        $t8, $v1, $v0
    ctx->r24 = ADD32(ctx->r3, ctx->r2);
    // 0x800506D0: lw          $t9, 0x28($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X28);
    // 0x800506D4: addu        $t0, $v0, $v1
    ctx->r8 = ADD32(ctx->r2, ctx->r3);
    // 0x800506D8: bne         $t9, $zero, L_800506F8
    if (ctx->r25 != 0) {
        // 0x800506DC: nop
    
            goto L_800506F8;
    }
    // 0x800506DC: nop

    // 0x800506E0: sw          $zero, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = 0;
    // 0x800506E4: lw          $t1, 0x3C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X3C);
    // 0x800506E8: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800506EC: bne         $t7, $t1, L_800506F8
    if (ctx->r15 != ctx->r9) {
        // 0x800506F0: nop
    
            goto L_800506F8;
    }
    // 0x800506F0: nop

    // 0x800506F4: sw          $t2, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r10;
L_800506F8:
    // 0x800506F8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80050700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80050700: lw          $a2, 0x44($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X44);
    // 0x80050704: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x80050708: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8005070C: blez        $a2, L_80050790
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80050710: addiu       $a3, $zero, 0x30
        ctx->r7 = ADD32(0, 0X30);
            goto L_80050790;
    }
    // 0x80050710: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
L_80050714:
    // 0x80050714: multu       $v1, $a3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80050718: mflo        $t6
    ctx->r14 = lo;
    // 0x8005071C: addu        $a0, $v0, $t6
    ctx->r4 = ADD32(ctx->r2, ctx->r14);
    // 0x80050720: lw          $t7, 0x1C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1C);
    // 0x80050724: bne         $t7, $zero, L_80050778
    if (ctx->r15 != 0) {
        // 0x80050728: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80050778;
    }
    // 0x80050728: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005072C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80050730: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x80050734: addiu       $t9, $zero, 0x40
    ctx->r25 = ADD32(0, 0X40);
    // 0x80050738: sw          $a1, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r5;
    // 0x8005073C: sh          $t8, 0x20($a0)
    MEM_H(0X20, ctx->r4) = ctx->r24;
    // 0x80050740: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
    // 0x80050744: sb          $t9, 0x2E($a0)
    MEM_B(0X2E, ctx->r4) = ctx->r25;
    // 0x80050748: sb          $zero, 0x2F($a0)
    MEM_B(0X2F, ctx->r4) = 0;
    // 0x8005074C: swc1        $f4, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f4.u32l;
    // 0x80050750: lbu         $t0, 0xD($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0XD);
    // 0x80050754: addiu       $at, $zero, 0x7F
    ctx->r1 = ADD32(0, 0X7F);
    // 0x80050758: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8005075C: sll         $t1, $t0, 15
    ctx->r9 = S32(ctx->r8 << 15);
    // 0x80050760: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80050764: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x80050768: mflo        $t2
    ctx->r10 = lo;
    // 0x8005076C: sh          $t2, 0x2C($a0)
    MEM_H(0X2C, ctx->r4) = ctx->r10;
    // 0x80050770: jr          $ra
    // 0x80050774: nop

    TRACE_RETURN()
    return;
    // 0x80050774: nop

L_80050778:
    // 0x80050778: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8005077C: sll         $t3, $v1, 16
    ctx->r11 = S32(ctx->r3 << 16);
    // 0x80050780: sra         $v1, $t3, 16
    ctx->r3 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80050784: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80050788: bne         $at, $zero, L_80050714
    if (ctx->r1 != 0) {
        // 0x8005078C: nop
    
            goto L_80050714;
    }
    // 0x8005078C: nop

L_80050790:
    // 0x80050790: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80050794: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800507A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800507A0: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x800507A4: andi        $t6, $a1, 0xF
    ctx->r14 = ctx->r5 & 0XF;
    // 0x800507A8: subu        $v0, $v1, $t6
    ctx->r2 = SUB32(ctx->r3, ctx->r14);
    // 0x800507AC: beq         $v1, $v0, L_800507BC
    if (ctx->r3 == ctx->r2) {
        // 0x800507B0: addu        $t7, $a1, $v0
        ctx->r15 = ADD32(ctx->r5, ctx->r2);
            goto L_800507BC;
    }
    // 0x800507B0: addu        $t7, $a1, $v0
    ctx->r15 = ADD32(ctx->r5, ctx->r2);
    // 0x800507B4: b           L_800507C0
    // 0x800507B8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
        goto L_800507C0;
    // 0x800507B8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_800507BC:
    // 0x800507BC: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
L_800507C0:
    // 0x800507C0: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800507C4: sw          $a2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r6;
    // 0x800507C8: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x800507CC: jr          $ra
    // 0x800507D0: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    TRACE_RETURN()
    return;
    // 0x800507D0: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_800507E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800507E0: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x800507E4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800507E8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800507EC: multu       $a3, $t6
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800507F0: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    // 0x800507F4: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800507F8: lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X4);
    // 0x800507FC: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80050800: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80050804: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80050808: mflo        $v0
    ctx->r2 = lo;
    // 0x8005080C: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x80050810: and         $t7, $v0, $at
    ctx->r15 = ctx->r2 & ctx->r1;
    // 0x80050814: addu        $t1, $a0, $t7
    ctx->r9 = ADD32(ctx->r4, ctx->r15);
    // 0x80050818: sltu        $at, $t0, $t1
    ctx->r1 = ctx->r8 < ctx->r9 ? 1 : 0;
    // 0x8005081C: bne         $at, $zero, L_8005082C
    if (ctx->r1 != 0) {
        // 0x80050820: addu        $t2, $a0, $t7
        ctx->r10 = ADD32(ctx->r4, ctx->r15);
            goto L_8005082C;
    }
    // 0x80050820: addu        $t2, $a0, $t7
    ctx->r10 = ADD32(ctx->r4, ctx->r15);
    // 0x80050824: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80050828: sw          $t2, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r10;
L_8005082C:
    // 0x8005082C: jr          $ra
    // 0x80050830: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    TRACE_RETURN()
    return;
    // 0x80050830: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_800509A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800509A0: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800509A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800509A8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800509B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800509B0: lbu         $t6, 0x3($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X3);
    // 0x800509B4: bne         $t6, $zero, L_80050A94
    if (ctx->r14 != 0) {
        // 0x800509B8: nop
    
            goto L_80050A94;
    }
    // 0x800509B8: nop

    // 0x800509BC: lh          $t7, 0xE($a0)
    ctx->r15 = MEM_H(ctx->r4, 0XE);
    // 0x800509C0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800509C4: sb          $t1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r9;
    // 0x800509C8: blez        $t7, L_80050A94
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800509CC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80050A94;
    }
    // 0x800509CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800509D0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800509D4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800509D8: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
L_800509DC:
    // 0x800509DC: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800509E0: sw          $t9, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r25;
    // 0x800509E4: lbu         $t6, 0xE($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0XE);
    // 0x800509E8: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800509EC: bnel        $t6, $zero, L_80050A80
    if (ctx->r14 != 0) {
        // 0x800509F0: lh          $t8, 0xE($a0)
        ctx->r24 = MEM_H(ctx->r4, 0XE);
            goto L_80050A80;
    }
    goto skip_0;
    // 0x800509F0: lh          $t8, 0xE($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE);
    skip_0:
    // 0x800509F4: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x800509F8: sb          $t1, 0xE($t9)
    MEM_B(0XE, ctx->r25) = ctx->r9;
    // 0x800509FC: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x80050A00: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80050A04: lw          $t9, 0x4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4);
    // 0x80050A08: lw          $t7, 0x8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X8);
    // 0x80050A0C: addu        $t6, $t9, $a1
    ctx->r14 = ADD32(ctx->r25, ctx->r5);
    // 0x80050A10: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x80050A14: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x80050A18: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x80050A1C: lbu         $t9, 0x9($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X9);
    // 0x80050A20: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x80050A24: bnel        $t9, $zero, L_80050A80
    if (ctx->r25 != 0) {
        // 0x80050A28: lh          $t8, 0xE($a0)
        ctx->r24 = MEM_H(ctx->r4, 0XE);
            goto L_80050A80;
    }
    goto skip_1;
    // 0x80050A28: lh          $t8, 0xE($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE);
    skip_1:
    // 0x80050A2C: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x80050A30: lbu         $a2, 0x8($t8)
    ctx->r6 = MEM_BU(ctx->r24, 0X8);
    // 0x80050A34: sb          $t1, 0x9($t8)
    MEM_B(0X9, ctx->r24) = ctx->r9;
    // 0x80050A38: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x80050A3C: bne         $a2, $zero, L_80050A64
    if (ctx->r6 != 0) {
        // 0x80050A40: sw          $t7, 0x0($t8)
        MEM_W(0X0, ctx->r24) = ctx->r15;
            goto L_80050A64;
    }
    // 0x80050A40: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80050A44: lw          $t8, 0x10($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X10);
    // 0x80050A48: lw          $a2, 0xC($t0)
    ctx->r6 = MEM_W(ctx->r8, 0XC);
    // 0x80050A4C: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x80050A50: beq         $a2, $zero, L_80050A7C
    if (ctx->r6 == 0) {
        // 0x80050A54: sw          $t9, 0x10($t0)
        MEM_W(0X10, ctx->r8) = ctx->r25;
            goto L_80050A7C;
    }
    // 0x80050A54: sw          $t9, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r25;
    // 0x80050A58: addu        $t6, $a2, $a1
    ctx->r14 = ADD32(ctx->r6, ctx->r5);
    // 0x80050A5C: b           L_80050A7C
    // 0x80050A60: sw          $t6, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r14;
        goto L_80050A7C;
    // 0x80050A60: sw          $t6, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r14;
L_80050A64:
    // 0x80050A64: bnel        $t2, $a2, L_80050A80
    if (ctx->r10 != ctx->r6) {
        // 0x80050A68: lh          $t8, 0xE($a0)
        ctx->r24 = MEM_H(ctx->r4, 0XE);
            goto L_80050A80;
    }
    goto skip_2;
    // 0x80050A68: lh          $t8, 0xE($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE);
    skip_2:
    // 0x80050A6C: lw          $a2, 0xC($t0)
    ctx->r6 = MEM_W(ctx->r8, 0XC);
    // 0x80050A70: beq         $a2, $zero, L_80050A7C
    if (ctx->r6 == 0) {
        // 0x80050A74: addu        $t7, $a2, $a1
        ctx->r15 = ADD32(ctx->r6, ctx->r5);
            goto L_80050A7C;
    }
    // 0x80050A74: addu        $t7, $a2, $a1
    ctx->r15 = ADD32(ctx->r6, ctx->r5);
    // 0x80050A78: sw          $t7, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r15;
L_80050A7C:
    // 0x80050A7C: lh          $t8, 0xE($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE);
L_80050A80:
    // 0x80050A80: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050A84: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80050A88: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80050A8C: bnel        $at, $zero, L_800509DC
    if (ctx->r1 != 0) {
        // 0x80050A90: lw          $t8, 0x10($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X10);
            goto L_800509DC;
    }
    goto skip_3;
    // 0x80050A90: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
    skip_3:
L_80050A94:
    // 0x80050A94: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80050A9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80050A9C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80050AA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80050AA4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80050AA8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80050AAC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80050AB0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80050AB4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80050AB8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80050ABC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80050AC0: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x80050AC4: addiu       $at, $zero, 0x4231
    ctx->r1 = ADD32(0, 0X4231);
    // 0x80050AC8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80050ACC: bne         $t6, $at, L_80050B88
    if (ctx->r14 != ctx->r1) {
        // 0x80050AD0: or          $s1, $a1, $zero
        ctx->r17 = ctx->r5 | 0;
            goto L_80050B88;
    }
    // 0x80050AD0: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80050AD4: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    // 0x80050AD8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80050ADC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80050AE0: blez        $t7, L_80050B88
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80050AE4: addiu       $s4, $zero, 0x1
        ctx->r20 = ADD32(0, 0X1);
            goto L_80050B88;
    }
    // 0x80050AE4: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80050AE8: lw          $t8, 0x4($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X4);
L_80050AEC:
    // 0x80050AEC: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x80050AF0: beq         $t9, $zero, L_80050B70
    if (ctx->r25 == 0) {
        // 0x80050AF4: sw          $t9, 0x4($s2)
        MEM_W(0X4, ctx->r18) = ctx->r25;
            goto L_80050B70;
    }
    // 0x80050AF4: sw          $t9, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r25;
    // 0x80050AF8: lbu         $t6, 0x2($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X2);
    // 0x80050AFC: or          $t5, $t9, $zero
    ctx->r13 = ctx->r25 | 0;
    // 0x80050B00: bnel        $t6, $zero, L_80050B74
    if (ctx->r14 != 0) {
        // 0x80050B04: lh          $t8, 0x2($s0)
        ctx->r24 = MEM_H(ctx->r16, 0X2);
            goto L_80050B74;
    }
    goto skip_0;
    // 0x80050B04: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    skip_0:
    // 0x80050B08: lw          $v0, 0x8($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X8);
    // 0x80050B0C: sb          $s4, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r20;
    // 0x80050B10: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80050B14: beq         $v0, $zero, L_80050B2C
    if (ctx->r2 == 0) {
        // 0x80050B18: addu        $a0, $v0, $s0
        ctx->r4 = ADD32(ctx->r2, ctx->r16);
            goto L_80050B2C;
    }
    // 0x80050B18: addu        $a0, $v0, $s0
    ctx->r4 = ADD32(ctx->r2, ctx->r16);
    // 0x80050B1C: sw          $a0, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r4;
    // 0x80050B20: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80050B24: jal         0x800509B0
    // 0x80050B28: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_800509B0(rdram, ctx);
        goto after_0;
    // 0x80050B28: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_0:
L_80050B2C:
    // 0x80050B2C: lh          $t8, 0x0($t5)
    ctx->r24 = MEM_H(ctx->r13, 0X0);
    // 0x80050B30: or          $t3, $t5, $zero
    ctx->r11 = ctx->r13 | 0;
    // 0x80050B34: blezl       $t8, L_80050B74
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80050B38: lh          $t8, 0x2($s0)
        ctx->r24 = MEM_H(ctx->r16, 0X2);
            goto L_80050B74;
    }
    goto skip_1;
    // 0x80050B38: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    skip_1:
    // 0x80050B3C: lw          $t9, 0xC($t3)
    ctx->r25 = MEM_W(ctx->r11, 0XC);
L_80050B40:
    // 0x80050B40: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80050B44: addu        $a0, $t9, $s0
    ctx->r4 = ADD32(ctx->r25, ctx->r16);
    // 0x80050B48: beq         $a0, $zero, L_80050B58
    if (ctx->r4 == 0) {
        // 0x80050B4C: sw          $a0, 0xC($t3)
        MEM_W(0XC, ctx->r11) = ctx->r4;
            goto L_80050B58;
    }
    // 0x80050B4C: sw          $a0, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r4;
    // 0x80050B50: jal         0x800509B0
    // 0x80050B54: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_800509B0(rdram, ctx);
        goto after_1;
    // 0x80050B54: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_1:
L_80050B58:
    // 0x80050B58: lh          $t7, 0x0($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X0);
    // 0x80050B5C: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x80050B60: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x80050B64: slt         $at, $t4, $t7
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80050B68: bnel        $at, $zero, L_80050B40
    if (ctx->r1 != 0) {
        // 0x80050B6C: lw          $t9, 0xC($t3)
        ctx->r25 = MEM_W(ctx->r11, 0XC);
            goto L_80050B40;
    }
    goto skip_2;
    // 0x80050B6C: lw          $t9, 0xC($t3)
    ctx->r25 = MEM_W(ctx->r11, 0XC);
    skip_2:
L_80050B70:
    // 0x80050B70: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
L_80050B74:
    // 0x80050B74: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80050B78: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80050B7C: slt         $at, $s3, $t8
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80050B80: bnel        $at, $zero, L_80050AEC
    if (ctx->r1 != 0) {
        // 0x80050B84: lw          $t8, 0x4($s2)
        ctx->r24 = MEM_W(ctx->r18, 0X4);
            goto L_80050AEC;
    }
    goto skip_3;
    // 0x80050B84: lw          $t8, 0x4($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X4);
    skip_3:
L_80050B88:
    // 0x80050B88: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80050B8C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80050B90: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80050B94: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80050B98: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80050B9C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80050BA0: jr          $ra
    // 0x80050BA4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    TRACE_RETURN()
    return;
    // 0x80050BA4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80050BA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80050BA8: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x80050BAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80050BB0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80050BB4: blez        $t6, L_80050BE0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80050BB8: nop
    
            goto L_80050BE0;
    }
    // 0x80050BB8: nop

    // 0x80050BBC: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
L_80050BC0:
    // 0x80050BC0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050BC4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80050BC8: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x80050BCC: sw          $t8, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r24;
    // 0x80050BD0: lh          $t9, 0x2($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X2);
    // 0x80050BD4: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80050BD8: bnel        $at, $zero, L_80050BC0
    if (ctx->r1 != 0) {
        // 0x80050BDC: lw          $t7, 0x4($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X4);
            goto L_80050BC0;
    }
    goto skip_0;
    // 0x80050BDC: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    skip_0:
L_80050BE0:
    // 0x80050BE0: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80050BF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80050BF0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80050BF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80050BF8: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x80050BFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80050C00: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80050C04: bnel        $t6, $at, L_80050C54
    if (ctx->r14 != ctx->r1) {
        // 0x80050C08: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80050C54;
    }
    goto skip_0;
    // 0x80050C08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80050C0C: lw          $a0, 0x18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X18);
    // 0x80050C10: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80050C14: beql        $a0, $zero, L_80050C54
    if (ctx->r4 == 0) {
        // 0x80050C18: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80050C54;
    }
    goto skip_1;
    // 0x80050C18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80050C1C: jal         0x8005041C
    // 0x80050C20: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    func_8005041C(rdram, ctx);
        goto after_0;
    // 0x80050C20: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_0:
    // 0x80050C24: beq         $v0, $zero, L_80050C50
    if (ctx->r2 == 0) {
        // 0x80050C28: lw          $a3, 0x30($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X30);
            goto L_80050C50;
    }
    // 0x80050C28: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80050C2C: sh          $zero, 0x20($sp)
    MEM_H(0X20, ctx->r29) = 0;
    // 0x80050C30: lw          $t7, 0x24($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X24);
    // 0x80050C34: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80050C38: addiu       $a0, $a3, 0x48
    ctx->r4 = ADD32(ctx->r7, 0X48);
    // 0x80050C3C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80050C40: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80050C44: mflo        $a2
    ctx->r6 = lo;
    // 0x80050C48: jal         0x8005702C
    // 0x80050C4C: nop

    func_8005702C(rdram, ctx);
        goto after_1;
    // 0x80050C4C: nop

    after_1:
L_80050C50:
    // 0x80050C50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80050C54:
    // 0x80050C54: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80050C58: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80050C60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80050C60: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x80050C64: addiu       $t8, $zero, 0x1E8
    ctx->r24 = ADD32(0, 0X1E8);
    // 0x80050C68: beql        $v0, $zero, L_80050C8C
    if (ctx->r2 == 0) {
        // 0x80050C6C: sw          $t8, 0x24($a0)
        MEM_W(0X24, ctx->r4) = ctx->r24;
            goto L_80050C8C;
    }
    goto skip_0;
    // 0x80050C6C: sw          $t8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r24;
    skip_0:
    // 0x80050C70: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80050C74: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80050C78: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80050C7C: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x80050C80: jr          $ra
    // 0x80050C84: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
    TRACE_RETURN()
    return;
    // 0x80050C84: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
    // 0x80050C88: sw          $t8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r24;
L_80050C8C:
    // 0x80050C8C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80050C94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80050C94: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80050C9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80050C9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80050CA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80050CA4: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x80050CA8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80050CAC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80050CB0: bne         $t6, $at, L_80050E5C
    if (ctx->r14 != ctx->r1) {
        // 0x80050CB4: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_80050E5C;
    }
    // 0x80050CB4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80050CB8: lbu         $t7, 0x9($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X9);
    // 0x80050CBC: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x80050CC0: addiu       $v0, $a1, 0x4
    ctx->r2 = ADD32(ctx->r5, 0X4);
    // 0x80050CC4: bnel        $t7, $at, L_80050E60
    if (ctx->r15 != ctx->r1) {
        // 0x80050CC8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80050E60;
    }
    goto skip_0;
    // 0x80050CC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80050CCC: lbu         $t6, 0x8($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X8);
    // 0x80050CD0: lbu         $t8, 0x7($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X7);
    // 0x80050CD4: lw          $fp, 0x24($s7)
    ctx->r30 = MEM_W(ctx->r23, 0X24);
    // 0x80050CD8: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x80050CDC: lbu         $t6, 0x9($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X9);
    // 0x80050CE0: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80050CE4: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x80050CE8: or          $v1, $t8, $t6
    ctx->r3 = ctx->r24 | ctx->r14;
    // 0x80050CEC: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80050CF0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80050CF4: jal         0x80050C60
    // 0x80050CF8: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_80050C60(rdram, ctx);
        goto after_0;
    // 0x80050CF8: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_0:
    // 0x80050CFC: lw          $s1, 0x50($s7)
    ctx->r17 = MEM_W(ctx->r23, 0X50);
    // 0x80050D00: beq         $s1, $zero, L_80050D78
    if (ctx->r17 == 0) {
        // 0x80050D04: nop
    
            goto L_80050D78;
    }
    // 0x80050D04: nop

    // 0x80050D08: addiu       $s4, $zero, 0x15
    ctx->r20 = ADD32(0, 0X15);
L_80050D0C:
    // 0x80050D0C: lh          $t7, 0xC($s1)
    ctx->r15 = MEM_H(ctx->r17, 0XC);
    // 0x80050D10: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x80050D14: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x80050D18: bne         $s4, $t7, L_80050D70
    if (ctx->r20 != ctx->r15) {
        // 0x80050D1C: addu        $s0, $s0, $t9
        ctx->r16 = ADD32(ctx->r16, ctx->r25);
            goto L_80050D70;
    }
    // 0x80050D1C: addu        $s0, $s0, $t9
    ctx->r16 = ADD32(ctx->r16, ctx->r25);
    // 0x80050D20: jal         0x800526C0
    // 0x80050D24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800526C0(rdram, ctx);
        goto after_1;
    // 0x80050D24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80050D28: beql        $s3, $zero, L_80050D48
    if (ctx->r19 == 0) {
        // 0x80050D2C: sw          $zero, 0x0($s1)
        MEM_W(0X0, ctx->r17) = 0;
            goto L_80050D48;
    }
    goto skip_1;
    // 0x80050D2C: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    skip_1:
    // 0x80050D30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80050D34: jal         0x800526F0
    // 0x80050D38: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800526F0(rdram, ctx);
        goto after_2;
    // 0x80050D38: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_2:
    // 0x80050D3C: b           L_80050D50
    // 0x80050D40: nop

        goto L_80050D50;
    // 0x80050D40: nop

    // 0x80050D44: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_80050D48:
    // 0x80050D48: sw          $zero, 0x4($s1)
    MEM_W(0X4, ctx->r17) = 0;
    // 0x80050D4C: or          $s3, $s1, $zero
    ctx->r19 = ctx->r17 | 0;
L_80050D50:
    // 0x80050D50: beq         $s2, $zero, L_80050D6C
    if (ctx->r18 == 0) {
        // 0x80050D54: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_80050D6C;
    }
    // 0x80050D54: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80050D58: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x80050D5C: lw          $t8, 0x8($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X8);
    // 0x80050D60: subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // 0x80050D64: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x80050D68: sw          $t6, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r14;
L_80050D6C:
    // 0x80050D6C: sw          $v1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r3;
L_80050D70:
    // 0x80050D70: bne         $s2, $zero, L_80050D0C
    if (ctx->r18 != 0) {
        // 0x80050D74: or          $s1, $s2, $zero
        ctx->r17 = ctx->r18 | 0;
            goto L_80050D0C;
    }
    // 0x80050D74: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
L_80050D78:
    // 0x80050D78: beq         $s3, $zero, L_80050E5C
    if (ctx->r19 == 0) {
        // 0x80050D7C: or          $s1, $s3, $zero
        ctx->r17 = ctx->r19 | 0;
            goto L_80050E5C;
    }
    // 0x80050D7C: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
    // 0x80050D80: addiu       $s4, $s7, 0x48
    ctx->r20 = ADD32(ctx->r23, 0X48);
    // 0x80050D84: addiu       $s5, $s4, 0x8
    ctx->r21 = ADD32(ctx->r20, 0X8);
    // 0x80050D88: addiu       $s6, $zero, -0x8
    ctx->r22 = ADD32(0, -0X8);
L_80050D8C:
    // 0x80050D8C: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x80050D90: lw          $t7, 0x24($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X24);
    // 0x80050D94: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x80050D98: div         $zero, $t9, $fp
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r30))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r30)));
    // 0x80050D9C: mflo        $v0
    ctx->r2 = lo;
    // 0x80050DA0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80050DA4: bne         $fp, $zero, L_80050DB0
    if (ctx->r30 != 0) {
        // 0x80050DA8: nop
    
            goto L_80050DB0;
    }
    // 0x80050DA8: nop

    // 0x80050DAC: break       7
    do_break(2147814828);
L_80050DB0:
    // 0x80050DB0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80050DB4: bne         $fp, $at, L_80050DC8
    if (ctx->r30 != ctx->r1) {
        // 0x80050DB8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80050DC8;
    }
    // 0x80050DB8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80050DBC: bne         $t9, $at, L_80050DC8
    if (ctx->r25 != ctx->r1) {
        // 0x80050DC0: nop
    
            goto L_80050DC8;
    }
    // 0x80050DC0: nop

    // 0x80050DC4: break       6
    do_break(2147814852);
L_80050DC8:
    // 0x80050DC8: multu       $t7, $v0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80050DCC: or          $s0, $s5, $zero
    ctx->r16 = ctx->r21 | 0;
    // 0x80050DD0: mflo        $t8
    ctx->r24 = lo;
    // 0x80050DD4: sw          $t8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r24;
    // 0x80050DD8: jal         0x80059290
    // 0x80050DDC: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x80050DDC: nop

    after_3:
    // 0x80050DE0: beq         $s4, $s6, L_80050E4C
    if (ctx->r20 == ctx->r22) {
        // 0x80050DE4: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80050E4C;
    }
    // 0x80050DE4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80050DE8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_80050DEC:
    // 0x80050DEC: bnel        $a0, $zero, L_80050E0C
    if (ctx->r4 != 0) {
        // 0x80050DF0: lw          $v0, 0x8($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X8);
            goto L_80050E0C;
    }
    goto skip_2;
    // 0x80050DF0: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    skip_2:
    // 0x80050DF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80050DF8: jal         0x800526F0
    // 0x80050DFC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800526F0(rdram, ctx);
        goto after_4;
    // 0x80050DFC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x80050E00: b           L_80050E4C
    // 0x80050E04: nop

        goto L_80050E4C;
    // 0x80050E04: nop

    // 0x80050E08: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
L_80050E0C:
    // 0x80050E0C: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x80050E10: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80050E14: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80050E18: beq         $at, $zero, L_80050E3C
    if (ctx->r1 == 0) {
        // 0x80050E1C: subu        $t9, $v0, $v1
        ctx->r25 = SUB32(ctx->r2, ctx->r3);
            goto L_80050E3C;
    }
    // 0x80050E1C: subu        $t9, $v0, $v1
    ctx->r25 = SUB32(ctx->r2, ctx->r3);
    // 0x80050E20: subu        $t6, $v1, $v0
    ctx->r14 = SUB32(ctx->r3, ctx->r2);
    // 0x80050E24: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x80050E28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80050E2C: jal         0x800526F0
    // 0x80050E30: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800526F0(rdram, ctx);
        goto after_5;
    // 0x80050E30: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80050E34: b           L_80050E4C
    // 0x80050E38: nop

        goto L_80050E4C;
    // 0x80050E38: nop

L_80050E3C:
    // 0x80050E3C: sw          $t9, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r25;
    // 0x80050E40: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x80050E44: bnel        $s0, $zero, L_80050DEC
    if (ctx->r16 != 0) {
        // 0x80050E48: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_80050DEC;
    }
    goto skip_3;
    // 0x80050E48: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_3:
L_80050E4C:
    // 0x80050E4C: jal         0x80059290
    // 0x80050E50: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    osSetIntMask_recomp(rdram, ctx);
        goto after_6;
    // 0x80050E50: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_6:
    // 0x80050E54: bne         $s2, $zero, L_80050D8C
    if (ctx->r18 != 0) {
        // 0x80050E58: or          $s1, $s2, $zero
        ctx->r17 = ctx->r18 | 0;
            goto L_80050D8C;
    }
    // 0x80050E58: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
L_80050E5C:
    // 0x80050E5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80050E60:
    // 0x80050E60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80050E64: jr          $ra
    TRACE_RETURN()
    return;
;}
