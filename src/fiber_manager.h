#pragma once
#include <stdint.h>
#include "recomp.h"

#ifdef __cplusplus
extern "C" {
#endif

void chopper_fiber_run_frame(uint8_t* rdram, recomp_context* ctx);
void chopper_fiber_yield(uint8_t* rdram, recomp_context* ctx);
void chopper_fiber_destroy(uint32_t fiber_addr);

#ifdef __cplusplus
}
#endif
