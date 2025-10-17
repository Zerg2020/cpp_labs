#pragma once

#include <iostream>
#include <string>

class CargoCarrier {
    double cost_pr_km;
    double speed_km_h;
    double distance;
    std::string city;

  protected:
    CargoCarrier();

    explicit CargoCarrier(double cost, double speed, double travel_distance, std::string city_name);

  public:
    virtual ~CargoCarrier();
    virtual std::string get_sound() const = 0;

    CargoCarrier(const CargoCarrier &other);
    CargoCarrier &operator=(const CargoCarrier &other);
    CargoCarrier(CargoCarrier &&move) noexcept;
    CargoCarrier &operator=(CargoCarrier &&move) noexcept;
    double calculate_cost() const;
    double calculate_time() const;
    std::string get_city() const;
};