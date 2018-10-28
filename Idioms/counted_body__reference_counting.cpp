#include "stdafx.h"

class StringRep
{
	friend class String;

	friend std::ostream &operator<<(std::ostream &out, StringRep const &str) {
		out << "[" << str.data_ << ", " << str.count_ << "]";
		return out;
	}

public:
	StringRep(const char *s) : count_(1) {
		strcpy_s(data_ = new char[strlen(s) + 1], strlen(s) + 1, s);
	}

	~StringRep() {
		delete[] data_;
	}

private:
	int count_;
	char *data_;
};

class String
{
public:
	String() : rep(new StringRep("")) {
		std::cout << "empty ctor: " << *rep << "\n";
	}

	String(const String &s) : rep(s.rep)	{
		rep->count_++;
		std::cout << "String ctor: " << *rep << "\n";
	}

	String(const char *s) : rep(new StringRep(s)) {
		std::cout << "char ctor:" << *rep << "\n";
	}

	String &operator=(const String &s) {
		std::cout << "before assign: " << *s.rep << " to " << *rep << "\n";
		String(s).swap(*this);  // copy-and-swap idiom
		std::cout << "after assign: " << *s.rep << " , " << *rep << "\n";
		return *this;
	}

	~String() {  // StringRep deleted only when the last handle goes out of scope.
		if(rep && --rep->count_ <= 0)
		{
			std::cout << "dtor: " << *rep << "\n";
			delete rep;
		}
	}

private:
	void swap(String &s) throw() {
		std::swap(this->rep, s.rep);
	}

	StringRep *rep = nullptr;
};

void counted_body__reference_counting()
{

	std::cout << "*** init String a with empty\n";
	String a;
	std::cout << "\n*** assign a to \"A\"\n";
	a = "A";

	std::cout << "\n*** init String b with \"B\"\n";
	String b = "B";

	std::cout << "\n*** b->a\n";
	a = b;

	std::cout << "\n*** init c with a\n";
	String c(a);

	std::cout << "\n*** init d with \"D\"\n";
	String d("D");
}
