#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <unknwn.h>
#endif

#include "rt64_render_context.h"

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <memory>
#include <vector>

#include "hle/rt64_application.h"
#include "hle/rt64_shared_queue_resources.h"
#include "hle/rt64_interpreter.h"
#include "gbi/rt64_gbi.h"
#include "ultramodern/ultramodern.hpp"
#include "ultramodern/config.hpp"

namespace chopper {
    namespace renderer {

        static void save_n64_fb_to_bmp(const char* path, const uint8_t* rdram, uint32_t origin, int width, int height) {
            #pragma pack(push, 1)
            struct BMPHeader {
                uint16_t bfType = 0x4D42;
                uint32_t bfSize;
                uint16_t bfReserved1 = 0;
                uint16_t bfReserved2 = 0;
                uint32_t bfOffBits = 54;
                uint32_t biSize = 40;
                int32_t  biWidth;
                int32_t  biHeight;
                uint16_t biPlanes = 1;
                uint16_t biBitCount = 24;
                uint32_t biCompression = 0;
                uint32_t biSizeImage = 0;
                int32_t  biXPelsPerMeter = 2835;
                int32_t  biYPelsPerMeter = 2835;
                uint32_t biClrUsed = 0;
                uint32_t biClrImportant = 0;
            } hdr;
            #pragma pack(pop)

            int row_stride = (width * 3 + 3) & ~3;
            hdr.biWidth = width;
            hdr.biHeight = height;
            hdr.bfSize = 54 + row_stride * height;

            FILE* f = fopen(path, "wb");
            if (!f) return;
            fwrite(&hdr, sizeof(hdr), 1, f);

            const uint8_t* fb = rdram;
            std::vector<uint8_t> row(row_stride, 0);
            for (int y = height - 1; y >= 0; y--) {
                for (int x = 0; x < width; x++) {
                    uint32_t addr = origin + (y * width + x) * 2;
                    uint16_t pixel = *(const uint16_t*)&fb[addr ^ 2];
                    uint8_t r = ((pixel >> 11) & 0x1F) * 255 / 31;
                    uint8_t g = ((pixel >> 6) & 0x1F) * 255 / 31;
                    uint8_t b = ((pixel >> 1) & 0x1F) * 255 / 31;
                    row[x * 3 + 0] = b;
                    row[x * 3 + 1] = g;
                    row[x * 3 + 2] = r;
                }
                fwrite(row.data(), row_stride, 1, f);
            }
            fclose(f);
        }

        static uint8_t DMEM[0x1000];
        static uint8_t IMEM[0x1000];
        static unsigned int MI_INTR_REG = 0;
        static unsigned int DPC_START_REG = 0;
        static unsigned int DPC_END_REG = 0;
        static unsigned int DPC_CURRENT_REG = 0;
        static unsigned int DPC_STATUS_REG = 0;
        static unsigned int DPC_CLOCK_REG = 0;
        static unsigned int DPC_BUFBUSY_REG = 0;
        static unsigned int DPC_PIPEBUSY_REG = 0;
        static unsigned int DPC_TMEM_REG = 0;

        static void dummy_check_interrupts() {}

        static RT64::UserConfiguration::AspectRatio to_rt64(ultramodern::renderer::AspectRatio option) {
            switch (option) {
                case ultramodern::renderer::AspectRatio::Original:
                    return RT64::UserConfiguration::AspectRatio::Original;
                case ultramodern::renderer::AspectRatio::Expand:
                    return RT64::UserConfiguration::AspectRatio::Expand;
                case ultramodern::renderer::AspectRatio::Manual:
                    return RT64::UserConfiguration::AspectRatio::Manual;
                default:
                    return RT64::UserConfiguration::AspectRatio::Original;
            }
        }

        static RT64::UserConfiguration::Antialiasing to_rt64(ultramodern::renderer::Antialiasing option) {
            switch (option) {
                case ultramodern::renderer::Antialiasing::None:
                    return RT64::UserConfiguration::Antialiasing::None;
                case ultramodern::renderer::Antialiasing::MSAA2X:
                    return RT64::UserConfiguration::Antialiasing::MSAA2X;
                case ultramodern::renderer::Antialiasing::MSAA4X:
                    return RT64::UserConfiguration::Antialiasing::MSAA4X;
                case ultramodern::renderer::Antialiasing::MSAA8X:
                    return RT64::UserConfiguration::Antialiasing::MSAA8X;
                default:
                    return RT64::UserConfiguration::Antialiasing::None;
            }
        }

        static RT64::UserConfiguration::RefreshRate to_rt64(ultramodern::renderer::RefreshRate option) {
            switch (option) {
                case ultramodern::renderer::RefreshRate::Original:
                    return RT64::UserConfiguration::RefreshRate::Original;
                case ultramodern::renderer::RefreshRate::Display:
                    return RT64::UserConfiguration::RefreshRate::Display;
                case ultramodern::renderer::RefreshRate::Manual:
                    return RT64::UserConfiguration::RefreshRate::Manual;
                default:
                    return RT64::UserConfiguration::RefreshRate::Display;
            }
        }

