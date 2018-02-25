//
//  Chapter7_Exercises.cpp
//  20170518 Chapter 7 Exercises
//
//  Created by ntueconRA on 2017/5/18.
//  Copyright © 2017年 Kai. All rights reserved.
//

#include "Chapter7_Exercises.hpp"

//7.10
ExerCh7_10::ExerCh7_10(int grosses[]){
	 setGrossesOfSalesperson(grosses);
}
void ExerCh7_10::setGrossesOfSalesperson(int grosses[] ){
	for (int i=0; i<members7_10; i++){
		grosses7_10[i] = grosses[i];
	}
}
const int ExerCh7_10::getmembers(){
	return members7_10;
}
void ExerCh7_10::salespersonSalaryRanges7_10(){
	const int num_catogaries = 9;
	int frequency[num_catogaries]={}; //from 0th to 8th position.
	int temp_Salary=0, to_Category=0;

	for(int i=0; i<members7_10; i++){
		temp_Salary = 200 + 0.09 * grosses7_10[i];
		to_Category = (temp_Salary-200) / 100;
		if (to_Category>= num_catogaries-1 )
			frequency[num_catogaries-1]++;
		else
			frequency[to_Category]++;
	}

	//print frequency[]
	cout << right << setw(13) << "Salary Range: " << endl;//header
	for (int i=0; i< num_catogaries; i++){
		if (i==num_catogaries-1) //last case title
			cout << "$" << i*100+200 << " and over: ";
		else
			cout << right << setw(7) << "$" << i*100+200 << "-" << i*100+299 << ": ";

		for (int j=0; j<frequency[i]; j++ ){
			cout << '*';
		}
		cout << endl;
	}
}
//7.10

void ExerCh7::bubbleSortAlgorithm7_12(int input[], int inputSize){
////insertion method
//	int temp = 0;
//
//	for(int n = 0+1; n < inputSize; n++){
//		temp = input[n];
//		int local = n;
//		while(local >0 && input[local-1] > temp){
//			input[local] = input[local-1];
//			local--;
//		}
//		input[local] = temp;
//	}
//
//	//print the result
//	for (int i=0; i< inputSize; i++)
//		cout << left << setw(4) << input[i];
////inseertion method END.

// method of 7.12 Only for decreasing sequence.
	int temp = 0;
	for(int n = inputSize-1 ; n > 0; n--){
		//pass values
		int truelocal = n;
		while (truelocal > 0 && input[truelocal-1] > input[n]){
			truelocal--;
		}
		//swap
		temp = input[n];
		input[n] = input[truelocal];
		input[truelocal] = temp;
		for(int i=0; i< inputSize; i++)
			cout << left << setw(4) << input[i];
		cout << endl;

	}
// method of 7.12 Only for decreasing sequence END
}
void ExerCh7::DuplicateEliminatio7_15(){
	int array_input[20]={};
	int subscript=0, elem=0;
	bool duplicate=0;
	cout << "Input 20 integers in [10,100] or input -111 to quit.\n";

	for ( int i=0 ; i<20; i++){

		cin >> elem;
		if (elem == -111){

			cout << "The non-duplicate input as far are: \n";

			if (subscript==0) cout << "none\n";
			for (int i=0; i<subscript; i++){
				cout << left << setw(4) << array_input[i];
			}
			cout << endl;

			return;
		}

		//check valid or not.
		while(elem <10 || elem >100){
			cout << "Invalid value for time " << i+1 << " input. Input again.\n";
			cin >> elem;
			if (elem == -111){
				cout << "The non-duplicate input as far are: \n";

				if (subscript==0) cout << "none\n";
				for (int i=0; i<subscript; i++){
					cout << left << setw(4) << array_input[i];
				}
				cout << endl;

				return;
			}
		}

		duplicate = 0; //defaulted to be false.
		//duplicate determination.
		for (int compare = 0; compare < subscript ; compare++){
			if (array_input[compare] == elem){
				duplicate = 1; //duplicate is true.
				break;
			}
		}

		//if not repeated, fill in the array.
		if ( !duplicate ){
			array_input[subscript] = elem;
			subscript++;
		}
	}

	//print the result
	cout << "The non-duplicate inputs are: \n";
	for (int i=0; i<subscript; i++){
		cout << left << setw(4) << array_input[i];
	}
	cout << endl;

}
void ExerCh7::DiceRolling7_17_and39(){
	const int diceSumCatogories = 11; //from sum 2 to 12.
	int frequencyDice[diceSumCatogories] = {}; //record frequency of the sum of two dices for 36000 tossing.
	const int totaltossing = 36000;
	int faceVal1 = 0, faceVal2 = 0;
	int counter = 0;

	//for 7_39 (use vector to solve the question.)
//	vector<int> frequDice(diceSumCatogories, 0);


	//toss 36000 and record the sum of two dice.
	for (counter = 0; counter < totaltossing; counter++){
		faceVal1 = rand() % 6 + 1;
		faceVal2 = rand() % 6 + 1;
		//store in array
		frequencyDice[ (faceVal1+faceVal2) -2  ]++;

		//store in vector
//		frequDice.at( (faceVal1+faceVal2)-2 )++;
	}

	//Print table!
	cout << right << setw(6) << "SumValue " << setw(8) << "times" << setw(13) << "%\n"; //header
	for (counter = 0; counter < diceSumCatogories; counter++){

		//call array
		//print the result by times of occurrance.
		cout << "sum=" << right << setw(2) << counter +2 << ": " << setw(9) << frequencyDice[counter];
		//print teh result by percentages.
		cout << setw(12) << 100 * static_cast<double>( frequencyDice[counter] ) / totaltossing << endl;

		//call vector
//		cout << "sum=" << right << setw(2) << counter +2 << ": " << setw(9) << frequDice.at(counter);
//		cout << setw(12) << 100 * static_cast<double>( frequDice.at(counter) ) / totaltossing << endl;
	}


}

