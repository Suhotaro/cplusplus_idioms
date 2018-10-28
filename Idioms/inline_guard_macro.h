#ifndef MYPROJECT_TEST_H // Note include guards.
#define MYPROJECT_TEST_H 

class Test
{
public:
	void func();
};

#ifdef MYPROJECT_INLINE_ENABLED
#define INLINE inline // Define INLINE as inline (the keyword)
#include "test.ipp"   // It is included only when MYPROJECT_INLINE_ENABLED is defined, i.e. inlining is enabled.
#endif

#endif  // MYPROJECT_TEST_H