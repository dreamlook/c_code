#include <stdio.h>
#include <malloc.h>

void main(void)
{
	int *p;
	fun(&p);
	printf("%d\n",p);
}
int fun(int **q)
{
	*q=(int *)malloc(4);
}
//上下俩种的对错 与 区别
/*
void main(void)
{
	int *p;
	fun(p);
	printf("%d\n",p);
}
int fun(int *q)
{
	q=(int *)malloc(4);
}
*/
