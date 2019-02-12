#include "RationalClass.hpp"

int main(){
	Rational Q1(101, -100), Q2(100, -50), Q3(-75, 50), Q4(-3),
			 Q6(100, -101), Q7(50, -100), Q8(-50, 75), Q9(-1,3), Q10(0,3);
    // sample print
    Q1.printFl();
    Q2.printR();
	Rational Q5(3,0); //this will fail: return exit code: 1, which means exis_failaure.
}
