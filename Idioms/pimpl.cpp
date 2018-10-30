#include "stdafx.h"

/*
T& operator= (const T& that)
{
if (this == &that)
return *this;

// handle assignment here

return *this;
}
*/

//====================================

class BookImpl
{
public:
	void print() { std::cout << "print from BookImpl" << std::endl; }
private:
	std::string  m_Contents;
	std::string  m_Title;
};

class Book
{
public:
	Book() : m_p(new BookImpl) {}
	~Book() { delete m_p; }
	void print() { m_p->print(); }
private:
	BookImpl* const m_p;
};

void pimpl()
{
	Book b;
	b.print();
}