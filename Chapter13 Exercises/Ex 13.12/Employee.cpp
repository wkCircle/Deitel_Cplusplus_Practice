
// Fig. 13.14: Employee.cpp
// Abstract-base-class Employee member-function definitions.
// Note: No definitions are given for pure virtual functions.
#include <iostream>
#include "Employee.hpp" // Employee class definition
using namespace std;

// constructor
Employee::Employee( const string &first, const string &last, const string &ssn,
                                                                int month, int day, int year )
    : firstName( first ), lastName( last ), socialSecurityNumber( ssn ), birthDate(month, day, year)
{
    // empty body
}

// set first name
void Employee::setFirstName( const string &first )
{
    firstName = first;
}

// return first name
string Employee::getFirstName() const
{
    return firstName;
}

// set last name
void Employee::setLastName( const string &last )
{
    lastName = last;
}

// return last name
string Employee::getLastName() const
{
    return lastName;
}

// set social security number
void Employee::setSocialSecurityNumber( const string &ssn )
{
    socialSecurityNumber = ssn; // should validate
}

// return social security number
string Employee::getSocialSecurityNumber() const
{
    return socialSecurityNumber;
}

Date Employee::getbirthDate() const
{
    return birthDate;
}

// print Employee's information (virtual, but not pure virtual)
void Employee::print() const
{
    cout << getFirstName() << ' ' << getLastName() << "\nsocial security number: " << getSocialSecurityNumber();
}
