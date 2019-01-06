#ifndef OverloadingtheParenthesesOperator_hpp
#define OverloadingtheParenthesesOperator

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <ctime>
#include <random>
#include <typeinfo>
#include <vector>
#include <cctype>  //isdigit function prototype
using namespace std;

class DoubleSubscriptedArray{
	friend ostream& operator<<( ostream &, const DoubleSubscriptedArray &);
	friend istream& operator>>( istream &, DoubleSubscriptedArray &);
public:
	DoubleSubscriptedArray(int =0, int =0);
	DoubleSubscriptedArray(const DoubleSubscriptedArray & ); //copy constructor must receive a refernce.
	~DoubleSubscriptedArray();
	const int& operator()(int, int) const; //returns rvalue
	int& operator()(int, int); //returns lvalue
	bool operator==( const DoubleSubscriptedArray &) const;
	bool operator!=( const DoubleSubscriptedArray &) const;
	const DoubleSubscriptedArray& operator=(const DoubleSubscriptedArray & ); //prevent statement like: (A = B) = C;
private:
	int rows;
	int cols;
	int * arrPtr;
};

#endif // OverloadingtheParenthesesOperator_hpp
