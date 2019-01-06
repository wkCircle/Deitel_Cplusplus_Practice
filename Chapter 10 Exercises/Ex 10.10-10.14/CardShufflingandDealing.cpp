//
//  Chapter10_Exercises.cpp
//  20170627 Chapter 10 Exercises
//
//  Created by kai on 05/11/2017.
//  Copyright © 2017 Wen-Kai Chung. All rights reserved.
//
/**<Start-----Ex10.10 to Ex10.14: Card Shuffling and Dealing>**/
#include "CardShufflingandDealing.hpp"
//global defs
string Card::Faces[13] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
string Card::Suits[4] = {"Club","Diamond","Heart","Spade"};
//prototype
inline void bubbleSort( int * arr );					//prototype
inline void swap(int &, int &); 						//prototype
inline int RtoLcompare( int * arr, int * brr);			//prototype
inline void twoPairsHandsort( int * arr);				//prototype
inline void onePairHandsort( int * arr );				//prototype
inline int myRand(int s){								//proto and def.
	srand( (int)time(0));
	return rand()%s;
}


Card::Card(int face, int suit){ //constructor for card
	if (face>=1&& face<=13) this-> face = face;
	else exit(EXIT_FAILURE);
	if (suit>=1 && suit<=4) this-> suit = suit;
	else exit(EXIT_FAILURE);
}
string Card::toString() const{
	return  Faces[face-1] + " " + Suits[suit-1] ;
}
int Card::getIntFace() const{	return this->face; }
string Card::getStrFace() const{	return Card::Faces[face-1]; }
int Card::getIntSuit() const  {	return this->suit; }
string Card::getStrSuit() const{	return Card::Suits[suit-1]; }



DeckOfCards::DeckOfCards(const bool & DeckFlag){ //constructor for deck
	deck.clear();
	if (DeckFlag == true){
		for (int s=1; s<5; s++){
			for (int f=1; f<14; f++){
				deck.push_back( Card(f,s) );
				/*Alternatively:
				 Card c(f,s);
				 deck.push_back( c);*/
			}
		}
	}
}
void DeckOfCards::shuffle( bool flag ){//true: turn on random; false: turnoff random.
	if (flag == true)
		random_shuffle(deck.begin(), deck.end(), myRand ); //end() points to past-the-end position.
	else
		random_shuffle(deck.begin(), deck.end() ); //use default rand_generatpor.
	/**<random_shuffle(): randomize btw deck.begin() and deck.end(), including the 1st but not the end element>**/
}
Card DeckOfCards:: dealCard() {
	Card c = *deck.begin();
	deck.erase(deck.begin());
	return c;
}
bool DeckOfCards::moreCards() const{
	return (deck.size() > 0 )? true: false;
}
void DeckOfCards::print() const {
	for(int i=0; i < deck.size(); i++){
		if ( i % 5 == 0) cout << endl << "  ";
		cout << left << setw(11) << deck.at(i).toString();
	}
	cout << endl << endl;
}
int DeckOfCards::deckSize() const{
	return (int)deck.size();
}



HandOfCards::HandOfCards( const bool & HandFlag){
	hand.clear();
	if(HandFlag == true){
		DeckOfCards Deck;
		for( int i =0; i <5; i++)
			hand.push_back( Deck.dealCard() );
	}
}
HandOfCards::HandOfCards( DeckOfCards & Deck ){
	hand.clear();
	for (int i=0; i<5; i++){
		this->hand.push_back( Deck.dealCard() );
	}
}

