#include "GreatestCommonDivisor.hpp"

void GreatestCommonDivisor(){
	int x=1, y=1;
	while(true){
		int temp=0, quotient=0;

		cout << "Input two integers to find their GCD.(or 0 to quit) \n";
		cin >> x >> y;
		x = abs(x); ///<stdlib>
		y = abs(y);
		if (x==0 || y==0)
			break;

		temp =0;
		do{
			temp = y; //Initialize temp = min-value.
			// x is always largest and reinitialize temp = min-value.
			if (x<y){
				temp = x;
				x = y;
				y = temp;
			}
			quotient = x/y; //automatically truncated for int types.
			if( x - quotient*y == 0)
				break;
			else
				x -= (quotient*y) ;

		}while( x - quotient*y != 0);
		cout << temp << endl;


	}

}
