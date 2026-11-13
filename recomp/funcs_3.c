#include "recomp.h"
#include "trace.h"
#include "funcs.h"

RECOMP_FUNC void func_8000523C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000523C: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80005240: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x80005244: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x80005248: sw          $a2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r6;
    // 0x8000524C: jr          $ra
    // 0x80005250: addiu       $v0, $a0, 0xC
    ctx->r2 = ADD32(ctx->r4, 0XC);
    TRACE_RETURN()
    return;
    // 0x80005250: addiu       $v0, $a0, 0xC
    ctx->r2 = ADD32(ctx->r4, 0XC);
;}
RECOMP_FUNC void func_80005254(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80005254: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80005258: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8000525C: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x80005260: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x80005264: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x80005268: addiu       $v0, $a0, 0xC
    ctx->r2 = ADD32(ctx->r4, 0XC);
    // 0x8000526C: jr          $ra
    // 0x80005270: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    TRACE_RETURN()
    return;
    // 0x80005270: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_80005274(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80005274: addiu       $v1, $a3, 0x3
    ctx->r3 = ADD32(ctx->r7, 0X3);
    // 0x80005278: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8000527C: and         $t6, $v1, $at
    ctx->r14 = ctx->r3 & ctx->r1;
    // 0x80005280: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x80005284: andi        $a1, $t6, 0xF
    ctx->r5 = ctx->r14 & 0XF;
    // 0x80005288: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x8000528C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80005290: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x80005294: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x80005298: beq         $a1, $zero, L_800052C4
    if (ctx->r5 == 0) {
        // 0x8000529C: addiu       $t1, $a0, 0x8
        ctx->r9 = ADD32(ctx->r4, 0X8);
            goto L_800052C4;
    }
    // 0x8000529C: addiu       $t1, $a0, 0x8
    ctx->r9 = ADD32(ctx->r4, 0X8);
    // 0x800052A0: addu        $a0, $a1, $t6
    ctx->r4 = ADD32(ctx->r5, ctx->r14);
L_800052A4:
    // 0x800052A4: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800052A8: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x800052AC: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x800052B0: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800052B4: bne         $a0, $v0, L_800052A4
    if (ctx->r4 != ctx->r2) {
        // 0x800052B8: sw          $t7, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r15;
            goto L_800052A4;
    }
    // 0x800052B8: sw          $t7, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r15;
    // 0x800052BC: beq         $v0, $zero, L_800052F4
    if (ctx->r2 == 0) {
        // 0x800052C0: nop
    
            goto L_800052F4;
    }
    // 0x800052C0: nop

L_800052C4:
    // 0x800052C4: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800052C8: addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // 0x800052CC: addiu       $t1, $t1, 0x10
    ctx->r9 = ADD32(ctx->r9, 0X10);
    // 0x800052D0: sw          $t8, -0x10($t1)
    MEM_W(-0X10, ctx->r9) = ctx->r24;
    // 0x800052D4: lw          $t9, 0x4($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X4);
    // 0x800052D8: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x800052DC: sw          $t9, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->r25;
    // 0x800052E0: lw          $t2, -0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, -0X8);
    // 0x800052E4: sw          $t2, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->r10;
    // 0x800052E8: lw          $t3, -0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, -0X4);
    // 0x800052EC: bne         $v0, $zero, L_800052C4
    if (ctx->r2 != 0) {
        // 0x800052F0: sw          $t3, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r11;
            goto L_800052C4;
    }
    // 0x800052F0: sw          $t3, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r11;
L_800052F4:
    // 0x800052F4: jr          $ra
    // 0x800052F8: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    TRACE_RETURN()
    return;
    // 0x800052F8: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
;}
RECOMP_FUNC void func_800052FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800052FC: addiu       $sp, $sp, -0x140
    ctx->r29 = ADD32(ctx->r29, -0X140);
    // 0x80005300: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80005304: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80005308: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000530C: addiu       $s1, $sp, 0x3C
    ctx->r17 = ADD32(ctx->r29, 0X3C);
    // 0x80005310: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80005314: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80005318: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000531C: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80005320: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80005324: jal         0x800050B0
    // 0x80005328: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800050B0(rdram, ctx);
        goto after_0;
    // 0x80005328: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x8000532C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80005330: jal         0x80005160
    // 0x80005334: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80005160(rdram, ctx);
        goto after_1;
    // 0x80005334: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80005338: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8000533C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80005340: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80005344: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x80005348: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x8000534C: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80005350: beq         $at, $zero, L_800053C4
    if (ctx->r1 == 0) {
        // 0x80005354: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800053C4;
    }
    // 0x80005354: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80005358:
    // 0x80005358: jal         0x80005160
    // 0x8000535C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80005160(rdram, ctx);
        goto after_2;
    // 0x8000535C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80005360: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80005364: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80005368: addu        $t2, $s1, $t1
    ctx->r10 = ADD32(ctx->r17, ctx->r9);
    // 0x8000536C: lw          $v1, 0x8($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X8);
    // 0x80005370: bne         $v1, $s3, L_8000537C
    if (ctx->r3 != ctx->r19) {
        // 0x80005374: sra         $v0, $v1, 24
        ctx->r2 = S32(SIGNED(ctx->r3) >> 24);
            goto L_8000537C;
    }
    // 0x80005374: sra         $v0, $v1, 24
    ctx->r2 = S32(SIGNED(ctx->r3) >> 24);
    // 0x80005378: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8000537C:
    // 0x8000537C: slti        $at, $v0, 0x41
    ctx->r1 = SIGNED(ctx->r2) < 0X41 ? 1 : 0;
    // 0x80005380: bne         $at, $zero, L_8000539C
    if (ctx->r1 != 0) {
        // 0x80005384: slti        $at, $v0, 0x5B
        ctx->r1 = SIGNED(ctx->r2) < 0X5B ? 1 : 0;
            goto L_8000539C;
    }
    // 0x80005384: slti        $at, $v0, 0x5B
    ctx->r1 = SIGNED(ctx->r2) < 0X5B ? 1 : 0;
    // 0x80005388: beq         $at, $zero, L_8000539C
    if (ctx->r1 == 0) {
        // 0x8000538C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8000539C;
    }
    // 0x8000538C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80005390: jal         0x800052FC
    // 0x80005394: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800052FC(rdram, ctx);
        goto after_3;
    // 0x80005394: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_3:
    // 0x80005398: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
L_8000539C:
    // 0x8000539C: jal         0x800051C4
    // 0x800053A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800051C4(rdram, ctx);
        goto after_4;
    // 0x800053A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x800053A4: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x800053A8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800053AC: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x800053B0: addu        $t5, $s1, $t4
    ctx->r13 = ADD32(ctx->r17, ctx->r12);
    // 0x800053B4: lw          $t6, 0x10($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10);
    // 0x800053B8: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800053BC: bnel        $at, $zero, L_80005358
    if (ctx->r1 != 0) {
        // 0x800053C0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80005358;
    }
    goto skip_0;
    // 0x800053C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
L_800053C4:
    // 0x800053C4: jal         0x800051C4
    // 0x800053C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800051C4(rdram, ctx);
        goto after_5;
    // 0x800053C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x800053CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800053D0: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800053D4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800053D8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800053DC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800053E0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800053E4: jr          $ra
    // 0x800053E8: addiu       $sp, $sp, 0x140
    ctx->r29 = ADD32(ctx->r29, 0X140);
    TRACE_RETURN()
    return;
    // 0x800053E8: addiu       $sp, $sp, 0x140
    ctx->r29 = ADD32(ctx->r29, 0X140);
;}
RECOMP_FUNC void func_800053EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800053EC: jr          $ra
    // 0x800053F0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    TRACE_RETURN()
    return;
    // 0x800053F0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80005400(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80005400: sltiu       $at, $a0, 0x2
    ctx->r1 = ctx->r4 < 0X2 ? 1 : 0;
    // 0x80005404: bne         $at, $zero, L_80005424
    if (ctx->r1 != 0) {
        // 0x80005408: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80005424;
    }
    // 0x80005408: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000540C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80005410:
    // 0x80005410: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80005414: sllv        $t7, $t6, $v1
    ctx->r15 = S32(ctx->r14 << (ctx->r3 & 31));
    // 0x80005418: sltu        $at, $t7, $a0
    ctx->r1 = ctx->r15 < ctx->r4 ? 1 : 0;
    // 0x8000541C: bnel        $at, $zero, L_80005410
    if (ctx->r1 != 0) {
        // 0x80005420: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80005410;
    }
    goto skip_0;
    // 0x80005420: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
L_80005424:
    // 0x80005424: jr          $ra
    // 0x80005428: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    TRACE_RETURN()
    return;
    // 0x80005428: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8000542C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000542C: sltiu       $at, $a0, 0x2
    ctx->r1 = ctx->r4 < 0X2 ? 1 : 0;
    // 0x80005430: bne         $at, $zero, L_80005450
    if (ctx->r1 != 0) {
        // 0x80005434: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80005450;
    }
    // 0x80005434: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80005438: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8000543C:
    // 0x8000543C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80005440: sllv        $t7, $t6, $v1
    ctx->r15 = S32(ctx->r14 << (ctx->r3 & 31));
    // 0x80005444: sltu        $at, $t7, $a0
    ctx->r1 = ctx->r15 < ctx->r4 ? 1 : 0;
    // 0x80005448: bnel        $at, $zero, L_8000543C
    if (ctx->r1 != 0) {
        // 0x8000544C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8000543C;
    }
    goto skip_0;
    // 0x8000544C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
