#include "Fig11_6_Array.hpp"

int main(){
	Array integers1( 7 ); // seven-element Array
	Array integers2; // 10-element Array by default

	cout << "Size of Array integers1 is " << integers1.getSize() << "\nArray after initialization:\n" << integers1;
	cout << "\nSize of Array integers2 is "<<integers2.getSize() << "\nArray after initialization:\n" << integers2;

	// input and print integers1 and integers2
	cout << "\nEnter 17 integers:" << endl;
	cin  >> integers1 >> integers2;

	cout << "\nAfter input, the Arrays contain:\n"
	<< "integers1:\n" << integers1
	<< "integers2:\n" << integers2;

	// use overloaded inequality (!=) operator
	cout << "\nEvaluating: integers1 != integers2" << endl;
	if ( integers1 != integers2 )
		cout << "integers1 and integers2 are not equal" << endl;

	// create Array integers3 using integers1 as an initializer; print size and contents
	Array integers3( integers1 ); // invokes copy constructor

	cout << "\nSize of Array integers3 is " << integers3.getSize() << "\nArray after initialization:\n" << integers3;

	// use overloaded assignment (=) operator
	cout << "\nAssigning integers2 to integers1:" << endl;
	integers1 = integers2; // note target Array is smaller

	cout << "integers1:\n" << integers1
	<< "integers2:\n" << integers2;

	// use overloaded equality (==) operator
	cout << "\nEvaluating: integers1 == integers2" << endl;
	if (integers1 == integers2)
		cout << "integers1 and integers2 are equal" << endl;

	// use overloaded subscript operator to create rvalue
	cout << "\nintegers1[5] is " << integers1[ 5 ];

	// use overloaded subscript operator to create lvalue
	cout << "\n\nAssigning 1000 to integers1[5]" << endl;
	integers1[5] = 1000;
	cout << "integers1:\n" << integers1;

	// attempt to use out-of-range subscript
	cout << "\nAttempt to assign 1000 to integers1[15]" << endl;
	integers1[ 15 ] = 1000; // ERROR: out of range
}

/**<小結:
 1. Array integers3( integers1 ); 會使用到Copy constructor。
 2. Copy constructor must receive its argumet by reference, not by value. Otherwise, infinite recursion will occur.
 3. From 2, the reason is that receiving an object by value requires the copy constructor to make a copy of the argument object
 4. int & Array::operator[]( int subscript ): returning a reference allows the assignment task! e.g., integers1[5]=1000;
 5. Dangling pointer: if a copy constructor simply copied the pointer of the source object to our target object,
 then both pointers would point to the same dynamically allocated memory! When the first destructor is called, it will delete
 the dynamically allocated memory and cause the other pointer undefined!
 6. const Array & Array::operator=( const Array & ) 的宣告中, const return 可避免 ( a1 = a2 ) = a3
 */
