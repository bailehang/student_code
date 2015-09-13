#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<string.h>

#define MAXSIZE 50

#define Up 72

#define Down 80

#define Left 75

#define Right 77

#define Esc 27

#define  NT  "\n\n\n\t\t\t"

typedef struct {//学生信息

	long snum;

	char name[10];//姓名

	int rank;// 名次

	float score[4];//四科成绩

	float average;//平均分

}stu;

typedef struct {

	stu date[MAXSIZE];//学生信息

	int num;//实际学生人数

}student;




int BUBB;//设置排序方式

int PASS;//设置合格分数




void interface_welcome(student *s);//第一界面

int interface_settings_option(student *s);//选择设置界面

int interface_settings_bubblesort_option(student *s);//设置排序选择界面

int interface_student(student *s);//学生管理系统界面

int interface_student_option(student *s);//选择学生记录界面

int interface_alter(student *s);//修改学生记录属性选择

int interface_select(student *s);//查询学生记录界面

int interface_select_course(student *s);//查询科目选择界面

void about(student *s);//关于

void settings(student *s);//设置

void alter(student *s);//修改

void deletedate(student *s);//删除

void update(student *s);//新建

void select(student *s);//查询

int check_snum(student *s, long  snum);//检测学号

int check_score(int score);//检测成绩

void pass(student *s, student *r, int I);//储存科目合格学生记录

void notpass(student *s, student *r, int I);//储存科目不合格学生记录

float avg(student *s, int I);//求各科目平均分

void more_avg(student *s, student *r, int I);//储存科目高于或等于平均分学生记录

void less_avg(student *s, student *r, int I);//储存科目低于平均分学生记录

void statistics(student *s);//统计信息

void bubblesort(student *s);//排序

void fscanfstudent(student *s);//学生记录从硬盘写进内存

void fprintfstudent(student *s);//学生记录从内存写进硬盘（保存）

void fscanfsettings();//设置参数从硬盘写进内存

void fprintfsettings();//设置参数从内存写进硬盘（保存）

void fprintftxt(student *s);//学生记录从内存写进txt



void interface_welcome(student *s) {//第一界面　

	int A = 0;

	char ch;

	while (1)

	{
		system("cls");

		puts("\n\n\n\n\n");

		puts("\t\t ________________________________________________ ");

		puts("\t\t|                                                |");

		puts("\t\t|                学生成绩管理系统                |");

		puts("\t\t|                                                |");

		puts("\t\t|________________________________________________|");

		puts("\t\t|                                                |");

		switch (A) {

		case 0:puts("\t\t|    →【进入】  【退出】  【设置】  【其他】    |");

			if (ch == '\r') interface_student(s); break;

		case 1:puts("\t\t|      【进入】→【退出】  【设置】  【其他】    |");

			if (ch == '\r') {
				puts("\t\t|________________________________________________|");
				exit(1);
			}break;

		case 2:puts("\t\t|      【进入】  【退出】→【设置】  【其他】    |");

			if (ch == '\r') settings(s); break;

		case 3:puts("\t\t|      【进入】  【退出】  【设置】→【其他】    |");

			if (ch == '\r') about(s); break;

		}

		puts("\t\t|________________________________________________|");

		ch = getch();

		if (ch == Right) A++;

		if (ch == Left) A--;

		A += 4;

		A %= 4;

	}

}




