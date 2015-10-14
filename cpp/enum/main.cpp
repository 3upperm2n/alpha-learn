#include <stdio.h>
#include <stdlib.h>
#include <iostream>

enum weekdays {monday, tuesday, wednesday, thursday, friday, saturday, sunday};

weekdays styles[2][7] = {
  {monday, tuesday, wednesday, thursday, friday, saturday, sunday},
  {sunday, monday, tuesday, wednesday, thursday, friday, saturday}
}; 


int main(int argc, char **argv) {
	for(int i; i < 7; i++) {
		std::cout << styles[0][i] << ",\t";
	}
	std::cout << std::endl;

	for(int i; i < 7; i++) {
		std::cout << styles[1][i] << ",\t";
	}
	std::cout << std::endl;
	return 0;	
}
