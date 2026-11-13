#include "recomp.h"
#include "trace.h"
#include "funcs.h"

RECOMP_FUNC void func_8004A064(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004A064: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004A068: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004A06C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8004A070: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8004A074: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8004A078: beq         $a0, $zero, L_8004A0AC
    if (ctx->r4 == 0) {
        // 0x8004A07C: or          $s0, $a0, $zero
        ctx->r16 = ctx->r4 | 0;
            goto L_8004A0AC;
    }
    // 0x8004A07C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8004A080: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8004A084: lui         $s1, 0x801A
    ctx->r17 = S32(0X801A << 16);
    // 0x8004A088: addiu       $s1, $s1, 0x2800
    ctx->r17 = ADD32(ctx->r17, 0X2800);
    // 0x8004A08C: addiu       $s2, $s2, -0x6C60
    ctx->r18 = ADD32(ctx->r18, -0X6C60);
    // 0x8004A090: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
L_8004A094:
    // 0x8004A094: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x8004A098: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004A09C: jal         0x8001026C
    // 0x8004A0A0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_8001026C(rdram, ctx);
        goto after_0;
    // 0x8004A0A0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_0:
    // 0x8004A0A4: bnel        $s0, $zero, L_8004A094
    if (ctx->r16 != 0) {
        // 0x8004A0A8: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_8004A094;
    }
    goto skip_0;
    // 0x8004A0A8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    skip_0:
L_8004A0AC:
    // 0x8004A0AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8004A0B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004A0B4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8004A0B8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8004A0BC: jr          $ra
    // 0x8004A0C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    TRACE_RETURN()
    return;
    // 0x8004A0C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8004A0C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004A0C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004A0C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004A0CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004A0D0: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x8004A0D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8004A0D8: lw          $a1, 0xE0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0XE0);
    // 0x8004A0DC: beql        $a1, $zero, L_8004A0F0
    if (ctx->r5 == 0) {
        // 0x8004A0E0: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_8004A0F0;
    }
    goto skip_0;
    // 0x8004A0E0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x8004A0E4: jal         0x8004D690
    // 0x8004A0E8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_8004D690(rdram, ctx);
        goto after_0;
    // 0x8004A0E8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8004A0EC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_8004A0F0:
    // 0x8004A0F0: beql        $a0, $zero, L_8004A104
    if (ctx->r4 == 0) {
        // 0x8004A0F4: lw          $t7, 0xC($s0)
        ctx->r15 = MEM_W(ctx->r16, 0XC);
            goto L_8004A104;
    }
    goto skip_1;
    // 0x8004A0F4: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    skip_1:
    // 0x8004A0F8: jal         0x8004A064
    // 0x8004A0FC: nop

    func_8004A064(rdram, ctx);
        goto after_1;
    // 0x8004A0FC: nop

    after_1:
    // 0x8004A100: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
L_8004A104:
    // 0x8004A104: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004A108: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8004A10C: addiu       $a2, $a2, -0x6C60
    ctx->r6 = ADD32(ctx->r6, -0X6C60);
    // 0x8004A110: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8004A114: jal         0x8001026C
    // 0x8004A118: lw          $a1, 0xD0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0XD0);
    func_8001026C(rdram, ctx);
        goto after_2;
    // 0x8004A118: lw          $a1, 0xD0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0XD0);
    after_2:
    // 0x8004A11C: jal         0x8000F8BC
    // 0x8004A120: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    func_8000F8BC(rdram, ctx);
        goto after_3;
    // 0x8004A120: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    after_3:
    // 0x8004A124: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004A128: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8004A12C: jal         0x800042A8
    // 0x8004A130: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800042A8(rdram, ctx);
        goto after_4;
    // 0x8004A130: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x8004A134: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004A138: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004A13C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004A140: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8004A148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004A148: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8004A14C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004A150: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004A154: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x8004A158: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8004A15C: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8004A160: lw          $v1, 0xDC($t6)
    ctx->r3 = MEM_W(ctx->r14, 0XDC);
    // 0x8004A164: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x8004A168: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8004A16C: beq         $v1, $zero, L_8004A178
    if (ctx->r3 == 0) {
        // 0x8004A170: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_8004A178;
    }
    // 0x8004A170: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8004A174: lh          $t3, 0xE($v1)
    ctx->r11 = MEM_H(ctx->r3, 0XE);
L_8004A178:
    // 0x8004A178: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8004A17C: lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XC);
    // 0x8004A180: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8004A184: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x8004A188: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004A18C: andi        $t2, $t3, 0x2
    ctx->r10 = ctx->r11 & 0X2;
    // 0x8004A190: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8004A194: lw          $v0, 0xD0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XD0);
    // 0x8004A198: beql        $a0, $zero, L_8004A23C
    if (ctx->r4 == 0) {
        // 0x8004A19C: sw          $t0, 0xD4($v1)
        MEM_W(0XD4, ctx->r3) = ctx->r8;
            goto L_8004A23C;
    }
    goto skip_0;
    // 0x8004A19C: sw          $t0, 0xD4($v1)
    MEM_W(0XD4, ctx->r3) = ctx->r8;
    skip_0:
    // 0x8004A1A0: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_8004A1A4:
    // 0x8004A1A4: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
    // 0x8004A1A8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8004A1AC: addiu       $t9, $t8, 0x90
    ctx->r25 = ADD32(ctx->r24, 0X90);
    // 0x8004A1B0: beql        $a2, $t9, L_8004A1D4
    if (ctx->r6 == ctx->r25) {
        // 0x8004A1B4: sh          $t1, 0x0($v0)
        MEM_H(0X0, ctx->r2) = ctx->r9;
            goto L_8004A1D4;
    }
    goto skip_1;
    // 0x8004A1B4: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
    skip_1:
    // 0x8004A1B8: sh          $a3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r7;
    // 0x8004A1BC: lw          $a2, 0xC($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XC);
    // 0x8004A1C0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8004A1C4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8004A1C8: addiu       $a2, $a2, 0x90
    ctx->r6 = ADD32(ctx->r6, 0X90);
    // 0x8004A1CC: sw          $a2, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r6;
    // 0x8004A1D0: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
L_8004A1D4:
    // 0x8004A1D4: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    // 0x8004A1D8: beq         $t2, $zero, L_8004A220
    if (ctx->r10 == 0) {
        // 0x8004A1DC: sw          $t5, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r13;
            goto L_8004A220;
    }
    // 0x8004A1DC: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8004A1E0: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x8004A1E4: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8004A1E8: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x8004A1EC: lw          $v1, 0xDC($t6)
    ctx->r3 = MEM_W(ctx->r14, 0XDC);
    // 0x8004A1F0: lw          $a2, 0x0($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X0);
    // 0x8004A1F4: lh          $a3, 0xC($v1)
    ctx->r7 = MEM_H(ctx->r3, 0XC);
    // 0x8004A1F8: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x8004A1FC: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8004A200: jal         0x8004D48C
    // 0x8004A204: addiu       $a0, $v1, 0x10
    ctx->r4 = ADD32(ctx->r3, 0X10);
    func_8004D48C(rdram, ctx);
        goto after_0;
    // 0x8004A204: addiu       $a0, $v1, 0x10
    ctx->r4 = ADD32(ctx->r3, 0X10);
    after_0:
    // 0x8004A208: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8004A20C: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8004A210: or          $t4, $v0, $zero
    ctx->r12 = ctx->r2 | 0;
    // 0x8004A214: lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XC);
    // 0x8004A218: b           L_8004A238
    // 0x8004A21C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
        goto L_8004A238;
    // 0x8004A21C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_8004A220:
    // 0x8004A220: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8004A224: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8004A228: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8004A22C: bnel        $a0, $zero, L_8004A1A4
    if (ctx->r4 != 0) {
        // 0x8004A230: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_8004A1A4;
    }
    goto skip_2;
    // 0x8004A230: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    skip_2:
    // 0x8004A234: lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XC);
L_8004A238:
    // 0x8004A238: sw          $t0, 0xD4($v1)
    MEM_W(0XD4, ctx->r3) = ctx->r8;
L_8004A23C:
    // 0x8004A23C: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x8004A240: andi        $t9, $t3, 0x1
    ctx->r25 = ctx->r11 & 0X1;
    // 0x8004A244: bne         $t9, $zero, L_8004A258
    if (ctx->r25 != 0) {
        // 0x8004A248: sw          $t4, 0xE0($t8)
        MEM_W(0XE0, ctx->r24) = ctx->r12;
            goto L_8004A258;
    }
    // 0x8004A248: sw          $t4, 0xE0($t8)
    MEM_W(0XE0, ctx->r24) = ctx->r12;
    // 0x8004A24C: jal         0x8004A064
    // 0x8004A250: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_8004A064(rdram, ctx);
        goto after_1;
    // 0x8004A250: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x8004A254: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_8004A258:
    // 0x8004A258: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004A25C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004A260: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8004A264: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8004A26C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004A26C: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x8004A270: addiu       $v1, $v0, -0x45E0
    ctx->r3 = ADD32(ctx->r2, -0X45E0);
    // 0x8004A274: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8004A278: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x8004A27C: addiu       $t7, $t7, -0x45E0
    ctx->r15 = ADD32(ctx->r15, -0X45E0);
    // 0x8004A280: beql        $t6, $zero, L_8004A2C8
    if (ctx->r14 == 0) {
        // 0x8004A284: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8004A2C8;
    }
    goto skip_0;
    // 0x8004A284: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8004A288: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x8004A28C: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x8004A290: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
L_8004A294:
    // 0x8004A294: bnel        $a2, $t8, L_8004A2B8
    if (ctx->r6 != ctx->r24) {
        // 0x8004A298: lw          $a1, 0x8($v1)
        ctx->r5 = MEM_W(ctx->r3, 0X8);
            goto L_8004A2B8;
    }
    goto skip_1;
    // 0x8004A298: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
    skip_1:
    // 0x8004A29C: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x8004A2A0: lw          $t0, 0x4($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X4);
    // 0x8004A2A4: bnel        $t9, $t0, L_8004A2B8
    if (ctx->r25 != ctx->r8) {
        // 0x8004A2A8: lw          $a1, 0x8($v1)
        ctx->r5 = MEM_W(ctx->r3, 0X8);
            goto L_8004A2B8;
    }
    goto skip_2;
    // 0x8004A2A8: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
    skip_2:
    // 0x8004A2AC: jr          $ra
    // 0x8004A2B0: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    TRACE_RETURN()
    return;
    // 0x8004A2B0: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8004A2B4: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
L_8004A2B8:
    // 0x8004A2B8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8004A2BC: bnel        $a1, $zero, L_8004A294
    if (ctx->r5 != 0) {
        // 0x8004A2C0: lw          $t8, 0x0($a1)
        ctx->r24 = MEM_W(ctx->r5, 0X0);
            goto L_8004A294;
    }
    goto skip_3;
    // 0x8004A2C0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    skip_3:
    // 0x8004A2C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004A2C8:
    // 0x8004A2C8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8004A2D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004A2D0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8004A2D4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8004A2D8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8004A2DC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8004A2E0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8004A2E4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8004A2E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004A2EC: lh          $t6, 0xC($a0)
    ctx->r14 = MEM_H(ctx->r4, 0XC);
    // 0x8004A2F0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8004A2F4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8004A2F8: blez        $t6, L_8004A358
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8004A2FC: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8004A358;
    }
    // 0x8004A2FC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8004A300: lui         $s4, 0x801A
    ctx->r20 = S32(0X801A << 16);
    // 0x8004A304: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8004A308: addiu       $s2, $s2, -0x6C60
    ctx->r18 = ADD32(ctx->r18, -0X6C60);
    // 0x8004A30C: addiu       $s4, $s4, 0x2800
    ctx->r20 = ADD32(ctx->r20, 0X2800);
    // 0x8004A310: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
L_8004A314:
    // 0x8004A314: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8004A318: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8004A31C: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8004A320: jal         0x8001026C
    // 0x8004A324: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    func_8001026C(rdram, ctx);
        goto after_0;
    // 0x8004A324: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    after_0:
    // 0x8004A328: lw          $t9, 0x4($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X4);
    // 0x8004A32C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8004A330: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8004A334: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x8004A338: jal         0x8001026C
    // 0x8004A33C: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    func_8001026C(rdram, ctx);
        goto after_1;
    // 0x8004A33C: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    after_1:
    // 0x8004A340: lh          $t1, 0xC($s3)
    ctx->r9 = MEM_H(ctx->r19, 0XC);
    // 0x8004A344: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8004A348: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8004A34C: slt         $at, $s1, $t1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8004A350: bnel        $at, $zero, L_8004A314
    if (ctx->r1 != 0) {
        // 0x8004A354: lw          $t7, 0x0($s3)
        ctx->r15 = MEM_W(ctx->r19, 0X0);
            goto L_8004A314;
    }
    goto skip_0;
    // 0x8004A354: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    skip_0:
L_8004A358:
    // 0x8004A358: lui         $s4, 0x801A
    ctx->r20 = S32(0X801A << 16);
    // 0x8004A35C: addiu       $s4, $s4, 0x2800
    ctx->r20 = ADD32(ctx->r20, 0X2800);
    // 0x8004A360: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8004A364: jal         0x800042A8
    // 0x8004A368: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    func_800042A8(rdram, ctx);
        goto after_2;
    // 0x8004A368: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    after_2:
    // 0x8004A36C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8004A370: jal         0x800042A8
    // 0x8004A374: lw          $a1, 0x4($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X4);
    func_800042A8(rdram, ctx);
        goto after_3;
    // 0x8004A374: lw          $a1, 0x4($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X4);
    after_3:
    // 0x8004A378: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8004A37C: jal         0x800042A8
    // 0x8004A380: lw          $a1, 0x8($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X8);
    func_800042A8(rdram, ctx);
        goto after_4;
    // 0x8004A380: lw          $a1, 0x8($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X8);
    after_4:
    // 0x8004A384: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8004A388: jal         0x800042A8
    // 0x8004A38C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800042A8(rdram, ctx);
        goto after_5;
    // 0x8004A38C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_5:
    // 0x8004A390: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8004A394: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004A398: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8004A39C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8004A3A0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8004A3A4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8004A3A8: jr          $ra
    // 0x8004A3AC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    TRACE_RETURN()
    return;
    // 0x8004A3AC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8004A3B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004A3B0: addiu       $sp, $sp, -0x218
    ctx->r29 = ADD32(ctx->r29, -0X218);
    // 0x8004A3B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004A3B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8004A3BC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8004A3C0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8004A3C4: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004A3C8: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8004A3CC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8004A3D0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8004A3D4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8004A3D8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8004A3DC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8004A3E0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8004A3E4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8004A3E8: sh          $t6, 0xB8($sp)
    MEM_H(0XB8, ctx->r29) = ctx->r14;
    // 0x8004A3EC: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8004A3F0: jal         0x80004364
    // 0x8004A3F4: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x8004A3F4: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    after_0:
    // 0x8004A3F8: addiu       $s2, $sp, 0x110
    ctx->r18 = ADD32(ctx->r29, 0X110);
    // 0x8004A3FC: sw          $zero, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = 0;
    // 0x8004A400: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8004A404: jal         0x800050B0
    // 0x8004A408: sw          $v0, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r2;
    func_800050B0(rdram, ctx);
        goto after_1;
    // 0x8004A408: sw          $v0, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r2;
    after_1:
    // 0x8004A40C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8004A410: jal         0x80005160
    // 0x8004A414: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80005160(rdram, ctx);
        goto after_2;
    // 0x8004A414: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8004A418: lw          $t7, 0x110($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X110);
    // 0x8004A41C: lw          $ra, 0x214($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X214);
    // 0x8004A420: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8004A424: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8004A428: addu        $t9, $s2, $t8
    ctx->r25 = ADD32(ctx->r18, ctx->r24);
    // 0x8004A42C: lw          $t6, 0x10($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X10);
    // 0x8004A430: lui         $s6, 0xBF00
    ctx->r22 = S32(0XBF00 << 16);
    // 0x8004A434: addiu       $s5, $zero, 0xA
    ctx->r21 = ADD32(0, 0XA);
    // 0x8004A438: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8004A43C: beq         $at, $zero, L_8004ACFC
    if (ctx->r1 == 0) {
        // 0x8004A440: addiu       $s4, $zero, 0xFF
        ctx->r20 = ADD32(0, 0XFF);
            goto L_8004ACFC;
    }
    // 0x8004A440: addiu       $s4, $zero, 0xFF
    ctx->r20 = ADD32(0, 0XFF);
    // 0x8004A444: lw          $s3, 0xFC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XFC);
    // 0x8004A448: lw          $s1, 0xB4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XB4);
    // 0x8004A44C: sw          $ra, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r31;
L_8004A450:
    // 0x8004A450: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8004A454: jal         0x80005160
    // 0x8004A458: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80005160(rdram, ctx);
        goto after_3;
    // 0x8004A458: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x8004A45C: lw          $t7, 0x110($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X110);
    // 0x8004A460: lui         $at, 0x6D6F
    ctx->r1 = S32(0X6D6F << 16);
    // 0x8004A464: ori         $at, $at, 0x6465
    ctx->r1 = ctx->r1 | 0X6465;
    // 0x8004A468: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8004A46C: addu        $t9, $s2, $t8
    ctx->r25 = ADD32(ctx->r18, ctx->r24);
    // 0x8004A470: lw          $a0, 0x8($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X8);
    // 0x8004A474: lw          $ra, 0x214($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X214);
    // 0x8004A478: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8004A47C: beq         $a0, $at, L_8004A564
    if (ctx->r4 == ctx->r1) {
        // 0x8004A480: lui         $at, 0x6E61
        ctx->r1 = S32(0X6E61 << 16);
            goto L_8004A564;
    }
    // 0x8004A480: lui         $at, 0x6E61
    ctx->r1 = S32(0X6E61 << 16);
    // 0x8004A484: ori         $at, $at, 0x6D65
    ctx->r1 = ctx->r1 | 0X6D65;
    // 0x8004A488: beq         $a0, $at, L_8004A570
    if (ctx->r4 == ctx->r1) {
        // 0x8004A48C: or          $s7, $zero, $zero
        ctx->r23 = 0 | 0;
            goto L_8004A570;
    }
    // 0x8004A48C: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x8004A490: lui         $at, 0x6E6F
    ctx->r1 = S32(0X6E6F << 16);
    // 0x8004A494: ori         $at, $at, 0x6465
    ctx->r1 = ctx->r1 | 0X6465;
    // 0x8004A498: beq         $a0, $at, L_8004A610
    if (ctx->r4 == ctx->r1) {
        // 0x8004A49C: or          $s7, $zero, $zero
        ctx->r23 = 0 | 0;
            goto L_8004A610;
    }
    // 0x8004A49C: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x8004A4A0: lui         $at, 0x6E6F
    ctx->r1 = S32(0X6E6F << 16);
    // 0x8004A4A4: ori         $at, $at, 0x646E
    ctx->r1 = ctx->r1 | 0X646E;
    // 0x8004A4A8: beq         $a0, $at, L_8004A4FC
    if (ctx->r4 == ctx->r1) {
        // 0x8004A4AC: lui         $at, 0x7465
        ctx->r1 = S32(0X7465 << 16);
            goto L_8004A4FC;
    }
    // 0x8004A4AC: lui         $at, 0x7465
    ctx->r1 = S32(0X7465 << 16);
    // 0x8004A4B0: ori         $at, $at, 0x7874
    ctx->r1 = ctx->r1 | 0X7874;
    // 0x8004A4B4: beq         $a0, $at, L_8004A5DC
    if (ctx->r4 == ctx->r1) {
        // 0x8004A4B8: addiu       $a2, $s0, 0x4
        ctx->r6 = ADD32(ctx->r16, 0X4);
            goto L_8004A5DC;
    }
    // 0x8004A4B8: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x8004A4BC: lui         $at, 0x7472
    ctx->r1 = S32(0X7472 << 16);
    // 0x8004A4C0: ori         $at, $at, 0x694E
    ctx->r1 = ctx->r1 | 0X694E;
    // 0x8004A4C4: beq         $a0, $at, L_8004A5D0
    if (ctx->r4 == ctx->r1) {
        // 0x8004A4C8: lui         $at, 0x7478
        ctx->r1 = S32(0X7478 << 16);
            goto L_8004A5D0;
    }
    // 0x8004A4C8: lui         $at, 0x7478
    ctx->r1 = S32(0X7478 << 16);
    // 0x8004A4CC: ori         $at, $at, 0x746E
    ctx->r1 = ctx->r1 | 0X746E;
    // 0x8004A4D0: beq         $a0, $at, L_8004A4EC
    if (ctx->r4 == ctx->r1) {
        // 0x8004A4D4: lui         $at, 0x7674
        ctx->r1 = S32(0X7674 << 16);
            goto L_8004A4EC;
    }
    // 0x8004A4D4: lui         $at, 0x7674
    ctx->r1 = S32(0X7674 << 16);
    // 0x8004A4D8: ori         $at, $at, 0x784E
    ctx->r1 = ctx->r1 | 0X784E;
    // 0x8004A4DC: beql        $a0, $at, L_8004A5C8
    if (ctx->r4 == ctx->r1) {
        // 0x8004A4E0: lw          $t9, 0x0($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X0);
            goto L_8004A5C8;
    }
    goto skip_0;
    // 0x8004A4E0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x8004A4E4: b           L_8004ACC8
    // 0x8004A4E8: sw          $ra, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r31;
        goto L_8004ACC8;
    // 0x8004A4E8: sw          $ra, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r31;
L_8004A4EC:
    // 0x8004A4EC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8004A4F0: sw          $t6, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r14;
    // 0x8004A4F4: b           L_8004ACC4
    // 0x8004A4F8: sh          $t6, 0x1E($ra)
    MEM_H(0X1E, ctx->r31) = ctx->r14;
        goto L_8004ACC4;
    // 0x8004A4F8: sh          $t6, 0x1E($ra)
    MEM_H(0X1E, ctx->r31) = ctx->r14;
L_8004A4FC:
    // 0x8004A4FC: lw          $s7, 0x0($s0)
    ctx->r23 = MEM_W(ctx->r16, 0X0);
    // 0x8004A500: lui         $fp, 0x801A
    ctx->r30 = S32(0X801A << 16);
    // 0x8004A504: addiu       $fp, $fp, 0x2800
    ctx->r30 = ADD32(ctx->r30, 0X2800);
    // 0x8004A508: sw          $ra, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r31;
    // 0x8004A50C: sll         $s2, $s7, 2
    ctx->r18 = S32(ctx->r23 << 2);
    // 0x8004A510: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8004A514: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8004A518: jal         0x80004364
    // 0x8004A51C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    func_80004364(rdram, ctx);
        goto after_4;
    // 0x8004A51C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_4:
    // 0x8004A520: lw          $ra, 0x214($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X214);
    // 0x8004A524: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8004A528: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8004A52C: sw          $v0, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->r2;
    // 0x8004A530: jal         0x80004364
    // 0x8004A534: nop

    func_80004364(rdram, ctx);
        goto after_5;
    // 0x8004A534: nop

    after_5:
    // 0x8004A538: lw          $ra, 0x214($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X214);
    // 0x8004A53C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8004A540: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8004A544: sw          $v0, 0x4($ra)
    MEM_W(0X4, ctx->r31) = ctx->r2;
    // 0x8004A548: jal         0x80004364
    // 0x8004A54C: nop

    func_80004364(rdram, ctx);
        goto after_6;
    // 0x8004A54C: nop

    after_6:
    // 0x8004A550: lw          $ra, 0x214($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X214);
    // 0x8004A554: addiu       $s2, $sp, 0x110
    ctx->r18 = ADD32(ctx->r29, 0X110);
    // 0x8004A558: sw          $v0, 0x8($ra)
    MEM_W(0X8, ctx->r31) = ctx->r2;
    // 0x8004A55C: b           L_8004ACC4
    // 0x8004A560: sh          $s7, 0xC($ra)
    MEM_H(0XC, ctx->r31) = ctx->r23;
        goto L_8004ACC4;
    // 0x8004A560: sh          $s7, 0xC($ra)
    MEM_H(0XC, ctx->r31) = ctx->r23;
L_8004A564:
    // 0x8004A564: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8004A568: b           L_8004ACC4
    // 0x8004A56C: sh          $t8, 0xE($ra)
    MEM_H(0XE, ctx->r31) = ctx->r24;
        goto L_8004ACC4;
    // 0x8004A56C: sh          $t8, 0xE($ra)
    MEM_H(0XE, ctx->r31) = ctx->r24;
L_8004A570:
    // 0x8004A570: sw          $ra, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r31;
    // 0x8004A574: jal         0x8004A26C
    // 0x8004A578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8004A26C(rdram, ctx);
        goto after_7;
    // 0x8004A578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8004A57C: lw          $ra, 0x214($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X214);
    // 0x8004A580: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8004A584: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8004A588: or          $v1, $ra, $zero
    ctx->r3 = ctx->r31 | 0;
L_8004A58C:
    // 0x8004A58C: lbu         $t9, 0x0($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X0);
    // 0x8004A590: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x8004A594: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8004A598: sb          $t9, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r25;
    // 0x8004A59C: lbu         $t6, -0x3($s0)
    ctx->r14 = MEM_BU(ctx->r16, -0X3);
    // 0x8004A5A0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8004A5A4: sb          $t6, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r14;
    // 0x8004A5A8: lbu         $t7, -0x2($s0)
    ctx->r15 = MEM_BU(ctx->r16, -0X2);
    // 0x8004A5AC: sb          $t7, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r15;
    // 0x8004A5B0: lbu         $t8, -0x1($s0)
    ctx->r24 = MEM_BU(ctx->r16, -0X1);
    // 0x8004A5B4: bne         $s7, $v0, L_8004A58C
    if (ctx->r23 != ctx->r2) {
        // 0x8004A5B8: sb          $t8, 0xF($v1)
        MEM_B(0XF, ctx->r3) = ctx->r24;
            goto L_8004A58C;
    }
    // 0x8004A5B8: sb          $t8, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r24;
    // 0x8004A5BC: b           L_8004ACC4
    // 0x8004A5C0: addiu       $s2, $sp, 0x110
    ctx->r18 = ADD32(ctx->r29, 0X110);
        goto L_8004ACC4;
    // 0x8004A5C0: addiu       $s2, $sp, 0x110
    ctx->r18 = ADD32(ctx->r29, 0X110);
    // 0x8004A5C4: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
L_8004A5C8:
    // 0x8004A5C8: b           L_8004ACC4
    // 0x8004A5CC: sh          $t9, 0x1A($ra)
    MEM_H(0X1A, ctx->r31) = ctx->r25;
        goto L_8004ACC4;
    // 0x8004A5CC: sh          $t9, 0x1A($ra)
    MEM_H(0X1A, ctx->r31) = ctx->r25;
L_8004A5D0:
    // 0x8004A5D0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8004A5D4: b           L_8004ACC4
    // 0x8004A5D8: sh          $t6, 0x1C($ra)
    MEM_H(0X1C, ctx->r31) = ctx->r14;
        goto L_8004ACC4;
    // 0x8004A5D8: sh          $t6, 0x1C($ra)
    MEM_H(0X1C, ctx->r31) = ctx->r14;
L_8004A5DC:
    // 0x8004A5DC: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8004A5E0: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    // 0x8004A5E4: sw          $ra, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r31;
    // 0x8004A5E8: jal         0x8004B010
    // 0x8004A5EC: addiu       $a3, $a2, 0x10
    ctx->r7 = ADD32(ctx->r6, 0X10);
    func_8004B010(rdram, ctx);
        goto after_8;
    // 0x8004A5EC: addiu       $a3, $a2, 0x10
    ctx->r7 = ADD32(ctx->r6, 0X10);
    after_8:
    // 0x8004A5F0: lw          $t7, 0x104($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X104);
    // 0x8004A5F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004A5F8: lw          $ra, 0x214($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X214);
    // 0x8004A5FC: bne         $t7, $at, L_8004A608
    if (ctx->r15 != ctx->r1) {
        // 0x8004A600: sh          $v0, 0xB2($sp)
        MEM_H(0XB2, ctx->r29) = ctx->r2;
            goto L_8004A608;
    }
    // 0x8004A600: sh          $v0, 0xB2($sp)
    MEM_H(0XB2, ctx->r29) = ctx->r2;
    // 0x8004A604: sh          $v0, 0x18($ra)
    MEM_H(0X18, ctx->r31) = ctx->r2;
L_8004A608:
    // 0x8004A608: b           L_8004ACC4
    // 0x8004A60C: addiu       $s2, $sp, 0x110
    ctx->r18 = ADD32(ctx->r29, 0X110);
        goto L_8004ACC4;
    // 0x8004A60C: addiu       $s2, $sp, 0x110
    ctx->r18 = ADD32(ctx->r29, 0X110);
