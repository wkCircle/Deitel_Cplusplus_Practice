// Fig. 9.12: CreateAndDestroy.cpp
// CreateAndDestroy class member-function definitions.
#include "Fig9_11_CreateAndDestroy.hpp"

CreateAndDestroy::CreateAndDestroy( int ID, string messageString ){// constructor
	objectID = ID; // set object's ID number
	message = messageString; // set object's descriptive message
	cout << "Object " << objectID << "   constructor runs   "
	<< message << endl << endl;
} // end CreateAndDestroy constructor
CreateAndDestroy::~CreateAndDestroy(){// destructor
	// output newline for certain objects; helps readability
	cout << ( objectID == 1 || objectID == 6 ? "\n" : "" );
	cout << "Object " << objectID << "   destructor runs    "
	<< message << endl << endl;
} // end ~CreateAndDestroy destructor


/**<小結: 上面例子旨在說明 在不同的時候宣告 object1~7 時, constructor 被呼叫的先後順序, 同時也觀察destructor被呼叫的先後順序,
 1. 先被宣告的, 就會同時呼叫constructor.
 2. 如果是automatic, 當compiler執行完當前brakets{}之後, auto objects就會消滅, 此時較先宣告的會較晚被消滅, 而後宣告的先消滅(透過呼叫destructor)
 3. 一般來說, 消滅先後順序: local auto -> static -> global. >**/
