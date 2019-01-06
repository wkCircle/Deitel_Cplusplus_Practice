// Fig. 10.4: Increment.h
// Definition of class Increment.
#ifndef INCREMENT_H
#define INCREMENT_H


#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <typeinfo>
#include <ctime>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

class Increment{
public:
	Increment( int c = 0, int i = 1 ); // default constructor
	void addIncrement(){
		count += increment;
	}
	void print() const; // prints count and increment

private:
	int count;
	const int increment; // const data member
};
#endif // INCREMENT_H

