#include "TurtleGraphics.hpp"


void showCommandList(){
	cout << " 1: pen up\n 2: pen down\n 3: turn right\n 4: turn left\n";
	cout << " \"5,x\": move forward x steps\n 6: print the graph\n";
	cout << " 7: call command list\n 8: clear all to reestart\n 9: end of data.\n";
}
//Notice: floorLength must be passed before the parameter array[][floorLength] if compatible with C99.
//You canNOT pass an array of refernces, but you can pass a reference of an array! (see following)
template <class T7_23_A, const unsigned int floorLength>
inline void printFloor( T7_23_A (&array)[floorLength][floorLength] ){
	for (unsigned int row = 0; row < floorLength; row++){
		for (unsigned int column = 0; column < floorLength; column++){
			if (array[row][column] == 0)
				cout << "  ";
			else if (array[row][column] == 1)
				cout << "* ";
		}
		cout << endl;
	}

	cout << endl << endl;
}

template <class T7_23_B, const unsigned int floorLength>
void DrawOrNot(T7_23_B floor[floorLength][floorLength] , int turtle[], int stepsMove){
	//turtle[row_posi, col_posi, pen is up(0)/down(1), pointing direction]
	/*
	 Rmb orginal location.
	 */
	int ori_posi[2] = {turtle[0], turtle[1]};

	switch (turtle[3]){

		case 1: //east
		case 3: //west
			if (turtle[3] == 3)
				stepsMove = -stepsMove;

			//update value
			turtle[1] += stepsMove;

			//if reach the border, then stop there and print warning.
			if (turtle[1] > floorLength -1 || turtle[1] < 0){
				turtle[1] = max(  min( turtle[1], static_cast<int>(floorLength-1)  ), 0); //max, min require two compared things of the same type.
				/**< this will make turtle[1] to be 0 for lower pound and floorLength -1 for uper bound. >**/
				cout << "reach border\n" << endl;
			}
			//Now, trace out the trajectory on floor if the pen is down.
			if (turtle[2] == 1){
				if (turtle[3] == 1){
					for(int column = ori_posi[1]; column <= turtle[1] ; column++)
						floor [  ori_posi[0]  ] [  column  ] = 1;
				}
				else if (turtle[3] == 3){
					for (int column = ori_posi[1]; column >= turtle[1]; column--)
						floor [  ori_posi[0]  ] [  column  ] = 1;
				}//end if
			}//end if

			break;

		case 2: //south
		case 4: //north
			if (turtle[3] == 4)
				stepsMove = -stepsMove;

			//update value
			turtle[0] += stepsMove;

			//if reach the border, then stop there.
			if (turtle[0] > floorLength -1 || turtle[0] < 0){
				turtle[0] = max(  min( turtle[0], static_cast<int>(floorLength-1)  ), 0);
				/**< this will make turtle[1] to be 0 for lower pound and floorLength -1 for uper bound. >**/
				cout << "reach border\n";
			}
			//Now, trace out the trajectory on floor if the pen is down.
			if (turtle[2] == 1){
				if (turtle[3] == 2){
					for(int row = ori_posi[0]; row <= turtle[0]; row++)
						floor [  row  ] [  ori_posi[1]  ] = 1;
				}
				else if (turtle[3] == 4){
					for (int row = ori_posi[0]; row >= turtle[0]; row--)
						floor [  row  ] [  ori_posi[1]  ] = 1;

				}//end if
			}//end if
			break;

	}//end switch

	//Report the newest situations of the turtle.
	cout << "Turtle stops at (" << turtle[0] << ", " << turtle[1] << "), with pen";
	if( turtle[2] == 0)
		cout << " up\n";
	else if (turtle[2] == 1)
		cout << " down\n";
	cout << "and with direction pointing to ";
	switch (turtle[3]) {
		case 1:
			cout << "east.\n";
			break;
		case 2:
			cout << "south.\n";
			break;
		case 3:
			cout << "west.\n";
			break;
		case 4:
			cout << "north.\n";
			break;
		default:
			cout << "Err. Algorithm method breaks.\n";
			return;
	}

	return;
}
inline void changeDirection( int & , int ); //prototype
void TurtleGraphics(){
	const unsigned int dimension = 2;
	const unsigned int floorLength = 20;
	bool floor [floorLength][floorLength] = {}; // an empty(0) paper waiting to be drawed(1).
	unsigned int row = 0, column = 0;
	//current location.
	//3rd elem: position of pen (up or down), defaulted to be up(0)
	//4th elem: current heading direction. (clockwise 1: east. 2: south 3: west 4: north)
	int turtle [dimension+2]={0,0,0,1};

	//1st elem determines the action of the program. 2nd elem determines number of forward/backward steps.
	int comm_arr [dimension]= {0, 0};


	cout << "Welcome to turtle graph program. Please refer to the following command list to start drawing.\n";
	showCommandList();
	cout << "If you forgot the command, please rembemer to press 7 to review.Please command.\n";

	//repeat requiring command until user presses 9.
	while(true){

		//read input and validate it.
		cin >> comm_arr[0];
		if(comm_arr[0] == 5){
			cin >> comm_arr[1];
		}
		while(comm_arr[0] < 1 || comm_arr[0] > 9 ){
			comm_arr[0] = comm_arr[1] = 0;
			cout << "Invalid command. Try again.\n";
			cin >> comm_arr[0];
			if(comm_arr[0] == 5){
				cin >> comm_arr[1];
			}
		}

		//branches of executioin
		switch (comm_arr[0]){
			case 1: //pen up
				turtle[2] = 0;
				break;
			case 2: //pen down (will trace out)
				turtle[2] = 1;
				break;
			case 3: //turn right
			case 4: //turn left
				changeDirection( turtle[3], comm_arr[0]);
				break;
			case 5: //turtle moves with pen up or down => draw or not.
				DrawOrNot(floor, turtle, comm_arr[1]);
				break;
			case 6:
				printFloor( floor );
				break;
			case 7:
				showCommandList();
				break;
			case 8: //reset all variables
				row = 0, column = 0;
				for (row = 0; row < floorLength; row++){
					for (column = 0; column < floorLength; column++){
						floor[row][column] = 0;
					}
				}
				turtle[0] = turtle[1] = turtle[2] =0;
				turtle[3] = 1;
				comm_arr[0] = comm_arr[1] = 0;
				break;

			case 9:
				return;
		}// end switch

	}// end while
}
//Notice: floorLength must be passed before the parameter array[][]!
inline void changeDirection(int &ori_Direction, int order){
	//clockwise 1: east. 2: south 3: west 4: north
	if (order == 3) { //order to turn right
		ori_Direction = ( ori_Direction % 4 ) +1 ;
	}
	else if (order == 4) {//turn left
		if (ori_Direction == 1)
			ori_Direction = 4;
		else
			ori_Direction -= 1;
	}
}
