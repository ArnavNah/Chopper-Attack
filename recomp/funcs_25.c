#include "recomp.h"
#include "trace.h"
#include "funcs.h"

RECOMP_FUNC void func_80055020(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80055020: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80055024: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80055028: lbu         $t7, 0x3F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X3F);
    // 0x8005502C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80055030: addiu       $t6, $t6, -0x45F0
    ctx->r14 = ADD32(ctx->r14, -0X45F0);
    // 0x80055034: slti        $at, $t7, 0x41
    ctx->r1 = SIGNED(ctx->r15) < 0X41 ? 1 : 0;
    // 0x80055038: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005503C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80055040: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80055044: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80055048: bne         $at, $zero, L_80055058
    if (ctx->r1 != 0) {
        // 0x8005504C: sw          $t6, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r14;
            goto L_80055058;
    }
    // 0x8005504C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80055050: b           L_800551C0
    // 0x80055054: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800551C0;
    // 0x80055054: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80055058:
    // 0x80055058: jal         0x8005CAD0
    // 0x8005505C: nop

    func_8005CAD0(rdram, ctx);
        goto after_0;
    // 0x8005505C: nop

    after_0:
    // 0x80055060: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80055064: jal         0x800552DC
    // 0x80055068: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800552DC(rdram, ctx);
        goto after_1;
    // 0x80055068: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x8005506C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80055070: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80055074: bne         $t8, $zero, L_8005508C
    if (ctx->r24 != 0) {
        // 0x80055078: nop
    
            goto L_8005508C;
    }
    // 0x80055078: nop

    // 0x8005507C: lhu         $t9, 0x1C($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X1C);
    // 0x80055080: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80055084: beq         $t9, $at, L_80055094
    if (ctx->r25 == ctx->r1) {
        // 0x80055088: nop
    
            goto L_80055094;
    }
    // 0x80055088: nop

L_8005508C:
    // 0x8005508C: b           L_800551C0
    // 0x80055090: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_800551C0;
    // 0x80055090: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_80055094:
    // 0x80055094: lbu         $t0, 0x1E($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X1E);
    // 0x80055098: andi        $t1, $t0, 0x80
    ctx->r9 = ctx->r8 & 0X80;
    // 0x8005509C: beq         $t1, $zero, L_800550C0
    if (ctx->r9 == 0) {
        // 0x800550A0: nop
    
            goto L_800550C0;
    }
    // 0x800550A0: nop

L_800550A4:
    // 0x800550A4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800550A8: jal         0x800552DC
    // 0x800550AC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800552DC(rdram, ctx);
        goto after_2;
    // 0x800550AC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_2:
    // 0x800550B0: lbu         $t2, 0x1E($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X1E);
    // 0x800550B4: andi        $t3, $t2, 0x80
    ctx->r11 = ctx->r10 & 0X80;
    // 0x800550B8: bne         $t3, $zero, L_800550A4
    if (ctx->r11 != 0) {
        // 0x800550BC: nop
    
            goto L_800550A4;
    }
    // 0x800550BC: nop

L_800550C0:
    // 0x800550C0: lbu         $a0, 0x3F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X3F);
    // 0x800550C4: jal         0x800551D0
    // 0x800550C8: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    func_800551D0(rdram, ctx);
        goto after_3;
    // 0x800550C8: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_3:
    // 0x800550CC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800550D0: addiu       $a1, $a1, -0x45F0
    ctx->r5 = ADD32(ctx->r5, -0X45F0);
    // 0x800550D4: jal         0x8005CB40
    // 0x800550D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8005CB40(rdram, ctx);
        goto after_4;
    // 0x800550D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x800550DC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x800550E0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800550E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800550E8: jal         0x8004F990
    // 0x800550EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x800550EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x800550F0: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_800550F4:
    // 0x800550F4: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x800550F8: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800550FC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80055100: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80055104: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80055108: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8005510C: sw          $t4, -0x45F0($at)
    MEM_W(-0X45F0, ctx->r1) = ctx->r12;
    // 0x80055110: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80055114: slti        $at, $t8, 0x10
    ctx->r1 = SIGNED(ctx->r24) < 0X10 ? 1 : 0;
    // 0x80055118: bne         $at, $zero, L_800550F4
    if (ctx->r1 != 0) {
        // 0x8005511C: sw          $t8, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r24;
            goto L_800550F4;
    }
    // 0x8005511C: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x80055120: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80055124: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80055128: sw          $zero, -0x45B4($at)
    MEM_W(-0X45B4, ctx->r1) = 0;
    // 0x8005512C: addiu       $a1, $a1, -0x45F0
    ctx->r5 = ADD32(ctx->r5, -0X45F0);
    // 0x80055130: jal         0x8005CB40
    // 0x80055134: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8005CB40(rdram, ctx);
        goto after_6;
    // 0x80055134: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x80055138: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x8005513C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80055140: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80055144: sb          $t9, -0x4640($at)
    MEM_B(-0X4640, ctx->r1) = ctx->r25;
    // 0x80055148: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8005514C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80055150: jal         0x8004F990
    // 0x80055154: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_7;
    // 0x80055154: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x80055158: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_8005515C:
    // 0x8005515C: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80055160: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80055164: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80055168: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x8005516C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80055170: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x80055174: bne         $at, $zero, L_8005515C
    if (ctx->r1 != 0) {
        // 0x80055178: sw          $t1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r9;
            goto L_8005515C;
    }
    // 0x80055178: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x8005517C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80055180: addiu       $t5, $sp, 0x20
    ctx->r13 = ADD32(ctx->r29, 0X20);
    // 0x80055184: lwl         $at, 0x0($t4)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r12, 0X0);
    // 0x80055188: lwr         $at, 0x3($t4)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r12, 0X3);
    // 0x8005518C: sw          $at, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r1;
    // 0x80055190: lwl         $t7, 0x4($t4)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r12, 0X4);
    // 0x80055194: lwr         $t7, 0x7($t4)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r12, 0X7);
    // 0x80055198: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x8005519C: lwl         $at, 0x8($t4)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r12, 0X8);
    // 0x800551A0: lwr         $at, 0xB($t4)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r12, 0XB);
    // 0x800551A4: sw          $at, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r1;
    // 0x800551A8: lbu         $t8, 0x21($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X21);
    // 0x800551AC: andi        $t9, $t8, 0xC0
    ctx->r25 = ctx->r24 & 0XC0;
    // 0x800551B0: sra         $t0, $t9, 4
    ctx->r8 = S32(SIGNED(ctx->r25) >> 4);
    // 0x800551B4: jal         0x8005CB14
    // 0x800551B8: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    func_8005CB14(rdram, ctx);
        goto after_8;
    // 0x800551B8: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    after_8:
    // 0x800551BC: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
