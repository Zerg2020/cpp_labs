#include "my_time.h"

#include <iomanip>
#include <iostream>

#include "consts.h"
#include "utils.h"

Time::Time(int input_hour, int input_minut, int input_second) :
    hour(input_hour), minute(input_minut), second(input_second)
{
}

void Time::show_time_format_exception(const std::string &time, const std::exception &exc)
{
    std::cout << C_RED << "\nIncorrect time format: " << exc.what() << " | input: " << time
              << C_WHITE << std::endl;
}

void Time::parse(const std::string &time)
{
    try
    {
        if (time.length() != FORMAT_TIME_LEN)
        {
            throw std::invalid_argument("expected format HH:MM:SS (8 characters)");
        }

        if (time[2] != ':' || time[5] != ':')
        {
            throw std::invalid_argument("separators must be ':' at positions 3 and 6");
        }

        if (!is_digits(time, 0, 2) || !is_digits(time, 3, 2) || !is_digits(time, 6, 2))
        {
            throw std::invalid_argument("hours, minutes and seconds must contain only digits");
        }

        int tmp_hour = std::stoi(time.substr(0, 2));
        int tmp_minute = std::stoi(time.substr(3, 2));
        int tmp_second = std::stoi(time.substr(6, 2));

        if (tmp_hour < 0 || tmp_hour > HOURS_COUNT)
        {
            throw std::invalid_argument("hour out of range (00..23)");
        }

        if (tmp_minute < 0 || tmp_minute > MINUTES_COUNT)
        {
            throw std::invalid_argument("minute out of range (00..59)");
        }

        if (tmp_second < 0 || tmp_second > SECOUNDS_COUNt)
        {
            throw std::invalid_argument("second out of range (00..59)");
        }

        hour = tmp_hour;
        minute = tmp_minute;
        second = tmp_second;
    }
    catch (const std::invalid_argument &exc)
    {
        show_time_format_exception(time, exc);
    }
    catch (const std::out_of_range &exc)
    {
        show_time_format_exception(time, exc);
    }
}

void Time::input()
{
    std::string input_time;

    while (true)
    {
        input_time = get_value<std::string>("\nPlease enter the time (HH:MM:SS): ");

        parse(input_time);

        if (!is_empty())
        {
            return;
        }
    }
}

bool Time::is_empty() const
{
    return (hour == 0 || minute == 0 || second == 0);
}
