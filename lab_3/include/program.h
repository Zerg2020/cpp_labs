#pragma once

#include "passenger_carrier.h"

class Program {
    PassengerCarrier **carriers = nullptr;
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