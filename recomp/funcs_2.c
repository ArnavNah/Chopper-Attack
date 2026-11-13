#include "recomp.h"
#include "trace.h"
#include "funcs.h"

extern void chopper_fiber_destroy(uint32_t fiber_addr);

RECOMP_FUNC void func_80003F50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80003F50: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80003F54: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80003F58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80003F5C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
L_80003F60:
    // 0x80003F60: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80003F64: lwc1        $f16, 0x0($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80003F68: lwc1        $f14, 0x4($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80003F6C: lwc1        $f12, 0x10($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80003F70: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80003F74: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80003F78: lwc1        $f10, 0x20($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X20);
    // 0x80003F7C: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80003F80: lwc1        $f14, 0x30($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X30);
    // 0x80003F84: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80003F88: mul.s       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80003F8C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80003F90: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80003F94: add.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x80003F98: add.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x80003F9C: add.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x80003FA0: bne         $v0, $a0, L_80003F60
    if (ctx->r2 != ctx->r4) {
        // 0x80003FA4: swc1        $f10, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
            goto L_80003F60;
    }
    // 0x80003FA4: swc1        $f10, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
    // 0x80003FA8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80003FB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80003FB0: addiu       $sp, $sp, -0x128
    ctx->r29 = ADD32(ctx->r29, -0X128);
    // 0x80003FB4: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80003FB8: addiu       $s3, $sp, 0x10C
    ctx->r19 = ADD32(ctx->r29, 0X10C);
    // 0x80003FBC: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80003FC0: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80003FC4: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80003FC8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80003FCC: sw          $a0, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r4;
    // 0x80003FD0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80003FD4: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80003FD8: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x80003FDC: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x80003FE0: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x80003FE4: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80003FE8: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80003FEC: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80003FF0: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80003FF4: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80003FF8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80003FFC: jal         0x80003088
    // 0x80004000: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80003088(rdram, ctx);
        goto after_0;
    // 0x80004000: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x80004004: addiu       $s4, $sp, 0xCC
    ctx->r20 = ADD32(ctx->r29, 0XCC);
    // 0x80004008: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8000400C: jal         0x80003D8C
    // 0x80004010: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_80003D8C(rdram, ctx);
        goto after_1;
    // 0x80004010: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_1:
    // 0x80004014: addiu       $fp, $sp, 0xC0
    ctx->r30 = ADD32(ctx->r29, 0XC0);
    // 0x80004018: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8000401C: lw          $a1, 0x128($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X128);
    // 0x80004020: jal         0x80003F50
    // 0x80004024: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_80003F50(rdram, ctx);
        goto after_2;
    // 0x80004024: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_2:
    // 0x80004028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000402C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80004030: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80004034: jal         0x80003BBC
    // 0x80004038: lw          $a3, 0x128($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X128);
    func_80003BBC(rdram, ctx);
        goto after_3;
    // 0x80004038: lw          $a3, 0x128($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X128);
    after_3:
    // 0x8000403C: beq         $v0, $zero, L_80004058
    if (ctx->r2 == 0) {
        // 0x80004040: lui         $at, 0x8007
        ctx->r1 = S32(0X8007 << 16);
            goto L_80004058;
    }
    // 0x80004040: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80004044: lw          $a0, 0x128($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X128);
    // 0x80004048: jal         0x80003668
    // 0x8000404C: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    func_80003668(rdram, ctx);
        goto after_4;
    // 0x8000404C: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    after_4:
    // 0x80004050: b           L_800041A8
    // 0x80004054: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_800041A8;
    // 0x80004054: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_80004058:
    // 0x80004058: lwc1        $f24, 0x48D0($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X48D0);
    // 0x8000405C: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80004060: sw          $s0, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r16;
    // 0x80004064: sw          $s1, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r17;
    // 0x80004068: sw          $s2, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r18;
    // 0x8000406C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80004070: addiu       $s4, $sp, 0x11C
    ctx->r20 = ADD32(ctx->r29, 0X11C);
    // 0x80004074: addiu       $s7, $sp, 0xCC
    ctx->r23 = ADD32(ctx->r29, 0XCC);
    // 0x80004078: addiu       $s6, $sp, 0x9C
    ctx->r22 = ADD32(ctx->r29, 0X9C);
    // 0x8000407C: addiu       $s5, $sp, 0x90
    ctx->r21 = ADD32(ctx->r29, 0X90);
    // 0x80004080: mov.s       $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    ctx->f20.fl = ctx->f24.fl;
    // 0x80004084: addiu       $a3, $v0, 0x1
    ctx->r7 = ADD32(ctx->r2, 0X1);
L_80004088:
    // 0x80004088: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000408C: bne         $v0, $at, L_80004098
    if (ctx->r2 != ctx->r1) {
        // 0x80004090: or          $v1, $a3, $zero
        ctx->r3 = ctx->r7 | 0;
            goto L_80004098;
    }
    // 0x80004090: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x80004094: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80004098:
    // 0x80004098: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8000409C: addiu       $t7, $sp, 0x11C
    ctx->r15 = ADD32(ctx->r29, 0X11C);
    // 0x800040A0: addu        $s3, $t6, $t7
    ctx->r19 = ADD32(ctx->r14, ctx->r15);
    // 0x800040A4: lw          $a2, 0x0($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X0);
    // 0x800040A8: lw          $a1, 0x0($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X0);
    // 0x800040AC: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x800040B0: jal         0x800034FC
    // 0x800040B4: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    func_800034FC(rdram, ctx);
        goto after_5;
    // 0x800040B4: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    after_5:
    // 0x800040B8: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800040BC: addiu       $a1, $sp, 0xA8
    ctx->r5 = ADD32(ctx->r29, 0XA8);
    // 0x800040C0: jal         0x80003CA8
    // 0x800040C4: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    func_80003CA8(rdram, ctx);
        goto after_6;
    // 0x800040C4: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    after_6:
    // 0x800040C8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800040CC: addiu       $s1, $sp, 0x90
    ctx->r17 = ADD32(ctx->r29, 0X90);
    // 0x800040D0: addiu       $s2, $sp, 0xC0
    ctx->r18 = ADD32(ctx->r29, 0XC0);
L_800040D4:
    // 0x800040D4: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x800040D8: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x800040DC: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x800040E0: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x800040E4: lwc1        $f4, 0x0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800040E8: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x800040EC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800040F0: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800040F4: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x800040F8: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
    // 0x800040FC: lwc1        $f8, 0x0($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80004100: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80004104: jal         0x80003730
    // 0x80004108: swc1        $f10, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f10.u32l;
    func_80003730(rdram, ctx);
        goto after_7;
    // 0x80004108: swc1        $f10, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f10.u32l;
    after_7:
    // 0x8000410C: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80004110: lw          $a0, 0x128($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X128);
    // 0x80004114: bc1fl       L_8000413C
    if (!c1cs) {
        // 0x80004118: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8000413C;
    }
    goto skip_0;
    // 0x80004118: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    skip_0:
    // 0x8000411C: jal         0x80003668
    // 0x80004120: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    func_80003668(rdram, ctx);
        goto after_8;
    // 0x80004120: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    after_8:
    // 0x80004124: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80004128: nop

    // 0x8000412C: bc1fl       L_8000413C
    if (!c1cs) {
        // 0x80004130: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8000413C;
    }
    goto skip_1;
    // 0x80004130: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    skip_1:
    // 0x80004134: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80004138: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_8000413C:
    // 0x8000413C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80004140: bne         $s2, $s7, L_800040D4
    if (ctx->r18 != ctx->r23) {
        // 0x80004144: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800040D4;
    }
    // 0x80004144: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80004148: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
    // 0x8000414C: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80004150: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80004154: bnel        $at, $zero, L_80004088
    if (ctx->r1 != 0) {
        // 0x80004158: addiu       $a3, $v0, 0x1
        ctx->r7 = ADD32(ctx->r2, 0X1);
            goto L_80004088;
    }
    goto skip_2;
    // 0x80004158: addiu       $a3, $v0, 0x1
    ctx->r7 = ADD32(ctx->r2, 0X1);
    skip_2:
    // 0x8000415C: c.eq.s      $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f20.fl == ctx->f24.fl;
    // 0x80004160: addiu       $s4, $sp, 0x11C
    ctx->r20 = ADD32(ctx->r29, 0X11C);
    // 0x80004164: addiu       $s0, $sp, 0x128
    ctx->r16 = ADD32(ctx->r29, 0X128);
    // 0x80004168: bc1t        L_80004178
    if (c1cs) {
        // 0x8000416C: nop
    
            goto L_80004178;
    }
    // 0x8000416C: nop

    // 0x80004170: b           L_800041A4
    // 0x80004174: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
        goto L_800041A4;
    // 0x80004174: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
