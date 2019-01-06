
#include "Account.hpp"

//Base class Account's member functions
Account::Account( double money): balance(money){ //it's also a conversion constructor.
    //cout << "Account constructor called\n\n";
    validation();
}
Account::~Account(){
    //cout << "Account destructor called\n\n";
    ;
}
void Account::validation(){
    if (balance < 0){
        cout << "invalid value for balance, set to 0.0 dolar.\n";
        balance = 0.0;
    }
}
bool Account::credit( double depo){
    if (depo < 0){
        cout << "Err. depo amount should be >= 0. Please re-do again.\n";
        return false;
    }

    balance += depo;
    return true;
}
bool Account::debit( double draw){
    if (draw < 0){
        cout << "Err. withdraw amount should be >= 0. Please re-do again.\n";
        return false;
    }
    else if (draw > balance){
        cout << "Sorry, debit amount exceeded account balance.\n";
        return false;
    }

    balance -= draw;
    return true;

}
double Account::calculateInterest(){
    return 0; //no interest
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
    //cout << "SavingsAccount constructor called\n\n";
    setRate( rate);
    validationRate();
}
SavingsAccount::~SavingsAccount(){
    //cout << "SavingsAccount destructor called\n\n";
    ;
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
    //cout << "CheckingAccount constructor called.\n\n";
    validationFee();
    setFee( fee);
}
CheckingAccount::~CheckingAccount(){
    //cout << "CheckingAccount destructor called.\n\n";
    ;
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
