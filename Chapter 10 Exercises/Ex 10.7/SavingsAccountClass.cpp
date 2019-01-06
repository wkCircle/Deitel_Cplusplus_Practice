#include "SavingsAccountClass.hpp"

double SavingsAccount::annualInterestRate = 0;
SavingsAccount::SavingsAccount(const double &balance ){
    this -> SavingsBalance = (balance >= 0)? balance : 0;
}
SavingsAccount::~SavingsAccount(){
    ;
}
double SavingsAccount::calculateMonthlyInterests(){
    //monthlyInterest = balance * annualInterestRate /12; add it to SavingsBalance
    return SavingsBalance * (1+ annualInterestRate) / 12 ;
}
void SavingsAccount::addIntereststoSavings(){
    SavingsBalance += calculateMonthlyInterests();
}
void SavingsAccount::print(){
    double temp = calculateMonthlyInterests();
    cout << "interest is " << temp << endl;
    cout << "new balance is " <<  SavingsBalance+temp << endl;
}
void SavingsAccount::modifyIntrestRate( const double & rate ){
    annualInterestRate = rate;
}
