#include "Account.hpp"

int main(){ //Following is used for Exercise 3.12 Account Class

    Account Account1("Xin, Hsu-Lin", 300000);
    Account Account2("Houston Hung", 250000);
    int userNumber=0, amount=0;
    string action="";

    //Test only
    //	cout << "the initial balance for " << Account1.getUser() <<" is: " << Account1.getBalance() << ".\n";
    //	cout <<"the initial balance for " << Account2.getUser() <<" is: " << Account2.getBalance() << ".\n";

    cout << "Please choose a representive number. [1 for "<< Account1.getUser() <<"/2 for "<< Account2.getUser() << ".]\n";
    cin >> userNumber;
    while (userNumber != 1 && userNumber != 2 ) {
        cout << "Invalid value, please only input either 1 or 2 to represent the user you wanna modify.\n";
        cin >> userNumber;
    };
    cout << "Choose an action.[deposit/withdraw]" << endl;
    cin >> action;
    while ( action != "deposit" && action != "withdraw"){
        cout << "Invlaid input. Please only input either \"deposit\" or \"withdraw\".\n";
        cin >> action;
    };
    cout << "Please input the amount of money you wanna " << action << ".\n";
    cin >> amount; //輸入asdf也會對...該怎麼辦？

    if (userNumber == 1){
        if (action == "deposit")
            Account1.credit(amount);
        else
            Account1.debit(amount);
    }
    else if (userNumber == 2){
        if (action == "deposit")
            Account2.credit(amount);
        else
            Account2.debit(amount);
    }
    cout << "moeny is: "<< Account1.getBalance()<< endl;
    cout << "moeny is: "<< Account2.getBalance()<<endl;
}
