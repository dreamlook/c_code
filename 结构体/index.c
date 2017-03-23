#include <stdio.h>
#include <string.h>

struct Student
{
	int sid;
	char name[200];
	int age;
 };

void fun(struct Student *pst);

void main(void)
{
	struct Student st={1000, "zhangsan", 20};//整体赋值  结构体变量不能加减乘除 但能直接赋值 ;
	struct Student * pst; 
	pst = &st;
	pst->sid = 99;  //第二种方式  pst->sid 等价于 （*pst）.sid 等价于st.sid 
	//pst 所指向的结构体变量中的sid 这个成员 
	fun(&st);
	printf("%d %s %d\n", st.sid, st.name, st.age);
	//st.sid = 99;//第一种方式 

	

	/*printf("%d %s %d\n", st.sid, st.name, st.age);
	
	st.sid = 99;
//	st.name = "lise";
	
	strcpy(st.name, "lisi");
	
	st.age = 30;
	printf("%d %s %d\n", st.sid, st.name, st.age);*/
}

void fun(struct Student *pst)//普通结构体体变量和结构体指针变量作为函数传参的问题 
{
	//(*pst).sid = 99;
	strcpy(pst->name, "zhangsan");
	//指针变量后边可以加-> 不能写. 
	
	pst->age = 22;
	
}

