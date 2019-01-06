//Sec 8.3 Pointer Operators
#include "PointerOperators.hpp"

void PointerOperators(){

	int a; // a is an integer
	int *aPtr; // aPtr is an int * which is a pointer to an integer

	a = 7; // assigned 7 to a
	aPtr = &a; // assign the address of a to aPtr

	cout << "The address of a is " << &a
	<< "\nThe value of aPtr is " <<  aPtr;
	cout << "\n\nThe value of a is " << a
	<< "\nThe value of *aPtr is " << *aPtr;
	cout << "\n\nShowing that * and & are inverses of "
	<< "each other.\n&*aPtr = " << &*aPtr
	<< "\n*&aPtr = " << *&aPtr << endl;
}



// & is called address operator (note that e.g. int &c is called pass-by-reference with reference arguments, in which & is different from address operator '&' )
// * is called dereferencing operator or indirection operator (also different from int *var, which declare a variable is of type int and is a pointer.)
// Though C++ allows pass-by-reference to a called function, C doesn't have this extended bility.
/**< An array name is already a pointer. And the name of the arrayis the starting location in memory of the array.
 Thus, the name of an array, say ArrayName, is equivalent to &ArrayName[0] >**/
