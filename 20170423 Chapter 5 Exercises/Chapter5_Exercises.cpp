//
//  Chapter5_Exercises.cpp
//  20170423 Chapter 5 Exercises
//
//  Created by ntueconRA on 2017/5/15.
//  Copyright © 2017年 Kai. All rights reserved.
//

#include "Chapter5_Exercises.hpp"

int ExerCh5::SummingIntegers5_5(){
	int howmanyNumbers=0, seqNum=0, total=0;
	cout << "Please input how many integers you want to sum.\n";
	cin >> howmanyNumbers;
	
	for (int count=1; count<=howmanyNumbers; count++){
		cout << "input an integer. \n";
		cin >> seqNum;
		total += seqNum;
	}
	
	return total;
}
int ExerCh5::AveragingIntegers5_6(){
	double average=0.0;
	int seqNum=0, count=0;
	
	for (; seqNum != 9999; ){
		cout << "Input a number to be averaged or enter 9999 to quit.\n";
		cin >> seqNum;
		if (seqNum==9999)
			break;
		
		average = ( (static_cast<double>(average) * count) + seqNum )/ (count+1);
		count++;
	}
	cout << average << endl;
	return average;
}
int ExerCh5::FindtheSmallestInteger5_8(){
	int howmanynumbers=0, seqNum=0, smallest=0;
	cout << "Input a number to specify how many integers you're gonna input to comapre to find the smallest value.\n";
	cin >> howmanynumbers;
	
	//	cout << "Input a number.\n";
	//	cin >> seqNum;
	//	smallest = seqNum;
	for (int count =1; count <= howmanynumbers; count++ ){
		cout << "Input a number.\n";
		cin >> seqNum;
		if (count==1)
			smallest = seqNum;
		
		smallest = min(smallest, seqNum);
	}
	return smallest;
}
int ExerCh5::ProductofOddInteger5_9(){
	for (int x=1; x<=15; x+=2){
		for (int y=1; y<=15; y+=2){
			cout << x*y << "\t";
		}
		cout << endl;
	}
	return 0;
}
int ExerCh5::DrawingPatternswithNestedforLoops5_12(){
	//	//case a)
	//	for (int i=1; i<=10; i++){
	//		for (int j=1; j<=i; j++){
	//			cout << '*';
	//		}
	//		cout << endl;
	//	}
	//	//case b)
	//	for (int i=1; i<=10; i++){
	//		for (int j=10; j>=i; j--){
	//			cout << '*';
	//		}
	//		cout << endl;
	//	}
	//	//case c)
	//	for (int i=1; i<=10; i++){
	//		for (int j=1; j<=10; j++){
	//			if (j>=i){
	//				cout << '*';
	//			}
	//			else
	//				cout << ' ';
	//		}
	//		cout << endl;
	//	}
	//	//case d)
	//	for (int i=1; i<=10; i++){
	//		for (int j=10; j>=1; j--){
	//			if (j>=i-1){
	//				cout << ' ';
	//			}
	//			else
	//				cout << '*';
	//		}
	//		cout << endl;
	//	}
	
	//For extra credit
	for (int i=1; i<=10; i++) {
		for (int j=1; j<=10; j++) {
			if (j<=i)
				cout << '*';
			else
				cout << ' ';
		}
		
		
		for (int j=10; j>=1; j--) {
			if (j>=i)
				cout << '*';
			else
				cout << ' ';
		}
		
		
		for (int j=1; j<=10; j++){
			if (j<=i-1)
				cout << ' ';
			else
				cout << '*';
		}
		
		
		for (int j=10; j>=1; j--){
			if (j>=i+1)
				cout << ' ';
			else
				cout << '*';
		}
		cout << endl;
	}
	return 0;
}
int ExerCh5::BarChart5_13(){
	int Num[5];
	cout << "Input five numbers(0~99) with white spaces among each number.\n";
	
	for (int i=0; i<=4; i++){
		
		cin >> setw(2) >> Num[i];
		
		for( int count = 0; count <= Num[i]-1; count++){
			cout << '*';
		}
		cout << endl;
	}
	return 0;
}
int ExerCh5::CalculatingTotalSales5_14(){
	int numbering=0, quantity=0;
	double Rprice=0, total=0;
	
	while (numbering != -1){
		cout << "Input the product number and its quantity sold, or -1 to quit.\n";
		cin >> numbering;
		if (numbering == -1)
			break;
		cin >> quantity;
		switch (numbering){
			case 1:
				Rprice = 2.98;
				break;
			case 2:
				Rprice = 4.50;
				break;
			case 3:
				Rprice = 9.98;
				break;
			case 4:
				Rprice = 4.49;
				break;
			case 5:
				Rprice = 6.87;
				break;
		}
		
		total += (Rprice * quantity);
		cout << "The total retail value as far is " << total << endl;
	}
	return 0;
}
int ExerCh5::NumberSystemsTable5_18(){
	
	for(int group=1; group <=256; group+=10 ){
		int Num = group;
		int i = 0; //for loop 專用
		int copyNum=0, count=0;
		
		//decimal
		cout << "decimal: \t";
		for ( i = 0; i <= 9; i++){
			if(Num>256)
				break;
			
			cout << Num << "\t";
			Num++;
		}
		cout << endl;
		
		
		//to octal
		cout << "octal: \t";
		Num=group;
		for ( i = 0; i <= 9; i++){
			int toOctal=0;
			copyNum=0, count=0;
			if (Num>256)
				break;
			
			copyNum = Num;
			while (copyNum != 0){
				toOctal += (copyNum % 8) * pow(10, count);
				copyNum /= 8;
				count++;
			}
			
			cout << toOctal << "\t";
			Num++;
		}
		cout << endl;
		
		
		//to Hexidecimal
		cout << "Hexideci\t";
		Num = group;
		const string alpha = "0123456789ABCDEF";
		
		for ( i = 0; i <= 9; i++){
			int rema = 0;
			string rema_Str = "";
			string toHexidecimal = "";
			
			copyNum = 0, count = 0;
			if (Num>256)
				break;
			
			copyNum = Num;
			while (copyNum != 0){
				rema = (copyNum % 16);
				
				switch (rema) {
					case 0:
						rema_Str = '0';
						break;
					case 1:
						rema_Str = '1';
						break;
					case 2:
						rema_Str = '2';
						break;
					case 3:
						rema_Str = '3';
						break;
					case 4:
						rema_Str = '4';
						break;
					case 5:
						rema_Str = '5';
						break;
					case 6:
						rema_Str = '6';
						break;
					case 7:
						rema_Str = '7';
						break;
					case 8:
						rema_Str = '8';
						break;
					case 9:
						rema_Str = '9';
						break;
					case 10:
						rema_Str = 'A';
						break;
					case 11:
						rema_Str = 'B';
						break;
					case 12:
						rema_Str = 'C';
						break;
					case 13:
						rema_Str = 'D';
						break;
					case 14:
						rema_Str = 'E';
						break;
					case 15:
						rema_Str = 'F';
						break;
				} //對照 rema_Str.
				
				
				toHexidecimal = rema_Str + toHexidecimal; //stacking.
				copyNum /= 16;
			}
			cout << toHexidecimal << "\t";
			Num++;
		}
		cout << endl << endl;
		
		
	}
	
	
	return 0;
}
int ExerCh5::CalculatingPi5_19(){
	double Pi = 0.0;
	
	for (int i=1; i<=100000; i++){
		
		if ( i % 2 == 0)
			Pi -= (4.0 / ( 2 * i - 1)) ;
		else
			Pi += (4.0 / ( 2 * i - 1)) ;
		if ( i % 1000 ==0)
			cout << setprecision(10)<< fixed << "The " << i << " terms approximation of pi is: " <<  Pi << endl;
		//到第10萬項才精準到3.1415'8'26536, 到100萬項才精準到3.14159'1'6536
	}
	
	return 0;
	
}
int ExerCh5::PythagoreanTriples5_20(){
	int side1 = 0, side2 = 0, hypotenus = 0, count = 0;
	
	for (side1 = 1; side1 <= 500; side1++){
		for ( side2 = side1; side2 <= 500; side2++){
			for (hypotenus = side2; hypotenus <= 500; hypotenus++){
				
				if (side1*side1 + side2*side2 == hypotenus*hypotenus){
					count++;
					
					string str="";
					switch (count) {
						case 1:
							str = "st";
							break;
						case 2:
							str = "nd";
							break;
						case 3:
							str = "rd";
						default:
							str = "th";
							break;
					}
					
					cout << "The " << count << str << " right triangle is: " << side1 << ',' << side2 << ',' << hypotenus << endl;
				}
				
				
				
			}
		}
		
	}
	
	
	return 0;
}
int ExerCh5::DiamondofAsterisks5_23(){
	
	for (int i=1; i<=9; i++){
		for (int j=1; j<=9; j++){
			
			if (i<=5){
				if (j <= 5-i || j >= 5+i)
					cout << " ";
				else
					cout << "*";
			}
			else {
				if (j <= i-5 || j >= 15-i)
					cout << " ";
				else
					cout << "*";
			}
			
		}
		cout << endl;
	}
	return 0;
	
}
int ExerCh5::DiamondofAsterisks5_24(){
	int row=0;
	while (true){
		
		cout << "Input an odd number btw 1-19 to specify the number of rows in the diamond you want to display.(Or -1 to quit.\n";
		cin >> row;
		if (row == -1 )
			return 0;
		
		while (row <= 0 || row>=20 || row%2 != 1){
			cout << "Invalid input value.\n";
			cin >> row;
			
			if ( row == -1)
				return 0;
		}
		
		for (int i=1; i<=row; i++){
			for (int j=1; j<=row; j++){
				
				if (i <= (row+1)/2 ){
					if ( j <= (row+1)/2 -i  ||  j >= (row+1)/2 + i )
						cout << " ";
					else
						cout << "*";
				}
				else {
					if ( j <= i- (row+1)/2 || j >= 3*(row+1)/2 -i   )
						cout << " ";
					else
						cout << "*";
				}
				
			}
			cout << endl;
			
		}
	}
	
	return 0;
}
int ExerCh5::The12DaysofChristmasSong5_28(){
	
	string strDay="";
	string rePeat="", keyWord="";
	
	for (int i = 1; i <= 12; i++){
		switch (i){
			case 1:
				strDay = "first";
				keyWord = "A Partridge in a Pear Tree\n";
				break;
			case 2:
				strDay = "second";
				keyWord = "Two Turtle Doves\n";
				break;
			case 3:
				strDay = "third";
				keyWord = "Three French Hens\n";
				break;
			case 4:
				strDay = "fourth";
				keyWord = "Four Calling Birds\n";
				break;
			case 5:
				strDay = "fifth";
				keyWord = "Five Golden Rings\n";
				break;
			case 6:
				strDay = "sixth";
				keyWord = "Six Geese a Laying\n";
				break;
			case 7:
				strDay = "seventh";
				keyWord = "Seven Swans a Swimming\n";
				break;
			case 8:
				strDay = "eighth";
				keyWord = "Eight Maids a Milking\n";
				break;
			case 9:
				strDay = "ninth";
				keyWord = "Nine Ladies Dancing\n";
				break;
			case 10:
				strDay = "tenth";
				keyWord = "Ten Lords a Leaping\n";
				break;
			case 11:
				strDay =  "eleventh";
				keyWord = "Eleven Pipers Piping\n";
				break;
			case 12:
				strDay = "twelefth";
				keyWord = "Twelf Drummers Drumming\n";
		} //strDay and keyWord values determination
		//Title
		cout << "On the " << strDay << " day of Christmas\n" << "My true love sent to me: \n";
		
		//Repetition
		
		rePeat = keyWord + rePeat;
		cout << rePeat << endl;
		
	}//end for
	
	
	
	//	On the first day of Christmas
	//	my true love sent to me:
	//	A Partridge in a Pear Tree
	//
	//	On the second day of Christmas
	//	my true love sent to me:
	//	Two Turtle Doves
	//	and a Partridge in a Pear Tree
	//
	//	On the third day of Christmas
	//	my true love sent to me:
	//	Three French Hens
	//	Two Turtle Doves
	//	and a Partridge in a Pear Tree
	//
	//	On the fourth day of Christmas
	//	my true love sent to me:
	//	Four Calling Birds
	//	Three French Hens
	//	Two Turtle Doves
	//	and a Partridge in a Pear Tree
	//
	//	On the fifth day of Christmas
	//	my true love sent to me:
	//	Five Golden Rings
	//	Four Calling Birds
	//	Three French Hens
	//	Two Turtle Doves
	//	and a Partridge in a Pear Tree2
	//
	//	On the sixth day of Christmas
	//	my true love sent to me:
	//	Six Geese a Laying
	//	Five Golden Rings
	//	Four Calling Birds
	//	Three French Hens
	//	Two Turtle Doves
	//	and a Partridge in a Pear Tree
	//
	//	On the seventh day of Christmas
	//	my true love sent to me:
	//	Seven Swans a Swimming
	//	Six Geese a Laying
	//	Five Golden Rings
	//	Four Calling Birds
	//	Three French Hens
	//	Two Turtle Doves
	//	and a Partridge in a Pear Tree
	//
	//	On the eighth day of Christmas
	//	my true love sent to me:
	//	Eight Maids a Milking
	//	Seven Swans a Swimming
	//	Six Geese a Laying
	//	Five Golden Rings
	//	Four Calling Birds
	//	Three French Hens
	//	Two Turtle Doves
	//	and a Partridge in a Pear Tree
	//
	//	On the ninth day of Christmas
	//	my true love sent to me:
	//	Nine Ladies Dancing
	//	Eight Maids a Milking
	//	Seven Swans a Swimming
	//	Six Geese a Laying
	//	Five Golden Rings
	//	Four Calling Birds
	//	Three French Hens
	//	Two Turtle Doves
	//	and a Partridge in a Pear Tree
	//
	//	On the tenth day of Christmas
	//	my true love sent to me:
	//	Ten Lords a Leaping
	//	Nine Ladies Dancing
	//	Eight Maids a Milking
	//	Seven Swans a Swimming
	//	Six Geese a Laying
	//	Five Golden Rings
	//	Four Calling Birds
	//	Three French Hens
	//	Two Turtle Doves
	//	and a Partridge in a Pear Tree
	//
	//	On the eleventh day of Christmas
	//	my true love sent to me:
	//	Eleven Pipers Piping
	//	Ten Lords a Leaping
	//	Nine Ladies Dancing
	//	Eight Maids a Milking
	//	Seven Swans a Swimming
	//	Six Geese a Laying
	//	Five Golden Rings
	//	Four Calling Birds
	//	Three French Hens
	//	Two Turtle Doves
	//	and a Partridge in a Pear Tree
	//
	//	On the twelfth day of Christmas
	//	my true love sent to me:
	//	Twelf Drummers Drumming
	//	Eleven Pipers Piping
	//	Ten Lords a Leaping
	//	Nine Ladies Dancing
	//	Eight Maids a Milking
	//	Seven Swans a Swimming
	//	Six Geese a Laying
	//	Five Golden Rings
	//	Four Calling Birds
	//	Three French Hens
	//	Two Turtle Doves
	//	and a Partridge in a Pear Tree
	return 0;
}
