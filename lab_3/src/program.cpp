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

    std::cout << kGreenColor << "\nYou have successfully added carrier!" << kWhiteColor << std::endl;
}

void Program::expand_carries() {
    if (size < 0) {
        size = 0;
    }

    if (size + 1 == cap) {
        cap *= 2;
        auto **newCarriers = new PassengerCarrier *[cap];

        for (int i = 0; i < size; i++) {
            newCarriers[i] = carriers[i];
        }

        delete[] carriers;

        carriers = newCarriers;
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
            std::cout << kRedColor << "\nError, you picked is an incorrect carrier menu option. Please try again."
                      << kWhiteColor << std::endl;
        }
    }
}

void Program::show_info() const {
    if (size == 0) {
        std::cout << kRedColor << "\nError, you have not added any carriers yet. Please use option 1 to add a carrier."
                  << kWhiteColor << std::endl;
        return;
    }

    std::cout << "\n\t\t\t\tINFO" << std::endl;

    for (int i = 0; i < size; i++) {
        print_info(*carriers[i]);
        std::cout << std::endl;
    }

    std::cout << kGreenColor << "You have successfully showed all info about carriers!" << kWhiteColor << std::endl;
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
            std::cout << kGreenColor << "\nYou have successfully exited the program." << kWhiteColor << std::endl;
            return;
        default:
            std::cout << kRedColor << "\nError, you picked is an incorrect menu option. Please try again."
                      << kWhiteColor << std::endl;
        }
    }
}