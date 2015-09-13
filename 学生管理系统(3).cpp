#include"stdio.h"
#include"stddef.h"
#include"iostream"
#include"string.h"
#define MAX 10
typedef struct student { /*定义结构体*/
	char name[MAX]; /*姓名*/
	int num[MAX]; /* 学号*/
	char sex[MAX]; /*性别*/
	int chinese; /*语文*/
	int mathematic; /* 数学*/
	int english; /*英语*/
	int computer; /*计算机*/
	struct student *next; /*结构体指针*/
}stu;
stu *head; /*头指针*/
void print() /*显示或打印函数*/
{
	system("cls");
	printf("\t\t\tScore Manage System\n"); /*成绩管理系统*/
	printf("<1>Enter Record\t"); /*输入数据*/
	printf("<2>Display\t"); /*显示*/
	printf("<3>Insert\t"); /*插入数据*/
	printf("<4>Quest\t"); /*访问数据*/
	printf("<5>Update\t"); /*以前数据*/
	printf("<6>Save\t"); /*保留数据*/
	printf("<7>Fresh\t"); /*更新数据*/
	printf("<8>Chinese Average\t"); /*语文平均成绩*/
	printf("<9>Math Average\t"); /*数学平均成绩*/
	printf("<10>English Average\t"); /*英语平均成绩*/
	printf("<11>Computer Average\t"); /*计算机平均成绩*/
	printf("<12>Quit\t\n"); /*退出*/
}
void cin(stu *p1) /*输入相关数据的函数*/
{
	printf("Enter name:\n");
	scanf("%s", &p1->name);
	printf("Enter num:\n");
	scanf("%d", &p1->num);
	printf("Enter sex:\n");
	scanf("%s", &p1->sex);
	printf("Enter score:\n");
	printf("Enter chinese:\n");
	scanf("%d", &p1->chinese);
	printf("Enter math:\n");
	scanf("%d", &p1->mathematic);
	printf("Enter English:\n");
	scanf("%d", &p1->english);
	printf("Enter Computer:\n");
	scanf("%d", &p1->computer);
}
stu *cindata() /*其他数据是否继续输入的函数*/
{
	stu *p1, *p2;
	int i = 1;
	char ch;
	p1 = (stu *)malloc(sizeof(stu));
	head = p1;
	while (i)
	{
		cin(p1);
		printf("Do you Want to Continue?yes or no"); /*是否继续输入数据*/
		ch = getchar();
		ch = getchar();
		if (ch == 'n' || ch == 'N')
		{
			i = 0;
			p1->next = NULL;
		}
		else
		{
			p2 = p1;
			p1 = (stu *)malloc(sizeof(stu));
			p2->next = p1;
		}
	}
	return(p1->next);
}
stu *lookdata(stu *p1) /*查看数据的函数*/
{
	while (p1 != NULL)
	{
		printf("Num:%d\t", p1->num);
		printf("Name:%s\t", p1->name);
		printf("Sex:%s\t", p1->sex);
		printf("\n");
		printf("Chinese:%d\t", p1->chinese);
		printf("Math:%d\t", p1->mathematic);
		printf("English:%d\t", p1->english);
		printf("Computer:%d\t", p1->computer);
		printf("\n");
		p1 = p1->next;
	}
	return p1;
}
void insert() /*通过比较学号来插入数据的函数*/
{
	stu *p1, *p3, *p2;
	char ch;
	p1 = head;
	p3 = (stu *)malloc(sizeof(stu));
	p3->next = NULL;
	if (head == NULL) { head = p3; return; }
	cin(p3);
	while (p1 != NULL && (p1->num<p3->num)) /*通过学号的比较来插入*/
	{
		p2 = p1; p1 = p1->next;
	}
	if (p2 == head) { p3->next = head; head = p3; return; }
	p3->next = p1;
	p2->next = p3;
}
void find(stu *p2) /*通过姓名查找查看数据的函数*/
{
	char name[20];
	int b = 0;
	printf("Enter the name of the student you want to find:"); /*通过姓名查看*/
	scanf("%s", name);
	while (p2 != NULL)
	{
		if (strcmp(name, p2->name) == 0)
		{
			printf("The data you want has be found\n");
			printf(" Name:%s\t", p2->name);
			printf("Num:%d\t", p2->num);
			printf("sex%s\t", p2->sex);
			printf("\n");
			printf("Chinese:%d\t", p2->chinese);
			printf("Math:%d\t", p2->mathematic);
			printf("English:%d\t", p2->english);
			printf("Computer:%d\t", p2->computer);
			printf("\n");
			b = 1;
		}
		else if (b == 0)
			printf("sorry not find data!");
		p2 = p2->next;
	}
	if (b == 1)
	{
		print();
		printf("Find one\n");
	}
	else
	{
		print();
		printf("Not find\n");
	}
}
void caverage() /*求各学生语文平均分、最高和最低分成绩的函数*/
{
	stu *p1;
	int i;
	float max = 0.0, min = 200.0;
	float sum = 0.0, aver = 0;
	p1 = head;
	if (p1 == NULL)
		printf("not data!");
	else
	{
		for (i = 0; p1 != NULL; i++, p1 = p1->next)
			sum += p1->chinese;
		aver = sum / i;
		p1 = head;
		for (i = 0; p1 != NULL; i++, p1 = p1->next)
		{
			if (max<p1->chinese)
				max = p1->chinese;
		}
		p1 = head;
		for (i = 0; p1 != NULL; i++, p1 = p1->next)
			if (min>p1->chinese)
				min = p1->chinese;
	}
	printf("Chinese Average:%f", aver);
	printf("Chinese Max:%f", max);
	printf("Chinese Min:%f", min);
}
void maverage() /*求各学生数学平均分、最高和最低分成绩的函数*/
{
	stu *p1;
	int i;
	float max = 0.0, min = 200.0;
	float sum = 0.0, aver = 0;
	p1 = head;
	if (p1 == NULL)
		printf("not data!");
	else
	{
		for (i = 0; p1 != NULL; i++, p1 = p1->next)
			sum += p1->mathematic;
		aver = sum / i;
		p1 = head;
		for (i = 0; p1 != NULL; i++, p1 = p1->next)
		{
			if (max<p1->mathematic)
				max = p1->mathematic;
		}
		p1 = head;
		for (i = 0; p1 != NULL; i++, p1 = p1->next)
			if (min>p1->mathematic)
				min = p1->mathematic;
	}
	printf("Mathe Average:%f", aver);
	printf("Mathe Max:%f", max);
	printf("Mathe Min:%f", min);
}
void eaverage() /*求各学生英语平均分、最高和最低分成绩的函数*/
{
	stu *p1;
	int i;
	float max = 0.0, min = 200.0;
	float sum = 0.0, aver = 0;
	p1 = head;
	if (p1 == NULL)
		printf("not data!");
	else
	{
		for (i = 0; p1 != NULL; i++, p1 = p1->next)
			sum += p1->english;
		aver = sum / i;
		p1 = head;
		for (i = 0; p1 != NULL; i++, p1 = p1->next)
		{
			if (max<p1->english)
				max = p1->english;
		}
		p1 = head;
		for (i = 0; p1 != NULL; i++, p1 = p1->next)
			if (min>p1->english)
				min = p1->english;
	}
	printf("English Average:%f", aver);
	printf("English Max:%f", max);
	printf("English Min:%f", min);
}
void comaverage() /*求各学生计算机平均分、最高和最低分成绩的函数*/
{
	stu *p1;
	int i;
	float max = 0.0, min = 200.0;
	float sum = 0.0, aver = 0;
	p1 = head;
	if (p1 == NULL)
		printf("not data!");
	else
	{
		for (i = 0; p1 != NULL; i++, p1 = p1->next)
			sum += p1->computer;
		aver = sum / i;
		p1 = head;
		for (i = 0; p1 != NULL; i++, p1 = p1->next)
		{
			if (max<p1->computer)
				max = p1->computer;
		}
		p1 = head;
		for (i = 0; p1 != NULL; i++, p1 = p1->next)
			if (min>p1->computer)
				min = p1->computer;
	}
	printf("Computer Average:%f", aver);
	printf("Computer Max:%f", max);
	printf("Computer Min:%f", min);
}
void update(stu *p2) /*通过姓名查找来更新数据*/
{
	char name[10]; /*p2为指向结构体struct student的指针*/
	int b = 0;
	printf("Enter The Name"); /*输入姓名*/
	scanf("%s", name);
	while (p2 != NULL)
	{
		if (strcmp(name, p2->name) == 0)
		{
			printf("Find you data\n");
			scanf("Name:%s", p2->name);
			scanf("Num:%s", p2->num);
			scanf("Sex:%s", p2->sex);
			scanf("Chinese:%d", p2->chinese);
			scanf("Math:%d", p2->mathematic);
			scanf("english:%d", p2->english);
			scanf("Computer:%d", p2->computer);
			printf("Success!");
			b = 1;
		}
		else if (b == 0)
			printf("Sorry not Find data!");
		p2 = p2->next;
	}
	if (b == 0)
	{
		print();
		printf("Sorry not Find data!");
	}
	else
	{
		print();
		printf("Finish!");
	}
}

