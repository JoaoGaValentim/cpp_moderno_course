cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 23)

project(EnumClass)

set(SOURCE
    src/main.cpp
)

add_executable(EnumClass ${SOURCE})

target_include_directories(EnumClass PRIVATE ${SOURCE_DIR}/include)
