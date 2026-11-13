#include "recomp.h"
#include "trace.h"
#include "funcs.h"

RECOMP_FUNC void func_8005D5E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005D5E8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8005D5EC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8005D5F0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8005D5F4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8005D5F8: ld          $t7, 0x8($sp)
    ctx->r15 = LD(ctx->r29, 0X8);
    // 0x8005D5FC: ld          $t6, 0x0($sp)
    ctx->r14 = LD(ctx->r29, 0X0);
    // 0x8005D600: dmultu      $t6, $t7
    DMULTU(U64(ctx->r14), U64(ctx->r15), &lo, &hi);
    // 0x8005D604: mflo        $v0
    ctx->r2 = lo;
    // 0x8005D608: dsll32      $v1, $v0, 0
    ctx->r3 = ctx->r2 << (0 + 32);
    // 0x8005D60C: dsra32      $v1, $v1, 0
    ctx->r3 = SIGNED(ctx->r3) >> (0 + 32);
    // 0x8005D610: jr          $ra
    // 0x8005D614: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    TRACE_RETURN()
    return;
    // 0x8005D614: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
;}
RECOMP_FUNC void func_8005D618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005D618: lh          $t7, 0x12($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X12);
    // 0x8005D61C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8005D620: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8005D624: ld          $t6, 0x8($sp)
    ctx->r14 = LD(ctx->r29, 0X8);
    // 0x8005D628: or          $t8, $t7, $zero
    ctx->r24 = ctx->r15 | 0;
    // 0x8005D62C: or          $t9, $t8, $zero
    ctx->r25 = ctx->r24 | 0;
    // 0x8005D630: ddivu       $zero, $t6, $t9
    DDIVU(U64(ctx->r14), U64(ctx->r25), &lo, &hi);
    // 0x8005D634: bne         $t9, $zero, L_8005D640
    if (ctx->r25 != 0) {
        // 0x8005D638: nop
    
            goto L_8005D640;
    }
    // 0x8005D638: nop

    // 0x8005D63C: break       7
    do_break(2147866172);
L_8005D640:
    // 0x8005D640: mflo        $t0
    ctx->r8 = lo;
    // 0x8005D644: sd          $t0, 0x0($a0)
    SD(ctx->r8, 0X0, ctx->r4);
    // 0x8005D648: lh          $t2, 0x12($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X12);
    // 0x8005D64C: ld          $t1, 0x8($sp)
    ctx->r9 = LD(ctx->r29, 0X8);
    // 0x8005D650: or          $t3, $t2, $zero
    ctx->r11 = ctx->r10 | 0;
    // 0x8005D654: or          $t4, $t3, $zero
    ctx->r12 = ctx->r11 | 0;
    // 0x8005D658: ddivu       $zero, $t1, $t4
    DDIVU(U64(ctx->r9), U64(ctx->r12), &lo, &hi);
    // 0x8005D65C: bne         $t4, $zero, L_8005D668
    if (ctx->r12 != 0) {
        // 0x8005D660: nop
    
            goto L_8005D668;
    }
    // 0x8005D660: nop

    // 0x8005D664: break       7
    do_break(2147866212);
L_8005D668:
    // 0x8005D668: mfhi        $t5
    ctx->r13 = hi;
    // 0x8005D66C: sd          $t5, 0x0($a1)
    SD(ctx->r13, 0X0, ctx->r5);
    // 0x8005D670: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005D678(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005D678: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8005D67C: sw          $a0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r4;
    // 0x8005D680: sw          $a1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r5;
    // 0x8005D684: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // 0x8005D688: sw          $a3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r7;
    // 0x8005D68C: ld          $t7, 0x10($sp)
    ctx->r15 = LD(ctx->r29, 0X10);
    // 0x8005D690: ld          $t6, 0x8($sp)
    ctx->r14 = LD(ctx->r29, 0X8);
    // 0x8005D694: ddiv        $zero, $t6, $t7
    DDIV(S64(ctx->r14), S64(ctx->r15), &lo, &hi);
    // 0x8005D698: nop

    // 0x8005D69C: bne         $t7, $zero, L_8005D6A8
    if (ctx->r15 != 0) {
        // 0x8005D6A0: nop
    
            goto L_8005D6A8;
    }
    // 0x8005D6A0: nop

    // 0x8005D6A4: break       7
    do_break(2147866276);
L_8005D6A8:
    // 0x8005D6A8: daddiu      $at, $zero, -0x1
    ctx->r1 = 0 + -0X1;
    // 0x8005D6AC: bne         $t7, $at, L_8005D6C4
    if (ctx->r15 != ctx->r1) {
        // 0x8005D6B0: daddiu      $at, $zero, 0x1
        ctx->r1 = 0 + 0X1;
            goto L_8005D6C4;
    }
    // 0x8005D6B0: daddiu      $at, $zero, 0x1
    ctx->r1 = 0 + 0X1;
    // 0x8005D6B4: dsll32      $at, $at, 31
    ctx->r1 = ctx->r1 << (31 + 32);
    // 0x8005D6B8: bne         $t6, $at, L_8005D6C4
    if (ctx->r14 != ctx->r1) {
        // 0x8005D6BC: nop
    
            goto L_8005D6C4;
    }
    // 0x8005D6BC: nop

    // 0x8005D6C0: break       6
    do_break(2147866304);
L_8005D6C4:
    // 0x8005D6C4: mfhi        $t8
    ctx->r24 = hi;
    // 0x8005D6C8: sd          $t8, 0x0($sp)
    SD(ctx->r24, 0X0, ctx->r29);
    // 0x8005D6CC: bgez        $t8, L_8005D6DC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8005D6D0: nop
    
            goto L_8005D6DC;
    }
    // 0x8005D6D0: nop

    // 0x8005D6D4: bgtz        $t7, L_8005D6F4
    if (SIGNED(ctx->r15) > 0) {
        // 0x8005D6D8: nop
    
            goto L_8005D6F4;
    }
    // 0x8005D6D8: nop

L_8005D6DC:
    // 0x8005D6DC: ld          $t9, 0x0($sp)
    ctx->r25 = LD(ctx->r29, 0X0);
    // 0x8005D6E0: blez        $t9, L_8005D704
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8005D6E4: nop
    
            goto L_8005D704;
    }
    // 0x8005D6E4: nop

    // 0x8005D6E8: ld          $t0, 0x10($sp)
    ctx->r8 = LD(ctx->r29, 0X10);
    // 0x8005D6EC: bgez        $t0, L_8005D704
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8005D6F0: nop
    
            goto L_8005D704;
    }
    // 0x8005D6F0: nop

L_8005D6F4:
    // 0x8005D6F4: ld          $t1, 0x0($sp)
    ctx->r9 = LD(ctx->r29, 0X0);
    // 0x8005D6F8: ld          $t2, 0x10($sp)
    ctx->r10 = LD(ctx->r29, 0X10);
    // 0x8005D6FC: daddu       $t3, $t1, $t2
    ctx->r11 = ctx->r9 + ctx->r10;
    // 0x8005D700: sd          $t3, 0x0($sp)
    SD(ctx->r11, 0X0, ctx->r29);
L_8005D704:
    // 0x8005D704: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x8005D708: lw          $v1, 0x4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4);
    // 0x8005D70C: jr          $ra
    // 0x8005D710: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    TRACE_RETURN()
    return;
    // 0x8005D710: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8005D714(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005D714: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8005D718: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8005D71C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8005D720: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8005D724: ld          $t7, 0x8($sp)
    ctx->r15 = LD(ctx->r29, 0X8);
    // 0x8005D728: ld          $t6, 0x0($sp)
    ctx->r14 = LD(ctx->r29, 0X0);
    // 0x8005D72C: dsrav       $v0, $t6, $t7
    ctx->r2 = SIGNED(ctx->r14) >> (ctx->r15 & 63);
    // 0x8005D730: dsll32      $v1, $v0, 0
    ctx->r3 = ctx->r2 << (0 + 32);
    // 0x8005D734: dsra32      $v1, $v1, 0
    ctx->r3 = SIGNED(ctx->r3) >> (0 + 32);
    // 0x8005D738: jr          $ra
    // 0x8005D73C: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    TRACE_RETURN()
    return;
    // 0x8005D73C: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
;}
RECOMP_FUNC void func_8005D740(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005D740: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005D744: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8005D748: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8005D74C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005D750: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8005D754: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8005D758: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x8005D75C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8005D760: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8005D764: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8005D768: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8005D76C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8005D770: sw          $t9, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r25;
    // 0x8005D774: sw          $t8, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r24;
    // 0x8005D778: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8005D77C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D780: bne         $t2, $zero, L_8005D790
    if (ctx->r10 != 0) {
        // 0x8005D784: nop
    
            goto L_8005D790;
    }
    // 0x8005D784: nop

    // 0x8005D788: beq         $t3, $zero, L_8005D7A0
    if (ctx->r11 == 0) {
        // 0x8005D78C: nop
    
            goto L_8005D7A0;
    }
    // 0x8005D78C: nop

L_8005D790:
    // 0x8005D790: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8005D794: sw          $t2, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r10;
    // 0x8005D798: b           L_8005D7B4
    // 0x8005D79C: sw          $t3, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r11;
        goto L_8005D7B4;
    // 0x8005D79C: sw          $t3, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r11;
L_8005D7A0:
    // 0x8005D7A0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8005D7A4: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8005D7A8: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8005D7AC: sw          $t4, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r12;
    // 0x8005D7B0: sw          $t5, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r13;
L_8005D7B4:
    // 0x8005D7B4: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8005D7B8: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8005D7BC: sw          $t7, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r15;
    // 0x8005D7C0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8005D7C4: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8005D7C8: sw          $t9, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r25;
    // 0x8005D7CC: jal         0x80060388
    // 0x8005D7D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    osSetTimer_recomp(rdram, ctx);
        goto after_0;
    // 0x8005D7D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x8005D7D4: lui         $t2, 0x8007
    ctx->r10 = S32(0X8007 << 16);
    // 0x8005D7D8: lw          $t2, 0x4770($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X4770);
    // 0x8005D7DC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8005D7E0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8005D7E4: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8005D7E8: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8005D7EC: bne         $t3, $t1, L_8005D800
    if (ctx->r11 != ctx->r9) {
        // 0x8005D7F0: nop
    
            goto L_8005D800;
    }
    // 0x8005D7F0: nop

    // 0x8005D7F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8005D7F8: jal         0x80060314
    // 0x8005D7FC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80060314(rdram, ctx);
        goto after_1;
    // 0x8005D7FC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
L_8005D800:
    // 0x8005D800: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005D804: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005D808: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005D80C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005D820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005D820: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8005D824: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005D828: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8005D82C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8005D830: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8005D834: jal         0x8005C8B0
    // 0x8005D838: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8005C8B0(rdram, ctx);
        goto after_0;
    // 0x8005D838: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8005D83C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8005D840: addiu       $a1, $a1, -0x2170
    ctx->r5 = ADD32(ctx->r5, -0X2170);
    // 0x8005D844: jal         0x8005CB40
    // 0x8005D848: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8005CB40(rdram, ctx);
        goto after_1;
    // 0x8005D848: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x8005D84C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8005D850: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8005D854: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8005D858: jal         0x8004F990
    // 0x8005D85C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x8005D85C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8005D860: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8005D864: addiu       $a1, $a1, -0x2170
    ctx->r5 = ADD32(ctx->r5, -0X2170);
    // 0x8005D868: jal         0x8005CB40
    // 0x8005D86C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8005CB40(rdram, ctx);
        goto after_3;
    // 0x8005D86C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x8005D870: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8005D874: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8005D878: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8005D87C: jal         0x8004F990
    // 0x8005D880: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x8005D880: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x8005D884: addiu       $a0, $sp, 0x2F
    ctx->r4 = ADD32(ctx->r29, 0X2F);
    // 0x8005D888: jal         0x8005C9AC
    // 0x8005D88C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8005C9AC(rdram, ctx);
        goto after_5;
    // 0x8005D88C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_5:
    // 0x8005D890: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8005D894: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8005D898: addu        $t8, $sp, $t7
    ctx->r24 = ADD32(ctx->r29, ctx->r15);
    // 0x8005D89C: lbu         $t8, 0x1E($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X1E);
    // 0x8005D8A0: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8005D8A4: beq         $t9, $zero, L_8005D8C0
    if (ctx->r25 == 0) {
        // 0x8005D8A8: nop
    
            goto L_8005D8C0;
    }
    // 0x8005D8A8: nop

    // 0x8005D8AC: andi        $t0, $t8, 0x2
    ctx->r8 = ctx->r24 & 0X2;
    // 0x8005D8B0: beq         $t0, $zero, L_8005D8C0
    if (ctx->r8 == 0) {
        // 0x8005D8B4: nop
    
            goto L_8005D8C0;
    }
    // 0x8005D8B4: nop

    // 0x8005D8B8: b           L_8005D91C
    // 0x8005D8BC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8005D91C;
    // 0x8005D8BC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8005D8C0:
    // 0x8005D8C0: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8005D8C4: addiu       $t3, $sp, 0x1C
    ctx->r11 = ADD32(ctx->r29, 0X1C);
    // 0x8005D8C8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8005D8CC: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8005D8D0: lbu         $t5, 0x3($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X3);
    // 0x8005D8D4: bne         $t5, $zero, L_8005D8EC
    if (ctx->r13 != 0) {
        // 0x8005D8D8: nop
    
            goto L_8005D8EC;
    }
    // 0x8005D8D8: nop

    // 0x8005D8DC: lbu         $t6, 0x2($t4)
    ctx->r14 = MEM_BU(ctx->r12, 0X2);
    // 0x8005D8E0: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8005D8E4: bne         $t7, $zero, L_8005D8F4
    if (ctx->r15 != 0) {
        // 0x8005D8E8: nop
    
            goto L_8005D8F4;
    }
    // 0x8005D8E8: nop

L_8005D8EC:
    // 0x8005D8EC: b           L_8005D91C
    // 0x8005D8F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8005D91C;
    // 0x8005D8F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005D8F4:
    // 0x8005D8F4: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8005D8F8: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8005D8FC: addu        $t0, $sp, $t8
    ctx->r8 = ADD32(ctx->r29, ctx->r24);
    // 0x8005D900: lbu         $t0, 0x1E($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X1E);
    // 0x8005D904: andi        $t1, $t0, 0x4
    ctx->r9 = ctx->r8 & 0X4;
    // 0x8005D908: beq         $t1, $zero, L_8005D918
    if (ctx->r9 == 0) {
        // 0x8005D90C: nop
    
            goto L_8005D918;
    }
    // 0x8005D90C: nop

    // 0x8005D910: b           L_8005D91C
    // 0x8005D914: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_8005D91C;
    // 0x8005D914: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8005D918:
    // 0x8005D918: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
L_8005D91C:
    // 0x8005D91C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005D920: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8005D924: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005D930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005D930: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8005D934: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
    // 0x8005D938: sw          $a0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r4;
    // 0x8005D93C: blez        $a1, L_8005D980
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8005D940: sw          $zero, 0xC($sp)
        MEM_W(0XC, ctx->r29) = 0;
            goto L_8005D980;
    }
    // 0x8005D940: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
L_8005D944:
    // 0x8005D944: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8005D948: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x8005D94C: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x8005D950: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x8005D954: addiu       $t0, $t7, 0x1
    ctx->r8 = ADD32(ctx->r15, 0X1);
    // 0x8005D958: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005D95C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8005D960: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x8005D964: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x8005D968: slt         $at, $t4, $a1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8005D96C: sw          $t4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r12;
    // 0x8005D970: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x8005D974: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x8005D978: bne         $at, $zero, L_8005D944
    if (ctx->r1 != 0) {
        // 0x8005D97C: sw          $t2, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r10;
            goto L_8005D944;
    }
    // 0x8005D97C: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
L_8005D980:
    // 0x8005D980: lhu         $v0, 0xA($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0XA);
    // 0x8005D984: jr          $ra
    // 0x8005D988: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    TRACE_RETURN()
    return;
    // 0x8005D988: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8005D98C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005D98C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8005D990: sh          $zero, 0x6($sp)
    MEM_H(0X6, ctx->r29) = 0;
    // 0x8005D994: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
    // 0x8005D998: lhu         $t6, 0x0($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X0);
    // 0x8005D99C: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x8005D9A0: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_8005D9A4:
    // 0x8005D9A4: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x8005D9A8: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x8005D9AC: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x8005D9B0: sh          $t9, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r25;
    // 0x8005D9B4: lhu         $t0, 0x0($a1)
    ctx->r8 = MEM_HU(ctx->r5, 0X0);
    // 0x8005D9B8: addu        $t1, $t0, $t9
    ctx->r9 = ADD32(ctx->r8, ctx->r25);
    // 0x8005D9BC: sh          $t1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r9;
    // 0x8005D9C0: lhu         $t3, 0x6($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X6);
    // 0x8005D9C4: lhu         $t2, 0x0($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X0);
    // 0x8005D9C8: nor         $t4, $t3, $zero
    ctx->r12 = ~(ctx->r11 | 0);
    // 0x8005D9CC: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8005D9D0: sh          $t5, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r13;
    // 0x8005D9D4: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x8005D9D8: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x8005D9DC: sltiu       $at, $t7, 0x1C
    ctx->r1 = ctx->r15 < 0X1C ? 1 : 0;
    // 0x8005D9E0: bne         $at, $zero, L_8005D9A4
    if (ctx->r1 != 0) {
        // 0x8005D9E4: sw          $t7, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r15;
            goto L_8005D9A4;
    }
    // 0x8005D9E4: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x8005D9E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005D9EC: jr          $ra
    // 0x8005D9F0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    TRACE_RETURN()
    return;
    // 0x8005D9F0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8005D9F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005D9F4: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8005D9F8: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x8005D9FC: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x8005DA00: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005DA04: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x8005DA08: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x8005DA0C: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    // 0x8005DA10: sb          $zero, 0x33($sp)
    MEM_B(0X33, ctx->r29) = 0;
    // 0x8005DA14: lbu         $t7, 0x65($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X65);
    // 0x8005DA18: beq         $t7, $zero, L_8005DA44
    if (ctx->r15 == 0) {
        // 0x8005DA1C: nop
    
            goto L_8005DA44;
    }
    // 0x8005DA1C: nop

    // 0x8005DA20: sb          $zero, 0x65($t6)
    MEM_B(0X65, ctx->r14) = 0;
    // 0x8005DA24: jal         0x8005E61C
    // 0x8005DA28: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    func_8005E61C(rdram, ctx);
        goto after_0;
    // 0x8005DA28: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    after_0:
    // 0x8005DA2C: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x8005DA30: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x8005DA34: beq         $t8, $zero, L_8005DA44
    if (ctx->r24 == 0) {
        // 0x8005DA38: nop
    
            goto L_8005DA44;
    }
    // 0x8005DA38: nop

    // 0x8005DA3C: b           L_8005DDFC
    // 0x8005DA40: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_8005DDFC;
    // 0x8005DA40: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8005DA44:
    // 0x8005DA44: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x8005DA48: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8005DA4C: jal         0x80060100
    // 0x8005DA50: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    osGetCount_recomp(rdram, ctx);
        goto after_1;
    // 0x8005DA50: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    after_1:
    // 0x8005DA54: lw          $t1, 0x80($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X80);
    // 0x8005DA58: sw          $v0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r2;
    // 0x8005DA5C: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x8005DA60: lw          $t3, 0x80($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X80);
    // 0x8005DA64: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x8005DA68: lw          $t5, 0xC($t2)
    ctx->r13 = MEM_W(ctx->r10, 0XC);
    // 0x8005DA6C: sw          $t4, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r12;
    // 0x8005DA70: sw          $t5, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r13;
    // 0x8005DA74: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x8005DA78: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x8005DA7C: lw          $t6, 0x10($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X10);
    // 0x8005DA80: lw          $t7, 0x14($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X14);
    // 0x8005DA84: sw          $t6, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r14;
    // 0x8005DA88: sw          $t7, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r15;
    // 0x8005DA8C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
