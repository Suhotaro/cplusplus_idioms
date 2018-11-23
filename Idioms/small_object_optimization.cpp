#include "stdafx.h"

class my_string final
{
	constexpr static auto SMALL_BUFFER_SIZE = 16;

	bool _isAllocated{ false };                       ///< Remember if we allocated memory
	char *_buffer{ nullptr };                         ///< Pointer to the buffer we are using
	char _smallBuffer[SMALL_BUFFER_SIZE] = { '\0' };   ///< Stack space used for SMALL OBJECT OPTIMIZATION

public:
	~my_string()
	{
		if (_isAllocated)
			delete[] _buffer;
	}

	explicit my_string(const char *cStyleString)
	{
		auto stringSize = std::strlen(cStyleString);
		_isAllocated = (stringSize > SMALL_BUFFER_SIZE);
		if (_isAllocated)
			_buffer = new char[stringSize];
		else
			_buffer = &_smallBuffer[0];

		strcpy_s(_buffer, SMALL_BUFFER_SIZE, &cStyleString[0]);
	}

	my_string(my_string &&rhs)
		: _isAllocated(rhs._isAllocated)
		, _buffer(rhs._buffer)
	{
		if (_isAllocated)
		{
			// Prevent double deletion of the memory
			rhs._buffer = nullptr;
		}
		else
		{
			// Copy over data
			strcpy_s(_smallBuffer, SMALL_BUFFER_SIZE, rhs._smallBuffer);
			_buffer = &_smallBuffer[0];
		}
	}
	// Other methods, including other constructors, copy constructor,
	// assignment operators have been omitted for readability
};

void small_object_optimization()
{
	/*

	Small object optimization is a technique which is used within low level data
	structures, for instance the std::string (Sometimes referred to as Short/Small
	String Optimization). It's meant to use stack space as a buffer instead of
	some allocated memory in case the content is small enough to fit within the
	reserved space.

	By adding extra memory overhead and extra calculations, it tries to prevent an
	expensive heap allocation. The benefits of this technique are dependent on the
	usage and can even hurt performance if incorrectly used.

	*/
}