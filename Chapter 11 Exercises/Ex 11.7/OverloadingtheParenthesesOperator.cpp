#include "OverloadingtheParenthesesOperator.hpp"
//Ex7.11
ostream& operator<<( ostream & output, const DoubleSubscriptedArray &arr ){
	for ( int i = 0; i < arr.rows * arr.cols ; i++){
		if ( i != 0 && i % arr.cols == 0) output << endl;
		output << left << setw(5) << arr.arrPtr[i];
	}
	output << endl;
	return output; //enables cascated expresstion
}
istream& operator>>( istream & input, DoubleSubscriptedArray &arr ){
	for ( int i = 0; i < arr.rows * arr.cols ; i++)
		input >> arr.arrPtr[i];
	return input;
}
DoubleSubscriptedArray::DoubleSubscriptedArray(int r, int c){ //constructor
	rows = ( r > 0 )? r: 0;
	cols = ( c > 0 )? c: 0;
	arrPtr = new int [rows*cols]; //1-dim array but operate it like a 2-dim one.
	for (int i= 0; i < rows*cols ; i++)
		arrPtr[i] = 0; //initialize to 0.
}
DoubleSubscriptedArray::DoubleSubscriptedArray(const DoubleSubscriptedArray &inarr ){ //copy constructor
	rows = inarr.rows;
	cols = inarr.cols;
	arrPtr = new int[ rows * cols ];
	for (int i =0; i < rows * cols; i++)
		arrPtr[i] = inarr.arrPtr[i];
}
DoubleSubscriptedArray::~DoubleSubscriptedArray(){
	delete [] arrPtr;
}
const int&	DoubleSubscriptedArray::operator()(int i, int j) const {//returns rvalue //const function
	if ( i > rows || j > cols || i < 1 || j < 1){
		cout << "Error: subscript(" << i << ", " << j << ") out of range"  << endl;
		exit(1);
	}
	return arrPtr[ (i-1)*cols + (j-1) ];
}
int& DoubleSubscriptedArray::operator()(int i , int j){ //returns lvalue //non-constant version function
	if ( i > rows || j > cols || i < 1 || j < 1){
		cout << "Error: subscript(" << i << ", " << j << ") out of range"  << endl;
		exit(1);
	}
	return arrPtr[ (i-1)*cols + (j-1) ];
}
bool DoubleSubscriptedArray::operator==( const DoubleSubscriptedArray &brr) const{
	if (this == &brr ) return true; //avoid self-comparing.
	if (rows == brr.rows && cols == brr.cols){
		for (int i = 0; i < rows*cols ; i++)
			if ( this->arrPtr[i] != brr.arrPtr[i]) return false;
		return true;
	}
	return false;
}
bool DoubleSubscriptedArray::operator!=( const DoubleSubscriptedArray &arr) const{
	return ! ( this->operator==( arr ) ); //Alternatively, return ! (*this = arr);
}
const DoubleSubscriptedArray& 	DoubleSubscriptedArray::operator=(const DoubleSubscriptedArray &brr ){
	if ( this == &brr ) return *this; //avoid self-assigning.

	delete [] arrPtr;
	int arrR = (rows = brr.rows);
	int arrC = (cols = brr.cols);
	arrPtr = new int [arrR * arrC];

	for ( int i = 0; i < arrC*arrR; i++)
		arrPtr[i] = brr.arrPtr[i];

	return *this;
}