L_8005DA90:
    // 0x8005DA90: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8005DA94: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x8005DA98: sb          $t9, 0x65($t0)
    MEM_B(0X65, ctx->r8) = ctx->r25;
    // 0x8005DA9C: jal         0x8005E61C
    // 0x8005DAA0: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    func_8005E61C(rdram, ctx);
        goto after_2;
    // 0x8005DAA0: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    after_2:
    // 0x8005DAA4: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x8005DAA8: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
    // 0x8005DAAC: beq         $t1, $zero, L_8005DABC
    if (ctx->r9 == 0) {
        // 0x8005DAB0: nop
    
            goto L_8005DABC;
    }
    // 0x8005DAB0: nop

    // 0x8005DAB4: b           L_8005DDFC
    // 0x8005DAB8: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_8005DDFC;
    // 0x8005DAB8: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_8005DABC:
    // 0x8005DABC: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x8005DAC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005DAC4: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    // 0x8005DAC8: lw          $a0, 0x4($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X4);
    // 0x8005DACC: jal         0x8005D0F0
    // 0x8005DAD0: lw          $a1, 0x8($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X8);
    func_8005D0F0(rdram, ctx);
        goto after_3;
    // 0x8005DAD0: lw          $a1, 0x8($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X8);
    after_3:
    // 0x8005DAD4: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x8005DAD8: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x8005DADC: beq         $t4, $zero, L_8005DAEC
    if (ctx->r12 == 0) {
        // 0x8005DAE0: nop
    
            goto L_8005DAEC;
    }
    // 0x8005DAE0: nop

    // 0x8005DAE4: b           L_8005DDFC
    // 0x8005DAE8: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
        goto L_8005DDFC;
    // 0x8005DAE8: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
L_8005DAEC:
    // 0x8005DAEC: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8005DAF0: addiu       $t6, $sp, 0x54
    ctx->r14 = ADD32(ctx->r29, 0X54);
    // 0x8005DAF4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005DAF8: ori         $t3, $t5, 0x80
    ctx->r11 = ctx->r13 | 0X80;
    // 0x8005DAFC: sb          $t3, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r11;
    // 0x8005DB00: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
L_8005DB04:
    // 0x8005DB04: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8005DB08: addiu       $t9, $sp, 0x54
    ctx->r25 = ADD32(ctx->r29, 0X54);
    // 0x8005DB0C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8005DB10: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x8005DB14: nor         $t2, $t1, $zero
    ctx->r10 = ~(ctx->r9 | 0);
    // 0x8005DB18: sb          $t2, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r10;
    // 0x8005DB1C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8005DB20: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8005DB24: slti        $at, $t5, 0x20
    ctx->r1 = SIGNED(ctx->r13) < 0X20 ? 1 : 0;
    // 0x8005DB28: bne         $at, $zero, L_8005DB04
    if (ctx->r1 != 0) {
        // 0x8005DB2C: sw          $t5, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r13;
            goto L_8005DB04;
    }
    // 0x8005DB2C: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x8005DB30: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x8005DB34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005DB38: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    // 0x8005DB3C: lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X4);
    // 0x8005DB40: lw          $a1, 0x8($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X8);
    // 0x8005DB44: jal         0x8005CD70
    // 0x8005DB48: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8005CD70(rdram, ctx);
        goto after_4;
    // 0x8005DB48: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x8005DB4C: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x8005DB50: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x8005DB54: beq         $t6, $zero, L_8005DB64
    if (ctx->r14 == 0) {
        // 0x8005DB58: nop
    
            goto L_8005DB64;
    }
    // 0x8005DB58: nop

    // 0x8005DB5C: b           L_8005DDFC
    // 0x8005DB60: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8005DDFC;
    // 0x8005DB60: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_8005DB64:
    // 0x8005DB64: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x8005DB68: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005DB6C: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    // 0x8005DB70: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    // 0x8005DB74: jal         0x8005D0F0
    // 0x8005DB78: lw          $a1, 0x8($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X8);
    func_8005D0F0(rdram, ctx);
        goto after_5;
    // 0x8005DB78: lw          $a1, 0x8($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X8);
    after_5:
    // 0x8005DB7C: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x8005DB80: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x8005DB84: beq         $t8, $zero, L_8005DB94
    if (ctx->r24 == 0) {
        // 0x8005DB88: nop
    
            goto L_8005DB94;
    }
    // 0x8005DB88: nop

    // 0x8005DB8C: b           L_8005DDFC
    // 0x8005DB90: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_8005DDFC;
    // 0x8005DB90: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8005DB94:
    // 0x8005DB94: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8005DB98:
    // 0x8005DB98: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8005DB9C: addu        $t1, $sp, $t9
    ctx->r9 = ADD32(ctx->r29, ctx->r25);
    // 0x8005DBA0: addu        $t2, $sp, $t9
    ctx->r10 = ADD32(ctx->r29, ctx->r25);
    // 0x8005DBA4: lbu         $t2, 0x34($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X34);
    // 0x8005DBA8: lbu         $t1, 0x54($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X54);
    // 0x8005DBAC: bne         $t1, $t2, L_8005DBC8
    if (ctx->r9 != ctx->r10) {
        // 0x8005DBB0: nop
    
            goto L_8005DBC8;
    }
    // 0x8005DBB0: nop

    // 0x8005DBB4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8005DBB8: addiu       $t4, $t0, 0x1
    ctx->r12 = ADD32(ctx->r8, 0X1);
    // 0x8005DBBC: slti        $at, $t4, 0x20
    ctx->r1 = SIGNED(ctx->r12) < 0X20 ? 1 : 0;
    // 0x8005DBC0: bne         $at, $zero, L_8005DB98
    if (ctx->r1 != 0) {
        // 0x8005DBC4: sw          $t4, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r12;
            goto L_8005DB98;
    }
    // 0x8005DBC4: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
L_8005DBC8:
    // 0x8005DBC8: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8005DBCC: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x8005DBD0: bne         $t5, $at, L_8005DC6C
    if (ctx->r13 != ctx->r1) {
        // 0x8005DBD4: nop
    
            goto L_8005DC6C;
    }
    // 0x8005DBD4: nop

    // 0x8005DBD8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8005DBDC: blez        $t3, L_8005DC50
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8005DBE0: nop
    
            goto L_8005DC50;
    }
    // 0x8005DBE0: nop

    // 0x8005DBE4: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x8005DBE8: sb          $zero, 0x65($t6)
    MEM_B(0X65, ctx->r14) = 0;
    // 0x8005DBEC: jal         0x8005E61C
    // 0x8005DBF0: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    func_8005E61C(rdram, ctx);
        goto after_6;
    // 0x8005DBF0: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    after_6:
    // 0x8005DBF4: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x8005DBF8: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x8005DBFC: beq         $t7, $zero, L_8005DC0C
    if (ctx->r15 == 0) {
        // 0x8005DC00: nop
    
            goto L_8005DC0C;
    }
    // 0x8005DC00: nop

    // 0x8005DC04: b           L_8005DDFC
    // 0x8005DC08: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_8005DDFC;
    // 0x8005DC08: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8005DC0C:
    // 0x8005DC0C: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x8005DC10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005DC14: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    // 0x8005DC18: lw          $a0, 0x4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X4);
    // 0x8005DC1C: jal         0x8005D0F0
    // 0x8005DC20: lw          $a1, 0x8($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X8);
    func_8005D0F0(rdram, ctx);
        goto after_7;
    // 0x8005DC20: lw          $a1, 0x8($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X8);
    after_7:
    // 0x8005DC24: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x8005DC28: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x8005DC2C: beq         $t9, $zero, L_8005DC3C
    if (ctx->r25 == 0) {
        // 0x8005DC30: nop
    
            goto L_8005DC3C;
    }
    // 0x8005DC30: nop

    // 0x8005DC34: b           L_8005DDFC
    // 0x8005DC38: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_8005DDFC;
    // 0x8005DC38: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8005DC3C:
    // 0x8005DC3C: addiu       $t1, $sp, 0x54
    ctx->r9 = ADD32(ctx->r29, 0X54);
    // 0x8005DC40: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x8005DC44: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x8005DC48: bne         $t2, $at, L_8005DC6C
    if (ctx->r10 != ctx->r1) {
        // 0x8005DC4C: nop
    
            goto L_8005DC6C;
    }
    // 0x8005DC4C: nop

L_8005DC50:
    // 0x8005DC50: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8005DC54: addiu       $t4, $t0, 0x1
    ctx->r12 = ADD32(ctx->r8, 0X1);
    // 0x8005DC58: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x8005DC5C: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8005DC60: slti        $at, $t5, 0x3E
    ctx->r1 = SIGNED(ctx->r13) < 0X3E ? 1 : 0;
    // 0x8005DC64: bne         $at, $zero, L_8005DA90
    if (ctx->r1 != 0) {
        // 0x8005DC68: nop
    
            goto L_8005DA90;
    }
    // 0x8005DC68: nop

L_8005DC6C:
    // 0x8005DC6C: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x8005DC70: sb          $zero, 0x65($t3)
    MEM_B(0X65, ctx->r11) = 0;
    // 0x8005DC74: jal         0x8005E61C
    // 0x8005DC78: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    func_8005E61C(rdram, ctx);
        goto after_8;
    // 0x8005DC78: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    after_8:
    // 0x8005DC7C: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x8005DC80: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x8005DC84: beq         $t6, $zero, L_8005DC94
    if (ctx->r14 == 0) {
        // 0x8005DC88: nop
    
            goto L_8005DC94;
    }
    // 0x8005DC88: nop

    // 0x8005DC8C: b           L_8005DDFC
    // 0x8005DC90: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8005DDFC;
    // 0x8005DC90: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_8005DC94:
    // 0x8005DC94: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8005DC98: blez        $t7, L_8005DCAC
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8005DC9C: nop
    
            goto L_8005DCAC;
    }
    // 0x8005DC9C: nop

    // 0x8005DCA0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8005DCA4: b           L_8005DCB0
    // 0x8005DCA8: sb          $t8, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r24;
        goto L_8005DCB0;
    // 0x8005DCA8: sb          $t8, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r24;
L_8005DCAC:
    // 0x8005DCAC: sb          $zero, 0x33($sp)
    MEM_B(0X33, ctx->r29) = 0;
L_8005DCB0:
    // 0x8005DCB0: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x8005DCB4: lbu         $t0, 0x33($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X33);
    // 0x8005DCB8: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
    // 0x8005DCBC: lhu         $t1, 0x18($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X18);
    // 0x8005DCC0: andi        $t2, $t1, 0xFFFE
    ctx->r10 = ctx->r9 & 0XFFFE;
    // 0x8005DCC4: or          $t4, $t2, $t0
    ctx->r12 = ctx->r10 | ctx->r8;
    // 0x8005DCC8: sh          $t4, 0x18($t5)
    MEM_H(0X18, ctx->r13) = ctx->r12;
    // 0x8005DCCC: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x8005DCD0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8005DCD4: sb          $t3, 0x1A($t6)
    MEM_B(0X1A, ctx->r14) = ctx->r11;
    // 0x8005DCD8: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x8005DCDC: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x8005DCE0: lbu         $t8, 0x1B($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X1B);
    // 0x8005DCE4: sb          $t8, 0x1B($t9)
    MEM_B(0X1B, ctx->r25) = ctx->r24;
    // 0x8005DCE8: lw          $t1, 0x80($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X80);
    // 0x8005DCEC: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x8005DCF0: addiu       $a1, $t1, 0x1C
    ctx->r5 = ADD32(ctx->r9, 0X1C);
    // 0x8005DCF4: jal         0x8005D98C
    // 0x8005DCF8: addiu       $a2, $t1, 0x1E
    ctx->r6 = ADD32(ctx->r9, 0X1E);
    func_8005D98C(rdram, ctx);
        goto after_9;
    // 0x8005DCF8: addiu       $a2, $t1, 0x1E
    ctx->r6 = ADD32(ctx->r9, 0X1E);
    after_9:
    // 0x8005DCFC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8005DD00: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
    // 0x8005DD04: sh          $t2, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r10;
    // 0x8005DD08: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8005DD0C: addiu       $t5, $sp, 0x20
    ctx->r13 = ADD32(ctx->r29, 0X20);
    // 0x8005DD10: sh          $t4, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r12;
    // 0x8005DD14: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8005DD18: addiu       $t6, $sp, 0x20
    ctx->r14 = ADD32(ctx->r29, 0X20);
    // 0x8005DD1C: sh          $t3, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r11;
    // 0x8005DD20: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x8005DD24: addiu       $t8, $sp, 0x20
    ctx->r24 = ADD32(ctx->r29, 0X20);
    // 0x8005DD28: sh          $t7, 0x6($t8)
    MEM_H(0X6, ctx->r24) = ctx->r15;
    // 0x8005DD2C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8005DD30:
    // 0x8005DD30: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8005DD34: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x8005DD38: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8005DD3C: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8005DD40: addu        $a2, $sp, $t2
    ctx->r6 = ADD32(ctx->r29, ctx->r10);
    // 0x8005DD44: lhu         $a2, 0x20($a2)
    ctx->r6 = MEM_HU(ctx->r6, 0X20);
    // 0x8005DD48: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x8005DD4C: lw          $a1, 0x8($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X8);
    // 0x8005DD50: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8005DD54: jal         0x8005CD70
    // 0x8005DD58: lw          $a3, 0x80($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X80);
    func_8005CD70(rdram, ctx);
        goto after_10;
    // 0x8005DD58: lw          $a3, 0x80($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X80);
    after_10:
    // 0x8005DD5C: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x8005DD60: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x8005DD64: beq         $t4, $zero, L_8005DD74
    if (ctx->r12 == 0) {
        // 0x8005DD68: nop
    
            goto L_8005DD74;
    }
    // 0x8005DD68: nop

    // 0x8005DD6C: b           L_8005DDFC
    // 0x8005DD70: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
        goto L_8005DDFC;
    // 0x8005DD70: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
