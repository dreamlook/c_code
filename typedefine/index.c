# include <stdio.h>

typedef int zhangsan;//Ϊ���е���������������� 

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
	
	struct Student st;   //�ȼ���ST st
	struct Student * ps = &st; //�ȼ���ST * ps
	
	ST st2;
	st2.sid = 200;
	printf("%d\n",st2.sid); 
	return 0;
}
