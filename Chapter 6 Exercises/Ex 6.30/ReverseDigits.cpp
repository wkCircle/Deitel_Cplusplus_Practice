#include "ReverseDigits.hpp"

void ReverseDigits(){
	int n=0, rev_n=0; //This even works for negative integer.
	int temp=0, digits=0;

	while ( n!=-1){
		cout << "Input an integer to be reversed.(or -1 to quit.)\n";
		cin >> n;
		if (n== -1)
			break;

		//calculate total digits.
		temp = n;
		while(temp != 0){
			temp/=10;
			digits++;
		}

		temp=0, rev_n=0;
		while(n != 0){
			temp = n%10 ;
			rev_n += temp * int(pow(10, digits-1) + 0.5);
			/**< +0.5 because sometimes pow() is weird E.g., pow(10,2) is 99 but not 100. To solve this, add 0.5 and take int() */
			digits--;
			n/=10;
		}
		cout << "Its reverse is: " << rev_n << endl;
	}

}
