#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

class Stack {
	public:
		Stack (int sz);
		~Stack();
		void Push(int value);
		bool Full() const;
	private:
		int top;
		int size;
		//int stack[10];
		int *stack;
};


void Stack::Push(int value) {
	assert(!Full());
	stack[top++] = value;
}


bool Stack::Full() const
{
	return (top == 10);
}

Stack::Stack (int sz) 
{
	size = sz;
	top = 0;
	stack = new int[size];
}

Stack::~Stack()
{
	delete [] stack;
}


void test()
{
	Stack s1(17);
	Stack *s2 = new Stack(23);
}


int main(int argc, char**argv)
{
	test();

	return 0;
}
