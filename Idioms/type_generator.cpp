#include "stdafx.h"

/* C++11
template <class Value>
using newType = std::map<std::string,
						 Value,
						 std::less<std::string>,
						 __gnu_cxx::malloc_allocator<std::string>>;
*/

/* Code is ok but I have no __gnu_cxx::malloc_allocator<std::string>
template <class Value>
struct Directory
{
  typedef map <string,
			   Value,
			   less<string>,
			   __gnu_cxx::malloc_allocator<std::string> > type;

  typedef _Select1st<typename type::value_type> KeySelector;
  typedef _Select2nd<typename type::value_type> ValueSelector;
};
Directory<int>::type age;    // This is a map.
*/


void type_generator()
{
	/*
	Directory<int>::type	type1;  // gives a map of string to integers.
	Directory<float>::type	type2; // gives a map of string to floats.

	transform(age.begin(), age.end(),
		std::ostream_iterator<string>(std::cout, "\n"),
		Directory<int>::KeySelector());
	*/

	//NOTE: Main Idea here is that we create new classes which holds
	// typedefs/usings to simplify code redability, remove code duplications
	// and last but not lease consolidate a complicated type expression into a simple one.
}