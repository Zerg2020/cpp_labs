#include "tariff.h"

#include <fstream>
#include <iostream>

#include "consts.h"
#include "utils.h"

void MobileTariff::show_tariff_format_exception(const std::string &input_mobile_tariff,
                                                const std::exception &exc)
{
    std::cout << C_RED << "\nIncorrect tariff format: " << exc.what()
              << " | input: " << input_mobile_tariff << C_WHITE << std::endl;
}

bool MobileTariff::is_valid_tariff(const std::string_view &input_mobile_tariff)
{
    std::ifstream file_in;

    std::string file_content;

    file_in.open(FILE_WITH_TARIFFS);

    if (!file_in.is_open())
    {
        std::cout << C_RED << "\nError, could not open " << FILE_WITH_TARIFFS
                  << ". Please try again!" << C_WHITE << std::endl;
        return false;
    }

    while (file_in >> file_content)
    {
        if (file_content == input_mobile_tariff)
        {
            file_in.close();
            return true;
        }
    }

    file_in.close();
    return false;
}

void MobileTariff::parse(const std::string &input_mobile_tariff)
{
    try
    {
        if (!is_valid_tariff(input_mobile_tariff))
        {
            throw std::invalid_argument("Unknown Belarusian mobile tariff");
        }

        mobile_tariff = input_mobile_tariff;
    }
    catch (const std::invalid_argument &exc)
    {
        show_tariff_format_exception(input_mobile_tariff, exc);
    }
}

void MobileTariff::input()
{
    std::string input_mobile_tariff;

    while (true)
    {
        input_mobile_tariff = get_value<std::string>("\nEnter Belarusian tariff name: ");

        parse(input_mobile_tariff);

        if (!is_empty())
        {
            return;
        }
    }
}

bool MobileTariff::is_empty() const
{
    return mobile_tariff.empty();
}