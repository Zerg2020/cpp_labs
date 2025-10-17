#include "train.h"
#include "consts.h"
#include "functions.h"

std::string Train::get_sound() const {
    return TRAIN_SOUND;
}

Train::Train()
    : CargoCarrier(get_number("\nPlease enter train cost (per km): ", TRAIN_MIN_COST_PR_KM, TRAIN_MAX_COST_PR_KM),
                   get_number("\nPlease enter train speed (km/h): ", TRAIN_MIN_SPEED_KM_H, TRAIN_MAX_SPEED_KM_H),
                   get_number("\nPlease enter train travel distance(km): ", TRAIN_MIN_DISTANCE_KM, TRAIN_MAX_DISTANCE_KM),
                   get_string("\nPlease enter the name of the city to travel to by train: ")) {
}