        static void set_application_user_config(RT64::Application* application, const ultramodern::renderer::GraphicsConfig& config) {
            switch (config.res_option) {
                default:
                case ultramodern::renderer::Resolution::Auto:
                    application->userConfig.resolution = RT64::UserConfiguration::Resolution::WindowIntegerScale;
                    application->userConfig.downsampleMultiplier = 1;
                    break;
                case ultramodern::renderer::Resolution::Original:
                    application->userConfig.resolution = RT64::UserConfiguration::Resolution::Manual;
                    application->userConfig.resolutionMultiplier = std::max(config.ds_option, 1);
                    application->userConfig.downsampleMultiplier = std::max(config.ds_option, 1);
                    break;
                case ultramodern::renderer::Resolution::Original2x:
                    application->userConfig.resolution = RT64::UserConfiguration::Resolution::Manual;
                    application->userConfig.resolutionMultiplier = 2.0 * std::max(config.ds_option, 1);
                    application->userConfig.downsampleMultiplier = std::max(config.ds_option, 1);
                    break;
            }

            application->userConfig.aspectRatio = to_rt64(config.ar_option);
            application->userConfig.antialiasing = to_rt64(config.msaa_option);
            application->userConfig.refreshRate = to_rt64(config.rr_option);
            application->userConfig.refreshRateTarget = config.rr_manual_value;
            application->userConfig.displayBuffering = RT64::UserConfiguration::DisplayBuffering::Triple;
        }

        static ultramodern::renderer::SetupResult map_setup_result(RT64::Application::SetupResult rt64_result) {
            switch (rt64_result) {
                case RT64::Application::SetupResult::Success:
                    return ultramodern::renderer::SetupResult::Success;
                case RT64::Application::SetupResult::DynamicLibrariesNotFound:
                    return ultramodern::renderer::SetupResult::DynamicLibrariesNotFound;
                case RT64::Application::SetupResult::InvalidGraphicsAPI:
                    return ultramodern::renderer::SetupResult::InvalidGraphicsAPI;
                case RT64::Application::SetupResult::GraphicsAPINotFound:
                    return ultramodern::renderer::SetupResult::GraphicsAPINotFound;
                case RT64::Application::SetupResult::GraphicsDeviceNotFound:
                    return ultramodern::renderer::SetupResult::GraphicsDeviceNotFound;
            }
            return ultramodern::renderer::SetupResult::Success;
        }

        static ultramodern::renderer::GraphicsApi map_graphics_api(RT64::UserConfiguration::GraphicsAPI api) {
            switch (api) {
                case RT64::UserConfiguration::GraphicsAPI::D3D12:
                    return ultramodern::renderer::GraphicsApi::D3D12;
                case RT64::UserConfiguration::GraphicsAPI::Vulkan:
                    return ultramodern::renderer::GraphicsApi::Vulkan;
                case RT64::UserConfiguration::GraphicsAPI::Metal:
                    return ultramodern::renderer::GraphicsApi::Metal;
                case RT64::UserConfiguration::GraphicsAPI::Automatic:
                default:
                    return ultramodern::renderer::GraphicsApi::Auto;
            }
        }