L_80005450:
    // 0x80005450: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80005454: sllv        $t9, $t8, $v1
    ctx->r25 = S32(ctx->r24 << (ctx->r3 & 31));
    // 0x80005458: beq         $a0, $t9, L_80005464
    if (ctx->r4 == ctx->r25) {
        // 0x8000545C: nop
    
            goto L_80005464;
    }
    // 0x8000545C: nop

    // 0x80005460: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
L_80005464:
    // 0x80005464: jr          $ra
    // 0x80005468: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    TRACE_RETURN()
    return;
    // 0x80005468: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8000546C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000546C: sltiu       $at, $a0, 0x2
    ctx->r1 = ctx->r4 < 0X2 ? 1 : 0;
    // 0x80005470: bne         $at, $zero, L_80005490
    if (ctx->r1 != 0) {
        // 0x80005474: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80005490;
    }
    // 0x80005474: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80005478: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8000547C:
    // 0x8000547C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80005480: sllv        $t7, $t6, $v1
    ctx->r15 = S32(ctx->r14 << (ctx->r3 & 31));
    // 0x80005484: sltu        $at, $t7, $a0
    ctx->r1 = ctx->r15 < ctx->r4 ? 1 : 0;
    // 0x80005488: bnel        $at, $zero, L_8000547C
    if (ctx->r1 != 0) {
        // 0x8000548C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8000547C;
    }
    goto skip_0;
    // 0x8000548C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
L_80005490:
    // 0x80005490: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80005494: sllv        $t9, $t8, $v1
    ctx->r25 = S32(ctx->r24 << (ctx->r3 & 31));
    // 0x80005498: beq         $a0, $t9, L_800054A4
    if (ctx->r4 == ctx->r25) {
        // 0x8000549C: nop
    
            goto L_800054A4;
    }
    // 0x8000549C: nop

    // 0x800054A0: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_800054A4:
    // 0x800054A4: jr          $ra
    // 0x800054A8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    TRACE_RETURN()
    return;
    // 0x800054A8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_800054B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800054B0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800054B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800054B8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800054BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800054C0: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800054C4: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x800054C8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800054CC: or          $t6, $a2, $zero
    ctx->r14 = ctx->r6 | 0;
    // 0x800054D0: addiu       $a3, $t6, 0x18
    ctx->r7 = ADD32(ctx->r14, 0X18);
    // 0x800054D4: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x800054D8: jal         0x80003088
    // 0x800054DC: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    func_80003088(rdram, ctx);
        goto after_0;
    // 0x800054DC: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_0:
    // 0x800054E0: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800054E4: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800054E8: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800054EC: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800054F0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800054F4: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800054F8: lwc1        $f14, 0xC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800054FC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80005500: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80005504: ldc1        $f16, 0x48F0($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, 0X48F0);
    // 0x80005508: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x8000550C: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x80005510: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80005514: add.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80005518: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8000551C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80005520: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
    // 0x80005524: c.lt.d      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.d < ctx->f0.d;
    // 0x80005528: nop

    // 0x8000552C: bc1fl       L_80005554
    if (!c1cs) {
        // 0x80005530: lwc1        $f18, 0x4($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
            goto L_80005554;
    }
    goto skip_0;
    // 0x80005530: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    skip_0:
    // 0x80005534: ldc1        $f4, 0x48F8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X48F8);
    // 0x80005538: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x8000553C: nop

    // 0x80005540: bc1fl       L_80005554
    if (!c1cs) {
        // 0x80005544: lwc1        $f18, 0x4($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
            goto L_80005554;
    }
    goto skip_1;
    // 0x80005544: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    skip_1:
    // 0x80005548: b           L_800055C0
    // 0x8000554C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800055C0;
    // 0x8000554C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80005550: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
L_80005554:
    // 0x80005554: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80005558: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000555C: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80005560: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80005564: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80005568: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8000556C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80005570: mul.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80005574: add.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x80005578: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8000557C: add.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80005580: add.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80005584: neg.s       $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = -ctx->f6.fl;
    // 0x80005588: div.s       $f0, $f18, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8000558C: mul.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80005590: add.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x80005594: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x80005598: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8000559C: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800055A0: mul.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800055A4: add.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x800055A8: swc1        $f18, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f18.u32l;
    // 0x800055AC: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800055B0: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800055B4: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800055B8: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800055BC: swc1        $f16, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f16.u32l;
L_800055C0:
    // 0x800055C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800055C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800055C8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800055CC: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800055D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800055D4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800055D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800055DC: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800055E0: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800055E4: jal         0x80005684
    // 0x800055E8: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    func_80005684(rdram, ctx);
        goto after_0;
    // 0x800055E8: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    after_0:
    // 0x800055EC: beq         $v0, $zero, L_800055FC
    if (ctx->r2 == 0) {
        // 0x800055F0: lw          $a2, 0x50($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X50);
            goto L_800055FC;
    }
    // 0x800055F0: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x800055F4: b           L_80005674
    // 0x800055F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80005674;
    // 0x800055F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800055FC:
    // 0x800055FC: addiu       $v0, $sp, 0x24
    ctx->r2 = ADD32(ctx->r29, 0X24);
    // 0x80005600: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x80005604: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
L_80005608:
    // 0x80005608: lwc1        $f4, 0x18($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X18);
    // 0x8000560C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80005610: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x80005614: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80005618: bne         $at, $zero, L_80005608
    if (ctx->r1 != 0) {
        // 0x8000561C: swc1        $f4, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
            goto L_80005608;
    }
    // 0x8000561C: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80005620: addiu       $v0, $sp, 0x24
    ctx->r2 = ADD32(ctx->r29, 0X24);
    // 0x80005624: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x80005628: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
L_8000562C:
    // 0x8000562C: lwc1        $f6, 0x24($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X24);
    // 0x80005630: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80005634: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x80005638: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000563C: bne         $at, $zero, L_8000562C
    if (ctx->r1 != 0) {
        // 0x80005640: swc1        $f6, 0x8($v0)
        MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
            goto L_8000562C;
    }
    // 0x80005640: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x80005644: addiu       $v0, $sp, 0x24
    ctx->r2 = ADD32(ctx->r29, 0X24);
    // 0x80005648: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x8000564C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
L_80005650:
    // 0x80005650: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80005654: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80005658: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000565C: bne         $v0, $a0, L_80005650
    if (ctx->r2 != ctx->r4) {
        // 0x80005660: swc1        $f8, 0x14($v0)
        MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
            goto L_80005650;
    }
    // 0x80005660: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
    // 0x80005664: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80005668: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8000566C: jal         0x80005684
    // 0x80005670: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_80005684(rdram, ctx);
        goto after_1;
    // 0x80005670: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_1:
L_80005674:
    // 0x80005674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80005678: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8000567C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80005684(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80005684: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80005688: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8000568C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80005690: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x80005694: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80005698: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8000569C: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800056A0: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800056A4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800056A8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800056AC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800056B0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800056B4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800056B8: jal         0x800054B0
    // 0x800056BC: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    func_800054B0(rdram, ctx);
        goto after_0;
    // 0x800056BC: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    after_0:
    // 0x800056C0: bne         $v0, $zero, L_800056D0
    if (ctx->r2 != 0) {
        // 0x800056C4: addiu       $s6, $sp, 0x8C
        ctx->r22 = ADD32(ctx->r29, 0X8C);
            goto L_800056D0;
    }
    // 0x800056C4: addiu       $s6, $sp, 0x8C
    ctx->r22 = ADD32(ctx->r29, 0X8C);
    // 0x800056C8: b           L_800057F8
    // 0x800056CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800057F8;
    // 0x800056CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800056D0:
    // 0x800056D0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800056D4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800056D8: addiu       $a2, $s5, 0xC
    ctx->r6 = ADD32(ctx->r21, 0XC);
    // 0x800056DC: jal         0x800037FC
    // 0x800056E0: addiu       $a3, $s5, 0x18
    ctx->r7 = ADD32(ctx->r21, 0X18);
    func_800037FC(rdram, ctx);
        goto after_1;
    // 0x800056E0: addiu       $a3, $s5, 0x18
    ctx->r7 = ADD32(ctx->r21, 0X18);
    after_1:
    // 0x800056E4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800056E8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800056EC: or          $s3, $s5, $zero
    ctx->r19 = ctx->r21 | 0;
    // 0x800056F0: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
    // 0x800056F4: addiu       $s7, $zero, 0xC
    ctx->r23 = ADD32(0, 0XC);
    // 0x800056F8: addiu       $s4, $sp, 0x80
    ctx->r20 = ADD32(ctx->r29, 0X80);
L_800056FC:
    // 0x800056FC: addiu       $s1, $s2, 0x1
    ctx->r17 = ADD32(ctx->r18, 0X1);
    // 0x80005700: slti        $at, $s1, 0x3
    ctx->r1 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // 0x80005704: bne         $at, $zero, L_80005710
    if (ctx->r1 != 0) {
        // 0x80005708: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80005710;
    }
    // 0x80005708: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x8000570C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80005710:
    // 0x80005710: multu       $s0, $s7
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80005714: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80005718: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8000571C: lw          $a3, 0x98($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X98);
    // 0x80005720: mflo        $t6
    ctx->r14 = lo;
    // 0x80005724: addu        $a2, $s5, $t6
    ctx->r6 = ADD32(ctx->r21, ctx->r14);
    // 0x80005728: jal         0x800037FC
    // 0x8000572C: nop

    func_800037FC(rdram, ctx);
        goto after_2;
    // 0x8000572C: nop

    after_2:
    // 0x80005730: bne         $v0, $zero, L_800057CC
    if (ctx->r2 != 0) {
        // 0x80005734: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_800057CC;
    }
    // 0x80005734: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80005738: sll         $t7, $s2, 2
    ctx->r15 = S32(ctx->r18 << 2);
    // 0x8000573C: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x80005740: subu        $t8, $t8, $s0
    ctx->r24 = SUB32(ctx->r24, ctx->r16);
    // 0x80005744: subu        $t7, $t7, $s2
    ctx->r15 = SUB32(ctx->r15, ctx->r18);
    // 0x80005748: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8000574C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80005750: addu        $a2, $s5, $t8
    ctx->r6 = ADD32(ctx->r21, ctx->r24);
    // 0x80005754: addu        $a1, $s5, $t7
    ctx->r5 = ADD32(ctx->r21, ctx->r15);
    // 0x80005758: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x8000575C: lw          $v0, 0x98($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X98);
    // 0x80005760: addiu       $v1, $sp, 0x68
    ctx->r3 = ADD32(ctx->r29, 0X68);
    // 0x80005764: addiu       $a3, $sp, 0x74
    ctx->r7 = ADD32(ctx->r29, 0X74);
