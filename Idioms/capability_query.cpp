#include "stdafx.h"

class Shape { // An interface class
public:
	virtual ~Shape() {}
	virtual void draw() const = 0;
};

class Rollable { // One more interface class
public:
	virtual ~Rollable() {}
	virtual void roll() = 0;
};

class Circle : public Shape, public Rollable { // circles roll - concrete class
	void draw() const { printf("Circle: draw\n"); }
	void roll() { printf("Circle: roll\n"); }
};

class Square : public Shape { // squares don't roll - concrete class
	void draw() const { printf("Square: draw\n"); }
};

void capability_query()
{
	unique_ptr<Shape> circle = make_unique<Circle>();
	unique_ptr<Shape> square = make_unique<Square>();
	
	Rollable* r;
	r = dynamic_cast<Rollable*>(circle.get());	//Capability query
	if (r) r->roll();

	r = dynamic_cast<Rollable*>(square.get());	//Capability query
	if (r) r->roll();

	//Example: imagine vector of Shapes of Circles and Squares
	//Note: indication of bad OOD
}