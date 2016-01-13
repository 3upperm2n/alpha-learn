/* File : example.h */
#ifndef _EXAMPLE_H_
#define _EXAMPLE_H_

class Number
{
	public:
		Number(int start);
		~Number(  );
		void add(int value);
		void sub(int value);
		void display();
		int data;
};

#endif
