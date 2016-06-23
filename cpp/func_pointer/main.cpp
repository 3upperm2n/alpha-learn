#include <stdlib.h>
#include <stdio.h>

void fun1() {
	printf("this is func 1!\n");
}

void fun2() {
	printf("this is func 2!\n");
}

void fun3() {
	printf("this is func 3!\n");
}

void (*func_ptr[3])()= {fun1, fun2, fun3};

int main() {
	func_ptr[0]();	
	func_ptr[2]();	
	func_ptr[1]();	

	return 0;
}
