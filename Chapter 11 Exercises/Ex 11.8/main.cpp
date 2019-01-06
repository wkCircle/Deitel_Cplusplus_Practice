#include "ComplexClass.hpp"
// Fig. 11.22: fig11_22.cpp
int main(){
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
