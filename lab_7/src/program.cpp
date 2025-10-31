#include "program.h"

#include <fstream>

#include "consts.h"
#include "menu.h"
#include "utils.h"

Program::Program() { std::ofstream ofs(kFileWithData, std::ios::trunc); }

void Program::addRecord() {
    ats.add();

    std::cout << kGreenColor << "\nYou successfully added the conversation!"
              << kWhiteColor << std::endl;
}

void Program::showAllRecords() const {
    if (ats.isEmpty()) {
        std::cout << kRedColor
                  << "\nError: ATS is empty! Please add a record first (use "
                     "option 1)."
                  << kWhiteColor << std::endl;
        return;
    }

    ATS::show();

    std::cout << kGreenColor
              << "\nYou successfully printed full info about ATS on the screen!"
              << kWhiteColor << std::endl;
}

void Program::displayPhoneNumbersByTariff() const {
    if (ats.isEmpty()) {
        std::cout << kRedColor
                  << "\nError: ATS is empty! Please add a record first (use "
                     "option 1)."
                  << kWhiteColor << std::endl;
        return;
    }

    MobileTariff tariff;

    tariff.input();

    PhoneNumbers storage = ATS::findPhoneNumbersByTariff(tariff);

    if (storage.isEmpty()) {
        std::cout << kRedColor
                  << "\nPhone number with this tariff was not found."
                  << kWhiteColor << std::endl;
        return;
    }

    std::cout << "\nPhone numbers with this tariff: ";
    storage.show();

    std::cout << kGreenColor
              << "\nYou successfully founded phone numbers by tariff!"
              << kWhiteColor << std::endl;
}

void Program::run() {
    system("clear");

    showTaskMenu();

    int opt = 0;

    while (true) {
        opt = getValue<int>("\nPlease enter menu option: ");

        switch (opt) {
            case 1:
                addRecord();
                break;
            case 2:
                showAllRecords();
                break;
            case 3:
                displayPhoneNumbersByTariff();
                break;
            case 4:
                std::cout << kGreenColor
                          << "\nYou have successfully exited the program."
                          << kWhiteColor << std::endl;
                return;
            default:
                std::cout << kRedColor
                          << "\nError, you picked is an incorrect menu option. "
                             "Please try again."
                          << kWhiteColor << std::endl;
        }
    }
}