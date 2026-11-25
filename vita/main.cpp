#include "audio.hpp"
#include "controls.hpp"
#include "librecomp/game.hpp"
#include "librecomp/rsp.hpp"
#include "n64_renderer.hpp"

#include <cstdio>
#include <cstdlib>
#include <memory>
#include <psp2/ctrl.h>
#include <psp2/io/stat.h>
#include <psp2/kernel/clib.h>
#include <psp2/kernel/threadmgr.h>
#include <vitaGL.h>

extern "C" void recomp_entrypoint(uint8_t*, recomp_context*);
RspUcodeFunc aspMain;
namespace chopper { void register_overlays(); }

extern "C" {
unsigned int _newlib_heap_size_user = 128 * 1024 * 1024;
unsigned int _pthread_stack_default_user = 1024 * 1024;
}

namespace {

constexpr char data_dir[] = "ux0:data/ChopperAttack";
constexpr char rom_path[] = "ux0:data/ChopperAttack/chopper_attack.z64";
constexpr char log_path[] = "ux0:data/ChopperAttack/log.txt";
constexpr int screen_width = 960;
constexpr int screen_height = 544;

void report(const char* message) {
    sceClibPrintf("[Chopper Attack] %s\n", message);
    if (FILE* log = std::fopen(log_path, "a")) {
        std::fprintf(log, "%s\n", message);
        std::fclose(log);
    }
}

namespace renderer = ultramodern::renderer;

class VitaRenderer final : public renderer::RendererContext {
public:
    explicit VitaRenderer(uint8_t* rdram) {
        setup_result = renderer::SetupResult::Success;
        chosen_api = renderer::GraphicsApi::Auto;
        vglInitExtended(0, screen_width, screen_height, 16 * 1024 * 1024, SCE_GXM_MULTISAMPLE_NONE);
        vglWaitVblankStart(GL_FALSE);
        if (!glGetString(GL_VERSION)) {
            setup_result = renderer::SetupResult::GraphicsDeviceNotFound;
            return;
        }
        n64gfx::Config config;
        // Supersample the game framebuffers before the final 960x544 blit.
        config.scale = 2;
        config.output_width = screen_width;
        config.output_height = screen_height;
        config.direct_to_screen = false;
        graphics = std::make_unique<n64gfx::Renderer>(rdram, config);
        report("Vita graphics initialized.");
    }

    bool valid() override { return graphics != nullptr; }
    bool update_config(const renderer::GraphicsConfig&, const renderer::GraphicsConfig&) override { return true; }
    void enable_instant_present() override {}
    void send_dl(const OSTask* task) override {
        if (!graphics) return;
        graphics->process_dl(uint32_t(task->t.data_ptr) & 0x7FFFFF);
        if (!first_task) {
            first_task = true;
            const auto& stats = graphics->last_stats();
            char message[128];
            std::snprintf(message, sizeof(message), "First graphics task drew %u triangles and %u rectangles (%u unknown commands).",
                          stats.triangles, stats.rects, stats.unknown_commands);
            report(message);
        }
        frame_pending = true;
    }
    void send_dummy_workload(uint32_t) override {}
    void update_screen() override {
        const auto* vi = renderer::get_vi_regs();
        if (!graphics) return;
        if (vi->VI_H_START_REG == 0 || (vi->VI_STATUS_REG & 3) == 0) {
            if (!blacked) {
                glBindFramebuffer(GL_FRAMEBUFFER, 0);
                glDisable(GL_SCISSOR_TEST);
                glClearColor(0, 0, 0, 1);
                glClear(GL_COLOR_BUFFER_BIT);
                vglSwapBuffers(GL_FALSE);
                blacked = true;
            }
            return;
        }
        const uint32_t origin = vi->VI_ORIGIN_REG;
        if (!frame_pending && !blacked && origin == previous_origin) return;
        if (graphics->present(origin)) {
            vglSwapBuffers(GL_FALSE);
            if (!first_frame) {
                first_frame = true;
                report("Presented the first game frame.");
            }
        }
        previous_origin = origin;
        frame_pending = blacked = false;
    }
    void shutdown() override { graphics.reset(); }
    uint32_t get_display_framerate() const override { return 60; }
    float get_resolution_scale() const override { return 1.0f; }

private:
    std::unique_ptr<n64gfx::Renderer> graphics;
    uint32_t previous_origin = 0;
    bool frame_pending = false;
    bool blacked = false;
    bool first_task = false;
    bool first_frame = false;
};

void update_app(void*) {
    static uint64_t held_since = 0;
    constexpr unsigned chord = SCE_CTRL_START | SCE_CTRL_SELECT;
    SceCtrlData pad{};
    if (sceCtrlPeekBufferPositive(0, &pad, 1) <= 0 || (pad.buttons & chord) != chord) {
        held_since = 0;
        return;
    }
    const auto now = sceKernelGetSystemTimeWide();
    if (!held_since) held_since = now;
    if (now - held_since >= 2'000'000) ultramodern::quit();
}

}

