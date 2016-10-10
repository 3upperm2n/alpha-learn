#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

class Stack {
	public:
		Stack();
		~Stack();          // deallocate the stack
		virtual void Push(int value) = 0; 
		// Push an integer, checking for overflow.
		virtual bool Full() = 0;   // Is the stack is full?
};

// For g++, need these even though no data to initialize.
Stack::Stack {}             
Stack::~Stack() {}


class ArrayStack : public Stack {  // the same as in Section 2
	public:
		ArrayStack(int sz);   // Constructor:  initialize variables, allocate space.
		~ArrayStack();        // Destructor:   deallocate space allocated above.
		void Push(int value); // Push an integer, checking for overflow.
		bool Full();     // Returns TRUE if the stack is full, FALSE otherwise.
	private:
		int size;        // The maximum capacity of the stack.
		int top;         // Index of the lowest unused position.
		int *stack;      // A pointer to an array that holds the contents.
};

class ListStack : public Stack {
	public:
		ListStack(); 
		~ListStack();
		void Push(int value);
		bool Full();
	private:
		List *list;         // list of items pushed on the stack
};

ListStack::ListStack() { 
	list = new List;
}

ListStack::~ListStack() { 
	delete list; 
}


void ListStack::Push(int value) {
	list->Prepend(value); 
}

bool ListStack::Full() {
	return FALSE;       // this stack never overflows!
}  


int main(int argc, char**argv)
{

	return 0;
}
