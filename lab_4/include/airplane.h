#pragma once

#include "cargo_carrier.h"

class Airplane : public CargoCarrier
{
  public:
    std::string get_sound() const override;

    Airplane();
};