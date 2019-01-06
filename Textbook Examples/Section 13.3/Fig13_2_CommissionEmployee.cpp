// Fig. 13.2: CommissionEmployee.cpp
// Class CommissionEmployee member-function definitions.
#include "Fig13_1&8_CommissionEmployee.hpp" // CommissionEmployee class definition
CommissionEmployee::CommissionEmployee( const string &first, const string &last, const string &ssn, double sales, double rate )
    : firstName( first ), lastName( last ), socialSecurityNumber( ssn )
{
        setGrossSales( sales ); // validate and store gross sales
        setCommissionRate( rate ); // validate and store commission rate
}
void CommissionEmployee::setFirstName( const string &first ) { firstName = first; }
string CommissionEmployee::getFirstName() const { return firstName; }
void CommissionEmployee::setLastName( const string &last ){ lastName = last; }
string CommissionEmployee::getLastName() const { return lastName; }
void CommissionEmployee::setSocialSecurityNumber( const string &ssn ){ socialSecurityNumber = ssn; }
string CommissionEmployee::getSocialSecurityNumber() const { return socialSecurityNumber; }
void CommissionEmployee::setGrossSales( double sales ) { grossSales = ( sales < 0.0 ) ? 0.0 : sales; }
double CommissionEmployee::getGrossSales() const { return grossSales; }
void CommissionEmployee::setCommissionRate( double rate ) { commissionRate = ( rate > 0.0 && rate < 1.0 ) ? rate : 0.0; }
double CommissionEmployee::getCommissionRate() const { return commissionRate; }
double CommissionEmployee::earnings() const { return getCommissionRate() * getGrossSales(); }

void CommissionEmployee::print() const
{
    cout << "commission employee: " << getFirstName() << ' ' << getLastName()
         << "\nsocial security number: " << getSocialSecurityNumber()
         << "\ngross sales: " << getGrossSales()
         << "\ncommission rate: " << getCommissionRate();
}
