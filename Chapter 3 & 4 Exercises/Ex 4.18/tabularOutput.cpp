#include "tabularOutput.hpp"


void tabularOutput(){
	int N=1;

	cout << "N \t 10*N \t100*N \t1000*N \n \n";
	while (N <= 5){
		cout << N << "\t " << 10*N << "\t \t" << 100*N << "\t \t" << 1000*N << "\t" << endl;
		N++;
	}
}

