#include "recomp.h"
#include "trace.h"
#include "funcs.h"

extern void runtime_log(const char* fmt, ...);

RECOMP_FUNC void func_8000BD4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000BD4C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000BD50: addiu       $v0, $v0, -0x2CF0
    ctx->r2 = ADD32(ctx->r2, -0X2CF0);
    // 0x8000BD54: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000BD58: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x8000BD5C: jr          $ra
    // 0x8000BD60: sw          $a2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r6;
    TRACE_RETURN()
    return;
    // 0x8000BD60: sw          $a2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r6;
;}
RECOMP_FUNC void func_8000BD64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000BD64: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000BD68: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000BD6C: addiu       $a0, $a0, -0x2CE0
    ctx->r4 = ADD32(ctx->r4, -0X2CE0);
    // 0x8000BD70: addiu       $a1, $a1, -0x2CF0
    ctx->r5 = ADD32(ctx->r5, -0X2CF0);
    // 0x8000BD74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000BD78:
    // 0x8000BD78: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8000BD7C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000BD80: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x8000BD84: addu        $t6, $a1, $v1
    ctx->r14 = ADD32(ctx->r5, ctx->r3);
    // 0x8000BD88: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8000BD8C: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8000BD90: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8000BD94: addu        $t8, $a0, $v1
    ctx->r24 = ADD32(ctx->r4, ctx->r3);
    // 0x8000BD98: bne         $at, $zero, L_8000BD78
    if (ctx->r1 != 0) {
        // 0x8000BD9C: sw          $t7, 0x0($t8)
        MEM_W(0X0, ctx->r24) = ctx->r15;
            goto L_8000BD78;
    }
    // 0x8000BD9C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8000BDA0: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000BDA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000BDA8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000BDAC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000BDB0: addiu       $a0, $a0, -0x2CF0
    ctx->r4 = ADD32(ctx->r4, -0X2CF0);
    // 0x8000BDB4: addiu       $a1, $a1, -0x2CE0
    ctx->r5 = ADD32(ctx->r5, -0X2CE0);
    // 0x8000BDB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000BDBC:
    // 0x8000BDBC: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8000BDC0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000BDC4: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x8000BDC8: addu        $t6, $a1, $v1
    ctx->r14 = ADD32(ctx->r5, ctx->r3);
    // 0x8000BDCC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8000BDD0: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8000BDD4: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8000BDD8: addu        $t8, $a0, $v1
    ctx->r24 = ADD32(ctx->r4, ctx->r3);
    // 0x8000BDDC: bne         $at, $zero, L_8000BDBC
    if (ctx->r1 != 0) {
        // 0x8000BDE0: sw          $t7, 0x0($t8)
        MEM_W(0X0, ctx->r24) = ctx->r15;
            goto L_8000BDBC;
    }
    // 0x8000BDE0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8000BDE4: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000BDEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000BDEC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000BDF0: addiu       $v0, $v0, -0x2CD0
    ctx->r2 = ADD32(ctx->r2, -0X2CD0);
    // 0x8000BDF4: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000BDF8: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x8000BDFC: jr          $ra
    // 0x8000BE00: sw          $a2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r6;
    TRACE_RETURN()
    return;
    // 0x8000BE00: sw          $a2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r6;
;}
RECOMP_FUNC void func_8000BE10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000BE10: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x8000BE14: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8000BE18: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8000BE1C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8000BE20: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8000BE24: addiu       $t3, $t3, -0x2CA4
    ctx->r11 = ADD32(ctx->r11, -0X2CA4);
    // 0x8000BE28: addiu       $t2, $t2, -0x2CA8
    ctx->r10 = ADD32(ctx->r10, -0X2CA8);
    // 0x8000BE2C: addiu       $t1, $t1, -0x2CAC
    ctx->r9 = ADD32(ctx->r9, -0X2CAC);
    // 0x8000BE30: addiu       $t0, $t0, -0x2CB0
    ctx->r8 = ADD32(ctx->r8, -0X2CB0);
    // 0x8000BE34: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    // 0x8000BE38: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8000BE3C: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8000BE40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000BE44: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8000BE48: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x8000BE4C: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8000BE50: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    // 0x8000BE54: beq         $a0, $zero, L_8000BF80
    if (ctx->r4 == 0) {
        // 0x8000BE58: sw          $zero, 0x0($t3)
        MEM_W(0X0, ctx->r11) = 0;
            goto L_8000BF80;
    }
    // 0x8000BE58: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
    // 0x8000BE5C: lbu         $a1, 0x0($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X0);
    // 0x8000BE60: beql        $a1, $zero, L_8000BF84
    if (ctx->r5 == 0) {
        // 0x8000BE64: lw          $s0, 0x8($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X8);
            goto L_8000BF84;
    }
    goto skip_0;
    // 0x8000BE64: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    skip_0:
    // 0x8000BE68: beq         $a1, $zero, L_8000BEE8
    if (ctx->r5 == 0) {
        // 0x8000BE6C: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_8000BEE8;
    }
    // 0x8000BE6C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8000BE70: lbu         $a0, 0x0($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X0);
    // 0x8000BE74: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
L_8000BE78:
    // 0x8000BE78: beq         $a0, $zero, L_8000BEA4
    if (ctx->r4 == 0) {
        // 0x8000BE7C: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_8000BEA4;
    }
    // 0x8000BE7C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8000BE80: bne         $a1, $a0, L_8000BEA4
    if (ctx->r5 != ctx->r4) {
        // 0x8000BE84: nop
    
            goto L_8000BEA4;
    }
    // 0x8000BE84: nop

    // 0x8000BE88: lbu         $a0, 0x1($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X1);
L_8000BE8C:
    // 0x8000BE8C: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    // 0x8000BE90: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8000BE94: beq         $a0, $zero, L_8000BEA4
    if (ctx->r4 == 0) {
        // 0x8000BE98: nop
    
            goto L_8000BEA4;
    }
    // 0x8000BE98: nop

    // 0x8000BE9C: beql        $a1, $a0, L_8000BE8C
    if (ctx->r5 == ctx->r4) {
        // 0x8000BEA0: lbu         $a0, 0x1($a2)
        ctx->r4 = MEM_BU(ctx->r6, 0X1);
            goto L_8000BE8C;
    }
    goto skip_1;
    // 0x8000BEA0: lbu         $a0, 0x1($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X1);
    skip_1:
L_8000BEA4:
    // 0x8000BEA4: beq         $a0, $zero, L_8000BEB8
    if (ctx->r4 == 0) {
        // 0x8000BEA8: addu        $t7, $a3, $t6
        ctx->r15 = ADD32(ctx->r7, ctx->r14);
            goto L_8000BEB8;
    }
    // 0x8000BEA8: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x8000BEAC: sw          $a2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r6;
    // 0x8000BEB0: lbu         $a0, 0x0($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X0);
    // 0x8000BEB4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8000BEB8:
    // 0x8000BEB8: beq         $a0, $zero, L_8000BEE0
    if (ctx->r4 == 0) {
        // 0x8000BEBC: nop
    
            goto L_8000BEE0;
    }
    // 0x8000BEBC: nop

    // 0x8000BEC0: beq         $a1, $a0, L_8000BEE0
    if (ctx->r5 == ctx->r4) {
        // 0x8000BEC4: nop
    
            goto L_8000BEE0;
    }
    // 0x8000BEC4: nop

    // 0x8000BEC8: lbu         $a0, 0x1($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X1);
L_8000BECC:
    // 0x8000BECC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8000BED0: beq         $a0, $zero, L_8000BEE0
    if (ctx->r4 == 0) {
        // 0x8000BED4: nop
    
            goto L_8000BEE0;
    }
    // 0x8000BED4: nop

    // 0x8000BED8: bnel        $a1, $a0, L_8000BECC
    if (ctx->r5 != ctx->r4) {
        // 0x8000BEDC: lbu         $a0, 0x1($a2)
        ctx->r4 = MEM_BU(ctx->r6, 0X1);
            goto L_8000BECC;
    }
    goto skip_2;
    // 0x8000BEDC: lbu         $a0, 0x1($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X1);
    skip_2:
L_8000BEE0:
    // 0x8000BEE0: bne         $a0, $zero, L_8000BE78
    if (ctx->r4 != 0) {
        // 0x8000BEE4: nop
    
            goto L_8000BE78;
    }
    // 0x8000BEE4: nop

L_8000BEE8:
    // 0x8000BEE8: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8000BEEC: bne         $at, $zero, L_8000BF80
    if (ctx->r1 != 0) {
        // 0x8000BEF0: lw          $t8, 0x28($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X28);
            goto L_8000BF80;
    }
    // 0x8000BEF0: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8000BEF4: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8000BEF8: addiu       $a2, $zero, 0x2D
    ctx->r6 = ADD32(0, 0X2D);
    // 0x8000BEFC: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8000BF00: bne         $a2, $t9, L_8000BF80
    if (ctx->r6 != ctx->r25) {
        // 0x8000BF04: addiu       $s0, $zero, 0x76
        ctx->r16 = ADD32(0, 0X76);
            goto L_8000BF80;
    }
    // 0x8000BF04: addiu       $s0, $zero, 0x76
    ctx->r16 = ADD32(0, 0X76);
    // 0x8000BF08: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x8000BF0C: addiu       $t5, $zero, 0x73
    ctx->r13 = ADD32(0, 0X73);
    // 0x8000BF10: addiu       $t4, $zero, 0x6C
    ctx->r12 = ADD32(0, 0X6C);
    // 0x8000BF14: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    // 0x8000BF18: lbu         $a1, 0x1($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X1);
L_8000BF1C:
    // 0x8000BF1C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8000BF20: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8000BF24: beq         $a1, $a3, L_8000BF4C
    if (ctx->r5 == ctx->r7) {
        // 0x8000BF28: nop
    
            goto L_8000BF4C;
    }
    // 0x8000BF28: nop

    // 0x8000BF2C: beql        $a1, $t4, L_8000BF68
    if (ctx->r5 == ctx->r12) {
        // 0x8000BF30: sw          $s1, 0x0($t3)
        MEM_W(0X0, ctx->r11) = ctx->r17;
            goto L_8000BF68;
    }
    goto skip_3;
    // 0x8000BF30: sw          $s1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r17;
    skip_3:
    // 0x8000BF34: beq         $a1, $t5, L_8000BF5C
    if (ctx->r5 == ctx->r13) {
        // 0x8000BF38: nop
    
            goto L_8000BF5C;
    }
    // 0x8000BF38: nop

    // 0x8000BF3C: beq         $a1, $s0, L_8000BF54
    if (ctx->r5 == ctx->r16) {
        // 0x8000BF40: nop
    
            goto L_8000BF54;
    }
    // 0x8000BF40: nop

    // 0x8000BF44: b           L_8000BF68
    // 0x8000BF48: nop

        goto L_8000BF68;
    // 0x8000BF48: nop

L_8000BF4C:
    // 0x8000BF4C: b           L_8000BF68
    // 0x8000BF50: sw          $s1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r17;
        goto L_8000BF68;
    // 0x8000BF50: sw          $s1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r17;
L_8000BF54:
    // 0x8000BF54: b           L_8000BF68
    // 0x8000BF58: sw          $s1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r17;
        goto L_8000BF68;
    // 0x8000BF58: sw          $s1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r17;
L_8000BF5C:
    // 0x8000BF5C: b           L_8000BF68
    // 0x8000BF60: sw          $s1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r17;
        goto L_8000BF68;
    // 0x8000BF60: sw          $s1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r17;
    // 0x8000BF64: sw          $s1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r17;
L_8000BF68:
    // 0x8000BF68: bne         $at, $zero, L_8000BF80
    if (ctx->r1 != 0) {
        // 0x8000BF6C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8000BF80;
    }
    // 0x8000BF6C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000BF70: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x8000BF74: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x8000BF78: beql        $a2, $t6, L_8000BF1C
    if (ctx->r6 == ctx->r14) {
        // 0x8000BF7C: lbu         $a1, 0x1($a0)
        ctx->r5 = MEM_BU(ctx->r4, 0X1);
            goto L_8000BF1C;
    }
    goto skip_4;
    // 0x8000BF7C: lbu         $a1, 0x1($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X1);
    skip_4:
L_8000BF80:
    // 0x8000BF80: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
