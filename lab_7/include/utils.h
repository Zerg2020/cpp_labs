#pragma once

#include <iostream>

#include "consts.h"

template <typename T>

T get_value(const std::string &msg)
{
    T value;
    int sym = 0;

    std::cout << msg;

    while (true)
    {
        if (std::cin.peek() != '\n' && std::cin.peek() != ' ' && (std::cin >> value).good())
        {
            sym = std::cin.peek();
            if ((char)sym == '\n' || (char)sym == EOF)
            {
                std::cin.get();
                return value;
            }
        }

        std::cin.clear();
        while (std::cin.get() != '\n' && !std::cin.eof())
            ;
        std::cout << C_RED << "\nError, invalid input. Please try again: " << C_WHITE;
    }
}

template <typename T>
bool is_valid_file_open(T &file, const std::string &file_name)
{
    if (!file.is_open())
    {
        std::cerr << "\nError, could not open " << file_name << "\n";
        return false;
    }
    return true;
}

bool is_digits(const std::string &str, int pos, int len);
bool is_digits(const std::string_view &str);
