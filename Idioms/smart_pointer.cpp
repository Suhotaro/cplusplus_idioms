#include "stdafx.h"

class Body
{
public:
	void foo() {}
};

class Handle // Completely pointer like semantics
{
public:
	void set(Body *b) { body_ = b; }
	Body * operator -> () const throw()
	{
		return body_;
	}
	Body & operator * () const throw ()
	{
		return *body_;
	}
private:
	mutable Body *body_;
};

class Handle2 // Less pointer like semantics
{
public:
	void set(Body *b) { body_ = b; }
	Body * operator -> () throw()
	{
		return body_;
	}
	Body const * operator -> () const throw()
	{
		return body_;
	}
	operator const Body & () const // type conversion
	{
		return *body_;
	}
	operator Body & ()  // type conversion
	{
		return *body_;
	}
	// No operator *()
private:
	mutable Body *body_;
};

/*
Body const & get(const Handle2 &h)
{
	return *h.body_;
}
Body & get(Handle2 &h)
{
	return *h.body_;
}
*/

void smart_pointer()
{
	Handle h;
	h.set(new Body());
	h->foo();    // A way of invoking Body::foo()
	(*h).foo();  // Another way of invoking Body::foo()

	Handle2 h2;
	h2.set(new Body());
	h2->foo();
	//get(h2).foo(); // compiles only if Body::foo() is a const function.
}