L_800551C0:
    // 0x800551C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800551C4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800551C8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800551D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800551D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800551D4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800551D8: addiu       $t6, $t6, -0x45F0
    ctx->r14 = ADD32(ctx->r14, -0X45F0);
    // 0x800551DC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800551E0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800551E4: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800551E8:
    // 0x800551E8: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x800551EC: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800551F0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800551F4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800551F8: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800551FC: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80055200: sw          $t7, -0x45F0($at)
    MEM_W(-0X45F0, ctx->r1) = ctx->r15;
    // 0x80055204: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80055208: slti        $at, $t1, 0x10
    ctx->r1 = SIGNED(ctx->r9) < 0X10 ? 1 : 0;
    // 0x8005520C: bne         $at, $zero, L_800551E8
    if (ctx->r1 != 0) {
        // 0x80055210: sw          $t1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r9;
            goto L_800551E8;
    }
    // 0x80055210: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x80055214: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80055218: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8005521C: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x80055220: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80055224: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x80055228: sw          $t2, -0x45B4($at)
    MEM_W(-0X45B4, ctx->r1) = ctx->r10;
    // 0x8005522C: sb          $t3, 0x8($sp)
    MEM_B(0X8, ctx->r29) = ctx->r11;
    // 0x80055230: sb          $t4, 0x9($sp)
    MEM_B(0X9, ctx->r29) = ctx->r12;
    // 0x80055234: sb          $t5, 0xA($sp)
    MEM_B(0XA, ctx->r29) = ctx->r13;
    // 0x80055238: sb          $a0, 0xB($sp)
    MEM_B(0XB, ctx->r29) = ctx->r4;
    // 0x8005523C: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_80055240:
    // 0x80055240: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80055244: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x80055248: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8005524C: addu        $t7, $sp, $t8
    ctx->r15 = ADD32(ctx->r29, ctx->r24);
    // 0x80055250: sb          $t6, 0xC($t7)
    MEM_B(0XC, ctx->r15) = ctx->r14;
    // 0x80055254: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x80055258: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8005525C: slti        $at, $t0, 0x8
    ctx->r1 = SIGNED(ctx->r8) < 0X8 ? 1 : 0;
    // 0x80055260: bne         $at, $zero, L_80055240
    if (ctx->r1 != 0) {
        // 0x80055264: sw          $t0, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r8;
            goto L_80055240;
    }
    // 0x80055264: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x80055268: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005526C:
    // 0x8005526C: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x80055270: sb          $zero, 0x0($t1)
    MEM_B(0X0, ctx->r9) = 0;
    // 0x80055274: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x80055278: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x8005527C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80055280: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    // 0x80055284: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80055288: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x8005528C: bne         $at, $zero, L_8005526C
    if (ctx->r1 != 0) {
        // 0x80055290: sw          $t3, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r11;
            goto L_8005526C;
    }
    // 0x80055290: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80055294: addiu       $t8, $sp, 0x8
    ctx->r24 = ADD32(ctx->r29, 0X8);
    // 0x80055298: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x8005529C: lw          $t6, 0x14($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14);
    // 0x800552A0: addiu       $t2, $zero, 0xFE
    ctx->r10 = ADD32(0, 0XFE);
    // 0x800552A4: swl         $at, 0x0($t6)
    do_swl(rdram, 0X0, ctx->r14, ctx->r1);
    // 0x800552A8: swr         $at, 0x3($t6)
    do_swr(rdram, 0X3, ctx->r14, ctx->r1);
    // 0x800552AC: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x800552B0: swl         $t9, 0x4($t6)
    do_swl(rdram, 0X4, ctx->r14, ctx->r25);
    // 0x800552B4: swr         $t9, 0x7($t6)
    do_swr(rdram, 0X7, ctx->r14, ctx->r25);
    // 0x800552B8: lw          $at, 0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X8);
    // 0x800552BC: swl         $at, 0x8($t6)
    do_swl(rdram, 0X8, ctx->r14, ctx->r1);
    // 0x800552C0: swr         $at, 0xB($t6)
    do_swr(rdram, 0XB, ctx->r14, ctx->r1);
    // 0x800552C4: lw          $t0, 0x14($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14);
    // 0x800552C8: addiu       $t1, $t0, 0xC
    ctx->r9 = ADD32(ctx->r8, 0XC);
    // 0x800552CC: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800552D0: sb          $t2, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r10;
    // 0x800552D4: jr          $ra
    // 0x800552D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    TRACE_RETURN()
    return;
    // 0x800552D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800552DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800552DC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800552E0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800552E4: addiu       $t6, $t6, -0x45F0
    ctx->r14 = ADD32(ctx->r14, -0X45F0);
    // 0x800552E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800552EC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800552F0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800552F4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800552F8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x800552FC: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
L_80055300:
    // 0x80055300: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80055304: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80055308: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8005530C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80055310: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80055314: sw          $zero, -0x45F0($at)
    MEM_W(-0X45F0, ctx->r1) = 0;
    // 0x80055318: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8005531C: slti        $at, $t0, 0x10
    ctx->r1 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // 0x80055320: bne         $at, $zero, L_80055300
    if (ctx->r1 != 0) {
        // 0x80055324: sw          $t0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r8;
            goto L_80055300;
    }
    // 0x80055324: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80055328: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x8005532C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80055330: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80055334: addiu       $t2, $t2, -0x45F0
    ctx->r10 = ADD32(ctx->r10, -0X45F0);
    // 0x80055338: sw          $t1, -0x45B4($at)
    MEM_W(-0X45B4, ctx->r1) = ctx->r9;
    // 0x8005533C: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80055340: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
L_80055344:
    // 0x80055344: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80055348: sb          $zero, 0x0($t3)
    MEM_B(0X0, ctx->r11) = 0;
    // 0x8005534C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80055350: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80055354: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80055358: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x8005535C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80055360: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80055364: bne         $at, $zero, L_80055344
    if (ctx->r1 != 0) {
        // 0x80055368: sw          $t5, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r13;
            goto L_80055344;
    }
    // 0x80055368: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x8005536C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80055370: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80055374: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x80055378: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8005537C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80055380: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80055384: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80055388: sb          $t8, 0x1C($sp)
    MEM_B(0X1C, ctx->r29) = ctx->r24;
    // 0x8005538C: sb          $t9, 0x1D($sp)
    MEM_B(0X1D, ctx->r29) = ctx->r25;
    // 0x80055390: sb          $t0, 0x1E($sp)
    MEM_B(0X1E, ctx->r29) = ctx->r8;
    // 0x80055394: sb          $zero, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = 0;
    // 0x80055398: sb          $t1, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r9;
    // 0x8005539C: sb          $t2, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r10;
    // 0x800553A0: sb          $t3, 0x22($sp)
    MEM_B(0X22, ctx->r29) = ctx->r11;
    // 0x800553A4: sb          $t4, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r12;
    // 0x800553A8: addiu       $t6, $sp, 0x1C
    ctx->r14 = ADD32(ctx->r29, 0X1C);
    // 0x800553AC: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x800553B0: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800553B4: addiu       $t2, $zero, 0xFE
    ctx->r10 = ADD32(0, 0XFE);
    // 0x800553B8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800553BC: swl         $at, 0x0($t5)
    do_swl(rdram, 0X0, ctx->r13, ctx->r1);
    // 0x800553C0: swr         $at, 0x3($t5)
    do_swr(rdram, 0X3, ctx->r13, ctx->r1);
    // 0x800553C4: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x800553C8: addiu       $a1, $a1, -0x45F0
    ctx->r5 = ADD32(ctx->r5, -0X45F0);
    // 0x800553CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800553D0: swl         $t9, 0x4($t5)
    do_swl(rdram, 0X4, ctx->r13, ctx->r25);
    // 0x800553D4: swr         $t9, 0x7($t5)
    do_swr(rdram, 0X7, ctx->r13, ctx->r25);
    // 0x800553D8: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800553DC: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800553E0: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x800553E4: jal         0x8005CB40
    // 0x800553E8: sb          $t2, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r10;
    func_8005CB40(rdram, ctx);
        goto after_0;
    // 0x800553E8: sb          $t2, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r10;
    after_0:
    // 0x800553EC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800553F0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800553F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800553F8: jal         0x8004F990
    // 0x800553FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800553FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80055400: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x80055404: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80055408: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8005540C: sb          $t3, -0x4640($at)
    MEM_B(-0X4640, ctx->r1) = ctx->r11;
    // 0x80055410: addiu       $a1, $a1, -0x45F0
    ctx->r5 = ADD32(ctx->r5, -0X45F0);
    // 0x80055414: jal         0x8005CB40
    // 0x80055418: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8005CB40(rdram, ctx);
        goto after_2;
    // 0x80055418: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x8005541C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80055420: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80055424: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80055428: jal         0x8004F990
    // 0x8005542C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x8005542C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80055430: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80055434: beq         $t4, $zero, L_80055444
    if (ctx->r12 == 0) {
        // 0x80055438: nop
    
            goto L_80055444;
    }
    // 0x80055438: nop

    // 0x8005543C: b           L_800554F0
    // 0x80055440: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
        goto L_800554F0;
    // 0x80055440: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
L_80055444:
    // 0x80055444: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80055448: addiu       $t8, $t8, -0x45F0
    ctx->r24 = ADD32(ctx->r24, -0X45F0);
    // 0x8005544C: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80055450: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
