//Fig 8.10 Nonconstant Pointer to Constant Data
#include "nonconstPtr2constData.hpp"

// xPtr cannot modify the value of constant variable to which it points
void f( const int *xPtr ){
	*xPtr = 100; // error: cannot modify a const object
} // end function f
