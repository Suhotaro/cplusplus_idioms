#pragma once

class Object;
//void delete_object(Object* p);

template<class T>
inline void my_checked_delete(T * x)
{
	typedef char type_must_be_complete[sizeof(T) ? 1 : -1];
	(void) sizeof(type_must_be_complete);
	delete x;
}

template<class T>
struct checked_deleter : std::unary_function <T *, void>
{
	void operator()(T * x) const
	{
		//boost::checked_delete(x); // bost version
	}
};