L_8000BF84:
    // 0x8000BF84: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8000BF88: jr          $ra
    // 0x8000BF8C: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    TRACE_RETURN()
    return;
    // 0x8000BF8C: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_8000BF90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000BF90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000BF94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000BF98: jal         0x80055EE0
    // 0x8000BF9C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    osInitialize_recomp(rdram, ctx);
        goto after_0;
    // 0x8000BF9C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8000BFA0: jal         0x8000BE10
    // 0x8000BFA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8000BE10(rdram, ctx);
        goto after_1;
    // 0x8000BFA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8000BFA8: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x8000BFAC: addiu       $t6, $t6, -0x79C8
    ctx->r14 = ADD32(ctx->r14, -0X79C8);
    // 0x8000BFB0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000BFB4: lui         $a2, 0x8001
    ctx->r6 = S32(0X8001 << 16);
    // 0x8000BFB8: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8000BFBC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8000BFC0: addiu       $a2, $a2, -0x400C
    ctx->r6 = ADD32(ctx->r6, -0X400C);
    // 0x8000BFC4: addiu       $a0, $a0, 0x7C88
    ctx->r4 = ADD32(ctx->r4, 0X7C88);
    // 0x8000BFC8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8000BFCC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8000BFD0: jal         0x800527B0
    // 0x8000BFD4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    osCreateThread_recomp(rdram, ctx);
        goto after_2;
    // 0x8000BFD4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8000BFD8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000BFDC: jal         0x80052570
    // 0x8000BFE0: addiu       $a0, $a0, 0x7C88
    ctx->r4 = ADD32(ctx->r4, 0X7C88);
    osStartThread_recomp(rdram, ctx);
        goto after_3;
    // 0x8000BFE0: addiu       $a0, $a0, 0x7C88
    ctx->r4 = ADD32(ctx->r4, 0X7C88);
    after_3:
    // 0x8000BFE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000BFE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000BFEC: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000BFF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000BFF4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000BFF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000BFFC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000C000: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x8000C004: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x8000C008: addiu       $a2, $a2, -0x7018
    ctx->r6 = ADD32(ctx->r6, -0X7018);
    // 0x8000C00C: addiu       $a1, $a1, -0x6CF8
    ctx->r5 = ADD32(ctx->r5, -0X6CF8);
    // 0x8000C010: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x8000C014: jal         0x80056170
    // 0x8000C018: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    osCreatePiManager_recomp(rdram, ctx);
        goto after_0;
    // 0x8000C018: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    after_0:
    // 0x8000C01C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8000C020: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000C024: addiu       $t6, $t6, 0x7C88
    ctx->r14 = ADD32(ctx->r14, 0X7C88);
    // 0x8000C028: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000C02C: lui         $a2, 0x8001
    ctx->r6 = S32(0X8001 << 16);
    // 0x8000C030: addiu       $t7, $zero, 0x11
    ctx->r15 = ADD32(0, 0X11);
    // 0x8000C034: sh          $zero, -0x2E10($at)
    MEM_H(-0X2E10, ctx->r1) = 0;
    // 0x8000C038: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8000C03C: addiu       $a2, $a2, -0x3D94
    ctx->r6 = ADD32(ctx->r6, -0X3D94);
    // 0x8000C040: addiu       $a0, $a0, 0x6AD8
    ctx->r4 = ADD32(ctx->r4, 0X6AD8);
    // 0x8000C044: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8000C048: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8000C04C: jal         0x800527B0
    // 0x8000C050: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    osCreateThread_recomp(rdram, ctx);
        goto after_1;
    // 0x8000C050: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8000C054: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000C058: jal         0x80052570
    // 0x8000C05C: addiu       $a0, $a0, 0x6AD8
    ctx->r4 = ADD32(ctx->r4, 0X6AD8);
    osStartThread_recomp(rdram, ctx);
        goto after_2;
    // 0x8000C05C: addiu       $a0, $a0, 0x6AD8
    ctx->r4 = ADD32(ctx->r4, 0X6AD8);
    after_2:
    // 0x8000C060: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000C064: jal         0x80056300
    // 0x8000C068: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    osSetThreadPri_recomp(rdram, ctx);
        goto after_3;
    // 0x8000C068: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
L_8000C06C:
    // 0x8000C06C: b           L_8000C06C
    pause_self(rdram);
;}
RECOMP_FUNC void func_8000C090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000C090: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C094: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000C098: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000C0A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000C0A0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8000C0A4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000C0A8: lui         $s0, 0x800F
    ctx->r16 = S32(0X800F << 16);
    // 0x8000C0AC: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8000C0B0: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8000C0B4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000C0B8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000C0BC: addiu       $s0, $s0, -0x6CB0
    ctx->r16 = ADD32(ctx->r16, -0X6CB0);
    // 0x8000C0C0: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8000C0C4: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8000C0C8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000C0CC: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x8000C0D0: lui         $s3, 0x800F
    ctx->r19 = S32(0X800F << 16);
    // 0x8000C0D4: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x8000C0D8: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x8000C0DC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8000C0E0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8000C0E4: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x8000C0E8: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x8000C0EC: addiu       $s7, $s7, -0x2E40
    ctx->r23 = ADD32(ctx->r23, -0X2E40);
    // 0x8000C0F0: addiu       $s6, $s6, -0x2E10
    ctx->r22 = ADD32(ctx->r22, -0X2E10);
    // 0x8000C0F4: addiu       $s3, $s3, -0x6CC0
    ctx->r19 = ADD32(ctx->r19, -0X6CC0);
    // 0x8000C0F8: addiu       $s1, $s1, -0x2E38
    ctx->r17 = ADD32(ctx->r17, -0X2E38);
    // 0x8000C0FC: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8000C100: addiu       $s4, $sp, 0x3C
    ctx->r20 = ADD32(ctx->r29, 0X3C);
    // 0x8000C104: addiu       $s5, $zero, 0x5
    ctx->r21 = ADD32(0, 0X5);
L_8000C108:
    // 0x8000C108: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8000C10C:
    // 0x8000C10C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8000C110: jal         0x8004F990
    // 0x8000C114: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8000C114: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_0:
    // 0x8000C118: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8000C11C: lh          $v1, 0x0($t6)
    ctx->r3 = MEM_H(ctx->r14, 0X0);
    // 0x8000C120: beq         $v1, $s2, L_8000C138
    if (ctx->r3 == ctx->r18) {
        // 0x8000C124: nop
    
            goto L_8000C138;
    }
    // 0x8000C124: nop

    // 0x8000C128: beq         $v1, $s5, L_8000C194
    if (ctx->r3 == ctx->r21) {
        // 0x8000C12C: sll         $a0, $s2, 16
        ctx->r4 = S32(ctx->r18 << 16);
            goto L_8000C194;
    }
    // 0x8000C12C: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x8000C130: b           L_8000C10C
    // 0x8000C134: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_8000C10C;
    // 0x8000C134: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8000C138:
    // 0x8000C138: jal         0x8000AA24
    // 0x8000C13C: nop

    func_8000AA24(rdram, ctx);
        goto after_1;
    // 0x8000C13C: nop

    after_1:
    // 0x8000C140: beql        $v0, $zero, L_8000C188
    if (ctx->r2 == 0) {
        // 0x8000C144: lw          $t1, 0x0($s3)
        ctx->r9 = MEM_W(ctx->r19, 0X0);
            goto L_8000C188;
    }
    goto skip_0;
    // 0x8000C144: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    skip_0:
    // 0x8000C148: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x8000C14C: beql        $t7, $zero, L_8000C160
    if (ctx->r15 == 0) {
        // 0x8000C150: lh          $t8, 0x0($s6)
        ctx->r24 = MEM_H(ctx->r22, 0X0);
            goto L_8000C160;
    }
    goto skip_1;
    // 0x8000C150: lh          $t8, 0x0($s6)
    ctx->r24 = MEM_H(ctx->r22, 0X0);
    skip_1:
    // 0x8000C154: jal         0x8000A530
    // 0x8000C158: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8000A530(rdram, ctx);
        goto after_2;
    // 0x8000C158: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x8000C15C: lh          $t8, 0x0($s6)
    ctx->r24 = MEM_H(ctx->r22, 0X0);
L_8000C160:
    // 0x8000C160: bnel        $t8, $zero, L_8000C188
    if (ctx->r24 != 0) {
        // 0x8000C164: lw          $t1, 0x0($s3)
        ctx->r9 = MEM_W(ctx->r19, 0X0);
            goto L_8000C188;
    }
    goto skip_2;
    // 0x8000C164: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    skip_2:
    // 0x8000C168: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x8000C16C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8000C170: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x8000C174: beql        $t0, $zero, L_8000C188
    if (ctx->r8 == 0) {
        // 0x8000C178: lw          $t1, 0x0($s3)
        ctx->r9 = MEM_W(ctx->r19, 0X0);
            goto L_8000C188;
    }
    goto skip_3;
    // 0x8000C178: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    skip_3:
    // 0x8000C17C: jal         0x80055500
    // 0x8000C180: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    osContStartReadData_recomp(rdram, ctx);
        goto after_3;
    // 0x8000C180: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    after_3:
    // 0x8000C184: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
L_8000C188:
    // 0x8000C188: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8000C18C: b           L_8000C108
    // 0x8000C190: sw          $t2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r10;
        goto L_8000C108;
    // 0x8000C190: sw          $t2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r10;
L_8000C194:
    // 0x8000C194: sra         $t3, $a0, 16
    ctx->r11 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8000C198: sh          $s2, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r18;
    // 0x8000C19C: jal         0x8000A530
    // 0x8000C1A0: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    func_8000A530(rdram, ctx);
        goto after_4;
    // 0x8000C1A0: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_4:
    // 0x8000C1A4: b           L_8000C10C
    // 0x8000C1A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_8000C10C;
    // 0x8000C1A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8000C1AC: nop

    // 0x8000C1B0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8000C1B4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000C1B8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000C1BC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C1C0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8000C1C4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8000C1C8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8000C1CC: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8000C1D0: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8000C1D4: jr          $ra
    // 0x8000C1D8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    TRACE_RETURN()
    return;
    // 0x8000C1D8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8000C1DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000C1DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000C1E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000C1E4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8000C1E8: jal         0x8000FAE4
    // 0x8000C1EC: lw          $a0, -0x6CA0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6CA0);
    func_8000FAE4(rdram, ctx);
        goto after_0;
    // 0x8000C1EC: lw          $a0, -0x6CA0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6CA0);
    after_0:
    // 0x8000C1F0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8000C1F4: jal         0x8000FAE4
    // 0x8000C1F8: lw          $a0, -0x6C9C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6C9C);
    func_8000FAE4(rdram, ctx);
        goto after_1;
    // 0x8000C1F8: lw          $a0, -0x6C9C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6C9C);
    after_1:
    // 0x8000C1FC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8000C200: jal         0x8000FAE4
    // 0x8000C204: lw          $a0, -0x6C98($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6C98);
    func_8000FAE4(rdram, ctx);
        goto after_2;
    // 0x8000C204: lw          $a0, -0x6C98($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6C98);
    after_2:
    // 0x8000C208: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8000C20C: jal         0x8000FAE4
    // 0x8000C210: lw          $a0, -0x6C94($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6C94);
    func_8000FAE4(rdram, ctx);
        goto after_3;
    // 0x8000C210: lw          $a0, -0x6C94($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6C94);
    after_3:
    // 0x8000C214: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8000C218: jal         0x8000FAE4
    // 0x8000C21C: lw          $a0, -0x6C90($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6C90);
    func_8000FAE4(rdram, ctx);
        goto after_4;
    // 0x8000C21C: lw          $a0, -0x6C90($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6C90);
    after_4:
    // 0x8000C220: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8000C224: jal         0x8000FAE4
    // 0x8000C228: lw          $a0, -0x6C8C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6C8C);
    func_8000FAE4(rdram, ctx);
        goto after_5;
    // 0x8000C228: lw          $a0, -0x6C8C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6C8C);
    after_5:
    // 0x8000C22C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8000C230: jal         0x8000FAE4
    // 0x8000C234: lw          $a0, -0x6C88($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6C88);
    func_8000FAE4(rdram, ctx);
        goto after_6;
    // 0x8000C234: lw          $a0, -0x6C88($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6C88);
    after_6:
    // 0x8000C238: jal         0x8004B898
    // 0x8000C23C: nop

    func_8004B898(rdram, ctx);
        goto after_7;
    // 0x8000C23C: nop

    after_7:
    // 0x8000C240: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8000C244: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8000C248: addiu       $a1, $a1, -0x6C70
    ctx->r5 = ADD32(ctx->r5, -0X6C70);
    // 0x8000C24C: jal         0x800102D4
    // 0x8000C250: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    func_800102D4(rdram, ctx);
        goto after_8;
    // 0x8000C250: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    after_8:
    // 0x8000C254: jal         0x8000F95C
    // 0x8000C258: nop

    func_8000F95C(rdram, ctx);
        goto after_9;
    // 0x8000C258: nop

    after_9:
    // 0x8000C25C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000C260: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000C264: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000C26C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000C26C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8000C270: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8000C274: lui         $s2, 0x800F
    ctx->r18 = S32(0X800F << 16);
    // 0x8000C278: addiu       $s2, $s2, -0x6CC0
    ctx->r18 = ADD32(ctx->r18, -0X6CC0);
    // 0x8000C27C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8000C280: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8000C284: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8000C288: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8000C28C: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x8000C290: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8000C294: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8000C298: lui         $s0, 0x800F
    ctx->r16 = S32(0X800F << 16);
    // 0x8000C29C: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x8000C2A0: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x8000C2A4: sh          $t7, -0x6CBC($at)
    MEM_H(-0X6CBC, ctx->r1) = ctx->r15;
    // 0x8000C2A8: addiu       $s3, $s3, 0x6AC0
    ctx->r19 = ADD32(ctx->r19, 0X6AC0);
    // 0x8000C2AC: addiu       $s1, $s1, -0x6CB8
    ctx->r17 = ADD32(ctx->r17, -0X6CB8);
    // 0x8000C2B0: addiu       $s0, $s0, -0x6CB4
    ctx->r16 = ADD32(ctx->r16, -0X6CB4);
    // 0x8000C2B4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8000C2B8: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8000C2BC: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8000C2C0: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8000C2C4: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8000C2C8: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8000C2CC: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8000C2D0: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // 0x8000C2D4: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x8000C2D8: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
    // 0x8000C2DC: jal         0x8000C4C0
    // 0x8000C2E0: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    func_8000C4C0(rdram, ctx);
        goto after_0;
    // 0x8000C2E0: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    after_0:
    // 0x8000C2E4: lui         $s5, 0x800F
    ctx->r21 = S32(0X800F << 16);
    // 0x8000C2E8: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x8000C2EC: addiu       $s5, $s5, -0x79C8
    ctx->r21 = ADD32(ctx->r21, -0X79C8);
    // 0x8000C2F0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8000C2F4: addiu       $t8, $t8, -0x7018
    ctx->r24 = ADD32(ctx->r24, -0X7018);
    // 0x8000C2F8: lui         $a2, 0x8001
    ctx->r6 = S32(0X8001 << 16);
    // 0x8000C2FC: addiu       $t9, $zero, 0x12
    ctx->r25 = ADD32(0, 0X12);
    // 0x8000C300: sw          $zero, -0x6CC4($at)
    MEM_W(-0X6CC4, ctx->r1) = 0;
    // 0x8000C304: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8000C308: addiu       $a2, $a2, -0x3F60
    ctx->r6 = ADD32(ctx->r6, -0X3F60);
    // 0x8000C30C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8000C310: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8000C314: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8000C318: jal         0x800527B0
    // 0x8000C31C: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_1;
    // 0x8000C31C: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_1:
    // 0x8000C320: jal         0x80052570
    // 0x8000C324: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    osStartThread_recomp(rdram, ctx);
        goto after_2;
    // 0x8000C324: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_2:
    // 0x8000C328: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x8000C32C: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x8000C330: addiu       $s4, $s4, -0x1CA0
    ctx->r20 = ADD32(ctx->r20, -0X1CA0);
    // 0x8000C334: addiu       $fp, $fp, -0x2E10
    ctx->r30 = ADD32(ctx->r30, -0X2E10);
    // 0x8000C338: addiu       $s7, $zero, 0x4
    ctx->r23 = ADD32(0, 0X4);
    // 0x8000C33C: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x8000C340: addiu       $s5, $sp, 0x54
    ctx->r21 = ADD32(ctx->r29, 0X54);
