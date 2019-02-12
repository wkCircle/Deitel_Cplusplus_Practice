#include "SelectionSort.hpp"
// prototype
void selectionSort( int [], const int );


void SelectionSort(){
    /*main function here*/
	const int arrSize = 10;
	int arr[arrSize]= {3,7,10,15,100,  1010,-57, -5, -10, 0};
    cout << "Before selection sore is:" << endl;
    for (int i = 0; i < arrSize; i++)
        cout << setw(5) << arr[i];
	cout << endl;

	selectionSort(arr, arrSize);

    cout << "After selection sore is:" << endl;
	for (int i = 0; i < arrSize; i++)
		cout << setw(5) << arr[i];
	cout << endl;
}

void selectionSort(int arr[], const int arrSize ){
	static int m = 0;
	m++; //record the times calling the recursive method and record the posi that starts sorting.
	if ( arrSize-m == 0)
		return;
	else{
		int i = 0, location = 0, minelem = 10000;
		//find the smallest
		for (i = m-1; i < arrSize; i++)
			if ( arr[i] < minelem){
				location = i;
				minelem = arr[i];
			}
		//swap with first elem
		arr[location] = arr[m-1];
		arr[m-1] = minelem;

		selectionSort(arr, arrSize ); // recursive call
	}
}

