#include "FuncTemplateminimum.hpp"

template <typename T6_53>
inline T6_53 minimum(T6_53 x, T6_53 y){
	if (x>=y)
		return y;
	else
		return x;
}
void FuncTemplateminimum(){
	int x=5, y=4;
	string xs="5.43", ys="-5.42";
	float xf = 5.43, yf = 5.42;

	cout << minimum(x, y) << endl;
	cout << minimum(xs, ys) << endl;
	cout << minimum(xf, yf) << endl;

}

