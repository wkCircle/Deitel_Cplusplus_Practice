#include "Shape.hpp"
#include "Shape2D.hpp"
#include "Shape3D.hpp"

int main(){
    Ellipse     ell(2,3);
    Circle      cir(1);
    Rectangle   rec(8,10);
    Square      squ(10);
    Triangle    tri(4,5);
    Pyramid     pyrNormal(6, 1, 10);
    Pyramid     pyrCone(0, 1, 10);
    Polyhedron  polNormal(6, 1, 10);
    Polyhedron  polCylinder(0, 1, 10);
    Ellipsoid   ell3d(3,4,5);
    Sphere      sph(1);

    // create base class pointers pointingto derived classes' objects.
    vector <Shape *> basePtrVec(11);
    basePtrVec[0] = &ell;
    basePtrVec[1] = &cir;
    basePtrVec[2] = &rec;
    basePtrVec[3] = &squ;
    basePtrVec[4] = &tri;
    basePtrVec[5] = &pyrNormal;
    basePtrVec[6] = &pyrCone;
    basePtrVec[7] = &polNormal;
    basePtrVec[8] = &polCylinder;
    basePtrVec[9] = &ell3d;
    basePtrVec[10]= &sph;


    //print results
    for ( size_t i=0; i < basePtrVec.size(); i++ )
    {
        cout << typeid(*basePtrVec[i]).name() << "'s parameters here: \t";
        basePtrVec[i]->print();
        cout << "Thus, it's area is " << basePtrVec[i] -> getArea() << endl ;
        if (i < 5)
            cout << endl;
        else
            cout << "Furthmore, it's volume is " << basePtrVec[i] -> getVolume() << endl << endl;
    }


}
