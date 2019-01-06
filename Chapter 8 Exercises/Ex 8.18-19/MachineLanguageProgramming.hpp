
//
//  Chpater8_Exercises.hpp
//  20170607 Chapter 8 Exercises
//
//  Created by ntueconRA on 2017/6/7.
//  Copyright © 2017年 Kai. All rights reserved.
//

#ifndef MachineLanguageProgramming_hpp
#define MachineLanguageProgramming_hpp

#include <cstdio>
#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <string>
#include <cstring>
#include <iomanip>
#include <cstdlib>

using namespace std;

//for quesion 8.18 & 8.19
class SML{
public:
	//Main
	void MachineLanguageProgramming();//SML main function.

	void setMemory(const short *memoryPtr, const int &value);
	double getMemory(const short *memoryPtr);
	void clearMemory();

	void setAccumulator(const int &value);
	double getAccumulator();
	void clearAccumulator();
	//Branches
	void IOoperations(const short &operation, const short *memoryPtr);
	void LSoperations(const short &operation, const short *memoryPtr);
	void Arithoperations(const short &operation, const short *memoryPtr);
	void TCoperations(const short &operation, const short *memoryPtr, size_t instrCounter);
	void Helpoperation();
	//Input/output operations
	const int READ = 10;	const int WRITE = 11;
	//Load and store operations //relevent to accumulator.
	const int LOAD = 20;	const int STORE = 21;
	//Arithmetic operations
	const int ADD = 30;		const int SUBTRACT = 31;
	const int DIVIDE = 32;	const int MULTIPLY = 33;
	//Transfer-of-control operations
	const int BRANCH = 40;
	const int BRANCHNEG = 41;
	const int BRANCHZERO = 42;
	const int HALTT = 43;
	//HELP
	const int HELP = 50;
private:
	int memory[100]={};
	int accumulator = 0.0;
};
class IOoperations{
public:
	void read(const short *memoryPtr );
	void write(const short *memoryPtr);
};
class LSoperations{
public:
	void load(const short *memoryPtr);
	void store(const short *memoryPtr);
};
class Arithoperations{
public:
	void add(const short *memoryPtr);
	void subtract(const short *memoryPtr);
	void divide(const short *memoryPtr);
	void multiply(const short *memoryPtr);
};
class TCoperations{
public:
	void branch(const short *memoryPtr, size_t &instrCounter);
	void branchNeg(const short *memoryPtr, size_t &instrCounter);
	void branchZero(const short *memoryPtr, size_t &instrCounter);
	void HALTT();
};
#endif // MachineLanguageProgramming_hpp
