#include "SummingIntegers.hpp"

int SummingIntegers(){
	int howmanyNumbers=0, seqNum=0, total=0;
	cout << "Please input how many integers you want to sum.\n";
	cin >> howmanyNumbers;

	for (int count=1; count<=howmanyNumbers; count++){
		cout << "input an integer. \n";
		cin >> seqNum;
		total += seqNum;
	}

	return total;
}
