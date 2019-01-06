#include "cubeByReference.hpp"

int main(){
    int number = 5;
	cout << "The original value of number is " << number;
	cubeByReference( &number ); // pass number address to cubeByReference
	cout << "\nThe new value of number is " << number << endl;
}
