#include "IntegerSetClass.hpp"

void IntegerSet::objInitial(){
    this -> IntegerBoolSet.assign(101, 0);
}
IntegerSet::IntegerSet( const vector<int> * const intVecPtr ) { //type1 constructor
    objInitial();
    for (int i=0; i< intVecPtr->size() ; i++)
        if ( intVecPtr->at(i) >= 0 && intVecPtr->at(i) <= 100)
            IntegerBoolSet.at( intVecPtr->at(i) ) = 1;
}
IntegerSet::IntegerSet(const vector<bool>* const boolVecPtr ){ //type2 and also the default type constructor
    objInitial();
    IntegerBoolSet =  *boolVecPtr;
    IntegerBoolSet.resize(101, 0);
}
IntegerSet::IntegerSet(const int arr[], const int &arrSize ){ //type3 constructor
    objInitial();
    for (int i=0; i< arrSize ; i++)
        if ( arr[i] >= 0 && arr[i] <= 100)
            IntegerBoolSet.at( arr[i] ) = 1;
}
IntegerSet::IntegerSet(const bool arr[], const int &arrSize){ //type4 constructor
    objInitial();
    for(int i=0; i<arrSize ; i++)
        IntegerBoolSet.at(i) = arr[i];
}
/**<special type: initializer_list (take precedence over other constructors)>**/
IntegerSet::IntegerSet(const initializer_list<int> &args ){
    objInitial();
    initializer_list<int>::iterator it;
    for(it = args.begin(); it != args.end(); it++ )
        if ( *it > 0)
            IntegerBoolSet.at( *it ) = 1;
}

void IntegerSet::unionOfSets( IntegerSet  st){
    for(int i=0; i < this->IntegerBoolSet.size(); i++)
         IntegerBoolSet.at(i) = IntegerBoolSet.at(i) | st.IntegerBoolSet.at(i);
}
void IntegerSet::intersectionOfSets( IntegerSet st){
    for(int i=0; i< this->IntegerBoolSet.size(); i++)
        IntegerBoolSet.at(i) = IntegerBoolSet.at(i) & st.IntegerBoolSet.at(i);
}
void IntegerSet::insertElement( const int & ele){
    if (ele>=0 && ele <= 100)
        IntegerBoolSet.at(ele)=1;
}
void IntegerSet::deleteElement( const int & ele){
    if(ele>=0 && ele <= 100)
        IntegerBoolSet.at(ele)=0;
}
bool IntegerSet::isEqualtTo( IntegerSet st ) const{
    for ( int i=0; i < this->IntegerBoolSet.size(); i++)
        if( IntegerBoolSet.at(i) != st.IntegerBoolSet.at(i) )
            return 0;
    return 1;
}
void IntegerSet::printSet() const{
    bool flag=0;
    for ( int i=0; i< this->IntegerBoolSet.size(); i++){
        if(IntegerBoolSet.at(i) == 1){
            cout << i << " ";
            flag =1;
        }
    }
    if (flag == 0) cout<<"empty set";
    cout << endl;
}