L_8000C344:
    {
        extern void set_game_client_registered(int registered);
        set_game_client_registered(1);
        static int s_loop_count = 0;
        if (++s_loop_count <= 5 || (s_loop_count % 60) == 0) {
            runtime_log("[Thread 6 Game Loop] Iteration #%d waiting on retrace mq=0x%08X", s_loop_count, (uint32_t)ctx->r20);
        }
    }
    // 0x8000C344: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_8000C348:
    // 0x8000C348: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8000C34C: jal         0x8004F990
    // 0x8000C350: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x8000C350: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_3:
    // 0x8000C354: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x8000C358: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000C35C: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x8000C360: beql        $v0, $s6, L_8000C384
    if (ctx->r2 == ctx->r22) {
        // 0x8000C364: lw          $t1, 0x0($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X0);
            goto L_8000C384;
    }
    goto skip_0;
    // 0x8000C364: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x8000C368: beql        $v0, $at, L_8000C458
    if (ctx->r2 == ctx->r1) {
        // 0x8000C36C: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_8000C458;
    }
    goto skip_1;
    // 0x8000C36C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x8000C370: beql        $v0, $s7, L_8000C484
    if (ctx->r2 == ctx->r23) {
        // 0x8000C374: lw          $t6, 0x0($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X0);
            goto L_8000C484;
    }
    goto skip_2;
    // 0x8000C374: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x8000C378: b           L_8000C348
    // 0x8000C37C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
        goto L_8000C348;
    // 0x8000C37C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8000C380: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
L_8000C384:
    // 0x8000C384: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x8000C388: sltiu       $at, $t1, 0x2
    ctx->r1 = ctx->r9 < 0X2 ? 1 : 0;
    // 0x8000C38C: beql        $at, $zero, L_8000C348
    if (ctx->r1 == 0) {
        // 0x8000C390: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_8000C348;
    }
    goto skip_3;
    // 0x8000C390: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_3:
    // 0x8000C394: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x8000C398: lh          $t3, -0x6CBC($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X6CBC);
    // 0x8000C39C: sltu        $at, $t2, $t3
    ctx->r1 = ctx->r10 < ctx->r11 ? 1 : 0;
    // 0x8000C3A0: bnel        $at, $zero, L_8000C348
    if (ctx->r1 != 0) {
        // 0x8000C3A4: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_8000C348;
    }
    goto skip_4;
    // 0x8000C3A4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_4:
    // 0x8000C3A8: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x8000C3AC: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    // 0x8000C3B0: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8000C3B4: jal         0x80007B60
    // 0x8000C3B8: sw          $t5, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r13;
    func_80007B60(rdram, ctx);
        goto after_4;
    // 0x8000C3B8: sw          $t5, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r13;
    after_4:
    // 0x8000C3BC: jal         0x8000A9E0
    // 0x8000C3C0: nop

    func_8000A9E0(rdram, ctx);
        goto after_5;
    // 0x8000C3C0: nop

    after_5:
    // 0x8000C3C4: lh          $t6, 0x0($fp)
    ctx->r14 = MEM_H(ctx->r30, 0X0);
    // 0x8000C3C8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8000C3CC: beql        $t6, $zero, L_8000C3F8
    if (ctx->r14 == 0) {
        // 0x8000C3D0: lw          $t9, 0x0($s1)
        ctx->r25 = MEM_W(ctx->r17, 0X0);
            goto L_8000C3F8;
    }
    goto skip_5;
    // 0x8000C3D0: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    skip_5:
    // 0x8000C3D4: lw          $t7, -0x2E40($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2E40);
    // 0x8000C3D8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000C3DC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8000C3E0: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8000C3E4: beq         $t8, $zero, L_8000C3F4
    if (ctx->r24 == 0) {
        // 0x8000C3E8: addiu       $a0, $a0, -0x2E38
        ctx->r4 = ADD32(ctx->r4, -0X2E38);
            goto L_8000C3F4;
    }
    // 0x8000C3E8: addiu       $a0, $a0, -0x2E38
    ctx->r4 = ADD32(ctx->r4, -0X2E38);
    // 0x8000C3EC: jal         0x80055500
    // 0x8000C3F0: sh          $zero, -0x6CB0($at)
    MEM_H(-0X6CB0, ctx->r1) = 0;
    osContStartReadData_recomp(rdram, ctx);
        goto after_6;
    // 0x8000C3F0: sh          $zero, -0x6CB0($at)
    MEM_H(-0X6CB0, ctx->r1) = 0;
    after_6:
L_8000C3F4:
    // 0x8000C3F4: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
L_8000C3F8:
    // 0x8000C3F8: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8000C3FC: addiu       $t1, $t1, -0x1C60
    ctx->r9 = ADD32(ctx->r9, -0X1C60);
    // 0x8000C400: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8000C404: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8000C408: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8000C40C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8000C410: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8000C414: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8000C418: sll         $t0, $t0, 7
    ctx->r8 = S32(ctx->r8 << 7);
    // 0x8000C41C: jal         0x8000AEF4
    // 0x8000C420: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    func_8000AEF4(rdram, ctx);
        goto after_7;
    // 0x8000C420: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    after_7:
    // 0x8000C424: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000C428: bnel        $v0, $zero, L_8000C440
    if (ctx->r2 != 0) {
        // 0x8000C42C: lw          $t3, 0x0($s1)
        ctx->r11 = MEM_W(ctx->r17, 0X0);
            goto L_8000C440;
    }
    goto skip_6;
    // 0x8000C42C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    skip_6:
    // 0x8000C430: jal         0x8000C1DC
    // 0x8000C434: nop

    func_8000C1DC(rdram, ctx);
        goto after_8;
    // 0x8000C434: nop

    after_8:
    // 0x8000C438: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000C43C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
L_8000C440:
    // 0x8000C440: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x8000C444: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8000C448: xori        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 ^ 0X1;
    // 0x8000C44C: b           L_8000C344
    // 0x8000C450: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
        goto L_8000C344;
    // 0x8000C450: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x8000C454: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8000C458:
    // 0x8000C458: sltiu       $at, $v0, 0x2
    ctx->r1 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x8000C45C: bne         $at, $zero, L_8000C470
    if (ctx->r1 != 0) {
        // 0x8000C460: nop
    
            goto L_8000C470;
    }
    // 0x8000C460: nop

    // 0x8000C464: jal         0x8000C1DC
    // 0x8000C468: nop

    func_8000C1DC(rdram, ctx);
        goto after_9;
    // 0x8000C468: nop

    after_9:
    // 0x8000C46C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8000C470:
    // 0x8000C470: beq         $v0, $zero, L_8000C344
    if (ctx->r2 == 0) {
        // 0x8000C474: addiu       $t5, $v0, -0x1
        ctx->r13 = ADD32(ctx->r2, -0X1);
            goto L_8000C344;
    }
    // 0x8000C474: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x8000C478: b           L_8000C344
    // 0x8000C47C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
        goto L_8000C344;
    // 0x8000C47C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8000C480: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
L_8000C484:
    // 0x8000C484: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x8000C488: b           L_8000C344
    // 0x8000C48C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
        goto L_8000C344;
    // 0x8000C48C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8000C490: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8000C494: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8000C498: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8000C49C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8000C4A0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8000C4A4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8000C4A8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8000C4AC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8000C4B0: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8000C4B4: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8000C4B8: jr          $ra
    // 0x8000C4BC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    TRACE_RETURN()
    return;
    // 0x8000C4BC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_8000C4C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000C4C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000C4C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000C4C8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8000C4CC: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x8000C4D0: addiu       $a1, $a1, -0x6CC8
    ctx->r5 = ADD32(ctx->r5, -0X6CC8);
    // 0x8000C4D4: addiu       $a0, $a0, -0x6CE0
    ctx->r4 = ADD32(ctx->r4, -0X6CE0);
    // 0x8000C4D8: jal         0x80052780
    // 0x8000C4DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x8000C4DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8000C4E0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000C4E4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000C4E8: addiu       $a1, $a1, -0x1C88
    ctx->r5 = ADD32(ctx->r5, -0X1C88);
    // 0x8000C4EC: addiu       $a0, $a0, -0x1CA0
    ctx->r4 = ADD32(ctx->r4, -0X1CA0);
    // 0x8000C4F0: jal         0x80052780
    // 0x8000C4F4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x8000C4F4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
    // 0x8000C4F8: jal         0x80010370
    // 0x8000C4FC: nop

    func_80010370(rdram, ctx);
        goto after_2;
    // 0x8000C4FC: nop

    after_2:
    // 0x8000C500: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8000C504: lui         $a1, 0x20
    ctx->r5 = S32(0X20 << 16);
    // 0x8000C508: ori         $a1, $a1, 0x800
    ctx->r5 = ctx->r5 | 0X800;
    // 0x8000C50C: jal         0x80004240
    // 0x8000C510: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    func_80004240(rdram, ctx);
        goto after_3;
    // 0x8000C510: addiu       $a0, $a0, 0x2800
    ctx->r4 = ADD32(ctx->r4, 0X2800);
    after_3:
    // 0x8000C514: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8000C518: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8000C51C: addiu       $a1, $a1, -0x6C60
    ctx->r5 = ADD32(ctx->r5, -0X6C60);
    // 0x8000C520: jal         0x80010220
    // 0x8000C524: addiu       $a0, $a0, -0x6C70
    ctx->r4 = ADD32(ctx->r4, -0X6C70);
    func_80010220(rdram, ctx);
        goto after_4;
    // 0x8000C524: addiu       $a0, $a0, -0x6C70
    ctx->r4 = ADD32(ctx->r4, -0X6C70);
    after_4:
    // 0x8000C528: jal         0x8000F5D0
    // 0x8000C52C: nop

    func_8000F5D0(rdram, ctx);
        goto after_5;
    // 0x8000C52C: nop

    after_5:
    // 0x8000C530: lui         $a0, 0x803A
    ctx->r4 = S32(0X803A << 16);
    // 0x8000C534: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x8000C538: ori         $a1, $a1, 0x2000
    ctx->r5 = ctx->r5 | 0X2000;
    // 0x8000C53C: addiu       $a0, $a0, 0x3000
    ctx->r4 = ADD32(ctx->r4, 0X3000);
    // 0x8000C540: jal         0x80004C20
    // 0x8000C544: addiu       $a2, $zero, 0x1100
    ctx->r6 = ADD32(0, 0X1100);
    func_80004C20(rdram, ctx);
        goto after_6;
    // 0x8000C544: addiu       $a2, $zero, 0x1100
    ctx->r6 = ADD32(0, 0X1100);
    after_6:
    // 0x8000C548: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x8000C54C: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x8000C550: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000C554: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000C558: bne         $t6, $at, L_8000C568
    if (ctx->r14 != ctx->r1) {
        // 0x8000C55C: addiu       $a0, $a0, 0x46A0
        ctx->r4 = ADD32(ctx->r4, 0X46A0);
            goto L_8000C568;
    }
    // 0x8000C55C: addiu       $a0, $a0, 0x46A0
    ctx->r4 = ADD32(ctx->r4, 0X46A0);
    // 0x8000C560: b           L_8000C56C
    // 0x8000C564: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
        goto L_8000C56C;
    // 0x8000C564: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8000C568:
    // 0x8000C568: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
