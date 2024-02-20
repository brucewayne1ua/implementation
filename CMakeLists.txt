cmake_minimum_required(VERSION 3.20)
project(Implementation)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set directories
set(HEADERS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/string/include)
set(SOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/string/src)

# Collect source files
file(GLOB SOURCES ${SOURCES_DIR}/*.cpp)

# Include directories
include_directories(${HEADERS_DIR})

# Add executable
add_executable(wstring ${SOURCES} ${HEADERS})
