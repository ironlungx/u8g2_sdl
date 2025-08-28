cmake_minimum_required(VERSION 3.10)
project(Renderer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -O3")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(source_dir "${PROJECT_SOURCE_DIR}/src/")
set(lib_dir "${PROJECT_SOURCE_DIR}/lib/")

file(GLOB source_files "${source_dir}/*.cpp")

# Collect u8g2 core sources
file(GLOB u8g2_core_sources "${lib_dir}/u8g2/csrc/*.c")

# Collect u8g2 SDL system sources (this was missing!)
file(GLOB u8g2_sdl_sources "${lib_dir}/u8g2/sys/sdl/common/*.c")

# Combine all u8g2 sources
set(u8g2_all_sources ${u8g2_core_sources} ${u8g2_sdl_sources})

# Add u8g2 as a static library with ALL sources
add_library(u8g2 STATIC ${u8g2_all_sources})

# Set include directories for u8g2
target_include_directories(u8g2 PUBLIC
    "${lib_dir}/u8g2/csrc/"
    "${lib_dir}/u8g2/sys/sdl/common/"
)

# Find SDL2
find_package(SDL2 REQUIRED)

# Link SDL2 to u8g2 since it depends on SDL
target_link_libraries(u8g2 PUBLIC ${SDL2_LIBRARIES})
target_include_directories(u8g2 PUBLIC ${SDL2_INCLUDE_DIRS})

# Add executable
add_executable(Renderer ${source_files})

# Link u8g2 to your executable (u8g2 will bring SDL2 with it)
target_link_libraries(Renderer PRIVATE u8g2)
