#include "RandomFromSet.hpp"

void RandomFromSet(){
	unsigned int x=0;
	srand( static_cast<int>(time(0)) );
	x = (rand()%5 + 1)*2;
	cout << "a) " << x << endl;

	x = (rand()%5 +1)*2 +1 ;
	cout << "b) " << x << endl;

	x = (rand()%5 +1 ) * 4 +2;
	cout << "c) " << x << endl;

}
