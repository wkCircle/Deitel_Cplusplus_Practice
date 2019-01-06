#include "Shape3D.hpp"
static const double pi = 3.14159265358974759;

Shape3D::Shape3D(){
    ;
}


Pyramid::Pyramid(int v, double a, double h)
    : ver(v), base_rad(a), height(h)
{
    ;
}
double Pyramid::getArea() const{
    if (ver != 0)
        return  base_rad * sin(pi/ver) * ( ver * base_rad * cos(pi/ver) + sqrt( height * height + base_rad * base_rad * cos(pi/ver) ) );
    else
        return pi * base_rad * base_rad + pi * height * base_rad;
}
double Pyramid::getVolume() const{
    if (ver != 0)
        return ( height * ver * base_rad * base_rad * sin(pi/ver) * cos(pi/ver) ) / 3.0 ;
    else
        return pi * base_rad * base_rad * height / 3.0;
}
void Pyramid::print() const{
    cout << "no. of vertices: " << ver << " , length from base center to any vertex: " << base_rad
         << " and height = " << height << endl;
}



Polyhedron::Polyhedron(int v, double a, double h)
    : ver(v), base_rad(a), height(h)
{
    ;
}
double Polyhedron::getArea() const{
    if (ver != 0)
        return base_rad * sin(pi/ver) * ver * ( base_rad * cos(pi/ver) + 2 * height );
    else
        return pi * base_rad * base_rad + 2 * pi * base_rad * height;
}
double Polyhedron::getVolume() const{
    if (ver != 0)
        return base_rad * base_rad * sin(pi/ver) * cos(pi/ver) * ver * height;
    else
        return pi * base_rad * base_rad * height;

}
void Polyhedron::print() const{
    cout << "no. of vertices: " << ver << " , length from base center to any vertex: " << base_rad
         << " and height = " << height << endl;
}


Ellipsoid::Ellipsoid(double a, double b, double c)
    : a(a), b(b), c(c)
{
    ;
}
double Ellipsoid::getArea() const {
    double p = 1.6;
    double x = pow(a, p);
    double y = pow(b, p);
    double z = pow(c, p);
    return 4 * pi * pow(    (x*y + y*z + z*x) / 3.0     , 1/p);
}
double Ellipsoid::getVolume() const{
    return 4 * pi * a * b * c / 3.0;
}
void Ellipsoid::print() const {
    cout << " The three axes lengths are: " << a << ", " << b  << ", and " << c << endl;
}



Sphere::Sphere(double r)
    : radius(r), Ellipsoid(r,r,r)
{
    ;
}
double Sphere::getArea() const {
    return Ellipsoid::getArea();
}
double Sphere::getVolume() const {
    return Ellipsoid::getVolume();
}
void Sphere::print() const{
    cout << "The radius is: " << radius << endl;
}
