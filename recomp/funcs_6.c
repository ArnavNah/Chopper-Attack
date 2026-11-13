#include "recomp.h"
#include "trace.h"
#include "funcs.h"

RECOMP_FUNC void func_80009874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80009874: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80009878: addiu       $v1, $v1, -0x4728
    ctx->r3 = ADD32(ctx->r3, -0X4728);
    // 0x8000987C: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x80009880: lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // 0x80009884: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80009888: bne         $t6, $zero, L_800098A4
    if (ctx->r14 != 0) {
        // 0x8000988C: addiu       $v0, $v0, -0x6908
        ctx->r2 = ADD32(ctx->r2, -0X6908);
            goto L_800098A4;
    }
    // 0x8000988C: addiu       $v0, $v0, -0x6908
    ctx->r2 = ADD32(ctx->r2, -0X6908);
    // 0x80009890: addiu       $t7, $t7, -0x4718
    ctx->r15 = ADD32(ctx->r15, -0X4718);
    // 0x80009894: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80009898: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000989C: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    // 0x800098A0: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
L_800098A4:
    // 0x800098A4: jr          $ra
    // 0x800098A8: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    TRACE_RETURN()
    return;
    // 0x800098A8: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
;}
RECOMP_FUNC void func_800098AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800098AC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800098B0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800098B4: lui         $s4, 0x8007
    ctx->r20 = S32(0X8007 << 16);
    // 0x800098B8: addiu       $s4, $s4, -0x7950
    ctx->r20 = ADD32(ctx->r20, -0X7950);
    // 0x800098BC: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x800098C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800098C4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800098C8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800098CC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800098D0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800098D4: beq         $t6, $zero, L_8000990C
    if (ctx->r14 == 0) {
        // 0x800098D8: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8000990C;
    }
    // 0x800098D8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800098DC: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x800098E0: addiu       $s1, $s1, -0x3F08
    ctx->r17 = ADD32(ctx->r17, -0X3F08);
    // 0x800098E4: addiu       $s2, $sp, 0x40
    ctx->r18 = ADD32(ctx->r29, 0X40);
    // 0x800098E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800098EC:
    // 0x800098EC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800098F0: jal         0x8004F990
    // 0x800098F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800098F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800098F8: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x800098FC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80009900: sltu        $at, $s0, $t7
    ctx->r1 = ctx->r16 < ctx->r15 ? 1 : 0;
    // 0x80009904: bnel        $at, $zero, L_800098EC
    if (ctx->r1 != 0) {
        // 0x80009908: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800098EC;
    }
    goto skip_0;
    // 0x80009908: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
L_8000990C:
    // 0x8000990C: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x80009910: addiu       $s2, $s2, -0x4728
    ctx->r18 = ADD32(ctx->r18, -0X4728);
    // 0x80009914: lw          $s0, 0x4($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X4);
    // 0x80009918: lui         $s3, 0x8007
    ctx->r19 = S32(0X8007 << 16);
    // 0x8000991C: addiu       $s3, $s3, -0x7954
    ctx->r19 = ADD32(ctx->r19, -0X7954);
    // 0x80009920: beq         $s0, $zero, L_8000998C
    if (ctx->r16 == 0) {
        // 0x80009924: nop
    
            goto L_8000998C;
    }
    // 0x80009924: nop

L_80009928:
    // 0x80009928: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x8000992C: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x80009930: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80009934: addiu       $t0, $t9, 0x2
    ctx->r8 = ADD32(ctx->r25, 0X2);
    // 0x80009938: sltu        $at, $t0, $t8
    ctx->r1 = ctx->r8 < ctx->r24 ? 1 : 0;
    // 0x8000993C: beq         $at, $zero, L_80009984
    if (ctx->r1 == 0) {
        // 0x80009940: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80009984;
    }
    // 0x80009940: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80009944: lw          $t1, 0x4($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X4);
    // 0x80009948: bne         $s0, $t1, L_80009954
    if (ctx->r16 != ctx->r9) {
        // 0x8000994C: nop
    
            goto L_80009954;
    }
    // 0x8000994C: nop

    // 0x80009950: sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
L_80009954:
    // 0x80009954: jal         0x800526C0
    // 0x80009958: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800526C0(rdram, ctx);
        goto after_1;
    // 0x80009958: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8000995C: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x80009960: beql        $a1, $zero, L_8000997C
    if (ctx->r5 == 0) {
        // 0x80009964: sw          $s0, 0x8($s2)
        MEM_W(0X8, ctx->r18) = ctx->r16;
            goto L_8000997C;
    }
    goto skip_1;
    // 0x80009964: sw          $s0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r16;
    skip_1:
    // 0x80009968: jal         0x800526F0
    // 0x8000996C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800526F0(rdram, ctx);
        goto after_2;
    // 0x8000996C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80009970: b           L_80009984
    // 0x80009974: nop

        goto L_80009984;
    // 0x80009974: nop

    // 0x80009978: sw          $s0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r16;
L_8000997C:
    // 0x8000997C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80009980: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
L_80009984:
    // 0x80009984: bne         $s1, $zero, L_80009928
    if (ctx->r17 != 0) {
        // 0x80009988: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80009928;
    }
    // 0x80009988: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_8000998C:
    // 0x8000998C: lui         $s3, 0x8007
    ctx->r19 = S32(0X8007 << 16);
    // 0x80009990: addiu       $s3, $s3, -0x7954
    ctx->r19 = ADD32(ctx->r19, -0X7954);
    // 0x80009994: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x80009998: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000999C: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
    // 0x800099A0: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800099A4: sw          $t3, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r11;
    // 0x800099A8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800099AC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800099B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800099B4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800099B8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800099BC: jr          $ra
    // 0x800099C0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    TRACE_RETURN()
    return;
    // 0x800099C0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_800099C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800099C4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800099C8: lwc1        $f0, 0x5E94($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5E94);
    // 0x800099CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800099D0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800099D4: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800099D8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800099DC: beq         $t6, $zero, L_80009A0C
    if (ctx->r14 == 0) {
        // 0x800099E0: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_80009A0C;
    }
    // 0x800099E0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
L_800099E4:
    // 0x800099E4: andi        $t7, $a0, 0x1
    ctx->r15 = ctx->r4 & 0X1;
    // 0x800099E8: beq         $t7, $zero, L_800099F8
    if (ctx->r15 == 0) {
        // 0x800099EC: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_800099F8;
    }
    // 0x800099EC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800099F0: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800099F4: nop

L_800099F8:
    // 0x800099F8: srl         $a0, $v0, 1
    ctx->r4 = S32(U32(ctx->r2) >> 1);
    // 0x800099FC: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80009A00: andi        $t8, $a0, 0xFF
    ctx->r24 = ctx->r4 & 0XFF;
    // 0x80009A04: bne         $t8, $zero, L_800099E4
    if (ctx->r24 != 0) {
        // 0x80009A08: or          $a0, $t8, $zero
        ctx->r4 = ctx->r24 | 0;
            goto L_800099E4;
    }
    // 0x80009A08: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
L_80009A0C:
    // 0x80009A0C: jr          $ra
    // 0x80009A10: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    TRACE_RETURN()
    return;
    // 0x80009A10: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void func_80009A14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80009A14: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80009A18: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80009A1C: addiu       $t0, $t0, -0x3364
    ctx->r8 = ADD32(ctx->r8, -0X3364);
    // 0x80009A20: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80009A24: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80009A28: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80009A2C: andi        $t7, $a3, 0xFF
    ctx->r15 = ctx->r7 & 0XFF;
    // 0x80009A30: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x80009A34: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80009A38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80009A3C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80009A40: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80009A44: andi        $t6, $a2, 0xFF
    ctx->r14 = ctx->r6 & 0XFF;
    // 0x80009A48: beq         $v1, $zero, L_80009CD4
    if (ctx->r3 == 0) {
        // 0x80009A4C: sw          $zero, 0x28($sp)
        MEM_W(0X28, ctx->r29) = 0;
            goto L_80009CD4;
    }
    // 0x80009A4C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80009A50: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80009A54: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80009A58: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x80009A5C: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80009A60: sb          $t6, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r14;
    // 0x80009A64: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x80009A68: lbu         $t9, 0x47($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X47);
    // 0x80009A6C: lbu         $a0, 0x43($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X43);
    // 0x80009A70: addiu       $t2, $zero, 0x103
    ctx->r10 = ADD32(0, 0X103);
    // 0x80009A74: sll         $t1, $t9, 14
    ctx->r9 = S32(ctx->r25 << 14);
    // 0x80009A78: beq         $t6, $at, L_80009ADC
    if (ctx->r14 == ctx->r1) {
        // 0x80009A7C: sw          $t1, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r9;
            goto L_80009ADC;
    }
    // 0x80009A7C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80009A80: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80009A84: beq         $t6, $at, L_80009B24
    if (ctx->r14 == ctx->r1) {
        // 0x80009A88: addiu       $v0, $zero, 0x7F
        ctx->r2 = ADD32(0, 0X7F);
            goto L_80009B24;
    }
    // 0x80009A88: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x80009A8C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80009A90: beq         $t6, $at, L_80009B60
    if (ctx->r14 == ctx->r1) {
        // 0x80009A94: addiu       $v0, $zero, 0x7F
        ctx->r2 = ADD32(0, 0X7F);
            goto L_80009B60;
    }
    // 0x80009A94: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x80009A98: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80009A9C: beq         $t6, $at, L_80009BA4
    if (ctx->r14 == ctx->r1) {
        // 0x80009AA0: lbu         $a0, 0x43($sp)
        ctx->r4 = MEM_BU(ctx->r29, 0X43);
            goto L_80009BA4;
    }
    // 0x80009AA0: lbu         $a0, 0x43($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X43);
    // 0x80009AA4: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x80009AA8: beq         $t6, $at, L_80009BEC
    if (ctx->r14 == ctx->r1) {
        // 0x80009AAC: lbu         $a0, 0x43($sp)
        ctx->r4 = MEM_BU(ctx->r29, 0X43);
            goto L_80009BEC;
    }
    // 0x80009AAC: lbu         $a0, 0x43($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X43);
    // 0x80009AB0: addiu       $at, $zero, 0x81
    ctx->r1 = ADD32(0, 0X81);
    // 0x80009AB4: beq         $t6, $at, L_80009C1C
    if (ctx->r14 == ctx->r1) {
        // 0x80009AB8: lbu         $a0, 0x43($sp)
        ctx->r4 = MEM_BU(ctx->r29, 0X43);
            goto L_80009C1C;
    }
    // 0x80009AB8: lbu         $a0, 0x43($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X43);
    // 0x80009ABC: addiu       $at, $zero, 0x82
    ctx->r1 = ADD32(0, 0X82);
    // 0x80009AC0: beq         $t6, $at, L_80009C64
    if (ctx->r14 == ctx->r1) {
        // 0x80009AC4: lbu         $a0, 0x43($sp)
        ctx->r4 = MEM_BU(ctx->r29, 0X43);
            goto L_80009C64;
    }
    // 0x80009AC4: lbu         $a0, 0x43($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X43);
    // 0x80009AC8: addiu       $at, $zero, 0x83
    ctx->r1 = ADD32(0, 0X83);
    // 0x80009ACC: beq         $t6, $at, L_80009C9C
    if (ctx->r14 == ctx->r1) {
        // 0x80009AD0: lbu         $a0, 0x43($sp)
        ctx->r4 = MEM_BU(ctx->r29, 0X43);
            goto L_80009C9C;
    }
    // 0x80009AD0: lbu         $a0, 0x43($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X43);
    // 0x80009AD4: b           L_80009CD8
    // 0x80009AD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80009CD8;
    // 0x80009AD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80009ADC:
    // 0x80009ADC: sra         $t5, $a0, 1
    ctx->r13 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80009AE0: addiu       $t6, $zero, 0x7F
    ctx->r14 = ADD32(0, 0X7F);
    // 0x80009AE4: subu        $t7, $t6, $t5
    ctx->r15 = SUB32(ctx->r14, ctx->r13);
    // 0x80009AE8: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80009AEC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80009AF0: subu        $t3, $t2, $a3
    ctx->r11 = SUB32(ctx->r10, ctx->r7);
    // 0x80009AF4: sh          $zero, 0x8($s0)
    MEM_H(0X8, ctx->r16) = 0;
    // 0x80009AF8: sh          $t3, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r11;
    // 0x80009AFC: sb          $t5, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r13;
    // 0x80009B00: sb          $t7, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r15;
    // 0x80009B04: bgez        $t8, L_80009B1C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80009B08: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80009B1C;
    }
    // 0x80009B08: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80009B0C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80009B10: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80009B14: nop

    // 0x80009B18: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80009B1C:
    // 0x80009B1C: b           L_80009CD4
    // 0x80009B20: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
        goto L_80009CD4;
    // 0x80009B20: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
L_80009B24:
    // 0x80009B24: lbu         $a0, 0x43($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X43);
    // 0x80009B28: addiu       $t9, $zero, 0x100
    ctx->r25 = ADD32(0, 0X100);
    // 0x80009B2C: subu        $t2, $t9, $a3
    ctx->r10 = SUB32(ctx->r25, ctx->r7);
    // 0x80009B30: addiu       $t3, $zero, 0x7F
    ctx->r11 = ADD32(0, 0X7F);
    // 0x80009B34: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80009B38: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80009B3C: subu        $t4, $t3, $a0
    ctx->r12 = SUB32(ctx->r11, ctx->r4);
    // 0x80009B40: sh          $t2, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r10;
    // 0x80009B44: sh          $t2, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r10;
    // 0x80009B48: sb          $zero, 0x5($s0)
    MEM_B(0X5, ctx->r16) = 0;
    // 0x80009B4C: sb          $t4, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r12;
    // 0x80009B50: sb          $v0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r2;
    // 0x80009B54: sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // 0x80009B58: b           L_80009CD4
    // 0x80009B5C: swc1        $f10, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
        goto L_80009CD4;
    // 0x80009B5C: swc1        $f10, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
L_80009B60:
    // 0x80009B60: lbu         $a0, 0x43($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X43);
    // 0x80009B64: andi        $t7, $v0, 0xFF
    ctx->r15 = ctx->r2 & 0XFF;
    // 0x80009B68: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80009B6C: addiu       $t6, $zero, 0x100
    ctx->r14 = ADD32(0, 0X100);
    // 0x80009B70: subu        $t5, $t6, $a3
    ctx->r13 = SUB32(ctx->r14, ctx->r7);
    // 0x80009B74: sh          $t5, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r13;
    // 0x80009B78: sh          $zero, 0x8($s0)
    MEM_H(0X8, ctx->r16) = 0;
    // 0x80009B7C: sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // 0x80009B80: sb          $a0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r4;
    // 0x80009B84: bgez        $t7, L_80009B9C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80009B88: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80009B9C;
    }
    // 0x80009B88: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80009B8C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80009B90: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80009B94: nop

    // 0x80009B98: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_80009B9C:
    // 0x80009B9C: b           L_80009CD4
    // 0x80009BA0: swc1        $f18, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f18.u32l;
        goto L_80009CD4;
    // 0x80009BA0: swc1        $f18, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f18.u32l;
L_80009BA4:
    // 0x80009BA4: addiu       $t1, $zero, 0x7F
    ctx->r9 = ADD32(0, 0X7F);
    // 0x80009BA8: subu        $t2, $t1, $a0
    ctx->r10 = SUB32(ctx->r9, ctx->r4);
    // 0x80009BAC: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x80009BB0: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80009BB4: addiu       $t8, $zero, 0x100
    ctx->r24 = ADD32(0, 0X100);
    // 0x80009BB8: subu        $t9, $t8, $a3
    ctx->r25 = SUB32(ctx->r24, ctx->r7);
    // 0x80009BBC: sh          $t9, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r25;
    // 0x80009BC0: sh          $zero, 0x8($s0)
    MEM_H(0X8, ctx->r16) = 0;
    // 0x80009BC4: sb          $a0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r4;
    // 0x80009BC8: sb          $t2, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r10;
    // 0x80009BCC: bgez        $t3, L_80009BE4
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80009BD0: cvt.s.w     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80009BE4;
    }
    // 0x80009BD0: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80009BD4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80009BD8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80009BDC: nop

    // 0x80009BE0: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_80009BE4:
    // 0x80009BE4: b           L_80009CD4
    // 0x80009BE8: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
        goto L_80009CD4;
    // 0x80009BE8: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
L_80009BEC:
    // 0x80009BEC: jal         0x800099C4
    // 0x80009BF0: sb          $a3, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r7;
    func_800099C4(rdram, ctx);
        goto after_0;
    // 0x80009BF0: sb          $a3, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r7;
    after_0:
    // 0x80009BF4: lbu         $a3, 0x3F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X3F);
    // 0x80009BF8: addiu       $t4, $zero, 0x103
    ctx->r12 = ADD32(0, 0X103);
    // 0x80009BFC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80009C00: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80009C04: subu        $t6, $t4, $a3
    ctx->r14 = SUB32(ctx->r12, ctx->r7);
    // 0x80009C08: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x80009C0C: sh          $zero, 0x8($s0)
    MEM_H(0X8, ctx->r16) = 0;
    // 0x80009C10: sh          $t6, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r14;
    // 0x80009C14: b           L_80009CD4
    // 0x80009C18: swc1        $f16, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
        goto L_80009CD4;
    // 0x80009C18: swc1        $f16, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
L_80009C1C:
    // 0x80009C1C: addiu       $t5, $zero, 0x100
    ctx->r13 = ADD32(0, 0X100);
    // 0x80009C20: subu        $t8, $t5, $a3
    ctx->r24 = SUB32(ctx->r13, ctx->r7);
    // 0x80009C24: sh          $t8, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r24;
    // 0x80009C28: sh          $t8, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r24;
    // 0x80009C2C: jal         0x800099C4
    // 0x80009C30: sb          $zero, 0x5($s0)
    MEM_B(0X5, ctx->r16) = 0;
    func_800099C4(rdram, ctx);
        goto after_1;
    // 0x80009C30: sb          $zero, 0x5($s0)
    MEM_B(0X5, ctx->r16) = 0;
    after_1:
    // 0x80009C34: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80009C38: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80009C3C: nop

    // 0x80009C40: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80009C44: jal         0x80053FD0
    // 0x80009C48: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    func_80053FD0(rdram, ctx);
        goto after_2;
    // 0x80009C48: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_2:
    // 0x80009C4C: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x80009C50: jal         0x80053FD0
    // 0x80009C54: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80053FD0(rdram, ctx);
        goto after_3;
    // 0x80009C54: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80009C58: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x80009C5C: b           L_80009CD4
    // 0x80009C60: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
        goto L_80009CD4;
    // 0x80009C60: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
L_80009C64:
    // 0x80009C64: addiu       $t1, $zero, 0x100
    ctx->r9 = ADD32(0, 0X100);
    // 0x80009C68: subu        $t3, $t1, $a3
    ctx->r11 = SUB32(ctx->r9, ctx->r7);
    // 0x80009C6C: sh          $t3, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r11;
    // 0x80009C70: jal         0x800099C4
    // 0x80009C74: sh          $t3, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r11;
    func_800099C4(rdram, ctx);
        goto after_4;
    // 0x80009C74: sh          $t3, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r11;
    after_4:
    // 0x80009C78: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80009C7C: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80009C80: nop

    // 0x80009C84: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x80009C88: sw          $t6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r14;
    // 0x80009C8C: jal         0x80053FD0
    // 0x80009C90: sw          $a0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r4;
    func_80053FD0(rdram, ctx);
        goto after_5;
    // 0x80009C90: sw          $a0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r4;
    after_5:
    // 0x80009C94: b           L_80009CD4
    // 0x80009C98: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
        goto L_80009CD4;
    // 0x80009C98: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
L_80009C9C:
    // 0x80009C9C: addiu       $t5, $zero, 0x100
    ctx->r13 = ADD32(0, 0X100);
    // 0x80009CA0: subu        $t8, $t5, $a3
    ctx->r24 = SUB32(ctx->r13, ctx->r7);
    // 0x80009CA4: sh          $t8, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r24;
    // 0x80009CA8: jal         0x800099C4
    // 0x80009CAC: sh          $t8, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r24;
    func_800099C4(rdram, ctx);
        goto after_6;
    // 0x80009CAC: sh          $t8, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r24;
    after_6:
    // 0x80009CB0: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80009CB4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80009CB8: nop

    // 0x80009CBC: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    // 0x80009CC0: sll         $t1, $a1, 1
    ctx->r9 = S32(ctx->r5 << 1);
    // 0x80009CC4: sw          $a0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r4;
    // 0x80009CC8: jal         0x80053FD0
    // 0x80009CCC: sw          $t1, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r9;
    func_80053FD0(rdram, ctx);
        goto after_7;
    // 0x80009CCC: sw          $t1, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r9;
    after_7:
    // 0x80009CD0: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