L_80005768:
    // 0x80005768: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8000576C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80005770: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80005774: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80005778: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8000577C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80005780: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80005784: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80005788: swc1        $f8, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f8.u32l;
    // 0x8000578C: lwc1        $f16, -0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80005790: lwc1        $f10, -0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, -0X4);
    // 0x80005794: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80005798: bne         $v1, $a3, L_80005768
    if (ctx->r3 != ctx->r7) {
        // 0x8000579C: swc1        $f18, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
            goto L_80005768;
    }
    // 0x8000579C: swc1        $f18, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
    // 0x800057A0: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x800057A4: jal         0x80003730
    // 0x800057A8: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    func_80003730(rdram, ctx);
        goto after_3;
    // 0x800057A8: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    after_3:
    // 0x800057AC: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x800057B0: nop

    // 0x800057B4: bc1f        L_800057C4
    if (!c1cs) {
        // 0x800057B8: nop
    
            goto L_800057C4;
    }
    // 0x800057B8: nop

    // 0x800057BC: b           L_800057F8
    // 0x800057C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800057F8;
    // 0x800057C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800057C4:
    // 0x800057C4: b           L_800057F8
    // 0x800057C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800057F8;
    // 0x800057C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800057CC:
    // 0x800057CC: jal         0x80003700
    // 0x800057D0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_80003700(rdram, ctx);
        goto after_4;
    // 0x800057D0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_4:
    // 0x800057D4: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800057D8: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
    // 0x800057DC: bc1f        L_800057EC
    if (!c1cs) {
        // 0x800057E0: nop
    
            goto L_800057EC;
    }
    // 0x800057E0: nop

    // 0x800057E4: b           L_800057F8
    // 0x800057E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800057F8;
    // 0x800057E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800057EC:
    // 0x800057EC: bne         $s1, $fp, L_800056FC
    if (ctx->r17 != ctx->r30) {
        // 0x800057F0: addiu       $s3, $s3, 0xC
        ctx->r19 = ADD32(ctx->r19, 0XC);
            goto L_800056FC;
    }
    // 0x800057F0: addiu       $s3, $s3, 0xC
    ctx->r19 = ADD32(ctx->r19, 0XC);
    // 0x800057F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800057F8:
    // 0x800057F8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800057FC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80005800: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80005804: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80005808: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8000580C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80005810: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80005814: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80005818: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8000581C: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80005820: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80005824: jr          $ra
    // 0x80005828: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    TRACE_RETURN()
    return;
    // 0x80005828: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    // 0x8000582C: nop

    // 0x80005830: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80005834: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80005838: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8000583C: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80005840: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80005844: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80005848: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8000584C: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80005850: ldc1        $f8, 0x4900($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X4900);
    // 0x80005854: mul.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80005858: add.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8000585C: cvt.d.s     $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f6.d = CVT_D_S(ctx->f14.fl);
    // 0x80005860: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x80005864: nop

    // 0x80005868: bc1fl       L_8000587C
    if (!c1cs) {
        // 0x8000586C: sqrt.s      $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = sqrtf(ctx->f14.fl);
            goto L_8000587C;
    }
    goto skip_0;
    // 0x8000586C: sqrt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = sqrtf(ctx->f14.fl);
    skip_0:
    // 0x80005870: jr          $ra
    // 0x80005874: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    TRACE_RETURN()
    return;
    // 0x80005874: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80005878: sqrt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = sqrtf(ctx->f14.fl);
L_8000587C:
    // 0x8000587C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80005880: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80005884: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80005888: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000588C: neg.s       $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = -ctx->f12.fl;
    // 0x80005890: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x80005894: div.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f18.d);
    // 0x80005898: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
    // 0x8000589C: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800058A0: nop

    // 0x800058A4: mul.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x800058A8: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x800058AC: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x800058B0: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800058B4: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800058B8: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800058BC: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800058C0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800058C4: nop

    // 0x800058C8: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800058CC: sub.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x800058D0: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800058D4: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x800058D8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800058E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800058E0: lwc1        $f2, 0x4($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800058E4: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800058E8: lwc1        $f12, 0x4($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800058EC: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800058F0: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800058F4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800058F8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800058FC: mul.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x80005900: sub.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80005904: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80005908: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x8000590C: bc1f        L_80005918
    if (!c1cs) {
        // 0x80005910: nop
    
            goto L_80005918;
    }
    // 0x80005910: nop

    // 0x80005914: neg.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = -ctx->f0.fl;
L_80005918:
    // 0x80005918: ldc1        $f4, 0x4908($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X4908);
    // 0x8000591C: cvt.d.s     $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f18.d = CVT_D_S(ctx->f14.fl);
    // 0x80005920: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80005924: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x80005928: nop

    // 0x8000592C: bc1fl       L_80005940
    if (!c1cs) {
        // 0x80005930: mtc1        $at, $f9
        ctx->f_odd[(9 - 1) * 2] = ctx->r1;
            goto L_80005940;
    }
    goto skip_0;
    // 0x80005930: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    skip_0:
    // 0x80005934: jr          $ra
    // 0x80005938: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    TRACE_RETURN()
    return;
    // 0x80005938: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000593C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
L_80005940:
    // 0x80005940: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80005944: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80005948: lwc1        $f16, 0x8($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8000594C: div.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f6.d);
    // 0x80005950: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80005954: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80005958: mul.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8000595C: nop

    // 0x80005960: mul.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80005964: sub.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x80005968: cvt.s.d     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
    // 0x8000596C: mul.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80005970: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x80005974: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80005978: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8000597C: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80005980: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80005984: mul.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80005988: nop

    // 0x8000598C: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80005990: sub.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x80005994: mul.s       $f4, $f16, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80005998: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    // 0x8000599C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800059A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800059A4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800059A8: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800059AC: lwc1        $f8, 0x14($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800059B0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800059B4: sub.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x800059B8: lwc1        $f18, 0x10($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800059BC: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x800059C0: lwc1        $f8, 0xC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800059C4: sub.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f12.fl;
    // 0x800059C8: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800059CC: sub.s       $f6, $f8, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x800059D0: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800059D4: jr          $ra
    // 0x800059D8: sub.s       $f0, $f16, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f10.fl;
    TRACE_RETURN()
    return;
    // 0x800059D8: sub.s       $f0, $f16, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f10.fl;