int interface_student(student *s) {//学生管理 

	int A = 0, i;

	char ch;

	bubblesort(s);

	while (1)
	{

		system("cls");

		puts("\n");

		puts("    ___________________________________________________________________");

		puts("   |     学号   |  姓名 |名次| 数学  | 英语  | 物理  | 计算机 | 平均分 |");

		puts("   |-------------------------------------------------------------------|");

		for (i = 0; i<s->num; i++)

			printf("   | %-11ld| %-6s| %-2d | %-6.1f| %-6.1f| %-6.1f| %-6.1f | %-6.2f |\n", s->date[i].snum, s->date[i].name, s->date[i].rank, s->date[i].score[0], s->date[i].score[1], s->date[i].score[2], s->date[i].score[3], s->date[i].average);

		puts("   |___________________________________________________________________|");

		printf("\n");

		switch (A) {

		case 0:puts("        →【修改】  【删除】  【新建】  【查询】  【返回主界面】");

			if (ch == '\r') alter(s); break;

		case 1:puts("          【修改】→【删除】  【新建】  【查询】  【返回主界面】");

			if (ch == '\r') deletedate(s); break;

		case 2:puts("          【修改】  【删除】→【新建】  【查询】  【返回主界面】");

			if (ch == '\r') update(s); break;

		case 3:puts("          【修改】  【删除】  【新建】→【查询】  【返回主界面】");

			if (ch == '\r') select(s); break;

		case 4:puts("          【修改】  【删除】  【新建】  【查询】→【返回主界面】");

			if (ch == '\r') interface_welcome(s);

		}

		puts("\n\n（按方向键选择操作，按Enter确定。）");

		ch = getch();

		if (ch == Right) A++;

		if (ch == Left) A--;

		A += 5;

		A %= 5;

	}

}




int interface_student_option(student *s) {//选择学生记录界面

	int A = 0, i;

	char ch;

	system("cls");

	if (s->num == 0) {//检查学生记录是否为空

		system("cls");

		printf("\n\n\t学生记录为空，按任意键返回。");

		getch();

		interface_student(s);

	}

	do {

		puts("\n");

		puts("    ___________________________________________________________________");

		puts("   |     学号   |  姓名 |名次| 数学  | 英语  | 物理  | 计算机 | 平均分 |");

		puts("   |-------------------------------------------------------------------|");

		for (i = 0; i<s->num; i++) {

			if ((A%s->num) == i) printf(" →");

			else printf("   ");

			printf("   | %-11ld| %-6s| %-2d | %-6.1f| %-6.1f| %-6.1f| %-6.1f | %-6.2f |\n", s->date[i].snum, s->date[i].name, s->date[i].rank,

				s->date[i].score[0], s->date[i].score[1], s->date[i].score[2], s->date[i].score[3], s->date[i].average);

		}

		puts("   |____________________________________________________________________|");

		puts("\n\n（按方向键选择学生记录,按Enter确定，按Esc取消选择。）\n");

		ch = getch();

		if (ch == Down) A++;

		if (ch == Up) A--;

		if (ch<0) A += s->num;

		if (ch == '\r') break;

		if (ch == Esc) {//取消选择，不返回下标，返回-1

			system("cls");

			return -1;

		}

		system("cls");

	} while (1);

	system("cls");

	return A % (s->num);//返回选择的学生记录的下标

}




int interface_alter(student *s) {//修改学生记录属性选择

	int A = 0;

	char ch;

	while (1) {

		switch (A) {

		case 0:puts("\n\n →[学号]   [姓名]     [数学]   [英语]   [物理]   [计算机]");

			if (ch == '\r') return A; break;//返回选择学生属性（参数）

		case 1:puts("\n\n   [学号] →[姓名]     [数学]   [英语]   [物理]   [计算机]");
			if (ch == '\r') return A; break;//返回选择学生属性（参数）

		case 2:puts("\n\n   [学号]   [姓名]   →[数学]   [英语]   [物理]   [计算机]");

			if (ch == '\r') return A; break;//返回选择学生属性（参数）

		case 3:puts("\n\n   [学号]   [姓名]     [数学] →[英语]   [物理]   [计算机]");

			if (ch == '\r') return A; break;//返回选择学生属性（参数）

		case 4:puts("\n\n   [学号]   [姓名]     [数学]   [英语] →[物理]   [计算机]");

			if (ch == '\r') return A; break;//返回选择学生属性（参数）

		case 5:puts("\n\n   [学号]   [姓名]     [数学]   [英语]   [物理]  →[计算机]");

			if (ch == '\r') return A; break;//返回选择学生属性（参数）

		}

		puts("\n\n（按方向键选择属性，按Enter确定，按Esc退出。）");

		ch = getch();

		system("cls");

		if (ch == Esc) alter(s);

		if (ch == Right) A++;

		if (ch == Left) A--;

		A += 6;

		A %= 6;

	}

}







