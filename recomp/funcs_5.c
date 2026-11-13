#include "recomp.h"
#include "trace.h"
#include "funcs.h"

extern void chopper_fiber_run_frame(uint8_t* rdram, recomp_context* ctx);
extern void chopper_fiber_yield(uint8_t* rdram, recomp_context* ctx);

RECOMP_FUNC void func_80007424(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80007424: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x80007428: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x8000742C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80007430: bnel        $t6, $v0, L_80007444
    if (ctx->r14 != ctx->r2) {
        // 0x80007434: lw          $a3, 0x14($a0)
        ctx->r7 = MEM_W(ctx->r4, 0X14);
            goto L_80007444;
    }
    goto skip_0;
    // 0x80007434: lw          $a3, 0x14($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X14);
    skip_0:
    // 0x80007438: jr          $ra
    // 0x8000743C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    TRACE_RETURN()
    return;
    // 0x8000743C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80007440: lw          $a3, 0x14($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X14);
L_80007444:
    // 0x80007444: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80007448: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000744C: andi        $t7, $a3, 0x3
    ctx->r15 = ctx->r7 & 0X3;
    // 0x80007450: beq         $t7, $zero, L_800074C0
    if (ctx->r15 == 0) {
        // 0x80007454: andi        $a2, $a3, 0xF
        ctx->r6 = ctx->r7 & 0XF;
            goto L_800074C0;
    }
    // 0x80007454: andi        $a2, $a3, 0xF
    ctx->r6 = ctx->r7 & 0XF;
    // 0x80007458: andi        $a2, $a3, 0x3
    ctx->r6 = ctx->r7 & 0X3;
    // 0x8000745C: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    // 0x80007460: beq         $a2, $zero, L_80007488
    if (ctx->r6 == 0) {
        // 0x80007464: addu        $v0, $a2, $a3
        ctx->r2 = ADD32(ctx->r6, ctx->r7);
            goto L_80007488;
    }
    // 0x80007464: addu        $v0, $a2, $a3
    ctx->r2 = ADD32(ctx->r6, ctx->r7);
L_80007468:
    // 0x80007468: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x8000746C: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x80007470: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80007474: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80007478: bne         $v0, $a3, L_80007468
    if (ctx->r2 != ctx->r7) {
        // 0x8000747C: sb          $t8, -0x1($a1)
        MEM_B(-0X1, ctx->r5) = ctx->r24;
            goto L_80007468;
    }
    // 0x8000747C: sb          $t8, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r24;
    // 0x80007480: beql        $a3, $zero, L_80007520
    if (ctx->r7 == 0) {
        // 0x80007484: lw          $t8, 0x4($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X4);
            goto L_80007520;
    }
    goto skip_1;
    // 0x80007484: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    skip_1:
L_80007488:
    // 0x80007488: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x8000748C: addiu       $a3, $a3, -0x4
    ctx->r7 = ADD32(ctx->r7, -0X4);
    // 0x80007490: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80007494: sb          $t9, -0x4($a1)
    MEM_B(-0X4, ctx->r5) = ctx->r25;
    // 0x80007498: lbu         $t0, 0x1($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X1);
    // 0x8000749C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800074A0: sb          $t0, -0x3($a1)
    MEM_B(-0X3, ctx->r5) = ctx->r8;
    // 0x800074A4: lbu         $t1, -0x2($v1)
    ctx->r9 = MEM_BU(ctx->r3, -0X2);
    // 0x800074A8: sb          $t1, -0x2($a1)
    MEM_B(-0X2, ctx->r5) = ctx->r9;
    // 0x800074AC: lbu         $t2, -0x1($v1)
    ctx->r10 = MEM_BU(ctx->r3, -0X1);
    // 0x800074B0: bne         $a3, $zero, L_80007488
    if (ctx->r7 != 0) {
        // 0x800074B4: sb          $t2, -0x1($a1)
        MEM_B(-0X1, ctx->r5) = ctx->r10;
            goto L_80007488;
    }
    // 0x800074B4: sb          $t2, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r10;
    // 0x800074B8: b           L_80007520
    // 0x800074BC: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
        goto L_80007520;
    // 0x800074BC: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
L_800074C0:
    // 0x800074C0: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    // 0x800074C4: beq         $a2, $zero, L_800074EC
    if (ctx->r6 == 0) {
        // 0x800074C8: addu        $v0, $a2, $a3
        ctx->r2 = ADD32(ctx->r6, ctx->r7);
            goto L_800074EC;
    }
    // 0x800074C8: addu        $v0, $a2, $a3
    ctx->r2 = ADD32(ctx->r6, ctx->r7);
L_800074CC:
    // 0x800074CC: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800074D0: addiu       $a3, $a3, -0x4
    ctx->r7 = ADD32(ctx->r7, -0X4);
    // 0x800074D4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800074D8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800074DC: bne         $v0, $a3, L_800074CC
    if (ctx->r2 != ctx->r7) {
        // 0x800074E0: sw          $t3, -0x4($a1)
        MEM_W(-0X4, ctx->r5) = ctx->r11;
            goto L_800074CC;
    }
    // 0x800074E0: sw          $t3, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r11;
    // 0x800074E4: beql        $a3, $zero, L_80007520
    if (ctx->r7 == 0) {
        // 0x800074E8: lw          $t8, 0x4($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X4);
            goto L_80007520;
    }
    goto skip_2;
    // 0x800074E8: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    skip_2:
L_800074EC:
    // 0x800074EC: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800074F0: addiu       $a3, $a3, -0x10
    ctx->r7 = ADD32(ctx->r7, -0X10);
    // 0x800074F4: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800074F8: sw          $t4, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->r12;
    // 0x800074FC: lw          $t5, 0x4($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X4);
    // 0x80007500: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80007504: sw          $t5, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->r13;
    // 0x80007508: lw          $t6, -0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, -0X8);
    // 0x8000750C: sw          $t6, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->r14;
    // 0x80007510: lw          $t7, -0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, -0X4);
    // 0x80007514: bne         $a3, $zero, L_800074EC
    if (ctx->r7 != 0) {
        // 0x80007518: sw          $t7, -0x4($a1)
        MEM_W(-0X4, ctx->r5) = ctx->r15;
            goto L_800074EC;
    }
    // 0x80007518: sw          $t7, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r15;
    // 0x8000751C: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
L_80007520:
    // 0x80007520: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80007524: sltu        $at, $v1, $t8
    ctx->r1 = ctx->r3 < ctx->r24 ? 1 : 0;
    // 0x80007528: bnel        $at, $zero, L_80007538
    if (ctx->r1 != 0) {
        // 0x8000752C: sw          $v1, 0x8($a0)
        MEM_W(0X8, ctx->r4) = ctx->r3;
            goto L_80007538;
    }
    goto skip_3;
    // 0x8000752C: sw          $v1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r3;
    skip_3:
    // 0x80007530: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80007534: sw          $v1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r3;
L_80007538:
    // 0x80007538: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80007540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80007540: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x80007544: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x80007548: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8000754C: bnel        $t6, $v0, L_80007560
    if (ctx->r14 != ctx->r2) {
        // 0x80007550: lw          $a3, 0x14($a0)
        ctx->r7 = MEM_W(ctx->r4, 0X14);
            goto L_80007560;
    }
    goto skip_0;
    // 0x80007550: lw          $a3, 0x14($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X14);
    skip_0:
    // 0x80007554: jr          $ra
    // 0x80007558: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    TRACE_RETURN()
    return;
    // 0x80007558: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000755C: lw          $a3, 0x14($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X14);
L_80007560:
    // 0x80007560: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80007564: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80007568: andi        $t7, $a3, 0x3
    ctx->r15 = ctx->r7 & 0X3;
    // 0x8000756C: beq         $t7, $zero, L_800075DC
    if (ctx->r15 == 0) {
        // 0x80007570: andi        $a0, $a3, 0xF
        ctx->r4 = ctx->r7 & 0XF;
            goto L_800075DC;
    }
    // 0x80007570: andi        $a0, $a3, 0xF
    ctx->r4 = ctx->r7 & 0XF;
    // 0x80007574: andi        $a0, $a3, 0x3
    ctx->r4 = ctx->r7 & 0X3;
    // 0x80007578: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x8000757C: beq         $a0, $zero, L_800075A4
    if (ctx->r4 == 0) {
        // 0x80007580: addu        $v0, $a0, $a3
        ctx->r2 = ADD32(ctx->r4, ctx->r7);
            goto L_800075A4;
    }
    // 0x80007580: addu        $v0, $a0, $a3
    ctx->r2 = ADD32(ctx->r4, ctx->r7);
L_80007584:
    // 0x80007584: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x80007588: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x8000758C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80007590: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80007594: bne         $v0, $a3, L_80007584
    if (ctx->r2 != ctx->r7) {
        // 0x80007598: sb          $t8, -0x1($a1)
        MEM_B(-0X1, ctx->r5) = ctx->r24;
            goto L_80007584;
    }
    // 0x80007598: sb          $t8, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r24;
    // 0x8000759C: beql        $a3, $zero, L_8000763C
    if (ctx->r7 == 0) {
        // 0x800075A0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000763C;
    }
    goto skip_1;
    // 0x800075A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
L_800075A4:
    // 0x800075A4: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x800075A8: addiu       $a3, $a3, -0x4
    ctx->r7 = ADD32(ctx->r7, -0X4);
    // 0x800075AC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800075B0: sb          $t9, -0x4($a1)
    MEM_B(-0X4, ctx->r5) = ctx->r25;
    // 0x800075B4: lbu         $t0, 0x1($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X1);
    // 0x800075B8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800075BC: sb          $t0, -0x3($a1)
    MEM_B(-0X3, ctx->r5) = ctx->r8;
    // 0x800075C0: lbu         $t1, -0x2($v1)
    ctx->r9 = MEM_BU(ctx->r3, -0X2);
    // 0x800075C4: sb          $t1, -0x2($a1)
    MEM_B(-0X2, ctx->r5) = ctx->r9;
    // 0x800075C8: lbu         $t2, -0x1($v1)
    ctx->r10 = MEM_BU(ctx->r3, -0X1);
    // 0x800075CC: bne         $a3, $zero, L_800075A4
    if (ctx->r7 != 0) {
        // 0x800075D0: sb          $t2, -0x1($a1)
        MEM_B(-0X1, ctx->r5) = ctx->r10;
            goto L_800075A4;
    }
    // 0x800075D0: sb          $t2, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r10;
    // 0x800075D4: b           L_8000763C
    // 0x800075D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8000763C;
    // 0x800075D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800075DC:
    // 0x800075DC: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x800075E0: beq         $a0, $zero, L_80007608
    if (ctx->r4 == 0) {
        // 0x800075E4: addu        $v0, $a0, $a3
        ctx->r2 = ADD32(ctx->r4, ctx->r7);
            goto L_80007608;
    }
    // 0x800075E4: addu        $v0, $a0, $a3
    ctx->r2 = ADD32(ctx->r4, ctx->r7);
L_800075E8:
    // 0x800075E8: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800075EC: addiu       $a3, $a3, -0x4
    ctx->r7 = ADD32(ctx->r7, -0X4);
    // 0x800075F0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800075F4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800075F8: bne         $v0, $a3, L_800075E8
    if (ctx->r2 != ctx->r7) {
        // 0x800075FC: sw          $t3, -0x4($a1)
        MEM_W(-0X4, ctx->r5) = ctx->r11;
            goto L_800075E8;
    }
    // 0x800075FC: sw          $t3, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r11;
    // 0x80007600: beql        $a3, $zero, L_8000763C
    if (ctx->r7 == 0) {
        // 0x80007604: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000763C;
    }
    goto skip_2;
    // 0x80007604: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
L_80007608:
    // 0x80007608: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8000760C: addiu       $a3, $a3, -0x10
    ctx->r7 = ADD32(ctx->r7, -0X10);
    // 0x80007610: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80007614: sw          $t4, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->r12;
    // 0x80007618: lw          $t5, 0x4($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X4);
    // 0x8000761C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80007620: sw          $t5, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->r13;
    // 0x80007624: lw          $t6, -0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, -0X8);
    // 0x80007628: sw          $t6, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->r14;
    // 0x8000762C: lw          $t7, -0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, -0X4);
    // 0x80007630: bne         $a3, $zero, L_80007608
    if (ctx->r7 != 0) {
        // 0x80007634: sw          $t7, -0x4($a1)
        MEM_W(-0X4, ctx->r5) = ctx->r15;
            goto L_80007608;
    }
    // 0x80007634: sw          $t7, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r15;
    // 0x80007638: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000763C:
    // 0x8000763C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80007650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80007650: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80007654: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80007658: beq         $a2, $zero, L_800076FC
    if (ctx->r6 == 0) {
        // 0x8000765C: or          $a3, $a2, $zero
        ctx->r7 = ctx->r6 | 0;
            goto L_800076FC;
    }
    // 0x8000765C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80007660: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80007664: addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
    // 0x80007668: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
L_8000766C:
    // 0x8000766C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80007670: slti        $at, $a0, 0x80
    ctx->r1 = SIGNED(ctx->r4) < 0X80 ? 1 : 0;
    // 0x80007674: beq         $at, $zero, L_80007698
    if (ctx->r1 == 0) {
        // 0x80007678: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_80007698;
    }
    // 0x80007678: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8000767C: slti        $at, $a1, 0x20
    ctx->r1 = SIGNED(ctx->r5) < 0X20 ? 1 : 0;
    // 0x80007680: bne         $at, $zero, L_80007690
    if (ctx->r1 != 0) {
        // 0x80007684: nop
    
            goto L_80007690;
    }
    // 0x80007684: nop

    // 0x80007688: bnel        $a2, $a1, L_800076EC
    if (ctx->r6 != ctx->r5) {
        // 0x8000768C: sb          $a0, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r4;
            goto L_800076EC;
    }
    goto skip_0;
    // 0x8000768C: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
    skip_0:
L_80007690:
    // 0x80007690: b           L_800076E8
    // 0x80007694: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
        goto L_800076E8;
    // 0x80007694: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
L_80007698:
    // 0x80007698: beq         $a3, $t0, L_800076E4
    if (ctx->r7 == ctx->r8) {
        // 0x8000769C: slti        $at, $a1, 0xA0
        ctx->r1 = SIGNED(ctx->r5) < 0XA0 ? 1 : 0;
            goto L_800076E4;
    }
    // 0x8000769C: slti        $at, $a1, 0xA0
    ctx->r1 = SIGNED(ctx->r5) < 0XA0 ? 1 : 0;
    // 0x800076A0: bne         $at, $zero, L_800076E4
    if (ctx->r1 != 0) {
        // 0x800076A4: slti        $at, $a1, 0xFF
        ctx->r1 = SIGNED(ctx->r5) < 0XFF ? 1 : 0;
            goto L_800076E4;
    }
    // 0x800076A4: slti        $at, $a1, 0xFF
    ctx->r1 = SIGNED(ctx->r5) < 0XFF ? 1 : 0;
    // 0x800076A8: beql        $at, $zero, L_800076E8
    if (ctx->r1 == 0) {
        // 0x800076AC: addiu       $a0, $zero, 0x2E
        ctx->r4 = ADD32(0, 0X2E);
            goto L_800076E8;
    }
    goto skip_1;
    // 0x800076AC: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    skip_1:
    // 0x800076B0: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    // 0x800076B4: slti        $at, $a1, 0xA0
    ctx->r1 = SIGNED(ctx->r5) < 0XA0 ? 1 : 0;
    // 0x800076B8: bne         $at, $zero, L_800076E4
    if (ctx->r1 != 0) {
        // 0x800076BC: slti        $at, $a1, 0xFF
        ctx->r1 = SIGNED(ctx->r5) < 0XFF ? 1 : 0;
            goto L_800076E4;
    }
    // 0x800076BC: slti        $at, $a1, 0xFF
    ctx->r1 = SIGNED(ctx->r5) < 0XFF ? 1 : 0;
    // 0x800076C0: beql        $at, $zero, L_800076E8
    if (ctx->r1 == 0) {
        // 0x800076C4: addiu       $a0, $zero, 0x2E
        ctx->r4 = ADD32(0, 0X2E);
            goto L_800076E8;
    }
    goto skip_2;
    // 0x800076C4: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    skip_2:
    // 0x800076C8: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
    // 0x800076CC: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800076D0: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800076D4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800076D8: addiu       $a3, $a3, -0x2
    ctx->r7 = ADD32(ctx->r7, -0X2);
    // 0x800076DC: b           L_800076F4
    // 0x800076E0: sb          $t6, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r14;
        goto L_800076F4;
    // 0x800076E0: sb          $t6, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r14;
L_800076E4:
    // 0x800076E4: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
L_800076E8:
    // 0x800076E8: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
L_800076EC:
    // 0x800076EC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800076F0: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
L_800076F4:
    // 0x800076F4: bnel        $a3, $zero, L_8000766C
    if (ctx->r7 != 0) {
        // 0x800076F8: lbu         $a0, 0x0($v0)
        ctx->r4 = MEM_BU(ctx->r2, 0X0);
            goto L_8000766C;
    }
    goto skip_3;
    // 0x800076F8: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    skip_3:
L_800076FC:
    // 0x800076FC: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x80007700: jr          $ra
    // 0x80007704: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    TRACE_RETURN()
    return;
    // 0x80007704: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80007708(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80007708: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000770C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80007710: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80007714: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80007718: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000771C: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80007720: or          $s5, $a3, $zero
    ctx->r21 = ctx->r7 | 0;
    // 0x80007724: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80007728: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8000772C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80007730: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80007734: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80007738: blez        $a2, L_800077B0
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8000773C: or          $s3, $a0, $zero
        ctx->r19 = ctx->r4 | 0;
            goto L_800077B0;
    }
    // 0x8000773C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80007740: lui         $s6, 0x8007
    ctx->r22 = S32(0X8007 << 16);
    // 0x80007744: lui         $s4, 0x8007
    ctx->r20 = S32(0X8007 << 16);
    // 0x80007748: addiu       $s4, $s4, 0x5E40
    ctx->r20 = ADD32(ctx->r20, 0X5E40);
    // 0x8000774C: addiu       $s6, $s6, 0x5E48
    ctx->r22 = ADD32(ctx->r22, 0X5E48);
L_80007750:
    // 0x80007750: bne         $s5, $zero, L_8000775C
    if (ctx->r21 != 0) {
        // 0x80007754: or          $s0, $s5, $zero
        ctx->r16 = ctx->r21 | 0;
            goto L_8000775C;
    }
    // 0x80007754: or          $s0, $s5, $zero
    ctx->r16 = ctx->r21 | 0;
    // 0x80007758: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8000775C:
    // 0x8000775C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80007760: beq         $s0, $zero, L_80007794
    if (ctx->r16 == 0) {
        // 0x80007764: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_80007794;
    }
    // 0x80007764: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_80007768:
    // 0x80007768: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000776C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80007770: lbu         $a2, 0x0($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X0);
    // 0x80007774: jal         0x80007098
    // 0x80007778: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    func_80007098(rdram, ctx);
        goto after_0;
    // 0x80007778: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    after_0:
    // 0x8000777C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80007780: blez        $s1, L_80007794
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80007784: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80007794;
    }
    // 0x80007784: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80007788: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8000778C: bne         $s0, $zero, L_80007768
    if (ctx->r16 != 0) {
        // 0x80007790: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_80007768;
    }
    // 0x80007790: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_80007794:
    // 0x80007794: beq         $s1, $zero, L_800077A8
    if (ctx->r17 == 0) {
        // 0x80007798: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800077A8;
    }
    // 0x80007798: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000779C: jal         0x80007098
    // 0x800077A0: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_80007098(rdram, ctx);
        goto after_1;
    // 0x800077A0: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_1:
    // 0x800077A4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
L_800077A8:
    // 0x800077A8: bgtz        $s1, L_80007750
    if (SIGNED(ctx->r17) > 0) {
        // 0x800077AC: nop
    
            goto L_80007750;
    }
    // 0x800077AC: nop

