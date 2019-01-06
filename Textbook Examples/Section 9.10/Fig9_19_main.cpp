#include "Fig9_17_Date.hpp"

int main(){
	Date date1( 7, 4, 2004 );
	Date date2; //date2 defaults to 1/1/2000

	cout << "date1 = ";
	date1.print();

	cout << "\ndate2 = ";
	date2.print();

	//********************KEY!*********************
	date2 = date1; // default memberwise assignment
	//********************KEY!*********************

	cout << "\n\nAfter default memberwise assignment, date2 = ";
	date2.print();
	cout << endl;
}
/**<memberwise assignement operator (=): can assign an opject to another object of the same type.>**/


