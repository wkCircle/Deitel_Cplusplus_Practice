#include "salaryCalculator.hpp"


void salaryCalculator(){
	int wk_hrs=0;
	double rate_hr=0;

	while (wk_hrs != -1){
		cout << "Enter hours worked (or -1 to quit). \n";
		cin >> wk_hrs;
		if (wk_hrs == -1)
			return;

		cout << "Enter hourly rate of the employee.($00.00)\n";
		cin >> rate_hr;

		if (wk_hrs <= 40)
			cout << "Salary is: " << wk_hrs * rate_hr << endl ;
		else
			cout<< "Salary is: "<< wk_hrs * rate_hr + (wk_hrs-40) * rate_hr *0.5 << endl;
	}

}
