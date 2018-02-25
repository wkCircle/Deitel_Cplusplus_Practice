//
//  Chapter11_Exercises.cpp
//  20170714 Chapter 11 Exercises
//
//  Created by kai on 14/11/2017.
//  Copyright © 2017 Wen-Kai Chung. All rights reserved.
//

#include "Chapter11_Exercises.hpp"

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
void Ex11_7main(){
	DoubleSubscriptedArray arrTest(2,2);
	DoubleSubscriptedArray brrTest(2,4);
	cout << "arr and brr before input: " << endl;
	cout << "arr: \n" << arrTest << endl << "brr:\n" << brrTest << endl;
	
	cout << "Now please input 12 integers into 2 arrays arr & brr: \n";
	cin >> arrTest >> brrTest;
	cout << "arr's content now becomes: \n" << arrTest << endl << "and brr's content now becomes: \n" << brrTest << endl;
	
	cout << "Is arr == brr ? \t" << ( arrTest == brrTest ? "Equal" : "Not Equal" ) << endl;
	cout << "Is arr != brr ? \t" << ( arrTest != brrTest ? "Not Equal" : "Euqal" ) << endl << endl;
	
	cout << "Assign brr to arr: \n" << (arrTest = brrTest) << endl;
	cout << "Is arr == brr ? \t" << ( arrTest == brrTest ? "Equal" : "Not Equal" ) << endl;
	cout << "Is arr != brr ? \t" << ( arrTest != brrTest ? "Not Equal" : "Euqal" ) << endl << endl;
	
	arrTest(2,2)=1000; //lvalue test
	cout << "Change value of arr(2,4)= 1000: \t" << arrTest(2,2) << endl; //rvalue test
	cout << "arr now becomes: \n" << arrTest << endl;
}







// Fig. 11.21: Complex.cpp (Modified)
// Complex class member-function definitions.
ostream & operator<<(ostream& output , Complex &h ){
	output << '(' << h.real << ", " << h.imaginary << ')';
	return output;
}
istream & operator>>(istream& input, Complex &h){
	//input form = (x, y)
	input.ignore(1); //ignore left parenthesis '('
	input >> h.real;
	input.ignore(1); //ignore comma','
	input >> h.imaginary;
	return input;
}
Complex::Complex( double realPart, double imaginaryPart ) : real( realPart ), imaginary( imaginaryPart ) {
	// empty body
}
Complex Complex::operator+( const Complex &h ) const {
	return Complex( real + h.real, imaginary + h.imaginary );
}
Complex Complex::operator-( const Complex &h ) const {
	return Complex( real - h.real, imaginary - h.imaginary );
}
Complex Complex::operator*( const Complex &h) const{
	return Complex( real * h.real - imaginary * h.imaginary  ,   real * h.imaginary + imaginary * h.real );
}
bool Complex::operator==( const Complex &h) const{
	return (real == h.real && imaginary == h.imaginary )? true: false ;
}
bool Complex::operator!=( const Complex &h) const{
	return !(*this == h);
}
void Ex11_8main(){  // Fig. 11.22: fig11_22.cpp
	Complex x, y( 4.3, 8.2 ), z( 3.3, 1.1 );
	
	cout << "x: " << x;
	cout << "\ny: "<< y;
	cout << "\nz: " << z;
	
	x=y+z;
	cout << "\n\nx = y + z:" << x << "=" << y << "+" << z;
	
	x=y-z;
	cout << "\n\nx = y - z:" << x << "=" << y << "-" << z;
	
	x=y*z;
	cout << "\n\nx = y * z:" << x << "=" << y << "*" << z;
	
	cout << "\n\n y==z? ANS: " << boolalpha << (y==z);
	cout << "\n y!=z? ANS: " << (y!=z) << noboolalpha;
	cout << endl;

}