L_800077B0:
    // 0x800077B0: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    // 0x800077B4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800077B8: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x800077BC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800077C0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800077C4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800077C8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800077CC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800077D0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800077D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800077D8: jr          $ra
    // 0x800077DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    TRACE_RETURN()
    return;
    // 0x800077DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
static void func_800077E0_entry(uint8_t* rdram, recomp_context* ctx, unsigned entry) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    if (entry == 1) goto indirect_80007970;


    // 0x800077E0: addiu       $sp, $sp, -0x1060
    ctx->r29 = ADD32(ctx->r29, -0X1060);
    // 0x800077E4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800077E8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800077EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800077F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800077F4: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800077F8: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800077FC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80007800: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80007804: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80007808: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8000780C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80007810: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80007814: bne         $a3, $zero, L_80007820
    if (ctx->r7 != 0) {
        // 0x80007818: sw          $s3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r19;
            goto L_80007820;
    }
    // 0x80007818: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000781C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80007820:
    // 0x80007820: lw          $s5, 0x1070($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1070);
    // 0x80007824: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x80007828: addiu       $a1, $a1, 0x5E4C
    ctx->r5 = ADD32(ctx->r5, 0X5E4C);
    // 0x8000782C: div         $zero, $s5, $a3
    lo = S32(S64(S32(ctx->r21)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r21)) % S64(S32(ctx->r7)));
    // 0x80007830: mflo        $t7
    ctx->r15 = lo;
    // 0x80007834: sll         $t6, $s5, 1
    ctx->r14 = S32(ctx->r21 << 1);
    // 0x80007838: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    // 0x8000783C: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x80007840: bne         $a3, $zero, L_8000784C
    if (ctx->r7 != 0) {
        // 0x80007844: nop
    
            goto L_8000784C;
    }
    // 0x80007844: nop

    // 0x80007848: break       7
    do_break(2147514440);
L_8000784C:
    // 0x8000784C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80007850: bne         $a3, $at, L_80007864
    if (ctx->r7 != ctx->r1) {
        // 0x80007854: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80007864;
    }
    // 0x80007854: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80007858: bne         $s5, $at, L_80007864
    if (ctx->r21 != ctx->r1) {
        // 0x8000785C: nop
    
            goto L_80007864;
    }
    // 0x8000785C: nop

    // 0x80007860: break       6
    do_break(2147514464);
L_80007864:
    // 0x80007864: sw          $a3, 0x106C($sp)
    MEM_W(0X106C, ctx->r29) = ctx->r7;
    // 0x80007868: jal         0x80007098
    // 0x8000786C: nop

    func_80007098(rdram, ctx);
        goto after_0;
    // 0x8000786C: nop

    after_0:
    // 0x80007870: or          $s3, $s0, $zero
    ctx->r19 = ctx->r16 | 0;
    // 0x80007874: beq         $s2, $zero, L_8000793C
    if (ctx->r18 == 0) {
        // 0x80007878: or          $s4, $s1, $zero
        ctx->r20 = ctx->r17 | 0;
            goto L_8000793C;
    }
    // 0x80007878: or          $s4, $s1, $zero
    ctx->r20 = ctx->r17 | 0;
    // 0x8000787C: lw          $v0, 0x1074($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1074);
    // 0x80007880: addiu       $s7, $sp, 0x454
    ctx->r23 = ADD32(ctx->r29, 0X454);
    // 0x80007884: addiu       $s6, $sp, 0x854
    ctx->r22 = ADD32(ctx->r29, 0X854);
    // 0x80007888: andi        $t8, $v0, 0x2
    ctx->r24 = ctx->r2 & 0X2;
    // 0x8000788C: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x80007890: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x80007894: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x80007898: andi        $fp, $v0, 0x4
    ctx->r30 = ctx->r2 & 0X4;
L_8000789C:
    // 0x8000789C: slt         $at, $s5, $s2
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x800078A0: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x800078A4: beq         $at, $zero, L_800078B0
    if (ctx->r1 == 0) {
        // 0x800078A8: addiu       $s1, $sp, 0xC54
        ctx->r17 = ADD32(ctx->r29, 0XC54);
            goto L_800078B0;
    }
    // 0x800078A8: addiu       $s1, $sp, 0xC54
    ctx->r17 = ADD32(ctx->r29, 0XC54);
    // 0x800078AC: or          $s0, $s5, $zero
    ctx->r16 = ctx->r21 | 0;
L_800078B0:
    // 0x800078B0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800078B4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800078B8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800078BC: jal         0x80007708
    // 0x800078C0: lw          $a3, 0x106C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X106C);
    func_80007708(rdram, ctx);
        goto after_1;
    // 0x800078C0: lw          $a3, 0x106C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X106C);
    after_1:
    // 0x800078C4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800078C8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800078CC: jal         0x80007650
    // 0x800078D0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80007650(rdram, ctx);
        goto after_2;
    // 0x800078D0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_2:
    // 0x800078D4: beq         $fp, $zero, L_800078F0
    if (ctx->r30 == 0) {
        // 0x800078D8: addiu       $a0, $sp, 0xC54
        ctx->r4 = ADD32(ctx->r29, 0XC54);
            goto L_800078F0;
    }
    // 0x800078D8: addiu       $a0, $sp, 0xC54
    ctx->r4 = ADD32(ctx->r29, 0XC54);
    // 0x800078DC: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x800078E0: addiu       $a1, $a1, 0x5E54
    ctx->r5 = ADD32(ctx->r5, 0X5E54);
    // 0x800078E4: jal         0x80007098
    // 0x800078E8: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_80007098(rdram, ctx);
        goto after_3;
    // 0x800078E8: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_3:
    // 0x800078EC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_800078F0:
    // 0x800078F0: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800078F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800078F8: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x800078FC: beql        $t0, $zero, L_80007914
    if (ctx->r8 == 0) {
        // 0x80007900: lw          $t1, 0x40($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X40);
            goto L_80007914;
    }
    goto skip_0;
    // 0x80007900: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    skip_0:
    // 0x80007904: jal         0x80007098
    // 0x80007908: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_80007098(rdram, ctx);
        goto after_4;
    // 0x80007908: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_4:
    // 0x8000790C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80007910: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
L_80007914:
    // 0x80007914: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x80007918: addiu       $a1, $a1, 0x5E5C
    ctx->r5 = ADD32(ctx->r5, 0X5E5C);
    // 0x8000791C: beq         $t1, $zero, L_8000792C
    if (ctx->r9 == 0) {
        // 0x80007920: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8000792C;
    }
    // 0x80007920: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80007924: jal         0x80007098
    // 0x80007928: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    func_80007098(rdram, ctx);
        goto after_5;
    // 0x80007928: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_5:
L_8000792C:
    // 0x8000792C: subu        $s2, $s2, $s0
    ctx->r18 = SUB32(ctx->r18, ctx->r16);
    // 0x80007930: addu        $s3, $s3, $s0
    ctx->r19 = ADD32(ctx->r19, ctx->r16);
    // 0x80007934: bne         $s2, $zero, L_8000789C
    if (ctx->r18 != 0) {
        // 0x80007938: addu        $s4, $s4, $s0
        ctx->r20 = ADD32(ctx->r20, ctx->r16);
            goto L_8000789C;
    }
    // 0x80007938: addu        $s4, $s4, $s0
    ctx->r20 = ADD32(ctx->r20, ctx->r16);
L_8000793C:
    // 0x8000793C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80007940: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80007944: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80007948: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000794C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80007950: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80007954: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80007958: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8000795C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80007960: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80007964: jr          $ra
    // 0x80007968: addiu       $sp, $sp, 0x1060
    ctx->r29 = ADD32(ctx->r29, 0X1060);
    TRACE_RETURN()
    return;
    // 0x80007968: addiu       $sp, $sp, 0x1060
    ctx->r29 = ADD32(ctx->r29, 0X1060);
    // 0x8000796C: nop

indirect_80007970:
    // 0x80007970: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80007974: addiu       $a0, $a0, -0x4A3C
    ctx->r4 = ADD32(ctx->r4, -0X4A3C);
    // 0x80007978: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x8000797C: jal         0x80004E5C
    // 0x80007980: addi        $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    func_80004E5C(rdram, ctx);
        goto after_6;
    // 0x80007980: addi        $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    after_6:
    // 0x80007984: jal         0x80007A80
    // 0x80007988: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    func_80007A80(rdram, ctx);
        goto after_7;
    // 0x80007988: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    after_7:
;}
RECOMP_FUNC void func_800077E0(uint8_t* rdram, recomp_context* ctx) { func_800077E0_entry(rdram, ctx, 0); }
RECOMP_FUNC void func_80007970(uint8_t* rdram, recomp_context* ctx) { func_800077E0_entry(rdram, ctx, 1); }


RECOMP_FUNC void func_8000798C(uint8_t* rdram, recomp_context* ctx) {
    TRACE_ENTRY()
    chopper_fiber_yield(rdram, ctx);
    TRACE_RETURN()
    return;
}
RECOMP_FUNC void func_80007A80(uint8_t* rdram, recomp_context* ctx) {
    TRACE_ENTRY()
    chopper_fiber_yield(rdram, ctx);
    TRACE_RETURN()
    return;
}
RECOMP_FUNC void func_80007B60(uint8_t* rdram, recomp_context* ctx) {
    TRACE_ENTRY()
    chopper_fiber_run_frame(rdram, ctx);
    TRACE_RETURN()
    return;
}
RECOMP_FUNC void func_80007C50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80007C50: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
    // 0x80007C54: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
    // 0x80007C58: sw          $a0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r4;
    // 0x80007C5C: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x80007C60: sw          $a2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r6;
    // 0x80007C64: sw          $a3, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r7;
    // 0x80007C68: sw          $s0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r16;
    // 0x80007C6C: sw          $s1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r17;
    // 0x80007C70: sw          $s2, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r18;
    // 0x80007C74: sw          $s3, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r19;
    // 0x80007C78: sw          $s4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r20;
    // 0x80007C7C: sw          $s5, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r21;
    // 0x80007C80: sw          $s6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r22;
    // 0x80007C84: sw          $s7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r23;
    // 0x80007C88: sw          $gp, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r28;
    // 0x80007C8C: sw          $fp, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r30;
    // 0x80007C90: sw          $ra, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r31;
    // 0x80007C94: swc1        $f1, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f_odd[(1 - 1) * 2];
    // 0x80007C98: swc1        $f2, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f2.u32l;
    // 0x80007C9C: swc1        $f3, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f_odd[(3 - 1) * 2];
    // 0x80007CA0: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
    // 0x80007CA4: swc1        $f5, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f_odd[(5 - 1) * 2];
    // 0x80007CA8: swc1        $f6, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f6.u32l;
    // 0x80007CAC: swc1        $f7, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f_odd[(7 - 1) * 2];
    // 0x80007CB0: swc1        $f8, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->f8.u32l;
    // 0x80007CB4: swc1        $f9, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->f_odd[(9 - 1) * 2];
    // 0x80007CB8: swc1        $f10, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->f10.u32l;
    // 0x80007CBC: swc1        $f11, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f_odd[(11 - 1) * 2];
    // 0x80007CC0: swc1        $f12, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f12.u32l;
    // 0x80007CC4: swc1        $f13, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f_odd[(13 - 1) * 2];
    // 0x80007CC8: swc1        $f14, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->f14.u32l;
    // 0x80007CCC: swc1        $f15, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->f_odd[(15 - 1) * 2];
    // 0x80007CD0: swc1        $f16, 0x80($a0)
    MEM_W(0X80, ctx->r4) = ctx->f16.u32l;
    // 0x80007CD4: swc1        $f17, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->f_odd[(17 - 1) * 2];
    // 0x80007CD8: swc1        $f18, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->f18.u32l;
    // 0x80007CDC: swc1        $f19, 0x8C($a0)
    MEM_W(0X8C, ctx->r4) = ctx->f_odd[(19 - 1) * 2];
    // 0x80007CE0: swc1        $f20, 0x90($a0)
    MEM_W(0X90, ctx->r4) = ctx->f20.u32l;
    // 0x80007CE4: swc1        $f21, 0x94($a0)
    MEM_W(0X94, ctx->r4) = ctx->f_odd[(21 - 1) * 2];
    // 0x80007CE8: swc1        $f22, 0x98($a0)
    MEM_W(0X98, ctx->r4) = ctx->f22.u32l;
    // 0x80007CEC: swc1        $f23, 0x9C($a0)
    MEM_W(0X9C, ctx->r4) = ctx->f_odd[(23 - 1) * 2];
    // 0x80007CF0: swc1        $f24, 0xA0($a0)
    MEM_W(0XA0, ctx->r4) = ctx->f24.u32l;
    // 0x80007CF4: swc1        $f25, 0xA4($a0)
    MEM_W(0XA4, ctx->r4) = ctx->f_odd[(25 - 1) * 2];
    // 0x80007CF8: swc1        $f26, 0xA8($a0)
    MEM_W(0XA8, ctx->r4) = ctx->f26.u32l;
    // 0x80007CFC: swc1        $f27, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->f_odd[(27 - 1) * 2];
    // 0x80007D00: swc1        $f28, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->f28.u32l;
    // 0x80007D04: swc1        $f29, 0xB4($a0)
    MEM_W(0XB4, ctx->r4) = ctx->f_odd[(29 - 1) * 2];
    // 0x80007D08: swc1        $f30, 0xB8($a0)
    MEM_W(0XB8, ctx->r4) = ctx->f30.u32l;
    // 0x80007D0C: jr          $ra
    // 0x80007D10: swc1        $f31, 0xBC($a0)
    MEM_W(0XBC, ctx->r4) = ctx->f_odd[(31 - 1) * 2];
    TRACE_RETURN()
    return;
    // 0x80007D10: swc1        $f31, 0xBC($a0)
    MEM_W(0XBC, ctx->r4) = ctx->f_odd[(31 - 1) * 2];
    // 0x80007D14: nop

    // 0x80007D18: nop

    // 0x80007D1C: nop

    // 0x80007D20: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80007D24: sw          $at, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r1;
    // 0x80007D28: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    // 0x80007D2C: sw          $v1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r3;
    // 0x80007D30: sw          $a0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r4;
    // 0x80007D34: sw          $a1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r5;
    // 0x80007D38: sw          $a2, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r6;
    // 0x80007D3C: sw          $a3, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r7;
    // 0x80007D40: sw          $t0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r8;
    // 0x80007D44: sw          $t1, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r9;
    // 0x80007D48: sw          $t2, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r10;
    // 0x80007D4C: sw          $t3, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r11;
    // 0x80007D50: sw          $t4, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r12;
    // 0x80007D54: sw          $t5, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r13;
    // 0x80007D58: sw          $t6, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r14;
    // 0x80007D5C: sw          $t7, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r15;
    // 0x80007D60: sw          $s0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r16;
    // 0x80007D64: sw          $s1, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r17;
    // 0x80007D68: sw          $s2, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r18;
    // 0x80007D6C: sw          $s3, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->r19;
    // 0x80007D70: sw          $s4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->r20;
    // 0x80007D74: sw          $s5, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r21;
    // 0x80007D78: sw          $s6, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->r22;
    // 0x80007D7C: sw          $s7, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->r23;
    // 0x80007D80: sw          $t8, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->r24;
    // 0x80007D84: sw          $t9, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r25;
    // 0x80007D88: sw          $k0, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->r26;
    // 0x80007D8C: sw          $k1, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r27;
    // 0x80007D90: sw          $gp, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->r28;
    // 0x80007D94: sw          $sp, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->r29;
    // 0x80007D98: sw          $fp, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r30;
    // 0x80007D9C: sw          $ra, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r31;
    // 0x80007DA0: jr          $ra
    // 0x80007DA4: nop

    TRACE_RETURN()
    return;
    // 0x80007DA4: nop

    // 0x80007DA8: nop

    // 0x80007DAC: nop

    // 0x80007DB0: lbu         $t0, 0x0($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X0);
L_80007DB4:
    // 0x80007DB4: lb          $t1, 0x0($a1)
    ctx->r9 = MEM_B(ctx->r5, 0X0);
    // 0x80007DB8: beq         $t0, $zero, L_80007DE4
    if (ctx->r8 == 0) {
        // 0x80007DBC: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_80007DE4;
    }
    // 0x80007DBC: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80007DC0: bne         $t0, $t1, L_80007DEC
    if (ctx->r8 != ctx->r9) {
        // 0x80007DC4: lb          $t2, -0x1($a0)
        ctx->r10 = MEM_B(ctx->r4, -0X1);
            goto L_80007DEC;
    }
    // 0x80007DC4: lb          $t2, -0x1($a0)
    ctx->r10 = MEM_B(ctx->r4, -0X1);
    // 0x80007DC8: lb          $t1, 0x1($a1)
    ctx->r9 = MEM_B(ctx->r5, 0X1);
    // 0x80007DCC: beq         $t2, $zero, L_80007DE4
    if (ctx->r10 == 0) {
        // 0x80007DD0: addiu       $a1, $a1, 0x2
        ctx->r5 = ADD32(ctx->r5, 0X2);
            goto L_80007DE4;
    }
    // 0x80007DD0: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80007DD4: beq         $t2, $t1, L_80007DB4
    if (ctx->r10 == ctx->r9) {
        // 0x80007DD8: lbu         $t0, 0x0($a0)
        ctx->r8 = MEM_BU(ctx->r4, 0X0);
            goto L_80007DB4;
    }
    // 0x80007DD8: lbu         $t0, 0x0($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X0);
    // 0x80007DDC: jr          $ra
    // 0x80007DE0: subu        $v0, $t2, $t1
    ctx->r2 = SUB32(ctx->r10, ctx->r9);
    TRACE_RETURN()
    return;
    // 0x80007DE0: subu        $v0, $t2, $t1
    ctx->r2 = SUB32(ctx->r10, ctx->r9);
L_80007DE4:
    // 0x80007DE4: jr          $ra
    // 0x80007DE8: negu        $v0, $t1
    ctx->r2 = SUB32(0, ctx->r9);
    TRACE_RETURN()
    return;
    // 0x80007DE8: negu        $v0, $t1
    ctx->r2 = SUB32(0, ctx->r9);
L_80007DEC:
    // 0x80007DEC: jr          $ra
    // 0x80007DF0: subu        $v0, $t0, $t1
    ctx->r2 = SUB32(ctx->r8, ctx->r9);
    TRACE_RETURN()
    return;
    // 0x80007DF0: subu        $v0, $t0, $t1
    ctx->r2 = SUB32(ctx->r8, ctx->r9);
;}
RECOMP_FUNC void func_80007DF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80007DF4: add         $v0, $zero, $a0
    ctx->r2 = ADD32(0, ctx->r4);
    // 0x80007DF8: beq         $a2, $zero, L_80007E18
    if (ctx->r6 == 0) {
        // 0x80007DFC: add         $v1, $zero, $a1
        ctx->r3 = ADD32(0, ctx->r5);
            goto L_80007E18;
    }
    // 0x80007DFC: add         $v1, $zero, $a1
    ctx->r3 = ADD32(0, ctx->r5);
L_80007E00:
    // 0x80007E00: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x80007E04: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80007E08: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80007E0C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80007E10: bne         $a2, $zero, L_80007E00
    if (ctx->r6 != 0) {
        // 0x80007E14: sb          $t6, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = ctx->r14;
            goto L_80007E00;
    }
    // 0x80007E14: sb          $t6, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r14;
L_80007E18:
    // 0x80007E18: jr          $ra
    // 0x80007E1C: add         $v0, $zero, $a0
    ctx->r2 = ADD32(0, ctx->r4);
    TRACE_RETURN()
    return;
    // 0x80007E1C: add         $v0, $zero, $a0
    ctx->r2 = ADD32(0, ctx->r4);
