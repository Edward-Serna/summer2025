cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 17)
project(summer2025)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(thirdparty)
set(SDL_STATIC ON)

find_package(OpenGL REQUIRED)

add_executable(summer2025
        src/main.cpp
        "${PROJECT_SOURCE_DIR}/thirdparty/imgui/backends/imgui_impl_sdl2.cpp"
        "${PROJECT_SOURCE_DIR}/thirdparty/imgui/backends/imgui_impl_opengl3.cpp"
        "${PROJECT_SOURCE_DIR}/thirdparty/imgui/imgui.cpp"
        "${PROJECT_SOURCE_DIR}/thirdparty/imgui/imgui_draw.cpp"
        "${PROJECT_SOURCE_DIR}/thirdparty/imgui/imgui_widgets.cpp"
        "${PROJECT_SOURCE_DIR}/thirdparty/imgui/imgui_tables.cpp"
        "${PROJECT_SOURCE_DIR}/thirdparty/imgui/imgui_demo.cpp"
)
target_link_libraries(summer2025 PUBLIC SDL2 ${OPENGL_LIBRARIES})

target_include_directories(summer2025 PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/thirdparty/imgui/"
        "${PROJECT_SOURCE_DIR}/thirdparty/imgui/backends"
        "${PROJECT_SOURCE_DIR}/thirdparty/SDL/include/SDL3"
        ${OPENGL_INCLUDE_DIR}
)