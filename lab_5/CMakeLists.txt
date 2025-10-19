cmake_minimum_required(VERSION 3.10)

project(lab_5)

include_directories(include)

set(SOURCES
    src/main.cpp
    src/menu.cpp
    src/function.cpp
)

set(HEADERS
    include/menu.h
    include/function.h
    include/const.h
)

add_executable(lab_5 ${SOURCES})