// Fig. 13.25: fig13_25.cpp
// Demonstrating downcasting and runtime type information.
// NOTE: You may need to enable RTTI on your compiler
// before you can execute this application.
#include <iostream>
#include <iomanip>
#include <vector>
#include <typeinfo>
#include "Employee.hpp"
#include "SalariedEmployee.hpp"
#include "HourlyEmployee.hpp"
#include "CommissionEmployee.hpp"
#include "BasePlusCommissionEmployee.hpp"
using namespace std;
int main()
{
    // set floating-point output formatting
    cout << fixed << setprecision( 2 );

    // create vector of four base-class pointers
    vector < Employee * > employees( 4 );

    // initialize vector with various kinds of Employees
    employees[ 0 ] = new SalariedEmployee( "John", "Smith", "111-11-1111", 800 );
    employees[ 1 ] = new HourlyEmployee( "Karen", "Price", "222-22-2222", 16.75, 40 );
    employees[ 2 ] = new CommissionEmployee( "Sue", "Jones", "333-33-3333", 10000, .06 );
    employees[ 3 ] = new BasePlusCommissionEmployee( "Bob", "Lewis", "444-44-4444", 5000, .04, 300 );

    // polymorphically process each element in vector employees
    for ( size_t i = 0; i < employees.size(); i++ )
    {
        employees[ i ]->print(); // output employee information
        cout << endl;

        // downcast pointer
        BasePlusCommissionEmployee *derivedPtr = dynamic_cast < BasePlusCommissionEmployee * > ( employees[ i ] );

        // determine whether element points to base-salaried
        // commission employee
        if (derivedPtr!=0){
            double oldBaseSalary = derivedPtr -> getBaseSalary();
            cout << "old base salary: $" << oldBaseSalary << endl;
            derivedPtr->setBaseSalary( 1.10 * oldBaseSalary );
            cout << "new base salary with 10% increase is: $" << derivedPtr -> getBaseSalary() << endl;
        }

        cout << "earned $" << employees[ i ]->earnings() << "\n\n";
    } // end for


    // release objects pointed to by vector’s elements
    for ( size_t j = 0; j < employees.size(); j++ )
    {
        // output class name
        cout << "deleting object of " << typeid( *employees[ j ] ).name() << endl;
        delete employees[ j ];
    } // end for
} // end main
