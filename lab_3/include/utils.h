#pragma once

#include "consts.h"
#include <limits>
#include "passenger_carrier.h"


int get_number(const std::string &msg, int min, int max);
void print_info(const PassengerCarrier &carrier);