L_80009CD4:
    // 0x80009CD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80009CD8:
    // 0x80009CD8: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80009CDC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80009CE0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80009CE4: jr          $ra
    // 0x80009CE8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    TRACE_RETURN()
    return;
    // 0x80009CE8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80009CEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80009CEC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80009CF0: addiu       $t6, $zero, 0x3E80
    ctx->r14 = ADD32(0, 0X3E80);
    // 0x80009CF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80009CF8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80009CFC: lbu         $v0, 0x4($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X4);
    // 0x80009D00: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80009D04: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80009D08: beq         $v0, $at, L_80009D50
    if (ctx->r2 == ctx->r1) {
        // 0x80009D0C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80009D50;
    }
    // 0x80009D0C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80009D10: beq         $v0, $at, L_80009E2C
    if (ctx->r2 == ctx->r1) {
        // 0x80009D14: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80009E2C;
    }
    // 0x80009D14: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80009D18: beq         $v0, $at, L_80009EB0
    if (ctx->r2 == ctx->r1) {
        // 0x80009D1C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80009EB0;
    }
    // 0x80009D1C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80009D20: beq         $v0, $at, L_80009F64
    if (ctx->r2 == ctx->r1) {
        // 0x80009D24: addiu       $at, $zero, 0x80
        ctx->r1 = ADD32(0, 0X80);
            goto L_80009F64;
    }
    // 0x80009D24: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x80009D28: beq         $v0, $at, L_8000A018
    if (ctx->r2 == ctx->r1) {
        // 0x80009D2C: addiu       $at, $zero, 0x81
        ctx->r1 = ADD32(0, 0X81);
            goto L_8000A018;
    }
    // 0x80009D2C: addiu       $at, $zero, 0x81
    ctx->r1 = ADD32(0, 0X81);
    // 0x80009D30: beq         $v0, $at, L_8000A0C4
    if (ctx->r2 == ctx->r1) {
        // 0x80009D34: addiu       $at, $zero, 0x82
        ctx->r1 = ADD32(0, 0X82);
            goto L_8000A0C4;
    }
    // 0x80009D34: addiu       $at, $zero, 0x82
    ctx->r1 = ADD32(0, 0X82);
    // 0x80009D38: beq         $v0, $at, L_8000A110
    if (ctx->r2 == ctx->r1) {
        // 0x80009D3C: addiu       $at, $zero, 0x83
        ctx->r1 = ADD32(0, 0X83);
            goto L_8000A110;
    }
    // 0x80009D3C: addiu       $at, $zero, 0x83
    ctx->r1 = ADD32(0, 0X83);
    // 0x80009D40: beql        $v0, $at, L_8000A1B8
    if (ctx->r2 == ctx->r1) {
        // 0x80009D44: lhu         $t7, 0x8($a2)
        ctx->r15 = MEM_HU(ctx->r6, 0X8);
            goto L_8000A1B8;
    }
    goto skip_0;
    // 0x80009D44: lhu         $t7, 0x8($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X8);
    skip_0:
    // 0x80009D48: b           L_8000A258
    // 0x80009D4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000A258;
    // 0x80009D4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80009D50:
    // 0x80009D50: lhu         $t7, 0x8($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X8);
    // 0x80009D54: lhu         $v1, 0x6($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X6);
    // 0x80009D58: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80009D5C: andi        $v0, $t8, 0xFFFF
    ctx->r2 = ctx->r24 & 0XFFFF;
    // 0x80009D60: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80009D64: bne         $at, $zero, L_80009D78
    if (ctx->r1 != 0) {
        // 0x80009D68: sh          $t8, 0x8($a2)
        MEM_H(0X8, ctx->r6) = ctx->r24;
            goto L_80009D78;
    }
    // 0x80009D68: sh          $t8, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r24;
    // 0x80009D6C: sh          $zero, 0x8($a2)
    MEM_H(0X8, ctx->r6) = 0;
    // 0x80009D70: andi        $v0, $zero, 0xFFFF
    ctx->r2 = 0 & 0XFFFF;
    // 0x80009D74: lhu         $v1, 0x6($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X6);
L_80009D78:
    // 0x80009D78: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80009D7C: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x80009D80: bgez        $v0, L_80009D98
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80009D84: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80009D98;
    }
    // 0x80009D84: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80009D88: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80009D8C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80009D90: nop

    // 0x80009D94: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80009D98:
    // 0x80009D98: bgez        $v1, L_80009DB0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80009D9C: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80009DB0;
    }
    // 0x80009D9C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80009DA0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80009DA4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80009DA8: nop

    // 0x80009DAC: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_80009DB0:
    // 0x80009DB0: div.s       $f2, $f6, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80009DB4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80009DB8: ldc1        $f8, 0x5E98($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X5E98);
    // 0x80009DBC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80009DC0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80009DC4: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x80009DC8: mul.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x80009DCC: jal         0x8004F7C0
    // 0x80009DD0: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    func_8004F7C0(rdram, ctx);
        goto after_0;
    // 0x80009DD0: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    after_0:
    // 0x80009DD4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80009DD8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80009DDC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80009DE0: lbu         $t9, 0xC($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0XC);
    // 0x80009DE4: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80009DE8: bgez        $t9, L_80009DFC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80009DEC: cvt.s.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80009DFC;
    }
    // 0x80009DEC: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80009DF0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80009DF4: nop

    // 0x80009DF8: add.s       $f6, $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f16.fl;
L_80009DFC:
    // 0x80009DFC: lbu         $t0, 0xD($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0XD);
    // 0x80009E00: mul.s       $f2, $f6, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80009E04: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80009E08: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80009E0C: bgez        $t0, L_80009E20
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80009E10: cvt.s.w     $f8, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80009E20;
    }
    // 0x80009E10: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80009E14: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80009E18: nop

    // 0x80009E1C: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_80009E20:
    // 0x80009E20: add.s       $f18, $f8, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x80009E24: b           L_8000A254
    // 0x80009E28: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
        goto L_8000A254;
    // 0x80009E28: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
L_80009E2C:
    // 0x80009E2C: lbu         $t1, 0x5($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X5);
    // 0x80009E30: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80009E34: bnel        $t1, $zero, L_80009E6C
    if (ctx->r9 != 0) {
        // 0x80009E38: lbu         $t4, 0xD($a2)
        ctx->r12 = MEM_BU(ctx->r6, 0XD);
            goto L_80009E6C;
    }
    goto skip_1;
    // 0x80009E38: lbu         $t4, 0xD($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0XD);
    skip_1:
    // 0x80009E3C: lbu         $t2, 0xE($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0XE);
    // 0x80009E40: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80009E44: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x80009E48: bgez        $t2, L_80009E5C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80009E4C: cvt.s.w     $f6, $f16
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80009E5C;
    }
    // 0x80009E4C: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80009E50: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80009E54: nop

    // 0x80009E58: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
L_80009E5C:
    // 0x80009E5C: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x80009E60: b           L_80009E90
    // 0x80009E64: sb          $t3, 0x5($a2)
    MEM_B(0X5, ctx->r6) = ctx->r11;
        goto L_80009E90;
    // 0x80009E64: sb          $t3, 0x5($a2)
    MEM_B(0X5, ctx->r6) = ctx->r11;
    // 0x80009E68: lbu         $t4, 0xD($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0XD);
L_80009E6C:
    // 0x80009E6C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80009E70: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x80009E74: bgez        $t4, L_80009E88
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80009E78: cvt.s.w     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80009E88;
    }
    // 0x80009E78: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80009E7C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80009E80: nop

    // 0x80009E84: add.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f18.fl;
L_80009E88:
    // 0x80009E88: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x80009E8C: sb          $zero, 0x5($a2)
    MEM_B(0X5, ctx->r6) = 0;
L_80009E90:
    // 0x80009E90: lhu         $t5, 0x6($a2)
    ctx->r13 = MEM_HU(ctx->r6, 0X6);
    // 0x80009E94: sll         $t6, $t5, 5
    ctx->r14 = S32(ctx->r13 << 5);
    // 0x80009E98: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80009E9C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80009EA0: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80009EA4: sll         $t6, $t6, 7
    ctx->r14 = S32(ctx->r14 << 7);
    // 0x80009EA8: b           L_8000A254
    // 0x80009EAC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
        goto L_8000A254;
    // 0x80009EAC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_80009EB0:
    // 0x80009EB0: lhu         $t7, 0x8($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X8);
    // 0x80009EB4: lhu         $v1, 0x6($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X6);
    // 0x80009EB8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80009EBC: andi        $v0, $t8, 0xFFFF
    ctx->r2 = ctx->r24 & 0XFFFF;
    // 0x80009EC0: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80009EC4: beq         $at, $zero, L_80009ED8
    if (ctx->r1 == 0) {
        // 0x80009EC8: sh          $t8, 0x8($a2)
        MEM_H(0X8, ctx->r6) = ctx->r24;
            goto L_80009ED8;
    }
    // 0x80009EC8: sh          $t8, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r24;
    // 0x80009ECC: sh          $zero, 0x8($a2)
    MEM_H(0X8, ctx->r6) = 0;
    // 0x80009ED0: andi        $v0, $zero, 0xFFFF
    ctx->r2 = 0 & 0XFFFF;
    // 0x80009ED4: lhu         $v1, 0x6($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X6);
L_80009ED8:
    // 0x80009ED8: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x80009EDC: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x80009EE0: bgez        $v0, L_80009EF8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80009EE4: cvt.s.w     $f4, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80009EF8;
    }
    // 0x80009EE4: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80009EE8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80009EEC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80009EF0: nop

    // 0x80009EF4: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_80009EF8:
    // 0x80009EF8: bgez        $v1, L_80009F10
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80009EFC: cvt.s.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80009F10;
    }
    // 0x80009EFC: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80009F00: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80009F04: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80009F08: nop

    // 0x80009F0C: add.s       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f8.fl;
L_80009F10:
    // 0x80009F10: lbu         $t9, 0xD($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0XD);
    // 0x80009F14: div.s       $f2, $f4, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80009F18: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80009F1C: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80009F20: bgez        $t9, L_80009F34
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80009F24: cvt.s.w     $f6, $f16
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80009F34;
    }
    // 0x80009F24: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80009F28: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80009F2C: nop

    // 0x80009F30: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_80009F34:
    // 0x80009F34: lbu         $t0, 0xC($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0XC);
    // 0x80009F38: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80009F3C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80009F40: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x80009F44: bgez        $t0, L_80009F58
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80009F48: cvt.s.w     $f4, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80009F58;
    }
    // 0x80009F48: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80009F4C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80009F50: nop

    // 0x80009F54: add.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f18.fl;
L_80009F58:
    // 0x80009F58: sub.s       $f16, $f4, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x80009F5C: b           L_8000A254
    // 0x80009F60: swc1        $f16, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
        goto L_8000A254;
    // 0x80009F60: swc1        $f16, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
L_80009F64:
    // 0x80009F64: lhu         $t1, 0x8($a2)
    ctx->r9 = MEM_HU(ctx->r6, 0X8);
    // 0x80009F68: lhu         $v1, 0x6($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X6);
    // 0x80009F6C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80009F70: andi        $v0, $t2, 0xFFFF
    ctx->r2 = ctx->r10 & 0XFFFF;
    // 0x80009F74: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80009F78: beq         $at, $zero, L_80009F8C
    if (ctx->r1 == 0) {
        // 0x80009F7C: sh          $t2, 0x8($a2)
        MEM_H(0X8, ctx->r6) = ctx->r10;
            goto L_80009F8C;
    }
    // 0x80009F7C: sh          $t2, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r10;
    // 0x80009F80: sh          $zero, 0x8($a2)
    MEM_H(0X8, ctx->r6) = 0;
    // 0x80009F84: andi        $v0, $zero, 0xFFFF
    ctx->r2 = 0 & 0XFFFF;
    // 0x80009F88: lhu         $v1, 0x6($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X6);
L_80009F8C:
    // 0x80009F8C: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80009F90: mtc1        $v1, $f18
    ctx->f18.u32l = ctx->r3;
    // 0x80009F94: bgez        $v0, L_80009FAC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80009F98: cvt.s.w     $f6, $f10
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80009FAC;
    }
    // 0x80009F98: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80009F9C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80009FA0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80009FA4: nop

    // 0x80009FA8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80009FAC:
    // 0x80009FAC: bgez        $v1, L_80009FC4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80009FB0: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80009FC4;
    }
    // 0x80009FB0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80009FB4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80009FB8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80009FBC: nop

    // 0x80009FC0: add.s       $f4, $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f16.fl;
L_80009FC4:
    // 0x80009FC4: lbu         $t3, 0xD($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0XD);
    // 0x80009FC8: div.s       $f2, $f6, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80009FCC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80009FD0: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80009FD4: bgez        $t3, L_80009FE8
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80009FD8: cvt.s.w     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80009FE8;
    }
    // 0x80009FD8: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80009FDC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80009FE0: nop

    // 0x80009FE4: add.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f18.fl;
L_80009FE8:
    // 0x80009FE8: lbu         $t4, 0xC($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0XC);
    // 0x80009FEC: mul.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80009FF0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80009FF4: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80009FF8: bgez        $t4, L_8000A00C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80009FFC: cvt.s.w     $f6, $f16
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8000A00C;
    }
    // 0x80009FFC: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8000A000: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000A004: nop

    // 0x8000A008: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
L_8000A00C:
    // 0x8000A00C: add.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8000A010: b           L_8000A254
    // 0x8000A014: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
        goto L_8000A254;
    // 0x8000A014: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
L_8000A018:
    // 0x8000A018: lhu         $t5, 0x8($a2)
    ctx->r13 = MEM_HU(ctx->r6, 0X8);
    // 0x8000A01C: lhu         $v1, 0x6($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X6);
    // 0x8000A020: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8000A024: andi        $v0, $t6, 0xFFFF
    ctx->r2 = ctx->r14 & 0XFFFF;
    // 0x8000A028: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000A02C: bne         $at, $zero, L_8000A040
    if (ctx->r1 != 0) {
        // 0x8000A030: sh          $t6, 0x8($a2)
        MEM_H(0X8, ctx->r6) = ctx->r14;
            goto L_8000A040;
    }
    // 0x8000A030: sh          $t6, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r14;
    // 0x8000A034: sh          $zero, 0x8($a2)
    MEM_H(0X8, ctx->r6) = 0;
    // 0x8000A038: andi        $v0, $zero, 0xFFFF
    ctx->r2 = 0 & 0XFFFF;
    // 0x8000A03C: lhu         $v1, 0x6($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X6);
L_8000A040:
    // 0x8000A040: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x8000A044: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x8000A048: bgez        $v0, L_8000A060
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000A04C: cvt.s.w     $f8, $f18
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8000A060;
    }
    // 0x8000A04C: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000A050: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000A054: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000A058: nop

    // 0x8000A05C: add.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f16.fl;
L_8000A060:
    // 0x8000A060: bgez        $v1, L_8000A078
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8000A064: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8000A078;
    }
    // 0x8000A064: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000A068: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000A06C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000A070: nop

    // 0x8000A074: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_8000A078:
    // 0x8000A078: div.s       $f2, $f8, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8000A07C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000A080: ldc1        $f16, 0x5EA0($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, 0X5EA0);
    // 0x8000A084: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8000A088: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8000A08C: cvt.d.s     $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f18.d = CVT_D_S(ctx->f2.fl);
    // 0x8000A090: mul.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f16.d);
    // 0x8000A094: jal         0x8004F7C0
    // 0x8000A098: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    func_8004F7C0(rdram, ctx);
        goto after_1;
    // 0x8000A098: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    after_1:
    // 0x8000A09C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8000A0A0: lwc1        $f10, 0xC($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0XC);
    // 0x8000A0A4: mul.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8000A0A8: trunc.w.s   $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8000A0AC: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x8000A0B0: jal         0x80053FD0
    // 0x8000A0B4: nop

    func_80053FD0(rdram, ctx);
        goto after_2;
    // 0x8000A0B4: nop

    after_2:
    // 0x8000A0B8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8000A0BC: b           L_8000A254
    // 0x8000A0C0: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
        goto L_8000A254;
    // 0x8000A0C0: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
L_8000A0C4:
    // 0x8000A0C4: lbu         $t8, 0x5($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X5);
    // 0x8000A0C8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8000A0CC: bnel        $t8, $zero, L_8000A0E8
    if (ctx->r24 != 0) {
        // 0x8000A0D0: lwc1        $f18, 0x10($a2)
        ctx->f18.u32l = MEM_W(ctx->r6, 0X10);
            goto L_8000A0E8;
    }
    goto skip_2;
    // 0x8000A0D0: lwc1        $f18, 0x10($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X10);
    skip_2:
    // 0x8000A0D4: lwc1        $f6, 0xC($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0XC);
    // 0x8000A0D8: sb          $t9, 0x5($a2)
    MEM_B(0X5, ctx->r6) = ctx->r25;
    // 0x8000A0DC: b           L_8000A0F0
    // 0x8000A0E0: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
        goto L_8000A0F0;
    // 0x8000A0E0: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x8000A0E4: lwc1        $f18, 0x10($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X10);
L_8000A0E8:
    // 0x8000A0E8: sb          $zero, 0x5($a2)
    MEM_B(0X5, ctx->r6) = 0;
    // 0x8000A0EC: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
L_8000A0F0:
    // 0x8000A0F0: lhu         $t0, 0x6($a2)
    ctx->r8 = MEM_HU(ctx->r6, 0X6);
    // 0x8000A0F4: sll         $t1, $t0, 5
    ctx->r9 = S32(ctx->r8 << 5);
    // 0x8000A0F8: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8000A0FC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8000A100: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8000A104: sll         $t1, $t1, 7
    ctx->r9 = S32(ctx->r9 << 7);
    // 0x8000A108: b           L_8000A254
    // 0x8000A10C: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
        goto L_8000A254;
    // 0x8000A10C: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
L_8000A110:
    // 0x8000A110: lhu         $t2, 0x8($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X8);
    // 0x8000A114: lhu         $v1, 0x6($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X6);
    // 0x8000A118: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8000A11C: andi        $v0, $t3, 0xFFFF
    ctx->r2 = ctx->r11 & 0XFFFF;
    // 0x8000A120: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000A124: beq         $at, $zero, L_8000A138
    if (ctx->r1 == 0) {
        // 0x8000A128: sh          $t3, 0x8($a2)
        MEM_H(0X8, ctx->r6) = ctx->r11;
            goto L_8000A138;
    }
    // 0x8000A128: sh          $t3, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r11;
    // 0x8000A12C: sh          $zero, 0x8($a2)
    MEM_H(0X8, ctx->r6) = 0;
    // 0x8000A130: andi        $v0, $zero, 0xFFFF
    ctx->r2 = 0 & 0XFFFF;
    // 0x8000A134: lhu         $v1, 0x6($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X6);
L_8000A138:
    // 0x8000A138: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x8000A13C: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x8000A140: bgez        $v0, L_8000A158
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000A144: cvt.s.w     $f4, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8000A158;
    }
    // 0x8000A144: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8000A148: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000A14C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000A150: nop

    // 0x8000A154: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
L_8000A158:
    // 0x8000A158: bgez        $v1, L_8000A170
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8000A15C: cvt.s.w     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8000A170;
    }
    // 0x8000A15C: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000A160: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000A164: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8000A168: nop

    // 0x8000A16C: add.s       $f6, $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f18.fl;
L_8000A170:
    // 0x8000A170: div.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8000A174: lw          $t4, 0x10($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X10);
    // 0x8000A178: lw          $t5, 0xC($a2)
    ctx->r13 = MEM_W(ctx->r6, 0XC);
    // 0x8000A17C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8000A180: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x8000A184: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8000A188: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8000A18C: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000A190: mul.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8000A194: sub.s       $f2, $f18, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x8000A198: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8000A19C: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x8000A1A0: jal         0x80053FD0
    // 0x8000A1A4: nop

    func_80053FD0(rdram, ctx);
        goto after_3;
    // 0x8000A1A4: nop

    after_3:
    // 0x8000A1A8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8000A1AC: b           L_8000A254
    // 0x8000A1B0: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
        goto L_8000A254;
    // 0x8000A1B0: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x8000A1B4: lhu         $t7, 0x8($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X8);
