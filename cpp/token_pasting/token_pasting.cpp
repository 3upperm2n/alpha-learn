// preprocessor_token_pasting.cpp
#include <stdio.h>

#define paster( n ) printf( "token" #n " = %d\n", token##n )

int token9 = 9;

int main()
{
	paster(9);
}
