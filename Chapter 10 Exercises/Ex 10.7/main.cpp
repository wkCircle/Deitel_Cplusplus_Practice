#include "SavingsAccountClass.hpp"
int main(){
	SavingsAccount saver1(2000), saver2(3000);
    SavingsAccount::modifyIntrestRate(0.03);
    cout << "Info for saver1 under 3\%: " << endl;
    saver1.print();
    cout << "Info for saver2 under 3\%: " << endl;
    saver2.print();
    SavingsAccount::modifyIntrestRate(0.04);
    cout << "Info for saver1 under 4\%: " << endl;
    saver1.print();
    cout << "Info for saver2 under 4\%: " << endl;
    saver2.print();
}
