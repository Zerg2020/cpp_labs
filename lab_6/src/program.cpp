#include "program.h"

#include "menu.h"
#include "utils.h"

void Program::input_date()
{
    if (!date.is_empty())
    {
        std::cout << C_RED << "\nError, date is already full" << C_WHITE << std::endl;
        return;
    }

    std::string str_date;

    while (date.is_empty())
    {
        str_date = get_value<std::string>("\nPlease enter a date: ");
        date.parse(str_date);
    }

    std::cout << C_GREEN << "\nYou have successfully entered the date!" << C_WHITE << std::endl;
}

void Program::show_date() const
{
    if (date.is_empty())
    {
        std::cout << C_RED << "\nError, date is not entered, please use first option" << C_WHITE
                  << std::endl;
        return;
    }

    date.show();

    std::cout << C_GREEN << "\nYou have successfully displayed the string on the screen!"
              << C_WHITE;
}

void Program::run()
{
    int opt = 0;

    system("clear");
    show_task_menu();

    while (true)
    {
        opt = get_value<int>("\nPlease enter a menu option: ");

        switch (opt)
        {
        case 1:
            input_date();
            break;
        case 2:
            show_date();
            break;
        case 3:
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