L_8004A610:
    // 0x8004A610: lw          $t9, 0x8($ra)
    ctx->r25 = MEM_W(ctx->r31, 0X8);
    // 0x8004A614: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8004A618: sll         $fp, $s3, 2
    ctx->r30 = S32(ctx->r19 << 2);
    // 0x8004A61C: addu        $t6, $t9, $fp
    ctx->r14 = ADD32(ctx->r25, ctx->r30);
    // 0x8004A620: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8004A624: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8004A628: sw          $s0, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r16;
    // 0x8004A62C: lh          $t4, 0x12($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X12);
    // 0x8004A630: lh          $v0, 0x14($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X14);
    // 0x8004A634: lh          $t7, 0x16($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X16);
    // 0x8004A638: sw          $ra, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r31;
    // 0x8004A63C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004A640: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x8004A644: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8004A648: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8004A64C: sh          $t4, 0xF0($sp)
    MEM_H(0XF0, ctx->r29) = ctx->r12;
    // 0x8004A650: sll         $a1, $v0, 4
    ctx->r5 = S32(ctx->r2 << 4);
    // 0x8004A654: jal         0x80004364
    // 0x8004A658: sh          $t7, 0xEC($sp)
    MEM_H(0XEC, ctx->r29) = ctx->r15;
    func_80004364(rdram, ctx);
        goto after_9;
    // 0x8004A658: sh          $t7, 0xEC($sp)
    MEM_H(0XEC, ctx->r29) = ctx->r15;
    after_9:
    // 0x8004A65C: lw          $ra, 0x214($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X214);
    // 0x8004A660: lh          $t4, 0xF0($sp)
    ctx->r12 = MEM_H(ctx->r29, 0XF0);
    // 0x8004A664: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004A668: lw          $t9, 0x0($ra)
    ctx->r25 = MEM_W(ctx->r31, 0X0);
    // 0x8004A66C: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8004A670: addu        $t8, $t9, $fp
    ctx->r24 = ADD32(ctx->r25, ctx->r30);
    // 0x8004A674: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x8004A678: lh          $t6, 0xEC($sp)
    ctx->r14 = MEM_H(ctx->r29, 0XEC);
    // 0x8004A67C: sw          $v0, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r2;
    // 0x8004A680: addu        $a1, $t6, $t4
    ctx->r5 = ADD32(ctx->r14, ctx->r12);
    // 0x8004A684: sll         $t7, $a1, 3
    ctx->r15 = S32(ctx->r5 << 3);
    // 0x8004A688: jal         0x80004364
    // 0x8004A68C: addiu       $a1, $t7, 0x80
    ctx->r5 = ADD32(ctx->r15, 0X80);
    func_80004364(rdram, ctx);
        goto after_10;
    // 0x8004A68C: addiu       $a1, $t7, 0x80
    ctx->r5 = ADD32(ctx->r15, 0X80);
    after_10:
    // 0x8004A690: lw          $ra, 0x214($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X214);
    // 0x8004A694: addiu       $a0, $sp, 0xB2
    ctx->r4 = ADD32(ctx->r29, 0XB2);
    // 0x8004A698: lw          $t9, 0x4($ra)
    ctx->r25 = MEM_W(ctx->r31, 0X4);
    // 0x8004A69C: addu        $t8, $t9, $fp
    ctx->r24 = ADD32(ctx->r25, ctx->r30);
    // 0x8004A6A0: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x8004A6A4: sw          $v0, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r2;
    // 0x8004A6A8: jal         0x8004B0F4
    // 0x8004A6AC: lw          $a1, 0xF4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XF4);
    func_8004B0F4(rdram, ctx);
        goto after_11;
    // 0x8004A6AC: lw          $a1, 0xF4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XF4);
    after_11:
    // 0x8004A6B0: lwl         $t6, 0xA($v0)
    ctx->r14 = do_lwl(rdram, ctx->r14, ctx->r2, 0XA);
    // 0x8004A6B4: lwr         $t6, 0xD($v0)
    ctx->r14 = do_lwr(rdram, ctx->r14, ctx->r2, 0XD);
    // 0x8004A6B8: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8004A6BC: lw          $v1, 0xE4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XE4);
    // 0x8004A6C0: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8004A6C4: lui         $at, 0x6B61
    ctx->r1 = S32(0X6B61 << 16);
    // 0x8004A6C8: ori         $at, $at, 0x6E00
    ctx->r1 = ctx->r1 | 0X6E00;
    // 0x8004A6CC: lw          $a2, 0xE8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XE8);
    // 0x8004A6D0: lh          $t4, 0xF0($sp)
    ctx->r12 = MEM_H(ctx->r29, 0XF0);
    // 0x8004A6D4: lw          $ra, 0x214($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X214);
    // 0x8004A6D8: bne         $t7, $at, L_8004A6E4
    if (ctx->r15 != ctx->r1) {
        // 0x8004A6DC: lw          $t5, 0x18($v0)
        ctx->r13 = MEM_W(ctx->r2, 0X18);
            goto L_8004A6E4;
    }
    // 0x8004A6DC: lw          $t5, 0x18($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X18);
    // 0x8004A6E0: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8004A6E4:
    // 0x8004A6E4: lh          $t9, 0xB8($sp)
    ctx->r25 = MEM_H(ctx->r29, 0XB8);
    // 0x8004A6E8: beql        $s2, $t9, L_8004A730
    if (ctx->r18 == ctx->r25) {
        // 0x8004A6EC: lw          $t8, 0x104($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X104);
            goto L_8004A730;
    }
    goto skip_1;
    // 0x8004A6EC: lw          $t8, 0x104($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X104);
    skip_1:
    // 0x8004A6F0: beq         $s2, $zero, L_8004A714
    if (ctx->r18 == 0) {
        // 0x8004A6F4: sh          $s2, 0xB8($sp)
        MEM_H(0XB8, ctx->r29) = ctx->r18;
            goto L_8004A714;
    }
    // 0x8004A6F4: sh          $s2, 0xB8($sp)
    MEM_H(0XB8, ctx->r29) = ctx->r18;
    // 0x8004A6F8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8004A6FC: lui         $t8, 0xB700
    ctx->r24 = S32(0XB700 << 16);
    // 0x8004A700: lui         $t6, 0x4
    ctx->r14 = S32(0X4 << 16);
    // 0x8004A704: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8004A708: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8004A70C: b           L_8004A72C
    // 0x8004A710: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
        goto L_8004A72C;
    // 0x8004A710: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
L_8004A714:
    // 0x8004A714: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8004A718: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x8004A71C: lui         $t9, 0x4
    ctx->r25 = S32(0X4 << 16);
    // 0x8004A720: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8004A724: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8004A728: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
L_8004A72C:
    // 0x8004A72C: lw          $t8, 0x104($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X104);
L_8004A730:
    // 0x8004A730: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004A734: bnel        $t8, $at, L_8004A74C
    if (ctx->r24 != ctx->r1) {
        // 0x8004A738: lh          $t7, 0x1E($ra)
        ctx->r15 = MEM_H(ctx->r31, 0X1E);
            goto L_8004A74C;
    }
    goto skip_2;
    // 0x8004A738: lh          $t7, 0x1E($ra)
    ctx->r15 = MEM_H(ctx->r31, 0X1E);
    skip_2:
    // 0x8004A73C: beq         $s2, $zero, L_8004A748
    if (ctx->r18 == 0) {
        // 0x8004A740: addiu       $t6, $zero, -0x1
        ctx->r14 = ADD32(0, -0X1);
            goto L_8004A748;
    }
    // 0x8004A740: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8004A744: sh          $t6, 0x18($ra)
    MEM_H(0X18, ctx->r31) = ctx->r14;
L_8004A748:
    // 0x8004A748: lh          $t7, 0x1E($ra)
    ctx->r15 = MEM_H(ctx->r31, 0X1E);
L_8004A74C:
    // 0x8004A74C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004A750: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    // 0x8004A754: bne         $t7, $at, L_8004A764
    if (ctx->r15 != ctx->r1) {
        // 0x8004A758: nop
    
            goto L_8004A764;
    }
    // 0x8004A758: nop

    // 0x8004A75C: beq         $s2, $zero, L_8004A9C8
    if (ctx->r18 == 0) {
        // 0x8004A760: nop
    
            goto L_8004A9C8;
    }
    // 0x8004A760: nop

L_8004A764:
    // 0x8004A764: beq         $t5, $t9, L_8004A9C8
    if (ctx->r13 == ctx->r25) {
        // 0x8004A768: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8004A9C8;
    }
    // 0x8004A768: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8004A76C: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8004A770: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x8004A774: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8004A778: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8004A77C: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8004A780: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
    // 0x8004A784: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8004A788: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x8004A78C: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8004A790: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x8004A794: lui         $t7, 0xF500
    ctx->r15 = S32(0XF500 << 16);
    // 0x8004A798: ori         $t7, $t7, 0x100
    ctx->r15 = ctx->r15 | 0X100;
    // 0x8004A79C: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8004A7A0: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x8004A7A4: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x8004A7A8: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x8004A7AC: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8004A7B0: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8004A7B4: or          $t1, $a2, $zero
    ctx->r9 = ctx->r6 | 0;
    // 0x8004A7B8: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x8004A7BC: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x8004A7C0: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8004A7C4: lui         $t7, 0x73F
    ctx->r15 = S32(0X73F << 16);
    // 0x8004A7C8: ori         $t7, $t7, 0xC000
    ctx->r15 = ctx->r15 | 0XC000;
    // 0x8004A7CC: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8004A7D0: lui         $t6, 0xF000
    ctx->r14 = S32(0XF000 << 16);
    // 0x8004A7D4: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8004A7D8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8004A7DC: sw          $t7, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r15;
    // 0x8004A7E0: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8004A7E4: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8004A7E8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8004A7EC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8004A7F0: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8004A7F4: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8004A7F8: addiu       $t6, $t5, 0x200
    ctx->r14 = ADD32(ctx->r13, 0X200);
    // 0x8004A7FC: lui         $t8, 0xFD50
    ctx->r24 = S32(0XFD50 << 16);
    // 0x8004A800: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8004A804: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x8004A808: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8004A80C: lui         $t7, 0xF550
    ctx->r15 = S32(0XF550 << 16);
    // 0x8004A810: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8004A814: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x8004A818: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8004A81C: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8004A820: andi        $t8, $t9, 0xF
    ctx->r24 = ctx->r25 & 0XF;
    // 0x8004A824: lh          $t9, 0x4($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X4);
    // 0x8004A828: sll         $t6, $t8, 14
    ctx->r14 = S32(ctx->r24 << 14);
    // 0x8004A82C: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8004A830: andi        $t8, $t9, 0xF
    ctx->r24 = ctx->r25 & 0XF;
    // 0x8004A834: sll         $t6, $t8, 4
    ctx->r14 = S32(ctx->r24 << 4);
    // 0x8004A838: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x8004A83C: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x8004A840: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x8004A844: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8004A848: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x8004A84C: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x8004A850: or          $t3, $a2, $zero
    ctx->r11 = ctx->r6 | 0;
    // 0x8004A854: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8004A858: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x8004A85C: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8004A860: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x8004A864: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x8004A868: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8004A86C: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
    // 0x8004A870: multu       $a0, $t6
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004A874: mflo        $a1
    ctx->r5 = lo;
    // 0x8004A878: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8004A87C: sra         $t9, $a1, 1
    ctx->r25 = S32(SIGNED(ctx->r5) >> 1);
    // 0x8004A880: addiu       $a1, $t9, -0x1
    ctx->r5 = ADD32(ctx->r25, -0X1);
    // 0x8004A884: slti        $at, $a1, 0x7FF
    ctx->r1 = SIGNED(ctx->r5) < 0X7FF ? 1 : 0;
    // 0x8004A888: beq         $at, $zero, L_8004A898
    if (ctx->r1 == 0) {
        // 0x8004A88C: nop
    
            goto L_8004A898;
    }
    // 0x8004A88C: nop

    // 0x8004A890: b           L_8004A898
    // 0x8004A894: or          $t1, $a1, $zero
    ctx->r9 = ctx->r5 | 0;
        goto L_8004A898;
    // 0x8004A894: or          $t1, $a1, $zero
    ctx->r9 = ctx->r5 | 0;
L_8004A898:
    // 0x8004A898: bgez        $a0, L_8004A8A8
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8004A89C: sra         $a1, $a0, 3
        ctx->r5 = S32(SIGNED(ctx->r4) >> 3);
            goto L_8004A8A8;
    }
    // 0x8004A89C: sra         $a1, $a0, 3
    ctx->r5 = S32(SIGNED(ctx->r4) >> 3);
    // 0x8004A8A0: addiu       $at, $a0, 0x7
    ctx->r1 = ADD32(ctx->r4, 0X7);
    // 0x8004A8A4: sra         $a1, $at, 3
    ctx->r5 = S32(SIGNED(ctx->r1) >> 3);
L_8004A8A8:
    // 0x8004A8A8: bgtz        $a1, L_8004A8B8
    if (SIGNED(ctx->r5) > 0) {
        // 0x8004A8AC: or          $t2, $a1, $zero
        ctx->r10 = ctx->r5 | 0;
            goto L_8004A8B8;
    }
    // 0x8004A8AC: or          $t2, $a1, $zero
    ctx->r10 = ctx->r5 | 0;
    // 0x8004A8B0: b           L_8004A8B8
    // 0x8004A8B4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_8004A8B8;
    // 0x8004A8B4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8004A8B8:
    // 0x8004A8B8: bgtz        $a1, L_8004A8C8
    if (SIGNED(ctx->r5) > 0) {
        // 0x8004A8BC: addiu       $t8, $t2, 0x7FF
        ctx->r24 = ADD32(ctx->r10, 0X7FF);
            goto L_8004A8C8;
    }
    // 0x8004A8BC: addiu       $t8, $t2, 0x7FF
    ctx->r24 = ADD32(ctx->r10, 0X7FF);
    // 0x8004A8C0: b           L_8004A8CC
    // 0x8004A8C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_8004A8CC;
    // 0x8004A8C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8004A8C8:
    // 0x8004A8C8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_8004A8CC:
    // 0x8004A8CC: div         $zero, $t8, $a0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r4)));
    // 0x8004A8D0: bne         $a0, $zero, L_8004A8DC
    if (ctx->r4 != 0) {
        // 0x8004A8D4: nop
    
            goto L_8004A8DC;
    }
    // 0x8004A8D4: nop

    // 0x8004A8D8: break       7
    do_break(2147789016);
L_8004A8DC:
    // 0x8004A8DC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004A8E0: bne         $a0, $at, L_8004A8F4
    if (ctx->r4 != ctx->r1) {
        // 0x8004A8E4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8004A8F4;
    }
    // 0x8004A8E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8004A8E8: bne         $t8, $at, L_8004A8F4
    if (ctx->r24 != ctx->r1) {
        // 0x8004A8EC: nop
    
            goto L_8004A8F4;
    }
    // 0x8004A8EC: nop

    // 0x8004A8F0: break       6
    do_break(2147789040);
L_8004A8F4:
    // 0x8004A8F4: mflo        $t7
    ctx->r15 = lo;
    // 0x8004A8F8: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8004A8FC: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8004A900: andi        $t8, $t1, 0xFFF
    ctx->r24 = ctx->r9 & 0XFFF;
    // 0x8004A904: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x8004A908: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x8004A90C: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x8004A910: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x8004A914: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8004A918: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8004A91C: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8004A920: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x8004A924: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x8004A928: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8004A92C: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8004A930: addiu       $t7, $t9, 0x7
    ctx->r15 = ADD32(ctx->r25, 0X7);
    // 0x8004A934: sra         $t6, $t7, 3
    ctx->r14 = S32(SIGNED(ctx->r15) >> 3);
    // 0x8004A938: andi        $t8, $t6, 0x1FF
    ctx->r24 = ctx->r14 & 0X1FF;
    // 0x8004A93C: sll         $t9, $t8, 9
    ctx->r25 = S32(ctx->r24 << 9);
    // 0x8004A940: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x8004A944: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8004A948: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8004A94C: lh          $t6, 0x6($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X6);
    // 0x8004A950: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x8004A954: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8004A958: andi        $t8, $t6, 0xF
    ctx->r24 = ctx->r14 & 0XF;
    // 0x8004A95C: sll         $t9, $t8, 14
    ctx->r25 = S32(ctx->r24 << 14);
    // 0x8004A960: andi        $t6, $t7, 0xF
    ctx->r14 = ctx->r15 & 0XF;
    // 0x8004A964: sll         $t8, $t6, 4
    ctx->r24 = S32(ctx->r14 << 4);
    // 0x8004A968: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x8004A96C: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x8004A970: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x8004A974: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x8004A978: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x8004A97C: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x8004A980: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8004A984: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x8004A988: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8004A98C: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x8004A990: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8004A994: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x8004A998: addiu       $t7, $t8, -0x1
    ctx->r15 = ADD32(ctx->r24, -0X1);
    // 0x8004A99C: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8004A9A0: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x8004A9A4: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x8004A9A8: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x8004A9AC: lh          $t6, 0xE($ra)
    ctx->r14 = MEM_H(ctx->r31, 0XE);
    // 0x8004A9B0: andi        $t9, $t6, 0x2
    ctx->r25 = ctx->r14 & 0X2;
    // 0x8004A9B4: beql        $t9, $zero, L_8004A9C8
    if (ctx->r25 == 0) {
        // 0x8004A9B8: sw          $t5, 0xBC($sp)
        MEM_W(0XBC, ctx->r29) = ctx->r13;
            goto L_8004A9C8;
    }
    goto skip_3;
    // 0x8004A9B8: sw          $t5, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r13;
    skip_3:
    // 0x8004A9BC: b           L_8004A9C8
    // 0x8004A9C0: sw          $zero, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = 0;
        goto L_8004A9C8;
    // 0x8004A9C0: sw          $zero, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = 0;
    // 0x8004A9C4: sw          $t5, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r13;
L_8004A9C8:
    // 0x8004A9C8: blez        $t4, L_8004AC94
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8004A9CC: nop
    
            goto L_8004AC94;
    }
    // 0x8004A9CC: nop

    // 0x8004A9D0: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
L_8004A9D4:
    // 0x8004A9D4: lh          $a3, 0x2($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X2);
    // 0x8004A9D8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8004A9DC: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x8004A9E0: blez        $a1, L_8004ABD0
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8004A9E4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8004ABD0;
    }
    // 0x8004A9E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8004A9E8: andi        $v0, $a1, 0x1
    ctx->r2 = ctx->r5 & 0X1;
    // 0x8004A9EC: beql        $v0, $zero, L_8004AA98
    if (ctx->r2 == 0) {
        // 0x8004A9F0: lh          $t8, 0x0($s0)
        ctx->r24 = MEM_H(ctx->r16, 0X0);
            goto L_8004AA98;
    }
    goto skip_4;
    // 0x8004A9F0: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    skip_4:
    // 0x8004A9F4: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x8004A9F8: addiu       $s0, $s0, 0xA
    ctx->r16 = ADD32(ctx->r16, 0XA);
    // 0x8004A9FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8004AA00: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x8004AA04: lh          $t7, -0x8($s0)
    ctx->r15 = MEM_H(ctx->r16, -0X8);
    // 0x8004AA08: sh          $t7, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r15;
    // 0x8004AA0C: lh          $t6, -0x6($s0)
    ctx->r14 = MEM_H(ctx->r16, -0X6);
    // 0x8004AA10: sh          $t6, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r14;
    // 0x8004AA14: lh          $t9, -0x4($s0)
    ctx->r25 = MEM_H(ctx->r16, -0X4);
    // 0x8004AA18: sh          $t9, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r25;
    // 0x8004AA1C: lh          $t8, -0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, -0X2);
    // 0x8004AA20: beq         $s2, $zero, L_8004AA54
    if (ctx->r18 == 0) {
        // 0x8004AA24: sh          $t8, 0xA($v1)
        MEM_H(0XA, ctx->r3) = ctx->r24;
            goto L_8004AA54;
    }
    // 0x8004AA24: sh          $t8, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r24;
    // 0x8004AA28: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x8004AA2C: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    // 0x8004AA30: sra         $t6, $t7, 3
    ctx->r14 = S32(SIGNED(ctx->r15) >> 3);
    // 0x8004AA34: sb          $t6, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r14;
    // 0x8004AA38: lh          $t9, -0x4($s0)
    ctx->r25 = MEM_H(ctx->r16, -0X4);
    // 0x8004AA3C: sra         $t8, $t9, 3
    ctx->r24 = S32(SIGNED(ctx->r25) >> 3);
    // 0x8004AA40: sb          $t8, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r24;
    // 0x8004AA44: lh          $t7, -0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, -0X2);
    // 0x8004AA48: sra         $t6, $t7, 3
    ctx->r14 = S32(SIGNED(ctx->r15) >> 3);
    // 0x8004AA4C: b           L_8004AA70
    // 0x8004AA50: sb          $t6, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r14;
        goto L_8004AA70;
    // 0x8004AA50: sb          $t6, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r14;
L_8004AA54:
    // 0x8004AA54: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x8004AA58: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    // 0x8004AA5C: sb          $t9, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r25;
    // 0x8004AA60: lh          $t8, -0x4($s0)
    ctx->r24 = MEM_H(ctx->r16, -0X4);
    // 0x8004AA64: sb          $t8, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r24;
    // 0x8004AA68: lh          $t7, -0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, -0X2);
    // 0x8004AA6C: sb          $t7, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r15;
L_8004AA70:
    // 0x8004AA70: beq         $s1, $zero, L_8004AA88
    if (ctx->r17 == 0) {
        // 0x8004AA74: sh          $zero, 0x6($v1)
        MEM_H(0X6, ctx->r3) = 0;
            goto L_8004AA88;
    }
    // 0x8004AA74: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x8004AA78: addu        $t6, $s1, $s3
    ctx->r14 = ADD32(ctx->r17, ctx->r19);
    // 0x8004AA7C: lbu         $t9, 0x0($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X0);
    // 0x8004AA80: b           L_8004AA8C
    // 0x8004AA84: sb          $t9, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r25;
        goto L_8004AA8C;
    // 0x8004AA84: sb          $t9, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r25;
L_8004AA88:
    // 0x8004AA88: sb          $s4, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r20;
L_8004AA8C:
    // 0x8004AA8C: beq         $a0, $a1, L_8004ABCC
    if (ctx->r4 == ctx->r5) {
        // 0x8004AA90: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_8004ABCC;
    }
    // 0x8004AA90: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_8004AA94:
    // 0x8004AA94: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
L_8004AA98:
    // 0x8004AA98: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8004AA9C: addiu       $s0, $s0, 0xA
    ctx->r16 = ADD32(ctx->r16, 0XA);
    // 0x8004AAA0: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x8004AAA4: lh          $t7, -0x8($s0)
    ctx->r15 = MEM_H(ctx->r16, -0X8);
    // 0x8004AAA8: sh          $t7, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r15;
    // 0x8004AAAC: lh          $t6, -0x6($s0)
    ctx->r14 = MEM_H(ctx->r16, -0X6);
    // 0x8004AAB0: sh          $t6, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r14;
    // 0x8004AAB4: lh          $t9, -0x4($s0)
    ctx->r25 = MEM_H(ctx->r16, -0X4);
    // 0x8004AAB8: sh          $t9, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r25;
    // 0x8004AABC: lh          $t8, -0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, -0X2);
    // 0x8004AAC0: beq         $s2, $zero, L_8004AAF4
    if (ctx->r18 == 0) {
        // 0x8004AAC4: sh          $t8, 0xA($v1)
        MEM_H(0XA, ctx->r3) = ctx->r24;
            goto L_8004AAF4;
    }
    // 0x8004AAC4: sh          $t8, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r24;
    // 0x8004AAC8: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x8004AACC: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    // 0x8004AAD0: sra         $t6, $t7, 3
    ctx->r14 = S32(SIGNED(ctx->r15) >> 3);
    // 0x8004AAD4: sb          $t6, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r14;
    // 0x8004AAD8: lh          $t9, -0x4($s0)
    ctx->r25 = MEM_H(ctx->r16, -0X4);
    // 0x8004AADC: sra         $t8, $t9, 3
    ctx->r24 = S32(SIGNED(ctx->r25) >> 3);
    // 0x8004AAE0: sb          $t8, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r24;
    // 0x8004AAE4: lh          $t7, -0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, -0X2);
    // 0x8004AAE8: sra         $t6, $t7, 3
    ctx->r14 = S32(SIGNED(ctx->r15) >> 3);
    // 0x8004AAEC: b           L_8004AB10
    // 0x8004AAF0: sb          $t6, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r14;
        goto L_8004AB10;
    // 0x8004AAF0: sb          $t6, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r14;
L_8004AAF4:
    // 0x8004AAF4: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x8004AAF8: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    // 0x8004AAFC: sb          $t9, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r25;
    // 0x8004AB00: lh          $t8, -0x4($s0)
    ctx->r24 = MEM_H(ctx->r16, -0X4);
    // 0x8004AB04: sb          $t8, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r24;
    // 0x8004AB08: lh          $t7, -0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, -0X2);
    // 0x8004AB0C: sb          $t7, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r15;
L_8004AB10:
    // 0x8004AB10: beq         $s1, $zero, L_8004AB28
    if (ctx->r17 == 0) {
        // 0x8004AB14: sh          $zero, 0x6($v1)
        MEM_H(0X6, ctx->r3) = 0;
            goto L_8004AB28;
    }
    // 0x8004AB14: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x8004AB18: addu        $t6, $s1, $s3
    ctx->r14 = ADD32(ctx->r17, ctx->r19);
    // 0x8004AB1C: lbu         $t9, 0x0($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X0);
    // 0x8004AB20: b           L_8004AB2C
    // 0x8004AB24: sb          $t9, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r25;
        goto L_8004AB2C;
    // 0x8004AB24: sb          $t9, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r25;
L_8004AB28:
    // 0x8004AB28: sb          $s4, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r20;
L_8004AB2C:
    // 0x8004AB2C: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x8004AB30: addiu       $s0, $s0, 0xA
    ctx->r16 = ADD32(ctx->r16, 0XA);
    // 0x8004AB34: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8004AB38: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x8004AB3C: lh          $t7, -0x8($s0)
    ctx->r15 = MEM_H(ctx->r16, -0X8);
    // 0x8004AB40: sh          $t7, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r15;
    // 0x8004AB44: lh          $t6, -0x6($s0)
    ctx->r14 = MEM_H(ctx->r16, -0X6);
    // 0x8004AB48: sh          $t6, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r14;
    // 0x8004AB4C: lh          $t9, -0x4($s0)
    ctx->r25 = MEM_H(ctx->r16, -0X4);
    // 0x8004AB50: sh          $t9, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r25;
    // 0x8004AB54: lh          $t8, -0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, -0X2);
    // 0x8004AB58: beq         $s2, $zero, L_8004AB8C
    if (ctx->r18 == 0) {
        // 0x8004AB5C: sh          $t8, 0xA($v1)
        MEM_H(0XA, ctx->r3) = ctx->r24;
            goto L_8004AB8C;
    }
    // 0x8004AB5C: sh          $t8, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r24;
    // 0x8004AB60: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x8004AB64: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    // 0x8004AB68: sra         $t6, $t7, 3
    ctx->r14 = S32(SIGNED(ctx->r15) >> 3);
    // 0x8004AB6C: sb          $t6, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r14;
    // 0x8004AB70: lh          $t9, -0x4($s0)
    ctx->r25 = MEM_H(ctx->r16, -0X4);
    // 0x8004AB74: sra         $t8, $t9, 3
    ctx->r24 = S32(SIGNED(ctx->r25) >> 3);
    // 0x8004AB78: sb          $t8, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r24;
    // 0x8004AB7C: lh          $t7, -0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, -0X2);
    // 0x8004AB80: sra         $t6, $t7, 3
    ctx->r14 = S32(SIGNED(ctx->r15) >> 3);
    // 0x8004AB84: b           L_8004ABA8
    // 0x8004AB88: sb          $t6, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r14;
        goto L_8004ABA8;
    // 0x8004AB88: sb          $t6, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r14;
L_8004AB8C:
    // 0x8004AB8C: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x8004AB90: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    // 0x8004AB94: sb          $t9, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r25;
    // 0x8004AB98: lh          $t8, -0x4($s0)
    ctx->r24 = MEM_H(ctx->r16, -0X4);
    // 0x8004AB9C: sb          $t8, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r24;
    // 0x8004ABA0: lh          $t7, -0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, -0X2);
    // 0x8004ABA4: sb          $t7, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r15;
L_8004ABA8:
    // 0x8004ABA8: beq         $s1, $zero, L_8004ABC0
    if (ctx->r17 == 0) {
        // 0x8004ABAC: sh          $zero, 0x6($v1)
        MEM_H(0X6, ctx->r3) = 0;
            goto L_8004ABC0;
    }
    // 0x8004ABAC: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x8004ABB0: addu        $t6, $s1, $s3
    ctx->r14 = ADD32(ctx->r17, ctx->r19);
    // 0x8004ABB4: lbu         $t9, 0x0($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X0);
    // 0x8004ABB8: b           L_8004ABC4
    // 0x8004ABBC: sb          $t9, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r25;
        goto L_8004ABC4;
    // 0x8004ABBC: sb          $t9, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r25;
L_8004ABC0:
    // 0x8004ABC0: sb          $s4, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r20;
L_8004ABC4:
    // 0x8004ABC4: bne         $a0, $a1, L_8004AA94
    if (ctx->r4 != ctx->r5) {
        // 0x8004ABC8: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_8004AA94;
    }
    // 0x8004ABC8: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_8004ABCC:
    // 0x8004ABCC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8004ABD0:
    // 0x8004ABD0: addiu       $t8, $a1, -0x1
    ctx->r24 = ADD32(ctx->r5, -0X1);
    // 0x8004ABD4: sll         $t7, $t8, 4
    ctx->r15 = S32(ctx->r24 << 4);
    // 0x8004ABD8: andi        $t6, $t7, 0xFF
    ctx->r14 = ctx->r15 & 0XFF;
    // 0x8004ABDC: sll         $t9, $t6, 16
    ctx->r25 = S32(ctx->r14 << 16);
    // 0x8004ABE0: sll         $t7, $a1, 4
    ctx->r15 = S32(ctx->r5 << 4);
    // 0x8004ABE4: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8004ABE8: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x8004ABEC: andi        $t6, $t7, 0xFFFF
    ctx->r14 = ctx->r15 & 0XFFFF;
    // 0x8004ABF0: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8004ABF4: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x8004ABF8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8004ABFC: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8004AC00: blez        $a3, L_8004AC88
    if (SIGNED(ctx->r7) <= 0) {
        // 0x8004AC04: addiu       $a2, $a2, 0x8
        ctx->r6 = ADD32(ctx->r6, 0X8);
            goto L_8004AC88;
    }
    // 0x8004AC04: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
