#pragma once

#include <iostream>

class Date {
    int day = 0;
    int month = 0;
    int year = 0;

    bool isLeapYear() const;
    int getDaysInMonth() const;

    static void showDateFormatException(const std::string& date,
                                        const std::exception& exc);

   public:
    Date() = default;
    Date(int day, int month, int year);

    void parse(const std::string& str);
    void show() const;
    bool isEmpty() const;
};