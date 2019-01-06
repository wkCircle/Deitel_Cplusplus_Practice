#include "Fig10_10_Date.hpp"
#include "Fig10_12_Employee.hpp"
int main(){
	Date birth( 7, 24, 1949 );
    Date hire( 3, 12, 1988 );
	Employee manager( "Bob", "Blue", birth, hire );
	cout << endl;
	manager.print();
	cout << "\nTest Date constructor with invalid values:\n";
	Date lastDayOff( 14, 35, 1994 ); // invalid month and day
	cout << endl;
}


/**<小結: (Fig10.10-Fig10.14)
 1. member initializer list 出現在constructor的參數之後，前面要加上 ":" 以便跟參數做區隔
 2. Composition技巧: 1個class可以在建構object時，參數裡面放來自其他class的object,
 則compiler會先建構參數內物件，最後才建立原始物件，(其實很自然，因為要建構該物件就必須先建構該物件的data members)。
 3. 如果把member initializer list的關於Date Obj 那兩行都註解掉，則compiler 先建構原始的Date object: birth, hire,
 然後進入Employee::Employee, 看到member initializer list沒有定義，則呼叫default constructor of class Date以建構
 birthDate, hireDate, 這兩個都是class Employee底下的private data member object of type Date, 預設值是1/1/1900,
 所以即使birth, hire 有寫在 定義manager物件的參數裡然後在employee constructor裡面換個代名詞叫做dateOfBirth, dateOfHire，
 但完全沒用到阿~~由此可知 member initializer幫助把 birth, hire 的值，傳遞到dateOfBirth, dateOfHire裏頭。
 4. 承3, 不用member initializer也可以，那就要在constructor body裡面assgin(例如用set function)*/
