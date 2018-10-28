#include "stdafx.h"

//prototype
template <template <class> class ... _PolicyTs> struct GenHierarchy;

//specialization for N policies constructs inheritance hierarchy
template <template <class> class _HeadPolicyT, template <class> class ... _TailPolicyTs>
struct GenHierarchy<_HeadPolicyT, _TailPolicyTs...> : _HeadPolicyT < GenHierarchy<_TailPolicyTs...> > {};

//inheritance hierarchy terminator and base class for concrete implementations
template <> struct GenHierarchy < > {};

//dance behavior policies
template <typename _ParentT> struct DanceA : _ParentT {
	void Dance() { std::cout << __FUNCTION__ << std::endl; }
};

template <typename _ParentT> struct DanceB : _ParentT {
	void Dance() { std::cout << __FUNCTION__ << std::endl; }
};

template <typename _ParentT> struct DanceC : _ParentT {
	void Dance() { std::cout << __FUNCTION__ << std::endl; }
};

//joke behavior policies
template <typename _ParentT> struct JokeA : _ParentT {
	void Joke() { std::cout << __FUNCTION__ << std::endl; }
};

template <typename _ParentT> struct JokeB : _ParentT {
	void Joke() { std::cout << __FUNCTION__ << std::endl; }
};

template <typename _ParentT> struct JokeC : _ParentT {
	void Joke() { std::cout << __FUNCTION__ << std::endl; }
};

//sing behavior policies
template <typename _ParentT> struct SongA : _ParentT {
	void Sing() { std::cout << __FUNCTION__ << std::endl; }
};

template <typename _ParentT> struct SongB : _ParentT {
	void Sing() { std::cout << __FUNCTION__ << std::endl; }
};

template <typename _ParentT> struct SongC : _ParentT {
	void Sing() { std::cout << __FUNCTION__ << std::endl; }
};

//combine some behavior policies into concrete types
using BozoTheClown = GenHierarchy < DanceA, JokeB, SongC >;
using HowdyDoody = GenHierarchy < DanceB, JokeA, SongA >;
using RedButtons = GenHierarchy < DanceC, JokeC, SongB >;
using Red = GenHierarchy < DanceA, DanceC, SongB >;

template <typename _Ty> void Entertain(_Ty oEntertainer) {
	oEntertainer.Sing();
	oEntertainer.Dance();
	oEntertainer.Joke();
}

void hierarchy_generation()
{
	Entertain(BozoTheClown());
	Entertain(HowdyDoody());
	Entertain(RedButtons());

	Red r;
	r.Dance();
}