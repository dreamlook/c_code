#include<stdio.h>

void f(int **q);

int main(void)
{
	int i = 9;
	int *p = &i;
	printf("%p\n", p);
	f(&p);
	printf("%p\n", p);	
}

void f(int **q)
{
	*q = (int *)0xffffffff;
}
