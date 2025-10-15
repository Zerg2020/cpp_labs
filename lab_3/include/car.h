#pragma once

#include "passenger_carrier.h"

class Car : public PassengerCarrier
{
  public:
    std::string get_sound() const override;

    Car();
};