#include "Chapter12_Exercises.hpp"

int main(){
//    //Ex 12.3
//    BasePlusCommissionEmployee Jenny( "Jenny", "Lin", "0912695747", 100, 0.1, 30000);
//    //Ex 12.9
//    TwoDayPackage Binoculars("NTU", " No. 1, Section 4, Roosevelt Rd, Da¡¦an District", "Taipei City", "Taiwan(ROC)", "10617",
//                             "Kai", " No. 123, Section 1, Chongqing South Road, Taoyuan District", "Taoyuan City", "Taiwan(ROC)", "33047",
//                             800/28.35, 7, 3);
//    OvernightPackage Telescope("NTU", " No. 1, Section 4, Roosevelt Rd, Da¡¦an District", "Taipei City", "Taiwan(ROC)", "10617",
//                             "Kai", " No. 123, Section 1, Chongqing South Road, Taoyuan District", "Taoyuan City", "Taiwan(ROC)", "33047",
//                             800/28.35, 7, 1);
//    cout << "total price for TwodayPackage: \t" << setw(7);
//    Binoculars.printPriceTwoDay();
//    cout << endl;
//    cout << "total price for OvernightPackage: \t" << setw(7);
//    Telescope.printPriceOvernight();
//    cout << endl;
//    Binoculars.setInfo( Binoculars.name, "Lin", "r");

    //Ex 12.10
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


