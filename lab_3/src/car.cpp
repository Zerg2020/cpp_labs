#include "car.h"

#include "consts.h"
#include "functions.h"

std::string Car::get_sound() const
{
    return CAR_SOUND;
}

Car::Car() : PassengerCarrier(CAR_COST_PER_KM, CAR_SPEED, get_number("\nPlease enter car travel distance (km): ", (int)CAR_MIN_DIST, (int)CAR_MAX_DIST)) {}
