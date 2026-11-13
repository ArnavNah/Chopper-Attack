#include "recomp.h"
#include "trace.h"
#include "funcs.h"

extern void runtime_log(const char* fmt, ...);
extern void set_game_client_registered(int registered);

RECOMP_FUNC void func_80053038(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80053038: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005303C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80053040: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80053044: lw          $v1, 0x260($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X260);
    // 0x80053048: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8005304C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80053050: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80053054: jal         0x80059290
    // 0x80053058: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80053058: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8005305C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80053060: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80053064: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80053068: beq         $v1, $zero, L_800530A8
    if (ctx->r3 == 0) {
        // 0x8005306C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800530A8;
    }
    // 0x8005306C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80053070:
    // 0x80053070: bnel        $v1, $a1, L_8005309C
    if (ctx->r3 != ctx->r5) {
        // 0x80053074: or          $a2, $v1, $zero
        ctx->r6 = ctx->r3 | 0;
            goto L_8005309C;
    }
    goto skip_0;
    // 0x80053074: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    skip_0:
    // 0x80053078: beq         $a2, $zero, L_8005308C
    if (ctx->r6 == 0) {
        // 0x8005307C: lw          $t9, 0x20($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X20);
            goto L_8005308C;
    }
    // 0x8005307C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80053080: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80053084: b           L_800530A8
    // 0x80053088: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
        goto L_800530A8;
    // 0x80053088: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
L_8005308C:
    // 0x8005308C: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80053090: b           L_800530A8
    // 0x80053094: sw          $t8, 0x260($t9)
    MEM_W(0X260, ctx->r25) = ctx->r24;
        goto L_800530A8;
    // 0x80053094: sw          $t8, 0x260($t9)
    MEM_W(0X260, ctx->r25) = ctx->r24;
    // 0x80053098: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_8005309C:
    // 0x8005309C: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800530A0: bne         $v1, $zero, L_80053070
    if (ctx->r3 != 0) {
        // 0x800530A4: nop
    
            goto L_80053070;
    }
    // 0x800530A4: nop

L_800530A8:
    // 0x800530A8: jal         0x80059290
    // 0x800530AC: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800530AC: nop

    after_1:
    // 0x800530B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800530B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800530B8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800530C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    runtime_log("[Scheduler] osScAddClient: sc=0x%08X, client=0x%08X, mq=0x%08X", (uint32_t)ctx->r4, (uint32_t)ctx->r5, (uint32_t)ctx->r6);
    if ((uint32_t)ctx->r6 == 0x800DE360) {
        runtime_log("[Scheduler] osScAddClient: Registered game graphics queue 0x800DE360!");
        extern void register_gfx_message_queue(uint32_t mq);
        register_gfx_message_queue(0x800DE360);
    }
    // 0x800530C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800530C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800530C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800530CC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800530D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800530D4: jal         0x80059290
    // 0x800530D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800530D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800530DC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800530E0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800530E4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800530E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800530EC: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x800530F0: lw          $t7, 0x260($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X260);
    // 0x800530F4: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800530F8: jal         0x80059290
    // 0x800530FC: sw          $a1, 0x260($v1)
    MEM_W(0X260, ctx->r3) = ctx->r5;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800530FC: sw          $a1, 0x260($v1)
    MEM_W(0X260, ctx->r3) = ctx->r5;
    after_1:
    // 0x80053100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80053104: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80053108: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80053110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80053110: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80053114: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80053118: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8005311C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80053120: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80053124: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80053128: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8005312C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80053130: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80053134: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80053138: sw          $zero, 0x274($a0)
    MEM_W(0X274, ctx->r4) = 0;
    // 0x8005313C: sw          $zero, 0x278($a0)
    MEM_W(0X278, ctx->r4) = 0;
    // 0x80053140: sw          $zero, 0x260($a0)
    MEM_W(0X260, ctx->r4) = 0;
    // 0x80053144: sw          $zero, 0x27C($a0)
    MEM_W(0X27C, ctx->r4) = 0;
    // 0x80053148: sw          $zero, 0x264($a0)
    MEM_W(0X264, ctx->r4) = 0;
    // 0x8005314C: sw          $zero, 0x268($a0)
    MEM_W(0X268, ctx->r4) = 0;
    // 0x80053150: sw          $zero, 0x26C($a0)
    MEM_W(0X26C, ctx->r4) = 0;
    // 0x80053154: sw          $zero, 0x270($a0)
    MEM_W(0X270, ctx->r4) = 0;
    // 0x80053158: sh          $t6, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r14;
    // 0x8005315C: sh          $t7, 0x20($a0)
    MEM_H(0X20, ctx->r4) = ctx->r15;
    // 0x80053160: addiu       $s1, $a0, 0x40
    ctx->r17 = ADD32(ctx->r4, 0X40);
    // 0x80053164: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80053168: addiu       $a1, $s0, 0x58
    ctx->r5 = ADD32(ctx->r16, 0X58);
    // 0x8005316C: jal         0x80052780
    // 0x80053170: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80053170: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x80053174: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    // 0x80053178: addiu       $a1, $s0, 0x90
    ctx->r5 = ADD32(ctx->r16, 0X90);
    // 0x8005317C: jal         0x80052780
    // 0x80053180: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x80053180: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
    // 0x80053184: jal         0x800593D0
    // 0x80053188: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    osCreateViManager_recomp(rdram, ctx);
        goto after_2;
    // 0x80053188: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    after_2:
    // 0x8005318C: lbu         $t8, 0x37($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X37);
    // 0x80053190: lui         $t0, 0x8007
    ctx->r8 = S32(0X8007 << 16);
    // 0x80053194: addiu       $t0, $t0, 0x3290
    ctx->r8 = ADD32(ctx->r8, 0X3290);
    // 0x80053198: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8005319C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800531A0: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x800531A4: jal         0x80059730
    // 0x800531A8: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    osViSetMode_recomp(rdram, ctx);
        goto after_3;
    // 0x800531A8: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    after_3:
    // 0x800531AC: jal         0x80053630
    // 0x800531B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osViBlack_recomp(rdram, ctx);
        goto after_4;
    // 0x800531B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x800531B4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800531B8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800531BC: jal         0x800547C0
    // 0x800531C0: addiu       $a2, $zero, 0x29B
    ctx->r6 = ADD32(0, 0X29B);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x800531C0: addiu       $a2, $zero, 0x29B
    ctx->r6 = ADD32(0, 0X29B);
    after_5:
    // 0x800531C4: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x800531C8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800531CC: jal         0x800547C0
    // 0x800531D0: addiu       $a2, $zero, 0x29C
    ctx->r6 = ADD32(0, 0X29C);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_6;
    // 0x800531D0: addiu       $a2, $zero, 0x29C
    ctx->r6 = ADD32(0, 0X29C);
    after_6:
    // 0x800531D4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x800531D8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800531DC: jal         0x800547C0
    // 0x800531E0: addiu       $a2, $zero, 0x29D
    ctx->r6 = ADD32(0, 0X29D);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_7;
    // 0x800531E0: addiu       $a2, $zero, 0x29D
    ctx->r6 = ADD32(0, 0X29D);
    after_7:
    // 0x800531E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800531E8: addiu       $a1, $zero, 0x29A
    ctx->r5 = ADD32(0, 0X29A);
    // 0x800531EC: jal         0x800597A0
    // 0x800531F0: lbu         $a2, 0x3B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X3B);
    osViSetEvent_recomp(rdram, ctx);
        goto after_8;
    // 0x800531F0: lbu         $a2, 0x3B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X3B);
    after_8:
    // 0x800531F4: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800531F8: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800531FC: addiu       $s1, $s0, 0xB0
    ctx->r17 = ADD32(ctx->r16, 0XB0);
    // 0x80053200: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80053204: addiu       $a2, $a2, 0x2E04
    ctx->r6 = ADD32(ctx->r6, 0X2E04);
    // 0x80053208: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005320C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80053210: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80053214: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80053218: jal         0x800527B0
    // 0x8005321C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    osCreateThread_recomp(rdram, ctx);
        goto after_9;
    // 0x8005321C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_9:
    // 0x80053220: jal         0x80052570
    // 0x80053224: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    osStartThread_recomp(rdram, ctx);
        goto after_10;
    // 0x80053224: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x80053228: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005322C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80053230: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80053234: jr          $ra
    // 0x80053238: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    TRACE_RETURN()
    return;
    // 0x80053238: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80053240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80053240: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x80053244: lw          $v1, 0x40($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X40);
    // 0x80053248: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8005324C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80053250: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80053254: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80053258: jr          $ra
    // 0x8005325C: lw          $v0, 0x28($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X28);
    TRACE_RETURN()
    return;
    // 0x8005325C: lw          $v0, 0x28($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X28);
;}
RECOMP_FUNC void func_80053260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80053260: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80053264: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80053268: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x8005326C: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80053270: sh          $t6, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r14;
    // 0x80053274: lw          $t7, 0x3C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X3C);
    // 0x80053278: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8005327C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80053280: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80053284: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80053288: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x8005328C: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x80053290: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80053294: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x80053298: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005329C: jal         0x8005702C
    // 0x800532A0: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    func_8005702C(rdram, ctx);
        goto after_0;
    // 0x800532A0: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x800532A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800532A8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800532AC: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800532C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800532C0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800532C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800532C8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800532CC: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x800532D0: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x800532D4: sh          $t6, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r14;
    // 0x800532D8: lw          $t7, 0x3C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X3C);
    // 0x800532DC: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x800532E0: sb          $t0, 0x28($sp)
    MEM_B(0X28, ctx->r29) = ctx->r8;
    // 0x800532E4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800532E8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800532EC: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x800532F0: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800532F4: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x800532F8: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800532FC: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x80053300: jal         0x8005702C
    // 0x80053304: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8005702C(rdram, ctx);
        goto after_0;
    // 0x80053304: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80053308: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005330C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80053310: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80053320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80053320: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80053324: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80053328: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8005332C: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x80053330: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x80053334: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80053338: sh          $t6, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r14;
    // 0x8005333C: sb          $t0, 0x28($sp)
    MEM_B(0X28, ctx->r29) = ctx->r8;
    // 0x80053340: lw          $t7, 0x3C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X3C);
    // 0x80053344: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80053348: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x8005334C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80053350: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80053354: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80053358: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8005335C: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80053360: jal         0x8005702C
    // 0x80053364: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8005702C(rdram, ctx);
        goto after_0;
    // 0x80053364: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80053368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005336C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80053370: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80053380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80053380: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80053384: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80053388: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8005338C: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x80053390: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80053394: sh          $t7, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r15;
    // 0x80053398: lw          $t8, 0x3C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X3C);
    // 0x8005339C: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x800533A0: sh          $t6, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r14;
    // 0x800533A4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800533A8: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800533AC: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x800533B0: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x800533B4: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x800533B8: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800533BC: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x800533C0: jal         0x8005702C
    // 0x800533C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8005702C(rdram, ctx);
        goto after_0;
    // 0x800533C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800533C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800533CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800533D0: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800533E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800533E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800533E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800533E8: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x800533EC: addiu       $v1, $zero, 0x30
    ctx->r3 = ADD32(0, 0X30);
    // 0x800533F0: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x800533F4: multu       $t6, $v1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800533F8: mflo        $t7
    ctx->r15 = lo;
    // 0x800533FC: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80053400: lw          $t9, 0x28($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X28);
    // 0x80053404: bnel        $t9, $zero, L_80053438
    if (ctx->r25 != 0) {
        // 0x80053408: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80053438;
    }
    goto skip_0;
    // 0x80053408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8005340C: sh          $zero, 0x20($sp)
    MEM_H(0X20, ctx->r29) = 0;
    // 0x80053410: lw          $t0, 0x3C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X3C);
    // 0x80053414: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x80053418: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8005341C: multu       $t0, $v1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80053420: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80053424: mflo        $t1
    ctx->r9 = lo;
    // 0x80053428: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x8005342C: jal         0x8005702C
    // 0x80053430: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    func_8005702C(rdram, ctx);
        goto after_0;
    // 0x80053430: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    after_0:
    // 0x80053434: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80053438:
    // 0x80053438: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8005343C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80053450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80053450: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80053454: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80053458: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x8005345C: sh          $zero, 0x20($sp)
    MEM_H(0X20, ctx->r29) = 0;
    // 0x80053460: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x80053464: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80053468: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8005346C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80053470: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80053474: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80053478: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8005347C: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80053480: jal         0x8005702C
    // 0x80053484: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    func_8005702C(rdram, ctx);
        goto after_0;
    // 0x80053484: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_0:
    // 0x80053488: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005348C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80053490: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800535F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800535F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800535F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800535F8: addiu       $t6, $zero, 0x11
    ctx->r14 = ADD32(0, 0X11);
    // 0x800535FC: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x80053600: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80053604: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x80053608: jal         0x8005702C
    // 0x8005360C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8005702C(rdram, ctx);
        goto after_0;
    // 0x8005360C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80053610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80053614: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80053618: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80053620(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80053620: jr          $ra
    // 0x80053624: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    TRACE_RETURN()
    return;
    // 0x80053624: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
