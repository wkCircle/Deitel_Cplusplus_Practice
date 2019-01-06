//
//  Chpater8_Exercises.cpp
//  20170607 Chapter 8 Exercises
//
//  Created by ntueconRA on 2017/6/7.
//  Copyright © 2017年 Kai. All rights reserved.
//
//8.18 & 8.19
#include "MachineLanguageProgramming.hpp"

//Determine the sign(+/-) of an argument input.
SML SML; // class instance initialization.
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

void SML::setMemory(const short *memoryPtr, const int &value){
	/*SML private member data accessing, set memory.*/
	int tmp = *memoryPtr;
	if (*memoryPtr < 0)
        tmp *= -1; // equiv. to taking the absolute value.
    memory[tmp] = value;
}
double SML::getMemory(const short *memoryPtr){
    /*SML private member data accessing, get memory.*/
	int tmp = *memoryPtr;
	if (*memoryPtr < 0)
        tmp *= -1; // equiv. to taking the absolute value.
	return memory[tmp];
}
void SML::clearMemory(){
    /*SML private member data accessing, clear memory.*/
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

// Core function
void SML::MachineLanguageProgramming(){
	int flag = 0;
	Helpoperation();
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
			const short int memory = sign(Word) * (Word % 100) ;//in between +/- 00~99.

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
//detailed functions
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
	/*load memory: memory location -> accumulator*/
	SML.setAccumulator( SML.getMemory(memoryPtr) );
}
void LSoperations::store(const short *memoryPtr){
	/*store value: accumulator -> momeory location*/
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