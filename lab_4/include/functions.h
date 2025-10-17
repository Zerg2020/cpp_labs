#pragma once

#include "cargo_carrier.h"
#include "consts.h"

template <typename T>

T get_number(const std::string &msg, T min, T max) {
    T num;
    int sym = 0;

    std::cout << msg;
    std::cout << "(" << min << " <= input <= " << max << "): ";

    while (true) {
        if (std::cin.peek() != '\n' && std::cin.peek() != ' ' && (std::cin >> num).good()) {
            sym = std::cin.peek();
            if (((char)sym == '\n' || (char)sym == EOF) && num >= min && num <= max) {
                std::cin.get();
                return num;
            }
        }

        std::cin.clear();
        while (std::cin.get() != '\n' && !std::cin.eof())
            ;
        std::cout << C_RED << "\nError, invalid input. Please try again: " << C_WHITE;
    }
}

std::string get_string(const std::string &msg);

void print_info(const CargoCarrier &carrier);