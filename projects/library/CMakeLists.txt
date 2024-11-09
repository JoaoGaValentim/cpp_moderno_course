cmake_minimum_required(VERSION 3.10)

# Project name
project(library)

# Set C++ standard (optional)
set(CMAKE_CXX_STANDARD 23)

# System-specific settings for MySQL
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    # For Linux systems
    if(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64")
        # For 64-bit x86 Linux
        set(MYSQL_INCLUDE_DIR "/usr/include/mysql")
        set(MYSQL_LIBRARIES "/usr/lib/x86_64-linux-gnu/libmysqlclient.so")
    elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "armv7l")
        # For ARMv7 32-bit Linux
        set(MYSQL_INCLUDE_DIR "/usr/include/mysql")
        set(MYSQL_LIBRARIES "/usr/arm-linux-gnueabihf/lib/mysql/libmysqlclient.so")
    elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64")
        # For ARM64 64-bit Linux
        set(MYSQL_INCLUDE_DIR "/usr/include/mysql")
        set(MYSQL_LIBRARIES "/usr/lib/aarch64-linux-gnu/libmysqlclient.so")
    else()
        message(FATAL_ERROR "Unsupported architecture for Linux: ${CMAKE_SYSTEM_PROCESSOR}")
    endif()
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    # For Windows systems
    if(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64")
        # For 64-bit Windows
        set(MYSQL_INCLUDE_DIR "C:/Program Files/MySQL/MySQL Connector C/include")
        set(MYSQL_LIBRARIES "C:/Program Files/MySQL/MySQL Connector C/lib/libmysql.lib")
        set(MYSQL_DLL_PATH "C:/Program Files/MySQL/MySQL Connector C/lib/libmysql.dll")
    elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "i686" OR CMAKE_SYSTEM_PROCESSOR MATCHES "x86")
        # For 32-bit Windows (i686 or x86)
        set(MYSQL_INCLUDE_DIR "C:/Program Files (x86)/MySQL/MySQL Connector C/include")
        set(MYSQL_LIBRARIES "C:/Program Files (x86)/MySQL/MySQL Connector C/lib/libmysql.lib")
        set(MYSQL_DLL_PATH "C:/Program Files (x86)/MySQL/MySQL Connector C/lib/libmysql.dll")
    elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "ARM")
        # For ARM-based Windows (e.g., ARM64)
        set(MYSQL_INCLUDE_DIR "C:/Program Files/MySQL/MySQL Connector C/include")
        set(MYSQL_LIBRARIES "C:/Program Files/MySQL/MySQL Connector C/lib/libmysql.lib")
        set(MYSQL_DLL_PATH "C:/Program Files/MySQL/MySQL Connector C/lib/libmysql.dll")
    else()
        message(FATAL_ERROR "Unsupported processor architecture for Windows: ${CMAKE_SYSTEM_PROCESSOR}")
    endif()

    # Add a post-build command to copy the MySQL DLL on Windows if linking dynamically
    add_custom_command(TARGET library POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different ${MYSQL_DLL_PATH} $<TARGET_FILE_DIR:library>)

elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    # For macOS systems
    set(MYSQL_INCLUDE_DIR "/usr/local/include/mysql")   # Path for macOS (adjust as needed)
    set(MYSQL_LIBRARIES "/usr/local/lib/libmysqlclient.dylib")  # Path for macOS (adjust as needed)
else()
    message(FATAL_ERROR "Unsupported operating system: ${CMAKE_SYSTEM_NAME}")
endif()

# Include MySQL headers
include_directories(${MYSQL_INCLUDE_DIR})

# Source files
set(SOURCE
    src/main.cpp
    src/connection_mysql.cpp
    src/book_model.cpp
    src/connection_exception.cpp
    src/empty_field_exception.cpp
)

# Add your executable
add_executable(library ${SOURCE})

# Include dir
target_include_directories(library PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Link MySQL client library
target_link_libraries(library ${MYSQL_LIBRARIES})

# Optionally, for Windows, copy the MySQL DLL to the output directory after build
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    add_custom_command(TARGET library POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different ${MYSQL_DLL_PATH} $<TARGET_FILE_DIR:library>)
endif()
