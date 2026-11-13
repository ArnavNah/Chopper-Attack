#include "recomp.h"
#include "trace.h"
#include "funcs.h"

RECOMP_FUNC void recomp_entrypoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80000400: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80000404: lui         $t1, 0xB
    ctx->r9 = S32(0XB << 16);
    // 0x80000408: addiu       $t0, $t0, -0x4A50
    ctx->r8 = ADD32(ctx->r8, -0X4A50);
    // 0x8000040C: ori         $t1, $t1, 0x3C50
    ctx->r9 = ctx->r9 | 0X3C50;
L_80000410:
    // 0x80000410: addi        $t1, $t1, -0x8
    ctx->r9 = ADD32(ctx->r9, -0X8);
    // 0x80000414: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x80000418: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8000041C: bne         $t1, $zero, L_80000410
    if (ctx->r9 != 0) {
        // 0x80000420: addi        $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
            goto L_80000410;
    }
    // 0x80000420: addi        $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80000424: lui         $t2, 0x8001
    ctx->r10 = S32(0X8001 << 16);
    // 0x80000428: lui         $sp, 0x800E
    ctx->r29 = S32(0X800E << 16);
    // 0x8000042C: addiu       $t2, $t2, -0x4070
    ctx->r10 = ADD32(ctx->r10, -0X4070);
    // 0x80000430: jr          $t2
    // 0x80000434: addiu       $sp, $sp, -0x1CA0
    ctx->r29 = ADD32(ctx->r29, -0X1CA0);
    LOOKUP_FUNC(ctx->r10)(rdram, ctx);
    TRACE_RETURN()
    return;
    // 0x80000434: addiu       $sp, $sp, -0x1CA0
    ctx->r29 = ADD32(ctx->r29, -0X1CA0);
;}
RECOMP_FUNC void func_80000450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80000450: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80000454: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80000458: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000045C: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x80000460: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80000464: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80000468: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000046C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80000470: sll         $s3, $a3, 10
    ctx->r19 = S32(ctx->r7 << 10);
    // 0x80000474: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x80000478: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000047C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80000480: sw          $a2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r6;
    // 0x80000484: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80000488: jal         0x80004364
    // 0x8000048C: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x8000048C: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    after_0:
    // 0x80000490: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80000494: sll         $v1, $s2, 2
    ctx->r3 = S32(ctx->r18 << 2);
    // 0x80000498: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8000049C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800004A0: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x800004A4: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x800004A8: jal         0x80004364
    // 0x800004AC: sw          $v0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r2;
    func_80004364(rdram, ctx);
        goto after_1;
    // 0x800004AC: sw          $v0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r2;
    after_1:
    // 0x800004B0: sra         $a2, $s3, 2
    ctx->r6 = S32(SIGNED(ctx->r19) >> 2);
    // 0x800004B4: lw          $t2, 0x90($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X90);
    // 0x800004B8: lw          $ra, 0x80($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X80);
    // 0x800004BC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800004C0: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x800004C4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800004C8: beq         $a2, $zero, L_80000510
    if (ctx->r6 == 0) {
        // 0x800004CC: or          $v1, $s4, $zero
        ctx->r3 = ctx->r20 | 0;
            goto L_80000510;
    }
    // 0x800004CC: or          $v1, $s4, $zero
    ctx->r3 = ctx->r20 | 0;
    // 0x800004D0: andi        $a3, $a2, 0x3
    ctx->r7 = ctx->r6 & 0X3;
    // 0x800004D4: negu        $a3, $a3
    ctx->r7 = SUB32(0, ctx->r7);
    // 0x800004D8: beq         $a3, $zero, L_800004F4
    if (ctx->r7 == 0) {
        // 0x800004DC: addu        $a1, $a3, $a2
        ctx->r5 = ADD32(ctx->r7, ctx->r6);
            goto L_800004F4;
    }
    // 0x800004DC: addu        $a1, $a3, $a2
    ctx->r5 = ADD32(ctx->r7, ctx->r6);
L_800004E0:
    // 0x800004E0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800004E4: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800004E8: bne         $a1, $a0, L_800004E0
    if (ctx->r5 != ctx->r4) {
        // 0x800004EC: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800004E0;
    }
    // 0x800004EC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800004F0: beq         $a0, $zero, L_80000510
    if (ctx->r4 == 0) {
        // 0x800004F4: addiu       $a0, $a0, -0x4
        ctx->r4 = ADD32(ctx->r4, -0X4);
            goto L_80000510;
    }
L_800004F4:
    // 0x800004F4: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x800004F8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800004FC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80000500: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x80000504: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x80000508: bne         $a0, $zero, L_800004F4
    if (ctx->r4 != 0) {
        // 0x8000050C: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800004F4;
    }
    // 0x8000050C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_80000510:
    // 0x80000510: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
    // 0x80000514: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80000518: blez        $s2, L_80000608
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8000051C: or          $s3, $a1, $zero
        ctx->r19 = ctx->r5 | 0;
            goto L_80000608;
    }
    // 0x8000051C: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80000520: sll         $t6, $s2, 2
    ctx->r14 = S32(ctx->r18 << 2);
    // 0x80000524: addu        $t1, $t6, $a1
    ctx->r9 = ADD32(ctx->r14, ctx->r5);
    // 0x80000528: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x8000052C: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
L_80000530:
    // 0x80000530: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80000534: blez        $s1, L_800005F8
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80000538: addu        $a0, $t7, $t2
        ctx->r4 = ADD32(ctx->r15, ctx->r10);
            goto L_800005F8;
    }
    // 0x80000538: addu        $a0, $t7, $t2
    ctx->r4 = ADD32(ctx->r15, ctx->r10);
    // 0x8000053C: andi        $v1, $s1, 0x3
    ctx->r3 = ctx->r17 & 0X3;
    // 0x80000540: beq         $v1, $zero, L_8000057C
    if (ctx->r3 == 0) {
        // 0x80000544: or          $a3, $v1, $zero
        ctx->r7 = ctx->r3 | 0;
            goto L_8000057C;
    }
    // 0x80000544: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x80000548: sll         $t8, $zero, 10
    ctx->r24 = S32(0 << 10);
    // 0x8000054C: addu        $a1, $s4, $t8
    ctx->r5 = ADD32(ctx->r20, ctx->r24);
L_80000550:
    // 0x80000550: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x80000554: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80000558: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8000055C: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80000560: addu        $v1, $a1, $t6
    ctx->r3 = ADD32(ctx->r5, ctx->r14);
    // 0x80000564: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80000568: addiu       $a1, $a1, 0x400
    ctx->r5 = ADD32(ctx->r5, 0X400);
    // 0x8000056C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80000570: bne         $a3, $a2, L_80000550
    if (ctx->r7 != ctx->r6) {
        // 0x80000574: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_80000550;
    }
    // 0x80000574: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80000578: beq         $a2, $s1, L_800005F4
    if (ctx->r6 == ctx->r17) {
        // 0x8000057C: sll         $t9, $a2, 10
        ctx->r25 = S32(ctx->r6 << 10);
            goto L_800005F4;
    }
L_8000057C:
    // 0x8000057C: sll         $t9, $a2, 10
    ctx->r25 = S32(ctx->r6 << 10);
    // 0x80000580: addu        $a1, $s4, $t9
    ctx->r5 = ADD32(ctx->r20, ctx->r25);
L_80000584:
    // 0x80000584: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80000588: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8000058C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80000590: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80000594: addu        $v1, $a1, $t7
    ctx->r3 = ADD32(ctx->r5, ctx->r15);
    // 0x80000598: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8000059C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800005A0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800005A4: lbu         $t6, -0x3($a0)
    ctx->r14 = MEM_BU(ctx->r4, -0X3);
    // 0x800005A8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800005AC: addu        $v1, $a1, $t7
    ctx->r3 = ADD32(ctx->r5, ctx->r15);
    // 0x800005B0: lw          $t8, 0x400($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X400);
    // 0x800005B4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800005B8: sw          $t9, 0x400($v1)
    MEM_W(0X400, ctx->r3) = ctx->r25;
    // 0x800005BC: lbu         $t6, -0x2($a0)
    ctx->r14 = MEM_BU(ctx->r4, -0X2);
    // 0x800005C0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800005C4: addu        $v1, $a1, $t7
    ctx->r3 = ADD32(ctx->r5, ctx->r15);
    // 0x800005C8: lw          $t8, 0x800($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X800);
    // 0x800005CC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800005D0: sw          $t9, 0x800($v1)
    MEM_W(0X800, ctx->r3) = ctx->r25;
    // 0x800005D4: lbu         $t6, -0x1($a0)
    ctx->r14 = MEM_BU(ctx->r4, -0X1);
    // 0x800005D8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800005DC: addu        $v1, $a1, $t7
    ctx->r3 = ADD32(ctx->r5, ctx->r15);
    // 0x800005E0: lw          $t8, 0xC00($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC00);
    // 0x800005E4: addiu       $a1, $a1, 0x1000
    ctx->r5 = ADD32(ctx->r5, 0X1000);
    // 0x800005E8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800005EC: bne         $a2, $s1, L_80000584
    if (ctx->r6 != ctx->r17) {
        // 0x800005F0: sw          $t9, 0xC00($v1)
        MEM_W(0XC00, ctx->r3) = ctx->r25;
            goto L_80000584;
    }
    // 0x800005F0: sw          $t9, 0xC00($v1)
    MEM_W(0XC00, ctx->r3) = ctx->r25;
L_800005F4:
    // 0x800005F4: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
L_800005F8:
    // 0x800005F8: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800005FC: bnel        $t0, $t1, L_80000530
    if (ctx->r8 != ctx->r9) {
        // 0x80000600: lw          $t7, 0x0($t0)
        ctx->r15 = MEM_W(ctx->r8, 0X0);
            goto L_80000530;
    }
    goto skip_0;
    // 0x80000600: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    skip_0:
    // 0x80000604: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
L_80000608:
    // 0x80000608: blez        $s1, L_8000069C
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8000060C: lw          $t0, 0x98($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X98);
            goto L_8000069C;
    }
    // 0x8000060C: lw          $t0, 0x98($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X98);
    // 0x80000610: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
L_80000614:
    // 0x80000614: bne         $t0, $zero, L_8000066C
    if (ctx->r8 != 0) {
        // 0x80000618: addiu       $t5, $t5, 0x1
        ctx->r13 = ADD32(ctx->r13, 0X1);
            goto L_8000066C;
    }
    // 0x80000618: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x8000061C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80000620: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80000624: or          $a0, $ra, $zero
    ctx->r4 = ctx->r31 | 0;
L_80000628:
    // 0x80000628: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8000062C: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x80000630: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80000634: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80000638: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    // 0x8000063C: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x80000640: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80000644: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80000648: lw          $a1, -0x8($a0)
    ctx->r5 = MEM_W(ctx->r4, -0X8);
    // 0x8000064C: sw          $v1, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = ctx->r3;
    // 0x80000650: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80000654: lw          $a1, -0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, -0X4);
    // 0x80000658: sw          $v1, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->r3;
    // 0x8000065C: bne         $a2, $a3, L_80000628
    if (ctx->r6 != ctx->r7) {
        // 0x80000660: addu        $v1, $v1, $a1
        ctx->r3 = ADD32(ctx->r3, ctx->r5);
            goto L_80000628;
    }
    // 0x80000660: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80000664: b           L_80000690
    // 0x80000668: nop

        goto L_80000690;
    // 0x80000668: nop

L_8000066C:
    // 0x8000066C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80000670: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80000674: addiu       $a0, $ra, 0x3FC
    ctx->r4 = ADD32(ctx->r31, 0X3FC);
L_80000678:
    // 0x80000678: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8000067C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80000680: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x80000684: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x80000688: bgez        $a2, L_80000678
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8000068C: addu        $v1, $v1, $a1
        ctx->r3 = ADD32(ctx->r3, ctx->r5);
            goto L_80000678;
    }
    // 0x8000068C: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
L_80000690:
    // 0x80000690: bne         $t5, $s1, L_80000614
    if (ctx->r13 != ctx->r17) {
        // 0x80000694: addiu       $ra, $ra, 0x400
        ctx->r31 = ADD32(ctx->r31, 0X400);
            goto L_80000614;
    }
    // 0x80000694: addiu       $ra, $ra, 0x400
    ctx->r31 = ADD32(ctx->r31, 0X400);
    // 0x80000698: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
L_8000069C:
    // 0x8000069C: addu        $v1, $t2, $s1
    ctx->r3 = ADD32(ctx->r10, ctx->r17);
    // 0x800006A0: addiu       $t5, $v1, -0x1
    ctx->r13 = ADD32(ctx->r3, -0X1);
    // 0x800006A4: slt         $at, $t5, $t2
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800006A8: bne         $at, $zero, L_80000860
    if (ctx->r1 != 0) {
        // 0x800006AC: addiu       $s1, $t2, -0x1
        ctx->r17 = ADD32(ctx->r10, -0X1);
            goto L_80000860;
    }
    // 0x800006AC: addiu       $s1, $t2, -0x1
    ctx->r17 = ADD32(ctx->r10, -0X1);
L_800006B0:
    // 0x800006B0: addiu       $ra, $ra, -0x400
    ctx->r31 = ADD32(ctx->r31, -0X400);
    // 0x800006B4: blez        $s2, L_80000848
    if (SIGNED(ctx->r18) <= 0) {
        // 0x800006B8: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80000848;
    }
    // 0x800006B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800006BC: andi        $a0, $s2, 0x3
    ctx->r4 = ctx->r18 & 0X3;
    // 0x800006C0: beq         $a0, $zero, L_80000724
    if (ctx->r4 == 0) {
        // 0x800006C4: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80000724;
    }
    // 0x800006C4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800006C8: sll         $t6, $zero, 2
    ctx->r14 = S32(0 << 2);
    // 0x800006CC: addu        $v1, $s3, $t6
    ctx->r3 = ADD32(ctx->r19, ctx->r14);
L_800006D0:
    // 0x800006D0: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800006D4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800006D8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800006DC: addu        $t7, $a0, $t5
    ctx->r15 = ADD32(ctx->r4, ctx->r13);
    // 0x800006E0: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800006E4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800006E8: addu        $t6, $ra, $t9
    ctx->r14 = ADD32(ctx->r31, ctx->r25);
    // 0x800006EC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800006F0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800006F4: addu        $t9, $s0, $t8
    ctx->r25 = ADD32(ctx->r16, ctx->r24);
    // 0x800006F8: sw          $a0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r4;
    // 0x800006FC: lw          $t6, -0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, -0X4);
    // 0x80000700: addu        $t7, $t6, $t5
    ctx->r15 = ADD32(ctx->r14, ctx->r13);
    // 0x80000704: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80000708: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8000070C: addu        $a1, $ra, $t9
    ctx->r5 = ADD32(ctx->r31, ctx->r25);
    // 0x80000710: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80000714: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80000718: bne         $a3, $a2, L_800006D0
    if (ctx->r7 != ctx->r6) {
        // 0x8000071C: sw          $t7, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r15;
            goto L_800006D0;
    }
    // 0x8000071C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80000720: beq         $a2, $s2, L_80000848
    if (ctx->r6 == ctx->r18) {
        // 0x80000724: sll         $t8, $a2, 2
        ctx->r24 = S32(ctx->r6 << 2);
            goto L_80000848;
    }
