// Fig. 11.13: Fig11_13.cpp
// Driver for simple class Array.
#include "Fig11_6_Array.hpp"
void outputArray( const Array & ); // prototype

int main(){
	Array integers1( 7 ); // 7-element array
	outputArray( integers1 ); // output Array integers1
	outputArray( 3 ); /**< convert 3 to an object of class Array and output this object's content>**/
}
void outputArray( const Array &arrayToOutput ){
	cout << "The Array received has " << arrayToOutput.getSize()
		 << " elements. The contents are:\n" << arrayToOutput << endl;
}

/**<�p��: 1. outputArray�S��int�����A�ҥHcompiler�ݨ�outputArray(3)�ɡA���hclass Array�ݦ��S��conversion constructor�i�H�ഫint��Array.
          2. �u�n�O�u���@�ӰѼƪ�constructor���i�H�Q����conversion constructor, �ҥH���Ҥ�compiler�۰��ഫ3��Array�h��ña�JoutputArray�㦨�\�ഫ.
          3. �ҥH�Y�ϧڭ̨S������int������outputArray, compiler���M�|�۰��ഫ�A���ɭԧڭ̻ݭn�קK�o�ر��εo�͡A�i�ŧi"explicit"�bconstructor�e��.
 	*/


