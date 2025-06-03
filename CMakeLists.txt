cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 17)
project(summer2025)

set(CMAKE_FIND_LIBRARY_PREFER_SHARED TRUE)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)
set(SDL_STATIC ON)
add_subdirectory(thirdparty/sdl)

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

target_link_libraries(summer2025 PUBLIC
        SDL2-static ${OPENGL_LIBRARIES}
)

target_include_directories(summer2025 PUBLIC
        ${PROJECT_BINARY_DIR}
        ${OPENGL_INCLUDE_DIR}
        ${PROJECT_SOURCE_DIR}/thirdparty/imgui
        ${PROJECT_SOURCE_DIR}/thirdparty/imgui/backends
        ${PROJECT_SOURCE_DIR}/thirdparty/sdl/include
)