L_80000724:
    // 0x80000724: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80000728: addu        $v1, $s3, $t8
    ctx->r3 = ADD32(ctx->r19, ctx->r24);
L_8000072C:
    // 0x8000072C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80000730: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80000734: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80000738: addu        $t9, $a0, $t5
    ctx->r25 = ADD32(ctx->r4, ctx->r13);
    // 0x8000073C: lbu         $t6, 0x0($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X0);
    // 0x80000740: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80000744: addu        $t8, $ra, $t7
    ctx->r24 = ADD32(ctx->r31, ctx->r15);
    // 0x80000748: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8000074C: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80000750: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x80000754: sw          $a0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r4;
    // 0x80000758: lw          $t8, -0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, -0X10);
    // 0x8000075C: addu        $t9, $t8, $t5
    ctx->r25 = ADD32(ctx->r24, ctx->r13);
    // 0x80000760: lbu         $t6, 0x0($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X0);
    // 0x80000764: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80000768: addu        $a1, $ra, $t7
    ctx->r5 = ADD32(ctx->r31, ctx->r15);
    // 0x8000076C: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80000770: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80000774: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80000778: lw          $a3, -0xC($v1)
    ctx->r7 = MEM_W(ctx->r3, -0XC);
    // 0x8000077C: addu        $t6, $a3, $t5
    ctx->r14 = ADD32(ctx->r7, ctx->r13);
    // 0x80000780: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80000784: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80000788: addu        $t9, $ra, $t8
    ctx->r25 = ADD32(ctx->r31, ctx->r24);
    // 0x8000078C: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x80000790: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80000794: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x80000798: sw          $a3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r7;
    // 0x8000079C: lw          $t9, -0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, -0XC);
    // 0x800007A0: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x800007A4: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800007A8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800007AC: addu        $t0, $ra, $t8
    ctx->r8 = ADD32(ctx->r31, ctx->r24);
    // 0x800007B0: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800007B4: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800007B8: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800007BC: lw          $t1, -0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, -0X8);
    // 0x800007C0: addu        $t7, $t1, $t5
    ctx->r15 = ADD32(ctx->r9, ctx->r13);
    // 0x800007C4: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800007C8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800007CC: addu        $t6, $ra, $t9
    ctx->r14 = ADD32(ctx->r31, ctx->r25);
    // 0x800007D0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800007D4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800007D8: addu        $t9, $s0, $t8
    ctx->r25 = ADD32(ctx->r16, ctx->r24);
    // 0x800007DC: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
    // 0x800007E0: lw          $t6, -0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, -0X8);
    // 0x800007E4: addu        $t7, $t6, $t5
    ctx->r15 = ADD32(ctx->r14, ctx->r13);
    // 0x800007E8: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800007EC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800007F0: addu        $t2, $ra, $t9
    ctx->r10 = ADD32(ctx->r31, ctx->r25);
    // 0x800007F4: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x800007F8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800007FC: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x80000800: lw          $t3, -0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, -0X4);
    // 0x80000804: addu        $t8, $t3, $t5
    ctx->r24 = ADD32(ctx->r11, ctx->r13);
    // 0x80000808: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8000080C: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80000810: addu        $t7, $ra, $t6
    ctx->r15 = ADD32(ctx->r31, ctx->r14);
    // 0x80000814: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80000818: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8000081C: addu        $t6, $s0, $t9
    ctx->r14 = ADD32(ctx->r16, ctx->r25);
    // 0x80000820: sw          $t3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r11;
    // 0x80000824: lw          $t7, -0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, -0X4);
    // 0x80000828: addu        $t8, $t7, $t5
    ctx->r24 = ADD32(ctx->r15, ctx->r13);
    // 0x8000082C: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x80000830: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80000834: addu        $t4, $ra, $t6
    ctx->r12 = ADD32(ctx->r31, ctx->r14);
    // 0x80000838: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x8000083C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80000840: bne         $a2, $s2, L_8000072C
    if (ctx->r6 != ctx->r18) {
        // 0x80000844: sw          $t8, 0x0($t4)
        MEM_W(0X0, ctx->r12) = ctx->r24;
            goto L_8000072C;
    }
    // 0x80000844: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
L_80000848:
    // 0x80000848: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
    // 0x8000084C: addiu       $t5, $t5, -0x1
    ctx->r13 = ADD32(ctx->r13, -0X1);
    // 0x80000850: or          $s3, $s0, $zero
    ctx->r19 = ctx->r16 | 0;
    // 0x80000854: bne         $t5, $s1, L_800006B0
    if (ctx->r13 != ctx->r17) {
        // 0x80000858: or          $s0, $v1, $zero
        ctx->r16 = ctx->r3 | 0;
            goto L_800006B0;
    }
    // 0x80000858: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x8000085C: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
L_80000860:
    // 0x80000860: beq         $s3, $a1, L_8000088C
    if (ctx->r19 == ctx->r5) {
        // 0x80000864: lw          $v1, 0x34($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X34);
            goto L_8000088C;
    }
    // 0x80000864: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80000868: beq         $v1, $zero, L_8000088C
    if (ctx->r3 == 0) {
        // 0x8000086C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8000088C;
    }
    // 0x8000086C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80000870: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
L_80000874:
    // 0x80000874: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80000878: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8000087C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80000880: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80000884: bgtz        $v1, L_80000874
    if (SIGNED(ctx->r3) > 0) {
        // 0x80000888: sw          $t9, -0x4($a1)
        MEM_W(-0X4, ctx->r5) = ctx->r25;
            goto L_80000874;
    }
    // 0x80000888: sw          $t9, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r25;
L_8000088C:
    // 0x8000088C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80000890: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80000894: jal         0x800042A8
    // 0x80000898: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    func_800042A8(rdram, ctx);
        goto after_2;
    // 0x80000898: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    after_2:
    // 0x8000089C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800008A0: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x800008A4: jal         0x800042A8
    // 0x800008A8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800042A8(rdram, ctx);
        goto after_3;
    // 0x800008A8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_3:
    // 0x800008AC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800008B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800008B4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800008B8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800008BC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800008C0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800008C4: jr          $ra
    // 0x800008C8: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    TRACE_RETURN()
    return;
    // 0x800008C8: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_800008CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800008CC: multu       $a1, $a2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800008D0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800008D4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800008D8: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x800008DC: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800008E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800008E4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800008E8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800008EC: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800008F0: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x800008F4: mflo        $t0
    ctx->r8 = lo;
    // 0x800008F8: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x800008FC: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x80000900: jal         0x80004364
    // 0x80000904: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x80000904: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    after_0:
    // 0x80000908: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8000090C: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80000910: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80000914: sll         $a1, $s1, 2
    ctx->r5 = S32(ctx->r17 << 2);
    // 0x80000918: jal         0x80004364
    // 0x8000091C: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    func_80004364(rdram, ctx);
        goto after_1;
    // 0x8000091C: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    after_1:
    // 0x80000920: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80000924: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x80000928: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000092C: beq         $a1, $zero, L_80000954
    if (ctx->r5 == 0) {
        // 0x80000930: sw          $v0, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r2;
            goto L_80000954;
    }
    // 0x80000930: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x80000934: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x80000938: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
L_8000093C:
    // 0x8000093C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80000940: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x80000944: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80000948: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8000094C: bgtz        $a1, L_8000093C
    if (SIGNED(ctx->r5) > 0) {
        // 0x80000950: sw          $t6, -0x4($a2)
        MEM_W(-0X4, ctx->r6) = ctx->r14;
            goto L_8000093C;
    }
    // 0x80000950: sw          $t6, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->r14;
L_80000954:
    // 0x80000954: blez        $s1, L_800009B0
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80000958: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800009B0;
    }
    // 0x80000958: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000095C: andi        $a2, $s1, 0x3
    ctx->r6 = ctx->r17 & 0X3;
    // 0x80000960: beq         $a2, $zero, L_80000984
    if (ctx->r6 == 0) {
        // 0x80000964: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_80000984;
    }
    // 0x80000964: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
L_80000968:
    // 0x80000968: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x8000096C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80000970: addu        $v1, $v1, $s0
    ctx->r3 = ADD32(ctx->r3, ctx->r16);
    // 0x80000974: bne         $a1, $v0, L_80000968
    if (ctx->r5 != ctx->r2) {
        // 0x80000978: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80000968;
    }
    // 0x80000978: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8000097C: beq         $v0, $s1, L_800009B0
    if (ctx->r2 == ctx->r17) {
        // 0x80000980: nop
    
            goto L_800009B0;
    }
    // 0x80000980: nop

L_80000984:
    // 0x80000984: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x80000988: addu        $v1, $v1, $s0
    ctx->r3 = ADD32(ctx->r3, ctx->r16);
    // 0x8000098C: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x80000990: addu        $v1, $v1, $s0
    ctx->r3 = ADD32(ctx->r3, ctx->r16);
    // 0x80000994: sw          $v1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r3;
    // 0x80000998: addu        $v1, $v1, $s0
    ctx->r3 = ADD32(ctx->r3, ctx->r16);
    // 0x8000099C: sw          $v1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r3;
    // 0x800009A0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800009A4: addu        $v1, $v1, $s0
    ctx->r3 = ADD32(ctx->r3, ctx->r16);
    // 0x800009A8: bne         $v0, $s1, L_80000984
    if (ctx->r2 != ctx->r17) {
        // 0x800009AC: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_80000984;
    }
    // 0x800009AC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
L_800009B0:
    // 0x800009B0: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x800009B4: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x800009B8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800009BC: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    // 0x800009C0: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    // 0x800009C4: jal         0x80000450
    // 0x800009C8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_80000450(rdram, ctx);
        goto after_2;
    // 0x800009C8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_2:
    // 0x800009CC: andi        $t8, $s0, 0x3
    ctx->r24 = ctx->r16 & 0X3;
    // 0x800009D0: beq         $t8, $zero, L_80000A68
    if (ctx->r24 == 0) {
        // 0x800009D4: nop
    
            goto L_80000A68;
    }
    // 0x800009D4: nop

    // 0x800009D8: blez        $s1, L_80000AB0
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800009DC: lw          $v0, 0x68($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X68);
            goto L_80000AB0;
    }
    // 0x800009DC: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x800009E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800009E4: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x800009E8: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
L_800009EC:
    // 0x800009EC: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x800009F0: blez        $s0, L_80000A54
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800009F4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80000A54;
    }
    // 0x800009F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800009F8: andi        $a2, $s0, 0x3
    ctx->r6 = ctx->r16 & 0X3;
    // 0x800009FC: beq         $a2, $zero, L_80000A24
    if (ctx->r6 == 0) {
        // 0x80000A00: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_80000A24;
    }
    // 0x80000A00: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
L_80000A04:
    // 0x80000A04: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x80000A08: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80000A0C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80000A10: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80000A14: bne         $a1, $a0, L_80000A04
    if (ctx->r5 != ctx->r4) {
        // 0x80000A18: sb          $t9, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = ctx->r25;
            goto L_80000A04;
    }
    // 0x80000A18: sb          $t9, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r25;
    // 0x80000A1C: beql        $a0, $s0, L_80000A58
    if (ctx->r4 == ctx->r16) {
        // 0x80000A20: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80000A58;
    }
    goto skip_0;
    // 0x80000A20: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    skip_0:
L_80000A24:
    // 0x80000A24: lbu         $t2, 0x0($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X0);
    // 0x80000A28: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80000A2C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80000A30: sb          $t2, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = ctx->r10;
    // 0x80000A34: lbu         $t3, 0x1($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X1);
    // 0x80000A38: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80000A3C: sb          $t3, -0x3($v0)
    MEM_B(-0X3, ctx->r2) = ctx->r11;
    // 0x80000A40: lbu         $t4, -0x2($v1)
    ctx->r12 = MEM_BU(ctx->r3, -0X2);
    // 0x80000A44: sb          $t4, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = ctx->r12;
    // 0x80000A48: lbu         $t5, -0x1($v1)
    ctx->r13 = MEM_BU(ctx->r3, -0X1);
    // 0x80000A4C: bne         $a0, $s0, L_80000A24
    if (ctx->r4 != ctx->r16) {
        // 0x80000A50: sb          $t5, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = ctx->r13;
            goto L_80000A24;
    }
    // 0x80000A50: sb          $t5, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r13;
L_80000A54:
    // 0x80000A54: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
L_80000A58:
    // 0x80000A58: bne         $a3, $t1, L_800009EC
    if (ctx->r7 != ctx->r9) {
        // 0x80000A5C: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_800009EC;
    }
    // 0x80000A5C: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80000A60: b           L_80000AB0
    // 0x80000A64: nop

        goto L_80000AB0;
    // 0x80000A64: nop

L_80000A68:
    // 0x80000A68: blez        $s1, L_80000AB0
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80000A6C: lw          $v1, 0x68($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X68);
            goto L_80000AB0;
    }
    // 0x80000A6C: lw          $v1, 0x68($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X68);
    // 0x80000A70: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80000A74: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x80000A78: sll         $a1, $s1, 2
    ctx->r5 = S32(ctx->r17 << 2);
L_80000A7C:
    // 0x80000A7C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80000A80: blez        $s0, L_80000AA4
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80000A84: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80000AA4;
    }
    // 0x80000A84: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80000A88:
    // 0x80000A88: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80000A8C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80000A90: slt         $at, $a0, $s0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80000A94: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80000A98: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80000A9C: bne         $at, $zero, L_80000A88
    if (ctx->r1 != 0) {
        // 0x80000AA0: sw          $t6, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r14;
            goto L_80000A88;
    }
    // 0x80000AA0: sw          $t6, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r14;
L_80000AA4:
    // 0x80000AA4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80000AA8: bne         $a3, $a1, L_80000A7C
    if (ctx->r7 != ctx->r5) {
        // 0x80000AAC: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_80000A7C;
    }
    // 0x80000AAC: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
