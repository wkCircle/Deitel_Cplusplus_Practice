#include "Fig10_10_Date.hpp"
#include "Fig10_12_Employee.hpp"
int main(){
	Date birth( 7, 24, 1949 );
    Date hire( 3, 12, 1988 );
	Employee manager( "Bob", "Blue", birth, hire );
	cout << endl;
	manager.print();
	cout << "\nTest Date constructor with invalid values:\n";
	Date lastDayOff( 14, 35, 1994 ); // invalid month and day
	cout << endl;
}


/**<�p��: (Fig10.10-Fig10.14)
 1. member initializer list �X�{�bconstructor���ѼƤ���A�e���n�[�W ":" �H�K��Ѽư��Ϲj
 2. Composition�ޥ�: 1��class�i�H�b�غcobject�ɡA�ѼƸ̭���Ӧۨ�Lclass��object,
 �hcompiler�|���غc�ѼƤ�����A�̫�~�إ߭�l����A(���ܦ۵M�A�]���n�غc�Ӫ���N�������غc�Ӫ���data members)�C
 3. �p�G��member initializer list������Date Obj ����泣���ѱ��A�hcompiler ���غc��l��Date object: birth, hire,
 �M��i�JEmployee::Employee, �ݨ�member initializer list�S���w�q�A�h�I�sdefault constructor of class Date�H�غc
 birthDate, hireDate, �o��ӳ��Oclass Employee���U��private data member object of type Date, �w�]�ȬO1/1/1900,
 �ҥH�Y��birth, hire ���g�b �w�qmanager���󪺰ѼƸ̵M��bemployee constructor�̭����ӥN�W���s��dateOfBirth, dateOfHire�A
 �������S�Ψ��~~�Ѧ��i�� member initializer���U�� birth, hire ���ȡA�ǻ���dateOfBirth, dateOfHire���Y�C
 4. ��3, ����member initializer�]�i�H�A���N�n�bconstructor body�̭�assgin(�Ҧp��set function)*/
