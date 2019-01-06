//Ex11.8
// Fig. 11.20: Complex.h (Modified)
#ifndef ComplexClass_hpp
#define ComplexClass_hpp

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

#endif // ComplexClass_hpp
