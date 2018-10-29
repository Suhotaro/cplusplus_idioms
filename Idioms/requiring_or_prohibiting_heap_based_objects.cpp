#include "stdafx.h"

// Requiring heap-based objects
class HeapOnly {
public:
	HeapOnly() {}
	void destroy() const { delete this; }
protected:
	~HeapOnly() {}
};

//HeapOnly h1;     // Destructor is protected so h1 can't be created globally

void func()  // Compiler error because destructor of temporary is protected
{
	HeapOnly *hoptr = new HeapOnly; // This is ok. No destructor is invoked automatically for heap-based objects
	//return *hoptr;
	return ;
}

void foo(void) {
	//HeapOnly h2; // Destructor is protected so h2 can't be created on stack
}

//========================================================

//Prohibiting heap-based objects
class NoHeap {
protected:
	static void * operator new(std::size_t);      // #1: To prevent allocation of scalar objects
	static void * operator new[](std::size_t);  // #2: To prevent allocation of array of objects
};

class NoHeapTwo : public NoHeap {};


void requiring_or_prohibiting_heap_based_objects()
{
	//new NoHeap;        // Not allowed because of #1
	//new NoHeap[1];     // Not allowed because of #2
	//new NoHeapTwo[10];  // Not allowed because of inherited protected new operator (#2).
}
