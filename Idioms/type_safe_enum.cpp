#include "stdafx.h"

template<typename def, typename inner = typename def::type>
class safe_enum : public def
{
	typedef inner type;
	inner val;

public:

	safe_enum() {}
	safe_enum(type v) : val(v) {}
	type underlying() const { return val; }

	friend bool operator == (const safe_enum & lhs, const safe_enum & rhs) { return lhs.val == rhs.val; }
	friend bool operator != (const safe_enum & lhs, const safe_enum & rhs) { return lhs.val != rhs.val; }
	friend bool operator <  (const safe_enum & lhs, const safe_enum & rhs) { return lhs.val <  rhs.val; }
	friend bool operator <= (const safe_enum & lhs, const safe_enum & rhs) { return lhs.val <= rhs.val; }
	friend bool operator >  (const safe_enum & lhs, const safe_enum & rhs) { return lhs.val >  rhs.val; }
	friend bool operator >= (const safe_enum & lhs, const safe_enum & rhs) { return lhs.val >= rhs.val; }
};

struct color_def {
	enum type { red, green, blue };
};
typedef safe_enum<color_def> color;

struct shape_def {
	enum type { circle, square, triangle };
};
typedef safe_enum<shape_def, unsigned char> shape; // unsigned char representation

void type_safe_enum()
{
/*
	color c = color::red;
	bool flag = (c >= shape::triangle); // Compiler error.
*/
}