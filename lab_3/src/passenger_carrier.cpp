#include "passenger_carrier.h"

PassengerCarrier::PassengerCarrier() : const_pr_km(0.0), speed_km_h(0.0), distance(0.0) {}
PassengerCarrier::PassengerCarrier(double cost, double speed, double travelDistance) : const_pr_km(cost),
                                 speed_km_h(speed), distance(travelDistance) {}
PassengerCarrier::~PassengerCarrier()
{
    const_pr_km = 0;
    speed_km_h = 0;
    distance = 0;
}

PassengerCarrier::PassengerCarrier(const PassengerCarrier &other) = default;
PassengerCarrier::PassengerCarrier(PassengerCarrier &&move) noexcept = default;
PassengerCarrier &PassengerCarrier::operator=(const PassengerCarrier &other) = default;
PassengerCarrier &PassengerCarrier::operator=(PassengerCarrier &&move) noexcept = default;

std::string PassengerCarrier::get_sound() const
{
    return "NONE";
}

double PassengerCarrier::calculate_cost() const
{
    return distance * const_pr_km;
}

double PassengerCarrier::calculate_time() const
{
    return distance / speed_km_h;
}