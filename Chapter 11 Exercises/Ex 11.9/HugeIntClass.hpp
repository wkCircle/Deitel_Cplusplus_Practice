// Fig. 11.23: Hugeint.h
// HugeInt class definition.
#ifndef HugeIntClass_hpp
#define HugeIntClass_hpp

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
	HugeInt operator/( const string & ) const;	//overloading/ for HugeInt vs string  °£ªk«Ý¸É
protected:
	short integer[ digits ];
	int length;
};

#endif // HugeIntClass_hpp
