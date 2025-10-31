cmake_minimum_required(VERSION 3.12.0)

project(lab6)

include_directories(include)

set(SOURCES
    src/main.cpp
    src/date.cpp
    src/utils.cpp
    src/program.cpp
    src/menu.cpp
)

set(HEADERS
    include/consts.h
    include/date.h
    include/utils.h
    include/program.h
    include/menu.h
)

add_executable(lab6 ${SOURCES})