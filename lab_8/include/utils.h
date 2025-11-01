#pragma once

#include "array.h"
#include "consts.h"

template <typename T>
T get_value()
{
    T value;
    int sym = 0;

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

void choice_array_type();

template <typename T>
size_t get_valid_index(const Array<T> &arr)
{
    while (true)
    {
        std::cout << "\nPlease enter the index at which to add the value: ";

        if (auto index = get_value<size_t>(); index <= arr.size())
        {
            return index;
        }

        std::cout << C_RED << "\nInvalid index, please try again!" << C_WHITE << std::endl;
    }
}