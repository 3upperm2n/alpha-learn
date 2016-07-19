#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

inline unsigned int upper_power_of_two(unsigned int v)                          
{                                                                               
	v--;                                                                        
	v |= v >> 1;                                                                
	v |= v >> 2;                                                                
	v |= v >> 4;                                                                
	v |= v >> 8;                                                                
	v |= v >> 16;                                                               
	v++;                                                                        
	return v;                                                                   
}   

inline unsigned int regular_compute(unsigned int v)                          
{                                                                               
	v = ((v + 31) / 32 ) * 32;                          
	return v;                                                                   
}   


int main(int argc, char **argv)
{
	int iters = atoi(argv[1]);
	int number = atoi(argv[2]);

	float ms;
	long seconds, useconds;
	double mtime;

	struct timeval startc, end;

	// option 1
	gettimeofday(&startc, NULL);

	for(int i=0; i<iters; i++)
		upper_power_of_two(number);                          

	gettimeofday(&end, NULL);

	seconds  = end.tv_sec  - startc.tv_sec;
	useconds = end.tv_usec - startc.tv_usec;
	mtime = useconds;
	mtime/=1000;
	mtime+=seconds*1000;

	printf("%f ms\n", mtime);


	// option 2
	gettimeofday(&startc, NULL);

	for(int i=0; i<iters; i++)
		regular_compute(number);

	gettimeofday(&end, NULL);

	seconds  = end.tv_sec  - startc.tv_sec;
	useconds = end.tv_usec - startc.tv_usec;
	mtime = useconds;
	mtime/=1000;
	mtime+=seconds*1000;

	printf("%f ms\n", mtime);

	return 0;
}
