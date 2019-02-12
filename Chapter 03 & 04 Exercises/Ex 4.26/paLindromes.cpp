#include "paLindromes.hpp"

void paLindromes(){
	int number=0;

	while (number != -1){
		cout << "Input a five-digit integer to check if it's a palindrome or -1 to quit.\n";
		cin >> number;
		if (number == -1)
			return;

		while (number < 1000) {
			cout << "Err. Input a 4, or 5-digit integer. (if you input a 4-digit number, system will automatically regard the fifth digit as 0 to compile.\n";
			cin >> number;
			if (number == -1)
				return;
		}

		//core
		if (number/10000 == number % 10){
			if ( (number % 10000) /1000  ==  (number % 100) /10 )
				cout << "This number is a palindrome.\n";
		}
		else
			cout << "This number is not a palindrome.\n";
	}

}

