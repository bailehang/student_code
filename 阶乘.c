#include<stdio.h>
void main()
{
	int i, a, b = 1;
	printf("输入一个数\n");
	scanf("%d", &a);
	for (i = 1; i <= a; i++)
		b = i*b;
	printf("%d!=%d\n", a, b);
}
