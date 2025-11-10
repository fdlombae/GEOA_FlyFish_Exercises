cmake_minimum_required(VERSION 3.25)

# Set C++23 standard for the entire project
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project("FlyFish Exercises" VERSION 1.0.0 LANGUAGES CXX)

# Enable modern CMake features
if(POLICY CMP0135)
    cmake_policy(SET CMP0135 NEW)
endif()

# Compiler-specific optimizations
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic -O3)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options(/W4)
endif()

# --- Submodule check ---
if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/FlyFish/CMakeLists.txt")
    message(STATUS "FlyFish submodule not found. Initializing...")
    execute_process(
            COMMAND git submodule update --init --recursive
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
endif()

# --- Add the FlyFish submodule ---
add_subdirectory(FlyFish)

# --- Testing setup ---
include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
        DOWNLOAD_EXTRACT_TIMESTAMP ON
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# --- Create executables ---
add_executable(Lab_01 "tests/Lab_01_test.cpp" "src/Lab_01.cpp")
target_link_libraries(Lab_01 PRIVATE gtest gtest_main FlyFish)
