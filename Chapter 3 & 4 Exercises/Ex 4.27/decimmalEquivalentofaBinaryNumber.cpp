#include "decimmalEquivalentofaBinaryNumber.hpp"

void decimmalEquivalentofaBinaryNumber(){
	long int bnyNum = 0;
	int deciNum = 0;
	int count = 0;

	while ( bnyNum != -1){
		cout << "Input a binary integers or 0 to quit.(System will regard any digit that is not 0 or 1, for example, 7, as 7%2 = 1)\n";
		cin >> bnyNum;
		if (bnyNum == -1)
			return;

		count = 0;

		deciNum = 0;
		while (bnyNum != 0 ) {
			deciNum += ((bnyNum % 2) * pow(2, count)) ;
			bnyNum /= 10;

			count++;
		}

		cout << "The corresponding decimal number is: " << deciNum << endl;
	}

}

