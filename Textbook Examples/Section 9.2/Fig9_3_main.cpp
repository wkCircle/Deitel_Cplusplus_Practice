// Fig. 9.3: fig09_03.cpp
#include "Fig9_1_Time.hpp"

int main(){

	Time t; // instantiate object t of class Time

	// output Time object t's initial values
	cout << "The initial universal time is ";
	t.printUniversal(); // 00:00:00
	cout << "\nThe initial standard time is ";
	t.printStandard(); // 12:00:00 AM


	t.setTime( 13, 27, 6 ); // change time
	// output Time object t's new values
	cout << "\n\nUniversal time after setTime is ";
	t.printUniversal(); // 13:27:06
	cout << "\nStandard time after setTime is ";
	t.printStandard(); // 1:27:06 PM


	t.setTime( 99, 99, 99 ); // attempt invalid settings
	// output t's values after specifying invalid values
	cout << "\n\nAfter attempting invalid settings:"
	<< "\nUniversal time: ";
	t.printUniversal(); // 00:00:00
	cout << "\nStandard time: ";
	t.printStandard(); // 12:00:00 AM

	cout << endl;
}