L_8004AC08:
    // 0x8004AC08: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    // 0x8004AC0C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8004AC10: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8004AC14: sb          $t7, 0xC8($sp)
    MEM_B(0XC8, ctx->r29) = ctx->r15;
    // 0x8004AC18: lbu         $t8, 0x1($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1);
    // 0x8004AC1C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8004AC20: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8004AC24: sb          $t8, 0xC9($sp)
    MEM_B(0XC9, ctx->r29) = ctx->r24;
    // 0x8004AC28: lbu         $t6, -0x2($s0)
    ctx->r14 = MEM_BU(ctx->r16, -0X2);
    // 0x8004AC2C: sb          $t6, 0xCA($sp)
    MEM_B(0XCA, ctx->r29) = ctx->r14;
    // 0x8004AC30: lbu         $t9, -0x1($s0)
    ctx->r25 = MEM_BU(ctx->r16, -0X1);
    // 0x8004AC34: sb          $t9, 0xCB($sp)
    MEM_B(0XCB, ctx->r29) = ctx->r25;
    // 0x8004AC38: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x8004AC3C: lbu         $t7, 0xCA($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XCA);
    // 0x8004AC40: lbu         $t9, 0xC8($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0XC8);
    // 0x8004AC44: multu       $t7, $s5
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004AC48: mflo        $t8
    ctx->r24 = lo;
    // 0x8004AC4C: andi        $t6, $t8, 0xFF
    ctx->r14 = ctx->r24 & 0XFF;
    // 0x8004AC50: nop

    // 0x8004AC54: multu       $t9, $s5
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004AC58: mflo        $t7
    ctx->r15 = lo;
    // 0x8004AC5C: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8004AC60: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8004AC64: lbu         $t8, 0xC9($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XC9);
    // 0x8004AC68: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x8004AC6C: multu       $t8, $s5
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004AC70: mflo        $t6
    ctx->r14 = lo;
    // 0x8004AC74: andi        $t9, $t6, 0xFF
    ctx->r25 = ctx->r14 & 0XFF;
    // 0x8004AC78: sll         $t8, $t9, 8
    ctx->r24 = S32(ctx->r25 << 8);
    // 0x8004AC7C: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x8004AC80: bne         $a0, $a3, L_8004AC08
    if (ctx->r4 != ctx->r7) {
        // 0x8004AC84: sw          $t6, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r14;
            goto L_8004AC08;
    }
    // 0x8004AC84: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_8004AC88:
    // 0x8004AC88: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8004AC8C: bnel        $s7, $t4, L_8004A9D4
    if (ctx->r23 != ctx->r12) {
        // 0x8004AC90: lh          $a1, 0x0($s0)
        ctx->r5 = MEM_H(ctx->r16, 0X0);
            goto L_8004A9D4;
    }
    goto skip_5;
    // 0x8004AC90: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    skip_5:
L_8004AC94:
    // 0x8004AC94: beq         $s2, $zero, L_8004ACB4
    if (ctx->r18 == 0) {
        // 0x8004AC98: lui         $t8, 0xB800
        ctx->r24 = S32(0XB800 << 16);
            goto L_8004ACB4;
    }
    // 0x8004AC98: lui         $t8, 0xB800
    ctx->r24 = S32(0XB800 << 16);
    // 0x8004AC9C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8004ACA0: lui         $t9, 0xB600
    ctx->r25 = S32(0XB600 << 16);
    // 0x8004ACA4: lui         $t7, 0x4
    ctx->r15 = S32(0X4 << 16);
    // 0x8004ACA8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8004ACAC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8004ACB0: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
L_8004ACB4:
    // 0x8004ACB4: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8004ACB8: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x8004ACBC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8004ACC0: addiu       $s2, $sp, 0x110
    ctx->r18 = ADD32(ctx->r29, 0X110);
L_8004ACC4:
    // 0x8004ACC4: sw          $ra, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r31;
L_8004ACC8:
    // 0x8004ACC8: jal         0x800051C4
    // 0x8004ACCC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800051C4(rdram, ctx);
        goto after_12;
    // 0x8004ACCC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_12:
    // 0x8004ACD0: lw          $t6, 0x110($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X110);
    // 0x8004ACD4: lw          $ra, 0x214($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X214);
    // 0x8004ACD8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8004ACDC: sll         $t9, $t6, 4
    ctx->r25 = S32(ctx->r14 << 4);
    // 0x8004ACE0: addu        $t7, $s2, $t9
    ctx->r15 = ADD32(ctx->r18, ctx->r25);
    // 0x8004ACE4: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x8004ACE8: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8004ACEC: bnel        $at, $zero, L_8004A450
    if (ctx->r1 != 0) {
        // 0x8004ACF0: sw          $ra, 0x214($sp)
        MEM_W(0X214, ctx->r29) = ctx->r31;
            goto L_8004A450;
    }
    goto skip_6;
    // 0x8004ACF0: sw          $ra, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r31;
    skip_6:
    // 0x8004ACF4: sw          $s3, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r19;
    // 0x8004ACF8: sw          $s1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r17;
L_8004ACFC:
    // 0x8004ACFC: sw          $ra, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r31;
    // 0x8004AD00: jal         0x800051C4
    // 0x8004AD04: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800051C4(rdram, ctx);
        goto after_13;
    // 0x8004AD04: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_13:
    // 0x8004AD08: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8004AD0C: lw          $v0, 0x214($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X214);
    // 0x8004AD10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004AD14: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8004AD18: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8004AD1C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8004AD20: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8004AD24: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8004AD28: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8004AD2C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8004AD30: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8004AD34: jr          $ra
    // 0x8004AD38: addiu       $sp, $sp, 0x218
    ctx->r29 = ADD32(ctx->r29, 0X218);
    TRACE_RETURN()
    return;
    // 0x8004AD38: addiu       $sp, $sp, 0x218
    ctx->r29 = ADD32(ctx->r29, 0X218);
    // 0x8004AD3C: nop

    // 0x8004AD40: jr          $ra
    // 0x8004AD44: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    TRACE_RETURN()
    return;
    // 0x8004AD44: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8004AD48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004AD48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004AD4C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004AD50: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004AD54: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004AD58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004AD5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8004AD60: sw          $zero, -0x6050($at)
    MEM_W(-0X6050, ctx->r1) = 0;
    // 0x8004AD64: addiu       $v1, $v1, -0x4A68
    ctx->r3 = ADD32(ctx->r3, -0X4A68);
    // 0x8004AD68: addiu       $v0, $v0, -0x6048
    ctx->r2 = ADD32(ctx->r2, -0X6048);
L_8004AD6C:
    // 0x8004AD6C: addiu       $v0, $v0, 0x70
    ctx->r2 = ADD32(ctx->r2, 0X70);
    // 0x8004AD70: sw          $zero, -0x3C($v0)
    MEM_W(-0X3C, ctx->r2) = 0;
    // 0x8004AD74: sw          $zero, -0x20($v0)
    MEM_W(-0X20, ctx->r2) = 0;
    // 0x8004AD78: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x8004AD7C: bne         $v0, $v1, L_8004AD6C
    if (ctx->r2 != ctx->r3) {
        // 0x8004AD80: sw          $zero, -0x58($v0)
        MEM_W(-0X58, ctx->r2) = 0;
            goto L_8004AD6C;
    }
    // 0x8004AD80: sw          $zero, -0x58($v0)
    MEM_W(-0X58, ctx->r2) = 0;
    // 0x8004AD84: lh          $t6, 0x1A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1A);
    // 0x8004AD88: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x8004AD8C: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8004AD90: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8004AD94: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8004AD98: lw          $v0, 0x1C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1C0);
    // 0x8004AD9C: addiu       $a2, $a2, -0x7010
    ctx->r6 = ADD32(ctx->r6, -0X7010);
    // 0x8004ADA0: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x8004ADA4: lh          $a1, 0x2($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X2);
    // 0x8004ADA8: jal         0x8004B010
    // 0x8004ADAC: addiu       $a3, $v0, 0x10
    ctx->r7 = ADD32(ctx->r2, 0X10);
    func_8004B010(rdram, ctx);
        goto after_0;
    // 0x8004ADAC: addiu       $a3, $v0, 0x10
    ctx->r7 = ADD32(ctx->r2, 0X10);
    after_0:
    // 0x8004ADB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004ADB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004ADB8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8004ADC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004ADC0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004ADC4: lw          $v0, -0x6050($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6050);
    // 0x8004ADC8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004ADCC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8004ADD0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8004ADD4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8004ADD8: beq         $v0, $zero, L_8004AE24
    if (ctx->r2 == 0) {
        // 0x8004ADDC: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8004AE24;
    }
    // 0x8004ADDC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004ADE0: blez        $v0, L_8004AE24
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004ADE4: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8004AE24;
    }
    // 0x8004ADE4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8004ADE8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8004ADEC: lui         $s2, 0x801A
    ctx->r18 = S32(0X801A << 16);
    // 0x8004ADF0: addiu       $s2, $s2, 0x2800
    ctx->r18 = ADD32(ctx->r18, 0X2800);
    // 0x8004ADF4: addiu       $s0, $s0, -0x6048
    ctx->r16 = ADD32(ctx->r16, -0X6048);
L_8004ADF8:
    // 0x8004ADF8: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    // 0x8004ADFC: beql        $a1, $zero, L_8004AE18
    if (ctx->r5 == 0) {
        // 0x8004AE00: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8004AE18;
    }
    goto skip_0;
    // 0x8004AE00: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x8004AE04: jal         0x800042A8
    // 0x8004AE08: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800042A8(rdram, ctx);
        goto after_0;
    // 0x8004AE08: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x8004AE0C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004AE10: lw          $v0, -0x6050($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6050);
    // 0x8004AE14: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8004AE18:
    // 0x8004AE18: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8004AE1C: bne         $at, $zero, L_8004ADF8
    if (ctx->r1 != 0) {
        // 0x8004AE20: addiu       $s0, $s0, 0x1C
        ctx->r16 = ADD32(ctx->r16, 0X1C);
            goto L_8004ADF8;
    }
    // 0x8004AE20: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
L_8004AE24:
    // 0x8004AE24: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8004AE28: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004AE2C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8004AE30: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8004AE34: jr          $ra
    // 0x8004AE38: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    TRACE_RETURN()
    return;
    // 0x8004AE38: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8004AE3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004AE3C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8004AE40: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x8004AE44: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8004AE48: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8004AE4C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8004AE50: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8004AE54: addiu       $t7, $t7, -0x6048
    ctx->r15 = ADD32(ctx->r15, -0X6048);
    // 0x8004AE58: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8004AE5C: lh          $t8, 0x36($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X36);
    // 0x8004AE60: lh          $t9, 0x3A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X3A);
    // 0x8004AE64: addu        $t1, $t6, $t7
    ctx->r9 = ADD32(ctx->r14, ctx->r15);
    // 0x8004AE68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004AE6C: addiu       $v0, $t1, 0x8
    ctx->r2 = ADD32(ctx->r9, 0X8);
    // 0x8004AE70: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8004AE74: sh          $t8, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r24;
    // 0x8004AE78: sh          $t9, 0x2($t1)
    MEM_H(0X2, ctx->r9) = ctx->r25;
L_8004AE7C:
    // 0x8004AE7C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8004AE80: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x8004AE84: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8004AE88: bne         $at, $zero, L_8004AE7C
    if (ctx->r1 != 0) {
        // 0x8004AE8C: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8004AE7C;
    }
    // 0x8004AE8C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8004AE90: sll         $t3, $a0, 3
    ctx->r11 = S32(ctx->r4 << 3);
    // 0x8004AE94: subu        $t3, $t3, $a0
    ctx->r11 = SUB32(ctx->r11, ctx->r4);
    // 0x8004AE98: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x8004AE9C: addiu       $t4, $t4, -0x6048
    ctx->r12 = ADD32(ctx->r12, -0X6048);
    // 0x8004AEA0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8004AEA4: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
    // 0x8004AEA8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8004AEAC: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_8004AEB0:
    // 0x8004AEB0: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    // 0x8004AEB4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8004AEB8: slti        $at, $t0, 0x10
    ctx->r1 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // 0x8004AEBC: sb          $t5, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r13;
    // 0x8004AEC0: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8004AEC4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8004AEC8: bne         $t6, $zero, L_8004AED8
    if (ctx->r14 != 0) {
        // 0x8004AECC: nop
    
            goto L_8004AED8;
    }
    // 0x8004AECC: nop

    // 0x8004AED0: b           L_8004AEE4
    // 0x8004AED4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
        goto L_8004AEE4;
    // 0x8004AED4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8004AED8:
    // 0x8004AED8: bne         $at, $zero, L_8004AEB0
    if (ctx->r1 != 0) {
        // 0x8004AEDC: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8004AEB0;
    }
    // 0x8004AEDC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004AEE0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8004AEE4:
    // 0x8004AEE4: lh          $t7, 0x36($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X36);
    // 0x8004AEE8: lh          $t8, 0x3A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X3A);
    // 0x8004AEEC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004AEF0: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8004AEF4: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004AEF8: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8004AEFC: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8004AF00: mflo        $a3
    ctx->r7 = lo;
    // 0x8004AF04: sll         $a1, $a3, 1
    ctx->r5 = S32(ctx->r7 << 1);
    // 0x8004AF08: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8004AF0C: jal         0x80004364
    // 0x8004AF10: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x8004AF10: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x8004AF14: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8004AF18: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8004AF1C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8004AF20: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8004AF24: blez        $a3, L_8004AFCC
    if (SIGNED(ctx->r7) <= 0) {
        // 0x8004AF28: sw          $v0, 0x18($t1)
        MEM_W(0X18, ctx->r9) = ctx->r2;
            goto L_8004AFCC;
    }
    // 0x8004AF28: sw          $v0, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->r2;
    // 0x8004AF2C: andi        $a1, $a3, 0x3
    ctx->r5 = ctx->r7 & 0X3;
    // 0x8004AF30: beq         $a1, $zero, L_8004AF6C
    if (ctx->r5 == 0) {
        // 0x8004AF34: lw          $t2, 0x40($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X40);
            goto L_8004AF6C;
    }
    // 0x8004AF34: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8004AF38: sll         $v1, $t0, 1
    ctx->r3 = S32(ctx->r8 << 1);
    // 0x8004AF3C: addu        $v0, $t2, $v1
    ctx->r2 = ADD32(ctx->r10, ctx->r3);
    // 0x8004AF40: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_8004AF44:
    // 0x8004AF44: lw          $t3, 0x18($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X18);
    // 0x8004AF48: lhu         $t9, 0x0($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X0);
    // 0x8004AF4C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8004AF50: addu        $t4, $t3, $v1
    ctx->r12 = ADD32(ctx->r11, ctx->r3);
    // 0x8004AF54: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8004AF58: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8004AF5C: bne         $a0, $t0, L_8004AF44
    if (ctx->r4 != ctx->r8) {
        // 0x8004AF60: sh          $t9, 0x0($t4)
        MEM_H(0X0, ctx->r12) = ctx->r25;
            goto L_8004AF44;
    }
    // 0x8004AF60: sh          $t9, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r25;
    // 0x8004AF64: beql        $t0, $a3, L_8004AFD0
    if (ctx->r8 == ctx->r7) {
        // 0x8004AF68: lh          $a0, 0x36($sp)
        ctx->r4 = MEM_H(ctx->r29, 0X36);
            goto L_8004AFD0;
    }
    goto skip_0;
    // 0x8004AF68: lh          $a0, 0x36($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X36);
    skip_0:
L_8004AF6C:
    // 0x8004AF6C: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8004AF70: sll         $v1, $t0, 1
    ctx->r3 = S32(ctx->r8 << 1);
    // 0x8004AF74: sll         $t5, $a2, 1
    ctx->r13 = S32(ctx->r6 << 1);
    // 0x8004AF78: addu        $a0, $t5, $t2
    ctx->r4 = ADD32(ctx->r13, ctx->r10);
    // 0x8004AF7C: addu        $v0, $t2, $v1
    ctx->r2 = ADD32(ctx->r10, ctx->r3);
L_8004AF80:
    // 0x8004AF80: lw          $t7, 0x18($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X18);
    // 0x8004AF84: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x8004AF88: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8004AF8C: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8004AF90: sh          $t6, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r14;
    // 0x8004AF94: lw          $t9, 0x18($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X18);
    // 0x8004AF98: lhu         $t3, -0x6($v0)
    ctx->r11 = MEM_HU(ctx->r2, -0X6);
    // 0x8004AF9C: addu        $t4, $t9, $v1
    ctx->r12 = ADD32(ctx->r25, ctx->r3);
    // 0x8004AFA0: sh          $t3, 0x2($t4)
    MEM_H(0X2, ctx->r12) = ctx->r11;
    // 0x8004AFA4: lw          $t7, 0x18($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X18);
    // 0x8004AFA8: lhu         $t5, -0x4($v0)
    ctx->r13 = MEM_HU(ctx->r2, -0X4);
    // 0x8004AFAC: addu        $t6, $t7, $v1
    ctx->r14 = ADD32(ctx->r15, ctx->r3);
    // 0x8004AFB0: sh          $t5, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r13;
    // 0x8004AFB4: lw          $t9, 0x18($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X18);
    // 0x8004AFB8: lhu         $t8, -0x2($v0)
    ctx->r24 = MEM_HU(ctx->r2, -0X2);
    // 0x8004AFBC: addu        $t3, $t9, $v1
    ctx->r11 = ADD32(ctx->r25, ctx->r3);
    // 0x8004AFC0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8004AFC4: bne         $v0, $a0, L_8004AF80
    if (ctx->r2 != ctx->r4) {
        // 0x8004AFC8: sh          $t8, 0x6($t3)
        MEM_H(0X6, ctx->r11) = ctx->r24;
            goto L_8004AF80;
    }
    // 0x8004AFC8: sh          $t8, 0x6($t3)
    MEM_H(0X6, ctx->r11) = ctx->r24;
L_8004AFCC:
    // 0x8004AFCC: lh          $a0, 0x36($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X36);
L_8004AFD0:
    // 0x8004AFD0: jal         0x80005400
    // 0x8004AFD4: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    func_80005400(rdram, ctx);
        goto after_1;
    // 0x8004AFD4: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    after_1:
    // 0x8004AFD8: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8004AFDC: lh          $a0, 0x3A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X3A);
    // 0x8004AFE0: jal         0x80005400
    // 0x8004AFE4: sh          $v0, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r2;
    func_80005400(rdram, ctx);
        goto after_2;
    // 0x8004AFE4: sh          $v0, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r2;
    after_2:
    // 0x8004AFE8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004AFEC: addiu       $v1, $v1, -0x6050
    ctx->r3 = ADD32(ctx->r3, -0X6050);
    // 0x8004AFF0: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8004AFF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004AFF8: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8004AFFC: addiu       $t7, $t4, 0x1
    ctx->r15 = ADD32(ctx->r12, 0X1);
    // 0x8004B000: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8004B004: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8004B008: jr          $ra
    // 0x8004B00C: sh          $v0, 0x6($t1)
    MEM_H(0X6, ctx->r9) = ctx->r2;
    TRACE_RETURN()
    return;
    // 0x8004B00C: sh          $v0, 0x6($t1)
    MEM_H(0X6, ctx->r9) = ctx->r2;
;}
RECOMP_FUNC void func_8004B010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004B010: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8004B014: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004B018: lw          $v0, -0x6050($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6050);
    // 0x8004B01C: addiu       $v1, $zero, 0xC8
    ctx->r3 = ADD32(0, 0XC8);
    // 0x8004B020: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004B024: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8004B028: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8004B02C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8004B030: bne         $v1, $v0, L_8004B040
    if (ctx->r3 != ctx->r2) {
        // 0x8004B034: sw          $a3, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r7;
            goto L_8004B040;
    }
    // 0x8004B034: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8004B038: b           L_8004B0E4
    // 0x8004B03C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8004B0E4;
    // 0x8004B03C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8004B040:
    // 0x8004B040: bne         $v0, $zero, L_8004B06C
    if (ctx->r2 != 0) {
        // 0x8004B044: addiu       $a0, $sp, 0x26
        ctx->r4 = ADD32(ctx->r29, 0X26);
            goto L_8004B06C;
    }
    // 0x8004B044: addiu       $a0, $sp, 0x26
    ctx->r4 = ADD32(ctx->r29, 0X26);
    // 0x8004B048: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8004B04C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8004B050: lh          $a1, 0x32($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X32);
    // 0x8004B054: lh          $a2, 0x36($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X36);
    // 0x8004B058: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8004B05C: jal         0x8004AE3C
    // 0x8004B060: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_8004AE3C(rdram, ctx);
        goto after_0;
    // 0x8004B060: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x8004B064: b           L_8004B0E4
    // 0x8004B068: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8004B0E4;
    // 0x8004B068: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004B06C:
    // 0x8004B06C: jal         0x8004B0F4
    // 0x8004B070: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_8004B0F4(rdram, ctx);
        goto after_1;
    // 0x8004B070: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x8004B074: lh          $a0, 0x26($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X26);
    // 0x8004B078: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004B07C: addiu       $v1, $zero, 0xC8
    ctx->r3 = ADD32(0, 0XC8);
    // 0x8004B080: bne         $a0, $at, L_8004B0E4
    if (ctx->r4 != ctx->r1) {
        // 0x8004B084: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8004B0E4;
    }
    // 0x8004B084: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8004B088: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004B08C: addiu       $v0, $v0, -0x6048
    ctx->r2 = ADD32(ctx->r2, -0X6048);
    // 0x8004B090: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8004B094:
    // 0x8004B094: lw          $t7, 0x18($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X18);
    // 0x8004B098: bnel        $t7, $zero, L_8004B0D4
    if (ctx->r15 != 0) {
        // 0x8004B09C: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8004B0D4;
    }
    goto skip_0;
    // 0x8004B09C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_0:
    // 0x8004B0A0: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8004B0A4: lh          $a1, 0x32($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X32);
    // 0x8004B0A8: lh          $a2, 0x36($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X36);
    // 0x8004B0AC: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8004B0B0: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x8004B0B4: jal         0x8004AE3C
    // 0x8004B0B8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_8004AE3C(rdram, ctx);
        goto after_2;
    // 0x8004B0B8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_2:
    // 0x8004B0BC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8004B0C0: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x8004B0C4: sra         $t9, $v0, 16
    ctx->r25 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8004B0C8: b           L_8004B0E4
    // 0x8004B0CC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_8004B0E4;
    // 0x8004B0CC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8004B0D0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8004B0D4:
    // 0x8004B0D4: bne         $a0, $v1, L_8004B094
    if (ctx->r4 != ctx->r3) {
        // 0x8004B0D8: addiu       $v0, $v0, 0x1C
        ctx->r2 = ADD32(ctx->r2, 0X1C);
            goto L_8004B094;
    }
    // 0x8004B0D8: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x8004B0DC: b           L_8004B0E8
    // 0x8004B0E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8004B0E8;
    // 0x8004B0E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004B0E4:
    // 0x8004B0E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004B0E8:
    // 0x8004B0E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8004B0EC: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8004B0F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004B0F4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8004B0F8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8004B0FC: addiu       $v0, $sp, 0x14
    ctx->r2 = ADD32(ctx->r29, 0X14);
    // 0x8004B100: addiu       $v1, $sp, 0x24
    ctx->r3 = ADD32(ctx->r29, 0X24);
L_8004B104:
    // 0x8004B104: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8004B108: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8004B10C: bne         $at, $zero, L_8004B104
    if (ctx->r1 != 0) {
        // 0x8004B110: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_8004B104;
    }
    // 0x8004B110: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x8004B114: addiu       $v0, $sp, 0x14
    ctx->r2 = ADD32(ctx->r29, 0X14);
    // 0x8004B118: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8004B11C: addiu       $v1, $sp, 0x24
    ctx->r3 = ADD32(ctx->r29, 0X24);
L_8004B120:
    // 0x8004B120: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x8004B124: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004B128: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8004B12C: sb          $t6, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r14;
    // 0x8004B130: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x8004B134: bne         $t7, $zero, L_8004B144
    if (ctx->r15 != 0) {
        // 0x8004B138: nop
    
            goto L_8004B144;
    }
    // 0x8004B138: nop

    // 0x8004B13C: b           L_8004B150
    // 0x8004B140: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_8004B150;
    // 0x8004B140: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8004B144:
    // 0x8004B144: bne         $at, $zero, L_8004B120
    if (ctx->r1 != 0) {
        // 0x8004B148: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8004B120;
    }
    // 0x8004B148: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8004B14C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8004B150:
    // 0x8004B150: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004B154: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8004B158: addiu       $t1, $sp, 0x24
    ctx->r9 = ADD32(ctx->r29, 0X24);
    // 0x8004B15C: or          $t2, $t1, $zero
    ctx->r10 = ctx->r9 | 0;
    // 0x8004B160: addiu       $a0, $a0, -0x6048
    ctx->r4 = ADD32(ctx->r4, -0X6048);
    // 0x8004B164: lw          $v0, -0x6050($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6050);
L_8004B168:
    // 0x8004B168: lw          $t9, 0x18($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X18);
    // 0x8004B16C: addiu       $a3, $sp, 0x14
    ctx->r7 = ADD32(ctx->r29, 0X14);
    // 0x8004B170: addiu       $t0, $a0, 0x8
    ctx->r8 = ADD32(ctx->r4, 0X8);
    // 0x8004B174: beql        $t9, $zero, L_8004B1B4
    if (ctx->r25 == 0) {
        // 0x8004B178: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8004B1B4;
    }
    goto skip_0;
    // 0x8004B178: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
L_8004B17C:
    // 0x8004B17C: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x8004B180: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x8004B184: bne         $t3, $t4, L_8004B198
    if (ctx->r11 != ctx->r12) {
        // 0x8004B188: nop
    
            goto L_8004B198;
    }
    // 0x8004B188: nop

    // 0x8004B18C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8004B190: bne         $a3, $t2, L_8004B17C
    if (ctx->r7 != ctx->r10) {
        // 0x8004B194: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_8004B17C;
    }
    // 0x8004B194: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
L_8004B198:
    // 0x8004B198: bne         $a3, $t1, L_8004B1AC
    if (ctx->r7 != ctx->r9) {
        // 0x8004B19C: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8004B1AC;
    }
    // 0x8004B19C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8004B1A0: sh          $v1, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r3;
    // 0x8004B1A4: b           L_8004B1CC
    // 0x8004B1A8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8004B1CC;
    // 0x8004B1A8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8004B1AC:
    // 0x8004B1AC: beq         $v0, $zero, L_8004B1C0
    if (ctx->r2 == 0) {
        // 0x8004B1B0: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8004B1C0;
    }
    // 0x8004B1B0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8004B1B4:
    // 0x8004B1B4: slti        $at, $v1, 0xC8
    ctx->r1 = SIGNED(ctx->r3) < 0XC8 ? 1 : 0;
    // 0x8004B1B8: bne         $at, $zero, L_8004B168
    if (ctx->r1 != 0) {
        // 0x8004B1BC: addiu       $a0, $a0, 0x1C
        ctx->r4 = ADD32(ctx->r4, 0X1C);
            goto L_8004B168;
    }
    // 0x8004B1BC: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
