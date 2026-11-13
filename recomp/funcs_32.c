#include "recomp.h"
#include "trace.h"
#include "funcs.h"

RECOMP_FUNC void func_80062A30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80062A30: lui         $t6, 0xA460
    ctx->r14 = S32(0XA460 << 16);
    // 0x80062A34: lw          $a3, 0x10($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X10);
    // 0x80062A38: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80062A3C: andi        $t7, $a3, 0x3
    ctx->r15 = ctx->r7 & 0X3;
    // 0x80062A40: beq         $t7, $zero, L_80062A5C
    if (ctx->r15 == 0) {
        // 0x80062A44: nop
    
            goto L_80062A5C;
    }
    // 0x80062A44: nop

L_80062A48:
    // 0x80062A48: lui         $t8, 0xA460
    ctx->r24 = S32(0XA460 << 16);
    // 0x80062A4C: lw          $a3, 0x10($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X10);
    // 0x80062A50: andi        $t9, $a3, 0x3
    ctx->r25 = ctx->r7 & 0X3;
    // 0x80062A54: bne         $t9, $zero, L_80062A48
    if (ctx->r25 != 0) {
        // 0x80062A58: nop
    
            goto L_80062A48;
    }
    // 0x80062A58: nop

L_80062A5C:
    // 0x80062A5C: lw          $t0, 0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XC);
    // 0x80062A60: lui         $at, 0xA000
    ctx->r1 = S32(0XA000 << 16);
    // 0x80062A64: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80062A68: or          $t1, $t0, $a1
    ctx->r9 = ctx->r8 | ctx->r5;
    // 0x80062A6C: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x80062A70: sw          $a2, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r6;
    // 0x80062A74: jr          $ra
    // 0x80062A78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    TRACE_RETURN()
    return;
    // 0x80062A78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80062A80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80062A80: lui         $t6, 0xA460
    ctx->r14 = S32(0XA460 << 16);
    // 0x80062A84: lw          $a3, 0x10($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X10);
    // 0x80062A88: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80062A8C: andi        $t7, $a3, 0x3
    ctx->r15 = ctx->r7 & 0X3;
    // 0x80062A90: beq         $t7, $zero, L_80062AAC
    if (ctx->r15 == 0) {
        // 0x80062A94: nop
    
            goto L_80062AAC;
    }
    // 0x80062A94: nop

L_80062A98:
    // 0x80062A98: lui         $t8, 0xA460
    ctx->r24 = S32(0XA460 << 16);
    // 0x80062A9C: lw          $a3, 0x10($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X10);
    // 0x80062AA0: andi        $t9, $a3, 0x3
    ctx->r25 = ctx->r7 & 0X3;
    // 0x80062AA4: bne         $t9, $zero, L_80062A98
    if (ctx->r25 != 0) {
        // 0x80062AA8: nop
    
            goto L_80062A98;
    }
    // 0x80062AA8: nop

L_80062AAC:
    // 0x80062AAC: lw          $t0, 0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XC);
    // 0x80062AB0: lui         $at, 0xA000
    ctx->r1 = S32(0XA000 << 16);
    // 0x80062AB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80062AB8: or          $t1, $t0, $a1
    ctx->r9 = ctx->r8 | ctx->r5;
    // 0x80062ABC: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x80062AC0: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80062AC4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80062AC8: jr          $ra
    // 0x80062ACC: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    TRACE_RETURN()
    return;
    // 0x80062ACC: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
;}
RECOMP_FUNC void func_80062AD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80062AD0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80062AD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80062AD8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80062ADC: jal         0x80056580
    // 0x80062AE0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    __osDisableInt_recomp(rdram, ctx);
        goto after_0;
    // 0x80062AE0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80062AE4: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x80062AE8: lw          $t6, 0x31F0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X31F0);
    // 0x80062AEC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80062AF0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80062AF4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80062AF8: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80062AFC: sw          $t8, 0x31F0($at)
    MEM_W(0X31F0, ctx->r1) = ctx->r24;
    // 0x80062B00: jal         0x800565A0
    // 0x80062B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    __osRestoreInt_recomp(rdram, ctx);
        goto after_1;
    // 0x80062B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80062B08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80062B0C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80062B10: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80062B14: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80062B20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80062B20: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80062B24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80062B28: jal         0x80056580
    // 0x80062B2C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    __osDisableInt_recomp(rdram, ctx);
        goto after_0;
    // 0x80062B2C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80062B30: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x80062B34: lw          $t7, 0x3240($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3240);
    // 0x80062B38: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80062B3C: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80062B40: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80062B44: addiu       $a0, $a0, 0x3238
    ctx->r4 = ADD32(ctx->r4, 0X3238);
    // 0x80062B48: jal         0x80056C2C
    // 0x80062B4C: sh          $t6, 0x10($t7)
    MEM_H(0X10, ctx->r15) = ctx->r14;
    func_80056C2C(rdram, ctx);
        goto after_1;
    // 0x80062B4C: sh          $t6, 0x10($t7)
    MEM_H(0X10, ctx->r15) = ctx->r14;
    after_1:
    // 0x80062B50: jal         0x800565A0
    // 0x80062B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    __osRestoreInt_recomp(rdram, ctx);
        goto after_2;
    // 0x80062B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80062B58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80062B5C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80062B60: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80062B64: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80062B70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
;}
RECOMP_FUNC void func_80062BBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
;}
RECOMP_FUNC void func_80064EC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
;}
RECOMP_FUNC void func_80064ED8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
;}
RECOMP_FUNC void func_80064F70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
;}