int interface_settings(student *s) {//选择设置界面

	int A = 0;

	char ch;

	while (1) {

		system("cls");

		switch (A) {

		case 0:puts("→【设置学生记录排序】""  【设置合格分数】""  【退出设置】");

			if (ch == '\r') return A; break;

		case 1:puts("  【设置学生记录排序】""→【设置合格分数】""  【退出设置】");

			if (ch == '\r') return A; break;

		case 2:puts("  【设置学生记录排序】""  【设置合格分数】""→【退出设置】");

			if (ch == '\r') return -1;

		}

		ch = getch();

		if (ch == Down) A++;

		if (ch == Up) A--;

		A += 3;

		A %= 3;

	}

}




int interface_settings_bubblesort_option(student *s) {//设置排序选择界面

	int A = 0;

	char ch;

	while (1) {

		system("cls");

		printf("\n\n当前排序设置为：");

		BUBB ? printf("按学号进行排序\n") : printf("按名次进行排序\n");

		switch (A) {

		case 0:puts("\n\n\t→[按学号进行排序]     [按名次进行排序]");

			if (ch == '\r') return 1; break;

		case 1:puts("\n\n\t  [按学号进行排序]   →[按名次进行排序]");

			if (ch == '\r') return 0;

		}

		puts("\n\n（按方向键选择排序方式，按Enter确定，按Esc取消。）");

		ch = getch();

		if (ch == Esc) settings(s);

		if (ch == Right) A++;

		if (ch == Left) A--;

		A += 2;

		A %= 2;

	}

}










int interface_select(student *s) {//查询学生记录界面

	int A = 0;

	char ch;

	while (1) {

		system("cls");

		switch (A) {

		case 0:puts("\t\t\t→[按姓名]"  NT  "  [按学号]" NT "  [按合格]" NT "  [按不合格]" NT "  [按高于或等于平均分]" NT "  [按低于平均分]" NT "  [统计信息]" NT );

			if (ch == '\r') return A; break;

		case 1:puts("\t\t\t  [按姓名]" NT "→[按学号]" NT "  [按合格]" NT "  [按不合格]" NT "  [按高于或等于平均分]" NT "  [按低于平均分]" NT "  [统计信息]" NT );

			if (ch == '\r') return A; break;

		case 2:puts("\t\t\t  [按姓名]" NT "  [按学号]" NT "→[按合格]" NT "  [按不合格]" NT "  [按高于或等于平均分]" NT "  [按低于平均分]" NT "  [统计信息]" NT );

			if (ch == '\r') return A; break;

		case 3:puts("\t\t\t  [按姓名]" NT "  [按学号]" NT "  [按合格]" NT "→[按不合格]" NT "  [按高于或等于平均分]" NT "  [按低于平均分]" NT "  [统计信息]" NT );

			if (ch == '\r') return A; break;

		case 4:puts("\t\t\t  [按姓名]" NT "  [按学号]" NT "  [按合格]" NT "  [按不合格]" NT "→[按高于或等于平均分]" NT "  [按低于平均分]" NT "  [统计信息]" NT );

			if (ch == '\r') return A; break;

		case 5:puts("\t\t\t  [按姓名]" NT "  [按学号]" NT "  [按合格]" NT "  [按不合格]" NT "  [按高于或等于平均分]" NT "→[按低于平均分]" NT "  [统计信息]" NT );

			if (ch == '\r') return A; break;

		case 6:puts("\t\t\t  [按姓名]" NT "  [按学号]" NT "  [按合格]" NT "  [按不合格]" NT "  [按高于或等于平均分]" NT "  [按低于平均分]" NT "→[统计信息]" NT );

			if (ch == '\r') return A;

		}

		puts("（按方向键选择排序方式，按Enter确定，按Esc取消。）");

		ch = getch();

		if (ch == Esc) interface_student(s);

		if (ch == Down) A++;

		if (ch == Up) A--;

		A += 7;

		A %= 7;

	}

}




