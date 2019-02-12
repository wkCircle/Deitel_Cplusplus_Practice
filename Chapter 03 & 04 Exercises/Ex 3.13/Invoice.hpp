//
//  20170408 Chapter 3 & 4 Exercises.hpp
//  20170408 Chapter 3 & 4 Exercises
//
//  Created by ntueconRA on 2017/5/15.
//  Copyright © 2017年 Kai. All rights reserved.
//

#ifndef Invoice_hpp
#define Invoice_hpp

#include <cstdio>
#include <cmath>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <string>
#include <typeinfo>
using namespace std;



class Invoice {
public:
	Invoice(int partNumber, string Desciption, int Quantity, int Price);

	void setpartNumber(int);
	void setpartDsp(string);
	void setpartQuant(int);
	void setpartSinglePrice(int);

	int getpartNumber();
	string getpartDsp();
	int getpartQuant();
	int getpartSinglePrice();

	int getInvoiceAmount();

private:
	int partNumber;
	string partDsp;
	int partQuant;
	int partSinglePrice;

};


#endif //Invoice_hpp
