//
//  Chpater8_Exercises.cpp
//  20170607 Chapter 8 Exercises
//
//  Created by ntueconRA on 2017/6/7.
//  Copyright © 2017年 Kai. All rights reserved.
//

#include "Chpater8_Exercises.hpp"

//8.12
inline void moveTortoise( int * , const int & );
inline void moveHare( int *, const int & );
void ExerCh8::TortoiseAndHare8_12(){
	
	const int finishLine = 70;
	int posiTortoise = 1, posiHare = 1; //recor positions, begin at positioin 1.
	int clocktick = 0; //Record total times/while loops.
	srand(static_cast<unsigned int >(time(0)));
	//Introduction
	cout << "Welcome! Mr. Tortoise and Ms. Hare. The race is held besides the slippery mountain, and is going to begin soon. Word of Advice: Watch out your step to avoid slipping!\n";
	cout << "The first contender to reach or pass square 70 is rewarded with a pail of fresh carrots and lettuce!\n";
	cout << "GOOOOOOOOOOD LUCK!\n";
	cout << "BANG !!!!!\n";
	cout << "And THEY'RE OFF !!!!!\n\n\n";
	
	//RACE Began.
	while ( posiTortoise < finishLine && posiHare < finishLine ){
		//Move!
		moveTortoise( &posiTortoise, finishLine);
		moveHare( &posiHare, finishLine);
		clocktick++;
		//pring current race situation.
		cout << "Round " << clocktick << ": ";
		for (int i = 1; i < finishLine + 1; i++){
			if (i == posiTortoise && i == posiHare)
				cout << "OUCH!";
			else if (i == posiTortoise)
				cout << "T";
			else if (i == posiHare)
				cout << "H";
			else
				cout << " ";
		}
		cout << endl;
	}
	
	//Winner determination process.
	if ( posiTortoise == finishLine && posiHare == finishLine)
		cout << "Though it's a tie, but since tortoise is the underdog. So Tortoise WINS!!! CONGRATS!\n";
	else if (posiTortoise == finishLine)
		cout << "TORTOISE WINS!!! YAY!!!\n";
	else if (posiHare == finishLine)
		cout << "Hare wins. Yuch\n";
		
	
}
inline void moveTortoise( int *posiPtr, const int & finishLine ){
	
	int randMove = rand()%10 + 1; //Move type Generation.
	//Move steps determination
	if (1 <= randMove && randMove <= 5)//Fast plod
		randMove = 3;
	else if ( 6 <= randMove && randMove <= 7 ) //Slip
		randMove = -6;
	else if ( 8 <= randMove && randMove <= 10) //Slow plod
		randMove = 1;
	//Move!
	*posiPtr += randMove;
	//Check conditions.
	if (*posiPtr < 1)
		*posiPtr = 1;
	else if (*posiPtr > finishLine)
		*posiPtr = finishLine;
	
}
inline void moveHare( int *posiPtr, const int & finishLine){
	int randMove = rand()%10 + 1; //Move type Generation.
	//Move steps determination
	switch (randMove) {
		case 1:
		case 2:
			randMove = 0; //Sleep
			break;
		case 3:
		case 4:
			randMove = 9; //Big Hop
			break;
		case 5:
			randMove = -12; //Big Slip
			break;
		case 6:
		case 7:
		case 8:
			randMove = 1; //Small Hop
			break;
		case 9:
		case 10:
			randMove = -2; // Small Slip
			break;
	}
	//Move!
	*posiPtr += randMove;
	//Check conditions.
	if (*posiPtr < 1)
		*posiPtr = 1;
	else if (*posiPtr > finishLine)
		*posiPtr = finishLine;
	
}


