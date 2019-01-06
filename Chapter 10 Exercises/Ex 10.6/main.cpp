#include "DateClassModification.hpp"

int main(){
	struct tm A;
	Date DateTest( A );
	DateTest.print('c');
}
