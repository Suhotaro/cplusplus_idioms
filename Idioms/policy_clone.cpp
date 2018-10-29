#include "stdafx.h"

template <typename T>
class NiftyAlloc
{
public:
	template <typename Other>
	struct rebind // The Policy Clone idiom
	{
		typedef NiftyAlloc <Other> other;
	};
	//...
};

template <typename T, class Alloc = NiftyAlloc <T> >
class Vector
{
public:
	typedef typename Alloc::template rebind<long>::other ClonePolicy;
	// Here, Alloc may not be a template class or a parametrized instantiation of
	// a class that takes unknown number of type parameters.
};

void policy_clone()
{

}