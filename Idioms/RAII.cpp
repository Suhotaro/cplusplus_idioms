#include "stdafx.h"

//  Private copy constructor and copy assignment ensure classes derived 
//  from class NonCopyable cannot be copied.
class NonCopyable
{
public:
	NonCopyable() = default;
private:
	NonCopyable(NonCopyable const &); // private copy constructor
	NonCopyable & operator = (NonCopyable const &); // private assignment operator
};

template <class T>
class AutoDelete : NonCopyable
{
public:
	AutoDelete(T * p = 0) : ptr_(p) {}
	~AutoDelete() throw() { delete ptr_; }
private:
	T *ptr_;
};

class Lock
{
public:
	void acquire() {}
	void release() {}
};

class ScopedLock : NonCopyable // Scoped Lock idiom
{
public:
	ScopedLock(Lock & l) : lock_(l) { lock_.acquire(); }
	~ScopedLock() throw () { lock_.release(); }
private:
	Lock& lock_;
};

void RAII()
{

}