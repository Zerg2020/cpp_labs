#pragma once

#include "date.h"

class Program
{
    Date date;

    void input_date();
    void show_date() const;

  public:
    void run();
};