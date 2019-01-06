#include "FindtheSmallestInteger.hpp"

int FindtheSmallestInteger(){
	int howmanynumbers=0, seqNum=0, smallest=0;
	cout << "Input a number to specify how many integers you're gonna input to comapre to find the smallest value.\n";
	cin >> howmanynumbers;

	//	cout << "Input a number.\n";
	//	cin >> seqNum;
	//	smallest = seqNum;
	for (int count =1; count <= howmanynumbers; count++ ){
		cout << "Input a number.\n";
		cin >> seqNum;
		if (count==1)
			smallest = seqNum;

		smallest = min(smallest, seqNum);
	}
	return smallest;
}