L_8005DD74:
    // 0x8005DD74: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8005DD78: addiu       $t3, $t5, 0x1
    ctx->r11 = ADD32(ctx->r13, 0X1);
    // 0x8005DD7C: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x8005DD80: bne         $at, $zero, L_8005DD30
    if (ctx->r1 != 0) {
        // 0x8005DD84: sw          $t3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r11;
            goto L_8005DD30;
    }
    // 0x8005DD84: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x8005DD88: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x8005DD8C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005DD90: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    // 0x8005DD94: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    // 0x8005DD98: jal         0x8005D0F0
    // 0x8005DD9C: lw          $a1, 0x8($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X8);
    func_8005D0F0(rdram, ctx);
        goto after_11;
    // 0x8005DD9C: lw          $a1, 0x8($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X8);
    after_11:
    // 0x8005DDA0: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x8005DDA4: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x8005DDA8: beq         $t7, $zero, L_8005DDB8
    if (ctx->r15 == 0) {
        // 0x8005DDAC: nop
    
            goto L_8005DDB8;
    }
    // 0x8005DDAC: nop

    // 0x8005DDB0: b           L_8005DDFC
    // 0x8005DDB4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_8005DDFC;
    // 0x8005DDB4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8005DDB8:
    // 0x8005DDB8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8005DDBC:
    // 0x8005DDBC: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8005DDC0: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x8005DDC4: addu        $t0, $sp, $t9
    ctx->r8 = ADD32(ctx->r29, ctx->r25);
    // 0x8005DDC8: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x8005DDCC: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x8005DDD0: lbu         $t0, 0x54($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X54);
    // 0x8005DDD4: beq         $t2, $t0, L_8005DDE4
    if (ctx->r10 == ctx->r8) {
        // 0x8005DDD8: nop
    
            goto L_8005DDE4;
    }
    // 0x8005DDD8: nop

    // 0x8005DDDC: b           L_8005DDFC
    // 0x8005DDE0: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_8005DDFC;
    // 0x8005DDE0: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_8005DDE4:
    // 0x8005DDE4: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8005DDE8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8005DDEC: slti        $at, $t5, 0x20
    ctx->r1 = SIGNED(ctx->r13) < 0X20 ? 1 : 0;
    // 0x8005DDF0: bne         $at, $zero, L_8005DDBC
    if (ctx->r1 != 0) {
        // 0x8005DDF4: sw          $t5, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r13;
            goto L_8005DDBC;
    }
    // 0x8005DDF4: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x8005DDF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005DDFC:
    // 0x8005DDFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005DE00: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x8005DE04: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005DE0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005DE0C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8005DE10: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8005DE14: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8005DE18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005DE1C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8005DE20: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8005DE24: lbu         $t7, 0x65($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X65);
    // 0x8005DE28: beq         $t7, $zero, L_8005DE54
    if (ctx->r15 == 0) {
        // 0x8005DE2C: nop
    
            goto L_8005DE54;
    }
    // 0x8005DE2C: nop

    // 0x8005DE30: sb          $zero, 0x65($t6)
    MEM_B(0X65, ctx->r14) = 0;
    // 0x8005DE34: jal         0x8005E61C
    // 0x8005DE38: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_8005E61C(rdram, ctx);
        goto after_0;
    // 0x8005DE38: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_0:
    // 0x8005DE3C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8005DE40: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8005DE44: beq         $t8, $zero, L_8005DE54
    if (ctx->r24 == 0) {
        // 0x8005DE48: nop
    
            goto L_8005DE54;
    }
    // 0x8005DE48: nop

    // 0x8005DE4C: b           L_8005DF94
    // 0x8005DE50: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_8005DF94;
    // 0x8005DE50: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8005DE54:
    // 0x8005DE54: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8005DE58: addiu       $t0, $sp, 0x30
    ctx->r8 = ADD32(ctx->r29, 0X30);
    // 0x8005DE5C: sh          $t9, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r25;
    // 0x8005DE60: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8005DE64: addiu       $t2, $sp, 0x30
    ctx->r10 = ADD32(ctx->r29, 0X30);
    // 0x8005DE68: sh          $t1, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r9;
    // 0x8005DE6C: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8005DE70: addiu       $t4, $sp, 0x30
    ctx->r12 = ADD32(ctx->r29, 0X30);
    // 0x8005DE74: sh          $t3, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r11;
    // 0x8005DE78: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x8005DE7C: addiu       $t7, $sp, 0x30
    ctx->r15 = ADD32(ctx->r29, 0X30);
    // 0x8005DE80: sh          $t5, 0x6($t7)
    MEM_H(0X6, ctx->r15) = ctx->r13;
    // 0x8005DE84: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005DE88: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_8005DE8C:
    // 0x8005DE8C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8005DE90: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8005DE94: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8005DE98: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8005DE9C: addu        $a2, $sp, $t0
    ctx->r6 = ADD32(ctx->r29, ctx->r8);
    // 0x8005DEA0: lhu         $a2, 0x30($a2)
    ctx->r6 = MEM_HU(ctx->r6, 0X30);
    // 0x8005DEA4: lw          $a0, 0x4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X4);
    // 0x8005DEA8: jal         0x8005D0F0
    // 0x8005DEAC: lw          $a1, 0x8($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X8);
    func_8005D0F0(rdram, ctx);
        goto after_1;
    // 0x8005DEAC: lw          $a1, 0x8($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X8);
    after_1:
    // 0x8005DEB0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8005DEB4: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8005DEB8: beq         $t1, $zero, L_8005DEC8
    if (ctx->r9 == 0) {
        // 0x8005DEBC: nop
    
            goto L_8005DEC8;
    }
    // 0x8005DEBC: nop

    // 0x8005DEC0: b           L_8005DF94
    // 0x8005DEC4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_8005DF94;
    // 0x8005DEC4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_8005DEC8:
    // 0x8005DEC8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8005DECC: addiu       $a1, $sp, 0x2A
    ctx->r5 = ADD32(ctx->r29, 0X2A);
    // 0x8005DED0: jal         0x8005D98C
    // 0x8005DED4: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    func_8005D98C(rdram, ctx);
        goto after_2;
    // 0x8005DED4: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x8005DED8: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8005DEDC: lhu         $t4, 0x2A($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X2A);
    // 0x8005DEE0: lhu         $t3, 0x1C($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X1C);
    // 0x8005DEE4: bne         $t3, $t4, L_8005DEFC
    if (ctx->r11 != ctx->r12) {
        // 0x8005DEE8: nop
    
            goto L_8005DEFC;
    }
    // 0x8005DEE8: nop

    // 0x8005DEEC: lhu         $t5, 0x1E($t2)
    ctx->r13 = MEM_HU(ctx->r10, 0X1E);
    // 0x8005DEF0: lhu         $t7, 0x28($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X28);
    // 0x8005DEF4: beq         $t5, $t7, L_8005DF10
    if (ctx->r13 == ctx->r15) {
        // 0x8005DEF8: nop
    
            goto L_8005DF10;
    }
    // 0x8005DEF8: nop

L_8005DEFC:
    // 0x8005DEFC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8005DF00: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x8005DF04: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x8005DF08: bne         $at, $zero, L_8005DE8C
    if (ctx->r1 != 0) {
        // 0x8005DF0C: sw          $t8, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r24;
            goto L_8005DE8C;
    }
    // 0x8005DF0C: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_8005DF10:
    // 0x8005DF10: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8005DF14: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005DF18: bne         $t9, $at, L_8005DF28
    if (ctx->r25 != ctx->r1) {
        // 0x8005DF1C: nop
    
            goto L_8005DF28;
    }
    // 0x8005DF1C: nop

    // 0x8005DF20: b           L_8005DF94
    // 0x8005DF24: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_8005DF94;
    // 0x8005DF24: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_8005DF28:
    // 0x8005DF28: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_8005DF2C:
    // 0x8005DF2C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8005DF30: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8005DF34: beq         $t0, $t1, L_8005DF7C
    if (ctx->r8 == ctx->r9) {
        // 0x8005DF38: nop
    
            goto L_8005DF7C;
    }
    // 0x8005DF38: nop

    // 0x8005DF3C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8005DF40: sll         $t4, $t0, 1
    ctx->r12 = S32(ctx->r8 << 1);
    // 0x8005DF44: addu        $a2, $sp, $t4
    ctx->r6 = ADD32(ctx->r29, ctx->r12);
    // 0x8005DF48: lhu         $a2, 0x30($a2)
    ctx->r6 = MEM_HU(ctx->r6, 0X30);
    // 0x8005DF4C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8005DF50: lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X4);
    // 0x8005DF54: lw          $a1, 0x8($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X8);
    // 0x8005DF58: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8005DF5C: jal         0x8005CD70
    // 0x8005DF60: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    func_8005CD70(rdram, ctx);
        goto after_3;
    // 0x8005DF60: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    after_3:
    // 0x8005DF64: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8005DF68: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8005DF6C: beq         $t5, $zero, L_8005DF7C
    if (ctx->r13 == 0) {
        // 0x8005DF70: nop
    
            goto L_8005DF7C;
    }
    // 0x8005DF70: nop

    // 0x8005DF74: b           L_8005DF94
    // 0x8005DF78: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_8005DF94;
    // 0x8005DF78: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_8005DF7C:
    // 0x8005DF7C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8005DF80: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x8005DF84: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x8005DF88: bne         $at, $zero, L_8005DF2C
    if (ctx->r1 != 0) {
        // 0x8005DF8C: sw          $t6, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r14;
            goto L_8005DF2C;
    }
    // 0x8005DF8C: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8005DF90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005DF94:
    // 0x8005DF94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005DF98: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8005DF9C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005DFA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005DFA4: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8005DFA8: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x8005DFAC: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x8005DFB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005DFB4: lbu         $t7, 0x65($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X65);
    // 0x8005DFB8: beq         $t7, $zero, L_8005DFE4
    if (ctx->r15 == 0) {
        // 0x8005DFBC: nop
    
            goto L_8005DFE4;
    }
    // 0x8005DFBC: nop

    // 0x8005DFC0: sb          $zero, 0x65($t6)
    MEM_B(0X65, ctx->r14) = 0;
    // 0x8005DFC4: jal         0x8005E61C
    // 0x8005DFC8: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    func_8005E61C(rdram, ctx);
        goto after_0;
    // 0x8005DFC8: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    after_0:
    // 0x8005DFCC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8005DFD0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8005DFD4: beq         $t8, $zero, L_8005DFE4
    if (ctx->r24 == 0) {
        // 0x8005DFD8: nop
    
            goto L_8005DFE4;
    }
    // 0x8005DFD8: nop

    // 0x8005DFDC: b           L_8005E1F0
    // 0x8005DFE0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_8005E1F0;
    // 0x8005DFE0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8005DFE4:
    // 0x8005DFE4: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x8005DFE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005DFEC: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x8005DFF0: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x8005DFF4: jal         0x8005D0F0
    // 0x8005DFF8: lw          $a1, 0x8($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X8);
    func_8005D0F0(rdram, ctx);
        goto after_1;
    // 0x8005DFF8: lw          $a1, 0x8($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X8);
    after_1:
    // 0x8005DFFC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8005E000: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8005E004: beq         $t0, $zero, L_8005E014
    if (ctx->r8 == 0) {
        // 0x8005E008: nop
    
            goto L_8005E014;
    }
    // 0x8005E008: nop

    // 0x8005E00C: b           L_8005E1F0
    // 0x8005E010: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_8005E1F0;
    // 0x8005E010: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8005E014:
    // 0x8005E014: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8005E018: addiu       $a1, $sp, 0x62
    ctx->r5 = ADD32(ctx->r29, 0X62);
    // 0x8005E01C: jal         0x8005D98C
    // 0x8005E020: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    func_8005D98C(rdram, ctx);
        goto after_2;
    // 0x8005E020: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    after_2:
    // 0x8005E024: addiu       $t1, $sp, 0x40
    ctx->r9 = ADD32(ctx->r29, 0X40);
    // 0x8005E028: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8005E02C: lhu         $t2, 0x1C($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X1C);
    // 0x8005E030: lhu         $t3, 0x62($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X62);
    // 0x8005E034: bne         $t2, $t3, L_8005E04C
    if (ctx->r10 != ctx->r11) {
        // 0x8005E038: nop
    
            goto L_8005E04C;
    }
    // 0x8005E038: nop

    // 0x8005E03C: lhu         $t4, 0x1E($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X1E);
    // 0x8005E040: lhu         $t5, 0x60($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X60);
    // 0x8005E044: beq         $t4, $t5, L_8005E0B4
    if (ctx->r12 == ctx->r13) {
        // 0x8005E048: nop
    
            goto L_8005E0B4;
    }
    // 0x8005E048: nop

L_8005E04C:
    // 0x8005E04C: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8005E050: jal         0x8005DE0C
    // 0x8005E054: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_8005DE0C(rdram, ctx);
        goto after_3;
    // 0x8005E054: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8005E058: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8005E05C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8005E060: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8005E064: bne         $t7, $at, L_8005E0A0
    if (ctx->r15 != ctx->r1) {
        // 0x8005E068: nop
    
            goto L_8005E0A0;
    }
    // 0x8005E068: nop

    // 0x8005E06C: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8005E070: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8005E074: jal         0x8005D9F4
    // 0x8005E078: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_8005D9F4(rdram, ctx);
        goto after_4;
    // 0x8005E078: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_4:
    // 0x8005E07C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8005E080: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8005E084: beq         $t6, $zero, L_8005E094
    if (ctx->r14 == 0) {
        // 0x8005E088: nop
    
            goto L_8005E094;
    }
    // 0x8005E088: nop

    // 0x8005E08C: b           L_8005E1F0
    // 0x8005E090: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8005E1F0;
    // 0x8005E090: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_8005E094:
    // 0x8005E094: addiu       $t8, $sp, 0x20
    ctx->r24 = ADD32(ctx->r29, 0X20);
    // 0x8005E098: b           L_8005E0B4
    // 0x8005E09C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
        goto L_8005E0B4;
    // 0x8005E09C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
L_8005E0A0:
    // 0x8005E0A0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8005E0A4: beq         $t9, $zero, L_8005E0B4
    if (ctx->r25 == 0) {
        // 0x8005E0A8: nop
    
            goto L_8005E0B4;
    }
    // 0x8005E0A8: nop

    // 0x8005E0AC: b           L_8005E1F0
    // 0x8005E0B0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_8005E1F0;
    // 0x8005E0B0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8005E0B4:
    // 0x8005E0B4: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8005E0B8: lhu         $t2, 0x18($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X18);
    // 0x8005E0BC: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8005E0C0: bne         $t3, $zero, L_8005E110
    if (ctx->r11 != 0) {
        // 0x8005E0C4: nop
    
            goto L_8005E110;
    }
    // 0x8005E0C4: nop

    // 0x8005E0C8: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8005E0CC: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x8005E0D0: jal         0x8005D9F4
    // 0x8005E0D4: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_8005D9F4(rdram, ctx);
        goto after_5;
    // 0x8005E0D4: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_5:
    // 0x8005E0D8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8005E0DC: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8005E0E0: beq         $t1, $zero, L_8005E0F0
    if (ctx->r9 == 0) {
        // 0x8005E0E4: nop
    
            goto L_8005E0F0;
    }
    // 0x8005E0E4: nop

    // 0x8005E0E8: b           L_8005E1F0
    // 0x8005E0EC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_8005E1F0;
    // 0x8005E0EC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_8005E0F0:
    // 0x8005E0F0: addiu       $t4, $sp, 0x20
    ctx->r12 = ADD32(ctx->r29, 0X20);
    // 0x8005E0F4: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8005E0F8: lhu         $t5, 0x18($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X18);
    // 0x8005E0FC: andi        $t7, $t5, 0x1
    ctx->r15 = ctx->r13 & 0X1;
    // 0x8005E100: bne         $t7, $zero, L_8005E110
    if (ctx->r15 != 0) {
        // 0x8005E104: nop
    
            goto L_8005E110;
    }
    // 0x8005E104: nop

    // 0x8005E108: b           L_8005E1F0
    // 0x8005E10C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_8005E1F0;
    // 0x8005E10C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_8005E110:
    // 0x8005E110: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
L_8005E114:
    // 0x8005E114: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8005E118: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x8005E11C: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x8005E120: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8005E124: lbu         $t2, 0x0($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0X0);
    // 0x8005E128: addu        $t0, $t3, $t8
    ctx->r8 = ADD32(ctx->r11, ctx->r24);
    // 0x8005E12C: sb          $t2, 0xC($t0)
    MEM_B(0XC, ctx->r8) = ctx->r10;
    // 0x8005E130: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x8005E134: addiu       $t4, $t1, 0x1
    ctx->r12 = ADD32(ctx->r9, 0X1);
    // 0x8005E138: slti        $at, $t4, 0x20
    ctx->r1 = SIGNED(ctx->r12) < 0X20 ? 1 : 0;
    // 0x8005E13C: bne         $at, $zero, L_8005E114
    if (ctx->r1 != 0) {
        // 0x8005E140: sw          $t4, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r12;
            goto L_8005E114;
    }
    // 0x8005E140: sw          $t4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r12;
    // 0x8005E144: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8005E148: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x8005E14C: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x8005E150: lbu         $t7, 0x1B($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X1B);
    // 0x8005E154: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
    // 0x8005E158: sw          $t7, 0x4C($t6)
    MEM_W(0X4C, ctx->r14) = ctx->r15;
    // 0x8005E15C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8005E160: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x8005E164: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8005E168: lbu         $t3, 0x1A($t9)
    ctx->r11 = MEM_BU(ctx->r25, 0X1A);
    // 0x8005E16C: sb          $t3, 0x64($t8)
    MEM_B(0X64, ctx->r24) = ctx->r11;
    // 0x8005E170: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x8005E174: lbu         $t0, 0x64($t2)
    ctx->r8 = MEM_BU(ctx->r10, 0X64);
    // 0x8005E178: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8005E17C: addiu       $t4, $t1, 0x3
    ctx->r12 = ADD32(ctx->r9, 0X3);
    // 0x8005E180: sw          $t4, 0x60($t2)
    MEM_W(0X60, ctx->r10) = ctx->r12;
    // 0x8005E184: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x8005E188: sw          $t5, 0x50($t7)
    MEM_W(0X50, ctx->r15) = ctx->r13;
    // 0x8005E18C: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x8005E190: sw          $t6, 0x54($t9)
    MEM_W(0X54, ctx->r25) = ctx->r14;
    // 0x8005E194: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x8005E198: lbu         $t8, 0x64($t3)
    ctx->r24 = MEM_BU(ctx->r11, 0X64);
    // 0x8005E19C: sll         $t0, $t8, 3
    ctx->r8 = S32(ctx->r24 << 3);
    // 0x8005E1A0: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8005E1A4: sw          $t1, 0x58($t3)
    MEM_W(0X58, ctx->r11) = ctx->r9;
    // 0x8005E1A8: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x8005E1AC: lbu         $t5, 0x64($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X64);
    // 0x8005E1B0: lw          $t2, 0x58($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X58);
    // 0x8005E1B4: sll         $t7, $t5, 3
    ctx->r15 = S32(ctx->r13 << 3);
    // 0x8005E1B8: addu        $t6, $t2, $t7
    ctx->r14 = ADD32(ctx->r10, ctx->r15);
    // 0x8005E1BC: sw          $t6, 0x5C($t4)
    MEM_W(0X5C, ctx->r12) = ctx->r14;
    // 0x8005E1C0: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x8005E1C4: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x8005E1C8: lw          $a1, 0x8($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X8);
    // 0x8005E1CC: jal         0x8005D0F0
    // 0x8005E1D0: addiu       $a3, $t9, 0x2C
    ctx->r7 = ADD32(ctx->r25, 0X2C);
    func_8005D0F0(rdram, ctx);
        goto after_6;
    // 0x8005E1D0: addiu       $a3, $t9, 0x2C
    ctx->r7 = ADD32(ctx->r25, 0X2C);
    after_6:
    // 0x8005E1D4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8005E1D8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8005E1DC: beq         $t8, $zero, L_8005E1EC
    if (ctx->r24 == 0) {
        // 0x8005E1E0: nop
    
            goto L_8005E1EC;
    }
    // 0x8005E1E0: nop

    // 0x8005E1E4: b           L_8005E1F0
    // 0x8005E1E8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_8005E1F0;
    // 0x8005E1E8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8005E1EC:
    // 0x8005E1EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005E1F0:
    // 0x8005E1F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005E1F4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8005E1F8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005E200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005E200: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8005E204: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8005E208: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8005E20C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005E210: lbu         $t7, 0x65($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X65);
    // 0x8005E214: beq         $t7, $zero, L_8005E240
    if (ctx->r15 == 0) {
        // 0x8005E218: nop
    
            goto L_8005E240;
    }
    // 0x8005E218: nop

    // 0x8005E21C: sb          $zero, 0x65($t6)
    MEM_B(0X65, ctx->r14) = 0;
    // 0x8005E220: jal         0x8005E61C
    // 0x8005E224: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_8005E61C(rdram, ctx);
        goto after_0;
    // 0x8005E224: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_0:
    // 0x8005E228: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8005E22C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8005E230: beq         $t8, $zero, L_8005E240
    if (ctx->r24 == 0) {
        // 0x8005E234: nop
    
            goto L_8005E240;
    }
    // 0x8005E234: nop

    // 0x8005E238: b           L_8005E2EC
    // 0x8005E23C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_8005E2EC;
    // 0x8005E23C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8005E240:
    // 0x8005E240: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8005E244: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005E248: addiu       $a3, $sp, 0x1C
    ctx->r7 = ADD32(ctx->r29, 0X1C);
    // 0x8005E24C: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x8005E250: jal         0x8005D0F0
    // 0x8005E254: lw          $a1, 0x8($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X8);
    func_8005D0F0(rdram, ctx);
        goto after_1;
    // 0x8005E254: lw          $a1, 0x8($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X8);
    after_1:
    // 0x8005E258: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8005E25C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8005E260: beq         $t0, $zero, L_8005E2A8
    if (ctx->r8 == 0) {
        // 0x8005E264: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8005E2A8;
    }
    // 0x8005E264: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005E268: beq         $t0, $at, L_8005E278
    if (ctx->r8 == ctx->r1) {
        // 0x8005E26C: nop
    
            goto L_8005E278;
    }
    // 0x8005E26C: nop

    // 0x8005E270: b           L_8005E2EC
    // 0x8005E274: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_8005E2EC;
    // 0x8005E274: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8005E278:
    // 0x8005E278: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8005E27C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005E280: addiu       $a3, $sp, 0x1C
    ctx->r7 = ADD32(ctx->r29, 0X1C);
    // 0x8005E284: lw          $a0, 0x4($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X4);
    // 0x8005E288: jal         0x8005D0F0
    // 0x8005E28C: lw          $a1, 0x8($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X8);
    func_8005D0F0(rdram, ctx);
        goto after_2;
    // 0x8005E28C: lw          $a1, 0x8($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X8);
    after_2:
    // 0x8005E290: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8005E294: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8005E298: beq         $t2, $zero, L_8005E2A8
    if (ctx->r10 == 0) {
        // 0x8005E29C: nop
    
            goto L_8005E2A8;
    }
    // 0x8005E29C: nop

    // 0x8005E2A0: b           L_8005E2EC
    // 0x8005E2A4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
        goto L_8005E2EC;
    // 0x8005E2A4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_8005E2A8:
    // 0x8005E2A8: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
