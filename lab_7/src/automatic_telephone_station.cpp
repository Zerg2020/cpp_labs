#include "automatic_telephone_station.h"

#include <fstream>
#include <iomanip>
#include <iostream>

#include "consts.h"
#include "phone_numbers.h"
#include "utils.h"

void ATS::add()
{
    ATS tmp;

    tmp.date.input();
    tmp.city_code.input();
    tmp.city_name.input();
    tmp.time.input();
    tmp.mobile_tariff.input();
    tmp.phone_number.input();

    std::ofstream fileOut;

    fileOut.open(FILE_WITH_DATA, std::ios::app);

    if (!is_valid_file_open(fileOut, FILE_WITH_DATA))
    {
        return;
    }

    fileOut << tmp << " ";

    fileOut.close();

    *this = tmp;
}

void ATS::show()
{
    std::ifstream file_in;

    file_in.open(FILE_WITH_DATA);

    ATS tmp;

    if (!is_valid_file_open(file_in, FILE_WITH_DATA))
    {
        return;
    }

    std::cout << "\n\t\t\t\tATS" << std::endl;

    while (file_in >> tmp)
    {
        std::cout << tmp << std::endl;
    }
}

PhoneNumbers ATS::find_phone_numbers_by_tariff(const MobileTariff &tariff)
{
    std::ifstream file_in;

    file_in.open(FILE_WITH_DATA);

    ATS tmp;
    PhoneNumbers res;

    if (!is_valid_file_open(file_in, FILE_WITH_DATA))
    {
        return res;
    }

    while (file_in >> tmp)
    {
        if (tmp.mobile_tariff == tariff)
        {
            res.add(tmp.phone_number);
        }
    }

    return res;
}

bool ATS::is_empty() const
{
    return (date.is_empty() && city_code.is_empty() && city_name.is_empty() && time.is_empty() &&
            mobile_tariff.is_empty() && phone_number.is_empty());
}