//8.15
inline void quickSort (int *, int , int );
inline int partition(int * const , int &, int &);
void ExerCh8::Quicksort8_15(){
	const int arrSize = 10;
	int arr[arrSize];
	const int sIndex = 0, eIndex = arrSize-1;
	
	//initialization and print original values of the array
	cout << "The original arrya to be sorted is: \n";
	for (int i = 0; i < arrSize; i++)
		cout << setw(3) << (*(arr+i) = rand()%100+1 );
	cout << endl;
	
	//quickSort.
	quickSort( arr, sIndex, eIndex );
	
	//Print the result
	cout << "The array after sorting is: \n";
	for ( int i = 0; i < arrSize; i++)
		cout << setw(3) << *(arr+i);
	cout << endl;
}
inline void quickSort(int * const arrPtr, int sIndex, int eIndex){
	//Recursive return condition
	if (sIndex == eIndex)
		return;
	//Otherwise, partition and find the cut point.
	int distFromSI = partition(arrPtr, sIndex, eIndex);
		//one cut point divides an array into two pieces.
	quickSort(arrPtr, sIndex, max(sIndex, sIndex+distFromSI-1) );	//確保後者至少大於等於前者, 否則令相等
	quickSort(arrPtr, min(sIndex+distFromSI+1, eIndex), eIndex);	//確保後者至少大於等於前者, 否則令相等
	
}
inline int partition(int * const arrPtr, int &sIndex, int &eIndex){
	int * nPtr = arrPtr+sIndex; //Record target number's address and value waited to be coped with.
	int *posiPtr = arrPtr+eIndex;//will be the final position of the target *n.
	
	//Concept: 感覺像是 指標n一開始在最左邊(公主) 等待 posi（騎士)從最右邊向公主靠近
	//但途中只要找到適當位置(陷阱卡, 發動位置互換) 就一直互換, 直到posi 最後和 指標n同個位子
	while (true){
		while (*nPtr <= *posiPtr && nPtr < posiPtr)//case for pointer from right: 找到第一個比較小的就跳出
			posiPtr--;
		while (*nPtr >= *posiPtr && nPtr > posiPtr)//case for pointer from left:找到第一個比較大的就跳出
			posiPtr++;
		if (nPtr == posiPtr) //如果比到自己那就完成任務了, 直接跳出
			break;
		else {				 //否則換值也換指標名稱
			swap(*nPtr, *posiPtr);
			swap(nPtr, posiPtr);
		}
	}//end while
	
	return static_cast<int>( nPtr-(arrPtr+sIndex) );
	/**< One can also use return nPtr method, but have to modify relevent code. >*/
	
}//end partition()

//8.16
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
	//往右邊看剛好符合順時鐘順序 ( 1: east, 2: south, 3: west, 4: north )
	switch (direction){ //找出沿方向上一格的位子
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
void ExerCh8::MazeTraversal8_16(){
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
	int RHSRow = 0, RHSCol = 0; //用以判別右手變是否為#, 是的話把右手放到這個#號(更新), 否則右手在舊的#號並且繞著他走
	int HashRow = 0, HashCol = 0; //右手所放的標的(#)位子
	//frontRow/Col: 前方一格的位子
	int frontRow = 0, frontCol = 0;
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
		
		//判定終點,要放在下面判別式之前
		if (  frontRow==atRow && frontCol==atCol && isBorder(arrSize, arrSize, atRow, atCol)  ){
			cout << "Reach the exit! It's at (" << atRow << ", " << atCol << ")\n";
			return;
		}
		//hash mark 在右邊 &前方是牆壁 => turn left
		else if ( maze[frontRow].at(frontCol)== '#' && maze[RHSRow].at(RHSCol)=='#' ){
			if (direction ==1)
				direction = 4;
			else
				direction -= 1;
			continue;
		}
		//hash mark 在右邊 &前方有道路 => Move forward.
		else if( maze[frontRow].at(frontCol)!='#' && RHSRow==HashRow && RHSCol==HashCol){
			maze[frontRow].at(frontCol) = 'x';//move
			//update current position.
			atRow = frontRow;
			atCol = frontCol;
		}
		//hash mark 在斜後(不管前方是牆或道路), => 之前atRow/Col 更新失敗=> 正右方必定可行 => turn right and move!
		else if ( maze[RHSRow].at(RHSCol) != '#' ){
			direction = direction %4 +1; //turn right
			maze[RHSRow].at(RHSCol) = 'x'; // move
			//update current position.
			atRow = RHSRow;
			atCol = RHSCol;
		}
		
		//check
		for (int i =0; i < arrSize; i++)
			cout << setw(3) << maze[i] << endl;
		cout << endl;
		cout << "press return to see next move\n";
		cin.get();
		
	}//end while
	
}//end mazeTraverse


