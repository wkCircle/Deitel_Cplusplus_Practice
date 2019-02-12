#include "CarbonFootprint.hpp"

int main (){

    Car     BMW740e( 17976, 135); //source https://tinyurl.com/yb5p323z
    Bicycle Giant(5000);
    Building TaipeiHouse(200);


    vector <CarbonFootprint *> CO2footprint(3);
    CO2footprint.at(0) = &BMW740e;
    CO2footprint.at(1) = &Giant;
    CO2footprint.at(2) = &TaipeiHouse;

    for (size_t i=0; i < CO2footprint.size(); i++){
        cout << "CO2 emission for " << typeid( *CO2footprint.at(i) ).name() << " is: \t"
             << setprecision(8) << right << setw(15) << CO2footprint.at(i) -> getCarbonFootprint() << endl << endl;
    }

    return 0;
}
