// Fig. 11.17: Interface.h
#ifndef Proxy_h
#define Proxy_h

#include <iostream>
using namespace std;

/**< Proxy class Interface definition. >**/
// Client sees this source code, but the source code does not reveal the data layout of class Implementation.
class Implementation;
class Interface {
public:
	Interface( int );
	~Interface();
	void Fig11_16to11_19main();
	 // same public interface as class Implementation has
	void setValue( int );
	int getValue() const;

private:
	// requires previous forward declaration (class Implementation;)
	Implementation *ptr;
};
#endif /* Proxy_h */
