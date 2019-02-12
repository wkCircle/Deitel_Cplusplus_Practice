// Fig. 13.22: BasePlusCommissionEmployee.cpp
// BasePlusCommissionEmployee member-function definitions.
#include <iostream>
#include "BasePlusCommissionEmployee.hpp"
using namespace std;

// constructor
BasePlusCommissionEmployee::BasePlusCommissionEmployee(
            const string &first, const string &last, const string &ssn,
            int month , int day , int year, double sales, double rate, double salary )
    : CommissionEmployee( first, last, ssn, month, day, year, sales, rate )
{
    setBaseSalary( salary ); // validate and store base salary
}

// set base salary
void BasePlusCommissionEmployee::setBaseSalary( double salary )
{
    baseSalary = ( ( salary < 0.0 ) ? 0.0 : salary );
}

// return base salary
double BasePlusCommissionEmployee::getBaseSalary() const
{
    return baseSalary;
}

// calculate earnings;
// override virtual function earnings in CommissionEmployee
double BasePlusCommissionEmployee::earnings() const
{
    return getBaseSalary() + CommissionEmployee::earnings() ;
}

// print BasePlusCommissionEmployee's information
void BasePlusCommissionEmployee::print() const
{
    cout << "base-salaried ";
    CommissionEmployee::print(); // code reuse
    cout << "; base salary: " << getBaseSalary();
}