L_8004B1C0:
    // 0x8004B1C0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8004B1C4: sh          $t5, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r13;
    // 0x8004B1C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004B1CC:
    // 0x8004B1CC: jr          $ra
    // 0x8004B1D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    TRACE_RETURN()
    return;
    // 0x8004B1D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8004B1E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004B1E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004B1E4: sll         $a1, $a0, 16
    ctx->r5 = S32(ctx->r4 << 16);
    // 0x8004B1E8: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8004B1EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8004B1F0: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x8004B1F4: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8004B1F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004B1FC: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x8004B200: jal         0x8004EFD0
    // 0x8004B204: lw          $a0, -0x4520($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4520);
    func_8004EFD0(rdram, ctx);
        goto after_0;
    // 0x8004B204: lw          $a0, -0x4520($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4520);
    after_0:
    // 0x8004B208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004B20C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004B210: sw          $v0, -0x4A24($at)
    MEM_W(-0X4A24, ctx->r1) = ctx->r2;
    // 0x8004B214: jr          $ra
    // 0x8004B218: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    TRACE_RETURN()
    return;
    // 0x8004B218: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8004B21C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004B21C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004B220: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004B224: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004B228: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8004B22C: lw          $a1, -0x4A24($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4A24);
    // 0x8004B230: jal         0x800042A8
    // 0x8004B234: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    func_800042A8(rdram, ctx);
        goto after_0;
    // 0x8004B234: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    after_0:
    // 0x8004B238: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004B23C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004B240: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8004B248(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004B248: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004B24C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004B250: lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // 0x8004B254: addiu       $s0, $s0, 0x2800
    ctx->r16 = ADD32(ctx->r16, 0X2800);
    // 0x8004B258: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004B25C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004B260: jal         0x80004364
    // 0x8004B264: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x8004B264: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    after_0:
    // 0x8004B268: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004B26C: addiu       $v1, $v1, -0x4A5C
    ctx->r3 = ADD32(ctx->r3, -0X4A5C);
    // 0x8004B270: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8004B274: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8004B278: jal         0x8000C7C0
    // 0x8004B27C: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    func_8000C7C0(rdram, ctx);
        goto after_1;
    // 0x8004B27C: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    after_1:
    // 0x8004B280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004B284: jal         0x80004364
    // 0x8004B288: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    func_80004364(rdram, ctx);
        goto after_2;
    // 0x8004B288: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    after_2:
    // 0x8004B28C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004B290: addiu       $v1, $v1, -0x4A58
    ctx->r3 = ADD32(ctx->r3, -0X4A58);
    // 0x8004B294: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8004B298: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8004B29C: jal         0x8000C7C0
    // 0x8004B2A0: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    func_8000C7C0(rdram, ctx);
        goto after_3;
    // 0x8004B2A0: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    after_3:
    // 0x8004B2A4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004B2A8: addiu       $v0, $v0, -0x4A5C
    ctx->r2 = ADD32(ctx->r2, -0X4A5C);
    // 0x8004B2AC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8004B2B0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004B2B4: addiu       $v1, $v1, -0x4A58
    ctx->r3 = ADD32(ctx->r3, -0X4A58);
    // 0x8004B2B8: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x8004B2BC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8004B2C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004B2C4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8004B2C8: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x8004B2CC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8004B2D0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8004B2D4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8004B2D8: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8004B2DC: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8004B2E0: jal         0x80004364
    // 0x8004B2E4: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    func_80004364(rdram, ctx);
        goto after_4;
    // 0x8004B2E4: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    after_4:
    // 0x8004B2E8: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8004B2EC: addiu       $t0, $t0, -0x4A60
    ctx->r8 = ADD32(ctx->r8, -0X4A60);
    // 0x8004B2F0: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8004B2F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8004B2F8: jal         0x8000C7C0
    // 0x8004B2FC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_8000C7C0(rdram, ctx);
        goto after_5;
    // 0x8004B2FC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_5:
    // 0x8004B300: jal         0x8000F764
    // 0x8004B304: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_8000F764(rdram, ctx);
        goto after_6;
    // 0x8004B304: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_6:
    // 0x8004B308: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8004B30C: addiu       $t0, $t0, -0x4A60
    ctx->r8 = ADD32(ctx->r8, -0X4A60);
    // 0x8004B310: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x8004B314: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004B318: addiu       $v1, $v1, -0x6C94
    ctx->r3 = ADD32(ctx->r3, -0X6C94);
    // 0x8004B31C: sw          $v0, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r2;
    // 0x8004B320: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8004B324: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x8004B328: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8004B32C: lw          $t7, 0xD4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XD4);
    // 0x8004B330: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x8004B334: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8004B338: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x8004B33C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8004B340: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x8004B344: lw          $t1, 0xD4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0XD4);
    // 0x8004B348: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x8004B34C: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8004B350: sw          $t2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r10;
    // 0x8004B354: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8004B358: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x8004B35C: lw          $t7, 0xD4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XD4);
    // 0x8004B360: lw          $t8, 0x8($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X8);
    // 0x8004B364: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8004B368: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x8004B36C: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8004B370: lw          $t2, 0xD4($t3)
    ctx->r10 = MEM_W(ctx->r11, 0XD4);
    // 0x8004B374: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x8004B378: jal         0x8000F764
    // 0x8004B37C: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    func_8000F764(rdram, ctx);
        goto after_7;
    // 0x8004B37C: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    after_7:
    // 0x8004B380: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8004B384: addiu       $t0, $t0, -0x4A60
    ctx->r8 = ADD32(ctx->r8, -0X4A60);
    // 0x8004B388: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x8004B38C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004B390: lui         $a3, 0xC1A0
    ctx->r7 = S32(0XC1A0 << 16);
    // 0x8004B394: sw          $v0, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r2;
    // 0x8004B398: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8004B39C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8004B3A0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8004B3A4: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    // 0x8004B3A8: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
    // 0x8004B3AC: lw          $t7, 0xD4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0XD4);
    // 0x8004B3B0: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8004B3B4: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8004B3B8: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8004B3BC: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x8004B3C0: lw          $t2, 0xC($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XC);
    // 0x8004B3C4: lw          $t3, 0xD4($t9)
    ctx->r11 = MEM_W(ctx->r25, 0XD4);
    // 0x8004B3C8: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x8004B3CC: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x8004B3D0: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8004B3D4: lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X8);
    // 0x8004B3D8: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x8004B3DC: lw          $t5, 0xD4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XD4);
    // 0x8004B3E0: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x8004B3E4: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8004B3E8: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x8004B3EC: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
    // 0x8004B3F0: lw          $t9, 0xD4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XD4);
    // 0x8004B3F4: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x8004B3F8: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x8004B3FC: lw          $a0, 0x8($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X8);
    // 0x8004B400: jal         0x80001A6C
    // 0x8004B404: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80001A6C(rdram, ctx);
        goto after_8;
    // 0x8004B404: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_8:
    // 0x8004B408: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8004B40C: addiu       $t0, $t0, -0x4A60
    ctx->r8 = ADD32(ctx->r8, -0X4A60);
    // 0x8004B410: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8004B414: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004B418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004B41C: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x8004B420: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    // 0x8004B424: sw          $zero, 0xDC($t2)
    MEM_W(0XDC, ctx->r10) = 0;
    // 0x8004B428: jal         0x80004364
    // 0x8004B42C: sw          $zero, -0x4A54($at)
    MEM_W(-0X4A54, ctx->r1) = 0;
    func_80004364(rdram, ctx);
        goto after_9;
    // 0x8004B42C: sw          $zero, -0x4A54($at)
    MEM_W(-0X4A54, ctx->r1) = 0;
    after_9:
    // 0x8004B430: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004B434: addiu       $v1, $v1, -0x4A4C
    ctx->r3 = ADD32(ctx->r3, -0X4A4C);
    // 0x8004B438: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8004B43C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8004B440: jal         0x8000C7C0
    // 0x8004B444: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    func_8000C7C0(rdram, ctx);
        goto after_10;
    // 0x8004B444: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    after_10:
    // 0x8004B448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004B44C: jal         0x80004364
    // 0x8004B450: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    func_80004364(rdram, ctx);
        goto after_11;
    // 0x8004B450: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    after_11:
    // 0x8004B454: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004B458: addiu       $v1, $v1, -0x4A48
    ctx->r3 = ADD32(ctx->r3, -0X4A48);
    // 0x8004B45C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8004B460: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8004B464: jal         0x8000C7C0
    // 0x8004B468: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    func_8000C7C0(rdram, ctx);
        goto after_12;
    // 0x8004B468: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    after_12:
    // 0x8004B46C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004B470: addiu       $v0, $v0, -0x4A4C
    ctx->r2 = ADD32(ctx->r2, -0X4A4C);
    // 0x8004B474: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8004B478: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004B47C: addiu       $v1, $v1, -0x4A48
    ctx->r3 = ADD32(ctx->r3, -0X4A48);
    // 0x8004B480: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x8004B484: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8004B488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004B48C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8004B490: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
    // 0x8004B494: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8004B498: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8004B49C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8004B4A0: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8004B4A4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8004B4A8: jal         0x80004364
    // 0x8004B4AC: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    func_80004364(rdram, ctx);
        goto after_13;
    // 0x8004B4AC: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    after_13:
    // 0x8004B4B0: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8004B4B4: addiu       $t0, $t0, -0x4A50
    ctx->r8 = ADD32(ctx->r8, -0X4A50);
    // 0x8004B4B8: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8004B4BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8004B4C0: jal         0x8000C7C0
    // 0x8004B4C4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_8000C7C0(rdram, ctx);
        goto after_14;
    // 0x8004B4C4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_14:
    // 0x8004B4C8: jal         0x8000F764
    // 0x8004B4CC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_8000F764(rdram, ctx);
        goto after_15;
    // 0x8004B4CC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_15:
    // 0x8004B4D0: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8004B4D4: addiu       $t0, $t0, -0x4A50
    ctx->r8 = ADD32(ctx->r8, -0X4A50);
    // 0x8004B4D8: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x8004B4DC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004B4E0: addiu       $v1, $v1, -0x6C90
    ctx->r3 = ADD32(ctx->r3, -0X6C90);
    // 0x8004B4E4: sw          $v0, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r2;
    // 0x8004B4E8: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8004B4EC: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8004B4F0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8004B4F4: lw          $t5, 0xD4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XD4);
    // 0x8004B4F8: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x8004B4FC: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x8004B500: sw          $t2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r10;
    // 0x8004B504: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8004B508: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x8004B50C: lw          $t6, 0xD4($t8)
    ctx->r14 = MEM_W(ctx->r24, 0XD4);
    // 0x8004B510: lw          $t1, 0x8($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X8);
    // 0x8004B514: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8004B518: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x8004B51C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8004B520: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8004B524: lw          $t5, 0xD4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XD4);
    // 0x8004B528: lw          $t7, 0x8($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X8);
    // 0x8004B52C: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x8004B530: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x8004B534: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x8004B538: lw          $t9, 0xD4($t3)
    ctx->r25 = MEM_W(ctx->r11, 0XD4);
    // 0x8004B53C: lw          $t6, 0x8($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X8);
    // 0x8004B540: jal         0x8000F764
    // 0x8004B544: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    func_8000F764(rdram, ctx);
        goto after_16;
    // 0x8004B544: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    after_16:
    // 0x8004B548: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8004B54C: addiu       $t0, $t0, -0x4A50
    ctx->r8 = ADD32(ctx->r8, -0X4A50);
    // 0x8004B550: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8004B554: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004B558: lui         $a3, 0xC1A0
    ctx->r7 = S32(0XC1A0 << 16);
    // 0x8004B55C: sw          $v0, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r2;
    // 0x8004B560: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8004B564: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8004B568: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8004B56C: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x8004B570: lw          $t4, 0xC($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XC);
    // 0x8004B574: lw          $t5, 0xD4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0XD4);
    // 0x8004B578: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x8004B57C: sw          $t4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r12;
    // 0x8004B580: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8004B584: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x8004B588: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x8004B58C: lw          $t3, 0xD4($t8)
    ctx->r11 = MEM_W(ctx->r24, 0XD4);
    // 0x8004B590: lw          $t6, 0x4($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X4);
    // 0x8004B594: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x8004B598: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8004B59C: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
    // 0x8004B5A0: lw          $t5, 0xC($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XC);
    // 0x8004B5A4: lw          $t2, 0xD4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XD4);
    // 0x8004B5A8: sw          $t2, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r10;
    // 0x8004B5AC: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8004B5B0: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x8004B5B4: lw          $t4, 0xC($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XC);
    // 0x8004B5B8: lw          $t8, 0xD4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XD4);
    // 0x8004B5BC: sw          $t4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r12;
    // 0x8004B5C0: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x8004B5C4: lw          $a0, 0x8($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X8);
    // 0x8004B5C8: jal         0x80001A6C
    // 0x8004B5CC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80001A6C(rdram, ctx);
        goto after_17;
    // 0x8004B5CC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_17:
    // 0x8004B5D0: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8004B5D4: addiu       $t0, $t0, -0x4A50
    ctx->r8 = ADD32(ctx->r8, -0X4A50);
    // 0x8004B5D8: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8004B5DC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004B5E0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004B5E4: lw          $t9, 0x8($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X8);
    // 0x8004B5E8: addiu       $v0, $v0, -0x4A30
    ctx->r2 = ADD32(ctx->r2, -0X4A30);
    // 0x8004B5EC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004B5F0: sw          $zero, 0xDC($t9)
    MEM_W(0XDC, ctx->r25) = 0;
    // 0x8004B5F4: sw          $zero, -0x4A44($at)
    MEM_W(-0X4A44, ctx->r1) = 0;
    // 0x8004B5F8: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x8004B5FC: lh          $t1, 0x0($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X0);
    // 0x8004B600: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004B604: addiu       $v1, $v1, -0x4A2E
    ctx->r3 = ADD32(ctx->r3, -0X4A2E);
    // 0x8004B608: sh          $t1, -0x4A34($at)
    MEM_H(-0X4A34, ctx->r1) = ctx->r9;
    // 0x8004B60C: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x8004B610: lh          $t2, 0x0($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X0);
    // 0x8004B614: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004B618: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8004B61C: sh          $t2, -0x4A32($at)
    MEM_H(-0X4A32, ctx->r1) = ctx->r10;
    // 0x8004B620: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x8004B624: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004B628: addiu       $a3, $a3, -0x4A2A
    ctx->r7 = ADD32(ctx->r7, -0X4A2A);
    // 0x8004B62C: sh          $a2, -0x4A2C($at)
    MEM_H(-0X4A2C, ctx->r1) = ctx->r6;
    // 0x8004B630: sh          $a2, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r6;
    // 0x8004B634: lh          $t5, 0x0($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X0);
    // 0x8004B638: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004B63C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004B640: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    // 0x8004B644: jal         0x80004364
    // 0x8004B648: sh          $t5, -0x4A28($at)
    MEM_H(-0X4A28, ctx->r1) = ctx->r13;
    func_80004364(rdram, ctx);
        goto after_18;
    // 0x8004B648: sh          $t5, -0x4A28($at)
    MEM_H(-0X4A28, ctx->r1) = ctx->r13;
    after_18:
    // 0x8004B64C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004B650: addiu       $v1, $v1, -0x4A3C
    ctx->r3 = ADD32(ctx->r3, -0X4A3C);
    // 0x8004B654: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8004B658: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8004B65C: jal         0x8000C7C0
    // 0x8004B660: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    func_8000C7C0(rdram, ctx);
        goto after_19;
    // 0x8004B660: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    after_19:
    // 0x8004B664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004B668: jal         0x80004364
    // 0x8004B66C: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    func_80004364(rdram, ctx);
        goto after_20;
    // 0x8004B66C: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    after_20:
    // 0x8004B670: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004B674: addiu       $v1, $v1, -0x4A38
    ctx->r3 = ADD32(ctx->r3, -0X4A38);
    // 0x8004B678: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8004B67C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8004B680: jal         0x8000C7C0
    // 0x8004B684: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    func_8000C7C0(rdram, ctx);
        goto after_21;
    // 0x8004B684: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    after_21:
    // 0x8004B688: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004B68C: addiu       $v0, $v0, -0x4A3C
    ctx->r2 = ADD32(ctx->r2, -0X4A3C);
    // 0x8004B690: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8004B694: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004B698: addiu       $v1, $v1, -0x4A38
    ctx->r3 = ADD32(ctx->r3, -0X4A38);
    // 0x8004B69C: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8004B6A0: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8004B6A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004B6A8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8004B6AC: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
    // 0x8004B6B0: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8004B6B4: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8004B6B8: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8004B6BC: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8004B6C0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8004B6C4: jal         0x80004364
    // 0x8004B6C8: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    func_80004364(rdram, ctx);
        goto after_22;
    // 0x8004B6C8: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    after_22:
    // 0x8004B6CC: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8004B6D0: addiu       $t0, $t0, -0x4A40
    ctx->r8 = ADD32(ctx->r8, -0X4A40);
    // 0x8004B6D4: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8004B6D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8004B6DC: jal         0x8000C7C0
    // 0x8004B6E0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_8000C7C0(rdram, ctx);
        goto after_23;
    // 0x8004B6E0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_23:
    // 0x8004B6E4: jal         0x8000F764
    // 0x8004B6E8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_8000F764(rdram, ctx);
        goto after_24;
    // 0x8004B6E8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_24:
    // 0x8004B6EC: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8004B6F0: addiu       $t0, $t0, -0x4A40
    ctx->r8 = ADD32(ctx->r8, -0X4A40);
    // 0x8004B6F4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8004B6F8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004B6FC: addiu       $v1, $v1, -0x6C8C
    ctx->r3 = ADD32(ctx->r3, -0X6C8C);
    // 0x8004B700: sw          $v0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r2;
    // 0x8004B704: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8004B708: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8004B70C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8004B710: lw          $t4, 0xD4($t7)
    ctx->r12 = MEM_W(ctx->r15, 0XD4);
    // 0x8004B714: lw          $t5, 0x8($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X8);
    // 0x8004B718: lw          $t8, 0x4($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X4);
    // 0x8004B71C: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x8004B720: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x8004B724: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8004B728: lw          $t6, 0xD4($t3)
    ctx->r14 = MEM_W(ctx->r11, 0XD4);
    // 0x8004B72C: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x8004B730: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8004B734: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x8004B738: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8004B73C: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x8004B740: lw          $t4, 0xD4($t7)
    ctx->r12 = MEM_W(ctx->r15, 0XD4);
    // 0x8004B744: lw          $t8, 0x8($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X8);
    // 0x8004B748: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
    // 0x8004B74C: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8004B750: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x8004B754: lw          $t9, 0xD4($t1)
    ctx->r25 = MEM_W(ctx->r9, 0XD4);
    // 0x8004B758: lw          $t6, 0x8($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X8);
    // 0x8004B75C: jal         0x8000F764
    // 0x8004B760: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    func_8000F764(rdram, ctx);
        goto after_25;
    // 0x8004B760: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    after_25:
    // 0x8004B764: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8004B768: addiu       $t0, $t0, -0x4A40
    ctx->r8 = ADD32(ctx->r8, -0X4A40);
    // 0x8004B76C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8004B770: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8004B774: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8004B778: sw          $v0, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r2;
    // 0x8004B77C: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8004B780: lui         $a3, 0xC1A0
    ctx->r7 = S32(0XC1A0 << 16);
    // 0x8004B784: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    // 0x8004B788: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x8004B78C: lw          $t4, 0xD4($t5)
    ctx->r12 = MEM_W(ctx->r13, 0XD4);
    // 0x8004B790: lw          $t8, 0x4($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X4);
    // 0x8004B794: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8004B798: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8004B79C: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    // 0x8004B7A0: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x8004B7A4: lw          $t1, 0xD4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0XD4);
    // 0x8004B7A8: lw          $t6, 0x4($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X4);
    // 0x8004B7AC: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x8004B7B0: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8004B7B4: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x8004B7B8: lw          $t4, 0xC($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XC);
    // 0x8004B7BC: lw          $t5, 0xD4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0XD4);
    // 0x8004B7C0: sw          $t5, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r13;
    // 0x8004B7C4: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8004B7C8: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x8004B7CC: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x8004B7D0: lw          $t3, 0xD4($t8)
    ctx->r11 = MEM_W(ctx->r24, 0XD4);
    // 0x8004B7D4: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x8004B7D8: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8004B7DC: lw          $a0, 0x8($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X8);
    // 0x8004B7E0: jal         0x80001A6C
    // 0x8004B7E4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_80001A6C(rdram, ctx);
        goto after_26;
    // 0x8004B7E4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_26:
    // 0x8004B7E8: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8004B7EC: addiu       $t0, $t0, -0x4A40
    ctx->r8 = ADD32(ctx->r8, -0X4A40);
    // 0x8004B7F0: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8004B7F4: lw          $t9, 0x8($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X8);
    // 0x8004B7F8: sw          $zero, 0xDC($t9)
    MEM_W(0XDC, ctx->r25) = 0;
    // 0x8004B7FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004B800: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004B804: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004B808: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8004B810(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004B810: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8004B814: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004B818: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8004B81C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8004B820: jal         0x800022F0
    // 0x8004B824: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_800022F0(rdram, ctx);
        goto after_0;
    // 0x8004B824: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x8004B828: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8004B82C: lw          $t6, -0x4A5C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4A5C);
    // 0x8004B830: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8004B834: addiu       $s1, $s1, -0x4A50
    ctx->r17 = ADD32(ctx->r17, -0X4A50);
    // 0x8004B838: lw          $s0, 0x0($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X0);
    // 0x8004B83C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8004B840: beql        $v0, $zero, L_8004B888
    if (ctx->r2 == 0) {
        // 0x8004B844: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8004B888;
    }
    goto skip_0;
    // 0x8004B844: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8004B848: lh          $t7, 0xE2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XE2);
L_8004B84C:
    // 0x8004B84C: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x8004B850: beql        $t8, $zero, L_8004B878
    if (ctx->r24 == 0) {
        // 0x8004B854: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8004B878;
    }
    goto skip_1;
    // 0x8004B854: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    skip_1:
    // 0x8004B858: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8004B85C: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    // 0x8004B860: addiu       $a1, $s0, 0x54
    ctx->r5 = ADD32(ctx->r16, 0X54);
    // 0x8004B864: lw          $a2, 0x8($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X8);
    // 0x8004B868: jal         0x80000BD8
    // 0x8004B86C: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    func_80000BD8(rdram, ctx);
        goto after_1;
    // 0x8004B86C: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    after_1:
    // 0x8004B870: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8004B874: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8004B878:
    // 0x8004B878: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8004B87C: bnel        $v0, $zero, L_8004B84C
    if (ctx->r2 != 0) {
        // 0x8004B880: lh          $t7, 0xE2($s0)
        ctx->r15 = MEM_H(ctx->r16, 0XE2);
            goto L_8004B84C;
    }
    goto skip_2;
    // 0x8004B880: lh          $t7, 0xE2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XE2);
    skip_2:
    // 0x8004B884: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004B888:
    // 0x8004B888: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8004B88C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8004B890: jr          $ra
    // 0x8004B894: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    TRACE_RETURN()
    return;
    // 0x8004B894: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_8004B898(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004B898: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8004B89C: lw          $t6, -0x4A5C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4A5C);
    // 0x8004B8A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004B8A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004B8A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004B8AC: lw          $s0, 0x0($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X0);
    // 0x8004B8B0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8004B8B4: beql        $v0, $zero, L_8004B8F0
    if (ctx->r2 == 0) {
        // 0x8004B8B8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8004B8F0;
    }
    goto skip_0;
    // 0x8004B8B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8004B8BC: lh          $t7, 0xE2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XE2);
L_8004B8C0:
    // 0x8004B8C0: addiu       $a0, $s0, 0x98
    ctx->r4 = ADD32(ctx->r16, 0X98);
    // 0x8004B8C4: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x8004B8C8: beql        $t8, $zero, L_8004B8E0
    if (ctx->r24 == 0) {
        // 0x8004B8CC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8004B8E0;
    }
    goto skip_1;
    // 0x8004B8CC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    skip_1:
    // 0x8004B8D0: jal         0x80004EF0
    // 0x8004B8D4: addiu       $a1, $s0, 0x14
    ctx->r5 = ADD32(ctx->r16, 0X14);
    func_80004EF0(rdram, ctx);
        goto after_0;
    // 0x8004B8D4: addiu       $a1, $s0, 0x14
    ctx->r5 = ADD32(ctx->r16, 0X14);
    after_0:
    // 0x8004B8D8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8004B8DC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8004B8E0:
    // 0x8004B8E0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8004B8E4: bnel        $v0, $zero, L_8004B8C0
    if (ctx->r2 != 0) {
        // 0x8004B8E8: lh          $t7, 0xE2($s0)
        ctx->r15 = MEM_H(ctx->r16, 0XE2);
            goto L_8004B8C0;
    }
    goto skip_2;
    // 0x8004B8E8: lh          $t7, 0xE2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XE2);
    skip_2:
    // 0x8004B8EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004B8F0:
    // 0x8004B8F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004B8F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004B8F8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8004B900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004B900: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8004B904: lw          $a1, -0x4A54($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4A54);
    // 0x8004B908: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x8004B90C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8004B910: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8004B914: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8004B918: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004B91C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8004B920: beq         $a1, $zero, L_8004B944
    if (ctx->r5 == 0) {
        // 0x8004B924: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8004B944;
    }
    // 0x8004B924: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8004B928: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004B92C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8004B930: addiu       $a2, $a2, -0x6C60
    ctx->r6 = ADD32(ctx->r6, -0X6C60);
    // 0x8004B934: jal         0x8001026C
    // 0x8004B938: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    func_8001026C(rdram, ctx);
        goto after_0;
    // 0x8004B938: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    after_0:
    // 0x8004B93C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004B940: sw          $zero, -0x4A54($at)
    MEM_W(-0X4A54, ctx->r1) = 0;
L_8004B944:
    // 0x8004B944: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8004B948: lw          $a1, -0x4A44($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4A44);
    // 0x8004B94C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004B950: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8004B954: beq         $a1, $zero, L_8004B96C
    if (ctx->r5 == 0) {
        // 0x8004B958: lui         $a2, 0x8013
        ctx->r6 = S32(0X8013 << 16);
            goto L_8004B96C;
    }
    // 0x8004B958: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8004B95C: jal         0x8001026C
    // 0x8004B960: addiu       $a2, $a2, -0x6C60
    ctx->r6 = ADD32(ctx->r6, -0X6C60);
    func_8001026C(rdram, ctx);
        goto after_1;
    // 0x8004B960: addiu       $a2, $a2, -0x6C60
    ctx->r6 = ADD32(ctx->r6, -0X6C60);
    after_1:
    // 0x8004B964: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004B968: sw          $zero, -0x4A44($at)
    MEM_W(-0X4A44, ctx->r1) = 0;
L_8004B96C:
    // 0x8004B96C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8004B970: lw          $t6, -0x4A5C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4A5C);
    // 0x8004B974: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x8004B978: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8004B97C: beq         $t7, $zero, L_8004B9B0
    if (ctx->r15 == 0) {
        // 0x8004B980: nop
    
            goto L_8004B9B0;
    }
    // 0x8004B980: nop

    // 0x8004B984: lh          $t8, 0xE2($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE2);
L_8004B988:
    // 0x8004B988: lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X0);
    // 0x8004B98C: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x8004B990: beql        $t9, $zero, L_8004B9A4
    if (ctx->r25 == 0) {
        // 0x8004B994: lw          $t0, 0x0($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X0);
            goto L_8004B9A4;
    }
    goto skip_0;
    // 0x8004B994: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x8004B998: jal         0x8004C444
    // 0x8004B99C: nop

    func_8004C444(rdram, ctx);
        goto after_2;
    // 0x8004B99C: nop

    after_2:
    // 0x8004B9A0: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
L_8004B9A4:
    // 0x8004B9A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004B9A8: bnel        $t0, $zero, L_8004B988
    if (ctx->r8 != 0) {
        // 0x8004B9AC: lh          $t8, 0xE2($a0)
        ctx->r24 = MEM_H(ctx->r4, 0XE2);
            goto L_8004B988;
    }
    goto skip_1;
    // 0x8004B9AC: lh          $t8, 0xE2($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE2);
    skip_1:
L_8004B9B0:
    // 0x8004B9B0: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8004B9B4: lw          $t1, -0x4A4C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4A4C);
    // 0x8004B9B8: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x8004B9BC: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8004B9C0: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8004B9C4: beq         $t2, $zero, L_8004BA04
    if (ctx->r10 == 0) {
        // 0x8004B9C8: nop
    
            goto L_8004BA04;
    }
    // 0x8004B9C8: nop

    // 0x8004B9CC: lh          $t3, 0xE2($a0)
    ctx->r11 = MEM_H(ctx->r4, 0XE2);
L_8004B9D0:
    // 0x8004B9D0: lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X0);
    // 0x8004B9D4: andi        $t4, $t3, 0x80
    ctx->r12 = ctx->r11 & 0X80;
    // 0x8004B9D8: beql        $t4, $zero, L_8004B9EC
    if (ctx->r12 == 0) {
        // 0x8004B9DC: lw          $t5, 0x0($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X0);
            goto L_8004B9EC;
    }
    goto skip_2;
    // 0x8004B9DC: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x8004B9E0: jal         0x8004C444
    // 0x8004B9E4: nop

    func_8004C444(rdram, ctx);
        goto after_3;
    // 0x8004B9E4: nop

    after_3:
    // 0x8004B9E8: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
L_8004B9EC:
    // 0x8004B9EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004B9F0: bnel        $t5, $zero, L_8004B9D0
    if (ctx->r13 != 0) {
        // 0x8004B9F4: lh          $t3, 0xE2($a0)
        ctx->r11 = MEM_H(ctx->r4, 0XE2);
            goto L_8004B9D0;
    }
    goto skip_3;
    // 0x8004B9F4: lh          $t3, 0xE2($a0)
    ctx->r11 = MEM_H(ctx->r4, 0XE2);
    skip_3:
    // 0x8004B9F8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8004B9FC: lw          $t6, -0x4A4C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4A4C);
    // 0x8004BA00: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
L_8004BA04:
    // 0x8004BA04: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8004BA08: lw          $t7, -0x4A5C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4A5C);
    // 0x8004BA0C: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x8004BA10: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8004BA14: beql        $v0, $zero, L_8004BA5C
    if (ctx->r2 == 0) {
        // 0x8004BA18: lw          $v0, 0x0($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X0);
            goto L_8004BA5C;
    }
    goto skip_4;
    // 0x8004BA18: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    skip_4:
    // 0x8004BA1C: lh          $t8, 0xE2($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE2);
L_8004BA20:
    // 0x8004BA20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8004BA24: andi        $t9, $t8, 0x10
    ctx->r25 = ctx->r24 & 0X10;
    // 0x8004BA28: beql        $t9, $zero, L_8004BA44
    if (ctx->r25 == 0) {
        // 0x8004BA2C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8004BA44;
    }
    goto skip_5;
    // 0x8004BA2C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_5:
    // 0x8004BA30: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8004BA34: sll         $t0, $s2, 16
    ctx->r8 = S32(ctx->r18 << 16);
    // 0x8004BA38: b           L_8004BA4C
    // 0x8004BA3C: sra         $s2, $t0, 16
    ctx->r18 = S32(SIGNED(ctx->r8) >> 16);
        goto L_8004BA4C;
    // 0x8004BA3C: sra         $s2, $t0, 16
    ctx->r18 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8004BA40: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8004BA44:
    // 0x8004BA44: sll         $t2, $s1, 16
    ctx->r10 = S32(ctx->r17 << 16);
    // 0x8004BA48: sra         $s1, $t2, 16
    ctx->r17 = S32(SIGNED(ctx->r10) >> 16);
L_8004BA4C:
    // 0x8004BA4C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8004BA50: bnel        $v0, $zero, L_8004BA20
    if (ctx->r2 != 0) {
        // 0x8004BA54: lh          $t8, 0xE2($a0)
        ctx->r24 = MEM_H(ctx->r4, 0XE2);
            goto L_8004BA20;
    }
    goto skip_6;
    // 0x8004BA54: lh          $t8, 0xE2($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE2);
    skip_6:
    // 0x8004BA58: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_8004BA5C:
    // 0x8004BA5C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004BA60: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004BA64: beq         $v0, $zero, L_8004BA80
    if (ctx->r2 == 0) {
        // 0x8004BA68: addiu       $v1, $v1, -0x4A60
        ctx->r3 = ADD32(ctx->r3, -0X4A60);
            goto L_8004BA80;
    }
    // 0x8004BA68: addiu       $v1, $v1, -0x4A60
    ctx->r3 = ADD32(ctx->r3, -0X4A60);
