// Fig. 13.3: BasePlusCommissionEmployee.h (non-virtual) + Fig. 13.9 (virtual version)
// BasePlusCommissionEmployee class derived from classvCommissionEmployee.
#ifndef BASEPLUS_H
#define BASEPLUS_H

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <typeinfo>
#include <ctime>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
#include "Fig13_1&8_CommissionEmployee.hpp" // CommissionEmployee class declaration

class BasePlusCommissionEmployee : public CommissionEmployee
{
public:
    BasePlusCommissionEmployee( const string &, const string &, const string &, double = 0.0, double = 0.0, double = 0.0 );

    void setBaseSalary( double );
    double getBaseSalary() const;

    //Implicitly becomes virtual function if base-class function is virtual.
    double earnings() const;
    void print() const; // print BasePlusCommissionEmployee object
private:
    double baseSalary;
};


#endif /*BASEPLUS_H*/
/**<結果差異: 如果更換為virtual version的話，執行結果應為 base-class ptr 指向 dervied-class obj 的case會從
    多個 "base-salaried" commission employee: Bob Lewis
    以及多一行 "base salary: 300.00"*/
