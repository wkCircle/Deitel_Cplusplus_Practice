#include "TheSieveofEratosthenes.hpp"

void SieveofEratosthenes(){
	const int arrSize = 10000;
	bool HelloPrime[arrSize] = {};//ignore elements 0 and 1, i.e., HelloPrime[0] and HelloPrime[1].
	int temp = 0, location = 0;
	//initialize to be true (ignore the first two elements).
	for (location = 2; location < arrSize; location++ ){
		HelloPrime[location] = true;
	}

	for (location = 2; location < arrSize; location++){
		//check if false, then next.
		if (HelloPrime[location] == false)
			continue;
		//otherwise, use the number as a factor to turn off the other integers that is divisible by it.
		for (temp = 2* location ; temp < arrSize; temp += location )
			HelloPrime[temp] = false;
	}//end 1st for

	//print all primes between 2 and 999
	int count = 0;
	for (int temp = 0; temp < arrSize; temp++){
		if (HelloPrime[temp] == true){
			cout << setw(8) << temp;
			count++;
			if (count % 10 == 0)
				cout << endl;
		}//end 1st if.
	}//end for loop
	cout << "\nthere are " << count << " prime numbers between in [0,"<< arrSize << "] in total" << endl;
}
