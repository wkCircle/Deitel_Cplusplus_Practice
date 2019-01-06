#include "OverloadingtheParenthesesOperator.hpp"
int main(){
    DoubleSubscriptedArray arrTest(2,2);
	DoubleSubscriptedArray brrTest(2,4);
	cout << "arr and brr before input: " << endl;
	cout << "arr: \n" << arrTest << endl << "brr:\n" << brrTest << endl;

	cout << "Now please input 12 integers into 2 arrays arr & brr: \n";
	cin >> arrTest >> brrTest;
	cout << "arr's content now becomes: \n" << arrTest << endl << "and brr's content now becomes: \n" << brrTest << endl;

	cout << "Is arr == brr ? \t" << ( arrTest == brrTest ? "Equal" : "Not Equal" ) << endl;
	cout << "Is arr != brr ? \t" << ( arrTest != brrTest ? "Not Equal" : "Euqal" ) << endl << endl;

	cout << "Assign brr to arr: \n" << (arrTest = brrTest) << endl;
	cout << "Is arr == brr ? \t" << ( arrTest == brrTest ? "Equal" : "Not Equal" ) << endl;
	cout << "Is arr != brr ? \t" << ( arrTest != brrTest ? "Not Equal" : "Euqal" ) << endl << endl;

	arrTest(2,2)=1000; //lvalue test
	cout << "Change value of arr(2,4)= 1000: \t" << arrTest(2,2) << endl; //rvalue test
	cout << "arr now becomes: \n" << arrTest << endl;
}
