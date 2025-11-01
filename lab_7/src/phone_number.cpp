#include "phone_number.h"

#include <iomanip>

#include "consts.h"
#include "utils.h"

void PhoneNumber::show_phone_format_exception(const std::string &raw, const std::exception &exc)
{
    std::cout << C_RED << "\nIncorrect phone format: " << exc.what() << " | input: " << raw
              << C_WHITE << std::endl;
}

void PhoneNumber::parse(const std::string &phone_num)
{
    try
    {
        if (phone_num.length() != PHONE_NUM_DIGITS_COUNT)
        {
            throw std::invalid_argument("expected format +375XXYYYYYYY");
        }

        std::string tmp_country_code = phone_num.substr(0, COUNTRY_CODE_DIGITS_COUNT);
        std::string tmp_operator_code =
            phone_num.substr(OPERATOR_CODE_POS, OPERATOR_CODE_DIGITS_COUNT);
        std::string tmp_subscriber_num =
            phone_num.substr(SUBSCRIBER_NUM_POS, SUBSCRIBER_NUMBER_DIGITS_COUNT);

        if (tmp_country_code != "+375")
        {
            throw std::invalid_argument("country code must be +375");
        }

        if (!is_digits(tmp_operator_code) || !is_digits(tmp_subscriber_num))
        {
            throw std::invalid_argument(
                "operator code and subscriber number must contain only digits");
        }

        country_code = tmp_country_code;
        operator_code = tmp_operator_code;
        subscriber_number = tmp_subscriber_num;
    }
    catch (const std::invalid_argument &exc)
    {
        show_phone_format_exception(phone_num, exc);
    }
}

void PhoneNumber::input()
{
    std::string input_phone_number;
    while (true)
    {
        input_phone_number =
            get_value<std::string>("\nPlease enter Belarusian phone number (+375XXYYYYYYY): ");

        parse(input_phone_number);

        if (!is_empty())
        {
            return;
        }
    }
}

bool PhoneNumber::is_empty() const
{
    return country_code.empty() || operator_code.empty() || subscriber_number.empty();
}
