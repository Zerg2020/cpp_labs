#include "city_name.h"

#include <fstream>

#include "consts.h"
#include "utils.h"

void CityName::show_city_format_exception(const std::string &input_city_name,
                                          const std::exception &exc)
{
    std::cout << C_RED << "\nIncorrect city name: " << exc.what() << " | input: " << input_city_name
              << C_WHITE << std::endl;
}

bool CityName::is_valid_city_name(const std::string_view &str)
{
    std::ifstream file_in;

    std::string file_content;

    file_in.open(FILE_WITH_CITY_NAMES);

    if (!file_in.is_open())
    {
        std::cout << C_RED << "\nError, could not open " << FILE_WITH_CITY_NAMES
                  << ". Please try again!" << C_WHITE << std::endl;
        return false;
    }

    while (file_in >> file_content)
    {
        if (str == file_content)
        {
            file_in.close();
            return true;
        }
    }

    file_in.close();

    return false;
}

void CityName::parse(const std::string &input_city_name)
{
    try
    {
        if (!is_valid_city_name(input_city_name))
        {
            throw std::invalid_argument("City not found in Belarus");
        }

        city_name = input_city_name;
    }
    catch (const std::invalid_argument &exc)
    {
        show_city_format_exception(input_city_name, exc);
    }
}

void CityName::input()
{
    std::string input_city_name;

    while (true)
    {
        input_city_name = get_value<std::string>("\nPlease enter the name of a Belarusian city: ");

        parse(input_city_name);

        if (!is_empty())
        {
            return;
        }
    }
}

bool CityName::is_empty() const
{
    return city_name.empty();
}
