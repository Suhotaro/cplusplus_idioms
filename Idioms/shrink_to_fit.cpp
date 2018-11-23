#include "stdafx.h"
#include "util.h"

void shrink_to_fit()
{
	std::vector<int> v;
	//v is swapped with its temporary copy, which is capacity optimal

	fill(v);
	std::vector<int>(v).swap(v);

	fill(v);
	//v is swapped with its temporary copy, which is capacity optimal
	std::vector<int>(v.begin(), v.end()).swap(v);


	fill(v);
	v.shrink_to_fit(); //same as uppon one
}