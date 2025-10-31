#include "city_name.h"

#include <fstream>

#include "consts.h"
#include "utils.h"

void CityName::showCityFormatException(const std::string& inputCityName,
                                       const std::exception& exc) {
    std::cout << kRedColor << "\nIncorrect city name: " << exc.what()
              << " | input: " << inputCityName << kWhiteColor << std::endl;
}

bool CityName::isValidCityName(const std::string_view& str) {
    std::ifstream fileIn;

    std::string fileContent;

    fileIn.open(kFileWithCityNames);

    if (!fileIn.is_open()) {
        std::cout << kRedColor << "\nError, could not open "
                  << kFileWithCityNames << ". Please try again!" << kWhiteColor
                  << std::endl;
        return false;
    }

    while (fileIn >> fileContent) {
        if (str == fileContent) {
            fileIn.close();
            return true;
        }
    }

    fileIn.close();

    return false;
}

void CityName::parse(const std::string& inputCityName) {
    try {
        if (!isValidCityName(inputCityName)) {
            throw std::invalid_argument("City not found in Belarus");
        }

        cityName = inputCityName;

    } catch (const std::invalid_argument& exc) {
        showCityFormatException(inputCityName, exc);
    }
}

void CityName::input() {
    std::string inputCityName;

    while (true) {
        inputCityName = getValue<std::string>(
            "\nPlease enter the name of a Belarusian city: ");

        parse(inputCityName);

        if (!isEmpty()) {
            return;
        }
    }
}

bool CityName::isEmpty() const { return cityName.empty(); }