;}
RECOMP_FUNC void func_800537E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800537E8: lw          $t6, 0x44($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X44);
    // 0x800537EC: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x800537F0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800537F4: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800537F8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800537FC: ldc1        $f4, -0x6C50($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X6C50);
    // 0x80053800: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80053804: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80053808: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x8005380C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80053810: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80053814: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80053818: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8005381C: div.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x80053820: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x80053824: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x80053828: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005382C: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x80053830: nop

    // 0x80053834: and         $t8, $v0, $at
    ctx->r24 = ctx->r2 & ctx->r1;
    // 0x80053838: jr          $ra
    // 0x8005383C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    TRACE_RETURN()
    return;
    // 0x8005383C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
;}
RECOMP_FUNC void func_80053840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80053840: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80053844: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80053848: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8005384C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80053850: jal         0x800526C0
    // 0x80053854: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800526C0(rdram, ctx);
        goto after_0;
    // 0x80053854: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80053858: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8005385C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80053860: jal         0x800526F0
    // 0x80053864: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    func_800526F0(rdram, ctx);
        goto after_1;
    // 0x80053864: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    after_1:
    // 0x80053868: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005386C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80053870: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80053878(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80053878: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005387C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80053880: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80053884: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80053888: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005388C: lw          $s0, 0x14($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X14);
    // 0x80053890: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80053894: addiu       $s2, $a0, 0x4
    ctx->r18 = ADD32(ctx->r4, 0X4);
    // 0x80053898: beql        $s0, $zero, L_800538C4
    if (ctx->r16 == 0) {
        // 0x8005389C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800538C4;
    }
    goto skip_0;
    // 0x8005389C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
L_800538A0:
    // 0x800538A0: jal         0x800526C0
    // 0x800538A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800526C0(rdram, ctx);
        goto after_0;
    // 0x800538A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800538A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800538AC: jal         0x800526F0
    // 0x800538B0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800526F0(rdram, ctx);
        goto after_1;
    // 0x800538B0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x800538B4: lw          $s0, 0x14($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X14);
    // 0x800538B8: bne         $s0, $zero, L_800538A0
    if (ctx->r16 != 0) {
        // 0x800538BC: nop
    
            goto L_800538A0;
    }
    // 0x800538BC: nop

    // 0x800538C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800538C4:
    // 0x800538C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800538C8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800538CC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800538D0: jr          $ra
    // 0x800538D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    TRACE_RETURN()
    return;
    // 0x800538D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800538D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800538D8: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x800538DC: lw          $v0, 0x3190($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3190);
    // 0x800538E0: lw          $t6, 0x2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C);
    // 0x800538E4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800538E8: jr          $ra
    // 0x800538EC: sw          $a0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r4;
    TRACE_RETURN()
    return;
    // 0x800538EC: sw          $a0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r4;