//7.20
inline void AirlineSeatsGraph7_20(bool [], const int);
inline int checkSeatsFull(bool [], const int , long long int & );
void ClassBooking(bool [], const int, long long int &);
void RandomlyBooking(bool [], const int, long long int &);
void ExerCh7::AirlineReservationsSystem7_20(){
	const unsigned int seats = 10;
	bool seats_array[seats] = {1,0,0,0,0,1,0,1,0,1}; //Initialized to be 0 (or euqiv., false) representing seats are empty.
	long long int answer = -100;

	while(true){

		//Introduction and prints seats graph
		cout << "Welcome to the KAI Airline.\n";

		//Explain how to use the interface.
		cout << left << setw(30) << "Press  1 for First class;" << setw(30) << "Press 2 for Economy class." << endl;
		cout << left << setw(30) << "Press  0 to randomly book an empty seat." << endl;
		cout << "Press 50 to see the current booking situation of all seats on airplane no. XZ-737M.\n";
		cout << "Press -1 to terminate the program if you didn't need the service.\n";
		cin >> answer;

		//check input value
		while ( (answer < -1 || answer > 2) && answer != 50){
			cout << "Invalid Input. Try again.\n";
			cin >> answer;
		}

		//goto braches to execute.
		switch (answer) {
			case 0:
				RandomlyBooking(seats_array, seats, answer);
				break;
			case 1:
			case 2:
				ClassBooking(seats_array, seats, answer);
				break;
			case 50: //show seats graph
				cout << "\n\nFollowing shows all the seats and reservation situation in our airplane no. XZ-737M." << endl;
				AirlineSeatsGraph7_20(seats_array, seats);
				break;
			case -1:
				cout << "Thank you for using our service. We hope you have a nice journey. Good Bye.\n";
				return;
		}
	}//end while{}
} //end function 7.20
inline void AirlineSeatsGraph7_20(bool seats_array[], const int arraySize){
	int temp = 0;
	//header
	cout << right << setw(20) << "Type and Label ";
	for (int i=0; i < arraySize/2; i++)
		cout << setw(5) << i+1;
	cout << endl;
	//body graph
	cout << setw(20) << "First Class:   ";
	while (temp >= 0 && temp < arraySize/2){
		cout << setw(5) << seats_array[temp];
		temp++;
	}
	cout << endl;
	cout << setw(20) << "Economy Class: ";
	while (temp >= arraySize/2 && temp < arraySize){
		cout << setw(5) << seats_array[temp];
		temp++;
	}
	cout << endl;
	//ending with explanation.
	cout << "where\n     0: the seat is currently empty;     1: seat that has been reserved.\n" << endl;
}
inline int checkSeatsFull(bool seats_array[], const int arraySize, long long int &type){
	bool backtoHome =1, backtoCaller =0;
	bool Fisfull = 1, Eisfull = 1;
	char answerchar= ' ';

	Fisfull = 1; //preassume (yes) that all seats under F have been reserved.
	for (int i=0; i < arraySize/2 ; i++)
		if (seats_array[i] == 0)
			Fisfull = 0;

	Eisfull = 1; //preassume (yes) that all seats under E have been reserved.
	for (int i=arraySize/2; i < arraySize; i++)
		if (seats_array[i] == 0)
			Eisfull = 0;

	//case full seats
	if (Fisfull == 1 && Eisfull == 1){
		cout << "Sorry, all seats in flight no. XZ-737M have been reserved. Next flight leaves in 3 hours.\n";
		return backtoHome;
	}
	//case only First class is full.
	else if (Fisfull == 1 && type == 1){
		cout <<  "Sorry, all seats under First class have been reserved. Change to Economy class?[Y;N]\n";
		cin >> answerchar;
		while(answerchar != 'Y' && answerchar != 'y' && answerchar != 'N' && answerchar != 'n'){
			cout << "Invalid input, try again.[Y;N]\n";
			cin >> answerchar;
		}
		//if no, return.
		if (answerchar == 'N' || answerchar == 'n')
			return backtoHome;
		// if yes, change to economy class
		else {
			type = 2;
			return backtoCaller;
		}
	}
	//case only Economy class is full.
	else if (Eisfull == 1 && type ==2){
		cout <<  "Sorry, all seats under Economy class have been reserved. Change to First class?[Y;N]\n";
		cin >> answerchar;
		while(answerchar != 'Y' && answerchar != 'y' && answerchar != 'N' && answerchar != 'n'){
			cout << "Invalid input, try again.[Y;N]\n";
			cin >> answerchar;
		}
		//if no, return.
		if (answerchar == 'N' || answerchar == 'n')
			return backtoHome;
		// if yes, change to First class
		else {
			type = 1;
			return backtoCaller;
		}
	}
	//The other cases, do nothing and return to caller. (Including type =0 cases.)
	return backtoCaller;

}
void ClassBooking(bool seats_array[], const int arraySize, long long int &type){
	while (true){
		int seat_choose = 0, elem = 0;
		char answerchar = ' ';
		int temp = 0;

		//check that if all seats of two classes have been reserved, or if one class are reserved, or none.
		temp = checkSeatsFull( seats_array, arraySize, type); //reference &type
		if (temp == 1) //from def of called function, backtoHome = 1 => should return Home.
			return;

		//choose a seat under a class (type==1: First class, type==2: Economy class)
		cout << "Please choose a seat to book under ";
		if (type ==1){
			cout << "First class.";
		}
		else if (type ==2){
			cout << "Economy class.";
		}
		cout << "(1~5) or 0 to back to previous action.\n";
		cin >> seat_choose;

		//check value
		while (seat_choose < 0 || seat_choose > 5){
			cout << "Invalid input. Try again. (1~5) or 0 to be back.\n";
			cin >> seat_choose;
		}
		if (seat_choose==0){
			cout << endl << endl;
			return;
		}

		//For convenient, we use a var to represent different elements for different type cases.
		if (type == 1)
			elem = seat_choose -1;
		else if (type == 2)
			elem = seat_choose -1 + arraySize/2 ;

		//check if the seat is available or not. (1=true, 0=false)
		//case: seat not avaiable
		if( seats_array[ elem ] == true){
			cout << "Sorry, the seat has already been reserved for other client. Would you like to choose other seats?[Y;N]\n";
			cin >> answerchar;
			while(answerchar != 'Y' && answerchar != 'y' && answerchar != 'N' && answerchar != 'n'){
				cout << "Invalid input, try again.[Y;N]\n";
				cin >> answerchar;
			}
			if (answerchar == 'N' || answerchar == 'n')
				return;
			else //case yes, would like to choose other seats.
				continue; //back to top line of while{} to retry.
		}

		//Otherwise, always enter into the following case: seat available. Then make sure again.
		cout << "you are choosing seat: " << seat_choose << "\nAre you sure to book the seat?[Y;N]\n";
		cin >> answerchar;
		while(answerchar != 'Y' && answerchar != 'y' && answerchar != 'N' && answerchar != 'n'){
			cout << "Invalid input, try again.[Y;N]\n";
			cin >> answerchar;
		}

		//if yes, confirm booking and print out confirmation message.
		if (answerchar == 'Y' || answerchar == 'y'){
			seats_array[ elem ] = true;
			cout << "Booking confirmation:\n";
			cout << "Booking successfully at time: " << time(0) << endl;
			cout << "Class and Seats: ";
			if (type == 1)
				cout << 'F';
			else if (type ==2)
				cout << 'E';
			cout << elem ;
			cout << "Thank you for your booking.\n\n";
			return;
		}
		//if no, ask whether to book or not.
		else {
			cout << "Continue to book under ";
			if (type == 1)
				cout << "First class?";
			else if (type == 2 )
				cout << "Economy class?";

			cout << "[Y;N]\n";
			while(answerchar != 'Y' && answerchar != 'y' && answerchar != 'N' && answerchar != 'n'){
				cout << "Invalid input, try again.[Y;N]\n";
				cin >> answerchar;
			}
			//if no again (do not continue to book), then return to the previous action.
			if (answerchar == 'N' || answerchar == 'n'){
				cout << endl << endl;
				return;
			}
		}
	}//end while

}// end function FirstClassBooking()
void RandomlyBooking(bool seats_array[], const int arraySize, long long int &type){
	char answerchar = ' ';
	int temp = 0;

	////check that if all seats of two classes have been reserved, or if one class are reserved, or none.
	temp = checkSeatsFull( seats_array, arraySize, type ); //reference &type
	if (temp == 1) //from def of called function, backtoHome = 1 => should return to Home.
		return;

	//randomly choose a seat.
	temp=0;
	do {
		temp = rand() % 10;
	} while (seats_array[temp] != 0);
	//print the result.
	cout << "The seat is: ";
	if (temp < arraySize/2)
		cout << 'F' << temp+1 << endl;
	else
		cout << 'E' << temp+1 - (arraySize/2) << endl;

	//make sure again.
	cout << "Are you sure to book the seat?[Y;N]\n";
	cin >> answerchar;
	while(answerchar != 'Y' && answerchar != 'y' && answerchar != 'N' && answerchar != 'n'){
		cout << "Invalid input, try again.[Y;N]\n";
		cin >> answerchar;
	}

	//if yes, confirm booking and print out confirmation message.
	time_t mytime;
	mytime = time(NULL);

	if (answerchar == 'Y' || answerchar == 'y'){
		seats_array[temp] = true;
		cout << "BOOKING CONFIRMATION.\n";
		cout << "Booking successfully at time: " << ctime(&mytime);
		cout << "Class and Seats: ";
		if (temp >=0 && temp < arraySize/2)
			cout << 'F' << temp+1 << endl;
		else
			cout << 'E' << temp+1 - (arraySize/2) << endl;
		cout << "Thank you for your booking.\n" << endl;
		return;
	}
	//if no, return to previous action.
	else
		return;
}//end function RandomlyBooking
//7.20

