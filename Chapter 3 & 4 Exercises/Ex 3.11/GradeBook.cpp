#include "GradeBook.hpp"

//GradeBook Exercises
GradeBook::GradeBook(string courseName, string lecturerName){
	setCourseName(courseName);
	setLecturerName(lecturerName);
}
void GradeBook::setCourseName(string name){
	if (name.length() <= 25)
		courseName = name;
	else {
		courseName = name.substr(0, 25);	//start at 0, length of 25.
		cout << "Name \"" << name << "\" exceeds max length (25). \n";
		cout << "Limiting course name to first 25 characters. \n";
	}
}
string GradeBook::getCourseName(){
	return courseName;
}
void GradeBook::setLecturerName(string name){
	lecturerName = name;
}
string GradeBook::getLecturerName(){
	return lecturerName;
}
void GradeBook::determineClassAverage(){
	int total=0;
	int gradeCounter=0;
	double grade=0; //if int type, error will occur. (endless loop witout stoping)
	double average=0.00;

	cout << "Please enter grade or -1 to quit.\n";
	cin >> grade;
	while (grade != -1 && grade <0 ){
		cout << "Invalid value. Please in put a score >=0.\n";
		cin >> grade;
	}


	while (grade != -1 ){
		while (grade != -1 && grade <0 ){
			cout << "Invalid value. Please input a score >=0 or -1 to quit.\n";
			cin >> grade;
		}
		if (grade == -1)
			break;

		total += grade;
		gradeCounter += 1;

		cout << "Please enter grade or -1 to quit." <<endl;
		cin >> grade;
	}



	if (gradeCounter != 0){
		// average = total / 10.00;
		//notice that 'total': type int, '10.00': type int.
		// If we replace 10.00 by 10, then total/10 will be int type, which leads to the wrong average answer.
		average  = static_cast<double>(total) / gradeCounter; //cast operator!

		cout << "\nTotal of all " << gradeCounter << " grades entered is " << total << endl;
		cout << "Class average is " << setprecision(2) << fixed << average << endl;
	}
	else
		cout << "No grades were entered" << endl;
}
void GradeBook::displayMessage(){
	cout << "Welcome to the Grade Book for " << courseName << "!" << "\nThis course is presented by " << getLecturerName() << "."<< endl;
}