L_80055454:
    // 0x80055454: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80055458: sb          $zero, 0x0($t7)
    MEM_B(0X0, ctx->r15) = 0;
    // 0x8005545C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80055460: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80055464: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80055468: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x8005546C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80055470: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80055474: bne         $at, $zero, L_80055454
    if (ctx->r1 != 0) {
        // 0x80055478: sw          $t6, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r14;
            goto L_80055454;
    }
    // 0x80055478: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8005547C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80055480: addiu       $t2, $sp, 0x1C
    ctx->r10 = ADD32(ctx->r29, 0X1C);
    // 0x80055484: lwl         $at, 0x0($t1)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r9, 0X0);
    // 0x80055488: lwr         $at, 0x3($t1)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r9, 0X3);
    // 0x8005548C: sw          $at, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r1;
    // 0x80055490: lwl         $t4, 0x4($t1)
    ctx->r12 = do_lwl(rdram, ctx->r12, ctx->r9, 0X4);
    // 0x80055494: lwr         $t4, 0x7($t1)
    ctx->r12 = do_lwr(rdram, ctx->r12, ctx->r9, 0X7);
    // 0x80055498: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x8005549C: lbu         $t8, 0x1E($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X1E);
    // 0x800554A0: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800554A4: andi        $t7, $t8, 0xC0
    ctx->r15 = ctx->r24 & 0XC0;
    // 0x800554A8: sra         $t5, $t7, 4
    ctx->r13 = S32(SIGNED(ctx->r15) >> 4);
    // 0x800554AC: sb          $t5, 0x3($t6)
    MEM_B(0X3, ctx->r14) = ctx->r13;
    // 0x800554B0: lbu         $t9, 0x21($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X21);
    // 0x800554B4: lbu         $t3, 0x20($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X20);
    // 0x800554B8: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800554BC: sll         $t0, $t9, 8
    ctx->r8 = S32(ctx->r25 << 8);
    // 0x800554C0: or          $t2, $t0, $t3
    ctx->r10 = ctx->r8 | ctx->r11;
    // 0x800554C4: sh          $t2, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r10;
    // 0x800554C8: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800554CC: lbu         $t4, 0x22($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X22);
    // 0x800554D0: sb          $t4, 0x2($t8)
    MEM_B(0X2, ctx->r24) = ctx->r12;
    // 0x800554D4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800554D8: lbu         $t5, 0x3($t7)
    ctx->r13 = MEM_BU(ctx->r15, 0X3);
    // 0x800554DC: beq         $t5, $zero, L_800554EC
    if (ctx->r13 == 0) {
        // 0x800554E0: nop
    
            goto L_800554EC;
    }
    // 0x800554E0: nop

    // 0x800554E4: b           L_800554F0
    // 0x800554E8: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_800554F0;
    // 0x800554E8: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_800554EC:
    // 0x800554EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800554F0:
    // 0x800554F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800554F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800554F8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_8005566C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005566C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80055670: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80055674: addiu       $t6, $t6, -0x4680
    ctx->r14 = ADD32(ctx->r14, -0X4680);
    // 0x80055678: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x8005567C: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_80055680:
    // 0x80055680: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x80055684: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x80055688: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8005568C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80055690: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80055694: sw          $zero, -0x4680($at)
    MEM_W(-0X4680, ctx->r1) = 0;
    // 0x80055698: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8005569C: slti        $at, $t0, 0x10
    ctx->r1 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // 0x800556A0: bne         $at, $zero, L_80055680
    if (ctx->r1 != 0) {
        // 0x800556A4: sw          $t0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r8;
            goto L_80055680;
    }
    // 0x800556A4: sw          $t0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r8;
    // 0x800556A8: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800556AC: lbu         $t9, -0x463F($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X463F);
    // 0x800556B0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800556B4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800556B8: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800556BC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800556C0: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800556C4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800556C8: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x800556CC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800556D0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800556D4: sw          $t1, -0x4644($at)
    MEM_W(-0X4644, ctx->r1) = ctx->r9;
    // 0x800556D8: sb          $t2, 0x4($sp)
    MEM_B(0X4, ctx->r29) = ctx->r10;
    // 0x800556DC: sb          $t3, 0x5($sp)
    MEM_B(0X5, ctx->r29) = ctx->r11;
    // 0x800556E0: sb          $t4, 0x6($sp)
    MEM_B(0X6, ctx->r29) = ctx->r12;
    // 0x800556E4: sb          $t5, 0x7($sp)
    MEM_B(0X7, ctx->r29) = ctx->r13;
    // 0x800556E8: sh          $t6, 0x8($sp)
    MEM_H(0X8, ctx->r29) = ctx->r14;
    // 0x800556EC: sb          $t7, 0xA($sp)
    MEM_B(0XA, ctx->r29) = ctx->r15;
    // 0x800556F0: sb          $t8, 0xB($sp)
    MEM_B(0XB, ctx->r29) = ctx->r24;
    // 0x800556F4: blez        $t9, L_80055744
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800556F8: sw          $zero, 0x0($sp)
        MEM_W(0X0, ctx->r29) = 0;
            goto L_80055744;
    }
    // 0x800556F8: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_800556FC:
    // 0x800556FC: addiu       $t1, $sp, 0x4
    ctx->r9 = ADD32(ctx->r29, 0X4);
    // 0x80055700: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x80055704: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x80055708: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8005570C: swl         $at, 0x0($t0)
    do_swl(rdram, 0X0, ctx->r8, ctx->r1);
    // 0x80055710: swr         $at, 0x3($t0)
    do_swr(rdram, 0X3, ctx->r8, ctx->r1);
    // 0x80055714: lw          $t3, 0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X4);
    // 0x80055718: swl         $t3, 0x4($t0)
    do_swl(rdram, 0X4, ctx->r8, ctx->r11);
    // 0x8005571C: swr         $t3, 0x7($t0)
    do_swr(rdram, 0X7, ctx->r8, ctx->r11);
    // 0x80055720: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x80055724: lbu         $t8, -0x463F($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X463F);
    // 0x80055728: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x8005572C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80055730: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80055734: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80055738: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x8005573C: bne         $at, $zero, L_800556FC
    if (ctx->r1 != 0) {
        // 0x80055740: sw          $t5, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r13;
            goto L_800556FC;
    }
    // 0x80055740: sw          $t5, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r13;
L_80055744:
    // 0x80055744: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x80055748: addiu       $t9, $zero, 0xFE
    ctx->r25 = ADD32(0, 0XFE);
    // 0x8005574C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x80055750: jr          $ra
    // 0x80055754: sb          $t9, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r25;
    TRACE_RETURN()
    return;
    // 0x80055754: sb          $t9, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r25;
