#include "recomp.h"
#include "trace.h"
#include "funcs.h"

RECOMP_FUNC void func_80059960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
;}
RECOMP_FUNC void func_80059990(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80059990: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80059994: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80059998: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005999C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800599A0: addiu       $t6, $t6, -0x21B0
    ctx->r14 = ADD32(ctx->r14, -0X21B0);
    // 0x800599A4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800599A8: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800599AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800599B0: jal         0x800618E0
    // 0x800599B4: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_800618E0(rdram, ctx);
        goto after_0;
    // 0x800599B4: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_0:
    // 0x800599B8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800599BC: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x800599C0: beq         $t8, $zero, L_800599D8
    if (ctx->r24 == 0) {
        // 0x800599C4: nop
    
            goto L_800599D8;
    }
    // 0x800599C4: nop

    // 0x800599C8: jal         0x80053750
    // 0x800599CC: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x800599CC: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_1:
    // 0x800599D0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800599D4: sw          $v0, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->r2;
L_800599D8:
    // 0x800599D8: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800599DC: lw          $t1, 0x18($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X18);
    // 0x800599E0: beq         $t1, $zero, L_800599F8
    if (ctx->r9 == 0) {
        // 0x800599E4: nop
    
            goto L_800599F8;
    }
    // 0x800599E4: nop

    // 0x800599E8: jal         0x80053750
    // 0x800599EC: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x800599EC: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_2:
    // 0x800599F0: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800599F4: sw          $v0, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->r2;
L_800599F8:
    // 0x800599F8: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800599FC: lw          $t4, 0x20($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X20);
    // 0x80059A00: beq         $t4, $zero, L_80059A18
    if (ctx->r12 == 0) {
        // 0x80059A04: nop
    
            goto L_80059A18;
    }
    // 0x80059A04: nop

    // 0x80059A08: jal         0x80053750
    // 0x80059A0C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_3;
    // 0x80059A0C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_3:
    // 0x80059A10: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80059A14: sw          $v0, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->r2;
L_80059A18:
    // 0x80059A18: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80059A1C: lw          $t7, 0x28($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X28);
    // 0x80059A20: beq         $t7, $zero, L_80059A38
    if (ctx->r15 == 0) {
        // 0x80059A24: nop
    
            goto L_80059A38;
    }
    // 0x80059A24: nop

    // 0x80059A28: jal         0x80053750
    // 0x80059A2C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_4;
    // 0x80059A2C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_4:
    // 0x80059A30: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80059A34: sw          $v0, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r2;
L_80059A38:
    // 0x80059A38: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80059A3C: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x80059A40: beq         $t0, $zero, L_80059A58
    if (ctx->r8 == 0) {
        // 0x80059A44: nop
    
            goto L_80059A58;
    }
    // 0x80059A44: nop

    // 0x80059A48: jal         0x80053750
    // 0x80059A4C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_5;
    // 0x80059A4C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_5:
    // 0x80059A50: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80059A54: sw          $v0, 0x2C($t1)
    MEM_W(0X2C, ctx->r9) = ctx->r2;
L_80059A58:
    // 0x80059A58: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80059A5C: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80059A60: beq         $t3, $zero, L_80059A78
    if (ctx->r11 == 0) {
        // 0x80059A64: nop
    
            goto L_80059A78;
    }
    // 0x80059A64: nop

    // 0x80059A68: jal         0x80053750
    // 0x80059A6C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_6;
    // 0x80059A6C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_6:
    // 0x80059A70: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80059A74: sw          $v0, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r2;
L_80059A78:
    // 0x80059A78: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80059A7C: lw          $t6, 0x38($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X38);
    // 0x80059A80: beq         $t6, $zero, L_80059A98
    if (ctx->r14 == 0) {
        // 0x80059A84: nop
    
            goto L_80059A98;
    }
    // 0x80059A84: nop

    // 0x80059A88: jal         0x80053750
    // 0x80059A8C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_7;
    // 0x80059A8C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_7:
    // 0x80059A90: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80059A94: sw          $v0, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->r2;
L_80059A98:
    // 0x80059A98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80059A9C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80059AA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80059AA4: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80059C80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
;}
RECOMP_FUNC void func_80059D30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80059D30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80059D34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80059D38: jal         0x80061BF0
    // 0x80059D3C: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    func_80061BF0(rdram, ctx);
        goto after_0;
    // 0x80059D3C: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    after_0:
    // 0x80059D40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80059D44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80059D48: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80059E90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
;}
RECOMP_FUNC void func_80059F80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80059F80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80059F84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80059F88: lui         $a1, 0x8006
    ctx->r5 = S32(0X8006 << 16);
    // 0x80059F8C: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x80059F90: addiu       $a2, $a2, -0x3B30
    ctx->r6 = ADD32(ctx->r6, -0X3B30);
    // 0x80059F94: addiu       $a1, $a1, -0x3AFC
    ctx->r5 = ADD32(ctx->r5, -0X3AFC);
    // 0x80059F98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80059F9C: jal         0x80061D30
    // 0x80059FA0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_80061D30(rdram, ctx);
        goto after_0;
    // 0x80059FA0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_0:
    // 0x80059FA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80059FA8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80059FAC: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x80059FB0: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x80059FB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80059FB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80059FBC: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80059FC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80059FC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80059FC8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80059FCC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80059FD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80059FD4: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x80059FD8: lui         $a1, 0x8006
    ctx->r5 = S32(0X8006 << 16);
    // 0x80059FDC: addiu       $a1, $a1, -0x5810
    ctx->r5 = ADD32(ctx->r5, -0X5810);
    // 0x80059FE0: addiu       $a2, $a2, -0x5840
    ctx->r6 = ADD32(ctx->r6, -0X5840);
    // 0x80059FE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80059FE8: jal         0x80061D30
    // 0x80059FEC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    func_80061D30(rdram, ctx);
        goto after_0;
    // 0x80059FEC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_0:
    // 0x80059FF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80059FF4: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x80059FF8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80059FFC: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x8005A000: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8005A004: sw          $t7, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r15;
    // 0x8005A008: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005A00C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005A010: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005A018(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005A018: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005A01C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8005A020: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8005A024: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005A028: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x8005A02C: lui         $a1, 0x8006
    ctx->r5 = S32(0X8006 << 16);
    // 0x8005A030: addiu       $a1, $a1, -0x3C10
    ctx->r5 = ADD32(ctx->r5, -0X3C10);
    // 0x8005A034: addiu       $a2, $a2, -0x3C40
    ctx->r6 = ADD32(ctx->r6, -0X3C40);
    // 0x8005A038: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8005A03C: jal         0x80061D30
    // 0x8005A040: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    func_80061D30(rdram, ctx);
        goto after_0;
    // 0x8005A040: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_0:
    // 0x8005A044: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8005A048: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x8005A04C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8005A050: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x8005A054: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8005A058: sw          $t7, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r15;
    // 0x8005A05C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005A060: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005A064: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005A06C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005A06C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005A070: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8005A074: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005A078: lui         $a1, 0x8006
    ctx->r5 = S32(0X8006 << 16);
    // 0x8005A07C: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x8005A080: addiu       $a2, $a2, -0x4BA0
    ctx->r6 = ADD32(ctx->r6, -0X4BA0);
    // 0x8005A084: addiu       $a1, $a1, -0x4AB4
    ctx->r5 = ADD32(ctx->r5, -0X4AB4);
    // 0x8005A088: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8005A08C: jal         0x80061D30
    // 0x8005A090: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80061D30(rdram, ctx);
        goto after_0;
    // 0x8005A090: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x8005A094: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x8005A098: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8005A09C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005A0A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005A0A4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8005A0A8: jal         0x800507E0
    // 0x8005A0AC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800507E0(rdram, ctx);
        goto after_1;
    // 0x8005A0AC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x8005A0B0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8005A0B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005A0B8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005A0BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005A0C0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005A0C4: sw          $v0, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r2;
    // 0x8005A0C8: sw          $t7, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r15;
    // 0x8005A0CC: sw          $zero, 0x30($t0)
    MEM_W(0X30, ctx->r8) = 0;
    // 0x8005A0D0: sw          $zero, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = 0;
    // 0x8005A0D4: sw          $zero, 0x28($t0)
    MEM_W(0X28, ctx->r8) = 0;
    // 0x8005A0D8: sw          $zero, 0x2C($t0)
    MEM_W(0X2C, ctx->r8) = 0;
    // 0x8005A0DC: swc1        $f4, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f4.u32l;
    // 0x8005A0E0: swc1        $f6, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f6.u32l;
    // 0x8005A0E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005A0E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005A0EC: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005A0F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005A0F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005A0F8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8005A0FC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8005A100: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005A104: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005A108: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x8005A10C: lui         $a1, 0x8006
    ctx->r5 = S32(0X8006 << 16);
    // 0x8005A110: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8005A114: addiu       $a1, $a1, -0x5044
    ctx->r5 = ADD32(ctx->r5, -0X5044);
    // 0x8005A118: addiu       $a2, $a2, -0x56F0
    ctx->r6 = ADD32(ctx->r6, -0X56F0);
    // 0x8005A11C: jal         0x80061D30
    // 0x8005A120: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80061D30(rdram, ctx);
        goto after_0;
    // 0x8005A120: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8005A124: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x8005A128: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8005A12C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005A130: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005A134: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8005A138: jal         0x800507E0
    // 0x8005A13C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800507E0(rdram, ctx);
        goto after_1;
    // 0x8005A13C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x8005A140: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x8005A144: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x8005A148: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8005A14C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8005A150: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005A154: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005A158: jal         0x800507E0
    // 0x8005A15C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800507E0(rdram, ctx);
        goto after_2;
    // 0x8005A15C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x8005A160: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x8005A164: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8005A168: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x8005A16C: jalr        $t9
    // 0x8005A170: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x8005A170: nop

    after_3:
    // 0x8005A174: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8005A178: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x8005A17C: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x8005A180: sw          $t8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r24;
    // 0x8005A184: sw          $zero, 0x44($s0)
    MEM_W(0X44, ctx->r16) = 0;
    // 0x8005A188: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005A18C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005A190: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8005A194: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005A19C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005A19C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005A1A0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8005A1A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005A1A8: lui         $a1, 0x8006
    ctx->r5 = S32(0X8006 << 16);
    // 0x8005A1AC: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x8005A1B0: addiu       $a2, $a2, -0x478C
    ctx->r6 = ADD32(ctx->r6, -0X478C);
    // 0x8005A1B4: addiu       $a1, $a1, -0x4194
    ctx->r5 = ADD32(ctx->r5, -0X4194);
    // 0x8005A1B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8005A1BC: jal         0x80061D30
    // 0x8005A1C0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_80061D30(rdram, ctx);
        goto after_0;
    // 0x8005A1C0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x8005A1C4: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x8005A1C8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8005A1CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005A1D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005A1D4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8005A1D8: jal         0x800507E0
    // 0x8005A1DC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800507E0(rdram, ctx);
        goto after_1;
    // 0x8005A1DC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x8005A1E0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8005A1E4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8005A1E8: sw          $v0, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r2;
    // 0x8005A1EC: sw          $v1, 0x38($t0)
    MEM_W(0X38, ctx->r8) = ctx->r3;
    // 0x8005A1F0: sw          $zero, 0x48($t0)
    MEM_W(0X48, ctx->r8) = 0;
    // 0x8005A1F4: sh          $v1, 0x1A($t0)
    MEM_H(0X1A, ctx->r8) = ctx->r3;
    // 0x8005A1F8: sh          $v1, 0x28($t0)
    MEM_H(0X28, ctx->r8) = ctx->r3;
    // 0x8005A1FC: sh          $v1, 0x2E($t0)
    MEM_H(0X2E, ctx->r8) = ctx->r3;
    // 0x8005A200: sh          $v1, 0x1C($t0)
    MEM_H(0X1C, ctx->r8) = ctx->r3;
    // 0x8005A204: sh          $v1, 0x1E($t0)
    MEM_H(0X1E, ctx->r8) = ctx->r3;
    // 0x8005A208: sh          $zero, 0x20($t0)
    MEM_H(0X20, ctx->r8) = 0;
    // 0x8005A20C: sh          $zero, 0x22($t0)
    MEM_H(0X22, ctx->r8) = 0;
    // 0x8005A210: sh          $v1, 0x26($t0)
    MEM_H(0X26, ctx->r8) = ctx->r3;
    // 0x8005A214: sh          $zero, 0x24($t0)
    MEM_H(0X24, ctx->r8) = 0;
    // 0x8005A218: sw          $zero, 0x30($t0)
    MEM_W(0X30, ctx->r8) = 0;
    // 0x8005A21C: sw          $zero, 0x34($t0)
    MEM_W(0X34, ctx->r8) = 0;
    // 0x8005A220: sh          $zero, 0x18($t0)
    MEM_H(0X18, ctx->r8) = 0;
    // 0x8005A224: sw          $zero, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = 0;
    // 0x8005A228: sw          $zero, 0x40($t0)
    MEM_W(0X40, ctx->r8) = 0;
    // 0x8005A22C: sw          $zero, 0x44($t0)
    MEM_W(0X44, ctx->r8) = 0;
    // 0x8005A230: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005A234: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005A238: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005A240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005A240: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x8005A244: addiu       $t9, $zero, 0x4000
    ctx->r25 = ADD32(0, 0X4000);
    // 0x8005A248: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8005A24C: sll         $t6, $v0, 14
    ctx->r14 = S32(ctx->r2 << 14);
    // 0x8005A250: sra         $v1, $t6, 15
    ctx->r3 = S32(SIGNED(ctx->r14) >> 15);
    // 0x8005A254: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x8005A258: sra         $v1, $t7, 16
    ctx->r3 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8005A25C: subu        $t0, $t9, $v1
    ctx->r8 = SUB32(ctx->r25, ctx->r3);
    // 0x8005A260: sh          $t0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r8;
    // 0x8005A264: sw          $t1, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r9;
    // 0x8005A268: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005A26C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
L_8005A270:
    // 0x8005A270: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8005A274: slti        $at, $a1, 0x8
    ctx->r1 = SIGNED(ctx->r5) < 0X8 ? 1 : 0;
    // 0x8005A278: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x8005A27C: bne         $at, $zero, L_8005A270
    if (ctx->r1 != 0) {
        // 0x8005A280: sh          $zero, 0x6($a2)
        MEM_H(0X6, ctx->r6) = 0;
            goto L_8005A270;
    }
    // 0x8005A280: sh          $zero, 0x6($a2)
    MEM_H(0X6, ctx->r6) = 0;
    // 0x8005A284: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x8005A288: lui         $at, 0x40D0
    ctx->r1 = S32(0X40D0 << 16);
    // 0x8005A28C: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8005A290: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8005A294: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8005A298: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8005A29C: slti        $at, $a1, 0x10
    ctx->r1 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x8005A2A0: sh          $v1, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r3;
    // 0x8005A2A4: div.d       $f2, $f6, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f2.d = DIV_D(ctx->f6.d, ctx->f12.d);
    // 0x8005A2A8: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x8005A2AC: beq         $at, $zero, L_8005A2D8
    if (ctx->r1 == 0) {
        // 0x8005A2B0: mov.d       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
            goto L_8005A2D8;
    }
    // 0x8005A2B0: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
