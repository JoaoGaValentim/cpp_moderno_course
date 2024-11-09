cmake_minimum_required(VERSION 3.10)

project(LambdaCpp)

set(CMAKE_CXX_STANDARD 23)

set(SOURCE
    src/main.cpp
)

add_executable(LambdaCpp ${SOURCE})