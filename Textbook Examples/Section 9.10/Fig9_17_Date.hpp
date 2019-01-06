// Fig. 9.17: Date.h
// Date class declaration. Member functions are defined in Date.cpp.
#ifndef DATE_H // prevent multiple inclusions of header file
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
	Date( int = 1, int = 1, int = 2000 ); // default constructor
	void print();
private:
	int month;
	int day;
	int year;
};
#endif //DATE_H