L_8005A2B4:
    // 0x8005A2B4: mul.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x8005A2B8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8005A2BC: slti        $at, $a1, 0x10
    ctx->r1 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x8005A2C0: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x8005A2C4: mul.d       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f12.d);
    // 0x8005A2C8: trunc.w.d   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_D(ctx->f8.d);
    // 0x8005A2CC: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x8005A2D0: bne         $at, $zero, L_8005A2B4
    if (ctx->r1 != 0) {
        // 0x8005A2D4: sh          $t3, 0x6($a2)
        MEM_H(0X6, ctx->r6) = ctx->r11;
            goto L_8005A2B4;
    }
    // 0x8005A2D4: sh          $t3, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r11;
L_8005A2D8:
    // 0x8005A2D8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005A2E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005A2E0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8005A2E4: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x8005A2E8: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x8005A2EC: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8005A2F0: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8005A2F4: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x8005A2F8: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x8005A2FC: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8005A300: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x8005A304: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x8005A308: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x8005A30C: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x8005A310: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x8005A314: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8005A318: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8005A31C: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x8005A320: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x8005A324: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8005A328: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8005A32C: addiu       $a2, $a2, 0x2644
    ctx->r6 = ADD32(ctx->r6, 0X2644);
    // 0x8005A330: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005A334: jal         0x80061D30
    // 0x8005A338: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    func_80061D30(rdram, ctx);
        goto after_0;
    // 0x8005A338: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_0:
    // 0x8005A33C: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x8005A340: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x8005A344: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x8005A348: addiu       $t6, $t6, 0x265C
    ctx->r14 = ADD32(ctx->r14, 0X265C);
    // 0x8005A34C: addiu       $t7, $t7, 0x23E8
    ctx->r15 = ADD32(ctx->r15, 0X23E8);
    // 0x8005A350: sw          $t6, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->r14;
    // 0x8005A354: sw          $t7, 0x28($s5)
    MEM_W(0X28, ctx->r21) = ctx->r15;
    // 0x8005A358: lbu         $t8, 0x1C($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1C);
    // 0x8005A35C: lui         $s3, 0x8007
    ctx->r19 = S32(0X8007 << 16);
    // 0x8005A360: addiu       $s3, $s3, 0x45E8
    ctx->r19 = ADD32(ctx->r19, 0X45E8);
    // 0x8005A364: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8005A368: sltiu       $at, $t9, 0x6
    ctx->r1 = ctx->r25 < 0X6 ? 1 : 0;
    // 0x8005A36C: beq         $at, $zero, L_8005A3CC
    if (ctx->r1 == 0) {
        // 0x8005A370: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_8005A3CC;
    }
    // 0x8005A370: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8005A374: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8005A378: addu        $at, $at, $t9
    gpr jr_addend_8005A380 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8005A37C: lw          $t9, -0x6900($at)
    ctx->r25 = ADD32(ctx->r1, -0X6900);
    // 0x8005A380: jr          $t9
    // 0x8005A384: nop

    switch (jr_addend_8005A380 >> 2) {
        case 0: goto L_8005A388; break;
        case 1: goto L_8005A394; break;
        case 2: goto L_8005A3AC; break;
        case 3: goto L_8005A3B8; break;
        case 4: goto L_8005A3A0; break;
        case 5: goto L_8005A3C4; break;
        default: switch_error(__func__, 0x8005A380, 0x80079700);
    }
    // 0x8005A384: nop

L_8005A388:
    // 0x8005A388: lui         $s3, 0x8007
    ctx->r19 = S32(0X8007 << 16);
    // 0x8005A38C: b           L_8005A3CC
    // 0x8005A390: addiu       $s3, $s3, 0x4480
    ctx->r19 = ADD32(ctx->r19, 0X4480);
        goto L_8005A3CC;
    // 0x8005A390: addiu       $s3, $s3, 0x4480
    ctx->r19 = ADD32(ctx->r19, 0X4480);
L_8005A394:
    // 0x8005A394: lui         $s3, 0x8007
    ctx->r19 = S32(0X8007 << 16);
    // 0x8005A398: b           L_8005A3CC
    // 0x8005A39C: addiu       $s3, $s3, 0x44E8
    ctx->r19 = ADD32(ctx->r19, 0X44E8);
        goto L_8005A3CC;
    // 0x8005A39C: addiu       $s3, $s3, 0x44E8
    ctx->r19 = ADD32(ctx->r19, 0X44E8);
L_8005A3A0:
    // 0x8005A3A0: lui         $s3, 0x8007
    ctx->r19 = S32(0X8007 << 16);
    // 0x8005A3A4: b           L_8005A3CC
    // 0x8005A3A8: addiu       $s3, $s3, 0x4570
    ctx->r19 = ADD32(ctx->r19, 0X4570);
        goto L_8005A3CC;
    // 0x8005A3A8: addiu       $s3, $s3, 0x4570
    ctx->r19 = ADD32(ctx->r19, 0X4570);
L_8005A3AC:
    // 0x8005A3AC: lui         $s3, 0x8007
    ctx->r19 = S32(0X8007 << 16);
    // 0x8005A3B0: b           L_8005A3CC
    // 0x8005A3B4: addiu       $s3, $s3, 0x4598
    ctx->r19 = ADD32(ctx->r19, 0X4598);
        goto L_8005A3CC;
    // 0x8005A3B4: addiu       $s3, $s3, 0x4598
    ctx->r19 = ADD32(ctx->r19, 0X4598);
L_8005A3B8:
    // 0x8005A3B8: lui         $s3, 0x8007
    ctx->r19 = S32(0X8007 << 16);
    // 0x8005A3BC: b           L_8005A3CC
    // 0x8005A3C0: addiu       $s3, $s3, 0x45C0
    ctx->r19 = ADD32(ctx->r19, 0X45C0);
        goto L_8005A3CC;
    // 0x8005A3C0: addiu       $s3, $s3, 0x45C0
    ctx->r19 = ADD32(ctx->r19, 0X45C0);
L_8005A3C4:
    // 0x8005A3C4: b           L_8005A3CC
    // 0x8005A3C8: lw          $s3, 0x20($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X20);
        goto L_8005A3CC;
    // 0x8005A3C8: lw          $s3, 0x20($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X20);
L_8005A3CC:
    // 0x8005A3CC: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x8005A3D0: addiu       $t2, $zero, 0x28
    ctx->r10 = ADD32(0, 0X28);
    // 0x8005A3D4: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x8005A3D8: sb          $t0, 0x24($s5)
    MEM_B(0X24, ctx->r21) = ctx->r8;
    // 0x8005A3DC: lw          $t1, 0x4($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X4);
    // 0x8005A3E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005A3E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005A3E8: sw          $t1, 0x1C($s5)
    MEM_W(0X1C, ctx->r21) = ctx->r9;
    // 0x8005A3EC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8005A3F0: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x8005A3F4: jal         0x800507E0
    // 0x8005A3F8: andi        $a3, $t0, 0xFF
    ctx->r7 = ctx->r8 & 0XFF;
    func_800507E0(rdram, ctx);
        goto after_1;
    // 0x8005A3F8: andi        $a3, $t0, 0xFF
    ctx->r7 = ctx->r8 & 0XFF;
    after_1:
    // 0x8005A3FC: sw          $v0, 0x20($s5)
    MEM_W(0X20, ctx->r21) = ctx->r2;
    // 0x8005A400: lw          $a3, 0x1C($s5)
    ctx->r7 = MEM_W(ctx->r21, 0X1C);
    // 0x8005A404: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8005A408: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8005A40C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005A410: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005A414: jal         0x800507E0
    // 0x8005A418: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_800507E0(rdram, ctx);
        goto after_2;
    // 0x8005A418: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_2:
    // 0x8005A41C: lw          $t4, 0x1C($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X1C);
    // 0x8005A420: sw          $v0, 0x14($s5)
    MEM_W(0X14, ctx->r21) = ctx->r2;
    // 0x8005A424: sw          $v0, 0x18($s5)
    MEM_W(0X18, ctx->r21) = ctx->r2;
    // 0x8005A428: beq         $t4, $zero, L_8005A45C
    if (ctx->r12 == 0) {
        // 0x8005A42C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8005A45C;
    }
    // 0x8005A42C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8005A430: lw          $t5, 0x14($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X14);
L_8005A434:
    // 0x8005A434: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x8005A438: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8005A43C: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8005A440: sh          $zero, 0x0($t7)
    MEM_H(0X0, ctx->r15) = 0;
    // 0x8005A444: lw          $t9, 0x1C($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X1C);
    // 0x8005A448: andi        $t8, $v1, 0xFFFF
    ctx->r24 = ctx->r3 & 0XFFFF;
    // 0x8005A44C: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x8005A450: sltu        $at, $t8, $t9
    ctx->r1 = ctx->r24 < ctx->r25 ? 1 : 0;
    // 0x8005A454: bnel        $at, $zero, L_8005A434
    if (ctx->r1 != 0) {
        // 0x8005A458: lw          $t5, 0x14($s5)
        ctx->r13 = MEM_W(ctx->r21, 0X14);
            goto L_8005A434;
    }
    goto skip_0;
    // 0x8005A458: lw          $t5, 0x14($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X14);
    skip_0:
L_8005A45C:
    // 0x8005A45C: lbu         $t0, 0x24($s5)
    ctx->r8 = MEM_BU(ctx->r21, 0X24);
    // 0x8005A460: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8005A464: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005A468: blez        $t0, L_8005A6DC
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8005A46C: addiu       $fp, $zero, 0x1
        ctx->r30 = ADD32(0, 0X1);
            goto L_8005A6DC;
    }
    // 0x8005A46C: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x8005A470: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8005A474: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8005A478: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8005A47C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8005A480: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x8005A484: ldc1        $f20, -0x68E8($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, -0X68E8);
    // 0x8005A488: addiu       $s7, $zero, 0x28
    ctx->r23 = ADD32(0, 0X28);
L_8005A48C:
    // 0x8005A48C: multu       $s4, $s7
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005A490: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x8005A494: lw          $t1, 0x20($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X20);
    // 0x8005A498: addu        $t4, $s3, $t3
    ctx->r12 = ADD32(ctx->r19, ctx->r11);
    // 0x8005A49C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8005A4A0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8005A4A4: andi        $t6, $s1, 0xFFFF
    ctx->r14 = ctx->r17 & 0XFFFF;
    // 0x8005A4A8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8005A4AC: addu        $t8, $s3, $t7
    ctx->r24 = ADD32(ctx->r19, ctx->r15);
    // 0x8005A4B0: addiu       $s1, $t6, 0x1
    ctx->r17 = ADD32(ctx->r14, 0X1);
    // 0x8005A4B4: mflo        $t2
    ctx->r10 = lo;
    // 0x8005A4B8: addu        $s0, $t1, $t2
    ctx->r16 = ADD32(ctx->r9, ctx->r10);
    // 0x8005A4BC: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8005A4C0: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8005A4C4: andi        $t0, $s1, 0xFFFF
    ctx->r8 = ctx->r17 & 0XFFFF;
    // 0x8005A4C8: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8005A4CC: addu        $t2, $s3, $t1
    ctx->r10 = ADD32(ctx->r19, ctx->r9);
    // 0x8005A4D0: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x8005A4D4: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8005A4D8: addiu       $s1, $t0, 0x1
    ctx->r17 = ADD32(ctx->r8, 0X1);
    // 0x8005A4DC: andi        $t4, $s1, 0xFFFF
    ctx->r12 = ctx->r17 & 0XFFFF;
    // 0x8005A4E0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8005A4E4: addu        $t6, $s3, $t5
    ctx->r14 = ADD32(ctx->r19, ctx->r13);
    // 0x8005A4E8: sh          $t3, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r11;
    // 0x8005A4EC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8005A4F0: addiu       $s1, $t4, 0x1
    ctx->r17 = ADD32(ctx->r12, 0X1);
    // 0x8005A4F4: andi        $t8, $s1, 0xFFFF
    ctx->r24 = ctx->r17 & 0XFFFF;
    // 0x8005A4F8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8005A4FC: addu        $t0, $s3, $t9
    ctx->r8 = ADD32(ctx->r19, ctx->r25);
    // 0x8005A500: sh          $t7, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r15;
    // 0x8005A504: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8005A508: addiu       $s1, $t8, 0x1
    ctx->r17 = ADD32(ctx->r24, 0X1);
    // 0x8005A50C: andi        $t2, $s1, 0xFFFF
    ctx->r10 = ctx->r17 & 0XFFFF;
    // 0x8005A510: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8005A514: addu        $t4, $s3, $t3
    ctx->r12 = ADD32(ctx->r19, ctx->r11);
    // 0x8005A518: sh          $t1, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r9;
    // 0x8005A51C: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x8005A520: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
    // 0x8005A524: or          $t0, $s1, $zero
    ctx->r8 = ctx->r17 | 0;
    // 0x8005A528: beq         $v0, $zero, L_8005A62C
    if (ctx->r2 == 0) {
        // 0x8005A52C: addiu       $s1, $t0, 0x2
        ctx->r17 = ADD32(ctx->r8, 0X2);
            goto L_8005A62C;
    }
    // 0x8005A52C: addiu       $s1, $t0, 0x2
    ctx->r17 = ADD32(ctx->r8, 0X2);
    // 0x8005A530: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8005A534: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x8005A538: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x8005A53C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005A540: lw          $t6, 0x18($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X18);
    // 0x8005A544: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8005A548: addiu       $s1, $t2, 0x1
    ctx->r17 = ADD32(ctx->r10, 0X1);
    // 0x8005A54C: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8005A550: andi        $t7, $s1, 0xFFFF
    ctx->r15 = ctx->r17 & 0XFFFF;
    // 0x8005A554: div.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f22.fl);
    // 0x8005A558: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x8005A55C: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x8005A560: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x8005A564: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x8005A568: addu        $t2, $s3, $t1
    ctx->r10 = ADD32(ctx->r19, ctx->r9);
    // 0x8005A56C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8005A570: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x8005A574: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8005A578: add.d       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f0.d + ctx->f0.d;
    // 0x8005A57C: cvt.d.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.d = CVT_D_W(ctx->f8.u32l);
    // 0x8005A580: div.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f18.d);
    // 0x8005A584: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8005A588: bgez        $t0, L_8005A5A0
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8005A58C: swc1        $f6, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
            goto L_8005A5A0;
    }
    // 0x8005A58C: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x8005A590: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8005A594: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005A598: nop

    // 0x8005A59C: add.d       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f16.d + ctx->f10.d;
L_8005A5A0:
    // 0x8005A5A0: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8005A5A4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8005A5A8: andi        $t4, $s1, 0xFFFF
    ctx->r12 = ctx->r17 & 0XFFFF;
    // 0x8005A5AC: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x8005A5B0: swc1        $f24, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f24.u32l;
    // 0x8005A5B4: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x8005A5B8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8005A5BC: addiu       $t5, $zero, 0x34
    ctx->r13 = ADD32(0, 0X34);
    // 0x8005A5C0: or          $s1, $t4, $zero
    ctx->r17 = ctx->r12 | 0;
    // 0x8005A5C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005A5C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005A5CC: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x8005A5D0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005A5D4: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x8005A5D8: div.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x8005A5DC: mul.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x8005A5E0: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005A5E4: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
    // 0x8005A5E8: jal         0x800507E0
    // 0x8005A5EC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_800507E0(rdram, ctx);
        goto after_3;
    // 0x8005A5EC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_3:
    // 0x8005A5F0: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x8005A5F4: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x8005A5F8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8005A5FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005A600: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005A604: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x8005A608: jal         0x800507E0
    // 0x8005A60C: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    func_800507E0(rdram, ctx);
        goto after_4;
    // 0x8005A60C: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_4:
    // 0x8005A610: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x8005A614: sw          $v0, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r2;
    // 0x8005A618: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x8005A61C: swc1        $f26, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f26.u32l;
    // 0x8005A620: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x8005A624: b           L_8005A638
    // 0x8005A628: sw          $fp, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r30;
        goto L_8005A638;
    // 0x8005A628: sw          $fp, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r30;
