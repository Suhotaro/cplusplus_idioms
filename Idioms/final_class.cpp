#include "stdafx.h"
#include "final_class.h"

class MakeFinal
{
	MakeFinal() { printf("call\n"); } // private by default.
	friend class sealed;
};

class sealed : virtual MakeFinal {};
class test : public sealed { };

//C++11
class Base final {};
//class Test : public Base {};  // incorrect

void final_class()
{

}