        class RT64Context final : public ultramodern::renderer::RendererContext {
        public:
            RT64Context(uint8_t* rdram, ultramodern::renderer::WindowHandle window_handle, bool debug) {
                static unsigned char dummy_rom_header[0x40] = {0};

                RT64::Application::Core appCore{};
#if defined(_WIN32)
                appCore.window = window_handle.window;
#elif defined(__linux__) || defined(__ANDROID__)
                appCore.window = window_handle;
#elif defined(__APPLE__)
                appCore.window.window = window_handle.window;
                appCore.window.view = window_handle.view;
#endif
                appCore.checkInterrupts = dummy_check_interrupts;
                appCore.HEADER = dummy_rom_header;
                appCore.RDRAM = rdram;
                appCore.DMEM = DMEM;
                appCore.IMEM = IMEM;
                appCore.MI_INTR_REG = &MI_INTR_REG;
                appCore.DPC_START_REG = &DPC_START_REG;
                appCore.DPC_END_REG = &DPC_END_REG;
                appCore.DPC_CURRENT_REG = &DPC_CURRENT_REG;
                appCore.DPC_STATUS_REG = &DPC_STATUS_REG;
                appCore.DPC_CLOCK_REG = &DPC_CLOCK_REG;
                appCore.DPC_BUFBUSY_REG = &DPC_BUFBUSY_REG;
                appCore.DPC_PIPEBUSY_REG = &DPC_PIPEBUSY_REG;
                appCore.DPC_TMEM_REG = &DPC_TMEM_REG;

                ultramodern::renderer::ViRegs* vi_regs = ultramodern::renderer::get_vi_regs();
                appCore.VI_STATUS_REG = &vi_regs->VI_STATUS_REG;
                appCore.VI_ORIGIN_REG = &vi_regs->VI_ORIGIN_REG;
                appCore.VI_WIDTH_REG = &vi_regs->VI_WIDTH_REG;
                appCore.VI_INTR_REG = &vi_regs->VI_INTR_REG;
                appCore.VI_V_CURRENT_LINE_REG = &vi_regs->VI_V_CURRENT_LINE_REG;
                appCore.VI_TIMING_REG = &vi_regs->VI_TIMING_REG;
                appCore.VI_V_SYNC_REG = &vi_regs->VI_V_SYNC_REG;
                appCore.VI_H_SYNC_REG = &vi_regs->VI_H_SYNC_REG;
                appCore.VI_LEAP_REG = &vi_regs->VI_LEAP_REG;
                appCore.VI_H_START_REG = &vi_regs->VI_H_START_REG;
                appCore.VI_V_START_REG = &vi_regs->VI_V_START_REG;
                appCore.VI_V_BURST_REG = &vi_regs->VI_V_BURST_REG;
                appCore.VI_X_SCALE_REG = &vi_regs->VI_X_SCALE_REG;
                appCore.VI_Y_SCALE_REG = &vi_regs->VI_Y_SCALE_REG;

                RT64::ApplicationConfiguration appConfig;
                appConfig.useConfigurationFile = false;

                app = std::make_unique<RT64::Application>(appCore, appConfig);

                auto& cur_config = ultramodern::renderer::get_graphics_config();
                set_application_user_config(app.get(), cur_config);
                app->userConfig.developerMode = debug;
                app->enhancementConfig.f3dex.forceBranch = true;
                app->enhancementConfig.textureLOD.scale = true;

                switch (cur_config.api_option) {
                    case ultramodern::renderer::GraphicsApi::D3D12:
                        app->userConfig.graphicsAPI = RT64::UserConfiguration::GraphicsAPI::D3D12;
                        break;
                    case ultramodern::renderer::GraphicsApi::Vulkan:
                        app->userConfig.graphicsAPI = RT64::UserConfiguration::GraphicsAPI::Vulkan;
                        break;
                    case ultramodern::renderer::GraphicsApi::Metal:
                        app->userConfig.graphicsAPI = RT64::UserConfiguration::GraphicsAPI::Metal;
                        break;
                    case ultramodern::renderer::GraphicsApi::Auto:
                    default:
                        app->userConfig.graphicsAPI = RT64::UserConfiguration::GraphicsAPI::Automatic;
                        break;
                }

                uint32_t thread_id = 0;
#ifdef _WIN32
                thread_id = window_handle.thread_id;
#endif
                setup_result = map_setup_result(app->setup(thread_id));
                chosen_api = map_graphics_api(app->chosenGraphicsAPI);
                if (setup_result != ultramodern::renderer::SetupResult::Success) {
                    fprintf(stderr, "[RT64] Setup failed with error code %d\n", (int)setup_result);
                    app = nullptr;
                    return;
                }

                app->setFullScreen(cur_config.wm_option == ultramodern::renderer::WindowMode::Fullscreen);
            }

            ~RT64Context() override = default;

            bool valid() override { return static_cast<bool>(app); }

            bool update_config(const ultramodern::renderer::GraphicsConfig& old_config, const ultramodern::renderer::GraphicsConfig& new_config) override {
                if (old_config == new_config) {
                    return false;
                }
                if (new_config.wm_option != old_config.wm_option) {
                    app->setFullScreen(new_config.wm_option == ultramodern::renderer::WindowMode::Fullscreen);
                }
                set_application_user_config(app.get(), new_config);
                app->updateUserConfig(true);
                if (new_config.msaa_option != old_config.msaa_option) {
                    app->updateMultisampling();
                }
                return true;
            }

            void enable_instant_present() override {
                app->enhancementConfig.presentation.mode = RT64::EnhancementConfiguration::Presentation::Mode::PresentEarly;
                app->updateEnhancementConfig();
            }

