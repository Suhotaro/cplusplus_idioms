#include "stdafx.h"

class ISerializable
{
public:
	virtual int serialize(char *& buffer, size_t & buf_size) const = 0;
};

template <class T>
class Serializable : public T,   /// Parameterized Base Class Idiom
	public ISerializable
{
public:
	Serializable(const T &t = T()) : T(t) {}
	virtual int serialize(char *& buffer, size_t & buf_size) const
	{
		const size_t size = sizeof(T);
		if (size > buf_size)
			throw std::runtime_error("Insufficient memory!");

		memcpy(buffer, static_cast<const T *>(this), size);
		buffer += size;
		buf_size -= size;
		return size;
	}
};

class Student
{
public:
	Student() = default;
	Student(string _name, int _age) : name(_name), age(_age) {}

	string name = "Bob";
	int age;
};


void parameterized_base_class()
{
	Serializable<Student> s;

	vector<char> v;
	v.resize(32);
	char *ptr = v.data();
	size_t size = v.size();
	s.serialize(ptr, size);
}