int interface_select_course(student *s) {//查询科目选择界面

	int A = 0;

	char ch;

	while (1) {

		switch (A) {

		case 0:puts("\n\n→[数学]   [英语]   [物理]    [计算机]   [任意科目]");

			if (ch == '\r') { printf("\n\n[数学]"); return A; }break;

		case 1:puts("\n\n  [数学] →[英语]   [物理]    [计算机]   [任意科目]");
			if (ch == '\r') { printf("\n\n[英语]"); return A; }break;

		case 2:puts("\n\n  [数学]   [英语] →[物理]    [计算机]   [任意科目]");
			if (ch == '\r') { printf("\n\n[物理]"); return A; }break;

		case 3:puts("\n\n  [数学]   [英语]   [物理]  →[计算机]   [任意科目]");
			if (ch == '\r') { printf("\n\n[计算机]"); return A; }break;

		case 4:puts("\n\n  [数学]   [英语]   [物理]    [计算机] →[任意科目]");

			if (ch == '\r') { printf("\n\n[任意科目]"); return A; }break;

		}

		puts("\n\n（按方向键选择，按Enter确定，按Esc退出。）");

		ch = getch();

		system("cls");

		if (ch == Esc) alter(s);

		if (ch == Right) A++;

		if (ch == Left) A--;

		A += 5;

		A %= 5;

	}

}







void interface_select_results(student *r, student *s) {//查询学生记录结果显示

	int i;

	if (r->num == 0) {

		printf("\n\n\t找不到学生记录！按任意键返回。");

		getch();

		select(s);

	}

	puts("\n");

	puts("    ___________________________________________________________________");

	puts("   |     学号   |  姓名 |名次| 数学  | 英语  | 物理  | 计算机 | 平均分 |");

	puts("   |-------------------------------------------------------------------|");

	for (i = 0; i<r->num; i++)

		printf("   | %-11ld| %-6s| %-2d | %-6.1f| %-6.1f| %-6.1f| %-6.1f | %-6.2f |\n", r->date[i].snum, r->date[i].name, r->date[i].rank,

			r->date[i].score[0], r->date[i].score[1], r->date[i].score[2], r->date[i].score[3], r->date[i].average);

	puts("   |____________________________________________________________________|");

	printf("\n\n按任意键返回。");

	getch();

}







void about(student *s) {

	system("cls");
	puts("________________________________________");

	puts(" ");

	puts("\n 1.输出文本文件");

	puts("\n 2.等待开发");

	puts("\n 3.");

	puts("\n 4.");

	puts("\n 5.");

	puts("\n 6.");

	puts("\n 7.");

	puts("________________________________________");

	puts("\n\n\n       ");

	int i;

	printf("输入对应选项：");

	scanf("%d", &i);

	switch (i)
	{
	case 1:
		fprintftxt(s);
		printf("已输出在根目录");
		break;

	case 2:
		printf("等待开发");
		break;
	}

	puts("\n\n（按任意键退出。）");

	getch();

	interface_welcome(s);

}




