//
//  Chapter10_Exercises.cpp
//  20170627 Chapter 10 Exercises
//
//  Created by kai on 05/11/2017.
//  Copyright © 2017 Wen-Kai Chung. All rights reserved.
//

#include "Chapter10_Exercises.hpp"

const string Exercise10_6_Date::MonthName[monthsPerYear+1] = { "0", "January", "February", "March", "April", "May", "June", "Juli", "August", "September", "October", "November", "December" };
const int Exercise10_6_Date::daysPerMonth[ monthsPerYear + 1 ] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

Exercise10_6_Date::Exercise10_6_Date( int mn, int dy, int yr ){ //constructor for format b

	if ( mn > 0 && mn <= monthsPerYear ) // validate the month
		month = mn;
	else {
		month = 1; // invalid month set to 1
		cout << "Invalid month (" << mn << ") set to 1.\n";
	}
	year = yr; // could validate yr
	day = checkDay( dy ); // validate the day

	cout << "Date object constructor for date ";
	print('b');
	cout << endl;
}

Exercise10_6_Date::Exercise10_6_Date(int ddd, int yr){ //constructor for format a

	if (ddd < 0){ //case:  <0
		cout << "Invalid day (" << ddd << ") set to 1.\n";
		day = 1;
		month = 1;
	}
	else if (ddd > 365 && yr % 4 == 0 ){//case: leap year
		cout << "Invalid day (" << ddd << ") set to 1.\n";
		day = 1;
		month = 1;
	}
	else if (ddd > 366 && yr % 4 != 0 ){ // case: normal year
		cout << "Invalid day (" << ddd << ") set to 1.\n";
		day = 1;
		month = 1;
	}
	else{ //validation pass! set values.
		int temp = 0;
		for ( temp = 0; ddd > daysPerMonth[temp] ; temp++){
			if (yr % 4 == 0 && temp == 2){ //case: leap year
				if ( ddd > 1 + daysPerMonth[temp] ){
					ddd = ddd - 1 - daysPerMonth[temp];
					temp++;
				}
				else
					break;
			}
			else { //case: normal year
				ddd -=  daysPerMonth[temp];
				temp++;
			}
		} // end for.
		day = ddd;
		month = temp;

	}
	year = yr;
	cout << "Date object constructor for date ";
	print('a');
	cout << endl;

}
Exercise10_6_Date::Exercise10_6_Date ( string strM, int dy, int yr){
	size_t strFind = 0;
	int i = 0;
	for ( i =0; i<13; i++){
		strFind = static_cast<string>(MonthName[i]).find(strM);
		if ( strFind != string::npos ){
			month = i;
			break;
		}
	}
	if (i==13){
		cout << "Invalid month string (" << strM << ") set to January.\n";
		month = 1;
	}

	day = checkDay(dy);
	year = yr;
	cout << "Date object constructor for date ";
	print('c');
	cout << endl;
}
Exercise10_6_Date::Exercise10_6_Date( struct tm ){ //ctime-get current time
	time_t t;
	time(&t); //get current time
	struct tm * currentTime = localtime(&t);

	day = currentTime -> tm_mday;
	month = 1 + currentTime -> tm_mon;
	year = 1900 + currentTime -> tm_year;
}
// print Date object in form month/day/year
void Exercise10_6_Date::print(const char & formatOption) const {

	switch ( formatOption ){
		case 'a':
		{	/**< {}breackets is necessary here since I declare a var inside switch statement, which will
			 interupt the corr. Label mechanism in assembly.*/
			int temp = 0;
			for (int i = 0 ; i < month; i++)
				temp += daysPerMonth[i];
			temp += day;
			cout << setfill('0') << setw(3) <<  temp << " " <<setw(4) << year << setfill(' ') << endl;
			break;
		}
		case 'b':
			cout << setfill('0') << setw(2) << month << "/" << setw(2) << day << "/" << setw(4) << year << setw(' ')<< endl;
			break;
		case 'c':
			cout << setw(3) << MonthName[month].substr(0,3) << " " << setfill('0')
				 << setw(2) << day << ", " << setw(4) << year << setfill(' ') << endl;
			break;
	}
}
Exercise10_6_Date::~Exercise10_6_Date(){
	cout << "Date object destructor for date ";
	print('a');
	print('b');
	print('c');
	cout << endl;
}
int Exercise10_6_Date::checkDay( int testDay ) const {

	if ( testDay > 0 && testDay <= daysPerMonth[ month ] )
		return testDay;
	if (month==2 && testDay==29&&(year%400==0|| (year%4==0 &&year%100!=0)))
		return testDay;

	cout << "Invalid day (" << testDay << ") set to 1.\n";
	return 1; // leave object in consistent state if bad value
}



