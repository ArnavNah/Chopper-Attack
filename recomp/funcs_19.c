#include "recomp.h"
#include "trace.h"
#include "funcs.h"

RECOMP_FUNC void func_800444F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800444F8: beq         $a0, $zero, L_8004450C
    if (ctx->r4 == 0) {
        // 0x800444FC: nop
    
            goto L_8004450C;
    }
    // 0x800444FC: nop

    // 0x80044500: lh          $t6, 0x8($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X8);
    // 0x80044504: ori         $t7, $t6, 0x4
    ctx->r15 = ctx->r14 | 0X4;
    // 0x80044508: sh          $t7, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r15;
L_8004450C:
    // 0x8004450C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80044514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80044514: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80044518: lh          $t7, -0x6458($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X6458);
    // 0x8004451C: sll         $a1, $a0, 16
    ctx->r5 = S32(ctx->r4 << 16);
    // 0x80044520: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80044524: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80044528: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004452C: beq         $t6, $t7, L_8004454C
    if (ctx->r14 == ctx->r15) {
        // 0x80044530: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8004454C;
    }
    // 0x80044530: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80044534: andi        $a0, $t6, 0xFFFF
    ctx->r4 = ctx->r14 & 0XFFFF;
    // 0x80044538: jal         0x800083EC
    // 0x8004453C: sh          $t6, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r14;
    func_800083EC(rdram, ctx);
        goto after_0;
    // 0x8004453C: sh          $t6, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r14;
    after_0:
    // 0x80044540: lh          $a1, 0x1A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X1A);
    // 0x80044544: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80044548: sh          $a1, -0x6458($at)
    MEM_H(-0X6458, ctx->r1) = ctx->r5;
L_8004454C:
    // 0x8004454C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80044550: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80044554: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8004455C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004455C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80044560: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80044564: lw          $t6, -0x6460($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6460);
    // 0x80044568: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004456C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80044570: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80044574: lw          $s0, 0x0($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X0);
    // 0x80044578: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8004457C: beql        $t7, $zero, L_80044604
    if (ctx->r15 == 0) {
        // 0x80044580: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80044604;
    }
    goto skip_0;
    // 0x80044580: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80044584: lh          $v1, 0x8($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X8);
L_80044588:
    // 0x80044588: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x8004458C: andi        $t8, $v1, 0x2
    ctx->r24 = ctx->r3 & 0X2;
    // 0x80044590: beq         $t8, $zero, L_800445B0
    if (ctx->r24 == 0) {
        // 0x80044594: andi        $t9, $v1, 0x4
        ctx->r25 = ctx->r3 & 0X4;
            goto L_800445B0;
    }
    // 0x80044594: andi        $t9, $v1, 0x4
    ctx->r25 = ctx->r3 & 0X4;
    // 0x80044598: beql        $t9, $zero, L_800445F4
    if (ctx->r25 == 0) {
        // 0x8004459C: lw          $t3, 0x0($s1)
        ctx->r11 = MEM_W(ctx->r17, 0X0);
            goto L_800445F4;
    }
    goto skip_1;
    // 0x8004459C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    skip_1:
    // 0x800445A0: jal         0x80044348
    // 0x800445A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80044348(rdram, ctx);
        goto after_0;
    // 0x800445A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800445A8: b           L_800445F4
    // 0x800445AC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
        goto L_800445F4;
    // 0x800445AC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
L_800445B0:
    // 0x800445B0: lh          $v0, 0xE($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XE);
    // 0x800445B4: beq         $v0, $zero, L_800445C4
    if (ctx->r2 == 0) {
        // 0x800445B8: addiu       $t0, $v0, -0x1
        ctx->r8 = ADD32(ctx->r2, -0X1);
            goto L_800445C4;
    }
    // 0x800445B8: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x800445BC: b           L_800445F0
    // 0x800445C0: sh          $t0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r8;
        goto L_800445F0;
    // 0x800445C0: sh          $t0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r8;
L_800445C4:
    // 0x800445C4: jal         0x8004427C
    // 0x800445C8: lh          $a0, 0xA($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XA);
    func_8004427C(rdram, ctx);
        goto after_1;
    // 0x800445C8: lh          $a0, 0xA($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XA);
    after_1:
    // 0x800445CC: lh          $v1, 0x8($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X8);
    // 0x800445D0: sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
    // 0x800445D4: andi        $t1, $v1, 0x1
    ctx->r9 = ctx->r3 & 0X1;
    // 0x800445D8: beq         $t1, $zero, L_800445E8
    if (ctx->r9 == 0) {
        // 0x800445DC: ori         $t2, $v1, 0x2
        ctx->r10 = ctx->r3 | 0X2;
            goto L_800445E8;
    }
    // 0x800445DC: ori         $t2, $v1, 0x2
    ctx->r10 = ctx->r3 | 0X2;
    // 0x800445E0: b           L_800445F0
    // 0x800445E4: sh          $t2, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r10;
        goto L_800445F0;
    // 0x800445E4: sh          $t2, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r10;
L_800445E8:
    // 0x800445E8: jal         0x80044348
    // 0x800445EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80044348(rdram, ctx);
        goto after_2;
    // 0x800445EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_800445F0:
    // 0x800445F0: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
L_800445F4:
    // 0x800445F4: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800445F8: bnel        $t3, $zero, L_80044588
    if (ctx->r11 != 0) {
        // 0x800445FC: lh          $v1, 0x8($s0)
        ctx->r3 = MEM_H(ctx->r16, 0X8);
            goto L_80044588;
    }
    goto skip_2;
    // 0x800445FC: lh          $v1, 0x8($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X8);
    skip_2:
    // 0x80044600: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80044604:
    // 0x80044604: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80044608: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8004460C: jr          $ra
    // 0x80044610: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    TRACE_RETURN()
    return;
    // 0x80044610: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80044614(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80044614: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80044618: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004461C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80044620: lh          $t8, 0xB4($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XB4);
    // 0x80044624: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80044628: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8004462C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80044630: beq         $t8, $zero, L_80044648
    if (ctx->r24 == 0) {
        // 0x80044634: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80044648;
    }
    // 0x80044634: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80044638: lh          $t9, 0xB6($a0)
    ctx->r25 = MEM_H(ctx->r4, 0XB6);
    // 0x8004463C: slt         $at, $t9, $t7
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80044640: beql        $at, $zero, L_8004471C
    if (ctx->r1 == 0) {
        // 0x80044644: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004471C;
    }
    goto skip_0;
    // 0x80044644: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_80044648:
    // 0x80044648: lh          $t2, 0x110($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X110);
    // 0x8004464C: lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // 0x80044650: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x80044654: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80044658: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x8004465C: addu        $v1, $v1, $t3
    ctx->r3 = ADD32(ctx->r3, ctx->r11);
    // 0x80044660: lh          $v1, -0x5230($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X5230);
    // 0x80044664: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x80044668: lw          $v0, -0x5254($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5254);
    // 0x8004466C: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x80044670: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x80044674: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x80044678: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x8004467C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x80044680: sh          $a1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r5;
    // 0x80044684: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80044688: jal         0x8000E35C
    // 0x8004468C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_8000E35C(rdram, ctx);
        goto after_0;
    // 0x8004468C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80044690: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80044694: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80044698: lh          $t1, 0x3E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3E);
    // 0x8004469C: and         $t8, $v0, $t7
    ctx->r24 = ctx->r2 & ctx->r15;
    // 0x800446A0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800446A4: addu        $v1, $a0, $t9
    ctx->r3 = ADD32(ctx->r4, ctx->r25);
    // 0x800446A8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800446AC: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800446B0: lh          $a2, 0x4($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X4);
    // 0x800446B4: lbu         $a1, 0x6($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X6);
    // 0x800446B8: bne         $t1, $at, L_800446EC
    if (ctx->r9 != ctx->r1) {
        // 0x800446BC: lbu         $t0, 0x7($v1)
        ctx->r8 = MEM_BU(ctx->r3, 0X7);
            goto L_800446EC;
    }
    // 0x800446BC: lbu         $t0, 0x7($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X7);
    // 0x800446C0: lh          $v0, 0x110($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X110);
    // 0x800446C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800446C8: beq         $v0, $at, L_800446E0
    if (ctx->r2 == ctx->r1) {
        // 0x800446CC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800446E0;
    }
    // 0x800446CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800446D0: beq         $v0, $at, L_800446E8
    if (ctx->r2 == ctx->r1) {
        // 0x800446D4: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_800446E8;
    }
    // 0x800446D4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800446D8: bnel        $v0, $at, L_800446F0
    if (ctx->r2 != ctx->r1) {
        // 0x800446DC: sll         $a0, $a2, 16
        ctx->r4 = S32(ctx->r6 << 16);
            goto L_800446F0;
    }
    goto skip_1;
    // 0x800446DC: sll         $a0, $a2, 16
    ctx->r4 = S32(ctx->r6 << 16);
    skip_1:
L_800446E0:
    // 0x800446E0: b           L_800446EC
    // 0x800446E4: addiu       $a2, $zero, 0x62
    ctx->r6 = ADD32(0, 0X62);
        goto L_800446EC;
    // 0x800446E4: addiu       $a2, $zero, 0x62
    ctx->r6 = ADD32(0, 0X62);
L_800446E8:
    // 0x800446E8: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
L_800446EC:
    // 0x800446EC: sll         $a0, $a2, 16
    ctx->r4 = S32(ctx->r6 << 16);
L_800446F0:
    // 0x800446F0: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800446F4: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800446F8: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800446FC: jal         0x800443A8
    // 0x80044700: sh          $t0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r8;
    func_800443A8(rdram, ctx);
        goto after_1;
    // 0x80044700: sh          $t0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r8;
    after_1:
    // 0x80044704: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80044708: lh          $t0, 0x1E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X1E);
    // 0x8004470C: sh          $t0, 0xB4($a3)
    MEM_H(0XB4, ctx->r7) = ctx->r8;
    // 0x80044710: lh          $t3, 0x3E($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X3E);
    // 0x80044714: sh          $t3, 0xB6($a3)
    MEM_H(0XB6, ctx->r7) = ctx->r11;
    // 0x80044718: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8004471C:
    // 0x8004471C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80044720: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80044728(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80044728: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004472C: sll         $a1, $a0, 16
    ctx->r5 = S32(ctx->r4 << 16);
    // 0x80044730: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80044734: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80044738: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x8004473C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80044740: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80044744: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x80044748: jal         0x80044514
    // 0x8004474C: lh          $a0, -0x5230($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X5230);
    func_80044514(rdram, ctx);
        goto after_0;
    // 0x8004474C: lh          $a0, -0x5230($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X5230);
    after_0:
    // 0x80044750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80044754: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80044758: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80044760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80044760: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80044764: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80044768: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8004476C: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x80044770: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80044774: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80044778: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8004477C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80044780: addiu       $a1, $a1, -0x5210
    ctx->r5 = ADD32(ctx->r5, -0X5210);
    // 0x80044784: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80044788: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004478C: jal         0x80049660
    // 0x80044790: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_80049660(rdram, ctx);
        goto after_0;
    // 0x80044790: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_0:
    // 0x80044794: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80044798: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004479C: jal         0x8004C388
    // 0x800447A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004C388(rdram, ctx);
        goto after_1;
    // 0x800447A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x800447A4: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x800447A8: addiu       $a2, $a2, 0x78EC
    ctx->r6 = ADD32(ctx->r6, 0X78EC);
    // 0x800447AC: addiu       $a0, $zero, -0xFF
    ctx->r4 = ADD32(0, -0XFF);
    // 0x800447B0: jal         0x8004BCF0
    // 0x800447B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8004BCF0(rdram, ctx);
        goto after_2;
    // 0x800447B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x800447B8: jal         0x8000798C
    // 0x800447BC: nop

    func_8000798C(rdram, ctx);
        goto after_3;
    // 0x800447BC: nop

    after_3:
    // 0x800447C0: jal         0x8000BD64
    // 0x800447C4: nop

    func_8000BD64(rdram, ctx);
        goto after_4;
    // 0x800447C4: nop

    after_4:
    // 0x800447C8: addiu       $s1, $sp, 0x28
    ctx->r17 = ADD32(ctx->r29, 0X28);
    // 0x800447CC: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
L_800447D0:
    // 0x800447D0: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    // 0x800447D4: jal         0x8000BD4C
    // 0x800447D8: addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
    func_8000BD4C(rdram, ctx);
        goto after_5;
    // 0x800447D8: addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
    after_5:
    // 0x800447DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800447E0: sh          $zero, -0x2CC4($at)
    MEM_H(-0X2CC4, ctx->r1) = 0;
    // 0x800447E4: jal         0x800496B4
    // 0x800447E8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_800496B4(rdram, ctx);
        goto after_6;
    // 0x800447E8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_6:
    // 0x800447EC: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800447F0: lhu         $t7, -0x2E5A($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X2E5A);
    // 0x800447F4: lh          $t9, 0x3C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X3C);
    // 0x800447F8: andi        $t8, $t7, 0x1000
    ctx->r24 = ctx->r15 & 0X1000;
    // 0x800447FC: beq         $t8, $zero, L_80044AF0
    if (ctx->r24 == 0) {
        // 0x80044800: addiu       $t0, $t9, -0x1
        ctx->r8 = ADD32(ctx->r25, -0X1);
            goto L_80044AF0;
    }
    // 0x80044800: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80044804: sltiu       $at, $t0, 0x9
    ctx->r1 = ctx->r8 < 0X9 ? 1 : 0;
    // 0x80044808: beq         $at, $zero, L_80044AF0
    if (ctx->r1 == 0) {
        // 0x8004480C: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80044AF0;
    }
    // 0x8004480C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80044810: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80044814: addu        $at, $at, $t0
    gpr jr_addend_8004481C = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80044818: lw          $t0, 0x7E48($at)
    ctx->r8 = ADD32(ctx->r1, 0X7E48);
    // 0x8004481C: jr          $t0
    // 0x80044820: nop

    switch (jr_addend_8004481C >> 2) {
        case 0: goto L_80044824; break;
        case 1: goto L_80044878; break;
        case 2: goto L_800448CC; break;
        case 3: goto L_80044920; break;
        case 4: goto L_80044974; break;
        case 5: goto L_800449C8; break;
        case 6: goto L_80044A1C; break;
        case 7: goto L_80044A70; break;
        case 8: goto L_80044AC4; break;
        default: switch_error(__func__, 0x8004481C, 0x80077E48);
    }
    // 0x80044820: nop

L_80044824:
    // 0x80044824: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80044828: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8004482C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80044830: addiu       $a0, $a0, 0x7928
    ctx->r4 = ADD32(ctx->r4, 0X7928);
    // 0x80044834: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80044838: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8004483C: jal         0x80004CE0
    // 0x80044840: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_80004CE0(rdram, ctx);
        goto after_7;
    // 0x80044840: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_7:
    // 0x80044844: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80044848: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8004484C: beq         $t2, $zero, L_80044868
    if (ctx->r10 == 0) {
        // 0x80044850: nop
    
            goto L_80044868;
    }
    // 0x80044850: nop

L_80044854:
    // 0x80044854: jal         0x8000798C
    // 0x80044858: nop

    func_8000798C(rdram, ctx);
        goto after_8;
    // 0x80044858: nop

    after_8:
    // 0x8004485C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80044860: bne         $t3, $zero, L_80044854
    if (ctx->r11 != 0) {
        // 0x80044864: nop
    
            goto L_80044854;
    }
    // 0x80044864: nop

L_80044868:
    // 0x80044868: jal         0x80004E5C
    // 0x8004486C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80004E5C(rdram, ctx);
        goto after_9;
    // 0x8004486C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80044870: b           L_80044AF4
    // 0x80044874: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80044AF4;
    // 0x80044874: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80044878:
    // 0x80044878: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8004487C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80044880: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x80044884: addiu       $a0, $a0, 0x534C
    ctx->r4 = ADD32(ctx->r4, 0X534C);
    // 0x80044888: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x8004488C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80044890: jal         0x80004CE0
    // 0x80044894: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_80004CE0(rdram, ctx);
        goto after_10;
    // 0x80044894: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_10:
    // 0x80044898: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8004489C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800448A0: beq         $t5, $zero, L_800448BC
    if (ctx->r13 == 0) {
        // 0x800448A4: nop
    
            goto L_800448BC;
    }
    // 0x800448A4: nop

L_800448A8:
    // 0x800448A8: jal         0x8000798C
    // 0x800448AC: nop

    func_8000798C(rdram, ctx);
        goto after_11;
    // 0x800448AC: nop

    after_11:
    // 0x800448B0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800448B4: bne         $t6, $zero, L_800448A8
    if (ctx->r14 != 0) {
        // 0x800448B8: nop
    
            goto L_800448A8;
    }
    // 0x800448B8: nop

L_800448BC:
    // 0x800448BC: jal         0x80004E5C
    // 0x800448C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80004E5C(rdram, ctx);
        goto after_12;
    // 0x800448C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x800448C4: b           L_80044AF4
    // 0x800448C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80044AF4;
    // 0x800448C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800448CC:
    // 0x800448CC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800448D0: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x800448D4: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x800448D8: addiu       $a0, $a0, -0x7C68
    ctx->r4 = ADD32(ctx->r4, -0X7C68);
    // 0x800448DC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x800448E0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x800448E4: jal         0x80004CE0
    // 0x800448E8: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_80004CE0(rdram, ctx);
        goto after_13;
    // 0x800448E8: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_13:
    // 0x800448EC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800448F0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800448F4: beq         $t8, $zero, L_80044910
    if (ctx->r24 == 0) {
        // 0x800448F8: nop
    
            goto L_80044910;
    }
    // 0x800448F8: nop

L_800448FC:
    // 0x800448FC: jal         0x8000798C
    // 0x80044900: nop

    func_8000798C(rdram, ctx);
        goto after_14;
    // 0x80044900: nop

    after_14:
    // 0x80044904: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80044908: bne         $t9, $zero, L_800448FC
    if (ctx->r25 != 0) {
        // 0x8004490C: nop
    
            goto L_800448FC;
    }
    // 0x8004490C: nop

L_80044910:
    // 0x80044910: jal         0x80004E5C
    // 0x80044914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80004E5C(rdram, ctx);
        goto after_15;
    // 0x80044914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80044918: b           L_80044AF4
    // 0x8004491C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80044AF4;
    // 0x8004491C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80044920:
    // 0x80044920: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80044924: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80044928: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8004492C: addiu       $a0, $a0, 0x4FE8
    ctx->r4 = ADD32(ctx->r4, 0X4FE8);
    // 0x80044930: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80044934: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80044938: jal         0x80004CE0
    // 0x8004493C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_80004CE0(rdram, ctx);
        goto after_16;
    // 0x8004493C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_16:
    // 0x80044940: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80044944: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80044948: beq         $t1, $zero, L_80044964
    if (ctx->r9 == 0) {
        // 0x8004494C: nop
    
            goto L_80044964;
    }
    // 0x8004494C: nop

L_80044950:
    // 0x80044950: jal         0x8000798C
    // 0x80044954: nop

    func_8000798C(rdram, ctx);
        goto after_17;
    // 0x80044954: nop

    after_17:
    // 0x80044958: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8004495C: bne         $t2, $zero, L_80044950
    if (ctx->r10 != 0) {
        // 0x80044960: nop
    
            goto L_80044950;
    }
    // 0x80044960: nop

L_80044964:
    // 0x80044964: jal         0x80004E5C
    // 0x80044968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80004E5C(rdram, ctx);
        goto after_18;
    // 0x80044968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x8004496C: b           L_80044AF4
    // 0x80044970: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80044AF4;
    // 0x80044970: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80044974:
    // 0x80044974: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80044978: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8004497C: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x80044980: addiu       $a0, $a0, 0x5850
    ctx->r4 = ADD32(ctx->r4, 0X5850);
    // 0x80044984: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80044988: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8004498C: jal         0x80004CE0
    // 0x80044990: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_80004CE0(rdram, ctx);
        goto after_19;
    // 0x80044990: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_19:
    // 0x80044994: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80044998: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8004499C: beq         $t4, $zero, L_800449B8
    if (ctx->r12 == 0) {
        // 0x800449A0: nop
    
            goto L_800449B8;
    }
    // 0x800449A0: nop

L_800449A4:
    // 0x800449A4: jal         0x8000798C
    // 0x800449A8: nop

    func_8000798C(rdram, ctx);
        goto after_20;
    // 0x800449A8: nop

    after_20:
    // 0x800449AC: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800449B0: bne         $t5, $zero, L_800449A4
    if (ctx->r13 != 0) {
        // 0x800449B4: nop
    
            goto L_800449A4;
    }
    // 0x800449B4: nop

L_800449B8:
    // 0x800449B8: jal         0x80004E5C
    // 0x800449BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80004E5C(rdram, ctx);
        goto after_21;
    // 0x800449BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x800449C0: b           L_80044AF4
    // 0x800449C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80044AF4;
    // 0x800449C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800449C8:
    // 0x800449C8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800449CC: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800449D0: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x800449D4: addiu       $a0, $a0, 0x5914
    ctx->r4 = ADD32(ctx->r4, 0X5914);
    // 0x800449D8: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x800449DC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x800449E0: jal         0x80004CE0
    // 0x800449E4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_80004CE0(rdram, ctx);
        goto after_22;
    // 0x800449E4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_22:
    // 0x800449E8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800449EC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800449F0: beq         $t7, $zero, L_80044A0C
    if (ctx->r15 == 0) {
        // 0x800449F4: nop
    
            goto L_80044A0C;
    }
    // 0x800449F4: nop

L_800449F8:
    // 0x800449F8: jal         0x8000798C
    // 0x800449FC: nop

    func_8000798C(rdram, ctx);
        goto after_23;
    // 0x800449FC: nop

    after_23:
    // 0x80044A00: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80044A04: bne         $t8, $zero, L_800449F8
    if (ctx->r24 != 0) {
        // 0x80044A08: nop
    
            goto L_800449F8;
    }
    // 0x80044A08: nop

L_80044A0C:
    // 0x80044A0C: jal         0x80004E5C
    // 0x80044A10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80004E5C(rdram, ctx);
        goto after_24;
    // 0x80044A10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80044A14: b           L_80044AF4
    // 0x80044A18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80044AF4;
    // 0x80044A18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80044A1C:
    // 0x80044A1C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80044A20: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80044A24: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x80044A28: addiu       $a0, $a0, 0x6928
    ctx->r4 = ADD32(ctx->r4, 0X6928);
    // 0x80044A2C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80044A30: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80044A34: jal         0x80004CE0
    // 0x80044A38: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_80004CE0(rdram, ctx);
        goto after_25;
    // 0x80044A38: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_25:
    // 0x80044A3C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80044A40: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80044A44: beq         $t0, $zero, L_80044A60
    if (ctx->r8 == 0) {
        // 0x80044A48: nop
    
            goto L_80044A60;
    }
    // 0x80044A48: nop

L_80044A4C:
    // 0x80044A4C: jal         0x8000798C
    // 0x80044A50: nop

    func_8000798C(rdram, ctx);
        goto after_26;
    // 0x80044A50: nop

    after_26:
    // 0x80044A54: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80044A58: bne         $t1, $zero, L_80044A4C
    if (ctx->r9 != 0) {
        // 0x80044A5C: nop
    
            goto L_80044A4C;
    }
    // 0x80044A5C: nop

L_80044A60:
    // 0x80044A60: jal         0x80004E5C
    // 0x80044A64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80004E5C(rdram, ctx);
        goto after_27;
    // 0x80044A64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x80044A68: b           L_80044AF4
    // 0x80044A6C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80044AF4;
    // 0x80044A6C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80044A70:
    // 0x80044A70: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80044A74: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80044A78: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x80044A7C: addiu       $a0, $a0, 0x4C34
    ctx->r4 = ADD32(ctx->r4, 0X4C34);
    // 0x80044A80: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80044A84: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80044A88: jal         0x80004CE0
    // 0x80044A8C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_80004CE0(rdram, ctx);
        goto after_28;
    // 0x80044A8C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_28:
    // 0x80044A90: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80044A94: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80044A98: beq         $t3, $zero, L_80044AB4
    if (ctx->r11 == 0) {
        // 0x80044A9C: nop
    
            goto L_80044AB4;
    }
    // 0x80044A9C: nop

L_80044AA0:
    // 0x80044AA0: jal         0x8000798C
    // 0x80044AA4: nop

    func_8000798C(rdram, ctx);
        goto after_29;
    // 0x80044AA4: nop

    after_29:
    // 0x80044AA8: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80044AAC: bne         $t4, $zero, L_80044AA0
    if (ctx->r12 != 0) {
        // 0x80044AB0: nop
    
            goto L_80044AA0;
    }
    // 0x80044AB0: nop

L_80044AB4:
    // 0x80044AB4: jal         0x80004E5C
    // 0x80044AB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80004E5C(rdram, ctx);
        goto after_30;
    // 0x80044AB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x80044ABC: b           L_80044AF4
    // 0x80044AC0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80044AF4;
    // 0x80044AC0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80044AC4:
    // 0x80044AC4: jal         0x8000BDA8
    // 0x80044AC8: nop

    func_8000BDA8(rdram, ctx);
        goto after_31;
    // 0x80044AC8: nop

    after_31:
    // 0x80044ACC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80044AD0: jal         0x8004C4D8
    // 0x80044AD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004C4D8(rdram, ctx);
        goto after_32;
    // 0x80044AD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_32:
    // 0x80044AD8: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80044ADC: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
L_80044AE0:
    // 0x80044AE0: jal         0x8000798C
    // 0x80044AE4: nop

    func_8000798C(rdram, ctx);
        goto after_33;
    // 0x80044AE4: nop

    after_33:
    // 0x80044AE8: b           L_80044AE0
    // 0x80044AEC: nop

        goto L_80044AE0;
    // 0x80044AEC: nop

L_80044AF0:
    // 0x80044AF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80044AF4:
    // 0x80044AF4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80044AF8: jal         0x8004C388
    // 0x80044AFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004C388(rdram, ctx);
        goto after_34;
    // 0x80044AFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_34:
    // 0x80044B00: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80044B04: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80044B08: lh          $a3, -0x2E60($a3)
    ctx->r7 = MEM_H(ctx->r7, -0X2E60);
    // 0x80044B0C: addiu       $a2, $a2, 0x78FC
    ctx->r6 = ADD32(ctx->r6, 0X78FC);
    // 0x80044B10: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80044B14: jal         0x8004C340
    // 0x80044B18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004C340(rdram, ctx);
        goto after_35;
    // 0x80044B18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_35:
    // 0x80044B1C: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80044B20: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80044B24: lh          $a3, -0x2E5E($a3)
    ctx->r7 = MEM_H(ctx->r7, -0X2E5E);
    // 0x80044B28: addiu       $a2, $a2, 0x790C
    ctx->r6 = ADD32(ctx->r6, 0X790C);
    // 0x80044B2C: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80044B30: jal         0x8004C340
    // 0x80044B34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004C340(rdram, ctx);
        goto after_36;
    // 0x80044B34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_36:
    // 0x80044B38: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80044B3C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80044B40: lh          $a3, -0x2E56($a3)
    ctx->r7 = MEM_H(ctx->r7, -0X2E56);
    // 0x80044B44: addiu       $a2, $a2, 0x791C
    ctx->r6 = ADD32(ctx->r6, 0X791C);
    // 0x80044B48: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80044B4C: jal         0x8004C340
    // 0x80044B50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004C340(rdram, ctx);
        goto after_37;
    // 0x80044B50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_37:
    // 0x80044B54: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80044B58: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80044B5C: lh          $a3, -0x2E54($a3)
    ctx->r7 = MEM_H(ctx->r7, -0X2E54);
    // 0x80044B60: addiu       $a2, $a2, 0x792C
    ctx->r6 = ADD32(ctx->r6, 0X792C);
    // 0x80044B64: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80044B68: jal         0x8004C340
    // 0x80044B6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004C340(rdram, ctx);
        goto after_38;
    // 0x80044B6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_38:
    // 0x80044B70: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80044B74: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80044B78: lh          $a3, -0x2E52($a3)
    ctx->r7 = MEM_H(ctx->r7, -0X2E52);
    // 0x80044B7C: addiu       $a2, $a2, 0x793C
    ctx->r6 = ADD32(ctx->r6, 0X793C);
    // 0x80044B80: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80044B84: jal         0x8004C340
    // 0x80044B88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004C340(rdram, ctx);
        goto after_39;
    // 0x80044B88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_39:
    // 0x80044B8C: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80044B90: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80044B94: lh          $a3, -0x2E50($a3)
    ctx->r7 = MEM_H(ctx->r7, -0X2E50);
    // 0x80044B98: addiu       $a2, $a2, 0x794C
    ctx->r6 = ADD32(ctx->r6, 0X794C);
    // 0x80044B9C: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80044BA0: jal         0x8004C340
    // 0x80044BA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004C340(rdram, ctx);
        goto after_40;
    // 0x80044BA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_40:
    // 0x80044BA8: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80044BAC: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80044BB0: lhu         $a3, -0x2E5C($a3)
    ctx->r7 = MEM_HU(ctx->r7, -0X2E5C);
    // 0x80044BB4: addiu       $a2, $a2, 0x795C
    ctx->r6 = ADD32(ctx->r6, 0X795C);
    // 0x80044BB8: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80044BBC: jal         0x8004C340
    // 0x80044BC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004C340(rdram, ctx);
        goto after_41;
    // 0x80044BC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_41:
    // 0x80044BC4: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80044BC8: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80044BCC: lhu         $a3, -0x2E5A($a3)
    ctx->r7 = MEM_HU(ctx->r7, -0X2E5A);
    // 0x80044BD0: addiu       $a2, $a2, 0x796C
    ctx->r6 = ADD32(ctx->r6, 0X796C);
    // 0x80044BD4: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80044BD8: jal         0x8004C340
    // 0x80044BDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004C340(rdram, ctx);
        goto after_42;
    // 0x80044BDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_42:
    // 0x80044BE0: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80044BE4: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80044BE8: lhu         $a3, -0x2E58($a3)
    ctx->r7 = MEM_HU(ctx->r7, -0X2E58);
    // 0x80044BEC: addiu       $a2, $a2, 0x797C
    ctx->r6 = ADD32(ctx->r6, 0X797C);
    // 0x80044BF0: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80044BF4: jal         0x8004C340
    // 0x80044BF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004C340(rdram, ctx);
        goto after_43;
    // 0x80044BF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_43:
    // 0x80044BFC: jal         0x8000798C
    // 0x80044C00: nop

    func_8000798C(rdram, ctx);
        goto after_44;
    // 0x80044C00: nop

    after_44:
    // 0x80044C04: b           L_800447D0
    // 0x80044C08: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
        goto L_800447D0;
    // 0x80044C08: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    // 0x80044C0C: nop

    // 0x80044C10: nop

    // 0x80044C14: nop

    // 0x80044C18: nop

    // 0x80044C1C: nop

    // 0x80044C20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80044C24: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80044C28: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80044C2C: jr          $ra
    // 0x80044C30: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    TRACE_RETURN()
    return;
    // 0x80044C30: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80044C34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80044C34: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80044C38: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80044C3C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80044C40: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80044C44: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80044C48: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80044C4C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80044C50: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80044C54: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80044C58: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80044C5C: addiu       $s0, $zero, 0xA
    ctx->r16 = ADD32(0, 0XA);
    // 0x80044C60: addiu       $s1, $zero, 0xA
    ctx->r17 = ADD32(0, 0XA);
    // 0x80044C64: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x80044C68: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80044C6C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80044C70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80044C74: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80044C78: jal         0x8004C388
    // 0x80044C7C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004C388(rdram, ctx);
        goto after_0;
    // 0x80044C7C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80044C80: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80044C84: addiu       $a2, $a2, 0x79CC
    ctx->r6 = ADD32(ctx->r6, 0X79CC);
    // 0x80044C88: addiu       $a0, $zero, -0xFE
    ctx->r4 = ADD32(0, -0XFE);
    // 0x80044C8C: jal         0x8004BCF0
    // 0x80044C90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004BCF0(rdram, ctx);
        goto after_1;
    // 0x80044C90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80044C94: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x80044C98: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80044C9C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80044CA0: addiu       $a1, $a1, -0x51A8
    ctx->r5 = ADD32(ctx->r5, -0X51A8);
    // 0x80044CA4: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80044CA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80044CAC: jal         0x80049660
    // 0x80044CB0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_80049660(rdram, ctx);
        goto after_2;
    // 0x80044CB0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_2:
    // 0x80044CB4: jal         0x8000798C
    // 0x80044CB8: nop

    func_8000798C(rdram, ctx);
        goto after_3;
    // 0x80044CB8: nop

    after_3:
    // 0x80044CBC: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x80044CC0: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x80044CC4: addiu       $s5, $s5, -0x2E58
    ctx->r21 = ADD32(ctx->r21, -0X2E58);
    // 0x80044CC8: addiu       $s6, $s6, -0x2E5A
    ctx->r22 = ADD32(ctx->r22, -0X2E5A);
L_80044CCC:
    // 0x80044CCC: jal         0x800496B4
    // 0x80044CD0: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    func_800496B4(rdram, ctx);
        goto after_4;
    // 0x80044CD0: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_4:
    // 0x80044CD4: lh          $v0, 0x5C($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X5C);
    // 0x80044CD8: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80044CDC: sltiu       $at, $t7, 0x9
    ctx->r1 = ctx->r15 < 0X9 ? 1 : 0;
    // 0x80044CE0: beq         $at, $zero, L_80044F50
    if (ctx->r1 == 0) {
        // 0x80044CE4: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80044F50;
    }
    // 0x80044CE4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80044CE8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80044CEC: addu        $at, $at, $t7
    gpr jr_addend_80044CF4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80044CF0: lw          $t7, 0x7E6C($at)
    ctx->r15 = ADD32(ctx->r1, 0X7E6C);
    // 0x80044CF4: jr          $t7
    // 0x80044CF8: nop

    switch (jr_addend_80044CF4 >> 2) {
        case 0: goto L_80044CFC; break;
        case 1: goto L_80044D64; break;
        case 2: goto L_80044DCC; break;
        case 3: goto L_80044E34; break;
        case 4: goto L_80044E9C; break;
        case 5: goto L_80044F50; break;
        case 6: goto L_80044F50; break;
        case 7: goto L_80044F50; break;
        case 8: goto L_80044F04; break;
        default: switch_error(__func__, 0x80044CF4, 0x80077E6C);
    }
    // 0x80044CF8: nop

L_80044CFC:
    // 0x80044CFC: addiu       $a1, $v0, 0x3
    ctx->r5 = ADD32(ctx->r2, 0X3);
    // 0x80044D00: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x80044D04: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80044D08: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x80044D0C: jal         0x8004C388
    // 0x80044D10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004C388(rdram, ctx);
        goto after_5;
    // 0x80044D10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80044D14: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80044D18: addiu       $a2, $a2, 0x79D8
    ctx->r6 = ADD32(ctx->r6, 0X79D8);
    // 0x80044D1C: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80044D20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80044D24: jal         0x8004C340
    // 0x80044D28: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_8004C340(rdram, ctx);
        goto after_6;
    // 0x80044D28: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_6:
    // 0x80044D2C: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x80044D30: andi        $t0, $v0, 0x200
    ctx->r8 = ctx->r2 & 0X200;
    // 0x80044D34: beq         $t0, $zero, L_80044D4C
    if (ctx->r8 == 0) {
        // 0x80044D38: andi        $t3, $v0, 0x100
        ctx->r11 = ctx->r2 & 0X100;
            goto L_80044D4C;
    }
    // 0x80044D38: andi        $t3, $v0, 0x100
    ctx->r11 = ctx->r2 & 0X100;
    // 0x80044D3C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80044D40: sll         $t1, $s0, 16
    ctx->r9 = S32(ctx->r16 << 16);
    // 0x80044D44: b           L_80044F50
    // 0x80044D48: sra         $s0, $t1, 16
    ctx->r16 = S32(SIGNED(ctx->r9) >> 16);
        goto L_80044F50;
    // 0x80044D48: sra         $s0, $t1, 16
    ctx->r16 = S32(SIGNED(ctx->r9) >> 16);
L_80044D4C:
    // 0x80044D4C: beql        $t3, $zero, L_80044F54
    if (ctx->r11 == 0) {
        // 0x80044D50: lhu         $v0, 0x0($s6)
        ctx->r2 = MEM_HU(ctx->r22, 0X0);
            goto L_80044F54;
    }
    goto skip_0;
    // 0x80044D50: lhu         $v0, 0x0($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X0);
    skip_0:
    // 0x80044D54: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80044D58: sll         $t4, $s0, 16
    ctx->r12 = S32(ctx->r16 << 16);
    // 0x80044D5C: b           L_80044F50
    // 0x80044D60: sra         $s0, $t4, 16
    ctx->r16 = S32(SIGNED(ctx->r12) >> 16);
        goto L_80044F50;
    // 0x80044D60: sra         $s0, $t4, 16
    ctx->r16 = S32(SIGNED(ctx->r12) >> 16);
L_80044D64:
    // 0x80044D64: addiu       $a1, $v0, 0x3
    ctx->r5 = ADD32(ctx->r2, 0X3);
    // 0x80044D68: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80044D6C: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80044D70: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x80044D74: jal         0x8004C388
    // 0x80044D78: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004C388(rdram, ctx);
        goto after_7;
    // 0x80044D78: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x80044D7C: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80044D80: addiu       $a2, $a2, 0x79DC
    ctx->r6 = ADD32(ctx->r6, 0X79DC);
    // 0x80044D84: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80044D88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80044D8C: jal         0x8004C340
    // 0x80044D90: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_8004C340(rdram, ctx);
        goto after_8;
    // 0x80044D90: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_8:
    // 0x80044D94: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x80044D98: andi        $t8, $v0, 0x200
    ctx->r24 = ctx->r2 & 0X200;
    // 0x80044D9C: beq         $t8, $zero, L_80044DB4
    if (ctx->r24 == 0) {
        // 0x80044DA0: andi        $t1, $v0, 0x100
        ctx->r9 = ctx->r2 & 0X100;
            goto L_80044DB4;
    }
    // 0x80044DA0: andi        $t1, $v0, 0x100
    ctx->r9 = ctx->r2 & 0X100;
    // 0x80044DA4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80044DA8: sll         $t9, $s1, 16
    ctx->r25 = S32(ctx->r17 << 16);
    // 0x80044DAC: b           L_80044F50
    // 0x80044DB0: sra         $s1, $t9, 16
    ctx->r17 = S32(SIGNED(ctx->r25) >> 16);
        goto L_80044F50;
    // 0x80044DB0: sra         $s1, $t9, 16
    ctx->r17 = S32(SIGNED(ctx->r25) >> 16);
L_80044DB4:
    // 0x80044DB4: beql        $t1, $zero, L_80044F54
    if (ctx->r9 == 0) {
        // 0x80044DB8: lhu         $v0, 0x0($s6)
        ctx->r2 = MEM_HU(ctx->r22, 0X0);
            goto L_80044F54;
    }
    goto skip_1;
    // 0x80044DB8: lhu         $v0, 0x0($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X0);
    skip_1:
    // 0x80044DBC: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80044DC0: sll         $t2, $s1, 16
    ctx->r10 = S32(ctx->r17 << 16);
    // 0x80044DC4: b           L_80044F50
    // 0x80044DC8: sra         $s1, $t2, 16
    ctx->r17 = S32(SIGNED(ctx->r10) >> 16);
        goto L_80044F50;
    // 0x80044DC8: sra         $s1, $t2, 16
    ctx->r17 = S32(SIGNED(ctx->r10) >> 16);
L_80044DCC:
    // 0x80044DCC: addiu       $a1, $v0, 0x3
    ctx->r5 = ADD32(ctx->r2, 0X3);
    // 0x80044DD0: sll         $t4, $a1, 16
    ctx->r12 = S32(ctx->r5 << 16);
    // 0x80044DD4: sra         $a1, $t4, 16
    ctx->r5 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80044DD8: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x80044DDC: jal         0x8004C388
    // 0x80044DE0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004C388(rdram, ctx);
        goto after_9;
    // 0x80044DE0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x80044DE4: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80044DE8: addiu       $a2, $a2, 0x79E0
    ctx->r6 = ADD32(ctx->r6, 0X79E0);
    // 0x80044DEC: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80044DF0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80044DF4: jal         0x8004C340
    // 0x80044DF8: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    func_8004C340(rdram, ctx);
        goto after_10;
    // 0x80044DF8: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_10:
    // 0x80044DFC: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x80044E00: andi        $t6, $v0, 0x200
    ctx->r14 = ctx->r2 & 0X200;
    // 0x80044E04: beq         $t6, $zero, L_80044E1C
    if (ctx->r14 == 0) {
        // 0x80044E08: andi        $t9, $v0, 0x100
        ctx->r25 = ctx->r2 & 0X100;
            goto L_80044E1C;
    }
    // 0x80044E08: andi        $t9, $v0, 0x100
    ctx->r25 = ctx->r2 & 0X100;
    // 0x80044E0C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80044E10: sll         $t7, $s2, 16
    ctx->r15 = S32(ctx->r18 << 16);
    // 0x80044E14: b           L_80044F50
    // 0x80044E18: sra         $s2, $t7, 16
    ctx->r18 = S32(SIGNED(ctx->r15) >> 16);
        goto L_80044F50;
    // 0x80044E18: sra         $s2, $t7, 16
    ctx->r18 = S32(SIGNED(ctx->r15) >> 16);
L_80044E1C:
    // 0x80044E1C: beql        $t9, $zero, L_80044F54
    if (ctx->r25 == 0) {
        // 0x80044E20: lhu         $v0, 0x0($s6)
        ctx->r2 = MEM_HU(ctx->r22, 0X0);
            goto L_80044F54;
    }
    goto skip_2;
    // 0x80044E20: lhu         $v0, 0x0($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X0);
    skip_2:
    // 0x80044E24: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80044E28: sll         $t0, $s2, 16
    ctx->r8 = S32(ctx->r18 << 16);
    // 0x80044E2C: b           L_80044F50
    // 0x80044E30: sra         $s2, $t0, 16
    ctx->r18 = S32(SIGNED(ctx->r8) >> 16);
        goto L_80044F50;
    // 0x80044E30: sra         $s2, $t0, 16
    ctx->r18 = S32(SIGNED(ctx->r8) >> 16);
L_80044E34:
    // 0x80044E34: addiu       $a1, $v0, 0x3
    ctx->r5 = ADD32(ctx->r2, 0X3);
    // 0x80044E38: sll         $t2, $a1, 16
    ctx->r10 = S32(ctx->r5 << 16);
    // 0x80044E3C: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80044E40: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x80044E44: jal         0x8004C388
    // 0x80044E48: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004C388(rdram, ctx);
        goto after_11;
    // 0x80044E48: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x80044E4C: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80044E50: addiu       $a2, $a2, 0x79E4
    ctx->r6 = ADD32(ctx->r6, 0X79E4);
    // 0x80044E54: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80044E58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80044E5C: jal         0x8004C340
    // 0x80044E60: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    func_8004C340(rdram, ctx);
        goto after_12;
    // 0x80044E60: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_12:
    // 0x80044E64: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x80044E68: andi        $t4, $v0, 0x200
    ctx->r12 = ctx->r2 & 0X200;
    // 0x80044E6C: beq         $t4, $zero, L_80044E84
    if (ctx->r12 == 0) {
        // 0x80044E70: andi        $t7, $v0, 0x100
        ctx->r15 = ctx->r2 & 0X100;
            goto L_80044E84;
    }
    // 0x80044E70: andi        $t7, $v0, 0x100
    ctx->r15 = ctx->r2 & 0X100;
    // 0x80044E74: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80044E78: sll         $t5, $s3, 16
    ctx->r13 = S32(ctx->r19 << 16);
    // 0x80044E7C: b           L_80044F50
    // 0x80044E80: sra         $s3, $t5, 16
    ctx->r19 = S32(SIGNED(ctx->r13) >> 16);
        goto L_80044F50;
    // 0x80044E80: sra         $s3, $t5, 16
    ctx->r19 = S32(SIGNED(ctx->r13) >> 16);
L_80044E84:
    // 0x80044E84: beql        $t7, $zero, L_80044F54
    if (ctx->r15 == 0) {
        // 0x80044E88: lhu         $v0, 0x0($s6)
        ctx->r2 = MEM_HU(ctx->r22, 0X0);
            goto L_80044F54;
    }
    goto skip_3;
    // 0x80044E88: lhu         $v0, 0x0($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X0);
    skip_3:
    // 0x80044E8C: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x80044E90: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x80044E94: b           L_80044F50
    // 0x80044E98: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
        goto L_80044F50;
    // 0x80044E98: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
L_80044E9C:
    // 0x80044E9C: addiu       $a1, $v0, 0x3
    ctx->r5 = ADD32(ctx->r2, 0X3);
    // 0x80044EA0: sll         $t0, $a1, 16
    ctx->r8 = S32(ctx->r5 << 16);
    // 0x80044EA4: sra         $a1, $t0, 16
    ctx->r5 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80044EA8: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x80044EAC: jal         0x8004C388
    // 0x80044EB0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004C388(rdram, ctx);
        goto after_13;
    // 0x80044EB0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_13:
    // 0x80044EB4: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80044EB8: addiu       $a2, $a2, 0x79E8
    ctx->r6 = ADD32(ctx->r6, 0X79E8);
    // 0x80044EBC: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80044EC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80044EC4: jal         0x8004C340
    // 0x80044EC8: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    func_8004C340(rdram, ctx);
        goto after_14;
    // 0x80044EC8: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_14:
    // 0x80044ECC: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x80044ED0: andi        $t2, $v0, 0x200
    ctx->r10 = ctx->r2 & 0X200;
    // 0x80044ED4: beq         $t2, $zero, L_80044EEC
    if (ctx->r10 == 0) {
        // 0x80044ED8: andi        $t5, $v0, 0x100
        ctx->r13 = ctx->r2 & 0X100;
            goto L_80044EEC;
    }
    // 0x80044ED8: andi        $t5, $v0, 0x100
    ctx->r13 = ctx->r2 & 0X100;
    // 0x80044EDC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80044EE0: sll         $t3, $s4, 16
    ctx->r11 = S32(ctx->r20 << 16);
    // 0x80044EE4: b           L_80044F50
    // 0x80044EE8: sra         $s4, $t3, 16
    ctx->r20 = S32(SIGNED(ctx->r11) >> 16);
        goto L_80044F50;
    // 0x80044EE8: sra         $s4, $t3, 16
    ctx->r20 = S32(SIGNED(ctx->r11) >> 16);
L_80044EEC:
    // 0x80044EEC: beql        $t5, $zero, L_80044F54
    if (ctx->r13 == 0) {
        // 0x80044EF0: lhu         $v0, 0x0($s6)
        ctx->r2 = MEM_HU(ctx->r22, 0X0);
            goto L_80044F54;
    }
    goto skip_4;
    // 0x80044EF0: lhu         $v0, 0x0($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X0);
    skip_4:
    // 0x80044EF4: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x80044EF8: sll         $t6, $s4, 16
    ctx->r14 = S32(ctx->r20 << 16);
    // 0x80044EFC: b           L_80044F50
    // 0x80044F00: sra         $s4, $t6, 16
    ctx->r20 = S32(SIGNED(ctx->r14) >> 16);
        goto L_80044F50;
    // 0x80044F00: sra         $s4, $t6, 16
    ctx->r20 = S32(SIGNED(ctx->r14) >> 16);
L_80044F04:
    // 0x80044F04: lhu         $t8, 0x0($s6)
    ctx->r24 = MEM_HU(ctx->r22, 0X0);
    // 0x80044F08: andi        $t9, $t8, 0x1000
    ctx->r25 = ctx->r24 & 0X1000;
    // 0x80044F0C: beql        $t9, $zero, L_80044F54
    if (ctx->r25 == 0) {
        // 0x80044F10: lhu         $v0, 0x0($s6)
        ctx->r2 = MEM_HU(ctx->r22, 0X0);
            goto L_80044F54;
    }
    goto skip_5;
    // 0x80044F10: lhu         $v0, 0x0($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X0);
    skip_5:
    // 0x80044F14: addiu       $s0, $zero, 0xA
    ctx->r16 = ADD32(0, 0XA);
    // 0x80044F18: addiu       $s1, $zero, 0xA
    ctx->r17 = ADD32(0, 0XA);
    // 0x80044F1C: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x80044F20: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80044F24: jal         0x8000AD90
    // 0x80044F28: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    func_8000AD90(rdram, ctx);
        goto after_15;
    // 0x80044F28: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    after_15:
    // 0x80044F2C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80044F30: jal         0x8004C4D8
    // 0x80044F34: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8004C4D8(rdram, ctx);
        goto after_16;
    // 0x80044F34: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_16:
    // 0x80044F38: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x80044F3C: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
L_80044F40:
    // 0x80044F40: jal         0x8000798C
    // 0x80044F44: nop

    func_8000798C(rdram, ctx);
        goto after_17;
    // 0x80044F44: nop

    after_17:
    // 0x80044F48: b           L_80044F40
    // 0x80044F4C: nop

        goto L_80044F40;
    // 0x80044F4C: nop

L_80044F50:
    // 0x80044F50: lhu         $v0, 0x0($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X0);
L_80044F54:
    // 0x80044F54: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80044F58: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80044F5C: andi        $t1, $v0, 0x8000
    ctx->r9 = ctx->r2 & 0X8000;
    // 0x80044F60: beq         $t1, $zero, L_80044FA0
    if (ctx->r9 == 0) {
        // 0x80044F64: andi        $t6, $v0, 0x4000
        ctx->r14 = ctx->r2 & 0X4000;
            goto L_80044FA0;
    }
    // 0x80044F64: andi        $t6, $v0, 0x4000
    ctx->r14 = ctx->r2 & 0X4000;
    // 0x80044F68: sll         $a1, $s1, 16
    ctx->r5 = S32(ctx->r17 << 16);
    // 0x80044F6C: sll         $a2, $s2, 16
    ctx->r6 = S32(ctx->r18 << 16);
    // 0x80044F70: sll         $a3, $s3, 16
    ctx->r7 = S32(ctx->r19 << 16);
    // 0x80044F74: sra         $t5, $a3, 16
    ctx->r13 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80044F78: sra         $t4, $a2, 16
    ctx->r12 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80044F7C: sra         $t3, $a1, 16
    ctx->r11 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80044F80: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x80044F84: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x80044F88: or          $a3, $t5, $zero
    ctx->r7 = ctx->r13 | 0;
    // 0x80044F8C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x80044F90: jal         0x8000ACEC
    // 0x80044F94: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    func_8000ACEC(rdram, ctx);
        goto after_18;
    // 0x80044F94: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_18:
    // 0x80044F98: b           L_80044FB0
    // 0x80044F9C: nop

        goto L_80044FB0;
    // 0x80044F9C: nop

L_80044FA0:
    // 0x80044FA0: beq         $t6, $zero, L_80044FB0
    if (ctx->r14 == 0) {
        // 0x80044FA4: nop
    
            goto L_80044FB0;
    }
    // 0x80044FA4: nop

    // 0x80044FA8: jal         0x8000AD90
    // 0x80044FAC: nop

    func_8000AD90(rdram, ctx);
        goto after_19;
    // 0x80044FAC: nop

    after_19:
L_80044FB0:
    // 0x80044FB0: jal         0x8000798C
    // 0x80044FB4: nop

    func_8000798C(rdram, ctx);
        goto after_20;
    // 0x80044FB4: nop

    after_20:
    // 0x80044FB8: b           L_80044CCC
    // 0x80044FBC: nop

        goto L_80044CCC;
    // 0x80044FBC: nop

    // 0x80044FC0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80044FC4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80044FC8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80044FCC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80044FD0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80044FD4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80044FD8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80044FDC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80044FE0: jr          $ra
    // 0x80044FE4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    TRACE_RETURN()
    return;
    // 0x80044FE4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80044FE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80044FE8: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80044FEC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80044FF0: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80044FF4: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80044FF8: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80044FFC: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80045000: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80045004: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x80045008: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x8004500C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80045010: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80045014: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80045018: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8004501C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80045020: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80045024: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80045028: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8004502C: jal         0x8004C388
    // 0x80045030: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004C388(rdram, ctx);
        goto after_0;
    // 0x80045030: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80045034: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80045038: addiu       $a2, $a2, 0x7A14
    ctx->r6 = ADD32(ctx->r6, 0X7A14);
    // 0x8004503C: addiu       $a0, $zero, -0xFE
    ctx->r4 = ADD32(0, -0XFE);
    // 0x80045040: jal         0x8004BCF0
    // 0x80045044: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004BCF0(rdram, ctx);
        goto after_1;
    // 0x80045044: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80045048: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x8004504C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80045050: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80045054: addiu       $a1, $a1, -0x5168
    ctx->r5 = ADD32(ctx->r5, -0X5168);
    // 0x80045058: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x8004505C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80045060: jal         0x80049660
    // 0x80045064: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_80049660(rdram, ctx);
        goto after_2;
    // 0x80045064: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_2:
    // 0x80045068: jal         0x8000798C
    // 0x8004506C: nop

    func_8000798C(rdram, ctx);
        goto after_3;
    // 0x8004506C: nop

    after_3:
    // 0x80045070: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x80045074: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x80045078: addiu       $s6, $s6, -0x2E5A
    ctx->r22 = ADD32(ctx->r22, -0X2E5A);
    // 0x8004507C: addiu       $s7, $s7, -0x2E58
    ctx->r23 = ADD32(ctx->r23, -0X2E58);
L_80045080:
    // 0x80045080: jal         0x800496B4
    // 0x80045084: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    func_800496B4(rdram, ctx);
        goto after_4;
    // 0x80045084: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_4:
    // 0x80045088: lh          $v0, 0x58($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X58);
    // 0x8004508C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80045090: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80045094: beq         $v0, $at, L_800450C8
    if (ctx->r2 == ctx->r1) {
        // 0x80045098: addiu       $a1, $v0, 0x3
        ctx->r5 = ADD32(ctx->r2, 0X3);
            goto L_800450C8;
    }
    // 0x80045098: addiu       $a1, $v0, 0x3
    ctx->r5 = ADD32(ctx->r2, 0X3);
    // 0x8004509C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800450A0: beq         $v0, $at, L_8004517C
    if (ctx->r2 == ctx->r1) {
        // 0x800450A4: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_8004517C;
    }
    // 0x800450A4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800450A8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800450AC: beq         $v0, $at, L_800451FC
    if (ctx->r2 == ctx->r1) {
        // 0x800450B0: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_800451FC;
    }
    // 0x800450B0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800450B4: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800450B8: beql        $v0, $at, L_800452B4
    if (ctx->r2 == ctx->r1) {
        // 0x800450BC: lhu         $t5, 0x0($s6)
        ctx->r13 = MEM_HU(ctx->r22, 0X0);
            goto L_800452B4;
    }
    goto skip_0;
    // 0x800450BC: lhu         $t5, 0x0($s6)
    ctx->r13 = MEM_HU(ctx->r22, 0X0);
    skip_0:
    // 0x800450C0: b           L_800452F8
    // 0x800450C4: nop

        goto L_800452F8;
    // 0x800450C4: nop

L_800450C8:
    // 0x800450C8: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x800450CC: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800450D0: jal         0x8004C388
    // 0x800450D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004C388(rdram, ctx);
        goto after_5;
    // 0x800450D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x800450D8: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x800450DC: addiu       $a2, $a2, 0x7A20
    ctx->r6 = ADD32(ctx->r6, 0X7A20);
    // 0x800450E0: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x800450E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800450E8: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x800450EC: jal         0x8004C340
    // 0x800450F0: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    func_8004C340(rdram, ctx);
        goto after_6;
    // 0x800450F0: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    after_6:
    // 0x800450F4: lhu         $v1, 0x0($s7)
    ctx->r3 = MEM_HU(ctx->r23, 0X0);
    // 0x800450F8: andi        $a0, $s5, 0xFFFF
    ctx->r4 = ctx->r21 & 0XFFFF;
    // 0x800450FC: andi        $s0, $s3, 0xFFFF
    ctx->r16 = ctx->r19 & 0XFFFF;
    // 0x80045100: andi        $t9, $v1, 0x200
    ctx->r25 = ctx->r3 & 0X200;
    // 0x80045104: beq         $t9, $zero, L_8004512C
    if (ctx->r25 == 0) {
        // 0x80045108: andi        $t2, $v1, 0x100
        ctx->r10 = ctx->r3 & 0X100;
            goto L_8004512C;
    }
    // 0x80045108: andi        $t2, $v1, 0x100
    ctx->r10 = ctx->r3 & 0X100;
    // 0x8004510C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80045110: sll         $t0, $s2, 16
    ctx->r8 = S32(ctx->r18 << 16);
    // 0x80045114: sra         $s2, $t0, 16
    ctx->r18 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80045118: slti        $at, $s2, 0x6E
    ctx->r1 = SIGNED(ctx->r18) < 0X6E ? 1 : 0;
    // 0x8004511C: bnel        $at, $zero, L_80045150
    if (ctx->r1 != 0) {
        // 0x80045120: lhu         $t5, 0x0($s6)
        ctx->r13 = MEM_HU(ctx->r22, 0X0);
            goto L_80045150;
    }
    goto skip_1;
    // 0x80045120: lhu         $t5, 0x0($s6)
    ctx->r13 = MEM_HU(ctx->r22, 0X0);
    skip_1:
    // 0x80045124: b           L_8004514C
    // 0x80045128: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
        goto L_8004514C;
    // 0x80045128: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8004512C:
    // 0x8004512C: beql        $t2, $zero, L_80045150
    if (ctx->r10 == 0) {
        // 0x80045130: lhu         $t5, 0x0($s6)
        ctx->r13 = MEM_HU(ctx->r22, 0X0);
            goto L_80045150;
    }
    goto skip_2;
    // 0x80045130: lhu         $t5, 0x0($s6)
    ctx->r13 = MEM_HU(ctx->r22, 0X0);
    skip_2:
    // 0x80045134: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80045138: sll         $t3, $s2, 16
    ctx->r11 = S32(ctx->r18 << 16);
    // 0x8004513C: sra         $s2, $t3, 16
    ctx->r18 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80045140: bgezl       $s2, L_80045150
    if (SIGNED(ctx->r18) >= 0) {
        // 0x80045144: lhu         $t5, 0x0($s6)
        ctx->r13 = MEM_HU(ctx->r22, 0X0);
            goto L_80045150;
    }
    goto skip_3;
    // 0x80045144: lhu         $t5, 0x0($s6)
    ctx->r13 = MEM_HU(ctx->r22, 0X0);
    skip_3:
    // 0x80045148: addiu       $s2, $zero, 0x6D
    ctx->r18 = ADD32(0, 0X6D);
L_8004514C:
    // 0x8004514C: lhu         $t5, 0x0($s6)
    ctx->r13 = MEM_HU(ctx->r22, 0X0);
L_80045150:
    // 0x80045150: andi        $t6, $t5, 0x2000
    ctx->r14 = ctx->r13 & 0X2000;
    // 0x80045154: beq         $t6, $zero, L_800452F8
    if (ctx->r14 == 0) {
        // 0x80045158: nop
    
            goto L_800452F8;
    }
    // 0x80045158: nop

    // 0x8004515C: jal         0x80008320
    // 0x80045160: andi        $s1, $s2, 0xFFFF
    ctx->r17 = ctx->r18 & 0XFFFF;
    func_80008320(rdram, ctx);
        goto after_7;
    // 0x80045160: andi        $s1, $s2, 0xFFFF
    ctx->r17 = ctx->r18 & 0XFFFF;
    after_7:
    // 0x80045164: jal         0x800083EC
    // 0x80045168: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    func_800083EC(rdram, ctx);
        goto after_8;
    // 0x80045168: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    after_8:
    // 0x8004516C: jal         0x8000804C
    // 0x80045170: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    func_8000804C(rdram, ctx);
        goto after_9;
    // 0x80045170: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    after_9:
    // 0x80045174: b           L_800452F8
    // 0x80045178: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
        goto L_800452F8;
    // 0x80045178: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
L_8004517C:
    // 0x8004517C: addiu       $a1, $v0, 0x3
    ctx->r5 = ADD32(ctx->r2, 0X3);
    // 0x80045180: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x80045184: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80045188: jal         0x8004C388
    // 0x8004518C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004C388(rdram, ctx);
        goto after_10;
    // 0x8004518C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_10:
    // 0x80045190: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80045194: addiu       $a2, $a2, 0x7A2C
    ctx->r6 = ADD32(ctx->r6, 0X7A2C);
    // 0x80045198: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x8004519C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800451A0: jal         0x8004C340
    // 0x800451A4: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    func_8004C340(rdram, ctx);
        goto after_11;
    // 0x800451A4: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_11:
    // 0x800451A8: lhu         $v1, 0x0($s7)
    ctx->r3 = MEM_HU(ctx->r23, 0X0);
    // 0x800451AC: andi        $t9, $v1, 0x200
    ctx->r25 = ctx->r3 & 0X200;
    // 0x800451B0: beq         $t9, $zero, L_800451D8
    if (ctx->r25 == 0) {
        // 0x800451B4: andi        $t2, $v1, 0x100
        ctx->r10 = ctx->r3 & 0X100;
            goto L_800451D8;
    }
    // 0x800451B4: andi        $t2, $v1, 0x100
    ctx->r10 = ctx->r3 & 0X100;
    // 0x800451B8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800451BC: sll         $t0, $s3, 16
    ctx->r8 = S32(ctx->r19 << 16);
    // 0x800451C0: sra         $s3, $t0, 16
    ctx->r19 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800451C4: slti        $at, $s3, 0x5
    ctx->r1 = SIGNED(ctx->r19) < 0X5 ? 1 : 0;
    // 0x800451C8: bne         $at, $zero, L_800452F8
    if (ctx->r1 != 0) {
        // 0x800451CC: nop
    
            goto L_800452F8;
    }
    // 0x800451CC: nop

    // 0x800451D0: b           L_800452F8
    // 0x800451D4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
        goto L_800452F8;
    // 0x800451D4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_800451D8:
    // 0x800451D8: beq         $t2, $zero, L_800452F8
    if (ctx->r10 == 0) {
        // 0x800451DC: nop
    
            goto L_800452F8;
    }
    // 0x800451DC: nop

    // 0x800451E0: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x800451E4: sll         $t3, $s3, 16
    ctx->r11 = S32(ctx->r19 << 16);
    // 0x800451E8: sra         $s3, $t3, 16
    ctx->r19 = S32(SIGNED(ctx->r11) >> 16);
    // 0x800451EC: bgez        $s3, L_800452F8
    if (SIGNED(ctx->r19) >= 0) {
        // 0x800451F0: nop
    
            goto L_800452F8;
    }
    // 0x800451F0: nop

    // 0x800451F4: b           L_800452F8
    // 0x800451F8: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
        goto L_800452F8;
    // 0x800451F8: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
L_800451FC:
    // 0x800451FC: addiu       $a1, $v0, 0x3
    ctx->r5 = ADD32(ctx->r2, 0X3);
    // 0x80045200: sll         $t5, $a1, 16
    ctx->r13 = S32(ctx->r5 << 16);
    // 0x80045204: sra         $a1, $t5, 16
    ctx->r5 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80045208: jal         0x8004C388
    // 0x8004520C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004C388(rdram, ctx);
        goto after_12;
    // 0x8004520C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_12:
    // 0x80045210: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80045214: addiu       $a2, $a2, 0x7A30
    ctx->r6 = ADD32(ctx->r6, 0X7A30);
    // 0x80045218: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x8004521C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80045220: jal         0x8004C340
    // 0x80045224: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    func_8004C340(rdram, ctx);
        goto after_13;
    // 0x80045224: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_13:
    // 0x80045228: lhu         $v1, 0x0($s7)
    ctx->r3 = MEM_HU(ctx->r23, 0X0);
    // 0x8004522C: andi        $t7, $v1, 0x200
    ctx->r15 = ctx->r3 & 0X200;
    // 0x80045230: beq         $t7, $zero, L_80045258
    if (ctx->r15 == 0) {
        // 0x80045234: andi        $t0, $v1, 0x100
        ctx->r8 = ctx->r3 & 0X100;
            goto L_80045258;
    }
    // 0x80045234: andi        $t0, $v1, 0x100
    ctx->r8 = ctx->r3 & 0X100;
    // 0x80045238: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8004523C: sll         $t8, $s4, 16
    ctx->r24 = S32(ctx->r20 << 16);
    // 0x80045240: sra         $s4, $t8, 16
    ctx->r20 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80045244: slti        $at, $s4, 0xE
    ctx->r1 = SIGNED(ctx->r20) < 0XE ? 1 : 0;
    // 0x80045248: bnel        $at, $zero, L_8004527C
    if (ctx->r1 != 0) {
        // 0x8004524C: lhu         $v0, 0x0($s6)
        ctx->r2 = MEM_HU(ctx->r22, 0X0);
            goto L_8004527C;
    }
    goto skip_4;
    // 0x8004524C: lhu         $v0, 0x0($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X0);
    skip_4:
    // 0x80045250: b           L_80045278
    // 0x80045254: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
        goto L_80045278;
    // 0x80045254: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_80045258:
    // 0x80045258: beql        $t0, $zero, L_8004527C
    if (ctx->r8 == 0) {
        // 0x8004525C: lhu         $v0, 0x0($s6)
        ctx->r2 = MEM_HU(ctx->r22, 0X0);
            goto L_8004527C;
    }
    goto skip_5;
    // 0x8004525C: lhu         $v0, 0x0($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X0);
    skip_5:
    // 0x80045260: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x80045264: sll         $t1, $s4, 16
    ctx->r9 = S32(ctx->r20 << 16);
    // 0x80045268: sra         $s4, $t1, 16
    ctx->r20 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8004526C: bgezl       $s4, L_8004527C
    if (SIGNED(ctx->r20) >= 0) {
        // 0x80045270: lhu         $v0, 0x0($s6)
        ctx->r2 = MEM_HU(ctx->r22, 0X0);
            goto L_8004527C;
    }
    goto skip_6;
    // 0x80045270: lhu         $v0, 0x0($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X0);
    skip_6:
    // 0x80045274: addiu       $s4, $zero, 0xD
    ctx->r20 = ADD32(0, 0XD);
L_80045278:
    // 0x80045278: lhu         $v0, 0x0($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X0);
L_8004527C:
    // 0x8004527C: andi        $t3, $v0, 0x2000
    ctx->r11 = ctx->r2 & 0X2000;
    // 0x80045280: beql        $t3, $zero, L_80045298
    if (ctx->r11 == 0) {
        // 0x80045284: andi        $t4, $v0, 0x8000
        ctx->r12 = ctx->r2 & 0X8000;
            goto L_80045298;
    }
    goto skip_7;
    // 0x80045284: andi        $t4, $v0, 0x8000
    ctx->r12 = ctx->r2 & 0X8000;
    skip_7:
    // 0x80045288: jal         0x80007EC8
    // 0x8004528C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_80007EC8(rdram, ctx);
        goto after_14;
    // 0x8004528C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_14:
    // 0x80045290: lhu         $v0, 0x0($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X0);
    // 0x80045294: andi        $t4, $v0, 0x8000
    ctx->r12 = ctx->r2 & 0X8000;
L_80045298:
    // 0x80045298: beq         $t4, $zero, L_800452F8
    if (ctx->r12 == 0) {
        // 0x8004529C: nop
    
            goto L_800452F8;
    }
    // 0x8004529C: nop

    // 0x800452A0: jal         0x80007E20
    // 0x800452A4: nop

    func_80007E20(rdram, ctx);
        goto after_15;
    // 0x800452A4: nop

    after_15:
    // 0x800452A8: b           L_800452F8
    // 0x800452AC: nop

        goto L_800452F8;
    // 0x800452AC: nop

    // 0x800452B0: lhu         $t5, 0x0($s6)
    ctx->r13 = MEM_HU(ctx->r22, 0X0);
L_800452B4:
    // 0x800452B4: andi        $t6, $t5, 0x1000
    ctx->r14 = ctx->r13 & 0X1000;
    // 0x800452B8: beq         $t6, $zero, L_800452F8
    if (ctx->r14 == 0) {
        // 0x800452BC: andi        $a0, $s5, 0xFFFF
        ctx->r4 = ctx->r21 & 0XFFFF;
            goto L_800452F8;
    }
    // 0x800452BC: andi        $a0, $s5, 0xFFFF
    ctx->r4 = ctx->r21 & 0XFFFF;
    // 0x800452C0: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800452C4: addiu       $s2, $zero, 0x6D
    ctx->r18 = ADD32(0, 0X6D);
    // 0x800452C8: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x800452CC: jal         0x80008320
    // 0x800452D0: addiu       $s4, $zero, 0xD
    ctx->r20 = ADD32(0, 0XD);
    func_80008320(rdram, ctx);
        goto after_16;
    // 0x800452D0: addiu       $s4, $zero, 0xD
    ctx->r20 = ADD32(0, 0XD);
    after_16:
    // 0x800452D4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800452D8: jal         0x8004C4D8
    // 0x800452DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8004C4D8(rdram, ctx);
        goto after_17;
    // 0x800452DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_17:
    // 0x800452E0: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x800452E4: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
L_800452E8:
    // 0x800452E8: jal         0x8000798C
    // 0x800452EC: nop

    func_8000798C(rdram, ctx);
        goto after_18;
    // 0x800452EC: nop

    after_18:
    // 0x800452F0: b           L_800452E8
    // 0x800452F4: nop

        goto L_800452E8;
    // 0x800452F4: nop

L_800452F8:
    // 0x800452F8: jal         0x8000798C
    // 0x800452FC: nop

    func_8000798C(rdram, ctx);
        goto after_19;
    // 0x800452FC: nop

    after_19:
    // 0x80045300: b           L_80045080
    // 0x80045304: nop

        goto L_80045080;
    // 0x80045304: nop

    // 0x80045308: nop

    // 0x8004530C: nop

    // 0x80045310: nop

    // 0x80045314: nop

    // 0x80045318: nop

    // 0x8004531C: nop

    // 0x80045320: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80045324: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80045328: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8004532C: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80045330: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80045334: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80045338: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x8004533C: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x80045340: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x80045344: jr          $ra
    // 0x80045348: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    TRACE_RETURN()
    return;
    // 0x80045348: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_8004534C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004534C: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80045350: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80045354: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80045358: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8004535C: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x80045360: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80045364: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80045368: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8004536C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80045370: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80045374: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80045378: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8004537C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80045380: addiu       $s6, $zero, 0xFF
    ctx->r22 = ADD32(0, 0XFF);
    // 0x80045384: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80045388: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8004538C: jal         0x8004C388
    // 0x80045390: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004C388(rdram, ctx);
        goto after_0;
    // 0x80045390: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80045394: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80045398: addiu       $a2, $a2, 0x7A5C
    ctx->r6 = ADD32(ctx->r6, 0X7A5C);
    // 0x8004539C: addiu       $a0, $zero, -0xFE
    ctx->r4 = ADD32(0, -0XFE);
    // 0x800453A0: jal         0x8004BCF0
    // 0x800453A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004BCF0(rdram, ctx);
        goto after_1;
    // 0x800453A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x800453A8: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x800453AC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800453B0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800453B4: addiu       $a1, $a1, -0x5138
    ctx->r5 = ADD32(ctx->r5, -0X5138);
    // 0x800453B8: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x800453BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800453C0: jal         0x80049660
    // 0x800453C4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_80049660(rdram, ctx);
        goto after_2;
    // 0x800453C4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_2:
    // 0x800453C8: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800453CC: jal         0x8000798C
    // 0x800453D0: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    func_8000798C(rdram, ctx);
        goto after_3;
    // 0x800453D0: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    after_3:
    // 0x800453D4: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800453D8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800453DC: jal         0x8004B1E0
    // 0x800453E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8004B1E0(rdram, ctx);
        goto after_4;
    // 0x800453E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x800453E4: addiu       $fp, $zero, 0x14
    ctx->r30 = ADD32(0, 0X14);
L_800453E8:
    // 0x800453E8: jal         0x800496B4
    // 0x800453EC: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    func_800496B4(rdram, ctx);
        goto after_5;
    // 0x800453EC: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    after_5:
    // 0x800453F0: lh          $v0, 0x64($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X64);
    // 0x800453F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800453F8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800453FC: beq         $v0, $at, L_80045438
    if (ctx->r2 == ctx->r1) {
        // 0x80045400: or          $s0, $s6, $zero
        ctx->r16 = ctx->r22 | 0;
            goto L_80045438;
    }
    // 0x80045400: or          $s0, $s6, $zero
    ctx->r16 = ctx->r22 | 0;
    // 0x80045404: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80045408: beq         $v0, $at, L_800454B8
    if (ctx->r2 == ctx->r1) {
        // 0x8004540C: sll         $t3, $s0, 24
        ctx->r11 = S32(ctx->r16 << 24);
            goto L_800454B8;
    }
    // 0x8004540C: sll         $t3, $s0, 24
    ctx->r11 = S32(ctx->r16 << 24);
    // 0x80045410: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80045414: beq         $v0, $at, L_80045580
    if (ctx->r2 == ctx->r1) {
        // 0x80045418: sra         $s0, $t3, 16
        ctx->r16 = S32(SIGNED(ctx->r11) >> 16);
            goto L_80045580;
    }
    // 0x80045418: sra         $s0, $t3, 16
    ctx->r16 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8004541C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80045420: beq         $v0, $at, L_80045610
    if (ctx->r2 == ctx->r1) {
        // 0x80045424: nop
    
            goto L_80045610;
    }
    // 0x80045424: nop

    // 0x80045428: or          $s0, $s6, $zero
    ctx->r16 = ctx->r22 | 0;
    // 0x8004542C: sll         $t7, $s0, 24
    ctx->r15 = S32(ctx->r16 << 24);
    // 0x80045430: b           L_8004566C
    // 0x80045434: sra         $s0, $t7, 16
    ctx->r16 = S32(SIGNED(ctx->r15) >> 16);
        goto L_8004566C;
    // 0x80045434: sra         $s0, $t7, 16
    ctx->r16 = S32(SIGNED(ctx->r15) >> 16);
L_80045438:
    // 0x80045438: addiu       $a1, $v0, 0x3
    ctx->r5 = ADD32(ctx->r2, 0X3);
    // 0x8004543C: sll         $t9, $a1, 16
    ctx->r25 = S32(ctx->r5 << 16);
    // 0x80045440: sra         $a1, $t9, 16
    ctx->r5 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80045444: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80045448: jal         0x8004C388
    // 0x8004544C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004C388(rdram, ctx);
        goto after_6;
    // 0x8004544C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x80045450: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80045454: addiu       $a2, $a2, 0x7A70
    ctx->r6 = ADD32(ctx->r6, 0X7A70);
    // 0x80045458: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x8004545C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80045460: jal         0x8004C340
    // 0x80045464: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    func_8004C340(rdram, ctx);
        goto after_7;
    // 0x80045464: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_7:
    // 0x80045468: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8004546C: lhu         $v1, -0x2E58($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2E58);
    // 0x80045470: or          $s0, $s6, $zero
    ctx->r16 = ctx->r22 | 0;
    // 0x80045474: sll         $t7, $s0, 24
    ctx->r15 = S32(ctx->r16 << 24);
    // 0x80045478: andi        $t1, $v1, 0x200
    ctx->r9 = ctx->r3 & 0X200;
    // 0x8004547C: beq         $t1, $zero, L_80045494
    if (ctx->r9 == 0) {
        // 0x80045480: andi        $t4, $v1, 0x100
        ctx->r12 = ctx->r3 & 0X100;
            goto L_80045494;
    }
    // 0x80045480: andi        $t4, $v1, 0x100
    ctx->r12 = ctx->r3 & 0X100;
    // 0x80045484: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80045488: sll         $t2, $s2, 16
    ctx->r10 = S32(ctx->r18 << 16);
    // 0x8004548C: b           L_800454B0
    // 0x80045490: sra         $s2, $t2, 16
    ctx->r18 = S32(SIGNED(ctx->r10) >> 16);
        goto L_800454B0;
    // 0x80045490: sra         $s2, $t2, 16
    ctx->r18 = S32(SIGNED(ctx->r10) >> 16);
L_80045494:
    // 0x80045494: beq         $t4, $zero, L_800454B0
    if (ctx->r12 == 0) {
        // 0x80045498: nop
    
            goto L_800454B0;
    }
    // 0x80045498: nop

    // 0x8004549C: blez        $s2, L_800454B0
    if (SIGNED(ctx->r18) <= 0) {
        // 0x800454A0: nop
    
            goto L_800454B0;
    }
    // 0x800454A0: nop

    // 0x800454A4: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x800454A8: sll         $t5, $s2, 16
    ctx->r13 = S32(ctx->r18 << 16);
    // 0x800454AC: sra         $s2, $t5, 16
    ctx->r18 = S32(SIGNED(ctx->r13) >> 16);
L_800454B0:
    // 0x800454B0: b           L_8004566C
    // 0x800454B4: sra         $s0, $t7, 16
    ctx->r16 = S32(SIGNED(ctx->r15) >> 16);
        goto L_8004566C;
    // 0x800454B4: sra         $s0, $t7, 16
    ctx->r16 = S32(SIGNED(ctx->r15) >> 16);
L_800454B8:
    // 0x800454B8: addiu       $a1, $v0, 0x3
    ctx->r5 = ADD32(ctx->r2, 0X3);
    // 0x800454BC: sll         $t9, $a1, 16
    ctx->r25 = S32(ctx->r5 << 16);
    // 0x800454C0: sra         $a1, $t9, 16
    ctx->r5 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800454C4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800454C8: jal         0x8004C388
    // 0x800454CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004C388(rdram, ctx);
        goto after_8;
    // 0x800454CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // 0x800454D0: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x800454D4: addiu       $a2, $a2, 0x7A74
    ctx->r6 = ADD32(ctx->r6, 0X7A74);
    // 0x800454D8: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x800454DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800454E0: jal         0x8004C340
    // 0x800454E4: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    func_8004C340(rdram, ctx);
        goto after_9;
    // 0x800454E4: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_9:
    // 0x800454E8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800454EC: lhu         $v1, -0x2E5A($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2E5A);
    // 0x800454F0: andi        $t1, $v1, 0x200
    ctx->r9 = ctx->r3 & 0X200;
    // 0x800454F4: beq         $t1, $zero, L_8004550C
    if (ctx->r9 == 0) {
        // 0x800454F8: andi        $t4, $v1, 0x100
        ctx->r12 = ctx->r3 & 0X100;
            goto L_8004550C;
    }
    // 0x800454F8: andi        $t4, $v1, 0x100
    ctx->r12 = ctx->r3 & 0X100;
    // 0x800454FC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80045500: sll         $t2, $s3, 16
    ctx->r10 = S32(ctx->r19 << 16);
    // 0x80045504: b           L_80045520
    // 0x80045508: sra         $s3, $t2, 16
    ctx->r19 = S32(SIGNED(ctx->r10) >> 16);
        goto L_80045520;
    // 0x80045508: sra         $s3, $t2, 16
    ctx->r19 = S32(SIGNED(ctx->r10) >> 16);
L_8004550C:
    // 0x8004550C: beq         $t4, $zero, L_80045520
    if (ctx->r12 == 0) {
        // 0x80045510: nop
    
            goto L_80045520;
    }
    // 0x80045510: nop

    // 0x80045514: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x80045518: sll         $t5, $s3, 16
    ctx->r13 = S32(ctx->r19 << 16);
    // 0x8004551C: sra         $s3, $t5, 16
    ctx->r19 = S32(SIGNED(ctx->r13) >> 16);
L_80045520:
    // 0x80045520: bgezl       $s3, L_80045530
    if (SIGNED(ctx->r19) >= 0) {
        // 0x80045524: slti        $at, $s3, 0xC
        ctx->r1 = SIGNED(ctx->r19) < 0XC ? 1 : 0;
            goto L_80045530;
    }
    goto skip_0;
    // 0x80045524: slti        $at, $s3, 0xC
    ctx->r1 = SIGNED(ctx->r19) < 0XC ? 1 : 0;
    skip_0:
    // 0x80045528: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8004552C: slti        $at, $s3, 0xC
    ctx->r1 = SIGNED(ctx->r19) < 0XC ? 1 : 0;
L_80045530:
    // 0x80045530: bne         $at, $zero, L_8004553C
    if (ctx->r1 != 0) {
        // 0x80045534: nop
    
            goto L_8004553C;
    }
    // 0x80045534: nop

    // 0x80045538: addiu       $s3, $zero, 0xB
    ctx->r19 = ADD32(0, 0XB);
L_8004553C:
    // 0x8004553C: beql        $s3, $s7, L_80045574
    if (ctx->r19 == ctx->r23) {
        // 0x80045540: or          $s0, $s6, $zero
        ctx->r16 = ctx->r22 | 0;
            goto L_80045574;
    }
    goto skip_1;
    // 0x80045540: or          $s0, $s6, $zero
    ctx->r16 = ctx->r22 | 0;
    skip_1:
    // 0x80045544: sll         $s7, $s3, 16
    ctx->r23 = S32(ctx->r19 << 16);
    // 0x80045548: sra         $t7, $s7, 16
    ctx->r15 = S32(SIGNED(ctx->r23) >> 16);
    // 0x8004554C: or          $s7, $t7, $zero
    ctx->r23 = ctx->r15 | 0;
    // 0x80045550: jal         0x8004B21C
    // 0x80045554: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    func_8004B21C(rdram, ctx);
        goto after_10;
    // 0x80045554: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    after_10:
    // 0x80045558: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x8004555C: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80045560: jal         0x8004B1E0
    // 0x80045564: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_8004B1E0(rdram, ctx);
        goto after_11;
    // 0x80045564: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_11:
    // 0x80045568: jal         0x8000798C
    // 0x8004556C: nop

    func_8000798C(rdram, ctx);
        goto after_12;
    // 0x8004556C: nop

    after_12:
    // 0x80045570: or          $s0, $s6, $zero
    ctx->r16 = ctx->r22 | 0;
L_80045574:
    // 0x80045574: sll         $t9, $s0, 24
    ctx->r25 = S32(ctx->r16 << 24);
    // 0x80045578: b           L_8004566C
    // 0x8004557C: sra         $s0, $t9, 16
    ctx->r16 = S32(SIGNED(ctx->r25) >> 16);
        goto L_8004566C;
    // 0x8004557C: sra         $s0, $t9, 16
    ctx->r16 = S32(SIGNED(ctx->r25) >> 16);
L_80045580:
    // 0x80045580: addiu       $a1, $v0, 0x3
    ctx->r5 = ADD32(ctx->r2, 0X3);
    // 0x80045584: sll         $t1, $a1, 16
    ctx->r9 = S32(ctx->r5 << 16);
    // 0x80045588: sra         $a1, $t1, 16
    ctx->r5 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8004558C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80045590: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80045594: jal         0x8004C388
    // 0x80045598: or          $s1, $s6, $zero
    ctx->r17 = ctx->r22 | 0;
    func_8004C388(rdram, ctx);
        goto after_13;
    // 0x80045598: or          $s1, $s6, $zero
    ctx->r17 = ctx->r22 | 0;
    after_13:
    // 0x8004559C: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x800455A0: addiu       $a2, $a2, 0x7A78
    ctx->r6 = ADD32(ctx->r6, 0X7A78);
    // 0x800455A4: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x800455A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800455AC: jal         0x8004C340
    // 0x800455B0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_8004C340(rdram, ctx);
        goto after_14;
    // 0x800455B0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_14:
    // 0x800455B4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800455B8: lhu         $v1, -0x2E58($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2E58);
    // 0x800455BC: slti        $at, $s1, 0xFF
    ctx->r1 = SIGNED(ctx->r17) < 0XFF ? 1 : 0;
    // 0x800455C0: andi        $t3, $v1, 0x200
    ctx->r11 = ctx->r3 & 0X200;
    // 0x800455C4: beq         $t3, $zero, L_800455E4
    if (ctx->r11 == 0) {
        // 0x800455C8: andi        $t5, $v1, 0x100
        ctx->r13 = ctx->r3 & 0X100;
            goto L_800455E4;
    }
    // 0x800455C8: andi        $t5, $v1, 0x100
    ctx->r13 = ctx->r3 & 0X100;
    // 0x800455CC: beq         $at, $zero, L_800455E4
    if (ctx->r1 == 0) {
        // 0x800455D0: nop
    
            goto L_800455E4;
    }
    // 0x800455D0: nop

    // 0x800455D4: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x800455D8: andi        $s1, $s6, 0xFF
    ctx->r17 = ctx->r22 & 0XFF;
    // 0x800455DC: b           L_80045600
    // 0x800455E0: or          $s6, $s1, $zero
    ctx->r22 = ctx->r17 | 0;
        goto L_80045600;
    // 0x800455E0: or          $s6, $s1, $zero
    ctx->r22 = ctx->r17 | 0;
L_800455E4:
    // 0x800455E4: beql        $t5, $zero, L_80045604
    if (ctx->r13 == 0) {
        // 0x800455E8: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80045604;
    }
    goto skip_2;
    // 0x800455E8: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    skip_2:
    // 0x800455EC: blezl       $s1, L_80045604
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800455F0: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80045604;
    }
    goto skip_3;
    // 0x800455F0: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    skip_3:
    // 0x800455F4: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    // 0x800455F8: andi        $s1, $s6, 0xFF
    ctx->r17 = ctx->r22 & 0XFF;
    // 0x800455FC: or          $s6, $s1, $zero
    ctx->r22 = ctx->r17 | 0;
L_80045600:
    // 0x80045600: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_80045604:
    // 0x80045604: sll         $t7, $s0, 24
    ctx->r15 = S32(ctx->r16 << 24);
    // 0x80045608: b           L_8004566C
    // 0x8004560C: sra         $s0, $t7, 16
    ctx->r16 = S32(SIGNED(ctx->r15) >> 16);
        goto L_8004566C;
    // 0x8004560C: sra         $s0, $t7, 16
    ctx->r16 = S32(SIGNED(ctx->r15) >> 16);
L_80045610:
    // 0x80045610: lhu         $t9, -0x2E5A($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X2E5A);
    // 0x80045614: andi        $t0, $t9, 0x1000
    ctx->r8 = ctx->r25 & 0X1000;
    // 0x80045618: beq         $t0, $zero, L_8004566C
    if (ctx->r8 == 0) {
        // 0x8004561C: nop
    
            goto L_8004566C;
    }
    // 0x8004561C: nop

    // 0x80045620: addiu       $s3, $zero, 0xB
    ctx->r19 = ADD32(0, 0XB);
    // 0x80045624: sll         $s7, $s3, 16
    ctx->r23 = S32(ctx->r19 << 16);
    // 0x80045628: sra         $t1, $s7, 16
    ctx->r9 = S32(SIGNED(ctx->r23) >> 16);
    // 0x8004562C: or          $s7, $t1, $zero
    ctx->r23 = ctx->r9 | 0;
    // 0x80045630: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80045634: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80045638: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8004563C: addiu       $s6, $zero, 0xFF
    ctx->r22 = ADD32(0, 0XFF);
    // 0x80045640: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80045644: jal         0x8004C4D8
    // 0x80045648: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    func_8004C4D8(rdram, ctx);
        goto after_15;
    // 0x80045648: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    after_15:
    // 0x8004564C: jal         0x8004B21C
    // 0x80045650: nop

    func_8004B21C(rdram, ctx);
        goto after_16;
    // 0x80045650: nop

    after_16:
    // 0x80045654: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x80045658: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
L_8004565C:
    // 0x8004565C: jal         0x8000798C
    // 0x80045660: nop

    func_8000798C(rdram, ctx);
        goto after_17;
    // 0x80045660: nop

    after_17:
    // 0x80045664: b           L_8004565C
    // 0x80045668: nop

        goto L_8004565C;
    // 0x80045668: nop

L_8004566C:
    // 0x8004566C: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x80045670: sll         $a1, $s4, 16
    ctx->r5 = S32(ctx->r20 << 16);
    // 0x80045674: sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16 << 16);
    // 0x80045678: sll         $a3, $s2, 16
    ctx->r7 = S32(ctx->r18 << 16);
    // 0x8004567C: sra         $t8, $a3, 16
    ctx->r24 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80045680: sra         $t7, $a2, 16
    ctx->r15 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80045684: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80045688: sra         $t5, $a0, 16
    ctx->r13 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8004568C: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x80045690: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80045694: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x80045698: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x8004569C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800456A0: jal         0x8004C580
    // 0x800456A4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_18;
    // 0x800456A4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_18:
    // 0x800456A8: bne         $v0, $zero, L_800456C0
    if (ctx->r2 != 0) {
        // 0x800456AC: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_800456C0;
    }
    // 0x800456AC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800456B0: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x800456B4: sll         $t9, $s2, 16
    ctx->r25 = S32(ctx->r18 << 16);
    // 0x800456B8: b           L_8004566C
    // 0x800456BC: sra         $s2, $t9, 16
    ctx->r18 = S32(SIGNED(ctx->r25) >> 16);
        goto L_8004566C;
    // 0x800456BC: sra         $s2, $t9, 16
    ctx->r18 = S32(SIGNED(ctx->r25) >> 16);
L_800456C0:
    // 0x800456C0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800456C4: lh          $t1, -0x2E60($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X2E60);
    // 0x800456C8: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800456CC: lh          $t5, -0x2E5E($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X2E5E);
    // 0x800456D0: div         $zero, $t1, $fp
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r30))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r30)));
    // 0x800456D4: mflo        $t2
    ctx->r10 = lo;
    // 0x800456D8: addu        $s5, $s5, $t2
    ctx->r21 = ADD32(ctx->r21, ctx->r10);
    // 0x800456DC: bne         $fp, $zero, L_800456E8
    if (ctx->r30 != 0) {
        // 0x800456E0: nop
    
            goto L_800456E8;
    }
    // 0x800456E0: nop

    // 0x800456E4: break       7
    do_break(2147768036);
L_800456E8:
    // 0x800456E8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800456EC: bne         $fp, $at, L_80045700
    if (ctx->r30 != ctx->r1) {
        // 0x800456F0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80045700;
    }
    // 0x800456F0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800456F4: bne         $t1, $at, L_80045700
    if (ctx->r9 != ctx->r1) {
        // 0x800456F8: nop
    
            goto L_80045700;
    }
    // 0x800456F8: nop

    // 0x800456FC: break       6
    do_break(2147768060);
L_80045700:
    // 0x80045700: div         $zero, $t5, $fp
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r30))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r30)));
    // 0x80045704: mflo        $t6
    ctx->r14 = lo;
    // 0x80045708: sll         $t3, $s5, 16
    ctx->r11 = S32(ctx->r21 << 16);
    // 0x8004570C: addu        $s4, $s4, $t6
    ctx->r20 = ADD32(ctx->r20, ctx->r14);
    // 0x80045710: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80045714: sll         $t7, $s4, 16
    ctx->r15 = S32(ctx->r20 << 16);
    // 0x80045718: or          $s5, $t4, $zero
    ctx->r21 = ctx->r12 | 0;
    // 0x8004571C: bne         $fp, $zero, L_80045728
    if (ctx->r30 != 0) {
        // 0x80045720: nop
    
            goto L_80045728;
    }
    // 0x80045720: nop

    // 0x80045724: break       7
    do_break(2147768100);
L_80045728:
    // 0x80045728: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004572C: bne         $fp, $at, L_80045740
    if (ctx->r30 != ctx->r1) {
        // 0x80045730: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80045740;
    }
    // 0x80045730: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80045734: bne         $t5, $at, L_80045740
    if (ctx->r13 != ctx->r1) {
        // 0x80045738: nop
    
            goto L_80045740;
    }
    // 0x80045738: nop

    // 0x8004573C: break       6
    do_break(2147768124);
L_80045740:
    // 0x80045740: sra         $s4, $t7, 16
    ctx->r20 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80045744: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80045748: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8004574C: jal         0x8004C388
    // 0x80045750: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004C388(rdram, ctx);
        goto after_19;
    // 0x80045750: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_19:
    // 0x80045754: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80045758: addiu       $a2, $a2, 0x7A7C
    ctx->r6 = ADD32(ctx->r6, 0X7A7C);
    // 0x8004575C: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80045760: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80045764: jal         0x8004C340
    // 0x80045768: lh          $a3, 0xD8($s1)
    ctx->r7 = MEM_H(ctx->r17, 0XD8);
    func_8004C340(rdram, ctx);
        goto after_20;
    // 0x80045768: lh          $a3, 0xD8($s1)
    ctx->r7 = MEM_H(ctx->r17, 0XD8);
    after_20:
    // 0x8004576C: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80045770: addiu       $a2, $a2, 0x7A8C
    ctx->r6 = ADD32(ctx->r6, 0X7A8C);
    // 0x80045774: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80045778: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004577C: jal         0x8004C340
    // 0x80045780: lh          $a3, 0xDA($s1)
    ctx->r7 = MEM_H(ctx->r17, 0XDA);
    func_8004C340(rdram, ctx);
        goto after_21;
    // 0x80045780: lh          $a3, 0xDA($s1)
    ctx->r7 = MEM_H(ctx->r17, 0XDA);
    after_21:
    // 0x80045784: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80045788: addiu       $a2, $a2, 0x7A9C
    ctx->r6 = ADD32(ctx->r6, 0X7A9C);
    // 0x8004578C: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80045790: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80045794: jal         0x8004C340
    // 0x80045798: lh          $a3, 0xDC($s1)
    ctx->r7 = MEM_H(ctx->r17, 0XDC);
    func_8004C340(rdram, ctx);
        goto after_22;
    // 0x80045798: lh          $a3, 0xDC($s1)
    ctx->r7 = MEM_H(ctx->r17, 0XDC);
    after_22:
    // 0x8004579C: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x800457A0: addiu       $a2, $a2, 0x7AAC
    ctx->r6 = ADD32(ctx->r6, 0X7AAC);
    // 0x800457A4: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x800457A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800457AC: jal         0x8004C340
    // 0x800457B0: lh          $a3, 0xDE($s1)
    ctx->r7 = MEM_H(ctx->r17, 0XDE);
    func_8004C340(rdram, ctx);
        goto after_23;
    // 0x800457B0: lh          $a3, 0xDE($s1)
    ctx->r7 = MEM_H(ctx->r17, 0XDE);
    after_23:
    // 0x800457B4: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x800457B8: addiu       $a2, $a2, 0x7ABC
    ctx->r6 = ADD32(ctx->r6, 0X7ABC);
    // 0x800457BC: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x800457C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800457C4: jal         0x8004C340
    // 0x800457C8: lh          $a3, 0xE0($s1)
    ctx->r7 = MEM_H(ctx->r17, 0XE0);
    func_8004C340(rdram, ctx);
        goto after_24;
    // 0x800457C8: lh          $a3, 0xE0($s1)
    ctx->r7 = MEM_H(ctx->r17, 0XE0);
    after_24:
    // 0x800457CC: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x800457D0: addiu       $a2, $a2, 0x7ACC
    ctx->r6 = ADD32(ctx->r6, 0X7ACC);
    // 0x800457D4: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x800457D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800457DC: jal         0x8004C340
    // 0x800457E0: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    func_8004C340(rdram, ctx);
        goto after_25;
    // 0x800457E0: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    after_25:
    // 0x800457E4: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x800457E8: addiu       $a2, $a2, 0x7AD4
    ctx->r6 = ADD32(ctx->r6, 0X7AD4);
    // 0x800457EC: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x800457F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800457F4: jal         0x8004C340
    // 0x800457F8: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    func_8004C340(rdram, ctx);
        goto after_26;
    // 0x800457F8: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_26:
    // 0x800457FC: jal         0x8000798C
    // 0x80045800: nop

    func_8000798C(rdram, ctx);
        goto after_27;
    // 0x80045800: nop

    after_27:
    // 0x80045804: b           L_800453E8
    // 0x80045808: nop

        goto L_800453E8;
    // 0x80045808: nop

    // 0x8004580C: nop

    // 0x80045810: nop

    // 0x80045814: nop

    // 0x80045818: nop

    // 0x8004581C: nop

    // 0x80045820: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80045824: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80045828: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8004582C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80045830: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80045834: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80045838: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8004583C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80045840: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80045844: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80045848: jr          $ra
    // 0x8004584C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    TRACE_RETURN()
    return;
    // 0x8004584C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_80045850(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80045850: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80045854: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80045858: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8004585C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80045860: jal         0x8004B1E0
    // 0x80045864: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8004B1E0(rdram, ctx);
        goto after_0;
    // 0x80045864: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80045868: jal         0x8000798C
    // 0x8004586C: nop

    func_8000798C(rdram, ctx);
        goto after_1;
    // 0x8004586C: nop

    after_1:
    // 0x80045870: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80045874: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80045878: addiu       $a2, $zero, -0xFF
    ctx->r6 = ADD32(0, -0XFF);
    // 0x8004587C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80045880: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80045884: jal         0x8004C580
    // 0x80045888: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004C580(rdram, ctx);
        goto after_2;
    // 0x80045888: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_2:
    // 0x8004588C: jal         0x8000798C
    // 0x80045890: nop

    func_8000798C(rdram, ctx);
        goto after_3;
    // 0x80045890: nop

    after_3:
    // 0x80045894: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80045898: addiu       $s0, $s0, -0x2E5A
    ctx->r16 = ADD32(ctx->r16, -0X2E5A);
    // 0x8004589C: lhu         $t6, 0x0($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X0);
L_800458A0:
    // 0x800458A0: andi        $t7, $t6, 0x1000
    ctx->r15 = ctx->r14 & 0X1000;
    // 0x800458A4: beq         $t7, $zero, L_800458D4
    if (ctx->r15 == 0) {
        // 0x800458A8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800458D4;
    }
    // 0x800458A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800458AC: jal         0x8004C4D8
    // 0x800458B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004C4D8(rdram, ctx);
        goto after_4;
    // 0x800458B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x800458B4: jal         0x8004B21C
    // 0x800458B8: nop

    func_8004B21C(rdram, ctx);
        goto after_5;
    // 0x800458B8: nop

    after_5:
    // 0x800458BC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800458C0: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
L_800458C4:
    // 0x800458C4: jal         0x8000798C
    // 0x800458C8: nop

    func_8000798C(rdram, ctx);
        goto after_6;
    // 0x800458C8: nop

    after_6:
    // 0x800458CC: b           L_800458C4
    // 0x800458D0: nop

        goto L_800458C4;
    // 0x800458D0: nop

L_800458D4:
    // 0x800458D4: jal         0x8000798C
    // 0x800458D8: nop

    func_8000798C(rdram, ctx);
        goto after_7;
    // 0x800458D8: nop

    after_7:
    // 0x800458DC: b           L_800458A0
    // 0x800458E0: lhu         $t6, 0x0($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X0);
        goto L_800458A0;
    // 0x800458E0: lhu         $t6, 0x0($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X0);
    // 0x800458E4: nop

    // 0x800458E8: nop

    // 0x800458EC: nop

    // 0x800458F0: nop

    // 0x800458F4: nop

    // 0x800458F8: nop

    // 0x800458FC: nop

    // 0x80045900: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80045904: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80045908: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8004590C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80045914(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80045914: addiu       $sp, $sp, -0x240
    ctx->r29 = ADD32(ctx->r29, -0X240);
    // 0x80045918: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x8004591C: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80045920: sdc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X50, ctx->r29);
    // 0x80045924: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80045928: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x8004592C: sw          $fp, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r30;
    // 0x80045930: sw          $s7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r23;
    // 0x80045934: sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // 0x80045938: sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // 0x8004593C: sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // 0x80045940: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // 0x80045944: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x80045948: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x8004594C: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x80045950: sdc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X48, ctx->r29);
    // 0x80045954: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x80045958: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x8004595C: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80045960: sw          $a0, 0x240($sp)
    MEM_W(0X240, ctx->r29) = ctx->r4;
    // 0x80045964: sw          $zero, 0x22C($sp)
    MEM_W(0X22C, ctx->r29) = 0;
    // 0x80045968: sh          $zero, 0x226($sp)
    MEM_H(0X226, ctx->r29) = 0;
    // 0x8004596C: sh          $t6, 0x224($sp)
    MEM_H(0X224, ctx->r29) = ctx->r14;
    // 0x80045970: sh          $zero, 0xB0($sp)
    MEM_H(0XB0, ctx->r29) = 0;
    // 0x80045974: addiu       $v0, $sp, 0x98
    ctx->r2 = ADD32(ctx->r29, 0X98);
    // 0x80045978: addiu       $v1, $sp, 0xA4
    ctx->r3 = ADD32(ctx->r29, 0XA4);
    // 0x8004597C: mov.s       $f30, $f24
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    ctx->f30.fl = ctx->f24.fl;
L_80045980:
    // 0x80045980: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80045984: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80045988: bne         $at, $zero, L_80045980
    if (ctx->r1 != 0) {
        // 0x8004598C: swc1        $f24, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f24.u32l;
            goto L_80045980;
    }
    // 0x8004598C: swc1        $f24, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f24.u32l;
    // 0x80045990: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80045994: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80045998: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8004599C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800459A0: addiu       $v1, $v1, -0x6C40
    ctx->r3 = ADD32(ctx->r3, -0X6C40);
    // 0x800459A4: addiu       $v0, $v0, -0x6C50
    ctx->r2 = ADD32(ctx->r2, -0X6C50);
    // 0x800459A8: swc1        $f24, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f24.u32l;
    // 0x800459AC: swc1        $f24, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f24.u32l;
    // 0x800459B0: swc1        $f24, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f24.u32l;
    // 0x800459B4: swc1        $f24, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f24.u32l;
    // 0x800459B8: swc1        $f24, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f24.u32l;
    // 0x800459BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800459C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800459C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800459C8: jal         0x8004C388
    // 0x800459CC: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    func_8004C388(rdram, ctx);
        goto after_0;
    // 0x800459CC: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    after_0:
    // 0x800459D0: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x800459D4: addiu       $a2, $a2, 0x7B28
    ctx->r6 = ADD32(ctx->r6, 0X7B28);
    // 0x800459D8: addiu       $a0, $zero, -0xFE
    ctx->r4 = ADD32(0, -0XFE);
    // 0x800459DC: jal         0x8004BCF0
    // 0x800459E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004BCF0(rdram, ctx);
        goto after_1;
    // 0x800459E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x800459E4: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x800459E8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800459EC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800459F0: addiu       $a1, $a1, -0x5108
    ctx->r5 = ADD32(ctx->r5, -0X5108);
    // 0x800459F4: addiu       $a0, $sp, 0x230
    ctx->r4 = ADD32(ctx->r29, 0X230);
    // 0x800459F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800459FC: jal         0x80049660
    // 0x80045A00: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_80049660(rdram, ctx);
        goto after_2;
    // 0x80045A00: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_2:
    // 0x80045A04: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80045A08: jal         0x800499B0
    // 0x80045A0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800499B0(rdram, ctx);
        goto after_3;
    // 0x80045A0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80045A10: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80045A14: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x80045A18: addiu       $a0, $a0, -0x2E00
    ctx->r4 = ADD32(ctx->r4, -0X2E00);
    // 0x80045A1C: sw          $t8, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r24;
    // 0x80045A20: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x80045A24: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80045A28: jal         0x80004CE0
    // 0x80045A2C: addiu       $a3, $sp, 0x19C
    ctx->r7 = ADD32(ctx->r29, 0X19C);
    func_80004CE0(rdram, ctx);
        goto after_4;
    // 0x80045A2C: addiu       $a3, $sp, 0x19C
    ctx->r7 = ADD32(ctx->r29, 0X19C);
    after_4:
    // 0x80045A30: jal         0x8000798C
    // 0x80045A34: sw          $v0, 0x198($sp)
    MEM_W(0X198, ctx->r29) = ctx->r2;
    func_8000798C(rdram, ctx);
        goto after_5;
    // 0x80045A34: sw          $v0, 0x198($sp)
    MEM_W(0X198, ctx->r29) = ctx->r2;
    after_5:
    // 0x80045A38: addiu       $s4, $sp, 0xB4
    ctx->r20 = ADD32(ctx->r29, 0XB4);
    // 0x80045A3C: addiu       $s0, $sp, 0xC8
    ctx->r16 = ADD32(ctx->r29, 0XC8);
L_80045A40:
    // 0x80045A40: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80045A44: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80045A48: jal         0x80004364
    // 0x80045A4C: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    func_80004364(rdram, ctx);
        goto after_6;
    // 0x80045A4C: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_6:
    // 0x80045A50: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    // 0x80045A54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80045A58: jal         0x8000C7C0
    // 0x80045A5C: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    func_8000C7C0(rdram, ctx);
        goto after_7;
    // 0x80045A5C: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_7:
    // 0x80045A60: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80045A64: sltu        $at, $s4, $s0
    ctx->r1 = ctx->r20 < ctx->r16 ? 1 : 0;
    // 0x80045A68: bne         $at, $zero, L_80045A40
    if (ctx->r1 != 0) {
        // 0x80045A6C: nop
    
            goto L_80045A40;
    }
    // 0x80045A6C: nop

    // 0x80045A70: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80045A74: lui         $s0, 0x8007
    ctx->r16 = S32(0X8007 << 16);
    // 0x80045A78: addiu       $s0, $s0, 0x7B34
    ctx->r16 = ADD32(ctx->r16, 0X7B34);
    // 0x80045A7C: lwc1        $f20, 0x7E90($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X7E90);
    // 0x80045A80: addiu       $s2, $sp, 0xC8
    ctx->r18 = ADD32(ctx->r29, 0XC8);
    // 0x80045A84: addiu       $s1, $sp, 0x17C
    ctx->r17 = ADD32(ctx->r29, 0X17C);
L_80045A88:
    // 0x80045A88: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80045A8C: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80045A90: jal         0x80004364
    // 0x80045A94: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    func_80004364(rdram, ctx);
        goto after_8;
    // 0x80045A94: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    after_8:
    // 0x80045A98: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x80045A9C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80045AA0: jal         0x8000C7C0
    // 0x80045AA4: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    func_8000C7C0(rdram, ctx);
        goto after_9;
    // 0x80045AA4: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    after_9:
    // 0x80045AA8: jal         0x80049CFC
    // 0x80045AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80049CFC(rdram, ctx);
        goto after_10;
    // 0x80045AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80045AB0: jal         0x80049D80
    // 0x80045AB4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80049D80(rdram, ctx);
        goto after_11;
    // 0x80045AB4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_11:
    // 0x80045AB8: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80045ABC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80045AC0: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x80045AC4: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x80045AC8: jal         0x80049DFC
    // 0x80045ACC: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    func_80049DFC(rdram, ctx);
        goto after_12;
    // 0x80045ACC: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    after_12:
    // 0x80045AD0: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80045AD4: sw          $v0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r2;
    // 0x80045AD8: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x80045ADC: swc1        $f20, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->f20.u32l;
    // 0x80045AE0: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x80045AE4: jal         0x8004A148
    // 0x80045AE8: lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X4);
    func_8004A148(rdram, ctx);
        goto after_13;
    // 0x80045AE8: lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X4);
    after_13:
    // 0x80045AEC: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x80045AF0: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80045AF4: bne         $s2, $s1, L_80045A88
    if (ctx->r18 != ctx->r17) {
        // 0x80045AF8: sh          $zero, 0x28($t4)
        MEM_H(0X28, ctx->r12) = 0;
            goto L_80045A88;
    }
    // 0x80045AF8: sh          $zero, 0x28($t4)
    MEM_H(0X28, ctx->r12) = 0;
    // 0x80045AFC: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x80045B00: mtc1        $at, $f29
    ctx->f_odd[(29 - 1) * 2] = ctx->r1;
    // 0x80045B04: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80045B08: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80045B0C: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x80045B10: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x80045B14: addiu       $s7, $zero, 0x3
    ctx->r23 = ADD32(0, 0X3);
    // 0x80045B18: addiu       $s6, $sp, 0x1A0
    ctx->r22 = ADD32(ctx->r29, 0X1A0);
    // 0x80045B1C: addiu       $s5, $sp, 0x1E0
    ctx->r21 = ADD32(ctx->r29, 0X1E0);
L_80045B20:
    // 0x80045B20: jal         0x800496B4
    // 0x80045B24: addiu       $a0, $sp, 0x230
    ctx->r4 = ADD32(ctx->r29, 0X230);
    func_800496B4(rdram, ctx);
        goto after_14;
    // 0x80045B24: addiu       $a0, $sp, 0x230
    ctx->r4 = ADD32(ctx->r29, 0X230);
    after_14:
    // 0x80045B28: lh          $v1, 0x23C($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X23C);
    // 0x80045B2C: addiu       $t5, $v1, -0x1
    ctx->r13 = ADD32(ctx->r3, -0X1);
    // 0x80045B30: sltiu       $at, $t5, 0x9
    ctx->r1 = ctx->r13 < 0X9 ? 1 : 0;
    // 0x80045B34: beq         $at, $zero, L_80046014
    if (ctx->r1 == 0) {
        // 0x80045B38: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_80046014;
    }
    // 0x80045B38: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80045B3C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80045B40: addu        $at, $at, $t5
    gpr jr_addend_80045B48 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80045B44: lw          $t5, 0x7E94($at)
    ctx->r13 = ADD32(ctx->r1, 0X7E94);
    // 0x80045B48: jr          $t5
    // 0x80045B4C: nop

    switch (jr_addend_80045B48 >> 2) {
        case 0: goto L_80045B50; break;
        case 1: goto L_80045BDC; break;
        case 2: goto L_80045C3C; break;
        case 3: goto L_80045CAC; break;
        case 4: goto L_80045D04; break;
        case 5: goto L_80045D5C; break;
        case 6: goto L_80045DB4; break;
        case 7: goto L_80045E24; break;
        case 8: goto L_80045EEC; break;
        default: switch_error(__func__, 0x80045B48, 0x80077E94);
    }
    // 0x80045B4C: nop

L_80045B50:
    // 0x80045B50: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80045B54: lhu         $v0, -0x2E58($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2E58);
    // 0x80045B58: addiu       $a1, $v1, 0x3
    ctx->r5 = ADD32(ctx->r3, 0X3);
    // 0x80045B5C: sll         $t4, $a1, 16
    ctx->r12 = S32(ctx->r5 << 16);
    // 0x80045B60: andi        $t6, $v0, 0x200
    ctx->r14 = ctx->r2 & 0X200;
    // 0x80045B64: beq         $t6, $zero, L_80045B7C
    if (ctx->r14 == 0) {
        // 0x80045B68: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_80045B7C;
    }
    // 0x80045B68: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80045B6C: lh          $t7, 0x226($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X226);
    // 0x80045B70: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80045B74: b           L_80045BA0
    // 0x80045B78: sh          $t8, 0x226($sp)
    MEM_H(0X226, ctx->r29) = ctx->r24;
        goto L_80045BA0;
    // 0x80045B78: sh          $t8, 0x226($sp)
    MEM_H(0X226, ctx->r29) = ctx->r24;
L_80045B7C:
    // 0x80045B7C: andi        $t9, $v0, 0x100
    ctx->r25 = ctx->r2 & 0X100;
    // 0x80045B80: beq         $t9, $zero, L_80045BA0
    if (ctx->r25 == 0) {
        // 0x80045B84: lh          $t0, 0x226($sp)
        ctx->r8 = MEM_H(ctx->r29, 0X226);
            goto L_80045BA0;
    }
    // 0x80045B84: lh          $t0, 0x226($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X226);
    // 0x80045B88: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80045B8C: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x80045B90: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80045B94: bgez        $t3, L_80045BA0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80045B98: sh          $t1, 0x226($sp)
        MEM_H(0X226, ctx->r29) = ctx->r9;
            goto L_80045BA0;
    }
    // 0x80045B98: sh          $t1, 0x226($sp)
    MEM_H(0X226, ctx->r29) = ctx->r9;
    // 0x80045B9C: sh          $zero, 0x226($sp)
    MEM_H(0X226, ctx->r29) = 0;
L_80045BA0:
    // 0x80045BA0: sll         $a2, $fp, 16
    ctx->r6 = S32(ctx->r30 << 16);
    // 0x80045BA4: sra         $t6, $a2, 16
    ctx->r14 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80045BA8: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80045BAC: jal         0x8004C388
    // 0x80045BB0: sra         $a1, $t4, 16
    ctx->r5 = S32(SIGNED(ctx->r12) >> 16);
    func_8004C388(rdram, ctx);
        goto after_15;
    // 0x80045BB0: sra         $a1, $t4, 16
    ctx->r5 = S32(SIGNED(ctx->r12) >> 16);
    after_15:
    // 0x80045BB4: sll         $a1, $fp, 16
    ctx->r5 = S32(ctx->r30 << 16);
    // 0x80045BB8: sra         $t7, $a1, 16
    ctx->r15 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80045BBC: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80045BC0: addiu       $a2, $a2, 0x7B3C
    ctx->r6 = ADD32(ctx->r6, 0X7B3C);
    // 0x80045BC4: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80045BC8: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80045BCC: jal         0x8004C340
    // 0x80045BD0: lh          $a3, 0x226($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X226);
    func_8004C340(rdram, ctx);
        goto after_16;
    // 0x80045BD0: lh          $a3, 0x226($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X226);
    after_16:
    // 0x80045BD4: b           L_80046018
    // 0x80045BD8: lh          $t5, 0x226($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X226);
        goto L_80046018;
    // 0x80045BD8: lh          $t5, 0x226($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X226);
L_80045BDC:
    // 0x80045BDC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80045BE0: lhu         $v0, -0x2E58($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2E58);
    // 0x80045BE4: lh          $t9, 0xB0($sp)
    ctx->r25 = MEM_H(ctx->r29, 0XB0);
    // 0x80045BE8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80045BEC: andi        $t8, $v0, 0x200
    ctx->r24 = ctx->r2 & 0X200;
    // 0x80045BF0: beq         $t8, $zero, L_80045C18
    if (ctx->r24 == 0) {
        // 0x80045BF4: andi        $t6, $v0, 0x100
        ctx->r14 = ctx->r2 & 0X100;
            goto L_80045C18;
    }
    // 0x80045BF4: andi        $t6, $v0, 0x100
    ctx->r14 = ctx->r2 & 0X100;
    // 0x80045BF8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80045BFC: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x80045C00: sra         $t2, $t1, 16
    ctx->r10 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80045C04: bne         $t2, $at, L_80046014
    if (ctx->r10 != ctx->r1) {
        // 0x80045C08: sh          $t0, 0xB0($sp)
        MEM_H(0XB0, ctx->r29) = ctx->r8;
            goto L_80046014;
    }
    // 0x80045C08: sh          $t0, 0xB0($sp)
    MEM_H(0XB0, ctx->r29) = ctx->r8;
    // 0x80045C0C: addiu       $t5, $t0, -0x1
    ctx->r13 = ADD32(ctx->r8, -0X1);
    // 0x80045C10: b           L_80046014
    // 0x80045C14: sh          $t5, 0xB0($sp)
    MEM_H(0XB0, ctx->r29) = ctx->r13;
        goto L_80046014;
    // 0x80045C14: sh          $t5, 0xB0($sp)
    MEM_H(0XB0, ctx->r29) = ctx->r13;
L_80045C18:
    // 0x80045C18: beq         $t6, $zero, L_80046014
    if (ctx->r14 == 0) {
        // 0x80045C1C: lh          $t7, 0xB0($sp)
        ctx->r15 = MEM_H(ctx->r29, 0XB0);
            goto L_80046014;
    }
    // 0x80045C1C: lh          $t7, 0xB0($sp)
    ctx->r15 = MEM_H(ctx->r29, 0XB0);
    // 0x80045C20: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80045C24: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80045C28: sra         $t1, $t9, 16
    ctx->r9 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80045C2C: bgez        $t1, L_80046014
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80045C30: sh          $t8, 0xB0($sp)
        MEM_H(0XB0, ctx->r29) = ctx->r24;
            goto L_80046014;
    }
    // 0x80045C30: sh          $t8, 0xB0($sp)
    MEM_H(0XB0, ctx->r29) = ctx->r24;
    // 0x80045C34: b           L_80046014
    // 0x80045C38: sh          $zero, 0xB0($sp)
    MEM_H(0XB0, ctx->r29) = 0;
        goto L_80046014;
    // 0x80045C38: sh          $zero, 0xB0($sp)
    MEM_H(0XB0, ctx->r29) = 0;
L_80045C3C:
    // 0x80045C3C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80045C40: lhu         $v0, -0x2E58($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2E58);
    // 0x80045C44: lh          $t0, 0xB0($sp)
    ctx->r8 = MEM_H(ctx->r29, 0XB0);
    // 0x80045C48: andi        $t2, $v0, 0x200
    ctx->r10 = ctx->r2 & 0X200;
    // 0x80045C4C: beq         $t2, $zero, L_80045C70
    if (ctx->r10 == 0) {
        // 0x80045C50: andi        $t6, $v0, 0x100
        ctx->r14 = ctx->r2 & 0X100;
            goto L_80045C70;
    }
    // 0x80045C50: andi        $t6, $v0, 0x100
    ctx->r14 = ctx->r2 & 0X100;
    // 0x80045C54: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x80045C58: addu        $v0, $sp, $t3
    ctx->r2 = ADD32(ctx->r29, ctx->r11);
    // 0x80045C5C: lw          $v0, 0xB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB4);
    // 0x80045C60: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x80045C64: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80045C68: b           L_80046014
    // 0x80045C6C: sh          $t5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r13;
        goto L_80046014;
    // 0x80045C6C: sh          $t5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r13;
L_80045C70:
    // 0x80045C70: beq         $t6, $zero, L_80046014
    if (ctx->r14 == 0) {
        // 0x80045C74: lh          $t7, 0xB0($sp)
        ctx->r15 = MEM_H(ctx->r29, 0XB0);
            goto L_80046014;
    }
    // 0x80045C74: lh          $t7, 0xB0($sp)
    ctx->r15 = MEM_H(ctx->r29, 0XB0);
    // 0x80045C78: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80045C7C: addiu       $t9, $sp, 0xB4
    ctx->r25 = ADD32(ctx->r29, 0XB4);
    // 0x80045C80: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x80045C84: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80045C88: lh          $t1, 0x0($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X0);
    // 0x80045C8C: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80045C90: sh          $t2, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r10;
    // 0x80045C94: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80045C98: lh          $t0, 0x0($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X0);
    // 0x80045C9C: bgezl       $t0, L_80046018
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80045CA0: lh          $t5, 0x226($sp)
        ctx->r13 = MEM_H(ctx->r29, 0X226);
            goto L_80046018;
    }
    goto skip_0;
    // 0x80045CA0: lh          $t5, 0x226($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X226);
    skip_0:
    // 0x80045CA4: b           L_80046014
    // 0x80045CA8: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
        goto L_80046014;
    // 0x80045CA8: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
L_80045CAC:
    // 0x80045CAC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80045CB0: lhu         $v1, -0x2E5C($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2E5C);
    // 0x80045CB4: lh          $t4, 0xB0($sp)
    ctx->r12 = MEM_H(ctx->r29, 0XB0);
    // 0x80045CB8: andi        $t3, $v1, 0x200
    ctx->r11 = ctx->r3 & 0X200;
    // 0x80045CBC: beq         $t3, $zero, L_80045CE0
    if (ctx->r11 == 0) {
        // 0x80045CC0: andi        $t8, $v1, 0x100
        ctx->r24 = ctx->r3 & 0X100;
            goto L_80045CE0;
    }
    // 0x80045CC0: andi        $t8, $v1, 0x100
    ctx->r24 = ctx->r3 & 0X100;
    // 0x80045CC4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80045CC8: addu        $v0, $sp, $t5
    ctx->r2 = ADD32(ctx->r29, ctx->r13);
    // 0x80045CCC: lw          $v0, 0xB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB4);
    // 0x80045CD0: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x80045CD4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80045CD8: b           L_80046014
    // 0x80045CDC: sh          $t7, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r15;
        goto L_80046014;
    // 0x80045CDC: sh          $t7, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r15;
L_80045CE0:
    // 0x80045CE0: beq         $t8, $zero, L_80046014
    if (ctx->r24 == 0) {
        // 0x80045CE4: lh          $t9, 0xB0($sp)
        ctx->r25 = MEM_H(ctx->r29, 0XB0);
            goto L_80046014;
    }
    // 0x80045CE4: lh          $t9, 0xB0($sp)
    ctx->r25 = MEM_H(ctx->r29, 0XB0);
    // 0x80045CE8: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80045CEC: addu        $v0, $sp, $t1
    ctx->r2 = ADD32(ctx->r29, ctx->r9);
    // 0x80045CF0: lw          $v0, 0xB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB4);
    // 0x80045CF4: lh          $t2, 0x2($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X2);
    // 0x80045CF8: addiu       $t0, $t2, -0x1
    ctx->r8 = ADD32(ctx->r10, -0X1);
    // 0x80045CFC: b           L_80046014
    // 0x80045D00: sh          $t0, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r8;
        goto L_80046014;
    // 0x80045D00: sh          $t0, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r8;
L_80045D04:
    // 0x80045D04: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80045D08: lhu         $v1, -0x2E5C($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2E5C);
    // 0x80045D0C: lh          $t4, 0xB0($sp)
    ctx->r12 = MEM_H(ctx->r29, 0XB0);
    // 0x80045D10: andi        $t3, $v1, 0x200
    ctx->r11 = ctx->r3 & 0X200;
    // 0x80045D14: beq         $t3, $zero, L_80045D38
    if (ctx->r11 == 0) {
        // 0x80045D18: andi        $t8, $v1, 0x100
        ctx->r24 = ctx->r3 & 0X100;
            goto L_80045D38;
    }
    // 0x80045D18: andi        $t8, $v1, 0x100
    ctx->r24 = ctx->r3 & 0X100;
    // 0x80045D1C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80045D20: addu        $v0, $sp, $t5
    ctx->r2 = ADD32(ctx->r29, ctx->r13);
    // 0x80045D24: lw          $v0, 0xB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB4);
    // 0x80045D28: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x80045D2C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80045D30: b           L_80046014
    // 0x80045D34: sh          $t7, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r15;
        goto L_80046014;
    // 0x80045D34: sh          $t7, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r15;
L_80045D38:
    // 0x80045D38: beq         $t8, $zero, L_80046014
    if (ctx->r24 == 0) {
        // 0x80045D3C: lh          $t9, 0xB0($sp)
        ctx->r25 = MEM_H(ctx->r29, 0XB0);
            goto L_80046014;
    }
    // 0x80045D3C: lh          $t9, 0xB0($sp)
    ctx->r25 = MEM_H(ctx->r29, 0XB0);
    // 0x80045D40: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80045D44: addu        $v0, $sp, $t1
    ctx->r2 = ADD32(ctx->r29, ctx->r9);
    // 0x80045D48: lw          $v0, 0xB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB4);
    // 0x80045D4C: lh          $t2, 0x4($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X4);
    // 0x80045D50: addiu       $t0, $t2, -0x1
    ctx->r8 = ADD32(ctx->r10, -0X1);
    // 0x80045D54: b           L_80046014
    // 0x80045D58: sh          $t0, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r8;
        goto L_80046014;
    // 0x80045D58: sh          $t0, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r8;
L_80045D5C:
    // 0x80045D5C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80045D60: lhu         $v1, -0x2E5C($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2E5C);
    // 0x80045D64: lh          $t4, 0xB0($sp)
    ctx->r12 = MEM_H(ctx->r29, 0XB0);
    // 0x80045D68: andi        $t3, $v1, 0x200
    ctx->r11 = ctx->r3 & 0X200;
    // 0x80045D6C: beq         $t3, $zero, L_80045D90
    if (ctx->r11 == 0) {
        // 0x80045D70: andi        $t8, $v1, 0x100
        ctx->r24 = ctx->r3 & 0X100;
            goto L_80045D90;
    }
    // 0x80045D70: andi        $t8, $v1, 0x100
    ctx->r24 = ctx->r3 & 0X100;
    // 0x80045D74: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80045D78: addu        $v0, $sp, $t5
    ctx->r2 = ADD32(ctx->r29, ctx->r13);
    // 0x80045D7C: lw          $v0, 0xB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB4);
    // 0x80045D80: lh          $t6, 0x6($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X6);
    // 0x80045D84: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80045D88: b           L_80046014
    // 0x80045D8C: sh          $t7, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r15;
        goto L_80046014;
    // 0x80045D8C: sh          $t7, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r15;
L_80045D90:
    // 0x80045D90: beq         $t8, $zero, L_80046014
    if (ctx->r24 == 0) {
        // 0x80045D94: lh          $t9, 0xB0($sp)
        ctx->r25 = MEM_H(ctx->r29, 0XB0);
            goto L_80046014;
    }
    // 0x80045D94: lh          $t9, 0xB0($sp)
    ctx->r25 = MEM_H(ctx->r29, 0XB0);
    // 0x80045D98: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80045D9C: addu        $v0, $sp, $t1
    ctx->r2 = ADD32(ctx->r29, ctx->r9);
    // 0x80045DA0: lw          $v0, 0xB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB4);
    // 0x80045DA4: lh          $t2, 0x6($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X6);
    // 0x80045DA8: addiu       $t0, $t2, -0x1
    ctx->r8 = ADD32(ctx->r10, -0X1);
    // 0x80045DAC: b           L_80046014
    // 0x80045DB0: sh          $t0, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r8;
        goto L_80046014;
    // 0x80045DB0: sh          $t0, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r8;
L_80045DB4:
    // 0x80045DB4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80045DB8: lhu         $v0, -0x2E58($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2E58);
    // 0x80045DBC: lh          $t4, 0xB0($sp)
    ctx->r12 = MEM_H(ctx->r29, 0XB0);
    // 0x80045DC0: andi        $t3, $v0, 0x200
    ctx->r11 = ctx->r2 & 0X200;
    // 0x80045DC4: beq         $t3, $zero, L_80045DE8
    if (ctx->r11 == 0) {
        // 0x80045DC8: andi        $t8, $v0, 0x100
        ctx->r24 = ctx->r2 & 0X100;
            goto L_80045DE8;
    }
    // 0x80045DC8: andi        $t8, $v0, 0x100
    ctx->r24 = ctx->r2 & 0X100;
    // 0x80045DCC: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80045DD0: addu        $v0, $sp, $t5
    ctx->r2 = ADD32(ctx->r29, ctx->r13);
    // 0x80045DD4: lw          $v0, 0xB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB4);
    // 0x80045DD8: lh          $t6, 0x14($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X14);
    // 0x80045DDC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80045DE0: b           L_80046014
    // 0x80045DE4: sh          $t7, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r15;
        goto L_80046014;
    // 0x80045DE4: sh          $t7, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r15;
L_80045DE8:
    // 0x80045DE8: beq         $t8, $zero, L_80046014
    if (ctx->r24 == 0) {
        // 0x80045DEC: lh          $t9, 0xB0($sp)
        ctx->r25 = MEM_H(ctx->r29, 0XB0);
            goto L_80046014;
    }
    // 0x80045DEC: lh          $t9, 0xB0($sp)
    ctx->r25 = MEM_H(ctx->r29, 0XB0);
    // 0x80045DF0: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80045DF4: addiu       $t2, $sp, 0xB4
    ctx->r10 = ADD32(ctx->r29, 0XB4);
    // 0x80045DF8: addu        $v1, $t1, $t2
    ctx->r3 = ADD32(ctx->r9, ctx->r10);
    // 0x80045DFC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80045E00: lh          $t0, 0x14($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X14);
    // 0x80045E04: addiu       $t3, $t0, -0x1
    ctx->r11 = ADD32(ctx->r8, -0X1);
    // 0x80045E08: sh          $t3, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r11;
    // 0x80045E0C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80045E10: lh          $t4, 0x14($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X14);
    // 0x80045E14: bgezl       $t4, L_80046018
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80045E18: lh          $t5, 0x226($sp)
        ctx->r13 = MEM_H(ctx->r29, 0X226);
            goto L_80046018;
    }
    goto skip_1;
    // 0x80045E18: lh          $t5, 0x226($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X226);
    skip_1:
    // 0x80045E1C: b           L_80046014
    // 0x80045E20: sh          $zero, 0x14($v0)
    MEM_H(0X14, ctx->r2) = 0;
        goto L_80046014;
    // 0x80045E20: sh          $zero, 0x14($v0)
    MEM_H(0X14, ctx->r2) = 0;
L_80045E24:
    // 0x80045E24: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80045E28: lhu         $v0, -0x2E58($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2E58);
    // 0x80045E2C: sll         $a2, $fp, 16
    ctx->r6 = S32(ctx->r30 << 16);
    // 0x80045E30: sra         $t2, $a2, 16
    ctx->r10 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80045E34: andi        $t5, $v0, 0x200
    ctx->r13 = ctx->r2 & 0X200;
    // 0x80045E38: beq         $t5, $zero, L_80045E68
    if (ctx->r13 == 0) {
        // 0x80045E3C: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_80045E68;
    }
    // 0x80045E3C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80045E40: lw          $t6, 0x22C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X22C);
    // 0x80045E44: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80045E48: ldc1        $f10, 0x7EB8($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X7EB8);
    // 0x80045E4C: lwc1        $f6, 0x2C($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X2C);
    // 0x80045E50: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80045E54: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x80045E58: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80045E5C: swc1        $f18, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->f18.u32l;
    // 0x80045E60: b           L_80045E94
    // 0x80045E64: lh          $v1, 0x23C($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X23C);
        goto L_80045E94;
    // 0x80045E64: lh          $v1, 0x23C($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X23C);
L_80045E68:
    // 0x80045E68: andi        $t7, $v0, 0x100
    ctx->r15 = ctx->r2 & 0X100;
    // 0x80045E6C: beq         $t7, $zero, L_80045E94
    if (ctx->r15 == 0) {
        // 0x80045E70: lw          $t8, 0x22C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X22C);
            goto L_80045E94;
    }
    // 0x80045E70: lw          $t8, 0x22C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X22C);
    // 0x80045E74: lwc1        $f4, 0x2C($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X2C);
    // 0x80045E78: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80045E7C: ldc1        $f8, 0x7EC0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X7EC0);
    // 0x80045E80: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80045E84: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x80045E88: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80045E8C: swc1        $f16, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->f16.u32l;
    // 0x80045E90: lh          $v1, 0x23C($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X23C);
L_80045E94:
    // 0x80045E94: addiu       $a1, $v1, 0x3
    ctx->r5 = ADD32(ctx->r3, 0X3);
    // 0x80045E98: sll         $t9, $a1, 16
    ctx->r25 = S32(ctx->r5 << 16);
    // 0x80045E9C: sra         $a1, $t9, 16
    ctx->r5 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80045EA0: jal         0x8004C388
    // 0x80045EA4: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    func_8004C388(rdram, ctx);
        goto after_17;
    // 0x80045EA4: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    after_17:
    // 0x80045EA8: lw          $t3, 0x22C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X22C);
    // 0x80045EAC: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80045EB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80045EB4: lwc1        $f18, 0x2C($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X2C);
    // 0x80045EB8: sll         $a1, $fp, 16
    ctx->r5 = S32(ctx->r30 << 16);
    // 0x80045EBC: sra         $t0, $a1, 16
    ctx->r8 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80045EC0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80045EC4: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80045EC8: addiu       $a2, $a2, 0x7B40
    ctx->r6 = ADD32(ctx->r6, 0X7B40);
    // 0x80045ECC: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x80045ED0: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80045ED4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80045ED8: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80045EDC: jal         0x8004C340
    // 0x80045EE0: nop

    func_8004C340(rdram, ctx);
        goto after_18;
    // 0x80045EE0: nop

    after_18:
    // 0x80045EE4: b           L_80046018
    // 0x80045EE8: lh          $t5, 0x226($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X226);
        goto L_80046018;
    // 0x80045EE8: lh          $t5, 0x226($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X226);
L_80045EEC:
    // 0x80045EEC: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80045EF0: lhu         $t5, -0x2E5A($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X2E5A);
    // 0x80045EF4: andi        $t6, $t5, 0x1000
    ctx->r14 = ctx->r13 & 0X1000;
    // 0x80045EF8: beq         $t6, $zero, L_80046014
    if (ctx->r14 == 0) {
        // 0x80045EFC: addiu       $s4, $sp, 0xB4
        ctx->r20 = ADD32(ctx->r29, 0XB4);
            goto L_80046014;
    }
    // 0x80045EFC: addiu       $s4, $sp, 0xB4
    ctx->r20 = ADD32(ctx->r29, 0XB4);
    // 0x80045F00: addiu       $s0, $sp, 0xC8
    ctx->r16 = ADD32(ctx->r29, 0XC8);
L_80045F04:
    // 0x80045F04: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80045F08: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80045F0C: jal         0x800042A8
    // 0x80045F10: lw          $a1, 0x0($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X0);
    func_800042A8(rdram, ctx);
        goto after_19;
    // 0x80045F10: lw          $a1, 0x0($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X0);
    after_19:
    // 0x80045F14: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80045F18: sltu        $at, $s4, $s0
    ctx->r1 = ctx->r20 < ctx->r16 ? 1 : 0;
    // 0x80045F1C: bne         $at, $zero, L_80045F04
    if (ctx->r1 != 0) {
        // 0x80045F20: nop
    
            goto L_80045F04;
    }
    // 0x80045F20: nop

    // 0x80045F24: addiu       $s2, $sp, 0xC8
    ctx->r18 = ADD32(ctx->r29, 0XC8);
    // 0x80045F28: addiu       $s0, $sp, 0x17C
    ctx->r16 = ADD32(ctx->r29, 0X17C);
    // 0x80045F2C: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
L_80045F30:
    // 0x80045F30: jal         0x8004A0C4
    // 0x80045F34: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    func_8004A0C4(rdram, ctx);
        goto after_20;
    // 0x80045F34: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    after_20:
    // 0x80045F38: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80045F3C: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80045F40: jal         0x800042A8
    // 0x80045F44: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    func_800042A8(rdram, ctx);
        goto after_21;
    // 0x80045F44: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    after_21:
    // 0x80045F48: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80045F4C: bnel        $s2, $s0, L_80045F30
    if (ctx->r18 != ctx->r16) {
        // 0x80045F50: lw          $t7, 0x0($s2)
        ctx->r15 = MEM_W(ctx->r18, 0X0);
            goto L_80045F30;
    }
    goto skip_2;
    // 0x80045F50: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    skip_2:
    // 0x80045F54: lw          $t8, 0x22C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X22C);
    // 0x80045F58: jal         0x8004A0C4
    // 0x80045F5C: lw          $a0, 0xC($t8)
    ctx->r4 = MEM_W(ctx->r24, 0XC);
    func_8004A0C4(rdram, ctx);
        goto after_22;
    // 0x80045F5C: lw          $a0, 0xC($t8)
    ctx->r4 = MEM_W(ctx->r24, 0XC);
    after_22:
    // 0x80045F60: lw          $t9, 0x22C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X22C);
    // 0x80045F64: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80045F68: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80045F6C: lh          $t1, 0x34($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X34);
    // 0x80045F70: addiu       $a2, $a2, -0x6C60
    ctx->r6 = ADD32(ctx->r6, -0X6C60);
    // 0x80045F74: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80045F78: beq         $t1, $zero, L_80045F88
    if (ctx->r9 == 0) {
        // 0x80045F7C: nop
    
            goto L_80045F88;
    }
    // 0x80045F7C: nop

    // 0x80045F80: jal         0x8001026C
    // 0x80045F84: lw          $a1, 0x30($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X30);
    func_8001026C(rdram, ctx);
        goto after_23;
    // 0x80045F84: lw          $a1, 0x30($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X30);
    after_23:
L_80045F88:
    // 0x80045F88: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80045F8C: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80045F90: jal         0x800042A8
    // 0x80045F94: lw          $a1, 0x22C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X22C);
    func_800042A8(rdram, ctx);
        goto after_24;
    // 0x80045F94: lw          $a1, 0x22C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X22C);
    after_24:
    // 0x80045F98: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80045F9C: jal         0x8004C4D8
    // 0x80045FA0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8004C4D8(rdram, ctx);
        goto after_25;
    // 0x80045FA0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_25:
    // 0x80045FA4: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80045FA8: sw          $t2, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r10;
L_80045FAC:
    // 0x80045FAC: jal         0x8000798C
    // 0x80045FB0: nop

    func_8000798C(rdram, ctx);
        goto after_26;
    // 0x80045FB0: nop

    after_26:
    // 0x80045FB4: lw          $t0, 0x19C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X19C);
    // 0x80045FB8: bne         $t0, $zero, L_80045FAC
    if (ctx->r8 != 0) {
        // 0x80045FBC: nop
    
            goto L_80045FAC;
    }
    // 0x80045FBC: nop

    // 0x80045FC0: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80045FC4: sh          $t3, 0x224($sp)
    MEM_H(0X224, ctx->r29) = ctx->r11;
    // 0x80045FC8: sh          $zero, 0x224($sp)
    MEM_H(0X224, ctx->r29) = 0;
    // 0x80045FCC: jal         0x80004E5C
    // 0x80045FD0: lw          $a0, 0x198($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X198);
    func_80004E5C(rdram, ctx);
        goto after_27;
    // 0x80045FD0: lw          $a0, 0x198($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X198);
    after_27:
    // 0x80045FD4: jal         0x80049C48
    // 0x80045FD8: nop

    func_80049C48(rdram, ctx);
        goto after_28;
    // 0x80045FD8: nop

    after_28:
    // 0x80045FDC: jal         0x8000798C
    // 0x80045FE0: nop

    func_8000798C(rdram, ctx);
        goto after_29;
    // 0x80045FE0: nop

    after_29:
    // 0x80045FE4: jal         0x8000798C
    // 0x80045FE8: nop

    func_8000798C(rdram, ctx);
        goto after_30;
    // 0x80045FE8: nop

    after_30:
    // 0x80045FEC: jal         0x8000798C
    // 0x80045FF0: nop

    func_8000798C(rdram, ctx);
        goto after_31;
    // 0x80045FF0: nop

    after_31:
    // 0x80045FF4: jal         0x8000798C
    // 0x80045FF8: nop

    func_8000798C(rdram, ctx);
        goto after_32;
    // 0x80045FF8: nop

    after_32:
    // 0x80045FFC: lw          $t4, 0x240($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X240);
    // 0x80046000: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
L_80046004:
    // 0x80046004: jal         0x8000798C
    // 0x80046008: nop

    func_8000798C(rdram, ctx);
        goto after_33;
    // 0x80046008: nop

    after_33:
    // 0x8004600C: b           L_80046004
    // 0x80046010: nop

        goto L_80046004;
    // 0x80046010: nop

L_80046014:
    // 0x80046014: lh          $t5, 0x226($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X226);
L_80046018:
    // 0x80046018: lh          $t6, 0x224($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X224);
    // 0x8004601C: beq         $t5, $t6, L_80046218
    if (ctx->r13 == ctx->r14) {
        // 0x80046020: addiu       $a1, $t5, 0x1
        ctx->r5 = ADD32(ctx->r13, 0X1);
            goto L_80046218;
    }
    // 0x80046020: addiu       $a1, $t5, 0x1
    ctx->r5 = ADD32(ctx->r13, 0X1);
    // 0x80046024: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x80046028: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8004602C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80046030: jal         0x8003DE20
    // 0x80046034: addiu       $a2, $sp, 0x98
    ctx->r6 = ADD32(ctx->r29, 0X98);
    func_8003DE20(rdram, ctx);
        goto after_34;
    // 0x80046034: addiu       $a2, $sp, 0x98
    ctx->r6 = ADD32(ctx->r29, 0X98);
    after_34:
    // 0x80046038: bne         $v0, $zero, L_80046050
    if (ctx->r2 != 0) {
        // 0x8004603C: sw          $v0, 0x228($sp)
        MEM_W(0X228, ctx->r29) = ctx->r2;
            goto L_80046050;
    }
    // 0x8004603C: sw          $v0, 0x228($sp)
    MEM_W(0X228, ctx->r29) = ctx->r2;
    // 0x80046040: lh          $t1, 0x224($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X224);
    // 0x80046044: sh          $t1, 0x226($sp)
    MEM_H(0X226, ctx->r29) = ctx->r9;
    // 0x80046048: b           L_80046218
    // 0x8004604C: sh          $t1, 0x224($sp)
    MEM_H(0X224, ctx->r29) = ctx->r9;
        goto L_80046218;
    // 0x8004604C: sh          $t1, 0x224($sp)
    MEM_H(0X224, ctx->r29) = ctx->r9;
L_80046050:
    // 0x80046050: lw          $t9, 0x22C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X22C);
    // 0x80046054: beql        $t9, $zero, L_800460A0
    if (ctx->r25 == 0) {
        // 0x80046058: lw          $v0, 0x228($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X228);
            goto L_800460A0;
    }
    goto skip_3;
    // 0x80046058: lw          $v0, 0x228($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X228);
    skip_3:
    // 0x8004605C: jal         0x8004A0C4
    // 0x80046060: lw          $a0, 0xC($t9)
    ctx->r4 = MEM_W(ctx->r25, 0XC);
    func_8004A0C4(rdram, ctx);
        goto after_35;
    // 0x80046060: lw          $a0, 0xC($t9)
    ctx->r4 = MEM_W(ctx->r25, 0XC);
    after_35:
    // 0x80046064: lw          $t2, 0x22C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X22C);
    // 0x80046068: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004606C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80046070: lh          $t0, 0x34($t2)
    ctx->r8 = MEM_H(ctx->r10, 0X34);
    // 0x80046074: addiu       $a2, $a2, -0x6C60
    ctx->r6 = ADD32(ctx->r6, -0X6C60);
    // 0x80046078: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8004607C: beq         $t0, $zero, L_8004608C
    if (ctx->r8 == 0) {
        // 0x80046080: nop
    
            goto L_8004608C;
    }
    // 0x80046080: nop

    // 0x80046084: jal         0x8001026C
    // 0x80046088: lw          $a1, 0x30($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X30);
    func_8001026C(rdram, ctx);
        goto after_36;
    // 0x80046088: lw          $a1, 0x30($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X30);
    after_36:
L_8004608C:
    // 0x8004608C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80046090: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80046094: jal         0x800042A8
    // 0x80046098: lw          $a1, 0x22C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X22C);
    func_800042A8(rdram, ctx);
        goto after_37;
    // 0x80046098: lw          $a1, 0x22C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X22C);
    after_37:
    // 0x8004609C: lw          $v0, 0x228($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X228);
L_800460A0:
    // 0x800460A0: sw          $v0, 0x22C($sp)
    MEM_W(0X22C, ctx->r29) = ctx->r2;
    // 0x800460A4: jal         0x80049CFC
    // 0x800460A8: addiu       $a0, $v0, 0x84
    ctx->r4 = ADD32(ctx->r2, 0X84);
    func_80049CFC(rdram, ctx);
        goto after_38;
    // 0x800460A8: addiu       $a0, $v0, 0x84
    ctx->r4 = ADD32(ctx->r2, 0X84);
    after_38:
    // 0x800460AC: lw          $v1, 0x228($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X228);
    // 0x800460B0: sh          $v0, 0x8C($v1)
    MEM_H(0X8C, ctx->r3) = ctx->r2;
    // 0x800460B4: jal         0x80049D80
    // 0x800460B8: lh          $a0, 0x8C($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X8C);
    func_80049D80(rdram, ctx);
        goto after_39;
    // 0x800460B8: lh          $a0, 0x8C($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X8C);
    after_39:
    // 0x800460BC: lw          $v1, 0x228($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X228);
    // 0x800460C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800460C4: lw          $t3, 0x80($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X80);
    // 0x800460C8: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x800460CC: lw          $t6, 0x228($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X228);
    // 0x800460D0: andi        $t4, $t3, 0x4
    ctx->r12 = ctx->r11 & 0X4;
    // 0x800460D4: beq         $t4, $zero, L_800460E4
    if (ctx->r12 == 0) {
        // 0x800460D8: nop
    
            goto L_800460E4;
    }
    // 0x800460D8: nop

    // 0x800460DC: b           L_800460E4
    // 0x800460E0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
        goto L_800460E4;
    // 0x800460E0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
L_800460E4:
    // 0x800460E4: lw          $a0, 0x8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X8);
    // 0x800460E8: jal         0x80049DFC
    // 0x800460EC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80049DFC(rdram, ctx);
        goto after_40;
    // 0x800460EC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_40:
    // 0x800460F0: lw          $t5, 0x228($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X228);
    // 0x800460F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800460F8: jal         0x8004A148
    // 0x800460FC: sw          $v0, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r2;
    func_8004A148(rdram, ctx);
        goto after_41;
    // 0x800460FC: sw          $v0, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r2;
    after_41:
    // 0x80046100: lw          $v0, 0x228($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X228);
    // 0x80046104: addiu       $s4, $sp, 0xB4
    ctx->r20 = ADD32(ctx->r29, 0XB4);
    // 0x80046108: addiu       $v1, $sp, 0xC8
    ctx->r3 = ADD32(ctx->r29, 0XC8);
    // 0x8004610C: lw          $t7, 0x80($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X80);
    // 0x80046110: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x80046114: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80046118: sw          $t8, 0x80($v0)
    MEM_W(0X80, ctx->r2) = ctx->r24;
    // 0x8004611C: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x80046120: sw          $t8, 0xD8($t0)
    MEM_W(0XD8, ctx->r8) = ctx->r24;
L_80046124:
    // 0x80046124: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x80046128: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8004612C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80046130: sh          $zero, 0x0($t2)
    MEM_H(0X0, ctx->r10) = 0;
L_80046134:
    // 0x80046134: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x80046138: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8004613C: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x80046140: sh          $zero, 0x2($t4)
    MEM_H(0X2, ctx->r12) = 0;
    // 0x80046144: bne         $s0, $s7, L_80046134
    if (ctx->r16 != ctx->r23) {
        // 0x80046148: addiu       $v0, $v0, 0x2
        ctx->r2 = ADD32(ctx->r2, 0X2);
            goto L_80046134;
    }
    // 0x80046148: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8004614C: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x80046150: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80046154: sltu        $at, $s4, $v1
    ctx->r1 = ctx->r20 < ctx->r3 ? 1 : 0;
    // 0x80046158: bne         $at, $zero, L_80046124
    if (ctx->r1 != 0) {
        // 0x8004615C: sh          $zero, 0x14($t6)
        MEM_H(0X14, ctx->r14) = 0;
            goto L_80046124;
    }
    // 0x8004615C: sh          $zero, 0x14($t6)
    MEM_H(0X14, ctx->r14) = 0;
    // 0x80046160: lw          $t5, 0x228($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X228);
    // 0x80046164: lh          $v0, 0x34($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X34);
    // 0x80046168: beql        $v0, $zero, L_80046210
    if (ctx->r2 == 0) {
        // 0x8004616C: lh          $t4, 0x226($sp)
        ctx->r12 = MEM_H(ctx->r29, 0X226);
            goto L_80046210;
    }
    goto skip_4;
    // 0x8004616C: lh          $t4, 0x226($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X226);
    skip_4:
    // 0x80046170: blez        $v0, L_8004620C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80046174: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8004620C;
    }
    // 0x80046174: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80046178: addiu       $s4, $sp, 0xB4
    ctx->r20 = ADD32(ctx->r29, 0XB4);
    // 0x8004617C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80046180: lw          $t7, 0x228($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X228);
L_80046184:
    // 0x80046184: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x80046188: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8004618C: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80046190: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80046194: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x80046198: lh          $t1, 0x0($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X0);
    // 0x8004619C: sh          $t1, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r9;
    // 0x800461A0: lw          $a0, 0x228($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X228);
L_800461A4:
    // 0x800461A4: lw          $t2, 0x30($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X30);
    // 0x800461A8: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x800461AC: subu        $t3, $t3, $s1
    ctx->r11 = SUB32(ctx->r11, ctx->r17);
    // 0x800461B0: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x800461B4: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x800461B8: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800461BC: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800461C0: lh          $t5, 0x2($t6)
    ctx->r13 = MEM_H(ctx->r14, 0X2);
    // 0x800461C4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800461C8: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800461CC: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800461D0: bne         $s0, $s7, L_800461A4
    if (ctx->r16 != ctx->r23) {
        // 0x800461D4: sh          $t5, 0x2($t8)
        MEM_H(0X2, ctx->r24) = ctx->r13;
            goto L_800461A4;
    }
    // 0x800461D4: sh          $t5, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r13;
    // 0x800461D8: lw          $v0, 0x228($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X228);
    // 0x800461DC: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x800461E0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800461E4: lw          $t9, 0x30($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X30);
    // 0x800461E8: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x800461EC: addu        $t1, $t9, $v1
    ctx->r9 = ADD32(ctx->r25, ctx->r3);
    // 0x800461F0: lh          $t0, 0x14($t1)
    ctx->r8 = MEM_H(ctx->r9, 0X14);
    // 0x800461F4: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x800461F8: sh          $t0, 0x14($t2)
    MEM_H(0X14, ctx->r10) = ctx->r8;
    // 0x800461FC: lh          $t3, 0x34($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X34);
    // 0x80046200: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80046204: bnel        $at, $zero, L_80046184
    if (ctx->r1 != 0) {
        // 0x80046208: lw          $t7, 0x228($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X228);
            goto L_80046184;
    }
    goto skip_5;
    // 0x80046208: lw          $t7, 0x228($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X228);
    skip_5:
L_8004620C:
    // 0x8004620C: lh          $t4, 0x226($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X226);
L_80046210:
    // 0x80046210: sh          $zero, 0xB0($sp)
    MEM_H(0XB0, ctx->r29) = 0;
    // 0x80046214: sh          $t4, 0x224($sp)
    MEM_H(0X224, ctx->r29) = ctx->r12;
L_80046218:
    // 0x80046218: addiu       $s2, $sp, 0xC8
    ctx->r18 = ADD32(ctx->r29, 0XC8);
    // 0x8004621C: addiu       $v0, $sp, 0x17C
    ctx->r2 = ADD32(ctx->r29, 0X17C);
L_80046220:
    // 0x80046220: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80046224: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80046228: sltu        $at, $s2, $v0
    ctx->r1 = ctx->r18 < ctx->r2 ? 1 : 0;
    // 0x8004622C: bne         $at, $zero, L_80046220
    if (ctx->r1 != 0) {
        // 0x80046230: sh          $zero, 0x28($t6)
        MEM_H(0X28, ctx->r14) = 0;
            goto L_80046220;
    }
    // 0x80046230: sh          $zero, 0x28($t6)
    MEM_H(0X28, ctx->r14) = 0;
    // 0x80046234: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80046238: addiu       $s4, $sp, 0xB4
    ctx->r20 = ADD32(ctx->r29, 0XB4);
    // 0x8004623C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
L_80046240:
    // 0x80046240: lh          $t7, 0x14($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X14);
    // 0x80046244: bnel        $t7, $zero, L_80046258
    if (ctx->r15 != 0) {
        // 0x80046248: lh          $t5, 0x2($v0)
        ctx->r13 = MEM_H(ctx->r2, 0X2);
            goto L_80046258;
    }
    goto skip_6;
    // 0x80046248: lh          $t5, 0x2($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X2);
    skip_6:
    // 0x8004624C: b           L_80046534
    // 0x80046250: nop

        goto L_80046534;
    // 0x80046250: nop

    // 0x80046254: lh          $t5, 0x2($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X2);
L_80046258:
    // 0x80046258: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x8004625C: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x80046260: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x80046264: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80046268: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8004626C: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80046270: sll         $t1, $s3, 2
    ctx->r9 = S32(ctx->r19 << 2);
    // 0x80046274: addiu       $t0, $sp, 0xC8
    ctx->r8 = ADD32(ctx->r29, 0XC8);
    // 0x80046278: addu        $s1, $t1, $t0
    ctx->r17 = ADD32(ctx->r9, ctx->r8);
    // 0x8004627C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80046280: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80046284: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80046288: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8004628C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80046290: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80046294: jal         0x80001A6C
    // 0x80046298: nop

    func_80001A6C(rdram, ctx);
        goto after_42;
    // 0x80046298: nop

    after_42:
    // 0x8004629C: lw          $t2, 0x22C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X22C);
    // 0x800462A0: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x800462A4: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x800462A8: lw          $a1, 0x1C($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X1C);
    // 0x800462AC: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x800462B0: jal         0x80049840
    // 0x800462B4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_80049840(rdram, ctx);
        goto after_43;
    // 0x800462B4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_43:
    // 0x800462B8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800462BC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800462C0: jal         0x80000BD8
    // 0x800462C4: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_80000BD8(rdram, ctx);
        goto after_44;
    // 0x800462C4: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_44:
    // 0x800462C8: lw          $t3, 0x22C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X22C);
    // 0x800462CC: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x800462D0: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x800462D4: lw          $a1, 0x20($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X20);
    // 0x800462D8: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x800462DC: jal         0x80049840
    // 0x800462E0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_80049840(rdram, ctx);
        goto after_45;
    // 0x800462E0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_45:
    // 0x800462E4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800462E8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800462EC: jal         0x80000BD8
    // 0x800462F0: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_80000BD8(rdram, ctx);
        goto after_46;
    // 0x800462F0: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_46:
    // 0x800462F4: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x800462F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800462FC: addiu       $v1, $sp, 0x1E0
    ctx->r3 = ADD32(ctx->r29, 0X1E0);
    // 0x80046300: addiu       $a0, $sp, 0x1EC
    ctx->r4 = ADD32(ctx->r29, 0X1EC);
    // 0x80046304: sh          $fp, 0x28($t4)
    MEM_H(0X28, ctx->r12) = ctx->r30;
L_80046308:
    // 0x80046308: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8004630C: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x80046310: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80046314: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x80046318: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8004631C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80046320: bne         $at, $zero, L_80046308
    if (ctx->r1 != 0) {
        // 0x80046324: swc1        $f4, 0x8($t7)
        MEM_W(0X8, ctx->r15) = ctx->f4.u32l;
            goto L_80046308;
    }
    // 0x80046324: swc1        $f4, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f4.u32l;
    // 0x80046328: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x8004632C: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x80046330: addiu       $t8, $sp, 0xC8
    ctx->r24 = ADD32(ctx->r29, 0XC8);
    // 0x80046334: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80046338: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8004633C: addu        $s2, $t5, $t8
    ctx->r18 = ADD32(ctx->r13, ctx->r24);
    // 0x80046340: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80046344: mov.s       $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    ctx->f22.fl = ctx->f24.fl;
L_80046348:
    // 0x80046348: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x8004634C: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80046350: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80046354: lh          $t1, 0x14($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X14);
    // 0x80046358: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8004635C: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80046360: nop

    // 0x80046364: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80046368: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8004636C: jal         0x80001A6C
    // 0x80046370: nop

    func_80001A6C(rdram, ctx);
        goto after_47;
    // 0x80046370: nop

    after_47:
    // 0x80046374: add.s       $f20, $f30, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f30.fl + ctx->f22.fl;
    // 0x80046378: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x8004637C: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80046380: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80046384: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80046388: jal         0x80049840
    // 0x8004638C: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    func_80049840(rdram, ctx);
        goto after_48;
    // 0x8004638C: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_48:
    // 0x80046390: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80046394: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80046398: jal         0x80000BD8
    // 0x8004639C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_80000BD8(rdram, ctx);
        goto after_49;
    // 0x8004639C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_49:
    // 0x800463A0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800463A4: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x800463A8: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x800463AC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800463B0: jal         0x80049840
    // 0x800463B4: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    func_80049840(rdram, ctx);
        goto after_50;
    // 0x800463B4: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_50:
    // 0x800463B8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800463BC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800463C0: jal         0x80000BD8
    // 0x800463C4: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_80000BD8(rdram, ctx);
        goto after_51;
    // 0x800463C4: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_51:
    // 0x800463C8: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x800463CC: lwc1        $f8, 0x210($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X210);
    // 0x800463D0: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x800463D4: lwc1        $f10, 0x8($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X8);
    // 0x800463D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800463DC: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x800463E0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800463E4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800463E8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800463EC: cvt.d.s     $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f10.d = CVT_D_S(ctx->f22.fl);
    // 0x800463F0: swc1        $f16, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f16.u32l;
    // 0x800463F4: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x800463F8: lw          $t4, -0x4($s1)
    ctx->r12 = MEM_W(ctx->r17, -0X4);
    // 0x800463FC: add.d       $f16, $f10, $f28
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f28.d); 
    ctx->f16.d = ctx->f10.d + ctx->f28.d;
    // 0x80046400: lwc1        $f18, 0xC($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0XC);
    // 0x80046404: swc1        $f18, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f18.u32l;
    // 0x80046408: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8004640C: lwc1        $f4, 0x218($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X218);
    // 0x80046410: lw          $t7, -0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, -0X4);
    // 0x80046414: lwc1        $f6, 0x10($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X10);
    // 0x80046418: cvt.s.d     $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f22.fl = CVT_S_D(ctx->f16.d);
    // 0x8004641C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80046420: swc1        $f8, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f8.u32l;
    // 0x80046424: lw          $t5, -0x4($s1)
    ctx->r13 = MEM_W(ctx->r17, -0X4);
    // 0x80046428: bne         $at, $zero, L_80046348
    if (ctx->r1 != 0) {
        // 0x8004642C: sh          $fp, 0x28($t5)
        MEM_H(0X28, ctx->r13) = ctx->r30;
            goto L_80046348;
    }
    // 0x8004642C: sh          $fp, 0x28($t5)
    MEM_H(0X28, ctx->r13) = ctx->r30;
    // 0x80046430: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80046434: mov.s       $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    ctx->f22.fl = ctx->f24.fl;
L_80046438:
    // 0x80046438: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x8004643C: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x80046440: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80046444: lh          $t9, 0x14($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X14);
    // 0x80046448: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8004644C: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80046450: nop

    // 0x80046454: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80046458: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8004645C: jal         0x80001A6C
    // 0x80046460: nop

    func_80001A6C(rdram, ctx);
        goto after_52;
    // 0x80046460: nop

    after_52:
    // 0x80046464: add.s       $f20, $f30, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f30.fl + ctx->f22.fl;
    // 0x80046468: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x8004646C: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80046470: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80046474: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80046478: jal         0x80049840
    // 0x8004647C: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    func_80049840(rdram, ctx);
        goto after_53;
    // 0x8004647C: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_53:
    // 0x80046480: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80046484: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80046488: jal         0x80000BD8
    // 0x8004648C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_80000BD8(rdram, ctx);
        goto after_54;
    // 0x8004648C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_54:
    // 0x80046490: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80046494: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80046498: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x8004649C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800464A0: jal         0x80049840
    // 0x800464A4: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    func_80049840(rdram, ctx);
        goto after_55;
    // 0x800464A4: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_55:
    // 0x800464A8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800464AC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800464B0: jal         0x80000BD8
    // 0x800464B4: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_80000BD8(rdram, ctx);
        goto after_56;
    // 0x800464B4: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_56:
    // 0x800464B8: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x800464BC: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x800464C0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800464C4: lwc1        $f4, 0x8($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X8);
    // 0x800464C8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800464CC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800464D0: swc1        $f4, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f4.u32l;
    // 0x800464D4: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x800464D8: lwc1        $f6, 0x214($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X214);
    // 0x800464DC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x800464E0: lwc1        $f8, 0xC($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0XC);
    // 0x800464E4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800464E8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800464EC: cvt.d.s     $f6, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f6.d = CVT_D_S(ctx->f22.fl);
    // 0x800464F0: swc1        $f10, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f10.u32l;
    // 0x800464F4: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x800464F8: lwc1        $f16, 0x218($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X218);
    // 0x800464FC: lw          $t6, -0x4($s1)
    ctx->r14 = MEM_W(ctx->r17, -0X4);
    // 0x80046500: lwc1        $f18, 0x10($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X10);
    // 0x80046504: add.d       $f8, $f6, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f28.d); 
    ctx->f8.d = ctx->f6.d + ctx->f28.d;
    // 0x80046508: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8004650C: cvt.s.d     $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f22.fl = CVT_S_D(ctx->f8.d);
    // 0x80046510: swc1        $f4, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f4.u32l;
    // 0x80046514: lw          $t7, -0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, -0X4);
    // 0x80046518: bne         $s0, $at, L_80046438
    if (ctx->r16 != ctx->r1) {
        // 0x8004651C: sh          $fp, 0x28($t7)
        MEM_H(0X28, ctx->r15) = ctx->r30;
            goto L_80046438;
    }
    // 0x8004651C: sh          $fp, 0x28($t7)
    MEM_H(0X28, ctx->r15) = ctx->r30;
    // 0x80046520: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80046524: addiu       $t5, $sp, 0xC8
    ctx->r13 = ADD32(ctx->r29, 0XC8);
    // 0x80046528: sltu        $at, $s4, $t5
    ctx->r1 = ctx->r20 < ctx->r13 ? 1 : 0;
    // 0x8004652C: bnel        $at, $zero, L_80046240
    if (ctx->r1 != 0) {
        // 0x80046530: lw          $v0, 0x0($s4)
        ctx->r2 = MEM_W(ctx->r20, 0X0);
            goto L_80046240;
    }
    goto skip_7;
    // 0x80046530: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    skip_7:
L_80046534:
    // 0x80046534: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80046538: ldc1        $f2, 0x7EC8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, 0X7EC8);
    // 0x8004653C: cvt.d.s     $f10, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); 
    ctx->f10.d = CVT_D_S(ctx->f30.fl);
    // 0x80046540: addiu       $s2, $sp, 0xC8
    ctx->r18 = ADD32(ctx->r29, 0XC8);
    // 0x80046544: add.d       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = ctx->f10.d + ctx->f2.d;
    // 0x80046548: cvt.s.d     $f30, $f16
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f30.fl = CVT_S_D(ctx->f16.d);
    // 0x8004654C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
L_80046550:
    // 0x80046550: lh          $t8, 0x28($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X28);
    // 0x80046554: beql        $t8, $zero, L_800465E0
    if (ctx->r24 == 0) {
        // 0x80046558: lw          $t8, 0x4($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X4);
            goto L_800465E0;
    }
    goto skip_8;
    // 0x80046558: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    skip_8:
    // 0x8004655C: lwc1        $f0, 0x24($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X24);
    // 0x80046560: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80046564: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80046568: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8004656C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80046570: jal         0x80001AB4
    // 0x80046574: nop

    func_80001AB4(rdram, ctx);
        goto after_57;
    // 0x80046574: nop

    after_57:
    // 0x80046578: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x8004657C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80046580: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x80046584: lw          $a0, 0x8($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X8);
    // 0x80046588: jal         0x80002340
    // 0x8004658C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80002340(rdram, ctx);
        goto after_58;
    // 0x8004658C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_58:
    // 0x80046590: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80046594: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80046598:
    // 0x80046598: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8004659C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800465A0: lw          $t2, 0x4($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X4);
    // 0x800465A4: addu        $t0, $v1, $v0
    ctx->r8 = ADD32(ctx->r3, ctx->r2);
    // 0x800465A8: lwc1        $f18, 0x8($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X8);
    // 0x800465AC: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x800465B0: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800465B4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800465B8: bne         $s0, $s7, L_80046598
    if (ctx->r16 != ctx->r23) {
        // 0x800465BC: swc1        $f18, 0x40($t4)
        MEM_W(0X40, ctx->r12) = ctx->f18.u32l;
            goto L_80046598;
    }
    // 0x800465BC: swc1        $f18, 0x40($t4)
    MEM_W(0X40, ctx->r12) = ctx->f18.u32l;
    // 0x800465C0: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x800465C4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800465C8: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800465CC: lw          $t5, 0x8($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X8);
    // 0x800465D0: sw          $fp, 0xD8($t5)
    MEM_W(0XD8, ctx->r13) = ctx->r30;
    // 0x800465D4: b           L_800465E8
    // 0x800465D8: ldc1        $f2, 0x7ED0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, 0X7ED0);
        goto L_800465E8;
    // 0x800465D8: ldc1        $f2, 0x7ED0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, 0X7ED0);
    // 0x800465DC: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
L_800465E0:
    // 0x800465E0: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x800465E4: sw          $zero, 0xD8($t9)
    MEM_W(0XD8, ctx->r25) = 0;
L_800465E8:
    // 0x800465E8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800465EC: addiu       $t1, $sp, 0x17C
    ctx->r9 = ADD32(ctx->r29, 0X17C);
    // 0x800465F0: sltu        $at, $s2, $t1
    ctx->r1 = ctx->r18 < ctx->r9 ? 1 : 0;
    // 0x800465F4: bnel        $at, $zero, L_80046550
    if (ctx->r1 != 0) {
        // 0x800465F8: lw          $v1, 0x0($s2)
        ctx->r3 = MEM_W(ctx->r18, 0X0);
            goto L_80046550;
    }
    goto skip_9;
    // 0x800465F8: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    skip_9:
    // 0x800465FC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80046600: lhu         $t0, -0x2E5C($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X2E5C);
    // 0x80046604: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80046608: andi        $t2, $t0, 0x20
    ctx->r10 = ctx->r8 & 0X20;
    // 0x8004660C: bne         $t2, $zero, L_800466B0
    if (ctx->r10 != 0) {
        // 0x80046610: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_800466B0;
    }
    // 0x80046610: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80046614: lh          $v0, -0x2E60($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2E60);
    // 0x80046618: slti        $at, $v0, 0x1A
    ctx->r1 = SIGNED(ctx->r2) < 0X1A ? 1 : 0;
    // 0x8004661C: bnel        $at, $zero, L_80046644
    if (ctx->r1 != 0) {
        // 0x80046620: slti        $at, $v0, -0x19
        ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
            goto L_80046644;
    }
    goto skip_10;
    // 0x80046620: slti        $at, $v0, -0x19
    ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
    skip_10:
    // 0x80046624: lw          $v0, 0x22C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X22C);
    // 0x80046628: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8004662C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80046630: add.d       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f6.d + ctx->f2.d;
    // 0x80046634: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80046638: b           L_80046660
    // 0x8004663C: swc1        $f10, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f10.u32l;
        goto L_80046660;
    // 0x8004663C: swc1        $f10, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f10.u32l;
    // 0x80046640: slti        $at, $v0, -0x19
    ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
L_80046644:
    // 0x80046644: beq         $at, $zero, L_80046660
    if (ctx->r1 == 0) {
        // 0x80046648: lw          $t3, 0x22C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X22C);
            goto L_80046660;
    }
    // 0x80046648: lw          $t3, 0x22C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X22C);
    // 0x8004664C: lwc1        $f16, 0x20($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X20);
    // 0x80046650: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80046654: sub.d       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f18.d - ctx->f2.d;
    // 0x80046658: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8004665C: swc1        $f6, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f6.u32l;
L_80046660:
    // 0x80046660: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80046664: lh          $v0, -0x2E5E($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2E5E);
    // 0x80046668: slti        $at, $v0, 0x1A
    ctx->r1 = SIGNED(ctx->r2) < 0X1A ? 1 : 0;
    // 0x8004666C: bnel        $at, $zero, L_80046694
    if (ctx->r1 != 0) {
        // 0x80046670: slti        $at, $v0, -0x19
        ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
            goto L_80046694;
    }
    goto skip_11;
    // 0x80046670: slti        $at, $v0, -0x19
    ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
    skip_11:
    // 0x80046674: lw          $v0, 0x22C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X22C);
    // 0x80046678: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8004667C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80046680: sub.d       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = ctx->f10.d - ctx->f2.d;
    // 0x80046684: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80046688: b           L_800466B0
    // 0x8004668C: swc1        $f18, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f18.u32l;
        goto L_800466B0;
    // 0x8004668C: swc1        $f18, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f18.u32l;
    // 0x80046690: slti        $at, $v0, -0x19
    ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
L_80046694:
    // 0x80046694: beq         $at, $zero, L_800466B0
    if (ctx->r1 == 0) {
        // 0x80046698: lw          $v0, 0x22C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X22C);
            goto L_800466B0;
    }
    // 0x80046698: lw          $v0, 0x22C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X22C);
    // 0x8004669C: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800466A0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800466A4: add.d       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f6.d + ctx->f2.d;
    // 0x800466A8: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x800466AC: swc1        $f10, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f10.u32l;
L_800466B0:
    // 0x800466B0: lw          $t4, 0x22C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X22C);
    // 0x800466B4: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x800466B8: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x800466BC: lw          $a1, 0x1C($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X1C);
    // 0x800466C0: jal         0x80049840
    // 0x800466C4: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    func_80049840(rdram, ctx);
        goto after_59;
    // 0x800466C4: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_59:
    // 0x800466C8: lw          $t6, 0x22C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X22C);
    // 0x800466CC: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x800466D0: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x800466D4: lw          $a1, 0x20($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X20);
    // 0x800466D8: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x800466DC: jal         0x80049840
    // 0x800466E0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_80049840(rdram, ctx);
        goto after_60;
    // 0x800466E0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_60:
    // 0x800466E4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800466E8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800466EC: jal         0x80000BD8
    // 0x800466F0: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_80000BD8(rdram, ctx);
        goto after_61;
    // 0x800466F0: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_61:
    // 0x800466F4: lw          $t7, 0x22C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X22C);
    // 0x800466F8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800466FC: lwc1        $f0, 0x2C($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X2C);
    // 0x80046700: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80046704: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80046708: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8004670C: jal         0x80001AB4
    // 0x80046710: nop

    func_80001AB4(rdram, ctx);
        goto after_62;
    // 0x80046710: nop

    after_62:
    // 0x80046714: lw          $t5, 0x22C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X22C);
    // 0x80046718: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8004671C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80046720: lw          $t8, 0xC($t5)
    ctx->r24 = MEM_W(ctx->r13, 0XC);
    // 0x80046724: lw          $a0, 0x8($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X8);
    // 0x80046728: jal         0x80000BD8
    // 0x8004672C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80000BD8(rdram, ctx);
        goto after_63;
    // 0x8004672C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_63:
    // 0x80046730: sll         $a2, $fp, 16
    ctx->r6 = S32(ctx->r30 << 16);
    // 0x80046734: sra         $t9, $a2, 16
    ctx->r25 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80046738: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x8004673C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80046740: jal         0x8004C388
    // 0x80046744: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    func_8004C388(rdram, ctx);
        goto after_64;
    // 0x80046744: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_64:
    // 0x80046748: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8004674C: lh          $t1, 0xB0($sp)
    ctx->r9 = MEM_H(ctx->r29, 0XB0);
L_80046750:
    // 0x80046750: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80046754: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
    // 0x80046758: bne         $t1, $s1, L_8004677C
    if (ctx->r9 != ctx->r17) {
        // 0x8004675C: addiu       $t6, $sp, 0xB4
        ctx->r14 = ADD32(ctx->r29, 0XB4);
            goto L_8004677C;
    }
    // 0x8004675C: addiu       $t6, $sp, 0xB4
    ctx->r14 = ADD32(ctx->r29, 0XB4);
    // 0x80046760: sll         $a1, $fp, 16
    ctx->r5 = S32(ctx->r30 << 16);
    // 0x80046764: sra         $t0, $a1, 16
    ctx->r8 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80046768: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x8004676C: addiu       $t3, $sp, 0xB4
    ctx->r11 = ADD32(ctx->r29, 0XB4);
    // 0x80046770: addu        $s4, $t2, $t3
    ctx->r20 = ADD32(ctx->r10, ctx->r11);
    // 0x80046774: b           L_80046780
    // 0x80046778: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
        goto L_80046780;
    // 0x80046778: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
L_8004677C:
    // 0x8004677C: addu        $s4, $t4, $t6
    ctx->r20 = ADD32(ctx->r12, ctx->r14);
L_80046780:
    // 0x80046780: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80046784: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80046788: addiu       $a2, $a2, 0x7B4C
    ctx->r6 = ADD32(ctx->r6, 0X7B4C);
    // 0x8004678C: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x80046790: lh          $a3, 0x0($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X0);
    // 0x80046794: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80046798: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8004679C: lh          $t5, 0x4($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X4);
    // 0x800467A0: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800467A4: lh          $t8, 0x6($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X6);
    // 0x800467A8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800467AC: lh          $t9, 0x14($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X14);
    // 0x800467B0: jal         0x8004C340
    // 0x800467B4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    func_8004C340(rdram, ctx);
        goto after_65;
    // 0x800467B4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_65:
    // 0x800467B8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800467BC: slti        $at, $s1, 0x5
    ctx->r1 = SIGNED(ctx->r17) < 0X5 ? 1 : 0;
    // 0x800467C0: bnel        $at, $zero, L_80046750
    if (ctx->r1 != 0) {
        // 0x800467C4: lh          $t1, 0xB0($sp)
        ctx->r9 = MEM_H(ctx->r29, 0XB0);
            goto L_80046750;
    }
    goto skip_12;
    // 0x800467C4: lh          $t1, 0xB0($sp)
    ctx->r9 = MEM_H(ctx->r29, 0XB0);
    skip_12:
    // 0x800467C8: sll         $a2, $fp, 16
    ctx->r6 = S32(ctx->r30 << 16);
    // 0x800467CC: sra         $t1, $a2, 16
    ctx->r9 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800467D0: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x800467D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800467D8: jal         0x8004C388
    // 0x800467DC: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    func_8004C388(rdram, ctx);
        goto after_66;
    // 0x800467DC: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    after_66:
    // 0x800467E0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800467E4: addiu       $v0, $sp, 0x18C
    ctx->r2 = ADD32(ctx->r29, 0X18C);
    // 0x800467E8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x800467EC: lw          $v1, 0x22C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X22C);
L_800467F0:
    // 0x800467F0: lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8);
    // 0x800467F4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800467F8: addu        $t2, $t0, $s1
    ctx->r10 = ADD32(ctx->r8, ctx->r17);
    // 0x800467FC: lbu         $t3, 0x10($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X10);
    // 0x80046800: sb          $t3, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = ctx->r11;
    // 0x80046804: lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X8);
    // 0x80046808: addu        $t6, $t4, $s1
    ctx->r14 = ADD32(ctx->r12, ctx->r17);
    // 0x8004680C: lbu         $t7, 0x11($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X11);
    // 0x80046810: sb          $t7, -0x3($v0)
    MEM_B(-0X3, ctx->r2) = ctx->r15;
    // 0x80046814: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    // 0x80046818: addu        $t8, $t5, $s1
    ctx->r24 = ADD32(ctx->r13, ctx->r17);
    // 0x8004681C: lbu         $t9, 0x12($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X12);
    // 0x80046820: sb          $t9, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = ctx->r25;
    // 0x80046824: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
    // 0x80046828: addu        $t0, $t1, $s1
    ctx->r8 = ADD32(ctx->r9, ctx->r17);
    // 0x8004682C: lbu         $t2, 0x13($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X13);
    // 0x80046830: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80046834: bne         $s1, $a0, L_800467F0
    if (ctx->r17 != ctx->r4) {
        // 0x80046838: sb          $t2, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = ctx->r10;
            goto L_800467F0;
    }
    // 0x80046838: sb          $t2, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r10;
    // 0x8004683C: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80046840: sb          $zero, 0x194($sp)
    MEM_B(0X194, ctx->r29) = 0;
    // 0x80046844: addiu       $a2, $a2, 0x7B68
    ctx->r6 = ADD32(ctx->r6, 0X7B68);
    // 0x80046848: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x8004684C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80046850: jal         0x8004C340
    // 0x80046854: addiu       $a3, $sp, 0x18C
    ctx->r7 = ADD32(ctx->r29, 0X18C);
    func_8004C340(rdram, ctx);
        goto after_67;
    // 0x80046854: addiu       $a3, $sp, 0x18C
    ctx->r7 = ADD32(ctx->r29, 0X18C);
    after_67:
    // 0x80046858: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8004685C: lhu         $v1, -0x2E5C($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2E5C);
    // 0x80046860: andi        $t3, $v1, 0x8
    ctx->r11 = ctx->r3 & 0X8;
    // 0x80046864: beq         $t3, $zero, L_80046880
    if (ctx->r11 == 0) {
        // 0x80046868: andi        $t4, $v1, 0x4
        ctx->r12 = ctx->r3 & 0X4;
            goto L_80046880;
    }
    // 0x80046868: andi        $t4, $v1, 0x4
    ctx->r12 = ctx->r3 & 0X4;
    // 0x8004686C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80046870: addiu       $v0, $v0, -0x6C50
    ctx->r2 = ADD32(ctx->r2, -0X6C50);
    // 0x80046874: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80046878: sub.s       $f18, $f16, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f26.fl;
    // 0x8004687C: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
L_80046880:
    // 0x80046880: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80046884: beq         $t4, $zero, L_80046898
    if (ctx->r12 == 0) {
        // 0x80046888: addiu       $v0, $v0, -0x6C50
        ctx->r2 = ADD32(ctx->r2, -0X6C50);
            goto L_80046898;
    }
    // 0x80046888: addiu       $v0, $v0, -0x6C50
    ctx->r2 = ADD32(ctx->r2, -0X6C50);
    // 0x8004688C: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80046890: add.s       $f6, $f4, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f26.fl;
    // 0x80046894: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
L_80046898:
    // 0x80046898: andi        $t6, $v1, 0x2
    ctx->r14 = ctx->r3 & 0X2;
    // 0x8004689C: beq         $t6, $zero, L_800468B8
    if (ctx->r14 == 0) {
        // 0x800468A0: andi        $t7, $v1, 0x1
        ctx->r15 = ctx->r3 & 0X1;
            goto L_800468B8;
    }
    // 0x800468A0: andi        $t7, $v1, 0x1
    ctx->r15 = ctx->r3 & 0X1;
    // 0x800468A4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800468A8: addiu       $a0, $a0, -0x6C40
    ctx->r4 = ADD32(ctx->r4, -0X6C40);
    // 0x800468AC: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800468B0: sub.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f26.fl;
    // 0x800468B4: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
L_800468B8:
    // 0x800468B8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800468BC: beq         $t7, $zero, L_800468D0
    if (ctx->r15 == 0) {
        // 0x800468C0: addiu       $a0, $a0, -0x6C40
        ctx->r4 = ADD32(ctx->r4, -0X6C40);
            goto L_800468D0;
    }
    // 0x800468C0: addiu       $a0, $a0, -0x6C40
    ctx->r4 = ADD32(ctx->r4, -0X6C40);
    // 0x800468C4: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800468C8: add.s       $f18, $f16, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f26.fl;
    // 0x800468CC: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
L_800468D0:
    // 0x800468D0: jal         0x8000798C
    // 0x800468D4: nop

    func_8000798C(rdram, ctx);
        goto after_68;
    // 0x800468D4: nop

    after_68:
    // 0x800468D8: b           L_80045B20
    // 0x800468DC: nop

        goto L_80045B20;
    // 0x800468DC: nop

    // 0x800468E0: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x800468E4: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x800468E8: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x800468EC: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x800468F0: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x800468F4: ldc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X48);
    // 0x800468F8: ldc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X50);
    // 0x800468FC: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x80046900: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x80046904: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x80046908: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x8004690C: lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X68);
    // 0x80046910: lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X6C);
    // 0x80046914: lw          $s6, 0x70($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X70);
    // 0x80046918: lw          $s7, 0x74($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X74);
    // 0x8004691C: lw          $fp, 0x78($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X78);
    // 0x80046920: jr          $ra
    // 0x80046924: addiu       $sp, $sp, 0x240
    ctx->r29 = ADD32(ctx->r29, 0X240);
    TRACE_RETURN()
    return;
    // 0x80046924: addiu       $sp, $sp, 0x240
    ctx->r29 = ADD32(ctx->r29, 0X240);
;}
RECOMP_FUNC void func_80046928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80046928: addiu       $sp, $sp, -0x430
    ctx->r29 = ADD32(ctx->r29, -0X430);
    // 0x8004692C: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x80046930: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80046934: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80046938: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004693C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80046940: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80046944: addiu       $v1, $v1, -0x6C40
    ctx->r3 = ADD32(ctx->r3, -0X6C40);
    // 0x80046948: addiu       $v0, $v0, -0x6C50
    ctx->r2 = ADD32(ctx->r2, -0X6C50);
    // 0x8004694C: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x80046950: sw          $s7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r23;
    // 0x80046954: sdc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X50, ctx->r29);
    // 0x80046958: sw          $a0, 0x430($sp)
    MEM_W(0X430, ctx->r29) = ctx->r4;
    // 0x8004695C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80046960: sw          $fp, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r30;
    // 0x80046964: sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // 0x80046968: sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // 0x8004696C: sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // 0x80046970: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // 0x80046974: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x80046978: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x8004697C: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x80046980: sdc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X48, ctx->r29);
    // 0x80046984: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x80046988: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x8004698C: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80046990: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x80046994: sh          $zero, 0x41A($sp)
    MEM_H(0X41A, ctx->r29) = 0;
    // 0x80046998: sh          $t6, 0x418($sp)
    MEM_H(0X418, ctx->r29) = ctx->r14;
    // 0x8004699C: sh          $zero, 0x2A8($sp)
    MEM_H(0X2A8, ctx->r29) = 0;
    // 0x800469A0: sh          $zero, 0x96($sp)
    MEM_H(0X96, ctx->r29) = 0;
    // 0x800469A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800469A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800469AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800469B0: mov.s       $f30, $f24
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    ctx->f30.fl = ctx->f24.fl;
    // 0x800469B4: swc1        $f24, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f24.u32l;
    // 0x800469B8: swc1        $f24, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f24.u32l;
    // 0x800469BC: swc1        $f24, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f24.u32l;
    // 0x800469C0: swc1        $f24, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f24.u32l;
    // 0x800469C4: swc1        $f24, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f24.u32l;
    // 0x800469C8: jal         0x8004C388
    // 0x800469CC: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    func_8004C388(rdram, ctx);
        goto after_0;
    // 0x800469CC: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    after_0:
    // 0x800469D0: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x800469D4: addiu       $a2, $a2, 0x7BC4
    ctx->r6 = ADD32(ctx->r6, 0X7BC4);
    // 0x800469D8: addiu       $a0, $zero, -0xFE
    ctx->r4 = ADD32(0, -0XFE);
    // 0x800469DC: jal         0x8004BCF0
    // 0x800469E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004BCF0(rdram, ctx);
        goto after_1;
    // 0x800469E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x800469E4: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x800469E8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800469EC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800469F0: addiu       $a1, $a1, -0x50B0
    ctx->r5 = ADD32(ctx->r5, -0X50B0);
    // 0x800469F4: addiu       $a0, $sp, 0x420
    ctx->r4 = ADD32(ctx->r29, 0X420);
    // 0x800469F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800469FC: jal         0x80049660
    // 0x80046A00: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_80049660(rdram, ctx);
        goto after_2;
    // 0x80046A00: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_2:
    // 0x80046A04: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x80046A08: jal         0x800499B0
    // 0x80046A0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800499B0(rdram, ctx);
        goto after_3;
    // 0x80046A0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80046A10: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80046A14: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x80046A18: addiu       $a0, $a0, -0x2E00
    ctx->r4 = ADD32(ctx->r4, -0X2E00);
    // 0x80046A1C: sw          $t8, 0x394($sp)
    MEM_W(0X394, ctx->r29) = ctx->r24;
    // 0x80046A20: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x80046A24: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80046A28: jal         0x80004CE0
    // 0x80046A2C: addiu       $a3, $sp, 0x394
    ctx->r7 = ADD32(ctx->r29, 0X394);
    func_80004CE0(rdram, ctx);
        goto after_4;
    // 0x80046A2C: addiu       $a3, $sp, 0x394
    ctx->r7 = ADD32(ctx->r29, 0X394);
    after_4:
    // 0x80046A30: jal         0x8000798C
    // 0x80046A34: sw          $v0, 0x390($sp)
    MEM_W(0X390, ctx->r29) = ctx->r2;
    func_8000798C(rdram, ctx);
        goto after_5;
    // 0x80046A34: sw          $v0, 0x390($sp)
    MEM_W(0X390, ctx->r29) = ctx->r2;
    after_5:
    // 0x80046A38: addiu       $s4, $sp, 0x2AC
    ctx->r20 = ADD32(ctx->r29, 0X2AC);
    // 0x80046A3C: addiu       $s0, $sp, 0x2C0
    ctx->r16 = ADD32(ctx->r29, 0X2C0);
L_80046A40:
    // 0x80046A40: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80046A44: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80046A48: jal         0x80004364
    // 0x80046A4C: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    func_80004364(rdram, ctx);
        goto after_6;
    // 0x80046A4C: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_6:
    // 0x80046A50: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    // 0x80046A54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80046A58: jal         0x8000C7C0
    // 0x80046A5C: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    func_8000C7C0(rdram, ctx);
        goto after_7;
    // 0x80046A5C: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_7:
    // 0x80046A60: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80046A64: sltu        $at, $s4, $s0
    ctx->r1 = ctx->r20 < ctx->r16 ? 1 : 0;
    // 0x80046A68: bne         $at, $zero, L_80046A40
    if (ctx->r1 != 0) {
        // 0x80046A6C: nop
    
            goto L_80046A40;
    }
    // 0x80046A6C: nop

    // 0x80046A70: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80046A74: lui         $s0, 0x8007
    ctx->r16 = S32(0X8007 << 16);
    // 0x80046A78: addiu       $s0, $s0, 0x7BD0
    ctx->r16 = ADD32(ctx->r16, 0X7BD0);
    // 0x80046A7C: lwc1        $f20, 0x7ED8($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X7ED8);
    // 0x80046A80: addiu       $s1, $sp, 0x2C0
    ctx->r17 = ADD32(ctx->r29, 0X2C0);
    // 0x80046A84: addiu       $s2, $sp, 0x374
    ctx->r18 = ADD32(ctx->r29, 0X374);
L_80046A88:
    // 0x80046A88: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80046A8C: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80046A90: jal         0x80004364
    // 0x80046A94: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    func_80004364(rdram, ctx);
        goto after_8;
    // 0x80046A94: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    after_8:
    // 0x80046A98: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x80046A9C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80046AA0: jal         0x8000C7C0
    // 0x80046AA4: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    func_8000C7C0(rdram, ctx);
        goto after_9;
    // 0x80046AA4: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    after_9:
    // 0x80046AA8: jal         0x80049CFC
    // 0x80046AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80049CFC(rdram, ctx);
        goto after_10;
    // 0x80046AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80046AB0: jal         0x80049D80
    // 0x80046AB4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80049D80(rdram, ctx);
        goto after_11;
    // 0x80046AB4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_11:
    // 0x80046AB8: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80046ABC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80046AC0: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x80046AC4: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80046AC8: jal         0x80049DFC
    // 0x80046ACC: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    func_80049DFC(rdram, ctx);
        goto after_12;
    // 0x80046ACC: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    after_12:
    // 0x80046AD0: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80046AD4: sw          $v0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r2;
    // 0x80046AD8: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80046ADC: swc1        $f20, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->f20.u32l;
    // 0x80046AE0: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80046AE4: jal         0x8004A148
    // 0x80046AE8: lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X4);
    func_8004A148(rdram, ctx);
        goto after_13;
    // 0x80046AE8: lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X4);
    after_13:
    // 0x80046AEC: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80046AF0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80046AF4: sltu        $at, $s1, $s2
    ctx->r1 = ctx->r17 < ctx->r18 ? 1 : 0;
    // 0x80046AF8: bne         $at, $zero, L_80046A88
    if (ctx->r1 != 0) {
        // 0x80046AFC: sh          $zero, 0x28($t4)
        MEM_H(0X28, ctx->r12) = 0;
            goto L_80046A88;
    }
    // 0x80046AFC: sh          $zero, 0x28($t4)
    MEM_H(0X28, ctx->r12) = 0;
    // 0x80046B00: lui         $t5, 0x8007
    ctx->r13 = S32(0X8007 << 16);
    // 0x80046B04: lh          $t5, 0x2584($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X2584);
    // 0x80046B08: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x80046B0C: mtc1        $at, $f29
    ctx->f_odd[(29 - 1) * 2] = ctx->r1;
    // 0x80046B10: beq         $t5, $zero, L_80046B7C
    if (ctx->r13 == 0) {
        // 0x80046B14: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80046B7C;
    }
    // 0x80046B14: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80046B18: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80046B1C: addiu       $a2, $a2, 0x2584
    ctx->r6 = ADD32(ctx->r6, 0X2584);
    // 0x80046B20: lh          $a3, 0x96($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X96);
    // 0x80046B24: addiu       $a0, $sp, 0x9C
    ctx->r4 = ADD32(ctx->r29, 0X9C);
    // 0x80046B28: lw          $a1, 0x4($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X4);
L_80046B2C:
    // 0x80046B2C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80046B30: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x80046B34: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80046B38: beql        $t6, $zero, L_80046B6C
    if (ctx->r14 == 0) {
        // 0x80046B3C: lh          $t1, 0x8($a2)
        ctx->r9 = MEM_H(ctx->r6, 0X8);
            goto L_80046B6C;
    }
    goto skip_0;
    // 0x80046B3C: lh          $t1, 0x8($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X8);
    skip_0:
    // 0x80046B40: lh          $v1, 0x0($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X0);
L_80046B44:
    // 0x80046B44: sll         $t7, $a3, 1
    ctx->r15 = S32(ctx->r7 << 1);
    // 0x80046B48: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x80046B4C: sh          $v1, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r3;
    // 0x80046B50: lh          $v1, 0x38($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X38);
    // 0x80046B54: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80046B58: sll         $t9, $a3, 16
    ctx->r25 = S32(ctx->r7 << 16);
    // 0x80046B5C: sra         $a3, $t9, 16
    ctx->r7 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80046B60: bne         $v1, $zero, L_80046B44
    if (ctx->r3 != 0) {
        // 0x80046B64: addiu       $v0, $v0, 0x38
        ctx->r2 = ADD32(ctx->r2, 0X38);
            goto L_80046B44;
    }
    // 0x80046B64: addiu       $v0, $v0, 0x38
    ctx->r2 = ADD32(ctx->r2, 0X38);
    // 0x80046B68: lh          $t1, 0x8($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X8);
L_80046B6C:
    // 0x80046B6C: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80046B70: bnel        $t1, $zero, L_80046B2C
    if (ctx->r9 != 0) {
        // 0x80046B74: lw          $a1, 0x4($a2)
        ctx->r5 = MEM_W(ctx->r6, 0X4);
            goto L_80046B2C;
    }
    goto skip_1;
    // 0x80046B74: lw          $a1, 0x4($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X4);
    skip_1:
    // 0x80046B78: sh          $a3, 0x96($sp)
    MEM_H(0X96, ctx->r29) = ctx->r7;
L_80046B7C:
    // 0x80046B7C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80046B80: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80046B84: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x80046B88: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x80046B8C: addiu       $s6, $sp, 0x398
    ctx->r22 = ADD32(ctx->r29, 0X398);
    // 0x80046B90: addiu       $s5, $sp, 0x3D8
    ctx->r21 = ADD32(ctx->r29, 0X3D8);
L_80046B94:
    // 0x80046B94: jal         0x800496B4
    // 0x80046B98: addiu       $a0, $sp, 0x420
    ctx->r4 = ADD32(ctx->r29, 0X420);
    func_800496B4(rdram, ctx);
        goto after_14;
    // 0x80046B98: addiu       $a0, $sp, 0x420
    ctx->r4 = ADD32(ctx->r29, 0X420);
    after_14:
    // 0x80046B9C: lh          $v1, 0x42C($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X42C);
    // 0x80046BA0: addiu       $t2, $v1, -0x1
    ctx->r10 = ADD32(ctx->r3, -0X1);
    // 0x80046BA4: sltiu       $at, $t2, 0x9
    ctx->r1 = ctx->r10 < 0X9 ? 1 : 0;
    // 0x80046BA8: beq         $at, $zero, L_80047090
    if (ctx->r1 == 0) {
        // 0x80046BAC: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_80047090;
    }
    // 0x80046BAC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80046BB0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80046BB4: addu        $at, $at, $t2
    gpr jr_addend_80046BBC = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80046BB8: lw          $t2, 0x7EDC($at)
    ctx->r10 = ADD32(ctx->r1, 0X7EDC);
    // 0x80046BBC: jr          $t2
    // 0x80046BC0: nop

    switch (jr_addend_80046BBC >> 2) {
        case 0: goto L_80046BC4; break;
        case 1: goto L_80046C6C; break;
        case 2: goto L_80046CCC; break;
        case 3: goto L_80046D3C; break;
        case 4: goto L_80046D94; break;
        case 5: goto L_80046DEC; break;
        case 6: goto L_80046E44; break;
        case 7: goto L_80046EB4; break;
        case 8: goto L_80046F74; break;
        default: switch_error(__func__, 0x80046BBC, 0x80077EDC);
    }
    // 0x80046BC0: nop

L_80046BC4:
    // 0x80046BC4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80046BC8: lhu         $v0, -0x2E58($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2E58);
    // 0x80046BCC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80046BD0: addiu       $a1, $v1, 0x3
    ctx->r5 = ADD32(ctx->r3, 0X3);
    // 0x80046BD4: andi        $t3, $v0, 0x200
    ctx->r11 = ctx->r2 & 0X200;
    // 0x80046BD8: beq         $t3, $zero, L_80046C0C
    if (ctx->r11 == 0) {
        // 0x80046BDC: sll         $a2, $fp, 16
        ctx->r6 = S32(ctx->r30 << 16);
            goto L_80046C0C;
    }
    // 0x80046BDC: sll         $a2, $fp, 16
    ctx->r6 = S32(ctx->r30 << 16);
    // 0x80046BE0: lh          $t4, 0x96($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X96);
    // 0x80046BE4: lh          $v0, 0x41A($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X41A);
    // 0x80046BE8: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80046BEC: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80046BF0: beq         $at, $zero, L_80046C04
    if (ctx->r1 == 0) {
        // 0x80046BF4: nop
    
            goto L_80046C04;
    }
    // 0x80046BF4: nop

    // 0x80046BF8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80046BFC: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x80046C00: sra         $v0, $t6, 16
    ctx->r2 = S32(SIGNED(ctx->r14) >> 16);
L_80046C04:
    // 0x80046C04: b           L_80046C30
    // 0x80046C08: sh          $v0, 0x41A($sp)
    MEM_H(0X41A, ctx->r29) = ctx->r2;
        goto L_80046C30;
    // 0x80046C08: sh          $v0, 0x41A($sp)
    MEM_H(0X41A, ctx->r29) = ctx->r2;
L_80046C0C:
    // 0x80046C0C: andi        $t8, $v0, 0x100
    ctx->r24 = ctx->r2 & 0X100;
    // 0x80046C10: beq         $t8, $zero, L_80046C30
    if (ctx->r24 == 0) {
        // 0x80046C14: lh          $t9, 0x41A($sp)
        ctx->r25 = MEM_H(ctx->r29, 0X41A);
            goto L_80046C30;
    }
    // 0x80046C14: lh          $t9, 0x41A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X41A);
    // 0x80046C18: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80046C1C: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x80046C20: sra         $t2, $t1, 16
    ctx->r10 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80046C24: bgez        $t2, L_80046C30
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80046C28: sh          $t0, 0x41A($sp)
        MEM_H(0X41A, ctx->r29) = ctx->r8;
            goto L_80046C30;
    }
    // 0x80046C28: sh          $t0, 0x41A($sp)
    MEM_H(0X41A, ctx->r29) = ctx->r8;
    // 0x80046C2C: sh          $zero, 0x41A($sp)
    MEM_H(0X41A, ctx->r29) = 0;
L_80046C30:
    // 0x80046C30: sll         $t3, $a1, 16
    ctx->r11 = S32(ctx->r5 << 16);
    // 0x80046C34: sra         $t5, $a2, 16
    ctx->r13 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80046C38: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x80046C3C: jal         0x8004C388
    // 0x80046C40: sra         $a1, $t3, 16
    ctx->r5 = S32(SIGNED(ctx->r11) >> 16);
    func_8004C388(rdram, ctx);
        goto after_15;
    // 0x80046C40: sra         $a1, $t3, 16
    ctx->r5 = S32(SIGNED(ctx->r11) >> 16);
    after_15:
    // 0x80046C44: sll         $a1, $fp, 16
    ctx->r5 = S32(ctx->r30 << 16);
    // 0x80046C48: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80046C4C: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80046C50: addiu       $a2, $a2, 0x7BD8
    ctx->r6 = ADD32(ctx->r6, 0X7BD8);
    // 0x80046C54: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80046C58: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80046C5C: jal         0x8004C340
    // 0x80046C60: lh          $a3, 0x41A($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X41A);
    func_8004C340(rdram, ctx);
        goto after_16;
    // 0x80046C60: lh          $a3, 0x41A($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X41A);
    after_16:
    // 0x80046C64: b           L_80047094
    // 0x80046C68: lh          $t0, 0x41A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X41A);
        goto L_80047094;
    // 0x80046C68: lh          $t0, 0x41A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X41A);
L_80046C6C:
    // 0x80046C6C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80046C70: lhu         $v0, -0x2E58($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2E58);
    // 0x80046C74: lh          $t8, 0x2A8($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X2A8);
    // 0x80046C78: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80046C7C: andi        $t7, $v0, 0x200
    ctx->r15 = ctx->r2 & 0X200;
    // 0x80046C80: beq         $t7, $zero, L_80046CA8
    if (ctx->r15 == 0) {
        // 0x80046C84: andi        $t5, $v0, 0x100
        ctx->r13 = ctx->r2 & 0X100;
            goto L_80046CA8;
    }
    // 0x80046C84: andi        $t5, $v0, 0x100
    ctx->r13 = ctx->r2 & 0X100;
    // 0x80046C88: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80046C8C: sll         $t0, $t9, 16
    ctx->r8 = S32(ctx->r25 << 16);
    // 0x80046C90: sra         $t1, $t0, 16
    ctx->r9 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80046C94: bne         $t1, $at, L_80047090
    if (ctx->r9 != ctx->r1) {
        // 0x80046C98: sh          $t9, 0x2A8($sp)
        MEM_H(0X2A8, ctx->r29) = ctx->r25;
            goto L_80047090;
    }
    // 0x80046C98: sh          $t9, 0x2A8($sp)
    MEM_H(0X2A8, ctx->r29) = ctx->r25;
    // 0x80046C9C: addiu       $t4, $t9, -0x1
    ctx->r12 = ADD32(ctx->r25, -0X1);
    // 0x80046CA0: b           L_80047090
    // 0x80046CA4: sh          $t4, 0x2A8($sp)
    MEM_H(0X2A8, ctx->r29) = ctx->r12;
        goto L_80047090;
    // 0x80046CA4: sh          $t4, 0x2A8($sp)
    MEM_H(0X2A8, ctx->r29) = ctx->r12;
L_80046CA8:
    // 0x80046CA8: beq         $t5, $zero, L_80047090
    if (ctx->r13 == 0) {
        // 0x80046CAC: lh          $t6, 0x2A8($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X2A8);
            goto L_80047090;
    }
    // 0x80046CAC: lh          $t6, 0x2A8($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X2A8);
    // 0x80046CB0: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80046CB4: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80046CB8: sra         $t0, $t8, 16
    ctx->r8 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80046CBC: bgez        $t0, L_80047090
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80046CC0: sh          $t7, 0x2A8($sp)
        MEM_H(0X2A8, ctx->r29) = ctx->r15;
            goto L_80047090;
    }
    // 0x80046CC0: sh          $t7, 0x2A8($sp)
    MEM_H(0X2A8, ctx->r29) = ctx->r15;
    // 0x80046CC4: b           L_80047090
    // 0x80046CC8: sh          $zero, 0x2A8($sp)
    MEM_H(0X2A8, ctx->r29) = 0;
        goto L_80047090;
    // 0x80046CC8: sh          $zero, 0x2A8($sp)
    MEM_H(0X2A8, ctx->r29) = 0;
L_80046CCC:
    // 0x80046CCC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80046CD0: lhu         $v0, -0x2E58($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2E58);
    // 0x80046CD4: lh          $t9, 0x2A8($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X2A8);
    // 0x80046CD8: andi        $t1, $v0, 0x200
    ctx->r9 = ctx->r2 & 0X200;
    // 0x80046CDC: beq         $t1, $zero, L_80046D00
    if (ctx->r9 == 0) {
        // 0x80046CE0: andi        $t5, $v0, 0x100
        ctx->r13 = ctx->r2 & 0X100;
            goto L_80046D00;
    }
    // 0x80046CE0: andi        $t5, $v0, 0x100
    ctx->r13 = ctx->r2 & 0X100;
    // 0x80046CE4: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x80046CE8: addu        $v0, $sp, $t2
    ctx->r2 = ADD32(ctx->r29, ctx->r10);
    // 0x80046CEC: lw          $v0, 0x2AC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2AC);
    // 0x80046CF0: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x80046CF4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80046CF8: b           L_80047090
    // 0x80046CFC: sh          $t4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r12;
        goto L_80047090;
    // 0x80046CFC: sh          $t4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r12;
L_80046D00:
    // 0x80046D00: beq         $t5, $zero, L_80047090
    if (ctx->r13 == 0) {
        // 0x80046D04: lh          $t6, 0x2A8($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X2A8);
            goto L_80047090;
    }
    // 0x80046D04: lh          $t6, 0x2A8($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X2A8);
    // 0x80046D08: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80046D0C: addiu       $t8, $sp, 0x2AC
    ctx->r24 = ADD32(ctx->r29, 0X2AC);
    // 0x80046D10: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80046D14: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80046D18: lh          $t0, 0x0($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X0);
    // 0x80046D1C: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80046D20: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
    // 0x80046D24: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80046D28: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x80046D2C: bgezl       $t9, L_80047094
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80046D30: lh          $t0, 0x41A($sp)
        ctx->r8 = MEM_H(ctx->r29, 0X41A);
            goto L_80047094;
    }
    goto skip_2;
    // 0x80046D30: lh          $t0, 0x41A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X41A);
    skip_2:
    // 0x80046D34: b           L_80047090
    // 0x80046D38: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
        goto L_80047090;
    // 0x80046D38: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
L_80046D3C:
    // 0x80046D3C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80046D40: lhu         $v1, -0x2E5C($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2E5C);
    // 0x80046D44: lh          $t3, 0x2A8($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X2A8);
    // 0x80046D48: andi        $t2, $v1, 0x200
    ctx->r10 = ctx->r3 & 0X200;
    // 0x80046D4C: beq         $t2, $zero, L_80046D70
    if (ctx->r10 == 0) {
        // 0x80046D50: andi        $t7, $v1, 0x100
        ctx->r15 = ctx->r3 & 0X100;
            goto L_80046D70;
    }
    // 0x80046D50: andi        $t7, $v1, 0x100
    ctx->r15 = ctx->r3 & 0X100;
    // 0x80046D54: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80046D58: addu        $v0, $sp, $t4
    ctx->r2 = ADD32(ctx->r29, ctx->r12);
    // 0x80046D5C: lw          $v0, 0x2AC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2AC);
    // 0x80046D60: lh          $t5, 0x2($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X2);
    // 0x80046D64: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80046D68: b           L_80047090
    // 0x80046D6C: sh          $t6, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r14;
        goto L_80047090;
    // 0x80046D6C: sh          $t6, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r14;
L_80046D70:
    // 0x80046D70: beq         $t7, $zero, L_80047090
    if (ctx->r15 == 0) {
        // 0x80046D74: lh          $t8, 0x2A8($sp)
        ctx->r24 = MEM_H(ctx->r29, 0X2A8);
            goto L_80047090;
    }
    // 0x80046D74: lh          $t8, 0x2A8($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X2A8);
    // 0x80046D78: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x80046D7C: addu        $v0, $sp, $t0
    ctx->r2 = ADD32(ctx->r29, ctx->r8);
    // 0x80046D80: lw          $v0, 0x2AC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2AC);
    // 0x80046D84: lh          $t1, 0x2($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X2);
    // 0x80046D88: addiu       $t9, $t1, -0x1
    ctx->r25 = ADD32(ctx->r9, -0X1);
    // 0x80046D8C: b           L_80047090
    // 0x80046D90: sh          $t9, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r25;
        goto L_80047090;
    // 0x80046D90: sh          $t9, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r25;
L_80046D94:
    // 0x80046D94: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80046D98: lhu         $v1, -0x2E5C($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2E5C);
    // 0x80046D9C: lh          $t3, 0x2A8($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X2A8);
    // 0x80046DA0: andi        $t2, $v1, 0x200
    ctx->r10 = ctx->r3 & 0X200;
    // 0x80046DA4: beq         $t2, $zero, L_80046DC8
    if (ctx->r10 == 0) {
        // 0x80046DA8: andi        $t7, $v1, 0x100
        ctx->r15 = ctx->r3 & 0X100;
            goto L_80046DC8;
    }
    // 0x80046DA8: andi        $t7, $v1, 0x100
    ctx->r15 = ctx->r3 & 0X100;
    // 0x80046DAC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80046DB0: addu        $v0, $sp, $t4
    ctx->r2 = ADD32(ctx->r29, ctx->r12);
    // 0x80046DB4: lw          $v0, 0x2AC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2AC);
    // 0x80046DB8: lh          $t5, 0x4($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X4);
    // 0x80046DBC: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80046DC0: b           L_80047090
    // 0x80046DC4: sh          $t6, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r14;
        goto L_80047090;
    // 0x80046DC4: sh          $t6, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r14;
L_80046DC8:
    // 0x80046DC8: beq         $t7, $zero, L_80047090
    if (ctx->r15 == 0) {
        // 0x80046DCC: lh          $t8, 0x2A8($sp)
        ctx->r24 = MEM_H(ctx->r29, 0X2A8);
            goto L_80047090;
    }
    // 0x80046DCC: lh          $t8, 0x2A8($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X2A8);
    // 0x80046DD0: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x80046DD4: addu        $v0, $sp, $t0
    ctx->r2 = ADD32(ctx->r29, ctx->r8);
    // 0x80046DD8: lw          $v0, 0x2AC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2AC);
    // 0x80046DDC: lh          $t1, 0x4($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X4);
    // 0x80046DE0: addiu       $t9, $t1, -0x1
    ctx->r25 = ADD32(ctx->r9, -0X1);
    // 0x80046DE4: b           L_80047090
    // 0x80046DE8: sh          $t9, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r25;
        goto L_80047090;
    // 0x80046DE8: sh          $t9, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r25;
L_80046DEC:
    // 0x80046DEC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80046DF0: lhu         $v1, -0x2E5C($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2E5C);
    // 0x80046DF4: lh          $t3, 0x2A8($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X2A8);
    // 0x80046DF8: andi        $t2, $v1, 0x200
    ctx->r10 = ctx->r3 & 0X200;
    // 0x80046DFC: beq         $t2, $zero, L_80046E20
    if (ctx->r10 == 0) {
        // 0x80046E00: andi        $t7, $v1, 0x100
        ctx->r15 = ctx->r3 & 0X100;
            goto L_80046E20;
    }
    // 0x80046E00: andi        $t7, $v1, 0x100
    ctx->r15 = ctx->r3 & 0X100;
    // 0x80046E04: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80046E08: addu        $v0, $sp, $t4
    ctx->r2 = ADD32(ctx->r29, ctx->r12);
    // 0x80046E0C: lw          $v0, 0x2AC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2AC);
    // 0x80046E10: lh          $t5, 0x6($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X6);
    // 0x80046E14: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80046E18: b           L_80047090
    // 0x80046E1C: sh          $t6, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r14;
        goto L_80047090;
    // 0x80046E1C: sh          $t6, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r14;
L_80046E20:
    // 0x80046E20: beq         $t7, $zero, L_80047090
    if (ctx->r15 == 0) {
        // 0x80046E24: lh          $t8, 0x2A8($sp)
        ctx->r24 = MEM_H(ctx->r29, 0X2A8);
            goto L_80047090;
    }
    // 0x80046E24: lh          $t8, 0x2A8($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X2A8);
    // 0x80046E28: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x80046E2C: addu        $v0, $sp, $t0
    ctx->r2 = ADD32(ctx->r29, ctx->r8);
    // 0x80046E30: lw          $v0, 0x2AC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2AC);
    // 0x80046E34: lh          $t1, 0x6($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X6);
    // 0x80046E38: addiu       $t9, $t1, -0x1
    ctx->r25 = ADD32(ctx->r9, -0X1);
    // 0x80046E3C: b           L_80047090
    // 0x80046E40: sh          $t9, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r25;
        goto L_80047090;
    // 0x80046E40: sh          $t9, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r25;
L_80046E44:
    // 0x80046E44: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80046E48: lhu         $v0, -0x2E58($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2E58);
    // 0x80046E4C: lh          $t3, 0x2A8($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X2A8);
    // 0x80046E50: andi        $t2, $v0, 0x200
    ctx->r10 = ctx->r2 & 0X200;
    // 0x80046E54: beq         $t2, $zero, L_80046E78
    if (ctx->r10 == 0) {
        // 0x80046E58: andi        $t7, $v0, 0x100
        ctx->r15 = ctx->r2 & 0X100;
            goto L_80046E78;
    }
    // 0x80046E58: andi        $t7, $v0, 0x100
    ctx->r15 = ctx->r2 & 0X100;
    // 0x80046E5C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80046E60: addu        $v0, $sp, $t4
    ctx->r2 = ADD32(ctx->r29, ctx->r12);
    // 0x80046E64: lw          $v0, 0x2AC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2AC);
    // 0x80046E68: lh          $t5, 0x14($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X14);
    // 0x80046E6C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80046E70: b           L_80047090
    // 0x80046E74: sh          $t6, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r14;
        goto L_80047090;
    // 0x80046E74: sh          $t6, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r14;
L_80046E78:
    // 0x80046E78: beq         $t7, $zero, L_80047090
    if (ctx->r15 == 0) {
        // 0x80046E7C: lh          $t8, 0x2A8($sp)
        ctx->r24 = MEM_H(ctx->r29, 0X2A8);
            goto L_80047090;
    }
    // 0x80046E7C: lh          $t8, 0x2A8($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X2A8);
    // 0x80046E80: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x80046E84: addiu       $t1, $sp, 0x2AC
    ctx->r9 = ADD32(ctx->r29, 0X2AC);
    // 0x80046E88: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x80046E8C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80046E90: lh          $t9, 0x14($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X14);
    // 0x80046E94: addiu       $t2, $t9, -0x1
    ctx->r10 = ADD32(ctx->r25, -0X1);
    // 0x80046E98: sh          $t2, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r10;
    // 0x80046E9C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80046EA0: lh          $t3, 0x14($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X14);
    // 0x80046EA4: bgezl       $t3, L_80047094
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80046EA8: lh          $t0, 0x41A($sp)
        ctx->r8 = MEM_H(ctx->r29, 0X41A);
            goto L_80047094;
    }
    goto skip_3;
    // 0x80046EA8: lh          $t0, 0x41A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X41A);
    skip_3:
    // 0x80046EAC: b           L_80047090
    // 0x80046EB0: sh          $zero, 0x14($v0)
    MEM_H(0X14, ctx->r2) = 0;
        goto L_80047090;
    // 0x80046EB0: sh          $zero, 0x14($v0)
    MEM_H(0X14, ctx->r2) = 0;
L_80046EB4:
    // 0x80046EB4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80046EB8: lhu         $v0, -0x2E58($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2E58);
    // 0x80046EBC: sll         $a2, $fp, 16
    ctx->r6 = S32(ctx->r30 << 16);
    // 0x80046EC0: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80046EC4: andi        $t4, $v0, 0x200
    ctx->r12 = ctx->r2 & 0X200;
    // 0x80046EC8: beq         $t4, $zero, L_80046EF4
    if (ctx->r12 == 0) {
        // 0x80046ECC: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_80046EF4;
    }
    // 0x80046ECC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80046ED0: lwc1        $f6, 0x24($s7)
    ctx->f6.u32l = MEM_W(ctx->r23, 0X24);
    // 0x80046ED4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80046ED8: ldc1        $f10, 0x7F00($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X7F00);
    // 0x80046EDC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80046EE0: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x80046EE4: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80046EE8: swc1        $f18, 0x24($s7)
    MEM_W(0X24, ctx->r23) = ctx->f18.u32l;
    // 0x80046EEC: b           L_80046F20
    // 0x80046EF0: lh          $v1, 0x42C($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X42C);
        goto L_80046F20;
    // 0x80046EF0: lh          $v1, 0x42C($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X42C);
L_80046EF4:
    // 0x80046EF4: andi        $t5, $v0, 0x100
    ctx->r13 = ctx->r2 & 0X100;
    // 0x80046EF8: beql        $t5, $zero, L_80046F24
    if (ctx->r13 == 0) {
        // 0x80046EFC: addiu       $a1, $v1, 0x3
        ctx->r5 = ADD32(ctx->r3, 0X3);
            goto L_80046F24;
    }
    goto skip_4;
    // 0x80046EFC: addiu       $a1, $v1, 0x3
    ctx->r5 = ADD32(ctx->r3, 0X3);
    skip_4:
    // 0x80046F00: lwc1        $f4, 0x24($s7)
    ctx->f4.u32l = MEM_W(ctx->r23, 0X24);
    // 0x80046F04: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80046F08: ldc1        $f8, 0x7F08($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X7F08);
    // 0x80046F0C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80046F10: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x80046F14: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80046F18: swc1        $f16, 0x24($s7)
    MEM_W(0X24, ctx->r23) = ctx->f16.u32l;
    // 0x80046F1C: lh          $v1, 0x42C($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X42C);
L_80046F20:
    // 0x80046F20: addiu       $a1, $v1, 0x3
    ctx->r5 = ADD32(ctx->r3, 0X3);
L_80046F24:
    // 0x80046F24: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80046F28: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80046F2C: jal         0x8004C388
    // 0x80046F30: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    func_8004C388(rdram, ctx);
        goto after_17;
    // 0x80046F30: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    after_17:
    // 0x80046F34: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80046F38: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80046F3C: lwc1        $f18, 0x24($s7)
    ctx->f18.u32l = MEM_W(ctx->r23, 0X24);
    // 0x80046F40: sll         $a1, $fp, 16
    ctx->r5 = S32(ctx->r30 << 16);
    // 0x80046F44: sra         $t0, $a1, 16
    ctx->r8 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80046F48: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80046F4C: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80046F50: addiu       $a2, $a2, 0x7BDC
    ctx->r6 = ADD32(ctx->r6, 0X7BDC);
    // 0x80046F54: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x80046F58: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80046F5C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80046F60: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80046F64: jal         0x8004C340
    // 0x80046F68: nop

    func_8004C340(rdram, ctx);
        goto after_18;
    // 0x80046F68: nop

    after_18:
    // 0x80046F6C: b           L_80047094
    // 0x80046F70: lh          $t0, 0x41A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X41A);
        goto L_80047094;
    // 0x80046F70: lh          $t0, 0x41A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X41A);
L_80046F74:
    // 0x80046F74: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80046F78: lhu         $t9, -0x2E5A($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X2E5A);
    // 0x80046F7C: andi        $t2, $t9, 0x1000
    ctx->r10 = ctx->r25 & 0X1000;
    // 0x80046F80: beq         $t2, $zero, L_80047090
    if (ctx->r10 == 0) {
        // 0x80046F84: addiu       $s4, $sp, 0x2AC
        ctx->r20 = ADD32(ctx->r29, 0X2AC);
            goto L_80047090;
    }
    // 0x80046F84: addiu       $s4, $sp, 0x2AC
    ctx->r20 = ADD32(ctx->r29, 0X2AC);
    // 0x80046F88: addiu       $s0, $sp, 0x2C0
    ctx->r16 = ADD32(ctx->r29, 0X2C0);
L_80046F8C:
    // 0x80046F8C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80046F90: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80046F94: jal         0x800042A8
    // 0x80046F98: lw          $a1, 0x0($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X0);
    func_800042A8(rdram, ctx);
        goto after_19;
    // 0x80046F98: lw          $a1, 0x0($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X0);
    after_19:
    // 0x80046F9C: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80046FA0: sltu        $at, $s4, $s0
    ctx->r1 = ctx->r20 < ctx->r16 ? 1 : 0;
    // 0x80046FA4: bne         $at, $zero, L_80046F8C
    if (ctx->r1 != 0) {
        // 0x80046FA8: nop
    
            goto L_80046F8C;
    }
    // 0x80046FA8: nop

    // 0x80046FAC: addiu       $s1, $sp, 0x2C0
    ctx->r17 = ADD32(ctx->r29, 0X2C0);
    // 0x80046FB0: addiu       $s0, $sp, 0x374
    ctx->r16 = ADD32(ctx->r29, 0X374);
    // 0x80046FB4: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
L_80046FB8:
    // 0x80046FB8: jal         0x8004A0C4
    // 0x80046FBC: lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X4);
    func_8004A0C4(rdram, ctx);
        goto after_20;
    // 0x80046FBC: lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X4);
    after_20:
    // 0x80046FC0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80046FC4: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80046FC8: jal         0x800042A8
    // 0x80046FCC: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    func_800042A8(rdram, ctx);
        goto after_21;
    // 0x80046FCC: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    after_21:
    // 0x80046FD0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80046FD4: bnel        $s1, $s0, L_80046FB8
    if (ctx->r17 != ctx->r16) {
        // 0x80046FD8: lw          $t3, 0x0($s1)
        ctx->r11 = MEM_W(ctx->r17, 0X0);
            goto L_80046FB8;
    }
    goto skip_5;
    // 0x80046FD8: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    skip_5:
    // 0x80046FDC: jal         0x8004A0C4
    // 0x80046FE0: lw          $a0, 0x8C($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X8C);
    func_8004A0C4(rdram, ctx);
        goto after_22;
    // 0x80046FE0: lw          $a0, 0x8C($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X8C);
    after_22:
    // 0x80046FE4: lh          $t4, 0x2C($s7)
    ctx->r12 = MEM_H(ctx->r23, 0X2C);
    // 0x80046FE8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80046FEC: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80046FF0: beq         $t4, $zero, L_80047004
    if (ctx->r12 == 0) {
        // 0x80046FF4: lui         $a2, 0x8013
        ctx->r6 = S32(0X8013 << 16);
            goto L_80047004;
    }
    // 0x80046FF4: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80046FF8: lw          $a1, 0x28($s7)
    ctx->r5 = MEM_W(ctx->r23, 0X28);
    // 0x80046FFC: jal         0x8001026C
    // 0x80047000: addiu       $a2, $a2, -0x6C60
    ctx->r6 = ADD32(ctx->r6, -0X6C60);
    func_8001026C(rdram, ctx);
        goto after_23;
    // 0x80047000: addiu       $a2, $a2, -0x6C60
    ctx->r6 = ADD32(ctx->r6, -0X6C60);
    after_23:
L_80047004:
    // 0x80047004: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80047008: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8004700C: jal         0x800042A8
    // 0x80047010: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    func_800042A8(rdram, ctx);
        goto after_24;
    // 0x80047010: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_24:
    // 0x80047014: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80047018: jal         0x8004C4D8
    // 0x8004701C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8004C4D8(rdram, ctx);
        goto after_25;
    // 0x8004701C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_25:
    // 0x80047020: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80047024: sw          $t5, 0x394($sp)
    MEM_W(0X394, ctx->r29) = ctx->r13;
L_80047028:
    // 0x80047028: jal         0x8000798C
    // 0x8004702C: nop

    func_8000798C(rdram, ctx);
        goto after_26;
    // 0x8004702C: nop

    after_26:
    // 0x80047030: lw          $t6, 0x394($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X394);
    // 0x80047034: bne         $t6, $zero, L_80047028
    if (ctx->r14 != 0) {
        // 0x80047038: nop
    
            goto L_80047028;
    }
    // 0x80047038: nop

    // 0x8004703C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80047040: sh          $t7, 0x418($sp)
    MEM_H(0X418, ctx->r29) = ctx->r15;
    // 0x80047044: sh          $zero, 0x418($sp)
    MEM_H(0X418, ctx->r29) = 0;
    // 0x80047048: jal         0x80004E5C
    // 0x8004704C: lw          $a0, 0x390($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X390);
    func_80004E5C(rdram, ctx);
        goto after_27;
    // 0x8004704C: lw          $a0, 0x390($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X390);
    after_27:
    // 0x80047050: jal         0x80049C48
    // 0x80047054: nop

    func_80049C48(rdram, ctx);
        goto after_28;
    // 0x80047054: nop

    after_28:
    // 0x80047058: jal         0x8000798C
    // 0x8004705C: nop

    func_8000798C(rdram, ctx);
        goto after_29;
    // 0x8004705C: nop

    after_29:
    // 0x80047060: jal         0x8000798C
    // 0x80047064: nop

    func_8000798C(rdram, ctx);
        goto after_30;
    // 0x80047064: nop

    after_30:
    // 0x80047068: jal         0x8000798C
    // 0x8004706C: nop

    func_8000798C(rdram, ctx);
        goto after_31;
    // 0x8004706C: nop

    after_31:
    // 0x80047070: jal         0x8000798C
    // 0x80047074: nop

    func_8000798C(rdram, ctx);
        goto after_32;
    // 0x80047074: nop

    after_32:
    // 0x80047078: lw          $t8, 0x430($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X430);
    // 0x8004707C: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
L_80047080:
    // 0x80047080: jal         0x8000798C
    // 0x80047084: nop

    func_8000798C(rdram, ctx);
        goto after_33;
    // 0x80047084: nop

    after_33:
    // 0x80047088: b           L_80047080
    // 0x8004708C: nop

        goto L_80047080;
    // 0x8004708C: nop

L_80047090:
    // 0x80047090: lh          $t0, 0x41A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X41A);
L_80047094:
    // 0x80047094: lh          $t1, 0x418($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X418);
    // 0x80047098: beql        $t0, $t1, L_80047234
    if (ctx->r8 == ctx->r9) {
        // 0x8004709C: addiu       $s1, $sp, 0x2C0
        ctx->r17 = ADD32(ctx->r29, 0X2C0);
            goto L_80047234;
    }
    goto skip_6;
    // 0x8004709C: addiu       $s1, $sp, 0x2C0
    ctx->r17 = ADD32(ctx->r29, 0X2C0);
    skip_6:
    // 0x800470A0: beql        $s7, $zero, L_800470E4
    if (ctx->r23 == 0) {
        // 0x800470A4: lh          $t2, 0x41A($sp)
        ctx->r10 = MEM_H(ctx->r29, 0X41A);
            goto L_800470E4;
    }
    goto skip_7;
    // 0x800470A4: lh          $t2, 0x41A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X41A);
    skip_7:
    // 0x800470A8: jal         0x8004A0C4
    // 0x800470AC: lw          $a0, 0x8C($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X8C);
    func_8004A0C4(rdram, ctx);
        goto after_34;
    // 0x800470AC: lw          $a0, 0x8C($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X8C);
    after_34:
    // 0x800470B0: lh          $t9, 0x2C($s7)
    ctx->r25 = MEM_H(ctx->r23, 0X2C);
    // 0x800470B4: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800470B8: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x800470BC: beq         $t9, $zero, L_800470D0
    if (ctx->r25 == 0) {
        // 0x800470C0: lui         $a2, 0x8013
        ctx->r6 = S32(0X8013 << 16);
            goto L_800470D0;
    }
    // 0x800470C0: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800470C4: lw          $a1, 0x28($s7)
    ctx->r5 = MEM_W(ctx->r23, 0X28);
    // 0x800470C8: jal         0x8001026C
    // 0x800470CC: addiu       $a2, $a2, -0x6C60
    ctx->r6 = ADD32(ctx->r6, -0X6C60);
    func_8001026C(rdram, ctx);
        goto after_35;
    // 0x800470CC: addiu       $a2, $a2, -0x6C60
    ctx->r6 = ADD32(ctx->r6, -0X6C60);
    after_35:
L_800470D0:
    // 0x800470D0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800470D4: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x800470D8: jal         0x800042A8
    // 0x800470DC: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    func_800042A8(rdram, ctx);
        goto after_36;
    // 0x800470DC: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_36:
    // 0x800470E0: lh          $t2, 0x41A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X41A);
L_800470E4:
    // 0x800470E4: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800470E8: addiu       $t4, $sp, 0x9C
    ctx->r12 = ADD32(ctx->r29, 0X9C);
    // 0x800470EC: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800470F0: addu        $s1, $t3, $t4
    ctx->r17 = ADD32(ctx->r11, ctx->r12);
    // 0x800470F4: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x800470F8: addiu       $a1, $zero, 0x144
    ctx->r5 = ADD32(0, 0X144);
    // 0x800470FC: jal         0x80004364
    // 0x80047100: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    func_80004364(rdram, ctx);
        goto after_37;
    // 0x80047100: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_37:
    // 0x80047104: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x80047108: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8004710C: jal         0x8000C7C0
    // 0x80047110: addiu       $a1, $zero, 0x144
    ctx->r5 = ADD32(0, 0X144);
    func_8000C7C0(rdram, ctx);
        goto after_38;
    // 0x80047110: addiu       $a1, $zero, 0x144
    ctx->r5 = ADD32(0, 0X144);
    after_38:
    // 0x80047114: lh          $t5, 0x0($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X0);
    // 0x80047118: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8004711C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80047120: sh          $t5, 0x94($s7)
    MEM_H(0X94, ctx->r23) = ctx->r13;
    // 0x80047124: jal         0x80034FDC
    // 0x80047128: lh          $a1, 0x94($s7)
    ctx->r5 = MEM_H(ctx->r23, 0X94);
    func_80034FDC(rdram, ctx);
        goto after_39;
    // 0x80047128: lh          $a1, 0x94($s7)
    ctx->r5 = MEM_H(ctx->r23, 0X94);
    after_39:
    // 0x8004712C: lw          $t6, 0x90($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X90);
    // 0x80047130: lw          $t0, 0x8C($s7)
    ctx->r8 = MEM_W(ctx->r23, 0X8C);
    // 0x80047134: addiu       $s4, $sp, 0x2AC
    ctx->r20 = ADD32(ctx->r29, 0X2AC);
    // 0x80047138: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x8004713C: sw          $t7, 0x90($s7)
    MEM_W(0X90, ctx->r23) = ctx->r15;
    // 0x80047140: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x80047144: sw          $t7, 0xD8($t1)
    MEM_W(0XD8, ctx->r9) = ctx->r15;
L_80047148:
    // 0x80047148: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x8004714C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80047150: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80047154: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // 0x80047158: sh          $zero, 0x0($t9)
    MEM_H(0X0, ctx->r25) = 0;
L_8004715C:
    // 0x8004715C: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x80047160: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x80047164: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80047168: bne         $v0, $v1, L_8004715C
    if (ctx->r2 != ctx->r3) {
        // 0x8004716C: sh          $zero, 0x2($t3)
        MEM_H(0X2, ctx->r11) = 0;
            goto L_8004715C;
    }
    // 0x8004716C: sh          $zero, 0x2($t3)
    MEM_H(0X2, ctx->r11) = 0;
    // 0x80047170: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x80047174: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80047178: addiu       $t5, $sp, 0x2C0
    ctx->r13 = ADD32(ctx->r29, 0X2C0);
    // 0x8004717C: sltu        $at, $s4, $t5
    ctx->r1 = ctx->r20 < ctx->r13 ? 1 : 0;
    // 0x80047180: bne         $at, $zero, L_80047148
    if (ctx->r1 != 0) {
        // 0x80047184: sh          $zero, 0x14($t4)
        MEM_H(0X14, ctx->r12) = 0;
            goto L_80047148;
    }
    // 0x80047184: sh          $zero, 0x14($t4)
    MEM_H(0X14, ctx->r12) = 0;
    // 0x80047188: lh          $v0, 0x2C($s7)
    ctx->r2 = MEM_H(ctx->r23, 0X2C);
    // 0x8004718C: beql        $v0, $zero, L_80047228
    if (ctx->r2 == 0) {
        // 0x80047190: lh          $t2, 0x41A($sp)
        ctx->r10 = MEM_H(ctx->r29, 0X41A);
            goto L_80047228;
    }
    goto skip_8;
    // 0x80047190: lh          $t2, 0x41A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X41A);
    skip_8:
    // 0x80047194: blez        $v0, L_80047224
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80047198: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80047224;
    }
    // 0x80047198: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8004719C: addiu       $s4, $sp, 0x2AC
    ctx->r20 = ADD32(ctx->r29, 0X2AC);
    // 0x800471A0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800471A4: lw          $t6, 0x28($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X28);
L_800471A8:
    // 0x800471A8: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x800471AC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800471B0: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x800471B4: lh          $t0, 0x0($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X0);
    // 0x800471B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800471BC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800471C0: sh          $t0, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r8;
L_800471C4:
    // 0x800471C4: lw          $t1, 0x28($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X28);
    // 0x800471C8: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x800471CC: subu        $t9, $t9, $s0
    ctx->r25 = SUB32(ctx->r25, ctx->r16);
    // 0x800471D0: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x800471D4: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800471D8: addu        $t2, $t1, $t9
    ctx->r10 = ADD32(ctx->r9, ctx->r25);
    // 0x800471DC: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x800471E0: lh          $t4, 0x2($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X2);
    // 0x800471E4: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800471E8: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800471EC: bne         $v0, $a0, L_800471C4
    if (ctx->r2 != ctx->r4) {
        // 0x800471F0: sh          $t4, 0x2($t6)
        MEM_H(0X2, ctx->r14) = ctx->r12;
            goto L_800471C4;
    }
    // 0x800471F0: sh          $t4, 0x2($t6)
    MEM_H(0X2, ctx->r14) = ctx->r12;
    // 0x800471F4: lw          $t7, 0x28($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X28);
    // 0x800471F8: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x800471FC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80047200: addu        $t0, $t7, $v1
    ctx->r8 = ADD32(ctx->r15, ctx->r3);
    // 0x80047204: lh          $t8, 0x14($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X14);
    // 0x80047208: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x8004720C: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80047210: sh          $t8, 0x14($t1)
    MEM_H(0X14, ctx->r9) = ctx->r24;
    // 0x80047214: lh          $t9, 0x2C($s7)
    ctx->r25 = MEM_H(ctx->r23, 0X2C);
    // 0x80047218: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8004721C: bnel        $at, $zero, L_800471A8
    if (ctx->r1 != 0) {
        // 0x80047220: lw          $t6, 0x28($s7)
        ctx->r14 = MEM_W(ctx->r23, 0X28);
            goto L_800471A8;
    }
    goto skip_9;
    // 0x80047220: lw          $t6, 0x28($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X28);
    skip_9:
L_80047224:
    // 0x80047224: lh          $t2, 0x41A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X41A);
L_80047228:
    // 0x80047228: sh          $zero, 0x2A8($sp)
    MEM_H(0X2A8, ctx->r29) = 0;
    // 0x8004722C: sh          $t2, 0x418($sp)
    MEM_H(0X418, ctx->r29) = ctx->r10;
    // 0x80047230: addiu       $s1, $sp, 0x2C0
    ctx->r17 = ADD32(ctx->r29, 0X2C0);
L_80047234:
    // 0x80047234: addiu       $v0, $sp, 0x374
    ctx->r2 = ADD32(ctx->r29, 0X374);
L_80047238:
    // 0x80047238: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x8004723C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80047240: sltu        $at, $s1, $v0
    ctx->r1 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x80047244: bne         $at, $zero, L_80047238
    if (ctx->r1 != 0) {
        // 0x80047248: sh          $zero, 0x28($t3)
        MEM_H(0X28, ctx->r11) = 0;
            goto L_80047238;
    }
    // 0x80047248: sh          $zero, 0x28($t3)
    MEM_H(0X28, ctx->r11) = 0;
    // 0x8004724C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80047250: addiu       $s4, $sp, 0x2AC
    ctx->r20 = ADD32(ctx->r29, 0X2AC);
    // 0x80047254: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
L_80047258:
    // 0x80047258: lh          $t5, 0x14($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X14);
    // 0x8004725C: bnel        $t5, $zero, L_80047270
    if (ctx->r13 != 0) {
        // 0x80047260: lh          $t4, 0x2($v0)
        ctx->r12 = MEM_H(ctx->r2, 0X2);
            goto L_80047270;
    }
    goto skip_10;
    // 0x80047260: lh          $t4, 0x2($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X2);
    skip_10:
    // 0x80047264: b           L_80047548
    // 0x80047268: nop

        goto L_80047548;
    // 0x80047268: nop

    // 0x8004726C: lh          $t4, 0x2($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X2);
L_80047270:
    // 0x80047270: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x80047274: lh          $t7, 0x6($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X6);
    // 0x80047278: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8004727C: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80047280: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80047284: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80047288: sll         $t0, $s3, 2
    ctx->r8 = S32(ctx->r19 << 2);
    // 0x8004728C: addiu       $t8, $sp, 0x2C0
    ctx->r24 = ADD32(ctx->r29, 0X2C0);
    // 0x80047290: addu        $s0, $t0, $t8
    ctx->r16 = ADD32(ctx->r8, ctx->r24);
    // 0x80047294: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80047298: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8004729C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800472A0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800472A4: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800472A8: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800472AC: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x800472B0: jal         0x80001A6C
    // 0x800472B4: nop

    func_80001A6C(rdram, ctx);
        goto after_40;
    // 0x800472B4: nop

    after_40:
    // 0x800472B8: lw          $a1, 0x14($s7)
    ctx->r5 = MEM_W(ctx->r23, 0X14);
    // 0x800472BC: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x800472C0: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x800472C4: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x800472C8: jal         0x80049840
    // 0x800472CC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_80049840(rdram, ctx);
        goto after_41;
    // 0x800472CC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_41:
    // 0x800472D0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800472D4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800472D8: jal         0x80000BD8
    // 0x800472DC: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_80000BD8(rdram, ctx);
        goto after_42;
    // 0x800472DC: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_42:
    // 0x800472E0: lw          $a1, 0x18($s7)
    ctx->r5 = MEM_W(ctx->r23, 0X18);
    // 0x800472E4: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x800472E8: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x800472EC: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x800472F0: jal         0x80049840
    // 0x800472F4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_80049840(rdram, ctx);
        goto after_43;
    // 0x800472F4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_43:
    // 0x800472F8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800472FC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80047300: jal         0x80000BD8
    // 0x80047304: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_80000BD8(rdram, ctx);
        goto after_44;
    // 0x80047304: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_44:
    // 0x80047308: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8004730C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80047310: addiu       $v1, $sp, 0x3D8
    ctx->r3 = ADD32(ctx->r29, 0X3D8);
    // 0x80047314: addiu       $a0, $sp, 0x3E4
    ctx->r4 = ADD32(ctx->r29, 0X3E4);
    // 0x80047318: sh          $fp, 0x28($t1)
    MEM_H(0X28, ctx->r9) = ctx->r30;
L_8004731C:
    // 0x8004731C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80047320: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x80047324: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80047328: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x8004732C: addu        $t2, $t9, $v0
    ctx->r10 = ADD32(ctx->r25, ctx->r2);
    // 0x80047330: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80047334: bne         $at, $zero, L_8004731C
    if (ctx->r1 != 0) {
        // 0x80047338: swc1        $f4, 0x8($t2)
        MEM_W(0X8, ctx->r10) = ctx->f4.u32l;
            goto L_8004731C;
    }
    // 0x80047338: swc1        $f4, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f4.u32l;
    // 0x8004733C: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x80047340: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80047344: addiu       $t5, $sp, 0x2C0
    ctx->r13 = ADD32(ctx->r29, 0X2C0);
    // 0x80047348: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8004734C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80047350: addu        $s1, $t3, $t5
    ctx->r17 = ADD32(ctx->r11, ctx->r13);
    // 0x80047354: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80047358: mov.s       $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    ctx->f22.fl = ctx->f24.fl;
L_8004735C:
    // 0x8004735C: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x80047360: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80047364: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80047368: lh          $t6, 0x14($t4)
    ctx->r14 = MEM_H(ctx->r12, 0X14);
    // 0x8004736C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80047370: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80047374: nop

    // 0x80047378: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8004737C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80047380: jal         0x80001A6C
    // 0x80047384: nop

    func_80001A6C(rdram, ctx);
        goto after_45;
    // 0x80047384: nop

    after_45:
    // 0x80047388: add.s       $f20, $f30, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f30.fl + ctx->f22.fl;
    // 0x8004738C: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x80047390: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80047394: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80047398: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8004739C: jal         0x80049840
    // 0x800473A0: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    func_80049840(rdram, ctx);
        goto after_46;
    // 0x800473A0: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_46:
    // 0x800473A4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800473A8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800473AC: jal         0x80000BD8
    // 0x800473B0: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_80000BD8(rdram, ctx);
        goto after_47;
    // 0x800473B0: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_47:
    // 0x800473B4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800473B8: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x800473BC: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x800473C0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800473C4: jal         0x80049840
    // 0x800473C8: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    func_80049840(rdram, ctx);
        goto after_48;
    // 0x800473C8: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_48:
    // 0x800473CC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800473D0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800473D4: jal         0x80000BD8
    // 0x800473D8: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_80000BD8(rdram, ctx);
        goto after_49;
    // 0x800473D8: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_49:
    // 0x800473DC: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800473E0: lwc1        $f8, 0x408($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X408);
    // 0x800473E4: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x800473E8: lwc1        $f10, 0x8($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X8);
    // 0x800473EC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800473F0: slti        $at, $s2, 0x4
    ctx->r1 = SIGNED(ctx->r18) < 0X4 ? 1 : 0;
    // 0x800473F4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800473F8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800473FC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80047400: cvt.d.s     $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f10.d = CVT_D_S(ctx->f22.fl);
    // 0x80047404: swc1        $f16, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f16.u32l;
    // 0x80047408: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8004740C: lw          $t1, -0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, -0X4);
    // 0x80047410: add.d       $f16, $f10, $f28
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f28.d); 
    ctx->f16.d = ctx->f10.d + ctx->f28.d;
    // 0x80047414: lwc1        $f18, 0xC($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0XC);
    // 0x80047418: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x8004741C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80047420: lwc1        $f4, 0x410($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X410);
    // 0x80047424: lw          $t2, -0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, -0X4);
    // 0x80047428: lwc1        $f6, 0x10($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X10);
    // 0x8004742C: cvt.s.d     $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f22.fl = CVT_S_D(ctx->f16.d);
    // 0x80047430: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80047434: swc1        $f8, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->f8.u32l;
    // 0x80047438: lw          $t3, -0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, -0X4);
    // 0x8004743C: bne         $at, $zero, L_8004735C
    if (ctx->r1 != 0) {
        // 0x80047440: sh          $fp, 0x28($t3)
        MEM_H(0X28, ctx->r11) = ctx->r30;
            goto L_8004735C;
    }
    // 0x80047440: sh          $fp, 0x28($t3)
    MEM_H(0X28, ctx->r11) = ctx->r30;
    // 0x80047444: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80047448: mov.s       $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    ctx->f22.fl = ctx->f24.fl;
L_8004744C:
    // 0x8004744C: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x80047450: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x80047454: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80047458: lh          $t4, 0x14($t5)
    ctx->r12 = MEM_H(ctx->r13, 0X14);
    // 0x8004745C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80047460: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80047464: nop

    // 0x80047468: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8004746C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80047470: jal         0x80001A6C
    // 0x80047474: nop

    func_80001A6C(rdram, ctx);
        goto after_50;
    // 0x80047474: nop

    after_50:
    // 0x80047478: add.s       $f20, $f30, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f30.fl + ctx->f22.fl;
    // 0x8004747C: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x80047480: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80047484: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80047488: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8004748C: jal         0x80049840
    // 0x80047490: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    func_80049840(rdram, ctx);
        goto after_51;
    // 0x80047490: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_51:
    // 0x80047494: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80047498: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8004749C: jal         0x80000BD8
    // 0x800474A0: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_80000BD8(rdram, ctx);
        goto after_52;
    // 0x800474A0: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_52:
    // 0x800474A4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800474A8: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x800474AC: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x800474B0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800474B4: jal         0x80049840
    // 0x800474B8: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    func_80049840(rdram, ctx);
        goto after_53;
    // 0x800474B8: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_53:
    // 0x800474BC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800474C0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800474C4: jal         0x80000BD8
    // 0x800474C8: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_80000BD8(rdram, ctx);
        goto after_54;
    // 0x800474C8: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_54:
    // 0x800474CC: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800474D0: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800474D4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800474D8: lwc1        $f4, 0x8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X8);
    // 0x800474DC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800474E0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800474E4: swc1        $f4, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f4.u32l;
    // 0x800474E8: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x800474EC: lwc1        $f6, 0x40C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40C);
    // 0x800474F0: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800474F4: lwc1        $f8, 0xC($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XC);
    // 0x800474F8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800474FC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80047500: cvt.d.s     $f6, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f6.d = CVT_D_S(ctx->f22.fl);
    // 0x80047504: swc1        $f10, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f10.u32l;
    // 0x80047508: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x8004750C: lwc1        $f16, 0x410($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X410);
    // 0x80047510: lw          $t9, -0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, -0X4);
    // 0x80047514: lwc1        $f18, 0x10($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X10);
    // 0x80047518: add.d       $f8, $f6, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f28.d); 
    ctx->f8.d = ctx->f6.d + ctx->f28.d;
    // 0x8004751C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80047520: cvt.s.d     $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f22.fl = CVT_S_D(ctx->f8.d);
    // 0x80047524: swc1        $f4, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f4.u32l;
    // 0x80047528: lw          $t2, -0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, -0X4);
    // 0x8004752C: bne         $s2, $at, L_8004744C
    if (ctx->r18 != ctx->r1) {
        // 0x80047530: sh          $fp, 0x28($t2)
        MEM_H(0X28, ctx->r10) = ctx->r30;
            goto L_8004744C;
    }
    // 0x80047530: sh          $fp, 0x28($t2)
    MEM_H(0X28, ctx->r10) = ctx->r30;
    // 0x80047534: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80047538: addiu       $t3, $sp, 0x2C0
    ctx->r11 = ADD32(ctx->r29, 0X2C0);
    // 0x8004753C: sltu        $at, $s4, $t3
    ctx->r1 = ctx->r20 < ctx->r11 ? 1 : 0;
    // 0x80047540: bnel        $at, $zero, L_80047258
    if (ctx->r1 != 0) {
        // 0x80047544: lw          $v0, 0x0($s4)
        ctx->r2 = MEM_W(ctx->r20, 0X0);
            goto L_80047258;
    }
    goto skip_11;
    // 0x80047544: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    skip_11:
L_80047548:
    // 0x80047548: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8004754C: ldc1        $f2, 0x7F10($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, 0X7F10);
    // 0x80047550: cvt.d.s     $f10, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); 
    ctx->f10.d = CVT_D_S(ctx->f30.fl);
    // 0x80047554: addiu       $s1, $sp, 0x2C0
    ctx->r17 = ADD32(ctx->r29, 0X2C0);
    // 0x80047558: add.d       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = ctx->f10.d + ctx->f2.d;
    // 0x8004755C: cvt.s.d     $f30, $f16
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f30.fl = CVT_S_D(ctx->f16.d);
    // 0x80047560: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
L_80047564:
    // 0x80047564: lh          $t5, 0x28($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X28);
    // 0x80047568: beql        $t5, $zero, L_800475F4
    if (ctx->r13 == 0) {
        // 0x8004756C: lw          $t5, 0x4($v1)
        ctx->r13 = MEM_W(ctx->r3, 0X4);
            goto L_800475F4;
    }
    goto skip_12;
    // 0x8004756C: lw          $t5, 0x4($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X4);
    skip_12:
    // 0x80047570: lwc1        $f0, 0x24($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X24);
    // 0x80047574: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80047578: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8004757C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80047580: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80047584: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80047588: jal         0x80001AB4
    // 0x8004758C: nop

    func_80001AB4(rdram, ctx);
        goto after_55;
    // 0x8004758C: nop

    after_55:
    // 0x80047590: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80047594: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80047598: lw          $t6, 0x4($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X4);
    // 0x8004759C: lw          $a0, 0x8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X8);
    // 0x800475A0: jal         0x80002340
    // 0x800475A4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80002340(rdram, ctx);
        goto after_56;
    // 0x800475A4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_56:
    // 0x800475A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800475AC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
L_800475B0:
    // 0x800475B0: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800475B4: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x800475B8: addu        $t7, $v1, $v0
    ctx->r15 = ADD32(ctx->r3, ctx->r2);
    // 0x800475BC: lwc1        $f18, 0x8($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X8);
    // 0x800475C0: lw          $t8, 0x8($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X8);
    // 0x800475C4: addu        $t1, $t8, $v0
    ctx->r9 = ADD32(ctx->r24, ctx->r2);
    // 0x800475C8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800475CC: bne         $v0, $a0, L_800475B0
    if (ctx->r2 != ctx->r4) {
        // 0x800475D0: swc1        $f18, 0x40($t1)
        MEM_W(0X40, ctx->r9) = ctx->f18.u32l;
            goto L_800475B0;
    }
    // 0x800475D0: swc1        $f18, 0x40($t1)
    MEM_W(0X40, ctx->r9) = ctx->f18.u32l;
    // 0x800475D4: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800475D8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800475DC: lw          $t2, 0x4($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X4);
    // 0x800475E0: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x800475E4: sw          $fp, 0xD8($t3)
    MEM_W(0XD8, ctx->r11) = ctx->r30;
    // 0x800475E8: b           L_800475FC
    // 0x800475EC: ldc1        $f2, 0x7F18($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, 0X7F18);
        goto L_800475FC;
    // 0x800475EC: ldc1        $f2, 0x7F18($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, 0X7F18);
    // 0x800475F0: lw          $t5, 0x4($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X4);
L_800475F4:
    // 0x800475F4: lw          $t4, 0x8($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X8);
    // 0x800475F8: sw          $zero, 0xD8($t4)
    MEM_W(0XD8, ctx->r12) = 0;
L_800475FC:
    // 0x800475FC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80047600: addiu       $t6, $sp, 0x374
    ctx->r14 = ADD32(ctx->r29, 0X374);
    // 0x80047604: sltu        $at, $s1, $t6
    ctx->r1 = ctx->r17 < ctx->r14 ? 1 : 0;
    // 0x80047608: bnel        $at, $zero, L_80047564
    if (ctx->r1 != 0) {
        // 0x8004760C: lw          $v1, 0x0($s1)
        ctx->r3 = MEM_W(ctx->r17, 0X0);
            goto L_80047564;
    }
    goto skip_13;
    // 0x8004760C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    skip_13:
    // 0x80047610: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80047614: lhu         $t7, -0x2E5C($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X2E5C);
    // 0x80047618: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x8004761C: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80047620: andi        $t0, $t7, 0x20
    ctx->r8 = ctx->r15 & 0X20;
    // 0x80047624: bne         $t0, $zero, L_800476C4
    if (ctx->r8 != 0) {
        // 0x80047628: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800476C4;
    }
    // 0x80047628: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8004762C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80047630: lh          $v0, -0x2E60($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2E60);
    // 0x80047634: slti        $at, $v0, 0x1A
    ctx->r1 = SIGNED(ctx->r2) < 0X1A ? 1 : 0;
    // 0x80047638: bnel        $at, $zero, L_8004765C
    if (ctx->r1 != 0) {
        // 0x8004763C: slti        $at, $v0, -0x19
        ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
            goto L_8004765C;
    }
    goto skip_14;
    // 0x8004763C: slti        $at, $v0, -0x19
    ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
    skip_14:
    // 0x80047640: lwc1        $f4, 0x18($s7)
    ctx->f4.u32l = MEM_W(ctx->r23, 0X18);
    // 0x80047644: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80047648: add.d       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f6.d + ctx->f2.d;
    // 0x8004764C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80047650: b           L_80047678
    // 0x80047654: swc1        $f10, 0x18($s7)
    MEM_W(0X18, ctx->r23) = ctx->f10.u32l;
        goto L_80047678;
    // 0x80047654: swc1        $f10, 0x18($s7)
    MEM_W(0X18, ctx->r23) = ctx->f10.u32l;
    // 0x80047658: slti        $at, $v0, -0x19
    ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
L_8004765C:
    // 0x8004765C: beq         $at, $zero, L_80047678
    if (ctx->r1 == 0) {
        // 0x80047660: nop
    
            goto L_80047678;
    }
    // 0x80047660: nop

    // 0x80047664: lwc1        $f16, 0x18($s7)
    ctx->f16.u32l = MEM_W(ctx->r23, 0X18);
    // 0x80047668: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8004766C: sub.d       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f18.d - ctx->f2.d;
    // 0x80047670: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80047674: swc1        $f6, 0x18($s7)
    MEM_W(0X18, ctx->r23) = ctx->f6.u32l;
L_80047678:
    // 0x80047678: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8004767C: lh          $v0, -0x2E5E($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2E5E);
    // 0x80047680: slti        $at, $v0, 0x1A
    ctx->r1 = SIGNED(ctx->r2) < 0X1A ? 1 : 0;
    // 0x80047684: bnel        $at, $zero, L_800476A8
    if (ctx->r1 != 0) {
        // 0x80047688: slti        $at, $v0, -0x19
        ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
            goto L_800476A8;
    }
    goto skip_15;
    // 0x80047688: slti        $at, $v0, -0x19
    ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
    skip_15:
    // 0x8004768C: lwc1        $f8, 0x14($s7)
    ctx->f8.u32l = MEM_W(ctx->r23, 0X14);
    // 0x80047690: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80047694: sub.d       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = ctx->f10.d - ctx->f2.d;
    // 0x80047698: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8004769C: b           L_800476C4
    // 0x800476A0: swc1        $f18, 0x14($s7)
    MEM_W(0X14, ctx->r23) = ctx->f18.u32l;
        goto L_800476C4;
    // 0x800476A0: swc1        $f18, 0x14($s7)
    MEM_W(0X14, ctx->r23) = ctx->f18.u32l;
    // 0x800476A4: slti        $at, $v0, -0x19
    ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
L_800476A8:
    // 0x800476A8: beql        $at, $zero, L_800476C8
    if (ctx->r1 == 0) {
        // 0x800476AC: lw          $a1, 0x14($s7)
        ctx->r5 = MEM_W(ctx->r23, 0X14);
            goto L_800476C8;
    }
    goto skip_16;
    // 0x800476AC: lw          $a1, 0x14($s7)
    ctx->r5 = MEM_W(ctx->r23, 0X14);
    skip_16:
    // 0x800476B0: lwc1        $f4, 0x14($s7)
    ctx->f4.u32l = MEM_W(ctx->r23, 0X14);
    // 0x800476B4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800476B8: add.d       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f6.d + ctx->f2.d;
    // 0x800476BC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x800476C0: swc1        $f10, 0x14($s7)
    MEM_W(0X14, ctx->r23) = ctx->f10.u32l;
L_800476C4:
    // 0x800476C4: lw          $a1, 0x14($s7)
    ctx->r5 = MEM_W(ctx->r23, 0X14);
L_800476C8:
    // 0x800476C8: jal         0x80049840
    // 0x800476CC: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    func_80049840(rdram, ctx);
        goto after_57;
    // 0x800476CC: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_57:
    // 0x800476D0: lw          $a1, 0x18($s7)
    ctx->r5 = MEM_W(ctx->r23, 0X18);
    // 0x800476D4: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x800476D8: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x800476DC: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x800476E0: jal         0x80049840
    // 0x800476E4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_80049840(rdram, ctx);
        goto after_58;
    // 0x800476E4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_58:
    // 0x800476E8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800476EC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800476F0: jal         0x80000BD8
    // 0x800476F4: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_80000BD8(rdram, ctx);
        goto after_59;
    // 0x800476F4: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_59:
    // 0x800476F8: lwc1        $f0, 0x24($s7)
    ctx->f0.u32l = MEM_W(ctx->r23, 0X24);
    // 0x800476FC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80047700: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80047704: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80047708: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8004770C: jal         0x80001AB4
    // 0x80047710: nop

    func_80001AB4(rdram, ctx);
        goto after_60;
    // 0x80047710: nop

    after_60:
    // 0x80047714: lw          $t8, 0x8C($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X8C);
    // 0x80047718: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8004771C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80047720: lw          $a0, 0x8($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X8);
    // 0x80047724: jal         0x80000BD8
    // 0x80047728: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80000BD8(rdram, ctx);
        goto after_61;
    // 0x80047728: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_61:
    // 0x8004772C: sll         $a2, $fp, 16
    ctx->r6 = S32(ctx->r30 << 16);
    // 0x80047730: sra         $t1, $a2, 16
    ctx->r9 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80047734: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x80047738: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8004773C: jal         0x8004C388
    // 0x80047740: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    func_8004C388(rdram, ctx);
        goto after_62;
    // 0x80047740: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_62:
    // 0x80047744: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80047748: lh          $t9, 0x2A8($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X2A8);
L_8004774C:
    // 0x8004774C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80047750: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x80047754: bne         $t9, $s0, L_80047778
    if (ctx->r25 != ctx->r16) {
        // 0x80047758: addiu       $t6, $sp, 0x2AC
        ctx->r14 = ADD32(ctx->r29, 0X2AC);
            goto L_80047778;
    }
    // 0x80047758: addiu       $t6, $sp, 0x2AC
    ctx->r14 = ADD32(ctx->r29, 0X2AC);
    // 0x8004775C: sll         $a1, $fp, 16
    ctx->r5 = S32(ctx->r30 << 16);
    // 0x80047760: sra         $t2, $a1, 16
    ctx->r10 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80047764: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x80047768: addiu       $t5, $sp, 0x2AC
    ctx->r13 = ADD32(ctx->r29, 0X2AC);
    // 0x8004776C: addu        $s4, $t3, $t5
    ctx->r20 = ADD32(ctx->r11, ctx->r13);
    // 0x80047770: b           L_8004777C
    // 0x80047774: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
        goto L_8004777C;
    // 0x80047774: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
L_80047778:
    // 0x80047778: addu        $s4, $t4, $t6
    ctx->r20 = ADD32(ctx->r12, ctx->r14);
L_8004777C:
    // 0x8004777C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80047780: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80047784: addiu       $a2, $a2, 0x7BE8
    ctx->r6 = ADD32(ctx->r6, 0X7BE8);
    // 0x80047788: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x8004778C: lh          $a3, 0x0($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X0);
    // 0x80047790: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80047794: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80047798: lh          $t0, 0x4($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X4);
    // 0x8004779C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800477A0: lh          $t8, 0x6($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X6);
    // 0x800477A4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800477A8: lh          $t1, 0x14($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X14);
    // 0x800477AC: jal         0x8004C340
    // 0x800477B0: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    func_8004C340(rdram, ctx);
        goto after_63;
    // 0x800477B0: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    after_63:
    // 0x800477B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800477B8: slti        $at, $s0, 0x5
    ctx->r1 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
    // 0x800477BC: bnel        $at, $zero, L_8004774C
    if (ctx->r1 != 0) {
        // 0x800477C0: lh          $t9, 0x2A8($sp)
        ctx->r25 = MEM_H(ctx->r29, 0X2A8);
            goto L_8004774C;
    }
    goto skip_17;
    // 0x800477C0: lh          $t9, 0x2A8($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X2A8);
    skip_17:
    // 0x800477C4: sll         $a2, $fp, 16
    ctx->r6 = S32(ctx->r30 << 16);
    // 0x800477C8: sra         $t9, $a2, 16
    ctx->r25 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800477CC: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800477D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800477D4: jal         0x8004C388
    // 0x800477D8: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    func_8004C388(rdram, ctx);
        goto after_64;
    // 0x800477D8: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    after_64:
    // 0x800477DC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800477E0: addiu       $v0, $sp, 0x384
    ctx->r2 = ADD32(ctx->r29, 0X384);
    // 0x800477E4: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
L_800477E8:
    // 0x800477E8: lw          $t2, 0x88($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X88);
    // 0x800477EC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800477F0: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x800477F4: lbu         $t5, 0x10($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X10);
    // 0x800477F8: sb          $t5, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = ctx->r13;
    // 0x800477FC: lw          $t4, 0x88($s7)
    ctx->r12 = MEM_W(ctx->r23, 0X88);
    // 0x80047800: addu        $t6, $t4, $s0
    ctx->r14 = ADD32(ctx->r12, ctx->r16);
    // 0x80047804: lbu         $t7, 0x11($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X11);
    // 0x80047808: sb          $t7, -0x3($v0)
    MEM_B(-0X3, ctx->r2) = ctx->r15;
    // 0x8004780C: lw          $t0, 0x88($s7)
    ctx->r8 = MEM_W(ctx->r23, 0X88);
    // 0x80047810: addu        $t8, $t0, $s0
    ctx->r24 = ADD32(ctx->r8, ctx->r16);
    // 0x80047814: lbu         $t1, 0x12($t8)
    ctx->r9 = MEM_BU(ctx->r24, 0X12);
    // 0x80047818: sb          $t1, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = ctx->r9;
    // 0x8004781C: lw          $t9, 0x88($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X88);
    // 0x80047820: addu        $t2, $t9, $s0
    ctx->r10 = ADD32(ctx->r25, ctx->r16);
    // 0x80047824: lbu         $t3, 0x13($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X13);
    // 0x80047828: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8004782C: bne         $s0, $v1, L_800477E8
    if (ctx->r16 != ctx->r3) {
        // 0x80047830: sb          $t3, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = ctx->r11;
            goto L_800477E8;
    }
    // 0x80047830: sb          $t3, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r11;
    // 0x80047834: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80047838: sb          $zero, 0x38C($sp)
    MEM_B(0X38C, ctx->r29) = 0;
    // 0x8004783C: addiu       $a2, $a2, 0x7C04
    ctx->r6 = ADD32(ctx->r6, 0X7C04);
    // 0x80047840: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80047844: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80047848: jal         0x8004C340
    // 0x8004784C: addiu       $a3, $sp, 0x384
    ctx->r7 = ADD32(ctx->r29, 0X384);
    func_8004C340(rdram, ctx);
        goto after_65;
    // 0x8004784C: addiu       $a3, $sp, 0x384
    ctx->r7 = ADD32(ctx->r29, 0X384);
    after_65:
    // 0x80047850: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80047854: lhu         $v1, -0x2E5C($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2E5C);
    // 0x80047858: andi        $t5, $v1, 0x8
    ctx->r13 = ctx->r3 & 0X8;
    // 0x8004785C: beq         $t5, $zero, L_80047878
    if (ctx->r13 == 0) {
        // 0x80047860: andi        $t4, $v1, 0x4
        ctx->r12 = ctx->r3 & 0X4;
            goto L_80047878;
    }
    // 0x80047860: andi        $t4, $v1, 0x4
    ctx->r12 = ctx->r3 & 0X4;
    // 0x80047864: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80047868: addiu       $v0, $v0, -0x6C50
    ctx->r2 = ADD32(ctx->r2, -0X6C50);
    // 0x8004786C: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80047870: sub.s       $f18, $f16, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f26.fl;
    // 0x80047874: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
L_80047878:
    // 0x80047878: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004787C: beq         $t4, $zero, L_80047890
    if (ctx->r12 == 0) {
        // 0x80047880: addiu       $v0, $v0, -0x6C50
        ctx->r2 = ADD32(ctx->r2, -0X6C50);
            goto L_80047890;
    }
    // 0x80047880: addiu       $v0, $v0, -0x6C50
    ctx->r2 = ADD32(ctx->r2, -0X6C50);
    // 0x80047884: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80047888: add.s       $f6, $f4, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f26.fl;
    // 0x8004788C: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
L_80047890:
    // 0x80047890: andi        $t6, $v1, 0x2
    ctx->r14 = ctx->r3 & 0X2;
    // 0x80047894: beq         $t6, $zero, L_800478B0
    if (ctx->r14 == 0) {
        // 0x80047898: andi        $t7, $v1, 0x1
        ctx->r15 = ctx->r3 & 0X1;
            goto L_800478B0;
    }
    // 0x80047898: andi        $t7, $v1, 0x1
    ctx->r15 = ctx->r3 & 0X1;
    // 0x8004789C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800478A0: addiu       $a0, $a0, -0x6C40
    ctx->r4 = ADD32(ctx->r4, -0X6C40);
    // 0x800478A4: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800478A8: sub.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f26.fl;
    // 0x800478AC: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
L_800478B0:
    // 0x800478B0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800478B4: beq         $t7, $zero, L_800478C8
    if (ctx->r15 == 0) {
        // 0x800478B8: addiu       $a0, $a0, -0x6C40
        ctx->r4 = ADD32(ctx->r4, -0X6C40);
            goto L_800478C8;
    }
    // 0x800478B8: addiu       $a0, $a0, -0x6C40
    ctx->r4 = ADD32(ctx->r4, -0X6C40);
    // 0x800478BC: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800478C0: add.s       $f18, $f16, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f26.fl;
    // 0x800478C4: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
L_800478C8:
    // 0x800478C8: jal         0x8000798C
    // 0x800478CC: nop

    func_8000798C(rdram, ctx);
        goto after_66;
    // 0x800478CC: nop

    after_66:
    // 0x800478D0: b           L_80046B94
    // 0x800478D4: nop

        goto L_80046B94;
    // 0x800478D4: nop

    // 0x800478D8: nop

    // 0x800478DC: nop

    // 0x800478E0: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x800478E4: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x800478E8: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x800478EC: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x800478F0: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x800478F4: ldc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X48);
    // 0x800478F8: ldc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X50);
    // 0x800478FC: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x80047900: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x80047904: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x80047908: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x8004790C: lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X68);
    // 0x80047910: lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X6C);
    // 0x80047914: lw          $s6, 0x70($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X70);
    // 0x80047918: lw          $s7, 0x74($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X74);
    // 0x8004791C: lw          $fp, 0x78($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X78);
    // 0x80047920: jr          $ra
    // 0x80047924: addiu       $sp, $sp, 0x430
    ctx->r29 = ADD32(ctx->r29, 0X430);
    TRACE_RETURN()
    return;
    // 0x80047924: addiu       $sp, $sp, 0x430
    ctx->r29 = ADD32(ctx->r29, 0X430);
;}
RECOMP_FUNC void func_80047928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80047928: addiu       $sp, $sp, -0x130
    ctx->r29 = ADD32(ctx->r29, -0X130);
    // 0x8004792C: sw          $a0, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r4;
    // 0x80047930: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80047934: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80047938: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8004793C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80047940: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80047944: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x80047948: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8004794C: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80047950: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80047954: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80047958: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8004795C: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80047960: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80047964: sw          $zero, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = 0;
    // 0x80047968: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8004796C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80047970: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
    // 0x80047974: sh          $zero, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = 0;
    // 0x80047978: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8004797C: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80047980: jal         0x80004364
    // 0x80047984: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x80047984: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_0:
    // 0x80047988: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8004798C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80047990: jal         0x8000C7C0
    // 0x80047994: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_8000C7C0(rdram, ctx);
        goto after_1;
    // 0x80047994: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_1:
    // 0x80047998: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8004799C: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x800479A0: addiu       $a0, $a0, -0x2E00
    ctx->r4 = ADD32(ctx->r4, -0X2E00);
    // 0x800479A4: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
    // 0x800479A8: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x800479AC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x800479B0: jal         0x80004CE0
    // 0x800479B4: addiu       $a3, $sp, 0x70
    ctx->r7 = ADD32(ctx->r29, 0X70);
    func_80004CE0(rdram, ctx);
        goto after_2;
    // 0x800479B4: addiu       $a3, $sp, 0x70
    ctx->r7 = ADD32(ctx->r29, 0X70);
    after_2:
    // 0x800479B8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800479BC: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x800479C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800479C4: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800479C8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
L_800479CC:
    // 0x800479CC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800479D0: swc1        $f20, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f20.u32l;
    // 0x800479D4: swc1        $f20, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f20.u32l;
    // 0x800479D8: bne         $a1, $a3, L_800479CC
    if (ctx->r5 != ctx->r7) {
        // 0x800479DC: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800479CC;
    }
    // 0x800479DC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800479E0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800479E4: lwc1        $f4, 0x7F20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7F20);
    // 0x800479E8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800479EC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800479F0: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    // 0x800479F4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800479F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800479FC: addiu       $v1, $v1, -0x6C40
    ctx->r3 = ADD32(ctx->r3, -0X6C40);
    // 0x80047A00: addiu       $v0, $v0, -0x6C50
    ctx->r2 = ADD32(ctx->r2, -0X6C50);
    // 0x80047A04: swc1        $f20, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f20.u32l;
    // 0x80047A08: swc1        $f20, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f20.u32l;
    // 0x80047A0C: swc1        $f20, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f20.u32l;
    // 0x80047A10: swc1        $f20, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f20.u32l;
    // 0x80047A14: swc1        $f20, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f20.u32l;
    // 0x80047A18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80047A1C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80047A20: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80047A24: jal         0x8004C388
    // 0x80047A28: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    func_8004C388(rdram, ctx);
        goto after_3;
    // 0x80047A28: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    after_3:
    // 0x80047A2C: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80047A30: addiu       $a2, $a2, 0x7C58
    ctx->r6 = ADD32(ctx->r6, 0X7C58);
    // 0x80047A34: addiu       $a0, $zero, -0xFE
    ctx->r4 = ADD32(0, -0XFE);
    // 0x80047A38: jal         0x8004BCF0
    // 0x80047A3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004BCF0(rdram, ctx);
        goto after_4;
    // 0x80047A3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80047A40: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x80047A44: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80047A48: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80047A4C: addiu       $a1, $a1, -0x5058
    ctx->r5 = ADD32(ctx->r5, -0X5058);
    // 0x80047A50: addiu       $a0, $sp, 0x120
    ctx->r4 = ADD32(ctx->r29, 0X120);
    // 0x80047A54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80047A58: jal         0x80049660
    // 0x80047A5C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_80049660(rdram, ctx);
        goto after_5;
    // 0x80047A5C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_5:
    // 0x80047A60: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80047A64: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80047A68: sw          $t9, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r25;
    // 0x80047A6C: jal         0x8000798C
    // 0x80047A70: sh          $t8, 0x114($sp)
    MEM_H(0X114, ctx->r29) = ctx->r24;
    func_8000798C(rdram, ctx);
        goto after_6;
    // 0x80047A70: sh          $t8, 0x114($sp)
    MEM_H(0X114, ctx->r29) = ctx->r24;
    after_6:
    // 0x80047A74: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80047A78: ldc1        $f22, 0x7F28($at)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r1, 0X7F28);
    // 0x80047A7C: lw          $fp, 0x110($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X110);
    // 0x80047A80: addiu       $s7, $sp, 0xC4
    ctx->r23 = ADD32(ctx->r29, 0XC4);
    // 0x80047A84: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x80047A88: addiu       $s5, $zero, 0x8
    ctx->r21 = ADD32(0, 0X8);
    // 0x80047A8C: addiu       $s4, $zero, 0xC
    ctx->r20 = ADD32(0, 0XC);
L_80047A90:
    // 0x80047A90: jal         0x800496B4
    // 0x80047A94: addiu       $a0, $sp, 0x120
    ctx->r4 = ADD32(ctx->r29, 0X120);
    func_800496B4(rdram, ctx);
        goto after_7;
    // 0x80047A94: addiu       $a0, $sp, 0x120
    ctx->r4 = ADD32(ctx->r29, 0X120);
    after_7:
    // 0x80047A98: lh          $t0, 0x12C($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X12C);
    // 0x80047A9C: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80047AA0: sltiu       $at, $t1, 0x9
    ctx->r1 = ctx->r9 < 0X9 ? 1 : 0;
    // 0x80047AA4: beq         $at, $zero, L_80047FB0
    if (ctx->r1 == 0) {
        // 0x80047AA8: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_80047FB0;
    }
    // 0x80047AA8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80047AAC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80047AB0: addu        $at, $at, $t1
    gpr jr_addend_80047AB8 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80047AB4: lw          $t1, 0x7F30($at)
    ctx->r9 = ADD32(ctx->r1, 0X7F30);
    // 0x80047AB8: jr          $t1
    // 0x80047ABC: nop

    switch (jr_addend_80047AB8 >> 2) {
        case 0: goto L_80047AC0; break;
        case 1: goto L_80047B3C; break;
        case 2: goto L_80047BC4; break;
        case 3: goto L_80047C98; break;
        case 4: goto L_80047D28; break;
        case 5: goto L_80047DE0; break;
        case 6: goto L_80047E8C; break;
        case 7: goto L_80047FB0; break;
        case 8: goto L_80047F04; break;
        default: switch_error(__func__, 0x80047AB8, 0x80077F30);
    }
    // 0x80047ABC: nop

L_80047AC0:
    // 0x80047AC0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80047AC4: lhu         $v0, -0x2E58($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2E58);
    // 0x80047AC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80047ACC: andi        $t2, $v0, 0x200
    ctx->r10 = ctx->r2 & 0X200;
    // 0x80047AD0: beq         $t2, $zero, L_80047AE0
    if (ctx->r10 == 0) {
        // 0x80047AD4: andi        $t3, $v0, 0x100
        ctx->r11 = ctx->r2 & 0X100;
            goto L_80047AE0;
    }
    // 0x80047AD4: andi        $t3, $v0, 0x100
    ctx->r11 = ctx->r2 & 0X100;
    // 0x80047AD8: b           L_80047AEC
    // 0x80047ADC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80047AEC;
    // 0x80047ADC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80047AE0:
    // 0x80047AE0: beq         $t3, $zero, L_80047AEC
    if (ctx->r11 == 0) {
        // 0x80047AE4: nop
    
            goto L_80047AEC;
    }
    // 0x80047AE4: nop

    // 0x80047AE8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_80047AEC:
    // 0x80047AEC: beql        $a1, $zero, L_80047B04
    if (ctx->r5 == 0) {
        // 0x80047AF0: lh          $a1, 0x12C($sp)
        ctx->r5 = MEM_H(ctx->r29, 0X12C);
            goto L_80047B04;
    }
    goto skip_0;
    // 0x80047AF0: lh          $a1, 0x12C($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X12C);
    skip_0:
    // 0x80047AF4: jal         0x80049CB0
    // 0x80047AF8: lw          $a0, 0x11C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X11C);
    func_80049CB0(rdram, ctx);
        goto after_8;
    // 0x80047AF8: lw          $a0, 0x11C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X11C);
    after_8:
    // 0x80047AFC: sw          $v0, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r2;
    // 0x80047B00: lh          $a1, 0x12C($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X12C);
L_80047B04:
    // 0x80047B04: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80047B08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80047B0C: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    // 0x80047B10: sll         $t4, $a1, 16
    ctx->r12 = S32(ctx->r5 << 16);
    // 0x80047B14: jal         0x8004C388
    // 0x80047B18: sra         $a1, $t4, 16
    ctx->r5 = S32(SIGNED(ctx->r12) >> 16);
    func_8004C388(rdram, ctx);
        goto after_9;
    // 0x80047B18: sra         $a1, $t4, 16
    ctx->r5 = S32(SIGNED(ctx->r12) >> 16);
    after_9:
    // 0x80047B1C: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80047B20: addiu       $a2, $a2, 0x7C64
    ctx->r6 = ADD32(ctx->r6, 0X7C64);
    // 0x80047B24: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80047B28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80047B2C: jal         0x8004C340
    // 0x80047B30: lw          $a3, 0x11C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X11C);
    func_8004C340(rdram, ctx);
        goto after_10;
    // 0x80047B30: lw          $a3, 0x11C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X11C);
    after_10:
    // 0x80047B34: b           L_80047FB4
    // 0x80047B38: lh          $t9, 0x12C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X12C);
        goto L_80047FB4;
    // 0x80047B38: lh          $t9, 0x12C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X12C);
L_80047B3C:
    // 0x80047B3C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80047B40: lhu         $v0, -0x2E58($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2E58);
    // 0x80047B44: lh          $a1, 0x12C($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X12C);
    // 0x80047B48: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80047B4C: andi        $t6, $v0, 0x200
    ctx->r14 = ctx->r2 & 0X200;
    // 0x80047B50: beq         $t6, $zero, L_80047B68
    if (ctx->r14 == 0) {
        // 0x80047B54: addiu       $a1, $a1, 0x3
        ctx->r5 = ADD32(ctx->r5, 0X3);
            goto L_80047B68;
    }
    // 0x80047B54: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    // 0x80047B58: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80047B5C: sll         $t7, $s3, 16
    ctx->r15 = S32(ctx->r19 << 16);
    // 0x80047B60: b           L_80047B80
    // 0x80047B64: sra         $s3, $t7, 16
    ctx->r19 = S32(SIGNED(ctx->r15) >> 16);
        goto L_80047B80;
    // 0x80047B64: sra         $s3, $t7, 16
    ctx->r19 = S32(SIGNED(ctx->r15) >> 16);
L_80047B68:
    // 0x80047B68: andi        $t9, $v0, 0x100
    ctx->r25 = ctx->r2 & 0X100;
    // 0x80047B6C: beq         $t9, $zero, L_80047B80
    if (ctx->r25 == 0) {
        // 0x80047B70: nop
    
            goto L_80047B80;
    }
    // 0x80047B70: nop

    // 0x80047B74: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x80047B78: sll         $t0, $s3, 16
    ctx->r8 = S32(ctx->r19 << 16);
    // 0x80047B7C: sra         $s3, $t0, 16
    ctx->r19 = S32(SIGNED(ctx->r8) >> 16);
L_80047B80:
    // 0x80047B80: bgez        $s3, L_80047B8C
    if (SIGNED(ctx->r19) >= 0) {
        // 0x80047B84: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_80047B8C;
    }
    // 0x80047B84: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80047B88: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80047B8C:
    // 0x80047B8C: slti        $at, $s3, 0x10
    ctx->r1 = SIGNED(ctx->r19) < 0X10 ? 1 : 0;
    // 0x80047B90: bne         $at, $zero, L_80047B9C
    if (ctx->r1 != 0) {
        // 0x80047B94: sll         $t2, $a1, 16
        ctx->r10 = S32(ctx->r5 << 16);
            goto L_80047B9C;
    }
    // 0x80047B94: sll         $t2, $a1, 16
    ctx->r10 = S32(ctx->r5 << 16);
    // 0x80047B98: addiu       $s3, $zero, 0xF
    ctx->r19 = ADD32(0, 0XF);
L_80047B9C:
    // 0x80047B9C: jal         0x8004C388
    // 0x80047BA0: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
    func_8004C388(rdram, ctx);
        goto after_11;
    // 0x80047BA0: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
    after_11:
    // 0x80047BA4: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80047BA8: addiu       $a2, $a2, 0x7C68
    ctx->r6 = ADD32(ctx->r6, 0X7C68);
    // 0x80047BAC: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80047BB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80047BB4: jal         0x8004C340
    // 0x80047BB8: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    func_8004C340(rdram, ctx);
        goto after_12;
    // 0x80047BB8: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_12:
    // 0x80047BBC: b           L_80047FB4
    // 0x80047BC0: lh          $t9, 0x12C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X12C);
        goto L_80047FB4;
    // 0x80047BC0: lh          $t9, 0x12C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X12C);
L_80047BC4:
    // 0x80047BC4: lw          $t4, 0x8($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X8);
    // 0x80047BC8: lw          $v0, 0xE0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0XE0);
    // 0x80047BCC: beql        $v0, $zero, L_80047FB4
    if (ctx->r2 == 0) {
        // 0x80047BD0: lh          $t9, 0x12C($sp)
        ctx->r25 = MEM_H(ctx->r29, 0X12C);
            goto L_80047FB4;
    }
    goto skip_1;
    // 0x80047BD0: lh          $t9, 0x12C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X12C);
    skip_1:
    // 0x80047BD4: lw          $t5, 0x18($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X18);
    // 0x80047BD8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80047BDC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80047BE0: beq         $t5, $zero, L_80047FB0
    if (ctx->r13 == 0) {
        // 0x80047BE4: lh          $a1, 0x12C($sp)
        ctx->r5 = MEM_H(ctx->r29, 0X12C);
            goto L_80047FB0;
    }
    // 0x80047BE4: lh          $a1, 0x12C($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X12C);
    // 0x80047BE8: lhu         $v0, -0x2E58($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2E58);
    // 0x80047BEC: sll         $v1, $s2, 16
    ctx->r3 = S32(ctx->r18 << 16);
    // 0x80047BF0: sra         $t6, $v1, 16
    ctx->r14 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80047BF4: andi        $t7, $v0, 0x200
    ctx->r15 = ctx->r2 & 0X200;
    // 0x80047BF8: beq         $t7, $zero, L_80047C10
    if (ctx->r15 == 0) {
        // 0x80047BFC: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_80047C10;
    }
    // 0x80047BFC: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x80047C00: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80047C04: sll         $t8, $s2, 16
    ctx->r24 = S32(ctx->r18 << 16);
    // 0x80047C08: b           L_80047C28
    // 0x80047C0C: sra         $s2, $t8, 16
    ctx->r18 = S32(SIGNED(ctx->r24) >> 16);
        goto L_80047C28;
    // 0x80047C0C: sra         $s2, $t8, 16
    ctx->r18 = S32(SIGNED(ctx->r24) >> 16);
L_80047C10:
    // 0x80047C10: andi        $t0, $v0, 0x100
    ctx->r8 = ctx->r2 & 0X100;
    // 0x80047C14: beq         $t0, $zero, L_80047C28
    if (ctx->r8 == 0) {
        // 0x80047C18: nop
    
            goto L_80047C28;
    }
    // 0x80047C18: nop

    // 0x80047C1C: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80047C20: sll         $t1, $s2, 16
    ctx->r9 = S32(ctx->r18 << 16);
    // 0x80047C24: sra         $s2, $t1, 16
    ctx->r18 = S32(SIGNED(ctx->r9) >> 16);
L_80047C28:
    // 0x80047C28: bgez        $s2, L_80047C34
    if (SIGNED(ctx->r18) >= 0) {
        // 0x80047C2C: addiu       $a1, $a1, 0x3
        ctx->r5 = ADD32(ctx->r5, 0X3);
            goto L_80047C34;
    }
    // 0x80047C2C: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    // 0x80047C30: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80047C34:
    // 0x80047C34: slti        $at, $s2, 0x8
    ctx->r1 = SIGNED(ctx->r18) < 0X8 ? 1 : 0;
    // 0x80047C38: bne         $at, $zero, L_80047C44
    if (ctx->r1 != 0) {
        // 0x80047C3C: sll         $t3, $a1, 16
        ctx->r11 = S32(ctx->r5 << 16);
            goto L_80047C44;
    }
    // 0x80047C3C: sll         $t3, $a1, 16
    ctx->r11 = S32(ctx->r5 << 16);
    // 0x80047C40: addiu       $s2, $zero, 0x7
    ctx->r18 = ADD32(0, 0X7);
L_80047C44:
    // 0x80047C44: sra         $a1, $t3, 16
    ctx->r5 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80047C48: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80047C4C: jal         0x8004C388
    // 0x80047C50: sh          $v1, 0x66($sp)
    MEM_H(0X66, ctx->r29) = ctx->r3;
    func_8004C388(rdram, ctx);
        goto after_13;
    // 0x80047C50: sh          $v1, 0x66($sp)
    MEM_H(0X66, ctx->r29) = ctx->r3;
    after_13:
    // 0x80047C54: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80047C58: addiu       $a2, $a2, 0x7C6C
    ctx->r6 = ADD32(ctx->r6, 0X7C6C);
    // 0x80047C5C: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80047C60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80047C64: jal         0x8004C340
    // 0x80047C68: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    func_8004C340(rdram, ctx);
        goto after_14;
    // 0x80047C68: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_14:
    // 0x80047C6C: lh          $v1, 0x66($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X66);
    // 0x80047C70: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x80047C74: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80047C78: beql        $s2, $v1, L_80047FB4
    if (ctx->r18 == ctx->r3) {
        // 0x80047C7C: lh          $t9, 0x12C($sp)
        ctx->r25 = MEM_H(ctx->r29, 0X12C);
            goto L_80047FB4;
    }
    goto skip_2;
    // 0x80047C7C: lh          $t9, 0x12C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X12C);
    skip_2:
    // 0x80047C80: lw          $t5, 0x8($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X8);
    // 0x80047C84: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80047C88: jal         0x8004D62C
    // 0x80047C8C: lw          $a0, 0xE0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0XE0);
    func_8004D62C(rdram, ctx);
        goto after_15;
    // 0x80047C8C: lw          $a0, 0xE0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0XE0);
    after_15:
    // 0x80047C90: b           L_80047FB4
    // 0x80047C94: lh          $t9, 0x12C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X12C);
        goto L_80047FB4;
    // 0x80047C94: lh          $t9, 0x12C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X12C);
L_80047C98:
    // 0x80047C98: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80047C9C: lhu         $t7, -0x2E5A($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X2E5A);
    // 0x80047CA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80047CA4: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80047CA8: andi        $t8, $t7, 0x300
    ctx->r24 = ctx->r15 & 0X300;
    // 0x80047CAC: beq         $t8, $zero, L_80047CC0
    if (ctx->r24 == 0) {
        // 0x80047CB0: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80047CC0;
    }
L_80047CB0:
    // 0x80047CB0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80047CB4: swc1        $f20, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f20.u32l;
    // 0x80047CB8: bne         $a1, $s6, L_80047CB0
    if (ctx->r5 != ctx->r22) {
        // 0x80047CBC: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80047CB0;
    }
    // 0x80047CBC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80047CC0:
    // 0x80047CC0: lh          $a1, 0x12C($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X12C);
    // 0x80047CC4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80047CC8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80047CCC: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    // 0x80047CD0: sll         $t9, $a1, 16
    ctx->r25 = S32(ctx->r5 << 16);
    // 0x80047CD4: jal         0x8004C388
    // 0x80047CD8: sra         $a1, $t9, 16
    ctx->r5 = S32(SIGNED(ctx->r25) >> 16);
    func_8004C388(rdram, ctx);
        goto after_16;
    // 0x80047CD8: sra         $a1, $t9, 16
    ctx->r5 = S32(SIGNED(ctx->r25) >> 16);
    after_16:
    // 0x80047CDC: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80047CE0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80047CE4: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80047CE8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80047CEC: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80047CF0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80047CF4: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80047CF8: addiu       $a2, $a2, 0x7C70
    ctx->r6 = ADD32(ctx->r6, 0X7C70);
    // 0x80047CFC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80047D00: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80047D04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80047D08: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80047D0C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80047D10: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80047D14: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x80047D18: jal         0x8004C340
    // 0x80047D1C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    func_8004C340(rdram, ctx);
        goto after_17;
    // 0x80047D1C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_17:
    // 0x80047D20: b           L_80047FB4
    // 0x80047D24: lh          $t9, 0x12C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X12C);
        goto L_80047FB4;
    // 0x80047D24: lh          $t9, 0x12C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X12C);
L_80047D28:
    // 0x80047D28: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80047D2C: lh          $v0, -0x2E60($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2E60);
    // 0x80047D30: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80047D34: slti        $at, $v0, 0x1A
    ctx->r1 = SIGNED(ctx->r2) < 0X1A ? 1 : 0;
    // 0x80047D38: bnel        $at, $zero, L_80047D5C
    if (ctx->r1 != 0) {
        // 0x80047D3C: slti        $at, $v0, -0x19
        ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
            goto L_80047D5C;
    }
    goto skip_3;
    // 0x80047D3C: slti        $at, $v0, -0x19
    ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
    skip_3:
    // 0x80047D40: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80047D44: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80047D48: sub.d       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f22.d); 
    ctx->f4.d = ctx->f18.d - ctx->f22.d;
    // 0x80047D4C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80047D50: b           L_80047D78
    // 0x80047D54: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
        goto L_80047D78;
    // 0x80047D54: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x80047D58: slti        $at, $v0, -0x19
    ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
L_80047D5C:
    // 0x80047D5C: beq         $at, $zero, L_80047D78
    if (ctx->r1 == 0) {
        // 0x80047D60: nop
    
            goto L_80047D78;
    }
    // 0x80047D60: nop

    // 0x80047D64: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80047D68: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80047D6C: add.d       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f22.d); 
    ctx->f16.d = ctx->f10.d + ctx->f22.d;
    // 0x80047D70: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80047D74: swc1        $f18, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f18.u32l;
L_80047D78:
    // 0x80047D78: lhu         $t4, -0x2E5A($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X2E5A);
    // 0x80047D7C: andi        $t5, $t4, 0x300
    ctx->r13 = ctx->r12 & 0X300;
    // 0x80047D80: beql        $t5, $zero, L_80047D90
    if (ctx->r13 == 0) {
        // 0x80047D84: lh          $a1, 0x12C($sp)
        ctx->r5 = MEM_H(ctx->r29, 0X12C);
            goto L_80047D90;
    }
    goto skip_4;
    // 0x80047D84: lh          $a1, 0x12C($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X12C);
    skip_4:
    // 0x80047D88: swc1        $f20, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f20.u32l;
    // 0x80047D8C: lh          $a1, 0x12C($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X12C);
L_80047D90:
    // 0x80047D90: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80047D94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80047D98: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    // 0x80047D9C: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80047DA0: jal         0x8004C388
    // 0x80047DA4: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    func_8004C388(rdram, ctx);
        goto after_18;
    // 0x80047DA4: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    after_18:
    // 0x80047DA8: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80047DAC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80047DB0: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80047DB4: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80047DB8: addiu       $a2, $a2, 0x7C80
    ctx->r6 = ADD32(ctx->r6, 0X7C80);
    // 0x80047DBC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80047DC0: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80047DC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80047DC8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80047DCC: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80047DD0: jal         0x8004C340
    // 0x80047DD4: nop

    func_8004C340(rdram, ctx);
        goto after_19;
    // 0x80047DD4: nop

    after_19:
    // 0x80047DD8: b           L_80047FB4
    // 0x80047DDC: lh          $t9, 0x12C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X12C);
        goto L_80047FB4;
    // 0x80047DDC: lh          $t9, 0x12C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X12C);
L_80047DE0:
    // 0x80047DE0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80047DE4: lhu         $v0, -0x2E58($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2E58);
    // 0x80047DE8: andi        $t9, $v0, 0x200
    ctx->r25 = ctx->r2 & 0X200;
    // 0x80047DEC: beq         $t9, $zero, L_80047E14
    if (ctx->r25 == 0) {
        // 0x80047DF0: andi        $t0, $v0, 0x100
        ctx->r8 = ctx->r2 & 0X100;
            goto L_80047E14;
    }
    // 0x80047DF0: andi        $t0, $v0, 0x100
    ctx->r8 = ctx->r2 & 0X100;
    // 0x80047DF4: lwc1        $f16, 0x1C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80047DF8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80047DFC: ldc1        $f4, 0x7F58($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X7F58);
    // 0x80047E00: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80047E04: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x80047E08: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80047E0C: b           L_80047E38
    // 0x80047E10: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
        goto L_80047E38;
    // 0x80047E10: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
L_80047E14:
    // 0x80047E14: beql        $t0, $zero, L_80047E3C
    if (ctx->r8 == 0) {
        // 0x80047E18: lh          $a1, 0x12C($sp)
        ctx->r5 = MEM_H(ctx->r29, 0X12C);
            goto L_80047E3C;
    }
    goto skip_5;
    // 0x80047E18: lh          $a1, 0x12C($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X12C);
    skip_5:
    // 0x80047E1C: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80047E20: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80047E24: ldc1        $f18, 0x7F60($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X7F60);
    // 0x80047E28: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80047E2C: sub.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d - ctx->f18.d;
    // 0x80047E30: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80047E34: swc1        $f6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f6.u32l;
L_80047E38:
    // 0x80047E38: lh          $a1, 0x12C($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X12C);
L_80047E3C:
    // 0x80047E3C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80047E40: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80047E44: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    // 0x80047E48: sll         $t1, $a1, 16
    ctx->r9 = S32(ctx->r5 << 16);
    // 0x80047E4C: jal         0x8004C388
    // 0x80047E50: sra         $a1, $t1, 16
    ctx->r5 = S32(SIGNED(ctx->r9) >> 16);
    func_8004C388(rdram, ctx);
        goto after_20;
    // 0x80047E50: sra         $a1, $t1, 16
    ctx->r5 = S32(SIGNED(ctx->r9) >> 16);
    after_20:
    // 0x80047E54: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80047E58: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80047E5C: lwc1        $f8, 0x1C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80047E60: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80047E64: addiu       $a2, $a2, 0x7C8C
    ctx->r6 = ADD32(ctx->r6, 0X7C8C);
    // 0x80047E68: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80047E6C: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80047E70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80047E74: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80047E78: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80047E7C: jal         0x8004C340
    // 0x80047E80: nop

    func_8004C340(rdram, ctx);
        goto after_21;
    // 0x80047E80: nop

    after_21:
    // 0x80047E84: b           L_80047FB4
    // 0x80047E88: lh          $t9, 0x12C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X12C);
        goto L_80047FB4;
    // 0x80047E88: lh          $t9, 0x12C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X12C);
L_80047E8C:
    // 0x80047E8C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80047E90: lhu         $t4, -0x2E58($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X2E58);
    // 0x80047E94: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x80047E98: andi        $t5, $t4, 0x300
    ctx->r13 = ctx->r12 & 0X300;
    // 0x80047E9C: beq         $t5, $zero, L_80047EA8
    if (ctx->r13 == 0) {
        // 0x80047EA0: xori        $t7, $t6, 0x1
        ctx->r15 = ctx->r14 ^ 0X1;
            goto L_80047EA8;
    }
    // 0x80047EA0: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x80047EA4: sw          $t7, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r15;
L_80047EA8:
    // 0x80047EA8: lh          $a1, 0x12C($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X12C);
    // 0x80047EAC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80047EB0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80047EB4: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    // 0x80047EB8: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x80047EBC: jal         0x8004C388
    // 0x80047EC0: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    func_8004C388(rdram, ctx);
        goto after_22;
    // 0x80047EC0: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    after_22:
    // 0x80047EC4: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x80047EC8: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80047ECC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80047ED0: beq         $t0, $zero, L_80047EF4
    if (ctx->r8 == 0) {
        // 0x80047ED4: lui         $a2, 0x8007
        ctx->r6 = S32(0X8007 << 16);
            goto L_80047EF4;
    }
    // 0x80047ED4: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80047ED8: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80047EDC: addiu       $a2, $a2, 0x7C98
    ctx->r6 = ADD32(ctx->r6, 0X7C98);
    // 0x80047EE0: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80047EE4: jal         0x8004BCF0
    // 0x80047EE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004BCF0(rdram, ctx);
        goto after_23;
    // 0x80047EE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_23:
    // 0x80047EEC: b           L_80047FB4
    // 0x80047EF0: lh          $t9, 0x12C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X12C);
        goto L_80047FB4;
    // 0x80047EF0: lh          $t9, 0x12C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X12C);
L_80047EF4:
    // 0x80047EF4: jal         0x8004BCF0
    // 0x80047EF8: addiu       $a2, $a2, 0x7CA4
    ctx->r6 = ADD32(ctx->r6, 0X7CA4);
    func_8004BCF0(rdram, ctx);
        goto after_24;
    // 0x80047EF8: addiu       $a2, $a2, 0x7CA4
    ctx->r6 = ADD32(ctx->r6, 0X7CA4);
    after_24:
    // 0x80047EFC: b           L_80047FB4
    // 0x80047F00: lh          $t9, 0x12C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X12C);
        goto L_80047FB4;
    // 0x80047F00: lh          $t9, 0x12C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X12C);
L_80047F04:
    // 0x80047F04: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80047F08: lhu         $t1, -0x2E5A($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X2E5A);
    // 0x80047F0C: andi        $t2, $t1, 0x1000
    ctx->r10 = ctx->r9 & 0X1000;
    // 0x80047F10: beql        $t2, $zero, L_80047FB4
    if (ctx->r10 == 0) {
        // 0x80047F14: lh          $t9, 0x12C($sp)
        ctx->r25 = MEM_H(ctx->r29, 0X12C);
            goto L_80047FB4;
    }
    goto skip_6;
    // 0x80047F14: lh          $t9, 0x12C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X12C);
    skip_6:
    // 0x80047F18: jal         0x8004A0C4
    // 0x80047F1C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8004A0C4(rdram, ctx);
        goto after_25;
    // 0x80047F1C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_25:
    // 0x80047F20: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80047F24: jal         0x8004C4D8
    // 0x80047F28: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8004C4D8(rdram, ctx);
        goto after_26;
    // 0x80047F28: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_26:
    // 0x80047F2C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80047F30: sw          $t3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r11;
L_80047F34:
    // 0x80047F34: jal         0x8000798C
    // 0x80047F38: nop

    func_8000798C(rdram, ctx);
        goto after_27;
    // 0x80047F38: nop

    after_27:
    // 0x80047F3C: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x80047F40: bne         $t4, $zero, L_80047F34
    if (ctx->r12 != 0) {
        // 0x80047F44: nop
    
            goto L_80047F34;
    }
    // 0x80047F44: nop

    // 0x80047F48: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80047F4C: sw          $t5, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r13;
    // 0x80047F50: jal         0x80004E5C
    // 0x80047F54: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    func_80004E5C(rdram, ctx);
        goto after_28;
    // 0x80047F54: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    after_28:
    // 0x80047F58: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80047F5C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80047F60: addiu       $a2, $a2, -0x6C60
    ctx->r6 = ADD32(ctx->r6, -0X6C60);
    // 0x80047F64: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80047F68: jal         0x8001026C
    // 0x80047F6C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8001026C(rdram, ctx);
        goto after_29;
    // 0x80047F6C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_29:
    // 0x80047F70: jal         0x80049C48
    // 0x80047F74: nop

    func_80049C48(rdram, ctx);
        goto after_30;
    // 0x80047F74: nop

    after_30:
    // 0x80047F78: jal         0x8000798C
    // 0x80047F7C: nop

    func_8000798C(rdram, ctx);
        goto after_31;
    // 0x80047F7C: nop

    after_31:
    // 0x80047F80: jal         0x8000798C
    // 0x80047F84: nop

    func_8000798C(rdram, ctx);
        goto after_32;
    // 0x80047F84: nop

    after_32:
    // 0x80047F88: jal         0x8000798C
    // 0x80047F8C: nop

    func_8000798C(rdram, ctx);
        goto after_33;
    // 0x80047F8C: nop

    after_33:
    // 0x80047F90: jal         0x8000798C
    // 0x80047F94: nop

    func_8000798C(rdram, ctx);
        goto after_34;
    // 0x80047F94: nop

    after_34:
    // 0x80047F98: lw          $t8, 0x130($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X130);
    // 0x80047F9C: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
L_80047FA0:
    // 0x80047FA0: jal         0x8000798C
    // 0x80047FA4: nop

    func_8000798C(rdram, ctx);
        goto after_35;
    // 0x80047FA4: nop

    after_35:
    // 0x80047FA8: b           L_80047FA0
    // 0x80047FAC: nop

        goto L_80047FA0;
    // 0x80047FAC: nop

L_80047FB0:
    // 0x80047FB0: lh          $t9, 0x12C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X12C);
L_80047FB4:
    // 0x80047FB4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80047FB8: beq         $t9, $at, L_80048054
    if (ctx->r25 == ctx->r1) {
        // 0x80047FBC: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_80048054;
    }
    // 0x80047FBC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80047FC0: lh          $v0, -0x2E60($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2E60);
    // 0x80047FC4: slti        $at, $v0, 0x1A
    ctx->r1 = SIGNED(ctx->r2) < 0X1A ? 1 : 0;
    // 0x80047FC8: bnel        $at, $zero, L_80047FEC
    if (ctx->r1 != 0) {
        // 0x80047FCC: slti        $at, $v0, -0x19
        ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
            goto L_80047FEC;
    }
    goto skip_7;
    // 0x80047FCC: slti        $at, $v0, -0x19
    ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
    skip_7:
    // 0x80047FD0: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80047FD4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80047FD8: add.d       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f22.d); 
    ctx->f8.d = ctx->f6.d + ctx->f22.d;
    // 0x80047FDC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80047FE0: b           L_80048008
    // 0x80047FE4: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
        goto L_80048008;
    // 0x80047FE4: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x80047FE8: slti        $at, $v0, -0x19
    ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
L_80047FEC:
    // 0x80047FEC: beq         $at, $zero, L_80048008
    if (ctx->r1 == 0) {
        // 0x80047FF0: nop
    
            goto L_80048008;
    }
    // 0x80047FF0: nop

    // 0x80047FF4: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80047FF8: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80047FFC: sub.d       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f22.d); 
    ctx->f4.d = ctx->f18.d - ctx->f22.d;
    // 0x80048000: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80048004: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
L_80048008:
    // 0x80048008: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8004800C: lh          $v0, -0x2E5E($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2E5E);
    // 0x80048010: slti        $at, $v0, 0x1A
    ctx->r1 = SIGNED(ctx->r2) < 0X1A ? 1 : 0;
    // 0x80048014: bnel        $at, $zero, L_80048038
    if (ctx->r1 != 0) {
        // 0x80048018: slti        $at, $v0, -0x19
        ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
            goto L_80048038;
    }
    goto skip_8;
    // 0x80048018: slti        $at, $v0, -0x19
    ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
    skip_8:
    // 0x8004801C: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80048020: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80048024: sub.d       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f22.d); 
    ctx->f16.d = ctx->f10.d - ctx->f22.d;
    // 0x80048028: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8004802C: b           L_80048054
    // 0x80048030: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
        goto L_80048054;
    // 0x80048030: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x80048034: slti        $at, $v0, -0x19
    ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
L_80048038:
    // 0x80048038: beql        $at, $zero, L_80048058
    if (ctx->r1 == 0) {
        // 0x8004803C: lh          $t0, 0x114($sp)
        ctx->r8 = MEM_H(ctx->r29, 0X114);
            goto L_80048058;
    }
    goto skip_9;
    // 0x8004803C: lh          $t0, 0x114($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X114);
    skip_9:
    // 0x80048040: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80048044: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80048048: add.d       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f22.d); 
    ctx->f8.d = ctx->f6.d + ctx->f22.d;
    // 0x8004804C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80048050: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
L_80048054:
    // 0x80048054: lh          $t0, 0x114($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X114);
L_80048058:
    // 0x80048058: beq         $s3, $t0, L_800480F4
    if (ctx->r19 == ctx->r8) {
        // 0x8004805C: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_800480F4;
    }
    // 0x8004805C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80048060: beql        $t0, $at, L_800480D4
    if (ctx->r8 == ctx->r1) {
        // 0x80048064: sll         $a0, $s3, 16
        ctx->r4 = S32(ctx->r19 << 16);
            goto L_800480D4;
    }
    goto skip_10;
    // 0x80048064: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    skip_10:
    // 0x80048068: beq         $s1, $zero, L_80048078
    if (ctx->r17 == 0) {
        // 0x8004806C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80048078;
    }
    // 0x8004806C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80048070: jal         0x8004A0C4
    // 0x80048074: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    func_8004A0C4(rdram, ctx);
        goto after_36;
    // 0x80048074: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_36:
L_80048078:
    // 0x80048078: jal         0x80049C48
    // 0x8004807C: nop

    func_80049C48(rdram, ctx);
        goto after_37;
    // 0x8004807C: nop

    after_37:
    // 0x80048080: jal         0x8000798C
    // 0x80048084: nop

    func_8000798C(rdram, ctx);
        goto after_38;
    // 0x80048084: nop

    after_38:
    // 0x80048088: jal         0x8000798C
    // 0x8004808C: nop

    func_8000798C(rdram, ctx);
        goto after_39;
    // 0x8004808C: nop

    after_39:
    // 0x80048090: jal         0x8000798C
    // 0x80048094: nop

    func_8000798C(rdram, ctx);
        goto after_40;
    // 0x80048094: nop

    after_40:
    // 0x80048098: jal         0x8000798C
    // 0x8004809C: nop

    func_8000798C(rdram, ctx);
        goto after_41;
    // 0x8004809C: nop

    after_41:
    // 0x800480A0: jal         0x8000798C
    // 0x800480A4: nop

    func_8000798C(rdram, ctx);
        goto after_42;
    // 0x800480A4: nop

    after_42:
    // 0x800480A8: jal         0x8000798C
    // 0x800480AC: nop

    func_8000798C(rdram, ctx);
        goto after_43;
    // 0x800480AC: nop

    after_43:
    // 0x800480B0: jal         0x8000798C
    // 0x800480B4: nop

    func_8000798C(rdram, ctx);
        goto after_44;
    // 0x800480B4: nop

    after_44:
    // 0x800480B8: jal         0x8000798C
    // 0x800480BC: nop

    func_8000798C(rdram, ctx);
        goto after_45;
    // 0x800480BC: nop

    after_45:
    // 0x800480C0: jal         0x8000798C
    // 0x800480C4: nop

    func_8000798C(rdram, ctx);
        goto after_46;
    // 0x800480C4: nop

    after_46:
    // 0x800480C8: jal         0x8000798C
    // 0x800480CC: nop

    func_8000798C(rdram, ctx);
        goto after_47;
    // 0x800480CC: nop

    after_47:
    // 0x800480D0: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
L_800480D4:
    // 0x800480D4: sra         $t1, $a0, 16
    ctx->r9 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800480D8: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800480DC: sw          $t2, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r10;
    // 0x800480E0: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800480E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800480E8: jal         0x800499B0
    // 0x800480EC: sh          $s3, 0x114($sp)
    MEM_H(0X114, ctx->r29) = ctx->r19;
    func_800499B0(rdram, ctx);
        goto after_48;
    // 0x800480EC: sh          $s3, 0x114($sp)
    MEM_H(0X114, ctx->r29) = ctx->r19;
    after_48:
    // 0x800480F0: sw          $zero, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = 0;
L_800480F4:
    // 0x800480F4: lw          $t3, 0x11C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X11C);
    // 0x800480F8: lw          $t4, 0x118($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X118);
    // 0x800480FC: beql        $t3, $t4, L_80048148
    if (ctx->r11 == ctx->r12) {
        // 0x80048100: lw          $t6, 0x8($s1)
        ctx->r14 = MEM_W(ctx->r17, 0X8);
            goto L_80048148;
    }
    goto skip_11;
    // 0x80048100: lw          $t6, 0x8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X8);
    skip_11:
    // 0x80048104: beql        $s1, $zero, L_80048118
    if (ctx->r17 == 0) {
        // 0x80048108: addiu       $a0, $sp, 0x11C
        ctx->r4 = ADD32(ctx->r29, 0X11C);
            goto L_80048118;
    }
    goto skip_12;
    // 0x80048108: addiu       $a0, $sp, 0x11C
    ctx->r4 = ADD32(ctx->r29, 0X11C);
    skip_12:
    // 0x8004810C: jal         0x8004A0C4
    // 0x80048110: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8004A0C4(rdram, ctx);
        goto after_49;
    // 0x80048110: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_49:
    // 0x80048114: addiu       $a0, $sp, 0x11C
    ctx->r4 = ADD32(ctx->r29, 0X11C);
L_80048118:
    // 0x80048118: jal         0x80049DA8
    // 0x8004811C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    func_80049DA8(rdram, ctx);
        goto after_50;
    // 0x8004811C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    after_50:
    // 0x80048120: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
    // 0x80048124: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80048128: jal         0x80049DFC
    // 0x8004812C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80049DFC(rdram, ctx);
        goto after_51;
    // 0x8004812C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_51:
    // 0x80048130: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80048134: jal         0x8004A148
    // 0x80048138: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8004A148(rdram, ctx);
        goto after_52;
    // 0x80048138: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_52:
    // 0x8004813C: lw          $t5, 0x11C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X11C);
    // 0x80048140: sw          $t5, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r13;
    // 0x80048144: lw          $t6, 0x8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X8);
L_80048148:
    // 0x80048148: lw          $v0, 0xE0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0XE0);
    // 0x8004814C: beq         $v0, $zero, L_8004818C
    if (ctx->r2 == 0) {
        // 0x80048150: nop
    
            goto L_8004818C;
    }
    // 0x80048150: nop

    // 0x80048154: lbu         $v1, 0x10($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X10);
    // 0x80048158: lh          $t8, 0x6A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X6A);
    // 0x8004815C: addiu       $t1, $zero, 0x1E
    ctx->r9 = ADD32(0, 0X1E);
    // 0x80048160: andi        $t7, $v1, 0x4
    ctx->r15 = ctx->r3 & 0X4;
    // 0x80048164: bnel        $t7, $zero, L_8004818C
    if (ctx->r15 != 0) {
        // 0x80048168: sh          $t1, 0x6A($sp)
        MEM_H(0X6A, ctx->r29) = ctx->r9;
            goto L_8004818C;
    }
    goto skip_13;
    // 0x80048168: sh          $t1, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r9;
    skip_13:
    // 0x8004816C: beq         $t8, $zero, L_80048180
    if (ctx->r24 == 0) {
        // 0x80048170: ori         $t0, $v1, 0x4
        ctx->r8 = ctx->r3 | 0X4;
            goto L_80048180;
    }
    // 0x80048170: ori         $t0, $v1, 0x4
    ctx->r8 = ctx->r3 | 0X4;
    // 0x80048174: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80048178: b           L_8004818C
    // 0x8004817C: sh          $t9, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r25;
        goto L_8004818C;
    // 0x8004817C: sh          $t9, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r25;
L_80048180:
    // 0x80048180: b           L_8004818C
    // 0x80048184: sb          $t0, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r8;
        goto L_8004818C;
    // 0x80048184: sb          $t0, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r8;
    // 0x80048188: sh          $t1, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r9;
L_8004818C:
    // 0x8004818C: beql        $s1, $zero, L_80048284
    if (ctx->r17 == 0) {
        // 0x80048190: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80048284;
    }
    goto skip_14;
    // 0x80048190: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_14:
    // 0x80048194: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x80048198: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8004819C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x800481A0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800481A4: jal         0x80049840
    // 0x800481A8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_80049840(rdram, ctx);
        goto after_53;
    // 0x800481A8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_53:
    // 0x800481AC: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    // 0x800481B0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800481B4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x800481B8: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x800481BC: jal         0x80049840
    // 0x800481C0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_80049840(rdram, ctx);
        goto after_54;
    // 0x800481C0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_54:
    // 0x800481C4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800481C8: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800481CC: jal         0x80000BD8
    // 0x800481D0: addiu       $a2, $sp, 0x84
    ctx->r6 = ADD32(ctx->r29, 0X84);
    func_80000BD8(rdram, ctx);
        goto after_55;
    // 0x800481D0: addiu       $a2, $sp, 0x84
    ctx->r6 = ADD32(ctx->r29, 0X84);
    after_55:
    // 0x800481D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800481D8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800481DC: lw          $a1, 0x14($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14);
    // 0x800481E0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800481E4: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800481E8: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x800481EC: jal         0x80049840
    // 0x800481F0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_80049840(rdram, ctx);
        goto after_56;
    // 0x800481F0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_56:
    // 0x800481F4: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    // 0x800481F8: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    // 0x800481FC: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x80048200: jal         0x80000BD8
    // 0x80048204: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80000BD8(rdram, ctx);
        goto after_57;
    // 0x80048204: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_57:
    // 0x80048208: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8004820C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80048210: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80048214: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80048218: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8004821C: jal         0x80001AB4
    // 0x80048220: nop

    func_80001AB4(rdram, ctx);
        goto after_58;
    // 0x80048220: nop

    after_58:
    // 0x80048224: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    // 0x80048228: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x8004822C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80048230: jal         0x80000BD8
    // 0x80048234: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_80000BD8(rdram, ctx);
        goto after_59;
    // 0x80048234: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_59:
    // 0x80048238: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8004823C: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
L_80048240:
    // 0x80048240: lw          $t2, 0x8($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X8);
    // 0x80048244: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80048248: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8004824C: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x80048250: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80048254: bne         $v0, $s4, L_80048240
    if (ctx->r2 != ctx->r20) {
        // 0x80048258: swc1        $f18, 0x40($t3)
        MEM_W(0X40, ctx->r11) = ctx->f18.u32l;
            goto L_80048240;
    }
    // 0x80048258: swc1        $f18, 0x40($t3)
    MEM_W(0X40, ctx->r11) = ctx->f18.u32l;
    // 0x8004825C: lw          $t6, 0x8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X8);
    // 0x80048260: lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X80);
    // 0x80048264: ori         $t5, $zero, 0x8001
    ctx->r13 = 0 | 0X8001;
    // 0x80048268: sw          $t5, 0xD8($t6)
    MEM_W(0XD8, ctx->r14) = ctx->r13;
    // 0x8004826C: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x80048270: sll         $t4, $v1, 1
    ctx->r12 = S32(ctx->r3 << 1);
    // 0x80048274: lw          $t7, 0xD8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XD8);
    // 0x80048278: or          $t8, $t7, $t4
    ctx->r24 = ctx->r15 | ctx->r12;
    // 0x8004827C: sw          $t8, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r24;
    // 0x80048280: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80048284:
    // 0x80048284: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80048288: jal         0x8004C388
    // 0x8004828C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004C388(rdram, ctx);
        goto after_60;
    // 0x8004828C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_60:
    // 0x80048290: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80048294: addiu       $a2, $a2, 0x7CB0
    ctx->r6 = ADD32(ctx->r6, 0X7CB0);
    // 0x80048298: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x8004829C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800482A0: jal         0x8004C340
    // 0x800482A4: lh          $a3, 0xC($fp)
    ctx->r7 = MEM_H(ctx->r30, 0XC);
    func_8004C340(rdram, ctx);
        goto after_61;
    // 0x800482A4: lh          $a3, 0xC($fp)
    ctx->r7 = MEM_H(ctx->r30, 0XC);
    after_61:
    // 0x800482A8: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x800482AC: addiu       $a2, $a2, 0x7CBC
    ctx->r6 = ADD32(ctx->r6, 0X7CBC);
    // 0x800482B0: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x800482B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800482B8: jal         0x8004C340
    // 0x800482BC: lh          $a3, 0x1A($fp)
    ctx->r7 = MEM_H(ctx->r30, 0X1A);
    func_8004C340(rdram, ctx);
        goto after_62;
    // 0x800482BC: lh          $a3, 0x1A($fp)
    ctx->r7 = MEM_H(ctx->r30, 0X1A);
    after_62:
    // 0x800482C0: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x800482C4: addiu       $a2, $a2, 0x7CC8
    ctx->r6 = ADD32(ctx->r6, 0X7CC8);
    // 0x800482C8: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x800482CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800482D0: jal         0x8004C340
    // 0x800482D4: lh          $a3, 0x1C($fp)
    ctx->r7 = MEM_H(ctx->r30, 0X1C);
    func_8004C340(rdram, ctx);
        goto after_63;
    // 0x800482D4: lh          $a3, 0x1C($fp)
    ctx->r7 = MEM_H(ctx->r30, 0X1C);
    after_63:
    // 0x800482D8: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x800482DC: addiu       $a2, $a2, 0x7CD4
    ctx->r6 = ADD32(ctx->r6, 0X7CD4);
    // 0x800482E0: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x800482E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800482E8: jal         0x8004C340
    // 0x800482EC: lh          $a3, 0x1E($fp)
    ctx->r7 = MEM_H(ctx->r30, 0X1E);
    func_8004C340(rdram, ctx);
        goto after_64;
    // 0x800482EC: lh          $a3, 0x1E($fp)
    ctx->r7 = MEM_H(ctx->r30, 0X1E);
    after_64:
    // 0x800482F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800482F4: addiu       $v1, $sp, 0x74
    ctx->r3 = ADD32(ctx->r29, 0X74);
    // 0x800482F8: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
L_800482FC:
    // 0x800482FC: lbu         $t9, 0x10($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X10);
    // 0x80048300: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80048304: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80048308: sb          $t9, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r25;
    // 0x8004830C: lbu         $t0, 0x11($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X11);
    // 0x80048310: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80048314: sb          $t0, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r8;
    // 0x80048318: lbu         $t1, 0xE($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0XE);
    // 0x8004831C: sb          $t1, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r9;
    // 0x80048320: lbu         $t2, 0xF($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0XF);
    // 0x80048324: bne         $a1, $s5, L_800482FC
    if (ctx->r5 != ctx->r21) {
        // 0x80048328: sb          $t2, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r10;
            goto L_800482FC;
    }
    // 0x80048328: sb          $t2, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r10;
    // 0x8004832C: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80048330: sb          $zero, 0x7C($sp)
    MEM_B(0X7C, ctx->r29) = 0;
    // 0x80048334: addiu       $a2, $a2, 0x7CE0
    ctx->r6 = ADD32(ctx->r6, 0X7CE0);
    // 0x80048338: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x8004833C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80048340: jal         0x8004C340
    // 0x80048344: addiu       $a3, $sp, 0x74
    ctx->r7 = ADD32(ctx->r29, 0X74);
    func_8004C340(rdram, ctx);
        goto after_65;
    // 0x80048344: addiu       $a3, $sp, 0x74
    ctx->r7 = ADD32(ctx->r29, 0X74);
    after_65:
    // 0x80048348: jal         0x8000798C
    // 0x8004834C: nop

    func_8000798C(rdram, ctx);
        goto after_66;
    // 0x8004834C: nop

    after_66:
    // 0x80048350: b           L_80047A90
    // 0x80048354: nop

        goto L_80047A90;
    // 0x80048354: nop

    // 0x80048358: nop

    // 0x8004835C: nop

    // 0x80048360: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80048364: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80048368: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8004836C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80048370: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80048374: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80048378: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8004837C: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80048380: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80048384: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80048388: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8004838C: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x80048390: jr          $ra
    // 0x80048394: addiu       $sp, $sp, 0x130
    ctx->r29 = ADD32(ctx->r29, 0X130);
    TRACE_RETURN()
    return;
    // 0x80048394: addiu       $sp, $sp, 0x130
    ctx->r29 = ADD32(ctx->r29, 0X130);
;}
RECOMP_FUNC void func_80048398(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80048398: addiu       $sp, $sp, -0x1A8
    ctx->r29 = ADD32(ctx->r29, -0X1A8);
    // 0x8004839C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800483A0: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800483A4: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800483A8: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x800483AC: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x800483B0: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800483B4: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800483B8: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800483BC: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800483C0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800483C4: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800483C8: sw          $a0, 0x1A8($sp)
    MEM_W(0X1A8, ctx->r29) = ctx->r4;
    // 0x800483CC: sw          $zero, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = 0;
    // 0x800483D0: sw          $zero, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = 0;
    // 0x800483D4: sw          $zero, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = 0;
    // 0x800483D8: sw          $zero, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = 0;
    // 0x800483DC: sw          $zero, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = 0;
    // 0x800483E0: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800483E4: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800483E8: sw          $zero, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = 0;
    // 0x800483EC: sh          $zero, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = 0;
    // 0x800483F0: jal         0x8000798C
    // 0x800483F4: sh          $zero, 0x9C($sp)
    MEM_H(0X9C, ctx->r29) = 0;
    func_8000798C(rdram, ctx);
        goto after_0;
    // 0x800483F4: sh          $zero, 0x9C($sp)
    MEM_H(0X9C, ctx->r29) = 0;
    after_0:
    // 0x800483F8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800483FC: lui         $a0, 0x8002
    ctx->r4 = S32(0X8002 << 16);
    // 0x80048400: addiu       $a0, $a0, -0x52C8
    ctx->r4 = ADD32(ctx->r4, -0X52C8);
    // 0x80048404: sw          $t6, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r14;
    // 0x80048408: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x8004840C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80048410: jal         0x80004CE0
    // 0x80048414: addiu       $a3, $sp, 0xD8
    ctx->r7 = ADD32(ctx->r29, 0XD8);
    func_80004CE0(rdram, ctx);
        goto after_1;
    // 0x80048414: addiu       $a3, $sp, 0xD8
    ctx->r7 = ADD32(ctx->r29, 0XD8);
    after_1:
    // 0x80048418: lw          $t7, 0xD8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD8);
    // 0x8004841C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80048420: beq         $t7, $zero, L_8004843C
    if (ctx->r15 == 0) {
        // 0x80048424: nop
    
            goto L_8004843C;
    }
    // 0x80048424: nop

L_80048428:
    // 0x80048428: jal         0x8000798C
    // 0x8004842C: nop

    func_8000798C(rdram, ctx);
        goto after_2;
    // 0x8004842C: nop

    after_2:
    // 0x80048430: lw          $t8, 0xD8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD8);
    // 0x80048434: bne         $t8, $zero, L_80048428
    if (ctx->r24 != 0) {
        // 0x80048438: nop
    
            goto L_80048428;
    }
    // 0x80048438: nop

L_8004843C:
    // 0x8004843C: jal         0x80004E5C
    // 0x80048440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80004E5C(rdram, ctx);
        goto after_3;
    // 0x80048440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80048444: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80048448: lhu         $t9, -0x2E5C($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X2E5C);
    // 0x8004844C: andi        $t5, $t9, 0x10
    ctx->r13 = ctx->r25 & 0X10;
    // 0x80048450: beq         $t5, $zero, L_80048470
    if (ctx->r13 == 0) {
        // 0x80048454: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_80048470;
    }
    // 0x80048454: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80048458: addiu       $v1, $v1, -0x6630
    ctx->r3 = ADD32(ctx->r3, -0X6630);
    // 0x8004845C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80048460: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80048464: bne         $v0, $at, L_80048470
    if (ctx->r2 != ctx->r1) {
        // 0x80048468: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_80048470;
    }
    // 0x80048468: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8004846C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_80048470:
    // 0x80048470: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80048474: addiu       $v1, $v1, -0x6630
    ctx->r3 = ADD32(ctx->r3, -0X6630);
    // 0x80048478: jal         0x80035D38
    // 0x8004847C: lh          $a0, 0x2($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2);
    func_80035D38(rdram, ctx);
        goto after_4;
    // 0x8004847C: lh          $a0, 0x2($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2);
    after_4:
    // 0x80048480: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80048484: addiu       $a0, $a0, -0x662C
    ctx->r4 = ADD32(ctx->r4, -0X662C);
    // 0x80048488: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x8004848C: lh          $v1, 0x0($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X0);
    // 0x80048490: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80048494: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80048498: beq         $v1, $at, L_800484A4
    if (ctx->r3 == ctx->r1) {
        // 0x8004849C: addiu       $s2, $zero, 0x3
        ctx->r18 = ADD32(0, 0X3);
            goto L_800484A4;
    }
    // 0x8004849C: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x800484A0: bne         $s2, $v1, L_800484C8
    if (ctx->r18 != ctx->r3) {
        // 0x800484A4: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_800484C8;
    }
L_800484A4:
    // 0x800484A4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800484A8: lhu         $t7, -0x2E5C($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X2E5C);
    // 0x800484AC: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x800484B0: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x800484B4: andi        $t8, $t7, 0x2000
    ctx->r24 = ctx->r15 & 0X2000;
    // 0x800484B8: beql        $t8, $zero, L_800484CC
    if (ctx->r24 == 0) {
        // 0x800484BC: sll         $a0, $v1, 16
        ctx->r4 = S32(ctx->r3 << 16);
            goto L_800484CC;
    }
    goto skip_0;
    // 0x800484BC: sll         $a0, $v1, 16
    ctx->r4 = S32(ctx->r3 << 16);
    skip_0:
    // 0x800484C0: sh          $t9, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r25;
    // 0x800484C4: lh          $v1, 0x0($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X0);
L_800484C8:
    // 0x800484C8: sll         $a0, $v1, 16
    ctx->r4 = S32(ctx->r3 << 16);
L_800484CC:
    // 0x800484CC: sra         $t5, $a0, 16
    ctx->r13 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800484D0: jal         0x800499B0
    // 0x800484D4: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    func_800499B0(rdram, ctx);
        goto after_5;
    // 0x800484D4: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_5:
    // 0x800484D8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800484DC: addiu       $v1, $v1, -0x2CFC
    ctx->r3 = ADD32(ctx->r3, -0X2CFC);
    // 0x800484E0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800484E4: addiu       $a0, $zero, 0x87
    ctx->r4 = ADD32(0, 0X87);
    // 0x800484E8: addiu       $a1, $zero, 0x87
    ctx->r5 = ADD32(0, 0X87);
    // 0x800484EC: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x800484F0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800484F4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800484F8: jal         0x8000BD4C
    // 0x800484FC: sw          $v0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r2;
    func_8000BD4C(rdram, ctx);
        goto after_6;
    // 0x800484FC: sw          $v0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r2;
    after_6:
    // 0x80048500: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80048504: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80048508: jal         0x80004364
    // 0x8004850C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_80004364(rdram, ctx);
        goto after_7;
    // 0x8004850C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_7:
    // 0x80048510: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80048514: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80048518: jal         0x8000C7C0
    // 0x8004851C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_8000C7C0(rdram, ctx);
        goto after_8;
    // 0x8004851C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_8:
    // 0x80048520: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80048524: lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // 0x80048528: addiu       $a0, $a0, 0x3D4
    ctx->r4 = ADD32(ctx->r4, 0X3D4);
    // 0x8004852C: sw          $t7, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r15;
    // 0x80048530: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x80048534: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80048538: jal         0x80004CE0
    // 0x8004853C: addiu       $a3, $sp, 0xD0
    ctx->r7 = ADD32(ctx->r29, 0XD0);
    func_80004CE0(rdram, ctx);
        goto after_9;
    // 0x8004853C: addiu       $a3, $sp, 0xD0
    ctx->r7 = ADD32(ctx->r29, 0XD0);
    after_9:
    // 0x80048540: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80048544: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x80048548: sw          $v0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r2;
    // 0x8004854C: addiu       $a0, $a0, -0x2E00
    ctx->r4 = ADD32(ctx->r4, -0X2E00);
    // 0x80048550: sw          $t8, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r24;
    // 0x80048554: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    // 0x80048558: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8004855C: jal         0x80004CE0
    // 0x80048560: addiu       $a3, $sp, 0xC8
    ctx->r7 = ADD32(ctx->r29, 0XC8);
    func_80004CE0(rdram, ctx);
        goto after_10;
    // 0x80048560: addiu       $a3, $sp, 0xC8
    ctx->r7 = ADD32(ctx->r29, 0XC8);
    after_10:
    // 0x80048564: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80048568: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x8004856C: sw          $v0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r2;
    // 0x80048570: addiu       $a0, $a0, -0x2910
    ctx->r4 = ADD32(ctx->r4, -0X2910);
    // 0x80048574: sw          $t9, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r25;
    // 0x80048578: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x8004857C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80048580: jal         0x80004CE0
    // 0x80048584: addiu       $a3, $sp, 0xC0
    ctx->r7 = ADD32(ctx->r29, 0XC0);
    func_80004CE0(rdram, ctx);
        goto after_11;
    // 0x80048584: addiu       $a3, $sp, 0xC0
    ctx->r7 = ADD32(ctx->r29, 0XC0);
    after_11:
    // 0x80048588: jal         0x8000798C
    // 0x8004858C: sw          $v0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r2;
    func_8000798C(rdram, ctx);
        goto after_12;
    // 0x8004858C: sw          $v0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r2;
    after_12:
    // 0x80048590: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80048594: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80048598: addiu       $a0, $a0, -0x6830
    ctx->r4 = ADD32(ctx->r4, -0X6830);
    // 0x8004859C: sw          $t5, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r13;
    // 0x800485A0: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    // 0x800485A4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x800485A8: jal         0x80004CE0
    // 0x800485AC: addiu       $a3, $sp, 0xB8
    ctx->r7 = ADD32(ctx->r29, 0XB8);
    func_80004CE0(rdram, ctx);
        goto after_13;
    // 0x800485AC: addiu       $a3, $sp, 0xB8
    ctx->r7 = ADD32(ctx->r29, 0XB8);
    after_13:
    // 0x800485B0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800485B4: sw          $v0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r2;
    // 0x800485B8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800485BC: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
L_800485C0:
    // 0x800485C0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800485C4: swc1        $f20, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f20.u32l;
    // 0x800485C8: swc1        $f20, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f20.u32l;
    // 0x800485CC: bne         $s0, $s2, L_800485C0
    if (ctx->r16 != ctx->r18) {
        // 0x800485D0: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800485C0;
    }
    // 0x800485D0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800485D4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800485D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800485DC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800485E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800485E4: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
    // 0x800485E8: lwc1        $f6, 0x7F68($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7F68);
    // 0x800485EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800485F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800485F4: jal         0x8004C388
    // 0x800485F8: swc1        $f6, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f6.u32l;
    func_8004C388(rdram, ctx);
        goto after_14;
    // 0x800485F8: swc1        $f6, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f6.u32l;
    after_14:
    // 0x800485FC: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80048600: addiu       $a2, $a2, 0x7D10
    ctx->r6 = ADD32(ctx->r6, 0X7D10);
    // 0x80048604: addiu       $a0, $zero, -0xFE
    ctx->r4 = ADD32(0, -0XFE);
    // 0x80048608: jal         0x8004BCF0
    // 0x8004860C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004BCF0(rdram, ctx);
        goto after_15;
    // 0x8004860C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x80048610: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x80048614: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80048618: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8004861C: addiu       $a1, $a1, -0x5008
    ctx->r5 = ADD32(ctx->r5, -0X5008);
    // 0x80048620: addiu       $a0, $sp, 0x198
    ctx->r4 = ADD32(ctx->r29, 0X198);
    // 0x80048624: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80048628: jal         0x80049660
    // 0x8004862C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_80049660(rdram, ctx);
        goto after_16;
    // 0x8004862C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_16:
    // 0x80048630: jal         0x8000798C
    // 0x80048634: nop

    func_8000798C(rdram, ctx);
        goto after_17;
    // 0x80048634: nop

    after_17:
    // 0x80048638: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8004863C: jal         0x80011520
    // 0x80048640: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80011520(rdram, ctx);
        goto after_18;
    // 0x80048640: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_18:
    // 0x80048644: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80048648: jal         0x8004EFB4
    // 0x8004864C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8004EFB4(rdram, ctx);
        goto after_19;
    // 0x8004864C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_19:
    // 0x80048650: jal         0x8000798C
    // 0x80048654: nop

    func_8000798C(rdram, ctx);
        goto after_20;
    // 0x80048654: nop

    after_20:
    // 0x80048658: addiu       $fp, $zero, 0xC
    ctx->r30 = ADD32(0, 0XC);
    // 0x8004865C: addiu       $s7, $zero, 0x8
    ctx->r23 = ADD32(0, 0X8);
    // 0x80048660: lw          $s5, 0x18C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X18C);
    // 0x80048664: lw          $s3, 0x188($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X188);
    // 0x80048668: lh          $t7, 0x9E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X9E);
L_8004866C:
    // 0x8004866C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80048670: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80048674: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80048678: bne         $s6, $zero, L_8004883C
    if (ctx->r22 != 0) {
        // 0x8004867C: sh          $t8, 0x9E($sp)
        MEM_H(0X9E, ctx->r29) = ctx->r24;
            goto L_8004883C;
    }
    // 0x8004867C: sh          $t8, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r24;
    // 0x80048680: jal         0x800496B4
    // 0x80048684: addiu       $a0, $sp, 0x198
    ctx->r4 = ADD32(ctx->r29, 0X198);
    func_800496B4(rdram, ctx);
        goto after_21;
    // 0x80048684: addiu       $a0, $sp, 0x198
    ctx->r4 = ADD32(ctx->r29, 0X198);
    after_21:
    // 0x80048688: lh          $v0, 0x1A4($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X1A4);
    // 0x8004868C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80048690: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80048694: beq         $v0, $at, L_800486C0
    if (ctx->r2 == ctx->r1) {
        // 0x80048698: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_800486C0;
    }
    // 0x80048698: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8004869C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800486A0: beq         $v0, $at, L_800486E8
    if (ctx->r2 == ctx->r1) {
        // 0x800486A4: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_800486E8;
    }
    // 0x800486A4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800486A8: beq         $v0, $s7, L_80048718
    if (ctx->r2 == ctx->r23) {
        // 0x800486AC: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_80048718;
    }
    // 0x800486AC: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800486B0: beq         $v0, $at, L_80048738
    if (ctx->r2 == ctx->r1) {
        // 0x800486B4: nop
    
            goto L_80048738;
    }
    // 0x800486B4: nop

    // 0x800486B8: b           L_800495E0
    // 0x800486BC: nop

        goto L_800495E0;
    // 0x800486BC: nop

L_800486C0:
    // 0x800486C0: lhu         $t9, -0x2E5A($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X2E5A);
    // 0x800486C4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800486C8: andi        $t5, $t9, 0x1000
    ctx->r13 = ctx->r25 & 0X1000;
    // 0x800486CC: beq         $t5, $zero, L_800495E0
    if (ctx->r13 == 0) {
        // 0x800486D0: nop
    
            goto L_800495E0;
    }
    // 0x800486D0: nop

    // 0x800486D4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800486D8: sw          $zero, 0x194($sp)
    MEM_W(0X194, ctx->r29) = 0;
    // 0x800486DC: sw          $t6, 0x190($sp)
    MEM_W(0X190, ctx->r29) = ctx->r14;
    // 0x800486E0: b           L_800495E0
    // 0x800486E4: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
        goto L_800495E0;
    // 0x800486E4: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_800486E8:
    // 0x800486E8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800486EC: lhu         $t7, -0x2E5A($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X2E5A);
    // 0x800486F0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800486F4: andi        $t8, $t7, 0x1000
    ctx->r24 = ctx->r15 & 0X1000;
    // 0x800486F8: beq         $t8, $zero, L_800495E0
    if (ctx->r24 == 0) {
        // 0x800486FC: nop
    
            goto L_800495E0;
    }
    // 0x800486FC: nop

    // 0x80048700: lw          $t9, -0x65A0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X65A0);
    // 0x80048704: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80048708: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x8004870C: lw          $s4, 0x0($t9)
    ctx->r20 = MEM_W(ctx->r25, 0X0);
    // 0x80048710: b           L_800495E0
    // 0x80048714: sw          $zero, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = 0;
        goto L_800495E0;
    // 0x80048714: sw          $zero, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = 0;
L_80048718:
    // 0x80048718: lhu         $t5, -0x2E5A($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X2E5A);
    // 0x8004871C: andi        $t6, $t5, 0x1000
    ctx->r14 = ctx->r13 & 0X1000;
    // 0x80048720: beq         $t6, $zero, L_800495E0
    if (ctx->r14 == 0) {
        // 0x80048724: nop
    
            goto L_800495E0;
    }
    // 0x80048724: nop

    // 0x80048728: jal         0x80049634
    // 0x8004872C: sh          $zero, 0x9C($sp)
    MEM_H(0X9C, ctx->r29) = 0;
    func_80049634(rdram, ctx);
        goto after_22;
    // 0x8004872C: sh          $zero, 0x9C($sp)
    MEM_H(0X9C, ctx->r29) = 0;
    after_22:
    // 0x80048730: b           L_800495E0
    // 0x80048734: nop

        goto L_800495E0;
    // 0x80048734: nop

L_80048738:
    // 0x80048738: lhu         $t7, -0x2E5A($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X2E5A);
    // 0x8004873C: andi        $t8, $t7, 0x1000
    ctx->r24 = ctx->r15 & 0X1000;
    // 0x80048740: beq         $t8, $zero, L_800495E0
    if (ctx->r24 == 0) {
        // 0x80048744: nop
    
            goto L_800495E0;
    }
    // 0x80048744: nop

    // 0x80048748: lh          $t5, 0x9C($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X9C);
    // 0x8004874C: lw          $t9, 0x98($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X98);
    // 0x80048750: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80048754: beq         $t5, $zero, L_80048764
    if (ctx->r13 == 0) {
        // 0x80048758: sw          $t9, -0x2CFC($at)
        MEM_W(-0X2CFC, ctx->r1) = ctx->r25;
            goto L_80048764;
    }
    // 0x80048758: sw          $t9, -0x2CFC($at)
    MEM_W(-0X2CFC, ctx->r1) = ctx->r25;
    // 0x8004875C: jal         0x80049634
    // 0x80048760: nop

    func_80049634(rdram, ctx);
        goto after_23;
    // 0x80048760: nop

    after_23:
L_80048764:
    // 0x80048764: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80048768: jal         0x8004C4D8
    // 0x8004876C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8004C4D8(rdram, ctx);
        goto after_24;
    // 0x8004876C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_24:
    // 0x80048770: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80048774: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80048778: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8004877C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80048780: sw          $t9, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r25;
    // 0x80048784: sw          $t8, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r24;
    // 0x80048788: sw          $t7, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r15;
    // 0x8004878C: sw          $t6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r14;
L_80048790:
    // 0x80048790: jal         0x8000798C
    // 0x80048794: nop

    func_8000798C(rdram, ctx);
        goto after_25;
    // 0x80048794: nop

    after_25:
    // 0x80048798: lw          $t5, 0xD0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XD0);
    // 0x8004879C: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x800487A0: lw          $t8, 0xC0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC0);
    // 0x800487A4: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x800487A8: lw          $t5, 0xB8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB8);
    // 0x800487AC: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800487B0: or          $t6, $t9, $t5
    ctx->r14 = ctx->r25 | ctx->r13;
    // 0x800487B4: bne         $t6, $zero, L_80048790
    if (ctx->r14 != 0) {
        // 0x800487B8: nop
    
            goto L_80048790;
    }
    // 0x800487B8: nop

    // 0x800487BC: jal         0x80004E5C
    // 0x800487C0: lw          $a0, 0xCC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XCC);
    func_80004E5C(rdram, ctx);
        goto after_26;
    // 0x800487C0: lw          $a0, 0xCC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XCC);
    after_26:
    // 0x800487C4: jal         0x80004E5C
    // 0x800487C8: lw          $a0, 0xC4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC4);
    func_80004E5C(rdram, ctx);
        goto after_27;
    // 0x800487C8: lw          $a0, 0xC4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC4);
    after_27:
    // 0x800487CC: jal         0x80004E5C
    // 0x800487D0: lw          $a0, 0xBC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XBC);
    func_80004E5C(rdram, ctx);
        goto after_28;
    // 0x800487D0: lw          $a0, 0xBC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XBC);
    after_28:
    // 0x800487D4: jal         0x80004E5C
    // 0x800487D8: lw          $a0, 0xB4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB4);
    func_80004E5C(rdram, ctx);
        goto after_29;
    // 0x800487D8: lw          $a0, 0xB4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB4);
    after_29:
    // 0x800487DC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800487E0: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800487E4: addiu       $a2, $a2, -0x6C60
    ctx->r6 = ADD32(ctx->r6, -0X6C60);
    // 0x800487E8: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x800487EC: jal         0x8001026C
    // 0x800487F0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8001026C(rdram, ctx);
        goto after_30;
    // 0x800487F0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_30:
    // 0x800487F4: jal         0x8000798C
    // 0x800487F8: nop

    func_8000798C(rdram, ctx);
        goto after_31;
    // 0x800487F8: nop

    after_31:
    // 0x800487FC: jal         0x80049C48
    // 0x80048800: nop

    func_80049C48(rdram, ctx);
        goto after_32;
    // 0x80048800: nop

    after_32:
    // 0x80048804: jal         0x8000798C
    // 0x80048808: nop

    func_8000798C(rdram, ctx);
        goto after_33;
    // 0x80048808: nop

    after_33:
    // 0x8004880C: jal         0x8000798C
    // 0x80048810: nop

    func_8000798C(rdram, ctx);
        goto after_34;
    // 0x80048810: nop

    after_34:
    // 0x80048814: jal         0x8000798C
    // 0x80048818: nop

    func_8000798C(rdram, ctx);
        goto after_35;
    // 0x80048818: nop

    after_35:
    // 0x8004881C: jal         0x8000798C
    // 0x80048820: nop

    func_8000798C(rdram, ctx);
        goto after_36;
    // 0x80048820: nop

    after_36:
    // 0x80048824: lw          $t7, 0x1A8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1A8);
    // 0x80048828: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
L_8004882C:
    // 0x8004882C: jal         0x8000798C
    // 0x80048830: nop

    func_8000798C(rdram, ctx);
        goto after_37;
    // 0x80048830: nop

    after_37:
    // 0x80048834: b           L_8004882C
    // 0x80048838: nop

        goto L_8004882C;
    // 0x80048838: nop

L_8004883C:
    // 0x8004883C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80048840: sh          $t8, 0x9C($sp)
    MEM_H(0X9C, ctx->r29) = ctx->r24;
    // 0x80048844: jal         0x8004C388
    // 0x80048848: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004C388(rdram, ctx);
        goto after_38;
    // 0x80048848: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_38:
    // 0x8004884C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80048850: beq         $s6, $at, L_8004886C
    if (ctx->r22 == ctx->r1) {
        // 0x80048854: lh          $t5, 0x9E($sp)
        ctx->r13 = MEM_H(ctx->r29, 0X9E);
            goto L_8004886C;
    }
    // 0x80048854: lh          $t5, 0x9E($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X9E);
    // 0x80048858: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004885C: beq         $s6, $at, L_8004888C
    if (ctx->r22 == ctx->r1) {
        // 0x80048860: lh          $t9, 0x9E($sp)
        ctx->r25 = MEM_H(ctx->r29, 0X9E);
            goto L_8004888C;
    }
    // 0x80048860: lh          $t9, 0x9E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X9E);
    // 0x80048864: b           L_800488A8
    // 0x80048868: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
        goto L_800488A8;
    // 0x80048868: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8004886C:
    // 0x8004886C: sll         $t6, $t5, 24
    ctx->r14 = S32(ctx->r13 << 24);
    // 0x80048870: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80048874: addiu       $a2, $a2, 0x7D20
    ctx->r6 = ADD32(ctx->r6, 0X7D20);
    // 0x80048878: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8004887C: jal         0x8004BCF0
    // 0x80048880: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004BCF0(rdram, ctx);
        goto after_39;
    // 0x80048880: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_39:
    // 0x80048884: b           L_800488A8
    // 0x80048888: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
        goto L_800488A8;
    // 0x80048888: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8004888C:
    // 0x8004888C: sll         $t5, $t9, 24
    ctx->r13 = S32(ctx->r25 << 24);
    // 0x80048890: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80048894: addiu       $a2, $a2, 0x7D2C
    ctx->r6 = ADD32(ctx->r6, 0X7D2C);
    // 0x80048898: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8004889C: jal         0x8004BCF0
    // 0x800488A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8004BCF0(rdram, ctx);
        goto after_40;
    // 0x800488A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_40:
    // 0x800488A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_800488A8:
    // 0x800488A8: beq         $s6, $at, L_800488C4
    if (ctx->r22 == ctx->r1) {
        // 0x800488AC: lw          $t7, 0x194($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X194);
            goto L_800488C4;
    }
    // 0x800488AC: lw          $t7, 0x194($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X194);
    // 0x800488B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800488B4: beq         $s6, $at, L_80048A08
    if (ctx->r22 == ctx->r1) {
        // 0x800488B8: lw          $t8, 0xA0($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XA0);
            goto L_80048A08;
    }
    // 0x800488B8: lw          $t8, 0xA0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA0);
    // 0x800488BC: b           L_80048B4C
    // 0x800488C0: nop

        goto L_80048B4C;
    // 0x800488C0: nop

L_800488C4:
    // 0x800488C4: lw          $t8, 0x190($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X190);
    // 0x800488C8: beq         $t7, $t8, L_80048B4C
    if (ctx->r15 == ctx->r24) {
        // 0x800488CC: nop
    
            goto L_80048B4C;
    }
    // 0x800488CC: nop

L_800488D0:
    // 0x800488D0: beq         $s3, $zero, L_800488E0
    if (ctx->r19 == 0) {
        // 0x800488D4: nop
    
            goto L_800488E0;
    }
    // 0x800488D4: nop

    // 0x800488D8: jal         0x8004A0C4
    // 0x800488DC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_8004A0C4(rdram, ctx);
        goto after_41;
    // 0x800488DC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_41:
L_800488E0:
    // 0x800488E0: lui         $s0, 0x8007
    ctx->r16 = S32(0X8007 << 16);
    // 0x800488E4: addiu       $s0, $s0, 0x64C
    ctx->r16 = ADD32(ctx->r16, 0X64C);
    // 0x800488E8: addiu       $a0, $sp, 0x194
    ctx->r4 = ADD32(ctx->r29, 0X194);
    // 0x800488EC: jal         0x80049DA8
    // 0x800488F0: sw          $zero, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = 0;
    func_80049DA8(rdram, ctx);
        goto after_42;
    // 0x800488F0: sw          $zero, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = 0;
    after_42:
    // 0x800488F4: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x800488F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800488FC: jal         0x80049DFC
    // 0x80048900: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80049DFC(rdram, ctx);
        goto after_43;
    // 0x80048900: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_43:
    // 0x80048904: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80048908: jal         0x8004A148
    // 0x8004890C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8004A148(rdram, ctx);
        goto after_44;
    // 0x8004890C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_44:
    // 0x80048910: lui         $t5, 0x8007
    ctx->r13 = S32(0X8007 << 16);
    // 0x80048914: lh          $t5, 0x654($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X654);
    // 0x80048918: lw          $t9, 0x194($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X194);
    // 0x8004891C: addiu       $v1, $s5, 0x10
    ctx->r3 = ADD32(ctx->r21, 0X10);
    // 0x80048920: beq         $t5, $zero, L_80048974
    if (ctx->r13 == 0) {
        // 0x80048924: sw          $t9, 0x190($sp)
        MEM_W(0X190, ctx->r29) = ctx->r25;
            goto L_80048974;
    }
    // 0x80048924: sw          $t9, 0x190($sp)
    MEM_W(0X190, ctx->r29) = ctx->r25;
    // 0x80048928: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8004892C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
L_80048930:
    // 0x80048930: bnel        $a0, $t6, L_80048968
    if (ctx->r4 != ctx->r14) {
        // 0x80048934: lh          $t9, 0x34($s0)
        ctx->r25 = MEM_H(ctx->r16, 0X34);
            goto L_80048968;
    }
    goto skip_1;
    // 0x80048934: lh          $t9, 0x34($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X34);
    skip_1:
    // 0x80048938: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x8004893C: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x80048940: bnel        $t7, $t8, L_80048968
    if (ctx->r15 != ctx->r24) {
        // 0x80048944: lh          $t9, 0x34($s0)
        ctx->r25 = MEM_H(ctx->r16, 0X34);
            goto L_80048968;
    }
    goto skip_2;
    // 0x80048944: lh          $t9, 0x34($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X34);
    skip_2:
    // 0x80048948: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8004894C: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    // 0x80048950: nop

    // 0x80048954: bc1t        L_80048974
    if (c1cs) {
        // 0x80048958: nop
    
            goto L_80048974;
    }
    // 0x80048958: nop

    // 0x8004895C: b           L_80048974
    // 0x80048960: swc1        $f0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f0.u32l;
        goto L_80048974;
    // 0x80048960: swc1        $f0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f0.u32l;
    // 0x80048964: lh          $t9, 0x34($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X34);
L_80048968:
    // 0x80048968: addiu       $s0, $s0, 0x2C
    ctx->r16 = ADD32(ctx->r16, 0X2C);
    // 0x8004896C: bnel        $t9, $zero, L_80048930
    if (ctx->r25 != 0) {
        // 0x80048970: lw          $t6, 0x0($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X0);
            goto L_80048930;
    }
    goto skip_3;
    // 0x80048970: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    skip_3:
L_80048974:
    // 0x80048974: lui         $t5, 0x8007
    ctx->r13 = S32(0X8007 << 16);
    // 0x80048978: lh          $t5, 0x2584($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X2584);
    // 0x8004897C: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80048980: addiu       $a2, $a2, 0x2584
    ctx->r6 = ADD32(ctx->r6, 0X2584);
    // 0x80048984: beq         $t5, $zero, L_80048B4C
    if (ctx->r13 == 0) {
        // 0x80048988: nop
    
            goto L_80048B4C;
    }
    // 0x80048988: nop

    // 0x8004898C: lw          $a1, 0x4($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X4);
L_80048990:
    // 0x80048990: addiu       $v1, $s5, 0x10
    ctx->r3 = ADD32(ctx->r21, 0X10);
    // 0x80048994: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x80048998: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8004899C: beql        $t6, $zero, L_800489F4
    if (ctx->r14 == 0) {
        // 0x800489A0: lh          $t7, 0x8($a2)
        ctx->r15 = MEM_H(ctx->r6, 0X8);
            goto L_800489F4;
    }
    goto skip_4;
    // 0x800489A0: lh          $t7, 0x8($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X8);
    skip_4:
    // 0x800489A4: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800489A8: lwl         $t7, 0x2($v0)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r2, 0X2);
L_800489AC:
    // 0x800489AC: lwr         $t7, 0x5($v0)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r2, 0X5);
    // 0x800489B0: bnel        $a0, $t7, L_800489E4
    if (ctx->r4 != ctx->r15) {
        // 0x800489B4: lh          $t6, 0x38($v0)
        ctx->r14 = MEM_H(ctx->r2, 0X38);
            goto L_800489E4;
    }
    goto skip_5;
    // 0x800489B4: lh          $t6, 0x38($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X38);
    skip_5:
    // 0x800489B8: lwl         $t9, 0x6($v0)
    ctx->r25 = do_lwl(rdram, ctx->r25, ctx->r2, 0X6);
    // 0x800489BC: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x800489C0: lwr         $t9, 0x9($v0)
    ctx->r25 = do_lwr(rdram, ctx->r25, ctx->r2, 0X9);
    // 0x800489C4: bnel        $t8, $t9, L_800489E4
    if (ctx->r24 != ctx->r25) {
        // 0x800489C8: lh          $t6, 0x38($v0)
        ctx->r14 = MEM_H(ctx->r2, 0X38);
            goto L_800489E4;
    }
    goto skip_6;
    // 0x800489C8: lh          $t6, 0x38($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X38);
    skip_6:
    // 0x800489CC: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800489D0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800489D4: swc1        $f8, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f8.u32l;
    // 0x800489D8: b           L_80048B4C
    // 0x800489DC: sw          $t5, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r13;
        goto L_80048B4C;
    // 0x800489DC: sw          $t5, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r13;
    // 0x800489E0: lh          $t6, 0x38($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X38);
L_800489E4:
    // 0x800489E4: addiu       $v0, $v0, 0x38
    ctx->r2 = ADD32(ctx->r2, 0X38);
    // 0x800489E8: bnel        $t6, $zero, L_800489AC
    if (ctx->r14 != 0) {
        // 0x800489EC: lwl         $t7, 0x2($v0)
        ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r2, 0X2);
            goto L_800489AC;
    }
    goto skip_7;
    // 0x800489EC: lwl         $t7, 0x2($v0)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r2, 0X2);
    skip_7:
    // 0x800489F0: lh          $t7, 0x8($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X8);
L_800489F4:
    // 0x800489F4: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x800489F8: bnel        $t7, $zero, L_80048990
    if (ctx->r15 != 0) {
        // 0x800489FC: lw          $a1, 0x4($a2)
        ctx->r5 = MEM_W(ctx->r6, 0X4);
            goto L_80048990;
    }
    goto skip_8;
    // 0x800489FC: lw          $a1, 0x4($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X4);
    skip_8:
    // 0x80048A00: b           L_80048B4C
    // 0x80048A04: nop

        goto L_80048B4C;
    // 0x80048A04: nop

L_80048A08:
    // 0x80048A08: beq         $s4, $t8, L_80048B4C
    if (ctx->r20 == ctx->r24) {
        // 0x80048A0C: nop
    
            goto L_80048B4C;
    }
    // 0x80048A0C: nop

    // 0x80048A10: beq         $t8, $zero, L_80048ACC
    if (ctx->r24 == 0) {
        // 0x80048A14: lw          $t9, 0x194($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X194);
            goto L_80048ACC;
    }
    // 0x80048A14: lw          $t9, 0x194($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X194);
    // 0x80048A18: sh          $t9, 0x8C($t8)
    MEM_H(0X8C, ctx->r24) = ctx->r25;
    // 0x80048A1C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80048A20: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80048A24: or          $v1, $s5, $zero
    ctx->r3 = ctx->r21 | 0;
L_80048A28:
    // 0x80048A28: lbu         $t5, 0x10($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X10);
    // 0x80048A2C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80048A30: slti        $at, $s0, 0x8
    ctx->r1 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x80048A34: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80048A38: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80048A3C: bne         $at, $zero, L_80048A28
    if (ctx->r1 != 0) {
        // 0x80048A40: sb          $t5, 0x83($v0)
        MEM_B(0X83, ctx->r2) = ctx->r13;
            goto L_80048A28;
    }
    // 0x80048A40: sb          $t5, 0x83($v0)
    MEM_B(0X83, ctx->r2) = ctx->r13;
    // 0x80048A44: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x80048A48: lwc1        $f10, 0x1C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80048A4C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80048A50: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x80048A54: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80048A58: swc1        $f10, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f10.u32l;
L_80048A5C:
    // 0x80048A5C: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80048A60: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80048A64: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80048A68: swc1        $f16, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f16.u32l;
    // 0x80048A6C: lwc1        $f18, 0x8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80048A70: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80048A74: bne         $s0, $s2, L_80048A5C
    if (ctx->r16 != ctx->r18) {
        // 0x80048A78: swc1        $f18, 0x18($v0)
        MEM_W(0X18, ctx->r2) = ctx->f18.u32l;
            goto L_80048A5C;
    }
    // 0x80048A78: swc1        $f18, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f18.u32l;
    // 0x80048A7C: lw          $t9, 0xF4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF4);
    // 0x80048A80: lw          $t6, 0xF8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF8);
    // 0x80048A84: andi        $t5, $t9, 0x1
    ctx->r13 = ctx->r25 & 0X1;
    // 0x80048A88: lw          $t9, 0xF0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF0);
    // 0x80048A8C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80048A90: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80048A94: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80048A98: andi        $t5, $t9, 0x1
    ctx->r13 = ctx->r25 & 0X1;
    // 0x80048A9C: lw          $t9, 0xE8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE8);
    // 0x80048AA0: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x80048AA4: sll         $t8, $t5, 3
    ctx->r24 = S32(ctx->r13 << 3);
    // 0x80048AA8: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x80048AAC: andi        $t5, $t9, 0x3F
    ctx->r13 = ctx->r25 & 0X3F;
    // 0x80048AB0: sll         $t7, $t5, 16
    ctx->r15 = S32(ctx->r13 << 16);
    // 0x80048AB4: lw          $t5, 0xEC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XEC);
    // 0x80048AB8: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80048ABC: sh          $zero, 0x7C($a0)
    MEM_H(0X7C, ctx->r4) = 0;
    // 0x80048AC0: sll         $t6, $t5, 31
    ctx->r14 = S32(ctx->r13 << 31);
    // 0x80048AC4: or          $v0, $t8, $t6
    ctx->r2 = ctx->r24 | ctx->r14;
    // 0x80048AC8: sw          $v0, 0x80($a0)
    MEM_W(0X80, ctx->r4) = ctx->r2;
L_80048ACC:
    // 0x80048ACC: lh          $t7, 0x8C($s4)
    ctx->r15 = MEM_H(ctx->r20, 0X8C);
    // 0x80048AD0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80048AD4: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x80048AD8: sw          $t7, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r15;
    // 0x80048ADC: lwc1        $f4, 0x2C($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X2C);
    // 0x80048AE0: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x80048AE4: swc1        $f4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f4.u32l;
L_80048AE8:
    // 0x80048AE8: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80048AEC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80048AF0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80048AF4: swc1        $f6, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f6.u32l;
    // 0x80048AF8: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80048AFC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80048B00: bne         $s0, $s2, L_80048AE8
    if (ctx->r16 != ctx->r18) {
        // 0x80048B04: swc1        $f8, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
            goto L_80048AE8;
    }
    // 0x80048B04: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
    // 0x80048B08: sw          $s4, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r20;
    // 0x80048B0C: lw          $v0, 0x80($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X80);
    // 0x80048B10: srl         $t9, $v0, 1
    ctx->r25 = S32(U32(ctx->r2) >> 1);
    // 0x80048B14: andi        $t5, $t9, 0x1
    ctx->r13 = ctx->r25 & 0X1;
    // 0x80048B18: srl         $t8, $v0, 2
    ctx->r24 = S32(U32(ctx->r2) >> 2);
    // 0x80048B1C: sw          $t5, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r13;
    // 0x80048B20: andi        $t6, $t8, 0x1
    ctx->r14 = ctx->r24 & 0X1;
    // 0x80048B24: srl         $t7, $v0, 16
    ctx->r15 = S32(U32(ctx->r2) >> 16);
    // 0x80048B28: srl         $t5, $v0, 31
    ctx->r13 = S32(U32(ctx->r2) >> 31);
    // 0x80048B2C: sw          $t6, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r14;
    // 0x80048B30: andi        $t9, $t7, 0x3F
    ctx->r25 = ctx->r15 & 0X3F;
    // 0x80048B34: andi        $t8, $t5, 0x1
    ctx->r24 = ctx->r13 & 0X1;
    // 0x80048B38: sw          $t9, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r25;
    // 0x80048B3C: sw          $t8, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r24;
    // 0x80048B40: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80048B44: b           L_800488D0
    // 0x80048B48: sh          $t6, 0x7C($s4)
    MEM_H(0X7C, ctx->r20) = ctx->r14;
        goto L_800488D0;
    // 0x80048B48: sh          $t6, 0x7C($s4)
    MEM_H(0X7C, ctx->r20) = ctx->r14;
L_80048B4C:
    // 0x80048B4C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80048B50: lhu         $v1, -0x2E5C($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2E5C);
    // 0x80048B54: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80048B58: andi        $v0, $v1, 0x20
    ctx->r2 = ctx->r3 & 0X20;
    // 0x80048B5C: beq         $v0, $zero, L_80048D34
    if (ctx->r2 == 0) {
        // 0x80048B60: nop
    
            goto L_80048D34;
    }
    // 0x80048B60: nop

    // 0x80048B64: lhu         $t7, -0x2E5A($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X2E5A);
    // 0x80048B68: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80048B6C: andi        $t9, $t7, 0x2000
    ctx->r25 = ctx->r15 & 0X2000;
    // 0x80048B70: beq         $t9, $zero, L_80048D34
    if (ctx->r25 == 0) {
        // 0x80048B74: nop
    
            goto L_80048D34;
    }
    // 0x80048B74: nop

    // 0x80048B78: beq         $s6, $at, L_80048B94
    if (ctx->r22 == ctx->r1) {
        // 0x80048B7C: lui         $a0, 0x801A
        ctx->r4 = S32(0X801A << 16);
            goto L_80048B94;
    }
    // 0x80048B7C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80048B80: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80048B84: beql        $s6, $at, L_80048CC4
    if (ctx->r22 == ctx->r1) {
        // 0x80048B88: lw          $a0, 0x4($s4)
        ctx->r4 = MEM_W(ctx->r20, 0X4);
            goto L_80048CC4;
    }
    goto skip_9;
    // 0x80048B88: lw          $a0, 0x4($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X4);
    skip_9:
    // 0x80048B8C: b           L_80048D34
    // 0x80048B90: nop

        goto L_80048D34;
    // 0x80048B90: nop

L_80048B94:
    // 0x80048B94: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80048B98: addiu       $a1, $zero, 0xCC
    ctx->r5 = ADD32(0, 0XCC);
    // 0x80048B9C: jal         0x80004364
    // 0x80048BA0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    func_80004364(rdram, ctx);
        goto after_45;
    // 0x80048BA0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_45:
    // 0x80048BA4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80048BA8: addiu       $a1, $zero, 0xCC
    ctx->r5 = ADD32(0, 0XCC);
    // 0x80048BAC: jal         0x8000C7C0
    // 0x80048BB0: sw          $v0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r2;
    func_8000C7C0(rdram, ctx);
        goto after_46;
    // 0x80048BB0: sw          $v0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r2;
    after_46:
    // 0x80048BB4: lw          $a2, 0xA8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA8);
    // 0x80048BB8: lw          $t5, 0x194($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X194);
    // 0x80048BBC: or          $v1, $s5, $zero
    ctx->r3 = ctx->r21 | 0;
    // 0x80048BC0: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80048BC4: sh          $t5, 0x8C($a2)
    MEM_H(0X8C, ctx->r6) = ctx->r13;
L_80048BC8:
    // 0x80048BC8: lbu         $t8, 0x10($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X10);
    // 0x80048BCC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80048BD0: slti        $at, $s0, 0x8
    ctx->r1 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x80048BD4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80048BD8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80048BDC: bne         $at, $zero, L_80048BC8
    if (ctx->r1 != 0) {
        // 0x80048BE0: sb          $t8, 0x83($v0)
        MEM_B(0X83, ctx->r2) = ctx->r24;
            goto L_80048BC8;
    }
    // 0x80048BE0: sb          $t8, 0x83($v0)
    MEM_B(0X83, ctx->r2) = ctx->r24;
    // 0x80048BE4: lwc1        $f10, 0x1C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80048BE8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80048BEC: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x80048BF0: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80048BF4: swc1        $f10, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->f10.u32l;
L_80048BF8:
    // 0x80048BF8: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80048BFC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80048C00: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80048C04: swc1        $f16, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f16.u32l;
    // 0x80048C08: lwc1        $f18, 0x8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80048C0C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80048C10: bne         $s0, $s2, L_80048BF8
    if (ctx->r16 != ctx->r18) {
        // 0x80048C14: swc1        $f18, 0x18($v0)
        MEM_W(0X18, ctx->r2) = ctx->f18.u32l;
            goto L_80048BF8;
    }
    // 0x80048C14: swc1        $f18, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f18.u32l;
    // 0x80048C18: lw          $v1, 0xF8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XF8);
    // 0x80048C1C: lw          $a3, 0xE8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XE8);
    // 0x80048C20: lw          $a0, 0xF4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XF4);
    // 0x80048C24: andi        $t6, $v1, 0x1
    ctx->r14 = ctx->r3 & 0X1;
    // 0x80048C28: sll         $v1, $t6, 1
    ctx->r3 = S32(ctx->r14 << 1);
    // 0x80048C2C: lw          $t6, 0x80($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X80);
    // 0x80048C30: lw          $a1, 0xF0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XF0);
    // 0x80048C34: lw          $t5, 0xEC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XEC);
    // 0x80048C38: andi        $t7, $a3, 0x3F
    ctx->r15 = ctx->r7 & 0X3F;
    // 0x80048C3C: sll         $a3, $t7, 16
    ctx->r7 = S32(ctx->r15 << 16);
    // 0x80048C40: andi        $t9, $a0, 0x1
    ctx->r25 = ctx->r4 & 0X1;
    // 0x80048C44: or          $t7, $t6, $v1
    ctx->r15 = ctx->r14 | ctx->r3;
    // 0x80048C48: sll         $a0, $t9, 2
    ctx->r4 = S32(ctx->r25 << 2);
    // 0x80048C4C: andi        $t8, $a1, 0x1
    ctx->r24 = ctx->r5 & 0X1;
    // 0x80048C50: sll         $t0, $t5, 31
    ctx->r8 = S32(ctx->r13 << 31);
    // 0x80048C54: sll         $a1, $t8, 3
    ctx->r5 = S32(ctx->r24 << 3);
    // 0x80048C58: or          $t5, $t7, $a0
    ctx->r13 = ctx->r15 | ctx->r4;
    // 0x80048C5C: sw          $t7, 0x80($a2)
    MEM_W(0X80, ctx->r6) = ctx->r15;
    // 0x80048C60: or          $t6, $t5, $a1
    ctx->r14 = ctx->r13 | ctx->r5;
    // 0x80048C64: sw          $t5, 0x80($a2)
    MEM_W(0X80, ctx->r6) = ctx->r13;
    // 0x80048C68: or          $t9, $t6, $a3
    ctx->r25 = ctx->r14 | ctx->r7;
    // 0x80048C6C: sw          $t6, 0x80($a2)
    MEM_W(0X80, ctx->r6) = ctx->r14;
    // 0x80048C70: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80048C74: sw          $t9, 0x80($a2)
    MEM_W(0X80, ctx->r6) = ctx->r25;
    // 0x80048C78: or          $t8, $t9, $t0
    ctx->r24 = ctx->r25 | ctx->r8;
    // 0x80048C7C: addiu       $v0, $v0, -0x659C
    ctx->r2 = ADD32(ctx->r2, -0X659C);
    // 0x80048C80: sw          $t8, 0x80($a2)
    MEM_W(0X80, ctx->r6) = ctx->r24;
    // 0x80048C84: sh          $zero, 0x7C($a2)
    MEM_H(0X7C, ctx->r6) = 0;
    // 0x80048C88: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80048C8C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80048C90: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80048C94: sw          $a2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r6;
    // 0x80048C98: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80048C9C: lw          $t5, 0x4($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X4);
    // 0x80048CA0: sw          $t5, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r13;
    // 0x80048CA4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80048CA8: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80048CAC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80048CB0: sw          $a2, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r6;
    // 0x80048CB4: lhu         $v1, -0x2E5C($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2E5C);
    // 0x80048CB8: b           L_80048D34
    // 0x80048CBC: andi        $v0, $v1, 0x20
    ctx->r2 = ctx->r3 & 0X20;
        goto L_80048D34;
    // 0x80048CBC: andi        $v0, $v1, 0x20
    ctx->r2 = ctx->r3 & 0X20;
    // 0x80048CC0: lw          $a0, 0x4($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X4);
L_80048CC4:
    // 0x80048CC4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80048CC8: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x80048CCC: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x80048CD0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80048CD4: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80048CD8: bne         $t7, $zero, L_80048CF8
    if (ctx->r15 != 0) {
        // 0x80048CDC: nop
    
            goto L_80048CF8;
    }
    // 0x80048CDC: nop

    // 0x80048CE0: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x80048CE4: sw          $t9, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r25;
    // 0x80048CE8: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x80048CEC: bne         $t8, $zero, L_80048CF8
    if (ctx->r24 != 0) {
        // 0x80048CF0: nop
    
            goto L_80048CF8;
    }
    // 0x80048CF0: nop

    // 0x80048CF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80048CF8:
    // 0x80048CF8: beq         $a1, $zero, L_80048D34
    if (ctx->r5 == 0) {
        // 0x80048CFC: nop
    
            goto L_80048D34;
    }
    // 0x80048CFC: nop

    // 0x80048D00: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80048D04: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x80048D08: lw          $s4, 0x80($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X80);
    // 0x80048D0C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80048D10: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80048D14: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x80048D18: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x80048D1C: addiu       $a2, $a2, -0x6C60
    ctx->r6 = ADD32(ctx->r6, -0X6C60);
    // 0x80048D20: jal         0x8001026C
    // 0x80048D24: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    func_8001026C(rdram, ctx);
        goto after_47;
    // 0x80048D24: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    after_47:
    // 0x80048D28: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80048D2C: lhu         $v1, -0x2E5C($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2E5C);
    // 0x80048D30: andi        $v0, $v1, 0x20
    ctx->r2 = ctx->r3 & 0X20;
L_80048D34:
    // 0x80048D34: bne         $v0, $zero, L_80048E10
    if (ctx->r2 != 0) {
        // 0x80048D38: andi        $t8, $v1, 0x10
        ctx->r24 = ctx->r3 & 0X10;
            goto L_80048E10;
    }
    // 0x80048D38: andi        $t8, $v1, 0x10
    ctx->r24 = ctx->r3 & 0X10;
    // 0x80048D3C: bne         $t8, $zero, L_80048E10
    if (ctx->r24 != 0) {
        // 0x80048D40: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_80048E10;
    }
    // 0x80048D40: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80048D44: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80048D48: andi        $t6, $v1, 0x2000
    ctx->r14 = ctx->r3 & 0X2000;
    // 0x80048D4C: beq         $t6, $zero, L_80048D60
    if (ctx->r14 == 0) {
        // 0x80048D50: andi        $t7, $v1, 0x200
        ctx->r15 = ctx->r3 & 0X200;
            goto L_80048D60;
    }
    // 0x80048D50: andi        $t7, $v1, 0x200
    ctx->r15 = ctx->r3 & 0X200;
    // 0x80048D54: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80048D58: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80048D5C: nop

L_80048D60:
    // 0x80048D60: beq         $t7, $zero, L_80048D80
    if (ctx->r15 == 0) {
        // 0x80048D64: andi        $t9, $v1, 0x100
        ctx->r25 = ctx->r3 & 0X100;
            goto L_80048D80;
    }
    // 0x80048D64: andi        $t9, $v1, 0x100
    ctx->r25 = ctx->r3 & 0X100;
    // 0x80048D68: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80048D6C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80048D70: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80048D74: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
    // 0x80048D78: b           L_80048D9C
    // 0x80048D7C: lhu         $v1, -0x2E5C($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2E5C);
        goto L_80048D9C;
    // 0x80048D7C: lhu         $v1, -0x2E5C($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2E5C);
L_80048D80:
    // 0x80048D80: beql        $t9, $zero, L_80048DA0
    if (ctx->r25 == 0) {
        // 0x80048D84: andi        $t5, $v1, 0x800
        ctx->r13 = ctx->r3 & 0X800;
            goto L_80048DA0;
    }
    goto skip_10;
    // 0x80048D84: andi        $t5, $v1, 0x800
    ctx->r13 = ctx->r3 & 0X800;
    skip_10:
    // 0x80048D88: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80048D8C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80048D90: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x80048D94: swc1        $f10, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
    // 0x80048D98: lhu         $v1, -0x2E5C($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2E5C);
L_80048D9C:
    // 0x80048D9C: andi        $t5, $v1, 0x800
    ctx->r13 = ctx->r3 & 0X800;
L_80048DA0:
    // 0x80048DA0: beq         $t5, $zero, L_80048DC0
    if (ctx->r13 == 0) {
        // 0x80048DA4: andi        $t8, $v1, 0x400
        ctx->r24 = ctx->r3 & 0X400;
            goto L_80048DC0;
    }
    // 0x80048DA4: andi        $t8, $v1, 0x400
    ctx->r24 = ctx->r3 & 0X400;
    // 0x80048DA8: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80048DAC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80048DB0: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x80048DB4: swc1        $f18, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f18.u32l;
    // 0x80048DB8: b           L_80048DDC
    // 0x80048DBC: lhu         $v1, -0x2E5C($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2E5C);
        goto L_80048DDC;
    // 0x80048DBC: lhu         $v1, -0x2E5C($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2E5C);
L_80048DC0:
    // 0x80048DC0: beql        $t8, $zero, L_80048DE0
    if (ctx->r24 == 0) {
        // 0x80048DC4: andi        $t6, $v1, 0x4000
        ctx->r14 = ctx->r3 & 0X4000;
            goto L_80048DE0;
    }
    goto skip_11;
    // 0x80048DC4: andi        $t6, $v1, 0x4000
    ctx->r14 = ctx->r3 & 0X4000;
    skip_11:
    // 0x80048DC8: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80048DCC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80048DD0: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80048DD4: swc1        $f6, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f6.u32l;
    // 0x80048DD8: lhu         $v1, -0x2E5C($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2E5C);
L_80048DDC:
    // 0x80048DDC: andi        $t6, $v1, 0x4000
    ctx->r14 = ctx->r3 & 0X4000;
L_80048DE0:
    // 0x80048DE0: beq         $t6, $zero, L_80048DF8
    if (ctx->r14 == 0) {
        // 0x80048DE4: andi        $t7, $v1, 0x8000
        ctx->r15 = ctx->r3 & 0X8000;
            goto L_80048DF8;
    }
    // 0x80048DE4: andi        $t7, $v1, 0x8000
    ctx->r15 = ctx->r3 & 0X8000;
    // 0x80048DE8: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80048DEC: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x80048DF0: b           L_80048F64
    // 0x80048DF4: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
        goto L_80048F64;
    // 0x80048DF4: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
L_80048DF8:
    // 0x80048DF8: beq         $t7, $zero, L_80048F64
    if (ctx->r15 == 0) {
        // 0x80048DFC: nop
    
            goto L_80048F64;
    }
    // 0x80048DFC: nop

    // 0x80048E00: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80048E04: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x80048E08: b           L_80048F64
    // 0x80048E0C: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
        goto L_80048F64;
    // 0x80048E0C: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
L_80048E10:
    // 0x80048E10: beq         $v0, $zero, L_80048F64
    if (ctx->r2 == 0) {
        // 0x80048E14: andi        $t9, $v1, 0x10
        ctx->r25 = ctx->r3 & 0X10;
            goto L_80048F64;
    }
    // 0x80048E14: andi        $t9, $v1, 0x10
    ctx->r25 = ctx->r3 & 0X10;
    // 0x80048E18: bne         $t9, $zero, L_80048F64
    if (ctx->r25 != 0) {
        // 0x80048E1C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80048F64;
    }
    // 0x80048E1C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80048E20: beq         $s6, $at, L_80048E3C
    if (ctx->r22 == ctx->r1) {
        // 0x80048E24: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_80048E3C;
    }
    // 0x80048E24: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80048E28: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80048E2C: beq         $s6, $at, L_80048E88
    if (ctx->r22 == ctx->r1) {
        // 0x80048E30: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_80048E88;
    }
    // 0x80048E30: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80048E34: b           L_80048EE0
    // 0x80048E38: andi        $t7, $v1, 0x800
    ctx->r15 = ctx->r3 & 0X800;
        goto L_80048EE0;
    // 0x80048E38: andi        $t7, $v1, 0x800
    ctx->r15 = ctx->r3 & 0X800;
L_80048E3C:
    // 0x80048E3C: lhu         $v0, -0x2E58($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2E58);
    // 0x80048E40: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80048E44: lw          $a0, 0x194($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X194);
    // 0x80048E48: andi        $t5, $v0, 0x200
    ctx->r13 = ctx->r2 & 0X200;
    // 0x80048E4C: beq         $t5, $zero, L_80048E5C
    if (ctx->r13 == 0) {
        // 0x80048E50: andi        $t8, $v0, 0x100
        ctx->r24 = ctx->r2 & 0X100;
            goto L_80048E5C;
    }
    // 0x80048E50: andi        $t8, $v0, 0x100
    ctx->r24 = ctx->r2 & 0X100;
    // 0x80048E54: b           L_80048E68
    // 0x80048E58: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_80048E68;
    // 0x80048E58: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80048E5C:
    // 0x80048E5C: beq         $t8, $zero, L_80048E68
    if (ctx->r24 == 0) {
        // 0x80048E60: nop
    
            goto L_80048E68;
    }
    // 0x80048E60: nop

    // 0x80048E64: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_80048E68:
    // 0x80048E68: beql        $a2, $zero, L_80048EE0
    if (ctx->r6 == 0) {
        // 0x80048E6C: andi        $t7, $v1, 0x800
        ctx->r15 = ctx->r3 & 0X800;
            goto L_80048EE0;
    }
    goto skip_12;
    // 0x80048E6C: andi        $t7, $v1, 0x800
    ctx->r15 = ctx->r3 & 0X800;
    skip_12:
    // 0x80048E70: jal         0x80049CB0
    // 0x80048E74: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80049CB0(rdram, ctx);
        goto after_48;
    // 0x80048E74: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_48:
    // 0x80048E78: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80048E7C: lhu         $v1, -0x2E5C($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2E5C);
    // 0x80048E80: b           L_80048EDC
    // 0x80048E84: sw          $v0, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r2;
        goto L_80048EDC;
    // 0x80048E84: sw          $v0, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r2;
L_80048E88:
    // 0x80048E88: lhu         $v0, -0x2E58($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2E58);
    // 0x80048E8C: andi        $t6, $v0, 0x200
    ctx->r14 = ctx->r2 & 0X200;
    // 0x80048E90: beq         $t6, $zero, L_80048EB8
    if (ctx->r14 == 0) {
        // 0x80048E94: andi        $t5, $v0, 0x100
        ctx->r13 = ctx->r2 & 0X100;
            goto L_80048EB8;
    }
    // 0x80048E94: andi        $t5, $v0, 0x100
    ctx->r13 = ctx->r2 & 0X100;
    // 0x80048E98: lw          $s4, 0x0($s4)
    ctx->r20 = MEM_W(ctx->r20, 0X0);
    // 0x80048E9C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80048EA0: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x80048EA4: bnel        $t7, $zero, L_80048EE0
    if (ctx->r15 != 0) {
        // 0x80048EA8: andi        $t7, $v1, 0x800
        ctx->r15 = ctx->r3 & 0X800;
            goto L_80048EE0;
    }
    goto skip_13;
    // 0x80048EA8: andi        $t7, $v1, 0x800
    ctx->r15 = ctx->r3 & 0X800;
    skip_13:
    // 0x80048EAC: lw          $t9, -0x65A0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X65A0);
    // 0x80048EB0: b           L_80048EDC
    // 0x80048EB4: lw          $s4, 0x0($t9)
    ctx->r20 = MEM_W(ctx->r25, 0X0);
        goto L_80048EDC;
    // 0x80048EB4: lw          $s4, 0x0($t9)
    ctx->r20 = MEM_W(ctx->r25, 0X0);
L_80048EB8:
    // 0x80048EB8: beql        $t5, $zero, L_80048EE0
    if (ctx->r13 == 0) {
        // 0x80048EBC: andi        $t7, $v1, 0x800
        ctx->r15 = ctx->r3 & 0X800;
            goto L_80048EE0;
    }
    goto skip_14;
    // 0x80048EBC: andi        $t7, $v1, 0x800
    ctx->r15 = ctx->r3 & 0X800;
    skip_14:
    // 0x80048EC0: lw          $s4, 0x4($s4)
    ctx->r20 = MEM_W(ctx->r20, 0X4);
    // 0x80048EC4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80048EC8: lw          $t8, 0x4($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X4);
    // 0x80048ECC: bnel        $t8, $zero, L_80048EE0
    if (ctx->r24 != 0) {
        // 0x80048ED0: andi        $t7, $v1, 0x800
        ctx->r15 = ctx->r3 & 0X800;
            goto L_80048EE0;
    }
    goto skip_15;
    // 0x80048ED0: andi        $t7, $v1, 0x800
    ctx->r15 = ctx->r3 & 0X800;
    skip_15:
    // 0x80048ED4: lw          $t6, -0x659C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X659C);
    // 0x80048ED8: lw          $s4, 0x4($t6)
    ctx->r20 = MEM_W(ctx->r14, 0X4);
L_80048EDC:
    // 0x80048EDC: andi        $t7, $v1, 0x800
    ctx->r15 = ctx->r3 & 0X800;
L_80048EE0:
    // 0x80048EE0: beq         $t7, $zero, L_80048F08
    if (ctx->r15 == 0) {
        // 0x80048EE4: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_80048F08;
    }
    // 0x80048EE4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80048EE8: lwc1        $f4, 0x1C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80048EEC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80048EF0: ldc1        $f8, 0x7F78($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X7F78);
    // 0x80048EF4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80048EF8: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x80048EFC: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80048F00: b           L_80048F30
    // 0x80048F04: swc1        $f16, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f16.u32l;
        goto L_80048F30;
    // 0x80048F04: swc1        $f16, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f16.u32l;
L_80048F08:
    // 0x80048F08: andi        $t9, $v1, 0x400
    ctx->r25 = ctx->r3 & 0X400;
    // 0x80048F0C: beq         $t9, $zero, L_80048F30
    if (ctx->r25 == 0) {
        // 0x80048F10: nop
    
            goto L_80048F30;
    }
    // 0x80048F10: nop

    // 0x80048F14: lwc1        $f18, 0x1C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80048F18: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80048F1C: ldc1        $f6, 0x7F80($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X7F80);
    // 0x80048F20: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80048F24: sub.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d - ctx->f6.d;
    // 0x80048F28: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80048F2C: swc1        $f10, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f10.u32l;
L_80048F30:
    // 0x80048F30: lhu         $v0, -0x2E5A($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2E5A);
    // 0x80048F34: lw          $t8, 0xF8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF8);
    // 0x80048F38: andi        $t5, $v0, 0x8000
    ctx->r13 = ctx->r2 & 0X8000;
    // 0x80048F3C: beq         $t5, $zero, L_80048F4C
    if (ctx->r13 == 0) {
        // 0x80048F40: andi        $t7, $v0, 0x4000
        ctx->r15 = ctx->r2 & 0X4000;
            goto L_80048F4C;
    }
    // 0x80048F40: andi        $t7, $v0, 0x4000
    ctx->r15 = ctx->r2 & 0X4000;
    // 0x80048F44: xori        $t6, $t8, 0x1
    ctx->r14 = ctx->r24 ^ 0X1;
    // 0x80048F48: sw          $t6, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r14;
L_80048F4C:
    // 0x80048F4C: beq         $t7, $zero, L_80048F64
    if (ctx->r15 == 0) {
        // 0x80048F50: lw          $t9, 0xE8($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XE8);
            goto L_80048F64;
    }
    // 0x80048F50: lw          $t9, 0xE8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE8);
    // 0x80048F54: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x80048F58: sw          $t5, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r13;
    // 0x80048F5C: andi        $t8, $t5, 0x3F
    ctx->r24 = ctx->r13 & 0X3F;
    // 0x80048F60: sw          $t8, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r24;
L_80048F64:
    // 0x80048F64: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80048F68: lhu         $v1, -0x2E5C($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2E5C);
    // 0x80048F6C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80048F70: lwc1        $f0, 0x7F88($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7F88);
    // 0x80048F74: andi        $t6, $v1, 0x2000
    ctx->r14 = ctx->r3 & 0X2000;
    // 0x80048F78: beq         $t6, $zero, L_80048F88
    if (ctx->r14 == 0) {
        // 0x80048F7C: andi        $v0, $v1, 0x10
        ctx->r2 = ctx->r3 & 0X10;
            goto L_80048F88;
    }
    // 0x80048F7C: andi        $v0, $v1, 0x10
    ctx->r2 = ctx->r3 & 0X10;
    // 0x80048F80: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80048F84: lwc1        $f0, 0x7F8C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7F8C);
L_80048F88:
    // 0x80048F88: bne         $v0, $zero, L_80049064
    if (ctx->r2 != 0) {
        // 0x80048F8C: andi        $t7, $v1, 0x20
        ctx->r15 = ctx->r3 & 0X20;
            goto L_80049064;
    }
    // 0x80048F8C: andi        $t7, $v1, 0x20
    ctx->r15 = ctx->r3 & 0X20;
    // 0x80048F90: bne         $t7, $zero, L_80049064
    if (ctx->r15 != 0) {
        // 0x80048F94: nop
    
            goto L_80049064;
    }
    // 0x80048F94: nop

    // 0x80048F98: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80048F9C: lh          $v0, -0x2E60($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2E60);
    // 0x80048FA0: slti        $at, $v0, 0x1A
    ctx->r1 = SIGNED(ctx->r2) < 0X1A ? 1 : 0;
    // 0x80048FA4: bnel        $at, $zero, L_80048FC0
    if (ctx->r1 != 0) {
        // 0x80048FA8: slti        $at, $v0, -0x19
        ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
            goto L_80048FC0;
    }
    goto skip_16;
    // 0x80048FA8: slti        $at, $v0, -0x19
    ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
    skip_16:
    // 0x80048FAC: lwc1        $f16, 0x10($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80048FB0: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x80048FB4: b           L_80048FD4
    // 0x80048FB8: swc1        $f18, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f18.u32l;
        goto L_80048FD4;
    // 0x80048FB8: swc1        $f18, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f18.u32l;
    // 0x80048FBC: slti        $at, $v0, -0x19
    ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
L_80048FC0:
    // 0x80048FC0: beq         $at, $zero, L_80048FD4
    if (ctx->r1 == 0) {
        // 0x80048FC4: nop
    
            goto L_80048FD4;
    }
    // 0x80048FC4: nop

    // 0x80048FC8: lwc1        $f4, 0x10($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80048FCC: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80048FD0: swc1        $f6, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f6.u32l;
L_80048FD4:
    // 0x80048FD4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80048FD8: lh          $v0, -0x2E5E($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2E5E);
    // 0x80048FDC: slti        $at, $v0, 0x1A
    ctx->r1 = SIGNED(ctx->r2) < 0X1A ? 1 : 0;
    // 0x80048FE0: bnel        $at, $zero, L_80049024
    if (ctx->r1 != 0) {
        // 0x80048FE4: slti        $at, $v0, -0x19
        ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
            goto L_80049024;
    }
    goto skip_17;
    // 0x80048FE4: slti        $at, $v0, -0x19
    ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
    skip_17:
    // 0x80048FE8: lwc1        $f8, 0x18($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X18);
    // 0x80048FEC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80048FF0: ldc1        $f10, 0x7F90($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X7F90);
    // 0x80048FF4: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x80048FF8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80048FFC: c.lt.d      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.d < ctx->f0.d;
    // 0x80049000: nop

    // 0x80049004: bc1fl       L_80049024
    if (!c1cs) {
        // 0x80049008: slti        $at, $v0, -0x19
        ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
            goto L_80049024;
    }
    goto skip_18;
    // 0x80049008: slti        $at, $v0, -0x19
    ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
    skip_18:
    // 0x8004900C: ldc1        $f16, 0x7F98($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, 0X7F98);
    // 0x80049010: sub.d       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f0.d - ctx->f16.d;
    // 0x80049014: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80049018: b           L_800490E8
    // 0x8004901C: swc1        $f4, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f4.u32l;
        goto L_800490E8;
    // 0x8004901C: swc1        $f4, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f4.u32l;
    // 0x80049020: slti        $at, $v0, -0x19
    ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
L_80049024:
    // 0x80049024: beq         $at, $zero, L_800490E8
    if (ctx->r1 == 0) {
        // 0x80049028: nop
    
            goto L_800490E8;
    }
    // 0x80049028: nop

    // 0x8004902C: lwc1        $f6, 0x18($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X18);
    // 0x80049030: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80049034: ldc1        $f8, 0x7FA0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X7FA0);
    // 0x80049038: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x8004903C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80049040: c.lt.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d < ctx->f8.d;
    // 0x80049044: nop

    // 0x80049048: bc1f        L_800490E8
    if (!c1cs) {
        // 0x8004904C: nop
    
            goto L_800490E8;
    }
    // 0x8004904C: nop

    // 0x80049050: ldc1        $f10, 0x7FA8($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X7FA8);
    // 0x80049054: add.d       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f0.d + ctx->f10.d;
    // 0x80049058: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8004905C: b           L_800490E8
    // 0x80049060: swc1        $f18, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f18.u32l;
        goto L_800490E8;
    // 0x80049060: swc1        $f18, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f18.u32l;
L_80049064:
    // 0x80049064: beq         $v0, $zero, L_800490E8
    if (ctx->r2 == 0) {
        // 0x80049068: andi        $t9, $v1, 0x20
        ctx->r25 = ctx->r3 & 0X20;
            goto L_800490E8;
    }
    // 0x80049068: andi        $t9, $v1, 0x20
    ctx->r25 = ctx->r3 & 0X20;
    // 0x8004906C: bne         $t9, $zero, L_800490E8
    if (ctx->r25 != 0) {
        // 0x80049070: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_800490E8;
    }
    // 0x80049070: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80049074: lh          $v0, -0x2E60($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2E60);
    // 0x80049078: slti        $at, $v0, 0x1A
    ctx->r1 = SIGNED(ctx->r2) < 0X1A ? 1 : 0;
    // 0x8004907C: bnel        $at, $zero, L_80049098
    if (ctx->r1 != 0) {
        // 0x80049080: slti        $at, $v0, -0x19
        ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
            goto L_80049098;
    }
    goto skip_19;
    // 0x80049080: slti        $at, $v0, -0x19
    ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
    skip_19:
    // 0x80049084: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80049088: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8004908C: b           L_800490AC
    // 0x80049090: swc1        $f6, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f6.u32l;
        goto L_800490AC;
    // 0x80049090: swc1        $f6, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f6.u32l;
    // 0x80049094: slti        $at, $v0, -0x19
    ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
L_80049098:
    // 0x80049098: beq         $at, $zero, L_800490AC
    if (ctx->r1 == 0) {
        // 0x8004909C: nop
    
            goto L_800490AC;
    }
    // 0x8004909C: nop

    // 0x800490A0: lwc1        $f8, 0x14($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800490A4: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800490A8: swc1        $f10, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f10.u32l;
L_800490AC:
    // 0x800490AC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800490B0: lh          $v0, -0x2E5E($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2E5E);
    // 0x800490B4: slti        $at, $v0, 0x1A
    ctx->r1 = SIGNED(ctx->r2) < 0X1A ? 1 : 0;
    // 0x800490B8: bnel        $at, $zero, L_800490D4
    if (ctx->r1 != 0) {
        // 0x800490BC: slti        $at, $v0, -0x19
        ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
            goto L_800490D4;
    }
    goto skip_20;
    // 0x800490BC: slti        $at, $v0, -0x19
    ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
    skip_20:
    // 0x800490C0: lwc1        $f16, 0xC($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800490C4: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x800490C8: b           L_800490E8
    // 0x800490CC: swc1        $f18, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f18.u32l;
        goto L_800490E8;
    // 0x800490CC: swc1        $f18, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f18.u32l;
    // 0x800490D0: slti        $at, $v0, -0x19
    ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
L_800490D4:
    // 0x800490D4: beq         $at, $zero, L_800490E8
    if (ctx->r1 == 0) {
        // 0x800490D8: nop
    
            goto L_800490E8;
    }
    // 0x800490D8: nop

    // 0x800490DC: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800490E0: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800490E4: swc1        $f6, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f6.u32l;
L_800490E8:
    // 0x800490E8: beq         $s3, $zero, L_8004924C
    if (ctx->r19 == 0) {
        // 0x800490EC: addiu       $a0, $sp, 0x13C
        ctx->r4 = ADD32(ctx->r29, 0X13C);
            goto L_8004924C;
    }
    // 0x800490EC: addiu       $a0, $sp, 0x13C
    ctx->r4 = ADD32(ctx->r29, 0X13C);
    // 0x800490F0: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x800490F4: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800490F8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x800490FC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80049100: jal         0x80049840
    // 0x80049104: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    func_80049840(rdram, ctx);
        goto after_49;
    // 0x80049104: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_49:
    // 0x80049108: lw          $a1, 0x10($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X10);
    // 0x8004910C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80049110: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80049114: addiu       $a0, $sp, 0xFC
    ctx->r4 = ADD32(ctx->r29, 0XFC);
    // 0x80049118: jal         0x80049840
    // 0x8004911C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_80049840(rdram, ctx);
        goto after_50;
    // 0x8004911C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_50:
    // 0x80049120: addiu       $a0, $sp, 0x13C
    ctx->r4 = ADD32(ctx->r29, 0X13C);
    // 0x80049124: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80049128: jal         0x80000BD8
    // 0x8004912C: addiu       $a2, $sp, 0xFC
    ctx->r6 = ADD32(ctx->r29, 0XFC);
    func_80000BD8(rdram, ctx);
        goto after_51;
    // 0x8004912C: addiu       $a2, $sp, 0xFC
    ctx->r6 = ADD32(ctx->r29, 0XFC);
    after_51:
    // 0x80049130: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80049134: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80049138: lw          $a1, 0x14($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X14);
    // 0x8004913C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80049140: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80049144: addiu       $a0, $sp, 0xFC
    ctx->r4 = ADD32(ctx->r29, 0XFC);
    // 0x80049148: jal         0x80049840
    // 0x8004914C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_80049840(rdram, ctx);
        goto after_52;
    // 0x8004914C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_52:
    // 0x80049150: lw          $a0, 0x8($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X8);
    // 0x80049154: addiu       $a1, $sp, 0xFC
    ctx->r5 = ADD32(ctx->r29, 0XFC);
    // 0x80049158: addiu       $a2, $sp, 0x13C
    ctx->r6 = ADD32(ctx->r29, 0X13C);
    // 0x8004915C: jal         0x80000BD8
    // 0x80049160: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80000BD8(rdram, ctx);
        goto after_53;
    // 0x80049160: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_53:
    // 0x80049164: lwc1        $f0, 0x1C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80049168: addiu       $a0, $sp, 0x13C
    ctx->r4 = ADD32(ctx->r29, 0X13C);
    // 0x8004916C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80049170: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80049174: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80049178: jal         0x80001AB4
    // 0x8004917C: nop

    func_80001AB4(rdram, ctx);
        goto after_54;
    // 0x8004917C: nop

    after_54:
    // 0x80049180: lw          $a0, 0x8($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X8);
    // 0x80049184: addiu       $a2, $sp, 0x13C
    ctx->r6 = ADD32(ctx->r29, 0X13C);
    // 0x80049188: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8004918C: jal         0x80000BD8
    // 0x80049190: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_80000BD8(rdram, ctx);
        goto after_55;
    // 0x80049190: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_55:
    // 0x80049194: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80049198: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
L_8004919C:
    // 0x8004919C: lw          $t5, 0x8($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X8);
    // 0x800491A0: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800491A4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800491A8: addu        $t8, $t5, $v0
    ctx->r24 = ADD32(ctx->r13, ctx->r2);
    // 0x800491AC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800491B0: bne         $v0, $fp, L_8004919C
    if (ctx->r2 != ctx->r30) {
        // 0x800491B4: swc1        $f10, 0x40($t8)
        MEM_W(0X40, ctx->r24) = ctx->f10.u32l;
            goto L_8004919C;
    }
    // 0x800491B4: swc1        $f10, 0x40($t8)
    MEM_W(0X40, ctx->r24) = ctx->f10.u32l;
    // 0x800491B8: lw          $a3, 0xE8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XE8);
    // 0x800491BC: lw          $v1, 0xF8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XF8);
    // 0x800491C0: lw          $a0, 0xF4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XF4);
    // 0x800491C4: andi        $t7, $a3, 0x3F
    ctx->r15 = ctx->r7 & 0X3F;
    // 0x800491C8: sll         $a3, $t7, 16
    ctx->r7 = S32(ctx->r15 << 16);
    // 0x800491CC: lw          $t7, 0x8($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X8);
    // 0x800491D0: andi        $t6, $v1, 0x1
    ctx->r14 = ctx->r3 & 0X1;
    // 0x800491D4: sll         $v1, $t6, 1
    ctx->r3 = S32(ctx->r14 << 1);
    // 0x800491D8: lw          $a1, 0xF0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XF0);
    // 0x800491DC: lw          $t5, 0xEC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XEC);
    // 0x800491E0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800491E4: sw          $t6, 0xD8($t7)
    MEM_W(0XD8, ctx->r15) = ctx->r14;
    // 0x800491E8: lw          $v0, 0x8($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X8);
    // 0x800491EC: andi        $t9, $a0, 0x1
    ctx->r25 = ctx->r4 & 0X1;
    // 0x800491F0: sll         $a0, $t9, 2
    ctx->r4 = S32(ctx->r25 << 2);
    // 0x800491F4: lw          $t9, 0xD8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XD8);
    // 0x800491F8: sll         $t0, $t5, 31
    ctx->r8 = S32(ctx->r13 << 31);
    // 0x800491FC: andi        $t8, $a1, 0x1
    ctx->r24 = ctx->r5 & 0X1;
    // 0x80049200: or          $t5, $t9, $v1
    ctx->r13 = ctx->r25 | ctx->r3;
    // 0x80049204: sw          $t5, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r13;
    // 0x80049208: lw          $v0, 0x8($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X8);
    // 0x8004920C: sll         $a1, $t8, 3
    ctx->r5 = S32(ctx->r24 << 3);
    // 0x80049210: lw          $t8, 0xD8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XD8);
    // 0x80049214: or          $t6, $t8, $a0
    ctx->r14 = ctx->r24 | ctx->r4;
    // 0x80049218: sw          $t6, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r14;
    // 0x8004921C: lw          $v0, 0x8($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X8);
    // 0x80049220: lw          $t7, 0xD8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XD8);
    // 0x80049224: or          $t9, $t7, $a1
    ctx->r25 = ctx->r15 | ctx->r5;
    // 0x80049228: sw          $t9, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r25;
    // 0x8004922C: lw          $v0, 0x8($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X8);
    // 0x80049230: lw          $t5, 0xD8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XD8);
    // 0x80049234: or          $t8, $t5, $a3
    ctx->r24 = ctx->r13 | ctx->r7;
    // 0x80049238: sw          $t8, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r24;
    // 0x8004923C: lw          $v0, 0x8($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X8);
    // 0x80049240: lw          $t6, 0xD8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XD8);
    // 0x80049244: or          $t7, $t6, $t0
    ctx->r15 = ctx->r14 | ctx->r8;
    // 0x80049248: sw          $t7, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r15;
L_8004924C:
    // 0x8004924C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80049250: lhu         $t9, -0x2E5A($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X2E5A);
    // 0x80049254: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80049258: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8004925C: andi        $t5, $t9, 0x1000
    ctx->r13 = ctx->r25 & 0X1000;
    // 0x80049260: beql        $t5, $zero, L_8004932C
    if (ctx->r13 == 0) {
        // 0x80049264: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8004932C;
    }
    goto skip_21;
    // 0x80049264: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_21:
    // 0x80049268: bne         $s6, $at, L_80049320
    if (ctx->r22 != ctx->r1) {
        // 0x8004926C: lw          $t8, 0x194($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X194);
            goto L_80049320;
    }
    // 0x8004926C: lw          $t8, 0x194($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X194);
    // 0x80049270: sh          $t8, 0x8C($s4)
    MEM_H(0X8C, ctx->r20) = ctx->r24;
    // 0x80049274: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80049278: or          $v1, $s5, $zero
    ctx->r3 = ctx->r21 | 0;
    // 0x8004927C: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
L_80049280:
    // 0x80049280: lbu         $t6, 0x10($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X10);
    // 0x80049284: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80049288: slti        $at, $s0, 0x8
    ctx->r1 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x8004928C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80049290: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80049294: bne         $at, $zero, L_80049280
    if (ctx->r1 != 0) {
        // 0x80049298: sb          $t6, 0x83($v0)
        MEM_B(0X83, ctx->r2) = ctx->r14;
            goto L_80049280;
    }
    // 0x80049298: sb          $t6, 0x83($v0)
    MEM_B(0X83, ctx->r2) = ctx->r14;
    // 0x8004929C: lwc1        $f16, 0x1C($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x800492A0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800492A4: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x800492A8: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x800492AC: swc1        $f16, 0x2C($s4)
    MEM_W(0X2C, ctx->r20) = ctx->f16.u32l;
L_800492B0:
    // 0x800492B0: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800492B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800492B8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800492BC: swc1        $f18, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f18.u32l;
    // 0x800492C0: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800492C4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800492C8: bne         $s0, $s2, L_800492B0
    if (ctx->r16 != ctx->r18) {
        // 0x800492CC: swc1        $f4, 0x18($v0)
        MEM_W(0X18, ctx->r2) = ctx->f4.u32l;
            goto L_800492B0;
    }
    // 0x800492CC: swc1        $f4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f4.u32l;
    // 0x800492D0: lw          $t8, 0xF4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF4);
    // 0x800492D4: lw          $t7, 0xF8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF8);
    // 0x800492D8: andi        $t6, $t8, 0x1
    ctx->r14 = ctx->r24 & 0X1;
    // 0x800492DC: lw          $t8, 0xF0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF0);
    // 0x800492E0: andi        $t9, $t7, 0x1
    ctx->r25 = ctx->r15 & 0X1;
    // 0x800492E4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800492E8: sll         $t5, $t9, 1
    ctx->r13 = S32(ctx->r25 << 1);
    // 0x800492EC: andi        $t6, $t8, 0x1
    ctx->r14 = ctx->r24 & 0X1;
    // 0x800492F0: lw          $t8, 0xE8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE8);
    // 0x800492F4: or          $t9, $t5, $t7
    ctx->r25 = ctx->r13 | ctx->r15;
    // 0x800492F8: sll         $t5, $t6, 3
    ctx->r13 = S32(ctx->r14 << 3);
    // 0x800492FC: or          $t7, $t9, $t5
    ctx->r15 = ctx->r25 | ctx->r13;
    // 0x80049300: andi        $t6, $t8, 0x3F
    ctx->r14 = ctx->r24 & 0X3F;
    // 0x80049304: sll         $t9, $t6, 16
    ctx->r25 = S32(ctx->r14 << 16);
    // 0x80049308: lw          $t6, 0xEC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XEC);
    // 0x8004930C: or          $t5, $t7, $t9
    ctx->r13 = ctx->r15 | ctx->r25;
    // 0x80049310: sh          $zero, 0x7C($s4)
    MEM_H(0X7C, ctx->r20) = 0;
    // 0x80049314: sll         $t7, $t6, 31
    ctx->r15 = S32(ctx->r14 << 31);
    // 0x80049318: or          $v0, $t5, $t7
    ctx->r2 = ctx->r13 | ctx->r15;
    // 0x8004931C: sw          $v0, 0x80($s4)
    MEM_W(0X80, ctx->r20) = ctx->r2;
L_80049320:
    // 0x80049320: jal         0x8004A0C4
    // 0x80049324: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    func_8004A0C4(rdram, ctx);
        goto after_56;
    // 0x80049324: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    after_56:
    // 0x80049328: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8004932C:
    // 0x8004932C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80049330: jal         0x8004C388
    // 0x80049334: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004C388(rdram, ctx);
        goto after_57;
    // 0x80049334: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_57:
    // 0x80049338: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x8004933C: addiu       $a2, $a2, 0x7D38
    ctx->r6 = ADD32(ctx->r6, 0X7D38);
    // 0x80049340: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80049344: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80049348: jal         0x8004C340
    // 0x8004934C: lw          $a3, 0x194($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X194);
    func_8004C340(rdram, ctx);
        goto after_58;
    // 0x8004934C: lw          $a3, 0x194($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X194);
    after_58:
    // 0x80049350: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80049354: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80049358: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8004935C: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80049360: addiu       $a2, $a2, 0x7D44
    ctx->r6 = ADD32(ctx->r6, 0X7D44);
    // 0x80049364: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80049368: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x8004936C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80049370: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80049374: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80049378: jal         0x8004C340
    // 0x8004937C: nop

    func_8004C340(rdram, ctx);
        goto after_59;
    // 0x8004937C: nop

    after_59:
    // 0x80049380: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80049384: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80049388: lwc1        $f18, 0x10($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004938C: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80049390: addiu       $a2, $a2, 0x7D58
    ctx->r6 = ADD32(ctx->r6, 0X7D58);
    // 0x80049394: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80049398: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x8004939C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800493A0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800493A4: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x800493A8: jal         0x8004C340
    // 0x800493AC: nop

    func_8004C340(rdram, ctx);
        goto after_60;
    // 0x800493AC: nop

    after_60:
    // 0x800493B0: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800493B4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800493B8: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800493BC: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x800493C0: addiu       $a2, $a2, 0x7D6C
    ctx->r6 = ADD32(ctx->r6, 0X7D6C);
    // 0x800493C4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800493C8: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x800493CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800493D0: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800493D4: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x800493D8: jal         0x8004C340
    // 0x800493DC: nop

    func_8004C340(rdram, ctx);
        goto after_61;
    // 0x800493DC: nop

    after_61:
    // 0x800493E0: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800493E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800493E8: lwc1        $f6, 0x1C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x800493EC: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x800493F0: addiu       $a2, $a2, 0x7D80
    ctx->r6 = ADD32(ctx->r6, 0X7D80);
    // 0x800493F4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800493F8: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x800493FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80049400: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80049404: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80049408: jal         0x8004C340
    // 0x8004940C: nop

    func_8004C340(rdram, ctx);
        goto after_62;
    // 0x8004940C: nop

    after_62:
    // 0x80049410: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80049414: addiu       $a2, $a2, 0x7D94
    ctx->r6 = ADD32(ctx->r6, 0X7D94);
    // 0x80049418: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x8004941C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80049420: jal         0x8004C340
    // 0x80049424: lw          $a3, 0xF0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF0);
    func_8004C340(rdram, ctx);
        goto after_63;
    // 0x80049424: lw          $a3, 0xF0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF0);
    after_63:
    // 0x80049428: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x8004942C: addiu       $a2, $a2, 0x7DA0
    ctx->r6 = ADD32(ctx->r6, 0X7DA0);
    // 0x80049430: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80049434: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80049438: jal         0x8004C340
    // 0x8004943C: lw          $a3, 0xE8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XE8);
    func_8004C340(rdram, ctx);
        goto after_64;
    // 0x8004943C: lw          $a3, 0xE8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XE8);
    after_64:
    // 0x80049440: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80049444: addiu       $a2, $a2, 0x7DAC
    ctx->r6 = ADD32(ctx->r6, 0X7DAC);
    // 0x80049448: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x8004944C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80049450: jal         0x8004C340
    // 0x80049454: lw          $a3, 0xF4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF4);
    func_8004C340(rdram, ctx);
        goto after_65;
    // 0x80049454: lw          $a3, 0xF4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF4);
    after_65:
    // 0x80049458: lw          $t7, 0xF8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF8);
    // 0x8004945C: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80049460: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80049464: beq         $t7, $zero, L_8004948C
    if (ctx->r15 == 0) {
        // 0x80049468: lui         $a2, 0x8007
        ctx->r6 = S32(0X8007 << 16);
            goto L_8004948C;
    }
    // 0x80049468: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x8004946C: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80049470: addiu       $a2, $a2, 0x7DB8
    ctx->r6 = ADD32(ctx->r6, 0X7DB8);
    // 0x80049474: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80049478: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004947C: jal         0x8004BCF0
    // 0x80049480: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    func_8004BCF0(rdram, ctx);
        goto after_66;
    // 0x80049480: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_66:
    // 0x80049484: b           L_80049498
    // 0x80049488: nop

        goto L_80049498;
    // 0x80049488: nop

L_8004948C:
    // 0x8004948C: addiu       $a2, $a2, 0x7DD0
    ctx->r6 = ADD32(ctx->r6, 0X7DD0);
    // 0x80049490: jal         0x8004BCF0
    // 0x80049494: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    func_8004BCF0(rdram, ctx);
        goto after_67;
    // 0x80049494: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_67:
L_80049498:
    // 0x80049498: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x8004949C: addiu       $a2, $a2, 0x7DE8
    ctx->r6 = ADD32(ctx->r6, 0X7DE8);
    // 0x800494A0: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x800494A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800494A8: jal         0x8004C340
    // 0x800494AC: lw          $a3, 0xEC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XEC);
    func_8004C340(rdram, ctx);
        goto after_68;
    // 0x800494AC: lw          $a3, 0xEC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XEC);
    after_68:
    // 0x800494B0: lwc1        $f18, 0x0($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800494B4: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x800494B8: addiu       $a2, $a2, 0x7DF4
    ctx->r6 = ADD32(ctx->r6, 0X7DF4);
    // 0x800494BC: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800494C0: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x800494C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800494C8: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x800494CC: jal         0x8004C340
    // 0x800494D0: nop

    func_8004C340(rdram, ctx);
        goto after_69;
    // 0x800494D0: nop

    after_69:
    // 0x800494D4: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800494D8: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x800494DC: addiu       $a2, $a2, 0x7DFC
    ctx->r6 = ADD32(ctx->r6, 0X7DFC);
    // 0x800494E0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800494E4: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x800494E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800494EC: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x800494F0: jal         0x8004C340
    // 0x800494F4: nop

    func_8004C340(rdram, ctx);
        goto after_70;
    // 0x800494F4: nop

    after_70:
    // 0x800494F8: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800494FC: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80049500: addiu       $a2, $a2, 0x7E04
    ctx->r6 = ADD32(ctx->r6, 0X7E04);
    // 0x80049504: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80049508: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x8004950C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80049510: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80049514: jal         0x8004C340
    // 0x80049518: nop

    func_8004C340(rdram, ctx);
        goto after_71;
    // 0x80049518: nop

    after_71:
    // 0x8004951C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80049520: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80049524: jal         0x8004C388
    // 0x80049528: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004C388(rdram, ctx);
        goto after_72;
    // 0x80049528: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_72:
    // 0x8004952C: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80049530: addiu       $a2, $a2, 0x7E0C
    ctx->r6 = ADD32(ctx->r6, 0X7E0C);
    // 0x80049534: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80049538: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004953C: jal         0x8004C340
    // 0x80049540: lh          $a3, 0xC($s5)
    ctx->r7 = MEM_H(ctx->r21, 0XC);
    func_8004C340(rdram, ctx);
        goto after_73;
    // 0x80049540: lh          $a3, 0xC($s5)
    ctx->r7 = MEM_H(ctx->r21, 0XC);
    after_73:
    // 0x80049544: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80049548: addiu       $a2, $a2, 0x7E18
    ctx->r6 = ADD32(ctx->r6, 0X7E18);
    // 0x8004954C: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80049550: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80049554: jal         0x8004C340
    // 0x80049558: lh          $a3, 0x1A($s5)
    ctx->r7 = MEM_H(ctx->r21, 0X1A);
    func_8004C340(rdram, ctx);
        goto after_74;
    // 0x80049558: lh          $a3, 0x1A($s5)
    ctx->r7 = MEM_H(ctx->r21, 0X1A);
    after_74:
    // 0x8004955C: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80049560: addiu       $a2, $a2, 0x7E24
    ctx->r6 = ADD32(ctx->r6, 0X7E24);
    // 0x80049564: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80049568: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004956C: jal         0x8004C340
    // 0x80049570: lh          $a3, 0x1C($s5)
    ctx->r7 = MEM_H(ctx->r21, 0X1C);
    func_8004C340(rdram, ctx);
        goto after_75;
    // 0x80049570: lh          $a3, 0x1C($s5)
    ctx->r7 = MEM_H(ctx->r21, 0X1C);
    after_75:
    // 0x80049574: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80049578: addiu       $a2, $a2, 0x7E30
    ctx->r6 = ADD32(ctx->r6, 0X7E30);
    // 0x8004957C: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x80049580: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80049584: jal         0x8004C340
    // 0x80049588: lh          $a3, 0x1E($s5)
    ctx->r7 = MEM_H(ctx->r21, 0X1E);
    func_8004C340(rdram, ctx);
        goto after_76;
    // 0x80049588: lh          $a3, 0x1E($s5)
    ctx->r7 = MEM_H(ctx->r21, 0X1E);
    after_76:
    // 0x8004958C: or          $v1, $s5, $zero
    ctx->r3 = ctx->r21 | 0;
    // 0x80049590: addiu       $a0, $sp, 0xDC
    ctx->r4 = ADD32(ctx->r29, 0XDC);
L_80049594:
    // 0x80049594: lbu         $t5, 0x10($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X10);
    // 0x80049598: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8004959C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800495A0: sb          $t5, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r13;
    // 0x800495A4: lbu         $t7, 0xD($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0XD);
    // 0x800495A8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800495AC: sb          $t7, -0x3($a0)
    MEM_B(-0X3, ctx->r4) = ctx->r15;
    // 0x800495B0: lbu         $t9, 0xE($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0XE);
    // 0x800495B4: sb          $t9, -0x2($a0)
    MEM_B(-0X2, ctx->r4) = ctx->r25;
    // 0x800495B8: lbu         $t8, 0xF($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XF);
    // 0x800495BC: bne         $s0, $s7, L_80049594
    if (ctx->r16 != ctx->r23) {
        // 0x800495C0: sb          $t8, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = ctx->r24;
            goto L_80049594;
    }
    // 0x800495C0: sb          $t8, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r24;
    // 0x800495C4: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x800495C8: sb          $zero, 0xE4($sp)
    MEM_B(0XE4, ctx->r29) = 0;
    // 0x800495CC: addiu       $a2, $a2, 0x7E3C
    ctx->r6 = ADD32(ctx->r6, 0X7E3C);
    // 0x800495D0: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x800495D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800495D8: jal         0x8004C340
    // 0x800495DC: addiu       $a3, $sp, 0xDC
    ctx->r7 = ADD32(ctx->r29, 0XDC);
    func_8004C340(rdram, ctx);
        goto after_77;
    // 0x800495DC: addiu       $a3, $sp, 0xDC
    ctx->r7 = ADD32(ctx->r29, 0XDC);
    after_77:
L_800495E0:
    // 0x800495E0: jal         0x8000798C
    // 0x800495E4: nop

    func_8000798C(rdram, ctx);
        goto after_78;
    // 0x800495E4: nop

    after_78:
    // 0x800495E8: b           L_8004866C
    // 0x800495EC: lh          $t7, 0x9E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X9E);
        goto L_8004866C;
    // 0x800495EC: lh          $t7, 0x9E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X9E);
    // 0x800495F0: nop

    // 0x800495F4: nop

    // 0x800495F8: nop

    // 0x800495FC: nop

    // 0x80049600: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80049604: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80049608: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8004960C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80049610: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80049614: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80049618: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8004961C: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80049620: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80049624: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80049628: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8004962C: jr          $ra
    // 0x80049630: addiu       $sp, $sp, 0x1A8
    ctx->r29 = ADD32(ctx->r29, 0X1A8);
    TRACE_RETURN()
    return;
    // 0x80049630: addiu       $sp, $sp, 0x1A8
    ctx->r29 = ADD32(ctx->r29, 0X1A8);
;}
RECOMP_FUNC void func_80049634(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80049634: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80049638: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004963C: jal         0x8003A1C8
    // 0x80049640: nop

    func_8003A1C8(rdram, ctx);
        goto after_0;
    // 0x80049640: nop

    after_0:
    // 0x80049644: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80049648: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004964C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80049660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80049660: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80049664: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80049668: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x8004966C: sh          $a2, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r6;
    // 0x80049670: sh          $a3, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r7;
    // 0x80049674: lh          $t0, 0x12($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X12);
    // 0x80049678: sh          $zero, 0xA($a0)
    MEM_H(0XA, ctx->r4) = 0;
    // 0x8004967C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80049680: sh          $t0, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r8;
    // 0x80049684: lh          $t1, 0x0($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X0);
    // 0x80049688: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x8004968C: beq         $t1, $zero, L_800496AC
    if (ctx->r9 == 0) {
        // 0x80049690: nop
    
            goto L_800496AC;
    }
    // 0x80049690: nop

L_80049694:
    // 0x80049694: lh          $t4, 0x8($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X8);
    // 0x80049698: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004969C: sll         $t2, $v0, 16
    ctx->r10 = S32(ctx->r2 << 16);
    // 0x800496A0: sra         $v0, $t2, 16
    ctx->r2 = S32(SIGNED(ctx->r10) >> 16);
    // 0x800496A4: bne         $t4, $zero, L_80049694
    if (ctx->r12 != 0) {
        // 0x800496A8: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_80049694;
    }
    // 0x800496A8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_800496AC:
    // 0x800496AC: jr          $ra
    // 0x800496B0: sh          $v0, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r2;
    TRACE_RETURN()
    return;
    // 0x800496B0: sh          $v0, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_800496B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800496B4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800496B8: lhu         $v0, -0x2E5A($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2E5A);
    // 0x800496BC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800496C0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800496C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800496C8: andi        $t6, $v0, 0x400
    ctx->r14 = ctx->r2 & 0X400;
    // 0x800496CC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800496D0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800496D4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800496D8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800496DC: bne         $t6, $zero, L_800496FC
    if (ctx->r14 != 0) {
        // 0x800496E0: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_800496FC;
    }
    // 0x800496E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800496E4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800496E8: lh          $v1, -0x2E4C($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X2E4C);
    // 0x800496EC: andi        $t8, $v0, 0x800
    ctx->r24 = ctx->r2 & 0X800;
    // 0x800496F0: andi        $t7, $v1, 0x400
    ctx->r15 = ctx->r3 & 0X400;
    // 0x800496F4: beq         $t7, $zero, L_80049704
    if (ctx->r15 == 0) {
        // 0x800496F8: nop
    
            goto L_80049704;
    }
    // 0x800496F8: nop

L_800496FC:
    // 0x800496FC: b           L_80049718
    // 0x80049700: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_80049718;
    // 0x80049700: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80049704:
    // 0x80049704: bne         $t8, $zero, L_80049714
    if (ctx->r24 != 0) {
        // 0x80049708: andi        $t9, $v1, 0x800
        ctx->r25 = ctx->r3 & 0X800;
            goto L_80049714;
    }
    // 0x80049708: andi        $t9, $v1, 0x800
    ctx->r25 = ctx->r3 & 0X800;
    // 0x8004970C: beq         $t9, $zero, L_80049718
    if (ctx->r25 == 0) {
        // 0x80049710: nop
    
            goto L_80049718;
    }
    // 0x80049710: nop

L_80049714:
    // 0x80049714: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
L_80049718:
    // 0x80049718: beq         $s0, $zero, L_8004972C
    if (ctx->r16 == 0) {
        // 0x8004971C: addiu       $a0, $zero, 0x12
        ctx->r4 = ADD32(0, 0X12);
            goto L_8004972C;
    }
    // 0x8004971C: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x80049720: jal         0x80044480
    // 0x80049724: sh          $a1, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r5;
    func_80044480(rdram, ctx);
        goto after_0;
    // 0x80049724: sh          $a1, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r5;
    after_0:
    // 0x80049728: lh          $a1, 0x28($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X28);
L_8004972C:
    // 0x8004972C: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x80049730: sh          $zero, 0xC($s1)
    MEM_H(0XC, ctx->r17) = 0;
    // 0x80049734: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80049738: lh          $t0, 0xA($s1)
    ctx->r8 = MEM_H(ctx->r17, 0XA);
L_8004973C:
    // 0x8004973C: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x80049740: sh          $t1, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r9;
    // 0x80049744: lh          $v0, 0xA($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XA);
    // 0x80049748: bgezl       $v0, L_80049764
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8004974C: sll         $t4, $v0, 3
        ctx->r12 = S32(ctx->r2 << 3);
            goto L_80049764;
    }
    goto skip_0;
    // 0x8004974C: sll         $t4, $v0, 3
    ctx->r12 = S32(ctx->r2 << 3);
    skip_0:
    // 0x80049750: lh          $t2, 0xE($s1)
    ctx->r10 = MEM_H(ctx->r17, 0XE);
    // 0x80049754: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80049758: sh          $t3, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r11;
    // 0x8004975C: lh          $v0, 0xA($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XA);
    // 0x80049760: sll         $t4, $v0, 3
    ctx->r12 = S32(ctx->r2 << 3);
L_80049764:
    // 0x80049764: addu        $t5, $t4, $s2
    ctx->r13 = ADD32(ctx->r12, ctx->r18);
    // 0x80049768: lh          $v1, 0x0($t5)
    ctx->r3 = MEM_H(ctx->r13, 0X0);
    // 0x8004976C: beq         $v1, $a0, L_800497A8
    if (ctx->r3 == ctx->r4) {
        // 0x80049770: nop
    
            goto L_800497A8;
    }
    // 0x80049770: nop

    // 0x80049774: beq         $v1, $zero, L_80049788
    if (ctx->r3 == 0) {
        // 0x80049778: nop
    
            goto L_80049788;
    }
    // 0x80049778: nop

    // 0x8004977C: sh          $v1, 0xC($s1)
    MEM_H(0XC, ctx->r17) = ctx->r3;
    // 0x80049780: b           L_800497BC
    // 0x80049784: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_800497BC;
    // 0x80049784: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80049788:
    // 0x80049788: blezl       $s0, L_8004979C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8004978C: lh          $t6, 0xE($s1)
        ctx->r14 = MEM_H(ctx->r17, 0XE);
            goto L_8004979C;
    }
    goto skip_1;
    // 0x8004978C: lh          $t6, 0xE($s1)
    ctx->r14 = MEM_H(ctx->r17, 0XE);
    skip_1:
    // 0x80049790: b           L_800497BC
    // 0x80049794: sh          $a0, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r4;
        goto L_800497BC;
    // 0x80049794: sh          $a0, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r4;
    // 0x80049798: lh          $t6, 0xE($s1)
    ctx->r14 = MEM_H(ctx->r17, 0XE);
L_8004979C:
    // 0x8004979C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800497A0: b           L_800497BC
    // 0x800497A4: sh          $t7, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r15;
        goto L_800497BC;
    // 0x800497A4: sh          $t7, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r15;
L_800497A8:
    // 0x800497A8: bne         $s0, $zero, L_800497BC
    if (ctx->r16 != 0) {
        // 0x800497AC: nop
    
            goto L_800497BC;
    }
    // 0x800497AC: nop

    // 0x800497B0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800497B4: sll         $t8, $s0, 16
    ctx->r24 = S32(ctx->r16 << 16);
    // 0x800497B8: sra         $s0, $t8, 16
    ctx->r16 = S32(SIGNED(ctx->r24) >> 16);
L_800497BC:
    // 0x800497BC: bnel        $a1, $zero, L_8004973C
    if (ctx->r5 != 0) {
        // 0x800497C0: lh          $t0, 0xA($s1)
        ctx->r8 = MEM_H(ctx->r17, 0XA);
            goto L_8004973C;
    }
    goto skip_2;
    // 0x800497C0: lh          $t0, 0xA($s1)
    ctx->r8 = MEM_H(ctx->r17, 0XA);
    skip_2:
    // 0x800497C4: lh          $a0, 0x4($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X4);
    // 0x800497C8: lh          $a1, 0x6($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X6);
    // 0x800497CC: jal         0x8004C388
    // 0x800497D0: lh          $a2, 0x8($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X8);
    func_8004C388(rdram, ctx);
        goto after_1;
    // 0x800497D0: lh          $a2, 0x8($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X8);
    after_1:
    // 0x800497D4: lh          $t0, 0xE($s1)
    ctx->r8 = MEM_H(ctx->r17, 0XE);
    // 0x800497D8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800497DC: blezl       $t0, L_80049824
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800497E0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80049824;
    }
    goto skip_3;
    // 0x800497E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x800497E4: lh          $t1, 0xA($s1)
    ctx->r9 = MEM_H(ctx->r17, 0XA);
L_800497E8:
    // 0x800497E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800497EC: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x800497F0: bne         $s0, $t1, L_800497FC
    if (ctx->r16 != ctx->r9) {
        // 0x800497F4: lui         $a2, 0x8007
        ctx->r6 = S32(0X8007 << 16);
            goto L_800497FC;
    }
    // 0x800497F4: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x800497F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_800497FC:
    // 0x800497FC: addiu       $a2, $a2, 0x7FB0
    ctx->r6 = ADD32(ctx->r6, 0X7FB0);
    // 0x80049800: jal         0x8004C340
    // 0x80049804: lw          $a3, 0x4($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X4);
    func_8004C340(rdram, ctx);
        goto after_2;
    // 0x80049804: lw          $a3, 0x4($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X4);
    after_2:
    // 0x80049808: lh          $t2, 0xE($s1)
    ctx->r10 = MEM_H(ctx->r17, 0XE);
    // 0x8004980C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80049810: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x80049814: slt         $at, $s0, $t2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80049818: bnel        $at, $zero, L_800497E8
    if (ctx->r1 != 0) {
        // 0x8004981C: lh          $t1, 0xA($s1)
        ctx->r9 = MEM_H(ctx->r17, 0XA);
            goto L_800497E8;
    }
    goto skip_4;
    // 0x8004981C: lh          $t1, 0xA($s1)
    ctx->r9 = MEM_H(ctx->r17, 0XA);
    skip_4:
    // 0x80049820: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80049824:
    // 0x80049824: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80049828: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8004982C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80049830: jr          $ra
    // 0x80049834: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    TRACE_RETURN()
    return;
    // 0x80049834: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80049840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80049840: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80049844: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80049848: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004984C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80049850: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80049854: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80049858: jal         0x800022F0
    // 0x8004985C: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    func_800022F0(rdram, ctx);
        goto after_0;
    // 0x8004985C: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_0:
    // 0x80049860: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80049864: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80049868: jal         0x80003918
    // 0x8004986C: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    func_80003918(rdram, ctx);
        goto after_1;
    // 0x8004986C: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    after_1:
    // 0x80049870: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80049874: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80049878: lwc1        $f4, 0x7FC0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7FC0);
    // 0x8004987C: mul.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80049880: jal         0x8004F7C0
    // 0x80049884: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    func_8004F7C0(rdram, ctx);
        goto after_2;
    // 0x80049884: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    after_2:
    // 0x80049888: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8004988C: jal         0x8004F650
    // 0x80049890: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    func_8004F650(rdram, ctx);
        goto after_3;
    // 0x80049890: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x80049894: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80049898: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8004989C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800498A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800498A4: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800498A8: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800498AC: sub.s       $f2, $f6, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800498B0: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800498B4: mul.s       $f18, $f4, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800498B8: nop

    // 0x800498BC: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800498C0: nop

    // 0x800498C4: mul.s       $f12, $f4, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800498C8: nop

    // 0x800498CC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800498D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800498D4: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800498D8: nop

    // 0x800498DC: mul.s       $f16, $f8, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x800498E0: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x800498E4: sub.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x800498E8: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800498EC: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800498F0: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    // 0x800498F4: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800498F8: mul.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800498FC: sub.s       $f4, $f12, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x80049900: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    // 0x80049904: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80049908: mul.s       $f6, $f8, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8004990C: add.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x80049910: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80049914: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    // 0x80049918: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8004991C: mul.s       $f8, $f4, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x80049920: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80049924: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x80049928: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8004992C: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80049930: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x80049934: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80049938: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8004993C: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80049940: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80049944: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x80049948: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8004994C: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80049950: mul.s       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80049954: sub.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80049958: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004995C: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x80049960: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80049964: mul.s       $f2, $f4, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x80049968: sub.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x8004996C: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80049970: add.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x80049974: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
    // 0x80049978: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8004997C: mul.s       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80049980: sub.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x80049984: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x80049988: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8004998C: mul.s       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80049990: add.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80049994: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x80049998: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004999C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800499A0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800499A4: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800499B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800499B0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800499B4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800499B8: sll         $s2, $a0, 16
    ctx->r18 = S32(ctx->r4 << 16);
    // 0x800499BC: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800499C0: sll         $a0, $a1, 16
    ctx->r4 = S32(ctx->r5 << 16);
    // 0x800499C4: sra         $t6, $s2, 16
    ctx->r14 = S32(SIGNED(ctx->r18) >> 16);
    // 0x800499C8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800499CC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800499D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800499D4: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800499D8: or          $s2, $t6, $zero
    ctx->r18 = ctx->r14 | 0;
    // 0x800499DC: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800499E0: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800499E4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800499E8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800499EC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800499F0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800499F4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800499F8: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800499FC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80049A00: jal         0x8004AD48
    // 0x80049A04: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_8004AD48(rdram, ctx);
        goto after_0;
    // 0x80049A04: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_0:
    // 0x80049A08: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80049A0C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80049A10: addiu       $v1, $v1, -0x6050
    ctx->r3 = ADD32(ctx->r3, -0X6050);
    // 0x80049A14: addiu       $v0, $v0, -0x6450
    ctx->r2 = ADD32(ctx->r2, -0X6450);
L_80049A18:
    // 0x80049A18: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80049A1C: sw          $zero, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = 0;
    // 0x80049A20: sw          $zero, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = 0;
    // 0x80049A24: sw          $zero, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = 0;
    // 0x80049A28: bne         $v0, $v1, L_80049A18
    if (ctx->r2 != ctx->r3) {
        // 0x80049A2C: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_80049A18;
    }
    // 0x80049A2C: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x80049A30: sll         $t0, $s2, 2
    ctx->r8 = S32(ctx->r18 << 2);
    // 0x80049A34: lui         $s1, 0x8007
    ctx->r17 = S32(0X8007 << 16);
    // 0x80049A38: addu        $s1, $s1, $t0
    ctx->r17 = ADD32(ctx->r17, ctx->r8);
    // 0x80049A3C: lw          $s1, -0x47D4($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X47D4);
    // 0x80049A40: addiu       $fp, $zero, -0x1
    ctx->r30 = ADD32(0, -0X1);
    // 0x80049A44: lh          $t1, 0x0($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X0);
    // 0x80049A48: or          $s6, $s1, $zero
    ctx->r22 = ctx->r17 | 0;
    // 0x80049A4C: beq         $fp, $t1, L_80049A98
    if (ctx->r30 == ctx->r9) {
        // 0x80049A50: nop
    
            goto L_80049A98;
    }
    // 0x80049A50: nop

    // 0x80049A54: lh          $v0, 0x0($s6)
    ctx->r2 = MEM_H(ctx->r22, 0X0);
    // 0x80049A58: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
L_80049A5C:
    // 0x80049A5C: sra         $t2, $v1, 16
    ctx->r10 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80049A60: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80049A64: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x80049A68: addu        $a1, $a1, $t3
    ctx->r5 = ADD32(ctx->r5, ctx->r11);
    // 0x80049A6C: jal         0x8004F3D4
    // 0x80049A70: lw          $a0, -0x4FD0($a1)
    ctx->r4 = MEM_W(ctx->r5, -0X4FD0);
    func_8004F3D4(rdram, ctx);
        goto after_1;
    // 0x80049A70: lw          $a0, -0x4FD0($a1)
    ctx->r4 = MEM_W(ctx->r5, -0X4FD0);
    after_1:
    // 0x80049A74: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80049A78: beql        $at, $zero, L_80049A88
    if (ctx->r1 == 0) {
        // 0x80049A7C: lh          $v0, 0x8($s6)
        ctx->r2 = MEM_H(ctx->r22, 0X8);
            goto L_80049A88;
    }
    goto skip_0;
    // 0x80049A7C: lh          $v0, 0x8($s6)
    ctx->r2 = MEM_H(ctx->r22, 0X8);
    skip_0:
    // 0x80049A80: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80049A84: lh          $v0, 0x8($s6)
    ctx->r2 = MEM_H(ctx->r22, 0X8);
L_80049A88:
    // 0x80049A88: addiu       $s6, $s6, 0x8
    ctx->r22 = ADD32(ctx->r22, 0X8);
    // 0x80049A8C: bnel        $fp, $v0, L_80049A5C
    if (ctx->r30 != ctx->r2) {
        // 0x80049A90: sll         $v1, $v0, 16
        ctx->r3 = S32(ctx->r2 << 16);
            goto L_80049A5C;
    }
    goto skip_1;
    // 0x80049A90: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    skip_1:
    // 0x80049A94: or          $s6, $s1, $zero
    ctx->r22 = ctx->r17 | 0;
L_80049A98:
    // 0x80049A98: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80049A9C: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80049AA0: jal         0x80004364
    // 0x80049AA4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80004364(rdram, ctx);
        goto after_2;
    // 0x80049AA4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80049AA8: lh          $t4, 0x0($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X0);
    // 0x80049AAC: lui         $s7, 0x8007
    ctx->r23 = S32(0X8007 << 16);
    // 0x80049AB0: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80049AB4: beq         $fp, $t4, L_80049C08
    if (ctx->r30 == ctx->r12) {
        // 0x80049AB8: addiu       $s7, $s7, -0x46E4
        ctx->r23 = ADD32(ctx->r23, -0X46E4);
            goto L_80049C08;
    }
    // 0x80049AB8: addiu       $s7, $s7, -0x46E4
    ctx->r23 = ADD32(ctx->r23, -0X46E4);
    // 0x80049ABC: lui         $s1, 0x6E61
    ctx->r17 = S32(0X6E61 << 16);
    // 0x80049AC0: ori         $s1, $s1, 0x6D65
    ctx->r17 = ctx->r17 | 0X6D65;
    // 0x80049AC4: lh          $v0, 0x0($s6)
    ctx->r2 = MEM_H(ctx->r22, 0X0);
    // 0x80049AC8: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
L_80049ACC:
    // 0x80049ACC: sra         $t5, $v1, 16
    ctx->r13 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80049AD0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80049AD4: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x80049AD8: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x80049ADC: lw          $s3, 0x4($s6)
    ctx->r19 = MEM_W(ctx->r22, 0X4);
    // 0x80049AE0: lw          $a1, -0x4FD0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4FD0);
    // 0x80049AE4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80049AE8: jal         0x8004F1DC
    // 0x80049AEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004F1DC(rdram, ctx);
        goto after_3;
    // 0x80049AEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80049AF0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80049AF4: bne         $s3, $at, L_80049B0C
    if (ctx->r19 != ctx->r1) {
        // 0x80049AF8: lui         $t7, 0x8013
        ctx->r15 = S32(0X8013 << 16);
            goto L_80049B0C;
    }
    // 0x80049AF8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80049AFC: lw          $t7, -0x68C8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X68C8);
    // 0x80049B00: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80049B04: addu        $t9, $s7, $t8
    ctx->r25 = ADD32(ctx->r23, ctx->r24);
    // 0x80049B08: lw          $s3, 0x0($t9)
    ctx->r19 = MEM_W(ctx->r25, 0X0);
L_80049B0C:
    // 0x80049B0C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80049B10: bne         $s3, $at, L_80049B1C
    if (ctx->r19 != ctx->r1) {
        // 0x80049B14: or          $s2, $s5, $zero
        ctx->r18 = ctx->r21 | 0;
            goto L_80049B1C;
    }
    // 0x80049B14: or          $s2, $s5, $zero
    ctx->r18 = ctx->r21 | 0;
    // 0x80049B18: lw          $s3, 0x28($s7)
    ctx->r19 = MEM_W(ctx->r23, 0X28);
L_80049B1C:
    // 0x80049B1C: lw          $t0, 0x0($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X0);
    // 0x80049B20: beq         $t0, $zero, L_80049BF8
    if (ctx->r8 == 0) {
        // 0x80049B24: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_80049BF8;
    }
    // 0x80049B24: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_80049B28:
    // 0x80049B28: beq         $s3, $zero, L_80049BC8
    if (ctx->r19 == 0) {
        // 0x80049B2C: addu        $a3, $v0, $s5
        ctx->r7 = ADD32(ctx->r2, ctx->r21);
            goto L_80049BC8;
    }
    // 0x80049B2C: addu        $a3, $v0, $s5
    ctx->r7 = ADD32(ctx->r2, ctx->r21);
    // 0x80049B30: addiu       $v0, $a3, 0x8
    ctx->r2 = ADD32(ctx->r7, 0X8);
    // 0x80049B34: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
L_80049B38:
    // 0x80049B38: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x80049B3C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80049B40: bnel        $s1, $t1, L_80049B54
    if (ctx->r17 != ctx->r9) {
        // 0x80049B44: lw          $v1, 0x0($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X0);
            goto L_80049B54;
    }
    goto skip_2;
    // 0x80049B44: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    skip_2:
    // 0x80049B48: b           L_80049B74
    // 0x80049B4C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
        goto L_80049B74;
    // 0x80049B4C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80049B50: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
L_80049B54:
    // 0x80049B54: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80049B58: bgez        $v1, L_80049B68
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80049B5C: sra         $t2, $v1, 2
        ctx->r10 = S32(SIGNED(ctx->r3) >> 2);
            goto L_80049B68;
    }
    // 0x80049B5C: sra         $t2, $v1, 2
    ctx->r10 = S32(SIGNED(ctx->r3) >> 2);
    // 0x80049B60: addiu       $at, $v1, 0x3
    ctx->r1 = ADD32(ctx->r3, 0X3);
    // 0x80049B64: sra         $t2, $at, 2
    ctx->r10 = S32(SIGNED(ctx->r1) >> 2);
L_80049B68:
    // 0x80049B68: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80049B6C: b           L_80049B38
    // 0x80049B70: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
        goto L_80049B38;
    // 0x80049B70: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
L_80049B74:
    // 0x80049B74: beq         $a0, $zero, L_80049BE8
    if (ctx->r4 == 0) {
        // 0x80049B78: or          $v1, $s3, $zero
        ctx->r3 = ctx->r19 | 0;
            goto L_80049BE8;
    }
    // 0x80049B78: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
    // 0x80049B7C: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x80049B80: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80049B84: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
L_80049B88:
    // 0x80049B88: bnel        $a2, $t4, L_80049BB4
    if (ctx->r6 != ctx->r12) {
        // 0x80049B8C: lw          $a0, 0x4($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X4);
            goto L_80049BB4;
    }
    goto skip_3;
    // 0x80049B8C: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    skip_3:
    // 0x80049B90: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x80049B94: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80049B98: bne         $t5, $t6, L_80049BB0
    if (ctx->r13 != ctx->r14) {
        // 0x80049B9C: lui         $t8, 0x8013
        ctx->r24 = S32(0X8013 << 16);
            goto L_80049BB0;
    }
    // 0x80049B9C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80049BA0: addiu       $t8, $t8, -0x6450
    ctx->r24 = ADD32(ctx->r24, -0X6450);
    // 0x80049BA4: sll         $t7, $s4, 2
    ctx->r15 = S32(ctx->r20 << 2);
    // 0x80049BA8: b           L_80049BD8
    // 0x80049BAC: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
        goto L_80049BD8;
    // 0x80049BAC: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
L_80049BB0:
    // 0x80049BB0: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
L_80049BB4:
    // 0x80049BB4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80049BB8: bnel        $a0, $zero, L_80049B88
    if (ctx->r4 != 0) {
        // 0x80049BBC: lw          $t4, 0x0($a0)
        ctx->r12 = MEM_W(ctx->r4, 0X0);
            goto L_80049B88;
    }
    goto skip_4;
    // 0x80049BBC: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    skip_4:
    // 0x80049BC0: b           L_80049BEC
    // 0x80049BC4: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
        goto L_80049BEC;
    // 0x80049BC4: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
L_80049BC8:
    // 0x80049BC8: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80049BCC: addiu       $t0, $t0, -0x6450
    ctx->r8 = ADD32(ctx->r8, -0X6450);
    // 0x80049BD0: sll         $t9, $s4, 2
    ctx->r25 = S32(ctx->r20 << 2);
    // 0x80049BD4: addu        $s0, $t9, $t0
    ctx->r16 = ADD32(ctx->r25, ctx->r8);
L_80049BD8:
    // 0x80049BD8: jal         0x8004A3B0
    // 0x80049BDC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_8004A3B0(rdram, ctx);
        goto after_4;
    // 0x80049BDC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_4:
    // 0x80049BE0: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80049BE4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_80049BE8:
    // 0x80049BE8: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
L_80049BEC:
    // 0x80049BEC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80049BF0: bne         $v0, $zero, L_80049B28
    if (ctx->r2 != 0) {
        // 0x80049BF4: nop
    
            goto L_80049B28;
    }
    // 0x80049BF4: nop

L_80049BF8:
    // 0x80049BF8: lh          $v0, 0x8($s6)
    ctx->r2 = MEM_H(ctx->r22, 0X8);
    // 0x80049BFC: addiu       $s6, $s6, 0x8
    ctx->r22 = ADD32(ctx->r22, 0X8);
    // 0x80049C00: bnel        $fp, $v0, L_80049ACC
    if (ctx->r30 != ctx->r2) {
        // 0x80049C04: sll         $v1, $v0, 16
        ctx->r3 = S32(ctx->r2 << 16);
            goto L_80049ACC;
    }
    goto skip_5;
    // 0x80049C04: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    skip_5:
L_80049C08:
    // 0x80049C08: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80049C0C: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x80049C10: jal         0x800042A8
    // 0x80049C14: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800042A8(rdram, ctx);
        goto after_5;
    // 0x80049C14: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_5:
    // 0x80049C18: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80049C1C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80049C20: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80049C24: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80049C28: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80049C2C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80049C30: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80049C34: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80049C38: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80049C3C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80049C40: jr          $ra
    // 0x80049C44: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    TRACE_RETURN()
    return;
    // 0x80049C44: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80049C48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80049C48: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80049C4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80049C50: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80049C54: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80049C58: jal         0x8004ADC0
    // 0x80049C5C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    func_8004ADC0(rdram, ctx);
        goto after_0;
    // 0x80049C5C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80049C60: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80049C64: lw          $t6, -0x6450($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6450);
    // 0x80049C68: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80049C6C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80049C70: beq         $t6, $zero, L_80049C9C
    if (ctx->r14 == 0) {
        // 0x80049C74: sll         $t8, $t7, 2
        ctx->r24 = S32(ctx->r15 << 2);
            goto L_80049C9C;
    }
    // 0x80049C74: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80049C78: addiu       $t9, $t9, -0x6450
    ctx->r25 = ADD32(ctx->r25, -0X6450);
    // 0x80049C7C: addu        $s0, $t8, $t9
    ctx->r16 = ADD32(ctx->r24, ctx->r25);
    // 0x80049C80: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
L_80049C84:
    // 0x80049C84: jal         0x8004A2D0
    // 0x80049C88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8004A2D0(rdram, ctx);
        goto after_1;
    // 0x80049C88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80049C8C: lw          $s1, 0x4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X4);
    // 0x80049C90: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80049C94: bne         $s1, $zero, L_80049C84
    if (ctx->r17 != 0) {
        // 0x80049C98: nop
    
            goto L_80049C84;
    }
    // 0x80049C98: nop

L_80049C9C:
    // 0x80049C9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80049CA0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80049CA4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80049CA8: jr          $ra
    // 0x80049CAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    TRACE_RETURN()
    return;
    // 0x80049CAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80049CB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80049CB0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80049CB4: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80049CB8: addiu       $a2, $a2, -0x6450
    ctx->r6 = ADD32(ctx->r6, -0X6450);
    // 0x80049CBC: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    // 0x80049CC0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80049CC4: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
L_80049CC8:
    // 0x80049CC8: bne         $v1, $v0, L_80049CD4
    if (ctx->r3 != ctx->r2) {
        // 0x80049CCC: nop
    
            goto L_80049CD4;
    }
    // 0x80049CCC: nop

    // 0x80049CD0: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_80049CD4:
    // 0x80049CD4: bnel        $v1, $a0, L_80049CE4
    if (ctx->r3 != ctx->r4) {
        // 0x80049CD8: sll         $t6, $v1, 2
        ctx->r14 = S32(ctx->r3 << 2);
            goto L_80049CE4;
    }
    goto skip_0;
    // 0x80049CD8: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    skip_0:
    // 0x80049CDC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80049CE0: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
L_80049CE4:
    // 0x80049CE4: addu        $t7, $a2, $t6
    ctx->r15 = ADD32(ctx->r6, ctx->r14);
    // 0x80049CE8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80049CEC: beql        $t8, $zero, L_80049CC8
    if (ctx->r24 == 0) {
        // 0x80049CF0: addu        $v1, $v1, $a1
        ctx->r3 = ADD32(ctx->r3, ctx->r5);
            goto L_80049CC8;
    }
    goto skip_1;
    // 0x80049CF0: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    skip_1:
    // 0x80049CF4: jr          $ra
    // 0x80049CF8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    TRACE_RETURN()
    return;
    // 0x80049CF8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80049CFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80049CFC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80049D00: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80049D04: addiu       $v0, $v0, -0x6450
    ctx->r2 = ADD32(ctx->r2, -0X6450);
    // 0x80049D08: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80049D0C: addiu       $t3, $zero, 0x100
    ctx->r11 = ADD32(0, 0X100);
    // 0x80049D10: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
L_80049D14:
    // 0x80049D14: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80049D18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80049D1C: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x80049D20: beq         $a0, $zero, L_80049D68
    if (ctx->r4 == 0) {
        // 0x80049D24: or          $t1, $a0, $zero
        ctx->r9 = ctx->r4 | 0;
            goto L_80049D68;
    }
    // 0x80049D24: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
L_80049D28:
    // 0x80049D28: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    // 0x80049D2C: lbu         $t6, 0x10($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X10);
    // 0x80049D30: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80049D34: beql        $a0, $t6, L_80049D50
    if (ctx->r4 == ctx->r14) {
        // 0x80049D38: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80049D50;
    }
    goto skip_0;
    // 0x80049D38: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_0:
    // 0x80049D3C: bne         $a0, $zero, L_80049D58
    if (ctx->r4 != 0) {
        // 0x80049D40: nop
    
            goto L_80049D58;
    }
    // 0x80049D40: nop

    // 0x80049D44: jr          $ra
    // 0x80049D48: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    TRACE_RETURN()
    return;
    // 0x80049D48: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80049D4C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80049D50:
    // 0x80049D50: bne         $a2, $t2, L_80049D28
    if (ctx->r6 != ctx->r10) {
        // 0x80049D54: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_80049D28;
    }
    // 0x80049D54: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_80049D58:
    // 0x80049D58: bnel        $a2, $t2, L_80049D6C
    if (ctx->r6 != ctx->r10) {
        // 0x80049D5C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80049D6C;
    }
    goto skip_1;
    // 0x80049D5C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_1:
    // 0x80049D60: jr          $ra
    // 0x80049D64: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    TRACE_RETURN()
    return;
    // 0x80049D64: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80049D68:
    // 0x80049D68: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80049D6C:
    // 0x80049D6C: bne         $v1, $t3, L_80049D14
    if (ctx->r3 != ctx->r11) {
        // 0x80049D70: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80049D14;
    }
    // 0x80049D70: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80049D74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80049D78: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80049D80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80049D80: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80049D84: addiu       $v0, $v0, -0x6450
    ctx->r2 = ADD32(ctx->r2, -0X6450);
    // 0x80049D88: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80049D8C: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80049D90: lw          $v1, 0x0($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X0);
    // 0x80049D94: bne         $v1, $zero, L_80049DA0
    if (ctx->r3 != 0) {
        // 0x80049D98: nop
    
            goto L_80049DA0;
    }
    // 0x80049D98: nop

    // 0x80049D9C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
L_80049DA0:
    // 0x80049DA0: jr          $ra
    // 0x80049DA4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    TRACE_RETURN()
    return;
    // 0x80049DA4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80049DA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80049DA8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80049DAC: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80049DB0: addiu       $a2, $a2, -0x6450
    ctx->r6 = ADD32(ctx->r6, -0X6450);
    // 0x80049DB4: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80049DB8: addu        $t7, $a2, $t6
    ctx->r15 = ADD32(ctx->r6, ctx->r14);
    // 0x80049DBC: lw          $v1, 0x0($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X0);
    // 0x80049DC0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80049DC4: bne         $v1, $zero, L_80049DF4
    if (ctx->r3 != 0) {
        // 0x80049DC8: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80049DF4;
    }
    // 0x80049DC8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80049DCC:
    // 0x80049DCC: slti        $at, $a1, 0x100
    ctx->r1 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    // 0x80049DD0: bnel        $at, $zero, L_80049DE0
    if (ctx->r1 != 0) {
        // 0x80049DD4: sll         $t8, $a1, 2
        ctx->r24 = S32(ctx->r5 << 2);
            goto L_80049DE0;
    }
    goto skip_0;
    // 0x80049DD4: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    skip_0:
    // 0x80049DD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80049DDC: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
L_80049DE0:
    // 0x80049DE0: addu        $t9, $a2, $t8
    ctx->r25 = ADD32(ctx->r6, ctx->r24);
    // 0x80049DE4: lw          $v1, 0x0($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X0);
    // 0x80049DE8: beql        $v1, $zero, L_80049DCC
    if (ctx->r3 == 0) {
        // 0x80049DEC: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80049DCC;
    }
    goto skip_1;
    // 0x80049DEC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_1:
    // 0x80049DF0: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
L_80049DF4:
    // 0x80049DF4: jr          $ra
    // 0x80049DF8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    TRACE_RETURN()
    return;
    // 0x80049DF8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80049DFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80049DFC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80049E00: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80049E04: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80049E08: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80049E0C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80049E10: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80049E14: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80049E18: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80049E1C: beq         $a1, $zero, L_80049E44
    if (ctx->r5 == 0) {
        // 0x80049E20: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_80049E44;
    }
    // 0x80049E20: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80049E24: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80049E28: beq         $a1, $at, L_80049E54
    if (ctx->r5 == ctx->r1) {
        // 0x80049E2C: lui         $t7, 0x8013
        ctx->r15 = S32(0X8013 << 16);
            goto L_80049E54;
    }
    // 0x80049E2C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80049E30: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80049E34: beq         $a1, $at, L_80049E60
    if (ctx->r5 == ctx->r1) {
        // 0x80049E38: lui         $t8, 0x8013
        ctx->r24 = S32(0X8013 << 16);
            goto L_80049E60;
    }
    // 0x80049E38: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80049E3C: b           L_80049E68
    // 0x80049E40: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
        goto L_80049E68;
    // 0x80049E40: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
L_80049E44:
    // 0x80049E44: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80049E48: lw          $t6, -0x6CA0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6CA0);
    // 0x80049E4C: b           L_80049E68
    // 0x80049E50: lw          $s0, 0xD4($t6)
    ctx->r16 = MEM_W(ctx->r14, 0XD4);
        goto L_80049E68;
    // 0x80049E50: lw          $s0, 0xD4($t6)
    ctx->r16 = MEM_W(ctx->r14, 0XD4);
L_80049E54:
    // 0x80049E54: lw          $t7, -0x6C9C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6C9C);
    // 0x80049E58: b           L_80049E68
    // 0x80049E5C: lw          $s0, 0xD4($t7)
    ctx->r16 = MEM_W(ctx->r15, 0XD4);
        goto L_80049E68;
    // 0x80049E5C: lw          $s0, 0xD4($t7)
    ctx->r16 = MEM_W(ctx->r15, 0XD4);
L_80049E60:
    // 0x80049E60: lw          $t8, -0x6C98($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6C98);
    // 0x80049E64: lw          $s0, 0xD4($t8)
    ctx->r16 = MEM_W(ctx->r24, 0XD4);
L_80049E68:
    // 0x80049E68: lui         $s5, 0x801A
    ctx->r21 = S32(0X801A << 16);
    // 0x80049E6C: addiu       $s5, $s5, 0x2800
    ctx->r21 = ADD32(ctx->r21, 0X2800);
    // 0x80049E70: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80049E74: jal         0x80004364
    // 0x80049E78: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x80049E78: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_0:
    // 0x80049E7C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80049E80: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80049E84: jal         0x8000C7C0
    // 0x80049E88: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_8000C7C0(rdram, ctx);
        goto after_1;
    // 0x80049E88: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_1:
    // 0x80049E8C: jal         0x8000F764
    // 0x80049E90: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_8000F764(rdram, ctx);
        goto after_2;
    // 0x80049E90: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_2:
    // 0x80049E94: sw          $v0, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r2;
    // 0x80049E98: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x80049E9C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80049EA0: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x80049EA4: lw          $t1, 0x8($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X8);
    // 0x80049EA8: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x80049EAC: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x80049EB0: lw          $t2, 0x8($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X8);
    // 0x80049EB4: sw          $s0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r16;
    // 0x80049EB8: lw          $t3, 0x8($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X8);
    // 0x80049EBC: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
    // 0x80049EC0: lw          $t4, 0x8($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X8);
    // 0x80049EC4: jal         0x8000F764
    // 0x80049EC8: sw          $s4, 0xDC($t4)
    MEM_W(0XDC, ctx->r12) = ctx->r20;
    func_8000F764(rdram, ctx);
        goto after_3;
    // 0x80049EC8: sw          $s4, 0xDC($t4)
    MEM_W(0XDC, ctx->r12) = ctx->r20;
    after_3:
    // 0x80049ECC: lw          $t5, 0x8($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X8);
    // 0x80049ED0: sw          $v0, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->r2;
    // 0x80049ED4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80049ED8: lw          $t6, 0xD4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XD4);
    // 0x80049EDC: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80049EE0: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x80049EE4: lw          $t8, 0x8($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X8);
    // 0x80049EE8: lw          $t1, 0xC($s3)
    ctx->r9 = MEM_W(ctx->r19, 0XC);
    // 0x80049EEC: lw          $t9, 0xD4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XD4);
    // 0x80049EF0: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80049EF4: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x80049EF8: lw          $t2, 0x8($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X8);
    // 0x80049EFC: lw          $t4, 0xC($s3)
    ctx->r12 = MEM_W(ctx->r19, 0XC);
    // 0x80049F00: lw          $t3, 0xD4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XD4);
    // 0x80049F04: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x80049F08: lw          $t6, 0x8($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X8);
    // 0x80049F0C: lw          $t5, 0xC($s3)
    ctx->r13 = MEM_W(ctx->r19, 0XC);
    // 0x80049F10: lw          $t7, 0xD4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XD4);
    // 0x80049F14: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x80049F18: lh          $a1, 0xC($s4)
    ctx->r5 = MEM_H(ctx->r20, 0XC);
    // 0x80049F1C: sll         $t8, $a1, 4
    ctx->r24 = S32(ctx->r5 << 4);
    // 0x80049F20: jal         0x80004364
    // 0x80049F24: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    func_80004364(rdram, ctx);
        goto after_4;
    // 0x80049F24: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_4:
    // 0x80049F28: lw          $t9, 0xC($s3)
    ctx->r25 = MEM_W(ctx->r19, 0XC);
    // 0x80049F2C: sw          $v0, 0xD0($t9)
    MEM_W(0XD0, ctx->r25) = ctx->r2;
    // 0x80049F30: lh          $a1, 0xC($s4)
    ctx->r5 = MEM_H(ctx->r20, 0XC);
    // 0x80049F34: lw          $t0, 0xC($s3)
    ctx->r8 = MEM_W(ctx->r19, 0XC);
    // 0x80049F38: sll         $t1, $a1, 4
    ctx->r9 = S32(ctx->r5 << 4);
    // 0x80049F3C: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x80049F40: jal         0x8000C7C0
    // 0x80049F44: lw          $a0, 0xD0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XD0);
    func_8000C7C0(rdram, ctx);
        goto after_5;
    // 0x80049F44: lw          $a0, 0xD0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XD0);
    after_5:
    // 0x80049F48: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80049F4C: jal         0x80004364
    // 0x80049F50: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    func_80004364(rdram, ctx);
        goto after_6;
    // 0x80049F50: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_6:
    // 0x80049F54: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x80049F58: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80049F5C: jal         0x8000C7C0
    // 0x80049F60: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    func_8000C7C0(rdram, ctx);
        goto after_7;
    // 0x80049F60: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_7:
    // 0x80049F64: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80049F68: jal         0x80004364
    // 0x80049F6C: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    func_80004364(rdram, ctx);
        goto after_8;
    // 0x80049F6C: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_8:
    // 0x80049F70: sw          $v0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r2;
    // 0x80049F74: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80049F78: jal         0x8000C7C0
    // 0x80049F7C: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    func_8000C7C0(rdram, ctx);
        goto after_9;
    // 0x80049F7C: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_9:
    // 0x80049F80: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x80049F84: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80049F88: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80049F8C: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x80049F90: lw          $t3, 0x4($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X4);
    // 0x80049F94: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
    // 0x80049F98: lw          $t4, 0x4($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X4);
    // 0x80049F9C: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80049FA0: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x80049FA4: lw          $t7, 0x4($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X4);
    // 0x80049FA8: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x80049FAC: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x80049FB0: lh          $t8, 0xC($s4)
    ctx->r24 = MEM_H(ctx->r20, 0XC);
    // 0x80049FB4: blez        $t8, L_8004A03C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80049FB8: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_8004A03C;
    }
    // 0x80049FB8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80049FBC:
    // 0x80049FBC: jal         0x80004364
    // 0x80049FC0: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    func_80004364(rdram, ctx);
        goto after_10;
    // 0x80049FC0: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_10:
    // 0x80049FC4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80049FC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80049FCC: jal         0x8000C7C0
    // 0x80049FD0: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    func_8000C7C0(rdram, ctx);
        goto after_11;
    // 0x80049FD0: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_11:
    // 0x80049FD4: lw          $t9, 0x4($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X4);
    // 0x80049FD8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80049FDC: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80049FE0: sw          $s0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r16;
    // 0x80049FE4: lw          $t1, 0x4($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X4);
    // 0x80049FE8: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80049FEC: sw          $t2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r10;
    // 0x80049FF0: lw          $t3, 0x4($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X4);
    // 0x80049FF4: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80049FF8: lw          $t4, 0x4($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X4);
    // 0x80049FFC: sw          $s0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r16;
    // 0x8004A000: lw          $t6, 0x4($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X4);
    // 0x8004A004: addu        $t5, $t6, $s1
    ctx->r13 = ADD32(ctx->r14, ctx->r17);
    // 0x8004A008: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8004A00C: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    // 0x8004A010: lw          $t8, 0xC($s3)
    ctx->r24 = MEM_W(ctx->r19, 0XC);
    // 0x8004A014: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
    // 0x8004A018: lw          $t9, 0x8($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X8);
    // 0x8004A01C: addu        $t0, $t9, $s1
    ctx->r8 = ADD32(ctx->r25, ctx->r17);
    // 0x8004A020: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8004A024: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8004A028: sw          $t1, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r9;
    // 0x8004A02C: lh          $t2, 0xC($s4)
    ctx->r10 = MEM_H(ctx->r20, 0XC);
    // 0x8004A030: slt         $at, $s2, $t2
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8004A034: bnel        $at, $zero, L_80049FBC
    if (ctx->r1 != 0) {
        // 0x8004A038: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80049FBC;
    }
    goto skip_0;
    // 0x8004A038: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_0:
L_8004A03C:
    // 0x8004A03C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8004A040: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x8004A044: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8004A048: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8004A04C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8004A050: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8004A054: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8004A058: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8004A05C: jr          $ra
    // 0x8004A060: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    TRACE_RETURN()
    return;
    // 0x8004A060: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
