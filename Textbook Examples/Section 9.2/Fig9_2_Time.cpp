// Fig. 9.2
// Time constructor initializes each data member to zero.
// Ensures all Time objects start in a consistent state.
#include "Fig9_1_Time.hpp"

Time::Time(){
	hour = minute = second = 0;
}
// set new Time value using universal time; ensure that the data remains consistent by setting invalid values to zero
void Time::setTime( int h, int m, int s ){
	//validate hour, minute, and second.
	hour   = (h >= 0 && h < 24) ? h:0;
	minute = (m >= 0 && m < 60) ? m:0;
	second = (s >= 0 && s < 60) ? s:0;
}
void Time::printUniversal(){// print Time in universal-time format (HH:MM:SS)
	cout << setfill('0') << setw(2) << hour << ":" << setw( 2 ) << minute << ":" << setw( 2 ) << second;
}
void Time::printStandard(){// print Time in standard-time format (HH:MM:SS AM or PM)
	cout << ( ( hour == 0 || hour == 12 ) ? 12 : hour % 12 ) << ":" << setfill('0') << setw(2) << minute
	<< ":" << setw(2) << second << (  hour < 12 ?  " AM" : " PM" );
}


//....................................NOTE...............................................
//Once the class time has been defined,
//it can be used as a type in object, array, pointer, and reference declarations as follows:
//Time sunset; // object of type Time
//Time arrayOfTimes[ 5 ]; // array of 5 Time objects
//Time &dinnerTime = sunset; // reference to a Time object
//Time *timePtr = &dinnerTime; // pointer to a Time object
//....................................NOTE...............................................

