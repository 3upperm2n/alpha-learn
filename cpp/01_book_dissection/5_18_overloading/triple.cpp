#include <iostream>

using namespace std;

class triple {
private:
	int i,j,k;	
public:
	triple(int a, int b, int c): i(a), j(b), k(c){}	
	void print() const { cout << i << "," << j << "," << k << endl;}
};


triple unauthor(0,0,0);

class t_ptr {
private:
	bool access;
	triple *ptr;

public:	
	t_ptr(bool f, triple *p) : access(f), ptr(p) {}	
	triple* operator->();
};


triple* t_ptr::operator->()
{
	if(access)
		return ptr;	
	else{
		cout << "unauthorized access" << endl;		
		return &unauthor;
	}	
}


int main() {
	triple a(1,2,3), b(4,5,6);	
	t_ptr ta(false, &a), tb(true, &b);

	ta->print();
	tb->print();
	
}