;}
RECOMP_FUNC void func_800059DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800059DC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800059E0: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x800059E4: lwc1        $f2, 0x8($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800059E8: lwc1        $f14, 0xC($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800059EC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800059F0: mul.s       $f0, $f2, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800059F4: ldc1        $f6, 0x4910($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X4910);
    // 0x800059F8: mul.s       $f12, $f14, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800059FC: add.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x80005A00: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x80005A04: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x80005A08: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x80005A0C: nop

    // 0x80005A10: bc1fl       L_80005A24
    if (!c1cs) {
        // 0x80005A14: lwc1        $f18, 0x0($a1)
        ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
            goto L_80005A24;
    }
    goto skip_0;
    // 0x80005A14: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    skip_0:
    // 0x80005A18: b           L_80005B80
    // 0x80005A1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80005B80;
    // 0x80005A1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80005A20: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
L_80005A24:
    // 0x80005A24: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80005A28: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80005A2C: sub.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x80005A30: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x80005A34: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80005A38: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80005A3C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80005A40: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80005A44: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x80005A48: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80005A4C: mul.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80005A50: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80005A54: mul.s       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x80005A58: sub.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80005A5C: mul.s       $f6, $f10, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x80005A60: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80005A64: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80005A68: ldc1        $f4, 0x4918($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X4918);
    // 0x80005A6C: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80005A70: sub.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80005A74: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80005A78: cvt.d.s     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f12.d = CVT_D_S(ctx->f6.fl);
    // 0x80005A7C: swc1        $f6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f6.u32l;
    // 0x80005A80: c.lt.d      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.d < ctx->f4.d;
    // 0x80005A84: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80005A88: bc1f        L_80005A98
    if (!c1cs) {
        // 0x80005A8C: nop
    
            goto L_80005A98;
    }
    // 0x80005A8C: nop

    // 0x80005A90: b           L_80005B80
    // 0x80005A94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80005B80;
    // 0x80005A94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80005A98:
    // 0x80005A98: mul.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x80005A9C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80005AA0: ldc1        $f8, 0x4920($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X4920);
    // 0x80005AA4: mul.s       $f4, $f2, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80005AA8: c.lt.d      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.d < ctx->f8.d;
    // 0x80005AAC: nop

    // 0x80005AB0: bc1f        L_80005AEC
    if (!c1cs) {
        // 0x80005AB4: add.s       $f0, $f10, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f4.fl;
            goto L_80005AEC;
    }
    // 0x80005AB4: add.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80005AB8: div.s       $f14, $f0, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = DIV_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80005ABC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80005AC0: mul.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80005AC4: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80005AC8: swc1        $f12, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f12.u32l;
    // 0x80005ACC: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x80005AD0: lwc1        $f10, 0xC($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80005AD4: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80005AD8: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80005ADC: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80005AE0: swc1        $f12, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f12.u32l;
    // 0x80005AE4: b           L_80005B80
    // 0x80005AE8: swc1        $f12, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f12.u32l;
        goto L_80005B80;
    // 0x80005AE8: swc1        $f12, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f12.u32l;
L_80005AEC:
    // 0x80005AEC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80005AF0: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
    // 0x80005AF4: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80005AF8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80005AFC: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80005B00: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80005B04: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80005B08: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80005B0C: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80005B10: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80005B14: div.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f4.d);
    // 0x80005B18: sub.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80005B1C: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x80005B20: mul.s       $f14, $f6, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80005B24: nop

    // 0x80005B28: mul.s       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80005B2C: add.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80005B30: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x80005B34: lwc1        $f10, 0xC($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80005B38: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80005B3C: mul.s       $f6, $f10, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80005B40: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80005B44: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    // 0x80005B48: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80005B4C: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80005B50: add.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80005B54: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80005B58: mul.s       $f16, $f6, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80005B5C: nop

    // 0x80005B60: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80005B64: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80005B68: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    // 0x80005B6C: lwc1        $f4, 0xC($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80005B70: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80005B74: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80005B78: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80005B7C: swc1        $f6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f6.u32l;
L_80005B80:
    // 0x80005B80: jr          $ra
    // 0x80005B84: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    TRACE_RETURN()
    return;
    // 0x80005B84: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80005B88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80005B88: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80005B8C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80005B90: lwc1        $f2, 0xC($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80005B94: lwc1        $f12, 0x8($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80005B98: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80005B9C: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80005BA0: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x80005BA4: ldc1        $f8, 0x4928($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X4928);
    // 0x80005BA8: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80005BAC: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80005BB0: cvt.d.s     $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f16.d = CVT_D_S(ctx->f14.fl);
    // 0x80005BB4: c.lt.d      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.d < ctx->f8.d;
    // 0x80005BB8: nop

    // 0x80005BBC: bc1fl       L_80005BE8
    if (!c1cs) {
        // 0x80005BC0: sqrt.s      $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = sqrtf(ctx->f14.fl);
            goto L_80005BE8;
    }
    goto skip_0;
    // 0x80005BC0: sqrt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = sqrtf(ctx->f14.fl);
    skip_0:
    // 0x80005BC4: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80005BC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80005BCC: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x80005BD0: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x80005BD4: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80005BD8: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x80005BDC: b           L_80005C74
    // 0x80005BE0: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
        goto L_80005C74;
    // 0x80005BE0: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x80005BE4: sqrt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = sqrtf(ctx->f14.fl);
L_80005BE8:
    // 0x80005BE8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80005BEC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80005BF0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80005BF4: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80005BF8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80005BFC: div.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f16.d);
    // 0x80005C00: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80005C04: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80005C08: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x80005C0C: swc1        $f8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f8.u32l;
    // 0x80005C10: swc1        $f10, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f10.u32l;
    // 0x80005C14: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x80005C18: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80005C1C: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80005C20: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80005C24: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x80005C28: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x80005C2C: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80005C30: mul.s       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80005C34: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x80005C38: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80005C3C: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x80005C40: lwc1        $f6, 0x8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8);
    // 0x80005C44: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80005C48: nop

    // 0x80005C4C: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80005C50: swc1        $f8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f8.u32l;
    // 0x80005C54: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80005C58: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80005C5C: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    // 0x80005C60: lwc1        $f4, 0xC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC);
    // 0x80005C64: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80005C68: mul.s       $f10, $f12, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80005C6C: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80005C70: swc1        $f6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f6.u32l;
L_80005C74:
    // 0x80005C74: jr          $ra
    // 0x80005C78: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    TRACE_RETURN()
    return;
    // 0x80005C78: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80005C7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80005C7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80005C80: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80005C84: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80005C88: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x80005C8C: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80005C90: sub.s       $f2, $f4, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x80005C94: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80005C98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80005C9C: sub.s       $f16, $f6, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f14.fl;
    // 0x80005CA0: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80005CA4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80005CA8: mul.s       $f10, $f16, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80005CAC: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80005CB0: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80005CB4: div.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80005CB8: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80005CBC: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80005CC0: mul.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80005CC4: add.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x80005CC8: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80005CCC: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80005CD0: neg.s       $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = -ctx->f18.fl;
    // 0x80005CD4: mul.s       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80005CD8: nop

    // 0x80005CDC: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80005CE0: nop

    // 0x80005CE4: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80005CE8: add.s       $f6, $f10, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x80005CEC: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80005CF0: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x80005CF4: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x80005CF8: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
    // 0x80005CFC: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80005D00: mul.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80005D04: nop

    // 0x80005D08: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80005D0C: add.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x80005D10: swc1        $f10, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f10.u32l;
    // 0x80005D14: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80005D18: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80005D1C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80005D20: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80005D24: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80005D28: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80005D2C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80005D30: jal         0x800059A4
    // 0x80005D34: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_800059A4(rdram, ctx);
        goto after_0;
    // 0x80005D34: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80005D38: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80005D3C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80005D40: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80005D44: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80005D48: nop

    // 0x80005D4C: bc1fl       L_80005D78
    if (!c1cs) {
        // 0x80005D50: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80005D78;
    }
    goto skip_0;
    // 0x80005D50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80005D54: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80005D58: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80005D5C: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x80005D60: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80005D64: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x80005D68: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80005D6C: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x80005D70: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    // 0x80005D74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80005D78:
    // 0x80005D78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80005D7C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80005D84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80005D84: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80005D88: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80005D8C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80005D90: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80005D94: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80005D98: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x80005D9C: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80005DA0: mul.s       $f8, $f6, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x80005DA4: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    // 0x80005DA8: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80005DAC: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x80005DB0: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80005DB4: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x80005DB8: ldc1        $f4, 0x4930($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X4930);
    // 0x80005DBC: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80005DC0: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x80005DC4: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80005DC8: cvt.d.s     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f2.d = CVT_D_S(ctx->f10.fl);
    // 0x80005DCC: c.lt.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d < ctx->f4.d;
    // 0x80005DD0: nop

    // 0x80005DD4: bc1fl       L_80005DEC
    if (!c1cs) {
        // 0x80005DD8: lwc1        $f6, 0x0($a0)
        ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
            goto L_80005DEC;
    }
    goto skip_0;
    // 0x80005DD8: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x80005DDC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80005DE0: b           L_80005E60
    // 0x80005DE4: nop

        goto L_80005E60;
    // 0x80005DE4: nop

    // 0x80005DE8: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
L_80005DEC:
    // 0x80005DEC: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80005DF0: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80005DF4: sub.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80005DF8: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80005DFC: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80005E00: sub.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80005E04: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80005E08: mul.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80005E0C: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80005E10: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80005E14: mul.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80005E18: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80005E1C: mul.s       $f8, $f16, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80005E20: sub.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80005E24: mul.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80005E28: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80005E2C: mul.s       $f4, $f16, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80005E30: sub.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80005E34: div.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f2.d);
    // 0x80005E38: mul.s       $f6, $f8, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x80005E3C: swc1        $f8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f8.u32l;
    // 0x80005E40: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80005E44: mul.s       $f10, $f18, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x80005E48: swc1        $f4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f4.u32l;
    // 0x80005E4C: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80005E50: mul.s       $f10, $f4, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x80005E54: nop

    // 0x80005E58: mul.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80005E5C: nop

L_80005E60:
    // 0x80005E60: jr          $ra
    // 0x80005E64: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    TRACE_RETURN()
    return;
    // 0x80005E64: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80005E68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80005E68: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80005E6C: lwc1        $f12, 0x0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80005E70: lwc1        $f14, 0x0($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80005E74: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80005E78: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80005E7C: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80005E80: nop

    // 0x80005E84: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80005E88: nop

    // 0x80005E8C: mul.s       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80005E90: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80005E94: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80005E98: mul.s       $f0, $f8, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80005E9C: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80005EA0: mul.s       $f6, $f14, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80005EA4: nop

    // 0x80005EA8: mul.s       $f10, $f16, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80005EAC: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80005EB0: jr          $ra
    // 0x80005EB4: div.s       $f0, $f18, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    TRACE_RETURN()
    return;
    // 0x80005EB4: div.s       $f0, $f18, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
;}
RECOMP_FUNC void func_80005EB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80005EB8: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80005EBC: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80005EC0: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80005EC4: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x80005EC8: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80005ECC: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80005ED0: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80005ED4: lwc1        $f18, 0x0($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80005ED8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80005EDC: nop

    // 0x80005EE0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80005EE4: add.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80005EE8: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80005EEC: jr          $ra
    // 0x80005EF0: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    TRACE_RETURN()
    return;
    // 0x80005EF0: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
;}
RECOMP_FUNC void func_80005F00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80005F00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80005F04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80005F08: lw          $a3, 0xC($a1)
    ctx->r7 = MEM_W(ctx->r5, 0XC);
    // 0x80005F0C: beql        $a3, $zero, L_80005F64
    if (ctx->r7 == 0) {
        // 0x80005F10: lh          $a3, 0xA($a1)
        ctx->r7 = MEM_H(ctx->r5, 0XA);
            goto L_80005F64;
    }
    goto skip_0;
    // 0x80005F10: lh          $a3, 0xA($a1)
    ctx->r7 = MEM_H(ctx->r5, 0XA);
    skip_0:
    // 0x80005F14: lw          $v0, 0x10($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X10);
    // 0x80005F18: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80005F1C: bnel        $v0, $at, L_80005F40
    if (ctx->r2 != ctx->r1) {
        // 0x80005F20: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80005F40;
    }
    goto skip_1;
    // 0x80005F20: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    skip_1:
    // 0x80005F24: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x80005F28: addiu       $a1, $a1, 0x4940
    ctx->r5 = ADD32(ctx->r5, 0X4940);
    // 0x80005F2C: jal         0x80007098
    // 0x80005F30: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    func_80007098(rdram, ctx);
        goto after_0;
    // 0x80005F30: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_0:
    // 0x80005F34: b           L_80005FE4
    // 0x80005F38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80005FE4;
    // 0x80005F38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80005F3C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
L_80005F40:
    // 0x80005F40: bnel        $v0, $at, L_80005F64
    if (ctx->r2 != ctx->r1) {
        // 0x80005F44: lh          $a3, 0xA($a1)
        ctx->r7 = MEM_H(ctx->r5, 0XA);
            goto L_80005F64;
    }
    goto skip_2;
    // 0x80005F44: lh          $a3, 0xA($a1)
    ctx->r7 = MEM_H(ctx->r5, 0XA);
    skip_2:
    // 0x80005F48: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x80005F4C: addiu       $a1, $a1, 0x4948
    ctx->r5 = ADD32(ctx->r5, 0X4948);
    // 0x80005F50: jal         0x80007098
    // 0x80005F54: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    func_80007098(rdram, ctx);
        goto after_1;
    // 0x80005F54: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_1:
    // 0x80005F58: b           L_80005FE4
    // 0x80005F5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80005FE4;
    // 0x80005F5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80005F60: lh          $a3, 0xA($a1)
    ctx->r7 = MEM_H(ctx->r5, 0XA);
L_80005F64:
    // 0x80005F64: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x80005F68: addiu       $a1, $a1, 0x4954
    ctx->r5 = ADD32(ctx->r5, 0X4954);
    // 0x80005F6C: bgez        $a3, L_80005F8C
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80005F70: andi        $t7, $a3, 0xFFFF
        ctx->r15 = ctx->r7 & 0XFFFF;
            goto L_80005F8C;
    }
    // 0x80005F70: andi        $t7, $a3, 0xFFFF
    ctx->r15 = ctx->r7 & 0XFFFF;
    // 0x80005F74: beq         $a2, $zero, L_80005F8C
    if (ctx->r6 == 0) {
        // 0x80005F78: addiu       $t6, $zero, 0x2D
        ctx->r14 = ADD32(0, 0X2D);
            goto L_80005F8C;
    }
    // 0x80005F78: addiu       $t6, $zero, 0x2D
    ctx->r14 = ADD32(0, 0X2D);
    // 0x80005F7C: negu        $a3, $a3
    ctx->r7 = SUB32(0, ctx->r7);
    // 0x80005F80: sb          $t6, 0x24($sp)
    MEM_B(0X24, ctx->r29) = ctx->r14;
    // 0x80005F84: b           L_80005F94
    // 0x80005F88: sb          $zero, 0x25($sp)
    MEM_B(0X25, ctx->r29) = 0;
        goto L_80005F94;
    // 0x80005F88: sb          $zero, 0x25($sp)
    MEM_B(0X25, ctx->r29) = 0;
