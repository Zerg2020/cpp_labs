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
inline const int FORMAT_DATA_LEN = 8;