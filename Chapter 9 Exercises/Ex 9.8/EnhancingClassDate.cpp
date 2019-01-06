#include "EnhancingClassDate.hpp"
//Question 9.8
Date::Date( int m, int d, int y ){
	setYear(y);
	setMonth(m);
	setMday(d);
}
void Date::setYear(int y){
	if ( y > 0)
		year = y;
	else {
		y = 2000;
		cout << "Error input for year, defaulted to be 2000\n";
	}
}
void Date::setMonth(int m){
	month = (0 < m && m <= 12)? m : 0;
	if ( 0 < m && m <= 12)
		month = m;
	else {
		m = 1;
		cout << "Error input for month, defaulted to be January.\n";
	}

}
void Date::setMday(int d){
	if ( 0 < d && d <= MdayUpperbound(month, year) )
		day = d;
	else{
		day = 1;
		cout << "Error input for day, defaulted to be day 1.\n";
	}
}
int Date::getYear(){
	return year;
}
int Date::getMonth(){
	return month;
}
int Date::getMday(){
	return day;
}
int Date::MdayUpperbound( const int &m, const int &y){
	if ( isMonthof31days(m) )
		return 31;
	else if ( m == 2 )
		return (isLeapYear(y))? 29: 28;
	else
		return 30;
}
bool Date::isLeapYear (const int &y){
	return ( y % 4 == 0 && y > 0);
}
bool Date::isMonthof31days(const int &m){
	return ( (m <=7 && m % 2 == 1) || ( m >= 8 && m % 2 == 0) )?  true : false;
}
void Date::print(){// print Date in the format mm/dd/yyyy
	cout << month << '/' << day << '/' << year << endl;
}
void Date::nextDay(){
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
void Date::Fig9_17to9_19main(){
	Date date1( 2, 27, 2004 );
	Date date2( 2, 27, 2005 );

	//test functions.
	while ( date1.getMonth() != 5 ){
		date1.nextDay();
		date1.print();
	}
	cout << endl << endl << endl;
	while ( date2.getMonth() != 5 ){
		date2.nextDay();
		date2.print();
	}
}
//end of Question 9.8
