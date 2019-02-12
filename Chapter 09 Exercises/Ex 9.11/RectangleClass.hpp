#ifndef RectangleClass_hpp
#define RectangleClass_hpp

#include <cstdio>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;


class Rectangle {
public:
	Rectangle( double =1, double =1 );
	Rectangle( double =0, double =0, double =1, double =0, double =0, double =1, double =1, double =1);
	void setLength( double * );
	void setWidth( double * );

	double getLength();
	double getWidth();

	double perimeter();
	double area();
private:

	bool isOutOfRange();
	bool isCommonLine();
	int typeDetermine();
	void AutoComputeLengthAndWidth(const int * const);
	double length=0;
	double width=0;
	double x1=0, y1=0, x2=0, y2=0, x3=0, y3=0, x4=0, y4=0;
};

#endif // RectangleClass_hpp
