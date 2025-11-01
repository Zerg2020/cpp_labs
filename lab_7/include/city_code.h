#pragma once

#include <iostream>

class CityCode
{
    std::string city_code;

    static void show_city_code_format_exception(const std::string &input_city_code,
                                                const std::exception &exc);

  public:
    CityCode() = default;

    void parse(const std::string &input_city_code);
    void input();
    bool is_empty() const;

    friend std::ostream &operator<<(std::ostream &ostm, const CityCode &code)
    {
        ostm << code.city_code;

        return ostm;
    }

    friend std::istream &operator>>(std::istream &istm, CityCode &code)
    {
        istm >> code.city_code;

        return istm;
    }
};