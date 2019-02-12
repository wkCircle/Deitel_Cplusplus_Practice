//Recursive main
#include <iostream>
using namespace std;
int main(void){
	static int count=1;
	++count;
	cout << count << endl;
	main();

	return 0;
}
