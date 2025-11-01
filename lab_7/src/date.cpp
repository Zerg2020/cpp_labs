#include "date.h"

#include <iomanip>
#include <iostream>

#include "consts.h"
#include "utils.h"

Date::Date(int input_day, int input_month, int input_year) :
    day(input_day), month(input_month), year(input_year)
{
}

bool Date::is_leap_year() const
{
    return (year % 4 == 0);
}

int Date::get_days_in_month() const
{
    if (month == 2 && is_leap_year())
    {
        return LEAP_FEBRUARY_DAYS;
    }

    return DAYS_IN_MONTH[month - 1];
}

void Date::show_date_format_exception(const std::string &date, const std::exception &exc)
{
    std::cout << C_RED << "\nIncorrect date format: " << exc.what() << " | input: " << date
              << C_WHITE << std::endl;
}

void Date::parse(const std::string &date)
{
    try
    {
        if (date.length() != FORMAT_DETE_LEN)
        {
            throw std::invalid_argument("expected format dd.mm.yy (8 characters)");
        }

        if (date[2] != '.' || date[5] != '.')
        {
            throw std::invalid_argument("separator must be a dot at positions 3 and 6");
        }

        if (!is_digits(date, 0, 2) || !is_digits(date, 3, 2) || !is_digits(date, 6, 2))
        {
            throw std::invalid_argument("day, month and year must contain only digits");
        }

        int tmp_day = std::stoi(date.substr(0, 2));
        int tmp_month = std::stoi(date.substr(3, 2));
        int tmp_year = std::stoi(date.substr(6, 2));

        if (tmp_month < 1 || tmp_month > MONTH_COUNT)
        {
            throw std::invalid_argument("month out of range (01..12)");
        }

        Date tmp(tmp_day, tmp_month, tmp_year);

        if (tmp_day < 1 || tmp_day > tmp.get_days_in_month())
        {
            throw std::invalid_argument("day out of range for this month");
        }

        *this = tmp;
    }
    catch (const std::invalid_argument &exc)
    {
        show_date_format_exception(date, exc);
    }
    catch (const std::out_of_range &exc)
    {
        show_date_format_exception(date, exc);
    }
}

void Date::input()
{
    std::string input_date;

    while (true)
    {
        input_date = get_value<std::string>("\nPlease enter the date(DD.MM.YY): ");

        parse(input_date);
        if (!is_empty())
        {
            return;
        }
    }
}

bool Date::is_empty() const
{
    return (day == 0 || month == 0 || year == 0);
}
