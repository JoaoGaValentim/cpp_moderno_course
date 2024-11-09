cmake_minimum_required(VERSION 3.10)

project(z_code_filter)

# my sets
set(CMAKE_CXX_STANDARD 23)

set(SOURCE
  src/main.cpp
  src/match.cpp
)

# create executable
add_executable(z_code_filter ${SOURCE})

# include folder
target_include_directories(z_code_filter PRIVATE ${CMAKE_SOURCE_DIR}/include)