;}
RECOMP_FUNC void func_80055920(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80055920: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80055924: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80055928: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005592C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80055930: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80055934: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80055938: jal         0x8005F1F0
    // 0x8005593C: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    func_8005F1F0(rdram, ctx);
        goto after_0;
    // 0x8005593C: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x80055940: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80055944: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80055948: ldc1        $f6, -0x6C30($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X6C30);
    // 0x8005594C: cvt.d.s     $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.d = CVT_D_S(ctx->f14.fl);
    // 0x80055950: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80055954: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80055958: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8005595C: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x80055960: div.s       $f12, $f14, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f14.fl, ctx->f10.fl);
    // 0x80055964: jal         0x8004F650
    // 0x80055968: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_8004F650(rdram, ctx);
        goto after_1;
    // 0x80055968: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x8005596C: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80055970: jal         0x8004F7C0
    // 0x80055974: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    func_8004F7C0(rdram, ctx);
        goto after_2;
    // 0x80055974: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80055978: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8005597C: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80055980: lwc1        $f14, 0x40($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80055984: div.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80055988: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8005598C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80055990: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80055994: add.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x80055998: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8005599C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800559A0: sub.s       $f12, $f14, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x800559A4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800559A8: swc1        $f4, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f4.u32l;
    // 0x800559AC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800559B0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800559B4: div.s       $f10, $f18, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800559B8: swc1        $f2, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f2.u32l;
    // 0x800559BC: div.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800559C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800559C4: swc1        $f10, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f10.u32l;
    // 0x800559C8: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x800559CC: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800559D0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800559D4: nop

    // 0x800559D8: swc1        $f6, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f6.u32l;
    // 0x800559DC: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800559E0: div.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800559E4: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
    // 0x800559E8: lwc1        $f0, 0x48($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800559EC: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800559F0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800559F4: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800559F8: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800559FC: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80055A00: beq         $v1, $a0, L_80055A44
    if (ctx->r3 == ctx->r4) {
        // 0x80055A04: lwc1        $f14, 0xC($v0)
        ctx->f14.u32l = MEM_W(ctx->r2, 0XC);
            goto L_80055A44;
    }
    // 0x80055A04: lwc1        $f14, 0xC($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XC);
L_80055A08:
    // 0x80055A08: mul.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80055A0C: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80055A10: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80055A14: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80055A18: lwc1        $f12, 0x18($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80055A1C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80055A20: mul.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80055A24: lwc1        $f14, 0x1C($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80055A28: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x80055A2C: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80055A30: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80055A34: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80055A38: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80055A3C: bne         $v1, $a0, L_80055A08
    if (ctx->r3 != ctx->r4) {
        // 0x80055A40: swc1        $f2, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
            goto L_80055A08;
    }
    // 0x80055A40: swc1        $f2, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
L_80055A44:
    // 0x80055A44: mul.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80055A48: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80055A4C: swc1        $f10, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f10.u32l;
    // 0x80055A50: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80055A54: nop

    // 0x80055A58: mul.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80055A5C: swc1        $f8, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f8.u32l;
    // 0x80055A60: swc1        $f4, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80055A64: swc1        $f2, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
    // 0x80055A68: beq         $a1, $zero, L_80055B40
    if (ctx->r5 == 0) {
        // 0x80055A6C: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_80055B40;
    }
    // 0x80055A6C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80055A70: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80055A74: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80055A78: cvt.d.s     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
    // 0x80055A7C: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x80055A80: c.le.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d <= ctx->f8.d;
    // 0x80055A84: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80055A88: bc1fl       L_80055A9C
    if (!c1cs) {
        // 0x80055A8C: mtc1        $at, $f11
        ctx->f_odd[(11 - 1) * 2] = ctx->r1;
            goto L_80055A9C;
    }
    goto skip_0;
    // 0x80055A8C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    skip_0:
    // 0x80055A90: b           L_80055B40
    // 0x80055A94: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
        goto L_80055B40;
    // 0x80055A94: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x80055A98: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
L_80055A9C:
    // 0x80055A9C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80055AA0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80055AA4: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80055AA8: div.d       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f0.d);
    // 0x80055AAC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80055AB0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80055AB4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80055AB8: nop

    // 0x80055ABC: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x80055AC0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80055AC4: nop

    // 0x80055AC8: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80055ACC: beql        $t8, $zero, L_80055B20
    if (ctx->r24 == 0) {
        // 0x80055AD0: mfc1        $t8, $f6
        ctx->r24 = (int32_t)ctx->f6.u32l;
            goto L_80055B20;
    }
    goto skip_1;
    // 0x80055AD0: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    skip_1:
    // 0x80055AD4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80055AD8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80055ADC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80055AE0: sub.d       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f6.d = ctx->f4.d - ctx->f6.d;
    // 0x80055AE4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80055AE8: nop

    // 0x80055AEC: cvt.w.d     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_D(ctx->f6.d);
    // 0x80055AF0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80055AF4: nop

    // 0x80055AF8: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80055AFC: bne         $t8, $zero, L_80055B14
    if (ctx->r24 != 0) {
        // 0x80055B00: nop
    
            goto L_80055B14;
    }
    // 0x80055B00: nop

    // 0x80055B04: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80055B08: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80055B0C: b           L_80055B2C
    // 0x80055B10: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_80055B2C;
    // 0x80055B10: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_80055B14:
    // 0x80055B14: b           L_80055B2C
    // 0x80055B18: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_80055B2C;
    // 0x80055B18: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80055B1C: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
L_80055B20:
    // 0x80055B20: nop

    // 0x80055B24: bltz        $t8, L_80055B14
    if (SIGNED(ctx->r24) < 0) {
        // 0x80055B28: nop
    
            goto L_80055B14;
    }
    // 0x80055B28: nop

L_80055B2C:
    // 0x80055B2C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80055B30: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80055B34: bgtz        $t9, L_80055B40
    if (SIGNED(ctx->r25) > 0) {
        // 0x80055B38: sh          $t8, 0x0($a1)
        MEM_H(0X0, ctx->r5) = ctx->r24;
            goto L_80055B40;
    }
    // 0x80055B38: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x80055B3C: sh          $t0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r8;
L_80055B40:
    // 0x80055B40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80055B44: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80055B48: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80055B50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80055B50: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80055B54: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80055B58: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x80055B5C: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80055B60: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80055B64: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80055B68: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80055B6C: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80055B70: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x80055B74: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80055B78: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80055B7C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80055B80: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80055B84: jal         0x80055920
    // 0x80055B88: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    func_80055920(rdram, ctx);
        goto after_0;
    // 0x80055B88: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x80055B8C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80055B90: jal         0x8005F0F0
    // 0x80055B94: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    func_8005F0F0(rdram, ctx);
        goto after_1;
    // 0x80055B94: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    after_1:
    // 0x80055B98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80055B9C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80055BA0: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80055BB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80055BB0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80055BB4: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80055BB8: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80055BBC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80055BC0: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80055BC4: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80055BC8: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80055BCC: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80055BD0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80055BD4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80055BD8: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80055BDC: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80055BE0: jal         0x8005F1F0
    // 0x80055BE4: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    func_8005F1F0(rdram, ctx);
        goto after_0;
    // 0x80055BE4: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80055BE8: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80055BEC: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80055BF0: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80055BF4: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80055BF8: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80055BFC: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80055C00: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80055C04: sub.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80055C08: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80055C0C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80055C10: sub.s       $f24, $f4, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80055C14: mul.s       $f10, $f22, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x80055C18: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80055C1C: mul.s       $f6, $f24, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x80055C20: jal         0x8004F640
    // 0x80055C24: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    func_8004F640(rdram, ctx);
        goto after_1;
    // 0x80055C24: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
    // 0x80055C28: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x80055C2C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80055C30: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80055C34: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x80055C38: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80055C3C: div.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x80055C40: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80055C44: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
    // 0x80055C48: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80055C4C: nop

    // 0x80055C50: mul.s       $f22, $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x80055C54: nop

    // 0x80055C58: mul.s       $f24, $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f2.fl);
    // 0x80055C5C: nop

    // 0x80055C60: mul.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x80055C64: nop

    // 0x80055C68: mul.s       $f4, $f10, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x80055C6C: sub.s       $f26, $f8, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80055C70: mul.s       $f8, $f10, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80055C74: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80055C78: mul.s       $f10, $f4, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x80055C7C: sub.s       $f28, $f8, $f10
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f28.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80055C80: mul.s       $f8, $f4, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x80055C84: nop

    // 0x80055C88: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80055C8C: sub.s       $f30, $f8, $f10
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f30.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80055C90: mul.s       $f4, $f26, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x80055C94: nop

    // 0x80055C98: mul.s       $f6, $f28, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f28.fl, ctx->f28.fl);
    // 0x80055C9C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80055CA0: mul.s       $f10, $f30, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f30.fl, ctx->f30.fl);
    // 0x80055CA4: jal         0x8004F640
    // 0x80055CA8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    func_8004F640(rdram, ctx);
        goto after_2;
    // 0x80055CA8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x80055CAC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80055CB0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80055CB4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80055CB8: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80055CBC: div.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x80055CC0: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x80055CC4: mul.s       $f26, $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f26.fl = MUL_S(ctx->f26.fl, ctx->f2.fl);
    // 0x80055CC8: nop

    // 0x80055CCC: mul.s       $f28, $f28, $f2
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f28.fl = MUL_S(ctx->f28.fl, ctx->f2.fl);
    // 0x80055CD0: nop

    // 0x80055CD4: mul.s       $f30, $f30, $f2
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f30.fl = MUL_S(ctx->f30.fl, ctx->f2.fl);
    // 0x80055CD8: nop

    // 0x80055CDC: mul.s       $f10, $f22, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f30.fl);
    // 0x80055CE0: nop

    // 0x80055CE4: mul.s       $f4, $f24, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f28.fl);
    // 0x80055CE8: nop

    // 0x80055CEC: mul.s       $f6, $f24, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f26.fl);
    // 0x80055CF0: nop

    // 0x80055CF4: mul.s       $f8, $f20, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f30.fl);
    // 0x80055CF8: sub.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80055CFC: mul.s       $f10, $f20, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f28.fl);
    // 0x80055D00: nop

    // 0x80055D04: mul.s       $f4, $f22, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f26.fl);
    // 0x80055D08: swc1        $f14, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f14.u32l;
    // 0x80055D0C: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80055D10: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80055D14: nop

    // 0x80055D18: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80055D1C: swc1        $f16, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f16.u32l;
    // 0x80055D20: sub.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80055D24: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x80055D28: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80055D2C: swc1        $f18, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f18.u32l;
    // 0x80055D30: jal         0x8004F640
    // 0x80055D34: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    func_8004F640(rdram, ctx);
        goto after_3;
    // 0x80055D34: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    after_3:
    // 0x80055D38: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80055D3C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80055D40: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80055D44: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x80055D48: lwc1        $f14, 0x6C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80055D4C: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x80055D50: lwc1        $f12, 0x70($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80055D54: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80055D58: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80055D5C: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
    // 0x80055D60: mul.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80055D64: nop

    // 0x80055D68: mul.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x80055D6C: nop

    // 0x80055D70: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80055D74: swc1        $f6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f6.u32l;
    // 0x80055D78: swc1        $f26, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f26.u32l;
    // 0x80055D7C: swc1        $f28, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f28.u32l;
    // 0x80055D80: swc1        $f30, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f30.u32l;
    // 0x80055D84: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80055D88: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80055D8C: mul.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x80055D90: nop

    // 0x80055D94: mul.s       $f6, $f4, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f28.fl);
    // 0x80055D98: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80055D9C: swc1        $f14, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f14.u32l;
    // 0x80055DA0: swc1        $f12, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f12.u32l;
    // 0x80055DA4: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80055DA8: mul.s       $f10, $f4, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f30.fl);
    // 0x80055DAC: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80055DB0: neg.s       $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = -ctx->f6.fl;
    // 0x80055DB4: swc1        $f4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
    // 0x80055DB8: lwc1        $f0, 0x74($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80055DBC: swc1        $f12, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f12.u32l;
    // 0x80055DC0: swc1        $f14, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f14.u32l;
    // 0x80055DC4: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80055DC8: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80055DCC: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80055DD0: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80055DD4: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80055DD8: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80055DDC: swc1        $f20, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f20.u32l;
    // 0x80055DE0: mul.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x80055DE4: swc1        $f22, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f22.u32l;
    // 0x80055DE8: swc1        $f24, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f24.u32l;
    // 0x80055DEC: mul.s       $f4, $f12, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x80055DF0: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80055DF4: mul.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80055DF8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80055DFC: nop

    // 0x80055E00: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x80055E04: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x80055E08: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x80055E0C: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80055E10: mul.s       $f8, $f14, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x80055E14: nop

    // 0x80055E18: mul.s       $f6, $f12, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f22.fl);
    // 0x80055E1C: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x80055E20: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    // 0x80055E24: mul.s       $f4, $f2, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x80055E28: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80055E2C: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80055E30: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80055E34: neg.s       $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = -ctx->f8.fl;
    // 0x80055E38: swc1        $f10, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f10.u32l;
    // 0x80055E3C: swc1        $f6, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f6.u32l;
    // 0x80055E40: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80055E44: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80055E48: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80055E4C: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80055E50: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80055E54: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80055E58: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80055E5C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80055E60: jr          $ra
    // 0x80055E64: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    TRACE_RETURN()
    return;
    // 0x80055E64: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80055E68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80055E68: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80055E6C: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80055E70: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80055E74: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80055E78: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x80055E7C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80055E80: lwc1        $f4, 0x94($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80055E84: lwc1        $f6, 0x84($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80055E88: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80055E8C: lwc1        $f10, 0x8C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80055E90: lwc1        $f18, 0x90($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80055E94: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80055E98: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x80055E9C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80055EA0: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80055EA4: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80055EA8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80055EAC: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x80055EB0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80055EB4: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x80055EB8: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x80055EBC: jal         0x80055BB0
    // 0x80055EC0: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    func_80055BB0(rdram, ctx);
        goto after_0;
    // 0x80055EC0: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x80055EC4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80055EC8: jal         0x8005F0F0
    // 0x80055ECC: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    func_8005F0F0(rdram, ctx);
        goto after_1;
    // 0x80055ECC: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    after_1:
    // 0x80055ED0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80055ED4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80055ED8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80056610(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
;}
RECOMP_FUNC void func_80056C2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
;}
RECOMP_FUNC void func_80056F04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80056F04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
;}
RECOMP_FUNC void func_80056F10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80056F10: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80056F14: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80056F18: sll         $s3, $a1, 16
    ctx->r19 = S32(ctx->r5 << 16);
    // 0x80056F1C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80056F20: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80056F24: sra         $t6, $s3, 16
    ctx->r14 = S32(SIGNED(ctx->r19) >> 16);
    // 0x80056F28: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80056F2C: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
    // 0x80056F30: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80056F34: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80056F38: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80056F3C: jal         0x80059290
    // 0x80056F40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80056F40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80056F44: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80056F48: lw          $s0, 0x8($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X8);
    // 0x80056F4C: beq         $s0, $zero, L_80056F98
    if (ctx->r16 == 0) {
        // 0x80056F50: nop
    
            goto L_80056F98;
    }
    // 0x80056F50: nop