L_8005A62C:
    // 0x8005A62C: andi        $t1, $s1, 0xFFFF
    ctx->r9 = ctx->r17 & 0XFFFF;
    // 0x8005A630: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x8005A634: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
L_8005A638:
    // 0x8005A638: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x8005A63C: addu        $s2, $s3, $t2
    ctx->r18 = ADD32(ctx->r19, ctx->r10);
    // 0x8005A640: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x8005A644: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005A648: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005A64C: beq         $t3, $zero, L_8005A6B4
    if (ctx->r11 == 0) {
        // 0x8005A650: or          $a2, $s6, $zero
        ctx->r6 = ctx->r22 | 0;
            goto L_8005A6B4;
    }
    // 0x8005A650: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x8005A654: addiu       $t4, $zero, 0x30
    ctx->r12 = ADD32(0, 0X30);
    // 0x8005A658: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8005A65C: jal         0x800507E0
    // 0x8005A660: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    func_800507E0(rdram, ctx);
        goto after_5;
    // 0x8005A660: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_5:
    // 0x8005A664: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x8005A668: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x8005A66C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8005A670: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005A674: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005A678: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x8005A67C: jal         0x800507E0
    // 0x8005A680: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    func_800507E0(rdram, ctx);
        goto after_6;
    // 0x8005A680: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_6:
    // 0x8005A684: lw          $t6, 0x20($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20);
    // 0x8005A688: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8005A68C: andi        $t9, $s1, 0xFFFF
    ctx->r25 = ctx->r17 & 0XFFFF;
    // 0x8005A690: sw          $v0, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->r2;
    // 0x8005A694: lw          $t8, 0x20($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X20);
    // 0x8005A698: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x8005A69C: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x8005A6A0: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x8005A6A4: jal         0x8005A240
    // 0x8005A6A8: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    func_8005A240(rdram, ctx);
        goto after_7;
    // 0x8005A6A8: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    after_7:
    // 0x8005A6AC: b           L_8005A6C8
    // 0x8005A6B0: lbu         $t2, 0x24($s5)
    ctx->r10 = MEM_BU(ctx->r21, 0X24);
        goto L_8005A6C8;
    // 0x8005A6B0: lbu         $t2, 0x24($s5)
    ctx->r10 = MEM_BU(ctx->r21, 0X24);
L_8005A6B4:
    // 0x8005A6B4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8005A6B8: andi        $t0, $s1, 0xFFFF
    ctx->r8 = ctx->r17 & 0XFFFF;
    // 0x8005A6BC: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x8005A6C0: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
    // 0x8005A6C4: lbu         $t2, 0x24($s5)
    ctx->r10 = MEM_BU(ctx->r21, 0X24);
L_8005A6C8:
    // 0x8005A6C8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8005A6CC: andi        $t1, $s4, 0xFFFF
    ctx->r9 = ctx->r20 & 0XFFFF;
    // 0x8005A6D0: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8005A6D4: bne         $at, $zero, L_8005A48C
    if (ctx->r1 != 0) {
        // 0x8005A6D8: or          $s4, $t1, $zero
        ctx->r20 = ctx->r9 | 0;
            goto L_8005A48C;
    }
    // 0x8005A6D8: or          $s4, $t1, $zero
    ctx->r20 = ctx->r9 | 0;
L_8005A6DC:
    // 0x8005A6DC: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x8005A6E0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8005A6E4: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8005A6E8: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x8005A6EC: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x8005A6F0: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8005A6F4: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x8005A6F8: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x8005A6FC: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x8005A700: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x8005A704: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x8005A708: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x8005A70C: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x8005A710: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x8005A714: jr          $ra
    // 0x8005A718: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    TRACE_RETURN()
    return;
    // 0x8005A718: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_8005A720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005A720: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005A724: sll         $t0, $a1, 16
    ctx->r8 = S32(ctx->r5 << 16);
    // 0x8005A728: sra         $t6, $t0, 16
    ctx->r14 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8005A72C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8005A730: sll         $s1, $t6, 2
    ctx->r17 = S32(ctx->r14 << 2);
    // 0x8005A734: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005A738: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8005A73C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8005A740: addu        $s1, $s1, $t6
    ctx->r17 = ADD32(ctx->r17, ctx->r14);
    // 0x8005A744: lw          $t7, 0x34($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X34);
    // 0x8005A748: sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17 << 2);
    // 0x8005A74C: subu        $s1, $s1, $t6
    ctx->r17 = SUB32(ctx->r17, ctx->r14);
    // 0x8005A750: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8005A754: sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17 << 2);
    // 0x8005A758: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8005A75C: addu        $a0, $t7, $s1
    ctx->r4 = ADD32(ctx->r15, ctx->r17);
    // 0x8005A760: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x8005A764: jal         0x8005A2E0
    // 0x8005A768: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    func_8005A2E0(rdram, ctx);
        goto after_0;
    // 0x8005A768: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_0:
    // 0x8005A76C: lw          $t8, 0x34($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X34);
    // 0x8005A770: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8005A774: addu        $a2, $t8, $s1
    ctx->r6 = ADD32(ctx->r24, ctx->r17);
    // 0x8005A778: jal         0x80062644
    // 0x8005A77C: addiu       $a0, $a2, 0x20
    ctx->r4 = ADD32(ctx->r6, 0X20);
    func_80062644(rdram, ctx);
        goto after_1;
    // 0x8005A77C: addiu       $a0, $a2, 0x20
    ctx->r4 = ADD32(ctx->r6, 0X20);
    after_1:
    // 0x8005A780: lw          $t9, 0x34($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X34);
    // 0x8005A784: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x8005A788: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8005A78C: addu        $a2, $t9, $s1
    ctx->r6 = ADD32(ctx->r25, ctx->r17);
    // 0x8005A790: jal         0x8005A7C0
    // 0x8005A794: addiu       $a2, $a2, 0x20
    ctx->r6 = ADD32(ctx->r6, 0X20);
    func_8005A7C0(rdram, ctx);
        goto after_2;
    // 0x8005A794: addiu       $a2, $a2, 0x20
    ctx->r6 = ADD32(ctx->r6, 0X20);
    after_2:
    // 0x8005A798: lw          $t2, 0x34($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X34);
    // 0x8005A79C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005A7A0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8005A7A4: addu        $v0, $t2, $s1
    ctx->r2 = ADD32(ctx->r10, ctx->r17);
    // 0x8005A7A8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8005A7AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005A7B0: jr          $ra
    // 0x8005A7B4: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    TRACE_RETURN()
    return;
    // 0x8005A7B4: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
;}
RECOMP_FUNC void func_8005A7C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005A7C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005A7C4: bne         $a1, $at, L_8005A7E8
    if (ctx->r5 != ctx->r1) {
        // 0x8005A7C8: lw          $v0, 0x1C($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1C);
            goto L_8005A7E8;
    }
    // 0x8005A7C8: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x8005A7CC: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x8005A7D0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8005A7D4: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8005A7D8: sw          $a2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r6;
    // 0x8005A7DC: lw          $t9, 0x14($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14);
    // 0x8005A7E0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8005A7E4: sw          $t0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r8;
L_8005A7E8:
    // 0x8005A7E8: jr          $ra
    // 0x8005A7EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    TRACE_RETURN()
    return;
    // 0x8005A7EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_8005A7F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005A7F0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8005A7F4: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x8005A7F8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8005A7FC: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8005A800: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8005A804: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8005A808: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8005A80C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8005A810: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8005A814: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8005A818: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8005A81C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005A820: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x8005A824: lui         $t6, 0x200
    ctx->r14 = S32(0X200 << 16);
    // 0x8005A828: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x8005A82C: lui         $t7, 0x200
    ctx->r15 = S32(0X200 << 16);
    // 0x8005A830: ori         $t6, $t6, 0x440
    ctx->r14 = ctx->r14 | 0X440;
    // 0x8005A834: ori         $t7, $t7, 0x580
    ctx->r15 = ctx->r15 | 0X580;
    // 0x8005A838: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x8005A83C: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    // 0x8005A840: sw          $t7, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r15;
    // 0x8005A844: sw          $v0, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r2;
    // 0x8005A848: lw          $t8, 0x14($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14);
    // 0x8005A84C: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x8005A850: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x8005A854: or          $fp, $a3, $zero
    ctx->r30 = ctx->r7 | 0;
    // 0x8005A858: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8005A85C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8005A860: blez        $t8, L_8005A8DC
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8005A864: addiu       $s3, $t0, 0x10
        ctx->r19 = ADD32(ctx->r8, 0X10);
            goto L_8005A8DC;
    }
    // 0x8005A864: addiu       $s3, $t0, 0x10
    ctx->r19 = ADD32(ctx->r8, 0X10);
    // 0x8005A868: lui         $s2, 0xC00
    ctx->r18 = S32(0XC00 << 16);
    // 0x8005A86C: ori         $s2, $s2, 0x7FFF
    ctx->r18 = ctx->r18 | 0X7FFF;
    // 0x8005A870: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x8005A874: andi        $s6, $v0, 0xFFFF
    ctx->r22 = ctx->r2 & 0XFFFF;
L_8005A878:
    // 0x8005A878: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8005A87C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x8005A880: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x8005A884: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x8005A888: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x8005A88C: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x8005A890: jalr        $t9
    // 0x8005A894: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8005A894: nop

    after_0:
    // 0x8005A898: lui         $t2, 0x6C0
    ctx->r10 = S32(0X6C0 << 16);
    // 0x8005A89C: lui         $t3, 0x800
    ctx->r11 = S32(0X800 << 16);
    // 0x8005A8A0: lui         $t1, 0x800
    ctx->r9 = S32(0X800 << 16);
    // 0x8005A8A4: ori         $t2, $t2, 0x440
    ctx->r10 = ctx->r10 | 0X440;
    // 0x8005A8A8: ori         $t3, $t3, 0x580
    ctx->r11 = ctx->r11 | 0X580;
    // 0x8005A8AC: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8005A8B0: sw          $s6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r22;
    // 0x8005A8B4: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x8005A8B8: sw          $s2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r18;
    // 0x8005A8BC: sw          $t3, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r11;
    // 0x8005A8C0: sw          $s2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r18;
    // 0x8005A8C4: lw          $t4, 0x14($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X14);
    // 0x8005A8C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8005A8CC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8005A8D0: slt         $at, $s0, $t4
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8005A8D4: bne         $at, $zero, L_8005A878
    if (ctx->r1 != 0) {
        // 0x8005A8D8: addiu       $s3, $v0, 0x18
        ctx->r19 = ADD32(ctx->r2, 0X18);
            goto L_8005A878;
    }
    // 0x8005A8D8: addiu       $s3, $v0, 0x18
    ctx->r19 = ADD32(ctx->r2, 0X18);
L_8005A8DC:
    // 0x8005A8DC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8005A8E0: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x8005A8E4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8005A8E8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005A8EC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8005A8F0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8005A8F4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8005A8F8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8005A8FC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8005A900: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8005A904: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8005A908: jr          $ra
    // 0x8005A90C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    TRACE_RETURN()
    return;
    // 0x8005A90C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8005A910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005A910: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005A914: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005A918: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005A91C: beq         $a1, $at, L_8005AA74
    if (ctx->r5 == ctx->r1) {
        // 0x8005A920: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_8005AA74;
    }
    // 0x8005A920: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8005A924: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8005A928: bnel        $a1, $at, L_8005AAD8
    if (ctx->r5 != ctx->r1) {
        // 0x8005A92C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005AAD8;
    }
    goto skip_0;
    // 0x8005A92C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8005A930: sw          $a2, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r6;
    // 0x8005A934: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8005A938: sw          $zero, 0x38($a0)
    MEM_W(0X38, ctx->r4) = 0;
    // 0x8005A93C: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x8005A940: sw          $t6, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r14;
    // 0x8005A944: lbu         $v0, 0x8($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X8);
    // 0x8005A948: beql        $v0, $zero, L_8005A968
    if (ctx->r2 == 0) {
        // 0x8005A94C: lw          $v0, 0x28($a3)
        ctx->r2 = MEM_W(ctx->r7, 0X28);
            goto L_8005A968;
    }
    goto skip_1;
    // 0x8005A94C: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    skip_1:
    // 0x8005A950: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8005A954: beq         $v0, $a0, L_8005AA28
    if (ctx->r2 == ctx->r4) {
        // 0x8005A958: lui         $t0, 0x8006
        ctx->r8 = S32(0X8006 << 16);
            goto L_8005AA28;
    }
    // 0x8005A958: lui         $t0, 0x8006
    ctx->r8 = S32(0X8006 << 16);
    // 0x8005A95C: b           L_8005AAD8
    // 0x8005A960: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8005AAD8;
    // 0x8005A960: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005A964: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
L_8005A968:
    // 0x8005A968: addiu       $t7, $t7, -0x5044
    ctx->r15 = ADD32(ctx->r15, -0X5044);
    // 0x8005A96C: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x8005A970: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x8005A974: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x8005A978: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x8005A97C: mflo        $t9
    ctx->r25 = lo;
    // 0x8005A980: bne         $a1, $zero, L_8005A98C
    if (ctx->r5 != 0) {
        // 0x8005A984: nop
    
            goto L_8005A98C;
    }
    // 0x8005A984: nop

    // 0x8005A988: break       7
    do_break(2147854728);
L_8005A98C:
    // 0x8005A98C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005A990: bne         $a1, $at, L_8005A9A4
    if (ctx->r5 != ctx->r1) {
        // 0x8005A994: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8005A9A4;
    }
    // 0x8005A994: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005A998: bne         $t8, $at, L_8005A9A4
    if (ctx->r24 != ctx->r1) {
        // 0x8005A99C: nop
    
            goto L_8005A9A4;
    }
    // 0x8005A99C: nop

    // 0x8005A9A0: break       6
    do_break(2147854752);
L_8005A9A4:
    // 0x8005A9A4: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005A9A8: mflo        $t0
    ctx->r8 = lo;
    // 0x8005A9AC: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8005A9B0: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    // 0x8005A9B4: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    // 0x8005A9B8: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005A9BC: lw          $t3, 0x4($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X4);
    // 0x8005A9C0: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x8005A9C4: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005A9C8: mflo        $t4
    ctx->r12 = lo;
    // 0x8005A9CC: sw          $t4, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->r12;
    // 0x8005A9D0: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x8005A9D4: beql        $v1, $zero, L_8005AA1C
    if (ctx->r3 == 0) {
        // 0x8005A9D8: sw          $zero, 0x24($a3)
        MEM_W(0X24, ctx->r7) = 0;
            goto L_8005AA1C;
    }
    goto skip_2;
    // 0x8005A9D8: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
    skip_2:
    // 0x8005A9DC: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8005A9E0: lw          $a1, 0x18($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X18);
    // 0x8005A9E4: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x8005A9E8: sw          $t5, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r13;
    // 0x8005A9EC: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x8005A9F0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8005A9F4: sw          $t7, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r15;
    // 0x8005A9F8: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x8005A9FC: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x8005AA00: sw          $t9, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r25;
    // 0x8005AA04: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x8005AA08: jal         0x80060E90
    // 0x8005AA0C: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_80060E90(rdram, ctx);
        goto after_0;
    // 0x8005AA0C: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_0:
    // 0x8005AA10: b           L_8005AAD8
    // 0x8005AA14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8005AAD8;
    // 0x8005AA14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005AA18: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
