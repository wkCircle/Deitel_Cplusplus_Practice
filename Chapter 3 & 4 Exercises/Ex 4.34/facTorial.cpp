#include "facTorial.hpp"
inline int factorial( int m){
	int m_fac = 1 ; // including case x = 0 or 1
	while (m > 1) {
		m_fac *= m-- ;
	}
	return m_fac;
}
inline double natureEestimation( int denominator){
	double e = 0.0;
	while (denominator >= 0){
		e += ( 1 / static_cast<double>(factorial(denominator)) );
		denominator--;
	}
	return e;
}
inline double expoenetialEestimation( int xx, int denominator){
	double e_x = 0.0;
	while (denominator >= 0) {
		e_x += ( pow(xx, denominator) / static_cast<double>(factorial(denominator)) );
		denominator--;
	}
	return e_x;
}
void facTorial(){
		int Num = 0, Num_fac = 0;
		int x=0, preciTerm = 0;

		//a)
		cout << "Input an integer to compute its factorial.\n";
		cin >> Num;
		Num_fac = factorial(Num);
		cout << "The " << Num << " factorial is: " << Num_fac << endl;

		//b)
		preciTerm=0;

		cout << "Input a number for estimating e (up to terms).\n";
		cin >> preciTerm;
		cout << "The estimation of e up to " << preciTerm << " term(s) is: " << natureEestimation( preciTerm - 1 ) << endl;

		//c)
		x=0, preciTerm=0;

		cout << "To calculate e^x, input x first.\n";
		cin >> x;
		if (x<0)
			return;

		cout << "Next, input a number for the desired accuracy (up to terms).\n";
		cin >> preciTerm;
		if (preciTerm<0)
			return;

		cout << "The estimation of e^" << x << " up to " << preciTerm << " is:" << expoenetialEestimation( x, preciTerm - 1 ) << endl;
}