double SavingsAccount10_7::annualInterestRate = 0;
SavingsAccount10_7::SavingsAccount10_7(const double &balance ){
    this -> SavingsBalance = (balance >= 0)? balance : 0;
}
SavingsAccount10_7::~SavingsAccount10_7(){
    ;
}
double SavingsAccount10_7::calculateMonthlyInterests(){
    //monthlyInterest = balance * annualInterestRate /12; add it to SavingsBalance
    return SavingsBalance * (1+ annualInterestRate) / 12 ;
}
void SavingsAccount10_7::addIntereststoSavings(){
    SavingsBalance += calculateMonthlyInterests();
}
void SavingsAccount10_7::print(){
    double temp = calculateMonthlyInterests();
    cout << "interest is " << temp << endl;
    cout << "new balance is " <<  SavingsBalance+temp << endl;
}
void SavingsAccount10_7::modifyIntrestRate( const double & rate ){
    annualInterestRate = rate;
}



void IntegerSet10_8::objInitial(){
    this -> IntegerBoolSet.assign(101, 0);
}
IntegerSet10_8::IntegerSet10_8( const vector<int> * const intVecPtr ) { //type1 constructor
    objInitial();
    for (int i=0; i< intVecPtr->size() ; i++)
        if ( intVecPtr->at(i) >= 0 && intVecPtr->at(i) <= 100)
            IntegerBoolSet.at( intVecPtr->at(i) ) = 1;
}
IntegerSet10_8::IntegerSet10_8(const vector<bool>* const boolVecPtr ){ //type2 and also the default type constructor
    objInitial();
    IntegerBoolSet =  *boolVecPtr;
    IntegerBoolSet.resize(101, 0);
}
IntegerSet10_8::IntegerSet10_8(const int arr[], const int &arrSize ){ //type3 constructor
    objInitial();
    for (int i=0; i< arrSize ; i++)
        if ( arr[i] >= 0 && arr[i] <= 100)
            IntegerBoolSet.at( arr[i] ) = 1;
}
IntegerSet10_8::IntegerSet10_8(const bool arr[], const int &arrSize){ //type4 constructor
    objInitial();
    for(int i=0; i<arrSize ; i++)
        IntegerBoolSet.at(i) = arr[i];
}
/**<special type: initializer_list (take precedence over other constructors)>**/
IntegerSet10_8::IntegerSet10_8(const initializer_list<int> &args ){
    objInitial();
    initializer_list<int>::iterator it;
    for(it = args.begin(); it != args.end(); it++ )
        if ( *it > 0)
            IntegerBoolSet.at( *it ) = 1;
}

void IntegerSet10_8::unionOfSets( IntegerSet10_8  st){
    for(int i=0; i < this->IntegerBoolSet.size(); i++)
         IntegerBoolSet.at(i) = IntegerBoolSet.at(i) | st.IntegerBoolSet.at(i);
}
void IntegerSet10_8::intersectionOfSets( IntegerSet10_8 st){
    for(int i=0; i< this->IntegerBoolSet.size(); i++)
        IntegerBoolSet.at(i) = IntegerBoolSet.at(i) & st.IntegerBoolSet.at(i);
}
void IntegerSet10_8::insertElement( const int & ele){
    if (ele>=0 && ele <= 100)
        IntegerBoolSet.at(ele)=1;
}
void IntegerSet10_8::deleteElement( const int & ele){
    if(ele>=0 && ele <= 100)
        IntegerBoolSet.at(ele)=0;
}
bool IntegerSet10_8::isEqualtTo( IntegerSet10_8 st ) const{
    for ( int i=0; i < this->IntegerBoolSet.size(); i++)
        if( IntegerBoolSet.at(i) != st.IntegerBoolSet.at(i) )
            return 0;
    return 1;
}
void IntegerSet10_8::printSet() const{
    bool flag=0;
    for ( int i=0; i< this->IntegerBoolSet.size(); i++){
        if(IntegerBoolSet.at(i) == 1){
            cout << i << " ";
            flag =1;
        }
    }
    if (flag == 0) cout<<"empty set";
    cout << endl;
}


