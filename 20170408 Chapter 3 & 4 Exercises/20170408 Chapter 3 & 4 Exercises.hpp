//
//  20170408 Chapter 3 & 4 Exercises.hpp
//  20170408 Chapter 3 & 4 Exercises
//
//  Created by ntueconRA on 2017/5/15.
//  Copyright © 2017年 Kai. All rights reserved.
//

#ifndef _0170408_Chapter_3___4_Exercises_hpp
#define _0170408_Chapter_3___4_Exercises_hpp

#include <cstdio>
#include <cmath>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <string>
#include <typeinfo>
using namespace std;

class ExerCh3and4 {
public:
	
	void gasMileage4_13();
	void CreditLimitCalculator4_14();
	void salesCommissionCalculator4_15();
	void salaryCalculator4_16();
	void findtheLargest4_17();
	void tabularOutput4_18();
	void findtheTwoLargestNumbrs4_19();
	void squareOfAsterisks4_25();
	void paLindromes4_26();
	void decimmalEquivalentofaBinaryNumber4_27();
	void checkerboardPatternOfAsterisks4_28();
	void multiplesOf2withanInfiniteLoop4_29();
	void sidesOfTriangleAndRightTriangle4_32and33();
	void facTorial4_34();
	void enforcingPrivacyWithCryptography4_35();
	
};


class Invoice3_13 {
public:
	Invoice3_13(int partNumber, string Desciption, int Quantity, int Price);
	
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


class Account3_12 {
public:
	Account3_12(string unserName, int accBalance);
	void setUser(string);
	string getUser();
	void setAccBalance(int); // access initial account balance.
	int getBalance(); //show current account balance
	void credit(int); //deposit money
	void debit(int); //withdraw money
	
private:
	string userName;
	int accBalance;
	
};


class GradeBook3_11 {
	
public: // access specifier.
	
	GradeBook3_11(string courseName, string leturerNamesss);			//constructor
	void setCourseName(string); //func that sets the courseName.
	string getCourseName();
	
	void setLecturerName(string);
	string getLecturerName();
	
	void determineClassAverage();
	
	void displayMessage();
	
	
private:
	string courseName;
	string lecturerName;
	
};

#endif /* _0170408_Chapter_3___4_Exercises_hpp */
