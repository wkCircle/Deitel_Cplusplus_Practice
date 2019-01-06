#include "Multiples.hpp"

void Multiples(){
	int num1=1, num2=2;
	while (true){
		cout << "Input a pair of integers to determine if the second is a mutilple of the first.\n";
		cout << "or put 0 on the second to quit.\n";
		cin >> num1 >> num2;
		if ( num2 ==0 ){
			cout << "End of execution\n";
			break;
		}

		cout << "A: " << boolalpha << (num2 % num1 == 0) << endl;
	}
}
