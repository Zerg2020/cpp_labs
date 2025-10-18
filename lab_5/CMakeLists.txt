cmake_minimum_required(VERSION 3.12.0)

project(lab5)

include_directories(include)

set(SOURCES
    src/main.cpp
    src/menus.cpp
    src/utils.cpp
)

set(HEADERS
    include/binary_tree.h
    include/utils.h
    include/tree_node.h
    include/menus.h
    include/consts.h
    include/program.h
)

add_executable(lab5 ${SOURCES} )