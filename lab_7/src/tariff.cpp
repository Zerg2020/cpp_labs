#include "tariff.h"

#include <fstream>
#include <iostream>

#include "consts.h"
#include "utils.h"

void MobileTariff::showTariffFormatException(
    const std::string& inputMobileTariff, const std::exception& exc) {
    std::cout << kRedColor << "\nIncorrect tariff format: " << exc.what()
              << " | input: " << inputMobileTariff << kWhiteColor << std::endl;
}

bool MobileTariff::isValidTariff(const std::string_view& inputMobileTariff) {
    std::ifstream fileIn;

    std::string fileContent;

    fileIn.open(kFileWithTariffs);

    if (!fileIn.is_open()) {
        std::cout << kRedColor << "\nError, could not open " << kFileWithTariffs
                  << ". Please try again!" << kWhiteColor << std::endl;
        return false;
    }

    while (fileIn >> fileContent) {
        if (fileContent == inputMobileTariff) {
            fileIn.close();
            return true;
        }
    }

    fileIn.close();
    return false;
}

void MobileTariff::parse(const std::string& inputMobileTariff) {
    try {
        if (!isValidTariff(inputMobileTariff)) {
            throw std::invalid_argument("Unknown Belarusian mobile tariff");
        }

        mobileTariff = inputMobileTariff;

    } catch (const std::invalid_argument& exc) {
        showTariffFormatException(inputMobileTariff, exc);
    }
}

void MobileTariff::input() {
    std::string inputMobileTariff;

    while (true) {
        inputMobileTariff =
            getValue<std::string>("\nEnter Belarusian tariff name: ");

        parse(inputMobileTariff);

        if (!isEmpty()) {
            return;
        }
    }
}

bool MobileTariff::isEmpty() const { return mobileTariff.empty(); }