L_8004BA6C:
    // 0x8004BA6C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8004BA70: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8004BA74: sll         $t4, $s1, 16
    ctx->r12 = S32(ctx->r17 << 16);
    // 0x8004BA78: bne         $v0, $zero, L_8004BA6C
    if (ctx->r2 != 0) {
        // 0x8004BA7C: sra         $s1, $t4, 16
        ctx->r17 = S32(SIGNED(ctx->r12) >> 16);
            goto L_8004BA6C;
    }
    // 0x8004BA7C: sra         $s1, $t4, 16
    ctx->r17 = S32(SIGNED(ctx->r12) >> 16);
L_8004BA80:
    // 0x8004BA80: beq         $s1, $zero, L_8004BB94
    if (ctx->r17 == 0) {
        // 0x8004BA84: addiu       $a0, $a0, 0x2800
        ctx->r4 = ADD32(ctx->r4, 0X2800);
            goto L_8004BB94;
    }
    // 0x8004BA84: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8004BA88: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8004BA8C: sll         $t6, $s1, 16
    ctx->r14 = S32(ctx->r17 << 16);
    // 0x8004BA90: sra         $s1, $t6, 16
    ctx->r17 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8004BA94: jal         0x80004364
    // 0x8004BA98: sll         $a1, $s1, 2
    ctx->r5 = S32(ctx->r17 << 2);
    func_80004364(rdram, ctx);
        goto after_4;
    // 0x8004BA98: sll         $a1, $s1, 2
    ctx->r5 = S32(ctx->r17 << 2);
    after_4:
    // 0x8004BA9C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004BAA0: lui         $t8, 0x8007
    ctx->r24 = S32(0X8007 << 16);
    // 0x8004BAA4: sw          $v0, -0x4A54($at)
    MEM_W(-0X4A54, ctx->r1) = ctx->r2;
    // 0x8004BAA8: addiu       $t8, $t8, -0x4498
    ctx->r24 = ADD32(ctx->r24, -0X4498);
    // 0x8004BAAC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8004BAB0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8004BAB4: lw          $t9, -0x4A5C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4A5C);
    // 0x8004BAB8: addiu       $v1, $v0, 0x4
    ctx->r3 = ADD32(ctx->r2, 0X4);
    // 0x8004BABC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8004BAC0: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x8004BAC4: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x8004BAC8: beq         $t0, $zero, L_8004BB10
    if (ctx->r8 == 0) {
        // 0x8004BACC: nop
    
            goto L_8004BB10;
    }
    // 0x8004BACC: nop

    // 0x8004BAD0: lh          $t1, 0xE2($a0)
    ctx->r9 = MEM_H(ctx->r4, 0XE2);
L_8004BAD4:
    // 0x8004BAD4: andi        $t2, $t1, 0x10
    ctx->r10 = ctx->r9 & 0X10;
    // 0x8004BAD8: bnel        $t2, $zero, L_8004BB04
    if (ctx->r10 != 0) {
        // 0x8004BADC: lw          $a0, 0x0($a0)
        ctx->r4 = MEM_W(ctx->r4, 0X0);
            goto L_8004BB04;
    }
    goto skip_7;
    // 0x8004BADC: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    skip_7:
    // 0x8004BAE0: lw          $t3, 0xC($a0)
    ctx->r11 = MEM_W(ctx->r4, 0XC);
    // 0x8004BAE4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8004BAE8: sw          $t3, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r11;
    // 0x8004BAEC: lh          $v0, 0xE2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0XE2);
    // 0x8004BAF0: andi        $t4, $v0, 0xF
    ctx->r12 = ctx->r2 & 0XF;
    // 0x8004BAF4: bne         $t4, $zero, L_8004BB00
    if (ctx->r12 != 0) {
        // 0x8004BAF8: ori         $t5, $v0, 0x80
        ctx->r13 = ctx->r2 | 0X80;
            goto L_8004BB00;
    }
    // 0x8004BAF8: ori         $t5, $v0, 0x80
    ctx->r13 = ctx->r2 | 0X80;
    // 0x8004BAFC: sh          $t5, 0xE2($a0)
    MEM_H(0XE2, ctx->r4) = ctx->r13;
L_8004BB00:
    // 0x8004BB00: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
L_8004BB04:
    // 0x8004BB04: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8004BB08: bnel        $t6, $zero, L_8004BAD4
    if (ctx->r14 != 0) {
        // 0x8004BB0C: lh          $t1, 0xE2($a0)
        ctx->r9 = MEM_H(ctx->r4, 0XE2);
            goto L_8004BAD4;
    }
    goto skip_8;
    // 0x8004BB0C: lh          $t1, 0xE2($a0)
    ctx->r9 = MEM_H(ctx->r4, 0XE2);
    skip_8:
L_8004BB10:
    // 0x8004BB10: lw          $t7, -0x4A4C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4A4C);
    // 0x8004BB14: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x8004BB18: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8004BB1C: beq         $t8, $zero, L_8004BB54
    if (ctx->r24 == 0) {
        // 0x8004BB20: nop
    
            goto L_8004BB54;
    }
    // 0x8004BB20: nop

    // 0x8004BB24: lw          $t9, 0xC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC);
L_8004BB28:
    // 0x8004BB28: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8004BB2C: sw          $t9, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r25;
    // 0x8004BB30: lh          $v0, 0xE2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0XE2);
    // 0x8004BB34: andi        $t0, $v0, 0xF
    ctx->r8 = ctx->r2 & 0XF;
    // 0x8004BB38: bne         $t0, $zero, L_8004BB44
    if (ctx->r8 != 0) {
        // 0x8004BB3C: ori         $t1, $v0, 0x80
        ctx->r9 = ctx->r2 | 0X80;
            goto L_8004BB44;
    }
    // 0x8004BB3C: ori         $t1, $v0, 0x80
    ctx->r9 = ctx->r2 | 0X80;
    // 0x8004BB40: sh          $t1, 0xE2($a0)
    MEM_H(0XE2, ctx->r4) = ctx->r9;
L_8004BB44:
    // 0x8004BB44: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x8004BB48: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8004BB4C: bnel        $t2, $zero, L_8004BB28
    if (ctx->r10 != 0) {
        // 0x8004BB50: lw          $t9, 0xC($a0)
        ctx->r25 = MEM_W(ctx->r4, 0XC);
            goto L_8004BB28;
    }
    goto skip_9;
    // 0x8004BB50: lw          $t9, 0xC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC);
    skip_9:
L_8004BB54:
    // 0x8004BB54: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004BB58: addiu       $v1, $v1, -0x4A60
    ctx->r3 = ADD32(ctx->r3, -0X4A60);
    // 0x8004BB5C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8004BB60: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x8004BB64: lw          $t3, -0x4A54($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4A54);
    // 0x8004BB68: lw          $t5, 0xC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC);
    // 0x8004BB6C: sw          $t3, 0xD0($t5)
    MEM_W(0XD0, ctx->r13) = ctx->r11;
    // 0x8004BB70: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8004BB74: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8004BB78: sw          $s1, 0xD4($t7)
    MEM_W(0XD4, ctx->r15) = ctx->r17;
    // 0x8004BB7C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8004BB80: lw          $v0, 0x8($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X8);
    // 0x8004BB84: lw          $t9, 0xD8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XD8);
    // 0x8004BB88: ori         $t0, $t9, 0x3
    ctx->r8 = ctx->r25 | 0X3;
    // 0x8004BB8C: b           L_8004BBAC
    // 0x8004BB90: sw          $t0, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r8;
        goto L_8004BBAC;
    // 0x8004BB90: sw          $t0, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r8;
L_8004BB94:
    // 0x8004BB94: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8004BB98: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004BB9C: lw          $v0, 0x8($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X8);
    // 0x8004BBA0: lw          $t2, 0xD8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XD8);
    // 0x8004BBA4: and         $t4, $t2, $at
    ctx->r12 = ctx->r10 & ctx->r1;
    // 0x8004BBA8: sw          $t4, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r12;
L_8004BBAC:
    // 0x8004BBAC: beq         $s2, $zero, L_8004BCBC
    if (ctx->r18 == 0) {
        // 0x8004BBB0: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_8004BCBC;
    }
    // 0x8004BBB0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004BBB4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8004BBB8: sll         $t3, $s2, 16
    ctx->r11 = S32(ctx->r18 << 16);
    // 0x8004BBBC: sra         $s2, $t3, 16
    ctx->r18 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8004BBC0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004BBC4: lui         $s1, 0x8007
    ctx->r17 = S32(0X8007 << 16);
    // 0x8004BBC8: addiu       $s1, $s1, -0x4498
    ctx->r17 = ADD32(ctx->r17, -0X4498);
    // 0x8004BBCC: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8004BBD0: jal         0x80004364
    // 0x8004BBD4: sll         $a1, $s2, 3
    ctx->r5 = S32(ctx->r18 << 3);
    func_80004364(rdram, ctx);
        goto after_5;
    // 0x8004BBD4: sll         $a1, $s2, 3
    ctx->r5 = S32(ctx->r18 << 3);
    after_5:
    // 0x8004BBD8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004BBDC: sw          $v0, -0x4A44($at)
    MEM_W(-0X4A44, ctx->r1) = ctx->r2;
    // 0x8004BBE0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8004BBE4: jal         0x800022F0
    // 0x8004BBE8: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    func_800022F0(rdram, ctx);
        goto after_6;
    // 0x8004BBE8: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    after_6:
    // 0x8004BBEC: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8004BBF0: jal         0x80004EF0
    // 0x8004BBF4: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    func_80004EF0(rdram, ctx);
        goto after_7;
    // 0x8004BBF4: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    after_7:
    // 0x8004BBF8: addiu       $t6, $sp, 0x30
    ctx->r14 = ADD32(ctx->r29, 0X30);
    // 0x8004BBFC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8004BC00: sw          $s1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r17;
    // 0x8004BC04: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8004BC08: lw          $t7, -0x4A5C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4A5C);
    // 0x8004BC0C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004BC10: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8004BC14: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x8004BC18: addiu       $v1, $v1, -0x4A50
    ctx->r3 = ADD32(ctx->r3, -0X4A50);
    // 0x8004BC1C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8004BC20: beql        $t8, $zero, L_8004BC88
    if (ctx->r24 == 0) {
        // 0x8004BC24: lw          $t9, 0x0($v1)
        ctx->r25 = MEM_W(ctx->r3, 0X0);
            goto L_8004BC88;
    }
    goto skip_10;
    // 0x8004BC24: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    skip_10:
    // 0x8004BC28: lh          $v0, 0xE2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0XE2);
L_8004BC2C:
    // 0x8004BC2C: andi        $t9, $v0, 0x10
    ctx->r25 = ctx->r2 & 0X10;
    // 0x8004BC30: beq         $t9, $zero, L_8004BC74
    if (ctx->r25 == 0) {
        // 0x8004BC34: andi        $t0, $v0, 0x20
        ctx->r8 = ctx->r2 & 0X20;
            goto L_8004BC74;
    }
    // 0x8004BC34: andi        $t0, $v0, 0x20
    ctx->r8 = ctx->r2 & 0X20;
    // 0x8004BC38: beq         $t0, $zero, L_8004BC50
    if (ctx->r8 == 0) {
        // 0x8004BC3C: addiu       $t4, $a0, 0x98
        ctx->r12 = ADD32(ctx->r4, 0X98);
            goto L_8004BC50;
    }
    // 0x8004BC3C: addiu       $t4, $a0, 0x98
    ctx->r12 = ADD32(ctx->r4, 0X98);
    // 0x8004BC40: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x8004BC44: sll         $t1, $s2, 16
    ctx->r9 = S32(ctx->r18 << 16);
    // 0x8004BC48: b           L_8004BC74
    // 0x8004BC4C: sra         $s2, $t1, 16
    ctx->r18 = S32(SIGNED(ctx->r9) >> 16);
        goto L_8004BC74;
    // 0x8004BC4C: sra         $s2, $t1, 16
    ctx->r18 = S32(SIGNED(ctx->r9) >> 16);
L_8004BC50:
    // 0x8004BC50: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8004BC54: lw          $t3, 0xC($a0)
    ctx->r11 = MEM_W(ctx->r4, 0XC);
    // 0x8004BC58: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8004BC5C: sw          $t3, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r11;
    // 0x8004BC60: lh          $v0, 0xE2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0XE2);
    // 0x8004BC64: andi        $t5, $v0, 0xF
    ctx->r13 = ctx->r2 & 0XF;
    // 0x8004BC68: bne         $t5, $zero, L_8004BC74
    if (ctx->r13 != 0) {
        // 0x8004BC6C: ori         $t6, $v0, 0x80
        ctx->r14 = ctx->r2 | 0X80;
            goto L_8004BC74;
    }
    // 0x8004BC6C: ori         $t6, $v0, 0x80
    ctx->r14 = ctx->r2 | 0X80;
    // 0x8004BC70: sh          $t6, 0xE2($a0)
    MEM_H(0XE2, ctx->r4) = ctx->r14;
L_8004BC74:
    // 0x8004BC74: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x8004BC78: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8004BC7C: bnel        $t7, $zero, L_8004BC2C
    if (ctx->r15 != 0) {
        // 0x8004BC80: lh          $v0, 0xE2($a0)
        ctx->r2 = MEM_H(ctx->r4, 0XE2);
            goto L_8004BC2C;
    }
    goto skip_11;
    // 0x8004BC80: lh          $v0, 0xE2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0XE2);
    skip_11:
    // 0x8004BC84: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
L_8004BC88:
    // 0x8004BC88: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8004BC8C: lw          $t8, -0x4A44($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4A44);
    // 0x8004BC90: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x8004BC94: sw          $t8, 0xD0($t0)
    MEM_W(0XD0, ctx->r8) = ctx->r24;
    // 0x8004BC98: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8004BC9C: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8004BCA0: sw          $s2, 0xD4($t2)
    MEM_W(0XD4, ctx->r10) = ctx->r18;
    // 0x8004BCA4: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8004BCA8: lw          $v0, 0x8($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X8);
    // 0x8004BCAC: lw          $t3, 0xD8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XD8);
    // 0x8004BCB0: ori         $t5, $t3, 0x3
    ctx->r13 = ctx->r11 | 0X3;
    // 0x8004BCB4: b           L_8004BCD8
    // 0x8004BCB8: sw          $t5, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r13;
        goto L_8004BCD8;
    // 0x8004BCB8: sw          $t5, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r13;
L_8004BCBC:
    // 0x8004BCBC: addiu       $v1, $v1, -0x4A50
    ctx->r3 = ADD32(ctx->r3, -0X4A50);
    // 0x8004BCC0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8004BCC4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004BCC8: lw          $v0, 0x8($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X8);
    // 0x8004BCCC: lw          $t7, 0xD8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XD8);
    // 0x8004BCD0: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x8004BCD4: sw          $t9, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r25;
L_8004BCD8:
    // 0x8004BCD8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8004BCDC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004BCE0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8004BCE4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8004BCE8: jr          $ra
    // 0x8004BCEC: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    TRACE_RETURN()
    return;
    // 0x8004BCEC: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void func_8004BCF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004BCF0: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x8004BCF4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8004BCF8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8004BCFC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8004BD00: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004BD04: sw          $a0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r4;
    // 0x8004BD08: sw          $a1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r5;
    // 0x8004BD0C: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    // 0x8004BD10: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8004BD14: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8004BD18: beq         $t6, $zero, L_8004BD68
    if (ctx->r14 == 0) {
        // 0x8004BD1C: or          $t4, $zero, $zero
        ctx->r12 = 0 | 0;
            goto L_8004BD68;
    }
    // 0x8004BD1C: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8004BD20: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x8004BD24: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
L_8004BD28:
    // 0x8004BD28: bne         $v1, $v0, L_8004BD40
    if (ctx->r3 != ctx->r2) {
        // 0x8004BD2C: addiu       $t4, $t4, 0x1
        ctx->r12 = ADD32(ctx->r12, 0X1);
            goto L_8004BD40;
    }
    // 0x8004BD2C: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x8004BD30: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8004BD34: sll         $t7, $s2, 16
    ctx->r15 = S32(ctx->r18 << 16);
    // 0x8004BD38: b           L_8004BD4C
    // 0x8004BD3C: sra         $s2, $t7, 16
    ctx->r18 = S32(SIGNED(ctx->r15) >> 16);
        goto L_8004BD4C;
    // 0x8004BD3C: sra         $s2, $t7, 16
    ctx->r18 = S32(SIGNED(ctx->r15) >> 16);
L_8004BD40:
    // 0x8004BD40: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8004BD44: sll         $t9, $s0, 16
    ctx->r25 = S32(ctx->r16 << 16);
    // 0x8004BD48: sra         $s0, $t9, 16
    ctx->r16 = S32(SIGNED(ctx->r25) >> 16);
L_8004BD4C:
    // 0x8004BD4C: sll         $t7, $t4, 16
    ctx->r15 = S32(ctx->r12 << 16);
    // 0x8004BD50: sra         $t4, $t7, 16
    ctx->r12 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8004BD54: addu        $t9, $t4, $a2
    ctx->r25 = ADD32(ctx->r12, ctx->r6);
    // 0x8004BD58: lbu         $v0, 0x0($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X0);
    // 0x8004BD5C: bne         $v0, $zero, L_8004BD28
    if (ctx->r2 != 0) {
        // 0x8004BD60: nop
    
            goto L_8004BD28;
    }
    // 0x8004BD60: nop

    // 0x8004BD64: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
L_8004BD68:
    // 0x8004BD68: sll         $s1, $s0, 16
    ctx->r17 = S32(ctx->r16 << 16);
    // 0x8004BD6C: sra         $t6, $s1, 16
    ctx->r14 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8004BD70: andi        $t7, $s0, 0x1
    ctx->r15 = ctx->r16 & 0X1;
    // 0x8004BD74: beq         $t7, $zero, L_8004BD88
    if (ctx->r15 == 0) {
        // 0x8004BD78: or          $s1, $t6, $zero
        ctx->r17 = ctx->r14 | 0;
            goto L_8004BD88;
    }
    // 0x8004BD78: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x8004BD7C: addiu       $s1, $s0, 0x1
    ctx->r17 = ADD32(ctx->r16, 0X1);
    // 0x8004BD80: sll         $t8, $s1, 16
    ctx->r24 = S32(ctx->r17 << 16);
    // 0x8004BD84: sra         $s1, $t8, 16
    ctx->r17 = S32(SIGNED(ctx->r24) >> 16);
L_8004BD88:
    // 0x8004BD88: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004BD8C: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8004BD90: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8004BD94: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8004BD98: sw          $a2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r6;
    // 0x8004BD9C: jal         0x80004364
    // 0x8004BDA0: sh          $t4, 0xB8($sp)
    MEM_H(0XB8, ctx->r29) = ctx->r12;
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x8004BDA0: sh          $t4, 0xB8($sp)
    MEM_H(0XB8, ctx->r29) = ctx->r12;
    after_0:
    // 0x8004BDA4: lw          $a2, 0xC8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC8);
    // 0x8004BDA8: lh          $t4, 0xB8($sp)
    ctx->r12 = MEM_H(ctx->r29, 0XB8);
    // 0x8004BDAC: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x8004BDB0: blez        $s0, L_8004BDE0
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8004BDB4: sw          $v0, 0x88($sp)
        MEM_W(0X88, ctx->r29) = ctx->r2;
            goto L_8004BDE0;
    }
    // 0x8004BDB4: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
L_8004BDB8:
    // 0x8004BDB8: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x8004BDBC: sll         $t7, $t4, 16
    ctx->r15 = S32(ctx->r12 << 16);
    // 0x8004BDC0: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    // 0x8004BDC4: sra         $t4, $t7, 16
    ctx->r12 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8004BDC8: slt         $at, $t4, $s0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8004BDCC: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x8004BDD0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8004BDD4: bne         $at, $zero, L_8004BDB8
    if (ctx->r1 != 0) {
        // 0x8004BDD8: sb          $t6, -0x1($t3)
        MEM_B(-0X1, ctx->r11) = ctx->r14;
            goto L_8004BDB8;
    }
    // 0x8004BDD8: sb          $t6, -0x1($t3)
    MEM_B(-0X1, ctx->r11) = ctx->r14;
    // 0x8004BDDC: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
L_8004BDE0:
    // 0x8004BDE0: beq         $s0, $s1, L_8004BDF0
    if (ctx->r16 == ctx->r17) {
        // 0x8004BDE4: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8004BDF0;
    }
    // 0x8004BDE4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004BDE8: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x8004BDEC: sb          $t9, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r25;
L_8004BDF0:
    // 0x8004BDF0: lh          $v0, -0x4A2C($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X4A2C);
    // 0x8004BDF4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8004BDF8: lh          $t6, -0x4A30($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X4A30);
    // 0x8004BDFC: multu       $v0, $s1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004BE00: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004BE04: bgez        $v0, L_8004BE14
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8004BE08: sra         $t7, $v0, 1
        ctx->r15 = S32(SIGNED(ctx->r2) >> 1);
            goto L_8004BE14;
    }
    // 0x8004BE08: sra         $t7, $v0, 1
    ctx->r15 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8004BE0C: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x8004BE10: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_8004BE14:
    // 0x8004BE14: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8004BE18: lh          $v1, -0x4A2A($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X4A2A);
    // 0x8004BE1C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8004BE20: lh          $t9, -0x4A2E($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X4A2E);
    // 0x8004BE24: sh          $t8, 0xA8($sp)
    MEM_H(0XA8, ctx->r29) = ctx->r24;
    // 0x8004BE28: bgez        $v1, L_8004BE38
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8004BE2C: sra         $t6, $v1, 1
        ctx->r14 = S32(SIGNED(ctx->r3) >> 1);
            goto L_8004BE38;
    }
    // 0x8004BE2C: sra         $t6, $v1, 1
    ctx->r14 = S32(SIGNED(ctx->r3) >> 1);
    // 0x8004BE30: addiu       $at, $v1, 0x1
    ctx->r1 = ADD32(ctx->r3, 0X1);
    // 0x8004BE34: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_8004BE38:
    // 0x8004BE38: mflo        $t8
    ctx->r24 = lo;
    // 0x8004BE3C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004BE40: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x8004BE44: sh          $t7, 0xA6($sp)
    MEM_H(0XA6, ctx->r29) = ctx->r15;
    // 0x8004BE48: sh          $t8, 0xA4($sp)
    MEM_H(0XA4, ctx->r29) = ctx->r24;
    // 0x8004BE4C: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8004BE50: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    // 0x8004BE54: sh          $t4, 0xB8($sp)
    MEM_H(0XB8, ctx->r29) = ctx->r12;
    // 0x8004BE58: jal         0x80004364
    // 0x8004BE5C: sh          $v1, 0xA2($sp)
    MEM_H(0XA2, ctx->r29) = ctx->r3;
    func_80004364(rdram, ctx);
        goto after_1;
    // 0x8004BE5C: sh          $v1, 0xA2($sp)
    MEM_H(0XA2, ctx->r29) = ctx->r3;
    after_1:
    // 0x8004BE60: lh          $t9, 0xC2($sp)
    ctx->r25 = MEM_H(ctx->r29, 0XC2);
    // 0x8004BE64: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
    // 0x8004BE68: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8004BE6C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004BE70: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x8004BE74: sh          $t6, 0xE2($v0)
    MEM_H(0XE2, ctx->r2) = ctx->r14;
    // 0x8004BE78: sh          $t7, 0xDC($v0)
    MEM_H(0XDC, ctx->r2) = ctx->r15;
    // 0x8004BE7C: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8004BE80: jal         0x80004364
    // 0x8004BE84: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_80004364(rdram, ctx);
        goto after_2;
    // 0x8004BE84: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_2:
    // 0x8004BE88: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x8004BE8C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004BE90: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8004BE94: sw          $v0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r2;
    // 0x8004BE98: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8004BE9C: sw          $v0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r2;
    // 0x8004BEA0: sll         $t9, $a1, 5
    ctx->r25 = S32(ctx->r5 << 5);
    // 0x8004BEA4: jal         0x80004364
    // 0x8004BEA8: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    func_80004364(rdram, ctx);
        goto after_3;
    // 0x8004BEA8: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_3:
    // 0x8004BEAC: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
    // 0x8004BEB0: lh          $t4, 0xB8($sp)
    ctx->r12 = MEM_H(ctx->r29, 0XB8);
    // 0x8004BEB4: lw          $t5, 0x98($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X98);
    // 0x8004BEB8: sw          $v0, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r2;
    // 0x8004BEBC: lw          $t3, 0x88($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X88);
    // 0x8004BEC0: blez        $s1, L_8004BF88
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8004BEC4: or          $ra, $zero, $zero
        ctx->r31 = 0 | 0;
            goto L_8004BF88;
    }
    // 0x8004BEC4: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x8004BEC8: or          $t2, $s1, $zero
    ctx->r10 = ctx->r17 | 0;
    // 0x8004BECC: sll         $t7, $t2, 17
    ctx->r15 = S32(ctx->r10 << 17);
    // 0x8004BED0: sra         $t2, $t7, 16
    ctx->r10 = S32(SIGNED(ctx->r15) >> 16);
L_8004BED4:
    // 0x8004BED4: lbu         $a0, 0x0($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X0);
    // 0x8004BED8: sll         $t9, $ra, 1
    ctx->r25 = S32(ctx->r31 << 1);
    // 0x8004BEDC: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x8004BEE0: addiu       $a0, $a0, -0x20
    ctx->r4 = ADD32(ctx->r4, -0X20);
    // 0x8004BEE4: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x8004BEE8: andi        $t6, $v1, 0xFFF8
    ctx->r14 = ctx->r3 & 0XFFF8;
    // 0x8004BEEC: sll         $t7, $t6, 20
    ctx->r15 = S32(ctx->r14 << 20);
    // 0x8004BEF0: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8004BEF4: andi        $t7, $v1, 0x7
    ctx->r15 = ctx->r3 & 0X7;
    // 0x8004BEF8: sll         $t8, $t7, 17
    ctx->r24 = S32(ctx->r15 << 17);
    // 0x8004BEFC: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8004BF00: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x8004BF04: addiu       $t7, $t7, -0x4320
    ctx->r15 = ADD32(ctx->r15, -0X4320);
    // 0x8004BF08: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x8004BF0C: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x8004BF10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004BF14: addu        $t1, $t6, $t7
    ctx->r9 = ADD32(ctx->r14, ctx->r15);
    // 0x8004BF18: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8004BF1C:
    // 0x8004BF1C: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x8004BF20: sll         $t9, $a1, 1
    ctx->r25 = S32(ctx->r5 << 1);
    // 0x8004BF24: addu        $a0, $t1, $t9
    ctx->r4 = ADD32(ctx->r9, ctx->r25);
    // 0x8004BF28: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x8004BF2C: addu        $v1, $t0, $t8
    ctx->r3 = ADD32(ctx->r8, ctx->r24);
    // 0x8004BF30: addu        $a2, $a2, $t2
    ctx->r6 = ADD32(ctx->r6, ctx->r10);
    // 0x8004BF34: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x8004BF38: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8004BF3C: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8004BF40: sll         $t8, $a3, 16
    ctx->r24 = S32(ctx->r7 << 16);
    // 0x8004BF44: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
    // 0x8004BF48: lhu         $t7, 0x2($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X2);
    // 0x8004BF4C: sra         $a3, $t8, 16
    ctx->r7 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8004BF50: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x8004BF54: slti        $at, $a3, 0x8
    ctx->r1 = SIGNED(ctx->r7) < 0X8 ? 1 : 0;
    // 0x8004BF58: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x8004BF5C: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8004BF60: bne         $at, $zero, L_8004BF1C
    if (ctx->r1 != 0) {
        // 0x8004BF64: sh          $t7, 0x2($v1)
        MEM_H(0X2, ctx->r3) = ctx->r15;
            goto L_8004BF1C;
    }
    // 0x8004BF64: sh          $t7, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r15;
    // 0x8004BF68: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x8004BF6C: sll         $t8, $t4, 16
    ctx->r24 = S32(ctx->r12 << 16);
    // 0x8004BF70: sra         $t4, $t8, 16
    ctx->r12 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8004BF74: addiu       $ra, $ra, 0x2
    ctx->r31 = ADD32(ctx->r31, 0X2);
    // 0x8004BF78: slt         $at, $t4, $s1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8004BF7C: sll         $t6, $ra, 16
    ctx->r14 = S32(ctx->r31 << 16);
    // 0x8004BF80: bne         $at, $zero, L_8004BED4
    if (ctx->r1 != 0) {
        // 0x8004BF84: sra         $ra, $t6, 16
        ctx->r31 = S32(SIGNED(ctx->r14) >> 16);
            goto L_8004BED4;
    }
    // 0x8004BF84: sra         $ra, $t6, 16
    ctx->r31 = S32(SIGNED(ctx->r14) >> 16);
