//
//  Proxy.hpp
//  20171010 Textbook Examples
//
//  Created by kai on 14/11/2017.
//  Copyright © 2017 Wen-Kai Chung. All rights reserved.
//

#ifndef Proxy_h
#define Proxy_h


// Fig. 11.17: Interface.h
/**< Proxy class Interface definition. >**/
// Client sees this source code, but the source code does not reveal the data layout of class Implementation.
class Implementation;
class Interface {
public:
	Interface( int );
	~Interface();
	void Fig11_16to11_19main();
	 // same public interface as class Implementation has
	void setValue( int );
	int getValue() const;
	
private:
	// requires previous forward declaration (class Implementation;)
	Implementation *ptr;
};
/**<小結: 1. proxy class 好處是可以對user隱藏真正的class Implementation內部的東西
 	2. 不需#include"TextbookExamples.hpp"(class Implementation被宣告的地方)，因為class Interface 是利用pointer指向原始物件，
 	   所以compiler不需找空間做保留，只要在前面加上class Implementation;即可(Line 16)
 	3. User 只會#include"Proxy.hpp"而真正的class都在另外一個.hpp裡頭不會被user看見，所以理想上user並不知道class Implementation的存在 >**/



#endif /* Proxy_h */
