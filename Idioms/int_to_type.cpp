#include "stdafx.h"
#include <array>

template <int I>
struct Int2Type
{
	enum { value = I };
}; // Int2Type<5> and Int2Type<10> are different

template <class T, unsigned int N>
class Array : public std::array <T, N>
{
	enum AlgoType { NOOP, INSERTION_SORT, QUICK_SORT };
	static const int algo = (N == 0) ? NOOP :
		(N == 1) ? NOOP :
		(N<50) ? INSERTION_SORT : QUICK_SORT;
	void sort(Int2Type<NOOP>) { std::cout << "NOOP\n"; }
	void sort(Int2Type<INSERTION_SORT>) { std::cout << "INSERTION_SORT\n"; }
	void sort(Int2Type<QUICK_SORT>) { std::cout << "QUICK_SORT\n"; }
public:
	void sort()
	{
		sort(Int2Type<algo>());
	}
};

template <int I>
struct Int2Type2
{
	enum { value = I };
	typedef int value_type;
	typedef Int2Type2<I> type;
	typedef Int2Type2<I + 1> next;
	typedef Int2Type2<I - 1> previous;
};

void int_to_type()
{
	Array<int, 1> a;
	a.sort(); // No-op!
	Array<int, 400> b;
	b.sort(); // Quick sort  
}
