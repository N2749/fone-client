cmake_minimum_required(VERSION 3.14)
project(fone-client LANGUAGES C CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Project source directories
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

# Collect source files
file(GLOB_RECURSE AUDIO_SRC "${SRC_DIR}/audio/*.cpp")
file(GLOB_RECURSE CORE_SRC "${SRC_DIR}/core/*.cpp")
set(SOURCES ${AUDIO_SRC} ${CORE_SRC})

# Add SFML source directory
add_subdirectory(libs/SFML-2.6.2)

# Add executable
add_executable(fone-client ${SOURCES})

# Include directories
target_include_directories(fone-client PRIVATE ${INCLUDE_DIR} ${SRC_DIR}/audio ${SRC_DIR}/core)

# Link SFML libraries
target_link_libraries(fone-client PRIVATE sfml-audio sfml-system sfml-window sfml-graphics)

# Compiler warnings
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(fone-client PRIVATE -Wall -Wextra -pedantic)
endif()