L_80000AB0:
    // 0x80000AB0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80000AB4: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80000AB8: jal         0x800042A8
    // 0x80000ABC: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    func_800042A8(rdram, ctx);
        goto after_3;
    // 0x80000ABC: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    after_3:
    // 0x80000AC0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80000AC4: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80000AC8: jal         0x800042A8
    // 0x80000ACC: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    func_800042A8(rdram, ctx);
        goto after_4;
    // 0x80000ACC: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_4:
    // 0x80000AD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80000AD4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80000AD8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80000ADC: jr          $ra
    // 0x80000AE0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    TRACE_RETURN()
    return;
    // 0x80000AE0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80000AE4: nop

    // 0x80000AE8: nop

    // 0x80000AEC: nop

    // 0x80000AF0: or          $t1, $a2, $zero
    ctx->r9 = ctx->r6 | 0;
    // 0x80000AF4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80000AF8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80000AFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80000B00: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80000B04: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
L_80000B08:
    // 0x80000B08: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80000B0C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80000B10: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x80000B14: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80000B18: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80000B1C: beq         $v1, $a2, L_80000B7C
    if (ctx->r3 == ctx->r6) {
        // 0x80000B20: lwc1        $f16, 0x0($a1)
        ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
            goto L_80000B7C;
    }
    // 0x80000B20: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
L_80000B24:
    // 0x80000B24: mul.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80000B28: lwc1        $f12, 0x4($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80000B2C: lwc1        $f10, 0x10($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80000B30: lwc1        $f8, 0x8($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80000B34: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x80000B38: mul.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x80000B3C: lwc1        $f12, 0xC($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80000B40: add.s       $f14, $f2, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x80000B44: mul.s       $f6, $f8, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80000B48: lwc1        $f8, 0x30($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X30);
    // 0x80000B4C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80000B50: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80000B54: mul.s       $f8, $f12, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x80000B58: add.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x80000B5C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80000B60: add.s       $f6, $f10, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80000B64: add.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80000B68: swc1        $f8, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f8.u32l;
    // 0x80000B6C: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80000B70: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80000B74: bne         $v1, $a2, L_80000B24
    if (ctx->r3 != ctx->r6) {
        // 0x80000B78: nop
    
            goto L_80000B24;
    }
    // 0x80000B78: nop

L_80000B7C:
    // 0x80000B7C: mul.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80000B80: lwc1        $f12, 0x4($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80000B84: lwc1        $f10, 0x10($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80000B88: lwc1        $f8, 0x8($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80000B8C: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x80000B90: mul.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x80000B94: lwc1        $f12, 0xC($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80000B98: add.s       $f14, $f2, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x80000B9C: mul.s       $f6, $f8, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80000BA0: lwc1        $f8, 0x30($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X30);
    // 0x80000BA4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80000BA8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80000BAC: mul.s       $f8, $f12, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x80000BB0: add.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x80000BB4: add.s       $f6, $f10, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80000BB8: add.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80000BBC: swc1        $f8, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f8.u32l;
    // 0x80000BC0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80000BC4: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x80000BC8: bne         $v0, $a2, L_80000B08
    if (ctx->r2 != ctx->r6) {
        // 0x80000BCC: addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
            goto L_80000B08;
    }
    // 0x80000BCC: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x80000BD0: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80000BD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80000BD8: beq         $a0, $a2, L_80000CB0
    if (ctx->r4 == ctx->r6) {
        // 0x80000BDC: addiu       $sp, $sp, -0x60
        ctx->r29 = ADD32(ctx->r29, -0X60);
            goto L_80000CB0;
    }
    // 0x80000BDC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80000BE0: beq         $a0, $a1, L_80000CB0
    if (ctx->r4 == ctx->r5) {
        // 0x80000BE4: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80000CB0;
    }
    // 0x80000BE4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80000BE8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80000BEC: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x80000BF0: addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // 0x80000BF4: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
L_80000BF8:
    // 0x80000BF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80000BFC: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80000C00: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
L_80000C04:
    // 0x80000C04: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80000C08: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80000C0C: lwc1        $f14, 0x4($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80000C10: lwc1        $f12, 0x10($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80000C14: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80000C18: lwc1        $f18, 0x8($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80000C1C: lwc1        $f10, 0x20($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X20);
    // 0x80000C20: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80000C24: lwc1        $f14, 0x30($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X30);
    // 0x80000C28: lwc1        $f8, 0xC($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80000C2C: mul.s       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80000C30: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80000C34: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80000C38: mul.s       $f8, $f14, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x80000C3C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80000C40: add.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x80000C44: add.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x80000C48: add.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80000C4C: swc1        $f10, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = ctx->f10.u32l;
    // 0x80000C50: lwc1        $f10, 0x0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80000C54: lwc1        $f8, -0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, -0X4);
    // 0x80000C58: lwc1        $f12, 0x4($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80000C5C: lwc1        $f16, 0xC($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80000C60: mul.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80000C64: lwc1        $f10, 0x8($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80000C68: lwc1        $f14, 0x1C($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80000C6C: mul.s       $f16, $f12, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x80000C70: lwc1        $f12, 0x2C($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80000C74: lwc1        $f18, 0xC($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80000C78: mul.s       $f14, $f10, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80000C7C: nop

    // 0x80000C80: mul.s       $f18, $f12, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x80000C84: add.s       $f16, $f8, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80000C88: add.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f14.fl;
    // 0x80000C8C: add.s       $f14, $f18, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f14.fl;
    // 0x80000C90: bne         $v0, $t1, L_80000C04
    if (ctx->r2 != ctx->r9) {
        // 0x80000C94: swc1        $f14, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = ctx->f14.u32l;
            goto L_80000C04;
    }
    // 0x80000C94: swc1        $f14, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f14.u32l;
    // 0x80000C98: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x80000C9C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80000CA0: bne         $a3, $t2, L_80000BF8
    if (ctx->r7 != ctx->r10) {
        // 0x80000CA4: addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
            goto L_80000BF8;
    }
    // 0x80000CA4: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x80000CA8: b           L_80000E14
    // 0x80000CAC: nop

        goto L_80000E14;
    // 0x80000CAC: nop

L_80000CB0:
    // 0x80000CB0: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x80000CB4: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x80000CB8: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x80000CBC: addiu       $v0, $sp, 0x58
    ctx->r2 = ADD32(ctx->r29, 0X58);
L_80000CC0:
    // 0x80000CC0: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80000CC4: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80000CC8: lwc1        $f14, 0x4($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80000CCC: lwc1        $f12, 0x10($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80000CD0: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80000CD4: lwc1        $f18, 0x8($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80000CD8: lwc1        $f10, 0x20($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X20);
    // 0x80000CDC: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80000CE0: lwc1        $f14, 0x30($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X30);
    // 0x80000CE4: lwc1        $f8, 0xC($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80000CE8: mul.s       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80000CEC: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x80000CF0: sltu        $at, $a3, $v0
    ctx->r1 = ctx->r7 < ctx->r2 ? 1 : 0;
    // 0x80000CF4: mul.s       $f8, $f14, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x80000CF8: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x80000CFC: add.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x80000D00: add.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x80000D04: add.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80000D08: swc1        $f10, -0x10($a3)
    MEM_W(-0X10, ctx->r7) = ctx->f10.u32l;
    // 0x80000D0C: lwc1        $f10, -0x10($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, -0X10);
    // 0x80000D10: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80000D14: lwc1        $f12, -0xC($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, -0XC);
    // 0x80000D18: lwc1        $f16, 0x14($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80000D1C: mul.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80000D20: lwc1        $f10, -0x8($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, -0X8);
    // 0x80000D24: lwc1        $f14, 0x24($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X24);
    // 0x80000D28: mul.s       $f16, $f12, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x80000D2C: lwc1        $f12, 0x34($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X34);
    // 0x80000D30: lwc1        $f18, -0x4($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, -0X4);
    // 0x80000D34: mul.s       $f14, $f10, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80000D38: nop

    // 0x80000D3C: mul.s       $f18, $f12, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x80000D40: add.s       $f16, $f8, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80000D44: add.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f14.fl;
    // 0x80000D48: add.s       $f14, $f18, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f14.fl;
    // 0x80000D4C: swc1        $f14, -0xC($a3)
    MEM_W(-0XC, ctx->r7) = ctx->f14.u32l;
    // 0x80000D50: lwc1        $f14, -0x10($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, -0X10);
    // 0x80000D54: lwc1        $f18, 0x8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80000D58: lwc1        $f16, -0xC($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, -0XC);
    // 0x80000D5C: lwc1        $f8, 0x18($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80000D60: mul.s       $f18, $f14, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x80000D64: lwc1        $f14, -0x8($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, -0X8);
    // 0x80000D68: lwc1        $f12, 0x28($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X28);
    // 0x80000D6C: mul.s       $f8, $f16, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80000D70: lwc1        $f16, 0x38($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X38);
    // 0x80000D74: lwc1        $f10, -0x4($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, -0X4);
    // 0x80000D78: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80000D7C: nop

    // 0x80000D80: mul.s       $f10, $f16, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80000D84: add.s       $f8, $f18, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80000D88: add.s       $f12, $f8, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x80000D8C: add.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x80000D90: swc1        $f12, -0x8($a3)
    MEM_W(-0X8, ctx->r7) = ctx->f12.u32l;
    // 0x80000D94: lwc1        $f12, -0x10($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, -0X10);
    // 0x80000D98: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80000D9C: lwc1        $f8, -0xC($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, -0XC);
    // 0x80000DA0: lwc1        $f18, 0x1C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x80000DA4: mul.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x80000DA8: lwc1        $f12, -0x8($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, -0X8);
    // 0x80000DAC: lwc1        $f16, 0x2C($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x80000DB0: mul.s       $f18, $f8, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80000DB4: lwc1        $f8, 0x3C($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x80000DB8: lwc1        $f14, -0x4($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, -0X4);
    // 0x80000DBC: mul.s       $f16, $f12, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x80000DC0: nop

    // 0x80000DC4: mul.s       $f14, $f8, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80000DC8: add.s       $f18, $f10, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80000DCC: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80000DD0: add.s       $f16, $f14, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x80000DD4: bne         $at, $zero, L_80000CC0
    if (ctx->r1 != 0) {
        // 0x80000DD8: swc1        $f16, -0x4($a3)
        MEM_W(-0X4, ctx->r7) = ctx->f16.u32l;
            goto L_80000CC0;
    }
    // 0x80000DD8: swc1        $f16, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->f16.u32l;
    // 0x80000DDC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80000DE0: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x80000DE4: addiu       $v0, $sp, 0x58
    ctx->r2 = ADD32(ctx->r29, 0X58);
L_80000DE8:
    // 0x80000DE8: lwc1        $f16, 0x0($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80000DEC: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x80000DF0: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80000DF4: swc1        $f16, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->f16.u32l;
    // 0x80000DF8: lwc1        $f18, -0xC($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, -0XC);
    // 0x80000DFC: swc1        $f18, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f18.u32l;
    // 0x80000E00: lwc1        $f6, -0x8($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, -0X8);
    // 0x80000E04: swc1        $f6, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f6.u32l;
    // 0x80000E08: lwc1        $f10, -0x4($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, -0X4);
    // 0x80000E0C: bne         $a3, $v0, L_80000DE8
    if (ctx->r7 != ctx->r2) {
        // 0x80000E10: swc1        $f10, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
            goto L_80000DE8;
    }
    // 0x80000E10: swc1        $f10, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
L_80000E14:
    // 0x80000E14: jr          $ra
    // 0x80000E18: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    TRACE_RETURN()
    return;
    // 0x80000E18: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80000E1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80000E1C: beq         $a0, $a2, L_80000EFC
    if (ctx->r4 == ctx->r6) {
        // 0x80000E20: addiu       $sp, $sp, -0x60
        ctx->r29 = ADD32(ctx->r29, -0X60);
            goto L_80000EFC;
    }
    // 0x80000E20: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80000E24: beq         $a0, $a1, L_80000EFC
    if (ctx->r4 == ctx->r5) {
        // 0x80000E28: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80000EFC;
    }
    // 0x80000E28: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80000E2C: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80000E30: or          $t2, $a1, $zero
    ctx->r10 = ctx->r5 | 0;
    // 0x80000E34: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
L_80000E38:
    // 0x80000E38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80000E3C: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x80000E40: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
L_80000E44:
    // 0x80000E44: lwc1        $f18, 0x0($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80000E48: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80000E4C: lwc1        $f14, 0x4($t2)
    ctx->f14.u32l = MEM_W(ctx->r10, 0X4);
    // 0x80000E50: lwc1        $f12, 0x10($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X10);
    // 0x80000E54: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80000E58: lwc1        $f18, 0x20($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X20);
    // 0x80000E5C: lwc1        $f10, 0x8($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X8);
    // 0x80000E60: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80000E64: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80000E68: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80000E6C: mul.s       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80000E70: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80000E74: add.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x80000E78: add.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x80000E7C: bne         $v0, $t4, L_80000E44
    if (ctx->r2 != ctx->r12) {
        // 0x80000E80: swc1        $f12, -0x4($a3)
        MEM_W(-0X4, ctx->r7) = ctx->f12.u32l;
            goto L_80000E44;
    }
    // 0x80000E80: swc1        $f12, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->f12.u32l;
    // 0x80000E84: addiu       $t1, $t1, 0x10
    ctx->r9 = ADD32(ctx->r9, 0X10);
    // 0x80000E88: slti        $at, $t1, 0x30
    ctx->r1 = SIGNED(ctx->r9) < 0X30 ? 1 : 0;
    // 0x80000E8C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80000E90: bne         $at, $zero, L_80000E38
    if (ctx->r1 != 0) {
        // 0x80000E94: addiu       $t2, $t2, 0x10
        ctx->r10 = ADD32(ctx->r10, 0X10);
            goto L_80000E38;
    }
    // 0x80000E94: addiu       $t2, $t2, 0x10
    ctx->r10 = ADD32(ctx->r10, 0X10);
    // 0x80000E98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80000E9C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80000EA0: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80000EA4: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
L_80000EA8:
    // 0x80000EA8: lwc1        $f18, 0x30($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X30);
    // 0x80000EAC: lwc1        $f6, 0x30($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X30);
    // 0x80000EB0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80000EB4: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80000EB8: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80000EBC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80000EC0: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80000EC4: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80000EC8: bne         $at, $zero, L_80000EA8
    if (ctx->r1 != 0) {
        // 0x80000ECC: swc1        $f10, 0x2C($v1)
        MEM_W(0X2C, ctx->r3) = ctx->f10.u32l;
            goto L_80000EA8;
    }
    // 0x80000ECC: swc1        $f10, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f10.u32l;
    // 0x80000ED0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80000ED4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80000ED8: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_80000EDC:
    // 0x80000EDC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80000EE0: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
    // 0x80000EE4: bne         $v0, $t4, L_80000EDC
    if (ctx->r2 != ctx->r12) {
        // 0x80000EE8: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_80000EDC;
    }
    // 0x80000EE8: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80000EEC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80000EF0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80000EF4: b           L_80000FDC
    // 0x80000EF8: swc1        $f16, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f16.u32l;
        goto L_80000FDC;
    // 0x80000EF8: swc1        $f16, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f16.u32l;
