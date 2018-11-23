#include "stdafx.h"

struct X
{
	void foo() {}
};

X* XfactoryBad()
{
	return new X; // Approach which might cause a leak if is used inproperly
}

std::unique_ptr<X> XfactoryGood() // Resource ownership explicitly transferred to the caller.
{
	//return new X; // Approach wichi might cause a leak
	return std::unique_ptr<X>(new X); // Dynamically allocated instance
}

void resource_return()
{
	XfactoryGood()->foo(); // Dynamically allocated instance of X does not leak here
}