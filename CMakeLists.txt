cmake_minimum_required(VERSION 3.20)

project(ChopperAttack LANGUAGES C CXX)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Avoid warning about DOWNLOAD_EXTRACT_TIMESTAMP in CMake 3.24:
if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
    cmake_policy(SET CMP0135 NEW)
endif()

# Windows specific configurations
if (WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_DISABLE_CONSTEXPR_MUTEX_CONSTRUCTOR")
    add_compile_definitions(
        NOMINMAX
        _CRT_SECURE_NO_WARNINGS
    )
    if (MSVC)
        add_compile_options(/bigobj)
    endif()
endif()

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Configure RT64
set(RT64_STATIC TRUE)
set(RT64_SDL_WINDOW_VULKAN TRUE)
add_compile_definitions(HLSL_CPU)

# Add RT64
add_subdirectory(tools/rt64 ${CMAKE_BINARY_DIR}/rt64)
target_include_directories(rt64 PRIVATE ${CMAKE_BINARY_DIR}/rt64/src)

# Add N64ModernRuntime
add_subdirectory(tools/N64ModernRuntime ${CMAKE_BINARY_DIR}/N64ModernRuntime)

# Fetch SDL2 on Windows
if (WIN32)
    include(FetchContent)
    if (DEFINED ENV{SDL2_VERSION})
        set(SDL2_VERSION $ENV{SDL2_VERSION})
    else()
        set(SDL2_VERSION "2.30.3")
    endif()

    FetchContent_Declare(
        sdl2
        URL https://github.com/libsdl-org/SDL/releases/download/release-${SDL2_VERSION}/SDL2-devel-${SDL2_VERSION}-VC.zip
    )
    FetchContent_MakeAvailable(sdl2)
endif()

# RecompiledFuncs - Library containing all C source files from N64Recomp
add_library(RecompiledFuncs STATIC)

file(GLOB FUNC_C_SOURCES ${CMAKE_SOURCE_DIR}/recomp/*.c)
target_sources(RecompiledFuncs PRIVATE ${FUNC_C_SOURCES})

target_include_directories(RecompiledFuncs PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/recomp
    ${CMAKE_SOURCE_DIR}/tools/N64ModernRuntime/ultramodern/include
    ${CMAKE_SOURCE_DIR}/tools/N64ModernRuntime/librecomp/include
    ${CMAKE_SOURCE_DIR}/tools/N64ModernRuntime/N64Recomp/include
)

if (MSVC)
    target_compile_options(RecompiledFuncs PRIVATE /W0 /O2 /bigobj)
else()
    target_compile_options(RecompiledFuncs PRIVATE -w -O2 -fno-strict-aliasing)
endif()

# ChopperAttack executable
add_executable(ChopperAttack
    src/main.cpp
    rsp/aspMain.cpp
    src/rt64_render_context.cpp
    src/register_overlays.cpp
    src/fiber_manager.cpp
)

target_include_directories(ChopperAttack PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/recomp
    ${CMAKE_SOURCE_DIR}/tools/N64ModernRuntime/ultramodern/include
    ${CMAKE_SOURCE_DIR}/tools/N64ModernRuntime/librecomp/include
    ${CMAKE_SOURCE_DIR}/tools/N64ModernRuntime/N64Recomp/include
    ${CMAKE_SOURCE_DIR}/tools/rt64/src
    ${CMAKE_SOURCE_DIR}/tools/rt64/src/contrib
    ${CMAKE_SOURCE_DIR}/tools/rt64/src/contrib/hlslpp/include
    ${CMAKE_SOURCE_DIR}/tools/rt64/src/contrib/dxc/inc
    ${CMAKE_SOURCE_DIR}/tools/rt64/src/rhi
    ${CMAKE_SOURCE_DIR}/tools/rt64/src/render
    ${CMAKE_SOURCE_DIR}/tools/rt64/src/hle
    ${CMAKE_BINARY_DIR}/rt64/src
)

if (WIN32)
    target_include_directories(ChopperAttack PRIVATE
        ${sdl2_SOURCE_DIR}/include
    )
    target_link_directories(ChopperAttack PRIVATE
        ${sdl2_SOURCE_DIR}/lib/x64
    )
    target_link_libraries(ChopperAttack PRIVATE
        RecompiledFuncs
        librecomp
        ultramodern
        rt64
        SDL2
        Winmm.lib
    )

    # Copy DLLs to target folder
    add_custom_command(TARGET ChopperAttack POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${sdl2_SOURCE_DIR}/lib/x64/SDL2.dll"
            "${CMAKE_SOURCE_DIR}/tools/rt64/src/contrib/dxc/bin/x64/dxil.dll"
            "${CMAKE_SOURCE_DIR}/tools/rt64/src/contrib/dxc/bin/x64/dxcompiler.dll"
            $<TARGET_FILE_DIR:ChopperAttack>
    )

    set_target_properties(
        ChopperAttack
        PROPERTIES
            LINK_FLAGS "/SUBSYSTEM:CONSOLE"
    )
else()
    find_package(SDL2 REQUIRED)
    target_include_directories(ChopperAttack PRIVATE ${SDL2_INCLUDE_DIRS})
    target_link_libraries(ChopperAttack PRIVATE
        RecompiledFuncs
        librecomp
        ultramodern
        rt64
        ${SDL2_LIBRARIES}
        pthread
        dl
    )
endif()
