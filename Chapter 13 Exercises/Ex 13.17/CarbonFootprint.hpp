//source: https://www.daniweb.com/programming/software-development/threads/456795/calculate-carbon-footprint-program

#ifndef CarbonFootprint_hpp
#define CarbonFootprint_hpp


#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <ctime>
#include <random>
#include <typeinfo>
#include <vector>
#include <cctype>  //isdigit function prototype
using namespace std;

class CarbonFootprint{
public:
    virtual double getCarbonFootprint() const =0; //pure virtual
};

class Car: public CarbonFootprint{
public:
    Car(double, double); //avgMy and MPG
    virtual double getCarbonFootprint() const; // unit: kgCO2 per car
private:
    double avgMy; //avg yearly miles for the car.
    double MPG; //miles per gallon (avg)
    static double const CO2perG ; //unit: kg per gallon
};


class Bicycle: public CarbonFootprint{
public:
    Bicycle(double); //avgMy
    virtual double getCarbonFootprint() const; // unit: kgCO2 per bike
private:
    /**< 1 gallon = 31000 calories or so. And 1 gallon = 9 kg CO2 or so. */
    double avgMy; //avg yearly miles using the bike
    static double const CalperG;
    static double const CalperCO2; //unit: kg per cal
    static double const HumanMPG; //source: https://auto.howstuffworks.com/question527.htm
};




class Building: public CarbonFootprint{
public:
    Building(double); //monthly kWh_m
    virtual double getCarbonFootprint() const; // unit: kgCO2 per house
private:
    double kWh_m;
    static double const JperCal;
    static double const JperkWh;
    static double const CalperCO2; //unit: kg per cal
    static int const MperY; //months per year
};


#endif // CarbonFootprint_hpp
