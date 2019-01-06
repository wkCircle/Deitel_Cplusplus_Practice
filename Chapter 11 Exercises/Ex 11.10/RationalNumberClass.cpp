//
//  Chapter11_Exercises.cpp
//  20170714 Chapter 11 Exercises
//
//  Created by kai on 14/11/2017.
//  Copyright © 2017 Wen-Kai Chung. All rights reserved.
//
//Ex11.10
#include "RationalNumberClass.hpp"
RationalNumber::RationalNumber(int numerator, int denominator){ //constructor
	//simplify values to get reduced form and validate inputs.
	*this = simplified(&numerator, &denominator);
}
RationalNumber::RationalNumber( const RationalNumber & obj ){
	numerator = obj.numerator;
	denominator = obj.denominator;
}
RationalNumber RationalNumber::simplified( const int *numPtr, const int *denPtr) const{
	//get reduced form and make the +/- sign stick with the numerator (so denominator is always positive).
	RationalNumber temp;
	//validate denominator
	if (*denPtr == 0){
		cout << "Denominator can't be zero.\n";
		exit(EXIT_FAILURE); //abort execution.
	}

	//find GCD
	size_t gcd = GCD( numPtr, denPtr);
	//update values
	if (gcd == 0){ //special case
		temp.numerator = 0;
		temp.denominator = 1;
	}
	else {
		temp.numerator =  *numPtr / static_cast<int>( gcd );
		temp.denominator = *denPtr / static_cast<int>( gcd );
		if ( *numPtr * *denPtr > 0 ){ // same sign
			temp.numerator = abs(*numPtr);
			temp.denominator = abs(*denPtr);
		}
		else if ( *numPtr * *denPtr < 0){ // different sign
			temp.numerator = -1 * abs(*numPtr);
			temp.denominator = abs(*denPtr);
		}
	}//end else

	return temp;
}
RationalNumber RationalNumber::simplified( const RationalNumber & obj) const{
	return simplified( &obj.numerator, &obj.denominator );
}
int RationalNumber::GCD(const int *numPtr, const int *denPtr) const{
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
	//minval is always positive.
}
RationalNumber RationalNumber::operator+( const RationalNumber & obj) const{
	RationalNumber temp;
	if ( obj.denominator == 0){ //obj is an integer.
		temp.numerator = numerator+ denominator * obj.numerator ;
		//denominator is unchanged.
	}
	else {
		int lcm = denominator* obj.denominator /GCD( &denominator, &obj.denominator);
		temp.numerator = (numerator * lcm / denominator )
						 + (obj.numerator * lcm / obj.denominator);
		temp.denominator = lcm;
	}
	return temp = simplified( temp );
}
RationalNumber RationalNumber::operator-( const RationalNumber & obj) const{
	RationalNumber temp;
	if ( obj.denominator == 0){ //obj is an integer.
		temp.numerator = numerator - denominator * obj.numerator ;
		//denominator is unchanged.
	}
	else {
		int lcm = denominator* obj.denominator/GCD(&denominator, &obj.denominator);
		temp.numerator = (numerator * lcm / denominator )
						- (obj.numerator * lcm / obj.denominator);
		temp.denominator = lcm;
	}
	return temp = simplified( temp );
}
RationalNumber RationalNumber::operator*( const RationalNumber & obj ) const{
	RationalNumber temp;
	RationalNumber objCopy(obj);
	//make the fractional nmber the simplest.
	int gcd1 = GCD( &numerator, &obj.denominator);
	temp.numerator = numerator / gcd1;
	objCopy.denominator = obj.denominator / gcd1;
	int gcd2 = GCD( &obj.numerator, &denominator);
	objCopy.numerator = obj.numerator / gcd2;
	temp.denominator = denominator / gcd2;
	//finally multiply together and make it the simplest fraction
	temp.numerator *= objCopy.numerator;
	temp.denominator *= objCopy.denominator;
	return temp = simplified( temp );
}
RationalNumber RationalNumber::operator/( const RationalNumber & obj ) const{
	RationalNumber temp;
	RationalNumber objCopy(obj);
	//make the fractional nmber the simplest.
	int gcd1 = GCD( &numerator, &obj.numerator);
	temp.numerator = numerator / gcd1;
	objCopy.numerator = obj.numerator / gcd1;
	int gcd2 = GCD( &obj.denominator, &denominator);
	objCopy.denominator =  obj.denominator / gcd2;
	temp.denominator = denominator / gcd2;
	//finally multiply together and make it the simplest fraction
	temp.numerator *= obj.denominator;
	temp.denominator *= obj.numerator;
	return temp = simplified( temp );
}
bool RationalNumber::operator==( const RationalNumber &obj) const{
	RationalNumber objCopy(obj);

	objCopy = simplified(obj);
	return (numerator == objCopy.numerator && denominator == objCopy.denominator)? true: false;
}
bool RationalNumber::operator!=( const RationalNumber &obj) const{
	return !( *this == obj );
}
bool RationalNumber::operator> ( const RationalNumber &obj) const{
	RationalNumber objCopy(obj);
	objCopy = simplified(obj);
	return (numerator * objCopy.denominator > denominator * objCopy.numerator);
}
bool RationalNumber::operator< ( const RationalNumber &obj) const{
	return !( *this > obj || *this == obj  );
}
bool RationalNumber::operator>=( const RationalNumber &obj) const{
	return (*this > obj || *this == obj);
}
bool RationalNumber::operator<=( const RationalNumber &obj) const{
	return (*this < obj || *this == obj);
}
void RationalNumber::printR(){
	cout << "Rational form: " << numerator << "/" << denominator << endl;
}
void RationalNumber::printFl(){
	cout << "floating form: " << static_cast<double>(numerator)/denominator << endl;
}
