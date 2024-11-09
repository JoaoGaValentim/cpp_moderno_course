# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(prototype_app VERSION 1.0)

# Add the source files
set(SOURCES
    src/main.cpp
)

# Create an executable from the source files
add_executable(prototype_app ${SOURCES})

target_include_directories(prototype_app PRIVATE ${CMAKE_SOURCE_DIR}/include)