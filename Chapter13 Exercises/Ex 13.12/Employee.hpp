// Fig. 13.13: Employee.h
// Employee abstract base class.
#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include "Date.hpp"
#include <string> // C++ standard string class
using namespace std;

class Employee {
public:
    Employee( const string &, const string &, const string &, int, int, int );

    void setFirstName( const string & );
    string getFirstName() const;
    void setLastName( const string & );
    string getLastName() const;
    void setSocialSecurityNumber( const string & );
    string getSocialSecurityNumber() const;

    Date getbirthDate() const;

    // pure virtual function makes Employee abstract base class
    virtual double earnings() const = 0; // pure virtual
    virtual void print() const; // virtual

private:
    Date birthDate;
    string firstName;
    string lastName;
    string socialSecurityNumber;
}; // end class Employee
#endif // EMPLOYEE_HPP
