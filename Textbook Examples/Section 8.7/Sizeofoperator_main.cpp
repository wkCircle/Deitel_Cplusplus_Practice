//Fig 8.14
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

size_t getSize( double * ); // prototype


int main(){

	double array[ 20 ]; // 20 doubles; occupies 160 bytes on our system
	cout << "The number of bytes in the array is " << sizeof( array );
	cout << "\nThe number of bytes returned by getSize is " << getSize( array ) << endl;

	array[0] = *( array +3);
}
size_t getSize( double *ptr ){
    /*return return size of ptr*/
	return sizeof( ptr );
}// end function getSize






/**<sizeof (arr) = 160, returns the size of arr in bytes.
	sizeof (ptr) = 8, where *ptr = arr , returns the size of pointer in bytes
 (�]�N�O���Х����t�m�O���骺�j�p, ��t�Φ����P���󫬺A�L��), not the size of arr in bytes.
	sizeof (*ptr) = 4, returns the size of the type of arr's 1st element, i.e. arr[0]
	PS1. sizeof �᭱���A��() �u���b�ѼƬOdata type�ɤ~���n, �_�h���i�H���g. E.g., sizeof( int ), sizeof arrayName; >**/
//	sizeof is a compile-time unary operator, not an execution-time operator, using sizeof does not negatively impact execution performance!!!