void ExerCh7::salesSummary7_22(){
	int salesperson_num = 0, prod_num = 0, temp = 0, totalTotal = 0;
	const int Salespeople = 4, Products = 5;
	int sales[Products][Salespeople]={};
	char Answer=' ';
	cout << "Input a slip message containing three information in order\n";
	while(true){ //first while, ask whether to continue to input values after printing result table.

		while(true){ //second while ,loop for value input.

			cout << "1. Salesperson number(1~4)/ or -1 to quit to terminate the program.(your only chance)\n";
			cin >> salesperson_num;
			while (salesperson_num < 0 || salesperson_num >4){
				if ( salesperson_num == -1){
					return;
				};
				cout << "Invalid Input. Try again.(1~4)\n";
				cin >> salesperson_num;
			}


			cout << "2. Product number(1-5)\n";
			cin >> prod_num;
			while ( prod_num < 0 || prod_num >5){
				cout << "Invalid Input. Try again.(1~5)\n";
				cin >> prod_num;
			}


			cout << "3. Total dollar value of that product sold that day(>0).\n";
			cin >> temp;
			while ( temp < 0 ){
				cout << "Invalid Input. Try again.(1~5)\n";
				cin >> temp;
			}
			//Assign value to sales array. (Accumulative '+=')
			sales [prod_num -1 ][salesperson_num -1 ] += temp;

			cout << "Continue to input value? Or see the result? [L;R]\n";
			cin >> Answer;
			while(Answer != 'L' && Answer != 'l' && Answer != 'R' && Answer != 'r'){
				cout << "Err. Input L or R again.\n";
				cin >> Answer;
			}
			if( Answer == 'R' || Answer == 'r')
				break;
		}// end second while

		//print the result
		//header
		cout << endl << fixed << right << setw(12) << "ProdNum";
		for (int i = 0; i < Salespeople; i++)
			cout << setw(10) << "Person" << i+1;
		cout << setw(15) << "ProdTotal$";
		cout << endl;
		//body
		totalTotal = 0; //initailize
		for (int row = 0; row < Products ; row++){
			temp = 0;												//initialize
			cout << setw(11) << "Prod" << row+1;					//front words
			for (int column = 0; column < Salespeople; column++){	//intermediate words
				cout << setw(11) << sales[row][column];
				temp += sales[row][column];
			}
			cout << setw(15) << temp << endl;						//end words (total $ of that product)

			totalTotal += temp;
		}
		//Final row
		cout << setw(12) << "PersonTotal$";
		for (int column = 0; column < Salespeople; column++){
			temp = 0;
			for (int row = 0; row < Products; row++){
				temp += sales[row][column];
			}
			cout << setw(11) << temp;
		}
		cout << setw(15) << totalTotal << endl;

		//continue or not?
		cout << "Continue to input? or Exit the program? [L;R]\n";
		cin >> Answer;
		while(Answer != 'L' && Answer != 'l' && Answer != 'R' && Answer != 'r'){
			cout << "Err. Input L or R again.\n";
			cin >> Answer;
		}
		if( Answer == 'R' || Answer == 'r')
			return;

	}//end first while
}


