#include "stdafx.h"
#include "util.h"

void clear_and_minimize()
{
	std::vector <int> v;
	fill(v);
	std::vector<int>().swap(v); // Clear-and-minimize

	fill(v);
	v.clear(); // Capacity remains

	fill(v);
	v.shrink_to_fit(); // Capacity equal to size

	fill(v);
	v.clear();			// Clear-and-minimize
	v.shrink_to_fit();	//
}