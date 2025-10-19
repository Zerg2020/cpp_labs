#pragma once
#include "const.h"
#include <iostream>
#include <limits>

int get_int(const std::string &msg, int min, int max);

template <class T>
T get_value(const std::string &prompt)
{
  T value;
  while (true)
  {
    std::cout << C_YELLOW << prompt << C_WHITE;
    std::cin >> value;

    if (std::cin.good() && std::cin.peek() == '\n')
    {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return value;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << C_RED << "Incorrect input, try again! " << C_WHITE << std::endl;
  }
}

template <class T>
int swap_element(T *array, int ind_first, int ind_secound)
{
  if (ind_first == ind_secound)
    return 0;

  T temp = array[ind_first];
  array[ind_first] = array[ind_secound];
  array[ind_secound] = temp;

  return 0;
}


template <class T>
T *get_array(const std::string &msg, int &lenght)
{
  lenght = get_int("Enter lenght array ", 0, MAX_INT);
  std::cout << msg << std::endl;

  auto *array = new T[lenght];
  for(int i = 0;i < lenght;i++)
  {
    std::string msg = "Enter element [" + std::to_string(i+1) + "] ";
    array[i] = get_value <T>(msg);
  }
  return array;
}

template <class T>
void print_arr(T *arr, int length)
{
  std::cout << "\nArray\n";
  for (int i = 0; i < length; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";
}

template <typename T>
void process_array()
{
  int length = 0;
  T *arr = get_array<T>("", length);

  while (true)
  {
    std::cout << "\n1.Show array\n2.Swap element\n3.Exit" << std::endl;
    int choose = get_int("Enter number of operation ", 1, 3);
    switch (choose)
    {
    case 1:
    {
      print_arr(arr, length);
      break;
    }
    case 2:
    {
      int index_first = get_int("Enter index first elment  ", 0, length - 1);
      int index_secound = get_int("Enter index secound elment  ", 0, length - 1);
      if (swap_element(arr, index_first, index_secound))
        std::cout << C_RED << "The operation was unsuccessful" << C_WHITE;
      else
        std::cout << C_GREN << "The operation was completed successfully\n" << C_WHITE;
      break;
    }
    case 3:
    {
      delete[] arr;
      return;
    }
    default:
      break;
    }
  }
}

