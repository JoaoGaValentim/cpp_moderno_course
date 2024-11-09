# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(custom_types VERSION 1.0)

# Add the source files
set(SOURCES
    src/main.cpp
)

# Create an executable from the source files
add_executable(custom_types ${SOURCES})