#pragma once

#include <iostream>

class PhoneNumber
{
    std::string country_code;
    std::string operator_code;
    std::string subscriber_number;

    static void show_phone_format_exception(const std::string &raw, const std::exception &exc);

  public:
    PhoneNumber() = default;
    PhoneNumber(std::string input_country_code,
                std::string input_operator_code,
                std::string inputSubscriberNumber) :
        country_code(std::move(input_country_code)),
        operator_code(std::move(input_operator_code)),
        subscriber_number(std::move(inputSubscriberNumber))
    {
    }

    void parse(const std::string &phone_num);
    void input();
    bool is_empty() const;

    friend std::ostream &operator<<(std::ostream &ostm, const PhoneNumber &number)
    {
        ostm << number.country_code << "(" << number.operator_code << ")"
             << number.subscriber_number;

        return ostm;
    }

    friend std::istream &operator>>(std::istream &istm, PhoneNumber &number)
    {
        std::string token;

        if (std::getline(istm, token, '('))
        {
            number.country_code = token;
        }

        if (std::getline(istm, token, ')'))
        {
            number.operator_code = token;
        }
        if (std::getline(istm, token, ' '))
        {
            number.subscriber_number = token;
        }
        return istm;
    }
};
