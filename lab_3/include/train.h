#pragma once

#include "passenger_carrier.h"

class Train : public PassengerCarrier {
  public:
    std::string get_sound() const override;

    Train();
};