//
//  Chapter9_Exercises.cpp
//  20170617 Chapter 9 Exercises
//
//  Created by ntueconRA on 2017/6/17.
//  Copyright © 2017年 Kai. All rights reserved.
//

#include "Chapter9_Exercises.hpp"

//Question 9.4
Time9_4::Time9_4(){ //initialize private data to current time
	time_t t = 0;
	time(&t); //same as t = time(0); OR, t = time(NULL);
	
	struct tm tinfo = *localtime(&t);
	year = tinfo.tm_year +1990 ; //tm_year returns years since 1990
	month = tinfo.tm_mon + 1; //tm_mon returns months since January(0~11)
	mday =tinfo.tm_mday;
	hour = tinfo.tm_hour;
	minute = tinfo.tm_min;
	second = tinfo.tm_sec;
}
//Question 9.5
complex::complex(double realPart, double imiginaryPart){
	complex::realPart = realPart;
	complex::imiginaryPart = imiginaryPart;
}
void complex::add( complex obj){
	realPart += obj.realPart;
	imiginaryPart += obj.imiginaryPart;
}
void complex::subtract(complex obj ){
	realPart -= obj.realPart;
	imiginaryPart -= obj.imiginaryPart;
}
void complex::printcomplex(){
	cout << "complex value is: (" << realPart << ", " << imiginaryPart << ")\n";
}
//end of Question 9.5
//Question 9.6
Rational::Rational(int numerator, int denominator){ //constructor
	//simplify values to get reduced form.
	simplified(&numerator, &denominator);
	//store values
	Rational::numerator = numerator;
	Rational::denominator = denominator;
}
void Rational::simplified( int *numPtr, int *denPtr){ //get reduced form and make the +/- sign stick with the numerator (so denominator is always positive).
	
	//validate denominator
	if (*denPtr == 0){
		cout << "Denominator can't be zero.\n";
		exit(EXIT_FAILURE); //abort execution.
	}
	
	//find GCD
	size_t gcd = GCD( numPtr, denPtr);
	//update values
	if (gcd == 0){ //special case
		*numPtr = 0;
		*denPtr = 1;
	}
	else {
		*numPtr /= static_cast<int>( gcd );
		*denPtr /= static_cast<int>( gcd );
		if ( *numPtr * *denPtr > 0 ){ // 同號
			*numPtr = abs(*numPtr);
			*denPtr = abs(*denPtr);
		}
		else if ( *numPtr * *denPtr < 0){ //異號
			*numPtr = -1 * abs(*numPtr);
			*denPtr = abs(*denPtr);
		}
	}
	
}
int Rational::GCD(const int *numPtr, const int *denPtr){
	if ( *numPtr == 0)
		return 0; //special case.
	
	int maxval = max( abs(*numPtr), abs(*denPtr));
	int minval = min( abs(*numPtr), abs(*denPtr));
	
	//find GCD
	while ( maxval % minval != 0){
		int temp = maxval % minval;
		maxval = minval;
		minval = temp;
	}
	return minval;
	//True for either case, maxval%minval ==0 or !=0.
	//minval 恆為正
}
void Rational::add(Rational obj){
	if ( obj.denominator == 0){ //obj is an integer.
		numerator += denominator * obj.numerator ;
		//denominator is unchanged.
	}
	else {
		int lcm = denominator* obj.denominator /GCD( &denominator, &obj.denominator);
		numerator = (numerator * lcm / denominator )
				  + (obj.numerator * lcm / obj.denominator);
		denominator = lcm;
	}
	simplified( &numerator, &denominator );
}
void Rational::subtract(Rational obj){
	if ( obj.denominator == 0){ //obj is an integer.
		numerator -= denominator * obj.numerator ;
		//denominator is unchanged.
	}
	else {
		int lcm = denominator* obj.denominator/GCD(&denominator, &obj.denominator);
		numerator = (numerator * lcm / denominator )
				  - (obj.numerator * lcm / obj.denominator);
		denominator = lcm;
	}
	simplified( &numerator, &denominator );
}
void Rational::multiply(Rational obj){
	//能約分先約分
	int gcd1 = GCD( &numerator, &obj.denominator);
	numerator /= gcd1;
	obj.denominator /= gcd1;
	int gcd2 = GCD( &obj.numerator, &denominator);
	obj.numerator /= gcd2;
	denominator /= gcd2;
	//最後乘起來並化簡
	numerator *= obj.numerator;
	denominator *= obj.denominator;
	simplified( &numerator, &denominator);
}
void Rational::divide(Rational obj){
	//能約分先約分
	int gcd1 = GCD( &numerator, &obj.numerator);
	numerator /= gcd1;
	obj.numerator /= gcd1;
	int gcd2 = GCD( &obj.denominator, &denominator);
	obj.denominator /= gcd2;
	denominator /= gcd2;
	//最後乘起來並化簡
	numerator *= obj.denominator;
	denominator *= obj.numerator;
	simplified( &numerator, &denominator);
}
void Rational::printR(){
	cout << "Rational form: " << numerator << "/" << denominator << endl;

}
void Rational::printFl(){
	cout << "floating form: " << static_cast<double>(numerator)/denominator << endl;
}
//end of Question 9.6

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


