#include "recomp.h"
#include "trace.h"
#include "funcs.h"
#include "chopper_recomp_hooks.h"

RECOMP_FUNC void func_8005F3E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005F3E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005F3E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005F3E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8005F3EC: jal         0x800629A0
    // 0x8005F3F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800629A0(rdram, ctx);
        goto after_0;
    // 0x8005F3F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8005F3F4: beq         $v0, $zero, L_8005F404
    if (ctx->r2 == 0) {
        // 0x8005F3F8: nop
    
            goto L_8005F404;
    }
    // 0x8005F3F8: nop

    // 0x8005F3FC: b           L_8005F41C
    // 0x8005F400: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8005F41C;
    // 0x8005F400: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8005F404:
    // 0x8005F404: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8005F408: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8005F40C: lui         $at, 0xA000
    ctx->r1 = S32(0XA000 << 16);
    // 0x8005F410: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8005F414: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005F418: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
L_8005F41C:
    // 0x8005F41C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005F420: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005F424: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005F430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
;}
RECOMP_FUNC void func_8005F4B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
;}
RECOMP_FUNC void func_8005F530(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
;}
RECOMP_FUNC void func_8005F590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005F590: lui         $t6, 0xA460
    ctx->r14 = S32(0XA460 << 16);
    // 0x8005F594: lw          $a2, 0x10($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X10);
    // 0x8005F598: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8005F59C: andi        $t7, $a2, 0x3
    ctx->r15 = ctx->r6 & 0X3;
    // 0x8005F5A0: beq         $t7, $zero, L_8005F5BC
    if (ctx->r15 == 0) {
        // 0x8005F5A4: nop
    
            goto L_8005F5BC;
    }
    // 0x8005F5A4: nop

L_8005F5A8:
    // 0x8005F5A8: lui         $t8, 0xA460
    ctx->r24 = S32(0XA460 << 16);
    // 0x8005F5AC: lw          $a2, 0x10($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X10);
    // 0x8005F5B0: andi        $t9, $a2, 0x3
    ctx->r25 = ctx->r6 & 0X3;
    // 0x8005F5B4: bne         $t9, $zero, L_8005F5A8
    if (ctx->r25 != 0) {
        // 0x8005F5B8: nop
    
            goto L_8005F5A8;
    }
    // 0x8005F5B8: nop

L_8005F5BC:
    // 0x8005F5BC: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x8005F5C0: lw          $t0, 0x308($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X308);
    // 0x8005F5C4: lui         $at, 0xA000
    ctx->r1 = S32(0XA000 << 16);
    // 0x8005F5C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005F5CC: or          $t1, $t0, $a0
    ctx->r9 = ctx->r8 | ctx->r4;
    // 0x8005F5D0: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x8005F5D4: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8005F5D8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8005F5DC: jr          $ra
    // 0x8005F5E0: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    TRACE_RETURN()
    return;
    // 0x8005F5E0: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
;}
RECOMP_FUNC void func_8005F5F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005F5F0: slti        $at, $a1, 0xC
    ctx->r1 = SIGNED(ctx->r5) < 0XC ? 1 : 0;
    // 0x8005F5F4: bne         $at, $zero, L_8005F66C
    if (ctx->r1 != 0) {
        // 0x8005F5F8: negu        $v1, $a0
        ctx->r3 = SUB32(0, ctx->r4);
            goto L_8005F66C;
    }
    // 0x8005F5F8: negu        $v1, $a0
    ctx->r3 = SUB32(0, ctx->r4);
    // 0x8005F5FC: andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // 0x8005F600: beq         $v1, $zero, L_8005F610
    if (ctx->r3 == 0) {
        // 0x8005F604: subu        $a1, $a1, $v1
        ctx->r5 = SUB32(ctx->r5, ctx->r3);
            goto L_8005F610;
    }
    // 0x8005F604: subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // 0x8005F608: swl         $zero, 0x0($a0)
    do_swl(rdram, 0X0, ctx->r4, 0);
    // 0x8005F60C: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
L_8005F610:
    // 0x8005F610: addiu       $at, $zero, -0x20
    ctx->r1 = ADD32(0, -0X20);
    // 0x8005F614: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x8005F618: beq         $a3, $zero, L_8005F64C
    if (ctx->r7 == 0) {
        // 0x8005F61C: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_8005F64C;
    }
    // 0x8005F61C: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x8005F620: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_8005F624:
    // 0x8005F624: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x8005F628: sw          $zero, -0x20($a0)
    MEM_W(-0X20, ctx->r4) = 0;
    // 0x8005F62C: sw          $zero, -0x1C($a0)
    MEM_W(-0X1C, ctx->r4) = 0;
    // 0x8005F630: sw          $zero, -0x18($a0)
    MEM_W(-0X18, ctx->r4) = 0;
    // 0x8005F634: sw          $zero, -0x14($a0)
    MEM_W(-0X14, ctx->r4) = 0;
    // 0x8005F638: sw          $zero, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = 0;
    // 0x8005F63C: sw          $zero, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = 0;
    // 0x8005F640: sw          $zero, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = 0;
    // 0x8005F644: bne         $a0, $a3, L_8005F624
    if (ctx->r4 != ctx->r7) {
        // 0x8005F648: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_8005F624;
    }
    // 0x8005F648: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_8005F64C:
    // 0x8005F64C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8005F650: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x8005F654: beq         $a3, $zero, L_8005F66C
    if (ctx->r7 == 0) {
        // 0x8005F658: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_8005F66C;
    }
    // 0x8005F658: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x8005F65C: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_8005F660:
    // 0x8005F660: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8005F664: bne         $a0, $a3, L_8005F660
    if (ctx->r4 != ctx->r7) {
        // 0x8005F668: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_8005F660;
    }
    // 0x8005F668: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_8005F66C:
    // 0x8005F66C: blez        $a1, L_8005F684
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8005F670: nop
    
            goto L_8005F684;
    }
    // 0x8005F670: nop

    // 0x8005F674: addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
L_8005F678:
    // 0x8005F678: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8005F67C: bne         $a0, $a1, L_8005F678
    if (ctx->r4 != ctx->r5) {
        // 0x8005F680: sb          $zero, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = 0;
            goto L_8005F678;
    }
    // 0x8005F680: sb          $zero, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = 0;
L_8005F684:
    // 0x8005F684: jr          $ra
    // 0x8005F688: nop

    TRACE_RETURN()
    return;
    // 0x8005F688: nop

    // 0x8005F68C: nop

    // 0x8005F690: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8005F694: lw          $t6, -0x2104($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2104);
    // 0x8005F698: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005F69C: lui         $at, 0xB000
    ctx->r1 = S32(0XB000 << 16);
    // 0x8005F6A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005F6A4: bne         $t6, $at, L_8005F6B8
    if (ctx->r14 != ctx->r1) {
        // 0x8005F6A8: sw          $zero, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = 0;
            goto L_8005F6B8;
    }
    // 0x8005F6A8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8005F6AC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8005F6B0: b           L_8005F76C
    // 0x8005F6B4: addiu       $v0, $v0, -0x2110
    ctx->r2 = ADD32(ctx->r2, -0X2110);
        goto L_8005F76C;
    // 0x8005F6B4: addiu       $v0, $v0, -0x2110
    ctx->r2 = ADD32(ctx->r2, -0X2110);
L_8005F6B8:
    // 0x8005F6B8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8005F6BC: sb          $zero, -0x210C($at)
    MEM_B(-0X210C, ctx->r1) = 0;
    // 0x8005F6C0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8005F6C4: lui         $t7, 0xB000
    ctx->r15 = S32(0XB000 << 16);
    // 0x8005F6C8: sw          $t7, -0x2104($at)
    MEM_W(-0X2104, ctx->r1) = ctx->r15;
    // 0x8005F6CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005F6D0: jal         0x8005F590
    // 0x8005F6D4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8005F590(rdram, ctx);
        goto after_0;
    // 0x8005F6D4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8005F6D8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8005F6DC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8005F6E0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005F6E4: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x8005F6E8: sb          $t9, -0x210B($at)
    MEM_B(-0X210B, ctx->r1) = ctx->r25;
    // 0x8005F6EC: srl         $t0, $t8, 8
    ctx->r8 = S32(U32(ctx->r24) >> 8);
    // 0x8005F6F0: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x8005F6F4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8005F6F8: sb          $t1, -0x2108($at)
    MEM_B(-0X2108, ctx->r1) = ctx->r9;
    // 0x8005F6FC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8005F700: srl         $t2, $t8, 16
    ctx->r10 = S32(U32(ctx->r24) >> 16);
    // 0x8005F704: srl         $t4, $t8, 20
    ctx->r12 = S32(U32(ctx->r24) >> 20);
    // 0x8005F708: andi        $t3, $t2, 0xF
    ctx->r11 = ctx->r10 & 0XF;
    // 0x8005F70C: andi        $t5, $t4, 0xF
    ctx->r13 = ctx->r12 & 0XF;
    // 0x8005F710: sb          $t3, -0x210A($at)
    MEM_B(-0X210A, ctx->r1) = ctx->r11;
    // 0x8005F714: sb          $t5, -0x2109($at)
    MEM_B(-0X2109, ctx->r1) = ctx->r13;
    // 0x8005F718: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8005F71C: addiu       $a0, $a0, -0x2110
    ctx->r4 = ADD32(ctx->r4, -0X2110);
    // 0x8005F720: sb          $zero, -0x2107($at)
    MEM_B(-0X2107, ctx->r1) = 0;
    // 0x8005F724: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x8005F728: jal         0x8005F5F0
    // 0x8005F72C: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    func_8005F5F0(rdram, ctx);
        goto after_1;
    // 0x8005F72C: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    after_1:
    // 0x8005F730: jal         0x80056580
    // 0x8005F734: nop

    __osDisableInt_recomp(rdram, ctx);
        goto after_2;
    // 0x8005F734: nop

    after_2:
    // 0x8005F738: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x8005F73C: lw          $t6, 0x321C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X321C);
    // 0x8005F740: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8005F744: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8005F748: sw          $t6, -0x2110($at)
    MEM_W(-0X2110, ctx->r1) = ctx->r14;
    // 0x8005F74C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8005F750: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8005F754: addiu       $t7, $t7, -0x2110
    ctx->r15 = ADD32(ctx->r15, -0X2110);
    // 0x8005F758: sw          $t7, 0x321C($at)
    MEM_W(0X321C, ctx->r1) = ctx->r15;
    // 0x8005F75C: jal         0x800565A0
    // 0x8005F760: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    __osRestoreInt_recomp(rdram, ctx);
        goto after_3;
    // 0x8005F760: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8005F764: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8005F768: addiu       $v0, $v0, -0x2110
    ctx->r2 = ADD32(ctx->r2, -0X2110);
L_8005F76C:
    // 0x8005F76C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005F770: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005F774: jr          $ra
    // 0x8005F778: nop

    TRACE_RETURN()
    return;
    // 0x8005F778: nop

    // 0x8005F77C: nop

    // 0x8005F780: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8005F784: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8005F788: sb          $t6, -0x208C($at)
    MEM_B(-0X208C, ctx->r1) = ctx->r14;
    // 0x8005F78C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8005F790: lui         $t7, 0xA500
    ctx->r15 = S32(0XA500 << 16);
    // 0x8005F794: sw          $t7, -0x2084($at)
    MEM_W(-0X2084, ctx->r1) = ctx->r15;
    // 0x8005F798: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8005F79C: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8005F7A0: sb          $t8, -0x208B($at)
    MEM_B(-0X208B, ctx->r1) = ctx->r24;
    // 0x8005F7A4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8005F7A8: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x8005F7AC: sb          $t9, -0x2088($at)
    MEM_B(-0X2088, ctx->r1) = ctx->r25;
    // 0x8005F7B0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8005F7B4: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x8005F7B8: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8005F7BC: sb          $t0, -0x208A($at)
    MEM_B(-0X208A, ctx->r1) = ctx->r8;
    // 0x8005F7C0: sb          $t1, -0x2089($at)
    MEM_B(-0X2089, ctx->r1) = ctx->r9;
    // 0x8005F7C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005F7C8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8005F7CC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8005F7D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005F7D4: sb          $t2, -0x2087($at)
    MEM_B(-0X2087, ctx->r1) = ctx->r10;
    // 0x8005F7D8: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8005F7DC: lui         $t4, 0xA460
    ctx->r12 = S32(0XA460 << 16);
    // 0x8005F7E0: sw          $t3, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->r11;
    // 0x8005F7E4: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x8005F7E8: lbu         $t5, -0x2088($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X2088);
    // 0x8005F7EC: lui         $t6, 0xA460
    ctx->r14 = S32(0XA460 << 16);
    // 0x8005F7F0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8005F7F4: sw          $t5, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->r13;
    // 0x8005F7F8: lbu         $t7, -0x208A($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X208A);
    // 0x8005F7FC: lui         $t8, 0xA460
    ctx->r24 = S32(0XA460 << 16);
    // 0x8005F800: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8005F804: sw          $t7, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->r15;
    // 0x8005F808: lbu         $t9, -0x2089($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X2089);
    // 0x8005F80C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005F810: lui         $t0, 0xA460
    ctx->r8 = S32(0XA460 << 16);
    // 0x8005F814: addiu       $a0, $a0, -0x2090
    ctx->r4 = ADD32(ctx->r4, -0X2090);
    // 0x8005F818: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x8005F81C: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    // 0x8005F820: jal         0x8005F5F0
    // 0x8005F824: sw          $t9, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r25;
    func_8005F5F0(rdram, ctx);
        goto after_4;
    // 0x8005F824: sw          $t9, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r25;
    after_4:
    // 0x8005F828: jal         0x80056580
    // 0x8005F82C: nop

    __osDisableInt_recomp(rdram, ctx);
        goto after_5;
    // 0x8005F82C: nop

    after_5:
    // 0x8005F830: lui         $t1, 0x8007
    ctx->r9 = S32(0X8007 << 16);
    // 0x8005F834: lw          $t1, 0x321C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X321C);
    // 0x8005F838: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8005F83C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x8005F840: sw          $t1, -0x2090($at)
    MEM_W(-0X2090, ctx->r1) = ctx->r9;
    // 0x8005F844: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8005F848: addiu       $t2, $t2, -0x2090
    ctx->r10 = ADD32(ctx->r10, -0X2090);
    // 0x8005F84C: sw          $t2, 0x321C($at)
    MEM_W(0X321C, ctx->r1) = ctx->r10;
    // 0x8005F850: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8005F854: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8005F858: sw          $t2, -0x201C($at)
    MEM_W(-0X201C, ctx->r1) = ctx->r10;
    // 0x8005F85C: jal         0x800565A0
    // 0x8005F860: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    __osRestoreInt_recomp(rdram, ctx);
        goto after_6;
    // 0x8005F860: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_6:
    // 0x8005F864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005F868: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8005F86C: addiu       $v0, $v0, -0x2090
    ctx->r2 = ADD32(ctx->r2, -0X2090);
    // 0x8005F870: jr          $ra
    // 0x8005F874: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    TRACE_RETURN()
    return;
    // 0x8005F874: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8005F880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005F880: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005F884: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005F888: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005F88C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8005F890: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005F894: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8005F898: sw          $t6, 0x4760($at)
    MEM_W(0X4760, ctx->r1) = ctx->r14;
    // 0x8005F89C: addiu       $a1, $a1, -0x2010
    ctx->r5 = ADD32(ctx->r5, -0X2010);
    // 0x8005F8A0: addiu       $a0, $a0, -0x2008
    ctx->r4 = ADD32(ctx->r4, -0X2008);
    // 0x8005F8A4: jal         0x80052780
    // 0x8005F8A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x8005F8A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8005F8AC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005F8B0: addiu       $a0, $a0, -0x2008
    ctx->r4 = ADD32(ctx->r4, -0X2008);
    // 0x8005F8B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005F8B8: jal         0x800534A0
    // 0x8005F8BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8005F8BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8005F8C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005F8C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005F8C8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005F8D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005F8D0: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x8005F8D4: lw          $t6, 0x4760($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4760);
    // 0x8005F8D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005F8DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005F8E0: bne         $t6, $zero, L_8005F8F0
    if (ctx->r14 != 0) {
        // 0x8005F8E4: nop
    
            goto L_8005F8F0;
    }
    // 0x8005F8E4: nop

    // 0x8005F8E8: jal         0x8005F880
    // 0x8005F8EC: nop

    func_8005F880(rdram, ctx);
        goto after_0;
    // 0x8005F8EC: nop

    after_0:
