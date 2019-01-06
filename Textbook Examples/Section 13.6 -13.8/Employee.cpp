
// Fig. 13.14: Employee.cpp
// Abstract-base-class Employee member-function definitions.
// Note: No definitions are given for pure virtual functions.
#include <iostream>
#include "Employee.hpp" // Employee class definition
using namespace std;

// constructor
Employee::Employee( const string &first, const string &last,
const string &ssn )
: firstName( first ), lastName( last ), socialSecurityNumber( ssn )
{
    // empty body
} // end Employee constructor

// set first name
void Employee::setFirstName( const string &first )
{
    firstName = first;
} // end function setFirstName

// return first name
string Employee::getFirstName() const
{
    return firstName;
} // end function getFirstName

// set last name
void Employee::setLastName( const string &last )
{
    lastName = last;
} // end function setLastName

// return last name
string Employee::getLastName() const
{
    return lastName;
} // end function getLastName

// set social security number
void Employee::setSocialSecurityNumber( const string &ssn )
{
    socialSecurityNumber = ssn; // should validate
} // end function setSocialSecurityNumber

// return social security number
string Employee::getSocialSecurityNumber() const
{
    return socialSecurityNumber;
} // end function getSocialSecurityNumber

// print Employee's information (virtual, but not pure virtual)
void Employee::print() const
{
    cout << getFirstName() << ' ' << getLastName() << "\nsocial security number: " << getSocialSecurityNumber();
} // end function print
