#include<stdio.h>

void show(int *p)
{
	p[0] = -1;
}

void main(void)
{
	int a[5] = {1,2,3,4,5}; 
	show(a);
	printf("%d\n",a[0]);
} 