L_8005F8F0:
    // 0x8005F8F0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005F8F4: addiu       $a0, $a0, -0x2008
    ctx->r4 = ADD32(ctx->r4, -0X2008);
    // 0x8005F8F8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8005F8FC: jal         0x8004F990
    // 0x8005F900: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8005F900: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8005F904: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005F908: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005F90C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005F914(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005F914: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005F918: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005F91C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005F920: addiu       $a0, $a0, -0x2008
    ctx->r4 = ADD32(ctx->r4, -0X2008);
    // 0x8005F924: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005F928: jal         0x800534A0
    // 0x8005F92C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8005F92C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8005F930: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005F934: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005F938: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005F960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005F960: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005F964: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005F968: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8005F96C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8005F970: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8005F974: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8005F978: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8005F97C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8005F980: lui         $t6, 0xA460
    ctx->r14 = S32(0XA460 << 16);
    // 0x8005F984: lw          $s0, 0x10($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X10);
    // 0x8005F988: andi        $t7, $s0, 0x3
    ctx->r15 = ctx->r16 & 0X3;
    // 0x8005F98C: beq         $t7, $zero, L_8005F9A8
    if (ctx->r15 == 0) {
        // 0x8005F990: nop
    
            goto L_8005F9A8;
    }
    // 0x8005F990: nop

L_8005F994:
    // 0x8005F994: lui         $t8, 0xA460
    ctx->r24 = S32(0XA460 << 16);
    // 0x8005F998: lw          $s0, 0x10($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X10);
    // 0x8005F99C: andi        $t9, $s0, 0x3
    ctx->r25 = ctx->r16 & 0X3;
    // 0x8005F9A0: bne         $t9, $zero, L_8005F994
    if (ctx->r25 != 0) {
        // 0x8005F9A4: nop
    
            goto L_8005F994;
    }
    // 0x8005F9A4: nop

L_8005F9A8:
    // 0x8005F9A8: jal         0x80053750
    // 0x8005F9AC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x8005F9AC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_0:
    // 0x8005F9B0: lui         $t0, 0xA460
    ctx->r8 = S32(0XA460 << 16);
    // 0x8005F9B4: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8005F9B8: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x8005F9BC: lw          $t1, 0x308($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X308);
    // 0x8005F9C0: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8005F9C4: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x8005F9C8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8005F9CC: or          $t3, $t1, $t2
    ctx->r11 = ctx->r9 | ctx->r10;
    // 0x8005F9D0: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x8005F9D4: lui         $t5, 0xA460
    ctx->r13 = S32(0XA460 << 16);
    // 0x8005F9D8: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x8005F9DC: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8005F9E0: beq         $s1, $zero, L_8005F9F8
    if (ctx->r17 == 0) {
        // 0x8005F9E4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8005F9F8;
    }
    // 0x8005F9E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005F9E8: beq         $s1, $at, L_8005FA0C
    if (ctx->r17 == ctx->r1) {
        // 0x8005F9EC: nop
    
            goto L_8005FA0C;
    }
    // 0x8005F9EC: nop

    // 0x8005F9F0: b           L_8005FA20
    // 0x8005F9F4: nop

        goto L_8005FA20;
    // 0x8005F9F4: nop

L_8005F9F8:
    // 0x8005F9F8: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8005F9FC: lui         $t8, 0xA460
    ctx->r24 = S32(0XA460 << 16);
    // 0x8005FA00: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8005FA04: b           L_8005FA28
    // 0x8005FA08: sw          $t7, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r15;
        goto L_8005FA28;
    // 0x8005FA08: sw          $t7, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r15;
L_8005FA0C:
    // 0x8005FA0C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8005FA10: lui         $t1, 0xA460
    ctx->r9 = S32(0XA460 << 16);
    // 0x8005FA14: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8005FA18: b           L_8005FA28
    // 0x8005FA1C: sw          $t0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r8;
        goto L_8005FA28;
    // 0x8005FA1C: sw          $t0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r8;
L_8005FA20:
    // 0x8005FA20: b           L_8005FA2C
    // 0x8005FA24: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8005FA2C;
    // 0x8005FA24: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8005FA28:
    // 0x8005FA28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005FA2C:
    // 0x8005FA2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005FA30: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8005FA34: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8005FA38: jr          $ra
    // 0x8005FA3C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    TRACE_RETURN()
    return;
    // 0x8005FA3C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
static void func_8005FA40_entry(uint8_t* rdram, recomp_context* ctx, unsigned entry) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    if (entry == 1) goto indirect_8005FC70;

    // 0x8005FA40: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8005FA44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005FA48: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8005FA4C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8005FA50: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8005FA54: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8005FA58: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005FA5C: lui         $t6, 0xA460
    ctx->r14 = S32(0XA460 << 16);
    // 0x8005FA60: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8005FA64: andi        $t8, $t7, 0x3
    ctx->r24 = ctx->r15 & 0X3;
    // 0x8005FA68: beq         $t8, $zero, L_8005FA8C
    if (ctx->r24 == 0) {
        // 0x8005FA6C: sw          $t7, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r15;
            goto L_8005FA8C;
    }
    // 0x8005FA6C: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
L_8005FA70:
    // 0x8005FA70: lui         $t9, 0xA460
    ctx->r25 = S32(0XA460 << 16);
    // 0x8005FA74: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x8005FA78: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8005FA7C: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8005FA80: andi        $t2, $t1, 0x3
    ctx->r10 = ctx->r9 & 0X3;
    // 0x8005FA84: bne         $t2, $zero, L_8005FA70
    if (ctx->r10 != 0) {
        // 0x8005FA88: nop
    
            goto L_8005FA70;
    }
    // 0x8005FA88: nop

L_8005FA8C:
    // 0x8005FA8C: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8005FA90: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x8005FA94: lbu         $t4, 0x9($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X9);
    // 0x8005FA98: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8005FA9C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8005FAA0: lw          $t6, 0x3220($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3220);
    // 0x8005FAA4: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x8005FAA8: beq         $t6, $t3, L_8005FBCC
    if (ctx->r14 == ctx->r11) {
        // 0x8005FAAC: nop
    
            goto L_8005FBCC;
    }
    // 0x8005FAAC: nop

    // 0x8005FAB0: bne         $t4, $zero, L_8005FB34
    if (ctx->r12 != 0) {
        // 0x8005FAB4: sw          $t6, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r14;
            goto L_8005FB34;
    }
    // 0x8005FAB4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8005FAB8: lbu         $t7, 0x5($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X5);
    // 0x8005FABC: lbu         $t8, 0x5($t3)
    ctx->r24 = MEM_BU(ctx->r11, 0X5);
    // 0x8005FAC0: beq         $t7, $t8, L_8005FAD0
    if (ctx->r15 == ctx->r24) {
        // 0x8005FAC4: nop
    
            goto L_8005FAD0;
    }
    // 0x8005FAC4: nop

    // 0x8005FAC8: lui         $t9, 0xA460
    ctx->r25 = S32(0XA460 << 16);
    // 0x8005FACC: sw          $t8, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->r24;
L_8005FAD0:
    // 0x8005FAD0: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8005FAD4: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8005FAD8: lbu         $t1, 0x6($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X6);
    // 0x8005FADC: lbu         $t5, 0x6($t2)
    ctx->r13 = MEM_BU(ctx->r10, 0X6);
    // 0x8005FAE0: beq         $t1, $t5, L_8005FAF0
    if (ctx->r9 == ctx->r13) {
        // 0x8005FAE4: nop
    
            goto L_8005FAF0;
    }
    // 0x8005FAE4: nop

    // 0x8005FAE8: lui         $t4, 0xA460
    ctx->r12 = S32(0XA460 << 16);
    // 0x8005FAEC: sw          $t5, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->r13;
L_8005FAF0:
    // 0x8005FAF0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8005FAF4: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8005FAF8: lbu         $t3, 0x7($t6)
    ctx->r11 = MEM_BU(ctx->r14, 0X7);
    // 0x8005FAFC: lbu         $t8, 0x7($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X7);
    // 0x8005FB00: beq         $t3, $t8, L_8005FB10
    if (ctx->r11 == ctx->r24) {
        // 0x8005FB04: nop
    
            goto L_8005FB10;
    }
    // 0x8005FB04: nop

    // 0x8005FB08: lui         $t9, 0xA460
    ctx->r25 = S32(0XA460 << 16);
    // 0x8005FB0C: sw          $t8, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->r24;
L_8005FB10:
    // 0x8005FB10: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8005FB14: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8005FB18: lbu         $t2, 0x8($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X8);
    // 0x8005FB1C: lbu         $t5, 0x8($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0X8);
    // 0x8005FB20: beq         $t2, $t5, L_8005FBB4
    if (ctx->r10 == ctx->r13) {
        // 0x8005FB24: nop
    
            goto L_8005FBB4;
    }
    // 0x8005FB24: nop

    // 0x8005FB28: lui         $t4, 0xA460
    ctx->r12 = S32(0XA460 << 16);
    // 0x8005FB2C: b           L_8005FBB4
    // 0x8005FB30: sw          $t5, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r13;
        goto L_8005FBB4;
    // 0x8005FB30: sw          $t5, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r13;
L_8005FB34:
    // 0x8005FB34: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8005FB38: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8005FB3C: lbu         $t7, 0x5($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X5);
    // 0x8005FB40: lbu         $t8, 0x5($t3)
    ctx->r24 = MEM_BU(ctx->r11, 0X5);
    // 0x8005FB44: beq         $t7, $t8, L_8005FB54
    if (ctx->r15 == ctx->r24) {
        // 0x8005FB48: nop
    
            goto L_8005FB54;
    }
    // 0x8005FB48: nop

    // 0x8005FB4C: lui         $t9, 0xA460
    ctx->r25 = S32(0XA460 << 16);
    // 0x8005FB50: sw          $t8, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r24;
L_8005FB54:
    // 0x8005FB54: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8005FB58: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8005FB5C: lbu         $t1, 0x6($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X6);
    // 0x8005FB60: lbu         $t5, 0x6($t2)
    ctx->r13 = MEM_BU(ctx->r10, 0X6);
    // 0x8005FB64: beq         $t1, $t5, L_8005FB74
    if (ctx->r9 == ctx->r13) {
        // 0x8005FB68: nop
    
            goto L_8005FB74;
    }
    // 0x8005FB68: nop

    // 0x8005FB6C: lui         $t4, 0xA460
    ctx->r12 = S32(0XA460 << 16);
    // 0x8005FB70: sw          $t5, 0x2C($t4)
    MEM_W(0X2C, ctx->r12) = ctx->r13;
L_8005FB74:
    // 0x8005FB74: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8005FB78: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8005FB7C: lbu         $t3, 0x7($t6)
    ctx->r11 = MEM_BU(ctx->r14, 0X7);
    // 0x8005FB80: lbu         $t8, 0x7($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X7);
    // 0x8005FB84: beq         $t3, $t8, L_8005FB94
    if (ctx->r11 == ctx->r24) {
        // 0x8005FB88: nop
    
            goto L_8005FB94;
    }
    // 0x8005FB88: nop

    // 0x8005FB8C: lui         $t9, 0xA460
    ctx->r25 = S32(0XA460 << 16);
    // 0x8005FB90: sw          $t8, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->r24;
L_8005FB94:
    // 0x8005FB94: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8005FB98: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8005FB9C: lbu         $t2, 0x8($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X8);
    // 0x8005FBA0: lbu         $t5, 0x8($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0X8);
    // 0x8005FBA4: beq         $t2, $t5, L_8005FBB4
    if (ctx->r10 == ctx->r13) {
        // 0x8005FBA8: nop
    
            goto L_8005FBB4;
    }
    // 0x8005FBA8: nop

    // 0x8005FBAC: lui         $t4, 0xA460
    ctx->r12 = S32(0XA460 << 16);
    // 0x8005FBB0: sw          $t5, 0x28($t4)
    MEM_W(0X28, ctx->r12) = ctx->r13;
L_8005FBB4:
    // 0x8005FBB4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8005FBB8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8005FBBC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8005FBC0: sll         $t3, $t7, 2
    ctx->r11 = S32(ctx->r15 << 2);
    // 0x8005FBC4: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8005FBC8: sw          $t6, 0x3220($at)
    MEM_W(0X3220, ctx->r1) = ctx->r14;
L_8005FBCC:
    // 0x8005FBCC: jal         0x80053750
    // 0x8005FBD0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x8005FBD0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_0:
    // 0x8005FBD4: lui         $t8, 0xA460
    ctx->r24 = S32(0XA460 << 16);
    // 0x8005FBD8: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x8005FBDC: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8005FBE0: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8005FBE4: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x8005FBE8: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x8005FBEC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8005FBF0: lui         $t4, 0xA460
    ctx->r12 = S32(0XA460 << 16);
    // 0x8005FBF4: or          $t2, $t0, $t1
    ctx->r10 = ctx->r8 | ctx->r9;
    // 0x8005FBF8: and         $t5, $t2, $at
    ctx->r13 = ctx->r10 & ctx->r1;
    // 0x8005FBFC: sw          $t5, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r13;
    // 0x8005FC00: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x8005FC04: beq         $s0, $zero, L_8005FC1C
    if (ctx->r16 == 0) {
        // 0x8005FC08: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8005FC1C;
    }
    // 0x8005FC08: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005FC0C: beq         $s0, $at, L_8005FC30
    if (ctx->r16 == ctx->r1) {
        // 0x8005FC10: nop
    
            goto L_8005FC30;
    }
    // 0x8005FC10: nop

    // 0x8005FC14: b           L_8005FC44
    // 0x8005FC18: nop

        goto L_8005FC44;
    // 0x8005FC18: nop