L_80000EFC:
    // 0x80000EFC: or          $t2, $a1, $zero
    ctx->r10 = ctx->r5 | 0;
    // 0x80000F00: addiu       $t1, $sp, 0x18
    ctx->r9 = ADD32(ctx->r29, 0X18);
    // 0x80000F04: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80000F08: addiu       $v1, $sp, 0x48
    ctx->r3 = ADD32(ctx->r29, 0X48);
L_80000F0C:
    // 0x80000F0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80000F10: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x80000F14: or          $t3, $t1, $zero
    ctx->r11 = ctx->r9 | 0;
L_80000F18:
    // 0x80000F18: lwc1        $f18, 0x0($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80000F1C: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80000F20: lwc1        $f14, 0x4($t2)
    ctx->f14.u32l = MEM_W(ctx->r10, 0X4);
    // 0x80000F24: lwc1        $f12, 0x10($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X10);
    // 0x80000F28: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80000F2C: lwc1        $f18, 0x20($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X20);
    // 0x80000F30: lwc1        $f10, 0x8($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X8);
    // 0x80000F34: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80000F38: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80000F3C: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80000F40: mul.s       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80000F44: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x80000F48: add.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x80000F4C: add.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x80000F50: bne         $v0, $t4, L_80000F18
    if (ctx->r2 != ctx->r12) {
        // 0x80000F54: swc1        $f12, -0x4($t3)
        MEM_W(-0X4, ctx->r11) = ctx->f12.u32l;
            goto L_80000F18;
    }
    // 0x80000F54: swc1        $f12, -0x4($t3)
    MEM_W(-0X4, ctx->r11) = ctx->f12.u32l;
    // 0x80000F58: addiu       $t1, $t1, 0x10
    ctx->r9 = ADD32(ctx->r9, 0X10);
    // 0x80000F5C: sltu        $at, $t1, $v1
    ctx->r1 = ctx->r9 < ctx->r3 ? 1 : 0;
    // 0x80000F60: bne         $at, $zero, L_80000F0C
    if (ctx->r1 != 0) {
        // 0x80000F64: addiu       $t2, $t2, 0x10
        ctx->r10 = ADD32(ctx->r10, 0X10);
            goto L_80000F0C;
    }
    // 0x80000F64: addiu       $t2, $t2, 0x10
    ctx->r10 = ADD32(ctx->r10, 0X10);
    // 0x80000F68: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80000F6C: addiu       $t1, $sp, 0x18
    ctx->r9 = ADD32(ctx->r29, 0X18);
    // 0x80000F70: addiu       $t0, $sp, 0x48
    ctx->r8 = ADD32(ctx->r29, 0X48);
L_80000F74:
    // 0x80000F74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80000F78: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x80000F7C: or          $t3, $t1, $zero
    ctx->r11 = ctx->r9 | 0;
L_80000F80:
    // 0x80000F80: lwc1        $f16, 0x0($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80000F84: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80000F88: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80000F8C: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x80000F90: bne         $v0, $t4, L_80000F80
    if (ctx->r2 != ctx->r12) {
        // 0x80000F94: swc1        $f16, -0x4($a3)
        MEM_W(-0X4, ctx->r7) = ctx->f16.u32l;
            goto L_80000F80;
    }
    // 0x80000F94: swc1        $f16, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->f16.u32l;
    // 0x80000F98: addiu       $t1, $t1, 0x10
    ctx->r9 = ADD32(ctx->r9, 0X10);
    // 0x80000F9C: sltu        $at, $t1, $t0
    ctx->r1 = ctx->r9 < ctx->r8 ? 1 : 0;
    // 0x80000FA0: bne         $at, $zero, L_80000F74
    if (ctx->r1 != 0) {
        // 0x80000FA4: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_80000F74;
    }
    // 0x80000FA4: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80000FA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80000FAC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80000FB0: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80000FB4: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
L_80000FB8:
    // 0x80000FB8: lwc1        $f8, 0x30($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X30);
    // 0x80000FBC: lwc1        $f6, 0x30($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X30);
    // 0x80000FC0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80000FC4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80000FC8: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80000FCC: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80000FD0: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80000FD4: bne         $v0, $t4, L_80000FB8
    if (ctx->r2 != ctx->r12) {
        // 0x80000FD8: swc1        $f10, 0x2C($v1)
        MEM_W(0X2C, ctx->r3) = ctx->f10.u32l;
            goto L_80000FB8;
    }
    // 0x80000FD8: swc1        $f10, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f10.u32l;
L_80000FDC:
    // 0x80000FDC: jr          $ra
    // 0x80000FE0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    TRACE_RETURN()
    return;
    // 0x80000FE0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80000FE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80000FE4: beq         $a0, $a1, L_8000104C
    if (ctx->r4 == ctx->r5) {
        // 0x80000FE8: addiu       $sp, $sp, -0x20
        ctx->r29 = ADD32(ctx->r29, -0X20);
            goto L_8000104C;
    }
    // 0x80000FE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80000FEC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80000FF0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80000FF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80000FF8: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
L_80000FFC:
    // 0x80000FFC: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80001000: lwc1        $f16, 0x0($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80001004: lwc1        $f14, 0x4($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80001008: lwc1        $f12, 0x10($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X10);
    // 0x8000100C: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80001010: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80001014: lwc1        $f10, 0x20($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X20);
    // 0x80001018: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8000101C: lwc1        $f14, 0x30($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X30);
    // 0x80001020: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80001024: mul.s       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80001028: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000102C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80001030: add.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x80001034: add.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x80001038: add.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x8000103C: bne         $v0, $a0, L_80000FFC
    if (ctx->r2 != ctx->r4) {
        // 0x80001040: swc1        $f10, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
            goto L_80000FFC;
    }
    // 0x80001040: swc1        $f10, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
    // 0x80001044: b           L_800010C0
    // 0x80001048: nop

        goto L_800010C0;
    // 0x80001048: nop

L_8000104C:
    // 0x8000104C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80001050: addiu       $t0, $sp, 0x10
    ctx->r8 = ADD32(ctx->r29, 0X10);
    // 0x80001054: addiu       $v0, $sp, 0x1C
    ctx->r2 = ADD32(ctx->r29, 0X1C);
L_80001058:
    // 0x80001058: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8000105C: lwc1        $f16, 0x0($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80001060: lwc1        $f14, 0x4($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80001064: lwc1        $f12, 0x10($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80001068: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8000106C: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80001070: lwc1        $f10, 0x20($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X20);
    // 0x80001074: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80001078: lwc1        $f14, 0x30($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X30);
    // 0x8000107C: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80001080: mul.s       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80001084: sltu        $at, $t0, $v0
    ctx->r1 = ctx->r8 < ctx->r2 ? 1 : 0;
    // 0x80001088: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8000108C: add.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x80001090: add.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x80001094: add.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x80001098: bne         $at, $zero, L_80001058
    if (ctx->r1 != 0) {
        // 0x8000109C: swc1        $f10, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->f10.u32l;
            goto L_80001058;
    }
    // 0x8000109C: swc1        $f10, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->f10.u32l;
    // 0x800010A0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800010A4: addiu       $t0, $sp, 0x10
    ctx->r8 = ADD32(ctx->r29, 0X10);
    // 0x800010A8: addiu       $v0, $sp, 0x1C
    ctx->r2 = ADD32(ctx->r29, 0X1C);
L_800010AC:
    // 0x800010AC: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800010B0: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800010B4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800010B8: bne         $t0, $v0, L_800010AC
    if (ctx->r8 != ctx->r2) {
        // 0x800010BC: swc1        $f18, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
            goto L_800010AC;
    }
    // 0x800010BC: swc1        $f18, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
L_800010C0:
    // 0x800010C0: jr          $ra
    // 0x800010C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    TRACE_RETURN()
    return;
    // 0x800010C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800010C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800010C8: beq         $a0, $a1, L_80001128
    if (ctx->r4 == ctx->r5) {
        // 0x800010CC: addiu       $sp, $sp, -0x20
        ctx->r29 = ADD32(ctx->r29, -0X20);
            goto L_80001128;
    }
    // 0x800010CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800010D0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800010D4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800010D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800010DC: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
L_800010E0:
    // 0x800010E0: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800010E4: lwc1        $f16, 0x0($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800010E8: lwc1        $f14, 0x4($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800010EC: lwc1        $f12, 0x10($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800010F0: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800010F4: lwc1        $f18, 0x20($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X20);
    // 0x800010F8: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800010FC: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80001100: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80001104: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80001108: mul.s       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8000110C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80001110: add.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x80001114: add.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x80001118: bne         $v0, $a0, L_800010E0
    if (ctx->r2 != ctx->r4) {
        // 0x8000111C: swc1        $f12, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f12.u32l;
            goto L_800010E0;
    }
    // 0x8000111C: swc1        $f12, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f12.u32l;
    // 0x80001120: b           L_80001194
    // 0x80001124: nop

        goto L_80001194;
    // 0x80001124: nop

L_80001128:
    // 0x80001128: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8000112C: addiu       $t0, $sp, 0x10
    ctx->r8 = ADD32(ctx->r29, 0X10);
    // 0x80001130: addiu       $v0, $sp, 0x1C
    ctx->r2 = ADD32(ctx->r29, 0X1C);
L_80001134:
    // 0x80001134: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80001138: lwc1        $f16, 0x0($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8000113C: lwc1        $f14, 0x4($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80001140: lwc1        $f12, 0x10($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80001144: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80001148: lwc1        $f18, 0x20($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X20);
    // 0x8000114C: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80001150: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80001154: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80001158: sltu        $at, $t0, $v0
    ctx->r1 = ctx->r8 < ctx->r2 ? 1 : 0;
    // 0x8000115C: mul.s       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80001160: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80001164: add.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x80001168: add.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x8000116C: bne         $at, $zero, L_80001134
    if (ctx->r1 != 0) {
        // 0x80001170: swc1        $f12, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->f12.u32l;
            goto L_80001134;
    }
    // 0x80001170: swc1        $f12, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->f12.u32l;
    // 0x80001174: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80001178: addiu       $t0, $sp, 0x10
    ctx->r8 = ADD32(ctx->r29, 0X10);
    // 0x8000117C: addiu       $v0, $sp, 0x1C
    ctx->r2 = ADD32(ctx->r29, 0X1C);
L_80001180:
    // 0x80001180: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80001184: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80001188: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000118C: bne         $t0, $v0, L_80001180
    if (ctx->r8 != ctx->r2) {
        // 0x80001190: swc1        $f8, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f8.u32l;
            goto L_80001180;
    }
    // 0x80001190: swc1        $f8, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f8.u32l;
L_80001194:
    // 0x80001194: jr          $ra
    // 0x80001198: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    TRACE_RETURN()
    return;
    // 0x80001198: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8000119C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000119C: lwc1        $f2, 0x8($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800011A0: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800011A4: lwc1        $f14, 0x0($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800011A8: mul.s       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800011AC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800011B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800011B4: mul.s       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800011B8: nop

    // 0x800011BC: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800011C0: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x800011C4: add.s       $f0, $f12, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x800011C8: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x800011CC: nop

    // 0x800011D0: bc1f        L_800011E0
    if (!c1cs) {
        // 0x800011D4: nop
    
            goto L_800011E0;
    }
    // 0x800011D4: nop

    // 0x800011D8: jr          $ra
    // 0x800011DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    TRACE_RETURN()
    return;
    // 0x800011DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800011E0:
    // 0x800011E0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800011E4: add.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f18.fl;
    // 0x800011E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800011EC: div.s       $f0, $f10, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800011F0: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800011F4: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x800011F8: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800011FC: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80001200: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x80001204: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80001208: nop

    // 0x8000120C: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80001210: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
    // 0x80001214: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80001218: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8000121C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80001220: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80001224: nop

    // 0x80001228: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8000122C: swc1        $f4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f4.u32l;
    // 0x80001230: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80001234: lwc1        $f8, 0xC($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80001238: neg.s       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = -ctx->f6.fl;
    // 0x8000123C: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80001240: nop

    // 0x80001244: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80001248: swc1        $f6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f6.u32l;
    // 0x8000124C: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80001250: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80001254: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x80001258: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8000125C: nop

    // 0x80001260: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80001264: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x80001268: lwc1        $f2, 0x8($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8000126C: lwc1        $f14, 0x0($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80001270: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80001274: nop

    // 0x80001278: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8000127C: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80001280: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80001284: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
    // 0x80001288: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8000128C: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80001290: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80001294: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80001298: nop

    // 0x8000129C: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800012A0: swc1        $f4, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f4.u32l;
    // 0x800012A4: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800012A8: lwc1        $f8, 0xC($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800012AC: neg.s       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = -ctx->f6.fl;
    // 0x800012B0: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800012B4: nop

    // 0x800012B8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800012BC: swc1        $f6, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f6.u32l;
    // 0x800012C0: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800012C4: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800012C8: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x800012CC: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800012D0: nop

    // 0x800012D4: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800012D8: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    // 0x800012DC: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800012E0: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800012E4: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800012E8: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800012EC: nop

    // 0x800012F0: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800012F4: swc1        $f4, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f4.u32l;
    // 0x800012F8: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800012FC: lwc1        $f14, 0x0($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80001300: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80001304: nop

    // 0x80001308: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8000130C: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80001310: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80001314: swc1        $f4, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f4.u32l;
    // 0x80001318: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8000131C: lwc1        $f8, 0xC($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80001320: neg.s       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = -ctx->f6.fl;
    // 0x80001324: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80001328: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8000132C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80001330: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
    // 0x80001334: swc1        $f10, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f10.u32l;
    // 0x80001338: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8000133C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80001340: nop

    // 0x80001344: swc1        $f4, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f4.u32l;
    // 0x80001348: swc1        $f6, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f6.u32l;
    // 0x8000134C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80001350: nop

    // 0x80001354: swc1        $f6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
    // 0x80001358: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80001360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80001360: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80001364: lwc1        $f18, 0x68($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80001368: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8000136C: lwc1        $f14, 0x70($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80001370: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80001374: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80001378: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x8000137C: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80001380: sub.s       $f0, $f18, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x80001384: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x80001388: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8000138C: sub.s       $f8, $f16, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x80001390: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80001394: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80001398: sub.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f10.fl;
    // 0x8000139C: mul.s       $f14, $f8, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x800013A0: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x800013A4: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x800013A8: mul.s       $f18, $f10, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800013AC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800013B0: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x800013B4: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x800013B8: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    // 0x800013BC: add.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f14.fl;
    // 0x800013C0: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800013C4: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x800013C8: jal         0x8004F640
    // 0x800013CC: add.s       $f12, $f14, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f14.fl + ctx->f18.fl;
    func_8004F640(rdram, ctx);
        goto after_0;
    // 0x800013CC: add.s       $f12, $f14, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f14.fl + ctx->f18.fl;
    after_0:
    // 0x800013D0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800013D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800013D8: lwc1        $f2, 0x50($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800013DC: lwc1        $f14, 0x4C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800013E0: div.s       $f18, $f4, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800013E4: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800013E8: lwc1        $f20, 0x74($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800013EC: lwc1        $f22, 0x78($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800013F0: lwc1        $f24, 0x7C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800013F4: mul.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x800013F8: nop

    // 0x800013FC: mul.s       $f14, $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x80001400: nop

    // 0x80001404: mul.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80001408: swc1        $f2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
    // 0x8000140C: mul.s       $f6, $f20, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80001410: swc1        $f14, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f14.u32l;
    // 0x80001414: mul.s       $f8, $f22, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x80001418: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    // 0x8000141C: mul.s       $f4, $f24, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x80001420: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80001424: jal         0x8004F640
    // 0x80001428: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    func_8004F640(rdram, ctx);
        goto after_1;
    // 0x80001428: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    after_1:
    // 0x8000142C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80001430: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80001434: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80001438: lwc1        $f14, 0x4C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8000143C: div.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80001440: lwc1        $f2, 0x50($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80001444: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80001448: mul.s       $f20, $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f12.fl);
    // 0x8000144C: nop

    // 0x80001450: mul.s       $f22, $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f12.fl);
    // 0x80001454: nop

    // 0x80001458: mul.s       $f24, $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f12.fl);
    // 0x8000145C: lwc1        $f12, 0x5C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80001460: mul.s       $f8, $f22, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f16.fl);
    // 0x80001464: nop

    // 0x80001468: mul.s       $f10, $f24, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f14.fl);
    // 0x8000146C: nop

    // 0x80001470: mul.s       $f4, $f24, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f2.fl);
