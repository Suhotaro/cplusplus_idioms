#include "stdafx.h"

class UndoString : public std::string
{
	struct proxy
	{
		UndoString * str;
		size_t pos;

		proxy(UndoString * us, size_t position) : str(us), pos(position) {}

		// Invoked when proxy is used to modify the value.
		void operator = (const char & rhs)
		{
			str->old = str->at(pos);
			str->old_pos = pos;
			str->at(pos) = rhs;
		}
		// Invoked when proxy is used to read the value.
		operator const char & () const { return str->at(pos); }
	};

	char old;
	int old_pos;

public:

	UndoString(const std::string & s) : std::string(s), old(0), old_pos(-1) {}
	// This operator replaces std::string's non-const operator [].
	proxy operator [] (size_t index) { return proxy(this, index); }

	//using std::string::operator []; //Not compiled of abiguty =(

	void undo()
	{
		if (old_pos == -1)
			throw std::runtime_error("Nothing to undo!");

		std::string::at(old_pos) = old;
		old = 0;
		old_pos = -1;
	}
};

void modify(char &c)
{
	c = 'Z';
}

void temporary_proxy()
{
	UndoString ustr("More C++ Idioms");
	std::cout << ustr[0];  // Prints 'M'
	ustr[0] = 'm';         // Change 'M' to 'm'
	std::cout << ustr[0];  // Prints 'm'
	ustr.undo();           // Restore'M'
	std::cout << ustr[0];  // Prints 'M'

	//modify(ustr[0]); // Caveate
}