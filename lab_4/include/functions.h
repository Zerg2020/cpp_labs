#pragma once

#include "cargo_carrier.h"
#include "consts.h"

int get_number(const std::string &msg, int min, int max);

std::string get_string(const std::string &msg);

void print_info(const CargoCarrier &carrier);