;}
RECOMP_FUNC void func_80001478(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80001478: mul.s       $f6, $f20, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f16.fl);
    // 0x8000147C: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80001480: mul.s       $f10, $f20, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f14.fl);
    // 0x80001484: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    // 0x80001488: lwc1        $f24, 0x44($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8000148C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80001490: mul.s       $f4, $f22, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x80001494: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80001498: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8000149C: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800014A0: mul.s       $f10, $f14, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x800014A4: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x800014A8: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x800014AC: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800014B0: sub.s       $f20, $f10, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800014B4: mul.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800014B8: nop

    // 0x800014BC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800014C0: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800014C4: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x800014C8: swc1        $f24, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f24.u32l;
    // 0x800014CC: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800014D0: sub.s       $f22, $f4, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800014D4: swc1        $f6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f6.u32l;
    // 0x800014D8: mul.s       $f4, $f12, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f24.fl);
    // 0x800014DC: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800014E0: mul.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800014E4: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800014E8: swc1        $f20, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f20.u32l;
    // 0x800014EC: swc1        $f22, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f22.u32l;
    // 0x800014F0: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800014F4: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800014F8: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800014FC: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80001500: swc1        $f10, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f10.u32l;
    // 0x80001504: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80001508: mul.s       $f4, $f2, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8000150C: nop

    // 0x80001510: mul.s       $f8, $f14, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f24.fl);
    // 0x80001514: sub.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80001518: mul.s       $f10, $f12, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x8000151C: swc1        $f0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f0.u32l;
    // 0x80001520: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80001524: swc1        $f2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f2.u32l;
    // 0x80001528: swc1        $f14, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f14.u32l;
    // 0x8000152C: mul.s       $f4, $f6, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x80001530: swc1        $f16, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f16.u32l;
    // 0x80001534: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80001538: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8000153C: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80001540: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80001544: mul.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x80001548: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x8000154C: swc1        $f4, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f4.u32l;
    // 0x80001550: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80001554: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x80001558: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x8000155C: mul.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80001560: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    // 0x80001564: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80001568: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8000156C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80001570: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80001574: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80001578: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
    // 0x8000157C: swc1        $f10, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f10.u32l;
    // 0x80001580: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80001584: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80001588: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8000158C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80001590: jr          $ra
    // 0x80001594: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    TRACE_RETURN()
    return;
    // 0x80001594: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80001598(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80001598: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000159C: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x800015A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800015A4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800015A8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800015AC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800015B0: jal         0x800022F0
    // 0x800015B4: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    func_800022F0(rdram, ctx);
        goto after_0;
    // 0x800015B4: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x800015B8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800015BC: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800015C0: lwc1        $f4, 0x4870($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X4870);
    // 0x800015C4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800015C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800015CC: mul.s       $f14, $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x800015D0: div.s       $f12, $f14, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f14.fl, ctx->f6.fl);
    // 0x800015D4: jal         0x8004F650
    // 0x800015D8: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_8004F650(rdram, ctx);
        goto after_1;
    // 0x800015D8: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x800015DC: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800015E0: jal         0x8004F7C0
    // 0x800015E4: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    func_8004F7C0(rdram, ctx);
        goto after_2;
    // 0x800015E4: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x800015E8: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800015EC: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800015F0: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800015F4: div.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800015F8: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800015FC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80001600: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80001604: sub.s       $f12, $f16, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f14.fl;
    // 0x80001608: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000160C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80001610: add.s       $f4, $f16, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f14.fl;
    // 0x80001614: swc1        $f8, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f8.u32l;
    // 0x80001618: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8000161C: nop

    // 0x80001620: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
    // 0x80001624: div.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80001628: swc1        $f2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f2.u32l;
    // 0x8000162C: div.s       $f18, $f2, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80001630: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80001634: swc1        $f6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f6.u32l;
    // 0x80001638: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x8000163C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80001640: nop

    // 0x80001644: mul.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x80001648: div.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8000164C: swc1        $f6, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f6.u32l;
    // 0x80001650: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001654: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80001658: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80001660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80001660: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001664: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001668: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8000166C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80001670: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80001674: jal         0x800022F0
    // 0x80001678: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800022F0(rdram, ctx);
        goto after_0;
    // 0x80001678: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8000167C: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80001680: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80001684: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80001688: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000168C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80001690: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80001694: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80001698: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8000169C: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800016A0: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800016A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800016A8: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x800016AC: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800016B0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800016B4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800016B8: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x800016BC: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800016C0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800016C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800016C8: sub.s       $f2, $f14, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f14.fl - ctx->f4.fl;
    // 0x800016CC: div.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800016D0: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800016D4: swc1        $f4, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f4.u32l;
    // 0x800016D8: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
    // 0x800016DC: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800016E0: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800016E4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800016E8: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x800016EC: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800016F0: swc1        $f6, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f6.u32l;
    // 0x800016F4: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800016F8: add.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x800016FC: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80001700: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x80001704: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80001708: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8000170C: div.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80001710: swc1        $f6, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f6.u32l;
    // 0x80001714: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80001718: nop

    // 0x8000171C: swc1        $f6, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f6.u32l;
    // 0x80001720: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
    // 0x80001724: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80001728: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000172C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80001730: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80001734: mul.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80001738: lwc1        $f14, 0x8($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8000173C: beq         $v1, $a0, L_80001780
    if (ctx->r3 == ctx->r4) {
        // 0x80001740: lwc1        $f16, 0xC($v0)
        ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
            goto L_80001780;
    }
    // 0x80001740: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
L_80001744:
    // 0x80001744: mul.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80001748: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8000174C: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80001750: mul.s       $f6, $f14, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80001754: lwc1        $f14, 0x18($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80001758: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000175C: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80001760: lwc1        $f16, 0x1C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80001764: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
    // 0x80001768: mul.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8000176C: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x80001770: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x80001774: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80001778: bne         $v1, $a0, L_80001744
    if (ctx->r3 != ctx->r4) {
        // 0x8000177C: swc1        $f4, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
            goto L_80001744;
    }
    // 0x8000177C: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
L_80001780:
    // 0x80001780: mul.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80001784: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
    // 0x80001788: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8000178C: mul.s       $f6, $f14, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80001790: nop

    // 0x80001794: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80001798: swc1        $f10, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f10.u32l;
    // 0x8000179C: swc1        $f6, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f6.u32l;
    // 0x800017A0: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x800017A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800017A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800017AC: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800017B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800017B4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800017B8: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800017BC: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x800017C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800017C4: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800017C8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800017CC: jal         0x800022F0
    // 0x800017D0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    func_800022F0(rdram, ctx);
        goto after_0;
    // 0x800017D0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x800017D4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800017D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800017DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800017E0: lwc1        $f14, 0x4($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800017E4: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800017E8: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800017EC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800017F0: mul.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800017F4: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800017F8: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800017FC: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x80001800: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80001804: mul.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x80001808: nop

    // 0x8000180C: mul.s       $f16, $f4, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80001810: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80001814: mul.s       $f8, $f0, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80001818: nop

    // 0x8000181C: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80001820: nop

    // 0x80001824: mul.s       $f2, $f0, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80001828: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x8000182C: sub.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x80001830: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80001834: add.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x80001838: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x8000183C: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80001840: mul.s       $f6, $f8, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80001844: sub.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x80001848: swc1        $f10, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f10.u32l;
    // 0x8000184C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80001850: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80001854: mul.s       $f8, $f4, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80001858: add.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8000185C: swc1        $f6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f6.u32l;
    // 0x80001860: lwc1        $f14, 0x4($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80001864: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80001868: mul.s       $f2, $f14, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8000186C: sub.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x80001870: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80001874: add.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x80001878: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
    // 0x8000187C: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80001880: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80001884: mul.s       $f8, $f4, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80001888: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8000188C: swc1        $f10, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f10.u32l;
    // 0x80001890: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80001894: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80001898: mul.s       $f6, $f8, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8000189C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800018A0: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800018A4: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    // 0x800018A8: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800018AC: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800018B0: mul.s       $f2, $f18, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800018B4: sub.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x800018B8: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800018BC: add.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x800018C0: swc1        $f8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f8.u32l;
    // 0x800018C4: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800018C8: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800018CC: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800018D0: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800018D4: swc1        $f8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f8.u32l;
    // 0x800018D8: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800018DC: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800018E0: mul.s       $f4, $f6, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800018E4: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800018E8: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    // 0x800018EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800018F0: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800018F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800018F8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80001900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80001900: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80001904: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80001908: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000190C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80001910: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80001914: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80001918: jal         0x800022F0
    // 0x8000191C: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    func_800022F0(rdram, ctx);
        goto after_0;
    // 0x8000191C: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_0:
    // 0x80001920: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80001924: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80001928: jal         0x80003918
    // 0x8000192C: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    func_80003918(rdram, ctx);
        goto after_1;
    // 0x8000192C: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    after_1:
    // 0x80001930: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80001934: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80001938: lwc1        $f4, 0x4874($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X4874);
    // 0x8000193C: mul.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80001940: jal         0x8004F7C0
    // 0x80001944: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    func_8004F7C0(rdram, ctx);
        goto after_2;
    // 0x80001944: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    after_2:
    // 0x80001948: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8000194C: jal         0x8004F650
    // 0x80001950: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    func_8004F650(rdram, ctx);
        goto after_3;
    // 0x80001950: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x80001954: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80001958: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8000195C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80001960: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80001964: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80001968: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8000196C: sub.s       $f2, $f6, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80001970: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80001974: mul.s       $f18, $f4, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80001978: nop

    // 0x8000197C: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80001980: nop

    // 0x80001984: mul.s       $f12, $f4, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80001988: nop

    // 0x8000198C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80001990: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80001994: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80001998: nop

    // 0x8000199C: mul.s       $f16, $f8, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x800019A0: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x800019A4: sub.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x800019A8: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800019AC: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800019B0: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    // 0x800019B4: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800019B8: mul.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800019BC: sub.s       $f4, $f12, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x800019C0: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    // 0x800019C4: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800019C8: mul.s       $f6, $f8, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800019CC: add.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x800019D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800019D4: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    // 0x800019D8: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800019DC: mul.s       $f8, $f4, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800019E0: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800019E4: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x800019E8: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800019EC: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800019F0: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x800019F4: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800019F8: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800019FC: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80001A00: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80001A04: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x80001A08: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80001A0C: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80001A10: mul.s       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80001A14: sub.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80001A18: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80001A1C: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x80001A20: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80001A24: mul.s       $f2, $f4, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x80001A28: sub.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x80001A2C: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80001A30: add.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x80001A34: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
    // 0x80001A38: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80001A3C: mul.s       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80001A40: sub.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x80001A44: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x80001A48: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80001A4C: mul.s       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80001A50: add.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80001A54: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x80001A58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80001A5C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80001A60: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80001A64: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80001A6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80001A6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001A70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001A74: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80001A78: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80001A7C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80001A80: jal         0x800022F0
    // 0x80001A84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800022F0(rdram, ctx);
        goto after_0;
    // 0x80001A84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80001A88: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80001A8C: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80001A90: swc1        $f4, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f4.u32l;
    // 0x80001A94: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80001A98: swc1        $f6, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f6.u32l;
    // 0x80001A9C: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80001AA0: swc1        $f8, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f8.u32l;
    // 0x80001AA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001AA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001AAC: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80001AB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80001AB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001AB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001ABC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80001AC0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80001AC4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80001AC8: jal         0x800022F0
    // 0x80001ACC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800022F0(rdram, ctx);
        goto after_0;
    // 0x80001ACC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80001AD0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80001AD4: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80001AD8: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80001ADC: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80001AE0: swc1        $f6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f6.u32l;
    // 0x80001AE4: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80001AE8: swc1        $f8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f8.u32l;
    // 0x80001AEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001AF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001AF4: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80001AFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80001AFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001B00: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80001B04: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80001B08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001B0C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80001B10: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80001B14: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_80001B18:
    // 0x80001B18: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80001B1C: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80001B20: nop

    // 0x80001B24: bc1tl       L_80001B3C
    if (c1cs) {
        // 0x80001B28: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_80001B3C;
    }
    goto skip_0;
    // 0x80001B28: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    skip_0:
    // 0x80001B2C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80001B30: bne         $v1, $a0, L_80001B18
    if (ctx->r3 != ctx->r4) {
        // 0x80001B34: addiu       $v0, $v0, 0x14
        ctx->r2 = ADD32(ctx->r2, 0X14);
            goto L_80001B18;
    }
    // 0x80001B34: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x80001B38: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
