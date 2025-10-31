#include "phone_number.h"

#include <iomanip>

#include "consts.h"
#include "utils.h"

void PhoneNumber::showPhoneFormatException(const std::string& raw,
                                           const std::exception& exc) {
    std::cout << kRedColor << "\nIncorrect phone format: " << exc.what()
              << " | input: " << raw << kWhiteColor << std::endl;
}

void PhoneNumber::parse(const std::string& phoneNum) {
    try {
        if (phoneNum.length() != kPhoneNumDigitsCount) {
            throw std::invalid_argument("expected format +375XXYYYYYYY");
        }

        std::string tmpCountryCode =
            phoneNum.substr(0, kCountryCodeDigitsCount);
        std::string tmpOperatorCode =
            phoneNum.substr(kOperatorCodePos, kOperatorCodeDigitsCount);
        std::string tmpSubscriberNum =
            phoneNum.substr(kSubscriberNumPos, kSubscriberNumDigitsCount);

        if (tmpCountryCode != "+375") {
            throw std::invalid_argument("country code must be +375");
        }

        if (!isDigits(tmpOperatorCode) || !isDigits(tmpSubscriberNum)) {
            throw std::invalid_argument(
                "operator code and subscriber number must contain only digits");
        }

        countryCode = tmpCountryCode;
        operatorCode = tmpOperatorCode;
        subscriberNumber = tmpSubscriberNum;

    } catch (const std::invalid_argument& exc) {
        showPhoneFormatException(phoneNum, exc);
    }
}

void PhoneNumber::input() {
    std::string inputPhoneNumber;
    while (true) {
        inputPhoneNumber = getValue<std::string>(
            "\nPlease enter Belarusian phone number (+375XXYYYYYYY): ");

        parse(inputPhoneNumber);

        if (!isEmpty()) {
            return;
        }
    }
}

bool PhoneNumber::isEmpty() const {
    return countryCode.empty() || operatorCode.empty() ||
           subscriberNumber.empty();
}
