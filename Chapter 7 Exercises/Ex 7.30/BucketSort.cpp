//7.30 Bucket Sort!!!! (Better than insertion sort in performance but requires more memory) A trade-off.
#include "BucketSort.hpp"

//prototype
void bucketSort( size_t [], const size_t );


void BucketSort(){
	const size_t arrSize = 20;
	size_t arr[arrSize] = {3,9,7,100,14,  20,1024,6,2,3964  ,1,1042,5,11,12  ,17,10,110,7,19};//must be positive integers

	cout << "Before bucket sorting, the sequence is: \n";
	for (size_t k = 0; k < arrSize; k++)
		cout <<setw(5) << arr[k];
	cout << endl << endl;
	bucketSort(arr, arrSize);
}

void bucketSort( size_t arr[], const size_t arrSize){
	size_t arr_bucket[10][arrSize];
	size_t maxDigit = 1, temp = 0, cateGory = 0, k = 0;
	size_t countarr = 0;


	//find the max digit in arr[]
	for ( k = 0; k < arrSize; k++){
		if ( arr[k] == 0 )
			continue;
		else if (	( temp = floor(log10(arr[k])) +1 )	>	maxDigit		)
			//note: cannot use ceiling() instead. CounterEg: arr[k] = 100
			maxDigit = temp;
	}

	//first for loop begins. Run through all digits.
	for (int digit = 1; digit < maxDigit+1; digit++){

		//initialize arr_bucket
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < arrSize; j++)
				arr_bucket[i][j] = 0;

		//Distribution Pass: categorize each elem in arr[] according to its value of the current digit.
		for ( k = 0; k < arrSize; k++){
			cateGory = (	arr[k] % static_cast<size_t>(pow(10,digit) )	) / static_cast<size_t>(pow(10, digit-1));
			temp = 0;
			//put the new element into the first empty entry of a specified row.
			while ( arr_bucket[cateGory][temp] != 0){
				temp++;
			}//end while
			arr_bucket[ cateGory ] [temp] = arr[k];
		}//end for

		//Gathering Pass: copy the temparory result to original array: arr[]
		countarr = 0;
		for ( k = 0 ; k < 10; k++){//run through all rows(categories).
			temp = 0;
			while ( arr_bucket[k][temp] != 0){
				arr[countarr] = arr_bucket[k][temp];
				countarr++;
				temp++;
			}//end while
		}//end for.

//		//test: if you want to deubg/explore the method, decomment the following codes.
//		cout << "Current arr_bucket is: \n";
//		for (int i = 0; i < 10; i++){
//			for (int j = 0; j < arrSize; j++){
//				cout << setw(4) << arr_bucket[i][j];
//			}
//			cout << endl;
//		}
//		cout << "\nAND current arr[arrSize] is: \n";
//		for (k = 0; k < arrSize; k++)
//			cout <<setw(6) << arr[k];
//		cout << endl << endl;

	}//end 1st for.

	//print the result
	cout << "After bucket sorting, the sequence is: \n";
	for (k = 0; k < arrSize; k++)
		cout <<setw(5) << arr[k];
	cout << endl << endl;

}
