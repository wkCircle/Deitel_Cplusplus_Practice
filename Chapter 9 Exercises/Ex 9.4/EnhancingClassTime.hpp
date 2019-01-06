#ifndef EnhancingClassTime_hpp
#define EnhancingClassTime_hpp


#include <cstdio>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;

class Time9_4 {
public:
	Time9_4(); //initialize private data to current time
private:
	int year;
	int month;
	int mday;
	int hour;
	int minute;
	int second;
};

#endif // EnhancingClassTime_hpp