L_8000C56C:
    // 0x8000C56C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000C570: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8000C574: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8000C578: addiu       $a1, $a1, 0x6930
    ctx->r5 = ADD32(ctx->r5, 0X6930);
    // 0x8000C57C: jal         0x80053110
    // 0x8000C580: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    func_80053110(rdram, ctx);
        goto after_7;
    // 0x8000C580: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_7:
    // 0x8000C584: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000C588: jal         0x80053030
    // 0x8000C58C: addiu       $a0, $a0, 0x46A0
    ctx->r4 = ADD32(ctx->r4, 0X46A0);
    func_80053030(rdram, ctx);
        goto after_8;
    // 0x8000C58C: addiu       $a0, $a0, 0x46A0
    ctx->r4 = ADD32(ctx->r4, 0X46A0);
    after_8:
    // 0x8000C590: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000C594: jal         0x8000A2B0
    // 0x8000C598: sw          $v0, 0x4928($at)
    MEM_W(0X4928, ctx->r1) = ctx->r2;
    func_8000A2B0(rdram, ctx);
        goto after_9;
    // 0x8000C598: sw          $v0, 0x4928($at)
    MEM_W(0X4928, ctx->r1) = ctx->r2;
    after_9:
    // 0x8000C59C: jal         0x8000ADD0
    // 0x8000C5A0: nop

    func_8000ADD0(rdram, ctx);
        goto after_10;
    // 0x8000C5A0: nop

    after_10:
    // 0x8000C5A4: jal         0x800086E4
    // 0x8000C5A8: nop

    func_800086E4(rdram, ctx);
        goto after_11;
    // 0x8000C5A8: nop

    after_11:
    // 0x8000C5AC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000C5B0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000C5B4: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8000C5B8: addiu       $a2, $a2, -0x1CA0
    ctx->r6 = ADD32(ctx->r6, -0X1CA0);
    // 0x8000C5BC: addiu       $a1, $a1, 0x6930
    ctx->r5 = ADD32(ctx->r5, 0X6930);
    // 0x8000C5C0: jal         0x800530C0
    // 0x8000C5C4: addiu       $a0, $a0, 0x46A0
    ctx->r4 = ADD32(ctx->r4, 0X46A0);
    func_800530C0(rdram, ctx);
        goto after_12;
    // 0x8000C5C4: addiu       $a0, $a0, 0x46A0
    ctx->r4 = ADD32(ctx->r4, 0X46A0);
    after_12:
    // 0x8000C5C8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000C5CC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000C5D0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8000C5D4: addiu       $a2, $a2, -0x2E38
    ctx->r6 = ADD32(ctx->r6, -0X2E38);
    // 0x8000C5D8: addiu       $a1, $a1, 0x6938
    ctx->r5 = ADD32(ctx->r5, 0X6938);
    // 0x8000C5DC: jal         0x800530C0
    // 0x8000C5E0: addiu       $a0, $a0, 0x46A0
    ctx->r4 = ADD32(ctx->r4, 0X46A0);
    func_800530C0(rdram, ctx);
        goto after_13;
    // 0x8000C5E0: addiu       $a0, $a0, 0x46A0
    ctx->r4 = ADD32(ctx->r4, 0X46A0);
    after_13:
    // 0x8000C5E4: jal         0x80011550
    // 0x8000C5E8: nop

    func_80011550(rdram, ctx);
        goto after_14;
    // 0x8000C5E8: nop

    after_14:
    // 0x8000C5EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C5F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000C5F4: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void dma_read_rom(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000C5FC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8000C600: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8000C604: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8000C608: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8000C60C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8000C610: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8000C614: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x8000C618: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8000C61C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8000C620: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x8000C624: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x8000C628: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x8000C62C: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8000C630: jal         0x80056440
    // 0x8000C634: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    osInvalDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x8000C634: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x8000C638: slti        $at, $s3, 0x400
    ctx->r1 = SIGNED(ctx->r19) < 0X400 ? 1 : 0;
    // 0x8000C63C: bne         $at, $zero, L_8000C698
    if (ctx->r1 != 0) {
        // 0x8000C640: addiu       $s5, $sp, 0x44
        ctx->r21 = ADD32(ctx->r29, 0X44);
            goto L_8000C698;
    }
    // 0x8000C640: addiu       $s5, $sp, 0x44
    ctx->r21 = ADD32(ctx->r29, 0X44);
    // 0x8000C644: lui         $s3, 0x800F
    ctx->r19 = S32(0X800F << 16);
    // 0x8000C648: addiu       $s3, $s3, -0x6CE0
    ctx->r19 = ADD32(ctx->r19, -0X6CE0);
    // 0x8000C64C: addiu       $s4, $sp, 0x48
    ctx->r20 = ADD32(ctx->r29, 0X48);
L_8000C650:
    // 0x8000C650: addiu       $t6, $zero, 0x400
    ctx->r14 = ADD32(0, 0X400);
    // 0x8000C654: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8000C658: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8000C65C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000C660: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000C664: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x8000C668: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x8000C66C: jal         0x80053EC0
    // 0x8000C670: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    osPiStartDma_recomp(rdram, ctx);
        goto after_1;
    // 0x8000C670: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    after_1:
    // 0x8000C674: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000C678: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8000C67C: jal         0x8004F990
    // 0x8000C680: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x8000C680: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8000C684: addiu       $s0, $s0, -0x400
    ctx->r16 = ADD32(ctx->r16, -0X400);
    // 0x8000C688: slti        $at, $s0, 0x400
    ctx->r1 = SIGNED(ctx->r16) < 0X400 ? 1 : 0;
    // 0x8000C68C: addiu       $s2, $s2, 0x400
    ctx->r18 = ADD32(ctx->r18, 0X400);
    // 0x8000C690: beq         $at, $zero, L_8000C650
    if (ctx->r1 == 0) {
        // 0x8000C694: addiu       $s1, $s1, 0x400
        ctx->r17 = ADD32(ctx->r17, 0X400);
            goto L_8000C650;
    }
    // 0x8000C694: addiu       $s1, $s1, 0x400
    ctx->r17 = ADD32(ctx->r17, 0X400);
L_8000C698:
    // 0x8000C698: lui         $s3, 0x800F
    ctx->r19 = S32(0X800F << 16);
    // 0x8000C69C: addiu       $s3, $s3, -0x6CE0
    ctx->r19 = ADD32(ctx->r19, -0X6CE0);
    // 0x8000C6A0: addiu       $s4, $sp, 0x48
    ctx->r20 = ADD32(ctx->r29, 0X48);
    // 0x8000C6A4: beq         $s0, $zero, L_8000C6DC
    if (ctx->r16 == 0) {
        // 0x8000C6A8: addiu       $s5, $sp, 0x44
        ctx->r21 = ADD32(ctx->r29, 0X44);
            goto L_8000C6DC;
    }
    // 0x8000C6A8: addiu       $s5, $sp, 0x44
    ctx->r21 = ADD32(ctx->r29, 0X44);
    // 0x8000C6AC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8000C6B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000C6B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000C6B8: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x8000C6BC: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x8000C6C0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000C6C4: jal         0x80053EC0
    // 0x8000C6C8: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    osPiStartDma_recomp(rdram, ctx);
        goto after_3;
    // 0x8000C6C8: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    after_3:
    // 0x8000C6CC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000C6D0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8000C6D4: jal         0x8004F990
    // 0x8000C6D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x8000C6D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
L_8000C6DC:
    // 0x8000C6DC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8000C6E0: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8000C6E4: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8000C6E8: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x8000C6EC: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x8000C6F0: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x8000C6F4: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x8000C6F8: jr          $ra
    // 0x8000C6FC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    TRACE_RETURN()
    return;
    // 0x8000C6FC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_8000C700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000C700: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000C704: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000C708: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000C70C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000C710: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000C714: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000C718: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000C71C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000C720: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8000C724: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
    // 0x8000C728: addiu       $s3, $zero, -0x2
    ctx->r19 = ADD32(0, -0X2);
    // 0x8000C72C: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // 0x8000C730: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8000C734:
    // 0x8000C734: beq         $v0, $s1, L_8000C74C
    if (ctx->r2 == ctx->r17) {
        // 0x8000C738: nop
    
            goto L_8000C74C;
    }
    // 0x8000C738: nop

    // 0x8000C73C: beq         $v0, $s2, L_8000C764
    if (ctx->r2 == ctx->r18) {
        // 0x8000C740: nop
    
            goto L_8000C764;
    }
    // 0x8000C740: nop

    // 0x8000C744: b           L_8000C778
    // 0x8000C748: nop

        goto L_8000C778;
    // 0x8000C748: nop

L_8000C74C:
    // 0x8000C74C: jal         0x8004D1F0
    // 0x8000C750: nop

    func_8004D1F0(rdram, ctx);
        goto after_0;
    // 0x8000C750: nop

    after_0:
    // 0x8000C754: bne         $v0, $zero, L_8000C778
    if (ctx->r2 != 0) {
        // 0x8000C758: nop
    
            goto L_8000C778;
    }
    // 0x8000C758: nop

    // 0x8000C75C: b           L_8000C778
    // 0x8000C760: sw          $s4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r20;
        goto L_8000C778;
    // 0x8000C760: sw          $s4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r20;
L_8000C764:
    // 0x8000C764: jal         0x8004D1F0
    // 0x8000C768: nop

    func_8004D1F0(rdram, ctx);
        goto after_1;
    // 0x8000C768: nop

    after_1:
    // 0x8000C76C: bne         $v0, $zero, L_8000C778
    if (ctx->r2 != 0) {
        // 0x8000C770: nop
    
            goto L_8000C778;
    }
    // 0x8000C770: nop

    // 0x8000C774: sw          $s3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r19;
L_8000C778:
    // 0x8000C778: jal         0x8000798C
    // 0x8000C77C: nop

    func_8000798C(rdram, ctx);
        goto after_2;
    // 0x8000C77C: nop

    after_2:
    // 0x8000C780: b           L_8000C734
    // 0x8000C784: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_8000C734;
    // 0x8000C784: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000C788: nop

    // 0x8000C78C: nop

    // 0x8000C790: nop

    // 0x8000C794: nop

    // 0x8000C798: nop

    // 0x8000C79C: nop

    // 0x8000C7A0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000C7A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000C7A8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C7AC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000C7B0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000C7B4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8000C7B8: jr          $ra
    // 0x8000C7BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    TRACE_RETURN()
    return;
    // 0x8000C7BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8000C7C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000C7C0: andi        $t6, $a1, 0x3
    ctx->r14 = ctx->r5 & 0X3;
    // 0x8000C7C4: beq         $t6, $zero, L_8000C7F8
    if (ctx->r14 == 0) {
        // 0x8000C7C8: sra         $v1, $a1, 2
        ctx->r3 = S32(SIGNED(ctx->r5) >> 2);
            goto L_8000C7F8;
    }
    // 0x8000C7C8: sra         $v1, $a1, 2
    ctx->r3 = S32(SIGNED(ctx->r5) >> 2);
    // 0x8000C7CC: sra         $v1, $a1, 1
    ctx->r3 = S32(SIGNED(ctx->r5) >> 1);
    // 0x8000C7D0: blez        $v1, L_8000C818
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8000C7D4: sll         $t7, $v1, 1
        ctx->r15 = S32(ctx->r3 << 1);
            goto L_8000C818;
    }
    // 0x8000C7D4: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x8000C7D8: addu        $v1, $t7, $a0
    ctx->r3 = ADD32(ctx->r15, ctx->r4);
    // 0x8000C7DC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
L_8000C7E0:
    // 0x8000C7E0: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8000C7E4: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x8000C7E8: bne         $at, $zero, L_8000C7E0
    if (ctx->r1 != 0) {
        // 0x8000C7EC: sh          $zero, -0x2($a1)
        MEM_H(-0X2, ctx->r5) = 0;
            goto L_8000C7E0;
    }
    // 0x8000C7EC: sh          $zero, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = 0;
    // 0x8000C7F0: jr          $ra
    // 0x8000C7F4: nop

    TRACE_RETURN()
    return;
    // 0x8000C7F4: nop

L_8000C7F8:
    // 0x8000C7F8: blez        $v1, L_8000C818
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8000C7FC: sll         $t8, $v1, 2
        ctx->r24 = S32(ctx->r3 << 2);
            goto L_8000C818;
    }
    // 0x8000C7FC: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x8000C800: addu        $v1, $t8, $a0
    ctx->r3 = ADD32(ctx->r24, ctx->r4);
    // 0x8000C804: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
L_8000C808:
    // 0x8000C808: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8000C80C: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x8000C810: bne         $at, $zero, L_8000C808
    if (ctx->r1 != 0) {
        // 0x8000C814: sw          $zero, -0x4($a1)
        MEM_W(-0X4, ctx->r5) = 0;
            goto L_8000C808;
    }
    // 0x8000C814: sw          $zero, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = 0;
L_8000C818:
    // 0x8000C818: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000C820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000C820: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000C824: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000C828: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000C82C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000C830: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000C834: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x8000C838: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000C83C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000C840: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8000C844: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
L_8000C848:
    // 0x8000C848: jal         0x8000E35C
    // 0x8000C84C: nop

    func_8000E35C(rdram, ctx);
        goto after_0;
    // 0x8000C84C: nop

    after_0:
    // 0x8000C850: and         $t6, $v0, $s3
    ctx->r14 = ctx->r2 & ctx->r19;
    // 0x8000C854: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8000C858: nop

    // 0x8000C85C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000C860: jal         0x8000E35C
    // 0x8000C864: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    func_8000E35C(rdram, ctx);
        goto after_1;
    // 0x8000C864: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    after_1:
    // 0x8000C868: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x8000C86C: beq         $t7, $zero, L_8000C880
    if (ctx->r15 == 0) {
        // 0x8000C870: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8000C880;
    }
    // 0x8000C870: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8000C874: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8000C878: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8000C87C: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
