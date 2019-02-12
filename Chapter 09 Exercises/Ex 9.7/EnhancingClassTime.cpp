#include "EnhancingClassTime.hpp"
//Question 9.7 & 9.10

Time::Time( int hr, int min, int sec ){
	setTime( hr, min, sec ); // validate and set time
} // end Time constructor
void Time::setTime( int h, int m, int s ){
	setHour( h ); // set private field hour
	setMinute( m ); // set private field minute
	setSecond( s ); // set private field second
}
void Time::setHour( int h ){
	if (h >= 0 && h < 24)
		hour = h;
	else{
		hour = 0;
		cout << "Invalid input for hour, defaulted to be 0.\n";
	}
}
void Time::setMinute( int m ){
	if (m >= 0 && m < 60)
		minute = m;
	else {
		minute = 0;
		cout << "Invalid input for minute, deraulted to be 0.\n";
	}
}
void Time::setSecond( int s ){
	if (s >= 0 && s < 60)
		second = s;
	else {
		second = 0;
		cout << "Invalid input for second, defaulted to be 0.\n";
	}
}
int Time::getHour(){
	return hour;
}
int Time::getMinute(){
	return minute;
}
int Time::getSecond(){
	return second;
}
void Time::printUniversal(){ // print Time in universal-time format (HH:MM:SS)
	cout << setfill( '0' ) << setw( 2 ) << getHour() << ":" << setw( 2 )
	<< getMinute() << ":" << setw( 2 ) << getSecond();
}
void Time::printStandard(){ // print Time in standard-time format (HH:MM:SS AM or PM)
	cout << setfill('0') << setw(2) << ( ( getHour() == 0 || getHour() == 12 ) ? 12 : getHour() % 12 )
	<< ":" << setw( 2 ) << getMinute()
	<< ":" << setw( 2 ) << getSecond() << ( hour < 12 ? " AM" : " PM" );
}
void Time::tick(){
	second++;
	if ( second == 60 ){
		second = 0;
		minute++;
		if (minute == 60 ){
			minute = 0;
			hour++;
			if (hour == 24){
				hour = 0;
			}
		}
	}
}
void Time::Fig9_8to9_10main(){
	Time t1(23, 59, 59); //test for increment to next day
	Time t2(22, 59, 59); //test for increment to next hour
	Time t3(19, 30, 59); //test for increment to next minute

	t1.tick();
	t2.tick();
	t3.tick();

	t1.printUniversal();
	t1.printStandard();
	cout << endl << endl;
	t2.printUniversal();
	t2.printStandard();
	cout << endl << endl;
	t3.printUniversal();
	t3.printStandard();
	cout << endl << endl;
}
//end of Question 9.7 & 9.10