L_8005E2AC:
    // 0x8005E2AC: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E2B0: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8005E2B4: addu        $t4, $sp, $t3
    ctx->r12 = ADD32(ctx->r29, ctx->r11);
    // 0x8005E2B8: addu        $t7, $t5, $t3
    ctx->r15 = ADD32(ctx->r13, ctx->r11);
    // 0x8005E2BC: lbu         $t6, 0xC($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0XC);
    // 0x8005E2C0: lbu         $t4, 0x1C($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X1C);
    // 0x8005E2C4: beq         $t4, $t6, L_8005E2D4
    if (ctx->r12 == ctx->r14) {
        // 0x8005E2C8: nop
    
            goto L_8005E2D4;
    }
    // 0x8005E2C8: nop

    // 0x8005E2CC: b           L_8005E2EC
    // 0x8005E2D0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8005E2EC;
    // 0x8005E2D0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8005E2D4:
    // 0x8005E2D4: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E2D8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8005E2DC: slti        $at, $t9, 0x20
    ctx->r1 = SIGNED(ctx->r25) < 0X20 ? 1 : 0;
    // 0x8005E2E0: bne         $at, $zero, L_8005E2AC
    if (ctx->r1 != 0) {
        // 0x8005E2E4: sw          $t9, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r25;
            goto L_8005E2AC;
    }
    // 0x8005E2E4: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x8005E2E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005E2EC:
    // 0x8005E2EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005E2F0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8005E2F4: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005E2FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005E2FC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8005E300: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8005E304: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8005E308: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005E30C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8005E310: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8005E314: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8005E318: lbu         $t7, 0x65($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X65);
    // 0x8005E31C: beq         $t7, $zero, L_8005E348
    if (ctx->r15 == 0) {
        // 0x8005E320: nop
    
            goto L_8005E348;
    }
    // 0x8005E320: nop

    // 0x8005E324: sb          $zero, 0x65($t6)
    MEM_B(0X65, ctx->r14) = 0;
    // 0x8005E328: jal         0x8005E61C
    // 0x8005E32C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_8005E61C(rdram, ctx);
        goto after_0;
    // 0x8005E32C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_0:
    // 0x8005E330: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8005E334: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8005E338: beq         $t8, $zero, L_8005E348
    if (ctx->r24 == 0) {
        // 0x8005E33C: nop
    
            goto L_8005E348;
    }
    // 0x8005E33C: nop

    // 0x8005E340: b           L_8005E60C
    // 0x8005E344: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_8005E60C;
    // 0x8005E344: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8005E348:
    // 0x8005E348: lbu         $t9, 0x47($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X47);
    // 0x8005E34C: blez        $t9, L_8005E360
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8005E350: nop
    
            goto L_8005E360;
    }
    // 0x8005E350: nop

    // 0x8005E354: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8005E358: b           L_8005E36C
    // 0x8005E35C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
        goto L_8005E36C;
    // 0x8005E35C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
L_8005E360:
    // 0x8005E360: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8005E364: lw          $t2, 0x60($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X60);
    // 0x8005E368: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
L_8005E36C:
    // 0x8005E36C: lbu         $t3, 0x43($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X43);
    // 0x8005E370: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005E374: bne         $t3, $at, L_8005E3A8
    if (ctx->r11 != ctx->r1) {
        // 0x8005E378: nop
    
            goto L_8005E3A8;
    }
    // 0x8005E378: nop

    // 0x8005E37C: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8005E380: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E384: negu        $a1, $t5
    ctx->r5 = SUB32(0, ctx->r13);
    // 0x8005E388: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x8005E38C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8005E390: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
    // 0x8005E394: addiu       $a1, $a1, 0x100
    ctx->r5 = ADD32(ctx->r5, 0X100);
    // 0x8005E398: jal         0x8005D930
    // 0x8005E39C: addu        $a0, $t4, $t7
    ctx->r4 = ADD32(ctx->r12, ctx->r15);
    func_8005D930(rdram, ctx);
        goto after_1;
    // 0x8005E39C: addu        $a0, $t4, $t7
    ctx->r4 = ADD32(ctx->r12, ctx->r15);
    after_1:
    // 0x8005E3A0: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E3A4: sb          $v0, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r2;
L_8005E3A8:
    // 0x8005E3A8: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_8005E3AC:
    // 0x8005E3AC: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8005E3B0: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E3B4: lbu         $t3, 0x43($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X43);
    // 0x8005E3B8: sll         $t1, $t0, 5
    ctx->r9 = S32(ctx->r8 << 5);
    // 0x8005E3BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005E3C0: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8005E3C4: bne         $t3, $at, L_8005E434
    if (ctx->r11 != ctx->r1) {
        // 0x8005E3C8: sw          $t2, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r10;
            goto L_8005E434;
    }
    // 0x8005E3C8: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x8005E3CC: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8005E3D0: lbu         $t5, 0x47($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X47);
    // 0x8005E3D4: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
    // 0x8005E3D8: lw          $t7, 0x54($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X54);
    // 0x8005E3DC: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x8005E3E0: lw          $a0, 0x4($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X4);
    // 0x8005E3E4: lw          $a1, 0x8($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X8);
    // 0x8005E3E8: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x8005E3EC: addu        $a2, $t8, $t0
    ctx->r6 = ADD32(ctx->r24, ctx->r8);
    // 0x8005E3F0: jal         0x8005CD70
    // 0x8005E3F4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8005CD70(rdram, ctx);
        goto after_2;
    // 0x8005E3F4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x8005E3F8: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8005E3FC: lbu         $t3, 0x47($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X47);
    // 0x8005E400: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8005E404: lw          $t1, 0x58($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X58);
    // 0x8005E408: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8005E40C: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x8005E410: lw          $a1, 0x8($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X8);
    // 0x8005E414: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x8005E418: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x8005E41C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8005E420: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8005E424: jal         0x8005CD70
    // 0x8005E428: addu        $a2, $t5, $t7
    ctx->r6 = ADD32(ctx->r13, ctx->r15);
    func_8005CD70(rdram, ctx);
        goto after_3;
    // 0x8005E428: addu        $a2, $t5, $t7
    ctx->r6 = ADD32(ctx->r13, ctx->r15);
    after_3:
    // 0x8005E42C: b           L_8005E464
    // 0x8005E430: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
        goto L_8005E464;
    // 0x8005E430: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_8005E434:
    // 0x8005E434: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8005E438: lbu         $t0, 0x47($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X47);
    // 0x8005E43C: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8005E440: lw          $t8, 0x54($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X54);
    // 0x8005E444: sll         $t2, $t0, 3
    ctx->r10 = S32(ctx->r8 << 3);
    // 0x8005E448: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8005E44C: addu        $t9, $t8, $t2
    ctx->r25 = ADD32(ctx->r24, ctx->r10);
    // 0x8005E450: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    // 0x8005E454: lw          $a1, 0x8($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X8);
    // 0x8005E458: jal         0x8005D0F0
    // 0x8005E45C: addu        $a2, $t9, $t3
    ctx->r6 = ADD32(ctx->r25, ctx->r11);
    func_8005D0F0(rdram, ctx);
        goto after_4;
    // 0x8005E45C: addu        $a2, $t9, $t3
    ctx->r6 = ADD32(ctx->r25, ctx->r11);
    after_4:
    // 0x8005E460: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_8005E464:
    // 0x8005E464: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8005E468: beq         $t1, $zero, L_8005E478
    if (ctx->r9 == 0) {
        // 0x8005E46C: nop
    
            goto L_8005E478;
    }
    // 0x8005E46C: nop

    // 0x8005E470: b           L_8005E60C
    // 0x8005E474: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_8005E60C;
    // 0x8005E474: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_8005E478:
    // 0x8005E478: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8005E47C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8005E480: slti        $at, $t5, 0x8
    ctx->r1 = SIGNED(ctx->r13) < 0X8 ? 1 : 0;
    // 0x8005E484: bne         $at, $zero, L_8005E3AC
    if (ctx->r1 != 0) {
        // 0x8005E488: sw          $t5, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r13;
            goto L_8005E3AC;
    }
    // 0x8005E488: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x8005E48C: lbu         $t7, 0x43($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X43);
    // 0x8005E490: bne         $t7, $zero, L_8005E608
    if (ctx->r15 != 0) {
        // 0x8005E494: nop
    
            goto L_8005E608;
    }
    // 0x8005E494: nop

    // 0x8005E498: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8005E49C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E4A0: negu        $a1, $t0
    ctx->r5 = SUB32(0, ctx->r8);
    // 0x8005E4A4: sll         $t2, $a1, 1
    ctx->r10 = S32(ctx->r5 << 1);
    // 0x8005E4A8: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x8005E4AC: sll         $t8, $t0, 1
    ctx->r24 = S32(ctx->r8 << 1);
    // 0x8005E4B0: addiu       $a1, $a1, 0x100
    ctx->r5 = ADD32(ctx->r5, 0X100);
    // 0x8005E4B4: jal         0x8005D930
    // 0x8005E4B8: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    func_8005D930(rdram, ctx);
        goto after_5;
    // 0x8005E4B8: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    after_5:
    // 0x8005E4BC: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E4C0: sb          $v0, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r2;
    // 0x8005E4C4: lbu         $t1, 0x37($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X37);
    // 0x8005E4C8: lbu         $t3, 0x1($t9)
    ctx->r11 = MEM_BU(ctx->r25, 0X1);
    // 0x8005E4CC: beq         $t3, $t1, L_8005E5AC
    if (ctx->r11 == ctx->r9) {
        // 0x8005E4D0: nop
    
            goto L_8005E5AC;
    }
    // 0x8005E4D0: nop

    // 0x8005E4D4: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_8005E4D8:
    // 0x8005E4D8: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8005E4DC: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E4E0: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8005E4E4: sll         $t7, $t5, 5
    ctx->r15 = S32(ctx->r13 << 5);
    // 0x8005E4E8: addu        $t6, $t4, $t7
    ctx->r14 = ADD32(ctx->r12, ctx->r15);
    // 0x8005E4EC: lbu         $t2, 0x47($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X47);
    // 0x8005E4F0: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8005E4F4: lw          $t0, 0x58($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X58);
    // 0x8005E4F8: sll         $t9, $t2, 3
    ctx->r25 = S32(ctx->r10 << 3);
    // 0x8005E4FC: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x8005E500: addu        $t3, $t0, $t9
    ctx->r11 = ADD32(ctx->r8, ctx->r25);
    // 0x8005E504: addu        $a2, $t3, $t5
    ctx->r6 = ADD32(ctx->r11, ctx->r13);
    // 0x8005E508: lw          $a1, 0x8($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X8);
    // 0x8005E50C: jal         0x8005D0F0
    // 0x8005E510: lw          $a0, 0x4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X4);
    func_8005D0F0(rdram, ctx);
        goto after_6;
    // 0x8005E510: lw          $a0, 0x4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X4);
    after_6:
    // 0x8005E514: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8005E518: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8005E51C: addiu       $t4, $t1, 0x1
    ctx->r12 = ADD32(ctx->r9, 0X1);
    // 0x8005E520: slti        $at, $t4, 0x8
    ctx->r1 = SIGNED(ctx->r12) < 0X8 ? 1 : 0;
    // 0x8005E524: bne         $at, $zero, L_8005E4D8
    if (ctx->r1 != 0) {
        // 0x8005E528: sw          $t4, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r12;
            goto L_8005E4D8;
    }
    // 0x8005E528: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x8005E52C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E530: lbu         $t2, 0x37($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X37);
    // 0x8005E534: lbu         $t8, 0x1($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X1);
    // 0x8005E538: beq         $t8, $t2, L_8005E548
    if (ctx->r24 == ctx->r10) {
        // 0x8005E53C: nop
    
            goto L_8005E548;
    }
    // 0x8005E53C: nop

    // 0x8005E540: b           L_8005E60C
    // 0x8005E544: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8005E60C;
    // 0x8005E544: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8005E548:
    // 0x8005E548: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_8005E54C:
    // 0x8005E54C: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8005E550: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E554: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8005E558: sll         $t3, $t9, 5
    ctx->r11 = S32(ctx->r25 << 5);
    // 0x8005E55C: addu        $t5, $t0, $t3
    ctx->r13 = ADD32(ctx->r8, ctx->r11);
    // 0x8005E560: lbu         $t4, 0x47($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X47);
    // 0x8005E564: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x8005E568: lw          $t1, 0x54($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X54);
    // 0x8005E56C: sll         $t7, $t4, 3
    ctx->r15 = S32(ctx->r12 << 3);
    // 0x8005E570: lw          $a1, 0x8($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X8);
    // 0x8005E574: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    // 0x8005E578: addu        $t8, $t1, $t7
    ctx->r24 = ADD32(ctx->r9, ctx->r15);
    // 0x8005E57C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8005E580: or          $a3, $t5, $zero
    ctx->r7 = ctx->r13 | 0;
    // 0x8005E584: jal         0x8005CD70
    // 0x8005E588: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    func_8005CD70(rdram, ctx);
        goto after_7;
    // 0x8005E588: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    after_7:
    // 0x8005E58C: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8005E590: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8005E594: addiu       $t0, $t2, 0x1
    ctx->r8 = ADD32(ctx->r10, 0X1);
    // 0x8005E598: slti        $at, $t0, 0x8
    ctx->r1 = SIGNED(ctx->r8) < 0X8 ? 1 : 0;
    // 0x8005E59C: bne         $at, $zero, L_8005E54C
    if (ctx->r1 != 0) {
        // 0x8005E5A0: sw          $t0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r8;
            goto L_8005E54C;
    }
    // 0x8005E5A0: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x8005E5A4: b           L_8005E608
    // 0x8005E5A8: nop

        goto L_8005E608;
    // 0x8005E5A8: nop

L_8005E5AC:
    // 0x8005E5AC: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_8005E5B0:
    // 0x8005E5B0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8005E5B4: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E5B8: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8005E5BC: sll         $t4, $t6, 5
    ctx->r12 = S32(ctx->r14 << 5);
    // 0x8005E5C0: addu        $t1, $t3, $t4
    ctx->r9 = ADD32(ctx->r11, ctx->r12);
    // 0x8005E5C4: lbu         $t9, 0x47($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X47);
    // 0x8005E5C8: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8005E5CC: lw          $t8, 0x58($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X58);
    // 0x8005E5D0: sll         $t5, $t9, 3
    ctx->r13 = S32(ctx->r25 << 3);
    // 0x8005E5D4: lw          $a1, 0x8($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X8);
    // 0x8005E5D8: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    // 0x8005E5DC: addu        $t2, $t8, $t5
    ctx->r10 = ADD32(ctx->r24, ctx->r13);
    // 0x8005E5E0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8005E5E4: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x8005E5E8: jal         0x8005CD70
    // 0x8005E5EC: addu        $a2, $t2, $t6
    ctx->r6 = ADD32(ctx->r10, ctx->r14);
    func_8005CD70(rdram, ctx);
        goto after_8;
    // 0x8005E5EC: addu        $a2, $t2, $t6
    ctx->r6 = ADD32(ctx->r10, ctx->r14);
    after_8:
    // 0x8005E5F0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8005E5F4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8005E5F8: addiu       $t3, $t0, 0x1
    ctx->r11 = ADD32(ctx->r8, 0X1);
    // 0x8005E5FC: slti        $at, $t3, 0x8
    ctx->r1 = SIGNED(ctx->r11) < 0X8 ? 1 : 0;
    // 0x8005E600: bne         $at, $zero, L_8005E5B0
    if (ctx->r1 != 0) {
        // 0x8005E604: sw          $t3, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r11;
            goto L_8005E5B0;
    }
    // 0x8005E604: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
