#include "SquareofAnyCharacter.hpp"

void SquareofAnyCharacter(){
	unsigned int side=1;
	string fillcharacter;
	string temp="";

	while (true){
		cout << "Input a natural number.\nOr 0 to quit.\n";
		cin >> side;
		if (side==0)
			break;
		cout << "Input a tmeplate of a character.\n";
		cin >> temp;
		cout << "The output square is:\n";
		fillcharacter = ( temp.substr(0, 1) );

		for (int i=1; i<=side ; i++){
			for (int j=1; j <= side; j++){
				cout << fillcharacter;
			}
			cout << endl;
		}
	}

}
