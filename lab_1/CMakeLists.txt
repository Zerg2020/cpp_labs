cmake_minimum_required(VERSION 3.10)

project(MyApp)

include_directories(include)

set(SOURCES
   src/main.cpp   
   src/string.cpp
   src/functions.cpp
   src/menu.cpp
)

set(HEADERS
   include/functions.h
   include/string.h
   include/const.h
   include/menu.h
)
add_executable(MyApp ${SOURCES} ${HEADERS})