L_80004178:
    // 0x80004178: lw          $a0, 0x128($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X128);
L_8000417C:
    // 0x8000417C: jal         0x80003668
    // 0x80004180: lw          $a1, 0x0($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X0);
    func_80003668(rdram, ctx);
        goto after_9;
    // 0x80004180: lw          $a1, 0x0($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X0);
    after_9:
    // 0x80004184: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80004188: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x8000418C: bc1f        L_80004198
    if (!c1cs) {
        // 0x80004190: nop
    
            goto L_80004198;
    }
    // 0x80004190: nop

    // 0x80004194: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_80004198:
    // 0x80004198: bnel        $s4, $s0, L_8000417C
    if (ctx->r20 != ctx->r16) {
        // 0x8000419C: lw          $a0, 0x128($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X128);
            goto L_8000417C;
    }
    goto skip_3;
    // 0x8000419C: lw          $a0, 0x128($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X128);
    skip_3:
    // 0x800041A0: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
L_800041A4:
    // 0x800041A4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_800041A8:
    // 0x800041A8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800041AC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800041B0: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x800041B4: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800041B8: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800041BC: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800041C0: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x800041C4: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x800041C8: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x800041CC: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x800041D0: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x800041D4: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x800041D8: jr          $ra
    // 0x800041DC: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
    TRACE_RETURN()
    return;
    // 0x800041DC: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
;}
RECOMP_FUNC void func_800041E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800041E0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800041E4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800041E8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800041EC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800041F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800041F4: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x800041F8: or          $t1, $a1, $zero
    ctx->r9 = ctx->r5 | 0;
    // 0x800041FC: or          $t2, $a2, $zero
    ctx->r10 = ctx->r6 | 0;
L_80004200:
    // 0x80004200: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80004204: lwc1        $f6, 0x0($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80004208: lwc1        $f10, 0x0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8000420C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80004210: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80004214: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80004218: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8000421C: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x80004220: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80004224: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x80004228: div.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8000422C: bne         $v0, $a0, L_80004200
    if (ctx->r2 != ctx->r4) {
        // 0x80004230: swc1        $f18, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
            goto L_80004200;
    }
    // 0x80004230: swc1        $f18, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
    // 0x80004234: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80004240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80004240: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004244: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004248: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8000424C: sw          $a0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r4;
    // 0x80004250: sw          $a0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r4;
    // 0x80004254: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80004258: addiu       $a2, $a3, -0x10
    ctx->r6 = ADD32(ctx->r7, -0X10);
    // 0x8000425C: jal         0x80004274
    // 0x80004260: addiu       $a1, $a0, 0x10
    ctx->r5 = ADD32(ctx->r4, 0X10);
    func_80004274(rdram, ctx);
        goto after_0;
    // 0x80004260: addiu       $a1, $a0, 0x10
    ctx->r5 = ADD32(ctx->r4, 0X10);
    after_0:
    // 0x80004264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80004268: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000426C: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80004274(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80004274: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004278: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000427C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80004280: xor         $t6, $a1, $at
    ctx->r14 = ctx->r5 ^ ctx->r1;
    // 0x80004284: srl         $t7, $a2, 3
    ctx->r15 = S32(U32(ctx->r6) >> 3);
    // 0x80004288: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8000428C: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80004290: jal         0x800042A8
    // 0x80004294: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    func_800042A8(rdram, ctx);
        goto after_0;
    // 0x80004294: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_0:
    // 0x80004298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000429C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800042A0: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800042A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800042A8: addiu       $v0, $a1, -0x8
    ctx->r2 = ADD32(ctx->r5, -0X8);
    // 0x800042AC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800042B0: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
L_800042B4:
    // 0x800042B4: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x800042B8: beql        $at, $zero, L_800042D4
    if (ctx->r1 == 0) {
        // 0x800042BC: lw          $a1, 0x0($v1)
        ctx->r5 = MEM_W(ctx->r3, 0X0);
            goto L_800042D4;
    }
    goto skip_0;
    // 0x800042BC: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x800042C0: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800042C4: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x800042C8: bnel        $at, $zero, L_800042FC
    if (ctx->r1 != 0) {
        // 0x800042CC: lw          $a2, 0x4($v0)
        ctx->r6 = MEM_W(ctx->r2, 0X4);
            goto L_800042FC;
    }
    goto skip_1;
    // 0x800042CC: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    skip_1:
    // 0x800042D0: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
L_800042D4:
    // 0x800042D4: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x800042D8: bne         $at, $zero, L_800042F0
    if (ctx->r1 != 0) {
        // 0x800042DC: sltu        $at, $v1, $v0
        ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
            goto L_800042F0;
    }
    // 0x800042DC: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x800042E0: bne         $at, $zero, L_800042F8
    if (ctx->r1 != 0) {
        // 0x800042E4: sltu        $at, $v0, $a1
        ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
            goto L_800042F8;
    }
    // 0x800042E4: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x800042E8: bnel        $at, $zero, L_800042FC
    if (ctx->r1 != 0) {
        // 0x800042EC: lw          $a2, 0x4($v0)
        ctx->r6 = MEM_W(ctx->r2, 0X4);
            goto L_800042FC;
    }
    goto skip_2;
    // 0x800042EC: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    skip_2:
L_800042F0:
    // 0x800042F0: b           L_800042B4
    // 0x800042F4: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
        goto L_800042B4;
    // 0x800042F4: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_800042F8:
    // 0x800042F8: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
L_800042FC:
    // 0x800042FC: sll         $t6, $a2, 3
    ctx->r14 = S32(ctx->r6 << 3);
    // 0x80004300: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80004304: bnel        $a1, $t7, L_8000432C
    if (ctx->r5 != ctx->r15) {
        // 0x80004308: sw          $a1, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r5;
            goto L_8000432C;
    }
    goto skip_3;
    // 0x80004308: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    skip_3:
    // 0x8000430C: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x80004310: addu        $t9, $a2, $t8
    ctx->r25 = ADD32(ctx->r6, ctx->r24);
    // 0x80004314: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80004318: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8000431C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80004320: b           L_8000432C
    // 0x80004324: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
        goto L_8000432C;
    // 0x80004324: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80004328: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
L_8000432C:
    // 0x8000432C: lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4);
    // 0x80004330: sll         $t2, $a1, 3
    ctx->r10 = S32(ctx->r5 << 3);
    // 0x80004334: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x80004338: bnel        $v0, $t3, L_8000435C
    if (ctx->r2 != ctx->r11) {
        // 0x8000433C: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000435C;
    }
    goto skip_4;
    // 0x8000433C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    skip_4:
    // 0x80004340: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x80004344: addu        $t5, $a1, $t4
    ctx->r13 = ADD32(ctx->r5, ctx->r12);
    // 0x80004348: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8000434C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80004350: b           L_8000435C
    // 0x80004354: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
        goto L_8000435C;
    // 0x80004354: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80004358: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_8000435C:
    // 0x8000435C: jr          $ra
    // 0x80004360: sw          $v1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r3;
    TRACE_RETURN()
    return;
    // 0x80004360: sw          $v1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r3;
;}
RECOMP_FUNC void func_80004364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80004364: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004368: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000436C: lw          $a2, 0x8($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X8);
    // 0x80004370: addiu       $a3, $a1, 0x7
    ctx->r7 = ADD32(ctx->r5, 0X7);
    // 0x80004374: srl         $t6, $a3, 3
    ctx->r14 = S32(U32(ctx->r7) >> 3);
    // 0x80004378: addiu       $a3, $t6, 0x1
    ctx->r7 = ADD32(ctx->r14, 0X1);
    // 0x8000437C: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x80004380: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
L_80004384:
    // 0x80004384: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80004388: slt         $at, $v0, $a3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8000438C: bne         $at, $zero, L_800043D0
    if (ctx->r1 != 0) {
        // 0x80004390: nop
    
            goto L_800043D0;
    }
    // 0x80004390: nop

    // 0x80004394: bne         $a3, $v0, L_800043A8
    if (ctx->r7 != ctx->r2) {
        // 0x80004398: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_800043A8;
    }
    // 0x80004398: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000439C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800043A0: b           L_800043BC
    // 0x800043A4: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
        goto L_800043BC;
    // 0x800043A4: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
L_800043A8:
    // 0x800043A8: subu        $t8, $v0, $a3
    ctx->r24 = SUB32(ctx->r2, ctx->r7);
    // 0x800043AC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800043B0: sll         $t1, $t8, 3
    ctx->r9 = S32(ctx->r24 << 3);
    // 0x800043B4: addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
    // 0x800043B8: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
