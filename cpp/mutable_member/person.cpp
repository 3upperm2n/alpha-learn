#include <iostream>
#include <string>

using namespace std;

class person {
private:
	mutable int age;
	// int age;
	const unsigned long soc_sec;
	const string name;

public:	
	person(const string namep, int agep, unsigned long ssn)
	: name(namep), age(agep), soc_sec(ssn) {}

	void bday() const { ++age; }
	// void bday() { ++age; }

	void print() const {
		cout << name << " is " << age << " years old. SSN = " << soc_sec << endl;	
	}

};



int main() {
	const person ylm("leiming yu", 31, 1110111);	
	// person ylm("leiming yu", 31, 1110111);	

	ylm.print();		
	ylm.bday();		
	ylm.print();
}
