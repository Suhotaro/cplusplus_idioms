#include "stdafx.h"
#include "base_from_member.h"

class fdoutbuf : public std::streambuf {
public:
	explicit fdoutbuf(int fd) {}
};

struct fdostream_pbase // A newly introduced class
{
	fdoutbuf sbuffer; // The member moved 'up' the hierarchy.
	explicit fdostream_pbase(int fd)
		: sbuffer(fd)
	{}
};

class fdostream
	: protected fdostream_pbase // This class will be initialized before the next one.
	, public std::ostream
{
public:
	explicit fdostream(int fd)
		: fdostream_pbase(fd),   // Initialize the newly added base before std::ostream.
		std::ostream(&sbuffer) //  Now safe to pass the pointer
	{}
	//...
};

void base_from_member()
{
	fdostream standard_out(1);
	standard_out << "Hello, World\n";
}
