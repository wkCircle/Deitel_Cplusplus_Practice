#include"DiamondofAsterisks.hpp"

int DiamondofAsterisks(){
	int row=0;
	while (true){

		cout << "Input an odd number btw 1-19 to specify the number of rows in the diamond you want to display.(Or -1 to quit.\n";
		cin >> row;
		if (row == -1 )
			return 0;

		while (row <= 0 || row>=20 || row%2 != 1){
			cout << "Invalid input value.\n";
			cin >> row;

			if ( row == -1)
				return 0;
		}

		for (int i=1; i<=row; i++){
			for (int j=1; j<=row; j++){

				if (i <= (row+1)/2 ){
					if ( j <= (row+1)/2 -i  ||  j >= (row+1)/2 + i )
						cout << " ";
					else
						cout << "*";
				}
				else {
					if ( j <= i- (row+1)/2 || j >= 3*(row+1)/2 -i   )
						cout << " ";
					else
						cout << "*";
				}

			}
			cout << endl;

		}
	}

	return 0;
}
