#include "CalculatingPi.hpp"

int CalculatingPi(){
	double Pi = 0.0;

	for (int i=1; i<=100000; i++){

		if ( i % 2 == 0)
			Pi -= (4.0 / ( 2 * i - 1)) ;
		else
			Pi += (4.0 / ( 2 * i - 1)) ;
		if ( i % 1000 ==0)
			cout << setprecision(10)<< fixed << "The " << i << " terms approximation of pi is: " <<  Pi << endl;
		//到第10萬項才精準到3.1415'8'26536, 到100萬項才精準到3.14159'1'6536
	}

	return 0;

}

