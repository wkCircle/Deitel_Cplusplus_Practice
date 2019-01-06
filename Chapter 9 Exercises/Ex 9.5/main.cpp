#include "ComplexClass.hpp"
int main(){
    complex A(3, -5), B(4,-2), C;
	A.add(B);	A.printcomplex();
	B.subtract(C);	B.printcomplex();
	C.subtract(B);	C.printcomplex();
}
