#include "sidesOfTriangleAndRightTriangle.hpp"

void sidesOfTriangleAndRightTriangle(){
	double a = 0.0, b = 0.0, c = 0.0;
	double temp = 0.0;
	while (a>=0 && b>=0 && c>=0){
		// Input and Reorder s.t. a>b>c
		cout << "Input the 1st side.\n";
		cin >> a;
		if (a<0)
			return;
		cout << "Input the 2nd side.\n";
		cin >> b;
		if (b<0)
			return;

		if (a<b){
			temp = a;
			a = b;
			b = temp;
		}

		cout << "Input the 3rd side.\n";
		cin >> c;
		if (c<0)
			return;

		if (c > a){
			temp = a;
			a = c;
			c = b;
			b = temp;
		}
		else if (c>b){
			temp = b;
			b = c;
			c = temp;
		}

		//Triangle  and Right triangle iff condition.
		if ( b+c > a) {
			if( c*c + b*b == a*a ){
				cout << "Ja! Das ist auch ein right triangle.\n";
			}
			else
				cout << "Das ist ein triangle, but nicht ein right triangle.\n";
		}
		else
			cout << "Nein, das ist nicht ein triangle.\n";
	}

}

