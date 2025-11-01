#include "utils.h"

#include "menus.h"
#include "program.h"

void choice_array_type()
{
    int choice = 0;

    system("clear");
    show_task();
    show_array_type_menu();

    while (true)
    {
        std::cout << "\nPlease choose a binary tree type: ";

        choice = get_value<int>();

        switch (choice)
        {
        case 1:
        {
            Program<int> program;
            program.run();
            return;
        }
        case 2:
        {
            Program<long> program;
            program.run();
            return;
        }
        case 3:
        {
            Program<float> program;
            program.run();
            return;
        }
        case 4:
        {
            Program<double> program;
            program.run();
            return;
        }
        case 5:
        {
            Program<char> program;
            program.run();
            return;
        }
        case 6:
        {
            Program<std::string> program;
            program.run();
            return;
        }
        default:
            std::cout << C_RED << "\nError, invalid choice. Please try again." << C_WHITE
                      << std::endl;
        }
    }
}