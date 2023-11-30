#include<stdio.h>
main()
{
	int i, sum;
	i=0; sum=0;
	while(i <= 100)
	{
		sum = sum + i;
		i++;
	}
	//error 
	printf("1+2+...+100=%d", sum);
}