//
//  Chapter11_Exercises.hpp
//  20170714 Chapter 11 Exercises
//
//  Created by kai on 14/11/2017.
//  Copyright © 2017 Wen-Kai Chung. All rights reserved.
//

#ifndef Chapter11_Exercises_hpp
#define Chapter11_Exercises_hpp

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

//Ex11.7
void Ex11_7main();
class DoubleSubscriptedArray{
	friend ostream& operator<<( ostream &, const DoubleSubscriptedArray &);
	friend istream& operator>>( istream &, DoubleSubscriptedArray &);
public:
	DoubleSubscriptedArray(int =0, int =0);
	DoubleSubscriptedArray(const DoubleSubscriptedArray & ); //copy constructor must receive a refernce.
	~DoubleSubscriptedArray();
	const int& operator()(int, int) const; //returns rvalue
	int& operator()(int, int); //returns lvalue
	bool operator==( const DoubleSubscriptedArray &) const;
	bool operator!=( const DoubleSubscriptedArray &) const;
	const DoubleSubscriptedArray& operator=(const DoubleSubscriptedArray & ); //prevent statement like: (A = B) = C;
private:
	int rows;
	int cols;
	int * arrPtr;
};

//Ex11.8
// Fig. 11.20: Complex.h (Modified)
void Ex11_8main();
class Complex{
	friend ostream & operator<<(ostream& , Complex &);
	friend istream & operator>>(istream& , Complex &);
public:
	Complex( double = 0.0, double = 0.0 ); // constructor
	Complex operator+( const Complex & ) const; // addition
	Complex operator-( const Complex & ) const; // subtraction
	Complex operator*( const Complex &) const; //multiplication
	bool operator==( const Complex &) const; 
	bool operator!=( const Complex &) const;
private:
	double real; // real part
	double imaginary; // imaginary part
};

// Fig. 11.23: Hugeint.h
// HugeInt class definition.
void Ex11_9main();
class HugeInt{
	friend ostream &operator<<( ostream &, const HugeInt & );
public:
	static const int digits = 30; // maximum digits in a HugeInt
	HugeInt( long = 0 ); // conversion/default constructor
	HugeInt( const string & ); // conversion constructor
	HugeInt operator+( const HugeInt & ) const; //overloading+ for HugeInt vs HugeInt
	HugeInt operator+( int ) const; 			//overloading+ for HugeInt vs int
	HugeInt operator+( const string & ) const;	//overloading+ for HugeInt vs string
	HugeInt operator*( const HugeInt & ) const;	//overloading* for HugeInt vs HugeInt
	HugeInt operator*( int ) const;				//overloading* for HugeInt vs int
	HugeInt operator*( const string & ) const;	//overloading* for HugeInt vs string
	HugeInt operator/( const HugeInt & ) const;	//overloading/ for HugeInt vs HugeInt
	HugeInt operator/( int ) const;				//overloading/ for HugeInt vs int
	HugeInt operator/( const string & ) const;	//overloading/ for HugeInt vs string  除法待補
protected:
	short integer[ digits ];
	int length;
};

//Ex11.10
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

//class Polynomial待補

#endif /* Chapter11_Exercises_hpp */
