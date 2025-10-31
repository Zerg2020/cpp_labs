#pragma once

#include <iostream>

class PhoneNumber {
    std::string countryCode;
    std::string operatorCode;
    std::string subscriberNumber;

    static void showPhoneFormatException(const std::string& raw,
                                         const std::exception& exc);

   public:
    PhoneNumber() = default;
    PhoneNumber(std::string inputCountryCode, std::string inputOperatorCode,
                std::string inputSubscriberNumber)
        : countryCode(std::move(inputCountryCode)),
          operatorCode(std::move(inputOperatorCode)),
          subscriberNumber(std::move(inputSubscriberNumber)) {}

    void parse(const std::string& phoneNum);
    void input();
    bool isEmpty() const;

    friend std::ostream& operator<<(std::ostream& ostm,
                                    const PhoneNumber& number) {
        ostm << number.countryCode << "(" << number.operatorCode << ")"
             << number.subscriberNumber;

        return ostm;
    }

    friend std::istream& operator>>(std::istream& istm, PhoneNumber& number) {
        std::string token;

        if (std::getline(istm, token, '(')) {
            number.countryCode = token;
        }

        if (std::getline(istm, token, ')')) {
            number.operatorCode = token;
        }
        if (std::getline(istm, token, ' ')) {
            number.subscriberNumber = token;
        }
        return istm;
    }
};
