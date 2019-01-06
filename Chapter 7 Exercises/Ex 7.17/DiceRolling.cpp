#include "DiceRolling.hpp"


void DiceRolling7_17_and39(){
	const int diceSumCatogories = 11; //from sum 2 to 12.
	int frequencyDice[diceSumCatogories] = {}; //record frequency of the sum of two dices for 36000 tossing.
	const int totaltossing = 36000;
	int faceVal1 = 0, faceVal2 = 0;
	int counter = 0;

	//toss 36000 and record the sum of two dice.
	for (counter = 0; counter < totaltossing; counter++){
		faceVal1 = rand() % 6 + 1;
		faceVal2 = rand() % 6 + 1;
		//store in array
		frequencyDice[ (faceVal1+faceVal2) -2  ]++;
	}

	//Print table!
	cout << right << setw(6) << "SumValue " << setw(8) << "times" << setw(13) << "%\n"; //header
	for (counter = 0; counter < diceSumCatogories; counter++){

		//call array
		//print the result by times of occurrance.
		cout << "sum=" << right << setw(2) << counter +2 << ": " << setw(9) << frequencyDice[counter];
		//print teh result by percentages.
		cout << setw(12) << 100 * static_cast<double>( frequencyDice[counter] ) / totaltossing << endl;
	}
}
