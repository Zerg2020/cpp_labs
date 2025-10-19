#include "train.h"
#include "consts.h"
#include "functions.h"

std::string Train::get_sound() const
{
    return TRAIN_SOUND;
}

Train::Train() :
    CargoCarrier(TRAIN_COST_PR_KM,
                 TRAIN_SPEED_KM_H,
                 get_number("\nPlease enter train travel distance(km): ",
                            TRAIN_MIN_DISTANCE_KM,
                            TRAIN_MAX_DISTANCE_KM),
                 get_string("\nPlease enter the name of the city to travel to by train: "))
{
}