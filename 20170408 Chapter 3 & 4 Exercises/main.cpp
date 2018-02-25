//
//  main.cpp
//  20170408 Chapter 3 & 4 Exercises
//
//  Created by ntueconRA on 2017/5/15.
//  Copyright © 2017年 Kai. All rights reserved.
//

#include "20170408 Chapter 3 & 4 Exercises.hpp"



int main(int argc, const char * argv[]) {
	
	//Following is used for executing other exercises:
	ExerCh3and4 Rabbit;
	Rabbit.gasMileage4_13();
	Rabbit.CreditLimitCalculator4_14();
	Rabbit.salesCommissionCalculator4_15();
	Rabbit.salaryCalculator4_16();
	Rabbit.findtheLargest4_17();
	Rabbit.tabularOutput4_18();
	Rabbit.findtheTwoLargestNumbrs4_19();
	Rabbit.squareOfAsterisks4_25();
	Rabbit.paLindromes4_26();
	Rabbit.decimmalEquivalentofaBinaryNumber4_27();
	Rabbit.checkerboardPatternOfAsterisks4_28();
	Rabbit.sidesOfTriangleAndRightTriangle4_32and33();
	Rabbit.facTorial4_34();
	Rabbit.enforcingPrivacyWithCryptography4_35();
	
	//Following is used for Exercise 3.12 Account Class
	{
		Account3_12 Account1("Chung, Wen-Kai", 300000);
		Account3_12 Account2("Houston Hung", 250000);
		int userNumber=0, amount=0;
		string action="";
		//Test only
		//	cout << "the initial balance for " << Account1.getUser() <<" is: " << Account1.getBalance() << ".\n";
		//	cout <<"the initial balance for " << Account2.getUser() <<" is: " << Account2.getBalance() << ".\n";
		
		cout << "Please choose a representive number. [1 for "<< Account1.getUser() <<"/2 for "<< Account2.getUser() << ".]\n";
		cin >> userNumber;
		while (userNumber != 1 && userNumber != 2 ) {
			cout << "Invalid value, please only input either 1 or 2 to represent the user you wanna modify.\n";
			cin >> userNumber;
		};
		cout << "Choose an action.[deposit/withdraw]" << endl;
		cin >> action;
		while ( action != "deposit" && action != "withdraw"){
			cout << "Invlaid input. Please only input either \"deposit\" or \"withdraw\".\n";
			cin >> action;
		};
		cout << "Please input the amount of money you wanna " << action << ".\n";
		cin >> amount; //輸入asdf也會對...該怎麼辦？
		
		if (userNumber == 1){
			if (action == "deposit")
				Account1.credit(amount);
			else
				Account1.debit(amount);
		}
		else if (userNumber == 2){
			if (action == "deposit")
				Account2.credit(amount);
			else
				Account2.debit(amount);
		}
		cout << "moeny is: "<< Account1.getBalance()<< endl;
		cout << "moeny is: "<< Account2.getBalance()<<endl;
	}
	
	//Following is used for Exercise 3.13 Invoice Class
	{
		Invoice3_13 invoiceEX(03734301, "Hard Drive- Synology", 2, 8888);
		Invoice3_13 invoiceDF(03732265, "Airplane ticket for busniess class including fwd and bwd trip", 1, 150000);
		
		//	Test only
		cout << "Your input for invoiceEX is: \n"
		<< "Invoice Number: "	<< invoiceEX.getpartNumber() << endl
		<< "Item Description: "	<< invoiceEX.getpartDsp()	 << endl
		<< "Item Quantity: "	<< invoiceEX.getpartQuant()	 << endl
		<< "Price per Item: "	<< invoiceEX.getpartSinglePrice() << endl;
		cout << "The total amount on the invoiceEX is: " << invoiceEX.getInvoiceAmount() << endl << endl;
		
		cout << "Your input for invoiceDF is: \n"
		<< "Invoice Number: "	<< invoiceDF.getpartNumber() << endl
		<< "Item Description: "	<< invoiceDF.getpartDsp()	 << endl
		<< "Item Quantity: "	<< invoiceDF.getpartQuant()	 << endl
		<< "Price per Item: "	<< invoiceDF.getpartSinglePrice() << endl;
		cout << "The total amount on the invoiceDF is: " << invoiceDF.getInvoiceAmount() << endl << endl;
	}
	
}

