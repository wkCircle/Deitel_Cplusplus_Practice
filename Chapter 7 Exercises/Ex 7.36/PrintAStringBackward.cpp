#include "PrintAStringBackward.hpp"

//prototype
void stringReverse( string, size_t);


void PrintAStringBackward(){
	string text = " Ich Heise Setsuna. Vielen Dank."; // sample string
	stringReverse(text, 15); // one should change the 2nd arg value to test the code.
}
void stringReverse( string str, size_t sReverse){
    /*
    sReverse: the posi that starts to print reversely.
    */
	if (sReverse != 0){
		cout << str[sReverse];
		stringReverse(str, sReverse-1 );
	}
	else if (sReverse == 0)
		cout << str[sReverse];

}
