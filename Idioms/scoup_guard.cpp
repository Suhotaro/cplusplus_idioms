#include "stdafx.h"

class ScopeGuard
{
public:
	ScopeGuard() : engaged_(true)
	{
		/* Acquire resources here. */
	}

	~ScopeGuard()
	{
		if (engaged_)
		{
			/* Release resources here. */
		}
	}
	void release()
	{
		engaged_ = false;
		/* Resources no longer be released */
	}
private:
	bool engaged_;
};

void scoup_guard()
{
	ScopeGuard guard;
	// ...... Something may throw here. If it does we release resources.
	guard.release(); // Resources will not be released in normal execution.
}
