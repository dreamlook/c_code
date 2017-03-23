/*栈
定义 : 一种可以实现先进后出的存储结构 栈类似于箱子 
分类：静态栈 动态栈 
算法：出栈 压栈 
*/
# include <stdio.h>
# include <malloc.h>

typedef struct Node
{
	int data;
	struct Node * pNext;
}NODE, * PNODE;

typedef struct Stack
{
	PNODE pTop;
	PNODE pBottom;
}STACK, *  PSTACK;

void init(PSTACK);
void push(PSTACK pS, int val);
void traverse(PSTACK);
int pop(PSTACK pS, int *pVal);

int main(void)
{
	STACK S;
	
	init(&S);
	push(&S, 1);
	push(&S, 2);
	if( pop(&S,&val) )
	{
		printf("出栈成功， 值为%d\n", val);
	}
	else
	{
		printf("出栈失败\n");
	}
	traverse(&S);
	return 0;
}

void init(PSTACK pS)
{
	pS->pTop = (PNODE)malloc(sizeof(NODE));
	if(NULL==pS->pBottom)
	{
		printf("动态内存分配失败\n");
		exit(-1);	
	}
	else
	{
		pS->pBottom = pS->pTop;
		pS->pTop->pNext = NULL;
	}
	return;
}

void push(PSTACK pS, int val)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	pNew->pNext = pS->pTop;
	pNew->data = val;
	pS->pTop = pNew;
	return;
}

void traverse(PSTACK pS)
{
	PNODE p = pS->pTop;
	
	while(p != pS->pBottom)
	{
		printf("%d ",p->data);
		p = p->pNext;
	}
	printf("\n");
	return;
}
int pop(PSTACK pS, int *pVal)
{
	if(empty(pS))
	{
		return 0;
	}
	else
	{
		PNODE r = pS->pTop;
		*pVal = r->data;
		pS->pTop = r->pNext;
		free(r);
		r= NULL;
		return 1;
	}
}
