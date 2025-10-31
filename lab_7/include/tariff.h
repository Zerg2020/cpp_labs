#pragma once

#include <iostream>

class MobileTariff {
    std::string mobileTariff;

    static void showTariffFormatException(const std::string& inputMobileTariff,
                                          const std::exception& exc);
    static bool isValidTariff(const std::string_view& inputMobileTariff);

   public:
    MobileTariff() = default;

    void parse(const std::string& inputMobileTariff);
    void input();
    bool isEmpty() const;

    friend bool operator==(const MobileTariff& original,
                           const MobileTariff& other) {
        return (original.mobileTariff == other.mobileTariff);
    }

    friend std::ostream& operator<<(std::ostream& ostm,
                                    const MobileTariff& tariff) {
        ostm << tariff.mobileTariff;

        return ostm;
    }

    friend std::istream& operator>>(std::istream& istm, MobileTariff& tariff) {
        istm >> tariff.mobileTariff;

        return istm;
    }
};