//Question 9.11
Rectangle::Rectangle( double L, double W ){
	setLength(&L);
	setWidth(&W);
}
Rectangle::Rectangle( double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4){
	Rectangle::x1 = x1;
	Rectangle::y1 = y1;
	Rectangle::x2 = x2;
	Rectangle::y2 = y2;
	Rectangle::x3 = x3;
	Rectangle::y3 = y3;
	Rectangle::x4 = x4;
	Rectangle::y4 = y4;
	
	if ( isOutOfRange() ){
		cout << "coordinates are out of range(>20.0). Sytstem excution terminated.\n";
		exit(EXIT_FAILURE);
	}
	
	int type = typeDetermine();
	if ( isCommonLine() || type == -1  ){
		cout << "Not a Rectangle. Sytstem excution terminated.\n";
		exit(EXIT_FAILURE);
	}
	
	AutoComputeLengthAndWidth(&type);
	
}
void Rectangle::setLength( double *Lptr ){
	if ( 0.0 < *Lptr && *Lptr < 20)
		length = *Lptr;
	else {
		length = 1;
		cout << "Invalid input for length, defaulted to be 1;";
	}
}
void Rectangle::setWidth( double *Wptr ){
	if ( 0.0 < *Wptr && *Wptr < 20)
		width = *Wptr;
	else {
		width = 1;
		cout << "Invalid input for width, defaulted to be 1;";
	}
}

double Rectangle::getLength(){
	return length;
}
double Rectangle::getWidth(){
	return width;
}
double Rectangle::perimeter(){
	return (length+width)*2;
}
double Rectangle::area(){
	return (length*width);
}
bool Rectangle::isOutOfRange(){
	if ( 0.0 <= x1 && 0.0 <= y1 && 0.0 <= x2 && 0.0 <= y2 &&
		 0.0 <= x3 && 0.0 <= y3 && 0.0 <= x4 && 0.0 <= y4 &&
		 20.0 >= x1 && 20.0 >= y1 && 20.0 >= x2 && 20.0 >= y2 &&
		 20.0 >= x3 && 20.0 >= y3 && 20.0 >= x4 && 20.0 >= y4)
		return false;
	else
		return true;
}
bool Rectangle::isCommonLine(){ //只判斷前3點即可, 第四點則透過前3點定位, 只有3個位置有可能
	return (  (x2-x1)*(y3-y1) == (x3-x1)*(y2-y1)  );
}
int Rectangle::typeDetermine(){ //returns true if it's not a rectangle.
	int type = 0;
	if ( x4 == x1 + (x3 - x2) && y4 == y1 + (y3 - y2) ) //math skill: 用這種寫法可確保3個位子被分辨出來, 按順時鐘或逆時鐘轉
		type = 1;
	else if ( x4 == x2 + (x1 -x3) && y4 == y2 + (y1 - y3) )
		type = 2;
	else if ( x4 == x3 + (x2 - x1) && y4 == y3 + (y2 - y1) )
		type = 3;
	else
		type = -1;
	return type;
}
void Rectangle::AutoComputeLengthAndWidth(const int * const typePtr){
	switch (*typePtr){
		//math skill: 看回typeDetermine(), 如果是type i, 可發現是以 (xi, yi)為基準點做向量加減, 故下列算是也以該點為基準被加減
		case 1:
			length = sqrt( pow( x4-x1, 2) + pow( y4-y1, 2));
			width  = sqrt( pow( x2-x1, 2) + pow( y2-y1, 2));
			break;
		case 2:
			length = sqrt( pow( x4-x2, 2) + pow( y4-y2, 2));
			width  = sqrt( pow( x3-x2, 2) + pow( y3-y2, 2));
			break;
		case 3:
			length = sqrt( pow( x1-x3, 2) + pow( y1-y3, 2));
			width  = sqrt( pow( x4-x3, 2) + pow( y4-y3, 2));
			break;
	}
}
//end of Question 9.11




