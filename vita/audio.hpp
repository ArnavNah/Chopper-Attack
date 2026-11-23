#pragma once

#include "ultramodern/ultramodern.hpp"

namespace chopper::vita {

ultramodern::audio_callbacks_t initialize_audio();
void shutdown_audio();

}
