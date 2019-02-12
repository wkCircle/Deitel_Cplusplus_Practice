#ifndef EnhancingClassTime_hpp
#define EnhancingClassTime_hpp

#include <cstdio>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;

class Time{
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

	//print functions
	void printUniversal(); // output time in universal-time format
	void printStandard(); // output time in standard-time format

	//other functions
	void tick();
private:
	int hour; // 0 - 23 (24-hour clock format)
	int minute; // 0 - 59
	int second; // 0 - 59
}; // end class Time

#endif // EnhancingClassTime_hpp
