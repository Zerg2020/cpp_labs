#include "functions.h"

std::string get_string(const std::string &msg) {
    std::string str;

    std::cout << msg;
    while (true) {
        std::getline(std::cin, str);

        if (!str.empty()) { // строка не пустая
            return str;
        }

        std::cout << C_RED << "\nError, the string cannot be empty. Please try again: " << C_WHITE;
    }
}

void print_info(const CargoCarrier &carrier) {
    std::cout << carrier.get_sound() << " The cost(in BYN) per distance travelled to " << carrier.get_city() + " is "
              << carrier.calculate_cost() << std::endl;
    std::cout << carrier.get_sound() << " The time(in Hours) per distance travelled to " << carrier.get_city() + " is "
              << carrier.calculate_time() << std::endl;
}