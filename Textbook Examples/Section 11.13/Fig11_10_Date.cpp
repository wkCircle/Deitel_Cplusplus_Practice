// Fig. 11.10: Date.cpp
// Date class member- and friend-function definitions.
// initialize static member; one classwide copy
#include "Fig11_9_Date.hpp"
const int Date::days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// Date constructor
Date::Date( int m, int d, int y ){
	setDate( m, d, y );
}

// set month, day and year
void Date::setDate( int mm, int dd, int yy ){
	month=(mm>=1&&mm<=12)?mm:1;
	year=(yy>=1900&&yy<=2100)?yy:1900;
	//test for a leap year
	if ( month == 2 && leapYear( year ) )
		day=(dd>=1&&dd<=29)?dd:1;
	else
		day = ( dd >= 1 && dd <= days[ month ] ) ? dd : 1;
}

// overloaded prefix increment operator
Date &Date::operator++() {
	helpIncrement(); // increment date
	return *this; // reference return to create an lvalue
}
// overloaded postfix increment operator; note that the dummy integer parameter does not have a parameter name
Date Date::operator++( int ){
	Date temp = *this; // hold current state of object
	helpIncrement();
	// return unincremented, saved, temporary object
	return temp; // value return; not a reference return
}

const Date &Date::operator+=( int additionalDays ){
	for ( int i = 0; i < additionalDays; i++ )
		helpIncrement();
	return *this; // enables cascading
}
bool Date::leapYear( int testYear ){
	if ( testYear % 400 == 0 || ( testYear % 100 != 0 && testYear % 4 == 0 ) )
		return true;
	else
		return false;
}
bool Date::endOfMonth( int testDay ) const {
	if ( month == 2 && leapYear( year ) )
		return testDay == 29;
	else
		return testDay == days[ month ];
}
void Date::helpIncrement() {
	//days in not end of month
	if ( !endOfMonth( day ) )
		day++;
	else
		if(month<12){//day is end of month and month < 12
			month++; // increment
			day = 1;
		}
		else { // last day of year
			year++;
			month = 1;
			day = 1;
		}
}
// overloaded output operator
ostream &operator<<( ostream &output, const Date &d ){
	static string monthName[ 13 ] = { "", "January", "February", "March", "April", "May", "June",
									"July", "August", "September", "October", "November", "December" };
	output << monthName[ d.month ] << ' ' << d.day << ", " << d.year;
	return output; // enables cascading
}


/**<小結: 1. ++x & x++ overloading 方式不同，prefix: Date &operator++(); postfix: Date operator++( int );
 	2. Any single-argument constructor can be used by the compiler to perform an implicit conversion--the type received by the
	   constructor is converted to an object of the class in which the constructor is defined
 */

