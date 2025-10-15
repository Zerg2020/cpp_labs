#pragma once

#include "passenger_carrier.h"

class Airplane : public PassengerCarrier
{
  public:
    std::string get_sound() const override;

    Airplane();
};