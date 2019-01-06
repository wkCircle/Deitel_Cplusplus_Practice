// Fig. 9.15: Time.cpp
// Time class member-function definitions.
#include "Fig9_14_Time.hpp"

// constructor function to initialize private data; calls member function
// setTime to set variables; default values are 0 (see class definition)
Time9_14::Time9_14( int hr, int min, int sec ){
	setTime( hr, min, sec );
}
void Time9_14::setTime( int h, int m, int s ){
	hour = ( h >= 0 && h < 24 ) ? h : 0; // validate hour
	minute = ( m >= 0 && m < 60 ) ? m : 0; // validate minute
	second = ( s >= 0 && s < 60 ) ? s : 0; // validate second
}
int Time9_14::getHour(){
	return hour;
}
// POOR PRACTICE: Returning a reference to a private data member.
int &Time9_14::badSetHour( int hh ){
	hour = ( hh >= 0 && hh < 24 ) ? hh : 0;
	return hour; // DANGEROUS reference return
} // end function badSetHour
