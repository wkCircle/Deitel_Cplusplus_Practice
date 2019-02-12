//8.18 & 8.19 Alternative (Following codes are from other people.
//                          https://github.com/am838/CS-2024-C--/tree/master/CS%202024-%20Simpletron)
#include "MachineLanguageProgramming.hpp"

#include <iostream>
#include <string>

using namespace std;

// Main method to begin inputing and executing code.
int main (int argc, char *argv[])
{
	Simpletron comp = Simpletron();

	comp.enterSML();
	comp.execute();

	system("Pause");
}
