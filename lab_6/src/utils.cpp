#include "utils.h"

#include <iostream>

bool isDigits(std::string str, int pos, int len) {
    for (int i = 0; i < len; i++) {
        if (isdigit(str[pos + i]) != 1) {
            return false;
        }
    }

    return true;
}