L_8004BF88:
    // 0x8004BF88: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004BF8C: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8004BF90: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
    // 0x8004BF94: jal         0x800042A8
    // 0x8004BF98: sw          $t5, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r13;
    func_800042A8(rdram, ctx);
        goto after_4;
    // 0x8004BF98: sw          $t5, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r13;
    after_4:
    // 0x8004BF9C: lw          $t5, 0x98($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X98);
    // 0x8004BFA0: lh          $t0, 0xA8($sp)
    ctx->r8 = MEM_H(ctx->r29, 0XA8);
    // 0x8004BFA4: lh          $t2, 0xA6($sp)
    ctx->r10 = MEM_H(ctx->r29, 0XA6);
    // 0x8004BFA8: addiu       $a2, $zero, 0x7E
    ctx->r6 = ADD32(0, 0X7E);
    // 0x8004BFAC: sh          $zero, 0x4($t5)
    MEM_H(0X4, ctx->r13) = 0;
    // 0x8004BFB0: sh          $zero, 0x6($t5)
    MEM_H(0X6, ctx->r13) = 0;
    // 0x8004BFB4: sh          $zero, 0x8($t5)
    MEM_H(0X8, ctx->r13) = 0;
    // 0x8004BFB8: sh          $zero, 0xA($t5)
    MEM_H(0XA, ctx->r13) = 0;
    // 0x8004BFBC: sb          $zero, 0xC($t5)
    MEM_B(0XC, ctx->r13) = 0;
    // 0x8004BFC0: sb          $zero, 0xD($t5)
    MEM_B(0XD, ctx->r13) = 0;
    // 0x8004BFC4: sb          $a2, 0xE($t5)
    MEM_B(0XE, ctx->r13) = ctx->r6;
    // 0x8004BFC8: sh          $t0, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r8;
    // 0x8004BFCC: sh          $t2, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r10;
    // 0x8004BFD0: lh          $v0, 0xC2($sp)
    ctx->r2 = MEM_H(ctx->r29, 0XC2);
    // 0x8004BFD4: addiu       $a3, $zero, 0x200
    ctx->r7 = ADD32(0, 0X200);
    // 0x8004BFD8: addiu       $t5, $t5, 0x30
    ctx->r13 = ADD32(ctx->r13, 0X30);
    // 0x8004BFDC: sra         $t7, $v0, 8
    ctx->r15 = S32(SIGNED(ctx->r2) >> 8);
    // 0x8004BFE0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8004BFE4: sb          $v0, -0x21($t5)
    MEM_B(-0X21, ctx->r13) = ctx->r2;
    // 0x8004BFE8: lh          $t9, 0xA4($sp)
    ctx->r25 = MEM_H(ctx->r29, 0XA4);
    // 0x8004BFEC: sll         $t7, $s1, 19
    ctx->r15 = S32(ctx->r17 << 19);
    // 0x8004BFF0: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8004BFF4: addu        $v1, $t0, $t9
    ctx->r3 = ADD32(ctx->r8, ctx->r25);
    // 0x8004BFF8: sh          $v1, -0x20($t5)
    MEM_H(-0X20, ctx->r13) = ctx->r3;
    // 0x8004BFFC: lh          $t6, 0xA2($sp)
    ctx->r14 = MEM_H(ctx->r29, 0XA2);
    // 0x8004C000: sll         $a1, $t8, 6
    ctx->r5 = S32(ctx->r24 << 6);
    // 0x8004C004: sh          $zero, -0x1C($t5)
    MEM_H(-0X1C, ctx->r13) = 0;
    // 0x8004C008: subu        $a0, $t2, $t6
    ctx->r4 = SUB32(ctx->r10, ctx->r14);
    // 0x8004C00C: sh          $a0, -0x1E($t5)
    MEM_H(-0X1E, ctx->r13) = ctx->r4;
    // 0x8004C010: sh          $a0, -0xE($t5)
    MEM_H(-0XE, ctx->r13) = ctx->r4;
    // 0x8004C014: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004C018: sh          $zero, -0x1A($t5)
    MEM_H(-0X1A, ctx->r13) = 0;
    // 0x8004C01C: sh          $a1, -0x18($t5)
    MEM_H(-0X18, ctx->r13) = ctx->r5;
    // 0x8004C020: sh          $a3, -0x16($t5)
    MEM_H(-0X16, ctx->r13) = ctx->r7;
    // 0x8004C024: sb          $zero, -0x14($t5)
    MEM_B(-0X14, ctx->r13) = 0;
    // 0x8004C028: sb          $zero, -0x13($t5)
    MEM_B(-0X13, ctx->r13) = 0;
    // 0x8004C02C: sb          $a2, -0x12($t5)
    MEM_B(-0X12, ctx->r13) = ctx->r6;
    // 0x8004C030: sb          $v0, -0x11($t5)
    MEM_B(-0X11, ctx->r13) = ctx->r2;
    // 0x8004C034: sh          $zero, -0xC($t5)
    MEM_H(-0XC, ctx->r13) = 0;
    // 0x8004C038: sh          $zero, -0xA($t5)
    MEM_H(-0XA, ctx->r13) = 0;
    // 0x8004C03C: sh          $zero, -0x8($t5)
    MEM_H(-0X8, ctx->r13) = 0;
    // 0x8004C040: sh          $a3, -0x6($t5)
    MEM_H(-0X6, ctx->r13) = ctx->r7;
    // 0x8004C044: sb          $zero, -0x4($t5)
    MEM_B(-0X4, ctx->r13) = 0;
    // 0x8004C048: sb          $zero, -0x3($t5)
    MEM_B(-0X3, ctx->r13) = 0;
    // 0x8004C04C: sb          $a2, -0x2($t5)
    MEM_B(-0X2, ctx->r13) = ctx->r6;
    // 0x8004C050: sb          $v0, -0x1($t5)
    MEM_B(-0X1, ctx->r13) = ctx->r2;
    // 0x8004C054: sh          $v1, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r3;
    // 0x8004C058: sh          $zero, 0x4($t5)
    MEM_H(0X4, ctx->r13) = 0;
    // 0x8004C05C: sh          $zero, 0x6($t5)
    MEM_H(0X6, ctx->r13) = 0;
    // 0x8004C060: sh          $a1, 0x8($t5)
    MEM_H(0X8, ctx->r13) = ctx->r5;
    // 0x8004C064: sh          $zero, 0xA($t5)
    MEM_H(0XA, ctx->r13) = 0;
    // 0x8004C068: sb          $zero, 0xC($t5)
    MEM_B(0XC, ctx->r13) = 0;
    // 0x8004C06C: sb          $zero, 0xD($t5)
    MEM_B(0XD, ctx->r13) = 0;
    // 0x8004C070: sb          $a2, 0xE($t5)
    MEM_B(0XE, ctx->r13) = ctx->r6;
    // 0x8004C074: sb          $v0, 0xF($t5)
    MEM_B(0XF, ctx->r13) = ctx->r2;
    // 0x8004C078: sh          $t0, -0x10($t5)
    MEM_H(-0X10, ctx->r13) = ctx->r8;
    // 0x8004C07C: sh          $t2, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r10;
    // 0x8004C080: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x8004C084: addiu       $a1, $zero, 0x88
    ctx->r5 = ADD32(0, 0X88);
    // 0x8004C088: jal         0x80004364
    // 0x8004C08C: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    func_80004364(rdram, ctx);
        goto after_5;
    // 0x8004C08C: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    after_5:
    // 0x8004C090: lw          $a2, 0x8C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8C);
    // 0x8004C094: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8004C098: lui         $t9, 0xFD10
    ctx->r25 = S32(0XFD10 << 16);
    // 0x8004C09C: sw          $v0, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r2;
    // 0x8004C0A0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8004C0A4: lh          $t6, 0xC6($sp)
    ctx->r14 = MEM_H(ctx->r29, 0XC6);
    // 0x8004C0A8: lui         $t8, 0x8007
    ctx->r24 = S32(0X8007 << 16);
    // 0x8004C0AC: addiu       $t8, $t8, -0x43A0
    ctx->r24 = ADD32(ctx->r24, -0X43A0);
    // 0x8004C0B0: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x8004C0B4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8004C0B8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8004C0BC: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x8004C0C0: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x8004C0C4: lui         $t9, 0x703
    ctx->r25 = S32(0X703 << 16);
    // 0x8004C0C8: lui         $t7, 0xF500
    ctx->r15 = S32(0XF500 << 16);
    // 0x8004C0CC: lui         $a1, 0xE600
    ctx->r5 = S32(0XE600 << 16);
    // 0x8004C0D0: lui         $t5, 0x700
    ctx->r13 = S32(0X700 << 16);
    // 0x8004C0D4: lui         $ra, 0xE700
    ctx->r31 = S32(0XE700 << 16);
    // 0x8004C0D8: ori         $t7, $t7, 0x100
    ctx->r15 = ctx->r15 | 0X100;
    // 0x8004C0DC: ori         $t9, $t9, 0xC000
    ctx->r25 = ctx->r25 | 0XC000;
    // 0x8004C0E0: lui         $t8, 0xF000
    ctx->r24 = S32(0XF000 << 16);
    // 0x8004C0E4: lui         $t6, 0xFD50
    ctx->r14 = S32(0XFD50 << 16);
    // 0x8004C0E8: sw          $t8, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r24;
    // 0x8004C0EC: sw          $t9, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r25;
    // 0x8004C0F0: sw          $t7, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r15;
    // 0x8004C0F4: sw          $ra, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r31;
    // 0x8004C0F8: sw          $t5, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r13;
    // 0x8004C0FC: sw          $a1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r5;
    // 0x8004C100: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x8004C104: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x8004C108: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x8004C10C: sw          $t6, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r14;
    // 0x8004C110: lw          $t7, 0x10($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X10);
    // 0x8004C114: sll         $a0, $t1, 3
    ctx->r4 = S32(ctx->r9 << 3);
    // 0x8004C118: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x8004C11C: sra         $t6, $a0, 2
    ctx->r14 = S32(SIGNED(ctx->r4) >> 2);
    // 0x8004C120: addiu       $a0, $t6, -0x1
    ctx->r4 = ADD32(ctx->r14, -0X1);
    // 0x8004C124: slti        $at, $a0, 0x7FF
    ctx->r1 = SIGNED(ctx->r4) < 0X7FF ? 1 : 0;
    // 0x8004C128: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x8004C12C: lui         $t8, 0xF550
    ctx->r24 = S32(0XF550 << 16);
    // 0x8004C130: sw          $t8, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r24;
    // 0x8004C134: sw          $t9, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r25;
    // 0x8004C138: sw          $zero, 0x44($v0)
    MEM_W(0X44, ctx->r2) = 0;
    // 0x8004C13C: sw          $a1, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r5;
    // 0x8004C140: sw          $t5, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r13;
    // 0x8004C144: addiu       $t2, $v0, 0x50
    ctx->r10 = ADD32(ctx->r2, 0X50);
    // 0x8004C148: beq         $at, $zero, L_8004C158
    if (ctx->r1 == 0) {
        // 0x8004C14C: sw          $t7, 0x34($v0)
        MEM_W(0X34, ctx->r2) = ctx->r15;
            goto L_8004C158;
    }
    // 0x8004C14C: sw          $t7, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r15;
    // 0x8004C150: b           L_8004C15C
    // 0x8004C154: or          $t3, $a0, $zero
    ctx->r11 = ctx->r4 | 0;
        goto L_8004C15C;
    // 0x8004C154: or          $t3, $a0, $zero
    ctx->r11 = ctx->r4 | 0;
L_8004C158:
    // 0x8004C158: addiu       $t3, $zero, 0x7FF
    ctx->r11 = ADD32(0, 0X7FF);
L_8004C15C:
    // 0x8004C15C: bgez        $t1, L_8004C16C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8004C160: sra         $v1, $t1, 4
        ctx->r3 = S32(SIGNED(ctx->r9) >> 4);
            goto L_8004C16C;
    }
    // 0x8004C160: sra         $v1, $t1, 4
    ctx->r3 = S32(SIGNED(ctx->r9) >> 4);
    // 0x8004C164: addiu       $at, $t1, 0xF
    ctx->r1 = ADD32(ctx->r9, 0XF);
    // 0x8004C168: sra         $v1, $at, 4
    ctx->r3 = S32(SIGNED(ctx->r1) >> 4);
L_8004C16C:
    // 0x8004C16C: bgtz        $v1, L_8004C17C
    if (SIGNED(ctx->r3) > 0) {
        // 0x8004C170: or          $t4, $v1, $zero
        ctx->r12 = ctx->r3 | 0;
            goto L_8004C17C;
    }
    // 0x8004C170: or          $t4, $v1, $zero
    ctx->r12 = ctx->r3 | 0;
    // 0x8004C174: b           L_8004C17C
    // 0x8004C178: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
        goto L_8004C17C;
    // 0x8004C178: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
L_8004C17C:
    // 0x8004C17C: bgtz        $v1, L_8004C18C
    if (SIGNED(ctx->r3) > 0) {
        // 0x8004C180: addiu       $t7, $t4, 0x7FF
        ctx->r15 = ADD32(ctx->r12, 0X7FF);
            goto L_8004C18C;
    }
    // 0x8004C180: addiu       $t7, $t4, 0x7FF
    ctx->r15 = ADD32(ctx->r12, 0X7FF);
    // 0x8004C184: b           L_8004C190
    // 0x8004C188: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_8004C190;
    // 0x8004C188: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8004C18C:
    // 0x8004C18C: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
L_8004C190:
    // 0x8004C190: div         $zero, $t7, $a3
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r7)));
    // 0x8004C194: mflo        $t8
    ctx->r24 = lo;
    // 0x8004C198: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8004C19C: bne         $a3, $zero, L_8004C1A8
    if (ctx->r7 != 0) {
        // 0x8004C1A0: nop
    
            goto L_8004C1A8;
    }
    // 0x8004C1A0: nop

    // 0x8004C1A4: break       7
    do_break(2147795364);
L_8004C1A8:
    // 0x8004C1A8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004C1AC: bne         $a3, $at, L_8004C1C0
    if (ctx->r7 != ctx->r1) {
        // 0x8004C1B0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8004C1C0;
    }
    // 0x8004C1B0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8004C1B4: bne         $t7, $at, L_8004C1C0
    if (ctx->r15 != ctx->r1) {
        // 0x8004C1B8: nop
    
            goto L_8004C1C0;
    }
    // 0x8004C1B8: nop

    // 0x8004C1BC: break       6
    do_break(2147795388);
L_8004C1C0:
    // 0x8004C1C0: andi        $t7, $t3, 0xFFF
    ctx->r15 = ctx->r11 & 0XFFF;
    // 0x8004C1C4: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x8004C1C8: or          $t6, $t9, $t5
    ctx->r14 = ctx->r25 | ctx->r13;
    // 0x8004C1CC: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8004C1D0: sra         $t7, $t1, 1
    ctx->r15 = S32(SIGNED(ctx->r9) >> 1);
    // 0x8004C1D4: addiu       $t6, $t7, 0x7
    ctx->r14 = ADD32(ctx->r15, 0X7);
    // 0x8004C1D8: sra         $t8, $t6, 3
    ctx->r24 = S32(SIGNED(ctx->r14) >> 3);
    // 0x8004C1DC: sw          $t9, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->r25;
    // 0x8004C1E0: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x8004C1E4: addiu       $v1, $t2, 0x8
    ctx->r3 = ADD32(ctx->r10, 0X8);
    // 0x8004C1E8: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8004C1EC: sll         $t7, $t9, 9
    ctx->r15 = S32(ctx->r25 << 9);
    // 0x8004C1F0: lui         $at, 0xF540
    ctx->r1 = S32(0XF540 << 16);
    // 0x8004C1F4: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x8004C1F8: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8004C1FC: sw          $ra, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r31;
    // 0x8004C200: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8004C204: addiu       $t9, $t1, -0x1
    ctx->r25 = ADD32(ctx->r9, -0X1);
    // 0x8004C208: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8004C20C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8004C210: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8004C214: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x8004C218: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8004C21C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8004C220: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8004C224: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x8004C228: ori         $t9, $t8, 0x1C
    ctx->r25 = ctx->r24 | 0X1C;
    // 0x8004C22C: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x8004C230: lw          $a3, 0x8C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X8C);
    // 0x8004C234: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8004C238: lui         $t7, 0x430
    ctx->r15 = S32(0X430 << 16);
    // 0x8004C23C: ori         $t7, $t7, 0x40
    ctx->r15 = ctx->r15 | 0X40;
    // 0x8004C240: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x8004C244: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x8004C248: lw          $t6, 0x8($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X8);
    // 0x8004C24C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8004C250: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8004C254: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8004C258: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x8004C25C: lui         $a2, 0xBF00
    ctx->r6 = S32(0XBF00 << 16);
    // 0x8004C260: addiu       $t8, $zero, 0xA14
    ctx->r24 = ADD32(0, 0XA14);
    // 0x8004C264: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8004C268: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8004C26C: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x8004C270: lui         $t9, 0xA
    ctx->r25 = S32(0XA << 16);
    // 0x8004C274: ori         $t9, $t9, 0x1E
    ctx->r25 = ctx->r25 | 0X1E;
    // 0x8004C278: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8004C27C: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x8004C280: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8004C284: lui         $t7, 0xB800
    ctx->r15 = S32(0XB800 << 16);
    // 0x8004C288: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8004C28C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8004C290: beq         $s2, $zero, L_8004C2D0
    if (ctx->r18 == 0) {
        // 0x8004C294: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_8004C2D0;
    }
    // 0x8004C294: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8004C298: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8004C29C: lh          $t9, -0x4A2A($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X4A2A);
    // 0x8004C2A0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8004C2A4: lh          $t6, -0x4A34($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X4A34);
    // 0x8004C2A8: multu       $t9, $s2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004C2AC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004C2B0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004C2B4: addiu       $v0, $v0, -0x4A2E
    ctx->r2 = ADD32(ctx->r2, -0X4A2E);
    // 0x8004C2B8: sh          $t6, -0x4A30($at)
    MEM_H(-0X4A30, ctx->r1) = ctx->r14;
    // 0x8004C2BC: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x8004C2C0: mflo        $t7
    ctx->r15 = lo;
    // 0x8004C2C4: subu        $t6, $t8, $t7
    ctx->r14 = SUB32(ctx->r24, ctx->r15);
    // 0x8004C2C8: b           L_8004C2F4
    // 0x8004C2CC: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
        goto L_8004C2F4;
    // 0x8004C2CC: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
L_8004C2D0:
    // 0x8004C2D0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8004C2D4: lh          $t8, -0x4A2C($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X4A2C);
    // 0x8004C2D8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004C2DC: addiu       $v0, $v0, -0x4A30
    ctx->r2 = ADD32(ctx->r2, -0X4A30);
    // 0x8004C2E0: multu       $t8, $s0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004C2E4: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x8004C2E8: mflo        $t7
    ctx->r15 = lo;
    // 0x8004C2EC: addu        $t6, $t9, $t7
    ctx->r14 = ADD32(ctx->r25, ctx->r15);
    // 0x8004C2F0: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
L_8004C2F4:
    // 0x8004C2F4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004C2F8: addiu       $v1, $v1, -0x4A48
    ctx->r3 = ADD32(ctx->r3, -0X4A48);
    // 0x8004C2FC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8004C300: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8004C304: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8004C308: sw          $a3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r7;
    // 0x8004C30C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8004C310: lw          $t6, 0x4($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X4);
    // 0x8004C314: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
    // 0x8004C318: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8004C31C: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8004C320: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8004C324: sw          $a3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r7;
    // 0x8004C328: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8004C32C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8004C330: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8004C334: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004C338: jr          $ra
    // 0x8004C33C: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    TRACE_RETURN()
    return;
    // 0x8004C33C: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void func_8004C340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004C340: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x8004C344: sw          $a1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r5;
    // 0x8004C348: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004C34C: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    // 0x8004C350: sw          $a2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r6;
    // 0x8004C354: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8004C358: sw          $a3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r7;
    // 0x8004C35C: addiu       $a2, $sp, 0xA4
    ctx->r6 = ADD32(ctx->r29, 0XA4);
    // 0x8004C360: jal         0x80006D70
    // 0x8004C364: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_80006D70(rdram, ctx);
        goto after_0;
    // 0x8004C364: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x8004C368: lh          $a0, 0x9A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X9A);
    // 0x8004C36C: lh          $a1, 0x9E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X9E);
    // 0x8004C370: jal         0x8004BCF0
    // 0x8004C374: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    func_8004BCF0(rdram, ctx);
        goto after_1;
    // 0x8004C374: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x8004C378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004C37C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    // 0x8004C380: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8004C388(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004C388: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8004C38C: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x8004C390: sll         $t0, $a2, 16
    ctx->r8 = S32(ctx->r6 << 16);
    // 0x8004C394: sra         $t1, $t0, 16
    ctx->r9 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8004C398: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8004C39C: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8004C3A0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8004C3A4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8004C3A8: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x8004C3AC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8004C3B0: beq         $t1, $zero, L_8004C3F8
    if (ctx->r9 == 0) {
        // 0x8004C3B4: sw          $a2, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r6;
            goto L_8004C3F8;
    }
    // 0x8004C3B4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8004C3B8: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x8004C3BC: lh          $t2, -0x4A2C($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X4A2C);
    // 0x8004C3C0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8004C3C4: lh          $t6, -0x4A28($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X4A28);
    // 0x8004C3C8: multu       $t7, $t2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004C3CC: negu        $t5, $t9
    ctx->r13 = SUB32(0, ctx->r25);
    // 0x8004C3D0: mflo        $v0
    ctx->r2 = lo;
    // 0x8004C3D4: addiu       $v0, $v0, -0x8A
    ctx->r2 = ADD32(ctx->r2, -0X8A);
    // 0x8004C3D8: sll         $t3, $v0, 16
    ctx->r11 = S32(ctx->r2 << 16);
    // 0x8004C3DC: multu       $t5, $t6
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004C3E0: sra         $v0, $t3, 16
    ctx->r2 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8004C3E4: mflo        $v1
    ctx->r3 = lo;
    // 0x8004C3E8: addiu       $v1, $v1, 0x6C
    ctx->r3 = ADD32(ctx->r3, 0X6C);
    // 0x8004C3EC: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x8004C3F0: b           L_8004C410
    // 0x8004C3F4: sra         $v1, $t7, 16
    ctx->r3 = S32(SIGNED(ctx->r15) >> 16);
        goto L_8004C410;
    // 0x8004C3F4: sra         $v1, $t7, 16
    ctx->r3 = S32(SIGNED(ctx->r15) >> 16);
L_8004C3F8:
    // 0x8004C3F8: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x8004C3FC: sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5 << 16);
    // 0x8004C400: sra         $t9, $v0, 16
    ctx->r25 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8004C404: sra         $t0, $v1, 16
    ctx->r8 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8004C408: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8004C40C: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_8004C410:
    // 0x8004C410: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8004C414: addiu       $a0, $a0, -0x4A30
    ctx->r4 = ADD32(ctx->r4, -0X4A30);
    // 0x8004C418: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x8004C41C: lh          $t1, 0x0($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X0);
    // 0x8004C420: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8004C424: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004C428: addiu       $a1, $a1, -0x4A2E
    ctx->r5 = ADD32(ctx->r5, -0X4A2E);
    // 0x8004C42C: sh          $t1, -0x4A34($at)
    MEM_H(-0X4A34, ctx->r1) = ctx->r9;
    // 0x8004C430: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
    // 0x8004C434: lh          $t2, 0x0($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X0);
    // 0x8004C438: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004C43C: jr          $ra
    // 0x8004C440: sh          $t2, -0x4A32($at)
    MEM_H(-0X4A32, ctx->r1) = ctx->r10;
    TRACE_RETURN()
    return;
    // 0x8004C440: sh          $t2, -0x4A32($at)
    MEM_H(-0X4A32, ctx->r1) = ctx->r10;
;}
RECOMP_FUNC void func_8004C444(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004C444: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004C448: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004C44C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004C450: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8004C454: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x8004C458: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8004C45C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8004C460: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8004C464: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8004C468: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x8004C46C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004C470: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8004C474: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8004C478: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x8004C47C: jal         0x8001026C
    // 0x8004C480: addiu       $a2, $a2, -0x6C60
    ctx->r6 = ADD32(ctx->r6, -0X6C60);
    func_8001026C(rdram, ctx);
        goto after_0;
    // 0x8004C480: addiu       $a2, $a2, -0x6C60
    ctx->r6 = ADD32(ctx->r6, -0X6C60);
    after_0:
    // 0x8004C484: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004C488: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8004C48C: addiu       $a2, $a2, -0x6C60
    ctx->r6 = ADD32(ctx->r6, -0X6C60);
    // 0x8004C490: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8004C494: jal         0x8001026C
    // 0x8004C498: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    func_8001026C(rdram, ctx);
        goto after_1;
    // 0x8004C498: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    after_1:
    // 0x8004C49C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004C4A0: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8004C4A4: addiu       $a2, $a2, -0x6C60
    ctx->r6 = ADD32(ctx->r6, -0X6C60);
    // 0x8004C4A8: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8004C4AC: jal         0x8001026C
    // 0x8004C4B0: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    func_8001026C(rdram, ctx);
        goto after_2;
    // 0x8004C4B0: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    after_2:
    // 0x8004C4B4: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004C4B8: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    // 0x8004C4BC: jal         0x800042A8
    // 0x8004C4C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800042A8(rdram, ctx);
        goto after_3;
    // 0x8004C4C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x8004C4C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004C4C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004C4CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004C4D0: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8004C4D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004C4D8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004C4DC: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8004C4E0: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8004C4E4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8004C4E8: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x8004C4EC: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8004C4F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004C4F4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8004C4F8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8004C4FC: beq         $t7, $zero, L_8004C518
    if (ctx->r15 == 0) {
        // 0x8004C500: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_8004C518;
    }
    // 0x8004C500: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8004C504: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004C508: beq         $t7, $at, L_8004C528
    if (ctx->r15 == ctx->r1) {
        // 0x8004C50C: lui         $t1, 0x8013
        ctx->r9 = S32(0X8013 << 16);
            goto L_8004C528;
    }
    // 0x8004C50C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8004C510: b           L_8004C530
    // 0x8004C514: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
        goto L_8004C530;
    // 0x8004C514: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
L_8004C518:
    // 0x8004C518: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8004C51C: lw          $t0, -0x4A5C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4A5C);
    // 0x8004C520: b           L_8004C530
    // 0x8004C524: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
        goto L_8004C530;
    // 0x8004C524: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
L_8004C528:
    // 0x8004C528: lw          $t1, -0x4A4C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4A4C);
    // 0x8004C52C: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
L_8004C530:
    // 0x8004C530: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8004C534: andi        $s1, $a1, 0xF
    ctx->r17 = ctx->r5 & 0XF;
    // 0x8004C538: beql        $t2, $zero, L_8004C570
    if (ctx->r10 == 0) {
        // 0x8004C53C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8004C570;
    }
    goto skip_0;
    // 0x8004C53C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8004C540: lh          $t3, 0xE2($a0)
    ctx->r11 = MEM_H(ctx->r4, 0XE2);
L_8004C544:
    // 0x8004C544: lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X0);
    // 0x8004C548: andi        $t4, $t3, 0xF
    ctx->r12 = ctx->r11 & 0XF;
    // 0x8004C54C: bnel        $s1, $t4, L_8004C560
    if (ctx->r17 != ctx->r12) {
        // 0x8004C550: lw          $t5, 0x0($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X0);
            goto L_8004C560;
    }
    goto skip_1;
    // 0x8004C550: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x8004C554: jal         0x8004C444
    // 0x8004C558: nop

    func_8004C444(rdram, ctx);
        goto after_0;
    // 0x8004C558: nop

    after_0:
    // 0x8004C55C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
L_8004C560:
    // 0x8004C560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004C564: bnel        $t5, $zero, L_8004C544
    if (ctx->r13 != 0) {
        // 0x8004C568: lh          $t3, 0xE2($a0)
        ctx->r11 = MEM_H(ctx->r4, 0XE2);
            goto L_8004C544;
    }
    goto skip_2;
    // 0x8004C568: lh          $t3, 0xE2($a0)
    ctx->r11 = MEM_H(ctx->r4, 0XE2);
    skip_2:
    // 0x8004C56C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004C570:
    // 0x8004C570: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8004C574: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8004C578: jr          $ra
    // 0x8004C57C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    TRACE_RETURN()
    return;
    // 0x8004C57C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8004C580(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004C580: addiu       $sp, $sp, -0x330
    ctx->r29 = ADD32(ctx->r29, -0X330);
    // 0x8004C584: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8004C588: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004C58C: lw          $v0, -0x4A24($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4A24);
    // 0x8004C590: sll         $fp, $a2, 16
    ctx->r30 = S32(ctx->r6 << 16);
    // 0x8004C594: sll         $t7, $a3, 16
    ctx->r15 = S32(ctx->r7 << 16);
    // 0x8004C598: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8004C59C: sra         $t6, $fp, 16
    ctx->r14 = S32(SIGNED(ctx->r30) >> 16);
    // 0x8004C5A0: or          $fp, $t6, $zero
    ctx->r30 = ctx->r14 | 0;
    // 0x8004C5A4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8004C5A8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8004C5AC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8004C5B0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8004C5B4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8004C5B8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8004C5BC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8004C5C0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8004C5C4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8004C5C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004C5CC: sw          $a0, 0x330($sp)
    MEM_W(0X330, ctx->r29) = ctx->r4;
    // 0x8004C5D0: sw          $a1, 0x334($sp)
    MEM_W(0X334, ctx->r29) = ctx->r5;
    // 0x8004C5D4: sw          $a2, 0x338($sp)
    MEM_W(0X338, ctx->r29) = ctx->r6;
    // 0x8004C5D8: sw          $a3, 0x33C($sp)
    MEM_W(0X33C, ctx->r29) = ctx->r7;
    // 0x8004C5DC: addu        $t6, $v0, $t9
    ctx->r14 = ADD32(ctx->r2, ctx->r25);
    // 0x8004C5E0: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x8004C5E4: lui         $s7, 0x801A
    ctx->r23 = S32(0X801A << 16);
    // 0x8004C5E8: addiu       $s7, $s7, 0x2800
    ctx->r23 = ADD32(ctx->r23, 0X2800);
    // 0x8004C5EC: bne         $v1, $zero, L_8004C5FC
    if (ctx->r3 != 0) {
        // 0x8004C5F0: addu        $a3, $v1, $v0
        ctx->r7 = ADD32(ctx->r3, ctx->r2);
            goto L_8004C5FC;
    }
    // 0x8004C5F0: addu        $a3, $v1, $v0
    ctx->r7 = ADD32(ctx->r3, ctx->r2);
    // 0x8004C5F4: b           L_8004D010
    // 0x8004C5F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8004D010;
    // 0x8004C5F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004C5FC:
    // 0x8004C5FC: lh          $s6, 0x4($a3)
    ctx->r22 = MEM_H(ctx->r7, 0X4);
    // 0x8004C600: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004C604: lh          $s4, 0x0($a3)
    ctx->r20 = MEM_H(ctx->r7, 0X0);
    // 0x8004C608: bne         $s6, $at, L_8004C61C
    if (ctx->r22 != ctx->r1) {
        // 0x8004C60C: lh          $t4, 0x2($a3)
        ctx->r12 = MEM_H(ctx->r7, 0X2);
            goto L_8004C61C;
    }
    // 0x8004C60C: lh          $t4, 0x2($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X2);
    // 0x8004C610: addiu       $a0, $zero, 0x800
    ctx->r4 = ADD32(0, 0X800);
    // 0x8004C614: b           L_8004C624
    // 0x8004C618: addiu       $s1, $zero, 0x100
    ctx->r17 = ADD32(0, 0X100);
        goto L_8004C624;
    // 0x8004C618: addiu       $s1, $zero, 0x100
    ctx->r17 = ADD32(0, 0X100);
L_8004C61C:
    // 0x8004C61C: addiu       $a0, $zero, 0x1000
    ctx->r4 = ADD32(0, 0X1000);
    // 0x8004C620: addiu       $s1, $zero, 0x10
    ctx->r17 = ADD32(0, 0X10);
L_8004C624:
    // 0x8004C624: multu       $s4, $t4
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004C628: mflo        $t7
    ctx->r15 = lo;
    // 0x8004C62C: slt         $at, $a0, $t7
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8004C630: beq         $at, $zero, L_8004C6E0
    if (ctx->r1 == 0) {
        // 0x8004C634: or          $t8, $s4, $zero
        ctx->r24 = ctx->r20 | 0;
            goto L_8004C6E0;
    }
    // 0x8004C634: or          $t8, $s4, $zero
    ctx->r24 = ctx->r20 | 0;
    // 0x8004C638: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x8004C63C: subu        $t6, $t9, $t8
    ctx->r14 = SUB32(ctx->r25, ctx->r24);
    // 0x8004C640: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x8004C644: addu        $s3, $s4, $t7
    ctx->r19 = ADD32(ctx->r20, ctx->r15);
    // 0x8004C648: sll         $t9, $s3, 16
    ctx->r25 = S32(ctx->r19 << 16);
    // 0x8004C64C: sra         $t8, $t9, 16
    ctx->r24 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8004C650: div         $zero, $a0, $t8
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r24))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r24)));
    // 0x8004C654: mflo        $v0
    ctx->r2 = lo;
    // 0x8004C658: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x8004C65C: sra         $t7, $v1, 16
    ctx->r15 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8004C660: div         $zero, $t4, $t7
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r15)));
    // 0x8004C664: mflo        $a1
    ctx->r5 = lo;
    // 0x8004C668: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x8004C66C: or          $s3, $t8, $zero
    ctx->r19 = ctx->r24 | 0;
    // 0x8004C670: multu       $v1, $a1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004C674: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x8004C678: bne         $s3, $zero, L_8004C684
    if (ctx->r19 != 0) {
        // 0x8004C67C: nop
    
            goto L_8004C684;
    }
    // 0x8004C67C: nop

    // 0x8004C680: break       7
    do_break(2147796608);