L_80001B3C:
    // 0x80001B3C: bne         $v1, $at, L_80001B54
    if (ctx->r3 != ctx->r1) {
        // 0x80001B40: nop
    
            goto L_80001B54;
    }
    // 0x80001B40: nop

    // 0x80001B44: jal         0x80001B6C
    // 0x80001B48: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80001B6C(rdram, ctx);
        goto after_0;
    // 0x80001B48: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x80001B4C: b           L_80001B5C
    // 0x80001B50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80001B5C;
    // 0x80001B50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80001B54:
    // 0x80001B54: jal         0x80001CB0
    // 0x80001B58: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80001CB0(rdram, ctx);
        goto after_1;
    // 0x80001B58: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
L_80001B5C:
    // 0x80001B5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001B60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001B64: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80001B6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80001B6C: beq         $a0, $a1, L_80001BB4
    if (ctx->r4 == ctx->r5) {
        // 0x80001B70: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_80001BB4;
    }
    // 0x80001B70: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80001B74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80001B78: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x80001B7C: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80001B80: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
L_80001B84:
    // 0x80001B84: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80001B88: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80001B8C: addiu       $t2, $t2, 0x10
    ctx->r10 = ADD32(ctx->r10, 0X10);
    // 0x80001B90: swc1        $f4, -0x10($t2)
    MEM_W(-0X10, ctx->r10) = ctx->f4.u32l;
    // 0x80001B94: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80001B98: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80001B9C: swc1        $f6, -0xC($t2)
    MEM_W(-0XC, ctx->r10) = ctx->f6.u32l;
    // 0x80001BA0: lwc1        $f8, -0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, -0X8);
    // 0x80001BA4: swc1        $f8, -0x8($t2)
    MEM_W(-0X8, ctx->r10) = ctx->f8.u32l;
    // 0x80001BA8: lwc1        $f10, -0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, -0X4);
    // 0x80001BAC: bne         $v0, $t4, L_80001B84
    if (ctx->r2 != ctx->r12) {
        // 0x80001BB0: swc1        $f10, -0x4($t2)
        MEM_W(-0X4, ctx->r10) = ctx->f10.u32l;
            goto L_80001B84;
    }
    // 0x80001BB0: swc1        $f10, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->f10.u32l;
L_80001BB4:
    // 0x80001BB4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80001BB8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80001BBC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80001BC0: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80001BC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80001BC8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80001BCC: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
L_80001BD0:
    // 0x80001BD0: lwc1        $f0, 0x0($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80001BD4: addiu       $t0, $t0, 0x14
    ctx->r8 = ADD32(ctx->r8, 0X14);
    // 0x80001BD8: swc1        $f2, -0x14($t0)
    MEM_W(-0X14, ctx->r8) = ctx->f2.u32l;
    // 0x80001BDC: c.eq.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl == ctx->f12.fl;
    // 0x80001BE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80001BE4: bc1t        L_80001C24
    if (c1cs) {
        // 0x80001BE8: nop
    
            goto L_80001C24;
    }
    // 0x80001BE8: nop

    // 0x80001BEC: div.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80001BF0: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80001BF4: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80001BF8: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80001BFC: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80001C00: lwc1        $f16, 0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80001C04: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80001C08: nop

    // 0x80001C0C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80001C10: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
    // 0x80001C14: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80001C18: swc1        $f6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f6.u32l;
    // 0x80001C1C: swc1        $f10, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f10.u32l;
    // 0x80001C20: swc1        $f18, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f18.u32l;
L_80001C24:
    // 0x80001C24: beq         $v0, $a1, L_80001C8C
    if (ctx->r2 == ctx->r5) {
        // 0x80001C28: sll         $t6, $v0, 4
        ctx->r14 = S32(ctx->r2 << 4);
            goto L_80001C8C;
    }
    // 0x80001C28: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x80001C2C: addu        $v1, $a0, $t6
    ctx->r3 = ADD32(ctx->r4, ctx->r14);
    // 0x80001C30: addu        $t1, $v1, $a3
    ctx->r9 = ADD32(ctx->r3, ctx->r7);
    // 0x80001C34: lwc1        $f0, 0x0($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80001C38: swc1        $f12, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f12.u32l;
    // 0x80001C3C: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80001C40: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80001C44: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80001C48: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80001C4C: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80001C50: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80001C54: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x80001C58: lwc1        $f18, 0x4($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80001C5C: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80001C60: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x80001C64: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80001C68: swc1        $f4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
    // 0x80001C6C: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80001C70: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80001C74: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x80001C78: swc1        $f16, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f16.u32l;
    // 0x80001C7C: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80001C80: mul.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80001C84: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80001C88: swc1        $f8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f8.u32l;
L_80001C8C:
    // 0x80001C8C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80001C90: bne         $v0, $t4, L_80001C24
    if (ctx->r2 != ctx->r12) {
        // 0x80001C94: nop
    
            goto L_80001C24;
    }
    // 0x80001C94: nop

    // 0x80001C98: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80001C9C: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80001CA0: bne         $a1, $t4, L_80001BD0
    if (ctx->r5 != ctx->r12) {
        // 0x80001CA4: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80001BD0;
    }
    // 0x80001CA4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80001CA8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80001CB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80001CB0: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x80001CB4: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80001CB8: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x80001CBC: lui         $t1, 0x8006
    ctx->r9 = S32(0X8006 << 16);
    // 0x80001CC0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80001CC4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80001CC8: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x80001CCC: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80001CD0: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x80001CD4: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x80001CD8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80001CDC: addiu       $t1, $t1, 0x7250
    ctx->r9 = ADD32(ctx->r9, 0X7250);
    // 0x80001CE0: addiu       $a3, $a3, 0x71F0
    ctx->r7 = ADD32(ctx->r7, 0X71F0);
    // 0x80001CE4: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x80001CE8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
L_80001CEC:
    // 0x80001CEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80001CF0:
    // 0x80001CF0: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x80001CF4: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x80001CF8: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x80001CFC: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x80001D00: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80001D04: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80001D08: nop

    // 0x80001D0C: bc1t        L_80001D24
    if (c1cs) {
        // 0x80001D10: nop
    
            goto L_80001D24;
    }
    // 0x80001D10: nop

    // 0x80001D14: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80001D18: slti        $at, $a0, 0x10
    ctx->r1 = SIGNED(ctx->r4) < 0X10 ? 1 : 0;
    // 0x80001D1C: bne         $at, $zero, L_80001CF0
    if (ctx->r1 != 0) {
        // 0x80001D20: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80001CF0;
    }
    // 0x80001D20: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80001D24:
    // 0x80001D24: bnel        $a0, $t0, L_80001D54
    if (ctx->r4 != ctx->r8) {
        // 0x80001D28: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80001D54;
    }
    goto skip_0;
    // 0x80001D28: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    skip_0:
    // 0x80001D2C: lbu         $t9, 0x0($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X0);
    // 0x80001D30: lbu         $t6, 0x1($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X1);
    // 0x80001D34: lbu         $t7, 0x2($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X2);
    // 0x80001D38: lbu         $t8, 0x3($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X3);
    // 0x80001D3C: sw          $t9, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r25;
    // 0x80001D40: sw          $t6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r14;
    // 0x80001D44: sw          $t7, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r15;
    // 0x80001D48: b           L_80001D60
    // 0x80001D4C: sw          $t8, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r24;
        goto L_80001D60;
    // 0x80001D4C: sw          $t8, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r24;
    // 0x80001D50: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
L_80001D54:
    // 0x80001D54: sltu        $at, $a3, $t1
    ctx->r1 = ctx->r7 < ctx->r9 ? 1 : 0;
    // 0x80001D58: bnel        $at, $zero, L_80001CEC
    if (ctx->r1 != 0) {
        // 0x80001D5C: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_80001CEC;
    }
    goto skip_1;
    // 0x80001D5C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    skip_1:
L_80001D60:
    // 0x80001D60: lui         $t9, 0x8006
    ctx->r25 = S32(0X8006 << 16);
    // 0x80001D64: addiu       $t9, $t9, 0x7250
    ctx->r25 = ADD32(ctx->r25, 0X7250);
    // 0x80001D68: bne         $a3, $t9, L_80001D78
    if (ctx->r7 != ctx->r25) {
        // 0x80001D6C: addiu       $a0, $sp, 0x98
        ctx->r4 = ADD32(ctx->r29, 0X98);
            goto L_80001D78;
    }
    // 0x80001D6C: addiu       $a0, $sp, 0x98
    ctx->r4 = ADD32(ctx->r29, 0X98);
    // 0x80001D70: b           L_800022D4
    // 0x80001D74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800022D4;
    // 0x80001D74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80001D78:
    // 0x80001D78: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80001D7C: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x80001D80: addiu       $a3, $sp, 0x90
    ctx->r7 = ADD32(ctx->r29, 0X90);
L_80001D84:
    // 0x80001D84: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80001D88: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80001D8C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80001D90: sltiu       $t8, $v1, 0x1
    ctx->r24 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80001D94: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80001D98: sll         $t6, $v1, 4
    ctx->r14 = S32(ctx->r3 << 4);
    // 0x80001D9C: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x80001DA0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80001DA4: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80001DA8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80001DAC: swc1        $f6, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->f6.u32l;
    // 0x80001DB0: swc1        $f10, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f10.u32l;
    // 0x80001DB4: lw          $v1, -0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X4);
    // 0x80001DB8: xori        $t7, $v1, 0x1
    ctx->r15 = ctx->r3 ^ 0X1;
    // 0x80001DBC: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80001DC0: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80001DC4: sll         $t9, $v1, 4
    ctx->r25 = S32(ctx->r3 << 4);
    // 0x80001DC8: addu        $t6, $s0, $t9
    ctx->r14 = ADD32(ctx->r16, ctx->r25);
    // 0x80001DCC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80001DD0: lwc1        $f16, 0x4($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X4);
    // 0x80001DD4: swc1        $f16, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->f16.u32l;
    // 0x80001DD8: swc1        $f4, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f4.u32l;
    // 0x80001DDC: lw          $v1, -0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X4);
    // 0x80001DE0: xori        $t6, $v1, 0x2
    ctx->r14 = ctx->r3 ^ 0X2;
    // 0x80001DE4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80001DE8: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80001DEC: sll         $t8, $v1, 4
    ctx->r24 = S32(ctx->r3 << 4);
    // 0x80001DF0: addu        $t9, $s0, $t8
    ctx->r25 = ADD32(ctx->r16, ctx->r24);
    // 0x80001DF4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80001DF8: lwc1        $f6, 0x8($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X8);
    // 0x80001DFC: swc1        $f6, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->f6.u32l;
    // 0x80001E00: swc1        $f10, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f10.u32l;
    // 0x80001E04: lw          $v1, -0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X4);
    // 0x80001E08: xori        $t9, $v1, 0x3
    ctx->r25 = ctx->r3 ^ 0X3;
    // 0x80001E0C: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80001E10: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80001E14: sll         $t7, $v1, 4
    ctx->r15 = S32(ctx->r3 << 4);
    // 0x80001E18: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x80001E1C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80001E20: lwc1        $f16, 0xC($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0XC);
    // 0x80001E24: swc1        $f16, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f16.u32l;
    // 0x80001E28: bne         $a1, $a3, L_80001D84
    if (ctx->r5 != ctx->r7) {
        // 0x80001E2C: swc1        $f4, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
            goto L_80001D84;
    }
    // 0x80001E2C: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80001E30: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80001E34: addiu       $t2, $sp, 0x50
    ctx->r10 = ADD32(ctx->r29, 0X50);
    // 0x80001E38: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80001E3C: or          $t0, $t2, $zero
    ctx->r8 = ctx->r10 | 0;
    // 0x80001E40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80001E44: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80001E48: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80001E4C: addiu       $s4, $sp, 0x90
    ctx->r20 = ADD32(ctx->r29, 0X90);
    // 0x80001E50: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
L_80001E54:
    // 0x80001E54: lwc1        $f6, 0x0($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80001E58: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x80001E5C: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x80001E60: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x80001E64: beq         $at, $zero, L_80001F40
    if (ctx->r1 == 0) {
        // 0x80001E68: div.s       $f0, $f2, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f6.fl);
            goto L_80001F40;
    }
    // 0x80001E68: div.s       $f0, $f2, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80001E6C: subu        $s2, $s3, $t3
    ctx->r18 = SUB32(ctx->r19, ctx->r11);
    // 0x80001E70: andi        $t7, $s2, 0x3
    ctx->r15 = ctx->r18 & 0X3;
    // 0x80001E74: beq         $t7, $zero, L_80001EBC
    if (ctx->r15 == 0) {
        // 0x80001E78: addu        $v0, $t7, $t3
        ctx->r2 = ADD32(ctx->r15, ctx->r11);
            goto L_80001EBC;
    }
    // 0x80001E78: addu        $v0, $t7, $t3
    ctx->r2 = ADD32(ctx->r15, ctx->r11);
    // 0x80001E7C: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x80001E80: addu        $t4, $t0, $t8
    ctx->r12 = ADD32(ctx->r8, ctx->r24);
    // 0x80001E84: lwc1        $f16, 0x0($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80001E88: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80001E8C: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80001E90: beql        $v0, $v1, L_80001EB4
    if (ctx->r2 == ctx->r3) {
        // 0x80001E94: swc1        $f18, 0x0($t4)
        MEM_W(0X0, ctx->r12) = ctx->f18.u32l;
            goto L_80001EB4;
    }
    goto skip_2;
    // 0x80001E94: swc1        $f18, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f18.u32l;
    skip_2:
L_80001E98:
    // 0x80001E98: lwc1        $f16, 0x4($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X4);
    // 0x80001E9C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80001EA0: swc1        $f18, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f18.u32l;
    // 0x80001EA4: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80001EA8: bne         $v0, $v1, L_80001E98
    if (ctx->r2 != ctx->r3) {
        // 0x80001EAC: addiu       $t4, $t4, 0x4
        ctx->r12 = ADD32(ctx->r12, 0X4);
            goto L_80001E98;
    }
    // 0x80001EAC: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x80001EB0: swc1        $f18, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f18.u32l;
L_80001EB4:
    // 0x80001EB4: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x80001EB8: beq         $v1, $s3, L_80001F40
    if (ctx->r3 == ctx->r19) {
        // 0x80001EBC: sll         $t9, $v1, 2
        ctx->r25 = S32(ctx->r3 << 2);
            goto L_80001F40;
    }
