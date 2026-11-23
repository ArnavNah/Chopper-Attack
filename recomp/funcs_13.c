#include "recomp.h"
#include "trace.h"
#include "funcs.h"
#include "chopper_recomp_hooks.h"

static void func_800233C4_entry(uint8_t* rdram, recomp_context* ctx, unsigned entry) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    if (entry == 1) goto indirect_800237E0;

    // 0x800233C4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800233C8: lh          $t6, -0x6BA6($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X6BA6);
    // 0x800233CC: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x800233D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800233D4: sw          $a0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r4;
    // 0x800233D8: beq         $t6, $zero, L_800237C8
    if (ctx->r14 == 0) {
        // 0x800233DC: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_800237C8;
    }
    // 0x800233DC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800233E0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800233E4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800233E8: addiu       $a0, $a0, -0x6888
    ctx->r4 = ADD32(ctx->r4, -0X6888);
    // 0x800233EC: addiu       $v1, $v1, -0x68B0
    ctx->r3 = ADD32(ctx->r3, -0X68B0);
L_800233F0:
    // 0x800233F0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800233F4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800233F8: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x800233FC: lh          $t7, 0xE2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XE2);
    // 0x80023400: ori         $t8, $t7, 0x20
    ctx->r24 = ctx->r15 | 0X20;
    // 0x80023404: bne         $at, $zero, L_800233F0
    if (ctx->r1 != 0) {
        // 0x80023408: sh          $t8, 0xE2($v0)
        MEM_H(0XE2, ctx->r2) = ctx->r24;
            goto L_800233F0;
    }
    // 0x80023408: sh          $t8, 0xE2($v0)
    MEM_H(0XE2, ctx->r2) = ctx->r24;
    // 0x8002340C: lw          $t9, 0xE0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE0);
    // 0x80023410: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80023414: lh          $t1, 0xE8($t9)
    ctx->r9 = MEM_H(ctx->r25, 0XE8);
    // 0x80023418: blezl       $t1, L_800237CC
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8002341C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800237CC;
    }
    goto skip_0;
    // 0x8002341C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80023420: lhu         $v0, -0x2E44($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2E44);
    // 0x80023424: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x80023428: andi        $t2, $v0, 0xC000
    ctx->r10 = ctx->r2 & 0XC000;
    // 0x8002342C: beq         $t2, $zero, L_80023448
    if (ctx->r10 == 0) {
        // 0x80023430: sll         $a1, $v0, 16
        ctx->r5 = S32(ctx->r2 << 16);
            goto L_80023448;
    }
    // 0x80023430: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x80023434: sra         $t3, $a1, 16
    ctx->r11 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80023438: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x8002343C: jal         0x800200F8
    // 0x80023440: sh          $t0, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r8;
    func_800200F8(rdram, ctx);
        goto after_0;
    // 0x80023440: sh          $t0, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r8;
    after_0:
    // 0x80023444: lh          $t0, 0x42($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X42);
L_80023448:
    // 0x80023448: lw          $t4, 0xE0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE0);
    // 0x8002344C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80023450: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80023454: lh          $t5, 0xDC($t4)
    ctx->r13 = MEM_H(ctx->r12, 0XDC);
    // 0x80023458: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002345C: addiu       $t8, $zero, -0x1F4
    ctx->r24 = ADD32(0, -0X1F4);
    // 0x80023460: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80023464: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80023468: lh          $t7, -0x6BC8($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X6BC8);
    // 0x8002346C: addiu       $t9, $zero, -0x32
    ctx->r25 = ADD32(0, -0X32);
    // 0x80023470: addiu       $a0, $sp, 0xA0
    ctx->r4 = ADD32(ctx->r29, 0XA0);
    // 0x80023474: bnel        $t7, $at, L_80023488
    if (ctx->r15 != ctx->r1) {
        // 0x80023478: sw          $t9, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r25;
            goto L_80023488;
    }
    goto skip_1;
    // 0x80023478: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    skip_1:
    // 0x8002347C: b           L_80023488
    // 0x80023480: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
        goto L_80023488;
    // 0x80023480: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x80023484: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
L_80023488:
    // 0x80023488: lw          $t1, 0xE0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE0);
    // 0x8002348C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80023490: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80023494: lw          $a1, 0x14($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X14);
    // 0x80023498: sh          $t0, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r8;
    // 0x8002349C: jal         0x80049840
    // 0x800234A0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80049840(rdram, ctx);
        goto after_1;
    // 0x800234A0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800234A4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800234A8: lw          $t2, 0xE0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XE0);
    // 0x800234AC: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x800234B0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800234B4: lw          $a1, 0x18($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X18);
    // 0x800234B8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800234BC: jal         0x80049840
    // 0x800234C0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80049840(rdram, ctx);
        goto after_2;
    // 0x800234C0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x800234C4: addiu       $a0, $sp, 0xA0
    ctx->r4 = ADD32(ctx->r29, 0XA0);
    // 0x800234C8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800234CC: jal         0x80000BD8
    // 0x800234D0: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    func_80000BD8(rdram, ctx);
        goto after_3;
    // 0x800234D0: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    after_3:
    // 0x800234D4: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x800234D8: lh          $t0, 0x42($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X42);
    // 0x800234DC: addiu       $v1, $sp, 0x50
    ctx->r3 = ADD32(ctx->r29, 0X50);
    // 0x800234E0: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800234E4: addiu       $v0, $sp, 0xA0
    ctx->r2 = ADD32(ctx->r29, 0XA0);
    // 0x800234E8: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x800234EC: addiu       $a1, $sp, 0xAC
    ctx->r5 = ADD32(ctx->r29, 0XAC);
    // 0x800234F0: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800234F4: lwc1        $f14, 0x20($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800234F8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800234FC: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x80023500: mul.s       $f18, $f14, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80023504: beql        $at, $zero, L_80023538
    if (ctx->r1 == 0) {
        // 0x80023508: lwc1        $f16, 0x8($a0)
        ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
            goto L_80023538;
    }
    goto skip_2;
    // 0x80023508: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    skip_2:
L_8002350C:
    // 0x8002350C: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80023510: lwc1        $f14, 0x20($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80023514: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80023518: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8002351C: mul.s       $f18, $f14, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80023520: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x80023524: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80023528: swc1        $f16, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f16.u32l;
    // 0x8002352C: bne         $at, $zero, L_8002350C
    if (ctx->r1 != 0) {
        // 0x80023530: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_8002350C;
    }
    // 0x80023530: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80023534: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
L_80023538:
    // 0x80023538: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8002353C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80023540: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80023544: swc1        $f16, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f16.u32l;
    // 0x80023548: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8002354C: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x80023550: jal         0x8000C94C
    // 0x80023554: sh          $t0, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r8;
    chopper_aim_reticle(rdram, ctx, MEM_W(0XE0, ctx->r29));
        goto after_4;
    // 0x80023554: sh          $t0, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r8;
    after_4:
    // 0x80023558: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8002355C: lh          $t0, 0x42($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X42);
    // 0x80023560: beq         $v0, $zero, L_800235D0
    if (ctx->r2 == 0) {
        // 0x80023564: sw          $v0, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r2;
            goto L_800235D0;
    }
    // 0x80023564: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80023568: lw          $a1, 0xE0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE0);
    // 0x8002356C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80023570: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80023574: lh          $t4, 0xDC($a1)
    ctx->r12 = MEM_H(ctx->r5, 0XDC);
    // 0x80023578: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8002357C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80023580: lh          $t6, -0x6BC8($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X6BC8);
    // 0x80023584: bne         $t6, $at, L_800235D0
    if (ctx->r14 != ctx->r1) {
        // 0x80023588: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800235D0;
    }
    // 0x80023588: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002358C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80023590: lwc1        $f12, 0x14($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80023594: add.s       $f18, $f12, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x80023598: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x8002359C: nop

    // 0x800235A0: bc1fl       L_800235D4
    if (!c1cs) {
        // 0x800235A4: lw          $a1, 0xE0($sp)
        ctx->r5 = MEM_W(ctx->r29, 0XE0);
            goto L_800235D4;
    }
    goto skip_3;
    // 0x800235A4: lw          $a1, 0xE0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE0);
    skip_3:
    // 0x800235A8: jal         0x8000E16C
    // 0x800235AC: sh          $t0, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r8;
    func_8000E16C(rdram, ctx);
        goto after_5;
    // 0x800235AC: sh          $t0, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r8;
    after_5:
    // 0x800235B0: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x800235B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800235B8: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800235BC: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x800235C0: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800235C4: lh          $t0, 0x42($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X42);
    // 0x800235C8: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800235CC: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
L_800235D0:
    // 0x800235D0: lw          $a1, 0xE0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE0);
L_800235D4:
    // 0x800235D4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800235D8: addiu       $t9, $t9, -0x6BC8
    ctx->r25 = ADD32(ctx->r25, -0X6BC8);
    // 0x800235DC: lh          $t7, 0xDC($a1)
    ctx->r15 = MEM_H(ctx->r5, 0XDC);
    // 0x800235E0: addiu       $t3, $zero, 0x9
    ctx->r11 = ADD32(0, 0X9);
    // 0x800235E4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800235E8: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x800235EC: lh          $t1, 0x2($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X2);
    // 0x800235F0: beql        $t1, $zero, L_80023734
    if (ctx->r9 == 0) {
        // 0x800235F4: sh          $t3, 0x34($sp)
        MEM_H(0X34, ctx->r29) = ctx->r11;
            goto L_80023734;
    }
    goto skip_4;
    // 0x800235F4: sh          $t3, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r11;
    skip_4:
    // 0x800235F8: lh          $a2, 0x0($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X0);
    // 0x800235FC: addiu       $t2, $a2, -0x1
    ctx->r10 = ADD32(ctx->r6, -0X1);
    // 0x80023600: sltiu       $at, $t2, 0x8
    ctx->r1 = ctx->r10 < 0X8 ? 1 : 0;
    // 0x80023604: beq         $at, $zero, L_80023734
    if (ctx->r1 == 0) {
        // 0x80023608: sh          $a2, 0x34($sp)
        MEM_H(0X34, ctx->r29) = ctx->r6;
            goto L_80023734;
    }
    // 0x80023608: sh          $a2, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r6;
    // 0x8002360C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80023610: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80023614: addu        $at, $at, $t2
    gpr jr_addend_8002361C = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80023618: lw          $t2, 0x67F8($at)
    ctx->r10 = ADD32(ctx->r1, 0X67F8);
    // 0x8002361C: jr          $t2
    // 0x80023620: nop

    switch (jr_addend_8002361C >> 2) {
        case 0: goto L_80023624; break;
        case 1: goto L_80023624; break;
        case 2: goto L_80023624; break;
        case 3: goto L_80023710; break;
        case 4: goto L_80023720; break;
        case 5: goto L_80023700; break;
        case 6: goto L_80023698; break;
        case 7: goto L_800236CC; break;
        default: switch_error(__func__, 0x8002361C, 0x800767F8);
    }
    // 0x80023620: nop

L_80023624:
    // 0x80023624: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80023628: beq         $a2, $at, L_80023650
    if (ctx->r6 == ctx->r1) {
        // 0x8002362C: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_80023650;
    }
    // 0x8002362C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80023630: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80023634: beq         $v0, $at, L_8002365C
    if (ctx->r2 == ctx->r1) {
        // 0x80023638: addiu       $t4, $zero, 0x2
        ctx->r12 = ADD32(0, 0X2);
            goto L_8002365C;
    }
    // 0x80023638: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8002363C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80023640: beq         $v0, $at, L_80023664
    if (ctx->r2 == ctx->r1) {
        // 0x80023644: addiu       $t5, $zero, 0x3
        ctx->r13 = ADD32(0, 0X3);
            goto L_80023664;
    }
    // 0x80023644: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80023648: b           L_8002366C
    // 0x8002364C: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
        goto L_8002366C;
    // 0x8002364C: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
L_80023650:
    // 0x80023650: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80023654: b           L_80023668
    // 0x80023658: sh          $t3, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r11;
        goto L_80023668;
    // 0x80023658: sh          $t3, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r11;
L_8002365C:
    // 0x8002365C: b           L_80023668
    // 0x80023660: sh          $t4, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r12;
        goto L_80023668;
    // 0x80023660: sh          $t4, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r12;
L_80023664:
    // 0x80023664: sh          $t5, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r13;
L_80023668:
    // 0x80023668: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
L_8002366C:
    // 0x8002366C: beq         $t6, $zero, L_80023688
    if (ctx->r14 == 0) {
        // 0x80023670: nop
    
            goto L_80023688;
    }
    // 0x80023670: nop

    // 0x80023674: jal         0x80022C88
    // 0x80023678: lh          $a3, 0x36($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X36);
    func_80022C88(rdram, ctx);
        goto after_6;
    // 0x80023678: lh          $a3, 0x36($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X36);
    after_6:
    // 0x8002367C: sll         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2 << 16);
    // 0x80023680: sra         $t7, $t0, 16
    ctx->r15 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80023684: or          $t0, $t7, $zero
    ctx->r8 = ctx->r15 | 0;
L_80023688:
    // 0x80023688: beql        $t0, $zero, L_80023738
    if (ctx->r8 == 0) {
        // 0x8002368C: lw          $t4, 0x44($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X44);
            goto L_80023738;
    }
    goto skip_5;
    // 0x8002368C: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    skip_5:
    // 0x80023690: b           L_80023734
    // 0x80023694: sh          $zero, 0x34($sp)
    MEM_H(0X34, ctx->r29) = 0;
        goto L_80023734;
    // 0x80023694: sh          $zero, 0x34($sp)
    MEM_H(0X34, ctx->r29) = 0;
L_80023698:
    // 0x80023698: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8002369C: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x800236A0: beq         $t8, $zero, L_800236BC
    if (ctx->r24 == 0) {
        // 0x800236A4: nop
    
            goto L_800236BC;
    }
    // 0x800236A4: nop

    // 0x800236A8: jal         0x80022C88
    // 0x800236AC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_80022C88(rdram, ctx);
        goto after_7;
    // 0x800236AC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_7:
    // 0x800236B0: sll         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2 << 16);
    // 0x800236B4: sra         $t9, $t0, 16
    ctx->r25 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800236B8: or          $t0, $t9, $zero
    ctx->r8 = ctx->r25 | 0;
L_800236BC:
    // 0x800236BC: beql        $t0, $zero, L_80023738
    if (ctx->r8 == 0) {
        // 0x800236C0: lw          $t4, 0x44($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X44);
            goto L_80023738;
    }
    goto skip_6;
    // 0x800236C0: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    skip_6:
    // 0x800236C4: b           L_80023734
    // 0x800236C8: sh          $zero, 0x34($sp)
    MEM_H(0X34, ctx->r29) = 0;
        goto L_80023734;
    // 0x800236C8: sh          $zero, 0x34($sp)
    MEM_H(0X34, ctx->r29) = 0;
L_800236CC:
    // 0x800236CC: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800236D0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x800236D4: beq         $t1, $zero, L_800236F0
    if (ctx->r9 == 0) {
        // 0x800236D8: nop
    
            goto L_800236F0;
    }
    // 0x800236D8: nop

    // 0x800236DC: jal         0x80022C88
    // 0x800236E0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_80022C88(rdram, ctx);
        goto after_8;
    // 0x800236E0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_8:
    // 0x800236E4: sll         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2 << 16);
    // 0x800236E8: sra         $t2, $t0, 16
    ctx->r10 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800236EC: or          $t0, $t2, $zero
    ctx->r8 = ctx->r10 | 0;
L_800236F0:
    // 0x800236F0: beql        $t0, $zero, L_80023738
    if (ctx->r8 == 0) {
        // 0x800236F4: lw          $t4, 0x44($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X44);
            goto L_80023738;
    }
    goto skip_7;
    // 0x800236F4: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    skip_7:
    // 0x800236F8: b           L_80023734
    // 0x800236FC: sh          $zero, 0x34($sp)
    MEM_H(0X34, ctx->r29) = 0;
        goto L_80023734;
    // 0x800236FC: sh          $zero, 0x34($sp)
    MEM_H(0X34, ctx->r29) = 0;
L_80023700:
    // 0x80023700: jal         0x8002331C
    // 0x80023704: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_8002331C(rdram, ctx);
        goto after_9;
    // 0x80023704: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_9:
    // 0x80023708: b           L_80023738
    // 0x8002370C: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
        goto L_80023738;
    // 0x8002370C: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
L_80023710:
    // 0x80023710: jal         0x80023370
    // 0x80023714: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80023370(rdram, ctx);
        goto after_10;
    // 0x80023714: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_10:
    // 0x80023718: b           L_80023738
    // 0x8002371C: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
        goto L_80023738;
    // 0x8002371C: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
L_80023720:
    // 0x80023720: jal         0x80023264
    // 0x80023724: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80023264(rdram, ctx);
        goto after_11;
    // 0x80023724: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_11:
    // 0x80023728: b           L_80023738
    // 0x8002372C: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
        goto L_80023738;
    // 0x8002372C: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x80023730: sh          $t3, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r11;
L_80023734:
    // 0x80023734: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
L_80023738:
    // 0x80023738: beql        $t4, $zero, L_800237CC
    if (ctx->r12 == 0) {
        // 0x8002373C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800237CC;
    }
    goto skip_8;
    // 0x8002373C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_8:
    // 0x80023740: lh          $t5, 0x34($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X34);
    // 0x80023744: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80023748: addiu       $t7, $t7, -0x68B0
    ctx->r15 = ADD32(ctx->r15, -0X68B0);
    // 0x8002374C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80023750: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x80023754: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80023758: addiu       $v0, $sp, 0x48
    ctx->r2 = ADD32(ctx->r29, 0X48);
    // 0x8002375C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
L_80023760:
    // 0x80023760: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80023764: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80023768: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8002376C: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x80023770: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80023774: bne         $v0, $a0, L_80023760
    if (ctx->r2 != ctx->r4) {
        // 0x80023778: swc1        $f16, 0x84($t9)
        MEM_W(0X84, ctx->r25) = ctx->f16.u32l;
            goto L_80023760;
    }
    // 0x80023778: swc1        $f16, 0x84($t9)
    MEM_W(0X84, ctx->r25) = ctx->f16.u32l;
    // 0x8002377C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80023780: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80023784: addiu       $t3, $t3, -0x68B0
    ctx->r11 = ADD32(ctx->r11, -0X68B0);
    // 0x80023788: lh          $t1, 0xE2($v0)
    ctx->r9 = MEM_H(ctx->r2, 0XE2);
    // 0x8002378C: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80023790: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80023794: andi        $t2, $t1, 0xFFDF
    ctx->r10 = ctx->r9 & 0XFFDF;
    // 0x80023798: bne         $a1, $t3, L_800237C4
    if (ctx->r5 != ctx->r11) {
        // 0x8002379C: sh          $t2, 0xE2($v0)
        MEM_H(0XE2, ctx->r2) = ctx->r10;
            goto L_800237C4;
    }
    // 0x8002379C: sh          $t2, 0xE2($v0)
    MEM_H(0XE2, ctx->r2) = ctx->r10;
    // 0x800237A0: lh          $t4, -0x6888($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X6888);
    // 0x800237A4: bnel        $t4, $zero, L_800237B8
    if (ctx->r12 != 0) {
        // 0x800237A8: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_800237B8;
    }
    goto skip_9;
    // 0x800237A8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    skip_9:
    // 0x800237AC: jal         0x80044480
    // 0x800237B0: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    func_80044480(rdram, ctx);
        goto after_12;
    // 0x800237B0: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_12:
    // 0x800237B4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_800237B8:
    // 0x800237B8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800237BC: b           L_800237C8
    // 0x800237C0: sh          $t5, -0x6888($at)
    MEM_H(-0X6888, ctx->r1) = ctx->r13;
        goto L_800237C8;
    // 0x800237C0: sh          $t5, -0x6888($at)
    MEM_H(-0X6888, ctx->r1) = ctx->r13;
L_800237C4:
    // 0x800237C4: sh          $zero, -0x6888($at)
    MEM_H(-0X6888, ctx->r1) = 0;
L_800237C8:
    // 0x800237C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800237CC:
    // 0x800237CC: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    // 0x800237D0: jr          $ra
    // 0x800237D4: nop

    TRACE_RETURN()
    return;
    // 0x800237D4: nop

    // 0x800237D8: nop

    // 0x800237DC: nop