L_8004C684:
    // 0x8004C684: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004C688: bne         $s3, $at, L_8004C69C
    if (ctx->r19 != ctx->r1) {
        // 0x8004C68C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8004C69C;
    }
    // 0x8004C68C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8004C690: bne         $a0, $at, L_8004C69C
    if (ctx->r4 != ctx->r1) {
        // 0x8004C694: nop
    
            goto L_8004C69C;
    }
    // 0x8004C694: nop

    // 0x8004C698: break       6
    do_break(2147796632);
L_8004C69C:
    // 0x8004C69C: sra         $t6, $s0, 16
    ctx->r14 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8004C6A0: mflo        $t9
    ctx->r25 = lo;
    // 0x8004C6A4: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x8004C6A8: bne         $v1, $zero, L_8004C6B4
    if (ctx->r3 != 0) {
        // 0x8004C6AC: nop
    
            goto L_8004C6B4;
    }
    // 0x8004C6AC: nop

    // 0x8004C6B0: break       7
    do_break(2147796656);
L_8004C6B4:
    // 0x8004C6B4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004C6B8: bne         $v1, $at, L_8004C6CC
    if (ctx->r3 != ctx->r1) {
        // 0x8004C6BC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8004C6CC;
    }
    // 0x8004C6BC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8004C6C0: bne         $t4, $at, L_8004C6CC
    if (ctx->r12 != ctx->r1) {
        // 0x8004C6C4: nop
    
            goto L_8004C6CC;
    }
    // 0x8004C6C4: nop

    // 0x8004C6C8: break       6
    do_break(2147796680);
L_8004C6CC:
    // 0x8004C6CC: sw          $a1, 0x2E0($sp)
    MEM_W(0X2E0, ctx->r29) = ctx->r5;
    // 0x8004C6D0: beq         $t4, $t9, L_8004C70C
    if (ctx->r12 == ctx->r25) {
        // 0x8004C6D4: addiu       $t8, $a1, 0x1
        ctx->r24 = ADD32(ctx->r5, 0X1);
            goto L_8004C70C;
    }
    // 0x8004C6D4: addiu       $t8, $a1, 0x1
    ctx->r24 = ADD32(ctx->r5, 0X1);
    // 0x8004C6D8: b           L_8004C70C
    // 0x8004C6DC: sw          $t8, 0x2E0($sp)
    MEM_W(0X2E0, ctx->r29) = ctx->r24;
        goto L_8004C70C;
    // 0x8004C6DC: sw          $t8, 0x2E0($sp)
    MEM_W(0X2E0, ctx->r29) = ctx->r24;
L_8004C6E0:
    // 0x8004C6E0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8004C6E4: sll         $s0, $t4, 16
    ctx->r16 = S32(ctx->r12 << 16);
    // 0x8004C6E8: sw          $t6, 0x2E0($sp)
    MEM_W(0X2E0, ctx->r29) = ctx->r14;
    // 0x8004C6EC: sra         $t7, $s0, 16
    ctx->r15 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8004C6F0: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x8004C6F4: subu        $t6, $t8, $s4
    ctx->r14 = SUB32(ctx->r24, ctx->r20);
    // 0x8004C6F8: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x8004C6FC: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x8004C700: addu        $s3, $s4, $t7
    ctx->r19 = ADD32(ctx->r20, ctx->r15);
    // 0x8004C704: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x8004C708: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
L_8004C70C:
    // 0x8004C70C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8004C710: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    // 0x8004C714: sw          $a3, 0x304($sp)
    MEM_W(0X304, ctx->r29) = ctx->r7;
    // 0x8004C718: jal         0x80004364
    // 0x8004C71C: sh          $t4, 0x328($sp)
    MEM_H(0X328, ctx->r29) = ctx->r12;
    func_80004364(rdram, ctx);
        goto after_0;
    // 0x8004C71C: sh          $t4, 0x328($sp)
    MEM_H(0X328, ctx->r29) = ctx->r12;
    after_0:
    // 0x8004C720: lw          $a3, 0x304($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X304);
    // 0x8004C724: lh          $t4, 0x328($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X328);
    // 0x8004C728: sw          $v0, 0x32C($sp)
    MEM_W(0X32C, ctx->r29) = ctx->r2;
    // 0x8004C72C: andi        $t6, $fp, 0xFF
    ctx->r14 = ctx->r30 & 0XFF;
    // 0x8004C730: sh          $t6, 0xE2($v0)
    MEM_H(0XE2, ctx->r2) = ctx->r14;
    // 0x8004C734: sh          $s4, 0xD8($v0)
    MEM_H(0XD8, ctx->r2) = ctx->r20;
    // 0x8004C738: sh          $s6, 0xDC($v0)
    MEM_H(0XDC, ctx->r2) = ctx->r22;
    // 0x8004C73C: sh          $t4, 0xDA($v0)
    MEM_H(0XDA, ctx->r2) = ctx->r12;
    // 0x8004C740: lhu         $t7, 0x6($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X6);
    // 0x8004C744: lh          $t9, 0xE2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XE2);
    // 0x8004C748: sh          $t7, 0xDE($v0)
    MEM_H(0XDE, ctx->r2) = ctx->r15;
    // 0x8004C74C: lw          $t8, 0x2E0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2E0);
    // 0x8004C750: andi        $t6, $t9, 0x10
    ctx->r14 = ctx->r25 & 0X10;
    // 0x8004C754: beq         $t6, $zero, L_8004C784
    if (ctx->r14 == 0) {
        // 0x8004C758: sh          $t8, 0xE0($v0)
        MEM_H(0XE0, ctx->r2) = ctx->r24;
            goto L_8004C784;
    }
    // 0x8004C758: sh          $t8, 0xE0($v0)
    MEM_H(0XE0, ctx->r2) = ctx->r24;
    // 0x8004C75C: lw          $a0, 0x32C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X32C);
    // 0x8004C760: sw          $a3, 0x304($sp)
    MEM_W(0X304, ctx->r29) = ctx->r7;
    // 0x8004C764: sh          $t4, 0x328($sp)
    MEM_H(0X328, ctx->r29) = ctx->r12;
    // 0x8004C768: jal         0x800022F0
    // 0x8004C76C: addiu       $a0, $a0, 0x54
    ctx->r4 = ADD32(ctx->r4, 0X54);
    func_800022F0(rdram, ctx);
        goto after_1;
    // 0x8004C76C: addiu       $a0, $a0, 0x54
    ctx->r4 = ADD32(ctx->r4, 0X54);
    after_1:
    // 0x8004C770: lw          $a0, 0x32C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X32C);
    // 0x8004C774: jal         0x800022F0
    // 0x8004C778: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    func_800022F0(rdram, ctx);
        goto after_2;
    // 0x8004C778: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_2:
    // 0x8004C77C: lw          $a3, 0x304($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X304);
    // 0x8004C780: lh          $t4, 0x328($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X328);
L_8004C784:
    // 0x8004C784: multu       $s3, $t4
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004C788: sll         $s5, $s1, 1
    ctx->r21 = S32(ctx->r17 << 1);
    // 0x8004C78C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8004C790: sw          $a3, 0x304($sp)
    MEM_W(0X304, ctx->r29) = ctx->r7;
    // 0x8004C794: sh          $t4, 0x328($sp)
    MEM_H(0X328, ctx->r29) = ctx->r12;
    // 0x8004C798: mflo        $t7
    ctx->r15 = lo;
    // 0x8004C79C: nop

    // 0x8004C7A0: nop

    // 0x8004C7A4: div         $zero, $t7, $s6
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r22))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r22)));
    // 0x8004C7A8: mflo        $t8
    ctx->r24 = lo;
    // 0x8004C7AC: addu        $s2, $t8, $s5
    ctx->r18 = ADD32(ctx->r24, ctx->r21);
    // 0x8004C7B0: bne         $s6, $zero, L_8004C7BC
    if (ctx->r22 != 0) {
        // 0x8004C7B4: nop
    
            goto L_8004C7BC;
    }
    // 0x8004C7B4: nop

    // 0x8004C7B8: break       7
    do_break(2147796920);
L_8004C7BC:
    // 0x8004C7BC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004C7C0: bne         $s6, $at, L_8004C7D4
    if (ctx->r22 != ctx->r1) {
        // 0x8004C7C4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8004C7D4;
    }
    // 0x8004C7C4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8004C7C8: bne         $t7, $at, L_8004C7D4
    if (ctx->r15 != ctx->r1) {
        // 0x8004C7CC: nop
    
            goto L_8004C7D4;
    }
    // 0x8004C7CC: nop

    // 0x8004C7D0: break       6
    do_break(2147796944);
L_8004C7D4:
    // 0x8004C7D4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8004C7D8: jal         0x80004364
    // 0x8004C7DC: nop

    func_80004364(rdram, ctx);
        goto after_3;
    // 0x8004C7DC: nop

    after_3:
    // 0x8004C7E0: lw          $t9, 0x32C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X32C);
    // 0x8004C7E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8004C7E8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8004C7EC: sw          $v0, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->r2;
    // 0x8004C7F0: jal         0x8000C7C0
    // 0x8004C7F4: sw          $v0, 0x308($sp)
    MEM_W(0X308, ctx->r29) = ctx->r2;
    func_8000C7C0(rdram, ctx);
        goto after_4;
    // 0x8004C7F4: sw          $v0, 0x308($sp)
    MEM_W(0X308, ctx->r29) = ctx->r2;
    after_4:
    // 0x8004C7F8: lw          $a3, 0x304($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X304);
    // 0x8004C7FC: lw          $t2, 0x308($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X308);
    // 0x8004C800: lh          $t4, 0x328($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X328);
    // 0x8004C804: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x8004C808: sh          $s6, 0x31A($sp)
    MEM_H(0X31A, ctx->r29) = ctx->r22;
    // 0x8004C80C: blez        $s1, L_8004C848
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8004C810: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8004C848;
    }
    // 0x8004C810: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
L_8004C814:
    // 0x8004C814: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x8004C818: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x8004C81C: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x8004C820: sll         $t9, $t5, 16
    ctx->r25 = S32(ctx->r13 << 16);
    // 0x8004C824: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x8004C828: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8004C82C: slt         $at, $t6, $s1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8004C830: or          $t5, $t6, $zero
    ctx->r13 = ctx->r14 | 0;
    // 0x8004C834: addiu       $t2, $t2, 0x2
    ctx->r10 = ADD32(ctx->r10, 0X2);
    // 0x8004C838: bne         $at, $zero, L_8004C814
    if (ctx->r1 != 0) {
        // 0x8004C83C: sh          $t8, -0x2($t2)
        MEM_H(-0X2, ctx->r10) = ctx->r24;
            goto L_8004C814;
    }
    // 0x8004C83C: sh          $t8, -0x2($t2)
    MEM_H(-0X2, ctx->r10) = ctx->r24;
    // 0x8004C840: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x8004C844: sh          $s6, 0x31A($sp)
    MEM_H(0X31A, ctx->r29) = ctx->r22;
L_8004C848:
    // 0x8004C848: addu        $a3, $s5, $a3
    ctx->r7 = ADD32(ctx->r21, ctx->r7);
    // 0x8004C84C: blez        $t4, L_8004C91C
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8004C850: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8004C91C;
    }
    // 0x8004C850: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004C854: lh          $s1, 0x31A($sp)
    ctx->r17 = MEM_H(ctx->r29, 0X31A);
    // 0x8004C858: div         $zero, $s4, $s1
    lo = S32(S64(S32(ctx->r20)) / S64(S32(ctx->r17))); hi = S32(S64(S32(ctx->r20)) % S64(S32(ctx->r17)));
    // 0x8004C85C: mflo        $a1
    ctx->r5 = lo;
    // 0x8004C860: bne         $s1, $zero, L_8004C86C
    if (ctx->r17 != 0) {
        // 0x8004C864: nop
    
            goto L_8004C86C;
    }
    // 0x8004C864: nop

    // 0x8004C868: break       7
    do_break(2147797096);
L_8004C86C:
    // 0x8004C86C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004C870: bne         $s1, $at, L_8004C884
    if (ctx->r17 != ctx->r1) {
        // 0x8004C874: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8004C884;
    }
    // 0x8004C874: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8004C878: bne         $s4, $at, L_8004C884
    if (ctx->r20 != ctx->r1) {
        // 0x8004C87C: nop
    
            goto L_8004C884;
    }
    // 0x8004C87C: nop

    // 0x8004C880: break       6
    do_break(2147797120);
L_8004C884:
    // 0x8004C884: blez        $a1, L_8004C904
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8004C888: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8004C904;
    }
    // 0x8004C888: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8004C88C: multu       $a2, $a1
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004C890: mflo        $v1
    ctx->r3 = lo;
    // 0x8004C894: nop

    // 0x8004C898: nop

    // 0x8004C89C: div         $zero, $s3, $s1
    lo = S32(S64(S32(ctx->r19)) / S64(S32(ctx->r17))); hi = S32(S64(S32(ctx->r19)) % S64(S32(ctx->r17)));
    // 0x8004C8A0: mflo        $t7
    ctx->r15 = lo;
    // 0x8004C8A4: bne         $s1, $zero, L_8004C8B0
    if (ctx->r17 != 0) {
        // 0x8004C8A8: nop
    
            goto L_8004C8B0;
    }
    // 0x8004C8A8: nop

    // 0x8004C8AC: break       7
    do_break(2147797164);
L_8004C8B0:
    // 0x8004C8B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004C8B4: bne         $s1, $at, L_8004C8C8
    if (ctx->r17 != ctx->r1) {
        // 0x8004C8B8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8004C8C8;
    }
    // 0x8004C8B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8004C8BC: bne         $s3, $at, L_8004C8C8
    if (ctx->r19 != ctx->r1) {
        // 0x8004C8C0: nop
    
            goto L_8004C8C8;
    }
    // 0x8004C8C0: nop

    // 0x8004C8C4: break       6
    do_break(2147797188);
L_8004C8C8:
    // 0x8004C8C8: multu       $a2, $t7
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004C8CC: mflo        $t8
    ctx->r24 = lo;
    // 0x8004C8D0: addu        $a0, $t2, $t8
    ctx->r4 = ADD32(ctx->r10, ctx->r24);
    // 0x8004C8D4: nop

L_8004C8D8:
    // 0x8004C8D8: addu        $t9, $v1, $v0
    ctx->r25 = ADD32(ctx->r3, ctx->r2);
    // 0x8004C8DC: addu        $t6, $t9, $a3
    ctx->r14 = ADD32(ctx->r25, ctx->r7);
    // 0x8004C8E0: addu        $t8, $a0, $v0
    ctx->r24 = ADD32(ctx->r4, ctx->r2);
    // 0x8004C8E4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004C8E8: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8004C8EC: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x8004C8F0: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8004C8F4: slt         $at, $t6, $a1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8004C8F8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8004C8FC: bne         $at, $zero, L_8004C8D8
    if (ctx->r1 != 0) {
        // 0x8004C900: sb          $t7, 0x0($t8)
        MEM_B(0X0, ctx->r24) = ctx->r15;
            goto L_8004C8D8;
    }
    // 0x8004C900: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
L_8004C904:
    // 0x8004C904: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8004C908: sll         $t7, $a2, 16
    ctx->r15 = S32(ctx->r6 << 16);
    // 0x8004C90C: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8004C910: slt         $at, $t8, $t4
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8004C914: bne         $at, $zero, L_8004C884
    if (ctx->r1 != 0) {
        // 0x8004C918: or          $a2, $t8, $zero
        ctx->r6 = ctx->r24 | 0;
            goto L_8004C884;
    }
    // 0x8004C918: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
L_8004C91C:
    // 0x8004C91C: lh          $t9, 0x336($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X336);
    // 0x8004C920: lw          $s2, 0x2E0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2E0);
    // 0x8004C924: lh          $s1, 0x31A($sp)
    ctx->r17 = MEM_H(ctx->r29, 0X31A);
    // 0x8004C928: bgez        $t4, L_8004C938
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8004C92C: sra         $t6, $t4, 1
        ctx->r14 = S32(SIGNED(ctx->r12) >> 1);
            goto L_8004C938;
    }
    // 0x8004C92C: sra         $t6, $t4, 1
    ctx->r14 = S32(SIGNED(ctx->r12) >> 1);
    // 0x8004C930: addiu       $at, $t4, 0x1
    ctx->r1 = ADD32(ctx->r12, 0X1);
    // 0x8004C934: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_8004C938:
    // 0x8004C938: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x8004C93C: sh          $t8, 0x314($sp)
    MEM_H(0X314, ctx->r29) = ctx->r24;
    // 0x8004C940: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8004C944: sw          $t2, 0x308($sp)
    MEM_W(0X308, ctx->r29) = ctx->r10;
    // 0x8004C948: sh          $t4, 0x328($sp)
    MEM_H(0X328, ctx->r29) = ctx->r12;
    // 0x8004C94C: sh          $t5, 0x2FA($sp)
    MEM_H(0X2FA, ctx->r29) = ctx->r13;
    // 0x8004C950: jal         0x80004364
    // 0x8004C954: sll         $a1, $s2, 6
    ctx->r5 = S32(ctx->r18 << 6);
    func_80004364(rdram, ctx);
        goto after_5;
    // 0x8004C954: sll         $a1, $s2, 6
    ctx->r5 = S32(ctx->r18 << 6);
    after_5:
    // 0x8004C958: mtc1        $s4, $f4
    ctx->f4.u32l = ctx->r20;
    // 0x8004C95C: lh          $v1, 0x342($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X342);
    // 0x8004C960: lw          $t9, 0x32C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X32C);
    // 0x8004C964: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8004C968: lh          $a3, 0x314($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X314);
    // 0x8004C96C: lw          $t2, 0x308($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X308);
    // 0x8004C970: lh          $t4, 0x328($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X328);
    // 0x8004C974: lh          $t5, 0x2FA($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X2FA);
    // 0x8004C978: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8004C97C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8004C980: beq         $v1, $zero, L_8004C9A4
    if (ctx->r3 == 0) {
        // 0x8004C984: sw          $v0, 0x8($t9)
        MEM_W(0X8, ctx->r25) = ctx->r2;
            goto L_8004C9A4;
    }
    // 0x8004C984: sw          $v0, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r2;
    // 0x8004C988: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8004C98C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004C990: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x8004C994: div.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8004C998: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8004C99C: mul.s       $f0, $f8, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8004C9A0: nop

L_8004C9A4:
    // 0x8004C9A4: blez        $s2, L_8004CB00
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8004C9A8: sll         $t1, $s4, 6
        ctx->r9 = S32(ctx->r20 << 6);
            goto L_8004CB00;
    }
    // 0x8004C9A8: sll         $t1, $s4, 6
    ctx->r9 = S32(ctx->r20 << 6);
    // 0x8004C9AC: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8004C9B0: lh          $t8, 0x332($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X332);
    // 0x8004C9B4: sra         $a1, $fp, 8
    ctx->r5 = S32(SIGNED(ctx->r30) >> 8);
    // 0x8004C9B8: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x8004C9BC: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8004C9C0: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x8004C9C4: bgez        $s4, L_8004C9D4
    if (SIGNED(ctx->r20) >= 0) {
        // 0x8004C9C8: sra         $t9, $s4, 1
        ctx->r25 = S32(SIGNED(ctx->r20) >> 1);
            goto L_8004C9D4;
    }
    // 0x8004C9C8: sra         $t9, $s4, 1
    ctx->r25 = S32(SIGNED(ctx->r20) >> 1);
    // 0x8004C9CC: addiu       $at, $s4, 0x1
    ctx->r1 = ADD32(ctx->r20, 0X1);
    // 0x8004C9D0: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_8004C9D4:
    // 0x8004C9D4: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x8004C9D8: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x8004C9DC: sll         $t6, $t0, 16
    ctx->r14 = S32(ctx->r8 << 16);
    // 0x8004C9E0: sra         $t0, $t6, 16
    ctx->r8 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8004C9E4: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x8004C9E8: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8004C9EC: addu        $t3, $t0, $t7
    ctx->r11 = ADD32(ctx->r8, ctx->r15);
    // 0x8004C9F0: addiu       $a2, $zero, 0x7E
    ctx->r6 = ADD32(0, 0X7E);
    // 0x8004C9F4: sll         $t8, $t5, 1
    ctx->r24 = S32(ctx->r13 << 1);
L_8004C9F8:
    // 0x8004C9F8: addu        $t9, $sp, $t8
    ctx->r25 = ADD32(ctx->r29, ctx->r24);
    // 0x8004C9FC: sh          $s0, 0xE0($t9)
    MEM_H(0XE0, ctx->r25) = ctx->r16;
    // 0x8004CA00: subu        $t4, $t4, $s0
    ctx->r12 = SUB32(ctx->r12, ctx->r16);
    // 0x8004CA04: sh          $a3, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r7;
    // 0x8004CA08: subu        $v0, $a3, $s0
    ctx->r2 = SUB32(ctx->r7, ctx->r16);
    // 0x8004CA0C: sh          $a3, 0x32($a0)
    MEM_H(0X32, ctx->r4) = ctx->r7;
    // 0x8004CA10: sll         $t7, $t4, 16
    ctx->r15 = S32(ctx->r12 << 16);
    // 0x8004CA14: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x8004CA18: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8004CA1C: sll         $v1, $s0, 6
    ctx->r3 = S32(ctx->r16 << 6);
    // 0x8004CA20: sra         $t6, $a3, 16
    ctx->r14 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8004CA24: slt         $at, $t8, $s0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8004CA28: sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
    // 0x8004CA2C: sh          $zero, 0x4($a0)
    MEM_H(0X4, ctx->r4) = 0;
    // 0x8004CA30: sh          $zero, 0x6($a0)
    MEM_H(0X6, ctx->r4) = 0;
    // 0x8004CA34: sh          $zero, 0x8($a0)
    MEM_H(0X8, ctx->r4) = 0;
    // 0x8004CA38: sh          $zero, 0xA($a0)
    MEM_H(0XA, ctx->r4) = 0;
    // 0x8004CA3C: sb          $zero, 0xC($a0)
    MEM_B(0XC, ctx->r4) = 0;
    // 0x8004CA40: sb          $zero, 0xD($a0)
    MEM_B(0XD, ctx->r4) = 0;
    // 0x8004CA44: sb          $a2, 0xE($a0)
    MEM_B(0XE, ctx->r4) = ctx->r6;
    // 0x8004CA48: sb          $a1, 0xF($a0)
    MEM_B(0XF, ctx->r4) = ctx->r5;
    // 0x8004CA4C: sh          $t3, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r11;
    // 0x8004CA50: sh          $v0, 0x12($a0)
    MEM_H(0X12, ctx->r4) = ctx->r2;
    // 0x8004CA54: sh          $zero, 0x14($a0)
    MEM_H(0X14, ctx->r4) = 0;
    // 0x8004CA58: sh          $zero, 0x16($a0)
    MEM_H(0X16, ctx->r4) = 0;
    // 0x8004CA5C: sh          $t1, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r9;
    // 0x8004CA60: sh          $v1, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r3;
    // 0x8004CA64: sb          $zero, 0x1C($a0)
    MEM_B(0X1C, ctx->r4) = 0;
    // 0x8004CA68: sb          $zero, 0x1D($a0)
    MEM_B(0X1D, ctx->r4) = 0;
    // 0x8004CA6C: sb          $a2, 0x1E($a0)
    MEM_B(0X1E, ctx->r4) = ctx->r6;
    // 0x8004CA70: sb          $a1, 0x1F($a0)
    MEM_B(0X1F, ctx->r4) = ctx->r5;
    // 0x8004CA74: sh          $t0, 0x20($a0)
    MEM_H(0X20, ctx->r4) = ctx->r8;
    // 0x8004CA78: sh          $v0, 0x22($a0)
    MEM_H(0X22, ctx->r4) = ctx->r2;
    // 0x8004CA7C: sh          $zero, 0x24($a0)
    MEM_H(0X24, ctx->r4) = 0;
    // 0x8004CA80: sh          $zero, 0x26($a0)
    MEM_H(0X26, ctx->r4) = 0;
    // 0x8004CA84: sh          $zero, 0x28($a0)
    MEM_H(0X28, ctx->r4) = 0;
    // 0x8004CA88: sh          $v1, 0x2A($a0)
    MEM_H(0X2A, ctx->r4) = ctx->r3;
    // 0x8004CA8C: sb          $zero, 0x2C($a0)
    MEM_B(0X2C, ctx->r4) = 0;
    // 0x8004CA90: sb          $zero, 0x2D($a0)
    MEM_B(0X2D, ctx->r4) = 0;
    // 0x8004CA94: sb          $a2, 0x2E($a0)
    MEM_B(0X2E, ctx->r4) = ctx->r6;
    // 0x8004CA98: sb          $a1, 0x2F($a0)
    MEM_B(0X2F, ctx->r4) = ctx->r5;
    // 0x8004CA9C: sh          $t3, 0x30($a0)
    MEM_H(0X30, ctx->r4) = ctx->r11;
    // 0x8004CAA0: sh          $zero, 0x34($a0)
    MEM_H(0X34, ctx->r4) = 0;
    // 0x8004CAA4: sh          $zero, 0x36($a0)
    MEM_H(0X36, ctx->r4) = 0;
    // 0x8004CAA8: sh          $t1, 0x38($a0)
    MEM_H(0X38, ctx->r4) = ctx->r9;
    // 0x8004CAAC: sh          $zero, 0x3A($a0)
    MEM_H(0X3A, ctx->r4) = 0;
    // 0x8004CAB0: sb          $zero, 0x3C($a0)
    MEM_B(0X3C, ctx->r4) = 0;
    // 0x8004CAB4: sb          $zero, 0x3D($a0)
    MEM_B(0X3D, ctx->r4) = 0;
    // 0x8004CAB8: sb          $a2, 0x3E($a0)
    MEM_B(0X3E, ctx->r4) = ctx->r6;
    // 0x8004CABC: sb          $a1, 0x3F($a0)
    MEM_B(0X3F, ctx->r4) = ctx->r5;
    // 0x8004CAC0: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // 0x8004CAC4: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x8004CAC8: beq         $at, $zero, L_8004CADC
    if (ctx->r1 == 0) {
        // 0x8004CACC: or          $t4, $t8, $zero
        ctx->r12 = ctx->r24 | 0;
            goto L_8004CADC;
    }
    // 0x8004CACC: or          $t4, $t8, $zero
    ctx->r12 = ctx->r24 | 0;
    // 0x8004CAD0: sll         $s0, $t8, 16
    ctx->r16 = S32(ctx->r24 << 16);
    // 0x8004CAD4: sra         $t9, $s0, 16
    ctx->r25 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8004CAD8: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