void update(student *s) {//新建记录

	char ch, name[10];

	float score[4];

	long  snum;

	s->date[s->num].rank = 0;

	while (1) {

		fflush(stdin);

		system("cls");

		printf("请输入学生学号：");

		scanf("%ld", &snum);

		if (check_snum(s, snum)) continue;

		printf("请输入学生姓名：");

		scanf("%s", name);

		printf("请输入学生《数学》成绩：");

		scanf("%f", &score[0]);

		if (check_score(score[0])) continue;

		printf("请输入学生《英语》成绩：");

		scanf("%f", &score[1]);

		if (check_score(score[1])) continue;

		printf("请输入学生《物理》成绩：");

		scanf("%f", &score[2]);

		if (check_score(score[2])) continue;

		printf("请输入学生《计算机》成绩：");

		scanf("%f", &score[3]);

		if (check_score(score[3])) continue;

		break;

	}

	printf("\n\n按Enter键新建学生记录，按Esc键取消新建。\n");

	while (1) {

		ch = getch();//确认是否新建记录

		if (ch == Esc) interface_student(s);

		if (ch == '\r') break;

	}

	s->date[s->num].snum = snum;

	s->date[s->num].score[0] = score[0];

	s->date[s->num].score[1] = score[1];

	s->date[s->num].score[2] = score[2];

	s->date[s->num].score[3] = score[3];

	strcpy(s->date[s->num].name, name);

	s->date[s->num].average = (s->date[s->num].score[0] + s->date[s->num].score[1]

		+ s->date[s->num].score[2] + s->date[s->num].score[3]) / 4;

	(s->num)++;

	fprintfstudent(s);

	interface_student(s);

}




void deletedate(student *s) {//删除记录

	int A, i;

	char ch;

	A = interface_student_option(s);//A得到选择的学生记录下标

	if (A == -1) interface_student(s);

	printf("\n\n按Enter删除学生记录，按Esc键取消删除。\n");

	while (1) {

		ch = getch();//确认是否删除记录

		if (ch == Esc) interface_student(s);

		if (ch == '\r') break;

	}

	for (i = A; i<s->num - 1; i++)

		s->date[i] = s->date[i + 1];

	s->num -= 1;

	fprintfstudent(s);

	interface_student(s);

}




void alter(student *s) {//修改记录

	int A, I;//A得到选择的学生记录下标

	long snum;

	float score[4];

	char ch, name[10];

	A = interface_student_option(s);

	if (A == -1) interface_student(s);

	snum = s->date[A].snum;

	score[0] = s->date[A].score[0];

	score[1] = s->date[A].score[1];

	score[2] = s->date[A].score[2];

	score[3] = s->date[A].score[3];

	strcpy(name, s->date[A].name);

	I = interface_alter(s);//获取选择功能的学生属性(参数)

	while (1) {

		fflush(stdin);

		system("cls");

		switch (I) {

		case 0:printf("\n\n请输入学生学号：");

			scanf("%d", &snum);

			if (s->date[A].snum == snum) break;//修改学号与当前学号相同，不算输入错误

			if (check_snum(s, snum)) continue; break;//对输入学号进行检测

		case 1:printf("\n\n请输入学生姓名：");

			scanf("%s", name); break;

		case 2:printf("\n\n请输入学生《数学》成绩：");

			scanf("%f", &score[0]);

			if (check_score(score[0])) continue; break;//对输入成绩进行检测

		case 3:printf("\n\n请输入学生《英语》成绩：");

			scanf("%f", &score[1]);

			if (check_score(score[1])) continue; break;//对输入成绩进行检测

		case 4:printf("\n\n请输入学生《物理》成绩：");

			scanf("%f", &score[2]);

			if (check_score(score[2])) continue; break;//对输入成绩进行检测

		case 5:printf("\n\n请输入学生《计算机》成绩：");

			scanf("%f", &score[3]);

			if (check_score(score[0])) continue;//对输入成绩进行检测

		}

		break;

	}

	printf("\n\n按Enter修改学生记录，按Esc取消修改。\n");

	while (1) {

		ch = getch();

		if (ch == Esc) interface_student(s);

		if (ch == '\r') break;

	}

	s->date[A].snum = snum;

	s->date[A].score[0] = score[0];

	s->date[A].score[1] = score[1];

	s->date[A].score[2] = score[2];

	s->date[A].score[3] = score[3];

	strcpy(s->date[A].name, name);

	s->date[A].average = (s->date[A].score[0] + s->date[A].score[1]

		+ s->date[A].score[2] + s->date[A].score[3]) / 4;

	fprintfstudent(s);

	interface_student(s);

}




