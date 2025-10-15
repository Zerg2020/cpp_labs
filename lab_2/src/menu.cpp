#include "menu.h"
#include "array.h"
#include "consts.h"
#include "utils.h"
#include <iostream>

void show_constructors_menu() {
  std::cout << "\t\t\tCONSTRUCTORS MENU" << std::endl;
  std::cout << "1.Use default constructor." << std::endl;
  std::cout << "2.Use constructor with parameters." << std::endl;
  std::cout << "3.Exit." << std::endl;
}

void show_task_menu() {
  std::cout << "\n\t\t\t\tTASK" << std::endl;
  std::cout << "Create a class for working with one-dimensional arrays."
            << std::endl;
  std::cout << "Overload the ++ operator to increment array elements."
            << std::endl;
  std::cout << "Allocate memory for arrays dynamically." << std::endl;
  std::cout << "Provide a copy constructor." << std::endl;
  std::cout << "Define friend functions for input and output operations."
            << std::endl;

  std::cout << "\n\t\t\t\tMENU" << std::endl;
  std::cout << "1. Enter or re-enter array elements." << std::endl;
  std::cout << "2. Display the array." << std::endl;
  std::cout << "3. Increment array elements (++)." << std::endl;
  std::cout << "4. Exit the program." << std::endl;
}

void use_default_array_constructor(Array &arr) {
  Array tmp_arr;
  arr = tmp_arr;
  std::cout << C_GREEN
            << "The array object was successfully created using the default "
               "constructor!"
            << C_WHITE << std ::endl;
}

void use_parameterized_array_constructor(Array &arr) {
  int size = get_number("Please enter the array size: ", 1, MAX_INT);

  Array tmp_arr(size);
  arr = tmp_arr;

  std::cout << C_GREEN
            << "The array object was successfully created using the "
               "constructor with parameters!"
            << C_WHITE << std ::endl;
}

void show_array(const Array &arr) {
  if (arr.is_empty()) {
    std::cout << C_RED
              << "\nError, array has not been entered. Please use the "
                 "first or third option and try again!"
              << C_WHITE << std::endl;
    return;
  }
  show(arr, "Show array on the screen: ");
  std::cout << C_GREEN
            << "The array was successfully displayed on the screen using the "
               "friend function(show)!"
            << C_WHITE << std::endl;
}
void input_array(Array &arr) {
  //arr.input("Please enter or re-enter array elements.\n");
  input(arr, "Please enter or re-enter array elements.\n");

  std::cout << C_GREEN
            << "Array successfully entered using friend function(input)!"
            << C_WHITE << std::endl;
}

void increment_array(Array &arr) {
  if (arr.is_empty()) {
    std::cout << C_RED
              << "\nError, array has not been entered. Please use the "
                 "first or third option and try again!"
              << C_WHITE << std::endl;
    return;
  }

  arr++;

  std::cout << C_GREEN << "The array was successfully incremented!" << C_WHITE
            << std::endl;
}
void select_option(Array &array) {
  int opt;
  while (true) {
    opt = get_number("\nPlease select a menu option: ", 1, 4);

    switch (opt) {
    case 1:
      input_array(array);
      break;
    case 2:
      show_array(array);
      break;
    case 3:
      increment_array(array);
      break;
    case 4:
      std::cout << C_GREEN << "\nYou have successfully exited the program."
                << C_WHITE << std::endl;
      return;
    default:
      std::cout << C_RED
                << "\nError, you picked is an incorrect menu option. "
                   "Please try again."
                << C_WHITE << std::endl;
    }
  }
}
void menu() {
  Array array;
  while (true) {
    show_constructors_menu();
    int choose = get_number("Enter number of operation ", 1, 3);

    switch (choose) {
    case 1:
      use_default_array_constructor(array);
      show_task_menu();
      select_option(array);
      break;
    case 2:
      use_parameterized_array_constructor(array);
      show_task_menu();
      select_option(array);
      break;
    case 3:
      return;
    default:
      std::cout << C_RED
                << "\nError, you picked is an incorrect menu option. "
                   "Please try again."
                << C_WHITE << std::endl;
      break;
    }
  }
}