L_80005F8C:
    // 0x80005F8C: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x80005F90: sb          $zero, 0x24($sp)
    MEM_B(0X24, ctx->r29) = 0;
L_80005F94:
    // 0x80005F94: slti        $at, $a3, 0xA
    ctx->r1 = SIGNED(ctx->r7) < 0XA ? 1 : 0;
    // 0x80005F98: beql        $at, $zero, L_80005FB4
    if (ctx->r1 == 0) {
        // 0x80005F9C: slti        $at, $a3, 0x100
        ctx->r1 = SIGNED(ctx->r7) < 0X100 ? 1 : 0;
            goto L_80005FB4;
    }
    goto skip_3;
    // 0x80005F9C: slti        $at, $a3, 0x100
    ctx->r1 = SIGNED(ctx->r7) < 0X100 ? 1 : 0;
    skip_3:
    // 0x80005FA0: jal         0x80007098
    // 0x80005FA4: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_80007098(rdram, ctx);
        goto after_2;
    // 0x80005FA4: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_2:
    // 0x80005FA8: b           L_80005FE4
    // 0x80005FAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80005FE4;
    // 0x80005FAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80005FB0: slti        $at, $a3, 0x100
    ctx->r1 = SIGNED(ctx->r7) < 0X100 ? 1 : 0;
L_80005FB4:
    // 0x80005FB4: beq         $at, $zero, L_80005FD4
    if (ctx->r1 == 0) {
        // 0x80005FB8: lui         $a1, 0x8007
        ctx->r5 = S32(0X8007 << 16);
            goto L_80005FD4;
    }
    // 0x80005FB8: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x80005FBC: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x80005FC0: addiu       $a1, $a1, 0x495C
    ctx->r5 = ADD32(ctx->r5, 0X495C);
    // 0x80005FC4: jal         0x80007098
    // 0x80005FC8: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_80007098(rdram, ctx);
        goto after_3;
    // 0x80005FC8: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_3:
    // 0x80005FCC: b           L_80005FE4
    // 0x80005FD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80005FE4;
    // 0x80005FD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80005FD4:
    // 0x80005FD4: addiu       $a1, $a1, 0x4964
    ctx->r5 = ADD32(ctx->r5, 0X4964);
    // 0x80005FD8: jal         0x80007098
    // 0x80005FDC: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_80007098(rdram, ctx);
        goto after_4;
    // 0x80005FDC: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x80005FE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80005FE4:
    // 0x80005FE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80005FE8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80005FF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80005FF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80005FF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80005FF8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80005FFC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80006000: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80006004: jal         0x80006AD4
    // 0x80006008: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80006AD4(rdram, ctx);
        goto after_0;
    // 0x80006008: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8000600C: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x80006010: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x80006014: addiu       $at, $zero, 0x4644
    ctx->r1 = ADD32(0, 0X4644);
    // 0x80006018: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x8000601C: addu        $v1, $t6, $t8
    ctx->r3 = ADD32(ctx->r14, ctx->r24);
    // 0x80006020: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80006024: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80006028: beq         $v1, $at, L_800060E4
    if (ctx->r3 == ctx->r1) {
        // 0x8000602C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800060E4;
    }
    // 0x8000602C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80006030: addiu       $at, $zero, 0x4653
    ctx->r1 = ADD32(0, 0X4653);
    // 0x80006034: beq         $v1, $at, L_800060BC
    if (ctx->r3 == ctx->r1) {
        // 0x80006038: addiu       $at, $zero, 0x4654
        ctx->r1 = ADD32(0, 0X4654);
            goto L_800060BC;
    }
    // 0x80006038: addiu       $at, $zero, 0x4654
    ctx->r1 = ADD32(0, 0X4654);
    // 0x8000603C: beq         $v1, $at, L_800060D0
    if (ctx->r3 == ctx->r1) {
        // 0x80006040: addiu       $at, $zero, 0x5244
        ctx->r1 = ADD32(0, 0X5244);
            goto L_800060D0;
    }
    // 0x80006040: addiu       $at, $zero, 0x5244
    ctx->r1 = ADD32(0, 0X5244);
    // 0x80006044: beq         $v1, $at, L_80006094
    if (ctx->r3 == ctx->r1) {
        // 0x80006048: addiu       $at, $zero, 0x5253
        ctx->r1 = ADD32(0, 0X5253);
            goto L_80006094;
    }
    // 0x80006048: addiu       $at, $zero, 0x5253
    ctx->r1 = ADD32(0, 0X5253);
    // 0x8000604C: beq         $v1, $at, L_8000606C
    if (ctx->r3 == ctx->r1) {
        // 0x80006050: addiu       $at, $zero, 0x5254
        ctx->r1 = ADD32(0, 0X5254);
            goto L_8000606C;
    }
    // 0x80006050: addiu       $at, $zero, 0x5254
    ctx->r1 = ADD32(0, 0X5254);
    // 0x80006054: beq         $v1, $at, L_80006080
    if (ctx->r3 == ctx->r1) {
        // 0x80006058: addiu       $at, $zero, 0x5341
        ctx->r1 = ADD32(0, 0X5341);
            goto L_80006080;
    }
    // 0x80006058: addiu       $at, $zero, 0x5341
    ctx->r1 = ADD32(0, 0X5341);
    // 0x8000605C: beql        $v1, $at, L_800060AC
    if (ctx->r3 == ctx->r1) {
        // 0x80006060: lw          $t8, 0x8($a1)
        ctx->r24 = MEM_W(ctx->r5, 0X8);
            goto L_800060AC;
    }
    goto skip_0;
    // 0x80006060: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    skip_0:
    // 0x80006064: b           L_800060F4
    // 0x80006068: nop

        goto L_800060F4;
    // 0x80006068: nop

L_8000606C:
    // 0x8000606C: lw          $t9, 0x8($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X8);
    // 0x80006070: sra         $t0, $t9, 21
    ctx->r8 = S32(SIGNED(ctx->r25) >> 21);
    // 0x80006074: andi        $t1, $t0, 0x1F
    ctx->r9 = ctx->r8 & 0X1F;
    // 0x80006078: b           L_800060F4
    // 0x8000607C: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
        goto L_800060F4;
    // 0x8000607C: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
