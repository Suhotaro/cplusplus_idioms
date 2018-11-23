#include "stdafx.h"
#include <typeinfo>

const // It is a const object...
class my_nullptr_t
{
public:
	template<class T>
	inline operator T*() const // convertible to any type of null non-member pointer...
	{
		return 0;
	}

	template<class C, class T>
	inline operator T C::*() const   // or any type of null member pointer...
	{
		return 0;
	}

private:
	void operator&() const;  // Can't take address of nullptr

} my_nullptr = {};

//============================================================================

struct C
{
	void func();
};

template<typename T>
void g(T* t) {}

template<typename T>
void h(T t) {}

void func(double *) {}
void func(int) {}

void nullptrr()
{
	char * ch = my_nullptr;        // ok
	func(my_nullptr);             // Calls func(double *)
	func(0);                   // Calls func(int)
	void (C::*pmf2)() = 0;      // ok
	void (C::*pmf)() = my_nullptr; // ok
	my_nullptr_t n1, n2;
	n1 = n2;
	//my_nullptr_t *null = &n1;    // Address can't be taken.
	if(my_nullptr == ch)
	{
	}       // ok
	if(my_nullptr == pmf)
	{
	}      // Valid statement; but fails on g++ 4.1.1-4.5 due to bug #33990
#if 0
  // for GCC 4: if ((typeof(pmf))my_nullptr == pmf) {}
	const int n = 0;

	if(my_nullptr == n)
	{
	}        // Should not compile; but only Comeau shows an error.
#endif
	//int p = 0;
	//if (nullptr == p) {}      // not ok
	//g (nullptr);              // Can't deduce T
	int expr = 0;
	char* ch3 = expr ? my_nullptr : my_nullptr; // ch3 is the null pointer value
	//char* ch4 = expr ? 0 : nullptr;     // error, types are not compatible
	//int n3 = expr ? nullptr : nullptr;  // error, nullptr can’t be converted to int
	//int n4 = expr ? 0 : nullptr;        // error, types are not compatible

	h(0);                   // deduces T = int
	h(my_nullptr);          // deduces T = nullptr_t
	h((float*) my_nullptr); // deduces T = float*

	sizeof(my_nullptr);     // ok
	typeid(my_nullptr);     // ok
	throw my_nullptr;       // ok
}