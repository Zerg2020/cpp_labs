#pragma once

#include "algorithm.h"
#include "array.h"
#include "utils.h"

template <typename T>
class Program
{
    Array<T> arr;
    Algorithm<T> algorithm;

    void create_array();
    void add_array_element();
    void remove_array_element();
    void show_array();
    void sort_array();
    void search_array_element();
    void clear_array();

  public:
    Program();

    void run();
};

template <typename T>
Program<T>::Program()
{
    std::cout << C_GREEN << "\nYou successfully chose a type of array!" << C_WHITE << std::endl;
}

template <typename T>
void Program<T>::create_array()
{
    if (!arr.empty())
    {
        std::cout << C_RED << "\nError, array is also entered!" << C_WHITE << std::endl;
        return;
    }

    std::cout << "\nEnter initial size of array: ";
    auto size = get_value<size_t>();

    arr = Array<T>(size);

    for (size_t i = 0; i < size; i++)
    {
        std::cout << "\nEnter element " << i + 1 << ">> ";
        arr[i] = get_value<T>();
    }

    std::cout << C_GREEN << "\nArray created successfully!" << C_WHITE << std::endl;
}

template <typename T>
void Program<T>::add_array_element()
{
    if (arr.empty())
    {
        std::cout << C_RED << "\nError, array is empty." << C_WHITE << std::endl;
        return;
    }

    std::cout << "\nPlease enter a value to add to the array: ";
    auto value = get_value<T>();

    int opt = 0;
    show_add_menu();

    while (true)
    {
        std::cout << "\nPlease enter the add menu option: ";
        opt = get_value<int>();

        switch (opt)
        {
        case 1:
            arr.push_front(value);

            std::cout << C_GREEN
                      << "\nYou successfully added an element to the "
                         "beginning of the array!"
                      << C_WHITE << std::endl;
            return;
        case 2:
            arr.push_back(value);

            std::cout << C_GREEN
                      << "\nYou successfully added an element to the end "
                         "of the array!"
                      << C_WHITE << std::endl;
            return;
        case 3:
        {
            size_t index = get_valid_index(arr);

            arr.insert(arr.begin() + index, value);

            std::cout << C_GREEN << "\nYou successfully inserted an element into the array!"
                      << C_WHITE << std::endl;
            return;
        }
        default:
            std::cout << C_RED << "\nWrong choice, please try again!" << C_WHITE << std::endl;
        }
    }
}

template <typename T>
void Program<T>::remove_array_element()
{
    if (arr.empty())
    {
        std::cout << C_RED << "\nError, array is empty." << C_WHITE << std::endl;
        return;
    }

    int opt = 0;
    show_remove_menu();

    while (true)
    {
        std::cout << "\nPlease enter the remove menu option: ";
        opt = get_value<int>();

        switch (opt)
        {
        case 1:
            arr.pop_front();

            std::cout << C_GREEN
                      << "\nYou successfully removed the first element of "
                         "the array!"
                      << C_WHITE << std::endl;
            return;
        case 2:
            arr.pop_back();

            std::cout << C_GREEN
                      << "\nYou successfully removed the last element of "
                         "the array!"
                      << C_WHITE << std::endl;
            return;
        case 3:
        {
            size_t index = get_valid_index(arr);

            arr.erase(arr.begin() + index);

            std::cout << C_GREEN << "\nYou successfully removed an element from the array!"
                      << C_WHITE << std::endl;
            return;
        }
        default:
            std::cout << C_RED << "\nWrong choice, please try again!" << C_WHITE << std::endl;
        }
    }
}

template <typename T>
void Program<T>::show_array()
{
    if (arr.empty())
    {
        std::cout << C_RED << "\nError, array is empty." << C_WHITE << std::endl;
        return;
    }

    std::cout << "\nArray elements: ";
    for (auto it = arr.begin(); it != arr.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << C_GREEN << "\nYou have successfully displayed the array elements!" << C_WHITE
              << std::endl;
}

template <typename T>
void Program<T>::sort_array()
{
    if (arr.empty())
    {
        std::cout << C_RED << "\nError, array is empty." << C_WHITE << std::endl;
        return;
    }

    algorithm.sort(arr);

    std::cout << C_GREEN << "\nYou successfully sorted the array!" << C_WHITE << std::endl;
}

template <typename T>
void Program<T>::search_array_element()
{
    if (arr.empty())
    {
        std::cout << C_RED << "\nError, array is empty." << C_WHITE << std::endl;
        return;
    }

    std::cout << "\nPlease enter value to search: ";
    auto value = get_value<T>();

    Array tmp = arr;
    algorithm.sort(tmp);

    if (algorithm.find(tmp, value))
    {
        std::cout << C_GREEN << "\nThe element was found successfully!" << C_WHITE << std::endl;
    }
    else
    {
        std::cout << C_RED << "\nValue not found." << C_WHITE << std::endl;
    }
}

template <typename T>
void Program<T>::clear_array()
{
    if (arr.empty())
    {
        std::cout << C_RED << "Error, array is empty.\n" << C_WHITE;
        return;
    }

    arr.clear();

    std::cout << C_GREEN << "\nYou successfully cleared the array!" << C_WHITE << std::endl;
}

template <typename T>
void Program<T>::run()
{
    show_menu();

    int opt = 0;

    while (true)
    {
        std::cout << "\nPlease enter menu option: ";

        opt = get_value<int>();

        switch (opt)
        {
        case 1:
            create_array();
            break;
        case 2:
            add_array_element();
            break;
        case 3:
            remove_array_element();
            break;
        case 4:
            show_array();
            break;
        case 5:
            sort_array();
            break;
        case 6:
            search_array_element();
            break;
        case 7:
            clear_array();
            break;
        case 8:
            std::cout << C_GREEN << "\nYou have successfully exited the program." << C_WHITE
                      << std::endl;
            return;
        default:
            std::cout << C_RED
                      << "\nError, you picked is an incorrect menu option. "
                         "Please try again."
                      << C_WHITE << std::endl;
        }
    }
}