//
//  Chapter7_Exercises.hpp
//  20170518 Chapter 7 Exercises
//
//  Created by ntueconRA on 2017/5/18.
//  Copyright © 2017年 Kai. All rights reserved.
//

#ifndef Chapter7_Exercises_hpp
#define Chapter7_Exercises_hpp

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

class ExerCh7 {
public:
	void bubbleSortAlgorithm7_12(int [], int inputSize);
	void DuplicateEliminatio7_15();
	void DiceRolling7_17_and39();
	void AirlineReservationsSystem7_20();
	void salesSummary7_22();
	void TurtleGraphics7_23();
	void KnightsTour7_24();
	void EightQueens7_26();
	void SieveofEratosthenes7_29();
	void BucketSort7_30();
	void SelectionSort7_31();
	void Palindromes7_32();
	void LinearSearch7_33();
	void EightQueensRecursive7_34();
	void printArray7_35();
	void PrintAStringBackward7_36();
	void FindMinValInArray7_37_and40();
};

class ExerCh7_38 { //similar to ExerCh7_10 but use 'vector' to solve question.
public:
	ExerCh7_38( vector<int> & );
	static int getmembers(){
		return members7_38;
	}
	void setGrossesOfSalesperson ( vector<int> & );
	void salespersonSalaryRanges7_38();
	
private:
	const static int members7_38 = 30;
	vector<int> grosses7_38; //初始長度=0
	
};


class ExerCh7_10 {
public:
	ExerCh7_10(int []); //constructor
	const static int getmembers();
	void setGrossesOfSalesperson(int []);
	void salespersonSalaryRanges7_10();
	
private:
	const static int members7_10 = 30;
	int grosses7_10[members7_10]; //cannot be declared as static???
};

#endif /* Chapter7_Exercises_hpp */
