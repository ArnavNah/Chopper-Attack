#pragma once

#include <memory>
#include <cstdint>
#include "ultramodern/renderer_context.hpp"

namespace chopper {
    namespace renderer {
        std::unique_ptr<ultramodern::renderer::RendererContext> create_render_context(uint8_t* rdram, ultramodern::renderer::WindowHandle window_handle, bool developer_mode);
    }
}