//8.17 well, this is copied from solution
enum Direction {DOWN, RIGHT, UP, LEFT};
const int MAX_DOTS = 100; //max possible dots for maze.
//function prototypes
void mazeTraversal( char [][12], const int, const int, int, int, int);
void mazeGenerator( char [][12],  int * , int * );
void printMaze( const char [][12] );
bool validMove( const char [][12], int, int );
bool coordsAreEdge( int, int );
void ExerCh8::GeneratingMazesRandomly8_17(){
	const int arrSize = 12;
	char maze[12][12];
	int xStart, yStart; // starting position
	int x, y; //current position
	
	srand(static_cast<unsigned int>(time(0)));
	
	//loop to generate hashes
	for ( int loop = 0; loop < arrSize; loop++ )
		for ( int loop2 = 0; loop2 < arrSize; loop2++)
			maze[loop][loop2] = '#';
	
	//generate the maze
	mazeGenerator(maze, &xStart, &yStart);
	
	//initialize x and y
	x = xStart;
	y = yStart;
	
	mazeTraversal(maze, xStart, yStart, x, y, RIGHT);
}//end GeneratingMazesRandomly8_17()
//Assume that there is exactly one entrance and one exit.
void mazeTraversal( char maze[][12],
				    const int xStart, const int yStart, int xCoord, int yCoord, int direction){
	static bool flag = false;
	
	maze[xCoord][yCoord] = 'x'; //一開始在入口
	printMaze( maze );
	
	//最後在邊界上&不是回到入口
	if ( coordsAreEdge(xCoord, yCoord) && xCoord != xStart && yCoord !=yStart){
		cout << "Maze successfully exited.\n\n";
		return; //maze is completed.
	}
	//回到入口&flag==true.
	else if ( xCoord == xStart && yCoord == yStart && flag ){
		cout << "Arrived back at the starting location.\n\n";
		return;
	}
	else{
		flag = true; //只要有跨出第一步, 則true.
		
		//for loop uses switch to etermine appropriate move
		//count: for loop只會跑最多4次(方向)就跳出
		for ( int move = direction, count =0; count < 4; count++, move++, move%=4 ){
			
			switch (move) {//Key: 根據題目的想法, 要盡量用右手沿著牆壁摸著走, 故都要帶右手邊的值(e.g., case DOWN => 帶遞迴LEFT)
				/*順序也有差！(difficult) 照順序判定Down -> Rigth -> Up -> Left. 因為當 validmove return false時, 表是超出邊界或者撞牆, 撞牆的話根據我們的右手岩牆走規則, 應該要左彎！
				 */
				case DOWN:
					if (validMove(maze, xCoord+1, yCoord)){
						mazeTraversal(maze, xStart, yStart, xCoord+1, yCoord, LEFT);
						return;
					}
					break;
				case RIGHT:
					if (validMove(maze, xCoord, yCoord+1)){
						mazeTraversal(maze, xStart, yStart, xCoord, yCoord+1, DOWN);
						return;
					}
					break;
				case UP:
					if (validMove(maze, xCoord-1, yCoord)){
						mazeTraversal(maze, xStart, yStart, xCoord-1, yCoord, RIGHT);
						return;
					}
					break;
				case LEFT:
					if (validMove(maze, xCoord, yCoord-1)){
						mazeTraversal(maze, xStart, yStart, xCoord, yCoord-1, UP);
						return;
					}
					break;
			}//end switch
			//Notice, 如果4個方向都false, 則for迴圈跳出, function return, 結束。
		}//end for
	}//end if...else

}
bool validMove( const char maze[][12], int r, int c){
	//check 要走的位子在合理範圍內 && 要走的位子不是牆壁
	return ( r>=0 && r<=12-1 && c>=0 && c<=12-1 && maze[r][c] != '#');
}
bool coordsAreEdge (int x, int y){
	//在邊界上都是return true, 否則return false.
	if ( ( x== 0 || x== 12-1) && ( y >= 0 && y <= 12-1)  )
		return true;
	else if ( ( y== 0 || y== 12-1) && ( x >= 0 && x <= 12-1)  )
		return true;
	else
		return false;
}
void printMaze( const char maze[][12]){
	for ( int x = 0; x < 12; x++){
		for ( int y = 0; y < 12; y++){
			cout << maze[x][y]<< ' ';
		}
		cout << '\n';
	}
	cout << "\nHit return to see next move.\n";
	cin.get();
}
void mazeGenerator( char maze[][12], int * xPtr, int *yPtr){
	int a; //store random numbers
	int entry, exit;
	int x, y;
	
	//Determine 開口在哪裡
	do {
		entry = rand() % 4;
		exit = rand() % 4;
	}while( entry == exit);
	
	//Determine entry position
	if ( entry == 0){ //LEFT
		*xPtr = rand() % (12-2) +1; //avoid corners.
		*yPtr = 0;
		maze[*xPtr][*yPtr] = '.';
	}
	else if ( entry == 1){ //UP
		*xPtr = 0;
		*yPtr = rand() % (12-2) +1; //avoid corners.
		maze[*xPtr][*yPtr] = '.';
	}
	else if ( entry == 2){ //DOWN
		*xPtr = rand() % (12-2) +1; //avoid corners.
		*yPtr = 12-1;
		maze[*xPtr][*yPtr] = '.';
	}
	else{ //RIGHT
		*xPtr = 12-1;
		*yPtr = rand() % (12-2) +1; //avoid corners.
		maze[*xPtr][*yPtr] = '.';
	}
	
	//Determine exit location
	if (exit == 0){ //LEFT
		a = rand() % (12-2) + 1;
		maze[a][0] = '.';
	}
	else if (exit == 1){ //UP
		a = rand() % (12-2) + 1;
		maze[0][a] = '.';
	}
	else if (exit == 2){ //DOWN
		a = rand() % (12-2) + 1;
		maze[a][12-1] = '.';
	}
	else{
		a = rand() % 10 + 1;
		maze[12-1][a] = '.';
	}
	
	//Generate paths (dots) in the interior of the maze.
	for (int loop = 1; loop < MAX_DOTS; loop++){
		x = rand() % (12-2) + 1;
		y = rand() % (12-2) + 1;
		maze[x][y] = '.';
	}//end for
		
}