L_80001EBC:
    // 0x80001EBC: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x80001EC0: addu        $t4, $t0, $t9
    ctx->r12 = ADD32(ctx->r8, ctx->r25);
    // 0x80001EC4: lwc1        $f8, 0x0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80001EC8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80001ECC: lwc1        $f18, 0x4($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X4);
    // 0x80001ED0: mul.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80001ED4: lwc1        $f16, 0x8($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X8);
    // 0x80001ED8: beq         $v1, $s3, L_80001F1C
    if (ctx->r3 == ctx->r19) {
        // 0x80001EDC: lwc1        $f14, 0xC($t4)
        ctx->f14.u32l = MEM_W(ctx->r12, 0XC);
            goto L_80001F1C;
    }
    // 0x80001EDC: lwc1        $f14, 0xC($t4)
    ctx->f14.u32l = MEM_W(ctx->r12, 0XC);
L_80001EE0:
    // 0x80001EE0: mul.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80001EE4: lwc1        $f8, 0x10($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X10);
    // 0x80001EE8: lwc1        $f18, 0x14($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X14);
    // 0x80001EEC: mul.s       $f6, $f16, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80001EF0: lwc1        $f16, 0x18($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X18);
    // 0x80001EF4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80001EF8: mul.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80001EFC: lwc1        $f14, 0x1C($t4)
    ctx->f14.u32l = MEM_W(ctx->r12, 0X1C);
    // 0x80001F00: swc1        $f12, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f12.u32l;
    // 0x80001F04: mul.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80001F08: swc1        $f10, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f10.u32l;
    // 0x80001F0C: swc1        $f6, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f6.u32l;
    // 0x80001F10: addiu       $t4, $t4, 0x10
    ctx->r12 = ADD32(ctx->r12, 0X10);
    // 0x80001F14: bne         $v1, $s3, L_80001EE0
    if (ctx->r3 != ctx->r19) {
        // 0x80001F18: swc1        $f4, -0x4($t4)
        MEM_W(-0X4, ctx->r12) = ctx->f4.u32l;
            goto L_80001EE0;
    }
    // 0x80001F18: swc1        $f4, -0x4($t4)
    MEM_W(-0X4, ctx->r12) = ctx->f4.u32l;
L_80001F1C:
    // 0x80001F1C: mul.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80001F20: swc1        $f12, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f12.u32l;
    // 0x80001F24: addiu       $t4, $t4, 0x10
    ctx->r12 = ADD32(ctx->r12, 0X10);
    // 0x80001F28: mul.s       $f6, $f16, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80001F2C: nop

    // 0x80001F30: mul.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80001F34: swc1        $f10, -0xC($t4)
    MEM_W(-0XC, ctx->r12) = ctx->f10.u32l;
    // 0x80001F38: swc1        $f6, -0x8($t4)
    MEM_W(-0X8, ctx->r12) = ctx->f6.u32l;
    // 0x80001F3C: swc1        $f4, -0x4($t4)
    MEM_W(-0X4, ctx->r12) = ctx->f4.u32l;
L_80001F40:
    // 0x80001F40: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80001F44: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80001F48: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80001F4C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80001F50: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80001F54: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x80001F58: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80001F5C: sll         $t6, $v1, 4
    ctx->r14 = S32(ctx->r3 << 4);
    // 0x80001F60: addiu       $t7, $sp, 0x50
    ctx->r15 = ADD32(ctx->r29, 0X50);
    // 0x80001F64: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80001F68: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
    // 0x80001F6C: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x80001F70: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80001F74: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x80001F78: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
    // 0x80001F7C: addu        $t5, $a1, $t1
    ctx->r13 = ADD32(ctx->r5, ctx->r9);
    // 0x80001F80: swc1        $f18, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f18.u32l;
    // 0x80001F84: sll         $t8, $v1, 4
    ctx->r24 = S32(ctx->r3 << 4);
    // 0x80001F88: beq         $at, $zero, L_8000214C
    if (ctx->r1 == 0) {
        // 0x80001F8C: swc1        $f6, 0xC($s1)
        MEM_W(0XC, ctx->r17) = ctx->f6.u32l;
            goto L_8000214C;
    }
    // 0x80001F8C: swc1        $f6, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f6.u32l;
    // 0x80001F90: addu        $v0, $a2, $t8
    ctx->r2 = ADD32(ctx->r6, ctx->r24);
L_80001F94:
    // 0x80001F94: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x80001F98: lwc1        $f0, 0x0($t5)
    ctx->f0.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80001F9C: beq         $at, $zero, L_800020EC
    if (ctx->r1 == 0) {
        // 0x80001FA0: or          $v1, $t3, $zero
        ctx->r3 = ctx->r11 | 0;
            goto L_800020EC;
    }
    // 0x80001FA0: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x80001FA4: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80001FA8: subu        $s2, $t9, $t3
    ctx->r18 = SUB32(ctx->r25, ctx->r11);
    // 0x80001FAC: andi        $t6, $s2, 0x3
    ctx->r14 = ctx->r18 & 0X3;
    // 0x80001FB0: beq         $t6, $zero, L_80002018
    if (ctx->r14 == 0) {
        // 0x80001FB4: addu        $s0, $t6, $t3
        ctx->r16 = ADD32(ctx->r14, ctx->r11);
            goto L_80002018;
    }
    // 0x80001FB4: addu        $s0, $t6, $t3
    ctx->r16 = ADD32(ctx->r14, ctx->r11);
    // 0x80001FB8: sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3 << 2);
    // 0x80001FBC: addu        $a3, $a1, $a0
    ctx->r7 = ADD32(ctx->r5, ctx->r4);
    // 0x80001FC0: addu        $t4, $t0, $a0
    ctx->r12 = ADD32(ctx->r8, ctx->r4);
    // 0x80001FC4: lwc1        $f14, 0x0($t4)
    ctx->f14.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80001FC8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80001FCC: lwc1        $f18, 0x0($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80001FD0: mul.s       $f16, $f0, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80001FD4: beql        $s0, $v1, L_80002008
    if (ctx->r16 == ctx->r3) {
        // 0x80001FD8: sub.s       $f14, $f18, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f16.fl;
            goto L_80002008;
    }
    goto skip_3;
    // 0x80001FD8: sub.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f16.fl;
    skip_3:
    // 0x80001FDC: sub.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f16.fl;
L_80001FE0:
    // 0x80001FE0: lwc1        $f18, 0x4($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80001FE4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80001FE8: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80001FEC: swc1        $f14, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->f14.u32l;
    // 0x80001FF0: lwc1        $f14, 0x4($t4)
    ctx->f14.u32l = MEM_W(ctx->r12, 0X4);
    // 0x80001FF4: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x80001FF8: mul.s       $f16, $f0, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80001FFC: bnel        $s0, $v1, L_80001FE0
    if (ctx->r16 != ctx->r3) {
        // 0x80002000: sub.s       $f14, $f18, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f16.fl;
            goto L_80001FE0;
    }
    goto skip_4;
    // 0x80002000: sub.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f16.fl;
    skip_4:
    // 0x80002004: sub.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f16.fl;
L_80002008:
    // 0x80002008: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8000200C: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x80002010: swc1        $f14, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->f14.u32l;
    // 0x80002014: beq         $v1, $s3, L_800020EC
    if (ctx->r3 == ctx->r19) {
        // 0x80002018: sll         $a0, $v1, 2
        ctx->r4 = S32(ctx->r3 << 2);
            goto L_800020EC;
    }
L_80002018:
    // 0x80002018: sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3 << 2);
    // 0x8000201C: addu        $a3, $a1, $a0
    ctx->r7 = ADD32(ctx->r5, ctx->r4);
    // 0x80002020: addu        $t4, $t0, $a0
    ctx->r12 = ADD32(ctx->r8, ctx->r4);
    // 0x80002024: lwc1        $f14, 0x0($t4)
    ctx->f14.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80002028: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000202C: lwc1        $f18, 0x0($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80002030: mul.s       $f16, $f0, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80002034: beql        $v1, $s3, L_800020A4
    if (ctx->r3 == ctx->r19) {
        // 0x80002038: sub.s       $f14, $f18, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f16.fl;
            goto L_800020A4;
    }
    goto skip_5;
    // 0x80002038: sub.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f16.fl;
    skip_5:
    // 0x8000203C: sub.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f16.fl;
L_80002040:
    // 0x80002040: lwc1        $f12, 0x4($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80002044: lwc1        $f10, 0x8($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80002048: lwc1        $f8, 0xC($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8000204C: swc1        $f14, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f14.u32l;
    // 0x80002050: lwc1        $f14, 0x4($t4)
    ctx->f14.u32l = MEM_W(ctx->r12, 0X4);
    // 0x80002054: lwc1        $f18, 0x10($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80002058: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000205C: mul.s       $f14, $f0, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80002060: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x80002064: addiu       $t4, $t4, 0x10
    ctx->r12 = ADD32(ctx->r12, 0X10);
    // 0x80002068: sub.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x8000206C: swc1        $f14, -0xC($a3)
    MEM_W(-0XC, ctx->r7) = ctx->f14.u32l;
    // 0x80002070: lwc1        $f14, -0x8($t4)
    ctx->f14.u32l = MEM_W(ctx->r12, -0X8);
    // 0x80002074: mul.s       $f14, $f0, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80002078: sub.s       $f14, $f10, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x8000207C: swc1        $f14, -0x8($a3)
    MEM_W(-0X8, ctx->r7) = ctx->f14.u32l;
    // 0x80002080: lwc1        $f14, -0x4($t4)
    ctx->f14.u32l = MEM_W(ctx->r12, -0X4);
    // 0x80002084: mul.s       $f14, $f0, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80002088: sub.s       $f14, $f8, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x8000208C: swc1        $f14, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->f14.u32l;
    // 0x80002090: lwc1        $f14, 0x0($t4)
    ctx->f14.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80002094: mul.s       $f16, $f0, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80002098: bnel        $v1, $s3, L_80002040
    if (ctx->r3 != ctx->r19) {
        // 0x8000209C: sub.s       $f14, $f18, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f16.fl;
            goto L_80002040;
    }
    goto skip_6;
    // 0x8000209C: sub.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f16.fl;
    skip_6:
    // 0x800020A0: sub.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f16.fl;
L_800020A4:
    // 0x800020A4: lwc1        $f12, 0x4($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X4);
    // 0x800020A8: lwc1        $f10, 0x8($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X8);
    // 0x800020AC: lwc1        $f8, 0xC($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800020B0: swc1        $f14, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f14.u32l;
    // 0x800020B4: lwc1        $f14, 0x4($t4)
    ctx->f14.u32l = MEM_W(ctx->r12, 0X4);
    // 0x800020B8: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x800020BC: addiu       $t4, $t4, 0x10
    ctx->r12 = ADD32(ctx->r12, 0X10);
    // 0x800020C0: mul.s       $f14, $f0, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x800020C4: sub.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x800020C8: swc1        $f14, -0xC($a3)
    MEM_W(-0XC, ctx->r7) = ctx->f14.u32l;
    // 0x800020CC: lwc1        $f14, -0x8($t4)
    ctx->f14.u32l = MEM_W(ctx->r12, -0X8);
    // 0x800020D0: mul.s       $f14, $f0, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x800020D4: sub.s       $f14, $f10, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x800020D8: swc1        $f14, -0x8($a3)
    MEM_W(-0X8, ctx->r7) = ctx->f14.u32l;
    // 0x800020DC: lwc1        $f14, -0x4($t4)
    ctx->f14.u32l = MEM_W(ctx->r12, -0X4);
    // 0x800020E0: mul.s       $f14, $f0, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x800020E4: sub.s       $f14, $f8, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x800020E8: swc1        $f14, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->f14.u32l;
L_800020EC:
    // 0x800020EC: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800020F0: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800020F4: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800020F8: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800020FC: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80002100: addiu       $t5, $t5, 0x10
    ctx->r13 = ADD32(ctx->r13, 0X10);
    // 0x80002104: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80002108: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8000210C: lwc1        $f4, -0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, -0X8);
    // 0x80002110: swc1        $f6, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f6.u32l;
    // 0x80002114: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80002118: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8000211C: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80002120: lwc1        $f16, -0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80002124: swc1        $f18, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f18.u32l;
    // 0x80002128: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8000212C: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80002130: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80002134: swc1        $f8, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f8.u32l;
    // 0x80002138: lwc1        $f18, 0xC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8000213C: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80002140: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x80002144: bne         $a1, $s4, L_80001F94
    if (ctx->r5 != ctx->r20) {
        // 0x80002148: swc1        $f4, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
            goto L_80001F94;
    }
    // 0x80002148: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
L_8000214C:
    // 0x8000214C: slti        $at, $t3, 0x3
    ctx->r1 = SIGNED(ctx->r11) < 0X3 ? 1 : 0;
    // 0x80002150: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x80002154: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x80002158: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x8000215C: addiu       $t2, $t2, 0x14
    ctx->r10 = ADD32(ctx->r10, 0X14);
    // 0x80002160: bne         $at, $zero, L_80001E54
    if (ctx->r1 != 0) {
        // 0x80002164: addiu       $s1, $s1, 0x10
        ctx->r17 = ADD32(ctx->r17, 0X10);
            goto L_80001E54;
    }
    // 0x80002164: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x80002168: lwc1        $f10, 0x8C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8000216C: lwc1        $f8, 0x30($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X30);
    // 0x80002170: lwc1        $f16, 0x34($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X34);
    // 0x80002174: div.s       $f0, $f2, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80002178: lwc1        $f4, 0x38($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X38);
    // 0x8000217C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80002180: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x80002184: mul.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80002188: lwc1        $f8, 0x3C($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X3C);
    // 0x8000218C: mul.s       $f6, $f16, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80002190: nop

    // 0x80002194: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80002198: swc1        $f18, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->f18.u32l;
    // 0x8000219C: mul.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800021A0: swc1        $f6, 0x34($a2)
    MEM_W(0X34, ctx->r6) = ctx->f6.u32l;
    // 0x800021A4: swc1        $f10, 0x38($a2)
    MEM_W(0X38, ctx->r6) = ctx->f10.u32l;
    // 0x800021A8: swc1        $f18, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->f18.u32l;
    // 0x800021AC: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
L_800021B0:
    // 0x800021B0: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x800021B4: beq         $at, $zero, L_800022C4
    if (ctx->r1 == 0) {
        // 0x800021B8: sll         $a0, $t3, 2
        ctx->r4 = S32(ctx->r11 << 2);
            goto L_800022C4;
    }
    // 0x800021B8: sll         $a0, $t3, 2
    ctx->r4 = S32(ctx->r11 << 2);
    // 0x800021BC: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x800021C0: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x800021C4: sll         $t7, $t3, 4
    ctx->r15 = S32(ctx->r11 << 4);
    // 0x800021C8: addiu       $t9, $sp, 0x50
    ctx->r25 = ADD32(ctx->r29, 0X50);
    // 0x800021CC: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x800021D0: addu        $s1, $a2, $t6
    ctx->r17 = ADD32(ctx->r6, ctx->r14);
    // 0x800021D4: addu        $t4, $t8, $t9
    ctx->r12 = ADD32(ctx->r24, ctx->r25);
    // 0x800021D8: addu        $a1, $a2, $t7
    ctx->r5 = ADD32(ctx->r6, ctx->r15);
    // 0x800021DC: lwc1        $f10, 0x0($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800021E0: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800021E4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800021E8: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800021EC: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800021F0: beql        $a0, $a3, L_80002270
    if (ctx->r4 == ctx->r7) {
        // 0x800021F4: sub.s       $f14, $f16, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
            goto L_80002270;
    }
    goto skip_7;
    // 0x800021F4: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    skip_7:
    // 0x800021F8: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
L_800021FC:
    // 0x800021FC: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80002200: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80002204: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80002208: swc1        $f14, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f14.u32l;
    // 0x8000220C: lwc1        $f14, 0x0($t4)
    ctx->f14.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80002210: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80002214: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80002218: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8000221C: mul.s       $f6, $f14, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x80002220: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x80002224: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80002228: sub.s       $f6, $f12, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f6.fl;
    // 0x8000222C: swc1        $f6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f6.u32l;
    // 0x80002230: lwc1        $f6, -0x4($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, -0X4);
    // 0x80002234: lwc1        $f12, -0x8($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, -0X8);
    // 0x80002238: mul.s       $f12, $f6, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8000223C: sub.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x80002240: swc1        $f12, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f12.u32l;
    // 0x80002244: lwc1        $f12, -0x4($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, -0X4);
    // 0x80002248: lwc1        $f10, -0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, -0X4);
    // 0x8000224C: mul.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x80002250: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80002254: swc1        $f10, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f10.u32l;
    // 0x80002258: lwc1        $f10, 0x0($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8000225C: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80002260: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80002264: bnel        $a0, $a3, L_800021FC
    if (ctx->r4 != ctx->r7) {
        // 0x80002268: sub.s       $f14, $f16, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
            goto L_800021FC;
    }
    goto skip_8;
    // 0x80002268: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    skip_8:
    // 0x8000226C: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
L_80002270:
    // 0x80002270: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80002274: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80002278: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x8000227C: swc1        $f14, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f14.u32l;
    // 0x80002280: lwc1        $f14, -0x4($t4)
    ctx->f14.u32l = MEM_W(ctx->r12, -0X4);
    // 0x80002284: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80002288: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8000228C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80002290: mul.s       $f6, $f14, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x80002294: sub.s       $f6, $f12, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f6.fl;
    // 0x80002298: swc1        $f6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f6.u32l;
    // 0x8000229C: lwc1        $f6, -0x4($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, -0X4);
    // 0x800022A0: lwc1        $f12, -0x8($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, -0X8);
    // 0x800022A4: mul.s       $f12, $f6, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800022A8: sub.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x800022AC: swc1        $f12, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f12.u32l;
    // 0x800022B0: lwc1        $f10, -0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, -0X4);
    // 0x800022B4: lwc1        $f12, -0x4($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, -0X4);
    // 0x800022B8: mul.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x800022BC: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800022C0: swc1        $f10, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f10.u32l;
L_800022C4:
    // 0x800022C4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800022C8: bgezl       $v0, L_800021B0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800022CC: addiu       $t3, $v0, 0x1
        ctx->r11 = ADD32(ctx->r2, 0X1);
            goto L_800021B0;
    }
    goto skip_9;
    // 0x800022CC: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    skip_9:
    // 0x800022D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800022D4:
    // 0x800022D4: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x800022D8: lw          $s1, 0x8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8);
    // 0x800022DC: lw          $s2, 0xC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC);
    // 0x800022E0: lw          $s3, 0x10($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X10);
    // 0x800022E4: lw          $s4, 0x14($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X14);
    // 0x800022E8: jr          $ra
    // 0x800022EC: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    TRACE_RETURN()
    return;
    // 0x800022EC: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void func_800022F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800022F0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800022F4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800022F8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800022FC: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
    // 0x80002300: swc1        $f0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f0.u32l;
    // 0x80002304: swc1        $f0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f0.u32l;
    // 0x80002308: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    // 0x8000230C: swc1        $f0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f0.u32l;
    // 0x80002310: swc1        $f0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f0.u32l;
    // 0x80002314: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x80002318: swc1        $f0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f0.u32l;
    // 0x8000231C: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x80002320: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x80002324: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x80002328: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x8000232C: swc1        $f2, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f2.u32l;
    // 0x80002330: swc1        $f2, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f2.u32l;
    // 0x80002334: swc1        $f2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f2.u32l;
    // 0x80002338: jr          $ra
    // 0x8000233C: swc1        $f2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f2.u32l;
    TRACE_RETURN()
    return;
    // 0x8000233C: swc1        $f2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f2.u32l;
;}
RECOMP_FUNC void func_80002340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80002340: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80002344: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80002348: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8000234C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80002350:
    // 0x80002350: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80002354: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80002358: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8000235C: swc1        $f4, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f4.u32l;
    // 0x80002360: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80002364: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80002368: swc1        $f6, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f6.u32l;
    // 0x8000236C: lwc1        $f8, -0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, -0X8);
    // 0x80002370: swc1        $f8, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f8.u32l;
    // 0x80002374: lwc1        $f10, -0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, -0X4);
    // 0x80002378: bne         $a2, $a0, L_80002350
    if (ctx->r6 != ctx->r4) {
        // 0x8000237C: swc1        $f10, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
            goto L_80002350;
    }
    // 0x8000237C: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x80002380: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80002388(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80002388: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x8000238C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80002390: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80002394: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80002398: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
