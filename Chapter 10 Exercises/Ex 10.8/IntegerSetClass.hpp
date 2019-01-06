#ifndef IntegerSetClass_hpp
#define IntegerSetClass_hpp

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

class IntegerSet {
    vector<bool> IntegerBoolSet;
public:
    void objInitial();
    IntegerSet(const vector<int> * const ); //type1
    IntegerSet(const vector<bool>* const ); //type2 and standard type constructor.
    IntegerSet(const int [], const int& = 101); //type3
    IntegerSet(const bool[], const int& = 101); //type4
    IntegerSet(const initializer_list<int> & ); //ref: cplusplus std::initializer_list and its member function ::size
    void unionOfSets( IntegerSet );
    void intersectionOfSets( IntegerSet );
    void insertElement( const int & );
    void deleteElement( const int & );
    bool isEqualtTo( IntegerSet ) const;
    void printSet() const; //list of numbers separated by spaces; print "---" for an empty set.


};

#endif // IntegerSetClass_hpp
