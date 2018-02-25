

#include "Chapter12_Exercises.hpp"

/**<以下是Exercise 12.3中所要求的 inheritance vs composition approach>**/

/**<Base Class Started: CommissionEmployee >**/
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
/**<Case started: Composition approach for exercise 12.3>**/
BasePlusCommissionEmployee::BasePlusCommissionEmployee( const string &first, const string &last, const string &ssn,
                                                        double sales, double rate, double salary )
    // 重點!!explicitly initialize CommissionEmployee object by using private pointer
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
    /**<下列寫法是錯的: employeeObjPtr = NULL; 該寫法並不會呼叫原始class的destructor，而只是把指標指向空而已，仍然佔用記憶體>**/
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







//Ex 12.9
//base class functions
Package::Package(string name_s, string addr_s, string city_s, string state_s, string ZIP_s,
                 string name_r, string addr_r, string city_r, string state_r, string ZIP_r,
                 double w, double c)
    :name_sender(name_s), address_sender(addr_s), city_sender(city_s), state_sender(state_s), ZIP_sender(ZIP_s),
     name_recipient(name_r), address_recipient(addr_r), city_recipient(city_r), state_recipient(state_r), ZIP_recipient(ZIP_r)
{
    validationAndSet(w, c);

    cout << "Package constructor: " << endl;
    print();
    cout << "\n\n";
}
Package::~Package(){
    cout << "Package destructor: " << endl;
    print();
    cout << "\n\n";
}
double Package::calculateCost(){
    return weight*costPerOunce;
}
void Package::setInfo(Argument para, string input, string id){
    switch(para){
        case 0: //name
            (id == "s")? name_sender=input : name_recipient=input;
            break;
        case 1: //address
            (id == "s")? address_sender=input : address_recipient=input;
            break;
        case 2: //city
            (id == "s")? city_sender=input : city_recipient=input;
            break;
        case 3: //state
            (id == "s")? state_sender=input : state_recipient=input;
            break;
        case 4: //ZIP
            (id == "s")? ZIP_sender=input : ZIP_recipient=input;
            break;
        default: //otherwise...
            cout << "invalid argument (1st), please check the spelling.\n";
    }
}
void Package::validationAndSet(double &w , double &c){
    if( w < 0){
        cout << "invalid value for weight, set to 1 ounce.\n";
        weight = 1;
    }
    else weight = w;
    if (c < 0){
        cout << "invalid value for cost, set to 10 dollars.\n";
        costPerOunce = 10;
    }
    else costPerOunce = c;
}
double Package::getWeight(){
    return weight;
}
double Package::getCostPerOunce(){
    return costPerOunce;
}
void Package::printPrice(){
    cout << calculateCost() << endl;
}
void Package::print(){
    cout << "Sender: " << address_sender << ", " << city_sender << ", "
         << state_sender << ", " << ZIP_sender <<". " << name_sender <<endl;
    cout << "Recipient: " << address_recipient << ", " << city_recipient << ", "
         << state_recipient << ", " << ZIP_recipient <<". " << name_recipient <<endl;
    cout << "Package weight: \t" << setw(5) << right << weight << endl
         << "Package cost /ounce: \t" << setw(5) << right << costPerOunce << endl << endl;
}
//Derived class TwoDayPackage
TwoDayPackage::TwoDayPackage(string name_s, string addr_s, string city_s, string state_s, string ZIP_s,
                             string name_r, string addr_r, string city_r, string state_r, string ZIP_r,
                             double w, double c, double f_Fee)
    :Package(name_s, addr_s, city_s, state_s, ZIP_s, name_r, addr_r, city_r, state_r, ZIP_r,
             w, c)
{
    validationAndSet(f_Fee);

    cout << "TwoDayPackage constructor: " << endl;
    Package::print();
    cout << "Flat Fee: \t" << setw(5) << right << flatFee << endl;
    cout << "\n\n";
}
TwoDayPackage::~TwoDayPackage(){
    cout << "TwoDayPackage destructor: " << endl;
    print();
    cout << "\n\n";
}
void TwoDayPackage::validationAndSet(double &charge){
    if (charge < 0){
        cout << "invalid value for fixed fee, set to 3 dollar.\n";
        flatFee = 3;
    }
    else flatFee = charge;
}
double TwoDayPackage::calculateCost(){
    return ( this->flatFee + Package::calculateCost() );
}
void TwoDayPackage::printPriceTwoDay(){
    cout << calculateCost() << endl;
}
//Derived class OvernightPackage
OvernightPackage::OvernightPackage(string name_s, string addr_s, string city_s, string state_s, string ZIP_s,
                                   string name_r, string addr_r, string city_r, string state_r, string ZIP_r,
                                   double w, double c, double ex_Fee)
    :Package(name_s, addr_s, city_s, state_s, ZIP_s, name_r, addr_r, city_r, state_r, ZIP_r,
             w, c)
{
    validationAndSet(ex_Fee);

    cout << "TwoDayPackage constructor: " << endl;
    Package::print();
    cout << "Extra Fee per ounce: \t" << setw(5) << right << extraFee << endl;
    cout << "\n\n";
}
OvernightPackage::~OvernightPackage(){
    cout << "OvernightPackage destructor: " << endl;
    print();
    cout << "\n\n";
}
void OvernightPackage::validationAndSet( double & charge){
    if (charge < 0){
        cout << "invalid value for extra fee, set to 1 dollar.\n";
        extraFee = 1;
    }
    else extraFee = charge;
}
double OvernightPackage::calculateCost(){
    return ( ( Package::getWeight() + this->extraFee) * Package::getCostPerOunce() );
}
void OvernightPackage::printPriceOvernight(){
    cout << calculateCost() << endl;
}