L_8000A1B8:
    // 0x8000A1B8: lhu         $v1, 0x6($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X6);
    // 0x8000A1BC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8000A1C0: andi        $v0, $t8, 0xFFFF
    ctx->r2 = ctx->r24 & 0XFFFF;
    // 0x8000A1C4: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000A1C8: beq         $at, $zero, L_8000A1DC
    if (ctx->r1 == 0) {
        // 0x8000A1CC: sh          $t8, 0x8($a2)
        MEM_H(0X8, ctx->r6) = ctx->r24;
            goto L_8000A1DC;
    }
    // 0x8000A1CC: sh          $t8, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r24;
    // 0x8000A1D0: sh          $zero, 0x8($a2)
    MEM_H(0X8, ctx->r6) = 0;
    // 0x8000A1D4: andi        $v0, $zero, 0xFFFF
    ctx->r2 = 0 & 0XFFFF;
    // 0x8000A1D8: lhu         $v1, 0x6($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X6);
L_8000A1DC:
    // 0x8000A1DC: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8000A1E0: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x8000A1E4: bgez        $v0, L_8000A1FC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000A1E8: cvt.s.w     $f16, $f6
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8000A1FC;
    }
    // 0x8000A1E8: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000A1EC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000A1F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000A1F4: nop

    // 0x8000A1F8: add.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f10.fl;
L_8000A1FC:
    // 0x8000A1FC: bgez        $v1, L_8000A214
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8000A200: cvt.s.w     $f18, $f8
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8000A214;
    }
    // 0x8000A200: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000A204: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000A208: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000A20C: nop

    // 0x8000A210: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_8000A214:
    // 0x8000A214: div.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8000A218: lw          $t9, 0x10($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X10);
    // 0x8000A21C: lw          $t0, 0xC($a2)
    ctx->r8 = MEM_W(ctx->r6, 0XC);
    // 0x8000A220: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8000A224: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8000A228: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8000A22C: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000A230: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000A234: mul.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8000A238: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8000A23C: trunc.w.s   $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8000A240: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x8000A244: jal         0x80053FD0
    // 0x8000A248: nop

    func_80053FD0(rdram, ctx);
        goto after_4;
    // 0x8000A248: nop

    after_4:
    // 0x8000A24C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8000A250: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
L_8000A254:
    // 0x8000A254: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000A258:
    // 0x8000A258: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8000A25C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000A260: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000A268(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000A268: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000A26C: addiu       $v0, $v0, -0x3364
    ctx->r2 = ADD32(ctx->r2, -0X3364);
    // 0x8000A270: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8000A274: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8000A278: jr          $ra
    // 0x8000A27C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    TRACE_RETURN()
    return;
    // 0x8000A27C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
;}
RECOMP_FUNC void func_8000A280(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000A280: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000A284: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000A288: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000A28C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000A290: addiu       $a1, $a1, -0x2E08
    ctx->r5 = ADD32(ctx->r5, -0X2E08);
    // 0x8000A294: addiu       $a0, $a0, -0x2E38
    ctx->r4 = ADD32(ctx->r4, -0X2E38);
    // 0x8000A298: jal         0x800544DC
    // 0x8000A29C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osPfsInitPak_recomp(rdram, ctx);
        goto after_0;
    // 0x8000A29C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8000A2A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000A2A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000A2A8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000A2B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000A2B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000A2B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000A2B8: jal         0x8000A9E0
    // 0x8000A2BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_8000A9E0(rdram, ctx);
        goto after_0;
    // 0x8000A2BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8000A2C0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8000A2C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000A2C8: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8000A2CC: sh          $t6, -0x2D48($at)
    MEM_H(-0X2D48, ctx->r1) = ctx->r14;
    // 0x8000A2D0: addiu       $s0, $s0, -0x2E38
    ctx->r16 = ADD32(ctx->r16, -0X2E38);
    // 0x8000A2D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000A2D8: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8000A2DC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000A2E0: sh          $t7, -0x2D70($at)
    MEM_H(-0X2D70, ctx->r1) = ctx->r15;
    // 0x8000A2E4: addiu       $a1, $a1, -0x2E20
    ctx->r5 = ADD32(ctx->r5, -0X2E20);
    // 0x8000A2E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000A2EC: jal         0x80052780
    // 0x8000A2F0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x8000A2F0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x8000A2F4: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8000A2F8: addiu       $a2, $a2, -0x2D70
    ctx->r6 = ADD32(ctx->r6, -0X2D70);
    // 0x8000A2FC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8000A300: jal         0x800547C0
    // 0x8000A304: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    osSetEventMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x8000A304: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8000A308: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000A30C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8000A310: addiu       $a2, $a2, -0x2D98
    ctx->r6 = ADD32(ctx->r6, -0X2D98);
    // 0x8000A314: addiu       $a1, $a1, -0x2E3D
    ctx->r5 = ADD32(ctx->r5, -0X2E3D);
    // 0x8000A318: jal         0x80054830
    // 0x8000A31C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    osContInit_recomp(rdram, ctx);
        goto after_3;
    // 0x8000A31C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8000A320: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8000A324: lw          $t8, -0x2E40($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2E40);
    // 0x8000A328: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000A32C: sh          $zero, -0x2D20($at)
    MEM_H(-0X2D20, ctx->r1) = 0;
    // 0x8000A330: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8000A334: beq         $t9, $zero, L_8000A370
    if (ctx->r25 == 0) {
        // 0x8000A338: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8000A370;
    }
    // 0x8000A338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000A33C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000A340: addiu       $a1, $a1, -0x2E08
    ctx->r5 = ADD32(ctx->r5, -0X2E08);
    // 0x8000A344: jal         0x80054BF0
    // 0x8000A348: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osMotorInit_recomp(rdram, ctx);
        goto after_4;
    // 0x8000A348: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x8000A34C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000A350: addiu       $a1, $a1, -0x2E08
    ctx->r5 = ADD32(ctx->r5, -0X2E08);
    // 0x8000A354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000A358: jal         0x800544DC
    // 0x8000A35C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osPfsInitPak_recomp(rdram, ctx);
        goto after_5;
    // 0x8000A35C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8000A360: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8000A364: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000A368: jal         0x8000AA94
    // 0x8000A36C: sh          $t0, -0x2D20($at)
    MEM_H(-0X2D20, ctx->r1) = ctx->r8;
    func_8000AA94(rdram, ctx);
        goto after_6;
    // 0x8000A36C: sh          $t0, -0x2D20($at)
    MEM_H(-0X2D20, ctx->r1) = ctx->r8;
    after_6:
L_8000A370:
    // 0x8000A370: jal         0x80054CB0
    // 0x8000A374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    osPfsIsPlug_recomp(rdram, ctx);
        goto after_7;
    // 0x8000A374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8000A378: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8000A37C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000A380: sh          $v0, -0x2DA0($at)
    MEM_H(-0X2DA0, ctx->r1) = ctx->r2;
    // 0x8000A384: addiu       $v1, $v1, -0x2D24
    ctx->r3 = ADD32(ctx->r3, -0X2D24);
    // 0x8000A388: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x8000A38C: lh          $t1, 0x0($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X0);
    // 0x8000A390: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000A394: addiu       $a0, $a0, -0x2D26
    ctx->r4 = ADD32(ctx->r4, -0X2D26);
    // 0x8000A398: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000A39C: sh          $t1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r9;
    // 0x8000A3A0: lh          $t2, 0x0($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X0);
    // 0x8000A3A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000A3A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000A3AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000A3B0: jr          $ra
    // 0x8000A3B4: sh          $t2, -0x2D28($at)
    MEM_H(-0X2D28, ctx->r1) = ctx->r10;
    TRACE_RETURN()
    return;
    // 0x8000A3B4: sh          $t2, -0x2D28($at)
    MEM_H(-0X2D28, ctx->r1) = ctx->r10;
;}
RECOMP_FUNC void func_8000A3B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000A3B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000A3BC: sh          $a0, -0x2D30($at)
    MEM_H(-0X2D30, ctx->r1) = ctx->r4;
    // 0x8000A3C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000A3C4: sw          $a1, -0x2D2C($at)
    MEM_W(-0X2D2C, ctx->r1) = ctx->r5;
    // 0x8000A3C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000A3CC: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8000A3D0: sh          $t8, -0x2D28($at)
    MEM_H(-0X2D28, ctx->r1) = ctx->r24;
    // 0x8000A3D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000A3D8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8000A3DC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8000A3E0: jr          $ra
    // 0x8000A3E4: sh          $t9, -0x2D26($at)
    MEM_H(-0X2D26, ctx->r1) = ctx->r25;
    TRACE_RETURN()
    return;
    // 0x8000A3E4: sh          $t9, -0x2D26($at)
    MEM_H(-0X2D26, ctx->r1) = ctx->r25;
;}
RECOMP_FUNC void func_8000A3E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000A3E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000A3EC: sh          $a0, -0x2D30($at)
    MEM_H(-0X2D30, ctx->r1) = ctx->r4;
    // 0x8000A3F0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000A3F4: sw          $a1, -0x2D2C($at)
    MEM_W(-0X2D2C, ctx->r1) = ctx->r5;
    // 0x8000A3F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000A3FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000A400: sh          $v0, -0x2D28($at)
    MEM_H(-0X2D28, ctx->r1) = ctx->r2;
    // 0x8000A404: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000A408: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8000A40C: jr          $ra
    // 0x8000A410: sh          $v0, -0x2D26($at)
    MEM_H(-0X2D26, ctx->r1) = ctx->r2;
    TRACE_RETURN()
    return;
    // 0x8000A410: sh          $v0, -0x2D26($at)
    MEM_H(-0X2D26, ctx->r1) = ctx->r2;
;}
RECOMP_FUNC void func_8000A414(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000A414: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000A418: jr          $ra
    // 0x8000A41C: lh          $v0, -0x2D26($v0)
    // Clear busy flag so asynchronous controller/pfs checks never deadlock the game logic thread
    MEM_H(-0X2D26, ctx->r2) = 0;
    ctx->r2 = 0;
    TRACE_RETURN()
    return;
    // 0x8000A41C: lh          $v0, -0x2D26($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2D26);
;}
RECOMP_FUNC void func_8000A420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000A420: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000A424: addiu       $a1, $a1, -0x2D24
    ctx->r5 = ADD32(ctx->r5, -0X2D24);
    // 0x8000A428: lh          $v0, 0x0($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X0);
    // 0x8000A42C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000A430: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000A434: beq         $v0, $zero, L_8000A448
    if (ctx->r2 == 0) {
        // 0x8000A438: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8000A448;
    }
    // 0x8000A438: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000A43C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8000A440: b           L_8000A51C
    // 0x8000A444: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
        goto L_8000A51C;
    // 0x8000A444: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
L_8000A448:
    // 0x8000A448: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000A44C: lh          $v0, -0x2D28($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2D28);
    // 0x8000A450: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000A454: beql        $v0, $zero, L_8000A520
    if (ctx->r2 == 0) {
        // 0x8000A458: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8000A520;
    }
    goto skip_0;
    // 0x8000A458: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8000A45C: beq         $v0, $at, L_8000A478
    if (ctx->r2 == ctx->r1) {
        // 0x8000A460: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8000A478;
    }
    // 0x8000A460: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000A464: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000A468: beq         $v0, $at, L_8000A4C4
    if (ctx->r2 == ctx->r1) {
        // 0x8000A46C: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8000A4C4;
    }
    // 0x8000A46C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000A470: b           L_8000A50C
    // 0x8000A474: nop

        goto L_8000A50C;
    // 0x8000A474: nop

L_8000A478:
    // 0x8000A478: jal         0x80054CB0
    // 0x8000A47C: addiu       $a0, $a0, -0x2E38
    ctx->r4 = ADD32(ctx->r4, -0X2E38);
    osPfsIsPlug_recomp(rdram, ctx);
        goto after_0;
    // 0x8000A47C: addiu       $a0, $a0, -0x2E38
    ctx->r4 = ADD32(ctx->r4, -0X2E38);
    after_0:
    // 0x8000A480: beq         $v0, $zero, L_8000A4B0
    if (ctx->r2 == 0) {
        ctx->r1 = S32(0X800E << 16);
        MEM_H(-0X2D28, ctx->r1) = 0;
        MEM_H(-0X2D26, ctx->r1) = 0;
        // 0x8000A484: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8000A4B0;
    }
    // 0x8000A484: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000A488: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000A48C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8000A490: lw          $a2, -0x2D2C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X2D2C);
    // 0x8000A494: lbu         $a1, -0x2D2F($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2D2F);
    // 0x8000A498: jal         0x80054D20
    // 0x8000A49C: addiu       $a0, $a0, -0x2E38
    ctx->r4 = ADD32(ctx->r4, -0X2E38);
    func_80054D20(rdram, ctx);
        goto after_1;
    // 0x8000A49C: addiu       $a0, $a0, -0x2E38
    ctx->r4 = ADD32(ctx->r4, -0X2E38);
    after_1:
    // 0x8000A4A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000A4A4: sh          $v0, -0x2D26($at)
    MEM_H(-0X2D26, ctx->r1) = ctx->r2;
    // 0x8000A4A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000A4AC: sh          $zero, -0x2D28($at)
    MEM_H(-0X2D28, ctx->r1) = 0;
L_8000A4B0:
    // 0x8000A4B0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000A4B4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000A4B8: addiu       $a1, $a1, -0x2D24
    ctx->r5 = ADD32(ctx->r5, -0X2D24);
    // 0x8000A4BC: b           L_8000A50C
    // 0x8000A4C0: lh          $v0, -0x2D28($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2D28);
        goto L_8000A50C;
    // 0x8000A4C0: lh          $v0, -0x2D28($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2D28);
L_8000A4C4:
    // 0x8000A4C4: jal         0x80054CB0
    // 0x8000A4C8: addiu       $a0, $a0, -0x2E38
    ctx->r4 = ADD32(ctx->r4, -0X2E38);
    osPfsIsPlug_recomp(rdram, ctx);
        goto after_2;
    // 0x8000A4C8: addiu       $a0, $a0, -0x2E38
    ctx->r4 = ADD32(ctx->r4, -0X2E38);
    after_2:
    // 0x8000A4CC: beq         $v0, $zero, L_8000A4FC
    if (ctx->r2 == 0) {
        ctx->r1 = S32(0X800E << 16);
        MEM_H(-0X2D28, ctx->r1) = 0;
        MEM_H(-0X2D26, ctx->r1) = 0;
        // 0x8000A4D0: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8000A4FC;
    }
    // 0x8000A4D0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000A4D4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000A4D8: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8000A4DC: lw          $a2, -0x2D2C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X2D2C);
    // 0x8000A4E0: lbu         $a1, -0x2D2F($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2D2F);
    // 0x8000A4E4: jal         0x80055020
    // 0x8000A4E8: addiu       $a0, $a0, -0x2E38
    ctx->r4 = ADD32(ctx->r4, -0X2E38);
    func_80055020(rdram, ctx);
        goto after_3;
    // 0x8000A4E8: addiu       $a0, $a0, -0x2E38
    ctx->r4 = ADD32(ctx->r4, -0X2E38);
    after_3:
    // 0x8000A4EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000A4F0: sh          $v0, -0x2D26($at)
    MEM_H(-0X2D26, ctx->r1) = ctx->r2;
    // 0x8000A4F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000A4F8: sh          $zero, -0x2D28($at)
    MEM_H(-0X2D28, ctx->r1) = 0;
L_8000A4FC:
    // 0x8000A4FC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000A500: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000A504: addiu       $a1, $a1, -0x2D24
    ctx->r5 = ADD32(ctx->r5, -0X2D24);
    // 0x8000A508: lh          $v0, -0x2D28($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2D28);
L_8000A50C:
    // 0x8000A50C: bne         $v0, $zero, L_8000A51C
    if (ctx->r2 != 0) {
        // 0x8000A510: addiu       $v1, $zero, -0x2
        ctx->r3 = ADD32(0, -0X2);
            goto L_8000A51C;
    }
    // 0x8000A510: addiu       $v1, $zero, -0x2
    ctx->r3 = ADD32(0, -0X2);
    // 0x8000A514: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8000A518: sh          $t7, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r15;
L_8000A51C:
    // 0x8000A51C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000A520:
    // 0x8000A520: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000A524: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8000A528: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000A530(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000A530: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8000A534: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8000A538: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000A53C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000A540: jal         0x800555C4
    // 0x8000A544: addiu       $a0, $a0, -0x2D88
    ctx->r4 = ADD32(ctx->r4, -0X2D88);
    osContGetReadData_recomp(rdram, ctx);
        goto after_0;
    // 0x8000A544: addiu       $a0, $a0, -0x2D88
    ctx->r4 = ADD32(ctx->r4, -0X2D88);
    after_0:
    // 0x8000A548: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8000A54C: lw          $t6, -0x2E40($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E40);
    // 0x8000A550: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000A554: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8000A558: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8000A55C: beq         $t7, $zero, L_8000A988
    if (ctx->r15 == 0) {
        // 0x8000A560: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_8000A988;
    }
    // 0x8000A560: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8000A564: lhu         $t8, -0x2D88($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X2D88);
    // 0x8000A568: lhu         $t9, -0x2D50($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X2D50);
    // 0x8000A56C: addiu       $a0, $a0, -0x2D46
    ctx->r4 = ADD32(ctx->r4, -0X2D46);
    // 0x8000A570: lh          $v1, 0x0($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X0);
    // 0x8000A574: xor         $t6, $t9, $t8
    ctx->r14 = ctx->r25 ^ ctx->r24;
    // 0x8000A578: and         $a1, $t6, $t8
    ctx->r5 = ctx->r14 & ctx->r24;
    // 0x8000A57C: andi        $t7, $a1, 0xFFFF
    ctx->r15 = ctx->r5 & 0XFFFF;
    // 0x8000A580: bne         $v1, $zero, L_8000A5A4
    if (ctx->r3 != 0) {
        // 0x8000A584: or          $a1, $t7, $zero
        ctx->r5 = ctx->r15 | 0;
            goto L_8000A5A4;
    }
    // 0x8000A584: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x8000A588: beq         $t8, $zero, L_8000A5A4
    if (ctx->r24 == 0) {
        // 0x8000A58C: or          $a2, $t8, $zero
        ctx->r6 = ctx->r24 | 0;
            goto L_8000A5A4;
    }
    // 0x8000A58C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x8000A590: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000A594: sh          $t8, -0x2E5C($at)
    MEM_H(-0X2E5C, ctx->r1) = ctx->r24;
    // 0x8000A598: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8000A59C: b           L_8000A5B8
    // 0x8000A5A0: sh          $t9, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r25;
        goto L_8000A5B8;
    // 0x8000A5A0: sh          $t9, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r25;
L_8000A5A4:
    // 0x8000A5A4: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8000A5A8: bne         $v1, $zero, L_8000A5B8
    if (ctx->r3 != 0) {
        // 0x8000A5AC: lhu         $a2, -0x2D88($a2)
        ctx->r6 = MEM_HU(ctx->r6, -0X2D88);
            goto L_8000A5B8;
    }
    // 0x8000A5AC: lhu         $a2, -0x2D88($a2)
    ctx->r6 = MEM_HU(ctx->r6, -0X2D88);
    // 0x8000A5B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000A5B4: sh          $zero, -0x2E5C($at)
    MEM_H(-0X2E5C, ctx->r1) = 0;
L_8000A5B8:
    // 0x8000A5B8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000A5BC: addiu       $a0, $a0, -0x2D44
    ctx->r4 = ADD32(ctx->r4, -0X2D44);
    // 0x8000A5C0: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x8000A5C4: bne         $v0, $zero, L_8000A5FC
    if (ctx->r2 != 0) {
        // 0x8000A5C8: nop
    
            goto L_8000A5FC;
    }
    // 0x8000A5C8: nop

    // 0x8000A5CC: beq         $a1, $zero, L_8000A5FC
    if (ctx->r5 == 0) {
        // 0x8000A5D0: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_8000A5FC;
    }
    // 0x8000A5D0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8000A5D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000A5D8: sh          $a1, -0x2E5A($at)
    MEM_H(-0X2E5A, ctx->r1) = ctx->r5;
    // 0x8000A5DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000A5E0: addiu       $v1, $v1, -0x2D42
    ctx->r3 = ADD32(ctx->r3, -0X2D42);
    // 0x8000A5E4: sh          $a1, -0x2E58($at)
    MEM_H(-0X2E58, ctx->r1) = ctx->r5;
    // 0x8000A5E8: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x8000A5EC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8000A5F0: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
    // 0x8000A5F4: b           L_8000A610
    // 0x8000A5F8: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
        goto L_8000A610;
    // 0x8000A5F8: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
