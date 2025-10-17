#pragma once

#include "cargo_carrier.h"

class Car : public CargoCarrier {
  public:
    std::string get_sound() const override;

    Car();
};