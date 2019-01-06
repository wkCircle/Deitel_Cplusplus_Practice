// Fig. 13.4: BasePlusCommissionEmployee.cpp
// Class BasePlusCommissionEmployee member-function definitions.
#include "Fig13_3&9_BasePlusCommissionEmployee.hpp"
BasePlusCommissionEmployee::BasePlusCommissionEmployee( const string &first, const string &last, const string &ssn,
        double sales, double rate, double salary )
    : CommissionEmployee( first, last, ssn, sales, rate )
{
    setBaseSalary( salary );
}
void BasePlusCommissionEmployee::setBaseSalary( double salary ) { baseSalary = ( salary < 0.0 ) ? 0.0 : salary; }
double BasePlusCommissionEmployee::getBaseSalary() const { return baseSalary; }
double BasePlusCommissionEmployee::earnings() const { return getBaseSalary() + CommissionEmployee::earnings(); }
void BasePlusCommissionEmployee::print() const
{
    cout << "base-salaried ";
    CommissionEmployee::print();/**<invoke CommissionEmployee's print function*/
    cout << "\nbase salary: " << getBaseSalary();
}
