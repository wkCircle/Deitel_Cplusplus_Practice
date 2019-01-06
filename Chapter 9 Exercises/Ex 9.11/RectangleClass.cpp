#include "RectangleClass.hpp"

//Question 9.11
Rectangle::Rectangle( double L, double W ){
	setLength(&L);
	setWidth(&W);
}
Rectangle::Rectangle( double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4){
	Rectangle::x1 = x1;
	Rectangle::y1 = y1;
	Rectangle::x2 = x2;
	Rectangle::y2 = y2;
	Rectangle::x3 = x3;
	Rectangle::y3 = y3;
	Rectangle::x4 = x4;
	Rectangle::y4 = y4;

	if ( isOutOfRange() ){
		cout << "coordinates are out of range(>20.0). Sytstem excution terminated.\n";
		exit(EXIT_FAILURE);
	}

	int type = typeDetermine();
	if ( isCommonLine() || type == -1  ){
		cout << "Not a Rectangle. Sytstem excution terminated.\n";
		exit(EXIT_FAILURE);
	}

	AutoComputeLengthAndWidth(&type);

}
void Rectangle::setLength( double *Lptr ){
	if ( 0.0 < *Lptr && *Lptr < 20)
		length = *Lptr;
	else {
		length = 1;
		cout << "Invalid input for length, defaulted to be 1;";
	}
}
void Rectangle::setWidth( double *Wptr ){
	if ( 0.0 < *Wptr && *Wptr < 20)
		width = *Wptr;
	else {
		width = 1;
		cout << "Invalid input for width, defaulted to be 1;";
	}
}

double Rectangle::getLength(){
	return length;
}
double Rectangle::getWidth(){
	return width;
}
double Rectangle::perimeter(){
	return (length+width)*2;
}
double Rectangle::area(){
	return (length*width);
}
bool Rectangle::isOutOfRange(){
	if ( 0.0 <= x1 && 0.0 <= y1 && 0.0 <= x2 && 0.0 <= y2 &&
		 0.0 <= x3 && 0.0 <= y3 && 0.0 <= x4 && 0.0 <= y4 &&
		 20.0 >= x1 && 20.0 >= y1 && 20.0 >= x2 && 20.0 >= y2 &&
		 20.0 >= x3 && 20.0 >= y3 && 20.0 >= x4 && 20.0 >= y4)
		return false;
	else
		return true;
}
bool Rectangle::isCommonLine(){ //只判斷前3點即可, 第四點則透過前3點定位, 只有3個位置有可能
	return (  (x2-x1)*(y3-y1) == (x3-x1)*(y2-y1)  );
}
int Rectangle::typeDetermine(){ //returns true if it's not a rectangle.
	int type = 0;
	if ( x4 == x1 + (x3 - x2) && y4 == y1 + (y3 - y2) ) //math skill: 用這種寫法可確保3個位子被分辨出來, 按順時鐘或逆時鐘轉
		type = 1;
	else if ( x4 == x2 + (x1 -x3) && y4 == y2 + (y1 - y3) )
		type = 2;
	else if ( x4 == x3 + (x2 - x1) && y4 == y3 + (y2 - y1) )
		type = 3;
	else
		type = -1;
	return type;
}
void Rectangle::AutoComputeLengthAndWidth(const int * const typePtr){
	switch (*typePtr){
		//math skill: 看回typeDetermine(), 如果是type i, 可發現是以 (xi, yi)為基準點做向量加減, 故下列算是也以該點為基準被加減
		case 1:
			length = sqrt( pow( x4-x1, 2) + pow( y4-y1, 2));
			width  = sqrt( pow( x2-x1, 2) + pow( y2-y1, 2));
			break;
		case 2:
			length = sqrt( pow( x4-x2, 2) + pow( y4-y2, 2));
			width  = sqrt( pow( x3-x2, 2) + pow( y3-y2, 2));
			break;
		case 3:
			length = sqrt( pow( x1-x3, 2) + pow( y1-y3, 2));
			width  = sqrt( pow( x4-x3, 2) + pow( y4-y3, 2));
			break;
	}
}
//end of Question 9.11