;}
RECOMP_FUNC void func_800538F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800538F0: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x800538F4: lw          $v0, 0x3190($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3190);
    // 0x800538F8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800538FC: lw          $a0, 0x2C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X2C);
    // 0x80053900: beq         $a0, $zero, L_80053918
    if (ctx->r4 == 0) {
        // 0x80053904: nop
    
            goto L_80053918;
    }
    // 0x80053904: nop

    // 0x80053908: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005390C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80053910: sw          $t6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r14;
    // 0x80053914: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_80053918:
    // 0x80053918: jr          $ra
    // 0x8005391C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    TRACE_RETURN()
    return;
    // 0x8005391C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80053920(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80053920: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80053928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80053928: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x8005392C: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80053930: lui         $s1, 0x8007
    ctx->r17 = S32(0X8007 << 16);
    // 0x80053934: lw          $s1, 0x3190($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X3190);
    // 0x80053938: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8005393C: sw          $s7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r23;
    // 0x80053940: sw          $s6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r22;
    // 0x80053944: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x80053948: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x8005394C: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x80053950: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x80053954: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80053958: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8005395C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80053960: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    // 0x80053964: sw          $a1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r5;
    // 0x80053968: sh          $zero, 0xAA($sp)
    MEM_H(0XAA, ctx->r29) = 0;
    // 0x8005396C: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80053970: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x80053974: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80053978: bne         $t7, $zero, L_8005398C
    if (ctx->r15 != 0) {
        // 0x8005397C: or          $s5, $a2, $zero
        ctx->r21 = ctx->r6 | 0;
            goto L_8005398C;
    }
    // 0x8005397C: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x80053980: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x80053984: b           L_80053B8C
    // 0x80053988: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_80053B8C;
    // 0x80053988: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8005398C:
    // 0x8005398C: sw          $zero, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = 0;
    // 0x80053990: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80053994: lui         $v1, 0x7FFF
    ctx->r3 = S32(0X7FFF << 16);
    // 0x80053998: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x8005399C: beq         $v0, $zero, L_800539D8
    if (ctx->r2 == 0) {
        // 0x800539A0: addiu       $s2, $zero, -0x10
        ctx->r18 = ADD32(0, -0X10);
            goto L_800539D8;
    }
    // 0x800539A0: addiu       $s2, $zero, -0x10
    ctx->r18 = ADD32(0, -0X10);
    // 0x800539A4: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x800539A8: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
L_800539AC:
    // 0x800539AC: subu        $t0, $t9, $a0
    ctx->r8 = SUB32(ctx->r25, ctx->r4);
    // 0x800539B0: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800539B4: beql        $at, $zero, L_800539D0
    if (ctx->r1 == 0) {
        // 0x800539B8: lw          $v0, 0x0($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X0);
            goto L_800539D0;
    }
    goto skip_0;
    // 0x800539B8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x800539BC: sw          $v0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r2;
    // 0x800539C0: lw          $t1, 0x10($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X10);
    // 0x800539C4: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x800539C8: subu        $v1, $t1, $a0
    ctx->r3 = SUB32(ctx->r9, ctx->r4);
    // 0x800539CC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
L_800539D0:
    // 0x800539D0: bnel        $v0, $zero, L_800539AC
    if (ctx->r2 != 0) {
        // 0x800539D4: lw          $t9, 0x10($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X10);
            goto L_800539AC;
    }
    goto skip_1;
    // 0x800539D4: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
    skip_1:
L_800539D8:
    // 0x800539D8: lw          $t2, 0xB4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB4);
    // 0x800539DC: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x800539E0: lw          $v0, 0x10($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X10);
    // 0x800539E4: subu        $t3, $v0, $a0
    ctx->r11 = SUB32(ctx->r2, ctx->r4);
    // 0x800539E8: slt         $at, $t3, $s3
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800539EC: beq         $at, $zero, L_80053AD0
    if (ctx->r1 == 0) {
        // 0x800539F0: sw          $v0, 0x1C($s1)
        MEM_W(0X1C, ctx->r17) = ctx->r2;
            goto L_80053AD0;
    }
    // 0x800539F0: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
    // 0x800539F4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800539F8: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x800539FC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80053A00: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80053A04: ldc1        $f20, -0x6C48($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, -0X6C48);
L_80053A08:
    // 0x80053A08: lw          $t4, 0x1C($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X1C);
    // 0x80053A0C: lui         $s0, 0x7FFF
    ctx->r16 = S32(0X7FFF << 16);
    // 0x80053A10: ori         $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 | 0XFFFF;
    // 0x80053A14: and         $t5, $t4, $s2
    ctx->r13 = ctx->r12 & ctx->r18;
    // 0x80053A18: sw          $t5, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r13;
    // 0x80053A1C: lw          $a0, 0xB4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB4);
    // 0x80053A20: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x80053A24: jalr        $t9
    // 0x80053A28: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80053A28: nop

    after_0:
    // 0x80053A2C: lw          $t8, 0x44($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X44);
    // 0x80053A30: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80053A34: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
    // 0x80053A38: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80053A3C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80053A40: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x80053A44: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80053A48: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80053A4C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80053A50: div.d       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f20.d);
    // 0x80053A54: add.d       $f8, $f4, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f22.d); 
    ctx->f8.d = ctx->f4.d + ctx->f22.d;
    // 0x80053A58: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x80053A5C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80053A60: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80053A64: nop

    // 0x80053A68: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x80053A6C: sw          $t2, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r10;
    // 0x80053A70: sw          $zero, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = 0;
    // 0x80053A74: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80053A78: beql        $v1, $zero, L_80053AB8
    if (ctx->r3 == 0) {
        // 0x80053A7C: lw          $t7, 0xB4($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XB4);
            goto L_80053AB8;
    }
    goto skip_2;
    // 0x80053A7C: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    skip_2:
    // 0x80053A80: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x80053A84: lw          $t3, 0x10($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X10);
L_80053A88:
    // 0x80053A88: subu        $t4, $t3, $a0
    ctx->r12 = SUB32(ctx->r11, ctx->r4);
    // 0x80053A8C: slt         $at, $t4, $s0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80053A90: beql        $at, $zero, L_80053AAC
    if (ctx->r1 == 0) {
        // 0x80053A94: lw          $v1, 0x0($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X0);
            goto L_80053AAC;
    }
    goto skip_3;
    // 0x80053A94: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    skip_3:
    // 0x80053A98: sw          $v1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r3;
    // 0x80053A9C: lw          $t5, 0x10($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X10);
    // 0x80053AA0: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x80053AA4: subu        $s0, $t5, $a0
    ctx->r16 = SUB32(ctx->r13, ctx->r4);
    // 0x80053AA8: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
L_80053AAC:
    // 0x80053AAC: bnel        $v1, $zero, L_80053A88
    if (ctx->r3 != 0) {
        // 0x80053AB0: lw          $t3, 0x10($v1)
        ctx->r11 = MEM_W(ctx->r3, 0X10);
            goto L_80053A88;
    }
    goto skip_4;
    // 0x80053AB0: lw          $t3, 0x10($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X10);
    skip_4:
    // 0x80053AB4: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
L_80053AB8:
    // 0x80053AB8: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x80053ABC: lw          $v0, 0x10($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X10);
    // 0x80053AC0: subu        $t9, $v0, $a0
    ctx->r25 = SUB32(ctx->r2, ctx->r4);
    // 0x80053AC4: slt         $at, $t9, $s3
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80053AC8: bne         $at, $zero, L_80053A08
    if (ctx->r1 != 0) {
        // 0x80053ACC: sw          $v0, 0x1C($s1)
        MEM_W(0X1C, ctx->r17) = ctx->r2;
            goto L_80053A08;
    }
    // 0x80053ACC: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
L_80053AD0:
    // 0x80053AD0: lw          $t8, 0x1C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X1C);
    // 0x80053AD4: addiu       $s2, $zero, -0x10
    ctx->r18 = ADD32(0, -0X10);
    // 0x80053AD8: addiu       $s7, $sp, 0xAA
    ctx->r23 = ADD32(ctx->r29, 0XAA);
    // 0x80053ADC: and         $t6, $t8, $s2
    ctx->r14 = ctx->r24 & ctx->r18;
    // 0x80053AE0: blez        $s3, L_80053B6C
    if (SIGNED(ctx->r19) <= 0) {
        // 0x80053AE4: sw          $t6, 0x1C($s1)
        MEM_W(0X1C, ctx->r17) = ctx->r14;
            goto L_80053B6C;
    }
    // 0x80053AE4: sw          $t6, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r14;
    // 0x80053AE8: lui         $s6, 0x700
    ctx->r22 = S32(0X700 << 16);
