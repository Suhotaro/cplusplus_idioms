#include "stdafx.h"

struct A { A(const std::string & s) {} };

void func(const A & a) {}

void implicit_conversions()
{
	int a = 42;
	int* ptr = &a;
	if (ptr) // checks if ptr is not null_ptr
		;

	//func("one");				// error - requires 2 steps to convert: const char* -> std::string -> A
	func(A("two"));				// ok - converting const char* -> std::string, which is used to create A
	func(std::string("three"));	// ok - implicit conversion std::string -> A
}