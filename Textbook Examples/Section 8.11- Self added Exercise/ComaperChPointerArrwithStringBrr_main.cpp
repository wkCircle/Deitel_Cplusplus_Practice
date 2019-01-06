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

	cout << "取地址\n";
	cout <<			 setw(18) <<	arr			<< setw(18) <<		brr					<< endl << endl;

	//(由於string/char type, compiler自動把後面都print出來, 詳見上面line 326的Note)
	cout << "取第一個地址的值,但剛好又是一個pointer\n";
	cout <<			 setw(18) <<	*arr		<< setw(18) <<		*brr				<< endl;
	cout <<			 setw(18) <<	arr[0]		<< setw(18) <<		brr[0]				<< endl << endl;

	cout << "取第一個地址是個pointer, 再取其第一個地址的值\n";
	cout <<			 setw(18) <<	arr[0][0]	<< setw(18) <<	(brr[0].c_str())[0]		<< endl;
	cout <<			 setw(18) <<	*arr[0]		<< setw(18) <<	*brr[0].c_str()			<< endl;
	cout <<			 setw(18) <<	**arr		<< setw(18) <<	*((*brr).c_str())		<< endl << endl;

	cout << "取上面兩個例子各一個做比較\n";
	cout <<			 setw(18) <<	(arr[0]+1)	<< setw(18) <<	brr[0].c_str()+1		<< endl;
	cout <<			 setw(18) <<	*(arr[0]+1) << setw(18) <<	*(brr[0].c_str()+1)		<< endl << endl;


	cout << "Size of arr and brr\n";
	//四個指標 每個8 bytes, 故一共32 bytes				//四個string 每個data of type string 都是 size = 24, 一共96 bytes.
	cout <<			 setw(18) << sizeof (arr)   << setw(18) <<	sizeof (brr)			<< endl;

	cout << "Sizeof for each element\n";
	//以下四個, 每個都是指標 8 bytes, 與型態無關.			// 以下四個, 每個都是string type size = 24
	cout <<			 setw(18) << sizeof (*arr)		<< setw(18) <<	sizeof (*brr)		<< endl;
	cout <<			 setw(18) << sizeof ((*arr)+1)  << setw(18) <<	sizeof (*(brr+1))	<< endl;
	cout <<			 setw(18) << sizeof ((*arr)+2)  << setw(18) <<	sizeof (*(brr+2))	<< endl;
	cout <<			 setw(18) << sizeof ((*arr)+3)  << setw(18) <<	sizeof (*(brr+3))	<< endl << endl;

	//第一個指標的第一個位置的值的size = 1 bytes 與型態有關, 這裡是char.	//第一個string的值的size = 5
	cout <<			 setw(18) << sizeof (**arr)	  << setw(18) <<	brr[0].size()		<< endl << endl;
	//第一個指標所存的值的長度為 5+1 = 6, 分別是: 'C', 'l', 'u', 'b', 's', '\0'. 雖然我還無法想到用程式碼寫出來ＱＱ
}

