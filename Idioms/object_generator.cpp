#include "stdafx.h"

template <class T, class U>
std::pair <T, U>
my_make_pair(T t, U u)
{
	return std::pair <T, U>(t, u);
}

class File
{
public:
	void read_line(string s) {}
};

void read_lines(std::vector<File *> files)
{
	std::string arg;
	for_each(files.begin(), files.end(), bind2nd(mem_fun(&File::read_line), arg));
}

void object_generator()
{
	map <int, double> m;

	// Makes code more readable then directly use pair_template. Since types are atomatically deduced
	m.insert(my_make_pair(1, 1.0));
}