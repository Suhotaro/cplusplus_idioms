#include "stdafx.h"

class Bar { public: void f(){}};
class Bar2 { public: void f(){}};

struct Foo {
	Foo () { bar().f (); }

	Bar & bar () {
		static Bar *b = new Bar (); //If Bars's destructor is simple
		return *b;
	}
};

struct Foo2 {
	Foo2 () { bar().f (); }
	Bar2 & bar () {
		static Bar2 b;
		return b;
	}
};

void construct_on_first_use()
{
	Foo f;
	Foo2 f2;
}