//8.18 & 8.19
//Determine the sign of an argument input.
SML SML;
template <typename Tsign>
int sign(const Tsign &a){
	return ( (a >= 0)? 1: -1 );
}
bool validStr(const string &text){
	locale loc;
	if ( (text.at(0) == '+' || text.at(0) == '-') && text.length() == 5  ){	//case: first char is a sign
		for (int i = 0+1; i < 5; i++){ //continue to check from the second char.
			if ( ! isdigit(text.at(i),loc)  )
				return false;
		}
		return true;
	}
	else if ( isdigit(text.at(0), loc) && text.length() == 4 ){//case: first char is a decimal digit.
		for (int i = 0+1; i < 4; i++){ //continue to check from the second char.
			if ( ! isdigit(text.at(i),loc) )
				return false;
		}
		return true;
	}
	else
		return false;
}
//SML private member data accessing.
void SML::setMemory(const short *memoryPtr, const int &value){
	memory[abs(*memoryPtr)] = value;
}
double SML::getMemory(const short *memoryPtr){
	return memory[abs(*memoryPtr)];
}
void SML::clearMemory(){
	for (int i =0; i < 100; i++)
		memory[i] = 0;
}
void SML::setAccumulator(const int &value){
	accumulator = value;
}
double SML::getAccumulator(){
	return accumulator;
}
void SML::clearAccumulator(){
	accumulator = 0.0;
}
//Branches
void SML::IOoperations(const short &operation, const short *memoryPtr){
	class IOoperations Obj;
	switch (operation){
		case 10:
			Obj.read(memoryPtr);
			break;
		case 11:
			Obj.write(memoryPtr);
			break;
		default:
			cout << "Error, command not found\n";
			return;
	}
}
void SML::LSoperations(const short &operation, const short *memoryPtr){
	class LSoperations Obj;
	switch (operation) {
		case 20:
			Obj.load(memoryPtr);
			break;
		case 21:
			Obj.store(memoryPtr);
			break;
		default:
			cout << "Error, command not found\n";
			return;
	}
}
void SML::Arithoperations(const short &operation, const short *memoryPtr){
	class Arithoperations Obj;
	switch (operation) {
		case 30:
			Obj.add(memoryPtr);
			break;
		case 31:
			Obj.subtract(memoryPtr);
			break;
		case 32:
			Obj.divide(memoryPtr);
		case 33:
			Obj.multiply(memoryPtr);
		default:
			cout << "Error, command not found\n";
			return;
	}
	
}
void SML::TCoperations(const short &operation, const short *memoryPtr, size_t instrCounter){
	class TCoperations Obj;
	switch (operation) {
		case 40:
			Obj.branch(memoryPtr, instrCounter);
			break;
		case 41:
			Obj.branchNeg(memoryPtr, instrCounter);
			break;
		case 42:
			Obj.branchZero(memoryPtr, instrCounter);
			break;
		case 43:
			Obj.HALTT();
			break;
		default:
			cout << "Error, command not found\n";
			return;
	}
	
}
//Help
void SML::Helpoperation(){
	cout << "\nSimpletron Machine Language command list:\n";
	//Header
	cout << left << setw(12) << "Command"	<< setw(4) << "No"	<< "Explanation.\n";
	
	//List
	cout << left << setw(12) << "READ"		<< setw(4) << READ	<< "Read a word from the key board into a specific location in memory.\n";
	cout << left << setw(12) << "WRITE"		<< setw(4) << WRITE	<< "Write a word from a specific location in memory to the screen.\n";
	cout << left << setw(12) << "LOAD"		<< setw(4) << LOAD	<< "Load a word from a specific location in memoryin to the accumulator.\n";
	cout << left << setw(12) << "STORE"		<< setw(4) << STORE	<< "Store a word from the accumulator into a specific location in memory.\n";
	cout << left << setw(12) << "ADD"		<< setw(4) << ADD	<< "Add a word from a specific location in memory to the word in the accumulator (leave result in accumulator).\n";
	cout << left << setw(12) << "SUBTRACT"	<< setw(4) << SUBTRACT	<< ".\n";
	cout << left << setw(12) << "DIVIDE"	<< setw(4) << DIVIDE	<< ".\n";
	cout << left << setw(12) << "MULTYPLY"	<< setw(4) << MULTIPLY	<< ".\n";
	cout << left << setw(12) << "BRANCH"	<< setw(4) << BRANCH	<< "Branch to a specific location in memory.\n";
	cout << left << setw(12) << "BRANCHNEG" << setw(4) << BRANCHNEG << "Branch to a specific location in memory if the accumulator is negative.\n";
	cout << left << setw(12) << "BRANCHZERO"<< setw(4) << BRANCHZERO<< "Branch to a specific location in memory if the accumulator is zero.\n";
	cout << left << setw(12) << "HALT"		<< setw(4) << HALTT	<< "The program has completed its task.\n";
	cout << left << setw(12) << "HELP"		<< setw(4) << HELP	<< "Lookup command list.\n";
	cout << endl;
}
//main
void SML::MachineLanguageProgramming(){
	int flag = 0;
	while (flag != -9999){
		
		string text= "+0000";
		int instrCounter = 00;
		
		//Instrucsions input/store.
		while ( (stoi(text)/100) != 43  ){
			cout << right << setw(2) << setfill('0') << instrCounter << "?" << left << setfill(' ');
			cin >> text;
			while ( !validStr(text) ){ //check whether string is valid or not.
				cout << "\nInvalid input, pls input a 4-digit number with or without sign +/-.\n";
				cout << setprecision(2) << instrCounter << "?";
				cin >> text;
			}
			//store instructions into memory
			memory[instrCounter] = stoi(text);
			instrCounter++;
		}
		
		int i = 0; //used to record current excution num.
		do {
			
			//string to int; divide Word into two vars, one operation, the other memory locaion.
			const short int Word = memory[i];
			const short int operation = abs(Word)/100 ;
			const short int memory = sign(Word) * (Word % 100) ;//in between +/- 00~99. //不需要check, 自動成立
			
			//Branches.
			switch( (operation/10)*10 ){
				case 10:
					IOoperations(operation, &memory);
					break;
				case 20:
					LSoperations(operation, &memory);
					break;
				case 30:
					Arithoperations(operation, &memory);
					break;
				case 40:
					TCoperations(operation, &memory, i);
					break;
				case 50:
					Helpoperation();
					break;
				default:
					cout << "Error, command not found\n";
					break;
			}//end of switch
			i++; //execute next instruction
		} while ( (memory[i]/100) != 43 );//end do...while
	}//end while
}
//細項下的功能
void IOoperations::read(const short *memoryPtr ){
	int value;
	cout << "Input a value:";
	cin >> value;
	SML.setMemory( memoryPtr, value);
}
void IOoperations::write(const short *memoryPtr ){
	cout <<  SML.getMemory(memoryPtr) << endl;
}
void LSoperations::load(const short *memoryPtr){
	//load memory: memory location -> accumulator
	SML.setAccumulator( SML.getMemory(memoryPtr) );
}
void LSoperations::store(const short *memoryPtr){
	//store value: accumulator -> momeory location
	SML.setMemory( memoryPtr, SML.getAccumulator() ) ;
}
void Arithoperations::add(const short *memoryPtr){
	 SML.setAccumulator( SML.getAccumulator()+ SML.getMemory(memoryPtr) );
}
void Arithoperations::subtract(const short *memoryPtr){
	SML.setAccumulator( SML.getAccumulator()- SML.getMemory(memoryPtr) );
}
void Arithoperations::divide(const short *memoryPtr){
	SML.setAccumulator( SML.getAccumulator()/ SML.getMemory(memoryPtr) );
}
void Arithoperations::multiply(const short *memoryPtr){
	SML.setAccumulator( SML.getAccumulator() * SML.getMemory(memoryPtr) );
}
void TCoperations::branch(const short *memoryPtr, size_t &instrCounter){
	instrCounter = *memoryPtr;
}
void TCoperations::branchNeg(const short *memoryPtr, size_t &instrCounter){
	if ( SML.getAccumulator() < 0 )
		instrCounter = *memoryPtr;
}
void TCoperations::branchZero(const short *memoryPtr, size_t &instrCounter){
	if ( SML.getAccumulator() == 0)
		instrCounter = *memoryPtr;
}
void TCoperations::HALTT(){
	SML.clearMemory();
	SML.clearAccumulator();
	cout << "************SML execution terminated**************\n";
}



