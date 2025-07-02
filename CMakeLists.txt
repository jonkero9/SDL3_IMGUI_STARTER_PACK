cmake_minimum_required(VERSION 3.25.1)

project(sdl_starter)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set the output directory for built objects.
# This makes sure that the dynamic library goes into the build directory automatically.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

# This assumes the SDL source is available in vendored/SDL
add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)

add_executable(${PROJECT_NAME} 
    src/main.cpp 
    vendored/imgui/imgui.cpp
    vendored/imgui/imgui_draw.cpp
    vendored/imgui/imgui_demo.cpp
    vendored/imgui/imgui_impl_sdl3.cpp
    vendored/imgui/imgui_impl_sdlrenderer3.cpp
    vendored/imgui/imgui_tables.cpp
    vendored/imgui/imgui_widgets.cpp
)

# Link to the actual SDL3 library.
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)

target_include_directories(${PROJECT_NAME} PRIVATE 
    src
    vendored/entt
    vendored/imgui
)

