# include <stdio.h>

typedef int zhangsan;//为已有的数据类型起个名字 

typedef struct Student
{
	int sid;
	char name[100];
	char sex;
}ST;

int main(void)
{
	int i = 10;
	zhangsan j = 20;
	printf("%d  %d\n",i,j);
	
	struct Student st;   //等价于ST st
	struct Student * ps = &st; //等价于ST * ps
	
	ST st2;
	st2.sid = 200;
	printf("%d\n",st2.sid); 
	return 0;
}
