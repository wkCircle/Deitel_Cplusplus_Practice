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

int main(){
    int x, y;
	// ptr is a constant pointer to an integer that can
	// be modified through ptr, but ptr always points to the
	// same memory location.
	int * const ptr = &x; // "const pointer" must be initialized
	*ptr = 7; // allowed: *ptr is not const
	//	ptr = &y; // error: ptr is const; cannot assign to it a new address

	//I additionally add following code which doesn't exit in textbook.
	int const *pptr = &x;
	//	*pptr = 7;
	pptr = &y;

	//Hence,
	//ptr is a const pointer pointing to an int data;
	//pptr is a pointer pointing to a const int data.
	//順序有差 * 放在const之前或之後有差！ 不過 * 一定是放在 int 之後。
}
