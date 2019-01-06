#include "IntegerSetClass.hpp"
int main(){
    const vector<int> * const vecAPtr = new vector<int>{2,3,5,7,9};
    IntegerSet setA(vecAPtr); //type1 constructor

    const vector<bool>* const vecBPtr = new vector<bool>{1,0,1,0,1,0,1,0,1,0,1}; //Which is (int){0,2,4,6,8,10}
    IntegerSet setB(vecBPtr); //type2 constructor

    int arrSize = 3;
    int * const arrIntPtr = new int [arrSize];
    for(int i =0; i<arrSize; i++) *(arrIntPtr+i) = 50+i; //(int){50,51,52}
    IntegerSet setC(arrIntPtr, arrSize); //type3 constructor

    bool * const arrBoolPtr = new bool [101]{};
    for(int i =0; i<3; i++) *(arrBoolPtr+50-i) = 1; //(int){48,49,50}
    IntegerSet setD(arrBoolPtr); //type4 constructor

    IntegerSet setInit {83,89,97};// special type constructor

    setA.unionOfSets(setB);
    setA.printSet();

    setC.intersectionOfSets(setD);
    setC.printSet();

    setD.insertElement(2);
    setD.printSet();

    setInit.deleteElement(83);
    setInit.printSet();
}