indirect_800237E0:
    // 0x800237E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800237E4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800237E8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800237EC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800237F0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800237F4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800237F8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800237FC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80023800: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80023804: jal         0x80004364
    // 0x80023808: addiu       $a1, $zero, 0x144
    ctx->r5 = ADD32(0, 0X144);
    func_80004364(rdram, ctx);
        goto after_13;
    // 0x80023808: addiu       $a1, $zero, 0x144
    ctx->r5 = ADD32(0, 0X144);
    after_13:
    // 0x8002380C: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80023810: addiu       $s3, $s3, -0x6810
    ctx->r19 = ADD32(ctx->r19, -0X6810);
    // 0x80023814: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x80023818: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002381C: jal         0x8000C7C0
    // 0x80023820: addiu       $a1, $zero, 0x144
    ctx->r5 = ADD32(0, 0X144);
    func_8000C7C0(rdram, ctx);
        goto after_14;
    // 0x80023820: addiu       $a1, $zero, 0x144
    ctx->r5 = ADD32(0, 0X144);
    after_14:
    // 0x80023824: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80023828: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8002382C: jal         0x80004364
    // 0x80023830: addiu       $a1, $zero, 0x144
    ctx->r5 = ADD32(0, 0X144);
    func_80004364(rdram, ctx);
        goto after_15;
    // 0x80023830: addiu       $a1, $zero, 0x144
    ctx->r5 = ADD32(0, 0X144);
    after_15:
    // 0x80023834: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80023838: addiu       $v1, $v1, -0x6808
    ctx->r3 = ADD32(ctx->r3, -0X6808);
    // 0x8002383C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80023840: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80023844: jal         0x8000C7C0
    // 0x80023848: addiu       $a1, $zero, 0x144
    ctx->r5 = ADD32(0, 0X144);
    func_8000C7C0(rdram, ctx);
        goto after_16;
    // 0x80023848: addiu       $a1, $zero, 0x144
    ctx->r5 = ADD32(0, 0X144);
    after_16:
    // 0x8002384C: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80023850: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80023854: addiu       $v0, $v0, -0x6808
    ctx->r2 = ADD32(ctx->r2, -0X6808);
    // 0x80023858: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x8002385C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80023860: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80023864: addiu       $s0, $s0, -0x6B80
    ctx->r16 = ADD32(ctx->r16, -0X6B80);
    // 0x80023868: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x8002386C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80023870: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x80023874: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80023878: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8002387C: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x80023880: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x80023884: lh          $t2, 0x0($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X0);
    // 0x80023888: bne         $t2, $zero, L_80023898
    if (ctx->r10 != 0) {
        // 0x8002388C: nop
    
            goto L_80023898;
    }
    // 0x8002388C: nop

    // 0x80023890: jal         0x80023D64
    // 0x80023894: nop

    func_80023D64(rdram, ctx);
        goto after_17;
    // 0x80023894: nop

    after_17:
L_80023898:
    // 0x80023898: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8002389C: sh          $zero, -0x670C($at)
    MEM_H(-0X670C, ctx->r1) = 0;
    // 0x800238A0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800238A4: jal         0x80024E7C
    // 0x800238A8: sh          $zero, -0x66FC($at)
    MEM_H(-0X66FC, ctx->r1) = 0;
    func_80024E7C(rdram, ctx);
        goto after_18;
    // 0x800238A8: sh          $zero, -0x66FC($at)
    MEM_H(-0X66FC, ctx->r1) = 0;
    after_18:
    // 0x800238AC: jal         0x800356A0
    // 0x800238B0: nop

    func_800356A0(rdram, ctx);
        goto after_19;
    // 0x800238B0: nop

    after_19:
    // 0x800238B4: jal         0x8000798C
    // 0x800238B8: nop

    func_8000798C(rdram, ctx);
        goto after_20;
    // 0x800238B8: nop

    after_20:
    // 0x800238BC: lh          $t3, 0x0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X0);
    // 0x800238C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800238C4: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800238C8: bne         $t3, $at, L_80023930
    if (ctx->r11 != ctx->r1) {
        // 0x800238CC: addiu       $a0, $a0, 0x2800
        ctx->r4 = ADD32(ctx->r4, 0X2800);
            goto L_80023930;
    }
    // 0x800238CC: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x800238D0: jal         0x80004364
    // 0x800238D4: addiu       $a1, $zero, 0x144
    ctx->r5 = ADD32(0, 0X144);
    func_80004364(rdram, ctx);
        goto after_21;
    // 0x800238D4: addiu       $a1, $zero, 0x144
    ctx->r5 = ADD32(0, 0X144);
    after_21:
    // 0x800238D8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800238DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800238E0: jal         0x8000C7C0
    // 0x800238E4: addiu       $a1, $zero, 0x144
    ctx->r5 = ADD32(0, 0X144);
    func_8000C7C0(rdram, ctx);
        goto after_22;
    // 0x800238E4: addiu       $a1, $zero, 0x144
    ctx->r5 = ADD32(0, 0X144);
    after_22:
    // 0x800238E8: addiu       $t4, $zero, 0x3001
    ctx->r12 = ADD32(0, 0X3001);
    // 0x800238EC: sh          $t4, 0x94($s0)
    MEM_H(0X94, ctx->r16) = ctx->r12;
    // 0x800238F0: jal         0x80024818
    // 0x800238F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80024818(rdram, ctx);
        goto after_23;
    // 0x800238F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x800238F8: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800238FC: lw          $t5, -0x6808($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X6808);
    // 0x80023900: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80023904: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80023908: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x8002390C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80023910: sw          $s0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r16;
    // 0x80023914: lw          $t7, -0x6808($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6808);
    // 0x80023918: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8002391C: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x80023920: lw          $t9, -0x6808($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6808);
    // 0x80023924: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80023928: lw          $t0, -0x6808($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X6808);
    // 0x8002392C: sw          $s0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r16;
L_80023930:
    // 0x80023930: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80023934: addiu       $v0, $v0, -0x65E8
    ctx->r2 = ADD32(ctx->r2, -0X65E8);
    // 0x80023938: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8002393C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80023940: sw          $zero, -0x65EC($at)
    MEM_W(-0X65EC, ctx->r1) = 0;
    // 0x80023944: addiu       $s1, $zero, -0x2
    ctx->r17 = ADD32(0, -0X2);
    // 0x80023948: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
L_8002394C:
    // 0x8002394C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80023950: bne         $v0, $at, L_800239E4
    if (ctx->r2 != ctx->r1) {
        // 0x80023954: nop
    
            goto L_800239E4;
    }
    // 0x80023954: nop

    // 0x80023958: jal         0x80024034
    // 0x8002395C: nop

    func_80024034(rdram, ctx);
        goto after_24;
    // 0x8002395C: nop

    after_24:
    // 0x80023960: jal         0x800356E0
    // 0x80023964: nop

    func_800356E0(rdram, ctx);
        goto after_25;
    // 0x80023964: nop

    after_25:
    // 0x80023968: jal         0x80024FB4
    // 0x8002396C: nop

    func_80024FB4(rdram, ctx);
        goto after_26;
    // 0x8002396C: nop

    after_26:
    // 0x80023970: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    // 0x80023974: lw          $s0, 0x0($a1)
    ctx->r16 = MEM_W(ctx->r5, 0X0);
    // 0x80023978: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8002397C: beq         $t2, $zero, L_800239AC
    if (ctx->r10 == 0) {
        // 0x80023980: nop
    
            goto L_800239AC;
    }
    // 0x80023980: nop

    // 0x80023984: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
L_80023988:
    // 0x80023988: jal         0x800250D4
    // 0x8002398C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800250D4(rdram, ctx);
        goto after_27;
    // 0x8002398C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x80023990: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80023994: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80023998: bnel        $t3, $zero, L_80023988
    if (ctx->r11 != 0) {
        // 0x8002399C: lw          $s1, 0x0($s0)
        ctx->r17 = MEM_W(ctx->r16, 0X0);
            goto L_80023988;
    }
    goto skip_10;
    // 0x8002399C: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    skip_10:
    // 0x800239A0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800239A4: lw          $a1, -0x6810($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6810);
    // 0x800239A8: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
L_800239AC:
    // 0x800239AC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800239B0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800239B4: jal         0x800042A8
    // 0x800239B8: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    func_800042A8(rdram, ctx);
        goto after_28;
    // 0x800239B8: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    after_28:
    // 0x800239BC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800239C0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800239C4: lw          $a1, -0x6808($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6808);
    // 0x800239C8: jal         0x800042A8
    // 0x800239CC: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    func_800042A8(rdram, ctx);
        goto after_29;
    // 0x800239CC: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    after_29:
    // 0x800239D0: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
L_800239D4:
    // 0x800239D4: jal         0x8000798C
    // 0x800239D8: nop

    func_8000798C(rdram, ctx);
        goto after_30;
    // 0x800239D8: nop

    after_30:
    // 0x800239DC: b           L_800239D4
    // 0x800239E0: nop

        goto L_800239D4;
    // 0x800239E0: nop

L_800239E4:
    // 0x800239E4: bne         $s1, $v0, L_80023A08
    if (ctx->r17 != ctx->r2) {
        // 0x800239E8: nop
    
            goto L_80023A08;
    }
    // 0x800239E8: nop

    // 0x800239EC: bne         $s1, $v0, L_80023A08
    if (ctx->r17 != ctx->r2) {
        // 0x800239F0: nop
    
            goto L_80023A08;
    }
    // 0x800239F0: nop

L_800239F4:
    // 0x800239F4: jal         0x8000798C
    // 0x800239F8: nop

    func_8000798C(rdram, ctx);
        goto after_31;
    // 0x800239F8: nop

    after_31:
    // 0x800239FC: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x80023A00: beq         $s1, $t4, L_800239F4
    if (ctx->r17 == ctx->r12) {
        // 0x80023A04: nop
    
            goto L_800239F4;
    }
    // 0x80023A04: nop

L_80023A08:
    // 0x80023A08: jal         0x8002403C
    // 0x80023A0C: nop

    func_8002403C(rdram, ctx);
        goto after_32;
    // 0x80023A0C: nop

    after_32:
    // 0x80023A10: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x80023A14: lw          $s0, 0x0($t5)
    ctx->r16 = MEM_W(ctx->r13, 0X0);
    // 0x80023A18: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80023A1C: beq         $v0, $zero, L_80023A4C
    if (ctx->r2 == 0) {
        // 0x80023A20: nop
    
            goto L_80023A4C;
    }
    // 0x80023A20: nop

    // 0x80023A24: lw          $v1, 0xE0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XE0);
L_80023A28:
    // 0x80023A28: beql        $v1, $zero, L_80023A40
    if (ctx->r3 == 0) {
        // 0x80023A2C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80023A40;
    }
    goto skip_11;
    // 0x80023A2C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    skip_11:
    // 0x80023A30: jalr        $v1
    // 0x80023A34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_33;
    // 0x80023A34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x80023A38: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80023A3C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80023A40:
    // 0x80023A40: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80023A44: bnel        $v0, $zero, L_80023A28
    if (ctx->r2 != 0) {
        // 0x80023A48: lw          $v1, 0xE0($s0)
        ctx->r3 = MEM_W(ctx->r16, 0XE0);
            goto L_80023A28;
    }
    goto skip_12;
    // 0x80023A48: lw          $v1, 0xE0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XE0);
    skip_12:
L_80023A4C:
    // 0x80023A4C: jal         0x8001EFF8
    // 0x80023A50: nop

    func_8001EFF8(rdram, ctx);
        goto after_34;
    // 0x80023A50: nop

    after_34:
    // 0x80023A54: jal         0x8000798C
    // 0x80023A58: nop

    func_8000798C(rdram, ctx);
        goto after_35;
    // 0x80023A58: nop

    after_35:
    // 0x80023A5C: b           L_8002394C
    // 0x80023A60: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
        goto L_8002394C;
    // 0x80023A60: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80023A64: nop

    // 0x80023A68: nop

    // 0x80023A6C: nop

    // 0x80023A70: nop

    // 0x80023A74: nop

    // 0x80023A78: nop

    // 0x80023A7C: nop

    // 0x80023A80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80023A84: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80023A88: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80023A8C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80023A90: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80023A94: jr          $ra
    // 0x80023A98: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    TRACE_RETURN()
    return;
    // 0x80023A98: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800233C4(uint8_t* rdram, recomp_context* ctx) { func_800233C4_entry(rdram, ctx, 0); }
RECOMP_FUNC void func_800237E0(uint8_t* rdram, recomp_context* ctx) { func_800233C4_entry(rdram, ctx, 1); }

RECOMP_FUNC void func_80023A9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80023A9C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80023AA0: lh          $t2, -0x662C($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X662C);
    // 0x80023AA4: lui         $t8, 0x8007
    ctx->r24 = S32(0X8007 << 16);
    // 0x80023AA8: addiu       $t8, $t8, 0x2EA0
    ctx->r24 = ADD32(ctx->r24, 0X2EA0);
    // 0x80023AAC: sll         $t7, $t2, 3
    ctx->r15 = S32(ctx->r10 << 3);
    // 0x80023AB0: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80023AB4: lw          $t9, -0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X8);
    // 0x80023AB8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80023ABC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80023AC0: sw          $t9, -0x6714($at)
    MEM_W(-0X6714, ctx->r1) = ctx->r25;
    // 0x80023AC4: lw          $t3, -0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, -0X4);
    // 0x80023AC8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80023ACC: addiu       $a0, $a0, -0x6710
    ctx->r4 = ADD32(ctx->r4, -0X6710);
    // 0x80023AD0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80023AD4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80023AD8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80023ADC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80023AE0: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x80023AE4: lh          $t1, 0x0($t3)
    ctx->r9 = MEM_H(ctx->r11, 0X0);
    // 0x80023AE8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80023AEC: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x80023AF0: beq         $t1, $zero, L_80023B70
    if (ctx->r9 == 0) {
        // 0x80023AF4: or          $t0, $t3, $zero
        ctx->r8 = ctx->r11 | 0;
            goto L_80023B70;
    }
    // 0x80023AF4: or          $t0, $t3, $zero
    ctx->r8 = ctx->r11 | 0;
    // 0x80023AF8: or          $a3, $t3, $zero
    ctx->r7 = ctx->r11 | 0;
    // 0x80023AFC: lw          $a1, 0x4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X4);
L_80023B00:
    // 0x80023B00: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80023B04: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    // 0x80023B08: beql        $a0, $zero, L_80023B64
    if (ctx->r4 == 0) {
        // 0x80023B0C: lh          $t8, 0xC($a3)
        ctx->r24 = MEM_H(ctx->r7, 0XC);
            goto L_80023B64;
    }
    goto skip_0;
    // 0x80023B0C: lh          $t8, 0xC($a3)
    ctx->r24 = MEM_H(ctx->r7, 0XC);
    skip_0:
    // 0x80023B10: lh          $a2, -0x67F0($a2)
    ctx->r6 = MEM_H(ctx->r6, -0X67F0);
L_80023B14:
    // 0x80023B14: beq         $a2, $zero, L_80023B50
    if (ctx->r6 == 0) {
        // 0x80023B18: lui         $t4, 0x8013
        ctx->r12 = S32(0X8013 << 16);
            goto L_80023B50;
    }
    // 0x80023B18: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80023B1C: addiu       $v0, $t4, -0x67F0
    ctx->r2 = ADD32(ctx->r12, -0X67F0);
    // 0x80023B20: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
L_80023B24:
    // 0x80023B24: bnel        $a0, $v1, L_80023B44
    if (ctx->r4 != ctx->r3) {
        // 0x80023B28: lh          $v1, 0x4($v0)
        ctx->r3 = MEM_H(ctx->r2, 0X4);
            goto L_80023B44;
    }
    goto skip_1;
    // 0x80023B28: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    skip_1:
    // 0x80023B2C: lh          $t5, 0x2($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X2);
    // 0x80023B30: addu        $s0, $s0, $t5
    ctx->r16 = ADD32(ctx->r16, ctx->r13);
    // 0x80023B34: sll         $t6, $s0, 16
    ctx->r14 = S32(ctx->r16 << 16);
    // 0x80023B38: b           L_80023B50
    // 0x80023B3C: sra         $s0, $t6, 16
    ctx->r16 = S32(SIGNED(ctx->r14) >> 16);
        goto L_80023B50;
    // 0x80023B3C: sra         $s0, $t6, 16
    ctx->r16 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80023B40: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
L_80023B44:
    // 0x80023B44: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80023B48: bne         $v1, $zero, L_80023B24
    if (ctx->r3 != 0) {
        // 0x80023B4C: nop
    
            goto L_80023B24;
    }
    // 0x80023B4C: nop

L_80023B50:
    // 0x80023B50: lh          $a0, 0xA($a1)
    ctx->r4 = MEM_H(ctx->r5, 0XA);
    // 0x80023B54: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
    // 0x80023B58: bne         $a0, $zero, L_80023B14
    if (ctx->r4 != 0) {
        // 0x80023B5C: nop
    
            goto L_80023B14;
    }
    // 0x80023B5C: nop

    // 0x80023B60: lh          $t8, 0xC($a3)
    ctx->r24 = MEM_H(ctx->r7, 0XC);
L_80023B64:
    // 0x80023B64: addiu       $a3, $a3, 0xC
    ctx->r7 = ADD32(ctx->r7, 0XC);
    // 0x80023B68: bnel        $t8, $zero, L_80023B00
    if (ctx->r24 != 0) {
        // 0x80023B6C: lw          $a1, 0x4($a3)
        ctx->r5 = MEM_W(ctx->r7, 0X4);
            goto L_80023B00;
    }
    goto skip_2;
    // 0x80023B6C: lw          $a1, 0x4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X4);
    skip_2:
L_80023B70:
    // 0x80023B70: beq         $t1, $zero, L_80023BC8
    if (ctx->r9 == 0) {
        // 0x80023B74: sll         $t6, $t2, 2
        ctx->r14 = S32(ctx->r10 << 2);
            goto L_80023BC8;
    }
    // 0x80023B74: sll         $t6, $t2, 2
    ctx->r14 = S32(ctx->r10 << 2);
    // 0x80023B78: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
    // 0x80023B7C: addiu       $v0, $zero, 0x501
    ctx->r2 = ADD32(0, 0X501);
    // 0x80023B80: lw          $a1, 0x4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X4);
L_80023B84:
    // 0x80023B84: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    // 0x80023B88: beql        $a0, $zero, L_80023BBC
    if (ctx->r4 == 0) {
        // 0x80023B8C: lh          $t5, 0xC($a3)
        ctx->r13 = MEM_H(ctx->r7, 0XC);
            goto L_80023BBC;
    }
    goto skip_3;
    // 0x80023B8C: lh          $t5, 0xC($a3)
    ctx->r13 = MEM_H(ctx->r7, 0XC);
    skip_3:
L_80023B90:
    // 0x80023B90: beql        $v0, $a0, L_80023BAC
    if (ctx->r2 == ctx->r4) {
        // 0x80023B94: lh          $a0, 0xA($a1)
        ctx->r4 = MEM_H(ctx->r5, 0XA);
            goto L_80023BAC;
    }
    goto skip_4;
    // 0x80023B94: lh          $a0, 0xA($a1)
    ctx->r4 = MEM_H(ctx->r5, 0XA);
    skip_4:
    // 0x80023B98: lh          $t9, 0x2($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X2);
    // 0x80023B9C: addu        $s0, $s0, $t9
    ctx->r16 = ADD32(ctx->r16, ctx->r25);
    // 0x80023BA0: sll         $t3, $s0, 16
    ctx->r11 = S32(ctx->r16 << 16);
    // 0x80023BA4: sra         $s0, $t3, 16
    ctx->r16 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80023BA8: lh          $a0, 0xA($a1)
    ctx->r4 = MEM_H(ctx->r5, 0XA);
L_80023BAC:
    // 0x80023BAC: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
    // 0x80023BB0: bne         $a0, $zero, L_80023B90
    if (ctx->r4 != 0) {
        // 0x80023BB4: nop
    
            goto L_80023B90;
    }
    // 0x80023BB4: nop

    // 0x80023BB8: lh          $t5, 0xC($a3)
    ctx->r13 = MEM_H(ctx->r7, 0XC);
L_80023BBC:
    // 0x80023BBC: addiu       $a3, $a3, 0xC
    ctx->r7 = ADD32(ctx->r7, 0XC);
    // 0x80023BC0: bnel        $t5, $zero, L_80023B84
    if (ctx->r13 != 0) {
        // 0x80023BC4: lw          $a1, 0x4($a3)
        ctx->r5 = MEM_W(ctx->r7, 0X4);
            goto L_80023B84;
    }
    goto skip_5;
    // 0x80023BC4: lw          $a1, 0x4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X4);
    skip_5:
