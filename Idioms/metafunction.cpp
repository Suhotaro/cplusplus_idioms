#include "stdafx.h"

template <bool, class L, class R>
struct IF
{
	typedef R type;
};

template <class L, class R>
struct IF<true, L, R>
{
	typedef L type;
};

//============================================

template <int N>
struct Factorial
{
	enum { value = N * Factorial<N - 1>::value };
};

template <>
struct Factorial<0>
{
	enum { value = 1 };
};

void metafunction()
{
	IF<false, int, long>::type iLong; // is equivalent to long i;
	IF<true, int, long>::type iInt; // is equivalent to int i;

	int x = Factorial<4>::value; // == 24
	int y = Factorial<0>::value; // == 1
}