L_8000239C:
    // 0x8000239C: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800023A0: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800023A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800023A8: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800023AC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800023B0: bc1t        L_800023BC
    if (c1cs) {
        // 0x800023B4: nop
    
            goto L_800023BC;
    }
    // 0x800023B4: nop

    // 0x800023B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800023BC:
    // 0x800023BC: beq         $a0, $zero, L_800023CC
    if (ctx->r4 == 0) {
        // 0x800023C0: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800023CC;
    }
    // 0x800023C0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800023C4: jr          $ra
    // 0x800023C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    TRACE_RETURN()
    return;
    // 0x800023C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800023CC:
    // 0x800023CC: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800023D0: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800023D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800023D8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800023DC: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x800023E0: nop

    // 0x800023E4: bc1t        L_800023F0
    if (c1cs) {
        // 0x800023E8: nop
    
            goto L_800023F0;
    }
    // 0x800023E8: nop

    // 0x800023EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800023F0:
    // 0x800023F0: beq         $a0, $zero, L_80002400
    if (ctx->r4 == 0) {
        // 0x800023F4: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80002400;
    }
    // 0x800023F4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800023F8: jr          $ra
    // 0x800023FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    TRACE_RETURN()
    return;
    // 0x800023FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80002400:
    // 0x80002400: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80002404: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80002408: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000240C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80002410: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x80002414: nop

    // 0x80002418: bc1t        L_80002424
    if (c1cs) {
        // 0x8000241C: nop
    
            goto L_80002424;
    }
    // 0x8000241C: nop

    // 0x80002420: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80002424:
    // 0x80002424: beq         $a0, $zero, L_80002434
    if (ctx->r4 == 0) {
        // 0x80002428: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80002434;
    }
    // 0x80002428: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000242C: jr          $ra
    // 0x80002430: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    TRACE_RETURN()
    return;
    // 0x80002430: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80002434:
    // 0x80002434: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80002438: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8000243C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80002440: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80002444: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80002448: nop

    // 0x8000244C: bc1t        L_80002458
    if (c1cs) {
        // 0x80002450: nop
    
            goto L_80002458;
    }
    // 0x80002450: nop

    // 0x80002454: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80002458:
    // 0x80002458: beq         $a0, $zero, L_80002468
    if (ctx->r4 == 0) {
        // 0x8000245C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80002468;
    }
    // 0x8000245C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80002460: jr          $ra
    // 0x80002464: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    TRACE_RETURN()
    return;
    // 0x80002464: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80002468:
    // 0x80002468: bnel        $a2, $a1, L_8000239C
    if (ctx->r6 != ctx->r5) {
        // 0x8000246C: lwc1        $f4, 0x0($v0)
        ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
            goto L_8000239C;
    }
    goto skip_0;
    // 0x8000246C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x80002470: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80002474: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000247C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000247C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80002480: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80002484: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80002488: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8000248C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80002490: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x80002494: jal         0x8000279C
    // 0x80002498: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_8000279C(rdram, ctx);
        goto after_0;
    // 0x80002498: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x8000249C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800024A0: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x800024A4: jal         0x80000FE4
    // 0x800024A8: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    func_80000FE4(rdram, ctx);
        goto after_1;
    // 0x800024A8: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x800024AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800024B0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800024B4: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800024BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800024BC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800024C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800024C4: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800024C8: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800024CC: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800024D0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800024D4: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800024D8: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800024DC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800024E0: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800024E4: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800024E8: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x800024EC: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800024F0: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800024F4: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800024F8: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800024FC: lwc1        $f4, 0x8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80002500: mul.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80002504: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80002508: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x8000250C: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80002510: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80002514: mul.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80002518: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8000251C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x80002520: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80002524: mul.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80002528: sub.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8000252C: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80002530: mul.s       $f4, $f10, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x80002534: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x80002538: mul.s       $f10, $f6, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8000253C: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80002540: mul.s       $f4, $f8, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x80002544: ldc1        $f8, 0x4878($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X4878);
    // 0x80002548: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8000254C: cvt.d.s     $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.d = CVT_D_S(ctx->f12.fl);
    // 0x80002550: c.lt.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d < ctx->f8.d;
    // 0x80002554: nop

    // 0x80002558: bc1fl       L_8000256C
    if (!c1cs) {
        // 0x8000255C: sw          $a1, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r5;
            goto L_8000256C;
    }
    goto skip_0;
    // 0x8000255C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    skip_0:
    // 0x80002560: b           L_8000278C
    // 0x80002564: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000278C;
    // 0x80002564: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80002568: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
L_8000256C:
    // 0x8000256C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80002570: jal         0x8004F640
    // 0x80002574: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    func_8004F640(rdram, ctx);
        goto after_0;
    // 0x80002574: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_0:
    // 0x80002578: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000257C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80002580: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80002584: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80002588: div.s       $f2, $f16, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8000258C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80002590: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80002594: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80002598: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8000259C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800025A0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800025A4: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800025A8: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800025AC: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800025B0: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x800025B4: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800025B8: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x800025BC: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x800025C0: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800025C4: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800025C8: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800025CC: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800025D0: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800025D4: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800025D8: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800025DC: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800025E0: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800025E4: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800025E8: add.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800025EC: c.le.s      $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl <= ctx->f18.fl;
    // 0x800025F0: nop

    // 0x800025F4: bc1f        L_80002610
    if (!c1cs) {
        // 0x800025F8: nop
    
            goto L_80002610;
    }
    // 0x800025F8: nop

    // 0x800025FC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80002600: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80002604: mov.s       $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = ctx->f18.fl;
    // 0x80002608: b           L_80002640
    // 0x8000260C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
        goto L_80002640;
    // 0x8000260C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_80002610:
    // 0x80002610: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80002614: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x80002618: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x8000261C: jal         0x8004F640
    // 0x80002620: sub.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f10.fl;
    func_8004F640(rdram, ctx);
        goto after_1;
    // 0x80002620: sub.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f10.fl;
    after_1:
    // 0x80002624: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80002628: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000262C: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80002630: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80002634: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80002638: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8000263C: sub.s       $f2, $f16, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f14.fl;
L_80002640:
    // 0x80002640: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80002644: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80002648: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8000264C: mul.s       $f8, $f4, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x80002650: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80002654: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80002658: mul.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8000265C: add.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f14.fl;
    // 0x80002660: swc1        $f10, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f10.u32l;
    // 0x80002664: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80002668: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8000266C: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80002670: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80002674: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80002678: nop

    // 0x8000267C: mul.s       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80002680: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80002684: swc1        $f6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f6.u32l;
    // 0x80002688: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8000268C: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80002690: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80002694: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80002698: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8000269C: nop

    // 0x800026A0: mul.s       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800026A4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800026A8: swc1        $f10, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f10.u32l;
    // 0x800026AC: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800026B0: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800026B4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800026B8: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800026BC: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800026C0: nop

    // 0x800026C4: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800026C8: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800026CC: swc1        $f8, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f8.u32l;
    // 0x800026D0: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800026D4: mul.s       $f10, $f4, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800026D8: nop

    // 0x800026DC: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800026E0: add.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f14.fl;
    // 0x800026E4: swc1        $f8, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f8.u32l;
    // 0x800026E8: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800026EC: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800026F0: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800026F4: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800026F8: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800026FC: nop

    // 0x80002700: mul.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80002704: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80002708: swc1        $f6, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f6.u32l;
    // 0x8000270C: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80002710: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80002714: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80002718: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8000271C: mul.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80002720: nop

    // 0x80002724: mul.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80002728: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8000272C: swc1        $f8, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f8.u32l;
    // 0x80002730: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80002734: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80002738: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8000273C: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80002740: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80002744: nop

    // 0x80002748: mul.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8000274C: sub.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80002750: swc1        $f6, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->f6.u32l;
    // 0x80002754: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80002758: mul.s       $f8, $f4, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8000275C: nop

    // 0x80002760: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80002764: add.s       $f6, $f10, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x80002768: swc1        $f6, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->f6.u32l;
L_8000276C:
    // 0x8000276C: swc1        $f0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f0.u32l;
    // 0x80002770: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80002774: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x80002778: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000277C: bne         $v0, $a1, L_8000276C
    if (ctx->r2 != ctx->r5) {
        // 0x80002780: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_8000276C;
    }
    // 0x80002780: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80002784: swc1        $f16, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f16.u32l;
    // 0x80002788: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000278C:
    // 0x8000278C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80002790: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80002794: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000279C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000279C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800027A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800027A4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800027A8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800027AC: jal         0x8000399C
    // 0x800027B0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_8000399C(rdram, ctx);
        goto after_0;
    // 0x800027B0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x800027B4: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800027B8: jal         0x8000399C
    // 0x800027BC: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_8000399C(rdram, ctx);
        goto after_1;
    // 0x800027BC: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x800027C0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800027C4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x800027C8: jal         0x800024BC
    // 0x800027CC: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    func_800024BC(rdram, ctx);
        goto after_2;
    // 0x800027CC: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_2:
    // 0x800027D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800027D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800027D8: jr          $ra
    TRACE_RETURN()
    return;
;}
