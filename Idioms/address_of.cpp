#include "stdafx.h"
#include "address_of.h"

class nonaddressable
{
public:
	typedef double useless_type;

private:
	useless_type operator&() const; //inaccessable
};

template <class T>
T * myAddressOf(T & v)
{
	return reinterpret_cast<T *>(&const_cast<char&>(reinterpret_cast<const volatile char &>(v)));
}

void address_of()
{
	nonaddressable na;

//	nonaddressable * naptr = &na;			// compiler error.
//	nonaddressable::useless_type v = &na;	// compiler error.
	nonaddressable * naptr = myAddressOf(na);	// OK
}