L_80053AEC:
    // 0x80053AEC: lw          $v0, 0x48($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X48);
    // 0x80053AF0: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
    // 0x80053AF4: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80053AF8: beq         $at, $zero, L_80053B08
    if (ctx->r1 == 0) {
        // 0x80053AFC: nop
    
            goto L_80053B08;
    }
    // 0x80053AFC: nop

    // 0x80053B00: b           L_80053B08
    // 0x80053B04: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_80053B08;
    // 0x80053B04: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80053B08:
    // 0x80053B08: sw          $s6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r22;
    // 0x80053B0C: sw          $zero, 0x4($s4)
    MEM_W(0X4, ctx->r20) = 0;
    // 0x80053B10: lw          $s2, 0x38($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X38);
    // 0x80053B14: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80053B18: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80053B1C: lw          $t9, 0x8($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X8);
    // 0x80053B20: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80053B24: jalr        $t9
    // 0x80053B28: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80053B28: nop

    after_1:
    // 0x80053B2C: lw          $a3, 0x20($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X20);
    // 0x80053B30: addiu       $t1, $s4, 0x8
    ctx->r9 = ADD32(ctx->r20, 0X8);
    // 0x80053B34: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80053B38: lw          $t9, 0x4($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X4);
    // 0x80053B3C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80053B40: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x80053B44: jalr        $t9
    // 0x80053B48: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80053B48: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_2:
    // 0x80053B4C: lw          $t3, 0x20($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X20);
    // 0x80053B50: subu        $s3, $s3, $s0
    ctx->r19 = SUB32(ctx->r19, ctx->r16);
    // 0x80053B54: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x80053B58: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x80053B5C: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80053B60: addu        $s5, $s5, $t0
    ctx->r21 = ADD32(ctx->r21, ctx->r8);
    // 0x80053B64: bgtz        $s3, L_80053AEC
    if (SIGNED(ctx->r19) > 0) {
        // 0x80053B68: sw          $t4, 0x20($s1)
        MEM_W(0X20, ctx->r17) = ctx->r12;
            goto L_80053AEC;
    }
    // 0x80053B68: sw          $t4, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r12;
L_80053B6C:
    // 0x80053B6C: lw          $t5, 0xB8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB8);
    // 0x80053B70: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x80053B74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80053B78: subu        $t7, $s4, $t5
    ctx->r15 = SUB32(ctx->r20, ctx->r13);
    // 0x80053B7C: sra         $t8, $t7, 3
    ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
    // 0x80053B80: jal         0x80053878
    // 0x80053B84: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    func_80053878(rdram, ctx);
        goto after_3;
    // 0x80053B84: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    after_3:
    // 0x80053B88: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
L_80053B8C:
    // 0x80053B8C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80053B90: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80053B94: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80053B98: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80053B9C: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80053BA0: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x80053BA4: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x80053BA8: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x80053BAC: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x80053BB0: lw          $s6, 0x44($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X44);
    // 0x80053BB4: lw          $s7, 0x48($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X48);
    // 0x80053BB8: jr          $ra
    // 0x80053BBC: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    TRACE_RETURN()
    return;
    // 0x80053BBC: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void func_80053BC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80053BC0: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80053BC4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80053BC8: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80053BCC: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80053BD0: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80053BD4: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80053BD8: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80053BDC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80053BE0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80053BE4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80053BE8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80053BEC: lw          $s7, 0x14($a1)
    ctx->r23 = MEM_W(ctx->r5, 0X14);
    // 0x80053BF0: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80053BF4: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x80053BF8: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    // 0x80053BFC: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x80053C00: sw          $t6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r14;
    // 0x80053C04: lw          $t7, 0x18($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X18);
    // 0x80053C08: addiu       $t8, $zero, 0xA0
    ctx->r24 = ADD32(0, 0XA0);
    // 0x80053C0C: sw          $t8, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r24;
    // 0x80053C10: sw          $t7, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r15;
    // 0x80053C14: lw          $t9, 0x10($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X10);
    // 0x80053C18: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80053C1C: or          $fp, $a1, $zero
    ctx->r30 = ctx->r5 | 0;
    // 0x80053C20: addiu       $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
    // 0x80053C24: sw          $t9, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r25;
    // 0x80053C28: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80053C2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80053C30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80053C34: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80053C38: jal         0x800507E0
    // 0x80053C3C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    func_800507E0(rdram, ctx);
        goto after_0;
    // 0x80053C3C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_0:
    // 0x80053C40: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80053C44: jal         0x80059F80
    // 0x80053C48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80059F80(rdram, ctx);
        goto after_1;
    // 0x80053C48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80053C4C: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80053C50: addiu       $t2, $zero, 0x4C
    ctx->r10 = ADD32(0, 0X4C);
    // 0x80053C54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80053C58: sw          $t1, 0x38($s6)
    MEM_W(0X38, ctx->r22) = ctx->r9;
    // 0x80053C5C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80053C60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80053C64: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x80053C68: jal         0x800507E0
    // 0x80053C6C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800507E0(rdram, ctx);
        goto after_2;
    // 0x80053C6C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80053C70: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80053C74: sw          $v0, 0x34($s6)
    MEM_W(0X34, ctx->r22) = ctx->r2;
    // 0x80053C78: sw          $t3, 0x40($s6)
    MEM_W(0X40, ctx->r22) = ctx->r11;
    // 0x80053C7C: lw          $a3, 0x4($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X4);
    // 0x80053C80: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80053C84: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80053C88: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80053C8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80053C90: jal         0x800507E0
    // 0x80053C94: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    func_800507E0(rdram, ctx);
        goto after_3;
    // 0x80053C94: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_3:
    // 0x80053C98: lw          $a0, 0x34($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X34);
    // 0x80053C9C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80053CA0: jal         0x8005A018
    // 0x80053CA4: lw          $a2, 0x4($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X4);
    func_8005A018(rdram, ctx);
        goto after_4;
    // 0x80053CA4: lw          $a2, 0x4($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X4);
    after_4:
    // 0x80053CA8: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x80053CAC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80053CB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80053CB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80053CB8: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x80053CBC: jal         0x800507E0
    // 0x80053CC0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800507E0(rdram, ctx);
        goto after_5;
    // 0x80053CC0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x80053CC4: sw          $v0, 0x30($s6)
    MEM_W(0X30, ctx->r22) = ctx->r2;
    // 0x80053CC8: lw          $a3, 0x4($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X4);
    // 0x80053CCC: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80053CD0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80053CD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80053CD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80053CDC: jal         0x800507E0
    // 0x80053CE0: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    func_800507E0(rdram, ctx);
        goto after_6;
    // 0x80053CE0: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_6:
    // 0x80053CE4: lw          $a0, 0x30($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X30);
    // 0x80053CE8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80053CEC: jal         0x80059FC4
    // 0x80053CF0: lw          $a2, 0x4($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X4);
    func_80059FC4(rdram, ctx);
        goto after_7;
    // 0x80053CF0: lw          $a2, 0x4($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X4);
    after_7:
    // 0x80053CF4: lbu         $t7, 0x1C($fp)
    ctx->r15 = MEM_BU(ctx->r30, 0X1C);
    // 0x80053CF8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80053CFC: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    // 0x80053D00: beq         $t7, $zero, L_80053D1C
    if (ctx->r15 == 0) {
        // 0x80053D04: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_80053D1C;
    }
    // 0x80053D04: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80053D08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80053D0C: jal         0x8005A720
    // 0x80053D10: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    func_8005A720(rdram, ctx);
        goto after_8;
    // 0x80053D10: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    after_8:
    // 0x80053D14: b           L_80053D2C
    // 0x80053D18: sw          $zero, 0x4($s6)
    MEM_W(0X4, ctx->r22) = 0;
        goto L_80053D2C;
    // 0x80053D18: sw          $zero, 0x4($s6)
    MEM_W(0X4, ctx->r22) = 0;
