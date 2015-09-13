#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 5
int N;

struct student
{
	char num[11];
	char name[7];
	float math;
	float english;
	float computer;
	float total;
	float average;
}; student s[M];

void input()
{                             //***输入学生信息***//
	int n = 0;
	N = 0;
	char c = 'a';
	printf("\t\t请输入学生信息\n");
	printf("\n");
	printf("\t    退出请按'n',继续请按任意字");
	printf("\n");
	printf("\t    学号        姓名     数学 英语 计算机基础\n");
	printf("\t如：1018014000  张三     0    0        0\n");

	while (c != 'n')
	{
		printf("\t    ");
		scanf("%s%s%f%f%f", s[N].num, s[N].name, &s[N].math, &s[N].english, &s[N].computer);
		N++;
		getchar();
		c = getchar();
		getchar();
	}
	printf("\n");
}

void save()
{                          //***保存学生信息***//
	int i;
	FILE *fp;

	if ((fp = fopen("www.txt", "wb")) == NULL)
	{
		printf("文件打开失败\n");
		exit(0);
	}

	for (i = 0; i<N; i++)
	{
		fwrite(&s[i], sizeof(struct student), 1, fp);
	}
	fclose(fp);
	printf("\t\t成功写入文件\n");
	printf("\n");
}

void read()
{                         //***读取学生信息***//
	int n = 0;
	FILE *fp;
	if ((fp = fopen("www.txt", "rb")) == NULL)
	{
		printf("文件打开失败\n");
		exit(0);
	}
	//	while(!feof(fp))
	//	{
	for (int i = 0; i<N; i++)
		fread(&s[i], sizeof(struct student), 1, fp);
	//	n++;
	//N=n;
	printf("\t\t成功读取信息\n");
	fclose(fp);
	printf("\n");

}
void ave1(int n, student s[])
{
	float sum = 0;
	float smath, senglish, scomputer;
	float avemath, aveenglish, avecomputer;
	int i;
	for (i = 0; i<n; i++)
	{
		smath = s[i].math + smath;
		senglish = s[i].english + senglish;
		scomputer = s[i].computer + scomputer;
	}
	avemath = smath / n;
	aveenglish = senglish / n;
	avecomputer = scomputer / n;
	printf("各科平均成绩: 高数 英语 计算机基础  ");
	printf("%f%f%f", avemath, aveenglish, avecomputer);

}

float ave2(int n)
{
	float sum;
	sum = s[n].math + s[n].english + s[n].computer;
	sum = sum / 3;
	return sum;
}
void max(float ave1[], int n)
{
	int i;
	float MAX, t;
	for (i = 0; i<n; i++) {
		if (ave1[i]<ave1[i + 1]) {
			t = ave1[i];
			ave1[i] = ave1[i + 1];
			ave1[i + 1] = t;
		}
	}
	MAX = ave1[0];
	printf("平均分最高的学生：%f\n", MAX);
}
void savemax() {                          //***保存学生信息***//
	int i;
	FILE *fp;
	if ((fp = fopen("studmax.txt", "wb")) == NULL) {
		printf("文件打开失败\n");
		exit(0);
	}
	for (i = 0; i<N; i++) {
		fwrite(&s[i], sizeof(struct student), 1, fp);
	}
	fclose(fp);
	printf("\t\t成功写入文件\n");
	printf("\n");
}

void readmax()
{                         //***读取学生信息***//
	int n = 0;
	FILE *fp;
	if ((fp = fopen("www.txt", "rb")) == NULL)
	{
		printf("文件打开失败\n");
		exit(0);
	}
	//	while(!feof(fp))
	//	{
	for (int i = 0; i<N; i++)
		fread(&s[i], sizeof(struct student), 1, fp);
	//	n++;
	//N=n;
	printf("\t\t成功读取信息\n");
	fclose(fp);
	printf("\n");

}
void main()
{
	int i, j;
	float ave[M];
	float a;
	input();
	ave1(M, s);
	for (i = 0; i<M; i++)
	{
		ave[i] = a = ave2(i);
	}
	printf("输出学生平均分：");
	for (j = 0; j<M; j++)
	{
		printf("%f", ave[j]);
	}
	save();
	read();
	max(ave, M);
	savemax();
	readmax();
}

