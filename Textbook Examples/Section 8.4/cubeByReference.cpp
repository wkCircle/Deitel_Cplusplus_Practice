//Fig8.7 cube volume By Reference with pointer arguments.
#include "cubeByReference.hpp"

void cubeByReference( int *nPtr ) //use a pointer nPtr to store &number (address)
{
	*nPtr = *nPtr * *nPtr * *nPtr; // cube *nPtr: '*' is dereferencing operator.
} // end function cubeByReference
/**< a function receiving an address as an argument must define a pointer parameter to receive the address.>**/
