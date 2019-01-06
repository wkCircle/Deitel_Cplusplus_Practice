// Fig. 13.1: CommissionEmployee.h (non-virtual) + Fig. 13.8 (virtual version)
// CommissionEmployee class definition represents a commission employee.
#ifndef COMMISSION_H
#define COMMISSION_H


#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <typeinfo>
#include <ctime>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

class CommissionEmployee {
public:
    CommissionEmployee( const string &, const string &, const string &, double = 0.0, double = 0.0 );

    void setFirstName( const string & );
    string getFirstName() const;
    void setLastName( const string & );
    string getLastName() const;
    void setSocialSecurityNumber( const string & );
    string getSocialSecurityNumber() const;
    void setGrossSales( double );
    double getGrossSales() const;
    void setCommissionRate( double );
    double getCommissionRate() const;

    /**< Comment/Uncomment key word 'virtual' to switch between non-virtual or virtual version. */
    virtual double earnings() const;
    virtual void print() const; // print CommissionEmployee object
private:
    string firstName;
    string lastName;
    string socialSecurityNumber;
    double grossSales; // gross weekly sales
    double commissionRate;
};

#endif /*COMMISSION_H*/
