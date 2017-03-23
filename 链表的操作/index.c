# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

//算法感想：属于数学上的东西 想不通就不想了 把别人的看懂 背会 
//流程 每个语句的功能 试数 

typedef struct Node
{
	int data; //数据域
	struct Node * pNext; //指针域 
}NODE, *PNODE;//struct Node struct Node *

PNODE create_list(void);
void traverse_list(PNODE pHead);
int is_empty(PNODE pHead);
int length_list(PNODE pHead);
int insert_list(PNODE pHead, int pos, int val);
int delete_list(PNODE pHead, int, int *);
void sort_list(PNODE pHead);

int main(void)
{
	int length;
	int val;
	PNODE pHead = NULL; //等价于 struct Node * pHead = NULL;
	pHead = create_list(); //创建一个非循环单链表
	/*if(is_empty(pHead))
		printf("链表为空\n");
	else
		printf("链表不为空\n");
	length = length_list(pHead);
	printf("链表长度为%d\n",length);
	sort_list(pHead);*/
	insert_list(pHead, 2, 55);
	if(delete_list(pHead, 2, &val))
	{
		printf("删除成功，%d\n",val);
	}
	else
	{
		printf("删除失败\n");
	}
	traverse_list(pHead);
	return 0; 
}

PNODE create_list(void)
{
	int len;//有效节点个数
	int i;
	int val;
	
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if(NULL == pHead)
	{
		printf("分配失败，程序终止!\n");
		exit(-1);
	}
	PNODE pTail = pHead;//头节点 
	pTail->pNext = NULL;//尾节点 
	 
	printf("请输入链表节点个数：len = ");
	scanf("%d",&len);
	
	for (i=0; i<len; i++)
	{
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if(NULL == pNew)
		{
			printf("分配失败，程序终止!\n");
			exit(-1);
		}
		printf("请输入第%d个节点的值:",i+1);
		scanf("%d",&val);
		
		pNew->data = val;//
		pTail->pNext = pNew;//最后一个节点 
		pNew->pNext = NULL;//新节点指向null 
		pTail = pNew;//pNew 成最后一个节点 
	}
	return pHead;	
 }
 
void traverse_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	
	while (NULL != p)
	{
		printf("%d ",p->data);
		p = p->pNext;
	}
	printf("\n");	
	return;	
} 

int is_empty(PNODE pHead)
{
	if(NULL == pHead->pNext)
		return 1;
	else
		return 0;	
}

int length_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	int count;
	while (NULL != p)
	{
		count++;
		p = p->pNext;
	}
	return count;
}
//狭义的算法是与数据的存储方式密切相关
//广义的算法是与数据的存储方式无关
//泛型：利用某种技术达到的效果就是：不同的存储方式，执行的操作是一样的 
void sort_list(PNODE pHead)
{
	int i, j, t;
	int len = length_list(pHead);
	PNODE p,q;
	
	for (i=0, p=pHead->pNext; i<len-1; ++i,p=p->pNext)
	{
		for(j=i+1,q=p->pNext; j<len; ++j,q=q->pNext)
		{
			if(p->data > q->data)
			{
				t = p->data;
				p->data= q->data;//a[i] = a[j];
				q->data =t;//a[j] = t;
			}
		}
	}
	return ;
}
//在pHead所指向的链表的第pos个节点的前面插入一个新的节点，该节点的值是val,并且pos的 
int insert_list(PNODE pHead, int pos, int val)
{
	int i = 0;
	PNODE p = pHead;
	
	while (NULL!=p && i<pos-1)
	{
		p = p->pNext;
		++i;
	}
	if (i>pos-1 || NULL==p)
	{
		printf("hahaha\n");
		return -1;
	}
		
	
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if(NULL == pNew)
	{
		printf("动态分配内存失败！\n");
		exit(-1);
	}
	pNew->data = val;
	printf("pNew->data = %d\n",pNew->data);
	PNODE q = p->pNext;
	p->pNext = pNew;
	pNew->pNext = q;
	return 1;
} 
int delete_list(PNODE pHead, int pos, int * pVal)
{
	int i = 0;
	PNODE p = pHead;
	
	while (NULL!=p->pNext && i<pos-1)
	{
		p = p->pNext;
		++i;
	}
	if (i>pos-1 || NULL==p->pNext)
	{
		printf("hahaha\n");
		return -1;
	}
	
	PNODE q = p->pNext;
	*pVal = q->data;
	
	//删除p节点后面的节点
	p->pNext = p->pNext->pNext;
	free(q);
	q = NULL; 
	return 1;
} 

