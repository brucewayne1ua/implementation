cmake_minimum_required(VERSION 3.2)
project(Implementation)

# Установка версии CMake
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Включение исходных файлов и заголовочных файлов
set(HEADERS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/string/include)
set(SOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/string/src)
include_directories(${HEADERS_DIR})

# Создание исполняемого файла
add_executable(mystr ${SOURCES_DIR}/main.cpp)

# Указание библиотек и зависимостей, если таковые имеются

# Дополнительные настройки, если необходимо
