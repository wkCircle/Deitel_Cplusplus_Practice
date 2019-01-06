//
//  main.cpp
//  20170627 Chapter 10 Exercises
//
//  Created by kai on 05/11/2017.
//  Copyright © 2017 Wen-Kai Chung. All rights reserved.
//
#include "CardShufflingandDealing.hpp"

int main(){
	DeckOfCards myDeck;
	myDeck.shuffle(true); // setup random seed if true, otherwise, fix the seed.
	cout << "Display myDeck after shuffling.\n";
	myDeck.print();

	HandOfCards myHand(myDeck), dealerHand(myDeck);
	int i = 0;

	do{
		i++;
		cout << "\nROUND " << i << " \n";

		cout << "Deal hand: MY HAND.\n"; 	myHand.print();
		cout << "  My Hand type is: ";		myHand.typePrint();
		cout << "Deal hand: Dealer's HAND.\n";	dealerHand.print();
		cout << "  Dealer's Hand type is: ";	dealerHand.typePrint();

		switch(  myHand.betterHand( & dealerHand) ){
			case 1: cout << "I win!\n"; break;
			case 0: cout << "Dual"; break;
			case -1: cout << "Dealer winsQQ\n"; break;
		}
		if (i < 5){
			myHand.dealNewHandfromDeck( &myDeck );
			dealerHand.dealNewHandfromDeck(&myDeck);
		}
	}while( i<5 );
}
