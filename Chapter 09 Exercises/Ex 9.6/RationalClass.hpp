#ifndef RationalClass_hpp
#define RationalClass_hpp

#include <cstdio>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;


class Rational{
public:
	Rational(int =0, int =1);
	void add(Rational);
	void subtract(Rational);
	void multiply(Rational);
	void divide(Rational);
	void printR();
	void printFl();
private:
	void simplified( int *, int *);
	int GCD(const int *, const int *);
	int numerator;
	int denominator;
};

#endif // RationalClass_hpp