// Fig. 11.24: Hugeint.cpp
// HugeInt member-function and friend-function definitions.
ostream& operator<<( ostream &output, const HugeInt &num ) {
	int i;
	for ( i = 0; num.integer[i] == 0  && i <= HugeInt::digits ; i++ )
		; // skip leading zeros
	
	if ( i == HugeInt::digits )
		output << 0;
	else
		for ( ; i < HugeInt::digits; i++ )
			output << num.integer[i];
	return output;
}
HugeInt::HugeInt( long value ){
	// initialize array to zero
	for(int i=0; i < digits; i++)
		integer[ i ] = 0;
	// place digits of argument into array
	int j = 0;
	for( j = digits-1; value !=0 && j >= 0 ; j--) {
		integer[ j ] = value % 10;
		value /= 10;
	}
	length = digits - (j+1);
}
HugeInt::HugeInt( const string &number ){
	// initialize array to zero
	for ( int i = 0; i < digits; i++ )
		integer[ i ] = 0;
	// place digits of argument into array
	length = (int)number.size();
	for ( int j = digits - length, k = 0; j < digits; j++, k++ )
		if ( isdigit( number[ k ] ) ) // ensure that character is a digit
			integer[ j ] = number[ k ] - '0';
}
HugeInt HugeInt::operator+( const HugeInt &op2 ) const {
	HugeInt temp; // temporary result
	int carry = 0;
	
	for ( int i = digits -1; i >= 0; i-- ) { //從第一位開始做運算
		temp.integer[i] = integer[i] + op2.integer[i] + carry;
		// determine whether to carry a 1
		if ( temp.integer[ i ] > 9 ){
			temp.integer[ i ] %= 10;
			carry = 1;
		}
		else carry = 0;
	}
	return temp;
}
HugeInt HugeInt::operator+( int op2 ) const{
	// convert op2 to a HugeInt, then invoke operator+ for two HugeInt objects
//	return *this + HugeInt( op2 );
	return *this + (HugeInt)op2; //Alternative expresstion.
}
HugeInt HugeInt::operator+( const string &op2 ) const{
	// convert op2 to a HugeInt, then invoke operator+ for two HugeInt objects
//	return *this + HugeInt( op2 );
	return *this + (HugeInt)op2; //Alternative expression.
}
HugeInt HugeInt::operator*( const HugeInt &op2 ) const{
	HugeInt temp; // temporary result
	int carry = 0, storePosi=0;
	for ( int i = digits-1; i >= digits - op2.length && i >= 0; i-- ) {
		for (int j = digits-1; j >= digits - (*this).length -1 && j >= 0 ; j--){ //多給一位 因為可能會有carry
			if (  digits-1 - ( (digits-1-i) + (digits-1-j) ) < 0 && carry > 0 ){
				cout << "ERR1: value too large, out of 30 digits.\n";
				exit(EXIT_FAILURE);
			}
			else if (temp.integer[0] > 9){
				cout << "ERR2: value too large, out of 30 digits.\n";
				exit(EXIT_FAILURE);
			}
			else {
				storePosi = digits-1 - (  (digits-1-i)+(digits-1-j)  );
				temp.integer[ storePosi ] += (integer[j] * op2.integer[i] + carry);
				// determine whether to carry some value
				if ( temp.integer[ storePosi ] > 9 ){
					carry = temp.integer[ storePosi ] / 10;
					temp.integer[ storePosi ] %= 10;
				}
				else carry = 0;
			}
		}//end for loop j
	}//end for loop i
	return temp;
}
HugeInt HugeInt::operator*( int op2 ) const{
	return (*this) * (HugeInt)op2;
}
HugeInt HugeInt::operator*( const string &op2 ) const{
	return (*this) * (HugeInt)op2;
}
HugeInt HugeInt::operator/( const HugeInt & op2 ) const {
	HugeInt temp; //temporary result
	int carry = 0;
	return temp;
}//待補
HugeInt HugeInt::operator/( int op2 ) const {
	return (*this) / (HugeInt)op2;
}
HugeInt HugeInt::operator/( const string & op2 ) const {
	return (*this) / (HugeInt)op2;
}
// Fig. 11.25: fig11_25.cpp
// HugeInt test program.
	
void Ex11_9main(){
	HugeInt n1(	7654321 );
	HugeInt n2( 7891234 );
	HugeInt n3( "99999999999999999999999999999" );
	HugeInt n4( "20" );
	HugeInt n5;
	
	//print original valuse
	cout << "n1 is " << n1 << "\nn2 is " << n2 << "\nn3 is " << n3 << "\nn4 is " << n4<< "\nn5 is " << n5;
	//test HugeInt + HugeInt
	n5 = n1 + n2;
	cout<< n1 <<"+"<< n2 <<"="<< n5 <<"\n\n";
	//test HugeInt + string version HugeInt
	cout<< n3 <<"+"<< n4 <<"\n="<< (n3+n4) <<"\n\n";
	//test HugeInt + int
	n5 = n1 + 9;
	cout<< n1 <<"+"<< 9 <<"="<< n5 <<"\n\n";
	//test HugeInt + string
	n5 = n2 + "10000";
	cout << n2 << " + " << "10000" << " = " << n5 << "\n\n";
	//test HugeInt * HugeInt
	n5 = n1 * n2;
	cout<< n1 <<"*"<< n2 <<"="<< n5 <<"\n\n";
	//test HugeInt * string version HugeInt
	cout<< n3 <<"*"<< n4 <<"\n=" << (n3*n4) <<"\n\n";
	//test HugeInt * int
	n5 = n1 * 9;
	cout<< n1 <<"*"<< 9 <<"="<< n5 <<"\n\n";
	
	
	
}









