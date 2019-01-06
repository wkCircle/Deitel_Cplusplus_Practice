// Fig. 10.1: Time.h
// Time class definition with const member functions.
// Member functions defined in Time.cpp.
#ifndef TIME_H
#define TIME_H

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

class Time{
public:
	Time( int = 0, int = 0, int = 0 ); // default constructor
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
#endif // TIME_H
