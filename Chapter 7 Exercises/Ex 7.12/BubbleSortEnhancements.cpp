#include "BubbleSortEnhancements.hpp"


void bubbleSortAlgorithm(int input[], int inputSize){
////insertion method
//	int temp = 0;
//
//	for(int n = 0+1; n < inputSize; n++){
//		temp = input[n];
//		int local = n;
//		while(local >0 && input[local-1] > temp){
//			input[local] = input[local-1];
//			local--;
//		}
//		input[local] = temp;
//	}
//
//	//print the result
//	for (int i=0; i< inputSize; i++)
//		cout << left << setw(4) << input[i];
////inseertion method END.

// method of 7.12 Only for decreasing sequence.
	int temp = 0;
	for(int n = inputSize-1 ; n > 0; n--){
		//pass values
		int truelocal = n;
		while (truelocal > 0 && input[truelocal-1] > input[n]){
			truelocal--;
		}
		//swap
		temp = input[n];
		input[n] = input[truelocal];
		input[truelocal] = temp;
		for(int i=0; i< inputSize; i++)
			cout << left << setw(4) << input[i];
		cout << endl;

	}
// method of 7.12 Only for decreasing sequence END
}
