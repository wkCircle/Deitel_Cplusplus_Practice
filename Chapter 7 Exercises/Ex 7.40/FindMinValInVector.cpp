#include "FindMinValInVector.hpp"
//prototype
int recursiveMinimum (int [], int , int );
int recursiveMinimum (vector<int> & , int, int); //function overloading.


void FindMinValInVector(){
	const size_t arrSize = 10;
	//for vector: 4 different construct methods are shown below. Choose one of them to test the code.
//  vector<int> vec = {5, 100, 3, -12, 26, 55, 55, 0, -110, -1024};
    int arr[arrSize] =  {5, 100, 3, -12, 26, 55, 55, 0, -110, -1024};
    vector<int> vec(arrSize); vec.assign(arr, arr+arrSize );
//	vector<int> vec(arr, arr + sizeof(arr)/sizeof(int) );
//	vector<int> vec( arr, arr + arrSize);

//	srand(static_cast< unsigned int >(time(0)));
//	for (int i = 0; i < vec.size(); i++)
//		vec.at(i) = rand()%20000 - 10000;
	cout << "The smallest value by recursiveMin is:" <<
	recursiveMinimum( vec, 0 /**< starting index>*/, 5 /**<end index>*/   ) << endl;

}
int recursiveMinimum ( vector<int> &vec, int sIndex, int eIndex ){
	static int minvalue = 50000;

	if (sIndex > eIndex)
		return minvalue;

	int temp = 0;

	temp = min(vec.at(sIndex), vec.at(eIndex));
	if ( temp < minvalue )
		minvalue = temp;
	temp = 0;
	return recursiveMinimum( vec, sIndex+1, eIndex-1);


}
