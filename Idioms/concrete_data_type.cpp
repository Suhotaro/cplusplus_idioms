#include "stdafx.h"

class EventHandler 
{
public:
	virtual ~EventHandler () {}
};
class MouseEventHandler : public EventHandler // Note inheritance
{
 protected:
	~MouseEventHandler () {} // A protected virtual destructor.
 public:
	MouseEventHandler () {} // Public Constructor.
};

//====================================================================

class MouseEventHandler2 // Note no inheritance
{
 protected:
	MouseEventHandler2 () {} // Protected Constructor.
	~MouseEventHandler2 () {} // A protected, non-virtual destructor.
public:
	static MouseEventHandler2 * instance () { return new MouseEventHandler2(); }
	void destroy () { delete this; }  // Reclaim memory.
};

class ScopedLock
{
public:
	static void * operator new (size_t size) = delete;
	static void * operator new (size_t, void * mem) = delete;// Disallow placement new as well.
};

void concrete_data_type()
{
	//MouseEventHandler m; //Impossible since destructor is private

	EventHandler *e = new MouseEventHandler(); // Dynamic allocation is allowed
	delete e;

	MouseEventHandler2* e2 = MouseEventHandler2::instance();
	e2->destroy();

	ScopedLock sl;
	//ScopedLock *sl = new ScopedLock; //forbidden
}