L_8000C880:
    // 0x8000C880: bne         $s1, $s2, L_8000C848
    if (ctx->r17 != ctx->r18) {
        // 0x8000C884: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8000C848;
    }
    // 0x8000C884: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000C888: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000C88C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000C890: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000C894: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C898: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8000C89C: jr          $ra
    // 0x8000C8A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    TRACE_RETURN()
    return;
    // 0x8000C8A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8000C8A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000C8A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000C8A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000C8AC: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8000C8B0: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8000C8B4: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000C8B8: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8000C8BC: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8000C8C0: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8000C8C4: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8000C8C8: nop

    // 0x8000C8CC: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8000C8D0: jal         0x8004F640
    // 0x8000C8D4: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    func_8004F640(rdram, ctx);
        goto after_0;
    // 0x8000C8D4: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_0:
    // 0x8000C8D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000C8DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000C8E0: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000C8E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000C8E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000C8EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000C8F0: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000C8F4: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x8000C8F8: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8000C8FC: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x8000C900: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8000C904: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8000C908: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8000C90C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8000C910: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8000C914: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8000C918: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8000C91C: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8000C920: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8000C924: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8000C928: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8000C92C: nop

    // 0x8000C930: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8000C934: jal         0x8004F640
    // 0x8000C938: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    func_8004F640(rdram, ctx);
        goto after_0;
    // 0x8000C938: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x8000C93C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000C940: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000C944: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000C94C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000C94C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8000C950: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000C954: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8000C958: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8000C95C: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x8000C960: addiu       $a2, $a2, 0x6940
    ctx->r6 = ADD32(ctx->r6, 0X6940);
    // 0x8000C964: jal         0x80000FE4
    // 0x8000C968: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    func_80000FE4(rdram, ctx);
        goto after_0;
    // 0x8000C968: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_0:
    // 0x8000C96C: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    // 0x8000C970: addiu       $v1, $sp, 0x30
    ctx->r3 = ADD32(ctx->r29, 0X30);
    // 0x8000C974: addiu       $v0, $sp, 0x4C
    ctx->r2 = ADD32(ctx->r29, 0X4C);
    // 0x8000C978: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
L_8000C97C:
    // 0x8000C97C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000C980: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8000C984: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000C988: bne         $v0, $a0, L_8000C97C
    if (ctx->r2 != ctx->r4) {
        // 0x8000C98C: swc1        $f4, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
            goto L_8000C97C;
    }
    // 0x8000C98C: swc1        $f4, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
    // 0x8000C990: lwc1        $f0, 0x54($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8000C994: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8000C998: addiu       $a2, $a2, 0x6980
    ctx->r6 = ADD32(ctx->r6, 0X6980);
    // 0x8000C99C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8000C9A0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8000C9A4: jal         0x80000FE4
    // 0x8000C9A8: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    func_80000FE4(rdram, ctx);
        goto after_1;
    // 0x8000C9A8: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8000C9AC: jal         0x8000E16C
    // 0x8000C9B0: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    func_8000E16C(rdram, ctx);
        goto after_2;
    // 0x8000C9B0: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    after_2:
    // 0x8000C9B4: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8000C9B8: jal         0x8000E16C
    // 0x8000C9BC: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    func_8000E16C(rdram, ctx);
        goto after_3;
    // 0x8000C9BC: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x8000C9C0: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8000C9C4: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8000C9C8: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8000C9CC: nop

    // 0x8000C9D0: bc1fl       L_8000CA2C
    if (!c1cs) {
        // 0x8000C9D4: lw          $t7, 0x3C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X3C);
            goto L_8000CA2C;
    }
    goto skip_0;
    // 0x8000C9D4: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x8000C9D8: jal         0x8000E16C
    // 0x8000C9DC: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    func_8000E16C(rdram, ctx);
        goto after_4;
    // 0x8000C9DC: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    after_4:
    // 0x8000C9E0: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8000C9E4: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8000C9E8: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8000C9EC: lwc1        $f0, 0x54($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8000C9F0: bc1fl       L_8000CA2C
    if (!c1cs) {
        // 0x8000C9F4: lw          $t7, 0x3C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X3C);
            goto L_8000CA2C;
    }
    goto skip_1;
    // 0x8000C9F4: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    skip_1:
    // 0x8000C9F8: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x8000C9FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000CA00: bc1fl       L_8000CA2C
    if (!c1cs) {
        // 0x8000CA04: lw          $t7, 0x3C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X3C);
            goto L_8000CA2C;
    }
    goto skip_2;
    // 0x8000CA04: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    skip_2:
    // 0x8000CA08: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000CA0C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8000CA10: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x8000CA14: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x8000CA18: nop

    // 0x8000CA1C: bc1fl       L_8000CA2C
    if (!c1cs) {
        // 0x8000CA20: lw          $t7, 0x3C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X3C);
            goto L_8000CA2C;
    }
    goto skip_3;
    // 0x8000CA20: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    skip_3:
    // 0x8000CA24: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x8000CA28: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
L_8000CA2C:
    // 0x8000CA2C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8000CA30: bne         $t7, $zero, L_8000CA40
    if (ctx->r15 != 0) {
        // 0x8000CA34: nop
    
            goto L_8000CA40;
    }
    // 0x8000CA34: nop

    // 0x8000CA38: b           L_8000CA94
    // 0x8000CA3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000CA94;
    // 0x8000CA3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000CA40:
    // 0x8000CA40: jal         0x8000399C
    // 0x8000CA44: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_8000399C(rdram, ctx);
        goto after_5;
    // 0x8000CA44: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_5:
    // 0x8000CA48: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8000CA4C: addiu       $a2, $a2, 0x6980
    ctx->r6 = ADD32(ctx->r6, 0X6980);
    // 0x8000CA50: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8000CA54: jal         0x80000FE4
    // 0x8000CA58: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80000FE4(rdram, ctx);
        goto after_6;
    // 0x8000CA58: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_6:
    // 0x8000CA5C: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8000CA60: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8000CA64: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8000CA68: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x8000CA6C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8000CA70: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8000CA74: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000CA78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000CA7C: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x8000CA80: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x8000CA84: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8000CA88: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8000CA8C: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x8000CA90: swc1        $f10, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f10.u32l;
L_8000CA94:
    // 0x8000CA94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000CA98: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8000CA9C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000CAA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000CAA4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8000CAA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000CAAC: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x8000CAB0: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8000CAB4: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8000CAB8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000CABC: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8000CAC0: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8000CAC4: bc1f        L_8000CAF0
    if (!c1cs) {
        // 0x8000CAC8: nop
    
            goto L_8000CAF0;
    }
    // 0x8000CAC8: nop

    // 0x8000CACC: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8000CAD0: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8000CAD4: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x8000CAD8: nop

    // 0x8000CADC: bc1f        L_8000CAF0
    if (!c1cs) {
        // 0x8000CAE0: nop
    
            goto L_8000CAF0;
    }
    // 0x8000CAE0: nop

    // 0x8000CAE4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8000CAE8: b           L_8000CCFC
    // 0x8000CAEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000CCFC;
    // 0x8000CAEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000CAF0:
    // 0x8000CAF0: lwc1        $f6, 0x5EB0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5EB0);
    // 0x8000CAF4: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8000CAF8: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8000CAFC: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8000CB00: jal         0x8004F7C0
    // 0x8000CB04: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_8004F7C0(rdram, ctx);
        goto after_0;
    // 0x8000CB04: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x8000CB08: neg.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = -ctx->f0.fl;
    // 0x8000CB0C: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8000CB10: jal         0x8004F650
    // 0x8000CB14: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    func_8004F650(rdram, ctx);
        goto after_1;
    // 0x8000CB14: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x8000CB18: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x8000CB1C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8000CB20: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8000CB24: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x8000CB28: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8000CB2C: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8000CB30: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8000CB34: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8000CB38: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x8000CB3C: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8000CB40: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8000CB44: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8000CB48: c.eq.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl == ctx->f6.fl;
    // 0x8000CB4C: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8000CB50: bc1f        L_8000CB74
    if (!c1cs) {
        // 0x8000CB54: swc1        $f4, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
            goto L_8000CB74;
    }
    // 0x8000CB54: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x8000CB58: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8000CB5C: c.eq.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl == ctx->f8.fl;
    // 0x8000CB60: nop

    // 0x8000CB64: bc1fl       L_8000CB78
    if (!c1cs) {
        // 0x8000CB68: lwc1        $f10, 0x34($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
            goto L_8000CB78;
    }
    goto skip_0;
    // 0x8000CB68: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x8000CB6C: b           L_8000CCF8
    // 0x8000CB70: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_8000CCF8;
    // 0x8000CB70: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
L_8000CB74:
    // 0x8000CB74: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
L_8000CB78:
    // 0x8000CB78: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8000CB7C: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8000CB80: mul.s       $f4, $f10, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8000CB84: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000CB88: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8000CB8C: nop

    // 0x8000CB90: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8000CB94: nop

    // 0x8000CB98: mul.s       $f10, $f18, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8000CB9C: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8000CBA0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8000CBA4: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8000CBA8: mul.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8000CBAC: jal         0x8004F640
    // 0x8000CBB0: nop

    func_8004F640(rdram, ctx);
        goto after_2;
    // 0x8000CBB0: nop

    after_2:
    // 0x8000CBB4: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000CBB8: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8000CBBC: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8000CBC0: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8000CBC4: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8000CBC8: nop

    // 0x8000CBCC: mul.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8000CBD0: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8000CBD4: jal         0x8000E978
    // 0x8000CBD8: div.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    func_8000E978(rdram, ctx);
        goto after_3;
    // 0x8000CBD8: div.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    after_3:
    // 0x8000CBDC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000CBE0: lwc1        $f8, 0x5EB4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5EB4);
    // 0x8000CBE4: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8000CBE8: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x8000CBEC: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8000CBF0: jal         0x8004F7C0
    // 0x8000CBF4: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_8004F7C0(rdram, ctx);
        goto after_4;
    // 0x8000CBF4: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_4:
    // 0x8000CBF8: neg.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = -ctx->f0.fl;
    // 0x8000CBFC: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8000CC00: jal         0x8004F650
    // 0x8000CC04: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    func_8004F650(rdram, ctx);
        goto after_5;
    // 0x8000CC04: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x8000CC08: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8000CC0C: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x8000CC10: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000CC14: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8000CC18: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8000CC1C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8000CC20: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8000CC24: mul.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8000CC28: add.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8000CC2C: c.eq.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
    // 0x8000CC30: nop

    // 0x8000CC34: bc1f        L_8000CC54
    if (!c1cs) {
        // 0x8000CC38: nop
    
            goto L_8000CC54;
    }
    // 0x8000CC38: nop

    // 0x8000CC3C: c.eq.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl == ctx->f16.fl;
    // 0x8000CC40: nop

    // 0x8000CC44: bc1f        L_8000CC54
    if (!c1cs) {
        // 0x8000CC48: nop
    
            goto L_8000CC54;
    }
    // 0x8000CC48: nop

    // 0x8000CC4C: b           L_8000CCF8
    // 0x8000CC50: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_8000CCF8;
    // 0x8000CC50: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
L_8000CC54:
    // 0x8000CC54: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8000CC58: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8000CC5C: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x8000CC60: mul.s       $f6, $f18, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8000CC64: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x8000CC68: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    // 0x8000CC6C: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8000CC70: mul.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8000CC74: jal         0x8004F640
    // 0x8000CC78: nop

    func_8004F640(rdram, ctx);
        goto after_6;
    // 0x8000CC78: nop

    after_6:
    // 0x8000CC7C: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8000CC80: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000CC84: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8000CC88: div.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8000CC8C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000CC90: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8000CC94: add.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8000CC98: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x8000CC9C: nop

    // 0x8000CCA0: bc1f        L_8000CCCC
    if (!c1cs) {
        // 0x8000CCA4: nop
    
            goto L_8000CCCC;
    }
    // 0x8000CCA4: nop

    // 0x8000CCA8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000CCAC: lwc1        $f0, 0x5EB8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5EB8);
    // 0x8000CCB0: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8000CCB4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000CCB8: lwc1        $f6, 0x5EBC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5EBC);
    // 0x8000CCBC: sub.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8000CCC0: add.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8000CCC4: b           L_8000CCD4
    // 0x8000CCC8: div.s       $f2, $f10, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f10.fl, ctx->f6.fl);
        goto L_8000CCD4;
    // 0x8000CCC8: div.s       $f2, $f10, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f10.fl, ctx->f6.fl);
L_8000CCCC:
    // 0x8000CCCC: lwc1        $f4, 0x5EC0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5EC0);
    // 0x8000CCD0: div.s       $f2, $f8, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f4.fl);
