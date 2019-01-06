#include "SalespersonSalaryRangeswithVector.hpp"

int main(int argc, const char * argv[]) {
	size_t num_salespeople = ExerCh7_38::getmembers();
	vector<int> grosses(num_salespeople, 0); //30 elements, initialize all entries with value = 0.
	for (int i=0; i<num_salespeople; i++){
		grosses.at(i) =  rand() % 20000 /2;
	}
	ExerCh7_38 Grus( grosses );
	Grus.salespersonSalaryRangeswithVector();
}
