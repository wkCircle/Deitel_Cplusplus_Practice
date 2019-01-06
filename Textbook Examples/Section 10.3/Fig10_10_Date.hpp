// Fig. 10.10: Date.h
// Date class definition; Member functions defined in Date.cpp
#ifndef DATE_H
#define DATE_H


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


class Date{
public:
	static const int monthsPerYear = 12; // number of months in a year

	Date( int = 1, int = 1, int = 1900 ); // default constructor
	void print() const; // print date in month/day/year format
	~Date(); // provided to confirm destruction order

private:
	int month; // 1-12 (January-December)
	int day; // 1-31 based on month
	int year; // any year

	int checkDay( int ) const;
};
#endif // DATE_H
