#include "stdafx.h"
#include "idioms.h"

char* nedmalloc(std::size_t size) { return new char[size]; }
void nedfree(char* value) { delete[] value; }

struct user_allocator_nedmalloc
{
	typedef std::size_t size_type;
	typedef std::ptrdiff_t difference_type;

	static inline char* allocate(const size_type bytes) {
		return reinterpret_cast<char*>(nedmalloc(bytes));
	}

	static inline char* allocate(const size_type bytes, const void *) {
		return reinterpret_cast<char*>(nedmalloc(bytes));
	}

	static inline void free(char* const block) {
		nedfree(block);
	}
};

void free_function_allocators()
{
	//NOTE: quite difficult to implement custom since it must sutisfy the standrd one
	//vector<int, user_allocator_nedmalloc<int>> v; 
	vector<int, allocator<int>> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	v.front();
	v.front();
}
