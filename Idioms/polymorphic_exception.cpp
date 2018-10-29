#include "stdafx.h"

struct ExceptionBase {
	virtual void raise() { throw *this; }
	virtual ~ExceptionBase() {}
};

struct ExceptionDerived : ExceptionBase {
	virtual void raise() { throw *this; }
};

void foo(ExceptionBase& e) {
	e.raise(); // Uses dynamic type of e while raising an exception.
}

void polymorphic_exception()
{
	ExceptionDerived e;
	try {
		foo(e);
	}
	catch (ExceptionDerived& e) {
		// Exception raised in foo now matches this catch.
	}
	catch (...) {
		// not here anymore!
	}
}