L_8005AA1C:
    // 0x8005AA1C: sw          $zero, 0x20($a3)
    MEM_W(0X20, ctx->r7) = 0;
    // 0x8005AA20: b           L_8005AAD4
    // 0x8005AA24: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
        goto L_8005AAD4;
    // 0x8005AA24: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
L_8005AA28:
    // 0x8005AA28: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    // 0x8005AA2C: addiu       $t0, $t0, -0x551C
    ctx->r8 = ADD32(ctx->r8, -0X551C);
    // 0x8005AA30: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    // 0x8005AA34: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x8005AA38: beql        $v1, $zero, L_8005AA68
    if (ctx->r3 == 0) {
        // 0x8005AA3C: sw          $zero, 0x24($a3)
        MEM_W(0X24, ctx->r7) = 0;
            goto L_8005AA68;
    }
    goto skip_3;
    // 0x8005AA3C: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
    skip_3:
    // 0x8005AA40: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8005AA44: sw          $t1, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r9;
    // 0x8005AA48: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x8005AA4C: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x8005AA50: sw          $t3, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r11;
    // 0x8005AA54: lw          $t4, 0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XC);
    // 0x8005AA58: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x8005AA5C: b           L_8005AAD4
    // 0x8005AA60: sw          $t5, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r13;
        goto L_8005AAD4;
    // 0x8005AA60: sw          $t5, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r13;
    // 0x8005AA64: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
L_8005AA68:
    // 0x8005AA68: sw          $zero, 0x20($a3)
    MEM_W(0X20, ctx->r7) = 0;
    // 0x8005AA6C: b           L_8005AAD4
    // 0x8005AA70: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
        goto L_8005AAD4;
    // 0x8005AA70: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
L_8005AA74:
    // 0x8005AA74: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    // 0x8005AA78: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8005AA7C: sw          $zero, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = 0;
    // 0x8005AA80: sw          $a0, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r4;
    // 0x8005AA84: beq         $v0, $zero, L_8005AAD4
    if (ctx->r2 == 0) {
        // 0x8005AA88: sw          $zero, 0x38($a3)
        MEM_W(0X38, ctx->r7) = 0;
            goto L_8005AAD4;
    }
    // 0x8005AA88: sw          $zero, 0x38($a3)
    MEM_W(0X38, ctx->r7) = 0;
    // 0x8005AA8C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8005AA90: sw          $t6, 0x44($a3)
    MEM_W(0X44, ctx->r7) = ctx->r14;
    // 0x8005AA94: lbu         $v1, 0x8($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X8);
    // 0x8005AA98: bne         $v1, $zero, L_8005AAB8
    if (ctx->r3 != 0) {
        // 0x8005AA9C: nop
    
            goto L_8005AAB8;
    }
    // 0x8005AA9C: nop

    // 0x8005AAA0: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x8005AAA4: beql        $v1, $zero, L_8005AAD8
    if (ctx->r3 == 0) {
        // 0x8005AAA8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005AAD8;
    }
    goto skip_4;
    // 0x8005AAA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x8005AAAC: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x8005AAB0: b           L_8005AAD4
    // 0x8005AAB4: sw          $t7, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r15;
        goto L_8005AAD4;
    // 0x8005AAB4: sw          $t7, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r15;
L_8005AAB8:
    // 0x8005AAB8: bnel        $a0, $v1, L_8005AAD8
    if (ctx->r4 != ctx->r3) {
        // 0x8005AABC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005AAD8;
    }
    goto skip_5;
    // 0x8005AABC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x8005AAC0: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x8005AAC4: beql        $v1, $zero, L_8005AAD8
    if (ctx->r3 == 0) {
        // 0x8005AAC8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005AAD8;
    }
    goto skip_6;
    // 0x8005AAC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x8005AACC: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x8005AAD0: sw          $t8, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r24;
L_8005AAD4:
    // 0x8005AAD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005AAD8:
    // 0x8005AAD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005AADC: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005AAE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005AAE4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8005AAE8: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8005AAEC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8005AAF0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8005AAF4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8005AAF8: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x8005AAFC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005AB00: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8005AB04: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8005AB08: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x8005AB0C: or          $t2, $a1, $zero
    ctx->r10 = ctx->r5 | 0;
    // 0x8005AB10: bne         $a2, $zero, L_8005AB20
    if (ctx->r6 != 0) {
        // 0x8005AB14: or          $t1, $t0, $zero
        ctx->r9 = ctx->r8 | 0;
            goto L_8005AB20;
    }
    // 0x8005AB14: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
    // 0x8005AB18: b           L_8005AE74
    // 0x8005AB1C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_8005AE74;
    // 0x8005AB1C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8005AB20:
    // 0x8005AB20: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x8005AB24: lw          $v1, 0x20($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X20);
    // 0x8005AB28: addu        $t6, $v0, $s3
    ctx->r14 = ADD32(ctx->r2, ctx->r19);
    // 0x8005AB2C: sltu        $at, $v1, $t6
    ctx->r1 = ctx->r3 < ctx->r14 ? 1 : 0;
    // 0x8005AB30: beql        $at, $zero, L_8005AD44
    if (ctx->r1 == 0) {
        // 0x8005AB34: lw          $v0, 0x28($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X28);
            goto L_8005AD44;
    }
    goto skip_0;
    // 0x8005AB34: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    skip_0:
    // 0x8005AB38: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x8005AB3C: subu        $s2, $v1, $v0
    ctx->r18 = SUB32(ctx->r3, ctx->r2);
    // 0x8005AB40: beql        $t7, $zero, L_8005AD44
    if (ctx->r15 == 0) {
        // 0x8005AB44: lw          $v0, 0x28($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X28);
            goto L_8005AD44;
    }
    goto skip_1;
    // 0x8005AB44: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    skip_1:
    // 0x8005AB48: blez        $s2, L_8005ABC4
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8005AB4C: sll         $s1, $s2, 1
        ctx->r17 = S32(ctx->r18 << 1);
            goto L_8005ABC4;
    }
    // 0x8005AB4C: sll         $s1, $s2, 1
    ctx->r17 = S32(ctx->r18 << 1);
    // 0x8005AB50: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x8005AB54: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x8005AB58: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x8005AB5C: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x8005AB60: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8005AB64: jalr        $t9
    // 0x8005AB68: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8005AB68: nop

    after_0:
    // 0x8005AB6C: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x8005AB70: andi        $a2, $v0, 0x7
    ctx->r6 = ctx->r2 & 0X7;
    // 0x8005AB74: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8005AB78: lh          $t8, 0x0($t2)
    ctx->r24 = MEM_H(ctx->r10, 0X0);
    // 0x8005AB7C: addu        $a3, $s1, $a2
    ctx->r7 = ADD32(ctx->r17, ctx->r6);
    // 0x8005AB80: andi        $t5, $a3, 0x7
    ctx->r13 = ctx->r7 & 0X7;
    // 0x8005AB84: subu        $t6, $a3, $t5
    ctx->r14 = SUB32(ctx->r7, ctx->r13);
    // 0x8005AB88: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8005AB8C: andi        $t3, $t8, 0xFFFF
    ctx->r11 = ctx->r24 & 0XFFFF;
    // 0x8005AB90: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x8005AB94: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8005AB98: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8005AB9C: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x8005ABA0: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x8005ABA4: subu        $t3, $v0, $a2
    ctx->r11 = SUB32(ctx->r2, ctx->r6);
    // 0x8005ABA8: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x8005ABAC: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8005ABB0: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x8005ABB4: sw          $t3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r11;
    // 0x8005ABB8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8005ABBC: b           L_8005ABC8
    // 0x8005ABC0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
        goto L_8005ABC8;
    // 0x8005ABC0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_8005ABC4:
    // 0x8005ABC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8005ABC8:
    // 0x8005ABC8: lh          $t4, 0x0($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X0);
    // 0x8005ABCC: slt         $at, $s2, $s3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8005ABD0: addu        $t5, $t4, $a2
    ctx->r13 = ADD32(ctx->r12, ctx->r6);
    // 0x8005ABD4: sh          $t5, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r13;
    // 0x8005ABD8: lw          $t6, 0x28($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X28);
    // 0x8005ABDC: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x8005ABE0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8005ABE4: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x8005ABE8: sw          $v0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r2;
    // 0x8005ABEC: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x8005ABF0: sw          $t8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r24;
    // 0x8005ABF4: beq         $at, $zero, L_8005AD1C
    if (ctx->r1 == 0) {
        // 0x8005ABF8: lh          $t0, 0x0($t2)
        ctx->r8 = MEM_H(ctx->r10, 0X0);
            goto L_8005AD1C;
    }
    // 0x8005ABF8: lh          $t0, 0x0($t2)
    ctx->r8 = MEM_H(ctx->r10, 0X0);
    // 0x8005ABFC: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
L_8005AC00:
    // 0x8005AC00: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005AC04: addu        $t0, $t0, $s1
    ctx->r8 = ADD32(ctx->r8, ctx->r17);
    // 0x8005AC08: beq         $v0, $at, L_8005AC1C
    if (ctx->r2 == ctx->r1) {
        // 0x8005AC0C: subu        $s3, $s3, $s2
        ctx->r19 = SUB32(ctx->r19, ctx->r18);
            goto L_8005AC1C;
    }
    // 0x8005AC0C: subu        $s3, $s3, $s2
    ctx->r19 = SUB32(ctx->r19, ctx->r18);
    // 0x8005AC10: beq         $v0, $zero, L_8005AC1C
    if (ctx->r2 == 0) {
        // 0x8005AC14: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_8005AC1C;
    }
    // 0x8005AC14: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x8005AC18: sw          $t3, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r11;
L_8005AC1C:
    // 0x8005AC1C: lw          $t4, 0x20($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X20);
    // 0x8005AC20: lw          $t5, 0x1C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1C);
    // 0x8005AC24: subu        $v0, $t4, $t5
    ctx->r2 = SUB32(ctx->r12, ctx->r13);
    // 0x8005AC28: sltu        $at, $s3, $v0
    ctx->r1 = ctx->r19 < ctx->r2 ? 1 : 0;
    // 0x8005AC2C: beq         $at, $zero, L_8005AC3C
    if (ctx->r1 == 0) {
        // 0x8005AC30: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_8005AC3C;
    }
    // 0x8005AC30: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8005AC34: b           L_8005AC3C
    // 0x8005AC38: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
        goto L_8005AC3C;
    // 0x8005AC38: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
L_8005AC3C:
    // 0x8005AC3C: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x8005AC40: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x8005AC44: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x8005AC48: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8005AC4C: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x8005AC50: sll         $s1, $s2, 1
    ctx->r17 = S32(ctx->r18 << 1);
    // 0x8005AC54: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8005AC58: jalr        $t9
    // 0x8005AC5C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8005AC5C: nop

    after_1:
    // 0x8005AC60: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8005AC64: andi        $a1, $v0, 0x7
    ctx->r5 = ctx->r2 & 0X7;
    // 0x8005AC68: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x8005AC6C: andi        $v1, $t0, 0x7
    ctx->r3 = ctx->r8 & 0X7;
    // 0x8005AC70: beq         $v1, $zero, L_8005AC84
    if (ctx->r3 == 0) {
        // 0x8005AC74: addu        $a3, $s1, $a1
        ctx->r7 = ADD32(ctx->r17, ctx->r5);
            goto L_8005AC84;
    }
    // 0x8005AC74: addu        $a3, $s1, $a1
    ctx->r7 = ADD32(ctx->r17, ctx->r5);
    // 0x8005AC78: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8005AC7C: b           L_8005AC88
    // 0x8005AC80: subu        $a2, $t6, $v1
    ctx->r6 = SUB32(ctx->r14, ctx->r3);
        goto L_8005AC88;
    // 0x8005AC80: subu        $a2, $t6, $v1
    ctx->r6 = SUB32(ctx->r14, ctx->r3);
L_8005AC84:
    // 0x8005AC84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8005AC88:
    // 0x8005AC88: addu        $t7, $t0, $a2
    ctx->r15 = ADD32(ctx->r8, ctx->r6);
    // 0x8005AC8C: andi        $t4, $a3, 0x7
    ctx->r12 = ctx->r7 & 0X7;
    // 0x8005AC90: subu        $t5, $a3, $t4
    ctx->r13 = SUB32(ctx->r7, ctx->r12);
    // 0x8005AC94: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8005AC98: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x8005AC9C: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8005ACA0: or          $t3, $t8, $at
    ctx->r11 = ctx->r24 | ctx->r1;
    // 0x8005ACA4: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x8005ACA8: addiu       $t9, $t5, 0x8
    ctx->r25 = ADD32(ctx->r13, 0X8);
    // 0x8005ACAC: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x8005ACB0: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x8005ACB4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8005ACB8: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8005ACBC: subu        $t8, $v0, $a1
    ctx->r24 = SUB32(ctx->r2, ctx->r5);
    // 0x8005ACC0: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x8005ACC4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8005ACC8: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8005ACCC: bne         $a1, $zero, L_8005ACD8
    if (ctx->r5 != 0) {
        // 0x8005ACD0: addiu       $t1, $t1, 0x8
        ctx->r9 = ADD32(ctx->r9, 0X8);
            goto L_8005ACD8;
    }
    // 0x8005ACD0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x8005ACD4: beq         $a2, $zero, L_8005AD10
    if (ctx->r6 == 0) {
        // 0x8005ACD8: addu        $t3, $t0, $a1
        ctx->r11 = ADD32(ctx->r8, ctx->r5);
            goto L_8005AD10;
    }
L_8005ACD8:
    // 0x8005ACD8: addu        $t3, $t0, $a1
    ctx->r11 = ADD32(ctx->r8, ctx->r5);
    // 0x8005ACDC: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8005ACE0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8005ACE4: addu        $t4, $t3, $a2
    ctx->r12 = ADD32(ctx->r11, ctx->r6);
    // 0x8005ACE8: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x8005ACEC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8005ACF0: lui         $at, 0xA00
    ctx->r1 = S32(0XA00 << 16);
    // 0x8005ACF4: sll         $t7, $t0, 16
    ctx->r15 = S32(ctx->r8 << 16);
    // 0x8005ACF8: andi        $t8, $s1, 0xFFFF
    ctx->r24 = ctx->r17 & 0XFFFF;
    // 0x8005ACFC: or          $t3, $t7, $t8
    ctx->r11 = ctx->r15 | ctx->r24;
    // 0x8005AD00: or          $t9, $t5, $at
    ctx->r25 = ctx->r13 | ctx->r1;
    // 0x8005AD04: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8005AD08: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8005AD0C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_8005AD10:
    // 0x8005AD10: slt         $at, $s2, $s3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8005AD14: bnel        $at, $zero, L_8005AC00
    if (ctx->r1 != 0) {
        // 0x8005AD18: lw          $v0, 0x24($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X24);
            goto L_8005AC00;
    }
    goto skip_2;
    // 0x8005AD18: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    skip_2:
