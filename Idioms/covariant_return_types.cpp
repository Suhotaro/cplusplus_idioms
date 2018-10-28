#include "stdafx.h"

class Base
{
public:
	virtual Base * clone() const {
		return new Base(*this);
	}
};

class Derived : public Base
{
public:
	virtual Derived * clone() const override {
		return new Derived(*this);
	}
};

void covariant_return_types()
{
	Derived *d1 = new Derived();
	Derived *d2 = d1->clone();
}