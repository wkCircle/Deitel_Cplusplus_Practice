
#ifndef Shape3D_hpp
#define Shape3D_hpp

#include "Shape.hpp"

class Shape3D: public Shape{
public:
    Shape3D();
    virtual double getArea() const =0;
    virtual double getVolume() const =0;
    virtual void print() const =0;

};


class Pyramid: public Shape3D{
public:
    Pyramid(int, double, double);   // 1: number of vertices at the base; if =0, it means a cone.
                                    // 2: base ceter-to-vertix length 3: pyramid height
    virtual double getArea() const;
    virtual double getVolume() const;
    virtual void print() const;
private:
    int ver;
    double base_rad;
    double height;
};

class Polyhedron: public Shape3D{
public:
    Polyhedron(int, double, double); // 1: number of vertices at the base; if =0, it means a cylinder.
                                    // 2: base ceter-to-vertix length 3: polyhedron height
    virtual double getArea() const;
    virtual double getVolume() const;
    virtual void print() const;
private:
    int ver;
    double base_rad;
    double height;
};

class Ellipsoid: public Shape3D{
public:
    Ellipsoid(double, double, double); // lengths of a,b,c for ellipsoid
    virtual double getArea() const ;
    virtual double getVolume() const;
    virtual void print() const;
private:
    double a;
    double b;
    double c;
};

class Sphere: public Ellipsoid{
public:
    Sphere( double ); //radius
    virtual double getArea() const;
    virtual double getVolume() const;
    virtual void print() const;
private:
    double radius;

};

#endif // Shape3D_hpp
