#include "TortoiseAndHare.hpp"

inline void moveTortoise( int * , const int & );
inline void moveHare( int *, const int & );
void TortoiseAndHare(){

	const int finishLine = 70;
	int posiTortoise = 1, posiHare = 1; //recor positions, begin at positioin 1.
	int clocktick = 0; //Record total times/while loops.
	srand(static_cast<unsigned int >(time(0)));
	//Introduction
	cout << "Welcome! Mr. Tortoise and Ms. Hare. The race is held besides the slippery mountain, and is going to begin soon. Word of Advice: Watch out your step to avoid slipping!\n";
	cout << "The first contender to reach or pass square 70 is rewarded with a pail of fresh carrots and lettuce!\n";
	cout << "GOOOOOOOOOOD LUCK!\n";
	cout << "BANG !!!!!\n";
	cout << "And THEY'RE OFF !!!!!\n\n\n";

	//RACE Began.
	while ( posiTortoise < finishLine && posiHare < finishLine ){
		//Move!
		moveTortoise( &posiTortoise, finishLine);
		moveHare( &posiHare, finishLine);
		clocktick++;
		//pring current race situation.
		cout << "Round " << clocktick << ": ";
		for (int i = 1; i < finishLine + 1; i++){
			if (i == posiTortoise && i == posiHare)
				cout << "OUCH!";
			else if (i == posiTortoise)
				cout << "T";
			else if (i == posiHare)
				cout << "H";
			else
				cout << " ";
		}
		cout << endl;
	}

	//Winner determination process.
	if ( posiTortoise == finishLine && posiHare == finishLine)
		cout << "Though it's a tie, but since tortoise is the underdog. So Tortoise WINS!!! CONGRATS!\n";
	else if (posiTortoise == finishLine)
		cout << "TORTOISE WINS!!! YAY!!!\n";
	else if (posiHare == finishLine)
		cout << "Hare wins. Yuch\n";


}
inline void moveTortoise( int *posiPtr, const int & finishLine ){

	int randMove = rand()%10 + 1; //Move type Generation.
	//Move steps determination
	if (1 <= randMove && randMove <= 5)//Fast plod
		randMove = 3;
	else if ( 6 <= randMove && randMove <= 7 ) //Slip
		randMove = -6;
	else if ( 8 <= randMove && randMove <= 10) //Slow plod
		randMove = 1;
	//Move!
	*posiPtr += randMove;
	//Check conditions.
	if (*posiPtr < 1)
		*posiPtr = 1;
	else if (*posiPtr > finishLine)
		*posiPtr = finishLine;

}
inline void moveHare( int *posiPtr, const int & finishLine){
	int randMove = rand()%10 + 1; //Move type Generation.
	//Move steps determination
	switch (randMove) {
		case 1:
		case 2:
			randMove = 0; //Sleep
			break;
		case 3:
		case 4:
			randMove = 9; //Big Hop
			break;
		case 5:
			randMove = -12; //Big Slip
			break;
		case 6:
		case 7:
		case 8:
			randMove = 1; //Small Hop
			break;
		case 9:
		case 10:
			randMove = -2; // Small Slip
			break;
	}
	//Move!
	*posiPtr += randMove;
	//Check conditions.
	if (*posiPtr < 1)
		*posiPtr = 1;
	else if (*posiPtr > finishLine)
		*posiPtr = finishLine;

}