L_8000A5FC:
    // 0x8000A5FC: bne         $v0, $zero, L_8000A610
    if (ctx->r2 != 0) {
        // 0x8000A600: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8000A610;
    }
    // 0x8000A600: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000A604: sh          $zero, -0x2E5A($at)
    MEM_H(-0X2E5A, ctx->r1) = 0;
    // 0x8000A608: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000A60C: sh          $zero, -0x2E58($at)
    MEM_H(-0X2E58, ctx->r1) = 0;
L_8000A610:
    // 0x8000A610: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8000A614: addiu       $v1, $v1, -0x2D42
    ctx->r3 = ADD32(ctx->r3, -0X2D42);
    // 0x8000A618: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x8000A61C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000A620: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8000A624: beq         $v0, $zero, L_8000A638
    if (ctx->r2 == 0) {
        // 0x8000A628: lui         $ra, 0x800E
        ctx->r31 = S32(0X800E << 16);
            goto L_8000A638;
    }
    // 0x8000A628: lui         $ra, 0x800E
    ctx->r31 = S32(0X800E << 16);
    // 0x8000A62C: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x8000A630: b           L_8000A650
    // 0x8000A634: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
        goto L_8000A650;
    // 0x8000A634: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
L_8000A638:
    // 0x8000A638: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8000A63C: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
    // 0x8000A640: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8000A644: lhu         $t6, -0x2E5C($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X2E5C);
    // 0x8000A648: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000A64C: sh          $t6, -0x2E58($at)
    MEM_H(-0X2E58, ctx->r1) = ctx->r14;
L_8000A650:
    // 0x8000A650: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8000A654: lb          $v1, -0x2D86($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X2D86);
    // 0x8000A658: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000A65C: sh          $a2, -0x2D50($at)
    MEM_H(-0X2D50, ctx->r1) = ctx->r6;
    // 0x8000A660: bgez        $v1, L_8000A66C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8000A664: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8000A66C;
    }
    // 0x8000A664: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8000A668: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_8000A66C:
    // 0x8000A66C: addiu       $v0, $v0, -0xA
    ctx->r2 = ADD32(ctx->r2, -0XA);
    // 0x8000A670: bgez        $v0, L_8000A67C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000A674: addiu       $ra, $ra, -0x2D34
        ctx->r31 = ADD32(ctx->r31, -0X2D34);
            goto L_8000A67C;
    }
    // 0x8000A674: addiu       $ra, $ra, -0x2D34
    ctx->r31 = ADD32(ctx->r31, -0X2D34);
    // 0x8000A678: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000A67C:
    // 0x8000A67C: slti        $at, $v0, 0x3D
    ctx->r1 = SIGNED(ctx->r2) < 0X3D ? 1 : 0;
    // 0x8000A680: bne         $at, $zero, L_8000A68C
    if (ctx->r1 != 0) {
        // 0x8000A684: addiu       $t5, $sp, 0x40
        ctx->r13 = ADD32(ctx->r29, 0X40);
            goto L_8000A68C;
    }
    // 0x8000A684: addiu       $t5, $sp, 0x40
    ctx->r13 = ADD32(ctx->r29, 0X40);
    // 0x8000A688: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
L_8000A68C:
    // 0x8000A68C: bgez        $v1, L_8000A698
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8000A690: lui         $t4, 0x800E
        ctx->r12 = S32(0X800E << 16);
            goto L_8000A698;
    }
    // 0x8000A690: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8000A694: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_8000A698:
    // 0x8000A698: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8000A69C: lb          $v1, -0x2D85($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X2D85);
    // 0x8000A6A0: addiu       $a0, $a0, -0x2E60
    ctx->r4 = ADD32(ctx->r4, -0X2E60);
    // 0x8000A6A4: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x8000A6A8: bgez        $v1, L_8000A6B4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8000A6AC: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8000A6B4;
    }
    // 0x8000A6AC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8000A6B0: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_8000A6B4:
    // 0x8000A6B4: addiu       $v0, $v0, -0xA
    ctx->r2 = ADD32(ctx->r2, -0XA);
    // 0x8000A6B8: bgez        $v0, L_8000A6C4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000A6BC: addiu       $t4, $t4, -0x2D38
        ctx->r12 = ADD32(ctx->r12, -0X2D38);
            goto L_8000A6C4;
    }
    // 0x8000A6BC: addiu       $t4, $t4, -0x2D38
    ctx->r12 = ADD32(ctx->r12, -0X2D38);
    // 0x8000A6C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000A6C4:
    // 0x8000A6C4: slti        $at, $v0, 0x3D
    ctx->r1 = SIGNED(ctx->r2) < 0X3D ? 1 : 0;
    // 0x8000A6C8: bne         $at, $zero, L_8000A6D4
    if (ctx->r1 != 0) {
        // 0x8000A6CC: addiu       $t3, $sp, 0x3C
        ctx->r11 = ADD32(ctx->r29, 0X3C);
            goto L_8000A6D4;
    }
    // 0x8000A6CC: addiu       $t3, $sp, 0x3C
    ctx->r11 = ADD32(ctx->r29, 0X3C);
    // 0x8000A6D0: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
L_8000A6D4:
    // 0x8000A6D4: bgez        $v1, L_8000A6E0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8000A6D8: nop
    
            goto L_8000A6E0;
    }
    // 0x8000A6D8: nop

    // 0x8000A6DC: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_8000A6E0:
    // 0x8000A6E0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8000A6E4: addiu       $v1, $v1, -0x2E5E
    ctx->r3 = ADD32(ctx->r3, -0X2E5E);
    // 0x8000A6E8: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x8000A6EC: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x8000A6F0: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x8000A6F4: addiu       $t2, $sp, 0x38
    ctx->r10 = ADD32(ctx->r29, 0X38);
    // 0x8000A6F8: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x8000A6FC: sh          $t7, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r15;
    // 0x8000A700: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x8000A704: sh          $t9, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r25;
L_8000A708:
    // 0x8000A708: sll         $v1, $t1, 1
    ctx->r3 = S32(ctx->r9 << 1);
    // 0x8000A70C: addu        $t7, $t5, $v1
    ctx->r15 = ADD32(ctx->r13, ctx->r3);
    // 0x8000A710: lh          $a2, 0x0($t7)
    ctx->r6 = MEM_H(ctx->r15, 0X0);
    // 0x8000A714: addu        $t0, $ra, $v1
    ctx->r8 = ADD32(ctx->r31, ctx->r3);
    // 0x8000A718: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8000A71C: sll         $v0, $a2, 16
    ctx->r2 = S32(ctx->r6 << 16);
    // 0x8000A720: sra         $t8, $v0, 16
    ctx->r24 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8000A724: bgez        $t8, L_8000A738
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8000A728: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_8000A738;
    }
    // 0x8000A728: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8000A72C: negu        $v0, $t8
    ctx->r2 = SUB32(0, ctx->r24);
    // 0x8000A730: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x8000A734: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
L_8000A738:
    // 0x8000A738: slti        $at, $v0, 0x33
    ctx->r1 = SIGNED(ctx->r2) < 0X33 ? 1 : 0;
    // 0x8000A73C: bne         $at, $zero, L_8000A74C
    if (ctx->r1 != 0) {
        // 0x8000A740: addiu       $t6, $t6, -0x2D40
        ctx->r14 = ADD32(ctx->r14, -0X2D40);
            goto L_8000A74C;
    }
    // 0x8000A740: addiu       $t6, $t6, -0x2D40
    ctx->r14 = ADD32(ctx->r14, -0X2D40);
    // 0x8000A744: b           L_8000A750
    // 0x8000A748: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8000A750;
    // 0x8000A748: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000A74C:
    // 0x8000A74C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000A750:
    // 0x8000A750: lh          $t7, 0x0($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X0);
    // 0x8000A754: addu        $a0, $v1, $t6
    ctx->r4 = ADD32(ctx->r3, ctx->r14);
    // 0x8000A758: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8000A75C: xor         $t8, $t7, $v0
    ctx->r24 = ctx->r15 ^ ctx->r2;
    // 0x8000A760: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x8000A764: and         $a1, $t8, $v0
    ctx->r5 = ctx->r24 & ctx->r2;
    // 0x8000A768: andi        $t9, $a1, 0xFFFF
    ctx->r25 = ctx->r5 & 0XFFFF;
    // 0x8000A76C: bne         $t7, $zero, L_8000A780
    if (ctx->r15 != 0) {
        // 0x8000A770: or          $a1, $t9, $zero
        ctx->r5 = ctx->r25 | 0;
            goto L_8000A780;
    }
    // 0x8000A770: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x8000A774: beq         $v0, $zero, L_8000A780
    if (ctx->r2 == 0) {
        // 0x8000A778: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8000A780;
    }
    // 0x8000A778: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8000A77C: sh          $t8, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r24;
L_8000A780:
    // 0x8000A780: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8000A784: addiu       $t9, $t9, -0x2D3C
    ctx->r25 = ADD32(ctx->r25, -0X2D3C);
    // 0x8000A788: addu        $v0, $v1, $t9
    ctx->r2 = ADD32(ctx->r3, ctx->r25);
    // 0x8000A78C: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x8000A790: bne         $a0, $zero, L_8000A7C4
    if (ctx->r4 != 0) {
        // 0x8000A794: nop
    
            goto L_8000A7C4;
    }
    // 0x8000A794: nop

    // 0x8000A798: beq         $a1, $zero, L_8000A7C4
    if (ctx->r5 == 0) {
        // 0x8000A79C: addu        $t6, $t3, $v1
        ctx->r14 = ADD32(ctx->r11, ctx->r3);
            goto L_8000A7C4;
    }
    // 0x8000A79C: addu        $t6, $t3, $v1
    ctx->r14 = ADD32(ctx->r11, ctx->r3);
    // 0x8000A7A0: sh          $a2, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r6;
    // 0x8000A7A4: addu        $t7, $t2, $v1
    ctx->r15 = ADD32(ctx->r10, ctx->r3);
    // 0x8000A7A8: sh          $a2, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r6;
    // 0x8000A7AC: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x8000A7B0: addu        $t9, $t4, $v1
    ctx->r25 = ADD32(ctx->r12, ctx->r3);
    // 0x8000A7B4: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
    // 0x8000A7B8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8000A7BC: b           L_8000A7D8
    // 0x8000A7C0: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
        goto L_8000A7D8;
    // 0x8000A7C0: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
L_8000A7C4:
    // 0x8000A7C4: bne         $a0, $zero, L_8000A7D8
    if (ctx->r4 != 0) {
        // 0x8000A7C8: addu        $t7, $t3, $v1
        ctx->r15 = ADD32(ctx->r11, ctx->r3);
            goto L_8000A7D8;
    }
    // 0x8000A7C8: addu        $t7, $t3, $v1
    ctx->r15 = ADD32(ctx->r11, ctx->r3);
    // 0x8000A7CC: sh          $zero, 0x0($t7)
    MEM_H(0X0, ctx->r15) = 0;
    // 0x8000A7D0: addu        $t8, $t2, $v1
    ctx->r24 = ADD32(ctx->r10, ctx->r3);
    // 0x8000A7D4: sh          $zero, 0x0($t8)
    MEM_H(0X0, ctx->r24) = 0;
L_8000A7D8:
    // 0x8000A7D8: addu        $v0, $t4, $v1
    ctx->r2 = ADD32(ctx->r12, ctx->r3);
    // 0x8000A7DC: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x8000A7E0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8000A7E4: andi        $t8, $t1, 0xFFFF
    ctx->r24 = ctx->r9 & 0XFFFF;
    // 0x8000A7E8: beq         $a0, $zero, L_8000A7FC
    if (ctx->r4 == 0) {
        // 0x8000A7EC: or          $t1, $t8, $zero
        ctx->r9 = ctx->r24 | 0;
            goto L_8000A7FC;
    }
    // 0x8000A7EC: or          $t1, $t8, $zero
    ctx->r9 = ctx->r24 | 0;
    // 0x8000A7F0: addiu       $t9, $a0, -0x1
    ctx->r25 = ADD32(ctx->r4, -0X1);
    // 0x8000A7F4: b           L_8000A80C
    // 0x8000A7F8: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
        goto L_8000A80C;
    // 0x8000A7F8: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
L_8000A7FC:
    // 0x8000A7FC: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8000A800: addu        $t7, $t2, $v1
    ctx->r15 = ADD32(ctx->r10, ctx->r3);
    // 0x8000A804: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
    // 0x8000A808: sh          $a2, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r6;
L_8000A80C:
    // 0x8000A80C: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x8000A810: bne         $at, $zero, L_8000A708
    if (ctx->r1 != 0) {
        // 0x8000A814: sh          $a3, 0x0($t0)
        MEM_H(0X0, ctx->r8) = ctx->r7;
            goto L_8000A708;
    }
    // 0x8000A814: sh          $a3, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r7;
    // 0x8000A818: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000A81C: addiu       $a1, $a1, -0x2E4A
    ctx->r5 = ADD32(ctx->r5, -0X2E4A);
    // 0x8000A820: lh          $t9, 0x3C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X3C);
    // 0x8000A824: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x8000A828: lh          $a2, 0x0($a1)
    ctx->r6 = MEM_H(ctx->r5, 0X0);
    // 0x8000A82C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8000A830: addiu       $a3, $a3, -0x2E56
    ctx->r7 = ADD32(ctx->r7, -0X2E56);
    // 0x8000A834: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8000A838: addiu       $v1, $v1, -0x2E4C
    ctx->r3 = ADD32(ctx->r3, -0X2E4C);
    // 0x8000A83C: sh          $t9, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r25;
    // 0x8000A840: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8000A844: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
    // 0x8000A848: lh          $t6, 0x3E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X3E);
    // 0x8000A84C: lh          $t7, 0x38($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X38);
    // 0x8000A850: lh          $t8, 0x3A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X3A);
    // 0x8000A854: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x8000A858: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000A85C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8000A860: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8000A864: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8000A868: addiu       $t2, $t2, -0x2E50
    ctx->r10 = ADD32(ctx->r10, -0X2E50);
    // 0x8000A86C: addiu       $t1, $t1, -0x2E52
    ctx->r9 = ADD32(ctx->r9, -0X2E52);
    // 0x8000A870: addiu       $t0, $t0, -0x2E54
    ctx->r8 = ADD32(ctx->r8, -0X2E54);
    // 0x8000A874: addiu       $v0, $v0, -0x2E4E
    ctx->r2 = ADD32(ctx->r2, -0X2E4E);
    // 0x8000A878: sh          $t6, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r14;
    // 0x8000A87C: sh          $t7, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r15;
    // 0x8000A880: sh          $t8, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r24;
    // 0x8000A884: blez        $t9, L_8000A89C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8000A888: sh          $a0, 0x0($v0)
        MEM_H(0X0, ctx->r2) = ctx->r4;
            goto L_8000A89C;
    }
    // 0x8000A888: sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
    // 0x8000A88C: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8000A890: ori         $t7, $t6, 0x100
    ctx->r15 = ctx->r14 | 0X100;
    // 0x8000A894: b           L_8000A8B4
    // 0x8000A898: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
        goto L_8000A8B4;
    // 0x8000A898: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
L_8000A89C:
    // 0x8000A89C: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8000A8A0: bgezl       $t8, L_8000A8B8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8000A8A4: lw          $t7, 0x30($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X30);
            goto L_8000A8B8;
    }
    goto skip_0;
    // 0x8000A8A4: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    skip_0:
    // 0x8000A8A8: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x8000A8AC: ori         $t6, $t9, 0x200
    ctx->r14 = ctx->r25 | 0X200;
    // 0x8000A8B0: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
L_8000A8B4:
    // 0x8000A8B4: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
L_8000A8B8:
    // 0x8000A8B8: blezl       $t7, L_8000A8D4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8000A8BC: lw          $t6, 0x30($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X30);
            goto L_8000A8D4;
    }
    goto skip_1;
    // 0x8000A8BC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    skip_1:
    // 0x8000A8C0: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x8000A8C4: ori         $t9, $t8, 0x800
    ctx->r25 = ctx->r24 | 0X800;
    // 0x8000A8C8: b           L_8000A8E8
    // 0x8000A8CC: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
        goto L_8000A8E8;
    // 0x8000A8CC: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x8000A8D0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
L_8000A8D4:
    // 0x8000A8D4: bgezl       $t6, L_8000A8EC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8000A8D8: lh          $v0, 0x0($a3)
        ctx->r2 = MEM_H(ctx->r7, 0X0);
            goto L_8000A8EC;
    }
    goto skip_2;
    // 0x8000A8D8: lh          $v0, 0x0($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X0);
    skip_2:
    // 0x8000A8DC: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x8000A8E0: ori         $t8, $t7, 0x400
    ctx->r24 = ctx->r15 | 0X400;
    // 0x8000A8E4: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
L_8000A8E8:
    // 0x8000A8E8: lh          $v0, 0x0($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X0);
L_8000A8EC:
    // 0x8000A8EC: blez        $v0, L_8000A8FC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000A8F0: ori         $t9, $a0, 0x100
        ctx->r25 = ctx->r4 | 0X100;
            goto L_8000A8FC;
    }
    // 0x8000A8F0: ori         $t9, $a0, 0x100
    ctx->r25 = ctx->r4 | 0X100;
    // 0x8000A8F4: b           L_8000A908
    // 0x8000A8F8: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
        goto L_8000A908;
    // 0x8000A8F8: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
L_8000A8FC:
    // 0x8000A8FC: bgez        $v0, L_8000A908
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000A900: ori         $t6, $a0, 0x200
        ctx->r14 = ctx->r4 | 0X200;
            goto L_8000A908;
    }
    // 0x8000A900: ori         $t6, $a0, 0x200
    ctx->r14 = ctx->r4 | 0X200;
    // 0x8000A904: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
L_8000A908:
    // 0x8000A908: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x8000A90C: blez        $v0, L_8000A924
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000A910: nop
    
            goto L_8000A924;
    }
    // 0x8000A910: nop

    // 0x8000A914: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x8000A918: ori         $t8, $t7, 0x800
    ctx->r24 = ctx->r15 | 0X800;
    // 0x8000A91C: b           L_8000A938
    // 0x8000A920: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
        goto L_8000A938;
    // 0x8000A920: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
L_8000A924:
    // 0x8000A924: bgezl       $v0, L_8000A93C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000A928: lh          $v0, 0x0($t1)
        ctx->r2 = MEM_H(ctx->r9, 0X0);
            goto L_8000A93C;
    }
    goto skip_3;
    // 0x8000A928: lh          $v0, 0x0($t1)
    ctx->r2 = MEM_H(ctx->r9, 0X0);
    skip_3:
    // 0x8000A92C: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x8000A930: ori         $t6, $t9, 0x400
    ctx->r14 = ctx->r25 | 0X400;
    // 0x8000A934: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
L_8000A938:
    // 0x8000A938: lh          $v0, 0x0($t1)
    ctx->r2 = MEM_H(ctx->r9, 0X0);
L_8000A93C:
    // 0x8000A93C: blez        $v0, L_8000A94C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000A940: ori         $t7, $a2, 0x100
        ctx->r15 = ctx->r6 | 0X100;
            goto L_8000A94C;
    }
    // 0x8000A940: ori         $t7, $a2, 0x100
    ctx->r15 = ctx->r6 | 0X100;
    // 0x8000A944: b           L_8000A958
    // 0x8000A948: sh          $t7, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r15;
        goto L_8000A958;
    // 0x8000A948: sh          $t7, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r15;
L_8000A94C:
    // 0x8000A94C: bgez        $v0, L_8000A958
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000A950: ori         $t8, $a2, 0x200
        ctx->r24 = ctx->r6 | 0X200;
            goto L_8000A958;
    }
    // 0x8000A950: ori         $t8, $a2, 0x200
    ctx->r24 = ctx->r6 | 0X200;
    // 0x8000A954: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
L_8000A958:
    // 0x8000A958: lh          $v0, 0x0($t2)
    ctx->r2 = MEM_H(ctx->r10, 0X0);
    // 0x8000A95C: blez        $v0, L_8000A974
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000A960: nop
    
            goto L_8000A974;
    }
    // 0x8000A960: nop

    // 0x8000A964: lh          $t9, 0x0($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X0);
    // 0x8000A968: ori         $t6, $t9, 0x800
    ctx->r14 = ctx->r25 | 0X800;
    // 0x8000A96C: b           L_8000A988
    // 0x8000A970: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
        goto L_8000A988;
    // 0x8000A970: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
