


#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cstdio>
#include <typeinfo>
#include <initializer_list>
#include <algorithm> //random_shuffle();


using namespace std;

class Date{
public:
	static const int monthsPerYear = 12;
	static const int daysPerMonth[ monthsPerYear + 1 ];
	static const string MonthName[monthsPerYear+1 ];
	Date ( int = 1, int = 1, int = 1900 ); //format corr. to b
	Date ( int = 1, int = 1990); //format corr. to a
	Date ( string = "Jan uary", int =1, int =1900); //format corr. to c
	Date ( struct tm );
	void print( const char & ) const ;
	~Date();
private:
	int month; // 1-12 (January-December)
	int day; // 1-31 based on month
	int year; // any year
	// utility function to check if day is proper for month and year
	int checkDay( int ) const;
};