L_8005AD1C:
    // 0x8005AD1C: lw          $t4, 0x38($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X38);
    // 0x8005AD20: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    // 0x8005AD24: sll         $t6, $s3, 1
    ctx->r14 = S32(ctx->r19 << 1);
    // 0x8005AD28: addu        $t5, $t4, $s3
    ctx->r13 = ADD32(ctx->r12, ctx->r19);
    // 0x8005AD2C: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x8005AD30: sw          $t5, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r13;
    // 0x8005AD34: sw          $t7, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r15;
    // 0x8005AD38: b           L_8005AE74
    // 0x8005AD3C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_8005AE74;
    // 0x8005AD3C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8005AD40: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
L_8005AD44:
    // 0x8005AD44: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x8005AD48: sll         $s1, $s3, 1
    ctx->r17 = S32(ctx->r19 << 1);
    // 0x8005AD4C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8005AD50: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x8005AD54: addu        $v1, $a0, $s1
    ctx->r3 = ADD32(ctx->r4, ctx->r17);
    // 0x8005AD58: subu        $t3, $v1, $t8
    ctx->r11 = SUB32(ctx->r3, ctx->r24);
    // 0x8005AD5C: subu        $s2, $t3, $t4
    ctx->r18 = SUB32(ctx->r11, ctx->r12);
    // 0x8005AD60: bgezl       $s2, L_8005AD70
    if (SIGNED(ctx->r18) >= 0) {
        // 0x8005AD64: slt         $at, $s1, $s2
        ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
            goto L_8005AD70;
    }
    goto skip_3;
    // 0x8005AD64: slt         $at, $s1, $s2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
    skip_3:
    // 0x8005AD68: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8005AD6C: slt         $at, $s1, $s2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
L_8005AD70:
    // 0x8005AD70: beql        $at, $zero, L_8005AD80
    if (ctx->r1 == 0) {
        // 0x8005AD74: slt         $at, $s2, $s1
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r17) ? 1 : 0;
            goto L_8005AD80;
    }
    goto skip_4;
    // 0x8005AD74: slt         $at, $s2, $s1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r17) ? 1 : 0;
    skip_4:
    // 0x8005AD78: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
    // 0x8005AD7C: slt         $at, $s2, $s1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r17) ? 1 : 0;
L_8005AD80:
    // 0x8005AD80: beql        $at, $zero, L_8005AE34
    if (ctx->r1 == 0) {
        // 0x8005AD84: sw          $v1, 0x44($s0)
        MEM_W(0X44, ctx->r16) = ctx->r3;
            goto L_8005AE34;
    }
    goto skip_5;
    // 0x8005AD84: sw          $v1, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r3;
    skip_5:
    // 0x8005AD88: blez        $s3, L_8005AE08
    if (SIGNED(ctx->r19) <= 0) {
        // 0x8005AD8C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8005AE08;
    }
    // 0x8005AD8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005AD90: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x8005AD94: subu        $a1, $s1, $s2
    ctx->r5 = SUB32(ctx->r17, ctx->r18);
    // 0x8005AD98: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    // 0x8005AD9C: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x8005ADA0: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x8005ADA4: jalr        $t9
    // 0x8005ADA8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8005ADA8: nop

    after_2:
    // 0x8005ADAC: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x8005ADB0: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x8005ADB4: andi        $a2, $v0, 0x7
    ctx->r6 = ctx->r2 & 0X7;
    // 0x8005ADB8: lh          $t5, 0x0($t2)
    ctx->r13 = MEM_H(ctx->r10, 0X0);
    // 0x8005ADBC: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8005ADC0: addu        $a3, $a3, $a2
    ctx->r7 = ADD32(ctx->r7, ctx->r6);
    // 0x8005ADC4: andi        $t8, $a3, 0x7
    ctx->r24 = ctx->r7 & 0X7;
    // 0x8005ADC8: subu        $t3, $a3, $t8
    ctx->r11 = SUB32(ctx->r7, ctx->r24);
    // 0x8005ADCC: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8005ADD0: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x8005ADD4: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8005ADD8: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8005ADDC: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8005ADE0: andi        $t9, $t4, 0xFFFF
    ctx->r25 = ctx->r12 & 0XFFFF;
    // 0x8005ADE4: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x8005ADE8: subu        $t6, $v0, $a2
    ctx->r14 = SUB32(ctx->r2, ctx->r6);
    // 0x8005ADEC: lui         $t5, 0x400
    ctx->r13 = S32(0X400 << 16);
    // 0x8005ADF0: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8005ADF4: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x8005ADF8: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8005ADFC: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8005AE00: b           L_8005AE08
    // 0x8005AE04: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
        goto L_8005AE08;
    // 0x8005AE04: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_8005AE08:
    // 0x8005AE08: lh          $t7, 0x0($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X0);
    // 0x8005AE0C: addu        $t8, $t7, $a2
    ctx->r24 = ADD32(ctx->r15, ctx->r6);
    // 0x8005AE10: sh          $t8, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r24;
    // 0x8005AE14: lw          $t3, 0x38($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X38);
    // 0x8005AE18: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    // 0x8005AE1C: addu        $t4, $t3, $s3
    ctx->r12 = ADD32(ctx->r11, ctx->r19);
    // 0x8005AE20: addu        $t5, $t9, $s1
    ctx->r13 = ADD32(ctx->r25, ctx->r17);
    // 0x8005AE24: sw          $t4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r12;
    // 0x8005AE28: b           L_8005AE34
    // 0x8005AE2C: sw          $t5, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r13;
        goto L_8005AE34;
    // 0x8005AE2C: sw          $t5, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r13;
    // 0x8005AE30: sw          $v1, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r3;
L_8005AE34:
    // 0x8005AE34: beq         $s2, $zero, L_8005AE70
    if (ctx->r18 == 0) {
        // 0x8005AE38: subu        $v1, $s1, $s2
        ctx->r3 = SUB32(ctx->r17, ctx->r18);
            goto L_8005AE70;
    }
    // 0x8005AE38: subu        $v1, $s1, $s2
    ctx->r3 = SUB32(ctx->r17, ctx->r18);
    // 0x8005AE3C: bgez        $v1, L_8005AE48
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8005AE40: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_8005AE48;
    }
    // 0x8005AE40: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8005AE44: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8005AE48:
    // 0x8005AE48: lh          $t6, 0x0($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X0);
    // 0x8005AE4C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8005AE50: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8005AE54: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x8005AE58: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8005AE5C: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8005AE60: or          $t3, $t8, $at
    ctx->r11 = ctx->r24 | ctx->r1;
    // 0x8005AE64: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8005AE68: sw          $s2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r18;
    // 0x8005AE6C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_8005AE70:
    // 0x8005AE70: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_8005AE74:
    // 0x8005AE74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005AE78: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8005AE7C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8005AE80: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8005AE84: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8005AE88: jr          $ra
    // 0x8005AE8C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    TRACE_RETURN()
    return;
    // 0x8005AE8C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8005AE90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005AE90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005AE94: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8005AE98: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8005AE9C: sll         $t6, $s3, 16
    ctx->r14 = S32(ctx->r19 << 16);
    // 0x8005AEA0: sll         $t8, $s5, 16
    ctx->r24 = S32(ctx->r21 << 16);
    // 0x8005AEA4: sra         $s5, $t8, 16
    ctx->r21 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8005AEA8: sra         $s3, $t6, 16
    ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8005AEAC: blez        $s1, L_8005AF18
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8005AEB0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8005AF18;
    }
    // 0x8005AEB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005AEB4: lw          $t9, 0x30($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X30);
    // 0x8005AEB8: lw          $a0, 0x44($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X44);
    // 0x8005AEBC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8005AEC0: jalr        $t9
    // 0x8005AEC4: lw          $a2, 0x34($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X34);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8005AEC4: lw          $a2, 0x34($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X34);
    after_0:
    // 0x8005AEC8: andi        $a2, $v0, 0x7
    ctx->r6 = ctx->r2 & 0X7;
    // 0x8005AECC: addu        $s1, $s1, $a2
    ctx->r17 = ADD32(ctx->r17, ctx->r6);
    // 0x8005AED0: andi        $t6, $s3, 0xFFFF
    ctx->r14 = ctx->r19 & 0XFFFF;
    // 0x8005AED4: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8005AED8: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8005AEDC: andi        $t8, $s1, 0x7
    ctx->r24 = ctx->r17 & 0X7;
    // 0x8005AEE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005AEE4: subu        $t9, $s1, $t8
    ctx->r25 = SUB32(ctx->r17, ctx->r24);
    // 0x8005AEE8: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x8005AEEC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8005AEF0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8005AEF4: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x8005AEF8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8005AEFC: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8005AF00: subu        $t9, $v0, $a2
    ctx->r25 = SUB32(ctx->r2, ctx->r6);
    // 0x8005AF04: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x8005AF08: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8005AF0C: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x8005AF10: b           L_8005AF1C
    // 0x8005AF14: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_8005AF1C;
    // 0x8005AF14: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_8005AF18:
    // 0x8005AF18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8005AF1C:
    // 0x8005AF1C: andi        $t6, $s4, 0x2
    ctx->r14 = ctx->r20 & 0X2;
    // 0x8005AF20: beq         $t6, $zero, L_8005AF48
    if (ctx->r14 == 0) {
        // 0x8005AF24: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_8005AF48;
    }
    // 0x8005AF24: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8005AF28: lui         $t7, 0xF00
    ctx->r15 = S32(0XF00 << 16);
    // 0x8005AF2C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005AF30: lw          $t8, 0x18($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X18);
    // 0x8005AF34: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x8005AF38: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8005AF3C: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8005AF40: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8005AF44: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_8005AF48:
    // 0x8005AF48: addu        $t6, $s3, $a2
    ctx->r14 = ADD32(ctx->r19, ctx->r6);
    // 0x8005AF4C: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x8005AF50: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8005AF54: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8005AF58: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8005AF5C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8005AF60: sll         $t7, $s6, 1
    ctx->r15 = S32(ctx->r22 << 1);
    // 0x8005AF64: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8005AF68: sll         $t6, $s5, 16
    ctx->r14 = S32(ctx->r21 << 16);
    // 0x8005AF6C: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8005AF70: andi        $t7, $s4, 0xFF
    ctx->r15 = ctx->r20 & 0XFF;
    // 0x8005AF74: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8005AF78: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x8005AF7C: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x8005AF80: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8005AF84: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x8005AF88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005AF8C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8005AF90: lw          $t9, 0x14($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X14);
    // 0x8005AF94: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x8005AF98: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8005AF9C: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x8005AFA0: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8005AFA4: sw          $zero, 0x40($s2)
    MEM_W(0X40, ctx->r18) = 0;
    // 0x8005AFA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005AFAC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8005AFB0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8005AFB4: jr          $ra
    // 0x8005AFB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    TRACE_RETURN()
    return;
    // 0x8005AFB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005AFBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005AFBC: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8005AFC0: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8005AFC4: sw          $a3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r7;
    // 0x8005AFC8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8005AFCC: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x8005AFD0: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8005AFD4: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8005AFD8: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8005AFDC: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8005AFE0: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8005AFE4: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8005AFE8: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8005AFEC: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8005AFF0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8005AFF4: sw          $a1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r5;
    // 0x8005AFF8: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x8005AFFC: bne         $a2, $zero, L_8005B00C
    if (ctx->r6 != 0) {
        // 0x8005B000: or          $t5, $zero, $zero
        ctx->r13 = 0 | 0;
            goto L_8005B00C;
    }
    // 0x8005B000: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x8005B004: b           L_8005B42C
    // 0x8005B008: lw          $v0, 0xC0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC0);
        goto L_8005B42C;
    // 0x8005B008: lw          $v0, 0xC0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC0);
L_8005B00C:
    // 0x8005B00C: lw          $t6, 0x2C($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X2C);
    // 0x8005B010: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8005B014: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8005B018: lw          $a1, 0xC0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC0);
    // 0x8005B01C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8005B020: lui         $at, 0xB00
    ctx->r1 = S32(0XB00 << 16);
    // 0x8005B024: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8005B028: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8005B02C: lw          $t9, 0x28($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X28);
    // 0x8005B030: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x8005B034: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8005B038: lw          $t6, 0x10($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X10);
    // 0x8005B03C: addiu       $t2, $a1, 0x8
    ctx->r10 = ADD32(ctx->r5, 0X8);
    // 0x8005B040: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005B044: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8005B048: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8005B04C: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x8005B050: lw          $v1, 0x38($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X38);
    // 0x8005B054: lw          $a0, 0x20($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X20);
    // 0x8005B058: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x8005B05C: addu        $t9, $v1, $t0
    ctx->r25 = ADD32(ctx->r3, ctx->r8);
    // 0x8005B060: sltu        $t1, $a0, $t9
    ctx->r9 = ctx->r4 < ctx->r25 ? 1 : 0;
    // 0x8005B064: beq         $t1, $zero, L_8005B078
    if (ctx->r9 == 0) {
        // 0x8005B068: addiu       $t7, $zero, 0x10
        ctx->r15 = ADD32(0, 0X10);
            goto L_8005B078;
    }
    // 0x8005B068: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x8005B06C: lw          $t1, 0x24($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X24);
    // 0x8005B070: sltu        $t6, $zero, $t1
    ctx->r14 = 0 < ctx->r9 ? 1 : 0;
    // 0x8005B074: or          $t1, $t6, $zero
    ctx->r9 = ctx->r14 | 0;
L_8005B078:
    // 0x8005B078: beq         $t1, $zero, L_8005B088
    if (ctx->r9 == 0) {
        // 0x8005B07C: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_8005B088;
    }
    // 0x8005B07C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8005B080: b           L_8005B088
    // 0x8005B084: subu        $a1, $a0, $v1
    ctx->r5 = SUB32(ctx->r4, ctx->r3);
        goto L_8005B088;
    // 0x8005B084: subu        $a1, $a0, $v1
    ctx->r5 = SUB32(ctx->r4, ctx->r3);
L_8005B088:
    // 0x8005B088: lw          $v1, 0x3C($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X3C);
    // 0x8005B08C: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x8005B090: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x8005B094: beq         $v1, $zero, L_8005B0A4
    if (ctx->r3 == 0) {
        // 0x8005B098: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8005B0A4;
    }
    // 0x8005B098: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8005B09C: b           L_8005B0A4
    // 0x8005B0A0: subu        $a2, $t7, $v1
    ctx->r6 = SUB32(ctx->r15, ctx->r3);
        goto L_8005B0A4;
    // 0x8005B0A0: subu        $a2, $t7, $v1
    ctx->r6 = SUB32(ctx->r15, ctx->r3);
