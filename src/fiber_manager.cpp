#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

#include "fiber_manager.h"
#include <unordered_map>
#include <cstdio>
#include <cstring>

extern "C" void runtime_log(const char* fmt, ...);
extern "C" void func_80004E5C(uint8_t* rdram, recomp_context* ctx);

#define FIBER_CURRENT_PTR  0x8007B5C4
#define FIBER_HEAD_PTR     0x8007B5C8
#define FIBER_MAIN_PTR     0x8007B5CC

static inline int32_t& RDRAM_W(uint8_t* rdram, uint32_t addr, int32_t offset = 0) {
    uint32_t physical_addr = (addr + offset) & 0x007FFFFF;
    return *(int32_t*)(rdram + physical_addr);
}

struct HostFiber {
    void* host_fiber;
    uint32_t fiber_addr;
    uint8_t* rdram;
    recomp_context ctx;
    bool is_started;
    bool is_finished;
};

static void* s_main_fiber_host = nullptr;
static uint32_t s_current_running_fiber = 0;
static std::unordered_map<uint32_t, HostFiber*> s_fibers;
static uint64_t s_frame_count = 0;

extern "C" void chopper_fiber_destroy(uint32_t fiber_addr) {
    auto it = s_fibers.find(fiber_addr);
    if (it != s_fibers.end()) {
        it->second->is_finished = true;
    }
}

static void CALLBACK HostFiberProc(void* lpParameter) {
    HostFiber* hf = (HostFiber*)lpParameter;
    uint8_t* rdram = hf->rdram;
    recomp_context* ctx = &hf->ctx;
    uint32_t fiber_addr = hf->fiber_addr;

    hf->is_started = true;

    // Read initial fiber stack setup from RDRAM:
    uint32_t sp = (uint32_t)RDRAM_W(rdram, fiber_addr, 0x8);
    uint32_t entry_addr = sp ? (uint32_t)RDRAM_W(rdram, sp, 0x3C) : 0;
    uint32_t ra_addr = sp ? (uint32_t)RDRAM_W(rdram, sp, 0x38) : 0;

    if (sp == 0 || entry_addr == 0) {
        runtime_log("[HostFiber] ERROR: Invalid fiber 0x%08X (sp=0x%08X, entry=0x%08X)", fiber_addr, sp, entry_addr);
        hf->is_finished = true;
        SwitchToFiber(s_main_fiber_host);
        return;
    }

    // Initialize MIPS context for this fiber:
    ctx->r29 = (gpr)(int32_t)(sp + 0xC0);
    ctx->r4  = (gpr)(int32_t)RDRAM_W(rdram, sp, 0x00);
    ctx->r5  = (gpr)(int32_t)RDRAM_W(rdram, sp, 0x04);
    ctx->r6  = (gpr)(int32_t)RDRAM_W(rdram, sp, 0x08);
    ctx->r7  = (gpr)(int32_t)RDRAM_W(rdram, sp, 0x0C);
    ctx->r16 = (gpr)(int32_t)RDRAM_W(rdram, sp, 0x10);
    ctx->r17 = (gpr)(int32_t)RDRAM_W(rdram, sp, 0x14);
    ctx->r18 = (gpr)(int32_t)RDRAM_W(rdram, sp, 0x18);
    ctx->r19 = (gpr)(int32_t)RDRAM_W(rdram, sp, 0x1C);
    ctx->r20 = (gpr)(int32_t)RDRAM_W(rdram, sp, 0x20);
    ctx->r21 = (gpr)(int32_t)RDRAM_W(rdram, sp, 0x24);
    ctx->r22 = (gpr)(int32_t)RDRAM_W(rdram, sp, 0x28);
    ctx->r23 = (gpr)(int32_t)RDRAM_W(rdram, sp, 0x2C);
    ctx->r28 = (gpr)(int32_t)RDRAM_W(rdram, sp, 0x30);
    ctx->r30 = (gpr)(int32_t)RDRAM_W(rdram, sp, 0x34);
    ctx->r31 = (gpr)(int32_t)ra_addr;
    ctx->f_odd = &ctx->f0.u32h;
    ctx->mips3_float_mode = false;

    if (s_frame_count <= 20 || (s_frame_count % 300 == 0)) {
        runtime_log("[HostFiber] Fiber 0x%08X started: entry=0x%08X, sp=0x%08X, a0=0x%08X",
                    fiber_addr, entry_addr, (uint32_t)ctx->r29, (uint32_t)ctx->r4);
    }

    // Call entry point
    LOOKUP_FUNC(entry_addr)(rdram, ctx);

    if (s_frame_count <= 20 || (s_frame_count % 300 == 0)) {
        runtime_log("[HostFiber] Fiber 0x%08X finished normally", fiber_addr);
    }
    hf->is_finished = true;

    // Unlink and yield
    ctx->r4 = (gpr)(int32_t)fiber_addr;
    func_80004E5C(rdram, ctx);
    chopper_fiber_yield(rdram, ctx);

    // Fallback if returned
    SwitchToFiber(s_main_fiber_host);
}

