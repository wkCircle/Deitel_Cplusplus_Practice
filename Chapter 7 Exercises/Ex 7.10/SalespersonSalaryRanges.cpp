#include "SalespersonSalaryRanges.hpp"
ExerCh7_10::ExerCh7_10(int in_grosses[]){
	 setGrossesOfSalesperson(in_grosses);
}
void ExerCh7_10::setGrossesOfSalesperson(int in_grosses[] ){
	for (int i=0; i<members; i++){
		this->grosses[i] = in_grosses[i];
	}
}
const int ExerCh7_10::getmembers(){
	return members;
}
void ExerCh7_10::salespersonSalaryRanges(){
	const int num_catogaries = 9;
	int frequency[num_catogaries]={}; //from 0th to 8th position.
	int temp_Salary=0, to_Category=0;

	for(int i=0; i<members; i++){
		temp_Salary = 200 + 0.09 * grosses[i];
		to_Category = (temp_Salary-200) / 100;
		if (to_Category>= num_catogaries-1 )
			frequency[num_catogaries-1]++;
		else
			frequency[to_Category]++;
	}

	//print frequency[]
	cout << right << setw(13) << "Salary Range: " << endl;//header
	for (int i=0; i< num_catogaries; i++){
		if (i==num_catogaries-1) //last case title
			cout << "$" << i*100+200 << " and over: ";
		else
			cout << right << setw(7) << "$" << i*100+200 << "-" << i*100+299 << ": ";

		for (int j=0; j<frequency[i]; j++ ){
			cout << '*';
		}
		cout << endl;
	}
}