L_8000A974:
    // 0x8000A974: bgezl       $v0, L_8000A98C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000A978: lh          $t9, 0x5A($sp)
        ctx->r25 = MEM_H(ctx->r29, 0X5A);
            goto L_8000A98C;
    }
    goto skip_4;
    // 0x8000A978: lh          $t9, 0x5A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X5A);
    skip_4:
    // 0x8000A97C: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
    // 0x8000A980: ori         $t8, $t7, 0x400
    ctx->r24 = ctx->r15 | 0X400;
    // 0x8000A984: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
L_8000A988:
    // 0x8000A988: lh          $t9, 0x5A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X5A);
L_8000A98C:
    // 0x8000A98C: bne         $t9, $zero, L_8000A9B8
    if (ctx->r25 != 0) {
        // 0x8000A990: lui         $t6, 0x800E
        ctx->r14 = S32(0X800E << 16);
            goto L_8000A9B8;
    }
    // 0x8000A990: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8000A994: lh          $t6, -0x2D20($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X2D20);
    // 0x8000A998: beq         $t6, $zero, L_8000A9B8
    if (ctx->r14 == 0) {
        // 0x8000A99C: nop
    
            goto L_8000A9B8;
    }
    // 0x8000A99C: nop

    // 0x8000A9A0: jal         0x8000AB18
    // 0x8000A9A4: nop

    func_8000AB18(rdram, ctx);
        goto after_1;
    // 0x8000A9A4: nop

    after_1:
    // 0x8000A9A8: beq         $v0, $zero, L_8000A9B8
    if (ctx->r2 == 0) {
        // 0x8000A9AC: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8000A9B8;
    }
    // 0x8000A9AC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000A9B0: jal         0x80055500
    // 0x8000A9B4: addiu       $a0, $a0, -0x2E38
    ctx->r4 = ADD32(ctx->r4, -0X2E38);
    osContStartReadData_recomp(rdram, ctx);
        goto after_2;
    // 0x8000A9B4: addiu       $a0, $a0, -0x2E38
    ctx->r4 = ADD32(ctx->r4, -0X2E38);
    after_2:
L_8000A9B8:
    // 0x8000A9B8: jal         0x8000A420
    // 0x8000A9BC: nop

    func_8000A420(rdram, ctx);
        goto after_3;
    // 0x8000A9BC: nop

    after_3:
    // 0x8000A9C0: beq         $v0, $zero, L_8000A9D0
    if (ctx->r2 == 0) {
        // 0x8000A9C4: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8000A9D0;
    }
    // 0x8000A9C4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000A9C8: jal         0x80055500
    // 0x8000A9CC: addiu       $a0, $a0, -0x2E38
    ctx->r4 = ADD32(ctx->r4, -0X2E38);
    osContStartReadData_recomp(rdram, ctx);
        goto after_4;
    // 0x8000A9CC: addiu       $a0, $a0, -0x2E38
    ctx->r4 = ADD32(ctx->r4, -0X2E38);
    after_4:
L_8000A9D0:
    // 0x8000A9D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000A9D4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8000A9D8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000A9E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000A9E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000A9E4: sh          $zero, -0x2D46($at)
    MEM_H(-0X2D46, ctx->r1) = 0;
    // 0x8000A9E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000A9EC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8000A9F0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000A9F4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000A9F8: sh          $zero, -0x2D44($at)
    MEM_H(-0X2D44, ctx->r1) = 0;
    // 0x8000A9FC: addiu       $v0, $v0, -0x2D38
    ctx->r2 = ADD32(ctx->r2, -0X2D38);
    // 0x8000AA00: addiu       $a0, $a0, -0x2D3C
    ctx->r4 = ADD32(ctx->r4, -0X2D3C);
    // 0x8000AA04: addiu       $v1, $v1, -0x2D40
    ctx->r3 = ADD32(ctx->r3, -0X2D40);
L_8000AA08:
    // 0x8000AA08: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8000AA0C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8000AA10: sh          $zero, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = 0;
    // 0x8000AA14: bne         $a0, $v0, L_8000AA08
    if (ctx->r4 != ctx->r2) {
        // 0x8000AA18: sh          $zero, -0x2($a0)
        MEM_H(-0X2, ctx->r4) = 0;
            goto L_8000AA08;
    }
    // 0x8000AA18: sh          $zero, -0x2($a0)
    MEM_H(-0X2, ctx->r4) = 0;
    // 0x8000AA1C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000AA24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000AA24: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000AA28: jr          $ra
    // 0x8000AA2C: lh          $v0, -0x2D48($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2D48);
    TRACE_RETURN()
    return;
    // 0x8000AA2C: lh          $v0, -0x2D48($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2D48);
;}
RECOMP_FUNC void func_8000AA30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000AA30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000AA34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000AA38: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8000AA3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000AA40: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000AA44: sh          $t6, -0x2D18($at)
    MEM_H(-0X2D18, ctx->r1) = ctx->r14;
    // 0x8000AA48: jal         0x800541C0
    // 0x8000AA4C: addiu       $a0, $a0, -0x2E08
    ctx->r4 = ADD32(ctx->r4, -0X2E08);
    osMotorStart_recomp(rdram, ctx);
        goto after_0;
    // 0x8000AA4C: addiu       $a0, $a0, -0x2E08
    ctx->r4 = ADD32(ctx->r4, -0X2E08);
    after_0:
    // 0x8000AA50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000AA54: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x8000AA58: sra         $v0, $t7, 16
    ctx->r2 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8000AA5C: jr          $ra
    // 0x8000AA60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    TRACE_RETURN()
    return;
    // 0x8000AA60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8000AA64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000AA64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000AA68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000AA6C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000AA70: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000AA74: sh          $zero, -0x2D18($at)
    MEM_H(-0X2D18, ctx->r1) = 0;
    // 0x8000AA78: jal         0x80054020
    // 0x8000AA7C: addiu       $a0, $a0, -0x2E08
    ctx->r4 = ADD32(ctx->r4, -0X2E08);
    osMotorStop_recomp(rdram, ctx);
        goto after_0;
    // 0x8000AA7C: addiu       $a0, $a0, -0x2E08
    ctx->r4 = ADD32(ctx->r4, -0X2E08);
    after_0:
    // 0x8000AA80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000AA84: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x8000AA88: sra         $v0, $t6, 16
    ctx->r2 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8000AA8C: jr          $ra
    // 0x8000AA90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    TRACE_RETURN()
    return;
    // 0x8000AA90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8000AA94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000AA94: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8000AA98: addiu       $v1, $v1, -0x2D10
    ctx->r3 = ADD32(ctx->r3, -0X2D10);
    // 0x8000AA9C: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x8000AAA0: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x8000AAA4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000AAA8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000AAAC: sh          $t6, -0x2D12($at)
    MEM_H(-0X2D12, ctx->r1) = ctx->r14;
    // 0x8000AAB0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000AAB4: sh          $zero, -0x2D0A($at)
    MEM_H(-0X2D0A, ctx->r1) = 0;
    // 0x8000AAB8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000AABC: addiu       $v0, $v0, -0x2D16
    ctx->r2 = ADD32(ctx->r2, -0X2D16);
    // 0x8000AAC0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000AAC4: sh          $zero, -0x2D08($at)
    MEM_H(-0X2D08, ctx->r1) = 0;
    // 0x8000AAC8: addiu       $a0, $a0, -0x2D0C
    ctx->r4 = ADD32(ctx->r4, -0X2D0C);
    // 0x8000AACC: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x8000AAD0: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x8000AAD4: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x8000AAD8: lh          $t8, 0x0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X0);
    // 0x8000AADC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000AAE0: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x8000AAE4: sh          $t8, -0x2D0E($at)
    MEM_H(-0X2D0E, ctx->r1) = ctx->r24;
    // 0x8000AAE8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000AAEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000AAF0: sh          $zero, -0x2D1E($at)
    MEM_H(-0X2D1E, ctx->r1) = 0;
    // 0x8000AAF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000AAF8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000AAFC: jal         0x8000AA64
    // 0x8000AB00: sh          $zero, -0x2D1C($at)
    MEM_H(-0X2D1C, ctx->r1) = 0;
    func_8000AA64(rdram, ctx);
        goto after_0;
    // 0x8000AB00: sh          $zero, -0x2D1C($at)
    MEM_H(-0X2D1C, ctx->r1) = 0;
    after_0:
    // 0x8000AB04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000AB08: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000AB0C: sh          $zero, -0x2D06($at)
    MEM_H(-0X2D06, ctx->r1) = 0;
    // 0x8000AB10: jr          $ra
    // 0x8000AB14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    TRACE_RETURN()
    return;
    // 0x8000AB14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8000AB18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000AB18: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8000AB1C: lh          $t6, -0x2D1E($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X2D1E);
    // 0x8000AB20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000AB24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000AB28: beq         $t6, $zero, L_8000AB7C
    if (ctx->r14 == 0) {
        // 0x8000AB2C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8000AB7C;
    }
    // 0x8000AB2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000AB30: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000AB34: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000AB38: addiu       $a1, $a1, -0x2E08
    ctx->r5 = ADD32(ctx->r5, -0X2E08);
    // 0x8000AB3C: addiu       $a0, $a0, -0x2E38
    ctx->r4 = ADD32(ctx->r4, -0X2E38);
    // 0x8000AB40: jal         0x800544DC
    // 0x8000AB44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osPfsInitPak_recomp(rdram, ctx);
        goto after_0;
    // 0x8000AB44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8000AB48: jal         0x8000AA94
    // 0x8000AB4C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_8000AA94(rdram, ctx);
        goto after_1;
    // 0x8000AB4C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x8000AB50: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8000AB54: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8000AB58: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000AB5C: beq         $t7, $zero, L_8000AB70
    if (ctx->r15 == 0) {
        // 0x8000AB60: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_8000AB70;
    }
    // 0x8000AB60: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8000AB64: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000AB68: b           L_8000ACDC
    // 0x8000AB6C: sh          $zero, -0x2D1A($at)
    MEM_H(-0X2D1A, ctx->r1) = 0;
        goto L_8000ACDC;
    // 0x8000AB6C: sh          $zero, -0x2D1A($at)
    MEM_H(-0X2D1A, ctx->r1) = 0;
L_8000AB70:
    // 0x8000AB70: sh          $t8, -0x2D1A($at)
    MEM_H(-0X2D1A, ctx->r1) = ctx->r24;
    // 0x8000AB74: b           L_8000ACDC
    // 0x8000AB78: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000ACDC;
    // 0x8000AB78: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000AB7C:
    // 0x8000AB7C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8000AB80: lh          $t9, -0x2D1C($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X2D1C);
    // 0x8000AB84: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8000AB88: addiu       $v1, $v1, -0x2D14
    ctx->r3 = ADD32(ctx->r3, -0X2D14);
    // 0x8000AB8C: beq         $t9, $zero, L_8000ABA4
    if (ctx->r25 == 0) {
        // 0x8000AB90: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_8000ABA4;
    }
    // 0x8000AB90: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000AB94: jal         0x8000AA94
    // 0x8000AB98: nop

    func_8000AA94(rdram, ctx);
        goto after_2;
    // 0x8000AB98: nop

    after_2:
    // 0x8000AB9C: b           L_8000ACDC
    // 0x8000ABA0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000ACDC;
    // 0x8000ABA0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000ABA4:
    // 0x8000ABA4: lh          $v0, -0x2D16($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2D16);
    // 0x8000ABA8: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
    // 0x8000ABAC: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8000ABB0: addiu       $a2, $a2, -0x2D08
    ctx->r6 = ADD32(ctx->r6, -0X2D08);
    // 0x8000ABB4: beq         $t0, $v0, L_8000ABC0
    if (ctx->r8 == ctx->r2) {
        // 0x8000ABB8: lui         $a1, 0x800E
        ctx->r5 = S32(0X800E << 16);
            goto L_8000ABC0;
    }
    // 0x8000ABB8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000ABBC: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_8000ABC0:
    // 0x8000ABC0: lh          $t1, 0x0($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X0);
    // 0x8000ABC4: addiu       $a1, $a1, -0x2D0A
    ctx->r5 = ADD32(ctx->r5, -0X2D0A);
    // 0x8000ABC8: beq         $t1, $zero, L_8000ACA4
    if (ctx->r9 == 0) {
        // 0x8000ABCC: nop
    
            goto L_8000ACA4;
    }
    // 0x8000ABCC: nop

    // 0x8000ABD0: lh          $t2, 0x0($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X0);
    // 0x8000ABD4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8000ABD8: bne         $t2, $zero, L_8000ACC0
    if (ctx->r10 != 0) {
        // 0x8000ABDC: nop
    
            goto L_8000ACC0;
    }
    // 0x8000ABDC: nop

    // 0x8000ABE0: lh          $t3, -0x2D06($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X2D06);
    // 0x8000ABE4: beq         $t3, $zero, L_8000AC68
    if (ctx->r11 == 0) {
        // 0x8000ABE8: nop
    
            goto L_8000AC68;
    }
    // 0x8000ABE8: nop

    // 0x8000ABEC: jal         0x8000AA64
    // 0x8000ABF0: nop

    func_8000AA64(rdram, ctx);
        goto after_3;
    // 0x8000ABF0: nop

    after_3:
    // 0x8000ABF4: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8000ABF8: addiu       $a2, $a2, -0x2D08
    ctx->r6 = ADD32(ctx->r6, -0X2D08);
    // 0x8000ABFC: lh          $v1, 0x0($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X0);
    // 0x8000AC00: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000AC04: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000AC08: addiu       $a1, $a1, -0x2D0A
    ctx->r5 = ADD32(ctx->r5, -0X2D0A);
    // 0x8000AC0C: beq         $v1, $at, L_8000AC54
    if (ctx->r3 == ctx->r1) {
        // 0x8000AC10: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_8000AC54;
    }
    // 0x8000AC10: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8000AC14: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000AC18: addiu       $t4, $v1, -0x1
    ctx->r12 = ADD32(ctx->r3, -0X1);
    // 0x8000AC1C: addiu       $v0, $v0, -0x2D12
    ctx->r2 = ADD32(ctx->r2, -0X2D12);
    // 0x8000AC20: sh          $t4, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r12;
    // 0x8000AC24: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8000AC28: lh          $t6, -0x2D0E($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X2D0E);
    // 0x8000AC2C: lh          $t5, 0x0($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X0);
    // 0x8000AC30: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8000AC34: addiu       $a3, $a3, -0x2D10
    ctx->r7 = ADD32(ctx->r7, -0X2D10);
    // 0x8000AC38: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8000AC3C: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x8000AC40: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8000AC44: lh          $t9, -0x2D0C($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X2D0C);
    // 0x8000AC48: lh          $t8, 0x0($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X0);
    // 0x8000AC4C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8000AC50: sh          $t0, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r8;
L_8000AC54:
    // 0x8000AC54: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000AC58: addiu       $v0, $v0, -0x2D12
    ctx->r2 = ADD32(ctx->r2, -0X2D12);
    // 0x8000AC5C: lh          $t1, 0x0($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X0);
    // 0x8000AC60: b           L_8000AC8C
    // 0x8000AC64: sh          $t1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r9;
        goto L_8000AC8C;
    // 0x8000AC64: sh          $t1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r9;
L_8000AC68:
    // 0x8000AC68: jal         0x8000AA30
    // 0x8000AC6C: nop

    func_8000AA30(rdram, ctx);
        goto after_4;
    // 0x8000AC6C: nop

    after_4:
    // 0x8000AC70: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8000AC74: addiu       $a3, $a3, -0x2D10
    ctx->r7 = ADD32(ctx->r7, -0X2D10);
    // 0x8000AC78: lh          $t2, 0x0($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X0);
    // 0x8000AC7C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000AC80: addiu       $a1, $a1, -0x2D0A
    ctx->r5 = ADD32(ctx->r5, -0X2D0A);
    // 0x8000AC84: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8000AC88: sh          $t2, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r10;
L_8000AC8C:
    // 0x8000AC8C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8000AC90: lh          $t3, -0x2D06($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X2D06);
    // 0x8000AC94: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000AC98: xori        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 ^ 0X1;
    // 0x8000AC9C: b           L_8000ACC0
    // 0x8000ACA0: sh          $t4, -0x2D06($at)
    MEM_H(-0X2D06, ctx->r1) = ctx->r12;
        goto L_8000ACC0;
    // 0x8000ACA0: sh          $t4, -0x2D06($at)
    MEM_H(-0X2D06, ctx->r1) = ctx->r12;
L_8000ACA4:
    // 0x8000ACA4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8000ACA8: lh          $t5, -0x2D18($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X2D18);
    // 0x8000ACAC: beq         $t5, $zero, L_8000ACC0
    if (ctx->r13 == 0) {
        // 0x8000ACB0: nop
    
            goto L_8000ACC0;
    }
    // 0x8000ACB0: nop

    // 0x8000ACB4: jal         0x8000AA64
    // 0x8000ACB8: nop

    func_8000AA64(rdram, ctx);
        goto after_5;
    // 0x8000ACB8: nop

    after_5:
    // 0x8000ACBC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_8000ACC0:
    // 0x8000ACC0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000ACC4: addiu       $a1, $a1, -0x2D0A
    ctx->r5 = ADD32(ctx->r5, -0X2D0A);
    // 0x8000ACC8: lh          $v0, 0x0($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X0);
    // 0x8000ACCC: beq         $v0, $zero, L_8000ACD8
    if (ctx->r2 == 0) {
        // 0x8000ACD0: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8000ACD8;
    }
    // 0x8000ACD0: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8000ACD4: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
L_8000ACD8:
    // 0x8000ACD8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8000ACDC:
    // 0x8000ACDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000ACE0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000ACE4: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000ACEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000ACEC: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8000ACF0: lh          $t4, -0x2D20($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X2D20);
    // 0x8000ACF4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8000ACF8: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8000ACFC: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x8000AD00: sll         $t0, $a2, 16
    ctx->r8 = S32(ctx->r6 << 16);
    // 0x8000AD04: sll         $t2, $a3, 16
    ctx->r10 = S32(ctx->r7 << 16);
    // 0x8000AD08: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x8000AD0C: sra         $t1, $t0, 16
    ctx->r9 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8000AD10: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8000AD14: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8000AD18: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8000AD1C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8000AD20: beq         $t4, $zero, L_8000AD88
    if (ctx->r12 == 0) {
        // 0x8000AD24: sw          $a3, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r7;
            goto L_8000AD88;
    }
    // 0x8000AD24: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8000AD28: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x8000AD2C: lw          $t5, -0x6BE0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X6BE0);
    // 0x8000AD30: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000AD34: addiu       $v0, $v0, -0x2D16
    ctx->r2 = ADD32(ctx->r2, -0X2D16);
    // 0x8000AD38: andi        $t6, $t5, 0x4
    ctx->r14 = ctx->r13 & 0X4;
    // 0x8000AD3C: bne         $t6, $zero, L_8000AD88
    if (ctx->r14 != 0) {
        // 0x8000AD40: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8000AD88;
    }
    // 0x8000AD40: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000AD44: lh          $t7, 0x12($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X12);
    // 0x8000AD48: sh          $t1, -0x2D08($at)
    MEM_H(-0X2D08, ctx->r1) = ctx->r9;
    // 0x8000AD4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000AD50: sh          $t7, -0x2D0E($at)
    MEM_H(-0X2D0E, ctx->r1) = ctx->r15;
    // 0x8000AD54: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000AD58: sh          $t3, -0x2D0C($at)
    MEM_H(-0X2D0C, ctx->r1) = ctx->r11;
    // 0x8000AD5C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000AD60: sh          $t9, -0x2D12($at)
    MEM_H(-0X2D12, ctx->r1) = ctx->r25;
    // 0x8000AD64: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000AD68: sh          $a0, -0x2D10($at)
    MEM_H(-0X2D10, ctx->r1) = ctx->r4;
    // 0x8000AD6C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000AD70: sh          $zero, -0x2D0A($at)
    MEM_H(-0X2D0A, ctx->r1) = 0;
    // 0x8000AD74: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000AD78: sh          $zero, -0x2D06($at)
    MEM_H(-0X2D06, ctx->r1) = 0;
    // 0x8000AD7C: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x8000AD80: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8000AD84: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
