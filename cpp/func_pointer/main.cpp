#include <stdlib.h>
#include <stdio.h>

void fun1(float *x) {
	printf("this is func 1! x = %f\n", *x);
	*x += 1.f;
}

void fun2(float *x) {
	printf("this is func 2! x = %f\n", *x);
	*x += 2.f;
}

void fun3(float *x) {
	printf("this is func 3! x = %f\n", *x);
	*x += 3.f;
}

void (*func_ptr[3])(float *x)= {fun1, fun2, fun3};

int main() {
	float x = 1.1f;
	func_ptr[0](&x);	
	func_ptr[1](&x);	
	func_ptr[2](&x);	

	printf("final x = %f\n", x);

	return 0;
}
