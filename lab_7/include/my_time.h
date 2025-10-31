#pragma once

#include <iomanip>
#include <iostream>

class Time {
    int hour = 0;
    int minute = 0;
    int second = 0;

    static void showTimeFormatException(const std::string& time,
                                        const std::exception& exc);
    Time(int inputHour, int inputMinute, int inputSecond);

   public:
    Time() = default;

    void parse(const std::string& time);
    void input();
    bool isEmpty() const;

    friend std::ostream& operator<<(std::ostream& ostm, const Time& time) {
        ostm << std::setfill('0') << std::setw(2) << time.hour << ':'
             << std::setw(2) << time.minute << ':' << std::setw(2)
             << time.second;

        return ostm;
    }

    friend std::istream& operator>>(std::istream& istm, Time& time) {
        std::string token;
        if (std::getline(istm, token, ':')) {
            time.hour = std::stoi(token);
        }
        if (std::getline(istm, token, ':')) {
            time.minute = std::stoi(token);
        }
        if (std::getline(istm, token, ' ')) {
            time.second = std::stoi(token);
        }
        return istm;
    }
};
