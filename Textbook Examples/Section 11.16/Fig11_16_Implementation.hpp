// Fig. 11.16: Implementation.h
// Implementation class definition.

class Implementation {
public:
	Implementation( int v ) : value( v ) {}// initialize value with v
	void setValue( int v ){ value = v; }
	int getValue() const {	return value; }
private:
	int value; // data that we would like to hide from the client
};


