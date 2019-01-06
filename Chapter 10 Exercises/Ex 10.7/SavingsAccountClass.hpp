#ifndef SavingsAccountClass_hpp
#define SavingsAccountClass_hpp


#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cstdio>
#include <typeinfo>
#include <initializer_list>
#include <algorithm> //random_shuffle();


using namespace std;

class SavingsAccount{
public:

	SavingsAccount(const double & );
	~SavingsAccount();
	//monthlyInterest = balance * annualInterestRate[ person i] /12; add it to SavingsBalance
	double calculateMonthlyInterests();
	void addIntereststoSavings();

	static void modifyIntrestRate( const double & );
	void print();

private:
	static double annualInterestRate;
	double SavingsBalance = 0; //deposit
};


#endif // SavingsAccountClass_hpp