;}
RECOMP_FUNC void func_80007E20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80007E20: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x80007E24: addiu       $v0, $v0, -0x7960
    ctx->r2 = ADD32(ctx->r2, -0X7960);
    // 0x80007E28: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80007E2C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80007E30: addiu       $t7, $zero, 0x67F0
    ctx->r15 = ADD32(0, 0X67F0);
    // 0x80007E34: bne         $t6, $at, L_80007E4C
    if (ctx->r14 != ctx->r1) {
        // 0x80007E38: lui         $t8, 0x800D
        ctx->r24 = S32(0X800D << 16);
            goto L_80007E4C;
    }
    // 0x80007E38: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80007E3C: addiu       $t8, $t8, 0x762C
    ctx->r24 = ADD32(ctx->r24, 0X762C);
    // 0x80007E40: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x80007E44: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80007E48: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_80007E4C:
    // 0x80007E4C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80007E54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80007E54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80007E58: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x80007E5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80007E60: addiu       $t6, $t6, -0x7960
    ctx->r14 = ADD32(ctx->r14, -0X7960);
    // 0x80007E64: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80007E68: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80007E6C: addiu       $t8, $zero, 0x67F0
    ctx->r24 = ADD32(0, 0X67F0);
    // 0x80007E70: bne         $t7, $at, L_80007EB8
    if (ctx->r15 != ctx->r1) {
        // 0x80007E74: lui         $t9, 0x800D
        ctx->r25 = S32(0X800D << 16);
            goto L_80007EB8;
    }
    // 0x80007E74: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80007E78: addiu       $t9, $t9, 0x762C
    ctx->r25 = ADD32(ctx->r25, 0X762C);
    // 0x80007E7C: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
    // 0x80007E80: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80007E84: jal         0x8004F980
    // 0x80007E88: lw          $a0, 0x7610($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7610);
    func_8004F980(rdram, ctx);
        goto after_0;
    // 0x80007E88: lw          $a0, 0x7610($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7610);
    after_0:
    // 0x80007E8C: lui         $t0, 0x8007
    ctx->r8 = S32(0X8007 << 16);
    // 0x80007E90: addiu       $t0, $t0, -0x7974
    ctx->r8 = ADD32(ctx->r8, -0X7974);
    // 0x80007E94: lui         $t2, 0x8007
    ctx->r10 = S32(0X8007 << 16);
    // 0x80007E98: sh          $v0, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r2;
    // 0x80007E9C: addiu       $t2, $t2, -0x7970
    ctx->r10 = ADD32(ctx->r10, -0X7970);
    // 0x80007EA0: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x80007EA4: lui         $t4, 0x8007
    ctx->r12 = S32(0X8007 << 16);
    // 0x80007EA8: sh          $t1, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r9;
    // 0x80007EAC: addiu       $t4, $t4, -0x7960
    ctx->r12 = ADD32(ctx->r12, -0X7960);
    // 0x80007EB0: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80007EB4: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
L_80007EB8:
    // 0x80007EB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80007EBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80007EC0: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80007EC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80007EC8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80007ECC: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x80007ED0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80007ED4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80007ED8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80007EDC: addiu       $t6, $t6, -0x797C
    ctx->r14 = ADD32(ctx->r14, -0X797C);
    // 0x80007EE0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80007EE4: lui         $a3, 0x8007
    ctx->r7 = S32(0X8007 << 16);
    // 0x80007EE8: addiu       $a3, $a3, -0x7960
    ctx->r7 = ADD32(ctx->r7, -0X7960);
    // 0x80007EEC: bnel        $t7, $zero, L_80008040
    if (ctx->r15 != 0) {
        // 0x80007EF0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80008040;
    }
    goto skip_0;
    // 0x80007EF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80007EF4: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x80007EF8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80007EFC: bnel        $t8, $at, L_80007F18
    if (ctx->r24 != ctx->r1) {
        // 0x80007F00: lw          $t9, 0x0($a3)
        ctx->r25 = MEM_W(ctx->r7, 0X0);
            goto L_80007F18;
    }
    goto skip_1;
    // 0x80007F00: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    skip_1:
    // 0x80007F04: jal         0x80007E20
    // 0x80007F08: nop

    func_80007E20(rdram, ctx);
        goto after_0;
    // 0x80007F08: nop

    after_0:
    // 0x80007F0C: lui         $a3, 0x8007
    ctx->r7 = S32(0X8007 << 16);
    // 0x80007F10: addiu       $a3, $a3, -0x7960
    ctx->r7 = ADD32(ctx->r7, -0X7960);
    // 0x80007F14: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
L_80007F18:
    // 0x80007F18: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80007F1C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80007F20: beq         $v0, $t9, L_80007F34
    if (ctx->r2 == ctx->r25) {
        // 0x80007F24: lui         $t2, 0x8007
        ctx->r10 = S32(0X8007 << 16);
            goto L_80007F34;
    }
    // 0x80007F24: lui         $t2, 0x8007
    ctx->r10 = S32(0X8007 << 16);
    // 0x80007F28: lw          $t0, 0x0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X0);
    // 0x80007F2C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80007F30: bne         $t0, $at, L_80007F74
    if (ctx->r8 != ctx->r1) {
        // 0x80007F34: addiu       $t2, $t2, -0x7958
        ctx->r10 = ADD32(ctx->r10, -0X7958);
            goto L_80007F74;
    }
L_80007F34:
    // 0x80007F34: addiu       $t2, $t2, -0x7958
    ctx->r10 = ADD32(ctx->r10, -0X7958);
    // 0x80007F38: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80007F3C: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x80007F40: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80007F44: addiu       $a0, $a0, -0x4A10
    ctx->r4 = ADD32(ctx->r4, -0X4A10);
    // 0x80007F48: beq         $v0, $t3, L_80007F60
    if (ctx->r2 == ctx->r11) {
        // 0x80007F4C: addiu       $a1, $sp, 0x2C
        ctx->r5 = ADD32(ctx->r29, 0X2C);
            goto L_80007F60;
    }
    // 0x80007F4C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80007F50: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x80007F54: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80007F58: bne         $t4, $at, L_80007F68
    if (ctx->r12 != ctx->r1) {
        // 0x80007F5C: nop
    
            goto L_80007F68;
    }
    // 0x80007F5C: nop

L_80007F60:
    // 0x80007F60: jal         0x8004F990
    // 0x80007F64: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80007F64: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
L_80007F68:
    // 0x80007F68: lui         $t5, 0x8007
    ctx->r13 = S32(0X8007 << 16);
    // 0x80007F6C: addiu       $t5, $t5, -0x7958
    ctx->r13 = ADD32(ctx->r13, -0X7958);
    // 0x80007F70: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
L_80007F74:
    // 0x80007F74: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80007F78: lw          $v1, 0x7638($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7638);
    // 0x80007F7C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80007F80: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x80007F84: lh          $t7, 0x2($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X2);
    // 0x80007F88: addiu       $a1, $a1, -0x7968
    ctx->r5 = ADD32(ctx->r5, -0X7968);
    // 0x80007F8C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80007F90: sltu        $at, $t6, $t7
    ctx->r1 = ctx->r14 < ctx->r15 ? 1 : 0;
    // 0x80007F94: bne         $at, $zero, L_80007FA4
    if (ctx->r1 != 0) {
        // 0x80007F98: nop
    
            goto L_80007FA4;
    }
    // 0x80007F98: nop

    // 0x80007F9C: b           L_80007FB0
    // 0x80007FA0: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
        goto L_80007FB0;
    // 0x80007FA0: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_80007FA4:
    // 0x80007FA4: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x80007FA8: addiu       $a1, $a1, -0x7968
    ctx->r5 = ADD32(ctx->r5, -0X7968);
    // 0x80007FAC: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
L_80007FB0:
    // 0x80007FB0: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80007FB4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80007FB8: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x80007FBC: addu        $v0, $v1, $t0
    ctx->r2 = ADD32(ctx->r3, ctx->r8);
    // 0x80007FC0: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    // 0x80007FC4: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x80007FC8: andi        $t1, $a2, 0x1
    ctx->r9 = ctx->r6 & 0X1;
    // 0x80007FCC: beq         $t1, $zero, L_80007FD8
    if (ctx->r9 == 0) {
        // 0x80007FD0: nop
    
            goto L_80007FD8;
    }
    // 0x80007FD0: nop

    // 0x80007FD4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80007FD8:
    // 0x80007FD8: jal         0x8000C5FC
    // 0x80007FDC: lw          $a1, 0x7630($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7630);
    dma_read_rom(rdram, ctx);
        goto after_2;
    // 0x80007FDC: lw          $a1, 0x7630($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7630);
    after_2:
    // 0x80007FE0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80007FE4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80007FE8: lw          $a1, 0x7630($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7630);
    // 0x80007FEC: jal         0x8005002C
    // 0x80007FF0: lw          $a0, 0x7614($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7614);
    func_8005002C(rdram, ctx);
        goto after_3;
    // 0x80007FF0: lw          $a0, 0x7614($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7614);
    after_3:
    // 0x80007FF4: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80007FF8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80007FFC: lw          $a1, 0x7614($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7614);
    // 0x80008000: jal         0x80050590
    // 0x80008004: lw          $a0, 0x7610($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7610);
    func_80050590(rdram, ctx);
        goto after_4;
    // 0x80008004: lw          $a0, 0x7610($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7610);
    after_4:
    // 0x80008008: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8000800C: addiu       $t2, $t2, 0x762C
    ctx->r10 = ADD32(ctx->r10, 0X762C);
    // 0x80008010: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80008014: lw          $a0, 0x7610($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7610);
    // 0x80008018: jal         0x800505D0
    // 0x8000801C: lh          $a1, 0x0($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X0);
    func_800505D0(rdram, ctx);
        goto after_5;
    // 0x8000801C: lh          $a1, 0x0($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X0);
    after_5:
    // 0x80008020: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80008024: jal         0x80050610
    // 0x80008028: lw          $a0, 0x7610($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7610);
    func_80050610(rdram, ctx);
        goto after_6;
    // 0x80008028: lw          $a0, 0x7610($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7610);
    after_6:
    // 0x8000802C: lui         $t4, 0x8007
    ctx->r12 = S32(0X8007 << 16);
    // 0x80008030: addiu       $t4, $t4, -0x7960
    ctx->r12 = ADD32(ctx->r12, -0X7960);
    // 0x80008034: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80008038: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8000803C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80008040:
    // 0x80008040: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80008044: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000804C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000804C: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x80008050: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80008054: addiu       $t7, $t7, -0x797C
    ctx->r15 = ADD32(ctx->r15, -0X797C);
    // 0x80008058: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8000805C: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80008060: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80008064: bne         $t8, $zero, L_80008150
    if (ctx->r24 != 0) {
        // 0x80008068: addiu       $v1, $zero, -0x1
        ctx->r3 = ADD32(0, -0X1);
            goto L_80008150;
    }
    // 0x80008068: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8000806C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80008070: lw          $t5, -0x3E6C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X3E6C);
    // 0x80008074: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80008078: addiu       $t9, $t9, -0x33D0
    ctx->r25 = ADD32(ctx->r25, -0X33D0);
    // 0x8000807C: addu        $v1, $a0, $t9
    ctx->r3 = ADD32(ctx->r4, ctx->r25);
    // 0x80008080: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x80008084: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x80008088: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8000808C: addiu       $t4, $a1, 0x1
    ctx->r12 = ADD32(ctx->r5, 0X1);
    // 0x80008090: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80008094: div         $zero, $t4, $t7
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r15)));
    // 0x80008098: lw          $t0, -0x3E68($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X3E68);
    // 0x8000809C: mfhi        $t8
    ctx->r24 = hi;
    // 0x800080A0: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x800080A4: addu        $t1, $t0, $a0
    ctx->r9 = ADD32(ctx->r8, ctx->r4);
    // 0x800080A8: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x800080AC: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
    // 0x800080B0: lw          $t9, 0x7624($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7624);
    // 0x800080B4: addu        $v0, $a1, $t2
    ctx->r2 = ADD32(ctx->r5, ctx->r10);
    // 0x800080B8: andi        $t3, $v0, 0xFF
    ctx->r11 = ctx->r2 & 0XFF;
    // 0x800080BC: lh          $t0, 0xE($t9)
    ctx->r8 = MEM_H(ctx->r25, 0XE);
    // 0x800080C0: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x800080C4: bne         $t7, $zero, L_800080D0
    if (ctx->r15 != 0) {
        // 0x800080C8: nop
    
            goto L_800080D0;
    }
    // 0x800080C8: nop

    // 0x800080CC: break       7
    do_break(2147516620);
L_800080D0:
    // 0x800080D0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800080D4: bne         $t7, $at, L_800080E8
    if (ctx->r15 != ctx->r1) {
        // 0x800080D8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800080E8;
    }
    // 0x800080D8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800080DC: bne         $t4, $at, L_800080E8
    if (ctx->r12 != ctx->r1) {
        // 0x800080E0: nop
    
            goto L_800080E8;
    }
    // 0x800080E0: nop

    // 0x800080E4: break       6
    do_break(2147516644);
L_800080E8:
    // 0x800080E8: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800080EC: bne         $at, $zero, L_800080FC
    if (ctx->r1 != 0) {
        // 0x800080F0: sll         $t1, $v0, 4
        ctx->r9 = S32(ctx->r2 << 4);
            goto L_800080FC;
    }
    // 0x800080F0: sll         $t1, $v0, 4
    ctx->r9 = S32(ctx->r2 << 4);
    // 0x800080F4: jr          $ra
    // 0x800080F8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    TRACE_RETURN()
    return;
    // 0x800080F8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800080FC:
    // 0x800080FC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80008100: lw          $t3, -0x3E70($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X3E70);
    // 0x80008104: sll         $a2, $a0, 2
    ctx->r6 = S32(ctx->r4 << 2);
    // 0x80008108: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8000810C: addu        $t5, $t3, $a2
    ctx->r13 = ADD32(ctx->r11, ctx->r6);
    // 0x80008110: lwc1        $f4, 0x0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80008114: addiu       $t2, $t2, -0x3E60
    ctx->r10 = ADD32(ctx->r10, -0X3E60);
    // 0x80008118: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    // 0x8000811C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80008120: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x80008124: lw          $t6, -0x3E64($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3E64);
    // 0x80008128: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8000812C: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80008130: addu        $t4, $t6, $a2
    ctx->r12 = ADD32(ctx->r14, ctx->r6);
    // 0x80008134: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x80008138: sll         $t0, $v0, 1
    ctx->r8 = S32(ctx->r2 << 1);
    // 0x8000813C: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80008140: sb          $t8, 0xC($a1)
    MEM_B(0XC, ctx->r5) = ctx->r24;
    // 0x80008144: lw          $t9, 0x7628($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7628);
    // 0x80008148: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8000814C: lh          $v1, 0x0($t1)
    ctx->r3 = MEM_H(ctx->r9, 0X0);
L_80008150:
    // 0x80008150: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80008154: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000815C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000815C: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x80008160: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80008164: addiu       $t7, $t7, -0x797C
    ctx->r15 = ADD32(ctx->r15, -0X797C);
    // 0x80008168: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8000816C: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80008170: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80008174: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80008178: bne         $t8, $zero, L_80008314
    if (ctx->r24 != 0) {
        // 0x8000817C: addiu       $a2, $zero, -0x1
        ctx->r6 = ADD32(0, -0X1);
            goto L_80008314;
    }
    // 0x8000817C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80008180: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80008184: lw          $t6, -0x3E6C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3E6C);
    // 0x80008188: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8000818C: addiu       $t9, $t9, -0x33D0
    ctx->r25 = ADD32(ctx->r25, -0X33D0);
    // 0x80008190: addu        $a2, $a0, $t9
    ctx->r6 = ADD32(ctx->r4, ctx->r25);
    // 0x80008194: lbu         $a3, 0x0($a2)
    ctx->r7 = MEM_BU(ctx->r6, 0X0);
    // 0x80008198: addu        $t1, $a0, $t6
    ctx->r9 = ADD32(ctx->r4, ctx->r14);
    // 0x8000819C: lbu         $t8, 0x0($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X0);
    // 0x800081A0: addiu       $t7, $a3, 0x1
    ctx->r15 = ADD32(ctx->r7, 0X1);
    // 0x800081A4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800081A8: div         $zero, $t7, $t8
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r24))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r24)));
    // 0x800081AC: lw          $t3, -0x3E68($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X3E68);
    // 0x800081B0: mfhi        $t9
    ctx->r25 = hi;
    // 0x800081B4: addu        $t0, $t3, $a0
    ctx->r8 = ADD32(ctx->r11, ctx->r4);
    // 0x800081B8: lbu         $t4, 0x0($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X0);
    // 0x800081BC: sb          $t9, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r25;
    // 0x800081C0: lbu         $t6, 0x0($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X0);
    // 0x800081C4: addu        $v0, $a3, $t4
    ctx->r2 = ADD32(ctx->r7, ctx->r12);
    // 0x800081C8: andi        $t5, $v0, 0xFF
    ctx->r13 = ctx->r2 & 0XFF;
    // 0x800081CC: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x800081D0: andi        $a3, $t9, 0xFF
    ctx->r7 = ctx->r25 & 0XFF;
    // 0x800081D4: addiu       $t5, $a3, 0x1
    ctx->r13 = ADD32(ctx->r7, 0X1);
    // 0x800081D8: div         $zero, $t5, $t6
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r14)));
    // 0x800081DC: bne         $t8, $zero, L_800081E8
    if (ctx->r24 != 0) {
        // 0x800081E0: nop
    
            goto L_800081E8;
    }
    // 0x800081E0: nop

    // 0x800081E4: break       7
    do_break(2147516900);
L_800081E8:
    // 0x800081E8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800081EC: bne         $t8, $at, L_80008200
    if (ctx->r24 != ctx->r1) {
        // 0x800081F0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80008200;
    }
    // 0x800081F0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800081F4: bne         $t7, $at, L_80008200
    if (ctx->r15 != ctx->r1) {
        // 0x800081F8: nop
    
            goto L_80008200;
    }
    // 0x800081F8: nop

    // 0x800081FC: break       6
    do_break(2147516924);
L_80008200:
    // 0x80008200: lbu         $t3, 0x0($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X0);
    // 0x80008204: mfhi        $t7
    ctx->r15 = hi;
    // 0x80008208: sb          $t7, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r15;
    // 0x8000820C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80008210: lw          $t8, 0x7624($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7624);
    // 0x80008214: addu        $v1, $a3, $t3
    ctx->r3 = ADD32(ctx->r7, ctx->r11);
    // 0x80008218: andi        $t4, $v1, 0xFF
    ctx->r12 = ctx->r3 & 0XFF;
    // 0x8000821C: lh          $t2, 0xE($t8)
    ctx->r10 = MEM_H(ctx->r24, 0XE);
    // 0x80008220: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
    // 0x80008224: bne         $t6, $zero, L_80008230
    if (ctx->r14 != 0) {
        // 0x80008228: nop
    
            goto L_80008230;
    }
    // 0x80008228: nop

    // 0x8000822C: break       7
    do_break(2147516972);
L_80008230:
    // 0x80008230: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80008234: bne         $t6, $at, L_80008248
    if (ctx->r14 != ctx->r1) {
        // 0x80008238: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80008248;
    }
    // 0x80008238: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000823C: bne         $t5, $at, L_80008248
    if (ctx->r13 != ctx->r1) {
        // 0x80008240: nop
    
            goto L_80008248;
    }
    // 0x80008240: nop

    // 0x80008244: break       6
    do_break(2147516996);
L_80008248:
    // 0x80008248: slt         $at, $v0, $t2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8000824C: beq         $at, $zero, L_8000825C
    if (ctx->r1 == 0) {
        // 0x80008250: slt         $at, $v1, $t2
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_8000825C;
    }
    // 0x80008250: slt         $at, $v1, $t2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80008254: bne         $at, $zero, L_80008264
    if (ctx->r1 != 0) {
        // 0x80008258: lui         $t2, 0x800E
        ctx->r10 = S32(0X800E << 16);
            goto L_80008264;
    }
    // 0x80008258: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
