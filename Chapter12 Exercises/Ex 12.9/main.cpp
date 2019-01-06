//Ex 12.9
#include "PackageInheritanceHierarchy.hpp"
int main(){
    TwoDayPackage Binoculars("NTU", " No. 1, Section 4, Roosevelt Rd, Da_an District", "Taipei City", "Taiwan(ROC)", "10617",
                             "Kai", " No. 123, Section 1, Chongqing South Road, Taoyuan District[fake]", "Taoyuan City", "Taiwan(ROC)", "33047",
                             800/28.35, 7, 3);
    OvernightPackage Telescope("NTU", " No. 1, Section 4, Roosevelt Rd, Da_an District", "Taipei City", "Taiwan(ROC)", "10617",
                             "Kai", " No. 123, Section 1, Chongqing South Road, Taoyuan District[fake]", "Taoyuan City", "Taiwan(ROC)", "33047",
                             800/28.35, 7, 1);
    cout << "total price for TwodayPackage: \t" << setw(7);
    Binoculars.printPriceTwoDay();
    cout << endl;
    cout << "total price for OvernightPackage: \t" << setw(7);
    Telescope.printPriceOvernight();
    cout << endl;
    Binoculars.setInfo( Binoculars.name, "Lin", "r");
}
