#include "stdafx.h"

class Initilaizer
{
	using func = function<void()>;
	using funcs = vector<func>;

public:
	static Initilaizer* Get() {
		static Initilaizer initilaizer;
		return &initilaizer;
	}

	void Init() {
		for (func& f : foos)
			f();
	}

	void Set(func foo) {
		foos.push_back(foo);
	}

private:
	funcs foos;
};

void InitGlobal() { printf("Init Global\n"); }

class Some
{
public:
	Some()
	{
		Initilaizer::Get()->Set([]() { printf("Lambda\n"); });
		Initilaizer::Get()->Set(InitGlobal);
		Initilaizer::Get()->Set([this]() { Init(); });
	}

	void Init()
	{
		printf("Init class\n");
	}
};

Some some; // The Idiom

void attach_by_initialization()
{
	Initilaizer* init = Initilaizer::Get();
	init->Init();
}