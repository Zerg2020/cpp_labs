#pragma once

#include <iostream>

class CityName {
    std::string cityName;

    static void showCityFormatException(const std::string& inputCityName,
                                        const std::exception& exc);
    static bool isValidCityName(const std::string_view& str);

   public:
    CityName() = default;

    void parse(const std::string& inputCityName);
    void input();
    bool isEmpty() const;

    friend std::ostream& operator<<(std::ostream& ostm, const CityName& name) {
        ostm << name.cityName;

        return ostm;
    }

    friend std::istream& operator>>(std::istream& istm, CityName& name) {
        istm >> name.cityName;

        return istm;
    }
};