//Ex 12.10
#include "AccountInheritanceHierarchy.hpp"

int main(){
    SavingsAccount myforDeposit( 1000, -1);
    CheckingAccount myforPay( 3500, 12);


    cout << "Annual interest will be: "<< myforDeposit.calculateInterest() << endl;
    cout << "Savings account deposit 1 dollar: ";
    myforDeposit.credit(1);
    myforDeposit.print();

    cout << "Checking account deposit 12 dollars: ";
    myforPay.credit(12);
    myforPay.print();
    cout << "Checking account withdraw 88 dollars: ";
    myforPay.debit(88);
    myforPay.print();

    return 0;
}


