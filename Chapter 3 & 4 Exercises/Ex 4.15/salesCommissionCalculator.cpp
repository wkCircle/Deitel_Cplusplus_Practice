#include "salesCommissionCalculator.hpp"


void salesCommissionCalculator(){
	double bonus=0;

	while (bonus != -1){
		cout << "Enter sales in dollars.(or -1 to quit)\n";
		cin >> bonus;
		if (bonus==-1)
			return;
		cout << "salary is: $" << 200 + bonus* 0.09 <<endl;
	}
}