L_8000CCD4:
    // 0x8000CCD4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000CCD8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8000CCDC: nop

    // 0x8000CCE0: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8000CCE4: nop

    // 0x8000CCE8: bc1fl       L_8000CCF8
    if (!c1cs) {
        // 0x8000CCEC: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_8000CCF8;
    }
    goto skip_1;
    // 0x8000CCEC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_1:
    // 0x8000CCF0: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8000CCF4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8000CCF8:
    // 0x8000CCF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000CCFC:
    // 0x8000CCFC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8000CD00: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8000CD08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000CD08: addiu       $sp, $sp, -0x110
    ctx->r29 = ADD32(ctx->r29, -0X110);
    // 0x8000CD0C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000CD10: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8000CD14: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8000CD18: sw          $a0, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r4;
    // 0x8000CD1C: sw          $a1, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r5;
    // 0x8000CD20: sw          $a2, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r6;
    // 0x8000CD24: sw          $a3, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r7;
    // 0x8000CD28: lwc1        $f6, 0x0($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8000CD2C: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8000CD30: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8000CD34: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8000CD38: nop

    // 0x8000CD3C: bc1fl       L_8000CD8C
    if (!c1cs) {
        // 0x8000CD40: mtc1        $zero, $f22
        ctx->f22.u32l = 0;
            goto L_8000CD8C;
    }
    goto skip_0;
    // 0x8000CD40: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    skip_0:
    // 0x8000CD44: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8000CD48: lwc1        $f10, 0x8($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8000CD4C: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x8000CD50: nop

    // 0x8000CD54: bc1fl       L_8000CD8C
    if (!c1cs) {
        // 0x8000CD58: mtc1        $zero, $f22
        ctx->f22.u32l = 0;
            goto L_8000CD8C;
    }
    goto skip_1;
    // 0x8000CD58: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    skip_1:
    // 0x8000CD5C: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8000CD60: nop

    // 0x8000CD64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8000CD68:
    // 0x8000CD68: lw          $v0, 0x110($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X110);
    // 0x8000CD6C: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_8000CD70:
    // 0x8000CD70: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8000CD74: swc1        $f22, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f22.u32l;
    // 0x8000CD78: bne         $a0, $v1, L_8000CD70
    if (ctx->r4 != ctx->r3) {
        // 0x8000CD7C: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8000CD70;
    }
    // 0x8000CD7C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8000CD80: b           L_8000D100
    // 0x8000CD84: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8000D100;
    // 0x8000CD84: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000CD88: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
L_8000CD8C:
    // 0x8000CD8C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000CD90: lw          $t8, 0x11C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X11C);
    // 0x8000CD94: lw          $t9, 0x118($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X118);
    // 0x8000CD98: swc1        $f22, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f22.u32l;
    // 0x8000CD9C: swc1        $f22, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f22.u32l;
    // 0x8000CDA0: swc1        $f4, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f4.u32l;
    // 0x8000CDA4: lwc1        $f6, 0x0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8000CDA8: lwc1        $f8, 0x0($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8000CDAC: lwc1        $f4, 0x4($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8000CDB0: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    // 0x8000CDB4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8000CDB8: lwc1        $f6, 0x4($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X4);
    // 0x8000CDBC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8000CDC0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8000CDC4: lwc1        $f10, 0x8($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8000CDC8: lwc1        $f4, 0x8($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X8);
    // 0x8000CDCC: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8000CDD0: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8000CDD4: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8000CDD8: jal         0x80001A6C
    // 0x8000CDDC: nop

    func_80001A6C(rdram, ctx);
        goto after_0;
    // 0x8000CDDC: nop

    after_0:
    // 0x8000CDE0: lw          $t0, 0x114($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X114);
    // 0x8000CDE4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000CDE8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8000CDEC: lwc1        $f8, 0x4($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8000CDF0: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8000CDF4: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8000CDF8: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8000CDFC: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x8000CE00: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8000CE04: jal         0x80049840
    // 0x8000CE08: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    func_80049840(rdram, ctx);
        goto after_1;
    // 0x8000CE08: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    after_1:
    // 0x8000CE0C: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    // 0x8000CE10: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8000CE14: jal         0x80000BD8
    // 0x8000CE18: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    func_80000BD8(rdram, ctx);
        goto after_2;
    // 0x8000CE18: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    after_2:
    // 0x8000CE1C: lw          $t1, 0x114($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X114);
    // 0x8000CE20: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8000CE24: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8000CE28: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8000CE2C: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x8000CE30: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x8000CE34: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8000CE38: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8000CE3C: jal         0x80049840
    // 0x8000CE40: nop

    func_80049840(rdram, ctx);
        goto after_3;
    // 0x8000CE40: nop

    after_3:
    // 0x8000CE44: addiu       $a1, $sp, 0xA8
    ctx->r5 = ADD32(ctx->r29, 0XA8);
    // 0x8000CE48: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8000CE4C: jal         0x80000BD8
    // 0x8000CE50: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    func_80000BD8(rdram, ctx);
        goto after_4;
    // 0x8000CE50: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    after_4:
    // 0x8000CE54: addiu       $v1, $sp, 0xE8
    ctx->r3 = ADD32(ctx->r29, 0XE8);
    // 0x8000CE58: addiu       $v0, $sp, 0xA8
    ctx->r2 = ADD32(ctx->r29, 0XA8);
    // 0x8000CE5C: addiu       $a0, $sp, 0xB4
    ctx->r4 = ADD32(ctx->r29, 0XB4);
L_8000CE60:
    // 0x8000CE60: lwc1        $f8, 0x30($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8000CE64: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8000CE68: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x8000CE6C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000CE70: bne         $at, $zero, L_8000CE60
    if (ctx->r1 != 0) {
        // 0x8000CE74: swc1        $f8, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f8.u32l;
            goto L_8000CE60;
    }
    // 0x8000CE74: swc1        $f8, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f8.u32l;
    // 0x8000CE78: lwc1        $f2, 0xFC($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x8000CE7C: lwc1        $f14, 0xF0($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x8000CE80: lwc1        $f4, 0xEC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x8000CE84: lwc1        $f6, 0xE8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x8000CE88: mul.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x8000CE8C: nop

    // 0x8000CE90: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8000CE94: nop

    // 0x8000CE98: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8000CE9C: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    // 0x8000CEA0: lwc1        $f10, 0xF8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x8000CEA4: mul.s       $f0, $f4, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8000CEA8: swc1        $f16, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f16.u32l;
    // 0x8000CEAC: mul.s       $f8, $f6, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8000CEB0: swc1        $f18, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
    // 0x8000CEB4: mul.s       $f4, $f10, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8000CEB8: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x8000CEBC: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x8000CEC0: add.s       $f8, $f0, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x8000CEC4: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8000CEC8: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8000CECC: jal         0x8004F640
    // 0x8000CED0: nop

    func_8004F640(rdram, ctx);
        goto after_5;
    // 0x8000CED0: nop

    after_5:
    // 0x8000CED4: lwc1        $f10, 0xF8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x8000CED8: lwc1        $f4, 0xEC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x8000CEDC: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8000CEE0: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8000CEE4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8000CEE8: jal         0x8000E978
    // 0x8000CEEC: div.s       $f12, $f10, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    func_8000E978(rdram, ctx);
        goto after_6;
    // 0x8000CEEC: div.s       $f12, $f10, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    after_6:
    // 0x8000CEF0: lwc1        $f2, 0xF4($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x8000CEF4: lwc1        $f16, 0x60($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8000CEF8: lwc1        $f18, 0x5C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8000CEFC: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8000CF00: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8000CF04: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x8000CF08: swc1        $f4, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->f4.u32l;
    // 0x8000CF0C: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8000CF10: add.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8000CF14: mul.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8000CF18: jal         0x8004F640
    // 0x8000CF1C: nop

    func_8004F640(rdram, ctx);
        goto after_7;
    // 0x8000CF1C: nop

    after_7:
    // 0x8000CF20: lwc1        $f6, 0xF4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x8000CF24: lwc1        $f10, 0xE8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x8000CF28: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8000CF2C: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8000CF30: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8000CF34: jal         0x8000E978
    // 0x8000CF38: div.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    func_8000E978(rdram, ctx);
        goto after_8;
    // 0x8000CF38: div.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    after_8:
    // 0x8000CF3C: lwc1        $f14, 0xF0($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x8000CF40: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8000CF44: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000CF48: mul.s       $f4, $f14, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f22.fl);
    // 0x8000CF4C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000CF50: lwc1        $f6, 0xEC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x8000CF54: mul.s       $f16, $f22, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8000CF58: swc1        $f10, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f10.u32l;
    // 0x8000CF5C: swc1        $f8, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f8.u32l;
    // 0x8000CF60: mul.s       $f12, $f14, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8000CF64: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    // 0x8000CF68: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8000CF6C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8000CF70: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8000CF74: swc1        $f0, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f0.u32l;
    // 0x8000CF78: swc1        $f22, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f22.u32l;
    // 0x8000CF7C: mov.s       $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    ctx->f18.fl = ctx->f12.fl;
    // 0x8000CF80: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8000CF84: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8000CF88: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000CF8C: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x8000CF90: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    // 0x8000CF94: c.eq.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl == ctx->f4.fl;
    // 0x8000CF98: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    // 0x8000CF9C: bc1fl       L_8000CFC4
    if (!c1cs) {
        // 0x8000CFA0: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_8000CFC4;
    }
    goto skip_2;
    // 0x8000CFA0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_2:
    // 0x8000CFA4: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x8000CFA8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8000CFAC: nop

    // 0x8000CFB0: c.eq.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl == ctx->f6.fl;
    // 0x8000CFB4: nop

    // 0x8000CFB8: bc1tl       L_8000CD68
    if (c1cs) {
        // 0x8000CFBC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8000CD68;
    }
    goto skip_3;
    // 0x8000CFBC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_3:
    // 0x8000CFC0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_8000CFC4:
    // 0x8000CFC4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000CFC8: swc1        $f16, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f16.u32l;
    // 0x8000CFCC: swc1        $f18, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
    // 0x8000CFD0: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8000CFD4: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8000CFD8: add.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8000CFDC: mul.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8000CFE0: jal         0x8004F640
    // 0x8000CFE4: nop

    func_8004F640(rdram, ctx);
        goto after_9;
    // 0x8000CFE4: nop

    after_9:
    // 0x8000CFE8: lwc1        $f14, 0x4C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8000CFEC: lwc1        $f10, 0xE8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x8000CFF0: lwc1        $f6, 0xF4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x8000CFF4: div.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8000CFF8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8000CFFC: lwc1        $f18, 0x5C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8000D000: lwc1        $f16, 0x60($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8000D004: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8000D008: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8000D00C: lwc1        $f6, 0xF4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x8000D010: add.s       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8000D014: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x8000D018: swc1        $f8, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f8.u32l;
    // 0x8000D01C: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8000D020: add.s       $f14, $f4, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8000D024: c.eq.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl == ctx->f12.fl;
    // 0x8000D028: nop

    // 0x8000D02C: bc1f        L_8000D044
    if (!c1cs) {
        // 0x8000D030: nop
    
            goto L_8000D044;
    }
    // 0x8000D030: nop

    // 0x8000D034: c.eq.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl == ctx->f12.fl;
    // 0x8000D038: nop

    // 0x8000D03C: bc1tl       L_8000CD68
    if (c1cs) {
        // 0x8000D040: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8000CD68;
    }
    goto skip_4;
    // 0x8000D040: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_4:
L_8000D044:
    // 0x8000D044: mul.s       $f4, $f6, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8000D048: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8000D04C: swc1        $f14, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f14.u32l;
    // 0x8000D050: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8000D054: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8000D058: jal         0x8004F640
    // 0x8000D05C: nop

    func_8004F640(rdram, ctx);
        goto after_10;
    // 0x8000D05C: nop

    after_10:
    // 0x8000D060: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8000D064: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000D068: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8000D06C: div.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8000D070: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000D074: lwc1        $f12, 0x5EC4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X5EC4);
    // 0x8000D078: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000D07C: lwc1        $f2, 0x5EC8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5EC8);
    // 0x8000D080: lw          $v0, 0x110($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X110);
    // 0x8000D084: addiu       $a1, $sp, 0x100
    ctx->r5 = ADD32(ctx->r29, 0X100);
    // 0x8000D088: addiu       $v1, $sp, 0x108
    ctx->r3 = ADD32(ctx->r29, 0X108);
    // 0x8000D08C: addiu       $a0, $sp, 0x110
    ctx->r4 = ADD32(ctx->r29, 0X110);
    // 0x8000D090: swc1        $f4, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f4.u32l;
L_8000D094:
    // 0x8000D094: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8000D098: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8000D09C: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x8000D0A0: c.lt.s      $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f10.fl < ctx->f20.fl;
    // 0x8000D0A4: nop

    // 0x8000D0A8: bc1fl       L_8000D0CC
    if (!c1cs) {
        // 0x8000D0AC: lwc1        $f6, 0x0($v1)
        ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
            goto L_8000D0CC;
    }
    goto skip_5;
    // 0x8000D0AC: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    skip_5:
    // 0x8000D0B0: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8000D0B4: sub.s       $f4, $f2, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x8000D0B8: add.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8000D0BC: div.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8000D0C0: b           L_8000D0D4
    // 0x8000D0C4: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
        goto L_8000D0D4;
    // 0x8000D0C4: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x8000D0C8: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
L_8000D0CC:
    // 0x8000D0CC: div.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8000D0D0: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
L_8000D0D4:
    // 0x8000D0D4: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000D0D8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000D0DC: c.le.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl <= ctx->f0.fl;
    // 0x8000D0E0: nop

    // 0x8000D0E4: bc1f        L_8000D0F4
    if (!c1cs) {
        // 0x8000D0E8: nop
    
            goto L_8000D0F4;
    }
    // 0x8000D0E8: nop

    // 0x8000D0EC: sub.s       $f8, $f0, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x8000D0F0: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
