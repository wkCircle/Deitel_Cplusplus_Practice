//8.18 & 8.19 Alternative (Following codes are from other people.
//                          https://github.com/am838/CS-2024-C--/tree/master/CS%202024-%20Simpletron)
#ifndef MachineLanguageProgramming_hpp
#define MachineLanguageProgramming_hpp

#include <iostream>

using namespace std;

const int READ = 10;
const int WRITE = 11;
const int LOAD = 20;
const int STORE = 21;
const int ADD = 30;
const int SUBTRACT = 31;
const int DIVIDE = 32;
const int MULTIPLY = 33;
const int BRANCH = 40;
const int BRANCHNEG = 41;
const int BRANCHZERO = 42;
const int HALT = 43;

// The main class header for the Simpletron class.
class Simpletron
{
public:
	// declares the public functions
	Simpletron();
	void enterSML();
	void execute();
	void SML();

private:
	// declares the member variables
	void error(string);
	void printmem();
	int* memory;
	int accumulator;
	int instructionCounter;
	int operationCode;
	int operand;
	int instructionRegister;
};

#endif // MachineLanguageProgramming_hpp

