#pragma once

#include "cargo_carrier.h"

class Train : public CargoCarrier {
  public:
    std::string get_sound() const override;

    Train();
};