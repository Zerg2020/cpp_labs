#pragma once

#include <array>
#include <iostream>

inline const std::string C_WHITE = "\o{33}[0m";
inline const std::string C_RED = "\o{33}[31m";
inline const std::string C_GREEN = "\o{33}[32m";

inline const int MONTH_COUNT = 12;
inline const std::array<int, MONTH_COUNT> DAYS_IN_MONTH = {31, 28, 31, 30, 31, 30,
                                                           31, 31, 30, 31, 30, 31};
inline const int LEAP_FEBRUARY_DAYS = 29;
inline const int FORMAT_DETE_LEN = 8;

inline const int FORMAT_TIME_LEN = 8;
inline const int HOURS_COUNT = 23;
inline const int MINUTES_COUNT = 59;
inline const int SECOUNDS_COUNt = 59;

inline const int PHONE_NUM_DIGITS_COUNT = 13;
inline const int COUNTRY_CODE_DIGITS_COUNT = 4;
inline const int OPERATOR_CODE_DIGITS_COUNT = 2;
inline const int SUBSCRIBER_NUMBER_DIGITS_COUNT = 7;
inline const int OPERATOR_CODE_POS = 4;
inline const int SUBSCRIBER_NUM_POS = 6;

inline const std::string FILE_WITH_CITY_NAMES = "city_names.txt";

inline const int CITY_CODE_DIGITS_COUNTS = 3;

inline const std::string FILE_WITH_TARIFFS = "tariffs.txt";

inline const std::string FILE_WITH_DATA = "data.txt";

inline const int INDENT_WIDTH = 16;