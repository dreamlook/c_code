# include <stdio.h>

typedef struct Student
{
	int sid;
	char name[100];
	char sex;
}* PST, STU; //µÈ¼ÛÓÚstruct Student * 

int main(void)
{
	//struct Student st;
	STU st;
	PST ps = &st;
	ps->sid = 99;
	printf("%d\n",ps->sid);
	return 0;
}