L_8000825C:
    // 0x8000825C: jr          $ra
    // 0x80008260: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    TRACE_RETURN()
    return;
    // 0x80008260: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80008264:
    // 0x80008264: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80008268: lw          $t3, -0x3E70($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X3E70);
    // 0x8000826C: sll         $a2, $a0, 2
    ctx->r6 = S32(ctx->r4 << 2);
    // 0x80008270: addiu       $t2, $t2, -0x3E60
    ctx->r10 = ADD32(ctx->r10, -0X3E60);
    // 0x80008274: addu        $t0, $t3, $a2
    ctx->r8 = ADD32(ctx->r11, ctx->r6);
    // 0x80008278: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8000827C: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
    // 0x80008280: addu        $a3, $t2, $t9
    ctx->r7 = ADD32(ctx->r10, ctx->r25);
    // 0x80008284: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80008288: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
    // 0x8000828C: lw          $t4, -0x3E64($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X3E64);
    // 0x80008290: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x80008294: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80008298: addu        $t1, $t4, $a2
    ctx->r9 = ADD32(ctx->r12, ctx->r6);
    // 0x8000829C: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800082A0: sll         $t7, $v1, 4
    ctx->r15 = S32(ctx->r3 << 4);
    // 0x800082A4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800082A8: sw          $t5, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r13;
    // 0x800082AC: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800082B0: addu        $a0, $t2, $t7
    ctx->r4 = ADD32(ctx->r10, ctx->r15);
    // 0x800082B4: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800082B8: nop

    // 0x800082BC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800082C0: mul.s       $f0, $f8, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800082C4: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x800082C8: nop

    // 0x800082CC: bc1fl       L_800082DC
    if (!c1cs) {
        // 0x800082D0: trunc.w.s   $f18, $f0
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
            goto L_800082DC;
    }
    goto skip_0;
    // 0x800082D0: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    skip_0:
    // 0x800082D4: lwc1        $f0, 0x5E70($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5E70);
    // 0x800082D8: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
L_800082DC:
    // 0x800082DC: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800082E0: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800082E4: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x800082E8: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x800082EC: swc1        $f16, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f16.u32l;
    // 0x800082F0: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x800082F4: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x800082F8: sw          $a1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r5;
    // 0x800082FC: sb          $t3, 0xC($a3)
    MEM_B(0XC, ctx->r7) = ctx->r11;
    // 0x80008300: sb          $t4, 0xC($a0)
    MEM_B(0XC, ctx->r4) = ctx->r12;
    // 0x80008304: lw          $t5, 0x7628($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7628);
    // 0x80008308: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x8000830C: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80008310: lh          $a2, 0x0($t7)
    ctx->r6 = MEM_H(ctx->r15, 0X0);
L_80008314:
    // 0x80008314: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80008318: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80008320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80008320: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80008324: lw          $t6, 0x7624($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7624);
    // 0x80008328: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000832C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80008330: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80008334: lh          $t7, 0xE($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XE);
    // 0x80008338: andi        $a2, $a0, 0xFFFF
    ctx->r6 = ctx->r4 & 0XFFFF;
    // 0x8000833C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80008340: slt         $at, $a2, $t7
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80008344: beq         $at, $zero, L_8000838C
    if (ctx->r1 == 0) {
        // 0x80008348: lui         $t8, 0x800D
        ctx->r24 = S32(0X800D << 16);
            goto L_8000838C;
    }
    // 0x80008348: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8000834C: lw          $t8, 0x7628($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7628);
    // 0x80008350: sll         $t9, $a2, 1
    ctx->r25 = S32(ctx->r6 << 1);
    // 0x80008354: lw          $a0, 0x7618($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7618);
    // 0x80008358: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8000835C: lh          $a1, 0x0($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X0);
    // 0x80008360: jal         0x80050640
    // 0x80008364: sh          $a2, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r6;
    func_80050640(rdram, ctx);
        goto after_0;
    // 0x80008364: sh          $a2, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r6;
    after_0:
    // 0x80008368: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8000836C: jal         0x80050660
    // 0x80008370: lw          $a0, 0x7618($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7618);
    func_80050660(rdram, ctx);
        goto after_1;
    // 0x80008370: lw          $a0, 0x7618($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7618);
    after_1:
    // 0x80008374: lhu         $t2, 0x1A($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X1A);
    // 0x80008378: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000837C: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x80008380: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x80008384: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80008388: sb          $t1, -0x3E54($at)
    MEM_B(-0X3E54, ctx->r1) = ctx->r9;
L_8000838C:
    // 0x8000838C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80008390: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80008394: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000839C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000839C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800083A0: lw          $v1, 0x7624($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7624);
    // 0x800083A4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800083A8: addiu       $a0, $a0, -0x3E60
    ctx->r4 = ADD32(ctx->r4, -0X3E60);
    // 0x800083AC: lh          $t6, 0xE($v1)
    ctx->r14 = MEM_H(ctx->r3, 0XE);
    // 0x800083B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800083B4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800083B8: blez        $t6, L_800083E4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800083BC: sll         $t7, $v0, 4
        ctx->r15 = S32(ctx->r2 << 4);
            goto L_800083E4;
    }
    // 0x800083BC: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
L_800083C0:
    // 0x800083C0: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x800083C4: sb          $a1, 0xC($t8)
    MEM_B(0XC, ctx->r24) = ctx->r5;
    // 0x800083C8: lh          $t1, 0xE($v1)
    ctx->r9 = MEM_H(ctx->r3, 0XE);
    // 0x800083CC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800083D0: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x800083D4: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800083D8: slt         $at, $v0, $t1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800083DC: bnel        $at, $zero, L_800083C0
    if (ctx->r1 != 0) {
        // 0x800083E0: sll         $t7, $v0, 4
        ctx->r15 = S32(ctx->r2 << 4);
            goto L_800083C0;
    }
    goto skip_0;
    // 0x800083E0: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    skip_0:
L_800083E4:
    // 0x800083E4: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800083EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800083EC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800083F0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800083F4: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x800083F8: lhu         $v0, -0x796C($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X796C);
    // 0x800083FC: lhu         $a1, 0x3A($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X3A);
    // 0x80008400: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80008404: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80008408: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8000840C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80008410: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80008414: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80008418: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000841C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80008420: beq         $v0, $a1, L_8000863C
    if (ctx->r2 == ctx->r5) {
        // 0x80008424: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_8000863C;
    }
    // 0x80008424: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80008428: slti        $at, $a1, 0x5
    ctx->r1 = SIGNED(ctx->r5) < 0X5 ? 1 : 0;
    // 0x8000842C: beq         $at, $zero, L_8000863C
    if (ctx->r1 == 0) {
        // 0x80008430: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8000863C;
    }
    // 0x80008430: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80008434: beq         $v0, $at, L_8000851C
    if (ctx->r2 == ctx->r1) {
        // 0x80008438: lui         $t6, 0x800D
        ctx->r14 = S32(0X800D << 16);
            goto L_8000851C;
    }
    // 0x80008438: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8000843C: lw          $t6, 0x7620($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7620);
    // 0x80008440: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80008444: lui         $s7, 0x800D
    ctx->r23 = S32(0X800D << 16);
    // 0x80008448: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8000844C: lw          $v1, 0xC($t8)
    ctx->r3 = MEM_W(ctx->r24, 0XC);
    // 0x80008450: addiu       $s7, $s7, 0x7624
    ctx->r23 = ADD32(ctx->r23, 0X7624);
    // 0x80008454: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80008458: sw          $v1, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r3;
    // 0x8000845C: lh          $a0, 0xE($v1)
    ctx->r4 = MEM_H(ctx->r3, 0XE);
    // 0x80008460: beq         $a0, $zero, L_8000848C
    if (ctx->r4 == 0) {
        // 0x80008464: nop
    
            goto L_8000848C;
    }
    // 0x80008464: nop

L_80008468:
    // 0x80008468: jal         0x80008320
    // 0x8000846C: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    func_80008320(rdram, ctx);
        goto after_0;
    // 0x8000846C: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    after_0:
    // 0x80008470: lw          $v1, 0x0($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X0);
    // 0x80008474: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80008478: lh          $a0, 0xE($v1)
    ctx->r4 = MEM_H(ctx->r3, 0XE);
    // 0x8000847C: sltu        $at, $s1, $a0
    ctx->r1 = ctx->r17 < ctx->r4 ? 1 : 0;
    // 0x80008480: bne         $at, $zero, L_80008468
    if (ctx->r1 != 0) {
        // 0x80008484: nop
    
            goto L_80008468;
    }
    // 0x80008484: nop

    // 0x80008488: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8000848C:
    // 0x8000848C: beq         $a0, $zero, L_800084C8
    if (ctx->r4 == 0) {
        // 0x80008490: lui         $t2, 0x8007
        ctx->r10 = S32(0X8007 << 16);
            goto L_800084C8;
    }
    // 0x80008490: lui         $t2, 0x8007
    ctx->r10 = S32(0X8007 << 16);
    // 0x80008494: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80008498: addiu       $v0, $v0, -0x3E60
    ctx->r2 = ADD32(ctx->r2, -0X3E60);
L_8000849C:
    // 0x8000849C: lbu         $t0, 0xC($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0XC);
    // 0x800084A0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800084A4: sltu        $at, $s1, $a0
    ctx->r1 = ctx->r17 < ctx->r4 ? 1 : 0;
    // 0x800084A8: beq         $t0, $zero, L_800084BC
    if (ctx->r8 == 0) {
        // 0x800084AC: nop
    
            goto L_800084BC;
    }
    // 0x800084AC: nop

    // 0x800084B0: lbu         $t1, 0xC($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0XC);
L_800084B4:
    MEM_B(0XC, ctx->r2) = 0;
    ctx->r9 = 0;
    // 0x800084B4: bnel        $t1, $zero, L_800084B4
    if (ctx->r9 != 0) {
        // 0x800084B8: lbu         $t1, 0xC($v0)
        ctx->r9 = MEM_BU(ctx->r2, 0XC);
            goto L_800084B4;
    }
    goto skip_0;
    // 0x800084B8: lbu         $t1, 0xC($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0XC);
    skip_0:
L_800084BC:
    // 0x800084BC: bne         $at, $zero, L_8000849C
    if (ctx->r1 != 0) {
        // 0x800084C0: addiu       $v0, $v0, 0x10
        ctx->r2 = ADD32(ctx->r2, 0X10);
            goto L_8000849C;
    }
    // 0x800084C0: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800084C4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800084C8:
    // 0x800084C8: addiu       $t2, $t2, -0x795C
    ctx->r10 = ADD32(ctx->r10, -0X795C);
    // 0x800084CC: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    // 0x800084D0: lh          $t3, 0xE($v1)
    ctx->r11 = MEM_H(ctx->r3, 0XE);
    // 0x800084D4: lui         $s6, 0x800D
    ctx->r22 = S32(0X800D << 16);
    // 0x800084D8: addiu       $s6, $s6, 0x7628
    ctx->r22 = ADD32(ctx->r22, 0X7628);
    // 0x800084DC: beq         $t3, $zero, L_8000851C
    if (ctx->r11 == 0) {
        // 0x800084E0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8000851C;
    }
    // 0x800084E0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800084E4: lui         $s5, 0x800D
    ctx->r21 = S32(0X800D << 16);
    // 0x800084E8: addiu       $s5, $s5, 0x7618
    ctx->r21 = ADD32(ctx->r21, 0X7618);
    // 0x800084EC: lw          $t4, 0x0($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X0);
L_800084F0:
    // 0x800084F0: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x800084F4: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x800084F8: jal         0x800506B0
    // 0x800084FC: lh          $a1, 0x0($t5)
    ctx->r5 = MEM_H(ctx->r13, 0X0);
    func_800506B0(rdram, ctx);
        goto after_1;
    // 0x800084FC: lh          $a1, 0x0($t5)
    ctx->r5 = MEM_H(ctx->r13, 0X0);
    after_1:
    // 0x80008500: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x80008504: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80008508: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8000850C: lh          $t7, 0xE($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XE);
    // 0x80008510: sltu        $at, $s1, $t7
    ctx->r1 = ctx->r17 < ctx->r15 ? 1 : 0;
    // 0x80008514: bnel        $at, $zero, L_800084F0
    if (ctx->r1 != 0) {
        // 0x80008518: lw          $t4, 0x0($s6)
        ctx->r12 = MEM_W(ctx->r22, 0X0);
            goto L_800084F0;
    }
    goto skip_1;
    // 0x80008518: lw          $t4, 0x0($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X0);
    skip_1:
L_8000851C:
    // 0x8000851C: lhu         $v1, 0x3A($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X3A);
    // 0x80008520: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80008524: lw          $t9, 0x7620($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7620);
    // 0x80008528: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x8000852C: lui         $s7, 0x800D
    ctx->r23 = S32(0X800D << 16);
    // 0x80008530: addu        $t0, $t9, $t8
    ctx->r8 = ADD32(ctx->r25, ctx->r24);
    // 0x80008534: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x80008538: addiu       $s7, $s7, 0x7624
    ctx->r23 = ADD32(ctx->r23, 0X7624);
    // 0x8000853C: lui         $t2, 0x8007
    ctx->r10 = S32(0X8007 << 16);
    // 0x80008540: addu        $t2, $t2, $t8
    ctx->r10 = ADD32(ctx->r10, ctx->r24);
    // 0x80008544: sw          $t1, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r9;
    // 0x80008548: lw          $t2, -0x7490($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7490);
    // 0x8000854C: lui         $t3, 0x8007
    ctx->r11 = S32(0X8007 << 16);
    // 0x80008550: addu        $t3, $t3, $t8
    ctx->r11 = ADD32(ctx->r11, ctx->r24);
    // 0x80008554: lw          $t3, -0x7884($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7884);
    // 0x80008558: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000855C: lui         $t4, 0x8007
    ctx->r12 = S32(0X8007 << 16);
    // 0x80008560: addu        $t4, $t4, $t8
    ctx->r12 = ADD32(ctx->r12, ctx->r24);
    // 0x80008564: sw          $t2, -0x3E70($at)
    MEM_W(-0X3E70, ctx->r1) = ctx->r10;
    // 0x80008568: lw          $t4, -0x77AC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X77AC);
    // 0x8000856C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80008570: lui         $t5, 0x8007
    ctx->r13 = S32(0X8007 << 16);
    // 0x80008574: addu        $t5, $t5, $t8
    ctx->r13 = ADD32(ctx->r13, ctx->r24);
    // 0x80008578: sw          $t3, -0x3E6C($at)
    MEM_W(-0X3E6C, ctx->r1) = ctx->r11;
    // 0x8000857C: lw          $t5, -0x6CC8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X6CC8);
    // 0x80008580: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80008584: sw          $t4, -0x3E68($at)
    MEM_W(-0X3E68, ctx->r1) = ctx->r12;
    // 0x80008588: lui         $s5, 0x800D
    ctx->r21 = S32(0X800D << 16);
    // 0x8000858C: lui         $s6, 0x800D
    ctx->r22 = S32(0X800D << 16);
    // 0x80008590: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80008594: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80008598: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000859C: addiu       $s6, $s6, 0x7628
    ctx->r22 = ADD32(ctx->r22, 0X7628);
    // 0x800085A0: addiu       $s5, $s5, 0x7618
    ctx->r21 = ADD32(ctx->r21, 0X7618);
    // 0x800085A4: addiu       $v0, $v0, -0x33D0
    ctx->r2 = ADD32(ctx->r2, -0X33D0);
    // 0x800085A8: addiu       $v1, $v1, -0x3365
    ctx->r3 = ADD32(ctx->r3, -0X3365);
    // 0x800085AC: sw          $t5, -0x3E64($at)
    MEM_W(-0X3E64, ctx->r1) = ctx->r13;
L_800085B0:
    // 0x800085B0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800085B4: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800085B8: bne         $at, $zero, L_800085B0
    if (ctx->r1 != 0) {
        // 0x800085BC: sb          $zero, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = 0;
            goto L_800085B0;
    }
    // 0x800085BC: sb          $zero, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = 0;
    // 0x800085C0: lw          $v1, 0x0($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X0);
    // 0x800085C4: lui         $s3, 0x800D
    ctx->r19 = S32(0X800D << 16);
    // 0x800085C8: addiu       $s3, $s3, 0x761C
    ctx->r19 = ADD32(ctx->r19, 0X761C);
    // 0x800085CC: lh          $t6, 0xE($v1)
    ctx->r14 = MEM_H(ctx->r3, 0XE);
    // 0x800085D0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800085D4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800085D8: beq         $t6, $zero, L_80008620
    if (ctx->r14 == 0) {
        // 0x800085DC: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80008620;
    }
    // 0x800085DC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800085E0: addu        $t7, $v1, $s2
    ctx->r15 = ADD32(ctx->r3, ctx->r18);
L_800085E4:
    // 0x800085E4: lw          $a1, 0x10($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X10);
    // 0x800085E8: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x800085EC: jal         0x80050700
    // 0x800085F0: sw          $a1, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r5;
    func_80050700(rdram, ctx);
        goto after_2;
    // 0x800085F0: sw          $a1, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r5;
    after_2:
    // 0x800085F4: lw          $t9, 0x0($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X0);
    // 0x800085F8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800085FC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80008600: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x80008604: sh          $v0, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r2;
    // 0x80008608: lw          $v1, 0x0($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X0);
    // 0x8000860C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80008610: lh          $t1, 0xE($v1)
    ctx->r9 = MEM_H(ctx->r3, 0XE);
    // 0x80008614: sltu        $at, $s1, $t1
    ctx->r1 = ctx->r17 < ctx->r9 ? 1 : 0;
    // 0x80008618: bnel        $at, $zero, L_800085E4
    if (ctx->r1 != 0) {
        // 0x8000861C: addu        $t7, $v1, $s2
        ctx->r15 = ADD32(ctx->r3, ctx->r18);
            goto L_800085E4;
    }
    goto skip_2;
    // 0x8000861C: addu        $t7, $v1, $s2
    ctx->r15 = ADD32(ctx->r3, ctx->r18);
    skip_2:
L_80008620:
    // 0x80008620: lhu         $t2, 0x3A($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X3A);
    // 0x80008624: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80008628: lui         $t4, 0x8007
    ctx->r12 = S32(0X8007 << 16);
    // 0x8000862C: addiu       $t4, $t4, -0x795C
    ctx->r12 = ADD32(ctx->r12, -0X795C);
    // 0x80008630: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80008634: sh          $t2, -0x796C($at)
    MEM_H(-0X796C, ctx->r1) = ctx->r10;
    // 0x80008638: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
L_8000863C:
    // 0x8000863C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80008640: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80008644: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80008648: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000864C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80008650: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80008654: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80008658: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8000865C: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80008660: jr          $ra
    // 0x80008664: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    TRACE_RETURN()
    return;
    // 0x80008664: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80008668(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80008668: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8000866C: lw          $t6, 0x7624($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7624);
    // 0x80008670: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80008674: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80008678: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000867C: lh          $t7, 0xE($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XE);
    // 0x80008680: andi        $a2, $a0, 0xFFFF
    ctx->r6 = ctx->r4 & 0XFFFF;
    // 0x80008684: ori         $t0, $zero, 0xFFFF
    ctx->r8 = 0 | 0XFFFF;
    // 0x80008688: slt         $at, $a2, $t7
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8000868C: beq         $at, $zero, L_800086CC
    if (ctx->r1 == 0) {
        // 0x80008690: lui         $t1, 0x8007
        ctx->r9 = S32(0X8007 << 16);
            goto L_800086CC;
    }
    // 0x80008690: lui         $t1, 0x8007
    ctx->r9 = S32(0X8007 << 16);
    // 0x80008694: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80008698: beq         $a2, $at, L_800086CC
    if (ctx->r6 == ctx->r1) {
        // 0x8000869C: lui         $a0, 0x800D
        ctx->r4 = S32(0X800D << 16);
            goto L_800086CC;
    }
    // 0x8000869C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800086A0: sll         $a1, $a2, 16
    ctx->r5 = S32(ctx->r6 << 16);
    // 0x800086A4: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800086A8: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x800086AC: lw          $a0, 0x7618($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7618);
    // 0x800086B0: jal         0x80050640
    // 0x800086B4: sh          $a2, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r6;
    func_80050640(rdram, ctx);
        goto after_0;
    // 0x800086B4: sh          $a2, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r6;
    after_0:
    // 0x800086B8: lhu         $a2, 0x1A($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X1A);
    // 0x800086BC: lui         $t9, 0x8007
    ctx->r25 = S32(0X8007 << 16);
    // 0x800086C0: addiu       $t9, $t9, -0x7978
    ctx->r25 = ADD32(ctx->r25, -0X7978);
    // 0x800086C4: b           L_800086D4
    // 0x800086C8: sh          $a2, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r6;
        goto L_800086D4;
    // 0x800086C8: sh          $a2, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r6;