L_80006080:
    // 0x80006080: lw          $t2, 0x8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X8);
    // 0x80006084: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80006088: andi        $t4, $t3, 0x1F
    ctx->r12 = ctx->r11 & 0X1F;
    // 0x8000608C: b           L_800060F4
    // 0x80006090: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
        goto L_800060F4;
    // 0x80006090: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
L_80006094:
    // 0x80006094: lw          $t5, 0x8($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X8);
    // 0x80006098: sra         $t7, $t5, 11
    ctx->r15 = S32(SIGNED(ctx->r13) >> 11);
    // 0x8000609C: andi        $t6, $t7, 0x1F
    ctx->r14 = ctx->r15 & 0X1F;
    // 0x800060A0: b           L_800060F4
    // 0x800060A4: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
        goto L_800060F4;
    // 0x800060A4: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800060A8: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
L_800060AC:
    // 0x800060AC: sra         $t9, $t8, 6
    ctx->r25 = S32(SIGNED(ctx->r24) >> 6);
    // 0x800060B0: andi        $t0, $t9, 0x1F
    ctx->r8 = ctx->r25 & 0X1F;
    // 0x800060B4: b           L_800060F4
    // 0x800060B8: sw          $t0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r8;
        goto L_800060F4;
    // 0x800060B8: sw          $t0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r8;
L_800060BC:
    // 0x800060BC: lw          $t1, 0x8($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X8);
    // 0x800060C0: sra         $t2, $t1, 11
    ctx->r10 = S32(SIGNED(ctx->r9) >> 11);
    // 0x800060C4: andi        $t3, $t2, 0x1F
    ctx->r11 = ctx->r10 & 0X1F;
    // 0x800060C8: b           L_800060F4
    // 0x800060CC: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
        goto L_800060F4;
    // 0x800060CC: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
L_800060D0:
    // 0x800060D0: lw          $t4, 0x8($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X8);
    // 0x800060D4: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800060D8: andi        $t7, $t5, 0x1F
    ctx->r15 = ctx->r13 & 0X1F;
    // 0x800060DC: b           L_800060F4
    // 0x800060E0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
        goto L_800060F4;
    // 0x800060E0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
L_800060E4:
    // 0x800060E4: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x800060E8: sra         $t8, $t6, 6
    ctx->r24 = S32(SIGNED(ctx->r14) >> 6);
    // 0x800060EC: andi        $t9, $t8, 0x1F
    ctx->r25 = ctx->r24 & 0X1F;
    // 0x800060F0: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
L_800060F4:
    // 0x800060F4: jal         0x80006AD4
    // 0x800060F8: addiu       $a0, $a2, 0x2
    ctx->r4 = ADD32(ctx->r6, 0X2);
    func_80006AD4(rdram, ctx);
        goto after_1;
    // 0x800060F8: addiu       $a0, $a2, 0x2
    ctx->r4 = ADD32(ctx->r6, 0X2);
    after_1:
    // 0x800060FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006100: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80006104: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80006108: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80006110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80006110: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x80006114: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80006118: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8000611C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80006120: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80006124: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80006128: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000612C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80006130: lbu         $a3, 0x0($a2)
    ctx->r7 = MEM_BU(ctx->r6, 0X0);
    // 0x80006134: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80006138: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8000613C: beq         $a3, $zero, L_800064E0
    if (ctx->r7 == 0) {
        // 0x80006140: or          $s2, $a1, $zero
        ctx->r18 = ctx->r5 | 0;
            goto L_800064E0;
    }
    // 0x80006140: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80006144: addiu       $s5, $sp, 0x7C
    ctx->r21 = ADD32(ctx->r29, 0X7C);
    // 0x80006148: addiu       $s4, $sp, 0xBC
    ctx->r20 = ADD32(ctx->r29, 0XBC);
    // 0x8000614C: addiu       $s3, $sp, 0x3C
    ctx->r19 = ADD32(ctx->r29, 0X3C);
    // 0x80006150: addiu       $at, $zero, 0x3B
    ctx->r1 = ADD32(0, 0X3B);
L_80006154:
    // 0x80006154: bne         $a3, $at, L_80006164
    if (ctx->r7 != ctx->r1) {
        // 0x80006158: or          $v1, $a3, $zero
        ctx->r3 = ctx->r7 | 0;
            goto L_80006164;
    }
    // 0x80006158: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8000615C: b           L_800064D4
    // 0x80006160: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_800064D4;
    // 0x80006160: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80006164:
    // 0x80006164: lbu         $t6, 0x1($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X1);
    // 0x80006168: sll         $t7, $v1, 8
    ctx->r15 = S32(ctx->r3 << 8);
    // 0x8000616C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80006170: slti        $at, $v0, 0x4959
    ctx->r1 = SIGNED(ctx->r2) < 0X4959 ? 1 : 0;
    // 0x80006174: bne         $at, $zero, L_800061C4
    if (ctx->r1 != 0) {
        // 0x80006178: addiu       $at, $zero, 0x4A41
        ctx->r1 = ADD32(0, 0X4A41);
            goto L_800061C4;
    }
    // 0x80006178: addiu       $at, $zero, 0x4A41
    ctx->r1 = ADD32(0, 0X4A41);
    // 0x8000617C: beq         $v0, $at, L_800063C8
    if (ctx->r2 == ctx->r1) {
        // 0x80006180: addiu       $at, $zero, 0x5228
        ctx->r1 = ADD32(0, 0X5228);
            goto L_800063C8;
    }
    // 0x80006180: addiu       $at, $zero, 0x5228
    ctx->r1 = ADD32(0, 0X5228);
    // 0x80006184: beq         $v0, $at, L_80006214
    if (ctx->r2 == ctx->r1) {
        // 0x80006188: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80006214;
    }
    // 0x80006188: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8000618C: addiu       $at, $zero, 0x524C
    ctx->r1 = ADD32(0, 0X524C);
    // 0x80006190: beq         $v0, $at, L_80006394
    if (ctx->r2 == ctx->r1) {
        // 0x80006194: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80006394;
    }
    // 0x80006194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80006198: addiu       $at, $zero, 0x5256
    ctx->r1 = ADD32(0, 0X5256);
    // 0x8000619C: beq         $v0, $at, L_80006444
    if (ctx->r2 == ctx->r1) {
        // 0x800061A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80006444;
    }
    // 0x800061A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800061A4: addiu       $at, $zero, 0x5349
    ctx->r1 = ADD32(0, 0X5349);
    // 0x800061A8: beq         $v0, $at, L_8000633C
    if (ctx->r2 == ctx->r1) {
        // 0x800061AC: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8000633C;
    }
    // 0x800061AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800061B0: addiu       $at, $zero, 0x5549
    ctx->r1 = ADD32(0, 0X5549);
    // 0x800061B4: beq         $v0, $at, L_80006368
    if (ctx->r2 == ctx->r1) {
        // 0x800061B8: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80006368;
    }
    // 0x800061B8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800061BC: b           L_800064CC
    // 0x800061C0: sb          $a3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r7;
        goto L_800064CC;
    // 0x800061C0: sb          $a3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r7;
L_800061C4:
    // 0x800061C4: addiu       $at, $zero, 0x4228
    ctx->r1 = ADD32(0, 0X4228);
    // 0x800061C8: beq         $v0, $at, L_800062CC
    if (ctx->r2 == ctx->r1) {
        // 0x800061CC: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_800062CC;
    }
    // 0x800061CC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800061D0: addiu       $at, $zero, 0x4344
    ctx->r1 = ADD32(0, 0X4344);
    // 0x800061D4: beq         $v0, $at, L_80006428
    if (ctx->r2 == ctx->r1) {
        // 0x800061D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80006428;
    }
    // 0x800061D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800061DC: addiu       $at, $zero, 0x4350
    ctx->r1 = ADD32(0, 0X4350);
    // 0x800061E0: beq         $v0, $at, L_80006470
    if (ctx->r2 == ctx->r1) {
        // 0x800061E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80006470;
    }
    // 0x800061E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800061E8: addiu       $at, $zero, 0x4628
    ctx->r1 = ADD32(0, 0X4628);
    // 0x800061EC: beq         $v0, $at, L_800062A0
    if (ctx->r2 == ctx->r1) {
        // 0x800061F0: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_800062A0;
    }
    // 0x800061F0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800061F4: addiu       $at, $zero, 0x464D
    ctx->r1 = ADD32(0, 0X464D);
    // 0x800061F8: beq         $v0, $at, L_80006494
    if (ctx->r2 == ctx->r1) {
        // 0x800061FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80006494;
    }
    // 0x800061FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80006200: addiu       $at, $zero, 0x4958
    ctx->r1 = ADD32(0, 0X4958);
    // 0x80006204: beq         $v0, $at, L_800062F8
    if (ctx->r2 == ctx->r1) {
        // 0x80006208: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800062F8;
    }
    // 0x80006208: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8000620C: b           L_800064CC
    // 0x80006210: sb          $a3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r7;
        goto L_800064CC;
    // 0x80006210: sb          $a3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r7;
