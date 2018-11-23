#include "stdafx.h"

class getRandomN
{
	size_t count;

public:
	getRandomN(int n = 1) : count(n) {}

	template <class Container>
	operator Container () {
		Container c;
		for (size_t i = 0; i < count; ++i)
			c.insert(c.end(), rand()); // push_back is not supported by all standard containers.
		return c;
	}
};

void return_type_resolver()
{
	std::set<int> random_s = getRandomN(10);
	std::vector<int> random_v = getRandomN(10);
	std::list<int> random_l = getRandomN(10);
}