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

/**<小結: 1. outputArray沒有int版本，所以compiler看到outputArray(3)時，先去class Array看有沒有conversion constructor可以轉換int到Array.
          2. 只要是只有一個參數的constructor都可以被視為conversion constructor, 所以此例中compiler自動轉換3到Array去～並帶入outputArray～成功轉換.
          3. 所以即使我們沒有提供int版本的outputArray, compiler仍然會自動轉換，有時候我們需要避免這種情形發生，可宣告"explicit"在constructor前面.
 	*/


