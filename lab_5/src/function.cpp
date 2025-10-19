#include "function.h"

int get_int(const std::string &prompt = "Enter a single integer: ", int min = 0, int max = 0)
{
    int value = 0;
    while (true)
    {
        std::cout << C_YELLOW << prompt << C_WHITE;
        std::cin >> value;

        if (std::cin.good() && std::cin.peek() == '\n' && value >= min && value <= max)
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << C_RED << "Incorrect input, try again! " << C_WHITE << std::endl;
    }
}