L_8005E608:
    // 0x8005E608: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005E60C:
    // 0x8005E60C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005E610: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8005E614: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005E61C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005E61C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8005E620: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005E624: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8005E628: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8005E62C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_8005E630:
    // 0x8005E630: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8005E634: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8005E638: lbu         $t7, 0x65($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X65);
    // 0x8005E63C: addu        $t9, $sp, $t8
    ctx->r25 = ADD32(ctx->r29, ctx->r24);
    // 0x8005E640: sb          $t7, 0x28($t9)
    MEM_B(0X28, ctx->r25) = ctx->r15;
    // 0x8005E644: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8005E648: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8005E64C: slti        $at, $t1, 0x20
    ctx->r1 = SIGNED(ctx->r9) < 0X20 ? 1 : 0;
    // 0x8005E650: bne         $at, $zero, L_8005E630
    if (ctx->r1 != 0) {
        // 0x8005E654: sw          $t1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r9;
            goto L_8005E630;
    }
    // 0x8005E654: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8005E658: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x8005E65C: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    // 0x8005E660: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // 0x8005E664: lw          $a0, 0x4($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X4);
    // 0x8005E668: lw          $a1, 0x8($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X8);
    // 0x8005E66C: jal         0x8005CD70
    // 0x8005E670: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8005CD70(rdram, ctx);
        goto after_0;
    // 0x8005E670: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x8005E674: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005E678: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8005E67C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8005E680: jr          $ra
    // 0x8005E684: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    TRACE_RETURN()
    return;
    // 0x8005E684: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8005E690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005E690: addiu       $sp, $sp, -0x488
    ctx->r29 = ADD32(ctx->r29, -0X488);
    // 0x8005E694: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005E698: sw          $a0, 0x488($sp)
    MEM_W(0X488, ctx->r29) = ctx->r4;
    // 0x8005E69C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8005E6A0: jal         0x8005E200
    // 0x8005E6A4: lw          $a0, 0x488($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X488);
    func_8005E200(rdram, ctx);
        goto after_0;
    // 0x8005E6A4: lw          $a0, 0x488($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X488);
    after_0:
    // 0x8005E6A8: sw          $v0, 0x480($sp)
    MEM_W(0X480, ctx->r29) = ctx->r2;
    // 0x8005E6AC: lw          $t6, 0x480($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X480);
    // 0x8005E6B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005E6B4: bne         $t6, $at, L_8005E6C8
    if (ctx->r14 != ctx->r1) {
        // 0x8005E6B8: nop
    
            goto L_8005E6C8;
    }
    // 0x8005E6B8: nop

    // 0x8005E6BC: jal         0x8005DFA4
    // 0x8005E6C0: lw          $a0, 0x488($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X488);
    func_8005DFA4(rdram, ctx);
        goto after_1;
    // 0x8005E6C0: lw          $a0, 0x488($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X488);
    after_1:
    // 0x8005E6C4: sw          $v0, 0x480($sp)
    MEM_W(0X480, ctx->r29) = ctx->r2;
L_8005E6C8:
    // 0x8005E6C8: lw          $t7, 0x480($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X480);
    // 0x8005E6CC: beq         $t7, $zero, L_8005E6DC
    if (ctx->r15 == 0) {
        // 0x8005E6D0: nop
    
            goto L_8005E6DC;
    }
    // 0x8005E6D0: nop

    // 0x8005E6D4: b           L_8005ED44
    // 0x8005E6D8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_8005ED44;
    // 0x8005E6D8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8005E6DC:
    // 0x8005E6DC: lw          $a0, 0x488($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X488);
    // 0x8005E6E0: jal         0x8005ED54
    // 0x8005E6E4: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_8005ED54(rdram, ctx);
        goto after_2;
    // 0x8005E6E4: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_2:
    // 0x8005E6E8: sw          $v0, 0x480($sp)
    MEM_W(0X480, ctx->r29) = ctx->r2;
    // 0x8005E6EC: lw          $t8, 0x480($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X480);
    // 0x8005E6F0: beq         $t8, $zero, L_8005E700
    if (ctx->r24 == 0) {
        // 0x8005E6F4: nop
    
            goto L_8005E700;
    }
    // 0x8005E6F4: nop

    // 0x8005E6F8: b           L_8005ED44
    // 0x8005E6FC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_8005ED44;
    // 0x8005E6FC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8005E700:
    // 0x8005E700: lw          $t9, 0x488($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X488);
    // 0x8005E704: sw          $zero, 0x484($sp)
    MEM_W(0X484, ctx->r29) = 0;
    // 0x8005E708: lw          $t0, 0x50($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X50);
    // 0x8005E70C: blez        $t0, L_8005EA10
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8005E710: nop
    
            goto L_8005EA10;
    }
    // 0x8005E710: nop

L_8005E714:
    // 0x8005E714: lw          $t1, 0x488($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X488);
    // 0x8005E718: lw          $t3, 0x484($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X484);
    // 0x8005E71C: addiu       $a3, $sp, 0x25C
    ctx->r7 = ADD32(ctx->r29, 0X25C);
    // 0x8005E720: lw          $t2, 0x5C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X5C);
    // 0x8005E724: lw          $a0, 0x4($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X4);
    // 0x8005E728: lw          $a1, 0x8($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X8);
    // 0x8005E72C: jal         0x8005D0F0
    // 0x8005E730: addu        $a2, $t2, $t3
    ctx->r6 = ADD32(ctx->r10, ctx->r11);
    func_8005D0F0(rdram, ctx);
        goto after_3;
    // 0x8005E730: addu        $a2, $t2, $t3
    ctx->r6 = ADD32(ctx->r10, ctx->r11);
    after_3:
    // 0x8005E734: sw          $v0, 0x480($sp)
    MEM_W(0X480, ctx->r29) = ctx->r2;
    // 0x8005E738: lw          $t4, 0x480($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X480);
    // 0x8005E73C: beq         $t4, $zero, L_8005E74C
    if (ctx->r12 == 0) {
        // 0x8005E740: nop
    
            goto L_8005E74C;
    }
    // 0x8005E740: nop

    // 0x8005E744: b           L_8005ED44
    // 0x8005E748: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
        goto L_8005ED44;
    // 0x8005E748: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
L_8005E74C:
    // 0x8005E74C: lhu         $t5, 0x260($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X260);
    // 0x8005E750: beq         $t5, $zero, L_8005E948
    if (ctx->r13 == 0) {
        // 0x8005E754: nop
    
            goto L_8005E948;
    }
    // 0x8005E754: nop

    // 0x8005E758: lw          $t6, 0x25C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X25C);
    // 0x8005E75C: beq         $t6, $zero, L_8005E948
    if (ctx->r14 == 0) {
        // 0x8005E760: nop
    
            goto L_8005E948;
    }
    // 0x8005E760: nop

    // 0x8005E764: lhu         $t7, 0x262($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X262);
    // 0x8005E768: lw          $t0, 0x488($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X488);
    // 0x8005E76C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8005E770: sh          $t7, 0x47C($sp)
    MEM_H(0X47C, ctx->r29) = ctx->r15;
    // 0x8005E774: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8005E778: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8005E77C: sb          $t8, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r24;
    // 0x8005E780: lhu         $t9, 0x47C($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X47C);
    // 0x8005E784: lw          $t1, 0x60($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X60);
    // 0x8005E788: slt         $at, $t9, $t1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8005E78C: bne         $at, $zero, L_8005E898
    if (ctx->r1 != 0) {
        // 0x8005E790: nop
    
            goto L_8005E898;
    }
    // 0x8005E790: nop

    // 0x8005E794: lbu         $t2, 0x47C($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X47C);
    // 0x8005E798: lbu         $t3, 0x64($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X64);
    // 0x8005E79C: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8005E7A0: beq         $at, $zero, L_8005E898
    if (ctx->r1 == 0) {
        // 0x8005E7A4: nop
    
            goto L_8005E898;
    }
    // 0x8005E7A4: nop

    // 0x8005E7A8: lbu         $t4, 0x47D($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X47D);
    // 0x8005E7AC: blez        $t4, L_8005E898
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8005E7B0: slti        $at, $t4, 0x80
        ctx->r1 = SIGNED(ctx->r12) < 0X80 ? 1 : 0;
            goto L_8005E898;
    }
    // 0x8005E7B0: slti        $at, $t4, 0x80
    ctx->r1 = SIGNED(ctx->r12) < 0X80 ? 1 : 0;
    // 0x8005E7B4: beq         $at, $zero, L_8005E898
    if (ctx->r1 == 0) {
        // 0x8005E7B8: nop
    
            goto L_8005E898;
    }
    // 0x8005E7B8: nop

L_8005E7BC:
    // 0x8005E7BC: lbu         $t5, 0x33($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X33);
    // 0x8005E7C0: lbu         $t6, 0x47C($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X47C);
    // 0x8005E7C4: beq         $t5, $t6, L_8005E804
    if (ctx->r13 == ctx->r14) {
        // 0x8005E7C8: nop
    
            goto L_8005E804;
    }
    // 0x8005E7C8: nop

    // 0x8005E7CC: sb          $t6, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r14;
    // 0x8005E7D0: lw          $a0, 0x488($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X488);
    // 0x8005E7D4: addiu       $a1, $sp, 0x27C
    ctx->r5 = ADD32(ctx->r29, 0X27C);
    // 0x8005E7D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005E7DC: jal         0x8005E2FC
    // 0x8005E7E0: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    func_8005E2FC(rdram, ctx);
        goto after_4;
    // 0x8005E7E0: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    after_4:
    // 0x8005E7E4: sw          $v0, 0x480($sp)
    MEM_W(0X480, ctx->r29) = ctx->r2;
    // 0x8005E7E8: lw          $t7, 0x480($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X480);
    // 0x8005E7EC: beq         $t7, $zero, L_8005E804
    if (ctx->r15 == 0) {
        // 0x8005E7F0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8005E804;
    }
    // 0x8005E7F0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005E7F4: beq         $t7, $at, L_8005E804
    if (ctx->r15 == ctx->r1) {
        // 0x8005E7F8: nop
    
            goto L_8005E804;
    }
    // 0x8005E7F8: nop

    // 0x8005E7FC: b           L_8005ED44
    // 0x8005E800: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_8005ED44;
    // 0x8005E800: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8005E804:
    // 0x8005E804: lhu         $t8, 0x47C($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X47C);
    // 0x8005E808: lw          $a0, 0x488($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X488);
    // 0x8005E80C: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x8005E810: sh          $t8, 0x4($sp)
    MEM_H(0X4, ctx->r29) = ctx->r24;
    // 0x8005E814: jal         0x8005EF08
    // 0x8005E818: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    func_8005EF08(rdram, ctx);
        goto after_5;
    // 0x8005E818: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    after_5:
    // 0x8005E81C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8005E820: subu        $t1, $v0, $t9
    ctx->r9 = SUB32(ctx->r2, ctx->r25);
    // 0x8005E824: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x8005E828: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8005E82C: bne         $t0, $zero, L_8005E898
    if (ctx->r8 != 0) {
        // 0x8005E830: nop
    
            goto L_8005E898;
    }
    // 0x8005E830: nop

    // 0x8005E834: lbu         $t4, 0x47D($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X47D);
    // 0x8005E838: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8005E83C: addiu       $t6, $sp, 0x27C
    ctx->r14 = ADD32(ctx->r29, 0X27C);
    // 0x8005E840: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8005E844: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x8005E848: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8005E84C: lhu         $at, 0x0($t7)
    ctx->r1 = MEM_HU(ctx->r15, 0X0);
    // 0x8005E850: addiu       $t3, $sp, 0x47C
    ctx->r11 = ADD32(ctx->r29, 0X47C);
    // 0x8005E854: sh          $at, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r1;
    // 0x8005E858: lw          $t2, 0x488($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X488);
    // 0x8005E85C: lhu         $t0, 0x47C($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X47C);
    // 0x8005E860: lw          $t4, 0x60($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X60);
    // 0x8005E864: slt         $at, $t0, $t4
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8005E868: bne         $at, $zero, L_8005E898
    if (ctx->r1 != 0) {
        // 0x8005E86C: nop
    
            goto L_8005E898;
    }
    // 0x8005E86C: nop

    // 0x8005E870: lbu         $t5, 0x47C($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X47C);
    // 0x8005E874: lbu         $t6, 0x64($t2)
    ctx->r14 = MEM_BU(ctx->r10, 0X64);
    // 0x8005E878: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8005E87C: beq         $at, $zero, L_8005E898
    if (ctx->r1 == 0) {
        // 0x8005E880: nop
    
            goto L_8005E898;
    }
    // 0x8005E880: nop

    // 0x8005E884: lbu         $t9, 0x47D($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X47D);
    // 0x8005E888: blez        $t9, L_8005E898
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8005E88C: slti        $at, $t9, 0x80
        ctx->r1 = SIGNED(ctx->r25) < 0X80 ? 1 : 0;
            goto L_8005E898;
    }
    // 0x8005E88C: slti        $at, $t9, 0x80
    ctx->r1 = SIGNED(ctx->r25) < 0X80 ? 1 : 0;
    // 0x8005E890: bne         $at, $zero, L_8005E7BC
    if (ctx->r1 != 0) {
        // 0x8005E894: nop
    
            goto L_8005E7BC;
    }
    // 0x8005E894: nop

L_8005E898:
    // 0x8005E898: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8005E89C: bne         $t8, $zero, L_8005E8B4
    if (ctx->r24 != 0) {
        // 0x8005E8A0: nop
    
            goto L_8005E8B4;
    }
    // 0x8005E8A0: nop

    // 0x8005E8A4: lhu         $t3, 0x47C($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X47C);
    // 0x8005E8A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005E8AC: beq         $t3, $at, L_8005E9F0
    if (ctx->r11 == ctx->r1) {
        // 0x8005E8B0: nop
    
            goto L_8005E9F0;
    }
    // 0x8005E8B0: nop

L_8005E8B4:
    // 0x8005E8B4: lw          $t7, 0x488($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X488);
    // 0x8005E8B8: sh          $zero, 0x260($sp)
    MEM_H(0X260, ctx->r29) = 0;
    // 0x8005E8BC: sw          $zero, 0x25C($sp)
    MEM_W(0X25C, ctx->r29) = 0;
    // 0x8005E8C0: sh          $zero, 0x262($sp)
    MEM_H(0X262, ctx->r29) = 0;
    // 0x8005E8C4: sb          $zero, 0x264($sp)
    MEM_B(0X264, ctx->r29) = 0;
    // 0x8005E8C8: sh          $zero, 0x266($sp)
    MEM_H(0X266, ctx->r29) = 0;
    // 0x8005E8CC: lbu         $t1, 0x65($t7)
    ctx->r9 = MEM_BU(ctx->r15, 0X65);
    // 0x8005E8D0: beq         $t1, $zero, L_8005E8FC
    if (ctx->r9 == 0) {
        // 0x8005E8D4: nop
    
            goto L_8005E8FC;
    }
    // 0x8005E8D4: nop

    // 0x8005E8D8: sb          $zero, 0x65($t7)
    MEM_B(0X65, ctx->r15) = 0;
    // 0x8005E8DC: jal         0x8005E61C
    // 0x8005E8E0: lw          $a0, 0x488($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X488);
    func_8005E61C(rdram, ctx);
        goto after_6;
    // 0x8005E8E0: lw          $a0, 0x488($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X488);
    after_6:
    // 0x8005E8E4: sw          $v0, 0x480($sp)
    MEM_W(0X480, ctx->r29) = ctx->r2;
    // 0x8005E8E8: lw          $t0, 0x480($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X480);
    // 0x8005E8EC: beq         $t0, $zero, L_8005E8FC
    if (ctx->r8 == 0) {
        // 0x8005E8F0: nop
    
            goto L_8005E8FC;
    }
    // 0x8005E8F0: nop

    // 0x8005E8F4: b           L_8005ED44
    // 0x8005E8F8: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_8005ED44;
    // 0x8005E8F8: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8005E8FC:
    // 0x8005E8FC: lw          $t4, 0x488($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X488);
    // 0x8005E900: lw          $t5, 0x484($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X484);
    // 0x8005E904: addiu       $a3, $sp, 0x25C
    ctx->r7 = ADD32(ctx->r29, 0X25C);
    // 0x8005E908: lw          $t2, 0x5C($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X5C);
    // 0x8005E90C: lw          $a0, 0x4($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X4);
    // 0x8005E910: lw          $a1, 0x8($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X8);
    // 0x8005E914: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8005E918: jal         0x8005CD70
    // 0x8005E91C: addu        $a2, $t2, $t5
    ctx->r6 = ADD32(ctx->r10, ctx->r13);
    func_8005CD70(rdram, ctx);
        goto after_7;
    // 0x8005E91C: addu        $a2, $t2, $t5
    ctx->r6 = ADD32(ctx->r10, ctx->r13);
    after_7:
    // 0x8005E920: sw          $v0, 0x480($sp)
    MEM_W(0X480, ctx->r29) = ctx->r2;
    // 0x8005E924: lw          $t6, 0x480($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X480);
    // 0x8005E928: beq         $t6, $zero, L_8005E938
    if (ctx->r14 == 0) {
        // 0x8005E92C: nop
    
            goto L_8005E938;
    }
    // 0x8005E92C: nop

    // 0x8005E930: b           L_8005ED44
    // 0x8005E934: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8005ED44;
    // 0x8005E934: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_8005E938:
    // 0x8005E938: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8005E93C: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x8005E940: b           L_8005E9F0
    // 0x8005E944: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
        goto L_8005E9F0;
    // 0x8005E944: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_8005E948:
    // 0x8005E948: lhu         $t3, 0x260($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X260);
    // 0x8005E94C: bne         $t3, $zero, L_8005E960
    if (ctx->r11 != 0) {
        // 0x8005E950: nop
    
            goto L_8005E960;
    }
    // 0x8005E950: nop

    // 0x8005E954: lw          $t1, 0x25C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X25C);
    // 0x8005E958: beq         $t1, $zero, L_8005E9F0
    if (ctx->r9 == 0) {
        // 0x8005E95C: nop
    
            goto L_8005E9F0;
    }
    // 0x8005E95C: nop