L_800043BC:
    // 0x800043BC: sw          $t0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r8;
    // 0x800043C0: xor         $t2, $v1, $at
    ctx->r10 = ctx->r3 ^ ctx->r1;
    // 0x800043C4: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800043C8: b           L_800043F0
    // 0x800043CC: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
        goto L_800043F0;
    // 0x800043CC: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
L_800043D0:
    // 0x800043D0: bne         $v1, $a2, L_800043E8
    if (ctx->r3 != ctx->r6) {
        // 0x800043D4: or          $t0, $v1, $zero
        ctx->r8 = ctx->r3 | 0;
            goto L_800043E8;
    }
    // 0x800043D4: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x800043D8: jal         0x80004400
    // 0x800043DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80004400(rdram, ctx);
        goto after_0;
    // 0x800043DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x800043E0: b           L_800043F0
    // 0x800043E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800043F0;
    // 0x800043E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800043E8:
    // 0x800043E8: b           L_80004384
    // 0x800043EC: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
        goto L_80004384;
    // 0x800043EC: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
L_800043F0:
    // 0x800043F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800043F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800043F8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80004400(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80004400: lw          $a2, 0x8($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X8);
    // 0x80004404: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80004408: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
L_8000440C:
    // 0x8000440C: lw          $t6, 0x4($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X4);
    // 0x80004410: beq         $a3, $a2, L_80004420
    if (ctx->r7 == ctx->r6) {
        // 0x80004414: addu        $v0, $v0, $t6
        ctx->r2 = ADD32(ctx->r2, ctx->r14);
            goto L_80004420;
    }
    // 0x80004414: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80004418: b           L_8000440C
    // 0x8000441C: lw          $a3, 0x0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X0);
        goto L_8000440C;
    // 0x8000441C: lw          $a3, 0x0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X0);
L_80004420:
    // 0x80004420: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80004430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80004430: addiu       $t6, $a1, -0xC
    ctx->r14 = ADD32(ctx->r5, -0XC);
    // 0x80004434: addiu       $t7, $a2, 0x4
    ctx->r15 = ADD32(ctx->r6, 0X4);
    // 0x80004438: divu        $zero, $t6, $t7
    lo = S32(U32(ctx->r14) / U32(ctx->r15)); hi = S32(U32(ctx->r14) % U32(ctx->r15));
    // 0x8000443C: mflo        $v0
    ctx->r2 = lo;
    // 0x80004440: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80004444: sh          $v0, -0x4A4E($at)
    MEM_H(-0X4A4E, ctx->r1) = ctx->r2;
    // 0x80004448: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000444C: sh          $zero, -0x4A50($at)
    MEM_H(-0X4A50, ctx->r1) = 0;
    // 0x80004450: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80004454: addiu       $t8, $v0, 0x2
    ctx->r24 = ADD32(ctx->r2, 0X2);
    // 0x80004458: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8000445C: addiu       $v1, $a0, 0x8
    ctx->r3 = ADD32(ctx->r4, 0X8);
    // 0x80004460: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x80004464: bne         $t7, $zero, L_80004470
    if (ctx->r15 != 0) {
        // 0x80004468: nop
    
            goto L_80004470;
    }
    // 0x80004468: nop

    // 0x8000446C: break       7
    do_break(2147501164);
L_80004470:
    // 0x80004470: addu        $a3, $t2, $a0
    ctx->r7 = ADD32(ctx->r10, ctx->r4);
    // 0x80004474: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x80004478: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x8000447C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80004480: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x80004484: beq         $v0, $zero, L_800044A4
    if (ctx->r2 == 0) {
        // 0x80004488: addiu       $t1, $v0, -0x1
        ctx->r9 = ADD32(ctx->r2, -0X1);
            goto L_800044A4;
    }
    // 0x80004488: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
L_8000448C:
    // 0x8000448C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80004490: sw          $a3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r7;
    // 0x80004494: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80004498: addu        $a3, $a3, $a2
    ctx->r7 = ADD32(ctx->r7, ctx->r6);
    // 0x8000449C: bne         $t1, $zero, L_8000448C
    if (ctx->r9 != 0) {
        // 0x800044A0: addiu       $t1, $t1, -0x1
        ctx->r9 = ADD32(ctx->r9, -0X1);
            goto L_8000448C;
    }
    // 0x800044A0: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
L_800044A4:
    // 0x800044A4: jr          $ra
    // 0x800044A8: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    TRACE_RETURN()
    return;
    // 0x800044A8: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
;}
RECOMP_FUNC void func_800044AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800044AC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800044B0: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800044B4: addiu       $t6, $v0, 0x4
    ctx->r14 = ADD32(ctx->r2, 0X4);
    // 0x800044B8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800044BC: beql        $v1, $zero, L_800044E4
    if (ctx->r3 == 0) {
        // 0x800044C0: lw          $t9, 0x0($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X0);
            goto L_800044E4;
    }
    goto skip_0;
    // 0x800044C0: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x800044C4: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800044C8: addiu       $a0, $a0, -0x4A50
    ctx->r4 = ADD32(ctx->r4, -0X4A50);
    // 0x800044CC: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x800044D0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800044D4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800044D8: jr          $ra
    // 0x800044DC: sh          $t8, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r24;
    TRACE_RETURN()
    return;
    // 0x800044DC: sh          $t8, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r24;
    // 0x800044E0: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
L_800044E4:
    // 0x800044E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800044E8: addiu       $t0, $t9, -0x4
    ctx->r8 = ADD32(ctx->r25, -0X4);
    // 0x800044EC: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x800044F0: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_800044F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800044F8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800044FC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80004500: addiu       $v0, $v0, -0x4A50
    ctx->r2 = ADD32(ctx->r2, -0X4A50);
    // 0x80004504: addiu       $t7, $t6, -0x4
    ctx->r15 = ADD32(ctx->r14, -0X4);
    // 0x80004508: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8000450C: sw          $a1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r5;
    // 0x80004510: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x80004514: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80004518: jr          $ra
    // 0x8000451C: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
    TRACE_RETURN()
    return;
    // 0x8000451C: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
;}
RECOMP_FUNC void func_80004520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80004520: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80004524: lh          $t6, -0x4A4E($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X4A4E);
    // 0x80004528: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x8000452C: sh          $t6, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r14;
    // 0x80004530: lh          $t7, -0x4A50($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X4A50);
    // 0x80004534: jr          $ra
    // 0x80004538: sh          $t7, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r15;
    TRACE_RETURN()
    return;
    // 0x80004538: sh          $t7, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r15;