L_8005FC1C:
    // 0x8005FC1C: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8005FC20: lui         $t3, 0xA460
    ctx->r11 = S32(0XA460 << 16);
    // 0x8005FC24: addiu       $t6, $t7, -0x1
    ctx->r14 = ADD32(ctx->r15, -0X1);
    // 0x8005FC28: b           L_8005FC4C
    // 0x8005FC2C: sw          $t6, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r14;
        goto L_8005FC4C;
    // 0x8005FC2C: sw          $t6, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r14;
L_8005FC30:
    // 0x8005FC30: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8005FC34: lui         $t0, 0xA460
    ctx->r8 = S32(0XA460 << 16);
    // 0x8005FC38: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8005FC3C: b           L_8005FC4C
    // 0x8005FC40: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
        goto L_8005FC4C;
    // 0x8005FC40: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
L_8005FC44:
    // 0x8005FC44: b           L_8005FC50
    // 0x8005FC48: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8005FC50;
    // 0x8005FC48: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8005FC4C:
    // 0x8005FC4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005FC50:
    // 0x8005FC50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005FC54: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005FC58: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8005FC5C: jr          $ra
    // 0x8005FC60: nop

    TRACE_RETURN()
    return;
    // 0x8005FC60: nop

    // 0x8005FC64: nop

    // 0x8005FC68: nop

    // 0x8005FC6C: nop

indirect_8005FC70:
    // 0x8005FC70: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8005FC74: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8005FC78: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8005FC7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005FC80: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8005FC84: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x8005FC88: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x8005FC8C: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
L_8005FC90:
    // 0x8005FC90: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8005FC94: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x8005FC98: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005FC9C: jal         0x8004F990
    // 0x8005FCA0: lw          $a0, 0x8($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X8);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8005FCA0: lw          $a0, 0x8($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X8);
    after_1:
    // 0x8005FCA4: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8005FCA8: lw          $t9, 0x14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X14);
    // 0x8005FCAC: beq         $t9, $zero, L_8005FF34
    if (ctx->r25 == 0) {
        // 0x8005FCB0: nop
    
            goto L_8005FF34;
    }
    // 0x8005FCB0: nop

    // 0x8005FCB4: lbu         $t0, 0x4($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X4);
    // 0x8005FCB8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005FCBC: bne         $t0, $at, L_8005FF34
    if (ctx->r8 != ctx->r1) {
        // 0x8005FCC0: nop
    
            goto L_8005FF34;
    }
    // 0x8005FCC0: nop

    // 0x8005FCC4: lw          $t1, 0x14($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X14);
    // 0x8005FCC8: beq         $t1, $zero, L_8005FCD8
    if (ctx->r9 == 0) {
        // 0x8005FCCC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8005FCD8;
    }
    // 0x8005FCCC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005FCD0: bne         $t1, $at, L_8005FF34
    if (ctx->r9 != ctx->r1) {
        // 0x8005FCD4: nop
    
            goto L_8005FF34;
    }
    // 0x8005FCD4: nop

L_8005FCD8:
    // 0x8005FCD8: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8005FCDC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8005FCE0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005FCE4: lw          $t3, 0x14($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X14);
    // 0x8005FCE8: addiu       $t4, $t3, 0x14
    ctx->r12 = ADD32(ctx->r11, 0X14);
    // 0x8005FCEC: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x8005FCF0: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x8005FCF4: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x8005FCF8: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8005FCFC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8005FD00: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x8005FD04: addiu       $t8, $t7, 0x18
    ctx->r24 = ADD32(ctx->r15, 0X18);
    // 0x8005FD08: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8005FD0C: sw          $t0, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r8;
    // 0x8005FD10: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8005FD14: lhu         $t1, 0x4($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X4);
    // 0x8005FD18: beq         $t1, $at, L_8005FD34
    if (ctx->r9 == ctx->r1) {
        // 0x8005FD1C: nop
    
            goto L_8005FD34;
    }
    // 0x8005FD1C: nop

    // 0x8005FD20: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8005FD24: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x8005FD28: lw          $t5, 0xC($t2)
    ctx->r13 = MEM_W(ctx->r10, 0XC);
    // 0x8005FD2C: subu        $t6, $t3, $t5
    ctx->r14 = SUB32(ctx->r11, ctx->r13);
    // 0x8005FD30: sw          $t6, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r14;
L_8005FD34:
    // 0x8005FD34: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8005FD38: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005FD3C: lhu         $t8, 0x4($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X4);
    // 0x8005FD40: bne         $t8, $at, L_8005FD68
    if (ctx->r24 != ctx->r1) {
        // 0x8005FD44: nop
    
            goto L_8005FD68;
    }
    // 0x8005FD44: nop

    // 0x8005FD48: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8005FD4C: lw          $t4, 0x14($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X14);
    // 0x8005FD50: lw          $t9, 0x14($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X14);
    // 0x8005FD54: bne         $t9, $zero, L_8005FD68
    if (ctx->r25 != 0) {
        // 0x8005FD58: nop
    
            goto L_8005FD68;
    }
    // 0x8005FD58: nop

    // 0x8005FD5C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8005FD60: b           L_8005FD6C
    // 0x8005FD64: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
        goto L_8005FD6C;
    // 0x8005FD64: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
L_8005FD68:
    // 0x8005FD68: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_8005FD6C:
    // 0x8005FD6C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8005FD70: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x8005FD74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005FD78: jal         0x8004F990
    // 0x8005FD7C: lw          $a0, 0x10($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X10);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x8005FD7C: lw          $a0, 0x10($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X10);
    after_2:
    // 0x8005FD80: lui         $a0, 0x10
    ctx->r4 = S32(0X10 << 16);
    // 0x8005FD84: jal         0x800629D0
    // 0x8005FD88: ori         $a0, $a0, 0x401
    ctx->r4 = ctx->r4 | 0X401;
    func_800629D0(rdram, ctx);
        goto after_3;
    // 0x8005FD88: ori         $a0, $a0, 0x401
    ctx->r4 = ctx->r4 | 0X401;
    after_3:
    // 0x8005FD8C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8005FD90: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8005FD94: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005FD98: lw          $a2, 0x10($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X10);
    // 0x8005FD9C: lui         $a1, 0x500
    ctx->r5 = S32(0X500 << 16);
    // 0x8005FDA0: ori         $a1, $a1, 0x510
    ctx->r5 = ctx->r5 | 0X510;
    // 0x8005FDA4: or          $t2, $a2, $at
    ctx->r10 = ctx->r6 | ctx->r1;
    // 0x8005FDA8: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    // 0x8005FDAC: jal         0x80062A30
    // 0x8005FDB0: lw          $a0, 0x14($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X14);
    func_80062A30(rdram, ctx);
        goto after_4;
    // 0x8005FDB0: lw          $a0, 0x14($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X14);
    after_4:
L_8005FDB4:
    // 0x8005FDB4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8005FDB8: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x8005FDBC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005FDC0: jal         0x8004F990
    // 0x8005FDC4: lw          $a0, 0xC($t7)
    ctx->r4 = MEM_W(ctx->r15, 0XC);
    osRecvMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x8005FDC4: lw          $a0, 0xC($t7)
    ctx->r4 = MEM_W(ctx->r15, 0XC);
    after_5:
    // 0x8005FDC8: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8005FDCC: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x8005FDD0: lw          $t0, 0x14($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X14);
    // 0x8005FDD4: addiu       $t4, $t0, 0x14
    ctx->r12 = ADD32(ctx->r8, 0X14);
    // 0x8005FDD8: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x8005FDDC: lhu         $t9, 0x6($t4)
    ctx->r25 = MEM_HU(ctx->r12, 0X6);
    // 0x8005FDE0: sll         $t1, $t9, 3
    ctx->r9 = S32(ctx->r25 << 3);
    // 0x8005FDE4: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x8005FDE8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8005FDEC: addu        $t3, $t4, $t1
    ctx->r11 = ADD32(ctx->r12, ctx->r9);
    // 0x8005FDF0: addiu       $t5, $t3, 0x18
    ctx->r13 = ADD32(ctx->r11, 0X18);
    // 0x8005FDF4: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x8005FDF8: lw          $t6, 0x18($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X18);
    // 0x8005FDFC: bne         $t6, $at, L_8005FEB8
    if (ctx->r14 != ctx->r1) {
        // 0x8005FE00: nop
    
            goto L_8005FEB8;
    }
    // 0x8005FE00: nop

    // 0x8005FE04: lw          $a2, 0x10($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X10);
    // 0x8005FE08: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x8005FE0C: lui         $a1, 0x500
    ctx->r5 = S32(0X500 << 16);
    // 0x8005FE10: or          $t2, $a2, $at
    ctx->r10 = ctx->r6 | ctx->r1;
    // 0x8005FE14: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    // 0x8005FE18: ori         $a1, $a1, 0x510
    ctx->r5 = ctx->r5 | 0X510;
    // 0x8005FE1C: jal         0x80062A30
    // 0x8005FE20: lw          $a0, 0x14($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X14);
    func_80062A30(rdram, ctx);
        goto after_6;
    // 0x8005FE20: lw          $a0, 0x14($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X14);
    after_6:
    // 0x8005FE24: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8005FE28: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8005FE2C: lui         $a1, 0x500
    ctx->r5 = S32(0X500 << 16);
    // 0x8005FE30: ori         $a1, $a1, 0x510
    ctx->r5 = ctx->r5 | 0X510;
    // 0x8005FE34: lw          $a0, 0x14($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X14);
    // 0x8005FE38: jal         0x80062A30
    // 0x8005FE3C: lw          $a2, 0x10($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X10);
    func_80062A30(rdram, ctx);
        goto after_7;
    // 0x8005FE3C: lw          $a2, 0x10($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X10);
    after_7:
    // 0x8005FE40: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8005FE44: lui         $a1, 0x500
    ctx->r5 = S32(0X500 << 16);
    // 0x8005FE48: ori         $a1, $a1, 0x508
    ctx->r5 = ctx->r5 | 0X508;
    // 0x8005FE4C: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x8005FE50: jal         0x80062A80
    // 0x8005FE54: lw          $a0, 0x14($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X14);
    func_80062A80(rdram, ctx);
        goto after_8;
    // 0x8005FE54: lw          $a0, 0x14($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X14);
    after_8:
    // 0x8005FE58: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8005FE5C: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8005FE60: and         $t5, $t1, $at
    ctx->r13 = ctx->r9 & ctx->r1;
    // 0x8005FE64: beq         $t5, $zero, L_8005FE94
    if (ctx->r13 == 0) {
        // 0x8005FE68: nop
    
            goto L_8005FE94;
    }
    // 0x8005FE68: nop

    // 0x8005FE6C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8005FE70: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8005FE74: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x8005FE78: lw          $a2, 0x10($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X10);
    // 0x8005FE7C: lui         $a1, 0x500
    ctx->r5 = S32(0X500 << 16);
    // 0x8005FE80: ori         $a1, $a1, 0x510
    ctx->r5 = ctx->r5 | 0X510;
    // 0x8005FE84: or          $t8, $a2, $at
    ctx->r24 = ctx->r6 | ctx->r1;
    // 0x8005FE88: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x8005FE8C: jal         0x80062A30
    // 0x8005FE90: lw          $a0, 0x14($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X14);
    func_80062A30(rdram, ctx);
        goto after_9;
    // 0x8005FE90: lw          $a0, 0x14($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X14);
    after_9:
L_8005FE94:
    // 0x8005FE94: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8005FE98: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8005FE9C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8005FEA0: lui         $t0, 0xA460
    ctx->r8 = S32(0XA460 << 16);
    // 0x8005FEA4: lui         $a0, 0x10
    ctx->r4 = S32(0X10 << 16);
    // 0x8005FEA8: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x8005FEAC: sw          $t7, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r15;
    // 0x8005FEB0: jal         0x80062AD0
    // 0x8005FEB4: ori         $a0, $a0, 0xC01
    ctx->r4 = ctx->r4 | 0XC01;
    func_80062AD0(rdram, ctx);
        goto after_10;
    // 0x8005FEB4: ori         $a0, $a0, 0xC01
    ctx->r4 = ctx->r4 | 0XC01;
    after_10:
L_8005FEB8:
    // 0x8005FEB8: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8005FEBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005FEC0: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x8005FEC4: jal         0x800534A0
    // 0x8005FEC8: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_11;
    // 0x8005FEC8: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_11:
    // 0x8005FECC: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8005FED0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005FED4: bne         $t1, $at, L_8005FEF8
    if (ctx->r9 != ctx->r1) {
        // 0x8005FED8: nop
    
            goto L_8005FEF8;
    }
    // 0x8005FED8: nop

    // 0x8005FEDC: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8005FEE0: lw          $t3, 0x14($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X14);
    // 0x8005FEE4: lw          $t6, 0x2C($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X2C);
    // 0x8005FEE8: bne         $t6, $zero, L_8005FEF8
    if (ctx->r14 != 0) {
        // 0x8005FEEC: nop
    
            goto L_8005FEF8;
    }
    // 0x8005FEEC: nop

    // 0x8005FEF0: b           L_8005FDB4
    // 0x8005FEF4: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
        goto L_8005FDB4;
    // 0x8005FEF4: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_8005FEF8:
    // 0x8005FEF8: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8005FEFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005FF00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005FF04: jal         0x800534A0
    // 0x8005FF08: lw          $a0, 0x10($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X10);
    osSendMesg_recomp(rdram, ctx);
        goto after_12;
    // 0x8005FF08: lw          $a0, 0x10($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X10);
    after_12:
    // 0x8005FF0C: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8005FF10: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005FF14: lw          $t2, 0x14($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X14);
    // 0x8005FF18: lhu         $t7, 0x1A($t2)
    ctx->r15 = MEM_HU(ctx->r10, 0X1A);
    // 0x8005FF1C: bne         $t7, $at, L_8005FC90
    if (ctx->r15 != ctx->r1) {
        // 0x8005FF20: nop
    
            goto L_8005FC90;
    }
    // 0x8005FF20: nop

    // 0x8005FF24: jal         0x80062B20
    // 0x8005FF28: nop

    func_80062B20(rdram, ctx);
        goto after_13;
    // 0x8005FF28: nop

    after_13:
    // 0x8005FF2C: b           L_8005FC90
    // 0x8005FF30: nop

        goto L_8005FC90;
    // 0x8005FF30: nop

