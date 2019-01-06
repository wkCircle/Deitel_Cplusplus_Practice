#include "FindMinValInArray.hpp"
//prototype
int recursiveMinimum (int [], int , int );
int recursiveMinimum (vector<int> & , int, int); //function overloading.


void FindMinValInArray(){
	const size_t arrSize = 10;
	//for array
	int arr[arrSize] =  {5, 100, 3, -12, 26, 55, 55, 0, -110, -1024};
//	srand(static_cast< unsigned int >(time(0)));
//	for (int i = 0; i < arrSize; i++)
//		arr[i] = rand()%20000 - 10000;
    cout << "list of elements:" << endl;
	for (int i=0; i<arrSize;i++){
        cout << setw(5) << arr[i];
 	}
 	cout << endl;

	cout << "The smallest value by recursiveMin is:" <<
	recursiveMinimum( arr, 0 /**< starting index>*/, 5 /**<end index>*/   ) << endl;
}
int recursiveMinimum (int arr[], int sIndex, int eIndex ){
	static int minvalue = 50000;

	if (sIndex > eIndex)
		return minvalue;

	int temp = 0;

	temp = min(arr[sIndex], arr[eIndex]);
	if ( temp < minvalue )
		minvalue = temp;
	temp = 0;
	return recursiveMinimum(arr, sIndex+1, eIndex-1);


}