;}
RECOMP_FUNC void func_80004540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80004540: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80004544: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80004548: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x8000454C: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x80004550: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x80004554: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80004558: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8000455C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80004560: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80004564: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80004568: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8000456C: lwc1        $f8, 0x4($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80004570: sub.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80004574: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80004578: lwc1        $f4, 0x8($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8000457C: sub.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80004580: mul.s       $f8, $f20, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80004584: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80004588: sub.s       $f24, $f4, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8000458C: mul.s       $f10, $f22, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x80004590: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80004594: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80004598: mul.s       $f6, $f24, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x8000459C: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800045A0: jal         0x8004F640
    // 0x800045A4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    func_8004F640(rdram, ctx);
        goto after_0;
    // 0x800045A4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x800045A8: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x800045AC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800045B0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800045B4: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x800045B8: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800045BC: div.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x800045C0: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800045C4: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
    // 0x800045C8: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x800045CC: nop

    // 0x800045D0: mul.s       $f22, $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x800045D4: nop

    // 0x800045D8: mul.s       $f24, $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f2.fl);
    // 0x800045DC: nop

    // 0x800045E0: mul.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x800045E4: nop

    // 0x800045E8: mul.s       $f4, $f10, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x800045EC: sub.s       $f26, $f8, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800045F0: mul.s       $f8, $f10, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800045F4: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800045F8: mul.s       $f10, $f4, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x800045FC: sub.s       $f28, $f8, $f10
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f28.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80004600: mul.s       $f8, $f4, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x80004604: nop

    // 0x80004608: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8000460C: sub.s       $f30, $f8, $f10
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f30.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80004610: mul.s       $f4, $f26, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x80004614: nop

    // 0x80004618: mul.s       $f6, $f28, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f28.fl, ctx->f28.fl);
    // 0x8000461C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80004620: mul.s       $f10, $f30, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f30.fl, ctx->f30.fl);
    // 0x80004624: jal         0x8004F640
    // 0x80004628: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    func_8004F640(rdram, ctx);
        goto after_1;
    // 0x80004628: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_1:
    // 0x8000462C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80004630: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80004634: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80004638: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8000463C: div.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x80004640: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x80004644: mul.s       $f26, $f26, $f14
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f26.fl = MUL_S(ctx->f26.fl, ctx->f14.fl);
    // 0x80004648: nop

    // 0x8000464C: mul.s       $f28, $f28, $f14
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f28.fl = MUL_S(ctx->f28.fl, ctx->f14.fl);
    // 0x80004650: nop

    // 0x80004654: mul.s       $f30, $f30, $f14
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f30.fl = MUL_S(ctx->f30.fl, ctx->f14.fl);
    // 0x80004658: nop

    // 0x8000465C: mul.s       $f10, $f22, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f30.fl);
    // 0x80004660: nop

    // 0x80004664: mul.s       $f4, $f24, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f28.fl);
    // 0x80004668: nop

    // 0x8000466C: mul.s       $f6, $f24, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f26.fl);
    // 0x80004670: nop

    // 0x80004674: mul.s       $f8, $f20, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f30.fl);
    // 0x80004678: sub.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8000467C: mul.s       $f10, $f20, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f28.fl);
    // 0x80004680: nop

    // 0x80004684: mul.s       $f4, $f22, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f26.fl);
    // 0x80004688: swc1        $f2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f2.u32l;
    // 0x8000468C: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80004690: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80004694: nop

    // 0x80004698: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8000469C: swc1        $f16, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f16.u32l;
    // 0x800046A0: sub.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800046A4: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800046A8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800046AC: swc1        $f18, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f18.u32l;
    // 0x800046B0: jal         0x8004F640
    // 0x800046B4: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    func_8004F640(rdram, ctx);
        goto after_2;
    // 0x800046B4: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    after_2:
    // 0x800046B8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800046BC: ldc1        $f2, 0x48E0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, 0X48E0);
    // 0x800046C0: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x800046C4: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800046C8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800046CC: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800046D0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800046D4: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x800046D8: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800046DC: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x800046E0: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800046E4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800046E8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800046EC: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x800046F0: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x800046F4: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x800046F8: cvt.s.d     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
    // 0x800046FC: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80004700: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80004704: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80004708: cvt.d.s     $f8, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f8.d = CVT_D_S(ctx->f26.fl);
    // 0x8000470C: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x80004710: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80004714: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
    // 0x80004718: mul.d       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f12.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x8000471C: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
    // 0x80004720: c.lt.d      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.d < ctx->f2.d;
    // 0x80004724: nop

    // 0x80004728: bc1fl       L_8000473C
    if (!c1cs) {
        // 0x8000472C: mov.d       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
            goto L_8000473C;
    }
    goto skip_0;
    // 0x8000472C: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
    skip_0:
    // 0x80004730: b           L_8000473C
    // 0x80004734: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
        goto L_8000473C;
    // 0x80004734: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    // 0x80004738: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
L_8000473C:
    // 0x8000473C: cvt.d.s     $f4, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); 
    ctx->f4.d = CVT_D_S(ctx->f28.fl);
    // 0x80004740: trunc.w.d   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x80004744: mul.d       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f12.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x80004748: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x8000474C: nop

    // 0x80004750: sb          $t8, 0x8($a1)
    MEM_B(0X8, ctx->r5) = ctx->r24;
    // 0x80004754: c.lt.d      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.d < ctx->f2.d;
    // 0x80004758: nop

    // 0x8000475C: bc1fl       L_80004770
    if (!c1cs) {
        // 0x80004760: mov.d       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
            goto L_80004770;
    }
    goto skip_1;
    // 0x80004760: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
    skip_1:
    // 0x80004764: b           L_80004770
    // 0x80004768: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
        goto L_80004770;
    // 0x80004768: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    // 0x8000476C: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
L_80004770:
    // 0x80004770: cvt.d.s     $f8, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); 
    ctx->f8.d = CVT_D_S(ctx->f30.fl);
    // 0x80004774: trunc.w.d   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x80004778: mul.d       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f12.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x8000477C: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x80004780: nop

    // 0x80004784: sb          $t1, 0x9($a1)
    MEM_B(0X9, ctx->r5) = ctx->r9;
    // 0x80004788: c.lt.d      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.d < ctx->f2.d;
    // 0x8000478C: nop

    // 0x80004790: bc1fl       L_800047A4
    if (!c1cs) {
        // 0x80004794: mov.d       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
            goto L_800047A4;
    }
    goto skip_2;
    // 0x80004794: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
    skip_2:
    // 0x80004798: b           L_800047A4
    // 0x8000479C: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
        goto L_800047A4;
    // 0x8000479C: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    // 0x800047A0: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
L_800047A4:
    // 0x800047A4: trunc.w.d   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x800047A8: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800047AC: nop

    // 0x800047B0: sb          $t4, 0xA($a1)
    MEM_B(0XA, ctx->r5) = ctx->r12;
    // 0x800047B4: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800047B8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800047BC: mul.d       $f12, $f6, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f12.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x800047C0: c.lt.d      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.d < ctx->f2.d;
    // 0x800047C4: nop

    // 0x800047C8: bc1fl       L_800047DC
    if (!c1cs) {
        // 0x800047CC: mov.d       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
            goto L_800047DC;
    }
    goto skip_3;
    // 0x800047CC: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
    skip_3:
    // 0x800047D0: b           L_800047DC
    // 0x800047D4: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
        goto L_800047DC;
    // 0x800047D4: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    // 0x800047D8: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
L_800047DC:
    // 0x800047DC: trunc.w.d   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x800047E0: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x800047E4: nop

    // 0x800047E8: sb          $t7, 0x18($a1)
    MEM_B(0X18, ctx->r5) = ctx->r15;
    // 0x800047EC: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800047F0: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x800047F4: mul.d       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f12.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x800047F8: c.lt.d      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.d < ctx->f2.d;
    // 0x800047FC: nop

    // 0x80004800: bc1fl       L_80004814
    if (!c1cs) {
        // 0x80004804: mov.d       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
            goto L_80004814;
    }
    goto skip_4;
    // 0x80004804: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
    skip_4:
    // 0x80004808: b           L_80004814
    // 0x8000480C: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
        goto L_80004814;
    // 0x8000480C: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    // 0x80004810: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
L_80004814:
    // 0x80004814: trunc.w.d   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x80004818: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x8000481C: nop

    // 0x80004820: sb          $t0, 0x19($a1)
    MEM_B(0X19, ctx->r5) = ctx->r8;
    // 0x80004824: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80004828: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8000482C: mul.d       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f12.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x80004830: c.lt.d      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.d < ctx->f2.d;
    // 0x80004834: nop

    // 0x80004838: bc1fl       L_8000484C
    if (!c1cs) {
        // 0x8000483C: mov.d       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
            goto L_8000484C;
    }
    goto skip_5;
    // 0x8000483C: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
    skip_5:
    // 0x80004840: b           L_8000484C
    // 0x80004844: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
        goto L_8000484C;
    // 0x80004844: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    // 0x80004848: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
L_8000484C:
    // 0x8000484C: trunc.w.d   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x80004850: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x80004854: sb          $zero, 0x1($a1)
    MEM_B(0X1, ctx->r5) = 0;
    // 0x80004858: sb          $zero, 0x2($a1)
    MEM_B(0X2, ctx->r5) = 0;
    // 0x8000485C: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x80004860: sb          $zero, 0x3($a1)
    MEM_B(0X3, ctx->r5) = 0;
    // 0x80004864: sb          $zero, 0x4($a1)
    MEM_B(0X4, ctx->r5) = 0;
    // 0x80004868: sb          $zero, 0x5($a1)
    MEM_B(0X5, ctx->r5) = 0;
    // 0x8000486C: sb          $zero, 0x6($a1)
    MEM_B(0X6, ctx->r5) = 0;
    // 0x80004870: sb          $zero, 0x7($a1)
    MEM_B(0X7, ctx->r5) = 0;
    // 0x80004874: sb          $zero, 0x10($a1)
    MEM_B(0X10, ctx->r5) = 0;
    // 0x80004878: sb          $v0, 0x11($a1)
    MEM_B(0X11, ctx->r5) = ctx->r2;
    // 0x8000487C: sb          $zero, 0x12($a1)
    MEM_B(0X12, ctx->r5) = 0;
    // 0x80004880: sb          $zero, 0x13($a1)
    MEM_B(0X13, ctx->r5) = 0;
    // 0x80004884: sb          $zero, 0x14($a1)
    MEM_B(0X14, ctx->r5) = 0;
    // 0x80004888: sb          $v0, 0x15($a1)
    MEM_B(0X15, ctx->r5) = ctx->r2;
    // 0x8000488C: sb          $zero, 0x16($a1)
    MEM_B(0X16, ctx->r5) = 0;
    // 0x80004890: sb          $zero, 0x17($a1)
    MEM_B(0X17, ctx->r5) = 0;
    // 0x80004894: sb          $t3, 0x1A($a1)
    MEM_B(0X1A, ctx->r5) = ctx->r11;
    // 0x80004898: swc1        $f26, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f26.u32l;
    // 0x8000489C: lwc1        $f12, 0x5C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800048A0: lwc1        $f2, 0x60($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800048A4: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800048A8: swc1        $f28, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f28.u32l;
    // 0x800048AC: swc1        $f30, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f30.u32l;
    // 0x800048B0: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800048B4: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800048B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800048BC: mul.s       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x800048C0: nop

    // 0x800048C4: mul.s       $f4, $f10, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f28.fl);
    // 0x800048C8: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800048CC: swc1        $f12, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f12.u32l;
    // 0x800048D0: swc1        $f2, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f2.u32l;
    // 0x800048D4: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x800048D8: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800048DC: mul.s       $f8, $f10, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f30.fl);
    // 0x800048E0: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800048E4: neg.s       $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = -ctx->f4.fl;
    // 0x800048E8: swc1        $f10, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f10.u32l;
    // 0x800048EC: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800048F0: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800048F4: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800048F8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800048FC: mul.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80004900: lwc1        $f4, 0x8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80004904: swc1        $f20, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f20.u32l;
    // 0x80004908: swc1        $f22, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f22.u32l;
    // 0x8000490C: swc1        $f24, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f24.u32l;
    // 0x80004910: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80004914: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80004918: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8000491C: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x80004920: swc1        $f4, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f4.u32l;
    // 0x80004924: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80004928: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8000492C: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80004930: nop

    // 0x80004934: mul.s       $f4, $f10, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x80004938: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8000493C: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x80004940: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x80004944: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    // 0x80004948: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8000494C: mul.s       $f8, $f10, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x80004950: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80004954: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80004958: neg.s       $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = -ctx->f4.fl;
    // 0x8000495C: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
    // 0x80004960: swc1        $f10, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f10.u32l;
    // 0x80004964: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80004968: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x8000496C: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x80004970: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x80004974: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80004978: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8000497C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80004980: jr          $ra
    // 0x80004984: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    TRACE_RETURN()
    return;
    // 0x80004984: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80004988(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80004988: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x8000498C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80004990: ldc1        $f6, 0x48E8($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X48E8);
    // 0x80004994: cvt.d.s     $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.d = CVT_D_S(ctx->f14.fl);
    // 0x80004998: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8000499C: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800049A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800049A4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800049A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800049AC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800049B0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800049B4: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800049B8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800049BC: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x800049C0: div.s       $f12, $f14, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f14.fl, ctx->f10.fl);
    // 0x800049C4: jal         0x8004F650
    // 0x800049C8: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    func_8004F650(rdram, ctx);
        goto after_0;
    // 0x800049C8: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x800049CC: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800049D0: jal         0x8004F7C0
    // 0x800049D4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_8004F7C0(rdram, ctx);
        goto after_1;
    // 0x800049D4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800049D8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800049DC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800049E0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x800049E4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800049E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800049EC: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800049F0:
    // 0x800049F0: xor         $t7, $v1, $a0
    ctx->r15 = ctx->r3 ^ ctx->r4;
    // 0x800049F4: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800049F8: sltiu       $t6, $v1, 0x1
    ctx->r14 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x800049FC: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80004A00: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80004A04: xor         $t8, $v1, $a1
    ctx->r24 = ctx->r3 ^ ctx->r5;
    // 0x80004A08: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80004A0C: xor         $t9, $v1, $a2
    ctx->r25 = ctx->r3 ^ ctx->r6;
    // 0x80004A10: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80004A14: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80004A18: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80004A1C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80004A20: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80004A24: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x80004A28: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80004A2C: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x80004A30: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80004A34: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x80004A38: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80004A3C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80004A40: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x80004A44: bne         $at, $zero, L_800049F0
    if (ctx->r1 != 0) {
        // 0x80004A48: swc1        $f6, -0x8($v0)
        MEM_W(-0X8, ctx->r2) = ctx->f6.u32l;
            goto L_800049F0;
    }
    // 0x80004A48: swc1        $f6, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f6.u32l;
    // 0x80004A4C: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80004A50: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80004A54: lwc1        $f14, 0x40($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80004A58: div.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80004A5C: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80004A60: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80004A64: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80004A68: add.s       $f16, $f18, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f14.fl;
    // 0x80004A6C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80004A70: swc1        $f4, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->f4.u32l;
    // 0x80004A74: sub.s       $f12, $f18, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f14.fl;
    // 0x80004A78: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80004A7C: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x80004A80: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80004A84: div.s       $f10, $f16, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = DIV_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80004A88: swc1        $f2, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f2.u32l;
    // 0x80004A8C: div.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80004A90: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80004A94: swc1        $f10, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->f10.u32l;
    // 0x80004A98: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
    // 0x80004A9C: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80004AA0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80004AA4: nop

    // 0x80004AA8: swc1        $f6, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f6.u32l;
    // 0x80004AAC: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80004AB0: div.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80004AB4: swc1        $f4, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->f4.u32l;
    // 0x80004AB8: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80004ABC: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80004AC0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80004AC4: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80004AC8: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80004ACC: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80004AD0: beq         $v1, $a0, L_80004B14
    if (ctx->r3 == ctx->r4) {
        // 0x80004AD4: lwc1        $f14, 0xC($v0)
        ctx->f14.u32l = MEM_W(ctx->r2, 0XC);
            goto L_80004B14;
    }
    // 0x80004AD4: lwc1        $f14, 0xC($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XC);
L_80004AD8:
    // 0x80004AD8: mul.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80004ADC: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80004AE0: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80004AE4: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80004AE8: lwc1        $f12, 0x18($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80004AEC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80004AF0: mul.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80004AF4: lwc1        $f14, 0x1C($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80004AF8: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x80004AFC: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80004B00: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80004B04: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80004B08: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80004B0C: bne         $v1, $a0, L_80004AD8
    if (ctx->r3 != ctx->r4) {
        // 0x80004B10: swc1        $f2, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
            goto L_80004AD8;
    }
    // 0x80004B10: swc1        $f2, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
L_80004B14:
    // 0x80004B14: mul.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80004B18: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80004B1C: swc1        $f10, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f10.u32l;
    // 0x80004B20: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80004B24: nop

    // 0x80004B28: mul.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80004B2C: swc1        $f8, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f8.u32l;
    // 0x80004B30: swc1        $f4, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80004B34: swc1        $f2, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
    // 0x80004B38: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80004B3C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80004B40: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80004B44: cvt.d.s     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.d = CVT_D_S(ctx->f16.fl);
    // 0x80004B48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80004B4C: c.le.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d <= ctx->f8.d;
    // 0x80004B50: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80004B54: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80004B58: bc1fl       L_80004B6C
    if (!c1cs) {
        // 0x80004B5C: mtc1        $at, $f11
        ctx->f_odd[(11 - 1) * 2] = ctx->r1;
            goto L_80004B6C;
    }
    goto skip_0;
    // 0x80004B5C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    skip_0:
    // 0x80004B60: b           L_80004C0C
    // 0x80004B64: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
        goto L_80004C0C;
    // 0x80004B64: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // 0x80004B68: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
L_80004B6C:
    // 0x80004B6C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80004B70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80004B74: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80004B78: div.d       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f0.d);
    // 0x80004B7C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80004B80: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80004B84: nop

    // 0x80004B88: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x80004B8C: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80004B90: nop

    // 0x80004B94: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80004B98: beql        $v0, $zero, L_80004BEC
    if (ctx->r2 == 0) {
        // 0x80004B9C: mfc1        $v0, $f6
        ctx->r2 = (int32_t)ctx->f6.u32l;
            goto L_80004BEC;
    }
    goto skip_1;
    // 0x80004B9C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    skip_1:
    // 0x80004BA0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80004BA4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80004BA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80004BAC: sub.d       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f6.d = ctx->f4.d - ctx->f6.d;
    // 0x80004BB0: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80004BB4: nop

    // 0x80004BB8: cvt.w.d     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_D(ctx->f6.d);
    // 0x80004BBC: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80004BC0: nop

    // 0x80004BC4: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80004BC8: bne         $v0, $zero, L_80004BE0
    if (ctx->r2 != 0) {
        // 0x80004BCC: nop
    
            goto L_80004BE0;
    }
    // 0x80004BCC: nop

    // 0x80004BD0: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80004BD4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80004BD8: b           L_80004BF8
    // 0x80004BDC: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_80004BF8;
    // 0x80004BDC: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_80004BE0:
    // 0x80004BE0: b           L_80004BF8
    // 0x80004BE4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80004BF8;
    // 0x80004BE4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80004BE8: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
L_80004BEC:
    // 0x80004BEC: nop

    // 0x80004BF0: bltz        $v0, L_80004BE0
    if (SIGNED(ctx->r2) < 0) {
        // 0x80004BF4: nop
    
            goto L_80004BE0;
    }
    // 0x80004BF4: nop

L_80004BF8:
    // 0x80004BF8: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80004BFC: andi        $t1, $v0, 0xFFFF
    ctx->r9 = ctx->r2 & 0XFFFF;
    // 0x80004C00: bgtz        $t1, L_80004C0C
    if (SIGNED(ctx->r9) > 0) {
        // 0x80004C04: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80004C0C;
    }
    // 0x80004C04: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80004C08: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80004C0C:
    // 0x80004C0C: jr          $ra
    // 0x80004C10: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    TRACE_RETURN()
    return;
    // 0x80004C10: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80004C20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80004C20: addiu       $t6, $a1, -0x30
    ctx->r14 = ADD32(ctx->r5, -0X30);
    // 0x80004C24: addiu       $t7, $a2, 0x4
    ctx->r15 = ADD32(ctx->r6, 0X4);
    // 0x80004C28: divu        $zero, $t6, $t7
    lo = S32(U32(ctx->r14) / U32(ctx->r15)); hi = S32(U32(ctx->r14) % U32(ctx->r15));
    // 0x80004C2C: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x80004C30: addiu       $t2, $t2, -0x4A40
    ctx->r10 = ADD32(ctx->r10, -0X4A40);
    // 0x80004C34: addiu       $v0, $a0, 0x2C
    ctx->r2 = ADD32(ctx->r4, 0X2C);
    // 0x80004C38: sw          $a0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r4;
    // 0x80004C3C: mflo        $t0
    ctx->r8 = lo;
    // 0x80004C40: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    // 0x80004C44: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80004C48: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x80004C4C: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x80004C50: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x80004C54: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80004C58: and         $t9, $v0, $at
    ctx->r25 = ctx->r2 & ctx->r1;
    // 0x80004C5C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80004C60: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x80004C64: bne         $t7, $zero, L_80004C70
    if (ctx->r15 != 0) {
        // 0x80004C68: nop
    
            goto L_80004C70;
    }
    // 0x80004C68: nop

    // 0x80004C6C: break       7
    do_break(2147503212);
L_80004C70:
    // 0x80004C70: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80004C74: beq         $t0, $zero, L_80004C94
    if (ctx->r8 == 0) {
        // 0x80004C78: addiu       $t1, $t0, -0x1
        ctx->r9 = ADD32(ctx->r8, -0X1);
            goto L_80004C94;
    }
    // 0x80004C78: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
L_80004C7C:
    // 0x80004C7C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x80004C80: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x80004C84: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80004C88: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80004C8C: bne         $t1, $zero, L_80004C7C
    if (ctx->r9 != 0) {
        // 0x80004C90: addiu       $t1, $t1, -0x1
        ctx->r9 = ADD32(ctx->r9, -0X1);
            goto L_80004C7C;
    }
    // 0x80004C90: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
L_80004C94:
    // 0x80004C94: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80004C98: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80004C9C: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x80004CA0: addiu       $a0, $a0, -0x4A34
    ctx->r4 = ADD32(ctx->r4, -0X4A34);
    // 0x80004CA4: addiu       $v0, $v0, -0x4A38
    ctx->r2 = ADD32(ctx->r2, -0X4A38);
    // 0x80004CA8: addiu       $t3, $v1, 0xC
    ctx->r11 = ADD32(ctx->r3, 0XC);
    // 0x80004CAC: addiu       $t4, $v1, 0x1C
    ctx->r12 = ADD32(ctx->r3, 0X1C);
    // 0x80004CB0: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80004CB4: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x80004CB8: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x80004CBC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80004CC0: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x80004CC4: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80004CC8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80004CCC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80004CD0: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x80004CD4: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80004CD8: jr          $ra
    // 0x80004CDC: sw          $t9, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r25;
    TRACE_RETURN()
    return;
    // 0x80004CDC: sw          $t9, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r25;
;}
RECOMP_FUNC void func_80004CE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80004CE0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80004CE4: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80004CE8: lw          $t0, -0x4A40($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4A40);
    // 0x80004CEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004CF0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80004CF4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80004CF8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80004CFC: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80004D00: lw          $v0, 0x8($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X8);
    // 0x80004D04: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80004D08: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80004D0C: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x80004D10: addiu       $t6, $v0, 0x4
    ctx->r14 = ADD32(ctx->r2, 0X4);
    // 0x80004D14: sw          $t6, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r14;
    // 0x80004D18: beql        $t1, $zero, L_80004E40
    if (ctx->r9 == 0) {
        // 0x80004D1C: lw          $t5, 0x8($t0)
        ctx->r13 = MEM_W(ctx->r8, 0X8);
            goto L_80004E40;
    }
    goto skip_0;
    // 0x80004D1C: lw          $t5, 0x8($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X8);
    skip_0:
    // 0x80004D20: sw          $a1, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r5;
    // 0x80004D24: lw          $t7, -0x4A38($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4A38);
    // 0x80004D28: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x80004D2C: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80004D30: beql        $t8, $zero, L_80004D60
    if (ctx->r24 == 0) {
        // 0x80004D34: lw          $t3, 0x4($a1)
        ctx->r11 = MEM_W(ctx->r5, 0X4);
            goto L_80004D60;
    }
    goto skip_1;
    // 0x80004D34: lw          $t3, 0x4($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X4);
    skip_1:
    // 0x80004D38: lw          $t9, 0xC($a1)
    ctx->r25 = MEM_W(ctx->r5, 0XC);
L_80004D3C:
    // 0x80004D3C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80004D40: slt         $at, $a2, $t9
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80004D44: bnel        $at, $zero, L_80004D60
    if (ctx->r1 != 0) {
        // 0x80004D48: lw          $t3, 0x4($a1)
        ctx->r11 = MEM_W(ctx->r5, 0X4);
            goto L_80004D60;
    }
    goto skip_2;
    // 0x80004D48: lw          $t3, 0x4($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X4);
    skip_2:
    // 0x80004D4C: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80004D50: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80004D54: bnel        $t2, $zero, L_80004D3C
    if (ctx->r10 != 0) {
        // 0x80004D58: lw          $t9, 0xC($a1)
        ctx->r25 = MEM_W(ctx->r5, 0XC);
            goto L_80004D3C;
    }
    goto skip_3;
    // 0x80004D58: lw          $t9, 0xC($a1)
    ctx->r25 = MEM_W(ctx->r5, 0XC);
    skip_3:
    // 0x80004D5C: lw          $t3, 0x4($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X4);
L_80004D60:
    // 0x80004D60: addiu       $v0, $sp, 0x44
    ctx->r2 = ADD32(ctx->r29, 0X44);
    // 0x80004D64: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x80004D68: lw          $t4, 0x4($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X4);
    // 0x80004D6C: sw          $a1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r5;
    // 0x80004D70: sw          $t4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r12;
    // 0x80004D74: sw          $t1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r9;
    // 0x80004D78: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80004D7C: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x80004D80: addu        $t6, $t1, $t5
    ctx->r14 = ADD32(ctx->r9, ctx->r13);
    // 0x80004D84: subu        $a3, $t6, $t7
    ctx->r7 = SUB32(ctx->r14, ctx->r15);
    // 0x80004D88: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x80004D8C: bgez        $t7, L_80004D9C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80004D90: sra         $a2, $t7, 2
        ctx->r6 = S32(SIGNED(ctx->r15) >> 2);
            goto L_80004D9C;
    }
    // 0x80004D90: sra         $a2, $t7, 2
    ctx->r6 = S32(SIGNED(ctx->r15) >> 2);
    // 0x80004D94: addiu       $at, $t7, 0x3
    ctx->r1 = ADD32(ctx->r15, 0X3);
    // 0x80004D98: sra         $a2, $at, 2
    ctx->r6 = S32(SIGNED(ctx->r1) >> 2);
