#include<stdio.h>
#include<stdlib.h>

int Is_In(int x, int*A, int a)
{
	int s = 0;
	for (int i = 0; i<a; i++)
	{
		if (x == A[i])
		{
			s = 1;
			break;
		}
	}
	return s;
}

void main()
{
	int x, *A, na;

	printf("请输入集合A的元素个数：\n");
	scanf("%d", &na);
	A = (int*)malloc(na*sizeof(int));
	printf("请输入集合A的元素：\n");
	for (int i = 0; i<na; i++)
	{
		scanf("%d", &A[i]);
	}

	printf("输入一个x\n");
	scanf("%d", &x);
	if (Is_In(x, A, na) == 1)
	{
		printf("%d是其中的元素\t", x);
	}
	else
		printf("%d不是其中的元素", x);

}
