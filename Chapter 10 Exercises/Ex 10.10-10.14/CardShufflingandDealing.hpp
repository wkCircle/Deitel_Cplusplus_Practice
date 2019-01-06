
//
//  Chapter10_Exercises.hpp
//  20170627 Chapter 10 Exercises
//
//  Created by kai on 05/11/2017.
//  Copyright © 2017 Wen-Kai Chung. All rights reserved.
//
/**<Start-----Ex10.10 to Ex10.14: Card Shuffling and Dealing>**/
#ifndef CardShufflingandDealing_hpp
#define CardShufflingandDealing_hpp

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cstdio>
#include <typeinfo>
#include <initializer_list>
#include <algorithm> //random_shuffle();
using namespace std;

class Card{
	int face;//1-13
	int suit;//1-4
	static string Faces[];
	static string Suits[];
public:
	Card(int, int );
	string toString() const; //returns the card as a string in the form "face of suit"
	int getIntFace() const;
	string getStrFace() const;
	int getIntSuit() const;
	string getStrSuit() const;
};

class DeckOfCards{
	vector<Card> deck; //0-51
	int currentCard; //representing the next card to deal
public:
	DeckOfCards(const bool & = true); //initialize contents in deck.
	void shuffle( bool =true); //shuffle the cards in the deck.
	Card dealCard(); //returns the next card object from the deck.
	bool moreCards() const; //whether there are more cards to deal.
	void print() const;
	int deckSize() const;

};

class HandOfCards{
	vector<Card> hand; //5 cards in total
public:
	HandOfCards( const bool & = true);
	HandOfCards( DeckOfCards & );

	int judgeHand() const;
	bool havePair() const;
	bool have2Pairs() const ;
	bool have3aKind() const;
	bool have4aKind() const;
	bool haveFlush() const;
	bool haveStraight() const;
	void sortPrint() const;
	void print() const;
	void typePrint() const;
	int betterHand( HandOfCards *) const; //return 1 means better, 0 equal rank, -1 worse.
	void dealNewHandfromDeck( DeckOfCards *);
};

#endif // CardShufflingandDealing_hpp
/**<End-------Ex10.10 to Ex10.14: Card Shuffling and Dealing>**/
