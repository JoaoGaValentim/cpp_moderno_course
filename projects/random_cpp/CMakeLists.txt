cmake_minimum_required(VERSION 3.10)

project(RandomCpp)

set(CMAKE_CXX_STANDARD 23)

set(SOURCE
    src/main.cpp
)

add_executable(RandomCpp ${SOURCE})