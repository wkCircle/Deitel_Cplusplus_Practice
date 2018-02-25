//
//  main.cpp
//  20170617 Chapter 9 Exercises
//
//  Created by ntueconRA on 2017/6/17.
//  Copyright © 2017年 Kai. All rights reserved.
//

#include "Chapter9_Exercises.hpp"

int main(int argc, const char * argv[]) {
	
	Time9_4 vier;
	
	complex A(3, -5), B(4,-2), C;
	A.add(B);	A.printcomplex();
	B.subtract(C);	B.printcomplex();
	C.subtract(B);	C.printcomplex();
	
	Rational Q1(101, -100), Q2(100, -50), Q3(-75, 50), Q4(-3),
			 Q6(100, -101), Q7(50, -100), Q8(-50, 75), Q9(-1,3), Q10(0,3);
	Rational Q5(3,0); //return exit code: 1, which means exis_failaure.
	
	Time kukunsUhr;
	kukunsUhr.Fig9_8to9_10main();
	Date bubunUhr;
	bubunUhr.Fig9_17to9_19main();
	DateAndTime bukubunkuUhr;
	bukubunkuUhr.DATmain();
	Rectangle dirac(2,4,4,2,2,0,0,2);
	
	

	
	
}
