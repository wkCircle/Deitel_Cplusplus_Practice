// Ex12.3
#ifndef CompositionasanAlternativetoInheritance_hpp
#define CompositionasanAlternativetoInheritance_hpp


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

// Fig. 12.22: CommissionEmployee.h
// CommissionEmployee class definition represents a commission employee.
class CommissionEmployee { /**<Base Class>**/
public:
    CommissionEmployee( const string &, const string &, const string &, double = 0.0, double = 0.0 );
    ~CommissionEmployee(); // destructor

    void setFirstName( const string & ); // set first name
    string getFirstName() const;
    void setLastName( const string & ); // set last name
    string getLastName() const;
    void setSocialSecurityNumber( const string & ); // set SSN
    string getSocialSecurityNumber() const;
    void setGrossSales( double ); // set gross sales amount
    double getGrossSales() const;
    void setCommissionRate( double ); // set commission rate
    double getCommissionRate() const;

    double earnings() const; // calculate earnings
    void print() const; // print CommissionEmployee object
private:
    string firstName;
    string lastName;
    string socialSecurityNumber;
    double grossSales; // gross weekly sales
    double commissionRate; // commission percentage
};


/**<Case started: Inheriatance approach from textbook>**/
//// Fig. 12.24: BasePlusCommissionEmployee.h
//// BasePlusCommissionEmployee class derived from class CommissionEmployee.
//class BasePlusCommissionEmployee : public CommissionEmployee { //public inheritance
//public:
//    BasePlusCommissionEmployee( const string &, const string &, const string &, double = 0.0, double = 0.0, double = 0.0 );
//    ~BasePlusCommissionEmployee();
//
//    void setBaseSalary( double ); // set base salary
//    double getBaseSalary() const;
//    double earnings() const; // calculate earnings
//    void print() const; // print BasePlusCommissionEmployee object
//private:
//    double baseSalary; // base salary
//};
/**<Case finished: Inheritance approach from textbook>**/
/**<Case started: Composition approach for exercise 12.3>**/
class BasePlusCommissionEmployee{
public:
    BasePlusCommissionEmployee( const string &, const string &, const string &, double = 0.0, double = 0.0, double = 0.0 );
    ~BasePlusCommissionEmployee();

    ///Following comments explain the difference between inheritance method and composition method
    //Below declarations reuse memebers in class CommissionEmployee. All codes in each function body are the same as the originate.
    //If one uses Inheritance method, then codes shown in Block1 can be deleted.
    //But if one uses composition method, then codes shown in Block1 are required.
    // Block1
    void setFirstName( const string & ); // set first name
    string getFirstName() const;
    void setLastName( const string & ); // set last name
    string getLastName() const;
    void setSocialSecurityNumber( const string & ); // set SSN
    string getSocialSecurityNumber() const;
    void setGrossSales( double ); // set gross sales amount
    double getGrossSales() const;
    void setCommissionRate( double ); // set commission rate
    double getCommissionRate() const;
    // end of Block1

    void setBaseSalary( double ); // set base salary
    double getBaseSalary() const;
    double earnings() const; // calculate earnings
    void print() const; // print BasePlusCommissionEmployee object
private:
    /**<composition method: its key idea is to reuse other pre-defined functions by leveraging
        pointers.>**/
    CommissionEmployee *employeeObjPtr;
    double baseSalary; // base salary
};
/**<Case finished: Composition approach for exercise 12.3>**/

#endif // CompositionasanAlternativetoInheritance_hpp