L_80056F54:
    // 0x80056F54: lh          $t7, 0xC($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XC);
    // 0x80056F58: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x80056F5C: bne         $s3, $t7, L_80056F90
    if (ctx->r19 != ctx->r15) {
        // 0x80056F60: nop
    
            goto L_80056F90;
    }
    // 0x80056F60: nop

    // 0x80056F64: beq         $s1, $zero, L_80056F7C
    if (ctx->r17 == 0) {
        // 0x80056F68: nop
    
            goto L_80056F7C;
    }
    // 0x80056F68: nop

    // 0x80056F6C: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
    // 0x80056F70: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x80056F74: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80056F78: sw          $t0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r8;
L_80056F7C:
    // 0x80056F7C: jal         0x800526C0
    // 0x80056F80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800526C0(rdram, ctx);
        goto after_1;
    // 0x80056F80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80056F84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80056F88: jal         0x800526F0
    // 0x80056F8C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800526F0(rdram, ctx);
        goto after_2;
    // 0x80056F8C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
L_80056F90:
    // 0x80056F90: bne         $s1, $zero, L_80056F54
    if (ctx->r17 != 0) {
        // 0x80056F94: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80056F54;
    }
    // 0x80056F94: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_80056F98:
    // 0x80056F98: jal         0x80059290
    // 0x80056F9C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x80056F9C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x80056FA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80056FA4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80056FA8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80056FAC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80056FB0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80056FB4: jr          $ra
    // 0x80056FB8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    TRACE_RETURN()
    return;
    // 0x80056FB8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80056FBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80056FBC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80056FC0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80056FC4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80056FC8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80056FCC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80056FD0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80056FD4: jal         0x80059290
    // 0x80056FD8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80056FD8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80056FDC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80056FE0: lw          $s0, 0x8($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X8);
    // 0x80056FE4: beq         $s0, $zero, L_8005700C
    if (ctx->r16 == 0) {
        // 0x80056FE8: nop
    
            goto L_8005700C;
    }
    // 0x80056FE8: nop

L_80056FEC:
    // 0x80056FEC: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x80056FF0: jal         0x800526C0
    // 0x80056FF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800526C0(rdram, ctx);
        goto after_1;
    // 0x80056FF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80056FF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80056FFC: jal         0x800526F0
    // 0x80057000: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800526F0(rdram, ctx);
        goto after_2;
    // 0x80057000: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x80057004: bne         $s1, $zero, L_80056FEC
    if (ctx->r17 != 0) {
        // 0x80057008: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80056FEC;
    }
    // 0x80057008: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_8005700C:
    // 0x8005700C: jal         0x80059290
    // 0x80057010: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x80057010: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x80057014: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80057018: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005701C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80057020: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80057024: jr          $ra
    // 0x80057028: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    TRACE_RETURN()
    return;
    // 0x80057028: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8005702C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005702C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80057030: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80057034: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80057038: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8005703C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80057040: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80057044: jal         0x80059290
    // 0x80057048: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80057048: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x8005704C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80057050: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80057054: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80057058: lw          $t0, 0x0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X0);
    // 0x8005705C: bne         $t0, $zero, L_80057074
    if (ctx->r8 != 0) {
        // 0x80057060: or          $a0, $t0, $zero
        ctx->r4 = ctx->r8 | 0;
            goto L_80057074;
    }
    // 0x80057060: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x80057064: jal         0x80059290
    // 0x80057068: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x80057068: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8005706C: b           L_80057144
    // 0x80057070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80057144;
    // 0x80057070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80057074:
    // 0x80057074: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80057078: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x8005707C: jal         0x800526C0
    // 0x80057080: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    func_800526C0(rdram, ctx);
        goto after_2;
    // 0x80057080: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_2:
    // 0x80057084: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80057088: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8005708C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80057090: jal         0x80060E90
    // 0x80057094: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    func_80060E90(rdram, ctx);
        goto after_3;
    // 0x80057094: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    after_3:
    // 0x80057098: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8005709C: lui         $at, 0x7FFF
    ctx->r1 = S32(0X7FFF << 16);
    // 0x800570A0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800570A4: bne         $a3, $at, L_800570B4
    if (ctx->r7 != ctx->r1) {
        // 0x800570A8: lw          $t0, 0x2C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X2C);
            goto L_800570B4;
    }
    // 0x800570A8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800570AC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800570B0: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
