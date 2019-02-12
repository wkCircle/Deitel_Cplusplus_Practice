//
//  20170408 Chapter 3 & 4 Exercises.hpp
//  20170408 Chapter 3 & 4 Exercises
//
//  Created by ntueconRA on 2017/5/15.
//  Copyright © 2017年 Kai. All rights reserved.
//

#ifndef GradeBook_hpp
#define GradeBook_hpp

#include <cstdio>
#include <cmath>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <string>
#include <typeinfo>
using namespace std;




class GradeBook {

public: // access specifier.

	GradeBook(string courseName, string leturerNamesss);			//constructor
	void setCourseName(string); //func that sets the courseName.
	string getCourseName();

	void setLecturerName(string);
	string getLecturerName();

	void determineClassAverage();

	void displayMessage();


private:
	string courseName;
	string lecturerName;

};


#endif // GradeBook_hpp
