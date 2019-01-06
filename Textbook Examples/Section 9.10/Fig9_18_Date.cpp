// Fig. 9.18: Date.cpp
// Date class member-function definitions.
#include "Fig9_17_Date.hpp"

// Date constructor (should do range checking)
Date::Date( int m, int d, int y ){
	month = m;
	day = d;
	year = y;
}
void Date::print(){// print Date in the format mm/dd/yyyy
	cout << month << '/' << day << '/' << year;
}
