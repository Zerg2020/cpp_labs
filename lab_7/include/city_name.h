#pragma once

#include <iostream>

class CityName
{
    std::string city_name;

    static void show_city_format_exception(const std::string &input_city_name,
                                           const std::exception &exc);
    static bool is_valid_city_name(const std::string_view &str);

  public:
    CityName() = default;

    void parse(const std::string &input_city_name);
    void input();
    bool is_empty() const;

    friend std::ostream &operator<<(std::ostream &ostm, const CityName &name)
    {
        ostm << name.city_name;

        return ostm;
    }

    friend std::istream &operator>>(std::istream &istm, CityName &name)
    {
        istm >> name.city_name;

        return istm;
    }
};