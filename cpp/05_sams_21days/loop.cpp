#include <iostream>

int main()
{
	using namespace std;
	int count = 0;

loop:
	count++;
	cout << "counter : " << count << endl;

	if (count < 5) {
		goto loop;
	}

	cout << "Complete. Counter : " << count << endl;

	return 0;
}