//7.23
void showCommandList7_23(){
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
void ExerCh7::TurtleGraphics7_23(){
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
	showCommandList7_23();
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
				showCommandList7_23();
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
//7.23

/*
 this global variable is used by following codes! 7.24, 7.26,...
 */
const int boardLength = 8; //global variable for the size of chessboard.


//7.24 && 7.28
//represent types 0, 1,..., 7, respectively. Here we initialize all 8 possible move types.
const int horizontal[8] = {2 , 1, -1, -2,  -2, -1, 1, 2};
const int vertical[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
void showCommandList7_24(); //prototype
void printChessBoard(int (*array) [boardLength], int, int); //prototype
void moveKnight(int (*acc) [boardLength], int (*array) [boardLength], int& , int& , char, int& ); //prototype
void moveUndo(int (*acc) [boardLength] , int (*array) [boardLength], int& , int& , int& ); //prototype
void AccInitialize(int (*acc) [boardLength], int (*board) [boardLength], int, int);
void AccUpdate(int (*acc)[boardLength], int (*board)[boardLength], int , int, int, int );
void AccUndo(int acc [boardLength][boardLength], int board[boardLength][boardLength], int , int, int, int );
void printAcc(int acc [boardLength] [boardLength], int (*board)[boardLength]); //prototype
void checkClosedTour(const int, const int, int, int);
void solution_Algorithm(const int, const int); //prototype
void ExerCh7::KnightsTour7_24(){
	//Solution Input: 6567 07250 21243 46560 35070 12143 45771 31763 03435 06457 12747 12527 6165(or 6612)
	//Solution CLOSED tour: 7076 56305 34312 17075 32456 50702 42467 25212 76702 14576 43111 64256 3125
	//initializations
	const int BK = 75;
	bool success = false; //check if user wins(=true).
	int board [boardLength][boardLength] = {}; //棋盤
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
				showCommandList7_24();
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
void showCommandList7_24(){
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

	const int BK = 75;

	//restrict moveNumber = 0~7 (i.e., 8 types)
	int moveNumber = (int) command - '0'; //ASCII Table: '0'=48, 'A'=65, 'a'=97
	int tempRow = currentRow + vertical[moveNumber];
	int tempCol = currentColumn + horizontal[moveNumber];
	//record the updated Knight's position after applying move type.

	//we use these dummy vars to check BORDER CONDITION berfor updating the real values currentRow and currentColumn.
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
	const int BK = 75;
	int largest = 0;
	int lastrow = 0, lastcol = 0;

	//INITIAL CONDITION checker.
	if (currentRow == 0 && currentColumn == 0){
		cout << "BK has reached initial place, cannot undo anymore.\n";
		return;
	}

	//remove current position
	board[currentRow][currentColumn] = 0;

	//find the largest other than 'BK'(=75), but we've wiped it out.
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

	//Undo all paramaters.
	counter--;
	/**< we capture the old board and old currentRow, and old currentColumn>*/
	AccUndo( acc, board, lastrow, lastcol, currentRow, currentColumn);
	currentRow = lastrow;
	currentColumn = lastcol;
	board[currentRow][currentColumn] = BK;

}
void AccInitialize(int (*acc)[boardLength], int (*board)[boardLength], int currentRow, int currentColumn){
	const int BK = 75;
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
//Update accessibility for moveKnight
void AccUpdate(int (*acc)[boardLength], int (*board)[boardLength],int preRow, int preColumn, int newestRow, int newestColumn ){

	const int BK = 75;
	int tempRow = 0, tempCol = 0;
	// whenever the unit square was ever occuppied, set its value to the original value(=0).
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
	const int BK = 75;
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
	const int BK = 75;

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
	//use AccInitialize(), moveKnight()(including AccUpdate())
	//initializations, same as before in ExerCh7::KnightsTour7_24();
	const int BK = 75;
	int board [boardLength][boardLength] = {}; //棋盤
	int acc [boardLength][boardLength];

	int counter = 1;
	int currentRow = 0, currentColumn = 0; //Knight's current position, initialized at (0,0).

	//Initialize board with Kinght's initial position.
	board[currentRow][currentColumn] = BK;
	//call to initialize Array: accessibility.
	AccInitialize(acc, board, currentRow, currentColumn);
	//Intrduction and interface tutorial.



	//record solutions
	string sol= "  "; //故意空2格 後面排版方便

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
//end 7.24 && 7.28


//7.26
void elminInitialize( int (*elmin)[boardLength] );
void elminUpdate( int (*elmin)[boardLength] );
void ExerCh7::EightQueens7_26(){
	//solution algorithm
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
		if (countQueen == 7){ //第7次再進來判定就好
			success = false; //預設為否, 由下面判別式搬正
			for ( row = 0; row < boardLength; row++){
				for (col = 0; col < boardLength; col++){
					if (elmin[row][col] != notValid && elmin[row][col] != Qu){ //在找到第8個Queen以前, 至少要存在一個可行位置
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
		//Find SMALLEST value in elmin, if there are mutilple candidates, RANDOMLY choose one of them.
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
}//end function ExerCh7::EightQueens7_26()
void elminInitialize( int (*elmin)[boardLength] ){
	for (int i = 0; i < boardLength; i++){
		for (int j = 0; j < boardLength; j++){

			elmin[i][j] = boardLength	 //horizontal
						+ boardLength -1 //vertical - 重複1個
						+ ( -1 * abs(i-j) + boardLength ) -1 //左上-右下對角線數目 -重複1個 i-j=const is like a family curve.
						+ boardLength - abs( i+j-(boardLength-1)) -1; //右上-左下對角線數目 - 重複1個(i+j的最中間值=boardLength-1)

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
//end 7.26

//7.29
void ExerCh7::SieveofEratosthenes7_29(){
	const int arrSize = 1000;
	bool HelloPrime[arrSize] = {};//ignore elements 0 and 1, i.e., HelloPrime[0] and HelloPrime[1].
	int temp = 0, location = 0;
	//initialize to be true (ignore the first two elements).
	for (location = 2; location < 1000; location++ ){
		HelloPrime[location] = true;
	}

	for (location = 2; location < arrSize; location++){
		//check if false.
		if (HelloPrime[location] == false)
			continue;
		//otherwise, use the number as a factor to turn off the other integers that is divisible by it.
		for (temp = 2* location ; temp < arrSize; temp += location )
			HelloPrime[temp] = false;
	}//end 1st for

	//print all primes between 2 and 999
	int count = 0;
	for (int temp = 0; temp < arrSize; temp++){
		if (HelloPrime[temp] == true){
			cout << setw(4) << temp;
			count++;
			if (count % 10 == 0)
				cout << endl;
		}//end 1st if.

	}
}

//7.30 Bucket Sort!!!! (Better than insertion sort in performance but requires more memory) A trade-off.
void bucketSort( size_t [], const size_t );
void ExerCh7::BucketSort7_30(){
	const size_t arrSize = 20;
	size_t arr[arrSize] = {3,9,7,100,14,  20,1024,6,2,3964  ,1,1042,5,11,12  ,17,10,110,7,19};//must be positive integers
	bucketSort(arr, arrSize);
}
void bucketSort( size_t arr[], const size_t arrSize){
	size_t arr_bucket[10][arrSize];
	size_t maxDigit = 1, temp = 0, cateGory = 0, k = 0;
	size_t countarr = 0;


	//find the max digit in arr[]
	for ( k = 0; k < arrSize; k++){
		if ( arr[k] == 0 )
			continue;
		else if (	( temp = floor(log10(arr[k])) +1 )	>	maxDigit		)
			//note: cannot use ceiling() instead. CounterEg: arr[k] = 100
			maxDigit = temp;
	}


	//Big for loops begin. Run through all digits.
	for (int digit = 1; digit < maxDigit+1; digit++){

		//initialize arr_bucket
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < arrSize; j++)
				arr_bucket[i][j] = 0;

		//Distribution Pass: categorize each elem in arr[] according to its value of the current digit.
		for ( k = 0; k < arrSize; k++){
			cateGory = (	arr[k] % static_cast<size_t>(pow(10,digit) )	) / static_cast<size_t>(pow(10, digit-1));
			temp = 0;
			//put the new element into the first empty entry of a specified row.
			while ( arr_bucket[cateGory][temp] != 0){
				temp++;
			}//end while
			arr_bucket[ cateGory ] [temp] = arr[k];
		}//end for

		//Gathering Pass: copy the temparory result to original array: arr[]
		countarr = 0;
		for ( k = 0 ; k < 10; k++){//run through all rows(categories).
			temp = 0;
			while ( arr_bucket[k][temp] != 0){
				arr[countarr] = arr_bucket[k][temp];
				countarr++;
				temp++;
			}//end while
		}//end for.

		//		//test: if you want to deubg/explore the method, decomment the following codes.
		//		cout << "Current arr_bucket is: \n";
		//		for (int i = 0; i < 10; i++){
		//			for (int j = 0; j < arrSize; j++){
		//				cout << setw(4) << arr_bucket[i][j];
		//			}
		//			cout << endl;
		//		}
		//		cout << "\nAND current arr[arrSize] is: \n";
		//		for (k = 0; k < arrSize; k++)
		//			cout <<setw(6) << arr[k];
		//		cout << endl << endl;

	}//end 1st for.

	//print the result
	cout << "After bucket sorting, the sequence is: \n";
	for (k = 0; k < arrSize; k++)
		cout <<setw(6) << arr[k];
	cout << endl << endl;

}

//7.31
void selectionSort( int [], const int );
void ExerCh7::SelectionSort7_31(){
	const int arrSize = 10;
	int arr[arrSize]= {3,7,10,15,100,  1010,-57, -5, -10, 0};
	selectionSort(arr, arrSize);

	for (int i = 0; i < arrSize; i++)
		cout << setw(5) << arr[i];
	cout << endl;
}
void selectionSort(int arr[], const int arrSize ){
	static int m = 0;
	m++; //記錄呼叫次數, 同時紀錄從第幾個entry開始sorting.
	if ( arrSize-m == 0)
		return;
	else{
		int i = 0, location = 0, minelem = 10000;
		//find the smallest
		for (i = m-1; i < arrSize; i++)
			if ( arr[i] < minelem){
				location = i;
				minelem = arr[i];
			}
		//swap with first elem
		arr[location] = arr[m-1];
		arr[m-1] = minelem;

		selectionSort(arr, arrSize );
	}
}

//7.32
bool testPalindrome( char [], size_t, int );
inline int getSize( string str){
	return static_cast<int>( str.length() );
	//or strlen(str);
	//or str.size();
}
inline void putStrIntoArr( char arr[], size_t arrSize, string str){
	for (int temp = 0; temp < arrSize; temp++){
		arr[temp] =  str.at(temp);
	}
//	or strcpy(arr, str.c_str() );
}
void ExerCh7::Palindromes7_32(){
	string text = "     Hello H  olleH ";
	string Msg = "I have no idea";

	const int len_text = getSize(text);
	const int len_Msg = getSize(Msg);
	char textArr[ len_text ];
	char MsgArr[ len_Msg ];
	putStrIntoArr(textArr, len_text, text );
	putStrIntoArr(MsgArr, len_Msg, Msg);
//以上其實太麻煩了, 可直接使用"[]", see below
/*
 int i = 0;
 int j = text.length() -1;
 while( i != j && i < j ){
	if ( text[0] == text[j] )
		text = text.substr(1, j-1);
	else{
		cout << "false";
		break;
	}

 }
 */

	cout << "text string is a palindrome?\t" << boolalpha << testPalindrome( textArr, 0, len_text-1 ) << endl;
	cout << "string Msg is a palindrome?\t " << testPalindrome( MsgArr, 0, len_Msg-1 ) << endl;
}
bool testPalindrome( char arr[], size_t startIndex, int endIndex){
	if ( endIndex+1 == 0)
		return true;
	else if (endIndex- startIndex == 0 )
		return true;

	//start checking palindrome
	//neglect null character
	while ( arr[startIndex] == ' ' && startIndex < endIndex )
		startIndex++;
	while ( arr[endIndex] == ' ' && startIndex < endIndex )
		endIndex--;
	//case1 nothing can be compared.
	if (endIndex == startIndex )
		return true;
	//case2 compare
	else if (arr[startIndex] == arr[endIndex]){
		return testPalindrome(arr, startIndex+1, endIndex-1 );
	}
	//if incorrect otherwise, return false
	else
		return false;
}

//7.33
int linearSearch( int [], int, int );
void ExerCh7::LinearSearch7_33(){
	const int arrSize = 100;
	int arr[arrSize] = {};
	int key = 97, position = 0;

	//initialize arr[]
	for (int i =0; i < arrSize; i++)
		arr[i] = rand()%100;

	//function call
	position = linearSearch(arr, key, arrSize);

	//print result:
	if (position != -1 )
		cout << "The key value " << key << " is found in position " << position << " in the array\n";
	else
		cout << "Key value not found.\n";
}
int linearSearch( int arr[],int key, int arrSize){
	//if find the value, return the location
	if (arr[arrSize-1] == key)
		return arrSize-1;
	//if not, then check if arrSize is still >0 and then return recursive function
	else if (arrSize > 0)
		return linearSearch(arr, key, arrSize-1);
	//if didn't find the key until arrSize == 0
	else
		return -1;
}

//7.34 Backtrack recursive method.
const int N7_34 = 8;
void placeQueen( bool (*arr)[N7_34], int ); // prototype
bool checkQueen( bool (*arr)[N7_34], int , int ); // prototype
void ExerCh7::EightQueensRecursive7_34(){

	bool QueenBoard[N7_34][N7_34] = {};

	//place the queen columnwise.

	//For Method 1 (see below)
/*	if ( placeQueen( QueenBoard, 0 ) ){
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

	//For method 2.
	placeQueen(QueenBoard, 0);

}//end EightQueensRecursive7_34()
//method 1, type bool to return true/false. Only print 1 result
/*bool placeQueen(bool (*QueenBoard)[N7_34], int Num_queen ){
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
}*/
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

			//反正之前已經把result印出來了, 所以當樹枝的placeQueen跑完return回樹幹時就復原，方便樹幹跑下一個for loop 變數(ie, row)
			//如需儲存結果，在上面declare陣列變數再透過function pass就好
			QueenBoard[row][Num_queen] = 0;
		}//end if
	}//end for
}
bool checkQueen( bool (*arr)[N7_34], int row, int column){
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

//7.35
void printArray( char [], size_t, size_t);
void ExerCh7::printArray7_35(){
	char array[] = " Ich Heiße Setsuna. Vielen Dank."; //ß = 2 bytes.
	printArray( array, 7, 7);
	cout << endl;
	printArray( array, 8, 8);
	cout << endl;
	printArray(array, 8, 9);
}
void printArray( char arr[], size_t sIndex, size_t endIndex){
	//While-method.
//	while ( sIndex != endIndex+1){
//		cout << arr[sIndex];
//		sIndex++;
//	}
//	cout << endl;
	//Recursive method
	if ( sIndex != endIndex+1){
		cout << arr[sIndex];
		printArray(arr, sIndex+1, endIndex);
	}

}

//7.36
void stringReverse( string, size_t);
void ExerCh7::PrintAStringBackward7_36(){
	string text = " Ich Heiße Setsuna. Vielen Dank.";	//Problem: how to print ß correctly?
	stringReverse(text, 15);
}
void stringReverse( string str, size_t sReverse){
	if (sReverse != 0){
		cout << str[sReverse];
		stringReverse(str, sReverse-1 );
	}
	else if (sReverse == 0)
		cout << str[sReverse];

}

//7.37
int recursiveMinimum (int [], int , int );
int recursiveMinimum (vector<int> & , int, int); //function overloading.
void ExerCh7::FindMinValInArray7_37_and40(){
	const size_t arrSize = 10;
	//for array
	int arr[arrSize] =  {5, 100, 3, -12, 26, 55, 55, 0, -110, -1024};
//	srand(static_cast< unsigned int >(time(0)));
//	for (int i = 0; i < arrSize; i++)
//		arr[i] = rand()%20000 - 10000;
	cout << recursiveMinimum( arr, 0 /**< starting index>*/, 5 /**<end index>*/   ) << endl;

	//for vector
//  vector<int> vec = {5, 100, 3, -12, 26, 55, 55, 0, -110, -1024};
    vector<int> vec(arrSize); vec.assign(arr, arr+arrSize );
//	vector<int> vec(arr, arr + sizeof(arr)/sizeof(int) );
//	vector<int> vec( arr, arr + arrSize);

//	srand(static_cast< unsigned int >(time(0)));
//	for (int i = 0; i < vec.size(); i++)
//		vec.at(i) = rand()%20000 - 10000;
	cout << recursiveMinimum( vec, 0 /**< starting index>*/, 5 /**<end index>*/   ) << endl;

}
int recursiveMinimum (int arr[], int sIndex, int eIndex ){
	static int minvalue = 50000;

	if (sIndex > eIndex)
		return minvalue;

	int temp = 0;

	temp = min(arr[sIndex], arr[eIndex]);
	if ( temp < minvalue )
		minvalue = temp;
	temp = 0;
	return recursiveMinimum(arr, sIndex+1, eIndex-1);


}
int recursiveMinimum ( vector<int> &vec, int sIndex, int eIndex ){
	static int minvalue = 50000;

	if (sIndex > eIndex)
		return minvalue;

	int temp = 0;

	temp = min(vec.at(sIndex), vec.at(eIndex));
	if ( temp < minvalue )
		minvalue = temp;
	temp = 0;
	return recursiveMinimum( vec, sIndex+1, eIndex-1);


}

//7.38 //require header file #include<vector>
ExerCh7_38::ExerCh7_38( vector<int> &input ){
	setGrossesOfSalesperson(input);
}
void ExerCh7_38::setGrossesOfSalesperson( vector<int> &input ){
		grosses7_38 = input;//will change size of grosses7_38 directly to match input.
}
void ExerCh7_38::salespersonSalaryRanges7_38(){
	const int num_catogaries = 9;
	vector<int> frequency(num_catogaries, 0); //from 0th to 8th position, all are initialized with value = 0.
	int temp_Salary=0, to_Category=0;

	for(int i = 0; i < members7_38; i++){
		temp_Salary = 200 + 0.09 * grosses7_38.at(i);
		to_Category = (temp_Salary-200) / 100;

		//since [] operator doesn't check borders, it's better to use .at() to visit address.
		if (to_Category >= num_catogaries-1 )
			frequency.at(num_catogaries-1)++;
		else
			frequency.at(to_Category)++;
	}

	//print frequency()
	cout << right << setw(13) << "Salary Range: " << endl;//header
	for (int i = 0; i< num_catogaries; i++){
		if (i == num_catogaries-1 ) //last case title
			cout << "$" << i*100+200 << " and over: ";
		else
			cout << right << setw(7) << "$" << i*100+200 << "-" << i*100+299 << ": ";

		for (int j=0; j<frequency.at(i); j++ ){
			cout << '*';
		}
		cout << endl;
	}
}








