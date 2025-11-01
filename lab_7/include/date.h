#pragma once

#include <iomanip>
#include <iostream>

class Date
{
    int day = 0;
    int month = 0;
    int year = 0;

    bool is_leap_year() const;
    int get_days_in_month() const;

    static void show_date_format_exception(const std::string &date, const std::exception &exc);
    Date(int day, int month, int year);

  public:
    Date() = default;

    void parse(const std::string &date);
    void input();
    bool is_empty() const;

    friend std::ostream &operator<<(std::ostream &ostm, const Date &date)
    {
        ostm << std::setfill('0') << std::setw(2) << date.day << '.' << std::setw(2) << date.month
             << '.' << std::setw(2) << date.year;

        return ostm;
    }

    friend std::istream &operator>>(std::istream &istm, Date &date)
    {
        std::string token;

        if (std::getline(istm, token, '.'))
        {
            date.day = std::stoi(token);
        }

        if (std::getline(istm, token, '.'))
        {
            date.month = std::stoi(token);
        }

        if (std::getline(istm, token, ' '))
        {
            date.year = std::stoi(token);
        }

        return istm;
    }
};