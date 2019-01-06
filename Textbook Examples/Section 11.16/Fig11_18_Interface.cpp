// Fig. 11.18: Interface.cpp
// Implementation of class Interface--client receives this file only as precompiled object code, keeping the implementation hidden.
#include "Fig11_16_Implementation.hpp"
#include "Fig11_17_Interface.hpp"


Interface::Interface( int v ): ptr ( new Implementation(v) ){
	//empty
}
Interface::~Interface(){
	delete ptr;
}
void Interface::setValue( int v ){
	ptr->setValue( v );
}
int Interface::getValue() const{
	return ptr->getValue();
}


/**<What I learned:
        1. Constructor��initializer list���Ainitializes ptr to point to a new Implementation object.
        2. user �b�ϥήɲ@�L������ܻP�v�T
        3. Always use 'ptr' to acess original class's "�A��"(member functions)
        4. �Ш�Proxy.hpp�p���C
 */


