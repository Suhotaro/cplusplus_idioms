#include "stdafx.h"

struct C
{
	C() {}
	C(const C&) { std::cout << "A copy was made.\n"; }
};

C f()
{
	//NOTE: there is no copings
	return C(); //RVO is used when a function does not use a named var

	C c;
	//do stuffs with c
	return c; //NRVO because RVO is not possible here. But not all compillers support it

	C c1;
	C c2;
	return true ? c1 : c2; //Neither possible here
}

/*
//No optimization
Hello World!
A copy was made.
A copy was made.

Hello World!
A copy was made.
//RVO
// Pass external var a pointer and crate stack tmp
// after everything is done copy tmp into pointer

Hello World!
//NRVO
// Pass external var a pointer and do stuffs directly
*/

void computational_constructor()
{
	std::cout << "Hello World!\n";
	C obj = f();
}
