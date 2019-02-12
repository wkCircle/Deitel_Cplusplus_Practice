// Fig. 13.20: CommissionEmployee.cpp
// CommissionEmployee class member-function definitions.
#include <iostream>
#include "CommissionEmployee.hpp" // CommissionEmployee class definition
using namespace std;

// constructor
CommissionEmployee::CommissionEmployee( const string &first, const string &last, const string &ssn,
                                                    int month, int day, int year, double sales, double rate )
    : Employee( first, last, ssn, month, day, year )
{
    setGrossSales( sales );
    setCommissionRate( rate );
} // end CommissionEmployee constructor

// set commission rate
void CommissionEmployee::setCommissionRate( double rate )
{
    commissionRate = ( ( rate > 0.0 && rate < 1.0 ) ? rate : 0.0 );
} // end function setCommissionRate

// return commission rate
double CommissionEmployee::getCommissionRate() const
{
    return commissionRate;
} // end function getCommissionRate

// set gross sales amount
void CommissionEmployee::setGrossSales( double sales )
{
    grossSales = ( ( sales < 0.0 ) ? 0.0 : sales );
} // end function setGrossSales
    // return gross sales amount
double CommissionEmployee::getGrossSales() const
{
    return grossSales;
} // end function getGrossSales

// calculate earnings; override pure virtual function earnings in Employee
double CommissionEmployee::earnings() const
{
    return getCommissionRate() * getGrossSales();
} // end function earnings

// print CommissionEmployee's information
void CommissionEmployee::print() const
{
    cout << "commission employee: ";
    Employee::print(); // code reuse
    cout << "\ngross sales: " << getGrossSales() << "; commission rate: " << getCommissionRate();
} // end function print