int HandOfCards::judgeHand() const{
	if( (*this).haveStraight() && (*this).haveFlush() ) return 1;
	if( (*this).have4aKind() ) return 2;
	if( (*this).have3aKind() && (*this).havePair()) return 3;
	if( (*this).haveFlush() ) return 4;
	if( (*this).haveStraight() ) return 5;
	if( (*this).have3aKind() /*&& !(*this).havePair()*/) return 6;
	if( (*this).have2Pairs() ) return 7;
	if( (*this).havePair() ) return 8;
	return 9;
}
bool HandOfCards::havePair() const{
	int counter[13] = {};
	for (int i =0; i< 5; i++)
		++counter[ hand.at(i).getIntFace()-1 ];
	for (int p =0; p<13; p++)
		if(counter[p]==2)
			return true;
	return false;
}
bool HandOfCards::have2Pairs() const{
	int counter[13] = {}, temp = 0;
	for (int i =0; i< 5; i++)
		++counter[ hand.at(i).getIntFace()-1 ];
	for (int p =0; p<13; p++)
		if(counter[p]==2) ++temp;
	return (temp == 2)? true: false;
}
bool HandOfCards::have3aKind() const{
	int counter[13] = {};
	for (int i =0; i< 5; i++)
		++counter[ hand.at(i).getIntFace()-1 ];
	for (int p =0; p<13; p++)
		if(counter[p]==3) return true;
	return false;
}
bool HandOfCards::have4aKind() const {
	int counter[13] = {};
	for (int i =0; i< 5; i++)
		++counter[ hand.at(i).getIntFace()-1 ];
	for (int p =0; p<13; p++)
		if(counter[p]==4) return true;
	return false;
}
bool HandOfCards::haveFlush() const{
	int counter[4] = {};
	for (int i =0; i<5; i++)
		++counter[ hand.at(i).getIntSuit()-1 ];
	for (int p =0; p<4; p++){
		if ( counter[p] !=0 ) return (counter[p]==5)? true: false;
	}

	exit(EXIT_FAILURE); //should not reach here.
}
bool HandOfCards::haveStraight() const{
	int arr[5] = {} ;
	for (int i =0; i<5; i++)
		arr[i] = this->hand.at(i).getIntFace();

	//bubble sort Ace is the largest(in the end)
	bubbleSort(arr);

	//check straight
	//case1: 10,J,Q,K,A
	if (arr[0]==10 && arr[1]==11 && arr[2]==12 && arr[3]==13 && arr[4]==1 ) return true;
	//case2: Other straight
	for (int i =0; i < 4; i++)
		if (arr[i+1] != arr[i]+1 ) return false;
	return true;
}
void HandOfCards::sortPrint() const{
	int arr[5] = {};
	for(int i=0; i<5; i++)
		arr[i] = hand.at(i).getIntFace();
	bubbleSort(arr);
	for(int i=0; i<5; i++)
		cout << left << setw(11) << arr[i];
	cout << endl;
}
void HandOfCards::print() const{
	if (hand.size() == 5){
		cout << "  ";
		for (int i =0; i < 5; i++)
			cout << left << setw(11) << hand.at(i).toString();
		cout << endl;
	}
	else cout << "hand size incorrect!\n";
}
void HandOfCards::typePrint() const{
	switch ( judgeHand() ){
		case 0: cout << "Five of a Kind."; break;
		case 1: cout << "Straight Flush."; break;
		case 2: cout << "Four of a Kind."; break;
		case 3: cout << "Full House."; break;
		case 4: cout << "Flush."; break;
		case 5: cout << "Straight."; break;
		case 6: cout << "Three of a Kind."; break;
		case 7: cout << "Two Pairs."; break;
		case 8: cout << "One Pair."; break;
		case 9: cout << "High Card (ie. nothing)"; break;
		default: exit(EXIT_FAILURE); //shouldn't reach here
	}
	cout << endl;
}
int HandOfCards::betterHand( HandOfCards * oppoHandPtr) const{
	/*Rank number: 0: FiveOfaKind 1:Straight Flush 2:FourOfaKind 3:Full House 4:Flush 5:Straight
	 6:ThreeOfaKind 7: TwoPair 8:OnePair 9:High Card*/
	/*In the above, all types of hands that differ by suit alone are of equal rank.*/

	//judge myHand and opponent's hand
	int myNum = this -> judgeHand();
	int oppoNum = oppoHandPtr -> judgeHand();

	//compare
	if( myNum < oppoNum ) return 1;
	else if (myNum > oppoNum) return -1;
	else
	{ //case myNum == oppoNum

		//construct Arrays representing Hand
		int myArr[5] = {}, oppoArr[5] = {};
		int myAceCounter = 0, oppoAceCounter = 0;

		for(int i=0; i<5; i++){
			myArr[i] = hand.at(i).getIntFace();
			oppoArr[i] = (*oppoHandPtr).hand.at(i).getIntFace();
		}
		//Ace is the largest(in the end if any)
		bubbleSort(myArr);
		bubbleSort(oppoArr);

		//construct/evaluate number of aces in each hand
		for (int i =0; i<5; i++){
			if ( myArr[i] == 1) ++myAceCounter;
			if ( oppoArr[i] == 1) ++oppoAceCounter;
		}

		switch (myNum){
			case 1: //flush straight
			case 4: //flush
			case 5: //straight
			case 9: //high card
				//In The above cases, it's impossible that 2 or more cards have the same number.
				return RtoLcompare(myArr, oppoArr);
			case 2:
			case 3:
			case 6:
			{	//The order must be: 1vs4 or 4vs1 (2vs3 or 3vs2) (3vs1vs1 or 1vs1vs3),
			    // so posi [2] must take the mass number ove all 5 cards.
				int myMax=myArr[2], oppoMax=oppoArr[2];
				if ( myMax == 1 || myMax > oppoMax)  return 1;// 4or3-Ace of a kind is the largest
				else return -1; //impossible to be the same number.
			}
			case 7:
					//Re-sort again to transform 2pairs hand into 1-2-2 type
					twoPairsHandsort(myArr);
					twoPairsHandsort(oppoArr);
					return RtoLcompare(myArr, oppoArr);
			case 8:
					//Re-sort again to transform 1 pair hand into 1-1-1-2 type
					onePairHandsort(myArr);
					onePairHandsort(oppoArr);
					return RtoLcompare(myArr, oppoArr);
			default:
				exit(EXIT_FAILURE); //shouldn't reach here.
		}//end switch
	}//end else

}//end function betterHand();
void HandOfCards::dealNewHandfromDeck( DeckOfCards * DeckPtr){

	if( DeckPtr->deckSize() < 5){
		cout << "Not enough cards in deck, required action failed\n";
		return;
	}
	this->hand.clear();
	for(int i =0; i< 5; i++)
		this->hand.push_back( DeckPtr -> dealCard() );
}
inline void bubbleSort( int * arr ){
    /// Note: In this game, Ace is the largest. I define its value as 13, and I'll redefine its value back to 1 later.
	for (int i =0; i< 5; i++)
		if (arr[i] == 1) arr[i]=14;
	for ( int pass = 1; pass < 5; ++pass )
		for ( int comp = 0; comp < 5-1; ++comp )
			if ( arr[ comp ] > arr[ comp + 1 ] )
				swap( arr[ comp] , arr[ comp+1] );
	for (int i =0; i< 5; i++ )
		if (arr[i] ==14) arr[i]=1;
}
inline void swap( int & x, int & y){
	int temp = x;
	x = y;
	y = temp;
}
//compare from right to left (ignore types)
inline int RtoLcompare(int * arr, int * brr){
	for( int i = 4; i >=0; i-- ){
		if (arr[i] == 1 && brr[i] != 1) return 1;
		else if (arr[i] != 1 && brr[i] == 1) return -1;
		else if (arr[i] > brr[i]) return 1;
		else if (arr[i] < brr[i]) return -1;
	}
	return 0; //if pass the for loop, it means all are the same.
}
inline void twoPairsHandsort( int * arr){ //Transform into 1-2-2 type
	if ( arr[2] != arr[1] && arr[2] != arr[3] ) //2-1-2 type
		swap(arr[0], arr[2]);
	else if ( arr[2]==arr[3] ){ //2-2-1 type
		swap(arr[4], arr[2]);
		swap(arr[2], arr[0]);
	}
}
inline void onePairHandsort(int * arr){
	int posi = 0, temp = 0;
	for(int i =0; i<5; i++){
		if ( arr[i] == arr[i+1] ){
			posi = i;
			break;
		}
	}
	temp = arr[posi];
	for (int i =posi; i<5-2; i++)
		arr[i] = arr[i+2];
	arr[3] = arr[4] = temp;
}
/**<What I Learned：
    1. If a function is declared with "const", then in its body, only member functions declared with "const" can be used.
	2. Non-member function cannot have const qualifier.>**/
/**<End-------Ex10.10 to Ex10.14: Card Shuffling and Dealing>**/