L_80004D9C:
    // 0x80004D9C: beq         $a2, $zero, L_80004DC4
    if (ctx->r6 == 0) {
        // 0x80004DA0: addiu       $a0, $a2, -0x1
        ctx->r4 = ADD32(ctx->r6, -0X1);
            goto L_80004DC4;
    }
    // 0x80004DA0: addiu       $a0, $a2, -0x1
    ctx->r4 = ADD32(ctx->r6, -0X1);
L_80004DA4:
    // 0x80004DA4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80004DA8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80004DAC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80004DB0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80004DB4: sw          $t8, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r24;
    // 0x80004DB8: bne         $a0, $zero, L_80004DA4
    if (ctx->r4 != 0) {
        // 0x80004DBC: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_80004DA4;
    }
    // 0x80004DBC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80004DC0: addiu       $v0, $sp, 0x44
    ctx->r2 = ADD32(ctx->r29, 0X44);
L_80004DC4:
    // 0x80004DC4: addiu       $a0, $a3, -0xC0
    ctx->r4 = ADD32(ctx->r7, -0XC0);
    // 0x80004DC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80004DCC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80004DD0: jal         0x80007C50
    // 0x80004DD4: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    func_80007C50(rdram, ctx);
        goto after_0;
    // 0x80004DD4: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    after_0:
    // 0x80004DD8: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80004DDC: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80004DE0: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80004DE4: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80004DE8: addiu       $t9, $t9, 0x7970
    ctx->r25 = ADD32(ctx->r25, 0X7970);
    // 0x80004DEC: sw          $t9, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->r25;
    // 0x80004DF0: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80004DF4: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x80004DF8: sw          $t2, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->r10;
    // 0x80004DFC: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80004E00: bgez        $a2, L_80004E10
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80004E04: sra         $t3, $a2, 2
        ctx->r11 = S32(SIGNED(ctx->r6) >> 2);
            goto L_80004E10;
    }
    // 0x80004E04: sra         $t3, $a2, 2
    ctx->r11 = S32(SIGNED(ctx->r6) >> 2);
    // 0x80004E08: addiu       $at, $a2, 0x3
    ctx->r1 = ADD32(ctx->r6, 0X3);
    // 0x80004E0C: sra         $t3, $at, 2
    ctx->r11 = S32(SIGNED(ctx->r1) >> 2);
