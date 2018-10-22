#include "stdafx.h"
#include "construction_tracker.h"

#include <iostream>
#include <stdexcept>
#include <cassert>

struct B { B (char const *) { throw std::runtime_error("B Error"); } };
struct C { C (char const *) { throw std::runtime_error("C Error"); } };

class A {
	B b_;
	C c_;
	enum TrackerType { NONE, ONE, TWO };
public:
	A( TrackerType tracker = NONE)
	try // A constructor try block.
		: b_((tracker = ONE, "hello")) // Can throw std::exception
		, c_((tracker = TWO, "world")) // Can throw std::exception
		{
			assert(tracker == TWO);
			// ... constructor body ...
		}
	catch (std::exception const & e)
	{
		switch(tracker)
		{
		case NONE:	std::cout << "B threw: " << e.what() << std::endl; break;
		case ONE:	std::cout << "C threw: " << e.what() << std::endl;
		default: break;
		}
		throw;
	}
};

void construction_tracker()
{
	try {
		A a;
	}
	catch (std::exception const & e) {
		std::cout << "Caught: " << e.what() << std::endl;
	}
}