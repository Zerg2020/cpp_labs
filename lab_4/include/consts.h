#pragma once

#include <iostream>

inline const std::string CAR_SOUND = "BIP BIP!";
inline const std::string TRAIN_SOUND = "CHOOH CHOOH!";
inline const std::string AIRPLANE_SOUND = "WHOOOSH!";

inline const double CAR_MIN_PR_KM = 0.1;
inline const double CAR_MAX_PR_KM = 5.0;
inline const double CAR_MIN_SPEED_KM_H = 10.0;
inline const double CAR_MAX_SPEED_KM_H = 250.0;
inline const double CAR_MIN_DISTANCE_KM = 1.0;
inline const double CAR_MAX_DISTANCE_KM = 1000.0;

inline const double TRAIN_MIN_COST_PR_KM = 0.05;
inline const double TRAIN_MAX_COST_PR_KM = 1.0;
inline const double TRAIN_MIN_SPEED_KM_H = 30.0;
inline const double TRAIN_MAX_SPEED_KM_H = 350.0;
inline const double TRAIN_MIN_DISTANCE_KM = 10.0;
inline const double TRAIN_MAX_DISTANCE_KM = 2000.0;

inline const double AIRPLANE_MIN_COST_PR_KM = 0.5;
inline const double AIRPLANE_MAX_COST_PR_KM = 10.0;
inline const double AIRPLANE_MIN_SPEED_KM_H = 300.0;
inline const double AIRPLANE_MAX_SPEED_KM_H = 1200.0;
inline const double AIRPLANE_MIN_DISTANCE_KM = 100.0;
inline const double AIRPLANE_MAX_DISTANCE_KM = 10000.0;

inline const std::string C_WHITE = "\o{33}[0m";
inline const std::string C_RED = "\o{33}[31m";
inline const std::string C_GREEN = "\o{33}[32m";