#include "menu.h"

#include <iostream>

void showTaskMenu() {
    std::cout << "\n\t\t\t\tTASK" << std::endl;
    std::cout << "Task: Implement the class 'ATS' with the following fields:"
              << std::endl;
    std::cout << "  - Call date" << std::endl;
    std::cout << "  - City code and name" << std::endl;
    std::cout << "  - Call time" << std::endl;
    std::cout << "  - Tariff" << std::endl;
    std::cout << "  - Subscriber phone number" << std::endl;
    std::cout << "Overload the << and >> operators for file input/output,"
              << std::endl;
    std::cout
        << "and implement a method to return phone numbers by a given tariff.\n"
        << std::endl;

    std::cout << "\n\t\t\t\tMENU" << std::endl;
    std::cout << "1. Add a new record." << std::endl;
    std::cout << "2. Show all records." << std::endl;
    std::cout << "3. Find phone numbers by tariff." << std::endl;
    std::cout << "4. Exit program." << std::endl;
}