L_80023BC8:
    // 0x80023BC8: subu        $t6, $t6, $t2
    ctx->r14 = SUB32(ctx->r14, ctx->r10);
    // 0x80023BCC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80023BD0: addiu       $t7, $t7, 0x1F0
    ctx->r15 = ADD32(ctx->r15, 0X1F0);
    // 0x80023BD4: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80023BD8: lw          $t8, -0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X4);
    // 0x80023BDC: lw          $t9, -0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X8);
    // 0x80023BE0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80023BE4: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80023BE8: subu        $s1, $t8, $t9
    ctx->r17 = SUB32(ctx->r24, ctx->r25);
    // 0x80023BEC: jal         0x80004364
    // 0x80023BF0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x80023BF0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x80023BF4: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80023BF8: lh          $t3, -0x662C($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X662C);
    // 0x80023BFC: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80023C00: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80023C04: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80023C08: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80023C0C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80023C10: addu        $a0, $a0, $t4
    ctx->r4 = ADD32(ctx->r4, ctx->r12);
    // 0x80023C14: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80023C18: lw          $a0, 0x1E8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1E8);
    // 0x80023C1C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80023C20: jal         0x8000C5FC
    // 0x80023C24: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    dma_read_rom(rdram, ctx);
        goto after_1;
    // 0x80023C24: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_1:
    // 0x80023C28: lbu         $t5, 0x0($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X0);
    // 0x80023C2C: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80023C30: beq         $t5, $at, L_80023D38
    if (ctx->r13 == ctx->r1) {
        // 0x80023C34: nop
    
            goto L_80023D38;
    }
    // 0x80023C34: nop

    // 0x80023C38: lw          $v0, 0x24($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X24);
L_80023C3C:
    // 0x80023C3C: andi        $t6, $v0, 0x8
    ctx->r14 = ctx->r2 & 0X8;
    // 0x80023C40: beq         $t6, $zero, L_80023C58
    if (ctx->r14 == 0) {
        // 0x80023C44: srl         $v1, $v0, 16
        ctx->r3 = S32(U32(ctx->r2) >> 16);
            goto L_80023C58;
    }
    // 0x80023C44: srl         $v1, $v0, 16
    ctx->r3 = S32(U32(ctx->r2) >> 16);
    // 0x80023C48: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80023C4C: sll         $t7, $s0, 16
    ctx->r15 = S32(ctx->r16 << 16);
    // 0x80023C50: b           L_80023D24
    // 0x80023C54: sra         $s0, $t7, 16
    ctx->r16 = S32(SIGNED(ctx->r15) >> 16);
        goto L_80023D24;
    // 0x80023C54: sra         $s0, $t7, 16
    ctx->r16 = S32(SIGNED(ctx->r15) >> 16);
L_80023C58:
    // 0x80023C58: andi        $t9, $v1, 0x3F
    ctx->r25 = ctx->r3 & 0X3F;
    // 0x80023C5C: sltiu       $at, $t9, 0x21
    ctx->r1 = ctx->r25 < 0X21 ? 1 : 0;
    // 0x80023C60: bne         $at, $zero, L_80023D24
    if (ctx->r1 != 0) {
        // 0x80023C64: andi        $s1, $v1, 0xF
        ctx->r17 = ctx->r3 & 0XF;
            goto L_80023D24;
    }
    // 0x80023C64: andi        $s1, $v1, 0xF
    ctx->r17 = ctx->r3 & 0XF;
    // 0x80023C68: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80023C6C: lh          $v0, -0x662C($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X662C);
    // 0x80023C70: sll         $t3, $s1, 16
    ctx->r11 = S32(ctx->r17 << 16);
    // 0x80023C74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80023C78: beq         $v0, $at, L_80023C94
    if (ctx->r2 == ctx->r1) {
        // 0x80023C7C: sra         $s1, $t3, 16
        ctx->r17 = S32(SIGNED(ctx->r11) >> 16);
            goto L_80023C94;
    }
    // 0x80023C7C: sra         $s1, $t3, 16
    ctx->r17 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80023C80: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80023C84: beq         $v0, $at, L_80023CD4
    if (ctx->r2 == ctx->r1) {
        // 0x80023C88: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_80023CD4;
    }
    // 0x80023C88: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80023C8C: b           L_80023D1C
    // 0x80023C90: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_80023D1C;
    // 0x80023C90: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80023C94:
    // 0x80023C94: sll         $a1, $s1, 16
    ctx->r5 = S32(ctx->r17 << 16);
    // 0x80023C98: sra         $t5, $a1, 16
    ctx->r13 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80023C9C: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x80023CA0: jal         0x8003A114
    // 0x80023CA4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8003A114(rdram, ctx);
        goto after_2;
    // 0x80023CA4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80023CA8: beq         $v0, $zero, L_80023D18
    if (ctx->r2 == 0) {
        // 0x80023CAC: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_80023D18;
    }
    // 0x80023CAC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80023CB0: lh          $t6, -0x6B78($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X6B78);
    // 0x80023CB4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80023CB8: beql        $s1, $t6, L_80023D1C
    if (ctx->r17 == ctx->r14) {
        // 0x80023CBC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80023D1C;
    }
    goto skip_6;
    // 0x80023CBC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_6:
    // 0x80023CC0: lh          $t7, -0x6B76($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X6B76);
    // 0x80023CC4: beql        $s1, $t7, L_80023D1C
    if (ctx->r17 == ctx->r15) {
        // 0x80023CC8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80023D1C;
    }
    goto skip_7;
    // 0x80023CC8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_7:
    // 0x80023CCC: b           L_80023D28
    // 0x80023CD0: lbu         $t7, 0x28($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X28);
        goto L_80023D28;
    // 0x80023CD0: lbu         $t7, 0x28($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X28);
L_80023CD4:
    // 0x80023CD4: sll         $a1, $s1, 16
    ctx->r5 = S32(ctx->r17 << 16);
    // 0x80023CD8: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80023CDC: jal         0x8003A114
    // 0x80023CE0: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    func_8003A114(rdram, ctx);
        goto after_3;
    // 0x80023CE0: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_3:
    // 0x80023CE4: beq         $v0, $zero, L_80023D18
    if (ctx->r2 == 0) {
        // 0x80023CE8: lui         $t9, 0x8013
        ctx->r25 = S32(0X8013 << 16);
            goto L_80023D18;
    }
    // 0x80023CE8: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80023CEC: lh          $t9, -0x6B74($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X6B74);
    // 0x80023CF0: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80023CF4: beql        $s1, $t9, L_80023D1C
    if (ctx->r17 == ctx->r25) {
        // 0x80023CF8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80023D1C;
    }
    goto skip_8;
    // 0x80023CF8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_8:
    // 0x80023CFC: lh          $t3, -0x6B72($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X6B72);
    // 0x80023D00: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80023D04: beql        $s1, $t3, L_80023D1C
    if (ctx->r17 == ctx->r11) {
        // 0x80023D08: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80023D1C;
    }
    goto skip_9;
    // 0x80023D08: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_9:
    // 0x80023D0C: lh          $t4, -0x6B70($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X6B70);
    // 0x80023D10: bnel        $s1, $t4, L_80023D28
    if (ctx->r17 != ctx->r12) {
        // 0x80023D14: lbu         $t7, 0x28($s2)
        ctx->r15 = MEM_BU(ctx->r18, 0X28);
            goto L_80023D28;
    }
    goto skip_10;
    // 0x80023D14: lbu         $t7, 0x28($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X28);
    skip_10:
L_80023D18:
    // 0x80023D18: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80023D1C:
    // 0x80023D1C: sll         $t5, $s0, 16
    ctx->r13 = S32(ctx->r16 << 16);
    // 0x80023D20: sra         $s0, $t5, 16
    ctx->r16 = S32(SIGNED(ctx->r13) >> 16);
L_80023D24:
    // 0x80023D24: lbu         $t7, 0x28($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X28);
L_80023D28:
    // 0x80023D28: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80023D2C: addiu       $s2, $s2, 0x28
    ctx->r18 = ADD32(ctx->r18, 0X28);
    // 0x80023D30: bnel        $t7, $at, L_80023C3C
    if (ctx->r15 != ctx->r1) {
        // 0x80023D34: lw          $v0, 0x24($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X24);
            goto L_80023C3C;
    }
    goto skip_11;
    // 0x80023D34: lw          $v0, 0x24($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X24);
    skip_11:
L_80023D38:
    // 0x80023D38: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80023D3C: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80023D40: jal         0x800042A8
    // 0x80023D44: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800042A8(rdram, ctx);
        goto after_4;
    // 0x80023D44: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x80023D48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80023D4C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80023D50: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80023D54: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80023D58: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80023D5C: jr          $ra
    // 0x80023D60: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    TRACE_RETURN()
    return;
    // 0x80023D60: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80023D64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80023D64: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80023D68: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80023D6C: lh          $t6, -0x6B8E($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X6B8E);
    // 0x80023D70: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80023D74: sh          $zero, -0x66E8($at)
    MEM_H(-0X66E8, ctx->r1) = 0;
    // 0x80023D78: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80023D7C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80023D80: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80023D84: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80023D88: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80023D8C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80023D90: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80023D94: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80023D98: beq         $t6, $zero, L_80023DCC
    if (ctx->r14 == 0) {
        // 0x80023D9C: sh          $zero, -0x66E6($at)
        MEM_H(-0X66E6, ctx->r1) = 0;
            goto L_80023DCC;
    }
    // 0x80023D9C: sh          $zero, -0x66E6($at)
    MEM_H(-0X66E6, ctx->r1) = 0;
    // 0x80023DA0: lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // 0x80023DA4: addiu       $v1, $v1, 0x2EA0
    ctx->r3 = ADD32(ctx->r3, 0X2EA0);
    // 0x80023DA8: lw          $t7, 0x48($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X48);
    // 0x80023DAC: lw          $t8, 0x4C($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4C);
    // 0x80023DB0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80023DB4: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80023DB8: addiu       $s3, $s3, -0x6710
    ctx->r19 = ADD32(ctx->r19, -0X6710);
    // 0x80023DBC: addiu       $a1, $a1, -0x6714
    ctx->r5 = ADD32(ctx->r5, -0X6714);
    // 0x80023DC0: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80023DC4: b           L_80023E04
    // 0x80023DC8: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
        goto L_80023E04;
    // 0x80023DC8: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
L_80023DCC:
    // 0x80023DCC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80023DD0: lh          $t0, -0x662C($t9)
    ctx->r8 = MEM_H(ctx->r25, -0X662C);
    // 0x80023DD4: lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // 0x80023DD8: addiu       $v1, $v1, 0x2EA0
    ctx->r3 = ADD32(ctx->r3, 0X2EA0);
    // 0x80023DDC: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80023DE0: addu        $v0, $v1, $t1
    ctx->r2 = ADD32(ctx->r3, ctx->r9);
    // 0x80023DE4: lw          $t2, -0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, -0X8);
    // 0x80023DE8: lw          $t3, -0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, -0X4);
    // 0x80023DEC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80023DF0: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80023DF4: addiu       $s3, $s3, -0x6710
    ctx->r19 = ADD32(ctx->r19, -0X6710);
    // 0x80023DF8: addiu       $a1, $a1, -0x6714
    ctx->r5 = ADD32(ctx->r5, -0X6714);
    // 0x80023DFC: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x80023E00: sw          $t3, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r11;
L_80023E04:
    // 0x80023E04: lw          $a2, 0x0($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X0);
    // 0x80023E08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80023E0C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80023E10: lh          $t4, 0x0($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X0);
    // 0x80023E14: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x80023E18: beql        $t4, $zero, L_80023E4C
    if (ctx->r12 == 0) {
        // 0x80023E1C: lw          $v1, 0x0($s3)
        ctx->r3 = MEM_W(ctx->r19, 0X0);
            goto L_80023E4C;
    }
    goto skip_0;
    // 0x80023E1C: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    skip_0:
    // 0x80023E20: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
L_80023E24:
    // 0x80023E24: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x80023E28: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x80023E2C: sh          $zero, 0x8($t6)
    MEM_H(0X8, ctx->r14) = 0;
    // 0x80023E30: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80023E34: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x80023E38: addu        $v1, $t7, $v0
    ctx->r3 = ADD32(ctx->r15, ctx->r2);
    // 0x80023E3C: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x80023E40: bnel        $t8, $zero, L_80023E24
    if (ctx->r24 != 0) {
        // 0x80023E44: sh          $zero, 0x4($v1)
        MEM_H(0X4, ctx->r3) = 0;
            goto L_80023E24;
    }
    goto skip_1;
    // 0x80023E44: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    skip_1:
    // 0x80023E48: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
L_80023E4C:
    // 0x80023E4C: lh          $a1, 0x0($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X0);
    // 0x80023E50: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80023E54: beq         $a1, $zero, L_80023EF8
    if (ctx->r5 == 0) {
        // 0x80023E58: nop
    
            goto L_80023EF8;
    }
    // 0x80023E58: nop

    // 0x80023E5C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80023E60: addiu       $a1, $a1, -0x67F0
    ctx->r5 = ADD32(ctx->r5, -0X67F0);
    // 0x80023E64: lw          $s1, 0x4($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X4);
L_80023E68:
    // 0x80023E68: lh          $t9, 0x0($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X0);
    // 0x80023E6C: beql        $t9, $zero, L_80023EE4
    if (ctx->r25 == 0) {
        // 0x80023E70: lh          $t7, 0xC($v0)
        ctx->r15 = MEM_H(ctx->r2, 0XC);
            goto L_80023EE4;
    }
    goto skip_2;
    // 0x80023E70: lh          $t7, 0xC($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XC);
    skip_2:
    // 0x80023E74: sh          $zero, 0x4($s1)
    MEM_H(0X4, ctx->r17) = 0;
L_80023E78:
    // 0x80023E78: lh          $t0, 0x0($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X0);
    // 0x80023E7C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80023E80: addiu       $v0, $t1, -0x67F0
    ctx->r2 = ADD32(ctx->r9, -0X67F0);
    // 0x80023E84: beql        $t0, $zero, L_80023ECC
    if (ctx->r8 == 0) {
        // 0x80023E88: lh          $t6, 0xA($s1)
        ctx->r14 = MEM_H(ctx->r17, 0XA);
            goto L_80023ECC;
    }
    goto skip_3;
    // 0x80023E88: lh          $t6, 0xA($s1)
    ctx->r14 = MEM_H(ctx->r17, 0XA);
    skip_3:
    // 0x80023E8C: lh          $s0, 0x0($s1)
    ctx->r16 = MEM_H(ctx->r17, 0X0);
    // 0x80023E90: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
L_80023E94:
    // 0x80023E94: bnel        $s0, $v1, L_80023EBC
    if (ctx->r16 != ctx->r3) {
        // 0x80023E98: lh          $v1, 0x4($v0)
        ctx->r3 = MEM_H(ctx->r2, 0X4);
            goto L_80023EBC;
    }
    goto skip_4;
    // 0x80023E98: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    skip_4:
    // 0x80023E9C: lh          $t2, 0x2($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X2);
    // 0x80023EA0: sh          $t2, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r10;
    // 0x80023EA4: lh          $t3, 0x4($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X4);
    // 0x80023EA8: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x80023EAC: sll         $t4, $a0, 16
    ctx->r12 = S32(ctx->r4 << 16);
    // 0x80023EB0: b           L_80023EC8
    // 0x80023EB4: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
        goto L_80023EC8;
    // 0x80023EB4: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80023EB8: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
L_80023EBC:
    // 0x80023EBC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80023EC0: bne         $v1, $zero, L_80023E94
    if (ctx->r3 != 0) {
        // 0x80023EC4: nop
    
            goto L_80023E94;
    }
    // 0x80023EC4: nop

L_80023EC8:
    // 0x80023EC8: lh          $t6, 0xA($s1)
    ctx->r14 = MEM_H(ctx->r17, 0XA);
L_80023ECC:
    // 0x80023ECC: addiu       $s1, $s1, 0xA
    ctx->r17 = ADD32(ctx->r17, 0XA);
    // 0x80023ED0: bnel        $t6, $zero, L_80023E78
    if (ctx->r14 != 0) {
        // 0x80023ED4: sh          $zero, 0x4($s1)
        MEM_H(0X4, ctx->r17) = 0;
            goto L_80023E78;
    }
    goto skip_5;
    // 0x80023ED4: sh          $zero, 0x4($s1)
    MEM_H(0X4, ctx->r17) = 0;
    skip_5:
    // 0x80023ED8: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80023EDC: addu        $v0, $v1, $s4
    ctx->r2 = ADD32(ctx->r3, ctx->r20);
    // 0x80023EE0: lh          $t7, 0xC($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XC);
L_80023EE4:
    // 0x80023EE4: addiu       $s4, $s4, 0xC
    ctx->r20 = ADD32(ctx->r20, 0XC);
    // 0x80023EE8: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x80023EEC: bnel        $t7, $zero, L_80023E68
    if (ctx->r15 != 0) {
        // 0x80023EF0: lw          $s1, 0x4($v0)
        ctx->r17 = MEM_W(ctx->r2, 0X4);
            goto L_80023E68;
    }
    goto skip_6;
    // 0x80023EF0: lw          $s1, 0x4($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X4);
    skip_6:
    // 0x80023EF4: lh          $a1, 0x0($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X0);
L_80023EF8:
    // 0x80023EF8: beq         $a1, $zero, L_80023F70
    if (ctx->r5 == 0) {
        // 0x80023EFC: lui         $a0, 0x801A
        ctx->r4 = S32(0X801A << 16);
            goto L_80023F70;
    }
    // 0x80023EFC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80023F00: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80023F04: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80023F08: lw          $s1, 0x4($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X4);
L_80023F0C:
    // 0x80023F0C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80023F10: lh          $t8, 0x0($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X0);
    // 0x80023F14: beql        $t8, $zero, L_80023F58
    if (ctx->r24 == 0) {
        // 0x80023F18: sh          $v1, 0x8($v0)
        MEM_H(0X8, ctx->r2) = ctx->r3;
            goto L_80023F58;
    }
    goto skip_7;
    // 0x80023F18: sh          $v1, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r3;
    skip_7:
L_80023F1C:
    // 0x80023F1C: lh          $t9, 0x2($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X2);
    // 0x80023F20: lh          $t0, 0x4($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X4);
    // 0x80023F24: lh          $t4, 0xA($s1)
    ctx->r12 = MEM_H(ctx->r17, 0XA);
    // 0x80023F28: addiu       $s1, $s1, 0xA
    ctx->r17 = ADD32(ctx->r17, 0XA);
    // 0x80023F2C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80023F30: sh          $t1, -0x4($s1)
    MEM_H(-0X4, ctx->r17) = ctx->r9;
    // 0x80023F34: lh          $v0, -0x4($s1)
    ctx->r2 = MEM_H(ctx->r17, -0X4);
    // 0x80023F38: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80023F3C: sll         $t2, $v1, 16
    ctx->r10 = S32(ctx->r3 << 16);
    // 0x80023F40: sra         $v1, $t2, 16
    ctx->r3 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80023F44: bne         $t4, $zero, L_80023F1C
    if (ctx->r12 != 0) {
        // 0x80023F48: sh          $v0, -0x2($s1)
        MEM_H(-0X2, ctx->r17) = ctx->r2;
            goto L_80023F1C;
    }
    // 0x80023F48: sh          $v0, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r2;
    // 0x80023F4C: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x80023F50: addu        $v0, $t5, $s4
    ctx->r2 = ADD32(ctx->r13, ctx->r20);
    // 0x80023F54: sh          $v1, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r3;
L_80023F58:
    // 0x80023F58: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80023F5C: addiu       $s4, $s4, 0xC
    ctx->r20 = ADD32(ctx->r20, 0XC);
    // 0x80023F60: addu        $v0, $t6, $s4
    ctx->r2 = ADD32(ctx->r14, ctx->r20);
    // 0x80023F64: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x80023F68: bnel        $t7, $zero, L_80023F0C
    if (ctx->r15 != 0) {
        // 0x80023F6C: lw          $s1, 0x4($v0)
        ctx->r17 = MEM_W(ctx->r2, 0X4);
            goto L_80023F0C;
    }
    goto skip_8;
    // 0x80023F6C: lw          $s1, 0x4($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X4);
    skip_8:
L_80023F70:
    // 0x80023F70: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80023F74: jal         0x80004364
    // 0x80023F78: addiu       $a1, $zero, 0x144
    ctx->r5 = ADD32(0, 0X144);
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x80023F78: addiu       $a1, $zero, 0x144
    ctx->r5 = ADD32(0, 0X144);
    after_0:
    // 0x80023F7C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80023F80: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80023F84: jal         0x8000C7C0
    // 0x80023F88: addiu       $a1, $zero, 0x144
    ctx->r5 = ADD32(0, 0X144);
    func_8000C7C0(rdram, ctx);
        goto after_1;
    // 0x80023F88: addiu       $a1, $zero, 0x144
    ctx->r5 = ADD32(0, 0X144);
    after_1:
    // 0x80023F8C: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80023F90: addiu       $s3, $zero, -0x9
    ctx->r19 = ADD32(0, -0X9);
    // 0x80023F94: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80023F98: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x80023F9C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80023FA0: beq         $t8, $zero, L_80024004
    if (ctx->r24 == 0) {
        // 0x80023FA4: nop
    
            goto L_80024004;
    }
    // 0x80023FA4: nop

    // 0x80023FA8: lw          $s1, 0x4($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X4);