L_8005E960:
    // 0x8005E960: lw          $t7, 0x488($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X488);
    // 0x8005E964: sh          $zero, 0x260($sp)
    MEM_H(0X260, ctx->r29) = 0;
    // 0x8005E968: sw          $zero, 0x25C($sp)
    MEM_W(0X25C, ctx->r29) = 0;
    // 0x8005E96C: sh          $zero, 0x262($sp)
    MEM_H(0X262, ctx->r29) = 0;
    // 0x8005E970: sb          $zero, 0x264($sp)
    MEM_B(0X264, ctx->r29) = 0;
    // 0x8005E974: sh          $zero, 0x266($sp)
    MEM_H(0X266, ctx->r29) = 0;
    // 0x8005E978: lbu         $t0, 0x65($t7)
    ctx->r8 = MEM_BU(ctx->r15, 0X65);
    // 0x8005E97C: beq         $t0, $zero, L_8005E9A8
    if (ctx->r8 == 0) {
        // 0x8005E980: nop
    
            goto L_8005E9A8;
    }
    // 0x8005E980: nop

    // 0x8005E984: sb          $zero, 0x65($t7)
    MEM_B(0X65, ctx->r15) = 0;
    // 0x8005E988: jal         0x8005E61C
    // 0x8005E98C: lw          $a0, 0x488($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X488);
    func_8005E61C(rdram, ctx);
        goto after_8;
    // 0x8005E98C: lw          $a0, 0x488($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X488);
    after_8:
    // 0x8005E990: sw          $v0, 0x480($sp)
    MEM_W(0X480, ctx->r29) = ctx->r2;
    // 0x8005E994: lw          $t4, 0x480($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X480);
    // 0x8005E998: beq         $t4, $zero, L_8005E9A8
    if (ctx->r12 == 0) {
        // 0x8005E99C: nop
    
            goto L_8005E9A8;
    }
    // 0x8005E99C: nop

    // 0x8005E9A0: b           L_8005ED44
    // 0x8005E9A4: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
        goto L_8005ED44;
    // 0x8005E9A4: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
L_8005E9A8:
    // 0x8005E9A8: lw          $t2, 0x488($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X488);
    // 0x8005E9AC: lw          $t6, 0x484($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X484);
    // 0x8005E9B0: addiu       $a3, $sp, 0x25C
    ctx->r7 = ADD32(ctx->r29, 0X25C);
    // 0x8005E9B4: lw          $t5, 0x5C($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X5C);
    // 0x8005E9B8: lw          $a0, 0x4($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X4);
    // 0x8005E9BC: lw          $a1, 0x8($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X8);
    // 0x8005E9C0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8005E9C4: jal         0x8005CD70
    // 0x8005E9C8: addu        $a2, $t5, $t6
    ctx->r6 = ADD32(ctx->r13, ctx->r14);
    func_8005CD70(rdram, ctx);
        goto after_9;
    // 0x8005E9C8: addu        $a2, $t5, $t6
    ctx->r6 = ADD32(ctx->r13, ctx->r14);
    after_9:
    // 0x8005E9CC: sw          $v0, 0x480($sp)
    MEM_W(0X480, ctx->r29) = ctx->r2;
    // 0x8005E9D0: lw          $t9, 0x480($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X480);
    // 0x8005E9D4: beq         $t9, $zero, L_8005E9E4
    if (ctx->r25 == 0) {
        // 0x8005E9D8: nop
    
            goto L_8005E9E4;
    }
    // 0x8005E9D8: nop

    // 0x8005E9DC: b           L_8005ED44
    // 0x8005E9E0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_8005ED44;
    // 0x8005E9E0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8005E9E4:
    // 0x8005E9E4: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8005E9E8: addiu       $t3, $t8, 0x1
    ctx->r11 = ADD32(ctx->r24, 0X1);
    // 0x8005E9EC: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
L_8005E9F0:
    // 0x8005E9F0: lw          $t1, 0x484($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X484);
    // 0x8005E9F4: lw          $t7, 0x488($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X488);
    // 0x8005E9F8: addiu       $t0, $t1, 0x1
    ctx->r8 = ADD32(ctx->r9, 0X1);
    // 0x8005E9FC: sw          $t0, 0x484($sp)
    MEM_W(0X484, ctx->r29) = ctx->r8;
    // 0x8005EA00: lw          $t4, 0x50($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X50);
    // 0x8005EA04: slt         $at, $t0, $t4
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8005EA08: bne         $at, $zero, L_8005E714
    if (ctx->r1 != 0) {
        // 0x8005EA0C: nop
    
            goto L_8005E714;
    }
    // 0x8005EA0C: nop

L_8005EA10:
    // 0x8005EA10: lw          $t2, 0x488($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X488);
    // 0x8005EA14: sw          $zero, 0x484($sp)
    MEM_W(0X484, ctx->r29) = 0;
    // 0x8005EA18: lw          $t5, 0x50($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X50);
    // 0x8005EA1C: blez        $t5, L_8005EAD0
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8005EA20: nop
    
            goto L_8005EAD0;
    }
    // 0x8005EA20: nop

L_8005EA24:
    // 0x8005EA24: lw          $t6, 0x488($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X488);
    // 0x8005EA28: lw          $t8, 0x484($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X484);
    // 0x8005EA2C: addiu       $a3, $sp, 0x25C
    ctx->r7 = ADD32(ctx->r29, 0X25C);
    // 0x8005EA30: lw          $t9, 0x5C($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X5C);
    // 0x8005EA34: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    // 0x8005EA38: lw          $a1, 0x8($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X8);
    // 0x8005EA3C: jal         0x8005D0F0
    // 0x8005EA40: addu        $a2, $t9, $t8
    ctx->r6 = ADD32(ctx->r25, ctx->r24);
    func_8005D0F0(rdram, ctx);
        goto after_10;
    // 0x8005EA40: addu        $a2, $t9, $t8
    ctx->r6 = ADD32(ctx->r25, ctx->r24);
    after_10:
    // 0x8005EA44: sw          $v0, 0x480($sp)
    MEM_W(0X480, ctx->r29) = ctx->r2;
    // 0x8005EA48: lw          $t3, 0x480($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X480);
    // 0x8005EA4C: beq         $t3, $zero, L_8005EA5C
    if (ctx->r11 == 0) {
        // 0x8005EA50: nop
    
            goto L_8005EA5C;
    }
    // 0x8005EA50: nop

    // 0x8005EA54: b           L_8005ED44
    // 0x8005EA58: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
        goto L_8005ED44;
    // 0x8005EA58: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_8005EA5C:
    // 0x8005EA5C: lhu         $t1, 0x260($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X260);
    // 0x8005EA60: beq         $t1, $zero, L_8005EAA0
    if (ctx->r9 == 0) {
        // 0x8005EA64: nop
    
            goto L_8005EAA0;
    }
    // 0x8005EA64: nop

    // 0x8005EA68: lw          $t7, 0x25C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X25C);
    // 0x8005EA6C: beq         $t7, $zero, L_8005EAA0
    if (ctx->r15 == 0) {
        // 0x8005EA70: nop
    
            goto L_8005EAA0;
    }
    // 0x8005EA70: nop

    // 0x8005EA74: lw          $t4, 0x488($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X488);
    // 0x8005EA78: lhu         $t0, 0x262($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X262);
    // 0x8005EA7C: lhu         $t2, 0x62($t4)
    ctx->r10 = MEM_HU(ctx->r12, 0X62);
    // 0x8005EA80: slt         $at, $t0, $t2
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8005EA84: bne         $at, $zero, L_8005EAA0
    if (ctx->r1 != 0) {
        // 0x8005EA88: nop
    
            goto L_8005EAA0;
    }
    // 0x8005EA88: nop

    // 0x8005EA8C: lw          $t5, 0x484($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X484);
    // 0x8005EA90: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x8005EA94: addu        $t9, $sp, $t6
    ctx->r25 = ADD32(ctx->r29, ctx->r14);
    // 0x8005EA98: b           L_8005EAB0
    // 0x8005EA9C: sh          $t0, 0x23C($t9)
    MEM_H(0X23C, ctx->r25) = ctx->r8;
        goto L_8005EAB0;
    // 0x8005EA9C: sh          $t0, 0x23C($t9)
    MEM_H(0X23C, ctx->r25) = ctx->r8;
L_8005EAA0:
    // 0x8005EAA0: lw          $t8, 0x484($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X484);
    // 0x8005EAA4: sll         $t3, $t8, 1
    ctx->r11 = S32(ctx->r24 << 1);
    // 0x8005EAA8: addu        $t1, $sp, $t3
    ctx->r9 = ADD32(ctx->r29, ctx->r11);
    // 0x8005EAAC: sh          $zero, 0x23C($t1)
    MEM_H(0X23C, ctx->r9) = 0;
L_8005EAB0:
    // 0x8005EAB0: lw          $t7, 0x484($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X484);
    // 0x8005EAB4: lw          $t2, 0x488($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X488);
    // 0x8005EAB8: addiu       $t4, $t7, 0x1
    ctx->r12 = ADD32(ctx->r15, 0X1);
    // 0x8005EABC: sw          $t4, 0x484($sp)
    MEM_W(0X484, ctx->r29) = ctx->r12;
    // 0x8005EAC0: lw          $t5, 0x50($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X50);
    // 0x8005EAC4: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8005EAC8: bne         $at, $zero, L_8005EA24
    if (ctx->r1 != 0) {
        // 0x8005EACC: nop
    
            goto L_8005EA24;
    }
    // 0x8005EACC: nop

L_8005EAD0:
    // 0x8005EAD0: lw          $t0, 0x488($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X488);
    // 0x8005EAD4: sb          $zero, 0x33($sp)
    MEM_B(0X33, ctx->r29) = 0;
    // 0x8005EAD8: lbu         $t6, 0x64($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X64);
    // 0x8005EADC: blez        $t6, L_8005ED0C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8005EAE0: nop
    
            goto L_8005ED0C;
    }
    // 0x8005EAE0: nop

L_8005EAE4:
    // 0x8005EAE4: lw          $a0, 0x488($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X488);
    // 0x8005EAE8: addiu       $a1, $sp, 0x27C
    ctx->r5 = ADD32(ctx->r29, 0X27C);
    // 0x8005EAEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005EAF0: jal         0x8005E2FC
    // 0x8005EAF4: lbu         $a3, 0x33($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X33);
    func_8005E2FC(rdram, ctx);
        goto after_11;
    // 0x8005EAF4: lbu         $a3, 0x33($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X33);
    after_11:
    // 0x8005EAF8: sw          $v0, 0x480($sp)
    MEM_W(0X480, ctx->r29) = ctx->r2;
    // 0x8005EAFC: lw          $t9, 0x480($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X480);
    // 0x8005EB00: beq         $t9, $zero, L_8005EB18
    if (ctx->r25 == 0) {
        // 0x8005EB04: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8005EB18;
    }
    // 0x8005EB04: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005EB08: beq         $t9, $at, L_8005EB18
    if (ctx->r25 == ctx->r1) {
        // 0x8005EB0C: nop
    
            goto L_8005EB18;
    }
    // 0x8005EB0C: nop

    // 0x8005EB10: b           L_8005ED44
    // 0x8005EB14: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_8005ED44;
    // 0x8005EB14: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8005EB18:
    // 0x8005EB18: lbu         $t8, 0x33($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X33);
    // 0x8005EB1C: blez        $t8, L_8005EB30
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8005EB20: nop
    
            goto L_8005EB30;
    }
    // 0x8005EB20: nop

    // 0x8005EB24: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005EB28: b           L_8005EB3C
    // 0x8005EB2C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
        goto L_8005EB3C;
    // 0x8005EB2C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
L_8005EB30:
    // 0x8005EB30: lw          $t1, 0x488($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X488);
    // 0x8005EB34: lw          $t7, 0x60($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X60);
    // 0x8005EB38: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_8005EB3C:
    // 0x8005EB3C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8005EB40: sw          $zero, 0x484($sp)
    MEM_W(0X484, ctx->r29) = 0;
    // 0x8005EB44: blez        $t2, L_8005EB7C
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8005EB48: nop
    
            goto L_8005EB7C;
    }
    // 0x8005EB48: nop

L_8005EB4C:
    // 0x8005EB4C: lw          $t4, 0x484($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X484);
    // 0x8005EB50: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8005EB54: addu        $t0, $sp, $t5
    ctx->r8 = ADD32(ctx->r29, ctx->r13);
    // 0x8005EB58: lhu         $t0, 0x27C($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X27C);
    // 0x8005EB5C: addu        $t6, $sp, $t5
    ctx->r14 = ADD32(ctx->r29, ctx->r13);
    // 0x8005EB60: sh          $t0, 0x37C($t6)
    MEM_H(0X37C, ctx->r14) = ctx->r8;
    // 0x8005EB64: lw          $t9, 0x484($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X484);
    // 0x8005EB68: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8005EB6C: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x8005EB70: slt         $at, $t8, $t3
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8005EB74: bne         $at, $zero, L_8005EB4C
    if (ctx->r1 != 0) {
        // 0x8005EB78: sw          $t8, 0x484($sp)
        MEM_W(0X484, ctx->r29) = ctx->r24;
            goto L_8005EB4C;
    }
    // 0x8005EB78: sw          $t8, 0x484($sp)
    MEM_W(0X484, ctx->r29) = ctx->r24;
L_8005EB7C:
    // 0x8005EB7C: lw          $t1, 0x484($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X484);
    // 0x8005EB80: slti        $at, $t1, 0x80
    ctx->r1 = SIGNED(ctx->r9) < 0X80 ? 1 : 0;
    // 0x8005EB84: beq         $at, $zero, L_8005EBB4
    if (ctx->r1 == 0) {
        // 0x8005EB88: nop
    
            goto L_8005EBB4;
    }
    // 0x8005EB88: nop

L_8005EB8C:
    // 0x8005EB8C: lw          $t2, 0x484($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X484);
    // 0x8005EB90: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8005EB94: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x8005EB98: addu        $t0, $sp, $t4
    ctx->r8 = ADD32(ctx->r29, ctx->r12);
    // 0x8005EB9C: sh          $t7, 0x37C($t0)
    MEM_H(0X37C, ctx->r8) = ctx->r15;
    // 0x8005EBA0: lw          $t5, 0x484($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X484);
    // 0x8005EBA4: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8005EBA8: slti        $at, $t6, 0x80
    ctx->r1 = SIGNED(ctx->r14) < 0X80 ? 1 : 0;
    // 0x8005EBAC: bne         $at, $zero, L_8005EB8C
    if (ctx->r1 != 0) {
        // 0x8005EBB0: sw          $t6, 0x484($sp)
        MEM_W(0X484, ctx->r29) = ctx->r14;
            goto L_8005EB8C;
    }
    // 0x8005EBB0: sw          $t6, 0x484($sp)
    MEM_W(0X484, ctx->r29) = ctx->r14;
L_8005EBB4:
    // 0x8005EBB4: lw          $t9, 0x488($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X488);
    // 0x8005EBB8: sw          $zero, 0x484($sp)
    MEM_W(0X484, ctx->r29) = 0;
    // 0x8005EBBC: lw          $t8, 0x50($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X50);
    // 0x8005EBC0: blez        $t8, L_8005ECBC
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8005EBC4: nop
    
            goto L_8005ECBC;
    }
    // 0x8005EBC4: nop

L_8005EBC8:
    // 0x8005EBC8: lw          $t3, 0x484($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X484);
    // 0x8005EBCC: addiu       $t2, $sp, 0x23C
    ctx->r10 = ADD32(ctx->r29, 0X23C);
    // 0x8005EBD0: lbu         $t0, 0x33($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X33);
    // 0x8005EBD4: sll         $t1, $t3, 1
    ctx->r9 = S32(ctx->r11 << 1);
    // 0x8005EBD8: addu        $t7, $t1, $t2
    ctx->r15 = ADD32(ctx->r9, ctx->r10);
    // 0x8005EBDC: lbu         $t4, 0x0($t7)
    ctx->r12 = MEM_BU(ctx->r15, 0X0);
    // 0x8005EBE0: bne         $t4, $t0, L_8005EC9C
    if (ctx->r12 != ctx->r8) {
        // 0x8005EBE4: nop
    
            goto L_8005EC9C;
    }
    // 0x8005EBE4: nop

    // 0x8005EBE8: lw          $t6, 0x488($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X488);
    // 0x8005EBEC: lhu         $t5, 0x0($t7)
    ctx->r13 = MEM_HU(ctx->r15, 0X0);
    // 0x8005EBF0: lhu         $t9, 0x62($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X62);
    // 0x8005EBF4: slt         $at, $t5, $t9
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8005EBF8: bne         $at, $zero, L_8005EC9C
    if (ctx->r1 != 0) {
        // 0x8005EBFC: nop
    
            goto L_8005EC9C;
    }
    // 0x8005EBFC: nop

