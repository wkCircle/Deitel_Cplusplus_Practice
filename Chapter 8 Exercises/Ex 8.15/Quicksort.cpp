//8.15
#include "Quicksort.hpp"
// prototyoe
inline void quickSort (int *, int , int );
inline int partition(int * const , int &, int &);

void Quicksort(){
	const int arrSize = 10;
	int arr[arrSize];
	const int sIndex = 0, eIndex = arrSize-1; // start and end index of an array.

	//initialization and print original values of the array
	cout << "The original arrya to be sorted is: \n";
	for (int i = 0; i < arrSize; i++)
		cout << setw(3) << (*(arr+i) = rand()%100+1 );
	cout << endl;

	//quickSort.
	quickSort( arr, sIndex, eIndex );

	//Print the result
	cout << "The array after sorting is: \n";
	for ( int i = 0; i < arrSize; i++)
		cout << setw(3) << *(arr+i);
	cout << endl;
}
inline void quickSort(int * const arrPtr, int sIndex, int eIndex){
	//Recursive return condition
	if (sIndex == eIndex)
		return;
	//Otherwise, partition and find the cut point.
	int distFromSI = partition(arrPtr, sIndex, eIndex);
    //one cut point divides an array into two pieces.
	quickSort(arrPtr, sIndex, max(sIndex, sIndex+distFromSI-1) );	//ensure that the later >= the former; otherwise, make them equal to each other.
	quickSort(arrPtr, min(sIndex+distFromSI+1, eIndex), eIndex);	//ensure that the later >= the former; otherwise, make them equal to each other.

}
inline int partition(int * const arrPtr, int &sIndex, int &eIndex){
	int * nPtr = arrPtr+sIndex; //Record target number's address and value waited to be coped with.
	int *posiPtr = arrPtr+eIndex;//will be the final position of the target *n.

	while (true){
		while (*nPtr <= *posiPtr && nPtr < posiPtr)//case for pointer from right direction: break while when encountering smaller.
			posiPtr--;
		while (*nPtr >= *posiPtr && nPtr > posiPtr)//case for pointer from left direction: break while when encountering larger.
			posiPtr++;
		if (nPtr == posiPtr) // if compare with itself, which means the mission is completed, then break the while and return.
			break;
		else {				 // otherwise, update(swap) pointers and their values and continue the while loop.
			swap(*nPtr, *posiPtr);
			swap(nPtr, posiPtr);
		}
	}//end while

	return static_cast<int>( nPtr-(arrPtr+sIndex) );
	/**< One can also use return nPtr method, but have to modify relevent code. >*/

}//end partition()