L_80023FAC:
    // 0x80023FAC: lh          $s0, 0x0($s1)
    ctx->r16 = MEM_H(ctx->r17, 0X0);
    // 0x80023FB0: beql        $s0, $zero, L_80023FF4
    if (ctx->r16 == 0) {
        // 0x80023FB4: lh          $t1, 0xC($v0)
        ctx->r9 = MEM_H(ctx->r2, 0XC);
            goto L_80023FF4;
    }
    goto skip_9;
    // 0x80023FB4: lh          $t1, 0xC($v0)
    ctx->r9 = MEM_H(ctx->r2, 0XC);
    skip_9:
    // 0x80023FB8: sh          $s0, 0x94($s2)
    MEM_H(0X94, ctx->r18) = ctx->r16;
L_80023FBC:
    // 0x80023FBC: sh          $s3, 0x96($s2)
    MEM_H(0X96, ctx->r18) = ctx->r19;
    // 0x80023FC0: lh          $t9, 0x6($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X6);
    // 0x80023FC4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80023FC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80023FCC: jal         0x80035A7C
    // 0x80023FD0: sh          $t9, 0x98($s2)
    MEM_H(0X98, ctx->r18) = ctx->r25;
    func_80035A7C(rdram, ctx);
        goto after_2;
    // 0x80023FD0: sh          $t9, 0x98($s2)
    MEM_H(0X98, ctx->r18) = ctx->r25;
    after_2:
    // 0x80023FD4: lh          $s0, 0xA($s1)
    ctx->r16 = MEM_H(ctx->r17, 0XA);
    // 0x80023FD8: addiu       $s1, $s1, 0xA
    ctx->r17 = ADD32(ctx->r17, 0XA);
    // 0x80023FDC: bnel        $s0, $zero, L_80023FBC
    if (ctx->r16 != 0) {
        // 0x80023FE0: sh          $s0, 0x94($s2)
        MEM_H(0X94, ctx->r18) = ctx->r16;
            goto L_80023FBC;
    }
    goto skip_10;
    // 0x80023FE0: sh          $s0, 0x94($s2)
    MEM_H(0X94, ctx->r18) = ctx->r16;
    skip_10:
    // 0x80023FE4: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80023FE8: lw          $t0, -0x6710($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X6710);
    // 0x80023FEC: addu        $v0, $t0, $s4
    ctx->r2 = ADD32(ctx->r8, ctx->r20);
    // 0x80023FF0: lh          $t1, 0xC($v0)
    ctx->r9 = MEM_H(ctx->r2, 0XC);
L_80023FF4:
    // 0x80023FF4: addiu       $s4, $s4, 0xC
    ctx->r20 = ADD32(ctx->r20, 0XC);
    // 0x80023FF8: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x80023FFC: bnel        $t1, $zero, L_80023FAC
    if (ctx->r9 != 0) {
        // 0x80024000: lw          $s1, 0x4($v0)
        ctx->r17 = MEM_W(ctx->r2, 0X4);
            goto L_80023FAC;
    }
    goto skip_11;
    // 0x80024000: lw          $s1, 0x4($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X4);
    skip_11:
L_80024004:
    // 0x80024004: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80024008: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8002400C: jal         0x800042A8
    // 0x80024010: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800042A8(rdram, ctx);
        goto after_3;
    // 0x80024010: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_3:
    // 0x80024014: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80024018: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002401C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80024020: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80024024: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80024028: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8002402C: jr          $ra
    // 0x80024030: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    TRACE_RETURN()
    return;
    // 0x80024030: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80024034(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80024034: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8002403C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8002403C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80024040: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80024044: lh          $t6, -0x6B94($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X6B94);
    // 0x80024048: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8002404C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80024050: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80024054: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80024058: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8002405C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80024060: beq         $t6, $zero, L_800241F8
    if (ctx->r14 == 0) {
        // 0x80024064: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800241F8;
    }
    // 0x80024064: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80024068: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8002406C: lh          $t7, -0x6B80($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X6B80);
    // 0x80024070: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x80024074: addiu       $s5, $s5, -0x66E8
    ctx->r21 = ADD32(ctx->r21, -0X66E8);
    // 0x80024078: bne         $t7, $zero, L_800241F8
    if (ctx->r15 != 0) {
        // 0x8002407C: lui         $t2, 0x8013
        ctx->r10 = S32(0X8013 << 16);
            goto L_800241F8;
    }
    // 0x8002407C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80024080: lh          $v1, 0x0($s5)
    ctx->r3 = MEM_H(ctx->r21, 0X0);
    // 0x80024084: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80024088: addiu       $s1, $s1, -0x6714
    ctx->r17 = ADD32(ctx->r17, -0X6714);
    // 0x8002408C: beq         $v1, $zero, L_800240AC
    if (ctx->r3 == 0) {
        // 0x80024090: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800240AC;
    }
    // 0x80024090: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80024094: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80024098: beq         $v0, $at, L_800240D0
    if (ctx->r2 == ctx->r1) {
        // 0x8002409C: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800240D0;
    }
    // 0x8002409C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800240A0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800240A4: b           L_800240EC
    // 0x800240A8: addiu       $a0, $a0, -0x66E6
    ctx->r4 = ADD32(ctx->r4, -0X66E6);
        goto L_800240EC;
    // 0x800240A8: addiu       $a0, $a0, -0x66E6
    ctx->r4 = ADD32(ctx->r4, -0X66E6);
L_800240AC:
    // 0x800240AC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800240B0: addiu       $a0, $a0, -0x66E6
    ctx->r4 = ADD32(ctx->r4, -0X66E6);
    // 0x800240B4: lh          $t8, 0x0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X0);
    // 0x800240B8: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x800240BC: slti        $at, $t8, 0x2329
    ctx->r1 = SIGNED(ctx->r24) < 0X2329 ? 1 : 0;
    // 0x800240C0: bne         $at, $zero, L_800240EC
    if (ctx->r1 != 0) {
        // 0x800240C4: nop
    
            goto L_800240EC;
    }
    // 0x800240C4: nop

    // 0x800240C8: b           L_800240EC
    // 0x800240CC: sh          $t9, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r25;
        goto L_800240EC;
    // 0x800240CC: sh          $t9, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r25;
L_800240D0:
    // 0x800240D0: addiu       $a0, $a0, -0x66E6
    ctx->r4 = ADD32(ctx->r4, -0X66E6);
    // 0x800240D4: lh          $t0, 0x0($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X0);
    // 0x800240D8: addiu       $t1, $v1, 0x1
    ctx->r9 = ADD32(ctx->r3, 0X1);
    // 0x800240DC: slti        $at, $t0, 0x3139
    ctx->r1 = SIGNED(ctx->r8) < 0X3139 ? 1 : 0;
    // 0x800240E0: bne         $at, $zero, L_800240EC
    if (ctx->r1 != 0) {
        // 0x800240E4: nop
    
            goto L_800240EC;
    }
    // 0x800240E4: nop

    // 0x800240E8: sh          $t1, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r9;
L_800240EC:
    // 0x800240EC: lh          $t2, -0x662C($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X662C);
    // 0x800240F0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800240F4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800240F8: beq         $t2, $at, L_8002411C
    if (ctx->r10 == ctx->r1) {
        // 0x800240FC: lui         $s4, 0x8013
        ctx->r20 = S32(0X8013 << 16);
            goto L_8002411C;
    }
    // 0x800240FC: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x80024100: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x80024104: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x80024108: ori         $at, $at, 0xBF20
    ctx->r1 = ctx->r1 | 0XBF20;
    // 0x8002410C: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80024110: beq         $at, $zero, L_8002411C
    if (ctx->r1 == 0) {
        // 0x80024114: addiu       $t3, $v0, 0x1
        ctx->r11 = ADD32(ctx->r2, 0X1);
            goto L_8002411C;
    }
    // 0x80024114: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x80024118: sh          $t3, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r11;
L_8002411C:
    // 0x8002411C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80024120: addiu       $s4, $s4, -0x6710
    ctx->r20 = ADD32(ctx->r20, -0X6710);
    // 0x80024124: addiu       $s3, $zero, 0x600
    ctx->r19 = ADD32(0, 0X600);
    // 0x80024128: lh          $t4, 0x0($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X0);
    // 0x8002412C: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x80024130: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80024134: beql        $t4, $zero, L_800241FC
    if (ctx->r12 == 0) {
        // 0x80024138: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800241FC;
    }
    goto skip_0;
    // 0x80024138: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x8002413C: lh          $v1, 0x8($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X8);
L_80024140:
    // 0x80024140: bne         $v1, $zero, L_800241D0
    if (ctx->r3 != 0) {
        // 0x80024144: nop
    
            goto L_800241D0;
    }
    // 0x80024144: nop

    // 0x80024148: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x8002414C: bnel        $s3, $a0, L_80024160
    if (ctx->r19 != ctx->r4) {
        // 0x80024150: lh          $v1, 0x0($s5)
        ctx->r3 = MEM_H(ctx->r21, 0X0);
            goto L_80024160;
    }
    goto skip_1;
    // 0x80024150: lh          $v1, 0x0($s5)
    ctx->r3 = MEM_H(ctx->r21, 0X0);
    skip_1:
    // 0x80024154: b           L_80024160
    // 0x80024158: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80024160;
    // 0x80024158: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002415C: lh          $v1, 0x0($s5)
    ctx->r3 = MEM_H(ctx->r21, 0X0);
L_80024160:
    // 0x80024160: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x80024164: lh          $t5, 0x4($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X4);
    // 0x80024168: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x8002416C: slt         $at, $t5, $t7
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80024170: beql        $at, $zero, L_800241E8
    if (ctx->r1 == 0) {
        // 0x80024174: lh          $t9, 0xA($v0)
        ctx->r25 = MEM_H(ctx->r2, 0XA);
            goto L_800241E8;
    }
    goto skip_2;
    // 0x80024174: lh          $t9, 0xA($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XA);
    skip_2:
    // 0x80024178: jal         0x80024A08
    // 0x8002417C: lw          $a1, 0x0($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X0);
    func_80024A08(rdram, ctx);
        goto after_0;
    // 0x8002417C: lw          $a1, 0x0($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X0);
    after_0:
    // 0x80024180: beql        $v0, $zero, L_800241BC
    if (ctx->r2 == 0) {
        // 0x80024184: lw          $t4, 0x0($s1)
        ctx->r12 = MEM_W(ctx->r17, 0X0);
            goto L_800241BC;
    }
    goto skip_3;
    // 0x80024184: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    skip_3:
    // 0x80024188: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8002418C: addu        $v0, $t8, $s0
    ctx->r2 = ADD32(ctx->r24, ctx->r16);
    // 0x80024190: lh          $t9, 0x4($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X4);
    // 0x80024194: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80024198: sh          $t0, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r8;
    // 0x8002419C: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x800241A0: addu        $v0, $t1, $s0
    ctx->r2 = ADD32(ctx->r9, ctx->r16);
    // 0x800241A4: lh          $t2, 0x6($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X6);
    // 0x800241A8: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x800241AC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x800241B0: b           L_800241E4
    // 0x800241B4: addu        $v0, $t3, $s0
    ctx->r2 = ADD32(ctx->r11, ctx->r16);
        goto L_800241E4;
    // 0x800241B4: addu        $v0, $t3, $s0
    ctx->r2 = ADD32(ctx->r11, ctx->r16);
    // 0x800241B8: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
L_800241BC:
    // 0x800241BC: addu        $t6, $t4, $s0
    ctx->r14 = ADD32(ctx->r12, ctx->r16);
    // 0x800241C0: sh          $s2, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r18;
    // 0x800241C4: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x800241C8: b           L_800241E4
    // 0x800241CC: addu        $v0, $t5, $s0
    ctx->r2 = ADD32(ctx->r13, ctx->r16);
        goto L_800241E4;
    // 0x800241CC: addu        $v0, $t5, $s0
    ctx->r2 = ADD32(ctx->r13, ctx->r16);
L_800241D0:
    // 0x800241D0: beq         $s2, $v1, L_800241E4
    if (ctx->r18 == ctx->r3) {
        // 0x800241D4: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_800241E4;
    }
    // 0x800241D4: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x800241D8: sh          $t7, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r15;
    // 0x800241DC: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800241E0: addu        $v0, $t8, $s0
    ctx->r2 = ADD32(ctx->r24, ctx->r16);
L_800241E4:
    // 0x800241E4: lh          $t9, 0xA($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XA);
L_800241E8:
    // 0x800241E8: addiu       $s0, $s0, 0xA
    ctx->r16 = ADD32(ctx->r16, 0XA);
    // 0x800241EC: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x800241F0: bnel        $t9, $zero, L_80024140
    if (ctx->r25 != 0) {
        // 0x800241F4: lh          $v1, 0x8($v0)
        ctx->r3 = MEM_H(ctx->r2, 0X8);
            goto L_80024140;
    }
    goto skip_4;
    // 0x800241F4: lh          $v1, 0x8($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X8);
    skip_4:
L_800241F8:
    // 0x800241F8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800241FC:
    // 0x800241FC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80024200: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80024204: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80024208: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8002420C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80024210: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80024214: jr          $ra
    // 0x80024218: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    TRACE_RETURN()
    return;
    // 0x80024218: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8002421C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8002421C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80024220: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80024224: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80024228: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8002422C: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80024230: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80024234: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80024238: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002423C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80024240: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80024244: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80024248: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8002424C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80024250: addiu       $v0, $v0, -0x6770
    ctx->r2 = ADD32(ctx->r2, -0X6770);
    // 0x80024254: addiu       $s0, $s0, -0x67F0
    ctx->r16 = ADD32(ctx->r16, -0X67F0);
L_80024258:
    // 0x80024258: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8002425C: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x80024260: sh          $zero, -0x4($s0)
    MEM_H(-0X4, ctx->r16) = 0;
    // 0x80024264: bne         $at, $zero, L_80024258
    if (ctx->r1 != 0) {
        // 0x80024268: sh          $zero, -0x2($s0)
        MEM_H(-0X2, ctx->r16) = 0;
            goto L_80024258;
    }
    // 0x80024268: sh          $zero, -0x2($s0)
    MEM_H(-0X2, ctx->r16) = 0;
    // 0x8002426C: beq         $a0, $zero, L_800243E4
    if (ctx->r4 == 0) {
        // 0x80024270: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800243E4;
    }
    // 0x80024270: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80024274: lh          $v0, -0x662C($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X662C);
    // 0x80024278: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002427C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80024280: beq         $v0, $at, L_80024294
    if (ctx->r2 == ctx->r1) {
        // 0x80024284: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80024294;
    }
    // 0x80024284: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80024288: beq         $v0, $at, L_80024294
    if (ctx->r2 == ctx->r1) {
        // 0x8002428C: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80024294;
    }
    // 0x8002428C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80024290: bne         $v0, $at, L_800243E4
    if (ctx->r2 != ctx->r1) {
        // 0x80024294: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800243E4;
    }
L_80024294:
    // 0x80024294: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80024298: lw          $v0, -0x6710($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6710);
    // 0x8002429C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800242A0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800242A4: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x800242A8: addiu       $t0, $t0, -0x67F0
    ctx->r8 = ADD32(ctx->r8, -0X67F0);
    // 0x800242AC: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x800242B0: beq         $t8, $zero, L_8002431C
    if (ctx->r24 == 0) {
        // 0x800242B4: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8002431C;
    }
    // 0x800242B4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800242B8: lw          $v0, 0x4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X4);
L_800242BC:
    // 0x800242BC: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800242C0: addiu       $t1, $t1, -0x67F0
    ctx->r9 = ADD32(ctx->r9, -0X67F0);
    // 0x800242C4: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x800242C8: sll         $t9, $s1, 2
    ctx->r25 = S32(ctx->r17 << 2);
    // 0x800242CC: addu        $v1, $t9, $t1
    ctx->r3 = ADD32(ctx->r25, ctx->r9);
    // 0x800242D0: beql        $a0, $zero, L_8002430C
    if (ctx->r4 == 0) {
        // 0x800242D4: lh          $t6, 0xC($a2)
        ctx->r14 = MEM_H(ctx->r6, 0XC);
            goto L_8002430C;
    }
    goto skip_0;
    // 0x800242D4: lh          $t6, 0xC($a2)
    ctx->r14 = MEM_H(ctx->r6, 0XC);
    skip_0:
L_800242D8:
    // 0x800242D8: sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
    // 0x800242DC: lh          $t2, 0x8($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X8);
    // 0x800242E0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800242E4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800242E8: sh          $t2, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r10;
    // 0x800242EC: lh          $t3, 0x8($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X8);
    // 0x800242F0: lh          $a0, 0xA($v0)
    ctx->r4 = MEM_H(ctx->r2, 0XA);
    // 0x800242F4: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x800242F8: addu        $a1, $a1, $t3
    ctx->r5 = ADD32(ctx->r5, ctx->r11);
    // 0x800242FC: sll         $t4, $a1, 16
    ctx->r12 = S32(ctx->r5 << 16);
    // 0x80024300: bne         $a0, $zero, L_800242D8
    if (ctx->r4 != 0) {
        // 0x80024304: sra         $a1, $t4, 16
        ctx->r5 = S32(SIGNED(ctx->r12) >> 16);
            goto L_800242D8;
    }
    // 0x80024304: sra         $a1, $t4, 16
    ctx->r5 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80024308: lh          $t6, 0xC($a2)
    ctx->r14 = MEM_H(ctx->r6, 0XC);
L_8002430C:
    // 0x8002430C: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x80024310: bnel        $t6, $zero, L_800242BC
    if (ctx->r14 != 0) {
        // 0x80024314: lw          $v0, 0x4($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X4);
            goto L_800242BC;
    }
    goto skip_1;
    // 0x80024314: lw          $v0, 0x4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X4);
    skip_1:
    // 0x80024318: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8002431C:
    // 0x8002431C: lw          $t7, -0x6810($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6810);
    // 0x80024320: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80024324: lw          $a2, 0x0($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X0);
    // 0x80024328: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x8002432C: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80024330: beq         $a3, $zero, L_800243B4
    if (ctx->r7 == 0) {
        // 0x80024334: nop
    
            goto L_800243B4;
    }
    // 0x80024334: nop

    // 0x80024338: lh          $t8, 0x2E($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X2E);
L_8002433C:
    // 0x8002433C: blezl       $t8, L_800243A8
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80024340: or          $a2, $a3, $zero
        ctx->r6 = ctx->r7 | 0;
            goto L_800243A8;
    }
    goto skip_2;
    // 0x80024340: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    skip_2:
    // 0x80024344: lh          $t9, 0x0($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X0);
    // 0x80024348: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8002434C: addiu       $s0, $t1, -0x67F0
    ctx->r16 = ADD32(ctx->r9, -0X67F0);
    // 0x80024350: beql        $t9, $zero, L_800243A8
    if (ctx->r25 == 0) {
        // 0x80024354: or          $a2, $a3, $zero
        ctx->r6 = ctx->r7 | 0;
            goto L_800243A8;
    }
    goto skip_3;
    // 0x80024354: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    skip_3:
    // 0x80024358: lh          $a0, 0x94($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X94);
    // 0x8002435C: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
L_80024360:
    // 0x80024360: bnel        $a0, $v0, L_80024390
    if (ctx->r4 != ctx->r2) {
        // 0x80024364: lh          $v0, 0x4($s0)
        ctx->r2 = MEM_H(ctx->r16, 0X4);
            goto L_80024390;
    }
    goto skip_4;
    // 0x80024364: lh          $v0, 0x4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4);
    skip_4:
    // 0x80024368: lh          $t2, 0x2($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X2);
    // 0x8002436C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80024370: sll         $t4, $a1, 16
    ctx->r12 = S32(ctx->r5 << 16);
    // 0x80024374: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80024378: sh          $t3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r11;
    // 0x8002437C: sra         $a1, $t4, 16
    ctx->r5 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80024380: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80024384: b           L_800243A4
    // 0x80024388: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_800243A4;
    // 0x80024388: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002438C: lh          $v0, 0x4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4);
L_80024390:
    // 0x80024390: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80024394: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80024398: bne         $v0, $zero, L_80024360
    if (ctx->r2 != 0) {
        // 0x8002439C: nop
    
            goto L_80024360;
    }
    // 0x8002439C: nop

    // 0x800243A0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800243A4:
    // 0x800243A4: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
