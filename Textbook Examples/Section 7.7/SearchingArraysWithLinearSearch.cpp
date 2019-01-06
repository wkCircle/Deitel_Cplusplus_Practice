//Sec 7.7 Searching Arrays with Linear Search
#include "SearchingArraysWithLinearSearch.hpp"

int linearSearch( const int [], int, int); //function prototype
void SearchingArraysWithLinearSearch(){
	//linear search compares each element of an array with a search key.

	const int arraySize = 100;
	int a[ arraySize ];
	int searchKey; // value to locate in array a

	for(int i=0; i < arraySize; i++)
		a[ i ] = 2 * i; // create some data

	cout << "Enter integer search key: ";
	cin >> searchKey;

	int element = linearSearch( a, searchKey, arraySize );

	// display results
	if(element!=-1)
		cout << "Found value in element " << element << endl;
	else
		cout << "Value not found" << endl;
}
int linearSearch( const int array[], int key, int sizeOfArray ) {
	for ( int j = 0; j < sizeOfArray; j++ )
		if(array[j] == key)//iffound, return j; // return location of key
			return j;

	return -1; // key not found
}
