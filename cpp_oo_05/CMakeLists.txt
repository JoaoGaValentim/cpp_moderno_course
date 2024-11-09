# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(constexpr VERSION 1.0)

# Add the source files
set(SOURCES
    src/main.cpp
)

# Create an executable from the source files
add_executable(constexpr_app ${SOURCES})