L_80053D1C:
    // 0x80053D1C: lw          $a0, 0x30($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X30);
    // 0x80053D20: jal         0x8005A7C0
    // 0x80053D24: lw          $a2, 0x34($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X34);
    func_8005A7C0(rdram, ctx);
        goto after_9;
    // 0x80053D24: lw          $a2, 0x34($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X34);
    after_9:
    // 0x80053D28: sw          $zero, 0x4($s6)
    MEM_W(0X4, ctx->r22) = 0;
L_80053D2C:
    // 0x80053D2C: sw          $zero, 0x8($s6)
    MEM_W(0X8, ctx->r22) = 0;
    // 0x80053D30: sw          $zero, 0x14($s6)
    MEM_W(0X14, ctx->r22) = 0;
    // 0x80053D34: sw          $zero, 0x18($s6)
    MEM_W(0X18, ctx->r22) = 0;
    // 0x80053D38: sw          $zero, 0xC($s6)
    MEM_W(0XC, ctx->r22) = 0;
    // 0x80053D3C: sw          $zero, 0x10($s6)
    MEM_W(0X10, ctx->r22) = 0;
    // 0x80053D40: lw          $a3, 0x4($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X4);
    // 0x80053D44: addiu       $t8, $zero, 0xDC
    ctx->r24 = ADD32(0, 0XDC);
    // 0x80053D48: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80053D4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80053D50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80053D54: jal         0x800507E0
    // 0x80053D58: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    func_800507E0(rdram, ctx);
        goto after_10;
    // 0x80053D58: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_10:
    // 0x80053D5C: lw          $t9, 0x4($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X4);
    // 0x80053D60: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80053D64: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80053D68: blez        $t9, L_80053E28
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80053D6C: addiu       $a1, $s6, 0x4
        ctx->r5 = ADD32(ctx->r22, 0X4);
            goto L_80053E28;
    }
    // 0x80053D6C: addiu       $a1, $s6, 0x4
    ctx->r5 = ADD32(ctx->r22, 0X4);
    // 0x80053D70: addiu       $s1, $v0, 0x8C
    ctx->r17 = ADD32(ctx->r2, 0X8C);
    // 0x80053D74: addiu       $s2, $v0, 0x58
    ctx->r18 = ADD32(ctx->r2, 0X58);
    // 0x80053D78: addiu       $s3, $v0, 0x10
    ctx->r19 = ADD32(ctx->r2, 0X10);
    // 0x80053D7C: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
L_80053D80:
    // 0x80053D80: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80053D84: or          $s5, $s0, $zero
    ctx->r21 = ctx->r16 | 0;
    // 0x80053D88: jal         0x800526F0
    // 0x80053D8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800526F0(rdram, ctx);
        goto after_11;
    // 0x80053D8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80053D90: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x80053D94: lw          $a1, 0x24($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X24);
    // 0x80053D98: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80053D9C: jal         0x8005A0F4
    // 0x80053DA0: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    func_8005A0F4(rdram, ctx);
        goto after_12;
    // 0x80053DA0: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_12:
    // 0x80053DA4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80053DA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80053DAC: jal         0x8005A910
    // 0x80053DB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8005A910(rdram, ctx);
        goto after_13;
    // 0x80053DB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
    // 0x80053DB4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80053DB8: jal         0x8005A06C
    // 0x80053DBC: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    func_8005A06C(rdram, ctx);
        goto after_14;
    // 0x80053DBC: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_14:
    // 0x80053DC0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80053DC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80053DC8: jal         0x8005B460
    // 0x80053DCC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_8005B460(rdram, ctx);
        goto after_15;
    // 0x80053DCC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_15:
    // 0x80053DD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80053DD4: jal         0x8005A19C
    // 0x80053DD8: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    func_8005A19C(rdram, ctx);
        goto after_16;
    // 0x80053DD8: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_16:
    // 0x80053DDC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80053DE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80053DE4: jal         0x8005B874
    // 0x80053DE8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_8005B874(rdram, ctx);
        goto after_17;
    // 0x80053DE8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_17:
    // 0x80053DEC: lw          $a0, 0x34($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X34);
    // 0x80053DF0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80053DF4: jal         0x8005C3C0
    // 0x80053DF8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_8005C3C0(rdram, ctx);
        goto after_18;
    // 0x80053DF8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_18:
    // 0x80053DFC: addiu       $t0, $s5, 0x8C
    ctx->r8 = ADD32(ctx->r21, 0X8C);
    // 0x80053E00: sw          $t0, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r8;
    // 0x80053E04: lw          $t1, 0x4($fp)
    ctx->r9 = MEM_W(ctx->r30, 0X4);
    // 0x80053E08: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80053E0C: addiu       $s0, $s0, 0xDC
    ctx->r16 = ADD32(ctx->r16, 0XDC);
    // 0x80053E10: slt         $at, $s4, $t1
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80053E14: addiu       $s1, $s1, 0xDC
    ctx->r17 = ADD32(ctx->r17, 0XDC);
    // 0x80053E18: addiu       $s2, $s2, 0xDC
    ctx->r18 = ADD32(ctx->r18, 0XDC);
    // 0x80053E1C: bne         $at, $zero, L_80053D80
    if (ctx->r1 != 0) {
        // 0x80053E20: addiu       $s3, $s3, 0xDC
        ctx->r19 = ADD32(ctx->r19, 0XDC);
            goto L_80053D80;
    }
    // 0x80053E20: addiu       $s3, $s3, 0xDC
    ctx->r19 = ADD32(ctx->r19, 0XDC);
    // 0x80053E24: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_80053E28:
    // 0x80053E28: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80053E2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80053E30: jal         0x8005C4D0
    // 0x80053E34: lw          $a2, 0x30($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X30);
    func_8005C4D0(rdram, ctx);
        goto after_19;
    // 0x80053E34: lw          $a2, 0x30($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X30);
    after_19:
    // 0x80053E38: lw          $a3, 0x8($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X8);
    // 0x80053E3C: addiu       $t2, $zero, 0x1C
    ctx->r10 = ADD32(0, 0X1C);
    // 0x80053E40: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80053E44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80053E48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80053E4C: jal         0x800507E0
    // 0x80053E50: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    func_800507E0(rdram, ctx);
        goto after_20;
    // 0x80053E50: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_20:
    // 0x80053E54: sw          $zero, 0x2C($s6)
    MEM_W(0X2C, ctx->r22) = 0;
    // 0x80053E58: lw          $t3, 0x8($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X8);
    // 0x80053E5C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80053E60: blezl       $t3, L_80053E90
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80053E64: sw          $s7, 0x28($s6)
        MEM_W(0X28, ctx->r22) = ctx->r23;
            goto L_80053E90;
    }
    goto skip_0;
    // 0x80053E64: sw          $s7, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->r23;
    skip_0:
    // 0x80053E68: lw          $t4, 0x2C($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X2C);
L_80053E6C:
    // 0x80053E6C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80053E70: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80053E74: sw          $v1, 0x2C($s6)
    MEM_W(0X2C, ctx->r22) = ctx->r3;
    // 0x80053E78: lw          $t5, 0x8($fp)
    ctx->r13 = MEM_W(ctx->r30, 0X8);
    // 0x80053E7C: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x80053E80: slt         $at, $s4, $t5
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80053E84: bnel        $at, $zero, L_80053E6C
    if (ctx->r1 != 0) {
        // 0x80053E88: lw          $t4, 0x2C($s6)
        ctx->r12 = MEM_W(ctx->r22, 0X2C);
            goto L_80053E6C;
    }
    goto skip_1;
    // 0x80053E88: lw          $t4, 0x2C($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X2C);
    skip_1:
    // 0x80053E8C: sw          $s7, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->r23;
L_80053E90:
    // 0x80053E90: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80053E94: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80053E98: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80053E9C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80053EA0: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80053EA4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80053EA8: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80053EAC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80053EB0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80053EB4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80053EB8: jr          $ra
    // 0x80053EBC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    TRACE_RETURN()
    return;
    // 0x80053EBC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_80053FD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80053FD0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80053FD4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80053FD8: bltz        $a0, L_80053FEC
    if (SIGNED(ctx->r4) < 0) {
        // 0x80053FDC: lui         $at, 0x8008
        ctx->r1 = S32(0X8008 << 16);
            goto L_80053FEC;
    }
    // 0x80053FDC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80053FE0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80053FE4: b           L_80053FF4
    // 0x80053FE8: lwc1        $f0, -0x6C40($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6C40);
        goto L_80053FF4;
    // 0x80053FE8: lwc1        $f0, -0x6C40($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6C40);
