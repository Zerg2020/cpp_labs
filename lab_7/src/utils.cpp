#include "utils.h"

#include <algorithm>
#include <fstream>
#include <iostream>

#include "automatic_telephone_station.h"

bool isDigits(const std::string& str, const int pos, const int len) {
    for (int i = 0; i < len; i++) {
        if (isdigit(str[pos + i]) != 1) {
            return false;
        }
    }

    return true;
}

bool isDigits(const std::string_view& str) {
    return std::all_of(str.begin(), str.end(),
                       [](unsigned char sym) { return std::isdigit(sym); });
}
