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
	struct Student st={1000, "zhangsan", 20};//���帳ֵ  �ṹ��������ܼӼ��˳� ����ֱ�Ӹ�ֵ ;
	struct Student * pst; 
	pst = &st;
	pst->sid = 99;  //�ڶ��ַ�ʽ  pst->sid �ȼ��� ��*pst��.sid �ȼ���st.sid 
	//pst ��ָ��Ľṹ������е�sid �����Ա 
	fun(&st);
	printf("%d %s %d\n", st.sid, st.name, st.age);
	//st.sid = 99;//��һ�ַ�ʽ 

	

	/*printf("%d %s %d\n", st.sid, st.name, st.age);
	
	st.sid = 99;
//	st.name = "lise";
	
	strcpy(st.name, "lisi");
	
	st.age = 30;
	printf("%d %s %d\n", st.sid, st.name, st.age);*/
}

void fun(struct Student *pst)//��ͨ�ṹ��������ͽṹ��ָ�������Ϊ�������ε����� 
{
	//(*pst).sid = 99;
	strcpy(pst->name, "zhangsan");
	//ָ�������߿��Լ�-> ����д. 
	
	pst->age = 22;
	
}

