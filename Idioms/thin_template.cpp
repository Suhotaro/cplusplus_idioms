#include "stdafx.h"

// Not a template
class MyVectorBase {
	void insert(void *) {}
	void *at(int index) {}
};

template <typename T>
class MyVector : public MyVectorBase // Thin template
{
	inline void insert(T *t) { MyVectorBase::insert(t); }
	inline T *at(int index) { return static_cast<T*>(MyVectorBase::at(index)); }
};

void thin_template()
{
	// As I understad idea here is
	// 1. Base huge classes are not templates to reduce object code
	// 2. Base class uses void*
	// 3. Template class methods just do typecasting in inline functions
}