L_800086CC:
    // 0x800086CC: addiu       $t1, $t1, -0x7978
    ctx->r9 = ADD32(ctx->r9, -0X7978);
    // 0x800086D0: sh          $t0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r8;
L_800086D4:
    // 0x800086D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800086D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800086DC: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800086E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800086E4: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x800086E8: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800086EC: addiu       $a1, $a1, -0x49F0
    ctx->r5 = ADD32(ctx->r5, -0X49F0);
    // 0x800086F0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800086F4: lui         $a0, 0x5
    ctx->r4 = S32(0X5 << 16);
    // 0x800086F8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800086FC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80008700: sb          $zero, -0x4728($at)
    MEM_B(-0X4728, ctx->r1) = 0;
    // 0x80008704: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80008708: ori         $a0, $a0, 0xC000
    ctx->r4 = ctx->r4 | 0XC000;
    // 0x8000870C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80008710:
    // 0x80008710: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80008714: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x80008718: sb          $zero, 0x2($v0)
    MEM_B(0X2, ctx->r2) = 0;
    // 0x8000871C: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // 0x80008720: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80008724: bne         $v1, $a0, L_80008710
    if (ctx->r3 != ctx->r4) {
        // 0x80008728: sb          $zero, -0x4($v0)
        MEM_B(-0X4, ctx->r2) = 0;
            goto L_80008710;
    }
    // 0x80008728: sb          $zero, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = 0;
    // 0x8000872C: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80008730: addiu       $s0, $s0, 0x7640
    ctx->r16 = ADD32(ctx->r16, 0X7640);
    // 0x80008734: lui         $a2, 0x5
    ctx->r6 = S32(0X5 << 16);
    // 0x80008738: ori         $a2, $a2, 0xC000
    ctx->r6 = ctx->r6 | 0XC000;
    // 0x8000873C: jal         0x800507A0
    // 0x80008740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800507A0(rdram, ctx);
        goto after_0;
    // 0x80008740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80008744: addiu       $t6, $zero, 0xF8
    ctx->r14 = ADD32(0, 0XF8);
    // 0x80008748: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8000874C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80008750: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80008754: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80008758: jal         0x800507E0
    // 0x8000875C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800507E0(rdram, ctx);
        goto after_1;
    // 0x8000875C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x80008760: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80008764: addiu       $t7, $zero, 0x7C
    ctx->r15 = ADD32(0, 0X7C);
    // 0x80008768: sw          $v0, 0x7614($at)
    MEM_W(0X7614, ctx->r1) = ctx->r2;
    // 0x8000876C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80008770: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80008774: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80008778: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8000877C: jal         0x800507E0
    // 0x80008780: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800507E0(rdram, ctx);
        goto after_2;
    // 0x80008780: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80008784: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80008788: addiu       $t8, $zero, 0x54
    ctx->r24 = ADD32(0, 0X54);
    // 0x8000878C: sw          $v0, 0x7610($at)
    MEM_W(0X7610, ctx->r1) = ctx->r2;
    // 0x80008790: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80008794: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80008798: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000879C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800087A0: jal         0x800507E0
    // 0x800087A4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800507E0(rdram, ctx);
        goto after_3;
    // 0x800087A4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x800087A8: lui         $t9, 0x51
    ctx->r25 = S32(0X51 << 16);
    // 0x800087AC: lui         $t0, 0x51
    ctx->r8 = S32(0X51 << 16);
    // 0x800087B0: addiu       $t0, $t0, -0x73F0
    ctx->r8 = ADD32(ctx->r8, -0X73F0);
    // 0x800087B4: addiu       $t9, $t9, 0x2B20
    ctx->r25 = ADD32(ctx->r25, 0X2B20);
    // 0x800087B8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800087BC: subu        $v1, $t9, $t0
    ctx->r3 = SUB32(ctx->r25, ctx->r8);
    // 0x800087C0: sw          $v0, 0x7618($at)
    MEM_W(0X7618, ctx->r1) = ctx->r2;
    // 0x800087C4: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x800087C8: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x800087CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800087D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800087D4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800087D8: jal         0x800507E0
    // 0x800087DC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800507E0(rdram, ctx);
        goto after_4;
    // 0x800087DC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x800087E0: lui         $a0, 0x51
    ctx->r4 = S32(0X51 << 16);
    // 0x800087E4: sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
    // 0x800087E8: addiu       $a0, $a0, -0x73F0
    ctx->r4 = ADD32(ctx->r4, -0X73F0);
    // 0x800087EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800087F0: jal         0x8000C5FC
    // 0x800087F4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    dma_read_rom(rdram, ctx);
        goto after_5;
    // 0x800087F4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x800087F8: lui         $t1, 0x6B
    ctx->r9 = S32(0X6B << 16);
    // 0x800087FC: lui         $t2, 0x6A
    ctx->r10 = S32(0X6A << 16);
    // 0x80008800: addiu       $t2, $t2, 0x2580
    ctx->r10 = ADD32(ctx->r10, 0X2580);
    // 0x80008804: addiu       $t1, $t1, -0x1B10
    ctx->r9 = ADD32(ctx->r9, -0X1B10);
    // 0x80008808: subu        $v0, $t1, $t2
    ctx->r2 = SUB32(ctx->r9, ctx->r10);
    // 0x8000880C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80008810: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80008814: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80008818: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000881C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80008820: jal         0x800507E0
    // 0x80008824: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800507E0(rdram, ctx);
        goto after_6;
    // 0x80008824: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
    // 0x80008828: lui         $a0, 0x6A
    ctx->r4 = S32(0X6A << 16);
    // 0x8000882C: sw          $v0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r2;
    // 0x80008830: addiu       $a0, $a0, 0x2580
    ctx->r4 = ADD32(ctx->r4, 0X2580);
    // 0x80008834: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80008838: jal         0x8000C5FC
    // 0x8000883C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    dma_read_rom(rdram, ctx);
        goto after_7;
    // 0x8000883C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x80008840: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80008844: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80008848: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000884C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80008850: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80008854: jal         0x800507E0
    // 0x80008858: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800507E0(rdram, ctx);
        goto after_8;
    // 0x80008858: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_8:
    // 0x8000885C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80008860: addiu       $v1, $v1, 0x7638
    ctx->r3 = ADD32(ctx->r3, 0X7638);
    // 0x80008864: lui         $a0, 0x68
    ctx->r4 = S32(0X68 << 16);
    // 0x80008868: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000886C: addiu       $a0, $a0, 0x55A0
    ctx->r4 = ADD32(ctx->r4, 0X55A0);
    // 0x80008870: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80008874: jal         0x8000C5FC
    // 0x80008878: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    dma_read_rom(rdram, ctx);
        goto after_9;
    // 0x80008878: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_9:
    // 0x8000887C: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x80008880: lw          $t4, 0x7638($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7638);
    // 0x80008884: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80008888: addiu       $v0, $v0, 0x7634
    ctx->r2 = ADD32(ctx->r2, 0X7634);
    // 0x8000888C: lh          $t5, 0x2($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X2);
    // 0x80008890: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80008894: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80008898: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x8000889C: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x800088A0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800088A4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800088A8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800088AC: jal         0x800507E0
    // 0x800088B0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800507E0(rdram, ctx);
        goto after_10;
    // 0x800088B0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_10:
    // 0x800088B4: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800088B8: addiu       $v1, $v1, 0x7638
    ctx->r3 = ADD32(ctx->r3, 0X7638);
    // 0x800088BC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800088C0: lui         $a0, 0x68
    ctx->r4 = S32(0X68 << 16);
    // 0x800088C4: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800088C8: lw          $a2, 0x7634($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7634);
    // 0x800088CC: addiu       $a0, $a0, 0x55A0
    ctx->r4 = ADD32(ctx->r4, 0X55A0);
    // 0x800088D0: jal         0x8000C5FC
    // 0x800088D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    dma_read_rom(rdram, ctx);
        goto after_11;
    // 0x800088D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_11:
    // 0x800088D8: addiu       $t9, $zero, 0x4880
    ctx->r25 = ADD32(0, 0X4880);
    // 0x800088DC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800088E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800088E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800088E8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800088EC: jal         0x800507E0
    // 0x800088F0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800507E0(rdram, ctx);
        goto after_12;
    // 0x800088F0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_12:
    // 0x800088F4: lui         $t3, 0x8001
    ctx->r11 = S32(0X8001 << 16);
    // 0x800088F8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800088FC: addiu       $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
    // 0x80008900: addiu       $t1, $zero, 0x20
    ctx->r9 = ADD32(0, 0X20);
    // 0x80008904: addiu       $t2, $zero, 0x100
    ctx->r10 = ADD32(0, 0X100);
    // 0x80008908: addiu       $t3, $t3, -0x678C
    ctx->r11 = ADD32(ctx->r11, -0X678C);
    // 0x8000890C: sw          $v0, 0x7630($at)
    MEM_W(0X7630, ctx->r1) = ctx->r2;
    // 0x80008910: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    // 0x80008914: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
    // 0x80008918: sw          $t2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r10;
    // 0x8000891C: sw          $t3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r11;
    // 0x80008920: jal         0x80050840
    // 0x80008924: ori         $a0, $zero, 0xAC44
    ctx->r4 = 0 | 0XAC44;
    osAiSetFrequency_recomp(rdram, ctx);
        goto after_13;
    // 0x80008924: ori         $a0, $zero, 0xAC44
    ctx->r4 = 0 | 0XAC44;
    after_13:
    // 0x80008928: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8000892C: ori         $t5, $zero, 0xAC44
    ctx->r13 = 0 | 0XAC44;
    // 0x80008930: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80008934: addiu       $t7, $zero, 0x1000
    ctx->r15 = ADD32(0, 0X1000);
    // 0x80008938: sw          $v0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r2;
    // 0x8000893C: sw          $s0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r16;
    // 0x80008940: sb          $t4, 0x84($sp)
    MEM_B(0X84, ctx->r29) = ctx->r12;
    // 0x80008944: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x80008948: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x8000894C: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x80008950: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x80008954: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x80008958: jal         0x80008A98
    // 0x8000895C: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_80008A98(rdram, ctx);
        goto after_14;
    // 0x8000895C: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_14:
    // 0x80008960: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80008964: lui         $a1, 0x68
    ctx->r5 = S32(0X68 << 16);
    // 0x80008968: addiu       $a1, $a1, 0x55A0
    ctx->r5 = ADD32(ctx->r5, 0X55A0);
    // 0x8000896C: jal         0x80050BA8
    // 0x80008970: lw          $a0, 0x7638($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7638);
    func_80050BA8(rdram, ctx);
        goto after_15;
    // 0x80008970: lw          $a0, 0x7638($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7638);
    after_15:
    // 0x80008974: lui         $t1, 0x8001
    ctx->r9 = S32(0X8001 << 16);
    // 0x80008978: lui         $t2, 0x8001
    ctx->r10 = S32(0X8001 << 16);
    // 0x8000897C: lui         $t3, 0x8001
    ctx->r11 = S32(0X8001 << 16);
    // 0x80008980: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x80008984: addiu       $t9, $zero, 0x100
    ctx->r25 = ADD32(0, 0X100);
    // 0x80008988: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x8000898C: addiu       $t1, $t1, -0x65EC
    ctx->r9 = ADD32(ctx->r9, -0X65EC);
    // 0x80008990: addiu       $t2, $t2, -0x6314
    ctx->r10 = ADD32(ctx->r10, -0X6314);
    // 0x80008994: addiu       $t3, $t3, -0x5D98
    ctx->r11 = ADD32(ctx->r11, -0X5D98);
    // 0x80008998: lui         $a1, 0x51
    ctx->r5 = S32(0X51 << 16);
    // 0x8000899C: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x800089A0: sw          $t9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r25;
    // 0x800089A4: sb          $t0, 0x54($sp)
    MEM_B(0X54, ctx->r29) = ctx->r8;
    // 0x800089A8: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x800089AC: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x800089B0: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x800089B4: sw          $t3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r11;
    // 0x800089B8: addiu       $a1, $a1, 0x2B20
    ctx->r5 = ADD32(ctx->r5, 0X2B20);
    // 0x800089BC: jal         0x80050AA4
    // 0x800089C0: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    func_80050AA4(rdram, ctx);
        goto after_16;
    // 0x800089C0: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    after_16:
    // 0x800089C4: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800089C8: lw          $a0, 0x7610($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7610);
    // 0x800089CC: jal         0x80051CB0
    // 0x800089D0: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_80051CB0(rdram, ctx);
        goto after_17;
    // 0x800089D0: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_17:
    // 0x800089D4: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
    // 0x800089D8: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800089DC: lw          $a0, 0x7610($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7610);
    // 0x800089E0: jal         0x80051E20
    // 0x800089E4: lw          $a1, 0x4($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X4);
    func_80051E20(rdram, ctx);
        goto after_18;
    // 0x800089E4: lw          $a1, 0x4($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X4);
    after_18:
    // 0x800089E8: lui         $a1, 0x6B
    ctx->r5 = S32(0X6B << 16);
    // 0x800089EC: addiu       $a1, $a1, -0x1B10
    ctx->r5 = ADD32(ctx->r5, -0X1B10);
    // 0x800089F0: jal         0x80050AA4
    // 0x800089F4: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    func_80050AA4(rdram, ctx);
        goto after_19;
    // 0x800089F4: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    after_19:
    // 0x800089F8: lw          $t5, 0x90($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X90);
    // 0x800089FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80008A00: addiu       $t7, $zero, 0x152
    ctx->r15 = ADD32(0, 0X152);
    // 0x80008A04: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x80008A08: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80008A0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80008A10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80008A14: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80008A18: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80008A1C: jal         0x800507E0
    // 0x80008A20: sw          $t6, 0x7620($at)
    MEM_W(0X7620, ctx->r1) = ctx->r14;
    func_800507E0(rdram, ctx);
        goto after_20;
    // 0x80008A20: sw          $t6, 0x7620($at)
    MEM_W(0X7620, ctx->r1) = ctx->r14;
    after_20:
    // 0x80008A24: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80008A28: addiu       $t8, $zero, 0xA9
    ctx->r24 = ADD32(0, 0XA9);
    // 0x80008A2C: addiu       $t9, $zero, 0x100
    ctx->r25 = ADD32(0, 0X100);
    // 0x80008A30: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80008A34: sw          $v0, 0x7628($at)
    MEM_W(0X7628, ctx->r1) = ctx->r2;
    // 0x80008A38: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x80008A3C: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x80008A40: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80008A44: lw          $a0, 0x7618($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7618);
    // 0x80008A48: jal         0x80052434
    // 0x80008A4C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_80052434(rdram, ctx);
        goto after_21;
    // 0x80008A4C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_21:
    // 0x80008A50: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80008A54: jal         0x80052570
    // 0x80008A58: addiu       $a0, $a0, 0x7668
    ctx->r4 = ADD32(ctx->r4, 0X7668);
    osStartThread_recomp(rdram, ctx);
        goto after_22;
    // 0x80008A58: addiu       $a0, $a0, 0x7668
    ctx->r4 = ADD32(ctx->r4, 0X7668);
    after_22:
    // 0x80008A5C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80008A60: addiu       $v0, $v0, 0x762C
    ctx->r2 = ADD32(ctx->r2, 0X762C);
    // 0x80008A64: addiu       $t0, $zero, 0x67F0
    ctx->r8 = ADD32(0, 0X67F0);
    // 0x80008A68: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
    // 0x80008A6C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80008A70: lw          $a0, 0x7610($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7610);
    // 0x80008A74: jal         0x800505D0
    // 0x80008A78: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    func_800505D0(rdram, ctx);
        goto after_23;
    // 0x80008A78: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    after_23:
    // 0x80008A7C: jal         0x800083EC
    // 0x80008A80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800083EC(rdram, ctx);
        goto after_24;
    // 0x80008A80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_24:
    // 0x80008A84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80008A88: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80008A8C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    // 0x80008A90: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80008A98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80008A98: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x80008A9C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80008AA0: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80008AA4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80008AA8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80008AAC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80008AB0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80008AB4: sw          $a1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r5;
    // 0x80008AB8: lw          $t6, 0x4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X4);
    // 0x80008ABC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80008AC0: addiu       $v1, $v1, -0x4214
    ctx->r3 = ADD32(ctx->r3, -0X4214);
    // 0x80008AC4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80008AC8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80008ACC: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x80008AD0: bgez        $t6, L_80008AE8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80008AD4: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80008AE8;
    }
    // 0x80008AD4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80008AD8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80008ADC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80008AE0: nop

    // 0x80008AE4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80008AE8:
    // 0x80008AE8: lw          $t7, 0x18($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X18);
    // 0x80008AEC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80008AF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80008AF4: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80008AF8: nop

    // 0x80008AFC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80008B00: mul.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80008B04: div.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80008B08: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80008B0C: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80008B10: nop

    // 0x80008B14: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80008B18: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80008B1C: bgez        $v0, L_80008B34
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80008B20: cvt.s.w     $f6, $f10
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80008B34;
    }
    // 0x80008B20: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80008B24: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80008B28: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80008B2C: nop

    // 0x80008B30: add.s       $f6, $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f16.fl;
L_80008B34:
    // 0x80008B34: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80008B38: nop

    // 0x80008B3C: bc1f        L_80008B4C
    if (!c1cs) {
        // 0x80008B40: addiu       $t0, $v0, 0x1
        ctx->r8 = ADD32(ctx->r2, 0X1);
            goto L_80008B4C;
    }
    // 0x80008B40: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    // 0x80008B44: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80008B48: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_80008B4C:
    // 0x80008B4C: andi        $t1, $v0, 0xF
    ctx->r9 = ctx->r2 & 0XF;
    // 0x80008B50: beq         $t1, $zero, L_80008B64
    if (ctx->r9 == 0) {
        // 0x80008B54: addiu       $at, $zero, -0x10
        ctx->r1 = ADD32(0, -0X10);
            goto L_80008B64;
    }
    // 0x80008B54: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80008B58: and         $t2, $v0, $at
    ctx->r10 = ctx->r2 & ctx->r1;
    // 0x80008B5C: addiu       $v0, $t2, 0x10
    ctx->r2 = ADD32(ctx->r10, 0X10);
    // 0x80008B60: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80008B64:
    // 0x80008B64: addiu       $t4, $v0, -0x10
    ctx->r12 = ADD32(ctx->r2, -0X10);
    // 0x80008B68: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80008B6C: sw          $t4, -0x4218($at)
    MEM_W(-0X4218, ctx->r1) = ctx->r12;
    // 0x80008B70: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80008B74: addiu       $t5, $v0, 0x60
    ctx->r13 = ADD32(ctx->r2, 0X60);
    // 0x80008B78: sw          $t5, -0x4210($at)
    MEM_W(-0X4210, ctx->r1) = ctx->r13;
    // 0x80008B7C: lbu         $t6, 0x1C($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X1C);
    // 0x80008B80: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80008B84: bne         $t6, $at, L_80008BEC
    if (ctx->r14 != ctx->r1) {
        // 0x80008B88: lui         $t7, 0x8007
        ctx->r15 = S32(0X8007 << 16);
            goto L_80008BEC;
    }
    // 0x80008B88: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x80008B8C: addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // 0x80008B90: addiu       $t7, $t7, -0x6CB4
    ctx->r15 = ADD32(ctx->r15, -0X6CB4);
    // 0x80008B94: addiu       $t9, $t7, 0x60
    ctx->r25 = ADD32(ctx->r15, 0X60);
    // 0x80008B98: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
