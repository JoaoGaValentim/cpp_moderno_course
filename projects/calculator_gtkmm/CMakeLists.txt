cmake_minimum_required(VERSION 3.10)
project(MyGtkApp)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Find GTKMM package
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

# Include directories
include_directories(${GTKMM_INCLUDE_DIRS})

set(SOURCE
    src/main.cpp
)

# Add executable
add_executable(MyGtkApp ${SOURCE})

# Link libraries
target_link_libraries(MyGtkApp ${GTKMM_LIBRARIES})