L_8005EC00:
    // 0x8005EC00: lw          $t8, 0x484($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X484);
    // 0x8005EC04: addiu       $t0, $sp, 0x27C
    ctx->r8 = ADD32(ctx->r29, 0X27C);
    // 0x8005EC08: addiu       $t2, $sp, 0x20
    ctx->r10 = ADD32(ctx->r29, 0X20);
    // 0x8005EC0C: sll         $t3, $t8, 1
    ctx->r11 = S32(ctx->r24 << 1);
    // 0x8005EC10: addu        $t1, $sp, $t3
    ctx->r9 = ADD32(ctx->r29, ctx->r11);
    // 0x8005EC14: lbu         $t1, 0x23D($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X23D);
    // 0x8005EC18: sll         $t4, $t1, 1
    ctx->r12 = S32(ctx->r9 << 1);
    // 0x8005EC1C: addu        $t7, $t4, $t0
    ctx->r15 = ADD32(ctx->r12, ctx->r8);
    // 0x8005EC20: sb          $t1, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r9;
    // 0x8005EC24: lhu         $at, 0x0($t7)
    ctx->r1 = MEM_HU(ctx->r15, 0X0);
    // 0x8005EC28: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
    // 0x8005EC2C: addiu       $t1, $sp, 0x37C
    ctx->r9 = ADD32(ctx->r29, 0X37C);
    // 0x8005EC30: sh          $at, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r1;
    // 0x8005EC34: lbu         $t8, 0x23($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X23);
    // 0x8005EC38: lhu         $at, 0x0($t0)
    ctx->r1 = MEM_HU(ctx->r8, 0X0);
    // 0x8005EC3C: sll         $t3, $t8, 1
    ctx->r11 = S32(ctx->r24 << 1);
    // 0x8005EC40: addu        $t4, $t3, $t1
    ctx->r12 = ADD32(ctx->r11, ctx->r9);
    // 0x8005EC44: sh          $at, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r1;
    // 0x8005EC48: lw          $t7, 0x484($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X484);
    // 0x8005EC4C: addiu       $t1, $sp, 0x20
    ctx->r9 = ADD32(ctx->r29, 0X20);
    // 0x8005EC50: lhu         $at, 0x0($t1)
    ctx->r1 = MEM_HU(ctx->r9, 0X0);
    // 0x8005EC54: addiu       $t8, $sp, 0x23C
    ctx->r24 = ADD32(ctx->r29, 0X23C);
    // 0x8005EC58: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x8005EC5C: addu        $t3, $t9, $t8
    ctx->r11 = ADD32(ctx->r25, ctx->r24);
    // 0x8005EC60: sh          $at, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r1;
    // 0x8005EC64: lw          $t0, 0x484($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X484);
    // 0x8005EC68: addiu       $t7, $sp, 0x23C
    ctx->r15 = ADD32(ctx->r29, 0X23C);
    // 0x8005EC6C: lbu         $t5, 0x33($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X33);
    // 0x8005EC70: sll         $t2, $t0, 1
    ctx->r10 = S32(ctx->r8 << 1);
    // 0x8005EC74: addu        $t9, $t2, $t7
    ctx->r25 = ADD32(ctx->r10, ctx->r15);
    // 0x8005EC78: lbu         $t8, 0x0($t9)
    ctx->r24 = MEM_BU(ctx->r25, 0X0);
    // 0x8005EC7C: bne         $t8, $t5, L_8005EC9C
    if (ctx->r24 != ctx->r13) {
        // 0x8005EC80: nop
    
            goto L_8005EC9C;
    }
    // 0x8005EC80: nop

    // 0x8005EC84: lw          $t3, 0x488($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X488);
    // 0x8005EC88: lhu         $t6, 0x0($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0X0);
    // 0x8005EC8C: lhu         $t1, 0x62($t3)
    ctx->r9 = MEM_HU(ctx->r11, 0X62);
    // 0x8005EC90: slt         $at, $t6, $t1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8005EC94: beq         $at, $zero, L_8005EC00
    if (ctx->r1 == 0) {
        // 0x8005EC98: nop
    
            goto L_8005EC00;
    }
    // 0x8005EC98: nop

L_8005EC9C:
    // 0x8005EC9C: lw          $t4, 0x484($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X484);
    // 0x8005ECA0: lw          $t2, 0x488($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X488);
    // 0x8005ECA4: addiu       $t0, $t4, 0x1
    ctx->r8 = ADD32(ctx->r12, 0X1);
    // 0x8005ECA8: sw          $t0, 0x484($sp)
    MEM_W(0X484, ctx->r29) = ctx->r8;
    // 0x8005ECAC: lw          $t7, 0x50($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X50);
    // 0x8005ECB0: slt         $at, $t0, $t7
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8005ECB4: bne         $at, $zero, L_8005EBC8
    if (ctx->r1 != 0) {
        // 0x8005ECB8: nop
    
            goto L_8005EBC8;
    }
    // 0x8005ECB8: nop

L_8005ECBC:
    // 0x8005ECBC: lw          $a0, 0x488($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X488);
    // 0x8005ECC0: addiu       $a1, $sp, 0x37C
    ctx->r5 = ADD32(ctx->r29, 0X37C);
    // 0x8005ECC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005ECC8: jal         0x8005E2FC
    // 0x8005ECCC: lbu         $a3, 0x33($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X33);
    func_8005E2FC(rdram, ctx);
        goto after_12;
    // 0x8005ECCC: lbu         $a3, 0x33($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X33);
    after_12:
    // 0x8005ECD0: sw          $v0, 0x480($sp)
    MEM_W(0X480, ctx->r29) = ctx->r2;
    // 0x8005ECD4: lw          $t8, 0x480($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X480);
    // 0x8005ECD8: beq         $t8, $zero, L_8005ECE8
    if (ctx->r24 == 0) {
        // 0x8005ECDC: nop
    
            goto L_8005ECE8;
    }
    // 0x8005ECDC: nop

    // 0x8005ECE0: b           L_8005ED44
    // 0x8005ECE4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_8005ED44;
    // 0x8005ECE4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8005ECE8:
    // 0x8005ECE8: lbu         $t5, 0x33($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X33);
    // 0x8005ECEC: lw          $t6, 0x488($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X488);
    // 0x8005ECF0: addiu       $t9, $t5, 0x1
    ctx->r25 = ADD32(ctx->r13, 0X1);
    // 0x8005ECF4: sb          $t9, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r25;
    // 0x8005ECF8: lbu         $t1, 0x64($t6)
    ctx->r9 = MEM_BU(ctx->r14, 0X64);
    // 0x8005ECFC: andi        $t3, $t9, 0xFF
    ctx->r11 = ctx->r25 & 0XFF;
    // 0x8005ED00: slt         $at, $t3, $t1
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8005ED04: bne         $at, $zero, L_8005EAE4
    if (ctx->r1 != 0) {
        // 0x8005ED08: nop
    
            goto L_8005EAE4;
    }
    // 0x8005ED08: nop

L_8005ED0C:
    // 0x8005ED0C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x8005ED10: beq         $t4, $zero, L_8005ED2C
    if (ctx->r12 == 0) {
        // 0x8005ED14: nop
    
            goto L_8005ED2C;
    }
    // 0x8005ED14: nop

    // 0x8005ED18: lw          $t2, 0x488($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X488);
    // 0x8005ED1C: lw          $t0, 0x0($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X0);
    // 0x8005ED20: ori         $t7, $t0, 0x2
    ctx->r15 = ctx->r8 | 0X2;
    // 0x8005ED24: b           L_8005ED40
    // 0x8005ED28: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
        goto L_8005ED40;
    // 0x8005ED28: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
L_8005ED2C:
    // 0x8005ED2C: lw          $t8, 0x488($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X488);
    // 0x8005ED30: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8005ED34: lw          $t5, 0x0($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X0);
    // 0x8005ED38: and         $t9, $t5, $at
    ctx->r25 = ctx->r13 & ctx->r1;
    // 0x8005ED3C: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
L_8005ED40:
    // 0x8005ED40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005ED44:
    // 0x8005ED44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005ED48: addiu       $sp, $sp, 0x488
    ctx->r29 = ADD32(ctx->r29, 0X488);
    // 0x8005ED4C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005ED54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005ED54: addiu       $sp, $sp, -0x130
    ctx->r29 = ADD32(ctx->r29, -0X130);
    // 0x8005ED58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005ED5C: sw          $a0, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r4;
    // 0x8005ED60: sw          $a1, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r5;
    // 0x8005ED64: sw          $zero, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = 0;
L_8005ED68:
    // 0x8005ED68: lw          $t6, 0x134($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X134);
    // 0x8005ED6C: lw          $t7, 0x12C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X12C);
    // 0x8005ED70: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8005ED74: sb          $zero, 0x101($t8)
    MEM_B(0X101, ctx->r24) = 0;
    // 0x8005ED78: lw          $t9, 0x12C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X12C);
    // 0x8005ED7C: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8005ED80: slti        $at, $t0, 0x100
    ctx->r1 = SIGNED(ctx->r8) < 0X100 ? 1 : 0;
    // 0x8005ED84: bne         $at, $zero, L_8005ED68
    if (ctx->r1 != 0) {
        // 0x8005ED88: sw          $t0, 0x12C($sp)
        MEM_W(0X12C, ctx->r29) = ctx->r8;
            goto L_8005ED68;
    }
    // 0x8005ED88: sw          $t0, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r8;
    // 0x8005ED8C: lw          $t2, 0x134($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X134);
    // 0x8005ED90: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8005ED94: sb          $t1, 0x100($t2)
    MEM_B(0X100, ctx->r10) = ctx->r9;
    // 0x8005ED98: lw          $t3, 0x130($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X130);
    // 0x8005ED9C: sb          $zero, 0x123($sp)
    MEM_B(0X123, ctx->r29) = 0;
    // 0x8005EDA0: lbu         $t4, 0x64($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X64);
    // 0x8005EDA4: blez        $t4, L_8005EEF4
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8005EDA8: nop
    
            goto L_8005EEF4;
    }
    // 0x8005EDA8: nop

L_8005EDAC:
    // 0x8005EDAC: lbu         $t5, 0x123($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X123);
    // 0x8005EDB0: blez        $t5, L_8005EDC4
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8005EDB4: nop
    
            goto L_8005EDC4;
    }
    // 0x8005EDB4: nop

    // 0x8005EDB8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005EDBC: b           L_8005EDD0
    // 0x8005EDC0: sw          $t6, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r14;
        goto L_8005EDD0;
    // 0x8005EDC0: sw          $t6, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r14;
L_8005EDC4:
    // 0x8005EDC4: lw          $t7, 0x130($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X130);
    // 0x8005EDC8: lw          $t8, 0x60($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X60);
    // 0x8005EDCC: sw          $t8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r24;
L_8005EDD0:
    // 0x8005EDD0: lw          $a0, 0x130($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X130);
    // 0x8005EDD4: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8005EDD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005EDDC: jal         0x8005E2FC
    // 0x8005EDE0: lbu         $a3, 0x123($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X123);
    func_8005E2FC(rdram, ctx);
        goto after_0;
    // 0x8005EDE0: lbu         $a3, 0x123($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X123);
    after_0:
    // 0x8005EDE4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8005EDE8: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8005EDEC: beq         $t9, $zero, L_8005EE04
    if (ctx->r25 == 0) {
        // 0x8005EDF0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8005EE04;
    }
    // 0x8005EDF0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005EDF4: beq         $t9, $at, L_8005EE04
    if (ctx->r25 == ctx->r1) {
        // 0x8005EDF8: nop
    
            goto L_8005EE04;
    }
    // 0x8005EDF8: nop

    // 0x8005EDFC: b           L_8005EEF8
    // 0x8005EE00: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_8005EEF8;
    // 0x8005EE00: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8005EE04:
    // 0x8005EE04: lw          $t0, 0x124($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X124);
    // 0x8005EE08: slti        $at, $t0, 0x80
    ctx->r1 = SIGNED(ctx->r8) < 0X80 ? 1 : 0;
    // 0x8005EE0C: beq         $at, $zero, L_8005EED0
    if (ctx->r1 == 0) {
        // 0x8005EE10: sw          $t0, 0x12C($sp)
        MEM_W(0X12C, ctx->r29) = ctx->r8;
            goto L_8005EED0;
    }
    // 0x8005EE10: sw          $t0, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r8;
L_8005EE14:
    // 0x8005EE14: lw          $t2, 0x12C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X12C);
    // 0x8005EE18: addiu       $t4, $sp, 0x20
    ctx->r12 = ADD32(ctx->r29, 0X20);
    // 0x8005EE1C: addiu       $t1, $sp, 0x120
    ctx->r9 = ADD32(ctx->r29, 0X120);
    // 0x8005EE20: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8005EE24: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8005EE28: lhu         $at, 0x0($t5)
    ctx->r1 = MEM_HU(ctx->r13, 0X0);
    // 0x8005EE2C: sh          $at, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r1;
    // 0x8005EE30: lw          $t9, 0x130($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X130);
    // 0x8005EE34: lhu         $t8, 0x120($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X120);
    // 0x8005EE38: lw          $t0, 0x60($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X60);
    // 0x8005EE3C: slt         $at, $t8, $t0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8005EE40: bne         $at, $zero, L_8005EEBC
    if (ctx->r1 != 0) {
        // 0x8005EE44: nop
    
            goto L_8005EEBC;
    }
    // 0x8005EE44: nop

    // 0x8005EE48: lbu         $t2, 0x120($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X120);
    // 0x8005EE4C: lbu         $t3, 0x123($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X123);
    // 0x8005EE50: beq         $t2, $t3, L_8005EEBC
    if (ctx->r10 == ctx->r11) {
        // 0x8005EE54: nop
    
            goto L_8005EEBC;
    }
    // 0x8005EE54: nop

    // 0x8005EE58: lbu         $t4, 0x121($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X121);
    // 0x8005EE5C: lw          $t9, 0x134($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X134);
    // 0x8005EE60: bgez        $t4, L_8005EE70
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8005EE64: sra         $t6, $t4, 2
        ctx->r14 = S32(SIGNED(ctx->r12) >> 2);
            goto L_8005EE70;
    }
    // 0x8005EE64: sra         $t6, $t4, 2
    ctx->r14 = S32(SIGNED(ctx->r12) >> 2);
    // 0x8005EE68: addiu       $at, $t4, 0x3
    ctx->r1 = ADD32(ctx->r12, 0X3);
    // 0x8005EE6C: sra         $t6, $at, 2
    ctx->r14 = S32(SIGNED(ctx->r1) >> 2);
L_8005EE70:
    // 0x8005EE70: bgez        $t2, L_8005EE84
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8005EE74: andi        $t1, $t2, 0x7
        ctx->r9 = ctx->r10 & 0X7;
            goto L_8005EE84;
    }
    // 0x8005EE74: andi        $t1, $t2, 0x7
    ctx->r9 = ctx->r10 & 0X7;
    // 0x8005EE78: beq         $t1, $zero, L_8005EE84
    if (ctx->r9 == 0) {
        // 0x8005EE7C: nop
    
            goto L_8005EE84;
    }
    // 0x8005EE7C: nop

    // 0x8005EE80: addiu       $t1, $t1, -0x8
    ctx->r9 = ADD32(ctx->r9, -0X8);
L_8005EE84:
    // 0x8005EE84: sll         $t5, $t1, 5
    ctx->r13 = S32(ctx->r9 << 5);
    // 0x8005EE88: addu        $t7, $t6, $t5
    ctx->r15 = ADD32(ctx->r14, ctx->r13);
    // 0x8005EE8C: sw          $t7, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r15;
    // 0x8005EE90: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x8005EE94: lbu         $t0, 0x101($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X101);
    // 0x8005EE98: bgez        $t3, L_8005EEAC
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8005EE9C: andi        $t4, $t3, 0x7
        ctx->r12 = ctx->r11 & 0X7;
            goto L_8005EEAC;
    }
    // 0x8005EE9C: andi        $t4, $t3, 0x7
    ctx->r12 = ctx->r11 & 0X7;
    // 0x8005EEA0: beq         $t4, $zero, L_8005EEAC
    if (ctx->r12 == 0) {
        // 0x8005EEA4: nop
    
            goto L_8005EEAC;
    }
    // 0x8005EEA4: nop

    // 0x8005EEA8: addiu       $t4, $t4, -0x8
    ctx->r12 = ADD32(ctx->r12, -0X8);
L_8005EEAC:
    // 0x8005EEAC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8005EEB0: sllv        $t1, $t2, $t4
    ctx->r9 = S32(ctx->r10 << (ctx->r12 & 31));
    // 0x8005EEB4: or          $t6, $t0, $t1
    ctx->r14 = ctx->r8 | ctx->r9;
    // 0x8005EEB8: sb          $t6, 0x101($t8)
    MEM_B(0X101, ctx->r24) = ctx->r14;
L_8005EEBC:
    // 0x8005EEBC: lw          $t5, 0x12C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X12C);
    // 0x8005EEC0: addiu       $t9, $t5, 0x1
    ctx->r25 = ADD32(ctx->r13, 0X1);
    // 0x8005EEC4: slti        $at, $t9, 0x80
    ctx->r1 = SIGNED(ctx->r25) < 0X80 ? 1 : 0;
    // 0x8005EEC8: bne         $at, $zero, L_8005EE14
    if (ctx->r1 != 0) {
        // 0x8005EECC: sw          $t9, 0x12C($sp)
        MEM_W(0X12C, ctx->r29) = ctx->r25;
            goto L_8005EE14;
    }
    // 0x8005EECC: sw          $t9, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r25;
L_8005EED0:
    // 0x8005EED0: lbu         $t7, 0x123($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X123);
    // 0x8005EED4: lw          $t4, 0x130($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X130);
    // 0x8005EED8: addiu       $t3, $t7, 0x1
    ctx->r11 = ADD32(ctx->r15, 0X1);
    // 0x8005EEDC: sb          $t3, 0x123($sp)
    MEM_B(0X123, ctx->r29) = ctx->r11;
    // 0x8005EEE0: lbu         $t0, 0x64($t4)
    ctx->r8 = MEM_BU(ctx->r12, 0X64);
    // 0x8005EEE4: andi        $t2, $t3, 0xFF
    ctx->r10 = ctx->r11 & 0XFF;
    // 0x8005EEE8: slt         $at, $t2, $t0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8005EEEC: bne         $at, $zero, L_8005EDAC
    if (ctx->r1 != 0) {
        // 0x8005EEF0: nop
    
            goto L_8005EDAC;
    }
    // 0x8005EEF0: nop

L_8005EEF4:
    // 0x8005EEF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005EEF8:
    // 0x8005EEF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005EEFC: addiu       $sp, $sp, 0x130
    ctx->r29 = ADD32(ctx->r29, 0X130);
    // 0x8005EF00: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005EF08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005EF08: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8005EF0C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8005EF10: lbu         $t8, 0x34($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X34);
    // 0x8005EF14: lbu         $t6, 0x35($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X35);
    // 0x8005EF18: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8005EF1C: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8005EF20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005EF24: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8005EF28: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8005EF2C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8005EF30: bgez        $t6, L_8005EF40
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8005EF34: sra         $t7, $t6, 2
        ctx->r15 = S32(SIGNED(ctx->r14) >> 2);
            goto L_8005EF40;
    }
    // 0x8005EF34: sra         $t7, $t6, 2
    ctx->r15 = S32(SIGNED(ctx->r14) >> 2);
    // 0x8005EF38: addiu       $at, $t6, 0x3
    ctx->r1 = ADD32(ctx->r14, 0X3);
    // 0x8005EF3C: sra         $t7, $at, 2
    ctx->r15 = S32(SIGNED(ctx->r1) >> 2);
