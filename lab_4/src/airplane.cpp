#include "airplane.h"
#include "consts.h"
#include "functions.h"

std::string Airplane::get_sound() const {
    return AIRPLANE_SOUND;
}

Airplane::Airplane()
    : CargoCarrier(
          get_number("\nPlease enter airplane cost (per km): ", AIRPLANE_MIN_COST_PR_KM, AIRPLANE_MAX_COST_PR_KM),
          get_number("\nPlease enter airplane speed (km/h): ", AIRPLANE_MIN_SPEED_KM_H, AIRPLANE_MAX_SPEED_KM_H),
          get_number("\nPlease enter airplane travel distance(km): ", AIRPLANE_MIN_DISTANCE_KM, AIRPLANE_MAX_DISTANCE_KM),
          get_string("\nPlease enter the name of the city to travel to by plane: ")) {
}