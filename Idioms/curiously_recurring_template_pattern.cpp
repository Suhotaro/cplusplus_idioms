#include "stdafx.h"
#include "curiously_recurring_template_pattern.h"

template <class Derived>
struct base
{
	void interface() {
		static_cast<Derived*>(this)->implementation();
	}

	//NOTE: static polifmorfizm
	static void static_interface() {
		Derived::static_implementation();
	}

	// The default implementation may be (if exists) or should be (otherwise) 
	// overridden by inheriting in derived classes (see below)
	void implementation()					{ printf("base implementation\n"); }
	static void static_implementation()		{ printf("base static_implementation\n"); }
};

// The Curiously Recurring Template Pattern (CRTP)
struct derived_1 : base<derived_1>
{
	// This class uses base variant of implementation
	//void implementation();

	// ... and overrides static_implementation
	static void static_implementation() { printf("deried_1 static_implementation\n"); }
};

struct derived_2 : base<derived_2>
{
	// This class overrides implementation
	void implementation() { printf("derived_2 implementation\n"); }

	// ... and uses base variant of static_implementation
	//static void static_implementation();
};

void curiously_recurring_template_pattern()
{
	derived_1 d1;
	d1.interface();
	d1.static_interface();

	derived_2 d2;
	d2.interface();
	d2.static_interface();
}