L_80053FEC:
    // 0x80053FEC: lwc1        $f0, -0x6C3C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6C3C);
    // 0x80053FF0: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
L_80053FF4:
    // 0x80053FF4: beq         $a0, $zero, L_80054018
    if (ctx->r4 == 0) {
        // 0x80053FF8: andi        $t6, $a0, 0x1
        ctx->r14 = ctx->r4 & 0X1;
            goto L_80054018;
    }
L_80053FF8:
    // 0x80053FF8: andi        $t6, $a0, 0x1
    ctx->r14 = ctx->r4 & 0X1;
    // 0x80053FFC: beq         $t6, $zero, L_8005400C
    if (ctx->r14 == 0) {
        // 0x80054000: sra         $t7, $a0, 1
        ctx->r15 = S32(SIGNED(ctx->r4) >> 1);
            goto L_8005400C;
    }
    // 0x80054000: sra         $t7, $a0, 1
    ctx->r15 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80054004: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80054008: nop

L_8005400C:
    // 0x8005400C: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80054010: bne         $t7, $zero, L_80053FF8
    if (ctx->r15 != 0) {
        // 0x80054014: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_80053FF8;
    }
    // 0x80054014: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
L_80054018:
    // 0x80054018: jr          $ra
    // 0x8005401C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    TRACE_RETURN()
    return;
    // 0x8005401C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void func_80054360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80054360: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80054364: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x80054368: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x8005436C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80054370: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80054374: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80054378: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8005437C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80054380: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
L_80054384:
    // 0x80054384: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80054388: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8005438C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80054390: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80054394: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x80054398: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8005439C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800543A0: slti        $at, $t2, 0xF
    ctx->r1 = SIGNED(ctx->r10) < 0XF ? 1 : 0;
    // 0x800543A4: bne         $at, $zero, L_80054384
    if (ctx->r1 != 0) {
        // 0x800543A8: sw          $t2, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r10;
            goto L_80054384;
    }
    // 0x800543A8: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x800543AC: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x800543B0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800543B4: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800543B8: sw          $t3, 0x3C($t4)
    MEM_W(0X3C, ctx->r12) = ctx->r11;
    // 0x800543BC: addiu       $t6, $zero, 0x23
    ctx->r14 = ADD32(0, 0X23);
    // 0x800543C0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800543C4: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x800543C8: sb          $t5, 0x1C($sp)
    MEM_B(0X1C, ctx->r29) = ctx->r13;
    // 0x800543CC: sb          $t6, 0x1D($sp)
    MEM_B(0X1D, ctx->r29) = ctx->r14;
    // 0x800543D0: sb          $t8, 0x1E($sp)
    MEM_B(0X1E, ctx->r29) = ctx->r24;
    // 0x800543D4: sb          $t7, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r15;
    // 0x800543D8: jal         0x8005CBF0
    // 0x800543DC: lhu         $a0, 0x4E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X4E);
    func_8005CBF0(rdram, ctx);
        goto after_0;
    // 0x800543DC: lhu         $a0, 0x4E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X4E);
    after_0:
    // 0x800543E0: lhu         $t9, 0x4E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X4E);
    // 0x800543E4: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800543E8: sb          $t2, 0x42($sp)
    MEM_B(0X42, ctx->r29) = ctx->r10;
    // 0x800543EC: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x800543F0: or          $t1, $v0, $t0
    ctx->r9 = ctx->r2 | ctx->r8;
    // 0x800543F4: sh          $t1, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r9;
    // 0x800543F8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_800543FC:
    // 0x800543FC: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80054400: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80054404: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x80054408: addu        $t6, $sp, $t5
    ctx->r14 = ADD32(ctx->r29, ctx->r13);
    // 0x8005440C: sb          $t4, 0x22($t6)
    MEM_B(0X22, ctx->r14) = ctx->r12;
    // 0x80054410: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80054414: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80054418: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8005441C: slti        $at, $t0, 0x20
    ctx->r1 = SIGNED(ctx->r8) < 0X20 ? 1 : 0;
    // 0x80054420: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x80054424: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80054428: bne         $at, $zero, L_800543FC
    if (ctx->r1 != 0) {
        // 0x8005442C: sw          $t7, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r15;
            goto L_800543FC;
    }
    // 0x8005442C: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x80054430: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80054434: beq         $t1, $zero, L_80054470
    if (ctx->r9 == 0) {
        // 0x80054438: nop
    
            goto L_80054470;
    }
    // 0x80054438: nop

    // 0x8005443C: blez        $t1, L_80054470
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80054440: sw          $zero, 0x18($sp)
        MEM_W(0X18, ctx->r29) = 0;
            goto L_80054470;
    }
    // 0x80054440: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_80054444:
    // 0x80054444: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80054448: sb          $zero, 0x0($t2)
    MEM_B(0X0, ctx->r10) = 0;
    // 0x8005444C: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80054450: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80054454: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80054458: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8005445C: slt         $at, $t6, $t8
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80054460: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80054464: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80054468: bne         $at, $zero, L_80054444
    if (ctx->r1 != 0) {
        // 0x8005446C: sw          $t4, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r12;
            goto L_80054444;
    }
    // 0x8005446C: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
L_80054470:
    // 0x80054470: addiu       $t9, $sp, 0x1C
    ctx->r25 = ADD32(ctx->r29, 0X1C);
    // 0x80054474: addiu       $t1, $t9, 0x24
    ctx->r9 = ADD32(ctx->r25, 0X24);
    // 0x80054478: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
L_8005447C:
    // 0x8005447C: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x80054480: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80054484: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80054488: swl         $at, -0xC($t7)
    do_swl(rdram, -0XC, ctx->r15, ctx->r1);
    // 0x8005448C: swr         $at, -0x9($t7)
    do_swr(rdram, -0X9, ctx->r15, ctx->r1);
    // 0x80054490: lw          $at, -0x8($t9)
    ctx->r1 = MEM_W(ctx->r25, -0X8);
    // 0x80054494: swl         $at, -0x8($t7)
    do_swl(rdram, -0X8, ctx->r15, ctx->r1);
    // 0x80054498: swr         $at, -0x5($t7)
    do_swr(rdram, -0X5, ctx->r15, ctx->r1);
    // 0x8005449C: lw          $at, -0x4($t9)
    ctx->r1 = MEM_W(ctx->r25, -0X4);
    // 0x800544A0: swl         $at, -0x4($t7)
    do_swl(rdram, -0X4, ctx->r15, ctx->r1);
    // 0x800544A4: bne         $t9, $t1, L_8005447C
    if (ctx->r25 != ctx->r9) {
        // 0x800544A8: swr         $at, -0x1($t7)
        do_swr(rdram, -0X1, ctx->r15, ctx->r1);
            goto L_8005447C;
    }
    // 0x800544A8: swr         $at, -0x1($t7)
    do_swr(rdram, -0X1, ctx->r15, ctx->r1);
    // 0x800544AC: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x800544B0: addiu       $t4, $zero, 0xFE
    ctx->r12 = ADD32(0, 0XFE);
    // 0x800544B4: swl         $at, 0x0($t7)
    do_swl(rdram, 0X0, ctx->r15, ctx->r1);
    // 0x800544B8: swr         $at, 0x3($t7)
    do_swr(rdram, 0X3, ctx->r15, ctx->r1);
    // 0x800544BC: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800544C0: addiu       $t3, $t2, 0x28
    ctx->r11 = ADD32(ctx->r10, 0X28);
    // 0x800544C4: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x800544C8: sb          $t4, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r12;
    // 0x800544CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800544D0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800544D4: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80054A28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80054A28: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80054A2C: lbu         $t7, -0x463F($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X463F);
    // 0x80054A30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80054A34: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80054A38: addiu       $t6, $t6, -0x4680
    ctx->r14 = ADD32(ctx->r14, -0X4680);
    // 0x80054A3C: sb          $zero, 0x7($sp)
    MEM_B(0X7, ctx->r29) = 0;
    // 0x80054A40: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80054A44: blez        $t7, L_80054AE8
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80054A48: sw          $zero, 0x8($sp)
        MEM_W(0X8, ctx->r29) = 0;
            goto L_80054AE8;
    }
    // 0x80054A48: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
