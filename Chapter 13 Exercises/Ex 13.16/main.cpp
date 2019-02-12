
#include "Account.hpp"

int main(){


    SavingsAccount myforDeposit( 1000, 0.1);
    CheckingAccount myforPay( 3500, 12);


    // create base pointer pointing to dervied classes objects (polymorphic)
    vector <Account *> accounts(2);
    accounts.at(0) = &myforDeposit;
    accounts.at(1) = &myforPay;

    cout << "initially, your savings account info:\n";
    myforDeposit.print();
    cout << "\nAnd your checking account info:\n";
    myforPay.print();

    int x=0, y=0;
    double z=0.0, temp=0.0;
    while(true){
        x=y=0;
        z=temp=0.0;

        cout << "please sepeciy in which account you wanna operate\n";
        cout << "[0]savings account \t [1]checkings account\n";
        cin >> x;
        cout << "Which operations you wanna make to this account?\n";
        cout << "[0]deposit \t\t [1]withdraw\n";
        cin >> y;
        cout << "How much money?\n";
        cin >> z;

        if (y==0){
            accounts.at(x) -> credit(z);
        }
        else if (y==1) {
            accounts.at(x) -> debit(z);
        }
        else {
            cout << "error, system terminated\n";
            exit(0);
        }

        cout << "Interest for account " << right << setw(14) << typeid(*accounts.at(x)).name() << " is:" << setw(5);
        cout << (temp = accounts.at(x) -> calculateInterest());
        cout << "\nAdds it to this account. So the final result is:\n";
        accounts.at(x) -> Account::credit(temp);
        accounts.at(x) -> print();
    }

}
