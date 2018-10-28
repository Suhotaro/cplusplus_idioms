#include "stdafx.h"

long multiply(int i, int j)
{
	return i * j;
}

//NOTE: during compilation it is taken first, but after instantiation
// there would be an error because of substitution int::multiplication_result\
// but there is non template "multiply" and after failing of instantiating
// non template function is taken without producing an error
template <class T>
typename T::multiplication_result multiply(T t1, T t2)
{
	return t1 * t2;
}

//===================================================================================

template <class T>
struct my_is_pointer
{
	template <class U>
	static char is_ptr(U *);

	template <class X, class Y>
	static char is_ptr(Y X::*);

	template <class U>
	static char is_ptr(U(*)());

	static double is_ptr(...);

	static T t;
	enum
	{
		value = sizeof(is_ptr(t)) == sizeof(char)
	};
};

struct Foo
{
	int bar;
};

void SFINAE()
{
	multiply(4,5);

	typedef int * IntPtr;
	typedef int Foo::* FooMemberPtr;
	typedef int(*FuncPtr)();

	printf("%d\n", my_is_pointer<IntPtr>::value);		// prints 1
	printf("%d\n", my_is_pointer<FooMemberPtr>::value);	// prints 1
	printf("%d\n", my_is_pointer<FuncPtr>::value);		// prints 1
}
