#include "checkerboardPatternOfAsterisks.hpp"

void checkerboardPatternOfAsterisks(){
	for ( int i = 1; i <= 8; i++){
		if ( i % 2 ==0 ){
			cout << ' ';
		}
		for ( int j = 1; j <= 8; j++){
			cout << "* ";
		}
		cout << endl;
	}
}