extern "C" void recomp_trace_func_entry_str(const char*) {}
extern "C" void __osEnqueueThread_recomp(uint8_t*, recomp_context*) {}
extern "C" void __osDequeueThread_recomp(uint8_t*, recomp_context*) {}
extern "C" void __osPopThread_recomp(uint8_t*, recomp_context*) {}
extern "C" void __osDispatchThread_recomp(uint8_t*, recomp_context*) {}
extern "C" void osPfsIsPlug_recomp(uint8_t*, recomp_context* ctx) { ctx->r2 = 0; }

int main() {
    sceIoMkdir(data_dir, 0777);
    if (FILE* log = std::fopen(log_path, "w")) std::fclose(log);

    SceIoStat stat{};
    if (sceIoGetstat("ur0:data/libshacccg.suprx", &stat) < 0 &&
        sceIoGetstat("ur0:data/external/libshacccg.suprx", &stat) < 0) {
        report("vitaGL requires libshacccg.suprx in ur0:data.");
        return EXIT_FAILURE;
    }

    recomp::register_config_path(data_dir);
    const recomp::GameEntry game{
        .rom_hash = 0x567f7275cea88092ULL,
        .internal_name = "CHOPPER_ATTACK",
        .display_name = "Chopper Attack",
        .game_id = u8"chopper_attack",
        .save_type = recomp::SaveType::AllowAll,
        .is_enabled = true,
        .entrypoint_address = static_cast<gpr>(S32(0x80000400u)),
        .entrypoint = recomp_entrypoint,
    };
    recomp::register_game(game);
    recomp::check_all_stored_roms();
    if (!recomp::is_rom_valid(game.game_id)) {
        report("A valid Chopper Attack (USA) ROM is required at ux0:data/ChopperAttack/chopper_attack.z64.");
        return EXIT_FAILURE;
    }
    report("ROM validated. Starting the game.");
    chopper::register_overlays();

    const recomp::Configuration config{
        .project_version = recomp::Version(1, 0, 0),
        .rsp_callbacks = {.get_rsp_microcode = [](const OSTask* task) -> RspUcodeFunc* {
            return task->t.type == M_AUDTASK ? aspMain : nullptr;
        }},
        .renderer_callbacks = {.create_render_context = [](uint8_t* rdram, renderer::WindowHandle, bool) -> std::unique_ptr<renderer::RendererContext> {
            return std::make_unique<VitaRenderer>(rdram);
        }},
        .audio_callbacks = chopper::vita::initialize_audio(),
        .input_callbacks = chopper::vita::initialize_controls(),
        .gfx_callbacks = {
            .create_window = [](void*) -> renderer::WindowHandle { return {}; },
            .update_gfx = update_app,
        },
        .error_handling_callbacks = {.message_box = report},
    };
    recomp::start_game(game.game_id, "");
    recomp::start(config);
    chopper::vita::shutdown_audio();
    return EXIT_SUCCESS;
}
