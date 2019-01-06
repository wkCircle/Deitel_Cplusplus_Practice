#include "squareOfAsterisks.hpp"

void Method1(){
	int sideSize=1;
	int count=1;
	string starStr="";
	string interstarStr="*";

	cout << "Input a size of the hollow suqare.(or 0 to quit)\n";
	cin >> sideSize;
	if (sideSize == 0)
		return;

	//Head
	while (count <= sideSize){
		starStr = starStr + '*';
		count++;
	}
	cout << starStr << endl;

	//Body and Tail
	//case for sideSize <= 2
	if (sideSize == 1)
		return;
	else if (sideSize == 2){
		cout << starStr << endl;
		return;
	}
	//case for sideSize >2
	count=1;
	while (count <= sideSize-2){
		interstarStr = interstarStr + ' ' ;
		count++;
	}
	interstarStr = interstarStr + '*' ;
	count=1;
	while (count <= sideSize-2){
		cout << interstarStr << endl;
		count++;
	}

	cout << starStr << endl;
}
void Method2(){
	int sideSize=1;
	cout << "Input a size of the hollow suqare.(or 0 to quit)\n";
	cin >> sideSize;
	if (sideSize == 0)
		return;

	for (int row=1; row<=sideSize; row++) {
		for(int column=1; column<=sideSize; column++) {
			if ( row==1 || row==sideSize || column==1 || column==sideSize)
				cout << '*';
			else
				cout << ' ';
		}
		cout << endl;
	}

}
void squareOfAsterisks(){
		Method1();
		Method2();
}