void select(student *s) {//查询记录

	int A, i, j = 0, I;

	long snum;

	char name[10];

	student r;

	r.num = 0;

	A = interface_select(s);

	system("cls");

	fflush(stdin);

	switch (A) {

	case 0:printf("请输入查找学生姓名：");

		scanf("%s", name);

		for (i = 0; i<s->num; i++) {

			if (!strcmp(s->date[i].name, name))

				r.date[j++] = s->date[i];

		}

		r.num = j;

		printf("\n查询名字为“%s”的学生记录结果如下：\n", name);

		break;

	case 1:printf("请输入查找学生学号：");

		scanf("%ld", &snum);

		for (i = 0; i<s->num; i++) {

			if (s->date[i].snum == snum)

				r.date[j++] = s->date[i];

		}

		r.num = j;

		printf("\n查询学号为%d的学生记录结果如下：\n", snum);

		break;

	case 2:I = interface_select_course(s); printf("合格学生记录结果如下：\n"); pass(s, &r, I); break;

	case 3:I = interface_select_course(s); printf("不合格学生记录结果如下：\n"); notpass(s, &r, I); break;

	case 4:I = interface_select_course(s); printf("平均分为%.2f，高于或等于平均学生记录结果如下：", avg(s, I)); more_avg(s, &r, I); break;

	case 5:I = interface_select_course(s); printf("平均分为%.2f，低于平均学生记录结果如下：", avg(s, I)); less_avg(s, &r, I); break;

	case 6:statistics(s); printf("\n\n按任意键返回。"); getch(); select(s);

	}

	interface_select_results(&r, s);

	select(s);

}




void settings(student *s) {//设置

	int A, pass;

	char ch;

	A = interface_settings(s);//获取选择设置的选项（参数）

	if (A == -1) interface_welcome(s);

	if (A == 0) {

		BUBB = interface_settings_bubblesort_option(s);

		fscanfsettings();

		settings(s);

	}

	if (A == 1) {

		while (1) {

			system("cls");

			printf("\n\n当前设置合格分数为：%d", PASS);

			printf("\n\n更改合格分数为：");

			scanf("%d", &pass);

			if (pass >= 0 && pass <= 100) break;

			else { printf("输入合格分数有误,请按任意键重新输入。"); getch(); }

		}

		printf("\n\n按Enter确定保存设置，按Esc键取消保存设置。\n");

		while (1) {

			ch = getch();

			if (ch == '\r') { PASS = pass; fscanfsettings(); settings(s); }

			if (ch == Esc)  settings(s);

		}

	}

}




int check_snum(student *s, long snum) {//检测学生学号是否输入错误

	int i, t = 0;

	if (snum<1000000000 || snum>2000000000) {//如果学号范围有错误执行

		printf("输入有误，学号范围为（1000000000-2000000000），按任意键重新输入！");

		fflush(stdin);

		getch();

		return 1;

	}

	for (i = 0; i<s->num; i++)

		if (s->date[i].snum == snum) t++;//如果出现重复学号执行t++

	if (t>0) {///如果出现重复学号执行

		printf("输入有误，输入的学号与已存的学生记录重复，请按任意重新输入！");

		fflush(stdin);

		getch();

		return 1;

	}

	else return 0;

}




int check_score(int score) {

	if (score<0 || score>100) {//如果成绩范围有错误执行

		printf("输入有误，科目分数范围为（0-100），按任意键重新输入！");

		fflush(stdin);

		getch();

		return 1;

	}

	else return 0;

}




void pass(student *s, student *r, int I) {//储存科目合格学生记录

	int i, j = 0;

	if (I != 4)

		for (i = 0; i<s->num; i++) {//储存第I科目合格学生记录

			if (s->date[i].score[I] >= PASS)

				r->date[j++] = s->date[i];

		}

	else

		for (i = 0; i<s->num; i++) {//储存任意科目合格学生记录

			if (s->date[i].score[0] >= PASS || s->date[i].score[1] >= PASS || s->date[i].score[2] >= PASS || s->date[i].score[3] >= PASS)

				r->date[j++] = s->date[i];

		}

	r->num = j;

}




