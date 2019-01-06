// Fig. 11.3: PhoneNumber.h
// PhoneNumber class definition
#ifndef PHONENUMBER_H
#define PHONENUMBER_H


#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <typeinfo>
#include <ctime>
#include <cmath>
#include <vector>
#include <string>
using namespace std;


class PhoneNumber {
	friend ostream & operator<<( ostream &, const PhoneNumber & );
	friend istream & operator>>( istream &, PhoneNumber & );
private:
	string areaCode; // 3-digit area code
	string exchange; // 3-digit exchange
	string line; // 4-digit line
};
#endif // PHONENUMBER_H
