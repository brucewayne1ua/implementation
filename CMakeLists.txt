cmake_minimum_required(VERSION 3.20)
project(Implementation)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/string/include)
set(SOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/string/src)

include_directories(${HEADERS_DIR})

add_executable(a_string ${SOURCES_DIR}/main.cpp)