//8.18 & 8.19 別人的寫法
//simpletron.c
//instrution of error
typedef enum {EXCEPTION_INPUT_DATA,
	EXCEPTION_INSRUCTION,
	EXCEPTION_ERROR_DIVIDED,
	EXCEPTION_OUT_ACCUMULATOR,
	EXCEPTION_ERROR_OPERAND
}ERROR;
////////////////////////////////////////////////////////////////////
//function of instruction
void othersPeople::enterInstruction(void){
	printf("* * * Welcome to Simpletron * * *\n");
	printf("* * * Please enter your program one istruction * * *\n");
	printf("* * * (or data word) at a time .I will type the * * *\n");
	printf("* * * Location number and a question mark(?). * * *\n");
	printf("* * * You then tupe the word for that location. * * *\n");
	printf("* * * Type the sentinel -99999 to stop entering * * *\n");
	printf("* * * You program. * * *\n");
	int temporary_i = 0;
	while(1)
	{
		printf("%02d?",temporary_i);    //output information to get instruction
		scanf("%d",&memory[temporary_i]);    //get instruction
  
		if(memory[temporary_i] == -99999)    //end of -99999
		{
			printf("* * * Program loading completed * * *\n");
			printf("* * * Program execution begins * * *\n");
			break;
		}
		temporary_i++;     //add one
	}
}
////////////////////////////////////////////////////////////////////
//function of load instruction to register
void othersPeople::loadRegister(void){
	instructionRegister = memory[instructionCounter];    //load instruction to register
}
////////////////////////////////////////////////////////////////////
//function of translate instruction to oprationcode and oprand
void othersPeople::translateInstruction(void){
	operationCode = instructionRegister / 100;     //control accumulator get instruction code
	operand = instructionRegister % 100;    //control accumulator get operand
	if(operand < 0||operand >99)
		exception(EXCEPTION_ERROR_OPERAND);
}
////////////////////////////////////////////////////////////////////
//function of carry out struction
void othersPeople::carryInstruction(void){
	switch(operationCode)
	{
		case READ:    //read data from std intput
			scanf("%d",&memory[operand]);
			if(memory[operand]<-9999 || memory[operand]>9999)
			{
				exceptionQQ(EXCEPTION_INPUT_DATA);
				break;
			}
			instructionCounter++;
			break;
			
		case WRITE:    //write data to std ouput
			printf("%d\n",memory[operand]);
			instructionCounter++;
			break;
			
		case LOAD:    //add data to accumulator from memory
			accumulator = memory[operand];
			instructionCounter++;
			break;
			
		case STORE:    //transfer data of accumulator to memory
			memory[operand] = accumulator;
			instructionCounter++;
			break;
			
		case ADD:    //data of accumulator add to memory data
			accumulator += memory[operand];
			if(memory[operand]<-9999 || memory[operand]>9999)
			{
				exceptionQQ(EXCEPTION_OUT_ACCUMULATOR);
				break;
			}
			instructionCounter++;
			
			break;
			
		case SUBTRACT:    //data of accumulator subtract memory data
			accumulator -= memory[operand];
			if(memory[operand]<-9999 || memory[operand]>9999)
			{
				exceptionQQ(EXCEPTION_OUT_ACCUMULATOR);
				break;
			}
			instructionCounter++;
			break;
			
		case MULTIPLY:    //data of accumulator multiply memory data
			accumulator *= memory[operand];
			if(memory[operand]<-9999 || memory[operand]>9999)
			{
				exceptionQQ(EXCEPTION_OUT_ACCUMULATOR);
				break;
			}
			instructionCounter++;
			break;
			
		case DIVIDE:    //data of accumulator divide memory data
			accumulator /= memory[operand];
			if(memory[operand] == 0)
			{
				exceptionQQ(EXCEPTION_ERROR_DIVIDED);
				break;
			}
			instructionCounter++;
			break;
			
		case BRANCH:
			instructionCounter = operand;
			break;
			
		case BRANCHNEG:     //if accumulator less than zero,  //if accumulator equal to  zero, transfer memory
			if(accumulator < 0)
				instructionCounter = operand;
			else
				instructionCounter++;
			break;
			
		case BRANCHZERO:    //if accumulator equal to  zero, transfer memory
			if(accumulator == 0)
				instructionCounter = operand;
			else
				instructionCounter++;
			break;
			
		case HALT:    //if operation code equal to 43, break program
			printf("* * * Simpletron execution terminated * * *\n");
			break;
			
		default:    //carry out other instruction code
			exceptionQQ(EXCEPTION_INSRUCTION);
			break;
	}
}
////////////////////////////////////////////////////////////////////
//function of computer dump

