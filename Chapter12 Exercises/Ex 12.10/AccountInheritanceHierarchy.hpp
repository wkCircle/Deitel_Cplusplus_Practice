//Ex 12.10
#ifndef AccountInheritanceHierarchy_hpp
#define AccountInheritanceHierarchy

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <ctime>
#include <random>
#include <typeinfo>
#include <vector>
#include <cctype>  //isdigit function prototype
using namespace std;

class Account{
public:
    Account ( double );
    ~Account();
    void validation();
    bool credit( double ); //add $ to current balance.
    bool debit( double ); //withdraw $ from current balance.
    double getBalance();
    void print();
private:
    double balance;

};

class SavingsAccount: public Account{
public:
    SavingsAccount( double, double);
    ~SavingsAccount();
    void setRate( double );
    double calculateInterest();
    void print();
private:
    void validationRate();
    double interestRate;

};

class CheckingAccount: public Account{
public:
    CheckingAccount( double, double);
    ~CheckingAccount();
    void setFee( double );
    bool credit( double );
    bool debit( double );
    void print();
private:
    void validationFee();
    double fee; //represents fee charged per transanction.
};
#endif // AccountInheritanceHierarchy_hpp