L_80006214:
    // 0x80006214: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80006218: jal         0x80005FF0
    // 0x8000621C: addiu       $a2, $s1, 0x2
    ctx->r6 = ADD32(ctx->r17, 0X2);
    func_80005FF0(rdram, ctx);
        goto after_0;
    // 0x8000621C: addiu       $a2, $s1, 0x2
    ctx->r6 = ADD32(ctx->r17, 0X2);
    after_0:
    // 0x80006220: lw          $a2, 0xBC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XBC);
    // 0x80006224: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80006228: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8000622C: beq         $a2, $at, L_80006278
    if (ctx->r6 == ctx->r1) {
        // 0x80006230: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80006278;
    }
    // 0x80006230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80006234: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x80006238: beq         $a2, $at, L_80006264
    if (ctx->r6 == ctx->r1) {
        // 0x8000623C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80006264;
    }
    // 0x8000623C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80006240: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80006244: bne         $a2, $at, L_8000628C
    if (ctx->r6 != ctx->r1) {
        // 0x80006248: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8000628C;
    }
    // 0x80006248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000624C: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x80006250: addiu       $a1, $a1, 0x49AC
    ctx->r5 = ADD32(ctx->r5, 0X49AC);
    // 0x80006254: jal         0x80007098
    // 0x80006258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80007098(rdram, ctx);
        goto after_1;
    // 0x80006258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8000625C: b           L_800064D4
    // 0x80006260: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_800064D4;
    // 0x80006260: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80006264:
    // 0x80006264: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x80006268: jal         0x80007098
    // 0x8000626C: addiu       $a1, $a1, 0x49B0
    ctx->r5 = ADD32(ctx->r5, 0X49B0);
    func_80007098(rdram, ctx);
        goto after_2;
    // 0x8000626C: addiu       $a1, $a1, 0x49B0
    ctx->r5 = ADD32(ctx->r5, 0X49B0);
    after_2:
    // 0x80006270: b           L_800064D4
    // 0x80006274: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_800064D4;
    // 0x80006274: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80006278:
    // 0x80006278: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x8000627C: jal         0x80007098
    // 0x80006280: addiu       $a1, $a1, 0x49B4
    ctx->r5 = ADD32(ctx->r5, 0X49B4);
    func_80007098(rdram, ctx);
        goto after_3;
    // 0x80006280: addiu       $a1, $a1, 0x49B4
    ctx->r5 = ADD32(ctx->r5, 0X49B4);
    after_3:
    // 0x80006284: b           L_800064D4
    // 0x80006288: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_800064D4;
    // 0x80006288: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8000628C:
    // 0x8000628C: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x80006290: jal         0x80007098
    // 0x80006294: addiu       $a1, $a1, 0x49B8
    ctx->r5 = ADD32(ctx->r5, 0X49B8);
    func_80007098(rdram, ctx);
        goto after_4;
    // 0x80006294: addiu       $a1, $a1, 0x49B8
    ctx->r5 = ADD32(ctx->r5, 0X49B8);
    after_4:
    // 0x80006298: b           L_800064D4
    // 0x8000629C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_800064D4;
    // 0x8000629C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800062A0:
    // 0x800062A0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800062A4: jal         0x80005FF0
    // 0x800062A8: addiu       $a2, $s1, 0x2
    ctx->r6 = ADD32(ctx->r17, 0X2);
    func_80005FF0(rdram, ctx);
        goto after_5;
    // 0x800062A8: addiu       $a2, $s1, 0x2
    ctx->r6 = ADD32(ctx->r17, 0X2);
    after_5:
    // 0x800062AC: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x800062B0: lw          $a2, 0xBC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XBC);
    // 0x800062B4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800062B8: addiu       $a1, $a1, 0x49BC
    ctx->r5 = ADD32(ctx->r5, 0X49BC);
    // 0x800062BC: jal         0x80007098
    // 0x800062C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80007098(rdram, ctx);
        goto after_6;
    // 0x800062C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x800062C4: b           L_800064D4
    // 0x800062C8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_800064D4;
    // 0x800062C8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800062CC:
    // 0x800062CC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800062D0: jal         0x80005FF0
    // 0x800062D4: addiu       $a2, $s1, 0x2
    ctx->r6 = ADD32(ctx->r17, 0X2);
    func_80005FF0(rdram, ctx);
        goto after_7;
    // 0x800062D4: addiu       $a2, $s1, 0x2
    ctx->r6 = ADD32(ctx->r17, 0X2);
    after_7:
    // 0x800062D8: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x800062DC: lw          $a2, 0xBC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XBC);
    // 0x800062E0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800062E4: addiu       $a1, $a1, 0x49C0
    ctx->r5 = ADD32(ctx->r5, 0X49C0);
    // 0x800062E8: jal         0x80007098
    // 0x800062EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80007098(rdram, ctx);
        goto after_8;
    // 0x800062EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x800062F0: b           L_800064D4
    // 0x800062F4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_800064D4;
    // 0x800062F4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800062F8:
    // 0x800062F8: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x800062FC: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x80006300: addiu       $a2, $a2, 0x49C4
    ctx->r6 = ADD32(ctx->r6, 0X49C4);
    // 0x80006304: jal         0x80006110
    // 0x80006308: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80006110(rdram, ctx);
        goto after_9;
    // 0x80006308: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_9:
    // 0x8000630C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80006310: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80006314: jal         0x80005F00
    // 0x80006318: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80005F00(rdram, ctx);
        goto after_10;
    // 0x80006318: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_10:
    // 0x8000631C: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x80006320: addiu       $a1, $a1, 0x49CC
    ctx->r5 = ADD32(ctx->r5, 0X49CC);
    // 0x80006324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80006328: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x8000632C: jal         0x80007098
    // 0x80006330: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    func_80007098(rdram, ctx);
        goto after_11;
    // 0x80006330: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    after_11:
    // 0x80006334: b           L_800064D4
    // 0x80006338: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_800064D4;
    // 0x80006338: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8000633C:
    // 0x8000633C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x80006340: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80006344: jal         0x80005F00
    // 0x80006348: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80005F00(rdram, ctx);
        goto after_12;
    // 0x80006348: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_12:
    // 0x8000634C: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x80006350: addiu       $a1, $a1, 0x49D4
    ctx->r5 = ADD32(ctx->r5, 0X49D4);
    // 0x80006354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80006358: jal         0x80007098
    // 0x8000635C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_80007098(rdram, ctx);
        goto after_13;
    // 0x8000635C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_13:
    // 0x80006360: b           L_800064D4
    // 0x80006364: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_800064D4;
    // 0x80006364: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80006368:
    // 0x80006368: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8000636C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80006370: jal         0x80005F00
    // 0x80006374: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80005F00(rdram, ctx);
        goto after_14;
    // 0x80006374: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_14:
    // 0x80006378: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x8000637C: addiu       $a1, $a1, 0x49D8
    ctx->r5 = ADD32(ctx->r5, 0X49D8);
    // 0x80006380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80006384: jal         0x80007098
    // 0x80006388: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_80007098(rdram, ctx);
        goto after_15;
    // 0x80006388: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_15:
    // 0x8000638C: b           L_800064D4
    // 0x80006390: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_800064D4;
    // 0x80006390: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80006394:
    // 0x80006394: lw          $t0, 0x8($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X8);
    // 0x80006398: lw          $t8, 0x4($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X4);
    // 0x8000639C: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x800063A0: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x800063A4: sra         $t2, $t1, 16
    ctx->r10 = S32(SIGNED(ctx->r9) >> 16);
    // 0x800063A8: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800063AC: addu        $a2, $t8, $t3
    ctx->r6 = ADD32(ctx->r24, ctx->r11);
    // 0x800063B0: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800063B4: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800063B8: jal         0x80007098
    // 0x800063BC: addiu       $a1, $a1, 0x49DC
    ctx->r5 = ADD32(ctx->r5, 0X49DC);
    func_80007098(rdram, ctx);
        goto after_16;
    // 0x800063BC: addiu       $a1, $a1, 0x49DC
    ctx->r5 = ADD32(ctx->r5, 0X49DC);
    after_16:
    // 0x800063C0: b           L_800064D4
    // 0x800063C4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_800064D4;
    // 0x800063C4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800063C8:
    // 0x800063C8: lw          $a2, 0xC($s2)
    ctx->r6 = MEM_W(ctx->r18, 0XC);
    // 0x800063CC: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800063D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800063D4: beq         $a2, $zero, L_800063F4
    if (ctx->r6 == 0) {
        // 0x800063D8: lui         $a1, 0x8007
        ctx->r5 = S32(0X8007 << 16);
            goto L_800063F4;
    }
    // 0x800063D8: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x800063DC: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x800063E0: addiu       $a1, $a1, 0x49E4
    ctx->r5 = ADD32(ctx->r5, 0X49E4);
    // 0x800063E4: jal         0x80007098
    // 0x800063E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80007098(rdram, ctx);
        goto after_17;
    // 0x800063E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x800063EC: b           L_800064D4
    // 0x800063F0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_800064D4;
    // 0x800063F0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800063F4:
    // 0x800063F4: lw          $t4, 0x4($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X4);
    // 0x800063F8: lui         $at, 0xF000
    ctx->r1 = S32(0XF000 << 16);
    // 0x800063FC: lw          $t6, 0x8($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X8);
    // 0x80006400: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x80006404: lui         $at, 0x3FF
    ctx->r1 = S32(0X3FF << 16);
    // 0x80006408: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8000640C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80006410: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80006414: or          $a2, $t5, $t9
    ctx->r6 = ctx->r13 | ctx->r25;
    // 0x80006418: jal         0x80007098
    // 0x8000641C: addiu       $a1, $a1, 0x49E8
    ctx->r5 = ADD32(ctx->r5, 0X49E8);
    func_80007098(rdram, ctx);
        goto after_18;
    // 0x8000641C: addiu       $a1, $a1, 0x49E8
    ctx->r5 = ADD32(ctx->r5, 0X49E8);
    after_18:
    // 0x80006420: b           L_800064D4
    // 0x80006424: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_800064D4;
    // 0x80006424: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80006428:
    // 0x80006428: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x8000642C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x80006430: addiu       $a1, $a1, 0x49F0
    ctx->r5 = ADD32(ctx->r5, 0X49F0);
    // 0x80006434: jal         0x80007098
    // 0x80006438: lw          $a2, 0x8($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X8);
    func_80007098(rdram, ctx);
        goto after_19;
    // 0x80006438: lw          $a2, 0x8($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X8);
    after_19:
    // 0x8000643C: b           L_800064D4
    // 0x80006440: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_800064D4;
    // 0x80006440: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80006444:
    // 0x80006444: lw          $a2, 0x8($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X8);
    // 0x80006448: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x8000644C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80006450: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x80006454: sra         $t0, $a2, 6
    ctx->r8 = S32(SIGNED(ctx->r6) >> 6);
    // 0x80006458: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8000645C: and         $a2, $t0, $at
    ctx->r6 = ctx->r8 & ctx->r1;
    // 0x80006460: jal         0x80007098
    // 0x80006464: addiu       $a1, $a1, 0x49F8
    ctx->r5 = ADD32(ctx->r5, 0X49F8);
    func_80007098(rdram, ctx);
        goto after_20;
    // 0x80006464: addiu       $a1, $a1, 0x49F8
    ctx->r5 = ADD32(ctx->r5, 0X49F8);
    after_20:
    // 0x80006468: b           L_800064D4
    // 0x8000646C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_800064D4;
    // 0x8000646C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80006470:
    // 0x80006470: lw          $a2, 0x8($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X8);
    // 0x80006474: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x80006478: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8000647C: sra         $t2, $a2, 26
    ctx->r10 = S32(SIGNED(ctx->r6) >> 26);
    // 0x80006480: andi        $a2, $t2, 0x3
    ctx->r6 = ctx->r10 & 0X3;
    // 0x80006484: jal         0x80007098
    // 0x80006488: addiu       $a1, $a1, 0x4A00
    ctx->r5 = ADD32(ctx->r5, 0X4A00);
    func_80007098(rdram, ctx);
        goto after_21;
    // 0x80006488: addiu       $a1, $a1, 0x4A00
    ctx->r5 = ADD32(ctx->r5, 0X4A00);
    after_21:
    // 0x8000648C: b           L_800064D4
    // 0x80006490: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_800064D4;
    // 0x80006490: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80006494:
    // 0x80006494: lw          $t3, 0x8($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X8);
    // 0x80006498: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x8000649C: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x800064A0: sra         $t4, $t3, 21
    ctx->r12 = S32(SIGNED(ctx->r11) >> 21);
    // 0x800064A4: andi        $t6, $t4, 0xF
    ctx->r14 = ctx->r12 & 0XF;
    // 0x800064A8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800064AC: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x800064B0: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800064B4: lw          $a2, 0x7250($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7250);
    // 0x800064B8: jal         0x80007098
    // 0x800064BC: addiu       $a1, $a1, 0x4A04
    ctx->r5 = ADD32(ctx->r5, 0X4A04);
    func_80007098(rdram, ctx);
        goto after_22;
    // 0x800064BC: addiu       $a1, $a1, 0x4A04
    ctx->r5 = ADD32(ctx->r5, 0X4A04);
    after_22:
    // 0x800064C0: b           L_800064D4
    // 0x800064C4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_800064D4;
    // 0x800064C4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800064C8: sb          $a3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r7;
