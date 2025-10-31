#pragma once

#include <iostream>

#include "consts.h"

template <typename T>

T getValue(const std::string& msg) {
    T value;
    int sym = 0;

    std::cout << msg;

    while (true) {
        if (std::cin.peek() != '\n' && std::cin.peek() != ' ' &&
            (std::cin >> value).good()) {
            sym = std::cin.peek();
            if ((char)sym == '\n' || (char)sym == EOF) {
                std::cin.get();
                return value;
            }
        }

        std::cin.clear();
        while (std::cin.get() != '\n' && !std::cin.eof());
        std::cout << kRedColor << "\nError, invalid input. Please try again: "
                  << kWhiteColor;
    }
}

bool isDigits(std::string str, int pos, int len);