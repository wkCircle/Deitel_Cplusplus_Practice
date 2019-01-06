#ifndef TimeClassModification_hpp
#define TimeClassModification_hpp

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

class Time { //This exercise nicely demonstrates the virtues of implementation hiding.
    int second = 0;
public:
    Time( int  =0, int =0, int =0);
    Time & setTime(int, int, int);
    Time & setHour(int);
    Time & setMinute(int);
    Time & setSecond(int);

    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    void printUniversal() const;
    void printStandard() const;

};


#endif // TimeClassModification_hpp
