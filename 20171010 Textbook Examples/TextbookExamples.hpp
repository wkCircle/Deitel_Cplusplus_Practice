//
//  TextBookExamples.hpp
//  20170331 TextBookExamples
//
//  Created by ntueconRA on 2017/5/15.
//  Copyright © 2017年 Kai. All rights reserved.
//

#ifndef TextBookExamples_hpp
#define TextBookExamples_hpp

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

class Egg{
public:
	void SearchingArraysWithLinearSearch();
	void SearchingArraysWithInsertionSort();
	void introToVector();
	void PointerOperators();
	void Fig8_7();
	void Fig8_10();
	void Fig8_11();
	void Fig8_12();
	void Fig8_14();
	void RelationshipBetweenPointersandArrays();
	void MultiSortingUsingFunctionPointers();
};

class Self{
public:
	void ComaperChPointerArrwithStringBrr();
};


// Fig. 9.1: Time.h
//Declaration of class time.
//member functions on defined in time.cpp (here in TextBookExamples.cpp)

// prevent multiple inclusions of header file
#ifndef TIME_H
#define TIME_H

// Time class definition
class Time {
public:
	Time(); // constructor
	void Fig9_3main();
	void setTime( int, int, int ); // set hour, minute and second
	void printUniversal(); // print time in universal-time format
	void printStandard(); // print time in standard-time format
private:
	//All are initialized in constructor.
	int hour; // 0 - 23 (24-hour clock format)
	int minute; // 0 - 59
	int second; // 0 - 59
}; // end class Time

#endif
/**<
	1. The #ifndefine...#define...#endif is called preprocessor wrappter, which prevents the code between #ifnedef~#endif from being included if the name TIME_H has been defined.
	2. Defining a member function inside the class definition inlines the member function (if the compiler chooses to do so). This can improve performance.
 >**/

//Fig 9.5  SalesPerson.h
// SalesPerson class definition.
// Member functions defined in SalesPerson.cpp.
#ifndef SALESP_H
#define SALESP_H
class SalesPerson{
public:
	static const int monthsPerYear = 12; // months in one year
	SalesPerson(); // constructor
	void getSalesFromUser(); // input sales from keyboard
	void setSales( int, double ); // set sales for a specific month
	void printAnnualSales(); // summarize and print sales
private:
	double totalAnnualSales(); // **prototype for utility function
	double sales[ monthsPerYear ]; // 12 monthly sales figures
}; // end class SalesPerson
#endif

// Fig. 9.8: Time.h
// Time class containing a constructor with default arguments.
// Member functions defined in Time.cpp.
// prevent multiple inclusions of header file
//#ifndef TIME_H
//#define TIME_H
// Time abstract data type definition
class TimeFig9_8{
public:
	TimeFig9_8( int = 0, int = 0, int = 0 ); // default constructor
	void Fig9_8to9_10main();
	// set functions
	void setTime( int, int, int ); // set hour, minute, second
	void setHour( int ); // set hour (after validation)
	void setMinute( int ); // set minute (after validation)
	void setSecond( int ); // set second (after validation)

	// get functions
	int getHour(); // return hour
	int getMinute(); // return minute
	int getSecond(); // return second
	void printUniversal(); // output time in universal-time format
	void printStandard(); // output time in standard-time format

private:
	int hour; // 0 - 23 (24-hour clock format)
	int minute; // 0 - 59
	int second; // 0 - 59
}; // end class Time
//#endif

// Fig. 9.11: CreateAndDestroy.h
// CreateAndDestroy class definition.
// Member functions defined in CreateAndDestroy.cpp.
#ifndef CREATE_H
#define CREATE_H
class CreateAndDestroy{
public:
	void Fig9_11to9_13main();
	CreateAndDestroy( int, string ); // constructor
	~CreateAndDestroy(); // destructor

private:
	int objectID; // ID number for object
	string message; // message describing object
}; // end class CreateAndDestroy
#endif




