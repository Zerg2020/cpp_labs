#include "city_code.h"

#include <iostream>

#include "consts.h"
#include "utils.h"

void CityCode::showCityCodeFormatException(const std::string& inputCityCode,
                                           const std::exception& exc) {
    std::cout << kRedColor << "\nError: " << exc.what()
              << " | input: " << inputCityCode << kWhiteColor << std::endl;
}

void CityCode::parse(const std::string& inputCityCode) {
    try {
        if (inputCityCode.length() != kCityCodeDigitsCount) {
            throw std::invalid_argument("\nCity code must be 3 digits");
        }

        if (!isDigits(inputCityCode)) {
            throw std::invalid_argument("\nCity code must be numeric");
        }

        cityCode = inputCityCode;

    } catch (const std::invalid_argument& exc) {
        showCityCodeFormatException(inputCityCode, exc);
    }
}

void CityCode::input() {
    std::string inputCityCode;

    while (true) {
        inputCityCode = getValue<std::string>("\nEnter city code (3 digits): ");

        parse(inputCityCode);

        if (!isEmpty()) return;
    }
}

bool CityCode::isEmpty() const { return cityCode.empty(); }
