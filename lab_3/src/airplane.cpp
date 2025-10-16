#include "airplane.h"

#include "consts.h"
#include "functions.h"

std::string Airplane::get_sound() const
{
    return AIRPLANE_SOUND;
}

Airplane::Airplane() : PassengerCarrier(AIRPLANE_COST_PER_KM, AIRPLANE_SPEED, get_number("\nPlease enter airplane travel distance(km): ", (int)AIRPLANE_MIN_DIST, (int)AIRPLANE_MAX_DIST)) {}