L_8000AD88:
    // 0x8000AD88: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000AD90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000AD90: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8000AD94: lh          $t6, -0x2D20($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X2D20);
    // 0x8000AD98: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8000AD9C: beq         $t6, $zero, L_8000ADBC
    if (ctx->r14 == 0) {
        // 0x8000ADA0: nop
    
            goto L_8000ADBC;
    }
    // 0x8000ADA0: nop

    // 0x8000ADA4: lw          $t7, -0x6BE0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6BE0);
    // 0x8000ADA8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000ADAC: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x8000ADB0: bne         $t8, $zero, L_8000ADBC
    if (ctx->r24 != 0) {
        // 0x8000ADB4: nop
    
            goto L_8000ADBC;
    }
    // 0x8000ADB4: nop

    // 0x8000ADB8: sh          $zero, -0x2D08($at)
    MEM_H(-0X2D08, ctx->r1) = 0;
L_8000ADBC:
    // 0x8000ADBC: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000ADD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000ADD0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000ADD4: addiu       $v0, $v0, -0x1C60
    ctx->r2 = ADD32(ctx->r2, -0X1C60);
    // 0x8000ADD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000ADDC: lui         $t6, 0x803B
    ctx->r14 = S32(0X803B << 16);
    // 0x8000ADE0: lui         $t7, 0x803E
    ctx->r15 = S32(0X803E << 16);
    // 0x8000ADE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000ADE8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8000ADEC: addiu       $t6, $t6, 0x5000
    ctx->r14 = ADD32(ctx->r14, 0X5000);
    // 0x8000ADF0: addiu       $t7, $t7, -0x5800
    ctx->r15 = ADD32(ctx->r15, -0X5800);
    // 0x8000ADF4: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8000ADF8: sh          $v1, 0x3158($v0)
    MEM_H(0X3158, ctx->r2) = ctx->r3;
    // 0x8000ADFC: sw          $t6, 0x3178($v0)
    MEM_W(0X3178, ctx->r2) = ctx->r14;
    // 0x8000AE00: sh          $v1, 0x62D8($v0)
    MEM_H(0X62D8, ctx->r2) = ctx->r3;
    // 0x8000AE04: sw          $t7, 0x62F8($v0)
    MEM_W(0X62F8, ctx->r2) = ctx->r15;
    // 0x8000AE08: addiu       $a0, $a0, -0x7C00
    ctx->r4 = ADD32(ctx->r4, -0X7C00);
    // 0x8000AE0C: jal         0x8000C7C0
    // 0x8000AE10: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    func_8000C7C0(rdram, ctx);
        goto after_0;
    // 0x8000AE10: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    after_0:
    // 0x8000AE14: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x8000AE18: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000AE1C: sw          $t8, -0x2D00($at)
    MEM_W(-0X2D00, ctx->r1) = ctx->r24;
    // 0x8000AE20: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
    // 0x8000AE24: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000AE28: sw          $v0, -0x2CFC($at)
    MEM_W(-0X2CFC, ctx->r1) = ctx->r2;
    // 0x8000AE2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000AE30: sw          $v0, -0x2CF8($at)
    MEM_W(-0X2CF8, ctx->r1) = ctx->r2;
    // 0x8000AE34: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000AE38: addiu       $t9, $zero, 0x3E4
    ctx->r25 = ADD32(0, 0X3E4);
    // 0x8000AE3C: sw          $t9, -0x2CF4($at)
    MEM_W(-0X2CF4, ctx->r1) = ctx->r25;
    // 0x8000AE40: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000AE44: sh          $zero, -0x2CC4($at)
    MEM_H(-0X2CC4, ctx->r1) = 0;
    // 0x8000AE48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000AE4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000AE50: jal         0x8000BD4C
    // 0x8000AE54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BD4C(rdram, ctx);
        goto after_1;
    // 0x8000AE54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8000AE58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000AE5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000AE60: jal         0x8000BDEC
    // 0x8000AE64: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000BDEC(rdram, ctx);
        goto after_2;
    // 0x8000AE64: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8000AE68: jal         0x80055760
    // 0x8000AE6C: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_3;
    // 0x8000AE6C: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    after_3:
    // 0x8000AE70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000AE74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000AE78: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000AE80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000AE80: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000AE84: addiu       $v0, $v0, -0x2CC0
    ctx->r2 = ADD32(ctx->r2, -0X2CC0);
    // 0x8000AE88: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8000AE8C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000AE90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000AE94: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8000AE98: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000AE9C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000AEA0: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x8000AEA4: lw          $t8, 0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC);
    // 0x8000AEA8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8000AEAC: bnel        $t8, $at, L_8000AEE4
    if (ctx->r24 != ctx->r1) {
        // 0x8000AEB0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8000AEE4;
    }
    goto skip_0;
    // 0x8000AEB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8000AEB4: lw          $t9, 0xD0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XD0);
    // 0x8000AEB8: lw          $s1, 0x0($t9)
    ctx->r17 = MEM_W(ctx->r25, 0X0);
    // 0x8000AEBC: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8000AEC0: beql        $s0, $zero, L_8000AEE4
    if (ctx->r16 == 0) {
        // 0x8000AEC4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8000AEE4;
    }
    goto skip_1;
    // 0x8000AEC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
