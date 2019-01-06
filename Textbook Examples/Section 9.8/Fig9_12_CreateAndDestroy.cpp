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


/**<�p��: �W���Ҥl���b���� �b���P���ɭԫŧi object1~7 ��, constructor �Q�I�s�����ᶶ��, �P�ɤ]�[��destructor�Q�I�s�����ᶶ��,
 1. ���Q�ŧi��, �N�|�P�ɩI�sconstructor.
 2. �p�G�Oautomatic, ��compiler���槹��ebrakets{}����, auto objects�N�|����, ���ɸ����ŧi���|���߳Q����, �ӫ�ŧi��������(�z�L�I�sdestructor)
 3. �@��ӻ�, �������ᶶ��: local auto -> static -> global. >**/
