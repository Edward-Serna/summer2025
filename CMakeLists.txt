cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 17)
project(summer2025)

set(CMAKE_FIND_LIBRARY_PREFER_SHARED TRUE)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)

# SDL3 Configuration
set(SDL_STATIC ON)
set(SDL_SHARED OFF)  # Explicitly disable shared libraries
add_subdirectory(thirdparty/sdl)

# Find OpenGL
find_package(OpenGL REQUIRED)

# Add executable
add_executable(summer2025
        src/main.cpp
        # ImGui core files
        "${PROJECT_SOURCE_DIR}/thirdparty/imgui/imgui.cpp"
        "${PROJECT_SOURCE_DIR}/thirdparty/imgui/imgui_draw.cpp"
        "${PROJECT_SOURCE_DIR}/thirdparty/imgui/imgui_widgets.cpp"
        "${PROJECT_SOURCE_DIR}/thirdparty/imgui/imgui_tables.cpp"
        "${PROJECT_SOURCE_DIR}/thirdparty/imgui/imgui_demo.cpp"
        # ImGui backends
        "${PROJECT_SOURCE_DIR}/thirdparty/imgui/backends/imgui_impl_sdl3.cpp"
        "${PROJECT_SOURCE_DIR}/thirdparty/imgui/backends/imgui_impl_opengl3.cpp"
)

# Link libraries
target_link_libraries(summer2025 PRIVATE
        SDL3::SDL3-static
        ${OPENGL_LIBRARIES}
)

# Include directories
target_include_directories(summer2025 PRIVATE
        ${PROJECT_BINARY_DIR}
        ${OPENGL_INCLUDE_DIR}
        ${PROJECT_SOURCE_DIR}/thirdparty/imgui
        ${PROJECT_SOURCE_DIR}/thirdparty/imgui/backends
        ${PROJECT_SOURCE_DIR}/thirdparty/sdl/include
)

# Copy font file to build directory (optional but recommended)
configure_file(
        ${PROJECT_SOURCE_DIR}/thirdparty/imgui/misc/fonts/Roboto-Medium.ttf
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Roboto-Medium.ttf
        COPYONLY
)

# Platform-specific configurations
if(WIN32)
    # Windows-specific settings
    target_link_libraries(summer2025 PRIVATE
            opengl32
            gdi32
            winmm
            imm32
            ole32
            oleaut32
            uuid
            advapi32
            shell32
            version
    )
elseif(APPLE)
    # macOS-specific settings
    find_library(COCOA_LIBRARY Cocoa)
    find_library(IOKIT_LIBRARY IOKit)
    find_library(COREVIDEO_LIBRARY CoreVideo)
    target_link_libraries(summer2025 PRIVATE
            ${COCOA_LIBRARY}
            ${IOKIT_LIBRARY}
            ${COREVIDEO_LIBRARY}
    )
elseif(UNIX)
    # Linux-specific settings
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
    target_link_libraries(summer2025 PRIVATE
            ${GTK3_LIBRARIES}
            pthread
            dl
    )
    target_include_directories(summer2025 PRIVATE ${GTK3_INCLUDE_DIRS})
endif()

# Compiler-specific settings
if(MSVC)
    target_compile_options(summer2025 PRIVATE /W4)
else()
    target_compile_options(summer2025 PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Debug/Release configurations
set_target_properties(summer2025 PROPERTIES
        DEBUG_POSTFIX "_d"
)

# Set working directory for Visual Studio
set_property(TARGET summer2025 PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

# Print some useful information
message(STATUS "SDL3 include directory: ${PROJECT_SOURCE_DIR}/thirdparty/sdl/include")
message(STATUS "ImGui directory: ${PROJECT_SOURCE_DIR}/thirdparty/imgui")
message(STATUS "Runtime output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")