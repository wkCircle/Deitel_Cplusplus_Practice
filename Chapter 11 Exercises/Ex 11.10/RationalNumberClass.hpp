//
//  Chapter11_Exercises.hpp
//  20170714 Chapter 11 Exercises
//
//  Created by kai on 14/11/2017.
//  Copyright © 2017 Wen-Kai Chung. All rights reserved.
//
//Ex11.10
#ifndef RationalNumberClass_hpp
#define RationalNumberClass_hpp

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <ctime>
#include <random>
#include <typeinfo>
#include <vector>
#include <cctype>  //isdigit function prototype
using namespace std;

class RationalNumber{
	friend ostream & operator<<(ostream& , RationalNumber &);
	friend istream & operator>>(istream& , RationalNumber &);
public:
	RationalNumber(int =0 , int =1); //rational constructor
	RationalNumber( const RationalNumber &); //copy constructor
	RationalNumber operator+( const RationalNumber & ) const;
	RationalNumber operator-( const RationalNumber & ) const;
	RationalNumber operator*( const RationalNumber & ) const;
	RationalNumber operator/( const RationalNumber & ) const;
	bool operator==( const RationalNumber &) const;
	bool operator!=( const RationalNumber &) const;
	bool operator> ( const RationalNumber &) const;
	bool operator< ( const RationalNumber &) const;
	bool operator>=( const RationalNumber &) const;
	bool operator<=( const RationalNumber &) const;

	void printR();
	void printFl();
private:
	RationalNumber simplified( const int *, const int *) const;
	RationalNumber simplified( const RationalNumber &) const;
	int GCD(const int *, const int *) const;
	int numerator;
	int denominator;
};

#endif // RationalNumberClass_hpp
