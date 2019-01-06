// Fig. 10.20: Employee.h
// Employee class definition with a static data member to
// track the number of Employee objects in memory
#ifndef EMPLOYEE_H
#define EMPLOYEE_H


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


class Employee{
public:
	Employee( const string &, const string & );
	~Employee();
	string getFirstName() const;
	string getLastName() const;
	static int getCount(); // return number of objects instantiated
private:
	string firstName;
	string lastName;
	static int count; // number of objects instantiated
};
#endif // EMPLOYEE_H
