//
//  Chapter9_Exercises.hpp
//  20170617 Chapter 9 Exercises
//
//  Created by ntueconRA on 2017/6/17.
//  Copyright © 2017年 Kai. All rights reserved.
//

#ifndef Chapter9_Exercises_hpp
#define Chapter9_Exercises_hpp

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

class Time9_4 {
public:
	Time9_4(); //initialize private data to current time
private:
	int year;
	int month;
	int mday;
	int hour;
	int minute;
	int second;
};

class complex{
public:
	complex(double =0, double =0); //constructor
	void add(complex );
	void subtract(complex);
	void printcomplex();
	
private:
	double realPart;
	double imiginaryPart;

};

class Rational{
public:
	Rational(int =0, int =1);
	void add(Rational);
	void subtract(Rational);
	void multiply(Rational);
	void divide(Rational);
	void printR();
	void printFl();
private:
	void simplified( int *, int *);
	int GCD(const int *, const int *);
	int numerator;
	int denominator;
};




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



//combine the above 2 classes Time and Date to become class DateandTime.
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


class Rectangle {
public:
	Rectangle( double =1, double =1 );
	Rectangle( double =0, double =0, double =1, double =0, double =0, double =1, double =1, double =1);
	void setLength( double * );
	void setWidth( double * );
	
	double getLength();
	double getWidth();
	
	double perimeter();
	double area();
private:
	
	bool isOutOfRange();
	bool isCommonLine();
	int typeDetermine();
	void AutoComputeLengthAndWidth(const int * const);
	double length=0;
	double width=0;
	double x1=0, y1=0, x2=0, y2=0, x3=0, y3=0, x4=0, y4=0;
};


class HugeInteger{
public:
	HugeInteger(); //constructor
	//I/O stream functions
	void input();
	void output();
	
	//arithmetic functions
	void add( HugeInteger *);
	void subtract( HugeInteger *);
	//compare functions
	bool isEqualTo( HugeInteger * );
	bool isNotEqualTo( HugeInteger *);
	bool isGreaterThan( HugeInteger *);
	bool isLessThan( HugeInteger *);
	bool isGreaterThanOrEqualTo(HugeInteger *);
	bool isLessThanOrEqualTo( HugeInteger * );
	bool isZero( HugeInteger *);
private:
	bool validStr( const string &);
	vector<char> bigNumVec;
	int lengthOfNum;
};








#endif /* Chapter9_Exercises_hpp */
