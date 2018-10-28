#include "stdafx.h"
#include "idioms.h"

#include <ostream>

using namespace std;

/*
template<typename T>
class Foo {
	T value;
public:
	Foo(const T& t) { value = t; }
	friend ostream& operator<<(ostream&, const Foo<T>&);
};

template<typename T>
ostream& operator<<(ostream& os, const Foo<T>& b) {
	return os << b.value;
}
*/

template<typename T>
class Foo2 {
	T value;
public:
	Foo2(const T& t) { value = t; }

	friend ostream& operator<<(ostream& os, const Foo2<T>& b)
	{
		return os << b.value;
	}
};

 /*
Such a friend function is not a template, but the
template acts as a factory for "making" new friends.
A new non-template function is created for each
specialization of Foo.
*/

void making_new_friends()
{
	Foo2<int>f2(10);
	cout << f2 << endl;

/*
	Foo<string>f3("hello");
	cout << f3 << endl;
*/
}