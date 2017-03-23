#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int a[5]={4,10,2,8,6};
	int i = 0;
	
	int len;
	printf("请输入您需要分配的数组的长度：len=");
	scanf("%d",&len);
	int *pArr = (int*)malloc(sizeof(int) *len);//强制转换  只能返回第一个字节地址 干地址
//	*pArr = 4; //类似于a[0] = 4;
//	pArr[1] = 10; //类似于a[1]= 10;
//	
//	printf("%d %d",*pArr,pArr[1]);

	for(i = 0; i<len; ++i)
		scanf("%d",&pArr[i]);
	for(i = 0; i<len; ++i)
		printf("%d\n",*(pArr+i));
	
	
	free(pArr);//把pArr所代表的动态分配的20个字节的内存释放
	 
	//在循环条件中声明变量，只在C99标准中支持，C90标准不支持
 } 
