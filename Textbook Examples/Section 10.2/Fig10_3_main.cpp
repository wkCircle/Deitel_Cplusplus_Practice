#include "Fig10_1_Time.hpp"

int main(){
	Time wakeUp( 6, 45, 0 ); // non-constant object
	const Time noon( 12, 0, 0 ); // constant object
	// OBJECT MEMBER FUNCTION
	wakeUp.setHour( 18 ); // non-const non-const
	//    noon.setHour( 12 ); // const non-const
	wakeUp.getHour(); // non-const const
	noon.getMinute(); // const const
	noon.printUniversal(); // const const
	//    noon.printStandard(); // const non-const
}


/**<小結:   1. constant obj to call a non-const function LEADS to an err.
 2. constant obj 只能使用 constant member function; non-constant obj 可以任意使用 member function.
 3. constant obj
 */
