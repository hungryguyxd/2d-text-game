cmake_minimum_required(VERSION 3.10)

project(2d-text-game)
# Set C++ standard to C++11
set(CMAKE_CXX_STANDARD 20)

# Add all the source files in the src directory to the project
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE SOURCES "main.cpp")

# Set the include directory
include_directories("includes")

# Add the executable
add_executable(game ${SOURCES})

# Set the path to the Raylib library relative to the project directory
set(RAYLIB_LIBRARY "${CMAKE_SOURCE_DIR}/lib/libraylib.a")
# Link Raylib library
target_link_libraries(game ${RAYLIB_LIBRARY})

# # Link against Core Foundation framework
# find_library(CORE_FOUNDATION CoreFoundation)
# target_link_libraries(game ${CORE_FOUNDATION})

# Copy required resources to build directory
file(COPY "resources" DESTINATION "${CMAKE_BINARY_DIR}")
