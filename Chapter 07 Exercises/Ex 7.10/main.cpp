#include "SalespersonSalaryRanges.hpp"

int main(){

	const int num_salespeople = ExerCh7_10::getmembers();
	int grosses[num_salespeople];
		//initialize each salesperson's gross sales
	for (int i=0; i<num_salespeople; i++){
		grosses[i] =  rand() % 20000 /2;
	}
	//function call
	ExerCh7_10 Happiness(grosses);
	Happiness.salespersonSalaryRanges();
}


