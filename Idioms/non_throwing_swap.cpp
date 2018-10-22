#include "stdafx.h"
#include "non_throwing_swap.h"

template<class T>
void swap(T &a, T &b)
{
	T temp(a);
	a = b;
	b = temp;
}

//NOTE: T is a pointer !!!

class String
{
	char * str;
public:
	String & operator=(const String & s)
	{
		String temp(s); // Copy-constructor -- RAII //note: exception of no memory
		temp.swap(*this); // Non-throwing swap

		return *this;
	}
	// Old resources released when destructor of temp is called.

	void swap(String & s) throw() // Also see the non-throwing swap idiom
	{
		std::swap(this->str, s.str);
	}
};

class UserDefined
{
	String str;
public:
	void swap(UserDefined & u) // throw () 
	{
		std::swap(str, u.str);
	}
};

namespace std
{
// Full specializations of the templates in std namespace can be added in std namespace.
template <>
void swap(UserDefined & u1, UserDefined & u2) // throw ()
{
	u1.swap(u2);
}
}

class Myclass
{
	UserDefined u;
	char * name;
public:
	void swap(Myclass & m) // throw ()
	{
		std::swap(u, m.u);       // cascading use of the idiom due to uniformity
		std::swap(name, m.name); // Ditto here
	}
};

namespace std
{
// Full specializations of the templates in std namespace can be added in std namespace.
template <>
void swap(Myclass & m1, Myclass & m2) // throw ()
{
	m1.swap(m2);
}

};

void non_throwing_swap()
{

}
