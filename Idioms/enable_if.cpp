#include "stdafx.h"
#include "enable_if.h"

template <bool, class T = void>
struct my_enable_if
{};

template <class T>
struct my_enable_if<true, T>
{
	typedef T type;
};

template <class T>
typename my_enable_if<is_arithmetic<T>::value, T>::type
foo(T t)
{
	// ...
	return t;
}

template <class T>
T bar(T t, typename my_enable_if<is_arithmetic<T>::value >::type* dummy = 0)
{
	return t;
}

void enable_if()
{
	int t = foo(111);
	//string s = foo("123"); //impossible to instantiate

	int t2 = bar(222);
	//string s2 = bar("123"); //impossible to instantiate
}
