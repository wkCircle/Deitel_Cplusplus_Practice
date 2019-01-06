// Fig. 13.15: SalariedEmployee.h
// SalariedEmployee class derived from Employee.
#ifndef SALARIED_HPP
#define SALARIED_HPP
#include "Employee.hpp" // Employee class definition

class SalariedEmployee : public Employee
{
public:
    SalariedEmployee( const string &, const string &, const string &,
                                int, int, int, double = 0.0 );
    void setWeeklySalary( double ); // set weekly salary
    double getWeeklySalary() const; // return weekly salary

    // keyword virtual signals intent to override
    virtual double earnings() const; // calculate earnings
    virtual void print() const; // print SalariedEmployee object

private:
    double weeklySalary; // salary per week

};

#endif // SALARIED_HPP