//Ex11.10
RationalNumber::RationalNumber(int numerator, int denominator){ //constructor
	//simplify values to get reduced form and validate inputs.
	*this = simplified(&numerator, &denominator);
}
RationalNumber::RationalNumber( const RationalNumber & obj ){
	numerator = obj.numerator;
	denominator = obj.denominator;
}
RationalNumber RationalNumber::simplified( const int *numPtr, const int *denPtr) const{
	//get reduced form and make the +/- sign stick with the numerator (so denominator is always positive).
	RationalNumber temp;
	//validate denominator
	if (*denPtr == 0){
		cout << "Denominator can't be zero.\n";
		exit(EXIT_FAILURE); //abort execution.
	}
	
	//find GCD
	size_t gcd = GCD( numPtr, denPtr);
	//update values
	if (gcd == 0){ //special case
		temp.numerator = 0;
		temp.denominator = 1;
	}
	else {
		temp.numerator =  *numPtr / static_cast<int>( gcd );
		temp.denominator = *denPtr / static_cast<int>( gcd );
		if ( *numPtr * *denPtr > 0 ){ // 同號
			temp.numerator = abs(*numPtr);
			temp.denominator = abs(*denPtr);
		}
		else if ( *numPtr * *denPtr < 0){ //異號
			temp.numerator = -1 * abs(*numPtr);
			temp.denominator = abs(*denPtr);
		}
	}//end else
	
	return temp;
}
RationalNumber RationalNumber::simplified( const RationalNumber & obj) const{
	return simplified( &obj.numerator, &obj.denominator );
}
int RationalNumber::GCD(const int *numPtr, const int *denPtr) const{
	if ( *numPtr == 0)
		return 0; //special case.
	
	int maxval = max( abs(*numPtr), abs(*denPtr));
	int minval = min( abs(*numPtr), abs(*denPtr));
	
	//find GCD
	while ( maxval % minval != 0){
		int temp = maxval % minval;
		maxval = minval;
		minval = temp;
	}
	return minval;
	//True for either case, maxval%minval ==0 or !=0.
	//minval 恆為正
}
RationalNumber RationalNumber::operator+( const RationalNumber & obj) const{
	RationalNumber temp;
	if ( obj.denominator == 0){ //obj is an integer.
		temp.numerator = numerator+ denominator * obj.numerator ;
		//denominator is unchanged.
	}
	else {
		int lcm = denominator* obj.denominator /GCD( &denominator, &obj.denominator);
		temp.numerator = (numerator * lcm / denominator )
						 + (obj.numerator * lcm / obj.denominator);
		temp.denominator = lcm;
	}
	return temp = simplified( temp );
}
RationalNumber RationalNumber::operator-( const RationalNumber & obj) const{
	RationalNumber temp;
	if ( obj.denominator == 0){ //obj is an integer.
		temp.numerator = numerator - denominator * obj.numerator ;
		//denominator is unchanged.
	}
	else {
		int lcm = denominator* obj.denominator/GCD(&denominator, &obj.denominator);
		temp.numerator = (numerator * lcm / denominator )
						- (obj.numerator * lcm / obj.denominator);
		temp.denominator = lcm;
	}
	return temp = simplified( temp );
}
RationalNumber RationalNumber::operator*( const RationalNumber & obj ) const{
	RationalNumber temp;
	RationalNumber objCopy(obj);
	//能約分先約分
	int gcd1 = GCD( &numerator, &obj.denominator);
	temp.numerator = numerator / gcd1;
	objCopy.denominator = obj.denominator / gcd1;
	int gcd2 = GCD( &obj.numerator, &denominator);
	objCopy.numerator = obj.numerator / gcd2;
	temp.denominator = denominator / gcd2;
	//最後乘起來並化簡
	temp.numerator *= objCopy.numerator;
	temp.denominator *= objCopy.denominator;
	return temp = simplified( temp );
}
RationalNumber RationalNumber::operator/( const RationalNumber & obj ) const{
	RationalNumber temp;
	RationalNumber objCopy(obj);
	//能約分先約分
	int gcd1 = GCD( &numerator, &obj.numerator);
	temp.numerator = numerator / gcd1;
	objCopy.numerator = obj.numerator / gcd1;
	int gcd2 = GCD( &obj.denominator, &denominator);
	objCopy.denominator =  obj.denominator / gcd2;
	temp.denominator = denominator / gcd2;
	//最後乘起來並化簡
	temp.numerator *= obj.denominator;
	temp.denominator *= obj.numerator;
	return temp = simplified( temp );
}
bool RationalNumber::operator==( const RationalNumber &obj) const{
	RationalNumber objCopy(obj);
	
	objCopy = simplified(obj);
	return (numerator == objCopy.numerator && denominator == objCopy.denominator)? true: false;
}
bool RationalNumber::operator!=( const RationalNumber &obj) const{
	return !( *this == obj );
}
bool RationalNumber::operator> ( const RationalNumber &obj) const{
	RationalNumber objCopy(obj);
	objCopy = simplified(obj);
	return (numerator * objCopy.denominator > denominator * objCopy.numerator);
}
bool RationalNumber::operator< ( const RationalNumber &obj) const{
	return !( *this > obj || *this == obj  );
}
bool RationalNumber::operator>=( const RationalNumber &obj) const{
	return (*this > obj || *this == obj);
}
bool RationalNumber::operator<=( const RationalNumber &obj) const{
	return (*this < obj || *this == obj);
}
void RationalNumber::printR(){
	cout << "Rational form: " << numerator << "/" << denominator << endl;
}
void RationalNumber::printFl(){
	cout << "floating form: " << static_cast<double>(numerator)/denominator << endl;
}


