//
//  TextBookExamples.cpp
//  20170331 TextBookExamples
//
//  Created by ntueconRA on 2017/5/15.
//  Copyright © 2017年 Kai. All rights reserved.
//

#include "TextbookExamples.hpp"
#include "Proxy.hpp"
using namespace std;

//Sec 7.7 Searching Arrays with Linear Search
int linearSearch( const int [], int, int); //function prototype
void Egg::SearchingArraysWithLinearSearch(){
	//linear search compares each element of an array with a search key.

	const int arraySize = 100;
	int a[ arraySize ];
	int searchKey; // value to locate in array a

	for(int i=0; i < arraySize; i++)
		a[ i ] = 2 * i; // create some data

	cout << "Enter integer search key: ";
	cin >> searchKey;

	int element = linearSearch( a, searchKey, arraySize );

	// display results
	if(element!=-1)
		cout << "Found value in element " << element << endl;
	else
		cout << "Value not found" << endl;
}
int linearSearch( const int array[], int key, int sizeOfArray ) {
	for ( int j = 0; j < sizeOfArray; j++ )
		if(array[j] == key)//iffound, return j; // return location of key
			return j;

	return -1; // key not found
}

//Sec 7.8 Searching Arrays with Insertion Sort
inline void insertionSort(int data[], const int arraySize){
	int insert; // temporary variable to hold element to insert

	// loop over the elements of the array
	for ( int next = 1; next < arraySize; next++ )
	{
		insert = data[ next ]; // store the value in the current element
		int moveItem = next; // initialize location to place element
		// search for the location in which to put the current element
		while ( ( moveItem > 0 ) && ( data[ moveItem - 1 ] > insert ) )
		{
			// shift element one slot to the right
			data[ moveItem ] = data[ moveItem - 1 ];
			moveItem--;
		} // end while
		data[ moveItem ] = insert; // place inserted element into the array
	} // end for
}
void Egg::SearchingArraysWithInsertionSort(){

	const int arraySize = 10; // size of array a
	int data[ arraySize ] = { 34, 56, 4, 10, 77, 51, 93, 30, 5, 52 };

	cout << "Unsorted array:\n";
	// output original array
	for ( int i = 0; i < arraySize; i++ )
		cout << setw( 4 ) << data[ i ];

	cout << "\nSorted array:\n";
	// output sorted array
	for ( int i = 0; i < arraySize; i++ )
		cout << setw( 4 ) << data[ i ];

	cout << endl;
}

#include <vector> // vector<type>, size(), at()
//Sec 7.11 Introduction to C++ Standard Library Class Template 'vector.'
//Standard class template vector is defined in header <vector> and belongs to namespace std
void outputVector( const vector< int > &); // display the vector
void inputVector( vector <int> & ); // input values into the vector
void Egg::introToVector(){

	vector<int> integers1(7); //7-element <int>
	vector<int> integers2(10); // 10-element <int>

	// print integers1 and integers2 sizes and contents
	cout << "Size of vector integers1 is " << integers1.size() << "\nvector after initialization:" << endl;
	outputVector( integers1 );

	cout << "\nSize of vector integers2 is " << integers2.size() << "\nvector after initialization:" << endl;
	outputVector( integers2 );

	// input and print integers1 and integers2
	cout << "\nEnter 17 integers:" << endl;
	inputVector( integers1 );
	inputVector( integers2 );

	cout << "\nAfter input, the vectors contain:\n"	<< "integers1:" << endl;
	outputVector( integers1 );

	cout << "integers2:" << endl;
	outputVector( integers2 );

	// use inequality (!=) operator with vector objects
	cout << "\nEvaluating: integers1 != integers2" << endl;

	if ( integers1 != integers2 )
		cout << "integers1 and integers2 are not equal" << endl;

	// Now create integers3 using integers1 as an initializer; print size and contents
	vector< int > integers3( integers1 ); // copy constructor

	cout << "\nSize of vector integers3 is " << integers3.size() << "\nvector after initialization:" << endl;
	outputVector( integers3 );

	// use overloaded assignment (=) operator
	cout << "\nAssigning integers2 to integers1:" << endl;
	integers1 = integers2; // assign integers2 to integers1

	cout << "integers1:" << endl;
	outputVector( integers1 );
	cout << "integers2:" << endl;
	outputVector( integers2 );

	// use equality (==) operator with vector objects
	cout << "\nEvaluating: integers1 == integers2" << endl;

	if ( integers1 == integers2 )
		cout << "integers1 and integers2 are equal" << endl;

	// use square brackets to creat rvalue
	cout << "\nintegers1[5] is " << integers1[ 5 ];

	// use square brackets to create lvalue
	cout << "\n\nAssigning 1000 to integers1[5]" << endl;
	integers1[ 5 ] = 1000;
	cout << "integers1:" << endl;
	outputVector( integers1 );

	// attempt to use out-of-range subscript
	cout << "\nAttempt to assign 1000 to integers1.at( 15 )" << endl;

	////Error
	integers1.at( 15 ) = 1000; // ERROR: out of range
	////Error
	//Error message: libc++abi.dylib: terminating with uncaught exception of type std::out_of_range: vector

}
void outputVector( const vector<int> &array ) {
	size_t i; // declare control variable //it represents unsigned int in many compilers.

	for ( i = 0; i < array.size(); i++ )
	{
		cout << setw( 12 ) << array[ i ];
		if ( ( i + 1 ) % 4 == 0 ) // 4 numbers per row of output
			cout << endl;
	}

	if ( i % 4 != 0 )
		cout << endl;

} // end function outputVector
void inputVector( vector<int> &array ){
	for ( size_t i = 0; i < array.size(); i++ )
		cin >> array[ i ];

} // end function inputVector
/*
 Conclusions:
 1. vector <int>: type specifier as a form of vector (one dimension)
 2. vec.size(): size() returns the number of elements in that object(here vec) as type size_t.
 3. size_t: unsigned int
 4. assign/print values to/from a vector: use [] (do not check borders) or vec.at() (check borders)
 5. vectors can be compared with ones another, assigned value: !=, ==, =.
 e.g. vector<int > vec(15, 0): reserve 15 positions for the vector vec and assign 0 to all positions.
 e.g. vector<int > vec(v2.begin(), v2.end()): use vector v2 to initialize vec, i.e., copy v2 to vec. (same as vec = v2)
 e.g. vector<int > vec(arr, arr + sizeof(arr)/sizeof(type_of_arr) ): assine each entry value of arr to vec.
 6. An array name is already a pointer. And the name of the arrayis the starting location in memory of the array.

 7. vector can be initialized by another existing vector (In contrast, array can only be initialzied by const var.)
 */