L_800243A8:
    // 0x800243A8: lw          $a3, 0x0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X0);
    // 0x800243AC: bnel        $a3, $zero, L_8002433C
    if (ctx->r7 != 0) {
        // 0x800243B0: lh          $t8, 0x2E($a2)
        ctx->r24 = MEM_H(ctx->r6, 0X2E);
            goto L_8002433C;
    }
    goto skip_5;
    // 0x800243B0: lh          $t8, 0x2E($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X2E);
    skip_5:
L_800243B4:
    // 0x800243B4: blez        $s1, L_800243E4
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800243B8: addiu       $s0, $t6, -0x67F0
        ctx->r16 = ADD32(ctx->r14, -0X67F0);
            goto L_800243E4;
    }
    // 0x800243B8: addiu       $s0, $t6, -0x67F0
    ctx->r16 = ADD32(ctx->r14, -0X67F0);
    // 0x800243BC: addu        $s2, $t7, $s0
    ctx->r18 = ADD32(ctx->r15, ctx->r16);
    // 0x800243C0: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
L_800243C4:
    // 0x800243C4: jal         0x80024400
    // 0x800243C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80024400(rdram, ctx);
        goto after_0;
    // 0x800243C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800243CC: bnel        $v0, $s3, L_800243DC
    if (ctx->r2 != ctx->r19) {
        // 0x800243D0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800243DC;
    }
    goto skip_6;
    // 0x800243D0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_6:
    // 0x800243D4: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x800243D8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800243DC:
    // 0x800243DC: bnel        $s0, $s2, L_800243C4
    if (ctx->r16 != ctx->r18) {
        // 0x800243E0: lh          $a0, 0x0($s0)
        ctx->r4 = MEM_H(ctx->r16, 0X0);
            goto L_800243C4;
    }
    goto skip_7;
    // 0x800243E0: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    skip_7:
L_800243E4:
    // 0x800243E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800243E8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800243EC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800243F0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800243F4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800243F8: jr          $ra
    // 0x800243FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    TRACE_RETURN()
    return;
    // 0x800243FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80024400(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80024400: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x80024404: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80024408: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8002440C: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80024410: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80024414: bne         $t9, $zero, L_80024468
    if (ctx->r25 != 0) {
        // 0x80024418: sw          $a1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r5;
            goto L_80024468;
    }
    // 0x80024418: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8002441C: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x80024420: addiu       $a1, $a1, -0x5ED0
    ctx->r5 = ADD32(ctx->r5, -0X5ED0);
    // 0x80024424: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80024428: sll         $t0, $v1, 1
    ctx->r8 = S32(ctx->r3 << 1);
L_8002442C:
    // 0x8002442C: addu        $t1, $a1, $t0
    ctx->r9 = ADD32(ctx->r5, ctx->r8);
    // 0x80024430: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x80024434: bne         $a0, $t2, L_80024448
    if (ctx->r4 != ctx->r10) {
        // 0x80024438: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_80024448;
    }
    // 0x80024438: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8002443C: sll         $t3, $v0, 16
    ctx->r11 = S32(ctx->r2 << 16);
    // 0x80024440: jr          $ra
    // 0x80024444: sra         $v0, $t3, 16
    ctx->r2 = S32(SIGNED(ctx->r11) >> 16);
    TRACE_RETURN()
    return;
    // 0x80024444: sra         $v0, $t3, 16
    ctx->r2 = S32(SIGNED(ctx->r11) >> 16);
L_80024448:
    // 0x80024448: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002444C: sll         $t5, $v1, 16
    ctx->r13 = S32(ctx->r3 << 16);
    // 0x80024450: sra         $v1, $t5, 16
    ctx->r3 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80024454: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x80024458: bnel        $at, $zero, L_8002442C
    if (ctx->r1 != 0) {
        // 0x8002445C: sll         $t0, $v1, 1
        ctx->r8 = S32(ctx->r3 << 1);
            goto L_8002442C;
    }
    goto skip_0;
    // 0x8002445C: sll         $t0, $v1, 1
    ctx->r8 = S32(ctx->r3 << 1);
    skip_0:
    // 0x80024460: jr          $ra
    // 0x80024464: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    TRACE_RETURN()
    return;
    // 0x80024464: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80024468:
    // 0x80024468: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x8002446C: addiu       $a1, $a1, -0x5ED0
    ctx->r5 = ADD32(ctx->r5, -0X5ED0);
    // 0x80024470: sll         $t7, $a0, 1
    ctx->r15 = S32(ctx->r4 << 1);
    // 0x80024474: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x80024478: lh          $v0, -0x2($t8)
    ctx->r2 = MEM_H(ctx->r24, -0X2);
    // 0x8002447C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80024484(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80024484: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80024488: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8002448C: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80024490: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80024494: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80024498: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8002449C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800244A0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800244A4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800244A8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800244AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800244B0: bne         $t7, $zero, L_8002457C
    if (ctx->r15 != 0) {
        // 0x800244B4: sw          $a0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r4;
            goto L_8002457C;
    }
    // 0x800244B4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800244B8: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800244BC: addiu       $s4, $s4, -0x6B68
    ctx->r20 = ADD32(ctx->r20, -0X6B68);
    // 0x800244C0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800244C4:
    // 0x800244C4: addu        $t8, $s4, $s0
    ctx->r24 = ADD32(ctx->r20, ctx->r16);
    // 0x800244C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800244CC: sll         $t9, $s0, 16
    ctx->r25 = S32(ctx->r16 << 16);
    // 0x800244D0: sra         $s0, $t9, 16
    ctx->r16 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800244D4: slti        $at, $s0, 0x10
    ctx->r1 = SIGNED(ctx->r16) < 0X10 ? 1 : 0;
    // 0x800244D8: bne         $at, $zero, L_800244C4
    if (ctx->r1 != 0) {
        // 0x800244DC: sb          $zero, 0x0($t8)
        MEM_B(0X0, ctx->r24) = 0;
            goto L_800244C4;
    }
    // 0x800244DC: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
    // 0x800244E0: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800244E4: addiu       $s5, $s5, -0x67F0
    ctx->r21 = ADD32(ctx->r21, -0X67F0);
    // 0x800244E8: lh          $v0, 0x0($s5)
    ctx->r2 = MEM_H(ctx->r21, 0X0);
    // 0x800244EC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800244F0: beql        $v0, $zero, L_80024630
    if (ctx->r2 == 0) {
        // 0x800244F4: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80024630;
    }
    goto skip_0;
    // 0x800244F4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x800244F8: beq         $v0, $zero, L_8002462C
    if (ctx->r2 == 0) {
        // 0x800244FC: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8002462C;
    }
    // 0x800244FC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80024500: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80024504: addiu       $s1, $s1, -0x67F0
    ctx->r17 = ADD32(ctx->r17, -0X67F0);
    // 0x80024508: addiu       $s6, $zero, 0x10
    ctx->r22 = ADD32(0, 0X10);
    // 0x8002450C: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x80024510: lh          $t1, 0x2($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X2);
L_80024514:
    // 0x80024514: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80024518: beql        $t1, $zero, L_80024558
    if (ctx->r9 == 0) {
        // 0x8002451C: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80024558;
    }
    goto skip_1;
    // 0x8002451C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_1:
    // 0x80024520: jal         0x80024400
    // 0x80024524: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    func_80024400(rdram, ctx);
        goto after_0;
    // 0x80024524: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    after_0:
    // 0x80024528: beq         $v0, $s2, L_80024554
    if (ctx->r2 == ctx->r18) {
        // 0x8002452C: sll         $t4, $v0, 4
        ctx->r12 = S32(ctx->r2 << 4);
            goto L_80024554;
    }
    // 0x8002452C: sll         $t4, $v0, 4
    ctx->r12 = S32(ctx->r2 << 4);
    // 0x80024530: lh          $v1, 0x2($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X2);
    // 0x80024534: addu        $t7, $s4, $s0
    ctx->r15 = ADD32(ctx->r20, ctx->r16);
    // 0x80024538: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002453C: sll         $t8, $s0, 16
    ctx->r24 = S32(ctx->r16 << 16);
    // 0x80024540: andi        $t5, $v1, 0xF
    ctx->r13 = ctx->r3 & 0XF;
    // 0x80024544: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x80024548: sra         $s0, $t8, 16
    ctx->r16 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002454C: beq         $s0, $s6, L_8002462C
    if (ctx->r16 == ctx->r22) {
        // 0x80024550: sb          $t6, 0x0($t7)
        MEM_B(0X0, ctx->r15) = ctx->r14;
            goto L_8002462C;
    }
    // 0x80024550: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
L_80024554:
    // 0x80024554: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80024558:
    // 0x80024558: sll         $t0, $s3, 16
    ctx->r8 = S32(ctx->r19 << 16);
    // 0x8002455C: sra         $s3, $t0, 16
    ctx->r19 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80024560: sll         $t2, $s3, 2
    ctx->r10 = S32(ctx->r19 << 2);
    // 0x80024564: addu        $s1, $s5, $t2
    ctx->r17 = ADD32(ctx->r21, ctx->r10);
    // 0x80024568: lh          $t3, 0x0($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X0);
    // 0x8002456C: bnel        $t3, $zero, L_80024514
    if (ctx->r11 != 0) {
        // 0x80024570: lh          $t1, 0x2($s1)
        ctx->r9 = MEM_H(ctx->r17, 0X2);
            goto L_80024514;
    }
    goto skip_2;
    // 0x80024570: lh          $t1, 0x2($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X2);
    skip_2:
    // 0x80024574: b           L_80024630
    // 0x80024578: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_80024630;
    // 0x80024578: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8002457C:
    // 0x8002457C: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x80024580: addiu       $s5, $s5, -0x67F0
    ctx->r21 = ADD32(ctx->r21, -0X67F0);
    // 0x80024584: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80024588:
    // 0x80024588: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x8002458C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80024590: sll         $t5, $s0, 16
    ctx->r13 = S32(ctx->r16 << 16);
    // 0x80024594: sra         $s0, $t5, 16
    ctx->r16 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80024598: slti        $at, $s0, 0x20
    ctx->r1 = SIGNED(ctx->r16) < 0X20 ? 1 : 0;
    // 0x8002459C: addu        $v0, $s5, $t4
    ctx->r2 = ADD32(ctx->r21, ctx->r12);
    // 0x800245A0: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x800245A4: bne         $at, $zero, L_80024588
    if (ctx->r1 != 0) {
        // 0x800245A8: sh          $zero, 0x2($v0)
        MEM_H(0X2, ctx->r2) = 0;
            goto L_80024588;
    }
    // 0x800245A8: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x800245AC: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800245B0: addiu       $s4, $s4, -0x6B68
    ctx->r20 = ADD32(ctx->r20, -0X6B68);
    // 0x800245B4: lbu         $t7, 0x0($s4)
    ctx->r15 = MEM_BU(ctx->r20, 0X0);
    // 0x800245B8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800245BC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800245C0: beq         $t7, $zero, L_8002462C
    if (ctx->r15 == 0) {
        // 0x800245C4: addu        $t8, $s4, $s0
        ctx->r24 = ADD32(ctx->r20, ctx->r16);
            goto L_8002462C;
    }
    // 0x800245C4: addu        $t8, $s4, $s0
    ctx->r24 = ADD32(ctx->r20, ctx->r16);
L_800245C8:
    // 0x800245C8: lbu         $v0, 0x0($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X0);
    // 0x800245CC: beq         $v0, $zero, L_8002462C
    if (ctx->r2 == 0) {
        // 0x800245D0: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_8002462C;
    }
    // 0x800245D0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800245D4: sra         $a0, $v0, 4
    ctx->r4 = S32(SIGNED(ctx->r2) >> 4);
    // 0x800245D8: andi        $t9, $a0, 0xF
    ctx->r25 = ctx->r4 & 0XF;
    // 0x800245DC: sll         $t0, $t9, 16
    ctx->r8 = S32(ctx->r25 << 16);
    // 0x800245E0: sra         $a0, $t0, 16
    ctx->r4 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800245E4: beql        $a0, $zero, L_80024618
    if (ctx->r4 == 0) {
        // 0x800245E8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80024618;
    }
    goto skip_3;
    // 0x800245E8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_3:
    // 0x800245EC: jal         0x80024400
    // 0x800245F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80024400(rdram, ctx);
        goto after_1;
    // 0x800245F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x800245F4: sll         $t2, $s3, 2
    ctx->r10 = S32(ctx->r19 << 2);
    // 0x800245F8: addu        $s1, $s5, $t2
    ctx->r17 = ADD32(ctx->r21, ctx->r10);
    // 0x800245FC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80024600: andi        $t3, $s2, 0xF
    ctx->r11 = ctx->r18 & 0XF;
    // 0x80024604: sll         $t4, $s3, 16
    ctx->r12 = S32(ctx->r19 << 16);
    // 0x80024608: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // 0x8002460C: sh          $t3, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r11;
    // 0x80024610: sra         $s3, $t4, 16
    ctx->r19 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80024614: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80024618:
    // 0x80024618: sll         $t6, $s0, 16
    ctx->r14 = S32(ctx->r16 << 16);
    // 0x8002461C: sra         $s0, $t6, 16
    ctx->r16 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80024620: slti        $at, $s0, 0x10
    ctx->r1 = SIGNED(ctx->r16) < 0X10 ? 1 : 0;
    // 0x80024624: bnel        $at, $zero, L_800245C8
    if (ctx->r1 != 0) {
        // 0x80024628: addu        $t8, $s4, $s0
        ctx->r24 = ADD32(ctx->r20, ctx->r16);
            goto L_800245C8;
    }
    goto skip_4;
    // 0x80024628: addu        $t8, $s4, $s0
    ctx->r24 = ADD32(ctx->r20, ctx->r16);
    skip_4:
L_8002462C:
    // 0x8002462C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80024630:
    // 0x80024630: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80024634: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80024638: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8002463C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80024640: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80024644: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80024648: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8002464C: jr          $ra
    // 0x80024650: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    TRACE_RETURN()
    return;
    // 0x80024650: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80024654(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80024654: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80024658: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x8002465C: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80024660: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80024664: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80024668: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x8002466C: bne         $t9, $zero, L_80024710
    if (ctx->r25 != 0) {
        // 0x80024670: sw          $a2, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r6;
            goto L_80024710;
    }
    // 0x80024670: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80024674: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80024678: beq         $t7, $at, L_8002469C
    if (ctx->r15 == ctx->r1) {
        // 0x8002467C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8002469C;
    }
    // 0x8002467C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80024680: sh          $t7, 0x80($a0)
    MEM_H(0X80, ctx->r4) = ctx->r15;
    // 0x80024684: lh          $t0, 0x80($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X80);
    // 0x80024688: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x8002468C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80024690: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80024694: lw          $t2, -0x6750($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X6750);
    // 0x80024698: sw          $t2, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r10;
L_8002469C:
    // 0x8002469C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800246A0: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x800246A4: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x800246A8: beq         $v1, $v0, L_800246DC
    if (ctx->r3 == ctx->r2) {
        // 0x800246AC: lw          $t3, 0x7C($a0)
        ctx->r11 = MEM_W(ctx->r4, 0X7C);
            goto L_800246DC;
    }
    // 0x800246AC: lw          $t3, 0x7C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X7C);
L_800246B0:
    // 0x800246B0: addu        $t4, $t3, $v1
    ctx->r12 = ADD32(ctx->r11, ctx->r3);
    // 0x800246B4: lwc1        $f18, 0x4($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X4);
    // 0x800246B8: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800246BC: swc1        $f18, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f18.u32l;
    // 0x800246C0: lw          $t5, 0x7C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X7C);
    // 0x800246C4: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x800246C8: lwc1        $f18, 0x10($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X10);
    // 0x800246CC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800246D0: swc1        $f18, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f18.u32l;
    // 0x800246D4: bne         $v1, $v0, L_800246B0
    if (ctx->r3 != ctx->r2) {
        // 0x800246D8: lw          $t3, 0x7C($a0)
        ctx->r11 = MEM_W(ctx->r4, 0X7C);
            goto L_800246B0;
    }
    // 0x800246D8: lw          $t3, 0x7C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X7C);
L_800246DC:
    // 0x800246DC: addu        $t4, $t3, $v1
    ctx->r12 = ADD32(ctx->r11, ctx->r3);
    // 0x800246E0: lwc1        $f18, 0x4($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X4);
    // 0x800246E4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800246E8: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800246EC: swc1        $f18, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f18.u32l;
    // 0x800246F0: lw          $t5, 0x7C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X7C);
    // 0x800246F4: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x800246F8: lwc1        $f18, 0x10($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X10);
    // 0x800246FC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80024700: swc1        $f18, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f18.u32l;
    // 0x80024704: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80024708: jr          $ra
    // 0x8002470C: sh          $t7, 0x82($a0)
    MEM_H(0X82, ctx->r4) = ctx->r15;
    TRACE_RETURN()
    return;
    // 0x8002470C: sh          $t7, 0x82($a0)
    MEM_H(0X82, ctx->r4) = ctx->r15;
L_80024710:
    // 0x80024710: sh          $a1, 0x78($a0)
    MEM_H(0X78, ctx->r4) = ctx->r5;
    // 0x80024714: lh          $t8, 0x78($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X78);
    // 0x80024718: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8002471C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80024720: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80024724: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80024728: lw          $t0, -0x6750($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X6750);
    // 0x8002472C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80024730: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x80024734: sw          $t0, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->r8;
    // 0x80024738: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x8002473C: beq         $v1, $v0, L_80024770
    if (ctx->r3 == ctx->r2) {
        // 0x80024740: lw          $t1, 0x74($a0)
        ctx->r9 = MEM_W(ctx->r4, 0X74);
            goto L_80024770;
    }
    // 0x80024740: lw          $t1, 0x74($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X74);
L_80024744:
    // 0x80024744: addu        $t2, $t1, $v1
    ctx->r10 = ADD32(ctx->r9, ctx->r3);
    // 0x80024748: lwc1        $f18, 0x4($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X4);
    // 0x8002474C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80024750: swc1        $f18, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f18.u32l;
    // 0x80024754: lw          $t3, 0x74($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X74);
    // 0x80024758: addu        $t4, $t3, $v1
    ctx->r12 = ADD32(ctx->r11, ctx->r3);
    // 0x8002475C: lwc1        $f18, 0x10($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X10);
    // 0x80024760: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80024764: swc1        $f18, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f18.u32l;
    // 0x80024768: bne         $v1, $v0, L_80024744
    if (ctx->r3 != ctx->r2) {
        // 0x8002476C: lw          $t1, 0x74($a0)
        ctx->r9 = MEM_W(ctx->r4, 0X74);
            goto L_80024744;
    }
    // 0x8002476C: lw          $t1, 0x74($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X74);
L_80024770:
    // 0x80024770: addu        $t2, $t1, $v1
    ctx->r10 = ADD32(ctx->r9, ctx->r3);
    // 0x80024774: lwc1        $f18, 0x4($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X4);
    // 0x80024778: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8002477C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80024780: swc1        $f18, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f18.u32l;
    // 0x80024784: lw          $t3, 0x74($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X74);
    // 0x80024788: addu        $t4, $t3, $v1
    ctx->r12 = ADD32(ctx->r11, ctx->r3);
    // 0x8002478C: lwc1        $f18, 0x10($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X10);
    // 0x80024790: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80024794: swc1        $f18, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f18.u32l;
    // 0x80024798: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8002479C: sh          $t5, 0x7A($a0)
    MEM_H(0X7A, ctx->r4) = ctx->r13;
    // 0x800247A0: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800247A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800247A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800247AC: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800247B0: lw          $a2, -0x6714($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X6714);
    // 0x800247B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800247B8: lh          $a1, 0x94($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X94);
    // 0x800247BC: lh          $t9, 0x0($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X0);
    // 0x800247C0: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x800247C4: andi        $t6, $a1, 0xFF00
    ctx->r14 = ctx->r5 & 0XFF00;
    // 0x800247C8: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800247CC: beq         $t9, $zero, L_80024800
    if (ctx->r25 == 0) {
        // 0x800247D0: sra         $a1, $t7, 16
        ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
            goto L_80024800;
    }
    // 0x800247D0: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800247D4: lh          $v1, 0x0($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X0);
L_800247D8:
    // 0x800247D8: bnel        $a1, $v1, L_800247F4
    if (ctx->r5 != ctx->r3) {
        // 0x800247DC: lh          $v1, 0xA($v0)
        ctx->r3 = MEM_H(ctx->r2, 0XA);
            goto L_800247F4;
    }
    goto skip_0;
    // 0x800247DC: lh          $v1, 0xA($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XA);
    skip_0:
    // 0x800247E0: lh          $t0, 0x4($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X4);
    // 0x800247E4: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x800247E8: b           L_80024800
    // 0x800247EC: sh          $t1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r9;
        goto L_80024800;
    // 0x800247EC: sh          $t1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r9;
    // 0x800247F0: lh          $v1, 0xA($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XA);
