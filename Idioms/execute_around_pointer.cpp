#include "stdafx.h"
#include "execute_around_pointer.h"

//========================================================

class VisualizableVector
{
public:
	class proxy
	{
	public:
		proxy(vector<int> *v) : vect(v)	{ std::cout << "Before size is: " << vect->size(); }
		vector<int> * operator -> ()	{ return vect; }
		~proxy()						{ std::cout << "After size is: " << vect->size(); }
	private:
		vector <int> * vect;
	};

	VisualizableVector(vector<int> *v) : vect(v) {}
	proxy operator -> () { return proxy(vect); }
private:
	vector <int> * vect;
};

//======================================================

template <class NextAspect, class Para>
class Aspect
{
protected:
	Aspect(Para p) : para_(p) {}
	Para  para_;
public:
	NextAspect operator -> () { return NextAspect(para_); }
};

template <class NextAspect, class Para>
struct Visualizing : Aspect <NextAspect, Para>
{
public:
	Visualizing(Para p) : Aspect <NextAspect, Para>(p)	{ std::cout << "Before Visualization aspect" << std::endl; }
	~Visualizing()										{ std::cout << "After Visualization aspect" << std::endl; }
};

template <class NextAspect, class Para>
struct Locking : Aspect <NextAspect, Para>
{
public:
	Locking(Para p) : Aspect <NextAspect, Para>(p)	{ std::cout << "Before Lock aspect" << std::endl; }
	~Locking()										{ std::cout << "After Lock aspect" << std::endl; }
};

template <class NextAspect, class Para>
struct Logging : Aspect <NextAspect, Para>
{
public:
	Logging(Para p) : Aspect <NextAspect, Para>(p)	{ std::cout << "Before Log aspect" << std::endl; }
	~Logging()										{ std::cout << "After Log aspect" << std::endl; }
};

template <class Aspect, class Para>
class AspectWeaver
{
public:
	AspectWeaver(Para p) : para_(p) {}
	Aspect operator -> () { return Aspect(para_); }
private:
	Para para_;
};

#define AW1(T,U) AspectWeaver <T <U, U>, U >
#define AW2(T,U,V) AspectWeaver <T < U <V, V> , V>, V >
#define AW3(T,U,V,X) AspectWeaver <T < U <V <X, X>, X> , X>, X >

void execute_around_pointer()
{
	VisualizableVector vecc (new vector<int>);
	vecc->push_back(1);
	vecc->push_back(2);

	AW3(Visualizing, Locking, Logging, vector <int> *) X(new vector<int>);
	//...
	X->push_back(10); // Note use of -> operator instead of . operator
	X->push_back(20);

	AW1(Logging, vector <int> *) Y(new vector<int>);
	Y->push_back(20);
}
