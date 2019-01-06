#include "Fig11_17_Interface.hpp"

int main(){
	Interface i( 5 ); // create Interface object
	cout << "Interface contains: " << i.getValue() << " before setValue" << endl;
	i.setValue( 10 );
	cout << "Interface contains: " << i.getValue() << " after setValue" << endl;
}


/**<小結: 1. proxy class 好處是可以對user隱藏真正的class Implementation內部的東西
 	2. 不需#include"TextbookExamples.hpp"(class Implementation被宣告的地方)，因為class Interface 是利用pointer指向原始物件，
 	   所以compiler不需找空間做保留，只要在前面加上class Implementation;即可(Line 16)
 	3. User 只會#include"Proxy.hpp"而真正的class都在另外一個.hpp裡頭不會被user看見，所以理想上user並不知道class Implementation的存在 >**/