void save(stu *p2) /*保留数据函数*/
{
	FILE *fp;
	char file[10];
	printf("Enter file name"); /*输入文件名*/
	scanf("%s", file);
	fp = fopen(file, "w");
	while (p2 != NULL)
	{
		fprintf(fp, "%s", p2->name);
		fprintf(fp, "%s", p2->num);
		fprintf(fp, "%s", p2->sex);
		fprintf(fp, "%d", p2->chinese);
		fprintf(fp, "%d", p2->mathematic);
		fprintf(fp, "%d", p2->english);
		fprintf(fp, "%d", p2->computer);
		p2 = p2->next;
	}
	fclose(fp);
}
char password[7] = "123456"; /*定义初始密码*/
void main() /*主函数*/
{
	int choice;
	stu *p2;
	char s[8];
	int flag = 0, i; /*标志项*/
	int n = 3;
	do {
		printf("Enter password:\n");
		scanf("%s", s);
		if (!strcmp(s, password)) /*进行密码匹配验证*/
		{
			printf("PASS\n\n\n");
			flag = 1;
			break;
		}
		else {
			printf("Error Enter again:\n");
			n--;
		}
	} while (n>0);
	if (!flag)
	{
		printf("you have Enter 3 times!"); /*输入密码超过了3次！！*/
		exit(0); /*自动退出*/
	}
	/*密码验证成功后进入的界面*/
	printf("~~~~~~~~~~\t\t\t~~~~~~~~~~~~\n"); /*操作界面*/
	printf("\t\tWelcom to the Mis\n");
	printf("Author:-----\tClass:------\tNum:------\n"); /*作者，班级和号码*/
	printf("Adress:HG\n"); /*地址*/
	printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
	printf("\t\tEnter OP:\n");
	printf("\n\n\n\n");
	printf("==============\t\t==============\n");
	printf("==============\t\t==============\n");
	printf("\t\tEnter the MIS yes or no\n"); /*问进入系统与否*/
	scanf("%d", &choice);
	if (choice == 'n' || choice == 'N')
		exit(1);
	print();
	while (1)
	{
		printf("Enter choice:");
		scanf("%d", &i);
		if (i<1 || i>13)
		{
			printf("Enter num from 1 to 13:\n"); /*再从1-13中进行选择*/
			exit(1);
		}
		switch (i)
		{
		case 1:
			p2 = cindata(); /*其他数据是否继续输入的函数*/
			break;
		case 2:
			p2 = lookdata(head); /*查看数据的函数*/
			break;
		case 3:
			insert(); /*通过比较学号来插入数据的函数*/
			break;
		case 4:
			find(head); /*通过姓名查找查看数据的函数*/
			break;
		case 5:
			update(head); /*通过姓名查找来更新数据*/
			break;
		case 6:
			save(head); /*保留数据函数*/
			break;
		case 7:
			print(); /*显示或打印函数*/
			break;
		case 8:
			caverage(); /*求各学生语文平均分、最高和最低分成绩的函数*/
			break;
		case 9:
			maverage(); /*求各学生数学平均分、最高和最低分成绩的函数*/
			break;
		case 10:
			eaverage(); /*求各学生英语平均分、最高和最低分成绩的函数*/
			break;
		case 11:
			comaverage(); /*求各学生计算机平均分、最高和最低分成绩的函数*/
			break;
		case 12:
			; /*空操作*/
		case 13:
			exit(1); /*退出*/
			break;
		}
		scanf("%d", &i);
	}
}


