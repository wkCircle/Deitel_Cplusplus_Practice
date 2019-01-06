#include "DuplicateElimination.hpp"


void DuplicateElimination(){
	int array_input[20]={};
	int subscript=0, elem=0;
	bool duplicate=0;
	cout << "Input 20 integers in [10,100] or input -111 to quit.\n";

	for ( int i=0 ; i<20; i++){

		cin >> elem;
		if (elem == -111){

			cout << "The non-duplicate input as far are: \n";

			if (subscript==0) cout << "none\n";
			for (int i=0; i<subscript; i++){
				cout << left << setw(4) << array_input[i];
			}
			cout << endl;

			return;
		}

		//check valid or not.
		while(elem <10 || elem >100){
			cout << "Invalid value for time " << i+1 << " input. Input again.\n";
			cin >> elem;
			if (elem == -111){
				cout << "The non-duplicate input as far are: \n";

				if (subscript==0) cout << "none\n";
				for (int i=0; i<subscript; i++){
					cout << left << setw(4) << array_input[i];
				}
				cout << endl;

				return;
			}
		}

		duplicate = 0; //defaulted to be false.
		//duplicate determination.
		for (int compare = 0; compare < subscript ; compare++){
			if (array_input[compare] == elem){
				duplicate = 1; //duplicate is true.
				break;
			}
		}

		//if not repeated, fill in the array.
		if ( !duplicate ){
			array_input[subscript] = elem;
			subscript++;
		}
	}

	//print the result
	cout << "The non-duplicate inputs are: \n";
	for (int i=0; i<subscript; i++){
		cout << left << setw(4) << array_input[i];
	}
	cout << endl;

}
