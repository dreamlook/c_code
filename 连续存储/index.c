# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>//包含了exit

//定义了一个数据类型，该数据的名字叫struct Arr,该数据类型含有三个成员，分别是pBase,len,cnt

struct Arr
{
	int * pBase;//存储的第一个元素的地址
	int len;//数组所能容纳的最大元素的个数
	int cnt;//当前数组有效元素的个数
};

void init_arr(struct Arr * pArr, int length); //分号不能省
int append_arr(struct Arr * pArr, int val);
int insert_arr(struct Arr * pArr, int pos, int val);
int delete_arr(struct Arr * pArr, int pos, int *pVal);
int get();
int is_empty(struct Arr * pArr);
int is_full(struct Arr * pArr);
void sort_arr();
void show_arr(struct Arr * pArr);
void inversion_arr(struct Arr * pArr);

int main(void)
{
	struct Arr arr;
	int val;
	
	init_arr(&arr,6);
	printf("%d\n",arr.len);
	show_arr(&arr);
	append_arr(&arr,1);
	append_arr(&arr,2);
	append_arr(&arr,3);
	if (append_arr(&arr,8))
		printf("׷�ӳɹ�\n");
	else
		printf("׷��ʧ��\n");
	if (delete_arr(&arr,7,&val))
	{
		printf("ɾ���ɹ�\n");
		printf("��ɾ����Ԫ����%d\n",val);
	}
	else
		printf("ɾ��ʧ��\n");
	insert_arr(&arr,1,99);
	printf("����\n");
	show_arr(&arr);
	inversion_arr(&arr);
	printf("����\n");
	show_arr(&arr);
	sort_arr(&arr);
	printf("����\n");
	show_arr(&arr);
	return 0;
}

void init_arr(struct Arr * pArr, int length)
{
	pArr->pBase = (int *)malloc(sizeof(int)* length);
	if (NULL == pArr->pBase)
	{
		printf(" 6666\n");
		exit(-1);//终止整个程序
	}
	else
	{
		pArr->len = length;
		pArr->cnt = 0; 
	}
	return;
}

int is_empty(struct Arr * pArr)
{
	if (0 == pArr->cnt)
		return 1;
	else
		return 0;
		
}
int is_full(struct Arr * pArr)
{
	if (pArr->cnt == pArr->len)
		return 1;
	else
		return 0;
}

void show_arr(struct Arr * pArr)
{
	int i = 0;
	if (is_empty(pArr))//数组为空
	{
		printf("数组为空\n");
	}
	//提示用户数组为空
	else 
	{
		for(i=0; i<pArr->cnt; ++i)
			printf("%d ",pArr->pBase[i]);//int *
		printf("\n");
	}	
	//输出数组有效内容		
}

int append_arr(struct Arr * pArr, int val)
{
	//满是返回false
	if ( is_full(pArr))
		return 0;
	pArr->pBase[pArr->cnt] = val;
	pArr->cnt++;
}

int insert_arr(struct Arr * pArr, int pos, int val)
{
	int i;
	
	if(is_full(pArr))
		return 0;
			
	if(pos<1 || pos>pArr->cnt+1)
		return 0;
		
	for(i=pArr->cnt-1; i>=pos-1; --i)
	{
		pArr->pBase[i+1] = pArr->pBase[i];
	}
	pArr->pBase[pos-1]=val;
	pArr->cnt++;
	return 1;
}

int delete_arr(struct Arr * pArr,int pos, int *pVal)
{
	int i;
	if (is_empty(pArr))
		return 0;
	if (pos<1 || pos>pArr->cnt)
		return 0;
	*pVal = pArr->pBase[pos-1];
	for(i=pos; i<pArr->cnt; ++i)
		{
			pArr->pBase[i-1]= pArr->pBase[i];
		}
	pArr->cnt--;
	return 1;
}

void inversion_arr(struct Arr * pArr)
{
	int i = 0;
	int j = pArr->cnt-1;
	int t;
	while (i < j)
	{
		t = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = t;
		++i;
		--j;
	}
	return ;
}

void sort_arr(struct Arr * pArr)
{
	int i,j,t;
	
	for (i = 0; i<pArr->cnt; i++)
	{
		for(j = i+1; j<pArr->cnt; j++)
		{
			if(pArr->pBase[i] > pArr->pBase[j])
			{
				t = pArr->pBase[i];
				pArr->pBase[i] = pArr->pBase[j];
				pArr->pBase[j] = t;
			}
		}
	}
}