L_8000AEC8:
    // 0x8000AEC8: jal         0x8000AE80
    // 0x8000AECC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000AE80(rdram, ctx);
        goto after_0;
    // 0x8000AECC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x8000AED0: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x8000AED4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x8000AED8: bne         $s0, $zero, L_8000AEC8
    if (ctx->r16 != 0) {
        // 0x8000AEDC: nop
    
            goto L_8000AEC8;
    }
    // 0x8000AEDC: nop

    // 0x8000AEE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000AEE4:
    // 0x8000AEE4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000AEE8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000AEEC: jr          $ra
    // 0x8000AEF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    TRACE_RETURN()
    return;
    // 0x8000AEF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8000AEF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000AEF4: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x8000AEF8: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x8000AEFC: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8000AF00: addiu       $s0, $s0, -0x1C68
    ctx->r16 = ADD32(ctx->r16, -0X1C68);
    // 0x8000AF04: addiu       $t6, $a0, 0x158
    ctx->r14 = ADD32(ctx->r4, 0X158);
    // 0x8000AF08: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8000AF0C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8000AF10: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8000AF14: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8000AF18: lw          $t8, -0x2CFC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2CFC);
    // 0x8000AF1C: lw          $t7, -0x2D00($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2D00);
    // 0x8000AF20: lwc1        $f4, -0x6C24($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6C24);
    // 0x8000AF24: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8000AF28: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8000AF2C: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8000AF30: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8000AF34: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8000AF38: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8000AF3C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000AF40: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000AF44: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8000AF48: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8000AF4C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8000AF50: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000AF54: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000AF58: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8000AF5C: lui         $a3, 0x3FAA
    ctx->r7 = S32(0X3FAA << 16);
    // 0x8000AF60: ori         $a3, $a3, 0xAAAB
    ctx->r7 = ctx->r7 | 0XAAAB;
    // 0x8000AF64: addiu       $a0, $a0, 0x6A00
    ctx->r4 = ADD32(ctx->r4, 0X6A00);
    // 0x8000AF68: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8000AF6C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8000AF70: addiu       $a1, $sp, 0xB6
    ctx->r5 = ADD32(ctx->r29, 0XB6);
    // 0x8000AF74: jal         0x80055920
    // 0x8000AF78: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    func_80055920(rdram, ctx);
        goto after_0;
    // 0x8000AF78: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8000AF7C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8000AF80: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8000AF84: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8000AF88: lw          $t6, -0x2CFC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2CFC);
    // 0x8000AF8C: lw          $t9, -0x2D00($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2D00);
    // 0x8000AF90: lwc1        $f8, -0x6C24($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6C24);
    // 0x8000AF94: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8000AF98: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000AF9C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8000AFA0: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8000AFA4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8000AFA8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000AFAC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000AFB0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000AFB4: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8000AFB8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000AFBC: lui         $a3, 0x3FAA
    ctx->r7 = S32(0X3FAA << 16);
    // 0x8000AFC0: ori         $a3, $a3, 0xAAAB
    ctx->r7 = ctx->r7 | 0XAAAB;
    // 0x8000AFC4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000AFC8: addiu       $a0, $a0, 0x6A80
    ctx->r4 = ADD32(ctx->r4, 0X6A80);
    // 0x8000AFCC: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8000AFD0: addiu       $a1, $sp, 0xB6
    ctx->r5 = ADD32(ctx->r29, 0XB6);
    // 0x8000AFD4: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x8000AFD8: jal         0x80055920
    // 0x8000AFDC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80055920(rdram, ctx);
        goto after_1;
    // 0x8000AFDC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8000AFE0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8000AFE4: addiu       $v1, $v1, -0x6C40
    ctx->r3 = ADD32(ctx->r3, -0X6C40);
    // 0x8000AFE8: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8000AFEC: addiu       $t0, $t0, -0x6C30
    ctx->r8 = ADD32(ctx->r8, -0X6C30);
    // 0x8000AFF0: lwc1        $f0, 0x0($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8000AFF4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8000AFF8: lwc1        $f6, 0x4($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8000AFFC: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8000B000: lwc1        $f18, 0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8000B004: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8000B008: addiu       $v0, $v0, -0x6C50
    ctx->r2 = ADD32(ctx->r2, -0X6C50);
    // 0x8000B00C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000B010: addiu       $a0, $a0, 0x6A40
    ctx->r4 = ADD32(ctx->r4, 0X6A40);
    // 0x8000B014: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8000B018: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x8000B01C: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x8000B020: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8000B024: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8000B028: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8000B02C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8000B030: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x8000B034: jal         0x80055BB0
    // 0x8000B038: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    func_80055BB0(rdram, ctx);
        goto after_2;
    // 0x8000B038: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x8000B03C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8000B040: lw          $t7, -0x2D00($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2D00);
    // 0x8000B044: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8000B048: lw          $t8, -0x2CFC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2CFC);
    // 0x8000B04C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8000B050: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000B054: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8000B058: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000B05C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8000B060: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000B064: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8000B068: lui         $a2, 0x3FAA
    ctx->r6 = S32(0X3FAA << 16);
    // 0x8000B06C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000B070: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8000B074: ori         $a2, $a2, 0xAAAB
    ctx->r6 = ctx->r6 | 0XAAAB;
    // 0x8000B078: lw          $a1, -0x6C24($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6C24);
    // 0x8000B07C: addiu       $a0, $a0, 0x6980
    ctx->r4 = ADD32(ctx->r4, 0X6980);
    // 0x8000B080: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x8000B084: jal         0x80004988
    // 0x8000B088: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_80004988(rdram, ctx);
        goto after_3;
    // 0x8000B088: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x8000B08C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8000B090: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000B094: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000B098: addiu       $v1, $s1, 0x58
    ctx->r3 = ADD32(ctx->r17, 0X58);
    // 0x8000B09C: addiu       $a1, $v1, 0xC0
    ctx->r5 = ADD32(ctx->r3, 0XC0);
    // 0x8000B0A0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000B0A4: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8000B0A8: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x8000B0AC: sh          $v0, 0xB6($sp)
    MEM_H(0XB6, ctx->r29) = ctx->r2;
    // 0x8000B0B0: addiu       $a3, $a3, -0x6C40
    ctx->r7 = ADD32(ctx->r7, -0X6C40);
    // 0x8000B0B4: addiu       $a2, $a2, -0x6C50
    ctx->r6 = ADD32(ctx->r6, -0X6C50);
    // 0x8000B0B8: addiu       $a0, $a0, 0x6940
    ctx->r4 = ADD32(ctx->r4, 0X6940);
    // 0x8000B0BC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8000B0C0: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x8000B0C4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8000B0C8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8000B0CC: jal         0x80004540
    // 0x8000B0D0: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_80004540(rdram, ctx);
        goto after_4;
    // 0x8000B0D0: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x8000B0D4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8000B0D8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8000B0DC: lw          $t6, -0x2CFC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2CFC);
    // 0x8000B0E0: lw          $t9, -0x2D00($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2D00);
    // 0x8000B0E4: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8000B0E8: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8000B0EC: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8000B0F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8000B0F4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8000B0F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000B0FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000B100: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    // 0x8000B104: lui         $a1, 0xC320
    ctx->r5 = S32(0XC320 << 16);
    // 0x8000B108: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000B10C: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x8000B110: lui         $a2, 0x4320
    ctx->r6 = S32(0X4320 << 16);
    // 0x8000B114: lui         $a3, 0xC2F0
    ctx->r7 = S32(0XC2F0 << 16);
    // 0x8000B118: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8000B11C: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8000B120: jal         0x80001660
    // 0x8000B124: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_80001660(rdram, ctx);
        goto after_5;
    // 0x8000B124: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x8000B128: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8000B12C: addiu       $a1, $sp, 0xB8
    ctx->r5 = ADD32(ctx->r29, 0XB8);
    // 0x8000B130: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    // 0x8000B134: jal         0x80004EF0
    // 0x8000B138: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    func_80004EF0(rdram, ctx);
        goto after_6;
    // 0x8000B138: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    after_6:
    // 0x8000B13C: jal         0x800022F0
    // 0x8000B140: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    func_800022F0(rdram, ctx);
        goto after_7;
    // 0x8000B140: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    after_7:
    // 0x8000B144: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8000B148: lw          $a0, -0x6CA0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6CA0);
    // 0x8000B14C: jal         0x8000FA04
    // 0x8000B150: addiu       $a1, $sp, 0xB8
    ctx->r5 = ADD32(ctx->r29, 0XB8);
    func_8000FA04(rdram, ctx);
        goto after_8;
    // 0x8000B150: addiu       $a1, $sp, 0xB8
    ctx->r5 = ADD32(ctx->r29, 0XB8);
    after_8:
    // 0x8000B154: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8000B158: lw          $a0, -0x6C9C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6C9C);
    // 0x8000B15C: jal         0x8000FA04
    // 0x8000B160: addiu       $a1, $sp, 0xB8
    ctx->r5 = ADD32(ctx->r29, 0XB8);
    func_8000FA04(rdram, ctx);
        goto after_9;
    // 0x8000B160: addiu       $a1, $sp, 0xB8
    ctx->r5 = ADD32(ctx->r29, 0XB8);
    after_9:
    // 0x8000B164: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8000B168: lw          $a0, -0x6C98($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6C98);
    // 0x8000B16C: jal         0x8000FA04
    // 0x8000B170: addiu       $a1, $sp, 0xB8
    ctx->r5 = ADD32(ctx->r29, 0XB8);
    func_8000FA04(rdram, ctx);
        goto after_10;
    // 0x8000B170: addiu       $a1, $sp, 0xB8
    ctx->r5 = ADD32(ctx->r29, 0XB8);
    after_10:
    // 0x8000B174: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8000B178: lw          $a0, -0x6C94($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6C94);
    // 0x8000B17C: jal         0x8000FA04
    // 0x8000B180: addiu       $a1, $sp, 0xB8
    ctx->r5 = ADD32(ctx->r29, 0XB8);
    func_8000FA04(rdram, ctx);
        goto after_11;
    // 0x8000B180: addiu       $a1, $sp, 0xB8
    ctx->r5 = ADD32(ctx->r29, 0XB8);
    after_11:
    // 0x8000B184: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8000B188: lw          $a0, -0x6C90($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6C90);
    // 0x8000B18C: jal         0x8000FA04
    // 0x8000B190: addiu       $a1, $sp, 0xB8
    ctx->r5 = ADD32(ctx->r29, 0XB8);
    func_8000FA04(rdram, ctx);
        goto after_12;
    // 0x8000B190: addiu       $a1, $sp, 0xB8
    ctx->r5 = ADD32(ctx->r29, 0XB8);
    after_12:
    // 0x8000B194: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8000B198: lw          $a0, -0x6C8C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6C8C);
    // 0x8000B19C: jal         0x8000FA04
    // 0x8000B1A0: addiu       $a1, $sp, 0xB8
    ctx->r5 = ADD32(ctx->r29, 0XB8);
    func_8000FA04(rdram, ctx);
        goto after_13;
    // 0x8000B1A0: addiu       $a1, $sp, 0xB8
    ctx->r5 = ADD32(ctx->r29, 0XB8);
    after_13:
    // 0x8000B1A4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8000B1A8: lw          $a0, -0x6C88($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6C88);
    // 0x8000B1AC: jal         0x8000FA04
    // 0x8000B1B0: addiu       $a1, $sp, 0xB8
    ctx->r5 = ADD32(ctx->r29, 0XB8);
    func_8000FA04(rdram, ctx);
        goto after_14;
    // 0x8000B1B0: addiu       $a1, $sp, 0xB8
    ctx->r5 = ADD32(ctx->r29, 0XB8);
    after_14:
    // 0x8000B1B4: jal         0x8004B810
    // 0x8000B1B8: nop

    func_8004B810(rdram, ctx);
        goto after_15;
    // 0x8000B1B8: nop

    after_15:
    // 0x8000B1BC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000B1C0: lui         $t8, 0xBC00
    ctx->r24 = S32(0XBC00 << 16);
    // 0x8000B1C4: ori         $t8, $t8, 0x6
    ctx->r24 = ctx->r24 | 0X6;
    // 0x8000B1C8: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8000B1CC: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8000B1D0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000B1D4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000B1D8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000B1DC: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x8000B1E0: lui         $a1, 0x600
    ctx->r5 = S32(0X600 << 16);
    // 0x8000B1E4: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8000B1E8: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8000B1EC: addiu       $t6, $t6, -0x6A78
    ctx->r14 = ADD32(ctx->r14, -0X6A78);
    // 0x8000B1F0: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x8000B1F4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8000B1F8: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x8000B1FC: lw          $t7, -0x6BB8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6BB8);
    // 0x8000B200: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8000B204: beql        $t7, $zero, L_8000B234
    if (ctx->r15 == 0) {
        // 0x8000B208: lw          $v1, 0x0($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X0);
            goto L_8000B234;
    }
    goto skip_0;
    // 0x8000B208: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x8000B20C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000B210: lui         $t9, 0x8007
    ctx->r25 = S32(0X8007 << 16);
    // 0x8000B214: addiu       $t9, $t9, -0x6B80
    ctx->r25 = ADD32(ctx->r25, -0X6B80);
    // 0x8000B218: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8000B21C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8000B220: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000B224: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8000B228: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x8000B22C: sw          $zero, -0x6BB8($at)
    MEM_W(-0X6BB8, ctx->r1) = 0;
    // 0x8000B230: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_8000B234:
    // 0x8000B234: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x8000B238: addiu       $t7, $t7, -0x6A98
    ctx->r15 = ADD32(ctx->r15, -0X6A98);
    // 0x8000B23C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8000B240: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8000B244: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x8000B248: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8000B24C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000B250: lui         $t9, 0xFE00
    ctx->r25 = S32(0XFE00 << 16);
    // 0x8000B254: addiu       $a0, $a0, -0x3000
    ctx->r4 = ADD32(ctx->r4, -0X3000);
    // 0x8000B258: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8000B25C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8000B260: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000B264: jal         0x80053750
    // 0x8000B268: sw          $v1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r3;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_16;
    // 0x8000B268: sw          $v1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r3;
    after_16:
    // 0x8000B26C: lw          $a3, 0x9C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X9C);
    // 0x8000B270: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8000B274: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x8000B278: sw          $v0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r2;
    // 0x8000B27C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000B280: ori         $t9, $t9, 0x1402
    ctx->r25 = ctx->r25 | 0X1402;
    // 0x8000B284: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8000B288: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8000B28C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8000B290: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8000B294: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000B298: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000B29C: lui         $t6, 0x30
    ctx->r14 = S32(0X30 << 16);
    // 0x8000B2A0: addiu       $a0, $a0, -0x3000
    ctx->r4 = ADD32(ctx->r4, -0X3000);
    // 0x8000B2A4: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8000B2A8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8000B2AC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000B2B0: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8000B2B4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000B2B8: lui         $t8, 0xFF10
    ctx->r24 = S32(0XFF10 << 16);
    // 0x8000B2BC: ori         $t8, $t8, 0x13F
    ctx->r24 = ctx->r24 | 0X13F;
    // 0x8000B2C0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8000B2C4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8000B2C8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000B2CC: jal         0x80053750
    // 0x8000B2D0: sw          $v1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r3;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_17;
    // 0x8000B2D0: sw          $v1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r3;
    after_17:
    // 0x8000B2D4: lw          $t1, 0x90($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X90);
    // 0x8000B2D8: lui         $t7, 0xFFFC
    ctx->r15 = S32(0XFFFC << 16);
    // 0x8000B2DC: ori         $t7, $t7, 0xFFFC
    ctx->r15 = ctx->r15 | 0XFFFC;
    // 0x8000B2E0: sw          $v0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r2;
    // 0x8000B2E4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000B2E8: lui         $t6, 0xF700
    ctx->r14 = S32(0XF700 << 16);
    // 0x8000B2EC: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8000B2F0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8000B2F4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8000B2F8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8000B2FC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000B300: lui         $t9, 0xF64F
    ctx->r25 = S32(0XF64F << 16);
    // 0x8000B304: ori         $t9, $t9, 0xC3BC
    ctx->r25 = ctx->r25 | 0XC3BC;
    // 0x8000B308: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8000B30C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8000B310: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000B314: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000B318: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000B31C: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8000B320: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x8000B324: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8000B328: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8000B32C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8000B330: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000B334: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000B338: lui         $t6, 0x30
    ctx->r14 = S32(0X30 << 16);
    // 0x8000B33C: ori         $t9, $t9, 0x1402
    ctx->r25 = ctx->r25 | 0X1402;
    // 0x8000B340: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8000B344: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8000B348: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000B34C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8000B350: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000B354: lui         $t8, 0xFF10
    ctx->r24 = S32(0XFF10 << 16);
    // 0x8000B358: ori         $t8, $t8, 0x13F
    ctx->r24 = ctx->r24 | 0X13F;
    // 0x8000B35C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8000B360: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8000B364: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000B368: lw          $a0, 0x3178($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3178);
    // 0x8000B36C: jal         0x80053750
    // 0x8000B370: sw          $v1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r3;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_18;
    // 0x8000B370: sw          $v1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r3;
    after_18:
    // 0x8000B374: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x8000B378: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8000B37C: lui         $t6, 0xF700
    ctx->r14 = S32(0XF700 << 16);
    // 0x8000B380: sw          $v0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r2;
    // 0x8000B384: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000B388: addiu       $t4, $t4, -0x2CF0
    ctx->r12 = ADD32(ctx->r12, -0X2CF0);
    // 0x8000B38C: lui         $ra, 0xE700
    ctx->r31 = S32(0XE700 << 16);
    // 0x8000B390: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8000B394: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8000B398: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8000B39C: lw          $t7, 0x8($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X8);
    // 0x8000B3A0: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8000B3A4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000B3A8: srl         $t8, $t7, 2
    ctx->r24 = S32(U32(ctx->r15) >> 2);
    // 0x8000B3AC: andi        $t9, $t8, 0x3E
    ctx->r25 = ctx->r24 & 0X3E;
    // 0x8000B3B0: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x8000B3B4: andi        $t8, $t7, 0xF800
    ctx->r24 = ctx->r15 & 0XF800;
    // 0x8000B3B8: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x8000B3BC: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x8000B3C0: addiu       $a1, $a1, 0x6980
    ctx->r5 = ADD32(ctx->r5, 0X6980);
    // 0x8000B3C4: sll         $t9, $t7, 3
    ctx->r25 = S32(ctx->r15 << 3);
    // 0x8000B3C8: andi        $t8, $t9, 0x7C0
    ctx->r24 = ctx->r25 & 0X7C0;
    // 0x8000B3CC: or          $a3, $t6, $t8
    ctx->r7 = ctx->r14 | ctx->r24;
    // 0x8000B3D0: ori         $t7, $a3, 0x1
    ctx->r15 = ctx->r7 | 0X1;
    // 0x8000B3D4: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x8000B3D8: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x8000B3DC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8000B3E0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000B3E4: lui         $t7, 0xF64F
    ctx->r15 = S32(0XF64F << 16);
    // 0x8000B3E8: ori         $t7, $t7, 0xC3BC
    ctx->r15 = ctx->r15 | 0XC3BC;
    // 0x8000B3EC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8000B3F0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8000B3F4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000B3F8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8000B3FC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000B400: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x8000B404: ori         $t8, $t8, 0x1402
    ctx->r24 = ctx->r24 | 0X1402;
    // 0x8000B408: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8000B40C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8000B410: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000B414: sw          $ra, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r31;
    // 0x8000B418: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000B41C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8000B420: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8000B424: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000B428: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000B42C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000B430: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8000B434: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8000B438: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000B43C: sw          $ra, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r31;
    // 0x8000B440: jal         0x80004EF0
    // 0x8000B444: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_80004EF0(rdram, ctx);
        goto after_19;
    // 0x8000B444: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_19:
    // 0x8000B448: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8000B44C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000B450: addiu       $a1, $a1, 0x6940
    ctx->r5 = ADD32(ctx->r5, 0X6940);
    // 0x8000B454: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // 0x8000B458: jal         0x80004EF0
    // 0x8000B45C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_80004EF0(rdram, ctx);
        goto after_20;
    // 0x8000B45C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_20:
    // 0x8000B460: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000B464: lui         $t6, 0x384
    ctx->r14 = S32(0X384 << 16);
    // 0x8000B468: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8000B46C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8000B470: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8000B474: ori         $t6, $t6, 0x10
    ctx->r14 = ctx->r14 | 0X10;
    // 0x8000B478: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8000B47C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8000B480: lui         $t9, 0x382
    ctx->r25 = S32(0X382 << 16);
    // 0x8000B484: ori         $t9, $t9, 0x10
    ctx->r25 = ctx->r25 | 0X10;
    // 0x8000B488: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8000B48C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000B490: addiu       $t6, $t2, 0xD0
    ctx->r14 = ADD32(ctx->r10, 0XD0);
    // 0x8000B494: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000B498: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8000B49C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8000B4A0: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8000B4A4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000B4A8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000B4AC: lui         $t7, 0xBC00
    ctx->r15 = S32(0XBC00 << 16);
    // 0x8000B4B0: ori         $t7, $t7, 0xE
    ctx->r15 = ctx->r15 | 0XE;
    // 0x8000B4B4: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8000B4B8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8000B4BC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8000B4C0: lhu         $t9, 0xB6($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0XB6);
    // 0x8000B4C4: lui         $t8, 0x103
    ctx->r24 = S32(0X103 << 16);
    // 0x8000B4C8: ori         $t8, $t8, 0x40
    ctx->r24 = ctx->r24 | 0X40;
    // 0x8000B4CC: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8000B4D0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000B4D4: lui         $t9, 0x101
    ctx->r25 = S32(0X101 << 16);
    // 0x8000B4D8: ori         $t9, $t9, 0x40
    ctx->r25 = ctx->r25 | 0X40;
    // 0x8000B4DC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8000B4E0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8000B4E4: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x8000B4E8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000B4EC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000B4F0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8000B4F4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8000B4F8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000B4FC: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8000B500: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8000B504: jal         0x8000B764
    // 0x8000B508: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_8000B764(rdram, ctx);
        goto after_21;
    // 0x8000B508: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_21:
    // 0x8000B50C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000B510: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8000B514: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8000B518: sw          $t8, -0x4A68($at)
    MEM_W(-0X4A68, ctx->r1) = ctx->r24;
    // 0x8000B51C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8000B520: lw          $a1, -0x6C88($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6C88);
    // 0x8000B524: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8000B528: jal         0x8000FB9C
    // 0x8000B52C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000FB9C(rdram, ctx);
        goto after_22;
    // 0x8000B52C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_22:
    // 0x8000B530: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000B534: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000B538: jal         0x8000B764
    // 0x8000B53C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8000B764(rdram, ctx);
        goto after_23;
    // 0x8000B53C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_23:
    // 0x8000B540: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000B544: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8000B548: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8000B54C: sw          $t7, -0x4A68($at)
    MEM_W(-0X4A68, ctx->r1) = ctx->r15;
    // 0x8000B550: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8000B554: lw          $a1, -0x6CA0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6CA0);
    // 0x8000B558: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8000B55C: jal         0x8000FB9C
    // 0x8000B560: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000FB9C(rdram, ctx);
        goto after_24;
    // 0x8000B560: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_24:
    // 0x8000B564: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000B568: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000B56C: jal         0x8000B764
    // 0x8000B570: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8000B764(rdram, ctx);
        goto after_25;
    // 0x8000B570: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_25:
    // 0x8000B574: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000B578: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8000B57C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8000B580: sw          $t9, -0x4A68($at)
    MEM_W(-0X4A68, ctx->r1) = ctx->r25;
    // 0x8000B584: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8000B588: lw          $a1, -0x6C98($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6C98);
    // 0x8000B58C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8000B590: jal         0x8000FB9C
    // 0x8000B594: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8000FB9C(rdram, ctx);
        goto after_26;
    // 0x8000B594: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_26:
    // 0x8000B598: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000B59C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000B5A0: jal         0x8000B764
    // 0x8000B5A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8000B764(rdram, ctx);
        goto after_27;
    // 0x8000B5A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_27:
    // 0x8000B5A8: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000B5AC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8000B5B0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8000B5B4: sw          $t6, -0x4A68($at)
    MEM_W(-0X4A68, ctx->r1) = ctx->r14;
    // 0x8000B5B8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8000B5BC: lw          $a1, -0x6C9C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6C9C);
    // 0x8000B5C0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8000B5C4: jal         0x8000FB9C
    // 0x8000B5C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8000FB9C(rdram, ctx);
        goto after_28;
    // 0x8000B5C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_28:
    // 0x8000B5CC: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000B5D0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8000B5D4: lui         $t7, 0x103
    ctx->r15 = S32(0X103 << 16);
    // 0x8000B5D8: ori         $t7, $t7, 0x40
    ctx->r15 = ctx->r15 | 0X40;
    // 0x8000B5DC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8000B5E0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8000B5E4: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8000B5E8: jal         0x8004B900
    // 0x8000B5EC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    func_8004B900(rdram, ctx);
        goto after_29;
    // 0x8000B5EC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    after_29:
    // 0x8000B5F0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8000B5F4: lw          $a1, -0x6C94($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6C94);
    // 0x8000B5F8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8000B5FC: jal         0x8000FB9C
    // 0x8000B600: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8000FB9C(rdram, ctx);
        goto after_30;
    // 0x8000B600: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_30:
    // 0x8000B604: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000B608: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8000B60C: lw          $a1, -0x6C90($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6C90);
    // 0x8000B610: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000B614: jal         0x8000FB9C
    // 0x8000B618: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8000FB9C(rdram, ctx);
        goto after_31;
    // 0x8000B618: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_31:
    // 0x8000B61C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000B620: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8000B624: lw          $a1, -0x6C8C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6C8C);
    // 0x8000B628: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000B62C: jal         0x8000FB9C
    // 0x8000B630: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8000FB9C(rdram, ctx);
        goto after_32;
    // 0x8000B630: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_32:
    // 0x8000B634: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000B638: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8000B63C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8000B640: lui         $t8, 0xE900
    ctx->r24 = S32(0XE900 << 16);
    // 0x8000B644: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8000B648: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8000B64C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000B650: lui         $t9, 0xB800
    ctx->r25 = S32(0XB800 << 16);
    // 0x8000B654: lui         $t1, 0x8006
    ctx->r9 = S32(0X8006 << 16);
    // 0x8000B658: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8000B65C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8000B660: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000B664: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000B668: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8000B66C: addiu       $t1, $t1, 0x2B80
    ctx->r9 = ADD32(ctx->r9, 0X2B80);
    // 0x8000B670: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8000B674: addiu       $t8, $t6, 0x100
    ctx->r24 = ADD32(ctx->r14, 0X100);
    // 0x8000B678: sw          $t8, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->r24;
    // 0x8000B67C: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8000B680: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8000B684: addiu       $t2, $t2, -0x7C00
    ctx->r10 = ADD32(ctx->r10, -0X7C00);
    // 0x8000B688: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8000B68C: subu        $t6, $t7, $t9
    ctx->r14 = SUB32(ctx->r15, ctx->r25);
    // 0x8000B690: addiu       $t8, $t6, -0x100
    ctx->r24 = ADD32(ctx->r14, -0X100);
    // 0x8000B694: sra         $t7, $t8, 3
    ctx->r15 = S32(SIGNED(ctx->r24) >> 3);
    // 0x8000B698: lui         $t8, 0x8006
    ctx->r24 = S32(0X8006 << 16);
    // 0x8000B69C: sll         $t9, $t7, 3
    ctx->r25 = S32(ctx->r15 << 3);
    // 0x8000B6A0: addiu       $t8, $t8, 0x2C50
    ctx->r24 = ADD32(ctx->r24, 0X2C50);
    // 0x8000B6A4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8000B6A8: subu        $t7, $t8, $t1
    ctx->r15 = SUB32(ctx->r24, ctx->r9);
    // 0x8000B6AC: sw          $t9, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->r25;
    // 0x8000B6B0: sw          $t6, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r14;
    // 0x8000B6B4: sw          $t7, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r15;
    // 0x8000B6B8: lui         $t9, 0x8006
    ctx->r25 = S32(0X8006 << 16);
    // 0x8000B6BC: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8000B6C0: addiu       $t7, $zero, 0x800
    ctx->r15 = ADD32(0, 0X800);
    // 0x8000B6C4: addiu       $t9, $t9, 0x4F90
    ctx->r25 = ADD32(ctx->r25, 0X4F90);
    // 0x8000B6C8: addiu       $t6, $t6, -0x5510
    ctx->r14 = ADD32(ctx->r14, -0X5510);
    // 0x8000B6CC: addu        $t8, $t2, $at
    ctx->r24 = ADD32(ctx->r10, ctx->r1);
    // 0x8000B6D0: sw          $t7, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r15;
    // 0x8000B6D4: sw          $t9, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r25;
    // 0x8000B6D8: sw          $t6, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r14;
    // 0x8000B6DC: sw          $t8, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->r24;
    // 0x8000B6E0: addiu       $t7, $zero, 0x900
    ctx->r15 = ADD32(0, 0X900);
    // 0x8000B6E4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8000B6E8: addiu       $t6, $zero, 0x400
    ctx->r14 = ADD32(0, 0X400);
    // 0x8000B6EC: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8000B6F0: sw          $t7, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->r15;
    // 0x8000B6F4: lw          $t7, 0x3178($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X3178);
    // 0x8000B6F8: addiu       $t9, $t9, -0x7C00
    ctx->r25 = ADD32(ctx->r25, -0X7C00);
    // 0x8000B6FC: sw          $t6, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r14;
    // 0x8000B700: addiu       $t8, $t8, -0x7800
    ctx->r24 = ADD32(ctx->r24, -0X7800);
    // 0x8000B704: sw          $t9, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r25;
    // 0x8000B708: sw          $t8, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->r24;
    // 0x8000B70C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8000B710: addiu       $t9, $zero, 0x63
    ctx->r25 = ADD32(0, 0X63);
    // 0x8000B714: addiu       $t6, $t6, -0x1CA0
    ctx->r14 = ADD32(ctx->r14, -0X1CA0);
    // 0x8000B718: addiu       $t8, $s1, 0x3158
    ctx->r24 = ADD32(ctx->r17, 0X3158);
    // 0x8000B71C: sw          $t1, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r9;
    // 0x8000B720: sw          $zero, 0x14($s1)
    MEM_W(0X14, ctx->r17) = 0;
    // 0x8000B724: sw          $t2, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->r10;
    // 0x8000B728: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x8000B72C: sw          $t9, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r25;
    // 0x8000B730: sw          $t6, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->r14;
    // 0x8000B734: sw          $t8, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->r24;
    // 0x8000B738: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000B73C: sw          $t7, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r15;
    // 0x8000B740: lw          $a0, 0x4928($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4928);
    // 0x8000B744: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8000B748: jal         0x800534A0
    // 0x8000B74C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_33;
    // 0x8000B74C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_33:
    // 0x8000B750: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8000B754: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8000B758: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8000B75C: jr          $ra
    // 0x8000B760: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    TRACE_RETURN()
    return;
    // 0x8000B760: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}
