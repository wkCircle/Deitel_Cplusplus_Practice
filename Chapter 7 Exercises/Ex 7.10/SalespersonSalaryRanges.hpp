#ifndef SalespersonSalaryRanges_hpp
#define SalespersonSalaryRanges_hpp

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;
class ExerCh7_10 {
public:
	ExerCh7_10(int []); //constructor
	const static int getmembers();
	void setGrossesOfSalesperson(int []);
	void salespersonSalaryRanges();

private:
	const static int members = 30;
	int grosses[members]; //cannot be declared as static???
};

#endif // SalespersonSalaryRanges_hpp
