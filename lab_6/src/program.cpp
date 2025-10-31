#include "program.h"

#include "menu.h"
#include "utils.h"

void Program::inputDate() {
    if (!date.isEmpty()) {
        std::cout << kRedColor << "\nError, date is already full" << kWhiteColor
                  << std::endl;
        return;
    }

    std::string str_date;

    while (date.isEmpty()) {
        str_date = getValue<std::string>("\nPlease enter a date: ");
        date.parse(str_date);
    }

    std::cout << kGreenColor << "\nYou have successfully entered the date!"
              << kWhiteColor << std::endl;
}

void Program::showDate() const {
    if (date.isEmpty()) {
        std::cout << kRedColor
                  << "\nError, date is not entered, please use first option"
                  << kWhiteColor << std::endl;
        return;
    }

    date.show();

    std::cout << kGreenColor
              << "\nYou have successfully displayed the string on the screen!"
              << kWhiteColor;
}

void Program::run() {
    int opt = 0;

    system("clear");
    showTaskMenu();

    while (true) {
        opt = getValue<int>("\nPlease enter a menu option: ");

        switch (opt) {
            case 1:
                inputDate();
                break;
            case 2:
                showDate();
                break;
            case 3:
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