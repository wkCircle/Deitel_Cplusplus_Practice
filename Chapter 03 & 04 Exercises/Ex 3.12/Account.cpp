#include "Account.hpp"



Account::Account(string userName, int accBalance){
	setUser(userName);
	setAccBalance(accBalance);
}
void Account::setUser(string name){
	userName = name;
}
string Account::getUser(){
	return userName;
}
void Account::setAccBalance(int money){
	if (money>=0)
		accBalance = money;
	else {
		accBalance = 0;
		cout << "Err. Invalid value for initial balance(>=0).\nPlease try again.\n";
	}
}
int Account::getBalance(){
	return accBalance;
}
void Account::credit(int deposit){
	if (deposit>=0)
		accBalance = accBalance + deposit;
	else {
		deposit = 0;
		cout << "Err. Invalid value for moeny being deposited.\nPlease try again.\n";
	}
}
void Account::debit(int withdraw){
	if (withdraw>=0 && withdraw<= accBalance)
		accBalance = accBalance - withdraw;
	else {
		withdraw = 0;
		cout << "Err. Invalid value for moeny being withdrawed.\nPlease try again.\n";
	}
}

