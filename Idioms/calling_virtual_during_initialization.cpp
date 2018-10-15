#include "stdafx.h"
#include "calling_virtual_during_initialization.h"

// 1:Two phase initialization technique
class Base {
public:
	void init();  // may or may not be virtual

	virtual void foo(int n) const { printf("Base: foo\n"); } // often pure virtual
	virtual void bar() const { printf("Base: bar\n"); } // often pure virtual

	template <class T, class Parameter>
	static std::unique_ptr <Base> Create(Parameter p) {
		std::unique_ptr <Base> ptr(new T(p));
		ptr->init();
		return ptr;
	}
};

void Base::init()
{
	foo(42);
	bar();
	// most of this is copied from the original Base::Base()
}

class Derived : public Base {
public:
	Derived(int) : Base() {}
	virtual void foo(int n) const { printf("Derived: foo\n"); } // often pure virtual
	virtual void bar() const { printf("Derived: bar\n"); } // often pure virtual
};

template <class T, class Parameter>
unique_ptr<Base> factory(Parameter p)
{
	std::unique_ptr <Base> ptr(new T(p));
	ptr->init();
	return ptr;
}

// 2:Without using two phase initialization

class Base2 {
public:
	static void foo() { cout << "Derived::foo()\n"; }
	static void bar() { cout << "Derived::bar()\n"; }
};

template <class D>
class InitTimeCaller : public Base2 {
protected:
	InitTimeCaller() {
		D::foo();
		D::bar();
	}
};

class Derived2 : public InitTimeCaller <Derived2>
{
public:
	Derived2() : InitTimeCaller <Derived2>() {
		cout << "Derived::Derived()\n";
	}
	static void foo() { cout << "Derived::foo()\n"; }
	static void bar() { cout << "Derived::bar()\n"; }
};

void calling_virtual_during_initialization()
{
	unique_ptr<Base> ptr(factory<Derived>(10));
	ptr->init(); // might be called again --> weired

	Derived2 d2;
	d2.foo();
	d2.bar();
}