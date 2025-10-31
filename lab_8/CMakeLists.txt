cmake_minimum_required(VERSION 3.12.0)

include_directories(include)

project(lab8)

set(SOURCES
    src/main.cpp
    src/menus.cpp
    src/utils.cpp
)

set(HEADERS
    include/array.h
    include/algorithm.h
    include/consts.h
    include/menus.h
    include/program.h
    include/utils.h
)

add_executable(lab8 ${SOURCES} ${HEADERS})