#include "menu.h"
#include "array.h"
#include "utils.h"
#include "consts.h"
#include <iostream>

void showConstructorsMenu() {
    std::cout << "\t\t\tCONSTRUCTORS MENU" << std::endl;
    std::cout << "1.Use default constructor." << std::endl;
    std::cout << "2.Use constructor with parameters." << std::endl;
    std::cout << "3.Exit." << std::endl;
}

void showTaskMenu() {
    std::cout << "\n\t\t\t\tTASK" << std::endl;
    std::cout << "Create a class for working with one-dimensional arrays." << std::endl;
    std::cout << "Overload the ++ operator to increment array elements." << std::endl;
    std::cout << "Allocate memory for arrays dynamically." << std::endl;
    std::cout << "Provide a copy constructor." << std::endl;
    std::cout << "Define friend functions for input and output operations." << std::endl;

    std::cout << "\n\t\t\t\tMENU" << std::endl;
    std::cout << "1. Enter or re-enter array elements." << std::endl;
    std::cout << "2. Display the array." << std::endl;
    std::cout << "3. Increment array elements (++)." << std::endl;
    std::cout << "4. Exit the program." << std::endl;
}

void useDefaultArrayConstructor(Array &arr) {
    Array tmp_arr;
    arr = tmp_arr;
    std::cout << kGreenColor
              << "The array object was successfully created using the default "
                 "constructor!"
              << kWhiteColor << std ::endl;
}

void useParameterizedArrayConstructor(Array &arr) {
    int size = getNumber("Please enter the array size: ", 1, kMaxInt);

    Array tmp_arr(size);
    arr = tmp_arr;

    std::cout << kGreenColor
              << "The array object was successfully created using the "
                 "constructor with parameters!"
              << kWhiteColor << std ::endl;
}

void showArray(const Array &arr){
    if (arr.isEmpty()) {
        std::cout << kRedColor
                  << "\nError, array has not been entered. Please use the "
                     "first or third option and try again!"
                  << kWhiteColor << std::endl;
        return;
    }
    show(arr, "Show array on the screen: ");
    std::cout << kGreenColor
              << "The array was successfully displayed on the screen using the "
                 "friend function(show)!"
              << kWhiteColor << std::endl;
}
void inputArray(Array &arr) {
    input(arr, "Please enter or re-enter array elements.\n");

    std::cout << kGreenColor
              << "Array successfully entered using friend function(input)!"
              << kWhiteColor << std::endl;
}

void incrementArray(Array & arr) {
    if (arr.isEmpty()) {
        std::cout << kRedColor
                  << "\nError, array has not been entered. Please use the "
                     "first or third option and try again!"
                  << kWhiteColor << std::endl;
        return;
    }

    arr++;

    std::cout << kGreenColor << "The array was successfully incremented!"
              << kWhiteColor << std::endl;
}
void selectOption(Array &array){
    int opt;
    while (true) {
        opt = getNumber("\nPlease select a menu option: ", 1, 4);

        switch (opt) {
            case 1:
                inputArray(array);
                break;
            case 2:
                showArray(array);
                break;
            case 3:
                incrementArray(array);
                break;
            case 4:
                std::cout << kGreenColor
                          << "\nYou have successfully exited the program."
                          << kWhiteColor << std::endl;
                return;
            default:
                std::cout << kRedColor
                          << "\nError, you picked is an incorrect menu option. "
                             "Please try again."
                          << kWhiteColor << std::endl;
        }
    }
}
void menu(){
    Array array;
    while(true)
    {
        showConstructorsMenu();
        int choose = getNumber("Enter number of operation ",1,3);

        switch (choose)
        {
        case 1:
            useDefaultArrayConstructor(array);
            showTaskMenu();
            selectOption(array);
            break;
        case 2:
            useParameterizedArrayConstructor(array);
            showTaskMenu();
            selectOption(array);
            break;
        case 3:
            return;
        default:
         std::cout << kRedColor
                          << "\nError, you picked is an incorrect menu option. "
                             "Please try again."
                          << kWhiteColor << std::endl;
            break;
        }

    }
}