cmake_minimum_required(VERSION 3.20)
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE AND DEFINED ENV{VITASDK})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE FILEPATH "VitaSDK toolchain")
endif()
project(ChopperAttackVitaCore LANGUAGES C CXX)

if(NOT CMAKE_C_COMPILER MATCHES "arm-vita-eabi-gcc")
    message(FATAL_ERROR "Set VITASDK or pass the VitaSDK CMake toolchain file.")
endif()

set(chopper_root "${CMAKE_CURRENT_LIST_DIR}/..")
set(runtime "${chopper_root}/tools/N64ModernRuntime")
if(NOT EXISTS "${runtime}/N64Recomp/include/recomp.h")
    message(FATAL_ERROR "Initialize the pinned N64ModernRuntime dependency first.")
endif()

file(GLOB recompiled_sources CONFIGURE_DEPENDS "${chopper_root}/recomp/funcs_*.c")
if(NOT recompiled_sources)
    message(FATAL_ERROR "The existing N64Recomp output is required.")
endif()

# Compile the shared game code separately from the host runtime and renderer.
# This archive contains unresolved host callbacks and is not an installable VPK.
add_library(ChopperAttackVitaCore STATIC
    ${recompiled_sources}
    "${chopper_root}/src/aim_assist.c"
    "${chopper_root}/src/fiber_manager.cpp"
    "${chopper_root}/src/register_overlays.cpp"
    "${chopper_root}/rsp/aspMain.cpp"
    controls.cpp
)
target_compile_features(ChopperAttackVitaCore PRIVATE c_std_17 cxx_std_20)
target_link_libraries(ChopperAttackVitaCore PUBLIC SceCtrl_stub)
target_compile_options(ChopperAttackVitaCore PRIVATE
    -mcpu=cortex-a9 -mfpu=neon -fno-strict-aliasing
)
target_include_directories(ChopperAttackVitaCore PRIVATE
    "${chopper_root}/include"
    "${chopper_root}/recomp"
    "${runtime}/N64Recomp/include"
    "${runtime}/librecomp/include"
    "${runtime}/ultramodern/include"
)

option(CHOPPER_VITA_APP "Build the experimental Vita application and VPK" OFF)
if(CHOPPER_VITA_APP)
    set(CHOPPER_VITA_RUNTIME "${chopper_root}/build/vita-deps/runtime" CACHE PATH "Vita-patched N64ModernRuntime source")
    set(CHOPPER_VITA_RENDERER "${chopper_root}/build/vita-deps/gles" CACHE PATH "Vita-patched Fast3D GLES renderer source")
    if(NOT EXISTS "${CHOPPER_VITA_RUNTIME}/CMakeLists.txt" OR
       NOT EXISTS "${CHOPPER_VITA_RENDERER}/n64_renderer.cpp")
        message(FATAL_ERROR "Prepare the Vita runtime and renderer first. See the Vita build instructions.")
    endif()

    include("${VITASDK}/share/vita.cmake")
    add_compile_options(-mcpu=cortex-a9 -mfpu=neon -fno-strict-aliasing)
    add_subdirectory("${CHOPPER_VITA_RUNTIME}" runtime EXCLUDE_FROM_ALL)

    add_executable(ChopperAttackVita main.cpp audio.cpp mod_stubs.cpp
        "${CHOPPER_VITA_RENDERER}/n64_renderer.cpp")
    target_compile_features(ChopperAttackVita PRIVATE cxx_std_20)
    target_include_directories(ChopperAttackVita PRIVATE
        "${CHOPPER_VITA_RENDERER}"
        "${CHOPPER_VITA_RUNTIME}/N64Recomp/include"
        "${CHOPPER_VITA_RUNTIME}/thirdparty/xxHash"
    )
    target_link_libraries(ChopperAttackVita PRIVATE
        -Wl,--start-group ChopperAttackVitaCore librecomp ultramodern -Wl,--end-group
        vitaGL vitashark SceShaccCgExt mathneon taihen_stub SceShaccCg_stub
        SceKernelDmacMgr_stub SceGxm_stub SceCommonDialog_stub SceRazorCapture_stub
        SceDisplay_stub SceAudio_stub SceSysmem_stub SceAppMgr_stub SceKernelThreadMgr_stub
        SceFiber_stub -Wl,--whole-archive pthread -Wl,--no-whole-archive
    )

    vita_create_self(eboot.bin ChopperAttackVita UNSAFE)
    vita_create_vpk(ChopperAttack.vpk CHOP00001 eboot.bin
        VERSION "01.02" NAME "Chopper Attack Recompiled")
endif()
