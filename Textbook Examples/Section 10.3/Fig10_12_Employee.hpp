// Fig. 10.12: Employee.h
// Employee class definition showing composition. Member functions defined in Employee.cpp.
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Fig10_10_Date.hpp"
class Employee{
public:
	Employee( const string &, const string &, const Date &, const Date & );
	void print() const;
	~Employee(); // provided to confirm destruction order

private:
	string firstName; // composition: member object
	string lastName; // composition: member object
	const Date birthDate; // composition: member object
	const Date hireDate; // composition: member object

}; // end class Employee
#endif // EMPLOYEE_H
