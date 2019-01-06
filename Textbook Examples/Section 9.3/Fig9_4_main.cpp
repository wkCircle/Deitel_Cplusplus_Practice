// Fig. 9.4: fig09_04.cpp
// Demonstrating the class member access operators . and ->
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

class Count{ // class Count definition
public: // public data is dangerous
	void setX( int value ){ // sets the value of private data member x
		x = value;
	}
	void print(){ // prints the value of private data member x
		cout << x << endl;
	}
private:
	int x;
}; // end class Count

int main(){

	Count counter; // create counter object
	Count *counterPtr = &counter; // create pointer to counter
	Count &counterRef = counter; // create reference to counter

	cout << "Set x to 1 and print using the object's name: ";
	counter.setX( 1 ); // set data member x to 1
	counter.print(); // call member function print

	cout << "Set x to 2 and print using a reference to an object: ";
	counterRef.setX( 2 ); // set data member x to 2
	counterRef.print(); // call member function print

	cout << "Set x to 3 and print using a pointer to an object: ";
	counterPtr->setX( 3 ); // set data member x to 3
	counterPtr->print(); // call member function print

}

/* ��3�ؤ�k�i�H�I�s class member function
 1. �ŧi class object. �ϥ� (.) dot member selection operator: obj.func(para1, ...)
 2. �ŧi �Y��object �� reference, �z�L�� reference �ӥi�H�ϥ�function, �P�ˤ]�O�ϥ� (.) dot member selection operator
 3. �ŧi �Y��object �� pointer, �z�L�� pointer �ӥi�H�ϥ�function, �n�� (->) arrow member selection operator
 */

