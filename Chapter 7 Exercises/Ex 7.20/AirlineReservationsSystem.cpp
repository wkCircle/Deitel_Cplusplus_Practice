#include "AirlineReservationsSystem.hpp"

inline void AirlineSeatsGraph(bool [], const int);
inline int checkSeatsFull(bool [], const int , long long int & );
void ClassBooking(bool [], const int, long long int &);
void RandomlyBooking(bool [], const int, long long int &);
void AirlineReservationsSystem(){
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
				AirlineSeatsGraph(seats_array, seats);
				break;
			case -1:
				cout << "Thank you for using our service. We hope you have a nice journey. Good Bye.\n";
				return;
		}
	}//end while{}
} //end function 7.20
inline void AirlineSeatsGraph(bool seats_array[], const int arraySize){
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
