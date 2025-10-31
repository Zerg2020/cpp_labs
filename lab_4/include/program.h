#pragma once

#include "cargo_carrier.h"

class Program
{
    CargoCarrier **carriers = nullptr;
    int size = 0;
    int cap = 1;

    void add_carrier();
    void choose_carrier();
    void expand_carries();
    void show_info() const;
    void remove_carriers();

  public:
    Program();

    void run();
};