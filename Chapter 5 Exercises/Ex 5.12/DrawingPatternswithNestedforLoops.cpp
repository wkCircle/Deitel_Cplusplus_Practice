#include "DrawingPatternswithNestedforLoops.hpp"


int DrawingPatternswithNestedforLoops(){
	//	//case a)
	//	for (int i=1; i<=10; i++){
	//		for (int j=1; j<=i; j++){
	//			cout << '*';
	//		}
	//		cout << endl;
	//	}
	//	//case b)
	//	for (int i=1; i<=10; i++){
	//		for (int j=10; j>=i; j--){
	//			cout << '*';
	//		}
	//		cout << endl;
	//	}
	//	//case c)
	//	for (int i=1; i<=10; i++){
	//		for (int j=1; j<=10; j++){
	//			if (j>=i){
	//				cout << '*';
	//			}
	//			else
	//				cout << ' ';
	//		}
	//		cout << endl;
	//	}
	//	//case d)
	//	for (int i=1; i<=10; i++){
	//		for (int j=10; j>=1; j--){
	//			if (j>=i-1){
	//				cout << ' ';
	//			}
	//			else
	//				cout << '*';
	//		}
	//		cout << endl;
	//	}

	//For extra credit in the question
	for (int i=1; i<=10; i++) {
		for (int j=1; j<=10; j++) {
			if (j<=i)
				cout << '*';
			else
				cout << ' ';
		}


		for (int j=10; j>=1; j--) {
			if (j>=i)
				cout << '*';
			else
				cout << ' ';
		}


		for (int j=1; j<=10; j++){
			if (j<=i-1)
				cout << ' ';
			else
				cout << '*';
		}


		for (int j=10; j>=1; j--){
			if (j>=i+1)
				cout << ' ';
			else
				cout << '*';
		}
		cout << endl;
	}
	return 0;
}
