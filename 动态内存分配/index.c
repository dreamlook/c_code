#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int a[5]={4,10,2,8,6};
	int i = 0;
	
	int len;
	printf("����������Ҫ���������ĳ��ȣ�len=");
	scanf("%d",&len);
	int *pArr = (int*)malloc(sizeof(int) *len);//ǿ��ת��  ֻ�ܷ��ص�һ���ֽڵ�ַ �ɵ�ַ
//	*pArr = 4; //������a[0] = 4;
//	pArr[1] = 10; //������a[1]= 10;
//	
//	printf("%d %d",*pArr,pArr[1]);

	for(i = 0; i<len; ++i)
		scanf("%d",&pArr[i]);
	for(i = 0; i<len; ++i)
		printf("%d\n",*(pArr+i));
	
	
	free(pArr);//��pArr������Ķ�̬�����20���ֽڵ��ڴ��ͷ�
	 
	//��ѭ������������������ֻ��C99��׼��֧�֣�C90��׼��֧��
 } 