L_800247F4:
    // 0x800247F4: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x800247F8: bne         $v1, $zero, L_800247D8
    if (ctx->r3 != 0) {
        // 0x800247FC: nop
    
            goto L_800247D8;
    }
    // 0x800247FC: nop

L_80024800:
    // 0x80024800: jal         0x80035C74
    // 0x80024804: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80035C74(rdram, ctx);
        goto after_0;
    // 0x80024804: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80024808: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002480C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80024810: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80024818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80024818: lh          $v0, 0x94($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X94);
    // 0x8002481C: andi        $t6, $v0, 0xFF00
    ctx->r14 = ctx->r2 & 0XFF00;
    // 0x80024820: slti        $at, $t6, 0x901
    ctx->r1 = SIGNED(ctx->r14) < 0X901 ? 1 : 0;
    // 0x80024824: bne         $at, $zero, L_800248AC
    if (ctx->r1 != 0) {
        // 0x80024828: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_800248AC;
    }
    // 0x80024828: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8002482C: slti        $at, $t6, 0xF01
    ctx->r1 = SIGNED(ctx->r14) < 0XF01 ? 1 : 0;
    // 0x80024830: bne         $at, $zero, L_80024868
    if (ctx->r1 != 0) {
        // 0x80024834: addiu       $at, $zero, 0x1000
        ctx->r1 = ADD32(0, 0X1000);
            goto L_80024868;
    }
    // 0x80024834: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x80024838: beq         $t6, $at, L_80024994
    if (ctx->r14 == ctx->r1) {
        // 0x8002483C: addiu       $at, $zero, 0x2000
        ctx->r1 = ADD32(0, 0X2000);
            goto L_80024994;
    }
    // 0x8002483C: addiu       $at, $zero, 0x2000
    ctx->r1 = ADD32(0, 0X2000);
    // 0x80024840: beq         $t6, $at, L_800249C8
    if (ctx->r14 == ctx->r1) {
        // 0x80024844: lui         $t0, 0x8003
        ctx->r8 = S32(0X8003 << 16);
            goto L_800249C8;
    }
    // 0x80024844: lui         $t0, 0x8003
    ctx->r8 = S32(0X8003 << 16);
    // 0x80024848: addiu       $at, $zero, 0x3000
    ctx->r1 = ADD32(0, 0X3000);
    // 0x8002484C: beq         $t6, $at, L_800249D4
    if (ctx->r14 == ctx->r1) {
        // 0x80024850: lui         $t1, 0x8003
        ctx->r9 = S32(0X8003 << 16);
            goto L_800249D4;
    }
    // 0x80024850: lui         $t1, 0x8003
    ctx->r9 = S32(0X8003 << 16);
    // 0x80024854: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x80024858: beq         $t6, $at, L_800249E0
    if (ctx->r14 == ctx->r1) {
        // 0x8002485C: lui         $t2, 0x8003
        ctx->r10 = S32(0X8003 << 16);
            goto L_800249E0;
    }
    // 0x8002485C: lui         $t2, 0x8003
    ctx->r10 = S32(0X8003 << 16);
    // 0x80024860: jr          $ra
    // 0x80024864: nop

    TRACE_RETURN()
    return;
    // 0x80024864: nop

L_80024868:
    // 0x80024868: addiu       $at, $zero, 0xA00
    ctx->r1 = ADD32(0, 0XA00);
    // 0x8002486C: beq         $v0, $at, L_80024988
    if (ctx->r2 == ctx->r1) {
        // 0x80024870: lui         $t5, 0x8003
        ctx->r13 = S32(0X8003 << 16);
            goto L_80024988;
    }
    // 0x80024870: lui         $t5, 0x8003
    ctx->r13 = S32(0X8003 << 16);
    // 0x80024874: addiu       $at, $zero, 0xB00
    ctx->r1 = ADD32(0, 0XB00);
    // 0x80024878: beq         $v0, $at, L_800249A4
    if (ctx->r2 == ctx->r1) {
        // 0x8002487C: lui         $t7, 0x8003
        ctx->r15 = S32(0X8003 << 16);
            goto L_800249A4;
    }
    // 0x8002487C: lui         $t7, 0x8003
    ctx->r15 = S32(0X8003 << 16);
    // 0x80024880: addiu       $at, $zero, 0xC00
    ctx->r1 = ADD32(0, 0XC00);
    // 0x80024884: beq         $v0, $at, L_800249B0
    if (ctx->r2 == ctx->r1) {
        // 0x80024888: lui         $t8, 0x8003
        ctx->r24 = S32(0X8003 << 16);
            goto L_800249B0;
    }
    // 0x80024888: lui         $t8, 0x8003
    ctx->r24 = S32(0X8003 << 16);
    // 0x8002488C: addiu       $at, $zero, 0xE00
    ctx->r1 = ADD32(0, 0XE00);
    // 0x80024890: beq         $v0, $at, L_800249EC
    if (ctx->r2 == ctx->r1) {
        // 0x80024894: lui         $t3, 0x8003
        ctx->r11 = S32(0X8003 << 16);
            goto L_800249EC;
    }
    // 0x80024894: lui         $t3, 0x8003
    ctx->r11 = S32(0X8003 << 16);
    // 0x80024898: addiu       $at, $zero, 0xF00
    ctx->r1 = ADD32(0, 0XF00);
    // 0x8002489C: beq         $v0, $at, L_800249F8
    if (ctx->r2 == ctx->r1) {
        // 0x800248A0: lui         $t4, 0x8003
        ctx->r12 = S32(0X8003 << 16);
            goto L_800249F8;
    }
    // 0x800248A0: lui         $t4, 0x8003
    ctx->r12 = S32(0X8003 << 16);
    // 0x800248A4: jr          $ra
    // 0x800248A8: nop

    TRACE_RETURN()
    return;
    // 0x800248A8: nop

L_800248AC:
    // 0x800248AC: slti        $at, $v0, 0x501
    ctx->r1 = SIGNED(ctx->r2) < 0X501 ? 1 : 0;
    // 0x800248B0: bne         $at, $zero, L_800248EC
    if (ctx->r1 != 0) {
        // 0x800248B4: addiu       $at, $zero, 0x600
        ctx->r1 = ADD32(0, 0X600);
            goto L_800248EC;
    }
    // 0x800248B4: addiu       $at, $zero, 0x600
    ctx->r1 = ADD32(0, 0X600);
    // 0x800248B8: beq         $v0, $at, L_80024934
    if (ctx->r2 == ctx->r1) {
        // 0x800248BC: lui         $t8, 0x8002
        ctx->r24 = S32(0X8002 << 16);
            goto L_80024934;
    }
    // 0x800248BC: lui         $t8, 0x8002
    ctx->r24 = S32(0X8002 << 16);
    // 0x800248C0: addiu       $at, $zero, 0x700
    ctx->r1 = ADD32(0, 0X700);
    // 0x800248C4: beq         $v0, $at, L_80024964
    if (ctx->r2 == ctx->r1) {
        // 0x800248C8: lui         $t2, 0x8003
        ctx->r10 = S32(0X8003 << 16);
            goto L_80024964;
    }
    // 0x800248C8: lui         $t2, 0x8003
    ctx->r10 = S32(0X8003 << 16);
    // 0x800248CC: addiu       $at, $zero, 0x800
    ctx->r1 = ADD32(0, 0X800);
    // 0x800248D0: beq         $v0, $at, L_80024970
    if (ctx->r2 == ctx->r1) {
        // 0x800248D4: lui         $t3, 0x8003
        ctx->r11 = S32(0X8003 << 16);
            goto L_80024970;
    }
    // 0x800248D4: lui         $t3, 0x8003
    ctx->r11 = S32(0X8003 << 16);
    // 0x800248D8: addiu       $at, $zero, 0x900
    ctx->r1 = ADD32(0, 0X900);
    // 0x800248DC: beq         $v0, $at, L_8002497C
    if (ctx->r2 == ctx->r1) {
        // 0x800248E0: lui         $t4, 0x8003
        ctx->r12 = S32(0X8003 << 16);
            goto L_8002497C;
    }
    // 0x800248E0: lui         $t4, 0x8003
    ctx->r12 = S32(0X8003 << 16);
    // 0x800248E4: jr          $ra
    // 0x800248E8: nop

    TRACE_RETURN()
    return;
    // 0x800248E8: nop

L_800248EC:
    // 0x800248EC: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x800248F0: beq         $v0, $at, L_80024940
    if (ctx->r2 == ctx->r1) {
        // 0x800248F4: lui         $t9, 0x8002
        ctx->r25 = S32(0X8002 << 16);
            goto L_80024940;
    }
    // 0x800248F4: lui         $t9, 0x8002
    ctx->r25 = S32(0X8002 << 16);
    // 0x800248F8: addiu       $at, $zero, 0x200
    ctx->r1 = ADD32(0, 0X200);
    // 0x800248FC: beq         $v0, $at, L_8002494C
    if (ctx->r2 == ctx->r1) {
        // 0x80024900: lui         $t0, 0x8003
        ctx->r8 = S32(0X8003 << 16);
            goto L_8002494C;
    }
    // 0x80024900: lui         $t0, 0x8003
    ctx->r8 = S32(0X8003 << 16);
    // 0x80024904: addiu       $at, $zero, 0x300
    ctx->r1 = ADD32(0, 0X300);
    // 0x80024908: beq         $v0, $at, L_80024958
    if (ctx->r2 == ctx->r1) {
        // 0x8002490C: lui         $t1, 0x8003
        ctx->r9 = S32(0X8003 << 16);
            goto L_80024958;
    }
    // 0x8002490C: lui         $t1, 0x8003
    ctx->r9 = S32(0X8003 << 16);
    // 0x80024910: addiu       $at, $zero, 0x400
    ctx->r1 = ADD32(0, 0X400);
    // 0x80024914: beq         $v0, $at, L_800249BC
    if (ctx->r2 == ctx->r1) {
        // 0x80024918: lui         $t9, 0x8003
        ctx->r25 = S32(0X8003 << 16);
            goto L_800249BC;
    }
    // 0x80024918: lui         $t9, 0x8003
    ctx->r25 = S32(0X8003 << 16);
    // 0x8002491C: addiu       $at, $zero, 0x500
    ctx->r1 = ADD32(0, 0X500);
    // 0x80024920: bne         $v0, $at, L_80024A00
    if (ctx->r2 != ctx->r1) {
        // 0x80024924: lui         $t7, 0x8002
        ctx->r15 = S32(0X8002 << 16);
            goto L_80024A00;
    }
    // 0x80024924: lui         $t7, 0x8002
    ctx->r15 = S32(0X8002 << 16);
    // 0x80024928: addiu       $t7, $t7, 0x55B0
    ctx->r15 = ADD32(ctx->r15, 0X55B0);
    // 0x8002492C: jr          $ra
    // 0x80024930: sw          $t7, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->r15;
    TRACE_RETURN()
    return;
    // 0x80024930: sw          $t7, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->r15;
L_80024934:
    // 0x80024934: addiu       $t8, $t8, 0x60F8
    ctx->r24 = ADD32(ctx->r24, 0X60F8);
    // 0x80024938: jr          $ra
    // 0x8002493C: sw          $t8, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->r24;
    TRACE_RETURN()
    return;
    // 0x8002493C: sw          $t8, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->r24;
L_80024940:
    // 0x80024940: addiu       $t9, $t9, 0x7478
    ctx->r25 = ADD32(ctx->r25, 0X7478);
    // 0x80024944: jr          $ra
    // 0x80024948: sw          $t9, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->r25;
    TRACE_RETURN()
    return;
    // 0x80024948: sw          $t9, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->r25;
L_8002494C:
    // 0x8002494C: addiu       $t0, $t0, -0x7D50
    ctx->r8 = ADD32(ctx->r8, -0X7D50);
    // 0x80024950: jr          $ra
    // 0x80024954: sw          $t0, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->r8;
    TRACE_RETURN()
    return;
    // 0x80024954: sw          $t0, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->r8;
L_80024958:
    // 0x80024958: addiu       $t1, $t1, -0x6314
    ctx->r9 = ADD32(ctx->r9, -0X6314);
    // 0x8002495C: jr          $ra
    // 0x80024960: sw          $t1, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->r9;
    TRACE_RETURN()
    return;
    // 0x80024960: sw          $t1, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->r9;
L_80024964:
    // 0x80024964: addiu       $t2, $t2, 0x3DC
    ctx->r10 = ADD32(ctx->r10, 0X3DC);
    // 0x80024968: jr          $ra
    // 0x8002496C: sw          $t2, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->r10;
    TRACE_RETURN()
    return;
    // 0x8002496C: sw          $t2, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->r10;
L_80024970:
    // 0x80024970: addiu       $t3, $t3, 0x3DC
    ctx->r11 = ADD32(ctx->r11, 0X3DC);
    // 0x80024974: jr          $ra
    // 0x80024978: sw          $t3, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->r11;
    TRACE_RETURN()
    return;
    // 0x80024978: sw          $t3, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->r11;
L_8002497C:
    // 0x8002497C: addiu       $t4, $t4, 0x2F4C
    ctx->r12 = ADD32(ctx->r12, 0X2F4C);
    // 0x80024980: jr          $ra
    // 0x80024984: sw          $t4, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->r12;
    TRACE_RETURN()
    return;
    // 0x80024984: sw          $t4, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->r12;
L_80024988:
    // 0x80024988: addiu       $t5, $t5, 0x3FAC
    ctx->r13 = ADD32(ctx->r13, 0X3FAC);
    // 0x8002498C: jr          $ra
    // 0x80024990: sw          $t5, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->r13;
    TRACE_RETURN()
    return;
    // 0x80024990: sw          $t5, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->r13;
L_80024994:
    // 0x80024994: lui         $t6, 0x8003
    ctx->r14 = S32(0X8003 << 16);
    // 0x80024998: addiu       $t6, $t6, 0x1598
    ctx->r14 = ADD32(ctx->r14, 0X1598);
    // 0x8002499C: jr          $ra
    // 0x800249A0: sw          $t6, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->r14;
    TRACE_RETURN()
    return;
    // 0x800249A0: sw          $t6, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->r14;
L_800249A4:
    // 0x800249A4: addiu       $t7, $t7, -0x174C
    ctx->r15 = ADD32(ctx->r15, -0X174C);
    // 0x800249A8: jr          $ra
    // 0x800249AC: sw          $t7, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->r15;
    TRACE_RETURN()
    return;
    // 0x800249AC: sw          $t7, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->r15;
L_800249B0:
    // 0x800249B0: addiu       $t8, $t8, -0xC50
    ctx->r24 = ADD32(ctx->r24, -0XC50);
    // 0x800249B4: jr          $ra
    // 0x800249B8: sw          $t8, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->r24;
    TRACE_RETURN()
    return;
    // 0x800249B8: sw          $t8, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->r24;
L_800249BC:
    // 0x800249BC: addiu       $t9, $t9, -0x50B0
    ctx->r25 = ADD32(ctx->r25, -0X50B0);
    // 0x800249C0: jr          $ra
    // 0x800249C4: sw          $t9, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->r25;
    TRACE_RETURN()
    return;
    // 0x800249C4: sw          $t9, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->r25;
L_800249C8:
    // 0x800249C8: addiu       $t0, $t0, -0x4064
    ctx->r8 = ADD32(ctx->r8, -0X4064);
    // 0x800249CC: jr          $ra
    // 0x800249D0: sw          $t0, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->r8;
    TRACE_RETURN()
    return;
    // 0x800249D0: sw          $t0, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->r8;
L_800249D4:
    // 0x800249D4: addiu       $t1, $t1, -0x3298
    ctx->r9 = ADD32(ctx->r9, -0X3298);
    // 0x800249D8: jr          $ra
    // 0x800249DC: sw          $t1, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->r9;
    TRACE_RETURN()
    return;
    // 0x800249DC: sw          $t1, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->r9;
L_800249E0:
    // 0x800249E0: addiu       $t2, $t2, -0x1C18
    ctx->r10 = ADD32(ctx->r10, -0X1C18);
    // 0x800249E4: jr          $ra
    // 0x800249E8: sw          $t2, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->r10;
    TRACE_RETURN()
    return;
    // 0x800249E8: sw          $t2, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->r10;
L_800249EC:
    // 0x800249EC: addiu       $t3, $t3, 0x2554
    ctx->r11 = ADD32(ctx->r11, 0X2554);
    // 0x800249F0: jr          $ra
    // 0x800249F4: sw          $t3, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->r11;
    TRACE_RETURN()
    return;
    // 0x800249F4: sw          $t3, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->r11;
L_800249F8:
    // 0x800249F8: addiu       $t4, $t4, 0x2D9C
    ctx->r12 = ADD32(ctx->r12, 0X2D9C);
    // 0x800249FC: sw          $t4, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->r12;
L_80024A00:
    // 0x80024A00: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80024A08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80024A08: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80024A0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80024A10: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x80024A14: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
    // 0x80024A18: sll         $a3, $a0, 16
    ctx->r7 = S32(ctx->r4 << 16);
    // 0x80024A1C: sra         $t6, $a3, 16
    ctx->r14 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80024A20: beq         $t7, $zero, L_80024C38
    if (ctx->r15 == 0) {
        // 0x80024A24: or          $a3, $t6, $zero
        ctx->r7 = ctx->r14 | 0;
            goto L_80024C38;
    }
    // 0x80024A24: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x80024A28: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80024A2C: lh          $v1, 0x0($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X0);
L_80024A30:
    // 0x80024A30: bnel        $a3, $v1, L_80024C2C
    if (ctx->r7 != ctx->r3) {
        // 0x80024A34: lh          $v1, 0xC($v0)
        ctx->r3 = MEM_H(ctx->r2, 0XC);
            goto L_80024C2C;
    }
    goto skip_0;
    // 0x80024A34: lh          $v1, 0xC($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XC);
    skip_0:
    // 0x80024A38: lh          $t8, 0x8($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X8);
    // 0x80024A3C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80024A40: beq         $t8, $zero, L_80024C20
    if (ctx->r24 == 0) {
        // 0x80024A44: nop
    
            goto L_80024C20;
    }
    // 0x80024A44: nop

    // 0x80024A48: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x80024A4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80024A50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80024A54: lh          $t9, 0x0($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X0);
    // 0x80024A58: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x80024A5C: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80024A60: beq         $t9, $zero, L_80024AA8
    if (ctx->r25 == 0) {
        // 0x80024A64: nop
    
            goto L_80024AA8;
    }
    // 0x80024A64: nop

    // 0x80024A68: lh          $t2, 0x8($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X8);
L_80024A6C:
    // 0x80024A6C: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x80024A70: addu        $v0, $a2, $t3
    ctx->r2 = ADD32(ctx->r6, ctx->r11);
    // 0x80024A74: beql        $t2, $zero, L_80024A98
    if (ctx->r10 == 0) {
        // 0x80024A78: lh          $t7, 0xA($v1)
        ctx->r15 = MEM_H(ctx->r3, 0XA);
            goto L_80024A98;
    }
    goto skip_1;
    // 0x80024A78: lh          $t7, 0xA($v1)
    ctx->r15 = MEM_H(ctx->r3, 0XA);
    skip_1:
    // 0x80024A7C: lh          $t4, 0x0($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X0);
    // 0x80024A80: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80024A84: sll         $t5, $a1, 16
    ctx->r13 = S32(ctx->r5 << 16);
    // 0x80024A88: sh          $a0, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r4;
    // 0x80024A8C: sra         $a1, $t5, 16
    ctx->r5 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80024A90: sh          $t4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r12;
    // 0x80024A94: lh          $t7, 0xA($v1)
    ctx->r15 = MEM_H(ctx->r3, 0XA);
L_80024A98:
    // 0x80024A98: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80024A9C: addiu       $v1, $v1, 0xA
    ctx->r3 = ADD32(ctx->r3, 0XA);
    // 0x80024AA0: bnel        $t7, $zero, L_80024A6C
    if (ctx->r15 != 0) {
        // 0x80024AA4: lh          $t2, 0x8($v1)
        ctx->r10 = MEM_H(ctx->r3, 0X8);
            goto L_80024A6C;
    }
    goto skip_2;
    // 0x80024AA4: lh          $t2, 0x8($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X8);
    skip_2:
