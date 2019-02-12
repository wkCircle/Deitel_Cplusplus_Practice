#ifndef ComplexClass_hpp
#define ComplexClass_hpp

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

class complex{
public:
	complex(double =0, double =0); //constructor
	void add(complex );
	void subtract(complex);
	void printcomplex();

private:
	double realPart;
	double imiginaryPart;

};

#endif // ComplexClass_hpp
