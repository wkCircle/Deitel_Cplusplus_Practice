//
//  Chapter10_Exercises.hpp
//  20170627 Chapter 10 Exercises
//
//  Created by kai on 05/11/2017.
//  Copyright © 2017 Wen-Kai Chung. All rights reserved.
//

#ifndef Chapter10_Exercises_hpp
#define Chapter10_Exercises_hpp

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

class Exercise10_6_Date{
public:
	static const int monthsPerYear = 12;
	static const int daysPerMonth[ monthsPerYear + 1 ];
	static const string MonthName[monthsPerYear+1 ];
	Exercise10_6_Date ( int = 1, int = 1, int = 1900 ); //format corr. to b
	Exercise10_6_Date ( int = 1, int = 1990); //format corr. to a
	Exercise10_6_Date ( string = "Jan uary", int =1, int =1900); //format corr. to c
	Exercise10_6_Date ( struct tm );
	void print( const char & ) const ;
	~Exercise10_6_Date();
private:
	int month; // 1-12 (January-December)
	int day; // 1-31 based on month
	int year; // any year
	// utility function to check if day is proper for month and year
	int checkDay( int ) const;
};

class SavingsAccount10_7{
public:

	SavingsAccount10_7(const double & );
	~SavingsAccount10_7();
	//monthlyInterest = balance * annualInterestRate[ person i] /12; add it to SavingsBalance
	double calculateMonthlyInterests();
	void addIntereststoSavings();

	static void modifyIntrestRate( const double & );
	void print();

private:
	static double annualInterestRate;
	double SavingsBalance = 0; //deposit
};

class IntegerSet10_8 {
    vector<bool> IntegerBoolSet;
public:
    void objInitial();
    IntegerSet10_8(const vector<int> * const ); //type1
    IntegerSet10_8(const vector<bool>* const ); //type2 and standard type constructor.
    IntegerSet10_8(const int [], const int& = 101); //type3
    IntegerSet10_8(const bool[], const int& = 101); //type4
    IntegerSet10_8(const initializer_list<int> & ); //ref: cplusplus std::initializer_list and its member function ::size
    void unionOfSets( IntegerSet10_8 );
    void intersectionOfSets( IntegerSet10_8 );
    void insertElement( const int & );
    void deleteElement( const int & );
    bool isEqualtTo( IntegerSet10_8 ) const;
    void printSet() const; //list of numbers separated by spaces; print "---" for an empty set.


};

class Time10_9 { //This exercise nicely demonstrates the virtues of implementation hiding.
    int second = 0;
public:
    Time10_9( int  =0, int =0, int =0);
    Time10_9 & setTime(int, int, int);
    Time10_9 & setHour(int);
    Time10_9 & setMinute(int);
    Time10_9 & setSecond(int);

    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    void printUniversal() const;
    void printStandard() const;

};

/**<Start-----Ex10.10 to Ex10.14: Card Shuffling and Dealing>**/
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

/**<End-------Ex10.10 to Ex10.14: Card Shuffling and Dealing>**/

#endif /* Chapter10_Exercises_hpp */