            void send_dl(const OSTask* task) override {
                static uint32_t dl_count = 0;
                dl_count++;
                app->interpreter->loadUCodeGBI(task->t.ucode & 0x3FFFFFF, task->t.ucode_data & 0x3FFFFFF, true);
                if (std::getenv("CHOPPER_DEBUG") && (dl_count <= 5 || (dl_count % 30 == 0))) {
                    auto* gbi = app->interpreter->hleGBI;
                    printf("[RT64 send_dl #%u] task=%p, type=%u, flags=0x%X, ucode=0x%08X, ucode_data=0x%08X, data_ptr=0x%08X (size=0x%X)\n",
                        dl_count, (const void*)task, task->t.type, task->t.flags,
                        (uint32_t)task->t.ucode, (uint32_t)task->t.ucode_data,
                        (uint32_t)task->t.data_ptr, (uint32_t)task->t.data_size);
                    if (gbi != nullptr) {
                        printf("  -> GBI matched: ucode_enum=%u\n", (uint32_t)gbi->ucode);
                    } else {
                        printf("  -> GBI is NULL (unmatched microcode!)\n");
                    }
                    uint32_t dl_offset = task->t.data_ptr & 0x3FFFFFF;
                    uint32_t* dl_words = (uint32_t*)&app->core.RDRAM[dl_offset];
                    uint32_t num_pairs = std::min((uint32_t)(task->t.data_size / 8), 48u);
                    printf("  -> DL dump (first %u pairs):\n", num_pairs);
                    for (uint32_t i = 0; i < num_pairs; i++) {
                        printf("     [%02u] 0x%08X 0x%08X\n", i, dl_words[i * 2 + 0], dl_words[i * 2 + 1]);
                    }
                }
                app->processDisplayLists(app->core.RDRAM, task->t.data_ptr & 0x3FFFFFF, 0, true);
            }

            void send_dummy_workload(uint32_t fb_address) override {}

            void update_screen() override {
                static uint32_t screen_count = 0;
                screen_count++;
                RT64::VI vi = app->core.decodeVI();
                auto fb_size = vi.fbSize();
                uint32_t fb_addr = vi.fbAddress();
                if (std::getenv("CHOPPER_DEBUG") && (screen_count <= 10 || (screen_count % 60 == 0))) {
                    printf("[RT64 update_screen #%u] status=0x%08X, origin=0x%08X (fbAddr=0x%08X), fbSize=(%u, %u), width=%u, hStart=%u, visible=%d\n",
                        screen_count, vi.status.word, vi.origin, fb_addr, (uint32_t)fb_size.x, (uint32_t)fb_size.y, vi.width, vi.hRegion.hStart, (int)vi.visible());
                    if (vi.visible() && vi.origin >= 0x100000 && vi.origin < 8 * 1024 * 1024) {
                        uint8_t* fb = &app->core.RDRAM[vi.origin];
                        int nonzero = 0;
                        for (int b = 0; b < 320 * 240 * 2; b++) {
                            if (fb[b] != 0) { nonzero++; }
                        }
                        printf("  -> Framebuffer 0x%08X non-zero bytes: %d / %d\n", vi.origin, nonzero, 320 * 240 * 2);

                        if (screen_count % 60 == 0) {
                            char bmp_name[128];
                            snprintf(bmp_name, sizeof(bmp_name), "package/evidence/frame_%u.bmp", screen_count);
                            save_n64_fb_to_bmp(bmp_name, app->core.RDRAM, vi.origin, 320, 240);
                            snprintf(bmp_name, sizeof(bmp_name), "evidence/frame_%u.bmp", screen_count);
                            save_n64_fb_to_bmp(bmp_name, app->core.RDRAM, vi.origin, 320, 240);
                            printf("[Screenshot] Saved framebuffer BMP to frame_%u.bmp!\n", screen_count);
                        }
                    }
                }
                app->updateScreen();
            }

            void shutdown() override {
                if (app != nullptr) {
                    app->end();
                }
            }

            uint32_t get_display_framerate() const override {
                if (app && app->sharedQueueResources) {
                    return app->sharedQueueResources->swapChainRate;
                }
                return 60;
            }

            float get_resolution_scale() const override {
                constexpr int ReferenceHeight = 240;
                if (!app) return 1.0f;
                switch (app->userConfig.resolution) {
                    case RT64::UserConfiguration::Resolution::WindowIntegerScale:
                        if (app->sharedQueueResources && app->sharedQueueResources->swapChainHeight > 0) {
                            return std::max(float((app->sharedQueueResources->swapChainHeight + ReferenceHeight - 1) / ReferenceHeight), 1.0f);
                        } else {
                            return 1.0f;
                        }
                    case RT64::UserConfiguration::Resolution::Manual:
                        return float(app->userConfig.resolutionMultiplier);
                    case RT64::UserConfiguration::Resolution::Original:
                    default:
                        return 1.0f;
                }
            }

        private:
            std::unique_ptr<RT64::Application> app;
        };

        std::unique_ptr<ultramodern::renderer::RendererContext> create_render_context(uint8_t* rdram, ultramodern::renderer::WindowHandle window_handle, bool developer_mode) {
            return std::make_unique<RT64Context>(rdram, window_handle, developer_mode);
        }

    } // namespace renderer
} // namespace chopper
