//
//  main.cpp
//  20170627 Chapter 10 Exercises
//
//  Created by kai on 05/11/2017.
//  Copyright © 2017 Wen-Kai Chung. All rights reserved.
//

#include "Chapter10_Exercises.hpp"

int main(){

//  Ex10_6
//	struct tm A;
//	Exercise10_6_Date DateTest( A );
//	DateTest.print('c');

//  Ex10_7
//	SavingsAccount10_7 saver1(2000), saver2(3000);
//    SavingsAccount10_7::modifyIntrestRate(0.03);
//    cout << "Info for saver1 under 3\%: " << endl;
//    saver1.print();
//    cout << "Info for saver2 under 3\%: " << endl;
//    saver2.print();
//    SavingsAccount10_7::modifyIntrestRate(0.04);
//    cout << "Info for saver1 under 4\%: " << endl;
//    saver1.print();
//    cout << "Info for saver2 under 4\%: " << endl;
//    saver2.print();

//  Ex10_8
//    const vector<int> * const vecAPtr = new vector<int>{2,3,5,7,9};
//    IntegerSet10_8 setA(vecAPtr); //type1 constructor
//
//    const vector<bool>* const vecBPtr = new vector<bool>{1,0,1,0,1,0,1,0,1,0,1}; //Which is (int){0,2,4,6,8,10}
//    IntegerSet10_8 setB(vecBPtr); //type2 constructor
//
//    int arrSize = 3;
//    int * const arrIntPtr = new int [arrSize];
//    for(int i =0; i<arrSize; i++) *(arrIntPtr+i) = 50+i; //(int){50,51,52}
//    IntegerSet10_8 setC(arrIntPtr, arrSize); //type3 constructor
//
//    bool * const arrBoolPtr = new bool [101]{};
//    for(int i =0; i<3; i++) *(arrBoolPtr+50-i) = 1; //(int){48,49,50}
//    IntegerSet10_8 setD(arrBoolPtr); //type4 constructor
//
//    IntegerSet10_8 setInit {83,89,97};// special type constructor
//
//    setA.unionOfSets(setB);
//    setA.printSet();
//
//    setC.intersectionOfSets(setD);
//    setC.printSet();
//
//    setD.insertElement(2);
//    setD.printSet();
//
//    setInit.deleteElement(83);
//    setInit.printSet();


//  Ex10_9
//    Time10_9 t;
//    t.setHour(18).setMinute(30).setSecond(22); /**<cascaded function calls>**/
//
//    cout << "Universal time: " ;
//    t.printUniversal();
//    cout << "\nStandard time: ";
//    t.printStandard();
//
//    cout << "\n\nNew standard time: ";
//    t.setTime(20,20,20).printStandard();
//    cout << endl;

//	Ex10_10 to Ex10_14
	DeckOfCards myDeck;
	myDeck.shuffle(false);
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
