//
//  20170408 Chapter 3 & 4 Exercises.cpp
//  20170408 Chapter 3 & 4 Exercises
//
//  Created by ntueconRA on 2017/5/15.
//  Copyright © 2017年 Kai. All rights reserved.
//

#include "20170408 Chapter 3 & 4 Exercises.hpp"
using namespace std;

//GradeBook Exercises
GradeBook3_11::GradeBook3_11(string courseName, string lecturerName){
	setCourseName(courseName);
	setLecturerName(lecturerName);
}
void GradeBook3_11::setCourseName(string name){
	if (name.length() <= 25)
		courseName = name;
	else {
		courseName = name.substr(0, 25);	//start at 0, length of 25.
		cout << "Name \"" << name << "\" exceeds max length (25). \n";
		cout << "Limiting course name to first 25 characters. \n";
	}
}
string GradeBook3_11::getCourseName(){
	return courseName;
}
void GradeBook3_11::setLecturerName(string name){
	lecturerName = name;
}
string GradeBook3_11::getLecturerName(){
	return lecturerName;
}
void GradeBook3_11::determineClassAverage(){
	int total=0;
	int gradeCounter=0;
	double grade=0; //if int type, error will occur. (endless loop witout stoping)
	double average=0.00;
	
	cout << "Please enter grade or -1 to quit.\n";
	cin >> grade;
	while (grade != -1 && grade <0 ){
		cout << "Invalid value. Please in put a score >=0.\n";
		cin >> grade;
	}
	
	
	while (grade != -1 ){
		while (grade != -1 && grade <0 ){
			cout << "Invalid value. Please input a score >=0 or -1 to quit.\n";
			cin >> grade;
		}
		if (grade == -1)
			break;
		
		total += grade;
		gradeCounter += 1;
		
		cout << "Please enter grade or -1 to quit." <<endl;
		cin >> grade;
	}
	
	
	
	if (gradeCounter != 0){
		// average = total / 10.00;
		//notice that 'total': type int, '10.00': type int.
		// If we replace 10.00 by 10, then total/10 will be int type, which leads to the wrong average answer.
		average  = static_cast<double>(total) / gradeCounter; //cast operator!
		
		cout << "\nTotal of all " << gradeCounter << " grades entered is " << total << endl;
		cout << "Class average is " << setprecision(2) << fixed << average << endl;
	}
	else
		cout << "No grades were entered" << endl;
}
void GradeBook3_11::displayMessage(){
	cout << "Welcome to the Grade Book for " << courseName << "!" << "\nThis course is presented by " << getLecturerName() << "."<< endl;
}


Account3_12::Account3_12(string userName, int accBalance){
	setUser(userName);
	setAccBalance(accBalance);
}
void Account3_12::setUser(string name){
	userName = name;
}
string Account3_12::getUser(){
	return userName;
}
void Account3_12::setAccBalance(int money){
	if (money>=0)
		accBalance = money;
	else {
		accBalance = 0;
		cout << "Err. Invalid value for initial balance(>=0).\nPlease try again.\n";
	}
}
int Account3_12::getBalance(){
	return accBalance;
}
void Account3_12::credit(int deposit){
	if (deposit>=0)
		accBalance = accBalance + deposit;
	else {
		deposit = 0;
		cout << "Err. Invalid value for moeny being deposited.\nPlease try again.\n";
	}
}
void Account3_12::debit(int withdraw){
	if (withdraw>=0 && withdraw<= accBalance)
		accBalance = accBalance - withdraw;
	else {
		withdraw = 0;
		cout << "Err. Invalid value for moeny being withdrawed.\nPlease try again.\n";
	}
}


Invoice3_13::Invoice3_13(int Num, string Dsp, int q, int p){
	setpartNumber(Num);
	setpartDsp(Dsp);
	setpartQuant(q);
	setpartSinglePrice(p);
}

void Invoice3_13::setpartNumber(int num){
	partNumber = num;
}
void Invoice3_13::setpartDsp(string dsp){
	partDsp = dsp;
}
void Invoice3_13::setpartQuant(int q){
	if (q <0){
		q=0;
		cout << "Invalid value. Please set a nonnegative quantity.\n";
	}
	else
		partQuant = q;
}
void Invoice3_13::setpartSinglePrice(int p){
	if (p <0){
		p=0;
		cout << "Invalid value. Please set a nonnegative quantity.\n";
	}
	else
		partSinglePrice = p;
}
int Invoice3_13::getpartNumber(){
	return partNumber;
}
string Invoice3_13::getpartDsp(){
	return partDsp;
}
int Invoice3_13::getpartQuant(){
	return partQuant;
}
int Invoice3_13::getpartSinglePrice(){
	return partSinglePrice;
}
int Invoice3_13::getInvoiceAmount(){
	int totalPrice=0;
	totalPrice = partQuant * partSinglePrice;
	return totalPrice;
}

