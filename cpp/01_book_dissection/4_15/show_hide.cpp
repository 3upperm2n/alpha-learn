#include <iostream>

using namespace std;

class X {
private:
    int hide;

public:
    int visible;
    void print() {
        cout << "\nhide = " << hide << "visible = " << 
            visible;
    }
    void reset() {visible = hide;}
    void set(int i) {hide =  i;}
};

typedef void (X::*pfcn)();

int main() {
    X a, b, *pb = &b;
    int X::*pXint = &X::visible;
    pfcn pF = &X::print;

	a.set(8);a.reset();
	b.set(4);b.reset();
	a.print();

	a.*pXint += 1;
	a.print();

	cout << "\nb.visible = " << b.*pXint; 

	(b.*pF)();

	pF = &X::reset;

	(a.*pF)();
	a.print();

	cout << endl;


    return 0;
}
