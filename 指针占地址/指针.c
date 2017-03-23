#include<stdio.h>

void main(void)
{
	double *p;
	double x = 66.6;
	
	p = &x;//指针只占四个字节 
	
	double arr[3] = {1.1,2.2,3.3};//8个字节 
	double *q;
	
	q = &arr[0];
	printf("%p\n", q);
	q = &arr[1];
	printf("%p\n", q);
	 
 } 
