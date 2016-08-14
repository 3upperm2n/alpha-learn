#include <stdlib.h>
#include <stdio.h>

void fun1(float *x) {
	printf("this is func 1!\n");
}

void fun2(float *x) {
	printf("this is func 2!\n");
}

void fun3(float *x) {
	printf("this is func 3!\n");
}

void (*func_ptr[3])(float *x)= {fun1, fun2, fun3};

int main() {
	float x = 1.1f;
	func_ptr[0](&x);	
	func_ptr[2](&x);	
	func_ptr[1](&x);	

	return 0;
}
