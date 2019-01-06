// Fig. 13.13: Employee.h
// Employee abstract base class.
#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <string> // C++ standard string class
using namespace std;

class Employee{
public:
    Employee( const string &, const string &, const string & );
    void setFirstName( const string & ); // set first name
    string getFirstName() const; // return first name
    void setLastName( const string & ); // set last name
    string getLastName() const; // return last name
    void setSocialSecurityNumber( const string & ); // set SSN
    string getSocialSecurityNumber() const; // return SSN
    // pure virtual function makes Employee abstract base class
    virtual double earnings() const = 0; // pure virtual
    virtual void print() const; // virtual
private:
    string firstName;
    string lastName;
    string socialSecurityNumber;
}; // end class Employee
#endif // EMPLOYEE_HPP
