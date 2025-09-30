#pragma once

#include <iostream>

inline const std::string kCarSound = "BIP BIP!";
inline const std::string kTrainSound = "CHOOH CHOOH!";
inline const std::string kAirplaneSound = "WHOOOSH!";

inline const int kCarSpeedInKmH = 60;
inline const int kCarCostPerKmInBYN = 1;
inline const double kCarMinDistanceKm = 1.0;
inline const double kCarMaxDistanceKm = 1000.0;

inline const int kTrainSpeedInKmH = 120;
inline const double kTrainCostPerKmInBYN = 0.5;
inline const double kTrainMinDistanceKm = 10.0;
inline const double kTrainMaxDistanceKm = 2000.0;

inline const int kAirplaneSpeedInKmH = 800;
inline const double kAirplaneCostPerKmInBYN = 0.1;
inline const double kAirplaneMinDistanceKm = 100.0;
inline const double kAirplaneMaxDistanceKm = 10000.0;

inline const std::string kWhiteColor = "\o{33}[0m";
inline const std::string kRedColor = "\o{33}[31m";
inline const std::string kGreenColor = "\o{33}[32m";
