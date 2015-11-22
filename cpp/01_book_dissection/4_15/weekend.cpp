#include <iostream>

using namespace std;

enum weekdays {sun, mon, tue, wed, thu, fri, sat};

static union {
	int i;
	weekdays w;	
};

int main() {

	i = 0;

	if (w==sun || w ==sat) 
		cout << "It is weekend!\n";

	cout << weekdays(i) << endl;

    return 0;
}
