#include "stdafx.h"
#include "util.h"

void fill(std::vector <int>& v)
{
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.pop_back();
	v.pop_back();
	v.pop_back();
}