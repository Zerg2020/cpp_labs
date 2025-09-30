#include "menus.h"
#include <iostream>

void show_task_menu() {
    std::cout << "\n\t\t\t\tTASK" << std::endl;
    std::cout << "Create a base class 'PassengerCarrier' and derived classes 'Airplane', 'Train', 'Car'." << std::endl;
    std::cout << "Define methods to calculate time and cost of travel." << std::endl;

    std::cout << "\n\t\t\t\tMENU" << std::endl;
    std::cout << "1. Add a carrier." << std::endl;
    std::cout << "2. Show information (cost and time for a given distance)." << std::endl;
    std::cout << "3. Exit the program." << std::endl;
}

void show_carriers_menu() {
    std::cout << "\n\t\t\t\tSELECT CARRIER TYPE" << std::endl;
    std::cout << "1. Car" << std::endl;
    std::cout << "2. Train" << std::endl;
    std::cout << "3. Airplane" << std::endl;
}