//******************************************End of Chapter 7*****************************************
//*****************************************Begin of Chapter 8*****************************************
//Sec 8.3 Pointer Operators
void Egg::PointerOperators(){

	int a; // a is an integer
	int *aPtr; // aPtr is an int * which is a pointer to an integer

	a = 7; // assigned 7 to a
	aPtr = &a; // assign the address of a to aPtr

	cout << "The address of a is " << &a
	<< "\nThe value of aPtr is " <<  aPtr;
	cout << "\n\nThe value of a is " << a
	<< "\nThe value of *aPtr is " << *aPtr;
	cout << "\n\nShowing that * and & are inverses of "
	<< "each other.\n&*aPtr = " << &*aPtr
	<< "\n*&aPtr = " << *&aPtr << endl;
}
// & is called address operator (note that e.g. int &c is called pass-by-reference with reference arguments, in which & is different from address operator '&' )
// * is called dereferencing operator or indirection operator (also different from int *var, which declare a variable is of type int and is a pointer.)
// Though C++ allows pass-by-reference to a called function, C doesn't have this extended bility.
/**< An array name is already a pointer. And the name of the arrayis the starting location in memory of the array.
 Thus, the name of an array, say ArrayName, is equivalent to &ArrayName[0] >**/

//Fig8.7 cube volume By Reference with pointer arguments.
void cubeByReference( int * ); // prototype
void Egg::Fig8_7() {
	int number = 5;
	cout << "The original value of number is " << number;
	cubeByReference( &number ); // pass number address to cubeByReference
	cout << "\nThe new value of number is " << number << endl;
}//endmain
void cubeByReference( int *nPtr ) //use a pointer nPtr to store &number (address)
{
	*nPtr = *nPtr * *nPtr * *nPtr; // cube *nPtr: '*' is dereferencing operator.
} // end function cubeByReference
/**< a function receiving an address as an argument must define a pointer parameter to receive the address.>**/

//Fig 8.10 Nonconstant Pointer to Constant Data
void f( const int * );
void Egg::Fig8_10(){
	int y;
	f( &y ); // f attempts illegal modification
}//endmain
// xPtr cannot modify the value of constant variable to which it points
void f( const int *xPtr ){
	//*xPtr = 100; // error: cannot modify a const object
} // end function f

//Fig 8.11 Constant Pointer to Nonconstant Data
void Egg::Fig8_11(){
	int x, y;
	// ptr is a constant pointer to an integer that can
	// be modified through ptr, but ptr always points to the
	// same memory location.
	int * const ptr = &x; // "const pointer" must be initialized
	*ptr = 7; // allowed: *ptr is not const
	//	ptr = &y; // error: ptr is const; cannot assign to it a new address

	//下面是自己新增的
	int const *pptr = &x;
	//	*pptr = 7;
	pptr = &y;

	//故可知
	//ptr is a const pointer pointing to an int data;
	//pptr is a pointer pointing to a const int data.
	//順序有差 * 放在const之前或之後有差！ 不過 * 一定是放在 int 之後。
}

//Fig 8.12 Constant Pointer to Constant Data
void Egg::Fig8_12(){

	int x = 5, y;

	// ptr is a constant pointer to a constant integer.
	// ptr always points to the same location; the integer
	// at that location cannot be modified.
	const int *const ptr = &x;

	cout << *ptr << endl;
	//	*ptr = 7; // error: *ptr is const; cannot assign new value
	//	ptr = &y; // error: ptr is const; cannot assign new address


}
size_t getSize( double * ); // prototype


//Fig 8.14
void Egg::Fig8_14(){

	double array[ 20 ]; // 20 doubles; occupies 160 bytes on our system
	cout << "The number of bytes in the array is " << sizeof( array );
	cout << "\nThe number of bytes returned by getSize is " << getSize( array ) << endl;

	array[0] = *( array +3);
}
//return return size of ptr
size_t getSize( double *ptr ){
	return sizeof( ptr );
} // end function getSize
/**<sizeof (arr) = 160, returns the size of arr in bytes.
	sizeof (ptr) = 8, where *ptr = arr , returns the size of pointer in bytes
 (也就是指標本身配置記憶體的大小, 跟系統有關與任何型態無關), not the size of arr in bytes.
	sizeof (*ptr) = 4, returns the size of the type of arr's 1st element, i.e. arr[0]
	PS1. sizeof 後面的括號() 只有在參數是data type時才必要, 否則都可以不寫. E.g., sizeof( int ), sizeof arrayName; >**/
//	sizeof is a compile-time unary operator, not an execution-time operator, using sizeof does not negatively impact execution performance!!!



//Fig8.18 & Section 8.9 Relationship Between Pointers and Arrays
void Egg::RelationshipBetweenPointersandArrays(){
	int b[] = { 10, 20, 30, 40 }; // create 4-element array b
	int *bPtr = b; // set bPtr to point to array b

	// output array b using array subscript notation
	cout << "Array b printed with:\n\nArray subscript notation\n";
	for(int i=0; i < 4; i++)
		cout << "b[" << i << "] = " << b[ i ] << '\n';

	// output array b using the array name and pointer/offset notation
	cout << "\nPointer/offset notation where " << "the pointer is the array name\n";
	for ( int offset1 = 0; offset1 < 4; offset1++ )
		cout << "*(b + " << offset1 << ") = " << *( b + offset1 ) << '\n';

	// output array b using bPtr and array subscript notation
	cout << "\nPointer subscript notation\n";
	for(int j=0; j < 4; j++)
		cout << "bPtr[" << j << "] = " << bPtr[ j ] << '\n';

	// output array b using bPtr and pointer/offset notation
	cout << "\nPointer/offset notation\n";
	for ( int offset2 = 0; offset2 < 4; offset2++ )
		cout << "*(bPtr + " << offset2 << ") = " << *( bPtr + offset2 ) << '\n';
}
/**< sum up here, you can use
	arr[n], ptr[n]			(array subscript notation, pointer subscript notation)
 or *(arr+n), *(ptr+n):		(arrayname pointer offset notation, pointer offset notation)
 to take the value of an array's position n. >**/
/**<Note: cin/cout assume that character arrays should be processed as strings terminated by null characters;
	cin/cout do not provide similar input and output processing capabilities for other array types.>**/




