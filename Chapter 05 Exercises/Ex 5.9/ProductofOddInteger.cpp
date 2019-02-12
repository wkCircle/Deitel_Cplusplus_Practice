#include "ProductofOddInteger.hpp"

int ProductofOddInteger(){
	for (int x=1; x<=15; x+=2){
		for (int y=1; y<=15; y+=2){
			cout << x*y << "\t";
		}
		cout << endl;
	}
	return 0;
}
