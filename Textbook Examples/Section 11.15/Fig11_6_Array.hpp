// Fig. 11.6: Array.h
// Array class definition with overloaded operators.
#ifndef ARRAY_H
#define ARRAY_H

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


class Array {
	friend ostream & operator<<( ostream &, const Array & );
	friend istream & operator>>( istream &, Array & );
public:
	Array( int = 10 );//compiler will also regard the single argument constructor as a conversion constructor.(c.f. Fig11.13)
	Array( const Array & ); // copy constructor
	~Array();
	const Array & operator=( const Array & ); // assignment operator

	void Fig11_13main();
	int getSize() const;


	bool operator==( const Array & ) const; // equality operator
	bool operator!=( const Array &right ) const { // inequality operator; returns opposite of == operato
		return ! ( *this == right ); // invokes Array::operator==
	}
	int &operator[]( int ); // subscript operator for non-const objects returns modifiable lvalue
	int operator[]( int ) const; // subscript operator for const objects returns rvalue
private:
	int size; // pointer-based array size
	int *ptr; // pointer to first element of pointer-based array
};
#endif // ARRAY_H

