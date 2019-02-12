#include "multiplesOf2withanInfiniteLoop.hpp"

void multiplesOf2withanInfiniteLoop(){
	int x=1;
	int terminate= 100;
	int i =0;
	while (i < terminate){
        x*=2;
		cout << x << endl;
		i++;
	}
}
