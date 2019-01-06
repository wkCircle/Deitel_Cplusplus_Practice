// Fig. 13.16: SalariedEmployee.cpp
// SalariedEmployee class member-function definitions.
#include <iostream>
#include "SalariedEmployee.hpp" // SalariedEmployee class definition
using namespace std;

// constructor
SalariedEmployee::SalariedEmployee( const string &first, const string &last, const string &ssn,
                                            int month, int day, int year, double salary )
    : Employee( first, last, ssn, month, day, year )
{
    setWeeklySalary( salary );
} // end SalariedEmployee constructor

// set salary
void SalariedEmployee::setWeeklySalary( double salary )
{
    weeklySalary = ( salary < 0.0 ) ? 0.0 : salary;
} // end function setWeeklySalary

// return salary
double SalariedEmployee::getWeeklySalary() const
{
    return weeklySalary;
} // end function getWeeklySalary

// calculate earnings;
// override pure virtual function earnings in Employee
double SalariedEmployee::earnings() const
{
    return getWeeklySalary();
} // end function earnings

// print SalariedEmployee's information
void SalariedEmployee::print() const
{
    cout << "salaried employee: ";
    Employee::print(); // reuse abstract base-class print function
    cout << "\nweekly salary: " << getWeeklySalary();
} // end function print
