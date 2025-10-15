#pragma once

#include "consts.h"
#include "passenger_carrier.h"
#include <limits>

int get_number(const std::string &msg, int min, int max);
void print_info(const PassengerCarrier &carrier);