L_8005FF34:
    // 0x8005FF34: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8005FF38: lhu         $t9, 0x0($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X0);
    // 0x8005FF3C: addiu       $t1, $t9, -0xA
    ctx->r9 = ADD32(ctx->r25, -0XA);
    // 0x8005FF40: sltiu       $at, $t1, 0x7
    ctx->r1 = ctx->r9 < 0X7 ? 1 : 0;
    // 0x8005FF44: beq         $at, $zero, L_8006008C
    if (ctx->r1 == 0) {
        // 0x8005FF48: nop
    
            goto L_8006008C;
    }
    // 0x8005FF48: nop

    // 0x8005FF4C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8005FF50: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8005FF54: addu        $at, $at, $t1
    gpr jr_addend_8005FF5C = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8005FF58: lw          $t1, -0x6840($at)
    ctx->r9 = ADD32(ctx->r1, -0X6840);
    // 0x8005FF5C: jr          $t1
    // 0x8005FF60: nop

    switch (jr_addend_8005FF5C >> 2) {
        case 0: goto L_8006006C; break;
        case 1: goto L_8005FF64; break;
        case 2: goto L_8005FFA0; break;
        case 3: goto L_8006008C; break;
        case 4: goto L_8006008C; break;
        case 5: goto L_8005FFDC; break;
        case 6: goto L_80060024; break;
        default: switch_error(__func__, 0x8005FF5C, 0x800797C0);
    }
    // 0x8005FF60: nop

L_8005FF64:
    // 0x8005FF64: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8005FF68: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x8005FF6C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005FF70: jal         0x8004F990
    // 0x8005FF74: lw          $a0, 0x10($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X10);
    osRecvMesg_recomp(rdram, ctx);
        goto after_14;
    // 0x8005FF74: lw          $a0, 0x10($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X10);
    after_14:
    // 0x8005FF78: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8005FF7C: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8005FF80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005FF84: lw          $t9, 0x14($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X14);
    // 0x8005FF88: lw          $a1, 0xC($t3)
    ctx->r5 = MEM_W(ctx->r11, 0XC);
    // 0x8005FF8C: lw          $a2, 0x8($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X8);
    // 0x8005FF90: jalr        $t9
    // 0x8005FF94: lw          $a3, 0x10($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X10);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_15;
    // 0x8005FF94: lw          $a3, 0x10($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X10);
    after_15:
    // 0x8005FF98: b           L_80060094
    // 0x8005FF9C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
        goto L_80060094;
    // 0x8005FF9C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_8005FFA0:
    // 0x8005FFA0: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8005FFA4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x8005FFA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005FFAC: jal         0x8004F990
    // 0x8005FFB0: lw          $a0, 0x10($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X10);
    osRecvMesg_recomp(rdram, ctx);
        goto after_16;
    // 0x8005FFB0: lw          $a0, 0x10($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X10);
    after_16:
    // 0x8005FFB4: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8005FFB8: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8005FFBC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8005FFC0: lw          $t9, 0x14($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X14);
    // 0x8005FFC4: lw          $a1, 0xC($t4)
    ctx->r5 = MEM_W(ctx->r12, 0XC);
    // 0x8005FFC8: lw          $a2, 0x8($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X8);
    // 0x8005FFCC: jalr        $t9
    // 0x8005FFD0: lw          $a3, 0x10($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X10);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_17;
    // 0x8005FFD0: lw          $a3, 0x10($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X10);
    after_17:
    // 0x8005FFD4: b           L_80060094
    // 0x8005FFD8: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
        goto L_80060094;
    // 0x8005FFD8: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_8005FFDC:
    // 0x8005FFDC: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8005FFE0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x8005FFE4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005FFE8: jal         0x8004F990
    // 0x8005FFEC: lw          $a0, 0x10($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X10);
    osRecvMesg_recomp(rdram, ctx);
        goto after_18;
    // 0x8005FFEC: lw          $a0, 0x10($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X10);
    after_18:
    // 0x8005FFF0: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8005FFF4: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8005FFF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005FFFC: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x80060000: lw          $a0, 0x14($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X14);
    // 0x80060004: lw          $a2, 0xC($t0)
    ctx->r6 = MEM_W(ctx->r8, 0XC);
    // 0x80060008: lw          $a3, 0x8($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X8);
    // 0x8006000C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80060010: lw          $t9, 0x18($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X18);
    // 0x80060014: jalr        $t9
    // 0x80060018: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_19;
    // 0x80060018: nop

    after_19:
    // 0x8006001C: b           L_80060094
    // 0x80060020: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
        goto L_80060094;
    // 0x80060020: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_80060024:
    // 0x80060024: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80060028: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x8006002C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80060030: jal         0x8004F990
    // 0x80060034: lw          $a0, 0x10($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X10);
    osRecvMesg_recomp(rdram, ctx);
        goto after_20;
    // 0x80060034: lw          $a0, 0x10($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X10);
    after_20:
    // 0x80060038: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8006003C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80060040: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80060044: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x80060048: lw          $a0, 0x14($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X14);
    // 0x8006004C: lw          $a2, 0xC($t6)
    ctx->r6 = MEM_W(ctx->r14, 0XC);
    // 0x80060050: lw          $a3, 0x8($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X8);
    // 0x80060054: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80060058: lw          $t9, 0x18($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X18);
    // 0x8006005C: jalr        $t9
    // 0x80060060: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_21;
    // 0x80060060: nop

    after_21:
    // 0x80060064: b           L_80060094
    // 0x80060068: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
        goto L_80060094;
    // 0x80060068: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_8006006C:
    // 0x8006006C: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80060070: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80060074: lw          $a0, 0x4($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X4);
    // 0x80060078: jal         0x800534A0
    // 0x8006007C: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_22;
    // 0x8006007C: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    after_22:
    // 0x80060080: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80060084: b           L_80060094
    // 0x80060088: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
        goto L_80060094;
    // 0x80060088: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
L_8006008C:
    // 0x8006008C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80060090: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
L_80060094:
    // 0x80060094: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80060098: bne         $t1, $zero, L_8005FC90
    if (ctx->r9 != 0) {
        // 0x8006009C: nop
    
            goto L_8005FC90;
    }
    // 0x8006009C: nop

    // 0x800600A0: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x800600A4: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800600A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800600AC: jal         0x8004F990
    // 0x800600B0: lw          $a0, 0xC($t5)
    ctx->r4 = MEM_W(ctx->r13, 0XC);
    osRecvMesg_recomp(rdram, ctx);
        goto after_23;
    // 0x800600B0: lw          $a0, 0xC($t5)
    ctx->r4 = MEM_W(ctx->r13, 0XC);
    after_23:
    // 0x800600B4: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x800600B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800600BC: lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X4);
    // 0x800600C0: jal         0x800534A0
    // 0x800600C4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_24;
    // 0x800600C4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_24:
    // 0x800600C8: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800600CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800600D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800600D4: jal         0x800534A0
    // 0x800600D8: lw          $a0, 0x10($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X10);
    osSendMesg_recomp(rdram, ctx);
        goto after_25;
    // 0x800600D8: lw          $a0, 0x10($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X10);
    after_25:
    // 0x800600DC: b           L_8005FC90
    // 0x800600E0: nop

        goto L_8005FC90;
    // 0x800600E0: nop

    // 0x800600E4: nop

    // 0x800600E8: nop

    // 0x800600EC: nop

    // 0x800600F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800600F4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800600F8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005FA40(uint8_t* rdram, recomp_context* ctx) { func_8005FA40_entry(rdram, ctx, 0); }
RECOMP_FUNC void func_8005FC70(uint8_t* rdram, recomp_context* ctx) { func_8005FA40_entry(rdram, ctx, 1); }

RECOMP_FUNC void func_80060110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80060110: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80060114: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x80060118: addiu       $t7, $zero, 0x0
    ctx->r15 = ADD32(0, 0X0);
    // 0x8006011C: sw          $t7, -0x1FCC($at)
    MEM_W(-0X1FCC, ctx->r1) = ctx->r15;
    // 0x80060120: sw          $t6, -0x1FD0($at)
    MEM_W(-0X1FD0, ctx->r1) = ctx->r14;
    // 0x80060124: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80060128: lui         $t8, 0x8007
    ctx->r24 = S32(0X8007 << 16);
    // 0x8006012C: lw          $t8, 0x4770($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4770);
    // 0x80060130: sw          $zero, -0x1FC8($at)
    MEM_W(-0X1FC8, ctx->r1) = 0;
    // 0x80060134: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80060138: sw          $zero, -0x1FC4($at)
    MEM_W(-0X1FC4, ctx->r1) = 0;
    // 0x8006013C: lui         $t9, 0x8007
    ctx->r25 = S32(0X8007 << 16);
    // 0x80060140: sw          $t8, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r24;
    // 0x80060144: lw          $t9, 0x4770($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4770);
    // 0x80060148: lui         $t1, 0x8007
    ctx->r9 = S32(0X8007 << 16);
    // 0x8006014C: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
    // 0x80060150: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80060154: addiu       $t3, $zero, 0x0
    ctx->r11 = ADD32(0, 0X0);
    // 0x80060158: lui         $t4, 0x8007
    ctx->r12 = S32(0X8007 << 16);
    // 0x8006015C: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x80060160: lw          $t1, 0x4770($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4770);
    // 0x80060164: lui         $t5, 0x8007
    ctx->r13 = S32(0X8007 << 16);
    // 0x80060168: lui         $t8, 0x8007
    ctx->r24 = S32(0X8007 << 16);
    // 0x8006016C: sw          $t2, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r10;
    // 0x80060170: sw          $t3, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r11;
    // 0x80060174: lw          $t4, 0x4770($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X4770);
    // 0x80060178: lw          $t6, 0x10($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X10);
    // 0x8006017C: lw          $t7, 0x14($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X14);
    // 0x80060180: sw          $t6, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r14;
    // 0x80060184: sw          $t7, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r15;
    // 0x80060188: lw          $t5, 0x4770($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X4770);
    // 0x8006018C: sw          $zero, 0x18($t5)
    MEM_W(0X18, ctx->r13) = 0;
    // 0x80060190: lw          $t8, 0x4770($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4770);
    // 0x80060194: jr          $ra
    // 0x80060198: sw          $zero, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = 0;
    TRACE_RETURN()
    return;
    // 0x80060198: sw          $zero, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = 0;
;}
RECOMP_FUNC void func_8006019C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8006019C: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x800601A0: lw          $t6, 0x4770($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4770);
    // 0x800601A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800601A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800601AC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800601B0: beq         $t7, $t6, L_80060304
    if (ctx->r15 == ctx->r14) {
        // 0x800601B4: nop
    
            goto L_80060304;
    }
    // 0x800601B4: nop

L_800601B8:
    // 0x800601B8: lui         $t8, 0x8007
    ctx->r24 = S32(0X8007 << 16);
    // 0x800601BC: lw          $t8, 0x4770($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4770);
    // 0x800601C0: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800601C4: bne         $t9, $t8, L_800601E0
    if (ctx->r25 != ctx->r24) {
        // 0x800601C8: sw          $t9, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r25;
            goto L_800601E0;
    }
    // 0x800601C8: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x800601CC: jal         0x80062B70
    // 0x800601D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80062B70(rdram, ctx);
        goto after_0;
    // 0x800601D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800601D4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800601D8: b           L_80060304
    // 0x800601DC: sw          $zero, -0x1FC0($at)
    MEM_W(-0X1FC0, ctx->r1) = 0;
        goto L_80060304;
    // 0x800601DC: sw          $zero, -0x1FC0($at)
    MEM_W(-0X1FC0, ctx->r1) = 0;
L_800601E0:
    // 0x800601E0: jal         0x80060100
    // 0x800601E4: nop

    osGetCount_recomp(rdram, ctx);
        goto after_1;
    // 0x800601E4: nop

    after_1:
    // 0x800601E8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800601EC: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800601F0: lw          $t1, -0x1FC0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X1FC0);
    // 0x800601F4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800601F8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800601FC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80060200: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x80060204: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x80060208: sw          $t0, -0x1FC0($at)
    MEM_W(-0X1FC0, ctx->r1) = ctx->r8;
    // 0x8006020C: lw          $t6, 0x10($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X10);
    // 0x80060210: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80060214: addiu       $t4, $zero, 0x0
    ctx->r12 = ADD32(0, 0X0);
    // 0x80060218: or          $t9, $t7, $zero
    ctx->r25 = ctx->r15 | 0;
    // 0x8006021C: sltu        $at, $t6, $t4
    ctx->r1 = ctx->r14 < ctx->r12 ? 1 : 0;
    // 0x80060220: lw          $t7, 0x14($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X14);
    // 0x80060224: bne         $at, $zero, L_80060280
    if (ctx->r1 != 0) {
        // 0x80060228: or          $t5, $t3, $zero
        ctx->r13 = ctx->r11 | 0;
            goto L_80060280;
    }
    // 0x80060228: or          $t5, $t3, $zero
    ctx->r13 = ctx->r11 | 0;
    // 0x8006022C: sltu        $at, $t4, $t6
    ctx->r1 = ctx->r12 < ctx->r14 ? 1 : 0;
    // 0x80060230: bne         $at, $zero, L_80060240
    if (ctx->r1 != 0) {
        // 0x80060234: sltu        $at, $t5, $t7
        ctx->r1 = ctx->r13 < ctx->r15 ? 1 : 0;
            goto L_80060240;
    }
    // 0x80060234: sltu        $at, $t5, $t7
    ctx->r1 = ctx->r13 < ctx->r15 ? 1 : 0;
    // 0x80060238: beq         $at, $zero, L_80060280
    if (ctx->r1 == 0) {
        // 0x8006023C: nop
    
            goto L_80060280;
    }
    // 0x8006023C: nop

L_80060240:
    // 0x80060240: addiu       $t8, $t9, 0x10
    ctx->r24 = ADD32(ctx->r25, 0X10);
    // 0x80060244: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80060248: lw          $t3, 0x14($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X14);
    // 0x8006024C: lw          $t2, 0x10($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X10);
    // 0x80060250: sltu        $at, $t3, $t5
    ctx->r1 = ctx->r11 < ctx->r13 ? 1 : 0;
    // 0x80060254: subu        $t0, $t2, $t4
    ctx->r8 = SUB32(ctx->r10, ctx->r12);
    // 0x80060258: subu        $t0, $t0, $at
    ctx->r8 = SUB32(ctx->r8, ctx->r1);
    // 0x8006025C: subu        $t1, $t3, $t5
    ctx->r9 = SUB32(ctx->r11, ctx->r13);
    // 0x80060260: sw          $t1, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->r9;
    // 0x80060264: sw          $t0, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->r8;
    // 0x80060268: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8006026C: lw          $a0, 0x10($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X10);
    // 0x80060270: jal         0x80060314
    // 0x80060274: lw          $a1, 0x14($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X14);
    func_80060314(rdram, ctx);
        goto after_2;
    // 0x80060274: lw          $a1, 0x14($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X14);
    after_2:
    // 0x80060278: b           L_80060304
    // 0x8006027C: nop

        goto L_80060304;
    // 0x8006027C: nop

