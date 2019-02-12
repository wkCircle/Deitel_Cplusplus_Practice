#include "PrintanArray.hpp"
//prototype
void printArray( char [], size_t, size_t);

void printArray(){
	char array[] = " Ich Heise Setsuna. Vielen Dank."; // exsample string
	// one should change following values to test the code.
	printArray( array, 7, 7); // print posi from 7 to 7
	cout << endl;
	printArray( array, 8, 8);
	cout << endl;
	printArray(array, 8, 9); // print posi from 8 to 9
}
void printArray( char arr[], size_t sIndex, size_t endIndex){
	//While-method.
//	while ( sIndex != endIndex+1){
//		cout << arr[sIndex];
//		sIndex++;
//	}
//	cout << endl;

	//Recursive method
	if ( sIndex != endIndex+1){
		cout << arr[sIndex];
		printArray(arr, sIndex+1, endIndex);
	}

}
