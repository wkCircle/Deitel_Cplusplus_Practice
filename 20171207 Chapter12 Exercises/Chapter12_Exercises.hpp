
#ifndef Chapter12_Exercises_hpp
#define Chapter12_Exercises_hpp

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <ctime>
#include <random>
#include <typeinfo>
#include <vector>
#include <cctype>  //isdigit function prototype
using namespace std;

//Ex12.3
// Fig. 12.22: CommissionEmployee.h
// CommissionEmployee class definition represents a commission employee.
class CommissionEmployee { /**<Base Class>**/
public:
    CommissionEmployee( const string &, const string &, const string &, double = 0.0, double = 0.0 );
    ~CommissionEmployee(); // destructor

    void setFirstName( const string & ); // set first name
    string getFirstName() const;
    void setLastName( const string & ); // set last name
    string getLastName() const;
    void setSocialSecurityNumber( const string & ); // set SSN
    string getSocialSecurityNumber() const;
    void setGrossSales( double ); // set gross sales amount
    double getGrossSales() const;
    void setCommissionRate( double ); // set commission rate
    double getCommissionRate() const;

    double earnings() const; // calculate earnings
    void print() const; // print CommissionEmployee object
private:
    string firstName;
    string lastName;
    string socialSecurityNumber;
    double grossSales; // gross weekly sales
    double commissionRate; // commission percentage
};
/**<Case started: Inheriatance approach for exercise 12.3>**/
//// Fig. 12.24: BasePlusCommissionEmployee.h
//// BasePlusCommissionEmployee class derived from class CommissionEmployee.
//class BasePlusCommissionEmployee : public CommissionEmployee { //public inheritance
//public:
//    BasePlusCommissionEmployee( const string &, const string &, const string &, double = 0.0, double = 0.0, double = 0.0 );
//    ~BasePlusCommissionEmployee();
//
//    void setBaseSalary( double ); // set base salary
//    double getBaseSalary() const;
//    double earnings() const; // calculate earnings
//    void print() const; // print BasePlusCommissionEmployee object
//private:
//    double baseSalary; // base salary
//};
/**<Case finished: Inheritance approach for exercise 12.3>**/
/**<Case started: Composition approach for exercise 12.3>**/
class BasePlusCommissionEmployee{
public:
    BasePlusCommissionEmployee( const string &, const string &, const string &, double = 0.0, double = 0.0, double = 0.0 );
    ~BasePlusCommissionEmployee();

    //以下皆reuse class CommissionEmployee 的成員，body都是 call 原始class的function。
    //Inheritance寫法下，以下就根本不用寫；組合寫法下，以下就需要。
    void setFirstName( const string & ); // set first name
    string getFirstName() const;
    void setLastName( const string & ); // set last name
    string getLastName() const;
    void setSocialSecurityNumber( const string & ); // set SSN
    string getSocialSecurityNumber() const;
    void setGrossSales( double ); // set gross sales amount
    double getGrossSales() const;
    void setCommissionRate( double ); // set commission rate
    double getCommissionRate() const;
    //以上

    void setBaseSalary( double ); // set base salary
    double getBaseSalary() const;
    double earnings() const; // calculate earnings
    void print() const; // print BasePlusCommissionEmployee object
private:
    CommissionEmployee *employeeObjPtr; /**<composition method: 強調的是用指標的概念去reuse其他類別寫好的方法>**/
    double baseSalary; // base salary
};
/**<Case finished: Composition approach for exercise 12.3>**/


//Ex 12.9
class Package {
public:
    enum Argument {name=0, address, city, state, ZIP};
    Package(string, string, string, string, string, string, string, string, string, string, double =1, double = 10.0);
    ~Package();
    double calculateCost();
    void validationAndSet(double &, double &);
    void setInfo(Argument , string, string ="r"); //1st: name/address/city/...;  2nd:input_value; 3rd: r means recipient;
    double getWeight();
    double getCostPerOunce();
    void print();
    void printPrice();
private:
    string name_sender, name_recipient;
    string address_sender, address_recipient;
    string city_sender, city_recipient;
    string state_sender, state_recipient;
    string ZIP_sender, ZIP_recipient;
    double weight; //in ounces
    double costPerOunce;
};

class TwoDayPackage: public Package{
public:
    TwoDayPackage(string, string, string, string, string, string, string, string, string, string, double =1, double = 10.0, double =3.0);
    ~TwoDayPackage();
    void validationAndSet( double &);
    double calculateCost();
    void printPriceTwoDay();
private:
    double flatFee;
};
class OvernightPackage: public Package{
public:
    OvernightPackage(string, string, string, string, string, string, string, string, string, string, double =1, double = 10.0, double = 1.0);
    ~OvernightPackage();
    void validationAndSet( double &);
    double calculateCost();
    void printPriceOvernight();
private:
    double extraFee; //depends on weight per ounce
};










//Ex 12.10
class Account{
public:
    Account ( double );
    ~Account();
    void validation();
    bool credit( double ); //add $ to current balance.
    bool debit( double ); //withdraw $ from current balance.
    double getBalance();
    void print();
private:
    double balance;

};

class SavingsAccount: public Account{
public:
    SavingsAccount( double, double);
    ~SavingsAccount();
    void setRate( double );
    double calculateInterest();
    void print();
private:
    void validationRate();
    double interestRate;

};

class CheckingAccount: public Account{
public:
    CheckingAccount( double, double);
    ~CheckingAccount();
    void setFee( double );
    bool credit( double );
    bool debit( double );
    void print();
private:
    void validationFee();
    double fee; //represents fee charged per transanction.
};
#endif /* Chapter12_Exercises_hpp */
