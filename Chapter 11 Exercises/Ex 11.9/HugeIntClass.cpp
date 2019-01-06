#include "HugeIntClass.hpp"

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
