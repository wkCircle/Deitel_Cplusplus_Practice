// Fig. 9.8: Time.h
// Time class containing a constructor with default arguments.
// Member functions defined in Time.cpp.
// prevent multiple inclusions of header file
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

class Time{// Time abstract data type definition
public:
	Time( int = 0, int = 0, int = 0 ); // default constructor
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
#endif //TIME_H
