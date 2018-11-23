#include "stdafx.h"

class Testable {
	bool ok_;
	using bool_type = void (Testable::*)() const;
	void this_type_does_not_support_comparisons() const {}

public:
	explicit Testable(bool b = true) :ok_(b) {}

	operator bool_type() const
	{
		return ok_ ? &Testable::this_type_does_not_support_comparisons : 0;
	}
};
template <typename T>
bool operator!=(const Testable& lhs, const T&) {
	lhs.this_type_does_not_support_comparisons();
	return false;
}
template <typename T>
bool operator==(const Testable& lhs, const T&) {
	lhs.this_type_does_not_support_comparisons();
	return false;
}


void safe_bool()
{
	Testable t1;

	bool t = t1;


	if (t1) {} // Works as expected
	//if (t1 == t1) {} // Fails to compile
}