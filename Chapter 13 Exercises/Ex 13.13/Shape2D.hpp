
#ifndef Shape2D_hpp
#define Shape2D_hpp

#include "Shape.hpp"

class Shape2D: public Shape{
public:
    Shape2D();
    virtual double getArea() const = 0; // pure virtual function
    virtual double getVolume() const;
    virtual void print() const = 0;

};


class Ellipse: public Shape2D{
public:
    Ellipse(double , double ); //ellipse's semi-major and semi-minor axes
    virtual double getArea() const;
    virtual void print() const;
private:
    double a;
    double b;
};

class Circle: public Ellipse{
public:
    Circle(double);    // circle radius
    virtual double getArea() const;
    virtual void print() const;
private:
    double radius;
};



class Rectangle: public Shape2D{
public:
    Rectangle(double, double); //rectangle's lenght and width
    virtual double getArea() const;
    virtual void print() const;
private:
    double x;
    double y;
};

class Square: public Rectangle{
public:
    Square(double); //square's length
    virtual double getArea() const;
    virtual void print() const;
private:
    double length;
};

class Triangle: public Shape2D{
public:
    Triangle(double, double); // triangle's base side and the height of the corresponding base side.
    virtual double getArea() const;
    virtual void print() const;
private:
    double base;
    double height;
};

#endif // Shape2D_hpp