static HostFiber* get_or_create_host_fiber(uint32_t fiber_addr, uint8_t* rdram) {
    auto it = s_fibers.find(fiber_addr);
    if (it != s_fibers.end()) {
        HostFiber* hf = it->second;
        if (!hf->is_finished) {
            return hf;
        }
        DeleteFiber(hf->host_fiber);
        delete hf;
        s_fibers.erase(it);
    }

    HostFiber* hf = new HostFiber();
    hf->fiber_addr = fiber_addr;
    hf->rdram = rdram;
    memset(&hf->ctx, 0, sizeof(recomp_context));
    hf->ctx.f_odd = &hf->ctx.f0.u32h;
    hf->ctx.mips3_float_mode = false;
    hf->is_started = false;
    hf->is_finished = false;
    hf->host_fiber = CreateFiber(256 * 1024, HostFiberProc, (void*)hf);
    s_fibers[fiber_addr] = hf;
    return hf;
}

extern "C" void chopper_fiber_run_frame(uint8_t* rdram, recomp_context* ctx) {
    s_frame_count++;

    if (!s_main_fiber_host) {
        s_main_fiber_host = ConvertThreadToFiber(NULL);
        if (!s_main_fiber_host) {
            s_main_fiber_host = GetCurrentFiber();
        }
    }

    uint32_t head = (uint32_t)RDRAM_W(rdram, FIBER_HEAD_PTR);
    uint32_t main_fiber = (uint32_t)RDRAM_W(rdram, FIBER_MAIN_PTR);

    if (head == 0 || main_fiber == 0) {
        return;
    }

    uint32_t first_fiber = (uint32_t)RDRAM_W(rdram, head, 0x0);
    if (first_fiber == 0 || first_fiber == main_fiber) {
        return;
    }

    if (s_frame_count <= 20 || (s_frame_count % 300 == 0)) {
        runtime_log("[FiberFrame #%llu] Starting frame: first_fiber=0x%08X", s_frame_count, first_fiber);
    }

    // Save main thread's sp to main_fiber struct in RDRAM
    RDRAM_W(rdram, main_fiber, 0x8) = (int32_t)ctx->r29;

    RDRAM_W(rdram, FIBER_CURRENT_PTR) = first_fiber;
    s_current_running_fiber = first_fiber;

    HostFiber* hf = get_or_create_host_fiber(first_fiber, rdram);
    if (hf && hf->host_fiber) {
        SwitchToFiber(hf->host_fiber);
    }

    // Returned to main fiber: restore FIBER_CURRENT_PTR in RDRAM
    RDRAM_W(rdram, FIBER_CURRENT_PTR) = main_fiber;
    s_current_running_fiber = main_fiber;

    if (s_frame_count <= 20 || (s_frame_count % 300 == 0)) {
        runtime_log("[FiberFrame #%llu] All fibers completed for frame, returning to Thread 6", s_frame_count);
    }
}

extern "C" void chopper_fiber_yield(uint8_t* rdram, recomp_context* ctx) {
    void* cur_host_fiber = GetCurrentFiber();
    if (!cur_host_fiber || cur_host_fiber == s_main_fiber_host) {
        return; // Called from main thread, ignore
    }

    uint32_t main_fiber = (uint32_t)RDRAM_W(rdram, FIBER_MAIN_PTR);
    uint32_t cur_fiber = (uint32_t)RDRAM_W(rdram, FIBER_CURRENT_PTR);

    if (cur_fiber != 0) {
        RDRAM_W(rdram, cur_fiber, 0x8) = (int32_t)ctx->r29;
    }

    uint32_t next_fiber = (cur_fiber != 0) ? (uint32_t)RDRAM_W(rdram, cur_fiber, 0x0) : 0;
    RDRAM_W(rdram, FIBER_CURRENT_PTR) = next_fiber;

    if (next_fiber == 0 || next_fiber == main_fiber) {
        s_current_running_fiber = main_fiber;
        SwitchToFiber(s_main_fiber_host);
    } else {
        s_current_running_fiber = next_fiber;
        HostFiber* hf = get_or_create_host_fiber(next_fiber, rdram);
        if (hf && hf->host_fiber) {
            SwitchToFiber(hf->host_fiber);
        } else {
            SwitchToFiber(s_main_fiber_host);
        }
    }
}
