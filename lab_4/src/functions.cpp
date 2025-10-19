#include "functions.h"

int get_number(const std::string &msg, int min, int max)
{
    int num;
    int sym = 0;

    std::cout << msg;
    std::cout << "(" << min << " <= input <= " << max << "): ";

    while (true)
    {
        if (std::cin.peek() != '\n' && std::cin.peek() != ' ' && (std::cin >> num).good())
        {
            sym = std::cin.peek();
            if (((char)sym == '\n' || (char)sym == EOF) && num >= min && num <= max)
            {
                std::cin.get();
                return num;
            }
        }

        std::cin.clear();
        while (std::cin.get() != '\n' && !std::cin.eof())
            ;
        std::cout << C_RED << "\nError, invalid input. Please try again: " << C_WHITE;
    }
}
std::string get_string(const std::string &msg)
{
    std::string str;

    std::cout << msg;
    while (true)
    {
        std::getline(std::cin, str);

        if (!str.empty())
        {
            return str;
        }

        std::cout << C_RED << "\nError, the string cannot be empty. Please try again: " << C_WHITE;
    }
}

void print_info(const CargoCarrier &carrier)
{
    std::cout << carrier.get_sound() << " The cost(in BYN) per distance travelled to "
              << carrier.get_city() + " is " << carrier.calculate_cost() << std::endl;
    std::cout << carrier.get_sound() << " The time(in Hours) per distance travelled to "
              << carrier.get_city() + " is " << carrier.calculate_time() << std::endl;
}