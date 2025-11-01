#pragma once

#include <iostream>

class Date
{
    int day = 0;
    int month = 0;
    int year = 0;

    bool is_leap_year() const;
    int get_day_in_month() const;

    static void show_sate_format_exception(const std::string &date, const std::exception &exc);

  public:
    Date() = default;
    Date(int day, int month, int year);

    void parse(const std::string &str);
    void show() const;
    bool is_empty() const;
};