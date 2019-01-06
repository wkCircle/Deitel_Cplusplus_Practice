#include "GradeBook.hpp"

int main(){
    GradeBook myGrade("Math101", "Lisa Wu");
    myGrade.displayMessage();
    cout << myGrade.getCourseName() << endl;
    cout << myGrade.getLecturerName() << endl;
    myGrade.determineClassAverage();
}
