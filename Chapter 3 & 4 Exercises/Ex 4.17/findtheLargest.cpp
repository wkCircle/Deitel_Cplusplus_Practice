#include "findtheLargest.hpp"

void findtheLargest(){
	int counter=1, number=0, largest=0;
	string a;

	while (counter<=10){

		switch (counter) {
			case 1:
				a = "st";
				break;
			case 2:
				a = "nd";
				break;
			case 3:
				a = "rd";
				break;
			default:
				a = "th";
				break;
		}
		cout << "Please input the " << counter << a << " number.\n";
		cin >> number;

		largest = max( largest, number);
		counter++;
	}
	cout << "The largest number among the 10 numbers is: " << largest << endl;
}
