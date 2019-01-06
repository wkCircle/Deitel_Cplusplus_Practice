#include "CarbonFootprint.hpp"
double const Car::CO2perG = 9;
double const Bicycle::CalperG = 31000;
double const Bicycle::CalperCO2 = 31000 / 9;
double const Bicycle::HumanMPG = 912;
double const Building::JperCal = 4.2;
double const Building::JperkWh = 3600000;
double const Building::CalperCO2 = 31000 / 9;
int const Building::MperY = 12;



Car::Car(double avg_m_y, double mpg)
    : avgMy(avg_m_y), MPG(mpg)
{
    ;
}
double Car::getCarbonFootprint() const{
    return avgMy / MPG * CO2perG; //yearly CO2 kg for the car.
}
Bicycle::Bicycle(double avg_m_y)
    : avgMy(avg_m_y)
{
    ;
}
double Bicycle::getCarbonFootprint() const{
    return avgMy * CalperG / CalperCO2 / HumanMPG ;
}

Building::Building(double monthly_kWh)
    : kWh_m(monthly_kWh)
{
    ;
}
double Building::getCarbonFootprint() const{
    return MperY * kWh_m * JperkWh / JperCal / CalperCO2;
}
