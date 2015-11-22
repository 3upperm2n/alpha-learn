#include <iostream>
#include <cassert>
//#include <stdio.h>
//#include <stdlib.h>

using namespace std;

struct slistelem {
	char data;
	slistelem *next;	
};

class slist {
	public:
		slist():h(0) {}
		~slist() { 
			cout << "destructor invoked" << endl;
			release(); 
		}
		void prepend(char c);
		void del();
		slistelem *first() const {return h;}
		void print() const;
		void release();
	private:
		slistelem *h;	
};


void slist::prepend(char c) {
	slistelem *temp = new slistelem;	
	assert(temp != 0);
	temp->data = c;	
	temp->next = h;	
	h = temp;			// update head of slist
}

void slist::del() {
	slistelem *temp = h;	
	h = h->next;		// assume non-empty slist	
	delete temp;
}

void slist::print() const {
	slistelem *temp = h;	
	while(temp != 0) {
		cout << temp->data << " -> ";
		temp = temp->next;
	}	
	cout << "\n###" << endl;
}

void slist::release() {
	while(h != 0) del();		
}


int main() {
	slist *p;
	{
		slist w;
		w.prepend('A');
		w.prepend('B');
		w.print();

		w.del();
		w.print();

		p = &w;
		p->print();
		cout << "existing inner block" << endl;
	}
	cout << "existing outer block" << endl;

	return 0;
}
