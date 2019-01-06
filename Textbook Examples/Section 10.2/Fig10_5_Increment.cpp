// Fig. 10.5: Increment.cpp +Fig. 10.6
// Member-function definitions for class Increment demonstrate using a member initializer to initialize a constant of a built-in data type.
#include <iostream>
#include "Fig10_4_Increment.hpp"

using namespace std;
// constructor: initializer for non-const member and for const member(necessary)
Increment::Increment( int c, int i ): count( c ), increment( i ){
	// empty body
}
void Increment::print() const{
	cout << "count = " << count << ", increment = " << increment << endl;
}
