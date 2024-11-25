# Minimum required version of CMake
cmake_minimum_required(VERSION 3.23)

# Project name
project(Raylib_2D_Stationary_Portal)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)

# Fleet test
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include directories for headers
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/ResourceManager/include)
include_directories(lib/raylib/include)

# Holds the full resolved path of Assets folder.
add_definitions(-DASSETS_PATH="${CMAKE_SOURCE_DIR}/Assets")

# Link directories
link_directories(lib/raylib/lib)

# Define the executable target
add_executable(Raylib_2D_Stationary_Portal src/main.cpp src/Game.cpp)

# Link the raylib library to the Visible 2D target
target_link_libraries(Raylib_2D_Stationary_Portal PRIVATE raylib)

# For Windows, link additional required libraries
if (WIN32)
    target_link_libraries(Raylib_2D_Stationary_Portal PRIVATE winmm)
endif()