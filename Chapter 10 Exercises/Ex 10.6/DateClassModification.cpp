#include "DateClassModification.hpp"

const string Date::MonthName[monthsPerYear+1] = { "0", "January", "February", "March", "April", "May", "June", "Juli", "August", "September", "October", "November", "December" };
const int Date::daysPerMonth[ monthsPerYear + 1 ] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

Date::Date( int mn, int dy, int yr ){ //constructor for format b

	if ( mn > 0 && mn <= monthsPerYear ) // validate the month
		month = mn;
	else {
		month = 1; // invalid month set to 1
		cout << "Invalid month (" << mn << ") set to 1.\n";
	}
	year = yr; // could validate yr
	day = checkDay( dy ); // validate the day

	cout << "Date object constructor for date ";
	print('b');
	cout << endl;
}

Date::Date(int ddd, int yr){ //constructor for format a

	if (ddd < 0){ //case:  <0
		cout << "Invalid day (" << ddd << ") set to 1.\n";
		day = 1;
		month = 1;
	}
	else if (ddd > 365 && yr % 4 == 0 ){//case: leap year
		cout << "Invalid day (" << ddd << ") set to 1.\n";
		day = 1;
		month = 1;
	}
	else if (ddd > 366 && yr % 4 != 0 ){ // case: normal year
		cout << "Invalid day (" << ddd << ") set to 1.\n";
		day = 1;
		month = 1;
	}
	else{ //validation pass! set values.
		int temp = 0;
		for ( temp = 0; ddd > daysPerMonth[temp] ; temp++){
			if (yr % 4 == 0 && temp == 2){ //case: leap year
				if ( ddd > 1 + daysPerMonth[temp] ){
					ddd = ddd - 1 - daysPerMonth[temp];
					temp++;
				}
				else
					break;
			}
			else { //case: normal year
				ddd -=  daysPerMonth[temp];
				temp++;
			}
		} // end for.
		day = ddd;
		month = temp;

	}
	year = yr;
	cout << "Date object constructor for date ";
	print('a');
	cout << endl;

}
Date::Date ( string strM, int dy, int yr){
	size_t strFind = 0;
	int i = 0;
	for ( i =0; i<13; i++){
		strFind = static_cast<string>(MonthName[i]).find(strM);
		if ( strFind != string::npos ){
			month = i;
			break;
		}
	}
	if (i==13){
		cout << "Invalid month string (" << strM << ") set to January.\n";
		month = 1;
	}

	day = checkDay(dy);
	year = yr;
	cout << "Date object constructor for date ";
	print('c');
	cout << endl;
}
Date::Date( struct tm ){ //ctime-get current time
	time_t t;
	time(&t); //get current time
	struct tm * currentTime = localtime(&t);

	day = currentTime -> tm_mday;
	month = 1 + currentTime -> tm_mon;
	year = 1900 + currentTime -> tm_year;
}
// print Date object in form month/day/year
void Date::print(const char & formatOption) const {

	switch ( formatOption ){
		case 'a':
		{	/**< {}breackets is necessary here since I declare a var inside switch statement, which will
			 interupt the corr. Label mechanism in assembly.*/
			int temp = 0;
			for (int i = 0 ; i < month; i++)
				temp += daysPerMonth[i];
			temp += day;
			cout << setfill('0') << setw(3) <<  temp << " " <<setw(4) << year << setfill(' ') << endl;
			break;
		}
		case 'b':
			cout << setfill('0') << setw(2) << month << "/" << setw(2) << day << "/" << setw(4) << year << setw(' ')<< endl;
			break;
		case 'c':
			cout << setw(3) << MonthName[month].substr(0,3) << " " << setfill('0')
				 << setw(2) << day << ", " << setw(4) << year << setfill(' ') << endl;
			break;
	}
}
Date::~Date(){
	cout << "Date object destructor for date ";
	print('a');
	print('b');
	print('c');
	cout << endl;
}
int Date::checkDay( int testDay ) const {

	if ( testDay > 0 && testDay <= daysPerMonth[ month ] )
		return testDay;
	if (month==2 && testDay==29&&(year%400==0|| (year%4==0 &&year%100!=0)))
		return testDay;

	cout << "Invalid day (" << testDay << ") set to 1.\n";
	return 1; // leave object in consistent state if bad value
}