void notpass(student *s, student *r, int I) {//储存科目不合格学生记录

	int i, j = 0;

	if (I != 4)

		for (i = 0; i<s->num; i++) {//储存第I科目不合格学生记录

			if (s->date[i].score[I]<PASS)

				r->date[j++] = s->date[i];

		}

	else

		for (i = 0; i<s->num; i++) {//储存任意科目不合格学生记录

			if (s->date[i].score[0]<PASS || s->date[i].score[1]<PASS || s->date[i].score[2]<PASS || s->date[i].score[3]<PASS)

				r->date[j++] = s->date[i];

		}

	r->num = j;

}




float avg(student *s, int I) {//求各科目平均分

	int i;

	float a = 0;

	for (i = 0; i<s->num; i++)

		a += s->date[i].score[I];

	return a / i;

}




void more_avg(student *s, student *r, int I) {//储存科目高于或等于平均分学生记录

	int i, j = 0;

	float a;

	a = avg(s, I);

	if (I != 4)

		for (i = 0; i<s->num; i++) {//储存第I科目高于或等于平均分学生记录

			if (s->date[i].score[I] >= a)

				r->date[j++] = s->date[i];

		}

	else

		for (i = 0; i<s->num; i++) {//储存任意科目高于或等于平均分学生记录

			if (s->date[i].score[0] >= a || s->date[i].score[1] >= a || s->date[i].score[2] >= a || s->date[i].score[3] >= a)

				r->date[j++] = s->date[i];

		}

	r->num = j;

}




void less_avg(student *s, student *r, int I) {//储存科目低于平均分学生记录

	int i, j = 0;

	float a;

	a = avg(s, I);

	if (I != 4)

		for (i = 0; i<s->num; i++) {//储存第I科目低于平均分学生记录

			if (s->date[i].score[I]<a)

				r->date[j++] = s->date[i];

		}

	else

		for (i = 0; i<s->num; i++) {//储存任意科目低于平均分学生记录

			if (s->date[i].score[0]<a || s->date[i].score[1]<a || s->date[i].score[2]<a || s->date[i].score[3]<a)

				r->date[j++] = s->date[i];

		}

	r->num = j;

}




void statistics(student *s) {//统计信息

	int i, n;

	printf("\n\n考试人数为：%d\n\n\n", s->num);

	n = 0;

	for (i = 0; i<s->num; i++)

		if (s->date[i].score[0] >= PASS)

			n++;

	printf("\n《数学》：    平均分为%.2f，合格人数为%d ，不合格人数%d。\n", avg(s, 0), n, s->num - n);

	n = 0;

	for (i = 0; i<s->num; i++)

		if (s->date[i].score[1] >= PASS)

			n++;

	printf("\n《英语》：平均分为%.2f，合格人数为%d ，不合格人数%d。\n", avg(s, 1), n, s->num - n);

	n = 0;

	for (i = 0; i<s->num; i++)

		if (s->date[i].score[2] >= PASS)

			n++;

	printf("\n《物理》：  平均分为%.2f，合格人数为%d ，不合格人数%d。\n", avg(s, 2), n, s->num - n);

	n = 0;

	for (i = 0; i<s->num; i++)

		if (s->date[i].score[3] >= PASS)

			n++;

	printf("\n《计算机》：    平均分为%.2f，合格人数为%d ，不合格人数%d。\n", avg(s, 3), n, s->num - n);

	n = 0;

	for (i = 0; i<s->num; i++)

		if (s->date[i].score[0] >= PASS || s->date[i].score[1] >= PASS || s->date[i].score[2] >= PASS || s->date[i].score[3] >= PASS)

			n++;

	printf("\n任意科目合格人数为：%d ，不合格人数：%d。\n", n, s->num - n);

}







