// Fig. 9.13: fig09_13.cpp
// Demonstrating the order in which constructors and destructors are called.
#include "Fig9_11_CreateAndDestroy.hpp"
int main(){
   	CreateAndDestroy dem(0, "maincall");
	dem.Fig9_11to9_13main();
}


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

