#ifndef CombiningClassTimeandClassDate_hpp
#define CombiningClassTimeandClassDate_hpp

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


class DateAndTime{
public:
	DateAndTime( int hh=0, int mm=0, int ss=0, int M=1, int d=1, int y=2000);
	void DATmain();
	// set functions
	void setTime( int, int, int ); // set hour, minute, second
	void setHour( int ); // set hour (after validation)
	void setMinute( int ); // set minute (after validation)
	void setSecond( int ); // set second (after validation)
	void setMday( int );
	void setMonth( int );
	void setYear( int );
	// get functions
	int getHour(); // return hour
	int getMinute(); // return minute
	int getSecond(); // return second
	int getMday();
	int getMonth();
	int getYear();

	//print functions
	void printUniversal(); // output time in universal-time format
	void printStandard(); // output time in standard-time format

	//other functions
	void tick();
	void nextDay();

private:
	bool isLeapYear(const int& );
	bool isMonthof31days(const int&);
	int MdayUpperbound(const int& , const int&);

	int year;
	int month;
	int day;
	int hour; // 0 - 23 (24-hour clock format)
	int minute; // 0 - 59
	int second; // 0 - 59
};

#endif // CombiningClassTimeandClassDate_hpp
