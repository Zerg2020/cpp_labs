#include "my_time.h"

#include <iomanip>
#include <iostream>

#include "consts.h"
#include "utils.h"

Time::Time(int inputHour, int inputMinut, int inputSecond)
    : hour(inputHour), minute(inputMinut), second(inputSecond) {}

void Time::showTimeFormatException(const std::string& time,
                                   const std::exception& exc) {
    std::cout << kRedColor << "\nIncorrect time format: " << exc.what()
              << " | input: " << time << kWhiteColor << std::endl;
}

void Time::parse(const std::string& time) {
    try {
        if (time.length() != kFormatTimeLen) {
            throw std::invalid_argument(
                "expected format HH:MM:SS (8 characters)");
        }

        if (time[2] != ':' || time[5] != ':') {
            throw std::invalid_argument(
                "separators must be ':' at positions 3 and 6");
        }

        if (!isDigits(time, 0, 2) || !isDigits(time, 3, 2) ||
            !isDigits(time, 6, 2)) {
            throw std::invalid_argument(
                "hours, minutes and seconds must contain only digits");
        }

        int tmpHour = std::stoi(time.substr(0, 2));
        int tmpMinute = std::stoi(time.substr(3, 2));
        int tmpSecond = std::stoi(time.substr(6, 2));

        if (tmpHour < 0 || tmpHour > kHoursCount) {
            throw std::invalid_argument("hour out of range (00..23)");
        }

        if (tmpMinute < 0 || tmpMinute > kMinutesCount) {
            throw std::invalid_argument("minute out of range (00..59)");
        }

        if (tmpSecond < 0 || tmpSecond > kSecondsCount) {
            throw std::invalid_argument("second out of range (00..59)");
        }

        hour = tmpHour;
        minute = tmpMinute;
        second = tmpSecond;

    } catch (const std::invalid_argument& exc) {
        showTimeFormatException(time, exc);
    } catch (const std::out_of_range& exc) {
        showTimeFormatException(time, exc);
    }
}

void Time::input() {
    std::string inputTime;

    while (true) {
        inputTime =
            getValue<std::string>("\nPlease enter the time (HH:MM:SS): ");

        parse(inputTime);

        if (!isEmpty()) {
            return;
        }
    }
}

bool Time::isEmpty() const { return (hour == 0 || minute == 0 || second == 0); }