L_80060280:
    // 0x80060280: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80060284: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80060288: lw          $t2, 0x4($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X4);
    // 0x8006028C: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x80060290: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80060294: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x80060298: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x8006029C: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x800602A0: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800602A4: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x800602A8: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800602AC: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800602B0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800602B4: lw          $t6, 0x18($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X18);
    // 0x800602B8: beq         $t6, $zero, L_800602D0
    if (ctx->r14 == 0) {
        // 0x800602BC: nop
    
            goto L_800602D0;
    }
    // 0x800602BC: nop

    // 0x800602C0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800602C4: lw          $a1, 0x1C($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X1C);
    // 0x800602C8: jal         0x800534A0
    // 0x800602CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x800602CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
L_800602D0:
    // 0x800602D0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800602D4: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x800602D8: lw          $t9, 0xC($t7)
    ctx->r25 = MEM_W(ctx->r15, 0XC);
    // 0x800602DC: bne         $t8, $zero, L_800602EC
    if (ctx->r24 != 0) {
        // 0x800602E0: nop
    
            goto L_800602EC;
    }
    // 0x800602E0: nop

    // 0x800602E4: beq         $t9, $zero, L_800601B8
    if (ctx->r25 == 0) {
        // 0x800602E8: nop
    
            goto L_800601B8;
    }
    // 0x800602E8: nop

L_800602EC:
    // 0x800602EC: sw          $t8, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->r24;
    // 0x800602F0: sw          $t9, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r25;
    // 0x800602F4: jal         0x80060388
    // 0x800602F8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    osSetTimer_recomp(rdram, ctx);
        goto after_4;
    // 0x800602F8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x800602FC: b           L_800601B8
    // 0x80060300: nop

        goto L_800601B8;
    // 0x80060300: nop

L_80060304:
    // 0x80060304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80060308: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006030C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80060314(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80060314: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80060318: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006031C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80060320: jal         0x80056580
    // 0x80060324: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    __osDisableInt_recomp(rdram, ctx);
        goto after_0;
    // 0x80060324: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80060328: jal         0x80060100
    // 0x8006032C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    osGetCount_recomp(rdram, ctx);
        goto after_1;
    // 0x8006032C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80060330: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80060334: sw          $v0, -0x1FC0($at)
    MEM_W(-0X1FC0, ctx->r1) = ctx->r2;
    // 0x80060338: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8006033C: lw          $t6, -0x1FC0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X1FC0);
    // 0x80060340: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80060344: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80060348: or          $t9, $t6, $zero
    ctx->r25 = ctx->r14 | 0;
    // 0x8006034C: addu        $t3, $t9, $t1
    ctx->r11 = ADD32(ctx->r25, ctx->r9);
    // 0x80060350: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80060354: sltu        $at, $t3, $t1
    ctx->r1 = ctx->r11 < ctx->r9 ? 1 : 0;
    // 0x80060358: addu        $t2, $at, $t8
    ctx->r10 = ADD32(ctx->r1, ctx->r24);
    // 0x8006035C: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x80060360: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x80060364: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80060368: jal         0x80062B70
    // 0x8006036C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    func_80062B70(rdram, ctx);
        goto after_2;
    // 0x8006036C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_2:
    // 0x80060370: jal         0x800565A0
    // 0x80060374: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    __osRestoreInt_recomp(rdram, ctx);
        goto after_3;
    // 0x80060374: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80060378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006037C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80060380: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80060510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80060510: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80060514: lw          $t6, -0x201C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X201C);
    // 0x80060518: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8006051C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80060520: addiu       $t7, $t6, 0x14
    ctx->r15 = ADD32(ctx->r14, 0X14);
    // 0x80060524: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x80060528: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x8006052C: lhu         $t8, 0x1A($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X1A);
    // 0x80060530: lui         $t2, 0xA460
    ctx->r10 = S32(0XA460 << 16);
    // 0x80060534: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80060538: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8006053C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80060540: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80060544: addiu       $t1, $t0, 0x18
    ctx->r9 = ADD32(ctx->r8, 0X18);
    // 0x80060548: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x8006054C: lw          $t3, 0x10($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10);
    // 0x80060550: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x80060554: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80060558: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x8006055C: beq         $t5, $zero, L_80060590
    if (ctx->r13 == 0) {
        // 0x80060560: nop
    
            goto L_80060590;
    }
    // 0x80060560: nop

    // 0x80060564: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x80060568: lw          $t6, 0x31F0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X31F0);
    // 0x8006056C: addiu       $at, $zero, -0x801
    ctx->r1 = ADD32(0, -0X801);
    // 0x80060570: addiu       $t7, $zero, 0x1D
    ctx->r15 = ADD32(0, 0X1D);
    // 0x80060574: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x80060578: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8006057C: sw          $t8, 0x31F0($at)
    MEM_W(0X31F0, ctx->r1) = ctx->r24;
    // 0x80060580: jal         0x80060C9C
    // 0x80060584: sw          $t7, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r15;
    func_80060C9C(rdram, ctx);
        goto after_0;
    // 0x80060584: sw          $t7, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r15;
    after_0:
    // 0x80060588: b           L_80060BA4
    // 0x8006058C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80060BA4;
    // 0x8006058C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80060590:
    // 0x80060590: lui         $t9, 0xA460
    ctx->r25 = S32(0XA460 << 16);
    // 0x80060594: lw          $t1, 0x10($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X10);
    // 0x80060598: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x8006059C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800605A0: andi        $t3, $t2, 0x3
    ctx->r11 = ctx->r10 & 0X3;
    // 0x800605A4: beq         $t3, $zero, L_800605C8
    if (ctx->r11 == 0) {
        // 0x800605A8: nop
    
            goto L_800605C8;
    }
    // 0x800605A8: nop

L_800605AC:
    // 0x800605AC: lui         $t4, 0xA460
    ctx->r12 = S32(0XA460 << 16);
    // 0x800605B0: lw          $t5, 0x10($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X10);
    // 0x800605B4: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x800605B8: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800605BC: andi        $t8, $t6, 0x3
    ctx->r24 = ctx->r14 & 0X3;
    // 0x800605C0: bne         $t8, $zero, L_800605AC
    if (ctx->r24 != 0) {
        // 0x800605C4: nop
    
            goto L_800605AC;
    }
    // 0x800605C4: nop

L_800605C8:
    // 0x800605C8: lui         $t7, 0xA500
    ctx->r15 = S32(0XA500 << 16);
    // 0x800605CC: lw          $t0, 0x508($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X508);
    // 0x800605D0: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x800605D4: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x800605D8: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800605DC: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x800605E0: beq         $t1, $zero, L_80060648
    if (ctx->r9 == 0) {
        // 0x800605E4: nop
    
            goto L_80060648;
    }
    // 0x800605E4: nop

    // 0x800605E8: lui         $t2, 0xA460
    ctx->r10 = S32(0XA460 << 16);
    // 0x800605EC: lw          $t3, 0x10($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10);
    // 0x800605F0: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x800605F4: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800605F8: andi        $t5, $t4, 0x3
    ctx->r13 = ctx->r12 & 0X3;
    // 0x800605FC: beq         $t5, $zero, L_80060620
    if (ctx->r13 == 0) {
        // 0x80060600: nop
    
            goto L_80060620;
    }
    // 0x80060600: nop

L_80060604:
    // 0x80060604: lui         $t6, 0xA460
    ctx->r14 = S32(0XA460 << 16);
    // 0x80060608: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x8006060C: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x80060610: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80060614: andi        $t0, $t7, 0x3
    ctx->r8 = ctx->r15 & 0X3;
    // 0x80060618: bne         $t0, $zero, L_80060604
    if (ctx->r8 != 0) {
        // 0x8006061C: nop
    
            goto L_80060604;
    }
    // 0x8006061C: nop

L_80060620:
    // 0x80060620: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80060624: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x80060628: lui         $t3, 0xA500
    ctx->r11 = S32(0XA500 << 16);
    // 0x8006062C: lw          $t1, 0x10($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X10);
    // 0x80060630: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80060634: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x80060638: sw          $t2, 0x510($t3)
    MEM_W(0X510, ctx->r11) = ctx->r10;
    // 0x8006063C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80060640: b           L_80060BA4
    // 0x80060644: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
        goto L_80060BA4;
    // 0x80060644: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
L_80060648:
    // 0x80060648: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8006064C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80060650: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80060654: bne         $t6, $at, L_80060664
    if (ctx->r14 != ctx->r1) {
        // 0x80060658: nop
    
            goto L_80060664;
    }
    // 0x80060658: nop

    // 0x8006065C: b           L_80060BA4
    // 0x80060660: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80060BA4;
    // 0x80060660: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80060664:
    // 0x80060664: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80060668: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8006066C: and         $t7, $t8, $at
    ctx->r15 = ctx->r24 & ctx->r1;
    // 0x80060670: beq         $t7, $zero, L_800606FC
    if (ctx->r15 == 0) {
        // 0x80060674: nop
    
            goto L_800606FC;
    }
    // 0x80060674: nop

    // 0x80060678: lui         $t0, 0xA460
    ctx->r8 = S32(0XA460 << 16);
    // 0x8006067C: lw          $t9, 0x10($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X10);
    // 0x80060680: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x80060684: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80060688: andi        $t2, $t1, 0x3
    ctx->r10 = ctx->r9 & 0X3;
    // 0x8006068C: beq         $t2, $zero, L_800606B0
    if (ctx->r10 == 0) {
        // 0x80060690: nop
    
            goto L_800606B0;
    }
    // 0x80060690: nop

L_80060694:
    // 0x80060694: lui         $t3, 0xA460
    ctx->r11 = S32(0XA460 << 16);
    // 0x80060698: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x8006069C: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x800606A0: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800606A4: andi        $t6, $t5, 0x3
    ctx->r14 = ctx->r13 & 0X3;
    // 0x800606A8: bne         $t6, $zero, L_80060694
    if (ctx->r14 != 0) {
        // 0x800606AC: nop
    
            goto L_80060694;
    }
    // 0x800606AC: nop

L_800606B0:
    // 0x800606B0: lui         $t8, 0xA500
    ctx->r24 = S32(0XA500 << 16);
    // 0x800606B4: lw          $t7, 0x508($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X508);
    // 0x800606B8: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800606BC: addiu       $t0, $zero, 0x16
    ctx->r8 = ADD32(0, 0X16);
    // 0x800606C0: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x800606C4: jal         0x80060C9C
    // 0x800606C8: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    func_80060C9C(rdram, ctx);
        goto after_1;
    // 0x800606C8: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    after_1:
    // 0x800606CC: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x800606D0: lui         $t2, 0xA460
    ctx->r10 = S32(0XA460 << 16);
    // 0x800606D4: sw          $t1, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->r9;
    // 0x800606D8: lui         $t3, 0x8007
    ctx->r11 = S32(0X8007 << 16);
    // 0x800606DC: lw          $t3, 0x31F0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X31F0);
    // 0x800606E0: lui         $at, 0x10
    ctx->r1 = S32(0X10 << 16);
    // 0x800606E4: ori         $at, $at, 0x401
    ctx->r1 = ctx->r1 | 0X401;
    // 0x800606E8: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x800606EC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800606F0: sw          $t4, 0x31F0($at)
    MEM_W(0X31F0, ctx->r1) = ctx->r12;
    // 0x800606F4: b           L_80060BA4
    // 0x800606F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80060BA4;
    // 0x800606F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800606FC:
    // 0x800606FC: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80060700: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80060704: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80060708: bne         $t6, $at, L_800607F8
    if (ctx->r14 != ctx->r1) {
        // 0x8006070C: nop
    
            goto L_800607F8;
    }
    // 0x8006070C: nop

    // 0x80060710: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80060714: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80060718: and         $t7, $t8, $at
    ctx->r15 = ctx->r24 & ctx->r1;
    // 0x8006071C: bne         $t7, $zero, L_800607A4
    if (ctx->r15 != 0) {
        // 0x80060720: nop
    
            goto L_800607A4;
    }
    // 0x80060720: nop

    // 0x80060724: lhu         $t1, 0x4($t5)
    ctx->r9 = MEM_HU(ctx->r13, 0X4);
    // 0x80060728: lw          $t0, 0x8($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X8);
    // 0x8006072C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80060730: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80060734: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80060738: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8006073C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80060740: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80060744: addiu       $t9, $t0, 0x1
    ctx->r25 = ADD32(ctx->r8, 0X1);
    // 0x80060748: beq         $t9, $t2, L_80060768
    if (ctx->r25 == ctx->r10) {
        // 0x8006074C: nop
    
            goto L_80060768;
    }
    // 0x8006074C: nop

    // 0x80060750: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80060754: addiu       $t3, $zero, 0x18
    ctx->r11 = ADD32(0, 0X18);
    // 0x80060758: jal         0x80060BB4
    // 0x8006075C: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    func_80060BB4(rdram, ctx);
        goto after_2;
    // 0x8006075C: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    after_2:
    // 0x80060760: b           L_80060BA4
    // 0x80060764: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80060BA4;
    // 0x80060764: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80060768:
    // 0x80060768: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8006076C: lui         $t8, 0xA460
    ctx->r24 = S32(0XA460 << 16);
    // 0x80060770: sw          $t6, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r14;
    // 0x80060774: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x80060778: lw          $t7, 0x31F0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X31F0);
    // 0x8006077C: lui         $at, 0x10
    ctx->r1 = S32(0X10 << 16);
    // 0x80060780: ori         $at, $at, 0x401
    ctx->r1 = ctx->r1 | 0X401;
    // 0x80060784: or          $t0, $t7, $at
    ctx->r8 = ctx->r15 | ctx->r1;
    // 0x80060788: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8006078C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80060790: sw          $t0, 0x31F0($at)
    MEM_W(0X31F0, ctx->r1) = ctx->r8;
    // 0x80060794: jal         0x80060C9C
    // 0x80060798: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
    func_80060C9C(rdram, ctx);
        goto after_3;
    // 0x80060798: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
    after_3:
    // 0x8006079C: b           L_80060BA4
    // 0x800607A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80060BA4;
    // 0x800607A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800607A4:
    // 0x800607A4: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800607A8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800607AC: lui         $a2, 0x500
    ctx->r6 = S32(0X500 << 16);
    // 0x800607B0: lw          $t9, 0x4($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X4);
    // 0x800607B4: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x800607B8: ori         $a2, $a2, 0x400
    ctx->r6 = ctx->r6 | 0X400;
    // 0x800607BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800607C0: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x800607C4: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x800607C8: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800607CC: lw          $t6, 0x8($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X8);
    // 0x800607D0: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x800607D4: sw          $t8, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r24;
    // 0x800607D8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800607DC: lw          $a0, -0x201C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X201C);
    // 0x800607E0: lw          $t0, 0xC($t7)
    ctx->r8 = MEM_W(ctx->r15, 0XC);
    // 0x800607E4: lw          $a3, 0x4($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X4);
    // 0x800607E8: jal         0x8005FA40
    // 0x800607EC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_8005FA40(rdram, ctx);
        goto after_4;
    // 0x800607EC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_4:
    // 0x800607F0: b           L_80060BA4
    // 0x800607F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80060BA4;
    // 0x800607F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800607F8:
    // 0x800607F8: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x800607FC: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x80060800: bne         $t9, $zero, L_80060B90
    if (ctx->r25 != 0) {
        // 0x80060804: nop
    
            goto L_80060B90;
    }
    // 0x80060804: nop

    // 0x80060808: lhu         $t2, 0x4($t5)
    ctx->r10 = MEM_HU(ctx->r13, 0X4);
    // 0x8006080C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80060810: bne         $t2, $at, L_80060870
    if (ctx->r10 != ctx->r1) {
        // 0x80060814: nop
    
            goto L_80060870;
    }
    // 0x80060814: nop

    // 0x80060818: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8006081C: lw          $t3, 0x8($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X8);
    // 0x80060820: lw          $t6, 0x10($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X10);
    // 0x80060824: addiu       $t8, $t6, 0x11
    ctx->r24 = ADD32(ctx->r14, 0X11);
    // 0x80060828: slt         $at, $t8, $t3
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8006082C: beq         $at, $zero, L_80060844
    if (ctx->r1 == 0) {
        // 0x80060830: nop
    
            goto L_80060844;
    }
    // 0x80060830: nop

    // 0x80060834: jal         0x80060BB4
    // 0x80060838: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    func_80060BB4(rdram, ctx);
        goto after_5;
    // 0x80060838: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    after_5:
    // 0x8006083C: b           L_80060BA4
    // 0x80060840: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80060BA4;
    // 0x80060840: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80060844:
    // 0x80060844: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80060848: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8006084C: and         $t7, $t4, $at
    ctx->r15 = ctx->r12 & ctx->r1;
    // 0x80060850: bne         $t7, $zero, L_80060884
    if (ctx->r15 != 0) {
        // 0x80060854: nop
    
            goto L_80060884;
    }
    // 0x80060854: nop

    // 0x80060858: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8006085C: addiu       $t0, $zero, 0x17
    ctx->r8 = ADD32(0, 0X17);
    // 0x80060860: jal         0x80060BB4
    // 0x80060864: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    func_80060BB4(rdram, ctx);
        goto after_6;
    // 0x80060864: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    after_6:
    // 0x80060868: b           L_80060BA4
    // 0x8006086C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80060BA4;
    // 0x8006086C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80060870:
    // 0x80060870: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80060874: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80060878: lw          $t6, 0xC($t2)
    ctx->r14 = MEM_W(ctx->r10, 0XC);
    // 0x8006087C: addu        $t3, $t5, $t6
    ctx->r11 = ADD32(ctx->r13, ctx->r14);
    // 0x80060880: sw          $t3, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r11;