L_800570B4:
    // 0x800570B4: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x800570B8: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800570BC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800570C0: beq         $v0, $at, L_80057138
    if (ctx->r2 == ctx->r1) {
        // 0x800570C4: addiu       $a1, $v0, 0x8
        ctx->r5 = ADD32(ctx->r2, 0X8);
            goto L_80057138;
    }
    // 0x800570C4: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
L_800570C8:
    // 0x800570C8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800570CC: bnel        $v0, $zero, L_800570FC
    if (ctx->r2 != 0) {
        // 0x800570D0: lw          $v1, 0x8($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X8);
            goto L_800570FC;
    }
    goto skip_0;
    // 0x800570D0: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    skip_0:
    // 0x800570D4: beql        $t8, $zero, L_800570E8
    if (ctx->r24 == 0) {
        // 0x800570D8: sw          $a3, 0x8($t0)
        MEM_W(0X8, ctx->r8) = ctx->r7;
            goto L_800570E8;
    }
    goto skip_1;
    // 0x800570D8: sw          $a3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r7;
    skip_1:
    // 0x800570DC: b           L_800570E8
    // 0x800570E0: sw          $zero, 0x8($t0)
    MEM_W(0X8, ctx->r8) = 0;
        goto L_800570E8;
    // 0x800570E0: sw          $zero, 0x8($t0)
    MEM_W(0X8, ctx->r8) = 0;
    // 0x800570E4: sw          $a3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r7;
L_800570E8:
    // 0x800570E8: jal         0x800526F0
    // 0x800570EC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_800526F0(rdram, ctx);
        goto after_4;
    // 0x800570EC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_4:
    // 0x800570F0: b           L_80057138
    // 0x800570F4: nop

        goto L_80057138;
    // 0x800570F4: nop

    // 0x800570F8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
L_800570FC:
    // 0x800570FC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80057100: slt         $at, $a3, $v1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80057104: beql        $at, $zero, L_80057130
    if (ctx->r1 == 0) {
        // 0x80057108: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80057130;
    }
    goto skip_2;
    // 0x80057108: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    skip_2:
    // 0x8005710C: sw          $a3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r7;
    // 0x80057110: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    // 0x80057114: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x80057118: subu        $t1, $t9, $a3
    ctx->r9 = SUB32(ctx->r25, ctx->r7);
    // 0x8005711C: jal         0x800526F0
    // 0x80057120: sw          $t1, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r9;
    func_800526F0(rdram, ctx);
        goto after_5;
    // 0x80057120: sw          $t1, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r9;
    after_5:
    // 0x80057124: b           L_80057138
    // 0x80057128: nop

        goto L_80057138;
    // 0x80057128: nop

    // 0x8005712C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80057130:
    // 0x80057130: bne         $v0, $zero, L_800570C8
    if (ctx->r2 != 0) {
        // 0x80057134: subu        $a3, $a3, $v1
        ctx->r7 = SUB32(ctx->r7, ctx->r3);
            goto L_800570C8;
    }
    // 0x80057134: subu        $a3, $a3, $v1
    ctx->r7 = SUB32(ctx->r7, ctx->r3);
L_80057138:
    // 0x80057138: jal         0x80059290
    // 0x8005713C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    osSetIntMask_recomp(rdram, ctx);
        goto after_6;
    // 0x8005713C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_6:
    // 0x80057140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80057144:
    // 0x80057144: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80057148: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80057150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80057150: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80057154: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80057158: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8005715C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80057160: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80057164: jal         0x80059290
    // 0x80057168: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80057168: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8005716C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80057170: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80057174: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80057178: lw          $s0, 0x8($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X8);
    // 0x8005717C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80057180: beql        $s0, $zero, L_800571B8
    if (ctx->r16 == 0) {
        // 0x80057184: addiu       $t7, $zero, -0x1
        ctx->r15 = ADD32(0, -0X1);
            goto L_800571B8;
    }
    goto skip_0;
    // 0x80057184: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    skip_0:
    // 0x80057188: jal         0x800526C0
    // 0x8005718C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800526C0(rdram, ctx);
        goto after_1;
    // 0x8005718C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80057190: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    // 0x80057194: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80057198: jal         0x80060E90
    // 0x8005719C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    func_80060E90(rdram, ctx);
        goto after_2;
    // 0x8005719C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_2:
    // 0x800571A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800571A4: jal         0x800526F0
    // 0x800571A8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800526F0(rdram, ctx);
        goto after_3;
    // 0x800571A8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x800571AC: b           L_800571BC
    // 0x800571B0: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
        goto L_800571BC;
    // 0x800571B0: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x800571B4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_800571B8:
    // 0x800571B8: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
L_800571BC:
    // 0x800571BC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800571C0: jal         0x80059290
    // 0x800571C4: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    osSetIntMask_recomp(rdram, ctx);
        goto after_4;
    // 0x800571C4: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_4:
    // 0x800571C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800571CC: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x800571D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800571D4: jr          $ra
    // 0x800571D8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    TRACE_RETURN()
    return;
    // 0x800571D8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800571DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800571DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800571E0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800571E4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800571E8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800571EC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800571F0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800571F4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800571F8: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x800571FC: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x80057200: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x80057204: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x80057208: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8005720C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80057210: blez        $a2, L_80057234
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80057214: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80057234;
    }
    // 0x80057214: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80057218: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
L_8005721C:
    // 0x8005721C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80057220: jal         0x800526F0
    // 0x80057224: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800526F0(rdram, ctx);
        goto after_0;
    // 0x80057224: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x80057228: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8005722C: bne         $s0, $s3, L_8005721C
    if (ctx->r16 != ctx->r19) {
        // 0x80057230: addiu       $s1, $s1, 0x1C
        ctx->r17 = ADD32(ctx->r17, 0X1C);
            goto L_8005721C;
    }
    // 0x80057230: addiu       $s1, $s1, 0x1C
    ctx->r17 = ADD32(ctx->r17, 0X1C);
L_80057234:
    // 0x80057234: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80057238: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8005723C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80057240: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80057244: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80057248: jr          $ra
    // 0x8005724C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    TRACE_RETURN()
    return;
    // 0x8005724C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80057250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80057250: lw          $t6, 0x60($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X60);
    // 0x80057254: sll         $v0, $a2, 4
    ctx->r2 = S32(ctx->r6 << 4);
    // 0x80057258: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8005725C: sw          $a1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r5;
    // 0x80057260: lw          $t9, 0x60($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X60);
    // 0x80057264: lbu         $t8, 0x1($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X1);
    // 0x80057268: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x8005726C: sb          $t8, 0x7($t0)
    MEM_B(0X7, ctx->r8) = ctx->r24;
    // 0x80057270: lw          $t2, 0x60($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X60);
    // 0x80057274: lbu         $t1, 0x0($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X0);
    // 0x80057278: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x8005727C: sb          $t1, 0x9($t3)
    MEM_B(0X9, ctx->r11) = ctx->r9;
    // 0x80057280: lw          $t5, 0x60($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X60);
    // 0x80057284: lbu         $t4, 0x2($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X2);
    // 0x80057288: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8005728C: sb          $t4, 0x8($t6)
    MEM_B(0X8, ctx->r14) = ctx->r12;
    // 0x80057290: lw          $t9, 0x60($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X60);
    // 0x80057294: lh          $t7, 0xC($a1)
    ctx->r15 = MEM_H(ctx->r5, 0XC);
    // 0x80057298: addu        $t8, $t9, $v0
    ctx->r24 = ADD32(ctx->r25, ctx->r2);
    // 0x8005729C: jr          $ra
    // 0x800572A0: sh          $t7, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r15;
    TRACE_RETURN()
    return;
    // 0x800572A0: sh          $t7, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r15;
