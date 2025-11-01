#include "program.h"

#include <fstream>

#include "consts.h"
#include "menu.h"
#include "utils.h"

Program::Program()
{
    std::ofstream ofs(FILE_WITH_DATA, std::ios::trunc);
}

void Program::add_record()
{
    ats.add();

    std::cout << C_GREEN << "\nYou successfully added the conversation!" << C_WHITE << std::endl;
}

void Program::show_all_records() const
{
    if (ats.is_empty())
    {
        std::cout << C_RED
                  << "\nError: ATS is empty! Please add a record first (use "
                     "option 1)."
                  << C_WHITE << std::endl;
        return;
    }

    ATS::show();

    std::cout << C_GREEN << "\nYou successfully printed full info about ATS on the screen!"
              << C_WHITE << std::endl;
}

void Program::display_phone_numbers_by_tariff() const
{
    if (ats.is_empty())
    {
        std::cout << C_RED
                  << "\nError: ATS is empty! Please add a record first (use "
                     "option 1)."
                  << C_WHITE << std::endl;
        return;
    }

    MobileTariff tariff;

    tariff.input();

    PhoneNumbers storage = ATS::find_phone_numbers_by_tariff(tariff);

    if (storage.is_empty())
    {
        std::cout << C_RED << "\nPhone number with this tariff was not found." << C_WHITE
                  << std::endl;
        return;
    }

    std::cout << "\nPhone numbers with this tariff: ";
    storage.show();

    std::cout << C_GREEN << "\nYou successfully founded phone numbers by tariff!" << C_WHITE
              << std::endl;
}

void Program::run()
{
    system("clear");

    show_task_menu();

    int opt = 0;

    while (true)
    {
        opt = get_value<int>("\nPlease enter menu option: ");

        switch (opt)
        {
        case 1:
            add_record();
            break;
        case 2:
            show_all_records();
            break;
        case 3:
            display_phone_numbers_by_tariff();
            break;
        case 4:
            std::cout << C_GREEN << "\nYou have successfully exited the program." << C_WHITE
                      << std::endl;
            return;
        default:
            std::cout << C_RED
                      << "\nError, you picked is an incorrect menu option. "
                         "Please try again."
                      << C_WHITE << std::endl;
        }
    }
}