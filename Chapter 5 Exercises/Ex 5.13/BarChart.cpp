#include "BarChart.hpp"

int BarChart(){
	int Num[5];
	cout << "Input five numbers(0~99) with white spaces among each number.\n";

	for (int i=0; i<=4; i++){

		cin >> setw(2) >> Num[i];

		for( int count = 0; count <= Num[i]-1; count++){
			cout << '*';
		}
		cout << endl;
	}
	return 0;
}