L_80054A4C:
    // 0x80054A4C: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x80054A50: addiu       $t8, $sp, 0xC
    ctx->r24 = ADD32(ctx->r29, 0XC);
    // 0x80054A54: lwl         $at, 0x0($t9)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r25, 0X0);
    // 0x80054A58: lwr         $at, 0x3($t9)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r25, 0X3);
    // 0x80054A5C: sw          $at, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r1;
    // 0x80054A60: lwl         $t1, 0x4($t9)
    ctx->r9 = do_lwl(rdram, ctx->r9, ctx->r25, 0X4);
    // 0x80054A64: lwr         $t1, 0x7($t9)
    ctx->r9 = do_lwr(rdram, ctx->r9, ctx->r25, 0X7);
    // 0x80054A68: sw          $t1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r9;
    // 0x80054A6C: lbu         $t2, 0xE($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0XE);
    // 0x80054A70: andi        $t3, $t2, 0xC0
    ctx->r11 = ctx->r10 & 0XC0;
    // 0x80054A74: sra         $t4, $t3, 4
    ctx->r12 = S32(SIGNED(ctx->r11) >> 4);
    // 0x80054A78: sb          $t4, 0x3($a1)
    MEM_B(0X3, ctx->r5) = ctx->r12;
    // 0x80054A7C: lbu         $t5, 0x3($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X3);
    // 0x80054A80: bne         $t5, $zero, L_80054ABC
    if (ctx->r13 != 0) {
        // 0x80054A84: nop
    
            goto L_80054ABC;
    }
    // 0x80054A84: nop

    // 0x80054A88: lbu         $t6, 0x11($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X11);
    // 0x80054A8C: lbu         $t0, 0x10($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X10);
    // 0x80054A90: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80054A94: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x80054A98: or          $t8, $t7, $t0
    ctx->r24 = ctx->r15 | ctx->r8;
    // 0x80054A9C: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x80054AA0: lbu         $t9, 0x12($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X12);
    // 0x80054AA4: sb          $t9, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r25;
    // 0x80054AA8: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x80054AAC: lbu         $t1, 0x7($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X7);
    // 0x80054AB0: sllv        $t4, $t3, $t2
    ctx->r12 = S32(ctx->r11 << (ctx->r10 & 31));
    // 0x80054AB4: or          $t5, $t1, $t4
    ctx->r13 = ctx->r9 | ctx->r12;
    // 0x80054AB8: sb          $t5, 0x7($sp)
    MEM_B(0X7, ctx->r29) = ctx->r13;
L_80054ABC:
    // 0x80054ABC: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x80054AC0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80054AC4: lbu         $t9, -0x463F($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X463F);
    // 0x80054AC8: lw          $t0, 0x14($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14);
    // 0x80054ACC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80054AD0: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80054AD4: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x80054AD8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80054ADC: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x80054AE0: bne         $at, $zero, L_80054A4C
    if (ctx->r1 != 0) {
        // 0x80054AE4: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80054A4C;
    }
    // 0x80054AE4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_80054AE8:
    // 0x80054AE8: lbu         $t3, 0x7($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X7);
    // 0x80054AEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80054AF0: jr          $ra
    // 0x80054AF4: sb          $t3, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r11;
    TRACE_RETURN()
    return;
    // 0x80054AF4: sb          $t3, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r11;
;}
RECOMP_FUNC void func_80054D20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80054D20: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80054D24: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80054D28: lbu         $t7, 0x3F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X3F);
    // 0x80054D2C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80054D30: addiu       $t6, $t6, -0x45F0
    ctx->r14 = ADD32(ctx->r14, -0X45F0);
    // 0x80054D34: slti        $at, $t7, 0x41
    ctx->r1 = SIGNED(ctx->r15) < 0X41 ? 1 : 0;
    // 0x80054D38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80054D3C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80054D40: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80054D44: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80054D48: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80054D4C: bne         $at, $zero, L_80054D5C
    if (ctx->r1 != 0) {
        // 0x80054D50: sw          $t6, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r14;
            goto L_80054D5C;
    }
    // 0x80054D50: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80054D54: b           L_80054F00
    // 0x80054D58: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80054F00;
    // 0x80054D58: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80054D5C:
    // 0x80054D5C: jal         0x8005CAD0
    // 0x80054D60: nop

    func_8005CAD0(rdram, ctx);
        goto after_0;
    // 0x80054D60: nop

    after_0:
    // 0x80054D64: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80054D68: jal         0x800552DC
    // 0x80054D6C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800552DC(rdram, ctx);
        goto after_1;
    // 0x80054D6C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x80054D70: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80054D74: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80054D78: bne         $t8, $zero, L_80054D90
    if (ctx->r24 != 0) {
        // 0x80054D7C: nop
    
            goto L_80054D90;
    }
    // 0x80054D7C: nop

    // 0x80054D80: lhu         $t9, 0x28($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X28);
    // 0x80054D84: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80054D88: beq         $t9, $at, L_80054D98
    if (ctx->r25 == ctx->r1) {
        // 0x80054D8C: nop
    
            goto L_80054D98;
    }
    // 0x80054D8C: nop

L_80054D90:
    // 0x80054D90: b           L_80054F00
    // 0x80054D94: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_80054F00;
    // 0x80054D94: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_80054D98:
    // 0x80054D98: lbu         $t0, 0x2A($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X2A);
    // 0x80054D9C: andi        $t1, $t0, 0x80
    ctx->r9 = ctx->r8 & 0X80;
    // 0x80054DA0: beq         $t1, $zero, L_80054DC4
    if (ctx->r9 == 0) {
        // 0x80054DA4: nop
    
            goto L_80054DC4;
    }
    // 0x80054DA4: nop

L_80054DA8:
    // 0x80054DA8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80054DAC: jal         0x800552DC
    // 0x80054DB0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800552DC(rdram, ctx);
        goto after_2;
    // 0x80054DB0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x80054DB4: lbu         $t2, 0x2A($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X2A);
    // 0x80054DB8: andi        $t3, $t2, 0x80
    ctx->r11 = ctx->r10 & 0X80;
    // 0x80054DBC: bne         $t3, $zero, L_80054DA8
    if (ctx->r11 != 0) {
        // 0x80054DC0: nop
    
            goto L_80054DA8;
    }
    // 0x80054DC0: nop