// Fig. 9.14: Time.h
// Time class declaration.
// Member functions defined in Time.cpp
// prevent multiple inclusions of header file
//#ifndef TIME_H
//#define TIME_H
class Time9_14
{
public:
	Time9_14( int = 0, int = 0, int = 0 );
	void Fig9_14to9_16main();
	void setTime( int, int, int );
	int getHour();
	int &badSetHour( int ); // DANGEROUS reference return
private:
	int hour;
	int minute;
	int second;
}; // end class Time
//#endif


// Fig. 9.17: Date.h
// Date class declaration. Member functions are defined in Date.cpp.
#ifndef DATE_H // prevent multiple inclusions of header file
#define DATE_H
class Date9_17{
public:
	Date9_17( int = 1, int = 1, int = 2000 ); // default constructor
	void Fig9_17to9_19main();
	void print();
private:
	int month;
	int day;
	int year;
};
#endif


// Fig. 10.1: Time.h
// Time class definition with const member functions.
// Member functions defined in Time.cpp.
//#ifndef TIME_H
//#define TIME_H
class Time10_3{
public:
	Time10_3( int = 0, int = 0, int = 0 ); // default constructor
	void Fig10_1to10_3main();
	// set functions
	void setTime( int, int, int ); // set time
	void setHour( int ); // set hour
	void setMinute( int ); // set minute
	void setSecond( int ); // set second
	// get functions (normally declared const)
	int getHour() const; // return hour
	int getMinute() const; // return minute
	int getSecond() const; // return second
	// print functions (normally declared const)
	void printUniversal() const; // print universal time
	void printStandard(); // print standard time (should be const)
private:
	int hour; // 0 - 23 (24-hour clock format)
	int minute; // 0 - 59
	int second; // 0 - 59
};
//#endif // TIME_H



// Fig. 10.4: Increment.h
// Definition of class Increment.
#ifndef INCREMENT_H
#define INCREMENT_H
class Increment{
public:
	Increment( int c = 0, int i = 1 ); // default constructor
	void Fig10_4to10_6main();
	void addIncrement(){
		count += increment;
	}
	void print() const; // prints count and increment

private:
	int count;
	const int increment; // const data member
};
#endif // INCREMENT_H



// Fig. 10.10: Date.h
// Date class definition; Member functions defined in Date.cpp
//#ifndef DATE_H
//#define DATE_H
class Date10_10{
public:
	static const int monthsPerYear = 12; // number of months in a year

	Date10_10( int = 1, int = 1, int = 1900 ); // default constructor
	void print() const; // print date in month/day/year format
	~Date10_10(); // provided to confirm destruction order

private:
	int month; // 1-12 (January-December)
	int day; // 1-31 based on month
	int year; // any year

	int checkDay( int ) const;
};
//#endif // DATE_H
// Fig. 10.12: Employee.h
// Employee class definition showing composition. Member functions defined in Employee.cpp.
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
//#include "Date.h" // include Date class definition
class Employee{
public:
	Employee( const string &, const string &, const Date10_10 &, const Date10_10 & );
	void print() const;
	~Employee(); // provided to confirm destruction order

private:
	string firstName; // composition: member object
	string lastName; // composition: member object
	const Date10_10 birthDate; // composition: member object
	const Date10_10 hireDate; // composition: member object

}; // end class Employee
#endif // EMPLOYEE_H

// Fig. 10.20: Employee.h
// Employee class definition with a static data member to
// track the number of Employee objects in memory
//#ifndef EMPLOYEE_H
//#define EMPLOYEE_H
class Employee10_20{
public:
	Employee10_20( const string &, const string & );
	~Employee10_20();
	string getFirstName() const;
	string getLastName() const;
	static int getCount(); // return number of objects instantiated
private:
	string firstName;
	string lastName;
	static int count; // number of objects instantiated
};
//#endif // EMPLOYEE_H