L_80004E10:
    // 0x80004E10: beq         $t3, $zero, L_80004E34
    if (ctx->r11 == 0) {
        // 0x80004E14: addiu       $a0, $t3, -0x1
        ctx->r4 = ADD32(ctx->r11, -0X1);
            goto L_80004E34;
    }
    // 0x80004E14: addiu       $a0, $t3, -0x1
    ctx->r4 = ADD32(ctx->r11, -0X1);
L_80004E18:
    // 0x80004E18: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80004E1C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80004E20: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80004E24: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80004E28: sw          $t4, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r12;
    // 0x80004E2C: bne         $a0, $zero, L_80004E18
    if (ctx->r4 != 0) {
        // 0x80004E30: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_80004E18;
    }
    // 0x80004E30: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
L_80004E34:
    // 0x80004E34: b           L_80004E48
    // 0x80004E38: sw          $a3, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r7;
        goto L_80004E48;
    // 0x80004E38: sw          $a3, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r7;
    // 0x80004E3C: lw          $t5, 0x8($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X8);
L_80004E40:
    // 0x80004E40: addiu       $t6, $t5, -0x4
    ctx->r14 = ADD32(ctx->r13, -0X4);
    // 0x80004E44: sw          $t6, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r14;
L_80004E48:
    // 0x80004E48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80004E4C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80004E50: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80004E54: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80004E5C(uint8_t* rdram, recomp_context* ctx) {
    chopper_fiber_destroy((uint32_t)ctx->r4);
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80004E5C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80004E60: lw          $v1, -0x4A40($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4A40);
    // 0x80004E64: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80004E68: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x80004E6C: addiu       $t7, $t6, -0x4
    ctx->r15 = ADD32(ctx->r14, -0X4);
    // 0x80004E70: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    // 0x80004E74: sw          $a0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r4;
    // 0x80004E78: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80004E7C: lw          $t0, 0x4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4);
    // 0x80004E80: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80004E84: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x80004E88: lw          $t1, 0x4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4);
    // 0x80004E8C: jr          $ra
    // 0x80004E90: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    TRACE_RETURN()
    return;
    // 0x80004E90: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x80004E94: nop

    // 0x80004E98: nop

    // 0x80004E9C: nop

    // 0x80004EA0: addiu       $sp, $sp, -0x1018
    ctx->r29 = ADD32(ctx->r29, -0X1018);
    // 0x80004EA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004EA8: sw          $a0, 0x1018($sp)
    MEM_W(0X1018, ctx->r29) = ctx->r4;
    // 0x80004EAC: sw          $a1, 0x101C($sp)
    MEM_W(0X101C, ctx->r29) = ctx->r5;
    // 0x80004EB0: sw          $a2, 0x1020($sp)
    MEM_W(0X1020, ctx->r29) = ctx->r6;
    // 0x80004EB4: sw          $a3, 0x1024($sp)
    MEM_W(0X1024, ctx->r29) = ctx->r7;
    // 0x80004EB8: addiu       $a2, $sp, 0x101C
    ctx->r6 = ADD32(ctx->r29, 0X101C);
    // 0x80004EBC: lw          $a1, 0x1018($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1018);
    // 0x80004EC0: jal         0x80006D70
    // 0x80004EC4: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_80006D70(rdram, ctx);
        goto after_0;
    // 0x80004EC4: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