L_8005B0A4:
    // 0x8005B0A4: subu        $a0, $a1, $a2
    ctx->r4 = SUB32(ctx->r5, ctx->r6);
    // 0x8005B0A8: bgez        $a0, L_8005B0B4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8005B0AC: nop
    
            goto L_8005B0B4;
    }
    // 0x8005B0AC: nop

    // 0x8005B0B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8005B0B4:
    // 0x8005B0B4: beq         $t1, $zero, L_8005B2BC
    if (ctx->r9 == 0) {
        // 0x8005B0B8: addiu       $fp, $a0, 0xF
        ctx->r30 = ADD32(ctx->r4, 0XF);
            goto L_8005B2BC;
    }
    // 0x8005B0B8: addiu       $fp, $a0, 0xF
    ctx->r30 = ADD32(ctx->r4, 0XF);
    // 0x8005B0BC: addiu       $fp, $a0, 0xF
    ctx->r30 = ADD32(ctx->r4, 0XF);
    // 0x8005B0C0: sra         $t8, $fp, 4
    ctx->r24 = S32(SIGNED(ctx->r30) >> 4);
    // 0x8005B0C4: lh          $s5, 0x0($a3)
    ctx->r21 = MEM_H(ctx->r7, 0X0);
    // 0x8005B0C8: lw          $s4, 0x40($s7)
    ctx->r20 = MEM_W(ctx->r23, 0X40);
    // 0x8005B0CC: sll         $t1, $t8, 3
    ctx->r9 = S32(ctx->r24 << 3);
    // 0x8005B0D0: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8005B0D4: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x8005B0D8: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x8005B0DC: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    // 0x8005B0E0: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    // 0x8005B0E4: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x8005B0E8: or          $fp, $t8, $zero
    ctx->r30 = ctx->r24 | 0;
    // 0x8005B0EC: jal         0x8005AE90
    // 0x8005B0F0: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    func_8005AE90(rdram, ctx);
        goto after_0;
    // 0x8005B0F0: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    after_0:
    // 0x8005B0F4: lw          $v1, 0x3C($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X3C);
    // 0x8005B0F8: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x8005B0FC: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x8005B100: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x8005B104: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8005B108: beq         $v1, $zero, L_8005B124
    if (ctx->r3 == 0) {
        // 0x8005B10C: or          $t2, $v0, $zero
        ctx->r10 = ctx->r2 | 0;
            goto L_8005B124;
    }
    // 0x8005B10C: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x8005B110: lh          $t9, 0x0($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X0);
    // 0x8005B114: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x8005B118: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x8005B11C: b           L_8005B130
    // 0x8005B120: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
        goto L_8005B130;
    // 0x8005B120: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
L_8005B124:
    // 0x8005B124: lh          $t8, 0x0($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X0);
    // 0x8005B128: addiu       $t9, $t8, 0x20
    ctx->r25 = ADD32(ctx->r24, 0X20);
    // 0x8005B12C: sh          $t9, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r25;
L_8005B130:
    // 0x8005B130: lw          $v0, 0x1C($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X1C);
    // 0x8005B134: lw          $t7, 0x28($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X28);
    // 0x8005B138: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8005B13C: andi        $t6, $v0, 0xF
    ctx->r14 = ctx->r2 & 0XF;
    // 0x8005B140: sw          $t6, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = ctx->r14;
    // 0x8005B144: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8005B148: srl         $t9, $v0, 4
    ctx->r25 = S32(U32(ctx->r2) >> 4);
    // 0x8005B14C: sll         $t6, $t9, 3
    ctx->r14 = S32(ctx->r25 << 3);
    // 0x8005B150: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x8005B154: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x8005B158: addiu       $t9, $t7, 0x9
    ctx->r25 = ADD32(ctx->r15, 0X9);
    // 0x8005B15C: sw          $t9, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r25;
    // 0x8005B160: sw          $v0, 0x38($s7)
    MEM_W(0X38, ctx->r23) = ctx->r2;
    // 0x8005B164: beq         $at, $zero, L_8005B28C
    if (ctx->r1 == 0) {
        // 0x8005B168: lh          $a2, 0x0($a3)
        ctx->r6 = MEM_H(ctx->r7, 0X0);
            goto L_8005B28C;
    }
    // 0x8005B168: lh          $a2, 0x0($a3)
    ctx->r6 = MEM_H(ctx->r7, 0X0);
    // 0x8005B16C: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
L_8005B170:
    // 0x8005B170: addiu       $t8, $fp, 0x1
    ctx->r24 = ADD32(ctx->r30, 0X1);
    // 0x8005B174: sll         $t6, $t8, 5
    ctx->r14 = S32(ctx->r24 << 5);
    // 0x8005B178: lw          $v0, 0x24($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X24);
    // 0x8005B17C: addu        $a3, $t6, $a2
    ctx->r7 = ADD32(ctx->r14, ctx->r6);
    // 0x8005B180: addiu       $at, $zero, -0x20
    ctx->r1 = ADD32(0, -0X20);
    // 0x8005B184: and         $t7, $a3, $at
    ctx->r15 = ctx->r7 & ctx->r1;
    // 0x8005B188: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005B18C: subu        $t0, $t0, $a1
    ctx->r8 = SUB32(ctx->r8, ctx->r5);
    // 0x8005B190: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x8005B194: beq         $v0, $at, L_8005B1A8
    if (ctx->r2 == ctx->r1) {
        // 0x8005B198: addu        $a2, $a2, $v1
        ctx->r6 = ADD32(ctx->r6, ctx->r3);
            goto L_8005B1A8;
    }
    // 0x8005B198: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x8005B19C: beq         $v0, $zero, L_8005B1A8
    if (ctx->r2 == 0) {
        // 0x8005B1A0: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_8005B1A8;
    }
    // 0x8005B1A0: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x8005B1A4: sw          $t9, 0x24($s7)
    MEM_W(0X24, ctx->r23) = ctx->r25;
L_8005B1A8:
    // 0x8005B1A8: lw          $t8, 0x20($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X20);
    // 0x8005B1AC: lw          $t6, 0x1C($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X1C);
    // 0x8005B1B0: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x8005B1B4: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x8005B1B8: subu        $v0, $t8, $t6
    ctx->r2 = SUB32(ctx->r24, ctx->r14);
    // 0x8005B1BC: sltu        $at, $t0, $v0
    ctx->r1 = ctx->r8 < ctx->r2 ? 1 : 0;
    // 0x8005B1C0: beq         $at, $zero, L_8005B1D0
    if (ctx->r1 == 0) {
        // 0x8005B1C4: sll         $s5, $a3, 16
        ctx->r21 = S32(ctx->r7 << 16);
            goto L_8005B1D0;
    }
    // 0x8005B1C4: sll         $s5, $a3, 16
    ctx->r21 = S32(ctx->r7 << 16);
    // 0x8005B1C8: b           L_8005B1D4
    // 0x8005B1CC: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
        goto L_8005B1D4;
    // 0x8005B1CC: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
L_8005B1D0:
    // 0x8005B1D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8005B1D4:
    // 0x8005B1D4: lw          $t7, 0x3C($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X3C);
    // 0x8005B1D8: sra         $t8, $s5, 16
    ctx->r24 = S32(SIGNED(ctx->r21) >> 16);
    // 0x8005B1DC: or          $s5, $t8, $zero
    ctx->r21 = ctx->r24 | 0;
    // 0x8005B1E0: addu        $a0, $a1, $t7
    ctx->r4 = ADD32(ctx->r5, ctx->r15);
    // 0x8005B1E4: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
    // 0x8005B1E8: bgez        $a0, L_8005B1F4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8005B1EC: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8005B1F4;
    }
    // 0x8005B1EC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8005B1F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8005B1F4:
    // 0x8005B1F4: lw          $s4, 0x40($s7)
    ctx->r20 = MEM_W(ctx->r23, 0X40);
    // 0x8005B1F8: addiu       $fp, $a0, 0xF
    ctx->r30 = ADD32(ctx->r4, 0XF);
    // 0x8005B1FC: sra         $t9, $fp, 4
    ctx->r25 = S32(SIGNED(ctx->r30) >> 4);
    // 0x8005B200: sll         $t1, $t9, 3
    ctx->r9 = S32(ctx->r25 << 3);
    // 0x8005B204: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x8005B208: ori         $t6, $s4, 0x2
    ctx->r14 = ctx->r20 | 0X2;
    // 0x8005B20C: or          $s4, $t6, $zero
    ctx->r20 = ctx->r14 | 0;
    // 0x8005B210: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x8005B214: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x8005B218: or          $fp, $t9, $zero
    ctx->r30 = ctx->r25 | 0;
    // 0x8005B21C: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    // 0x8005B220: sw          $a3, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r7;
    // 0x8005B224: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x8005B228: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x8005B22C: jal         0x8005AE90
    // 0x8005B230: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    func_8005AE90(rdram, ctx);
        goto after_1;
    // 0x8005B230: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    after_1:
    // 0x8005B234: lw          $t7, 0x3C($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X3C);
    // 0x8005B238: lw          $a3, 0x88($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X88);
    // 0x8005B23C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8005B240: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x8005B244: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8005B248: addu        $t8, $t9, $a3
    ctx->r24 = ADD32(ctx->r25, ctx->r7);
    // 0x8005B24C: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x8005B250: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x8005B254: lui         $at, 0xA00
    ctx->r1 = S32(0XA00 << 16);
    // 0x8005B258: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x8005B25C: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8005B260: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x8005B264: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8005B268: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x8005B26C: andi        $t6, $v1, 0xFFFF
    ctx->r14 = ctx->r3 & 0XFFFF;
    // 0x8005B270: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005B274: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x8005B278: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8005B27C: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8005B280: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8005B284: bne         $at, $zero, L_8005B170
    if (ctx->r1 != 0) {
        // 0x8005B288: addiu       $t2, $v0, 0x8
        ctx->r10 = ADD32(ctx->r2, 0X8);
            goto L_8005B170;
    }
    // 0x8005B288: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
L_8005B28C:
    // 0x8005B28C: lw          $t9, 0x3C($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X3C);
    // 0x8005B290: lw          $t7, 0x38($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X38);
    // 0x8005B294: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8005B298: addu        $t8, $t9, $t0
    ctx->r24 = ADD32(ctx->r25, ctx->r8);
    // 0x8005B29C: andi        $t6, $t8, 0xF
    ctx->r14 = ctx->r24 & 0XF;
    // 0x8005B2A0: lw          $t8, 0x44($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X44);
    // 0x8005B2A4: sw          $t6, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = ctx->r14;
    // 0x8005B2A8: addu        $t9, $t7, $t0
    ctx->r25 = ADD32(ctx->r15, ctx->r8);
    // 0x8005B2AC: addu        $t6, $t8, $t1
    ctx->r14 = ADD32(ctx->r24, ctx->r9);
    // 0x8005B2B0: sw          $t9, 0x38($s7)
    MEM_W(0X38, ctx->r23) = ctx->r25;
    // 0x8005B2B4: b           L_8005B42C
    // 0x8005B2B8: sw          $t6, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r14;
        goto L_8005B42C;
    // 0x8005B2B8: sw          $t6, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r14;
L_8005B2BC:
    // 0x8005B2BC: lw          $v0, 0x28($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X28);
    // 0x8005B2C0: sra         $t7, $fp, 4
    ctx->r15 = S32(SIGNED(ctx->r30) >> 4);
    // 0x8005B2C4: lw          $t9, 0x44($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X44);
    // 0x8005B2C8: sll         $t1, $t7, 3
    ctx->r9 = S32(ctx->r15 << 3);
    // 0x8005B2CC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8005B2D0: addu        $t1, $t1, $t7
    ctx->r9 = ADD32(ctx->r9, ctx->r15);
    // 0x8005B2D4: or          $fp, $t7, $zero
    ctx->r30 = ctx->r15 | 0;
    // 0x8005B2D8: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8005B2DC: addu        $t3, $t9, $t1
    ctx->r11 = ADD32(ctx->r25, ctx->r9);
    // 0x8005B2E0: subu        $t6, $t3, $t8
    ctx->r14 = SUB32(ctx->r11, ctx->r24);
    // 0x8005B2E4: subu        $v1, $t6, $t7
    ctx->r3 = SUB32(ctx->r14, ctx->r15);
    // 0x8005B2E8: bgez        $v1, L_8005B2F4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8005B2EC: sll         $a1, $fp, 4
        ctx->r5 = S32(ctx->r30 << 4);
            goto L_8005B2F4;
    }
    // 0x8005B2EC: sll         $a1, $fp, 4
    ctx->r5 = S32(ctx->r30 << 4);
    // 0x8005B2F0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8005B2F4:
    // 0x8005B2F4: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x8005B2F8: mflo        $v0
    ctx->r2 = lo;
    // 0x8005B2FC: sll         $a0, $v0, 4
    ctx->r4 = S32(ctx->r2 << 4);
    // 0x8005B300: addu        $t4, $a1, $a2
    ctx->r12 = ADD32(ctx->r5, ctx->r6);
    // 0x8005B304: slt         $at, $t4, $a0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8005B308: beq         $at, $zero, L_8005B314
    if (ctx->r1 == 0) {
        // 0x8005B30C: or          $s0, $t2, $zero
        ctx->r16 = ctx->r10 | 0;
            goto L_8005B314;
    }
    // 0x8005B30C: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x8005B310: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
L_8005B314:
    // 0x8005B314: andi        $t8, $a0, 0xF
    ctx->r24 = ctx->r4 & 0XF;
    // 0x8005B318: subu        $t6, $a0, $t8
    ctx->r14 = SUB32(ctx->r4, ctx->r24);
    // 0x8005B31C: slt         $at, $t6, $t0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8005B320: beq         $at, $zero, L_8005B3D0
    if (ctx->r1 == 0) {
        // 0x8005B324: subu        $a2, $t1, $v1
        ctx->r6 = SUB32(ctx->r9, ctx->r3);
            goto L_8005B3D0;
    }
    // 0x8005B324: subu        $a2, $t1, $v1
    ctx->r6 = SUB32(ctx->r9, ctx->r3);
    // 0x8005B328: lh          $s5, 0x0($a3)
    ctx->r21 = MEM_H(ctx->r7, 0X0);
    // 0x8005B32C: lw          $s4, 0x40($s7)
    ctx->r20 = MEM_W(ctx->r23, 0X40);
    // 0x8005B330: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8005B334: sw          $t5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r13;
    // 0x8005B338: sw          $t4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r12;
    // 0x8005B33C: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x8005B340: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    // 0x8005B344: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    // 0x8005B348: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x8005B34C: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x8005B350: subu        $s6, $a1, $a0
    ctx->r22 = SUB32(ctx->r5, ctx->r4);
    // 0x8005B354: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8005B358: jal         0x8005AE90
    // 0x8005B35C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    func_8005AE90(rdram, ctx);
        goto after_2;
    // 0x8005B35C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    after_2:
    // 0x8005B360: lw          $v1, 0x3C($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X3C);
    // 0x8005B364: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x8005B368: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x8005B36C: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x8005B370: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8005B374: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8005B378: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x8005B37C: beq         $v1, $zero, L_8005B398
    if (ctx->r3 == 0) {
        // 0x8005B380: or          $t2, $v0, $zero
        ctx->r10 = ctx->r2 | 0;
            goto L_8005B398;
    }
    // 0x8005B380: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x8005B384: lh          $t7, 0x0($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X0);
    // 0x8005B388: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x8005B38C: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x8005B390: b           L_8005B3A4
    // 0x8005B394: sh          $t8, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r24;
        goto L_8005B3A4;
    // 0x8005B394: sh          $t8, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r24;
L_8005B398:
    // 0x8005B398: lh          $t6, 0x0($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X0);
    // 0x8005B39C: addiu       $t7, $t6, 0x20
    ctx->r15 = ADD32(ctx->r14, 0X20);
    // 0x8005B3A0: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
