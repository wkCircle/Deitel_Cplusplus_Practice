// Fig. 10.13: Employee.cpp
// Employee class member-function definitions.
#include "Fig10_12_Employee.hpp"
#include "Fig10_10_Date.hpp"



// constructor uses member initializer list to pass initializer values to constructors of member objects
Employee::Employee( const string &first, const string &last, const Date &dateOfBirth, const Date &dateOfHire )
: firstName( first ), // initialize firstName
lastName( last ), // initialize lastName
birthDate( dateOfBirth ), // initialize birthDate
hireDate( dateOfHire ) // initialize hireDate
{
	// output Employee object to show when constructor is called
	cout << "Employee object constructor: " << firstName << ' ' << lastName << endl;
}
void Employee::print() const {
	cout << lastName << ", " << firstName << " Hired: ";
	hireDate.print();
	cout << " Birthday: ";
	birthDate.print();
	cout << endl;
}
Employee::~Employee() {
	cout << "Employee object destructor: " << lastName << ", " << firstName << endl;
}
