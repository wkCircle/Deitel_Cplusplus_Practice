//
//  main.cpp
//  20170518 Chapter 7 Exercises
//
//  Created by ntueconRA on 2017/5/18.
//  Copyright © 2017年 Kai. All rights reserved.
//

#include "../Chapter7_Exercises.hpp"

int main(int argc, const char * argv[]) {

//	//7_10
	const int num_salespeople = ExerCh7_10::getmembers();
	int grosses[num_salespeople];
		//initialize each salesperson's gross sales
	for (int i=0; i<num_salespeople; i++){
		grosses[i] =  rand() % 20000 /2;
	}
	ExerCh7_10 Happiness(grosses);
	Happiness.salespersonSalaryRanges7_10();
//	//7_10
	
	//7.38
	size_t num_salespeople7_38 = ExerCh7_38::getmembers();
	vector<int> grosses7_38(num_salespeople7_38, 0); //30 elements, initialize all entries with value = 0.
	for (int i=0; i<num_salespeople7_38; i++){
		grosses7_38.at(i) =  rand() % 20000 /2;
	}
	ExerCh7_38 Gruß( grosses7_38 );
	Gruß.salespersonSalaryRanges7_38();
	//7.38
	
	ExerCh7 Mouse;
//7_12
	int array_Decreaseing[]={33, 26, 20, 18, 4, 1, -6};
	ExerCh7 Bubble;
	Bubble.bubbleSortAlgorithm7_12(array_Decreaseing, sizeof(array_Decreaseing)/sizeof(array_Decreaseing[0]));
//7_12 END
	Mouse.DuplicateEliminatio7_15();
	Mouse.DiceRolling7_17_and39();
	Mouse.salesSummary7_22();
	Mouse.AirlineReservationsSystem7_20();
	Mouse.TurtleGraphics7_23();
	Mouse.KnightsTour7_24();
	Mouse.EightQueens7_26();
	Mouse.SieveofEratosthenes7_29();
	Mouse.BucketSort7_30();
	Mouse.SelectionSort7_31();
	Mouse.Palindromes7_32();
	Mouse.LinearSearch7_33();
	Mouse.EightQueensRecursive7_34();
	Mouse.printArray7_35();
	Mouse.PrintAStringBackward7_36();
	Mouse.FindMinValInArray7_37_and40();
	
}
