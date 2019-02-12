//Ex 12.9
#include "PackageInheritanceHierarchy.hpp"

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