L_8005EF40:
    // 0x8005EF40: bgez        $t8, L_8005EF54
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8005EF44: andi        $t9, $t8, 0x7
        ctx->r25 = ctx->r24 & 0X7;
            goto L_8005EF54;
    }
    // 0x8005EF44: andi        $t9, $t8, 0x7
    ctx->r25 = ctx->r24 & 0X7;
    // 0x8005EF48: beq         $t9, $zero, L_8005EF54
    if (ctx->r25 == 0) {
        // 0x8005EF4C: nop
    
            goto L_8005EF54;
    }
    // 0x8005EF4C: nop

    // 0x8005EF50: addiu       $t9, $t9, -0x8
    ctx->r25 = ADD32(ctx->r25, -0X8);
L_8005EF54:
    // 0x8005EF54: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x8005EF58: addu        $t1, $t7, $t0
    ctx->r9 = ADD32(ctx->r15, ctx->r8);
    // 0x8005EF5C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8005EF60: sb          $zero, 0x23($sp)
    MEM_B(0X23, ctx->r29) = 0;
    // 0x8005EF64: lbu         $t3, 0x64($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X64);
    // 0x8005EF68: blez        $t3, L_8005F0DC
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8005EF6C: nop
    
            goto L_8005F0DC;
    }
    // 0x8005EF6C: nop

L_8005EF70:
    // 0x8005EF70: lbu         $t4, 0x23($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X23);
    // 0x8005EF74: blez        $t4, L_8005EF88
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8005EF78: nop
    
            goto L_8005EF88;
    }
    // 0x8005EF78: nop

    // 0x8005EF7C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8005EF80: b           L_8005EF94
    // 0x8005EF84: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
        goto L_8005EF94;
    // 0x8005EF84: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
L_8005EF88:
    // 0x8005EF88: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8005EF8C: lw          $t8, 0x60($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X60);
    // 0x8005EF90: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
L_8005EF94:
    // 0x8005EF94: lbu         $t9, 0x23($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X23);
    // 0x8005EF98: lbu         $t7, 0x34($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X34);
    // 0x8005EF9C: beq         $t9, $t7, L_8005EFDC
    if (ctx->r25 == ctx->r15) {
        // 0x8005EFA0: nop
    
            goto L_8005EFDC;
    }
    // 0x8005EFA0: nop

    // 0x8005EFA4: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8005EFA8: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8005EFAC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8005EFB0: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8005EFB4: lbu         $t3, 0x101($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X101);
    // 0x8005EFB8: bgez        $t9, L_8005EFCC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8005EFBC: andi        $t4, $t9, 0x7
        ctx->r12 = ctx->r25 & 0X7;
            goto L_8005EFCC;
    }
    // 0x8005EFBC: andi        $t4, $t9, 0x7
    ctx->r12 = ctx->r25 & 0X7;
    // 0x8005EFC0: beq         $t4, $zero, L_8005EFCC
    if (ctx->r12 == 0) {
        // 0x8005EFC4: nop
    
            goto L_8005EFCC;
    }
    // 0x8005EFC4: nop

    // 0x8005EFC8: addiu       $t4, $t4, -0x8
    ctx->r12 = ADD32(ctx->r12, -0X8);
L_8005EFCC:
    // 0x8005EFCC: sllv        $t6, $t5, $t4
    ctx->r14 = S32(ctx->r13 << (ctx->r12 & 31));
    // 0x8005EFD0: and         $t8, $t3, $t6
    ctx->r24 = ctx->r11 & ctx->r14;
    // 0x8005EFD4: beq         $t8, $zero, L_8005F0B8
    if (ctx->r24 == 0) {
        // 0x8005EFD8: nop
    
            goto L_8005F0B8;
    }
    // 0x8005EFD8: nop

L_8005EFDC:
    // 0x8005EFDC: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8005EFE0: lbu         $t7, 0x23($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X23);
    // 0x8005EFE4: lbu         $t1, 0x100($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X100);
    // 0x8005EFE8: beq         $t7, $t1, L_8005F030
    if (ctx->r15 == ctx->r9) {
        // 0x8005EFEC: nop
    
            goto L_8005F030;
    }
    // 0x8005EFEC: nop

    // 0x8005EFF0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8005EFF4: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x8005EFF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005EFFC: jal         0x8005E2FC
    // 0x8005F000: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    func_8005E2FC(rdram, ctx);
        goto after_0;
    // 0x8005F000: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    after_0:
    // 0x8005F004: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8005F008: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8005F00C: beq         $t2, $zero, L_8005F024
    if (ctx->r10 == 0) {
        // 0x8005F010: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8005F024;
    }
    // 0x8005F010: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005F014: beq         $t2, $at, L_8005F024
    if (ctx->r10 == ctx->r1) {
        // 0x8005F018: nop
    
            goto L_8005F024;
    }
    // 0x8005F018: nop

    // 0x8005F01C: b           L_8005F0E0
    // 0x8005F020: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
        goto L_8005F0E0;
    // 0x8005F020: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_8005F024:
    // 0x8005F024: lbu         $t9, 0x23($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X23);
    // 0x8005F028: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8005F02C: sb          $t9, 0x100($t5)
    MEM_B(0X100, ctx->r13) = ctx->r25;
L_8005F030:
    // 0x8005F030: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8005F034: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8005F038: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x8005F03C: beq         $at, $zero, L_8005F0A0
    if (ctx->r1 == 0) {
        // 0x8005F040: sw          $t4, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r12;
            goto L_8005F0A0;
    }
    // 0x8005F040: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x8005F044: slti        $at, $t4, 0x80
    ctx->r1 = SIGNED(ctx->r12) < 0X80 ? 1 : 0;
    // 0x8005F048: beq         $at, $zero, L_8005F0A0
    if (ctx->r1 == 0) {
        // 0x8005F04C: nop
    
            goto L_8005F0A0;
    }
    // 0x8005F04C: nop

L_8005F050:
    // 0x8005F050: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8005F054: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8005F058: lhu         $t2, 0x34($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X34);
    // 0x8005F05C: sll         $t1, $t8, 1
    ctx->r9 = S32(ctx->r24 << 1);
    // 0x8005F060: addu        $t0, $t6, $t1
    ctx->r8 = ADD32(ctx->r14, ctx->r9);
    // 0x8005F064: lhu         $t7, 0x0($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X0);
    // 0x8005F068: bne         $t7, $t2, L_8005F07C
    if (ctx->r15 != ctx->r10) {
        // 0x8005F06C: nop
    
            goto L_8005F07C;
    }
    // 0x8005F06C: nop

    // 0x8005F070: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8005F074: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x8005F078: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
L_8005F07C:
    // 0x8005F07C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8005F080: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8005F084: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005F088: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x8005F08C: beq         $at, $zero, L_8005F0A0
    if (ctx->r1 == 0) {
        // 0x8005F090: sw          $t4, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r12;
            goto L_8005F0A0;
    }
    // 0x8005F090: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x8005F094: slti        $at, $t4, 0x80
    ctx->r1 = SIGNED(ctx->r12) < 0X80 ? 1 : 0;
    // 0x8005F098: bne         $at, $zero, L_8005F050
    if (ctx->r1 != 0) {
        // 0x8005F09C: nop
    
            goto L_8005F050;
    }
    // 0x8005F09C: nop

L_8005F0A0:
    // 0x8005F0A0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8005F0A4: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x8005F0A8: bne         $at, $zero, L_8005F0B8
    if (ctx->r1 != 0) {
        // 0x8005F0AC: nop
    
            goto L_8005F0B8;
    }
    // 0x8005F0AC: nop

    // 0x8005F0B0: b           L_8005F0E0
    // 0x8005F0B4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8005F0E0;
    // 0x8005F0B4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8005F0B8:
    // 0x8005F0B8: lbu         $t1, 0x23($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X23);
    // 0x8005F0BC: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8005F0C0: addiu       $t0, $t1, 0x1
    ctx->r8 = ADD32(ctx->r9, 0X1);
    // 0x8005F0C4: sb          $t0, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r8;
    // 0x8005F0C8: lbu         $t9, 0x64($t2)
    ctx->r25 = MEM_BU(ctx->r10, 0X64);
    // 0x8005F0CC: andi        $t7, $t0, 0xFF
    ctx->r15 = ctx->r8 & 0XFF;
    // 0x8005F0D0: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8005F0D4: bne         $at, $zero, L_8005EF70
    if (ctx->r1 != 0) {
        // 0x8005F0D8: nop
    
            goto L_8005EF70;
    }
    // 0x8005F0D8: nop

L_8005F0DC:
    // 0x8005F0DC: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_8005F0E0:
    // 0x8005F0E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005F0E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8005F0E8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005F0F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005F0F0: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x8005F0F4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005F0F8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8005F0FC: addiu       $v1, $a1, 0x20
    ctx->r3 = ADD32(ctx->r5, 0X20);
    // 0x8005F100: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005F104: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8005F108: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8005F10C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8005F110: lui         $t2, 0xFFFF
    ctx->r10 = S32(0XFFFF << 16);
L_8005F114:
    // 0x8005F114: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005F118: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x8005F11C: lwc1        $f14, 0x4($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8005F120: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8005F124: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8005F128: mul.s       $f16, $f14, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8005F12C: beq         $a0, $t3, L_8005F194
    if (ctx->r4 == ctx->r11) {
        // 0x8005F130: nop
    
            goto L_8005F194;
    }
    // 0x8005F130: nop

L_8005F134:
    // 0x8005F134: mul.s       $f14, $f18, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8005F138: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8005F13C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8005F140: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8005F144: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x8005F148: trunc.w.s   $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8005F14C: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x8005F150: mfc1        $t1, $f12
    ctx->r9 = (int32_t)ctx->f12.u32l;
    // 0x8005F154: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x8005F158: sra         $t9, $t1, 16
    ctx->r25 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8005F15C: andi        $t5, $t9, 0xFFFF
    ctx->r13 = ctx->r25 & 0XFFFF;
    // 0x8005F160: and         $t8, $a1, $t2
    ctx->r24 = ctx->r5 & ctx->r10;
    // 0x8005F164: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x8005F168: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x8005F16C: and         $t9, $t7, $t2
    ctx->r25 = ctx->r15 & ctx->r10;
    // 0x8005F170: sw          $t6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r14;
    // 0x8005F174: andi        $t8, $t1, 0xFFFF
    ctx->r24 = ctx->r9 & 0XFFFF;
    // 0x8005F178: or          $t5, $t9, $t8
    ctx->r13 = ctx->r25 | ctx->r24;
    // 0x8005F17C: sw          $t5, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r13;
    // 0x8005F180: lwc1        $f14, 0x4($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8005F184: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8005F188: mul.s       $f16, $f14, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8005F18C: bne         $a0, $t3, L_8005F134
    if (ctx->r4 != ctx->r11) {
        // 0x8005F190: nop
    
            goto L_8005F134;
    }
    // 0x8005F190: nop

L_8005F194:
    // 0x8005F194: mul.s       $f14, $f18, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8005F198: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x8005F19C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8005F1A0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8005F1A4: trunc.w.s   $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8005F1A8: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x8005F1AC: mfc1        $t1, $f12
    ctx->r9 = (int32_t)ctx->f12.u32l;
    // 0x8005F1B0: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x8005F1B4: sra         $t9, $t1, 16
    ctx->r25 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8005F1B8: andi        $t5, $t9, 0xFFFF
    ctx->r13 = ctx->r25 & 0XFFFF;
    // 0x8005F1BC: and         $t8, $a1, $t2
    ctx->r24 = ctx->r5 & ctx->r10;
    // 0x8005F1C0: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x8005F1C4: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x8005F1C8: and         $t9, $t7, $t2
    ctx->r25 = ctx->r15 & ctx->r10;
    // 0x8005F1CC: andi        $t8, $t1, 0xFFFF
    ctx->r24 = ctx->r9 & 0XFFFF;
    // 0x8005F1D0: sw          $t6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r14;
    // 0x8005F1D4: or          $t5, $t9, $t8
    ctx->r13 = ctx->r25 | ctx->r24;
    // 0x8005F1D8: sw          $t5, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r13;
    // 0x8005F1DC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8005F1E0: bne         $a2, $t4, L_8005F114
    if (ctx->r6 != ctx->r12) {
        // 0x8005F1E4: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8005F114;
    }
    // 0x8005F1E4: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8005F1E8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005F1F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005F1F0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005F1F4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8005F1F8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005F1FC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8005F200: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8005F204: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005F208: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x8005F20C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8005F210: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_8005F214:
    // 0x8005F214: bnel        $v0, $zero, L_8005F228
    if (ctx->r2 != 0) {
        // 0x8005F218: swc1        $f2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
            goto L_8005F228;
    }
    goto skip_0;
    // 0x8005F218: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
    skip_0:
    // 0x8005F21C: b           L_8005F228
    // 0x8005F220: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
        goto L_8005F228;
    // 0x8005F220: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x8005F224: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
L_8005F228:
    // 0x8005F228: bnel        $v0, $a0, L_8005F23C
    if (ctx->r2 != ctx->r4) {
        // 0x8005F22C: swc1        $f2, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
            goto L_8005F23C;
    }
    goto skip_1;
    // 0x8005F22C: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    skip_1:
    // 0x8005F230: b           L_8005F23C
    // 0x8005F234: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
        goto L_8005F23C;
    // 0x8005F234: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x8005F238: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
L_8005F23C:
    // 0x8005F23C: bnel        $v0, $a1, L_8005F250
    if (ctx->r2 != ctx->r5) {
        // 0x8005F240: swc1        $f2, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
            goto L_8005F250;
    }
    goto skip_2;
    // 0x8005F240: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
    skip_2:
    // 0x8005F244: b           L_8005F250
    // 0x8005F248: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
        goto L_8005F250;
    // 0x8005F248: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x8005F24C: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
L_8005F250:
    // 0x8005F250: bnel        $v0, $a2, L_8005F264
    if (ctx->r2 != ctx->r6) {
        // 0x8005F254: swc1        $f2, 0xC($v1)
        MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
            goto L_8005F264;
    }
    goto skip_3;
    // 0x8005F254: swc1        $f2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
    skip_3:
    // 0x8005F258: b           L_8005F264
    // 0x8005F25C: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
        goto L_8005F264;
    // 0x8005F25C: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
    // 0x8005F260: swc1        $f2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
L_8005F264:
    // 0x8005F264: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005F268: bne         $v0, $a3, L_8005F214
    if (ctx->r2 != ctx->r7) {
        // 0x8005F26C: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_8005F214;
    }
    // 0x8005F26C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8005F270: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005F278(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005F278: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8005F27C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005F280: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8005F284: jal         0x8005F1F0
    // 0x8005F288: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_8005F1F0(rdram, ctx);
        goto after_0;
    // 0x8005F288: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x8005F28C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8005F290: jal         0x8005F0F0
    // 0x8005F294: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    func_8005F0F0(rdram, ctx);
        goto after_1;
    // 0x8005F294: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_1:
    // 0x8005F298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005F29C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8005F2A0: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005F2A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005F2A8: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x8005F2AC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005F2B0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8005F2B4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8005F2B8: addiu       $v1, $a1, 0x20
    ctx->r3 = ADD32(ctx->r5, 0X20);
    // 0x8005F2BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005F2C0: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x8005F2C4: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8005F2C8: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8005F2CC: lui         $t2, 0xFFFF
    ctx->r10 = S32(0XFFFF << 16);
L_8005F2D0:
    // 0x8005F2D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005F2D4: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
L_8005F2D8:
    // 0x8005F2D8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8005F2DC: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8005F2E0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8005F2E4: srl         $t7, $t6, 16
    ctx->r15 = S32(U32(ctx->r14) >> 16);
    // 0x8005F2E8: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8005F2EC: and         $t5, $t9, $t2
    ctx->r13 = ctx->r25 & ctx->r10;
    // 0x8005F2F0: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x8005F2F4: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x8005F2F8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8005F2FC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8005F300: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8005F304: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x8005F308: sll         $t5, $t8, 16
    ctx->r13 = S32(ctx->r24 << 16);
    // 0x8005F30C: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
    // 0x8005F310: and         $t6, $t5, $t2
    ctx->r14 = ctx->r13 & ctx->r10;
    // 0x8005F314: or          $a3, $t9, $t6
    ctx->r7 = ctx->r25 | ctx->r14;
    // 0x8005F318: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8005F31C: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x8005F320: sw          $a3, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r7;
    // 0x8005F324: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8005F328: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8005F32C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8005F330: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x8005F334: div.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8005F338: div.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8005F33C: swc1        $f18, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->f18.u32l;
    // 0x8005F340: bne         $a0, $t3, L_8005F2D8
    if (ctx->r4 != ctx->r11) {
        // 0x8005F344: swc1        $f16, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->f16.u32l;
            goto L_8005F2D8;
    }
    // 0x8005F344: swc1        $f16, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->f16.u32l;
    // 0x8005F348: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8005F34C: bne         $a2, $t4, L_8005F2D0
    if (ctx->r6 != ctx->r12) {
        // 0x8005F350: addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
            goto L_8005F2D0;
    }
    // 0x8005F350: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x8005F354: jr          $ra
    // 0x8005F358: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    TRACE_RETURN()
    return;
    // 0x8005F358: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8005F360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
;}
RECOMP_FUNC void func_8005F370(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
;}
RECOMP_FUNC void func_8005F380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005F380: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x8005F384: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x8005F388: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005F390(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005F390: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005F394: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005F398: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8005F39C: jal         0x800629A0
    // 0x8005F3A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800629A0(rdram, ctx);
        goto after_0;
    // 0x8005F3A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8005F3A4: beq         $v0, $zero, L_8005F3B4
    if (ctx->r2 == 0) {
        // 0x8005F3A8: nop
    
            goto L_8005F3B4;
    }
    // 0x8005F3A8: nop

    // 0x8005F3AC: b           L_8005F3D0
    // 0x8005F3B0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8005F3D0;
    // 0x8005F3B0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8005F3B4:
    // 0x8005F3B4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8005F3B8: lui         $at, 0xA000
    ctx->r1 = S32(0XA000 << 16);
    // 0x8005F3BC: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8005F3C0: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8005F3C4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8005F3C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005F3CC: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
L_8005F3D0:
    // 0x8005F3D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005F3D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005F3D8: jr          $ra
    TRACE_RETURN()
    return;
;}
