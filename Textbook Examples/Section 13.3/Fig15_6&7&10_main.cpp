// For Fig13.1 to Fig13.7 (no virtual case) + For Fig13.8 to Fig13.10 (virtual case)
// (non-virtual) Fig. 13.5: fig13_05.cpp + Fig. 13.6: fig13_6.cpp + Fig. 13.7: fig13_7.cpp || (virtual) Fig. 13.10: fig13_10.cpp
// Aiming base-class and derived-class pointers at base-class and derived-class objects, respectively.
#include "Fig13_3&9_BasePlusCommissionEmployee.hpp"
#include "Fig13_1&8_CommissionEmployee.hpp"

int main(){ //global function
    CommissionEmployee commissionEmployee( "Sue", "Jones", "222-22-2222", 10000, .06 );
    CommissionEmployee *commissionEmployeePtr = 0; /**< base class pointer*/
    BasePlusCommissionEmployee basePlusCommissionEmployee( "Bob", "Lewis", "333-33-3333", 5000, .04, 300 );
    BasePlusCommissionEmployee *basePlusCommissionEmployeePtr = 0; /**< derived-class pointer*/

    // objects calling
    cout << fixed << setprecision( 2 );
    cout << "Print base-class and derived-class objects:\n\n";
    commissionEmployee.print(); // invokes base-class print (static binding)
    cout << "\n\n";
    basePlusCommissionEmployee.print(); // invokes derived-class print (static binding)

    // base-class pointer -> base-class object and print
    commissionEmployeePtr = &commissionEmployee; // natural
    cout << "\n\n\nCalling print with base-class pointer to " << "\nbase-class object invokes base-class print function:\n\n";
    commissionEmployeePtr->print(); // invokes base-class print (dynamic binding)

    // derived-class pointer -> derived-class object and print
    basePlusCommissionEmployeePtr = &basePlusCommissionEmployee; // natural
    cout << "\n\n\nCalling print with derived-class pointer to "
         << "\nderived-class object invokes derived-class " << "print function:\n\n";
    basePlusCommissionEmployeePtr->print(); // invokes derived-class print (dynamic binding)

    // base-class pointer -> derived-class object and print
    commissionEmployeePtr = &basePlusCommissionEmployee; ///***KEY!***
    cout << "\n\n\nCalling print with base-class pointer to "
         << "derived-class object\ninvokes base-class print (if non-virtual)/ derived-class print (if virtual)"
         << "function on that derived-class object:\n\n";
    commissionEmployeePtr->print(); /* invokes base-class print *//**<dynamic binding, polymorphism if virtual case!!!*/
    cout << endl;


    // derived-class pointer -> base-clas object (Ref: Fig13.6)
//    basePlusCommissionEmployeePtr = &commissionEmployee;
    /**< Error, base-class obj is not an obj of derived class; derived-class pointer can only point to lower hierarchy class' obj.*/


    //Following illustrates: base-class pointer CANNOT call the members of the pointed class instance(unless use "virtual")(Ref: Fig13.7)
    //Assume that base-class pointer -> derived-class object
    commissionEmployeePtr = &basePlusCommissionEmployee;
    // case 1: invoke base-class member functions on derived-class object through base-class pointer (allowed)
    string firstName = commissionEmployeePtr->getFirstName();
    string lastName = commissionEmployeePtr->getLastName();
    string ssn = commissionEmployeePtr->getSocialSecurityNumber();
    double grossSales = commissionEmployeePtr->getGrossSales();
    double commissionRate = commissionEmployeePtr->getCommissionRate();
    // case 2: invoke derived-class-only member functions on derived-class object through base-class pointer (disallowed)
//    double baseSalary = commissionEmployeePtr->getBaseSalary();
//    commissionEmployeePtr->setBaseSalary( 500 );
    /**< Error, base-class ptr can only access to base-class member functions, no matther which type of the object it points to.*/

}

/**<What I learned:
    1. base-class ptr 可以指向 derived-class 物件，但derived-class ptr 不可以指回較基層的base-class 物件。
    2. 敘述1等價於: derived-class objects are also base-class objects, but the reverse statment is incorrect.
        (而且你當然也不行把 base-class pointer 指向 derived-class pointer，道理同敘述2)
    3. base-class ptr 不管指向 base- 或 derived-class 物件都好，只要透過該ptr呼叫函數，一律都只看handle type.(即ptr所屬的class)
    如果想改成讓compiler看ptr所指向的物件的type，則需使用 virtual function (down-casting skill)，請解鎖 base-class keyword "virtual"
    4. virtual與non-virtual print的結果差異，請見.hpp 的Comment。
    */