;}
RECOMP_FUNC void func_800572A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800572A4: lw          $t6, 0x60($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X60);
    // 0x800572A8: sll         $v0, $a1, 4
    ctx->r2 = S32(ctx->r5 << 4);
    // 0x800572AC: addiu       $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
    // 0x800572B0: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800572B4: sb          $zero, 0x6($t7)
    MEM_B(0X6, ctx->r15) = 0;
    // 0x800572B8: lw          $t8, 0x60($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X60);
    // 0x800572BC: addiu       $t3, $zero, 0x7F
    ctx->r11 = ADD32(0, 0X7F);
    // 0x800572C0: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x800572C4: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800572C8: sb          $zero, 0xA($t9)
    MEM_B(0XA, ctx->r25) = 0;
    // 0x800572CC: lw          $t1, 0x60($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X60);
    // 0x800572D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800572D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800572D8: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x800572DC: sb          $t0, 0x7($t2)
    MEM_B(0X7, ctx->r10) = ctx->r8;
    // 0x800572E0: lw          $t4, 0x60($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X60);
    // 0x800572E4: addiu       $t0, $zero, 0xC8
    ctx->r8 = ADD32(0, 0XC8);
    // 0x800572E8: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800572EC: sb          $t3, 0x9($t5)
    MEM_B(0X9, ctx->r13) = ctx->r11;
    // 0x800572F0: lw          $t7, 0x60($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X60);
    // 0x800572F4: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800572F8: sb          $t6, 0x8($t8)
    MEM_B(0X8, ctx->r24) = ctx->r14;
    // 0x800572FC: lw          $t9, 0x60($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X60);
    // 0x80057300: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x80057304: sb          $zero, 0xB($t1)
    MEM_B(0XB, ctx->r9) = 0;
    // 0x80057308: lw          $t2, 0x60($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X60);
    // 0x8005730C: addu        $t4, $t2, $v0
    ctx->r12 = ADD32(ctx->r10, ctx->r2);
    // 0x80057310: sh          $t0, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r8;
    // 0x80057314: lw          $t3, 0x60($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X60);
    // 0x80057318: addu        $t5, $t3, $v0
    ctx->r13 = ADD32(ctx->r11, ctx->r2);
    // 0x8005731C: jr          $ra
    // 0x80057320: swc1        $f4, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f4.u32l;
    TRACE_RETURN()
    return;
    // 0x80057320: swc1        $f4, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_80057324(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80057324: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80057328: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8005732C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80057330: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80057334: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80057338: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005733C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80057340: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80057344: lw          $s1, 0xC($v0)
    ctx->r17 = MEM_W(ctx->r2, 0XC);
L_80057348:
    // 0x80057348: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8005734C: beql        $s1, $zero, L_80057348
    if (ctx->r17 == 0) {
        // 0x80057350: lw          $s1, 0xC($v0)
        ctx->r17 = MEM_W(ctx->r2, 0XC);
            goto L_80057348;
    }
    goto skip_0;
    // 0x80057350: lw          $s1, 0xC($v0)
    ctx->r17 = MEM_W(ctx->r2, 0XC);
    skip_0:
    // 0x80057354: lbu         $t6, 0x34($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X34);
    // 0x80057358: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8005735C: blez        $t6, L_80057390
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80057360: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80057390;
    }
    // 0x80057360: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80057364:
    // 0x80057364: jal         0x800572A4
    // 0x80057368: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800572A4(rdram, ctx);
        goto after_0;
    // 0x80057368: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x8005736C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80057370: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80057374: jal         0x80057250
    // 0x80057378: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80057250(rdram, ctx);
        goto after_1;
    // 0x80057378: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_1:
    // 0x8005737C: lbu         $t7, 0x34($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X34);
    // 0x80057380: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80057384: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80057388: bnel        $at, $zero, L_80057364
    if (ctx->r1 != 0) {
        // 0x8005738C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80057364;
    }
    goto skip_1;
    // 0x8005738C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_1:
L_80057390:
    // 0x80057390: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80057394: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80057398: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x8005739C: beql        $t9, $zero, L_800573C4
    if (ctx->r25 == 0) {
        // 0x800573A0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800573C4;
    }
    goto skip_2;
    // 0x800573A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x800573A4: jal         0x800572A4
    // 0x800573A8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800572A4(rdram, ctx);
        goto after_2;
    // 0x800573A8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x800573AC: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800573B0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800573B4: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x800573B8: jal         0x80057250
    // 0x800573BC: lw          $a1, 0x8($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X8);
    func_80057250(rdram, ctx);
        goto after_3;
    // 0x800573BC: lw          $a1, 0x8($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X8);
    after_3:
    // 0x800573C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800573C4:
    // 0x800573C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800573C8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800573CC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800573D0: jr          $ra
    // 0x800573D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    TRACE_RETURN()
    return;
    // 0x800573D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800573D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800573D8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800573E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800573E0: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x800573E4: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
    // 0x800573E8: subu        $v1, $t6, $a1
    ctx->r3 = SUB32(ctx->r14, ctx->r5);
    // 0x800573EC: bltz        $v1, L_800573FC
    if (SIGNED(ctx->r3) < 0) {
        // 0x800573F0: nop
    
            goto L_800573FC;
    }
    // 0x800573F0: nop

    // 0x800573F4: jr          $ra
    // 0x800573F8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    TRACE_RETURN()
    return;
    // 0x800573F8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800573FC:
    // 0x800573FC: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80057404(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80057404: lbu         $t6, 0x36($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X36);
    // 0x80057408: lbu         $t7, 0x33($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X33);
    // 0x8005740C: lbu         $t9, 0x30($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X30);
    // 0x80057410: lbu         $t2, 0x31($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X31);
    // 0x80057414: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80057418: lw          $t1, 0x60($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X60);
    // 0x8005741C: lw          $t6, 0x20($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X20);
    // 0x80057420: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x80057424: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80057428: lbu         $t5, 0x9($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X9);
    // 0x8005742C: lbu         $t7, 0xD($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XD);
    // 0x80057430: mflo        $t8
    ctx->r24 = lo;
    // 0x80057434: nop

    // 0x80057438: nop

    // 0x8005743C: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80057440: lh          $t9, 0x32($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X32);
    // 0x80057444: mflo        $v1
    ctx->r3 = lo;
    // 0x80057448: sra         $t0, $v1, 6
    ctx->r8 = S32(SIGNED(ctx->r3) >> 6);
    // 0x8005744C: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80057450: multu       $t5, $t7
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80057454: mflo        $t8
    ctx->r24 = lo;
    // 0x80057458: nop

    // 0x8005745C: nop

    // 0x80057460: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80057464: mflo        $a2
    ctx->r6 = lo;
    // 0x80057468: sra         $t0, $a2, 14
    ctx->r8 = S32(SIGNED(ctx->r6) >> 14);
    // 0x8005746C: nop

    // 0x80057470: multu       $v1, $t0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80057474: mflo        $v1
    ctx->r3 = lo;
    // 0x80057478: srl         $t2, $v1, 15
    ctx->r10 = S32(U32(ctx->r3) >> 15);
    // 0x8005747C: sll         $v0, $t2, 16
    ctx->r2 = S32(ctx->r10 << 16);
    // 0x80057480: sra         $t1, $v0, 16
    ctx->r9 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80057484: jr          $ra
    // 0x80057488: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    TRACE_RETURN()
    return;
    // 0x80057488: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
;}
RECOMP_FUNC void func_8005748C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8005748C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80057490: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80057494: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80057498: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8005749C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800574A0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800574A4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800574A8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800574AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800574B0: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x800574B4: lw          $s6, 0x10($a1)
    ctx->r22 = MEM_W(ctx->r5, 0X10);
    // 0x800574B8: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800574BC: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x800574C0: lbu         $t6, 0x34($s6)
    ctx->r14 = MEM_BU(ctx->r22, 0X34);
    // 0x800574C4: bnel        $t6, $zero, L_80057530
    if (ctx->r14 != 0) {
        // 0x800574C8: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_80057530;
    }
    goto skip_0;
    // 0x800574C8: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    skip_0:
    // 0x800574CC: lw          $s0, 0x50($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X50);
    // 0x800574D0: addiu       $s3, $zero, 0x6
    ctx->r19 = ADD32(0, 0X6);
    // 0x800574D4: beql        $s0, $zero, L_80057530
    if (ctx->r16 == 0) {
        // 0x800574D8: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_80057530;
    }
    goto skip_1;
    // 0x800574D8: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    skip_1:
L_800574DC:
    // 0x800574DC: lh          $t7, 0xC($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XC);
    // 0x800574E0: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800574E4: bne         $s3, $t7, L_80057524
    if (ctx->r19 != ctx->r15) {
        // 0x800574E8: nop
    
            goto L_80057524;
    }
    // 0x800574E8: nop

    // 0x800574EC: lw          $t8, 0x10($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X10);
    // 0x800574F0: bne         $s5, $t8, L_80057524
    if (ctx->r21 != ctx->r24) {
        // 0x800574F4: nop
    
            goto L_80057524;
    }
    // 0x800574F4: nop

    // 0x800574F8: beq         $s1, $zero, L_80057510
    if (ctx->r17 == 0) {
        // 0x800574FC: addiu       $s2, $s4, 0x48
        ctx->r18 = ADD32(ctx->r20, 0X48);
            goto L_80057510;
    }
    // 0x800574FC: addiu       $s2, $s4, 0x48
    ctx->r18 = ADD32(ctx->r20, 0X48);
    // 0x80057500: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x80057504: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x80057508: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8005750C: sw          $t1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r9;
L_80057510:
    // 0x80057510: jal         0x800526C0
    // 0x80057514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800526C0(rdram, ctx);
        goto after_0;
    // 0x80057514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80057518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005751C: jal         0x800526F0
    // 0x80057520: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800526F0(rdram, ctx);
        goto after_1;
    // 0x80057520: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
L_80057524:
    // 0x80057524: bne         $s1, $zero, L_800574DC
    if (ctx->r17 != 0) {
        // 0x80057528: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800574DC;
    }
    // 0x80057528: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x8005752C: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
L_80057530:
    // 0x80057530: sb          $zero, 0x33($s6)
    MEM_B(0X33, ctx->r22) = 0;
    // 0x80057534: sb          $t2, 0x34($s6)
    MEM_B(0X34, ctx->r22) = ctx->r10;
    // 0x80057538: sb          $zero, 0x30($s6)
    MEM_B(0X30, ctx->r22) = 0;
    // 0x8005753C: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x80057540: lw          $t3, 0x1C($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X1C);
    // 0x80057544: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80057548: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005754C: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80057550: sw          $t5, 0x24($s6)
    MEM_W(0X24, ctx->r22) = ctx->r13;
    // 0x80057554: lw          $a0, 0x14($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X14);
    // 0x80057558: jal         0x80061530
    // 0x8005755C: addiu       $s2, $s4, 0x48
    ctx->r18 = ADD32(ctx->r20, 0X48);
    func_80061530(rdram, ctx);
        goto after_2;
    // 0x8005755C: addiu       $s2, $s4, 0x48
    ctx->r18 = ADD32(ctx->r20, 0X48);
    after_2:
    // 0x80057560: lw          $a0, 0x14($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X14);
    // 0x80057564: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80057568: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005756C: jal         0x80058D10
    // 0x80057570: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    func_80058D10(rdram, ctx);
        goto after_3;
    // 0x80057570: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    after_3:
    // 0x80057574: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80057578: sh          $t6, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r14;
    // 0x8005757C: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x80057580: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80057584: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x80057588: jal         0x8005702C
    // 0x8005758C: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    func_8005702C(rdram, ctx);
        goto after_4;
    // 0x8005758C: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    after_4:
    // 0x80057590: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80057594: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80057598: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8005759C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800575A0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800575A4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800575A8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800575AC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800575B0: jr          $ra
    // 0x800575B4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    TRACE_RETURN()
    return;
    // 0x800575B4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_800575B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800575B8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800575BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800575C0: lw          $a3, 0x50($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X50);
    // 0x800575C4: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x800575C8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800575CC: beq         $a3, $zero, L_8005764C
    if (ctx->r7 == 0) {
        // 0x800575D0: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_8005764C;
    }
    // 0x800575D0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800575D4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
L_800575D8:
    // 0x800575D8: lh          $t6, 0xC($a3)
    ctx->r14 = MEM_H(ctx->r7, 0XC);
    // 0x800575DC: lw          $v1, 0x8($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X8);
    // 0x800575E0: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x800575E4: bne         $a0, $t6, L_80057644
    if (ctx->r4 != ctx->r14) {
        // 0x800575E8: addu        $t0, $t0, $v1
        ctx->r8 = ADD32(ctx->r8, ctx->r3);
            goto L_80057644;
    }
    // 0x800575E8: addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // 0x800575EC: lw          $t7, 0x10($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X10);
    // 0x800575F0: bne         $a1, $t7, L_80057644
    if (ctx->r5 != ctx->r15) {
        // 0x800575F4: slt         $at, $a2, $t0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_80057644;
    }
    // 0x800575F4: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800575F8: beq         $at, $zero, L_8005763C
    if (ctx->r1 == 0) {
        // 0x800575FC: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8005763C;
    }
    // 0x800575FC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80057600: beql        $v0, $zero, L_80057618
    if (ctx->r2 == 0) {
        // 0x80057604: sw          $a3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r7;
            goto L_80057618;
    }
    goto skip_0;
    // 0x80057604: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    skip_0:
    // 0x80057608: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x8005760C: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x80057610: sw          $t9, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r25;
    // 0x80057614: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
L_80057618:
    // 0x80057618: sb          $t1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r9;
    // 0x8005761C: jal         0x800526C0
    // 0x80057620: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    func_800526C0(rdram, ctx);
        goto after_0;
    // 0x80057620: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    after_0:
    // 0x80057624: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80057628: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8005762C: jal         0x800526F0
    // 0x80057630: addiu       $a1, $t2, 0x48
    ctx->r5 = ADD32(ctx->r10, 0X48);
    func_800526F0(rdram, ctx);
        goto after_1;
    // 0x80057630: addiu       $a1, $t2, 0x48
    ctx->r5 = ADD32(ctx->r10, 0X48);
    after_1:
    // 0x80057634: b           L_8005764C
    // 0x80057638: lbu         $t1, 0x1F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X1F);
        goto L_8005764C;
    // 0x80057638: lbu         $t1, 0x1F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X1F);
L_8005763C:
    // 0x8005763C: b           L_8005764C
    // 0x80057640: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
        goto L_8005764C;
    // 0x80057640: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_80057644:
    // 0x80057644: bne         $v0, $zero, L_800575D8
    if (ctx->r2 != 0) {
        // 0x80057648: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800575D8;
    }
    // 0x80057648: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_8005764C:
    // 0x8005764C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80057650: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80057654: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80057658: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80057660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80057660: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x80057664: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80057668: addiu       $a2, $a1, -0x4
    ctx->r6 = ADD32(ctx->r5, -0X4);
    // 0x8005766C: beq         $v1, $zero, L_800576C8
    if (ctx->r3 == 0) {
        // 0x80057670: nop
    
            goto L_800576C8;
    }
    // 0x80057670: nop

L_80057674:
    // 0x80057674: bnel        $v1, $a2, L_800576BC
    if (ctx->r3 != ctx->r6) {
        // 0x80057678: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800576BC;
    }
    goto skip_0;
    // 0x80057678: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_0:
    // 0x8005767C: beql        $v0, $zero, L_80057694
    if (ctx->r2 == 0) {
        // 0x80057680: lw          $t7, 0x0($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X0);
            goto L_80057694;
    }
    goto skip_1;
    // 0x80057680: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x80057684: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80057688: b           L_80057698
    // 0x8005768C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
        goto L_80057698;
    // 0x8005768C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80057690: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
L_80057694:
    // 0x80057694: sw          $t7, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r15;
L_80057698:
    // 0x80057698: lw          $t8, 0x68($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X68);
    // 0x8005769C: bnel        $v1, $t8, L_800576AC
    if (ctx->r3 != ctx->r24) {
        // 0x800576A0: lw          $t9, 0x6C($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X6C);
            goto L_800576AC;
    }
    goto skip_2;
    // 0x800576A0: lw          $t9, 0x6C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X6C);
    skip_2:
    // 0x800576A4: sw          $v0, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->r2;
    // 0x800576A8: lw          $t9, 0x6C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X6C);
L_800576AC:
    // 0x800576AC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800576B0: jr          $ra
    // 0x800576B4: sw          $v1, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r3;
    TRACE_RETURN()
    return;
    // 0x800576B4: sw          $v1, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r3;
    // 0x800576B8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800576BC:
    // 0x800576BC: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800576C0: bne         $v1, $zero, L_80057674
    if (ctx->r3 != 0) {
        // 0x800576C4: nop
    
            goto L_80057674;
    }
    // 0x800576C4: nop

L_800576C8:
    // 0x800576C8: jr          $ra
    TRACE_RETURN()
    return;
;}