//Question of 9.14 , here we use vectors to solve the question.
HugeInteger::HugeInteger(){
	lengthOfNum = 0;
	bigNumVec.assign(40,'0'); //initialize vector with capacity 40 and values defaulted to be 0.
	input();
}
//I/O stream functions
void HugeInteger::input(){
	
	string input="";
	cout << "Pls input an integer of max digits 40.\n";
	cin >> input;
	
	//validate the input string.
	while( ! validStr( input)  ){
		cout << "Error input, please only input an integer of max length 40. (no #,.,$, or letters etc.)\n";
		cin >> input;
	}
	//store the number of digits of the input number.
	lengthOfNum = sizeof(input) / sizeof(input.at(0));
	
	//store digits backward.  //要分清楚 vec.size() , vec.capacity(), vec.max_size();
	for ( int i = (int) bigNumVec.size() , j = lengthOfNum ; i >= 0 && j >=0 ; i--, j-- )
		bigNumVec.at(i) = input.at(j);
}
void HugeInteger::output(){
	for ( int i = 0; i < lengthOfNum; i++)
		cout << bigNumVec.at(  bigNumVec.size()-lengthOfNum +i );
	endl(cout);
}
//arithmetic functions
void HugeInteger::add( HugeInteger *objPtr){
	int temp = 0; //record 進位數字
	for ( int i = (int)bigNumVec.size() -1 ; i >= 0; i-- ){
		temp = ( bigNumVec.at(i)-'0' +  objPtr->bigNumVec.at(i) -'0' )/10 ;
		bigNumVec.at(i) = ( bigNumVec.at(i)-'0' +  objPtr->bigNumVec.at(i)-'0' ) % 10 ;
		if (i != 0) //怕邊界爆掉
			bigNumVec.at(i-1) += temp;
	}
		
}
void HugeInteger::subtract( HugeInteger *objPtr){
	int temp = 0; //record 進位數字
	for ( int i = (int)bigNumVec.size() -1 ; i >= 0; i-- ){
		temp = (bigNumVec.at(i)-'0' +  objPtr->bigNumVec.at(i) -'0')/10 ;
		bigNumVec.at(i) = (bigNumVec.at(i)-'0' +  objPtr->bigNumVec.at(i)-'0') % 10 ;
		if (i != 0) //怕邊界爆掉
			bigNumVec.at(i-1) += temp;
	}
}
//compare functions 待補
bool HugeInteger::isEqualTo( HugeInteger * ){
	return false;
}
bool HugeInteger::isNotEqualTo( HugeInteger *){
	return false;
}
bool HugeInteger::isGreaterThan( HugeInteger *){
	return false;
}
bool HugeInteger::isLessThan( HugeInteger *){
	return false;
}
bool HugeInteger::isGreaterThanOrEqualTo(HugeInteger *){
	return false;
}
bool HugeInteger::isLessThanOrEqualTo( HugeInteger * ){
	return false;
}
bool HugeInteger::isZero( HugeInteger *){
	return false;
}
bool HugeInteger::validStr( const string &str ){
	//condition 1: restricted size.
	if ( str.length() > bigNumVec.size() ){
		cout << "Err: out-of-range input size.\n";
		return false;
	}
	
	//condition 2: isdigit or not.
	//case1 negative integer
	if ( str.at(0) == '-'){
		for (int i = (int) str.length() ; i >= 1; i-- ){
			if (  ! isdigit( str.at(i) ) 	){
				cout << "Err: not a decimal number or dot(.)\n";
				return false;
			}
		}//end for
	}
	//case1 positive integer
	else {
		for (int i = (int) str.length() ; i >= 0; i-- ){
			if (  ! isdigit( str.at(i) ) 	){
				cout << "Err: not a decimal number or dot(.)\n";
				return false;
			}
		}//end for
	}
	
	//after passing the above conditions, return true;
	return true;
}
//end of Question 9.14