L_80060884:
    // 0x80060884: lui         $t8, 0xA500
    ctx->r24 = S32(0XA500 << 16);
    // 0x80060888: lw          $t1, 0x510($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X510);
    // 0x8006088C: lui         $at, 0x20
    ctx->r1 = S32(0X20 << 16);
    // 0x80060890: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x80060894: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80060898: and         $t7, $t4, $at
    ctx->r15 = ctx->r12 & ctx->r1;
    // 0x8006089C: beq         $t7, $zero, L_800608B0
    if (ctx->r15 == 0) {
        // 0x800608A0: lui         $at, 0x40
        ctx->r1 = S32(0X40 << 16);
            goto L_800608B0;
    }
    // 0x800608A0: lui         $at, 0x40
    ctx->r1 = S32(0X40 << 16);
    // 0x800608A4: and         $t0, $t4, $at
    ctx->r8 = ctx->r12 & ctx->r1;
    // 0x800608A8: bne         $t0, $zero, L_800608C4
    if (ctx->r8 != 0) {
        // 0x800608AC: nop
    
            goto L_800608C4;
    }
    // 0x800608AC: nop

L_800608B0:
    // 0x800608B0: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800608B4: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x800608B8: and         $t5, $t9, $at
    ctx->r13 = ctx->r25 & ctx->r1;
    // 0x800608BC: beq         $t5, $zero, L_80060948
    if (ctx->r13 == 0) {
        // 0x800608C0: nop
    
            goto L_80060948;
    }
    // 0x800608C0: nop

L_800608C4:
    // 0x800608C4: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800608C8: lw          $t3, 0x10($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X10);
    // 0x800608CC: sltiu       $at, $t3, 0x4
    ctx->r1 = ctx->r11 < 0X4 ? 1 : 0;
    // 0x800608D0: bne         $at, $zero, L_80060914
    if (ctx->r1 != 0) {
        // 0x800608D4: nop
    
            goto L_80060914;
    }
    // 0x800608D4: nop

    // 0x800608D8: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800608DC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800608E0: lhu         $t8, 0x4($t2)
    ctx->r24 = MEM_HU(ctx->r10, 0X4);
    // 0x800608E4: bne         $t8, $at, L_800608FC
    if (ctx->r24 != ctx->r1) {
        // 0x800608E8: nop
    
            goto L_800608FC;
    }
    // 0x800608E8: nop

    // 0x800608EC: lw          $t1, 0x8($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X8);
    // 0x800608F0: slti        $at, $t1, 0x53
    ctx->r1 = SIGNED(ctx->r9) < 0X53 ? 1 : 0;
    // 0x800608F4: bne         $at, $zero, L_80060938
    if (ctx->r1 != 0) {
        // 0x800608F8: nop
    
            goto L_80060938;
    }
    // 0x800608F8: nop

L_800608FC:
    // 0x800608FC: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80060900: addiu       $t7, $zero, 0x17
    ctx->r15 = ADD32(0, 0X17);
    // 0x80060904: jal         0x80060BB4
    // 0x80060908: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    func_80060BB4(rdram, ctx);
        goto after_7;
    // 0x80060908: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    after_7:
    // 0x8006090C: b           L_80060BA4
    // 0x80060910: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80060BA4;
    // 0x80060910: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80060914:
    // 0x80060914: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80060918: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8006091C: lw          $t9, 0x10($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X10);
    // 0x80060920: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x80060924: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x80060928: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8006092C: addu        $t2, $t0, $t8
    ctx->r10 = ADD32(ctx->r8, ctx->r24);
    // 0x80060930: addiu       $t3, $t6, 0x1
    ctx->r11 = ADD32(ctx->r14, 0X1);
    // 0x80060934: sw          $t3, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->r11;
L_80060938:
    // 0x80060938: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8006093C: lw          $t7, 0x10($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X10);
    // 0x80060940: addiu       $t4, $t7, 0x1
    ctx->r12 = ADD32(ctx->r15, 0X1);
    // 0x80060944: sw          $t4, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r12;
L_80060948:
    // 0x80060948: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8006094C: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x80060950: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x80060954: beq         $t6, $zero, L_80060A44
    if (ctx->r14 == 0) {
        // 0x80060958: nop
    
            goto L_80060A44;
    }
    // 0x80060958: nop

    // 0x8006095C: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80060960: addiu       $at, $zero, 0x57
    ctx->r1 = ADD32(0, 0X57);
    // 0x80060964: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x80060968: beq         $t0, $at, L_80060980
    if (ctx->r8 == ctx->r1) {
        // 0x8006096C: nop
    
            goto L_80060980;
    }
    // 0x8006096C: nop

    // 0x80060970: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80060974: addiu       $t8, $zero, 0x18
    ctx->r24 = ADD32(0, 0X18);
    // 0x80060978: jal         0x80060BB4
    // 0x8006097C: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    func_80060BB4(rdram, ctx);
        goto after_8;
    // 0x8006097C: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    after_8:
L_80060980:
    // 0x80060980: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80060984: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80060988: lhu         $t7, 0x4($t2)
    ctx->r15 = MEM_HU(ctx->r10, 0X4);
    // 0x8006098C: bne         $t7, $at, L_800609D8
    if (ctx->r15 != ctx->r1) {
        // 0x80060990: nop
    
            goto L_800609D8;
    }
    // 0x80060990: nop

    // 0x80060994: lhu         $t4, 0x6($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X6);
    // 0x80060998: bne         $t4, $zero, L_800609D8
    if (ctx->r12 != 0) {
        // 0x8006099C: nop
    
            goto L_800609D8;
    }
    // 0x8006099C: nop

    // 0x800609A0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800609A4: sh          $t1, 0x6($t2)
    MEM_H(0X6, ctx->r10) = ctx->r9;
    // 0x800609A8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800609AC: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800609B0: addiu       $t7, $zero, 0x16
    ctx->r15 = ADD32(0, 0X16);
    // 0x800609B4: sw          $t5, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r13;
    // 0x800609B8: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800609BC: lw          $t0, 0x40($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X40);
    // 0x800609C0: lw          $t8, 0x48($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X48);
    // 0x800609C4: subu        $t3, $t0, $t8
    ctx->r11 = SUB32(ctx->r8, ctx->r24);
    // 0x800609C8: sw          $t3, 0x40($t9)
    MEM_W(0X40, ctx->r25) = ctx->r11;
    // 0x800609CC: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800609D0: b           L_80060A14
    // 0x800609D4: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
        goto L_80060A14;
    // 0x800609D4: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
L_800609D8:
    // 0x800609D8: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x800609DC: lui         $t2, 0xA460
    ctx->r10 = S32(0XA460 << 16);
    // 0x800609E0: sw          $t1, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->r9;
    // 0x800609E4: lui         $t5, 0x8007
    ctx->r13 = S32(0X8007 << 16);
    // 0x800609E8: lw          $t5, 0x31F0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X31F0);
    // 0x800609EC: lui         $at, 0x10
    ctx->r1 = S32(0X10 << 16);
    // 0x800609F0: ori         $at, $at, 0x401
    ctx->r1 = ctx->r1 | 0X401;
    // 0x800609F4: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800609F8: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x800609FC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80060A00: sw          $t6, 0x31F0($at)
    MEM_W(0X31F0, ctx->r1) = ctx->r14;
    // 0x80060A04: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80060A08: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x80060A0C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80060A10: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
L_80060A14:
    // 0x80060A14: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80060A18: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80060A1C: lw          $a0, -0x201C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X201C);
    // 0x80060A20: lw          $t7, 0xC($t9)
    ctx->r15 = MEM_W(ctx->r25, 0XC);
    // 0x80060A24: lw          $a3, 0x8($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X8);
    // 0x80060A28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80060A2C: sll         $t4, $t7, 2
    ctx->r12 = S32(ctx->r15 << 2);
    // 0x80060A30: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80060A34: jal         0x8005FA40
    // 0x80060A38: lui         $a2, 0x500
    ctx->r6 = S32(0X500 << 16);
    func_8005FA40(rdram, ctx);
        goto after_9;
    // 0x80060A38: lui         $a2, 0x500
    ctx->r6 = S32(0X500 << 16);
    after_9:
    // 0x80060A3C: b           L_80060BA4
    // 0x80060A40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80060BA4;
    // 0x80060A40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80060A44:
    // 0x80060A44: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80060A48: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80060A4C: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x80060A50: bne         $t2, $at, L_80060AD4
    if (ctx->r10 != ctx->r1) {
        // 0x80060A54: nop
    
            goto L_80060AD4;
    }
    // 0x80060A54: nop

    // 0x80060A58: lhu         $t5, 0x4($t1)
    ctx->r13 = MEM_HU(ctx->r9, 0X4);
    // 0x80060A5C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80060A60: bne         $t5, $at, L_80060AD4
    if (ctx->r13 != ctx->r1) {
        // 0x80060A64: nop
    
            goto L_80060AD4;
    }
    // 0x80060A64: nop

    // 0x80060A68: lhu         $t6, 0x6($t1)
    ctx->r14 = MEM_HU(ctx->r9, 0X6);
    // 0x80060A6C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80060A70: bne         $t6, $at, L_80060AD4
    if (ctx->r14 != ctx->r1) {
        // 0x80060A74: nop
    
            goto L_80060AD4;
    }
    // 0x80060A74: nop

    // 0x80060A78: addiu       $t0, $t1, 0x18
    ctx->r8 = ADD32(ctx->r9, 0X18);
    // 0x80060A7C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80060A80: lw          $t8, 0x28($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X28);
    // 0x80060A84: bne         $t8, $zero, L_80060AC8
    if (ctx->r24 != 0) {
        // 0x80060A88: nop
    
            goto L_80060AC8;
    }
    // 0x80060A88: nop

    // 0x80060A8C: lw          $t3, 0x20($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X20);
    // 0x80060A90: lw          $t9, 0x0($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X0);
    // 0x80060A94: lw          $t7, 0x4($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X4);
    // 0x80060A98: lw          $t2, 0x8($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X8);
    // 0x80060A9C: lw          $t6, 0xC($t3)
    ctx->r14 = MEM_W(ctx->r11, 0XC);
    // 0x80060AA0: or          $t4, $t9, $t7
    ctx->r12 = ctx->r25 | ctx->r15;
    // 0x80060AA4: or          $t5, $t4, $t2
    ctx->r13 = ctx->r12 | ctx->r10;
    // 0x80060AA8: or          $t0, $t6, $t5
    ctx->r8 = ctx->r14 | ctx->r13;
    // 0x80060AAC: beq         $t0, $zero, L_80060AC8
    if (ctx->r8 == 0) {
        // 0x80060AB0: nop
    
            goto L_80060AC8;
    }
    // 0x80060AB0: nop

    // 0x80060AB4: addiu       $t8, $zero, 0x18
    ctx->r24 = ADD32(0, 0X18);
    // 0x80060AB8: jal         0x80060BB4
    // 0x80060ABC: sw          $t8, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->r24;
    func_80060BB4(rdram, ctx);
        goto after_10;
    // 0x80060ABC: sw          $t8, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->r24;
    after_10:
    // 0x80060AC0: b           L_80060BA4
    // 0x80060AC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80060BA4;
    // 0x80060AC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80060AC8:
    // 0x80060AC8: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80060ACC: jal         0x80060C9C
    // 0x80060AD0: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    func_80060C9C(rdram, ctx);
        goto after_11;
    // 0x80060AD0: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    after_11:
L_80060AD4:
    // 0x80060AD4: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80060AD8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80060ADC: lw          $t4, 0x8($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X8);
    // 0x80060AE0: addiu       $t2, $t4, 0x1
    ctx->r10 = ADD32(ctx->r12, 0X1);
    // 0x80060AE4: sw          $t2, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r10;
    // 0x80060AE8: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80060AEC: and         $t6, $t3, $at
    ctx->r14 = ctx->r11 & ctx->r1;
    // 0x80060AF0: beq         $t6, $zero, L_80060B5C
    if (ctx->r14 == 0) {
        // 0x80060AF4: nop
    
            goto L_80060B5C;
    }
    // 0x80060AF4: nop

    // 0x80060AF8: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80060AFC: lw          $t0, 0x8($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X8);
    // 0x80060B00: slti        $at, $t0, 0x55
    ctx->r1 = SIGNED(ctx->r8) < 0X55 ? 1 : 0;
    // 0x80060B04: bne         $at, $zero, L_80060B24
    if (ctx->r1 != 0) {
        // 0x80060B08: nop
    
            goto L_80060B24;
    }
    // 0x80060B08: nop

    // 0x80060B0C: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80060B10: addiu       $t8, $zero, 0x18
    ctx->r24 = ADD32(0, 0X18);
    // 0x80060B14: jal         0x80060BB4
    // 0x80060B18: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    func_80060BB4(rdram, ctx);
        goto after_12;
    // 0x80060B18: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    after_12:
    // 0x80060B1C: b           L_80060BA4
    // 0x80060B20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80060BA4;
    // 0x80060B20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80060B24:
    // 0x80060B24: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80060B28: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80060B2C: lui         $a2, 0x500
    ctx->r6 = S32(0X500 << 16);
    // 0x80060B30: lw          $t4, 0xC($t9)
    ctx->r12 = MEM_W(ctx->r25, 0XC);
    // 0x80060B34: lw          $a3, 0x4($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X4);
    // 0x80060B38: ori         $a2, $a2, 0x400
    ctx->r6 = ctx->r6 | 0X400;
    // 0x80060B3C: lw          $a0, -0x201C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X201C);
    // 0x80060B40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80060B44: jal         0x8005FA40
    // 0x80060B48: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    func_8005FA40(rdram, ctx);
        goto after_13;
    // 0x80060B48: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_13:
    // 0x80060B4C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80060B50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80060B54: b           L_80060BA4
    // 0x80060B58: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
        goto L_80060BA4;
    // 0x80060B58: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
L_80060B5C:
    // 0x80060B5C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80060B60: lw          $t3, 0x8($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X8);
    // 0x80060B64: slti        $at, $t3, 0x55
    ctx->r1 = SIGNED(ctx->r11) < 0X55 ? 1 : 0;
    // 0x80060B68: beq         $at, $zero, L_80060B88
    if (ctx->r1 == 0) {
        // 0x80060B6C: nop
    
            goto L_80060B88;
    }
    // 0x80060B6C: nop

    // 0x80060B70: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80060B74: addiu       $t6, $zero, 0x18
    ctx->r14 = ADD32(0, 0X18);
    // 0x80060B78: jal         0x80060BB4
    // 0x80060B7C: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    func_80060BB4(rdram, ctx);
        goto after_14;
    // 0x80060B7C: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    after_14:
    // 0x80060B80: b           L_80060BA4
    // 0x80060B84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80060BA4;
    // 0x80060B84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80060B88:
    // 0x80060B88: b           L_80060BA4
    // 0x80060B8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80060BA4;
    // 0x80060B8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80060B90:
    // 0x80060B90: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80060B94: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80060B98: jal         0x80060BB4
    // 0x80060B9C: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    func_80060BB4(rdram, ctx);
        goto after_15;
    // 0x80060B9C: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    after_15:
    // 0x80060BA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80060BA4:
    // 0x80060BA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80060BA8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80060BAC: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80060BB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80060BB4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80060BB8: lw          $t6, -0x201C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X201C);
    // 0x80060BBC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80060BC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80060BC4: addiu       $t7, $t6, 0x14
    ctx->r15 = ADD32(ctx->r14, 0X14);
    // 0x80060BC8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80060BCC: lui         $t8, 0xA460
    ctx->r24 = S32(0XA460 << 16);
    // 0x80060BD0: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x80060BD4: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80060BD8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80060BDC: andi        $t1, $t0, 0x3
    ctx->r9 = ctx->r8 & 0X3;
    // 0x80060BE0: beq         $t1, $zero, L_80060C04
    if (ctx->r9 == 0) {
        // 0x80060BE4: nop
    
            goto L_80060C04;
    }
    // 0x80060BE4: nop

L_80060BE8:
    // 0x80060BE8: lui         $t2, 0xA460
    ctx->r10 = S32(0XA460 << 16);
    // 0x80060BEC: lw          $t3, 0x10($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10);
    // 0x80060BF0: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80060BF4: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80060BF8: andi        $t5, $t4, 0x3
    ctx->r13 = ctx->r12 & 0X3;
    // 0x80060BFC: bne         $t5, $zero, L_80060BE8
    if (ctx->r13 != 0) {
        // 0x80060C00: nop
    
            goto L_80060BE8;
    }
    // 0x80060C00: nop

L_80060C04:
    // 0x80060C04: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80060C08: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x80060C0C: lui         $t9, 0xA500
    ctx->r25 = S32(0XA500 << 16);
    // 0x80060C10: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80060C14: lui         $t0, 0xA460
    ctx->r8 = S32(0XA460 << 16);
    // 0x80060C18: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80060C1C: sw          $t8, 0x510($t9)
    MEM_W(0X510, ctx->r25) = ctx->r24;
    // 0x80060C20: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x80060C24: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80060C28: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80060C2C: andi        $t3, $t2, 0x3
    ctx->r11 = ctx->r10 & 0X3;
    // 0x80060C30: beq         $t3, $zero, L_80060C54
    if (ctx->r11 == 0) {
        // 0x80060C34: nop
    
            goto L_80060C54;
    }
    // 0x80060C34: nop

L_80060C38:
    // 0x80060C38: lui         $t4, 0xA460
    ctx->r12 = S32(0XA460 << 16);
    // 0x80060C3C: lw          $t5, 0x10($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X10);
    // 0x80060C40: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80060C44: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80060C48: andi        $t7, $t6, 0x3
    ctx->r15 = ctx->r14 & 0X3;
    // 0x80060C4C: bne         $t7, $zero, L_80060C38
    if (ctx->r15 != 0) {
        // 0x80060C50: nop
    
            goto L_80060C38;
    }
    // 0x80060C50: nop

L_80060C54:
    // 0x80060C54: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80060C58: lui         $t0, 0xA500
    ctx->r8 = S32(0XA500 << 16);
    // 0x80060C5C: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x80060C60: jal         0x80060C9C
    // 0x80060C64: sw          $t9, 0x510($t0)
    MEM_W(0X510, ctx->r8) = ctx->r25;
    func_80060C9C(rdram, ctx);
        goto after_0;
    // 0x80060C64: sw          $t9, 0x510($t0)
    MEM_W(0X510, ctx->r8) = ctx->r25;
    after_0:
    // 0x80060C68: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80060C6C: lui         $t2, 0xA460
    ctx->r10 = S32(0XA460 << 16);
    // 0x80060C70: sw          $t1, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->r9;
    // 0x80060C74: lui         $t3, 0x8007
    ctx->r11 = S32(0X8007 << 16);
    // 0x80060C78: lw          $t3, 0x31F0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X31F0);
    // 0x80060C7C: lui         $at, 0x10
    ctx->r1 = S32(0X10 << 16);
    // 0x80060C80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80060C84: ori         $at, $at, 0x401
    ctx->r1 = ctx->r1 | 0X401;
    // 0x80060C88: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x80060C8C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80060C90: sw          $t4, 0x31F0($at)
    MEM_W(0X31F0, ctx->r1) = ctx->r12;
    // 0x80060C94: jr          $ra
    // 0x80060C98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    TRACE_RETURN()
    return;
    // 0x80060C98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80060C9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80060C9C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80060CA0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80060CA4: addiu       $t6, $t6, -0x4700
    ctx->r14 = ADD32(ctx->r14, -0X4700);
    // 0x80060CA8: addiu       $t7, $t6, 0x40
    ctx->r15 = ADD32(ctx->r14, 0X40);
    // 0x80060CAC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80060CB0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80060CB4: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80060CB8: lw          $t8, 0x40($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X40);
    // 0x80060CBC: beq         $t8, $zero, L_80060D74
    if (ctx->r24 == 0) {
        // 0x80060CC0: sw          $t8, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r24;
            goto L_80060D74;
    }
    // 0x80060CC0: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x80060CC4: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x80060CC8: lw          $t0, 0x10($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X10);
    // 0x80060CCC: slt         $at, $t9, $t0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80060CD0: beq         $at, $zero, L_80060D74
    if (ctx->r1 == 0) {
        // 0x80060CD4: nop
    
            goto L_80060D74;
    }
    // 0x80060CD4: nop

    // 0x80060CD8: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80060CDC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80060CE0: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80060CE4: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x80060CE8: lw          $t5, 0x10($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X10);
    // 0x80060CEC: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80060CF0: div         $zero, $t4, $t5
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r13)));
    // 0x80060CF4: mfhi        $t7
    ctx->r15 = hi;
    // 0x80060CF8: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80060CFC: lw          $t0, 0x14($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X14);
    // 0x80060D00: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x80060D04: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80060D08: addu        $t2, $t0, $t9
    ctx->r10 = ADD32(ctx->r8, ctx->r25);
    // 0x80060D0C: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x80060D10: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80060D14: bne         $t5, $zero, L_80060D20
    if (ctx->r13 != 0) {
        // 0x80060D18: nop
    
            goto L_80060D20;
    }
    // 0x80060D18: nop

    // 0x80060D1C: break       7
    do_break(2147880220);
L_80060D20:
    // 0x80060D20: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80060D24: bne         $t5, $at, L_80060D38
    if (ctx->r13 != ctx->r1) {
        // 0x80060D28: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80060D38;
    }
    // 0x80060D28: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80060D2C: bne         $t4, $at, L_80060D38
    if (ctx->r12 != ctx->r1) {
        // 0x80060D30: nop
    
            goto L_80060D38;
    }
    // 0x80060D30: nop

    // 0x80060D34: break       6
    do_break(2147880244);
L_80060D38:
    // 0x80060D38: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x80060D3C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80060D40: sw          $t5, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r13;
    // 0x80060D44: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80060D48: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80060D4C: lw          $t1, 0x0($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X0);
    // 0x80060D50: beq         $t1, $zero, L_80060D74
    if (ctx->r9 == 0) {
        // 0x80060D54: nop
    
            goto L_80060D74;
    }
    // 0x80060D54: nop

    // 0x80060D58: jal         0x80056D74
    // 0x80060D5C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    __osPopThread_recomp(rdram, ctx);
        goto after_0;
    // 0x80060D5C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x80060D60: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80060D64: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80060D68: addiu       $a0, $a0, 0x3238
    ctx->r4 = ADD32(ctx->r4, 0X3238);
    // 0x80060D6C: jal         0x80056D2C
    // 0x80060D70: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    __osEnqueueThread_recomp(rdram, ctx);
        goto after_1;
    // 0x80060D70: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
L_80060D74:
    // 0x80060D74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80060D78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80060D7C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80060D80: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80060E90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80060E90: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80060E94: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80060E98: blez        $a2, L_80060EFC
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80060E9C: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80060EFC;
    }
    // 0x80060E9C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80060EA0: andi        $a1, $a2, 0x3
    ctx->r5 = ctx->r6 & 0X3;
    // 0x80060EA4: beq         $a1, $zero, L_80060ECC
    if (ctx->r5 == 0) {
        // 0x80060EA8: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80060ECC;
    }
    // 0x80060EA8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_80060EAC:
    // 0x80060EAC: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80060EB0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80060EB4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80060EB8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80060EBC: bne         $a0, $a3, L_80060EAC
    if (ctx->r4 != ctx->r7) {
        // 0x80060EC0: sb          $t6, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r14;
            goto L_80060EAC;
    }
    // 0x80060EC0: sb          $t6, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r14;
    // 0x80060EC4: beq         $a3, $a2, L_80060EFC
    if (ctx->r7 == ctx->r6) {
        // 0x80060EC8: nop
    
            goto L_80060EFC;
    }
    // 0x80060EC8: nop

L_80060ECC:
    // 0x80060ECC: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x80060ED0: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80060ED4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80060ED8: sb          $t7, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r15;
    // 0x80060EDC: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x80060EE0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80060EE4: sb          $t8, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r24;
    // 0x80060EE8: lbu         $t9, -0x2($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X2);
    // 0x80060EEC: sb          $t9, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r25;
    // 0x80060EF0: lbu         $t0, -0x1($v0)
    ctx->r8 = MEM_BU(ctx->r2, -0X1);
    // 0x80060EF4: bne         $a3, $a2, L_80060ECC
    if (ctx->r7 != ctx->r6) {
        // 0x80060EF8: sb          $t0, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r8;
            goto L_80060ECC;
    }
    // 0x80060EF8: sb          $t0, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r8;
L_80060EFC:
    // 0x80060EFC: jr          $ra
    // 0x80060F00: nop

    TRACE_RETURN()
    return;
    // 0x80060F00: nop

    // 0x80060F04: nop

    // 0x80060F08: nop

    // 0x80060F0C: nop

    // 0x80060F10: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x80060F14: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80060F18: lh          $t7, 0x1A($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X1A);
    // 0x80060F1C: sh          $t7, 0xC($a1)
    MEM_H(0XC, ctx->r5) = ctx->r15;
    // 0x80060F20: lw          $t8, 0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC);
    // 0x80060F24: jr          $ra
    // 0x80060F28: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    TRACE_RETURN()
    return;
    // 0x80060F28: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
;}
RECOMP_FUNC void func_80060F2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80060F2C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80060F30: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x80060F34: lh          $t7, 0xC($a1)
    ctx->r15 = MEM_H(ctx->r5, 0XC);
    // 0x80060F38: sh          $t7, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r15;
    // 0x80060F3C: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x80060F40: jr          $ra
    // 0x80060F44: sw          $t8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r24;
    TRACE_RETURN()
    return;
    // 0x80060F44: sw          $t8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_80060F48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80060F48: jr          $ra
    // 0x80060F4C: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    TRACE_RETURN()
    return;
    // 0x80060F4C: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
;}
RECOMP_FUNC void func_80060F50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80060F50: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80060F58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80060F58: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x80060F5C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80060F60: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x80060F64: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x80060F68: andi        $t7, $v0, 0x80
    ctx->r15 = ctx->r2 & 0X80;
    // 0x80060F6C: beq         $t7, $zero, L_80060F9C
    if (ctx->r15 == 0) {
        // 0x80060F70: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80060F9C;
    }
    // 0x80060F70: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80060F74: andi        $a1, $v0, 0x7F
    ctx->r5 = ctx->r2 & 0X7F;
