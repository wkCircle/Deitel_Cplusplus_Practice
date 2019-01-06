#include "ComplexClass.hpp"
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
