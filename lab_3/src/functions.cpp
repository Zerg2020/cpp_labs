#include "functions.h"

void print_info(const PassengerCarrier &carrier)
{
    std::cout <<"The distance = " << carrier.get_distance() << "km" << std::endl;
    std::cout << carrier.get_sound() << " The cost(in BYN) per distance travelled is " << carrier.calculate_cost() << std::endl;
    std::cout << carrier.get_sound() << " The time(in Hours) per distance travelled is " << carrier.calculate_time() << std::endl;
}
int get_number(const std::string &prompt, int min, int max)
{
    int value = 0;
    while (true)
    {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.good() && std::cin.peek() == '\n' && value >= min && value <= max)
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Incorrect input, try again! " << std::endl;
    }
}