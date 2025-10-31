#pragma once

#include "automatic_telephone_station.h"

class Program {
    ATS ats;

    void addRecord();
    void showAllRecords() const;
    void displayPhoneNumbersByTariff() const;

   public:
    Program();

    void run();
};