#include "train.h"

#include "consts.h"
#include "utils.h"

std::string Train::get_sound() const { return kTrainSound; }

Train::Train()
    : PassengerCarrier(kTrainCostPerKmInBYN, kTrainSpeedInKmH,
                       get_number("\nPlease enter train travel distance(km): ",
                                 (int)kTrainMinDistanceKm, (int)kTrainMaxDistanceKm)) {}
