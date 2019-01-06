// Fig. 9.11: CreateAndDestroy.h
// CreateAndDestroy class definition.
// Member functions defined in CreateAndDestroy.cpp.
#ifndef CREATE_H
#define CREATE_H

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


class CreateAndDestroy{
public:
	void Fig9_11to9_13main();
	CreateAndDestroy( int, string ); // constructor
	~CreateAndDestroy(); // destructor

private:
	int objectID; // ID number for object
	string message; // message describing object
}; // end class CreateAndDestroy
#endif //CREATE_H

