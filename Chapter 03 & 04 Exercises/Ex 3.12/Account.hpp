//
//  20170408 Chapter 3 & 4 Exercises.hpp
//  20170408 Chapter 3 & 4 Exercises
//
//  Created by ntueconRA on 2017/5/15.
//  Copyright © 2017年 Kai. All rights reserved.
//

#ifndef Account_hpp
#define Account_hpp

#include <cstdio>
#include <cmath>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <string>
#include <typeinfo>
using namespace std;


class Account {
public:
	Account(string unserName, int accBalance);
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

#endif // Account_hpp
