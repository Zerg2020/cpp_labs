#pragma once

#include "city_code.h"
#include "city_name.h"
#include "date.h"
#include "my_time.h"
#include "phone_number.h"
#include "phone_numbers.h"
#include "tariff.h"

class ATS
{
    Date date;
    CityCode city_code;
    CityName city_name;
    Time time;
    MobileTariff mobile_tariff;
    PhoneNumber phone_number;

  public:
    ATS() = default;

    friend std::ostream &operator<<(std::ostream &ostm, const ATS &ats)
    {
        ostm << ats.date << " " << ats.city_code << " " << ats.city_name << " " << ats.time << " "
             << ats.mobile_tariff << " " << ats.phone_number;

        return ostm;
    }

    friend std::istream &operator>>(std::istream &istm, ATS &ats)
    {
        istm >> ats.date >> ats.city_code >> ats.city_name >> ats.time >> ats.mobile_tariff >>
            ats.phone_number;

        return istm;
    }

    void add();
    static void show();
    static PhoneNumbers find_phone_numbers_by_tariff(const MobileTariff &tariff);
    bool is_empty() const;
};