L_8005B3A4:
    // 0x8005B3A4: lw          $t9, 0x3C($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X3C);
    // 0x8005B3A8: lw          $t7, 0x38($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X38);
    // 0x8005B3AC: addu        $t8, $t9, $t0
    ctx->r24 = ADD32(ctx->r25, ctx->r8);
    // 0x8005B3B0: andi        $t6, $t8, 0xF
    ctx->r14 = ctx->r24 & 0XF;
    // 0x8005B3B4: lw          $t8, 0x44($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X44);
    // 0x8005B3B8: sw          $t6, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = ctx->r14;
    // 0x8005B3BC: addu        $t9, $t7, $t0
    ctx->r25 = ADD32(ctx->r15, ctx->r8);
    // 0x8005B3C0: addu        $t6, $t8, $t1
    ctx->r14 = ADD32(ctx->r24, ctx->r9);
    // 0x8005B3C4: sw          $t9, 0x38($s7)
    MEM_W(0X38, ctx->r23) = ctx->r25;
    // 0x8005B3C8: b           L_8005B3D8
    // 0x8005B3CC: sw          $t6, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r14;
        goto L_8005B3D8;
    // 0x8005B3CC: sw          $t6, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r14;
L_8005B3D0:
    // 0x8005B3D0: sw          $zero, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = 0;
    // 0x8005B3D4: sw          $t3, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r11;
L_8005B3D8:
    // 0x8005B3D8: beq         $a0, $zero, L_8005B428
    if (ctx->r4 == 0) {
        // 0x8005B3DC: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_8005B428;
    }
    // 0x8005B3DC: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8005B3E0: beq         $t5, $zero, L_8005B3F8
    if (ctx->r13 == 0) {
        // 0x8005B3E4: sw          $zero, 0x3C($s7)
        MEM_W(0X3C, ctx->r23) = 0;
            goto L_8005B3F8;
    }
    // 0x8005B3E4: sw          $zero, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = 0;
    // 0x8005B3E8: subu        $v1, $t4, $a0
    ctx->r3 = SUB32(ctx->r12, ctx->r4);
    // 0x8005B3EC: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x8005B3F0: b           L_8005B3FC
    // 0x8005B3F4: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
        goto L_8005B3FC;
    // 0x8005B3F4: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
L_8005B3F8:
    // 0x8005B3F8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8005B3FC:
    // 0x8005B3FC: lh          $t9, 0x0($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X0);
    // 0x8005B400: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8005B404: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8005B408: addu        $t8, $t9, $v1
    ctx->r24 = ADD32(ctx->r25, ctx->r3);
    // 0x8005B40C: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x8005B410: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8005B414: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8005B418: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x8005B41C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8005B420: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005B424: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
L_8005B428:
    // 0x8005B428: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_8005B42C:
    // 0x8005B42C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8005B430: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8005B434: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8005B438: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8005B43C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8005B440: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8005B444: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8005B448: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8005B44C: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8005B450: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8005B454: jr          $ra
    // 0x8005B458: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    TRACE_RETURN()
    return;
    // 0x8005B458: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_8005B460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005B460: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x8005B464: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005B468: sltiu       $at, $t6, 0x9
    ctx->r1 = ctx->r14 < 0X9 ? 1 : 0;
    // 0x8005B46C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005B470: beq         $at, $zero, L_8005B520
    if (ctx->r1 == 0) {
        // 0x8005B474: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_8005B520;
    }
    // 0x8005B474: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8005B478: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8005B47C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8005B480: addu        $at, $at, $t6
    gpr jr_addend_8005B488 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8005B484: lw          $t6, -0x68E0($at)
    ctx->r14 = ADD32(ctx->r1, -0X68E0);
    // 0x8005B488: jr          $t6
    // 0x8005B48C: nop

    switch (jr_addend_8005B488 >> 2) {
        case 0: goto L_8005B490; break;
        case 1: goto L_8005B520; break;
        case 2: goto L_8005B520; break;
        case 3: goto L_8005B498; break;
        case 4: goto L_8005B520; break;
        case 5: goto L_8005B520; break;
        case 6: goto L_8005B504; break;
        case 7: goto L_8005B514; break;
        case 8: goto L_8005B4D4; break;
        default: switch_error(__func__, 0x8005B488, 0x80079720);
    }
    // 0x8005B48C: nop

L_8005B490:
    // 0x8005B490: b           L_8005B538
    // 0x8005B494: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
        goto L_8005B538;
    // 0x8005B494: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
L_8005B498:
    // 0x8005B498: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x8005B49C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005B4A0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005B4A4: sw          $t7, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r15;
    // 0x8005B4A8: sw          $zero, 0x30($a3)
    MEM_W(0X30, ctx->r7) = 0;
    // 0x8005B4AC: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
    // 0x8005B4B0: beq         $a0, $zero, L_8005B538
    if (ctx->r4 == 0) {
        // 0x8005B4B4: swc1        $f4, 0x20($a3)
        MEM_W(0X20, ctx->r7) = ctx->f4.u32l;
            goto L_8005B538;
    }
    // 0x8005B4B4: swc1        $f4, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f4.u32l;
    // 0x8005B4B8: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x8005B4BC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8005B4C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005B4C4: jalr        $t9
    // 0x8005B4C8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8005B4C8: nop

    after_0:
    // 0x8005B4CC: b           L_8005B53C
    // 0x8005B4D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8005B53C;
    // 0x8005B4D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005B4D4:
    // 0x8005B4D4: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x8005B4D8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8005B4DC: sw          $t8, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r24;
    // 0x8005B4E0: beql        $a0, $zero, L_8005B53C
    if (ctx->r4 == 0) {
        // 0x8005B4E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005B53C;
    }
    goto skip_0;
    // 0x8005B4E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8005B4E8: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x8005B4EC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x8005B4F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005B4F4: jalr        $t9
    // 0x8005B4F8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8005B4F8: nop

    after_1:
    // 0x8005B4FC: b           L_8005B53C
    // 0x8005B500: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8005B53C;
    // 0x8005B500: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005B504:
    // 0x8005B504: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x8005B508: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8005B50C: b           L_8005B538
    // 0x8005B510: swc1        $f6, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f6.u32l;
        goto L_8005B538;
    // 0x8005B510: swc1        $f6, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f6.u32l;
L_8005B514:
    // 0x8005B514: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8005B518: b           L_8005B538
    // 0x8005B51C: sw          $t0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r8;
        goto L_8005B538;
    // 0x8005B51C: sw          $t0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r8;
L_8005B520:
    // 0x8005B520: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x8005B524: beql        $a0, $zero, L_8005B53C
    if (ctx->r4 == 0) {
        // 0x8005B528: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005B53C;
    }
    goto skip_1;
    // 0x8005B528: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8005B52C: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x8005B530: jalr        $t9
    // 0x8005B534: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8005B534: nop

    after_2:
L_8005B538:
    // 0x8005B538: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005B53C:
    // 0x8005B53C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8005B540: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005B544: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005B54C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005B54C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8005B550: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005B554: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8005B558: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005B55C: addiu       $t6, $zero, 0x140
    ctx->r14 = ADD32(0, 0X140);
    // 0x8005B560: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x8005B564: or          $t2, $a2, $zero
    ctx->r10 = ctx->r6 | 0;
    // 0x8005B568: bne         $a2, $zero, L_8005B578
    if (ctx->r6 != 0) {
        // 0x8005B56C: sh          $t6, 0x46($sp)
        MEM_H(0X46, ctx->r29) = ctx->r14;
            goto L_8005B578;
    }
    // 0x8005B56C: sh          $t6, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r14;
    // 0x8005B570: b           L_8005B744
    // 0x8005B574: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
        goto L_8005B744;
    // 0x8005B574: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
L_8005B578:
    // 0x8005B578: lw          $t7, 0x1C($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X1C);
    // 0x8005B57C: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8005B580: beql        $t7, $zero, L_8005B5EC
    if (ctx->r15 == 0) {
        // 0x8005B584: lwc1        $f2, 0x18($t0)
        ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
            goto L_8005B5EC;
    }
    goto skip_0;
    // 0x8005B584: lwc1        $f2, 0x18($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
    skip_0:
    // 0x8005B588: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8005B58C: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
    // 0x8005B590: lw          $t9, 0x4($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X4);
    // 0x8005B594: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x8005B598: addiu       $a1, $sp, 0x46
    ctx->r5 = ADD32(ctx->r29, 0X46);
    // 0x8005B59C: jalr        $t9
    // 0x8005B5A0: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8005B5A0: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    after_0:
    // 0x8005B5A4: lh          $t3, 0x46($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X46);
    // 0x8005B5A8: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8005B5AC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8005B5B0: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x8005B5B4: lui         $at, 0xA00
    ctx->r1 = S32(0XA00 << 16);
    // 0x8005B5B8: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x8005B5BC: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x8005B5C0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8005B5C4: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x8005B5C8: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8005B5CC: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x8005B5D0: lh          $t8, 0x0($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X0);
    // 0x8005B5D4: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    // 0x8005B5D8: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8005B5DC: or          $t5, $t9, $t4
    ctx->r13 = ctx->r25 | ctx->r12;
    // 0x8005B5E0: b           L_8005B740
    // 0x8005B5E4: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
        goto L_8005B740;
    // 0x8005B5E4: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8005B5E8: lwc1        $f2, 0x18($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
L_8005B5EC:
    // 0x8005B5EC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8005B5F0: ldc1        $f4, -0x68B8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X68B8);
    // 0x8005B5F4: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x8005B5F8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8005B5FC: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x8005B600: nop

    // 0x8005B604: bc1fl       L_8005B61C
    if (!c1cs) {
        // 0x8005B608: lui         $at, 0x4700
        ctx->r1 = S32(0X4700 << 16);
            goto L_8005B61C;
    }
    goto skip_1;
    // 0x8005B608: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    skip_1:
    // 0x8005B60C: lwc1        $f8, -0x68B0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X68B0);
    // 0x8005B610: swc1        $f8, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f8.u32l;
    // 0x8005B614: lwc1        $f2, 0x18($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
    // 0x8005B618: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
L_8005B61C:
    // 0x8005B61C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8005B620: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x8005B624: addiu       $a1, $sp, 0x46
    ctx->r5 = ADD32(ctx->r29, 0X46);
    // 0x8005B628: mul.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x8005B62C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8005B630: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x8005B634: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8005B638: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8005B63C: nop

    // 0x8005B640: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8005B644: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8005B648: swc1        $f4, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f4.u32l;
    // 0x8005B64C: lwc1        $f6, 0x18($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X18);
    // 0x8005B650: div.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8005B654: lwc1        $f6, 0x20($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X20);
    // 0x8005B658: swc1        $f8, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f8.u32l;
    // 0x8005B65C: lwc1        $f10, 0x18($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X18);
    // 0x8005B660: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8005B664: add.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8005B668: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005B66C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8005B670: nop

    // 0x8005B674: mtc1        $a2, $f16
    ctx->f16.u32l = ctx->r6;
    // 0x8005B678: nop

    // 0x8005B67C: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8005B680: sub.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8005B684: swc1        $f18, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f18.u32l;
    // 0x8005B688: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x8005B68C: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
    // 0x8005B690: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x8005B694: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8005B698: lw          $t9, 0x4($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X4);
    // 0x8005B69C: jalr        $t9
    // 0x8005B6A0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8005B6A0: nop

    after_1:
    // 0x8005B6A4: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8005B6A8: lh          $t5, 0x46($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X46);
    // 0x8005B6AC: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x8005B6B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005B6B4: lwc1        $f6, 0x18($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X18);
    // 0x8005B6B8: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8005B6BC: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x8005B6C0: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x8005B6C4: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8005B6C8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005B6CC: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x8005B6D0: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8005B6D4: sll         $t5, $t2, 1
    ctx->r13 = S32(ctx->r10 << 1);
    // 0x8005B6D8: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x8005B6DC: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x8005B6E0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8005B6E4: sll         $t4, $t9, 16
    ctx->r12 = S32(ctx->r25 << 16);
    // 0x8005B6E8: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x8005B6EC: trunc.w.s   $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8005B6F0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8005B6F4: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x8005B6F8: lw          $t3, 0x24($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X24);
    // 0x8005B6FC: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x8005B700: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x8005B704: andi        $t9, $t3, 0xFF
    ctx->r25 = ctx->r11 & 0XFF;
    // 0x8005B708: sll         $t5, $t9, 16
    ctx->r13 = S32(ctx->r25 << 16);
    // 0x8005B70C: or          $t4, $t5, $at
    ctx->r12 = ctx->r13 | ctx->r1;
    // 0x8005B710: andi        $t6, $v1, 0xFFFF
    ctx->r14 = ctx->r3 & 0XFFFF;
    // 0x8005B714: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x8005B718: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x8005B71C: addiu       $a1, $v0, 0x10
    ctx->r5 = ADD32(ctx->r2, 0X10);
    // 0x8005B720: lw          $a0, 0x14($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X14);
    // 0x8005B724: jal         0x80053750
    // 0x8005B728: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x8005B728: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    after_2:
    // 0x8005B72C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8005B730: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8005B734: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8005B738: sw          $v0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r2;
    // 0x8005B73C: sw          $zero, 0x24($t0)
    MEM_W(0X24, ctx->r8) = 0;
L_8005B740:
    // 0x8005B740: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8005B744:
    // 0x8005B744: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005B748: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8005B74C: jr          $ra
    // 0x8005B750: nop

    TRACE_RETURN()
    return;
    // 0x8005B750: nop

    // 0x8005B754: nop

    // 0x8005B758: nop

    // 0x8005B75C: nop

    // 0x8005B760: beq         $a2, $zero, L_8005B780
    if (ctx->r6 == 0) {
        // 0x8005B764: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8005B780;
    }
    // 0x8005B764: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005B768: sllv        $t7, $t6, $a2
    ctx->r15 = S32(ctx->r14 << (ctx->r6 & 31));
    // 0x8005B76C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8005B770: nop

    // 0x8005B774: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8005B778: mul.d       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f6.d); 
    ctx->f12.d = MUL_D(ctx->f12.d, ctx->f6.d);
    // 0x8005B77C: nop

L_8005B780:
    // 0x8005B780: jr          $ra
    // 0x8005B784: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    TRACE_RETURN()
    return;
    // 0x8005B784: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
