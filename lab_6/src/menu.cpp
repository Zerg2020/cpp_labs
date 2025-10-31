#include "menu.h"

#include <iostream>

void showTaskMenu() {
    std::cout << "\t\t\t\tTASK" << std::endl;
    std::cout << "Create a program to check input format of a date."
              << std::endl;
    std::cout << "Implement methods to:" << std::endl;
    std::cout << "- Parse a date string in format dd.mm.yy." << std::endl;
    std::cout << "- Validate correctness of the format." << std::endl;
    std::cout << "- Throw exceptions if format is incorrect." << std::endl;
    std::cout << "- Show the parsed date in normalized format." << std::endl;

    std::cout << "\n\t\t\t\tMENU" << std::endl;
    std::cout << "1. Enter a date." << std::endl;
    std::cout << "2. Show parsed date." << std::endl;
    std::cout << "3. Exit program." << std::endl;
}