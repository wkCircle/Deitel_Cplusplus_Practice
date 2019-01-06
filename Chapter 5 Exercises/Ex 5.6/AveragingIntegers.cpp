#include "AveragingIntegers.hpp"

int AveragingIntegers(){
	double average=0.0;
	int seqNum=0, count=0;

	for (; seqNum != 9999; ){
		cout << "Input a number to be averaged. Enter 9999 if you want to stop and start averaging.\n";
		cin >> seqNum;
		if (seqNum==9999)
			break;

		average = ( (static_cast<double>(average) * count) + seqNum )/ (count+1);
		count++;
	}
	cout << average << endl;
	return average;
}
