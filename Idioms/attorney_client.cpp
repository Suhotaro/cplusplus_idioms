#include "stdafx.h"
#include "attorney_client.h"

class Client
{
private:
	void A(int a) { printf("A\n"); }
	void B(float b) { printf("B\n"); }
	void C(double c) { printf("C\n"); }
	friend class Attorney;
};

class Attorney { // proxy for class Client
private:
	static void callA(Client & c, int a) {
		c.A(a);
	}
	static void callB(Client & c, float b) {
		c.B(b);
	}
	friend class Bar;
};

class Bar {
public:
	void foo(Client &c)
	{
		Attorney::callA(c, 10);
		Attorney::callB(c, 3.14);
	}
};

//----------------------------------------------------------

class Base {
private:
	virtual void Func(int x) = 0;
	friend class Attorney2;
public:
	virtual ~Base() {}
};

class Derived : public Base {
private:
	virtual void Func(int x) {
		printf("Derived::Func\n"); // This is called even though main is not a friend of Derived.
	}

public:
	~Derived() {}
};

class Attorney2 {
public:
	static void callFunc(Base & b, int x) {
		return b.Func(x);
	}
	friend int main(void);
};

//------------------------------------------------------------

void attorney_client()
{
	Client client;
	Bar bar;
	bar.foo(client);

	Derived d;
	Attorney2::callFunc(d, 10);
}