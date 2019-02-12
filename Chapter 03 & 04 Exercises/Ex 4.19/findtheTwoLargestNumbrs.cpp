#include "findtheTwoLargestNumbrs.hpp"

void findtheTwoLargestNumbrs(){
	int counter =1;
	double largest=0, number=0, secondlargest=0;
	string postfix="";

	while (counter <=10){
		switch (counter) {
			case 1:
				postfix = "st";
				break;
			case 2:
				postfix = "nd";
				break;
			case 3:
				postfix = "rd";
				break;
			default:
				postfix = "th";
				break;
		}

		cout << "Enter the " << counter << postfix << "number.\n";
		cin >> number;

		if (largest < number) {
			secondlargest = largest;
			largest = number;
		}
		else if (secondlargest < number) {
			secondlargest = number;
		}
		else {
			;
		}

		counter++;
	}
	cout << "The two largest numbers among the 10s are: " << largest << " and " << secondlargest << endl;

}
