#include <iostream>
#include <set>

using namespace std;

int main() {
	int primes[4]={2,5,3,7};
	int *ptr = primes;

	//set<int, greater<int> > s;
	//set<int, greater<int> > ::const_iterator c_it;

	set<int, less<int> > s;
	set<int, less<int> > ::const_iterator c_it;

	while(ptr != primes + 4) {
		s.insert(*ptr++);		
	}

	for(c_it = s.begin(); c_it != s.end(); ++c_it)
		cout << *c_it << '\t';
	cout<<endl;	
}
