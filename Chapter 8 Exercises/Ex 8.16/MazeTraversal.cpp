//8.16
#include "MazeTraversal.hpp"

bool isBorder(const int SizeRow, const int SizeCol, const int objRow, const int objCol){

	if (  (objRow == SizeRow-1 || objRow == 0) && 0 <= objCol && objCol < SizeCol)
		return true;
	else if ( (objCol == SizeRow-1 || objCol == 0) && 0 <= objRow && objRow < SizeRow)
		return true;
	else
		return false;
}
void posiFromDirection(const int arrSize, const int direction,const int baseRow, const int baseCol,
					   int  *determinedRow, int *determinedCol ){
	//clockwise: ( 1: east, 2: south, 3: west, 4: north )
	switch (direction){ //find the one-step-forward posi according to the direction and your curret posi(baseRow,baseCol).
		case 1:
			*determinedCol = min(baseCol+1, arrSize-1);
			break;
		case 2:
			*determinedRow = min(baseRow+1, arrSize-1);
			break;
		case 3:
			*determinedCol = max(baseCol-1, 0);
			break;
		case 4:
			*determinedRow = max(baseRow-1, 0);
			break;
	}//end switch

}
void mazeTraverse( string maze[], const int, int &, int & );

// core function
void MazeTraversal(){
	const int arrSize = 12;
	//The array maza is a const pointer pointing to const char.
	//the hash(#) represents the wall and the dot represents the space that you can move freely.
	string maze[arrSize] = {
		"############",
		"#...#......#",
		"..#.#.####.#",
		"###.#....#.#",
		"#....###.#..",
		"####.#.#.#.#",
		"#..#.#.#.#.#",
		"##.#.#.#.#.#",
		"#........#.#",
		"######.###.#",
		"#......#...#",
		"############"};
	/*OR one can use:
	char * maze2[arrSize] = {
		(char*)"############",
		(char*)"#...#......#",
		(char*)"..#.#.####.#",
		(char*)"###.#....#.#",
		(char*)"#....###.#..",
		(char*)"####.#.#.#.#",
		(char*)"#..#.#.#.#.#",
		(char*)"##.#.#.#.#.#",
		(char*)"#........#.#",
		(char*)"######.###.#",
		(char*)"#......#...#",
		(char*)"############"};
	*/
	int EntranceRow = 2, EntranceCol = 0;
	//Mark entrance by O
	maze[EntranceRow].at(EntranceCol) = 'O';

	//mazeTraverse!
	mazeTraverse( maze, arrSize, EntranceRow, EntranceCol);
}
void mazeTraverse( string maze[],const int arrSize, int &atRow, int &atCol  ){
	int direction = 1;
	//determine the correct direction
	//i.e., the target position's RHS is a hash(#) and its front is a dot (.)
	int RHSRow = 0, RHSCol = 0; // these are used to determine if right hand side is '#'(hash). If yes, then put your right hand on it(new hash); otherwise, you move according to the old hash(which your right hand remains originally.)
	int HashRow = 0, HashCol = 0; //the hash posi that your right hand put currently.
	int frontRow = 0, frontCol = 0; // your one-step-forward posi
	while ( true ){
		RHSRow = frontRow = atRow;
		RHSCol = frontCol = atCol;

		//update frontRow/Col
		posiFromDirection(arrSize, direction, atRow, atCol, &frontRow, &frontCol);
		//update RHSRow/Col
		posiFromDirection(arrSize, direction%4 +1 , atRow, atCol, &RHSRow, &RHSCol);

		//update the HASH MARK (the wall) on which the right hand puts
		if ( maze[RHSRow].at(RHSCol)=='#'){
			HashRow = RHSRow;
			HashCol = RHSCol;
		}

		//1. should firstly judge if you has successfully reached the exit or not.
		if (  frontRow==atRow && frontCol==atCol && isBorder(arrSize, arrSize, atRow, atCol)  ){
			cout << "Reach the exit! It's at (" << atRow << ", " << atCol << ")\n";
			return;
		}
		//2. case: hash mark is at your RHS & the front is a wall => turn left
		else if ( maze[frontRow].at(frontCol)== '#' && maze[RHSRow].at(RHSCol)=='#' ){
			if (direction ==1)
				direction = 4;
			else
				direction -= 1;
			continue;
		}
		//3. hash mark is at your RHS & the front is a road => Move forward.
		else if( maze[frontRow].at(frontCol)!='#' && RHSRow==HashRow && RHSCol==HashCol){
			maze[frontRow].at(frontCol) = 'x';//move
			//update current position.
			atRow = frontRow;
			atCol = frontCol;
		}
		//4. hash mark is behind you (no matter the front is a road or a wall),
		//   => previously if condition (3) is false => failed to update atRow & atCol values,
		//   => your RHS must be a road => turn right and move!
		else if ( maze[RHSRow].at(RHSCol) != '#' ){
			direction = direction %4 +1; //turn right
			maze[RHSRow].at(RHSCol) = 'x'; // move
			//update current position.
			atRow = RHSRow;
			atCol = RHSCol;
		}

		//print the maze.
		for (int i =0; i < arrSize; i++)
			cout << setw(3) << maze[i] << endl;
		cout << endl;
		cout << "press return to see next move\n";
		cin.get();

	}//end while

}//end mazeTraverse

