#include "stdafx.h"

#define named(blockname) goto blockname; \
                         blockname##_skip: if (0) \
                         blockname:

#define break(blockname) goto blockname##_skip

struct test
{
	std::string str;
	test(std::string s) : str(s) {
		std::cout << "test::test()::" << str.c_str() << "\n";
	}
	~test() {
		std::cout << "~test::" << str.c_str() << "\n";
	}
};

void named_loop()
{
	// Problem here is that object are not properly consturcted and destroyed
	named(outer)
	for (int i = 0; i < 10; i++)
	{
		test t1("t1");
		int j = 0;
		named(inner)
			for (test t2("t2"); j < 5; j++)
			{
				test t3("t3");
				if (j == 1) break(outer);
				if (j == 3) break(inner);
				test t4("t4");
			}
		std::cout << "after inner\n";
	}

}