cmake_minimum_required(VERSION 3.12.0)

project(lab4)

include_directories(include)

set(SOURCES
    src/main.cpp
    src/cargo_carrier.cpp
    src/car.cpp
    src/train.cpp
    src/airplane.cpp
    src/functions.cpp
    src/program.cpp
    src/menu.cpp
)

set(HEADERS
    include/cargo_carrier.h
    include/car.h
    include/train.h
    include/airplane.h
    include/functions.h
    include/program.h
    include/menu.h
)

add_executable(lab4 ${SOURCES})