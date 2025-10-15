#include "utils.h"
#include "consts.h"

int get_number(const std::string &msg, int min, int max) {
    int num = 0;
    int sym = 0;

    std::cout << msg;

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
        while (std::cin.get() != '\n' && !std::cin.eof());
        std::cout << C_RED << "\nError, invalid input. Please try again: "
                  << C_WHITE;
    }
}
