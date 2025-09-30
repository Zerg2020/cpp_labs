#include "car.h"

#include "consts.h"
#include "utils.h"

std::string Car::get_sound() const { return kCarSound; }

Car::Car()
    : PassengerCarrier(kCarCostPerKmInBYN, kCarSpeedInKmH,
                       get_number("\nPlease enter car travel distance (km): ",
                                 (int)kCarMinDistanceKm, (int)kCarMaxDistanceKm)) {}
