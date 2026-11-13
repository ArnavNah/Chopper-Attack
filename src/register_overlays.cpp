#include <cstddef>

#define ARRLEN(x) (sizeof(x) / sizeof((x)[0]))

#include "recomp.h"
#include "librecomp/sections.h"
#include "librecomp/overlays.hpp"

// Include generated overlays table from N64Recomp
#include "recomp_overlays.inl"

namespace chopper {
    void register_overlays() {
        recomp::overlays::overlay_section_table_data_t sections {
            .code_sections = section_table,
            .num_code_sections = ARRLEN(section_table),
            .total_num_sections = num_sections,
        };

        recomp::overlays::overlays_by_index_t overlays {
            .table = overlay_sections_by_index,
            .len = ARRLEN(overlay_sections_by_index),
        };

        recomp::overlays::register_overlays(sections, overlays);
    }
}
