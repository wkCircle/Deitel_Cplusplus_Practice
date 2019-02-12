#include "CombiningClassTimeandClassDate.hpp"


//Question 9.9
DateAndTime::DateAndTime( int hh, int mm, int ss, int M, int d, int y){
	setTime(hh, mm, ss);
	setYear(y);
	setMonth(M);
	setMday(d);
}
void DateAndTime::setTime( int hh, int mm, int ss ){
	setHour( hh ); // set private field hour
	setMinute( mm ); // set private field minute
	setSecond( ss ); // set private field second
}
void DateAndTime::setHour( int hh ){
	hour = (hh >= 0 && hh < 24)? hh : 0 ;//validatehour
}
void DateAndTime::setMinute( int mm ){
	minute = (mm >= 0 && mm < 60)? mm : 0;//validateminute
}
void DateAndTime::setSecond( int ss ){
	second = (ss >= 0 && ss < 60)? ss : 0;//validateminute
}
void DateAndTime::setYear(int y){
	if ( y > 0)
		year = y;
	else {
		y = 2000;
		cout << "Error input for year, defaulted to be 2000\n";
	}
}
void DateAndTime::setMonth(int M){
	month = (0 < M && M <= 12)? M : 0;
	if ( 0 < M && M <= 12)
		month = M;
	else {
		M = 1;
		cout << "Error input for month, defaulted to be January.\n";
	}

}
void DateAndTime::setMday(int d){
	if ( 0 < d && d <= MdayUpperbound(month, year) )
		day = d;
	else{
		day = 1;
		cout << "Error input for day, defaulted to be day 1.\n";
	}
}
int DateAndTime::getHour(){
	return hour;
}
int DateAndTime::getMinute(){
	return minute;
}
int DateAndTime::getSecond(){
	return second;
}
int DateAndTime::getYear(){
	return year;
}
int DateAndTime::getMonth(){
	return month;
}
int DateAndTime::getMday(){
	return day;
}
int DateAndTime::MdayUpperbound( const int &M, const int &y){
	if ( isMonthof31days(M) )
		return 31;
	else if ( M == 2 )
		return (isLeapYear(y))? 29: 28;
	else
		return 30;
}
bool DateAndTime::isLeapYear (const int &y){
	return ( y % 4 == 0 && y > 0);
}
bool DateAndTime::isMonthof31days(const int &M){
	return ( (M <=7 && M % 2 == 1) || ( M >= 8 && M % 2 == 0) )?  true : false;
}
void DateAndTime::printUniversal(){ // print Time in universal-time format (HH:MM:SS)
	cout << setfill( '0' ) << setw( 2 ) << getHour() << ":" << setw( 2 )
	<< getMinute() << ":" << setw( 2 ) << getSecond() <<"  "<< month << '/' << day << '/' << year << endl;
}
void DateAndTime::printStandard(){ // print Time in standard-time format (HH:MM:SS AM or PM)
	cout << setfill('0') << setw(2) << ( ( getHour() == 0 || getHour() == 12 ) ? 12 : getHour() % 12 )
	<< ":" << setw( 2 ) << getMinute()
	<< ":" << setw( 2 ) << getSecond() << ( hour < 12 ? " AM" : " PM" )
	<< "  "<< month << '/' << day << '/' << year << endl;
}
void DateAndTime::tick(){
	second++;
	if ( second == 60 ){
		second = 0;
		minute++;
		if (minute == 60 ){
			minute = 0;
			hour++;
			if (hour == 24){
				hour = 0;
				nextDay();
			}
		}
	}
}
void DateAndTime::nextDay(){
	day++;
	if ( day == MdayUpperbound(month, year)+1 ){
		day = 1;
		month++;
		if ( month == 12 + 1 ){
			month = 1;
			year++;
		}
	}
}
void DateAndTime::DATmain(){
	DateAndTime UhrA(23, 58, 59, 2, 27, 2016 );
	//test functions
	while( UhrA.getMday() != 28 ){
		UhrA.tick();
		UhrA.printStandard();
		UhrA.printUniversal();
	}
}
//end of Question 9.9

