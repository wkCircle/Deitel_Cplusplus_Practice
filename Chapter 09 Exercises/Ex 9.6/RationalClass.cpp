#include "RationalClass.hpp"

Rational::Rational(int numerator, int denominator){ //constructor
	//simplify values to get reduced form.
	simplified(&numerator, &denominator);
	//store values
	Rational::numerator = numerator;
	Rational::denominator = denominator;
}
void Rational::simplified( int *numPtr, int *denPtr){ //get reduced form and make the +/- sign stick with the numerator (so denominator is always positive).

	//validate denominator
	if (*denPtr == 0){
		cout << "Denominator can't be zero.\n";
		exit(EXIT_FAILURE); //abort execution.
	}

	//find GCD
	size_t gcd = GCD( numPtr, denPtr);
	//update values
	if (gcd == 0){ //special case
		*numPtr = 0;
		*denPtr = 1;
	}
	else {
		*numPtr /= static_cast<int>( gcd );
		*denPtr /= static_cast<int>( gcd );
		if ( *numPtr * *denPtr > 0 ){ // same sign
			*numPtr = abs(*numPtr);
			*denPtr = abs(*denPtr);
		}
		else if ( *numPtr * *denPtr < 0){ //different sign
			*numPtr = -1 * abs(*numPtr);
			*denPtr = abs(*denPtr);
		}
	}

}
int Rational::GCD(const int *numPtr, const int *denPtr){
	if ( *numPtr == 0)
		return 0; //special case.

	int maxval = max( abs(*numPtr), abs(*denPtr));
	int minval = min( abs(*numPtr), abs(*denPtr));

	//find GCD
	while ( maxval % minval != 0){
		int temp = maxval % minval;
		maxval = minval;
		minval = temp;
	}
	return minval;
	//True for either case, maxval%minval ==0 or !=0.
	//minval is always positive.
}
void Rational::add(Rational obj){
	if ( obj.denominator == 0){ //obj is an integer.
		numerator += denominator * obj.numerator ;
		//denominator is unchanged.
	}
	else {
		int lcm = denominator* obj.denominator /GCD( &denominator, &obj.denominator);
		numerator = (numerator * lcm / denominator )
				  + (obj.numerator * lcm / obj.denominator);
		denominator = lcm;
	}
	simplified( &numerator, &denominator );
}
void Rational::subtract(Rational obj){
	if ( obj.denominator == 0){ //obj is an integer.
		numerator -= denominator * obj.numerator ;
		//denominator is unchanged.
	}
	else {
		int lcm = denominator* obj.denominator/GCD(&denominator, &obj.denominator);
		numerator = (numerator * lcm / denominator )
				  - (obj.numerator * lcm / obj.denominator);
		denominator = lcm;
	}
	simplified( &numerator, &denominator );
}
void Rational::multiply(Rational obj){
	// make the fraction as the simplest one
	int gcd1 = GCD( &numerator, &obj.denominator);
	numerator /= gcd1;
	obj.denominator /= gcd1;
	int gcd2 = GCD( &obj.numerator, &denominator);
	obj.numerator /= gcd2;
	denominator /= gcd2;
	// Finally, multiply with each other and do the simplification.
	numerator *= obj.numerator;
	denominator *= obj.denominator;
	simplified( &numerator, &denominator);
}
void Rational::divide(Rational obj){
	// make the fraction as the simplest one
	int gcd1 = GCD( &numerator, &obj.numerator);
	numerator /= gcd1;
	obj.numerator /= gcd1;
	int gcd2 = GCD( &obj.denominator, &denominator);
	obj.denominator /= gcd2;
	denominator /= gcd2;
	// Finally, multiply with each other and do the simplification.
	numerator *= obj.denominator;
	denominator *= obj.numerator;
	simplified( &numerator, &denominator);
}
void Rational::printR(){
	cout << "Rational form: " << numerator << "/" << denominator << endl;
}
void Rational::printFl(){
	cout << "floating form: " << static_cast<double>(numerator)/denominator << endl;
}
