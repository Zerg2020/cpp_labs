cmake_minimum_required(VERSION 3.12.0)

project(lab7)

include_directories(include)

set(SOURCES
    src/main.cpp
    src/date.cpp
    src/my_time.cpp
    src/utils.cpp
    src/phone_number.cpp
    src/phone_numbers.cpp
    src/city_code.cpp
    src/city_name.cpp
    src/tariff.cpp
    src/automatic_telephone_station.cpp
    src/menu.cpp
    src/program.cpp
)

set(HEADERS
    include/date.h
    include/my_time.h
    include/utils.h
    include/consts.h
    include/phone_number.h
    include/phone_numbers.h
    include/city_code.h
    include/city_name.h
    include/tariff.h
    include/automatic_telephone_station.h
    include/menu.h
    include/program.h
)

add_executable(lab7 ${SOURCES} ${HEADERS})