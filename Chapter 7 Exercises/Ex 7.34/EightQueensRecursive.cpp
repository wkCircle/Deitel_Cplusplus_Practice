//7.34 Backtrack recursive method.
#include "EightQueensRecursive.hpp"

const int N7_34 = 8;
//prototype
void placeQueen( bool (*arr)[N7_34], int ); // declare "bool" for method 1, or "void" for method 2.
bool checkQueen( bool (*arr)[N7_34], int , int );

void EightQueensRecursive(){
    /*place the queen columnwise. Please uncomment either method 1 or method 2, then comment the other one.*/
	bool QueenBoard[N7_34][N7_34] = {}; // initialize the chess board.

	//For Method 1
    /*
    if ( placeQueen( QueenBoard, 0 ) ){
		cout << "The solutioin is: \n";
		for (int i = 0; i < N7_34; i++){
			for (int j = 0; j < N7_34; j++){
				cout << " " << QueenBoard[i][j];
			}
			cout << endl;
		}
	}//end if
	else
		cout << "Can't find any solution\n";
    */
    //End For Method 1

	//For Method 2
	placeQueen(QueenBoard, 0);
	//End For Method 2

}//end EightQueensRecursive()

//method 1, type bool to return true/false. Only print 1 result
/*
bool placeQueen(bool (*QueenBoard)[N7_34], int Num_queen ){
	if (Num_queen == N7_34) //if have already placed 0 to N-1 queens, return true.
		return true;

	for ( int row = 0; row < N7_34; row++){

		//check conditions. Notice that the target positioin is ( row, Num_queen ).
		if (  checkQueen( QueenBoard, row, Num_queen) ){

			//place the queen at first!
			QueenBoard[row][Num_queen] = 1;

			//continue to next queen. But if one of them reurn false, TRACKBACK.
			if ( placeQueen( QueenBoard, Num_queen+1) )
				return true;
			else
				QueenBoard[row][Num_queen] = 0;
		}//end if
	}//end for

	//if we didn't find any solution, reutrn false.
	return false;
}
*/
//End method 1 bool placeQueen
//method2 Brute force. print all results
void placeQueen(bool (*QueenBoard)[N7_34], int Num_queen ){
	static int counter = 0; //count number of successful patterns

	for ( int row = 0; row < N7_34; row++){
		//check conditions. Notice that the target positioin is ( row, Num_queen ).
		if (  checkQueen( QueenBoard, row, Num_queen) ){
			//place the queen at first!
			QueenBoard[row][Num_queen] = 1;
			if (Num_queen == N7_34-1){ //Once reach the number, all queens have been placed, and print the result.
				cout << "Number " << ++counter << " successful pattern:\n";
				for (int i = 0; i < N7_34; i++){
					for (int j = 0; j < N7_34; j++){
						cout << " " << QueenBoard[i][j];
					}
					cout << endl;
				}
				cout << endl << endl;
			}
			//continue to next queen.
			placeQueen( QueenBoard, Num_queen+1);
			QueenBoard[row][Num_queen] = 0;
		}//end if
	}//end for
}
//End method 2 void placeQueen

bool checkQueen( bool (*arr)[N7_34], int row, int column){
    /*
    Helper function to check if queens are placed correctly without breaking the game rules.
    Do not comment this function.
    */
	//target position at (row, column )
	int i = 0, j = 0;
	//A. check row
	for (j = 0; j < column; j++){
		if ( arr[row][j] == 1)
			return false;
	}
	//B. check up-left diagonal.
	for ( i = row, j = column ; i >=0 && j >= 0; i--, j--  ){
		if ( arr[i][j] == 1)
			return false;
	}
	//C. check down-left diagonal.
	for ( i = row, j = column ; i < N7_34 && j >= 0; i++, j-- ){
		if (arr[i][j] == 1)
			return false;
	}
	return true;
}
