#pragma once

#include <iostream>

class MobileTariff
{
    std::string mobile_tariff;

    static void show_tariff_format_exception(const std::string &input_mobile_tariff,
                                             const std::exception &exc);
    static bool is_valid_tariff(const std::string_view &input_mobile_tariff);

  public:
    MobileTariff() = default;

    void parse(const std::string &input_mobile_tariff);
    void input();
    bool is_empty() const;

    friend bool operator==(const MobileTariff &original, const MobileTariff &other)
    {
        return (original.mobile_tariff == other.mobile_tariff);
    }

    friend std::ostream &operator<<(std::ostream &ostm, const MobileTariff &tariff)
    {
        ostm << tariff.mobile_tariff;

        return ostm;
    }

    friend std::istream &operator>>(std::istream &istm, MobileTariff &tariff)
    {
        istm >> tariff.mobile_tariff;

        return istm;
    }
};