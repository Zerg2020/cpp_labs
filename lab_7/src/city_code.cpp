#include "city_code.h"

#include <iostream>

#include "consts.h"
#include "utils.h"

void CityCode::show_city_code_format_exception(const std::string &input_city_code,
                                               const std::exception &exc)
{
    std::cout << C_RED << "\nError: " << exc.what() << " | input: " << input_city_code << C_WHITE
              << std::endl;
}

void CityCode::parse(const std::string &input_city_code)
{
    try
    {
        if (input_city_code.length() != CITY_CODE_DIGITS_COUNTS)
        {
            throw std::invalid_argument("\nCity code must be 3 digits");
        }

        if (!is_digits(input_city_code))
        {
            throw std::invalid_argument("\nCity code must be numeric");
        }

        city_code = input_city_code;
    }
    catch (const std::invalid_argument &exc)
    {
        show_city_code_format_exception(input_city_code, exc);
    }
}

void CityCode::input()
{
    std::string input_city_code;

    while (true)
    {
        input_city_code = get_value<std::string>("\nEnter city code (3 digits): ");

        parse(input_city_code);

        if (!is_empty())
            return;
    }
}

bool CityCode::is_empty() const
{
    return city_code.empty();
}
