#include "Shape2D.hpp"
static const double pi = 3.14159265358974759;

Shape2D::Shape2D()
{
    ;
}
double Shape2D::getVolume() const{
    ;
}

Ellipse::Ellipse(double a, double b)
    : a(a), b(b)
{
    ;
}
double Ellipse::getArea() const {
    return pi*a*b;
}

void Ellipse::print() const{
    cout << "semi-major and semi-minor axes are: " << a << " and " << b << endl;
}



Circle::Circle(double r)
    : radius(r), Ellipse(r, r)
{
    ;
}

double Circle::getArea() const {
    return Ellipse::getArea();
}

void Circle::print() const{
    cout << "radius is: " << radius << endl;
}



Rectangle::Rectangle(double x, double y )
    : x(x), y(y)
{
    ;
}

double Rectangle::getArea() const{
    return x*y;
}

void Rectangle::print() const{
    cout << "the length and width are: " << x << " and " << y << endl;
}



Square::Square( double x )
    : length(x), Rectangle(x, x)
{
    ;
}

double Square::getArea() const{
    return Rectangle::getArea();
}

void Square::print() const {
    cout << "the length is: " << length << endl;
}



Triangle::Triangle(double x, double h)
    : base(x), height(h)
{
    ;
}

double Triangle::getArea() const{
    return 0.5 * base * height;
}

void Triangle::print() const {
    cout << " the base-length and heigth are: " << base << " and " << height << endl;
}