void othersPeople::computerDump(void){
	//
	int temporary_i, temporary_j, temporary_k, temporary_l = 00, temporary_m = 00, temporary_n = 0;
	
	printf("\n");
	///////////////////////////////////////////////////////
	////print the data of simpletron
	printf("accumulator              %d\n",accumulator);
	printf("instructionCounter       %d\n",instructionCounter);
	printf("instructionRegister      %d\n",instructionRegister);
	printf("operationCode            %d\n",operand);
	printf("operand                  %d\n",operand);
	
	printf("memory:\n");    //print memory data
	printf("%2c",' ');
	
	//control
	
	for(temporary_i = 0; temporary_i < MEMORY_COUNTER / 10; temporary_i++)
	{
		printf("%8d",temporary_l);
		temporary_l++;
	}
	printf("\n\n");
	
	for(temporary_j = 0; temporary_j < MEMORY_COUNTER / 10; temporary_j++)
	{
		printf("%2d",temporary_m);
		temporary_m += 10;
  
		for(temporary_k = 0; temporary_k < MEMORY_COUNTER / 10; temporary_k++)
		{
			if(memory[temporary_n] == 0)
				printf("%3c%c%c%c%c%c",' ','+','0','0','0','0');
			else
				printf("%8d",memory[temporary_n]);
			
			temporary_n++;
		}
  
		printf("\n");
	}
	
}
///////////////////////////////////////////////////////////////////
//carry exception of program
void othersPeople::exceptionQQ(ERROR error){
	switch(error)
	{
		case EXCEPTION_INPUT_DATA:
			operationCode = HALT;
			printf("* * * the input data lsee than-9999 or more than 9999 * * *\n");
			break;
			
		case EXCEPTION_ERROR_DIVIDED:
			operationCode = HALT;
			printf("* * * the divide equal to zero * * *\n");
			break;
			
		case EXCEPTION_INSRUCTION:
			operationCode = HALT;
			printf("* * * the instruction error * * *\n");
			break;
			
		case EXCEPTION_OUT_ACCUMULATOR:
			operationCode = HALT;
			printf("* * * the accumulator is... * * *\n");
			break;
			
		case EXCEPTION_ERROR_OPERAND:
			operationCode = HALT;
			break;
		default:
			break;
	}
	//TODO
}
