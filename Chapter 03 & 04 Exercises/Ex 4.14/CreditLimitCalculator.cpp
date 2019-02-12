#include "CreditLimitCalculator.hpp"


void CreditLimitCalculator(){
	int accNum=0;
	double Balance=0, charges=0, credits=0, creditLimit=0;

	//	cout << "Enter account number (or -1 to quit): \n";
	//	cin >> accNum;
	//	if (accNum==-1)
	//		return 0;

	while (accNum != -1){
		accNum=0, Balance=0, charges=0, credits=0, creditLimit=0;

		cout << "Enter account number (or -1 to quit):\n";
		cin >> accNum;
		if (accNum==-1)
			return;

		cout << "Enter beginning balance:\n";
		cin >> Balance;

		cout << "Enter total charges:\n";
		cin >> charges;

		cout << "Enter total credits:\n";
		cin >> credits;

		cout << "Enter credit limit:\n";
		cin >> creditLimit;

		Balance = Balance +charges - credits;
		cout << "New Balance is: " << Balance << endl << endl;

		if (Balance > creditLimit) {
			cout << "Account: " << accNum << endl;
			cout << "Caredit limit: " << creditLimit << endl;
			cout << "Balance: " << Balance << endl;
			cout << "Credit limit exceeded!" << endl << endl << endl;
		}
	}

}

