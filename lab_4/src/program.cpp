#include "program.h"
#include "airplane.h"
#include "car.h"
#include "consts.h"
#include "menus.h"
#include "train.h"
#include "utils.h"

Program::Program() = default;

void Program::add_carrier() {
    expand_carries();

    choose_carrier();

    std::cout << C_GREEN << "\nYou have successfully added carrier!" << C_WHITE << std::endl;
}

void Program::expand_carries() {
    if (size < 0) {
        size = 0;
    }

    if (size + 1 == cap) {
        cap *= 2;
        auto **new_carriers = new CargoCarrier *[cap];

        for (int i = 0; i < size; i++) {
            new_carriers[i] = carriers[i];
        }

        delete[] carriers;

        carriers = new_carriers;
    }

    size++;
}

void Program::choose_carrier() {
    int opt = 0;

    show_carriers_menu();

    while (true) {
        opt = get_number("\nPlease enter carriers menu option ", 1, 3);

        switch (opt) {
        case 1:
            carriers[size - 1] = new Car;
            return;
        case 2:
            carriers[size - 1] = new Train;
            return;
        case 3:
            carriers[size - 1] = new Airplane;
            return;
        default:
            std::cout << C_RED << "\nError, you picked is an incorrect carrier menu option. Please try again."
                      << C_WHITE << std::endl;
        }
    }
}

void Program::show_info() const {
    if (size == 0) {
        std::cout << C_RED << "\nError, you have not added any carriers yet. Please use option 1 to add a carrier."
                  << C_WHITE << std::endl;
        return;
    }

    std::cout << "\n\t\t\t\tINFO" << std::endl;

    for (int i = 0; i < size; i++) {
        print_info(*carriers[i]);
        std::cout << std::endl;
    }

    std::cout << C_GREEN << "You have successfully showed all info about carriers!" << C_WHITE << std::endl;
}

void Program::remove_carriers() {
    for (int i = 0; i < size; i++) {
        delete carriers[i];
    }

    delete[] carriers;
    carriers = nullptr;
    size = 0;
    cap = 0;
}

void Program::run() {
    int opt = 0;

    system("clear");
    show_task_menu();

    while (true) {
        opt = get_number("\nPlease enter menu option ", 1, 3);

        switch (opt) {
        case 1:
            add_carrier();
            break;
        case 2:
            show_info();
            break;
        case 3:
            remove_carriers();
            std::cout << C_GREEN << "\nYou have successfully exited the program." << C_WHITE << std::endl;
            return;
        default:
            std::cout << C_RED << "\nError, you picked is an incorrect menu option. Please try again."
                      << C_WHITE << std::endl;
        }
    }
}