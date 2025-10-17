#include "car.h"
#include "consts.h"
#include "utils.h"

std::string Car::get_sound() const {
    return CAR_SOUND;
}

Car::Car()
    : CargoCarrier(get_number("\nPlease enter car cost (per km): ", CAR_MIN_PR_KM, CAR_MAX_PR_KM),
                   get_number("\nPlease enter car speed (km/h): ", CAR_MIN_SPEED_KM_H, CAR_MAX_SPEED_KM_H),
                   get_number("\nPlease enter car travel distance(km): ", CAR_MIN_DISTANCE_KM, CAR_MAX_DISTANCE_KM),
                   get_string("\nPlease enter the name of the city to travel to by car: ")) {
}