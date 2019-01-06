#include "DiamondofAsterisks.hpp"

int DiamondofAsterisks(){

	for (int i=1; i<=9; i++){
		for (int j=1; j<=9; j++){

			if (i<=5){
				if (j <= 5-i || j >= 5+i)
					cout << " ";
				else
					cout << "*";
			}
			else {
				if (j <= i-5 || j >= 15-i)
					cout << " ";
				else
					cout << "*";
			}

		}
		cout << endl;
	}
	return 0;

}