L_8004CADC:
    // 0x8004CADC: lw          $t8, 0x2E0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2E0);
    // 0x8004CAE0: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x8004CAE4: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x8004CAE8: sra         $t5, $t6, 16
    ctx->r13 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8004CAEC: slt         $at, $t5, $t8
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8004CAF0: bnel        $at, $zero, L_8004C9F8
    if (ctx->r1 != 0) {
        // 0x8004CAF4: sll         $t8, $t5, 1
        ctx->r24 = S32(ctx->r13 << 1);
            goto L_8004C9F8;
    }
    goto skip_0;
    // 0x8004CAF4: sll         $t8, $t5, 1
    ctx->r24 = S32(ctx->r13 << 1);
    skip_0:
    // 0x8004CAF8: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x8004CAFC: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
L_8004CB00:
    // 0x8004CB00: sll         $a1, $s2, 2
    ctx->r5 = S32(ctx->r18 << 2);
    // 0x8004CB04: addu        $a1, $a1, $s2
    ctx->r5 = ADD32(ctx->r5, ctx->r18);
    // 0x8004CB08: sll         $a1, $a1, 4
    ctx->r5 = S32(ctx->r5 << 4);
    // 0x8004CB0C: addiu       $a1, $a1, 0x38
    ctx->r5 = ADD32(ctx->r5, 0X38);
    // 0x8004CB10: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8004CB14: sw          $t2, 0x308($sp)
    MEM_W(0X308, ctx->r29) = ctx->r10;
    // 0x8004CB18: jal         0x80004364
    // 0x8004CB1C: sh          $t5, 0x2FA($sp)
    MEM_H(0X2FA, ctx->r29) = ctx->r13;
    func_80004364(rdram, ctx);
        goto after_6;
    // 0x8004CB1C: sh          $t5, 0x2FA($sp)
    MEM_H(0X2FA, ctx->r29) = ctx->r13;
    after_6:
    // 0x8004CB20: lw          $t3, 0x32C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X32C);
    // 0x8004CB24: lw          $t2, 0x308($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X308);
    // 0x8004CB28: lh          $t5, 0x2FA($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X2FA);
    // 0x8004CB2C: sw          $v0, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r2;
    // 0x8004CB30: lh          $t9, 0x31A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X31A);
    // 0x8004CB34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004CB38: lui         $s2, 0x700
    ctx->r18 = S32(0X700 << 16);
    // 0x8004CB3C: bne         $t9, $at, L_8004CBD0
    if (ctx->r25 != ctx->r1) {
        // 0x8004CB40: lw          $a0, 0x8($t3)
        ctx->r4 = MEM_W(ctx->r11, 0X8);
            goto L_8004CBD0;
    }
    // 0x8004CB40: lw          $a0, 0x8($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X8);
    // 0x8004CB44: lui         $t6, 0xFD10
    ctx->r14 = S32(0XFD10 << 16);
    // 0x8004CB48: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8004CB4C: lw          $t7, 0x10($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X10);
    // 0x8004CB50: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x8004CB54: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8004CB58: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8004CB5C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8004CB60: lui         $t8, 0xE800
    ctx->r24 = S32(0XE800 << 16);
    // 0x8004CB64: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8004CB68: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x8004CB6C: lui         $t9, 0xF500
    ctx->r25 = S32(0XF500 << 16);
    // 0x8004CB70: ori         $t9, $t9, 0x100
    ctx->r25 = ctx->r25 | 0X100;
    // 0x8004CB74: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8004CB78: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x8004CB7C: lui         $s2, 0x700
    ctx->r18 = S32(0X700 << 16);
    // 0x8004CB80: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8004CB84: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x8004CB88: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8004CB8C: sw          $s2, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r18;
    // 0x8004CB90: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x8004CB94: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8004CB98: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x8004CB9C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8004CBA0: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8004CBA4: lui         $t8, 0x73F
    ctx->r24 = S32(0X73F << 16);
    // 0x8004CBA8: ori         $t8, $t8, 0xC000
    ctx->r24 = ctx->r24 | 0XC000;
    // 0x8004CBAC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8004CBB0: lui         $t7, 0xF000
    ctx->r15 = S32(0XF000 << 16);
    // 0x8004CBB4: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8004CBB8: sw          $t8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r24;
    // 0x8004CBBC: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8004CBC0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8004CBC4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8004CBC8: b           L_8004CC54
    // 0x8004CBCC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
        goto L_8004CC54;
    // 0x8004CBCC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_8004CBD0:
    // 0x8004CBD0: lui         $t6, 0xFD10
    ctx->r14 = S32(0XFD10 << 16);
    // 0x8004CBD4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8004CBD8: lw          $t7, 0x10($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X10);
    // 0x8004CBDC: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x8004CBE0: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8004CBE4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8004CBE8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8004CBEC: lui         $t8, 0xE800
    ctx->r24 = S32(0XE800 << 16);
    // 0x8004CBF0: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8004CBF4: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x8004CBF8: lui         $t9, 0xF500
    ctx->r25 = S32(0XF500 << 16);
    // 0x8004CBFC: ori         $t9, $t9, 0x100
    ctx->r25 = ctx->r25 | 0X100;
    // 0x8004CC00: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8004CC04: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x8004CC08: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8004CC0C: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x8004CC10: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8004CC14: sw          $s2, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r18;
    // 0x8004CC18: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x8004CC1C: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8004CC20: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x8004CC24: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8004CC28: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8004CC2C: lui         $t8, 0x703
    ctx->r24 = S32(0X703 << 16);
    // 0x8004CC30: ori         $t8, $t8, 0xC000
    ctx->r24 = ctx->r24 | 0XC000;
    // 0x8004CC34: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8004CC38: lui         $t7, 0xF000
    ctx->r15 = S32(0XF000 << 16);
    // 0x8004CC3C: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8004CC40: sw          $t8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r24;
    // 0x8004CC44: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8004CC48: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8004CC4C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8004CC50: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_8004CC54:
    // 0x8004CC54: lw          $t6, 0x2E0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2E0);
    // 0x8004CC58: addiu       $s4, $s3, -0x1
    ctx->r20 = ADD32(ctx->r19, -0X1);
    // 0x8004CC5C: sll         $t7, $s4, 2
    ctx->r15 = S32(ctx->r20 << 2);
    // 0x8004CC60: blez        $t6, L_8004CFD0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8004CC64: andi        $t8, $t7, 0xFFF
        ctx->r24 = ctx->r15 & 0XFFF;
            goto L_8004CFD0;
    }
    // 0x8004CC64: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8004CC68: sll         $s4, $t8, 12
    ctx->r20 = S32(ctx->r24 << 12);
    // 0x8004CC6C: lui         $fp, 0xF200
    ctx->r30 = S32(0XF200 << 16);
    // 0x8004CC70: lui         $s7, 0xF300
    ctx->r23 = S32(0XF300 << 16);
    // 0x8004CC74: lui         $s6, 0xF550
    ctx->r22 = S32(0XF550 << 16);
    // 0x8004CC78: lui         $s5, 0xFD50
    ctx->r21 = S32(0XFD50 << 16);
L_8004CC7C:
    // 0x8004CC7C: lh          $t7, 0x31A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X31A);
    // 0x8004CC80: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x8004CC84: addu        $s0, $sp, $t6
    ctx->r16 = ADD32(ctx->r29, ctx->r14);
    // 0x8004CC88: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004CC8C: bne         $t7, $at, L_8004CDDC
    if (ctx->r15 != ctx->r1) {
        // 0x8004CC90: lh          $s0, 0xE0($s0)
        ctx->r16 = MEM_H(ctx->r16, 0XE0);
            goto L_8004CDDC;
    }
    // 0x8004CC90: lh          $s0, 0xE0($s0)
    ctx->r16 = MEM_H(ctx->r16, 0XE0);
    // 0x8004CC94: multu       $s3, $s0
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004CC98: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8004CC9C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8004CCA0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8004CCA4: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x8004CCA8: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8004CCAC: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x8004CCB0: addiu       $s1, $a3, 0x7
    ctx->r17 = ADD32(ctx->r7, 0X7);
    // 0x8004CCB4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8004CCB8: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8004CCBC: mflo        $t4
    ctx->r12 = lo;
    // 0x8004CCC0: addiu       $t1, $t4, 0x1
    ctx->r9 = ADD32(ctx->r12, 0X1);
    // 0x8004CCC4: sra         $t6, $s1, 3
    ctx->r14 = S32(SIGNED(ctx->r17) >> 3);
    // 0x8004CCC8: sw          $s2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r18;
    // 0x8004CCCC: sw          $s6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r22;
    // 0x8004CCD0: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x8004CCD4: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8004CCD8: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x8004CCDC: sra         $t9, $t1, 1
    ctx->r25 = S32(SIGNED(ctx->r9) >> 1);
    // 0x8004CCE0: addiu       $t1, $t9, -0x1
    ctx->r9 = ADD32(ctx->r25, -0X1);
    // 0x8004CCE4: sll         $t8, $t7, 9
    ctx->r24 = S32(ctx->r15 << 9);
    // 0x8004CCE8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8004CCEC: or          $ra, $v1, $zero
    ctx->r31 = ctx->r3 | 0;
    // 0x8004CCF0: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x8004CCF4: sw          $s7, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->r23;
    // 0x8004CCF8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8004CCFC: bgez        $a3, L_8004CD0C
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8004CD00: sra         $t0, $a3, 3
        ctx->r8 = S32(SIGNED(ctx->r7) >> 3);
            goto L_8004CD0C;
    }
    // 0x8004CD00: sra         $t0, $a3, 3
    ctx->r8 = S32(SIGNED(ctx->r7) >> 3);
    // 0x8004CD04: addiu       $at, $a3, 0x7
    ctx->r1 = ADD32(ctx->r7, 0X7);
    // 0x8004CD08: sra         $t0, $at, 3
    ctx->r8 = S32(SIGNED(ctx->r1) >> 3);
L_8004CD0C:
    // 0x8004CD0C: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8004CD10: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8004CD14: slti        $at, $t1, 0x7FF
    ctx->r1 = SIGNED(ctx->r9) < 0X7FF ? 1 : 0;
    // 0x8004CD18: beq         $at, $zero, L_8004CD28
    if (ctx->r1 == 0) {
        // 0x8004CD1C: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_8004CD28;
    }
    // 0x8004CD1C: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x8004CD20: b           L_8004CD2C
    // 0x8004CD24: or          $t3, $t1, $zero
    ctx->r11 = ctx->r9 | 0;
        goto L_8004CD2C;
    // 0x8004CD24: or          $t3, $t1, $zero
    ctx->r11 = ctx->r9 | 0;
L_8004CD28:
    // 0x8004CD28: addiu       $t3, $zero, 0x7FF
    ctx->r11 = ADD32(0, 0X7FF);
L_8004CD2C:
    // 0x8004CD2C: bgtz        $t0, L_8004CD3C
    if (SIGNED(ctx->r8) > 0) {
        // 0x8004CD30: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8004CD3C;
    }
    // 0x8004CD30: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8004CD34: b           L_8004CD40
    // 0x8004CD38: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_8004CD40;
    // 0x8004CD38: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8004CD3C:
    // 0x8004CD3C: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
L_8004CD40:
    // 0x8004CD40: bgtz        $t0, L_8004CD50
    if (SIGNED(ctx->r8) > 0) {
        // 0x8004CD44: addiu       $t6, $t1, 0x7FF
        ctx->r14 = ADD32(ctx->r9, 0X7FF);
            goto L_8004CD50;
    }
    // 0x8004CD44: addiu       $t6, $t1, 0x7FF
    ctx->r14 = ADD32(ctx->r9, 0X7FF);
    // 0x8004CD48: b           L_8004CD54
    // 0x8004CD4C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_8004CD54;
    // 0x8004CD4C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8004CD50:
    // 0x8004CD50: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
L_8004CD54:
    // 0x8004CD54: div         $zero, $t6, $a3
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r7)));
    // 0x8004CD58: mflo        $t7
    ctx->r15 = lo;
    // 0x8004CD5C: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8004CD60: bne         $a3, $zero, L_8004CD6C
    if (ctx->r7 != 0) {
        // 0x8004CD64: nop
    
            goto L_8004CD6C;
    }
    // 0x8004CD64: nop

    // 0x8004CD68: break       7
    do_break(2147798376);
L_8004CD6C:
    // 0x8004CD6C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004CD70: bne         $a3, $at, L_8004CD84
    if (ctx->r7 != ctx->r1) {
        // 0x8004CD74: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8004CD84;
    }
    // 0x8004CD74: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8004CD78: bne         $t6, $at, L_8004CD84
    if (ctx->r14 != ctx->r1) {
        // 0x8004CD7C: nop
    
            goto L_8004CD84;
    }
    // 0x8004CD7C: nop

    // 0x8004CD80: break       6
    do_break(2147798400);
L_8004CD84:
    // 0x8004CD84: andi        $t6, $t3, 0xFFF
    ctx->r14 = ctx->r11 & 0XFFF;
    // 0x8004CD88: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x8004CD8C: or          $t9, $t8, $s2
    ctx->r25 = ctx->r24 | ctx->r18;
    // 0x8004CD90: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x8004CD94: sw          $t8, 0x4($ra)
    MEM_W(0X4, ctx->r31) = ctx->r24;
    // 0x8004CD98: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8004CD9C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8004CDA0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8004CDA4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8004CDA8: addiu       $t9, $s0, -0x1
    ctx->r25 = ADD32(ctx->r16, -0X1);
    // 0x8004CDAC: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8004CDB0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8004CDB4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8004CDB8: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8004CDBC: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8004CDC0: or          $t6, $s4, $t8
    ctx->r14 = ctx->r20 | ctx->r24;
    // 0x8004CDC4: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x8004CDC8: sw          $s1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r17;
    // 0x8004CDCC: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x8004CDD0: sw          $fp, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r30;
    // 0x8004CDD4: b           L_8004CF20
    // 0x8004CDD8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
        goto L_8004CF20;
    // 0x8004CDD8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_8004CDDC:
    // 0x8004CDDC: multu       $s3, $s0
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004CDE0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8004CDE4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8004CDE8: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8004CDEC: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x8004CDF0: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8004CDF4: sra         $s1, $s3, 1
    ctx->r17 = S32(SIGNED(ctx->r19) >> 1);
    // 0x8004CDF8: addiu       $s1, $s1, 0x7
    ctx->r17 = ADD32(ctx->r17, 0X7);
    // 0x8004CDFC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8004CE00: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8004CE04: mflo        $t4
    ctx->r12 = lo;
    // 0x8004CE08: addiu       $a3, $t4, 0x3
    ctx->r7 = ADD32(ctx->r12, 0X3);
    // 0x8004CE0C: sra         $t8, $s1, 3
    ctx->r24 = S32(SIGNED(ctx->r17) >> 3);
    // 0x8004CE10: sw          $s2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r18;
    // 0x8004CE14: sw          $s6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r22;
    // 0x8004CE18: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8004CE1C: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8004CE20: andi        $t6, $t8, 0x1FF
    ctx->r14 = ctx->r24 & 0X1FF;
    // 0x8004CE24: sra         $t7, $a3, 2
    ctx->r15 = S32(SIGNED(ctx->r7) >> 2);
    // 0x8004CE28: addiu       $a3, $t7, -0x1
    ctx->r7 = ADD32(ctx->r15, -0X1);
    // 0x8004CE2C: sll         $t9, $t6, 9
    ctx->r25 = S32(ctx->r14 << 9);
    // 0x8004CE30: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8004CE34: or          $ra, $v1, $zero
    ctx->r31 = ctx->r3 | 0;
    // 0x8004CE38: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x8004CE3C: sw          $s7, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->r23;
    // 0x8004CE40: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8004CE44: bgez        $s3, L_8004CE54
    if (SIGNED(ctx->r19) >= 0) {
        // 0x8004CE48: sra         $t0, $s3, 4
        ctx->r8 = S32(SIGNED(ctx->r19) >> 4);
            goto L_8004CE54;
    }
    // 0x8004CE48: sra         $t0, $s3, 4
    ctx->r8 = S32(SIGNED(ctx->r19) >> 4);
    // 0x8004CE4C: addiu       $at, $s3, 0xF
    ctx->r1 = ADD32(ctx->r19, 0XF);
    // 0x8004CE50: sra         $t0, $at, 4
    ctx->r8 = S32(SIGNED(ctx->r1) >> 4);
L_8004CE54:
    // 0x8004CE54: lui         $at, 0xF540
    ctx->r1 = S32(0XF540 << 16);
    // 0x8004CE58: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x8004CE5C: slti        $at, $a3, 0x7FF
    ctx->r1 = SIGNED(ctx->r7) < 0X7FF ? 1 : 0;
    // 0x8004CE60: beq         $at, $zero, L_8004CE70
    if (ctx->r1 == 0) {
        // 0x8004CE64: or          $s1, $t7, $zero
        ctx->r17 = ctx->r15 | 0;
            goto L_8004CE70;
    }
    // 0x8004CE64: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x8004CE68: b           L_8004CE74
    // 0x8004CE6C: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
        goto L_8004CE74;
    // 0x8004CE6C: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
L_8004CE70:
    // 0x8004CE70: addiu       $t3, $zero, 0x7FF
    ctx->r11 = ADD32(0, 0X7FF);
L_8004CE74:
    // 0x8004CE74: bgtz        $t0, L_8004CE84
    if (SIGNED(ctx->r8) > 0) {
        // 0x8004CE78: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8004CE84;
    }
    // 0x8004CE78: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8004CE7C: b           L_8004CE88
    // 0x8004CE80: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_8004CE88;
    // 0x8004CE80: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8004CE84:
    // 0x8004CE84: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
L_8004CE88:
    // 0x8004CE88: bgtz        $t0, L_8004CE98
    if (SIGNED(ctx->r8) > 0) {
        // 0x8004CE8C: addiu       $t8, $t1, 0x7FF
        ctx->r24 = ADD32(ctx->r9, 0X7FF);
            goto L_8004CE98;
    }
    // 0x8004CE8C: addiu       $t8, $t1, 0x7FF
    ctx->r24 = ADD32(ctx->r9, 0X7FF);
    // 0x8004CE90: b           L_8004CE9C
    // 0x8004CE94: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_8004CE9C;
    // 0x8004CE94: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8004CE98:
    // 0x8004CE98: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
L_8004CE9C:
    // 0x8004CE9C: div         $zero, $t8, $a3
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r7)));
    // 0x8004CEA0: mflo        $t6
    ctx->r14 = lo;
    // 0x8004CEA4: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x8004CEA8: bne         $a3, $zero, L_8004CEB4
    if (ctx->r7 != 0) {
        // 0x8004CEAC: nop
    
            goto L_8004CEB4;
    }
    // 0x8004CEAC: nop

    // 0x8004CEB0: break       7
    do_break(2147798704);
L_8004CEB4:
    // 0x8004CEB4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004CEB8: bne         $a3, $at, L_8004CECC
    if (ctx->r7 != ctx->r1) {
        // 0x8004CEBC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8004CECC;
    }
    // 0x8004CEBC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8004CEC0: bne         $t8, $at, L_8004CECC
    if (ctx->r24 != ctx->r1) {
        // 0x8004CEC4: nop
    
            goto L_8004CECC;
    }
    // 0x8004CEC4: nop

    // 0x8004CEC8: break       6
    do_break(2147798728);
L_8004CECC:
    // 0x8004CECC: andi        $t8, $t3, 0xFFF
    ctx->r24 = ctx->r11 & 0XFFF;
    // 0x8004CED0: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x8004CED4: or          $t7, $t9, $s2
    ctx->r15 = ctx->r25 | ctx->r18;
    // 0x8004CED8: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x8004CEDC: sw          $t9, 0x4($ra)
    MEM_W(0X4, ctx->r31) = ctx->r25;
    // 0x8004CEE0: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8004CEE4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8004CEE8: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8004CEEC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8004CEF0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8004CEF4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8004CEF8: addiu       $t7, $s0, -0x1
    ctx->r15 = ADD32(ctx->r16, -0X1);
    // 0x8004CEFC: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8004CF00: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8004CF04: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x8004CF08: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x8004CF0C: sw          $s1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r17;
    // 0x8004CF10: or          $t8, $s4, $t9
    ctx->r24 = ctx->r20 | ctx->r25;
    // 0x8004CF14: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x8004CF18: sw          $fp, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r30;
    // 0x8004CF1C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_8004CF20:
    // 0x8004CF20: lh          $t6, 0x31A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X31A);
    // 0x8004CF24: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8004CF28: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8004CF2C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8004CF30: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x8004CF34: lui         $a3, 0xBF00
    ctx->r7 = S32(0XBF00 << 16);
    // 0x8004CF38: bgez        $t4, L_8004CF48
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8004CF3C: sra         $t7, $t4, 1
        ctx->r15 = S32(SIGNED(ctx->r12) >> 1);
            goto L_8004CF48;
    }
    // 0x8004CF3C: sra         $t7, $t4, 1
    ctx->r15 = S32(SIGNED(ctx->r12) >> 1);
    // 0x8004CF40: addiu       $at, $t4, 0x1
    ctx->r1 = ADD32(ctx->r12, 0X1);
    // 0x8004CF44: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_8004CF48:
    // 0x8004CF48: div         $zero, $t7, $t6
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r14)));
    // 0x8004CF4C: bne         $t6, $zero, L_8004CF58
    if (ctx->r14 != 0) {
        // 0x8004CF50: nop
    
            goto L_8004CF58;
    }
    // 0x8004CF50: nop

    // 0x8004CF54: break       7
    do_break(2147798868);
L_8004CF58:
    // 0x8004CF58: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004CF5C: bne         $t6, $at, L_8004CF70
    if (ctx->r14 != ctx->r1) {
        // 0x8004CF60: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8004CF70;
    }
    // 0x8004CF60: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8004CF64: bne         $t7, $at, L_8004CF70
    if (ctx->r15 != ctx->r1) {
        // 0x8004CF68: nop
    
            goto L_8004CF70;
    }
    // 0x8004CF68: nop

    // 0x8004CF6C: break       6
    do_break(2147798892);
L_8004CF70:
    // 0x8004CF70: lui         $t7, 0x430
    ctx->r15 = S32(0X430 << 16);
    // 0x8004CF74: ori         $t7, $t7, 0x40
    ctx->r15 = ctx->r15 | 0X40;
    // 0x8004CF78: mflo        $t9
    ctx->r25 = lo;
    // 0x8004CF7C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8004CF80: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x8004CF84: addiu       $t6, $zero, 0xA14
    ctx->r14 = ADD32(0, 0XA14);
    // 0x8004CF88: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8004CF8C: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x8004CF90: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x8004CF94: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8004CF98: lui         $t9, 0xA
    ctx->r25 = S32(0XA << 16);
    // 0x8004CF9C: ori         $t9, $t9, 0x1E
    ctx->r25 = ctx->r25 | 0X1E;
    // 0x8004CFA0: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x8004CFA4: sw          $a3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r7;
    // 0x8004CFA8: lw          $t6, 0x2E0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2E0);
    // 0x8004CFAC: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x8004CFB0: addu        $t2, $t2, $t8
    ctx->r10 = ADD32(ctx->r10, ctx->r24);
    // 0x8004CFB4: sll         $t8, $t5, 16
    ctx->r24 = S32(ctx->r13 << 16);
    // 0x8004CFB8: sra         $t7, $t8, 16
    ctx->r15 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8004CFBC: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8004CFC0: or          $t5, $t7, $zero
    ctx->r13 = ctx->r15 | 0;
    // 0x8004CFC4: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // 0x8004CFC8: bne         $at, $zero, L_8004CC7C
    if (ctx->r1 != 0) {
        // 0x8004CFCC: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_8004CC7C;
    }
    // 0x8004CFCC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_8004CFD0:
    // 0x8004CFD0: lw          $v0, 0x32C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X32C);
    // 0x8004CFD4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8004CFD8: lui         $t9, 0xB800
    ctx->r25 = S32(0XB800 << 16);
    // 0x8004CFDC: addiu       $a1, $a1, -0x4A58
    ctx->r5 = ADD32(ctx->r5, -0X4A58);
    // 0x8004CFE0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8004CFE4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8004CFE8: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8004CFEC: lw          $t7, 0x4($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X4);
    // 0x8004CFF0: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x8004CFF4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8004CFF8: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8004CFFC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8004D000: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8004D004: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8004D008: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8004D00C: sw          $v0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r2;
L_8004D010:
    // 0x8004D010: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8004D014: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004D018: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8004D01C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8004D020: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8004D024: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8004D028: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8004D02C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8004D030: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8004D034: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8004D038: jr          $ra
    // 0x8004D03C: addiu       $sp, $sp, 0x330
    ctx->r29 = ADD32(ctx->r29, 0X330);
    TRACE_RETURN()
    return;
    // 0x8004D03C: addiu       $sp, $sp, 0x330
    ctx->r29 = ADD32(ctx->r29, 0X330);
;}
RECOMP_FUNC void func_8004D040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004D040: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8004D044: lw          $t6, -0x4A40($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4A40);
    // 0x8004D048: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004D04C: lw          $v0, 0x8($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X8);
    // 0x8004D050: lw          $t7, 0xD8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XD8);
    // 0x8004D054: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8004D058: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004D05C: sw          $t8, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r24;
    // 0x8004D060: jr          $ra
    // 0x8004D064: sh          $zero, -0x4A20($at)
    MEM_H(-0X4A20, ctx->r1) = 0;
    TRACE_RETURN()
    return;
    // 0x8004D064: sh          $zero, -0x4A20($at)
    MEM_H(-0X4A20, ctx->r1) = 0;
;}
RECOMP_FUNC void func_8004D068(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8004D068: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004D06C: addiu       $v1, $v1, -0x4A20
    ctx->r3 = ADD32(ctx->r3, -0X4A20);
    // 0x8004D070: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x8004D074: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004D078: beq         $v0, $zero, L_8004D12C
    if (ctx->r2 == 0) {
        // 0x8004D07C: nop
    
            goto L_8004D12C;
    }
    // 0x8004D07C: nop

    // 0x8004D080: bne         $v0, $at, L_8004D12C
    if (ctx->r2 != ctx->r1) {
        // 0x8004D084: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_8004D12C;
    }
    // 0x8004D084: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8004D088: addiu       $a0, $a0, -0x4A18
    ctx->r4 = ADD32(ctx->r4, -0X4A18);
    // 0x8004D08C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8004D090: lh          $t7, -0x4A1E($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X4A1E);
    // 0x8004D094: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x8004D098: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8004D09C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8004D0A0: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8004D0A4: sh          $t8, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r24;
    // 0x8004D0A8: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x8004D0AC: bgez        $v0, L_8004D0C0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8004D0B0: slti        $at, $v0, 0x100
        ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
            goto L_8004D0C0;
    }
    // 0x8004D0B0: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x8004D0B4: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x8004D0B8: b           L_8004D0D0
    // 0x8004D0BC: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
        goto L_8004D0D0;
    // 0x8004D0BC: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
L_8004D0C0:
    // 0x8004D0C0: bne         $at, $zero, L_8004D0D0
    if (ctx->r1 != 0) {
        // 0x8004D0C4: addiu       $t9, $zero, 0xFF
        ctx->r25 = ADD32(0, 0XFF);
            goto L_8004D0D0;
    }
    // 0x8004D0C4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8004D0C8: sh          $t9, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r25;
    // 0x8004D0CC: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
L_8004D0D0:
    // 0x8004D0D0: lh          $t0, -0x4A1A($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X4A1A);
    // 0x8004D0D4: bnel        $t0, $v0, L_8004D100
    if (ctx->r8 != ctx->r2) {
        // 0x8004D0D8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8004D100;
    }
    goto skip_0;
    // 0x8004D0D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    skip_0:
    // 0x8004D0DC: lw          $t1, -0x4A40($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4A40);
    // 0x8004D0E0: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004D0E4: lw          $v0, 0x8($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X8);
    // 0x8004D0E8: lw          $t2, 0xD8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XD8);
    // 0x8004D0EC: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x8004D0F0: sw          $t3, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r11;
    // 0x8004D0F4: jr          $ra
    // 0x8004D0F8: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    TRACE_RETURN()
    return;
    // 0x8004D0F8: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x8004D0FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8004D100:
    // 0x8004D100: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x8004D104: addiu       $v0, $v0, -0x4440
    ctx->r2 = ADD32(ctx->r2, -0X4440);
    // 0x8004D108: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8004D10C:
    // 0x8004D10C: sll         $t4, $v1, 4
    ctx->r12 = S32(ctx->r3 << 4);
    // 0x8004D110: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8004D114: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x8004D118: sra         $v1, $t6, 16
    ctx->r3 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8004D11C: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x8004D120: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x8004D124: bne         $at, $zero, L_8004D10C
    if (ctx->r1 != 0) {
        // 0x8004D128: sb          $a0, 0xF($t5)
        MEM_B(0XF, ctx->r13) = ctx->r4;
            goto L_8004D10C;
    }
    // 0x8004D128: sb          $a0, 0xF($t5)
    MEM_B(0XF, ctx->r13) = ctx->r4;
L_8004D12C:
    // 0x8004D12C: jr          $ra
    TRACE_RETURN()
    return;
;}
