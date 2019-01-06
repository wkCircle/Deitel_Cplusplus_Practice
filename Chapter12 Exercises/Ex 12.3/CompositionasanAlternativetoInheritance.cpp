//Exercise 12.3 inheritance vs composition approach

/**<Base Class Started: CommissionEmployee >**/
#include "CompositionasanAlternativetoInheritance.hpp"

// Fig. 12.23: CommissionEmployee.cpp
// Class CommissionEmployee member-function definitions.
CommissionEmployee::CommissionEmployee( const string &first, const string &last, // constructor
                                        const string &ssn, double sales, double rate )
    : firstName( first ), lastName( last ), socialSecurityNumber( ssn )
{
    setGrossSales( sales ); // validate and store gross sales
    setCommissionRate( rate ); // validate and store commission rate

    cout << "CommissionEmployee constructor: " << endl;
    print();
    cout << "\n\n";
}
CommissionEmployee::~CommissionEmployee() { // destructor
    cout << "CommissionEmployee destructor: " << endl;
    print();
    cout << "\n\n";
}
void CommissionEmployee::setFirstName( const string &first ) {
    firstName = first;
}
string CommissionEmployee::getFirstName() const {
    return firstName;
}
void CommissionEmployee::setLastName( const string &last ) {
    lastName = last;
}
string CommissionEmployee::getLastName() const{
    return lastName;
}
void CommissionEmployee::setSocialSecurityNumber( const string &ssn ) {
    socialSecurityNumber = ssn;
}
string CommissionEmployee::getSocialSecurityNumber() const {
    return socialSecurityNumber;
}
void CommissionEmployee::setGrossSales( double sales ){
    grossSales = ( sales < 0.0 ) ? 0.0 : sales;
}
double CommissionEmployee::getGrossSales() const {
    return grossSales;
}
void CommissionEmployee::setCommissionRate( double rate ){
    commissionRate = ( rate > 0.0 && rate < 1.0 ) ? rate : 0.0;
}
double CommissionEmployee::getCommissionRate() const {
    return commissionRate;
}
double CommissionEmployee::earnings() const { // calculate earnings
    return getCommissionRate() * getGrossSales();
}
void CommissionEmployee::print() const { // print CommissionEmployee object
    cout << "commission employee: " << getFirstName() << ' ' << getLastName()
         << "\nsocial security number: " << getSocialSecurityNumber()
         << "\ngross sales: " << getGrossSales()
         << "\ncommission rate: " << getCommissionRate();
}
/**<Base Class Ended: CommissionEmployee >**/




/**<Case Started: Inheritance approach from textbook>**/
//// Fig. 12.25: BasePlusCommissionEmployee.cpp
//// Class BasePlusCommissionEmployee member-function definitions.
//BasePlusCommissionEmployee::BasePlusCommissionEmployee( const string &first, const string &last, const string &ssn,
//                                                        double sales, double rate, double salary )
//    : CommissionEmployee( first, last, ssn, sales, rate ) // explicitly call base-class constructor
//{
//    setBaseSalary( salary ); // validate and store base salary
//    cout << "BasePlusCommissionEmployee constructor: " << endl;
//    print();
//    cout << "\n\n";
//}
//
//BasePlusCommissionEmployee::~BasePlusCommissionEmployee() {
//    cout << "BasePlusCommissionEmployee destructor: " << endl;
//    print();
//    cout << "\n\n";
//}
//void BasePlusCommissionEmployee::setBaseSalary( double salary ) {
//    baseSalary = ( salary < 0.0 ) ? 0.0 : salary;
//}
//double BasePlusCommissionEmployee::getBaseSalary() const {
//    return baseSalary;
//}
//double BasePlusCommissionEmployee::earnings() const { // calculate earnings
//    return getBaseSalary() + CommissionEmployee::earnings();
//}
//void BasePlusCommissionEmployee::print() const {// print BasePlusCommissionEmployee object
//    cout << "base-salaried ";
//    // invoke CommissionEmployee's print function
//    CommissionEmployee::print();
//    cout << "\nbase salary: " << getBaseSalary();
//}
/**<Case finished: Inheritance approach from textbook>**/
/**<Case started: Composition approach for exercise 12.3, which replaces
   the inheritance method shown in textbook(the above commented code)>**/