L_800064CC:
    // 0x800064CC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800064D0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800064D4:
    // 0x800064D4: lbu         $a3, 0x0($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X0);
    // 0x800064D8: bnel        $a3, $zero, L_80006154
    if (ctx->r7 != 0) {
        // 0x800064DC: addiu       $at, $zero, 0x3B
        ctx->r1 = ADD32(0, 0X3B);
            goto L_80006154;
    }
    goto skip_0;
    // 0x800064DC: addiu       $at, $zero, 0x3B
    ctx->r1 = ADD32(0, 0X3B);
    skip_0:
L_800064E0:
    // 0x800064E0: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x800064E4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800064E8: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x800064EC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800064F0: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800064F4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800064F8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800064FC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80006500: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80006504: jr          $ra
    // 0x80006508: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    TRACE_RETURN()
    return;
    // 0x80006508: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void func_8000650C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000650C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80006510: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80006514: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80006518: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8000651C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80006520: lw          $a2, 0x8($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X8);
    // 0x80006524: jal         0x80006110
    // 0x80006528: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_80006110(rdram, ctx);
        goto after_0;
    // 0x80006528: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x8000652C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006530: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80006534: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000653C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000653C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80006540: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80006544: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80006548: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x8000654C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80006550: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80006554: sra         $v1, $v0, 21
    ctx->r3 = S32(SIGNED(ctx->r2) >> 21);
    // 0x80006558: andi        $t7, $v1, 0x1F
    ctx->r15 = ctx->r3 & 0X1F;
    // 0x8000655C: sra         $a2, $v0, 16
    ctx->r6 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80006560: beq         $t7, $zero, L_800065A4
    if (ctx->r15 == 0) {
        // 0x80006564: andi        $t8, $a2, 0x1F
        ctx->r24 = ctx->r6 & 0X1F;
            goto L_800065A4;
    }
    // 0x80006564: andi        $t8, $a2, 0x1F
    ctx->r24 = ctx->r6 & 0X1F;
    // 0x80006568: beq         $t7, $t8, L_8000658C
    if (ctx->r15 == ctx->r24) {
        // 0x8000656C: addiu       $a0, $sp, 0x20
        ctx->r4 = ADD32(ctx->r29, 0X20);
            goto L_8000658C;
    }
    // 0x8000656C: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80006570: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x80006574: addiu       $a1, $a1, 0x4A08
    ctx->r5 = ADD32(ctx->r5, 0X4A08);
    // 0x80006578: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8000657C: jal         0x80007098
    // 0x80006580: lw          $a2, 0x8($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X8);
    func_80007098(rdram, ctx);
        goto after_0;
    // 0x80006580: lw          $a2, 0x8($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X8);
    after_0:
    // 0x80006584: b           L_800065B4
    // 0x80006588: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
        goto L_800065B4;
    // 0x80006588: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
L_8000658C:
    // 0x8000658C: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x80006590: addiu       $a1, $a1, 0x4A1C
    ctx->r5 = ADD32(ctx->r5, 0X4A1C);
    // 0x80006594: jal         0x80007098
    // 0x80006598: lw          $a2, 0x8($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X8);
    func_80007098(rdram, ctx);
        goto after_1;
    // 0x80006598: lw          $a2, 0x8($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X8);
    after_1:
    // 0x8000659C: b           L_800065B4
    // 0x800065A0: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
        goto L_800065B4;
    // 0x800065A0: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
L_800065A4:
    // 0x800065A4: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x800065A8: jal         0x80007098
    // 0x800065AC: addiu       $a1, $a1, 0x4A28
    ctx->r5 = ADD32(ctx->r5, 0X4A28);
    func_80007098(rdram, ctx);
        goto after_2;
    // 0x800065AC: addiu       $a1, $a1, 0x4A28
    ctx->r5 = ADD32(ctx->r5, 0X4A28);
    after_2:
    // 0x800065B0: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
L_800065B4:
    // 0x800065B4: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x800065B8: jal         0x80006110
    // 0x800065BC: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    func_80006110(rdram, ctx);
        goto after_3;
    // 0x800065BC: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    after_3:
    // 0x800065C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800065C4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x800065C8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800065D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800065D0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800065D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800065D8: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x800065DC: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x800065E0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800065E4: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x800065E8: sra         $v1, $v0, 21
    ctx->r3 = S32(SIGNED(ctx->r2) >> 21);
    // 0x800065EC: sra         $a2, $v0, 16
    ctx->r6 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800065F0: andi        $t6, $v1, 0x1F
    ctx->r14 = ctx->r3 & 0X1F;
    // 0x800065F4: andi        $t7, $a2, 0x1F
    ctx->r15 = ctx->r6 & 0X1F;
    // 0x800065F8: beq         $t6, $t7, L_80006624
    if (ctx->r14 == ctx->r15) {
        // 0x800065FC: lw          $t9, 0x6C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X6C);
            goto L_80006624;
    }
    // 0x800065FC: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x80006600: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x80006604: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x80006608: addiu       $a1, $a1, 0x4A34
    ctx->r5 = ADD32(ctx->r5, 0X4A34);
    // 0x8000660C: lw          $a2, 0x8($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X8);
    // 0x80006610: sw          $a3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r7;
    // 0x80006614: jal         0x80007098
    // 0x80006618: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    func_80007098(rdram, ctx);
        goto after_0;
    // 0x80006618: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x8000661C: b           L_8000663C
    // 0x80006620: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
        goto L_8000663C;
    // 0x80006620: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
L_80006624:
    // 0x80006624: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x80006628: lw          $a2, 0x8($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X8);
    // 0x8000662C: sw          $a3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r7;
    // 0x80006630: jal         0x80007098
    // 0x80006634: addiu       $a1, $a1, 0x4A44
    ctx->r5 = ADD32(ctx->r5, 0X4A44);
    func_80007098(rdram, ctx);
        goto after_1;
    // 0x80006634: addiu       $a1, $a1, 0x4A44
    ctx->r5 = ADD32(ctx->r5, 0X4A44);
    after_1:
    // 0x80006638: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
L_8000663C:
    // 0x8000663C: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80006640: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80006644: jal         0x80006110
    // 0x80006648: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_80006110(rdram, ctx);
        goto after_2;
    // 0x80006648: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_2:
    // 0x8000664C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006650: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80006654: jr          $ra
    TRACE_RETURN()
    return;
;}
