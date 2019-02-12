#include "CalculatingTotalSales.hpp"


int CalculatingTotalSales(){
	int numbering=0, quantity=0;
	double Rprice=0, total=0;

	while (numbering != -1){
		cout << "Input the product number and its quantity sold, or -1 to quit.\n";
		cin >> numbering;
		if (numbering == -1)
			break;
		cin >> quantity;
		switch (numbering){
			case 1:
				Rprice = 2.98;
				break;
			case 2:
				Rprice = 4.50;
				break;
			case 3:
				Rprice = 9.98;
				break;
			case 4:
				Rprice = 4.49;
				break;
			case 5:
				Rprice = 6.87;
				break;
		}

		total += (Rprice * quantity);
		cout << "The total retail value as far is " << total << endl;
	}
	return 0;
}
