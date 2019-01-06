// Fig. 9.14: Time.h
// Time class declaration.
// Member functions defined in Time.cpp
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
#endif //TIME_H
