#pragma once

#include "automatic_telephone_station.h"

class Program
{
    ATS ats;

    void add_record();
    void show_all_records() const;
    void display_phone_numbers_by_tariff() const;

  public:
    Program();

    void run();
};