void bubblesort(student *s) {//对学生记录进行排序

	int i, j;

	stu temp;

	for (i = 0; i<s->num - 1; i++)//对学生记录数组进行按分数排序

		for (j = 0; j<s->num - i - 1; j++)

			if (s->date[j].average<s->date[j + 1].average) {

				temp = s->date[j];

				s->date[j] = s->date[j + 1];

				s->date[j + 1] = temp;

			}

	for (i = 0; i<s->num; i++)//按下标给学生记录.rank（名次赋值）

		s->date[i].rank = i + 1;

	for (i = 0; i<s->num; i++)//对平均分相同的学生的名次进行并列

		if (s->date[i].average == s->date[i + 1].average)

			s->date[i + 1].rank = s->date[i].rank;

	if (BUBB) {

		for (i = 0; i<s->num - 1; i++)//对学生记录数组进行按学号排序

			for (j = 0; j<s->num - i - 1; j++)

				if (s->date[j].snum>s->date[j + 1].snum) {

					temp = s->date[j];

					s->date[j] = s->date[j + 1];

					s->date[j + 1] = temp;

				}

	}

}




void fscanfstudent(student *s) {//把学生记录从硬盘写进内存里

	int i = 0;

	FILE *p;

	p = fopen("date.dat", "rb");

	if (p == NULL) {//检查学生记录是否为空

		p = fopen("date.dat", "wt");//学生记录为空，新建一个空白的文本到硬盘里

		s->num = 0;

		fclose(p);

		return;

	}

	while (!feof(p)) {//从硬盘读取学生记录，直接光标读取到为空，结束循环

		fscanf(p, "%ld%s%d%f%f%f%f%f", &s->date[i].snum, s->date[i].name, &s->date[i].rank, &s->date[i].score[0],

			&s->date[i].score[1], &s->date[i].score[2], &s->date[i].score[3], &s->date[i].average);

		i++;

	}

	bubblesort(s);//写进内存前进行排序

	s->num = i - 1;//4.??把学生记录从硬盘写进内存里，记录次数比实际多1

	fclose(p);

}




void fprintfstudent(student *s) {//把学生记录从内存写进硬盘

	int i = 0;

	FILE *p;

	bubblesort(s);//写进硬盘前进行排序

	p = fopen("date.dat", "wt");

	while (i<s->num) {

		fprintf(p, "%ld %s %d %.2f %.2f %.2f %.2f %.2f\n", s->date[i].snum, s->date[i].name, s->date[i].rank, s->date[i].score[0],

			s->date[i].score[1], s->date[i].score[2], s->date[i].score[3], s->date[i].average);

		i++;

	}

	fclose(p);

}


void fprintftxt(student *s) {//把学生记录从内存写进txt

	int i = 0;

	FILE *p;

	bubblesort(s);//写进硬盘前进行排序

	p = fopen("date.txt", "wt");

	while (i<s->num) {

		fprintf(p, "%ld %s %d %.2f %.2f %.2f %.2f %.2f\n", s->date[i].snum, s->date[i].name, s->date[i].rank, s->date[i].score[0],

			s->date[i].score[1], s->date[i].score[2], s->date[i].score[3], s->date[i].average);

		i++;

	}

	fclose(p);

}






void fscanfsettings() {//把设置参数从内存保存到硬盘里

	FILE *p;

	p = fopen("settings.dat", "wt");

	fprintf(p, "%d %d", BUBB, PASS);

	fclose(p);

}




void fprintfsettings() {//把设置参数从硬盘写进内存中

	FILE *p;

	p = fopen("settings.dat", "rb");

	if (p == NULL) {//检查设置参数是否为空

		BUBB = 1;//设置默认参数

		PASS = 60;//设置默认参数

		p = fopen("settings.dat", "wt");//设置参数是否为空，新建一个空白的文本到硬盘里

		fprintf(p, "%d %d", BUBB, PASS);//设置默认参数

		fclose(p);

		return;

	}

	fscanf(p, "%d%d", &BUBB, &PASS);

	fclose(p);

}




int main() {

	student s;

	fprintfsettings();

	fscanfstudent(&s);

	interface_welcome(&s);

	return 0;

}
