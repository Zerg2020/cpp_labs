#include "cargo_carrier.h"

CargoCarrier::CargoCarrier() : cost_pr_km(0.0), speed_km_h(0.0), distance(0.0) {}

CargoCarrier::CargoCarrier(double cost,
                           double speed,
                           double travel_distance,
                           std::string city_name) :
    cost_pr_km(cost),
    speed_km_h(speed), distance(travel_distance), city(std::move(city_name))
{
}

CargoCarrier::~CargoCarrier()
{
    cost_pr_km = 0;
    speed_km_h = 0;
    distance = 0;
}

CargoCarrier::CargoCarrier(const CargoCarrier &other) = default;

CargoCarrier::CargoCarrier(CargoCarrier &&move) noexcept = default;

CargoCarrier &CargoCarrier::operator=(const CargoCarrier &other) = default;

CargoCarrier &CargoCarrier::operator=(CargoCarrier &&move) noexcept = default;

double CargoCarrier::calculate_cost() const
{
    return distance * cost_pr_km;
}

double CargoCarrier::calculate_time() const
{
    return distance / speed_km_h;
}

std::string CargoCarrier::get_city() const
{
    return city;
}