Time10_9::Time10_9( int hr, int min, int sec){
    this -> second = 0;
    setTime(hr, min, sec);
}
Time10_9 & Time10_9::setTime(int h , int m , int s ){
    setHour(h);
    setMinute(m);
    setSecond(s);
    return *this; /**<enables cascading>**/
};
Time10_9 & Time10_9::setHour(int h ){
    second %= 3600; //remove hours and preserve minutes and seconds.
    second += (h >= 0 && h < 24)? h*3600 : 0 ; //reset/add on hours
    return *this; /**<enables cascading>**/
}
Time10_9 & Time10_9::setMinute(int m ){
    second = (second %60) + (second/3600)*3600;
    second += ( m >= 0 && m < 60)? m*60 : 0;
    return *this; /**<enables cascading>**/
}
Time10_9 & Time10_9::setSecond(int s){
    second -= (second%60); //preserve hours and minute
    second += ( s >= 0 && s < 60)? s: 0;
    return *this; /**<enables cascading>**/
}
int Time10_9::getHour() const{
    return (second/3600);
}
int Time10_9::getMinute() const{
    return (second%3600)/60;
}
int Time10_9::getSecond() const{
    return (second%60);
}
void Time10_9::printUniversal() const{
    cout << setfill('0') << setw(2) << second/3600 << ":" <<setw(2) << (second%3600)/60 << ":" <<setw(2) << (second%60);
}
void Time10_9::printStandard() const{
    cout << (( second/3600 == 0 || second/3600 == 12 )? 12 :  (second/3600)%12  )
        << ":" << setfill('0') << setw(2) << ( second%3600 )/60
        << ":" << setw(2) << second%60 << ( second/3600 < 12 ? " AM" : " PM" );
}



/**<Start-----Ex10.10 to Ex10.14: Card Shuffling and Dealing>**/
string Card::Faces[13] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
string Card::Suits[4] = {"Club","Diamond","Heart","Spade"};
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
				deck.push_back( Card::Card(f,s) );
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
	/**<random_shuffle() randomize btw deck.begin() and deck.end(), including the 1st but not the end element>**/
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
				//以上情形皆不可能有 兩張(含以上)一樣大的可能。
				return RtoLcompare(myArr, oppoArr);
			case 2:
			case 3:
			case 6:
			{	//順序必為 1張4張 或 4張1張 (2張3張 或 3張2張)(3張1張1張 或 1張3張1張 或 1張1張3張)  故[2]必定取到眾數
				int myMax=myArr[2], oppoMax=oppoArr[2];
				if ( myMax == 1 || myMax > oppoMax)  return 1;// 4or3-Ace of a kind is the largest
				else return -1; //沒有一樣大的可能
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
	//QQQ可否直接呼叫constructor?
	
	if( DeckPtr->deckSize() < 5){
		cout << "Not enough cards in deck, required action failed\n";
		return;
	}
	this->hand.clear();
	for(int i =0; i< 5; i++)
		this->hand.push_back( DeckPtr -> dealCard() );
}
inline void bubbleSort( int * arr ){
	for (int i =0; i< 5; i++)//Ace最大 暫時改成13之後再改回來
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
/**<小結： function 如宣告const，有些函數會不見Compiler會無法識別，Eg: vector<int> X; X.erase() 無法使用。
	2. Non-member function cannot have const qualifier.(不能宣告function 為 const)>**/






/**<End-------Ex10.10 to Ex10.14: Card Shuffling and Dealing>**/
