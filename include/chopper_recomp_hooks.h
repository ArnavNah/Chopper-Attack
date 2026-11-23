#pragma once

#include "recomp.h"

#ifdef __cplusplus
extern "C" {
#endif

void osPfsIsPlug_recomp(uint8_t* rdram, recomp_context* ctx);
void __osPopThread_recomp(uint8_t* rdram, recomp_context* ctx);
void __osEnqueueThread_recomp(uint8_t* rdram, recomp_context* ctx);
void chopper_aim_cannon(uint8_t* rdram, recomp_context* ctx);
void chopper_aim_secondary(uint8_t* rdram, recomp_context* ctx);
void chopper_aim_reticle(uint8_t* rdram, recomp_context* ctx, gpr player);
void chopper_draw_lock(uint8_t* rdram, recomp_context* ctx);
#if defined(_WIN32) || defined(__vita__)
uint16_t chopper_flight_camera_mask(void);
void chopper_apply_flight_controls(uint8_t* rdram, recomp_context* ctx);
#endif

#ifdef __cplusplus
}
#endif