L_80008B9C:
    // 0x80008B9C: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80008BA0: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80008BA4: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x80008BA8: sw          $at, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r1;
    // 0x80008BAC: lw          $at, -0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X8);
    // 0x80008BB0: sw          $at, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r1;
    // 0x80008BB4: lw          $at, -0x4($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X4);
    // 0x80008BB8: bne         $t7, $t9, L_80008B9C
    if (ctx->r15 != ctx->r25) {
        // 0x80008BBC: sw          $at, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r1;
            goto L_80008B9C;
    }
    // 0x80008BBC: sw          $at, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r1;
    // 0x80008BC0: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80008BC4: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80008BC8: addiu       $a0, $a0, 0x7888
    ctx->r4 = ADD32(ctx->r4, 0X7888);
    // 0x80008BCC: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x80008BD0: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x80008BD4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80008BD8: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x80008BDC: jal         0x8005274C
    // 0x80008BE0: sw          $v0, 0x20($s3)
    MEM_W(0X20, ctx->r19) = ctx->r2;
    func_8005274C(rdram, ctx);
        goto after_0;
    // 0x80008BE0: sw          $v0, 0x20($s3)
    MEM_W(0X20, ctx->r19) = ctx->r2;
    after_0:
    // 0x80008BE4: b           L_80008BFC
    // 0x80008BE8: nop

        goto L_80008BFC;
    // 0x80008BE8: nop

L_80008BEC:
    // 0x80008BEC: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80008BF0: addiu       $a0, $a0, 0x7888
    ctx->r4 = ADD32(ctx->r4, 0X7888);
    // 0x80008BF4: jal         0x8005274C
    // 0x80008BF8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_8005274C(rdram, ctx);
        goto after_1;
    // 0x80008BF8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_1:
L_80008BFC:
    // 0x80008BFC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80008C00: addiu       $v1, $a0, -0x3360
    ctx->r3 = ADD32(ctx->r4, -0X3360);
    // 0x80008C04: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80008C08: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80008C0C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80008C10: sw          $v1, -0x3364($at)
    MEM_W(-0X3364, ctx->r1) = ctx->r3;
    // 0x80008C14: addiu       $v0, $v0, -0x334C
    ctx->r2 = ADD32(ctx->r2, -0X334C);
    // 0x80008C18: addiu       $a0, $a0, -0x2E60
    ctx->r4 = ADD32(ctx->r4, -0X2E60);
    // 0x80008C1C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80008C20:
    // 0x80008C20: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80008C24: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x80008C28: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x80008C2C: bnel        $at, $zero, L_80008C20
    if (ctx->r1 != 0) {
        // 0x80008C30: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_80008C20;
    }
    goto skip_0;
    // 0x80008C30: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    skip_0:
    // 0x80008C34: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80008C38: addiu       $v0, $v0, -0x4718
    ctx->r2 = ADD32(ctx->r2, -0X4718);
    // 0x80008C3C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80008C40: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x80008C44: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80008C48: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80008C4C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80008C50: addiu       $s0, $s0, -0x4704
    ctx->r16 = ADD32(ctx->r16, -0X4704);
    // 0x80008C54: addiu       $s1, $s1, -0x4718
    ctx->r17 = ADD32(ctx->r17, -0X4718);
    // 0x80008C58: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80008C5C:
    // 0x80008C5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80008C60: jal         0x800526F0
    // 0x80008C64: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800526F0(rdram, ctx);
        goto after_2;
    // 0x80008C64: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x80008C68: lw          $a2, 0x14($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X14);
    // 0x80008C6C: addiu       $t1, $zero, 0x400
    ctx->r9 = ADD32(0, 0X400);
    // 0x80008C70: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80008C74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80008C78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80008C7C: jal         0x800507E0
    // 0x80008C80: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800507E0(rdram, ctx);
        goto after_3;
    // 0x80008C80: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x80008C84: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80008C88: sltiu       $at, $s2, 0x3F
    ctx->r1 = ctx->r18 < 0X3F ? 1 : 0;
    // 0x80008C8C: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    // 0x80008C90: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x80008C94: bne         $at, $zero, L_80008C5C
    if (ctx->r1 != 0) {
        // 0x80008C98: sw          $v0, -0x4($s1)
        MEM_W(-0X4, ctx->r17) = ctx->r2;
            goto L_80008C5C;
    }
    // 0x80008C98: sw          $v0, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->r2;
    // 0x80008C9C: lw          $a2, 0x14($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X14);
    // 0x80008CA0: addiu       $t2, $zero, 0x400
    ctx->r10 = ADD32(0, 0X400);
    // 0x80008CA4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80008CA8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80008CAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80008CB0: jal         0x800507E0
    // 0x80008CB4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800507E0(rdram, ctx);
        goto after_4;
    // 0x80008CB4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x80008CB8: sw          $v0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r2;
    // 0x80008CBC: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x80008CC0: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80008CC4: addiu       $s0, $s0, 0x7650
    ctx->r16 = ADD32(ctx->r16, 0X7650);
    // 0x80008CC8: addiu       $s1, $s1, 0x7658
    ctx->r17 = ADD32(ctx->r17, 0X7658);
L_80008CCC:
    // 0x80008CCC: lw          $t3, 0x8($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X8);
    // 0x80008CD0: lw          $a2, 0x14($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X14);
    // 0x80008CD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80008CD8: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80008CDC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80008CE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80008CE4: jal         0x800507E0
    // 0x80008CE8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800507E0(rdram, ctx);
        goto after_5;
    // 0x80008CE8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x80008CEC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80008CF0: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x80008CF4: bne         $at, $zero, L_80008CCC
    if (ctx->r1 != 0) {
        // 0x80008CF8: sw          $v0, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->r2;
            goto L_80008CCC;
    }
    // 0x80008CF8: sw          $v0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r2;
    // 0x80008CFC: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80008D00: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    // 0x80008D04: addiu       $s2, $s2, 0x765C
    ctx->r18 = ADD32(ctx->r18, 0X765C);
    // 0x80008D08: addiu       $s0, $s0, 0x7650
    ctx->r16 = ADD32(ctx->r16, 0X7650);
    // 0x80008D0C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_80008D10:
    // 0x80008D10: lw          $a2, 0x14($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X14);
    // 0x80008D14: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x80008D18: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80008D1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80008D20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80008D24: jal         0x800507E0
    // 0x80008D28: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800507E0(rdram, ctx);
        goto after_6;
    // 0x80008D28: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
    // 0x80008D2C: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x80008D30: sh          $s1, 0x60($v0)
    MEM_H(0X60, ctx->r2) = ctx->r17;
    // 0x80008D34: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x80008D38: addiu       $t6, $zero, 0x6000
    ctx->r14 = ADD32(0, 0X6000);
    // 0x80008D3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80008D40: sw          $v1, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->r3;
    // 0x80008D44: lw          $a2, 0x14($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X14);
    // 0x80008D48: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80008D4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80008D50: jal         0x800507E0
    // 0x80008D54: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800507E0(rdram, ctx);
        goto after_7;
    // 0x80008D54: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x80008D58: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80008D5C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80008D60: bne         $s0, $s2, L_80008D10
    if (ctx->r16 != ctx->r18) {
        // 0x80008D64: sw          $v0, 0x0($t8)
        MEM_W(0X0, ctx->r24) = ctx->r2;
            goto L_80008D10;
    }
    // 0x80008D64: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x80008D68: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80008D6C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80008D70: addiu       $a1, $a1, 0x7868
    ctx->r5 = ADD32(ctx->r5, 0X7868);
    // 0x80008D74: addiu       $a0, $a0, 0x7850
    ctx->r4 = ADD32(ctx->r4, 0X7850);
    // 0x80008D78: jal         0x80052780
    // 0x80008D7C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_8;
    // 0x80008D7C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_8:
    // 0x80008D80: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80008D84: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80008D88: addiu       $a1, $a1, 0x7830
    ctx->r5 = ADD32(ctx->r5, 0X7830);
    // 0x80008D8C: addiu       $a0, $a0, 0x7818
    ctx->r4 = ADD32(ctx->r4, 0X7818);
    // 0x80008D90: jal         0x80052780
    // 0x80008D94: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_9;
    // 0x80008D94: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_9:
    // 0x80008D98: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80008D9C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80008DA0: addiu       $a1, $a1, -0x3EF0
    ctx->r5 = ADD32(ctx->r5, -0X3EF0);
    // 0x80008DA4: addiu       $a0, $a0, -0x3F08
    ctx->r4 = ADD32(ctx->r4, -0X3F08);
    // 0x80008DA8: jal         0x80052780
    // 0x80008DAC: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_10;
    // 0x80008DAC: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_10:
    // 0x80008DB0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80008DB4: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80008DB8: addiu       $a1, $a1, -0x4A18
    ctx->r5 = ADD32(ctx->r5, -0X4A18);
    // 0x80008DBC: addiu       $a0, $a0, -0x4A30
    ctx->r4 = ADD32(ctx->r4, -0X4A30);
    // 0x80008DC0: jal         0x80052780
    // 0x80008DC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_11;
    // 0x80008DC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x80008DC8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80008DCC: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80008DD0: addiu       $a1, $a1, -0x49F8
    ctx->r5 = ADD32(ctx->r5, -0X49F8);
    // 0x80008DD4: addiu       $a0, $a0, -0x4A10
    ctx->r4 = ADD32(ctx->r4, -0X4A10);
    // 0x80008DD8: jal         0x80052780
    // 0x80008DDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_12;
    // 0x80008DDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_12:
    // 0x80008DE0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80008DE4: addiu       $t9, $t9, -0x4728
    ctx->r25 = ADD32(ctx->r25, -0X4728);
    // 0x80008DE8: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80008DEC: lui         $a2, 0x8001
    ctx->r6 = S32(0X8001 << 16);
    // 0x80008DF0: addiu       $t7, $zero, 0x13
    ctx->r15 = ADD32(0, 0X13);
    // 0x80008DF4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80008DF8: addiu       $a2, $a2, -0x71D0
    ctx->r6 = ADD32(ctx->r6, -0X71D0);
    // 0x80008DFC: addiu       $a0, $a0, 0x7668
    ctx->r4 = ADD32(ctx->r4, 0X7668);
    // 0x80008E00: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80008E04: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80008E08: jal         0x800527B0
    // 0x80008E0C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_13;
    // 0x80008E0C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_13:
    // 0x80008E10: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80008E14: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80008E18: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80008E1C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80008E20: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80008E24: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80008E28: jr          $ra
    // 0x80008E2C: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    TRACE_RETURN()
    return;
    // 0x80008E2C: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void func_80008E30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80008E30: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80008E34: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x80008E38: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80008E3C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80008E40: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80008E44: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80008E48: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80008E4C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80008E50: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80008E54: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80008E58: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80008E5C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80008E60: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80008E64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80008E68: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x80008E6C: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    // 0x80008E70: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    // 0x80008E74: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    // 0x80008E78: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x80008E7C: addiu       $a2, $a2, 0x7818
    ctx->r6 = ADD32(ctx->r6, 0X7818);
    // 0x80008E80: addiu       $a0, $a0, 0x46A0
    ctx->r4 = ADD32(ctx->r4, 0X46A0);
    // 0x80008E84: jal         0x800530C0
    // 0x80008E88: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    func_800530C0(rdram, ctx);
        goto after_0;
    // 0x80008E88: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    after_0:
    // 0x80008E8C: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x80008E90: lui         $s5, 0x800D
    ctx->r21 = S32(0X800D << 16);
    // 0x80008E94: lui         $s4, 0x800D
    ctx->r20 = S32(0X800D << 16);
    // 0x80008E98: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x80008E9C: addiu       $s1, $s1, 0x7618
    ctx->r17 = ADD32(ctx->r17, 0X7618);
    // 0x80008EA0: addiu       $s4, $s4, 0x7624
    ctx->r20 = ADD32(ctx->r20, 0X7624);
    // 0x80008EA4: addiu       $s5, $s5, 0x7628
    ctx->r21 = ADD32(ctx->r21, 0X7628);
    // 0x80008EA8: addiu       $s7, $s7, -0x3E60
    ctx->r23 = ADD32(ctx->r23, -0X3E60);
    // 0x80008EAC: addiu       $fp, $zero, 0x7
    ctx->r30 = ADD32(0, 0X7);
    // 0x80008EB0: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
    // 0x80008EB4: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80008EB8:
    // 0x80008EB8: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80008EBC: addiu       $a0, $a0, 0x7818
    ctx->r4 = ADD32(ctx->r4, 0X7818);
    // 0x80008EC0: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x80008EC4: jal         0x8004F990
    // 0x80008EC8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80008EC8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80008ECC: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x80008ED0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80008ED4: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x80008ED8: lh          $v1, 0x0($t6)
    ctx->r3 = MEM_H(ctx->r14, 0X0);
    // 0x80008EDC: addiu       $t7, $t7, -0x7980
    ctx->r15 = ADD32(ctx->r15, -0X7980);
    // 0x80008EE0: beql        $v1, $at, L_80008F00
    if (ctx->r3 == ctx->r1) {
        // 0x80008EE4: lw          $t8, 0x0($t7)
        ctx->r24 = MEM_W(ctx->r15, 0X0);
            goto L_80008F00;
    }
    goto skip_0;
    // 0x80008EE4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    skip_0:
    // 0x80008EE8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80008EEC: beq         $v1, $at, L_800093E0
    if (ctx->r3 == ctx->r1) {
        // 0x80008EF0: nop
    
            goto L_800093E0;
    }
    // 0x80008EF0: nop

    // 0x80008EF4: b           L_80009474
    // 0x80008EF8: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
        goto L_80009474;
    // 0x80008EF8: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x80008EFC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
L_80008F00:
    // 0x80008F00: beq         $t8, $zero, L_80008F10
    if (ctx->r24 == 0) {
        // 0x80008F04: nop
    
            goto L_80008F10;
    }
    // 0x80008F04: nop

    // 0x80008F08: b           L_80009474
    // 0x80008F0C: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
        goto L_80009474;
    // 0x80008F0C: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
L_80008F10:
    // 0x80008F10: lui         $t9, 0x8007
    ctx->r25 = S32(0X8007 << 16);
    // 0x80008F14: addiu       $t9, $t9, -0x797C
    ctx->r25 = ADD32(ctx->r25, -0X797C);
    // 0x80008F18: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80008F1C: lui         $t3, 0x8007
    ctx->r11 = S32(0X8007 << 16);
    // 0x80008F20: addiu       $t3, $t3, -0x7980
    ctx->r11 = ADD32(ctx->r11, -0X7980);
    // 0x80008F24: beq         $t0, $zero, L_80008F48
    if (ctx->r8 == 0) {
        // 0x80008F28: lui         $t4, 0x8007
        ctx->r12 = S32(0X8007 << 16);
            goto L_80008F48;
    }
    // 0x80008F28: lui         $t4, 0x8007
    ctx->r12 = S32(0X8007 << 16);
    // 0x80008F2C: lui         $t1, 0x8007
    ctx->r9 = S32(0X8007 << 16);
    // 0x80008F30: addiu       $t1, $t1, -0x7974
    ctx->r9 = ADD32(ctx->r9, -0X7974);
    // 0x80008F34: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x80008F38: bnel        $t2, $zero, L_80008F4C
    if (ctx->r10 != 0) {
        // 0x80008F3C: sw          $s3, 0x0($t3)
        MEM_W(0X0, ctx->r11) = ctx->r19;
            goto L_80008F4C;
    }
    goto skip_1;
    // 0x80008F3C: sw          $s3, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r19;
    skip_1:
    // 0x80008F40: b           L_80009474
    // 0x80008F44: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
        goto L_80009474;
    // 0x80008F44: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
L_80008F48:
    // 0x80008F48: sw          $s3, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r19;
L_80008F4C:
    // 0x80008F4C: lw          $t4, -0x7954($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7954);
    // 0x80008F50: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80008F54: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x80008F58: divu        $zero, $t4, $s6
    lo = S32(U32(ctx->r12) / U32(ctx->r22)); hi = S32(U32(ctx->r12) % U32(ctx->r22));
    // 0x80008F5C: mfhi        $t5
    ctx->r13 = hi;
    // 0x80008F60: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80008F64: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x80008F68: bne         $s6, $zero, L_80008F74
    if (ctx->r22 != 0) {
        // 0x80008F6C: nop
    
            goto L_80008F74;
    }
    // 0x80008F6C: nop

    // 0x80008F70: break       7
    do_break(2147520368);
L_80008F74:
    // 0x80008F74: lw          $a0, 0x7658($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7658);
    // 0x80008F78: jal         0x800094F0
    // 0x80008F7C: nop

    func_800094F0(rdram, ctx);
        goto after_2;
    // 0x80008F7C: nop

    after_2:
    // 0x80008F80: beq         $v0, $zero, L_80008FB0
    if (ctx->r2 == 0) {
        // 0x80008F84: lui         $a0, 0x800D
        ctx->r4 = S32(0X800D << 16);
            goto L_80008FB0;
    }
    // 0x80008F84: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80008F88: addiu       $a0, $a0, 0x7850
    ctx->r4 = ADD32(ctx->r4, 0X7850);
    // 0x80008F8C: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x80008F90: jal         0x8004F990
    // 0x80008F94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x80008F94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80008F98: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x80008F9C: jal         0x800096B8
    // 0x80008FA0: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    func_800096B8(rdram, ctx);
        goto after_4;
    // 0x80008FA0: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    after_4:
    // 0x80008FA4: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x80008FA8: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80008FAC: sw          $t9, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r25;
L_80008FB0:
    // 0x80008FB0: lui         $t0, 0x8007
    ctx->r8 = S32(0X8007 << 16);
    // 0x80008FB4: addiu       $t0, $t0, -0x795C
    ctx->r8 = ADD32(ctx->r8, -0X795C);
    // 0x80008FB8: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80008FBC: beq         $t1, $zero, L_800091DC
    if (ctx->r9 == 0) {
        // 0x80008FC0: nop
    
            goto L_800091DC;
    }
    // 0x80008FC0: nop

    // 0x80008FC4: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x80008FC8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80008FCC: lh          $t3, 0xE($t2)
    ctx->r11 = MEM_H(ctx->r10, 0XE);
    // 0x80008FD0: blez        $t3, L_800091DC
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80008FD4: nop
    
            goto L_800091DC;
    }
    // 0x80008FD4: nop

    // 0x80008FD8: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
L_80008FDC:
    // 0x80008FDC: sll         $t5, $s2, 1
    ctx->r13 = S32(ctx->r18 << 1);
    // 0x80008FE0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80008FE4: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80008FE8: jal         0x80050640
    // 0x80008FEC: lh          $a1, 0x0($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X0);
    func_80050640(rdram, ctx);
        goto after_5;
    // 0x80008FEC: lh          $a1, 0x0($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X0);
    after_5:
    // 0x80008FF0: jal         0x80053240
    // 0x80008FF4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_80053240(rdram, ctx);
        goto after_6;
    // 0x80008FF4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_6:
    // 0x80008FF8: sll         $t7, $s2, 4
    ctx->r15 = S32(ctx->r18 << 4);
    // 0x80008FFC: addu        $s0, $s7, $t7
    ctx->r16 = ADD32(ctx->r23, ctx->r15);
    // 0x80009000: lbu         $t8, 0xC($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XC);
    // 0x80009004: sltiu       $at, $t8, 0x8
    ctx->r1 = ctx->r24 < 0X8 ? 1 : 0;
    // 0x80009008: beq         $at, $zero, L_800091BC
    if (ctx->r1 == 0) {
        // 0x8000900C: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_800091BC;
    }
    // 0x8000900C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80009010: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80009014: addu        $at, $at, $t8
    gpr jr_addend_8000901C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80009018: lw          $t8, 0x5E74($at)
    ctx->r24 = ADD32(ctx->r1, 0X5E74);
    // 0x8000901C: jr          $t8
    // 0x80009020: nop

    switch (jr_addend_8000901C >> 2) {
        case 0: goto L_800091BC; break;
        case 1: goto L_80009048; break;
        case 2: goto L_80009058; break;
        case 3: goto L_8000911C; break;
        case 4: goto L_80009048; break;
        case 5: goto L_80009024; break;
        case 6: goto L_800090B8; break;
        case 7: goto L_8000916C; break;
        default: switch_error(__func__, 0x8000901C, 0x80075E74);
    }
    // 0x80009020: nop

