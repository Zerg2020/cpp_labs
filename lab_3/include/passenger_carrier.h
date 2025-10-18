#pragma once

#include <iostream>

class PassengerCarrier
{
    double cost_pr_km;
    double speed_km_h;
    double distance;

  protected:
    PassengerCarrier();

    explicit PassengerCarrier(double cost, double speed, double travel_distance);

  public:
    virtual ~PassengerCarrier();
    virtual std::string get_sound() const;
    double calculate_cost() const;
    double calculate_time() const;
    double get_distance() const { return distance; };

    PassengerCarrier(const PassengerCarrier &other);
    PassengerCarrier &operator=(const PassengerCarrier &other);
    PassengerCarrier(PassengerCarrier &&move) noexcept;
    PassengerCarrier &operator=(PassengerCarrier &&move) noexcept;
};