L_80024AA8:
    // 0x80024AA8: bne         $a1, $at, L_80024AB8
    if (ctx->r5 != ctx->r1) {
        // 0x80024AAC: addiu       $a2, $sp, 0x2C
        ctx->r6 = ADD32(ctx->r29, 0X2C);
            goto L_80024AB8;
    }
    // 0x80024AAC: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x80024AB0: b           L_80024B08
    // 0x80024AB4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80024B08;
    // 0x80024AB4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80024AB8:
    // 0x80024AB8: sh          $a1, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r5;
    // 0x80024ABC: sh          $a3, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = ctx->r7;
    // 0x80024AC0: jal         0x8000E35C
    // 0x80024AC4: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    func_8000E35C(rdram, ctx);
        goto after_0;
    // 0x80024AC4: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    after_0:
    // 0x80024AC8: lh          $a1, 0x2A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2A);
    // 0x80024ACC: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x80024AD0: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x80024AD4: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x80024AD8: mfhi        $a0
    ctx->r4 = hi;
    // 0x80024ADC: lh          $a3, 0x8A($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X8A);
    // 0x80024AE0: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x80024AE4: bne         $a1, $zero, L_80024AF0
    if (ctx->r5 != 0) {
        // 0x80024AE8: nop
    
            goto L_80024AF0;
    }
    // 0x80024AE8: nop

    // 0x80024AEC: break       7
    do_break(2147633900);
L_80024AF0:
    // 0x80024AF0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80024AF4: bne         $a1, $at, L_80024B08
    if (ctx->r5 != ctx->r1) {
        // 0x80024AF8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80024B08;
    }
    // 0x80024AF8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80024AFC: bne         $t8, $at, L_80024B08
    if (ctx->r24 != ctx->r1) {
        // 0x80024B00: nop
    
            goto L_80024B08;
    }
    // 0x80024B00: nop

    // 0x80024B04: break       6
    do_break(2147633924);
L_80024B08:
    // 0x80024B08: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80024B0C: lw          $t2, -0x6BE0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X6BE0);
    // 0x80024B10: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x80024B14: addu        $v1, $a2, $t9
    ctx->r3 = ADD32(ctx->r6, ctx->r25);
    // 0x80024B18: andi        $t3, $t2, 0x200
    ctx->r11 = ctx->r10 & 0X200;
    // 0x80024B1C: bne         $t3, $zero, L_80024B90
    if (ctx->r11 != 0) {
        // 0x80024B20: lh          $t1, 0x0($v1)
        ctx->r9 = MEM_H(ctx->r3, 0X0);
            goto L_80024B90;
    }
    // 0x80024B20: lh          $t1, 0x0($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X0);
    // 0x80024B24: lh          $t4, 0x2($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X2);
L_80024B28:
    // 0x80024B28: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80024B2C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80024B30: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80024B34: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x80024B38: addu        $v0, $t0, $t5
    ctx->r2 = ADD32(ctx->r8, ctx->r13);
    // 0x80024B3C: lh          $t6, 0x8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X8);
    // 0x80024B40: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80024B44: sh          $t7, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r15;
    // 0x80024B48: lw          $a1, -0x6710($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6710);
    // 0x80024B4C: lh          $t8, 0x0($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X0);
    // 0x80024B50: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80024B54: beq         $t8, $zero, L_80024BA8
    if (ctx->r24 == 0) {
        // 0x80024B58: nop
    
            goto L_80024BA8;
    }
    // 0x80024B58: nop

    // 0x80024B5C: lh          $v1, 0x0($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X0);
L_80024B60:
    // 0x80024B60: bnel        $a3, $v1, L_80024B7C
    if (ctx->r7 != ctx->r3) {
        // 0x80024B64: lh          $v1, 0xC($v0)
        ctx->r3 = MEM_H(ctx->r2, 0XC);
            goto L_80024B7C;
    }
    goto skip_3;
    // 0x80024B64: lh          $v1, 0xC($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XC);
    skip_3:
    // 0x80024B68: lh          $t9, 0x8($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X8);
    // 0x80024B6C: addiu       $t2, $t9, -0x1
    ctx->r10 = ADD32(ctx->r25, -0X1);
    // 0x80024B70: b           L_80024BA8
    // 0x80024B74: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
        goto L_80024BA8;
    // 0x80024B74: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x80024B78: lh          $v1, 0xC($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XC);
L_80024B7C:
    // 0x80024B7C: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x80024B80: bne         $v1, $zero, L_80024B60
    if (ctx->r3 != 0) {
        // 0x80024B84: nop
    
            goto L_80024B60;
    }
    // 0x80024B84: nop

    // 0x80024B88: b           L_80024BA8
    // 0x80024B8C: nop

        goto L_80024BA8;
    // 0x80024B8C: nop

L_80024B90:
    // 0x80024B90: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80024B94: beql        $t1, $at, L_80024B28
    if (ctx->r9 == ctx->r1) {
        // 0x80024B98: lh          $t4, 0x2($v1)
        ctx->r12 = MEM_H(ctx->r3, 0X2);
            goto L_80024B28;
    }
    goto skip_4;
    // 0x80024B98: lh          $t4, 0x2($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X2);
    skip_4:
    // 0x80024B9C: addiu       $at, $zero, 0xA01
    ctx->r1 = ADD32(0, 0XA01);
    // 0x80024BA0: beql        $t1, $at, L_80024B28
    if (ctx->r9 == ctx->r1) {
        // 0x80024BA4: lh          $t4, 0x2($v1)
        ctx->r12 = MEM_H(ctx->r3, 0X2);
            goto L_80024B28;
    }
    goto skip_5;
    // 0x80024BA4: lh          $t4, 0x2($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X2);
    skip_5:
L_80024BA8:
    // 0x80024BA8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80024BAC: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80024BB0: addiu       $a1, $zero, 0x144
    ctx->r5 = ADD32(0, 0X144);
    // 0x80024BB4: jal         0x80004364
    // 0x80024BB8: sh          $t1, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r9;
    func_80004364(rdram, ctx);
        goto after_1;
    // 0x80024BB8: sh          $t1, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r9;
    after_1:
    // 0x80024BBC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80024BC0: addiu       $a1, $zero, 0x144
    ctx->r5 = ADD32(0, 0X144);
    // 0x80024BC4: jal         0x8000C7C0
    // 0x80024BC8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8000C7C0(rdram, ctx);
        goto after_2;
    // 0x80024BC8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_2:
    // 0x80024BCC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80024BD0: lh          $t1, 0x28($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X28);
    // 0x80024BD4: jal         0x80024818
    // 0x80024BD8: sh          $t1, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r9;
    func_80024818(rdram, ctx);
        goto after_3;
    // 0x80024BD8: sh          $t1, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r9;
    after_3:
    // 0x80024BDC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80024BE0: addiu       $v0, $v0, -0x6808
    ctx->r2 = ADD32(ctx->r2, -0X6808);
    // 0x80024BE4: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80024BE8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80024BEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80024BF0: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x80024BF4: sw          $a0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r4;
    // 0x80024BF8: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80024BFC: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x80024C00: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x80024C04: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80024C08: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80024C0C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80024C10: jal         0x80035A7C
    // 0x80024C14: sw          $a0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r4;
    func_80035A7C(rdram, ctx);
        goto after_4;
    // 0x80024C14: sw          $a0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r4;
    after_4:
    // 0x80024C18: b           L_80024C3C
    // 0x80024C1C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
        goto L_80024C3C;
    // 0x80024C1C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_80024C20:
    // 0x80024C20: b           L_80024C3C
    // 0x80024C24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80024C3C;
    // 0x80024C24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80024C28: lh          $v1, 0xC($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XC);
L_80024C2C:
    // 0x80024C2C: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x80024C30: bne         $v1, $zero, L_80024A30
    if (ctx->r3 != 0) {
        // 0x80024C34: nop
    
            goto L_80024A30;
    }
    // 0x80024C34: nop

L_80024C38:
    // 0x80024C38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80024C3C:
    // 0x80024C3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80024C40: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x80024C44: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80024C4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80024C4C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80024C50: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x80024C54: lh          $t6, 0x2584($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X2584);
    // 0x80024C58: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80024C5C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80024C60: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80024C64: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80024C68: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80024C6C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80024C70: beq         $t6, $zero, L_80024DA8
    if (ctx->r14 == 0) {
        // 0x80024C74: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_80024DA8;
    }
    // 0x80024C74: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80024C78: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80024C7C: addiu       $a0, $a0, 0x2584
    ctx->r4 = ADD32(ctx->r4, 0X2584);
    // 0x80024C80: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
L_80024C84:
    // 0x80024C84: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x80024C88: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x80024C8C: beql        $t7, $zero, L_80024D9C
    if (ctx->r15 == 0) {
        // 0x80024C90: lh          $t2, 0x8($a0)
        ctx->r10 = MEM_H(ctx->r4, 0X8);
            goto L_80024D9C;
    }
    goto skip_0;
    // 0x80024C90: lh          $t2, 0x8($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X8);
    skip_0:
    // 0x80024C94: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80024C98: lwl         $t8, 0x2($s0)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r16, 0X2);
L_80024C9C:
    // 0x80024C9C: lwr         $t8, 0x5($s0)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r16, 0X5);
    // 0x80024CA0: bnel        $v0, $t8, L_80024D8C
    if (ctx->r2 != ctx->r24) {
        // 0x80024CA4: lh          $t1, 0x38($s0)
        ctx->r9 = MEM_H(ctx->r16, 0X38);
            goto L_80024D8C;
    }
    goto skip_1;
    // 0x80024CA4: lh          $t1, 0x38($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X38);
    skip_1:
    // 0x80024CA8: lwl         $t0, 0x6($s0)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r16, 0X6);
    // 0x80024CAC: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x80024CB0: lwr         $t0, 0x9($s0)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r16, 0X9);
    // 0x80024CB4: bnel        $t9, $t0, L_80024D8C
    if (ctx->r25 != ctx->r8) {
        // 0x80024CB8: lh          $t1, 0x38($s0)
        ctx->r9 = MEM_H(ctx->r16, 0X38);
            goto L_80024D8C;
    }
    goto skip_2;
    // 0x80024CB8: lh          $t1, 0x38($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X38);
    skip_2:
    // 0x80024CBC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80024CC0: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80024CC4: addiu       $a1, $zero, 0x144
    ctx->r5 = ADD32(0, 0X144);
    // 0x80024CC8: jal         0x80004364
    // 0x80024CCC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x80024CCC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    after_0:
    // 0x80024CD0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80024CD4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80024CD8: jal         0x8000C7C0
    // 0x80024CDC: addiu       $a1, $zero, 0x144
    ctx->r5 = ADD32(0, 0X144);
    func_8000C7C0(rdram, ctx);
        goto after_1;
    // 0x80024CDC: addiu       $a1, $zero, 0x144
    ctx->r5 = ADD32(0, 0X144);
    after_1:
    // 0x80024CE0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80024CE4: addiu       $v0, $v0, -0x6808
    ctx->r2 = ADD32(ctx->r2, -0X6808);
    // 0x80024CE8: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x80024CEC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80024CF0: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80024CF4: sw          $s2, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r18;
    // 0x80024CF8: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80024CFC: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x80024D00: sw          $t4, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r12;
    // 0x80024D04: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80024D08: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x80024D0C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80024D10: sw          $s2, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r18;
    // 0x80024D14: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x80024D18: jal         0x80024818
    // 0x80024D1C: sh          $t7, 0x94($s2)
    MEM_H(0X94, ctx->r18) = ctx->r15;
    func_80024818(rdram, ctx);
        goto after_2;
    // 0x80024D1C: sh          $t7, 0x94($s2)
    MEM_H(0X94, ctx->r18) = ctx->r15;
    after_2:
    // 0x80024D20: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x80024D24: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x80024D28: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
L_80024D2C:
    // 0x80024D2C: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80024D30: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80024D34: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80024D38: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80024D3C: lwc1        $f6, 0x18($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80024D40: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80024D44: bne         $s3, $a0, L_80024D2C
    if (ctx->r19 != ctx->r4) {
        // 0x80024D48: swc1        $f6, 0x10($v0)
        MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
            goto L_80024D2C;
    }
    // 0x80024D48: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    // 0x80024D4C: addiu       $t8, $zero, -0x9
    ctx->r24 = ADD32(0, -0X9);
    // 0x80024D50: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80024D54: sh          $t8, 0x96($s2)
    MEM_H(0X96, ctx->r18) = ctx->r24;
    // 0x80024D58: sh          $t9, 0x98($s2)
    MEM_H(0X98, ctx->r18) = ctx->r25;
    // 0x80024D5C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80024D60: jal         0x80035A7C
    // 0x80024D64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80035A7C(rdram, ctx);
        goto after_3;
    // 0x80024D64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80024D68: sh          $zero, 0x96($s2)
    MEM_H(0X96, ctx->r18) = 0;
    // 0x80024D6C: sh          $zero, 0x98($s2)
    MEM_H(0X98, ctx->r18) = 0;
    // 0x80024D70: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80024D74: jal         0x80035A7C
    // 0x80024D78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80035A7C(rdram, ctx);
        goto after_4;
    // 0x80024D78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80024D7C: lh          $t0, 0x2E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X2E);
    // 0x80024D80: b           L_80024DA8
    // 0x80024D84: sh          $t0, 0xD8($s2)
    MEM_H(0XD8, ctx->r18) = ctx->r8;
        goto L_80024DA8;
    // 0x80024D84: sh          $t0, 0xD8($s2)
    MEM_H(0XD8, ctx->r18) = ctx->r8;
    // 0x80024D88: lh          $t1, 0x38($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X38);
L_80024D8C:
    // 0x80024D8C: addiu       $s0, $s0, 0x38
    ctx->r16 = ADD32(ctx->r16, 0X38);
    // 0x80024D90: bnel        $t1, $zero, L_80024C9C
    if (ctx->r9 != 0) {
        // 0x80024D94: lwl         $t8, 0x2($s0)
        ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r16, 0X2);
            goto L_80024C9C;
    }
    goto skip_3;
    // 0x80024D94: lwl         $t8, 0x2($s0)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r16, 0X2);
    skip_3:
    // 0x80024D98: lh          $t2, 0x8($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X8);
L_80024D9C:
    // 0x80024D9C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80024DA0: bnel        $t2, $zero, L_80024C84
    if (ctx->r10 != 0) {
        // 0x80024DA4: lw          $v1, 0x4($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X4);
            goto L_80024C84;
    }
    goto skip_4;
    // 0x80024DA4: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    skip_4:
L_80024DA8:
    // 0x80024DA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80024DAC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80024DB0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80024DB4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80024DB8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80024DBC: jr          $ra
    // 0x80024DC0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    TRACE_RETURN()
    return;
    // 0x80024DC0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80024DC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80024DC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80024DC8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80024DCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80024DD0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80024DD4: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80024DD8: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80024DDC: jal         0x80004364
    // 0x80024DE0: addiu       $a1, $zero, 0x144
    ctx->r5 = ADD32(0, 0X144);
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x80024DE0: addiu       $a1, $zero, 0x144
    ctx->r5 = ADD32(0, 0X144);
    after_0:
    // 0x80024DE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80024DE8: addiu       $a1, $zero, 0x144
    ctx->r5 = ADD32(0, 0X144);
    // 0x80024DEC: jal         0x8000C7C0
    // 0x80024DF0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8000C7C0(rdram, ctx);
        goto after_1;
    // 0x80024DF0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80024DF4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80024DF8: addiu       $v0, $v0, -0x6808
    ctx->r2 = ADD32(ctx->r2, -0X6808);
    // 0x80024DFC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80024E00: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80024E04: addiu       $t2, $zero, 0xF01
    ctx->r10 = ADD32(0, 0XF01);
    // 0x80024E08: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80024E0C: sw          $a0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r4;
    // 0x80024E10: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80024E14: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80024E18: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x80024E1C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80024E20: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x80024E24: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x80024E28: sw          $a0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r4;
    // 0x80024E2C: jal         0x80024818
    // 0x80024E30: sh          $t2, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r10;
    func_80024818(rdram, ctx);
        goto after_2;
    // 0x80024E30: sh          $t2, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r10;
    after_2:
    // 0x80024E34: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80024E38: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80024E3C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80024E40: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80024E44: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
L_80024E48:
    // 0x80024E48: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80024E4C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80024E50: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80024E54: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80024E58: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80024E5C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80024E60: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80024E64: bne         $v1, $a2, L_80024E48
    if (ctx->r3 != ctx->r6) {
        // 0x80024E68: swc1        $f6, 0x10($v0)
        MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
            goto L_80024E48;
    }
    // 0x80024E68: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    // 0x80024E6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80024E70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80024E74: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80024E7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80024E7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80024E80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80024E84: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80024E88: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80024E8C: jal         0x80004364
    // 0x80024E90: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x80024E90: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_0:
    // 0x80024E94: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80024E98: addiu       $v1, $v1, -0x6800
    ctx->r3 = ADD32(ctx->r3, -0X6800);
    // 0x80024E9C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80024EA0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80024EA4: jal         0x8000C7C0
    // 0x80024EA8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_8000C7C0(rdram, ctx);
        goto after_1;
    // 0x80024EA8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_1:
    // 0x80024EAC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80024EB0: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80024EB4: jal         0x80004364
    // 0x80024EB8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80004364(rdram, ctx);
        goto after_2;
    // 0x80024EB8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x80024EBC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80024EC0: addiu       $v1, $v1, -0x67F8
    ctx->r3 = ADD32(ctx->r3, -0X67F8);
    // 0x80024EC4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80024EC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80024ECC: jal         0x8000C7C0
    // 0x80024ED0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_8000C7C0(rdram, ctx);
        goto after_3;
    // 0x80024ED0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_3:
    // 0x80024ED4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80024ED8: addiu       $v0, $v0, -0x6800
    ctx->r2 = ADD32(ctx->r2, -0X6800);
    // 0x80024EDC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80024EE0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80024EE4: addiu       $v1, $v1, -0x67F8
    ctx->r3 = ADD32(ctx->r3, -0X67F8);
    // 0x80024EE8: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x80024EEC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80024EF0: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x80024EF4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80024EF8: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80024EFC: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80024F00: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x80024F04: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80024F08: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x80024F0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80024F10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80024F14: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80024F1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80024F1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80024F20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80024F24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80024F28: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80024F2C: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80024F30: jal         0x80004364
    // 0x80024F34: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x80024F34: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_0:
    // 0x80024F38: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80024F3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80024F40: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80024F44: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
L_80024F48:
    // 0x80024F48: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80024F4C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80024F50: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80024F54: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80024F58: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80024F5C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80024F60: bne         $v1, $a2, L_80024F48
    if (ctx->r3 != ctx->r6) {
        // 0x80024F64: sh          $t7, 0x6($a1)
        MEM_H(0X6, ctx->r5) = ctx->r15;
            goto L_80024F48;
    }
    // 0x80024F64: sh          $t7, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r15;
    // 0x80024F68: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80024F6C: addiu       $v1, $v1, -0x67F8
    ctx->r3 = ADD32(ctx->r3, -0X67F8);
    // 0x80024F70: sh          $zero, 0xE($v0)
    MEM_H(0XE, ctx->r2) = 0;
    // 0x80024F74: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80024F78: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80024F7C: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x80024F80: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80024F84: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x80024F88: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80024F8C: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80024F90: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80024F94: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x80024F98: sw          $v0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r2;
    // 0x80024F9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80024FA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80024FA4: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80024FAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80024FAC: jr          $ra
    // 0x80024FB0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    TRACE_RETURN()
    return;
    // 0x80024FB0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80024FB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80024FB4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80024FB8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80024FBC: lw          $a1, -0x6800($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6800);
    // 0x80024FC0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80024FC4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80024FC8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80024FCC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80024FD0: lw          $s0, 0x0($a1)
    ctx->r16 = MEM_W(ctx->r5, 0X0);
    // 0x80024FD4: lui         $s2, 0x801A
    ctx->r18 = S32(0X801A << 16);
    // 0x80024FD8: addiu       $s2, $s2, 0x2800
    ctx->r18 = ADD32(ctx->r18, 0X2800);
    // 0x80024FDC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80024FE0: beq         $t6, $zero, L_80025024
    if (ctx->r14 == 0) {
        // 0x80024FE4: nop
    
            goto L_80025024;
    }
    // 0x80024FE4: nop

    // 0x80024FE8: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
L_80024FEC:
    // 0x80024FEC: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x80024FF0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80024FF4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80024FF8: sw          $s1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r17;
    // 0x80024FFC: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80025000: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x80025004: jal         0x800042A8
    // 0x80025008: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    func_800042A8(rdram, ctx);
        goto after_0;
    // 0x80025008: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    after_0:
    // 0x8002500C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80025010: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80025014: bnel        $t0, $zero, L_80024FEC
    if (ctx->r8 != 0) {
        // 0x80025018: lw          $s1, 0x0($s0)
        ctx->r17 = MEM_W(ctx->r16, 0X0);
            goto L_80024FEC;
    }
    goto skip_0;
    // 0x80025018: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x8002501C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80025020: lw          $a1, -0x6800($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6800);
