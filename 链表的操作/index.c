# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

//�㷨���룺������ѧ�ϵĶ��� �벻ͨ�Ͳ����� �ѱ��˵Ŀ��� ���� 
//���� ÿ�����Ĺ��� ���� 

typedef struct Node
{
	int data; //������
	struct Node * pNext; //ָ���� 
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
	PNODE pHead = NULL; //�ȼ��� struct Node * pHead = NULL;
	pHead = create_list(); //����һ����ѭ��������
	/*if(is_empty(pHead))
		printf("����Ϊ��\n");
	else
		printf("����Ϊ��\n");
	length = length_list(pHead);
	printf("������Ϊ%d\n",length);
	sort_list(pHead);*/
	insert_list(pHead, 2, 55);
	if(delete_list(pHead, 2, &val))
	{
		printf("ɾ���ɹ���%d\n",val);
	}
	else
	{
		printf("ɾ��ʧ��\n");
	}
	traverse_list(pHead);
	return 0; 
}

PNODE create_list(void)
{
	int len;//��Ч�ڵ����
	int i;
	int val;
	
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if(NULL == pHead)
	{
		printf("����ʧ�ܣ�������ֹ!\n");
		exit(-1);
	}
	PNODE pTail = pHead;//ͷ�ڵ� 
	pTail->pNext = NULL;//β�ڵ� 
	 
	printf("����������ڵ������len = ");
	scanf("%d",&len);
	
	for (i=0; i<len; i++)
	{
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if(NULL == pNew)
		{
			printf("����ʧ�ܣ�������ֹ!\n");
			exit(-1);
		}
		printf("�������%d���ڵ��ֵ:",i+1);
		scanf("%d",&val);
		
		pNew->data = val;//
		pTail->pNext = pNew;//���һ���ڵ� 
		pNew->pNext = NULL;//�½ڵ�ָ��null 
		pTail = pNew;//pNew �����һ���ڵ� 
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
//������㷨�������ݵĴ洢��ʽ�������
//������㷨�������ݵĴ洢��ʽ�޹�
//���ͣ�����ĳ�ּ����ﵽ��Ч�����ǣ���ͬ�Ĵ洢��ʽ��ִ�еĲ�����һ���� 
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
//��pHead��ָ�������ĵ�pos���ڵ��ǰ�����һ���µĽڵ㣬�ýڵ��ֵ��val,����pos�� 
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
		printf("��̬�����ڴ�ʧ�ܣ�\n");
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
	
	//ɾ��p�ڵ����Ľڵ�
	p->pNext = p->pNext->pNext;
	free(q);
	q = NULL; 
	return 1;
} 

