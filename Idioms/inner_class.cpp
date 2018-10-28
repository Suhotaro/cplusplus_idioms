#include "stdafx.h"

class Base1  /// Provided by Moon
{
public:
	virtual int open() = 0;
	/* virtual */ ~Base1() {}  // No polymorphic deletion allowed
};

class Base2  /// Provided by Jupitor
{
public:
	virtual int open() = 0;
	/* virtual */ ~Base2() {}  // No polymorphic deletion allowed
};

class Derived  // Note no inheritance
{
	class Base1_Impl;
	friend class Base1_Impl;
	class Base1_Impl : public Base1  // Note public inheritance
	{
	public:
		Base1_Impl(Derived* p) : parent_(p) {}
		int open() override { return parent_->base1_open(); }

	private:
		Derived* parent_;
	} base1_obj;  // Note member object here.

	class Base2_Impl;
	friend class Base2_Impl;
	class Base2_Impl : public Base2  // Note public inheritance
	{
	public:
		Base2_Impl(Derived* p) : parent_(p) {}
		int open() override { return parent_->base2_open(); }

	private:
		Derived* parent_;
	} base2_obj;  // Note member object here

	int base1_open() { return 111; }  /// implement
	int base2_open() { return 222; }  /// implement

public:

	Derived() : base1_obj(this), base2_obj(this) {}
	Derived(Derived const&) : base1_obj(this), base2_obj(this) {}
	Derived(Derived&&) : base1_obj(this), base2_obj(this) {}
	Derived& operator=(Derived const&) { return *this; }
	Derived& operator=(Derived&&) { return *this; }

	operator Base1&() { return base1_obj; }  /// convert to Base1&
	operator Base2&() { return base2_obj; }  /// convert to Base2&
};                                         /// class Derived

int base1_open(Base1& b1) { return b1.open(); }

int base2_open(Base2& b2) { return b2.open(); }

void inner_class()
{
	Derived d;
	std::cout << base1_open(d) << std::endl;  // Like upcasting in inheritance.
	std::cout << base2_open(d) << std::endl;  // Like upcasting in inheritance.
}