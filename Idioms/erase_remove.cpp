#include "stdafx.h"
#include "erase_remove.h"

template<typename T>
inline void erase_remove_impl(std::vector<T> & v, const T & item)
{
	v.erase(std::remove(v.begin(), v.end(), item), v.end());
}

void erase_remove()
{
	vector<int> v = { 1, 2, 2, 2, 3, 4, 5};
	erase_remove_impl(v, 2);
}