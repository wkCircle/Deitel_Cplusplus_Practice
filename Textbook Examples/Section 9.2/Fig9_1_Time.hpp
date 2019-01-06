// Fig. 9.1: Time.h
//Declaration of class time.
//member functions on defined in time.cpp (here in TextBookExamples.cpp)

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

class Time {
public:
	Time(); // constructor
	void setTime( int, int, int ); // set hour, minute and second
	void printUniversal(); // print time in universal-time format
	void printStandard(); // print time in standard-time format
private:
	//All are initialized in constructor.
	int hour; // 0 - 23 (24-hour clock format)
	int minute; // 0 - 59
	int second; // 0 - 59
}; // end class Time

#endif // TIME_H



/**<
	1. The #ifndefine...#define...#endif is called preprocessor wrappter, which prevents the code between #ifnedef~#endif from being included if the name TIME_H has been defined.
	2. Defining a member function inside the class definition inlines the member function (if the compiler chooses to do so). This can improve performance.
 >**/
