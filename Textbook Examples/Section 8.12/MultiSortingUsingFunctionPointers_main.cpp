//Section 8.12 Multipurpose sorting program using function pointers.
//Pointers to functions can be passed to functions, returned from functions, stored in arrays, assigned to other function pointers and used to call the underlying function.

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

void MultiSortingUsingFunctionPointers();
void selectionSort( int [], const int, bool (*)( int, int ) );
/**<Last paramater of the above is the form of a function pointer that requires two int arguments and returns data in bool type.
	The parentheses of (*) are required to implement it's a function pointer,
	Otherwise, it would become bool *(int, int), which means a function with 2 int inputs returns a pointer to bool tyape data.>**/
void swap( int * const, int * const );
bool ascending( int, int ); // implements ascending order
bool descending( int, int ); // implements descending order


int main(){
    MultiSortingUsingFunctionPointers();
}
void MultiSortingUsingFunctionPointers(){

	const int arraySize = 10;
	int order; // 1 = ascending, 2 = descending
	int counter; // array index
	int a[ arraySize ] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };

	cout << "Enter 1 to sort in ascending order,\n" << "Enter 2 to sort in descending order: ";
	cin >> order;

	// output original array
	cout << "\nData items in original order\n";
	for ( counter = 0; counter < arraySize; counter++ )
		cout << setw( 4 ) << a[ counter ];


	//sort array in ascending order;
	//pass function ascending as an argument to specify ascending sorting order
	if (order==1){
		selectionSort(a, arraySize, ascending); //Thus, ascending is passed and compare = ascending.
		cout << "\nData items in ascending order\n";
	}
	// sort array in descending order; pass function descending
	// as an argument to specify descending sorting order
	else {
		selectionSort( a, arraySize, descending ); //Regard 'descending' as a pointer to function.
		cout << "\nData items in descending order\n";
	}// end else part of if...else

	// output sorted array
	for ( counter = 0; counter < arraySize; counter++ )
		cout << setw( 4 ) << a[ counter ];

	cout << endl;
}





// multipurpose selection sort; the parameter compare is a pointer to the comparison function that determines the sorting order
void selectionSort( int work[], const int size, bool (*compare)( int, int ) ){ //(*compare): () is also required.
	int smallestOrLargest; // index of smallest (or largest) element

	// loop over size - 1 elements
	for ( int i = 0; i < size - 1; i++ ){
		smallestOrLargest = i; // first index of remaining vector

		// loop to find index of smallest (or largest) element
		for ( int index = i + 1; index < size; index++ )
			if ( !(*compare)( work[ smallestOrLargest ], work[ index ] ) )
				smallestOrLargest = index;
		/**<Alternatively, if (   ! (  compare( work[smallestOrLargest], work [index] ) )   ), i.e., without the '*', which means to execute the function pointed by the pointer 'compare'. This works also well, but we prefer the original method since, in the second method, it appears 'compare' is an actual function name, which frequently confuses users, who want to search it but it turns out to be in vain. >**/
		/**<Just as a pointer to a variable is dereferenced to access the value of the variable, a pointer to a function is dereferenced to execute the function>**/
		/**<For the aobve codes, the parentheses around *compare are necessary¡Xif they were left out, the * operator would attempt to dereference the value returned from the function call. >**/

		swap( &work[ smallestOrLargest ], &work[ i ] );
	}//end for
}
// swap values at memory locations to which
// element1Ptr and element2Ptr point
void swap( int * const element1Ptr, int * const element2Ptr ){
	int hold = *element1Ptr;
	*element1Ptr = *element2Ptr;
	*element2Ptr = hold;
} // end function swap
// determine whether element a is less than
// element b for an ascending order sort
bool ascending( int a, int b ){
	return a < b; // returns true if a is less than b
} // end function ascending
// determine whether element a is greater than
// element b for a descending order sort
bool descending( int a, int b ){
	return a > b; // returns true if a is greater than b
} // end function descending
