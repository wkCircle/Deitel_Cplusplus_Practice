#include "KnightsTour.hpp"
/*
 this global variable is used by following codes! 7.24, 7.26,...
 */
const int boardLength = 8; //global variable for the size of chessboard.

//represent types 0, 1,..., 7, respectively. Here we initialize all 8 possible move types.
const int horizontal[8] = {2 , 1, -1, -2,  -2, -1, 1, 2};
const int vertical[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
// Global var: a symbol BK representing the Knight's current position. I use 75 to avoid confliction with 0-64
const int BK = 75;

// prototype here
void showCommandList();
void printChessBoard(int (*array) [boardLength], int, int);
void moveKnight(int (*acc) [boardLength], int (*array) [boardLength], int& , int& , char, int& );
void moveUndo(int (*acc) [boardLength] , int (*array) [boardLength], int& , int& , int& );
void AccInitialize(int (*acc) [boardLength], int (*board) [boardLength], int, int);
void AccUpdate(int (*acc)[boardLength], int (*board)[boardLength], int , int, int, int );
void AccUndo(int acc [boardLength][boardLength], int board[boardLength][boardLength], int , int, int, int );
void printAcc(int acc [boardLength] [boardLength], int (*board)[boardLength]);
void checkClosedTour(const int, const int, int, int);
void solution_Algorithm(const int, const int);

//Solution Input: 6567 07250 21243 46560 35070 12143 45771 31763 03435 06457 12747 12527 6165(or 6612)
//Solution CLOSED tour: 7076 56305 34312 17075 32456 50702 42467 25212 76702 14576 43111 64256 3125
void KnightsTour(){
    /*main API function for the Knights Tour game.*/

	//initializations
	bool success = false; //check if user wins(==true).
	int board [boardLength][boardLength] = {}; //chess board
	int accessibility [boardLength][boardLength]; //Record total possible move types for each grid.

	static int counter = 1; //Record that how many number of unit squares have been passed. Varies from 1 to 64.
	const int startRow = 0, startColumn = 0;
	int currentRow = startRow, currentColumn = startColumn; //Knight's current position, initialized by startRow/startColumn.
	char command=' ';

	//Initialize board with Kinght's initial position.
	board[currentRow][currentColumn] = BK;
	//call to initialize Array: accessibility.
	AccInitialize(accessibility, board, currentRow, currentColumn);
	//Intrduction and interface tutorial.
	cout << "Welcome to chessBoard study, here we'll discuss whether a chess called Knight can pass thourgh all 8x8 squares with exactly one time for each square.\n";
	cout << "The Knight(marked as BK) starts at the position ("<< startRow << ", " << startColumn << " )\n";
	cout << "Please press H to call the operation list or B to show chessboard and history movement records.\n";
	cout << "Press 0-7 representing each move type to start moveing the Knight.\n";
	cout << "Press K to clear all data and restart or press Z to undo the last move.\n";
	cout << "Finally, press C to print array Accessibility. And press Capital Q to quit.\n";
	cout << "(Press A for solutions.)\n";
	while(true){
		cin >> command;
		while(  !(command >= '0' && command <= '7')
				&& command != 'H' && command != 'h' && command != 'B' && command != 'b' && command != 'K' && command != 'k'
				&& command != 'Z' && command != 'z' && command != 'C' && command != 'c' && command != 'Q' && command != 'A'
				&& command != 'a' ){
			cout << "Invalid Input. Try again.\n";
			cin >> command;
		}//end 2nd while (command checker)

		//Enter into different command function.
		switch (command){
			case 'H':
			case 'h':
				showCommandList();
				break;
			case 'B':
			case 'b':
				printChessBoard(board, currentRow, currentColumn);
				break;
			case 'K':
			case 'k':
				currentRow = startRow, currentColumn = startColumn;
				counter = 01;
				for (int i=0; i < boardLength; i++)
					for (int j =0; j < boardLength; j++)
						board[i][j] = 0;
				board[currentRow][currentColumn] = BK;
				AccInitialize(accessibility, board, currentRow, currentColumn);
				break;
			case 'Z':
			case 'z':
				moveUndo(accessibility, board, currentRow, currentColumn, counter);
				break;
			case 'C':
			case 'c':
				printAcc( accessibility , board);
				break;
			case 'A':
			case 'a':
				solution_Algorithm(startRow, startColumn);
				break;
			case 'Q': //require capital letter.
				return;

			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
				moveKnight( accessibility, board, currentRow, currentColumn, command, counter);
				break;
		}//end switch

		success = false;
		//User wins?
		if (counter == boardLength * boardLength){
			cout << "Congratulations! You wins!! How amazing you did it!\n";
			checkClosedTour(startRow, startColumn, currentRow, currentColumn);
			cout << "Please continue to command.\n";
		}
	}//end 1st while (always true)
}//end 7.24's main function.
void showCommandList(){
    /*show the help command to the user.*/
	cout << left << setw(25) << setfill(' ') << "H: Command List.";
	cout << "B: Print ChessBoard and history movement on the board.\n";
	cout << left << setw(25) << setfill(' ') << "Z: Undo last move." << "K: Reset all data and restart.\n";
	cout << "number 0-7: movement type as follows:\n";
	cout << "\t   2   1  " << endl;
	cout << "\t 3       0" << endl;
	cout << "\t     K    " << endl;
	cout << "\t 4       7" << endl;
	cout << "\t   5   6  " << endl;
	cout << "C: print array accessibility.\n";
	cout << "A: show solitions randomly.\n";
	cout << "Q(Capital): terminate program.\n\n";
}
void printChessBoard(int (*board)[boardLength], int currentRow, int currentColumn){
    /*print current posi and all histroy movements of knight as far*/
	for (int row = 0; row < boardLength; row++){
		for (int col = 0; col < boardLength; col++){
			if (row == currentRow && col == currentColumn ) //Alternatively, array[row][col] == 75 (see MoveKnight below)
				cout << " BK ";
			else if (board[row][col] == 0)
				cout << "    ";
			else
				cout << right << " "<< setw(2) << setfill('0') << board[row][col] << " ";
		}//end 2nd for
		cout << endl << endl;
	}//end 1st for
}
void moveKnight(int (*acc)[boardLength], int (*board)[boardLength], int& currentRow, int& currentColumn, char command, int& counter){
    /*get the input command and move the knight*/

	//restrict moveNumber = 0~7 (i.e., 8 types)
	int moveNumber = (int) command - '0'; //ASCII Table: '0'=48, 'A'=65, 'a'=97
	int tempRow = currentRow + vertical[moveNumber];
	int tempCol = currentColumn + horizontal[moveNumber];
	//record the updated Knight's position after applying move type.

	//we use these dummy vars to check BORDER CONDITION berfor updating the real values, currentRow and currentColumn.
	if ( !(0 <= tempRow && tempRow < boardLength) || !(0 <= tempCol && tempCol < boardLength) ){
		cout << "Invalid movement, Knight will fall out of chessboard. Please command again.\n";
		return;
	}
	//check PASSING exactly 1 time for each unit square.
	if ( board[tempRow][tempCol] != 0 ){
		cout << "Invalid movement, target place has already been passed through. Please command again.\n";
		return;
	}
	//After passing the above 'if' checkers, mark/record the old addresses in order.
	board [currentRow] [currentColumn] = counter++;

	//Update array: accessibility
	AccUpdate( acc, board, currentRow, currentColumn, tempRow, tempCol);
	//Update real paramaters.
	currentRow = tempRow;
	currentColumn = tempCol;

	//Mark/Record the current address as 75 (char ='K')
	board [currentRow][currentColumn] = BK;
}
void moveUndo(int (*acc)[boardLength], int (*board)[boardLength],int& currentRow, int& currentColumn, int & counter){
	/*undo the movement. There's no limit for the undo steps.*/
	int largest = 0;
	int lastrow = 0, lastcol = 0;

	//INITIAL CONDITION checker.
	if (currentRow == 0 && currentColumn == 0){
		cout << "BK has reached initial place, cannot undo anymore.\n";
		return;
	}
	//1. remove current position
	board[currentRow][currentColumn] = 0;

	//2. find the largest other than 'BK'(=75), but we've wiped it out.
	//This method will find the last move.
	for (int row = 0; row < boardLength; row++){
		for (int col = 0; col < boardLength; col++){
			if ( board[row][col] > largest ){
				largest = board[row][col];
				lastrow = row;
				lastcol = col;
			}
		}
	}

	//3.Undo all paramaters.
	counter--;
	/**< we capture the old board and old currentRow, and old currentColumn>*/
	AccUndo( acc, board, lastrow, lastcol, currentRow, currentColumn);
	currentRow = lastrow;
	currentColumn = lastcol;
	board[currentRow][currentColumn] = BK;

}

void AccInitialize(int (*acc)[boardLength], int (*board)[boardLength], int currentRow, int currentColumn){
    /*
    initialize the accessibility graph of the board
    accessibility shows for each grid how many possible moves can be made if the knight is at the grid.
    */
	int row = 0, col = 0; //only used by for loop header.
	int tempRow = 0, tempCol = 0;

	//clear all data in acc (i.e., accessibility[boardLength[boardLength])
	for ( row = 0; row < boardLength; row++)
		for ( col = 0; col < boardLength; col++)
			acc[row][col] = 0;

	for ( row = 0; row < boardLength; row++){
		for ( col = 0; col < boardLength; col++){
			//case1 for Knight's current position. set its value = BK.
			if ( row == currentRow && col == currentColumn){
				acc[row][col] = BK;
				continue;
			}

			//case2 for the unit square that has been passed by. Pass it. (set value = 0)
			if ( board[row][col] != 0 ){
				//acc[row][col] = 0; But this holds naturally with the declaration of acc.
				continue; //pass to next unit square.
			}

			tempRow = tempCol = 0;
			//case 3
			//Check two conditions for each movement type of a given position (row, col). +1 in acc[row][col] if two conditions pass!
			for( int temp = 0; temp < 8; temp++){
				tempRow = row + vertical[temp];
				tempCol = col + horizontal[temp];
				// check BORDER CONDITION.
				if ( !(0 <= tempRow && tempRow < boardLength) || !(0 <= tempCol && tempCol < boardLength) )
					continue; //check next movement type.
				// check NO REPEATED trace.
				else if ( board[tempRow][tempCol] != 0 )
					continue;
				//After passing two condition checkers, we know that this type is accessible. So +1.
				else
					acc[row][col]++;
			}
		}
	}
}

void AccUpdate(int (*acc)[boardLength], int (*board)[boardLength],int preRow, int preColumn, int newestRow, int newestColumn ){
    /*Update accessibility graph when the knight has been moved sucessfully.*/
	int tempRow = 0, tempCol = 0;

	//whenever the unit square was ever occuppied, set its value to the original value(=0).
	acc[preRow][preColumn] = 0;
	//update the newest Knight's position to be BK = 75.
	acc[newestRow][newestColumn] = BK;

	//update Knights' surronding at most 8 accessible positions' value by -1.
	for (int temp = 0; temp < 8; temp++){
		tempRow = newestRow + vertical[temp];
		tempCol = newestColumn + horizontal[temp];

		if ( ! (0 <= tempRow && tempRow < boardLength) || ! (0 <= tempCol && tempCol < boardLength) )
			continue;
		else if ( board[tempRow][tempCol] != 0)
			continue;
		else
			acc[tempRow][tempCol]--;
	}
}
void AccUndo(int (*acc)[boardLength], int (*board)[boardLength], int preRow, int preColumn, int currentRow, int currentColumn){
	/*Undo the accessibility graph*/
	int tempRow = 0, tempCol = 0;

	//set pre-position as BK and remove current position's value (originally it's =BK)
	acc[preRow][preColumn] = BK;
	acc[currentRow][currentColumn] = 0;

	//recover current position's accessibility value.
	//Simultaneously, recover it's surrounding 8 "possible" positions' value by +1.
	for (int temp=0; temp < 8; temp++){
		tempRow = currentRow + vertical[temp];
		tempCol = currentColumn + horizontal[temp];

		if ( ! (0 <= tempRow && tempRow < boardLength) || ! (0 <= tempCol && tempCol < boardLength) )
			continue;
		else if ( board[tempRow][tempCol] != 0)
			continue;
		else {
			acc[currentRow][currentColumn]++;
			acc[tempRow][tempCol]++;
		}
	}


}
void printAcc (int acc[boardLength][boardLength], int board[boardLength][boardLength]){
    /*print the accessibility graph of the chess board.*/

	for (int row = 0; row < boardLength; row++){
		for(int col = 0; col < boardLength; col++){
			if (acc[row][col] == BK)
				cout << " BK ";
			else if (board[row][col] != 0)
				cout << "    ";
			else
				cout << right << " " << setw(2) << setfill('0') << acc[row][col] << " ";
		}
		cout << endl << endl;
	}
}
void checkClosedTour(const int startRow, const int startColumn, int finalRow, int finalColumn){
    /*check if the knights final posi is the same as the original posi when user wins*/
	int tempRow = 0, tempCol = 0;
	for (int temp =0; temp < 8; temp++ ){
		tempRow = finalRow + vertical[temp];
		tempCol = finalColumn + horizontal[temp];

		//check BORDERS
		if ( ! (0 <= tempRow && tempRow < boardLength) || ! (0 <= tempCol && tempCol < boardLength) )
			continue;
		//check if the final place is one move away from the starting point.
		else if ( tempRow == startRow && tempCol == startColumn){
			cout << "Sehr Gut! The solution is a CLOSED tour!\n";
			return;
		}
	}//end for
	//if the above return doesn't occur, then following words will be printed.
	cout << "A little pitty that it's not a closed tour.\n";
}
void solution_Algorithm(const int start_Row,const int start_Column){
	/*
	this function will use AccInitialize(), moveKnight()(including AccUpdate())
	this function helps show a possible solution (randomly, and hence not necessary a closed tour solution).
	*/

	//initializations, same as before in ExerCh7::KnightsTour7_24();
	int board [boardLength][boardLength] = {}; //chess board
	int acc [boardLength][boardLength];
	int counter = 1;
	int currentRow = 0, currentColumn = 0; //Knight's current position, initialized at (0,0).

	//Initialize board with Kinght's initial position.
	board[currentRow][currentColumn] = BK;
	//call to initialize Array: accessibility.
	AccInitialize(acc, board, currentRow, currentColumn);
	//Intrduction and interface tutorial.



	//record solutions
	string sol= "  "; //for pretty print, I intentionally leave 2 spaces.

	//Algorithm
	//Strategy: starting from (0,0), let the Knight choose the position, which is accessible from the Knight, with the lowest accessibility value in array acc. If multiple positions satisfy the previous requirement, choose one of them randomly.

	int temp = 0, tempRow = 0, tempCol = 0; //vars to run all 8 movement types
	int record[8][2] = {}; //Records for 8 types, 1st elem: move type 0~7. 2nd elem: acc value.
	//record possible positions' corresponding values in acc. if not possible, set its value = 10000
	srand(static_cast<unsigned int>(time(0)));

	while(counter < boardLength * boardLength ){

		//ACCESSIBLE: run through all 8 move types to check which are accessible from the Knight.
		for ( temp = 0; temp < 8; temp++){
			record[temp][0] = temp;
			tempRow = currentRow + vertical[temp];
			tempCol = currentColumn + horizontal[temp];

			//check BORDERS
			if ( ! (0 <= tempRow && tempRow < boardLength) || ! (0 <= tempCol && tempCol < boardLength) )
				record[temp][1] = 10000;
			//check if the target position has been occuppied.
			else if ( board[tempRow][tempCol] != 0)
				record[temp][1] = 10000;
			else {
				record[temp][1] = acc[tempRow][tempCol];
			}
		}


		//A. Insertion method. Order from small to large according to record[ _var_ ][1].
		for( temp = 0 + 1; temp < 8 ; temp ++ ){
			int local = record[temp][0]; //(actually, = temp)
			int tar_type = record[temp][0];
			int tar_value = record[temp][1];

			while ( local > 0  && record[ local -1 ][1] > tar_value ){
				record[ local ][0] = record[ local -1 ][0];
				record[ local ][1] = record[ local -1 ][1];
				local--;
			}
			record[local][0] = tar_type;
			record[local][1] = tar_value;
		}

		//B. find those positions which have smallest acc values
		temp = 0;
		while ( record[temp+1][1] == record[temp][1] ) {
			temp++;
		}
		//Now, we let the Knight to move to one of those positions which have smallest acc values RANDOMLY!
		//A. Random choose.
		int moveInt_Choose = record[ rand() % (temp+1) ][0];
		//B. Put the decision into the solution string.
		char moveChar_Choose = '*';
		sprintf( &moveChar_Choose, "%d", moveInt_Choose);
		sol = sol + moveChar_Choose;
		if (sol.length() % 6 == 0)
			sol = sol + ' ';
		//C. MOVE and update acc array!
		moveKnight(acc, board, currentRow, currentColumn, moveChar_Choose, counter);
	}//end while

	//print the relevent results
	cout << "The Board will finally be: \n";
	printChessBoard(board, currentRow, currentColumn);
	cout << "The Accessibility array will finally look like: \n";
	printAcc(acc, board);
	cout << endl << endl;
	cout << "The corresponding solution string is: \n" << sol << endl;
	//check if it's a CLOSED tour.
	checkClosedTour(start_Row, start_Column, currentRow, currentColumn);

	//OVER and return
	cout << "Please continue to command.\n";
}//end solution_Algorithm()
