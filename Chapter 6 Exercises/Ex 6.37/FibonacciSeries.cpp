#include "FibonacciSeries.hpp"


template <class T6_37>
inline T6_37 fibonacci(T6_37 n){
	// The (int ) max n = 48 so that val_n = 2971215073
	// The (double) max n = 1477 so that val_n = 1.30699e+308
	if (n==1)
		return 0;
	else if (n==2)
		return 1;

	T6_37 val_n=1, pre_val=0, helprmb=0;

	for(int i = 3; i <= n; i++){
		helprmb = val_n;
		val_n += pre_val;
		pre_val = helprmb;
	}
	return val_n;
}
void FibonacciSeries(){
	unsigned int n=1;

	while (true) {
		cout << "Input an integer representing th nth term of fibanacci series.(or 0 to quit.)\n";
		cin >> n;
		if (n==0)
			break;
		else {
			cout << "The value is:" << fibonacci(n) << endl;
			cout << "The value under double is: " << fibonacci(static_cast<double>(n)) << endl;
		}
	}
}
