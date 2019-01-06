#ifndef Account_hpp
#define Account_hpp


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
    virtual bool credit( double ); //add $ to current balance.
    virtual bool debit( double ); //withdraw $ from current balance.
    virtual double calculateInterest();
    virtual double getBalance();
    virtual void print();
private:
    double balance;

};

class SavingsAccount: public Account{
public:
    SavingsAccount( double, double);
    ~SavingsAccount();
    void setRate( double );
    virtual double calculateInterest();
    virtual void print();
private:
    void validationRate();
    double interestRate;

};

class CheckingAccount: public Account{
public:
    CheckingAccount( double, double);
    ~CheckingAccount();
    void setFee( double );
    virtual bool credit( double );
    virtual bool debit( double );
    virtual void print();
private:
    void validationFee();
    double fee; //represents fee charged per transanction.
};


#endif // Account_hpp
