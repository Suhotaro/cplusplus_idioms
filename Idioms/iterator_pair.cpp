#include "stdafx.h"
#include "idioms.h"

template <class T>
class my_vector
{
	T * mem;
public:
	template <class InputIterator>
	my_vector(InputIterator begin, InputIterator end) // Iterator-pair constructor
	{
		// allocate enough memory and store in mem.
		mem = new T[std::distance(begin, end)];
		for (int i = 0; begin != end; ++i)
		{
			mem[i] = *begin;
			++begin;
		}
	}
};

void iterator_pair()
{
	vector<int> v = {1,2,3};
	my_vector<int> mv(v.begin(), v.end());

	int v2[3];
	v2[0] = 1;
	v2[1] = 2;
	v2[2] = 3;
	my_vector<int> mv2(v2, v2 + sizeof(v2)/sizeof(*v2));
}