void ExerCh3and4::gasMileage4_13(){
	int miles=0, gallons=0,counter=1;
	double avg=0, MpG=0;
	
	while (miles != -1){
		cout << "Enter miles driven (-1 to quit): \n";
		cin >> miles;
		if (miles == -1)
			return;
		
		cout << "Enter gallons used: \n";
		cin >> gallons;
		MpG = static_cast<double>(miles) / static_cast<double>(gallons);
		cout << "MPG this tankful: " << MpG << endl;
		
		avg = (avg * (counter-1) + MpG)/ (counter);
		cout << "Total MPG: " << avg << endl;
		counter++;
	}

}
void ExerCh3and4::CreditLimitCalculator4_14(){
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
void ExerCh3and4::salesCommissionCalculator4_15(){
	double bonus=0;
	
	while (bonus != -1){
		cout << "Enter sales in dollars.(or -1 to quit)\n";
		cin >> bonus;
		if (bonus==-1)
			return;
		cout << "salary is: $" << 200 + bonus* 0.09 <<endl;
	}
}
void ExerCh3and4::salaryCalculator4_16(){
	int wk_hrs=0;
	double rate_hr=0;
	
	while (wk_hrs != -1){
		cout << "Enter hours worked (or -1 to quit). \n";
		cin >> wk_hrs;
		if (wk_hrs == -1)
			return;
		
		cout << "Enter hourly rate of the employee.($00.00)\n";
		cin >> rate_hr;
		
		if (wk_hrs <= 40)
			cout << "Salary is: " << wk_hrs * rate_hr << endl ;
		else
			cout<< "Salary is: "<< wk_hrs * rate_hr + (wk_hrs-40) * rate_hr *0.5 << endl;
	}

}
void ExerCh3and4::findtheLargest4_17(){
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
void ExerCh3and4::tabularOutput4_18(){
	int N=1;
	
	cout << "N \t 10*N \t100*N \t1000*N \n \n";
	while (N <= 5){
		cout << N << "\t " << 10*N << "\t \t" << 100*N << "\t \t" << 1000*N << "\t" << endl;
		N++;
	}
}
void ExerCh3and4::findtheTwoLargestNumbrs4_19(){
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

void Method1of4_25(){
	int sideSize=1;
	int count=1;
	string starStr="";
	string interstarStr="*";
	
	cout << "Input a size of the hollow suqare.(or 0 to quit)\n";
	cin >> sideSize;
	if (sideSize == 0)
		return;
	
	//Head
	while (count <= sideSize){
		starStr = starStr + '*';
		count++;
	}
	cout << starStr << endl;
	
	//Body and Tail
	//case for sideSize <= 2
	if (sideSize == 1)
		return;
	else if (sideSize == 2){
		cout << starStr << endl;
		return;
	}
	//case for sideSize >2
	count=1;
	while (count <= sideSize-2){
		interstarStr = interstarStr + ' ' ;
		count++;
	}
	interstarStr = interstarStr + '*' ;
	count=1;
	while (count <= sideSize-2){
		cout << interstarStr << endl;
		count++;
	}
	
	cout << starStr << endl;
}
void Method2of4_25(){
	int sideSize=1;
	cout << "Input a size of the hollow suqare.(or 0 to quit)\n";
	cin >> sideSize;
	if (sideSize == 0)
		return;
	
	for (int row=1; row<=sideSize; row++) {
		for(int column=1; column<=sideSize; column++) {
			if ( row==1 || row==sideSize || column==1 || column==sideSize)
				cout << '*';
			else
				cout << ' ';
		}
		cout << endl;
	}

}
void ExerCh3and4::squareOfAsterisks4_25(){
		Method1of4_25();
		Method2of4_25();
}

void ExerCh3and4::paLindromes4_26(){
	int number=0;
	
	while (number != -1){
		cout << "Input a five-digit integer to check if it's a palindrome or -1 to quit.\n";
		cin >> number;
		if (number == -1)
			return;
		
		while (number < 1000) {
			cout << "Err. Input a 4, or 5-digit integer. (if you input a 4-digit number, system will automatically regard the fifth digit as 0 to compile.\n";
			cin >> number;
			if (number == -1)
				return;
		}
		
		//core
		if (number/10000 == number % 10){
			if ( (number % 10000) /1000  ==  (number % 100) /10 )
				cout << "This number is a palindrome.\n";
		}
		else
			cout << "This number is not a palindrome.\n";
	}

}
void ExerCh3and4::decimmalEquivalentofaBinaryNumber4_27(){
	long int bnyNum = 0;
	int deciNum = 0;
	int count = 0;
	
	while ( bnyNum != -1){
		cout << "Input a binary integers or 0 to quit.(System will regard any digit that is not 0 or 1, for example, 7, as 7%2 = 1)\n";
		cin >> bnyNum;
		if (bnyNum == -1)
			return;
		
		count = 0;
		
		deciNum = 0;
		while (bnyNum != 0 ) {
			deciNum += ((bnyNum % 2) * pow(2, count)) ;
			bnyNum /= 10;
			
			count++;
		}
		
		cout << "The corresponding decimal number is: " << deciNum << endl;
	}

}
void ExerCh3and4::checkerboardPatternOfAsterisks4_28(){
	for ( int i = 1; i <= 8; i++){
		if ( i % 2 ==0 ){
			cout << ' ';
		}
		for ( int j = 1; j <= 8; j++){
			cout << "* ";
		}
		cout << endl;
	}
}
void ExerCh3and4::multiplesOf2withanInfiniteLoop4_29(){
	int x=1;
	while (true){
		cout << (x *= 2) << endl;
	}
}
void ExerCh3and4::sidesOfTriangleAndRightTriangle4_32and33(){
	double a = 0.0, b = 0.0, c = 0.0;
	double temp = 0.0;
	while (a>=0 && b>=0 && c>=0){
		// Input and Reorder s.t. a>b>c
		cout << "Input the 1st side.\n";
		cin >> a;
		if (a<0)
			return;
		cout << "Input the 2nd side.\n";
		cin >> b;
		if (b<0)
			return;
		
		if (a<b){
			temp = a;
			a = b;
			b = temp;
		}
		
		cout << "Input the 3rd side.\n";
		cin >> c;
		if (c<0)
			return;
		
		if (c > a){
			temp = a;
			a = c;
			c = b;
			b = temp;
		}
		else if (c>b){
			temp = b;
			b = c;
			c = temp;
		}
		
		//Triangle  and Right triangle iff condition.
		if ( b+c > a) {
			if( c*c + b*b == a*a ){
				cout << "Ja! Das ist auch ein right triangle.\n";
			}
			else
				cout << "Das ist ein triangle, but nicht ein right triangle.\n";
		}
		else
			cout << "Nein, das ist nicht ein triangle.\n";
	}

}

inline int factorial4_34( int m){
	int m_fac = 1 ; // including case x = 0 or 1
	while (m > 1) {
		m_fac *= m-- ;
	}
	return m_fac;
}
inline double natureEestimation4_34( int denominator){
	double e = 0.0;
	while (denominator >= 0){
		e += ( 1 / static_cast<double>(factorial4_34(denominator)) );
		denominator--;
	}
	return e;
}
inline double expoenetialEestimation4_34( int xx, int denominator){
	double e_x = 0.0;
	while (denominator >= 0) {
		e_x += ( pow(xx, denominator) / static_cast<double>(factorial4_34(denominator)) );
		denominator--;
	}
	return e_x;
}
void ExerCh3and4::facTorial4_34(){
		int Num = 0, Num_fac = 0;
		int x=0, preciTerm = 0;
	
		//a)
		cout << "Input an integer to compute its factorial.\n";
		cin >> Num;
		Num_fac = factorial4_34(Num);
		cout << "The " << Num << " factorial is: " << Num_fac << endl;
		
		//b)
		preciTerm=0;
		
		cout << "Input a number for estimating e (up to terms).\n";
		cin >> preciTerm;
		cout << "The estimation of e up to " << preciTerm << " term(s) is: " << natureEestimation4_34( preciTerm - 1 ) << endl;
		
		//c)
		x=0, preciTerm=0;
		
		cout << "To calculate e^x, input x first.\n";
		cin >> x;
		if (x<0)
			return;
		
		cout << "Next, input a number for the desired accuracy (up to terms).\n";
		cin >> preciTerm;
		if (preciTerm<0)
			return;
		
		cout << "The estimation of e^" << x << " up to " << preciTerm << " is:" << expoenetialEestimation4_34( x, preciTerm - 1 ) << endl;
}

inline int enCrypt(int object){
	int enc_object = 0;
	int temp = 0, count = 0;
	//最精簡方法: 多一個變數enc_object做為容器，同時執行 (m+7) mod 10 及 swap.
	while (count<=3){
		temp = (object + 7) % 10; //temp 記住每一位數字, count 當計數器.
		enc_object += (  temp * static_cast<int>( pow( 10, (count+2) % 4 ) )  );
		object /= 10;
		count++;
	}
	return enc_object;
}
inline int deCrypt( int object){
	int dec_object = 0;
	int temp = 0, count = 0;
	
	while (count<=3) {
		temp = (object - 7) % 10;
		if (temp<0)
			temp += 10;
		
		dec_object += (  temp * static_cast<int>( pow( 10, (count+2) % 4 ) )  );
		object /= 10;
		count++;
	}
	
	return dec_object;
}
void ExerCh3and4::enforcingPrivacyWithCryptography4_35(){
	int enCrypt(int);
	int deCrypt(int);
		int obJect = 1111;
		
		while (obJect>=0){
			cout << "Input a four-digit integer to encrypt.\n";
			cin >> obJect;
			if (obJect<0)
				return;
			cout << "The integer after encrypting is: " << enCrypt(obJect) << endl;
			
			
			obJect = 1111;
			cout << "Input a four-digit integer to decrypt.\n";
			cin >> obJect;
			if (obJect<0)
				return;
			cout << "The integer after decrypting is: " << deCrypt(obJect) << endl;
		}
}