L_80025024:
    // 0x80025024: lui         $s2, 0x801A
    ctx->r18 = S32(0X801A << 16);
    // 0x80025028: addiu       $s2, $s2, 0x2800
    ctx->r18 = ADD32(ctx->r18, 0X2800);
    // 0x8002502C: jal         0x800042A8
    // 0x80025030: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800042A8(rdram, ctx);
        goto after_1;
    // 0x80025030: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x80025034: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80025038: lw          $a1, -0x67F8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X67F8);
    // 0x8002503C: jal         0x800042A8
    // 0x80025040: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800042A8(rdram, ctx);
        goto after_2;
    // 0x80025040: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x80025044: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80025048: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002504C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80025050: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80025054: jr          $ra
    // 0x80025058: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    TRACE_RETURN()
    return;
    // 0x80025058: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8002505C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8002505C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80025060: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80025064: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80025068: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002506C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80025070: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80025074: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80025078: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
L_8002507C:
    // 0x8002507C: jal         0x8000E35C
    // 0x80025080: nop

    func_8000E35C(rdram, ctx);
        goto after_0;
    // 0x80025080: nop

    after_0:
    // 0x80025084: andi        $t6, $v0, 0x3FF
    ctx->r14 = ctx->r2 & 0X3FF;
    // 0x80025088: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8002508C: nop

    // 0x80025090: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80025094: jal         0x8000E35C
    // 0x80025098: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    func_8000E35C(rdram, ctx);
        goto after_1;
    // 0x80025098: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    after_1:
    // 0x8002509C: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x800250A0: beq         $t7, $zero, L_800250B4
    if (ctx->r15 == 0) {
        // 0x800250A4: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800250B4;
    }
    // 0x800250A4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800250A8: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800250AC: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800250B0: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
L_800250B4:
    // 0x800250B4: bne         $s1, $s2, L_8002507C
    if (ctx->r17 != ctx->r18) {
        // 0x800250B8: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8002507C;
    }
    // 0x800250B8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800250BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800250C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800250C4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800250C8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800250CC: jr          $ra
    // 0x800250D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    TRACE_RETURN()
    return;
    // 0x800250D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800250D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800250D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800250D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800250DC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800250E0: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x800250E4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800250E8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800250EC: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x800250F0: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x800250F4: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x800250F8: lw          $a1, 0x8C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X8C);
    // 0x800250FC: beq         $a1, $zero, L_80025110
    if (ctx->r5 == 0) {
        // 0x80025100: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80025110;
    }
    // 0x80025100: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80025104: jal         0x8004A0C4
    // 0x80025108: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_8004A0C4(rdram, ctx);
        goto after_0;
    // 0x80025108: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8002510C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_80025110:
    // 0x80025110: lh          $t0, 0x2C($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X2C);
    // 0x80025114: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80025118: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8002511C: beql        $t0, $zero, L_80025138
    if (ctx->r8 == 0) {
        // 0x80025120: lw          $a1, 0x78($a2)
        ctx->r5 = MEM_W(ctx->r6, 0X78);
            goto L_80025138;
    }
    goto skip_0;
    // 0x80025120: lw          $a1, 0x78($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X78);
    skip_0:
    // 0x80025124: lw          $a1, 0x28($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X28);
    // 0x80025128: jal         0x800042A8
    // 0x8002512C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800042A8(rdram, ctx);
        goto after_1;
    // 0x8002512C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x80025130: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80025134: lw          $a1, 0x78($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X78);
L_80025138:
    // 0x80025138: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8002513C: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80025140: beq         $a1, $zero, L_80025154
    if (ctx->r5 == 0) {
        // 0x80025144: nop
    
            goto L_80025154;
    }
    // 0x80025144: nop

    // 0x80025148: jal         0x800042A8
    // 0x8002514C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800042A8(rdram, ctx);
        goto after_2;
    // 0x8002514C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_2:
    // 0x80025150: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_80025154:
    // 0x80025154: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80025158: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8002515C: jal         0x800042A8
    // 0x80025160: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800042A8(rdram, ctx);
        goto after_3;
    // 0x80025160: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_3:
    // 0x80025164: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80025168: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002516C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80025174(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80025174: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80025178: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8002517C: lw          $t7, -0x6810($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6810);
    // 0x80025180: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80025184: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80025188: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8002518C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80025190: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80025194: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80025198: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8002519C: lw          $s0, 0x0($t7)
    ctx->r16 = MEM_W(ctx->r15, 0X0);
    // 0x800251A0: sll         $s2, $a2, 16
    ctx->r18 = S32(ctx->r6 << 16);
    // 0x800251A4: sra         $t6, $s2, 16
    ctx->r14 = S32(SIGNED(ctx->r18) >> 16);
    // 0x800251A8: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800251AC: or          $s2, $t6, $zero
    ctx->r18 = ctx->r14 | 0;
    // 0x800251B0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800251B4: beq         $t8, $zero, L_80025230
    if (ctx->r24 == 0) {
        // 0x800251B8: or          $s3, $a1, $zero
        ctx->r19 = ctx->r5 | 0;
            goto L_80025230;
    }
    // 0x800251B8: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
L_800251BC:
    // 0x800251BC: beql        $s0, $s1, L_80025224
    if (ctx->r16 == ctx->r17) {
        // 0x800251C0: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80025224;
    }
    goto skip_0;
    // 0x800251C0: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x800251C4: lh          $t9, 0x98($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X98);
    // 0x800251C8: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x800251CC: beql        $t0, $zero, L_80025224
    if (ctx->r8 == 0) {
        // 0x800251D0: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80025224;
    }
    goto skip_1;
    // 0x800251D0: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x800251D4: lh          $t1, 0x94($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X94);
    // 0x800251D8: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x800251DC: andi        $t2, $t1, 0xFF00
    ctx->r10 = ctx->r9 & 0XFF00;
    // 0x800251E0: beql        $s2, $t2, L_80025224
    if (ctx->r18 == ctx->r10) {
        // 0x800251E4: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80025224;
    }
    goto skip_2;
    // 0x800251E4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x800251E8: jal         0x80003668
    // 0x800251EC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_80003668(rdram, ctx);
        goto after_0;
    // 0x800251EC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_0:
    // 0x800251F0: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800251F4: lw          $t5, 0x28($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X28);
    // 0x800251F8: lw          $t7, 0x28($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X28);
    // 0x800251FC: lh          $t6, 0x14($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X14);
    // 0x80025200: lh          $t8, 0x14($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X14);
    // 0x80025204: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x80025208: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8002520C: slt         $at, $t4, $t9
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80025210: beq         $at, $zero, L_80025220
    if (ctx->r1 == 0) {
        // 0x80025214: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80025220;
    }
    // 0x80025214: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80025218: b           L_80025230
    // 0x8002521C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
        goto L_80025230;
    // 0x8002521C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
L_80025220:
    // 0x80025220: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_80025224:
    // 0x80025224: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80025228: bne         $t1, $zero, L_800251BC
    if (ctx->r9 != 0) {
        // 0x8002522C: nop
    
            goto L_800251BC;
    }
    // 0x8002522C: nop

L_80025230:
    // 0x80025230: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80025234: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80025238: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8002523C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80025240: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80025244: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80025248: jr          $ra
    // 0x8002524C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    TRACE_RETURN()
    return;
    // 0x8002524C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80025250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80025250: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80025254: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80025258: lw          $t6, -0x65A0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X65A0);
    // 0x8002525C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80025260: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80025264: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80025268: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8002526C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80025270: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80025274: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80025278: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8002527C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80025280: lw          $s1, 0x0($t6)
    ctx->r17 = MEM_W(ctx->r14, 0X0);
    // 0x80025284: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x80025288: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x8002528C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80025290: addiu       $s2, $zero, 0x6
    ctx->r18 = ADD32(0, 0X6);
    // 0x80025294: addiu       $s3, $sp, 0x60
    ctx->r19 = ADD32(ctx->r29, 0X60);
    // 0x80025298: beq         $v1, $zero, L_800253F4
    if (ctx->r3 == 0) {
        // 0x8002529C: addiu       $s5, $sp, 0x54
        ctx->r21 = ADD32(ctx->r29, 0X54);
            goto L_800253F4;
    }
    // 0x8002529C: addiu       $s5, $sp, 0x54
    ctx->r21 = ADD32(ctx->r29, 0X54);
    // 0x800252A0: lh          $t7, 0x36($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X36);
L_800252A4:
    // 0x800252A4: blezl       $t7, L_800253E8
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800252A8: or          $s1, $v1, $zero
        ctx->r17 = ctx->r3 | 0;
            goto L_800253E8;
    }
    goto skip_0;
    // 0x800252A8: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    skip_0:
    // 0x800252AC: lh          $v0, 0x34($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X34);
    // 0x800252B0: beql        $v0, $zero, L_800253E8
    if (ctx->r2 == 0) {
        // 0x800252B4: or          $s1, $v1, $zero
        ctx->r17 = ctx->r3 | 0;
            goto L_800253E8;
    }
    goto skip_1;
    // 0x800252B4: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    skip_1:
    // 0x800252B8: blez        $v0, L_800253E4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800252BC: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800253E4;
    }
    // 0x800252BC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800252C0: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800252C4: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
L_800252C8:
    // 0x800252C8: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x800252CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800252D0: addiu       $v0, $sp, 0x54
    ctx->r2 = ADD32(ctx->r29, 0X54);
    // 0x800252D4: bne         $t8, $zero, L_80025374
    if (ctx->r24 != 0) {
        // 0x800252D8: or          $v1, $s1, $zero
        ctx->r3 = ctx->r17 | 0;
            goto L_80025374;
    }
    // 0x800252D8: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x800252DC: addiu       $v0, $sp, 0x54
    ctx->r2 = ADD32(ctx->r29, 0X54);
    // 0x800252E0: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x800252E4: lw          $t9, 0x30($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X30);
    // 0x800252E8: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x800252EC: subu        $t0, $t0, $s0
    ctx->r8 = SUB32(ctx->r8, ctx->r16);
    // 0x800252F0: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x800252F4: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800252F8: addiu       $s2, $s2, -0x2
    ctx->r18 = ADD32(ctx->r18, -0X2);
    // 0x800252FC: addu        $t2, $t1, $a0
    ctx->r10 = ADD32(ctx->r9, ctx->r4);
    // 0x80025300: beq         $a0, $s2, L_80025348
    if (ctx->r4 == ctx->r18) {
        // 0x80025304: lh          $t3, 0x2($t2)
        ctx->r11 = MEM_H(ctx->r10, 0X2);
            goto L_80025348;
    }
    // 0x80025304: lh          $t3, 0x2($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X2);
L_80025308:
    // 0x80025308: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x8002530C: lwc1        $f16, 0x10($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80025310: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x80025314: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80025318: subu        $t0, $t0, $s0
    ctx->r8 = SUB32(ctx->r8, ctx->r16);
    // 0x8002531C: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80025320: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80025324: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80025328: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8002532C: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80025330: swc1        $f16, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
    // 0x80025334: lw          $t9, 0x30($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X30);
    // 0x80025338: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8002533C: addu        $t2, $t1, $a0
    ctx->r10 = ADD32(ctx->r9, ctx->r4);
    // 0x80025340: bne         $a0, $s2, L_80025308
    if (ctx->r4 != ctx->r18) {
        // 0x80025344: lh          $t3, 0x2($t2)
        ctx->r11 = MEM_H(ctx->r10, 0X2);
            goto L_80025308;
    }
    // 0x80025344: lh          $t3, 0x2($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X2);
L_80025348:
    // 0x80025348: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x8002534C: lwc1        $f16, 0x10($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80025350: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x80025354: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80025358: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8002535C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80025360: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80025364: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80025368: swc1        $f16, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
    // 0x8002536C: b           L_8002538C
    // 0x80025370: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
        goto L_8002538C;
    // 0x80025370: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
L_80025374:
    // 0x80025374: lwc1        $f16, 0x10($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80025378: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8002537C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80025380: bne         $v0, $s3, L_80025374
    if (ctx->r2 != ctx->r19) {
        // 0x80025384: swc1        $f16, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
            goto L_80025374;
    }
    // 0x80025384: swc1        $f16, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
    // 0x80025388: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
L_8002538C:
    // 0x8002538C: jal         0x80003668
    // 0x80025390: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_80003668(rdram, ctx);
        goto after_0;
    // 0x80025390: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_0:
    // 0x80025394: lw          $t4, 0x30($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X30);
    // 0x80025398: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002539C: lw          $t8, 0x28($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X28);
    // 0x800253A0: addu        $v0, $t4, $s4
    ctx->r2 = ADD32(ctx->r12, ctx->r20);
    // 0x800253A4: lh          $t7, 0x14($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X14);
    // 0x800253A8: lh          $t9, 0x14($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X14);
    // 0x800253AC: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800253B0: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x800253B4: slt         $at, $t6, $t0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800253B8: beql        $at, $zero, L_800253CC
    if (ctx->r1 == 0) {
        // 0x800253BC: lh          $t1, 0x34($s1)
        ctx->r9 = MEM_H(ctx->r17, 0X34);
            goto L_800253CC;
    }
    goto skip_2;
    // 0x800253BC: lh          $t1, 0x34($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X34);
    skip_2:
    // 0x800253C0: b           L_800253F8
    // 0x800253C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800253F8;
    // 0x800253C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800253C8: lh          $t1, 0x34($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X34);
L_800253CC:
    // 0x800253CC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800253D0: addiu       $s4, $s4, 0x18
    ctx->r20 = ADD32(ctx->r20, 0X18);
    // 0x800253D4: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800253D8: bne         $at, $zero, L_800252C8
    if (ctx->r1 != 0) {
        // 0x800253DC: addiu       $v0, $v0, 0x18
        ctx->r2 = ADD32(ctx->r2, 0X18);
            goto L_800252C8;
    }
    // 0x800253DC: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x800253E0: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
L_800253E4:
    // 0x800253E4: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
L_800253E8:
    // 0x800253E8: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800253EC: bnel        $v1, $zero, L_800252A4
    if (ctx->r3 != 0) {
        // 0x800253F0: lh          $t7, 0x36($s1)
        ctx->r15 = MEM_H(ctx->r17, 0X36);
            goto L_800252A4;
    }
    goto skip_3;
    // 0x800253F0: lh          $t7, 0x36($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X36);
    skip_3:
L_800253F4:
    // 0x800253F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800253F8:
    // 0x800253F8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800253FC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80025400: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80025404: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80025408: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8002540C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80025410: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80025414: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80025418: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8002541C: jr          $ra
    // 0x80025420: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    TRACE_RETURN()
    return;
    // 0x80025420: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80025424(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80025424: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80025428: sll         $a2, $a1, 16
    ctx->r6 = S32(ctx->r5 << 16);
    // 0x8002542C: sra         $t6, $a2, 16
    ctx->r14 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80025430: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80025434: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80025438: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8002543C: sh          $t6, 0x74($a0)
    MEM_H(0X74, ctx->r4) = ctx->r14;
    // 0x80025440: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80025444: sll         $a3, $t6, 4
    ctx->r7 = S32(ctx->r14 << 4);
    // 0x80025448: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8002544C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80025450: jal         0x80004364
    // 0x80025454: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x80025454: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    after_0:
    // 0x80025458: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8002545C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80025460: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80025464: jal         0x8000C7C0
    // 0x80025468: sw          $v0, 0x78($t8)
    MEM_W(0X78, ctx->r24) = ctx->r2;
    func_8000C7C0(rdram, ctx);
        goto after_1;
    // 0x80025468: sw          $v0, 0x78($t8)
    MEM_W(0X78, ctx->r24) = ctx->r2;
    after_1:
    // 0x8002546C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80025470: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80025474: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8002547C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8002547C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80025480: lh          $t2, 0x2A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X2A);
    // 0x80025484: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80025488: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8002548C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80025490: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80025494: sh          $a1, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r5;
    // 0x80025498: sh          $a1, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r5;
    // 0x8002549C: sh          $a2, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r6;
    // 0x800254A0: sh          $zero, 0xA($a0)
    MEM_H(0XA, ctx->r4) = 0;
    // 0x800254A4: sh          $a3, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r7;
    // 0x800254A8: sh          $t2, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r10;
    // 0x800254AC: jal         0x8000E35C
    // 0x800254B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8000E35C(rdram, ctx);
        goto after_0;
    // 0x800254B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800254B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800254B8: andi        $t3, $v0, 0x3F
    ctx->r11 = ctx->r2 & 0X3F;
    // 0x800254BC: sh          $t3, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r11;
    // 0x800254C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800254C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800254C8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800254D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800254D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800254D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800254D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800254DC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800254E0: lh          $v0, 0xE($a0)
    ctx->r2 = MEM_H(ctx->r4, 0XE);
    // 0x800254E4: sll         $t6, $a3, 16
    ctx->r14 = S32(ctx->r7 << 16);
    // 0x800254E8: sra         $a3, $t6, 16
    ctx->r7 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800254EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800254F0: beq         $v0, $zero, L_80025534
    if (ctx->r2 == 0) {
        // 0x800254F4: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80025534;
    }
    // 0x800254F4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800254F8: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x800254FC: sh          $t8, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r24;
    // 0x80025500: lh          $t9, 0xE($a0)
    ctx->r25 = MEM_H(ctx->r4, 0XE);
    // 0x80025504: bne         $t9, $zero, L_8002552C
    if (ctx->r25 != 0) {
        // 0x80025508: nop
    
            goto L_8002552C;
    }
    // 0x80025508: nop

    // 0x8002550C: lh          $t0, 0x2($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X2);
    // 0x80025510: bnel        $t0, $zero, L_80025524
    if (ctx->r8 != 0) {
        // 0x80025514: lh          $t1, 0x4($s0)
        ctx->r9 = MEM_H(ctx->r16, 0X4);
            goto L_80025524;
    }
    goto skip_0;
    // 0x80025514: lh          $t1, 0x4($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X4);
    skip_0:
    // 0x80025518: b           L_8002559C
    // 0x8002551C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8002559C;
    // 0x8002551C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80025520: lh          $t1, 0x4($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X4);
L_80025524:
    // 0x80025524: b           L_80025534
    // 0x80025528: sh          $t1, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r9;
        goto L_80025534;
    // 0x80025528: sh          $t1, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r9;
L_8002552C:
    // 0x8002552C: b           L_8002559C
    // 0x80025530: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8002559C;
    // 0x80025530: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80025534:
    // 0x80025534: lh          $v0, 0xA($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XA);
    // 0x80025538: beq         $v0, $zero, L_80025548
    if (ctx->r2 == 0) {
        // 0x8002553C: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_80025548;
    }
    // 0x8002553C: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x80025540: b           L_80025598
    // 0x80025544: sh          $t2, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r10;
        goto L_80025598;
    // 0x80025544: sh          $t2, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r10;
L_80025548:
    // 0x80025548: jal         0x8003F3A4
    // 0x8002554C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8003F3A4(rdram, ctx);
        goto after_0;
    // 0x8002554C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80025550: beq         $v0, $zero, L_80025598
    if (ctx->r2 == 0) {
        // 0x80025554: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80025598;
    }
    // 0x80025554: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80025558: lh          $t3, 0x6($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X6);
    // 0x8002555C: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80025560: sh          $t4, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r12;
    // 0x80025564: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
    // 0x80025568: beql        $t5, $zero, L_80025580
    if (ctx->r13 == 0) {
        // 0x8002556C: lh          $v0, 0x2($s0)
        ctx->r2 = MEM_H(ctx->r16, 0X2);
            goto L_80025580;
    }
    goto skip_1;
    // 0x8002556C: lh          $v0, 0x2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2);
    skip_1:
    // 0x80025570: lh          $t6, 0x8($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X8);
    // 0x80025574: b           L_80025598
    // 0x80025578: sh          $t6, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r14;
        goto L_80025598;
    // 0x80025578: sh          $t6, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r14;
    // 0x8002557C: lh          $v0, 0x2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2);
L_80025580:
    // 0x80025580: lh          $t7, 0xC($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XC);
    // 0x80025584: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80025588: beq         $v0, $at, L_80025598
    if (ctx->r2 == ctx->r1) {
        // 0x8002558C: sh          $t7, 0xE($s0)
        MEM_H(0XE, ctx->r16) = ctx->r15;
            goto L_80025598;
    }
    // 0x8002558C: sh          $t7, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r15;
    // 0x80025590: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x80025594: sh          $t8, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r24;
L_80025598:
    // 0x80025598: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8002559C:
    // 0x8002559C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800255A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800255A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800255A8: jr          $ra
    TRACE_RETURN()
    return;
;}
