#include <iostream>
#include "some_class.h"

SomeClass::SomeClass() {
	mValA = mValB = 0;	
	std::cout << "A = " << mValA << ", B = " << mValB << std::endl;
}

SomeClass::SomeClass(int a, int b) {
	mValA = a;
	mValB = b;	
	std::cout << "A = " << mValA << ", B = " << mValB << std::endl;
}

SomeClass::~SomeClass() {
	std::cout << "~A = " << mValA << ", ~B = " << mValB << std::endl;
}
