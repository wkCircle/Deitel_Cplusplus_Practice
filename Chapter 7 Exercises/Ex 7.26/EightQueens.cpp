#include "EightQueens.hpp"
/*
 this global variable is used by following codes! 7.24, 7.26,...
 */
const int boardLength = 8; //global variable for the size of chessboard.

//prototype
void elminInitialize( int (*elmin)[boardLength] );
void elminUpdate( int (*elmin)[boardLength] );


void EightQueens(){
	// solution algorithm
    // For each unit square, record the number of places would be eliminated if the queen is placed on that square.
	int elmin[boardLength][boardLength] = {};

	// In fact, possiblePosi and elmin are exactly the same (possiblePosi is the 1-dim transformation of elemin (2-dim))
	// elem 0: record corresponding position in elmin, elem 1: elmin-value
	int possiblePosi[boardLength*boardLength][2]= {};
	int countQueen = 0; //By question, we have to use 8 queens in total.
	const int Qu = 81, notValid = 1000;
	int row = 0, col = 0, temp = 0;
	bool success = false; //initial value can be neglected.
	//Initialize elmin array.
	elminInitialize( elmin );
	srand(static_cast<unsigned int>(time(0)));

	//THEOREM: A chessboard of size n can place at most n-1 queens if n=2,3. And can place at most n queens if n > 3.
	//According to theorem, the following method can only be used when n>3.
	while (countQueen < boardLength ){ //have to place boardLength = 8 queens.
		//This method won't always succeed. so if it fails to find 8 queens, we retry.
		if (countQueen == 7){ //after giving 7 queens, we then judge if it succeed or not.
			success = false; //default is false, and we use the following codes give chance that success becomes true.
			for ( row = 0; row < boardLength; row++){
				for (col = 0; col < boardLength; col++){
					if (elmin[row][col] != notValid && elmin[row][col] != Qu){ //ensure that there's a possible posi for the 8th queen.
						success = true;
						break;
					}
				}
			}//end for judgement
			if (success == false){ //that is, fail to find 8 queens
				countQueen = 0;
				row = col = temp = 0;
				elminInitialize(elmin);
				continue;
			}
		}

		//Transform from elmin into 1-dim array: possiblePosi.
		for ( row = 0; row < boardLength; row++){
			for ( col = 0; col < boardLength; col++){
				possiblePosi[ row*boardLength + col ][0] = row*boardLength + col;
				possiblePosi[ row*boardLength + col ][1] = elmin[row][col];
			}
		}

		//Linear Insertion
		for( temp = 0 + 1; temp < boardLength*boardLength ; temp ++ ){
			int local = possiblePosi[temp][0];
			int tar_posi = possiblePosi[temp][0];
			int tar_value = possiblePosi[temp][1];

			while ( local > 0  && possiblePosi[ local -1 ][1] > tar_value ){
				possiblePosi[ local ][0] = possiblePosi[ local -1 ][0];
				possiblePosi[ local ][1] = possiblePosi[ local -1 ][1];
				local--;
			}
			possiblePosi[local][0] = tar_posi;
			possiblePosi[local][1] = tar_value;
		}
		//Find SMALLEST value in elmin. If there are mutilple candidates, RANDOMLY choose one of them.
		//find the number of positions having smallest values.
		temp = 0;
		while ( possiblePosi[temp][1] == possiblePosi[temp+1][1] ) {
			temp++;
		}
		//Randomly choose.
		int decisionPosi = possiblePosi[ rand() % (temp+1) ][0];
		//Transform the decision into corr. position (i,j))
		int row_newQ = decisionPosi / boardLength;
		int col_newQ = decisionPosi % boardLength;
		//Update elmin array (since a new queen has been placed.)
		//1. horizontal updating
		for (col = 0; col < boardLength; col++)
			elmin[row_newQ][col] = notValid;
		//2. vertical updating
		for (row = 0; row < boardLength; row++)
			elmin[row][col_newQ] = notValid;
		//3. upleft-downright diagonal updating
		row = row_newQ;
		col = col_newQ;
		while( row >= 0 && col >= 0 ){
			elmin[row][col] = notValid;
			row--;
			col--;
		}
		row = row_newQ;
		col = col_newQ;
		while ( row < boardLength && col < boardLength ){
			elmin[row][col] = notValid;
			row++;
			col++;
		}
		//4. upright-downleft diagonal updating
		row = row_newQ;
		col = col_newQ;
		while ( row >= 0 && col < boardLength){
			elmin[row][col] = notValid;
			row--;
			col++;
		}
		row = row_newQ;
		col = col_newQ;
		while( row < boardLength && col >= 0){
			elmin[row][col] = notValid;
			row++;
			col--;
		}
		//5. Finally, the Queen and the countQueen++!
		elmin[ row_newQ ][ col_newQ ] = Qu;
		countQueen++;

		//Update elmin
		elminUpdate(elmin);

	}//end while

	//print the result
	row = col = 0;
	for (row = 0; row < boardLength; row++){
		for (col = 0; col < boardLength; col++){
			if (elmin[row][col] == notValid)
				cout << "   x";
			else if (elmin[row][col] == Qu)
				cout << "   Q";
			else
				cout << right << setw(4) << elmin[row][col];

		}//end 2nd for
		cout << endl << endl;
	}//end 1st for
}//end function EightQueens()
void elminInitialize( int (*elmin)[boardLength] ){
	for (int i = 0; i < boardLength; i++){
		for (int j = 0; j < boardLength; j++){

			elmin[i][j] = boardLength	 //horizontal
						+ boardLength -1 //vertical - repeated one
						+ ( -1 * abs(i-j) + boardLength ) -1 // #diagonal -repeated one; "i-j=const" is like a family curve.
						+ boardLength - abs( i+j-(boardLength-1)) -1; // #upright-to-donwlefg diagonal - repeated one; (the median of i+j is equal to boardLength-1)

		}//end 2nd for
	}//end 1st for

}
void elminUpdate( int (*elmin)[boardLength] ){
	const int Qu = 81, notValid = 1000;
	int i = 0, j =0;
	//only focus on positions that are still valid.
	for (int row = 0; row < boardLength; row++){
		for (int col = 0; col < boardLength; col++){
			//check conditions of available positions
			if (elmin[row][col] == notValid)
				continue;
			else if (elmin[row][col] == Qu)
				continue;

			//Initialize available positions
			elmin[row][col] = 0;
			//1. horizontal
			for ( j = 0; j < boardLength; j++){
				if ( elmin[row][j] != notValid && elmin[row][j] != Qu )
					elmin[row][col]++;
			}
			//2. vertical
			for ( i = 0; i < boardLength; i++){
				if ( elmin[i][col] != notValid && elmin[i][col] != Qu )
					elmin[row][col]++;
			}
			elmin[row][col]--; //PS repeated computation, so -1.
			//3. upleft-downright diagonal
			/**< case upper-lefter*/
			i = row;
			j = col;
			while( i >= 0 && j >= 0 ){
				if ( elmin[i][j] != notValid && elmin[i][j] != Qu)
					elmin[row][col]++;
				i--;
				j--;
			}
			elmin[row][col]--; //repeadted computation.
			/**< case downer-righter*/
			i = row;
			j = col;
			while ( i < boardLength && j < boardLength){
				if ( elmin[i][j] != notValid && elmin[i][j] != Qu)
					elmin[row][col]++;
				i++;
				j++;
			}
			elmin[row][col]--;
			//4. upright-downleft diagonal
			/**< case upper-righter*/
			i = row;
			j = col;
			while ( i >= 0 && j < boardLength){
				if ( elmin[i][j] != notValid && elmin[i][j] != Qu)
					elmin[row][col]++;
				i--;
				j++;
			}
			elmin[row][col]--; //repeadted computation.
			/**< case downer-lefter*/
			i = row;
			j = col;
			while ( i < boardLength && j >= 0){
				if ( elmin[i][j] != notValid && elmin[i][j] != Qu)
					elmin[row][col]++;
				i++;
				j--;
			}
			elmin[row][col]--; //repeadted computation.

		}//end 2nd while
	}//end 1st while
}
