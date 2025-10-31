#pragma once

#include <iostream>

class CityCode {
    std::string cityCode;

    static void showCityCodeFormatException(const std::string& inputCityCode,
                                            const std::exception& exc);

   public:
    CityCode() = default;

    void parse(const std::string& inputCityCode);
    void input();
    bool isEmpty() const;

    friend std::ostream& operator<<(std::ostream& ostm, const CityCode& code) {
        ostm << code.cityCode;

        return ostm;
    }

    friend std::istream& operator>>(std::istream& istm, CityCode& code) {
        istm >> code.cityCode;

        return istm;
    }
};