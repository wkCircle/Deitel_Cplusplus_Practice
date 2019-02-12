#include "GuesstheNumberGame.hpp"


void GuesstheNumberGame(){
	char willing='y';

	while (willing=='y'){

		int s=0, guess=0;;

		srand( static_cast<int>( time(0) ) );
		s = rand()%1000 +1;

		cout << "I have number btw 1 and 1000. \nCan you guess my number?\nPlease type your first guess.\n";

		do {

			cin >> guess;
			if (guess==s){
				cout << "Excellent! You guess the number.\n";
				break;
			}
			else if (guess > s)
				cout << "Too high. Try again.\n";
			else
				cout << "Too low. Try again.\n";

		} while( guess != s);

		cout << "Would you like to play again?[y;n]\n";
		cin >> willing;

		while (willing != 'y' && willing != 'n'){
			cout << "Invalid input. Try again.[y;n]\n";
			cin >> willing;
		}


	}

}