L_8000D0F4:
    // 0x8000D0F4: bne         $v1, $a0, L_8000D094
    if (ctx->r3 != ctx->r4) {
        // 0x8000D0F8: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8000D094;
    }
    // 0x8000D0F8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8000D0FC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8000D100:
    // 0x8000D100: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8000D104: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8000D108: jr          $ra
    // 0x8000D10C: addiu       $sp, $sp, 0x110
    ctx->r29 = ADD32(ctx->r29, 0X110);
    TRACE_RETURN()
    return;
    // 0x8000D10C: addiu       $sp, $sp, 0x110
    ctx->r29 = ADD32(ctx->r29, 0X110);
;}
RECOMP_FUNC void func_8000D110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000D110: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000D114: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8000D118: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8000D11C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8000D120: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8000D124: addiu       $v1, $sp, 0x14
    ctx->r3 = ADD32(ctx->r29, 0X14);
    // 0x8000D128: addiu       $v0, $sp, 0x20
    ctx->r2 = ADD32(ctx->r29, 0X20);
L_8000D12C:
    // 0x8000D12C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8000D130: lwc1        $f6, 0xC($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8000D134: lwc1        $f10, 0x18($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X18);
    // 0x8000D138: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000D13C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8000D140: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8000D144: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8000D148: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8000D14C: div.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8000D150: bne         $at, $zero, L_8000D12C
    if (ctx->r1 != 0) {
        // 0x8000D154: swc1        $f18, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
            goto L_8000D12C;
    }
    // 0x8000D154: swc1        $f18, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
    // 0x8000D158: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000D15C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8000D160: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8000D164: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
L_8000D168:
    // 0x8000D168: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8000D16C: addiu       $a2, $sp, 0x14
    ctx->r6 = ADD32(ctx->r29, 0X14);
    // 0x8000D170: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000D174: lwc1        $f14, 0x0($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8000D178: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8000D17C: sub.s       $f14, $f10, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x8000D180: swc1        $f14, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f14.u32l;
    // 0x8000D184: lwc1        $f14, 0x0($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000D188: mul.s       $f18, $f14, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8000D18C: beql        $a2, $a3, L_8000D1D4
    if (ctx->r6 == ctx->r7) {
        // 0x8000D190: swc1        $f18, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
            goto L_8000D1D4;
    }
    goto skip_0;
    // 0x8000D190: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    skip_0:
    // 0x8000D194: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
L_8000D198:
    // 0x8000D198: lwc1        $f16, 0x0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000D19C: lwc1        $f14, -0x4($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, -0X4);
    // 0x8000D1A0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8000D1A4: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000D1A8: add.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f14.fl;
    // 0x8000D1AC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8000D1B0: swc1        $f14, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f14.u32l;
    // 0x8000D1B4: lwc1        $f14, -0x4($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, -0X4);
    // 0x8000D1B8: sub.s       $f14, $f10, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x8000D1BC: swc1        $f14, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f14.u32l;
    // 0x8000D1C0: lwc1        $f14, 0x0($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000D1C4: mul.s       $f18, $f14, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8000D1C8: bnel        $a2, $a3, L_8000D198
    if (ctx->r6 != ctx->r7) {
        // 0x8000D1CC: swc1        $f18, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
            goto L_8000D198;
    }
    goto skip_1;
    // 0x8000D1CC: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    skip_1:
    // 0x8000D1D0: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
L_8000D1D4:
    // 0x8000D1D4: lwc1        $f16, 0x0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000D1D8: lwc1        $f14, -0x4($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, -0X4);
    // 0x8000D1DC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8000D1E0: add.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f14.fl;
    // 0x8000D1E4: swc1        $f14, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f14.u32l;
    // 0x8000D1E8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000D1EC: bne         $v0, $t0, L_8000D168
    if (ctx->r2 != ctx->r8) {
        // 0x8000D1F0: addiu       $a1, $a1, 0xC
        ctx->r5 = ADD32(ctx->r5, 0XC);
            goto L_8000D168;
    }
    // 0x8000D1F0: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    // 0x8000D1F4: jr          $ra
    // 0x8000D1F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    TRACE_RETURN()
    return;
    // 0x8000D1F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8000D1FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000D1FC: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x8000D200: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8000D204: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8000D208: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x8000D20C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8000D210: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8000D214: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8000D218: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8000D21C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8000D220: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8000D224: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8000D228: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8000D22C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8000D230: jal         0x800054B0
    // 0x8000D234: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    func_800054B0(rdram, ctx);
        goto after_0;
    // 0x8000D234: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    after_0:
    // 0x8000D238: bne         $v0, $zero, L_8000D248
    if (ctx->r2 != 0) {
        // 0x8000D23C: addiu       $s6, $sp, 0x8C
        ctx->r22 = ADD32(ctx->r29, 0X8C);
            goto L_8000D248;
    }
    // 0x8000D23C: addiu       $s6, $sp, 0x8C
    ctx->r22 = ADD32(ctx->r29, 0X8C);
    // 0x8000D240: b           L_8000D370
    // 0x8000D244: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000D370;
    // 0x8000D244: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000D248:
    // 0x8000D248: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8000D24C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8000D250: addiu       $a2, $s5, 0xC
    ctx->r6 = ADD32(ctx->r21, 0XC);
    // 0x8000D254: jal         0x800037FC
    // 0x8000D258: addiu       $a3, $s5, 0x18
    ctx->r7 = ADD32(ctx->r21, 0X18);
    func_800037FC(rdram, ctx);
        goto after_1;
    // 0x8000D258: addiu       $a3, $s5, 0x18
    ctx->r7 = ADD32(ctx->r21, 0X18);
    after_1:
    // 0x8000D25C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8000D260: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8000D264: or          $s3, $s5, $zero
    ctx->r19 = ctx->r21 | 0;
    // 0x8000D268: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
    // 0x8000D26C: addiu       $s7, $zero, 0xC
    ctx->r23 = ADD32(0, 0XC);
    // 0x8000D270: addiu       $s4, $sp, 0x80
    ctx->r20 = ADD32(ctx->r29, 0X80);
L_8000D274:
    // 0x8000D274: addiu       $s1, $s2, 0x1
    ctx->r17 = ADD32(ctx->r18, 0X1);
    // 0x8000D278: slti        $at, $s1, 0x3
    ctx->r1 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // 0x8000D27C: bne         $at, $zero, L_8000D288
    if (ctx->r1 != 0) {
        // 0x8000D280: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_8000D288;
    }
    // 0x8000D280: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x8000D284: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8000D288:
    // 0x8000D288: multu       $s0, $s7
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000D28C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8000D290: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8000D294: lw          $a3, 0x98($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X98);
    // 0x8000D298: mflo        $t6
    ctx->r14 = lo;
    // 0x8000D29C: addu        $a2, $s5, $t6
    ctx->r6 = ADD32(ctx->r21, ctx->r14);
    // 0x8000D2A0: jal         0x800037FC
    // 0x8000D2A4: nop

    func_800037FC(rdram, ctx);
        goto after_2;
    // 0x8000D2A4: nop

    after_2:
    // 0x8000D2A8: bne         $v0, $zero, L_8000D344
    if (ctx->r2 != 0) {
        // 0x8000D2AC: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_8000D344;
    }
    // 0x8000D2AC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8000D2B0: sll         $t7, $s2, 2
    ctx->r15 = S32(ctx->r18 << 2);
    // 0x8000D2B4: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x8000D2B8: subu        $t8, $t8, $s0
    ctx->r24 = SUB32(ctx->r24, ctx->r16);
    // 0x8000D2BC: subu        $t7, $t7, $s2
    ctx->r15 = SUB32(ctx->r15, ctx->r18);
    // 0x8000D2C0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8000D2C4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8000D2C8: addu        $a2, $s5, $t8
    ctx->r6 = ADD32(ctx->r21, ctx->r24);
    // 0x8000D2CC: addu        $a1, $s5, $t7
    ctx->r5 = ADD32(ctx->r21, ctx->r15);
    // 0x8000D2D0: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x8000D2D4: lw          $v0, 0x98($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X98);
    // 0x8000D2D8: addiu       $v1, $sp, 0x68
    ctx->r3 = ADD32(ctx->r29, 0X68);
    // 0x8000D2DC: addiu       $a3, $sp, 0x74
    ctx->r7 = ADD32(ctx->r29, 0X74);
L_8000D2E0:
    // 0x8000D2E0: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8000D2E4: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000D2E8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000D2EC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8000D2F0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8000D2F4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8000D2F8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8000D2FC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8000D300: swc1        $f8, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f8.u32l;
    // 0x8000D304: lwc1        $f16, -0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, -0X4);
    // 0x8000D308: lwc1        $f10, -0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, -0X4);
    // 0x8000D30C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8000D310: bne         $v1, $a3, L_8000D2E0
    if (ctx->r3 != ctx->r7) {
        // 0x8000D314: swc1        $f18, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
            goto L_8000D2E0;
    }
    // 0x8000D314: swc1        $f18, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
    // 0x8000D318: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x8000D31C: jal         0x80003730
    // 0x8000D320: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    func_80003730(rdram, ctx);
        goto after_3;
    // 0x8000D320: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    after_3:
    // 0x8000D324: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x8000D328: nop

    // 0x8000D32C: bc1f        L_8000D33C
    if (!c1cs) {
        // 0x8000D330: nop
    
            goto L_8000D33C;
    }
    // 0x8000D330: nop

    // 0x8000D334: b           L_8000D370
    // 0x8000D338: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8000D370;
    // 0x8000D338: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000D33C:
    // 0x8000D33C: b           L_8000D370
    // 0x8000D340: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000D370;
    // 0x8000D340: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000D344:
    // 0x8000D344: jal         0x80003700
    // 0x8000D348: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_80003700(rdram, ctx);
        goto after_4;
    // 0x8000D348: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_4:
    // 0x8000D34C: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8000D350: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
    // 0x8000D354: bc1f        L_8000D364
    if (!c1cs) {
        // 0x8000D358: nop
    
            goto L_8000D364;
    }
    // 0x8000D358: nop

    // 0x8000D35C: b           L_8000D370
    // 0x8000D360: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000D370;
    // 0x8000D360: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000D364:
    // 0x8000D364: bne         $s1, $fp, L_8000D274
    if (ctx->r17 != ctx->r30) {
        // 0x8000D368: addiu       $s3, $s3, 0xC
        ctx->r19 = ADD32(ctx->r19, 0XC);
            goto L_8000D274;
    }
    // 0x8000D368: addiu       $s3, $s3, 0xC
    ctx->r19 = ADD32(ctx->r19, 0XC);
    // 0x8000D36C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000D370:
    // 0x8000D370: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8000D374: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8000D378: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8000D37C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8000D380: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8000D384: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8000D388: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8000D38C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8000D390: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8000D394: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8000D398: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8000D39C: jr          $ra
    // 0x8000D3A0: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    TRACE_RETURN()
    return;
    // 0x8000D3A0: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_8000D3A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000D3A4: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x8000D3A8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8000D3AC: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8000D3B0: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8000D3B4: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8000D3B8: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8000D3BC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8000D3C0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8000D3C4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8000D3C8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8000D3CC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8000D3D0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8000D3D4: sw          $a0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r4;
    // 0x8000D3D8: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8000D3DC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8000D3E0: addiu       $a0, $sp, 0xD8
    ctx->r4 = ADD32(ctx->r29, 0XD8);
    // 0x8000D3E4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8000D3E8: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8000D3EC: nop

    // 0x8000D3F0: sw          $t7, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r15;
    // 0x8000D3F4: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8000D3F8: sw          $zero, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = 0;
    // 0x8000D3FC: addiu       $a1, $sp, 0xD4
    ctx->r5 = ADD32(ctx->r29, 0XD4);
    // 0x8000D400: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8000D404: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8000D408: jal         0x8004EE7C
    // 0x8000D40C: sw          $t9, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r25;
    func_8004EE7C(rdram, ctx);
        goto after_0;
    // 0x8000D40C: sw          $t9, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r25;
    after_0:
    // 0x8000D410: lw          $v1, 0xDC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XDC);
    // 0x8000D414: beq         $v0, $zero, L_8000D564
    if (ctx->r2 == 0) {
        // 0x8000D418: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8000D564;
    }
    // 0x8000D418: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8000D41C: lw          $t0, 0xD8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XD8);
    // 0x8000D420: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8000D424: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8000D428: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x8000D42C: lw          $t1, 0xD4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XD4);
    // 0x8000D430: addiu       $s7, $sp, 0x7C
    ctx->r23 = ADD32(ctx->r29, 0X7C);
    // 0x8000D434: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8000D438: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x8000D43C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8000D440: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x8000D444: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x8000D448: cvt.s.w     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000D44C: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x8000D450: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x8000D454: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8000D458: add.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f12.fl;
    // 0x8000D45C: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x8000D460: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8000D464: swc1        $f2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f2.u32l;
    // 0x8000D468: swc1        $f2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f2.u32l;
    // 0x8000D46C: sub.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x8000D470: sw          $v1, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r3;
    // 0x8000D474: jal         0x800034FC
    // 0x8000D478: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    func_800034FC(rdram, ctx);
        goto after_1;
    // 0x8000D478: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x8000D47C: lh          $s6, 0x2($s1)
    ctx->r22 = MEM_H(ctx->r17, 0X2);
    // 0x8000D480: lw          $v1, 0xDC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XDC);
    // 0x8000D484: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x8000D488: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x8000D48C: blez        $s6, L_8000D564
    if (SIGNED(ctx->r22) <= 0) {
        // 0x8000D490: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8000D564;
    }
    // 0x8000D490: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8000D494: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000D498: lwc1        $f20, 0x5ECC($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X5ECC);
    // 0x8000D49C: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8000D4A0: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x8000D4A4: addiu       $s5, $sp, 0x94
    ctx->r21 = ADD32(ctx->r29, 0X94);
    // 0x8000D4A8: addiu       $s2, $sp, 0xB8
    ctx->r18 = ADD32(ctx->r29, 0XB8);
    // 0x8000D4AC: addiu       $s1, $zero, 0x6
    ctx->r17 = ADD32(0, 0X6);