L_80009024:
    // 0x80009024: beq         $v0, $zero, L_80009040
    if (ctx->r2 == 0) {
        // 0x80009028: nop
    
            goto L_80009040;
    }
    // 0x80009028: nop

    // 0x8000902C: jal         0x80050660
    // 0x80009030: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_80050660(rdram, ctx);
        goto after_7;
    // 0x80009030: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_7:
    // 0x80009034: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80009038: b           L_800091BC
    // 0x8000903C: sb          $t9, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r25;
        goto L_800091BC;
    // 0x8000903C: sb          $t9, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r25;
L_80009040:
    // 0x80009040: b           L_800091BC
    // 0x80009044: sb          $zero, 0xC($s0)
    MEM_B(0XC, ctx->r16) = 0;
        goto L_800091BC;
    // 0x80009044: sb          $zero, 0xC($s0)
    MEM_B(0XC, ctx->r16) = 0;
L_80009048:
    // 0x80009048: bnel        $v0, $zero, L_800091C0
    if (ctx->r2 != 0) {
        // 0x8000904C: lw          $t9, 0x0($s4)
        ctx->r25 = MEM_W(ctx->r20, 0X0);
            goto L_800091C0;
    }
    goto skip_2;
    // 0x8000904C: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    skip_2:
    // 0x80009050: b           L_800091BC
    // 0x80009054: sb          $zero, 0xC($s0)
    MEM_B(0XC, ctx->r16) = 0;
        goto L_800091BC;
    // 0x80009054: sb          $zero, 0xC($s0)
    MEM_B(0XC, ctx->r16) = 0;
L_80009058:
    // 0x80009058: bne         $v0, $zero, L_800090A8
    if (ctx->r2 != 0) {
        // 0x8000905C: nop
    
            goto L_800090A8;
    }
    // 0x8000905C: nop

    // 0x80009060: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80009064: jal         0x80053260
    // 0x80009068: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_80053260(rdram, ctx);
        goto after_8;
    // 0x80009068: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_8:
    // 0x8000906C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80009070: jal         0x800532C0
    // 0x80009074: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800532C0(rdram, ctx);
        goto after_9;
    // 0x80009074: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x80009078: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8000907C: jal         0x80053320
    // 0x80009080: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_80053320(rdram, ctx);
        goto after_10;
    // 0x80009080: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_10:
    // 0x80009084: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x80009088: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8000908C: sll         $t0, $a1, 16
    ctx->r8 = S32(ctx->r5 << 16);
    // 0x80009090: jal         0x80053380
    // 0x80009094: sra         $a1, $t0, 16
    ctx->r5 = S32(SIGNED(ctx->r8) >> 16);
    func_80053380(rdram, ctx);
        goto after_11;
    // 0x80009094: sra         $a1, $t0, 16
    ctx->r5 = S32(SIGNED(ctx->r8) >> 16);
    after_11:
    // 0x80009098: jal         0x800533E0
    // 0x8000909C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_800533E0(rdram, ctx);
        goto after_12;
    // 0x8000909C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_12:
    // 0x800090A0: b           L_800091BC
    // 0x800090A4: sb          $s3, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r19;
        goto L_800091BC;
    // 0x800090A4: sb          $s3, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r19;
L_800090A8:
    // 0x800090A8: jal         0x80050660
    // 0x800090AC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_80050660(rdram, ctx);
        goto after_13;
    // 0x800090AC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_13:
    // 0x800090B0: b           L_800091BC
    // 0x800090B4: sb          $s6, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r22;
        goto L_800091BC;
    // 0x800090B4: sb          $s6, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r22;
L_800090B8:
    // 0x800090B8: bne         $v0, $zero, L_8000910C
    if (ctx->r2 != 0) {
        // 0x800090BC: nop
    
            goto L_8000910C;
    }
    // 0x800090BC: nop

    // 0x800090C0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800090C4: jal         0x80053260
    // 0x800090C8: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_80053260(rdram, ctx);
        goto after_14;
    // 0x800090C8: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_14:
    // 0x800090CC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800090D0: jal         0x800532C0
    // 0x800090D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800532C0(rdram, ctx);
        goto after_15;
    // 0x800090D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x800090D8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800090DC: jal         0x80053320
    // 0x800090E0: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_80053320(rdram, ctx);
        goto after_16;
    // 0x800090E0: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_16:
    // 0x800090E4: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x800090E8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800090EC: sll         $t2, $a1, 16
    ctx->r10 = S32(ctx->r5 << 16);
    // 0x800090F0: jal         0x80053380
    // 0x800090F4: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
    func_80053380(rdram, ctx);
        goto after_17;
    // 0x800090F4: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
    after_17:
    // 0x800090F8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800090FC: jal         0x80053450
    // 0x80009100: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    func_80053450(rdram, ctx);
        goto after_18;
    // 0x80009100: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    after_18:
    // 0x80009104: b           L_800091BC
    // 0x80009108: sb          $s3, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r19;
        goto L_800091BC;
    // 0x80009108: sb          $s3, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r19;
L_8000910C:
    // 0x8000910C: jal         0x80050660
    // 0x80009110: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_80050660(rdram, ctx);
        goto after_19;
    // 0x80009110: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_19:
    // 0x80009114: b           L_800091BC
    // 0x80009118: sb          $fp, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r30;
        goto L_800091BC;
    // 0x80009118: sb          $fp, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r30;
L_8000911C:
    // 0x8000911C: bnel        $v0, $zero, L_800091C0
    if (ctx->r2 != 0) {
        // 0x80009120: lw          $t9, 0x0($s4)
        ctx->r25 = MEM_W(ctx->r20, 0X0);
            goto L_800091C0;
    }
    goto skip_3;
    // 0x80009120: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    skip_3:
    // 0x80009124: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80009128: jal         0x80053260
    // 0x8000912C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_80053260(rdram, ctx);
        goto after_20;
    // 0x8000912C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_20:
    // 0x80009130: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80009134: jal         0x800532C0
    // 0x80009138: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800532C0(rdram, ctx);
        goto after_21;
    // 0x80009138: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x8000913C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80009140: jal         0x80053320
    // 0x80009144: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_80053320(rdram, ctx);
        goto after_22;
    // 0x80009144: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_22:
    // 0x80009148: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8000914C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80009150: sll         $t4, $a1, 16
    ctx->r12 = S32(ctx->r5 << 16);
    // 0x80009154: jal         0x80053380
    // 0x80009158: sra         $a1, $t4, 16
    ctx->r5 = S32(SIGNED(ctx->r12) >> 16);
    func_80053380(rdram, ctx);
        goto after_23;
    // 0x80009158: sra         $a1, $t4, 16
    ctx->r5 = S32(SIGNED(ctx->r12) >> 16);
    after_23:
    // 0x8000915C: jal         0x800533E0
    // 0x80009160: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_800533E0(rdram, ctx);
        goto after_24;
    // 0x80009160: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_24:
    // 0x80009164: b           L_800091BC
    // 0x80009168: sb          $s3, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r19;
        goto L_800091BC;
    // 0x80009168: sb          $s3, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r19;
L_8000916C:
    // 0x8000916C: bnel        $v0, $zero, L_800091C0
    if (ctx->r2 != 0) {
        // 0x80009170: lw          $t9, 0x0($s4)
        ctx->r25 = MEM_W(ctx->r20, 0X0);
            goto L_800091C0;
    }
    goto skip_4;
    // 0x80009170: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    skip_4:
    // 0x80009174: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80009178: jal         0x80053260
    // 0x8000917C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_80053260(rdram, ctx);
        goto after_25;
    // 0x8000917C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_25:
    // 0x80009180: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80009184: jal         0x800532C0
    // 0x80009188: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800532C0(rdram, ctx);
        goto after_26;
    // 0x80009188: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_26:
    // 0x8000918C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80009190: jal         0x80053320
    // 0x80009194: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_80053320(rdram, ctx);
        goto after_27;
    // 0x80009194: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_27:
    // 0x80009198: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8000919C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800091A0: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x800091A4: jal         0x80053380
    // 0x800091A8: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    func_80053380(rdram, ctx);
        goto after_28;
    // 0x800091A8: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    after_28:
    // 0x800091AC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800091B0: jal         0x80053450
    // 0x800091B4: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    func_80053450(rdram, ctx);
        goto after_29;
    // 0x800091B4: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    after_29:
    // 0x800091B8: sb          $s3, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r19;
L_800091BC:
    // 0x800091BC: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
L_800091C0:
    // 0x800091C0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800091C4: andi        $t8, $s2, 0xFF
    ctx->r24 = ctx->r18 & 0XFF;
    // 0x800091C8: lh          $t0, 0xE($t9)
    ctx->r8 = MEM_H(ctx->r25, 0XE);
    // 0x800091CC: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
    // 0x800091D0: slt         $at, $t8, $t0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800091D4: bnel        $at, $zero, L_80008FDC
    if (ctx->r1 != 0) {
        // 0x800091D8: lw          $t4, 0x0($s5)
        ctx->r12 = MEM_W(ctx->r21, 0X0);
            goto L_80008FDC;
    }
    goto skip_5;
    // 0x800091D8: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
    skip_5:
L_800091DC:
    // 0x800091DC: lui         $t1, 0x8007
    ctx->r9 = S32(0X8007 << 16);
    // 0x800091E0: addiu       $t1, $t1, -0x7978
    ctx->r9 = ADD32(ctx->r9, -0X7978);
    // 0x800091E4: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x800091E8: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800091EC: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x800091F0: beq         $t2, $at, L_80009250
    if (ctx->r10 == ctx->r1) {
        // 0x800091F4: nop
    
            goto L_80009250;
    }
    // 0x800091F4: nop

    // 0x800091F8: bne         $t3, $zero, L_8000921C
    if (ctx->r11 != 0) {
        // 0x800091FC: nop
    
            goto L_8000921C;
    }
    // 0x800091FC: nop

    // 0x80009200: jal         0x80053240
    // 0x80009204: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_80053240(rdram, ctx);
        goto after_30;
    // 0x80009204: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_30:
    // 0x80009208: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000920C: bne         $v0, $at, L_80009250
    if (ctx->r2 != ctx->r1) {
        // 0x80009210: nop
    
            goto L_80009250;
    }
    // 0x80009210: nop

    // 0x80009214: b           L_80009250
    // 0x80009218: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
        goto L_80009250;
    // 0x80009218: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
L_8000921C:
    // 0x8000921C: jal         0x80053240
    // 0x80009220: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_80053240(rdram, ctx);
        goto after_31;
    // 0x80009220: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_31:
    // 0x80009224: bne         $v0, $zero, L_80009250
    if (ctx->r2 != 0) {
        // 0x80009228: ori         $t4, $zero, 0xFFFF
        ctx->r12 = 0 | 0XFFFF;
            goto L_80009250;
    }
    // 0x80009228: ori         $t4, $zero, 0xFFFF
    ctx->r12 = 0 | 0XFFFF;
    // 0x8000922C: lui         $t5, 0x8007
    ctx->r13 = S32(0X8007 << 16);
    // 0x80009230: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    // 0x80009234: addiu       $t5, $t5, -0x7978
    ctx->r13 = ADD32(ctx->r13, -0X7978);
    // 0x80009238: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8000923C: sh          $t4, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r12;
    // 0x80009240: addiu       $a0, $a0, -0x4A30
    ctx->r4 = ADD32(ctx->r4, -0X4A30);
    // 0x80009244: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x80009248: jal         0x800534A0
    // 0x8000924C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_32;
    // 0x8000924C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_32:
L_80009250:
    // 0x80009250: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x80009254: addiu       $t6, $t6, -0x7960
    ctx->r14 = ADD32(ctx->r14, -0X7960);
    // 0x80009258: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8000925C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80009260: lui         $t8, 0x8007
    ctx->r24 = S32(0X8007 << 16);
    // 0x80009264: bne         $t7, $at, L_80009378
    if (ctx->r15 != ctx->r1) {
        // 0x80009268: addiu       $t8, $t8, -0x7970
        ctx->r24 = ADD32(ctx->r24, -0X7970);
            goto L_80009378;
    }
    // 0x80009268: addiu       $t8, $t8, -0x7970
    ctx->r24 = ADD32(ctx->r24, -0X7970);
    // 0x8000926C: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80009270: lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // 0x80009274: addiu       $v1, $v1, -0x7970
    ctx->r3 = ADD32(ctx->r3, -0X7970);
    // 0x80009278: beq         $t9, $zero, L_80009330
    if (ctx->r25 == 0) {
        // 0x8000927C: lui         $a0, 0x800D
        ctx->r4 = S32(0X800D << 16);
            goto L_80009330;
    }
    // 0x8000927C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80009280: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80009284: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80009288: addiu       $t3, $t3, 0x762C
    ctx->r11 = ADD32(ctx->r11, 0X762C);
    // 0x8000928C: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x80009290: sh          $t0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r8;
    // 0x80009294: lhu         $t1, 0x0($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X0);
    // 0x80009298: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x8000929C: addiu       $v0, $v0, -0x7974
    ctx->r2 = ADD32(ctx->r2, -0X7974);
    // 0x800092A0: beq         $t1, $zero, L_800092CC
    if (ctx->r9 == 0) {
        // 0x800092A4: nop
    
            goto L_800092CC;
    }
    // 0x800092A4: nop

    // 0x800092A8: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    // 0x800092AC: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x800092B0: bgez        $t4, L_800092C0
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800092B4: sra         $t5, $t4, 4
        ctx->r13 = S32(SIGNED(ctx->r12) >> 4);
            goto L_800092C0;
    }
    // 0x800092B4: sra         $t5, $t4, 4
    ctx->r13 = S32(SIGNED(ctx->r12) >> 4);
    // 0x800092B8: addiu       $at, $t4, 0xF
    ctx->r1 = ADD32(ctx->r12, 0XF);
    // 0x800092BC: sra         $t5, $at, 4
    ctx->r13 = S32(SIGNED(ctx->r1) >> 4);
L_800092C0:
    // 0x800092C0: subu        $t6, $t2, $t5
    ctx->r14 = SUB32(ctx->r10, ctx->r13);
    // 0x800092C4: b           L_800092D8
    // 0x800092C8: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
        goto L_800092D8;
    // 0x800092C8: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
L_800092CC:
    // 0x800092CC: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x800092D0: addiu       $t7, $t7, -0x7974
    ctx->r15 = ADD32(ctx->r15, -0X7974);
    // 0x800092D4: sh          $zero, 0x0($t7)
    MEM_H(0X0, ctx->r15) = 0;
L_800092D8:
    // 0x800092D8: lui         $t8, 0x8007
    ctx->r24 = S32(0X8007 << 16);
    // 0x800092DC: addiu       $t8, $t8, -0x7974
    ctx->r24 = ADD32(ctx->r24, -0X7974);
    // 0x800092E0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800092E4: lw          $a0, 0x7610($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7610);
    // 0x800092E8: jal         0x800505D0
    // 0x800092EC: lh          $a1, 0x0($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X0);
    func_800505D0(rdram, ctx);
        goto after_33;
    // 0x800092EC: lh          $a1, 0x0($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X0);
    after_33:
    // 0x800092F0: lui         $t9, 0x8007
    ctx->r25 = S32(0X8007 << 16);
    // 0x800092F4: addiu       $t9, $t9, -0x7974
    ctx->r25 = ADD32(ctx->r25, -0X7974);
    // 0x800092F8: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x800092FC: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80009300: bne         $t0, $zero, L_80009378
    if (ctx->r8 != 0) {
        // 0x80009304: nop
    
            goto L_80009378;
    }
    // 0x80009304: nop

    // 0x80009308: jal         0x800535F0
    // 0x8000930C: lw          $a0, 0x7610($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7610);
    func_800535F0(rdram, ctx);
        goto after_34;
    // 0x8000930C: lw          $a0, 0x7610($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7610);
    after_34:
    // 0x80009310: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80009314: addiu       $t1, $t1, 0x762C
    ctx->r9 = ADD32(ctx->r9, 0X762C);
    // 0x80009318: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8000931C: lw          $a0, 0x7610($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7610);
    // 0x80009320: jal         0x800505D0
    // 0x80009324: lh          $a1, 0x0($t1)
    ctx->r5 = MEM_H(ctx->r9, 0X0);
    func_800505D0(rdram, ctx);
        goto after_35;
    // 0x80009324: lh          $a1, 0x0($t1)
    ctx->r5 = MEM_H(ctx->r9, 0X0);
    after_35:
    // 0x80009328: b           L_80009378
    // 0x8000932C: nop

        goto L_80009378;
    // 0x8000932C: nop

L_80009330:
    // 0x80009330: jal         0x80053620
    // 0x80009334: lw          $a0, 0x7610($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7610);
    func_80053620(rdram, ctx);
        goto after_36;
    // 0x80009334: lw          $a0, 0x7610($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7610);
    after_36:
    // 0x80009338: bne         $v0, $zero, L_80009378
    if (ctx->r2 != 0) {
        // 0x8000933C: lui         $t3, 0x8007
        ctx->r11 = S32(0X8007 << 16);
            goto L_80009378;
    }
    // 0x8000933C: lui         $t3, 0x8007
    ctx->r11 = S32(0X8007 << 16);
    // 0x80009340: addiu       $t3, $t3, -0x7958
    ctx->r11 = ADD32(ctx->r11, -0X7958);
    // 0x80009344: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80009348: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8000934C: addiu       $a0, $a0, -0x4A10
    ctx->r4 = ADD32(ctx->r4, -0X4A10);
    // 0x80009350: bne         $s3, $t4, L_8000936C
    if (ctx->r19 != ctx->r12) {
        // 0x80009354: addiu       $a1, $sp, 0x58
        ctx->r5 = ADD32(ctx->r29, 0X58);
            goto L_8000936C;
    }
    // 0x80009354: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x80009358: jal         0x800534A0
    // 0x8000935C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_37;
    // 0x8000935C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_37:
    // 0x80009360: lui         $t2, 0x8007
    ctx->r10 = S32(0X8007 << 16);
    // 0x80009364: addiu       $t2, $t2, -0x7958
    ctx->r10 = ADD32(ctx->r10, -0X7958);
    // 0x80009368: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
L_8000936C:
    // 0x8000936C: lui         $t5, 0x8007
    ctx->r13 = S32(0X8007 << 16);
    // 0x80009370: addiu       $t5, $t5, -0x7960
    ctx->r13 = ADD32(ctx->r13, -0X7960);
    // 0x80009374: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