RECOMP_FUNC void func_8000B764(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000B764: beq         $a1, $zero, L_8000B788
    if (ctx->r5 == 0) {
        // 0x8000B768: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8000B788;
    }
    // 0x8000B768: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8000B76C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000B770: beq         $a1, $at, L_8000BBA4
    if (ctx->r5 == ctx->r1) {
        // 0x8000B774: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8000BBA4;
    }
    // 0x8000B774: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000B778: beq         $a1, $at, L_8000BC6C
    if (ctx->r5 == ctx->r1) {
        // 0x8000B77C: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8000BC6C;
    }
    // 0x8000B77C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8000B780: jr          $ra
    // 0x8000B784: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    TRACE_RETURN()
    return;
    // 0x8000B784: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8000B788:
    // 0x8000B788: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000B78C: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8000B790: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8000B794: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8000B798: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8000B79C: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x8000B7A0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8000B7A4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8000B7A8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8000B7AC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8000B7B0: lh          $t9, -0x2CC4($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X2CC4);
    // 0x8000B7B4: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000B7B8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8000B7BC: beq         $t9, $zero, L_8000B820
    if (ctx->r25 == 0) {
        // 0x8000B7C0: lui         $t6, 0xBA00
        ctx->r14 = S32(0XBA00 << 16);
            goto L_8000B820;
    }
    // 0x8000B7C0: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x8000B7C4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8000B7C8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000B7CC: lui         $t0, 0xBA00
    ctx->r8 = S32(0XBA00 << 16);
    // 0x8000B7D0: ori         $t0, $t0, 0x1402
    ctx->r8 = ctx->r8 | 0X1402;
    // 0x8000B7D4: lui         $t1, 0x10
    ctx->r9 = S32(0X10 << 16);
    // 0x8000B7D8: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8000B7DC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8000B7E0: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8000B7E4: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000B7E8: lui         $t3, 0x3
    ctx->r11 = S32(0X3 << 16);
    // 0x8000B7EC: ori         $t3, $t3, 0x2205
    ctx->r11 = ctx->r11 | 0X2205;
    // 0x8000B7F0: lui         $t2, 0xB700
    ctx->r10 = S32(0XB700 << 16);
    // 0x8000B7F4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8000B7F8: lui         $t4, 0xB900
    ctx->r12 = S32(0XB900 << 16);
    // 0x8000B7FC: lui         $t5, 0xC811
    ctx->r13 = S32(0XC811 << 16);
    // 0x8000B800: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8000B804: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x8000B808: ori         $t5, $t5, 0x3078
    ctx->r13 = ctx->r13 | 0X3078;
    // 0x8000B80C: ori         $t4, $t4, 0x31D
    ctx->r12 = ctx->r12 | 0X31D;
    // 0x8000B810: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x8000B814: sw          $t5, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r13;
    // 0x8000B818: b           L_8000B86C
    // 0x8000B81C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
        goto L_8000B86C;
    // 0x8000B81C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_8000B820:
    // 0x8000B820: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000B824: ori         $t6, $t6, 0x1402
    ctx->r14 = ctx->r14 | 0X1402;
    // 0x8000B828: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8000B82C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8000B830: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8000B834: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000B838: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x8000B83C: ori         $t8, $t8, 0x2205
    ctx->r24 = ctx->r24 | 0X2205;
    // 0x8000B840: lui         $t7, 0xB700
    ctx->r15 = S32(0XB700 << 16);
    // 0x8000B844: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8000B848: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8000B84C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8000B850: lui         $t9, 0xB900
    ctx->r25 = S32(0XB900 << 16);
    // 0x8000B854: lui         $t0, 0x55
    ctx->r8 = S32(0X55 << 16);
    // 0x8000B858: ori         $t0, $t0, 0x3078
    ctx->r8 = ctx->r8 | 0X3078;
    // 0x8000B85C: ori         $t9, $t9, 0x31D
    ctx->r25 = ctx->r25 | 0X31D;
    // 0x8000B860: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8000B864: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x8000B868: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_8000B86C:
    // 0x8000B86C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000B870: lh          $v0, -0x2CC2($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2CC2);
    // 0x8000B874: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000B878: lui         $t7, 0xBC00
    ctx->r15 = S32(0XBC00 << 16);
    // 0x8000B87C: beq         $v0, $at, L_8000B900
    if (ctx->r2 == ctx->r1) {
        // 0x8000B880: ori         $t7, $t7, 0x2
        ctx->r15 = ctx->r15 | 0X2;
            goto L_8000B900;
    }
    // 0x8000B880: ori         $t7, $t7, 0x2
    ctx->r15 = ctx->r15 | 0X2;
    // 0x8000B884: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8000B888: beq         $v0, $at, L_8000B95C
    if (ctx->r2 == ctx->r1) {
        // 0x8000B88C: lui         $t3, 0xBC00
        ctx->r11 = S32(0XBC00 << 16);
            goto L_8000B95C;
    }
    // 0x8000B88C: lui         $t3, 0xBC00
    ctx->r11 = S32(0XBC00 << 16);
    // 0x8000B890: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8000B894: beq         $v0, $at, L_8000B9BC
    if (ctx->r2 == ctx->r1) {
        // 0x8000B898: lui         $t9, 0xBC00
        ctx->r25 = S32(0XBC00 << 16);
            goto L_8000B9BC;
    }
    // 0x8000B898: lui         $t9, 0xBC00
    ctx->r25 = S32(0XBC00 << 16);
    // 0x8000B89C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8000B8A0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000B8A4: lui         $t1, 0xBC00
    ctx->r9 = S32(0XBC00 << 16);
    // 0x8000B8A8: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x8000B8AC: ori         $t2, $t2, 0x40
    ctx->r10 = ctx->r10 | 0X40;
    // 0x8000B8B0: ori         $t1, $t1, 0x2
    ctx->r9 = ctx->r9 | 0X2;
    // 0x8000B8B4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8000B8B8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000B8BC: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8000B8C0: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8000B8C4: lui         $t3, 0x386
    ctx->r11 = S32(0X386 << 16);
    // 0x8000B8C8: lui         $t4, 0x8007
    ctx->r12 = S32(0X8007 << 16);
    // 0x8000B8CC: addiu       $t4, $t4, -0x6C10
    ctx->r12 = ADD32(ctx->r12, -0X6C10);
    // 0x8000B8D0: ori         $t3, $t3, 0x10
    ctx->r11 = ctx->r11 | 0X10;
    // 0x8000B8D4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8000B8D8: lui         $t5, 0x388
    ctx->r13 = S32(0X388 << 16);
    // 0x8000B8DC: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x8000B8E0: addiu       $t6, $t6, -0x6C18
    ctx->r14 = ADD32(ctx->r14, -0X6C18);
    // 0x8000B8E4: ori         $t5, $t5, 0x10
    ctx->r13 = ctx->r13 | 0X10;
    // 0x8000B8E8: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8000B8EC: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x8000B8F0: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x8000B8F4: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x8000B8F8: b           L_8000BA18
    // 0x8000B8FC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
        goto L_8000BA18;
    // 0x8000B8FC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_8000B900:
    // 0x8000B900: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8000B904: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000B908: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x8000B90C: ori         $t8, $t8, 0x40
    ctx->r24 = ctx->r24 | 0X40;
    // 0x8000B910: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8000B914: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000B918: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8000B91C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8000B920: lui         $t9, 0x386
    ctx->r25 = S32(0X386 << 16);
    // 0x8000B924: lui         $t0, 0x8007
    ctx->r8 = S32(0X8007 << 16);
    // 0x8000B928: addiu       $t0, $t0, -0x6BF8
    ctx->r8 = ADD32(ctx->r8, -0X6BF8);
    // 0x8000B92C: ori         $t9, $t9, 0x10
    ctx->r25 = ctx->r25 | 0X10;
    // 0x8000B930: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8000B934: lui         $t1, 0x388
    ctx->r9 = S32(0X388 << 16);
    // 0x8000B938: lui         $t2, 0x8007
    ctx->r10 = S32(0X8007 << 16);
    // 0x8000B93C: addiu       $t2, $t2, -0x6C00
    ctx->r10 = ADD32(ctx->r10, -0X6C00);
    // 0x8000B940: ori         $t1, $t1, 0x10
    ctx->r9 = ctx->r9 | 0X10;
    // 0x8000B944: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000B948: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x8000B94C: sw          $t2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r10;
    // 0x8000B950: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x8000B954: b           L_8000BA18
    // 0x8000B958: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
        goto L_8000BA18;
    // 0x8000B958: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_8000B95C:
    // 0x8000B95C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8000B960: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000B964: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x8000B968: ori         $t4, $t4, 0x40
    ctx->r12 = ctx->r12 | 0X40;
    // 0x8000B96C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8000B970: ori         $t3, $t3, 0x2
    ctx->r11 = ctx->r11 | 0X2;
    // 0x8000B974: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8000B978: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000B97C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8000B980: lui         $t5, 0x386
    ctx->r13 = S32(0X386 << 16);
    // 0x8000B984: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x8000B988: addiu       $t6, $t6, -0x6BE0
    ctx->r14 = ADD32(ctx->r14, -0X6BE0);
    // 0x8000B98C: ori         $t5, $t5, 0x10
    ctx->r13 = ctx->r13 | 0X10;
    // 0x8000B990: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8000B994: lui         $t7, 0x388
    ctx->r15 = S32(0X388 << 16);
    // 0x8000B998: lui         $t8, 0x8007
    ctx->r24 = S32(0X8007 << 16);
    // 0x8000B99C: addiu       $t8, $t8, -0x6BE8
    ctx->r24 = ADD32(ctx->r24, -0X6BE8);
    // 0x8000B9A0: ori         $t7, $t7, 0x10
    ctx->r15 = ctx->r15 | 0X10;
    // 0x8000B9A4: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8000B9A8: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8000B9AC: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x8000B9B0: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8000B9B4: b           L_8000BA18
    // 0x8000B9B8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
        goto L_8000BA18;
    // 0x8000B9B8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_8000B9BC:
    // 0x8000B9BC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8000B9C0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000B9C4: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x8000B9C8: ori         $t0, $t0, 0x40
    ctx->r8 = ctx->r8 | 0X40;
    // 0x8000B9CC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8000B9D0: ori         $t9, $t9, 0x2
    ctx->r25 = ctx->r25 | 0X2;
    // 0x8000B9D4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8000B9D8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000B9DC: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8000B9E0: lui         $t1, 0x386
    ctx->r9 = S32(0X386 << 16);
    // 0x8000B9E4: lui         $t2, 0x8007
    ctx->r10 = S32(0X8007 << 16);
    // 0x8000B9E8: addiu       $t2, $t2, -0x6BC8
    ctx->r10 = ADD32(ctx->r10, -0X6BC8);
    // 0x8000B9EC: ori         $t1, $t1, 0x10
    ctx->r9 = ctx->r9 | 0X10;
    // 0x8000B9F0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8000B9F4: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8000B9F8: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x8000B9FC: lui         $t3, 0x388
    ctx->r11 = S32(0X388 << 16);
    // 0x8000BA00: lui         $t4, 0x8007
    ctx->r12 = S32(0X8007 << 16);
    // 0x8000BA04: addiu       $t4, $t4, -0x6BD0
    ctx->r12 = ADD32(ctx->r12, -0X6BD0);
    // 0x8000BA08: ori         $t3, $t3, 0x10
    ctx->r11 = ctx->r11 | 0X10;
    // 0x8000BA0C: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x8000BA10: sw          $t4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r12;
    // 0x8000BA14: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_8000BA18:
    // 0x8000BA18: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8000BA1C: lui         $t5, 0xBA00
    ctx->r13 = S32(0XBA00 << 16);
    // 0x8000BA20: ori         $t5, $t5, 0x602
    ctx->r13 = ctx->r13 | 0X602;
    // 0x8000BA24: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000BA28: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8000BA2C: addiu       $t6, $zero, 0xC0
    ctx->r14 = ADD32(0, 0XC0);
    // 0x8000BA30: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8000BA34: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8000BA38: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000BA3C: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x8000BA40: ori         $t7, $t7, 0x1301
    ctx->r15 = ctx->r15 | 0X1301;
    // 0x8000BA44: lui         $t8, 0x8
    ctx->r24 = S32(0X8 << 16);
    // 0x8000BA48: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8000BA4C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8000BA50: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8000BA54: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000BA58: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x8000BA5C: ori         $t9, $t9, 0x1001
    ctx->r25 = ctx->r25 | 0X1001;
    // 0x8000BA60: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x8000BA64: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8000BA68: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x8000BA6C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8000BA70: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000BA74: lui         $t1, 0xBB00
    ctx->r9 = S32(0XBB00 << 16);
    // 0x8000BA78: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x8000BA7C: ori         $t2, $t2, 0x8000
    ctx->r10 = ctx->r10 | 0X8000;
    // 0x8000BA80: ori         $t1, $t1, 0x1
    ctx->r9 = ctx->r9 | 0X1;
    // 0x8000BA84: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8000BA88: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x8000BA8C: sw          $t2, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r10;
    // 0x8000BA90: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x8000BA94: ori         $t3, $t3, 0xE02
    ctx->r11 = ctx->r11 | 0XE02;
    // 0x8000BA98: ori         $t4, $zero, 0x8000
    ctx->r12 = 0 | 0X8000;
    // 0x8000BA9C: sw          $t4, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r12;
    // 0x8000BAA0: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x8000BAA4: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000BAA8: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8000BAAC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8000BAB0: lui         $t5, 0xF800
    ctx->r13 = S32(0XF800 << 16);
    // 0x8000BAB4: addiu       $a3, $a3, -0x2CD0
    ctx->r7 = ADD32(ctx->r7, -0X2CD0);
    // 0x8000BAB8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8000BABC: lw          $t6, 0x8($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X8);
    // 0x8000BAC0: lw          $t3, 0x4($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X4);
    // 0x8000BAC4: lw          $t0, 0x0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X0);
    // 0x8000BAC8: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8000BACC: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x8000BAD0: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x8000BAD4: sll         $t1, $t0, 24
    ctx->r9 = S32(ctx->r8 << 24);
    // 0x8000BAD8: or          $t2, $t8, $t1
    ctx->r10 = ctx->r24 | ctx->r9;
    // 0x8000BADC: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x8000BAE0: or          $t6, $t2, $t5
    ctx->r14 = ctx->r10 | ctx->r13;
    // 0x8000BAE4: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x8000BAE8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000BAEC: lui         $t9, 0xBC00
    ctx->r25 = S32(0XBC00 << 16);
    // 0x8000BAF0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8000BAF4: ori         $t9, $t9, 0x8
    ctx->r25 = ctx->r25 | 0X8;
    // 0x8000BAF8: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8000BAFC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000BB00: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8000BB04: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000BB08: lw          $a1, -0x2CF4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2CF4);
    // 0x8000BB0C: lw          $t0, -0x2CF8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2CF8);
    // 0x8000BB10: lui         $t8, 0x1
    ctx->r24 = S32(0X1 << 16);
    // 0x8000BB14: ori         $t8, $t8, 0xF400
    ctx->r24 = ctx->r24 | 0XF400;
    // 0x8000BB18: subu        $a2, $t0, $a1
    ctx->r6 = SUB32(ctx->r8, ctx->r5);
    // 0x8000BB1C: div         $zero, $t8, $a2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r6)));
    // 0x8000BB20: negu        $t2, $a1
    ctx->r10 = SUB32(0, ctx->r5);
    // 0x8000BB24: sll         $t5, $t2, 8
    ctx->r13 = S32(ctx->r10 << 8);
    // 0x8000BB28: addu        $t6, $t5, $t8
    ctx->r14 = ADD32(ctx->r13, ctx->r24);
    // 0x8000BB2C: mflo        $t1
    ctx->r9 = lo;
    // 0x8000BB30: andi        $t3, $t1, 0xFFFF
    ctx->r11 = ctx->r9 & 0XFFFF;
    // 0x8000BB34: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x8000BB38: div         $zero, $t6, $a2
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r6)));
    // 0x8000BB3C: mflo        $t7
    ctx->r15 = lo;
    // 0x8000BB40: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x8000BB44: or          $t0, $t4, $t9
    ctx->r8 = ctx->r12 | ctx->r25;
    // 0x8000BB48: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000BB4C: bne         $a2, $zero, L_8000BB58
    if (ctx->r6 != 0) {
        // 0x8000BB50: nop
    
            goto L_8000BB58;
    }
    // 0x8000BB50: nop

    // 0x8000BB54: break       7
    do_break(2147531604);
L_8000BB58:
    // 0x8000BB58: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000BB5C: bne         $a2, $at, L_8000BB70
    if (ctx->r6 != ctx->r1) {
        // 0x8000BB60: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8000BB70;
    }
    // 0x8000BB60: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000BB64: bne         $t8, $at, L_8000BB70
    if (ctx->r24 != ctx->r1) {
        // 0x8000BB68: nop
    
            goto L_8000BB70;
    }
    // 0x8000BB68: nop

    // 0x8000BB6C: break       6
    do_break(2147531628);
L_8000BB70:
    // 0x8000BB70: addu        $at, $t8, $zero
    ctx->r1 = ADD32(ctx->r24, 0);
    // 0x8000BB74: bne         $a2, $zero, L_8000BB80
    if (ctx->r6 != 0) {
        // 0x8000BB78: nop
    
            goto L_8000BB80;
    }
    // 0x8000BB78: nop

    // 0x8000BB7C: break       7
    do_break(2147531644);
L_8000BB80:
    // 0x8000BB80: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000BB84: bne         $a2, $at, L_8000BB98
    if (ctx->r6 != ctx->r1) {
        // 0x8000BB88: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8000BB98;
    }
    // 0x8000BB88: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000BB8C: bne         $t6, $at, L_8000BB98
    if (ctx->r14 != ctx->r1) {
        // 0x8000BB90: nop
    
            goto L_8000BB98;
    }
    // 0x8000BB90: nop

    // 0x8000BB94: break       6
    do_break(2147531668);
L_8000BB98:
    // 0x8000BB98: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x8000BB9C: jr          $ra
    // 0x8000BBA0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    TRACE_RETURN()
    return;
    // 0x8000BBA0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8000BBA4:
    // 0x8000BBA4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8000BBA8: addiu       $v1, $a0, 0x8
    ctx->r3 = ADD32(ctx->r4, 0X8);
    // 0x8000BBAC: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8000BBB0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8000BBB4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8000BBB8: lui         $t1, 0xBA00
    ctx->r9 = S32(0XBA00 << 16);
    // 0x8000BBBC: ori         $t1, $t1, 0x1402
    ctx->r9 = ctx->r9 | 0X1402;
    // 0x8000BBC0: addiu       $a1, $v1, 0x8
    ctx->r5 = ADD32(ctx->r3, 0X8);
    // 0x8000BBC4: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8000BBC8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000BBCC: lui         $t3, 0xB700
    ctx->r11 = S32(0XB700 << 16);
    // 0x8000BBD0: lui         $t2, 0x2
    ctx->r10 = S32(0X2 << 16);
    // 0x8000BBD4: sw          $t2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r10;
    // 0x8000BBD8: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x8000BBDC: addiu       $a2, $a1, 0x8
    ctx->r6 = ADD32(ctx->r5, 0X8);
    // 0x8000BBE0: addiu       $a3, $a2, 0x8
    ctx->r7 = ADD32(ctx->r6, 0X8);
    // 0x8000BBE4: lui         $t5, 0xB600
    ctx->r13 = S32(0XB600 << 16);
    // 0x8000BBE8: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x8000BBEC: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x8000BBF0: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x8000BBF4: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x8000BBF8: lui         $t4, 0x50
    ctx->r12 = S32(0X50 << 16);
    // 0x8000BBFC: ori         $t4, $t4, 0x4B50
    ctx->r12 = ctx->r12 | 0X4B50;
    // 0x8000BC00: ori         $t7, $t7, 0x31D
    ctx->r15 = ctx->r15 | 0X31D;
    // 0x8000BC04: addiu       $a0, $a3, 0x8
    ctx->r4 = ADD32(ctx->r7, 0X8);
    // 0x8000BC08: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8000BC0C: sw          $t4, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r12;
    // 0x8000BC10: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8000BC14: lui         $t9, 0xBC00
    ctx->r25 = S32(0XBC00 << 16);
    // 0x8000BC18: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x8000BC1C: ori         $t0, $t0, 0x40
    ctx->r8 = ctx->r8 | 0X40;
    // 0x8000BC20: ori         $t9, $t9, 0x2
    ctx->r25 = ctx->r25 | 0X2;
    // 0x8000BC24: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8000BC28: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8000BC2C: addiu       $v1, $a0, 0x8
    ctx->r3 = ADD32(ctx->r4, 0X8);
    // 0x8000BC30: lui         $t1, 0x8007
    ctx->r9 = S32(0X8007 << 16);
    // 0x8000BC34: lui         $t8, 0x386
    ctx->r24 = S32(0X386 << 16);
    // 0x8000BC38: ori         $t8, $t8, 0x10
    ctx->r24 = ctx->r24 | 0X10;
    // 0x8000BC3C: addiu       $t1, $t1, -0x6C28
    ctx->r9 = ADD32(ctx->r9, -0X6C28);
    // 0x8000BC40: addiu       $a1, $v1, 0x8
    ctx->r5 = ADD32(ctx->r3, 0X8);
    // 0x8000BC44: lui         $t3, 0x388
    ctx->r11 = S32(0X388 << 16);
    // 0x8000BC48: lui         $t2, 0x8007
    ctx->r10 = S32(0X8007 << 16);
    // 0x8000BC4C: addiu       $t2, $t2, -0x6C30
    ctx->r10 = ADD32(ctx->r10, -0X6C30);
    // 0x8000BC50: ori         $t3, $t3, 0x10
    ctx->r11 = ctx->r11 | 0X10;
    // 0x8000BC54: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8000BC58: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000BC5C: sw          $t2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r10;
    // 0x8000BC60: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x8000BC64: jr          $ra
    // 0x8000BC68: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    TRACE_RETURN()
    return;
    // 0x8000BC68: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
L_8000BC6C:
    // 0x8000BC6C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000BC70: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x8000BC74: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8000BC78: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8000BC7C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8000BC80: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000BC84: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x8000BC88: ori         $t6, $t6, 0x1402
    ctx->r14 = ctx->r14 | 0X1402;
    // 0x8000BC8C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8000BC90: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8000BC94: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000BC98: lui         $t7, 0xB700
    ctx->r15 = S32(0XB700 << 16);
    // 0x8000BC9C: lui         $t4, 0x2
    ctx->r12 = S32(0X2 << 16);
    // 0x8000BCA0: sw          $t4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r12;
    // 0x8000BCA4: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8000BCA8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000BCAC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8000BCB0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000BCB4: lui         $t9, 0xB600
    ctx->r25 = S32(0XB600 << 16);
    // 0x8000BCB8: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x8000BCBC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8000BCC0: sw          $t0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r8;
    // 0x8000BCC4: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8000BCC8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000BCCC: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x8000BCD0: lui         $t1, 0x50
    ctx->r9 = S32(0X50 << 16);
    // 0x8000BCD4: ori         $t1, $t1, 0x4B50
    ctx->r9 = ctx->r9 | 0X4B50;
    // 0x8000BCD8: ori         $t8, $t8, 0x31D
    ctx->r24 = ctx->r24 | 0X31D;
    // 0x8000BCDC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8000BCE0: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8000BCE4: sw          $t1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r9;
    // 0x8000BCE8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000BCEC: lui         $t3, 0xBC00
    ctx->r11 = S32(0XBC00 << 16);
    // 0x8000BCF0: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x8000BCF4: ori         $t2, $t2, 0x40
    ctx->r10 = ctx->r10 | 0X40;
    // 0x8000BCF8: ori         $t3, $t3, 0x2
    ctx->r11 = ctx->r11 | 0X2;
    // 0x8000BCFC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8000BD00: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000BD04: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8000BD08: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8000BD0C: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x8000BD10: lui         $t5, 0x386
    ctx->r13 = S32(0X386 << 16);
    // 0x8000BD14: ori         $t5, $t5, 0x10
    ctx->r13 = ctx->r13 | 0X10;
    // 0x8000BD18: addiu       $t6, $t6, -0x6C28
    ctx->r14 = ADD32(ctx->r14, -0X6C28);
    // 0x8000BD1C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8000BD20: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8000BD24: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8000BD28: lui         $t7, 0x388
    ctx->r15 = S32(0X388 << 16);
    // 0x8000BD2C: lui         $t4, 0x8007
    ctx->r12 = S32(0X8007 << 16);
    // 0x8000BD30: addiu       $t4, $t4, -0x6C30
    ctx->r12 = ADD32(ctx->r12, -0X6C30);
    // 0x8000BD34: ori         $t7, $t7, 0x10
    ctx->r15 = ctx->r15 | 0X10;
    // 0x8000BD38: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8000BD3C: sw          $t4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r12;
    // 0x8000BD40: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000BD44: jr          $ra
    // 0x8000BD48: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    TRACE_RETURN()
    return;
    // 0x8000BD48: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
