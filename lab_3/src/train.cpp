#include "train.h"

#include "consts.h"
#include "functions.h"

std::string Train::get_sound() const
{
    return TRAIN_SOUND;
}

Train::Train() : PassengerCarrier(TRAIN_COST_PER_KM, TRAIN_SPEED, get_number("\nPlease enter train travel distance(km): ", (int)TRAIN_MIN_DIST, (int)TRAIN_MAX_DIST)) {}
