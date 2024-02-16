#include<stdio.h>
int main()
{
	int n;
	printf("输入一个整数: ");
	scanf("%d",&n);
	int fact = 1;
	int i=1;
	while( i<=n )
	{
		fact *= i;
		i++;
	}
	printf("它的阶乘是: %d\n",fact);
 } 