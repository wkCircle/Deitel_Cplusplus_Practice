#include "ComplexClass.hpp"

complex::complex(double realPart, double imiginaryPart){
	complex::realPart = realPart;
	complex::imiginaryPart = imiginaryPart;
}
void complex::add( complex obj){
	realPart += obj.realPart;
	imiginaryPart += obj.imiginaryPart;
}
void complex::subtract(complex obj ){
	realPart -= obj.realPart;
	imiginaryPart -= obj.imiginaryPart;
}
void complex::printcomplex(){
	cout << "complex value is: (" << realPart << ", " << imiginaryPart << ")\n";
}