// Fig. 11.3: PhoneNumber.h
// PhoneNumber class definition
#ifndef PHONENUMBER_H
#define PHONENUMBER_H
class PhoneNumber {
	friend ostream & operator<<( ostream &, const PhoneNumber & );
	friend istream & operator>>( istream &, PhoneNumber & );
public:
	void Fig11_3to11_5main(PhoneNumber &phone);
private:
	string areaCode; // 3-digit area code
	string exchange; // 3-digit exchange
	string line; // 4-digit line
};
#endif

// Fig. 11.6: Array.h
// Array class definition with overloaded operators.
#ifndef ARRAY_H
#define ARRAY_H
class Array {
	friend ostream & operator<<( ostream &, const Array & );
	friend istream & operator>>( istream &, Array & );
public:
	Array( int = 10 );//compiler will also regard the single argument constructor as a conversion constructor.(c.f. Fig11.13)
	Array( const Array & ); // copy constructor
	~Array();
	void Fig11_6to11_8main();
	void Fig11_13main();
	int getSize() const;


	bool operator==( const Array & ) const; // equality operator
	bool operator!=( const Array &right ) const { // inequality operator; returns opposite of == operato
		return ! ( *this == right ); // invokes Array::operator==
	}
	int &operator[]( int ); // subscript operator for non-const objects returns modifiable lvalue
	int operator[]( int ) const; // subscript operator for const objects returns rvalue
private:
	const Array & operator=( const Array & ); // assignment operator
	int size; // pointer-based array size
	int *ptr; // pointer to first element of pointer-based array
};
#endif // ARRAY_H

// Fig. 11.9: Date.h
// Date class definition with overloaded increment operators.
class Date {
	friend ostream &operator<<( ostream &, const Date & );
public:
	Date( int m = 1, int d = 1, int y = 1900 ); // default constructor
	void Fig11_9to11_11main();

	void setDate( int, int, int ); // set month, day, year
	Date &operator++(); /*<< prefix increment operator */
	Date operator++( int ); /*<< postfix increment operator */
	const Date &operator+=( int ); // add days, modify object
	static bool leapYear( int ); // is date in a leap year?
	bool endOfMonth( int ) const; // is date at the end of month?
private:
	int month;
	int day;
	int year;
	static const int days[]; // array of days per month
	void helpIncrement(); // utility function for incrementing date
};


// Fig. 11.16: Implementation.h
// Implementation class definition.
class Implementation {
public:
	Implementation( int v ) : value( v ) {}// initialize value with v
	void setValue( int v ){ value = v; }
	int getValue() const {	return value; }
private:
	int value; // data that we would like to hide from the client
};










/**< Chpater 12 的例子請直接看習題的例子，重點已囊括在其中。*/










// Fig. 13.1: CommissionEmployee.h (non-virtual) + Fig. 13.8 (virtual version)
// CommissionEmployee class definition represents a commission employee.
#ifndef COMMISSION_H
#define COMMISSION_H
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

    /**< Comment/Uncomment key word virtual to switch between non-virtual or virtual version. */
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


// Fig. 13.3: BasePlusCommissionEmployee.h (non-virtual) + Fig. 13.9 (virtual version)
// BasePlusCommissionEmployee class derived from classvCommissionEmployee.
#ifndef BASEPLUS_H
#define BASEPLUS_H
//#include "CommissionEmployee.h" // CommissionEmployee class declaration
class BasePlusCommissionEmployee : public CommissionEmployee
{
public:
    BasePlusCommissionEmployee( const string &, const string &, const string &, double = 0.0, double = 0.0, double = 0.0 );

    void setBaseSalary( double );
    double getBaseSalary() const;

    //Implicitly becomes virtual function if base-class function is virtual.
    double earnings() const;
    void print() const; // print BasePlusCommissionEmployee object
private:
    double baseSalary;
};

void  Fig13_1to13_10main(); //global function
#endif /*BASEPLUS_H*/
/**<結果差異: 如果更換為virtual version的話，執行結果應為 base-class ptr 指向 dervied-class obj 的case會從
    多個 "base-salaried" commission employee: Bob Lewis
    以及多一行 "base salary: 300.00"*/




#endif /* TextBookExamples_hpp */


























