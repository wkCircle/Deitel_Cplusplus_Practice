//7.38 //require header file #include<vector>
#include "SalespersonSalaryRangeswithVector.hpp"

ExerCh7_38::ExerCh7_38( vector<int> &input ){
	setGrossesOfSalesperson(input);
}
void ExerCh7_38::setGrossesOfSalesperson( vector<int> &input ){
		grosses = input;//will change size of grosses7_38 directly to match input.
}
void ExerCh7_38::salespersonSalaryRangeswithVector(){
	const int num_catogaries = 9;
	vector<int> frequency(num_catogaries, 0); //from 0th to 8th position, all are initialized with value = 0.
	int temp_Salary=0, to_Category=0;

	for(int i = 0; i < members; i++){
		temp_Salary = 200 + 0.09 * grosses.at(i);
		to_Category = (temp_Salary-200) / 100;

		//since [] operator doesn't check borders, it's better to use .at() to visit address.
		if (to_Category >= num_catogaries-1 )
			frequency.at(num_catogaries-1)++;
		else
			frequency.at(to_Category)++;
	}

	//print frequency()
	cout << right << setw(13) << "Salary Range: " << endl;//header
	for (int i = 0; i< num_catogaries; i++){
		if (i == num_catogaries-1 ) //last case title
			cout << "$" << i*100+200 << " and over: ";
		else
			cout << right << setw(7) << "$" << i*100+200 << "-" << i*100+299 << ": ";

		for (int j=0; j<frequency.at(i); j++ ){
			cout << '*';
		}
		cout << endl;
	}
}