L_8000D4B0:
    // 0x8000D4B0: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x8000D4B4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_8000D4B8:
    // 0x8000D4B8: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x8000D4BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000D4C0: addiu       $s1, $s1, -0x2
    ctx->r17 = ADD32(ctx->r17, -0X2);
    // 0x8000D4C4: beq         $v0, $s1, L_8000D4FC
    if (ctx->r2 == ctx->r17) {
        // 0x8000D4C8: lbu         $t2, 0x0($a0)
        ctx->r10 = MEM_BU(ctx->r4, 0X0);
            goto L_8000D4FC;
    }
    // 0x8000D4C8: lbu         $t2, 0x0($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X0);
L_8000D4CC:
    // 0x8000D4CC: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x8000D4D0: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x8000D4D4: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x8000D4D8: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x8000D4DC: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8000D4E0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000D4E4: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8000D4E8: nop

    // 0x8000D4EC: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000D4F0: swc1        $f18, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
    // 0x8000D4F4: bne         $v0, $s1, L_8000D4CC
    if (ctx->r2 != ctx->r17) {
        // 0x8000D4F8: lbu         $t2, 0x0($a0)
        ctx->r10 = MEM_BU(ctx->r4, 0X0);
            goto L_8000D4CC;
    }
    // 0x8000D4F8: lbu         $t2, 0x0($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X0);
L_8000D4FC:
    // 0x8000D4FC: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x8000D500: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x8000D504: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x8000D508: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x8000D50C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8000D510: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8000D514: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8000D518: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000D51C: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000D520: swc1        $f18, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
    // 0x8000D524: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    // 0x8000D528: bne         $a1, $s2, L_8000D4B8
    if (ctx->r5 != ctx->r18) {
        // 0x8000D52C: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8000D4B8;
    }
    // 0x8000D52C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8000D530: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8000D534: jal         0x8000D110
    // 0x8000D538: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_8000D110(rdram, ctx);
        goto after_2;
    // 0x8000D538: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_2:
    // 0x8000D53C: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x8000D540: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x8000D544: jal         0x8000D1FC
    // 0x8000D548: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_8000D1FC(rdram, ctx);
        goto after_3;
    // 0x8000D548: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_3:
    // 0x8000D54C: beq         $v0, $fp, L_8000D564
    if (ctx->r2 == ctx->r30) {
        // 0x8000D550: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8000D564;
    }
    // 0x8000D550: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000D554: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8000D558: addiu       $s4, $s4, 0x3
    ctx->r20 = ADD32(ctx->r20, 0X3);
    // 0x8000D55C: bne         $s3, $s6, L_8000D4B0
    if (ctx->r19 != ctx->r22) {
        // 0x8000D560: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8000D4B0;
    }
    // 0x8000D560: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8000D564:
    // 0x8000D564: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8000D568: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8000D56C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8000D570: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8000D574: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8000D578: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8000D57C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8000D580: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8000D584: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8000D588: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8000D58C: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8000D590: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    // 0x8000D594: jr          $ra
    // 0x8000D598: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    TRACE_RETURN()
    return;
    // 0x8000D598: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8000D59C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000D59C: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x8000D5A0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8000D5A4: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8000D5A8: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8000D5AC: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8000D5B0: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8000D5B4: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8000D5B8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8000D5BC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8000D5C0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8000D5C4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8000D5C8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8000D5CC: sw          $a0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r4;
    // 0x8000D5D0: sw          $a1, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r5;
    // 0x8000D5D4: sw          $a2, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r6;
    // 0x8000D5D8: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8000D5DC: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8000D5E0: addiu       $a1, $sp, 0xD4
    ctx->r5 = ADD32(ctx->r29, 0XD4);
    // 0x8000D5E4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8000D5E8: addiu       $a0, $sp, 0xD8
    ctx->r4 = ADD32(ctx->r29, 0XD8);
    // 0x8000D5EC: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8000D5F0: nop

    // 0x8000D5F4: sw          $t7, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r15;
    // 0x8000D5F8: lwc1        $f8, 0x8($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8000D5FC: sw          $zero, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = 0;
    // 0x8000D600: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8000D604: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8000D608: jal         0x8004EE7C
    // 0x8000D60C: sw          $t9, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r25;
    func_8004EE7C(rdram, ctx);
        goto after_0;
    // 0x8000D60C: sw          $t9, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r25;
    after_0:
    // 0x8000D610: lw          $v1, 0xDC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XDC);
    // 0x8000D614: beq         $v0, $zero, L_8000D7E0
    if (ctx->r2 == 0) {
        // 0x8000D618: sw          $v0, 0xD0($sp)
        MEM_W(0XD0, ctx->r29) = ctx->r2;
            goto L_8000D7E0;
    }
    // 0x8000D618: sw          $v0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r2;
    // 0x8000D61C: lw          $t0, 0xD8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XD8);
    // 0x8000D620: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8000D624: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8000D628: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x8000D62C: lw          $t1, 0xD4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XD4);
    // 0x8000D630: addiu       $s7, $sp, 0x7C
    ctx->r23 = ADD32(ctx->r29, 0X7C);
    // 0x8000D634: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8000D638: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x8000D63C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8000D640: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x8000D644: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x8000D648: cvt.s.w     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000D64C: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x8000D650: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x8000D654: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8000D658: add.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f12.fl;
    // 0x8000D65C: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x8000D660: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8000D664: swc1        $f2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f2.u32l;
    // 0x8000D668: swc1        $f2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f2.u32l;
    // 0x8000D66C: sub.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x8000D670: sw          $v1, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r3;
    // 0x8000D674: jal         0x800034FC
    // 0x8000D678: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    func_800034FC(rdram, ctx);
        goto after_1;
    // 0x8000D678: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x8000D67C: lw          $a2, 0xD0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XD0);
    // 0x8000D680: lw          $v1, 0xDC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XDC);
    // 0x8000D684: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8000D688: lh          $s6, 0x2($a2)
    ctx->r22 = MEM_H(ctx->r6, 0X2);
    // 0x8000D68C: lw          $v0, 0x8($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X8);
    // 0x8000D690: lw          $s0, 0x4($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X4);
    // 0x8000D694: blez        $s6, L_8000D7E0
    if (SIGNED(ctx->r22) <= 0) {
        // 0x8000D698: or          $s4, $v0, $zero
        ctx->r20 = ctx->r2 | 0;
            goto L_8000D7E0;
    }
    // 0x8000D698: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8000D69C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000D6A0: lwc1        $f20, 0x5ED0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X5ED0);
    // 0x8000D6A4: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x8000D6A8: addiu       $s5, $sp, 0x94
    ctx->r21 = ADD32(ctx->r29, 0X94);
    // 0x8000D6AC: addiu       $s2, $sp, 0xB8
    ctx->r18 = ADD32(ctx->r29, 0XB8);
    // 0x8000D6B0: addiu       $s1, $zero, 0x6
    ctx->r17 = ADD32(0, 0X6);
L_8000D6B4:
    // 0x8000D6B4: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x8000D6B8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_8000D6BC:
    // 0x8000D6BC: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x8000D6C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000D6C4: addiu       $s1, $s1, -0x2
    ctx->r17 = ADD32(ctx->r17, -0X2);
    // 0x8000D6C8: beq         $v0, $s1, L_8000D700
    if (ctx->r2 == ctx->r17) {
        // 0x8000D6CC: lbu         $t2, 0x0($a0)
        ctx->r10 = MEM_BU(ctx->r4, 0X0);
            goto L_8000D700;
    }
    // 0x8000D6CC: lbu         $t2, 0x0($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X0);
L_8000D6D0:
    // 0x8000D6D0: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x8000D6D4: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x8000D6D8: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x8000D6DC: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x8000D6E0: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8000D6E4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000D6E8: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8000D6EC: nop

    // 0x8000D6F0: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000D6F4: swc1        $f18, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
    // 0x8000D6F8: bne         $v0, $s1, L_8000D6D0
    if (ctx->r2 != ctx->r17) {
        // 0x8000D6FC: lbu         $t2, 0x0($a0)
        ctx->r10 = MEM_BU(ctx->r4, 0X0);
            goto L_8000D6D0;
    }
    // 0x8000D6FC: lbu         $t2, 0x0($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X0);
L_8000D700:
    // 0x8000D700: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x8000D704: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x8000D708: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x8000D70C: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x8000D710: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8000D714: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8000D718: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8000D71C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000D720: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000D724: swc1        $f18, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
    // 0x8000D728: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    // 0x8000D72C: bne         $a1, $s2, L_8000D6BC
    if (ctx->r5 != ctx->r18) {
        // 0x8000D730: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8000D6BC;
    }
    // 0x8000D730: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8000D734: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8000D738: jal         0x8000D110
    // 0x8000D73C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_8000D110(rdram, ctx);
        goto after_2;
    // 0x8000D73C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_2:
    // 0x8000D740: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x8000D744: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x8000D748: jal         0x8000D1FC
    // 0x8000D74C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_8000D1FC(rdram, ctx);
        goto after_3;
    // 0x8000D74C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_3:
    // 0x8000D750: bne         $v0, $fp, L_8000D7D4
    if (ctx->r2 != ctx->r30) {
        // 0x8000D754: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8000D7D4;
    }
    // 0x8000D754: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000D758: lw          $a0, 0xE8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE8);
    // 0x8000D75C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8000D760: addiu       $a2, $sp, 0xA0
    ctx->r6 = ADD32(ctx->r29, 0XA0);
    // 0x8000D764: addiu       $a3, $sp, 0xAC
    ctx->r7 = ADD32(ctx->r29, 0XAC);
    // 0x8000D768: jal         0x800037FC
    // 0x8000D76C: sw          $v0, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r2;
    func_800037FC(rdram, ctx);
        goto after_4;
    // 0x8000D76C: sw          $v0, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r2;
    after_4:
    // 0x8000D770: lw          $t7, 0xE8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE8);
    // 0x8000D774: jal         0x8000E978
    // 0x8000D778: lwc1        $f12, 0x8($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X8);
    func_8000E978(rdram, ctx);
        goto after_5;
    // 0x8000D778: lwc1        $f12, 0x8($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X8);
    after_5:
    // 0x8000D77C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000D780: lwc1        $f20, 0x5ED4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X5ED4);
    // 0x8000D784: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000D788: lwc1        $f6, 0x5ED8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5ED8);
    // 0x8000D78C: sub.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x8000D790: lw          $v0, 0xE4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XE4);
    // 0x8000D794: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8000D798: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8000D79C: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    // 0x8000D7A0: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8000D7A4: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x8000D7A8: lw          $t8, 0xE8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE8);
    // 0x8000D7AC: jal         0x8000E978
    // 0x8000D7B0: lwc1        $f12, 0x0($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X0);
    func_8000E978(rdram, ctx);
        goto after_6;
    // 0x8000D7B0: lwc1        $f12, 0x0($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X0);
    after_6:
    // 0x8000D7B4: sub.s       $f18, $f0, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x8000D7B8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000D7BC: lwc1        $f4, 0x5EDC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5EDC);
    // 0x8000D7C0: lw          $t9, 0xE4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE4);
    // 0x8000D7C4: lw          $v1, 0xDC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XDC);
    // 0x8000D7C8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8000D7CC: b           L_8000D7E0
    // 0x8000D7D0: swc1        $f6, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f6.u32l;
        goto L_8000D7E0;
    // 0x8000D7D0: swc1        $f6, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f6.u32l;
L_8000D7D4:
    // 0x8000D7D4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8000D7D8: bne         $s3, $s6, L_8000D6B4
    if (ctx->r19 != ctx->r22) {
        // 0x8000D7DC: addiu       $s4, $s4, 0x3
        ctx->r20 = ADD32(ctx->r20, 0X3);
            goto L_8000D6B4;
    }
    // 0x8000D7DC: addiu       $s4, $s4, 0x3
    ctx->r20 = ADD32(ctx->r20, 0X3);
L_8000D7E0:
    // 0x8000D7E0: beq         $v1, $zero, L_8000D800
    if (ctx->r3 == 0) {
        // 0x8000D7E4: ldc1        $f20, 0x18($sp)
        CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
            goto L_8000D800;
    }
    // 0x8000D7E4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8000D7E8: lw          $t0, 0xD0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XD0);
    // 0x8000D7EC: lbu         $t1, 0x44($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X44);
    // 0x8000D7F0: andi        $t2, $t1, 0x80
    ctx->r10 = ctx->r9 & 0X80;
    // 0x8000D7F4: beql        $t2, $zero, L_8000D804
    if (ctx->r10 == 0) {
        // 0x8000D7F8: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_8000D804;
    }
    goto skip_0;
    // 0x8000D7F8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x8000D7FC: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_8000D800:
    // 0x8000D800: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8000D804:
    // 0x8000D804: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8000D808: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8000D80C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8000D810: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8000D814: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8000D818: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8000D81C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8000D820: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8000D824: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8000D828: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    // 0x8000D82C: jr          $ra
    // 0x8000D830: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    TRACE_RETURN()
    return;
    // 0x8000D830: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
