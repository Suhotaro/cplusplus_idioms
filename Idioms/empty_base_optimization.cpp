#include "stdafx.h"

class EmptyClass {};
EmptyClass arr[10];

class AnInt : public EmptyClass
{
	int data;
};

class AnotherEmpty : public EmptyClass
{};

//------------------------------------------------------

class E1 {};
class E2 {};

class Foo
{
	E1 e1;
	E2 e2;
	int data;
};

// **** after EBCO ****

class Foo2 : private E1, private E2 // using EBCO
{
	int data;
};

// Caveat
template <class Base1, class Base2, class Member>
struct BaseOptimizationWithFunctions : Base1, Base2 
{
	Member member;
	BaseOptimizationWithFunctions() {}
	BaseOptimizationWithFunctions(Base1 const& b1, Base2 const & b2, Member const& mem)
		: Base1(b1), Base2(b2), member(mem) { }
	Base1 * first()  { return this; }
	Base2 * second() { return this; }
};

void empty_base_optimization()
{
	int emptyClassSize = sizeof(EmptyClass); // 1
	int arrEmptyClassSize = sizeof(arr); // 10

	int anotherEmptySize = sizeof(AnotherEmpty); // 1
	int anInt = sizeof(AnInt); // 4

	int fooSize = sizeof(Foo); // 8
	int foo2Size = sizeof(Foo2); // 4 EBCO

	BaseOptimizationWithFunctions<E1, E2, int> item;
	printf("item: %p\n", &item); // pointer

	int templateClass = sizeof(BaseOptimizationWithFunctions<E1, E2, int>); // 8
	E1* e1 = item.first();
	printf("e1: %p\n", e1); // same as item pointer
	E2* e2 = item.second();
	printf("e2: %p\n", e2); // other then item and e1 pointer
}