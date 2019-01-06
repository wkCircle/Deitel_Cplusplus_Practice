
#ifndef Shape_hpp
#define Shape_hpp

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


class Shape
{
public:
    Shape();
    virtual void print() const =0; // pure virtual function.
    virtual double getArea() const =0;
    virtual double getVolume()const =0;
};


#endif // Shape_hpp
