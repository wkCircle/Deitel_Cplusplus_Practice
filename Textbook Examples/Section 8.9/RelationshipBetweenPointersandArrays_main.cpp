//Fig8.18 & Section 8.9 Relationship Between Pointers and Arrays
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


int main(){
	int b[] = { 10, 20, 30, 40 }; // create 4-element array b
	int *bPtr = b; // set bPtr to point to array b

	// output array b using array subscript notation
	cout << "Array b printed with:\n\nArray subscript notation\n";
	for(int i=0; i < 4; i++)
		cout << "b[" << i << "] = " << b[ i ] << '\n';

	// output array b using the array name and pointer/offset notation
	cout << "\nPointer/offset notation where " << "the pointer is the array name\n";
	for ( int offset1 = 0; offset1 < 4; offset1++ )
		cout << "*(b + " << offset1 << ") = " << *( b + offset1 ) << '\n';

	// output array b using bPtr and array subscript notation
	cout << "\nPointer subscript notation\n";
	for(int j=0; j < 4; j++)
		cout << "bPtr[" << j << "] = " << bPtr[ j ] << '\n';

	// output array b using bPtr and pointer/offset notation
	cout << "\nPointer/offset notation\n";
	for ( int offset2 = 0; offset2 < 4; offset2++ )
		cout << "*(bPtr + " << offset2 << ") = " << *( bPtr + offset2 ) << '\n';
}



/**< sum up here, you can use
	arr[n], ptr[n]			(array subscript notation, pointer subscript notation)
 or *(arr+n), *(ptr+n):		(arrayname pointer offset notation, pointer offset notation)
 to take the value of an array's position n. >**/
/**<Note: cin/cout assume that character arrays should be processed as strings terminated by null characters;
	cin/cout do not provide similar input and output processing capabilities for other array types.>**/


