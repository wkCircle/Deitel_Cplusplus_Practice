#include "Exponentiation.hpp"

inline long long int integerPower(long long int base, long long unsigned int power){
	if(power == 0)
		return 0;
	else if (power == 1)
		return base;
	else if (power%2 ==0) //even
		return integerPower(base*base, power/2);
	else
		return integerPower(base*base, (power-1)/2 )*base ;
}
void Exponentiation(){
	int base=0;
	unsigned int power=0;
	while (true){
		cout << "Input two ordered pair of integers as base and power, respectively.)\nOr -1 to quit\n";
		cin >> base >> power;
		if ( base == -1 )
			break;

		cout << "The resule of base^power is: " << integerPower(base, power) << endl;
	}
}