L_80009378:
    // 0x80009378: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x8000937C: addiu       $t6, $t6, -0x7960
    ctx->r14 = ADD32(ctx->r14, -0X7960);
    // 0x80009380: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80009384: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80009388: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8000938C: bne         $t7, $at, L_800093D0
    if (ctx->r15 != ctx->r1) {
        // 0x80009390: nop
    
            goto L_800093D0;
    }
    // 0x80009390: nop

    // 0x80009394: jal         0x800535F0
    // 0x80009398: lw          $a0, 0x7610($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7610);
    func_800535F0(rdram, ctx);
        goto after_38;
    // 0x80009398: lw          $a0, 0x7610($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7610);
    after_38:
    // 0x8000939C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800093A0: addiu       $t8, $t8, 0x762C
    ctx->r24 = ADD32(ctx->r24, 0X762C);
    // 0x800093A4: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800093A8: lw          $a0, 0x7610($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7610);
    // 0x800093AC: jal         0x800505D0
    // 0x800093B0: lh          $a1, 0x0($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X0);
    func_800505D0(rdram, ctx);
        goto after_39;
    // 0x800093B0: lh          $a1, 0x0($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X0);
    after_39:
    // 0x800093B4: lui         $t9, 0x8007
    ctx->r25 = S32(0X8007 << 16);
    // 0x800093B8: addiu       $t9, $t9, -0x7970
    ctx->r25 = ADD32(ctx->r25, -0X7970);
    // 0x800093BC: lui         $t1, 0x8007
    ctx->r9 = S32(0X8007 << 16);
    // 0x800093C0: sh          $zero, 0x0($t9)
    MEM_H(0X0, ctx->r25) = 0;
    // 0x800093C4: addiu       $t1, $t1, -0x7960
    ctx->r9 = ADD32(ctx->r9, -0X7960);
    // 0x800093C8: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800093CC: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
L_800093D0:
    // 0x800093D0: lui         $t3, 0x8007
    ctx->r11 = S32(0X8007 << 16);
    // 0x800093D4: addiu       $t3, $t3, -0x7980
    ctx->r11 = ADD32(ctx->r11, -0X7980);
    // 0x800093D8: b           L_80009470
    // 0x800093DC: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
        goto L_80009470;
    // 0x800093DC: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
L_800093E0:
    // 0x800093E0: lui         $t4, 0x8007
    ctx->r12 = S32(0X8007 << 16);
    // 0x800093E4: addiu       $t4, $t4, -0x797C
    ctx->r12 = ADD32(ctx->r12, -0X797C);
    // 0x800093E8: sw          $s3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r19;
    // 0x800093EC: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800093F0: jal         0x800535F0
    // 0x800093F4: lw          $a0, 0x7610($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7610);
    func_800535F0(rdram, ctx);
        goto after_40;
    // 0x800093F4: lw          $a0, 0x7610($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7610);
    after_40:
    // 0x800093F8: lui         $t2, 0x8007
    ctx->r10 = S32(0X8007 << 16);
    // 0x800093FC: addiu       $t2, $t2, -0x795C
    ctx->r10 = ADD32(ctx->r10, -0X795C);
    // 0x80009400: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x80009404: beql        $t5, $zero, L_80009464
    if (ctx->r13 == 0) {
        // 0x80009408: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_80009464;
    }
    goto skip_6;
    // 0x80009408: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    skip_6:
    // 0x8000940C: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x80009410: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80009414: lh          $t7, 0xE($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XE);
    // 0x80009418: blezl       $t7, L_80009464
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8000941C: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_80009464;
    }
    goto skip_7;
    // 0x8000941C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    skip_7:
    // 0x80009420: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
L_80009424:
    // 0x80009424: sll         $t9, $s0, 1
    ctx->r25 = S32(ctx->r16 << 1);
    // 0x80009428: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8000942C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80009430: jal         0x80050640
    // 0x80009434: lh          $a1, 0x0($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X0);
    func_80050640(rdram, ctx);
        goto after_41;
    // 0x80009434: lh          $a1, 0x0($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X0);
    after_41:
    // 0x80009438: jal         0x80050660
    // 0x8000943C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_80050660(rdram, ctx);
        goto after_42;
    // 0x8000943C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_42:
    // 0x80009440: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x80009444: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80009448: sll         $t1, $s0, 16
    ctx->r9 = S32(ctx->r16 << 16);
    // 0x8000944C: lh          $t2, 0xE($t4)
    ctx->r10 = MEM_H(ctx->r12, 0XE);
    // 0x80009450: sra         $s0, $t1, 16
    ctx->r16 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80009454: slt         $at, $s0, $t2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80009458: bnel        $at, $zero, L_80009424
    if (ctx->r1 != 0) {
        // 0x8000945C: lw          $t8, 0x0($s5)
        ctx->r24 = MEM_W(ctx->r21, 0X0);
            goto L_80009424;
    }
    goto skip_8;
    // 0x8000945C: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    skip_8:
    // 0x80009460: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_80009464:
    // 0x80009464: sw          $t5, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r13;
    // 0x80009468: jal         0x80053630
    // 0x8000946C: andi        $a0, $s3, 0xFF
    ctx->r4 = ctx->r19 & 0XFF;
    osViBlack_recomp(rdram, ctx);
        goto after_43;
    // 0x8000946C: andi        $a0, $s3, 0xFF
    ctx->r4 = ctx->r19 & 0XFF;
    after_43:
L_80009470:
    // 0x80009470: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
L_80009474:
    // 0x80009474: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80009478: addiu       $a0, $a0, 0x7888
    ctx->r4 = ADD32(ctx->r4, 0X7888);
    // 0x8000947C: beq         $t6, $zero, L_80008EB8
    if (ctx->r14 == 0) {
        // 0x80009480: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80008EB8;
    }
    // 0x80009480: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80009484: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80009488: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000948C: jal         0x80052714
    // 0x80009490: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    func_80052714(rdram, ctx);
        goto after_44;
    // 0x80009490: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    after_44:
L_80009494:
    // 0x80009494: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80009498: addiu       $a0, $a0, 0x7818
    ctx->r4 = ADD32(ctx->r4, 0X7818);
    // 0x8000949C: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x800094A0: jal         0x8004F990
    // 0x800094A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_45;
    // 0x800094A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_45:
    // 0x800094A8: b           L_80009494
    // 0x800094AC: nop

        goto L_80009494;
    // 0x800094AC: nop

    // 0x800094B0: nop

    // 0x800094B4: nop

    // 0x800094B8: nop

    // 0x800094BC: nop

    // 0x800094C0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800094C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800094C8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800094CC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800094D0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800094D4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800094D8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800094DC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800094E0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800094E4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800094E8: jr          $ra
    // 0x800094EC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    TRACE_RETURN()
    return;
    // 0x800094EC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_800094F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800094F0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800094F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800094F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800094FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80009500: jal         0x800098AC
    // 0x80009504: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    func_800098AC(rdram, ctx);
        goto after_0;
    // 0x80009504: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_0:
    // 0x80009508: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x8000950C: beq         $a2, $zero, L_80009528
    if (ctx->r6 == 0) {
        // 0x80009510: nop
    
            goto L_80009528;
    }
    // 0x80009510: nop

    // 0x80009514: lh          $a1, 0x4($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X4);
    // 0x80009518: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x8000951C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80009520: jal         0x800536A0
    // 0x80009524: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    osAiSetNextBuffer_recomp(rdram, ctx);
        goto after_1;
    // 0x80009524: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_1:
L_80009528:
    // 0x80009528: jal         0x80053750
    // 0x8000952C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x8000952C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_2:
    // 0x80009530: jal         0x800537D0
    // 0x80009534: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    osAiGetLength_recomp(rdram, ctx);
        goto after_3;
    // 0x80009534: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_3:
    // 0x80009538: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8000953C: lw          $t7, -0x4214($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4214);
    // 0x80009540: srl         $t8, $v0, 2
    ctx->r24 = S32(U32(ctx->r2) >> 2);
    // 0x80009544: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80009548: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x8000954C: addiu       $t2, $t9, 0x50
    ctx->r10 = ADD32(ctx->r25, 0X50);
    // 0x80009550: andi        $t3, $t2, 0xFFF0
    ctx->r11 = ctx->r10 & 0XFFF0;
    // 0x80009554: addiu       $t4, $t3, 0x10
    ctx->r12 = ADD32(ctx->r11, 0X10);
    // 0x80009558: sh          $t4, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r12;
    // 0x8000955C: lw          $v1, -0x4218($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4218);
    // 0x80009560: lh          $a3, 0x4($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X4);
    // 0x80009564: lui         $t5, 0x8007
    ctx->r13 = S32(0X8007 << 16);
    // 0x80009568: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8000956C: sltu        $at, $a3, $v1
    ctx->r1 = ctx->r7 < ctx->r3 ? 1 : 0;
    // 0x80009570: beq         $at, $zero, L_80009580
    if (ctx->r1 == 0) {
        // 0x80009574: nop
    
            goto L_80009580;
    }
    // 0x80009574: nop

    // 0x80009578: sh          $v1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r3;
    // 0x8000957C: lh          $a3, 0x4($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X4);
L_80009580:
    // 0x80009580: lw          $t5, -0x794C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X794C);
    // 0x80009584: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80009588: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x8000958C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80009590: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x80009594: jal         0x80053928
    // 0x80009598: lw          $a0, 0x7650($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7650);
    func_80053928(rdram, ctx);
        goto after_4;
    // 0x80009598: lw          $a0, 0x7650($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7650);
    after_4:
    // 0x8000959C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800095A0: lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // 0x800095A4: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x800095A8: addiu       $t1, $t1, 0x7650
    ctx->r9 = ADD32(ctx->r9, 0X7650);
    // 0x800095AC: addiu       $v1, $v1, -0x794C
    ctx->r3 = ADD32(ctx->r3, -0X794C);
    // 0x800095B0: bne         $t7, $zero, L_800095C0
    if (ctx->r15 != 0) {
        // 0x800095B4: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800095C0;
    }
    // 0x800095B4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800095B8: b           L_800096A4
    // 0x800095BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800096A4;
    // 0x800095BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800095C0:
    // 0x800095C0: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800095C4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800095C8: addiu       $t8, $t8, 0x7850
    ctx->r24 = ADD32(ctx->r24, 0X7850);
    // 0x800095CC: addiu       $t9, $s0, 0x60
    ctx->r25 = ADD32(ctx->r16, 0X60);
    // 0x800095D0: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x800095D4: sw          $t8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r24;
    // 0x800095D8: sw          $t9, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r25;
    // 0x800095DC: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x800095E0: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x800095E4: lui         $t0, 0x8006
    ctx->r8 = S32(0X8006 << 16);
    // 0x800095E8: addiu       $t0, $t0, 0x2B80
    ctx->r8 = ADD32(ctx->r8, 0X2B80);
    // 0x800095EC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800095F0: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800095F4: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800095F8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800095FC: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    // 0x80009600: sw          $t5, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r13;
    // 0x80009604: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80009608: lui         $t5, 0x8006
    ctx->r13 = S32(0X8006 << 16);
    // 0x8000960C: addiu       $t5, $t5, 0x2C50
    ctx->r13 = ADD32(ctx->r13, 0X2C50);
    // 0x80009610: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80009614: addu        $t8, $t1, $t7
    ctx->r24 = ADD32(ctx->r9, ctx->r15);
    // 0x80009618: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8000961C: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x80009620: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80009624: subu        $t2, $a3, $t9
    ctx->r10 = SUB32(ctx->r7, ctx->r25);
    // 0x80009628: sra         $t3, $t2, 3
    ctx->r11 = S32(SIGNED(ctx->r10) >> 3);
    // 0x8000962C: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80009630: subu        $t6, $t5, $t0
    ctx->r14 = SUB32(ctx->r13, ctx->r8);
    // 0x80009634: addiu       $t7, $t7, 0x6390
    ctx->r15 = ADD32(ctx->r15, 0X6390);
    // 0x80009638: addiu       $t8, $t8, -0x4D10
    ctx->r24 = ADD32(ctx->r24, -0X4D10);
    // 0x8000963C: addiu       $t9, $zero, 0x1000
    ctx->r25 = ADD32(0, 0X1000);
    // 0x80009640: addiu       $t2, $zero, 0x800
    ctx->r10 = ADD32(0, 0X800);
    // 0x80009644: sw          $t4, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r12;
    // 0x80009648: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x8000964C: sw          $t0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r8;
    // 0x80009650: sw          $t6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r14;
    // 0x80009654: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x80009658: sw          $zero, 0x38($s0)
    MEM_W(0X38, ctx->r16) = 0;
    // 0x8000965C: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x80009660: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
    // 0x80009664: sw          $zero, 0x44($s0)
    MEM_W(0X44, ctx->r16) = 0;
    // 0x80009668: sw          $t7, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r15;
    // 0x8000966C: sw          $t8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r24;
    // 0x80009670: sw          $t9, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r25;
    // 0x80009674: sw          $t2, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r10;
    // 0x80009678: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
    // 0x8000967C: sw          $zero, 0x54($s0)
    MEM_W(0X54, ctx->r16) = 0;
    // 0x80009680: lw          $a0, 0x4928($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4928);
    // 0x80009684: jal         0x800534A0
    // 0x80009688: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x80009688: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x8000968C: lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // 0x80009690: addiu       $v1, $v1, -0x794C
    ctx->r3 = ADD32(ctx->r3, -0X794C);
    // 0x80009694: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x80009698: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000969C: xori        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 ^ 0X1;
    // 0x800096A0: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
L_800096A4:
    // 0x800096A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800096A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800096AC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800096B0: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800096B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800096B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800096BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800096C0: jal         0x800537D0
    // 0x800096C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    osAiGetLength_recomp(rdram, ctx);
        goto after_0;
    // 0x800096C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800096C8: srl         $t6, $v0, 2
    ctx->r14 = S32(U32(ctx->r2) >> 2);
    // 0x800096CC: bne         $t6, $zero, L_800096E8
    if (ctx->r14 != 0) {
        // 0x800096D0: lui         $t7, 0x8007
        ctx->r15 = S32(0X8007 << 16);
            goto L_800096E8;
    }
    // 0x800096D0: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x800096D4: lw          $t7, -0x6C4C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6C4C);
    // 0x800096D8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800096DC: bnel        $t7, $zero, L_800096EC
    if (ctx->r15 != 0) {
        // 0x800096E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800096EC;
    }
    goto skip_0;
    // 0x800096E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800096E4: sw          $zero, -0x6C4C($at)
    MEM_W(-0X6C4C, ctx->r1) = 0;
L_800096E8:
    // 0x800096E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800096EC:
    // 0x800096EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800096F0: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800096F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800096F8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800096FC: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80009700: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x80009704: addiu       $s1, $s1, -0x4728
    ctx->r17 = ADD32(ctx->r17, -0X4728);
    // 0x80009708: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8000970C: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x80009710: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80009714: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80009718: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8000971C: beq         $s0, $zero, L_80009774
    if (ctx->r16 == 0) {
        // 0x80009720: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80009774;
    }
    // 0x80009720: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80009724: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
L_80009728:
    // 0x80009728: addu        $t6, $a3, $a1
    ctx->r14 = ADD32(ctx->r7, ctx->r5);
    // 0x8000972C: sltu        $at, $a3, $v0
    ctx->r1 = ctx->r7 < ctx->r2 ? 1 : 0;
    // 0x80009730: bne         $at, $zero, L_80009774
    if (ctx->r1 != 0) {
        // 0x80009734: addiu       $v1, $v0, 0x400
        ctx->r3 = ADD32(ctx->r2, 0X400);
            goto L_80009774;
    }
    // 0x80009734: addiu       $v1, $v0, 0x400
    ctx->r3 = ADD32(ctx->r2, 0X400);
    // 0x80009738: slt         $at, $v1, $t6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8000973C: bne         $at, $zero, L_80009768
    if (ctx->r1 != 0) {
        // 0x80009740: or          $a2, $s0, $zero
        ctx->r6 = ctx->r16 | 0;
            goto L_80009768;
    }
    // 0x80009740: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80009744: lw          $t8, 0x10($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X10);
    // 0x80009748: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x8000974C: lw          $t7, -0x7954($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7954);
    // 0x80009750: addu        $t9, $t8, $a3
    ctx->r25 = ADD32(ctx->r24, ctx->r7);
    // 0x80009754: subu        $a0, $t9, $v0
    ctx->r4 = SUB32(ctx->r25, ctx->r2);
    // 0x80009758: jal         0x80053750
    // 0x8000975C: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x8000975C: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
    after_0:
    // 0x80009760: b           L_80009864
    // 0x80009764: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80009864;
    // 0x80009764: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80009768:
    // 0x80009768: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x8000976C: bnel        $s0, $zero, L_80009728
    if (ctx->r16 != 0) {
        // 0x80009770: lw          $v0, 0x8($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X8);
            goto L_80009728;
    }
    goto skip_0;
    // 0x80009770: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    skip_0:
L_80009774:
    // 0x80009774: lw          $s0, 0x8($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X8);
    // 0x80009778: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8000977C: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    // 0x80009780: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80009784: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80009788: jal         0x800526C0
    // 0x8000978C: sw          $t1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r9;
    func_800526C0(rdram, ctx);
        goto after_1;
    // 0x8000978C: sw          $t1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r9;
    after_1:
    // 0x80009790: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80009794: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x80009798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000979C: beq         $a2, $zero, L_800097B4
    if (ctx->r6 == 0) {
        // 0x800097A0: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_800097B4;
    }
    // 0x800097A0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800097A4: jal         0x800526F0
    // 0x800097A8: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    func_800526F0(rdram, ctx);
        goto after_2;
    // 0x800097A8: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    after_2:
    // 0x800097AC: b           L_800097E0
    // 0x800097B0: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
        goto L_800097E0;
    // 0x800097B0: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
L_800097B4:
    // 0x800097B4: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x800097B8: beql        $v0, $zero, L_800097D8
    if (ctx->r2 == 0) {
        // 0x800097BC: sw          $s0, 0x4($s1)
        MEM_W(0X4, ctx->r17) = ctx->r16;
            goto L_800097D8;
    }
    goto skip_1;
    // 0x800097BC: sw          $s0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r16;
    skip_1:
    // 0x800097C0: sw          $s0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r16;
    // 0x800097C4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800097C8: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800097CC: b           L_800097E0
    // 0x800097D0: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
        goto L_800097E0;
    // 0x800097D0: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
    // 0x800097D4: sw          $s0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r16;
L_800097D8:
    // 0x800097D8: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x800097DC: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
L_800097E0:
    // 0x800097E0: andi        $v0, $a3, 0x1
    ctx->r2 = ctx->r7 & 0X1;
    // 0x800097E4: lw          $s1, 0x10($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X10);
    // 0x800097E8: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x800097EC: subu        $a3, $a3, $v0
    ctx->r7 = SUB32(ctx->r7, ctx->r2);
    // 0x800097F0: sw          $a3, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r7;
    // 0x800097F4: lui         $t2, 0x8007
    ctx->r10 = S32(0X8007 << 16);
    // 0x800097F8: lw          $t2, -0x7954($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7954);
    // 0x800097FC: lui         $t0, 0x8007
    ctx->r8 = S32(0X8007 << 16);
    // 0x80009800: addiu       $t0, $t0, -0x7950
    ctx->r8 = ADD32(ctx->r8, -0X7950);
    // 0x80009804: sw          $t2, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r10;
    // 0x80009808: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8000980C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80009810: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80009814: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x80009818: subu        $t3, $t3, $v1
    ctx->r11 = SUB32(ctx->r11, ctx->r3);
    // 0x8000981C: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80009820: addiu       $t6, $t6, -0x3F08
    ctx->r14 = ADD32(ctx->r14, -0X3F08);
    // 0x80009824: addiu       $t4, $t4, -0x4208
    ctx->r12 = ADD32(ctx->r12, -0X4208);
    // 0x80009828: addiu       $t5, $zero, 0x400
    ctx->r13 = ADD32(0, 0X400);
    // 0x8000982C: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x80009830: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80009834: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80009838: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    // 0x8000983C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80009840: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80009844: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80009848: jal         0x80053EC0
    // 0x8000984C: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    osPiStartDma_recomp(rdram, ctx);
        goto after_3;
    // 0x8000984C: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_3:
    // 0x80009850: jal         0x80053750
    // 0x80009854: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_4;
    // 0x80009854: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80009858: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8000985C: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x80009860: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80009864:
    // 0x80009864: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80009868: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8000986C: jr          $ra
    // 0x80009870: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    TRACE_RETURN()
    return;
    // 0x80009870: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
