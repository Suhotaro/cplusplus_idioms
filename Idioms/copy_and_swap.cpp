#include "stdafx.h"
#include "copy_and_swap.h"

class String
{
	char * str;
public:
	String & operator=(const String & s) {
		String temp(s); // Copy-constructor -- RAII //note: exception of no memory
		temp.swap(*this); // Non-throwing swap

		return *this;
	}
	// Old resources released when destructor of temp is called.

	void swap(String & s) throw() // Also see the non-throwing swap idiom
	{
		std::swap(this->str, s.str);
	}
};

class String2
{
	char * str;
public:
	String2() {}

	String2 & operator=(String2 s) // <<-- NOTE
	{
		s.swap(*this); // Non-throwing swap
		return *this;
	}
	// Old resources released when destructor of temp is called.

	void swap(String2 & s) throw() // Also see the non-throwing swap idiom
	{
		std::swap(this->str, s.str);
	}
};

class String3
{
	char * str = nullptr;
public:
	String3 & operator=(String3&& s) // <<-- NOTE
	{
		s.swap(*this); // Non-throwing swap
		return *this;
	}
	// Old resources released when destructor of temp is called.

	void swap(String3 & s) throw() // Also see the non-throwing swap idiom
	{
		std::swap(this->str, s.str);
	}
};

void copy_and_swap()
{
	String2 s21;
	String2 s22;
	s22 = s21;
}
