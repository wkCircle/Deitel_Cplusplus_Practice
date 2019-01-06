#ifndef SalespersonSalaryRangeswithVector_hpp
#define SalespersonSalaryRangeswithVector_hpp


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

class ExerCh7_38 { //similar to ExerCh7_10 but use 'vector' to solve question.
public:
	ExerCh7_38( vector<int> & );
	static int getmembers(){
		return members;
	}
	void setGrossesOfSalesperson ( vector<int> & );
	void salespersonSalaryRangeswithVector();

private:
	const static int members = 30;
	vector<int> grosses; //ªì©lªø«×=0

};

#endif // SalespersonSalaryRangeswithVector_hpp
