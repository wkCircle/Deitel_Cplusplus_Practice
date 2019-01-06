#include "RecursiveExponentiation.hpp"


inline double power(double base, unsigned int exponent){
	if (exponent ==1)
		return base;
	else if (exponent % 2 == 0)
		return power(base * base, exponent/2);
	else
		return base * power(base * base, (exponent-1) /2 );

}
void RecursiveExponentiation(){
	unsigned int exponent=1;
	double base=1;

	cout << "Input base(double) and exponent(int>=1) values, or enter 0 in any value to quit.\n";
	cin >> base >> exponent;
	while(base !=0 && exponent != 0){
		cout << "The result is: " << power(base, exponent) << endl;

		cout << "Input base(double) and exponent(int>=1) values, or enter 0 in any value to quit.\n";
		cin >> base >> exponent;
	}


}
