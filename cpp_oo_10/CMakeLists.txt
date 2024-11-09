cmake_minimum_required(VERSION 3.10)

# name project
project(cpp_str_mani)

# src 
set(SOURCE
  src/main.cxx
)

# executable
add_executable(CppStrMani ${SOURCE})

# include
target_include_directories(CppStrMani PRIVATE ${SOURCE_DIR}/include)