L_80004EC8:
    // 0x80004EC8: b           L_80004EC8
    pause_self(rdram);
    // 0x80004ECC: nop

    // 0x80004ED0: nop

    // 0x80004ED4: nop

    // 0x80004ED8: nop

    // 0x80004EDC: nop

    // 0x80004EE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80004EE4: addiu       $sp, $sp, 0x1018
    ctx->r29 = ADD32(ctx->r29, 0X1018);
    // 0x80004EE8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80004EF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80004EF0: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x80004EF4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80004EF8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80004EFC: addiu       $v1, $a0, 0x20
    ctx->r3 = ADD32(ctx->r4, 0X20);
    // 0x80004F00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80004F04: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80004F08: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80004F0C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80004F10: lui         $t2, 0xFFFF
    ctx->r10 = S32(0XFFFF << 16);
L_80004F14:
    // 0x80004F14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80004F18: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x80004F1C: lwc1        $f14, 0x4($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80004F20: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80004F24: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80004F28: mul.s       $f16, $f14, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80004F2C: beq         $a0, $t3, L_80004F94
    if (ctx->r4 == ctx->r11) {
        // 0x80004F30: nop
    
            goto L_80004F94;
    }
    // 0x80004F30: nop

L_80004F34:
    // 0x80004F34: mul.s       $f14, $f18, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80004F38: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80004F3C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80004F40: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80004F44: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80004F48: trunc.w.s   $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80004F4C: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x80004F50: mfc1        $t1, $f12
    ctx->r9 = (int32_t)ctx->f12.u32l;
    // 0x80004F54: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x80004F58: sra         $t9, $t1, 16
    ctx->r25 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80004F5C: andi        $t5, $t9, 0xFFFF
    ctx->r13 = ctx->r25 & 0XFFFF;
    // 0x80004F60: and         $t8, $a1, $t2
    ctx->r24 = ctx->r5 & ctx->r10;
    // 0x80004F64: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x80004F68: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x80004F6C: and         $t9, $t7, $t2
    ctx->r25 = ctx->r15 & ctx->r10;
    // 0x80004F70: sw          $t6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r14;
    // 0x80004F74: andi        $t8, $t1, 0xFFFF
    ctx->r24 = ctx->r9 & 0XFFFF;
    // 0x80004F78: or          $t5, $t9, $t8
    ctx->r13 = ctx->r25 | ctx->r24;
    // 0x80004F7C: sw          $t5, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r13;
    // 0x80004F80: lwc1        $f14, 0x4($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80004F84: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80004F88: mul.s       $f16, $f14, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80004F8C: bne         $a0, $t3, L_80004F34
    if (ctx->r4 != ctx->r11) {
        // 0x80004F90: nop
    
            goto L_80004F34;
    }
    // 0x80004F90: nop

L_80004F94:
    // 0x80004F94: mul.s       $f14, $f18, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80004F98: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80004F9C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80004FA0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80004FA4: trunc.w.s   $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80004FA8: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x80004FAC: mfc1        $t1, $f12
    ctx->r9 = (int32_t)ctx->f12.u32l;
    // 0x80004FB0: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x80004FB4: sra         $t9, $t1, 16
    ctx->r25 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80004FB8: andi        $t5, $t9, 0xFFFF
    ctx->r13 = ctx->r25 & 0XFFFF;
    // 0x80004FBC: and         $t8, $a1, $t2
    ctx->r24 = ctx->r5 & ctx->r10;
    // 0x80004FC0: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x80004FC4: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x80004FC8: and         $t9, $t7, $t2
    ctx->r25 = ctx->r15 & ctx->r10;
    // 0x80004FCC: andi        $t8, $t1, 0xFFFF
    ctx->r24 = ctx->r9 & 0XFFFF;
    // 0x80004FD0: sw          $t6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r14;
    // 0x80004FD4: or          $t5, $t9, $t8
    ctx->r13 = ctx->r25 | ctx->r24;
    // 0x80004FD8: sw          $t5, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r13;
    // 0x80004FDC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80004FE0: bne         $a2, $t4, L_80004F14
    if (ctx->r6 != ctx->r12) {
        // 0x80004FE4: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_80004F14;
    }
    // 0x80004FE4: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x80004FE8: jr          $ra
    TRACE_RETURN()
    return;