;}
RECOMP_FUNC void func_8005B788(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005B788: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    // 0x8005B78C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8005B790: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8005B794: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8005B798: c.eq.d      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.d == ctx->f2.d;
    // 0x8005B79C: nop

    // 0x8005B7A0: bc1fl       L_8005B7B4
    if (!c1cs) {
        // 0x8005B7A4: c.lt.d      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
            goto L_8005B7B4;
    }
    goto skip_0;
    // 0x8005B7A4: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
    skip_0:
    // 0x8005B7A8: jr          $ra
    // 0x8005B7AC: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    TRACE_RETURN()
    return;
    // 0x8005B7AC: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    // 0x8005B7B0: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
L_8005B7B4:
    // 0x8005B7B4: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8005B7B8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8005B7BC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8005B7C0: bc1fl       L_8005B7D4
    if (!c1cs) {
        // 0x8005B7C4: neg.d       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f0.d = -ctx->f12.d;
            goto L_8005B7D4;
    }
    goto skip_1;
    // 0x8005B7C4: neg.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f0.d = -ctx->f12.d;
    skip_1:
    // 0x8005B7C8: b           L_8005B7D4
    // 0x8005B7CC: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
        goto L_8005B7D4;
    // 0x8005B7CC: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    // 0x8005B7D0: neg.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f0.d = -ctx->f12.d;
L_8005B7D4:
    // 0x8005B7D4: c.le.d      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.d <= ctx->f0.d;
    // 0x8005B7D8: nop

    // 0x8005B7DC: bc1fl       L_8005B814
    if (!c1cs) {
        // 0x8005B7E0: lui         $at, 0x3FE0
        ctx->r1 = S32(0X3FE0 << 16);
            goto L_8005B814;
    }
    goto skip_2;
    // 0x8005B7E0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    skip_2:
    // 0x8005B7E4: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8005B7E8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005B7EC: nop

L_8005B7F0:
    // 0x8005B7F0: mul.d       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f16.d);
    // 0x8005B7F4: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8005B7F8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8005B7FC: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x8005B800: c.le.d      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.d <= ctx->f0.d;
    // 0x8005B804: nop

    // 0x8005B808: bc1t        L_8005B7F0
    if (c1cs) {
        // 0x8005B80C: nop
    
            goto L_8005B7F0;
    }
    // 0x8005B80C: nop

    // 0x8005B810: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
L_8005B814:
    // 0x8005B814: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8005B818: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005B81C: nop

    // 0x8005B820: c.lt.d      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.d < ctx->f16.d;
    // 0x8005B824: nop

    // 0x8005B828: bc1fl       L_8005B850
    if (!c1cs) {
        // 0x8005B82C: c.lt.d      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
            goto L_8005B850;
    }
    goto skip_3;
    // 0x8005B82C: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
    skip_3:
    // 0x8005B830: add.d       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f0.d + ctx->f0.d;
L_8005B834:
    // 0x8005B834: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8005B838: c.lt.d      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.d < ctx->f16.d;
    // 0x8005B83C: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8005B840: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8005B844: bc1tl       L_8005B834
    if (c1cs) {
        // 0x8005B848: add.d       $f0, $f0, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f0.d + ctx->f0.d;
            goto L_8005B834;
    }
    goto skip_4;
    // 0x8005B848: add.d       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f0.d + ctx->f0.d;
    skip_4:
    // 0x8005B84C: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
L_8005B850:
    // 0x8005B850: nop

    // 0x8005B854: bc1fl       L_8005B868
    if (!c1cs) {
        // 0x8005B858: neg.d       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = -ctx->f0.d;
            goto L_8005B868;
    }
    goto skip_5;
    // 0x8005B858: neg.d       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = -ctx->f0.d;
    skip_5:
    // 0x8005B85C: b           L_8005B868
    // 0x8005B860: mov.d       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.d = ctx->f0.d;
        goto L_8005B868;
    // 0x8005B860: mov.d       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.d = ctx->f0.d;
    // 0x8005B864: neg.d       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = -ctx->f0.d;
L_8005B868:
    // 0x8005B868: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
    // 0x8005B86C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005B874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005B874: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005B878: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005B87C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005B880: beq         $a1, $v0, L_8005B920
    if (ctx->r5 == ctx->r2) {
        // 0x8005B884: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_8005B920;
    }
    // 0x8005B884: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8005B888: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005B88C: beq         $a1, $at, L_8005B8AC
    if (ctx->r5 == ctx->r1) {
        // 0x8005B890: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8005B8AC;
    }
    // 0x8005B890: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005B894: beq         $a1, $at, L_8005B8CC
    if (ctx->r5 == ctx->r1) {
        // 0x8005B898: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_8005B8CC;
    }
    // 0x8005B898: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8005B89C: beql        $a1, $at, L_8005B8FC
    if (ctx->r5 == ctx->r1) {
        // 0x8005B8A0: lw          $a0, 0x0($a3)
        ctx->r4 = MEM_W(ctx->r7, 0X0);
            goto L_8005B8FC;
    }
    goto skip_0;
    // 0x8005B8A0: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    skip_0:
    // 0x8005B8A4: b           L_8005B92C
    // 0x8005B8A8: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
        goto L_8005B92C;
    // 0x8005B8A8: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
L_8005B8AC:
    // 0x8005B8AC: lw          $v0, 0x40($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X40);
    // 0x8005B8B0: beql        $v0, $zero, L_8005B8C4
    if (ctx->r2 == 0) {
        // 0x8005B8B4: sw          $a2, 0x3C($a3)
        MEM_W(0X3C, ctx->r7) = ctx->r6;
            goto L_8005B8C4;
    }
    goto skip_1;
    // 0x8005B8B4: sw          $a2, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->r6;
    skip_1:
    // 0x8005B8B8: b           L_8005B8C4
    // 0x8005B8BC: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
        goto L_8005B8C4;
    // 0x8005B8BC: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x8005B8C0: sw          $a2, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->r6;
L_8005B8C4:
    // 0x8005B8C4: b           L_8005B940
    // 0x8005B8C8: sw          $a2, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r6;
        goto L_8005B940;
    // 0x8005B8C8: sw          $a2, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r6;
L_8005B8CC:
    // 0x8005B8CC: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x8005B8D0: sw          $v0, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->r2;
    // 0x8005B8D4: sw          $zero, 0x48($a3)
    MEM_W(0X48, ctx->r7) = 0;
    // 0x8005B8D8: beq         $a0, $zero, L_8005B940
    if (ctx->r4 == 0) {
        // 0x8005B8DC: sh          $v0, 0x1A($a3)
        MEM_H(0X1A, ctx->r7) = ctx->r2;
            goto L_8005B940;
    }
    // 0x8005B8DC: sh          $v0, 0x1A($a3)
    MEM_H(0X1A, ctx->r7) = ctx->r2;
    // 0x8005B8E0: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x8005B8E4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8005B8E8: jalr        $t9
    // 0x8005B8EC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8005B8EC: nop

    after_0:
    // 0x8005B8F0: b           L_8005B944
    // 0x8005B8F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8005B944;
    // 0x8005B8F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005B8F8: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
L_8005B8FC:
    // 0x8005B8FC: sw          $v0, 0x48($a3)
    MEM_W(0X48, ctx->r7) = ctx->r2;
    // 0x8005B900: beql        $a0, $zero, L_8005B944
    if (ctx->r4 == 0) {
        // 0x8005B904: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005B944;
    }
    goto skip_2;
    // 0x8005B904: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8005B908: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x8005B90C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x8005B910: jalr        $t9
    // 0x8005B914: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8005B914: nop

    after_1:
    // 0x8005B918: b           L_8005B944
    // 0x8005B91C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8005B944;
    // 0x8005B91C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005B920:
    // 0x8005B920: b           L_8005B940
    // 0x8005B924: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
        goto L_8005B940;
    // 0x8005B924: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
    // 0x8005B928: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
L_8005B92C:
    // 0x8005B92C: beql        $a0, $zero, L_8005B944
    if (ctx->r4 == 0) {
        // 0x8005B930: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005B944;
    }
    goto skip_3;
    // 0x8005B930: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8005B934: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x8005B938: jalr        $t9
    // 0x8005B93C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8005B93C: nop

    after_2:
L_8005B940:
    // 0x8005B940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005B944:
    // 0x8005B944: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005B948: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005B94C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005B954(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005B954: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x8005B958: bne         $a0, $zero, L_8005B988
    if (ctx->r4 != 0) {
        // 0x8005B95C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8005B988;
    }
    // 0x8005B95C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005B960: c.le.d      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.d <= ctx->f14.d;
    // 0x8005B964: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x8005B968: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005B96C: bc1f        L_8005B980
    if (!c1cs) {
        // 0x8005B970: nop
    
            goto L_8005B980;
    }
    // 0x8005B970: nop

    // 0x8005B974: sh          $t6, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r14;
    // 0x8005B978: b           L_8005BB14
    // 0x8005B97C: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
        goto L_8005BB14;
    // 0x8005B97C: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
L_8005B980:
    // 0x8005B980: b           L_8005BB14
    // 0x8005B984: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
        goto L_8005BB14;
    // 0x8005B984: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
L_8005B988:
    // 0x8005B988: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8005B98C: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x8005B990: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8005B994: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8005B998: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005B99C: c.lt.d      $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f14.d < ctx->f22.d;
    // 0x8005B9A0: addiu       $s2, $sp, 0x68
    ctx->r18 = ADD32(ctx->r29, 0X68);
    // 0x8005B9A4: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x8005B9A8: addiu       $t7, $t7, 0x4710
    ctx->r15 = ADD32(ctx->r15, 0X4710);
    // 0x8005B9AC: bc1f        L_8005B9B8
    if (!c1cs) {
        // 0x8005B9B0: or          $t6, $s2, $zero
        ctx->r14 = ctx->r18 | 0;
            goto L_8005B9B8;
    }
    // 0x8005B9B0: or          $t6, $s2, $zero
    ctx->r14 = ctx->r18 | 0;
    // 0x8005B9B4: mov.d       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.d = ctx->f22.d;
L_8005B9B8:
    // 0x8005B9B8: c.le.d      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.d <= ctx->f4.d;
    // 0x8005B9BC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8005B9C0: addiu       $t9, $t7, 0x3C
    ctx->r25 = ADD32(ctx->r15, 0X3C);
    // 0x8005B9C4: bc1f        L_8005B9D8
    if (!c1cs) {
        // 0x8005B9C8: nop
    
            goto L_8005B9D8;
    }
    // 0x8005B9C8: nop

    // 0x8005B9CC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8005B9D0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005B9D4: nop

L_8005B9D8:
    // 0x8005B9D8: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8005B9DC: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x8005B9E0: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8005B9E4: sw          $at, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r1;
    // 0x8005B9E8: lw          $at, -0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X8);
    // 0x8005B9EC: sw          $at, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r1;
    // 0x8005B9F0: lw          $at, -0x4($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X4);
    // 0x8005B9F4: bne         $t7, $t9, L_8005B9D8
    if (ctx->r15 != ctx->r25) {
        // 0x8005B9F8: sw          $at, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r1;
            goto L_8005B9D8;
    }
    // 0x8005B9F8: sw          $at, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r1;
    // 0x8005B9FC: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x8005BA00: lui         $t8, 0x4000
    ctx->r24 = S32(0X4000 << 16);
    // 0x8005BA04: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8005BA08: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x8005BA0C: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8005BA10: addiu       $a2, $sp, 0xB0
    ctx->r6 = ADD32(ctx->r29, 0XB0);
    // 0x8005BA14: cvt.d.w     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.d = CVT_D_W(ctx->f6.u32l);
    // 0x8005BA18: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8005BA1C: div.d       $f4, $f22, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = DIV_D(ctx->f22.d, ctx->f10.d);
    // 0x8005BA20: div.d       $f12, $f14, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f16.d); 
    ctx->f12.d = DIV_D(ctx->f14.d, ctx->f16.d);
    // 0x8005BA24: mul.d       $f2, $f4, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f20.d); 
    ctx->f2.d = MUL_D(ctx->f4.d, ctx->f20.d);
    // 0x8005BA28: trunc.w.d   $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = TRUNC_W_D(ctx->f2.d);
    // 0x8005BA2C: mfc1        $s0, $f6
    ctx->r16 = (int32_t)ctx->f6.u32l;
    // 0x8005BA30: jal         0x8005B788
    // 0x8005BA34: nop

    func_8005B788(rdram, ctx);
        goto after_0;
    // 0x8005BA34: nop

    after_0:
    // 0x8005BA38: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x8005BA3C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8005BA40: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x8005BA44: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8005BA48: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x8005BA4C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8005BA50: mul.d       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f2.d = MUL_D(ctx->f0.d, ctx->f10.d);
    // 0x8005BA54: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x8005BA58: ldc1        $f8, -0x68A0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X68A0);
    // 0x8005BA5C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8005BA60: trunc.w.d   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_D(ctx->f2.d);
    // 0x8005BA64: mov.d       $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    ctx->f2.d = ctx->f22.d;
    // 0x8005BA68: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8005BA6C: nop

    // 0x8005BA70: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8005BA74: addu        $t7, $s2, $t9
    ctx->r15 = ADD32(ctx->r18, ctx->r25);
    // 0x8005BA78: ldc1        $f6, -0x40($t7)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r15, -0X40);
    // 0x8005BA7C: add.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f6.d + ctx->f10.d;
    // 0x8005BA80: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005BA84: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8005BA88: mul.d       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f12.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x8005BA8C: nop

    // 0x8005BA90: mul.d       $f14, $f6, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f14.d = MUL_D(ctx->f6.d, ctx->f20.d);
    // 0x8005BA94: div.d       $f12, $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f14.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f14.d);
    // 0x8005BA98: beq         $s0, $zero, L_8005BAC0
    if (ctx->r16 == 0) {
        // 0x8005BA9C: add.d       $f0, $f22, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f22.d); NAN_CHECK(ctx->f12.d); 
    ctx->f0.d = ctx->f22.d + ctx->f12.d;
            goto L_8005BAC0;
    }
    // 0x8005BA9C: add.d       $f0, $f22, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f22.d); NAN_CHECK(ctx->f12.d); 
    ctx->f0.d = ctx->f22.d + ctx->f12.d;
L_8005BAA0:
    // 0x8005BAA0: andi        $t8, $s0, 0x1
    ctx->r24 = ctx->r16 & 0X1;
    // 0x8005BAA4: beq         $t8, $zero, L_8005BAB4
    if (ctx->r24 == 0) {
        // 0x8005BAA8: sra         $t9, $s0, 1
        ctx->r25 = S32(SIGNED(ctx->r16) >> 1);
            goto L_8005BAB4;
    }
    // 0x8005BAA8: sra         $t9, $s0, 1
    ctx->r25 = S32(SIGNED(ctx->r16) >> 1);
    // 0x8005BAAC: mul.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = MUL_D(ctx->f2.d, ctx->f0.d);
    // 0x8005BAB0: nop

L_8005BAB4:
    // 0x8005BAB4: mul.d       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f0.d);
    // 0x8005BAB8: bne         $t9, $zero, L_8005BAA0
    if (ctx->r25 != 0) {
        // 0x8005BABC: or          $s0, $t9, $zero
        ctx->r16 = ctx->r25 | 0;
            goto L_8005BAA0;
    }
    // 0x8005BABC: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
L_8005BAC0:
    // 0x8005BAC0: mul.d       $f0, $f2, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x8005BAC4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8005BAC8: mul.d       $f12, $f0, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f12.d = MUL_D(ctx->f0.d, ctx->f0.d);
    // 0x8005BACC: nop

    // 0x8005BAD0: mul.d       $f2, $f12, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f12.d); 
    ctx->f2.d = MUL_D(ctx->f12.d, ctx->f12.d);
    // 0x8005BAD4: trunc.w.d   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_D(ctx->f2.d);
    // 0x8005BAD8: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x8005BADC: nop

    // 0x8005BAE0: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x8005BAE4: sra         $v0, $t6, 16
    ctx->r2 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8005BAE8: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8005BAEC: nop

    // 0x8005BAF0: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005BAF4: ldc1        $f4, -0x6898($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X6898);
    // 0x8005BAF8: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8005BAFC: sub.d       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f2.d - ctx->f6.d;
    // 0x8005BB00: mul.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x8005BB04: trunc.w.d   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_D(ctx->f8.d);
    // 0x8005BB08: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8005BB0C: nop

    // 0x8005BB10: sh          $t7, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r15;
L_8005BB14:
    // 0x8005BB14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005BB18: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    // 0x8005BB1C: jr          $ra
    TRACE_RETURN()
    return;
;}
