#include <stdio.h>

void fun(int **q);

void main(void)
{
	int i = 10;
	int j = 9; 
	int *p = &i;
	printf("%d\n",p);
	fun(&p);
	printf("%d\n",p);
	printf("%d\n",&i);
}

void fun(int **q)
{	int j = 9;
	*q = &j;
}
