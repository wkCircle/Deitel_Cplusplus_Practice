#include "LinearSearch.hpp"
//prototpye
int linearSearch( int [], int, int );

void LinearSearch(){
    int key = 3; // NOTE: one should change key value to test the code.


	const int arrSize = 100;
	int arr[arrSize] = {};
	int position = 0;
	//initialize arr[] randomly. NOTE: one can use seed to adjust the randomness.
	for (int i =0; i < arrSize; i++)
		arr[i] = rand()%100;

	//function call
	position = linearSearch(arr, key, arrSize);

	//print result:
	if (position != -1 )
		cout << "The key value " << key << " is found in position " << position << " in the array\n";
	else
		cout << "Key value not found.\n";
}
int linearSearch( int arr[],int key, int arrSize){
	//if find the value, return the location
	if (arr[arrSize-1] == key)
		return arrSize-1;
	//if not, then check if arrSize is still >0 and then return recursive function
	else if (arrSize > 0)
		return linearSearch(arr, key, arrSize-1);
	//if didn't find the key until arrSize == 0
	else
		return -1;
}

