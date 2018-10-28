#include "stdafx.h"

template <class T>
class Ptr
{
public:
	Ptr () {}

	Ptr (Ptr const & p) : ptr (p.ptr) {
		std::cout << "Copy constructor\n";
	}

	// Supporting coercion using member template constructor.
	// This is not a copy constructor, but behaves similarly.
	template <class U>
	Ptr (Ptr <U> const & p) : ptr (p.ptr) // Implicit conversion from U to T required
	{
		std::cout << "Coercing member template constructor\n";
	}

	// Copy assignment operator.
	Ptr & operator = (Ptr const & p) {
		ptr = p.ptr;
		std::cout << "Copy assignment operator\n";
		return *this;
	}

	// Supporting coercion using member template assignment operator.
	// This is not the copy assignment operator, but works similarly.
	template <class U>
	Ptr & operator = (Ptr <U> const & p) {
		ptr = p.ptr; // Implicit conversion from U to T required
		std::cout << "Coercing member template assignment operator\n";
		return *this;
	}

	T *ptr;
};

class Base {};
class Derived : public Base {};
template <class T>
class Helper {};

void coercion_by_member_template()
{
	Helper<Base> hb;
	Helper<Derived> hd;
	//hb = hd; // Not allowed but could be very useful

	Ptr <Derived> d_ptr;
	Ptr <Base> b_ptr(d_ptr); // Now supported
	b_ptr = d_ptr;         // Now supported
}

//------------------------------------------------------------------------------------

template <class T>
class Array
{
public:
	Array()
	{}
	Array(Array const & a)
	{
		std::copy(a.array_, a.array_ + SIZE, array_);
	}

	template <class U>
	Array(Array <U *> const & a)
	{
		std::copy(a.array_, a.array_ + SIZE, array_);
	}

	template <class U>
	Array & operator = (Array <U *> const & a)
	{
		std::copy(a.array_, a.array_ + SIZE, array_);
		return *this;
	}

	enum
	{
		SIZE = 10
	};
	T array_[SIZE];
};

void coercion_by_member_template2()
{
	Array<Base*> v1;
	Array<Derived*> v2;

	v1 = v2;
	//v2 = v1; // Forbidden due to slicing
}