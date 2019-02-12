#include "ParkingCharges.hpp"

inline double calculateCharges(double m){
	double chargem = 0.0;

	if (m <= 3)
		chargem = 2.00;
	else
		chargem = min(  2.00 + (m-3)*0.50 , 10.00);
	return chargem;
}

void ParkingCharges(){
	double x, y, z;

	cout << "Enter the hours parked yesterday in the park for these 3 customer.\n";
	cin >> x >> y >> z;

	cout << setw(5) << left << "Car" << right << setw(8) << "Hours" << setw(10) << "Charge" << endl;
	cout << setw(5) << left << "1"   << right << fixed << setw(8) << setprecision(1) << x << setw(10) << setprecision(2) << calculateCharges(x) << endl;
	cout << setw(5) << left << "2"   << right << fixed << setw(8) << setprecision(1) << y << setw(10) << setprecision(2) << calculateCharges(y) << endl;
	cout << setw(5) << left << "3"   << right << fixed << setw(8) << setprecision(1) << z << setw(10) << setprecision(2) << calculateCharges(z) << endl;
	cout << setw(5) << left << "Total"<< right << fixed<< setw(8) << x+y+z << setw(10) << calculateCharges(x)+calculateCharges(y)+calculateCharges(z) << endl;

}