//Self Exercises (cf. Section 8.11 page 373)
//Compare const char * arr[4] with string brr[4], both of which have smae values.
void Self::ComaperChPointerArrwithStringBrr(){
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




//Section 8.12 Multipurpose sorting program using function pointers.
//Pointers to functions can be passed to functions, returned from functions, stored in arrays, assigned to other function pointers and used to call the underlying function.
void selectionSort( int [], const int, bool (*)( int, int ) );
/**<Last paramater of the above is the form of a function pointer that requires two int arguments and returns data in bool type.
	The parentheses of (*) are required to implement it's a function pointer,
	Otherwise, it would become bool *(int, int), which means a function with 2 int inputs returns a pointer to bool tyape data.>**/
void swap( int * const, int * const );
bool ascending( int, int ); // implements ascending order
bool descending( int, int ); // implements descending order
void Egg::MultiSortingUsingFunctionPointers(){

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
		/**<For the aobve codes, the parentheses around *compare are necessary—if they were left out, the * operator would attempt to dereference the value returned from the function call. >**/

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
//end of Secion 8.12
//*****************************************end of Chapter 8*****************************************

//*****************************************Begin of Chapter 9*****************************************
// Fig. 9.2
// Time constructor initializes each data member to zero.
// Ensures all Time objects start in a consistent state.
Time::Time(){
	hour = minute = second = 0;
}
// set new Time value using universal time; ensure that the data remains consistent by setting invalid values to zero
void Time::setTime( int h, int m, int s ){
	//validate hour, minute, and second.
	hour   = (h >= 0 && h < 24) ? h:0;
	minute = (m >= 0 && m < 60) ? m:0;
	second = (s >= 0 && s < 60) ? s:0;
}
void Time::printUniversal(){// print Time in universal-time format (HH:MM:SS)
	cout << setfill('0') << setw(2) << hour << ":" << setw( 2 ) << minute << ":" << setw( 2 ) << second;
}
void Time::printStandard(){// print Time in standard-time format (HH:MM:SS AM or PM)
	cout << ( ( hour == 0 || hour == 12 ) ? 12 : hour % 12 ) << ":" << setfill('0') << setw(2) << minute
	<< ":" << setw(2) << second << (  hour < 12 ?  " AM" : " PM" );
}
//....................................NOTE...............................................
//Once the class time has been defined,
//it can be used as a type in object, array, pointer, and reference declarations as follows:
//Time sunset; // object of type Time
//Time arrayOfTimes[ 5 ]; // array of 5 Time objects
//Time &dinnerTime = sunset; // reference to a Time object
//Time *timePtr = &dinnerTime; // pointer to a Time object
//....................................NOTE...............................................

// Fig. 9.3: fig09_03.cpp
void Time::Fig9_3main(){

	Time t; // instantiate object t of class Time

	// output Time object t's initial values
	cout << "The initial universal time is ";
	t.printUniversal(); // 00:00:00
	cout << "\nThe initial standard time is ";
	t.printStandard(); // 12:00:00 AM


	t.setTime( 13, 27, 6 ); // change time
	// output Time object t's new values
	cout << "\n\nUniversal time after setTime is ";
	t.printUniversal(); // 13:27:06
	cout << "\nStandard time after setTime is ";
	t.printStandard(); // 1:27:06 PM


	t.setTime( 99, 99, 99 ); // attempt invalid settings
	// output t's values after specifying invalid values
	cout << "\n\nAfter attempting invalid settings:"
	<< "\nUniversal time: ";
	t.printUniversal(); // 00:00:00
	cout << "\nStandard time: ";
	t.printStandard(); // 12:00:00 AM

	cout << endl;
}

// Fig. 9.4: fig09_04.cpp
// Demonstrating the class member access operators . and ->
class Count{ // class Count definition
public: // public data is dangerous
	void Fig9_4main(); //main function
	// sets the value of private data member x
	void setX( int value ){
		x = value;
	}
	// prints the value of private data member x
	void print(){
		cout << x << endl;
	}
private:
	int x;
}; // end class Count

void Count::Fig9_4main(){

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
/* 有3種方法可以呼叫 class member function
 1. 宣告 class object. 使用 (.) dot member selection operator: obj.func(para1, ...)
 2. 宣告 某個object 的 reference, 透過該 reference 而可以使用function, 同樣也是使用 (.) dot member selection operator
 3. 宣告 某個object 的 pointer, 透過該 pointer 而可以使用function, 要用 (->) arrow member selection operator
 */


// Fig. 9.6: SalesPerson.cpp
// SalesPerson class member-function definitions.
//#include "SalesPerson.h" // include SalesPerson class definition
// initialize elements of array sales to 0.0
SalesPerson::SalesPerson(){
	for ( int i = 0; i < monthsPerYear; i++ )
		sales[ i ] = 0.0;
} // end SalesPerson constructor
// get 12 sales figures from the user at the keyboard
void SalesPerson::getSalesFromUser(){
	double salesFigure;
	for ( int i = 1; i <= monthsPerYear; i++ ){
		cout << "Enter sales amount for month " << i << ": ";
		cin >> salesFigure;
		setSales( i, salesFigure );
	}
}//end function getSalesFromUser
// set one of the 12 monthly sales figures; function subtracts one from month value for proper subscript in sales array.
void SalesPerson::setSales( int month, double amount ){
	// test for valid month and amount values
	if ( month >= 1 && month <= monthsPerYear && amount > 0)
		sales[ month - 1 ] = amount; // adjust for subscripts 0-11
	else // invalid month or amount value
		cout << "Invalid month or sales figure" << endl;
} // end function setSales
// print total annual sales (with the help of utility function)
void SalesPerson::printAnnualSales(){
	cout << setprecision( 2 ) << fixed << "\nThe total annual sales are: $"
	<< totalAnnualSales() << endl; // call utility function
} // end function printAnnualSales
// private utility function to total annual sales
double SalesPerson::totalAnnualSales(){
	double total = 0.0; // initialize total

	for ( int i = 0; i < monthsPerYear; i++ ) // summarize sales results
		total += sales[ i ]; // add month i sales to total

	return total;
}// end function totalAnnualSales
/**<小結: private function 的功能是輔助 public function, 且client用不到. private function = utility function = helper function. >**/


// Fig. 9.9: Time.cpp
// Member-function definitions for class Time.
//#include "Time.h" // include definition of class Time from Time.h
// Time constructor initializes each data member to zero;
// ensures that Time objects start in a consistent state
TimeFig9_8::TimeFig9_8( int hr, int min, int sec ){
	setTime( hr, min, sec ); // validate and set time
} // end Time constructor
// set new Time value using universal time; ensure that the data remains consistent by setting invalid values to zero
void TimeFig9_8::setTime( int h, int m, int s ){
	setHour( h ); // set private field hour
	setMinute( m ); // set private field minute
	setSecond( s ); // set private field second
} // end function setTime
void TimeFig9_8::setHour( int h ){
	hour=(h>=0&&h< 24)?h:0;//validatehour
}// end function setHour
void TimeFig9_8::setMinute( int m ){
	minute = (m >= 0 && m < 60)? m : 0;//validateminute
} // end function setMinute
void TimeFig9_8::setSecond( int s ){
	second = (s >= 0 && s < 60)? s : 0;//validateminute
} // end function setMinute
int TimeFig9_8::getHour(){
	return hour;
} // end function getHour
int TimeFig9_8::getMinute(){
	return minute;
} // end function getMinute
int TimeFig9_8::getSecond(){
	return second;
} // end function getSecond
// print Time in universal-time format (HH:MM:SS)
void TimeFig9_8::printUniversal(){
	cout << setfill( '0' ) << setw( 2 ) << getHour() << ":" << setw( 2 )
	<< getMinute() << ":" << setw( 2 ) << getSecond();
} // end function printUniversal
// print Time in standard-time format (HH:MM:SS AM or PM)
void TimeFig9_8::printStandard(){
	cout << ( ( getHour() == 0 || getHour() == 12 ) ? 12 : getHour() % 12 )
	<< ":" << setfill( '0' ) << setw( 2 ) << getMinute()
	<< ":" << setw( 2 ) << getSecond() << ( hour < 12 ? " AM" : " PM" );
} // end function printStandard
// Fig. 9.10: fig09_10.cpp
// Demonstrating a default constructor for class Time.
//#include "Time.h" // include definition of class Time from Time.h
void TimeFig9_8::Fig9_8to9_10main(){
	TimeFig9_8 t1; // all arguments defaulted
	TimeFig9_8 t2( 2 ); // hour specified; minute and second defaulted
	TimeFig9_8 t3( 21, 34 ); // hour and minute specified; second defaulted
	TimeFig9_8 t4( 12, 25, 42 ); // hour, minute and second specified.
	TimeFig9_8 t5( 27, 74, 99 ); // all bad values specified

	cout << "Constructed with:\n\nt1: all arguments defaulted\n ";
	t1.printUniversal(); // 00:00:00
	cout << "\n ";
	t1.printStandard(); // 12:00:00 AM

	cout << "\n\nt2: hour specified; minute and second defaulted\n ";
	t2.printUniversal(); // 02:00:00
	cout << "\n ";
	t2.printStandard(); // 2:00:00 AM

	cout << "\n\nt3: hour and minute specified; second defaulted\n ";
	t3.printUniversal(); // 21:34:00
	cout << "\n ";
	t3.printStandard(); // 9:34:00 PM

	cout << "\n\nt4: hour, minute and second specified\n ";
	t4.printUniversal(); // 12:25:42
	cout << "\n ";
	t4.printStandard(); // 12:25:42 PM

	cout << "\n\nt5: all invalid values specified\n  ";
	t5.printUniversal(); // 00:00:00
	cout << "\n ";
	t5.printStandard(); // 12:00:00 AM
	cout << endl;
}




// Fig. 9.12: CreateAndDestroy.cpp
// CreateAndDestroy class member-function definitions.
//#include "CreateAndDestroy.h"// include CreateAndDestroy class definition
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
// Fig. 9.13: fig09_13.cpp
// Demonstrating the order in which constructors and destructors are called.
//#include "CreateAndDestroy.h" // include CreateAndDestroy class definition
void create( void ); // prototype
CreateAndDestroy first( 1, "(global before main)" ); // global object
void CreateAndDestroy::Fig9_11to9_13main(){

	cout << "\nMAIN FUNCTION: EXECUTION BEGINS" << endl;
	CreateAndDestroy second( 2, "(local automatic in main)" );
	static CreateAndDestroy third( 3, "(local static in main)" );

	create(); // call function to create objects

	cout << "\nMAIN FUNCTION: EXECUTION RESUMES" << endl;
	CreateAndDestroy fourth( 4, "(local automatic in main)" );
	cout << "\nMAIN FUNCTION: EXECUTION ENDS" << endl;
}//endmain
void create( void ){ // function to create objects
	cout << "\nCREATE FUNCTION: EXECUTION BEGINS" << endl;
	CreateAndDestroy fifth( 5, "(local automatic in create)" );
	static CreateAndDestroy sixth( 6, "(local static in create)" );
	CreateAndDestroy seventh( 7, "(local automatic in create)" );
	cout << "\nCREATE FUNCTION: EXECUTION ENDS" << endl;
} // end function create
/**<小結: 上面例子旨在說明 在不同的時候宣告 object1~7 時, constructor 被呼叫的先後順序, 同時也觀察destructor被呼叫的先後順序,
 1. 先被宣告的, 就會同時呼叫constructor.
 2. 如果是automatic, 當compiler執行完當前brakets{}之後, auto objects就會消滅, 此時較先宣告的會較晚被消滅, 而後宣告的先消滅(透過呼叫destructor)
 3. 一般來說, 消滅先後順序: local auto -> static -> global. >**/


// Fig. 9.15: Time.cpp
// Time class member-function definitions.
// constructor function to initialize private data; calls member function
// setTime to set variables; default values are 0 (see class definition)
Time9_14::Time9_14( int hr, int min, int sec ){
	setTime( hr, min, sec );
}
void Time9_14::setTime( int h, int m, int s ){
	hour = ( h >= 0 && h < 24 ) ? h : 0; // validate hour
	minute = ( m >= 0 && m < 60 ) ? m : 0; // validate minute
	second = ( s >= 0 && s < 60 ) ? s : 0; // validate second
}
int Time9_14::getHour(){
	return hour;
}
// POOR PRACTICE: Returning a reference to a private data member.
int &Time9_14::badSetHour( int hh ){
	hour = ( hh >= 0 && hh < 24 ) ? hh : 0;
	return hour; // DANGEROUS reference return
} // end function badSetHour
// Fig. 9.16: fig09_16.cpp
// Demonstrating a public member function that returns a reference to a private data member.
void Time9_14::Fig9_14to9_16main(){
	Time9_14 t; // create Time object

	// initialize hourRef with the reference returned by badSetHour
	int &hourRef = t.badSetHour( 20 ); // 20 is a valid hour

	cout << "Valid hour before modification: " << hourRef;
	hourRef = 30; // use hourRef to set invalid value in Time object t
	cout << "\nInvalid hour after modification: " << t.getHour();

	// Dangerous: Function call that returns a reference can be used as an lvalue!
	t.badSetHour( 12 ) = 74; // assign another invalid value to hour

	cout << "\n\n*************************************************\n"
	<< "POOR PROGRAMMING PRACTICE!!!!!!!!\n"
	<< "t.badSetHour( 12 ) as an lvalue, invalid hour: "
	<< t.getHour()
	<< "\n*************************************************" << endl;
}





// Fig. 9.18: Date.cpp
// Date class member-function definitions.
//#include "Date.h" // include definition of class Date from Date.h
// Date constructor (should do range checking)
Date9_17::Date9_17( int m, int d, int y ){
	month = m;
	day = d;
	year = y;
}
void Date9_17::print(){// print Date in the format mm/dd/yyyy
	cout << month << '/' << day << '/' << year;
}
void Date9_17::Fig9_17to9_19main(){
	Date9_17 date1( 7, 4, 2004 );
	Date9_17 date2; //date2 defaults to 1/1/2000

	cout << "date1 = ";
	date1.print();

	cout << "\ndate2 = ";
	date2.print();

	//********************KEY!*********************
	date2 = date1; // default memberwise assignment
	//********************KEY!*********************

	cout << "\n\nAfter default memberwise assignment, date2 = ";
	date2.print();
	cout << endl;
}
/**<memberwise assignement operator (=): can assign an opject to another object of the same type.>**/









//Fig. 10.2: Time.cpp
//Time class member-function definitions.
//#include "Time.h" // include definition of class Time
// constructor function to initialize private data;
// calls member function setTime to set variables;
// default values are 0 (see class definition)
Time10_3::Time10_3( int hour, int minute, int second ){
	setTime( hour, minute, second );
}
void Time10_3::setTime( int hour, int minute, int second ){
	setHour( hour );
	setMinute( minute );
	setSecond( second );
}
void Time10_3::setHour( int h ){
	hour = ( h >= 0 && h < 24 ) ? h : 0; // validate hour
}
void Time10_3::setMinute( int m ){
	minute = ( m >= 0 && m < 60 ) ? m : 0; // validate minute
}
void Time10_3::setSecond( int s ){
	second = ( s >= 0 && s < 60 ) ? s : 0; // validate second
}
int Time10_3::getHour() const{// get functions should be const
	return hour;
}
int Time10_3::getMinute() const{
	return minute;
}
int Time10_3::getSecond() const{
	return second;
}

void Time10_3::printUniversal() const{
	cout << setfill( '0' ) << setw( 2 ) << hour << ":" << setw( 2 ) << minute << ":" << setw( 2 ) << second;
}
void Time10_3::printStandard(){ /**< note lack of const declaration >**/
	cout << ( ( hour == 0 || hour == 12 ) ? 12 : hour % 12 )
	<< ":" << setfill( '0' ) << setw( 2 ) << minute
	<< ":" << setw( 2 ) << second << ( hour < 12 ? " AM" : " PM" );
}
void Time10_3::Fig10_1to10_3main(){
	Time10_3 wakeUp( 6, 45, 0 ); // non-constant object
	const Time10_3 noon( 12, 0, 0 ); // constant object
	// OBJECT MEMBER FUNCTION
	wakeUp.setHour( 18 ); // non-const non-const
	//    noon.setHour( 12 ); // const non-const
	wakeUp.getHour(); // non-const const
	noon.getMinute(); // const const
	noon.printUniversal(); // const const
	//    noon.printStandard(); // const non-const
};
/**<小結:   1. constant obj to call a non-const function LEADS to an err.
 2. constant obj 只能使用 constant member function; non-constant obj 可以任意使用 member function.
 3. constant obj
 */

// Fig. 10.5: Increment.cpp +Fig. 10.6
// Member-function definitions for class Increment demonstrate using a member initializer to initialize a constant of a built-in data type.
//#include <iostream>
//#include "Increment.h" // include definition of class Increment
using namespace std;
// constructor: initializer for non-const member and for const member(necessary)
Increment::Increment( int c, int i ): count( c ), increment( i ){
	// empty body
}
void Increment::print() const{
	cout << "count = " << count << ", increment = " << increment << endl;
}
void Increment::Fig10_4to10_6main(){
	Increment value( 10, 5 );
	cout << "Before incrementing: ";
	value.print();
	for ( int j = 1; j <= 3; j++ ){
		value.addIncrement();
		cout << "After increment " << j << ": ";
		value.print();
	}
}



// Fig. 10.11: Date.cpp
// Date class member-function definitions.
//#include <iostream>
//#include "Date.h"
// constructor confirms proper value for month; calls utility function checkDay to confirm proper value for day
Date10_10::Date10_10( int mn, int dy, int yr ){
	if ( mn > 0 && mn <= monthsPerYear ) // validate the month
		month = mn;
	else{
		month = 1; // invalid month set to 1
		cout << "Invalid month (" << mn << ") set to 1.\n";
	}
	year = yr; // could validate yr
	day = checkDay( dy ); // validate the day

	// output Date object to show when its constructor is called
	cout << "Date object constructor for date ";
	print();
	cout << endl;
}
void Date10_10::print() const{
	cout << month << '/' << day << '/' << year;
}
Date10_10::~Date10_10(){
	cout << "Date object destructor for date ";
	print();
	cout << endl;
}
// utility function to confirm proper day value based on month and year; handles leap years, too
int Date10_10::checkDay( int testDay ) const {
	static const int daysPerMonth[ monthsPerYear + 1 ] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	// determine whether testDay is valid for specified month
	if ( testDay > 0 && testDay <= daysPerMonth[ month ] )
		return testDay;

	// February 29 check for leap year
	if ( month == 2 && testDay == 29 && ( year % 400 == 0 || ( year % 4 == 0 && year % 100 != 0 ) ) )
		return testDay;

	cout << "Invalid day (" << testDay << ") set to 1.\n";
	return 1; // leave object in consistent state if bad value
}

// Fig. 10.13: Employee.cpp
// Employee class member-function definitions.
//#include "Employee.h" // Employee class definition
//#include "Date.h" // Date class definition
// constructor uses member initializer list to pass initializer values to constructors of member objects
Employee::Employee( const string &first, const string &last, const Date10_10 &dateOfBirth, const Date10_10 &dateOfHire )
: firstName( first ), // initialize firstName
lastName( last ), // initialize lastName
birthDate( dateOfBirth ), // initialize birthDate
hireDate( dateOfHire ) // initialize hireDate
{
	// output Employee object to show when constructor is called
	cout << "Employee object constructor: " << firstName << ' ' << lastName << endl;
}
void Employee::print() const {
	cout << lastName << ", " << firstName << " Hired: ";
	hireDate.print();
	cout << " Birthday: ";
	birthDate.print();
	cout << endl;
}
Employee::~Employee() {
	cout << "Employee object destructor: " << lastName << ", " << firstName << endl;
}

/**<小結: (Fig10.10-Fig10.14)
 1. member initializer list 出現在constructor的參數之後，前面要加上 ":" 以便跟參數做區隔
 2. Composition技巧: 1個class可以在建構object時，參數裡面放來自其他class的object,
 則compiler會先建構參數內物件，最後才建立原始物件，(其實很自然，因為要建構該物件就必須先建構該物件的data members)。
 3. 如果把member initializer list的關於Date Obj 那兩行都註解掉，則compiler 先建構原始的Date10_10 object: birth, hire,
 然後進入Employee::Employee, 看到member initializer list沒有定義，則呼叫default constructor of class Date10_10以建構
 birthDate, hireDate, 這兩個都是class Employee底下的private data member object of type Date10_10, 預設值是1/1/1900,
 所以即使birth, hire 有寫在 定義manager物件的參數裡然後在employee constructor裡面換個代名詞叫做dateOfBirth, dateOfHire，
 但完全沒用到阿~~由此可知 member initializer幫助把 birth, hire 的值，傳遞到dateOfBirth, dateOfHire裏頭。
 4. 承3, 不用member initializer也可以，那就要在constructor body裡面assgin(例如用set function)*/



// Fig. 10.21: Employee.cpp
// Employee class member-function definitions.
//#include "Employee.h"

int Employee10_20::count = 0; /**< cannot include keyword static */
// define static member function that returns number of Employee objects instantiated (declared static in Employee.h)
int Employee10_20::getCount(){
	return count;
}
// constructor initializes non-static data members and increments static data member count
Employee10_20::Employee10_20( const string &first, const string &last )
: firstName( first ),
lastName( last ) {
	++count; // increment static count of employees
	cout << "Employee constructor for " << firstName
	<< ' ' << lastName << " called." << endl;
}
Employee10_20::~Employee10_20(){
	cout << "~Employee10_20() called for " << firstName << ' ' << lastName << endl;
	--count; // decrement static count of employees
}
string Employee10_20::getFirstName() const {
	return firstName;
}
string Employee10_20::getLastName() const {
	return lastName;
}


// Fig. 11.4: PhoneNumber.cpp
// Overloaded stream insertion and stream extraction operators for class PhoneNumber.
//#include "PhoneNumber.h"
// Overloaded stream insertion operator; cannot be a member function if we would like to invoke it with cout << somePhoneNumber;
ostream & operator<< ( ostream &output, const PhoneNumber &number ){
	output << "(" << number.areaCode << ") " << number.exchange << "-" << number.line;
	return output; // enables cout << a << b << c;
}
// Overloaded stream extraction operator; cannot be a member function if we would like to invoke it with cin >> somePhoneNumber;
istream &operator>>( istream &input, PhoneNumber &number ){
	input.ignore(); // skip (
	input >> setw( 3 ) >> number.areaCode; // input area code
	input.ignore( 2 ); // skip ) and space
	input >> setw( 3 ) >> number.exchange; // input exchange
	input.ignore(); // skip dash (-)
	input >> setw( 4 ) >> number.line; // input line
	return input; // enables cin >> a >> b >> c;
}
// Fig. 11.5: fig11_05.cpp
// Demonstrating class PhoneNumber's overloaded stream insertion and stream extraction operators.
//#include "PhoneNumber.h"
void PhoneNumber::Fig11_3to11_5main(PhoneNumber &phone){

	cout << "Enter phone number in the form (123) 456-7890:" << endl;
	// cin >> phone invokes operator>> by implicitly issuing the global function call operator>>( cin, phone )
	cin >> phone;

	cout << "The phone number entered was: ";
	// cout << phone invokes operator<< by implicitly issuing the global function call operator<<( cout, phone )
	cout << phone << endl;
}


/**<Fig11.6 to Fig 11.8*/
// Fig 11.7: Array.cpp
Array::Array( int arraySize ){ /**< converstion constructor */
	size = ( arraySize > 0 ? arraySize : 10 );
	ptr = new int[ size ]; // create space for pointer-based array

	for ( int i = 0; i < size; i++ )
		ptr[ i ] = 0; // set pointer-based array element
}
/**<Copy constructor must receive a reference to prevent infinite recursion*/
Array::Array( const Array &arrayToCopy ) : size( arrayToCopy.size ) {
	ptr = new int[ size ]; // create space for pointer-based array
	//    ptr = arrayToCopy.ptr; <- Dangling pointer!
	for ( int i = 0; i < size; i++ )
		ptr[ i ] = arrayToCopy.ptr[ i ]; // copy into object
}
Array::~Array() {
	delete [] ptr;
}
int Array::getSize() const {
	return size;
}
// overloaded assignment operator; const return avoids: ( a1 = a2 ) = a3
const Array & Array::operator=( const Array &right ) {
	if ( &right != this ) {  /**avoid self-assignment*/
		if ( size != right.size ) {
			delete [] ptr;
			size = right.size;
			ptr = new int[ size ];
		}

		for ( int i = 0; i < size; i++ )
			ptr[ i ] = right.ptr[ i ];
	}
	return *this; // enables x = y = z, for example
}
// determine if two Arrays are equal and return true, otherwise return false
bool Array::operator==( const Array &right ) const{
	if ( size != right.size )
		return false;
	for ( int i = 0; i < size; i++ )
		if ( ptr[ i ] != right.ptr[ i ] )
			return false;

	return true; // Arrays are equal
}
// overloaded subscript operator for non-const Arrays; reference return creates a modifiable lvalue
int &Array::operator[]( int subscript ) {
	if ( subscript < 0 || subscript >= size ){
		cerr << "\nError: Subscript " << subscript << " out of range" << endl;
		exit( 1 ); // terminate program; subscript out of range
	}
	return ptr[ subscript ]; // reference return
}
// overloaded subscript operator for const Arrays; const reference return creates an rvalue
int Array::operator[]( int subscript ) const {
	if ( subscript < 0 || subscript >= size ) {
		cerr << "\nError: Subscript " << subscript << " out of range" << endl;
		exit( 1 ); // terminate program; subscript out of range
	}

	return ptr[ subscript ]; // returns copy of this element
}
istream &operator>>( istream &input, Array &a ) {
	for ( int i = 0; i < a.size; i++ )
		input >> a.ptr[ i ];
	return input; // enables cin >> x >> y;
}
ostream &operator<<( ostream &output, const Array &a ) {
	int i;
	// output private ptr-based array
	for ( i = 0; i < a.size; i++ ){
		output << setw( 12 ) << a.ptr[ i ];
		if ( ( i + 1 ) % 4 == 0 ) // 4 numbers per row of output
			output << endl;
	}
	if ( i % 4 != 0 ) // end last line of output
		output << endl;

	return output; // enables cout << x << y;
}
void Array::Fig11_6to11_8main(){
	Array integers1( 7 ); // seven-element Array
	Array integers2; // 10-element Array by default

	cout << "Size of Array integers1 is " << integers1.getSize() << "\nArray after initialization:\n" << integers1;
	cout << "\nSize of Array integers2 is "<<integers2.getSize() << "\nArray after initialization:\n" << integers2;

	// input and print integers1 and integers2
	cout << "\nEnter 17 integers:" << endl;
	cin  >> integers1 >> integers2;

	cout << "\nAfter input, the Arrays contain:\n"
	<< "integers1:\n" << integers1
	<< "integers2:\n" << integers2;

	// use overloaded inequality (!=) operator
	cout << "\nEvaluating: integers1 != integers2" << endl;
	if ( integers1 != integers2 )
		cout << "integers1 and integers2 are not equal" << endl;

	// create Array integers3 using integers1 as an initializer; print size and contents
	Array integers3( integers1 ); // invokes copy constructor

	cout << "\nSize of Array integers3 is " << integers3.getSize() << "\nArray after initialization:\n" << integers3;

	// use overloaded assignment (=) operator
	cout << "\nAssigning integers2 to integers1:" << endl;
	integers1 = integers2; // note target Array is smaller

	cout << "integers1:\n" << integers1
	<< "integers2:\n" << integers2;

	// use overloaded equality (==) operator
	cout << "\nEvaluating: integers1 == integers2" << endl;
	if (integers1 == integers2)
		cout << "integers1 and integers2 are equal" << endl;

	// use overloaded subscript operator to create rvalue
	cout << "\nintegers1[5] is " << integers1[ 5 ];

	// use overloaded subscript operator to create lvalue
	cout << "\n\nAssigning 1000 to integers1[5]" << endl;
	integers1[5] = 1000;
	cout << "integers1:\n" << integers1;

	// attempt to use out-of-range subscript
	cout << "\nAttempt to assign 1000 to integers1[15]" << endl;
	integers1[ 15 ] = 1000; // ERROR: out of range
}

/**<小結:
 1. Array integers3( integers1 ); 會使用到Copy constructor。
 2. Copy constructor must receive its argumet by reference, not by value. Otherwise, infinite recursion will occur.
 3. From 2, the reason is that receiving an object by value requires the copy constructor to make a copy of the argument object
 4. int & Array::operator[]( int subscript ): returning a reference allows the assignment task! e.g., integers1[5]=1000;
 5. Dangling pointer: if a copy constructor simply copied the pointer of the source object to our target object,
 then both pointers would point to the same dynamically allocated memory! When the first destructor is called, it will delete
 the dynamically allocated memory and cause the other pointer undefined!
 6. const Array & Array::operator=( const Array & ) 的宣告中, const return 可避免 ( a1 = a2 ) = a3
 */


// Fig. 11.10: Date.cpp
// Date class member- and friend-function definitions.
// initialize static member; one classwide copy
const int Date::days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// Date constructor
Date::Date( int m, int d, int y ){
	setDate( m, d, y );
}
void Date::Fig11_9to11_11main(){
	string s1( "happy" );
	string s2( " birthday" );
	string s3;

	// test overloaded equality and relational operators
	cout << "s1 is \""   << s1 << "\"; s2 is \"" << s2
		 << "\"; s3 is \""<< s3 << '\"'
	<< "\n\nThe results of comparing s2 and s1:"
	<<"\ns2==s1yields"<< ( s2 == s1 ? "true": "false" )
	<<"\ns2!=s1yields"<< ( s2 != s1 ? "true": "false" )
	<<"\ns2> s1yields"<< ( s2 > s1 ? "true": "false" )
	<<"\ns2< s1yields"<< ( s2 < s1 ? "true": "false" )
	<<"\ns2>=s1yields"<< ( s2 >= s1 ? "true": "false" )
	<<"\ns2<=s1yields"<< ( s2 <= s1 ? "true": "false" );

	//test string member-function empty
	cout << "\n\nTesting s3.empty():" << endl;
	if (s3.empty()){
		cout << "s3 is empty; assigning s1 to s3;" << endl;
		s3 = s1;
		cout << "s3 is \"" << s3 << "\"";
	}

	// test overloaded string concatenation operator
	cout << "\n\ns1 += s2 yields s1 = ";
	s1 += s2; // test overloaded concatenation
	cout << s1;

	// test overloaded string concatenation operator with C-style string
	cout << "\n\ns1 += \" to you\" yields" << endl;
	s1 += " to you";
	cout << "s1 = " << s1 << "\n\n";

	// test string member function substr
	cout << "The substring of s1 starting at location 0 for\n"	<< "14 characters, s1.substr(0, 14), is:\n"
	<< s1.substr( 0, 14 ) << "\n\n";

	// test substr "to-end-of-string" option
	cout << "The substring of s1 starting at\n"	<< "location 15, s1.substr(15), is:\n"
	<< s1.substr( 15 ) << endl;

	// test copy constructor
	string s4( s1 );
	cout << "\ns4 = " << s4 << "\n\n";

	// test overloaded assignment (=) operator with self-assignment
	cout << "assigning s4 to s4" << endl;
	s4=s4;
	cout<<"s4="<<s4<<endl;

	// test using overloaded subscript operator to create lvalue
	s1[ 0 ] = 'H';
	s1[ 6 ] = 'B';
	cout << "\ns1 after s1[0] = 'H' and s1[6] = 'B' is: " << s1 << "\n\n";

	// test subscript out of range with string member function "at"
	cout << "Attempt to assign 'd' to s1.at( 30 ) yields:" << endl;
	s1.at( 30 ) = 'd'; // ERROR: subscript out of range
}

// set month, day and year
void Date::setDate( int mm, int dd, int yy ){
	month=(mm>=1&&mm<=12)?mm:1;
	year=(yy>=1900&&yy<=2100)?yy:1900;
	//test for a leap year
	if ( month == 2 && leapYear( year ) )
		day=(dd>=1&&dd<=29)?dd:1;
	else
		day = ( dd >= 1 && dd <= days[ month ] ) ? dd : 1;
}

// overloaded prefix increment operator
Date &Date::operator++() {
	helpIncrement(); // increment date
	return *this; // reference return to create an lvalue
}
// overloaded postfix increment operator; note that the dummy integer parameter does not have a parameter name
Date Date::operator++( int ){
	Date temp = *this; // hold current state of object
	helpIncrement();
	// return unincremented, saved, temporary object
	return temp; // value return; not a reference return
}

const Date &Date::operator+=( int additionalDays ){
	for ( int i = 0; i < additionalDays; i++ )
		helpIncrement();
	return *this; // enables cascading
}
bool Date::leapYear( int testYear ){
	if ( testYear % 400 == 0 || ( testYear % 100 != 0 && testYear % 4 == 0 ) )
		return true;
	else
		return false;
}
bool Date::endOfMonth( int testDay ) const {
	if ( month == 2 && leapYear( year ) )
		return testDay == 29;
	else
		return testDay == days[ month ];
}
void Date::helpIncrement() {
	//days in not end of month
	if ( !endOfMonth( day ) )
		day++;
	else
		if(month<12){//day is end of month and month < 12
			month++; // increment
			day = 1;
		}
		else { // last day of year
			year++;
			month = 1;
			day = 1;
		}
}
// overloaded output operator
ostream &operator<<( ostream &output, const Date &d ){
	static string monthName[ 13 ] = { "", "January", "February", "March", "April", "May", "June",
									"July", "August", "September", "October", "November", "December" };
	output << monthName[ d.month ] << ' ' << d.day << ", " << d.year;
	return output; // enables cascading
}


/**<小結: 1. ++x & x++ overloading 方式不同，prefix: Date &operator++(); postfix: Date operator++( int );
 	2. Any single-argument constructor can be used by the compiler to perform an implicit conversion--the type received by the
	   constructor is converted to an object of the class in which the constructor is defined
 */


// Fig. 11.13: Fig11_13.cpp
// Driver for simple class Array.
void outputArray( const Array & ); // prototype
void Array::Fig11_13main(){
	Array integers1( 7 ); // 7-element array
	outputArray( integers1 ); // output Array integers1
	outputArray( 3 ); /**< convert 3 to an object of class Array and output this object's content>**/
}
void outputArray( const Array &arrayToOutput ){
	cout << "The Array received has " << arrayToOutput.getSize()
		 << " elements. The contents are:\n" << arrayToOutput << endl;
}

/**<小結: 1. outputArray沒有int版本，所以compiler看到outputArray(3)時，先去class Array看有沒有conversion constructor可以轉換int到Array.
          2. 只要是只有一個參數的constructor都可以被視為conversion constructor, 所以此例中compiler自動轉換3到Array去～並帶入outputArray～成功轉換.
          3. 所以即使我們沒有提供int版本的outputArray, compiler仍然會自動轉換，有時候我們需要避免這種情形發生，可宣告"explicit"在constructor前面.
 	*/


// Fig. 11.18: Interface.cpp
// Implementation of class Interface--client receives this file only as precompiled object code, keeping the implementation hidden.
//#include "Interface.h" // Interface class definition
//#include "Implementation.h" // Implementation class definition
Interface::Interface( int v ): ptr ( new Implementation(v) ){
	//empty
}
Interface::~Interface(){
	delete ptr;
}
void Interface::Fig11_16to11_19main(){
	Interface i( 5 ); // create Interface object
	cout << "Interface contains: " << i.getValue() << " before setValue" << endl;
	i.setValue( 10 );
	cout << "Interface contains: " << i.getValue() << " after setValue" << endl;
}
void Interface::setValue( int v ){
	ptr->setValue( v );
}
int Interface::getValue() const{
	return ptr->getValue();
}

/**<小結: 1. Constructor的initializer list中，initializes ptr to point to a new Implementation object.
          2. user 在使用時毫無任何改變與影響
          3. Always use 'ptr' to acess original class's "服務"(member functions)
          4. 請見Proxy.hpp小結。
 */









/**< Chpater 12 的例子請直接看習題的例子，重點已囊括在其中。*/








// Fig. 13.2: CommissionEmployee.cpp
// Class CommissionEmployee member-function definitions.
// #include "CommissionEmployee.h" // CommissionEmployee class definition
CommissionEmployee::CommissionEmployee( const string &first, const string &last, const string &ssn, double sales, double rate )
    : firstName( first ), lastName( last ), socialSecurityNumber( ssn )
{
        setGrossSales( sales ); // validate and store gross sales
        setCommissionRate( rate ); // validate and store commission rate
}
void CommissionEmployee::setFirstName( const string &first ) { firstName = first; }
string CommissionEmployee::getFirstName() const { return firstName; }
void CommissionEmployee::setLastName( const string &last ){ lastName = last; }
string CommissionEmployee::getLastName() const { return lastName; }
void CommissionEmployee::setSocialSecurityNumber( const string &ssn ){ socialSecurityNumber = ssn; }
string CommissionEmployee::getSocialSecurityNumber() const { return socialSecurityNumber; }
void CommissionEmployee::setGrossSales( double sales ) { grossSales = ( sales < 0.0 ) ? 0.0 : sales; }
double CommissionEmployee::getGrossSales() const { return grossSales; }
void CommissionEmployee::setCommissionRate( double rate ) { commissionRate = ( rate > 0.0 && rate < 1.0 ) ? rate : 0.0; }
double CommissionEmployee::getCommissionRate() const { return commissionRate; }
double CommissionEmployee::earnings() const { return getCommissionRate() * getGrossSales(); }
void CommissionEmployee::print() const
{
    cout << "commission employee: " << getFirstName() << ' ' << getLastName()
         << "\nsocial security number: " << getSocialSecurityNumber()
         << "\ngross sales: " << getGrossSales()
         << "\ncommission rate: " << getCommissionRate();
}
// Fig. 13.4: BasePlusCommissionEmployee.cpp
// Class BasePlusCommissionEmployee member-function definitions.
//#include "BasePlusCommissionEmployee.h"
BasePlusCommissionEmployee::BasePlusCommissionEmployee( const string &first, const string &last, const string &ssn,
        double sales, double rate, double salary )
    : CommissionEmployee( first, last, ssn, sales, rate )
{
    setBaseSalary( salary );
}
void BasePlusCommissionEmployee::setBaseSalary( double salary ) { baseSalary = ( salary < 0.0 ) ? 0.0 : salary; }
double BasePlusCommissionEmployee::getBaseSalary() const { return baseSalary; }
double BasePlusCommissionEmployee::earnings() const { return getBaseSalary() + CommissionEmployee::earnings(); }
void BasePlusCommissionEmployee::print() const
{
    cout << "base-salaried ";
    CommissionEmployee::print();/**<invoke CommissionEmployee's print function*/
    cout << "\nbase salary: " << getBaseSalary();
}
// For Fig13.1 to Fig13.7 (no virtual case) + For Fig13.8 to Fig13.10 (virtual case)
// (non-virtual) Fig. 13.5: fig13_05.cpp + Fig. 13.6: fig13_6.cpp + Fig. 13.7: fig13_7.cpp || (virtual) Fig. 13.10: fig13_10.cpp
// Aiming base-class and derived-class pointers at base-class and derived-class objects, respectively.
//#include "CommissionEmployee.h"
//#include "BasePlusCommissionEmployee.h"
void Fig13_1to13_10main(){ //global function
    CommissionEmployee commissionEmployee( "Sue", "Jones", "222-22-2222", 10000, .06 );
    CommissionEmployee *commissionEmployeePtr = 0; /**< base class pointer*/
    BasePlusCommissionEmployee basePlusCommissionEmployee( "Bob", "Lewis", "333-33-3333", 5000, .04, 300 );
    BasePlusCommissionEmployee *basePlusCommissionEmployeePtr = 0; /**< derived-class pointer*/

    // objects calling
    cout << fixed << setprecision( 2 );
    cout << "Print base-class and derived-class objects:\n\n";
    commissionEmployee.print(); // invokes base-class print (static binding)
    cout << "\n\n";
    basePlusCommissionEmployee.print(); // invokes derived-class print (static binding)

    // base-class pointer -> base-class object and print
    commissionEmployeePtr = &commissionEmployee; // natural
    cout << "\n\n\nCalling print with base-class pointer to " << "\nbase-class object invokes base-class print function:\n\n";
    commissionEmployeePtr->print(); // invokes base-class print (dynamic binding)

    // derived-class pointer -> derived-class object and print
    basePlusCommissionEmployeePtr = &basePlusCommissionEmployee; // natural
    cout << "\n\n\nCalling print with derived-class pointer to "
         << "\nderived-class object invokes derived-class " << "print function:\n\n";
    basePlusCommissionEmployeePtr->print(); // invokes derived-class print (dynamic binding)

    // base-class pointer -> derived-class object and print
    commissionEmployeePtr = &basePlusCommissionEmployee; /**< 重點 */
    cout << "\n\n\nCalling print with base-class pointer to "
         << "derived-class object\ninvokes base-class print (if non-virtual)/ derived-class print (if virtual)"
         << "function on that derived-class object:\n\n";
    commissionEmployeePtr->print(); /* invokes base-class print *//**<dynamic binding, polymorphism if virtual case!!!*/
    cout << endl;


    // derived-class pointer -> base-clas object 此段來自 Fig13.6
//    basePlusCommissionEmployeePtr = &commissionEmployee;
    /**< Error, base-class obj is not an obj of derived class; derived-class pointer can only point to lower hierarchy class' obj.*/


    //下面示範 base-class pointer 不能呼叫 所指向物件的class的成員(除非宣告為virtual)，此段來自 Fig13.7
    //假設 base-class pointer -> derived-class object
    commissionEmployeePtr = &basePlusCommissionEmployee;
    // case 1: invoke base-class member functions on derived-class object through base-class pointer (allowed)
    string firstName = commissionEmployeePtr->getFirstName();
    string lastName = commissionEmployeePtr->getLastName();
    string ssn = commissionEmployeePtr->getSocialSecurityNumber();
    double grossSales = commissionEmployeePtr->getGrossSales();
    double commissionRate = commissionEmployeePtr->getCommissionRate();
    // case 2: invoke derived-class-only member functions on derived-class object through base-class pointer (disallowed)
//    double baseSalary = commissionEmployeePtr->getBaseSalary();
//    commissionEmployeePtr->setBaseSalary( 500 );
    /**< Error, base-class ptr can only access to base-class member functions, no matther which type of the object it points to.*/

}

/**<小結:
    1. base-class ptr 可以指向 derived-class 物件，但derived-class ptr 不可以指回較基層的base-class 物件。
    2. 敘述1等價於: derived-class objects are also base-class objects, but the reverse statment is incorrect.
        (而且你當然也不行把 base-class pointer 指向 derived-class pointer，道理同敘述2)
    3. base-class ptr 不管指向 base- 或 derived-class 物件都好，只要透過該ptr呼叫函數，一律都只看handle type.(即ptr所屬的class)
    如果想改成讓compiler看ptr所指向的物件的type，則需使用 virtual function (down-casting skill)，請解鎖 base-class keyword "virtual"
    4. virtual與non-virtual print的結果差異，請見.hpp 的Comment。
    */
