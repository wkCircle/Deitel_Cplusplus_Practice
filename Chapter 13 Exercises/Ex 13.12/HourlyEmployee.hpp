// Fig. 13.17: HourlyEmployee.h
// HourlyEmployee class definition.
#ifndef HOURLY_HPP
#define HOURLY_HPP

#include "Employee.hpp" // Employee class definition

class HourlyEmployee : public Employee
{
public:
    static const int hoursPerWeek = 168; // hours in one week

    HourlyEmployee( const string &, const string &, const string &,
                   int, int, int, double = 0.0, double = 0.0 );
    void setWage( double ); // set hourly wage
    double getWage() const; // return hourly wage
    void setHours( double ); // set hours worked
    double getHours() const; // return hours worked

    // keyword virtual signals intent to override
    virtual double earnings() const; // calculate earnings
    virtual void print() const; // print HourlyEmployee object
private:
    double wage; // wage per hour
    double hours; // hours worked for week
};

#endif // HOURLY_HPP
