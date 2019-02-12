#ifndef EnhancingClassDate_hpp
#define EnhancingClassDate_hpp


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

class Date{
public:
	Date( int = 1, int = 1, int = 2000 ); // default constructor
	void Fig9_17to9_19main();

	//set functions
	void setMday( int );
	void setMonth( int );
	void setYear( int );

	//get functions
	int getMday();
	int getMonth();
	int getYear();

	//print functions
	void print();
	//other functions
	void nextDay();
private:
	bool isLeapYear(const int& );
	bool isMonthof31days(const int&);
	int MdayUpperbound(const int& , const int&);
	int month;
	int day;
	int year;
};



#endif // EnhancingClassDate_hpp
