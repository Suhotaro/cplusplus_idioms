#include "stdafx.h"

class Callable
{
public:
	void operator ()()
	{
		printf("Callable: has been called\n");
	}

	int operator ()(int n )
	{
		printf("Callable: has been called with: %d\n", n);
		return n + 1;
	}
};

void function_object()
{
	Callable foo;
	foo();
}