#pragma once

#include <iostream>

inline const std::string CAR_SOUND = "BIP BIP!";
inline const std::string TRAIN_SOUND = "CHOOH CHOOH CHOOH!";
inline const std::string AIRPLANE_SOUND = "WHOOSH! WHOOSH!";

inline const int CAR_SPEED = 60;
inline const int CAR_COST_PER_KM = 0.20;
inline const double CAR_MIN_DIST = 1.0;
inline const double CAR_MAX_DIST = 1000.0;

inline const int TRAIN_SPEED = 120;
inline const double TRAIN_COST_PER_KM = 0.5;
inline const double TRAIN_MIN_DIST = 10.0;
inline const double TRAIN_MAX_DIST = 2000.0;

inline const int AIRPLANE_SPEED = 800;
inline const double AIRPLANE_COST_PER_KM = 0.1;
inline const double AIRPLANE_MIN_DIST = 100.0;
inline const double AIRPLANE_MAX_DIST = 10000.0;

inline const std::string C_WHITE = "\o{33}[0m";
inline const std::string C_RED = "\o{33}[31m";
inline const std::string C_GREEN = "\o{33}[32m";
