#include "automatic_telephone_station.h"

#include <fstream>
#include <iomanip>
#include <iostream>

#include "consts.h"
#include "phone_numbers.h"
#include "utils.h"

void ATS::add() {
    ATS tmp;

    tmp.date.input();
    tmp.cityCode.input();
    tmp.cityName.input();
    tmp.time.input();
    tmp.mobileTariff.input();
    tmp.phoneNumber.input();

    std::ofstream fileOut;

    fileOut.open(kFileWithData, std::ios::app);

    if (!isValidFileOpen(fileOut, kFileWithData)) {
        return;
    }

    fileOut << tmp << " ";

    fileOut.close();

    *this = tmp;
}

void ATS::show() {
    std::ifstream fileIn;

    fileIn.open(kFileWithData);

    ATS tmp;

    if (!isValidFileOpen(fileIn, kFileWithData)) {
        return;
    }

    std::cout << "\n\t\t\t\tATS" << std::endl;

    while (fileIn >> tmp) {
        std::cout << tmp << std::endl;
    }
}

PhoneNumbers ATS::findPhoneNumbersByTariff(const MobileTariff& tariff) {
    std::ifstream fileIn;

    fileIn.open(kFileWithData);

    ATS tmp;
    PhoneNumbers res;

    if (!isValidFileOpen(fileIn, kFileWithData)) {
        return res;
    }

    while (fileIn >> tmp) {
        if (tmp.mobileTariff == tariff) {
            res.add(tmp.phoneNumber);
        }
    }

    return res;
}

bool ATS::isEmpty() const {
    return (date.isEmpty() && cityCode.isEmpty() && cityName.isEmpty() &&
            time.isEmpty() && mobileTariff.isEmpty() && phoneNumber.isEmpty());
}