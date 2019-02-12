#include "RoundingNumbers.hpp"

void RoundingNumbers(){
	double x = 0.0, y= 0.0;
	while (true) {
		cout << "Input a real number or -1 to quit.\n";
		cin >> x;

		if (x==-1)
			break;

		y = floor( x + .5 );
		cout << "The nearest intteger of "<< x << " is: " << y << endl;
	}
}
