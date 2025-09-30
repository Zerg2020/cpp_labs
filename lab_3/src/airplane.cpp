#include "airplane.h"

#include "consts.h"
#include "utils.h"

std::string Airplane::get_sound() const { return kAirplaneSound; }

Airplane::Airplane()
    : PassengerCarrier(
          kAirplaneCostPerKmInBYN, kAirplaneSpeedInKmH,
          get_number("\nPlease enter airplane travel distance(km): ",
                    kAirplaneMinDistanceKm, kAirplaneMaxDistanceKm)) {}