L_80060F78:
    // 0x80060F78: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x80060F7C: sll         $t9, $a1, 7
    ctx->r25 = S32(ctx->r5 << 7);
    // 0x80060F80: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80060F84: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x80060F88: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x80060F8C: andi        $t6, $v0, 0x7F
    ctx->r14 = ctx->r2 & 0X7F;
    // 0x80060F90: andi        $t7, $v0, 0x80
    ctx->r15 = ctx->r2 & 0X80;
    // 0x80060F94: bne         $t7, $zero, L_80060F78
    if (ctx->r15 != 0) {
        // 0x80060F98: addu        $a1, $t9, $t6
        ctx->r5 = ADD32(ctx->r25, ctx->r14);
            goto L_80060F78;
    }
    // 0x80060F98: addu        $a1, $t9, $t6
    ctx->r5 = ADD32(ctx->r25, ctx->r14);
L_80060F9C:
    // 0x80060F9C: jr          $ra
    // 0x80060FA0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    TRACE_RETURN()
    return;
    // 0x80060FA0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
;}
RECOMP_FUNC void func_80060FA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80060FA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80060FA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80060FAC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80060FB0: jal         0x80060F58
    // 0x80060FB4: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    func_80060F58(rdram, ctx);
        goto after_0;
    // 0x80060FB4: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    after_0:
    // 0x80060FB8: lw          $t6, 0xC($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XC);
    // 0x80060FBC: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x80060FC0: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80060FC4: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80060FC8: sw          $t7, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r15;
    // 0x80060FCC: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x80060FD0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80060FD4: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x80060FD8: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x80060FDC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80060FE0: bne         $a0, $at, L_800610A0
    if (ctx->r4 != ctx->r1) {
        // 0x80060FE4: andi        $a1, $a0, 0xFF
        ctx->r5 = ctx->r4 & 0XFF;
            goto L_800610A0;
    }
    // 0x80060FE4: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x80060FE8: lbu         $v0, 0x0($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X0);
    // 0x80060FEC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80060FF0: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x80060FF4: sw          $t9, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r25;
    // 0x80060FF8: bne         $v0, $at, L_80061068
    if (ctx->r2 != ctx->r1) {
        // 0x80060FFC: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_80061068;
    }
    // 0x80060FFC: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80061000: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80061004: sh          $t6, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r14;
    // 0x80061008: sw          $t1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r9;
    // 0x8006100C: sb          $a1, 0x8($a3)
    MEM_B(0X8, ctx->r7) = ctx->r5;
    // 0x80061010: sb          $t0, 0x9($a3)
    MEM_B(0X9, ctx->r7) = ctx->r8;
    // 0x80061014: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x80061018: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8006101C: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x80061020: sw          $t7, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r15;
    // 0x80061024: sb          $v0, 0xA($a3)
    MEM_B(0XA, ctx->r7) = ctx->r2;
    // 0x80061028: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x8006102C: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x80061030: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x80061034: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x80061038: sb          $a0, 0xB($a3)
    MEM_B(0XB, ctx->r7) = ctx->r4;
    // 0x8006103C: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x80061040: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x80061044: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x80061048: sw          $t9, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r25;
    // 0x8006104C: sb          $a1, 0xC($a3)
    MEM_B(0XC, ctx->r7) = ctx->r5;
    // 0x80061050: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x80061054: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x80061058: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x8006105C: sw          $t6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r14;
    // 0x80061060: b           L_80061098
    // 0x80061064: sb          $a0, 0xD($a3)
    MEM_B(0XD, ctx->r7) = ctx->r4;
        goto L_80061098;
    // 0x80061064: sb          $a0, 0xD($a3)
    MEM_B(0XD, ctx->r7) = ctx->r4;
L_80061068:
    // 0x80061068: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x8006106C: bne         $v0, $at, L_80061098
    if (ctx->r2 != ctx->r1) {
        // 0x80061070: addiu       $t7, $zero, 0x4
        ctx->r15 = ADD32(0, 0X4);
            goto L_80061098;
    }
    // 0x80061070: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80061074: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
    // 0x80061078: sw          $t1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r9;
    // 0x8006107C: sb          $a1, 0x8($a3)
    MEM_B(0X8, ctx->r7) = ctx->r5;
    // 0x80061080: sb          $t0, 0x9($a3)
    MEM_B(0X9, ctx->r7) = ctx->r8;
    // 0x80061084: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x80061088: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x8006108C: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x80061090: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x80061094: sb          $a0, 0xA($a3)
    MEM_B(0XA, ctx->r7) = ctx->r4;
L_80061098:
    // 0x80061098: b           L_80061118
    // 0x8006109C: sh          $zero, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = 0;
        goto L_80061118;
    // 0x8006109C: sh          $zero, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = 0;
L_800610A0:
    // 0x800610A0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800610A4: andi        $t6, $v0, 0x80
    ctx->r14 = ctx->r2 & 0X80;
    // 0x800610A8: sh          $t9, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r25;
    // 0x800610AC: beq         $t6, $zero, L_800610D4
    if (ctx->r14 == 0) {
        // 0x800610B0: sw          $t1, 0x4($a3)
        MEM_W(0X4, ctx->r7) = ctx->r9;
            goto L_800610D4;
    }
    // 0x800610B0: sw          $t1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r9;
    // 0x800610B4: sb          $a1, 0x8($a3)
    MEM_B(0X8, ctx->r7) = ctx->r5;
    // 0x800610B8: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x800610BC: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x800610C0: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x800610C4: sw          $t7, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r15;
    // 0x800610C8: sb          $a0, 0x9($a3)
    MEM_B(0X9, ctx->r7) = ctx->r4;
    // 0x800610CC: b           L_800610E0
    // 0x800610D0: sh          $a1, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = ctx->r5;
        goto L_800610E0;
    // 0x800610D0: sh          $a1, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = ctx->r5;
L_800610D4:
    // 0x800610D4: lh          $t8, 0x1A($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X1A);
    // 0x800610D8: sb          $a0, 0x9($a3)
    MEM_B(0X9, ctx->r7) = ctx->r4;
    // 0x800610DC: sb          $t8, 0x8($a3)
    MEM_B(0X8, ctx->r7) = ctx->r24;
L_800610E0:
    // 0x800610E0: lbu         $v0, 0x8($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X8);
    // 0x800610E4: addiu       $at, $zero, 0xC0
    ctx->r1 = ADD32(0, 0XC0);
    // 0x800610E8: andi        $t9, $v0, 0xF0
    ctx->r25 = ctx->r2 & 0XF0;
    // 0x800610EC: beq         $t9, $at, L_80061114
    if (ctx->r25 == ctx->r1) {
        // 0x800610F0: addiu       $at, $zero, 0xD0
        ctx->r1 = ADD32(0, 0XD0);
            goto L_80061114;
    }
    // 0x800610F0: addiu       $at, $zero, 0xD0
    ctx->r1 = ADD32(0, 0XD0);
    // 0x800610F4: beql        $t9, $at, L_80061118
    if (ctx->r25 == ctx->r1) {
        // 0x800610F8: sb          $zero, 0xA($a3)
        MEM_B(0XA, ctx->r7) = 0;
            goto L_80061118;
    }
    goto skip_0;
    // 0x800610F8: sb          $zero, 0xA($a3)
    MEM_B(0XA, ctx->r7) = 0;
    skip_0:
    // 0x800610FC: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x80061100: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x80061104: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x80061108: sw          $t6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r14;
    // 0x8006110C: b           L_80061118
    // 0x80061110: sb          $a0, 0xA($a3)
    MEM_B(0XA, ctx->r7) = ctx->r4;
        goto L_80061118;
    // 0x80061110: sb          $a0, 0xA($a3)
    MEM_B(0XA, ctx->r7) = ctx->r4;
L_80061114:
    // 0x80061114: sb          $zero, 0xA($a3)
    MEM_B(0XA, ctx->r7) = 0;
L_80061118:
    // 0x80061118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006111C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80061120: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80061128(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80061128: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8006112C: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80061130: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80061134: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80061138: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006113C: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80061140: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x80061144: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80061148: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8006114C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80061150: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80061154: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80061158: bne         $a2, $zero, L_80061178
    if (ctx->r6 != 0) {
        // 0x8006115C: sw          $s2, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r18;
            goto L_80061178;
    }
    // 0x8006115C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80061160: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80061164: sh          $zero, 0xC($a1)
    MEM_H(0XC, ctx->r5) = 0;
    // 0x80061168: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x8006116C: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    // 0x80061170: b           L_8006121C
    // 0x80061174: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
        goto L_8006121C;
    // 0x80061174: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
L_80061178:
    // 0x80061178: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x8006117C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80061180: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x80061184: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x80061188: lh          $t8, 0x1A($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X1A);
    // 0x8006118C: addiu       $s2, $sp, 0x50
    ctx->r18 = ADD32(ctx->r29, 0X50);
    // 0x80061190: sh          $t8, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r24;
    // 0x80061194: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x80061198: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x8006119C: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x800611A0: sh          $zero, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = 0;
    // 0x800611A4: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x800611A8: sw          $t0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r8;
    // 0x800611AC: lw          $s4, 0x8($s0)
    ctx->r20 = MEM_W(ctx->r16, 0X8);
L_800611B0:
    // 0x800611B0: lh          $s5, 0x1A($s0)
    ctx->r21 = MEM_H(ctx->r16, 0X1A);
    // 0x800611B4: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x800611B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800611BC: jal         0x80060FA4
    // 0x800611C0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80060FA4(rdram, ctx);
        goto after_0;
    // 0x800611C0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x800611C4: lh          $t1, 0x50($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X50);
    // 0x800611C8: bnel        $t1, $s3, L_800611E4
    if (ctx->r9 != ctx->r19) {
        // 0x800611CC: lw          $v0, 0xC($s0)
        ctx->r2 = MEM_W(ctx->r16, 0XC);
            goto L_800611E4;
    }
    goto skip_0;
    // 0x800611CC: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    skip_0:
    // 0x800611D0: lw          $s4, 0x8($s0)
    ctx->r20 = MEM_W(ctx->r16, 0X8);
    // 0x800611D4: lh          $s5, 0x1A($s0)
    ctx->r21 = MEM_H(ctx->r16, 0X1A);
    // 0x800611D8: b           L_800611F0
    // 0x800611DC: lw          $s6, 0xC($s0)
    ctx->r22 = MEM_W(ctx->r16, 0XC);
        goto L_800611F0;
    // 0x800611DC: lw          $s6, 0xC($s0)
    ctx->r22 = MEM_W(ctx->r16, 0XC);
    // 0x800611E0: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
L_800611E4:
    // 0x800611E4: sltu        $at, $v0, $s1
    ctx->r1 = ctx->r2 < ctx->r17 ? 1 : 0;
    // 0x800611E8: bnel        $at, $zero, L_800611B0
    if (ctx->r1 != 0) {
        // 0x800611EC: lw          $s4, 0x8($s0)
        ctx->r20 = MEM_W(ctx->r16, 0X8);
            goto L_800611B0;
    }
    goto skip_1;
    // 0x800611EC: lw          $s4, 0x8($s0)
    ctx->r20 = MEM_W(ctx->r16, 0X8);
    skip_1:
L_800611F0:
    // 0x800611F0: sw          $s4, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r20;
    // 0x800611F4: sh          $s5, 0xC($s7)
    MEM_H(0XC, ctx->r23) = ctx->r21;
    // 0x800611F8: sw          $s6, 0x4($s7)
    MEM_W(0X4, ctx->r23) = ctx->r22;
    // 0x800611FC: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
    // 0x80061200: sw          $t2, 0x8($s7)
    MEM_W(0X8, ctx->r23) = ctx->r10;
    // 0x80061204: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x80061208: sw          $t3, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r11;
    // 0x8006120C: lh          $t4, 0x3E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X3E);
    // 0x80061210: sh          $t4, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r12;
    // 0x80061214: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80061218: sw          $t5, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r13;
L_8006121C:
    // 0x8006121C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80061220: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80061224: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80061228: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8006122C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80061230: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80061234: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80061238: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8006123C: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80061240: jr          $ra
    // 0x80061244: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    TRACE_RETURN()
    return;
    // 0x80061244: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80061248(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80061248: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8006124C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80061250: ldc1        $f6, -0x6820($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X6820);
    // 0x80061254: lh          $t6, 0x18($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X18);
    // 0x80061258: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x8006125C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80061260: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80061264: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80061268: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x8006126C: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x80061270: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80061274: mul.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x80061278: bgezl       $a2, L_80061294
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8006127C: div.d       $f8, $f18, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f18.d, ctx->f6.d);
            goto L_80061294;
    }
    goto skip_0;
    // 0x8006127C: div.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f18.d, ctx->f6.d);
    skip_0:
    // 0x80061280: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80061284: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80061288: nop

    // 0x8006128C: add.d       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f6.d + ctx->f10.d;
    // 0x80061290: div.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f18.d, ctx->f6.d);
L_80061294:
    // 0x80061294: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80061298: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8006129C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800612A0: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x800612A4: nop

    // 0x800612A8: cvt.w.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_D(ctx->f8.d);
    // 0x800612AC: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x800612B0: nop

    // 0x800612B4: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800612B8: beql        $v0, $zero, L_80061314
    if (ctx->r2 == 0) {
        // 0x800612BC: mfc1        $v0, $f16
        ctx->r2 = (int32_t)ctx->f16.u32l;
            goto L_80061314;
    }
    goto skip_1;
    // 0x800612BC: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    skip_1:
    // 0x800612C0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800612C4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800612C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800612CC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800612D0: sub.d       $f16, $f8, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f16.d = ctx->f8.d - ctx->f16.d;
    // 0x800612D4: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x800612D8: nop

    // 0x800612DC: cvt.w.d     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_D(ctx->f16.d);
    // 0x800612E0: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x800612E4: nop

    // 0x800612E8: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800612EC: bnel        $v0, $zero, L_80061308
    if (ctx->r2 != 0) {
        // 0x800612F0: ctc1        $t7, $FpcCsr
        set_cop1_cs(ctx->r15);
            goto L_80061308;
    }
    goto skip_2;
    // 0x800612F0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    skip_2:
    // 0x800612F4: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x800612F8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800612FC: jr          $ra
    // 0x80061300: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    TRACE_RETURN()
    return;
    // 0x80061300: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    // 0x80061304: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
L_80061308:
    // 0x80061308: jr          $ra
    // 0x8006130C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    TRACE_RETURN()
    return;
    // 0x8006130C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80061310: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
L_80061314:
    // 0x80061314: nop

    // 0x80061318: bltzl       $v0, L_80061308
    if (SIGNED(ctx->r2) < 0) {
        // 0x8006131C: ctc1        $t7, $FpcCsr
        set_cop1_cs(ctx->r15);
            goto L_80061308;
    }
    goto skip_3;
    // 0x8006131C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    skip_3:
    // 0x80061320: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80061324: jr          $ra
    TRACE_RETURN()
    return;
;}
