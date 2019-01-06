// Fig. 11.5: fig11_05.cpp
// Demonstrating class PhoneNumber's overloaded stream insertion and stream extraction operators.
#include "Fig11_3_PhoneNumber.hpp"
int main(){

    PhoneNumber phone;

	cout << "Enter phone number in the form (123) 456-7890:" << endl;
	// cin >> phone invokes operator>> by implicitly issuing the global function call operator>>( cin, phone )
	cin >> phone;

	cout << "The phone number entered was: ";
	// cout << phone invokes operator<< by implicitly issuing the global function call operator<<( cout, phone )
	cout << phone << endl;
}
