//Sec 7.11 Introduction to C++ Standard Library Class Template 'vector.'
#include "introToVector.hpp"
#include <vector> // vector<type>, size(), at()


//Standard class template vector is defined in header <vector> and belongs to namespace std
void outputVector( const vector< int > &); // display the vector
void inputVector( vector <int> & ); // input values into the vector


void introToVector(){

	vector<int> integers1(7); //7-element <int>
	vector<int> integers2(10); // 10-element <int>

	// print integers1 and integers2 sizes and contents
	cout << "Size of vector integers1 is " << integers1.size() << "\nvector after initialization:" << endl;
	outputVector( integers1 );

	cout << "\nSize of vector integers2 is " << integers2.size() << "\nvector after initialization:" << endl;
	outputVector( integers2 );

	// input and print integers1 and integers2
	cout << "\nEnter 17 integers:" << endl;
	inputVector( integers1 );
	inputVector( integers2 );

	cout << "\nAfter input, the vectors contain:\n"	<< "integers1:" << endl;
	outputVector( integers1 );

	cout << "integers2:" << endl;
	outputVector( integers2 );

	// use inequality (!=) operator with vector objects
	cout << "\nEvaluating: integers1 != integers2" << endl;

	if ( integers1 != integers2 )
		cout << "integers1 and integers2 are not equal" << endl;

	// Now create integers3 using integers1 as an initializer; print size and contents
	vector< int > integers3( integers1 ); // copy constructor

	cout << "\nSize of vector integers3 is " << integers3.size() << "\nvector after initialization:" << endl;
	outputVector( integers3 );

	// use overloaded assignment (=) operator
	cout << "\nAssigning integers2 to integers1:" << endl;
	integers1 = integers2; // assign integers2 to integers1

	cout << "integers1:" << endl;
	outputVector( integers1 );
	cout << "integers2:" << endl;
	outputVector( integers2 );

	// use equality (==) operator with vector objects
	cout << "\nEvaluating: integers1 == integers2" << endl;

	if ( integers1 == integers2 )
		cout << "integers1 and integers2 are equal" << endl;

	// use square brackets to creat rvalue
	cout << "\nintegers1[5] is " << integers1[ 5 ];

	// use square brackets to create lvalue
	cout << "\n\nAssigning 1000 to integers1[5]" << endl;
	integers1[ 5 ] = 1000;
	cout << "integers1:" << endl;
	outputVector( integers1 );

	// attempt to use out-of-range subscript
	cout << "\nAttempt to assign 1000 to integers1.at( 15 )" << endl;

	////Error
	integers1.at( 15 ) = 1000; // ERROR: out of range
	////Error
	//Error message: libc++abi.dylib: terminating with uncaught exception of type std::out_of_range: vector

}
void outputVector( const vector<int> &array ) {
	size_t i; // declare control variable //it represents unsigned int in many compilers.

	for ( i = 0; i < array.size(); i++ )
	{
		cout << setw( 12 ) << array[ i ];
		if ( ( i + 1 ) % 4 == 0 ) // 4 numbers per row of output
			cout << endl;
	}

	if ( i % 4 != 0 )
		cout << endl;

} // end function outputVector
void inputVector( vector<int> &array ){
	for ( size_t i = 0; i < array.size(); i++ )
		cin >> array[ i ];

} // end function inputVector
/*
 Conclusions:
 1. vector <int>: type specifier as a form of vector (one dimension)
 2. vec.size(): size() returns the number of elements in that object(here vec) as type size_t.
 3. size_t: unsigned int
 4. assign/print values to/from a vector: use [] (do not check borders) or vec.at() (check borders)
 5. vectors can be compared with ones another, assigned value: !=, ==, =.
 e.g. vector<int > vec(15, 0): reserve 15 positions for the vector vec and assign 0 to all positions.
 e.g. vector<int > vec(v2.begin(), v2.end()): use vector v2 to initialize vec, i.e., copy v2 to vec. (same as vec = v2)
 e.g. vector<int > vec(arr, arr + sizeof(arr)/sizeof(type_of_arr) ): assine each entry value of arr to vec.
 6. An array name is already a pointer. And the name of the arrayis the starting location in memory of the array.

 7. vector can be initialized by another existing vector (In contrast, array can only be initialzied by const var.)
 */
