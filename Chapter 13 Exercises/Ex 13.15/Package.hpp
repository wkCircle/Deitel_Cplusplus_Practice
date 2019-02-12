
#ifndef Package_hpp
#define Package_hpp

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


class Package {
public:
    enum Argument {name=0, address, city, state, ZIP};
    Package(string, string, string, string, string, string, string, string, string, string, double =1, double = 10.0);
    ~Package();
    virtual double calculateCost();

    void validationAndSet(double &, double &);
    void setInfo(Argument , string, string ="r"); //1st: name/address/city/...;  2nd:input_value; 3rd: r means recipient; ow, sender.
    double getWeight();
    double getCostPerOunce();
    void print();

    virtual void printPrice();
private:
    string name_sender, name_recipient;
    string address_sender, address_recipient;
    string city_sender, city_recipient;
    string state_sender, state_recipient;
    string ZIP_sender, ZIP_recipient;
    double weight; //in ounces
    double costPerOunce;
};


class TwoDayPackage: public Package{
public:
    TwoDayPackage(string, string, string, string, string, string, string, string, string, string, double =1, double = 10.0, double =3.0);
    ~TwoDayPackage();
    void validationAndSet( double &);
    virtual double calculateCost();
    virtual void printPrice();
private:
    double flatFee;
};
class OvernightPackage: public Package{
public:
    OvernightPackage(string, string, string, string, string, string, string, string, string, string, double =1, double = 10.0, double = 1.0);
    ~OvernightPackage();
    void validationAndSet( double &);
    virtual double calculateCost();
    virtual void printPrice();
private:
    double extraFee; //depends on weight per ounce
};



#endif // Package_hpp
