#include<stdio.h>
int main()
{
	int n;
	printf("����һ������: ");
	scanf("%d",&n);
	int fact = 1;
	int i=1;
	while( i<=n )
	{
		fact *= i;
		i++;
	}
	printf("���Ľ׳���: %d\n",fact);
 } 