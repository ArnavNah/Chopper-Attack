#include "recomp.h"
#include "trace.h"
#include "funcs.h"

RECOMP_FUNC void func_800103D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800103D4: addiu       $sp, $sp, -0x170
    ctx->r29 = ADD32(ctx->r29, -0X170);
    // 0x800103D8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800103DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800103E0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800103E4: sw          $a0, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->r4;
    // 0x800103E8: sh          $t6, 0x8E($sp)
    MEM_H(0X8E, ctx->r29) = ctx->r14;
    // 0x800103EC: sh          $zero, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = 0;
    // 0x800103F0: jal         0x80010370
    // 0x800103F4: swc1        $f4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f4.u32l;
    func_80010370(rdram, ctx);
        goto after_0;
    // 0x800103F4: swc1        $f4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800103F8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800103FC: sw          $zero, -0x6C00($at)
    MEM_W(-0X6C00, ctx->r1) = 0;
    // 0x80010400: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80010404: sw          $zero, -0x6C04($at)
    MEM_W(-0X6C04, ctx->r1) = 0;
    // 0x80010408: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001040C: sh          $zero, -0x6C14($at)
    MEM_H(-0X6C14, ctx->r1) = 0;
    // 0x80010410: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80010414: lwc1        $f6, 0x6010($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6010);
    // 0x80010418: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001041C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80010420: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80010424: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80010428: addiu       $t0, $t0, -0x6C20
    ctx->r8 = ADD32(ctx->r8, -0X6C20);
    // 0x8001042C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80010430: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80010434: addiu       $v1, $v1, -0x6C50
    ctx->r3 = ADD32(ctx->r3, -0X6C50);
    // 0x80010438: addiu       $v0, $v0, -0x6C10
    ctx->r2 = ADD32(ctx->r2, -0X6C10);
    // 0x8001043C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80010440: addiu       $a2, $sp, 0xE4
    ctx->r6 = ADD32(ctx->r29, 0XE4);
    // 0x80010444: addiu       $a1, $sp, 0xD8
    ctx->r5 = ADD32(ctx->r29, 0XD8);
    // 0x80010448: addiu       $a3, $sp, 0xE4
    ctx->r7 = ADD32(ctx->r29, 0XE4);
    // 0x8001044C: swc1        $f6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f6.u32l;
    // 0x80010450: swc1        $f0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f0.u32l;
    // 0x80010454: swc1        $f0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f0.u32l;
    // 0x80010458: swc1        $f8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f8.u32l;
L_8001045C:
    // 0x8001045C: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80010460: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80010464: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80010468: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001046C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80010470: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80010474: swc1        $f0, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->f0.u32l;
    // 0x80010478: swc1        $f0, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f0.u32l;
    // 0x8001047C: bne         $a1, $a3, L_8001045C
    if (ctx->r5 != ctx->r7) {
        // 0x80010480: swc1        $f10, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
            goto L_8001045C;
    }
    // 0x80010480: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x80010484: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80010488: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001048C: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x80010490: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80010494: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80010498: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001049C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800104A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800104A4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800104A8: swc1        $f0, -0x6BF8($at)
    MEM_W(-0X6BF8, ctx->r1) = ctx->f0.u32l;
    // 0x800104AC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800104B0: swc1        $f0, -0x6BF4($at)
    MEM_W(-0X6BF4, ctx->r1) = ctx->f0.u32l;
    // 0x800104B4: swc1        $f4, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f4.u32l;
    // 0x800104B8: swc1        $f6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f6.u32l;
    // 0x800104BC: swc1        $f8, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f8.u32l;
    // 0x800104C0: swc1        $f10, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f10.u32l;
    // 0x800104C4: lw          $t7, 0x170($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X170);
L_800104C8:
    // 0x800104C8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800104CC: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x800104D0: bnel        $v0, $at, L_800104F0
    if (ctx->r2 != ctx->r1) {
        // 0x800104D4: addiu       $at, $zero, -0x2
        ctx->r1 = ADD32(0, -0X2);
            goto L_800104F0;
    }
    goto skip_0;
    // 0x800104D4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    skip_0:
    // 0x800104D8: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
L_800104DC:
    // 0x800104DC: jal         0x8000798C
    // 0x800104E0: nop

    func_8000798C(rdram, ctx);
        goto after_1;
    // 0x800104E0: nop

    after_1:
    // 0x800104E4: b           L_800104DC
    // 0x800104E8: nop

        goto L_800104DC;
    // 0x800104E8: nop

    // 0x800104EC: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
L_800104F0:
    // 0x800104F0: bne         $v0, $at, L_8001051C
    if (ctx->r2 != ctx->r1) {
        // 0x800104F4: addiu       $at, $zero, -0x2
        ctx->r1 = ADD32(0, -0X2);
            goto L_8001051C;
    }
    // 0x800104F4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800104F8: bne         $v0, $at, L_8001051C
    if (ctx->r2 != ctx->r1) {
        // 0x800104FC: nop
    
            goto L_8001051C;
    }
    // 0x800104FC: nop

L_80010500:
    // 0x80010500: jal         0x8000798C
    // 0x80010504: nop

    func_8000798C(rdram, ctx);
        goto after_2;
    // 0x80010504: nop

    after_2:
    // 0x80010508: lw          $t8, 0x170($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X170);
    // 0x8001050C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80010510: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80010514: beq         $t9, $at, L_80010500
    if (ctx->r25 == ctx->r1) {
        // 0x80010518: nop
    
            goto L_80010500;
    }
    // 0x80010518: nop

L_8001051C:
    // 0x8001051C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80010520: lw          $v0, -0x6C00($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6C00);
    // 0x80010524: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80010528: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8001052C: beq         $v0, $zero, L_80010544
    if (ctx->r2 == 0) {
        // 0x80010530: lui         $t2, 0x8013
        ctx->r10 = S32(0X8013 << 16);
            goto L_80010544;
    }
    // 0x80010530: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80010534: sw          $v0, -0x6C04($at)
    MEM_W(-0X6C04, ctx->r1) = ctx->r2;
    // 0x80010538: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001053C: sw          $zero, -0x6C00($at)
    MEM_W(-0X6C00, ctx->r1) = 0;
    // 0x80010540: sw          $t1, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r9;
L_80010544:
    // 0x80010544: lw          $t2, -0x6C04($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X6C04);
    // 0x80010548: sltiu       $at, $t2, 0xB
    ctx->r1 = ctx->r10 < 0XB ? 1 : 0;
    // 0x8001054C: beq         $at, $zero, L_8001142C
    if (ctx->r1 == 0) {
        // 0x80010550: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_8001142C;
    }
    // 0x80010550: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80010554: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80010558: addu        $at, $at, $t2
    gpr jr_addend_80010560 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8001055C: lw          $t2, 0x6014($at)
    ctx->r10 = ADD32(ctx->r1, 0X6014);
    // 0x80010560: jr          $t2
    // 0x80010564: nop

    switch (jr_addend_80010560 >> 2) {
        case 0: goto L_8001142C; break;
        case 1: goto L_80010684; break;
        case 2: goto L_80010B9C; break;
        case 3: goto L_80010DB8; break;
        case 4: goto L_800110E0; break;
        case 5: goto L_80011268; break;
        case 6: goto L_8001142C; break;
        case 7: goto L_8001142C; break;
        case 8: goto L_8001142C; break;
        case 9: goto L_8001142C; break;
        case 10: goto L_80010568; break;
        default: switch_error(__func__, 0x80010560, 0x80076014);
    }
    // 0x80010564: nop

L_80010568:
    // 0x80010568: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8001056C: lhu         $v0, -0x2E5C($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2E5C);
    // 0x80010570: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80010574: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80010578: andi        $t3, $v0, 0x4
    ctx->r11 = ctx->r2 & 0X4;
    // 0x8001057C: sh          $zero, 0x8E($sp)
    MEM_H(0X8E, ctx->r29) = 0;
    // 0x80010580: beq         $t3, $zero, L_800105C0
    if (ctx->r11 == 0) {
        // 0x80010584: sh          $zero, -0x6C14($at)
        MEM_H(-0X6C14, ctx->r1) = 0;
            goto L_800105C0;
    }
    // 0x80010584: sh          $zero, -0x6C14($at)
    MEM_H(-0X6C14, ctx->r1) = 0;
    // 0x80010588: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8001058C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80010590: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80010594: lui         $at, 0x457A
    ctx->r1 = S32(0X457A << 16);
    // 0x80010598: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001059C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800105A0: lui         $at, 0x457A
    ctx->r1 = S32(0X457A << 16);
    // 0x800105A4: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x800105A8: swc1        $f8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f8.u32l;
    // 0x800105AC: bc1fl       L_800105C4
    if (!c1cs) {
        // 0x800105B0: andi        $t4, $v0, 0x8
        ctx->r12 = ctx->r2 & 0X8;
            goto L_800105C4;
    }
    goto skip_1;
    // 0x800105B0: andi        $t4, $v0, 0x8
    ctx->r12 = ctx->r2 & 0X8;
    skip_1:
    // 0x800105B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800105B8: nop

    // 0x800105BC: swc1        $f4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f4.u32l;
L_800105C0:
    // 0x800105C0: andi        $t4, $v0, 0x8
    ctx->r12 = ctx->r2 & 0X8;
L_800105C4:
    // 0x800105C4: beq         $t4, $zero, L_80010604
    if (ctx->r12 == 0) {
        // 0x800105C8: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_80010604;
    }
    // 0x800105C8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800105CC: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x800105D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800105D4: lwc1        $f6, 0x84($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800105D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800105DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800105E0: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800105E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800105E8: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x800105EC: swc1        $f8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f8.u32l;
    // 0x800105F0: bc1f        L_80010604
    if (!c1cs) {
        // 0x800105F4: nop
    
            goto L_80010604;
    }
    // 0x800105F4: nop

    // 0x800105F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800105FC: nop

    // 0x80010600: swc1        $f6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f6.u32l;
L_80010604:
    // 0x80010604: lhu         $v1, -0x2E5A($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2E5A);
    // 0x80010608: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8001060C: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x80010610: andi        $t5, $v1, 0xC
    ctx->r13 = ctx->r3 & 0XC;
    // 0x80010614: bne         $t5, $at, L_8001062C
    if (ctx->r13 != ctx->r1) {
        // 0x80010618: andi        $t7, $v0, 0x2
        ctx->r15 = ctx->r2 & 0X2;
            goto L_8001062C;
    }
    // 0x80010618: andi        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 & 0X2;
    // 0x8001061C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80010620: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80010624: nop

    // 0x80010628: swc1        $f10, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f10.u32l;
L_8001062C:
    // 0x8001062C: beq         $t6, $zero, L_80010648
    if (ctx->r14 == 0) {
        // 0x80010630: andi        $t8, $v1, 0x3
        ctx->r24 = ctx->r3 & 0X3;
            goto L_80010648;
    }
    // 0x80010630: andi        $t8, $v1, 0x3
    ctx->r24 = ctx->r3 & 0X3;
    // 0x80010634: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80010638: lwc1        $f4, 0x6040($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6040);
    // 0x8001063C: lwc1        $f8, 0xA8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80010640: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80010644: swc1        $f6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f6.u32l;
L_80010648:
    // 0x80010648: beq         $t7, $zero, L_80010664
    if (ctx->r15 == 0) {
        // 0x8001064C: lui         $a2, 0x8013
        ctx->r6 = S32(0X8013 << 16);
            goto L_80010664;
    }
    // 0x8001064C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80010650: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80010654: lwc1        $f8, 0x6044($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6044);
    // 0x80010658: lwc1        $f10, 0xA8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8001065C: sub.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80010660: swc1        $f4, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f4.u32l;
L_80010664:
    // 0x80010664: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80010668: bne         $t8, $at, L_8001067C
    if (ctx->r24 != ctx->r1) {
        // 0x8001066C: addiu       $a0, $sp, 0xA8
        ctx->r4 = ADD32(ctx->r29, 0XA8);
            goto L_8001067C;
    }
    // 0x8001066C: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    // 0x80010670: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80010674: nop

    // 0x80010678: swc1        $f6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f6.u32l;
L_8001067C:
    // 0x8001067C: b           L_80010824
    // 0x80010680: lw          $a2, -0x6BFC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X6BFC);
        goto L_80010824;
    // 0x80010680: lw          $a2, -0x6BFC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X6BFC);
L_80010684:
    // 0x80010684: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80010688: lh          $t9, -0x6C14($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X6C14);
    // 0x8001068C: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x80010690: beql        $t9, $zero, L_80010700
    if (ctx->r25 == 0) {
        // 0x80010694: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_80010700;
    }
    goto skip_2;
    // 0x80010694: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    skip_2:
    // 0x80010698: jal         0x80040764
    // 0x8001069C: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    func_80040764(rdram, ctx);
        goto after_3;
    // 0x8001069C: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_3:
    // 0x800106A0: beq         $v0, $zero, L_800106F8
    if (ctx->r2 == 0) {
        // 0x800106A4: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_800106F8;
    }
    // 0x800106A4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800106A8: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    // 0x800106AC: jal         0x80044480
    // 0x800106B0: sh          $zero, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = 0;
    func_80044480(rdram, ctx);
        goto after_4;
    // 0x800106B0: sh          $zero, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = 0;
    after_4:
    // 0x800106B4: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x800106B8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800106BC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800106C0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800106C4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800106C8: sw          $t1, -0x6C04($at)
    MEM_W(-0X6C04, ctx->r1) = ctx->r9;
    // 0x800106CC: addiu       $v0, $v0, -0x6C14
    ctx->r2 = ADD32(ctx->r2, -0X6C14);
    // 0x800106D0: addiu       $v1, $v1, -0x6C20
    ctx->r3 = ADD32(ctx->r3, -0X6C20);
    // 0x800106D4: addiu       $a0, $a0, -0x6BF0
    ctx->r4 = ADD32(ctx->r4, -0X6BF0);
L_800106D8:
    // 0x800106D8: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800106DC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800106E0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800106E4: bne         $v1, $v0, L_800106D8
    if (ctx->r3 != ctx->r2) {
        // 0x800106E8: swc1        $f10, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = ctx->f10.u32l;
            goto L_800106D8;
    }
    // 0x800106E8: swc1        $f10, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f10.u32l;
    // 0x800106EC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800106F0: b           L_80010E28
    // 0x800106F4: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
        goto L_80010E28;
    // 0x800106F4: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
L_800106F8:
    // 0x800106F8: sh          $zero, -0x6C14($at)
    MEM_H(-0X6C14, ctx->r1) = 0;
    // 0x800106FC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
L_80010700:
    // 0x80010700: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80010704: nop

L_80010708:
    // 0x80010708: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001070C: lw          $v0, -0x6BE0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6BE0);
    // 0x80010710: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x80010714: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80010718: andi        $t2, $v0, 0x80
    ctx->r10 = ctx->r2 & 0X80;
    // 0x8001071C: beq         $t2, $zero, L_80010750
    if (ctx->r10 == 0) {
        // 0x80010720: andi        $t3, $v0, 0x4
        ctx->r11 = ctx->r2 & 0X4;
            goto L_80010750;
    }
    // 0x80010720: andi        $t3, $v0, 0x4
    ctx->r11 = ctx->r2 & 0X4;
    // 0x80010724: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80010728: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001072C: lwc1        $f10, 0x6048($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6048);
    // 0x80010730: lwc1        $f6, 0xA8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80010734: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80010738: lw          $a2, -0x6BFC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X6BFC);
    // 0x8001073C: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80010740: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    // 0x80010744: swc1        $f4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f4.u32l;
    // 0x80010748: b           L_80010824
    // 0x8001074C: swc1        $f8, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f8.u32l;
        goto L_80010824;
    // 0x8001074C: swc1        $f8, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f8.u32l;
L_80010750:
    // 0x80010750: bne         $t3, $zero, L_80010818
    if (ctx->r11 != 0) {
        // 0x80010754: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_80010818;
    }
    // 0x80010754: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80010758: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8001075C: lh          $t4, 0x6ACC($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X6ACC);
    // 0x80010760: lhu         $v1, -0x2E5A($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2E5A);
    // 0x80010764: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    // 0x80010768: beq         $t4, $zero, L_80010788
    if (ctx->r12 == 0) {
        // 0x8001076C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80010788;
    }
    // 0x8001076C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80010770: sra         $t7, $v1, 8
    ctx->r15 = S32(SIGNED(ctx->r3) >> 8);
    // 0x80010774: andi        $t6, $v0, 0xFFF0
    ctx->r14 = ctx->r2 & 0XFFF0;
    // 0x80010778: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x8001077C: or          $v0, $t6, $t8
    ctx->r2 = ctx->r14 | ctx->r24;
    // 0x80010780: andi        $t9, $v0, 0xFFFF
    ctx->r25 = ctx->r2 & 0XFFFF;
    // 0x80010784: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80010788:
    // 0x80010788: andi        $t1, $v0, 0x4
    ctx->r9 = ctx->r2 & 0X4;
    // 0x8001078C: beq         $t1, $zero, L_80010818
    if (ctx->r9 == 0) {
        // 0x80010790: nop
    
            goto L_80010818;
    }
    // 0x80010790: nop

    // 0x80010794: jal         0x80044480
    // 0x80010798: swc1        $f2, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f2.u32l;
    func_80044480(rdram, ctx);
        goto after_5;
    // 0x80010798: swc1        $f2, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f2.u32l;
    after_5:
    // 0x8001079C: lh          $t2, 0x8E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X8E);
    // 0x800107A0: lwc1        $f2, 0xB4($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800107A4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800107A8: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x800107AC: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800107B0: slti        $at, $t5, 0x3
    ctx->r1 = SIGNED(ctx->r13) < 0X3 ? 1 : 0;
    // 0x800107B4: bne         $at, $zero, L_800107C0
    if (ctx->r1 != 0) {
        // 0x800107B8: sh          $t3, 0x8E($sp)
        MEM_H(0X8E, ctx->r29) = ctx->r11;
            goto L_800107C0;
    }
    // 0x800107B8: sh          $t3, 0x8E($sp)
    MEM_H(0X8E, ctx->r29) = ctx->r11;
    // 0x800107BC: sh          $zero, 0x8E($sp)
    MEM_H(0X8E, ctx->r29) = 0;
L_800107C0:
    // 0x800107C0: lh          $t6, 0x8E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X8E);
    // 0x800107C4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800107C8: beql        $t6, $zero, L_800107F0
    if (ctx->r14 == 0) {
        // 0x800107CC: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_800107F0;
    }
    goto skip_3;
    // 0x800107CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_3:
    // 0x800107D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800107D4: beq         $t6, $at, L_800107F8
    if (ctx->r14 == ctx->r1) {
        // 0x800107D8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800107F8;
    }
    // 0x800107D8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800107DC: beql        $t6, $at, L_8001080C
    if (ctx->r14 == ctx->r1) {
        // 0x800107E0: lui         $at, 0x4316
        ctx->r1 = S32(0X4316 << 16);
            goto L_8001080C;
    }
    goto skip_4;
    // 0x800107E0: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    skip_4:
    // 0x800107E4: b           L_80010818
    // 0x800107E8: nop

        goto L_80010818;
    // 0x800107E8: nop

    // 0x800107EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_800107F0:
    // 0x800107F0: b           L_80010818
    // 0x800107F4: swc1        $f4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f4.u32l;
        goto L_80010818;
    // 0x800107F4: swc1        $f4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f4.u32l;
L_800107F8:
    // 0x800107F8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800107FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80010800: b           L_80010818
    // 0x80010804: swc1        $f6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f6.u32l;
        goto L_80010818;
    // 0x80010804: swc1        $f6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f6.u32l;
    // 0x80010808: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
L_8001080C:
    // 0x8001080C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80010810: nop

    // 0x80010814: swc1        $f10, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f10.u32l;
L_80010818:
    // 0x80010818: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8001081C: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    // 0x80010820: lw          $a2, -0x6BFC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X6BFC);
L_80010824:
    // 0x80010824: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80010828: lwc1        $f4, 0xD4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x8001082C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80010830: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80010834: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80010838: lw          $t7, 0x98($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X98);
    // 0x8001083C: lh          $t8, 0x8E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X8E);
    // 0x80010840: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80010844: div.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80010848: addiu       $v0, $sp, 0x9C
    ctx->r2 = ADD32(ctx->r29, 0X9C);
    // 0x8001084C: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x80010850: addiu       $a1, $sp, 0xA8
    ctx->r5 = ADD32(ctx->r29, 0XA8);
    // 0x80010854: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80010858: beq         $t7, $zero, L_80010884
    if (ctx->r15 == 0) {
        // 0x8001085C: swc1        $f6, 0xD4($sp)
        MEM_W(0XD4, ctx->r29) = ctx->f6.u32l;
            goto L_80010884;
    }
    // 0x8001085C: swc1        $f6, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f6.u32l;
    // 0x80010860: addiu       $v0, $sp, 0x9C
    ctx->r2 = ADD32(ctx->r29, 0X9C);
    // 0x80010864: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
L_80010868:
    // 0x80010868: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8001086C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80010870: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80010874: bne         $v0, $a0, L_80010868
    if (ctx->r2 != ctx->r4) {
        // 0x80010878: swc1        $f10, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
            goto L_80010868;
    }
    // 0x80010878: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x8001087C: b           L_800107C0
    // 0x80010880: sw          $zero, 0x98($sp)
    MEM_W(0X98, ctx->r29) = 0;
        goto L_800107C0;
    // 0x80010880: sw          $zero, 0x98($sp)
    MEM_W(0X98, ctx->r29) = 0;
L_80010884:
    // 0x80010884: beq         $t8, $zero, L_800108EC
    if (ctx->r24 == 0) {
        // 0x80010888: nop
    
            goto L_800108EC;
    }
    // 0x80010888: nop

    // 0x8001088C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80010890: addiu       $v0, $sp, 0x9C
    ctx->r2 = ADD32(ctx->r29, 0X9C);
    // 0x80010894: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x80010898: addiu       $a1, $sp, 0xA8
    ctx->r5 = ADD32(ctx->r29, 0XA8);
    // 0x8001089C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800108A0: beq         $v0, $a1, L_800108CC
    if (ctx->r2 == ctx->r5) {
        // 0x800108A4: lwc1        $f18, -0x4($v0)
        ctx->f18.u32l = MEM_W(ctx->r2, -0X4);
            goto L_800108CC;
    }
    // 0x800108A4: lwc1        $f18, -0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, -0X4);
L_800108A8:
    // 0x800108A8: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800108AC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800108B0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800108B4: sub.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800108B8: div.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = DIV_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800108BC: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800108C0: lwc1        $f18, -0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, -0X4);
    // 0x800108C4: bne         $v0, $a1, L_800108A8
    if (ctx->r2 != ctx->r5) {
        // 0x800108C8: swc1        $f16, -0x8($v0)
        MEM_W(-0X8, ctx->r2) = ctx->f16.u32l;
            goto L_800108A8;
    }
    // 0x800108C8: swc1        $f16, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f16.u32l;
L_800108CC:
    // 0x800108CC: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800108D0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800108D4: sub.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800108D8: div.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = DIV_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800108DC: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800108E0: swc1        $f16, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
    // 0x800108E4: b           L_80010904
    // 0x800108E8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
        goto L_80010904;
    // 0x800108E8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_800108EC:
    // 0x800108EC: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800108F0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800108F4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800108F8: bne         $v0, $a1, L_800108EC
    if (ctx->r2 != ctx->r5) {
        // 0x800108FC: swc1        $f4, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
            goto L_800108EC;
    }
    // 0x800108FC: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80010900: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_80010904:
    // 0x80010904: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80010908: lwc1        $f8, 0x10($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X10);
    // 0x8001090C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80010910: lwc1        $f10, 0x604C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X604C);
    // 0x80010914: add.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80010918: swc1        $f2, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f2.u32l;
    // 0x8001091C: sw          $a2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r6;
    // 0x80010920: mul.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80010924: jal         0x8004F7C0
    // 0x80010928: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    func_8004F7C0(rdram, ctx);
        goto after_6;
    // 0x80010928: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    after_6:
    // 0x8001092C: lwc1        $f2, 0xB4($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80010930: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80010934: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80010938: jal         0x8004F650
    // 0x8001093C: swc1        $f4, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f4.u32l;
    func_8004F650(rdram, ctx);
        goto after_7;
    // 0x8001093C: swc1        $f4, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x80010940: lwc1        $f2, 0xB4($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80010944: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80010948: lw          $v0, -0x6C04($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6C04);
    // 0x8001094C: mul.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80010950: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80010954: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80010958: lw          $a2, 0x90($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X90);
    // 0x8001095C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80010960: addiu       $v1, $v1, -0x6C20
    ctx->r3 = ADD32(ctx->r3, -0X6C20);
    // 0x80010964: beq         $v0, $t0, L_80010980
    if (ctx->r2 == ctx->r8) {
        // 0x80010968: swc1        $f8, 0xAC($sp)
        MEM_W(0XAC, ctx->r29) = ctx->f8.u32l;
            goto L_80010980;
    }
    // 0x80010968: swc1        $f8, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f8.u32l;
    // 0x8001096C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80010970: beql        $v0, $at, L_800109E8
    if (ctx->r2 == ctx->r1) {
        // 0x80010974: lwc1        $f10, 0x18($a2)
        ctx->f10.u32l = MEM_W(ctx->r6, 0X18);
            goto L_800109E8;
    }
    goto skip_5;
    // 0x80010974: lwc1        $f10, 0x18($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X18);
    skip_5:
    // 0x80010978: b           L_800109F0
    // 0x8001097C: nop

        goto L_800109F0;
    // 0x8001097C: nop

L_80010980:
    // 0x80010980: lwc1        $f6, 0x18($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X18);
    // 0x80010984: lwc1        $f10, 0x6050($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6050);
    // 0x80010988: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001098C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80010990: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80010994: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80010998: swc1        $f4, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f4.u32l;
    // 0x8001099C: lwc1        $f6, 0xE4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x800109A0: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x800109A4: nop

    // 0x800109A8: bc1fl       L_800109C0
    if (!c1cs) {
        // 0x800109AC: lwc1        $f0, 0x0($v1)
        ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
            goto L_800109C0;
    }
    goto skip_6;
    // 0x800109AC: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    skip_6:
    // 0x800109B0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800109B4: nop

    // 0x800109B8: swc1        $f10, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f10.u32l;
    // 0x800109BC: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
L_800109C0:
    // 0x800109C0: lwc1        $f4, 0xE4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x800109C4: lwc1        $f8, 0xBC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x800109C8: sub.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800109CC: div.s       $f12, $f2, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f2.fl, ctx->f8.fl);
    // 0x800109D0: swc1        $f2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f2.u32l;
    // 0x800109D4: add.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x800109D8: swc1        $f12, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f12.u32l;
    // 0x800109DC: b           L_800109F0
    // 0x800109E0: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
        goto L_800109F0;
    // 0x800109E0: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x800109E4: lwc1        $f10, 0x18($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X18);
L_800109E8:
    // 0x800109E8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800109EC: swc1        $f10, -0x6C20($at)
    MEM_W(-0X6C20, ctx->r1) = ctx->f10.u32l;
L_800109F0:
    // 0x800109F0: beq         $v0, $t0, L_80010A0C
    if (ctx->r2 == ctx->r8) {
        // 0x800109F4: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80010A0C;
    }
    // 0x800109F4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800109F8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800109FC: beql        $v0, $at, L_80010A28
    if (ctx->r2 == ctx->r1) {
        // 0x80010A00: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80010A28;
    }
    goto skip_7;
    // 0x80010A00: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_7:
    // 0x80010A04: b           L_80010A38
    // 0x80010A08: lwc1        $f4, 0xE8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XE8);
        goto L_80010A38;
    // 0x80010A08: lwc1        $f4, 0xE8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XE8);
L_80010A0C:
    // 0x80010A0C: lwc1        $f4, 0x10($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80010A10: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80010A14: nop

    // 0x80010A18: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80010A1C: b           L_80010A34
    // 0x80010A20: swc1        $f6, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f6.u32l;
        goto L_80010A34;
    // 0x80010A20: swc1        $f6, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f6.u32l;
    // 0x80010A24: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_80010A28:
    // 0x80010A28: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80010A2C: nop

    // 0x80010A30: swc1        $f10, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f10.u32l;
L_80010A34:
    // 0x80010A34: lwc1        $f4, 0xE8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XE8);
L_80010A38:
    // 0x80010A38: lwc1        $f8, 0xA8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80010A3C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80010A40: addiu       $v0, $v0, -0x6C20
    ctx->r2 = ADD32(ctx->r2, -0X6C20);
    // 0x80010A44: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80010A48: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80010A4C: lwc1        $f10, 0xC0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x80010A50: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80010A54: sub.s       $f2, $f6, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80010A58: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80010A5C: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80010A60: addiu       $a0, $sp, 0x130
    ctx->r4 = ADD32(ctx->r29, 0X130);
    // 0x80010A64: div.s       $f12, $f2, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80010A68: swc1        $f2, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f2.u32l;
    // 0x80010A6C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80010A70: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    // 0x80010A74: add.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x80010A78: swc1        $f12, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f12.u32l;
    // 0x80010A7C: jal         0x80049840
    // 0x80010A80: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    func_80049840(rdram, ctx);
        goto after_8;
    // 0x80010A80: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    after_8:
    // 0x80010A84: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80010A88: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80010A8C: lw          $a1, -0x6C1C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6C1C);
    // 0x80010A90: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80010A94: addiu       $a0, $sp, 0xF0
    ctx->r4 = ADD32(ctx->r29, 0XF0);
    // 0x80010A98: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80010A9C: jal         0x80049840
    // 0x80010AA0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80049840(rdram, ctx);
        goto after_9;
    // 0x80010AA0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_9:
    // 0x80010AA4: addiu       $a0, $sp, 0x130
    ctx->r4 = ADD32(ctx->r29, 0X130);
    // 0x80010AA8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80010AAC: jal         0x80000BD8
    // 0x80010AB0: addiu       $a2, $sp, 0xF0
    ctx->r6 = ADD32(ctx->r29, 0XF0);
    func_80000BD8(rdram, ctx);
        goto after_10;
    // 0x80010AB0: addiu       $a2, $sp, 0xF0
    ctx->r6 = ADD32(ctx->r29, 0XF0);
    after_10:
    // 0x80010AB4: lwc1        $f8, 0x150($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X150);
    // 0x80010AB8: lwc1        $f6, 0xD4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80010ABC: lwc1        $f2, 0x9C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80010AC0: lwc1        $f12, 0xA0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80010AC4: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80010AC8: lwc1        $f6, 0xD4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80010ACC: lwc1        $f8, 0x154($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X154);
    // 0x80010AD0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80010AD4: addiu       $a0, $a0, -0x6C10
    ctx->r4 = ADD32(ctx->r4, -0X6C10);
    // 0x80010AD8: lwc1        $f14, 0xA4($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80010ADC: lwc1        $f0, 0xB0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x80010AE0: sub.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x80010AE4: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80010AE8: lwc1        $f6, 0xD4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80010AEC: lwc1        $f8, 0x158($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X158);
    // 0x80010AF0: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80010AF4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80010AF8: addiu       $v0, $v0, -0x6C40
    ctx->r2 = ADD32(ctx->r2, -0X6C40);
    // 0x80010AFC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80010B00: add.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x80010B04: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80010B08: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80010B0C: swc1        $f12, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f12.u32l;
    // 0x80010B10: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    // 0x80010B14: add.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x80010B18: sub.s       $f4, $f14, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f10.fl;
    // 0x80010B1C: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x80010B20: add.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80010B24: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    // 0x80010B28: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80010B2C: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80010B30: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x80010B34: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80010B38: lwc1        $f10, 0xAC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80010B3C: add.s       $f4, $f14, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x80010B40: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x80010B44: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80010B48: lh          $t9, -0x68E4($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X68E4);
    // 0x80010B4C: beq         $t9, $zero, L_80010B94
    if (ctx->r25 == 0) {
        // 0x80010B50: nop
    
            goto L_80010B94;
    }
    // 0x80010B50: nop

    // 0x80010B54: jal         0x8003DAFC
    // 0x80010B58: nop

    func_8003DAFC(rdram, ctx);
        goto after_11;
    // 0x80010B58: nop

    after_11:
    // 0x80010B5C: beq         $v0, $zero, L_80010B94
    if (ctx->r2 == 0) {
        // 0x80010B60: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80010B94;
    }
    // 0x80010B60: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80010B64: lwc1        $f8, -0x6B98($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6B98);
    // 0x80010B68: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80010B6C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80010B70: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80010B74: addiu       $v0, $v0, -0x6C10
    ctx->r2 = ADD32(ctx->r2, -0X6C10);
    // 0x80010B78: add.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80010B7C: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80010B80: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80010B84: nop

    // 0x80010B88: bc1f        L_80010B94
    if (!c1cs) {
        // 0x80010B8C: nop
    
            goto L_80010B94;
    }
    // 0x80010B8C: nop

    // 0x80010B90: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
L_80010B94:
    // 0x80010B94: b           L_8001142C
    // 0x80010B98: nop

        goto L_8001142C;
    // 0x80010B98: nop

L_80010B9C:
    // 0x80010B9C: lw          $t1, 0x98($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X98);
    // 0x80010BA0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80010BA4: lw          $a1, -0x6BFC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6BFC);
    // 0x80010BA8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80010BAC: sh          $zero, -0x6C14($at)
    MEM_H(-0X6C14, ctx->r1) = 0;
    // 0x80010BB0: beq         $t1, $zero, L_80010C88
    if (ctx->r9 == 0) {
        // 0x80010BB4: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_80010C88;
    }
    // 0x80010BB4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80010BB8: addiu       $v0, $sp, 0x9C
    ctx->r2 = ADD32(ctx->r29, 0X9C);
    // 0x80010BBC: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80010BC0: addiu       $a3, $sp, 0xA8
    ctx->r7 = ADD32(ctx->r29, 0XA8);
L_80010BC4:
    // 0x80010BC4: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80010BC8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80010BCC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80010BD0: bne         $v0, $a3, L_80010BC4
    if (ctx->r2 != ctx->r7) {
        // 0x80010BD4: swc1        $f4, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
            goto L_80010BC4;
    }
    // 0x80010BD4: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80010BD8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80010BDC: jal         0x8004EFB4
    // 0x80010BE0: sw          $a2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r6;
    func_8004EFB4(rdram, ctx);
        goto after_12;
    // 0x80010BE0: sw          $a2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r6;
    after_12:
    // 0x80010BE4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80010BE8: lh          $v0, -0x662C($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X662C);
    // 0x80010BEC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80010BF0: lw          $a2, 0x90($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X90);
    // 0x80010BF4: beq         $v0, $at, L_80010C24
    if (ctx->r2 == ctx->r1) {
        // 0x80010BF8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80010C24;
    }
    // 0x80010BF8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80010BFC: beq         $v0, $at, L_80010C38
    if (ctx->r2 == ctx->r1) {
        // 0x80010C00: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80010C38;
    }
    // 0x80010C00: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80010C04: beq         $v0, $at, L_80010C4C
    if (ctx->r2 == ctx->r1) {
        // 0x80010C08: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80010C4C;
    }
    // 0x80010C08: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80010C0C: beq         $v0, $at, L_80010C60
    if (ctx->r2 == ctx->r1) {
        // 0x80010C10: lui         $at, 0x4248
        ctx->r1 = S32(0X4248 << 16);
            goto L_80010C60;
    }
    // 0x80010C10: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80010C14: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80010C18: sw          $zero, 0x98($sp)
    MEM_W(0X98, ctx->r29) = 0;
    // 0x80010C1C: b           L_80010C70
    // 0x80010C20: swc1        $f8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f8.u32l;
        goto L_80010C70;
    // 0x80010C20: swc1        $f8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f8.u32l;
L_80010C24:
    // 0x80010C24: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80010C28: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80010C2C: sw          $zero, 0x98($sp)
    MEM_W(0X98, ctx->r29) = 0;
    // 0x80010C30: b           L_80010C70
    // 0x80010C34: swc1        $f6, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f6.u32l;
        goto L_80010C70;
    // 0x80010C34: swc1        $f6, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f6.u32l;
L_80010C38:
    // 0x80010C38: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80010C3C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80010C40: sw          $zero, 0x98($sp)
    MEM_W(0X98, ctx->r29) = 0;
    // 0x80010C44: b           L_80010C70
    // 0x80010C48: swc1        $f10, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f10.u32l;
        goto L_80010C70;
    // 0x80010C48: swc1        $f10, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f10.u32l;
L_80010C4C:
    // 0x80010C4C: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80010C50: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80010C54: sw          $zero, 0x98($sp)
    MEM_W(0X98, ctx->r29) = 0;
    // 0x80010C58: b           L_80010C70
    // 0x80010C5C: swc1        $f4, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f4.u32l;
        goto L_80010C70;
    // 0x80010C5C: swc1        $f4, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f4.u32l;
L_80010C60:
    // 0x80010C60: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80010C64: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80010C68: sw          $zero, 0x98($sp)
    MEM_W(0X98, ctx->r29) = 0;
    // 0x80010C6C: swc1        $f8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f8.u32l;
L_80010C70:
    // 0x80010C70: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80010C74: lwc1        $f6, 0x6054($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6054);
    // 0x80010C78: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80010C7C: swc1        $f6, -0x6C20($at)
    MEM_W(-0X6C20, ctx->r1) = ctx->f6.u32l;
    // 0x80010C80: lwc1        $f10, 0x10($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80010C84: swc1        $f10, -0x6C1C($at)
    MEM_W(-0X6C1C, ctx->r1) = ctx->f10.u32l;
L_80010C88:
    // 0x80010C88: addiu       $v0, $sp, 0x9C
    ctx->r2 = ADD32(ctx->r29, 0X9C);
    // 0x80010C8C: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x80010C90: addiu       $t0, $sp, 0xA8
    ctx->r8 = ADD32(ctx->r29, 0XA8);
L_80010C94:
    // 0x80010C94: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80010C98: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80010C9C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80010CA0: bne         $v0, $t0, L_80010C94
    if (ctx->r2 != ctx->r8) {
        // 0x80010CA4: swc1        $f4, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
            goto L_80010C94;
    }
    // 0x80010CA4: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80010CA8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80010CAC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80010CB0: lw          $a1, -0x6C20($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6C20);
    // 0x80010CB4: addiu       $a0, $sp, 0x130
    ctx->r4 = ADD32(ctx->r29, 0X130);
    // 0x80010CB8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80010CBC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80010CC0: jal         0x80049840
    // 0x80010CC4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_80049840(rdram, ctx);
        goto after_13;
    // 0x80010CC4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_13:
    // 0x80010CC8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80010CCC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80010CD0: lw          $a1, -0x6C1C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6C1C);
    // 0x80010CD4: addiu       $a0, $sp, 0xF0
    ctx->r4 = ADD32(ctx->r29, 0XF0);
    // 0x80010CD8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80010CDC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80010CE0: jal         0x80049840
    // 0x80010CE4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_80049840(rdram, ctx);
        goto after_14;
    // 0x80010CE4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_14:
    // 0x80010CE8: addiu       $a1, $sp, 0x130
    ctx->r5 = ADD32(ctx->r29, 0X130);
    // 0x80010CEC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80010CF0: jal         0x80000BD8
    // 0x80010CF4: addiu       $a2, $sp, 0xF0
    ctx->r6 = ADD32(ctx->r29, 0XF0);
    func_80000BD8(rdram, ctx);
        goto after_15;
    // 0x80010CF4: addiu       $a2, $sp, 0xF0
    ctx->r6 = ADD32(ctx->r29, 0XF0);
    after_15:
    // 0x80010CF8: lwc1        $f10, 0x150($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X150);
    // 0x80010CFC: lwc1        $f4, 0xD4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80010D00: lwc1        $f2, 0x9C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80010D04: lwc1        $f12, 0xA0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80010D08: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80010D0C: lwc1        $f4, 0xD4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80010D10: lwc1        $f10, 0x154($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X154);
    // 0x80010D14: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80010D18: addiu       $a0, $a0, -0x6C10
    ctx->r4 = ADD32(ctx->r4, -0X6C10);
    // 0x80010D1C: lwc1        $f14, 0xA4($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80010D20: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80010D24: sub.s       $f6, $f2, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x80010D28: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80010D2C: lwc1        $f4, 0xD4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80010D30: lwc1        $f10, 0x158($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X158);
    // 0x80010D34: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x80010D38: add.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x80010D3C: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80010D40: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x80010D44: sub.s       $f6, $f14, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f8.fl;
    // 0x80010D48: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    // 0x80010D4C: swc1        $f2, -0x6C40($at)
    MEM_W(-0X6C40, ctx->r1) = ctx->f2.u32l;
    // 0x80010D50: swc1        $f12, -0x6C3C($at)
    MEM_W(-0X6C3C, ctx->r1) = ctx->f12.u32l;
    // 0x80010D54: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80010D58: swc1        $f14, -0x6C38($at)
    MEM_W(-0X6C38, ctx->r1) = ctx->f14.u32l;
    // 0x80010D5C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80010D60: lwc1        $f10, -0x6C1C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X6C1C);
    // 0x80010D64: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80010D68: lwc1        $f4, 0x6058($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6058);
    // 0x80010D6C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80010D70: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80010D74: jal         0x8003DAFC
    // 0x80010D78: swc1        $f8, -0x6C1C($at)
    MEM_W(-0X6C1C, ctx->r1) = ctx->f8.u32l;
    func_8003DAFC(rdram, ctx);
        goto after_16;
    // 0x80010D78: swc1        $f8, -0x6C1C($at)
    MEM_W(-0X6C1C, ctx->r1) = ctx->f8.u32l;
    after_16:
    // 0x80010D7C: beq         $v0, $zero, L_8001142C
    if (ctx->r2 == 0) {
        // 0x80010D80: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_8001142C;
    }
    // 0x80010D80: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80010D84: lwc1        $f6, -0x6B98($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X6B98);
    // 0x80010D88: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80010D8C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80010D90: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80010D94: lwc1        $f4, -0x6C0C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6C0C);
    // 0x80010D98: add.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80010D9C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80010DA0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80010DA4: nop

    // 0x80010DA8: bc1f        L_8001142C
    if (!c1cs) {
        // 0x80010DAC: nop
    
            goto L_8001142C;
    }
    // 0x80010DAC: nop

    // 0x80010DB0: b           L_8001142C
    // 0x80010DB4: swc1        $f0, -0x6C0C($at)
    MEM_W(-0X6C0C, ctx->r1) = ctx->f0.u32l;
        goto L_8001142C;
    // 0x80010DB4: swc1        $f0, -0x6C0C($at)
    MEM_W(-0X6C0C, ctx->r1) = ctx->f0.u32l;
L_80010DB8:
    // 0x80010DB8: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80010DBC: lh          $t3, -0x6C14($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X6C14);
    // 0x80010DC0: bne         $t3, $zero, L_80010E28
    if (ctx->r11 != 0) {
        // 0x80010DC4: nop
    
            goto L_80010E28;
    }
    // 0x80010DC4: nop

L_80010DC8:
    // 0x80010DC8: jal         0x80044480
    // 0x80010DCC: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    func_80044480(rdram, ctx);
        goto after_17;
    // 0x80010DCC: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_17:
    // 0x80010DD0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80010DD4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80010DD8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80010DDC: sw          $t4, -0x6C04($at)
    MEM_W(-0X6C04, ctx->r1) = ctx->r12;
    // 0x80010DE0: addiu       $a1, $a1, -0x6A18
    ctx->r5 = ADD32(ctx->r5, -0X6A18);
    // 0x80010DE4: jal         0x8004EFB4
    // 0x80010DE8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8004EFB4(rdram, ctx);
        goto after_18;
    // 0x80010DE8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_18:
    // 0x80010DEC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80010DF0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80010DF4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80010DF8: addiu       $a1, $a1, -0x6C14
    ctx->r5 = ADD32(ctx->r5, -0X6C14);
    // 0x80010DFC: addiu       $v1, $v1, -0x6C20
    ctx->r3 = ADD32(ctx->r3, -0X6C20);
    // 0x80010E00: addiu       $a0, $a0, -0x6BF0
    ctx->r4 = ADD32(ctx->r4, -0X6BF0);
L_80010E04:
    // 0x80010E04: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80010E08: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80010E0C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80010E10: bne         $v1, $a1, L_80010E04
    if (ctx->r3 != ctx->r5) {
        // 0x80010E14: swc1        $f8, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f8.u32l;
            goto L_80010E04;
    }
    // 0x80010E14: swc1        $f8, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f8.u32l;
    // 0x80010E18: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80010E1C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80010E20: b           L_80010708
    // 0x80010E24: nop

        goto L_80010708;
    // 0x80010E24: nop

L_80010E28:
    // 0x80010E28: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80010E2C: lh          $t5, -0x6938($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X6938);
    // 0x80010E30: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80010E34: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x80010E38: bgtz        $t5, L_80010E48
    if (SIGNED(ctx->r13) > 0) {
        // 0x80010E3C: nop
    
            goto L_80010E48;
    }
    // 0x80010E3C: nop

    // 0x80010E40: b           L_80010DC8
    // 0x80010E44: sh          $zero, -0x6C14($at)
    MEM_H(-0X6C14, ctx->r1) = 0;
        goto L_80010DC8;
    // 0x80010E44: sh          $zero, -0x6C14($at)
    MEM_H(-0X6C14, ctx->r1) = 0;
L_80010E48:
    // 0x80010E48: jal         0x80040764
    // 0x80010E4C: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    func_80040764(rdram, ctx);
        goto after_19;
    // 0x80010E4C: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_19:
    // 0x80010E50: beq         $v0, $zero, L_800110C0
    if (ctx->r2 == 0) {
        // 0x80010E54: lh          $t9, 0x4A($sp)
        ctx->r25 = MEM_H(ctx->r29, 0X4A);
            goto L_800110C0;
    }
    // 0x80010E54: lh          $t9, 0x4A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X4A);
    // 0x80010E58: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80010E5C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80010E60: addiu       $v1, $v1, -0x6C20
    ctx->r3 = ADD32(ctx->r3, -0X6C20);
    // 0x80010E64: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80010E68: swc1        $f6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f6.u32l;
    // 0x80010E6C: lh          $v0, -0x6C14($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X6C14);
    // 0x80010E70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80010E74: addiu       $a0, $sp, 0x130
    ctx->r4 = ADD32(ctx->r29, 0X130);
    // 0x80010E78: beq         $v0, $at, L_80010E9C
    if (ctx->r2 == ctx->r1) {
        // 0x80010E7C: lui         $a1, 0x8013
        ctx->r5 = S32(0X8013 << 16);
            goto L_80010E9C;
    }
    // 0x80010E7C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80010E80: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80010E84: beq         $v0, $at, L_80010ECC
    if (ctx->r2 == ctx->r1) {
        // 0x80010E88: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80010ECC;
    }
    // 0x80010E88: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80010E8C: beq         $v0, $at, L_80010EF0
    if (ctx->r2 == ctx->r1) {
        // 0x80010E90: lwc1        $f10, 0x40($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
            goto L_80010EF0;
    }
    // 0x80010E90: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80010E94: b           L_80010F28
    // 0x80010E98: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
        goto L_80010F28;
    // 0x80010E98: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80010E9C:
    // 0x80010E9C: lwc1        $f18, 0x70($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80010EA0: lui         $at, 0xBD00
    ctx->r1 = S32(0XBD00 << 16);
    // 0x80010EA4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80010EA8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80010EAC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80010EB0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80010EB4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80010EB8: add.s       $f14, $f18, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f14.fl;
    // 0x80010EBC: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
    // 0x80010EC0: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    // 0x80010EC4: b           L_80010F24
    // 0x80010EC8: swc1        $f14, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f14.u32l;
        goto L_80010F24;
    // 0x80010EC8: swc1        $f14, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f14.u32l;
L_80010ECC:
    // 0x80010ECC: lui         $at, 0xBC80
    ctx->r1 = S32(0XBC80 << 16);
    // 0x80010ED0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80010ED4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80010ED8: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80010EDC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80010EE0: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x80010EE4: swc1        $f8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f8.u32l;
    // 0x80010EE8: b           L_80010F24
    // 0x80010EEC: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
        goto L_80010F24;
    // 0x80010EEC: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
L_80010EF0:
    // 0x80010EF0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80010EF4: lwc1        $f4, 0x605C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X605C);
    // 0x80010EF8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80010EFC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80010F00: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80010F04: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80010F08: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x80010F0C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80010F10: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x80010F14: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80010F18: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x80010F1C: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80010F20: swc1        $f8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f8.u32l;
L_80010F24:
    // 0x80010F24: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80010F28:
    // 0x80010F28: lw          $a1, -0x6C20($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6C20);
    // 0x80010F2C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80010F30: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80010F34: jal         0x80049840
    // 0x80010F38: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80049840(rdram, ctx);
        goto after_20;
    // 0x80010F38: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_20:
    // 0x80010F3C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80010F40: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80010F44: lw          $a1, -0x6C1C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6C1C);
    // 0x80010F48: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80010F4C: addiu       $a0, $sp, 0xF0
    ctx->r4 = ADD32(ctx->r29, 0XF0);
    // 0x80010F50: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80010F54: jal         0x80049840
    // 0x80010F58: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80049840(rdram, ctx);
        goto after_21;
    // 0x80010F58: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_21:
    // 0x80010F5C: addiu       $a1, $sp, 0x130
    ctx->r5 = ADD32(ctx->r29, 0X130);
    // 0x80010F60: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80010F64: jal         0x80000BD8
    // 0x80010F68: addiu       $a2, $sp, 0xF0
    ctx->r6 = ADD32(ctx->r29, 0XF0);
    func_80000BD8(rdram, ctx);
        goto after_22;
    // 0x80010F68: addiu       $a2, $sp, 0xF0
    ctx->r6 = ADD32(ctx->r29, 0XF0);
    after_22:
    // 0x80010F6C: lwc1        $f18, 0x150($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X150);
    // 0x80010F70: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80010F74: lwc1        $f14, 0x78($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80010F78: lwc1        $f12, 0x154($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X154);
    // 0x80010F7C: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80010F80: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80010F84: lwc1        $f10, 0x158($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X158);
    // 0x80010F88: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80010F8C: mul.s       $f18, $f12, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x80010F90: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80010F94: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80010F98: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80010F9C: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x80010FA0: sub.s       $f16, $f14, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x80010FA4: mul.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80010FA8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80010FAC: add.s       $f6, $f18, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80010FB0: addiu       $v0, $v0, -0x6C10
    ctx->r2 = ADD32(ctx->r2, -0X6C10);
    // 0x80010FB4: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x80010FB8: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    // 0x80010FBC: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80010FC0: sub.s       $f8, $f4, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80010FC4: addiu       $a0, $sp, 0x130
    ctx->r4 = ADD32(ctx->r29, 0X130);
    // 0x80010FC8: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x80010FCC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80010FD0: jal         0x80049840
    // 0x80010FD4: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    func_80049840(rdram, ctx);
        goto after_23;
    // 0x80010FD4: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    after_23:
    // 0x80010FD8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80010FDC: addiu       $a0, $sp, 0xF0
    ctx->r4 = ADD32(ctx->r29, 0XF0);
    // 0x80010FE0: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x80010FE4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80010FE8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80010FEC: jal         0x80049840
    // 0x80010FF0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80049840(rdram, ctx);
        goto after_24;
    // 0x80010FF0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_24:
    // 0x80010FF4: addiu       $a1, $sp, 0x130
    ctx->r5 = ADD32(ctx->r29, 0X130);
    // 0x80010FF8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80010FFC: jal         0x80000BD8
    // 0x80011000: addiu       $a2, $sp, 0xF0
    ctx->r6 = ADD32(ctx->r29, 0XF0);
    func_80000BD8(rdram, ctx);
        goto after_25;
    // 0x80011000: addiu       $a2, $sp, 0xF0
    ctx->r6 = ADD32(ctx->r29, 0XF0);
    after_25:
    // 0x80011004: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x80011008: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001100C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80011010: addiu       $v1, $v1, -0x6C40
    ctx->r3 = ADD32(ctx->r3, -0X6C40);
    // 0x80011014: addiu       $a0, $sp, 0x130
    ctx->r4 = ADD32(ctx->r29, 0X130);
    // 0x80011018: addiu       $v0, $sp, 0x78
    ctx->r2 = ADD32(ctx->r29, 0X78);
    // 0x8001101C: addiu       $a2, $sp, 0x84
    ctx->r6 = ADD32(ctx->r29, 0X84);
    // 0x80011020: lwc1        $f14, 0x20($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80011024: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80011028: sltu        $at, $v0, $a2
    ctx->r1 = ctx->r2 < ctx->r6 ? 1 : 0;
    // 0x8001102C: mul.s       $f18, $f14, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80011030: beql        $at, $zero, L_80011064
    if (ctx->r1 == 0) {
        // 0x80011034: lwc1        $f16, -0x4($v0)
        ctx->f16.u32l = MEM_W(ctx->r2, -0X4);
            goto L_80011064;
    }
    goto skip_8;
    // 0x80011034: lwc1        $f16, -0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, -0X4);
    skip_8:
L_80011038:
    // 0x80011038: lwc1        $f16, -0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, -0X4);
    // 0x8001103C: lwc1        $f14, 0x24($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80011040: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80011044: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80011048: mul.s       $f18, $f14, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8001104C: sltu        $at, $v0, $a2
    ctx->r1 = ctx->r2 < ctx->r6 ? 1 : 0;
    // 0x80011050: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80011054: swc1        $f16, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f16.u32l;
    // 0x80011058: bne         $at, $zero, L_80011038
    if (ctx->r1 != 0) {
        // 0x8001105C: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80011038;
    }
    // 0x8001105C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80011060: lwc1        $f16, -0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, -0X4);
L_80011064:
    // 0x80011064: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80011068: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8001106C: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80011070: swc1        $f16, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f16.u32l;
    // 0x80011074: addiu       $v0, $sp, 0x78
    ctx->r2 = ADD32(ctx->r29, 0X78);
    // 0x80011078: addiu       $v1, $sp, 0x4C
    ctx->r3 = ADD32(ctx->r29, 0X4C);
    // 0x8001107C: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x80011080: addiu       $a3, $sp, 0x78
    ctx->r7 = ADD32(ctx->r29, 0X78);
L_80011084:
    // 0x80011084: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80011088: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001108C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80011090: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80011094: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80011098: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
    // 0x8001109C: bne         $a0, $a3, L_80011084
    if (ctx->r4 != ctx->r7) {
        // 0x800110A0: swc1        $f4, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
            goto L_80011084;
    }
    // 0x800110A0: swc1        $f4, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
    // 0x800110A4: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x800110A8: sh          $t8, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r24;
    // 0x800110AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800110B0: jal         0x8004EFB4
    // 0x800110B4: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_8004EFB4(rdram, ctx);
        goto after_26;
    // 0x800110B4: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_26:
    // 0x800110B8: b           L_8001142C
    // 0x800110BC: nop

        goto L_8001142C;
    // 0x800110BC: nop

L_800110C0:
    // 0x800110C0: beq         $t9, $zero, L_8001142C
    if (ctx->r25 == 0) {
        // 0x800110C4: addiu       $t1, $t9, -0x1
        ctx->r9 = ADD32(ctx->r25, -0X1);
            goto L_8001142C;
    }
    // 0x800110C4: addiu       $t1, $t9, -0x1
    ctx->r9 = ADD32(ctx->r25, -0X1);
    // 0x800110C8: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x800110CC: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x800110D0: bne         $t3, $zero, L_8001142C
    if (ctx->r11 != 0) {
        // 0x800110D4: sh          $t1, 0x4A($sp)
        MEM_H(0X4A, ctx->r29) = ctx->r9;
            goto L_8001142C;
    }
    // 0x800110D4: sh          $t1, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r9;
    // 0x800110D8: b           L_80010DC8
    // 0x800110DC: nop

        goto L_80010DC8;
    // 0x800110DC: nop

L_800110E0:
    // 0x800110E0: lw          $t4, 0x98($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X98);
    // 0x800110E4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800110E8: lw          $a1, -0x6BFC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6BFC);
    // 0x800110EC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800110F0: sh          $zero, -0x6C14($at)
    MEM_H(-0X6C14, ctx->r1) = 0;
    // 0x800110F4: beq         $t4, $zero, L_80011158
    if (ctx->r12 == 0) {
        // 0x800110F8: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_80011158;
    }
    // 0x800110F8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800110FC: addiu       $v0, $sp, 0x9C
    ctx->r2 = ADD32(ctx->r29, 0X9C);
    // 0x80011100: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80011104: addiu       $a3, $sp, 0xA8
    ctx->r7 = ADD32(ctx->r29, 0XA8);
L_80011108:
    // 0x80011108: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8001110C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80011110: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80011114: bne         $v0, $a3, L_80011108
    if (ctx->r2 != ctx->r7) {
        // 0x80011118: swc1        $f10, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
            goto L_80011108;
    }
    // 0x80011118: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x8001111C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80011120: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80011124: sw          $zero, 0x98($sp)
    MEM_W(0X98, ctx->r29) = 0;
    // 0x80011128: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8001112C: sw          $a2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r6;
    // 0x80011130: jal         0x8004EFB4
    // 0x80011134: swc1        $f6, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f6.u32l;
    func_8004EFB4(rdram, ctx);
        goto after_27;
    // 0x80011134: swc1        $f6, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f6.u32l;
    after_27:
    // 0x80011138: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001113C: lwc1        $f8, 0x6060($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6060);
    // 0x80011140: lw          $a2, 0x90($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X90);
    // 0x80011144: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80011148: addiu       $v0, $v0, -0x6C20
    ctx->r2 = ADD32(ctx->r2, -0X6C20);
    // 0x8001114C: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80011150: lwc1        $f4, 0x10($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80011154: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
L_80011158:
    // 0x80011158: addiu       $v0, $sp, 0x9C
    ctx->r2 = ADD32(ctx->r29, 0X9C);
    // 0x8001115C: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x80011160: addiu       $t0, $sp, 0xA8
    ctx->r8 = ADD32(ctx->r29, 0XA8);
L_80011164:
    // 0x80011164: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80011168: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001116C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80011170: bne         $v0, $t0, L_80011164
    if (ctx->r2 != ctx->r8) {
        // 0x80011174: swc1        $f10, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
            goto L_80011164;
    }
    // 0x80011174: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x80011178: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001117C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80011180: lw          $a1, -0x6C20($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6C20);
    // 0x80011184: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80011188: addiu       $a0, $sp, 0x130
    ctx->r4 = ADD32(ctx->r29, 0X130);
    // 0x8001118C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80011190: jal         0x80049840
    // 0x80011194: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80049840(rdram, ctx);
        goto after_28;
    // 0x80011194: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_28:
    // 0x80011198: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001119C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800111A0: lw          $a1, -0x6C1C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6C1C);
    // 0x800111A4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800111A8: addiu       $a0, $sp, 0xF0
    ctx->r4 = ADD32(ctx->r29, 0XF0);
    // 0x800111AC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800111B0: jal         0x80049840
    // 0x800111B4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80049840(rdram, ctx);
        goto after_29;
    // 0x800111B4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_29:
    // 0x800111B8: addiu       $a0, $sp, 0x130
    ctx->r4 = ADD32(ctx->r29, 0X130);
    // 0x800111BC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800111C0: jal         0x80000BD8
    // 0x800111C4: addiu       $a2, $sp, 0xF0
    ctx->r6 = ADD32(ctx->r29, 0XF0);
    func_80000BD8(rdram, ctx);
        goto after_30;
    // 0x800111C4: addiu       $a2, $sp, 0xF0
    ctx->r6 = ADD32(ctx->r29, 0XF0);
    after_30:
    // 0x800111C8: lwc1        $f6, 0x150($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X150);
    // 0x800111CC: lwc1        $f8, 0xD4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800111D0: lwc1        $f2, 0x9C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800111D4: lwc1        $f12, 0xA0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800111D8: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800111DC: lwc1        $f8, 0xD4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800111E0: lwc1        $f6, 0x154($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X154);
    // 0x800111E4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800111E8: addiu       $v1, $v1, -0x6C10
    ctx->r3 = ADD32(ctx->r3, -0X6C10);
    // 0x800111EC: lwc1        $f14, 0xA4($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x800111F0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800111F4: sub.s       $f10, $f2, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x800111F8: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800111FC: lwc1        $f8, 0xD4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80011200: lwc1        $f6, 0x158($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X158);
    // 0x80011204: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x80011208: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001120C: addiu       $v0, $v0, -0x6C20
    ctx->r2 = ADD32(ctx->r2, -0X6C20);
    // 0x80011210: add.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x80011214: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80011218: swc1        $f10, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f10.u32l;
    // 0x8001121C: sub.s       $f10, $f14, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f4.fl;
    // 0x80011220: swc1        $f10, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f10.u32l;
    // 0x80011224: swc1        $f2, -0x6C40($at)
    MEM_W(-0X6C40, ctx->r1) = ctx->f2.u32l;
    // 0x80011228: swc1        $f12, -0x6C3C($at)
    MEM_W(-0X6C3C, ctx->r1) = ctx->f12.u32l;
    // 0x8001122C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80011230: swc1        $f14, -0x6C38($at)
    MEM_W(-0X6C38, ctx->r1) = ctx->f14.u32l;
    // 0x80011234: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80011238: lwc1        $f8, 0x6064($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6064);
    // 0x8001123C: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80011240: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80011244: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80011248: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8001124C: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x80011250: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80011254: ldc1        $f8, 0x6068($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X6068);
    // 0x80011258: add.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f6.d + ctx->f8.d;
    // 0x8001125C: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x80011260: b           L_8001142C
    // 0x80011264: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
        goto L_8001142C;
    // 0x80011264: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
L_80011268:
    // 0x80011268: lw          $t5, 0x98($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X98);
    // 0x8001126C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80011270: lw          $a1, -0x6BFC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6BFC);
    // 0x80011274: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80011278: sh          $zero, -0x6C14($at)
    MEM_H(-0X6C14, ctx->r1) = 0;
    // 0x8001127C: beq         $t5, $zero, L_800112E0
    if (ctx->r13 == 0) {
        // 0x80011280: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_800112E0;
    }
    // 0x80011280: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80011284: addiu       $v0, $sp, 0x9C
    ctx->r2 = ADD32(ctx->r29, 0X9C);
    // 0x80011288: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x8001128C: addiu       $a3, $sp, 0xA8
    ctx->r7 = ADD32(ctx->r29, 0XA8);
L_80011290:
    // 0x80011290: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80011294: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80011298: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8001129C: bne         $v0, $a3, L_80011290
    if (ctx->r2 != ctx->r7) {
        // 0x800112A0: swc1        $f6, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
            goto L_80011290;
    }
    // 0x800112A0: swc1        $f6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
    // 0x800112A4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800112A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800112AC: sw          $zero, 0x98($sp)
    MEM_W(0X98, ctx->r29) = 0;
    // 0x800112B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800112B4: sw          $a2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r6;
    // 0x800112B8: jal         0x8004EFB4
    // 0x800112BC: swc1        $f8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f8.u32l;
    func_8004EFB4(rdram, ctx);
        goto after_31;
    // 0x800112BC: swc1        $f8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f8.u32l;
    after_31:
    // 0x800112C0: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x800112C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800112C8: lw          $a2, 0x90($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X90);
    // 0x800112CC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800112D0: addiu       $v0, $v0, -0x6C20
    ctx->r2 = ADD32(ctx->r2, -0X6C20);
    // 0x800112D4: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x800112D8: lwc1        $f10, 0x10($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800112DC: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
L_800112E0:
    // 0x800112E0: addiu       $v0, $sp, 0x9C
    ctx->r2 = ADD32(ctx->r29, 0X9C);
    // 0x800112E4: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x800112E8: addiu       $t0, $sp, 0xA8
    ctx->r8 = ADD32(ctx->r29, 0XA8);
L_800112EC:
    // 0x800112EC: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800112F0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800112F4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800112F8: bne         $v0, $t0, L_800112EC
    if (ctx->r2 != ctx->r8) {
        // 0x800112FC: swc1        $f6, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
            goto L_800112EC;
    }
    // 0x800112FC: swc1        $f6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80011300: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80011304: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80011308: lw          $a1, -0x6C20($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6C20);
    // 0x8001130C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80011310: addiu       $a0, $sp, 0x130
    ctx->r4 = ADD32(ctx->r29, 0X130);
    // 0x80011314: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80011318: jal         0x80049840
    // 0x8001131C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80049840(rdram, ctx);
        goto after_32;
    // 0x8001131C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_32:
    // 0x80011320: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80011324: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80011328: lw          $a1, -0x6C1C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6C1C);
    // 0x8001132C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80011330: addiu       $a0, $sp, 0xF0
    ctx->r4 = ADD32(ctx->r29, 0XF0);
    // 0x80011334: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80011338: jal         0x80049840
    // 0x8001133C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80049840(rdram, ctx);
        goto after_33;
    // 0x8001133C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_33:
    // 0x80011340: addiu       $a0, $sp, 0x130
    ctx->r4 = ADD32(ctx->r29, 0X130);
    // 0x80011344: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80011348: jal         0x80000BD8
    // 0x8001134C: addiu       $a2, $sp, 0xF0
    ctx->r6 = ADD32(ctx->r29, 0XF0);
    func_80000BD8(rdram, ctx);
        goto after_34;
    // 0x8001134C: addiu       $a2, $sp, 0xF0
    ctx->r6 = ADD32(ctx->r29, 0XF0);
    after_34:
    // 0x80011350: lwc1        $f8, 0x150($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X150);
    // 0x80011354: lwc1        $f4, 0xD4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80011358: lwc1        $f2, 0x9C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8001135C: lwc1        $f12, 0xA0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80011360: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80011364: lwc1        $f4, 0xD4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80011368: lwc1        $f8, 0x154($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X154);
    // 0x8001136C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80011370: addiu       $v1, $v1, -0x6C10
    ctx->r3 = ADD32(ctx->r3, -0X6C10);
    // 0x80011374: lwc1        $f14, 0xA4($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80011378: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001137C: sub.s       $f6, $f2, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x80011380: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80011384: lwc1        $f4, 0xD4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80011388: lwc1        $f8, 0x158($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X158);
    // 0x8001138C: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x80011390: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80011394: addiu       $v0, $v0, -0x6C20
    ctx->r2 = ADD32(ctx->r2, -0X6C20);
    // 0x80011398: add.s       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x8001139C: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800113A0: swc1        $f6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f6.u32l;
    // 0x800113A4: sub.s       $f6, $f14, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f10.fl;
    // 0x800113A8: swc1        $f6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f6.u32l;
    // 0x800113AC: swc1        $f2, -0x6C40($at)
    MEM_W(-0X6C40, ctx->r1) = ctx->f2.u32l;
    // 0x800113B0: swc1        $f12, -0x6C3C($at)
    MEM_W(-0X6C3C, ctx->r1) = ctx->f12.u32l;
    // 0x800113B4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800113B8: swc1        $f14, -0x6C38($at)
    MEM_W(-0X6C38, ctx->r1) = ctx->f14.u32l;
    // 0x800113BC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800113C0: lwc1        $f4, 0x6070($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6070);
    // 0x800113C4: lui         $at, 0xBD80
    ctx->r1 = S32(0XBD80 << 16);
    // 0x800113C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800113CC: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800113D0: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800113D4: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800113D8: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800113DC: bc1f        L_800113F8
    if (!c1cs) {
        // 0x800113E0: swc1        $f10, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
            goto L_800113F8;
    }
    // 0x800113E0: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x800113E4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800113E8: lwc1        $f8, 0x6074($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6074);
    // 0x800113EC: sub.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x800113F0: b           L_8001142C
    // 0x800113F4: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
        goto L_8001142C;
    // 0x800113F4: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
L_800113F8:
    // 0x800113F8: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x800113FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80011400: lwc1        $f10, 0xD4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80011404: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80011408: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x8001140C: nop

    // 0x80011410: bc1f        L_8001142C
    if (!c1cs) {
        // 0x80011414: nop
    
            goto L_8001142C;
    }
    // 0x80011414: nop

    // 0x80011418: ldc1        $f4, 0x6078($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X6078);
    // 0x8001141C: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x80011420: add.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d + ctx->f4.d;
    // 0x80011424: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x80011428: swc1        $f10, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f10.u32l;
L_8001142C:
    // 0x8001142C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80011430: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80011434: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80011438: addiu       $a1, $a1, -0x6C44
    ctx->r5 = ADD32(ctx->r5, -0X6C44);
    // 0x8001143C: addiu       $v1, $v1, -0x6C50
    ctx->r3 = ADD32(ctx->r3, -0X6C50);
    // 0x80011440: addiu       $v0, $v0, -0x6C10
    ctx->r2 = ADD32(ctx->r2, -0X6C10);
    // 0x80011444: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80011448:
    // 0x80011448: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001144C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80011450: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x80011454: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80011458: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001145C: bne         $at, $zero, L_80011448
    if (ctx->r1 != 0) {
        // 0x80011460: swc1        $f8, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f8.u32l;
            goto L_80011448;
    }
    // 0x80011460: swc1        $f8, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f8.u32l;
    // 0x80011464: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80011468: lwc1        $f4, 0x6080($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6080);
    // 0x8001146C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80011470: lwc1        $f6, -0x6BF8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X6BF8);
    // 0x80011474: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80011478: nop

    // 0x8001147C: bc1f        L_800114EC
    if (!c1cs) {
        // 0x80011480: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_800114EC;
    }
    // 0x80011480: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80011484: addiu       $v1, $v1, -0x6C50
    ctx->r3 = ADD32(ctx->r3, -0X6C50);
    // 0x80011488: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8001148C:
    // 0x8001148C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x80011490: jal         0x8000E35C
    // 0x80011494: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    func_8000E35C(rdram, ctx);
        goto after_35;
    // 0x80011494: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    after_35:
    // 0x80011498: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x8001149C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800114A0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800114A4: lwc1        $f0, -0x6BF8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6BF8);
    // 0x800114A8: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800114AC: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800114B0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800114B4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800114B8: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800114BC: addiu       $t7, $t7, -0x6C44
    ctx->r15 = ADD32(ctx->r15, -0X6C44);
    // 0x800114C0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800114C4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800114C8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800114CC: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800114D0: bne         $v1, $t7, L_8001148C
    if (ctx->r3 != ctx->r15) {
        // 0x800114D4: swc1        $f8, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f8.u32l;
            goto L_8001148C;
    }
    // 0x800114D4: swc1        $f8, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f8.u32l;
    // 0x800114D8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800114DC: lwc1        $f4, -0x6BF4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6BF4);
    // 0x800114E0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800114E4: sub.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800114E8: swc1        $f10, -0x6BF8($at)
    MEM_W(-0X6BF8, ctx->r1) = ctx->f10.u32l;
L_800114EC:
    // 0x800114EC: jal         0x8000798C
    // 0x800114F0: nop

    func_8000798C(rdram, ctx);
        goto after_36;
    // 0x800114F0: nop

    after_36:
    // 0x800114F4: b           L_800104C8
    // 0x800114F8: lw          $t7, 0x170($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X170);
        goto L_800104C8;
    // 0x800114F8: lw          $t7, 0x170($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X170);
    // 0x800114FC: nop

    // 0x80011500: nop

    // 0x80011504: nop

    // 0x80011508: nop

    // 0x8001150C: nop

    // 0x80011510: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80011514: addiu       $sp, $sp, 0x170
    ctx->r29 = ADD32(ctx->r29, 0X170);
    // 0x80011518: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80011520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80011520: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80011524: sw          $a0, -0x6C00($at)
    MEM_W(-0X6C00, ctx->r1) = ctx->r4;
    // 0x80011528: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001152C: jr          $ra
    // 0x80011530: sw          $a1, -0x6BFC($at)
    MEM_W(-0X6BFC, ctx->r1) = ctx->r5;
    TRACE_RETURN()
    return;
    // 0x80011530: sw          $a1, -0x6BFC($at)
    MEM_W(-0X6BFC, ctx->r1) = ctx->r5;
;}
RECOMP_FUNC void func_80011534(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80011534: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80011538: swc1        $f12, -0x6BF8($at)
    MEM_W(-0X6BF8, ctx->r1) = ctx->f12.u32l;
    // 0x8001153C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80011540: jr          $ra
    // 0x80011544: swc1        $f14, -0x6BF4($at)
    MEM_W(-0X6BF4, ctx->r1) = ctx->f14.u32l;
    TRACE_RETURN()
    return;
    // 0x80011544: swc1        $f14, -0x6BF4($at)
    MEM_W(-0X6BF4, ctx->r1) = ctx->f14.u32l;
;}
RECOMP_FUNC void func_80011550(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80011550: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80011554: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80011558: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001155C: lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // 0x80011560: sw          $zero, 0x6AC4($at)
    MEM_W(0X6AC4, ctx->r1) = 0;
    // 0x80011564: addiu       $a0, $a0, 0x1584
    ctx->r4 = ADD32(ctx->r4, 0X1584);
    // 0x80011568: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8001156C: jal         0x80004CE0
    // 0x80011570: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80004CE0(rdram, ctx);
        goto after_0;
    // 0x80011570: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80011574: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80011578: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001157C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80011584(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80011584: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80011588: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001158C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80011590: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80011594: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80011598: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x8001159C: sh          $s4, -0x2E10($at)
    MEM_H(-0X2E10, ctx->r1) = ctx->r20;
    // 0x800115A0: addiu       $s2, $s2, 0x6AC8
    ctx->r18 = ADD32(ctx->r18, 0X6AC8);
    // 0x800115A4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800115A8: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    // 0x800115AC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800115B0: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800115B4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800115B8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800115BC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800115C0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800115C4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800115C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800115CC: jal         0x8004B248
    // 0x800115D0: sh          $zero, -0x6BD8($at)
    MEM_H(-0X6BD8, ctx->r1) = 0;
    func_8004B248(rdram, ctx);
        goto after_0;
    // 0x800115D0: sh          $zero, -0x6BD8($at)
    MEM_H(-0X6BD8, ctx->r1) = 0;
    after_0:
    // 0x800115D4: jal         0x8004D040
    // 0x800115D8: nop

    func_8004D040(rdram, ctx);
        goto after_1;
    // 0x800115D8: nop

    after_1:
    // 0x800115DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800115E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800115E4: jal         0x8000BD4C
    // 0x800115E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BD4C(rdram, ctx);
        goto after_2;
    // 0x800115E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x800115EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800115F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800115F4: jal         0x8000BDEC
    // 0x800115F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BDEC(rdram, ctx);
        goto after_3;
    // 0x800115F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x800115FC: addiu       $t6, $zero, 0x3E8
    ctx->r14 = ADD32(0, 0X3E8);
    // 0x80011600: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80011604: sw          $t6, -0x2CF8($at)
    MEM_W(-0X2CF8, ctx->r1) = ctx->r14;
    // 0x80011608: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001160C: addiu       $t7, $zero, 0x3E4
    ctx->r15 = ADD32(0, 0X3E4);
    // 0x80011610: sw          $t7, -0x2CF4($at)
    MEM_W(-0X2CF4, ctx->r1) = ctx->r15;
    // 0x80011614: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80011618: sh          $zero, -0x2CC4($at)
    MEM_H(-0X2CC4, ctx->r1) = 0;
    // 0x8001161C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80011620: jal         0x8000798C
    // 0x80011624: sh          $zero, -0x2CC2($at)
    MEM_H(-0X2CC2, ctx->r1) = 0;
    func_8000798C(rdram, ctx);
        goto after_4;
    // 0x80011624: sh          $zero, -0x2CC2($at)
    MEM_H(-0X2CC2, ctx->r1) = 0;
    after_4:
    // 0x80011628: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8001162C: lw          $t8, -0x2E40($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2E40);
    // 0x80011630: lui         $s7, 0x8001
    ctx->r23 = S32(0X8001 << 16);
    // 0x80011634: addiu       $s7, $s7, 0x2740
    ctx->r23 = ADD32(ctx->r23, 0X2740);
    // 0x80011638: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8001163C: bne         $t9, $zero, L_8001167C
    if (ctx->r25 != 0) {
        // 0x80011640: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_8001167C;
    }
    // 0x80011640: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80011644: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80011648: lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // 0x8001164C: addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    // 0x80011650: addiu       $a0, $a0, 0x1EA4
    ctx->r4 = ADD32(ctx->r4, 0X1EA4);
    // 0x80011654: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x80011658: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8001165C: jal         0x80004CE0
    // 0x80011660: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_80004CE0(rdram, ctx);
        goto after_5;
    // 0x80011660: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_5:
L_80011664:
    // 0x80011664: jal         0x8004D068
    // 0x80011668: nop

    func_8004D068(rdram, ctx);
        goto after_6;
    // 0x80011668: nop

    after_6:
    // 0x8001166C: jal         0x8000798C
    // 0x80011670: nop

    func_8000798C(rdram, ctx);
        goto after_7;
    // 0x80011670: nop

    after_7:
    // 0x80011674: b           L_80011664
    // 0x80011678: nop

        goto L_80011664;
    // 0x80011678: nop

L_8001167C:
    // 0x8001167C: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x80011680: addiu       $fp, $fp, -0x6BE0
    ctx->r30 = ADD32(ctx->r30, -0X6BE0);
    // 0x80011684: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
    // 0x80011688: addiu       $s3, $sp, 0x50
    ctx->r19 = ADD32(ctx->r29, 0X50);
    // 0x8001168C: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x80011690: sll         $a0, $s4, 16
    ctx->r4 = S32(ctx->r20 << 16);
L_80011694:
    // 0x80011694: sra         $t1, $a0, 16
    ctx->r9 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80011698: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x8001169C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800116A0: jal         0x8001A37C
    // 0x800116A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8001A37C(rdram, ctx);
        goto after_8;
    // 0x800116A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x800116A8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800116AC: sh          $zero, -0x6B7C($at)
    MEM_H(-0X6B7C, ctx->r1) = 0;
    // 0x800116B0: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
L_800116B4:
    // 0x800116B4: jal         0x8004D068
    // 0x800116B8: nop

    func_8004D068(rdram, ctx);
        goto after_9;
    // 0x800116B8: nop

    after_9:
    // 0x800116BC: sltiu       $at, $s0, 0x10
    ctx->r1 = ctx->r16 < 0X10 ? 1 : 0;
    // 0x800116C0: beq         $at, $zero, L_80011A58
    if (ctx->r1 == 0) {
        // 0x800116C4: sll         $t2, $s0, 2
        ctx->r10 = S32(ctx->r16 << 2);
            goto L_80011A58;
    }
    // 0x800116C4: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x800116C8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800116CC: addu        $at, $at, $t2
    gpr jr_addend_800116D4 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800116D0: lw          $t2, 0x6090($at)
    ctx->r10 = ADD32(ctx->r1, 0X6090);
    // 0x800116D4: jr          $t2
    // 0x800116D8: nop

    switch (jr_addend_800116D4 >> 2) {
        case 0: goto L_800116DC; break;
        case 1: goto L_80011708; break;
        case 2: goto L_80011728; break;
        case 3: goto L_80011788; break;
        case 4: goto L_800117A8; break;
        case 5: goto L_800117E0; break;
        case 6: goto L_8001187C; break;
        case 7: goto L_800118A8; break;
        case 8: goto L_800118C8; break;
        case 9: goto L_800118F4; break;
        case 10: goto L_80011908; break;
        case 11: goto L_80011940; break;
        case 12: goto L_8001198C; break;
        case 13: goto L_800119C4; break;
        case 14: goto L_800119F4; break;
        case 15: goto L_80011A2C; break;
        default: switch_error(__func__, 0x800116D4, 0x80076090);
    }
    // 0x800116D8: nop

L_800116DC:
    // 0x800116DC: lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // 0x800116E0: addiu       $a0, $a0, 0x2310
    ctx->r4 = ADD32(ctx->r4, 0X2310);
    // 0x800116E4: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x800116E8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x800116EC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x800116F0: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800116F4: jal         0x80004CE0
    // 0x800116F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    func_80004CE0(rdram, ctx);
        goto after_10;
    // 0x800116F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    after_10:
    // 0x800116FC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80011700: b           L_80011A58
    // 0x80011704: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_80011A58;
    // 0x80011704: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80011708:
    // 0x80011708: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8001170C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80011710: beq         $t3, $s4, L_80011A58
    if (ctx->r11 == ctx->r20) {
        // 0x80011714: nop
    
            goto L_80011A58;
    }
    // 0x80011714: nop

    // 0x80011718: jal         0x80004E5C
    // 0x8001171C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    func_80004E5C(rdram, ctx);
        goto after_11;
    // 0x8001171C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    after_11:
    // 0x80011720: b           L_80011A58
    // 0x80011724: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
        goto L_80011A58;
    // 0x80011724: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
L_80011728:
    // 0x80011728: bne         $s5, $zero, L_8001175C
    if (ctx->r21 != 0) {
        // 0x8001172C: addiu       $t4, $zero, 0x2
        ctx->r12 = ADD32(0, 0X2);
            goto L_8001175C;
    }
    // 0x8001172C: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80011730: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80011734: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80011738: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8001173C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80011740: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x80011744: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x80011748: jal         0x80004CE0
    // 0x8001174C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    func_80004CE0(rdram, ctx);
        goto after_12;
    // 0x8001174C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    after_12:
    // 0x80011750: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80011754: b           L_80011A58
    // 0x80011758: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
        goto L_80011A58;
    // 0x80011758: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
L_8001175C:
    // 0x8001175C: sw          $t4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r12;
    // 0x80011760: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80011764: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80011768: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8001176C: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x80011770: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x80011774: jal         0x80004CE0
    // 0x80011778: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    func_80004CE0(rdram, ctx);
        goto after_13;
    // 0x80011778: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    after_13:
    // 0x8001177C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80011780: b           L_80011A58
    // 0x80011784: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
        goto L_80011A58;
    // 0x80011784: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
L_80011788:
    // 0x80011788: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8001178C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80011790: bne         $t5, $s6, L_80011A58
    if (ctx->r13 != ctx->r22) {
        // 0x80011794: nop
    
            goto L_80011A58;
    }
    // 0x80011794: nop

    // 0x80011798: jal         0x80004E5C
    // 0x8001179C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    func_80004E5C(rdram, ctx);
        goto after_14;
    // 0x8001179C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    after_14:
    // 0x800117A0: b           L_80011A58
    // 0x800117A4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_80011A58;
    // 0x800117A4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800117A8:
    // 0x800117A8: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x800117AC: lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // 0x800117B0: addiu       $a0, $a0, 0x1FE0
    ctx->r4 = ADD32(ctx->r4, 0X1FE0);
    // 0x800117B4: ori         $t7, $t6, 0x2
    ctx->r15 = ctx->r14 | 0X2;
    // 0x800117B8: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x800117BC: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x800117C0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x800117C4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x800117C8: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800117CC: jal         0x80004CE0
    // 0x800117D0: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    func_80004CE0(rdram, ctx);
        goto after_15;
    // 0x800117D0: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    after_15:
    // 0x800117D4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800117D8: b           L_80011A58
    // 0x800117DC: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
        goto L_80011A58;
    // 0x800117DC: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
L_800117E0:
    // 0x800117E0: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800117E4: beq         $t8, $s4, L_80011A58
    if (ctx->r24 == ctx->r20) {
        // 0x800117E8: nop
    
            goto L_80011A58;
    }
    // 0x800117E8: nop

    // 0x800117EC: jal         0x80004E5C
    // 0x800117F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80004E5C(rdram, ctx);
        goto after_16;
    // 0x800117F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_16:
    // 0x800117F4: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x800117F8: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x800117FC: beq         $t9, $at, L_8001181C
    if (ctx->r25 == ctx->r1) {
        // 0x80011800: addiu       $at, $zero, 0x65
        ctx->r1 = ADD32(0, 0X65);
            goto L_8001181C;
    }
    // 0x80011800: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x80011804: beq         $t9, $at, L_80011824
    if (ctx->r25 == ctx->r1) {
        // 0x80011808: addiu       $at, $zero, 0x66
        ctx->r1 = ADD32(0, 0X66);
            goto L_80011824;
    }
    // 0x80011808: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x8001180C: beql        $t9, $at, L_80011868
    if (ctx->r25 == ctx->r1) {
        // 0x80011810: addiu       $s0, $zero, 0xE
        ctx->r16 = ADD32(0, 0XE);
            goto L_80011868;
    }
    goto skip_0;
    // 0x80011810: addiu       $s0, $zero, 0xE
    ctx->r16 = ADD32(0, 0XE);
    skip_0:
    // 0x80011814: b           L_8001186C
    // 0x80011818: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
        goto L_8001186C;
    // 0x80011818: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
L_8001181C:
    // 0x8001181C: b           L_80011868
    // 0x80011820: addiu       $s0, $zero, 0x6
    ctx->r16 = ADD32(0, 0X6);
        goto L_80011868;
    // 0x80011820: addiu       $s0, $zero, 0x6
    ctx->r16 = ADD32(0, 0X6);
L_80011824:
    // 0x80011824: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80011828: jal         0x8000798C
    // 0x8001182C: sh          $s4, -0x2D1E($at)
    MEM_H(-0X2D1E, ctx->r1) = ctx->r20;
    func_8000798C(rdram, ctx);
        goto after_17;
    // 0x8001182C: sh          $s4, -0x2D1E($at)
    MEM_H(-0X2D1E, ctx->r1) = ctx->r20;
    after_17:
    // 0x80011830: jal         0x8000798C
    // 0x80011834: nop

    func_8000798C(rdram, ctx);
        goto after_18;
    // 0x80011834: nop

    after_18:
    // 0x80011838: jal         0x8000798C
    // 0x8001183C: nop

    func_8000798C(rdram, ctx);
        goto after_19;
    // 0x8001183C: nop

    after_19:
    // 0x80011840: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80011844: lh          $t0, -0x2D1A($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X2D1A);
    // 0x80011848: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8001184C: beq         $t0, $zero, L_8001185C
    if (ctx->r8 == 0) {
        // 0x80011850: nop
    
            goto L_8001185C;
    }
    // 0x80011850: nop

    // 0x80011854: b           L_80011868
    // 0x80011858: addiu       $s0, $zero, 0xA
    ctx->r16 = ADD32(0, 0XA);
        goto L_80011868;
    // 0x80011858: addiu       $s0, $zero, 0xA
    ctx->r16 = ADD32(0, 0XA);
L_8001185C:
    // 0x8001185C: b           L_80011868
    // 0x80011860: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_80011868;
    // 0x80011860: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80011864: addiu       $s0, $zero, 0xE
    ctx->r16 = ADD32(0, 0XE);
L_80011868:
    // 0x80011868: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
L_8001186C:
    // 0x8001186C: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80011870: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x80011874: b           L_80011A58
    // 0x80011878: sw          $t2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r10;
        goto L_80011A58;
    // 0x80011878: sw          $t2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r10;
L_8001187C:
    // 0x8001187C: lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // 0x80011880: addiu       $a0, $a0, 0x1AA0
    ctx->r4 = ADD32(ctx->r4, 0X1AA0);
    // 0x80011884: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80011888: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8001188C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80011890: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x80011894: jal         0x80004CE0
    // 0x80011898: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    func_80004CE0(rdram, ctx);
        goto after_20;
    // 0x80011898: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    after_20:
    // 0x8001189C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800118A0: b           L_80011A58
    // 0x800118A4: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
        goto L_80011A58;
    // 0x800118A4: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
L_800118A8:
    // 0x800118A8: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x800118AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800118B0: beq         $t3, $s4, L_80011A58
    if (ctx->r11 == ctx->r20) {
        // 0x800118B4: nop
    
            goto L_80011A58;
    }
    // 0x800118B4: nop

    // 0x800118B8: jal         0x80004E5C
    // 0x800118BC: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    func_80004E5C(rdram, ctx);
        goto after_21;
    // 0x800118BC: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    after_21:
    // 0x800118C0: b           L_80011A58
    // 0x800118C4: addiu       $s0, $zero, 0xC
    ctx->r16 = ADD32(0, 0XC);
        goto L_80011A58;
    // 0x800118C4: addiu       $s0, $zero, 0xC
    ctx->r16 = ADD32(0, 0XC);
L_800118C8:
    // 0x800118C8: lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // 0x800118CC: addiu       $a0, $a0, 0x1C80
    ctx->r4 = ADD32(ctx->r4, 0X1C80);
    // 0x800118D0: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x800118D4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x800118D8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x800118DC: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800118E0: jal         0x80004CE0
    // 0x800118E4: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    func_80004CE0(rdram, ctx);
        goto after_22;
    // 0x800118E4: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    after_22:
    // 0x800118E8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800118EC: b           L_80011A58
    // 0x800118F0: addiu       $s0, $zero, 0x9
    ctx->r16 = ADD32(0, 0X9);
        goto L_80011A58;
    // 0x800118F0: addiu       $s0, $zero, 0x9
    ctx->r16 = ADD32(0, 0X9);
L_800118F4:
    // 0x800118F4: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x800118F8: beq         $t4, $s4, L_80011A58
    if (ctx->r12 == ctx->r20) {
        // 0x800118FC: nop
    
            goto L_80011A58;
    }
    // 0x800118FC: nop

    // 0x80011900: jal         0x80004E5C
    // 0x80011904: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80004E5C(rdram, ctx);
        goto after_23;
    // 0x80011904: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_23:
L_80011908:
    // 0x80011908: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x8001190C: lui         $a0, 0x8002
    ctx->r4 = S32(0X8002 << 16);
    // 0x80011910: addiu       $a0, $a0, -0x4DB0
    ctx->r4 = ADD32(ctx->r4, -0X4DB0);
    // 0x80011914: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x80011918: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x8001191C: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80011920: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80011924: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80011928: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x8001192C: jal         0x80004CE0
    // 0x80011930: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    func_80004CE0(rdram, ctx);
        goto after_24;
    // 0x80011930: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    after_24:
    // 0x80011934: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80011938: b           L_80011A58
    // 0x8001193C: addiu       $s0, $zero, 0xB
    ctx->r16 = ADD32(0, 0XB);
        goto L_80011A58;
    // 0x8001193C: addiu       $s0, $zero, 0xB
    ctx->r16 = ADD32(0, 0XB);
L_80011940:
    // 0x80011940: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80011944: beq         $t7, $s4, L_80011A58
    if (ctx->r15 == ctx->r20) {
        // 0x80011948: nop
    
            goto L_80011A58;
    }
    // 0x80011948: nop

    // 0x8001194C: jal         0x80004E5C
    // 0x80011950: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80004E5C(rdram, ctx);
        goto after_25;
    // 0x80011950: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_25:
    // 0x80011954: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x80011958: lw          $t0, 0x0($fp)
    ctx->r8 = MEM_W(ctx->r30, 0X0);
    // 0x8001195C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80011960: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x80011964: bne         $s6, $t0, L_80011984
    if (ctx->r22 != ctx->r8) {
        // 0x80011968: sw          $t9, 0x0($s2)
        MEM_W(0X0, ctx->r18) = ctx->r25;
            goto L_80011984;
    }
    // 0x80011968: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x8001196C: sw          $zero, 0x0($fp)
    MEM_W(0X0, ctx->r30) = 0;
    // 0x80011970: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80011974: jal         0x8000798C
    // 0x80011978: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    func_8000798C(rdram, ctx);
        goto after_26;
    // 0x80011978: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    after_26:
    // 0x8001197C: b           L_80011694
    // 0x80011980: sll         $a0, $s4, 16
    ctx->r4 = S32(ctx->r20 << 16);
        goto L_80011694;
    // 0x80011980: sll         $a0, $s4, 16
    ctx->r4 = S32(ctx->r20 << 16);
L_80011984:
    // 0x80011984: b           L_80011A58
    // 0x80011988: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
        goto L_80011A58;
    // 0x80011988: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
L_8001198C:
    // 0x8001198C: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80011990: lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // 0x80011994: addiu       $a0, $a0, 0x2974
    ctx->r4 = ADD32(ctx->r4, 0X2974);
    // 0x80011998: ori         $t2, $t1, 0x4
    ctx->r10 = ctx->r9 | 0X4;
    // 0x8001199C: sw          $t2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r10;
    // 0x800119A0: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x800119A4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x800119A8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x800119AC: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800119B0: jal         0x80004CE0
    // 0x800119B4: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    func_80004CE0(rdram, ctx);
        goto after_27;
    // 0x800119B4: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    after_27:
    // 0x800119B8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800119BC: b           L_80011A58
    // 0x800119C0: addiu       $s0, $zero, 0xD
    ctx->r16 = ADD32(0, 0XD);
        goto L_80011A58;
    // 0x800119C0: addiu       $s0, $zero, 0xD
    ctx->r16 = ADD32(0, 0XD);
L_800119C4:
    // 0x800119C4: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x800119C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800119CC: beq         $t3, $s4, L_80011A58
    if (ctx->r11 == ctx->r20) {
        // 0x800119D0: nop
    
            goto L_80011A58;
    }
    // 0x800119D0: nop

    // 0x800119D4: jal         0x80004E5C
    // 0x800119D8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    func_80004E5C(rdram, ctx);
        goto after_28;
    // 0x800119D8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    after_28:
    // 0x800119DC: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x800119E0: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x800119E4: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
    // 0x800119E8: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x800119EC: b           L_80011A58
    // 0x800119F0: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
        goto L_80011A58;
    // 0x800119F0: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
L_800119F4:
    // 0x800119F4: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x800119F8: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800119FC: addiu       $a0, $a0, 0x4760
    ctx->r4 = ADD32(ctx->r4, 0X4760);
    // 0x80011A00: ori         $t7, $t6, 0x8
    ctx->r15 = ctx->r14 | 0X8;
    // 0x80011A04: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80011A08: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80011A0C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80011A10: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80011A14: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x80011A18: jal         0x80004CE0
    // 0x80011A1C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    func_80004CE0(rdram, ctx);
        goto after_29;
    // 0x80011A1C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    after_29:
    // 0x80011A20: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80011A24: b           L_80011A58
    // 0x80011A28: addiu       $s0, $zero, 0xF
    ctx->r16 = ADD32(0, 0XF);
        goto L_80011A58;
    // 0x80011A28: addiu       $s0, $zero, 0xF
    ctx->r16 = ADD32(0, 0XF);
L_80011A2C:
    // 0x80011A2C: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80011A30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80011A34: beq         $t8, $s4, L_80011A58
    if (ctx->r24 == ctx->r20) {
        // 0x80011A38: nop
    
            goto L_80011A58;
    }
    // 0x80011A38: nop

    // 0x80011A3C: jal         0x80004E5C
    // 0x80011A40: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    func_80004E5C(rdram, ctx);
        goto after_30;
    // 0x80011A40: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    after_30:
    // 0x80011A44: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80011A48: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80011A4C: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
    // 0x80011A50: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x80011A54: sw          $t0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r8;
L_80011A58:
    // 0x80011A58: jal         0x8000798C
    // 0x80011A5C: nop

    func_8000798C(rdram, ctx);
        goto after_31;
    // 0x80011A5C: nop

    after_31:
    // 0x80011A60: b           L_800116B4
    // 0x80011A64: nop

        goto L_800116B4;
    // 0x80011A64: nop

    // 0x80011A68: nop

    // 0x80011A6C: nop

    // 0x80011A70: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80011A74: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80011A78: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80011A7C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80011A80: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80011A84: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80011A88: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80011A8C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80011A90: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80011A94: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80011A98: jr          $ra
    // 0x80011A9C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    TRACE_RETURN()
    return;
    // 0x80011A9C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80011AA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80011AA0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80011AA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80011AA8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80011AAC: addiu       $a0, $zero, -0xA
    ctx->r4 = ADD32(0, -0XA);
    // 0x80011AB0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80011AB4: jal         0x8004D134
    // 0x80011AB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004D134(rdram, ctx);
        goto after_0;
    // 0x80011AB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80011ABC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80011AC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80011AC4: jal         0x8000BD4C
    // 0x80011AC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BD4C(rdram, ctx);
        goto after_1;
    // 0x80011AC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80011ACC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80011AD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80011AD4: jal         0x8000BDEC
    // 0x80011AD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BDEC(rdram, ctx);
        goto after_2;
    // 0x80011AD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80011ADC: addiu       $t6, $zero, 0x3E8
    ctx->r14 = ADD32(0, 0X3E8);
    // 0x80011AE0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80011AE4: sw          $t6, -0x2CF8($at)
    MEM_W(-0X2CF8, ctx->r1) = ctx->r14;
    // 0x80011AE8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80011AEC: addiu       $t7, $zero, 0x3D0
    ctx->r15 = ADD32(0, 0X3D0);
    // 0x80011AF0: sw          $t7, -0x2CF4($at)
    MEM_W(-0X2CF4, ctx->r1) = ctx->r15;
    // 0x80011AF4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80011AF8: sh          $zero, -0x2CC4($at)
    MEM_H(-0X2CC4, ctx->r1) = 0;
    // 0x80011AFC: jal         0x8004B1E0
    // 0x80011B00: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8004B1E0(rdram, ctx);
        goto after_3;
    // 0x80011B00: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80011B04: jal         0x8000798C
    // 0x80011B08: nop

    func_8000798C(rdram, ctx);
        goto after_4;
    // 0x80011B08: nop

    after_4:
    // 0x80011B0C: jal         0x8000798C
    // 0x80011B10: nop

    func_8000798C(rdram, ctx);
        goto after_5;
    // 0x80011B10: nop

    after_5:
    // 0x80011B14: jal         0x8000798C
    // 0x80011B18: nop

    func_8000798C(rdram, ctx);
        goto after_6;
    // 0x80011B18: nop

    after_6:
    // 0x80011B1C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80011B20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80011B24: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x80011B28: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x80011B2C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80011B30: jal         0x8004C580
    // 0x80011B34: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_7;
    // 0x80011B34: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_7:
    // 0x80011B38: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80011B3C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80011B40: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80011B44: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80011B48: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80011B4C: addiu       $a0, $a0, -0x6C40
    ctx->r4 = ADD32(ctx->r4, -0X6C40);
    // 0x80011B50: addiu       $v1, $v1, -0x6C50
    ctx->r3 = ADD32(ctx->r3, -0X6C50);
    // 0x80011B54: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x80011B58: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x80011B5C: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x80011B60: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x80011B64: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x80011B68: jal         0x8000798C
    // 0x80011B6C: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
    func_8000798C(rdram, ctx);
        goto after_8;
    // 0x80011B6C: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
    after_8:
    // 0x80011B70: jal         0x8000798C
    // 0x80011B74: nop

    func_8000798C(rdram, ctx);
        goto after_9;
    // 0x80011B74: nop

    after_9:
    // 0x80011B78: jal         0x8000798C
    // 0x80011B7C: nop

    func_8000798C(rdram, ctx);
        goto after_10;
    // 0x80011B7C: nop

    after_10:
    // 0x80011B80: jal         0x8004D1F0
    // 0x80011B84: nop

    func_8004D1F0(rdram, ctx);
        goto after_11;
    // 0x80011B84: nop

    after_11:
    // 0x80011B88: beql        $v0, $zero, L_80011BAC
    if (ctx->r2 == 0) {
        // 0x80011B8C: addiu       $v0, $zero, 0x5A
        ctx->r2 = ADD32(0, 0X5A);
            goto L_80011BAC;
    }
    goto skip_0;
    // 0x80011B8C: addiu       $v0, $zero, 0x5A
    ctx->r2 = ADD32(0, 0X5A);
    skip_0:
L_80011B90:
    // 0x80011B90: jal         0x8000798C
    // 0x80011B94: nop

    func_8000798C(rdram, ctx);
        goto after_12;
    // 0x80011B94: nop

    after_12:
    // 0x80011B98: jal         0x8004D1F0
    // 0x80011B9C: nop

    func_8004D1F0(rdram, ctx);
        goto after_13;
    // 0x80011B9C: nop

    after_13:
    // 0x80011BA0: bne         $v0, $zero, L_80011B90
    if (ctx->r2 != 0) {
        // 0x80011BA4: nop
    
            goto L_80011B90;
    }
    // 0x80011BA4: nop

    // 0x80011BA8: addiu       $v0, $zero, 0x5A
    ctx->r2 = ADD32(0, 0X5A);
L_80011BAC:
    // 0x80011BAC: beq         $v0, $zero, L_80011BC0
    if (ctx->r2 == 0) {
        // 0x80011BB0: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_80011BC0;
    }
    // 0x80011BB0: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80011BB4: lhu         $t8, -0x2E5A($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X2E5A);
    // 0x80011BB8: andi        $t9, $t8, 0x1000
    ctx->r25 = ctx->r24 & 0X1000;
    // 0x80011BBC: beq         $t9, $zero, L_80011C3C
    if (ctx->r25 == 0) {
        // 0x80011BC0: addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
            goto L_80011C3C;
    }
L_80011BC0:
    // 0x80011BC0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80011BC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80011BC8: jal         0x8004D134
    // 0x80011BCC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_8004D134(rdram, ctx);
        goto after_14;
    // 0x80011BCC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_14:
    // 0x80011BD0: jal         0x8004D1F0
    // 0x80011BD4: nop

    func_8004D1F0(rdram, ctx);
        goto after_15;
    // 0x80011BD4: nop

    after_15:
    // 0x80011BD8: beql        $v0, $zero, L_80011BFC
    if (ctx->r2 == 0) {
        // 0x80011BDC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80011BFC;
    }
    goto skip_1;
    // 0x80011BDC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_1:
L_80011BE0:
    // 0x80011BE0: jal         0x8000798C
    // 0x80011BE4: nop

    func_8000798C(rdram, ctx);
        goto after_16;
    // 0x80011BE4: nop

    after_16:
    // 0x80011BE8: jal         0x8004D1F0
    // 0x80011BEC: nop

    func_8004D1F0(rdram, ctx);
        goto after_17;
    // 0x80011BEC: nop

    after_17:
    // 0x80011BF0: bne         $v0, $zero, L_80011BE0
    if (ctx->r2 != 0) {
        // 0x80011BF4: nop
    
            goto L_80011BE0;
    }
    // 0x80011BF4: nop

    // 0x80011BF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80011BFC:
    // 0x80011BFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80011C00: jal         0x8004C4D8
    // 0x80011C04: addiu       $v0, $zero, 0x5A
    ctx->r2 = ADD32(0, 0X5A);
    func_8004C4D8(rdram, ctx);
        goto after_18;
    // 0x80011C04: addiu       $v0, $zero, 0x5A
    ctx->r2 = ADD32(0, 0X5A);
    after_18:
    // 0x80011C08: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80011C0C: jal         0x8004C4D8
    // 0x80011C10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004C4D8(rdram, ctx);
        goto after_19;
    // 0x80011C10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x80011C14: jal         0x8004B21C
    // 0x80011C18: nop

    func_8004B21C(rdram, ctx);
        goto after_20;
    // 0x80011C18: nop

    after_20:
    // 0x80011C1C: jal         0x8000798C
    // 0x80011C20: nop

    func_8000798C(rdram, ctx);
        goto after_21;
    // 0x80011C20: nop

    after_21:
    // 0x80011C24: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80011C28: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
L_80011C2C:
    // 0x80011C2C: jal         0x8000798C
    // 0x80011C30: nop

    func_8000798C(rdram, ctx);
        goto after_22;
    // 0x80011C30: nop

    after_22:
    // 0x80011C34: b           L_80011C2C
    // 0x80011C38: nop

        goto L_80011C2C;
    // 0x80011C38: nop

L_80011C3C:
    // 0x80011C3C: beq         $v0, $zero, L_80011C50
    if (ctx->r2 == 0) {
        // 0x80011C40: nop
    
            goto L_80011C50;
    }
    // 0x80011C40: nop

    // 0x80011C44: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80011C48: sll         $t1, $v0, 16
    ctx->r9 = S32(ctx->r2 << 16);
    // 0x80011C4C: sra         $v0, $t1, 16
    ctx->r2 = S32(SIGNED(ctx->r9) >> 16);
L_80011C50:
    // 0x80011C50: jal         0x8000798C
    // 0x80011C54: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    func_8000798C(rdram, ctx);
        goto after_23;
    // 0x80011C54: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    after_23:
    // 0x80011C58: b           L_80011BAC
    // 0x80011C5C: lh          $v0, 0x26($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X26);
        goto L_80011BAC;
    // 0x80011C5C: lh          $v0, 0x26($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X26);
    // 0x80011C60: nop

    // 0x80011C64: nop

    // 0x80011C68: nop

    // 0x80011C6C: nop

    // 0x80011C70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80011C74: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80011C78: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80011C80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80011C80: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80011C84: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80011C88: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80011C8C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80011C90: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80011C94: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80011C98: addiu       $a0, $zero, -0xA
    ctx->r4 = ADD32(0, -0XA);
    // 0x80011C9C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80011CA0: jal         0x8004D134
    // 0x80011CA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004D134(rdram, ctx);
        goto after_0;
    // 0x80011CA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80011CA8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80011CAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80011CB0: jal         0x8000BD4C
    // 0x80011CB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BD4C(rdram, ctx);
        goto after_1;
    // 0x80011CB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80011CB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80011CBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80011CC0: jal         0x8000BDEC
    // 0x80011CC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BDEC(rdram, ctx);
        goto after_2;
    // 0x80011CC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80011CC8: addiu       $t6, $zero, 0x3E8
    ctx->r14 = ADD32(0, 0X3E8);
    // 0x80011CCC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80011CD0: sw          $t6, -0x2CF8($at)
    MEM_W(-0X2CF8, ctx->r1) = ctx->r14;
    // 0x80011CD4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80011CD8: addiu       $t7, $zero, 0x3D0
    ctx->r15 = ADD32(0, 0X3D0);
    // 0x80011CDC: sw          $t7, -0x2CF4($at)
    MEM_W(-0X2CF4, ctx->r1) = ctx->r15;
    // 0x80011CE0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80011CE4: sh          $zero, -0x2CC4($at)
    MEM_H(-0X2CC4, ctx->r1) = 0;
    // 0x80011CE8: jal         0x8004B1E0
    // 0x80011CEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8004B1E0(rdram, ctx);
        goto after_3;
    // 0x80011CEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80011CF0: jal         0x8000798C
    // 0x80011CF4: nop

    func_8000798C(rdram, ctx);
        goto after_4;
    // 0x80011CF4: nop

    after_4:
    // 0x80011CF8: jal         0x8000798C
    // 0x80011CFC: nop

    func_8000798C(rdram, ctx);
        goto after_5;
    // 0x80011CFC: nop

    after_5:
    // 0x80011D00: jal         0x8000798C
    // 0x80011D04: nop

    func_8000798C(rdram, ctx);
        goto after_6;
    // 0x80011D04: nop

    after_6:
    // 0x80011D08: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80011D0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80011D10: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x80011D14: addiu       $a3, $zero, 0xD
    ctx->r7 = ADD32(0, 0XD);
    // 0x80011D18: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80011D1C: jal         0x8004C580
    // 0x80011D20: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_7;
    // 0x80011D20: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_7:
    // 0x80011D24: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80011D28: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80011D2C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80011D30: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80011D34: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80011D38: addiu       $a0, $a0, -0x6C40
    ctx->r4 = ADD32(ctx->r4, -0X6C40);
    // 0x80011D3C: addiu       $v1, $v1, -0x6C50
    ctx->r3 = ADD32(ctx->r3, -0X6C50);
    // 0x80011D40: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x80011D44: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x80011D48: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x80011D4C: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x80011D50: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x80011D54: jal         0x8000798C
    // 0x80011D58: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
    func_8000798C(rdram, ctx);
        goto after_8;
    // 0x80011D58: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
    after_8:
    // 0x80011D5C: jal         0x8000798C
    // 0x80011D60: nop

    func_8000798C(rdram, ctx);
        goto after_9;
    // 0x80011D60: nop

    after_9:
    // 0x80011D64: jal         0x8000798C
    // 0x80011D68: nop

    func_8000798C(rdram, ctx);
        goto after_10;
    // 0x80011D68: nop

    after_10:
    // 0x80011D6C: jal         0x8004D1F0
    // 0x80011D70: nop

    func_8004D1F0(rdram, ctx);
        goto after_11;
    // 0x80011D70: nop

    after_11:
    // 0x80011D74: beql        $v0, $zero, L_80011D98
    if (ctx->r2 == 0) {
        // 0x80011D78: addiu       $s0, $zero, 0x5A
        ctx->r16 = ADD32(0, 0X5A);
            goto L_80011D98;
    }
    goto skip_0;
    // 0x80011D78: addiu       $s0, $zero, 0x5A
    ctx->r16 = ADD32(0, 0X5A);
    skip_0:
L_80011D7C:
    // 0x80011D7C: jal         0x8000798C
    // 0x80011D80: nop

    func_8000798C(rdram, ctx);
        goto after_12;
    // 0x80011D80: nop

    after_12:
    // 0x80011D84: jal         0x8004D1F0
    // 0x80011D88: nop

    func_8004D1F0(rdram, ctx);
        goto after_13;
    // 0x80011D88: nop

    after_13:
    // 0x80011D8C: bne         $v0, $zero, L_80011D7C
    if (ctx->r2 != 0) {
        // 0x80011D90: nop
    
            goto L_80011D7C;
    }
    // 0x80011D90: nop

    // 0x80011D94: addiu       $s0, $zero, 0x5A
    ctx->r16 = ADD32(0, 0X5A);
L_80011D98:
    // 0x80011D98: beq         $s0, $zero, L_80011DB8
    if (ctx->r16 == 0) {
        // 0x80011D9C: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_80011DB8;
    }
    // 0x80011D9C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80011DA0: lhu         $t8, -0x2E5A($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X2E5A);
    // 0x80011DA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80011DA8: addiu       $a1, $zero, -0x54
    ctx->r5 = ADD32(0, -0X54);
    // 0x80011DAC: andi        $t9, $t8, 0x1000
    ctx->r25 = ctx->r24 & 0X1000;
    // 0x80011DB0: beq         $t9, $zero, L_80011E40
    if (ctx->r25 == 0) {
        // 0x80011DB4: sll         $t2, $s1, 24
        ctx->r10 = S32(ctx->r17 << 24);
            goto L_80011E40;
    }
    // 0x80011DB4: sll         $t2, $s1, 24
    ctx->r10 = S32(ctx->r17 << 24);
L_80011DB8:
    // 0x80011DB8: jal         0x80044480
    // 0x80011DBC: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    func_80044480(rdram, ctx);
        goto after_14;
    // 0x80011DBC: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_14:
    // 0x80011DC0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80011DC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80011DC8: jal         0x8004D134
    // 0x80011DCC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_8004D134(rdram, ctx);
        goto after_15;
    // 0x80011DCC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_15:
    // 0x80011DD0: jal         0x8004D1F0
    // 0x80011DD4: nop

    func_8004D1F0(rdram, ctx);
        goto after_16;
    // 0x80011DD4: nop

    after_16:
    // 0x80011DD8: beql        $v0, $zero, L_80011DFC
    if (ctx->r2 == 0) {
        // 0x80011DDC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80011DFC;
    }
    goto skip_1;
    // 0x80011DDC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_1:
L_80011DE0:
    // 0x80011DE0: jal         0x8000798C
    // 0x80011DE4: nop

    func_8000798C(rdram, ctx);
        goto after_17;
    // 0x80011DE4: nop

    after_17:
    // 0x80011DE8: jal         0x8004D1F0
    // 0x80011DEC: nop

    func_8004D1F0(rdram, ctx);
        goto after_18;
    // 0x80011DEC: nop

    after_18:
    // 0x80011DF0: bne         $v0, $zero, L_80011DE0
    if (ctx->r2 != 0) {
        // 0x80011DF4: nop
    
            goto L_80011DE0;
    }
    // 0x80011DF4: nop

    // 0x80011DF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80011DFC:
    // 0x80011DFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80011E00: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80011E04: jal         0x8004C4D8
    // 0x80011E08: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    func_8004C4D8(rdram, ctx);
        goto after_19;
    // 0x80011E08: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_19:
    // 0x80011E0C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80011E10: jal         0x8004C4D8
    // 0x80011E14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004C4D8(rdram, ctx);
        goto after_20;
    // 0x80011E14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
    // 0x80011E18: jal         0x8004B21C
    // 0x80011E1C: nop

    func_8004B21C(rdram, ctx);
        goto after_21;
    // 0x80011E1C: nop

    after_21:
    // 0x80011E20: jal         0x8000798C
    // 0x80011E24: nop

    func_8000798C(rdram, ctx);
        goto after_22;
    // 0x80011E24: nop

    after_22:
    // 0x80011E28: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80011E2C: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
L_80011E30:
    // 0x80011E30: jal         0x8000798C
    // 0x80011E34: nop

    func_8000798C(rdram, ctx);
        goto after_23;
    // 0x80011E34: nop

    after_23:
    // 0x80011E38: b           L_80011E30
    // 0x80011E3C: nop

        goto L_80011E30;
    // 0x80011E3C: nop

L_80011E40:
    // 0x80011E40: sra         $a2, $t2, 16
    ctx->r6 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80011E44: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80011E48: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80011E4C: jal         0x8004C580
    // 0x80011E50: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_24;
    // 0x80011E50: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_24:
    // 0x80011E54: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80011E58: lh          $t6, -0x2D1A($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X2D1A);
    // 0x80011E5C: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80011E60: sll         $t4, $s1, 16
    ctx->r12 = S32(ctx->r17 << 16);
    // 0x80011E64: beq         $t6, $zero, L_80011E70
    if (ctx->r14 == 0) {
        // 0x80011E68: sra         $s1, $t4, 16
        ctx->r17 = S32(SIGNED(ctx->r12) >> 16);
            goto L_80011E70;
    }
    // 0x80011E68: sra         $s1, $t4, 16
    ctx->r17 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80011E6C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80011E70:
    // 0x80011E70: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80011E74: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80011E78: jal         0x8000798C
    // 0x80011E7C: sh          $t7, -0x2D1E($at)
    MEM_H(-0X2D1E, ctx->r1) = ctx->r15;
    func_8000798C(rdram, ctx);
        goto after_25;
    // 0x80011E7C: sh          $t7, -0x2D1E($at)
    MEM_H(-0X2D1E, ctx->r1) = ctx->r15;
    after_25:
    // 0x80011E80: b           L_80011D98
    // 0x80011E84: nop

        goto L_80011D98;
    // 0x80011E84: nop

    // 0x80011E88: nop

    // 0x80011E8C: nop

    // 0x80011E90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80011E94: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80011E98: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80011E9C: jr          $ra
    // 0x80011EA0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    TRACE_RETURN()
    return;
    // 0x80011EA0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80011EA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80011EA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80011EA8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80011EAC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80011EB0: addiu       $a0, $zero, -0xA
    ctx->r4 = ADD32(0, -0XA);
    // 0x80011EB4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80011EB8: jal         0x8004D134
    // 0x80011EBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004D134(rdram, ctx);
        goto after_0;
    // 0x80011EBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80011EC0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80011EC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80011EC8: jal         0x8000BD4C
    // 0x80011ECC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BD4C(rdram, ctx);
        goto after_1;
    // 0x80011ECC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80011ED0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80011ED4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80011ED8: jal         0x8000BDEC
    // 0x80011EDC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BDEC(rdram, ctx);
        goto after_2;
    // 0x80011EDC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80011EE0: addiu       $t6, $zero, 0x3E8
    ctx->r14 = ADD32(0, 0X3E8);
    // 0x80011EE4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80011EE8: sw          $t6, -0x2CF8($at)
    MEM_W(-0X2CF8, ctx->r1) = ctx->r14;
    // 0x80011EEC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80011EF0: addiu       $t7, $zero, 0x3D0
    ctx->r15 = ADD32(0, 0X3D0);
    // 0x80011EF4: sw          $t7, -0x2CF4($at)
    MEM_W(-0X2CF4, ctx->r1) = ctx->r15;
    // 0x80011EF8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80011EFC: sh          $zero, -0x2CC4($at)
    MEM_H(-0X2CC4, ctx->r1) = 0;
    // 0x80011F00: jal         0x8004B1E0
    // 0x80011F04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8004B1E0(rdram, ctx);
        goto after_3;
    // 0x80011F04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80011F08: jal         0x8000798C
    // 0x80011F0C: nop

    func_8000798C(rdram, ctx);
        goto after_4;
    // 0x80011F0C: nop

    after_4:
    // 0x80011F10: jal         0x8000798C
    // 0x80011F14: nop

    func_8000798C(rdram, ctx);
        goto after_5;
    // 0x80011F14: nop

    after_5:
    // 0x80011F18: jal         0x8000798C
    // 0x80011F1C: nop

    func_8000798C(rdram, ctx);
        goto after_6;
    // 0x80011F1C: nop

    after_6:
    // 0x80011F20: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80011F24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80011F28: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x80011F2C: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    // 0x80011F30: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80011F34: jal         0x8004C580
    // 0x80011F38: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_7;
    // 0x80011F38: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_7:
    // 0x80011F3C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80011F40: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80011F44: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80011F48: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80011F4C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80011F50: addiu       $a0, $a0, -0x6C40
    ctx->r4 = ADD32(ctx->r4, -0X6C40);
    // 0x80011F54: addiu       $v1, $v1, -0x6C50
    ctx->r3 = ADD32(ctx->r3, -0X6C50);
    // 0x80011F58: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x80011F5C: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x80011F60: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x80011F64: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x80011F68: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x80011F6C: jal         0x8000798C
    // 0x80011F70: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
    func_8000798C(rdram, ctx);
        goto after_8;
    // 0x80011F70: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
    after_8:
    // 0x80011F74: jal         0x8000798C
    // 0x80011F78: nop

    func_8000798C(rdram, ctx);
        goto after_9;
    // 0x80011F78: nop

    after_9:
    // 0x80011F7C: jal         0x8000798C
    // 0x80011F80: nop

    func_8000798C(rdram, ctx);
        goto after_10;
    // 0x80011F80: nop

    after_10:
    // 0x80011F84: jal         0x8004D1F0
    // 0x80011F88: nop

    func_8004D1F0(rdram, ctx);
        goto after_11;
    // 0x80011F88: nop

    after_11:
    // 0x80011F8C: beq         $v0, $zero, L_80011FAC
    if (ctx->r2 == 0) {
        // 0x80011F90: nop
    
            goto L_80011FAC;
    }
    // 0x80011F90: nop

L_80011F94:
    // 0x80011F94: jal         0x8000798C
    // 0x80011F98: nop

    func_8000798C(rdram, ctx);
        goto after_12;
    // 0x80011F98: nop

    after_12:
    // 0x80011F9C: jal         0x8004D1F0
    // 0x80011FA0: nop

    func_8004D1F0(rdram, ctx);
        goto after_13;
    // 0x80011FA0: nop

    after_13:
    // 0x80011FA4: bne         $v0, $zero, L_80011F94
    if (ctx->r2 != 0) {
        // 0x80011FA8: nop
    
            goto L_80011F94;
    }
    // 0x80011FA8: nop

L_80011FAC:
    // 0x80011FAC: jal         0x8000798C
    // 0x80011FB0: nop

    func_8000798C(rdram, ctx);
        goto after_14;
    // 0x80011FB0: nop

    after_14:
    // 0x80011FB4: b           L_80011FAC
    // 0x80011FB8: nop

        goto L_80011FAC;
    // 0x80011FB8: nop

    // 0x80011FBC: nop

    // 0x80011FC0: nop

    // 0x80011FC4: nop

    // 0x80011FC8: nop

    // 0x80011FCC: nop

    // 0x80011FD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80011FD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80011FD8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80011FE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80011FE0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80011FE4: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80011FE8: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80011FEC: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80011FF0: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80011FF4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80011FF8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80011FFC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80012000: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80012004: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x80012008: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x8001200C: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x80012010: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80012014: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80012018: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x8001201C: addiu       $s2, $zero, 0xF0
    ctx->r18 = ADD32(0, 0XF0);
    // 0x80012020: addiu       $fp, $fp, -0x2E5C
    ctx->r30 = ADD32(ctx->r30, -0X2E5C);
    // 0x80012024: addiu       $s7, $s7, -0x6B8E
    ctx->r23 = ADD32(ctx->r23, -0X6B8E);
    // 0x80012028: addiu       $s6, $s6, -0x2E5A
    ctx->r22 = ADD32(ctx->r22, -0X2E5A);
    // 0x8001202C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80012030: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80012034: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80012038: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8001203C: addiu       $a0, $zero, -0xA
    ctx->r4 = ADD32(0, -0XA);
L_80012040:
    // 0x80012040: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80012044: jal         0x8004D134
    // 0x80012048: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004D134(rdram, ctx);
        goto after_0;
    // 0x80012048: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8001204C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80012050: sh          $zero, -0x2CC4($at)
    MEM_H(-0X2CC4, ctx->r1) = 0;
    // 0x80012054: jal         0x8004B1E0
    // 0x80012058: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8004B1E0(rdram, ctx);
        goto after_1;
    // 0x80012058: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8001205C: jal         0x8000798C
    // 0x80012060: nop

    func_8000798C(rdram, ctx);
        goto after_2;
    // 0x80012060: nop

    after_2:
    // 0x80012064: jal         0x8000798C
    // 0x80012068: nop

    func_8000798C(rdram, ctx);
        goto after_3;
    // 0x80012068: nop

    after_3:
    // 0x8001206C: jal         0x8000798C
    // 0x80012070: nop

    func_8000798C(rdram, ctx);
        goto after_4;
    // 0x80012070: nop

    after_4:
    // 0x80012074: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80012078: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8001207C: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x80012080: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x80012084: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80012088: jal         0x8004C580
    // 0x8001208C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_5;
    // 0x8001208C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_5:
    // 0x80012090: lh          $t6, 0x0($s7)
    ctx->r14 = MEM_H(ctx->r23, 0X0);
    // 0x80012094: addiu       $a0, $zero, -0x44
    ctx->r4 = ADD32(0, -0X44);
    // 0x80012098: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x8001209C: beq         $t6, $zero, L_800120C0
    if (ctx->r14 == 0) {
        // 0x800120A0: nop
    
            goto L_800120C0;
    }
    // 0x800120A0: nop

    // 0x800120A4: jal         0x8004C388
    // 0x800120A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004C388(rdram, ctx);
        goto after_6;
    // 0x800120A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x800120AC: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x800120B0: addiu       $a2, $a2, 0x60E0
    ctx->r6 = ADD32(ctx->r6, 0X60E0);
    // 0x800120B4: addiu       $a0, $zero, -0xFF
    ctx->r4 = ADD32(0, -0XFF);
    // 0x800120B8: jal         0x8004BCF0
    // 0x800120BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004BCF0(rdram, ctx);
        goto after_7;
    // 0x800120BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
L_800120C0:
    // 0x800120C0: jal         0x80044514
    // 0x800120C4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_80044514(rdram, ctx);
        goto after_8;
    // 0x800120C4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_8:
L_800120C8:
    // 0x800120C8: bnel        $s3, $zero, L_800120EC
    if (ctx->r19 != 0) {
        // 0x800120CC: lh          $t7, 0x0($s7)
        ctx->r15 = MEM_H(ctx->r23, 0X0);
            goto L_800120EC;
    }
    goto skip_0;
    // 0x800120CC: lh          $t7, 0x0($s7)
    ctx->r15 = MEM_H(ctx->r23, 0X0);
    skip_0:
    // 0x800120D0: jal         0x8004D1F0
    // 0x800120D4: nop

    func_8004D1F0(rdram, ctx);
        goto after_9;
    // 0x800120D4: nop

    after_9:
    // 0x800120D8: bne         $v0, $zero, L_800121A8
    if (ctx->r2 != 0) {
        // 0x800120DC: nop
    
            goto L_800121A8;
    }
    // 0x800120DC: nop

    // 0x800120E0: b           L_800121A8
    // 0x800120E4: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
        goto L_800121A8;
    // 0x800120E4: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800120E8: lh          $t7, 0x0($s7)
    ctx->r15 = MEM_H(ctx->r23, 0X0);
L_800120EC:
    // 0x800120EC: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x800120F0: bnel        $t7, $zero, L_80012110
    if (ctx->r15 != 0) {
        // 0x800120F4: lhu         $t0, 0x0($s6)
        ctx->r8 = MEM_HU(ctx->r22, 0X0);
            goto L_80012110;
    }
    goto skip_1;
    // 0x800120F4: lhu         $t0, 0x0($s6)
    ctx->r8 = MEM_HU(ctx->r22, 0X0);
    skip_1:
    // 0x800120F8: beql        $s2, $zero, L_80012110
    if (ctx->r18 == 0) {
        // 0x800120FC: lhu         $t0, 0x0($s6)
        ctx->r8 = MEM_HU(ctx->r22, 0X0);
            goto L_80012110;
    }
    goto skip_2;
    // 0x800120FC: lhu         $t0, 0x0($s6)
    ctx->r8 = MEM_HU(ctx->r22, 0X0);
    skip_2:
    // 0x80012100: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80012104: sll         $t8, $s2, 16
    ctx->r24 = S32(ctx->r18 << 16);
    // 0x80012108: sra         $s2, $t8, 16
    ctx->r18 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8001210C: lhu         $t0, 0x0($s6)
    ctx->r8 = MEM_HU(ctx->r22, 0X0);
L_80012110:
    // 0x80012110: andi        $t1, $t0, 0x1000
    ctx->r9 = ctx->r8 & 0X1000;
    // 0x80012114: beql        $t1, $zero, L_80012128
    if (ctx->r9 == 0) {
        // 0x80012118: sll         $t3, $s1, 24
        ctx->r11 = S32(ctx->r17 << 24);
            goto L_80012128;
    }
    goto skip_3;
    // 0x80012118: sll         $t3, $s1, 24
    ctx->r11 = S32(ctx->r17 << 24);
    skip_3:
    // 0x8001211C: jal         0x80044480
    // 0x80012120: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    func_80044480(rdram, ctx);
        goto after_10;
    // 0x80012120: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    after_10:
    // 0x80012124: sll         $t3, $s1, 24
    ctx->r11 = S32(ctx->r17 << 24);
L_80012128:
    // 0x80012128: sra         $a2, $t3, 16
    ctx->r6 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8001212C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80012130: addiu       $a1, $zero, -0xF
    ctx->r5 = ADD32(0, -0XF);
    // 0x80012134: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80012138: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001213C: jal         0x8004C580
    // 0x80012140: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_11;
    // 0x80012140: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_11:
    // 0x80012144: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80012148: sll         $t5, $s1, 16
    ctx->r13 = S32(ctx->r17 << 16);
    // 0x8001214C: slti        $at, $s0, 0x6
    ctx->r1 = SIGNED(ctx->r16) < 0X6 ? 1 : 0;
    // 0x80012150: beq         $at, $zero, L_800121A8
    if (ctx->r1 == 0) {
        // 0x80012154: sra         $s1, $t5, 16
        ctx->r17 = S32(SIGNED(ctx->r13) >> 16);
            goto L_800121A8;
    }
    // 0x80012154: sra         $s1, $t5, 16
    ctx->r17 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80012158: lhu         $t7, 0x0($fp)
    ctx->r15 = MEM_HU(ctx->r30, 0X0);
    // 0x8001215C: andi        $t8, $t7, 0x2000
    ctx->r24 = ctx->r15 & 0X2000;
    // 0x80012160: beql        $t8, $zero, L_800121A8
    if (ctx->r24 == 0) {
        // 0x80012164: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800121A8;
    }
    goto skip_4;
    // 0x80012164: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    skip_4:
    // 0x80012168: lhu         $v0, 0x0($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X0);
    // 0x8001216C: sll         $t0, $s0, 1
    ctx->r8 = S32(ctx->r16 << 1);
    // 0x80012170: lui         $t1, 0x8007
    ctx->r9 = S32(0X8007 << 16);
    // 0x80012174: andi        $t9, $v0, 0xCF00
    ctx->r25 = ctx->r2 & 0XCF00;
    // 0x80012178: beq         $t9, $zero, L_800121A8
    if (ctx->r25 == 0) {
        // 0x8001217C: addu        $t1, $t1, $t0
        ctx->r9 = ADD32(ctx->r9, ctx->r8);
            goto L_800121A8;
    }
    // 0x8001217C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80012180: lhu         $t1, -0x6A38($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X6A38);
    // 0x80012184: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80012188: sll         $t2, $s0, 16
    ctx->r10 = S32(ctx->r16 << 16);
    // 0x8001218C: bne         $t9, $t1, L_8001219C
    if (ctx->r25 != ctx->r9) {
        // 0x80012190: nop
    
            goto L_8001219C;
    }
    // 0x80012190: nop

    // 0x80012194: b           L_800121A8
    // 0x80012198: sra         $s0, $t2, 16
    ctx->r16 = S32(SIGNED(ctx->r10) >> 16);
        goto L_800121A8;
    // 0x80012198: sra         $s0, $t2, 16
    ctx->r16 = S32(SIGNED(ctx->r10) >> 16);
L_8001219C:
    // 0x8001219C: b           L_800121A8
    // 0x800121A0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_800121A8;
    // 0x800121A0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800121A4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800121A8:
    // 0x800121A8: bnel        $s5, $zero, L_800121B8
    if (ctx->r21 != 0) {
        // 0x800121AC: addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
            goto L_800121B8;
    }
    goto skip_5;
    // 0x800121AC: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    skip_5:
    // 0x800121B0: bne         $s2, $zero, L_800122B4
    if (ctx->r18 != 0) {
        // 0x800121B4: addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
            goto L_800122B4;
    }
    // 0x800121B4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
L_800121B8:
    // 0x800121B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800121BC: jal         0x8004D134
    // 0x800121C0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_8004D134(rdram, ctx);
        goto after_12;
    // 0x800121C0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_12:
    // 0x800121C4: jal         0x8004D1F0
    // 0x800121C8: nop

    func_8004D1F0(rdram, ctx);
        goto after_13;
    // 0x800121C8: nop

    after_13:
    // 0x800121CC: beql        $v0, $zero, L_800121F0
    if (ctx->r2 == 0) {
        // 0x800121D0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800121F0;
    }
    goto skip_6;
    // 0x800121D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_6:
L_800121D4:
    // 0x800121D4: jal         0x8000798C
    // 0x800121D8: nop

    func_8000798C(rdram, ctx);
        goto after_14;
    // 0x800121D8: nop

    after_14:
    // 0x800121DC: jal         0x8004D1F0
    // 0x800121E0: nop

    func_8004D1F0(rdram, ctx);
        goto after_15;
    // 0x800121E0: nop

    after_15:
    // 0x800121E4: bne         $v0, $zero, L_800121D4
    if (ctx->r2 != 0) {
        // 0x800121E8: nop
    
            goto L_800121D4;
    }
    // 0x800121E8: nop

    // 0x800121EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800121F0:
    // 0x800121F0: jal         0x8004C4D8
    // 0x800121F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004C4D8(rdram, ctx);
        goto after_16;
    // 0x800121F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x800121F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800121FC: jal         0x8004C4D8
    // 0x80012200: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004C4D8(rdram, ctx);
        goto after_17;
    // 0x80012200: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x80012204: beq         $s5, $zero, L_80012214
    if (ctx->r21 == 0) {
        // 0x80012208: addiu       $s4, $zero, 0x64
        ctx->r20 = ADD32(0, 0X64);
            goto L_80012214;
    }
    // 0x80012208: addiu       $s4, $zero, 0x64
    ctx->r20 = ADD32(0, 0X64);
    // 0x8001220C: b           L_80012214
    // 0x80012210: addiu       $s4, $zero, 0x65
    ctx->r20 = ADD32(0, 0X65);
        goto L_80012214;
    // 0x80012210: addiu       $s4, $zero, 0x65
    ctx->r20 = ADD32(0, 0X65);
L_80012214:
    // 0x80012214: jal         0x8004B21C
    // 0x80012218: nop

    func_8004B21C(rdram, ctx);
        goto after_18;
    // 0x80012218: nop

    after_18:
    // 0x8001221C: jal         0x8000798C
    // 0x80012220: nop

    func_8000798C(rdram, ctx);
        goto after_19;
    // 0x80012220: nop

    after_19:
    // 0x80012224: beq         $s5, $zero, L_8001229C
    if (ctx->r21 == 0) {
        // 0x80012228: slti        $at, $s0, 0x6
        ctx->r1 = SIGNED(ctx->r16) < 0X6 ? 1 : 0;
            goto L_8001229C;
    }
    // 0x80012228: slti        $at, $s0, 0x6
    ctx->r1 = SIGNED(ctx->r16) < 0X6 ? 1 : 0;
    // 0x8001222C: bne         $at, $zero, L_8001229C
    if (ctx->r1 != 0) {
        // 0x80012230: addiu       $t4, $zero, -0x1
        ctx->r12 = ADD32(0, -0X1);
            goto L_8001229C;
    }
    // 0x80012230: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80012234: lui         $a0, 0x8002
    ctx->r4 = S32(0X8002 << 16);
    // 0x80012238: addiu       $a0, $a0, -0x7F40
    ctx->r4 = ADD32(ctx->r4, -0X7F40);
    // 0x8001223C: sw          $t4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r12;
    // 0x80012240: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80012244: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80012248: jal         0x80004CE0
    // 0x8001224C: addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    func_80004CE0(rdram, ctx);
        goto after_20;
    // 0x8001224C: addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    after_20:
    // 0x80012250: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x80012254: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80012258: beql        $t5, $zero, L_80012278
    if (ctx->r13 == 0) {
        // 0x8001225C: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80012278;
    }
    goto skip_7;
    // 0x8001225C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_7:
L_80012260:
    // 0x80012260: jal         0x8000798C
    // 0x80012264: nop

    func_8000798C(rdram, ctx);
        goto after_21;
    // 0x80012264: nop

    after_21:
    // 0x80012268: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8001226C: bne         $t6, $zero, L_80012260
    if (ctx->r14 != 0) {
        // 0x80012270: nop
    
            goto L_80012260;
    }
    // 0x80012270: nop

    // 0x80012274: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_80012278:
    // 0x80012278: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001227C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80012280: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80012284: jal         0x80004E5C
    // 0x80012288: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    func_80004E5C(rdram, ctx);
        goto after_22;
    // 0x80012288: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    after_22:
    // 0x8001228C: jal         0x8000798C
    // 0x80012290: nop

    func_8000798C(rdram, ctx);
        goto after_23;
    // 0x80012290: nop

    after_23:
    // 0x80012294: b           L_80012040
    // 0x80012298: addiu       $a0, $zero, -0xA
    ctx->r4 = ADD32(0, -0XA);
        goto L_80012040;
    // 0x80012298: addiu       $a0, $zero, -0xA
    ctx->r4 = ADD32(0, -0XA);
L_8001229C:
    // 0x8001229C: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x800122A0: sw          $s4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r20;
L_800122A4:
    // 0x800122A4: jal         0x8000798C
    // 0x800122A8: nop

    func_8000798C(rdram, ctx);
        goto after_24;
    // 0x800122A8: nop

    after_24:
    // 0x800122AC: b           L_800122A4
    // 0x800122B0: nop

        goto L_800122A4;
    // 0x800122B0: nop

L_800122B4:
    // 0x800122B4: jal         0x8000798C
    // 0x800122B8: nop

    func_8000798C(rdram, ctx);
        goto after_25;
    // 0x800122B8: nop

    after_25:
    // 0x800122BC: b           L_800120C8
    // 0x800122C0: nop

        goto L_800120C8;
    // 0x800122C0: nop

    // 0x800122C4: nop

    // 0x800122C8: nop

    // 0x800122CC: nop

    // 0x800122D0: nop

    // 0x800122D4: nop

    // 0x800122D8: nop

    // 0x800122DC: nop

    // 0x800122E0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800122E4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800122E8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800122EC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800122F0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800122F4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800122F8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800122FC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80012300: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80012304: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80012308: jr          $ra
    // 0x8001230C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    TRACE_RETURN()
    return;
    // 0x8001230C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_80012310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80012310: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80012314: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80012318: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x8001231C: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80012320: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80012324: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80012328: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8001232C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80012330: addiu       $a0, $zero, -0xA
    ctx->r4 = ADD32(0, -0XA);
    // 0x80012334: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80012338: jal         0x8004D134
    // 0x8001233C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004D134(rdram, ctx);
        goto after_0;
    // 0x8001233C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80012340: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x80012344: jal         0x800499B0
    // 0x80012348: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800499B0(rdram, ctx);
        goto after_1;
    // 0x80012348: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8001234C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80012350: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80012354: jal         0x8000BD4C
    // 0x80012358: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BD4C(rdram, ctx);
        goto after_2;
    // 0x80012358: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8001235C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80012360: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80012364: jal         0x8000BDEC
    // 0x80012368: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BDEC(rdram, ctx);
        goto after_3;
    // 0x80012368: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8001236C: addiu       $t6, $zero, 0x3E8
    ctx->r14 = ADD32(0, 0X3E8);
    // 0x80012370: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80012374: sw          $t6, -0x2CF8($at)
    MEM_W(-0X2CF8, ctx->r1) = ctx->r14;
    // 0x80012378: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001237C: addiu       $t7, $zero, 0x3D0
    ctx->r15 = ADD32(0, 0X3D0);
    // 0x80012380: sw          $t7, -0x2CF4($at)
    MEM_W(-0X2CF4, ctx->r1) = ctx->r15;
    // 0x80012384: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80012388: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001238C: sh          $zero, -0x2CC4($at)
    MEM_H(-0X2CC4, ctx->r1) = 0;
    // 0x80012390: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80012394: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80012398: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8001239C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800123A0: addiu       $v1, $v1, -0x6C40
    ctx->r3 = ADD32(ctx->r3, -0X6C40);
    // 0x800123A4: addiu       $v0, $v0, -0x6C50
    ctx->r2 = ADD32(ctx->r2, -0X6C50);
    // 0x800123A8: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x800123AC: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x800123B0: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x800123B4: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x800123B8: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x800123BC: jal         0x8000798C
    // 0x800123C0: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    func_8000798C(rdram, ctx);
        goto after_4;
    // 0x800123C0: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    after_4:
    // 0x800123C4: jal         0x8000798C
    // 0x800123C8: nop

    func_8000798C(rdram, ctx);
        goto after_5;
    // 0x800123C8: nop

    after_5:
    // 0x800123CC: jal         0x8000798C
    // 0x800123D0: nop

    func_8000798C(rdram, ctx);
        goto after_6;
    // 0x800123D0: nop

    after_6:
    // 0x800123D4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800123D8: lwc1        $f20, 0x6114($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X6114);
    // 0x800123DC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800123E0: addiu       $s3, $zero, 0xC
    ctx->r19 = ADD32(0, 0XC);
    // 0x800123E4: addiu       $s2, $sp, 0x4C
    ctx->r18 = ADD32(ctx->r29, 0X4C);
L_800123E8:
    // 0x800123E8: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x800123EC: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x800123F0: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x800123F4: jal         0x80049CFC
    // 0x800123F8: lw          $a0, -0x6A2C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6A2C);
    func_80049CFC(rdram, ctx);
        goto after_7;
    // 0x800123F8: lw          $a0, -0x6A2C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6A2C);
    after_7:
    // 0x800123FC: jal         0x80049D80
    // 0x80012400: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80049D80(rdram, ctx);
        goto after_8;
    // 0x80012400: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x80012404: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80012408: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001240C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80012410: mflo        $t9
    ctx->r25 = lo;
    // 0x80012414: addu        $s1, $s2, $t9
    ctx->r17 = ADD32(ctx->r18, ctx->r25);
    // 0x80012418: jal         0x80049DFC
    // 0x8001241C: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    func_80049DFC(rdram, ctx);
        goto after_9;
    // 0x8001241C: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    after_9:
    // 0x80012420: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x80012424: jal         0x8004A148
    // 0x80012428: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8004A148(rdram, ctx);
        goto after_10;
    // 0x80012428: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_10:
    // 0x8001242C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80012430: lwc1        $f6, 0x6118($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6118);
    // 0x80012434: lw          $t1, 0x4($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X4);
    // 0x80012438: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001243C: swc1        $f6, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f6.u32l;
    // 0x80012440: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x80012444: sll         $t3, $s0, 16
    ctx->r11 = S32(ctx->r16 << 16);
    // 0x80012448: sra         $s0, $t3, 16
    ctx->r16 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8001244C: ori         $t0, $zero, 0x8000
    ctx->r8 = 0 | 0X8000;
    // 0x80012450: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x80012454: sw          $t0, 0xD8($t2)
    MEM_W(0XD8, ctx->r10) = ctx->r8;
    // 0x80012458: bne         $at, $zero, L_800123E8
    if (ctx->r1 != 0) {
        // 0x8001245C: swc1        $f20, 0x8($s1)
        MEM_W(0X8, ctx->r17) = ctx->f20.u32l;
            goto L_800123E8;
    }
    // 0x8001245C: swc1        $f20, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f20.u32l;
    // 0x80012460: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x80012464: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80012468: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8001246C: lw          $a0, 0x8($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X8);
    // 0x80012470: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80012474: jal         0x80001AB4
    // 0x80012478: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80001AB4(rdram, ctx);
        goto after_11;
    // 0x80012478: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_11:
    // 0x8001247C: addiu       $t6, $zero, 0x12
    ctx->r14 = ADD32(0, 0X12);
    // 0x80012480: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80012484: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x80012488: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001248C: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80012490: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80012494: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80012498: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x8001249C: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x800124A0: cvt.s.w     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    ctx->f2.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800124A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800124A8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800124AC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800124B0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800124B4: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800124B8: swc1        $f16, 0x40($t8)
    MEM_W(0X40, ctx->r24) = ctx->f16.u32l;
    // 0x800124BC: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x800124C0: swc1        $f2, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->f2.u32l;
    // 0x800124C4: lw          $t1, 0x8($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X8);
    // 0x800124C8: swc1        $f4, 0x48($t1)
    MEM_W(0X48, ctx->r9) = ctx->f4.u32l;
    // 0x800124CC: lw          $v0, 0x8($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X8);
    // 0x800124D0: lw          $t0, 0xD8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XD8);
    // 0x800124D4: ori         $t2, $t0, 0x8001
    ctx->r10 = ctx->r8 | 0X8001;
    // 0x800124D8: sw          $t2, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r10;
    // 0x800124DC: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x800124E0: lw          $a0, 0x8($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X8);
    // 0x800124E4: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x800124E8: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x800124EC: jal         0x80001AB4
    // 0x800124F0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80001AB4(rdram, ctx);
        goto after_12;
    // 0x800124F0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_12:
    // 0x800124F4: lui         $at, 0x4198
    ctx->r1 = S32(0X4198 << 16);
    // 0x800124F8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800124FC: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80012500: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x80012504: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x80012508: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8001250C: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x80012510: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80012514: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x80012518: swc1        $f10, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f10.u32l;
    // 0x8001251C: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80012520: lw          $t6, 0x8($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X8);
    // 0x80012524: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80012528: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8001252C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80012530: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80012534: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80012538: swc1        $f0, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->f0.u32l;
    // 0x8001253C: lw          $t8, 0x8($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X8);
    // 0x80012540: swc1        $f4, 0x48($t8)
    MEM_W(0X48, ctx->r24) = ctx->f4.u32l;
    // 0x80012544: lw          $v0, 0x8($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X8);
    // 0x80012548: lw          $t9, 0xD8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XD8);
    // 0x8001254C: ori         $t1, $t9, 0x8001
    ctx->r9 = ctx->r25 | 0X8001;
    // 0x80012550: sw          $t1, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r9;
    // 0x80012554: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x80012558: lw          $a0, 0x8($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X8);
    // 0x8001255C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80012560: jal         0x80001AB4
    // 0x80012564: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80001AB4(rdram, ctx);
        goto after_13;
    // 0x80012564: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_13:
    // 0x80012568: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x8001256C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80012570: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80012574: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x80012578: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x8001257C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80012580: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x80012584: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80012588: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8001258C: swc1        $f10, 0x40($t2)
    MEM_W(0X40, ctx->r10) = ctx->f10.u32l;
    // 0x80012590: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80012594: lw          $t3, 0x8($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X8);
    // 0x80012598: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8001259C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800125A0: swc1        $f16, 0x44($t3)
    MEM_W(0X44, ctx->r11) = ctx->f16.u32l;
    // 0x800125A4: lw          $t5, 0x8($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X8);
    // 0x800125A8: swc1        $f18, 0x48($t5)
    MEM_W(0X48, ctx->r13) = ctx->f18.u32l;
    // 0x800125AC: lw          $v0, 0x8($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X8);
    // 0x800125B0: lw          $t6, 0xD8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XD8);
    // 0x800125B4: ori         $t8, $t6, 0x8001
    ctx->r24 = ctx->r14 | 0X8001;
    // 0x800125B8: sw          $t8, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r24;
    // 0x800125BC: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x800125C0: lw          $a0, 0x8($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X8);
    // 0x800125C4: jal         0x80001AB4
    // 0x800125C8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80001AB4(rdram, ctx);
        goto after_14;
    // 0x800125C8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_14:
    // 0x800125CC: lui         $at, 0x4286
    ctx->r1 = S32(0X4286 << 16);
    // 0x800125D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800125D4: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800125D8: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x800125DC: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x800125E0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800125E4: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x800125E8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800125EC: swc1        $f8, 0x40($t1)
    MEM_W(0X40, ctx->r9) = ctx->f8.u32l;
    // 0x800125F0: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800125F4: lw          $t7, 0x8($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X8);
    // 0x800125F8: swc1        $f10, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f10.u32l;
    // 0x800125FC: lw          $t2, 0x8($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X8);
    // 0x80012600: swc1        $f16, 0x48($t2)
    MEM_W(0X48, ctx->r10) = ctx->f16.u32l;
    // 0x80012604: lw          $v0, 0x8($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X8);
    // 0x80012608: lw          $t3, 0xD8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XD8);
    // 0x8001260C: ori         $t5, $t3, 0x8001
    ctx->r13 = ctx->r11 | 0X8001;
    // 0x80012610: jal         0x8004D1F0
    // 0x80012614: sw          $t5, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r13;
    func_8004D1F0(rdram, ctx);
        goto after_15;
    // 0x80012614: sw          $t5, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r13;
    after_15:
    // 0x80012618: beq         $v0, $zero, L_80012638
    if (ctx->r2 == 0) {
        // 0x8001261C: nop
    
            goto L_80012638;
    }
    // 0x8001261C: nop

L_80012620:
    // 0x80012620: jal         0x8000798C
    // 0x80012624: nop

    func_8000798C(rdram, ctx);
        goto after_16;
    // 0x80012624: nop

    after_16:
    // 0x80012628: jal         0x8004D1F0
    // 0x8001262C: nop

    func_8004D1F0(rdram, ctx);
        goto after_17;
    // 0x8001262C: nop

    after_17:
    // 0x80012630: bne         $v0, $zero, L_80012620
    if (ctx->r2 != 0) {
        // 0x80012634: nop
    
            goto L_80012620;
    }
    // 0x80012634: nop

L_80012638:
    // 0x80012638: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x8001263C: addiu       $s0, $zero, 0x5A
    ctx->r16 = ADD32(0, 0X5A);
    // 0x80012640: addiu       $s1, $s1, -0x2E5A
    ctx->r17 = ADD32(ctx->r17, -0X2E5A);
L_80012644:
    // 0x80012644: beql        $s0, $zero, L_8001265C
    if (ctx->r16 == 0) {
        // 0x80012648: addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
            goto L_8001265C;
    }
    goto skip_0;
    // 0x80012648: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    skip_0:
    // 0x8001264C: lhu         $t0, 0x0($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0X0);
    // 0x80012650: andi        $t6, $t0, 0x1000
    ctx->r14 = ctx->r8 & 0X1000;
    // 0x80012654: beq         $t6, $zero, L_800126E8
    if (ctx->r14 == 0) {
        // 0x80012658: addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
            goto L_800126E8;
    }
    // 0x80012658: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
L_8001265C:
    // 0x8001265C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80012660: jal         0x8004D134
    // 0x80012664: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_8004D134(rdram, ctx);
        goto after_18;
    // 0x80012664: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_18:
    // 0x80012668: jal         0x8004D1F0
    // 0x8001266C: nop

    func_8004D1F0(rdram, ctx);
        goto after_19;
    // 0x8001266C: nop

    after_19:
    // 0x80012670: beql        $v0, $zero, L_80012694
    if (ctx->r2 == 0) {
        // 0x80012674: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80012694;
    }
    goto skip_1;
    // 0x80012674: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    skip_1:
L_80012678:
    // 0x80012678: jal         0x8000798C
    // 0x8001267C: nop

    func_8000798C(rdram, ctx);
        goto after_20;
    // 0x8001267C: nop

    after_20:
    // 0x80012680: jal         0x8004D1F0
    // 0x80012684: nop

    func_8004D1F0(rdram, ctx);
        goto after_21;
    // 0x80012684: nop

    after_21:
    // 0x80012688: bne         $v0, $zero, L_80012678
    if (ctx->r2 != 0) {
        // 0x8001268C: nop
    
            goto L_80012678;
    }
    // 0x8001268C: nop

    // 0x80012690: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80012694:
    // 0x80012694: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80012698: mflo        $t8
    ctx->r24 = lo;
    // 0x8001269C: addu        $t4, $s2, $t8
    ctx->r12 = ADD32(ctx->r18, ctx->r24);
    // 0x800126A0: jal         0x8004A0C4
    // 0x800126A4: lw          $a0, 0x4($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X4);
    func_8004A0C4(rdram, ctx);
        goto after_22;
    // 0x800126A4: lw          $a0, 0x4($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X4);
    after_22:
    // 0x800126A8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800126AC: sll         $t1, $s0, 16
    ctx->r9 = S32(ctx->r16 << 16);
    // 0x800126B0: sra         $s0, $t1, 16
    ctx->r16 = S32(SIGNED(ctx->r9) >> 16);
    // 0x800126B4: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x800126B8: bne         $at, $zero, L_80012694
    if (ctx->r1 != 0) {
        // 0x800126BC: nop
    
            goto L_80012694;
    }
    // 0x800126BC: nop

    // 0x800126C0: jal         0x80049C48
    // 0x800126C4: nop

    func_80049C48(rdram, ctx);
        goto after_23;
    // 0x800126C4: nop

    after_23:
    // 0x800126C8: jal         0x8000798C
    // 0x800126CC: nop

    func_8000798C(rdram, ctx);
        goto after_24;
    // 0x800126CC: nop

    after_24:
    // 0x800126D0: lw          $t2, 0x80($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X80);
    // 0x800126D4: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
L_800126D8:
    // 0x800126D8: jal         0x8000798C
    // 0x800126DC: nop

    func_8000798C(rdram, ctx);
        goto after_25;
    // 0x800126DC: nop

    after_25:
    // 0x800126E0: b           L_800126D8
    // 0x800126E4: nop

        goto L_800126D8;
    // 0x800126E4: nop

L_800126E8:
    // 0x800126E8: beq         $s0, $zero, L_800126FC
    if (ctx->r16 == 0) {
        // 0x800126EC: nop
    
            goto L_800126FC;
    }
    // 0x800126EC: nop

    // 0x800126F0: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800126F4: sll         $t9, $s0, 16
    ctx->r25 = S32(ctx->r16 << 16);
    // 0x800126F8: sra         $s0, $t9, 16
    ctx->r16 = S32(SIGNED(ctx->r25) >> 16);
L_800126FC:
    // 0x800126FC: jal         0x8000798C
    // 0x80012700: nop

    func_8000798C(rdram, ctx);
        goto after_26;
    // 0x80012700: nop

    after_26:
    // 0x80012704: b           L_80012644
    // 0x80012708: nop

        goto L_80012644;
    // 0x80012708: nop

    // 0x8001270C: nop

    // 0x80012710: nop

    // 0x80012714: nop

    // 0x80012718: nop

    // 0x8001271C: nop

    // 0x80012720: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80012724: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80012728: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8001272C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80012730: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80012734: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80012738: jr          $ra
    // 0x8001273C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    TRACE_RETURN()
    return;
    // 0x8001273C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_80012740(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80012740: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80012744: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80012748: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8001274C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80012750: addiu       $a0, $zero, -0xA
    ctx->r4 = ADD32(0, -0XA);
    // 0x80012754: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80012758: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001275C: jal         0x8004D134
    // 0x80012760: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    func_8004D134(rdram, ctx);
        goto after_0;
    // 0x80012760: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    after_0:
    // 0x80012764: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80012768: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001276C: jal         0x8000BD4C
    // 0x80012770: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BD4C(rdram, ctx);
        goto after_1;
    // 0x80012770: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80012774: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80012778: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001277C: jal         0x8000BDEC
    // 0x80012780: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BDEC(rdram, ctx);
        goto after_2;
    // 0x80012780: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80012784: addiu       $t8, $zero, 0x3E8
    ctx->r24 = ADD32(0, 0X3E8);
    // 0x80012788: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001278C: sw          $t8, -0x2CF8($at)
    MEM_W(-0X2CF8, ctx->r1) = ctx->r24;
    // 0x80012790: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80012794: addiu       $t9, $zero, 0x3D0
    ctx->r25 = ADD32(0, 0X3D0);
    // 0x80012798: sw          $t9, -0x2CF4($at)
    MEM_W(-0X2CF4, ctx->r1) = ctx->r25;
    // 0x8001279C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800127A0: sh          $zero, -0x2CC4($at)
    MEM_H(-0X2CC4, ctx->r1) = 0;
    // 0x800127A4: jal         0x8004B1E0
    // 0x800127A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8004B1E0(rdram, ctx);
        goto after_3;
    // 0x800127A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x800127AC: jal         0x8000798C
    // 0x800127B0: nop

    func_8000798C(rdram, ctx);
        goto after_4;
    // 0x800127B0: nop

    after_4:
    // 0x800127B4: jal         0x8000798C
    // 0x800127B8: nop

    func_8000798C(rdram, ctx);
        goto after_5;
    // 0x800127B8: nop

    after_5:
    // 0x800127BC: jal         0x8000798C
    // 0x800127C0: nop

    func_8000798C(rdram, ctx);
        goto after_6;
    // 0x800127C0: nop

    after_6:
    // 0x800127C4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800127C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800127CC: bne         $t0, $at, L_800127F4
    if (ctx->r8 != ctx->r1) {
        // 0x800127D0: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_800127F4;
    }
    // 0x800127D0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800127D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800127D8: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x800127DC: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x800127E0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800127E4: jal         0x8004C580
    // 0x800127E8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_7;
    // 0x800127E8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_7:
    // 0x800127EC: b           L_80012814
    // 0x800127F0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
        goto L_80012814;
    // 0x800127F0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_800127F4:
    // 0x800127F4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800127F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800127FC: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x80012800: addiu       $a3, $zero, 0xB
    ctx->r7 = ADD32(0, 0XB);
    // 0x80012804: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80012808: jal         0x8004C580
    // 0x8001280C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_8;
    // 0x8001280C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_8:
    // 0x80012810: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80012814:
    // 0x80012814: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80012818: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001281C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80012820: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80012824: addiu       $v1, $v1, -0x6C40
    ctx->r3 = ADD32(ctx->r3, -0X6C40);
    // 0x80012828: addiu       $v0, $v0, -0x6C50
    ctx->r2 = ADD32(ctx->r2, -0X6C50);
    // 0x8001282C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80012830: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80012834: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x80012838: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x8001283C: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x80012840: jal         0x8000798C
    // 0x80012844: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    func_8000798C(rdram, ctx);
        goto after_9;
    // 0x80012844: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    after_9:
    // 0x80012848: jal         0x8000798C
    // 0x8001284C: nop

    func_8000798C(rdram, ctx);
        goto after_10;
    // 0x8001284C: nop

    after_10:
    // 0x80012850: jal         0x8000798C
    // 0x80012854: nop

    func_8000798C(rdram, ctx);
        goto after_11;
    // 0x80012854: nop

    after_11:
    // 0x80012858: jal         0x8004D1F0
    // 0x8001285C: nop

    func_8004D1F0(rdram, ctx);
        goto after_12;
    // 0x8001285C: nop

    after_12:
    // 0x80012860: beql        $v0, $zero, L_80012884
    if (ctx->r2 == 0) {
        // 0x80012864: addiu       $v0, $zero, 0x5A
        ctx->r2 = ADD32(0, 0X5A);
            goto L_80012884;
    }
    goto skip_0;
    // 0x80012864: addiu       $v0, $zero, 0x5A
    ctx->r2 = ADD32(0, 0X5A);
    skip_0:
L_80012868:
    // 0x80012868: jal         0x8000798C
    // 0x8001286C: nop

    func_8000798C(rdram, ctx);
        goto after_13;
    // 0x8001286C: nop

    after_13:
    // 0x80012870: jal         0x8004D1F0
    // 0x80012874: nop

    func_8004D1F0(rdram, ctx);
        goto after_14;
    // 0x80012874: nop

    after_14:
    // 0x80012878: bne         $v0, $zero, L_80012868
    if (ctx->r2 != 0) {
        // 0x8001287C: nop
    
            goto L_80012868;
    }
    // 0x8001287C: nop

    // 0x80012880: addiu       $v0, $zero, 0x5A
    ctx->r2 = ADD32(0, 0X5A);
L_80012884:
    // 0x80012884: beq         $v0, $zero, L_80012898
    if (ctx->r2 == 0) {
        // 0x80012888: lui         $t1, 0x800E
        ctx->r9 = S32(0X800E << 16);
            goto L_80012898;
    }
    // 0x80012888: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8001288C: lhu         $t1, -0x2E5A($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X2E5A);
    // 0x80012890: andi        $t2, $t1, 0x1000
    ctx->r10 = ctx->r9 & 0X1000;
    // 0x80012894: beq         $t2, $zero, L_80012918
    if (ctx->r10 == 0) {
        // 0x80012898: addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
            goto L_80012918;
    }
L_80012898:
    // 0x80012898: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8001289C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800128A0: jal         0x8004D134
    // 0x800128A4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_8004D134(rdram, ctx);
        goto after_15;
    // 0x800128A4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_15:
    // 0x800128A8: jal         0x8004D1F0
    // 0x800128AC: nop

    func_8004D1F0(rdram, ctx);
        goto after_16;
    // 0x800128AC: nop

    after_16:
    // 0x800128B0: beql        $v0, $zero, L_800128D4
    if (ctx->r2 == 0) {
        // 0x800128B4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800128D4;
    }
    goto skip_1;
    // 0x800128B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_1:
L_800128B8:
    // 0x800128B8: jal         0x8000798C
    // 0x800128BC: nop

    func_8000798C(rdram, ctx);
        goto after_17;
    // 0x800128BC: nop

    after_17:
    // 0x800128C0: jal         0x8004D1F0
    // 0x800128C4: nop

    func_8004D1F0(rdram, ctx);
        goto after_18;
    // 0x800128C4: nop

    after_18:
    // 0x800128C8: bne         $v0, $zero, L_800128B8
    if (ctx->r2 != 0) {
        // 0x800128CC: nop
    
            goto L_800128B8;
    }
    // 0x800128CC: nop

    // 0x800128D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800128D4:
    // 0x800128D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800128D8: jal         0x8004C4D8
    // 0x800128DC: addiu       $v0, $zero, 0x5A
    ctx->r2 = ADD32(0, 0X5A);
    func_8004C4D8(rdram, ctx);
        goto after_19;
    // 0x800128DC: addiu       $v0, $zero, 0x5A
    ctx->r2 = ADD32(0, 0X5A);
    after_19:
    // 0x800128E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800128E4: jal         0x8004C4D8
    // 0x800128E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004C4D8(rdram, ctx);
        goto after_20;
    // 0x800128E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
    // 0x800128EC: jal         0x8004B21C
    // 0x800128F0: nop

    func_8004B21C(rdram, ctx);
        goto after_21;
    // 0x800128F0: nop

    after_21:
    // 0x800128F4: jal         0x8000798C
    // 0x800128F8: nop

    func_8000798C(rdram, ctx);
        goto after_22;
    // 0x800128F8: nop

    after_22:
    // 0x800128FC: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x80012900: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80012904: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
L_80012908:
    // 0x80012908: jal         0x8000798C
    // 0x8001290C: nop

    func_8000798C(rdram, ctx);
        goto after_23;
    // 0x8001290C: nop

    after_23:
    // 0x80012910: b           L_80012908
    // 0x80012914: nop

        goto L_80012908;
    // 0x80012914: nop

L_80012918:
    // 0x80012918: beq         $v0, $zero, L_8001292C
    if (ctx->r2 == 0) {
        // 0x8001291C: nop
    
            goto L_8001292C;
    }
    // 0x8001291C: nop

    // 0x80012920: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80012924: sll         $t5, $v0, 16
    ctx->r13 = S32(ctx->r2 << 16);
    // 0x80012928: sra         $v0, $t5, 16
    ctx->r2 = S32(SIGNED(ctx->r13) >> 16);
L_8001292C:
    // 0x8001292C: jal         0x8000798C
    // 0x80012930: sh          $v0, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r2;
    func_8000798C(rdram, ctx);
        goto after_24;
    // 0x80012930: sh          $v0, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r2;
    after_24:
    // 0x80012934: b           L_80012884
    // 0x80012938: lh          $v0, 0x5E($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X5E);
        goto L_80012884;
    // 0x80012938: lh          $v0, 0x5E($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X5E);
    // 0x8001293C: nop

    // 0x80012940: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80012944: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80012948: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80012950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80012950: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80012954: addiu       $v0, $v0, -0x6BD8
    ctx->r2 = ADD32(ctx->r2, -0X6BD8);
    // 0x80012958: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8001295C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80012960: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x80012964: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x80012968: andi        $t9, $t8, 0x3
    ctx->r25 = ctx->r24 & 0X3;
    // 0x8001296C: jr          $ra
    // 0x80012970: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    TRACE_RETURN()
    return;
    // 0x80012970: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void func_80012974(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80012974: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80012978: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8001297C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80012980: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80012984: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80012988: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001298C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80012990: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80012994: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x80012998: lui         $s4, 0x8002
    ctx->r20 = S32(0X8002 << 16);
    // 0x8001299C: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800129A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800129A4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800129A8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800129AC: sh          $zero, -0x2CC4($at)
    MEM_H(-0X2CC4, ctx->r1) = 0;
    // 0x800129B0: addiu       $s6, $s6, -0x6BD8
    ctx->r22 = ADD32(ctx->r22, -0X6BD8);
    // 0x800129B4: addiu       $s4, $s4, -0x423C
    ctx->r20 = ADD32(ctx->r20, -0X423C);
    // 0x800129B8: addiu       $s2, $s2, -0x2E5A
    ctx->r18 = ADD32(ctx->r18, -0X2E5A);
    // 0x800129BC: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x800129C0: addiu       $s5, $sp, 0x4C
    ctx->r21 = ADD32(ctx->r29, 0X4C);
    // 0x800129C4: lh          $t6, 0x0($s6)
    ctx->r14 = MEM_H(ctx->r22, 0X0);
L_800129C8:
    // 0x800129C8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800129CC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x800129D0: addiu       $t7, $t6, 0xA
    ctx->r15 = ADD32(ctx->r14, 0XA);
    // 0x800129D4: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x800129D8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x800129DC: jal         0x80004CE0
    // 0x800129E0: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    func_80004CE0(rdram, ctx);
        goto after_0;
    // 0x800129E0: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    after_0:
    // 0x800129E4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_800129E8:
    // 0x800129E8: jal         0x8004D1F0
    // 0x800129EC: nop

    func_8004D1F0(rdram, ctx);
        goto after_1;
    // 0x800129EC: nop

    after_1:
    // 0x800129F0: bnel        $v0, $zero, L_80012A64
    if (ctx->r2 != 0) {
        // 0x800129F4: lw          $t2, 0x0($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X0);
            goto L_80012A64;
    }
    goto skip_0;
    // 0x800129F4: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x800129F8: lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X0);
    // 0x800129FC: andi        $t8, $v0, 0x20
    ctx->r24 = ctx->r2 & 0X20;
    // 0x80012A00: beq         $t8, $zero, L_80012A40
    if (ctx->r24 == 0) {
        // 0x80012A04: andi        $t0, $v0, 0x1000
        ctx->r8 = ctx->r2 & 0X1000;
            goto L_80012A40;
    }
    // 0x80012A04: andi        $t0, $v0, 0x1000
    ctx->r8 = ctx->r2 & 0X1000;
    // 0x80012A08: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
L_80012A0C:
    // 0x80012A0C: jal         0x8000798C
    // 0x80012A10: nop

    func_8000798C(rdram, ctx);
        goto after_2;
    // 0x80012A10: nop

    after_2:
    // 0x80012A14: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x80012A18: bne         $t9, $zero, L_80012A0C
    if (ctx->r25 != 0) {
        // 0x80012A1C: nop
    
            goto L_80012A0C;
    }
    // 0x80012A1C: nop

    // 0x80012A20: jal         0x80004E5C
    // 0x80012A24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80004E5C(rdram, ctx);
        goto after_3;
    // 0x80012A24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80012A28: jal         0x8000798C
    // 0x80012A2C: nop

    func_8000798C(rdram, ctx);
        goto after_4;
    // 0x80012A2C: nop

    after_4:
    // 0x80012A30: jal         0x80012950
    // 0x80012A34: nop

    func_80012950(rdram, ctx);
        goto after_5;
    // 0x80012A34: nop

    after_5:
    // 0x80012A38: b           L_800129C8
    // 0x80012A3C: lh          $t6, 0x0($s6)
    ctx->r14 = MEM_H(ctx->r22, 0X0);
        goto L_800129C8;
    // 0x80012A3C: lh          $t6, 0x0($s6)
    ctx->r14 = MEM_H(ctx->r22, 0X0);
L_80012A40:
    // 0x80012A40: beql        $t0, $zero, L_80012A64
    if (ctx->r8 == 0) {
        // 0x80012A44: lw          $t2, 0x0($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X0);
            goto L_80012A64;
    }
    goto skip_1;
    // 0x80012A44: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x80012A48: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
L_80012A4C:
    // 0x80012A4C: jal         0x8000798C
    // 0x80012A50: nop

    func_8000798C(rdram, ctx);
        goto after_6;
    // 0x80012A50: nop

    after_6:
    // 0x80012A54: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x80012A58: bne         $t1, $zero, L_80012A4C
    if (ctx->r9 != 0) {
        // 0x80012A5C: nop
    
            goto L_80012A4C;
    }
    // 0x80012A5C: nop

    // 0x80012A60: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
L_80012A64:
    // 0x80012A64: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x80012A68: beq         $s3, $t2, L_80012A78
    if (ctx->r19 == ctx->r10) {
        // 0x80012A6C: nop
    
            goto L_80012A78;
    }
    // 0x80012A6C: nop

    // 0x80012A70: bne         $t3, $zero, L_80012A9C
    if (ctx->r11 != 0) {
        // 0x80012A74: nop
    
            goto L_80012A9C;
    }
    // 0x80012A74: nop

L_80012A78:
    // 0x80012A78: jal         0x80004E5C
    // 0x80012A7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80004E5C(rdram, ctx);
        goto after_7;
    // 0x80012A7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x80012A80: jal         0x80012950
    // 0x80012A84: nop

    func_80012950(rdram, ctx);
        goto after_8;
    // 0x80012A84: nop

    after_8:
    // 0x80012A88: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_80012A8C:
    // 0x80012A8C: jal         0x8000798C
    // 0x80012A90: nop

    func_8000798C(rdram, ctx);
        goto after_9;
    // 0x80012A90: nop

    after_9:
    // 0x80012A94: b           L_80012A8C
    // 0x80012A98: nop

        goto L_80012A8C;
    // 0x80012A98: nop

L_80012A9C:
    // 0x80012A9C: jal         0x8000798C
    // 0x80012AA0: nop

    func_8000798C(rdram, ctx);
        goto after_10;
    // 0x80012AA0: nop

    after_10:
    // 0x80012AA4: b           L_800129E8
    // 0x80012AA8: nop

        goto L_800129E8;
    // 0x80012AA8: nop

    // 0x80012AAC: nop

    // 0x80012AB0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80012AB4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80012AB8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80012ABC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80012AC0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80012AC4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80012AC8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80012ACC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80012AD0: jr          $ra
    // 0x80012AD4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    TRACE_RETURN()
    return;
    // 0x80012AD4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80012AE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80012AE0: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x80012AE4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80012AE8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80012AEC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80012AF0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80012AF4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80012AF8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80012AFC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80012B00: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80012B04: addiu       $v1, $v1, -0x6C40
    ctx->r3 = ADD32(ctx->r3, -0X6C40);
    // 0x80012B08: addiu       $v0, $v0, -0x6C50
    ctx->r2 = ADD32(ctx->r2, -0X6C50);
    // 0x80012B0C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80012B10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80012B14: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80012B18: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80012B1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80012B20: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x80012B24: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x80012B28: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80012B2C: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80012B30: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80012B34: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x80012B38: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x80012B3C: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x80012B40: jal         0x8004C580
    // 0x80012B44: swc1        $f8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f8.u32l;
    func_8004C580(rdram, ctx);
        goto after_0;
    // 0x80012B44: swc1        $f8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f8.u32l;
    after_0:
    // 0x80012B48: addiu       $a0, $zero, -0x66
    ctx->r4 = ADD32(0, -0X66);
    // 0x80012B4C: addiu       $a1, $zero, 0x42
    ctx->r5 = ADD32(0, 0X42);
    // 0x80012B50: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x80012B54: addiu       $a3, $zero, 0x25
    ctx->r7 = ADD32(0, 0X25);
    // 0x80012B58: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80012B5C: jal         0x8004C580
    // 0x80012B60: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_1;
    // 0x80012B60: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
    // 0x80012B64: addiu       $a0, $zero, 0x52
    ctx->r4 = ADD32(0, 0X52);
    // 0x80012B68: addiu       $a1, $zero, -0x50
    ctx->r5 = ADD32(0, -0X50);
    // 0x80012B6C: addiu       $a2, $zero, -0x7FFF
    ctx->r6 = ADD32(0, -0X7FFF);
    // 0x80012B70: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80012B74: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80012B78: jal         0x8004C580
    // 0x80012B7C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_2;
    // 0x80012B7C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_2:
    // 0x80012B80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80012B84: addiu       $a1, $zero, -0x44
    ctx->r5 = ADD32(0, -0X44);
    // 0x80012B88: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x80012B8C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80012B90: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80012B94: jal         0x8004C580
    // 0x80012B98: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_3;
    // 0x80012B98: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_3:
    // 0x80012B9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80012BA0: addiu       $a1, $zero, -0x5C
    ctx->r5 = ADD32(0, -0X5C);
    // 0x80012BA4: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x80012BA8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80012BAC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80012BB0: jal         0x8004C580
    // 0x80012BB4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_4;
    // 0x80012BB4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_4:
    // 0x80012BB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80012BBC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80012BC0: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80012BC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80012BC8: addiu       $sp, $sp, -0xC00
    ctx->r29 = ADD32(ctx->r29, -0XC00);
    // 0x80012BCC: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x80012BD0: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    // 0x80012BD4: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x80012BD8: sw          $a0, 0xC00($sp)
    MEM_W(0XC00, ctx->r29) = ctx->r4;
    // 0x80012BDC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80012BE0: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x80012BE4: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x80012BE8: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x80012BEC: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x80012BF0: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x80012BF4: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x80012BF8: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x80012BFC: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x80012C00: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x80012C04: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x80012C08: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80012C0C: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80012C10: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80012C14: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80012C18: sh          $zero, 0xAE($sp)
    MEM_H(0XAE, ctx->r29) = 0;
    // 0x80012C1C: sh          $t6, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r14;
    // 0x80012C20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80012C24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80012C28: jal         0x800499B0
    // 0x80012C2C: swc1        $f30, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f30.u32l;
    func_800499B0(rdram, ctx);
        goto after_0;
    // 0x80012C2C: swc1        $f30, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f30.u32l;
    after_0:
    // 0x80012C30: jal         0x8004B1E0
    // 0x80012C34: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8004B1E0(rdram, ctx);
        goto after_1;
    // 0x80012C34: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80012C38: jal         0x8000798C
    // 0x80012C3C: nop

    func_8000798C(rdram, ctx);
        goto after_2;
    // 0x80012C3C: nop

    after_2:
    // 0x80012C40: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80012C44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80012C48: jal         0x8000BD4C
    // 0x80012C4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BD4C(rdram, ctx);
        goto after_3;
    // 0x80012C4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80012C50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80012C54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80012C58: jal         0x8000BDEC
    // 0x80012C5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BDEC(rdram, ctx);
        goto after_4;
    // 0x80012C5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80012C60: addiu       $t7, $zero, 0x3E8
    ctx->r15 = ADD32(0, 0X3E8);
    // 0x80012C64: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80012C68: sw          $t7, -0x2CF8($at)
    MEM_W(-0X2CF8, ctx->r1) = ctx->r15;
    // 0x80012C6C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80012C70: addiu       $t8, $zero, 0x3D0
    ctx->r24 = ADD32(0, 0X3D0);
    // 0x80012C74: sw          $t8, -0x2CF4($at)
    MEM_W(-0X2CF4, ctx->r1) = ctx->r24;
    // 0x80012C78: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80012C7C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80012C80: jal         0x8000798C
    // 0x80012C84: sh          $t9, -0x2CC4($at)
    MEM_H(-0X2CC4, ctx->r1) = ctx->r25;
    func_8000798C(rdram, ctx);
        goto after_5;
    // 0x80012C84: sh          $t9, -0x2CC4($at)
    MEM_H(-0X2CC4, ctx->r1) = ctx->r25;
    after_5:
    // 0x80012C88: jal         0x8000798C
    // 0x80012C8C: nop

    func_8000798C(rdram, ctx);
        goto after_6;
    // 0x80012C8C: nop

    after_6:
    // 0x80012C90: jal         0x8000798C
    // 0x80012C94: nop

    func_8000798C(rdram, ctx);
        goto after_7;
    // 0x80012C94: nop

    after_7:
    // 0x80012C98: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80012C9C: addiu       $s2, $sp, 0x9C
    ctx->r18 = ADD32(ctx->r29, 0X9C);
L_80012CA0:
    // 0x80012CA0: sh          $s1, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r17;
    // 0x80012CA4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80012CA8: slti        $at, $s1, 0x8
    ctx->r1 = SIGNED(ctx->r17) < 0X8 ? 1 : 0;
    // 0x80012CAC: bne         $at, $zero, L_80012CA0
    if (ctx->r1 != 0) {
        // 0x80012CB0: addiu       $s2, $s2, 0x2
        ctx->r18 = ADD32(ctx->r18, 0X2);
            goto L_80012CA0;
    }
    // 0x80012CB0: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x80012CB4: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80012CB8: lhu         $t0, -0x2E5C($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X2E5C);
    // 0x80012CBC: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80012CC0: addiu       $s2, $sp, 0x9C
    ctx->r18 = ADD32(ctx->r29, 0X9C);
    // 0x80012CC4: andi        $t1, $t0, 0x10
    ctx->r9 = ctx->r8 & 0X10;
    // 0x80012CC8: beq         $t1, $zero, L_80012D00
    if (ctx->r9 == 0) {
        // 0x80012CCC: addiu       $s0, $sp, 0xF0
        ctx->r16 = ADD32(ctx->r29, 0XF0);
            goto L_80012D00;
    }
    // 0x80012CCC: addiu       $s0, $sp, 0xF0
    ctx->r16 = ADD32(ctx->r29, 0XF0);
    // 0x80012CD0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80012CD4: lh          $v0, -0x6B84($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X6B84);
    // 0x80012CD8: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x80012CDC: addiu       $t3, $zero, 0x9
    ctx->r11 = ADD32(0, 0X9);
    // 0x80012CE0: slti        $at, $v0, 0x7
    ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x80012CE4: bnel        $at, $zero, L_80012CF4
    if (ctx->r1 != 0) {
        // 0x80012CE8: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80012CF4;
    }
    goto skip_0;
    // 0x80012CE8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    skip_0:
    // 0x80012CEC: sh          $t2, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r10;
    // 0x80012CF0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
L_80012CF4:
    // 0x80012CF4: bnel        $v0, $at, L_80012D04
    if (ctx->r2 != ctx->r1) {
        // 0x80012CF8: lui         $at, 0x4220
        ctx->r1 = S32(0X4220 << 16);
            goto L_80012D04;
    }
    goto skip_1;
    // 0x80012CF8: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    skip_1:
    // 0x80012CFC: sh          $t3, 0xAA($sp)
    MEM_H(0XAA, ctx->r29) = ctx->r11;
L_80012D00:
    // 0x80012D00: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
L_80012D04:
    // 0x80012D04: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80012D08: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x80012D0C: lui         $s3, 0x8007
    ctx->r19 = S32(0X8007 << 16);
    // 0x80012D10: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80012D14: addiu       $s3, $s3, -0x6A10
    ctx->r19 = ADD32(ctx->r19, -0X6A10);
L_80012D18:
    // 0x80012D18: lh          $t4, 0x0($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X0);
    // 0x80012D1C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80012D20: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x80012D24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80012D28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80012D2C: jal         0x80020328
    // 0x80012D30: sw          $t4, -0x68C8($at)
    MEM_W(-0X68C8, ctx->r1) = ctx->r12;
    func_80020328(rdram, ctx);
        goto after_8;
    // 0x80012D30: sw          $t4, -0x68C8($at)
    MEM_W(-0X68C8, ctx->r1) = ctx->r12;
    after_8:
    // 0x80012D34: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80012D38: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80012D3C: lwc1        $f6, 0x6130($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6130);
    // 0x80012D40: add.s       $f20, $f4, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x80012D44: mul.s       $f22, $f20, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x80012D48: jal         0x8004F7C0
    // 0x80012D4C: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_8004F7C0(rdram, ctx);
        goto after_9;
    // 0x80012D4C: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_9:
    // 0x80012D50: mul.s       $f8, $f0, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x80012D54: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x80012D58: jal         0x8004F650
    // 0x80012D5C: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    func_8004F650(rdram, ctx);
        goto after_10;
    // 0x80012D5C: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    after_10:
    // 0x80012D60: mul.s       $f10, $f0, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x80012D64: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80012D68: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80012D6C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80012D70: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80012D74: addiu       $s0, $s0, 0x158
    ctx->r16 = ADD32(ctx->r16, 0X158);
    // 0x80012D78: addiu       $t8, $sp, 0xBB0
    ctx->r24 = ADD32(ctx->r29, 0XBB0);
    // 0x80012D7C: swc1        $f10, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f10.u32l;
    // 0x80012D80: lh          $t5, 0x0($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X0);
    // 0x80012D84: add.s       $f8, $f20, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f20.fl + ctx->f6.fl;
    // 0x80012D88: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x80012D8C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80012D90: addu        $t7, $s3, $t6
    ctx->r15 = ADD32(ctx->r19, ctx->r14);
    // 0x80012D94: lwc1        $f16, 0x0($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80012D98: sub.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f26.fl;
    // 0x80012D9C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80012DA0: swc1        $f10, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f10.u32l;
    // 0x80012DA4: sub.s       $f24, $f24, $f26
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f24.fl = ctx->f24.fl - ctx->f26.fl;
    // 0x80012DA8: bne         $s0, $t8, L_80012D18
    if (ctx->r16 != ctx->r24) {
        // 0x80012DAC: swc1        $f4, 0xC($s1)
        MEM_W(0XC, ctx->r17) = ctx->f4.u32l;
            goto L_80012D18;
    }
    // 0x80012DAC: swc1        $f4, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f4.u32l;
    // 0x80012DB0: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80012DB4: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80012DB8: jal         0x80049CFC
    // 0x80012DBC: addiu       $a0, $a0, 0x6120
    ctx->r4 = ADD32(ctx->r4, 0X6120);
    func_80049CFC(rdram, ctx);
        goto after_11;
    // 0x80012DBC: addiu       $a0, $a0, 0x6120
    ctx->r4 = ADD32(ctx->r4, 0X6120);
    after_11:
    // 0x80012DC0: jal         0x80049D80
    // 0x80012DC4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80049D80(rdram, ctx);
        goto after_12;
    // 0x80012DC4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_12:
    // 0x80012DC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80012DCC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80012DD0: jal         0x80049DFC
    // 0x80012DD4: sw          $v0, 0xBF0($sp)
    MEM_W(0XBF0, ctx->r29) = ctx->r2;
    func_80049DFC(rdram, ctx);
        goto after_13;
    // 0x80012DD4: sw          $v0, 0xBF0($sp)
    MEM_W(0XBF0, ctx->r29) = ctx->r2;
    after_13:
    // 0x80012DD8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80012DDC: jal         0x8004A148
    // 0x80012DE0: sw          $v0, 0xBF4($sp)
    MEM_W(0XBF4, ctx->r29) = ctx->r2;
    func_8004A148(rdram, ctx);
        goto after_14;
    // 0x80012DE0: sw          $v0, 0xBF4($sp)
    MEM_W(0XBF4, ctx->r29) = ctx->r2;
    after_14:
    // 0x80012DE4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80012DE8: sh          $zero, 0xD0($sp)
    MEM_H(0XD0, ctx->r29) = 0;
    // 0x80012DEC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80012DF0: sw          $t9, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r25;
    // 0x80012DF4: addiu       $v0, $sp, 0x9C
    ctx->r2 = ADD32(ctx->r29, 0X9C);
    // 0x80012DF8: lh          $s0, 0xAE($sp)
    ctx->r16 = MEM_H(ctx->r29, 0XAE);
    // 0x80012DFC: addiu       $fp, $zero, 0x158
    ctx->r30 = ADD32(0, 0X158);
    // 0x80012E00: addiu       $s7, $sp, 0xF0
    ctx->r23 = ADD32(ctx->r29, 0XF0);
    // 0x80012E04: addiu       $s6, $sp, 0xBB0
    ctx->r22 = ADD32(ctx->r29, 0XBB0);
    // 0x80012E08: addiu       $s5, $sp, 0xBF8
    ctx->r21 = ADD32(ctx->r29, 0XBF8);
    // 0x80012E0C: addiu       $s4, $sp, 0xC4
    ctx->r20 = ADD32(ctx->r29, 0XC4);
    // 0x80012E10: addiu       $s2, $zero, -0x2
    ctx->r18 = ADD32(0, -0X2);
L_80012E14:
    // 0x80012E14: lh          $t0, 0x0($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X0);
    // 0x80012E18: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80012E1C: jal         0x80013A94
    // 0x80012E20: sw          $t0, -0x68C8($at)
    MEM_W(-0X68C8, ctx->r1) = ctx->r8;
    func_80013A94(rdram, ctx);
        goto after_15;
    // 0x80012E20: sw          $t0, -0x68C8($at)
    MEM_W(-0X68C8, ctx->r1) = ctx->r8;
    after_15:
    // 0x80012E24: sltiu       $at, $s0, 0x7
    ctx->r1 = ctx->r16 < 0X7 ? 1 : 0;
    // 0x80012E28: beq         $at, $zero, L_80013294
    if (ctx->r1 == 0) {
        // 0x80012E2C: sll         $t1, $s0, 2
        ctx->r9 = S32(ctx->r16 << 2);
            goto L_80013294;
    }
    // 0x80012E2C: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    // 0x80012E30: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80012E34: addu        $at, $at, $t1
    gpr jr_addend_80012E3C = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80012E38: lw          $t1, 0x6134($at)
    ctx->r9 = ADD32(ctx->r1, 0X6134);
    // 0x80012E3C: jr          $t1
    // 0x80012E40: nop

    switch (jr_addend_80012E3C >> 2) {
        case 0: goto L_80012E44; break;
        case 1: goto L_80012F00; break;
        case 2: goto L_80012F18; break;
        case 3: goto L_800130A0; break;
        case 4: goto L_800130C8; break;
        case 5: goto L_80013154; break;
        case 6: goto L_8001317C; break;
        default: switch_error(__func__, 0x80012E3C, 0x80076134);
    }
    // 0x80012E40: nop

L_80012E44:
    // 0x80012E44: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
    // 0x80012E48: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80012E4C: jal         0x8004D134
    // 0x80012E50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004D134(rdram, ctx);
        goto after_16;
    // 0x80012E50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_16:
    // 0x80012E54: jal         0x80012AE0
    // 0x80012E58: nop

    func_80012AE0(rdram, ctx);
        goto after_17;
    // 0x80012E58: nop

    after_17:
    // 0x80012E5C: addiu       $s0, $sp, 0xB4
    ctx->r16 = ADD32(ctx->r29, 0XB4);
L_80012E60:
    // 0x80012E60: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80012E64: sltu        $at, $s0, $s4
    ctx->r1 = ctx->r16 < ctx->r20 ? 1 : 0;
    // 0x80012E68: bne         $at, $zero, L_80012E60
    if (ctx->r1 != 0) {
        // 0x80012E6C: sw          $zero, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = 0;
            goto L_80012E60;
    }
    // 0x80012E6C: sw          $zero, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = 0;
    // 0x80012E70: addiu       $s0, $sp, 0xBF0
    ctx->r16 = ADD32(ctx->r29, 0XBF0);
L_80012E74:
    // 0x80012E74: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x80012E78: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80012E7C: sltu        $at, $s0, $s5
    ctx->r1 = ctx->r16 < ctx->r21 ? 1 : 0;
    // 0x80012E80: lw          $v0, 0x8($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X8);
    // 0x80012E84: lw          $t3, 0xD8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XD8);
    // 0x80012E88: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x80012E8C: bne         $at, $zero, L_80012E74
    if (ctx->r1 != 0) {
        // 0x80012E90: sw          $t4, 0xD8($v0)
        MEM_W(0XD8, ctx->r2) = ctx->r12;
            goto L_80012E74;
    }
    // 0x80012E90: sw          $t4, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r12;
    // 0x80012E94: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80012E98: sh          $t5, 0xAE($sp)
    MEM_H(0XAE, ctx->r29) = ctx->r13;
    // 0x80012E9C: addiu       $s0, $sp, 0xF0
    ctx->r16 = ADD32(ctx->r29, 0XF0);
L_80012EA0:
    // 0x80012EA0: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x80012EA4: addiu       $s0, $s0, 0x560
    ctx->r16 = ADD32(ctx->r16, 0X560);
    // 0x80012EA8: lw          $v0, 0x8($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X8);
    // 0x80012EAC: lw          $t7, 0xD8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XD8);
    // 0x80012EB0: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80012EB4: sw          $t8, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r24;
    // 0x80012EB8: lw          $t9, -0x404($s0)
    ctx->r25 = MEM_W(ctx->r16, -0X404);
    // 0x80012EBC: lw          $v1, 0x8($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X8);
    // 0x80012EC0: lw          $t0, 0xD8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XD8);
    // 0x80012EC4: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80012EC8: sw          $t1, 0xD8($v1)
    MEM_W(0XD8, ctx->r3) = ctx->r9;
    // 0x80012ECC: lw          $t2, -0x2AC($s0)
    ctx->r10 = MEM_W(ctx->r16, -0X2AC);
    // 0x80012ED0: lw          $a0, 0x8($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X8);
    // 0x80012ED4: lw          $t3, 0xD8($a0)
    ctx->r11 = MEM_W(ctx->r4, 0XD8);
    // 0x80012ED8: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x80012EDC: sw          $t4, 0xD8($a0)
    MEM_W(0XD8, ctx->r4) = ctx->r12;
    // 0x80012EE0: lw          $t5, -0x154($s0)
    ctx->r13 = MEM_W(ctx->r16, -0X154);
    // 0x80012EE4: lw          $a1, 0x8($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X8);
    // 0x80012EE8: lw          $t6, 0xD8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XD8);
    // 0x80012EEC: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x80012EF0: bne         $s0, $s6, L_80012EA0
    if (ctx->r16 != ctx->r22) {
        // 0x80012EF4: sw          $t7, 0xD8($a1)
        MEM_W(0XD8, ctx->r5) = ctx->r15;
            goto L_80012EA0;
    }
    // 0x80012EF4: sw          $t7, 0xD8($a1)
    MEM_W(0XD8, ctx->r5) = ctx->r15;
    // 0x80012EF8: b           L_80013298
    // 0x80012EFC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_80013298;
    // 0x80012EFC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80012F00:
    // 0x80012F00: jal         0x8004D1F0
    // 0x80012F04: nop

    func_8004D1F0(rdram, ctx);
        goto after_18;
    // 0x80012F04: nop

    after_18:
    // 0x80012F08: bne         $v0, $zero, L_80013294
    if (ctx->r2 != 0) {
        // 0x80012F0C: addiu       $t8, $zero, 0x2
        ctx->r24 = ADD32(0, 0X2);
            goto L_80013294;
    }
    // 0x80012F0C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80012F10: b           L_80013294
    // 0x80012F14: sh          $t8, 0xAE($sp)
    MEM_H(0XAE, ctx->r29) = ctx->r24;
        goto L_80013294;
    // 0x80012F14: sh          $t8, 0xAE($sp)
    MEM_H(0XAE, ctx->r29) = ctx->r24;
L_80012F18:
    // 0x80012F18: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80012F1C: lhu         $v0, -0x2E5A($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2E5A);
    // 0x80012F20: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80012F24: andi        $t9, $v0, 0x20
    ctx->r25 = ctx->r2 & 0X20;
    // 0x80012F28: beq         $t9, $zero, L_80012F38
    if (ctx->r25 == 0) {
        // 0x80012F2C: andi        $t1, $v0, 0x9000
        ctx->r9 = ctx->r2 & 0X9000;
            goto L_80012F38;
    }
    // 0x80012F2C: andi        $t1, $v0, 0x9000
    ctx->r9 = ctx->r2 & 0X9000;
    // 0x80012F30: b           L_80013294
    // 0x80012F34: sh          $t0, 0xAE($sp)
    MEM_H(0XAE, ctx->r29) = ctx->r8;
        goto L_80013294;
    // 0x80012F34: sh          $t0, 0xAE($sp)
    MEM_H(0XAE, ctx->r29) = ctx->r8;
L_80012F38:
    // 0x80012F38: beq         $t1, $zero, L_80012F4C
    if (ctx->r9 == 0) {
        // 0x80012F3C: lui         $at, 0x8007
        ctx->r1 = S32(0X8007 << 16);
            goto L_80012F4C;
    }
    // 0x80012F3C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80012F40: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80012F44: b           L_80013294
    // 0x80012F48: sh          $t2, 0xAE($sp)
    MEM_H(0XAE, ctx->r29) = ctx->r10;
        goto L_80013294;
    // 0x80012F48: sh          $t2, 0xAE($sp)
    MEM_H(0XAE, ctx->r29) = ctx->r10;
L_80012F4C:
    // 0x80012F4C: lwc1        $f16, 0x6150($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6150);
    // 0x80012F50: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80012F54: lwc1        $f4, 0x6154($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6154);
    // 0x80012F58: add.s       $f18, $f30, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f30.fl + ctx->f16.fl;
    // 0x80012F5C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80012F60: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80012F64: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80012F68: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80012F6C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80012F70: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80012F74: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x80012F78: lwc1        $f8, 0xD4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80012F7C: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x80012F80: nop

    // 0x80012F84: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80012F88: lwc1        $f10, 0x6158($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6158);
    // 0x80012F8C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80012F90: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80012F94: lwc1        $f18, 0x615C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X615C);
    // 0x80012F98: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80012F9C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80012FA0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80012FA4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80012FA8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80012FAC: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x80012FB0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80012FB4: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80012FB8: nop

    // 0x80012FBC: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80012FC0: nop

    // 0x80012FC4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80012FC8: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80012FCC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80012FD0: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x80012FD4: nop

    // 0x80012FD8: bnel        $t6, $t0, L_80013080
    if (ctx->r14 != ctx->r8) {
        // 0x80012FDC: lwc1        $f6, 0xD4($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0XD4);
            goto L_80013080;
    }
    goto skip_2;
    // 0x80012FDC: lwc1        $f6, 0xD4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD4);
    skip_2:
    // 0x80012FE0: lh          $v0, -0x2E4E($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2E4E);
    // 0x80012FE4: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
    // 0x80012FE8: mov.s       $f30, $f8
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    ctx->f30.fl = ctx->f8.fl;
    // 0x80012FEC: andi        $t1, $v0, 0x100
    ctx->r9 = ctx->r2 & 0X100;
    // 0x80012FF0: bne         $t1, $zero, L_8001300C
    if (ctx->r9 != 0) {
        // 0x80012FF4: andi        $t6, $v0, 0x200
        ctx->r14 = ctx->r2 & 0X200;
            goto L_8001300C;
    }
    // 0x80012FF4: andi        $t6, $v0, 0x200
    ctx->r14 = ctx->r2 & 0X200;
    // 0x80012FF8: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80012FFC: lhu         $t2, -0x2E5C($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X2E5C);
    // 0x80013000: andi        $t3, $t2, 0x100
    ctx->r11 = ctx->r10 & 0X100;
    // 0x80013004: beq         $t3, $zero, L_80013028
    if (ctx->r11 == 0) {
        // 0x80013008: nop
    
            goto L_80013028;
    }
    // 0x80013008: nop

L_8001300C:
    // 0x8001300C: lwc1        $f10, 0xD4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80013010: addiu       $t5, $s3, 0x1
    ctx->r13 = ADD32(ctx->r19, 0X1);
    // 0x80013014: andi        $t7, $t5, 0x7
    ctx->r15 = ctx->r13 & 0X7;
    // 0x80013018: add.s       $f16, $f10, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f26.fl;
    // 0x8001301C: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80013020: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80013024: swc1        $f16, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f16.u32l;
L_80013028:
    // 0x80013028: bne         $t6, $zero, L_80013040
    if (ctx->r14 != 0) {
        // 0x8001302C: lui         $t0, 0x800E
        ctx->r8 = S32(0X800E << 16);
            goto L_80013040;
    }
    // 0x8001302C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80013030: lhu         $t0, -0x2E5C($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X2E5C);
    // 0x80013034: andi        $t1, $t0, 0x200
    ctx->r9 = ctx->r8 & 0X200;
    // 0x80013038: beql        $t1, $zero, L_80013060
    if (ctx->r9 == 0) {
        // 0x8001303C: lh          $t8, 0xD0($sp)
        ctx->r24 = MEM_H(ctx->r29, 0XD0);
            goto L_80013060;
    }
    goto skip_3;
    // 0x8001303C: lh          $t8, 0xD0($sp)
    ctx->r24 = MEM_H(ctx->r29, 0XD0);
    skip_3:
L_80013040:
    // 0x80013040: lwc1        $f18, 0xD4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80013044: addiu       $t3, $s3, -0x1
    ctx->r11 = ADD32(ctx->r19, -0X1);
    // 0x80013048: andi        $t4, $t3, 0x7
    ctx->r12 = ctx->r11 & 0X7;
    // 0x8001304C: sub.s       $f4, $f18, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f26.fl;
    // 0x80013050: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x80013054: sra         $s3, $t5, 16
    ctx->r19 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80013058: swc1        $f4, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f4.u32l;
    // 0x8001305C: lh          $t8, 0xD0($sp)
    ctx->r24 = MEM_H(ctx->r29, 0XD0);
L_80013060:
    // 0x80013060: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    // 0x80013064: beql        $s3, $t8, L_80013298
    if (ctx->r19 == ctx->r24) {
        // 0x80013068: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80013298;
    }
    goto skip_4;
    // 0x80013068: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    skip_4:
    // 0x8001306C: jal         0x80044480
    // 0x80013070: sh          $s3, 0xD0($sp)
    MEM_H(0XD0, ctx->r29) = ctx->r19;
    func_80044480(rdram, ctx);
        goto after_19;
    // 0x80013070: sh          $s3, 0xD0($sp)
    MEM_H(0XD0, ctx->r29) = ctx->r19;
    after_19:
    // 0x80013074: b           L_80013298
    // 0x80013078: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_80013298;
    // 0x80013078: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001307C: lwc1        $f6, 0xD4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD4);
L_80013080:
    // 0x80013080: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80013084: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80013088: sub.s       $f8, $f6, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f30.fl;
    // 0x8001308C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80013090: sh          $t9, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r25;
    // 0x80013094: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80013098: b           L_80013294
    // 0x8001309C: add.s       $f30, $f30, $f16
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f30.fl = ctx->f30.fl + ctx->f16.fl;
        goto L_80013294;
    // 0x8001309C: add.s       $f30, $f30, $f16
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f30.fl = ctx->f30.fl + ctx->f16.fl;
L_800130A0:
    // 0x800130A0: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800130A4: sh          $t6, 0xAE($sp)
    MEM_H(0XAE, ctx->r29) = ctx->r14;
    // 0x800130A8: jal         0x80044480
    // 0x800130AC: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    func_80044480(rdram, ctx);
        goto after_20;
    // 0x800130AC: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_20:
    // 0x800130B0: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x800130B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800130B8: jal         0x8004D134
    // 0x800130BC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_8004D134(rdram, ctx);
        goto after_21;
    // 0x800130BC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_21:
    // 0x800130C0: b           L_80013298
    // 0x800130C4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_80013298;
    // 0x800130C4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800130C8:
    // 0x800130C8: jal         0x8004D1F0
    // 0x800130CC: nop

    func_8004D1F0(rdram, ctx);
        goto after_22;
    // 0x800130CC: nop

    after_22:
    // 0x800130D0: bne         $v0, $zero, L_80013294
    if (ctx->r2 != 0) {
        // 0x800130D4: addiu       $s0, $sp, 0xBF0
        ctx->r16 = ADD32(ctx->r29, 0XBF0);
            goto L_80013294;
    }
    // 0x800130D4: addiu       $s0, $sp, 0xBF0
    ctx->r16 = ADD32(ctx->r29, 0XBF0);
    // 0x800130D8: addiu       $s1, $sp, 0xBF8
    ctx->r17 = ADD32(ctx->r29, 0XBF8);
L_800130DC:
    // 0x800130DC: jal         0x8004A0C4
    // 0x800130E0: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    func_8004A0C4(rdram, ctx);
        goto after_23;
    // 0x800130E0: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_23:
    // 0x800130E4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800130E8: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x800130EC: bne         $at, $zero, L_800130DC
    if (ctx->r1 != 0) {
        // 0x800130F0: nop
    
            goto L_800130DC;
    }
    // 0x800130F0: nop

    // 0x800130F4: addiu       $s0, $sp, 0xF0
    ctx->r16 = ADD32(ctx->r29, 0XF0);
    // 0x800130F8: addiu       $s1, $sp, 0xBB0
    ctx->r17 = ADD32(ctx->r29, 0XBB0);
L_800130FC:
    // 0x800130FC: jal         0x8004A0C4
    // 0x80013100: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    func_8004A0C4(rdram, ctx);
        goto after_24;
    // 0x80013100: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_24:
    // 0x80013104: addiu       $s0, $s0, 0x158
    ctx->r16 = ADD32(ctx->r16, 0X158);
    // 0x80013108: bne         $s0, $s1, L_800130FC
    if (ctx->r16 != ctx->r17) {
        // 0x8001310C: nop
    
            goto L_800130FC;
    }
    // 0x8001310C: nop

    // 0x80013110: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80013114: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    // 0x80013118: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001311C: jal         0x8004C4D8
    // 0x80013120: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004C4D8(rdram, ctx);
        goto after_25;
    // 0x80013120: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_25:
    // 0x80013124: jal         0x80049C48
    // 0x80013128: nop

    func_80049C48(rdram, ctx);
        goto after_26;
    // 0x80013128: nop

    after_26:
    // 0x8001312C: jal         0x8004B21C
    // 0x80013130: nop

    func_8004B21C(rdram, ctx);
        goto after_27;
    // 0x80013130: nop

    after_27:
    // 0x80013134: jal         0x8000798C
    // 0x80013138: nop

    func_8000798C(rdram, ctx);
        goto after_28;
    // 0x80013138: nop

    after_28:
    // 0x8001313C: lw          $t2, 0xC00($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC00);
    // 0x80013140: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
L_80013144:
    // 0x80013144: jal         0x8000798C
    // 0x80013148: nop

    func_8000798C(rdram, ctx);
        goto after_29;
    // 0x80013148: nop

    after_29:
    // 0x8001314C: b           L_80013144
    // 0x80013150: nop

        goto L_80013144;
    // 0x80013150: nop

L_80013154:
    // 0x80013154: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x80013158: sh          $t3, 0xAE($sp)
    MEM_H(0XAE, ctx->r29) = ctx->r11;
    // 0x8001315C: jal         0x80044480
    // 0x80013160: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    func_80044480(rdram, ctx);
        goto after_30;
    // 0x80013160: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_30:
    // 0x80013164: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80013168: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001316C: jal         0x8004D134
    // 0x80013170: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_8004D134(rdram, ctx);
        goto after_31;
    // 0x80013170: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_31:
    // 0x80013174: b           L_80013298
    // 0x80013178: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_80013298;
    // 0x80013178: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8001317C:
    // 0x8001317C: jal         0x8004D1F0
    // 0x80013180: nop

    func_8004D1F0(rdram, ctx);
        goto after_32;
    // 0x80013180: nop

    after_32:
    // 0x80013184: bne         $v0, $zero, L_80013294
    if (ctx->r2 != 0) {
        // 0x80013188: addiu       $s0, $sp, 0xBF0
        ctx->r16 = ADD32(ctx->r29, 0XBF0);
            goto L_80013294;
    }
    // 0x80013188: addiu       $s0, $sp, 0xBF0
    ctx->r16 = ADD32(ctx->r29, 0XBF0);
    // 0x8001318C: addiu       $v1, $sp, 0xBF8
    ctx->r3 = ADD32(ctx->r29, 0XBF8);
L_80013190:
    // 0x80013190: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x80013194: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80013198: sltu        $at, $s0, $v1
    ctx->r1 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x8001319C: lw          $v0, 0x8($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X8);
    // 0x800131A0: lw          $t5, 0xD8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XD8);
    // 0x800131A4: and         $t7, $t5, $s2
    ctx->r15 = ctx->r13 & ctx->r18;
    // 0x800131A8: bne         $at, $zero, L_80013190
    if (ctx->r1 != 0) {
        // 0x800131AC: sw          $t7, 0xD8($v0)
        MEM_W(0XD8, ctx->r2) = ctx->r15;
            goto L_80013190;
    }
    // 0x800131AC: sw          $t7, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r15;
    // 0x800131B0: lui         $t8, 0x8001
    ctx->r24 = S32(0X8001 << 16);
    // 0x800131B4: addiu       $t8, $t8, 0x3568
    ctx->r24 = ADD32(ctx->r24, 0X3568);
    // 0x800131B8: sw          $t8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r24;
    // 0x800131BC: addiu       $a3, $sp, 0xE8
    ctx->r7 = ADD32(ctx->r29, 0XE8);
    // 0x800131C0: addiu       $s0, $sp, 0xF0
    ctx->r16 = ADD32(ctx->r29, 0XF0);
    // 0x800131C4: addiu       $a2, $sp, 0xBB0
    ctx->r6 = ADD32(ctx->r29, 0XBB0);
L_800131C8:
    // 0x800131C8: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x800131CC: addiu       $s0, $s0, 0x560
    ctx->r16 = ADD32(ctx->r16, 0X560);
    // 0x800131D0: lw          $v0, 0x8($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X8);
    // 0x800131D4: lw          $t6, 0xD8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XD8);
    // 0x800131D8: and         $t0, $t6, $s2
    ctx->r8 = ctx->r14 & ctx->r18;
    // 0x800131DC: sw          $t0, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r8;
    // 0x800131E0: lw          $t1, -0x404($s0)
    ctx->r9 = MEM_W(ctx->r16, -0X404);
    // 0x800131E4: lw          $v1, 0x8($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X8);
    // 0x800131E8: lw          $t2, 0xD8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XD8);
    // 0x800131EC: and         $t3, $t2, $s2
    ctx->r11 = ctx->r10 & ctx->r18;
    // 0x800131F0: sw          $t3, 0xD8($v1)
    MEM_W(0XD8, ctx->r3) = ctx->r11;
    // 0x800131F4: lw          $t4, -0x2AC($s0)
    ctx->r12 = MEM_W(ctx->r16, -0X2AC);
    // 0x800131F8: lw          $a0, 0x8($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X8);
    // 0x800131FC: lw          $t5, 0xD8($a0)
    ctx->r13 = MEM_W(ctx->r4, 0XD8);
    // 0x80013200: and         $t7, $t5, $s2
    ctx->r15 = ctx->r13 & ctx->r18;
    // 0x80013204: sw          $t7, 0xD8($a0)
    MEM_W(0XD8, ctx->r4) = ctx->r15;
    // 0x80013208: lw          $t8, -0x154($s0)
    ctx->r24 = MEM_W(ctx->r16, -0X154);
    // 0x8001320C: lw          $a1, 0x8($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X8);
    // 0x80013210: lw          $t9, 0xD8($a1)
    ctx->r25 = MEM_W(ctx->r5, 0XD8);
    // 0x80013214: and         $t6, $t9, $s2
    ctx->r14 = ctx->r25 & ctx->r18;
    // 0x80013218: bne         $s0, $a2, L_800131C8
    if (ctx->r16 != ctx->r6) {
        // 0x8001321C: sw          $t6, 0xD8($a1)
        MEM_W(0XD8, ctx->r5) = ctx->r14;
            goto L_800131C8;
    }
    // 0x8001321C: sw          $t6, 0xD8($a1)
    MEM_W(0XD8, ctx->r5) = ctx->r14;
    // 0x80013220: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80013224: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80013228: jal         0x8004C4D8
    // 0x8001322C: sw          $a3, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r7;
    func_8004C4D8(rdram, ctx);
        goto after_33;
    // 0x8001322C: sw          $a3, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r7;
    after_33:
    // 0x80013230: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80013234: lw          $a3, 0x88($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X88);
    // 0x80013238: sw          $t0, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r8;
    // 0x8001323C: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x80013240: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    // 0x80013244: jal         0x80004CE0
    // 0x80013248: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_80004CE0(rdram, ctx);
        goto after_34;
    // 0x80013248: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_34:
    // 0x8001324C: lw          $t1, 0xE8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE8);
    // 0x80013250: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80013254: beql        $t1, $zero, L_80013274
    if (ctx->r9 == 0) {
        // 0x80013258: addiu       $t3, $zero, -0x1
        ctx->r11 = ADD32(0, -0X1);
            goto L_80013274;
    }
    goto skip_5;
    // 0x80013258: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    skip_5:
L_8001325C:
    // 0x8001325C: jal         0x8000798C
    // 0x80013260: nop

    func_8000798C(rdram, ctx);
        goto after_35;
    // 0x80013260: nop

    after_35:
    // 0x80013264: lw          $t2, 0xE8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XE8);
    // 0x80013268: bne         $t2, $zero, L_8001325C
    if (ctx->r10 != 0) {
        // 0x8001326C: nop
    
            goto L_8001325C;
    }
    // 0x8001326C: nop

    // 0x80013270: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
L_80013274:
    // 0x80013274: sw          $t3, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r11;
    // 0x80013278: jal         0x80004E5C
    // 0x8001327C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80004E5C(rdram, ctx);
        goto after_36;
    // 0x8001327C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x80013280: sw          $zero, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = 0;
    // 0x80013284: sw          $zero, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = 0;
    // 0x80013288: sw          $zero, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = 0;
    // 0x8001328C: b           L_80012E44
    // 0x80013290: sw          $zero, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = 0;
        goto L_80012E44;
    // 0x80013290: sw          $zero, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = 0;
L_80013294:
    // 0x80013294: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80013298:
    // 0x80013298: lh          $t4, 0x9A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X9A);
L_8001329C:
    // 0x8001329C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800132A0: sll         $t5, $s1, 2
    ctx->r13 = S32(ctx->r17 << 2);
    // 0x800132A4: beq         $t4, $zero, L_8001330C
    if (ctx->r12 == 0) {
        // 0x800132A8: nop
    
            goto L_8001330C;
    }
    // 0x800132A8: nop

    // 0x800132AC: add.s       $f20, $f30, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f30.fl + ctx->f24.fl;
    // 0x800132B0: lwc1        $f18, 0x6160($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6160);
    // 0x800132B4: subu        $t5, $t5, $s1
    ctx->r13 = SUB32(ctx->r13, ctx->r17);
    // 0x800132B8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800132BC: mul.s       $f22, $f20, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = MUL_S(ctx->f20.fl, ctx->f18.fl);
    // 0x800132C0: subu        $t5, $t5, $s1
    ctx->r13 = SUB32(ctx->r13, ctx->r17);
    // 0x800132C4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800132C8: subu        $t5, $t5, $s1
    ctx->r13 = SUB32(ctx->r13, ctx->r17);
    // 0x800132CC: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800132D0: addu        $s0, $s7, $t5
    ctx->r16 = ADD32(ctx->r23, ctx->r13);
    // 0x800132D4: jal         0x8004F7C0
    // 0x800132D8: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_8004F7C0(rdram, ctx);
        goto after_37;
    // 0x800132D8: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_37:
    // 0x800132DC: mul.s       $f4, $f0, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x800132E0: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x800132E4: jal         0x8004F650
    // 0x800132E8: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    func_8004F650(rdram, ctx);
        goto after_38;
    // 0x800132E8: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    after_38:
    // 0x800132EC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800132F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800132F4: mul.s       $f6, $f0, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x800132F8: sub.s       $f24, $f24, $f26
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f24.fl = ctx->f24.fl - ctx->f26.fl;
    // 0x800132FC: add.s       $f10, $f20, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f20.fl + ctx->f8.fl;
    // 0x80013300: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x80013304: sub.s       $f16, $f10, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f26.fl;
    // 0x80013308: swc1        $f16, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
L_8001330C:
    // 0x8001330C: multu       $s1, $fp
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80013310: mflo        $t7
    ctx->r15 = lo;
    // 0x80013314: addu        $a0, $s7, $t7
    ctx->r4 = ADD32(ctx->r23, ctx->r15);
    // 0x80013318: jal         0x80022440
    // 0x8001331C: nop

    func_80022440(rdram, ctx);
        goto after_39;
    // 0x8001331C: nop

    after_39:
    // 0x80013320: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80013324: slti        $at, $s1, 0x8
    ctx->r1 = SIGNED(ctx->r17) < 0X8 ? 1 : 0;
    // 0x80013328: bnel        $at, $zero, L_8001329C
    if (ctx->r1 != 0) {
        // 0x8001332C: lh          $t4, 0x9A($sp)
        ctx->r12 = MEM_H(ctx->r29, 0X9A);
            goto L_8001329C;
    }
    goto skip_6;
    // 0x8001332C: lh          $t4, 0x9A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X9A);
    skip_6:
    // 0x80013330: sll         $t8, $s3, 1
    ctx->r24 = S32(ctx->r19 << 1);
    // 0x80013334: addiu       $t6, $sp, 0x9C
    ctx->r14 = ADD32(ctx->r29, 0X9C);
    // 0x80013338: addu        $t0, $t8, $t6
    ctx->r8 = ADD32(ctx->r24, ctx->r14);
    // 0x8001333C: sw          $t0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r8;
    // 0x80013340: sw          $t8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r24;
    // 0x80013344: lh          $v1, 0x0($t0)
    ctx->r3 = MEM_H(ctx->r8, 0X0);
    // 0x80013348: lw          $t3, 0xB0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB0);
    // 0x8001334C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80013350: addiu       $s0, $sp, 0xB4
    ctx->r16 = ADD32(ctx->r29, 0XB4);
    // 0x80013354: beq         $t3, $v1, L_80013464
    if (ctx->r11 == ctx->r3) {
        // 0x80013358: sw          $v1, -0x68C8($at)
        MEM_W(-0X68C8, ctx->r1) = ctx->r3;
            goto L_80013464;
    }
    // 0x80013358: sw          $v1, -0x68C8($at)
    MEM_W(-0X68C8, ctx->r1) = ctx->r3;
    // 0x8001335C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_80013360:
    // 0x80013360: beql        $a0, $zero, L_80013374
    if (ctx->r4 == 0) {
        // 0x80013364: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80013374;
    }
    goto skip_7;
    // 0x80013364: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_7:
    // 0x80013368: jal         0x8004C444
    // 0x8001336C: nop

    func_8004C444(rdram, ctx);
        goto after_40;
    // 0x8001336C: nop

    after_40:
    // 0x80013370: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80013374:
    // 0x80013374: addiu       $t4, $sp, 0xC4
    ctx->r12 = ADD32(ctx->r29, 0XC4);
    // 0x80013378: bnel        $s0, $t4, L_80013360
    if (ctx->r16 != ctx->r12) {
        // 0x8001337C: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_80013360;
    }
    goto skip_8;
    // 0x8001337C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_8:
    // 0x80013380: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80013384: lw          $v1, -0x68C8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X68C8);
    // 0x80013388: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    // 0x8001338C: lui         $t0, 0x8007
    ctx->r8 = S32(0X8007 << 16);
    // 0x80013390: addiu       $t0, $t0, -0x69D0
    ctx->r8 = ADD32(ctx->r8, -0X69D0);
    // 0x80013394: addiu       $s0, $s3, 0x1D
    ctx->r16 = ADD32(ctx->r19, 0X1D);
    // 0x80013398: addiu       $s1, $s3, 0x15
    ctx->r17 = ADD32(ctx->r19, 0X15);
    // 0x8001339C: addiu       $a3, $v1, 0xB
    ctx->r7 = ADD32(ctx->r3, 0XB);
    // 0x800133A0: sll         $t8, $s1, 16
    ctx->r24 = S32(ctx->r17 << 16);
    // 0x800133A4: sll         $t5, $s0, 16
    ctx->r13 = S32(ctx->r16 << 16);
    // 0x800133A8: sll         $t2, $a3, 16
    ctx->r10 = S32(ctx->r7 << 16);
    // 0x800133AC: addu        $t1, $t6, $t0
    ctx->r9 = ADD32(ctx->r14, ctx->r8);
    // 0x800133B0: sw          $t1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r9;
    // 0x800133B4: sra         $s0, $t5, 16
    ctx->r16 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800133B8: sra         $s1, $t8, 16
    ctx->r17 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800133BC: sra         $a3, $t2, 16
    ctx->r7 = S32(SIGNED(ctx->r10) >> 16);
    // 0x800133C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800133C4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x800133C8: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x800133CC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800133D0: jal         0x8004C580
    // 0x800133D4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_41;
    // 0x800133D4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_41:
    // 0x800133D8: sll         $a3, $s0, 16
    ctx->r7 = S32(ctx->r16 << 16);
    // 0x800133DC: sra         $t4, $a3, 16
    ctx->r12 = S32(SIGNED(ctx->r7) >> 16);
    // 0x800133E0: sw          $v0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r2;
    // 0x800133E4: or          $a3, $t4, $zero
    ctx->r7 = ctx->r12 | 0;
    // 0x800133E8: addiu       $a0, $zero, -0x70
    ctx->r4 = ADD32(0, -0X70);
    // 0x800133EC: addiu       $a1, $zero, -0x50
    ctx->r5 = ADD32(0, -0X50);
    // 0x800133F0: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x800133F4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800133F8: jal         0x8004C580
    // 0x800133FC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_42;
    // 0x800133FC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_42:
    // 0x80013400: sll         $a3, $s1, 16
    ctx->r7 = S32(ctx->r17 << 16);
    // 0x80013404: sra         $t5, $a3, 16
    ctx->r13 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80013408: sw          $v0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r2;
    // 0x8001340C: or          $a3, $t5, $zero
    ctx->r7 = ctx->r13 | 0;
    // 0x80013410: addiu       $a0, $zero, -0x3C
    ctx->r4 = ADD32(0, -0X3C);
    // 0x80013414: addiu       $a1, $zero, -0x50
    ctx->r5 = ADD32(0, -0X50);
    // 0x80013418: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x8001341C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80013420: jal         0x8004C580
    // 0x80013424: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_43;
    // 0x80013424: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_43:
    // 0x80013428: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x8001342C: sw          $v0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r2;
    // 0x80013430: addiu       $a0, $zero, 0x52
    ctx->r4 = ADD32(0, 0X52);
    // 0x80013434: lh          $v1, 0x0($t7)
    ctx->r3 = MEM_H(ctx->r15, 0X0);
    // 0x80013438: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8001343C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80013440: sll         $a3, $v1, 16
    ctx->r7 = S32(ctx->r3 << 16);
    // 0x80013444: sra         $t8, $a3, 16
    ctx->r24 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80013448: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x8001344C: addiu       $a1, $zero, -0x50
    ctx->r5 = ADD32(0, -0X50);
    // 0x80013450: jal         0x8004C580
    // 0x80013454: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    func_8004C580(rdram, ctx);
        goto after_44;
    // 0x80013454: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    after_44:
    // 0x80013458: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001345C: lw          $v1, -0x68C8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X68C8);
    // 0x80013460: sw          $v0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r2;
L_80013464:
    // 0x80013464: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80013468: mfc1        $a1, $f30
    ctx->r5 = (int32_t)ctx->f30.u32l;
    // 0x8001346C: sw          $v1, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r3;
    // 0x80013470: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80013474: addiu       $a0, $sp, 0xBB0
    ctx->r4 = ADD32(ctx->r29, 0XBB0);
    // 0x80013478: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8001347C: jal         0x80049840
    // 0x80013480: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80049840(rdram, ctx);
        goto after_45;
    // 0x80013480: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_45:
    // 0x80013484: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80013488: lwc1        $f0, 0x6164($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6164);
    // 0x8001348C: lw          $t9, 0xBF4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBF4);
    // 0x80013490: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80013494: lw          $a0, 0x8($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X8);
    // 0x80013498: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8001349C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800134A0: jal         0x80001AB4
    // 0x800134A4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80001AB4(rdram, ctx);
        goto after_46;
    // 0x800134A4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_46:
    // 0x800134A8: lw          $t6, 0xBF4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBF4);
    // 0x800134AC: addiu       $a2, $sp, 0xBB0
    ctx->r6 = ADD32(ctx->r29, 0XBB0);
    // 0x800134B0: lw          $a0, 0x8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X8);
    // 0x800134B4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800134B8: jal         0x80000BD8
    // 0x800134BC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_80000BD8(rdram, ctx);
        goto after_47;
    // 0x800134BC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_47:
    // 0x800134C0: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x800134C4: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x800134C8: addiu       $a0, $a0, -0x69DC
    ctx->r4 = ADD32(ctx->r4, -0X69DC);
    // 0x800134CC: addiu       $v0, $v0, -0x69E8
    ctx->r2 = ADD32(ctx->r2, -0X69E8);
    // 0x800134D0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800134D4:
    // 0x800134D4: lw          $t0, 0xBF4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XBF4);
    // 0x800134D8: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800134DC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800134E0: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x800134E4: addu        $t2, $t1, $v1
    ctx->r10 = ADD32(ctx->r9, ctx->r3);
    // 0x800134E8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800134EC: bne         $v0, $a0, L_800134D4
    if (ctx->r2 != ctx->r4) {
        // 0x800134F0: swc1        $f18, 0x40($t2)
        MEM_W(0X40, ctx->r10) = ctx->f18.u32l;
            goto L_800134D4;
    }
    // 0x800134F0: swc1        $f18, 0x40($t2)
    MEM_W(0X40, ctx->r10) = ctx->f18.u32l;
    // 0x800134F4: jal         0x8000798C
    // 0x800134F8: lh          $s0, 0xAE($sp)
    ctx->r16 = MEM_H(ctx->r29, 0XAE);
    func_8000798C(rdram, ctx);
        goto after_48;
    // 0x800134F8: lh          $s0, 0xAE($sp)
    ctx->r16 = MEM_H(ctx->r29, 0XAE);
    after_48:
    // 0x800134FC: b           L_80012E14
    // 0x80013500: lw          $v0, 0x8C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X8C);
        goto L_80012E14;
    // 0x80013500: lw          $v0, 0x8C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X8C);
    // 0x80013504: nop

    // 0x80013508: nop

    // 0x8001350C: nop

    // 0x80013510: nop

    // 0x80013514: nop

    // 0x80013518: nop

    // 0x8001351C: nop

    // 0x80013520: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x80013524: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80013528: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8001352C: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80013530: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80013534: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x80013538: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x8001353C: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80013540: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x80013544: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x80013548: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x8001354C: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x80013550: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x80013554: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x80013558: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x8001355C: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x80013560: jr          $ra
    // 0x80013564: addiu       $sp, $sp, 0xC00
    ctx->r29 = ADD32(ctx->r29, 0XC00);
    TRACE_RETURN()
    return;
    // 0x80013564: addiu       $sp, $sp, 0xC00
    ctx->r29 = ADD32(ctx->r29, 0XC00);
;}
RECOMP_FUNC void func_80013568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80013568: addiu       $sp, $sp, -0x1E0
    ctx->r29 = ADD32(ctx->r29, -0X1E0);
    // 0x8001356C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80013570: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80013574: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80013578: lui         $at, 0x41D8
    ctx->r1 = S32(0X41D8 << 16);
    // 0x8001357C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80013580: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80013584: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80013588: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8001358C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80013590: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80013594: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80013598: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x8001359C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800135A0: addiu       $v1, $v1, -0x6C40
    ctx->r3 = ADD32(ctx->r3, -0X6C40);
    // 0x800135A4: addiu       $v0, $v0, -0x6C50
    ctx->r2 = ADD32(ctx->r2, -0X6C50);
    // 0x800135A8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800135AC: sw          $s7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r23;
    // 0x800135B0: sw          $s6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r22;
    // 0x800135B4: sw          $a0, 0x1E0($sp)
    MEM_W(0X1E0, ctx->r29) = ctx->r4;
    // 0x800135B8: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x800135BC: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x800135C0: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x800135C4: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x800135C8: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x800135CC: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x800135D0: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800135D4: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800135D8: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x800135DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800135E0: swc1        $f22, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f22.u32l;
    // 0x800135E4: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x800135E8: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x800135EC: swc1        $f20, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f20.u32l;
    // 0x800135F0: swc1        $f20, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f20.u32l;
    // 0x800135F4: jal         0x80020328
    // 0x800135F8: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    func_80020328(rdram, ctx);
        goto after_0;
    // 0x800135F8: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    after_0:
    // 0x800135FC: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80013600: jal         0x80049CFC
    // 0x80013604: addiu       $a0, $a0, 0x6128
    ctx->r4 = ADD32(ctx->r4, 0X6128);
    func_80049CFC(rdram, ctx);
        goto after_1;
    // 0x80013604: addiu       $a0, $a0, 0x6128
    ctx->r4 = ADD32(ctx->r4, 0X6128);
    after_1:
    // 0x80013608: jal         0x80049D80
    // 0x8001360C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80049D80(rdram, ctx);
        goto after_2;
    // 0x8001360C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80013610: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80013614: jal         0x80049DFC
    // 0x80013618: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80049DFC(rdram, ctx);
        goto after_3;
    // 0x80013618: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8001361C: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x80013620: jal         0x8004A148
    // 0x80013624: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8004A148(rdram, ctx);
        goto after_4;
    // 0x80013624: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80013628: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x8001362C: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80013630: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80013634: lw          $a0, 0x8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X8);
    // 0x80013638: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8001363C: jal         0x80001AB4
    // 0x80013640: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80001AB4(rdram, ctx);
        goto after_5;
    // 0x80013640: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_5:
    // 0x80013644: lw          $v1, 0x7C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X7C);
    // 0x80013648: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x8001364C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80013650: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x80013654: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80013658: addiu       $a1, $zero, 0x5F
    ctx->r5 = ADD32(0, 0X5F);
    // 0x8001365C: swc1        $f20, 0x40($t7)
    MEM_W(0X40, ctx->r15) = ctx->f20.u32l;
    // 0x80013660: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x80013664: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x80013668: addiu       $a3, $zero, 0x28
    ctx->r7 = ADD32(0, 0X28);
    // 0x8001366C: swc1        $f20, 0x44($t8)
    MEM_W(0X44, ctx->r24) = ctx->f20.u32l;
    // 0x80013670: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x80013674: swc1        $f10, 0x48($t9)
    MEM_W(0X48, ctx->r25) = ctx->f10.u32l;
    // 0x80013678: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x8001367C: lw          $t1, 0xD8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XD8);
    // 0x80013680: ori         $t2, $t1, 0x8001
    ctx->r10 = ctx->r9 | 0X8001;
    // 0x80013684: sw          $t2, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r10;
    // 0x80013688: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8001368C: jal         0x8004C580
    // 0x80013690: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_6;
    // 0x80013690: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_6:
    // 0x80013694: addiu       $a0, $zero, -0x4C
    ctx->r4 = ADD32(0, -0X4C);
    // 0x80013698: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001369C: addiu       $a2, $zero, -0x7FFF
    ctx->r6 = ADD32(0, -0X7FFF);
    // 0x800136A0: addiu       $a3, $zero, 0x38
    ctx->r7 = ADD32(0, 0X38);
    // 0x800136A4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800136A8: jal         0x8004C580
    // 0x800136AC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_7;
    // 0x800136AC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_7:
    // 0x800136B0: addiu       $a0, $zero, -0x66
    ctx->r4 = ADD32(0, -0X66);
    // 0x800136B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800136B8: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x800136BC: addiu       $a3, $zero, 0x37
    ctx->r7 = ADD32(0, 0X37);
    // 0x800136C0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800136C4: jal         0x8004C580
    // 0x800136C8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_8;
    // 0x800136C8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_8:
    // 0x800136CC: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800136D0: lw          $t0, -0x68C8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X68C8);
    // 0x800136D4: lui         $t4, 0x8007
    ctx->r12 = S32(0X8007 << 16);
    // 0x800136D8: addiu       $t4, $t4, -0x69A8
    ctx->r12 = ADD32(ctx->r12, -0X69A8);
    // 0x800136DC: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x800136E0: addu        $t3, $t3, $t0
    ctx->r11 = ADD32(ctx->r11, ctx->r8);
    // 0x800136E4: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x800136E8: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800136EC: lui         $s4, 0x8007
    ctx->r20 = S32(0X8007 << 16);
    // 0x800136F0: addiu       $s3, $zero, 0x37
    ctx->r19 = ADD32(0, 0X37);
    // 0x800136F4: addiu       $s4, $s4, -0x69A8
    ctx->r20 = ADD32(ctx->r20, -0X69A8);
    // 0x800136F8: addiu       $s5, $s5, -0x68C8
    ctx->r21 = ADD32(ctx->r21, -0X68C8);
    // 0x800136FC: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
    // 0x80013700: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80013704:
    // 0x80013704: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    // 0x80013708: addiu       $s0, $zero, -0x43
    ctx->r16 = ADD32(0, -0X43);
    // 0x8001370C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80013710: blez        $t5, L_80013778
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80013714: sll         $a0, $s0, 16
        ctx->r4 = S32(ctx->r16 << 16);
            goto L_80013778;
    }
    // 0x80013714: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
L_80013718:
    // 0x80013718: sll         $a1, $s3, 16
    ctx->r5 = S32(ctx->r19 << 16);
    // 0x8001371C: sra         $t7, $a1, 16
    ctx->r15 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80013720: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80013724: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80013728: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x8001372C: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x80013730: addiu       $a3, $zero, 0x39
    ctx->r7 = ADD32(0, 0X39);
    // 0x80013734: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80013738: jal         0x8004C580
    // 0x8001373C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_9;
    // 0x8001373C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_9:
    // 0x80013740: lw          $t0, 0x0($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X0);
    // 0x80013744: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80013748: addiu       $s0, $s0, 0xB
    ctx->r16 = ADD32(ctx->r16, 0XB);
    // 0x8001374C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80013750: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80013754: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x80013758: addu        $t2, $s4, $t1
    ctx->r10 = ADD32(ctx->r20, ctx->r9);
    // 0x8001375C: addu        $v1, $t2, $s2
    ctx->r3 = ADD32(ctx->r10, ctx->r18);
    // 0x80013760: lh          $t3, 0x0($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X0);
    // 0x80013764: sll         $t8, $s0, 16
    ctx->r24 = S32(ctx->r16 << 16);
    // 0x80013768: sra         $s0, $t8, 16
    ctx->r16 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8001376C: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80013770: bnel        $at, $zero, L_80013718
    if (ctx->r1 != 0) {
        // 0x80013774: sll         $a0, $s0, 16
        ctx->r4 = S32(ctx->r16 << 16);
            goto L_80013718;
    }
    goto skip_0;
    // 0x80013774: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    skip_0:
L_80013778:
    // 0x80013778: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x8001377C: addiu       $s3, $s3, -0x1A
    ctx->r19 = ADD32(ctx->r19, -0X1A);
    // 0x80013780: slti        $at, $s2, 0xA
    ctx->r1 = SIGNED(ctx->r18) < 0XA ? 1 : 0;
    // 0x80013784: sll         $t4, $s3, 16
    ctx->r12 = S32(ctx->r19 << 16);
    // 0x80013788: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8001378C: bne         $at, $zero, L_80013704
    if (ctx->r1 != 0) {
        // 0x80013790: sra         $s3, $t4, 16
        ctx->r19 = S32(SIGNED(ctx->r12) >> 16);
            goto L_80013704;
    }
    // 0x80013790: sra         $s3, $t4, 16
    ctx->r19 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80013794: addiu       $a3, $t0, 0x29
    ctx->r7 = ADD32(ctx->r8, 0X29);
    // 0x80013798: sll         $t6, $a3, 16
    ctx->r14 = S32(ctx->r7 << 16);
    // 0x8001379C: sra         $a3, $t6, 16
    ctx->r7 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800137A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800137A4: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    // 0x800137A8: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x800137AC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800137B0: jal         0x8004C580
    // 0x800137B4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_10;
    // 0x800137B4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_10:
    // 0x800137B8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800137BC: lh          $a0, -0x6BA8($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X6BA8);
    // 0x800137C0: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
    // 0x800137C4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800137C8: beq         $a0, $s4, L_800137E8
    if (ctx->r4 == ctx->r20) {
        // 0x800137CC: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_800137E8;
    }
    // 0x800137CC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800137D0: beq         $v1, $at, L_800137E8
    if (ctx->r3 == ctx->r1) {
        // 0x800137D4: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800137E8;
    }
    // 0x800137D4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800137D8: beq         $v1, $at, L_800137E8
    if (ctx->r3 == ctx->r1) {
        // 0x800137DC: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_800137E8;
    }
    // 0x800137DC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800137E0: bne         $v1, $at, L_800137F8
    if (ctx->r3 != ctx->r1) {
        // 0x800137E4: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800137F8;
    }
    // 0x800137E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_800137E8:
    // 0x800137E8: addiu       $a3, $a0, 0x31
    ctx->r7 = ADD32(ctx->r4, 0X31);
    // 0x800137EC: sll         $t8, $a3, 16
    ctx->r24 = S32(ctx->r7 << 16);
    // 0x800137F0: b           L_800137F8
    // 0x800137F4: sra         $a3, $t8, 16
    ctx->r7 = S32(SIGNED(ctx->r24) >> 16);
        goto L_800137F8;
    // 0x800137F4: sra         $a3, $t8, 16
    ctx->r7 = S32(SIGNED(ctx->r24) >> 16);
L_800137F8:
    // 0x800137F8: beq         $a3, $zero, L_80013814
    if (ctx->r7 == 0) {
        // 0x800137FC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80013814;
    }
    // 0x800137FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80013800: addiu       $a1, $zero, -0x59
    ctx->r5 = ADD32(0, -0X59);
    // 0x80013804: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x80013808: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001380C: jal         0x8004C580
    // 0x80013810: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_11;
    // 0x80013810: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_11:
L_80013814:
    // 0x80013814: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80013818: ldc1        $f22, 0x6168($at)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r1, 0X6168);
    // 0x8001381C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80013820: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x80013824: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x80013828: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8001382C: addiu       $s0, $s0, -0x2E60
    ctx->r16 = ADD32(ctx->r16, -0X2E60);
    // 0x80013830: addiu       $s1, $s1, -0x2E5E
    ctx->r17 = ADD32(ctx->r17, -0X2E5E);
    // 0x80013834: addiu       $s2, $s2, -0x2E5A
    ctx->r18 = ADD32(ctx->r18, -0X2E5A);
    // 0x80013838: ldc1        $f20, 0x6170($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, 0X6170);
    // 0x8001383C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80013840:
    // 0x80013840: beq         $s6, $zero, L_80013868
    if (ctx->r22 == 0) {
        // 0x80013844: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80013868;
    }
    // 0x80013844: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80013848: beq         $s6, $s3, L_80013884
    if (ctx->r22 == ctx->r19) {
        // 0x8001384C: nop
    
            goto L_80013884;
    }
    // 0x8001384C: nop

    // 0x80013850: beql        $s6, $s4, L_800138A8
    if (ctx->r22 == ctx->r20) {
        // 0x80013854: lhu         $t2, 0x0($s2)
        ctx->r10 = MEM_HU(ctx->r18, 0X0);
            goto L_800138A8;
    }
    goto skip_1;
    // 0x80013854: lhu         $t2, 0x0($s2)
    ctx->r10 = MEM_HU(ctx->r18, 0X0);
    skip_1:
    // 0x80013858: beq         $s6, $at, L_800138D8
    if (ctx->r22 == ctx->r1) {
        // 0x8001385C: nop
    
            goto L_800138D8;
    }
    // 0x8001385C: nop

    // 0x80013860: b           L_80013940
    // 0x80013864: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
        goto L_80013940;
    // 0x80013864: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
L_80013868:
    // 0x80013868: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
    // 0x8001386C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80013870: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80013874: jal         0x8004D134
    // 0x80013878: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    func_8004D134(rdram, ctx);
        goto after_12;
    // 0x80013878: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    after_12:
    // 0x8001387C: b           L_80013940
    // 0x80013880: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
        goto L_80013940;
    // 0x80013880: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
L_80013884:
    // 0x80013884: jal         0x8004D1F0
    // 0x80013888: nop

    func_8004D1F0(rdram, ctx);
        goto after_13;
    // 0x80013888: nop

    after_13:
    // 0x8001388C: bnel        $v0, $zero, L_80013940
    if (ctx->r2 != 0) {
        // 0x80013890: lw          $t5, 0x8C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X8C);
            goto L_80013940;
    }
    goto skip_2;
    // 0x80013890: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    skip_2:
    // 0x80013894: sll         $s6, $s4, 16
    ctx->r22 = S32(ctx->r20 << 16);
    // 0x80013898: sra         $t1, $s6, 16
    ctx->r9 = S32(SIGNED(ctx->r22) >> 16);
    // 0x8001389C: b           L_8001393C
    // 0x800138A0: or          $s6, $t1, $zero
    ctx->r22 = ctx->r9 | 0;
        goto L_8001393C;
    // 0x800138A0: or          $s6, $t1, $zero
    ctx->r22 = ctx->r9 | 0;
    // 0x800138A4: lhu         $t2, 0x0($s2)
    ctx->r10 = MEM_HU(ctx->r18, 0X0);
L_800138A8:
    // 0x800138A8: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x800138AC: andi        $t3, $t2, 0x4000
    ctx->r11 = ctx->r10 & 0X4000;
    // 0x800138B0: beql        $t3, $zero, L_80013940
    if (ctx->r11 == 0) {
        // 0x800138B4: lw          $t5, 0x8C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X8C);
            goto L_80013940;
    }
    goto skip_3;
    // 0x800138B4: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    skip_3:
    // 0x800138B8: jal         0x80044480
    // 0x800138BC: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
    func_80044480(rdram, ctx);
        goto after_14;
    // 0x800138BC: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
    after_14:
    // 0x800138C0: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x800138C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800138C8: jal         0x8004D134
    // 0x800138CC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_8004D134(rdram, ctx);
        goto after_15;
    // 0x800138CC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_15:
    // 0x800138D0: b           L_80013940
    // 0x800138D4: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
        goto L_80013940;
    // 0x800138D4: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
L_800138D8:
    // 0x800138D8: jal         0x8004D1F0
    // 0x800138DC: nop

    func_8004D1F0(rdram, ctx);
        goto after_16;
    // 0x800138DC: nop

    after_16:
    // 0x800138E0: bnel        $v0, $zero, L_80013940
    if (ctx->r2 != 0) {
        // 0x800138E4: lw          $t5, 0x8C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X8C);
            goto L_80013940;
    }
    goto skip_4;
    // 0x800138E4: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    skip_4:
    // 0x800138E8: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x800138EC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800138F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800138F4: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
    // 0x800138F8: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x800138FC: jal         0x8004A0C4
    // 0x80013900: addiu       $s0, $zero, -0x43
    ctx->r16 = ADD32(0, -0X43);
    func_8004A0C4(rdram, ctx);
        goto after_17;
    // 0x80013900: addiu       $s0, $zero, -0x43
    ctx->r16 = ADD32(0, -0X43);
    after_17:
    // 0x80013904: jal         0x8004A0C4
    // 0x80013908: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    func_8004A0C4(rdram, ctx);
        goto after_18;
    // 0x80013908: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    after_18:
    // 0x8001390C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80013910: jal         0x8004C4D8
    // 0x80013914: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004C4D8(rdram, ctx);
        goto after_19;
    // 0x80013914: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x80013918: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8001391C: jal         0x8004C4D8
    // 0x80013920: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004C4D8(rdram, ctx);
        goto after_20;
    // 0x80013920: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
    // 0x80013924: lw          $t4, 0x1E0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1E0);
    // 0x80013928: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
L_8001392C:
    // 0x8001392C: jal         0x8000798C
    // 0x80013930: nop

    func_8000798C(rdram, ctx);
        goto after_21;
    // 0x80013930: nop

    after_21:
    // 0x80013934: b           L_8001392C
    // 0x80013938: nop

        goto L_8001392C;
    // 0x80013938: nop

L_8001393C:
    // 0x8001393C: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
L_80013940:
    // 0x80013940: lw          $v0, 0x8($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X8);
    // 0x80013944: lw          $t6, 0xD8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XD8);
    // 0x80013948: ori         $t7, $t6, 0x8001
    ctx->r15 = ctx->r14 | 0X8001;
    // 0x8001394C: beq         $s7, $zero, L_80013A08
    if (ctx->r23 == 0) {
        // 0x80013950: sw          $t7, 0xD8($v0)
        MEM_W(0XD8, ctx->r2) = ctx->r15;
            goto L_80013A08;
    }
    // 0x80013950: sw          $t7, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r15;
    // 0x80013954: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x80013958: lwc1        $f16, 0xA0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8001395C: slti        $at, $v0, 0x1A
    ctx->r1 = SIGNED(ctx->r2) < 0X1A ? 1 : 0;
    // 0x80013960: bnel        $at, $zero, L_80013980
    if (ctx->r1 != 0) {
        // 0x80013964: slti        $at, $v0, -0x19
        ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
            goto L_80013980;
    }
    goto skip_5;
    // 0x80013964: slti        $at, $v0, -0x19
    ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
    skip_5:
    // 0x80013968: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8001396C: add.d       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = ctx->f18.d + ctx->f20.d;
    // 0x80013970: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80013974: b           L_80013998
    // 0x80013978: swc1        $f6, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f6.u32l;
        goto L_80013998;
    // 0x80013978: swc1        $f6, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f6.u32l;
    // 0x8001397C: slti        $at, $v0, -0x19
    ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
L_80013980:
    // 0x80013980: beq         $at, $zero, L_80013998
    if (ctx->r1 == 0) {
        // 0x80013984: lwc1        $f8, 0xA0($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0XA0);
            goto L_80013998;
    }
    // 0x80013984: lwc1        $f8, 0xA0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80013988: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8001398C: sub.d       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = ctx->f10.d - ctx->f20.d;
    // 0x80013990: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80013994: swc1        $f18, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f18.u32l;
L_80013998:
    // 0x80013998: lh          $v0, 0x0($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X0);
    // 0x8001399C: lwc1        $f4, 0x9C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800139A0: slti        $at, $v0, 0x1A
    ctx->r1 = SIGNED(ctx->r2) < 0X1A ? 1 : 0;
    // 0x800139A4: bnel        $at, $zero, L_800139C4
    if (ctx->r1 != 0) {
        // 0x800139A8: slti        $at, $v0, -0x19
        ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
            goto L_800139C4;
    }
    goto skip_6;
    // 0x800139A8: slti        $at, $v0, -0x19
    ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
    skip_6:
    // 0x800139AC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800139B0: sub.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = ctx->f6.d - ctx->f20.d;
    // 0x800139B4: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x800139B8: b           L_800139DC
    // 0x800139BC: swc1        $f10, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f10.u32l;
        goto L_800139DC;
    // 0x800139BC: swc1        $f10, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f10.u32l;
    // 0x800139C0: slti        $at, $v0, -0x19
    ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
L_800139C4:
    // 0x800139C4: beq         $at, $zero, L_800139DC
    if (ctx->r1 == 0) {
        // 0x800139C8: lwc1        $f16, 0x9C($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X9C);
            goto L_800139DC;
    }
    // 0x800139C8: lwc1        $f16, 0x9C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800139CC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800139D0: add.d       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = ctx->f18.d + ctx->f20.d;
    // 0x800139D4: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800139D8: swc1        $f6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f6.u32l;
L_800139DC:
    // 0x800139DC: lhu         $t8, 0x0($s2)
    ctx->r24 = MEM_HU(ctx->r18, 0X0);
    // 0x800139E0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800139E4: andi        $t9, $t8, 0x2000
    ctx->r25 = ctx->r24 & 0X2000;
    // 0x800139E8: beq         $t9, $zero, L_80013A3C
    if (ctx->r25 == 0) {
        // 0x800139EC: nop
    
            goto L_80013A3C;
    }
    // 0x800139EC: nop

    // 0x800139F0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800139F4: lwc1        $f10, 0x6178($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6178);
    // 0x800139F8: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800139FC: swc1        $f8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f8.u32l;
    // 0x80013A00: b           L_80013A3C
    // 0x80013A04: swc1        $f10, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f10.u32l;
        goto L_80013A3C;
    // 0x80013A04: swc1        $f10, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f10.u32l;
L_80013A08:
    // 0x80013A08: lwc1        $f16, 0xA0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80013A0C: lh          $t1, 0x0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X0);
    // 0x80013A10: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80013A14: bne         $t1, $zero, L_80013A28
    if (ctx->r9 != 0) {
        // 0x80013A18: add.d       $f4, $f18, $f22
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f22.d); 
    ctx->f4.d = ctx->f18.d + ctx->f22.d;
            goto L_80013A28;
    }
    // 0x80013A18: add.d       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f22.d); 
    ctx->f4.d = ctx->f18.d + ctx->f22.d;
    // 0x80013A1C: lh          $t2, 0x0($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X0);
    // 0x80013A20: beql        $t2, $zero, L_80013A38
    if (ctx->r10 == 0) {
        // 0x80013A24: cvt.s.d     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
            goto L_80013A38;
    }
    goto skip_7;
    // 0x80013A24: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    skip_7:
L_80013A28:
    // 0x80013A28: sll         $s7, $s3, 16
    ctx->r23 = S32(ctx->r19 << 16);
    // 0x80013A2C: sra         $t3, $s7, 16
    ctx->r11 = S32(SIGNED(ctx->r23) >> 16);
    // 0x80013A30: or          $s7, $t3, $zero
    ctx->r23 = ctx->r11 | 0;
    // 0x80013A34: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
L_80013A38:
    // 0x80013A38: swc1        $f6, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f6.u32l;
L_80013A3C:
    // 0x80013A3C: jal         0x80022440
    // 0x80013A40: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    func_80022440(rdram, ctx);
        goto after_22;
    // 0x80013A40: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    after_22:
    // 0x80013A44: jal         0x8000798C
    // 0x80013A48: nop

    func_8000798C(rdram, ctx);
        goto after_23;
    // 0x80013A48: nop

    after_23:
    // 0x80013A4C: b           L_80013840
    // 0x80013A50: nop

        goto L_80013840;
    // 0x80013A50: nop

    // 0x80013A54: nop

    // 0x80013A58: nop

    // 0x80013A5C: nop

    // 0x80013A60: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80013A64: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80013A68: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80013A6C: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80013A70: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80013A74: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x80013A78: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x80013A7C: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x80013A80: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x80013A84: lw          $s6, 0x44($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X44);
    // 0x80013A88: lw          $s7, 0x48($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X48);
    // 0x80013A8C: jr          $ra
    // 0x80013A90: addiu       $sp, $sp, 0x1E0
    ctx->r29 = ADD32(ctx->r29, 0X1E0);
    TRACE_RETURN()
    return;
    // 0x80013A90: addiu       $sp, $sp, 0x1E0
    ctx->r29 = ADD32(ctx->r29, 0X1E0);
;}
RECOMP_FUNC void func_80013A94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80013A94: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80013A98: lw          $t6, -0x68C8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X68C8);
    // 0x80013A9C: lui         $t8, 0x8007
    ctx->r24 = S32(0X8007 << 16);
    // 0x80013AA0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80013AA4: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80013AA8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80013AAC: lh          $t8, -0x69BC($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X69BC);
    // 0x80013AB0: jr          $ra
    // 0x80013AB4: sh          $t8, -0x6BA8($at)
    MEM_H(-0X6BA8, ctx->r1) = ctx->r24;
    TRACE_RETURN()
    return;
    // 0x80013AB4: sh          $t8, -0x6BA8($at)
    MEM_H(-0X6BA8, ctx->r1) = ctx->r24;
;}
RECOMP_FUNC void func_80013AC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80013AC0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80013AC4: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80013AC8: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80013ACC: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80013AD0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80013AD4: sll         $s6, $a1, 16
    ctx->r22 = S32(ctx->r5 << 16);
    // 0x80013AD8: sll         $s2, $t7, 16
    ctx->r18 = S32(ctx->r15 << 16);
    // 0x80013ADC: sra         $t8, $s6, 16
    ctx->r24 = S32(SIGNED(ctx->r22) >> 16);
    // 0x80013AE0: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80013AE4: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80013AE8: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80013AEC: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80013AF0: sra         $t9, $s2, 16
    ctx->r25 = S32(SIGNED(ctx->r18) >> 16);
    // 0x80013AF4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80013AF8: or          $s6, $t8, $zero
    ctx->r22 = ctx->r24 | 0;
    // 0x80013AFC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80013B00: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80013B04: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80013B08: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80013B0C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80013B10: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80013B14: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x80013B18: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80013B1C: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80013B20: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
    // 0x80013B24: bgez        $a2, L_80013B34
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80013B28: or          $s4, $a2, $zero
        ctx->r20 = ctx->r6 | 0;
            goto L_80013B34;
    }
    // 0x80013B28: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x80013B2C: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x80013B30: negu        $s4, $a2
    ctx->r20 = SUB32(0, ctx->r6);
L_80013B34:
    // 0x80013B34: lh          $t0, 0x56($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X56);
    // 0x80013B38: lui         $s1, 0x8007
    ctx->r17 = S32(0X8007 << 16);
    // 0x80013B3C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80013B40: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80013B44: addu        $s1, $s1, $t1
    ctx->r17 = ADD32(ctx->r17, ctx->r9);
    // 0x80013B48: blez        $t0, L_80013CA0
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80013B4C: lw          $s1, -0x6940($s1)
        ctx->r17 = MEM_W(ctx->r17, -0X6940);
            goto L_80013CA0;
    }
    // 0x80013B4C: lw          $s1, -0x6940($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X6940);
    // 0x80013B50: lh          $s7, 0x5A($sp)
    ctx->r23 = MEM_H(ctx->r29, 0X5A);
L_80013B54:
    // 0x80013B54: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80013B58: bne         $s1, $at, L_80013B64
    if (ctx->r17 != ctx->r1) {
        // 0x80013B5C: nop
    
            goto L_80013B64;
    }
    // 0x80013B5C: nop

    // 0x80013B60: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_80013B64:
    // 0x80013B64: div         $zero, $s4, $s1
    lo = S32(S64(S32(ctx->r20)) / S64(S32(ctx->r17))); hi = S32(S64(S32(ctx->r20)) % S64(S32(ctx->r17)));
    // 0x80013B68: bne         $s1, $zero, L_80013B74
    if (ctx->r17 != 0) {
        // 0x80013B6C: nop
    
            goto L_80013B74;
    }
    // 0x80013B6C: nop

    // 0x80013B70: break       7
    do_break(2147564400);
L_80013B74:
    // 0x80013B74: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80013B78: bne         $s1, $at, L_80013B8C
    if (ctx->r17 != ctx->r1) {
        // 0x80013B7C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80013B8C;
    }
    // 0x80013B7C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80013B80: bne         $s4, $at, L_80013B8C
    if (ctx->r20 != ctx->r1) {
        // 0x80013B84: nop
    
            goto L_80013B8C;
    }
    // 0x80013B84: nop

    // 0x80013B88: break       6
    do_break(2147564424);
L_80013B8C:
    // 0x80013B8C: mflo        $v0
    ctx->r2 = lo;
    // 0x80013B90: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80013B94: bne         $v0, $zero, L_80013BAC
    if (ctx->r2 != 0) {
        // 0x80013B98: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_80013BAC;
    }
    // 0x80013B98: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80013B9C: bne         $s5, $zero, L_80013BB0
    if (ctx->r21 != 0) {
        // 0x80013BA0: nop
    
            goto L_80013BB0;
    }
    // 0x80013BA0: nop

    // 0x80013BA4: b           L_80013BB0
    // 0x80013BA8: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
        goto L_80013BB0;
    // 0x80013BA8: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
L_80013BAC:
    // 0x80013BAC: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_80013BB0:
    // 0x80013BB0: beql        $s0, $at, L_80013C74
    if (ctx->r16 == ctx->r1) {
        // 0x80013BB4: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80013C74;
    }
    goto skip_0;
    // 0x80013BB4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    skip_0:
    // 0x80013BB8: beq         $fp, $zero, L_80013BF8
    if (ctx->r30 == 0) {
        // 0x80013BBC: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_80013BF8;
    }
    // 0x80013BBC: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80013BC0: beq         $s7, $zero, L_80013BCC
    if (ctx->r23 == 0) {
        // 0x80013BC4: or          $fp, $zero, $zero
        ctx->r30 = 0 | 0;
            goto L_80013BCC;
    }
    // 0x80013BC4: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80013BC8: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
L_80013BCC:
    // 0x80013BCC: subu        $a0, $s2, $v0
    ctx->r4 = SUB32(ctx->r18, ctx->r2);
    // 0x80013BD0: sll         $a1, $s6, 16
    ctx->r5 = S32(ctx->r22 << 16);
    // 0x80013BD4: sra         $t4, $a1, 16
    ctx->r12 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80013BD8: sll         $t2, $a0, 16
    ctx->r10 = S32(ctx->r4 << 16);
    // 0x80013BDC: sra         $a0, $t2, 16
    ctx->r4 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80013BE0: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x80013BE4: addiu       $a2, $zero, -0x100
    ctx->r6 = ADD32(0, -0X100);
    // 0x80013BE8: addiu       $a3, $zero, 0x2D
    ctx->r7 = ADD32(0, 0X2D);
    // 0x80013BEC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80013BF0: jal         0x8004C580
    // 0x80013BF4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_0;
    // 0x80013BF4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_0:
L_80013BF8:
    // 0x80013BF8: beq         $s7, $zero, L_80013C2C
    if (ctx->r23 == 0) {
        // 0x80013BFC: addiu       $a0, $s2, -0x7
        ctx->r4 = ADD32(ctx->r18, -0X7);
            goto L_80013C2C;
    }
    // 0x80013BFC: addiu       $a0, $s2, -0x7
    ctx->r4 = ADD32(ctx->r18, -0X7);
    // 0x80013C00: sll         $a1, $s6, 16
    ctx->r5 = S32(ctx->r22 << 16);
    // 0x80013C04: sra         $t7, $a1, 16
    ctx->r15 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80013C08: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x80013C0C: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80013C10: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80013C14: addiu       $a2, $zero, -0x100
    ctx->r6 = ADD32(0, -0X100);
    // 0x80013C18: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x80013C1C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80013C20: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80013C24: jal         0x8004C580
    // 0x80013C28: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    func_8004C580(rdram, ctx);
        goto after_1;
    // 0x80013C28: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    after_1:
L_80013C2C:
    // 0x80013C2C: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x80013C30: sll         $a1, $s6, 16
    ctx->r5 = S32(ctx->r22 << 16);
    // 0x80013C34: addiu       $a3, $s0, 0x22
    ctx->r7 = ADD32(ctx->r16, 0X22);
    // 0x80013C38: sll         $t1, $a3, 16
    ctx->r9 = S32(ctx->r7 << 16);
    // 0x80013C3C: sra         $t9, $a1, 16
    ctx->r25 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80013C40: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80013C44: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80013C48: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x80013C4C: sra         $a3, $t1, 16
    ctx->r7 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80013C50: addiu       $a2, $zero, -0x100
    ctx->r6 = ADD32(0, -0X100);
    // 0x80013C54: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80013C58: jal         0x8004C580
    // 0x80013C5C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_2;
    // 0x80013C5C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_2:
    // 0x80013C60: multu       $s0, $s1
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80013C64: mflo        $t2
    ctx->r10 = lo;
    // 0x80013C68: subu        $s4, $s4, $t2
    ctx->r20 = SUB32(ctx->r20, ctx->r10);
    // 0x80013C6C: nop

    // 0x80013C70: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
L_80013C74:
    // 0x80013C74: div         $zero, $s1, $at
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r1)));
    // 0x80013C78: lh          $t6, 0x56($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X56);
    // 0x80013C7C: addiu       $s2, $s2, 0x7
    ctx->r18 = ADD32(ctx->r18, 0X7);
    // 0x80013C80: sll         $t4, $s2, 16
    ctx->r12 = S32(ctx->r18 << 16);
    // 0x80013C84: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80013C88: mflo        $t3
    ctx->r11 = lo;
    // 0x80013C8C: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80013C90: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
    // 0x80013C94: bne         $s3, $t6, L_80013B54
    if (ctx->r19 != ctx->r14) {
        // 0x80013C98: or          $s2, $t5, $zero
        ctx->r18 = ctx->r13 | 0;
            goto L_80013B54;
    }
    // 0x80013C98: or          $s2, $t5, $zero
    ctx->r18 = ctx->r13 | 0;
    // 0x80013C9C: sh          $s7, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r23;
L_80013CA0:
    // 0x80013CA0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80013CA4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80013CA8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80013CAC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80013CB0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80013CB4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80013CB8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80013CBC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80013CC0: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80013CC4: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80013CC8: jr          $ra
    // 0x80013CCC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    TRACE_RETURN()
    return;
    // 0x80013CCC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80013CD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80013CD0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80013CD4: lh          $v0, -0x6BA6($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X6BA6);
    // 0x80013CD8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80013CDC: beq         $v0, $zero, L_80013D44
    if (ctx->r2 == 0) {
        // 0x80013CE0: nop
    
            goto L_80013D44;
    }
    // 0x80013CE0: nop

    // 0x80013CE4: blez        $v0, L_80013D30
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80013CE8: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_80013D30;
    }
    // 0x80013CE8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80013CEC: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80013CF0: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x80013CF4: addiu       $a0, $t6, -0x6BC8
    ctx->r4 = ADD32(ctx->r14, -0X6BC8);
    // 0x80013CF8: addu        $a1, $t7, $a0
    ctx->r5 = ADD32(ctx->r15, ctx->r4);
    // 0x80013CFC: addiu       $v0, $v0, -0x691C
    ctx->r2 = ADD32(ctx->r2, -0X691C);
    // 0x80013D00: lh          $t8, 0x0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X0);
L_80013D04:
    // 0x80013D04: lh          $t2, 0x2($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X2);
    // 0x80013D08: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80013D0C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80013D10: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x80013D14: lh          $t1, -0x2($t0)
    ctx->r9 = MEM_H(ctx->r8, -0X2);
    // 0x80013D18: sltu        $at, $a0, $a1
    ctx->r1 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x80013D1C: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80013D20: mflo        $t3
    ctx->r11 = lo;
    // 0x80013D24: addu        $v1, $v1, $t3
    ctx->r3 = ADD32(ctx->r3, ctx->r11);
    // 0x80013D28: bnel        $at, $zero, L_80013D04
    if (ctx->r1 != 0) {
        // 0x80013D2C: lh          $t8, 0x0($a0)
        ctx->r24 = MEM_H(ctx->r4, 0X0);
            goto L_80013D04;
    }
    goto skip_0;
    // 0x80013D2C: lh          $t8, 0x0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X0);
    skip_0:
L_80013D30:
    // 0x80013D30: bgez        $v1, L_80013D40
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80013D34: sra         $t4, $v1, 1
        ctx->r12 = S32(SIGNED(ctx->r3) >> 1);
            goto L_80013D40;
    }
    // 0x80013D34: sra         $t4, $v1, 1
    ctx->r12 = S32(SIGNED(ctx->r3) >> 1);
    // 0x80013D38: addiu       $at, $v1, 0x1
    ctx->r1 = ADD32(ctx->r3, 0X1);
    // 0x80013D3C: sra         $t4, $at, 1
    ctx->r12 = S32(SIGNED(ctx->r1) >> 1);
L_80013D40:
    // 0x80013D40: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
L_80013D44:
    // 0x80013D44: jr          $ra
    // 0x80013D48: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    TRACE_RETURN()
    return;
    // 0x80013D48: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80013D4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80013D4C: addiu       $sp, $sp, -0x1A0
    ctx->r29 = ADD32(ctx->r29, -0X1A0);
    // 0x80013D50: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80013D54: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80013D58: sw          $a0, 0x1A0($sp)
    MEM_W(0X1A0, ctx->r29) = ctx->r4;
    // 0x80013D5C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80013D60: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80013D64: sh          $zero, 0x180($sp)
    MEM_H(0X180, ctx->r29) = 0;
    // 0x80013D68: sh          $zero, 0x176($sp)
    MEM_H(0X176, ctx->r29) = 0;
    // 0x80013D6C: sh          $zero, 0x174($sp)
    MEM_H(0X174, ctx->r29) = 0;
    // 0x80013D70: sh          $zero, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = 0;
    // 0x80013D74: sh          $zero, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = 0;
    // 0x80013D78: sh          $zero, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = 0;
    // 0x80013D7C: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    // 0x80013D80: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
    // 0x80013D84: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80013D88: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80013D8C: jal         0x8004D134
    // 0x80013D90: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    func_8004D134(rdram, ctx);
        goto after_0;
    // 0x80013D90: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80013D94: lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // 0x80013D98: addiu       $a0, $a0, -0x3900
    ctx->r4 = ADD32(ctx->r4, -0X3900);
    // 0x80013D9C: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    // 0x80013DA0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80013DA4: jal         0x80004CE0
    // 0x80013DA8: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    func_80004CE0(rdram, ctx);
        goto after_1;
    // 0x80013DA8: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    after_1:
    // 0x80013DAC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80013DB0: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x80013DB4: jal         0x800499B0
    // 0x80013DB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800499B0(rdram, ctx);
        goto after_2;
    // 0x80013DB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80013DBC: jal         0x8004B1E0
    // 0x80013DC0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_8004B1E0(rdram, ctx);
        goto after_3;
    // 0x80013DC0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_3:
    // 0x80013DC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80013DC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80013DCC: jal         0x8000BD4C
    // 0x80013DD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BD4C(rdram, ctx);
        goto after_4;
    // 0x80013DD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80013DD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80013DD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80013DDC: jal         0x8000BDEC
    // 0x80013DE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BDEC(rdram, ctx);
        goto after_5;
    // 0x80013DE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x80013DE4: addiu       $t7, $zero, 0x3E8
    ctx->r15 = ADD32(0, 0X3E8);
    // 0x80013DE8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80013DEC: sw          $t7, -0x2CF8($at)
    MEM_W(-0X2CF8, ctx->r1) = ctx->r15;
    // 0x80013DF0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80013DF4: addiu       $t8, $zero, 0x3D0
    ctx->r24 = ADD32(0, 0X3D0);
    // 0x80013DF8: sw          $t8, -0x2CF4($at)
    MEM_W(-0X2CF4, ctx->r1) = ctx->r24;
    // 0x80013DFC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80013E00: sh          $zero, -0x2CC4($at)
    MEM_H(-0X2CC4, ctx->r1) = 0;
    // 0x80013E04: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80013E08: lui         $at, 0x4238
    ctx->r1 = S32(0X4238 << 16);
    // 0x80013E0C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80013E10: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80013E14: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80013E18: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80013E1C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80013E20: addiu       $v1, $v1, -0x6C40
    ctx->r3 = ADD32(ctx->r3, -0X6C40);
    // 0x80013E24: addiu       $v0, $v0, -0x6C50
    ctx->r2 = ADD32(ctx->r2, -0X6C50);
    // 0x80013E28: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80013E2C: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x80013E30: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x80013E34: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x80013E38: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80013E3C: jal         0x8000798C
    // 0x80013E40: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    func_8000798C(rdram, ctx);
        goto after_6;
    // 0x80013E40: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    after_6:
    // 0x80013E44: jal         0x8000798C
    // 0x80013E48: nop

    func_8000798C(rdram, ctx);
        goto after_7;
    // 0x80013E48: nop

    after_7:
    // 0x80013E4C: jal         0x8000798C
    // 0x80013E50: nop

    func_8000798C(rdram, ctx);
        goto after_8;
    // 0x80013E50: nop

    after_8:
    // 0x80013E54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80013E58: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x80013E5C: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x80013E60: addiu       $a3, $zero, 0x2E
    ctx->r7 = ADD32(0, 0X2E);
    // 0x80013E64: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80013E68: jal         0x8004C580
    // 0x80013E6C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_9;
    // 0x80013E6C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_9:
    // 0x80013E70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80013E74: addiu       $a1, $zero, -0x32
    ctx->r5 = ADD32(0, -0X32);
    // 0x80013E78: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x80013E7C: addiu       $a3, $zero, 0xB
    ctx->r7 = ADD32(0, 0XB);
    // 0x80013E80: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80013E84: jal         0x8004C580
    // 0x80013E88: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_10;
    // 0x80013E88: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_10:
    // 0x80013E8C: addiu       $a0, $zero, 0x73
    ctx->r4 = ADD32(0, 0X73);
    // 0x80013E90: addiu       $a1, $zero, -0x58
    ctx->r5 = ADD32(0, -0X58);
    // 0x80013E94: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x80013E98: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x80013E9C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80013EA0: jal         0x8004C580
    // 0x80013EA4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_11;
    // 0x80013EA4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_11:
    // 0x80013EA8: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80013EAC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80013EB0: addiu       $v0, $v0, -0x6BA8
    ctx->r2 = ADD32(ctx->r2, -0X6BA8);
    // 0x80013EB4: addiu       $t1, $t1, -0x6BC8
    ctx->r9 = ADD32(ctx->r9, -0X6BC8);
L_80013EB8:
    // 0x80013EB8: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x80013EBC: sltu        $at, $t1, $v0
    ctx->r1 = ctx->r9 < ctx->r2 ? 1 : 0;
    // 0x80013EC0: sh          $zero, -0x4($t1)
    MEM_H(-0X4, ctx->r9) = 0;
    // 0x80013EC4: bne         $at, $zero, L_80013EB8
    if (ctx->r1 != 0) {
        // 0x80013EC8: sh          $zero, -0x2($t1)
        MEM_H(-0X2, ctx->r9) = 0;
            goto L_80013EB8;
    }
    // 0x80013EC8: sh          $zero, -0x2($t1)
    MEM_H(-0X2, ctx->r9) = 0;
    // 0x80013ECC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80013ED0: sh          $zero, -0x6BA6($at)
    MEM_H(-0X6BA6, ctx->r1) = 0;
    // 0x80013ED4: addiu       $v0, $sp, 0x12C
    ctx->r2 = ADD32(ctx->r29, 0X12C);
    // 0x80013ED8: addiu       $v1, $sp, 0x16C
    ctx->r3 = ADD32(ctx->r29, 0X16C);
L_80013EDC:
    // 0x80013EDC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80013EE0: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80013EE4: bne         $at, $zero, L_80013EDC
    if (ctx->r1 != 0) {
        // 0x80013EE8: sh          $zero, -0x4($v0)
        MEM_H(-0X4, ctx->r2) = 0;
            goto L_80013EDC;
    }
    // 0x80013EE8: sh          $zero, -0x4($v0)
    MEM_H(-0X4, ctx->r2) = 0;
    // 0x80013EEC: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x80013EF0: addiu       $v0, $v0, -0x691C
    ctx->r2 = ADD32(ctx->r2, -0X691C);
    // 0x80013EF4: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x80013EF8: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x80013EFC: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80013F00: sw          $t6, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r14;
    // 0x80013F04: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x80013F08: sw          $t8, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r24;
    // 0x80013F0C: lh          $t8, 0x6($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X6);
    // 0x80013F10: sh          $t9, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r25;
    // 0x80013F14: sw          $t6, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r14;
    // 0x80013F18: lh          $t6, 0x8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X8);
    // 0x80013F1C: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x80013F20: sh          $t9, 0x142($sp)
    MEM_H(0X142, ctx->r29) = ctx->r25;
    // 0x80013F24: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x80013F28: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x80013F2C: sw          $t8, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r24;
    // 0x80013F30: lh          $t8, 0xA($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XA);
    // 0x80013F34: sh          $t7, 0x13A($sp)
    MEM_H(0X13A, ctx->r29) = ctx->r15;
    // 0x80013F38: sh          $t9, 0x152($sp)
    MEM_H(0X152, ctx->r29) = ctx->r25;
    // 0x80013F3C: sw          $t6, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r14;
    // 0x80013F40: lh          $t6, 0xC($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XC);
    // 0x80013F44: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x80013F48: addiu       $t9, $zero, 0xB
    ctx->r25 = ADD32(0, 0XB);
    // 0x80013F4C: sh          $t7, 0x14A($sp)
    MEM_H(0X14A, ctx->r29) = ctx->r15;
    // 0x80013F50: sh          $t9, 0x162($sp)
    MEM_H(0X162, ctx->r29) = ctx->r25;
    // 0x80013F54: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80013F58: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80013F5C: sw          $t8, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r24;
    // 0x80013F60: lh          $t8, 0xE($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XE);
    // 0x80013F64: lw          $t9, -0x6BD4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6BD4);
    // 0x80013F68: sh          $t7, 0x15A($sp)
    MEM_H(0X15A, ctx->r29) = ctx->r15;
    // 0x80013F6C: sw          $t6, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r14;
    // 0x80013F70: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x80013F74: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80013F78: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80013F7C: sh          $t7, 0x16A($sp)
    MEM_H(0X16A, ctx->r29) = ctx->r15;
    // 0x80013F80: sh          $t6, 0x184($sp)
    MEM_H(0X184, ctx->r29) = ctx->r14;
    // 0x80013F84: sh          $zero, 0x17E($sp)
    MEM_H(0X17E, ctx->r29) = 0;
    // 0x80013F88: sh          $zero, 0x17C($sp)
    MEM_H(0X17C, ctx->r29) = 0;
    // 0x80013F8C: addiu       $a0, $a0, 0x61C8
    ctx->r4 = ADD32(ctx->r4, 0X61C8);
    // 0x80013F90: sw          $t8, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r24;
    // 0x80013F94: jal         0x80049CFC
    // 0x80013F98: sw          $t9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r25;
    func_80049CFC(rdram, ctx);
        goto after_12;
    // 0x80013F98: sw          $t9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r25;
    after_12:
    // 0x80013F9C: jal         0x80049D80
    // 0x80013FA0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80049D80(rdram, ctx);
        goto after_13;
    // 0x80013FA0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_13:
    // 0x80013FA4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80013FA8: jal         0x80049DFC
    // 0x80013FAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80049DFC(rdram, ctx);
        goto after_14;
    // 0x80013FAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x80013FB0: sw          $v0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r2;
    // 0x80013FB4: jal         0x8004A148
    // 0x80013FB8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8004A148(rdram, ctx);
        goto after_15;
    // 0x80013FB8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_15:
    // 0x80013FBC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80013FC0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80013FC4: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x80013FC8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80013FCC: lw          $a0, 0x8($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X8);
    // 0x80013FD0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80013FD4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80013FD8: jal         0x80001AB4
    // 0x80013FDC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80001AB4(rdram, ctx);
        goto after_16;
    // 0x80013FDC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_16:
    // 0x80013FE0: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    // 0x80013FE4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80013FE8: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x80013FEC: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x80013FF0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80013FF4: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x80013FF8: swc1        $f0, 0x40($t8)
    MEM_W(0X40, ctx->r24) = ctx->f0.u32l;
    // 0x80013FFC: lw          $t9, 0x8($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X8);
    // 0x80014000: addiu       $v0, $v0, -0x67D8
    ctx->r2 = ADD32(ctx->r2, -0X67D8);
    // 0x80014004: lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // 0x80014008: swc1        $f0, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->f0.u32l;
    // 0x8001400C: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x80014010: addiu       $v1, $v1, -0x67B4
    ctx->r3 = ADD32(ctx->r3, -0X67B4);
    // 0x80014014: addiu       $s0, $sp, 0xB4
    ctx->r16 = ADD32(ctx->r29, 0XB4);
    // 0x80014018: swc1        $f10, 0x48($t6)
    MEM_W(0X48, ctx->r14) = ctx->f10.u32l;
    // 0x8001401C: lw          $a0, 0x8($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X8);
    // 0x80014020: lw          $t7, 0xD8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XD8);
    // 0x80014024: ori         $t8, $t7, 0x8001
    ctx->r24 = ctx->r15 | 0X8001;
    // 0x80014028: sw          $t8, 0xD8($a0)
    MEM_W(0XD8, ctx->r4) = ctx->r24;
    // 0x8001402C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_80014030:
    // 0x80014030: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80014034: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x80014038: jal         0x80049CFC
    // 0x8001403C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    func_80049CFC(rdram, ctx);
        goto after_17;
    // 0x8001403C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_17:
    // 0x80014040: jal         0x80049D80
    // 0x80014044: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80049D80(rdram, ctx);
        goto after_18;
    // 0x80014044: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_18:
    // 0x80014048: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8001404C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80014050: jal         0x80049DFC
    // 0x80014054: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80049DFC(rdram, ctx);
        goto after_19;
    // 0x80014054: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_19:
    // 0x80014058: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x8001405C: jal         0x8004A148
    // 0x80014060: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8004A148(rdram, ctx);
        goto after_20;
    // 0x80014060: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_20:
    // 0x80014064: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80014068: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x8001406C: ori         $t9, $zero, 0x8000
    ctx->r25 = 0 | 0X8000;
    // 0x80014070: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80014074: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80014078: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8001407C: swc1        $f16, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->f16.u32l;
    // 0x80014080: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x80014084: sw          $t9, 0xD8($t7)
    MEM_W(0XD8, ctx->r15) = ctx->r25;
    // 0x80014088: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8001408C: lui         $t9, 0x8007
    ctx->r25 = S32(0X8007 << 16);
    // 0x80014090: addiu       $t9, $t9, -0x6790
    ctx->r25 = ADD32(ctx->r25, -0X6790);
    // 0x80014094: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x80014098: bne         $v1, $t9, L_80014030
    if (ctx->r3 != ctx->r25) {
        // 0x8001409C: sw          $t6, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r14;
            goto L_80014030;
    }
    // 0x8001409C: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x800140A0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800140A4: lh          $t7, -0x662C($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X662C);
    // 0x800140A8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800140AC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800140B0: bne         $t7, $at, L_800140C0
    if (ctx->r15 != ctx->r1) {
        // 0x800140B4: lui         $v0, 0x8007
        ctx->r2 = S32(0X8007 << 16);
            goto L_800140C0;
    }
    // 0x800140B4: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x800140B8: b           L_800140C4
    // 0x800140BC: sh          $t8, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r24;
        goto L_800140C4;
    // 0x800140BC: sh          $t8, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r24;
L_800140C0:
    // 0x800140C0: sh          $zero, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = 0;
L_800140C4:
    // 0x800140C4: lh          $t6, 0x4C($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X4C);
    // 0x800140C8: addiu       $v0, $v0, -0x690C
    ctx->r2 = ADD32(ctx->r2, -0X690C);
    // 0x800140CC: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x800140D0: beq         $t6, $zero, L_80014104
    if (ctx->r14 == 0) {
        // 0x800140D4: addiu       $a3, $zero, 0x36
        ctx->r7 = ADD32(0, 0X36);
            goto L_80014104;
    }
    // 0x800140D4: addiu       $a3, $zero, 0x36
    ctx->r7 = ADD32(0, 0X36);
    // 0x800140D8: lh          $s0, 0xE4($v0)
    ctx->r16 = MEM_H(ctx->r2, 0XE4);
    // 0x800140DC: lh          $t0, 0xE6($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XE6);
    // 0x800140E0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800140E4: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x800140E8: sll         $a1, $t0, 16
    ctx->r5 = S32(ctx->r8 << 16);
    // 0x800140EC: sra         $t7, $a1, 16
    ctx->r15 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800140F0: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800140F4: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x800140F8: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x800140FC: jal         0x8004C580
    // 0x80014100: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_21;
    // 0x80014100: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_21:
L_80014104:
    // 0x80014104: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80014108: lhu         $t8, -0x2E5A($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X2E5A);
    // 0x8001410C: lh          $t9, 0x5E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X5E);
    // 0x80014110: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80014114: andi        $t6, $t8, 0x8000
    ctx->r14 = ctx->r24 & 0X8000;
    // 0x80014118: bne         $t9, $at, L_800141A4
    if (ctx->r25 != ctx->r1) {
        // 0x8001411C: sh          $t6, 0x56($sp)
        MEM_H(0X56, ctx->r29) = ctx->r14;
            goto L_800141A4;
    }
    // 0x8001411C: sh          $t6, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r14;
    // 0x80014120: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80014124: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80014128: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001412C: bnel        $t7, $at, L_800141A8
    if (ctx->r15 != ctx->r1) {
        // 0x80014130: lh          $t7, 0x5E($sp)
        ctx->r15 = MEM_H(ctx->r29, 0X5E);
            goto L_800141A8;
    }
    goto skip_0;
    // 0x80014130: lh          $t7, 0x5E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X5E);
    skip_0:
    // 0x80014134: jal         0x8004C4D8
    // 0x80014138: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004C4D8(rdram, ctx);
        goto after_22;
    // 0x80014138: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_22:
    // 0x8001413C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80014140: jal         0x8004C4D8
    // 0x80014144: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004C4D8(rdram, ctx);
        goto after_23;
    // 0x80014144: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_23:
    // 0x80014148: jal         0x8004A0C4
    // 0x8001414C: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    func_8004A0C4(rdram, ctx);
        goto after_24;
    // 0x8001414C: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    after_24:
    // 0x80014150: addiu       $s0, $sp, 0xB4
    ctx->r16 = ADD32(ctx->r29, 0XB4);
L_80014154:
    // 0x80014154: jal         0x8004A0C4
    // 0x80014158: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    func_8004A0C4(rdram, ctx);
        goto after_25;
    // 0x80014158: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_25:
    // 0x8001415C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80014160: addiu       $t8, $sp, 0x120
    ctx->r24 = ADD32(ctx->r29, 0X120);
    // 0x80014164: bne         $s0, $t8, L_80014154
    if (ctx->r16 != ctx->r24) {
        // 0x80014168: nop
    
            goto L_80014154;
    }
    // 0x80014168: nop

    // 0x8001416C: jal         0x80049C48
    // 0x80014170: sh          $zero, 0x174($sp)
    MEM_H(0X174, ctx->r29) = 0;
    func_80049C48(rdram, ctx);
        goto after_26;
    // 0x80014170: sh          $zero, 0x174($sp)
    MEM_H(0X174, ctx->r29) = 0;
    after_26:
    // 0x80014174: jal         0x8004B21C
    // 0x80014178: nop

    func_8004B21C(rdram, ctx);
        goto after_27;
    // 0x80014178: nop

    after_27:
    // 0x8001417C: jal         0x80004E5C
    // 0x80014180: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_80004E5C(rdram, ctx);
        goto after_28;
    // 0x80014180: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_28:
    // 0x80014184: jal         0x8000798C
    // 0x80014188: nop

    func_8000798C(rdram, ctx);
        goto after_29;
    // 0x80014188: nop

    after_29:
    // 0x8001418C: lw          $t9, 0x1A0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1A0);
    // 0x80014190: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
L_80014194:
    // 0x80014194: jal         0x8000798C
    // 0x80014198: nop

    func_8000798C(rdram, ctx);
        goto after_30;
    // 0x80014198: nop

    after_30:
    // 0x8001419C: b           L_80014194
    // 0x800141A0: nop

        goto L_80014194;
    // 0x800141A0: nop

L_800141A4:
    // 0x800141A4: lh          $t7, 0x5E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X5E);
L_800141A8:
    // 0x800141A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800141AC: lh          $v1, 0x184($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X184);
    // 0x800141B0: beq         $t7, $at, L_80014440
    if (ctx->r15 == ctx->r1) {
        // 0x800141B4: lh          $t6, 0x180($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X180);
            goto L_80014440;
    }
    // 0x800141B4: lh          $t6, 0x180($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X180);
    // 0x800141B8: sll         $a1, $v1, 16
    ctx->r5 = S32(ctx->r3 << 16);
    // 0x800141BC: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800141C0: bne         $t6, $zero, L_80014270
    if (ctx->r14 != 0) {
        // 0x800141C4: or          $a1, $t8, $zero
        ctx->r5 = ctx->r24 | 0;
            goto L_80014270;
    }
    // 0x800141C4: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x800141C8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800141CC: lh          $v0, -0x2E4C($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2E4C);
    // 0x800141D0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800141D4: sh          $t9, 0x180($sp)
    MEM_H(0X180, ctx->r29) = ctx->r25;
    // 0x800141D8: andi        $t7, $v0, 0x100
    ctx->r15 = ctx->r2 & 0X100;
    // 0x800141DC: beq         $t7, $zero, L_80014204
    if (ctx->r15 == 0) {
        // 0x800141E0: andi        $t9, $v0, 0x200
        ctx->r25 = ctx->r2 & 0X200;
            goto L_80014204;
    }
    // 0x800141E0: andi        $t9, $v0, 0x200
    ctx->r25 = ctx->r2 & 0X200;
    // 0x800141E4: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x800141E8: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x800141EC: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x800141F0: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x800141F4: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x800141F8: lh          $t6, -0x690C($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X690C);
    // 0x800141FC: b           L_80014224
    // 0x80014200: sh          $t6, 0x180($sp)
    MEM_H(0X180, ctx->r29) = ctx->r14;
        goto L_80014224;
    // 0x80014200: sh          $t6, 0x180($sp)
    MEM_H(0X180, ctx->r29) = ctx->r14;
L_80014204:
    // 0x80014204: beq         $t9, $zero, L_80014224
    if (ctx->r25 == 0) {
        // 0x80014208: sll         $t7, $v1, 3
        ctx->r15 = S32(ctx->r3 << 3);
            goto L_80014224;
    }
    // 0x80014208: sll         $t7, $v1, 3
    ctx->r15 = S32(ctx->r3 << 3);
    // 0x8001420C: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x80014210: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80014214: lui         $t8, 0x8007
    ctx->r24 = S32(0X8007 << 16);
    // 0x80014218: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8001421C: lh          $t8, -0x690A($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X690A);
    // 0x80014220: sh          $t8, 0x180($sp)
    MEM_H(0X180, ctx->r29) = ctx->r24;
L_80014224:
    // 0x80014224: andi        $t6, $v0, 0x400
    ctx->r14 = ctx->r2 & 0X400;
    // 0x80014228: beq         $t6, $zero, L_80014250
    if (ctx->r14 == 0) {
        // 0x8001422C: andi        $t8, $v0, 0x800
        ctx->r24 = ctx->r2 & 0X800;
            goto L_80014250;
    }
    // 0x8001422C: andi        $t8, $v0, 0x800
    ctx->r24 = ctx->r2 & 0X800;
    // 0x80014230: sll         $t9, $v1, 3
    ctx->r25 = S32(ctx->r3 << 3);
    // 0x80014234: addu        $t9, $t9, $v1
    ctx->r25 = ADD32(ctx->r25, ctx->r3);
    // 0x80014238: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8001423C: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x80014240: addu        $t7, $t7, $t9
    ctx->r15 = ADD32(ctx->r15, ctx->r25);
    // 0x80014244: lh          $t7, -0x6908($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X6908);
    // 0x80014248: b           L_80014270
    // 0x8001424C: sh          $t7, 0x180($sp)
    MEM_H(0X180, ctx->r29) = ctx->r15;
        goto L_80014270;
    // 0x8001424C: sh          $t7, 0x180($sp)
    MEM_H(0X180, ctx->r29) = ctx->r15;
L_80014250:
    // 0x80014250: beq         $t8, $zero, L_80014270
    if (ctx->r24 == 0) {
        // 0x80014254: sll         $t6, $v1, 3
        ctx->r14 = S32(ctx->r3 << 3);
            goto L_80014270;
    }
    // 0x80014254: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x80014258: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x8001425C: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80014260: lui         $t9, 0x8007
    ctx->r25 = S32(0X8007 << 16);
    // 0x80014264: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x80014268: lh          $t9, -0x6906($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X6906);
    // 0x8001426C: sh          $t9, 0x180($sp)
    MEM_H(0X180, ctx->r29) = ctx->r25;
L_80014270:
    // 0x80014270: lh          $t7, 0x180($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X180);
    // 0x80014274: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80014278: sh          $v1, 0x184($sp)
    MEM_H(0X184, ctx->r29) = ctx->r3;
    // 0x8001427C: beq         $t7, $at, L_800142E0
    if (ctx->r15 == ctx->r1) {
        // 0x80014280: lh          $t8, 0x17E($sp)
        ctx->r24 = MEM_H(ctx->r29, 0X17E);
            goto L_800142E0;
    }
    // 0x80014280: lh          $t8, 0x17E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X17E);
    // 0x80014284: sh          $t8, 0x17C($sp)
    MEM_H(0X17C, ctx->r29) = ctx->r24;
L_80014288:
    // 0x80014288: sh          $v1, 0x182($sp)
    MEM_H(0X182, ctx->r29) = ctx->r3;
    // 0x8001428C: lh          $v1, 0x180($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X180);
    // 0x80014290: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x80014294: lh          $t7, 0x17E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X17E);
    // 0x80014298: sll         $t9, $v1, 3
    ctx->r25 = S32(ctx->r3 << 3);
    // 0x8001429C: addu        $t9, $t9, $v1
    ctx->r25 = ADD32(ctx->r25, ctx->r3);
    // 0x800142A0: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x800142A4: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x800142A8: lh          $v0, -0x6904($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X6904);
    // 0x800142AC: sh          $v1, 0x184($sp)
    MEM_H(0X184, ctx->r29) = ctx->r3;
    // 0x800142B0: beql        $t7, $v0, L_800142E4
    if (ctx->r15 == ctx->r2) {
        // 0x800142B4: lh          $t7, 0x184($sp)
        ctx->r15 = MEM_H(ctx->r29, 0X184);
            goto L_800142E4;
    }
    goto skip_1;
    // 0x800142B4: lh          $t7, 0x184($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X184);
    skip_1:
    // 0x800142B8: sh          $v0, 0x17E($sp)
    MEM_H(0X17E, ctx->r29) = ctx->r2;
    // 0x800142BC: lh          $t8, 0x17E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X17E);
    // 0x800142C0: lh          $t6, 0x182($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X182);
    // 0x800142C4: lh          $t9, 0x17A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X17A);
    // 0x800142C8: beql        $t8, $zero, L_800142E0
    if (ctx->r24 == 0) {
        // 0x800142CC: sh          $t9, 0x184($sp)
        MEM_H(0X184, ctx->r29) = ctx->r25;
            goto L_800142E0;
    }
    goto skip_2;
    // 0x800142CC: sh          $t9, 0x184($sp)
    MEM_H(0X184, ctx->r29) = ctx->r25;
    skip_2:
    // 0x800142D0: sh          $t6, 0x17A($sp)
    MEM_H(0X17A, ctx->r29) = ctx->r14;
    // 0x800142D4: b           L_800142E0
    // 0x800142D8: sh          $v1, 0x184($sp)
    MEM_H(0X184, ctx->r29) = ctx->r3;
        goto L_800142E0;
    // 0x800142D8: sh          $v1, 0x184($sp)
    MEM_H(0X184, ctx->r29) = ctx->r3;
    // 0x800142DC: sh          $t9, 0x184($sp)
    MEM_H(0X184, ctx->r29) = ctx->r25;
L_800142E0:
    // 0x800142E0: lh          $t7, 0x184($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X184);
L_800142E4:
    // 0x800142E4: sh          $zero, 0x180($sp)
    MEM_H(0X180, ctx->r29) = 0;
    // 0x800142E8: bltz        $t7, L_8001436C
    if (SIGNED(ctx->r15) < 0) {
        // 0x800142EC: slti        $at, $t7, 0x5
        ctx->r1 = SIGNED(ctx->r15) < 0X5 ? 1 : 0;
            goto L_8001436C;
    }
    // 0x800142EC: slti        $at, $t7, 0x5
    ctx->r1 = SIGNED(ctx->r15) < 0X5 ? 1 : 0;
    // 0x800142F0: beq         $at, $zero, L_8001436C
    if (ctx->r1 == 0) {
        // 0x800142F4: lh          $t8, 0x4E($sp)
        ctx->r24 = MEM_H(ctx->r29, 0X4E);
            goto L_8001436C;
    }
    // 0x800142F4: lh          $t8, 0x4E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X4E);
    // 0x800142F8: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x800142FC: beq         $at, $zero, L_8001431C
    if (ctx->r1 == 0) {
        // 0x80014300: lh          $t8, 0x184($sp)
        ctx->r24 = MEM_H(ctx->r29, 0X184);
            goto L_8001431C;
    }
    // 0x80014300: lh          $t8, 0x184($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X184);
    // 0x80014304: lh          $t9, 0x17E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X17E);
    // 0x80014308: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8001430C: sh          $t6, 0x180($sp)
    MEM_H(0X180, ctx->r29) = ctx->r14;
    // 0x80014310: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x80014314: b           L_80014288
    // 0x80014318: sh          $t9, 0x17C($sp)
    MEM_H(0X17C, ctx->r29) = ctx->r25;
        goto L_80014288;
    // 0x80014318: sh          $t9, 0x17C($sp)
    MEM_H(0X17C, ctx->r29) = ctx->r25;
L_8001431C:
    // 0x8001431C: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80014320: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80014324: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x80014328: lh          $t9, -0x6BC8($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X6BC8);
    // 0x8001432C: lh          $t7, 0x17C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X17C);
    // 0x80014330: bnel        $t9, $zero, L_80014370
    if (ctx->r25 != 0) {
        // 0x80014334: lh          $t6, 0x184($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X184);
            goto L_80014370;
    }
    goto skip_3;
    // 0x80014334: lh          $t6, 0x184($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X184);
    skip_3:
    // 0x80014338: bne         $t7, $zero, L_80014354
    if (ctx->r15 != 0) {
        // 0x8001433C: lh          $t8, 0x4E($sp)
        ctx->r24 = MEM_H(ctx->r29, 0X4E);
            goto L_80014354;
    }
    // 0x8001433C: lh          $t8, 0x4E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X4E);
    // 0x80014340: lh          $t9, 0x17E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X17E);
    // 0x80014344: addiu       $t6, $t8, -0x1
    ctx->r14 = ADD32(ctx->r24, -0X1);
    // 0x80014348: sh          $t6, 0x180($sp)
    MEM_H(0X180, ctx->r29) = ctx->r14;
    // 0x8001434C: b           L_80014364
    // 0x80014350: sh          $t9, 0x17C($sp)
    MEM_H(0X17C, ctx->r29) = ctx->r25;
        goto L_80014364;
    // 0x80014350: sh          $t9, 0x17C($sp)
    MEM_H(0X17C, ctx->r29) = ctx->r25;
L_80014354:
    // 0x80014354: lh          $t8, 0x17E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X17E);
    // 0x80014358: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8001435C: sh          $t7, 0x180($sp)
    MEM_H(0X180, ctx->r29) = ctx->r15;
    // 0x80014360: sh          $t8, 0x17C($sp)
    MEM_H(0X17C, ctx->r29) = ctx->r24;
L_80014364:
    // 0x80014364: b           L_80014288
    // 0x80014368: lh          $v1, 0x184($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X184);
        goto L_80014288;
    // 0x80014368: lh          $v1, 0x184($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X184);
L_8001436C:
    // 0x8001436C: lh          $t6, 0x184($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X184);
L_80014370:
    // 0x80014370: beql        $t6, $a1, L_80014384
    if (ctx->r14 == ctx->r5) {
        // 0x80014374: lh          $t9, 0x4E($sp)
        ctx->r25 = MEM_H(ctx->r29, 0X4E);
            goto L_80014384;
    }
    goto skip_4;
    // 0x80014374: lh          $t9, 0x4E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X4E);
    skip_4:
    // 0x80014378: jal         0x80044480
    // 0x8001437C: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    func_80044480(rdram, ctx);
        goto after_31;
    // 0x8001437C: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_31:
    // 0x80014380: lh          $t9, 0x4E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X4E);
L_80014384:
    // 0x80014384: lh          $t7, 0x184($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X184);
    // 0x80014388: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x8001438C: bnel        $at, $zero, L_80014444
    if (ctx->r1 != 0) {
        // 0x80014390: addiu       $s0, $sp, 0xB4
        ctx->r16 = ADD32(ctx->r29, 0XB4);
            goto L_80014444;
    }
    goto skip_5;
    // 0x80014390: addiu       $s0, $sp, 0xB4
    ctx->r16 = ADD32(ctx->r29, 0XB4);
    skip_5:
    // 0x80014394: bltz        $t7, L_8001443C
    if (SIGNED(ctx->r15) < 0) {
        // 0x80014398: slti        $at, $t7, 0x5
        ctx->r1 = SIGNED(ctx->r15) < 0X5 ? 1 : 0;
            goto L_8001443C;
    }
    // 0x80014398: slti        $at, $t7, 0x5
    ctx->r1 = SIGNED(ctx->r15) < 0X5 ? 1 : 0;
    // 0x8001439C: beq         $at, $zero, L_8001443C
    if (ctx->r1 == 0) {
        // 0x800143A0: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_8001443C;
    }
    // 0x800143A0: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800143A4: lhu         $t8, -0x2E5C($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X2E5C);
    // 0x800143A8: lh          $t9, 0x5C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X5C);
    // 0x800143AC: andi        $t6, $t8, 0x2000
    ctx->r14 = ctx->r24 & 0X2000;
    // 0x800143B0: beq         $t6, $zero, L_80014434
    if (ctx->r14 == 0) {
        // 0x800143B4: nop
    
            goto L_80014434;
    }
    // 0x800143B4: nop

    // 0x800143B8: bne         $t9, $zero, L_800143CC
    if (ctx->r25 != 0) {
        // 0x800143BC: addiu       $t8, $t7, 0x1
        ctx->r24 = ADD32(ctx->r15, 0X1);
            goto L_800143CC;
    }
    // 0x800143BC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800143C0: sh          $t8, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r24;
    // 0x800143C4: jal         0x80044480
    // 0x800143C8: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    func_80044480(rdram, ctx);
        goto after_32;
    // 0x800143C8: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_32:
L_800143CC:
    // 0x800143CC: lh          $t6, 0x184($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X184);
    // 0x800143D0: lh          $t7, 0x5C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X5C);
    // 0x800143D4: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800143D8: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x800143DC: beq         $t9, $t7, L_80014440
    if (ctx->r25 == ctx->r15) {
        // 0x800143E0: addiu       $a3, $a3, -0x6BC8
        ctx->r7 = ADD32(ctx->r7, -0X6BC8);
            goto L_80014440;
    }
    // 0x800143E0: addiu       $a3, $a3, -0x6BC8
    ctx->r7 = ADD32(ctx->r7, -0X6BC8);
    // 0x800143E4: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800143E8: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
    // 0x800143EC: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800143F0: addu        $v1, $a3, $t9
    ctx->r3 = ADD32(ctx->r7, ctx->r25);
    // 0x800143F4: lh          $t6, -0x4($v1)
    ctx->r14 = MEM_H(ctx->r3, -0X4);
    // 0x800143F8: addu        $v0, $a3, $t8
    ctx->r2 = ADD32(ctx->r7, ctx->r24);
    // 0x800143FC: lh          $a2, 0x0($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X0);
    // 0x80014400: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
    // 0x80014404: lh          $t8, -0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, -0X2);
    // 0x80014408: lh          $a1, 0x2($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X2);
    // 0x8001440C: addiu       $t7, $t0, 0x1
    ctx->r15 = ADD32(ctx->r8, 0X1);
    // 0x80014410: sh          $t8, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r24;
    // 0x80014414: sh          $t7, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r15;
    // 0x80014418: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x8001441C: sh          $a2, -0x4($v1)
    MEM_H(-0X4, ctx->r3) = ctx->r6;
    // 0x80014420: sh          $a2, 0x12A($sp)
    MEM_H(0X12A, ctx->r29) = ctx->r6;
    // 0x80014424: jal         0x80044480
    // 0x80014428: sh          $a1, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r5;
    func_80044480(rdram, ctx);
        goto after_33;
    // 0x80014428: sh          $a1, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r5;
    after_33:
    // 0x8001442C: b           L_80014444
    // 0x80014430: addiu       $s0, $sp, 0xB4
    ctx->r16 = ADD32(ctx->r29, 0XB4);
        goto L_80014444;
    // 0x80014430: addiu       $s0, $sp, 0xB4
    ctx->r16 = ADD32(ctx->r29, 0XB4);
L_80014434:
    // 0x80014434: b           L_80014440
    // 0x80014438: sh          $zero, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = 0;
        goto L_80014440;
    // 0x80014438: sh          $zero, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = 0;
L_8001443C:
    // 0x8001443C: sh          $zero, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = 0;
L_80014440:
    // 0x80014440: addiu       $s0, $sp, 0xB4
    ctx->r16 = ADD32(ctx->r29, 0XB4);
L_80014444:
    // 0x80014444: addiu       $t0, $zero, -0x2
    ctx->r8 = ADD32(0, -0X2);
    // 0x80014448: addiu       $v1, $sp, 0x120
    ctx->r3 = ADD32(ctx->r29, 0X120);
L_8001444C:
    // 0x8001444C: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x80014450: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80014454: sltu        $at, $s0, $v1
    ctx->r1 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x80014458: lw          $v0, 0x8($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X8);
    // 0x8001445C: lw          $t6, 0xD8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XD8);
    // 0x80014460: and         $t8, $t6, $t0
    ctx->r24 = ctx->r14 & ctx->r8;
    // 0x80014464: bne         $at, $zero, L_8001444C
    if (ctx->r1 != 0) {
        // 0x80014468: sw          $t8, 0xD8($v0)
        MEM_W(0XD8, ctx->r2) = ctx->r24;
            goto L_8001444C;
    }
    // 0x80014468: sw          $t8, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r24;
    // 0x8001446C: lh          $t1, 0x184($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X184);
    // 0x80014470: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x80014474: bltz        $t1, L_80014498
    if (SIGNED(ctx->r9) < 0) {
        // 0x80014478: slti        $at, $t1, 0x5
        ctx->r1 = SIGNED(ctx->r9) < 0X5 ? 1 : 0;
            goto L_80014498;
    }
    // 0x80014478: slti        $at, $t1, 0x5
    ctx->r1 = SIGNED(ctx->r9) < 0X5 ? 1 : 0;
    // 0x8001447C: beq         $at, $zero, L_80014498
    if (ctx->r1 == 0) {
        // 0x80014480: sll         $t7, $t1, 2
        ctx->r15 = S32(ctx->r9 << 2);
            goto L_80014498;
    }
    // 0x80014480: sll         $t7, $t1, 2
    ctx->r15 = S32(ctx->r9 << 2);
    // 0x80014484: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80014488: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8001448C: lh          $t9, -0x6BC8($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X6BC8);
    // 0x80014490: b           L_800144B8
    // 0x80014494: sh          $t9, 0x12A($sp)
    MEM_H(0X12A, ctx->r29) = ctx->r25;
        goto L_800144B8;
    // 0x80014494: sh          $t9, 0x12A($sp)
    MEM_H(0X12A, ctx->r29) = ctx->r25;
L_80014498:
    // 0x80014498: sll         $t6, $t1, 3
    ctx->r14 = S32(ctx->r9 << 3);
    // 0x8001449C: addu        $t6, $t6, $t1
    ctx->r14 = ADD32(ctx->r14, ctx->r9);
    // 0x800144A0: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x800144A4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800144A8: lh          $v0, -0x6902($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X6902);
    // 0x800144AC: beql        $v0, $zero, L_800144BC
    if (ctx->r2 == 0) {
        // 0x800144B0: lh          $t8, 0x12A($sp)
        ctx->r24 = MEM_H(ctx->r29, 0X12A);
            goto L_800144BC;
    }
    goto skip_6;
    // 0x800144B0: lh          $t8, 0x12A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X12A);
    skip_6:
    // 0x800144B4: sh          $v0, 0x12A($sp)
    MEM_H(0X12A, ctx->r29) = ctx->r2;
L_800144B8:
    // 0x800144B8: lh          $t8, 0x12A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X12A);
L_800144BC:
    // 0x800144BC: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x800144C0: beq         $t8, $zero, L_80014650
    if (ctx->r24 == 0) {
        // 0x800144C4: nop
    
            goto L_80014650;
    }
    // 0x800144C4: nop

    // 0x800144C8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800144CC: bne         $t8, $at, L_800144E0
    if (ctx->r24 != ctx->r1) {
        // 0x800144D0: lh          $t7, 0x4C($sp)
        ctx->r15 = MEM_H(ctx->r29, 0X4C);
            goto L_800144E0;
    }
    // 0x800144D0: lh          $t7, 0x4C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X4C);
    // 0x800144D4: bne         $t7, $zero, L_800144E0
    if (ctx->r15 != 0) {
        // 0x800144D8: addiu       $t9, $zero, 0x9
        ctx->r25 = ADD32(0, 0X9);
            goto L_800144E0;
    }
    // 0x800144D8: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x800144DC: sh          $t9, 0x12A($sp)
    MEM_H(0X12A, ctx->r29) = ctx->r25;
L_800144E0:
    // 0x800144E0: lh          $v1, 0x12A($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X12A);
    // 0x800144E4: addiu       $t9, $sp, 0xB4
    ctx->r25 = ADD32(ctx->r29, 0XB4);
    // 0x800144E8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800144EC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800144F0: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x800144F4: sra         $v1, $t6, 16
    ctx->r3 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800144F8: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800144FC: subu        $t7, $t7, $v1
    ctx->r15 = SUB32(ctx->r15, ctx->r3);
    // 0x80014500: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80014504: addu        $s0, $t7, $t9
    ctx->r16 = ADD32(ctx->r15, ctx->r25);
    // 0x80014508: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x8001450C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80014510: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x80014514: lw          $v0, 0x8($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X8);
    // 0x80014518: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8001451C: lw          $t8, 0xD8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XD8);
    // 0x80014520: ori         $t7, $t8, 0x1
    ctx->r15 = ctx->r24 | 0X1;
    // 0x80014524: sw          $t7, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r15;
    // 0x80014528: sh          $v1, 0x12A($sp)
    MEM_H(0X12A, ctx->r29) = ctx->r3;
    // 0x8001452C: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80014530: jal         0x80049840
    // 0x80014534: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80049840(rdram, ctx);
        goto after_34;
    // 0x80014534: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_34:
    // 0x80014538: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8001453C: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x80014540: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80014544: lw          $a0, 0x8($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X8);
    // 0x80014548: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8001454C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80014550: jal         0x80001AB4
    // 0x80014554: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80001AB4(rdram, ctx);
        goto after_35;
    // 0x80014554: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_35:
    // 0x80014558: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x8001455C: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    // 0x80014560: lw          $a0, 0x8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X8);
    // 0x80014564: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80014568: jal         0x80000BD8
    // 0x8001456C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_80000BD8(rdram, ctx);
        goto after_36;
    // 0x8001456C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_36:
    // 0x80014570: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x80014574: lui         $at, 0x41D8
    ctx->r1 = S32(0X41D8 << 16);
    // 0x80014578: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001457C: lw          $t7, 0x8($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X8);
    // 0x80014580: lh          $v0, 0x12A($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X12A);
    // 0x80014584: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80014588: swc1        $f18, 0x40($t7)
    MEM_W(0X40, ctx->r15) = ctx->f18.u32l;
    // 0x8001458C: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x80014590: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80014594: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x80014598: lw          $t6, 0x8($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X8);
    // 0x8001459C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800145A0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800145A4: swc1        $f4, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->f4.u32l;
    // 0x800145A8: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x800145AC: addiu       $a3, $v0, 0x11
    ctx->r7 = ADD32(ctx->r2, 0X11);
    // 0x800145B0: sll         $t6, $a3, 16
    ctx->r14 = S32(ctx->r7 << 16);
    // 0x800145B4: lw          $t7, 0x8($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X8);
    // 0x800145B8: sra         $a3, $t6, 16
    ctx->r7 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800145BC: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    // 0x800145C0: swc1        $f6, 0x48($t7)
    MEM_W(0X48, ctx->r15) = ctx->f6.u32l;
    // 0x800145C4: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800145C8: ldc1        $f16, 0x61D0($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, 0X61D0);
    // 0x800145CC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800145D0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800145D4: lh          $t9, 0x4C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X4C);
    // 0x800145D8: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x800145DC: addiu       $a1, $zero, 0x42
    ctx->r5 = ADD32(0, 0X42);
    // 0x800145E0: addiu       $a2, $zero, -0x100
    ctx->r6 = ADD32(0, -0X100);
    // 0x800145E4: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x800145E8: bne         $v0, $at, L_800145F8
    if (ctx->r2 != ctx->r1) {
        // 0x800145EC: swc1        $f4, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
            goto L_800145F8;
    }
    // 0x800145EC: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    // 0x800145F0: beq         $t9, $zero, L_80014648
    if (ctx->r25 == 0) {
        // 0x800145F4: nop
    
            goto L_80014648;
    }
    // 0x800145F4: nop

L_800145F8:
    // 0x800145F8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800145FC: jal         0x8004C580
    // 0x80014600: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_37;
    // 0x80014600: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_37:
    // 0x80014604: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x80014608: addiu       $a1, $zero, -0x2
    ctx->r5 = ADD32(0, -0X2);
    // 0x8001460C: addiu       $a2, $zero, -0x8000
    ctx->r6 = ADD32(0, -0X8000);
    // 0x80014610: addiu       $a3, $zero, 0x21
    ctx->r7 = ADD32(0, 0X21);
    // 0x80014614: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80014618: jal         0x8004C580
    // 0x8001461C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_38;
    // 0x8001461C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_38:
    // 0x80014620: lh          $a3, 0x12A($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X12A);
    // 0x80014624: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x80014628: addiu       $a1, $zero, -0x2
    ctx->r5 = ADD32(0, -0X2);
    // 0x8001462C: addiu       $a3, $a3, 0x19
    ctx->r7 = ADD32(ctx->r7, 0X19);
    // 0x80014630: sll         $t7, $a3, 16
    ctx->r15 = S32(ctx->r7 << 16);
    // 0x80014634: sra         $a3, $t7, 16
    ctx->r7 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80014638: addiu       $a2, $zero, -0x100
    ctx->r6 = ADD32(0, -0X100);
    // 0x8001463C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80014640: jal         0x8004C580
    // 0x80014644: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_39;
    // 0x80014644: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_39:
L_80014648:
    // 0x80014648: b           L_80014680
    // 0x8001464C: lh          $t1, 0x184($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X184);
        goto L_80014680;
    // 0x8001464C: lh          $t1, 0x184($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X184);
L_80014650:
    // 0x80014650: bne         $t1, $at, L_80014680
    if (ctx->r9 != ctx->r1) {
        // 0x80014654: addiu       $a0, $zero, 0x38
        ctx->r4 = ADD32(0, 0X38);
            goto L_80014680;
    }
    // 0x80014654: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x80014658: lh          $a3, 0x5E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X5E);
    // 0x8001465C: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    // 0x80014660: addiu       $a2, $zero, -0x100
    ctx->r6 = ADD32(0, -0X100);
    // 0x80014664: addiu       $a3, $a3, 0x2F
    ctx->r7 = ADD32(ctx->r7, 0X2F);
    // 0x80014668: sll         $t6, $a3, 16
    ctx->r14 = S32(ctx->r7 << 16);
    // 0x8001466C: sra         $a3, $t6, 16
    ctx->r7 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80014670: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80014674: jal         0x8004C580
    // 0x80014678: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_40;
    // 0x80014678: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_40:
    // 0x8001467C: lh          $t1, 0x184($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X184);
L_80014680:
    // 0x80014680: sll         $t7, $t1, 3
    ctx->r15 = S32(ctx->r9 << 3);
    // 0x80014684: addu        $t7, $t7, $t1
    ctx->r15 = ADD32(ctx->r15, ctx->r9);
    // 0x80014688: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8001468C: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x80014690: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80014694: lh          $v0, -0x6902($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X6902);
    // 0x80014698: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8001469C: lh          $t9, 0x4C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X4C);
    // 0x800146A0: bne         $v0, $at, L_800146B4
    if (ctx->r2 != ctx->r1) {
        // 0x800146A4: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_800146B4;
    }
    // 0x800146A4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800146A8: bne         $t9, $zero, L_800146B4
    if (ctx->r25 != 0) {
        // 0x800146AC: nop
    
            goto L_800146B4;
    }
    // 0x800146AC: nop

    // 0x800146B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800146B4:
    // 0x800146B4: beq         $v0, $zero, L_8001493C
    if (ctx->r2 == 0) {
        // 0x800146B8: sh          $v0, 0x12A($sp)
        MEM_H(0X12A, ctx->r29) = ctx->r2;
            goto L_8001493C;
    }
    // 0x800146B8: sh          $v0, 0x12A($sp)
    MEM_H(0X12A, ctx->r29) = ctx->r2;
    // 0x800146BC: lh          $a2, 0x12A($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X12A);
    // 0x800146C0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800146C4: lh          $t7, 0x6ACC($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X6ACC);
    // 0x800146C8: lhu         $v1, -0x2E58($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2E58);
    // 0x800146CC: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800146D0: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x800146D4: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800146D8: beq         $t7, $zero, L_800146F8
    if (ctx->r15 == 0) {
        // 0x800146DC: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800146F8;
    }
    // 0x800146DC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800146E0: sll         $t8, $v1, 8
    ctx->r24 = S32(ctx->r3 << 8);
    // 0x800146E4: andi        $t6, $v0, 0xF0FF
    ctx->r14 = ctx->r2 & 0XF0FF;
    // 0x800146E8: andi        $t7, $t8, 0xF00
    ctx->r15 = ctx->r24 & 0XF00;
    // 0x800146EC: or          $v0, $t6, $t7
    ctx->r2 = ctx->r14 | ctx->r15;
    // 0x800146F0: andi        $t9, $v0, 0xFFFF
    ctx->r25 = ctx->r2 & 0XFFFF;
    // 0x800146F4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800146F8:
    // 0x800146F8: andi        $t6, $v0, 0x100
    ctx->r14 = ctx->r2 & 0X100;
    // 0x800146FC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80014700: beq         $t6, $zero, L_80014710
    if (ctx->r14 == 0) {
        // 0x80014704: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80014710;
    }
    // 0x80014704: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80014708: b           L_80014720
    // 0x8001470C: addiu       $s0, $zero, 0xA
    ctx->r16 = ADD32(0, 0XA);
        goto L_80014720;
    // 0x8001470C: addiu       $s0, $zero, 0xA
    ctx->r16 = ADD32(0, 0XA);
L_80014710:
    // 0x80014710: andi        $t8, $v1, 0x200
    ctx->r24 = ctx->r3 & 0X200;
    // 0x80014714: beql        $t8, $zero, L_80014724
    if (ctx->r24 == 0) {
        // 0x80014718: andi        $t7, $v1, 0x800
        ctx->r15 = ctx->r3 & 0X800;
            goto L_80014724;
    }
    goto skip_7;
    // 0x80014718: andi        $t7, $v1, 0x800
    ctx->r15 = ctx->r3 & 0X800;
    skip_7:
    // 0x8001471C: addiu       $s0, $zero, -0xA
    ctx->r16 = ADD32(0, -0XA);
L_80014720:
    // 0x80014720: andi        $t7, $v1, 0x800
    ctx->r15 = ctx->r3 & 0X800;
L_80014724:
    // 0x80014724: beq         $t7, $zero, L_80014734
    if (ctx->r15 == 0) {
        // 0x80014728: andi        $t9, $v1, 0x400
        ctx->r25 = ctx->r3 & 0X400;
            goto L_80014734;
    }
    // 0x80014728: andi        $t9, $v1, 0x400
    ctx->r25 = ctx->r3 & 0X400;
    // 0x8001472C: b           L_80014740
    // 0x80014730: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_80014740;
    // 0x80014730: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80014734:
    // 0x80014734: beq         $t9, $zero, L_80014740
    if (ctx->r25 == 0) {
        // 0x80014738: nop
    
            goto L_80014740;
    }
    // 0x80014738: nop

    // 0x8001473C: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
L_80014740:
    // 0x80014740: beq         $s0, $zero, L_8001493C
    if (ctx->r16 == 0) {
        // 0x80014744: sh          $a2, 0x12A($sp)
        MEM_H(0X12A, ctx->r29) = ctx->r6;
            goto L_8001493C;
    }
    // 0x80014744: sh          $a2, 0x12A($sp)
    MEM_H(0X12A, ctx->r29) = ctx->r6;
    // 0x80014748: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8001474C: bne         $a2, $at, L_80014760
    if (ctx->r6 != ctx->r1) {
        // 0x80014750: addiu       $a0, $zero, 0x12
        ctx->r4 = ADD32(0, 0X12);
            goto L_80014760;
    }
    // 0x80014750: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x80014754: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x80014758: addu        $t6, $t6, $s0
    ctx->r14 = ADD32(ctx->r14, ctx->r16);
    // 0x8001475C: sll         $s0, $t6, 1
    ctx->r16 = S32(ctx->r14 << 1);
L_80014760:
    // 0x80014760: blez        $s0, L_800147AC
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80014764: sll         $t9, $a2, 3
        ctx->r25 = S32(ctx->r6 << 3);
            goto L_800147AC;
    }
    // 0x80014764: sll         $t9, $a2, 3
    ctx->r25 = S32(ctx->r6 << 3);
    // 0x80014768: sll         $t8, $a2, 3
    ctx->r24 = S32(ctx->r6 << 3);
    // 0x8001476C: addiu       $t7, $sp, 0x12C
    ctx->r15 = ADD32(ctx->r29, 0X12C);
    // 0x80014770: addu        $a1, $t8, $t7
    ctx->r5 = ADD32(ctx->r24, ctx->r15);
    // 0x80014774: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80014778: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8001477C: multu       $t6, $s0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80014780: mflo        $t8
    ctx->r24 = lo;
    // 0x80014784: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80014788: bne         $at, $zero, L_800147A4
    if (ctx->r1 != 0) {
        // 0x8001478C: nop
    
            goto L_800147A4;
    }
    // 0x8001478C: nop

    // 0x80014790: lh          $t7, 0x4($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X4);
    // 0x80014794: addu        $t6, $t7, $s0
    ctx->r14 = ADD32(ctx->r15, ctx->r16);
    // 0x80014798: slti        $at, $t6, 0x3E8
    ctx->r1 = SIGNED(ctx->r14) < 0X3E8 ? 1 : 0;
    // 0x8001479C: bne         $at, $zero, L_800147C8
    if (ctx->r1 != 0) {
        // 0x800147A0: nop
    
            goto L_800147C8;
    }
    // 0x800147A0: nop

L_800147A4:
    // 0x800147A4: b           L_800147C8
    // 0x800147A8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_800147C8;
    // 0x800147A8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800147AC:
    // 0x800147AC: addiu       $t8, $sp, 0x12C
    ctx->r24 = ADD32(ctx->r29, 0X12C);
    // 0x800147B0: addu        $a1, $t9, $t8
    ctx->r5 = ADD32(ctx->r25, ctx->r24);
    // 0x800147B4: lh          $t7, 0x4($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X4);
    // 0x800147B8: addu        $t6, $t7, $s0
    ctx->r14 = ADD32(ctx->r15, ctx->r16);
    // 0x800147BC: bgez        $t6, L_800147C8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800147C0: nop
    
            goto L_800147C8;
    }
    // 0x800147C0: nop

    // 0x800147C4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800147C8:
    // 0x800147C8: beq         $s0, $zero, L_8001493C
    if (ctx->r16 == 0) {
        // 0x800147CC: sh          $a2, 0x12A($sp)
        MEM_H(0X12A, ctx->r29) = ctx->r6;
            goto L_8001493C;
    }
    // 0x800147CC: sh          $a2, 0x12A($sp)
    MEM_H(0X12A, ctx->r29) = ctx->r6;
    // 0x800147D0: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800147D4: addiu       $t1, $t1, -0x6BC8
    ctx->r9 = ADD32(ctx->r9, -0X6BC8);
    // 0x800147D8: lh          $v1, 0x0($t1)
    ctx->r3 = MEM_H(ctx->r9, 0X0);
L_800147DC:
    // 0x800147DC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800147E0: addiu       $t9, $t9, -0x6BA8
    ctx->r25 = ADD32(ctx->r25, -0X6BA8);
    // 0x800147E4: bne         $v1, $zero, L_8001482C
    if (ctx->r3 != 0) {
        // 0x800147E8: addiu       $t7, $a2, 0x1
        ctx->r15 = ADD32(ctx->r6, 0X1);
            goto L_8001482C;
    }
    // 0x800147E8: addiu       $t7, $a2, 0x1
    ctx->r15 = ADD32(ctx->r6, 0X1);
    // 0x800147EC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800147F0: lh          $t8, -0x6BA8($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X6BA8);
    // 0x800147F4: lh          $t9, 0x4E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X4E);
    // 0x800147F8: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800147FC: beq         $at, $zero, L_80014824
    if (ctx->r1 == 0) {
        // 0x80014800: nop
    
            goto L_80014824;
    }
    // 0x80014800: nop

    // 0x80014804: lh          $t6, 0x4E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X4E);
    // 0x80014808: addiu       $t7, $a2, 0x1
    ctx->r15 = ADD32(ctx->r6, 0X1);
    // 0x8001480C: sh          $t7, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r15;
    // 0x80014810: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x80014814: sh          $t9, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r25;
    // 0x80014818: lh          $t8, 0x4($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X4);
    // 0x8001481C: b           L_80014858
    // 0x80014820: addu        $v0, $t8, $s0
    ctx->r2 = ADD32(ctx->r24, ctx->r16);
        goto L_80014858;
    // 0x80014820: addu        $v0, $t8, $s0
    ctx->r2 = ADD32(ctx->r24, ctx->r16);
L_80014824:
    // 0x80014824: b           L_8001493C
    // 0x80014828: sh          $a2, 0x12A($sp)
    MEM_H(0X12A, ctx->r29) = ctx->r6;
        goto L_8001493C;
    // 0x80014828: sh          $a2, 0x12A($sp)
    MEM_H(0X12A, ctx->r29) = ctx->r6;
L_8001482C:
    // 0x8001482C: bnel        $t7, $v1, L_80014844
    if (ctx->r15 != ctx->r3) {
        // 0x80014830: addiu       $t1, $t1, 0x4
        ctx->r9 = ADD32(ctx->r9, 0X4);
            goto L_80014844;
    }
    goto skip_8;
    // 0x80014830: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    skip_8:
    // 0x80014834: lh          $t6, 0x4($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X4);
    // 0x80014838: b           L_80014858
    // 0x8001483C: addu        $v0, $t6, $s0
    ctx->r2 = ADD32(ctx->r14, ctx->r16);
        goto L_80014858;
    // 0x8001483C: addu        $v0, $t6, $s0
    ctx->r2 = ADD32(ctx->r14, ctx->r16);
    // 0x80014840: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
L_80014844:
    // 0x80014844: sltu        $at, $t1, $t9
    ctx->r1 = ctx->r9 < ctx->r25 ? 1 : 0;
    // 0x80014848: bnel        $at, $zero, L_800147DC
    if (ctx->r1 != 0) {
        // 0x8001484C: lh          $v1, 0x0($t1)
        ctx->r3 = MEM_H(ctx->r9, 0X0);
            goto L_800147DC;
    }
    goto skip_9;
    // 0x8001484C: lh          $v1, 0x0($t1)
    ctx->r3 = MEM_H(ctx->r9, 0X0);
    skip_9:
    // 0x80014850: lh          $t8, 0x4($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X4);
    // 0x80014854: addu        $v0, $t8, $s0
    ctx->r2 = ADD32(ctx->r24, ctx->r16);
L_80014858:
    // 0x80014858: sh          $v0, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r2;
    // 0x8001485C: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80014860: sh          $a2, 0x12A($sp)
    MEM_H(0X12A, ctx->r29) = ctx->r6;
    // 0x80014864: jal         0x80044480
    // 0x80014868: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    func_80044480(rdram, ctx);
        goto after_41;
    // 0x80014868: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_41:
    // 0x8001486C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80014870: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80014874: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80014878: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8001487C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80014880: multu       $s0, $t6
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80014884: lh          $t6, 0x2($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X2);
    // 0x80014888: mflo        $t9
    ctx->r25 = lo;
    // 0x8001488C: subu        $t8, $t7, $t9
    ctx->r24 = SUB32(ctx->r15, ctx->r25);
    // 0x80014890: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x80014894: sh          $t7, 0x2($t1)
    MEM_H(0X2, ctx->r9) = ctx->r15;
    // 0x80014898: lh          $t9, 0x2($t1)
    ctx->r25 = MEM_H(ctx->r9, 0X2);
    // 0x8001489C: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
    // 0x800148A0: bnel        $t9, $zero, L_800148BC
    if (ctx->r25 != 0) {
        // 0x800148A4: lh          $t7, 0x4E($sp)
        ctx->r15 = MEM_H(ctx->r29, 0X4E);
            goto L_800148BC;
    }
    goto skip_10;
    // 0x800148A4: lh          $t7, 0x4E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X4E);
    skip_10:
    // 0x800148A8: lh          $t8, 0x4E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X4E);
    // 0x800148AC: sh          $zero, 0x0($t1)
    MEM_H(0X0, ctx->r9) = 0;
    // 0x800148B0: addiu       $t6, $t8, -0x1
    ctx->r14 = ADD32(ctx->r24, -0X1);
    // 0x800148B4: sh          $t6, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r14;
    // 0x800148B8: lh          $t7, 0x4E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X4E);
L_800148BC:
    // 0x800148BC: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800148C0: addiu       $t1, $t1, -0x6BC8
    ctx->r9 = ADD32(ctx->r9, -0X6BC8);
    // 0x800148C4: beq         $t7, $zero, L_8001493C
    if (ctx->r15 == 0) {
        // 0x800148C8: nop
    
            goto L_8001493C;
    }
    // 0x800148C8: nop

L_800148CC:
    // 0x800148CC: lh          $v1, 0x0($t1)
    ctx->r3 = MEM_H(ctx->r9, 0X0);
    // 0x800148D0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800148D4: addiu       $t8, $t8, -0x6BC8
    ctx->r24 = ADD32(ctx->r24, -0X6BC8);
    // 0x800148D8: beq         $v1, $zero, L_80014934
    if (ctx->r3 == 0) {
        // 0x800148DC: sll         $t9, $t2, 2
        ctx->r25 = S32(ctx->r10 << 2);
            goto L_80014934;
    }
    // 0x800148DC: sll         $t9, $t2, 2
    ctx->r25 = S32(ctx->r10 << 2);
    // 0x800148E0: addu        $v0, $t9, $t8
    ctx->r2 = ADD32(ctx->r25, ctx->r24);
    // 0x800148E4: lh          $t7, 0x4E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X4E);
    // 0x800148E8: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // 0x800148EC: lh          $t6, 0x2($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X2);
    // 0x800148F0: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800148F4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800148F8: bne         $t7, $t2, L_80014934
    if (ctx->r15 != ctx->r10) {
        // 0x800148FC: sh          $t6, -0x2($v0)
        MEM_H(-0X2, ctx->r2) = ctx->r14;
            goto L_80014934;
    }
    // 0x800148FC: sh          $t6, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r14;
    // 0x80014900: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80014904: addiu       $t9, $t9, -0x6BB0
    ctx->r25 = ADD32(ctx->r25, -0X6BB0);
    // 0x80014908: sltu        $at, $v0, $t9
    ctx->r1 = ctx->r2 < ctx->r25 ? 1 : 0;
    // 0x8001490C: beq         $at, $zero, L_8001492C
    if (ctx->r1 == 0) {
        // 0x80014910: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_8001492C;
    }
    // 0x80014910: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80014914: addiu       $a0, $a0, -0x6BB0
    ctx->r4 = ADD32(ctx->r4, -0X6BB0);
L_80014918:
    // 0x80014918: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001491C: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x80014920: sh          $zero, -0x4($v0)
    MEM_H(-0X4, ctx->r2) = 0;
    // 0x80014924: bne         $at, $zero, L_80014918
    if (ctx->r1 != 0) {
        // 0x80014928: sh          $zero, -0x2($v0)
        MEM_H(-0X2, ctx->r2) = 0;
            goto L_80014918;
    }
    // 0x80014928: sh          $zero, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = 0;
L_8001492C:
    // 0x8001492C: b           L_8001493C
    // 0x80014930: nop

        goto L_8001493C;
    // 0x80014930: nop

L_80014934:
    // 0x80014934: b           L_800148CC
    // 0x80014938: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
        goto L_800148CC;
    // 0x80014938: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
L_8001493C:
    // 0x8001493C: lh          $t8, 0x4C($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X4C);
    // 0x80014940: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x80014944: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x80014948: beq         $t8, $zero, L_8001495C
    if (ctx->r24 == 0) {
        // 0x8001494C: addiu       $v0, $sp, 0x12C
        ctx->r2 = ADD32(ctx->r29, 0X12C);
            goto L_8001495C;
    }
    // 0x8001494C: addiu       $v0, $sp, 0x12C
    ctx->r2 = ADD32(ctx->r29, 0X12C);
    // 0x80014950: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x80014954: b           L_8001495C
    // 0x80014958: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
        goto L_8001495C;
    // 0x80014958: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_8001495C:
    // 0x8001495C: blez        $t2, L_80014A10
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80014960: sll         $t7, $t2, 3
        ctx->r15 = S32(ctx->r10 << 3);
            goto L_80014A10;
    }
    // 0x80014960: sll         $t7, $t2, 3
    ctx->r15 = S32(ctx->r10 << 3);
    // 0x80014964: addu        $t9, $t7, $v0
    ctx->r25 = ADD32(ctx->r15, ctx->r2);
    // 0x80014968: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x8001496C: lh          $t8, 0x6($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X6);
L_80014970:
    // 0x80014970: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x80014974: addiu       $t6, $t6, -0x690C
    ctx->r14 = ADD32(ctx->r14, -0X690C);
    // 0x80014978: sll         $t7, $t8, 3
    ctx->r15 = S32(ctx->r24 << 3);
    // 0x8001497C: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x80014980: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80014984: addu        $v1, $t7, $t6
    ctx->r3 = ADD32(ctx->r15, ctx->r14);
    // 0x80014988: lh          $s0, 0xC($v1)
    ctx->r16 = MEM_H(ctx->r3, 0XC);
    // 0x8001498C: lh          $t0, 0xE($v1)
    ctx->r8 = MEM_H(ctx->r3, 0XE);
    // 0x80014990: lh          $a2, 0x4($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X4);
    // 0x80014994: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    // 0x80014998: addiu       $a1, $t0, 0x5
    ctx->r5 = ADD32(ctx->r8, 0X5);
    // 0x8001499C: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x800149A0: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x800149A4: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800149A8: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800149AC: sw          $t2, 0x198($sp)
    MEM_W(0X198, ctx->r29) = ctx->r10;
    // 0x800149B0: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800149B4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800149B8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x800149BC: jal         0x80013AC0
    // 0x800149C0: sw          $t0, 0x190($sp)
    MEM_W(0X190, ctx->r29) = ctx->r8;
    func_80013AC0(rdram, ctx);
        goto after_42;
    // 0x800149C0: sw          $t0, 0x190($sp)
    MEM_W(0X190, ctx->r29) = ctx->r8;
    after_42:
    // 0x800149C4: lw          $t0, 0x190($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X190);
    // 0x800149C8: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x800149CC: addiu       $a0, $s0, -0x17
    ctx->r4 = ADD32(ctx->r16, -0X17);
    // 0x800149D0: addiu       $a1, $t0, -0x7
    ctx->r5 = ADD32(ctx->r8, -0X7);
    // 0x800149D4: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x800149D8: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x800149DC: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x800149E0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800149E4: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800149E8: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800149EC: jal         0x80013AC0
    // 0x800149F0: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_80013AC0(rdram, ctx);
        goto after_43;
    // 0x800149F0: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_43:
    // 0x800149F4: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x800149F8: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800149FC: lw          $t2, 0x198($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X198);
    // 0x80014A00: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80014A04: bnel        $v0, $t9, L_80014970
    if (ctx->r2 != ctx->r25) {
        // 0x80014A08: lh          $t8, 0x6($v0)
        ctx->r24 = MEM_H(ctx->r2, 0X6);
            goto L_80014970;
    }
    goto skip_11;
    // 0x80014A08: lh          $t8, 0x6($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X6);
    skip_11:
    // 0x80014A0C: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_80014A10:
    // 0x80014A10: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80014A14: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80014A18: addiu       $a0, $zero, 0x52
    ctx->r4 = ADD32(0, 0X52);
    // 0x80014A1C: addiu       $a1, $zero, -0x65
    ctx->r5 = ADD32(0, -0X65);
    // 0x80014A20: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80014A24: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x80014A28: jal         0x80013AC0
    // 0x80014A2C: sw          $t3, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r11;
    func_80013AC0(rdram, ctx);
        goto after_44;
    // 0x80014A2C: sw          $t3, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r11;
    after_44:
    // 0x80014A30: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80014A34: lh          $t7, -0x6BA8($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X6BA8);
    // 0x80014A38: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80014A3C: lw          $t3, 0x19C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X19C);
    // 0x80014A40: blez        $t7, L_80014B40
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80014A44: addiu       $t1, $t1, -0x6BC8
        ctx->r9 = ADD32(ctx->r9, -0X6BC8);
            goto L_80014B40;
    }
    // 0x80014A44: addiu       $t1, $t1, -0x6BC8
    ctx->r9 = ADD32(ctx->r9, -0X6BC8);
    // 0x80014A48: lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // 0x80014A4C: addiu       $v1, $v1, -0x690C
    ctx->r3 = ADD32(ctx->r3, -0X690C);
L_80014A50:
    // 0x80014A50: lh          $t6, 0x0($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X0);
    // 0x80014A54: lh          $s0, 0xC($v1)
    ctx->r16 = MEM_H(ctx->r3, 0XC);
    // 0x80014A58: lh          $t0, 0xE($v1)
    ctx->r8 = MEM_H(ctx->r3, 0XE);
    // 0x80014A5C: lui         $a3, 0x8007
    ctx->r7 = S32(0X8007 << 16);
    // 0x80014A60: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x80014A64: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80014A68: sll         $a1, $t0, 16
    ctx->r5 = S32(ctx->r8 << 16);
    // 0x80014A6C: addu        $a3, $a3, $t9
    ctx->r7 = ADD32(ctx->r7, ctx->r25);
    // 0x80014A70: sra         $t7, $a1, 16
    ctx->r15 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80014A74: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80014A78: lh          $a3, -0x67EC($a3)
    ctx->r7 = MEM_H(ctx->r7, -0X67EC);
    // 0x80014A7C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80014A80: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80014A84: addiu       $a2, $zero, -0x100
    ctx->r6 = ADD32(0, -0X100);
    // 0x80014A88: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80014A8C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80014A90: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x80014A94: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80014A98: sw          $t3, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r11;
    // 0x80014A9C: jal         0x8004C580
    // 0x80014AA0: sw          $t0, 0x190($sp)
    MEM_W(0X190, ctx->r29) = ctx->r8;
    func_8004C580(rdram, ctx);
        goto after_45;
    // 0x80014AA0: sw          $t0, 0x190($sp)
    MEM_W(0X190, ctx->r29) = ctx->r8;
    after_45:
    // 0x80014AA4: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80014AA8: addiu       $a0, $s0, 0x23
    ctx->r4 = ADD32(ctx->r16, 0X23);
    // 0x80014AAC: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80014AB0: lh          $a2, 0x2($t1)
    ctx->r6 = MEM_H(ctx->r9, 0X2);
    // 0x80014AB4: lw          $t0, 0x190($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X190);
    // 0x80014AB8: lw          $t3, 0x19C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X19C);
    // 0x80014ABC: beq         $a2, $zero, L_80014B20
    if (ctx->r6 == 0) {
        // 0x80014AC0: sll         $t6, $a0, 16
        ctx->r14 = S32(ctx->r4 << 16);
            goto L_80014B20;
    }
    // 0x80014AC0: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80014AC4: addiu       $a1, $t0, -0x1
    ctx->r5 = ADD32(ctx->r8, -0X1);
    // 0x80014AC8: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x80014ACC: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80014AD0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80014AD4: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80014AD8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80014ADC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80014AE0: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x80014AE4: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80014AE8: jal         0x80013AC0
    // 0x80014AEC: sw          $t3, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r11;
    func_80013AC0(rdram, ctx);
        goto after_46;
    // 0x80014AEC: sw          $t3, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r11;
    after_46:
    // 0x80014AF0: lw          $t3, 0x19C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X19C);
    // 0x80014AF4: addiu       $a0, $s0, -0x31
    ctx->r4 = ADD32(ctx->r16, -0X31);
    // 0x80014AF8: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80014AFC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80014B00: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80014B04: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80014B08: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80014B0C: jal         0x80013AC0
    // 0x80014B10: addiu       $a2, $t3, 0x1
    ctx->r6 = ADD32(ctx->r11, 0X1);
    func_80013AC0(rdram, ctx);
        goto after_47;
    // 0x80014B10: addiu       $a2, $t3, 0x1
    ctx->r6 = ADD32(ctx->r11, 0X1);
    after_47:
    // 0x80014B14: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80014B18: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80014B1C: lw          $t3, 0x19C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X19C);
L_80014B20:
    // 0x80014B20: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80014B24: lh          $t8, -0x6BA8($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X6BA8);
    // 0x80014B28: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x80014B2C: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x80014B30: slt         $at, $t3, $t8
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80014B34: bne         $at, $zero, L_80014A50
    if (ctx->r1 != 0) {
        // 0x80014B38: addiu       $v1, $v1, 0x12
        ctx->r3 = ADD32(ctx->r3, 0X12);
            goto L_80014A50;
    }
    // 0x80014B38: addiu       $v1, $v1, 0x12
    ctx->r3 = ADD32(ctx->r3, 0X12);
    // 0x80014B3C: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_80014B40:
    // 0x80014B40: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
L_80014B44:
    // 0x80014B44: bne         $t3, $at, L_80014B60
    if (ctx->r11 != ctx->r1) {
        // 0x80014B48: lh          $t7, 0x4C($sp)
        ctx->r15 = MEM_H(ctx->r29, 0X4C);
            goto L_80014B60;
    }
    // 0x80014B48: lh          $t7, 0x4C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X4C);
    // 0x80014B4C: bne         $t7, $zero, L_80014B60
    if (ctx->r15 != 0) {
        // 0x80014B50: sll         $t6, $t3, 3
        ctx->r14 = S32(ctx->r11 << 3);
            goto L_80014B60;
    }
    // 0x80014B50: sll         $t6, $t3, 3
    ctx->r14 = S32(ctx->r11 << 3);
    // 0x80014B54: addiu       $t9, $sp, 0x12C
    ctx->r25 = ADD32(ctx->r29, 0X12C);
    // 0x80014B58: b           L_80014BB8
    // 0x80014B5C: addu        $v0, $t6, $t9
    ctx->r2 = ADD32(ctx->r14, ctx->r25);
        goto L_80014BB8;
    // 0x80014B5C: addu        $v0, $t6, $t9
    ctx->r2 = ADD32(ctx->r14, ctx->r25);
L_80014B60:
    // 0x80014B60: sll         $t8, $t3, 3
    ctx->r24 = S32(ctx->r11 << 3);
    // 0x80014B64: addiu       $t7, $sp, 0x12C
    ctx->r15 = ADD32(ctx->r29, 0X12C);
    // 0x80014B68: addu        $v0, $t8, $t7
    ctx->r2 = ADD32(ctx->r24, ctx->r15);
    // 0x80014B6C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80014B70: bne         $t3, $at, L_80014B84
    if (ctx->r11 != ctx->r1) {
        // 0x80014B74: lw          $v1, 0x0($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X0);
            goto L_80014B84;
    }
    // 0x80014B74: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80014B78: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80014B7C: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x80014B80: sll         $v1, $t6, 1
    ctx->r3 = S32(ctx->r14 << 1);
L_80014B84:
    // 0x80014B84: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80014B88: lh          $t8, 0x4E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X4E);
    // 0x80014B8C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80014B90: slt         $at, $t9, $v1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80014B94: bnel        $at, $zero, L_80014BBC
    if (ctx->r1 != 0) {
        // 0x80014B98: lh          $t9, 0x6($v0)
        ctx->r25 = MEM_H(ctx->r2, 0X6);
            goto L_80014BBC;
    }
    goto skip_12;
    // 0x80014B98: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    skip_12:
    // 0x80014B9C: lh          $t7, -0x6BA8($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X6BA8);
    // 0x80014BA0: slt         $at, $t8, $t7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80014BA4: bnel        $at, $zero, L_80014C14
    if (ctx->r1 != 0) {
        // 0x80014BA8: addiu       $t3, $t3, 0x1
        ctx->r11 = ADD32(ctx->r11, 0X1);
            goto L_80014C14;
    }
    goto skip_13;
    // 0x80014BA8: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    skip_13:
    // 0x80014BAC: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x80014BB0: bnel        $t6, $zero, L_80014C14
    if (ctx->r14 != 0) {
        // 0x80014BB4: addiu       $t3, $t3, 0x1
        ctx->r11 = ADD32(ctx->r11, 0X1);
            goto L_80014C14;
    }
    goto skip_14;
    // 0x80014BB4: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    skip_14:
L_80014BB8:
    // 0x80014BB8: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
L_80014BBC:
    // 0x80014BBC: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x80014BC0: addiu       $t7, $t7, -0x690C
    ctx->r15 = ADD32(ctx->r15, -0X690C);
    // 0x80014BC4: sll         $t8, $t9, 3
    ctx->r24 = S32(ctx->r25 << 3);
    // 0x80014BC8: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x80014BCC: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80014BD0: addu        $v1, $t8, $t7
    ctx->r3 = ADD32(ctx->r24, ctx->r15);
    // 0x80014BD4: lh          $s0, 0xC($v1)
    ctx->r16 = MEM_H(ctx->r3, 0XC);
    // 0x80014BD8: lh          $t0, 0xE($v1)
    ctx->r8 = MEM_H(ctx->r3, 0XE);
    // 0x80014BDC: sw          $t3, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r11;
    // 0x80014BE0: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80014BE4: sll         $a1, $t0, 16
    ctx->r5 = S32(ctx->r8 << 16);
    // 0x80014BE8: sra         $t9, $a1, 16
    ctx->r25 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80014BEC: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80014BF0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80014BF4: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x80014BF8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80014BFC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80014C00: addiu       $a2, $zero, -0x8000
    ctx->r6 = ADD32(0, -0X8000);
    // 0x80014C04: jal         0x8004C580
    // 0x80014C08: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8004C580(rdram, ctx);
        goto after_48;
    // 0x80014C08: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_48:
    // 0x80014C0C: lw          $t3, 0x19C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X19C);
    // 0x80014C10: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
L_80014C14:
    // 0x80014C14: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80014C18: bnel        $t3, $at, L_80014B44
    if (ctx->r11 != ctx->r1) {
        // 0x80014C1C: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80014B44;
    }
    goto skip_15;
    // 0x80014C1C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    skip_15:
    // 0x80014C20: lh          $t8, 0x5E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X5E);
    // 0x80014C24: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80014C28: bnel        $t8, $zero, L_80014D34
    if (ctx->r24 != 0) {
        // 0x80014C2C: lh          $t8, 0x5E($sp)
        ctx->r24 = MEM_H(ctx->r29, 0X5E);
            goto L_80014D34;
    }
    goto skip_16;
    // 0x80014C2C: lh          $t8, 0x5E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X5E);
    skip_16:
    // 0x80014C30: lh          $t7, 0x6ACC($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X6ACC);
    // 0x80014C34: beq         $t7, $zero, L_80014C5C
    if (ctx->r15 == 0) {
        // 0x80014C38: addiu       $a0, $zero, -0x50
        ctx->r4 = ADD32(0, -0X50);
            goto L_80014C5C;
    }
    // 0x80014C38: addiu       $a0, $zero, -0x50
    ctx->r4 = ADD32(0, -0X50);
    // 0x80014C3C: addiu       $a1, $zero, -0x5E
    ctx->r5 = ADD32(0, -0X5E);
    // 0x80014C40: addiu       $a2, $zero, -0x100
    ctx->r6 = ADD32(0, -0X100);
    // 0x80014C44: addiu       $a3, $zero, 0x37
    ctx->r7 = ADD32(0, 0X37);
    // 0x80014C48: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80014C4C: jal         0x8004C580
    // 0x80014C50: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_49;
    // 0x80014C50: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_49:
    // 0x80014C54: b           L_80014C7C
    // 0x80014C58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80014C7C;
    // 0x80014C58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80014C5C:
    // 0x80014C5C: addiu       $a0, $zero, -0x50
    ctx->r4 = ADD32(0, -0X50);
    // 0x80014C60: addiu       $a1, $zero, -0x5E
    ctx->r5 = ADD32(0, -0X5E);
    // 0x80014C64: addiu       $a2, $zero, -0x100
    ctx->r6 = ADD32(0, -0X100);
    // 0x80014C68: addiu       $a3, $zero, 0x35
    ctx->r7 = ADD32(0, 0X35);
    // 0x80014C6C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80014C70: jal         0x8004C580
    // 0x80014C74: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_50;
    // 0x80014C74: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_50:
    // 0x80014C78: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80014C7C:
    // 0x80014C7C: addiu       $a1, $zero, -0x5E
    ctx->r5 = ADD32(0, -0X5E);
    // 0x80014C80: addiu       $a2, $zero, -0x100
    ctx->r6 = ADD32(0, -0X100);
    // 0x80014C84: addiu       $a3, $zero, 0x31
    ctx->r7 = ADD32(0, 0X31);
    // 0x80014C88: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80014C8C: jal         0x8004C580
    // 0x80014C90: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_51;
    // 0x80014C90: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_51:
    // 0x80014C94: lh          $t6, 0x184($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X184);
    // 0x80014C98: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80014C9C: bne         $t6, $at, L_80014D04
    if (ctx->r14 != ctx->r1) {
        // 0x80014CA0: addiu       $a0, $zero, 0x38
        ctx->r4 = ADD32(0, 0X38);
            goto L_80014D04;
    }
    // 0x80014CA0: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x80014CA4: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    // 0x80014CA8: addiu       $a2, $zero, -0x100
    ctx->r6 = ADD32(0, -0X100);
    // 0x80014CAC: addiu       $a3, $zero, 0x2F
    ctx->r7 = ADD32(0, 0X2F);
    // 0x80014CB0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80014CB4: jal         0x8004C580
    // 0x80014CB8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_52;
    // 0x80014CB8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_52:
    // 0x80014CBC: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80014CC0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80014CC4: lh          $t8, 0x56($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X56);
    // 0x80014CC8: bnel        $t9, $at, L_80014E5C
    if (ctx->r25 != ctx->r1) {
        // 0x80014CCC: lh          $t6, 0x5E($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X5E);
            goto L_80014E5C;
    }
    goto skip_17;
    // 0x80014CCC: lh          $t6, 0x5E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X5E);
    skip_17:
    // 0x80014CD0: bne         $t8, $zero, L_80014CE4
    if (ctx->r24 != 0) {
        // 0x80014CD4: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_80014CE4;
    }
    // 0x80014CD4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80014CD8: lhu         $t7, -0x2E5A($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X2E5A);
    // 0x80014CDC: andi        $t6, $t7, 0x1000
    ctx->r14 = ctx->r15 & 0X1000;
    // 0x80014CE0: beq         $t6, $zero, L_80014E58
    if (ctx->r14 == 0) {
        // 0x80014CE4: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80014E58;
    }
L_80014CE4:
    // 0x80014CE4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80014CE8: addiu       $t8, $zero, 0xE
    ctx->r24 = ADD32(0, 0XE);
    // 0x80014CEC: sh          $t8, 0x184($sp)
    MEM_H(0X184, ctx->r29) = ctx->r24;
    // 0x80014CF0: sh          $t9, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r25;
    // 0x80014CF4: jal         0x80044480
    // 0x80014CF8: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    func_80044480(rdram, ctx);
        goto after_53;
    // 0x80014CF8: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_53:
    // 0x80014CFC: b           L_80014E5C
    // 0x80014D00: lh          $t6, 0x5E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X5E);
        goto L_80014E5C;
    // 0x80014D00: lh          $t6, 0x5E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X5E);
L_80014D04:
    // 0x80014D04: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80014D08: lhu         $t7, -0x2E5A($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X2E5A);
    // 0x80014D0C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80014D10: addiu       $t9, $zero, 0xD
    ctx->r25 = ADD32(0, 0XD);
    // 0x80014D14: andi        $t6, $t7, 0x1000
    ctx->r14 = ctx->r15 & 0X1000;
    // 0x80014D18: beql        $t6, $zero, L_80014E5C
    if (ctx->r14 == 0) {
        // 0x80014D1C: lh          $t6, 0x5E($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X5E);
            goto L_80014E5C;
    }
    goto skip_18;
    // 0x80014D1C: lh          $t6, 0x5E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X5E);
    skip_18:
    // 0x80014D20: jal         0x80044480
    // 0x80014D24: sh          $t9, 0x184($sp)
    MEM_H(0X184, ctx->r29) = ctx->r25;
    func_80044480(rdram, ctx);
        goto after_54;
    // 0x80014D24: sh          $t9, 0x184($sp)
    MEM_H(0X184, ctx->r29) = ctx->r25;
    after_54:
    // 0x80014D28: b           L_80014E5C
    // 0x80014D2C: lh          $t6, 0x5E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X5E);
        goto L_80014E5C;
    // 0x80014D2C: lh          $t6, 0x5E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X5E);
    // 0x80014D30: lh          $t8, 0x5E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X5E);
L_80014D34:
    // 0x80014D34: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80014D38: beql        $t8, $at, L_80014E5C
    if (ctx->r24 == ctx->r1) {
        // 0x80014D3C: lh          $t6, 0x5E($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X5E);
            goto L_80014E5C;
    }
    goto skip_19;
    // 0x80014D3C: lh          $t6, 0x5E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X5E);
    skip_19:
    // 0x80014D40: lh          $t6, 0x174($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X174);
    // 0x80014D44: addiu       $a0, $zero, -0x50
    ctx->r4 = ADD32(0, -0X50);
    // 0x80014D48: addiu       $a1, $zero, -0x5E
    ctx->r5 = ADD32(0, -0X5E);
    // 0x80014D4C: sll         $t9, $t6, 24
    ctx->r25 = S32(ctx->r14 << 24);
    // 0x80014D50: sra         $a2, $t9, 16
    ctx->r6 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80014D54: addiu       $a3, $zero, 0x34
    ctx->r7 = ADD32(0, 0X34);
    // 0x80014D58: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80014D5C: jal         0x8004C580
    // 0x80014D60: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_55;
    // 0x80014D60: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_55:
    // 0x80014D64: lh          $t7, 0x174($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X174);
    // 0x80014D68: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x80014D6C: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    // 0x80014D70: addiu       $t6, $t7, 0x8
    ctx->r14 = ADD32(ctx->r15, 0X8);
    // 0x80014D74: sh          $t6, 0x174($sp)
    MEM_H(0X174, ctx->r29) = ctx->r14;
    // 0x80014D78: addiu       $a2, $zero, -0x100
    ctx->r6 = ADD32(0, -0X100);
    // 0x80014D7C: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    // 0x80014D80: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80014D84: jal         0x8004C580
    // 0x80014D88: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_56;
    // 0x80014D88: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_56:
    // 0x80014D8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80014D90: addiu       $a1, $zero, -0x5E
    ctx->r5 = ADD32(0, -0X5E);
    // 0x80014D94: addiu       $a2, $zero, -0x100
    ctx->r6 = ADD32(0, -0X100);
    // 0x80014D98: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    // 0x80014D9C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80014DA0: jal         0x8004C580
    // 0x80014DA4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_57;
    // 0x80014DA4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_57:
    // 0x80014DA8: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    // 0x80014DAC: addiu       $a1, $zero, -0x5E
    ctx->r5 = ADD32(0, -0X5E);
    // 0x80014DB0: addiu       $a2, $zero, -0x100
    ctx->r6 = ADD32(0, -0X100);
    // 0x80014DB4: addiu       $a3, $zero, 0x33
    ctx->r7 = ADD32(0, 0X33);
    // 0x80014DB8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80014DBC: jal         0x8004C580
    // 0x80014DC0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_58;
    // 0x80014DC0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_58:
    // 0x80014DC4: lh          $t9, 0x56($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X56);
    // 0x80014DC8: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80014DCC: lh          $t6, 0x184($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X184);
    // 0x80014DD0: bne         $t9, $zero, L_80014DE8
    if (ctx->r25 != 0) {
        // 0x80014DD4: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_80014DE8;
    }
    // 0x80014DD4: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80014DD8: lhu         $t8, -0x2E5A($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X2E5A);
    // 0x80014DDC: andi        $t7, $t8, 0x1000
    ctx->r15 = ctx->r24 & 0X1000;
    // 0x80014DE0: beql        $t7, $zero, L_80014E5C
    if (ctx->r15 == 0) {
        // 0x80014DE4: lh          $t6, 0x5E($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X5E);
            goto L_80014E5C;
    }
    goto skip_20;
    // 0x80014DE4: lh          $t6, 0x5E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X5E);
    skip_20:
L_80014DE8:
    // 0x80014DE8: bne         $t6, $at, L_80014E34
    if (ctx->r14 != ctx->r1) {
        // 0x80014DEC: lh          $t9, 0x184($sp)
        ctx->r25 = MEM_H(ctx->r29, 0X184);
            goto L_80014E34;
    }
    // 0x80014DEC: lh          $t9, 0x184($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X184);
    // 0x80014DF0: lh          $t9, 0x4E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X4E);
    // 0x80014DF4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80014DF8: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80014DFC: sh          $t9, -0x6BA6($at)
    MEM_H(-0X6BA6, ctx->r1) = ctx->r25;
    // 0x80014E00: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80014E04: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80014E08: sh          $t7, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r15;
    // 0x80014E0C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80014E10: jal         0x80044480
    // 0x80014E14: sw          $t8, -0x6BD4($at)
    MEM_W(-0X6BD4, ctx->r1) = ctx->r24;
    func_80044480(rdram, ctx);
        goto after_59;
    // 0x80014E14: sw          $t8, -0x6BD4($at)
    MEM_W(-0X6BD4, ctx->r1) = ctx->r24;
    after_59:
    // 0x80014E18: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80014E1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80014E20: jal         0x8004D134
    // 0x80014E24: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_8004D134(rdram, ctx);
        goto after_60;
    // 0x80014E24: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_60:
    // 0x80014E28: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80014E2C: b           L_80014E58
    // 0x80014E30: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
        goto L_80014E58;
    // 0x80014E30: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
L_80014E34:
    // 0x80014E34: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80014E38: bne         $t9, $at, L_80014E58
    if (ctx->r25 != ctx->r1) {
        // 0x80014E3C: addiu       $a0, $zero, 0x12
        ctx->r4 = ADD32(0, 0X12);
            goto L_80014E58;
    }
    // 0x80014E3C: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x80014E40: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x80014E44: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x80014E48: sh          $t7, 0x17A($sp)
    MEM_H(0X17A, ctx->r29) = ctx->r15;
    // 0x80014E4C: sh          $t8, 0x180($sp)
    MEM_H(0X180, ctx->r29) = ctx->r24;
    // 0x80014E50: jal         0x80044480
    // 0x80014E54: sh          $zero, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = 0;
    func_80044480(rdram, ctx);
        goto after_61;
    // 0x80014E54: sh          $zero, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = 0;
    after_61:
L_80014E58:
    // 0x80014E58: lh          $t6, 0x5E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X5E);
L_80014E5C:
    // 0x80014E5C: lh          $t9, 0x184($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X184);
    // 0x80014E60: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80014E64: beq         $t6, $at, L_80014EC8
    if (ctx->r14 == ctx->r1) {
        // 0x80014E68: sll         $t8, $t9, 3
        ctx->r24 = S32(ctx->r25 << 3);
            goto L_80014EC8;
    }
    // 0x80014E68: sll         $t8, $t9, 3
    ctx->r24 = S32(ctx->r25 << 3);
    // 0x80014E6C: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x80014E70: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x80014E74: addiu       $t7, $t7, -0x690C
    ctx->r15 = ADD32(ctx->r15, -0X690C);
    // 0x80014E78: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80014E7C: addu        $v0, $t8, $t7
    ctx->r2 = ADD32(ctx->r24, ctx->r15);
    // 0x80014E80: lh          $s0, 0xC($v0)
    ctx->r16 = MEM_H(ctx->r2, 0XC);
    // 0x80014E84: lh          $t0, 0xE($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XE);
    // 0x80014E88: lh          $t7, 0x176($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X176);
    // 0x80014E8C: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80014E90: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80014E94: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80014E98: sll         $a1, $t0, 16
    ctx->r5 = S32(ctx->r8 << 16);
    // 0x80014E9C: sra         $t9, $a1, 16
    ctx->r25 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80014EA0: sll         $t6, $t7, 24
    ctx->r14 = S32(ctx->r15 << 24);
    // 0x80014EA4: lh          $a3, 0x10($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X10);
    // 0x80014EA8: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80014EAC: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x80014EB0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80014EB4: jal         0x8004C580
    // 0x80014EB8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_62;
    // 0x80014EB8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_62:
    // 0x80014EBC: lh          $t8, 0x176($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X176);
    // 0x80014EC0: addiu       $t7, $t8, 0x10
    ctx->r15 = ADD32(ctx->r24, 0X10);
    // 0x80014EC4: sh          $t7, 0x176($sp)
    MEM_H(0X176, ctx->r29) = ctx->r15;
L_80014EC8:
    // 0x80014EC8: jal         0x8000798C
    // 0x80014ECC: nop

    func_8000798C(rdram, ctx);
        goto after_63;
    // 0x80014ECC: nop

    after_63:
    // 0x80014ED0: b           L_80014104
    // 0x80014ED4: nop

        goto L_80014104;
    // 0x80014ED4: nop

    // 0x80014ED8: nop

    // 0x80014EDC: nop

    // 0x80014EE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80014EE4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80014EE8: addiu       $sp, $sp, 0x1A0
    ctx->r29 = ADD32(ctx->r29, 0X1A0);
    // 0x80014EEC: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80014F00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80014F00: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80014F04: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80014F08: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80014F0C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80014F10: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80014F14: sll         $s7, $a1, 16
    ctx->r23 = S32(ctx->r5 << 16);
    // 0x80014F18: sll         $s3, $t7, 16
    ctx->r19 = S32(ctx->r15 << 16);
    // 0x80014F1C: sra         $t8, $s7, 16
    ctx->r24 = S32(SIGNED(ctx->r23) >> 16);
    // 0x80014F20: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80014F24: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80014F28: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80014F2C: sra         $t9, $s3, 16
    ctx->r25 = S32(SIGNED(ctx->r19) >> 16);
    // 0x80014F30: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80014F34: or          $s7, $t8, $zero
    ctx->r23 = ctx->r24 | 0;
    // 0x80014F38: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80014F3C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80014F40: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80014F44: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80014F48: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80014F4C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80014F50: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80014F54: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x80014F58: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x80014F5C: sh          $zero, 0x48($sp)
    MEM_H(0X48, ctx->r29) = 0;
    // 0x80014F60: or          $s3, $t9, $zero
    ctx->r19 = ctx->r25 | 0;
    // 0x80014F64: bgez        $a2, L_80014F78
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80014F68: or          $s5, $a2, $zero
        ctx->r21 = ctx->r6 | 0;
            goto L_80014F78;
    }
    // 0x80014F68: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x80014F6C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80014F70: sh          $t0, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r8;
    // 0x80014F74: negu        $s5, $a2
    ctx->r21 = SUB32(0, ctx->r6);
L_80014F78:
    // 0x80014F78: lh          $t1, 0x6E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X6E);
    // 0x80014F7C: lui         $s2, 0x8007
    ctx->r18 = S32(0X8007 << 16);
    // 0x80014F80: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80014F84: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80014F88: addu        $s2, $s2, $t2
    ctx->r18 = ADD32(ctx->r18, ctx->r10);
    // 0x80014F8C: blez        $t1, L_80015114
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80014F90: lw          $s2, -0x6790($s2)
        ctx->r18 = MEM_W(ctx->r18, -0X6790);
            goto L_80015114;
    }
    // 0x80014F90: lw          $s2, -0x6790($s2)
    ctx->r18 = MEM_W(ctx->r18, -0X6790);
    // 0x80014F94: lh          $fp, 0x76($sp)
    ctx->r30 = MEM_H(ctx->r29, 0X76);
L_80014F98:
    // 0x80014F98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80014F9C: bne         $s2, $at, L_80014FA8
    if (ctx->r18 != ctx->r1) {
        // 0x80014FA0: nop
    
            goto L_80014FA8;
    }
    // 0x80014FA0: nop

    // 0x80014FA4: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_80014FA8:
    // 0x80014FA8: div         $zero, $s5, $s2
    lo = S32(S64(S32(ctx->r21)) / S64(S32(ctx->r18))); hi = S32(S64(S32(ctx->r21)) % S64(S32(ctx->r18)));
    // 0x80014FAC: bne         $s2, $zero, L_80014FB8
    if (ctx->r18 != 0) {
        // 0x80014FB0: nop
    
            goto L_80014FB8;
    }
    // 0x80014FB0: nop

    // 0x80014FB4: break       7
    do_break(2147569588);
L_80014FB8:
    // 0x80014FB8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80014FBC: bne         $s2, $at, L_80014FD0
    if (ctx->r18 != ctx->r1) {
        // 0x80014FC0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80014FD0;
    }
    // 0x80014FC0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80014FC4: bne         $s5, $at, L_80014FD0
    if (ctx->r21 != ctx->r1) {
        // 0x80014FC8: nop
    
            goto L_80014FD0;
    }
    // 0x80014FC8: nop

    // 0x80014FCC: break       6
    do_break(2147569612);
L_80014FD0:
    // 0x80014FD0: mflo        $v0
    ctx->r2 = lo;
    // 0x80014FD4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80014FD8: bne         $v0, $zero, L_80014FF0
    if (ctx->r2 != 0) {
        // 0x80014FDC: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_80014FF0;
    }
    // 0x80014FDC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80014FE0: bne         $s6, $zero, L_80014FF4
    if (ctx->r22 != 0) {
        // 0x80014FE4: nop
    
            goto L_80014FF4;
    }
    // 0x80014FE4: nop

    // 0x80014FE8: b           L_80014FF4
    // 0x80014FEC: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
        goto L_80014FF4;
    // 0x80014FEC: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
L_80014FF0:
    // 0x80014FF0: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_80014FF4:
    // 0x80014FF4: beql        $s1, $at, L_800150E8
    if (ctx->r17 == ctx->r1) {
        // 0x80014FF8: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_800150E8;
    }
    goto skip_0;
    // 0x80014FF8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    skip_0:
    // 0x80014FFC: lh          $s0, 0x72($sp)
    ctx->r16 = MEM_H(ctx->r29, 0X72);
    // 0x80015000: lh          $t5, 0x48($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X48);
    // 0x80015004: ori         $at, $zero, 0xFF00
    ctx->r1 = 0 | 0XFF00;
    // 0x80015008: addu        $s0, $s0, $at
    ctx->r16 = ADD32(ctx->r16, ctx->r1);
    // 0x8001500C: sll         $t3, $s0, 16
    ctx->r11 = S32(ctx->r16 << 16);
    // 0x80015010: beq         $t5, $zero, L_8001505C
    if (ctx->r13 == 0) {
        // 0x80015014: sra         $s0, $t3, 16
        ctx->r16 = S32(SIGNED(ctx->r11) >> 16);
            goto L_8001505C;
    }
    // 0x80015014: sra         $s0, $t3, 16
    ctx->r16 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80015018: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8001501C: beq         $fp, $zero, L_80015028
    if (ctx->r30 == 0) {
        // 0x80015020: sh          $zero, 0x48($sp)
        MEM_H(0X48, ctx->r29) = 0;
            goto L_80015028;
    }
    // 0x80015020: sh          $zero, 0x48($sp)
    MEM_H(0X48, ctx->r29) = 0;
    // 0x80015024: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_80015028:
    // 0x80015028: subu        $a0, $s3, $v0
    ctx->r4 = SUB32(ctx->r19, ctx->r2);
    // 0x8001502C: sll         $a1, $s7, 16
    ctx->r5 = S32(ctx->r23 << 16);
    // 0x80015030: sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16 << 16);
    // 0x80015034: sra         $t9, $a2, 16
    ctx->r25 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80015038: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8001503C: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80015040: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80015044: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80015048: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x8001504C: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    // 0x80015050: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80015054: jal         0x8004C580
    // 0x80015058: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_0;
    // 0x80015058: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_0:
L_8001505C:
    // 0x8001505C: beq         $fp, $zero, L_80015098
    if (ctx->r30 == 0) {
        // 0x80015060: addiu       $a0, $s3, -0x8
        ctx->r4 = ADD32(ctx->r19, -0X8);
            goto L_80015098;
    }
    // 0x80015060: addiu       $a0, $s3, -0x8
    ctx->r4 = ADD32(ctx->r19, -0X8);
    // 0x80015064: sll         $a1, $s7, 16
    ctx->r5 = S32(ctx->r23 << 16);
    // 0x80015068: sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16 << 16);
    // 0x8001506C: sra         $t3, $a2, 16
    ctx->r11 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80015070: sra         $t1, $a1, 16
    ctx->r9 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80015074: sll         $t0, $a0, 16
    ctx->r8 = S32(ctx->r4 << 16);
    // 0x80015078: sra         $a0, $t0, 16
    ctx->r4 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8001507C: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x80015080: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x80015084: addiu       $a3, $zero, 0x15
    ctx->r7 = ADD32(0, 0X15);
    // 0x80015088: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001508C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80015090: jal         0x8004C580
    // 0x80015094: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    func_8004C580(rdram, ctx);
        goto after_1;
    // 0x80015094: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    after_1:
L_80015098:
    // 0x80015098: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x8001509C: sll         $a1, $s7, 16
    ctx->r5 = S32(ctx->r23 << 16);
    // 0x800150A0: sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16 << 16);
    // 0x800150A4: addiu       $a3, $s1, 0x7
    ctx->r7 = ADD32(ctx->r17, 0X7);
    // 0x800150A8: sll         $t7, $a3, 16
    ctx->r15 = S32(ctx->r7 << 16);
    // 0x800150AC: sra         $t6, $a2, 16
    ctx->r14 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800150B0: sra         $t5, $a1, 16
    ctx->r13 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800150B4: sra         $t4, $a0, 16
    ctx->r12 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800150B8: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800150BC: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x800150C0: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x800150C4: sra         $a3, $t7, 16
    ctx->r7 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800150C8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800150CC: jal         0x8004C580
    // 0x800150D0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_2;
    // 0x800150D0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_2:
    // 0x800150D4: multu       $s1, $s2
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800150D8: mflo        $t9
    ctx->r25 = lo;
    // 0x800150DC: subu        $s5, $s5, $t9
    ctx->r21 = SUB32(ctx->r21, ctx->r25);
    // 0x800150E0: nop

    // 0x800150E4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
L_800150E8:
    // 0x800150E8: div         $zero, $s2, $at
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r1)));
    // 0x800150EC: lh          $t3, 0x6E($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X6E);
    // 0x800150F0: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x800150F4: sll         $t2, $s3, 16
    ctx->r10 = S32(ctx->r19 << 16);
    // 0x800150F8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800150FC: mflo        $t0
    ctx->r8 = lo;
    // 0x80015100: sra         $t1, $t2, 16
    ctx->r9 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80015104: or          $s2, $t0, $zero
    ctx->r18 = ctx->r8 | 0;
    // 0x80015108: bne         $s4, $t3, L_80014F98
    if (ctx->r20 != ctx->r11) {
        // 0x8001510C: or          $s3, $t1, $zero
        ctx->r19 = ctx->r9 | 0;
            goto L_80014F98;
    }
    // 0x8001510C: or          $s3, $t1, $zero
    ctx->r19 = ctx->r9 | 0;
    // 0x80015110: sh          $fp, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r30;
L_80015114:
    // 0x80015114: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80015118: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8001511C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80015120: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80015124: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80015128: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8001512C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80015130: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80015134: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80015138: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8001513C: jr          $ra
    // 0x80015140: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    TRACE_RETURN()
    return;
    // 0x80015140: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80015144(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80015144: addiu       $sp, $sp, -0x230
    ctx->r29 = ADD32(ctx->r29, -0X230);
    // 0x80015148: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8001514C: sw          $a0, 0x230($sp)
    MEM_W(0X230, ctx->r29) = ctx->r4;
    // 0x80015150: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80015154: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80015158: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8001515C: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80015160: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80015164: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80015168: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8001516C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80015170: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80015174: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80015178: sh          $zero, 0x100($sp)
    MEM_H(0X100, ctx->r29) = 0;
    // 0x8001517C: sh          $zero, 0xFE($sp)
    MEM_H(0XFE, ctx->r29) = 0;
    // 0x80015180: sh          $zero, 0xF6($sp)
    MEM_H(0XF6, ctx->r29) = 0;
    // 0x80015184: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
    // 0x80015188: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
    // 0x8001518C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80015190: jal         0x8004D134
    // 0x80015194: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004D134(rdram, ctx);
        goto after_0;
    // 0x80015194: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80015198: lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // 0x8001519C: addiu       $a0, $a0, -0x3900
    ctx->r4 = ADD32(ctx->r4, -0X3900);
    // 0x800151A0: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    // 0x800151A4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x800151A8: jal         0x80004CE0
    // 0x800151AC: addiu       $a3, $sp, 0x6C
    ctx->r7 = ADD32(ctx->r29, 0X6C);
    func_80004CE0(rdram, ctx);
        goto after_1;
    // 0x800151AC: addiu       $a3, $sp, 0x6C
    ctx->r7 = ADD32(ctx->r29, 0X6C);
    after_1:
    // 0x800151B0: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x800151B4: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    // 0x800151B8: jal         0x800499B0
    // 0x800151BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800499B0(rdram, ctx);
        goto after_2;
    // 0x800151BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x800151C0: jal         0x8004B1E0
    // 0x800151C4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_8004B1E0(rdram, ctx);
        goto after_3;
    // 0x800151C4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_3:
    // 0x800151C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800151CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800151D0: jal         0x8000BD4C
    // 0x800151D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BD4C(rdram, ctx);
        goto after_4;
    // 0x800151D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x800151D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800151DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800151E0: jal         0x8000BDEC
    // 0x800151E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BDEC(rdram, ctx);
        goto after_5;
    // 0x800151E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x800151E8: addiu       $t7, $zero, 0x3E8
    ctx->r15 = ADD32(0, 0X3E8);
    // 0x800151EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800151F0: sw          $t7, -0x2CF8($at)
    MEM_W(-0X2CF8, ctx->r1) = ctx->r15;
    // 0x800151F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800151F8: addiu       $t8, $zero, 0x3D0
    ctx->r24 = ADD32(0, 0X3D0);
    // 0x800151FC: sw          $t8, -0x2CF4($at)
    MEM_W(-0X2CF4, ctx->r1) = ctx->r24;
    // 0x80015200: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80015204: sh          $zero, -0x2CC4($at)
    MEM_H(-0X2CC4, ctx->r1) = 0;
    // 0x80015208: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001520C: lui         $at, 0x4238
    ctx->r1 = S32(0X4238 << 16);
    // 0x80015210: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80015214: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80015218: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001521C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80015220: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80015224: addiu       $v1, $v1, -0x6C40
    ctx->r3 = ADD32(ctx->r3, -0X6C40);
    // 0x80015228: addiu       $v0, $v0, -0x6C50
    ctx->r2 = ADD32(ctx->r2, -0X6C50);
    // 0x8001522C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80015230: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x80015234: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x80015238: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x8001523C: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80015240: jal         0x8000798C
    // 0x80015244: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    func_8000798C(rdram, ctx);
        goto after_6;
    // 0x80015244: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    after_6:
    // 0x80015248: jal         0x8000798C
    // 0x8001524C: nop

    func_8000798C(rdram, ctx);
        goto after_7;
    // 0x8001524C: nop

    after_7:
    // 0x80015250: jal         0x8000798C
    // 0x80015254: nop

    func_8000798C(rdram, ctx);
        goto after_8;
    // 0x80015254: nop

    after_8:
    // 0x80015258: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8001525C: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x80015260: addiu       $a0, $a0, -0x2E00
    ctx->r4 = ADD32(ctx->r4, -0X2E00);
    // 0x80015264: sw          $t9, 0x22C($sp)
    MEM_W(0X22C, ctx->r29) = ctx->r25;
    // 0x80015268: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    // 0x8001526C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80015270: jal         0x80004CE0
    // 0x80015274: addiu       $a3, $sp, 0x22C
    ctx->r7 = ADD32(ctx->r29, 0X22C);
    func_80004CE0(rdram, ctx);
        goto after_9;
    // 0x80015274: addiu       $a3, $sp, 0x22C
    ctx->r7 = ADD32(ctx->r29, 0X22C);
    after_9:
    // 0x80015278: jal         0x8000798C
    // 0x8001527C: sw          $v0, 0x228($sp)
    MEM_W(0X228, ctx->r29) = ctx->r2;
    func_8000798C(rdram, ctx);
        goto after_10;
    // 0x8001527C: sw          $v0, 0x228($sp)
    MEM_W(0X228, ctx->r29) = ctx->r2;
    after_10:
    // 0x80015280: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80015284: jal         0x80049CFC
    // 0x80015288: addiu       $a0, $a0, 0x622C
    ctx->r4 = ADD32(ctx->r4, 0X622C);
    func_80049CFC(rdram, ctx);
        goto after_11;
    // 0x80015288: addiu       $a0, $a0, 0x622C
    ctx->r4 = ADD32(ctx->r4, 0X622C);
    after_11:
    // 0x8001528C: jal         0x80049D80
    // 0x80015290: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80049D80(rdram, ctx);
        goto after_12;
    // 0x80015290: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_12:
    // 0x80015294: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80015298: jal         0x80049DFC
    // 0x8001529C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80049DFC(rdram, ctx);
        goto after_13;
    // 0x8001529C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x800152A0: sw          $v0, 0x220($sp)
    MEM_W(0X220, ctx->r29) = ctx->r2;
    // 0x800152A4: jal         0x8004A148
    // 0x800152A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8004A148(rdram, ctx);
        goto after_14;
    // 0x800152A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_14:
    // 0x800152AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800152B0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800152B4: lw          $t3, 0x220($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X220);
    // 0x800152B8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800152BC: lw          $a0, 0x8($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X8);
    // 0x800152C0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800152C4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800152C8: jal         0x80001AB4
    // 0x800152CC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80001AB4(rdram, ctx);
        goto after_15;
    // 0x800152CC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_15:
    // 0x800152D0: lw          $v1, 0x220($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X220);
    // 0x800152D4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800152D8: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x800152DC: lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X8);
    // 0x800152E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800152E4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800152E8: swc1        $f0, 0x40($t4)
    MEM_W(0X40, ctx->r12) = ctx->f0.u32l;
    // 0x800152EC: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    // 0x800152F0: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x800152F4: swc1        $f0, 0x44($t5)
    MEM_W(0X44, ctx->r13) = ctx->f0.u32l;
    // 0x800152F8: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x800152FC: swc1        $f8, 0x48($t6)
    MEM_W(0X48, ctx->r14) = ctx->f8.u32l;
    // 0x80015300: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x80015304: lw          $t7, 0xD8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XD8);
    // 0x80015308: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x8001530C: sw          $t8, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r24;
    // 0x80015310: lw          $t9, -0x68C8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X68C8);
    // 0x80015314: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x80015318: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x8001531C: jal         0x80049CFC
    // 0x80015320: lw          $a0, -0x675C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X675C);
    func_80049CFC(rdram, ctx);
        goto after_16;
    // 0x80015320: lw          $a0, -0x675C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X675C);
    after_16:
    // 0x80015324: jal         0x80049D80
    // 0x80015328: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80049D80(rdram, ctx);
        goto after_17;
    // 0x80015328: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_17:
    // 0x8001532C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80015330: jal         0x80049DFC
    // 0x80015334: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80049DFC(rdram, ctx);
        goto after_18;
    // 0x80015334: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_18:
    // 0x80015338: sw          $v0, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r2;
    // 0x8001533C: jal         0x8004A148
    // 0x80015340: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8004A148(rdram, ctx);
        goto after_19;
    // 0x80015340: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_19:
    // 0x80015344: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80015348: addiu       $s0, $sp, 0xB0
    ctx->r16 = ADD32(ctx->r29, 0XB0);
    // 0x8001534C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80015350: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80015354: lui         $a1, 0xBE80
    ctx->r5 = S32(0XBE80 << 16);
    // 0x80015358: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8001535C: jal         0x80049840
    // 0x80015360: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80049840(rdram, ctx);
        goto after_20;
    // 0x80015360: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_20:
    // 0x80015364: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80015368: lwc1        $f0, 0x6234($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6234);
    // 0x8001536C: addiu       $s1, $sp, 0x70
    ctx->r17 = ADD32(ctx->r29, 0X70);
    // 0x80015370: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80015374: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80015378: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8001537C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80015380: jal         0x80001AB4
    // 0x80015384: nop

    func_80001AB4(rdram, ctx);
        goto after_21;
    // 0x80015384: nop

    after_21:
    // 0x80015388: lw          $t4, 0x214($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X214);
    // 0x8001538C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80015390: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80015394: lw          $a0, 0x8($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X8);
    // 0x80015398: jal         0x80000BD8
    // 0x8001539C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80000BD8(rdram, ctx);
        goto after_22;
    // 0x8001539C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_22:
    // 0x800153A0: lw          $t0, 0x214($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X214);
    // 0x800153A4: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x800153A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800153AC: lw          $t5, 0x8($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X8);
    // 0x800153B0: lui         $at, 0xC292
    ctx->r1 = S32(0XC292 << 16);
    // 0x800153B4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800153B8: swc1        $f10, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f10.u32l;
    // 0x800153BC: lw          $t6, 0x8($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X8);
    // 0x800153C0: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x800153C4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800153C8: swc1        $f16, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->f16.u32l;
    // 0x800153CC: lw          $t7, 0x8($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X8);
    // 0x800153D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800153D4: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x800153D8: swc1        $f18, 0x48($t7)
    MEM_W(0X48, ctx->r15) = ctx->f18.u32l;
    // 0x800153DC: lw          $v0, 0x8($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X8);
    // 0x800153E0: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x800153E4: addiu       $a3, $zero, 0x16
    ctx->r7 = ADD32(0, 0X16);
    // 0x800153E8: lw          $t8, 0xD8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XD8);
    // 0x800153EC: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x800153F0: sw          $t9, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r25;
    // 0x800153F4: lw          $t3, 0x8($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X8);
    // 0x800153F8: lw          $v1, 0xE0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0XE0);
    // 0x800153FC: lbu         $t4, 0x10($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X10);
    // 0x80015400: ori         $t5, $t4, 0x4
    ctx->r13 = ctx->r12 | 0X4;
    // 0x80015404: sb          $t5, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r13;
    // 0x80015408: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8001540C: jal         0x8004C580
    // 0x80015410: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_23;
    // 0x80015410: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_23:
    // 0x80015414: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80015418: addiu       $a1, $zero, -0x5C
    ctx->r5 = ADD32(0, -0X5C);
    // 0x8001541C: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x80015420: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x80015424: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80015428: jal         0x8004C580
    // 0x8001542C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_24;
    // 0x8001542C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_24:
    // 0x80015430: jal         0x80044514
    // 0x80015434: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_80044514(rdram, ctx);
        goto after_25;
    // 0x80015434: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_25:
    // 0x80015438: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001543C: addiu       $v0, $v0, -0x6628
    ctx->r2 = ADD32(ctx->r2, -0X6628);
    // 0x80015440: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x80015444: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x80015448: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8001544C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80015450: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80015454: addiu       $v1, $v1, -0x6A20
    ctx->r3 = ADD32(ctx->r3, -0X6A20);
    // 0x80015458: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001545C: lh          $t3, 0xE8($v1)
    ctx->r11 = MEM_H(ctx->r3, 0XE8);
    // 0x80015460: lh          $t4, 0xEC($v1)
    ctx->r12 = MEM_H(ctx->r3, 0XEC);
    // 0x80015464: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80015468: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8001546C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80015470: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80015474: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80015478: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8001547C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80015480: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80015484: addiu       $s1, $s1, -0x6BA2
    ctx->r17 = ADD32(ctx->r17, -0X6BA2);
    // 0x80015488: addiu       $s0, $s0, -0x6BA4
    ctx->r16 = ADD32(ctx->r16, -0X6BA4);
    // 0x8001548C: div.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80015490: mul.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80015494: cvt.s.w     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80015498: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8001549C: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800154A0: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x800154A4: nop

    // 0x800154A8: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x800154AC: mul.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800154B0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800154B4: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x800154B8: jal         0x80013CD0
    // 0x800154BC: sh          $t6, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r14;
    func_80013CD0(rdram, ctx);
        goto after_26;
    // 0x800154BC: sh          $t6, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r14;
    after_26:
    // 0x800154C0: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800154C4: addiu       $t2, $t2, -0x6BA0
    ctx->r10 = ADD32(ctx->r10, -0X6BA0);
    // 0x800154C8: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
    // 0x800154CC: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // 0x800154D0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800154D4: lw          $t7, -0x6BDC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6BDC);
    // 0x800154D8: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x800154DC: bne         $a0, $v1, L_800154F0
    if (ctx->r4 != ctx->r3) {
        // 0x800154E0: sw          $t7, 0x110($sp)
        MEM_W(0X110, ctx->r29) = ctx->r15;
            goto L_800154F0;
    }
    // 0x800154E0: sw          $t7, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r15;
    // 0x800154E4: addiu       $t8, $zero, 0x4E20
    ctx->r24 = ADD32(0, 0X4E20);
    // 0x800154E8: b           L_80015500
    // 0x800154EC: sw          $t8, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r24;
        goto L_80015500;
    // 0x800154EC: sw          $t8, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r24;
L_800154F0:
    // 0x800154F0: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800154F4: mflo        $t9
    ctx->r25 = lo;
    // 0x800154F8: sw          $t9, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r25;
    // 0x800154FC: nop

L_80015500:
    // 0x80015500: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80015504: lh          $v0, -0x6622($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X6622);
    // 0x80015508: addiu       $a0, $zero, 0x2710
    ctx->r4 = ADD32(0, 0X2710);
    // 0x8001550C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80015510: multu       $a0, $v0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80015514: lh          $a1, -0x6620($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X6620);
    // 0x80015518: addiu       $a3, $zero, -0x2710
    ctx->r7 = ADD32(0, -0X2710);
    // 0x8001551C: lh          $t0, 0x0($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X0);
    // 0x80015520: addiu       $t1, $zero, 0x64
    ctx->r9 = ADD32(0, 0X64);
    // 0x80015524: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x80015528: sh          $t1, 0x1B4($sp)
    MEM_H(0X1B4, ctx->r29) = ctx->r9;
    // 0x8001552C: sh          $a3, 0x190($sp)
    MEM_H(0X190, ctx->r29) = ctx->r7;
    // 0x80015530: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80015534: sh          $t0, 0x1B2($sp)
    MEM_H(0X1B2, ctx->r29) = ctx->r8;
    // 0x80015538: mflo        $t3
    ctx->r11 = lo;
    // 0x8001553C: sh          $v1, 0x146($sp)
    MEM_H(0X146, ctx->r29) = ctx->r3;
    // 0x80015540: sw          $t3, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r11;
    // 0x80015544: multu       $a3, $a1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80015548: sw          $zero, 0x1E8($sp)
    MEM_W(0X1E8, ctx->r29) = 0;
    // 0x8001554C: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    // 0x80015550: addiu       $a2, $a2, -0x676C
    ctx->r6 = ADD32(ctx->r6, -0X676C);
    // 0x80015554: sh          $a0, 0x16C($sp)
    MEM_H(0X16C, ctx->r29) = ctx->r4;
    // 0x80015558: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8001555C: addiu       $s3, $sp, 0x108
    ctx->r19 = ADD32(ctx->r29, 0X108);
    // 0x80015560: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x80015564: addiu       $s7, $zero, 0x3
    ctx->r23 = ADD32(0, 0X3);
    // 0x80015568: addiu       $s6, $zero, 0x24
    ctx->r22 = ADD32(0, 0X24);
    // 0x8001556C: mflo        $t4
    ctx->r12 = lo;
    // 0x80015570: sw          $t4, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r12;
    // 0x80015574: addiu       $s5, $sp, 0x108
    ctx->r21 = ADD32(ctx->r29, 0X108);
    // 0x80015578: multu       $t1, $t0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001557C: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x80015580: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x80015584: sh          $v0, 0x16A($sp)
    MEM_H(0X16A, ctx->r29) = ctx->r2;
    // 0x80015588: sh          $a1, 0x18E($sp)
    MEM_H(0X18E, ctx->r29) = ctx->r5;
    // 0x8001558C: sw          $t6, 0x1C4($sp)
    MEM_W(0X1C4, ctx->r29) = ctx->r14;
    // 0x80015590: mflo        $t5
    ctx->r13 = lo;
    // 0x80015594: sw          $t5, 0x1A0($sp)
    MEM_W(0X1A0, ctx->r29) = ctx->r13;
    // 0x80015598: nop

L_8001559C:
    // 0x8001559C: lh          $t7, 0x0($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X0);
    // 0x800155A0: sh          $s4, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r20;
    // 0x800155A4: sw          $zero, 0x4($s3)
    MEM_W(0X4, ctx->r19) = 0;
    // 0x800155A8: sh          $a3, 0x14($s3)
    MEM_H(0X14, ctx->r19) = ctx->r7;
    // 0x800155AC: beq         $s4, $t0, L_8001563C
    if (ctx->r20 == ctx->r8) {
        // 0x800155B0: sh          $t7, 0x2($s3)
        MEM_H(0X2, ctx->r19) = ctx->r15;
            goto L_8001563C;
    }
    // 0x800155B0: sh          $t7, 0x2($s3)
    MEM_H(0X2, ctx->r19) = ctx->r15;
    // 0x800155B4: lw          $v0, 0x8($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X8);
    // 0x800155B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800155BC: bgez        $v0, L_800155D8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800155C0: nop
    
            goto L_800155D8;
    }
    // 0x800155C0: nop

    // 0x800155C4: negu        $t8, $v0
    ctx->r24 = SUB32(0, ctx->r2);
    // 0x800155C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800155CC: sw          $t8, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r24;
    // 0x800155D0: b           L_800155D8
    // 0x800155D4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_800155D8;
    // 0x800155D4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800155D8:
    // 0x800155D8: lh          $v1, 0x14($s3)
    ctx->r3 = MEM_H(ctx->r19, 0X14);
    // 0x800155DC: div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // 0x800155E0: mflo        $a0
    ctx->r4 = lo;
    // 0x800155E4: sw          $a0, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->r4;
    // 0x800155E8: bne         $v1, $zero, L_800155F4
    if (ctx->r3 != 0) {
        // 0x800155EC: nop
    
            goto L_800155F4;
    }
    // 0x800155EC: nop

    // 0x800155F0: break       7
    do_break(2147571184);
L_800155F4:
    // 0x800155F4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800155F8: bne         $v1, $at, L_8001560C
    if (ctx->r3 != ctx->r1) {
        // 0x800155FC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001560C;
    }
    // 0x800155FC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80015600: bne         $v0, $at, L_8001560C
    if (ctx->r2 != ctx->r1) {
        // 0x80015604: nop
    
            goto L_8001560C;
    }
    // 0x80015604: nop

    // 0x80015608: break       6
    do_break(2147571208);
L_8001560C:
    // 0x8001560C: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80015610: mflo        $t9
    ctx->r25 = lo;
    // 0x80015614: subu        $t3, $v0, $t9
    ctx->r11 = SUB32(ctx->r2, ctx->r25);
    // 0x80015618: beq         $a1, $zero, L_8001563C
    if (ctx->r5 == 0) {
        // 0x8001561C: sw          $t3, 0x10($s3)
        MEM_W(0X10, ctx->r19) = ctx->r11;
            goto L_8001563C;
    }
    // 0x8001561C: sw          $t3, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->r11;
    // 0x80015620: negu        $t4, $v0
    ctx->r12 = SUB32(0, ctx->r2);
    // 0x80015624: negu        $t6, $a0
    ctx->r14 = SUB32(0, ctx->r4);
    // 0x80015628: negu        $t8, $t3
    ctx->r24 = SUB32(0, ctx->r11);
    // 0x8001562C: sw          $t4, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r12;
    // 0x80015630: sw          $t6, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->r14;
    // 0x80015634: or          $t5, $a0, $zero
    ctx->r13 = ctx->r4 | 0;
    // 0x80015638: sw          $t8, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->r24;
L_8001563C:
    // 0x8001563C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80015640: addiu       $s3, $s3, 0x24
    ctx->r19 = ADD32(ctx->r19, 0X24);
    // 0x80015644: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x80015648: sh          $zero, -0xE($s3)
    MEM_H(-0XE, ctx->r19) = 0;
    // 0x8001564C: bne         $s4, $t1, L_8001559C
    if (ctx->r20 != ctx->r9) {
        // 0x80015650: sh          $zero, -0xC($s3)
        MEM_H(-0XC, ctx->r19) = 0;
            goto L_8001559C;
    }
    // 0x80015650: sh          $zero, -0xC($s3)
    MEM_H(-0XC, ctx->r19) = 0;
    // 0x80015654: lw          $s2, 0x104($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X104);
    // 0x80015658: lw          $s1, 0xF8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XF8);
    // 0x8001565C: lh          $t9, 0xF6($sp)
    ctx->r25 = MEM_H(ctx->r29, 0XF6);
L_80015660:
    // 0x80015660: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80015664: addiu       $s3, $sp, 0x108
    ctx->r19 = ADD32(ctx->r29, 0X108);
    // 0x80015668: beq         $t9, $zero, L_800156F8
    if (ctx->r25 == 0) {
        // 0x8001566C: nop
    
            goto L_800156F8;
    }
    // 0x8001566C: nop

    // 0x80015670: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x80015674: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80015678: bne         $t3, $at, L_800156F8
    if (ctx->r11 != ctx->r1) {
        // 0x8001567C: nop
    
            goto L_800156F8;
    }
    // 0x8001567C: nop

    // 0x80015680: jal         0x8004A0C4
    // 0x80015684: lw          $a0, 0x214($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X214);
    func_8004A0C4(rdram, ctx);
        goto after_27;
    // 0x80015684: lw          $a0, 0x214($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X214);
    after_27:
    // 0x80015688: jal         0x8004A0C4
    // 0x8001568C: lw          $a0, 0x220($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X220);
    func_8004A0C4(rdram, ctx);
        goto after_28;
    // 0x8001568C: lw          $a0, 0x220($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X220);
    after_28:
    // 0x80015690: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80015694: jal         0x8004C4D8
    // 0x80015698: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004C4D8(rdram, ctx);
        goto after_29;
    // 0x80015698: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_29:
    // 0x8001569C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800156A0: sw          $t4, 0x22C($sp)
    MEM_W(0X22C, ctx->r29) = ctx->r12;
L_800156A4:
    // 0x800156A4: jal         0x8000798C
    // 0x800156A8: nop

    func_8000798C(rdram, ctx);
        goto after_30;
    // 0x800156A8: nop

    after_30:
    // 0x800156AC: lw          $t5, 0x22C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X22C);
    // 0x800156B0: bne         $t5, $zero, L_800156A4
    if (ctx->r13 != 0) {
        // 0x800156B4: nop
    
            goto L_800156A4;
    }
    // 0x800156B4: nop

    // 0x800156B8: jal         0x80004E5C
    // 0x800156BC: lw          $a0, 0x228($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X228);
    func_80004E5C(rdram, ctx);
        goto after_31;
    // 0x800156BC: lw          $a0, 0x228($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X228);
    after_31:
    // 0x800156C0: jal         0x80049C48
    // 0x800156C4: nop

    func_80049C48(rdram, ctx);
        goto after_32;
    // 0x800156C4: nop

    after_32:
    // 0x800156C8: jal         0x8004B21C
    // 0x800156CC: nop

    func_8004B21C(rdram, ctx);
        goto after_33;
    // 0x800156CC: nop

    after_33:
    // 0x800156D0: jal         0x80004E5C
    // 0x800156D4: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    func_80004E5C(rdram, ctx);
        goto after_34;
    // 0x800156D4: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    after_34:
    // 0x800156D8: jal         0x8000798C
    // 0x800156DC: nop

    func_8000798C(rdram, ctx);
        goto after_35;
    // 0x800156DC: nop

    after_35:
    // 0x800156E0: lw          $t6, 0x230($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X230);
    // 0x800156E4: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
L_800156E8:
    // 0x800156E8: jal         0x8000798C
    // 0x800156EC: nop

    func_8000798C(rdram, ctx);
        goto after_36;
    // 0x800156EC: nop

    after_36:
    // 0x800156F0: b           L_800156E8
    // 0x800156F4: nop

        goto L_800156E8;
    // 0x800156F4: nop

L_800156F8:
    // 0x800156F8: lh          $v1, 0x16($s3)
    ctx->r3 = MEM_H(ctx->r19, 0X16);
    // 0x800156FC: beq         $v1, $zero, L_80015B58
    if (ctx->r3 == 0) {
        // 0x80015700: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80015B58;
    }
    // 0x80015700: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80015704: beq         $v0, $fp, L_80015728
    if (ctx->r2 == ctx->r30) {
        // 0x80015708: negu        $at, $s4
        ctx->r1 = SUB32(0, ctx->r20);
            goto L_80015728;
    }
    // 0x80015708: negu        $at, $s4
    ctx->r1 = SUB32(0, ctx->r20);
    // 0x8001570C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80015710: beql        $v0, $at, L_80015A98
    if (ctx->r2 == ctx->r1) {
        // 0x80015714: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80015A98;
    }
    goto skip_0;
    // 0x80015714: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    skip_0:
    // 0x80015718: beq         $v0, $s7, L_80015B58
    if (ctx->r2 == ctx->r23) {
        // 0x8001571C: nop
    
            goto L_80015B58;
    }
    // 0x8001571C: nop

    // 0x80015720: b           L_80015B58
    // 0x80015724: nop

        goto L_80015B58;
    // 0x80015724: nop

L_80015728:
    // 0x80015728: sll         $s2, $at, 2
    ctx->r18 = S32(ctx->r1 << 2);
    // 0x8001572C: addu        $s2, $s2, $at
    ctx->r18 = ADD32(ctx->r18, ctx->r1);
    // 0x80015730: sll         $s2, $s2, 2
    ctx->r18 = S32(ctx->r18 << 2);
    // 0x80015734: subu        $s2, $s2, $at
    ctx->r18 = SUB32(ctx->r18, ctx->r1);
    // 0x80015738: addiu       $s2, $s2, 0x3E
    ctx->r18 = ADD32(ctx->r18, 0X3E);
    // 0x8001573C: sll         $t7, $s2, 16
    ctx->r15 = S32(ctx->r18 << 16);
    // 0x80015740: sra         $s2, $t7, 16
    ctx->r18 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80015744: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x80015748: sra         $t9, $a1, 16
    ctx->r25 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8001574C: lh          $a3, 0x2($s3)
    ctx->r7 = MEM_H(ctx->r19, 0X2);
    // 0x80015750: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80015754: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80015758: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x8001575C: addiu       $a0, $zero, -0x59
    ctx->r4 = ADD32(0, -0X59);
    // 0x80015760: jal         0x8004C580
    // 0x80015764: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    func_8004C580(rdram, ctx);
        goto after_37;
    // 0x80015764: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    after_37:
    // 0x80015768: beq         $s4, $fp, L_80015798
    if (ctx->r20 == ctx->r30) {
        // 0x8001576C: addiu       $a0, $zero, -0x1B
        ctx->r4 = ADD32(0, -0X1B);
            goto L_80015798;
    }
    // 0x8001576C: addiu       $a0, $zero, -0x1B
    ctx->r4 = ADD32(0, -0X1B);
    // 0x80015770: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80015774: beq         $s4, $at, L_800157F8
    if (ctx->r20 == ctx->r1) {
        // 0x80015778: addiu       $a0, $zero, -0x1B
        ctx->r4 = ADD32(0, -0X1B);
            goto L_800157F8;
    }
    // 0x80015778: addiu       $a0, $zero, -0x1B
    ctx->r4 = ADD32(0, -0X1B);
    // 0x8001577C: beq         $s4, $s7, L_800158C8
    if (ctx->r20 == ctx->r23) {
        // 0x80015780: addiu       $a0, $zero, -0x1B
        ctx->r4 = ADD32(0, -0X1B);
            goto L_800158C8;
    }
    // 0x80015780: addiu       $a0, $zero, -0x1B
    ctx->r4 = ADD32(0, -0X1B);
    // 0x80015784: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80015788: beq         $s4, $at, L_80015998
    if (ctx->r20 == ctx->r1) {
        // 0x8001578C: addiu       $a0, $zero, -0x1B
        ctx->r4 = ADD32(0, -0X1B);
            goto L_80015998;
    }
    // 0x8001578C: addiu       $a0, $zero, -0x1B
    ctx->r4 = ADD32(0, -0X1B);
    // 0x80015790: b           L_80015A60
    // 0x80015794: nop

        goto L_80015A60;
    // 0x80015794: nop

L_80015798:
    // 0x80015798: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x8001579C: sll         $a3, $s7, 16
    ctx->r7 = S32(ctx->r23 << 16);
    // 0x800157A0: sra         $t4, $a3, 16
    ctx->r12 = S32(SIGNED(ctx->r7) >> 16);
    // 0x800157A4: sra         $t3, $a1, 16
    ctx->r11 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800157A8: lh          $a2, 0x1A($s3)
    ctx->r6 = MEM_H(ctx->r19, 0X1A);
    // 0x800157AC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800157B0: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x800157B4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x800157B8: jal         0x80014F00
    // 0x800157BC: or          $a3, $t4, $zero
    ctx->r7 = ctx->r12 | 0;
    func_80014F00(rdram, ctx);
        goto after_38;
    // 0x800157BC: or          $a3, $t4, $zero
    ctx->r7 = ctx->r12 | 0;
    after_38:
    // 0x800157C0: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x800157C4: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x800157C8: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x800157CC: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800157D0: sra         $t5, $a0, 16
    ctx->r13 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800157D4: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x800157D8: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800157DC: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x800157E0: addiu       $a3, $zero, 0x12
    ctx->r7 = ADD32(0, 0X12);
    // 0x800157E4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800157E8: jal         0x8004C580
    // 0x800157EC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_39;
    // 0x800157EC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_39:
    // 0x800157F0: b           L_80015A60
    // 0x800157F4: nop

        goto L_80015A60;
    // 0x800157F4: nop

L_800157F8:
    // 0x800157F8: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x800157FC: sll         $a3, $s7, 16
    ctx->r7 = S32(ctx->r23 << 16);
    // 0x80015800: sra         $t8, $a3, 16
    ctx->r24 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80015804: sra         $t7, $a1, 16
    ctx->r15 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80015808: lh          $a2, 0x1A($s3)
    ctx->r6 = MEM_H(ctx->r19, 0X1A);
    // 0x8001580C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80015810: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x80015814: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80015818: jal         0x80014F00
    // 0x8001581C: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    func_80014F00(rdram, ctx);
        goto after_40;
    // 0x8001581C: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    after_40:
    // 0x80015820: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x80015824: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80015828: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x8001582C: sra         $t3, $a1, 16
    ctx->r11 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80015830: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80015834: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x80015838: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x8001583C: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x80015840: addiu       $a3, $zero, 0x13
    ctx->r7 = ADD32(0, 0X13);
    // 0x80015844: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80015848: jal         0x8004C580
    // 0x8001584C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_41;
    // 0x8001584C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_41:
    // 0x80015850: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80015854: sll         $t4, $s0, 16
    ctx->r12 = S32(ctx->r16 << 16);
    // 0x80015858: sra         $s0, $t4, 16
    ctx->r16 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8001585C: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80015860: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x80015864: sra         $t7, $a1, 16
    ctx->r15 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80015868: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001586C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80015870: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80015874: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x80015878: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    // 0x8001587C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80015880: jal         0x8004C580
    // 0x80015884: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_42;
    // 0x80015884: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_42:
    // 0x80015888: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8001588C: sll         $t8, $s0, 16
    ctx->r24 = S32(ctx->r16 << 16);
    // 0x80015890: sra         $s0, $t8, 16
    ctx->r16 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80015894: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80015898: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x8001589C: sra         $t4, $a1, 16
    ctx->r12 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800158A0: sra         $t3, $a0, 16
    ctx->r11 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800158A4: lh          $a2, 0x1C($s3)
    ctx->r6 = MEM_H(ctx->r19, 0X1C);
    // 0x800158A8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800158AC: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x800158B0: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x800158B4: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x800158B8: jal         0x80014F00
    // 0x800158BC: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    func_80014F00(rdram, ctx);
        goto after_43;
    // 0x800158BC: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_43:
    // 0x800158C0: b           L_80015A60
    // 0x800158C4: nop

        goto L_80015A60;
    // 0x800158C4: nop

L_800158C8:
    // 0x800158C8: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x800158CC: sll         $a3, $s7, 16
    ctx->r7 = S32(ctx->r23 << 16);
    // 0x800158D0: sra         $t6, $a3, 16
    ctx->r14 = S32(SIGNED(ctx->r7) >> 16);
    // 0x800158D4: sra         $t5, $a1, 16
    ctx->r13 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800158D8: lh          $a2, 0x1A($s3)
    ctx->r6 = MEM_H(ctx->r19, 0X1A);
    // 0x800158DC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800158E0: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x800158E4: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x800158E8: jal         0x80014F00
    // 0x800158EC: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    func_80014F00(rdram, ctx);
        goto after_44;
    // 0x800158EC: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    after_44:
    // 0x800158F0: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x800158F4: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x800158F8: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x800158FC: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80015900: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80015904: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80015908: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x8001590C: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x80015910: addiu       $a3, $zero, 0x13
    ctx->r7 = ADD32(0, 0X13);
    // 0x80015914: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80015918: jal         0x8004C580
    // 0x8001591C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_45;
    // 0x8001591C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_45:
    // 0x80015920: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80015924: sll         $t9, $s0, 16
    ctx->r25 = S32(ctx->r16 << 16);
    // 0x80015928: sra         $s0, $t9, 16
    ctx->r16 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8001592C: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80015930: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x80015934: sra         $t5, $a1, 16
    ctx->r13 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80015938: sra         $t4, $a0, 16
    ctx->r12 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001593C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x80015940: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x80015944: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x80015948: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    // 0x8001594C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80015950: jal         0x8004C580
    // 0x80015954: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_46;
    // 0x80015954: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_46:
    // 0x80015958: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8001595C: sll         $t6, $s0, 16
    ctx->r14 = S32(ctx->r16 << 16);
    // 0x80015960: sra         $s0, $t6, 16
    ctx->r16 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80015964: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80015968: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x8001596C: sra         $t9, $a1, 16
    ctx->r25 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80015970: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80015974: lh          $a2, 0x1C($s3)
    ctx->r6 = MEM_H(ctx->r19, 0X1C);
    // 0x80015978: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8001597C: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x80015980: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80015984: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x80015988: jal         0x80014F00
    // 0x8001598C: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    func_80014F00(rdram, ctx);
        goto after_47;
    // 0x8001598C: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_47:
    // 0x80015990: b           L_80015A60
    // 0x80015994: nop

        goto L_80015A60;
    // 0x80015994: nop

L_80015998:
    // 0x80015998: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x8001599C: sll         $a3, $s7, 16
    ctx->r7 = S32(ctx->r23 << 16);
    // 0x800159A0: sra         $t4, $a3, 16
    ctx->r12 = S32(SIGNED(ctx->r7) >> 16);
    // 0x800159A4: sra         $t3, $a1, 16
    ctx->r11 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800159A8: lh          $a2, 0x1A($s3)
    ctx->r6 = MEM_H(ctx->r19, 0X1A);
    // 0x800159AC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800159B0: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x800159B4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x800159B8: jal         0x80014F00
    // 0x800159BC: or          $a3, $t4, $zero
    ctx->r7 = ctx->r12 | 0;
    func_80014F00(rdram, ctx);
        goto after_48;
    // 0x800159BC: or          $a3, $t4, $zero
    ctx->r7 = ctx->r12 | 0;
    after_48:
    // 0x800159C0: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x800159C4: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x800159C8: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x800159CC: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800159D0: sra         $t5, $a0, 16
    ctx->r13 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800159D4: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x800159D8: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800159DC: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x800159E0: addiu       $a3, $zero, 0x12
    ctx->r7 = ADD32(0, 0X12);
    // 0x800159E4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800159E8: jal         0x8004C580
    // 0x800159EC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_49;
    // 0x800159EC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_49:
    // 0x800159F0: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800159F4: sll         $t7, $s0, 16
    ctx->r15 = S32(ctx->r16 << 16);
    // 0x800159F8: sra         $s0, $t7, 16
    ctx->r16 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800159FC: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80015A00: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x80015A04: sra         $t3, $a1, 16
    ctx->r11 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80015A08: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80015A0C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x80015A10: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x80015A14: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x80015A18: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    // 0x80015A1C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80015A20: jal         0x8004C580
    // 0x80015A24: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_50;
    // 0x80015A24: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_50:
    // 0x80015A28: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80015A2C: sll         $t4, $s0, 16
    ctx->r12 = S32(ctx->r16 << 16);
    // 0x80015A30: sra         $s0, $t4, 16
    ctx->r16 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80015A34: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80015A38: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x80015A3C: sra         $t7, $a1, 16
    ctx->r15 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80015A40: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80015A44: lh          $a2, 0x1C($s3)
    ctx->r6 = MEM_H(ctx->r19, 0X1C);
    // 0x80015A48: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80015A4C: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x80015A50: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80015A54: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80015A58: jal         0x80014F00
    // 0x80015A5C: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    func_80014F00(rdram, ctx);
        goto after_51;
    // 0x80015A5C: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_51:
L_80015A60:
    // 0x80015A60: jal         0x80044480
    // 0x80015A64: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    func_80044480(rdram, ctx);
        goto after_52;
    // 0x80015A64: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_52:
    // 0x80015A68: lw          $t9, 0x8($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X8);
    // 0x80015A6C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80015A70: sh          $t8, 0x16($s3)
    MEM_H(0X16, ctx->r19) = ctx->r24;
    // 0x80015A74: beq         $t9, $zero, L_80015A8C
    if (ctx->r25 == 0) {
        // 0x80015A78: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80015A8C;
    }
    // 0x80015A78: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80015A7C: jal         0x80044480
    // 0x80015A80: addiu       $a0, $zero, -0x4
    ctx->r4 = ADD32(0, -0X4);
    func_80044480(rdram, ctx);
        goto after_53;
    // 0x80015A80: addiu       $a0, $zero, -0x4
    ctx->r4 = ADD32(0, -0X4);
    after_53:
    // 0x80015A84: b           L_80015A8C
    // 0x80015A88: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
        goto L_80015A8C;
    // 0x80015A88: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_80015A8C:
    // 0x80015A8C: b           L_80015B58
    // 0x80015A90: lh          $v1, 0x16($s3)
    ctx->r3 = MEM_H(ctx->r19, 0X16);
        goto L_80015B58;
    // 0x80015A90: lh          $v1, 0x16($s3)
    ctx->r3 = MEM_H(ctx->r19, 0X16);
    // 0x80015A94: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
L_80015A98:
    // 0x80015A98: bne         $s4, $at, L_80015AEC
    if (ctx->r20 != ctx->r1) {
        // 0x80015A9C: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_80015AEC;
    }
    // 0x80015A9C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80015AA0: multu       $v1, $s6
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80015AA4: lw          $s1, 0x10C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X10C);
    // 0x80015AA8: lw          $t3, 0x130($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X130);
    // 0x80015AAC: addiu       $a0, $zero, 0x56
    ctx->r4 = ADD32(0, 0X56);
    // 0x80015AB0: addu        $s1, $s1, $t3
    ctx->r17 = ADD32(ctx->r17, ctx->r11);
    // 0x80015AB4: mflo        $t4
    ctx->r12 = lo;
    // 0x80015AB8: addu        $v0, $s5, $t4
    ctx->r2 = ADD32(ctx->r21, ctx->r12);
    // 0x80015ABC: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x80015AC0: lw          $t6, 0x28($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X28);
    // 0x80015AC4: lw          $t7, 0x4C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4C);
    // 0x80015AC8: lw          $t8, 0x70($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X70);
    // 0x80015ACC: addu        $s1, $s1, $t5
    ctx->r17 = ADD32(ctx->r17, ctx->r13);
    // 0x80015AD0: addu        $s1, $s1, $t6
    ctx->r17 = ADD32(ctx->r17, ctx->r14);
    // 0x80015AD4: addu        $s1, $s1, $t7
    ctx->r17 = ADD32(ctx->r17, ctx->r15);
    // 0x80015AD8: addu        $s1, $s1, $t8
    ctx->r17 = ADD32(ctx->r17, ctx->r24);
    // 0x80015ADC: jal         0x80044480
    // 0x80015AE0: sw          $s1, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r17;
    func_80044480(rdram, ctx);
        goto after_54;
    // 0x80015AE0: sw          $s1, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r17;
    after_54:
    // 0x80015AE4: b           L_80015B54
    // 0x80015AE8: sh          $s7, 0x16($s3)
    MEM_H(0X16, ctx->r19) = ctx->r23;
        goto L_80015B54;
    // 0x80015AE8: sh          $s7, 0x16($s3)
    MEM_H(0X16, ctx->r19) = ctx->r23;
L_80015AEC:
    // 0x80015AEC: lw          $v0, 0x10($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X10);
    // 0x80015AF0: beql        $v0, $zero, L_80015B0C
    if (ctx->r2 == 0) {
        // 0x80015AF4: lw          $t4, 0x4($s3)
        ctx->r12 = MEM_W(ctx->r19, 0X4);
            goto L_80015B0C;
    }
    goto skip_1;
    // 0x80015AF4: lw          $t4, 0x4($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X4);
    skip_1:
    // 0x80015AF8: lw          $t9, 0x4($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X4);
    // 0x80015AFC: sw          $zero, 0x10($s3)
    MEM_W(0X10, ctx->r19) = 0;
    // 0x80015B00: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x80015B04: sw          $t3, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r11;
    // 0x80015B08: lw          $t4, 0x4($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X4);
L_80015B0C:
    // 0x80015B0C: lw          $t5, 0xC($s3)
    ctx->r13 = MEM_W(ctx->r19, 0XC);
    // 0x80015B10: lw          $t7, 0x8($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X8);
    // 0x80015B14: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80015B18: sw          $t6, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r14;
    // 0x80015B1C: bne         $t7, $t6, L_80015B34
    if (ctx->r15 != ctx->r14) {
        // 0x80015B20: or          $t8, $t6, $zero
        ctx->r24 = ctx->r14 | 0;
            goto L_80015B34;
    }
    // 0x80015B20: or          $t8, $t6, $zero
    ctx->r24 = ctx->r14 | 0;
    // 0x80015B24: beql        $s2, $zero, L_80015B38
    if (ctx->r18 == 0) {
        // 0x80015B28: lh          $t9, 0x14($s3)
        ctx->r25 = MEM_H(ctx->r19, 0X14);
            goto L_80015B38;
    }
    goto skip_2;
    // 0x80015B28: lh          $t9, 0x14($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X14);
    skip_2:
    // 0x80015B2C: jal         0x80008320
    // 0x80015B30: andi        $a0, $s2, 0xFFFF
    ctx->r4 = ctx->r18 & 0XFFFF;
    func_80008320(rdram, ctx);
        goto after_55;
    // 0x80015B30: andi        $a0, $s2, 0xFFFF
    ctx->r4 = ctx->r18 & 0XFFFF;
    after_55:
L_80015B34:
    // 0x80015B34: lh          $t9, 0x14($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X14);
L_80015B38:
    // 0x80015B38: addiu       $t3, $t9, -0x1
    ctx->r11 = ADD32(ctx->r25, -0X1);
    // 0x80015B3C: sh          $t3, 0x14($s3)
    MEM_H(0X14, ctx->r19) = ctx->r11;
    // 0x80015B40: lh          $t4, 0x14($s3)
    ctx->r12 = MEM_H(ctx->r19, 0X14);
    // 0x80015B44: bnel        $t4, $zero, L_80015B58
    if (ctx->r12 != 0) {
        // 0x80015B48: lh          $v1, 0x16($s3)
        ctx->r3 = MEM_H(ctx->r19, 0X16);
            goto L_80015B58;
    }
    goto skip_3;
    // 0x80015B48: lh          $v1, 0x16($s3)
    ctx->r3 = MEM_H(ctx->r19, 0X16);
    skip_3:
    // 0x80015B4C: sh          $s7, 0x16($s3)
    MEM_H(0X16, ctx->r19) = ctx->r23;
    // 0x80015B50: sh          $fp, 0x3A($s3)
    MEM_H(0X3A, ctx->r19) = ctx->r30;
L_80015B54:
    // 0x80015B54: lh          $v1, 0x16($s3)
    ctx->r3 = MEM_H(ctx->r19, 0X16);
L_80015B58:
    // 0x80015B58: beq         $v1, $zero, L_80015B94
    if (ctx->r3 == 0) {
        // 0x80015B5C: negu        $at, $s4
        ctx->r1 = SUB32(0, ctx->r20);
            goto L_80015B94;
    }
    // 0x80015B5C: negu        $at, $s4
    ctx->r1 = SUB32(0, ctx->r20);
    // 0x80015B60: sll         $a1, $at, 2
    ctx->r5 = S32(ctx->r1 << 2);
    // 0x80015B64: addu        $a1, $a1, $at
    ctx->r5 = ADD32(ctx->r5, ctx->r1);
    // 0x80015B68: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x80015B6C: subu        $a1, $a1, $at
    ctx->r5 = SUB32(ctx->r5, ctx->r1);
    // 0x80015B70: addiu       $a1, $a1, 0x3E
    ctx->r5 = ADD32(ctx->r5, 0X3E);
    // 0x80015B74: sll         $t5, $a1, 16
    ctx->r13 = S32(ctx->r5 << 16);
    // 0x80015B78: lw          $a2, 0x4($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X4);
    // 0x80015B7C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80015B80: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80015B84: sra         $a1, $t5, 16
    ctx->r5 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80015B88: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    // 0x80015B8C: jal         0x80014F00
    // 0x80015B90: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_80014F00(rdram, ctx);
        goto after_56;
    // 0x80015B90: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_56:
L_80015B94:
    // 0x80015B94: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80015B98: slti        $at, $s4, 0x7
    ctx->r1 = SIGNED(ctx->r20) < 0X7 ? 1 : 0;
    // 0x80015B9C: bne         $at, $zero, L_800156F8
    if (ctx->r1 != 0) {
        // 0x80015BA0: addiu       $s3, $s3, 0x24
        ctx->r19 = ADD32(ctx->r19, 0X24);
            goto L_800156F8;
    }
    // 0x80015BA0: addiu       $s3, $s3, 0x24
    ctx->r19 = ADD32(ctx->r19, 0X24);
    // 0x80015BA4: lh          $v0, 0x100($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X100);
    // 0x80015BA8: sltiu       $at, $v0, 0x7
    ctx->r1 = ctx->r2 < 0X7 ? 1 : 0;
    // 0x80015BAC: beq         $at, $zero, L_80015E2C
    if (ctx->r1 == 0) {
        // 0x80015BB0: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_80015E2C;
    }
    // 0x80015BB0: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80015BB4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80015BB8: addu        $at, $at, $t7
    gpr jr_addend_80015BC0 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80015BBC: lw          $t7, 0x6238($at)
    ctx->r15 = ADD32(ctx->r1, 0X6238);
    // 0x80015BC0: jr          $t7
    // 0x80015BC4: nop

    switch (jr_addend_80015BC0 >> 2) {
        case 0: goto L_80015BC8; break;
        case 1: goto L_80015BD4; break;
        case 2: goto L_80015BF8; break;
        case 3: goto L_80015C14; break;
        case 4: goto L_80015C34; break;
        case 5: goto L_80015CB0; break;
        case 6: goto L_80015DE0; break;
        default: switch_error(__func__, 0x80015BC0, 0x80076238);
    }
    // 0x80015BC4: nop

L_80015BC8:
    // 0x80015BC8: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x80015BCC: sh          $t8, 0xFE($sp)
    MEM_H(0XFE, ctx->r29) = ctx->r24;
    // 0x80015BD0: sh          $fp, 0x100($sp)
    MEM_H(0X100, ctx->r29) = ctx->r30;
L_80015BD4:
    // 0x80015BD4: lh          $t9, 0xFE($sp)
    ctx->r25 = MEM_H(ctx->r29, 0XFE);
    // 0x80015BD8: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80015BDC: beq         $t9, $zero, L_80015BEC
    if (ctx->r25 == 0) {
        // 0x80015BE0: addiu       $t3, $t9, -0x1
        ctx->r11 = ADD32(ctx->r25, -0X1);
            goto L_80015BEC;
    }
    // 0x80015BE0: addiu       $t3, $t9, -0x1
    ctx->r11 = ADD32(ctx->r25, -0X1);
    // 0x80015BE4: b           L_80015E2C
    // 0x80015BE8: sh          $t3, 0xFE($sp)
    MEM_H(0XFE, ctx->r29) = ctx->r11;
        goto L_80015E2C;
    // 0x80015BE8: sh          $t3, 0xFE($sp)
    MEM_H(0XFE, ctx->r29) = ctx->r11;
L_80015BEC:
    // 0x80015BEC: sh          $fp, 0x11E($sp)
    MEM_H(0X11E, ctx->r29) = ctx->r30;
    // 0x80015BF0: b           L_80015E2C
    // 0x80015BF4: sh          $t4, 0x100($sp)
    MEM_H(0X100, ctx->r29) = ctx->r12;
        goto L_80015E2C;
    // 0x80015BF4: sh          $t4, 0x100($sp)
    MEM_H(0X100, ctx->r29) = ctx->r12;
L_80015BF8:
    // 0x80015BF8: lh          $t5, 0x1F6($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X1F6);
    // 0x80015BFC: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x80015C00: bne         $s7, $t5, L_80015E2C
    if (ctx->r23 != ctx->r13) {
        // 0x80015C04: nop
    
            goto L_80015E2C;
    }
    // 0x80015C04: nop

    // 0x80015C08: sh          $t6, 0xFE($sp)
    MEM_H(0XFE, ctx->r29) = ctx->r14;
    // 0x80015C0C: b           L_80015E2C
    // 0x80015C10: sh          $s7, 0x100($sp)
    MEM_H(0X100, ctx->r29) = ctx->r23;
        goto L_80015E2C;
    // 0x80015C10: sh          $s7, 0x100($sp)
    MEM_H(0X100, ctx->r29) = ctx->r23;
L_80015C14:
    // 0x80015C14: lh          $t7, 0xFE($sp)
    ctx->r15 = MEM_H(ctx->r29, 0XFE);
    // 0x80015C18: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80015C1C: beq         $t7, $zero, L_80015C2C
    if (ctx->r15 == 0) {
        // 0x80015C20: addiu       $t8, $t7, -0x1
        ctx->r24 = ADD32(ctx->r15, -0X1);
            goto L_80015C2C;
    }
    // 0x80015C20: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80015C24: b           L_80015E2C
    // 0x80015C28: sh          $t8, 0xFE($sp)
    MEM_H(0XFE, ctx->r29) = ctx->r24;
        goto L_80015E2C;
    // 0x80015C28: sh          $t8, 0xFE($sp)
    MEM_H(0XFE, ctx->r29) = ctx->r24;
L_80015C2C:
    // 0x80015C2C: b           L_80015E2C
    // 0x80015C30: sh          $t9, 0x100($sp)
    MEM_H(0X100, ctx->r29) = ctx->r25;
        goto L_80015E2C;
    // 0x80015C30: sh          $t9, 0x100($sp)
    MEM_H(0X100, ctx->r29) = ctx->r25;
L_80015C34:
    // 0x80015C34: lw          $v1, 0x1E4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1E4);
    // 0x80015C38: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x80015C3C: sw          $zero, 0x1E8($sp)
    MEM_W(0X1E8, ctx->r29) = 0;
    // 0x80015C40: div         $zero, $v1, $v0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r2)));
    // 0x80015C44: mflo        $a0
    ctx->r4 = lo;
    // 0x80015C48: sw          $a0, 0x1EC($sp)
    MEM_W(0X1EC, ctx->r29) = ctx->r4;
    // 0x80015C4C: bne         $v0, $zero, L_80015C58
    if (ctx->r2 != 0) {
        // 0x80015C50: nop
    
            goto L_80015C58;
    }
    // 0x80015C50: nop

    // 0x80015C54: break       7
    do_break(2147572820);
L_80015C58:
    // 0x80015C58: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80015C5C: bne         $v0, $at, L_80015C70
    if (ctx->r2 != ctx->r1) {
        // 0x80015C60: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80015C70;
    }
    // 0x80015C60: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80015C64: bne         $v1, $at, L_80015C70
    if (ctx->r3 != ctx->r1) {
        // 0x80015C68: nop
    
            goto L_80015C70;
    }
    // 0x80015C68: nop

    // 0x80015C6C: break       6
    do_break(2147572844);
L_80015C70:
    // 0x80015C70: multu       $v0, $a0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80015C74: sh          $v0, 0x1F4($sp)
    MEM_H(0X1F4, ctx->r29) = ctx->r2;
    // 0x80015C78: addiu       $a0, $zero, -0x4
    ctx->r4 = ADD32(0, -0X4);
    // 0x80015C7C: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x80015C80: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80015C84: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x80015C88: mflo        $t3
    ctx->r11 = lo;
    // 0x80015C8C: subu        $a1, $v1, $t3
    ctx->r5 = SUB32(ctx->r3, ctx->r11);
    // 0x80015C90: beq         $v1, $zero, L_80015CA8
    if (ctx->r3 == 0) {
        // 0x80015C94: sw          $a1, 0x1F0($sp)
        MEM_W(0X1F0, ctx->r29) = ctx->r5;
            goto L_80015CA8;
    }
    // 0x80015C94: sw          $a1, 0x1F0($sp)
    MEM_W(0X1F0, ctx->r29) = ctx->r5;
    // 0x80015C98: jal         0x80044480
    // 0x80015C9C: sh          $t4, 0x100($sp)
    MEM_H(0X100, ctx->r29) = ctx->r12;
    func_80044480(rdram, ctx);
        goto after_57;
    // 0x80015C9C: sh          $t4, 0x100($sp)
    MEM_H(0X100, ctx->r29) = ctx->r12;
    after_57:
    // 0x80015CA0: b           L_80015E2C
    // 0x80015CA4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
        goto L_80015E2C;
    // 0x80015CA4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_80015CA8:
    // 0x80015CA8: b           L_80015E2C
    // 0x80015CAC: sh          $t5, 0x100($sp)
    MEM_H(0X100, ctx->r29) = ctx->r13;
        goto L_80015E2C;
    // 0x80015CAC: sh          $t5, 0x100($sp)
    MEM_H(0X100, ctx->r29) = ctx->r13;
L_80015CB0:
    // 0x80015CB0: lw          $a1, 0x1F0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1F0);
    // 0x80015CB4: lw          $v1, 0x1E4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1E4);
    // 0x80015CB8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80015CBC: beq         $a1, $zero, L_80015CE0
    if (ctx->r5 == 0) {
        // 0x80015CC0: subu        $v1, $v1, $a1
        ctx->r3 = SUB32(ctx->r3, ctx->r5);
            goto L_80015CE0;
    }
    // 0x80015CC0: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x80015CC4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80015CC8: lw          $t6, -0x6BD4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6BD4);
    // 0x80015CCC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80015CD0: sw          $v1, 0x1E4($sp)
    MEM_W(0X1E4, ctx->r29) = ctx->r3;
    // 0x80015CD4: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x80015CD8: sw          $t7, -0x6BD4($at)
    MEM_W(-0X6BD4, ctx->r1) = ctx->r15;
    // 0x80015CDC: sw          $zero, 0x1F0($sp)
    MEM_W(0X1F0, ctx->r29) = 0;
L_80015CE0:
    // 0x80015CE0: lh          $v0, 0x1F4($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X1F4);
    // 0x80015CE4: lw          $a0, 0x1EC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1EC);
    // 0x80015CE8: lw          $v1, 0x1E4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1E4);
    // 0x80015CEC: lw          $t8, -0x6BD4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6BD4);
    // 0x80015CF0: lw          $t5, 0x1E8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1E8);
    // 0x80015CF4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80015CF8: sll         $t3, $v0, 16
    ctx->r11 = S32(ctx->r2 << 16);
    // 0x80015CFC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80015D00: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80015D04: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x80015D08: addu        $t9, $t8, $a0
    ctx->r25 = ADD32(ctx->r24, ctx->r4);
    // 0x80015D0C: sw          $t9, -0x6BD4($at)
    MEM_W(-0X6BD4, ctx->r1) = ctx->r25;
    // 0x80015D10: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x80015D14: bne         $t5, $v1, L_80015D30
    if (ctx->r13 != ctx->r3) {
        // 0x80015D18: sw          $v1, 0x1E4($sp)
        MEM_W(0X1E4, ctx->r29) = ctx->r3;
            goto L_80015D30;
    }
    // 0x80015D18: sw          $v1, 0x1E4($sp)
    MEM_W(0X1E4, ctx->r29) = ctx->r3;
    // 0x80015D1C: beq         $s2, $zero, L_80015D2C
    if (ctx->r18 == 0) {
        // 0x80015D20: sh          $t4, 0x1F4($sp)
        MEM_H(0X1F4, ctx->r29) = ctx->r12;
            goto L_80015D2C;
    }
    // 0x80015D20: sh          $t4, 0x1F4($sp)
    MEM_H(0X1F4, ctx->r29) = ctx->r12;
    // 0x80015D24: jal         0x80008320
    // 0x80015D28: andi        $a0, $s2, 0xFFFF
    ctx->r4 = ctx->r18 & 0XFFFF;
    func_80008320(rdram, ctx);
        goto after_58;
    // 0x80015D28: andi        $a0, $s2, 0xFFFF
    ctx->r4 = ctx->r18 & 0XFFFF;
    after_58:
L_80015D2C:
    // 0x80015D2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80015D30:
    // 0x80015D30: bne         $v0, $zero, L_80015E2C
    if (ctx->r2 != 0) {
        // 0x80015D34: sh          $v0, 0x1F4($sp)
        MEM_H(0X1F4, ctx->r29) = ctx->r2;
            goto L_80015E2C;
    }
    // 0x80015D34: sh          $v0, 0x1F4($sp)
    MEM_H(0X1F4, ctx->r29) = ctx->r2;
    // 0x80015D38: bgez        $s1, L_80015D50
    if (SIGNED(ctx->r17) >= 0) {
        // 0x80015D3C: ori         $at, $zero, 0xC350
        ctx->r1 = 0 | 0XC350;
            goto L_80015D50;
    }
    // 0x80015D3C: ori         $at, $zero, 0xC350
    ctx->r1 = 0 | 0XC350;
    // 0x80015D40: addiu       $t6, $zero, 0x3F
    ctx->r14 = ADD32(0, 0X3F);
    // 0x80015D44: sh          $t6, 0xF4($sp)
    MEM_H(0XF4, ctx->r29) = ctx->r14;
    // 0x80015D48: b           L_80015DA8
    // 0x80015D4C: sh          $fp, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r30;
        goto L_80015DA8;
    // 0x80015D4C: sh          $fp, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r30;
L_80015D50:
    // 0x80015D50: slt         $at, $s1, $at
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80015D54: beq         $at, $zero, L_80015D68
    if (ctx->r1 == 0) {
        // 0x80015D58: addiu       $t7, $zero, 0x43
        ctx->r15 = ADD32(0, 0X43);
            goto L_80015D68;
    }
    // 0x80015D58: addiu       $t7, $zero, 0x43
    ctx->r15 = ADD32(0, 0X43);
    // 0x80015D5C: sh          $t7, 0xF4($sp)
    MEM_H(0XF4, ctx->r29) = ctx->r15;
    // 0x80015D60: b           L_80015DA8
    // 0x80015D64: sh          $fp, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r30;
        goto L_80015DA8;
    // 0x80015D64: sh          $fp, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r30;
L_80015D68:
    // 0x80015D68: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x80015D6C: ori         $at, $at, 0x49F0
    ctx->r1 = ctx->r1 | 0X49F0;
    // 0x80015D70: slt         $at, $s1, $at
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80015D74: beq         $at, $zero, L_80015D8C
    if (ctx->r1 == 0) {
        // 0x80015D78: addiu       $t8, $zero, 0x40
        ctx->r24 = ADD32(0, 0X40);
            goto L_80015D8C;
    }
    // 0x80015D78: addiu       $t8, $zero, 0x40
    ctx->r24 = ADD32(0, 0X40);
    // 0x80015D7C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80015D80: sh          $t8, 0xF4($sp)
    MEM_H(0XF4, ctx->r29) = ctx->r24;
    // 0x80015D84: b           L_80015DA8
    // 0x80015D88: sh          $t9, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r25;
        goto L_80015DA8;
    // 0x80015D88: sh          $t9, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r25;
L_80015D8C:
    // 0x80015D8C: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x80015D90: ori         $at, $at, 0x49F0
    ctx->r1 = ctx->r1 | 0X49F0;
    // 0x80015D94: slt         $at, $s1, $at
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80015D98: bne         $at, $zero, L_80015DA8
    if (ctx->r1 != 0) {
        // 0x80015D9C: addiu       $t3, $zero, 0x41
        ctx->r11 = ADD32(0, 0X41);
            goto L_80015DA8;
    }
    // 0x80015D9C: addiu       $t3, $zero, 0x41
    ctx->r11 = ADD32(0, 0X41);
    // 0x80015DA0: sh          $t3, 0xF4($sp)
    MEM_H(0XF4, ctx->r29) = ctx->r11;
    // 0x80015DA4: sh          $s7, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r23;
L_80015DA8:
    // 0x80015DA8: jal         0x80044480
    // 0x80015DAC: lh          $a0, 0xF4($sp)
    ctx->r4 = MEM_H(ctx->r29, 0XF4);
    func_80044480(rdram, ctx);
        goto after_59;
    // 0x80015DAC: lh          $a0, 0xF4($sp)
    ctx->r4 = MEM_H(ctx->r29, 0XF4);
    after_59:
    // 0x80015DB0: lw          $t4, 0x214($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X214);
    // 0x80015DB4: beql        $t4, $zero, L_80015DD0
    if (ctx->r12 == 0) {
        // 0x80015DB8: addiu       $t6, $zero, 0x5A
        ctx->r14 = ADD32(0, 0X5A);
            goto L_80015DD0;
    }
    goto skip_4;
    // 0x80015DB8: addiu       $t6, $zero, 0x5A
    ctx->r14 = ADD32(0, 0X5A);
    skip_4:
    // 0x80015DBC: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x80015DC0: lh          $a1, 0x62($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X62);
    // 0x80015DC4: jal         0x8004D62C
    // 0x80015DC8: lw          $a0, 0xE0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0XE0);
    func_8004D62C(rdram, ctx);
        goto after_60;
    // 0x80015DC8: lw          $a0, 0xE0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0XE0);
    after_60:
    // 0x80015DCC: addiu       $t6, $zero, 0x5A
    ctx->r14 = ADD32(0, 0X5A);
L_80015DD0:
    // 0x80015DD0: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x80015DD4: sh          $t6, 0xFE($sp)
    MEM_H(0XFE, ctx->r29) = ctx->r14;
    // 0x80015DD8: b           L_80015E2C
    // 0x80015DDC: sh          $t7, 0x100($sp)
    MEM_H(0X100, ctx->r29) = ctx->r15;
        goto L_80015E2C;
    // 0x80015DDC: sh          $t7, 0x100($sp)
    MEM_H(0X100, ctx->r29) = ctx->r15;
L_80015DE0:
    // 0x80015DE0: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x80015DE4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80015DE8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80015DEC: bne         $t8, $at, L_80015E2C
    if (ctx->r24 != ctx->r1) {
        // 0x80015DF0: nop
    
            goto L_80015E2C;
    }
    // 0x80015DF0: nop

    // 0x80015DF4: lhu         $t9, -0x2E5A($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X2E5A);
    // 0x80015DF8: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x80015DFC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80015E00: andi        $t3, $t9, 0x9000
    ctx->r11 = ctx->r25 & 0X9000;
    // 0x80015E04: beq         $t3, $zero, L_80015E2C
    if (ctx->r11 == 0) {
        // 0x80015E08: nop
    
            goto L_80015E2C;
    }
    // 0x80015E08: nop

    // 0x80015E0C: jal         0x80044480
    // 0x80015E10: sh          $t4, 0xF6($sp)
    MEM_H(0XF6, ctx->r29) = ctx->r12;
    func_80044480(rdram, ctx);
        goto after_61;
    // 0x80015E10: sh          $t4, 0xF6($sp)
    MEM_H(0XF6, ctx->r29) = ctx->r12;
    after_61:
    // 0x80015E14: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80015E18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80015E1C: jal         0x8004D134
    // 0x80015E20: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_8004D134(rdram, ctx);
        goto after_62;
    // 0x80015E20: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_62:
    // 0x80015E24: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80015E28: sw          $t5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r13;
L_80015E2C:
    // 0x80015E2C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80015E30: lw          $a2, -0x6BD4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X6BD4);
    // 0x80015E34: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    // 0x80015E38: addiu       $a1, $zero, -0x5C
    ctx->r5 = ADD32(0, -0X5C);
    // 0x80015E3C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x80015E40: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80015E44: jal         0x80014F00
    // 0x80015E48: sw          $fp, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r30;
    func_80014F00(rdram, ctx);
        goto after_63;
    // 0x80015E48: sw          $fp, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r30;
    after_63:
    // 0x80015E4C: jal         0x8000798C
    // 0x80015E50: nop

    func_8000798C(rdram, ctx);
        goto after_64;
    // 0x80015E50: nop

    after_64:
    // 0x80015E54: b           L_80015660
    // 0x80015E58: lh          $t9, 0xF6($sp)
    ctx->r25 = MEM_H(ctx->r29, 0XF6);
        goto L_80015660;
    // 0x80015E58: lh          $t9, 0xF6($sp)
    ctx->r25 = MEM_H(ctx->r29, 0XF6);
    // 0x80015E5C: nop

    // 0x80015E60: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80015E64: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80015E68: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80015E6C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80015E70: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80015E74: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80015E78: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80015E7C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80015E80: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80015E84: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80015E88: jr          $ra
    // 0x80015E8C: addiu       $sp, $sp, 0x230
    ctx->r29 = ADD32(ctx->r29, 0X230);
    TRACE_RETURN()
    return;
    // 0x80015E8C: addiu       $sp, $sp, 0x230
    ctx->r29 = ADD32(ctx->r29, 0X230);
;}
RECOMP_FUNC void func_80015E90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80015E90: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80015E94: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80015E98: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80015E9C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80015EA0: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x80015EA4: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x80015EA8: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x80015EAC: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80015EB0: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80015EB4: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80015EB8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80015EBC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80015EC0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80015EC4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80015EC8: jal         0x800499B0
    // 0x80015ECC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800499B0(rdram, ctx);
        goto after_0;
    // 0x80015ECC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80015ED0: jal         0x8004B1E0
    // 0x80015ED4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8004B1E0(rdram, ctx);
        goto after_1;
    // 0x80015ED4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_1:
    // 0x80015ED8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80015EDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80015EE0: jal         0x8000BD4C
    // 0x80015EE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BD4C(rdram, ctx);
        goto after_2;
    // 0x80015EE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80015EE8: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80015EEC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80015EF0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80015EF4: sh          $zero, -0x2CC4($at)
    MEM_H(-0X2CC4, ctx->r1) = 0;
    // 0x80015EF8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80015EFC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80015F00: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80015F04: lui         $at, 0x433E
    ctx->r1 = S32(0X433E << 16);
    // 0x80015F08: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80015F0C: addiu       $v1, $v1, -0x6C40
    ctx->r3 = ADD32(ctx->r3, -0X6C40);
    // 0x80015F10: addiu       $v0, $v0, -0x6C50
    ctx->r2 = ADD32(ctx->r2, -0X6C50);
    // 0x80015F14: swc1        $f2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f2.u32l;
    // 0x80015F18: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    // 0x80015F1C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80015F20: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x80015F24: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x80015F28: jal         0x8000798C
    // 0x80015F2C: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    func_8000798C(rdram, ctx);
        goto after_3;
    // 0x80015F2C: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    after_3:
    // 0x80015F30: jal         0x8000798C
    // 0x80015F34: nop

    func_8000798C(rdram, ctx);
        goto after_4;
    // 0x80015F34: nop

    after_4:
    // 0x80015F38: jal         0x8000798C
    // 0x80015F3C: nop

    func_8000798C(rdram, ctx);
        goto after_5;
    // 0x80015F3C: nop

    after_5:
    // 0x80015F40: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80015F44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80015F48: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x80015F4C: sh          $zero, -0x6B94($at)
    MEM_H(-0X6B94, ctx->r1) = 0;
    // 0x80015F50: addiu       $a0, $a0, -0x2E00
    ctx->r4 = ADD32(ctx->r4, -0X2E00);
    // 0x80015F54: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
    // 0x80015F58: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    // 0x80015F5C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80015F60: jal         0x80004CE0
    // 0x80015F64: addiu       $a3, $sp, 0x8C
    ctx->r7 = ADD32(ctx->r29, 0X8C);
    func_80004CE0(rdram, ctx);
        goto after_6;
    // 0x80015F64: addiu       $a3, $sp, 0x8C
    ctx->r7 = ADD32(ctx->r29, 0X8C);
    after_6:
    // 0x80015F68: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80015F6C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80015F70: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    // 0x80015F74: addiu       $a0, $a0, 0x4020
    ctx->r4 = ADD32(ctx->r4, 0X4020);
    // 0x80015F78: sw          $v1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r3;
    // 0x80015F7C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80015F80: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80015F84: jal         0x80004CE0
    // 0x80015F88: addiu       $a3, $sp, 0x84
    ctx->r7 = ADD32(ctx->r29, 0X84);
    func_80004CE0(rdram, ctx);
        goto after_7;
    // 0x80015F88: addiu       $a3, $sp, 0x84
    ctx->r7 = ADD32(ctx->r29, 0X84);
    after_7:
    // 0x80015F8C: jal         0x8000798C
    // 0x80015F90: sw          $v0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r2;
    func_8000798C(rdram, ctx);
        goto after_8;
    // 0x80015F90: sw          $v0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r2;
    after_8:
    // 0x80015F94: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80015F98: jal         0x80049CFC
    // 0x80015F9C: addiu       $a0, $a0, 0x6260
    ctx->r4 = ADD32(ctx->r4, 0X6260);
    func_80049CFC(rdram, ctx);
        goto after_9;
    // 0x80015F9C: addiu       $a0, $a0, 0x6260
    ctx->r4 = ADD32(ctx->r4, 0X6260);
    after_9:
    // 0x80015FA0: jal         0x80049D80
    // 0x80015FA4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80049D80(rdram, ctx);
        goto after_10;
    // 0x80015FA4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_10:
    // 0x80015FA8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80015FAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80015FB0: jal         0x80049DFC
    // 0x80015FB4: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    func_80049DFC(rdram, ctx);
        goto after_11;
    // 0x80015FB4: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    after_11:
    // 0x80015FB8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80015FBC: jal         0x8004A148
    // 0x80015FC0: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    func_8004A148(rdram, ctx);
        goto after_12;
    // 0x80015FC0: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    after_12:
    // 0x80015FC4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80015FC8: lwc1        $f0, 0x6270($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6270);
    // 0x80015FCC: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x80015FD0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80015FD4: lw          $a0, 0x8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X8);
    // 0x80015FD8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80015FDC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80015FE0: jal         0x80001AB4
    // 0x80015FE4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80001AB4(rdram, ctx);
        goto after_13;
    // 0x80015FE4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_13:
    // 0x80015FE8: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x80015FEC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80015FF0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80015FF4: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x80015FF8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80015FFC: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80016000: swc1        $f0, 0x40($t8)
    MEM_W(0X40, ctx->r24) = ctx->f0.u32l;
    // 0x80016004: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80016008: addiu       $a0, $a0, 0x6268
    ctx->r4 = ADD32(ctx->r4, 0X6268);
    // 0x8001600C: swc1        $f6, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->f6.u32l;
    // 0x80016010: lw          $t0, 0x8($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X8);
    // 0x80016014: swc1        $f0, 0x48($t0)
    MEM_W(0X48, ctx->r8) = ctx->f0.u32l;
    // 0x80016018: lw          $t1, 0x8($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X8);
    // 0x8001601C: lw          $v0, 0xE0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0XE0);
    // 0x80016020: lbu         $t2, 0x10($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X10);
    // 0x80016024: ori         $t3, $t2, 0x4
    ctx->r11 = ctx->r10 | 0X4;
    // 0x80016028: jal         0x80049CFC
    // 0x8001602C: sb          $t3, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r11;
    func_80049CFC(rdram, ctx);
        goto after_14;
    // 0x8001602C: sb          $t3, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r11;
    after_14:
    // 0x80016030: jal         0x80049D80
    // 0x80016034: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80049D80(rdram, ctx);
        goto after_15;
    // 0x80016034: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_15:
    // 0x80016038: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001603C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80016040: jal         0x80049DFC
    // 0x80016044: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    func_80049DFC(rdram, ctx);
        goto after_16;
    // 0x80016044: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    after_16:
    // 0x80016048: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001604C: jal         0x8004A148
    // 0x80016050: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    func_8004A148(rdram, ctx);
        goto after_17;
    // 0x80016050: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    after_17:
    // 0x80016054: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80016058: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001605C: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x80016060: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80016064: lw          $a0, 0x8($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X8);
    // 0x80016068: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8001606C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80016070: jal         0x80001AB4
    // 0x80016074: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80001AB4(rdram, ctx);
        goto after_18;
    // 0x80016074: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_18:
    // 0x80016078: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x8001607C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80016080: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80016084: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x80016088: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8001608C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80016090: swc1        $f8, 0x40($t6)
    MEM_W(0X40, ctx->r14) = ctx->f8.u32l;
    // 0x80016094: lw          $t8, 0x8($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X8);
    // 0x80016098: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001609C: addiu       $a1, $zero, -0x4B
    ctx->r5 = ADD32(0, -0X4B);
    // 0x800160A0: swc1        $f10, 0x44($t8)
    MEM_W(0X44, ctx->r24) = ctx->f10.u32l;
    // 0x800160A4: lw          $t9, 0x8($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X8);
    // 0x800160A8: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x800160AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800160B0: swc1        $f16, 0x48($t9)
    MEM_W(0X48, ctx->r25) = ctx->f16.u32l;
    // 0x800160B4: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x800160B8: lw          $v0, 0x8($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X8);
    // 0x800160BC: lw          $t7, 0xD8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XD8);
    // 0x800160C0: ori         $t1, $t7, 0x8001
    ctx->r9 = ctx->r15 | 0X8001;
    // 0x800160C4: sw          $t1, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r9;
    // 0x800160C8: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x800160CC: lw          $v1, 0x8($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X8);
    // 0x800160D0: lw          $t3, 0xD8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XD8);
    // 0x800160D4: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x800160D8: sw          $t4, 0xD8($v1)
    MEM_W(0XD8, ctx->r3) = ctx->r12;
    // 0x800160DC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800160E0: jal         0x8004C580
    // 0x800160E4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_19;
    // 0x800160E4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_19:
    // 0x800160E8: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800160EC: lh          $a3, -0x662C($a3)
    ctx->r7 = MEM_H(ctx->r7, -0X662C);
    // 0x800160F0: addiu       $a0, $zero, -0xA
    ctx->r4 = ADD32(0, -0XA);
    // 0x800160F4: addiu       $a1, $zero, -0x2A
    ctx->r5 = ADD32(0, -0X2A);
    // 0x800160F8: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x800160FC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80016100: jal         0x8004C580
    // 0x80016104: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_20;
    // 0x80016104: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_20:
    // 0x80016108: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x8001610C: lh          $a3, -0x662C($a3)
    ctx->r7 = MEM_H(ctx->r7, -0X662C);
    // 0x80016110: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    // 0x80016114: addiu       $a1, $zero, -0x29
    ctx->r5 = ADD32(0, -0X29);
    // 0x80016118: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8001611C: sll         $t6, $a3, 16
    ctx->r14 = S32(ctx->r7 << 16);
    // 0x80016120: sra         $a3, $t6, 16
    ctx->r7 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80016124: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x80016128: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001612C: jal         0x8004C580
    // 0x80016130: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_21;
    // 0x80016130: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_21:
    // 0x80016134: addiu       $v1, $zero, 0x190
    ctx->r3 = ADD32(0, 0X190);
    // 0x80016138: addiu       $s7, $zero, 0x3
    ctx->r23 = ADD32(0, 0X3);
    // 0x8001613C: div         $zero, $v1, $s7
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r23))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r23)));
    // 0x80016140: mflo        $s6
    ctx->r22 = lo;
    // 0x80016144: sll         $t0, $s6, 16
    ctx->r8 = S32(ctx->r22 << 16);
    // 0x80016148: sra         $t7, $t0, 16
    ctx->r15 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8001614C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80016150: addiu       $t5, $zero, 0x3C
    ctx->r13 = ADD32(0, 0X3C);
    // 0x80016154: addiu       $t9, $zero, 0x96
    ctx->r25 = ADD32(0, 0X96);
    // 0x80016158: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8001615C: sh          $t5, 0x66($sp)
    MEM_H(0X66, ctx->r29) = ctx->r13;
    // 0x80016160: sh          $t9, 0x68($sp)
    MEM_H(0X68, ctx->r29) = ctx->r25;
    // 0x80016164: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80016168: bne         $s7, $zero, L_80016174
    if (ctx->r23 != 0) {
        // 0x8001616C: nop
    
            goto L_80016174;
    }
    // 0x8001616C: nop

    // 0x80016170: break       7
    do_break(2147574128);
L_80016174:
    // 0x80016174: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80016178: bne         $s7, $at, L_8001618C
    if (ctx->r23 != ctx->r1) {
        // 0x8001617C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001618C;
    }
    // 0x8001617C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80016180: bne         $v1, $at, L_8001618C
    if (ctx->r3 != ctx->r1) {
        // 0x80016184: nop
    
            goto L_8001618C;
    }
    // 0x80016184: nop

    // 0x80016188: break       6
    do_break(2147574152);
L_8001618C:
    // 0x8001618C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80016190: or          $s6, $t7, $zero
    ctx->r22 = ctx->r15 | 0;
    // 0x80016194: sh          $t7, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r15;
    // 0x80016198: sh          $s1, -0x6B94($at)
    MEM_H(-0X6B94, ctx->r1) = ctx->r17;
    // 0x8001619C: sh          $v1, 0x64($sp)
    MEM_H(0X64, ctx->r29) = ctx->r3;
    // 0x800161A0: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
L_800161A4:
    // 0x800161A4: beq         $s0, $zero, L_800161CC
    if (ctx->r16 == 0) {
        // 0x800161A8: addiu       $a0, $zero, 0xF
        ctx->r4 = ADD32(0, 0XF);
            goto L_800161CC;
    }
    // 0x800161A8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x800161AC: beq         $s0, $s1, L_800161E8
    if (ctx->r16 == ctx->r17) {
        // 0x800161B0: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800161E8;
    }
    // 0x800161B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800161B4: beq         $s0, $s2, L_80016208
    if (ctx->r16 == ctx->r18) {
        // 0x800161B8: addiu       $a2, $zero, 0xFF
        ctx->r6 = ADD32(0, 0XFF);
            goto L_80016208;
    }
    // 0x800161B8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800161BC: beq         $s0, $s7, L_8001624C
    if (ctx->r16 == ctx->r23) {
        // 0x800161C0: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_8001624C;
    }
    // 0x800161C0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800161C4: b           L_80016328
    // 0x800161C8: nop

        goto L_80016328;
    // 0x800161C8: nop

L_800161CC:
    // 0x800161CC: addiu       $a0, $zero, -0x5
    ctx->r4 = ADD32(0, -0X5);
    // 0x800161D0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800161D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800161D8: jal         0x8004D134
    // 0x800161DC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    func_8004D134(rdram, ctx);
        goto after_22;
    // 0x800161DC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    after_22:
    // 0x800161E0: b           L_80016328
    // 0x800161E4: nop

        goto L_80016328;
    // 0x800161E4: nop

L_800161E8:
    // 0x800161E8: jal         0x8004D1F0
    // 0x800161EC: nop

    func_8004D1F0(rdram, ctx);
        goto after_23;
    // 0x800161EC: nop

    after_23:
    // 0x800161F0: bne         $v0, $zero, L_80016328
    if (ctx->r2 != 0) {
        // 0x800161F4: nop
    
            goto L_80016328;
    }
    // 0x800161F4: nop

    // 0x800161F8: sll         $s0, $s2, 16
    ctx->r16 = S32(ctx->r18 << 16);
    // 0x800161FC: sra         $t1, $s0, 16
    ctx->r9 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80016200: b           L_80016328
    // 0x80016204: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
        goto L_80016328;
    // 0x80016204: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
L_80016208:
    // 0x80016208: beq         $s3, $zero, L_80016220
    if (ctx->r19 == 0) {
        // 0x8001620C: nop
    
            goto L_80016220;
    }
    // 0x8001620C: nop

    // 0x80016210: jal         0x8004D134
    // 0x80016214: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    func_8004D134(rdram, ctx);
        goto after_24;
    // 0x80016214: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    after_24:
    // 0x80016218: b           L_800161A4
    // 0x8001621C: nop

        goto L_800161A4;
    // 0x8001621C: nop

L_80016220:
    // 0x80016220: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80016224: lhu         $t2, -0x2E5A($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X2E5A);
    // 0x80016228: sll         $t4, $s4, 1
    ctx->r12 = S32(ctx->r20 << 1);
    // 0x8001622C: addu        $t6, $sp, $t4
    ctx->r14 = ADD32(ctx->r29, ctx->r12);
    // 0x80016230: andi        $t3, $t2, 0x1000
    ctx->r11 = ctx->r10 & 0X1000;
    // 0x80016234: beq         $t3, $zero, L_80016328
    if (ctx->r11 == 0) {
        // 0x80016238: addiu       $a0, $zero, 0x12
        ctx->r4 = ADD32(0, 0X12);
            goto L_80016328;
    }
    // 0x80016238: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x8001623C: jal         0x80044480
    // 0x80016240: sh          $zero, 0x64($t6)
    MEM_H(0X64, ctx->r14) = 0;
    func_80044480(rdram, ctx);
        goto after_25;
    // 0x80016240: sh          $zero, 0x64($t6)
    MEM_H(0X64, ctx->r14) = 0;
    after_25:
    // 0x80016244: b           L_80016328
    // 0x80016248: nop

        goto L_80016328;
    // 0x80016248: nop

L_8001624C:
    // 0x8001624C: jal         0x8004D1F0
    // 0x80016250: sh          $zero, -0x6B94($at)
    MEM_H(-0X6B94, ctx->r1) = 0;
    func_8004D1F0(rdram, ctx);
        goto after_26;
    // 0x80016250: sh          $zero, -0x6B94($at)
    MEM_H(-0X6B94, ctx->r1) = 0;
    after_26:
    // 0x80016254: bne         $v0, $zero, L_80016328
    if (ctx->r2 != 0) {
        // 0x80016258: addiu       $v0, $sp, 0x70
        ctx->r2 = ADD32(ctx->r29, 0X70);
            goto L_80016328;
    }
    // 0x80016258: addiu       $v0, $sp, 0x70
    ctx->r2 = ADD32(ctx->r29, 0X70);
    // 0x8001625C: addiu       $s0, $sp, 0x80
    ctx->r16 = ADD32(ctx->r29, 0X80);
    // 0x80016260: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
L_80016264:
    // 0x80016264: jal         0x8004A0C4
    // 0x80016268: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    func_8004A0C4(rdram, ctx);
        goto after_27;
    // 0x80016268: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    after_27:
    // 0x8001626C: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x80016270: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80016274: bnel        $v0, $s0, L_80016264
    if (ctx->r2 != ctx->r16) {
        // 0x80016278: lw          $a0, 0x4($v0)
        ctx->r4 = MEM_W(ctx->r2, 0X4);
            goto L_80016264;
    }
    goto skip_0;
    // 0x80016278: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    skip_0:
    // 0x8001627C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80016280: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80016284: jal         0x8000BD4C
    // 0x80016288: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BD4C(rdram, ctx);
        goto after_28;
    // 0x80016288: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_28:
    // 0x8001628C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80016290: sh          $zero, -0x2CC4($at)
    MEM_H(-0X2CC4, ctx->r1) = 0;
    // 0x80016294: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80016298: jal         0x8004C4D8
    // 0x8001629C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004C4D8(rdram, ctx);
        goto after_29;
    // 0x8001629C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_29:
    // 0x800162A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800162A4: jal         0x8004C4D8
    // 0x800162A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004C4D8(rdram, ctx);
        goto after_30;
    // 0x800162A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_30:
    // 0x800162AC: jal         0x80049C48
    // 0x800162B0: nop

    func_80049C48(rdram, ctx);
        goto after_31;
    // 0x800162B0: nop

    after_31:
    // 0x800162B4: jal         0x8004B21C
    // 0x800162B8: nop

    func_8004B21C(rdram, ctx);
        goto after_32;
    // 0x800162B8: nop

    after_32:
    // 0x800162BC: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800162C0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800162C4: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
    // 0x800162C8: sw          $v1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r3;
    // 0x800162CC: lw          $v0, 0x8C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X8C);
L_800162D0:
    // 0x800162D0: lw          $v1, 0x84($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X84);
    // 0x800162D4: or          $t8, $v0, $v1
    ctx->r24 = ctx->r2 | ctx->r3;
    // 0x800162D8: bne         $t8, $zero, L_800162E8
    if (ctx->r24 != 0) {
        // 0x800162DC: nop
    
            goto L_800162E8;
    }
    // 0x800162DC: nop

    // 0x800162E0: b           L_800162F8
    // 0x800162E4: sh          $s6, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r22;
        goto L_800162F8;
    // 0x800162E4: sh          $s6, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r22;
L_800162E8:
    // 0x800162E8: jal         0x8000798C
    // 0x800162EC: nop

    func_8000798C(rdram, ctx);
        goto after_33;
    // 0x800162EC: nop

    after_33:
    // 0x800162F0: b           L_800162D0
    // 0x800162F4: lw          $v0, 0x8C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X8C);
        goto L_800162D0;
    // 0x800162F4: lw          $v0, 0x8C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X8C);
L_800162F8:
    // 0x800162F8: jal         0x80004E5C
    // 0x800162FC: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    func_80004E5C(rdram, ctx);
        goto after_34;
    // 0x800162FC: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    after_34:
    // 0x80016300: jal         0x80004E5C
    // 0x80016304: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    func_80004E5C(rdram, ctx);
        goto after_35;
    // 0x80016304: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    after_35:
    // 0x80016308: jal         0x8000798C
    // 0x8001630C: nop

    func_8000798C(rdram, ctx);
        goto after_36;
    // 0x8001630C: nop

    after_36:
    // 0x80016310: lw          $t5, 0x90($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X90);
    // 0x80016314: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
L_80016318:
    // 0x80016318: jal         0x8000798C
    // 0x8001631C: nop

    func_8000798C(rdram, ctx);
        goto after_37;
    // 0x8001631C: nop

    after_37:
    // 0x80016320: b           L_80016318
    // 0x80016324: nop

        goto L_80016318;
    // 0x80016324: nop

L_80016328:
    // 0x80016328: bne         $s3, $zero, L_8001643C
    if (ctx->r19 != 0) {
        // 0x8001632C: sll         $t9, $s4, 1
        ctx->r25 = S32(ctx->r20 << 1);
            goto L_8001643C;
    }
    // 0x8001632C: sll         $t9, $s4, 1
    ctx->r25 = S32(ctx->r20 << 1);
    // 0x80016330: addiu       $t0, $sp, 0x64
    ctx->r8 = ADD32(ctx->r29, 0X64);
    // 0x80016334: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x80016338: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
    // 0x8001633C: beq         $v1, $zero, L_8001634C
    if (ctx->r3 == 0) {
        // 0x80016340: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_8001634C;
    }
    // 0x80016340: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x80016344: b           L_8001643C
    // 0x80016348: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
        goto L_8001643C;
    // 0x80016348: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
L_8001634C:
    // 0x8001634C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80016350: sll         $t1, $s4, 16
    ctx->r9 = S32(ctx->r20 << 16);
    // 0x80016354: sra         $t2, $t1, 16
    ctx->r10 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80016358: beq         $t2, $s1, L_80016378
    if (ctx->r10 == ctx->r17) {
        // 0x8001635C: or          $s4, $t2, $zero
        ctx->r20 = ctx->r10 | 0;
            goto L_80016378;
    }
    // 0x8001635C: or          $s4, $t2, $zero
    ctx->r20 = ctx->r10 | 0;
    // 0x80016360: beq         $t2, $s2, L_800163B0
    if (ctx->r10 == ctx->r18) {
        // 0x80016364: lw          $t8, 0x74($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X74);
            goto L_800163B0;
    }
    // 0x80016364: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x80016368: beql        $t2, $s7, L_80016434
    if (ctx->r10 == ctx->r23) {
        // 0x8001636C: sll         $s3, $s1, 16
        ctx->r19 = S32(ctx->r17 << 16);
            goto L_80016434;
    }
    goto skip_1;
    // 0x8001636C: sll         $s3, $s1, 16
    ctx->r19 = S32(ctx->r17 << 16);
    skip_1:
    // 0x80016370: b           L_8001643C
    // 0x80016374: nop

        goto L_8001643C;
    // 0x80016374: nop

L_80016378:
    // 0x80016378: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x8001637C: sll         $a1, $s1, 16
    ctx->r5 = S32(ctx->r17 << 16);
    // 0x80016380: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80016384: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x80016388: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8001638C: jal         0x8004D62C
    // 0x80016390: lw          $a0, 0xE0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0XE0);
    func_8004D62C(rdram, ctx);
        goto after_38;
    // 0x80016390: lw          $a0, 0xE0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0XE0);
    after_38:
    // 0x80016394: jal         0x80044514
    // 0x80016398: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80044514(rdram, ctx);
        goto after_39;
    // 0x80016398: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_39:
    // 0x8001639C: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    // 0x800163A0: jal         0x800443A8
    // 0x800163A4: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    func_800443A8(rdram, ctx);
        goto after_40;
    // 0x800163A4: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    after_40:
    // 0x800163A8: b           L_8001643C
    // 0x800163AC: nop

        goto L_8001643C;
    // 0x800163AC: nop

L_800163B0:
    // 0x800163B0: lw          $t5, 0x8($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X8);
    // 0x800163B4: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x800163B8: sra         $t9, $a1, 16
    ctx->r25 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800163BC: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x800163C0: jal         0x8004D62C
    // 0x800163C4: lw          $a0, 0xE0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0XE0);
    func_8004D62C(rdram, ctx);
        goto after_41;
    // 0x800163C4: lw          $a0, 0xE0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0XE0);
    after_41:
    // 0x800163C8: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x800163CC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800163D0: lw          $t7, 0x8($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X8);
    // 0x800163D4: lw          $v0, 0xE0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0XE0);
    // 0x800163D8: lbu         $t1, 0x10($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X10);
    // 0x800163DC: ori         $t2, $t1, 0x4
    ctx->r10 = ctx->r9 | 0X4;
    // 0x800163E0: jal         0x80044514
    // 0x800163E4: sb          $t2, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r10;
    func_80044514(rdram, ctx);
        goto after_42;
    // 0x800163E4: sb          $t2, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r10;
    after_42:
    // 0x800163E8: jal         0x8000E35C
    // 0x800163EC: nop

    func_8000E35C(rdram, ctx);
        goto after_43;
    // 0x800163EC: nop

    after_43:
    // 0x800163F0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800163F4: lh          $t6, -0x662C($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X662C);
    // 0x800163F8: andi        $a3, $v0, 0x1
    ctx->r7 = ctx->r2 & 0X1;
    // 0x800163FC: addiu       $a3, $a3, 0x32
    ctx->r7 = ADD32(ctx->r7, 0X32);
    // 0x80016400: sll         $t3, $a3, 16
    ctx->r11 = S32(ctx->r7 << 16);
    // 0x80016404: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80016408: bne         $t6, $at, L_80016414
    if (ctx->r14 != ctx->r1) {
        // 0x8001640C: sra         $a3, $t3, 16
        ctx->r7 = S32(SIGNED(ctx->r11) >> 16);
            goto L_80016414;
    }
    // 0x8001640C: sra         $a3, $t3, 16
    ctx->r7 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80016410: addiu       $a3, $zero, 0x33
    ctx->r7 = ADD32(0, 0X33);
L_80016414:
    // 0x80016414: sll         $a0, $a3, 16
    ctx->r4 = S32(ctx->r7 << 16);
    // 0x80016418: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001641C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80016420: jal         0x800443A8
    // 0x80016424: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_800443A8(rdram, ctx);
        goto after_44;
    // 0x80016424: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_44:
    // 0x80016428: b           L_8001643C
    // 0x8001642C: nop

        goto L_8001643C;
    // 0x8001642C: nop

    // 0x80016430: sll         $s3, $s1, 16
    ctx->r19 = S32(ctx->r17 << 16);
L_80016434:
    // 0x80016434: sra         $t5, $s3, 16
    ctx->r13 = S32(SIGNED(ctx->r19) >> 16);
    // 0x80016438: or          $s3, $t5, $zero
    ctx->r19 = ctx->r13 | 0;
L_8001643C:
    // 0x8001643C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80016440: lh          $t9, -0x662C($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X662C);
    // 0x80016444: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80016448: addiu       $a1, $zero, -0x53
    ctx->r5 = ADD32(0, -0X53);
    // 0x8001644C: multu       $t9, $s7
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80016450: addiu       $a2, $zero, -0x100
    ctx->r6 = ADD32(0, -0X100);
    // 0x80016454: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80016458: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8001645C: mflo        $t0
    ctx->r8 = lo;
    // 0x80016460: addu        $a3, $t0, $s5
    ctx->r7 = ADD32(ctx->r8, ctx->r21);
    // 0x80016464: addiu       $a3, $a3, 0xE
    ctx->r7 = ADD32(ctx->r7, 0XE);
    // 0x80016468: sll         $t7, $a3, 16
    ctx->r15 = S32(ctx->r7 << 16);
    // 0x8001646C: jal         0x8004C580
    // 0x80016470: sra         $a3, $t7, 16
    ctx->r7 = S32(SIGNED(ctx->r15) >> 16);
    func_8004C580(rdram, ctx);
        goto after_45;
    // 0x80016470: sra         $a3, $t7, 16
    ctx->r7 = S32(SIGNED(ctx->r15) >> 16);
    after_45:
    // 0x80016474: bne         $s3, $zero, L_800164B0
    if (ctx->r19 != 0) {
        // 0x80016478: nop
    
            goto L_800164B0;
    }
    // 0x80016478: nop

    // 0x8001647C: beq         $s6, $zero, L_80016494
    if (ctx->r22 == 0) {
        // 0x80016480: slti        $at, $s5, 0x2
        ctx->r1 = SIGNED(ctx->r21) < 0X2 ? 1 : 0;
            goto L_80016494;
    }
    // 0x80016480: slti        $at, $s5, 0x2
    ctx->r1 = SIGNED(ctx->r21) < 0X2 ? 1 : 0;
    // 0x80016484: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    // 0x80016488: sll         $t2, $s6, 16
    ctx->r10 = S32(ctx->r22 << 16);
    // 0x8001648C: b           L_800164B0
    // 0x80016490: sra         $s6, $t2, 16
    ctx->r22 = S32(SIGNED(ctx->r10) >> 16);
        goto L_800164B0;
    // 0x80016490: sra         $s6, $t2, 16
    ctx->r22 = S32(SIGNED(ctx->r10) >> 16);
L_80016494:
    // 0x80016494: beq         $at, $zero, L_800164B0
    if (ctx->r1 == 0) {
        // 0x80016498: addiu       $a0, $zero, 0x13
        ctx->r4 = ADD32(0, 0X13);
            goto L_800164B0;
    }
    // 0x80016498: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    // 0x8001649C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800164A0: sll         $t4, $s5, 16
    ctx->r12 = S32(ctx->r21 << 16);
    // 0x800164A4: sra         $s5, $t4, 16
    ctx->r21 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800164A8: jal         0x80044480
    // 0x800164AC: lh          $s6, 0x62($sp)
    ctx->r22 = MEM_H(ctx->r29, 0X62);
    func_80044480(rdram, ctx);
        goto after_46;
    // 0x800164AC: lh          $s6, 0x62($sp)
    ctx->r22 = MEM_H(ctx->r29, 0X62);
    after_46:
L_800164B0:
    // 0x800164B0: jal         0x8000798C
    // 0x800164B4: nop

    func_8000798C(rdram, ctx);
        goto after_47;
    // 0x800164B4: nop

    after_47:
    // 0x800164B8: b           L_800161A4
    // 0x800164BC: nop

        goto L_800161A4;
    // 0x800164BC: nop

    // 0x800164C0: nop

    // 0x800164C4: nop

    // 0x800164C8: nop

    // 0x800164CC: nop

    // 0x800164D0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800164D4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800164D8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800164DC: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800164E0: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800164E4: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x800164E8: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x800164EC: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x800164F0: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x800164F4: jr          $ra
    // 0x800164F8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    TRACE_RETURN()
    return;
    // 0x800164F8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_80016500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80016500: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80016504: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x80016508: lh          $t9, 0x56($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X56);
    // 0x8001650C: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80016510: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80016514: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80016518: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8001651C: sll         $s2, $t7, 16
    ctx->r18 = S32(ctx->r15 << 16);
    // 0x80016520: lui         $s1, 0x8007
    ctx->r17 = S32(0X8007 << 16);
    // 0x80016524: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80016528: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8001652C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80016530: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80016534: sra         $t8, $s2, 16
    ctx->r24 = S32(SIGNED(ctx->r18) >> 16);
    // 0x80016538: addu        $s1, $s1, $t0
    ctx->r17 = ADD32(ctx->r17, ctx->r8);
    // 0x8001653C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80016540: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80016544: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80016548: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8001654C: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80016550: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80016554: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80016558: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8001655C: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
    // 0x80016560: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x80016564: lw          $s1, -0x6730($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X6730);
    // 0x80016568: blez        $t9, L_80016644
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8001656C: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_80016644;
    }
    // 0x8001656C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80016570: addiu       $fp, $zero, 0xA
    ctx->r30 = ADD32(0, 0XA);
    // 0x80016574: ori         $s7, $zero, 0xFF00
    ctx->r23 = 0 | 0XFF00;
    // 0x80016578: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
    // 0x8001657C: lh          $s5, 0x5A($sp)
    ctx->r21 = MEM_H(ctx->r29, 0X5A);
L_80016580:
    // 0x80016580: div         $zero, $s3, $s1
    lo = S32(S64(S32(ctx->r19)) / S64(S32(ctx->r17))); hi = S32(S64(S32(ctx->r19)) % S64(S32(ctx->r17)));
    // 0x80016584: mflo        $v0
    ctx->r2 = lo;
    // 0x80016588: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8001658C: bne         $s1, $zero, L_80016598
    if (ctx->r17 != 0) {
        // 0x80016590: nop
    
            goto L_80016598;
    }
    // 0x80016590: nop

    // 0x80016594: break       7
    do_break(2147575188);
L_80016598:
    // 0x80016598: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001659C: bne         $s1, $at, L_800165B0
    if (ctx->r17 != ctx->r1) {
        // 0x800165A0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800165B0;
    }
    // 0x800165A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800165A4: bne         $s3, $at, L_800165B0
    if (ctx->r19 != ctx->r1) {
        // 0x800165A8: nop
    
            goto L_800165B0;
    }
    // 0x800165A8: nop

    // 0x800165AC: break       6
    do_break(2147575212);
L_800165B0:
    // 0x800165B0: beq         $v0, $s6, L_800165FC
    if (ctx->r2 == ctx->r22) {
        // 0x800165B4: nop
    
            goto L_800165FC;
    }
    // 0x800165B4: nop

    // 0x800165B8: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x800165BC: addu        $a2, $s5, $s7
    ctx->r6 = ADD32(ctx->r21, ctx->r23);
    // 0x800165C0: addiu       $a3, $s0, 0x13
    ctx->r7 = ADD32(ctx->r16, 0X13);
    // 0x800165C4: sll         $t4, $a3, 16
    ctx->r12 = S32(ctx->r7 << 16);
    // 0x800165C8: sll         $t2, $a2, 16
    ctx->r10 = S32(ctx->r6 << 16);
    // 0x800165CC: sra         $t1, $a0, 16
    ctx->r9 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800165D0: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800165D4: sra         $a2, $t2, 16
    ctx->r6 = S32(SIGNED(ctx->r10) >> 16);
    // 0x800165D8: sra         $a3, $t4, 16
    ctx->r7 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800165DC: lh          $a1, 0x4E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X4E);
    // 0x800165E0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800165E4: jal         0x8004C580
    // 0x800165E8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_0;
    // 0x800165E8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_0:
    // 0x800165EC: multu       $s0, $s1
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800165F0: mflo        $t6
    ctx->r14 = lo;
    // 0x800165F4: subu        $s3, $s3, $t6
    ctx->r19 = SUB32(ctx->r19, ctx->r14);
    // 0x800165F8: nop

L_800165FC:
    // 0x800165FC: div         $zero, $s1, $fp
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r30))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r30)));
    // 0x80016600: lh          $t0, 0x56($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X56);
    // 0x80016604: addiu       $s2, $s2, 0x7
    ctx->r18 = ADD32(ctx->r18, 0X7);
    // 0x80016608: bne         $fp, $zero, L_80016614
    if (ctx->r30 != 0) {
        // 0x8001660C: nop
    
            goto L_80016614;
    }
    // 0x8001660C: nop

    // 0x80016610: break       7
    do_break(2147575312);
L_80016614:
    // 0x80016614: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80016618: bne         $fp, $at, L_8001662C
    if (ctx->r30 != ctx->r1) {
        // 0x8001661C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001662C;
    }
    // 0x8001661C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80016620: bne         $s1, $at, L_8001662C
    if (ctx->r17 != ctx->r1) {
        // 0x80016624: nop
    
            goto L_8001662C;
    }
    // 0x80016624: nop

    // 0x80016628: break       6
    do_break(2147575336);
L_8001662C:
    // 0x8001662C: sll         $t7, $s2, 16
    ctx->r15 = S32(ctx->r18 << 16);
    // 0x80016630: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80016634: mflo        $s1
    ctx->r17 = lo;
    // 0x80016638: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8001663C: bne         $s4, $t0, L_80016580
    if (ctx->r20 != ctx->r8) {
        // 0x80016640: or          $s2, $t8, $zero
        ctx->r18 = ctx->r24 | 0;
            goto L_80016580;
    }
    // 0x80016640: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
L_80016644:
    // 0x80016644: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80016648: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8001664C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80016650: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80016654: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80016658: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8001665C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80016660: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80016664: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80016668: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8001666C: jr          $ra
    // 0x80016670: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    TRACE_RETURN()
    return;
    // 0x80016670: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
static void func_80016674_entry(uint8_t* rdram, recomp_context* ctx, unsigned entry) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    if (entry == 1) goto indirect_80016950;
    if (entry == 2) goto indirect_80016BD0;
    if (entry == 3) goto indirect_80017130;
    if (entry == 4) goto indirect_80017290;
    if (entry == 5) goto indirect_800179A0;
    if (entry == 6) goto indirect_800180C0;

    // 0x80016674: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80016678: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8001667C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80016680: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80016684: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80016688: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8001668C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80016690: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80016694: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80016698: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8001669C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800166A0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800166A4: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x800166A8: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
    // 0x800166AC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800166B0: jal         0x8004D134
    // 0x800166B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004D134(rdram, ctx);
        goto after_0;
    // 0x800166B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800166B8: lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // 0x800166BC: addiu       $a0, $a0, -0x3900
    ctx->r4 = ADD32(ctx->r4, -0X3900);
    // 0x800166C0: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    // 0x800166C4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x800166C8: jal         0x80004CE0
    // 0x800166CC: addiu       $a3, $sp, 0x44
    ctx->r7 = ADD32(ctx->r29, 0X44);
    func_80004CE0(rdram, ctx);
        goto after_1;
    // 0x800166CC: addiu       $a3, $sp, 0x44
    ctx->r7 = ADD32(ctx->r29, 0X44);
    after_1:
    // 0x800166D0: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x800166D4: jal         0x8004B1E0
    // 0x800166D8: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_8004B1E0(rdram, ctx);
        goto after_2;
    // 0x800166D8: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_2:
    // 0x800166DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800166E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800166E4: jal         0x8000BD4C
    // 0x800166E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BD4C(rdram, ctx);
        goto after_3;
    // 0x800166E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x800166EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800166F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800166F4: jal         0x8000BDEC
    // 0x800166F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BDEC(rdram, ctx);
        goto after_4;
    // 0x800166F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x800166FC: addiu       $t7, $zero, 0x3E8
    ctx->r15 = ADD32(0, 0X3E8);
    // 0x80016700: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80016704: sw          $t7, -0x2CF8($at)
    MEM_W(-0X2CF8, ctx->r1) = ctx->r15;
    // 0x80016708: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001670C: addiu       $t8, $zero, 0x3D0
    ctx->r24 = ADD32(0, 0X3D0);
    // 0x80016710: sw          $t8, -0x2CF4($at)
    MEM_W(-0X2CF4, ctx->r1) = ctx->r24;
    // 0x80016714: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80016718: sh          $zero, -0x2CC4($at)
    MEM_H(-0X2CC4, ctx->r1) = 0;
    // 0x8001671C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80016720: lui         $at, 0x4238
    ctx->r1 = S32(0X4238 << 16);
    // 0x80016724: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80016728: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8001672C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80016730: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80016734: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80016738: addiu       $v1, $v1, -0x6C40
    ctx->r3 = ADD32(ctx->r3, -0X6C40);
    // 0x8001673C: addiu       $v0, $v0, -0x6C50
    ctx->r2 = ADD32(ctx->r2, -0X6C50);
    // 0x80016740: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80016744: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x80016748: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x8001674C: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x80016750: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80016754: jal         0x8000798C
    // 0x80016758: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    func_8000798C(rdram, ctx);
        goto after_5;
    // 0x80016758: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    after_5:
    // 0x8001675C: jal         0x8000798C
    // 0x80016760: nop

    func_8000798C(rdram, ctx);
        goto after_6;
    // 0x80016760: nop

    after_6:
    // 0x80016764: jal         0x8000798C
    // 0x80016768: nop

    func_8000798C(rdram, ctx);
        goto after_7;
    // 0x80016768: nop

    after_7:
    // 0x8001676C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80016770: addiu       $a1, $zero, 0x5F
    ctx->r5 = ADD32(0, 0X5F);
    // 0x80016774: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x80016778: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001677C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80016780: jal         0x8004C580
    // 0x80016784: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_8;
    // 0x80016784: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_8:
    // 0x80016788: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x8001678C: addiu       $s6, $s6, -0x662C
    ctx->r22 = ADD32(ctx->r22, -0X662C);
    // 0x80016790: lh          $a3, 0x0($s6)
    ctx->r7 = MEM_H(ctx->r22, 0X0);
    // 0x80016794: addiu       $a0, $zero, -0x4
    ctx->r4 = ADD32(0, -0X4);
    // 0x80016798: addiu       $a1, $zero, -0x19
    ctx->r5 = ADD32(0, -0X19);
    // 0x8001679C: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x800167A0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800167A4: jal         0x8004C580
    // 0x800167A8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_9;
    // 0x800167A8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_9:
    // 0x800167AC: lh          $a3, 0x0($s6)
    ctx->r7 = MEM_H(ctx->r22, 0X0);
    // 0x800167B0: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    // 0x800167B4: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    // 0x800167B8: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x800167BC: sll         $t9, $a3, 16
    ctx->r25 = S32(ctx->r7 << 16);
    // 0x800167C0: sra         $a3, $t9, 16
    ctx->r7 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800167C4: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x800167C8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800167CC: jal         0x8004C580
    // 0x800167D0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_10;
    // 0x800167D0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_10:
    // 0x800167D4: jal         0x80023A9C
    // 0x800167D8: nop

    func_80023A9C(rdram, ctx);
        goto after_11;
    // 0x800167D8: nop

    after_11:
    // 0x800167DC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800167E0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800167E4: addiu       $a0, $zero, -0x49
    ctx->r4 = ADD32(0, -0X49);
    // 0x800167E8: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    // 0x800167EC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800167F0: jal         0x80016500
    // 0x800167F4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_80016500(rdram, ctx);
        goto after_12;
    // 0x800167F4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_12:
    // 0x800167F8: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800167FC: lui         $s4, 0x8007
    ctx->r20 = S32(0X8007 << 16);
    // 0x80016800: addiu       $s0, $zero, 0x3C
    ctx->r16 = ADD32(0, 0X3C);
    // 0x80016804: addiu       $s4, $s4, -0x670C
    ctx->r20 = ADD32(ctx->r20, -0X670C);
    // 0x80016808: addiu       $s5, $s5, -0x2E5A
    ctx->r21 = ADD32(ctx->r21, -0X2E5A);
    // 0x8001680C: addiu       $s3, $zero, -0x2
    ctx->r19 = ADD32(0, -0X2);
    // 0x80016810: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x80016814: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
L_80016818:
    // 0x80016818: bnel        $t2, $s2, L_8001686C
    if (ctx->r10 != ctx->r18) {
        // 0x8001681C: lw          $t8, 0x44($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X44);
            goto L_8001686C;
    }
    goto skip_0;
    // 0x8001681C: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x80016820: beql        $s0, $zero, L_8001683C
    if (ctx->r16 == 0) {
        // 0x80016824: lhu         $t5, 0x0($s5)
        ctx->r13 = MEM_HU(ctx->r21, 0X0);
            goto L_8001683C;
    }
    goto skip_1;
    // 0x80016824: lhu         $t5, 0x0($s5)
    ctx->r13 = MEM_HU(ctx->r21, 0X0);
    skip_1:
    // 0x80016828: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8001682C: sll         $t3, $s0, 16
    ctx->r11 = S32(ctx->r16 << 16);
    // 0x80016830: b           L_80016868
    // 0x80016834: sra         $s0, $t3, 16
    ctx->r16 = S32(SIGNED(ctx->r11) >> 16);
        goto L_80016868;
    // 0x80016834: sra         $s0, $t3, 16
    ctx->r16 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80016838: lhu         $t5, 0x0($s5)
    ctx->r13 = MEM_HU(ctx->r21, 0X0);
L_8001683C:
    // 0x8001683C: andi        $t6, $t5, 0x9000
    ctx->r14 = ctx->r13 & 0X9000;
    // 0x80016840: beql        $t6, $zero, L_8001686C
    if (ctx->r14 == 0) {
        // 0x80016844: lw          $t8, 0x44($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X44);
            goto L_8001686C;
    }
    goto skip_2;
    // 0x80016844: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    skip_2:
    // 0x80016848: jal         0x80044480
    // 0x8001684C: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    func_80044480(rdram, ctx);
        goto after_13;
    // 0x8001684C: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_13:
    // 0x80016850: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80016854: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80016858: jal         0x8004D134
    // 0x8001685C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_8004D134(rdram, ctx);
        goto after_14;
    // 0x8001685C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_14:
    // 0x80016860: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80016864: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
L_80016868:
    // 0x80016868: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
L_8001686C:
    // 0x8001686C: andi        $a2, $s1, 0x7F
    ctx->r6 = ctx->r17 & 0X7F;
    // 0x80016870: addiu       $t6, $a2, 0x80
    ctx->r14 = ADD32(ctx->r6, 0X80);
    // 0x80016874: bne         $t8, $s3, L_800168C0
    if (ctx->r24 != ctx->r19) {
        // 0x80016878: sll         $t7, $t6, 24
        ctx->r15 = S32(ctx->r14 << 24);
            goto L_800168C0;
    }
    // 0x80016878: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x8001687C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80016880: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80016884: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80016888: jal         0x8004C4D8
    // 0x8001688C: addiu       $s0, $zero, 0x3C
    ctx->r16 = ADD32(0, 0X3C);
    func_8004C4D8(rdram, ctx);
        goto after_15;
    // 0x8001688C: addiu       $s0, $zero, 0x3C
    ctx->r16 = ADD32(0, 0X3C);
    after_15:
    // 0x80016890: jal         0x8004B21C
    // 0x80016894: nop

    func_8004B21C(rdram, ctx);
        goto after_16;
    // 0x80016894: nop

    after_16:
    // 0x80016898: jal         0x80004E5C
    // 0x8001689C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_80004E5C(rdram, ctx);
        goto after_17;
    // 0x8001689C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_17:
    // 0x800168A0: jal         0x8000798C
    // 0x800168A4: nop

    func_8000798C(rdram, ctx);
        goto after_18;
    // 0x800168A4: nop

    after_18:
    // 0x800168A8: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800168AC: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
L_800168B0:
    // 0x800168B0: jal         0x8000798C
    // 0x800168B4: nop

    func_8000798C(rdram, ctx);
        goto after_19;
    // 0x800168B4: nop

    after_19:
    // 0x800168B8: b           L_800168B0
    // 0x800168BC: nop

        goto L_800168B0;
    // 0x800168BC: nop

L_800168C0:
    // 0x800168C0: lh          $t0, 0x0($s6)
    ctx->r8 = MEM_H(ctx->r22, 0X0);
    // 0x800168C4: sra         $a2, $t7, 16
    ctx->r6 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800168C8: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    // 0x800168CC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800168D0: addu        $v0, $s4, $t1
    ctx->r2 = ADD32(ctx->r20, ctx->r9);
    // 0x800168D4: lh          $a0, -0x4($v0)
    ctx->r4 = MEM_H(ctx->r2, -0X4);
    // 0x800168D8: lh          $a1, -0x2($v0)
    ctx->r5 = MEM_H(ctx->r2, -0X2);
    // 0x800168DC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800168E0: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x800168E4: addiu       $a1, $a1, -0x9
    ctx->r5 = ADD32(ctx->r5, -0X9);
    // 0x800168E8: sll         $t2, $a0, 16
    ctx->r10 = S32(ctx->r4 << 16);
    // 0x800168EC: sll         $t4, $a1, 16
    ctx->r12 = S32(ctx->r5 << 16);
    // 0x800168F0: sra         $a0, $t2, 16
    ctx->r4 = S32(SIGNED(ctx->r10) >> 16);
    // 0x800168F4: sra         $a1, $t4, 16
    ctx->r5 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800168F8: jal         0x8004C580
    // 0x800168FC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_20;
    // 0x800168FC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_20:
    // 0x80016900: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x80016904: sll         $t9, $s1, 16
    ctx->r25 = S32(ctx->r17 << 16);
    // 0x80016908: jal         0x8000798C
    // 0x8001690C: sra         $s1, $t9, 16
    ctx->r17 = S32(SIGNED(ctx->r25) >> 16);
    func_8000798C(rdram, ctx);
        goto after_21;
    // 0x8001690C: sra         $s1, $t9, 16
    ctx->r17 = S32(SIGNED(ctx->r25) >> 16);
    after_21:
    // 0x80016910: b           L_80016818
    // 0x80016914: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
        goto L_80016818;
    // 0x80016914: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80016918: nop

    // 0x8001691C: nop

    // 0x80016920: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80016924: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80016928: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8001692C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80016930: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80016934: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80016938: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8001693C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80016940: jr          $ra
    // 0x80016944: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    TRACE_RETURN()
    return;
    // 0x80016944: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80016948: nop

    // 0x8001694C: nop

indirect_80016950:
    // 0x80016950: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80016954: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80016958: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x8001695C: addiu       $s3, $s3, -0x6BE0
    ctx->r19 = ADD32(ctx->r19, -0X6BE0);
    // 0x80016960: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80016964: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80016968: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8001696C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80016970: andi        $t7, $t6, 0x100
    ctx->r15 = ctx->r14 & 0X100;
    // 0x80016974: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80016978: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8001697C: addiu       $s0, $zero, 0xA
    ctx->r16 = ADD32(0, 0XA);
    // 0x80016980: addiu       $s1, $zero, 0x10E
    ctx->r17 = ADD32(0, 0X10E);
    // 0x80016984: beq         $t7, $zero, L_8001699C
    if (ctx->r15 == 0) {
        // 0x80016988: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8001699C;
    }
    // 0x80016988: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8001698C: jal         0x80007EC8
    // 0x80016990: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_80007EC8(rdram, ctx);
        goto after_22;
    // 0x80016990: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_22:
    // 0x80016994: b           L_800169A8
    // 0x80016998: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_800169A8;
    // 0x80016998: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8001699C:
    // 0x8001699C: jal         0x80007EC8
    // 0x800169A0: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    func_80007EC8(rdram, ctx);
        goto after_23;
    // 0x800169A0: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_23:
    // 0x800169A4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800169A8:
    // 0x800169A8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800169AC: lh          $v0, -0x662C($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X662C);
    // 0x800169B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800169B4: beq         $v0, $at, L_800169E0
    if (ctx->r2 == ctx->r1) {
        // 0x800169B8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800169E0;
    }
    // 0x800169B8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800169BC: beq         $v0, $at, L_80016A14
    if (ctx->r2 == ctx->r1) {
        // 0x800169C0: lui         $a1, 0x8013
        ctx->r5 = S32(0X8013 << 16);
            goto L_80016A14;
    }
    // 0x800169C0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800169C4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800169C8: beq         $v0, $at, L_80016A40
    if (ctx->r2 == ctx->r1) {
        // 0x800169CC: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80016A40;
    }
    // 0x800169CC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800169D0: beq         $v0, $at, L_80016A78
    if (ctx->r2 == ctx->r1) {
        // 0x800169D4: nop
    
            goto L_80016A78;
    }
    // 0x800169D4: nop

    // 0x800169D8: b           L_80016AB0
    // 0x800169DC: nop

        goto L_80016AB0;
    // 0x800169DC: nop

L_800169E0:
    // 0x800169E0: beq         $v1, $zero, L_80016AB0
    if (ctx->r3 == 0) {
        // 0x800169E4: lui         $a1, 0x8013
        ctx->r5 = S32(0X8013 << 16);
            goto L_80016AB0;
    }
    // 0x800169E4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800169E8: lw          $a1, -0x65F0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X65F0);
    // 0x800169EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800169F0: jal         0x8004EFB4
    // 0x800169F4: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    func_8004EFB4(rdram, ctx);
        goto after_24;
    // 0x800169F4: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_24:
    // 0x800169F8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800169FC: lw          $a1, -0x65F0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X65F0);
    // 0x80016A00: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80016A04: jal         0x80011520
    // 0x80016A08: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    func_80011520(rdram, ctx);
        goto after_25;
    // 0x80016A08: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_25:
    // 0x80016A0C: b           L_80016AC0
    // 0x80016A10: nop

        goto L_80016AC0;
    // 0x80016A10: nop

L_80016A14:
    // 0x80016A14: lw          $a1, -0x65F4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X65F4);
    // 0x80016A18: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80016A1C: jal         0x8004EFB4
    // 0x80016A20: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    func_8004EFB4(rdram, ctx);
        goto after_26;
    // 0x80016A20: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_26:
    // 0x80016A24: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80016A28: lw          $a1, -0x65F4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X65F4);
    // 0x80016A2C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80016A30: jal         0x80011520
    // 0x80016A34: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    func_80011520(rdram, ctx);
        goto after_27;
    // 0x80016A34: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_27:
    // 0x80016A38: b           L_80016AC0
    // 0x80016A3C: nop

        goto L_80016AC0;
    // 0x80016A3C: nop

L_80016A40:
    // 0x80016A40: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80016A44: lw          $v0, -0x65E4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X65E4);
    // 0x80016A48: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80016A4C: beq         $v0, $zero, L_80016AB0
    if (ctx->r2 == 0) {
        // 0x80016A50: nop
    
            goto L_80016AB0;
    }
    // 0x80016A50: nop

    // 0x80016A54: jal         0x8004EFB4
    // 0x80016A58: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    func_8004EFB4(rdram, ctx);
        goto after_28;
    // 0x80016A58: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    after_28:
    // 0x80016A5C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80016A60: lw          $a1, -0x65E4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X65E4);
    // 0x80016A64: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80016A68: jal         0x80011520
    // 0x80016A6C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    func_80011520(rdram, ctx);
        goto after_29;
    // 0x80016A6C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_29:
    // 0x80016A70: b           L_80016AC0
    // 0x80016A74: nop

        goto L_80016AC0;
    // 0x80016A74: nop

L_80016A78:
    // 0x80016A78: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80016A7C: lw          $v0, -0x65E8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X65E8);
    // 0x80016A80: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80016A84: beq         $v0, $zero, L_80016AB0
    if (ctx->r2 == 0) {
        // 0x80016A88: nop
    
            goto L_80016AB0;
    }
    // 0x80016A88: nop

    // 0x80016A8C: jal         0x8004EFB4
    // 0x80016A90: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    func_8004EFB4(rdram, ctx);
        goto after_30;
    // 0x80016A90: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    after_30:
    // 0x80016A94: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80016A98: lw          $a1, -0x65E8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X65E8);
    // 0x80016A9C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80016AA0: jal         0x80011520
    // 0x80016AA4: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    func_80011520(rdram, ctx);
        goto after_31;
    // 0x80016AA4: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_31:
    // 0x80016AA8: b           L_80016AC0
    // 0x80016AAC: nop

        goto L_80016AC0;
    // 0x80016AAC: nop

L_80016AB0:
    // 0x80016AB0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80016AB4: addiu       $a1, $a1, -0x6A18
    ctx->r5 = ADD32(ctx->r5, -0X6A18);
    // 0x80016AB8: jal         0x80011520
    // 0x80016ABC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80011520(rdram, ctx);
        goto after_32;
    // 0x80016ABC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_32:
L_80016AC0:
    // 0x80016AC0: beq         $s0, $zero, L_80016AF8
    if (ctx->r16 == 0) {
        // 0x80016AC4: lui         $t0, 0x8013
        ctx->r8 = S32(0X8013 << 16);
            goto L_80016AF8;
    }
    // 0x80016AC4: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80016AC8: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80016ACC: bne         $s0, $zero, L_80016B8C
    if (ctx->r16 != 0) {
        // 0x80016AD0: nop
    
            goto L_80016B8C;
    }
    // 0x80016AD0: nop

    // 0x80016AD4: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x80016AD8: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    // 0x80016ADC: andi        $t9, $t8, 0x100
    ctx->r25 = ctx->r24 & 0X100;
    // 0x80016AE0: bne         $t9, $zero, L_80016B8C
    if (ctx->r25 != 0) {
        // 0x80016AE4: nop
    
            goto L_80016B8C;
    }
    // 0x80016AE4: nop

    // 0x80016AE8: jal         0x800443A8
    // 0x80016AEC: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    func_800443A8(rdram, ctx);
        goto after_33;
    // 0x80016AEC: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_33:
    // 0x80016AF0: b           L_80016B8C
    // 0x80016AF4: nop

        goto L_80016B8C;
    // 0x80016AF4: nop

L_80016AF8:
    // 0x80016AF8: lh          $t0, -0x6B8E($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X6B8E);
    // 0x80016AFC: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80016B00: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80016B04: beq         $t0, $zero, L_80016B34
    if (ctx->r8 == 0) {
        // 0x80016B08: addiu       $a1, $zero, 0x28
        ctx->r5 = ADD32(0, 0X28);
            goto L_80016B34;
    }
    // 0x80016B08: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x80016B0C: lhu         $t1, -0x2E5A($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X2E5A);
    // 0x80016B10: andi        $t2, $t1, 0x1000
    ctx->r10 = ctx->r9 & 0X1000;
    // 0x80016B14: beq         $t2, $zero, L_80016B8C
    if (ctx->r10 == 0) {
        // 0x80016B18: nop
    
            goto L_80016B8C;
    }
    // 0x80016B18: nop

    // 0x80016B1C: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80016B20: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
L_80016B24:
    // 0x80016B24: jal         0x8000798C
    // 0x80016B28: nop

    func_8000798C(rdram, ctx);
        goto after_34;
    // 0x80016B28: nop

    after_34:
    // 0x80016B2C: b           L_80016B24
    // 0x80016B30: nop

        goto L_80016B24;
    // 0x80016B30: nop

L_80016B34:
    // 0x80016B34: beq         $s1, $zero, L_80016B74
    if (ctx->r17 == 0) {
        // 0x80016B38: nor         $t7, $s2, $zero
        ctx->r15 = ~(ctx->r18 | 0);
            goto L_80016B74;
    }
    // 0x80016B38: nor         $t7, $s2, $zero
    ctx->r15 = ~(ctx->r18 | 0);
    // 0x80016B3C: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x80016B40: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x80016B44: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80016B48: andi        $t5, $t4, 0x100
    ctx->r13 = ctx->r12 & 0X100;
    // 0x80016B4C: beq         $t5, $zero, L_80016B5C
    if (ctx->r13 == 0) {
        // 0x80016B50: sra         $a2, $t8, 16
        ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
            goto L_80016B5C;
    }
    // 0x80016B50: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80016B54: b           L_80016B60
    // 0x80016B58: addiu       $a3, $zero, 0x53
    ctx->r7 = ADD32(0, 0X53);
        goto L_80016B60;
    // 0x80016B58: addiu       $a3, $zero, 0x53
    ctx->r7 = ADD32(0, 0X53);
L_80016B5C:
    // 0x80016B5C: addiu       $a3, $zero, 0x28
    ctx->r7 = ADD32(0, 0X28);
L_80016B60:
    // 0x80016B60: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80016B64: jal         0x8004C580
    // 0x80016B68: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_35;
    // 0x80016B68: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_35:
    // 0x80016B6C: b           L_80016B8C
    // 0x80016B70: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
        goto L_80016B8C;
    // 0x80016B70: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
L_80016B74:
    // 0x80016B74: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80016B78: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
L_80016B7C:
    // 0x80016B7C: jal         0x8000798C
    // 0x80016B80: nop

    func_8000798C(rdram, ctx);
        goto after_36;
    // 0x80016B80: nop

    after_36:
    // 0x80016B84: b           L_80016B7C
    // 0x80016B88: nop

        goto L_80016B7C;
    // 0x80016B88: nop

L_80016B8C:
    // 0x80016B8C: jal         0x8000798C
    // 0x80016B90: nop

    func_8000798C(rdram, ctx);
        goto after_37;
    // 0x80016B90: nop

    after_37:
    // 0x80016B94: b           L_80016AC0
    // 0x80016B98: nop

        goto L_80016AC0;
    // 0x80016B98: nop

    // 0x80016B9C: nop

    // 0x80016BA0: nop

    // 0x80016BA4: nop

    // 0x80016BA8: nop

    // 0x80016BAC: nop

    // 0x80016BB0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80016BB4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80016BB8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80016BBC: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80016BC0: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80016BC4: jr          $ra
    // 0x80016BC8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    TRACE_RETURN()
    return;
    // 0x80016BC8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80016BCC: nop

indirect_80016BD0:
    // 0x80016BD0: addiu       $sp, $sp, -0x240
    ctx->r29 = ADD32(ctx->r29, -0X240);
    // 0x80016BD4: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80016BD8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80016BDC: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80016BE0: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x80016BE4: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x80016BE8: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80016BEC: sw          $a0, 0x240($sp)
    MEM_W(0X240, ctx->r29) = ctx->r4;
    // 0x80016BF0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80016BF4: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x80016BF8: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80016BFC: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80016C00: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80016C04: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80016C08: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80016C0C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80016C10: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80016C14: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x80016C18: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80016C1C: sw          $t6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r14;
    // 0x80016C20: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
    // 0x80016C24: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80016C28: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80016C2C: jal         0x8004D134
    // 0x80016C30: mov.s       $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    ctx->f22.fl = ctx->f20.fl;
    func_8004D134(rdram, ctx);
        goto after_38;
    // 0x80016C30: mov.s       $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    ctx->f22.fl = ctx->f20.fl;
    after_38:
    // 0x80016C34: lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // 0x80016C38: addiu       $a0, $a0, -0x3900
    ctx->r4 = ADD32(ctx->r4, -0X3900);
    // 0x80016C3C: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    // 0x80016C40: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80016C44: jal         0x80004CE0
    // 0x80016C48: addiu       $a3, $sp, 0x78
    ctx->r7 = ADD32(ctx->r29, 0X78);
    func_80004CE0(rdram, ctx);
        goto after_39;
    // 0x80016C48: addiu       $a3, $sp, 0x78
    ctx->r7 = ADD32(ctx->r29, 0X78);
    after_39:
    // 0x80016C4C: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x80016C50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80016C54: jal         0x800499B0
    // 0x80016C58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800499B0(rdram, ctx);
        goto after_40;
    // 0x80016C58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_40:
    // 0x80016C5C: jal         0x8004B1E0
    // 0x80016C60: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8004B1E0(rdram, ctx);
        goto after_41;
    // 0x80016C60: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_41:
    // 0x80016C64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80016C68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80016C6C: jal         0x8000BD4C
    // 0x80016C70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BD4C(rdram, ctx);
        goto after_42;
    // 0x80016C70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_42:
    // 0x80016C74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80016C78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80016C7C: jal         0x8000BDEC
    // 0x80016C80: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BDEC(rdram, ctx);
        goto after_43;
    // 0x80016C80: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_43:
    // 0x80016C84: addiu       $t7, $zero, 0x3E8
    ctx->r15 = ADD32(0, 0X3E8);
    // 0x80016C88: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80016C8C: sw          $t7, -0x2CF8($at)
    MEM_W(-0X2CF8, ctx->r1) = ctx->r15;
    // 0x80016C90: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80016C94: addiu       $t8, $zero, 0x3D0
    ctx->r24 = ADD32(0, 0X3D0);
    // 0x80016C98: sw          $t8, -0x2CF4($at)
    MEM_W(-0X2CF4, ctx->r1) = ctx->r24;
    // 0x80016C9C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80016CA0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80016CA4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80016CA8: sh          $s1, -0x2CC4($at)
    MEM_H(-0X2CC4, ctx->r1) = ctx->r17;
    // 0x80016CAC: sw          $s1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r17;
    // 0x80016CB0: addiu       $a0, $a0, 0x28C0
    ctx->r4 = ADD32(ctx->r4, 0X28C0);
    // 0x80016CB4: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    // 0x80016CB8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80016CBC: jal         0x80004CE0
    // 0x80016CC0: addiu       $a3, $sp, 0x70
    ctx->r7 = ADD32(ctx->r29, 0X70);
    func_80004CE0(rdram, ctx);
        goto after_44;
    // 0x80016CC0: addiu       $a3, $sp, 0x70
    ctx->r7 = ADD32(ctx->r29, 0X70);
    after_44:
    // 0x80016CC4: lui         $at, 0x42A6
    ctx->r1 = S32(0X42A6 << 16);
    // 0x80016CC8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80016CCC: lui         $at, 0x4230
    ctx->r1 = S32(0X4230 << 16);
    // 0x80016CD0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80016CD4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80016CD8: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x80016CDC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80016CE0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80016CE4: addiu       $fp, $fp, -0x6C50
    ctx->r30 = ADD32(ctx->r30, -0X6C50);
    // 0x80016CE8: addiu       $v1, $v1, -0x6C40
    ctx->r3 = ADD32(ctx->r3, -0X6C40);
    // 0x80016CEC: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x80016CF0: swc1        $f20, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->f20.u32l;
    // 0x80016CF4: swc1        $f20, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f20.u32l;
    // 0x80016CF8: swc1        $f20, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f20.u32l;
    // 0x80016CFC: swc1        $f4, 0x4($fp)
    MEM_W(0X4, ctx->r30) = ctx->f4.u32l;
    // 0x80016D00: swc1        $f6, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->f6.u32l;
    // 0x80016D04: jal         0x8000798C
    // 0x80016D08: swc1        $f8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f8.u32l;
    func_8000798C(rdram, ctx);
        goto after_45;
    // 0x80016D08: swc1        $f8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f8.u32l;
    after_45:
    // 0x80016D0C: jal         0x8000798C
    // 0x80016D10: nop

    func_8000798C(rdram, ctx);
        goto after_46;
    // 0x80016D10: nop

    after_46:
    // 0x80016D14: jal         0x8000798C
    // 0x80016D18: nop

    func_8000798C(rdram, ctx);
        goto after_47;
    // 0x80016D18: nop

    after_47:
    // 0x80016D1C: addiu       $a0, $sp, 0xA0
    ctx->r4 = ADD32(ctx->r29, 0XA0);
    // 0x80016D20: jal         0x80020328
    // 0x80016D24: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80020328(rdram, ctx);
        goto after_48;
    // 0x80016D24: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_48:
    // 0x80016D28: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x80016D2C: addiu       $s6, $s6, -0x6BE0
    ctx->r22 = ADD32(ctx->r22, -0X6BE0);
    // 0x80016D30: lw          $t9, 0x0($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X0);
    // 0x80016D34: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // 0x80016D38: bne         $s4, $t9, L_80016D6C
    if (ctx->r20 != ctx->r25) {
        // 0x80016D3C: lui         $t0, 0x8013
        ctx->r8 = S32(0X8013 << 16);
            goto L_80016D6C;
    }
    // 0x80016D3C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80016D40: lw          $t0, -0x68C8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X68C8);
    // 0x80016D44: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80016D48: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80016D4C: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80016D50: lwc1        $f10, -0x66B8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X66B8);
    // 0x80016D54: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80016D58: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80016D5C: nop

    // 0x80016D60: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80016D64: b           L_80016DA0
    // 0x80016D68: swc1        $f18, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f18.u32l;
        goto L_80016DA0;
    // 0x80016D68: swc1        $f18, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f18.u32l;
L_80016D6C:
    // 0x80016D6C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80016D70: lw          $t2, -0x68C8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X68C8);
    // 0x80016D74: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80016D78: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80016D7C: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80016D80: lwc1        $f4, -0x66E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X66E0);
    // 0x80016D84: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80016D88: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80016D8C: lui         $at, 0x3D00
    ctx->r1 = S32(0X3D00 << 16);
    // 0x80016D90: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80016D94: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80016D98: swc1        $f10, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f10.u32l;
    // 0x80016D9C: swc1        $f8, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f8.u32l;
L_80016DA0:
    // 0x80016DA0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80016DA4: lwc1        $f0, 0x6290($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6290);
    // 0x80016DA8: lw          $t4, 0x0($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X0);
    // 0x80016DAC: swc1        $f0, 0x1AC($sp)
    MEM_W(0X1AC, ctx->r29) = ctx->f0.u32l;
    // 0x80016DB0: bne         $s4, $t4, L_80016DD4
    if (ctx->r20 != ctx->r12) {
        // 0x80016DB4: swc1        $f0, 0x1A8($sp)
        MEM_W(0X1A8, ctx->r29) = ctx->f0.u32l;
            goto L_80016DD4;
    }
    // 0x80016DB4: swc1        $f0, 0x1A8($sp)
    MEM_W(0X1A8, ctx->r29) = ctx->f0.u32l;
    // 0x80016DB8: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80016DBC: jal         0x80049CFC
    // 0x80016DC0: addiu       $a0, $a0, 0x6280
    ctx->r4 = ADD32(ctx->r4, 0X6280);
    func_80049CFC(rdram, ctx);
        goto after_49;
    // 0x80016DC0: addiu       $a0, $a0, 0x6280
    ctx->r4 = ADD32(ctx->r4, 0X6280);
    after_49:
    // 0x80016DC4: jal         0x80049D80
    // 0x80016DC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80049D80(rdram, ctx);
        goto after_50;
    // 0x80016DC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_50:
    // 0x80016DCC: b           L_80016DEC
    // 0x80016DD0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80016DEC;
    // 0x80016DD0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80016DD4:
    // 0x80016DD4: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80016DD8: jal         0x80049CFC
    // 0x80016DDC: addiu       $a0, $a0, 0x6288
    ctx->r4 = ADD32(ctx->r4, 0X6288);
    func_80049CFC(rdram, ctx);
        goto after_51;
    // 0x80016DDC: addiu       $a0, $a0, 0x6288
    ctx->r4 = ADD32(ctx->r4, 0X6288);
    after_51:
    // 0x80016DE0: jal         0x80049D80
    // 0x80016DE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80049D80(rdram, ctx);
        goto after_52;
    // 0x80016DE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_52:
    // 0x80016DE8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80016DEC:
    // 0x80016DEC: jal         0x80049DFC
    // 0x80016DF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80049DFC(rdram, ctx);
        goto after_53;
    // 0x80016DF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_53:
    // 0x80016DF4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80016DF8: jal         0x8004A148
    // 0x80016DFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8004A148(rdram, ctx);
        goto after_54;
    // 0x80016DFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_54:
    // 0x80016E00: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80016E04: addiu       $s2, $zero, 0x1C2
    ctx->r18 = ADD32(0, 0X1C2);
    // 0x80016E08: addiu       $s3, $zero, 0x3C
    ctx->r19 = ADD32(0, 0X3C);
    // 0x80016E0C: lw          $t5, 0xD8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XD8);
    // 0x80016E10: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80016E14: ori         $t6, $t5, 0x8001
    ctx->r14 = ctx->r13 | 0X8001;
    // 0x80016E18: jal         0x80044514
    // 0x80016E1C: sw          $t6, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r14;
    func_80044514(rdram, ctx);
        goto after_55;
    // 0x80016E1C: sw          $t6, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r14;
    after_55:
    // 0x80016E20: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80016E24: sh          $s1, -0x6B94($at)
    MEM_H(-0X6B94, ctx->r1) = ctx->r17;
    // 0x80016E28: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80016E2C: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80016E30: lwc1        $f20, 0x6294($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X6294);
    // 0x80016E34: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x80016E38: lw          $t7, 0x0($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X0);
L_80016E3C:
    // 0x80016E3C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80016E40: bnel        $s4, $t7, L_80016E5C
    if (ctx->r20 != ctx->r15) {
        // 0x80016E44: lw          $t8, 0x78($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X78);
            goto L_80016E5C;
    }
    goto skip_3;
    // 0x80016E44: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    skip_3:
    // 0x80016E48: lwc1        $f16, 0x4($fp)
    ctx->f16.u32l = MEM_W(ctx->r30, 0X4);
    // 0x80016E4C: lwc1        $f18, 0x6298($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6298);
    // 0x80016E50: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80016E54: swc1        $f4, 0x4($fp)
    MEM_W(0X4, ctx->r30) = ctx->f4.u32l;
    // 0x80016E58: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
L_80016E5C:
    // 0x80016E5C: bnel        $t8, $s4, L_80016E94
    if (ctx->r24 != ctx->r20) {
        // 0x80016E60: lw          $t2, 0x78($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X78);
            goto L_80016E94;
    }
    goto skip_4;
    // 0x80016E60: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    skip_4:
    // 0x80016E64: beq         $s2, $zero, L_80016E78
    if (ctx->r18 == 0) {
        // 0x80016E68: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_80016E78;
    }
    // 0x80016E68: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80016E6C: lhu         $t9, -0x2E5A($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X2E5A);
    // 0x80016E70: andi        $t0, $t9, 0x9000
    ctx->r8 = ctx->r25 & 0X9000;
    // 0x80016E74: beq         $t0, $zero, L_80016E90
    if (ctx->r8 == 0) {
        // 0x80016E78: addiu       $a0, $zero, 0xF
        ctx->r4 = ADD32(0, 0XF);
            goto L_80016E90;
    }
L_80016E78:
    // 0x80016E78: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80016E7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80016E80: jal         0x8004D134
    // 0x80016E84: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_8004D134(rdram, ctx);
        goto after_56;
    // 0x80016E84: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_56:
    // 0x80016E88: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80016E8C: sw          $t1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r9;
L_80016E90:
    // 0x80016E90: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
L_80016E94:
    // 0x80016E94: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80016E98: bne         $t2, $at, L_80016F20
    if (ctx->r10 != ctx->r1) {
        // 0x80016E9C: nop
    
            goto L_80016F20;
    }
    // 0x80016E9C: nop

    // 0x80016EA0: jal         0x8004A0C4
    // 0x80016EA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8004A0C4(rdram, ctx);
        goto after_57;
    // 0x80016EA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_57:
    // 0x80016EA8: jal         0x8004A0C4
    // 0x80016EAC: lw          $a0, 0xA4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA4);
    func_8004A0C4(rdram, ctx);
        goto after_58;
    // 0x80016EAC: lw          $a0, 0xA4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA4);
    after_58:
    // 0x80016EB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80016EB4: jal         0x8004C4D8
    // 0x80016EB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004C4D8(rdram, ctx);
        goto after_59;
    // 0x80016EB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_59:
    // 0x80016EBC: jal         0x80049C48
    // 0x80016EC0: nop

    func_80049C48(rdram, ctx);
        goto after_60;
    // 0x80016EC0: nop

    after_60:
    // 0x80016EC4: jal         0x8004B21C
    // 0x80016EC8: nop

    func_8004B21C(rdram, ctx);
        goto after_61;
    // 0x80016EC8: nop

    after_61:
    // 0x80016ECC: jal         0x80004E5C
    // 0x80016ED0: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    func_80004E5C(rdram, ctx);
        goto after_62;
    // 0x80016ED0: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    after_62:
    // 0x80016ED4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80016ED8: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80016EDC: sh          $zero, -0x6B94($at)
    MEM_H(-0X6B94, ctx->r1) = 0;
    // 0x80016EE0: sw          $t3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r11;
L_80016EE4:
    // 0x80016EE4: jal         0x8000798C
    // 0x80016EE8: nop

    func_8000798C(rdram, ctx);
        goto after_63;
    // 0x80016EE8: nop

    after_63:
    // 0x80016EEC: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x80016EF0: bne         $t4, $zero, L_80016EE4
    if (ctx->r12 != 0) {
        // 0x80016EF4: nop
    
            goto L_80016EE4;
    }
    // 0x80016EF4: nop

    // 0x80016EF8: jal         0x80004E5C
    // 0x80016EFC: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    func_80004E5C(rdram, ctx);
        goto after_64;
    // 0x80016EFC: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    after_64:
    // 0x80016F00: jal         0x8000798C
    // 0x80016F04: nop

    func_8000798C(rdram, ctx);
        goto after_65;
    // 0x80016F04: nop

    after_65:
    // 0x80016F08: lw          $t5, 0x240($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X240);
    // 0x80016F0C: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
L_80016F10:
    // 0x80016F10: jal         0x8000798C
    // 0x80016F14: nop

    func_8000798C(rdram, ctx);
        goto after_66;
    // 0x80016F14: nop

    after_66:
    // 0x80016F18: b           L_80016F10
    // 0x80016F1C: nop

        goto L_80016F10;
    // 0x80016F1C: nop

L_80016F20:
    // 0x80016F20: beql        $s3, $zero, L_80016F48
    if (ctx->r19 == 0) {
        // 0x80016F24: nor         $t9, $s7, $zero
        ctx->r25 = ~(ctx->r23 | 0);
            goto L_80016F48;
    }
    goto skip_5;
    // 0x80016F24: nor         $t9, $s7, $zero
    ctx->r25 = ~(ctx->r23 | 0);
    skip_5:
    // 0x80016F28: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x80016F2C: sll         $t6, $s3, 16
    ctx->r14 = S32(ctx->r19 << 16);
    // 0x80016F30: sra         $s3, $t6, 16
    ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80016F34: bnel        $s3, $zero, L_80016F48
    if (ctx->r19 != 0) {
        // 0x80016F38: nor         $t9, $s7, $zero
        ctx->r25 = ~(ctx->r23 | 0);
            goto L_80016F48;
    }
    goto skip_6;
    // 0x80016F38: nor         $t9, $s7, $zero
    ctx->r25 = ~(ctx->r23 | 0);
    skip_6:
    // 0x80016F3C: jal         0x80044480
    // 0x80016F40: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    func_80044480(rdram, ctx);
        goto after_67;
    // 0x80016F40: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    after_67:
    // 0x80016F44: nor         $t9, $s7, $zero
    ctx->r25 = ~(ctx->r23 | 0);
L_80016F48:
    // 0x80016F48: sll         $t0, $t9, 24
    ctx->r8 = S32(ctx->r25 << 24);
    // 0x80016F4C: sra         $a2, $t0, 16
    ctx->r6 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80016F50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80016F54: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80016F58: addiu       $a3, $zero, 0x27
    ctx->r7 = ADD32(0, 0X27);
    // 0x80016F5C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80016F60: jal         0x8004C580
    // 0x80016F64: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_68;
    // 0x80016F64: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_68:
    // 0x80016F68: addiu       $s7, $s7, 0x8
    ctx->r23 = ADD32(ctx->r23, 0X8);
    // 0x80016F6C: sll         $t2, $s7, 16
    ctx->r10 = S32(ctx->r23 << 16);
    // 0x80016F70: beq         $s2, $zero, L_80016F7C
    if (ctx->r18 == 0) {
        // 0x80016F74: sra         $s7, $t2, 16
        ctx->r23 = S32(SIGNED(ctx->r10) >> 16);
            goto L_80016F7C;
    }
    // 0x80016F74: sra         $s7, $t2, 16
    ctx->r23 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80016F78: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_80016F7C:
    // 0x80016F7C: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80016F80: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80016F84: addiu       $a0, $sp, 0x1F8
    ctx->r4 = ADD32(ctx->r29, 0X1F8);
    // 0x80016F88: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80016F8C: jal         0x80049840
    // 0x80016F90: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    func_80049840(rdram, ctx);
        goto after_69;
    // 0x80016F90: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_69:
    // 0x80016F94: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80016F98: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80016F9C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80016FA0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80016FA4: jal         0x80001AB4
    // 0x80016FA8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80001AB4(rdram, ctx);
        goto after_70;
    // 0x80016FA8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_70:
    // 0x80016FAC: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80016FB0: addiu       $a2, $sp, 0x1F8
    ctx->r6 = ADD32(ctx->r29, 0X1F8);
    // 0x80016FB4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80016FB8: jal         0x80000BD8
    // 0x80016FBC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_80000BD8(rdram, ctx);
        goto after_71;
    // 0x80016FBC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_71:
    // 0x80016FC0: lw          $t4, 0x0($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X0);
    // 0x80016FC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80016FC8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80016FCC: bne         $s4, $t4, L_8001700C
    if (ctx->r20 != ctx->r12) {
        // 0x80016FD0: lui         $at, 0x8007
        ctx->r1 = S32(0X8007 << 16);
            goto L_8001700C;
    }
    // 0x80016FD0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80016FD4: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80016FD8: addiu       $a0, $a0, -0x6684
    ctx->r4 = ADD32(ctx->r4, -0X6684);
    // 0x80016FDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80016FE0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80016FE4:
    // 0x80016FE4: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x80016FE8: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80016FEC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80016FF0: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x80016FF4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80016FF8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80016FFC: bne         $v0, $s1, L_80016FE4
    if (ctx->r2 != ctx->r17) {
        // 0x80017000: swc1        $f6, 0x40($t6)
        MEM_W(0X40, ctx->r14) = ctx->f6.u32l;
            goto L_80016FE4;
    }
    // 0x80017000: swc1        $f6, 0x40($t6)
    MEM_W(0X40, ctx->r14) = ctx->f6.u32l;
    // 0x80017004: b           L_80017034
    // 0x80017008: nop

        goto L_80017034;
    // 0x80017008: nop

L_8001700C:
    // 0x8001700C: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80017010: addiu       $a0, $a0, -0x6690
    ctx->r4 = ADD32(ctx->r4, -0X6690);
L_80017014:
    // 0x80017014: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80017018: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8001701C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80017020: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80017024: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80017028: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8001702C: bne         $v0, $s1, L_80017014
    if (ctx->r2 != ctx->r17) {
        // 0x80017030: swc1        $f8, 0x40($t8)
        MEM_W(0X40, ctx->r24) = ctx->f8.u32l;
            goto L_80017014;
    }
    // 0x80017030: swc1        $f8, 0x40($t8)
    MEM_W(0X40, ctx->r24) = ctx->f8.u32l;
L_80017034:
    // 0x80017034: lwc1        $f10, 0x629C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X629C);
    // 0x80017038: addiu       $a0, $sp, 0xA0
    ctx->r4 = ADD32(ctx->r29, 0XA0);
    // 0x8001703C: jal         0x80022440
    // 0x80017040: add.s       $f22, $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f10.fl;
    func_80022440(rdram, ctx);
        goto after_72;
    // 0x80017040: add.s       $f22, $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f10.fl;
    after_72:
    // 0x80017044: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    // 0x80017048: lw          $v0, 0x8($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X8);
    // 0x8001704C: lw          $t0, 0xD8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XD8);
    // 0x80017050: ori         $t1, $t0, 0x8001
    ctx->r9 = ctx->r8 | 0X8001;
    // 0x80017054: sw          $t1, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r9;
    // 0x80017058: lw          $t2, 0x0($s6)
    ctx->r10 = MEM_W(ctx->r22, 0X0);
    // 0x8001705C: swc1        $f22, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f22.u32l;
    // 0x80017060: beq         $s4, $t2, L_800170E0
    if (ctx->r20 == ctx->r10) {
        // 0x80017064: nop
    
            goto L_800170E0;
    }
    // 0x80017064: nop

    // 0x80017068: beq         $s5, $zero, L_8001707C
    if (ctx->r21 == 0) {
        // 0x8001706C: addiu       $s5, $s5, -0x1
        ctx->r21 = ADD32(ctx->r21, -0X1);
            goto L_8001707C;
    }
    // 0x8001706C: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x80017070: sll         $t3, $s5, 16
    ctx->r11 = S32(ctx->r21 << 16);
    // 0x80017074: b           L_800170E0
    // 0x80017078: sra         $s5, $t3, 16
    ctx->r21 = S32(SIGNED(ctx->r11) >> 16);
        goto L_800170E0;
    // 0x80017078: sra         $s5, $t3, 16
    ctx->r21 = S32(SIGNED(ctx->r11) >> 16);
L_8001707C:
    // 0x8001707C: jal         0x8000E35C
    // 0x80017080: nop

    func_8000E35C(rdram, ctx);
        goto after_73;
    // 0x80017080: nop

    after_73:
    // 0x80017084: andi        $t5, $v0, 0x7F
    ctx->r13 = ctx->r2 & 0X7F;
    // 0x80017088: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x8001708C: lui         $at, 0xC280
    ctx->r1 = S32(0XC280 << 16);
    // 0x80017090: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80017094: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80017098: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8001709C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800170A0: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x800170A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800170A8: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x800170AC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800170B0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800170B4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800170B8: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    // 0x800170BC: swc1        $f6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f6.u32l;
    // 0x800170C0: jal         0x80043714
    // 0x800170C4: swc1        $f10, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f10.u32l;
    func_80043714(rdram, ctx);
        goto after_74;
    // 0x800170C4: swc1        $f10, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f10.u32l;
    after_74:
    // 0x800170C8: jal         0x8000E35C
    // 0x800170CC: nop

    func_8000E35C(rdram, ctx);
        goto after_75;
    // 0x800170CC: nop

    after_75:
    // 0x800170D0: andi        $s5, $v0, 0x7F
    ctx->r21 = ctx->r2 & 0X7F;
    // 0x800170D4: addiu       $s5, $s5, 0x14
    ctx->r21 = ADD32(ctx->r21, 0X14);
    // 0x800170D8: sll         $t6, $s5, 16
    ctx->r14 = S32(ctx->r21 << 16);
    // 0x800170DC: sra         $s5, $t6, 16
    ctx->r21 = S32(SIGNED(ctx->r14) >> 16);
L_800170E0:
    // 0x800170E0: jal         0x8000798C
    // 0x800170E4: nop

    func_8000798C(rdram, ctx);
        goto after_76;
    // 0x800170E4: nop

    after_76:
    // 0x800170E8: b           L_80016E3C
    // 0x800170EC: lw          $t7, 0x0($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X0);
        goto L_80016E3C;
    // 0x800170EC: lw          $t7, 0x0($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X0);
    // 0x800170F0: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x800170F4: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800170F8: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800170FC: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80017100: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80017104: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80017108: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8001710C: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80017110: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80017114: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80017118: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8001711C: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x80017120: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x80017124: jr          $ra
    // 0x80017128: addiu       $sp, $sp, 0x240
    ctx->r29 = ADD32(ctx->r29, 0X240);
    TRACE_RETURN()
    return;
    // 0x80017128: addiu       $sp, $sp, 0x240
    ctx->r29 = ADD32(ctx->r29, 0X240);
    // 0x8001712C: nop

indirect_80017130:
    // 0x80017130: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80017134: addiu       $v0, $v0, -0x662C
    ctx->r2 = ADD32(ctx->r2, -0X662C);
    // 0x80017138: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8001713C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80017140: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
    // 0x80017144: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80017148: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001714C: bne         $v1, $t6, L_80017174
    if (ctx->r3 != ctx->r14) {
        // 0x80017150: sw          $a0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r4;
            goto L_80017174;
    }
    // 0x80017150: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80017154: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80017158: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001715C: sh          $a0, -0x6B80($at)
    MEM_H(-0X6B80, ctx->r1) = ctx->r4;
    // 0x80017160: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // 0x80017164: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80017168: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8001716C: b           L_80017190
    // 0x80017170: sw          $t7, -0x6630($at)
    MEM_W(-0X6630, ctx->r1) = ctx->r15;
        goto L_80017190;
    // 0x80017170: sw          $t7, -0x6630($at)
    MEM_W(-0X6630, ctx->r1) = ctx->r15;
L_80017174:
    // 0x80017174: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80017178: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001717C: sh          $t8, -0x6B80($at)
    MEM_H(-0X6B80, ctx->r1) = ctx->r24;
    // 0x80017180: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80017184: sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
    // 0x80017188: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8001718C: sw          $a0, -0x6630($at)
    MEM_W(-0X6630, ctx->r1) = ctx->r4;
L_80017190:
    // 0x80017190: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80017194: lui         $a0, 0x8002
    ctx->r4 = S32(0X8002 << 16);
    // 0x80017198: addiu       $a0, $a0, -0x423C
    ctx->r4 = ADD32(ctx->r4, -0X423C);
    // 0x8001719C: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x800171A0: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x800171A4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x800171A8: jal         0x80004CE0
    // 0x800171AC: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    func_80004CE0(rdram, ctx);
        goto after_77;
    // 0x800171AC: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    after_77:
    // 0x800171B0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800171B4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
L_800171B8:
    // 0x800171B8: bne         $t0, $zero, L_80017248
    if (ctx->r8 != 0) {
        // 0x800171BC: nop
    
            goto L_80017248;
    }
    // 0x800171BC: nop

    // 0x800171C0: jal         0x80004E5C
    // 0x800171C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80004E5C(rdram, ctx);
        goto after_78;
    // 0x800171C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_78:
    // 0x800171C8: jal         0x8000798C
    // 0x800171CC: nop

    func_8000798C(rdram, ctx);
        goto after_79;
    // 0x800171CC: nop

    after_79:
    // 0x800171D0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800171D4: sh          $zero, -0x6B80($at)
    MEM_H(-0X6B80, ctx->r1) = 0;
    // 0x800171D8: jal         0x80044514
    // 0x800171DC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_80044514(rdram, ctx);
        goto after_80;
    // 0x800171DC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_80:
    // 0x800171E0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800171E4:
    // 0x800171E4: jal         0x8000798C
    // 0x800171E8: nop

    func_8000798C(rdram, ctx);
        goto after_81;
    // 0x800171E8: nop

    after_81:
    // 0x800171EC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800171F0: sll         $t1, $s0, 16
    ctx->r9 = S32(ctx->r16 << 16);
    // 0x800171F4: sra         $s0, $t1, 16
    ctx->r16 = S32(SIGNED(ctx->r9) >> 16);
    // 0x800171F8: slti        $at, $s0, 0x32
    ctx->r1 = SIGNED(ctx->r16) < 0X32 ? 1 : 0;
    // 0x800171FC: bne         $at, $zero, L_800171E4
    if (ctx->r1 != 0) {
        // 0x80017200: nop
    
            goto L_800171E4;
    }
    // 0x80017200: nop

    // 0x80017204: jal         0x80044480
    // 0x80017208: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    func_80044480(rdram, ctx);
        goto after_82;
    // 0x80017208: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    after_82:
    // 0x8001720C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80017210:
    // 0x80017210: jal         0x8000798C
    // 0x80017214: nop

    func_8000798C(rdram, ctx);
        goto after_83;
    // 0x80017214: nop

    after_83:
    // 0x80017218: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001721C: sll         $t3, $s0, 16
    ctx->r11 = S32(ctx->r16 << 16);
    // 0x80017220: sra         $s0, $t3, 16
    ctx->r16 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80017224: slti        $at, $s0, 0x5A
    ctx->r1 = SIGNED(ctx->r16) < 0X5A ? 1 : 0;
    // 0x80017228: bne         $at, $zero, L_80017210
    if (ctx->r1 != 0) {
        // 0x8001722C: nop
    
            goto L_80017210;
    }
    // 0x8001722C: nop

    // 0x80017230: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80017234: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
L_80017238:
    // 0x80017238: jal         0x8000798C
    // 0x8001723C: nop

    func_8000798C(rdram, ctx);
        goto after_84;
    // 0x8001723C: nop

    after_84:
    // 0x80017240: b           L_80017238
    // 0x80017244: nop

        goto L_80017238;
    // 0x80017244: nop

L_80017248:
    // 0x80017248: jal         0x8000798C
    // 0x8001724C: nop

    func_8000798C(rdram, ctx);
        goto after_85;
    // 0x8001724C: nop

    after_85:
    // 0x80017250: b           L_800171B8
    // 0x80017254: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
        goto L_800171B8;
    // 0x80017254: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80017258: nop

    // 0x8001725C: nop

    // 0x80017260: nop

    // 0x80017264: nop

    // 0x80017268: nop

    // 0x8001726C: nop

    // 0x80017270: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80017274: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80017278: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001727C: jr          $ra
    // 0x80017280: nop

    TRACE_RETURN()
    return;
    // 0x80017280: nop

    // 0x80017284: nop

    // 0x80017288: nop

    // 0x8001728C: nop

indirect_80017290:
    // 0x80017290: addiu       $sp, $sp, -0x140
    ctx->r29 = ADD32(ctx->r29, -0X140);
    // 0x80017294: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x80017298: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    // 0x8001729C: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x800172A0: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x800172A4: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x800172A8: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x800172AC: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x800172B0: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800172B4: sw          $a0, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r4;
    // 0x800172B8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800172BC: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x800172C0: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x800172C4: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x800172C8: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x800172CC: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x800172D0: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x800172D4: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x800172D8: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x800172DC: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800172E0: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800172E4: sh          $zero, 0x12C($sp)
    MEM_H(0X12C, ctx->r29) = 0;
    // 0x800172E8: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800172EC: sh          $zero, 0x128($sp)
    MEM_H(0X128, ctx->r29) = 0;
    // 0x800172F0: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x800172F4: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x800172F8: sw          $t6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r14;
    // 0x800172FC: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
    // 0x80017300: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80017304: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80017308: mov.s       $f22, $f30
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    ctx->f22.fl = ctx->f30.fl;
    // 0x8001730C: jal         0x8004D134
    // 0x80017310: swc1        $f30, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f30.u32l;
    func_8004D134(rdram, ctx);
        goto after_86;
    // 0x80017310: swc1        $f30, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f30.u32l;
    after_86:
    // 0x80017314: lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // 0x80017318: addiu       $a0, $a0, -0x3900
    ctx->r4 = ADD32(ctx->r4, -0X3900);
    // 0x8001731C: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    // 0x80017320: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80017324: jal         0x80004CE0
    // 0x80017328: addiu       $a3, $sp, 0x9C
    ctx->r7 = ADD32(ctx->r29, 0X9C);
    func_80004CE0(rdram, ctx);
        goto after_87;
    // 0x80017328: addiu       $a3, $sp, 0x9C
    ctx->r7 = ADD32(ctx->r29, 0X9C);
    after_87:
    // 0x8001732C: sw          $v0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r2;
    // 0x80017330: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x80017334: jal         0x800499B0
    // 0x80017338: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800499B0(rdram, ctx);
        goto after_88;
    // 0x80017338: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_88:
    // 0x8001733C: jal         0x8004B1E0
    // 0x80017340: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_8004B1E0(rdram, ctx);
        goto after_89;
    // 0x80017340: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_89:
    // 0x80017344: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80017348: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001734C: jal         0x8000BD4C
    // 0x80017350: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BD4C(rdram, ctx);
        goto after_90;
    // 0x80017350: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_90:
    // 0x80017354: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80017358: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001735C: jal         0x8000BDEC
    // 0x80017360: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BDEC(rdram, ctx);
        goto after_91;
    // 0x80017360: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_91:
    // 0x80017364: addiu       $t7, $zero, 0x3E8
    ctx->r15 = ADD32(0, 0X3E8);
    // 0x80017368: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001736C: sw          $t7, -0x2CF8($at)
    MEM_W(-0X2CF8, ctx->r1) = ctx->r15;
    // 0x80017370: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80017374: addiu       $t8, $zero, 0x3D0
    ctx->r24 = ADD32(0, 0X3D0);
    // 0x80017378: sw          $t8, -0x2CF4($at)
    MEM_W(-0X2CF4, ctx->r1) = ctx->r24;
    // 0x8001737C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80017380: sh          $zero, -0x2CC4($at)
    MEM_H(-0X2CC4, ctx->r1) = 0;
    // 0x80017384: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80017388: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8001738C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80017390: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80017394: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x80017398: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8001739C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800173A0: addiu       $s7, $s7, -0x6C50
    ctx->r23 = ADD32(ctx->r23, -0X6C50);
    // 0x800173A4: addiu       $v0, $v0, -0x6C40
    ctx->r2 = ADD32(ctx->r2, -0X6C40);
    // 0x800173A8: swc1        $f0, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->f0.u32l;
    // 0x800173AC: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x800173B0: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x800173B4: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x800173B8: swc1        $f4, 0x4($s7)
    MEM_W(0X4, ctx->r23) = ctx->f4.u32l;
    // 0x800173BC: jal         0x8000798C
    // 0x800173C0: swc1        $f6, 0x8($s7)
    MEM_W(0X8, ctx->r23) = ctx->f6.u32l;
    func_8000798C(rdram, ctx);
        goto after_92;
    // 0x800173C0: swc1        $f6, 0x8($s7)
    MEM_W(0X8, ctx->r23) = ctx->f6.u32l;
    after_92:
    // 0x800173C4: jal         0x8000798C
    // 0x800173C8: nop

    func_8000798C(rdram, ctx);
        goto after_93;
    // 0x800173C8: nop

    after_93:
    // 0x800173CC: jal         0x8000798C
    // 0x800173D0: nop

    func_8000798C(rdram, ctx);
        goto after_94;
    // 0x800173D0: nop

    after_94:
    // 0x800173D4: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x800173D8: jal         0x80049CFC
    // 0x800173DC: addiu       $a0, $a0, 0x62A0
    ctx->r4 = ADD32(ctx->r4, 0X62A0);
    func_80049CFC(rdram, ctx);
        goto after_95;
    // 0x800173DC: addiu       $a0, $a0, 0x62A0
    ctx->r4 = ADD32(ctx->r4, 0X62A0);
    after_95:
    // 0x800173E0: jal         0x80049D80
    // 0x800173E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80049D80(rdram, ctx);
        goto after_96;
    // 0x800173E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_96:
    // 0x800173E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800173EC: jal         0x80049DFC
    // 0x800173F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80049DFC(rdram, ctx);
        goto after_97;
    // 0x800173F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_97:
    // 0x800173F4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800173F8: jal         0x8004A148
    // 0x800173FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8004A148(rdram, ctx);
        goto after_98;
    // 0x800173FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_98:
    // 0x80017400: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80017404: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80017408: lw          $t9, 0xD8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XD8);
    // 0x8001740C: ori         $t2, $t9, 0x8001
    ctx->r10 = ctx->r25 | 0X8001;
    // 0x80017410: jal         0x80007EC8
    // 0x80017414: sw          $t2, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r10;
    func_80007EC8(rdram, ctx);
        goto after_99;
    // 0x80017414: sw          $t2, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r10;
    after_99:
    // 0x80017418: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001741C: lwc1        $f24, 0x62A8($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X62A8);
    // 0x80017420: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80017424: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80017428: lwc1        $f28, 0xB0($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x8001742C: lwc1        $f26, 0xD0($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x80017430: lh          $s4, 0xA6($sp)
    ctx->r20 = MEM_H(ctx->r29, 0XA6);
    // 0x80017434: addiu       $s2, $sp, 0xC0
    ctx->r18 = ADD32(ctx->r29, 0XC0);
    // 0x80017438: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x8001743C: lh          $t3, 0x128($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X128);
L_80017440:
    // 0x80017440: lw          $t4, 0x9C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X9C);
    // 0x80017444: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80017448: beq         $t3, $zero, L_800174DC
    if (ctx->r11 == 0) {
        // 0x8001744C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800174DC;
    }
    // 0x8001744C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80017450: bne         $t4, $at, L_800174DC
    if (ctx->r12 != ctx->r1) {
        // 0x80017454: nop
    
            goto L_800174DC;
    }
    // 0x80017454: nop

    // 0x80017458: jal         0x8004A0C4
    // 0x8001745C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8004A0C4(rdram, ctx);
        goto after_100;
    // 0x8001745C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_100:
    // 0x80017460: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80017464: jal         0x8004C4D8
    // 0x80017468: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004C4D8(rdram, ctx);
        goto after_101;
    // 0x80017468: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_101:
    // 0x8001746C: jal         0x80049C48
    // 0x80017470: nop

    func_80049C48(rdram, ctx);
        goto after_102;
    // 0x80017470: nop

    after_102:
    // 0x80017474: jal         0x8004B21C
    // 0x80017478: nop

    func_8004B21C(rdram, ctx);
        goto after_103;
    // 0x80017478: nop

    after_103:
    // 0x8001747C: jal         0x80004E5C
    // 0x80017480: lw          $a0, 0x98($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X98);
    func_80004E5C(rdram, ctx);
        goto after_104;
    // 0x80017480: lw          $a0, 0x98($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X98);
    after_104:
    // 0x80017484: jal         0x8000798C
    // 0x80017488: nop

    func_8000798C(rdram, ctx);
        goto after_105;
    // 0x80017488: nop

    after_105:
    // 0x8001748C: bnel        $s3, $zero, L_800174C0
    if (ctx->r19 != 0) {
        // 0x80017490: lw          $t6, 0x140($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X140);
            goto L_800174C0;
    }
    goto skip_7;
    // 0x80017490: lw          $t6, 0x140($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X140);
    skip_7:
    // 0x80017494: jal         0x80044480
    // 0x80017498: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    func_80044480(rdram, ctx);
        goto after_106;
    // 0x80017498: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_106:
    // 0x8001749C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800174A0: addiu       $s0, $zero, 0xA
    ctx->r16 = ADD32(0, 0XA);
L_800174A4:
    // 0x800174A4: jal         0x8000798C
    // 0x800174A8: sw          $a0, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r4;
    func_8000798C(rdram, ctx);
        goto after_107;
    // 0x800174A8: sw          $a0, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r4;
    after_107:
    // 0x800174AC: lw          $a0, 0x13C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X13C);
    // 0x800174B0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800174B4: bne         $a0, $s0, L_800174A4
    if (ctx->r4 != ctx->r16) {
        // 0x800174B8: nop
    
            goto L_800174A4;
    }
    // 0x800174B8: nop

    // 0x800174BC: lw          $t6, 0x140($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X140);
L_800174C0:
    // 0x800174C0: addiu       $t5, $s3, 0x1
    ctx->r13 = ADD32(ctx->r19, 0X1);
    // 0x800174C4: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x800174C8: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
L_800174CC:
    // 0x800174CC: jal         0x8000798C
    // 0x800174D0: nop

    func_8000798C(rdram, ctx);
        goto after_108;
    // 0x800174D0: nop

    after_108:
    // 0x800174D4: b           L_800174CC
    // 0x800174D8: nop

        goto L_800174CC;
    // 0x800174D8: nop

L_800174DC:
    // 0x800174DC: beq         $s6, $zero, L_80017644
    if (ctx->r22 == 0) {
        // 0x800174E0: addiu       $a1, $zero, 0x44
        ctx->r5 = ADD32(0, 0X44);
            goto L_80017644;
    }
    // 0x800174E0: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    // 0x800174E4: lh          $t9, 0x12C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X12C);
    // 0x800174E8: sll         $t0, $s3, 16
    ctx->r8 = S32(ctx->r19 << 16);
    // 0x800174EC: sra         $t4, $t0, 16
    ctx->r12 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800174F0: sll         $t2, $t9, 24
    ctx->r10 = S32(ctx->r25 << 24);
    // 0x800174F4: sra         $a2, $t2, 16
    ctx->r6 = S32(SIGNED(ctx->r10) >> 16);
    // 0x800174F8: or          $t0, $t4, $zero
    ctx->r8 = ctx->r12 | 0;
    // 0x800174FC: sh          $t4, 0x130($sp)
    MEM_H(0X130, ctx->r29) = ctx->r12;
    // 0x80017500: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80017504: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80017508: jal         0x8004C580
    // 0x8001750C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_109;
    // 0x8001750C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_109:
    // 0x80017510: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80017514: lh          $t5, 0x12C($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X12C);
    // 0x80017518: lhu         $v1, -0x2E5A($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2E5A);
    // 0x8001751C: lh          $t0, 0x130($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X130);
    // 0x80017520: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x80017524: andi        $t7, $v1, 0x200
    ctx->r15 = ctx->r3 & 0X200;
    // 0x80017528: bne         $t7, $zero, L_80017548
    if (ctx->r15 != 0) {
        // 0x8001752C: sh          $t6, 0x12C($sp)
        MEM_H(0X12C, ctx->r29) = ctx->r14;
            goto L_80017548;
    }
    // 0x8001752C: sh          $t6, 0x12C($sp)
    MEM_H(0X12C, ctx->r29) = ctx->r14;
    // 0x80017530: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80017534: lh          $v0, -0x2E4C($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2E4C);
    // 0x80017538: andi        $t9, $v1, 0x100
    ctx->r25 = ctx->r3 & 0X100;
    // 0x8001753C: andi        $t8, $v0, 0x200
    ctx->r24 = ctx->r2 & 0X200;
    // 0x80017540: beq         $t8, $zero, L_80017550
    if (ctx->r24 == 0) {
        // 0x80017544: nop
    
            goto L_80017550;
    }
    // 0x80017544: nop

L_80017548:
    // 0x80017548: b           L_80017564
    // 0x8001754C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
        goto L_80017564;
    // 0x8001754C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80017550:
    // 0x80017550: bne         $t9, $zero, L_80017560
    if (ctx->r25 != 0) {
        // 0x80017554: andi        $t2, $v0, 0x100
        ctx->r10 = ctx->r2 & 0X100;
            goto L_80017560;
    }
    // 0x80017554: andi        $t2, $v0, 0x100
    ctx->r10 = ctx->r2 & 0X100;
    // 0x80017558: beq         $t2, $zero, L_80017564
    if (ctx->r10 == 0) {
        // 0x8001755C: nop
    
            goto L_80017564;
    }
    // 0x8001755C: nop

L_80017560:
    // 0x80017560: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80017564:
    // 0x80017564: beql        $t0, $s3, L_80017578
    if (ctx->r8 == ctx->r19) {
        // 0x80017568: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80017578;
    }
    goto skip_8;
    // 0x80017568: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_8:
    // 0x8001756C: jal         0x80044480
    // 0x80017570: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    func_80044480(rdram, ctx);
        goto after_110;
    // 0x80017570: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_110:
    // 0x80017574: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_80017578:
    // 0x80017578: bne         $s3, $at, L_80017588
    if (ctx->r19 != ctx->r1) {
        // 0x8001757C: addiu       $a0, $zero, -0x52
        ctx->r4 = ADD32(0, -0X52);
            goto L_80017588;
    }
    // 0x8001757C: addiu       $a0, $zero, -0x52
    ctx->r4 = ADD32(0, -0X52);
    // 0x80017580: b           L_8001758C
    // 0x80017584: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
        goto L_8001758C;
    // 0x80017584: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80017588:
    // 0x80017588: addiu       $v0, $zero, 0x60
    ctx->r2 = ADD32(0, 0X60);
L_8001758C:
    // 0x8001758C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80017590: sll         $t3, $a2, 24
    ctx->r11 = S32(ctx->r6 << 24);
    // 0x80017594: sra         $a2, $t3, 16
    ctx->r6 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80017598: addiu       $a1, $zero, -0x4D
    ctx->r5 = ADD32(0, -0X4D);
    // 0x8001759C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800175A0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800175A4: jal         0x8004C580
    // 0x800175A8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_111;
    // 0x800175A8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_111:
    // 0x800175AC: bne         $s3, $zero, L_800175CC
    if (ctx->r19 != 0) {
        // 0x800175B0: addiu       $a0, $zero, 0x52
        ctx->r4 = ADD32(0, 0X52);
            goto L_800175CC;
    }
    // 0x800175B0: addiu       $a0, $zero, 0x52
    ctx->r4 = ADD32(0, 0X52);
    // 0x800175B4: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x800175B8: addiu       $t6, $t6, -0x6670
    ctx->r14 = ADD32(ctx->r14, -0X6670);
    // 0x800175BC: sll         $t5, $s3, 2
    ctx->r13 = S32(ctx->r19 << 2);
    // 0x800175C0: addu        $t0, $t5, $t6
    ctx->r8 = ADD32(ctx->r13, ctx->r14);
    // 0x800175C4: b           L_800175E0
    // 0x800175C8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
        goto L_800175E0;
    // 0x800175C8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_800175CC:
    // 0x800175CC: lui         $t8, 0x8007
    ctx->r24 = S32(0X8007 << 16);
    // 0x800175D0: addiu       $t8, $t8, -0x6670
    ctx->r24 = ADD32(ctx->r24, -0X6670);
    // 0x800175D4: sll         $t7, $s3, 2
    ctx->r15 = S32(ctx->r19 << 2);
    // 0x800175D8: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x800175DC: addiu       $v0, $zero, 0x60
    ctx->r2 = ADD32(0, 0X60);
L_800175E0:
    // 0x800175E0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800175E4: sll         $t9, $a2, 24
    ctx->r25 = S32(ctx->r6 << 24);
    // 0x800175E8: sra         $a2, $t9, 16
    ctx->r6 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800175EC: addiu       $a1, $zero, -0x4D
    ctx->r5 = ADD32(0, -0X4D);
    // 0x800175F0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800175F4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800175F8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800175FC: jal         0x8004C580
    // 0x80017600: sw          $t0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r8;
    func_8004C580(rdram, ctx);
        goto after_112;
    // 0x80017600: sw          $t0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r8;
    after_112:
    // 0x80017604: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
    // 0x80017608: sll         $a3, $s1, 16
    ctx->r7 = S32(ctx->r17 << 16);
    // 0x8001760C: sra         $t5, $a3, 16
    ctx->r13 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80017610: lh          $v1, 0x0($t0)
    ctx->r3 = MEM_H(ctx->r8, 0X0);
    // 0x80017614: lh          $t1, 0x2($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X2);
    // 0x80017618: or          $a3, $t5, $zero
    ctx->r7 = ctx->r13 | 0;
    // 0x8001761C: sll         $a0, $v1, 16
    ctx->r4 = S32(ctx->r3 << 16);
    // 0x80017620: sll         $a1, $t1, 16
    ctx->r5 = S32(ctx->r9 << 16);
    // 0x80017624: sra         $t4, $a1, 16
    ctx->r12 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80017628: sra         $t3, $a0, 16
    ctx->r11 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001762C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x80017630: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x80017634: addiu       $a2, $zero, -0x100
    ctx->r6 = ADD32(0, -0X100);
    // 0x80017638: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001763C: jal         0x8004C580
    // 0x80017640: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_113;
    // 0x80017640: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_113:
L_80017644:
    // 0x80017644: beq         $s5, $zero, L_80017668
    if (ctx->r21 == 0) {
        // 0x80017648: lui         $at, 0xC1A0
        ctx->r1 = S32(0XC1A0 << 16);
            goto L_80017668;
    }
    // 0x80017648: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x8001764C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80017650: beq         $s5, $at, L_80017688
    if (ctx->r21 == ctx->r1) {
        // 0x80017654: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80017688;
    }
    // 0x80017654: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80017658: beql        $s5, $at, L_80017784
    if (ctx->r21 == ctx->r1) {
        // 0x8001765C: sub.s       $f18, $f26, $f22
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f26.fl - ctx->f22.fl;
            goto L_80017784;
    }
    goto skip_9;
    // 0x8001765C: sub.s       $f18, $f26, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f26.fl - ctx->f22.fl;
    skip_9:
    // 0x80017660: b           L_800178BC
    // 0x80017664: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
        goto L_800178BC;
    // 0x80017664: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80017668:
    // 0x80017668: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001766C: lui         $at, 0xC234
    ctx->r1 = S32(0XC234 << 16);
    // 0x80017670: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80017674: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80017678: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x8001767C: swc1        $f10, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f10.u32l;
    // 0x80017680: swc1        $f8, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f8.u32l;
    // 0x80017684: swc1        $f16, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f16.u32l;
L_80017688:
    // 0x80017688: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001768C: lwc1        $f18, 0x62AC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X62AC);
    // 0x80017690: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x80017694: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80017698: sub.s       $f22, $f22, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = ctx->f22.fl - ctx->f18.fl;
    // 0x8001769C: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x800176A0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800176A4: c.lt.s      $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f22.fl < ctx->f4.fl;
    // 0x800176A8: nop

    // 0x800176AC: bc1f        L_800176D4
    if (!c1cs) {
        // 0x800176B0: nop
    
            goto L_800176D4;
    }
    // 0x800176B0: nop

    // 0x800176B4: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x800176B8: lui         $at, 0xC268
    ctx->r1 = S32(0XC268 << 16);
    // 0x800176BC: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x800176C0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800176C4: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x800176C8: addiu       $s4, $zero, 0x78
    ctx->r20 = ADD32(0, 0X78);
    // 0x800176CC: b           L_80017728
    // 0x800176D0: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
        goto L_80017728;
    // 0x800176D0: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
L_800176D4:
    // 0x800176D4: lhu         $t6, -0x2E5A($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X2E5A);
    // 0x800176D8: andi        $t7, $t6, 0x9000
    ctx->r15 = ctx->r14 & 0X9000;
    // 0x800176DC: beql        $t7, $zero, L_800178BC
    if (ctx->r15 == 0) {
        // 0x800176E0: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_800178BC;
    }
    goto skip_10;
    // 0x800176E0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_10:
    // 0x800176E4: beq         $s3, $zero, L_80017710
    if (ctx->r19 == 0) {
        // 0x800176E8: addiu       $s5, $zero, 0x2
        ctx->r21 = ADD32(0, 0X2);
            goto L_80017710;
    }
    // 0x800176E8: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x800176EC: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x800176F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800176F4: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x800176F8: lwc1        $f28, 0x4($s7)
    ctx->f28.u32l = MEM_W(ctx->r23, 0X4);
    // 0x800176FC: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x80017700: addiu       $s4, $zero, 0x78
    ctx->r20 = ADD32(0, 0X78);
    // 0x80017704: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x80017708: b           L_80017738
    // 0x8001770C: swc1        $f6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f6.u32l;
        goto L_80017738;
    // 0x8001770C: swc1        $f6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f6.u32l;
L_80017710:
    // 0x80017710: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x80017714: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80017718: lui         $at, 0xC268
    ctx->r1 = S32(0XC268 << 16);
    // 0x8001771C: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80017720: addiu       $s4, $zero, 0x78
    ctx->r20 = ADD32(0, 0X78);
    // 0x80017724: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
L_80017728:
    // 0x80017728: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x8001772C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80017730: nop

    // 0x80017734: swc1        $f8, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f8.u32l;
L_80017738:
    // 0x80017738: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x8001773C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80017740: lwc1        $f16, 0xC0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x80017744: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80017748: swc1        $f10, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f10.u32l;
    // 0x8001774C: jal         0x80044514
    // 0x80017750: swc1        $f16, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f16.u32l;
    func_80044514(rdram, ctx);
        goto after_114;
    // 0x80017750: swc1        $f16, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f16.u32l;
    after_114:
    // 0x80017754: beql        $s3, $zero, L_80017768
    if (ctx->r19 == 0) {
        // 0x80017758: addiu       $a0, $zero, 0x3B
        ctx->r4 = ADD32(0, 0X3B);
            goto L_80017768;
    }
    goto skip_11;
    // 0x80017758: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    skip_11:
    // 0x8001775C: b           L_80017768
    // 0x80017760: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
        goto L_80017768;
    // 0x80017760: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    // 0x80017764: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
L_80017768:
    // 0x80017768: jal         0x80044480
    // 0x8001776C: nop

    func_80044480(rdram, ctx);
        goto after_115;
    // 0x8001776C: nop

    after_115:
    // 0x80017770: jal         0x80007E20
    // 0x80017774: nop

    func_80007E20(rdram, ctx);
        goto after_116;
    // 0x80017774: nop

    after_116:
    // 0x80017778: b           L_800178BC
    // 0x8001777C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
        goto L_800178BC;
    // 0x8001777C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80017780: sub.s       $f18, $f26, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f26.fl - ctx->f22.fl;
L_80017784:
    // 0x80017784: addiu       $v0, $sp, 0xC0
    ctx->r2 = ADD32(ctx->r29, 0XC0);
    // 0x80017788: addiu       $v1, $sp, 0xB4
    ctx->r3 = ADD32(ctx->r29, 0XB4);
    // 0x8001778C: div.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80017790: add.s       $f22, $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f4.fl;
    // 0x80017794: lwc1        $f14, 0x0($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80017798: lwc1        $f30, 0x0($v0)
    ctx->f30.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001779C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800177A0: beq         $v1, $s2, L_800177CC
    if (ctx->r3 == ctx->r18) {
        // 0x800177A4: sub.s       $f18, $f14, $f30
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f18.fl = ctx->f14.fl - ctx->f30.fl;
            goto L_800177CC;
    }
    // 0x800177A4: sub.s       $f18, $f14, $f30
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f18.fl = ctx->f14.fl - ctx->f30.fl;
L_800177A8:
    // 0x800177A8: div.s       $f16, $f18, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = DIV_S(ctx->f18.fl, ctx->f20.fl);
    // 0x800177AC: lwc1        $f14, 0x0($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800177B0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800177B4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800177B8: add.s       $f16, $f30, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f30.fl + ctx->f16.fl;
    // 0x800177BC: lwc1        $f30, 0x0($v0)
    ctx->f30.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800177C0: sub.s       $f18, $f14, $f30
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f18.fl = ctx->f14.fl - ctx->f30.fl;
    // 0x800177C4: bne         $v1, $s2, L_800177A8
    if (ctx->r3 != ctx->r18) {
        // 0x800177C8: swc1        $f16, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
            goto L_800177A8;
    }
    // 0x800177C8: swc1        $f16, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
L_800177CC:
    // 0x800177CC: div.s       $f16, $f18, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = DIV_S(ctx->f18.fl, ctx->f20.fl);
    // 0x800177D0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800177D4: add.s       $f16, $f30, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f30.fl + ctx->f16.fl;
    // 0x800177D8: swc1        $f16, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
    // 0x800177DC: lwc1        $f0, 0x4($s7)
    ctx->f0.u32l = MEM_W(ctx->r23, 0X4);
    // 0x800177E0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800177E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800177E8: sub.s       $f18, $f28, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f28.fl - ctx->f0.fl;
    // 0x800177EC: lwc1        $f12, 0xA8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800177F0: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800177F4: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x800177F8: jal         0x8004F7C0
    // 0x800177FC: swc1        $f8, 0x4($s7)
    MEM_W(0X4, ctx->r23) = ctx->f8.u32l;
    func_8004F7C0(rdram, ctx);
        goto after_117;
    // 0x800177FC: swc1        $f8, 0x4($s7)
    MEM_W(0X4, ctx->r23) = ctx->f8.u32l;
    after_117:
    // 0x80017800: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80017804: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80017808: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001780C: add.s       $f18, $f16, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f24.fl;
    // 0x80017810: mul.s       $f30, $f0, $f10
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f30.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80017814: beq         $s4, $zero, L_8001784C
    if (ctx->r20 == 0) {
        // 0x80017818: swc1        $f18, 0xA8($sp)
        MEM_W(0XA8, ctx->r29) = ctx->f18.u32l;
            goto L_8001784C;
    }
    // 0x80017818: swc1        $f18, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f18.u32l;
    // 0x8001781C: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x80017820: sll         $t8, $s4, 16
    ctx->r24 = S32(ctx->r20 << 16);
    // 0x80017824: sra         $s4, $t8, 16
    ctx->r20 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80017828: bne         $s4, $zero, L_8001784C
    if (ctx->r20 != 0) {
        // 0x8001782C: addiu       $a0, $zero, 0xF
        ctx->r4 = ADD32(0, 0XF);
            goto L_8001784C;
    }
    // 0x8001782C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80017830: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80017834: sh          $t2, 0x128($sp)
    MEM_H(0X128, ctx->r29) = ctx->r10;
    // 0x80017838: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001783C: jal         0x8004D134
    // 0x80017840: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_8004D134(rdram, ctx);
        goto after_118;
    // 0x80017840: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_118:
    // 0x80017844: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80017848: sw          $t3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r11;
L_8001784C:
    // 0x8001784C: lui         $at, 0xC03D
    ctx->r1 = S32(0XC03D << 16);
    // 0x80017850: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80017854: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80017858: cvt.d.s     $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); 
    ctx->f0.d = CVT_D_S(ctx->f30.fl);
    // 0x8001785C: lui         $at, 0x403D
    ctx->r1 = S32(0X403D << 16);
    // 0x80017860: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x80017864: nop

    // 0x80017868: bc1fl       L_8001789C
    if (!c1cs) {
        // 0x8001786C: mtc1        $at, $f7
        ctx->f_odd[(7 - 1) * 2] = ctx->r1;
            goto L_8001789C;
    }
    goto skip_12;
    // 0x8001786C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    skip_12:
    // 0x80017870: bne         $fp, $zero, L_800178B8
    if (ctx->r30 != 0) {
        // 0x80017874: addiu       $a0, $zero, 0x5
        ctx->r4 = ADD32(0, 0X5);
            goto L_800178B8;
    }
    // 0x80017874: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80017878: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001787C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80017880: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80017884: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80017888: jal         0x8000ACEC
    // 0x8001788C: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    func_8000ACEC(rdram, ctx);
        goto after_119;
    // 0x8001788C: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    after_119:
    // 0x80017890: b           L_800178BC
    // 0x80017894: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
        goto L_800178BC;
    // 0x80017894: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80017898: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
L_8001789C:
    // 0x8001789C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800178A0: nop

    // 0x800178A4: c.lt.d      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.d < ctx->f0.d;
    // 0x800178A8: nop

    // 0x800178AC: bc1fl       L_800178BC
    if (!c1cs) {
        // 0x800178B0: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_800178BC;
    }
    goto skip_13;
    // 0x800178B0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_13:
    // 0x800178B4: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
L_800178B8:
    // 0x800178B8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_800178BC:
    // 0x800178BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800178C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800178C4: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x800178C8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800178CC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800178D0: addiu       $a0, $sp, 0xD8
    ctx->r4 = ADD32(ctx->r29, 0XD8);
    // 0x800178D4: jal         0x80049840
    // 0x800178D8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_80049840(rdram, ctx);
        goto after_120;
    // 0x800178D8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_120:
    // 0x800178DC: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x800178E0: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x800178E4: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x800178E8: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x800178EC: jal         0x80001AB4
    // 0x800178F0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80001AB4(rdram, ctx);
        goto after_121;
    // 0x800178F0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_121:
    // 0x800178F4: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x800178F8: addiu       $a2, $sp, 0xD8
    ctx->r6 = ADD32(ctx->r29, 0XD8);
    // 0x800178FC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80017900: jal         0x80000BD8
    // 0x80017904: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_80000BD8(rdram, ctx);
        goto after_122;
    // 0x80017904: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_122:
    // 0x80017908: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001790C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80017910: addiu       $v0, $sp, 0xC0
    ctx->r2 = ADD32(ctx->r29, 0XC0);
L_80017914:
    // 0x80017914: lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8);
    // 0x80017918: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001791C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80017920: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x80017924: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80017928: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001792C: bne         $a0, $s1, L_80017914
    if (ctx->r4 != ctx->r17) {
        // 0x80017930: swc1        $f10, 0x40($t5)
        MEM_W(0X40, ctx->r13) = ctx->f10.u32l;
            goto L_80017914;
    }
    // 0x80017930: swc1        $f10, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f10.u32l;
    // 0x80017934: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80017938: lwc1        $f16, 0x44($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8001793C: add.s       $f18, $f16, $f30
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f30.fl;
    // 0x80017940: jal         0x8000798C
    // 0x80017944: swc1        $f18, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f18.u32l;
    func_8000798C(rdram, ctx);
        goto after_123;
    // 0x80017944: swc1        $f18, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f18.u32l;
    after_123:
    // 0x80017948: b           L_80017440
    // 0x8001794C: lh          $t3, 0x128($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X128);
        goto L_80017440;
    // 0x8001794C: lh          $t3, 0x128($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X128);
    // 0x80017950: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x80017954: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80017958: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8001795C: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80017960: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80017964: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x80017968: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x8001796C: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80017970: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x80017974: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x80017978: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x8001797C: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x80017980: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x80017984: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x80017988: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x8001798C: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x80017990: jr          $ra
    // 0x80017994: addiu       $sp, $sp, 0x140
    ctx->r29 = ADD32(ctx->r29, 0X140);
    TRACE_RETURN()
    return;
    // 0x80017994: addiu       $sp, $sp, 0x140
    ctx->r29 = ADD32(ctx->r29, 0X140);
    // 0x80017998: nop

    // 0x8001799C: nop

indirect_800179A0:
    // 0x800179A0: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800179A4: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x800179A8: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x800179AC: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800179B0: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800179B4: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800179B8: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800179BC: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800179C0: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800179C4: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800179C8: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x800179CC: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x800179D0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800179D4: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800179D8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800179DC: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x800179E0: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800179E4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800179E8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800179EC: addiu       $fp, $fp, -0x2E4C
    ctx->r30 = ADD32(ctx->r30, -0X2E4C);
    // 0x800179F0: addiu       $s7, $s7, -0x2E5A
    ctx->r23 = ADD32(ctx->r23, -0X2E5A);
    // 0x800179F4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800179F8: lh          $s5, 0x68($sp)
    ctx->r21 = MEM_H(ctx->r29, 0X68);
    // 0x800179FC: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
L_80017A00:
    // 0x80017A00: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
L_80017A04:
    // 0x80017A04: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80017A08: jal         0x8004D134
    // 0x80017A0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004D134(rdram, ctx);
        goto after_124;
    // 0x80017A0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_124:
    // 0x80017A10: jal         0x8004B1E0
    // 0x80017A14: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_8004B1E0(rdram, ctx);
        goto after_125;
    // 0x80017A14: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_125:
    // 0x80017A18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80017A1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80017A20: jal         0x8000BD4C
    // 0x80017A24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BD4C(rdram, ctx);
        goto after_126;
    // 0x80017A24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_126:
    // 0x80017A28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80017A2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80017A30: jal         0x8000BDEC
    // 0x80017A34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BDEC(rdram, ctx);
        goto after_127;
    // 0x80017A34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_127:
    // 0x80017A38: addiu       $t6, $zero, 0x3E8
    ctx->r14 = ADD32(0, 0X3E8);
    // 0x80017A3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80017A40: sw          $t6, -0x2CF8($at)
    MEM_W(-0X2CF8, ctx->r1) = ctx->r14;
    // 0x80017A44: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80017A48: addiu       $t7, $zero, 0x3D0
    ctx->r15 = ADD32(0, 0X3D0);
    // 0x80017A4C: sw          $t7, -0x2CF4($at)
    MEM_W(-0X2CF4, ctx->r1) = ctx->r15;
    // 0x80017A50: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80017A54: sh          $zero, -0x2CC4($at)
    MEM_H(-0X2CC4, ctx->r1) = 0;
    // 0x80017A58: lui         $at, 0x4238
    ctx->r1 = S32(0X4238 << 16);
    // 0x80017A5C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80017A60: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80017A64: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80017A68: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80017A6C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80017A70: addiu       $v1, $v1, -0x6C40
    ctx->r3 = ADD32(ctx->r3, -0X6C40);
    // 0x80017A74: addiu       $v0, $v0, -0x6C50
    ctx->r2 = ADD32(ctx->r2, -0X6C50);
    // 0x80017A78: swc1        $f20, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f20.u32l;
    // 0x80017A7C: swc1        $f20, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f20.u32l;
    // 0x80017A80: swc1        $f20, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f20.u32l;
    // 0x80017A84: swc1        $f20, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f20.u32l;
    // 0x80017A88: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80017A8C: jal         0x8000798C
    // 0x80017A90: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    func_8000798C(rdram, ctx);
        goto after_128;
    // 0x80017A90: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    after_128:
    // 0x80017A94: jal         0x8000798C
    // 0x80017A98: nop

    func_8000798C(rdram, ctx);
        goto after_129;
    // 0x80017A98: nop

    after_129:
    // 0x80017A9C: jal         0x8000798C
    // 0x80017AA0: nop

    func_8000798C(rdram, ctx);
        goto after_130;
    // 0x80017AA0: nop

    after_130:
    // 0x80017AA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80017AA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80017AAC: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x80017AB0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80017AB4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80017AB8: jal         0x8004C580
    // 0x80017ABC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_131;
    // 0x80017ABC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_131:
    // 0x80017AC0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80017AC4: addiu       $a1, $zero, 0x57
    ctx->r5 = ADD32(0, 0X57);
    // 0x80017AC8: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x80017ACC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80017AD0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80017AD4: jal         0x8004C580
    // 0x80017AD8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_132;
    // 0x80017AD8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_132:
    // 0x80017ADC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80017AE0: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    // 0x80017AE4: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x80017AE8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80017AEC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80017AF0: jal         0x8004C580
    // 0x80017AF4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_133;
    // 0x80017AF4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_133:
    // 0x80017AF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80017AFC: addiu       $a1, $zero, -0x6
    ctx->r5 = ADD32(0, -0X6);
    // 0x80017B00: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x80017B04: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80017B08: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80017B0C: jal         0x8004C580
    // 0x80017B10: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_134;
    // 0x80017B10: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_134:
    // 0x80017B14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80017B18: addiu       $a1, $zero, -0x45
    ctx->r5 = ADD32(0, -0X45);
    // 0x80017B1C: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x80017B20: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80017B24: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80017B28: jal         0x8004C580
    // 0x80017B2C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_135;
    // 0x80017B2C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_135:
    // 0x80017B30: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80017B34: lh          $t8, -0x6B90($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X6B90);
    // 0x80017B38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80017B3C: addiu       $a1, $zero, -0x61
    ctx->r5 = ADD32(0, -0X61);
    // 0x80017B40: bne         $t8, $zero, L_80017B50
    if (ctx->r24 != 0) {
        // 0x80017B44: addiu       $a2, $zero, -0xFF
        ctx->r6 = ADD32(0, -0XFF);
            goto L_80017B50;
    }
    // 0x80017B44: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x80017B48: b           L_80017B54
    // 0x80017B4C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
        goto L_80017B54;
    // 0x80017B4C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
L_80017B50:
    // 0x80017B50: addiu       $a3, $zero, 0xB
    ctx->r7 = ADD32(0, 0XB);
L_80017B54:
    // 0x80017B54: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80017B58: jal         0x8004C580
    // 0x80017B5C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_136;
    // 0x80017B5C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_136:
L_80017B60:
    // 0x80017B60: beq         $s2, $zero, L_80017B8C
    if (ctx->r18 == 0) {
        // 0x80017B64: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80017B8C;
    }
    // 0x80017B64: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80017B68: beql        $s2, $at, L_80017BA8
    if (ctx->r18 == ctx->r1) {
        // 0x80017B6C: lhu         $v1, 0x0($s7)
        ctx->r3 = MEM_HU(ctx->r23, 0X0);
            goto L_80017BA8;
    }
    goto skip_14;
    // 0x80017B6C: lhu         $v1, 0x0($s7)
    ctx->r3 = MEM_HU(ctx->r23, 0X0);
    skip_14:
    // 0x80017B70: beq         $s2, $s6, L_80017CF8
    if (ctx->r18 == ctx->r22) {
        // 0x80017B74: addiu       $a0, $zero, 0x15
        ctx->r4 = ADD32(0, 0X15);
            goto L_80017CF8;
    }
    // 0x80017B74: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x80017B78: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80017B7C: beq         $s2, $at, L_80017D18
    if (ctx->r18 == ctx->r1) {
        // 0x80017B80: nop
    
            goto L_80017D18;
    }
    // 0x80017B80: nop

    // 0x80017B84: b           L_80017F40
    // 0x80017B88: slti        $at, $s1, 0x2
    ctx->r1 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
        goto L_80017F40;
    // 0x80017B88: slti        $at, $s1, 0x2
    ctx->r1 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
L_80017B8C:
    // 0x80017B8C: jal         0x8004D1F0
    // 0x80017B90: nop

    func_8004D1F0(rdram, ctx);
        goto after_137;
    // 0x80017B90: nop

    after_137:
    // 0x80017B94: bnel        $v0, $zero, L_80017F40
    if (ctx->r2 != 0) {
        // 0x80017B98: slti        $at, $s1, 0x2
        ctx->r1 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
            goto L_80017F40;
    }
    goto skip_15;
    // 0x80017B98: slti        $at, $s1, 0x2
    ctx->r1 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
    skip_15:
    // 0x80017B9C: b           L_80017F3C
    // 0x80017BA0: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
        goto L_80017F3C;
    // 0x80017BA0: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80017BA4: lhu         $v1, 0x0($s7)
    ctx->r3 = MEM_HU(ctx->r23, 0X0);
L_80017BA8:
    // 0x80017BA8: sll         $t0, $s1, 2
    ctx->r8 = S32(ctx->r17 << 2);
    // 0x80017BAC: sll         $t1, $s3, 1
    ctx->r9 = S32(ctx->r19 << 1);
    // 0x80017BB0: andi        $t9, $v1, 0x9000
    ctx->r25 = ctx->r3 & 0X9000;
    // 0x80017BB4: beq         $t9, $zero, L_80017C18
    if (ctx->r25 == 0) {
        // 0x80017BB8: addu        $t2, $t0, $t1
        ctx->r10 = ADD32(ctx->r8, ctx->r9);
            goto L_80017C18;
    }
    // 0x80017BB8: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80017BBC: lui         $s5, 0x8007
    ctx->r21 = S32(0X8007 << 16);
    // 0x80017BC0: addu        $s5, $s5, $t2
    ctx->r21 = ADD32(ctx->r21, ctx->r10);
    // 0x80017BC4: lh          $s5, -0x664C($s5)
    ctx->r21 = MEM_H(ctx->r21, -0X664C);
    // 0x80017BC8: addiu       $t3, $s5, -0x1
    ctx->r11 = ADD32(ctx->r21, -0X1);
    // 0x80017BCC: sltiu       $at, $t3, 0x5
    ctx->r1 = ctx->r11 < 0X5 ? 1 : 0;
    // 0x80017BD0: beq         $at, $zero, L_80017C18
    if (ctx->r1 == 0) {
        // 0x80017BD4: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_80017C18;
    }
    // 0x80017BD4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80017BD8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80017BDC: addu        $at, $at, $t3
    gpr jr_addend_80017BE4 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80017BE0: lw          $t3, 0x62B0($at)
    ctx->r11 = ADD32(ctx->r1, 0X62B0);
    // 0x80017BE4: jr          $t3
    // 0x80017BE8: nop

    switch (jr_addend_80017BE4 >> 2) {
        case 0: goto L_80017BEC; break;
        case 1: goto L_80017BEC; break;
        case 2: goto L_80017BFC; break;
        case 3: goto L_80017BFC; break;
        case 4: goto L_80017C0C; break;
        default: switch_error(__func__, 0x80017BE4, 0x800762B0);
    }
    // 0x80017BE8: nop

L_80017BEC:
    // 0x80017BEC: sll         $s2, $s6, 16
    ctx->r18 = S32(ctx->r22 << 16);
    // 0x80017BF0: sra         $t4, $s2, 16
    ctx->r12 = S32(SIGNED(ctx->r18) >> 16);
    // 0x80017BF4: b           L_80017C18
    // 0x80017BF8: or          $s2, $t4, $zero
    ctx->r18 = ctx->r12 | 0;
        goto L_80017C18;
    // 0x80017BF8: or          $s2, $t4, $zero
    ctx->r18 = ctx->r12 | 0;
L_80017BFC:
    // 0x80017BFC: sll         $s2, $s6, 16
    ctx->r18 = S32(ctx->r22 << 16);
    // 0x80017C00: sra         $t5, $s2, 16
    ctx->r13 = S32(SIGNED(ctx->r18) >> 16);
    // 0x80017C04: b           L_80017C18
    // 0x80017C08: or          $s2, $t5, $zero
    ctx->r18 = ctx->r13 | 0;
        goto L_80017C18;
    // 0x80017C08: or          $s2, $t5, $zero
    ctx->r18 = ctx->r13 | 0;
L_80017C0C:
    // 0x80017C0C: sll         $s2, $s6, 16
    ctx->r18 = S32(ctx->r22 << 16);
    // 0x80017C10: sra         $t6, $s2, 16
    ctx->r14 = S32(SIGNED(ctx->r18) >> 16);
    // 0x80017C14: or          $s2, $t6, $zero
    ctx->r18 = ctx->r14 | 0;
L_80017C18:
    // 0x80017C18: sll         $a1, $s1, 16
    ctx->r5 = S32(ctx->r17 << 16);
    // 0x80017C1C: sra         $t7, $a1, 16
    ctx->r15 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80017C20: andi        $t8, $v1, 0x400
    ctx->r24 = ctx->r3 & 0X400;
    // 0x80017C24: bne         $t8, $zero, L_80017C3C
    if (ctx->r24 != 0) {
        // 0x80017C28: or          $a1, $t7, $zero
        ctx->r5 = ctx->r15 | 0;
            goto L_80017C3C;
    }
    // 0x80017C28: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80017C2C: lh          $v0, 0x0($fp)
    ctx->r2 = MEM_H(ctx->r30, 0X0);
    // 0x80017C30: andi        $t2, $v1, 0x800
    ctx->r10 = ctx->r3 & 0X800;
    // 0x80017C34: andi        $t9, $v0, 0x400
    ctx->r25 = ctx->r2 & 0X400;
    // 0x80017C38: beq         $t9, $zero, L_80017C58
    if (ctx->r25 == 0) {
        // 0x80017C3C: slti        $at, $s1, 0x2
        ctx->r1 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
            goto L_80017C58;
    }
L_80017C3C:
    // 0x80017C3C: slti        $at, $s1, 0x2
    ctx->r1 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
    // 0x80017C40: beq         $at, $zero, L_80017C7C
    if (ctx->r1 == 0) {
        // 0x80017C44: nop
    
            goto L_80017C7C;
    }
    // 0x80017C44: nop

    // 0x80017C48: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80017C4C: sll         $t0, $s1, 16
    ctx->r8 = S32(ctx->r17 << 16);
    // 0x80017C50: b           L_80017C7C
    // 0x80017C54: sra         $s1, $t0, 16
    ctx->r17 = S32(SIGNED(ctx->r8) >> 16);
        goto L_80017C7C;
    // 0x80017C54: sra         $s1, $t0, 16
    ctx->r17 = S32(SIGNED(ctx->r8) >> 16);
L_80017C58:
    // 0x80017C58: bne         $t2, $zero, L_80017C68
    if (ctx->r10 != 0) {
        // 0x80017C5C: andi        $t3, $v0, 0x800
        ctx->r11 = ctx->r2 & 0X800;
            goto L_80017C68;
    }
    // 0x80017C5C: andi        $t3, $v0, 0x800
    ctx->r11 = ctx->r2 & 0X800;
    // 0x80017C60: beq         $t3, $zero, L_80017C7C
    if (ctx->r11 == 0) {
        // 0x80017C64: nop
    
            goto L_80017C7C;
    }
    // 0x80017C64: nop

L_80017C68:
    // 0x80017C68: blez        $s1, L_80017C7C
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80017C6C: nop
    
            goto L_80017C7C;
    }
    // 0x80017C6C: nop

    // 0x80017C70: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80017C74: sll         $t4, $s1, 16
    ctx->r12 = S32(ctx->r17 << 16);
    // 0x80017C78: sra         $s1, $t4, 16
    ctx->r17 = S32(SIGNED(ctx->r12) >> 16);
L_80017C7C:
    // 0x80017C7C: beq         $a1, $s1, L_80017C8C
    if (ctx->r5 == ctx->r17) {
        // 0x80017C80: addiu       $a0, $zero, 0x13
        ctx->r4 = ADD32(0, 0X13);
            goto L_80017C8C;
    }
    // 0x80017C80: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    // 0x80017C84: jal         0x80044480
    // 0x80017C88: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    func_80044480(rdram, ctx);
        goto after_138;
    // 0x80017C88: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    after_138:
L_80017C8C:
    // 0x80017C8C: slti        $at, $s1, 0x2
    ctx->r1 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
    // 0x80017C90: beql        $at, $zero, L_80017F40
    if (ctx->r1 == 0) {
        // 0x80017C94: slti        $at, $s1, 0x2
        ctx->r1 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
            goto L_80017F40;
    }
    goto skip_16;
    // 0x80017C94: slti        $at, $s1, 0x2
    ctx->r1 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
    skip_16:
    // 0x80017C98: lhu         $v1, 0x0($s7)
    ctx->r3 = MEM_HU(ctx->r23, 0X0);
    // 0x80017C9C: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x80017CA0: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80017CA4: andi        $t7, $v1, 0x200
    ctx->r15 = ctx->r3 & 0X200;
    // 0x80017CA8: bne         $t7, $zero, L_80017CC4
    if (ctx->r15 != 0) {
        // 0x80017CAC: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_80017CC4;
    }
    // 0x80017CAC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80017CB0: lh          $v0, 0x0($fp)
    ctx->r2 = MEM_H(ctx->r30, 0X0);
    // 0x80017CB4: andi        $t9, $v1, 0x100
    ctx->r25 = ctx->r3 & 0X100;
    // 0x80017CB8: andi        $t8, $v0, 0x200
    ctx->r24 = ctx->r2 & 0X200;
    // 0x80017CBC: beq         $t8, $zero, L_80017CCC
    if (ctx->r24 == 0) {
        // 0x80017CC0: nop
    
            goto L_80017CCC;
    }
    // 0x80017CC0: nop

L_80017CC4:
    // 0x80017CC4: b           L_80017CE0
    // 0x80017CC8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
        goto L_80017CE0;
    // 0x80017CC8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80017CCC:
    // 0x80017CCC: bne         $t9, $zero, L_80017CDC
    if (ctx->r25 != 0) {
        // 0x80017CD0: andi        $t0, $v0, 0x100
        ctx->r8 = ctx->r2 & 0X100;
            goto L_80017CDC;
    }
    // 0x80017CD0: andi        $t0, $v0, 0x100
    ctx->r8 = ctx->r2 & 0X100;
    // 0x80017CD4: beq         $t0, $zero, L_80017CE0
    if (ctx->r8 == 0) {
        // 0x80017CD8: nop
    
            goto L_80017CE0;
    }
    // 0x80017CD8: nop

L_80017CDC:
    // 0x80017CDC: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80017CE0:
    // 0x80017CE0: beql        $a0, $s3, L_80017F40
    if (ctx->r4 == ctx->r19) {
        // 0x80017CE4: slti        $at, $s1, 0x2
        ctx->r1 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
            goto L_80017F40;
    }
    goto skip_17;
    // 0x80017CE4: slti        $at, $s1, 0x2
    ctx->r1 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
    skip_17:
    // 0x80017CE8: jal         0x80044480
    // 0x80017CEC: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    func_80044480(rdram, ctx);
        goto after_139;
    // 0x80017CEC: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_139:
    // 0x80017CF0: b           L_80017F40
    // 0x80017CF4: slti        $at, $s1, 0x2
    ctx->r1 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
        goto L_80017F40;
    // 0x80017CF4: slti        $at, $s1, 0x2
    ctx->r1 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
L_80017CF8:
    // 0x80017CF8: jal         0x80044480
    // 0x80017CFC: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    func_80044480(rdram, ctx);
        goto after_140;
    // 0x80017CFC: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    after_140:
    // 0x80017D00: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80017D04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80017D08: jal         0x8004D134
    // 0x80017D0C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_8004D134(rdram, ctx);
        goto after_141;
    // 0x80017D0C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_141:
    // 0x80017D10: b           L_80017F40
    // 0x80017D14: slti        $at, $s1, 0x2
    ctx->r1 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
        goto L_80017F40;
    // 0x80017D14: slti        $at, $s1, 0x2
    ctx->r1 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
L_80017D18:
    // 0x80017D18: jal         0x8004D1F0
    // 0x80017D1C: nop

    func_8004D1F0(rdram, ctx);
        goto after_142;
    // 0x80017D1C: nop

    after_142:
    // 0x80017D20: bne         $v0, $zero, L_80017F3C
    if (ctx->r2 != 0) {
        // 0x80017D24: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80017F3C;
    }
    // 0x80017D24: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80017D28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80017D2C: jal         0x8004C4D8
    // 0x80017D30: or          $s0, $s5, $zero
    ctx->r16 = ctx->r21 | 0;
    func_8004C4D8(rdram, ctx);
        goto after_143;
    // 0x80017D30: or          $s0, $s5, $zero
    ctx->r16 = ctx->r21 | 0;
    after_143:
    // 0x80017D34: jal         0x8004B21C
    // 0x80017D38: nop

    func_8004B21C(rdram, ctx);
        goto after_144;
    // 0x80017D38: nop

    after_144:
    // 0x80017D3C: jal         0x8000798C
    // 0x80017D40: nop

    func_8000798C(rdram, ctx);
        goto after_145;
    // 0x80017D40: nop

    after_145:
    // 0x80017D44: addiu       $t1, $s0, -0x1
    ctx->r9 = ADD32(ctx->r16, -0X1);
    // 0x80017D48: sltiu       $at, $t1, 0x5
    ctx->r1 = ctx->r9 < 0X5 ? 1 : 0;
    // 0x80017D4C: beq         $at, $zero, L_80017F3C
    if (ctx->r1 == 0) {
        // 0x80017D50: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_80017F3C;
    }
    // 0x80017D50: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80017D54: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80017D58: addu        $at, $at, $t1
    gpr jr_addend_80017D60 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80017D5C: lw          $t1, 0x62C4($at)
    ctx->r9 = ADD32(ctx->r1, 0X62C4);
    // 0x80017D60: jr          $t1
    // 0x80017D64: nop

    switch (jr_addend_80017D60 >> 2) {
        case 0: goto L_80017D68; break;
        case 1: goto L_80017D68; break;
        case 2: goto L_80017D80; break;
        case 3: goto L_80017E28; break;
        case 4: goto L_80017EDC; break;
        default: switch_error(__func__, 0x80017D60, 0x800762C4);
    }
    // 0x80017D64: nop

L_80017D68:
    // 0x80017D68: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x80017D6C: sw          $s5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r21;
L_80017D70:
    // 0x80017D70: jal         0x8000798C
    // 0x80017D74: nop

    func_8000798C(rdram, ctx);
        goto after_146;
    // 0x80017D74: nop

    after_146:
    // 0x80017D78: b           L_80017D70
    // 0x80017D7C: nop

        goto L_80017D70;
    // 0x80017D7C: nop

L_80017D80:
    // 0x80017D80: lui         $a0, 0x8002
    ctx->r4 = S32(0X8002 << 16);
    // 0x80017D84: addiu       $a0, $a0, -0x6AFC
    ctx->r4 = ADD32(ctx->r4, -0X6AFC);
    // 0x80017D88: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80017D8C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80017D90: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80017D94: jal         0x80004CE0
    // 0x80017D98: addiu       $a3, $sp, 0x60
    ctx->r7 = ADD32(ctx->r29, 0X60);
    func_80004CE0(rdram, ctx);
        goto after_147;
    // 0x80017D98: addiu       $a3, $sp, 0x60
    ctx->r7 = ADD32(ctx->r29, 0X60);
    after_147:
    // 0x80017D9C: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x80017DA0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80017DA4: bne         $t5, $s6, L_80017DC0
    if (ctx->r13 != ctx->r22) {
        // 0x80017DA8: nop
    
            goto L_80017DC0;
    }
    // 0x80017DA8: nop

L_80017DAC:
    // 0x80017DAC: jal         0x8000798C
    // 0x80017DB0: nop

    func_8000798C(rdram, ctx);
        goto after_148;
    // 0x80017DB0: nop

    after_148:
    // 0x80017DB4: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x80017DB8: beq         $t6, $s6, L_80017DAC
    if (ctx->r14 == ctx->r22) {
        // 0x80017DBC: nop
    
            goto L_80017DAC;
    }
    // 0x80017DBC: nop

L_80017DC0:
    // 0x80017DC0: jal         0x80004E5C
    // 0x80017DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80004E5C(rdram, ctx);
        goto after_149;
    // 0x80017DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_149:
    // 0x80017DC8: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x80017DCC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80017DD0: bnel        $t7, $at, L_80017DE4
    if (ctx->r15 != ctx->r1) {
        // 0x80017DD4: sll         $a1, $zero, 16
        ctx->r5 = S32(0 << 16);
            goto L_80017DE4;
    }
    goto skip_18;
    // 0x80017DD4: sll         $a1, $zero, 16
    ctx->r5 = S32(0 << 16);
    skip_18:
    // 0x80017DD8: b           L_80017A00
    // 0x80017DDC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
        goto L_80017A00;
    // 0x80017DDC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80017DE0: sll         $a1, $zero, 16
    ctx->r5 = S32(0 << 16);
L_80017DE4:
    // 0x80017DE4: sll         $a0, $zero, 16
    ctx->r4 = S32(0 << 16);
    // 0x80017DE8: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80017DEC: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80017DF0: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80017DF4: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x80017DF8: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80017DFC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80017E00: addiu       $a3, $zero, 0xB
    ctx->r7 = ADD32(0, 0XB);
    // 0x80017E04: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80017E08: jal         0x8000798C
    // 0x80017E0C: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    func_8000798C(rdram, ctx);
        goto after_150;
    // 0x80017E0C: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    after_150:
    // 0x80017E10: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x80017E14: sw          $s5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r21;
L_80017E18:
    // 0x80017E18: jal         0x8000798C
    // 0x80017E1C: nop

    func_8000798C(rdram, ctx);
        goto after_151;
    // 0x80017E1C: nop

    after_151:
    // 0x80017E20: b           L_80017E18
    // 0x80017E24: nop

        goto L_80017E18;
    // 0x80017E24: nop

L_80017E28:
    // 0x80017E28: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80017E2C: lui         $a0, 0x8002
    ctx->r4 = S32(0X8002 << 16);
    // 0x80017E30: addiu       $a0, $a0, -0x52C8
    ctx->r4 = ADD32(ctx->r4, -0X52C8);
    // 0x80017E34: sw          $t1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r9;
    // 0x80017E38: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80017E3C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80017E40: jal         0x80004CE0
    // 0x80017E44: addiu       $a3, $sp, 0x60
    ctx->r7 = ADD32(ctx->r29, 0X60);
    func_80004CE0(rdram, ctx);
        goto after_152;
    // 0x80017E44: addiu       $a3, $sp, 0x60
    ctx->r7 = ADD32(ctx->r29, 0X60);
    after_152:
    // 0x80017E48: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80017E4C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80017E50: beq         $t2, $zero, L_80017E6C
    if (ctx->r10 == 0) {
        // 0x80017E54: nop
    
            goto L_80017E6C;
    }
    // 0x80017E54: nop

L_80017E58:
    // 0x80017E58: jal         0x8000798C
    // 0x80017E5C: nop

    func_8000798C(rdram, ctx);
        goto after_153;
    // 0x80017E5C: nop

    after_153:
    // 0x80017E60: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x80017E64: bne         $t3, $zero, L_80017E58
    if (ctx->r11 != 0) {
        // 0x80017E68: nop
    
            goto L_80017E58;
    }
    // 0x80017E68: nop

L_80017E6C:
    // 0x80017E6C: jal         0x80004E5C
    // 0x80017E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80004E5C(rdram, ctx);
        goto after_154;
    // 0x80017E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_154:
    // 0x80017E74: jal         0x8000798C
    // 0x80017E78: nop

    func_8000798C(rdram, ctx);
        goto after_155;
    // 0x80017E78: nop

    after_155:
    // 0x80017E7C: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80017E80: lw          $t4, -0x6630($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X6630);
    // 0x80017E84: bnel        $t4, $zero, L_80017E98
    if (ctx->r12 != 0) {
        // 0x80017E88: sll         $a1, $zero, 16
        ctx->r5 = S32(0 << 16);
            goto L_80017E98;
    }
    goto skip_19;
    // 0x80017E88: sll         $a1, $zero, 16
    ctx->r5 = S32(0 << 16);
    skip_19:
    // 0x80017E8C: b           L_80017A00
    // 0x80017E90: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
        goto L_80017A00;
    // 0x80017E90: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80017E94: sll         $a1, $zero, 16
    ctx->r5 = S32(0 << 16);
L_80017E98:
    // 0x80017E98: sll         $a0, $zero, 16
    ctx->r4 = S32(0 << 16);
    // 0x80017E9C: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80017EA0: sra         $t5, $a1, 16
    ctx->r13 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80017EA4: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x80017EA8: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80017EAC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80017EB0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80017EB4: addiu       $a3, $zero, 0xB
    ctx->r7 = ADD32(0, 0XB);
    // 0x80017EB8: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80017EBC: jal         0x8000798C
    // 0x80017EC0: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    func_8000798C(rdram, ctx);
        goto after_156;
    // 0x80017EC0: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    after_156:
    // 0x80017EC4: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x80017EC8: sw          $s5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r21;
L_80017ECC:
    // 0x80017ECC: jal         0x8000798C
    // 0x80017ED0: nop

    func_8000798C(rdram, ctx);
        goto after_157;
    // 0x80017ED0: nop

    after_157:
    // 0x80017ED4: b           L_80017ECC
    // 0x80017ED8: nop

        goto L_80017ECC;
    // 0x80017ED8: nop

L_80017EDC:
    // 0x80017EDC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80017EE0: lui         $a0, 0x8002
    ctx->r4 = S32(0X8002 << 16);
    // 0x80017EE4: addiu       $a0, $a0, -0x7F40
    ctx->r4 = ADD32(ctx->r4, -0X7F40);
    // 0x80017EE8: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x80017EEC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80017EF0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80017EF4: jal         0x80004CE0
    // 0x80017EF8: addiu       $a3, $sp, 0x60
    ctx->r7 = ADD32(ctx->r29, 0X60);
    func_80004CE0(rdram, ctx);
        goto after_158;
    // 0x80017EF8: addiu       $a3, $sp, 0x60
    ctx->r7 = ADD32(ctx->r29, 0X60);
    after_158:
    // 0x80017EFC: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x80017F00: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80017F04: beql        $t9, $zero, L_80017F24
    if (ctx->r25 == 0) {
        // 0x80017F08: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80017F24;
    }
    goto skip_20;
    // 0x80017F08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_20:
L_80017F0C:
    // 0x80017F0C: jal         0x8000798C
    // 0x80017F10: nop

    func_8000798C(rdram, ctx);
        goto after_159;
    // 0x80017F10: nop

    after_159:
    // 0x80017F14: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x80017F18: bne         $t0, $zero, L_80017F0C
    if (ctx->r8 != 0) {
        // 0x80017F1C: nop
    
            goto L_80017F0C;
    }
    // 0x80017F1C: nop

    // 0x80017F20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80017F24:
    // 0x80017F24: jal         0x80004E5C
    // 0x80017F28: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    func_80004E5C(rdram, ctx);
        goto after_160;
    // 0x80017F28: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    after_160:
    // 0x80017F2C: jal         0x8000798C
    // 0x80017F30: nop

    func_8000798C(rdram, ctx);
        goto after_161;
    // 0x80017F30: nop

    after_161:
    // 0x80017F34: b           L_80017A04
    // 0x80017F38: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
        goto L_80017A04;
    // 0x80017F38: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
L_80017F3C:
    // 0x80017F3C: slti        $at, $s1, 0x2
    ctx->r1 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
L_80017F40:
    // 0x80017F40: beq         $at, $zero, L_80017FB8
    if (ctx->r1 == 0) {
        // 0x80017F44: sll         $t1, $s1, 2
        ctx->r9 = S32(ctx->r17 << 2);
            goto L_80017FB8;
    }
    // 0x80017F44: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x80017F48: lui         $t2, 0x8007
    ctx->r10 = S32(0X8007 << 16);
    // 0x80017F4C: lui         $t4, 0x8007
    ctx->r12 = S32(0X8007 << 16);
    // 0x80017F50: addiu       $t2, $t2, -0x6660
    ctx->r10 = ADD32(ctx->r10, -0X6660);
    // 0x80017F54: addiu       $t4, $t4, -0x6654
    ctx->r12 = ADD32(ctx->r12, -0X6654);
    // 0x80017F58: sll         $t3, $s3, 2
    ctx->r11 = S32(ctx->r19 << 2);
    // 0x80017F5C: addu        $s0, $t1, $t2
    ctx->r16 = ADD32(ctx->r9, ctx->r10);
    // 0x80017F60: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x80017F64: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80017F68: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    // 0x80017F6C: lh          $t5, 0x0($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X0);
    // 0x80017F70: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x80017F74: andi        $a2, $s4, 0x7F
    ctx->r6 = ctx->r20 & 0X7F;
    // 0x80017F78: addiu       $t1, $a2, 0x80
    ctx->r9 = ADD32(ctx->r6, 0X80);
    // 0x80017F7C: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x80017F80: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x80017F84: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80017F88: sll         $t9, $a1, 16
    ctx->r25 = S32(ctx->r5 << 16);
    // 0x80017F8C: sll         $t2, $t1, 24
    ctx->r10 = S32(ctx->r9 << 24);
    // 0x80017F90: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80017F94: sra         $a1, $t9, 16
    ctx->r5 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80017F98: sra         $a2, $t2, 16
    ctx->r6 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80017F9C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x80017FA0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80017FA4: jal         0x8004C580
    // 0x80017FA8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_162;
    // 0x80017FA8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_162:
    // 0x80017FAC: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80017FB0: sll         $t4, $s4, 16
    ctx->r12 = S32(ctx->r20 << 16);
    // 0x80017FB4: sra         $s4, $t4, 16
    ctx->r20 = S32(SIGNED(ctx->r12) >> 16);
L_80017FB8:
    // 0x80017FB8: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x80017FBC: addiu       $t7, $t7, -0x6660
    ctx->r15 = ADD32(ctx->r15, -0X6660);
    // 0x80017FC0: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x80017FC4: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x80017FC8: addiu       $a0, $zero, -0x44
    ctx->r4 = ADD32(0, -0X44);
    // 0x80017FCC: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x80017FD0: addiu       $a2, $zero, -0x100
    ctx->r6 = ADD32(0, -0X100);
    // 0x80017FD4: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x80017FD8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80017FDC: jal         0x8004C580
    // 0x80017FE0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_163;
    // 0x80017FE0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_163:
    // 0x80017FE4: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    // 0x80017FE8: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x80017FEC: addiu       $a2, $zero, -0x100
    ctx->r6 = ADD32(0, -0X100);
    // 0x80017FF0: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x80017FF4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80017FF8: jal         0x8004C580
    // 0x80017FFC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_164;
    // 0x80017FFC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_164:
    // 0x80018000: addiu       $a0, $zero, -0x44
    ctx->r4 = ADD32(0, -0X44);
    // 0x80018004: addiu       $a1, $zero, -0x20
    ctx->r5 = ADD32(0, -0X20);
    // 0x80018008: addiu       $a2, $zero, -0x100
    ctx->r6 = ADD32(0, -0X100);
    // 0x8001800C: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    // 0x80018010: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80018014: jal         0x8004C580
    // 0x80018018: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_165;
    // 0x80018018: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_165:
    // 0x8001801C: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    // 0x80018020: addiu       $a1, $zero, -0x20
    ctx->r5 = ADD32(0, -0X20);
    // 0x80018024: addiu       $a2, $zero, -0x100
    ctx->r6 = ADD32(0, -0X100);
    // 0x80018028: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x8001802C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80018030: jal         0x8004C580
    // 0x80018034: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_166;
    // 0x80018034: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_166:
    // 0x80018038: sll         $a3, $s6, 16
    ctx->r7 = S32(ctx->r22 << 16);
    // 0x8001803C: sra         $t8, $a3, 16
    ctx->r24 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80018040: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80018044: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    // 0x80018048: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x8001804C: addiu       $a2, $zero, -0x100
    ctx->r6 = ADD32(0, -0X100);
    // 0x80018050: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80018054: jal         0x8004C580
    // 0x80018058: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_167;
    // 0x80018058: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_167:
    // 0x8001805C: jal         0x8000798C
    // 0x80018060: nop

    func_8000798C(rdram, ctx);
        goto after_168;
    // 0x80018060: nop

    after_168:
    // 0x80018064: b           L_80017B60
    // 0x80018068: nop

        goto L_80017B60;
    // 0x80018068: nop

    // 0x8001806C: nop

    // 0x80018070: nop

    // 0x80018074: nop

    // 0x80018078: nop

    // 0x8001807C: nop

    // 0x80018080: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80018084: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80018088: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8001808C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80018090: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80018094: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80018098: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8001809C: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800180A0: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x800180A4: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x800180A8: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x800180AC: jr          $ra
    // 0x800180B0: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    TRACE_RETURN()
    return;
    // 0x800180B0: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x800180B4: nop

    // 0x800180B8: nop

    // 0x800180BC: nop

indirect_800180C0:
    // 0x800180C0: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x800180C4: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800180C8: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800180CC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800180D0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800180D4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800180D8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800180DC: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800180E0: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800180E4: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800180E8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800180EC: sw          $a0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r4;
    // 0x800180F0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800180F4: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x800180F8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800180FC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80018100: addiu       $s4, $sp, 0x68
    ctx->r20 = ADD32(ctx->r29, 0X68);
L_80018104:
    // 0x80018104: sll         $t6, $s0, 1
    ctx->r14 = S32(ctx->r16 << 1);
    // 0x80018108: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001810C: sll         $t8, $s0, 16
    ctx->r24 = S32(ctx->r16 << 16);
    // 0x80018110: sra         $s0, $t8, 16
    ctx->r16 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80018114: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x80018118: addu        $t7, $s4, $t6
    ctx->r15 = ADD32(ctx->r20, ctx->r14);
    // 0x8001811C: bne         $at, $zero, L_80018104
    if (ctx->r1 != 0) {
        // 0x80018120: sh          $zero, 0x0($t7)
        MEM_H(0X0, ctx->r15) = 0;
            goto L_80018104;
    }
    // 0x80018120: sh          $zero, 0x0($t7)
    MEM_H(0X0, ctx->r15) = 0;
    // 0x80018124: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80018128: addiu       $s1, $s1, -0x6B84
    ctx->r17 = ADD32(ctx->r17, -0X6B84);
    // 0x8001812C: lh          $t0, 0x0($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X0);
    // 0x80018130: lw          $t1, 0xB0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB0);
    // 0x80018134: sh          $zero, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = 0;
    // 0x80018138: sh          $t0, 0x7E($sp)
    MEM_H(0X7E, ctx->r29) = ctx->r8;
    // 0x8001813C: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80018140: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80018144: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80018148: bne         $t2, $at, L_800188FC
    if (ctx->r10 != ctx->r1) {
        // 0x8001814C: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_800188FC;
    }
    // 0x8001814C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80018150: jal         0x8004B1E0
    // 0x80018154: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8004B1E0(rdram, ctx);
        goto after_169;
    // 0x80018154: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_169:
    // 0x80018158: jal         0x8000798C
    // 0x8001815C: nop

    func_8000798C(rdram, ctx);
        goto after_170;
    // 0x8001815C: nop

    after_170:
    // 0x80018160: jal         0x8000798C
    // 0x80018164: nop

    func_8000798C(rdram, ctx);
        goto after_171;
    // 0x80018164: nop

    after_171:
    // 0x80018168: jal         0x8000798C
    // 0x8001816C: nop

    func_8000798C(rdram, ctx);
        goto after_172;
    // 0x8001816C: nop

    after_172:
    // 0x80018170: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80018174: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80018178: jal         0x8004C388
    // 0x8001817C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004C388(rdram, ctx);
        goto after_173;
    // 0x8001817C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_173:
    // 0x80018180: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80018184: addiu       $t3, $zero, 0x36
    ctx->r11 = ADD32(0, 0X36);
    // 0x80018188: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8001818C: addiu       $a2, $a2, 0x6394
    ctx->r6 = ADD32(ctx->r6, 0X6394);
    // 0x80018190: addiu       $a0, $zero, -0xFF
    ctx->r4 = ADD32(0, -0XFF);
    // 0x80018194: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80018198: jal         0x8004C340
    // 0x8001819C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8004C340(rdram, ctx);
        goto after_174;
    // 0x8001819C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_174:
    // 0x800181A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800181A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800181A8: jal         0x8001A37C
    // 0x800181AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8001A37C(rdram, ctx);
        goto after_175;
    // 0x800181AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_175:
    // 0x800181B0: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x800181B4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800181B8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800181BC: addiu       $a1, $a1, -0x6640
    ctx->r5 = ADD32(ctx->r5, -0X6640);
    // 0x800181C0: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x800181C4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800181C8: jal         0x80049660
    // 0x800181CC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_80049660(rdram, ctx);
        goto after_176;
    // 0x800181CC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_176:
    // 0x800181D0: jal         0x8000798C
    // 0x800181D4: nop

    func_8000798C(rdram, ctx);
        goto after_177;
    // 0x800181D4: nop

    after_177:
    // 0x800181D8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800181DC: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x800181E0: jal         0x8004C388
    // 0x800181E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004C388(rdram, ctx);
        goto after_178;
    // 0x800181E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_178:
    // 0x800181E8: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x800181EC: addiu       $a2, $a2, 0x63A4
    ctx->r6 = ADD32(ctx->r6, 0X63A4);
    // 0x800181F0: addiu       $a0, $zero, -0xFF
    ctx->r4 = ADD32(0, -0XFF);
    // 0x800181F4: jal         0x8004BCF0
    // 0x800181F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8004BCF0(rdram, ctx);
        goto after_179;
    // 0x800181F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_179:
    // 0x800181FC: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x80018200: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x80018204: jal         0x8004C388
    // 0x80018208: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004C388(rdram, ctx);
        goto after_180;
    // 0x80018208: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_180:
    // 0x8001820C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80018210: lw          $v0, 0x300($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X300);
    // 0x80018214: beq         $v0, $zero, L_80018238
    if (ctx->r2 == 0) {
        // 0x80018218: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80018238;
    }
    // 0x80018218: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001821C: beq         $v0, $at, L_80018254
    if (ctx->r2 == ctx->r1) {
        // 0x80018220: addiu       $a0, $zero, -0xFF
        ctx->r4 = ADD32(0, -0XFF);
            goto L_80018254;
    }
    // 0x80018220: addiu       $a0, $zero, -0xFF
    ctx->r4 = ADD32(0, -0XFF);
    // 0x80018224: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80018228: beq         $v0, $at, L_8001826C
    if (ctx->r2 == ctx->r1) {
        // 0x8001822C: addiu       $a0, $zero, -0xFF
        ctx->r4 = ADD32(0, -0XFF);
            goto L_8001826C;
    }
    // 0x8001822C: addiu       $a0, $zero, -0xFF
    ctx->r4 = ADD32(0, -0XFF);
    // 0x80018230: b           L_80018284
    // 0x80018234: addiu       $a0, $zero, -0xFF
    ctx->r4 = ADD32(0, -0XFF);
        goto L_80018284;
    // 0x80018234: addiu       $a0, $zero, -0xFF
    ctx->r4 = ADD32(0, -0XFF);
L_80018238:
    // 0x80018238: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x8001823C: addiu       $a2, $a2, 0x63B0
    ctx->r6 = ADD32(ctx->r6, 0X63B0);
    // 0x80018240: addiu       $a0, $zero, -0xFF
    ctx->r4 = ADD32(0, -0XFF);
    // 0x80018244: jal         0x8004BCF0
    // 0x80018248: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8004BCF0(rdram, ctx);
        goto after_181;
    // 0x80018248: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_181:
    // 0x8001824C: b           L_80018298
    // 0x80018250: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
        goto L_80018298;
    // 0x80018250: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_80018254:
    // 0x80018254: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80018258: addiu       $a2, $a2, 0x63B4
    ctx->r6 = ADD32(ctx->r6, 0X63B4);
    // 0x8001825C: jal         0x8004BCF0
    // 0x80018260: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8004BCF0(rdram, ctx);
        goto after_182;
    // 0x80018260: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_182:
    // 0x80018264: b           L_80018298
    // 0x80018268: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
        goto L_80018298;
    // 0x80018268: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_8001826C:
    // 0x8001826C: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80018270: addiu       $a2, $a2, 0x63BC
    ctx->r6 = ADD32(ctx->r6, 0X63BC);
    // 0x80018274: jal         0x8004BCF0
    // 0x80018278: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8004BCF0(rdram, ctx);
        goto after_183;
    // 0x80018278: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_183:
    // 0x8001827C: b           L_80018298
    // 0x80018280: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
        goto L_80018298;
    // 0x80018280: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_80018284:
    // 0x80018284: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80018288: addiu       $a2, $a2, 0x63C4
    ctx->r6 = ADD32(ctx->r6, 0X63C4);
    // 0x8001828C: jal         0x8004BCF0
    // 0x80018290: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8004BCF0(rdram, ctx);
        goto after_184;
    // 0x80018290: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_184:
    // 0x80018294: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_80018298:
    // 0x80018298: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x8001829C: jal         0x8004C388
    // 0x800182A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004C388(rdram, ctx);
        goto after_185;
    // 0x800182A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_185:
    // 0x800182A4: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x800182A8: addiu       $a2, $a2, 0x63CC
    ctx->r6 = ADD32(ctx->r6, 0X63CC);
    // 0x800182AC: addiu       $a0, $zero, -0xFF
    ctx->r4 = ADD32(0, -0XFF);
    // 0x800182B0: jal         0x8004BCF0
    // 0x800182B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8004BCF0(rdram, ctx);
        goto after_186;
    // 0x800182B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_186:
    // 0x800182B8: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x800182BC: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x800182C0: jal         0x8004C388
    // 0x800182C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004C388(rdram, ctx);
        goto after_187;
    // 0x800182C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_187:
    // 0x800182C8: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x800182CC: lw          $v0, 0x31E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31E8);
    // 0x800182D0: lui         $at, 0x2E6
    ctx->r1 = S32(0X2E6 << 16);
    // 0x800182D4: ori         $at, $at, 0x25C
    ctx->r1 = ctx->r1 | 0X25C;
    // 0x800182D8: beq         $v0, $at, L_80018338
    if (ctx->r2 == ctx->r1) {
        // 0x800182DC: addiu       $a0, $zero, -0xFF
        ctx->r4 = ADD32(0, -0XFF);
            goto L_80018338;
    }
    // 0x800182DC: addiu       $a0, $zero, -0xFF
    ctx->r4 = ADD32(0, -0XFF);
    // 0x800182E0: lui         $at, 0x2E6
    ctx->r1 = S32(0X2E6 << 16);
    // 0x800182E4: ori         $at, $at, 0xD354
    ctx->r1 = ctx->r1 | 0XD354;
    // 0x800182E8: beq         $v0, $at, L_80018308
    if (ctx->r2 == ctx->r1) {
        // 0x800182EC: addiu       $a0, $zero, -0xFF
        ctx->r4 = ADD32(0, -0XFF);
            goto L_80018308;
    }
    // 0x800182EC: addiu       $a0, $zero, -0xFF
    ctx->r4 = ADD32(0, -0XFF);
    // 0x800182F0: lui         $at, 0x2F5
    ctx->r1 = S32(0X2F5 << 16);
    // 0x800182F4: ori         $at, $at, 0xB2D2
    ctx->r1 = ctx->r1 | 0XB2D2;
    // 0x800182F8: beq         $v0, $at, L_80018320
    if (ctx->r2 == ctx->r1) {
        // 0x800182FC: addiu       $a0, $zero, -0xFF
        ctx->r4 = ADD32(0, -0XFF);
            goto L_80018320;
    }
    // 0x800182FC: addiu       $a0, $zero, -0xFF
    ctx->r4 = ADD32(0, -0XFF);
    // 0x80018300: b           L_80018350
    // 0x80018304: addiu       $a0, $zero, -0xFF
    ctx->r4 = ADD32(0, -0XFF);
        goto L_80018350;
    // 0x80018304: addiu       $a0, $zero, -0xFF
    ctx->r4 = ADD32(0, -0XFF);
L_80018308:
    // 0x80018308: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x8001830C: addiu       $a2, $a2, 0x63D8
    ctx->r6 = ADD32(ctx->r6, 0X63D8);
    // 0x80018310: jal         0x8004BCF0
    // 0x80018314: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8004BCF0(rdram, ctx);
        goto after_188;
    // 0x80018314: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_188:
    // 0x80018318: b           L_80018360
    // 0x8001831C: nop

        goto L_80018360;
    // 0x8001831C: nop

L_80018320:
    // 0x80018320: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80018324: addiu       $a2, $a2, 0x63E0
    ctx->r6 = ADD32(ctx->r6, 0X63E0);
    // 0x80018328: jal         0x8004BCF0
    // 0x8001832C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8004BCF0(rdram, ctx);
        goto after_189;
    // 0x8001832C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_189:
    // 0x80018330: b           L_80018360
    // 0x80018334: nop

        goto L_80018360;
    // 0x80018334: nop

L_80018338:
    // 0x80018338: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x8001833C: addiu       $a2, $a2, 0x63E4
    ctx->r6 = ADD32(ctx->r6, 0X63E4);
    // 0x80018340: jal         0x8004BCF0
    // 0x80018344: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8004BCF0(rdram, ctx);
        goto after_190;
    // 0x80018344: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_190:
    // 0x80018348: b           L_80018360
    // 0x8001834C: nop

        goto L_80018360;
    // 0x8001834C: nop

L_80018350:
    // 0x80018350: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80018354: addiu       $a2, $a2, 0x63EC
    ctx->r6 = ADD32(ctx->r6, 0X63EC);
    // 0x80018358: jal         0x8004BCF0
    // 0x8001835C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8004BCF0(rdram, ctx);
        goto after_191;
    // 0x8001835C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_191:
L_80018360:
    // 0x80018360: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x80018364: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x80018368: lui         $s5, 0x8007
    ctx->r21 = S32(0X8007 << 16);
    // 0x8001836C: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x80018370: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80018374: addiu       $s3, $s3, -0x6B86
    ctx->r19 = ADD32(ctx->r19, -0X6B86);
    // 0x80018378: addiu       $s4, $s4, -0x6B8E
    ctx->r20 = ADD32(ctx->r20, -0X6B8E);
    // 0x8001837C: addiu       $s5, $s5, -0x65A0
    ctx->r21 = ADD32(ctx->r21, -0X65A0);
    // 0x80018380: addiu       $s6, $s6, -0x6B7C
    ctx->r22 = ADD32(ctx->r22, -0X6B7C);
    // 0x80018384: addiu       $s7, $s7, -0x6B8A
    ctx->r23 = ADD32(ctx->r23, -0X6B8A);
L_80018388:
    // 0x80018388: jal         0x800496B4
    // 0x8001838C: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    func_800496B4(rdram, ctx);
        goto after_192;
    // 0x8001838C: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    after_192:
    // 0x80018390: lh          $t5, 0x90($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X90);
    // 0x80018394: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x80018398: sltiu       $at, $t6, 0xA
    ctx->r1 = ctx->r14 < 0XA ? 1 : 0;
    // 0x8001839C: beq         $at, $zero, L_800188EC
    if (ctx->r1 == 0) {
        // 0x800183A0: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800188EC;
    }
    // 0x800183A0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800183A4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800183A8: addu        $at, $at, $t6
    gpr jr_addend_800183B0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800183AC: lw          $t6, 0x640C($at)
    ctx->r14 = ADD32(ctx->r1, 0X640C);
    // 0x800183B0: jr          $t6
    // 0x800183B4: nop

    switch (jr_addend_800183B0 >> 2) {
        case 0: goto L_800183B8; break;
        case 1: goto L_8001843C; break;
        case 2: goto L_800184C0; break;
        case 3: goto L_80018544; break;
        case 4: goto L_800188EC; break;
        case 5: goto L_80018624; break;
        case 6: goto L_8001869C; break;
        case 7: goto L_800188EC; break;
        case 8: goto L_800188EC; break;
        case 9: goto L_800187A0; break;
        default: switch_error(__func__, 0x800183B0, 0x8007640C);
    }
    // 0x800183B4: nop

L_800183B8:
    // 0x800183B8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800183BC: lhu         $t7, -0x2E5A($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X2E5A);
    // 0x800183C0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800183C4: andi        $t8, $t7, 0x300
    ctx->r24 = ctx->r15 & 0X300;
    // 0x800183C8: bnel        $t8, $zero, L_800183E4
    if (ctx->r24 != 0) {
        // 0x800183CC: lh          $t1, 0x0($s4)
        ctx->r9 = MEM_H(ctx->r20, 0X0);
            goto L_800183E4;
    }
    goto skip_21;
    // 0x800183CC: lh          $t1, 0x0($s4)
    ctx->r9 = MEM_H(ctx->r20, 0X0);
    skip_21:
    // 0x800183D0: lh          $t9, -0x2E4C($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X2E4C);
    // 0x800183D4: andi        $t0, $t9, 0x300
    ctx->r8 = ctx->r25 & 0X300;
    // 0x800183D8: beql        $t0, $zero, L_800183F8
    if (ctx->r8 == 0) {
        // 0x800183DC: lh          $a1, 0x90($sp)
        ctx->r5 = MEM_H(ctx->r29, 0X90);
            goto L_800183F8;
    }
    goto skip_22;
    // 0x800183DC: lh          $a1, 0x90($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X90);
    skip_22:
    // 0x800183E0: lh          $t1, 0x0($s4)
    ctx->r9 = MEM_H(ctx->r20, 0X0);
L_800183E4:
    // 0x800183E4: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x800183E8: xori        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 ^ 0X1;
    // 0x800183EC: jal         0x80044480
    // 0x800183F0: sh          $t2, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r10;
    func_80044480(rdram, ctx);
        goto after_193;
    // 0x800183F0: sh          $t2, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r10;
    after_193:
    // 0x800183F4: lh          $a1, 0x90($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X90);
L_800183F8:
    // 0x800183F8: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x800183FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80018400: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80018404: sll         $t3, $a1, 16
    ctx->r11 = S32(ctx->r5 << 16);
    // 0x80018408: jal         0x8004C388
    // 0x8001840C: sra         $a1, $t3, 16
    ctx->r5 = S32(SIGNED(ctx->r11) >> 16);
    func_8004C388(rdram, ctx);
        goto after_194;
    // 0x8001840C: sra         $a1, $t3, 16
    ctx->r5 = S32(SIGNED(ctx->r11) >> 16);
    after_194:
    // 0x80018410: lh          $t5, 0x0($s4)
    ctx->r13 = MEM_H(ctx->r20, 0X0);
    // 0x80018414: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80018418: addiu       $a2, $a2, 0x63F4
    ctx->r6 = ADD32(ctx->r6, 0X63F4);
    // 0x8001841C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80018420: addu        $t7, $s5, $t6
    ctx->r15 = ADD32(ctx->r21, ctx->r14);
    // 0x80018424: lw          $a3, 0x0($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X0);
    // 0x80018428: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x8001842C: jal         0x8004C340
    // 0x80018430: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004C340(rdram, ctx);
        goto after_195;
    // 0x80018430: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_195:
    // 0x80018434: b           L_800188EC
    // 0x80018438: nop

        goto L_800188EC;
    // 0x80018438: nop

L_8001843C:
    // 0x8001843C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80018440: lhu         $t8, -0x2E5A($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X2E5A);
    // 0x80018444: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80018448: andi        $t9, $t8, 0x300
    ctx->r25 = ctx->r24 & 0X300;
    // 0x8001844C: bnel        $t9, $zero, L_80018468
    if (ctx->r25 != 0) {
        // 0x80018450: lh          $t2, 0x0($s7)
        ctx->r10 = MEM_H(ctx->r23, 0X0);
            goto L_80018468;
    }
    goto skip_23;
    // 0x80018450: lh          $t2, 0x0($s7)
    ctx->r10 = MEM_H(ctx->r23, 0X0);
    skip_23:
    // 0x80018454: lh          $t0, -0x2E4C($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X2E4C);
    // 0x80018458: andi        $t1, $t0, 0x300
    ctx->r9 = ctx->r8 & 0X300;
    // 0x8001845C: beql        $t1, $zero, L_8001847C
    if (ctx->r9 == 0) {
        // 0x80018460: lh          $a1, 0x90($sp)
        ctx->r5 = MEM_H(ctx->r29, 0X90);
            goto L_8001847C;
    }
    goto skip_24;
    // 0x80018460: lh          $a1, 0x90($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X90);
    skip_24:
    // 0x80018464: lh          $t2, 0x0($s7)
    ctx->r10 = MEM_H(ctx->r23, 0X0);
L_80018468:
    // 0x80018468: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x8001846C: xori        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 ^ 0X1;
    // 0x80018470: jal         0x80044480
    // 0x80018474: sh          $t3, 0x0($s7)
    MEM_H(0X0, ctx->r23) = ctx->r11;
    func_80044480(rdram, ctx);
        goto after_196;
    // 0x80018474: sh          $t3, 0x0($s7)
    MEM_H(0X0, ctx->r23) = ctx->r11;
    after_196:
    // 0x80018478: lh          $a1, 0x90($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X90);
L_8001847C:
    // 0x8001847C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80018480: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80018484: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80018488: sll         $t4, $a1, 16
    ctx->r12 = S32(ctx->r5 << 16);
    // 0x8001848C: jal         0x8004C388
    // 0x80018490: sra         $a1, $t4, 16
    ctx->r5 = S32(SIGNED(ctx->r12) >> 16);
    func_8004C388(rdram, ctx);
        goto after_197;
    // 0x80018490: sra         $a1, $t4, 16
    ctx->r5 = S32(SIGNED(ctx->r12) >> 16);
    after_197:
    // 0x80018494: lh          $t6, 0x0($s7)
    ctx->r14 = MEM_H(ctx->r23, 0X0);
    // 0x80018498: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x8001849C: addiu       $a2, $a2, 0x63F8
    ctx->r6 = ADD32(ctx->r6, 0X63F8);
    // 0x800184A0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800184A4: addu        $t8, $s5, $t7
    ctx->r24 = ADD32(ctx->r21, ctx->r15);
    // 0x800184A8: lw          $a3, 0x0($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X0);
    // 0x800184AC: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x800184B0: jal         0x8004C340
    // 0x800184B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004C340(rdram, ctx);
        goto after_198;
    // 0x800184B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_198:
    // 0x800184B8: b           L_800188EC
    // 0x800184BC: nop

        goto L_800188EC;
    // 0x800184BC: nop

L_800184C0:
    // 0x800184C0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800184C4: lhu         $t9, -0x2E5A($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X2E5A);
    // 0x800184C8: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800184CC: andi        $t0, $t9, 0x300
    ctx->r8 = ctx->r25 & 0X300;
    // 0x800184D0: bnel        $t0, $zero, L_800184EC
    if (ctx->r8 != 0) {
        // 0x800184D4: lh          $t3, 0x0($s3)
        ctx->r11 = MEM_H(ctx->r19, 0X0);
            goto L_800184EC;
    }
    goto skip_25;
    // 0x800184D4: lh          $t3, 0x0($s3)
    ctx->r11 = MEM_H(ctx->r19, 0X0);
    skip_25:
    // 0x800184D8: lh          $t1, -0x2E4C($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X2E4C);
    // 0x800184DC: andi        $t2, $t1, 0x300
    ctx->r10 = ctx->r9 & 0X300;
    // 0x800184E0: beql        $t2, $zero, L_80018500
    if (ctx->r10 == 0) {
        // 0x800184E4: lh          $a1, 0x90($sp)
        ctx->r5 = MEM_H(ctx->r29, 0X90);
            goto L_80018500;
    }
    goto skip_26;
    // 0x800184E4: lh          $a1, 0x90($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X90);
    skip_26:
    // 0x800184E8: lh          $t3, 0x0($s3)
    ctx->r11 = MEM_H(ctx->r19, 0X0);
L_800184EC:
    // 0x800184EC: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x800184F0: xori        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 ^ 0X1;
    // 0x800184F4: jal         0x80044480
    // 0x800184F8: sh          $t4, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r12;
    func_80044480(rdram, ctx);
        goto after_199;
    // 0x800184F8: sh          $t4, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r12;
    after_199:
    // 0x800184FC: lh          $a1, 0x90($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X90);
L_80018500:
    // 0x80018500: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80018504: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80018508: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8001850C: sll         $t5, $a1, 16
    ctx->r13 = S32(ctx->r5 << 16);
    // 0x80018510: jal         0x8004C388
    // 0x80018514: sra         $a1, $t5, 16
    ctx->r5 = S32(SIGNED(ctx->r13) >> 16);
    func_8004C388(rdram, ctx);
        goto after_200;
    // 0x80018514: sra         $a1, $t5, 16
    ctx->r5 = S32(SIGNED(ctx->r13) >> 16);
    after_200:
    // 0x80018518: lh          $t7, 0x0($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X0);
    // 0x8001851C: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80018520: addiu       $a2, $a2, 0x63FC
    ctx->r6 = ADD32(ctx->r6, 0X63FC);
    // 0x80018524: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80018528: addu        $t9, $s5, $t8
    ctx->r25 = ADD32(ctx->r21, ctx->r24);
    // 0x8001852C: lw          $a3, 0x0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X0);
    // 0x80018530: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80018534: jal         0x8004C340
    // 0x80018538: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004C340(rdram, ctx);
        goto after_201;
    // 0x80018538: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_201:
    // 0x8001853C: b           L_800188EC
    // 0x80018540: nop

        goto L_800188EC;
    // 0x80018540: nop

L_80018544:
    // 0x80018544: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80018548: lhu         $a1, -0x2E5A($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X2E5A);
    // 0x8001854C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80018550: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80018554: andi        $t0, $a1, 0x100
    ctx->r8 = ctx->r5 & 0X100;
    // 0x80018558: bne         $t0, $zero, L_80018570
    if (ctx->r8 != 0) {
        // 0x8001855C: andi        $t6, $a1, 0x200
        ctx->r14 = ctx->r5 & 0X200;
            goto L_80018570;
    }
    // 0x8001855C: andi        $t6, $a1, 0x200
    ctx->r14 = ctx->r5 & 0X200;
    // 0x80018560: lh          $t1, -0x2E4C($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X2E4C);
    // 0x80018564: andi        $t2, $t1, 0x100
    ctx->r10 = ctx->r9 & 0X100;
    // 0x80018568: beq         $t2, $zero, L_80018590
    if (ctx->r10 == 0) {
        // 0x8001856C: nop
    
            goto L_80018590;
    }
    // 0x8001856C: nop

L_80018570:
    // 0x80018570: lh          $t3, 0x0($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X0);
    // 0x80018574: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80018578: sh          $t4, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r12;
    // 0x8001857C: lh          $t5, 0x0($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X0);
    // 0x80018580: slti        $at, $t5, 0x9
    ctx->r1 = SIGNED(ctx->r13) < 0X9 ? 1 : 0;
    // 0x80018584: bne         $at, $zero, L_80018590
    if (ctx->r1 != 0) {
        // 0x80018588: nop
    
            goto L_80018590;
    }
    // 0x80018588: nop

    // 0x8001858C: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
L_80018590:
    // 0x80018590: bnel        $t6, $zero, L_800185AC
    if (ctx->r14 != 0) {
        // 0x80018594: lh          $t9, 0x0($s1)
        ctx->r25 = MEM_H(ctx->r17, 0X0);
            goto L_800185AC;
    }
    goto skip_27;
    // 0x80018594: lh          $t9, 0x0($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X0);
    skip_27:
    // 0x80018598: lh          $t7, -0x2E4C($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X2E4C);
    // 0x8001859C: andi        $t8, $t7, 0x200
    ctx->r24 = ctx->r15 & 0X200;
    // 0x800185A0: beql        $t8, $zero, L_800185CC
    if (ctx->r24 == 0) {
        // 0x800185A4: lh          $t3, 0x7E($sp)
        ctx->r11 = MEM_H(ctx->r29, 0X7E);
            goto L_800185CC;
    }
    goto skip_28;
    // 0x800185A4: lh          $t3, 0x7E($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X7E);
    skip_28:
    // 0x800185A8: lh          $t9, 0x0($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X0);
L_800185AC:
    // 0x800185AC: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x800185B0: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x800185B4: sh          $t0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r8;
    // 0x800185B8: lh          $t1, 0x0($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X0);
    // 0x800185BC: bgezl       $t1, L_800185CC
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800185C0: lh          $t3, 0x7E($sp)
        ctx->r11 = MEM_H(ctx->r29, 0X7E);
            goto L_800185CC;
    }
    goto skip_29;
    // 0x800185C0: lh          $t3, 0x7E($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X7E);
    skip_29:
    // 0x800185C4: sh          $t2, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r10;
    // 0x800185C8: lh          $t3, 0x7E($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X7E);
L_800185CC:
    // 0x800185CC: lh          $t4, 0x0($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X0);
    // 0x800185D0: beql        $t3, $t4, L_800185EC
    if (ctx->r11 == ctx->r12) {
        // 0x800185D4: lh          $a1, 0x90($sp)
        ctx->r5 = MEM_H(ctx->r29, 0X90);
            goto L_800185EC;
    }
    goto skip_30;
    // 0x800185D4: lh          $a1, 0x90($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X90);
    skip_30:
    // 0x800185D8: jal         0x80044480
    // 0x800185DC: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    func_80044480(rdram, ctx);
        goto after_202;
    // 0x800185DC: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_202:
    // 0x800185E0: lh          $t5, 0x0($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X0);
    // 0x800185E4: sh          $t5, 0x7E($sp)
    MEM_H(0X7E, ctx->r29) = ctx->r13;
    // 0x800185E8: lh          $a1, 0x90($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X90);
L_800185EC:
    // 0x800185EC: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x800185F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800185F4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800185F8: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x800185FC: jal         0x8004C388
    // 0x80018600: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    func_8004C388(rdram, ctx);
        goto after_203;
    // 0x80018600: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    after_203:
    // 0x80018604: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80018608: addiu       $a2, $a2, 0x6400
    ctx->r6 = ADD32(ctx->r6, 0X6400);
    // 0x8001860C: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80018610: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80018614: jal         0x8004C340
    // 0x80018618: lh          $a3, 0x0($s1)
    ctx->r7 = MEM_H(ctx->r17, 0X0);
    func_8004C340(rdram, ctx);
        goto after_204;
    // 0x80018618: lh          $a3, 0x0($s1)
    ctx->r7 = MEM_H(ctx->r17, 0X0);
    after_204:
    // 0x8001861C: b           L_800188EC
    // 0x80018620: nop

        goto L_800188EC;
    // 0x80018620: nop

L_80018624:
    // 0x80018624: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80018628: lhu         $t8, -0x2E5A($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X2E5A);
    // 0x8001862C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80018630: andi        $t9, $t8, 0x300
    ctx->r25 = ctx->r24 & 0X300;
    // 0x80018634: bnel        $t9, $zero, L_80018650
    if (ctx->r25 != 0) {
        // 0x80018638: lh          $t2, 0x0($s6)
        ctx->r10 = MEM_H(ctx->r22, 0X0);
            goto L_80018650;
    }
    goto skip_31;
    // 0x80018638: lh          $t2, 0x0($s6)
    ctx->r10 = MEM_H(ctx->r22, 0X0);
    skip_31:
    // 0x8001863C: lh          $t0, -0x2E4C($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X2E4C);
    // 0x80018640: andi        $t1, $t0, 0x300
    ctx->r9 = ctx->r8 & 0X300;
    // 0x80018644: beql        $t1, $zero, L_80018664
    if (ctx->r9 == 0) {
        // 0x80018648: lh          $a1, 0x90($sp)
        ctx->r5 = MEM_H(ctx->r29, 0X90);
            goto L_80018664;
    }
    goto skip_32;
    // 0x80018648: lh          $a1, 0x90($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X90);
    skip_32:
    // 0x8001864C: lh          $t2, 0x0($s6)
    ctx->r10 = MEM_H(ctx->r22, 0X0);
L_80018650:
    // 0x80018650: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x80018654: xori        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 ^ 0X1;
    // 0x80018658: jal         0x80044480
    // 0x8001865C: sh          $t3, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r11;
    func_80044480(rdram, ctx);
        goto after_205;
    // 0x8001865C: sh          $t3, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r11;
    after_205:
    // 0x80018660: lh          $a1, 0x90($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X90);
L_80018664:
    // 0x80018664: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80018668: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8001866C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80018670: sll         $t4, $a1, 16
    ctx->r12 = S32(ctx->r5 << 16);
    // 0x80018674: jal         0x8004C388
    // 0x80018678: sra         $a1, $t4, 16
    ctx->r5 = S32(SIGNED(ctx->r12) >> 16);
    func_8004C388(rdram, ctx);
        goto after_206;
    // 0x80018678: sra         $a1, $t4, 16
    ctx->r5 = S32(SIGNED(ctx->r12) >> 16);
    after_206:
    // 0x8001867C: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80018680: addiu       $a2, $a2, 0x6404
    ctx->r6 = ADD32(ctx->r6, 0X6404);
    // 0x80018684: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80018688: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8001868C: jal         0x8004C340
    // 0x80018690: lh          $a3, 0x0($s6)
    ctx->r7 = MEM_H(ctx->r22, 0X0);
    func_8004C340(rdram, ctx);
        goto after_207;
    // 0x80018690: lh          $a3, 0x0($s6)
    ctx->r7 = MEM_H(ctx->r22, 0X0);
    after_207:
    // 0x80018694: b           L_800188EC
    // 0x80018698: nop

        goto L_800188EC;
    // 0x80018698: nop

L_8001869C:
    // 0x8001869C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800186A0: lhu         $a1, -0x2E5A($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X2E5A);
    // 0x800186A4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800186A8: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800186AC: andi        $t6, $a1, 0x100
    ctx->r14 = ctx->r5 & 0X100;
    // 0x800186B0: bne         $t6, $zero, L_800186C8
    if (ctx->r14 != 0) {
        // 0x800186B4: andi        $t1, $a1, 0x200
        ctx->r9 = ctx->r5 & 0X200;
            goto L_800186C8;
    }
    // 0x800186B4: andi        $t1, $a1, 0x200
    ctx->r9 = ctx->r5 & 0X200;
    // 0x800186B8: lh          $t7, -0x2E4C($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X2E4C);
    // 0x800186BC: andi        $t8, $t7, 0x100
    ctx->r24 = ctx->r15 & 0X100;
    // 0x800186C0: beq         $t8, $zero, L_800186E4
    if (ctx->r24 == 0) {
        // 0x800186C4: nop
    
            goto L_800186E4;
    }
    // 0x800186C4: nop

L_800186C8:
    // 0x800186C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800186CC: sll         $t9, $s0, 16
    ctx->r25 = S32(ctx->r16 << 16);
    // 0x800186D0: sra         $s0, $t9, 16
    ctx->r16 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800186D4: slti        $at, $s0, 0xE
    ctx->r1 = SIGNED(ctx->r16) < 0XE ? 1 : 0;
    // 0x800186D8: bne         $at, $zero, L_800186E4
    if (ctx->r1 != 0) {
        // 0x800186DC: nop
    
            goto L_800186E4;
    }
    // 0x800186DC: nop

    // 0x800186E0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800186E4:
    // 0x800186E4: bne         $t1, $zero, L_800186FC
    if (ctx->r9 != 0) {
        // 0x800186E8: lh          $t6, 0x7A($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X7A);
            goto L_800186FC;
    }
    // 0x800186E8: lh          $t6, 0x7A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X7A);
    // 0x800186EC: lh          $t2, -0x2E4C($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X2E4C);
    // 0x800186F0: andi        $t3, $t2, 0x200
    ctx->r11 = ctx->r10 & 0X200;
    // 0x800186F4: beq         $t3, $zero, L_80018714
    if (ctx->r11 == 0) {
        // 0x800186F8: nop
    
            goto L_80018714;
    }
    // 0x800186F8: nop

L_800186FC:
    // 0x800186FC: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80018700: sll         $t4, $s0, 16
    ctx->r12 = S32(ctx->r16 << 16);
    // 0x80018704: sra         $s0, $t4, 16
    ctx->r16 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80018708: bgez        $s0, L_80018714
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8001870C: nop
    
            goto L_80018714;
    }
    // 0x8001870C: nop

    // 0x80018710: addiu       $s0, $zero, 0xD
    ctx->r16 = ADD32(0, 0XD);
L_80018714:
    // 0x80018714: beq         $s0, $t6, L_80018724
    if (ctx->r16 == ctx->r14) {
        // 0x80018718: addiu       $a0, $zero, 0x12
        ctx->r4 = ADD32(0, 0X12);
            goto L_80018724;
    }
    // 0x80018718: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x8001871C: jal         0x80044480
    // 0x80018720: sh          $s0, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = ctx->r16;
    func_80044480(rdram, ctx);
        goto after_208;
    // 0x80018720: sh          $s0, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = ctx->r16;
    after_208:
L_80018724:
    // 0x80018724: lh          $a1, 0x90($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X90);
    // 0x80018728: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x8001872C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80018730: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80018734: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x80018738: jal         0x8004C388
    // 0x8001873C: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    func_8004C388(rdram, ctx);
        goto after_209;
    // 0x8001873C: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    after_209:
    // 0x80018740: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80018744: addiu       $a2, $a2, 0x6408
    ctx->r6 = ADD32(ctx->r6, 0X6408);
    // 0x80018748: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x8001874C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80018750: jal         0x8004C340
    // 0x80018754: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_8004C340(rdram, ctx);
        goto after_210;
    // 0x80018754: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_210:
    // 0x80018758: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8001875C: lhu         $t9, -0x2E5A($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X2E5A);
    // 0x80018760: xori        $t1, $fp, 0x1
    ctx->r9 = ctx->r30 ^ 0X1;
    // 0x80018764: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x80018768: andi        $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 & 0X8000;
    // 0x8001876C: beq         $t0, $zero, L_800188EC
    if (ctx->r8 == 0) {
        // 0x80018770: nop
    
            goto L_800188EC;
    }
    // 0x80018770: nop

    // 0x80018774: sra         $fp, $t2, 16
    ctx->r30 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80018778: beq         $fp, $zero, L_80018790
    if (ctx->r30 == 0) {
        // 0x8001877C: nop
    
            goto L_80018790;
    }
    // 0x8001877C: nop

    // 0x80018780: jal         0x80007EC8
    // 0x80018784: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80007EC8(rdram, ctx);
        goto after_211;
    // 0x80018784: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_211:
    // 0x80018788: b           L_800188EC
    // 0x8001878C: nop

        goto L_800188EC;
    // 0x8001878C: nop

L_80018790:
    // 0x80018790: jal         0x80007E20
    // 0x80018794: nop

    func_80007E20(rdram, ctx);
        goto after_212;
    // 0x80018794: nop

    after_212:
    // 0x80018798: b           L_800188EC
    // 0x8001879C: nop

        goto L_800188EC;
    // 0x8001879C: nop

L_800187A0:
    // 0x800187A0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800187A4: lhu         $a1, -0x2E5A($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X2E5A);
    // 0x800187A8: andi        $t8, $s2, 0x1
    ctx->r24 = ctx->r18 & 0X1;
    // 0x800187AC: andi        $t4, $a1, 0x9000
    ctx->r12 = ctx->r5 & 0X9000;
    // 0x800187B0: beq         $t4, $zero, L_80018830
    if (ctx->r12 == 0) {
        // 0x800187B4: andi        $t7, $a1, 0x20
        ctx->r15 = ctx->r5 & 0X20;
            goto L_80018830;
    }
    // 0x800187B4: andi        $t7, $a1, 0x20
    ctx->r15 = ctx->r5 & 0X20;
L_800187B8:
    // 0x800187B8: beql        $fp, $zero, L_800187CC
    if (ctx->r30 == 0) {
        // 0x800187BC: addiu       $s0, $zero, 0xD
        ctx->r16 = ADD32(0, 0XD);
            goto L_800187CC;
    }
    goto skip_33;
    // 0x800187BC: addiu       $s0, $zero, 0xD
    ctx->r16 = ADD32(0, 0XD);
    skip_33:
    // 0x800187C0: jal         0x80007E20
    // 0x800187C4: nop

    func_80007E20(rdram, ctx);
        goto after_213;
    // 0x800187C4: nop

    after_213:
    // 0x800187C8: addiu       $s0, $zero, 0xD
    ctx->r16 = ADD32(0, 0XD);
L_800187CC:
    // 0x800187CC: sll         $v0, $s0, 16
    ctx->r2 = S32(ctx->r16 << 16);
    // 0x800187D0: sra         $t5, $v0, 16
    ctx->r13 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800187D4: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x800187D8: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x800187DC: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x800187E0: jal         0x80044480
    // 0x800187E4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    func_80044480(rdram, ctx);
        goto after_214;
    // 0x800187E4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    after_214:
    // 0x800187E8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800187EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800187F0: jal         0x8001A37C
    // 0x800187F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8001A37C(rdram, ctx);
        goto after_215;
    // 0x800187F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_215:
    // 0x800187F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800187FC: jal         0x8004C4D8
    // 0x80018800: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004C4D8(rdram, ctx);
        goto after_216;
    // 0x80018800: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_216:
    // 0x80018804: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80018808: jal         0x8004C4D8
    // 0x8001880C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004C4D8(rdram, ctx);
        goto after_217;
    // 0x8001880C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_217:
    // 0x80018810: jal         0x8004B21C
    // 0x80018814: nop

    func_8004B21C(rdram, ctx);
        goto after_218;
    // 0x80018814: nop

    after_218:
    // 0x80018818: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x8001881C: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
L_80018820:
    // 0x80018820: jal         0x8000798C
    // 0x80018824: nop

    func_8000798C(rdram, ctx);
        goto after_219;
    // 0x80018824: nop

    after_219:
    // 0x80018828: b           L_80018820
    // 0x8001882C: nop

        goto L_80018820;
    // 0x8001882C: nop

L_80018830:
    // 0x80018830: beq         $t7, $zero, L_80018854
    if (ctx->r15 == 0) {
        // 0x80018834: andi        $t1, $a1, 0x10
        ctx->r9 = ctx->r5 & 0X10;
            goto L_80018854;
    }
    // 0x80018834: andi        $t1, $a1, 0x10
    ctx->r9 = ctx->r5 & 0X10;
    // 0x80018838: bne         $t8, $zero, L_8001884C
    if (ctx->r24 != 0) {
        // 0x8001883C: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8001884C;
    }
    // 0x8001883C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80018840: sll         $t9, $s2, 16
    ctx->r25 = S32(ctx->r18 << 16);
    // 0x80018844: b           L_80018874
    // 0x80018848: sra         $s2, $t9, 16
    ctx->r18 = S32(SIGNED(ctx->r25) >> 16);
        goto L_80018874;
    // 0x80018848: sra         $s2, $t9, 16
    ctx->r18 = S32(SIGNED(ctx->r25) >> 16);
L_8001884C:
    // 0x8001884C: b           L_80018874
    // 0x80018850: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
        goto L_80018874;
    // 0x80018850: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80018854:
    // 0x80018854: beq         $t1, $zero, L_80018874
    if (ctx->r9 == 0) {
        // 0x80018858: andi        $t2, $s2, 0x1
        ctx->r10 = ctx->r18 & 0X1;
            goto L_80018874;
    }
    // 0x80018858: andi        $t2, $s2, 0x1
    ctx->r10 = ctx->r18 & 0X1;
    // 0x8001885C: beq         $t2, $zero, L_80018870
    if (ctx->r10 == 0) {
        // 0x80018860: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80018870;
    }
    // 0x80018860: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80018864: sll         $t3, $s2, 16
    ctx->r11 = S32(ctx->r18 << 16);
    // 0x80018868: b           L_80018874
    // 0x8001886C: sra         $s2, $t3, 16
    ctx->r18 = S32(SIGNED(ctx->r11) >> 16);
        goto L_80018874;
    // 0x8001886C: sra         $s2, $t3, 16
    ctx->r18 = S32(SIGNED(ctx->r11) >> 16);
L_80018870:
    // 0x80018870: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80018874:
    // 0x80018874: slti        $at, $s2, 0x65
    ctx->r1 = SIGNED(ctx->r18) < 0X65 ? 1 : 0;
    // 0x80018878: bne         $at, $zero, L_800188EC
    if (ctx->r1 != 0) {
        // 0x8001887C: nop
    
            goto L_800188EC;
    }
    // 0x8001887C: nop

    // 0x80018880: lh          $t5, 0x0($s3)
    ctx->r13 = MEM_H(ctx->r19, 0X0);
    // 0x80018884: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80018888: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8001888C: bne         $t5, $at, L_800188EC
    if (ctx->r13 != ctx->r1) {
        // 0x80018890: nop
    
            goto L_800188EC;
    }
    // 0x80018890: nop

    // 0x80018894: lh          $t6, 0x0($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X0);
    // 0x80018898: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8001889C: bne         $t6, $at, L_800188EC
    if (ctx->r14 != ctx->r1) {
        // 0x800188A0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800188EC;
    }
    // 0x800188A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800188A4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x800188A8: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x800188AC: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x800188B0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800188B4: jal         0x8004C580
    // 0x800188B8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_220;
    // 0x800188B8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_220:
    // 0x800188BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800188C0: jal         0x8004C4D8
    // 0x800188C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004C4D8(rdram, ctx);
        goto after_221;
    // 0x800188C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_221:
L_800188C8:
    // 0x800188C8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800188CC: lhu         $t7, -0x2E5A($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X2E5A);
    // 0x800188D0: andi        $t8, $t7, 0x1000
    ctx->r24 = ctx->r15 & 0X1000;
    // 0x800188D4: bne         $t8, $zero, L_800187B8
    if (ctx->r24 != 0) {
        // 0x800188D8: nop
    
            goto L_800187B8;
    }
    // 0x800188D8: nop

    // 0x800188DC: jal         0x8000798C
    // 0x800188E0: nop

    func_8000798C(rdram, ctx);
        goto after_222;
    // 0x800188E0: nop

    after_222:
    // 0x800188E4: b           L_800188C8
    // 0x800188E8: nop

        goto L_800188C8;
    // 0x800188E8: nop

L_800188EC:
    // 0x800188EC: jal         0x8000798C
    // 0x800188F0: nop

    func_8000798C(rdram, ctx);
        goto after_223;
    // 0x800188F0: nop

    after_223:
    // 0x800188F4: b           L_80018388
    // 0x800188F8: nop

        goto L_80018388;
    // 0x800188F8: nop

L_800188FC:
    // 0x800188FC: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80018900: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80018904: lh          $t1, 0x6ACE($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X6ACE);
    // 0x80018908: lh          $t3, 0x6AD0($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X6AD0);
    // 0x8001890C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80018910: lh          $t9, 0x6ACC($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X6ACC);
    // 0x80018914: lh          $t0, -0x6B90($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X6B90);
    // 0x80018918: lui         $t5, 0x8001
    ctx->r13 = S32(0X8001 << 16);
    // 0x8001891C: addiu       $t5, $t5, -0x3900
    ctx->r13 = ADD32(ctx->r13, -0X3900);
    // 0x80018920: addiu       $t6, $sp, 0xA0
    ctx->r14 = ADD32(ctx->r29, 0XA0);
    // 0x80018924: lui         $s6, 0x8007
    ctx->r22 = S32(0X8007 << 16);
    // 0x80018928: xori        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 ^ 0X1;
    // 0x8001892C: xori        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 ^ 0X1;
    // 0x80018930: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80018934: sh          $t2, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = ctx->r10;
    // 0x80018938: sh          $t4, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r12;
    // 0x8001893C: addiu       $s6, $s6, -0x65B0
    ctx->r22 = ADD32(ctx->r22, -0X65B0);
    // 0x80018940: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
    // 0x80018944: sw          $t5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r13;
    // 0x80018948: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8001894C: addiu       $fp, $zero, 0x4
    ctx->r30 = ADD32(0, 0X4);
    // 0x80018950: addiu       $s5, $zero, 0x42
    ctx->r21 = ADD32(0, 0X42);
    // 0x80018954: sh          $t9, 0x68($sp)
    MEM_H(0X68, ctx->r29) = ctx->r25;
    // 0x80018958: sh          $t0, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r8;
    // 0x8001895C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_80018960:
    // 0x80018960: sw          $t7, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r15;
    // 0x80018964: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
    // 0x80018968: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8001896C: jal         0x8004D134
    // 0x80018970: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004D134(rdram, ctx);
        goto after_224;
    // 0x80018970: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_224:
    // 0x80018974: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80018978: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    // 0x8001897C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80018980: jal         0x80004CE0
    // 0x80018984: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    func_80004CE0(rdram, ctx);
        goto after_225;
    // 0x80018984: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    after_225:
    // 0x80018988: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x8001898C: jal         0x8004B1E0
    // 0x80018990: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_8004B1E0(rdram, ctx);
        goto after_226;
    // 0x80018990: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_226:
    // 0x80018994: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80018998: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001899C: jal         0x8000BD4C
    // 0x800189A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BD4C(rdram, ctx);
        goto after_227;
    // 0x800189A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_227:
    // 0x800189A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800189A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800189AC: jal         0x8000BDEC
    // 0x800189B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BDEC(rdram, ctx);
        goto after_228;
    // 0x800189B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_228:
    // 0x800189B4: addiu       $t8, $zero, 0x3E8
    ctx->r24 = ADD32(0, 0X3E8);
    // 0x800189B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800189BC: sw          $t8, -0x2CF8($at)
    MEM_W(-0X2CF8, ctx->r1) = ctx->r24;
    // 0x800189C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800189C4: addiu       $t9, $zero, 0x3D0
    ctx->r25 = ADD32(0, 0X3D0);
    // 0x800189C8: sw          $t9, -0x2CF4($at)
    MEM_W(-0X2CF4, ctx->r1) = ctx->r25;
    // 0x800189CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800189D0: sh          $zero, -0x2CC4($at)
    MEM_H(-0X2CC4, ctx->r1) = 0;
    // 0x800189D4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800189D8: lui         $at, 0x4238
    ctx->r1 = S32(0X4238 << 16);
    // 0x800189DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800189E0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800189E4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800189E8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800189EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800189F0: addiu       $v1, $v1, -0x6C40
    ctx->r3 = ADD32(ctx->r3, -0X6C40);
    // 0x800189F4: addiu       $v0, $v0, -0x6C50
    ctx->r2 = ADD32(ctx->r2, -0X6C50);
    // 0x800189F8: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x800189FC: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x80018A00: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x80018A04: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x80018A08: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80018A0C: jal         0x8000798C
    // 0x80018A10: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    func_8000798C(rdram, ctx);
        goto after_229;
    // 0x80018A10: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    after_229:
    // 0x80018A14: jal         0x8000798C
    // 0x80018A18: nop

    func_8000798C(rdram, ctx);
        goto after_230;
    // 0x80018A18: nop

    after_230:
    // 0x80018A1C: jal         0x8000798C
    // 0x80018A20: nop

    func_8000798C(rdram, ctx);
        goto after_231;
    // 0x80018A20: nop

    after_231:
    // 0x80018A24: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80018A28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80018A2C: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x80018A30: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80018A34: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80018A38: jal         0x8004C580
    // 0x80018A3C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_232;
    // 0x80018A3C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_232:
    // 0x80018A40: lw          $t0, 0xA0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA0);
L_80018A44:
    // 0x80018A44: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80018A48: bnel        $t0, $at, L_80018AE0
    if (ctx->r8 != ctx->r1) {
        // 0x80018A4C: lw          $t0, 0xA0($sp)
        ctx->r8 = MEM_W(ctx->r29, 0XA0);
            goto L_80018AE0;
    }
    goto skip_34;
    // 0x80018A4C: lw          $t0, 0xA0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA0);
    skip_34:
    // 0x80018A50: beq         $s1, $fp, L_80018A5C
    if (ctx->r17 == ctx->r30) {
        // 0x80018A54: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80018A5C;
    }
    // 0x80018A54: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80018A58: bne         $s1, $at, L_80018ADC
    if (ctx->r17 != ctx->r1) {
        // 0x80018A5C: lui         $t1, 0x800E
        ctx->r9 = S32(0X800E << 16);
            goto L_80018ADC;
    }
L_80018A5C:
    // 0x80018A5C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80018A60: lhu         $t1, -0x2E5A($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X2E5A);
    // 0x80018A64: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x80018A68: andi        $t2, $t1, 0x9000
    ctx->r10 = ctx->r9 & 0X9000;
    // 0x80018A6C: beql        $t2, $zero, L_80018AE0
    if (ctx->r10 == 0) {
        // 0x80018A70: lw          $t0, 0xA0($sp)
        ctx->r8 = MEM_W(ctx->r29, 0XA0);
            goto L_80018AE0;
    }
    goto skip_35;
    // 0x80018A70: lw          $t0, 0xA0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA0);
    skip_35:
    // 0x80018A74: jal         0x80044480
    // 0x80018A78: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    func_80044480(rdram, ctx);
        goto after_233;
    // 0x80018A78: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    after_233:
    // 0x80018A7C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80018A80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80018A84: jal         0x8004D134
    // 0x80018A88: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_8004D134(rdram, ctx);
        goto after_234;
    // 0x80018A88: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_234:
    // 0x80018A8C: lh          $t4, 0x68($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X68);
    // 0x80018A90: lh          $t5, 0x6A($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X6A);
    // 0x80018A94: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80018A98: lh          $t6, 0x6C($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X6C);
    // 0x80018A9C: sh          $t4, 0x6ACC($at)
    MEM_H(0X6ACC, ctx->r1) = ctx->r12;
    // 0x80018AA0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80018AA4: lh          $t8, 0x6E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X6E);
    // 0x80018AA8: sh          $t5, -0x6B90($at)
    MEM_H(-0X6B90, ctx->r1) = ctx->r13;
    // 0x80018AAC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80018AB0: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x80018AB4: sh          $t7, 0x6ACE($at)
    MEM_H(0X6ACE, ctx->r1) = ctx->r15;
    // 0x80018AB8: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80018ABC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80018AC0: xori        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 ^ 0X1;
    // 0x80018AC4: sw          $t3, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r11;
    // 0x80018AC8: sh          $t9, 0x6AD0($at)
    MEM_H(0X6AD0, ctx->r1) = ctx->r25;
    // 0x80018ACC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80018AD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80018AD4: jal         0x8001A37C
    // 0x80018AD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8001A37C(rdram, ctx);
        goto after_235;
    // 0x80018AD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_235:
L_80018ADC:
    // 0x80018ADC: lw          $t0, 0xA0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA0);
L_80018AE0:
    // 0x80018AE0: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80018AE4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80018AE8: bne         $t0, $at, L_80018BF4
    if (ctx->r8 != ctx->r1) {
        // 0x80018AEC: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_80018BF4;
    }
    // 0x80018AEC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80018AF0: beq         $s1, $fp, L_80018B08
    if (ctx->r17 == ctx->r30) {
        // 0x80018AF4: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80018B08;
    }
    // 0x80018AF4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80018AF8: beql        $s1, $at, L_80018BA0
    if (ctx->r17 == ctx->r1) {
        // 0x80018AFC: sll         $a2, $zero, 16
        ctx->r6 = S32(0 << 16);
            goto L_80018BA0;
    }
    goto skip_36;
    // 0x80018AFC: sll         $a2, $zero, 16
    ctx->r6 = S32(0 << 16);
    skip_36:
    // 0x80018B00: b           L_80018BF4
    // 0x80018B04: nop

        goto L_80018BF4;
    // 0x80018B04: nop

L_80018B08:
    // 0x80018B08: lui         $s0, 0x8002
    ctx->r16 = S32(0X8002 << 16);
    // 0x80018B0C: addiu       $s0, $s0, -0x6AFC
    ctx->r16 = ADD32(ctx->r16, -0X6AFC);
    // 0x80018B10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80018B14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80018B18: jal         0x8004C4D8
    // 0x80018B1C: addiu       $s2, $sp, 0x98
    ctx->r18 = ADD32(ctx->r29, 0X98);
    func_8004C4D8(rdram, ctx);
        goto after_236;
    // 0x80018B1C: addiu       $s2, $sp, 0x98
    ctx->r18 = ADD32(ctx->r29, 0X98);
    after_236:
    // 0x80018B20: jal         0x8004B21C
    // 0x80018B24: nop

    func_8004B21C(rdram, ctx);
        goto after_237;
    // 0x80018B24: nop

    after_237:
    // 0x80018B28: jal         0x80004E5C
    // 0x80018B2C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_80004E5C(rdram, ctx);
        goto after_238;
    // 0x80018B2C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_238:
    // 0x80018B30: jal         0x8000798C
    // 0x80018B34: nop

    func_8000798C(rdram, ctx);
        goto after_239;
    // 0x80018B34: nop

    after_239:
    // 0x80018B38: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80018B3C: sw          $t1, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r9;
    // 0x80018B40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80018B44: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80018B48: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80018B4C: jal         0x80004CE0
    // 0x80018B50: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    func_80004CE0(rdram, ctx);
        goto after_240;
    // 0x80018B50: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_240:
    // 0x80018B54: lw          $t2, 0x98($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X98);
    // 0x80018B58: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80018B5C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80018B60: bnel        $t2, $at, L_80018B84
    if (ctx->r10 != ctx->r1) {
        // 0x80018B64: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80018B84;
    }
    goto skip_37;
    // 0x80018B64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_37:
L_80018B68:
    // 0x80018B68: jal         0x8000798C
    // 0x80018B6C: nop

    func_8000798C(rdram, ctx);
        goto after_241;
    // 0x80018B6C: nop

    after_241:
    // 0x80018B70: lw          $t3, 0x98($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X98);
    // 0x80018B74: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80018B78: beq         $t3, $at, L_80018B68
    if (ctx->r11 == ctx->r1) {
        // 0x80018B7C: nop
    
            goto L_80018B68;
    }
    // 0x80018B7C: nop

    // 0x80018B80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80018B84:
    // 0x80018B84: jal         0x80004E5C
    // 0x80018B88: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    func_80004E5C(rdram, ctx);
        goto after_242;
    // 0x80018B88: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    after_242:
    // 0x80018B8C: jal         0x8000798C
    // 0x80018B90: nop

    func_8000798C(rdram, ctx);
        goto after_243;
    // 0x80018B90: nop

    after_243:
    // 0x80018B94: b           L_80018960
    // 0x80018B98: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
        goto L_80018960;
    // 0x80018B98: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80018B9C: sll         $a2, $zero, 16
    ctx->r6 = S32(0 << 16);
L_80018BA0:
    // 0x80018BA0: sra         $t4, $a2, 16
    ctx->r12 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80018BA4: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x80018BA8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80018BAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80018BB0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80018BB4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80018BB8: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80018BBC: jal         0x8004C4D8
    // 0x80018BC0: addiu       $v1, $zero, 0x80
    ctx->r3 = ADD32(0, 0X80);
    func_8004C4D8(rdram, ctx);
        goto after_244;
    // 0x80018BC0: addiu       $v1, $zero, 0x80
    ctx->r3 = ADD32(0, 0X80);
    after_244:
    // 0x80018BC4: jal         0x8004B21C
    // 0x80018BC8: nop

    func_8004B21C(rdram, ctx);
        goto after_245;
    // 0x80018BC8: nop

    after_245:
    // 0x80018BCC: jal         0x80004E5C
    // 0x80018BD0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_80004E5C(rdram, ctx);
        goto after_246;
    // 0x80018BD0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_246:
    // 0x80018BD4: jal         0x8000798C
    // 0x80018BD8: nop

    func_8000798C(rdram, ctx);
        goto after_247;
    // 0x80018BD8: nop

    after_247:
    // 0x80018BDC: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x80018BE0: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
L_80018BE4:
    // 0x80018BE4: jal         0x8000798C
    // 0x80018BE8: nop

    func_8000798C(rdram, ctx);
        goto after_248;
    // 0x80018BE8: nop

    after_248:
    // 0x80018BEC: b           L_80018BE4
    // 0x80018BF0: nop

        goto L_80018BE4;
    // 0x80018BF0: nop

L_80018BF4:
    // 0x80018BF4: bnel        $s2, $zero, L_80018CF4
    if (ctx->r18 != 0) {
        // 0x80018BF8: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80018CF4;
    }
    goto skip_38;
    // 0x80018BF8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    skip_38:
    // 0x80018BFC: lhu         $a1, -0x2E5A($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X2E5A);
    // 0x80018C00: sll         $a2, $s1, 16
    ctx->r6 = S32(ctx->r17 << 16);
    // 0x80018C04: sra         $t6, $a2, 16
    ctx->r14 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80018C08: andi        $t7, $a1, 0x400
    ctx->r15 = ctx->r5 & 0X400;
    // 0x80018C0C: bne         $t7, $zero, L_80018C24
    if (ctx->r15 != 0) {
        // 0x80018C10: or          $a2, $t6, $zero
        ctx->r6 = ctx->r14 | 0;
            goto L_80018C24;
    }
    // 0x80018C10: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80018C14: lh          $v0, -0x2E4C($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2E4C);
    // 0x80018C18: andi        $t1, $a1, 0x800
    ctx->r9 = ctx->r5 & 0X800;
    // 0x80018C1C: andi        $t8, $v0, 0x400
    ctx->r24 = ctx->r2 & 0X400;
    // 0x80018C20: beq         $t8, $zero, L_80018C40
    if (ctx->r24 == 0) {
        // 0x80018C24: slti        $at, $s1, 0x5
        ctx->r1 = SIGNED(ctx->r17) < 0X5 ? 1 : 0;
            goto L_80018C40;
    }
L_80018C24:
    // 0x80018C24: slti        $at, $s1, 0x5
    ctx->r1 = SIGNED(ctx->r17) < 0X5 ? 1 : 0;
    // 0x80018C28: beq         $at, $zero, L_80018C64
    if (ctx->r1 == 0) {
        // 0x80018C2C: nop
    
            goto L_80018C64;
    }
    // 0x80018C2C: nop

    // 0x80018C30: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80018C34: sll         $t9, $s1, 16
    ctx->r25 = S32(ctx->r17 << 16);
    // 0x80018C38: b           L_80018C64
    // 0x80018C3C: sra         $s1, $t9, 16
    ctx->r17 = S32(SIGNED(ctx->r25) >> 16);
        goto L_80018C64;
    // 0x80018C3C: sra         $s1, $t9, 16
    ctx->r17 = S32(SIGNED(ctx->r25) >> 16);
L_80018C40:
    // 0x80018C40: bne         $t1, $zero, L_80018C50
    if (ctx->r9 != 0) {
        // 0x80018C44: andi        $t2, $v0, 0x800
        ctx->r10 = ctx->r2 & 0X800;
            goto L_80018C50;
    }
    // 0x80018C44: andi        $t2, $v0, 0x800
    ctx->r10 = ctx->r2 & 0X800;
    // 0x80018C48: beq         $t2, $zero, L_80018C64
    if (ctx->r10 == 0) {
        // 0x80018C4C: nop
    
            goto L_80018C64;
    }
    // 0x80018C4C: nop

L_80018C50:
    // 0x80018C50: blez        $s1, L_80018C64
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80018C54: nop
    
            goto L_80018C64;
    }
    // 0x80018C54: nop

    // 0x80018C58: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80018C5C: sll         $t3, $s1, 16
    ctx->r11 = S32(ctx->r17 << 16);
    // 0x80018C60: sra         $s1, $t3, 16
    ctx->r17 = S32(SIGNED(ctx->r11) >> 16);
L_80018C64:
    // 0x80018C64: beql        $a2, $s1, L_80018C78
    if (ctx->r6 == ctx->r17) {
        // 0x80018C68: slti        $at, $s1, 0x4
        ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
            goto L_80018C78;
    }
    goto skip_39;
    // 0x80018C68: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    skip_39:
    // 0x80018C6C: jal         0x80044480
    // 0x80018C70: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    func_80044480(rdram, ctx);
        goto after_249;
    // 0x80018C70: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_249:
    // 0x80018C74: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
L_80018C78:
    // 0x80018C78: beq         $at, $zero, L_80018CF0
    if (ctx->r1 == 0) {
        // 0x80018C7C: sll         $t5, $s1, 1
        ctx->r13 = S32(ctx->r17 << 1);
            goto L_80018CF0;
    }
    // 0x80018C7C: sll         $t5, $s1, 1
    ctx->r13 = S32(ctx->r17 << 1);
    // 0x80018C80: addu        $v1, $s4, $t5
    ctx->r3 = ADD32(ctx->r20, ctx->r13);
    // 0x80018C84: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x80018C88: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80018C8C: lhu         $a1, -0x2E5A($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X2E5A);
    // 0x80018C90: sll         $a2, $a0, 16
    ctx->r6 = S32(ctx->r4 << 16);
    // 0x80018C94: sra         $t6, $a2, 16
    ctx->r14 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80018C98: andi        $t7, $a1, 0x200
    ctx->r15 = ctx->r5 & 0X200;
    // 0x80018C9C: bne         $t7, $zero, L_80018CBC
    if (ctx->r15 != 0) {
        // 0x80018CA0: or          $a2, $t6, $zero
        ctx->r6 = ctx->r14 | 0;
            goto L_80018CBC;
    }
    // 0x80018CA0: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80018CA4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80018CA8: lh          $v0, -0x2E4C($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2E4C);
    // 0x80018CAC: andi        $t9, $a1, 0x100
    ctx->r25 = ctx->r5 & 0X100;
    // 0x80018CB0: andi        $t8, $v0, 0x200
    ctx->r24 = ctx->r2 & 0X200;
    // 0x80018CB4: beq         $t8, $zero, L_80018CC8
    if (ctx->r24 == 0) {
        // 0x80018CB8: nop
    
            goto L_80018CC8;
    }
    // 0x80018CB8: nop

L_80018CBC:
    // 0x80018CBC: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x80018CC0: b           L_80018CE0
    // 0x80018CC4: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
        goto L_80018CE0;
    // 0x80018CC4: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
L_80018CC8:
    // 0x80018CC8: bne         $t9, $zero, L_80018CD4
    if (ctx->r25 != 0) {
        // 0x80018CCC: andi        $t0, $v0, 0x100
        ctx->r8 = ctx->r2 & 0X100;
            goto L_80018CD4;
    }
    // 0x80018CCC: andi        $t0, $v0, 0x100
    ctx->r8 = ctx->r2 & 0X100;
    // 0x80018CD0: beq         $t0, $zero, L_80018CE0
    if (ctx->r8 == 0) {
        // 0x80018CD4: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_80018CE0;
    }
L_80018CD4:
    // 0x80018CD4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80018CD8: sh          $t1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r9;
    // 0x80018CDC: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
L_80018CE0:
    // 0x80018CE0: beql        $a2, $a0, L_80018CF4
    if (ctx->r6 == ctx->r4) {
        // 0x80018CE4: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80018CF4;
    }
    goto skip_40;
    // 0x80018CE4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    skip_40:
    // 0x80018CE8: jal         0x80044480
    // 0x80018CEC: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    func_80044480(rdram, ctx);
        goto after_250;
    // 0x80018CEC: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_250:
L_80018CF0:
    // 0x80018CF0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80018CF4:
    // 0x80018CF4: bne         $s1, $s0, L_80018D0C
    if (ctx->r17 != ctx->r16) {
        // 0x80018CF8: addiu       $v1, $zero, 0x80
        ctx->r3 = ADD32(0, 0X80);
            goto L_80018D0C;
    }
    // 0x80018CF8: addiu       $v1, $zero, 0x80
    ctx->r3 = ADD32(0, 0X80);
    // 0x80018CFC: andi        $v1, $s3, 0x7F
    ctx->r3 = ctx->r19 & 0X7F;
    // 0x80018D00: addiu       $v1, $v1, 0x80
    ctx->r3 = ADD32(ctx->r3, 0X80);
    // 0x80018D04: sll         $t2, $v1, 16
    ctx->r10 = S32(ctx->r3 << 16);
    // 0x80018D08: sra         $v1, $t2, 16
    ctx->r3 = S32(SIGNED(ctx->r10) >> 16);
L_80018D0C:
    // 0x80018D0C: sll         $t5, $s0, 1
    ctx->r13 = S32(ctx->r16 << 1);
    // 0x80018D10: addu        $t6, $s4, $t5
    ctx->r14 = ADD32(ctx->r20, ctx->r13);
    // 0x80018D14: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x80018D18: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x80018D1C: addu        $v0, $s6, $t4
    ctx->r2 = ADD32(ctx->r22, ctx->r12);
    // 0x80018D20: multu       $t7, $s5
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80018D24: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x80018D28: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80018D2C: sll         $t2, $a2, 24
    ctx->r10 = S32(ctx->r6 << 24);
    // 0x80018D30: sra         $a2, $t2, 16
    ctx->r6 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80018D34: lh          $a1, 0x2($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X2);
    // 0x80018D38: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80018D3C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80018D40: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x80018D44: mflo        $t8
    ctx->r24 = lo;
    // 0x80018D48: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x80018D4C: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80018D50: sll         $t0, $a0, 16
    ctx->r8 = S32(ctx->r4 << 16);
    // 0x80018D54: jal         0x8004C580
    // 0x80018D58: sra         $a0, $t0, 16
    ctx->r4 = S32(SIGNED(ctx->r8) >> 16);
    func_8004C580(rdram, ctx);
        goto after_251;
    // 0x80018D58: sra         $a0, $t0, 16
    ctx->r4 = S32(SIGNED(ctx->r8) >> 16);
    after_251:
    // 0x80018D5C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80018D60: sll         $t4, $s0, 16
    ctx->r12 = S32(ctx->r16 << 16);
    // 0x80018D64: sra         $s0, $t4, 16
    ctx->r16 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80018D68: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x80018D6C: bne         $at, $zero, L_80018CF4
    if (ctx->r1 != 0) {
        // 0x80018D70: nop
    
            goto L_80018CF4;
    }
    // 0x80018D70: nop

    // 0x80018D74: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x80018D78: addiu       $t7, $t7, -0x65D0
    ctx->r15 = ADD32(ctx->r15, -0X65D0);
    // 0x80018D7C: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x80018D80: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80018D84: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x80018D88: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80018D8C: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x80018D90: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80018D94: sll         $t0, $a0, 16
    ctx->r8 = S32(ctx->r4 << 16);
    // 0x80018D98: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80018D9C: sra         $a0, $t0, 16
    ctx->r4 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80018DA0: lh          $a1, 0x2($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X2);
    // 0x80018DA4: addiu       $a2, $zero, -0x100
    ctx->r6 = ADD32(0, -0X100);
    // 0x80018DA8: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x80018DAC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80018DB0: jal         0x8004C580
    // 0x80018DB4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_252;
    // 0x80018DB4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_252:
    // 0x80018DB8: jal         0x8000798C
    // 0x80018DBC: nop

    func_8000798C(rdram, ctx);
        goto after_253;
    // 0x80018DBC: nop

    after_253:
    // 0x80018DC0: b           L_80018A44
    // 0x80018DC4: lw          $t0, 0xA0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA0);
        goto L_80018A44;
    // 0x80018DC4: lw          $t0, 0xA0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA0);
    // 0x80018DC8: nop

    // 0x80018DCC: nop

    // 0x80018DD0: nop

    // 0x80018DD4: nop

    // 0x80018DD8: nop

    // 0x80018DDC: nop

    // 0x80018DE0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80018DE4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80018DE8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80018DEC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80018DF0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80018DF4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80018DF8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80018DFC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80018E00: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80018E04: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80018E08: jr          $ra
    // 0x80018E0C: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    TRACE_RETURN()
    return;
    // 0x80018E0C: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_80016674(uint8_t* rdram, recomp_context* ctx) { func_80016674_entry(rdram, ctx, 0); }
RECOMP_FUNC void func_80016950(uint8_t* rdram, recomp_context* ctx) { func_80016674_entry(rdram, ctx, 1); }
RECOMP_FUNC void func_80016BD0(uint8_t* rdram, recomp_context* ctx) { func_80016674_entry(rdram, ctx, 2); }
RECOMP_FUNC void func_80017130(uint8_t* rdram, recomp_context* ctx) { func_80016674_entry(rdram, ctx, 3); }
RECOMP_FUNC void func_80017290(uint8_t* rdram, recomp_context* ctx) { func_80016674_entry(rdram, ctx, 4); }
RECOMP_FUNC void func_800179A0(uint8_t* rdram, recomp_context* ctx) { func_80016674_entry(rdram, ctx, 5); }
RECOMP_FUNC void func_800180C0(uint8_t* rdram, recomp_context* ctx) { func_80016674_entry(rdram, ctx, 6); }

