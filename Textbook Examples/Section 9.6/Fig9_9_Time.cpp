// Fig. 9.9: Time.cpp
// Member-function definitions for class Time.
#include "Fig9_8_Time.hpp"


// Time constructor initializes each data member to zero;
// ensures that Time objects start in a consistent state
Time::Time( int hr, int min, int sec ){
	setTime( hr, min, sec ); // validate and set time
} // end Time constructor
// set new Time value using universal time; ensure that the data remains consistent by setting invalid values to zero
void Time::setTime( int h, int m, int s ){
	setHour( h ); // set private field hour
	setMinute( m ); // set private field minute
	setSecond( s ); // set private field second
} // end function setTime
void Time::setHour( int h ){
	hour=(h>=0&&h< 24)?h:0;//validatehour
}// end function setHour
void Time::setMinute( int m ){
	minute = (m >= 0 && m < 60)? m : 0;//validateminute
} // end function setMinute
void Time::setSecond( int s ){
	second = (s >= 0 && s < 60)? s : 0;//validateminute
} // end function setMinute
int Time::getHour(){
	return hour;
} // end function getHour
int Time::getMinute(){
	return minute;
} // end function getMinute
int Time::getSecond(){
	return second;
} // end function getSecond
// print Time in universal-time format (HH:MM:SS)
void Time::printUniversal(){
	cout << setfill( '0' ) << setw( 2 ) << getHour() << ":" << setw( 2 )
	<< getMinute() << ":" << setw( 2 ) << getSecond();
} // end function printUniversal
// print Time in standard-time format (HH:MM:SS AM or PM)
void Time::printStandard(){
	cout << ( ( getHour() == 0 || getHour() == 12 ) ? 12 : getHour() % 12 )
	<< ":" << setfill( '0' ) << setw( 2 ) << getMinute()
	<< ":" << setw( 2 ) << getSecond() << ( hour < 12 ? " AM" : " PM" );
} // end function printStandard