;}
RECOMP_FUNC void func_80004FF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80004FF0: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x80004FF4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80004FF8: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80004FFC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80005000: addiu       $v1, $a1, 0x20
    ctx->r3 = ADD32(ctx->r5, 0X20);
    // 0x80005004: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80005008: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x8000500C: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80005010: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80005014: lui         $t2, 0xFFFF
    ctx->r10 = S32(0XFFFF << 16);
L_80005018:
    // 0x80005018: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000501C: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
L_80005020:
    // 0x80005020: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80005024: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80005028: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8000502C: srl         $t7, $t6, 16
    ctx->r15 = S32(U32(ctx->r14) >> 16);
    // 0x80005030: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80005034: and         $t5, $t9, $t2
    ctx->r13 = ctx->r25 & ctx->r10;
    // 0x80005038: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x8000503C: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x80005040: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80005044: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80005048: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8000504C: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x80005050: sll         $t5, $t8, 16
    ctx->r13 = S32(ctx->r24 << 16);
    // 0x80005054: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
    // 0x80005058: and         $t6, $t5, $t2
    ctx->r14 = ctx->r13 & ctx->r10;
    // 0x8000505C: or          $a3, $t9, $t6
    ctx->r7 = ctx->r25 | ctx->r14;
    // 0x80005060: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80005064: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x80005068: sw          $a3, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r7;
    // 0x8000506C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80005070: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80005074: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80005078: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x8000507C: div.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80005080: div.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80005084: swc1        $f18, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->f18.u32l;
    // 0x80005088: bne         $a0, $t3, L_80005020
    if (ctx->r4 != ctx->r11) {
        // 0x8000508C: swc1        $f16, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->f16.u32l;
            goto L_80005020;
    }
    // 0x8000508C: swc1        $f16, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->f16.u32l;
    // 0x80005090: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80005094: bne         $a2, $t4, L_80005018
    if (ctx->r6 != ctx->r12) {
        // 0x80005098: addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
            goto L_80005018;
    }
    // 0x80005098: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x8000509C: jr          $ra
    // 0x800050A0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    TRACE_RETURN()
    return;
    // 0x800050A0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_800050B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800050B0: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800050B4: addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
    // 0x800050B8: addiu       $v1, $zero, 0x40
    ctx->r3 = ADD32(0, 0X40);
L_800050BC:
    // 0x800050BC: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x800050C0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800050C4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800050C8: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x800050CC: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x800050D0: bne         $v1, $zero, L_800050BC
    if (ctx->r3 != 0) {
        // 0x800050D4: addiu       $v0, $v0, 0x10
        ctx->r2 = ADD32(ctx->r2, 0X10);
            goto L_800050BC;
    }
    // 0x800050D4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800050D8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800050DC: jr          $ra
    // 0x800050E0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    TRACE_RETURN()
    return;
    // 0x800050E0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_800050E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800050E4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800050E8: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x800050EC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800050F0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800050F4: sw          $a2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r6;
    // 0x800050F8: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800050FC: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80005100: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x80005104: jr          $ra
    // 0x80005108: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    TRACE_RETURN()
    return;
    // 0x80005108: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
;}
RECOMP_FUNC void func_8000510C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x8000510C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80005110: addiu       $a3, $a1, 0x3
    ctx->r7 = ADD32(ctx->r5, 0X3);
    // 0x80005114: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80005118: and         $v0, $a3, $at
    ctx->r2 = ctx->r7 & ctx->r1;
    // 0x8000511C: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80005120: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x80005124: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80005128: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x8000512C: beq         $at, $zero, L_80005144
    if (ctx->r1 == 0) {
        // 0x80005130: lw          $a2, 0x4($t8)
        ctx->r6 = MEM_W(ctx->r24, 0X4);
            goto L_80005144;
    }
    // 0x80005130: lw          $a2, 0x4($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X4);
L_80005134:
    // 0x80005134: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80005138: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000513C: bne         $at, $zero, L_80005134
    if (ctx->r1 != 0) {
        // 0x80005140: sb          $zero, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = 0;
            goto L_80005134;
    }
    // 0x80005140: sb          $zero, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = 0;
L_80005144:
    // 0x80005144: subu        $a1, $v1, $a2
    ctx->r5 = SUB32(ctx->r3, ctx->r6);
    // 0x80005148: sw          $a1, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->r5;
    // 0x8000514C: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x80005150: addu        $v0, $a2, $a1
    ctx->r2 = ADD32(ctx->r6, ctx->r5);
    // 0x80005154: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80005158: jr          $ra
    // 0x8000515C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    TRACE_RETURN()
    return;
    // 0x8000515C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_80005160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x80005160: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80005164: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x80005168: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8000516C: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x80005170: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80005174: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x80005178: sw          $a1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r5;
    // 0x8000517C: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x80005180: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x80005184: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x80005188: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x8000518C: sw          $t1, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r9;
    // 0x80005190: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80005194: lw          $t5, 0x4($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X4);
    // 0x80005198: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8000519C: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x800051A0: sw          $t5, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r13;
    // 0x800051A4: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x800051A8: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x800051AC: addu        $v1, $a0, $t0
    ctx->r3 = ADD32(ctx->r4, ctx->r8);
    // 0x800051B0: lw          $t2, 0xC($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XC);
    // 0x800051B4: addu        $t3, $t2, $a1
    ctx->r11 = ADD32(ctx->r10, ctx->r5);
    // 0x800051B8: addiu       $t1, $t3, 0x8
    ctx->r9 = ADD32(ctx->r11, 0X8);
    // 0x800051BC: jr          $ra
    // 0x800051C0: sw          $t1, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r9;
    TRACE_RETURN()
    return;
    // 0x800051C0: sw          $t1, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r9;
;}
RECOMP_FUNC void func_800051C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800051C4: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x800051C8: sll         $t6, $a1, 4
    ctx->r14 = S32(ctx->r5 << 4);
    // 0x800051CC: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x800051D0: lw          $v0, 0x10($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X10);
    // 0x800051D4: addiu       $t8, $a1, -0x1
    ctx->r24 = ADD32(ctx->r5, -0X1);
    // 0x800051D8: jr          $ra
    // 0x800051DC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    TRACE_RETURN()
    return;
    // 0x800051DC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_800051E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    TRACE_ENTRY()
    // 0x800051E0: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x800051E4: addiu       $a3, $a0, 0x8
    ctx->r7 = ADD32(ctx->r4, 0X8);
    // 0x800051E8: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_800051EC:
    // 0x800051EC: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800051F0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800051F4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800051F8: bne         $v1, $zero, L_800051EC
    if (ctx->r3 != 0) {
        // 0x800051FC: sb          $v1, -0x1($a3)
        MEM_B(-0X1, ctx->r7) = ctx->r3;
            goto L_800051EC;
    }
    // 0x800051FC: sb          $v1, -0x1($a3)
    MEM_B(-0X1, ctx->r7) = ctx->r3;
    // 0x80005200: addiu       $v1, $a3, 0x3
    ctx->r3 = ADD32(ctx->r7, 0X3);
    // 0x80005204: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80005208: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x8000520C: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80005210: beq         $at, $zero, L_80005228
    if (ctx->r1 == 0) {
        // 0x80005214: addiu       $v1, $a0, 0x4
        ctx->r3 = ADD32(ctx->r4, 0X4);
            goto L_80005228;
    }
    // 0x80005214: addiu       $v1, $a0, 0x4
    ctx->r3 = ADD32(ctx->r4, 0X4);
L_80005218:
    // 0x80005218: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8000521C: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80005220: bne         $at, $zero, L_80005218
    if (ctx->r1 != 0) {
        // 0x80005224: sb          $zero, -0x1($a3)
        MEM_B(-0X1, ctx->r7) = 0;
            goto L_80005218;
    }
    // 0x80005224: sb          $zero, -0x1($a3)
    MEM_B(-0X1, ctx->r7) = 0;
L_80005228:
    // 0x80005228: subu        $t7, $a3, $v1
    ctx->r15 = SUB32(ctx->r7, ctx->r3);
    // 0x8000522C: addiu       $t8, $t7, -0x4
    ctx->r24 = ADD32(ctx->r15, -0X4);
    // 0x80005230: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80005234: jr          $ra
    // 0x80005238: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    TRACE_RETURN()
    return;
    // 0x80005238: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
;}
