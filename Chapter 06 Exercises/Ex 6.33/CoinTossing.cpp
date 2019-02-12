#include "CoinTossing.hpp"


inline int flips(){
	return rand()%2 ;
}
void CoinTossing(){
	int s=0, Head=0, Tail=0;
	srand(static_cast<int>(time(0))); ///<ctime>
	for (int i=1; i <= 100 ; i++){

		s = flips();
		if (s==1)
			Head++;
		else
			Tail++;
	}
	cout << "Head: " << Head << "\t" << "Tail: " << Tail << endl;
}