L_80054DC4:
    // 0x80054DC4: jal         0x80054F10
    // 0x80054DC8: lbu         $a0, 0x3F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X3F);
    func_80054F10(rdram, ctx);
        goto after_3;
    // 0x80054DC8: lbu         $a0, 0x3F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X3F);
    after_3:
    // 0x80054DCC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80054DD0: addiu       $a1, $a1, -0x45F0
    ctx->r5 = ADD32(ctx->r5, -0X45F0);
    // 0x80054DD4: jal         0x8005CB40
    // 0x80054DD8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8005CB40(rdram, ctx);
        goto after_4;
    // 0x80054DD8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x80054DDC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80054DE0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80054DE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80054DE8: jal         0x8004F990
    // 0x80054DEC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x80054DEC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80054DF0: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_80054DF4:
    // 0x80054DF4: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80054DF8: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80054DFC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80054E00: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80054E04: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80054E08: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80054E0C: sw          $t4, -0x45F0($at)
    MEM_W(-0X45F0, ctx->r1) = ctx->r12;
    // 0x80054E10: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80054E14: slti        $at, $t8, 0x10
    ctx->r1 = SIGNED(ctx->r24) < 0X10 ? 1 : 0;
    // 0x80054E18: bne         $at, $zero, L_80054DF4
    if (ctx->r1 != 0) {
        // 0x80054E1C: sw          $t8, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r24;
            goto L_80054DF4;
    }
    // 0x80054E1C: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x80054E20: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80054E24: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80054E28: sw          $zero, -0x45B4($at)
    MEM_W(-0X45B4, ctx->r1) = 0;
    // 0x80054E2C: addiu       $a1, $a1, -0x45F0
    ctx->r5 = ADD32(ctx->r5, -0X45F0);
    // 0x80054E30: jal         0x8005CB40
    // 0x80054E34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8005CB40(rdram, ctx);
        goto after_6;
    // 0x80054E34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x80054E38: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80054E3C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80054E40: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80054E44: sb          $t9, -0x4640($at)
    MEM_B(-0X4640, ctx->r1) = ctx->r25;
    // 0x80054E48: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80054E4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80054E50: jal         0x8004F990
    // 0x80054E54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_7;
    // 0x80054E54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x80054E58: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_80054E5C:
    // 0x80054E5C: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80054E60: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80054E64: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80054E68: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x80054E6C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80054E70: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x80054E74: bne         $at, $zero, L_80054E5C
    if (ctx->r1 != 0) {
        // 0x80054E78: sw          $t1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r9;
            goto L_80054E5C;
    }
    // 0x80054E78: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80054E7C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80054E80: addiu       $t5, $sp, 0x1C
    ctx->r13 = ADD32(ctx->r29, 0X1C);
    // 0x80054E84: lwl         $at, 0x0($t4)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r12, 0X0);
    // 0x80054E88: lwr         $at, 0x3($t4)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r12, 0X3);
    // 0x80054E8C: sw          $at, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r1;
    // 0x80054E90: lwl         $t7, 0x4($t4)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r12, 0X4);
    // 0x80054E94: lwr         $t7, 0x7($t4)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r12, 0X7);
    // 0x80054E98: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x80054E9C: lwl         $at, 0x8($t4)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r12, 0X8);
    // 0x80054EA0: lwr         $at, 0xB($t4)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r12, 0XB);
    // 0x80054EA4: sw          $at, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r1;
    // 0x80054EA8: lbu         $t8, 0x1D($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X1D);
    // 0x80054EAC: andi        $t9, $t8, 0xC0
    ctx->r25 = ctx->r24 & 0XC0;
    // 0x80054EB0: sra         $t0, $t9, 4
    ctx->r8 = S32(SIGNED(ctx->r25) >> 4);
    // 0x80054EB4: bne         $t0, $zero, L_80054EF4
    if (ctx->r8 != 0) {
        // 0x80054EB8: sw          $t0, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r8;
            goto L_80054EF4;
    }
    // 0x80054EB8: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x80054EBC: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_80054EC0:
    // 0x80054EC0: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80054EC4: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80054EC8: addu        $t2, $sp, $t1
    ctx->r10 = ADD32(ctx->r29, ctx->r9);
    // 0x80054ECC: lbu         $t2, 0x20($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X20);
    // 0x80054ED0: sb          $t2, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r10;
    // 0x80054ED4: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80054ED8: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80054EDC: addiu       $t7, $t4, 0x1
    ctx->r15 = ADD32(ctx->r12, 0X1);
    // 0x80054EE0: slti        $at, $t7, 0x8
    ctx->r1 = SIGNED(ctx->r15) < 0X8 ? 1 : 0;
    // 0x80054EE4: addiu       $t5, $t6, 0x1
    ctx->r13 = ADD32(ctx->r14, 0X1);
    // 0x80054EE8: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x80054EEC: bne         $at, $zero, L_80054EC0
    if (ctx->r1 != 0) {
        // 0x80054EF0: sw          $t5, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r13;
            goto L_80054EC0;
    }
    // 0x80054EF0: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
L_80054EF4:
    // 0x80054EF4: jal         0x8005CB14
    // 0x80054EF8: nop

    func_8005CB14(rdram, ctx);
        goto after_8;
    // 0x80054EF8: nop

    after_8:
    // 0x80054EFC: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
L_80054F00:
    // 0x80054F00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80054F04: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80054F08: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80054F10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80054F10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80054F14: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80054F18: addiu       $t6, $t6, -0x45F0
    ctx->r14 = ADD32(ctx->r14, -0X45F0);
    // 0x80054F1C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80054F20: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80054F24: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_80054F28:
    // 0x80054F28: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80054F2C: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80054F30: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80054F34: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80054F38: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80054F3C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80054F40: sw          $t7, -0x45F0($at)
    MEM_W(-0X45F0, ctx->r1) = ctx->r15;
    // 0x80054F44: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80054F48: slti        $at, $t1, 0x10
    ctx->r1 = SIGNED(ctx->r9) < 0X10 ? 1 : 0;
    // 0x80054F4C: bne         $at, $zero, L_80054F28
    if (ctx->r1 != 0) {
        // 0x80054F50: sw          $t1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r9;
            goto L_80054F28;
    }
    // 0x80054F50: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x80054F54: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80054F58: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80054F5C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80054F60: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x80054F64: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80054F68: sw          $t2, -0x45B4($at)
    MEM_W(-0X45B4, ctx->r1) = ctx->r10;
    // 0x80054F6C: sb          $t3, 0x8($sp)
    MEM_B(0X8, ctx->r29) = ctx->r11;
    // 0x80054F70: sb          $t4, 0x9($sp)
    MEM_B(0X9, ctx->r29) = ctx->r12;
    // 0x80054F74: sb          $t5, 0xA($sp)
    MEM_B(0XA, ctx->r29) = ctx->r13;
    // 0x80054F78: sb          $a0, 0xB($sp)
    MEM_B(0XB, ctx->r29) = ctx->r4;
    // 0x80054F7C: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_80054F80:
    // 0x80054F80: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80054F84: addu        $t8, $sp, $t6
    ctx->r24 = ADD32(ctx->r29, ctx->r14);
    // 0x80054F88: sb          $zero, 0xC($t8)
    MEM_B(0XC, ctx->r24) = 0;
    // 0x80054F8C: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80054F90: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80054F94: slti        $at, $t9, 0x8
    ctx->r1 = SIGNED(ctx->r25) < 0X8 ? 1 : 0;
    // 0x80054F98: bne         $at, $zero, L_80054F80
    if (ctx->r1 != 0) {
        // 0x80054F9C: sw          $t9, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r25;
            goto L_80054F80;
    }
    // 0x80054F9C: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x80054FA0: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_80054FA4:
    // 0x80054FA4: lw          $t0, 0x14($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14);
    // 0x80054FA8: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
    // 0x80054FAC: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x80054FB0: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x80054FB4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80054FB8: slti        $at, $t4, 0x4
    ctx->r1 = SIGNED(ctx->r12) < 0X4 ? 1 : 0;
    // 0x80054FBC: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80054FC0: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x80054FC4: bne         $at, $zero, L_80054FA4
    if (ctx->r1 != 0) {
        // 0x80054FC8: sw          $t2, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r10;
            goto L_80054FA4;
    }
    // 0x80054FC8: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80054FCC: addiu       $t6, $sp, 0x8
    ctx->r14 = ADD32(ctx->r29, 0X8);
    // 0x80054FD0: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x80054FD4: lw          $t5, 0x14($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14);
    // 0x80054FD8: addiu       $t1, $zero, 0xFE
    ctx->r9 = ADD32(0, 0XFE);
    // 0x80054FDC: swl         $at, 0x0($t5)
    do_swl(rdram, 0X0, ctx->r13, ctx->r1);
    // 0x80054FE0: swr         $at, 0x3($t5)
    do_swr(rdram, 0X3, ctx->r13, ctx->r1);
    // 0x80054FE4: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80054FE8: swl         $t7, 0x4($t5)
    do_swl(rdram, 0X4, ctx->r13, ctx->r15);
    // 0x80054FEC: swr         $t7, 0x7($t5)
    do_swr(rdram, 0X7, ctx->r13, ctx->r15);
    // 0x80054FF0: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x80054FF4: swl         $at, 0x8($t5)
    do_swl(rdram, 0X8, ctx->r13, ctx->r1);
    // 0x80054FF8: swr         $at, 0xB($t5)
    do_swr(rdram, 0XB, ctx->r13, ctx->r1);
    // 0x80054FFC: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x80055000: addiu       $t0, $t9, 0xC
    ctx->r8 = ADD32(ctx->r25, 0XC);
    // 0x80055004: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80055008: sb          $t1, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r9;
    // 0x8005500C: jr          $ra
    // 0x80055010: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    TRACE_RETURN()
    return;
    // 0x80055010: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
