// Fig. 11.25: fig11_25.cpp
// HugeInt test program.
#include "HugeIntClass.hpp"
int main(){
	HugeInt n1(	7654321 );
	HugeInt n2( 7891234 );
	HugeInt n3( "99999999999999999999999999999" );
	HugeInt n4( "20" );
	HugeInt n5;

	//print original valuse
	cout << "n1 is " << n1 << "\nn2 is " << n2 << "\nn3 is " << n3 << "\nn4 is " << n4<< "\nn5 is " << n5;
	//test HugeInt + HugeInt
	n5 = n1 + n2;
	cout<< n1 <<"+"<< n2 <<"="<< n5 <<"\n\n";
	//test HugeInt + string version HugeInt
	cout<< n3 <<"+"<< n4 <<"\n="<< (n3+n4) <<"\n\n";
	//test HugeInt + int
	n5 = n1 + 9;
	cout<< n1 <<"+"<< 9 <<"="<< n5 <<"\n\n";
	//test HugeInt + string
	n5 = n2 + "10000";
	cout << n2 << " + " << "10000" << " = " << n5 << "\n\n";
	//test HugeInt * HugeInt
	n5 = n1 * n2;
	cout<< n1 <<"*"<< n2 <<"="<< n5 <<"\n\n";
	//test HugeInt * string version HugeInt
	cout<< n3 <<"*"<< n4 <<"\n=" << (n3*n4) <<"\n\n";
	//test HugeInt * int
	n5 = n1 * 9;
	cout<< n1 <<"*"<< 9 <<"="<< n5 <<"\n\n";
}
