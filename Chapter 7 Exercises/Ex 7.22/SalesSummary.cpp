#include "SalesSummary.hpp"

void SalesSummary(){
	int salesperson_num = 0, prod_num = 0, temp = 0, totalTotal = 0;
	const int Salespeople = 4, Products = 5;
	int sales[Products][Salespeople]={};
	char Answer=' ';
	cout << "Input a slip message containing three information in order\n";
	while(true){ //first while, ask whether to continue to input values after printing result table.

		while(true){ //second while ,loop for value input.

			cout << "1. Salesperson number(1~4)/ or -1 to quit to terminate the program.(your only chance)\n";
			cin >> salesperson_num;
			while (salesperson_num < 0 || salesperson_num >4){
				if ( salesperson_num == -1){
					return;
				};
				cout << "Invalid Input. Try again.(1~4)\n";
				cin >> salesperson_num;
			}


			cout << "2. Product number(1-5)\n";
			cin >> prod_num;
			while ( prod_num < 0 || prod_num >5){
				cout << "Invalid Input. Try again.(1~5)\n";
				cin >> prod_num;
			}


			cout << "3. Total dollar value of that product sold that day(>0).\n";
			cin >> temp;
			while ( temp < 0 ){
				cout << "Invalid Input. Try again.(1~5)\n";
				cin >> temp;
			}
			//Assign value to sales array. (Accumulative '+=')
			sales [prod_num -1 ][salesperson_num -1 ] += temp;

			cout << "Continue to input value? Or see the result? [L;R]\n";
			cin >> Answer;
			while(Answer != 'L' && Answer != 'l' && Answer != 'R' && Answer != 'r'){
				cout << "Err. Input L or R again.\n";
				cin >> Answer;
			}
			if( Answer == 'R' || Answer == 'r')
				break;
		}// end second while

		//print the result
		//header
		cout << endl << fixed << right << setw(12) << "ProdNum";
		for (int i = 0; i < Salespeople; i++)
			cout << setw(10) << "Person" << i+1;
		cout << setw(15) << "ProdTotal$";
		cout << endl;
		//body
		totalTotal = 0; //initailize
		for (int row = 0; row < Products ; row++){
			temp = 0;												//initialize
			cout << setw(11) << "Prod" << row+1;					//front words
			for (int column = 0; column < Salespeople; column++){	//intermediate words
				cout << setw(11) << sales[row][column];
				temp += sales[row][column];
			}
			cout << setw(15) << temp << endl;						//end words (total $ of that product)

			totalTotal += temp;
		}
		//Final row
		cout << setw(12) << "PersonTotal$";
		for (int column = 0; column < Salespeople; column++){
			temp = 0;
			for (int row = 0; row < Products; row++){
				temp += sales[row][column];
			}
			cout << setw(11) << temp;
		}
		cout << setw(15) << totalTotal << endl;

		//continue or not?
		cout << "Continue to input? or Exit the program? [L;R]\n";
		cin >> Answer;
		while(Answer != 'L' && Answer != 'l' && Answer != 'R' && Answer != 'r'){
			cout << "Err. Input L or R again.\n";
			cin >> Answer;
		}
		if( Answer == 'R' || Answer == 'r')
			return;

	}//end first while
}
