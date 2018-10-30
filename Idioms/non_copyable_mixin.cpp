#include "stdafx.h"

class NonCopyable
{
protected:
	NonCopyable() {}
	~NonCopyable() {} /// Protected non-virtual destructor
private:
	NonCopyable(const NonCopyable &);
	NonCopyable & operator = (const NonCopyable &);
};
class CantCopy : private NonCopyable
{};

// C++11

void non_copyable_mixin()
{

}