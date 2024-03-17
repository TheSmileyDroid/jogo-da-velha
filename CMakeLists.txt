cmake_minimum_required(VERSION 3.10)
project(Velha)

set(CMAKE_CXX_STANDARD 17)

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})


# Find SDL2

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS})

# Add your source files
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")
add_executable(Velha ${SOURCE_FILES})

target_precompile_headers(Velha PRIVATE "src/precompiled.hpp")

# Link SDL2
target_link_libraries(Velha PRIVATE SDL2_image::SDL2_image SDL2_ttf::SDL2_ttf SDL2::SDL2main SDL2::SDL2)
