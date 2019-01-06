// Fig. 11.9: Date.h
// Date class definition with overloaded increment operators.
#ifndef DATE_HPP
#define DATE_HPP
#include <iostream>
using namespace std;

class Date
{
    friend ostream &operator<<( ostream &, const Date & );
public:
    Date( int m = 1, int d = 1, int y = 1900 ); // default constructor
    void setDate( int, int, int );


    int getMonth();


    Date &operator++(); // prefix increment operator
    Date operator++( int ); // postfix increment operator
    const Date &operator+=( int ); // add days, modify object

    static bool leapYear( int ); // is date in a leap year?
    bool endOfMonth( int ) const; // is date at the end of month?

private:
    int month;
    int day;
    int year;
    static const int days[]; // array of days per month
    void helpIncrement(); // utility function for incrementing date
}; // end class Date

#endif // DATE_HPP
