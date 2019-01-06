#include "gasMileage.hpp"

void gasMileage(){
	int miles=0, gallons=0,counter=1;
	double avg=0, MpG=0;

	while (miles != -1){
		cout << "Enter miles driven (-1 to quit): \n";
		cin >> miles;
		if (miles == -1)
			return;

		cout << "Enter gallons used: \n";
		cin >> gallons;
		MpG = static_cast<double>(miles) / static_cast<double>(gallons);
		cout << "MPG this tankful: " << MpG << endl;

		avg = (avg * (counter-1) + MpG)/ (counter);
		cout << "Total MPG: " << avg << endl;
		counter++;
	}

}
