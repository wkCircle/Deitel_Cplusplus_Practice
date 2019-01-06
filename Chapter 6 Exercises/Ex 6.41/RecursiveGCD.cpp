#include "RecursiveGCD.hpp"

inline int GCD(int x, int y){
	if (y==0)
		return x;
	else
		return GCD(y, x % y);
}
void RecursiveGCD(){
	int x, y, temp;
	while (true){
		cout << "Input two integers to calculate their GCD.(or 0 on any value to quit.)\n";
		cin >> x >> y;
		x = fabs(x);
		y = fabs(y);
		if (x==0 || y==0){
			cout << " GCD = 0 end system ended.\n";
			return;
		}

		// x is always largest and reinitialize temp = min-value.
		if (x<y){
			temp = x;
			x = y;
			y = temp;
		}


		cout << GCD(x, y) << endl;
	}
}
