#include "utils.h"

#include "menus.h"
#include "program.h"

void choiceArrayType() {
    int choice = 0;

    system("clear");
    showTask();
    showArrayTypeMenu();

    while (true) {
        std::cout << "\nPlease choose a binary tree type: ";

        choice = getValue<int>();

        switch (choice) {
            case 1: {
                Program<int> program;
                program.run();
                return;
            }
            case 2: {
                Program<long> program;
                program.run();
                return;
            }
            case 3: {
                Program<float> program;
                program.run();
                return;
            }
            case 4: {
                Program<double> program;
                program.run();
                return;
            }
            case 5: {
                Program<char> program;
                program.run();
                return;
            }
            case 6: {
                Program<std::string> program;
                program.run();
                return;
            }
            default:
                std::cout << kRedColor
                          << "\nError, invalid choice. Please try again."
                          << kWhiteColor << std::endl;
        }
    }
}