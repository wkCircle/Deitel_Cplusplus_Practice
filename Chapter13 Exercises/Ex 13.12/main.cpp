// Fig. 13.23: fig13_23.cpp
// Processing Employee derived-class objects individually
// and polymorphically using dynamic binding.
#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
#include "Employee.hpp"
#include "SalariedEmployee.hpp"
#include "HourlyEmployee.hpp"
#include "CommissionEmployee.hpp"
#include "BasePlusCommissionEmployee.hpp"
using namespace std;

// prototypes
void virtualViaPointer( const Employee * const );
void virtualViaReference( const Employee & );
int determineMonth();
double payrollBonus(const Employee * const );
double payrollBonus(const Employee & );


int main()
{
    // set floating-point output formatting
    cout << fixed << setprecision( 2 );
    // create derived-class objects
    SalariedEmployee salariedEmployee( "John", "Smith", "111-11-1111", 1, 1, 1990 , 800 );
    HourlyEmployee hourlyEmployee( "Karen", "Price", "222-22-2222", 2, 2, 1992, 16.75, 40 );
    CommissionEmployee commissionEmployee( "Sue", "Jones", "333-33-3333", 3, 3, 1993, 10000, .06 );
    BasePlusCommissionEmployee basePlusCommissionEmployee( "Bob", "Lewis", "444-44-4444", 4, 4, 2004, 5000, .04, 300 );

    // create vector of four base-class & references
    vector < Employee * > employees( 4 );

    // initialize vector with Employees
    employees[ 0 ] = &salariedEmployee;
    employees[ 1 ] = &hourlyEmployee;
    employees[ 2 ] = &commissionEmployee;
    employees[ 3 ] = &basePlusCommissionEmployee;

    // print current month
    int m = determineMonth();
    cout << "Current local month is: " << m << "\t"<< endl << endl;

    // call virtualViaPointer to print each Employee's information and earnings using dynamic binding
    cout << "Virtual function calls made off base-class pointers:\n\n";
    for ( size_t i = 0; i < employees.size(); i++ )
        virtualViaPointer( employees[ i ] );

    // call virtualViaReference to print each Employee's information and earnings using dynamic binding
    cout << "Virtual function calls made off base-class references:\n\n";
    for ( size_t i = 0; i < employees.size(); i++ )
        virtualViaReference( *employees[ i ] );

} // end main



// call Employee virtual functions print and earnings off a base-class pointer using dynamic binding
void virtualViaPointer( const Employee * const baseClassPtr )
{
    baseClassPtr->print();
    cout << "\nBirth: " << baseClassPtr->getbirthDate() << endl; //note: Date has overloaed operator <<.
    cout << "\nearned $" << baseClassPtr->earnings() + payrollBonus(baseClassPtr)<< "\n\n";
}


// call Employee virtual functions print and earnings off a base-class reference using dynamic binding
void virtualViaReference( const Employee &baseClassRef )
{
    baseClassRef.print();
    cout << "\nBirth: " << baseClassRef.getbirthDate() << endl; //note: Date has overloaed operator <<.
    cout << "\nearned $" << baseClassRef.earnings() + payrollBonus(baseClassRef) << "\n\n";
}

int determineMonth(){
    time_t current_time =  time(0);
    struct tm * tmPtr;

    tmPtr = localtime( & current_time );
    return tmPtr -> tm_mon+1 ;
}

double payrollBonus(const Employee* const birthPtr){
    double bonus = 0;
    if ( determineMonth() == birthPtr->getbirthDate().getMonth() )  bonus = 100;
    return bonus;
}
double payrollBonus(const Employee & birthRef){
    double bonus = 0;
    if ( determineMonth() == birthRef.getbirthDate().getMonth() )  bonus = 100;
    return bonus;
}
