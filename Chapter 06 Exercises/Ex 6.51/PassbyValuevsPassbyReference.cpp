#include "PassbyValuevsPassbyReference.hpp"

int tripleByValue(int x){
	x *= 3;
	return x;
}
int tripleByReference( int &x){
	x *= 3;
	return x;
}
void PassbyValuevsPassbyReference(){
	int count = 1;

	count =1;
	cout << "Original var \"count\" is: " << count << "\tafter tripleByValue: " << tripleByValue(count) <<
	"\tThen the var becomes: " << count  << endl;

	count =1;
	/**< since cout operator deals with count from right to left in the code, so it prints(3,3,1), which is wrong*/
	//cout << "Original var \"count\" is: " << count << "\tafter tripleByReference: " << tripleByReference(count) <<
	//"\tThen the var becomes: " << count  << endl;
	/**< instead, use the following code, which prints (1,3,3)*/
	cout << "Original var \"count\" is: " << count;
	cout << "\tafter tripleByReference: " << tripleByReference(count);
	cout << "\tThen the var becomes: " << count  << endl;
}