BasePlusCommissionEmployee::BasePlusCommissionEmployee( const string &first, const string &last, const string &ssn,
                                                        double sales, double rate, double salary )
    /// ***KEY!*** explicitly initialize CommissionEmployee object by using private pointer
    : employeeObjPtr ( new CommissionEmployee( first, last, ssn, sales, rate ) )
{
    setBaseSalary( salary ); // validate and store base salary
    //one can also initialize baseSalary with initializer list, but that way you can't validate the input data.
    cout << "BasePlusCommissionEmployee constructor: " << endl;
    print();
    cout << "\n\n";
}

BasePlusCommissionEmployee::~BasePlusCommissionEmployee() {
    cout << "BasePlusCommissionEmployee destructor: " << endl;
    print();
    cout << "\n\n";
    /**<Following displays a wrong code: employeeObjPtr = NULL;
       this way won't call the destructor of original class. Instead,
       this makes the pointer points to NuLL, which still occupy some memory>**/
    delete employeeObjPtr; //should appear after print() since it calls employeeObjPtr in its body.
}

void BasePlusCommissionEmployee::setFirstName( const string & first ){
    employeeObjPtr->setFirstName(first);
}
string BasePlusCommissionEmployee::getFirstName() const{
    employeeObjPtr->getFirstName();
}
void BasePlusCommissionEmployee::setLastName( const string & last ){
    employeeObjPtr->setLastName(last);
}
string BasePlusCommissionEmployee::getLastName() const{
    employeeObjPtr->getLastName();
}
void BasePlusCommissionEmployee::setSocialSecurityNumber( const string & ssn){
    employeeObjPtr->setSocialSecurityNumber(ssn);
}
string BasePlusCommissionEmployee::getSocialSecurityNumber() const{
    employeeObjPtr->getSocialSecurityNumber();
}
void BasePlusCommissionEmployee::setGrossSales( double sales){
    employeeObjPtr->setGrossSales(sales);
}
double BasePlusCommissionEmployee::getGrossSales() const{
    employeeObjPtr->getGrossSales();
}
void BasePlusCommissionEmployee::setCommissionRate( double rate){
    employeeObjPtr->setCommissionRate(rate);
}
double BasePlusCommissionEmployee::getCommissionRate() const{
    employeeObjPtr->getCommissionRate();
}
void BasePlusCommissionEmployee::setBaseSalary( double salary ) {
    baseSalary = ( salary < 0.0 ) ? 0.0 : salary;
}
double BasePlusCommissionEmployee::getBaseSalary() const {
    return baseSalary;
}
double BasePlusCommissionEmployee::earnings() const { // calculate earnings
    return getBaseSalary() + employeeObjPtr->earnings();
}
void BasePlusCommissionEmployee::print() const {// print BasePlusCommissionEmployee object
    cout << "base-salaried ";
    // invoke CommissionEmployee's print function
    employeeObjPtr->print();
    cout << "\nbase salary: " << getBaseSalary();
}

/**<Case finished: Composition approach for exercise 12.3>**/
/**<小結: 1. 繼承很複雜，雖然程式碼很簡潔，但是樹狀圖堆疊到兩三層之後就很需要思考到底該怎麼繼承才不會破壞被繼承的類別的封裝性
          2. 組合與繼承皆可達到code reuse的效果，雖說組合相對來講要多寫一點程式碼(詳見.hpp)，但這無傷大雅
          3. 可參考網路說法，現在大部分皆提倡 prefer composition over inheritance
          4. 要注意多重繼承(circle or dimand problem)在C++支援，但在Java並不支援，所以使用上有其限制>**/
