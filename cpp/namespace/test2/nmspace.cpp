#include <stdio.h>

#include <iostream>

//using namespace myname; 
namespace TEST
{
	namespace A
	{
		class A_class
		{
			public:
				void msg() {
					printf("I am msg in A_class under namespace A!\n");
				}	

		};
	}
}

namespace TEST
{
	namespace B
	{
		class B_class
		{
			public:
				void msg() {
					printf("I am msg in B_class under namespace B!\n");
				}	

		};
	}
}

int main(int argc, char **argv) {
	 TEST::A::A_class test_a;
	 test_a.msg();

	 TEST::B::B_class test_b;
	 test_b.msg();

	return 0;	
}
