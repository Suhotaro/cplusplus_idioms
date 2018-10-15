#include "stdafx.h"
#include "checked_delete.h"
#include "deleter.h"
#include "object.h"

void checked_delete()
{
	Object* p = new Object;
	my_checked_delete(p);
}