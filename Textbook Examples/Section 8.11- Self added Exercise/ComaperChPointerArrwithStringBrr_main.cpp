//Self Exercises (cf. Section 8.11 page 373)
//Compare const char * arr[4] with string brr[4], both of which have smae values.

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <typeinfo>
#include <ctime>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

void ComaperChPointerArrwithStringBrr(); // prototype
int main(){
    ComaperChPointerArrwithStringBrr();
}




void ComaperChPointerArrwithStringBrr(){
	const char * const arr[4]= { "Clubs", "Diamonds", "Hearts", "Spades"}; //length = 5+1, 8+1, 6+1, 6+1.
	const string brr[4] = { "Clubs", "Diamonds", "Hearts", "Spades"};  //length = 5, 8, 6, 6.
	string text = "Hello";

	//header
	cout << right << setw(18) <<	"**array**"	<< setw(18) <<		"**output**"		<< endl << endl;

	cout << "���a�}\n";
	cout <<			 setw(18) <<	arr			<< setw(18) <<		brr					<< endl << endl;

	//(�ѩ�string/char type, compiler�۰ʧ�᭱��print�X��, �Ԩ��W��line 326��Note)
	cout << "���Ĥ@�Ӧa�}����,����n�S�O�@��pointer\n";
	cout <<			 setw(18) <<	*arr		<< setw(18) <<		*brr				<< endl;
	cout <<			 setw(18) <<	arr[0]		<< setw(18) <<		brr[0]				<< endl << endl;

	cout << "���Ĥ@�Ӧa�}�O��pointer, �A����Ĥ@�Ӧa�}����\n";
	cout <<			 setw(18) <<	arr[0][0]	<< setw(18) <<	(brr[0].c_str())[0]		<< endl;
	cout <<			 setw(18) <<	*arr[0]		<< setw(18) <<	*brr[0].c_str()			<< endl;
	cout <<			 setw(18) <<	**arr		<< setw(18) <<	*((*brr).c_str())		<< endl << endl;

	cout << "���W����ӨҤl�U�@�Ӱ����\n";
	cout <<			 setw(18) <<	(arr[0]+1)	<< setw(18) <<	brr[0].c_str()+1		<< endl;
	cout <<			 setw(18) <<	*(arr[0]+1) << setw(18) <<	*(brr[0].c_str()+1)		<< endl << endl;


	cout << "Size of arr and brr\n";
	//�|�ӫ��� �C��8 bytes, �G�@�@32 bytes				//�|��string �C��data of type string ���O size = 24, �@�@96 bytes.
	cout <<			 setw(18) << sizeof (arr)   << setw(18) <<	sizeof (brr)			<< endl;

	cout << "Sizeof for each element\n";
	//�H�U�|��, �C�ӳ��O���� 8 bytes, �P���A�L��.			// �H�U�|��, �C�ӳ��Ostring type size = 24
	cout <<			 setw(18) << sizeof (*arr)		<< setw(18) <<	sizeof (*brr)		<< endl;
	cout <<			 setw(18) << sizeof ((*arr)+1)  << setw(18) <<	sizeof (*(brr+1))	<< endl;
	cout <<			 setw(18) << sizeof ((*arr)+2)  << setw(18) <<	sizeof (*(brr+2))	<< endl;
	cout <<			 setw(18) << sizeof ((*arr)+3)  << setw(18) <<	sizeof (*(brr+3))	<< endl << endl;

	//�Ĥ@�ӫ��Ъ��Ĥ@�Ӧ�m���Ȫ�size = 1 bytes �P���A����, �o�̬Ochar.	//�Ĥ@��string���Ȫ�size = 5
	cout <<			 setw(18) << sizeof (**arr)	  << setw(18) <<	brr[0].size()		<< endl << endl;
	//�Ĥ@�ӫ��ЩҦs���Ȫ����׬� 5+1 = 6, ���O�O: 'C', 'l', 'u', 'b', 's', '\0'. ���M���ٵL�k�Q��ε{���X�g�X�Ӣߢ�
}

