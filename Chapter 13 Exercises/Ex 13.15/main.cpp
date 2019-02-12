/**< requires compiler version -std = C++14 */

#include "Package.hpp"

int main(){

    TwoDayPackage Binoculars("NTU", " No. 1, Section 4, Roosevelt Rd, Da・an District", "Taipei City", "Taiwan(ROC)", "10617",
                             "Kai", " No. 123, Section 1, Chongqing South Road, Taoyuan District", "Taoyuan City", "Taiwan(ROC)", "33047",
                             800/28.35, 7, 3);
    TwoDayPackage Binoculars2("NTU2", " No. 1, Section 4, Roosevelt Rd, Da・an District", "Taipei City", "Taiwan(ROC)", "10617",
                             "Kai2", " No. 123, Section 1, Chongqing South Road, Taoyuan District", "Taoyuan City", "Taiwan(ROC)", "33047",
                             800/28.35, 7, 3);
    OvernightPackage Telescope("NTU", " No. 1, Section 4, Roosevelt Rd, Da・an District", "Taipei City", "Taiwan(ROC)", "10617",
                             "Kai", " No. 123, Section 1, Chongqing South Road, Taoyuan District", "Taoyuan City", "Taiwan(ROC)", "33047",
                             800/28.35, 7, 1);
    OvernightPackage Telescope2("NTU2", " No. 1, Section 4, Roosevelt Rd, Da・an District", "Taipei City", "Taiwan(ROC)", "10617",
                             "Kai2", " No. 123, Section 1, Chongqing South Road, Taoyuan District", "Taoyuan City", "Taiwan(ROC)", "33047",
                             800/28.35, 7, 1);


    // create base class pointer pointing to all packages.
    vector <Package *> packages(4);
    packages.at(0) = &Binoculars;
    packages.at(1) = &Telescope;
    packages.at(2) = &Binoculars2;
    packages.at(3) = &Telescope2;

    // initialize parameters
    double totalprice_2d = 0;
    double totalprice_overN = 0;

    // for loop
    for (size_t i =0; i < packages.size(); i++){
        cout << "price for " << typeid(*packages.at(i) ).name() << " is: \t\t" << left <<setw(11);
        packages.at(i) -> printPrice();
        if (typeid( *packages.at(i)) == typeid( TwoDayPackage) )
            totalprice_2d += packages.at(i) -> calculateCost();
        else if (typeid( *packages.at(i)) == typeid (OvernightPackage) )
            totalprice_overN += packages.at(i) -> calculateCost();
    }
    cout << "\n\ntotal fees for all 2D packages: \t" << setw(7) << totalprice_2d << endl;
    cout << "total fees for all overnight packages: \t" << setw(7) << totalprice_overN << endl;
    cout << "Totally: \t\t\t\t" << setw(7) << totalprice_2d + totalprice_overN << endl;


}
