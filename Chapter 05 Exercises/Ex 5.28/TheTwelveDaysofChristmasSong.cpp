#include "TheTwelveDaysofChristmasSong.hpp"

int The12DaysofChristmasSong(){

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
	return 0;
}

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
