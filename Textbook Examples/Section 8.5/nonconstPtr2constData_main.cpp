#include "nonconstPtr2constData.hpp"
int main(){
    int y;
	f( &y ); // f attempts illegal modification
}
