// Fig 11.7: Array.cpp
#include "Fig11_6_Array.hpp"

/**<converstion constructor */
Array::Array( int arraySize ){
	size = ( arraySize > 0 ? arraySize : 10 );
	ptr = new int[ size ]; // create space for pointer-based array

	for ( int i = 0; i < size; i++ )
		ptr[ i ] = 0; // set pointer-based array element
}

/**<Copy constructor must receive a reference to prevent infinite recursion*/
Array::Array( const Array &arrayToCopy ) : size( arrayToCopy.size ) {
	ptr = new int[ size ]; // create space for pointer-based array
	//    ptr = arrayToCopy.ptr; <- Dangling pointer!
	for ( int i = 0; i < size; i++ )
		ptr[ i ] = arrayToCopy.ptr[ i ]; // copy into object
}
Array::~Array() {
	delete [] ptr;
}
int Array::getSize() const {
	return size;
}
// overloaded assignment operator; const return avoids: ( a1 = a2 ) = a3
const Array & Array::operator=( const Array &right ) {
	if ( &right != this ) {  /**avoid self-assignment*/
		if ( size != right.size ) {
			delete [] ptr;
			size = right.size;
			ptr = new int[ size ];
		}

		for ( int i = 0; i < size; i++ )
			ptr[ i ] = right.ptr[ i ];
	}
	return *this; // enables x = y = z, for example
}
// determine if two Arrays are equal and return true, otherwise return false
bool Array::operator==( const Array &right ) const{
	if ( size != right.size )
		return false;
	for ( int i = 0; i < size; i++ )
		if ( ptr[ i ] != right.ptr[ i ] )
			return false;

	return true; // Arrays are equal
}
// overloaded subscript operator for non-const Arrays; reference return creates a modifiable lvalue
int &Array::operator[]( int subscript ) {
	if ( subscript < 0 || subscript >= size ){
		cerr << "\nError: Subscript " << subscript << " out of range" << endl;
		exit( 1 ); // terminate program; subscript out of range
	}
	return ptr[ subscript ]; // reference return
}
// overloaded subscript operator for const Arrays; const reference return creates an rvalue
int Array::operator[]( int subscript ) const {
	if ( subscript < 0 || subscript >= size ) {
		cerr << "\nError: Subscript " << subscript << " out of range" << endl;
		exit( 1 ); // terminate program; subscript out of range
	}

	return ptr[ subscript ]; // returns copy of this element
}
istream &operator>>( istream &input, Array &a ) {
	for ( int i = 0; i < a.size; i++ )
		input >> a.ptr[ i ];
	return input; // enables cin >> x >> y;
}
ostream &operator<<( ostream &output, const Array &a ) {
	int i;
	// output private ptr-based array
	for ( i = 0; i < a.size; i++ ){
		output << setw( 12 ) << a.ptr[ i ];
		if ( ( i + 1 ) % 4 == 0 ) // 4 numbers per row of output
			output << endl;
	}
	if ( i % 4 != 0 ) // end last line of output
		output << endl;

	return output; // enables cout << x << y;
}