//Ex 12.10
//Base class Account's member functions
Account::Account( double money): balance(money){ //it's also a conversion constructor.
    cout << "Account constructor called\n\n";
    validation();
}
Account::~Account(){
    cout << "Account destructor called\n\n";
}
void Account::validation(){
    if (balance < 0){
        cout << "invalid value for balance, set to 0.0 dolar.\n";
        balance = 0.0;
    }
}
bool Account::credit( double depo){
    if (depo <= 0){
        cout << "Err. input should be >= 0. Please re-do again.\n";
        return false;
    }

    balance += depo;
    return true;
}
bool Account::debit( double draw){
    if (draw <=0){
        cout << "Err. input should be >= 0. Please re-do again.\n";
        return false;
    }
    else if (draw > balance){
        cout << "Sorry, debit amount exceeded account balance.\n";
        return false;
    }

    balance -= draw;
    return true;

}
double Account::getBalance(){
    return balance;
}
void Account::print(){
    cout << "Balance: \t" << setw(5) << right << balance << endl;
}

//derived class SavingsAccount
SavingsAccount::SavingsAccount(double money, double rate)
    :Account(money)
{
    cout << "SavingsAccount constructor called\n\n";
    setRate( rate);
    validationRate();
}
SavingsAccount::~SavingsAccount(){
    cout << "SavingsAccount destructor called\n\n";
}
void SavingsAccount::setRate( double rate){
    interestRate = rate;
}
void SavingsAccount::validationRate(){
    if ( interestRate < 0){
        cout << "invalid value for interest rate, set to 0.05 .\n";
        setRate(0.05);
    }
}
double SavingsAccount::calculateInterest(){
    return getBalance() * interestRate;
}
void SavingsAccount::print(){
    Account::print();
    cout << "Interest Rate: \t\t" << setw(5) << right << interestRate << endl << endl;
}



//derived class CheckingAccount
CheckingAccount::CheckingAccount( double money, double fee)
    :Account( money )
{
    cout << "CheckingAccount constructor called.\n\n";
    validationFee();
    setFee( fee);
}
CheckingAccount::~CheckingAccount(){
    cout << "CheckingAccount destructor called.\n\n";
}
void CheckingAccount::setFee( double fee){
    this->fee = fee;
}
void CheckingAccount::validationFee(){
    if ( fee < 0){
        cout << "invalid value for fee, set to 0.65 .\n";
        setFee(0.65);
    }
}
bool CheckingAccount::credit( double depo){
    if ( Account::getBalance() +  depo >= fee ){
        Account::credit( depo );
        Account::debit( fee );
        return true;
    }

    cout << "account balance plus your deposit is not enough to pay for transanction fee.\n" << "Please try again.\n";
    return false;
}
bool CheckingAccount::debit( double draw){
    if (  Account::debit( draw + this->fee)  )
        return true;

    cout << "or not enough to pay for transanction fee.\n";
}
void CheckingAccount::print(){
    Account::print();
    cout << "fee per transanction: \t" << setw(5) << right << this->fee << endl << endl;
}


/**< 小結: 除了使用get/set function 去access Base class的 private member 以外(如上面的寫法)，亦可將Base class中可能會使用到的member
改成protected權限，這樣子繼承的class就可以直接access而不需透過原始Base class所提供的 get/set fucntion.
*/
