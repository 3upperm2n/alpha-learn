#include <iostream>

using namespace std;

union int_dbl {
	int i;
	double d;	
} n = {0};

int main() {

	cout << n.i << endl;

	n.i = 7;
	cout << "integer : " << n.i << endl;
	cout << "double(machine dependent) : " << n.d << endl;

	n.d = 7;
	cout << "integer(machine dependent) : " << n.i << endl;
	cout << "double : " << n.d << endl;

    return 0;
}
