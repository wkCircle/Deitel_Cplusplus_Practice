#include "PerfectNumbers.hpp"

inline char isPerfect(const int n){
	int total = 0;
	int counter=1;
	string factors;
	char result;

	while(total < n && counter < n){
		if (n % counter == 0){
			total += counter;
			factors = factors + to_string(counter) + ' ' ; ///<string>
		}
		counter++;
	}
	if (total == n){
		result = 'T';
		cout << setw(4) << left << n << " is perfect.\n";
		cout << "The factors of " << fixed << setw(4) << left << n << " are: " << setw(30) <<factors << endl << endl;
	}
	else{
		result = 'F';
		cout << setw(2) << left << n << " is not perfect.\n";
		cout << "The factors of " << fixed << setw(4) << left << n << " are: " << setw(30) <<factors << endl << endl;
	}

	return result;
}
void PerfectNumbers(){
	//test
	int n=1;
	while( n != -1){
		cout << "Input an integer.\n";
		cin >> n;
		if (n== -1)
			break;
		isPerfect(n);
	}
	//end test

    // following tries to prints all perfect numbers in 1-1000
//	for (int i=1 ; i <= 1000; i++){
//	    isPerfect(i);
//	}
}
