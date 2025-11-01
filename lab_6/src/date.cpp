#include "date.h"

#include <iomanip>
#include <iostream>

#include "consts.h"
#include "utils.h"

Date::Date(int in_day, int in_month, int in_year) : day(in_day), month(in_month), year(in_year) {}

bool Date::is_leap_year() const
{
    return (year % 4 == 0);
}

int Date::get_day_in_month() const
{
    if (month == 2 && is_leap_year())
    {
        return LEAP_FEBRUARY_DAYS;
    }

    return DAYS_IN_MONTH[month - 1];
}

void Date::show_sate_format_exception(const std::string &date, const std::exception &exc)
{
    std::cout << C_RED << "\nIncorrect date format: " << exc.what() << " | input: " << date
              << C_WHITE << std::endl;
}

void Date::parse(const std::string &str)
{
    try
    {
        if (str.size() != FORMAT_DATA_LEN)
        {
            throw std::invalid_argument("expected format dd.mm.yy (8 characters)");
        }

        if (str[2] != '.' || str[5] != '.')
        {
            throw std::invalid_argument("separator must be a dot at positions 3 and 6");
        }

        if (!is_digits(str, 0, 2) || !is_digits(str, 3, 2) || !is_digits(str, 6, 2))
        {
            throw std::invalid_argument("day, month and year must contain only digits");
        }

        int tmp_day = std::stoi(str.substr(0, 2));
        int tmp_month = std::stoi(str.substr(3, 2));
        int tmp_year = std::stoi(str.substr(6, 2));

        if (tmp_month < 1 || tmp_month > MONTH_COUNT)
        {
            throw std::invalid_argument("month out of range (01..12)");
        }

        Date tmp(tmp_day, tmp_month, tmp_year);

        if (tmp_day < 1 || tmp_day > tmp.get_day_in_month())
        {
            throw std::invalid_argument("day out of range for this month");
        }

        *this = tmp;
    }
    catch (const std::exception &exc)
    {
        show_sate_format_exception(str, exc);
    }
}

void Date::show() const
{
    std::cout << "\nThe date you entered: " << std::setfill('0') << std::setw(2) << day << '.'
              << std::setw(2) << month << '.' << std::setw(2) << year << std::endl;
}

bool Date::is_empty() const
{
    return (day == 0 || month == 0 || year == 0);
}