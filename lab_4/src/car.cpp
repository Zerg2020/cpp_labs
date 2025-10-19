#include "car.h"
#include "consts.h"
#include "functions.h"

std::string Car::get_sound() const
{
    return CAR_SOUND;
}

Car::Car() :
    CargoCarrier(CAR_COST_PR_KM,
                 CAR_SPEED_KM_H,
                 get_number("\nPlease enter car travel distance(km): ",
                            CAR_MIN_DISTANCE_KM,
                            CAR_MAX_DISTANCE_KM),
                 get_string("\nPlease enter the name of the city to travel to by car: "))
{
}