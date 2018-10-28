#include "stdafx.h"

class shape   // An interface class
{
public:
	virtual ~shape() = default;
	virtual void move_x(int x) = 0;
	virtual void move_y(int y) = 0;
	virtual void draw() = 0;
	//...
};

class line : public shape
{
public:
	virtual ~line() = default;
	virtual void move_x(int x) {} // implements move_x
	virtual void move_y(int y) {} // implements move_y
	virtual void draw() {} // implements draw
private:
	//point end_point_1, end_point_2;
	//...
};

void interface_class()
{
	std::vector<shape *> shapes;
	//  Fill up shapes vector somehow.
	for (vector<shape *>::iterator iter(shapes.begin());
		iter != shapes.end();
		++iter)
	{
		(*iter)->draw();
	}
}